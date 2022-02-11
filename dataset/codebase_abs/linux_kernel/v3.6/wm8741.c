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
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_18 = F_8 ( V_2 , V_19 ) & 0x1FC ;
int V_20 ;
for ( V_20 = 0 ; V_20 < F_9 ( V_21 ) ; V_20 ++ ) {
if ( V_9 -> V_10 / F_10 ( V_17 ) ==
V_21 [ V_20 ] . V_22 )
break;
}
if ( V_20 == F_9 ( V_21 ) ) {
F_5 ( V_2 -> V_11 , L_2 ,
V_9 -> V_10 / F_10 ( V_17 ) ) ;
return - V_12 ;
}
switch ( F_11 ( V_17 ) ) {
case V_23 :
break;
case V_24 :
V_18 |= 0x0001 ;
break;
case V_25 :
V_18 |= 0x0002 ;
break;
case V_26 :
V_18 |= 0x0003 ;
break;
default:
F_12 ( V_2 -> V_11 , L_3 ,
F_11 ( V_17 ) ) ;
return - V_12 ;
}
F_12 ( V_2 -> V_11 , L_4 ,
F_11 ( V_17 ) ) ;
F_2 ( V_2 , V_19 , V_18 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_27 ,
int V_28 , unsigned int V_29 , int V_30 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
F_12 ( V_2 -> V_11 , L_5 , V_29 ) ;
switch ( V_29 ) {
case 11289600 :
V_9 -> V_15 = & V_31 ;
V_9 -> V_10 = V_29 ;
return 0 ;
case 12288000 :
V_9 -> V_15 = & V_32 ;
V_9 -> V_10 = V_29 ;
return 0 ;
case 16384000 :
V_9 -> V_15 = & V_33 ;
V_9 -> V_10 = V_29 ;
return 0 ;
case 16934400 :
V_9 -> V_15 = & V_34 ;
V_9 -> V_10 = V_29 ;
return 0 ;
case 18432000 :
V_9 -> V_15 = & V_35 ;
V_9 -> V_10 = V_29 ;
return 0 ;
case 22579200 :
case 33868800 :
V_9 -> V_15 = & V_36 ;
V_9 -> V_10 = V_29 ;
return 0 ;
case 24576000 :
V_9 -> V_15 = & V_37 ;
V_9 -> V_10 = V_29 ;
return 0 ;
case 36864000 :
V_9 -> V_15 = & V_38 ;
V_9 -> V_10 = V_29 ;
return 0 ;
}
return - V_12 ;
}
static int F_14 ( struct V_6 * V_27 ,
unsigned int V_39 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
T_1 V_18 = F_8 ( V_2 , V_19 ) & 0x1C3 ;
switch ( V_39 & V_40 ) {
case V_41 :
break;
default:
return - V_12 ;
}
switch ( V_39 & V_42 ) {
case V_43 :
V_18 |= 0x0008 ;
break;
case V_44 :
break;
case V_45 :
V_18 |= 0x0004 ;
break;
case V_46 :
V_18 |= 0x000C ;
break;
case V_47 :
V_18 |= 0x001C ;
break;
default:
return - V_12 ;
}
switch ( V_39 & V_48 ) {
case V_49 :
break;
case V_50 :
V_18 |= 0x0010 ;
break;
case V_51 :
V_18 |= 0x0020 ;
break;
case V_52 :
V_18 |= 0x0030 ;
break;
default:
return - V_12 ;
}
F_12 ( V_2 -> V_11 , L_6 ,
V_39 & V_42 ,
( ( V_39 & V_48 ) ) ) ;
F_2 ( V_2 , V_19 , V_18 ) ;
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
int V_53 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < F_9 ( V_9 -> V_54 ) ; V_20 ++ )
V_9 -> V_54 [ V_20 ] . V_55 = V_56 [ V_20 ] ;
V_53 = F_18 ( V_2 -> V_11 , F_9 ( V_9 -> V_54 ) ,
V_9 -> V_54 ) ;
if ( V_53 != 0 ) {
F_5 ( V_2 -> V_11 , L_7 , V_53 ) ;
goto V_57;
}
V_53 = F_19 ( F_9 ( V_9 -> V_54 ) ,
V_9 -> V_54 ) ;
if ( V_53 != 0 ) {
F_5 ( V_2 -> V_11 , L_8 , V_53 ) ;
goto V_58;
}
V_53 = F_20 ( V_2 , 7 , 9 , V_9 -> V_59 ) ;
if ( V_53 != 0 ) {
F_5 ( V_2 -> V_11 , L_9 , V_53 ) ;
goto V_60;
}
V_53 = F_1 ( V_2 ) ;
if ( V_53 < 0 ) {
F_5 ( V_2 -> V_11 , L_10 ) ;
goto V_60;
}
F_21 ( V_2 , V_61 ,
V_62 , V_62 ) ;
F_21 ( V_2 , V_63 ,
V_64 , V_64 ) ;
F_21 ( V_2 , V_65 ,
V_66 , V_66 ) ;
F_21 ( V_2 , V_67 ,
V_68 , V_68 ) ;
F_12 ( V_2 -> V_11 , L_11 ) ;
return V_53 ;
V_60:
F_22 ( F_9 ( V_9 -> V_54 ) , V_9 -> V_54 ) ;
V_58:
F_23 ( F_9 ( V_9 -> V_54 ) , V_9 -> V_54 ) ;
V_57:
return V_53 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
F_22 ( F_9 ( V_9 -> V_54 ) , V_9 -> V_54 ) ;
F_23 ( F_9 ( V_9 -> V_54 ) , V_9 -> V_54 ) ;
return 0 ;
}
static int F_25 ( struct V_69 * V_70 ,
const struct V_71 * V_72 )
{
struct V_8 * V_9 ;
int V_53 ;
V_9 = F_26 ( & V_70 -> V_11 , sizeof( struct V_8 ) ,
V_73 ) ;
if ( V_9 == NULL )
return - V_74 ;
F_27 ( V_70 , V_9 ) ;
V_9 -> V_59 = V_75 ;
V_53 = F_28 ( & V_70 -> V_11 ,
& V_76 , & V_77 , 1 ) ;
return V_53 ;
}
static int F_29 ( struct V_69 * V_78 )
{
F_30 ( & V_78 -> V_11 ) ;
return 0 ;
}
static int T_2 F_31 ( struct V_79 * V_80 )
{
struct V_8 * V_9 ;
int V_53 ;
V_9 = F_26 ( & V_80 -> V_11 , sizeof( struct V_8 ) ,
V_73 ) ;
if ( V_9 == NULL )
return - V_74 ;
V_9 -> V_59 = V_81 ;
F_32 ( V_80 , V_9 ) ;
V_53 = F_28 ( & V_80 -> V_11 ,
& V_76 , & V_77 , 1 ) ;
return V_53 ;
}
static int T_3 F_33 ( struct V_79 * V_80 )
{
F_30 ( & V_80 -> V_11 ) ;
return 0 ;
}
static int T_4 F_34 ( void )
{
int V_53 = 0 ;
#if F_35 ( V_82 ) || F_35 ( V_83 )
V_53 = F_36 ( & V_84 ) ;
if ( V_53 != 0 )
F_37 ( L_12 , V_53 ) ;
#endif
#if F_35 ( V_85 )
V_53 = F_38 ( & V_86 ) ;
if ( V_53 != 0 ) {
F_39 ( V_87 L_13 ,
V_53 ) ;
}
#endif
return V_53 ;
}
static void T_5 F_40 ( void )
{
#if F_35 ( V_85 )
F_41 ( & V_86 ) ;
#endif
#if F_35 ( V_82 ) || F_35 ( V_83 )
F_42 ( & V_84 ) ;
#endif
}
