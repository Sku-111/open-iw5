#include <std_include.hpp>
#include "steam/steam.hpp"

namespace steam
{
	int user::GetHSteamUser()
	{
		return NULL;
	}

	bool user::LoggedOn()
	{
		return true;
	}

	steam_id user::GetSteamID()
	{
		steam_id id;
		id.bits = 0x110000100000000 | (0x1377 & ~0x80000000);
		return id;
	}

	int user::InitiateGameConnection(void *pAuthBlob, int cbMaxAuthBlob, steam_id steamIDGameServer, unsigned int unIPServer, unsigned short usPortServer, bool bSecure)
	{
		return 0;
	}

	void user::TerminateGameConnection(unsigned int unIPServer, unsigned short usPortServer)
	{
	}

	void user::TrackAppUsageEvent(steam_id gameID, int eAppUsageEvent, const char *pchExtraInfo)
	{
	}

	bool user::GetUserDataFolder(char *pchBuffer, int cubBuffer)
	{
		return false;
	}

	void user::StartVoiceRecording()
	{
	}

	void user::StopVoiceRecording()
	{
	}

	int user::GetAvailableVoice(unsigned int *pcbCompressed, unsigned int *pcbUncompressed, unsigned int nUncompressedVoiceDesiredSampleRate)
	{
		return 0;
	}

	int user::GetVoice(bool bWantCompressed, void *pDestBuffer, unsigned int cbDestBufferSize, unsigned int *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, unsigned int cbUncompressedDestBufferSize, unsigned int *nUncompressBytesWritten, unsigned int nUncompressedVoiceDesiredSampleRate)
	{
		return 0;
	}

	int user::DecompressVoice(void *pCompressed, unsigned int cbCompressed, void *pDestBuffer, unsigned int cbDestBufferSize, unsigned int *nBytesWritten)
	{
		return 0;
	}

	unsigned int user::GetVoiceOptimalSampleRate()
	{
		return 0;
	}

	unsigned int user::GetAuthSessionTicket(void *pTicket, int cbMaxTicket, unsigned int *pcbTicket)
	{
		return 0;
	}

	int user::BeginAuthSession(const void *pAuthTicket, int cbAuthTicket, steam_id steamID)
	{
		return 0;
	}

	void user::EndAuthSession(steam_id steamID)
	{
	}

	void user::CancelAuthTicket(unsigned int hAuthTicket)
	{
	}

	unsigned int user::UserHasLicenseForApp(steam_id steamID, unsigned int appID)
	{
		return 0;
	}

	bool user::BIsBehindNAT()
	{
		return false;
	}

	void user::AdvertiseGame(steam_id steamIDGameServer, unsigned int unIPServer, unsigned short usPortServer)
	{
	}

	unsigned __int64 user::RequestEncryptedAppTicket(void *pUserData, int cbUserData)
	{
		// Generate the authentication ticket
		//Components::DemonWare::GenerateAuthTicket(std::string(reinterpret_cast<char*>(pUserData), cbUserData));

		// Create the call response
		const auto result = callbacks::register_call();
		auto retvals = static_cast<encrypted_app_ticket_response*>(calloc(1, sizeof(encrypted_app_ticket_response)));//::Utils::Memory::AllocateArray<EncryptedAppTicketResponse>();
		retvals->m_e_result = 1;

		// Return the call response
		callbacks::return_call(retvals, sizeof(encrypted_app_ticket_response), encrypted_app_ticket_response::callback_id, result);

		return result;
	}

	bool user::GetEncryptedAppTicket(void *pTicket, int cbMaxTicket, unsigned int *pcbTicket)
	{
		if (cbMaxTicket < 0) return false;
		return false;//Components::DemonWare::GetAuthTicket(pTicket, static_cast<unsigned int>(cbMaxTicket), pcbTicket);
	}
}