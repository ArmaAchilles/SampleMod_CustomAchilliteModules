[EntityEditorProps(category: "GameScripted/Modules", description: "Hello World Module Class", color: "255 0 0 255")]
class SampleMod_ModuleHelloWorldEntityClass: ACL_ModuleEntityBaseClass
{
};

class SampleMod_ModuleHelloWorldEntity: ACL_ModuleEntityBase
{
	string m_title = "Hello World!";
	
	override void OnPlace(vector pos, SCR_EditableEntityComponent entity)
	{
		string entityName = "";
		if (entity)
		{
			entityName = entity.GetDisplayName();
		};
		string message = string.Format("Position: {%1}\nEntity Name: \"%2\"", pos.ToString(false), entityName);
		Print(message);
		SCR_HintManagerComponent.GetInstance().ShowCustomHint(message, m_title, 3.0);
		if (entity)
		{
			IEntity owner = entity.GetOwner();
			SCR_AIGroup group = SCR_AIGroup.Cast(owner);
			if (group)
			{
				array<AIAgent> agents = {};
				group.GetAgents(agents);
				foreach (AIAgent agent : agents)
				{
					SCR_AIInfoComponent infoComp = SCR_AIInfoComponent.Cast(agent.FindComponent(SCR_AIInfoComponent));
					CharacterControllerComponent charCtrlComp = CharacterControllerComponent.Cast(agent.GetControlledEntity().FindComponent(CharacterControllerComponent));
					infoComp.SetStance(ECharacterStance.PRONE);
					charCtrlComp.ForceStance(ECharacterStance.PRONE);
					charCtrlComp.SetStanceChange(ECharacterStanceChange.STANCECHANGE_TOPRONE);
				};
			};
		};
		Delete();
	}
};
