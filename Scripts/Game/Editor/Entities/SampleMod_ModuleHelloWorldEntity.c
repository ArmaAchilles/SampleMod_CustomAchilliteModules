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
		
		Delete();
	}
};
