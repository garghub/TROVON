static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static int F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
if ( ! V_9 -> V_10 ) {
F_5 ( V_2 -> V_11 ,
L_1 ) ;
return - V_12 ;
}
F_6 ( V_5 -> V_13 , 0 ,
V_14 ,
V_9 -> V_15 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 ,
struct V_16 * V_17 ,
struct V_6 * V_7 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_21 = F_8 ( V_2 , V_22 ) & 0x1FC ;
int V_23 ;
for ( V_23 = 0 ; V_23 < F_9 ( V_24 ) ; V_23 ++ ) {
if ( V_9 -> V_10 / F_10 ( V_17 ) ==
V_24 [ V_23 ] . V_25 )
break;
}
if ( V_23 == F_9 ( V_24 ) ) {
F_5 ( V_2 -> V_11 , L_2 ,
V_9 -> V_10 / F_10 ( V_17 ) ) ;
return - V_12 ;
}
switch ( F_11 ( V_17 ) ) {
case V_26 :
break;
case V_27 :
V_21 |= 0x0001 ;
break;
case V_28 :
V_21 |= 0x0002 ;
break;
case V_29 :
V_21 |= 0x0003 ;
break;
default:
F_12 ( V_2 -> V_11 , L_3 ,
F_11 ( V_17 ) ) ;
return - V_12 ;
}
F_12 ( V_2 -> V_11 , L_4 ,
F_11 ( V_17 ) ) ;
F_2 ( V_2 , V_22 , V_21 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_30 ,
int V_31 , unsigned int V_32 , int V_33 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
F_12 ( V_2 -> V_11 , L_5 , V_32 ) ;
switch ( V_32 ) {
case 11289600 :
V_9 -> V_15 = & V_34 ;
V_9 -> V_10 = V_32 ;
return 0 ;
case 12288000 :
V_9 -> V_15 = & V_35 ;
V_9 -> V_10 = V_32 ;
return 0 ;
case 16384000 :
V_9 -> V_15 = & V_36 ;
V_9 -> V_10 = V_32 ;
return 0 ;
case 16934400 :
V_9 -> V_15 = & V_37 ;
V_9 -> V_10 = V_32 ;
return 0 ;
case 18432000 :
V_9 -> V_15 = & V_38 ;
V_9 -> V_10 = V_32 ;
return 0 ;
case 22579200 :
case 33868800 :
V_9 -> V_15 = & V_39 ;
V_9 -> V_10 = V_32 ;
return 0 ;
case 24576000 :
V_9 -> V_15 = & V_40 ;
V_9 -> V_10 = V_32 ;
return 0 ;
case 36864000 :
V_9 -> V_15 = & V_41 ;
V_9 -> V_10 = V_32 ;
return 0 ;
}
return - V_12 ;
}
static int F_14 ( struct V_6 * V_30 ,
unsigned int V_42 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_21 = F_8 ( V_2 , V_22 ) & 0x1C3 ;
switch ( V_42 & V_43 ) {
case V_44 :
break;
default:
return - V_12 ;
}
switch ( V_42 & V_45 ) {
case V_46 :
V_21 |= 0x0008 ;
break;
case V_47 :
break;
case V_48 :
V_21 |= 0x0004 ;
break;
case V_49 :
V_21 |= 0x000C ;
break;
case V_50 :
V_21 |= 0x001C ;
break;
default:
return - V_12 ;
}
switch ( V_42 & V_51 ) {
case V_52 :
break;
case V_53 :
V_21 |= 0x0010 ;
break;
case V_54 :
V_21 |= 0x0020 ;
break;
case V_55 :
V_21 |= 0x0030 ;
break;
default:
return - V_12 ;
}
F_12 ( V_2 -> V_11 , L_6 ,
V_42 & V_45 ,
( ( V_42 & V_51 ) ) ) ;
F_2 ( V_2 , V_22 , V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_56 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < F_9 ( V_9 -> V_57 ) ; V_23 ++ )
V_9 -> V_57 [ V_23 ] . V_58 = V_59 [ V_23 ] ;
V_56 = F_18 ( V_2 -> V_11 , F_9 ( V_9 -> V_57 ) ,
V_9 -> V_57 ) ;
if ( V_56 != 0 ) {
F_5 ( V_2 -> V_11 , L_7 , V_56 ) ;
goto V_60;
}
V_56 = F_19 ( F_9 ( V_9 -> V_57 ) ,
V_9 -> V_57 ) ;
if ( V_56 != 0 ) {
F_5 ( V_2 -> V_11 , L_8 , V_56 ) ;
goto V_61;
}
V_56 = F_20 ( V_2 , 7 , 9 , V_9 -> V_62 ) ;
if ( V_56 != 0 ) {
F_5 ( V_2 -> V_11 , L_9 , V_56 ) ;
goto V_63;
}
V_56 = F_1 ( V_2 ) ;
if ( V_56 < 0 ) {
F_5 ( V_2 -> V_11 , L_10 ) ;
goto V_63;
}
F_21 ( V_2 , V_64 ,
V_65 , V_65 ) ;
F_21 ( V_2 , V_66 ,
V_67 , V_67 ) ;
F_21 ( V_2 , V_68 ,
V_69 , V_69 ) ;
F_21 ( V_2 , V_70 ,
V_71 , V_71 ) ;
F_12 ( V_2 -> V_11 , L_11 ) ;
return V_56 ;
V_63:
F_22 ( F_9 ( V_9 -> V_57 ) , V_9 -> V_57 ) ;
V_61:
F_23 ( F_9 ( V_9 -> V_57 ) , V_9 -> V_57 ) ;
V_60:
return V_56 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
F_22 ( F_9 ( V_9 -> V_57 ) , V_9 -> V_57 ) ;
F_23 ( F_9 ( V_9 -> V_57 ) , V_9 -> V_57 ) ;
return 0 ;
}
static int F_25 ( struct V_72 * V_73 ,
const struct V_74 * V_75 )
{
struct V_8 * V_9 ;
int V_56 ;
V_9 = F_26 ( & V_73 -> V_11 , sizeof( struct V_8 ) ,
V_76 ) ;
if ( V_9 == NULL )
return - V_77 ;
F_27 ( V_73 , V_9 ) ;
V_9 -> V_62 = V_78 ;
V_56 = F_28 ( & V_73 -> V_11 ,
& V_79 , & V_80 , 1 ) ;
return V_56 ;
}
static int F_29 ( struct V_72 * V_81 )
{
F_30 ( & V_81 -> V_11 ) ;
return 0 ;
}
static int T_2 F_31 ( struct V_82 * V_83 )
{
struct V_8 * V_9 ;
int V_56 ;
V_9 = F_26 ( & V_83 -> V_11 , sizeof( struct V_8 ) ,
V_76 ) ;
if ( V_9 == NULL )
return - V_77 ;
V_9 -> V_62 = V_84 ;
F_32 ( V_83 , V_9 ) ;
V_56 = F_28 ( & V_83 -> V_11 ,
& V_79 , & V_80 , 1 ) ;
return V_56 ;
}
static int T_3 F_33 ( struct V_82 * V_83 )
{
F_30 ( & V_83 -> V_11 ) ;
return 0 ;
}
static int T_4 F_34 ( void )
{
int V_56 = 0 ;
#if F_35 ( V_85 ) || F_35 ( V_86 )
V_56 = F_36 ( & V_87 ) ;
if ( V_56 != 0 )
F_37 ( L_12 , V_56 ) ;
#endif
#if F_35 ( V_88 )
V_56 = F_38 ( & V_89 ) ;
if ( V_56 != 0 ) {
F_39 ( V_90 L_13 ,
V_56 ) ;
}
#endif
return V_56 ;
}
static void T_5 F_40 ( void )
{
#if F_35 ( V_88 )
F_41 ( & V_89 ) ;
#endif
#if F_35 ( V_85 ) || F_35 ( V_86 )
F_42 ( & V_87 ) ;
#endif
}
