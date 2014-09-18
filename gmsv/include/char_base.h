#ifndef __CHAR_BASE_H__
#define __CHAR_BASE_H__

#include "version.h"
#include "skill.h"
#include "title.h"
/*#include "magicinfo.h"*/
#include "addressbook.h"

#define CHAR_DELIMITER "\n"

#define NONCHAR_DELIMITER "|"

#define STATUSSENDDELIMITER "|"

#define CHAR_MAXGOLDHAVE    (1000*10000)
#define CHAR_MAXBANKGOLDHAVE    (10000*10000)
#define CHAR_MAXFMBANKGOLDHAVE	(10000*10000*2)

#ifdef _NEW_MANOR_LAW
#define MAX_PERSONAL_MOMENTUM 10000000
#endif
#ifdef _PERSONAL_FAME	// Arminius 8.30: 家族个人声望
#define MAX_PERSONALFAME (10000 * 10000)
#endif
#ifdef _PROFESSION_SKILL			// WON ADD 人物职业技能
#define CHAR_SKILLMAXHAVE   26		// 职业技能上限
#else
#define CHAR_SKILLMAXHAVE   5
#endif

#ifdef _STREET_VENDOR
#define MAX_SELL_ITEM 20					// 道具加宠物共可卖二十个
#endif
#define CHAR_TITLEMAXHAVE   30

#define NULLSKILL   "0"

#define CHAR_MAXPETHAVE         5
#define CHAR_MAXPERSONAGOLD		50000000

#ifdef _ADD_POOL_ITEM			   // WON ADD 增加可寄放的道具
#define CHAR_MAXPOOLPETHAVE         15
#else
#define CHAR_MAXPOOLPETHAVE         10
#endif

#define CHAR_MAXPETSKILLHAVE       7
#define CHAR_PARTYMAX           5
#define	CHAR_MAXATTRIB			100
#define CHAR_MAXUPLEVEL			200
#define	CHAR_MAXDUELPOINT		100000000
#define CHAR_DEFAULTMAXAI		(60)
#define CHAR_MAXVARIABLEAI		(100*100)
#define CHAR_MINVARIABLEAI		(-100*100)
#define CHAR_POISONSTRING           "中毒"
#define CHAR_RECOVERPOISONSTRING    "解毒了"
#define CHAR_PARALYSISSTRING        "麻痹了"
#define CHAR_RECOVERPARALYSISSTRING "麻醉退了"
#define CHAR_SILENCESTRING          "无法念魔法了"
#define CHAR_RECOVERSILENCESTRING   "可以念魔法了"
#define CHAR_STONESTRING            "石化了"
#define CHAR_RECOVERSTONESTRING     "变灵活了"
#define CHAR_DARKNESSSTRING         "四周不见了"
#define CHAR_RECOVERDARKNESSSTRING  "四周出现了"
#define CHAR_CONFUSIONSTRING        "陷入恐慌"
#define CHAR_RECOVERCONFUSIONSTRING "恢复正常"

#define CHAR_DEFAULTSEESIZ  23
#define MAP_CHAR_DEFAULTSEESIZ      (CHAR_DEFAULTSEESIZ+4)

typedef enum
{
    CHAR_HEAD,               
    CHAR_BODY, 
    CHAR_ARM,
    CHAR_DECORATION1,
    CHAR_DECORATION2,
#ifdef _ITEM_EQUITSPACE
	CHAR_EQBELT,	//腰带
	CHAR_EQSHIELD,	//盾
	CHAR_EQSHOES,	//鞋子
#endif
#ifdef _EQUIT_NEWGLOVE
	CHAR_EQGLOVE,
#endif
    CHAR_EQUIPPLACENUM,
}CHAR_EquipPlace;


#ifdef _PET_ITEM
typedef enum
{
    CHAR_PET_HEAD,		//头
    CHAR_PET_TOOTH, 	//牙
    CHAR_PET_CLAW,		//爪
    CHAR_PET_BREAST,	//胸
    CHAR_PET_BACK,		//背
    CHAR_PET_WING,		//翅
    CHAR_PET_FEET,		//脚
    
    CHAR_PETITEMNUM,
}CHAR_petitem;
#endif


typedef struct tagCharHaveSkill
{
    int     use;
    Skill   skill;
}CHAR_HaveSkill;

#ifdef _STREET_VENDOR
typedef struct STREET_VENDDOR_t{
	int pile;												// 数量
	int price;											// 价格
	int index;											// 索引
	int kind;											// 道具或是宠物 0:道具 1:宠物
	BOOL usage;											// 是否使用中
}StreetVendor_t;

enum{
	SV_PILE,
	SV_PRICE,
	SV_INDEX,
	SV_KIND,
	SV_USAGE,
	MAX_SV
};
#endif

typedef enum
{
    CHAR_ACTSTAND,
    CHAR_ACTWALK,
    CHAR_ACTATTACK,
    CHAR_ACTTHROW,
    CHAR_ACTDAMAGE,
    CHAR_ACTDEAD,
    CHAR_ACTMAGIC,
    CHAR_ACTITEM,
    CHAR_ACTEFFECT,
    CHAR_ACTDOWN = 10,
    CHAR_ACTSIT,
    CHAR_ACTHAND,
    CHAR_ACTPLEASURE,
    CHAR_ACTANGRY,
    CHAR_ACTSAD,
    CHAR_ACTGUARD,
    CHAR_ACTACTIONWALK,
    CHAR_ACTNOD,
    CHAR_ACTACTIONSTAND,
    CHAR_ACTBATTLE = 20,
    CHAR_ACTLEADER,
	CHAR_ACTBATTLEWATCH,
	CHAR_ACTPOPUPNAME,
	CHAR_ACTTURN = 30,
	CHAR_ACTWARP,
	CHAR_ACTTRADE,
#ifdef _ANGEL_SUMMON
	CHAR_ACTANGEL = 34, 
#endif

#ifdef _MIND_ICON
	CHAR_MIND = 40,
#endif
#ifdef _STREET_VENDOR
	CHAR_STREETVENDOR_OPEN,
	CHAR_STREETVENDOR_CLOSE,
#endif
#ifdef _ITEM_CRACKER
	CHAR_ITEM_CRACKER = 50,
#endif
}CHAR_ACTION;

typedef enum
{
    CHAR_CLIACTATTACK,
    CHAR_CLIACTDAMAGE,
    CHAR_CLIACTDOWN,
    CHAR_CLIACTSTAND,
    CHAR_CLIACTWALK,
    CHAR_CLIACTSIT,
    CHAR_CLIACTHAND,
    CHAR_CLIACTPLEASURE,
    CHAR_CLIACTANGRY,
    CHAR_CLIACTSAD,
    CHAR_CLIACTGUARD,
	CHAR_CLIACTNOD,
	CHAR_CLIACTTHROW,

}CHAR_CLIENTACTION;

typedef enum
{
    CHAR_TYPENONE,
    CHAR_TYPEPLAYER,
    CHAR_TYPEENEMY,
    CHAR_TYPEPET,
    CHAR_TYPEDOOR,
    CHAR_TYPEBOX,
    CHAR_TYPEMSG,
    CHAR_TYPEWARP,
    CHAR_TYPESHOP,
    CHAR_TYPEHEALER,
    CHAR_TYPEOLDMAN,
    CHAR_TYPEROOMADMIN,
    CHAR_TYPETOWNPEOPLE,
    CHAR_TYPEDENGON,
    CHAR_TYPEADM,
    CHAR_TYPETEMPLE,
    CHAR_TYPESTORYTELLER,
    CHAR_TYPERANKING,
    CHAR_TYPEOTHERNPC,
    CHAR_TYPEPRINTPASSMAN,
    CHAR_TYPENPCENEMY,
    CHAR_TYPEACTION,
    CHAR_TYPEWINDOWMAN,
    CHAR_TYPESAVEPOINT,
    CHAR_TYPEWINDOWHEALER,
	CHAR_TYPEITEMSHOP,
	CHAR_TYPESTONESHOP,
	CHAR_TYPEDUELRANKING,
	CHAR_TYPEWARPMAN,
	CHAR_TYPEEVENT,
	CHAR_TYPEMIC,
	CHAR_TYPELUCKYMAN,
	CHAR_TYPEBUS,
	CHAR_TYPECHARM,
	CHAR_TYPECHECKMAN,
	CHAR_TYPEJANKEN,
	CHAR_TYPETRANSMIGRATION,
	CHAR_TYPEFMWARPMAN,			// 家族ＰＫ场管理员
	CHAR_TYPEFMSCHEDULEMAN,		// 家族ＰＫ场登记员
	CHAR_TYPEMANORSCHEDULEMAN,	// 庄园ＰＫ场预约人
#ifdef _GAMBLE_BANK
	CHAR_GAMBLEBANK,
#endif
#ifdef _NEW_WARPMAN
	CHAR_NEWNPCMAN,
#endif

#ifdef _GAMBLE_ROULETTE
	CHAR_GAMBLEROULETTE,
	CHAR_GAMBLEMASTER,
#endif
#ifdef _TRANSER_MAN
	CHAR_TRANSERMANS,
#endif

#ifdef _NPC_MAKEPAIR
	CHAR_MAKEPAIR,
#endif
#ifdef _NPC_FUSION
	CHAR_PETFUSIONMAN,
#endif

#ifdef _ITEM_NPCCHANGE
	CHAR_ITEMCHANGENPC,
#endif
#ifdef _CFREE_petskill
	CHAR_FREESKILLSHOP,
#endif
#ifdef _PETRACE
	CHAR_PETRACEMASTER,			// 宠物竞速
	CHAR_PETRACEPET,
#endif

#ifdef _ALLDOMAN // (不可开) Syu ADD 排行榜NPC
  CHAR_TYPEALLDOMAN,
#endif

    CHAR_TYPEPETMAKER,              // petmaker

#ifdef _NPC_WELFARE
  CHAR_TYPEWELFARE,
#endif
    CHAR_TYPENUM,
}CHAR_TYPE;

typedef enum
{
	CHAR_EVENT_NONE,
  CHAR_EVENT_NPC,
  CHAR_EVENT_ENEMY,
  CHAR_EVENT_WARP,
  CHAR_EVENT_DOOR,
	CHAR_EVENT_ALTERRATIVE,
	CHAR_EVENT_WARP_MORNING,
	CHAR_EVENT_WARP_NOON,
	CHAR_EVENT_WARP_NIGHT,
  CHAR_EVENTNUM,
}CHAR_EVENT;

typedef enum
{
    CHAR_PARTY_NONE,
    CHAR_PARTY_LEADER,
    CHAR_PARTY_CLIENT,
}CHAR_PARTY_MODE;

typedef enum
{
      CHAR_TRADE_FREE,      /* 可交易 */
      CHAR_TRADE_SENDING,   /* 交易请求中 */
      CHAR_TRADE_TRADING,   /* 交易中 */
      CHAR_TRADE_LOCK,	    /* 交易锁定中 */
}CHAR_TRADE_MODE;
                  
typedef enum
{
    CHAR_PETMAIL_NONE,
    CHAR_PETMAIL_IDLE1,
    CHAR_PETMAIL_IDLE2,
    CHAR_PETMAIL_RETURNWAIT,
    CHAR_PETMAIL_IDLE3,
    CHAR_PETMAIL_IDLE4,
    CHAR_PETMAIL_IDLE5,
}CHAR_PETMAIL_MODE;

typedef enum
{
    CHAR_PETFOLLOW_NONE,
    CHAR_PETFOLLOW_NOW,
}CHAR_PETFOLLOW_MODE;

#ifdef _DROPSTAKENEW
typedef enum
{
	DICE_BIG = 1,		// 骰子_大
	DICE_SMALL,			// 骰子_小
	DICE_ALLEAT,		// 骰子_通吃
	PET_RACE1 = 5,		// 竞速场_宠物1
	PET_RACE2,			// 竞速场_宠物2
	PET_RACE3,			// 竞速场_宠物3
	ROULETTE1 = 11,	ROULETTE2, ROULETTE3, ROULETTE4, ROULETTE5,	ROULETTE6, ROULETTE7, 
	ROULETTE8, ROULETTE9, ROULETTE10, ROULETTE11, ROULETTE12, ROULETTE13, ROULETTE14,
	ROULETTE15,	ROULETTE16,	ROULETTE17,	ROULETTE18,	ROULETTE19,	ROULETTE20,	
	ROULETTE21 = 41, ROULETTE22, ROULETTE23, ROULETTE24,	ROULETTE25,	ROULETTE26,	
	ROULETTE27,	ROULETTE28,	ROULETTE29, ROULETTE30, ROULETTE31, ROULETTE32,
	ROULETTE33,	ROULETTE34,	ROULETTE35,	ROULETTE36,	ROULETTE37,	ROULETTE38,
	ROULETTE39,	ROULETTE40,
	ROULETTE41 = 71, ROULETTE42, ROULETTE43, ROULETTE44, ROULETTE45,
	ROULETTE51 = 101, ROULETTE52, ROULETTE53,	//横列
	ROULETTE61 = 111, ROULETTE62,				//1到10 10到11
	PETFIGHT_WIN1 = 120,
	PETFIGHT_WIN2,
	PETFIGHT_DUEL,
}GAMBLE_TYPE;
#endif

#ifdef _CHAR_POOLITEM
#ifdef _NPC_DEPOTPET // 开放宠物仓库同时增加道具仓库容量
#define CHAR_MAXDEPOTITEMHAVE 80
#else
#define CHAR_MAXDEPOTITEMHAVE 60
#endif
#endif

#ifdef _CHAR_POOLPET
#define CHAR_MAXDEPOTPETHAVE 30
#endif


#ifdef _ADD_POOL_ITEM				// (不可开) WON ADD 增加可寄放的道具
#define CHAR_MAXPOOLITEMHAVE	30
#else
#define CHAR_MAXPOOLITEMHAVE	20
#endif

#define CHAR_MAXITEMNUM  15
#define CHAR_STARTITEMARRAY     CHAR_EQUIPPLACENUM
#define CHAR_MAXITEMHAVE (CHAR_STARTITEMARRAY+CHAR_MAXITEMNUM)

#ifdef _PET_ITEM
#define CHAR_MAXPETITEMHAVE CHAR_PETITEMNUM
#endif

typedef enum
{
    CHAR_DATAPLACENUMBER,
    CHAR_BASEIMAGENUMBER,
    CHAR_BASEBASEIMAGENUMBER,
    CHAR_FACEIMAGENUMBER,
    CHAR_FLOOR,
    CHAR_X,
    CHAR_Y,
    CHAR_DIR,
    CHAR_LV,
    CHAR_GOLD,
    CHAR_HP,
    CHAR_MP,
    CHAR_MAXMP,
    CHAR_VITAL,
    CHAR_STR,
    CHAR_TOUGH,
    CHAR_DEX,
    CHAR_CHARM,
    CHAR_LUCK,
    CHAR_EARTHAT,
    CHAR_WATERAT,
    CHAR_FIREAT,
    CHAR_WINDAT,
    CHAR_DEFAULTPET,
    CHAR_CRITIAL,
    CHAR_COUNTER,
	CHAR_RARE,
    CHAR_RADARSTRENGTH,
    CHAR_CHATVOLUME,
    CHAR_MERCHANTLEVEL,
    CHAR_HEALERLEVEL,
    CHAR_SAVEPOINT = CHAR_HEALERLEVEL,
    CHAR_DETERMINEITEM,
    CHAR_INDEXOFEQTITLE,
    CHAR_POISON,
    CHAR_PARALYSIS,
    CHAR_SLEEP,
    CHAR_STONE,
    CHAR_DRUNK,
    CHAR_CONFUSION,
    CHAR_LOGINCOUNT,
    CHAR_NPCCREATEINDEX=CHAR_LOGINCOUNT,
    CHAR_DEADCOUNT,
    CHAR_WALKCOUNT,
    CHAR_TALKCOUNT,
    CHAR_DAMAGECOUNT,
    CHAR_GETPETCOUNT,
    CHAR_KILLPETCOUNT,
    CHAR_DEADPETCOUNT,
		CHAR_SENDMAILCOUNT,
		CHAR_MERGEITEMCOUNT,
		CHAR_DUELBATTLECOUNT,
		CHAR_DUELWINCOUNT,
		CHAR_DUELLOSECOUNT,
		CHAR_DUELSTWINCOUNT,
		CHAR_DUELMAXSTWINCOUNT,
    CHAR_WHICHTYPE,
    CHAR_WALKINTERVAL,
    CHAR_LOOPINTERVAL,
#ifdef _NEWOPEN_MAXEXP
	CHAR_OLDEXP,
	CHAR_EXP,
#else
	CHAR_EXP,
#endif
    CHAR_LASTTALKELDER,
    CHAR_SKILLUPPOINT,
    CHAR_LEVELUPPOINT,
    CHAR_IMAGETYPE,
    CHAR_NAMECOLOR,
    CHAR_POPUPNAMECOLOR,
    CHAR_LASTTIMESETLUCK,
    CHAR_DUELPOINT,
    CHAR_ENDEVENT,				/* (0~31)		*/
    CHAR_ENDEVENT2,				/* (32~63)		*/
    CHAR_ENDEVENT3,				/* (64~96)		*/
#ifdef _NEWEVENT
	CHAR_ENDEVENT4,				/* (96~127) */
	CHAR_ENDEVENT5,				/* (128~159) */
	CHAR_ENDEVENT6,				/* (160~191) */
#endif
#ifdef _ADD_NEWEVENT            // WON 多增任务旗标
	CHAR_ENDEVENT7,					
	CHAR_ENDEVENT8,
#endif

	CHAR_NOWEVENT,				/* (0~31)		*/
	CHAR_NOWEVENT2,				/* (32~63)		*/
	CHAR_NOWEVENT3,				/* (64~96)		*/
#ifdef _NEWEVENT
	CHAR_NOWEVENT4,				/* (96~127)		*/
	CHAR_NOWEVENT5,				/* (128~159)	*/
	CHAR_NOWEVENT6,				/* (160~191)	*/
#endif
#ifdef _ADD_NEWEVENT            // WON 多增任务旗标	
	CHAR_NOWEVENT7,				
	CHAR_NOWEVENT8,				// 224~255 精灵召唤专用
#endif
	CHAR_TRANSMIGRATION,
	CHAR_TRANSEQUATION,
  CHAR_INITDATA,
  CHAR_SILENT,				/* char shutup time */    
  CHAR_FMINDEX,				// 家族 index
  CHAR_FMLEADERFLAG,			/* 家族成员种类
    							 * FMMEMBER_NONE	:没有加入任何家族
    							 * FMMEMBER_APPLY	:申请加入家族中
    							 * FMMEMBER_LEADER	:族长
    							 * FMMEMBER_MEMBER	:一般成员
    							 * FMMEMBER_ELDER	:长老    
    							 * FMMEMBER_INVITE	:祭司			// 暂时不用
    							 * FMMEMBER_BAILEE	:财务长			// 暂时不用
    							 * FMMEMBER_VICELEADER  :副族长		// 暂时不用
    							*/
  CHAR_FMSPRITE,		// 家族守护精灵

  CHAR_BANKGOLD,
  CHAR_RIDEPET,
  CHAR_LEARNRIDE,
#ifdef _NEW_RIDEPETS
	CHAR_LOWRIDEPETS,
#endif
    CHAR_LIMITLEVEL,
#ifdef _PET_FUSION
	CHAR_FUSIONCODE,		//物种编码
	CHAR_FUSIONINDEX,		//孵化宠物编号
	CHAR_FUSIONRAISE,		//  养次数
	CHAR_FUSIONBEIT,		//宠蛋旗标
	CHAR_FUSIONTIMELIMIT,	//  养时间
#endif

#ifdef _PERSONAL_FAME	// Arminius 8.30: 家族个人声望
    CHAR_FAME,
#endif

#ifdef _NEWSAVE
    CHAR_SAVEINDEXNUMBER,	/*  SaveFile .0.char or .1.char */
#endif
 
#ifdef _ATTACK_MAGIC
		CHAR_EARTH_EXP,						// 玩家的地魔法熟练度
		CHAR_WATER_EXP,						// 玩家的水魔法熟练度
		CHAR_FIRE_EXP,						// 玩家的火魔法熟练度
		CHAR_WIND_EXP,						// 玩家的风魔法熟练度
		CHAR_EARTH_RESIST,					// 玩家的地魔法抗性
		CHAR_WATER_RESIST,					// 玩家的水魔法抗性
		CHAR_FIRE_RESIST,					// 玩家的火魔法抗性
		CHAR_WIND_RESIST,					// 玩家的风魔法抗性
		CHAR_EARTH_ATTMAGIC_EXP,			// 玩家的地魔法熟练度经验值
		CHAR_WATER_ATTMAGIC_EXP,			// 玩家的水魔法熟练度经验值
		CHAR_FIRE_ATTMAGIC_EXP,				// 玩家的火魔法熟练度经验值
		CHAR_WIND_ATTMAGIC_EXP,				// 玩家的风魔法熟练度经验值
	 	CHAR_EARTH_DEFMAGIC_EXP,			// 玩家的地魔法抗性经验值
		CHAR_WATER_DEFMAGIC_EXP,			// 玩家的水魔法抗性经验值
		CHAR_FIRE_DEFMAGIC_EXP,				// 玩家的火魔法抗性经验值
		CHAR_WIND_DEFMAGIC_EXP,				// 玩家的风魔法抗性经验值
#endif


#ifdef _GAMBLE_BANK
		CHAR_PERSONAGOLD,	//赌场个人银行
#endif
#ifdef _DROPSTAKENEW
		CHAR_GAMBLENUM,		//赌场积分
#endif
#ifdef _ADD_ACTION          //npc动作
		CHAR_ACTIONSTYLE,
#endif
#ifdef _PET_EVOLUTION
		CHAR_EVOLUTIONBASEVTL,
		CHAR_EVOLUTIONBASESTR,	
		CHAR_EVOLUTIONBASETGH,	
		CHAR_EVOLUTIONBASEDEX,	
#endif

#ifdef _FM_JOINLIMIT
		CHAR_FMTIMELIMIT,
#endif

#ifdef _CHAR_PROFESSION			// WON ADD 人物职业
		PROFESSION_CLASS,			// 职业别
		PROFESSION_LEVEL,			// 职业等级
//		PROFESSION_EXP,				// 职业经验值
		PROFESSION_SKILL_POINT,		// 技能点数
		ATTACHPILE,					// 增加堆叠
		PROFESSION_FIRE_P,			// 火熟练度
		PROFESSION_ICE_P,			// 冰熟练度		
		PROFESSION_THUNDER_P,		// 雷熟练度
		PROFESSION_FIRE_R,			// 火抗性
		PROFESSION_ICE_R,			// 冰抗性	
		PROFESSION_THUNDER_R,		// 雷抗性
#endif
#ifdef _ALLDOMAN // (不可开) Syu ADD 排行榜NPC
		CHAR_HEROFLOOR, 
#endif
#ifdef _PETSKILL_BECOMEPIG
		CHAR_BECOMEPIG,
		CHAR_BECOMEPIG_BBI,//要变成的图号
#endif
		CHAR_LASTLEAVETIME, // Robin add 最後离线时间

#ifdef _NEW_MANOR_LAW
		CHAR_MOMENTUM,
#endif

#ifdef _ITEM_ADDEXP2
		CHAR_ADDEXPPOWER,
		CHAR_ADDEXPTIME,
#endif

#ifdef _ANGEL_SUMMON
		CHAR_HEROCNT, // 完成勇者任务的次数
#endif

#ifdef _TEACHER_SYSTEM
	CHAR_TEACHER_FAME,	// 导师领导声望
#endif

#ifdef _GM_ITEM
	CHAR_GMTIME,       // 玩家GM命令次数
#endif

#ifdef _VIP_SERVER
	CHAR_AMPOINT,      // 会员点数
#endif

#ifdef _VIP_RIDE
	CHAR_VIPRIDE,      // 会员骑黑鸡
#endif

		CHAR_LISTPAGE,

#ifdef _AUTO_PK
		CHAR_AUTOPK,       // 自动化PK
#endif
#ifdef _BATTLE_PK
		CHAR_BATTLEPK,
#endif

#ifdef _PET_BEATITUDE
		CHAR_BEATITUDE,
#endif
#ifdef _RIDE_CF
	CHAR_LOWRIDEPETS1,
#endif
		CHAR_DATAINTNUM,

}CHAR_DATAINT;

typedef enum {
    CHAR_MODAI    			= CHAR_CHARM,    		/*  矢永玄  及及镝擦艘膜恳袄    */
	CHAR_VARIABLEAI 		= CHAR_LUCK,			/*  矢永玄及镝擦艘  祭袄  ㄠㄟㄟ  仄凶袄匹  匀化云仁   */
    CHAR_SLOT 				= CHAR_DEFAULTPET,		/* 檗  毛本永玄请  月旦夫永玄醒  矢永玄互银迕  */
   	CHAR_PETGETLV			= CHAR_CHATVOLUME,		/* 必永玄今木凶伊矛伙  矢永玄及心银迕   */
    CHAR_PUTPETTIME			= CHAR_LOGINCOUNT,		/*  矢永玄互哗  卞  井木凶凛棉 */
	CHAR_MAILMODE 			= CHAR_RADARSTRENGTH,	/*   矢永玄及心银迕  丢□伙霜耨橇谪 */
    CHAR_ALLOCPOINT			= CHAR_LEVELUPPOINT,	/* 伊矛伙失永皿凛及喃曰蕊曰禾奶件玄(矢永玄迕) */
    CHAR_PETMAILBUFINDEX	= CHAR_GETPETCOUNT, 	/* 矢永玄丢□伙(offmsg)尺及index */
	CHAR_PETMAILIDLETIME	= CHAR_SENDMAILCOUNT,	/* 矢永玄丢□伙及啃及凛棉卅升 */
	CHAR_PETMAILFROMFLOOR	= CHAR_DUELBATTLECOUNT,	/* 丢□伙毛霜匀凶凛及白夫失 */
	CHAR_PETMAILFROMX		= CHAR_DUELWINCOUNT,	/* 丢□伙毛霜匀凶凛及  甄   */
	CHAR_PETMAILFROMY		= CHAR_DUELLOSECOUNT,	/* 丢□伙毛霜匀凶凛及  甄   */
	CHAR_PETMAILEFFECT		= CHAR_DUELSTWINCOUNT,	/* 矢永玄丢□伙及请蜇及巨白尼弁玄  寞 */
	CHAR_PETSENDMAILCOUNT	= CHAR_TALKCOUNT,		/* 矢永玄互丢□伙毛扪氏分荚醒 */
    CHAR_PETRANK			= CHAR_LASTTIMESETLUCK, /* 矢永玄及仿件弁(矢永玄迕  ㄠ  ㄥ［ㄟ反巨仿□迕 */
	CHAR_PETID				= CHAR_DUELMAXSTWINCOUNT,/* 矢永玄及  件皿伊□玄及     */
    CHAR_PETFAMILY		= CHAR_FMLEADERFLAG,		// CoolFish: Family 判断是否为家族守护兽
}CHAR_PET;


typedef enum
{
    CHAR_NAME,
    CHAR_OWNTITLE,
    CHAR_USERPETNAME = CHAR_OWNTITLE,
    CHAR_NPCARGUMENT,
    CHAR_CDKEY = CHAR_NPCARGUMENT,
    CHAR_OWNERCDKEY,
    CHAR_OWNERCHARANAME,
    CHAR_FMNAME,
#ifdef _UNIQUE_P_I
    CHAR_UNIQUECODE,
#endif
#ifdef _ACTION_GMQUE
	CHAR_GMQUESTR1,
#endif

#ifdef _TEACHER_SYSTEM
	CHAR_TEACHER_ID,		// 导师帐号
	CHAR_TEACHER_NAME,	// 导师名字
#endif
#ifdef _ITEM_SETLOVER
	CHAR_LOVE,         // 结婚判断
	CHAR_LOVERID,      // 爱人帐号
	CHAR_LOVERNAME,    // 爱人名字
#endif

#ifdef _GM_ITEM
	CHAR_GMFUNCTION,   // 玩家GM命令
#endif

    CHAR_DATACHARNUM,
}CHAR_DATACHAR;

typedef enum
{
    CHAR_ISATTACK,
    CHAR_ISATTACKED,
    CHAR_ISOVER,
    CHAR_ISOVERED,
    CHAR_HAVEHEIGHT,
    CHAR_ISVISIBLE,
    CHAR_ISTRANSPARENT,
    CHAR_ISFLYING,
    CHAR_ISDIE,
    CHAR_ISBIG,
    CHAR_ISSHOWBATTLEMSG,
    CHAR_ISPARTY,
    CHAR_ISWARP,
    CHAR_ISDUEL,
    CHAR_ISPARTYCHAT,
    CHAR_ISTRADECARD,
    CHAR_ISTRADE,
#ifdef _CHANNEL_MODIFY
		CHAR_ISTELL,				//密语频道开关
		CHAR_ISFM,					//家族频道开关
		CHAR_ISOCC,					//职业频道开关
		CHAR_ISSAVE,				//对话储存开关
		CHAR_ISCHAT,				//聊天室
#endif
    CHAR_FLGNUM,
}CHAR_DATAFLG;

#define CHAR_FS_PARTY			(1 << 0)
#define CHAR_FS_BATTLE		(1 << 1)
#define CHAR_FS_DUEL    	(1 << 2)
#define CHAR_FS_PARTYCHAT	(1 << 3)	//队伍频道开关
#define CHAR_FS_TRADECARD	(1 << 4)
#define CHAR_FS_TRADE			(1 << 5)
#ifdef _CHANNEL_MODIFY
#define CHAR_FS_TELL			(1 << 6)	//密语频道开关
#define CHAR_FS_FM				(1 << 7)	//家族频道开关
#define	CHAR_FS_OCC				(1 << 8)	//职业频道开关
#define	CHAR_FS_SAVE			(1 << 9)	//对话储存开关
#define CHAR_FS_CHAT			(1 << 10)	//聊天室开关
#endif
typedef enum
{
    CHAR_WORKBATTLEMODE,
    CHAR_WORKBATTLEINDEX,
    CHAR_WORKBATTLESIDE,
    CHAR_WORKBATTLECOM1,
    CHAR_WORKBATTLECOM2,
    CHAR_WORKBATTLECOM3,
#ifdef _PSKILL_MDFYATTACK
	CHAR_WORKBATTLECOM4,
#endif
    CHAR_WORKBATTLEFLG,
	CHAR_WORKBATTLEWATCH,

    CHAR_WORKFIXEARTHAT,
    CHAR_WORKFIXWATERAT,
    CHAR_WORKFIXFIREAT,
    CHAR_WORKFIXWINDAT,
#ifdef _PROFESSION_ADDSKILL
	CHAR_WORKFIXEARTHAT_BOUNDARY, //地结界  左16位元存放加强百分比 右16位元存放回合数
    CHAR_WORKFIXWATERAT_BOUNDARY, //水结界
    CHAR_WORKFIXFIREAT_BOUNDARY,  //火结界
	CHAR_WORKFIXWINDAT_BOUNDARY,  //风结界
#endif
	CHAR_WORKMAXHP,
    CHAR_WORKMAXMP,

    CHAR_WORKATTACKPOWER,
    CHAR_WORKDEFENCEPOWER,
    CHAR_WORKQUICK,

    CHAR_WORKFIXVITAL,
    CHAR_WORKFIXSTR,
    CHAR_WORKFIXTOUGH,
    CHAR_WORKFIXDEX,

#ifdef _ITEMSET5_TXT
	CHAR_WORKFIXARRANGE,
	CHAR_WORKARRANGEPOWER,
	CHAR_WORKFIXSEQUENCE,
	CHAR_WORKSEQUENCEPOWER,
	CHAR_WORKATTACHPILE,
	CHAR_WORKHITRIGHT,	//额外命中
#endif
#ifdef _ITEMSET6_TXT
	CHAR_WORKNEGLECTGUARD,
#endif
    CHAR_WORKMODATTACK,
    CHAR_WORKMODDEFENCE,
    CHAR_WORKMODQUICK,

    CHAR_WORKMODCAPTURE,
    CHAR_WORKMODCHARM,

    CHAR_WORKFIXCHARM,
    CHAR_WORKFIXLUCK,
    CHAR_WORKFIXAI,
    CHAR_WORKFIXAVOID,

	CHAR_WORKDAMAGEABSROB,
	CHAR_WORKDAMAGEREFLEC,
	CHAR_WORKDAMAGEVANISH,
    CHAR_WORKPOISON,
    CHAR_WORKPARALYSIS,
    CHAR_WORKSLEEP,
    CHAR_WORKSTONE,
    CHAR_WORKDRUNK,
    CHAR_WORKCONFUSION,
    CHAR_WORKWEAKEN,             //虚弱  vincent add  _MAGIC_WEAKEN
	CHAR_WORKDEEPPOISON,         //剧毒  vincent add _MAGIC_DEEPPOISON
	CHAR_WORKBARRIER,            //魔障  vincent add _MAGIC_BARRIER
	CHAR_WORKNOCAST,             //沉默  vincent add _MAGIC_NOCAST  
    CHAR_WORKMODPOISON,
    CHAR_WORKMODPARALYSIS,
    CHAR_WORKMODSLEEP,
    CHAR_WORKMODSTONE,
    CHAR_WORKMODDRUNK,
    CHAR_WORKMODCONFUSION,
	CHAR_WORKMODWEAKEN,
	CHAR_WORKMODDEEPPOISON,
	CHAR_WORKMODBARRIER,		//魔障
	CHAR_WORKMODNOCAST,			//沉默
	CHAR_WORKMODCRITICAL,		//一击必杀
    CHAR_WORKULTIMATE,
    CHAR_WORKPARTYMODE,
    CHAR_WORKTRADEMODE,         /* 交易模式
    							 * 0: CHAR_TRADE_FREE   :可交易
                                 * 1: CHAR_TRADE_SENDING:交易请求中
                                 * 2: CHAR_TRADE_TRADING:交易中
                                 * 3: CHAR_TRADE_LOCK   :交易锁定中
                                */
    CHAR_WORKPARTYINDEX1,
    CHAR_WORKPARTYINDEX2,
    CHAR_WORKPARTYINDEX3,
    CHAR_WORKPARTYINDEX4,
    CHAR_WORKPARTYINDEX5,
    CHAR_WORKOBJINDEX,
    CHAR_WORKWALKSTARTSEC,
    CHAR_WORKWALKSTARTMSEC,
    CHAR_WORKLOOPSTARTSEC,
    CHAR_WORKLOOPSTARTMSEC,
    CHAR_WORKLASTATTACKCHARAINDEX,
    CHAR_WORKEVENTTYPE,
    CHAR_WORKGETEXP,
	CHAR_WORKMODCAPTUREDEFAULT,
    CHAR_WORKACTION,
	CHAR_WORKFD,
	CHAR_WORKFLG,
	CHAR_WORKGMLEVEL,
    CHAR_NPCWORKINT1,
    CHAR_NPCWORKINT2,
    CHAR_NPCWORKINT3,
    CHAR_NPCWORKINT4,
    CHAR_NPCWORKINT5,
    CHAR_NPCWORKINT6,
    CHAR_NPCWORKINT7,
    CHAR_NPCWORKINT8,
    CHAR_NPCWORKINT9,
    CHAR_NPCWORKINT10,
    CHAR_NPCWORKINT11,
#ifdef _PETRACE
	CHAR_NPCWORKINT12,
#endif
	CHAR_NPCWORKINT13,
    CHAR_WORKWARPCHECK,
    CHAR_TENSEICHECKED,    
    CHAR_WORKFMINDEXI,		// 家族索引 index
    CHAR_WORKFMCHANNEL,		// 家族频道
    CHAR_WORKFMCHANNELQUICK,
    CHAR_WORKFMFLOOR,		// 家族据点图层
    CHAR_WORKFMDP,			// 家族ＤＰ值
    CHAR_WORKFMPKFLAG,		// 是否正参与家族ＰＫ 1:Yes
    CHAR_WORKFMSETUPFLAG,	// 家族是否已正式成立
    CHAR_WORKFMMANINDEX,	// FMWARPMAN Index
    CHAR_WORKFMCHARINDEX,	// 家族成员索引 index
    CHAR_WORKBATTLEFLAG,    // -1(战斗不能)，1(可战斗)    

	CHAR_WORK_PET0_STAT,        
	CHAR_WORK_PET1_STAT,
	CHAR_WORK_PET2_STAT,
	CHAR_WORK_PET3_STAT,
	CHAR_WORK_PET4_STAT,	

    CHAR_WORKLOGINTIME,		// 玩家登入时间
    CHAR_WORKTALKCOUNT,
    CHAR_WORKTALKTIME,
    CHAR_WORKPETFOLLOW,		// 宠物跟随
    CHAR_WORKPETFALL,		// 战斗落马
    CHAR_WORKLEADERCHANGE,	// 族长换位index
#ifdef _EQUIT_DEFMAGIC
	CHAR_EQUITDEFMAGIC_E,
	CHAR_EQUITDEFMAGIC_WA,
	CHAR_EQUITDEFMAGIC_F,
	CHAR_EQUITDEFMAGIC_WI,
	CHAR_EQUITQUIMAGIC,
#endif
#ifdef _EQUIT_RESIST
	CHAR_WORKEQUITFIRE,   //装备抗火
	CHAR_WORKEQUITTHUNDER,//装备抗雷
	CHAR_WORKEQUITICE,//装备抗冰
	CHAR_WORKEQUITWEAKEN,//装备抗虚弱
	CHAR_WORKEQUITBARRIER,//装备抗魔障
	CHAR_WORKEQUITNOCAST,//装备抗沉默
	CHAR_WORKEQUITFALLRIDE,//装备抗落马
#endif
#ifdef _PETMAIL_DEFNUMS
	CHAR_PETMAILNUMS,
	CHAR_PETMAILSENDTIME,
#endif
#ifdef _ITEM_METAMO
	CHAR_WORKITEMMETAMO,
#endif
#ifdef _ADD_DEAMGEDEFC
    CHAR_WORKOTHERDMAGE,
    CHAR_WORKOTHERDEFC,
#endif

#ifdef _LOSE_FINCH_ 
	CHAR_WORKSPETRELIFE,	//宠物复活特性
#endif

#ifdef _CHIKULA_STONE
	CHAR_WORKCHIKULAHP,
	CHAR_WORKCHIKULAMP,
#endif
#ifdef _PETSKILL_SETDUCK
	CHAR_MYSKILLDUCKPOWER,
	CHAR_MYSKILLDUCK,
	CHAR_MYSKILLSTRPOWER,
	CHAR_MYSKILLSTR,
	CHAR_MYSKILLTGHPOWER,
	CHAR_MYSKILLTGH,
	CHAR_MYSKILLDEXPOWER,
	CHAR_MYSKILLDEX,
	CHAR_MAGICPETMP,
#endif
	CHAR_SKILLSTRPOWER,
	CHAR_SKILLDEXPOWER,
#ifdef _NPC_MAKEPAIR
	CHAR_MYPAIRINDEX,
	CHAR_MYPAIRFLG,
	CHAR_MYPAIRCODE,
#endif
#ifdef _OTHER_MAGICSTAUTS
	CHAR_DEFMAGICSTATUS,
#ifdef _MAGIC_SUPERWALL
	CHAR_MAGICSUPERWALL,
#endif
	CHAR_OTHERSTATUSNUMS,
#endif
#ifdef _NPCCHANGE_PLAYERIMG
	CHAR_WORKNPCMETAMO,
#endif
	CHAR_PickAllPet,
#ifdef _DROPSTAKENEW
	CHAR_WORKSTAKEFLAG,
	CHAR_WORKSTAKETYPE1,
	CHAR_WORKSTAKETYPE2,
	CHAR_WORKSTAKETYPE3,
	CHAR_WORKSTAKETYPE4,
	CHAR_WORKSTAKETYPE5,
#endif

	CHAR_WORKTOXICATION,

#ifdef _SUIT_ITEM
	CHAR_WORKSUITITEM,
	CHAR_WORKROUNDHP,
	CHAR_WORKROUNDMP,
	CHAR_WORKSUITVIT,
	CHAR_WORKSUITSTR,
	CHAR_WORKSUITTGH,
	CHAR_WORKSUITDEX,
	CHAR_WORKSUITMODSTR,
#ifdef _SUIT_ADDENDUM
    CHAR_WORKRESIST, //异常抗性率
	CHAR_WORKCOUNTER,//反击率
	CHAR_WORKMPOWER, //加强法师的魔法( 受影响的法术:火山泉 火星球 召雷术 电流术 暴风雨 冰箭术 冰爆术 世界末日 火龙枪 嗜血成性 嗜血蛊 一针见血 附身术 )
#endif
#ifdef _SUIT_TWFWENDUM
	CHAR_WORK_EA,//地
	CHAR_WORK_WR,//水
	CHAR_WORK_FI,//火
	CHAR_WORK_WI,//风
#endif
#ifdef _SUIT_ADDPART3
	CHAR_WORKDUCKPOWER,//套装回避
    CHAR_WORKRENOCAST, //沉默抗性率
	CHAR_WORKSUITSTR_P,//攻提升 单位为%
	CHAR_WORKSUITTGH_P,//防提升 单位为%
	CHAR_WORKSUITDEX_P,//敏提升 单位为%
#endif
#ifdef _SUIT_ADDPART4
	CHAR_SUITPOISON,   //装备带毒
	CHAR_WORKMPOWER2,  //与CHAR_WORKMPOWER相同
	CHAR_WORKUNMPOWER, //抵抗法师的魔法( 受影响的法术:火山泉 火星球 召雷术 电流术 暴风雨 冰箭术 冰爆术 世界末日 火龙枪 嗜血成性 嗜血蛊 一针见血 附身术 )
#endif
#endif//_SUIT_ITEM

#ifdef _IMPRECATE_ITEM
	CHAR_WORKHURTMP,		//伤害 MP
	CHAR_WORKWISHESHP,		//祝福 hp
	CHAR_WORKWISHESMP,		//祝福 MP
	CHAR_WORKIMPRECATENUM1,
	CHAR_WORKIMPRECATENUM2,
	CHAR_WORKIMPRECATENUM3,
#endif
#ifdef _STATUS_WATERWORD
	CHAR_WORKMAPFLOORTYPE,
	CHAR_WORKSTATUSWATER,
#endif
#ifdef _BATTLENPC_WARP_PLAYER
	CHAR_WORKTURN,
#endif
#ifdef _MIND_ICON
	CHAR_MIND_NUM,
#endif
#ifdef _ITEM_CRACKER
	CHAR_WORKITEM_CRACKER,
#endif
#ifdef _ITEM_ADDEXP	//vincent 经验提升
	CHAR_WORKITEM_ADDEXP,
    CHAR_WORKITEM_ADDEXPTIME,
#endif
#ifdef _ALLDOMAN // (不可开) Syu ADD 排行榜NPC
	CHAR_WORKHEROFLOOR, 
#endif

#ifdef _PROFESSION_SKILL			// WON ADD 人物职业技能
	CHAR_ENCOUNT_FIX,		// 遇敌率
	CHAR_ENCOUNT_NUM,
	CHAR_WORK_F_PROFICIENCY,// 火熟练度
	CHAR_WORK_I_PROFICIENCY,// 冰熟练度
	CHAR_WORK_T_PROFICIENCY,// 电熟练度
	CHAR_WORK_F_RESIST,		// 火抗
	CHAR_WORK_I_RESIST,		// 冰抗
	CHAR_WORK_T_RESIST,		// 电抗
	CHAR_MYSKILLHIT,		// 命中率
	CHAR_MYSKILLHIT_NUM,		
	CHAR_WORKDIZZY,			// 晕眩
	CHAR_WORKMODDIZZY,
	CHAR_WORKENTWINE,		// 树根缠绕
	CHAR_WORKMODENTWINE,
	CHAR_WORKTRAP,			// 陷阱
	CHAR_WORKMODTRAP,
	CHAR_WORKDRAGNET,		// 天罗地网
	CHAR_WORKMODDRAGNET,
#ifdef _PROFESSION_ADDSKILL
	//***********注意:这里的位置不可更动*************
	CHAR_WORKICECRACK,		// 冰爆术	
	CHAR_WORKICECRACK2,		// 冰爆术存放处2
	CHAR_WORKICECRACK3,		// 冰爆术存放处3
	CHAR_WORKICECRACK4,		// 冰爆术存放处4
	CHAR_WORKICECRACK5,		// 冰爆术存放处5
	CHAR_WORKICECRACK6,		// 冰爆术存放处6
	CHAR_WORKICECRACK7,		// 冰爆术存放处7
	CHAR_WORKICECRACK8,		// 冰爆术存放处8
	CHAR_WORKICECRACK9,		// 冰爆术存放处9
	CHAR_WORKICECRACK10,	// 冰爆术存放处10
	CHAR_WORKMODICECRACK,
	CHAR_WORKMODICECRACK2,
	CHAR_WORKMODICECRACK3,
	CHAR_WORKMODICECRACK4,
	CHAR_WORKMODICECRACK5,
	CHAR_WORKMODICECRACK6,
	CHAR_WORKMODICECRACK7,
	CHAR_WORKMODICECRACK8,
	CHAR_WORKMODICECRACK9,
	CHAR_WORKMODICECRACK10,
	//*****************************************
#else
	CHAR_WORKICECRACK,		// 冰爆术	
	CHAR_WORKMODICECRACK,
#endif //_PROFESSION_ADDSKILL

	CHAR_WORKOBLIVION,		// 遗忘
	CHAR_WORKMODOBLIVION,
	CHAR_WORKICEARROW,		// 冰箭
	CHAR_WORKMODICEARROW,
	CHAR_WORKBLOODWORMS,	// 嗜血蛊
	CHAR_WORKMODBLOODWORMS,
	CHAR_WORKBLOODWORMSID,
	CHAR_WORKSIGN,			// 一针见血
	CHAR_WORKMODSIGN,
	CHAR_WORKSIGNID,
	CHAR_WORK_P_DUCK,		// 回避
	CHAR_WORKMOD_P_DUCK,
	CHAR_WORK_WEAPON,		// 武器专精
	CHAR_WORKMOD_WEAPON,
	CHAR_WORK_FOCUS,		// 专注战斗
	CHAR_WORKMOD_FOCUS,		
	CHAR_WORKINSTIGATE,		// 挑拨
	CHAR_WORKMODINSTIGATE,
	CHAR_WORK_F_ENCLOSE,	// 火附体
	CHAR_WORK_I_ENCLOSE,	// 冰附体
	CHAR_WORK_T_ENCLOSE,	// 雷附体
	CHAR_WORKMOD_F_ENCLOSE,
	CHAR_WORKMOD_I_ENCLOSE,
	CHAR_WORKMOD_T_ENCLOSE,
	CHAR_WORK_F_ENCLOSE_2,	// 火附	
	CHAR_WORK_I_ENCLOSE_2,	// 冰附
	CHAR_WORK_T_ENCLOSE_2,	// 雷附
	CHAR_WORKMOD_F_ENCLOSE_2,	
	CHAR_WORKMOD_I_ENCLOSE_2,
	CHAR_WORKMOD_T_ENCLOSE_2,
	CHAR_WORKRESIST_F,		// 提升火抗性
	CHAR_WORKRESIST_I,		// 提升冰抗性
	CHAR_WORKRESIST_T,		// 提升雷抗性
#ifdef _PROFESSION_ADDSKILL
    CHAR_WORKERSIST_F_I_T,  // 提升火冰雷抗性
	CHAR_WORKANNEX,         //附身
	CHAR_WORKWATER,         //水附体
	CHAR_WORKFEAR,			//恐惧
	CHAR_DOOMTIME,			//世界末日集气(与火龙枪共用)
	CHAR_WORK_com1,
	CHAR_WORK_toNo,
	CHAR_WORK_mode,
	CHAR_WORK_skill_level,
	CHAR_WORK_array,
#endif
	CHAR_WORKMODRESIST_F,   // 提升火抗性百分比数值
	CHAR_WORKMODRESIST_I,   // 提升冰抗性百分比数值
	CHAR_WORKMODRESIST_T,   // 提升雷抗性百分比数值
#endif

#ifdef _MAGICSTAUTS_RESIST
	CHAR_MAGICFIRE, //火抗精灵
	CHAR_MAGICTHUNDER,//电抗精灵
	CHAR_MAGICICE,//冰抗精灵
#endif

#ifdef _PET_SKILL_SARS			// WON ADD 毒煞蔓延
	CHAR_WORKSARS,
	CHAR_WORKMODSARS,
#endif

#ifdef _PETSKILL_ACUPUNCTURE
    CHAR_WORKACUPUNCTURE,
#endif
#ifdef _PETSKILL_RETRACE
	CHAR_WORKRETRACE,
#endif

#ifdef _CHATROOMPROTOCOL			// (不可开) Syu ADD 聊天室频道
	CHAR_WORKCHATROOMTYPE , 
	CHAR_WORKCHATROOMNUM , 
#endif

#ifdef _MAGIC_RESIST_EQUIT			// WON ADD 职业抗性装备
	 CHAR_WORK_F_SUIT,
	 CHAR_WORK_I_SUIT,
	 CHAR_WORK_T_SUIT,
#endif

#ifdef _PETSKILL_BECOMEFOX
     CHAR_WORKFOXROUND,  //计算狐狸变身回合数
#endif

	CHAR_WORKSTANDBYPET, // Robin add 待机宠
#ifdef _STREET_VENDOR
	CHAR_WORKSTREETVENDOR, // 摆摊状态 -1:没在摆摊,也没在摆摊交易;1:摆摊中;2:卖方在交易中;3:摆摊的买方
	CHAR_WORKSTREETVENDOR_WHO, // 谁和我交易
#endif

#ifdef _ANGEL_SUMMON
	CHAR_WORKMISSION,
	CHAR_WORKANGELMODE,
#endif
#ifdef _MAP_TIME
	CHAR_WORK_MAP_TIME,	// 特殊地图倒数
#endif
#ifdef _PETSKILL_LER
	CHAR_WORK_RELIFE,		// 雷尔复活
#endif
#ifdef _TEACHER_SYSTEM
	CHAR_WORK_GET_TEACHER_FAME,	// 导师领导声望
#endif

	CHAR_WORKSKYWALKER, // GM天行者??

	CHAR_WORKLASTMERGETIME, // 最後合成时间

#ifdef _FONT_SIZE
	CHAR_WORKFONTSIZE, // 
#endif

#ifdef _TIME_TICKET
	CHAR_WORKTICKETTIME,
	CHAR_WORKTICKETTIMESTART,
#endif

	CHAR_WORKDEBUGMODE, // 除错模式中

	CHAR_WORKDATAINTNUM,


    CHAR_WORKENCOUNTPROBABILITY_MIN = CHAR_NPCWORKINT1,
    CHAR_WORKENCOUNTPROBABILITY_MAX = CHAR_NPCWORKINT2,
    CHAR_WORK_TOHELOS_CUTRATE = CHAR_NPCWORKINT3,
    CHAR_WORK_TOHELOS_COUNT = CHAR_NPCWORKINT4,
    CHAR_WORKSHOPRELEVANT = CHAR_NPCWORKINT5,
    CHAR_WORKSHOPRELEVANTSEC = CHAR_NPCWORKINT6,
    CHAR_WORKSHOPRELEVANTTRD = CHAR_NPCWORKINT7,
    CHAR_WORKTRADER = CHAR_NPCWORKINT8,
	CHAR_WORKEFFECT = CHAR_NPCWORKINT9,
	CHAR_WORKRENAMEITEMNUM = CHAR_NPCWORKINT10, 
	CHAR_WORKRENAMEITEMINDEX = CHAR_NPCWORKINT5,
    CHAR_WORKPLAYERINDEX = CHAR_NPCWORKINT1,
    CHAR_WORKTACTICS = CHAR_NPCWORKINT2,
    CHAR_WORKPETFOLLOWMODE = CHAR_NPCWORKINT3,
    CHAR_WORKPETFOLLOWCOUNT = CHAR_NPCWORKINT4,
	CHAR_WORK_PETFLG = CHAR_NPCWORKINT1,
    CHAR_WORKGENERATEINDEX = CHAR_NPCWORKINT1,
    CHAR_WORKDOORCLOSETIME  = CHAR_NPCWORKINT1,
    CHAR_WORKDOORSWITCHCOUNT = CHAR_NPCWORKINT2,
    CHAR_WORKDOOROPENG = CHAR_NPCWORKINT3,
    CHAR_WORKDOORCLOSEG = CHAR_NPCWORKINT4,
    CHAR_WORKDOORSOONFLG = CHAR_NPCWORKINT5,
    CHAR_WORKDOORPASSFLG = CHAR_NPCWORKINT6,
    CHAR_WORKDOORKEYITEMID = CHAR_NPCWORKINT7,
    CHAR_WORKDOORSWITCHCURRENT = CHAR_NPCWORKINT8,
    CHAR_WORKDOORORIGINALGRAPHIC = CHAR_NPCWORKINT9,
    CHAR_WORKDOOREXPIRETIME = CHAR_NPCWORKINT10,
    CHAR_WORKOLDMANID = CHAR_NPCWORKINT1,
    CHAR_WORKSHOPCLIENTINDEX = CHAR_NPCWORKINT1,
    CHAR_WORKDENGONMAXID = CHAR_NPCWORKINT1,

}CHAR_WORKDATAINT;


enum{
	WORKFLG_DEBUGMODE = ( 1 << 0 ),
	WORKFLG_MICMODE = ( 2 << 0 ),
};

typedef enum
{
    CHAR_INITFUNC,
    CHAR_FIRSTFUNCTION = CHAR_INITFUNC,
    CHAR_WALKPREFUNC,
    CHAR_WALKPOSTFUNC,
    CHAR_PREOVERFUNC,
    CHAR_POSTOVERFUNC,
    CHAR_WATCHFUNC,
    CHAR_LOOPFUNC,
    CHAR_DYINGFUNC,
    CHAR_TALKEDFUNC,
    CHAR_PREATTACKEDFUNC,
    CHAR_POSTATTACKEDFUNC,
    CHAR_OFFFUNC,
    CHAR_LOOKEDFUNC,
    CHAR_ITEMPUTFUNC,
    CHAR_SPECIALTALKEDFUNC,
    CHAR_WINDOWTALKEDFUNC,
#ifdef _USER_CHARLOOPS
	CHAR_LOOPFUNCTEMP1,
	CHAR_LOOPFUNCTEMP2,
	CHAR_BATTLEPROPERTY,
#endif
    CHAR_LASTFUNCTION,
    CHAR_FUNCTABLENUM = CHAR_LASTFUNCTION,
}CHAR_FUNCTABLE;

typedef enum
{
    CHAR_WORKWALKARRAY,
    CHAR_NPCWORKCHAR1,
    CHAR_NPCWORKCHAR2,
    CHAR_NPCWORKCHAR3,
    CHAR_NPCWORKCHAR4,
    CHAR_NPCWORKCHAR5,
    CHAR_NPCWORKCHAR6,
#ifdef _ANGEL_SUMMON
	CHAR_WORKHEROINFO,
#endif
#ifdef _STREET_VENDOR
	CHAR_STREETVENDOR_NAME,
#endif
	CHAR_WORKDATACHARNUM,
    CHAR_WORKBATTLE_TACTICSOPTION = CHAR_NPCWORKCHAR1,
#ifdef _BATTLENPC_WARP_PLAYER
	CHAR_WORKBATTLE_ACT_CONDITION = CHAR_NPCWORKCHAR2,
#endif
    CHAR_WORKDOORPASSWD			= CHAR_NPCWORKCHAR1,
    CHAR_WORKDOORNAME			= CHAR_NPCWORKCHAR2,
    CHAR_WORKDOORGOLDLIMIT		= CHAR_NPCWORKCHAR3,
    CHAR_WORKDOORWEEK			= CHAR_NPCWORKCHAR4,
    CHAR_WORKDOORHOUR			= CHAR_NPCWORKCHAR5,
    CHAR_WORKDOORMINUTE			= CHAR_NPCWORKCHAR6,
    CHAR_WORKDOORTITLE			= CHAR_NPCWORKCHAR6,
    CHAR_WORKDOORMANDOORNAME	= CHAR_NPCWORKCHAR1,
    CHAR_TIME1,
    CHAR_TIME2			= CHAR_NPCWORKCHAR6,
	
}CHAR_WORKDATACHAR;


typedef enum
{
    CHAR_IMAGETYPE_GIRL,
    CHAR_IMAGETYPE_BOY,
    CHAR_IMAGETYPE_CHILDBOY,
    CHAR_IMAGETYPE_CHILDGIRL,
    CHAR_IMAGETYPE_MAN,
    CHAR_IMAGETYPE_WOMAN,
    CHAR_IMAGETYPE_OLDMAN,
    CHAR_IMAGETYPE_DOG,
    CHAR_IMAGETYPENUM
}CHAR_ImageType;


#define			CHAR_P_STRING_HP				( 1 << 1  )		// 0x00000002
#define			CHAR_P_STRING_MAXHP				( 1 << 2  )		// 0x00000004
#define			CHAR_P_STRING_MP				( 1 << 3  )		// 0x00000008
#define			CHAR_P_STRING_MAXMP				( 1 << 4  )		// 0x00000010
#define			CHAR_P_STRING_VITAL				( 1 << 5  )
#define			CHAR_P_STRING_STR				( 1 << 6  )
#define			CHAR_P_STRING_TOUGH				( 1 << 7  )
#define			CHAR_P_STRING_DEX				( 1 << 8  )
#define			CHAR_P_STRING_EXP				( 1 << 9  )
#define			CHAR_P_STRING_NEXTEXP			( 1 << 10 )
#define			CHAR_P_STRING_LV				( 1 << 11 )
#define			CHAR_P_STRING_ATK				( 1 << 12 )
#define			CHAR_P_STRING_DEF				( 1 << 13 )
#define			CHAR_P_STRING_QUICK				( 1 << 14 )
#define			CHAR_P_STRING_CHARM				( 1 << 15 )
#define			CHAR_P_STRING_LUCK				( 1 << 16 )
#define			CHAR_P_STRING_EARTH				( 1 << 17 )
#define			CHAR_P_STRING_WATER				( 1 << 18 )
#define			CHAR_P_STRING_FIRE				( 1 << 19 )
#define			CHAR_P_STRING_WIND				( 1 << 20 )
#define			CHAR_P_STRING_GOLD				( 1 << 21 )
#define			CHAR_P_STRING_TITLE				( 1 << 22 )
#define			CHAR_P_STRING_DUELPOINT			( 1 << 23 )
#define			CHAR_P_STRING_TRANSMIGRATION	( 1 << 24 )
#define			CHAR_P_STRING_NAME				( 1 << 25 )
#define			CHAR_P_STRING_OWNTITLE			( 1 << 26 )
#define			CHAR_P_STRING_RIDEPET			( 1 << 27 )		// 0x08000000
#define			CHAR_P_STRING_LEARNRIDE			( 1 << 28 )		// 0x10000000
#define			CHAR_P_STRING_BASEBASEIMAGENUMBER	( 1 << 29 )		// 0x20000000
//#define			CHAR_P_STRING_PKDP				( 1 << 30 )
//#ifdef _CHAR_PROFESSION
//#define			CHAR_P_STRING_PROFESSION				( 1 << 30 )
//#endif
#define			CHAR_P_STRING_SKYWALKER			( 1 << 30 )		// 0x40000000
#define			CHAR_P_STRING_DEBUGMODE			( 1 << 31 )		// 0x80000000



#define			CHAR_N_STRING_OBJINDEX			( 1 << 1  )
#define			CHAR_N_STRING_LV				( 1 << 2  )
#define			CHAR_N_STRING_MAXHP				( 1 << 3  )
#define			CHAR_N_STRING_HP				( 1 << 4  )
#define			CHAR_N_STRING_MP				( 1 << 5  )
#define			CHAR_N_STRING_NAME				( 1 << 6  )

#define			CHAR_K_STRING_BASEIMAGENUMBER   ( 1 << 1  )
#define			CHAR_K_STRING_HP				( 1 << 2  )
#define			CHAR_K_STRING_MAXHP				( 1 << 3  )
#define			CHAR_K_STRING_MP				( 1 << 4  )
#define			CHAR_K_STRING_MAXMP				( 1 << 5  )
#define			CHAR_K_STRING_EXP				( 1 << 6  )
#define			CHAR_K_STRING_NEXTEXP			( 1 << 7  )
#define			CHAR_K_STRING_LV				( 1 << 8  )
#define			CHAR_K_STRING_ATK				( 1 << 9  )
#define			CHAR_K_STRING_DEF				( 1 << 10 )
#define			CHAR_K_STRING_QUICK				( 1 << 11 )
#define			CHAR_K_STRING_AI				( 1 << 12 )
#define			CHAR_K_STRING_EARTH				( 1 << 13 )
#define			CHAR_K_STRING_WATER				( 1 << 14 )
#define			CHAR_K_STRING_FIRE				( 1 << 15 )
#define			CHAR_K_STRING_WIND				( 1 << 16 )
#define			CHAR_K_STRING_SLOT				( 1 << 17 )
#define			CHAR_K_STRING_CHANGENAMEFLG		( 1 << 18 )
#define			CHAR_K_STRING_NAME				( 1 << 19 )
#define			CHAR_K_STRING_USERPETNAME		( 1 << 20 )

typedef union {
	int		indexOfPet[CHAR_MAXPETHAVE];
    int		indexOfPetskill[CHAR_MAXPETSKILLHAVE];
}CHAR_UNIONTABLE;

typedef struct tagChar
{
    BOOL        use;

    int			data[CHAR_DATAINTNUM];
    STRING128	string[CHAR_DATACHARNUM];
    char        flg[(CHAR_FLGNUM%(sizeof(char)*8))
                   ? (CHAR_FLGNUM/(sizeof(char)*8))+1
                   : (CHAR_FLGNUM/(sizeof(char)*8))];
    int			indexOfExistItems[CHAR_MAXITEMHAVE];
    int			indexOfExistPoolItems[CHAR_MAXPOOLITEMHAVE];

#ifdef _CHAR_POOLITEM
	int			*indexOfExistDepotItems;
#endif
#ifdef _CHAR_POOLPET
	int			*indexOfExistDepotPets;
#endif

    CHAR_HaveSkill		haveSkill[CHAR_SKILLMAXHAVE];
    int			indexOfHaveTitle[CHAR_TITLEMAXHAVE];
    ADDRESSBOOK_entry	addressBook[ADDRESSBOOK_MAX];
    CHAR_UNIONTABLE		unionTable;
    int			indexOfPoolPet[CHAR_MAXPOOLPETHAVE];
    STRING32    charfunctable[CHAR_FUNCTABLENUM];
    int         workint[CHAR_WORKDATAINTNUM];
    STRING64    workchar[CHAR_WORKDATACHARNUM];
    int         CharMakeSequenceNumber;
    void*       functable[CHAR_FUNCTABLENUM];
#ifdef _STREET_VENDOR
		StreetVendor_t StreetVendor[MAX_SELL_ITEM];
#endif
}Char;


#define		CHAR_CHECKINDEX( index)	_CHAR_CHECKINDEX( __FILE__, __LINE__, index)
INLINE BOOL _CHAR_CHECKINDEX( char *file, int line, int index);
#define		CHAR_CHECKITEMINDEX( charaindex, iindex) _CHAR_CHECKITEMINDEX( __FILE__, __LINE__, charaindex, iindex)
INLINE BOOL _CHAR_CHECKITEMINDEX( char *file, int line, int charaindex, int iindex );
#define		CHAR_CHECKPETINDEX( petindex) _CHAR_CHECKPETINDEX( __FILE__, __LINE__, petindex )
INLINE BOOL _CHAR_CHECKPETINDEX( char *file, int line, int petindex );
#define		CHAR_CHECKPOOLPETINDEX( petindex) _CHAR_CHECKPOOLPETINDEX( __FILE__, __LINE__, petindex )
INLINE BOOL _CHAR_CHECKPOOLPETINDEX( char *file, int line, int petindex );
#define		CHAR_CHECKPETSKILLINDEX( havepetskillindex) _CHAR_CHECKPETSKILLINDEX( __FILE__, __LINE__, havepetskillindex)
INLINE BOOL _CHAR_CHECKPETSKILLINDEX( char *file, int line, int havepetskillindex );

INLINE int CHAR_getInt( int index , CHAR_DATAINT element);
#define CHAR_setInt( index , element, data) _CHAR_setInt( __FILE__, __LINE__, index , element, data)
INLINE int _CHAR_setInt( char *file, int line, int index ,CHAR_DATAINT element, int data);
#ifdef _FIX_SETWORKINT
#define CHAR_getWorkInt( index , element) _CHAR_getWorkInt( __FILE__, __LINE__, index , element)
INLINE int _CHAR_getWorkInt( char *file, int line, int index ,CHAR_WORKDATAINT element);
#define CHAR_setWorkInt( index, element, data) _CHAR_setWorkInt( __FILE__, __LINE__, index , element, data)
INLINE int _CHAR_setWorkInt( char *file, int line, int index ,CHAR_WORKDATAINT element, int data);
#else
INLINE int CHAR_setWorkInt( int index ,CHAR_WORKDATAINT element, int data);
#endif
#define		CHAR_getChar( index, elem) _CHAR_getChar( __FILE__, __LINE__, index, elem)
INLINE char* _CHAR_getChar( char *file, int line, int index ,CHAR_DATACHAR element );
#define		CHAR_setChar( index, elem, n) _CHAR_setChar( __FILE__, __LINE__, index, elem, n)
INLINE BOOL _CHAR_setChar( char *file, int line, int index ,CHAR_DATACHAR element, char* new );
#define		CHAR_getFlg( index, elem) _CHAR_getFlg( __FILE__, __LINE__, index, elem)
INLINE BOOL _CHAR_getFlg( char *file, int line, int index ,CHAR_DATAFLG element );
#define		CHAR_setFlg( index, elem, n) _CHAR_setFlg( __FILE__, __LINE__, index, elem, n)
INLINE BOOL _CHAR_setFlg( char *file, int line, int index , CHAR_DATACHAR element, int newdata );
#define		CHAR_getWorkChar( index, elem) _CHAR_getWorkChar( __FILE__, __LINE__, index, elem)
INLINE char * _CHAR_getWorkChar( char *file, int line, int index, CHAR_WORKDATACHAR element );
#define		CHAR_setWorkChar( index, elem, n) _CHAR_setWorkChar( __FILE__, __LINE__, index, elem, n)
INLINE BOOL _CHAR_setWorkChar( char *file, int line, int index, CHAR_WORKDATACHAR element, char * new);

#define		CHAR_getItemIndex( index, iindex) _CHAR_getItemIndex( __FILE__, __LINE__, index, iindex)
INLINE int _CHAR_getItemIndex( char *file, int line, int charaindex, int ti);
#define		CHAR_setItemIndex( index, iindex,id) _CHAR_setItemIndex( __FILE__, __LINE__, index, iindex, id)
INLINE int _CHAR_setItemIndex( char *file, int line, int index ,int iindex,int id );
#define		CHAR_getPoolItemIndex( index, iindex) _CHAR_getPoolItemIndex( __FILE__, __LINE__, index, iindex)
INLINE int _CHAR_getPoolItemIndex( char *file, int line, int index, int iindex);
#define		CHAR_setPoolItemIndex( index, iindex,id) _CHAR_setPoolItemIndex( __FILE__, __LINE__, index, iindex, id)
INLINE int _CHAR_setPoolItemIndex( char *file, int line, int index ,int iindex,int id );
INLINE BOOL CHAR_setAddressbookEntry( int index , int aindex , ADDRESSBOOK_entry *a );
INLINE ADDRESSBOOK_entry* CHAR_getAddressbookEntry( int index , int aindex);
INLINE Char* CHAR_getCharPointer( int index );
INLINE int CHAR_getCharNum( void );
INLINE int CHAR_getPlayerMaxNum( void );
INLINE int CHAR_getPetMaxNum( void );
INLINE int CHAR_getOthersMaxNum( void );
INLINE BOOL CHAR_getCharUse( int index );
INLINE CHAR_HaveSkill* CHAR_getCharHaveSkill( int index,int sindex );
INLINE int  CHAR_getCharHaveTitle( int index,int tindex );
INLINE int CHAR_setCharHaveTitle( int charaindex,int tindex, int new );
INLINE int CHAR_getCharPet( int charaindex,int petindex );
INLINE int CHAR_setCharPet( int charaindex,int petindex, int new );
INLINE int CHAR_getCharPoolPet( int charaindex,int petindex );
INLINE int CHAR_setCharPoolPet( int charaindex,int petindex, int new );
int CHAR_getCharPetElement( int charaindex );
int CHAR_getCharPoolPetElement( int charaindex );
int CHAR_getCharPoolItemIndexElement( int charaindex );
int CHAR_getEmptyCharPoolItemIndexNum( int charaindex);
#ifdef _CHAR_POOLPET
int CHAR_getCharDepotPetElement( int charaindex );
#endif
#define		CHAR_getIntPSkill( index, skillti, ti) _CHAR_getIntPSkill( __FILE__, __LINE__, index, skillti, ti)
INLINE int _CHAR_getIntPSkill( char *file, int line, int index, int skillti, SKILL_DATAINT ti);

#define		CHAR_setIntPSkill( index, skillti, ti, data) _CHAR_setIntPSkill( __FILE__, __LINE__, index, skillti, ti, data)
INLINE void _CHAR_setIntPSkill( char *file, int line, int index, int skillti, SKILL_DATAINT ti, int data);


extern Char *CHAR_chara;


INLINE int CHAR_getCharMakeSequenceNumber( int charaindex );
void CHAR_constructFunctable( int charaindex );
void* CHAR_getFunctionPointer( int charaindex, int functype );
BOOL CHAR_initCharArray( int pnum,  int petnum,int onum );
BOOL CHAR_endCharArray( void );
int CHAR_initCharOneArray( Char* ch );
void CHAR_endCharOneArray( int index );
void CHAR_removeHaveItem( Char* ch );
void CHAR_endCharData( Char* ch );
char* CHAR_makeStringFromCharData( Char* one );
char* CHAR_makeStringFromCharIndex( int index );
BOOL CHAR_makeCharFromStringToArg( char* data, Char* one);
int CHAR_makePetFromStringToArg( char *src, Char *ch, int ti);
char *CHAR_makePetStringFromPetIndex( int petindex);
#define CHAR_getPetSkillElement( petindex) _CHAR_getPetSkillElement( __FILE__, __LINE__, petindex)
int _CHAR_getPetSkillElement( char *file, int line, int petindex );
#define	CHAR_setPetSkill( petindex, havepetskillindex, n) _CHAR_setPetSkill( __FILE__, __LINE__, petindex, havepetskillindex, n)
INLINE int _CHAR_setPetSkill( char *file, int line, int petindex,int havepetskillindex, int new );
#define		CHAR_getPetSkill( petindex, havepetskillindex) _CHAR_getPetSkill( __FILE__, __LINE__, petindex, havepetskillindex)
INLINE int _CHAR_getPetSkill( char *file, int line, int petindex,int havepetskillindex );
#define SETFLG(a,b,c,d,e,f,g,h) (((a)<<0)+((b)<<1)+((c)<<2)+((d)<<3)+((e)<<4)+((f)<<5)+((g)<<6)+((h)<<7))

INLINE int CHAR_AddMaxExp( int charaindex, int addexp);
INLINE int CHAR_setMaxExpFromLevel( int charaindex, int level);
INLINE int CHAR_setMaxExp( int charaindex, unsigned long int Setexp);
#ifdef _NEWOPEN_MAXEXP
INLINE int CHAR_ChangeExp( int charaindex );
INLINE int CHAR_HandleExp( int charaindex );

#endif

// ride Pet table
typedef struct tagtagRidePetTable
{
	int rideNo;
	int charNo;
	int petNo;
	int petId;
	
} tagRidePetTable;


// CoolFish: Family Member Kind 2001/8/28
typedef enum
{
	FMMEMBER_NONE = -1,
	FMMEMBER_MEMBER = 1,
	FMMEMBER_APPLY,
	FMMEMBER_LEADER,
	FMMEMBER_ELDER,
} CHAR_FM_MEMBERKIND;

// shan 2002/01/10
typedef enum
{
	PET_STAT_NONE = 0,
	PET_STAT_SELECT,		
	PET_STAT_MAIL = 4,	
} CHAR_PET_STAT;


#ifdef _PERSONAL_FAME	// Arminius: 家族个人声望
void CHAR_earnFame(int index, int fame);
#endif

// CoolFish: 2001/10/11
#ifdef _UNIQUE_P_I
void CHAR_setPetUniCode(int petindex);
void ITEM_setItemUniCode(int itemindex);
void Check_P_I_UniCode(int charindex);
#endif

// Arminius 12.15 判断是否是男士
int IsMale(int charindex);

// Arminius 12.15 判断是否是女士
int IsFemale(int charindex);


#ifdef _NEW_RIDEPETS
#define RIDE_PET0	1
#define RIDE_PET1	( 1 << 1 )
#define RIDE_PET2	( 1 << 2 )
#define RIDE_PET3	( 1 << 3 )
#define RIDE_PET4	( 1 << 4 )
#define RIDE_PET5	( 1 << 5 )
#define RIDE_PET6	( 1 << 6 )
#define RIDE_PET7	( 1 << 7 )
#define RIDE_PET8	( 1 << 8 )
#define RIDE_PET9	( 1 << 9 )
#define RIDE_PET10	( 1 << 11 )
#define RIDE_PET11	( 1 << 10 )
#define RIDE_PET12	( 1 << 12 )
#define RIDE_PET13	( 1 << 13 )
#define RIDE_PET14	( 1 << 14 )
#ifdef _RIDE_CF
#define RIDE_PET15 ( 1 << 15 )
#define RIDE_PET16 ( 1 << 16 )
#define RIDE_PET17 ( 1 << 17 )
#define RIDE_PET19 ( 1 << 19 )
#define RIDE_PET18 ( 1 << 18 )
#define RIDE_PET20 ( 1 << 20 )
#define RIDE_PET21 ( 1 << 21 )
#define RIDE_PET22 ( 1 << 22 )
#define RIDE_PET23 ( 1 << 23 )
#define RIDE_PET24 ( 1 << 24 )
#define RIDE_PET25 ( 1 << 25 )
#define RIDE_PET26 ( 1 << 26 )
#define RIDE_PET27 ( 1 << 27 )
#define RIDE_PET28 ( 1 << 28 )
#define RIDE_PET29 ( 1 << 29 )
#define RIDE_PET30 ( 1 << 30 )
#define RIDE_PET31 ( 1 << 31 )

#define RIDE_TPYE1 1
#define RIDE_TPYE2 ( 1 << 1 )

#define RIDE_PET_ALL	( 0xFFFFFFFF )
#define RIDE_TPYE_ALL	( 0xFFFFFFFF )
#define MAXNOINDEX 32*2
#else
#define RIDE_PET_ALL	( RIDE_PET0|RIDE_PET1|RIDE_PET2|RIDE_PET3|RIDE_PET4|RIDE_PET5|RIDE_PET6|RIDE_PET7|RIDE_PET8|RIDE_PET9|RIDE_PET10|RIDE_PET11 )
#define MAXNOINDEX 15
#endif


#ifdef _PET_BEATITUDE
#define BEATITUDE_VITAL ( 1 << 0 )
#define BEATITUDE_STR   ( 1 << 1 )
#define BEATITUDE_TOUGH ( 1 << 2 )
#define BEATITUDE_DEX   ( 1 << 3 )
#endif

#ifdef _FM_LEADER_RIDE
typedef struct	{
	int fmfloor;
	int ride[3];
}tagFmLeaderRide;
#endif

#ifdef _FM_LEADER_RIDE
int CHAR_FmLeaderRide(int meindex,int pet);
#endif

typedef struct	{
	int petNo;
#ifdef _RIDE_CF	
	int petNo1;
#endif
	unsigned int learnCode;
}tagRideCodeMode;

typedef struct	{
	int RideNo[MAXNOINDEX];
	int flg;
}tagRideNoList;

typedef struct	{
	int charNo;
	int Noindex;
	int sex;
}tagRidePetList;

int RIDEPET_getNOindex( int baseNo);
#ifdef _RIDE_CF	
int RIDEPET_getPETindex( int PetNo, unsigned int learnCode, int unsigned learnCode1 );
#else
int RIDEPET_getPETindex( int PetNo, unsigned int learnCode);
#endif
int RIDEPET_getRIDEno( int index, int ti);
#endif

#ifdef _FUSION_TWO
int CHAR_OldFusion_init();
#endif

#ifdef _PET_EVOLUTION
int EVOLUTION_getPetTable( int charaindex, int petindex1, int petindex2);
int EVOLUTION_getPropertyTable( int charaindex, int petindex1, int petindex2);
int EVOLUTION_getFusionTable( int charaindex, int px, int py);
int EVOLUTION_getPetFusionCode( int petid);
#endif

#ifdef _EMENY_CHANCEMAN
int CHAR_getSexInt( int baseNo );
#endif
#ifdef _TYPE_TOXICATION
BOOL CHAR_CanCureFlg( int charaindex, char *arg);
#endif

BOOL CHAR_getCharOnArrayPercentage( int mode, int *max, int *min, int *cnt);


#define	CHAR_DelItemMess( index, ti, flg) _CHAR_DelItem( __FILE__, __LINE__, index, ti, 1, flg)
#define	CHAR_DelItem( index, ti) _CHAR_DelItem( __FILE__, __LINE__, index, ti, 1, 1)
#define	CHAR_DelPileItemMess( index, ti, num, flg) _CHAR_DelItem( __FILE__, __LINE__, index, ti, num, flg)

#define	CHAR_AddPileItem( index, itemindex) _CHAR_AddPileItem( __FILE__, __LINE__, index, itemindex)
INLINE int _CHAR_AddPileItem( char *file, int line, int charaindex, int itemindex);

INLINE int _CHAR_DelItem( char *file, int line, int charaindex, int ti, int num, int flg);

#define	CHAR_AddGold( index, ti) _CHAR_AddGold( __FILE__, __LINE__, index, ti)
INLINE int _CHAR_AddGold( char *file, int line, int charaindex, int gold);
#define	CHAR_DelGold( index, ti) _CHAR_DelGold( __FILE__, __LINE__, index, ti)
INLINE int _CHAR_DelGold( char *file, int line, int charaindex, int gold);
int CHAR_getMaxHaveGold( int charaindex);


#ifdef _CHAR_PROFESSION			// WON ADD 人物职业

int CHAR_getCharSkill( int index,int sindex );
int CHAR_setCharSkill( int index,int sindex,int new );
#define CHAR_CHECK_PROFESSION_SKILLINDEX( skillindex) _CHAR_CHECK_PROFESSION_SKILLINDEX( __FILE__, __LINE__, skillindex)
INLINE BOOL _CHAR_CHECK_PROFESSION_SKILLINDEX( char *file, int line, int skillindex );
#define	PROFESSION_SKILL_getSkill( charaindex, skillindex) _PROFESSION_SKILL_getSkill( __FILE__, __LINE__, charaindex, skillindex)
INLINE int _PROFESSION_SKILL_getSkill( char *file, int line, int charaindex, int skillindex );
#define	PROFESSION_SKILL_setSkill( charaindex, skillindex, n) _PROFESSION_SKILL_setSkill( __FILE__, __LINE__, charaindex, skillindex, n)
INLINE int _PROFESSION_SKILL_setSkill( char *file, int line, int charaindex,int skillindex, int new );
#define PROFESSION_SKILL_getSkillElement(charaindex) _PROFESSION_SKILL_getSkillElement( __FILE__, __LINE__, charaindex)
int _PROFESSION_SKILL_getSkillElement( char *file, int line, int charaindex );

#endif

#ifdef _NPC_SEPARATEDATA
void CHAR_showTempInt( int index);
BOOL CHAR_InitCharTempNum( Char* ch );
void CHAR_EndCharTempNum( void);
void CHAR_getDefaultCharTempNum( Char* ch );
#endif

#ifdef _CHAR_POOLITEM

#define	CHAR_getDepotItemIndex( index, iindex) _CHAR_getDepotItemIndex( __FILE__, __LINE__, index, iindex)
INLINE int _CHAR_getDepotItemIndex( char *file, int line, int index ,int iindex);
#define	CHAR_setDepotItemIndex( index, iindex,id) _CHAR_setDepotItemIndex( __FILE__, __LINE__, index, iindex, id)
INLINE int _CHAR_setDepotItemIndex( char *file, int line, int index ,int iindex,int id );

void CHAR_removeHaveDepotItem( Char* ch);
void CHAR_removeDepotItem( int charaindex);

char *CHAR_makeDepotItemFromCharIndex( int charaindex);
BOOL CHAR_makeDepotItemStringToChar( int charaindex, char* data);

BOOL CHAR_SaveDepotItem( int charaindex);
BOOL CHAR_GetDepotItem( int meindex, int charaindex);
void CHAR_ShowMyDepotItems( int charaindex);

int CHAR_findEmptyDepotItem( int charaindex);
int CHAR_getfindEmptyDepotItem( int charaindex);
BOOL CHAR_CheckDepotItem( int charaindex);
#endif

#ifdef _CHAR_POOLPET

#define	CHAR_getDepotPetIndex( index, iindex) _CHAR_getDepotPetIndex( __FILE__, __LINE__, index, iindex)
INLINE int _CHAR_getDepotPetIndex( char *file, int line, int index ,int iindex);
#define	CHAR_setDepotPetIndex( index, iindex,id) _CHAR_setDepotPetIndex( __FILE__, __LINE__, index, iindex, id)
INLINE int _CHAR_setDepotPetIndex( char *file, int line, int index ,int iindex,int id );

void CHAR_removeHaveDepotPet( Char* ch);
void CHAR_removeDepotPet( int charaindex);

char *CHAR_makeDepotPetFromCharIndex( int charaindex);
BOOL CHAR_makeDepotPetStringToChar( int charaindex, char* data);

BOOL CHAR_SaveDepotPet( int charaindex);
BOOL CHAR_GetDepotPet( int meindex, int charaindex);
void CHAR_ShowMyDepotPets( int charaindex);

int CHAR_findEmptyDepotPet( int charaindex);
int CHAR_getfindEmptyDepotPet( int charaindex);
BOOL CHAR_CheckDepotPet( int charaindex);
#endif

#ifdef _RIDE_CF
int CHAR_Ride_CF_init();
#endif

void LodBadPetString( char *data, char *err, int ti);

#ifdef _STREET_VENDOR
BOOL CHAR_setStreetVendor(int charindex,int index,int set,int num);
INLINE void CHAR_clearStreetVendor(int charindex,int index);
int CHAR_getStreetVendor(int charindex,int index,int set);
#endif

#ifdef _ANGEL_SUMMON

#define ANGELITEM 2884 //20701	//使者的信物 道具编号
#define HEROITEM 2885 //20702	//勇者的信物 道具编号

typedef enum
{
	ANGEL_NONE =0,
	ANGEL_ANGEL,
	ANGEL_HERO,
}ANGEL_TYPE;

typedef enum
{
	MISSION_NONE =0,
	MISSION_WAIT_ANSWER,
	MISSION_DOING,
	MISSION_HERO_COMPLETE,
	MISSION_TIMEOVER,
}ANGEL_MISSIONFLAG;
#endif

#endif
