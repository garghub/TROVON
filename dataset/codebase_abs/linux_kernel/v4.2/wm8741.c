static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_14 * V_15 )
{
return F_3 ( V_15 , V_16 , 0 ) ;
}
static int F_4 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_14 * V_15 = V_20 -> V_15 ;
struct V_21 * V_22 = F_5 ( V_15 ) ;
if ( V_22 -> V_23 )
F_6 ( V_18 -> V_24 , 0 ,
V_25 ,
V_22 -> V_26 ) ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 ,
struct V_27 * V_28 ,
struct V_19 * V_20 )
{
struct V_14 * V_15 = V_20 -> V_15 ;
struct V_21 * V_22 = F_5 ( V_15 ) ;
T_1 V_29 = F_8 ( V_15 , V_9 ) & 0x1FC ;
int V_30 ;
if ( ! V_22 -> V_23 ) {
F_9 ( V_15 -> V_2 ,
L_1 ) ;
return - V_31 ;
}
for ( V_30 = 0 ; V_30 < V_22 -> V_26 -> V_32 ; V_30 ++ ) {
if ( V_22 -> V_26 -> V_33 [ V_30 ] == F_10 ( V_28 ) )
break;
}
if ( V_30 == V_22 -> V_26 -> V_32 ) {
F_9 ( V_15 -> V_2 , L_2 ,
F_10 ( V_28 ) , V_22 -> V_23 ) ;
return - V_31 ;
}
switch ( F_11 ( V_28 ) ) {
case 16 :
break;
case 20 :
V_29 |= 0x0001 ;
break;
case 24 :
V_29 |= 0x0002 ;
break;
case 32 :
V_29 |= 0x0003 ;
break;
default:
F_12 ( V_15 -> V_2 , L_3 ,
F_11 ( V_28 ) ) ;
return - V_31 ;
}
F_12 ( V_15 -> V_2 , L_4 ,
F_11 ( V_28 ) , F_10 ( V_28 ) ) ;
F_3 ( V_15 , V_9 , V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_19 * V_34 ,
int V_35 , unsigned int V_36 , int V_37 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
struct V_21 * V_22 = F_5 ( V_15 ) ;
F_12 ( V_15 -> V_2 , L_5 , V_36 ) ;
switch ( V_36 ) {
case 0 :
V_22 -> V_26 = NULL ;
V_22 -> V_23 = V_36 ;
return 0 ;
case 11289600 :
V_22 -> V_26 = & V_38 ;
V_22 -> V_23 = V_36 ;
return 0 ;
case 12288000 :
V_22 -> V_26 = & V_39 ;
V_22 -> V_23 = V_36 ;
return 0 ;
case 16384000 :
V_22 -> V_26 = & V_40 ;
V_22 -> V_23 = V_36 ;
return 0 ;
case 16934400 :
V_22 -> V_26 = & V_41 ;
V_22 -> V_23 = V_36 ;
return 0 ;
case 18432000 :
V_22 -> V_26 = & V_42 ;
V_22 -> V_23 = V_36 ;
return 0 ;
case 22579200 :
case 33868800 :
V_22 -> V_26 = & V_43 ;
V_22 -> V_23 = V_36 ;
return 0 ;
case 24576000 :
V_22 -> V_26 = & V_44 ;
V_22 -> V_23 = V_36 ;
return 0 ;
case 36864000 :
V_22 -> V_26 = & V_45 ;
V_22 -> V_23 = V_36 ;
return 0 ;
}
return - V_31 ;
}
static int F_14 ( struct V_19 * V_34 ,
unsigned int V_46 )
{
struct V_14 * V_15 = V_34 -> V_15 ;
T_1 V_29 = F_8 ( V_15 , V_9 ) & 0x1C3 ;
switch ( V_46 & V_47 ) {
case V_48 :
break;
default:
return - V_31 ;
}
switch ( V_46 & V_49 ) {
case V_50 :
V_29 |= 0x0008 ;
break;
case V_51 :
break;
case V_52 :
V_29 |= 0x0004 ;
break;
case V_53 :
V_29 |= 0x000C ;
break;
case V_54 :
V_29 |= 0x001C ;
break;
default:
return - V_31 ;
}
switch ( V_46 & V_55 ) {
case V_56 :
break;
case V_57 :
V_29 |= 0x0010 ;
break;
case V_58 :
V_29 |= 0x0020 ;
break;
case V_59 :
V_29 |= 0x0030 ;
break;
default:
return - V_31 ;
}
F_12 ( V_15 -> V_2 , L_6 ,
V_46 & V_49 ,
( ( V_46 & V_55 ) ) ) ;
F_3 ( V_15 , V_9 , V_29 ) ;
return 0 ;
}
static int F_15 ( struct V_14 * V_15 )
{
F_16 ( V_15 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 )
{
struct V_21 * V_22 = F_5 ( V_15 ) ;
switch ( V_22 -> V_60 . V_61 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
F_18 ( V_15 , V_12 ,
V_66 ,
V_22 -> V_60 . V_61 << V_67 ) ;
break;
default:
return - V_31 ;
}
F_18 ( V_15 , V_4 ,
V_68 , V_68 ) ;
F_18 ( V_15 , V_5 ,
V_69 , V_69 ) ;
F_18 ( V_15 , V_6 ,
V_70 , V_70 ) ;
F_18 ( V_15 , V_7 ,
V_71 , V_71 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_21 * V_22 = F_5 ( V_15 ) ;
switch ( V_22 -> V_60 . V_61 ) {
case V_62 :
case V_63 :
F_20 ( V_15 ,
V_72 ,
F_21 ( V_72 ) ) ;
break;
case V_64 :
F_20 ( V_15 ,
V_73 ,
F_21 ( V_73 ) ) ;
break;
case V_65 :
F_20 ( V_15 ,
V_74 ,
F_21 ( V_74 ) ) ;
break;
default:
return - V_31 ;
}
return 0 ;
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_21 * V_22 = F_5 ( V_15 ) ;
int V_75 = 0 ;
V_75 = F_23 ( F_21 ( V_22 -> V_76 ) ,
V_22 -> V_76 ) ;
if ( V_75 != 0 ) {
F_9 ( V_15 -> V_2 , L_7 , V_75 ) ;
goto V_77;
}
V_75 = F_2 ( V_15 ) ;
if ( V_75 < 0 ) {
F_9 ( V_15 -> V_2 , L_8 ) ;
goto V_78;
}
V_75 = F_17 ( V_15 ) ;
if ( V_75 < 0 ) {
F_9 ( V_15 -> V_2 , L_9 ) ;
goto V_78;
}
V_75 = F_19 ( V_15 ) ;
if ( V_75 < 0 ) {
F_9 ( V_15 -> V_2 , L_10 ) ;
goto V_78;
}
F_12 ( V_15 -> V_2 , L_11 ) ;
return V_75 ;
V_78:
F_24 ( F_21 ( V_22 -> V_76 ) , V_22 -> V_76 ) ;
V_77:
return V_75 ;
}
static int F_25 ( struct V_14 * V_15 )
{
struct V_21 * V_22 = F_5 ( V_15 ) ;
F_24 ( F_21 ( V_22 -> V_76 ) , V_22 -> V_76 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
const struct V_79 * V_60 = F_27 ( V_2 ) ;
T_2 V_61 ;
if ( V_2 -> V_80 ) {
if ( F_28 ( V_2 -> V_80 , L_12 , & V_61 )
>= 0 )
V_22 -> V_60 . V_61 = V_61 ;
} else {
if ( V_60 != NULL )
memcpy ( & V_22 -> V_60 , V_60 , sizeof( V_22 -> V_60 ) ) ;
}
return 0 ;
}
static int F_29 ( struct V_81 * V_82 ,
const struct V_83 * V_84 )
{
struct V_21 * V_22 ;
int V_75 , V_30 ;
V_22 = F_30 ( & V_82 -> V_2 , sizeof( struct V_21 ) ,
V_85 ) ;
if ( V_22 == NULL )
return - V_86 ;
for ( V_30 = 0 ; V_30 < F_21 ( V_22 -> V_76 ) ; V_30 ++ )
V_22 -> V_76 [ V_30 ] . V_87 = V_88 [ V_30 ] ;
V_75 = F_31 ( & V_82 -> V_2 , F_21 ( V_22 -> V_76 ) ,
V_22 -> V_76 ) ;
if ( V_75 != 0 ) {
F_9 ( & V_82 -> V_2 , L_13 , V_75 ) ;
return V_75 ;
}
V_22 -> V_89 = F_32 ( V_82 , & V_90 ) ;
if ( F_33 ( V_22 -> V_89 ) ) {
V_75 = F_34 ( V_22 -> V_89 ) ;
F_9 ( & V_82 -> V_2 , L_14 , V_75 ) ;
return V_75 ;
}
V_75 = F_26 ( & V_82 -> V_2 , V_22 ) ;
if ( V_75 != 0 ) {
F_9 ( & V_82 -> V_2 , L_15 , V_75 ) ;
return V_75 ;
}
F_35 ( V_82 , V_22 ) ;
V_75 = F_36 ( & V_82 -> V_2 ,
& V_91 , & V_92 , 1 ) ;
return V_75 ;
}
static int F_37 ( struct V_81 * V_93 )
{
F_38 ( & V_93 -> V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_94 * V_95 )
{
struct V_21 * V_22 ;
int V_75 , V_30 ;
V_22 = F_30 ( & V_95 -> V_2 , sizeof( struct V_21 ) ,
V_85 ) ;
if ( V_22 == NULL )
return - V_86 ;
for ( V_30 = 0 ; V_30 < F_21 ( V_22 -> V_76 ) ; V_30 ++ )
V_22 -> V_76 [ V_30 ] . V_87 = V_88 [ V_30 ] ;
V_75 = F_31 ( & V_95 -> V_2 , F_21 ( V_22 -> V_76 ) ,
V_22 -> V_76 ) ;
if ( V_75 != 0 ) {
F_9 ( & V_95 -> V_2 , L_13 , V_75 ) ;
return V_75 ;
}
V_22 -> V_89 = F_40 ( V_95 , & V_90 ) ;
if ( F_33 ( V_22 -> V_89 ) ) {
V_75 = F_34 ( V_22 -> V_89 ) ;
F_9 ( & V_95 -> V_2 , L_14 , V_75 ) ;
return V_75 ;
}
V_75 = F_26 ( & V_95 -> V_2 , V_22 ) ;
if ( V_75 != 0 ) {
F_9 ( & V_95 -> V_2 , L_15 , V_75 ) ;
return V_75 ;
}
F_41 ( V_95 , V_22 ) ;
V_75 = F_36 ( & V_95 -> V_2 ,
& V_91 , & V_92 , 1 ) ;
return V_75 ;
}
static int F_42 ( struct V_94 * V_95 )
{
F_38 ( & V_95 -> V_2 ) ;
return 0 ;
}
static int T_3 F_43 ( void )
{
int V_75 = 0 ;
#if F_44 ( V_96 )
V_75 = F_45 ( & V_97 ) ;
if ( V_75 != 0 )
F_46 ( L_16 , V_75 ) ;
#endif
#if F_47 ( V_98 )
V_75 = F_48 ( & V_99 ) ;
if ( V_75 != 0 ) {
F_49 ( V_100 L_17 ,
V_75 ) ;
}
#endif
return V_75 ;
}
static void T_4 F_50 ( void )
{
#if F_47 ( V_98 )
F_51 ( & V_99 ) ;
#endif
#if F_44 ( V_96 )
F_52 ( & V_97 ) ;
#endif
}
