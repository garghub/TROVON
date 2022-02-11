static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 , void * V_8 )
{
#define F_6 ( T_2 ) { r, #r }
static const struct {
int V_9 ;
const char * V_10 ;
} V_5 [] = {
F_6 ( V_11 ) ,
F_6 ( V_12 ) ,
F_6 ( V_13 ) ,
F_6 ( V_14 ) ,
F_6 ( V_15 ) ,
F_6 ( V_16 ) ,
F_6 ( V_17 ) ,
F_6 ( V_18 ) ,
F_6 ( V_19 ) ,
F_6 ( V_20 ) ,
F_6 ( V_21 ) ,
F_6 ( V_22 ) ,
F_6 ( V_23 ) ,
F_6 ( V_24 ) ,
F_6 ( V_25 ) ,
F_6 ( V_26 ) ,
} ;
#undef F_6
struct V_1 * V_2 = V_7 -> V_27 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_7 ( V_5 ) ; V_28 ++ ) {
T_1 V_4 = F_3 ( V_2 , V_5 [ V_28 ] . V_9 ) ;
F_8 ( V_7 , L_1 , V_5 [ V_28 ] . V_10 , V_4 ) ;
}
return 0 ;
}
static int F_9 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
return F_10 ( V_30 , F_5 , V_29 -> V_31 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_32 = F_12 ( V_33 , V_34 ,
V_35 , V_2 ,
& V_36 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 )
F_14 ( V_2 -> V_32 ) ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
}
static inline void F_13 ( struct V_1 * V_2 )
{
}
static int F_15 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 = V_38 -> V_45 -> V_46 -> V_44 ;
struct V_1 * V_2 = F_16 ( V_42 ) ;
int V_47 , V_48 ;
V_2 -> V_49 &= ~ V_50 ;
V_2 -> V_49 &= ~ V_51 ;
switch ( F_17 ( V_40 ) ) {
case V_52 :
V_2 -> V_49 |= V_50 ;
V_2 -> V_49 |= V_53 ;
break;
default:
return - V_54 ;
}
switch ( F_18 ( V_40 ) ) {
case 32000 :
V_48 = 4096000 ;
break;
case 44100 :
V_48 = 5644800 ;
break;
case 48000 :
V_48 = 6144000 ;
break;
case 88200 :
V_48 = 11289600 ;
break;
case 96000 :
V_48 = 12288000 ;
break;
case 176400 :
V_48 = 22579200 ;
break;
case 192000 :
V_48 = 24576000 ;
break;
default:
return - V_54 ;
}
V_47 = F_19 ( V_2 -> V_55 , V_48 ) ;
if ( V_47 ) {
F_20 ( V_44 , L_2 , V_47 ) ;
return V_47 ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_49 |= V_56 ;
F_1 ( V_2 , V_11 , V_2 -> V_49 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_49 &= ~ V_56 ;
F_1 ( V_2 , V_11 , V_2 -> V_49 ) ;
}
static int F_23 ( struct V_37 * V_38 , int V_57 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_16 ( V_42 ) ;
switch ( V_57 ) {
case V_58 :
case V_59 :
case V_60 :
if ( ! V_2 -> V_61 )
F_24 ( V_2 -> V_55 ) ;
V_2 -> V_61 ++ ;
F_21 ( V_2 ) ;
break;
case V_62 :
case V_63 :
case V_64 :
F_22 ( V_2 ) ;
V_2 -> V_61 -- ;
if ( ! V_2 -> V_61 )
F_25 ( V_2 -> V_55 ) ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static int F_26 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_16 ( V_42 ) ;
V_42 -> V_65 = NULL ;
V_42 -> V_66 = & V_2 -> V_66 ;
return 0 ;
}
static T_3 int F_27 ( struct V_67 * V_68 )
{
struct V_1 * V_2 ;
struct V_69 * V_70 , * V_71 , * V_72 ;
int V_47 ;
V_2 = F_28 ( sizeof( struct V_1 ) , V_73 ) ;
if ( ! V_2 ) {
F_20 ( & V_68 -> V_44 , L_3 ) ;
V_47 = - V_74 ;
goto exit;
}
F_29 ( & V_68 -> V_44 , V_2 ) ;
V_2 -> V_55 = F_30 ( & V_68 -> V_44 , L_4 ) ;
if ( F_31 ( V_2 -> V_55 ) ) {
F_32 ( L_5 ) ;
V_47 = F_33 ( V_2 -> V_55 ) ;
goto V_75;
}
V_70 = F_34 ( V_68 , V_76 , 0 ) ;
if ( ! V_70 ) {
F_20 ( & V_68 -> V_44 , L_6 ) ;
V_47 = - V_77 ;
goto V_78;
}
V_72 = F_34 ( V_68 , V_79 , 0 ) ;
if ( ! V_72 ) {
F_20 ( & V_68 -> V_44 , L_7 ) ;
V_47 = - V_77 ;
goto V_78;
}
V_71 = F_35 ( V_70 -> V_80 , F_36 ( V_70 ) ,
V_33 ) ;
if ( ! V_71 ) {
F_20 ( & V_68 -> V_44 , L_8 ) ;
V_47 = - V_81 ;
goto V_78;
}
V_2 -> V_5 = F_37 ( V_70 -> V_80 , F_36 ( V_70 ) ) ;
if ( ! V_2 -> V_5 ) {
F_20 ( & V_68 -> V_44 , L_9 ) ;
V_47 = - V_74 ;
goto V_82;
}
V_2 -> V_66 . V_83 = V_70 -> V_80 + V_84 ;
V_2 -> V_66 . V_85 = 4 ;
V_2 -> V_66 . V_86 = 32 ;
V_2 -> V_66 . V_87 = V_72 -> V_80 ;
V_47 = F_38 ( & V_68 -> V_44 , & V_88 ) ;
if ( V_47 ) {
F_20 ( & V_68 -> V_44 , L_10 , V_47 ) ;
V_47 = - V_74 ;
goto V_89;
}
F_11 ( V_2 ) ;
return 0 ;
V_89:
F_39 ( V_2 -> V_5 ) ;
V_82:
F_40 ( V_70 -> V_80 , F_36 ( V_70 ) ) ;
V_78:
F_41 ( V_2 -> V_55 ) ;
V_75:
F_42 ( V_2 ) ;
exit:
return V_47 ;
}
static int T_4 F_43 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_44 ( & V_68 -> V_44 ) ;
struct V_69 * V_90 ;
F_45 ( & V_68 -> V_44 ) ;
F_13 ( V_2 ) ;
F_39 ( V_2 -> V_5 ) ;
V_90 = F_34 ( V_68 , V_76 , 0 ) ;
F_40 ( V_90 -> V_80 , F_36 ( V_90 ) ) ;
F_41 ( V_2 -> V_55 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int T_5 F_46 ( void )
{
return F_47 ( & V_91 ) ;
}
static void T_6 F_48 ( void )
{
F_49 ( & V_91 ) ;
}
