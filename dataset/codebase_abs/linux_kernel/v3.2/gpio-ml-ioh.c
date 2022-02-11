static void F_1 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
T_1 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
F_3 ( & V_7 -> V_8 ) ;
V_5 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_5 ( V_5 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
F_6 ( & V_7 -> V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
return F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_13 ) & ( 1 << V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_1 V_14 ;
T_1 V_5 ;
F_3 ( & V_7 -> V_8 ) ;
V_14 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) &
( ( 1 << V_15 [ V_7 -> V_11 ] ) - 1 ) ;
V_14 |= ( 1 << V_3 ) ;
F_5 ( V_14 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) ;
V_5 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_5 ( V_5 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
F_6 ( & V_7 -> V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_1 V_14 ;
F_3 ( & V_7 -> V_8 ) ;
V_14 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) &
( ( 1 << V_15 [ V_7 -> V_11 ] ) - 1 ) ;
V_14 &= ~ ( 1 << V_3 ) ;
F_5 ( V_14 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) ;
F_6 ( & V_7 -> V_8 ) ;
return 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ , V_7 ++ ) {
V_7 -> V_17 . V_18 =
F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
V_7 -> V_17 . V_19 =
F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) ;
V_7 -> V_17 . V_20 =
F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_21 ) ;
V_7 -> V_17 . V_22 =
F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_23 ) ;
V_7 -> V_17 . V_24 =
F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_25 ) ;
V_7 -> V_17 . V_26 =
F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_27 ) ;
if ( V_16 < 4 )
V_7 -> V_17 . V_28 =
F_4 ( & V_7 -> V_9 -> V_29 [ V_16 ] ) ;
}
}
static void F_11 ( struct V_6 * V_7 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ , V_7 ++ ) {
F_5 ( V_7 -> V_17 . V_18 ,
& V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
F_5 ( V_7 -> V_17 . V_19 ,
& V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) ;
F_5 ( V_7 -> V_17 . V_20 ,
& V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_21 ) ;
F_5 ( V_7 -> V_17 . V_22 ,
& V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_23 ) ;
F_5 ( V_7 -> V_17 . V_24 ,
& V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_25 ) ;
F_5 ( V_7 -> V_17 . V_26 ,
& V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_27 ) ;
if ( V_16 < 4 )
F_5 ( V_7 -> V_17 . V_28 ,
& V_7 -> V_9 -> V_29 [ V_16 ] ) ;
}
}
static int F_12 ( struct V_1 * V_2 , unsigned V_30 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
return V_7 -> V_31 + V_30 ;
}
static void F_13 ( struct V_6 * V_7 , int V_32 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
V_2 -> V_33 = F_14 ( V_7 -> V_34 ) ;
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = F_9 ;
V_2 -> V_38 = F_7 ;
V_2 -> V_39 = F_8 ;
V_2 -> V_40 = F_1 ;
V_2 -> V_41 = NULL ;
V_2 -> V_42 = - 1 ;
V_2 -> V_43 = V_32 ;
V_2 -> V_44 = 0 ;
V_2 -> V_45 = F_12 ;
}
static int F_15 ( struct V_46 * V_47 , unsigned int type )
{
T_1 V_48 ;
T_1 * V_49 ;
T_1 V_21 ;
T_1 V_50 ;
int V_11 ;
unsigned long V_51 ;
T_1 V_4 ;
int V_52 = V_47 -> V_52 ;
struct V_53 * V_54 = F_16 ( V_47 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
V_11 = V_52 - V_7 -> V_31 ;
if ( V_52 <= V_7 -> V_31 + 7 ) {
V_49 = & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_25 ;
V_50 = V_11 ;
} else {
V_49 = & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_27 ;
V_50 = V_11 - 8 ;
}
F_17 ( V_7 -> V_34 , L_1 ,
V_56 , V_52 , type , V_11 , V_50 , type ) ;
F_18 ( & V_7 -> V_57 , V_51 ) ;
switch ( type ) {
case V_58 :
V_4 = V_59 ;
break;
case V_60 :
V_4 = V_61 ;
break;
case V_62 :
V_4 = V_63 ;
break;
case V_64 :
V_4 = V_65 ;
break;
case V_66 :
V_4 = V_67 ;
break;
case V_68 :
goto V_69;
default:
F_19 ( V_7 -> V_34 , L_2 ,
V_56 , type ) ;
goto V_69;
}
V_48 = F_4 ( V_49 ) & ~ ( V_70 << ( V_50 * 4 ) ) ;
F_5 ( V_48 | ( V_4 << ( V_50 * 4 ) ) , V_49 ) ;
F_5 ( F_20 ( V_11 ) , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_71 ) ;
F_5 ( F_20 ( V_11 ) , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_72 ) ;
V_21 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_21 ) ;
F_5 ( V_21 | F_20 ( V_11 ) , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_21 ) ;
V_69:
F_21 ( & V_7 -> V_57 , V_51 ) ;
return 0 ;
}
static void F_22 ( struct V_46 * V_47 )
{
struct V_53 * V_54 = F_16 ( V_47 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
F_5 ( 1 << ( V_47 -> V_52 - V_7 -> V_31 ) ,
& V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_72 ) ;
}
static void F_23 ( struct V_46 * V_47 )
{
struct V_53 * V_54 = F_16 ( V_47 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
F_5 ( 1 << ( V_47 -> V_52 - V_7 -> V_31 ) ,
& V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_23 ) ;
}
static void F_24 ( struct V_46 * V_47 )
{
struct V_53 * V_54 = F_16 ( V_47 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
unsigned long V_51 ;
T_1 V_21 ;
F_18 ( & V_7 -> V_57 , V_51 ) ;
V_21 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_21 ) ;
V_21 &= ~ ( 1 << ( V_47 -> V_52 - V_7 -> V_31 ) ) ;
F_5 ( V_21 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_21 ) ;
F_21 ( & V_7 -> V_57 , V_51 ) ;
}
static void F_25 ( struct V_46 * V_47 )
{
struct V_53 * V_54 = F_16 ( V_47 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
unsigned long V_51 ;
T_1 V_21 ;
F_18 ( & V_7 -> V_57 , V_51 ) ;
V_21 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_21 ) ;
V_21 |= 1 << ( V_47 -> V_52 - V_7 -> V_31 ) ;
F_5 ( V_21 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_21 ) ;
F_21 ( & V_7 -> V_57 , V_51 ) ;
}
static T_2 F_26 ( int V_52 , void * V_73 )
{
struct V_6 * V_7 = V_73 ;
T_1 V_5 ;
int V_16 , V_74 ;
int V_75 = V_76 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ , V_7 ++ ) {
V_5 = F_4 ( & V_7 -> V_9 -> V_10 [ V_16 ] . V_77 ) ;
for ( V_74 = 0 ; V_74 < V_15 [ V_16 ] ; V_74 ++ ) {
if ( V_5 & F_20 ( V_74 ) ) {
F_17 ( V_7 -> V_34 ,
L_3 ,
V_56 , V_74 , V_52 , V_5 ) ;
F_5 ( F_20 ( V_74 ) ,
& V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_71 ) ;
F_27 ( V_7 -> V_31 + V_74 ) ;
V_75 = V_78 ;
}
}
}
return V_75 ;
}
static T_3 void F_28 ( struct V_6 * V_7 ,
unsigned int V_79 , unsigned int V_80 )
{
struct V_53 * V_54 ;
struct V_81 * V_82 ;
V_54 = F_29 ( L_4 , 1 , V_79 , V_7 -> V_42 ,
V_83 ) ;
V_54 -> V_55 = V_7 ;
V_82 = V_54 -> V_84 ;
V_82 -> V_7 . V_85 = F_23 ;
V_82 -> V_7 . V_86 = F_22 ;
V_82 -> V_7 . V_87 = F_15 ;
V_82 -> V_7 . V_88 = F_24 ;
V_82 -> V_7 . V_89 = F_25 ;
F_30 ( V_54 , F_31 ( V_80 ) , V_90 ,
V_91 | V_92 , 0 ) ;
}
static int T_3 F_32 ( struct V_93 * V_94 ,
const struct V_95 * V_96 )
{
int V_75 ;
int V_16 , V_74 ;
struct V_6 * V_7 ;
void T_4 * V_42 ;
void T_4 * V_97 ;
int V_31 ;
V_75 = F_33 ( V_94 ) ;
if ( V_75 ) {
F_34 ( & V_94 -> V_34 , L_5 , V_56 ) ;
goto V_98;
}
V_75 = F_35 ( V_94 , V_99 ) ;
if ( V_75 ) {
F_34 ( & V_94 -> V_34 , L_6 , V_75 ) ;
goto V_100;
}
V_42 = F_36 ( V_94 , 1 , 0 ) ;
if ( V_42 == 0 ) {
F_34 ( & V_94 -> V_34 , L_7 , V_56 ) ;
V_75 = - V_101 ;
goto V_102;
}
V_97 = F_37 ( sizeof( * V_7 ) * 8 , V_103 ) ;
if ( V_97 == NULL ) {
F_34 ( & V_94 -> V_34 , L_8 , V_56 ) ;
V_75 = - V_101 ;
goto V_104;
}
V_7 = V_97 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ , V_7 ++ ) {
V_7 -> V_34 = & V_94 -> V_34 ;
V_7 -> V_42 = V_42 ;
V_7 -> V_9 = V_7 -> V_42 ;
V_7 -> V_11 = V_16 ;
F_38 ( & V_7 -> V_8 ) ;
F_13 ( V_7 , V_15 [ V_16 ] ) ;
V_75 = F_39 ( & V_7 -> V_2 ) ;
if ( V_75 ) {
F_34 ( & V_94 -> V_34 , L_9 ) ;
goto V_105;
}
}
V_7 = V_97 ;
for ( V_74 = 0 ; V_74 < 8 ; V_74 ++ , V_7 ++ ) {
V_31 = F_40 ( - 1 , V_106 , V_15 [ V_74 ] ,
V_107 ) ;
if ( V_31 < 0 ) {
F_19 ( & V_94 -> V_34 ,
L_10 ) ;
V_7 -> V_31 = - 1 ;
goto V_108;
}
V_7 -> V_31 = V_31 ;
F_28 ( V_7 , V_31 , V_15 [ V_74 ] ) ;
}
V_7 = V_97 ;
V_75 = F_41 ( V_94 -> V_52 , F_26 ,
V_109 , V_99 , V_7 ) ;
if ( V_75 != 0 ) {
F_34 ( & V_94 -> V_34 ,
L_11 , V_56 ) ;
goto V_110;
}
F_42 ( V_94 , V_7 ) ;
return 0 ;
V_110:
V_7 = V_97 ;
V_108:
while ( -- V_74 >= 0 ) {
V_7 -- ;
F_43 ( V_7 -> V_31 , V_15 [ V_74 ] ) ;
}
V_7 = V_97 ;
V_105:
while ( -- V_16 >= 0 ) {
V_7 -- ;
V_75 = F_44 ( & V_7 -> V_2 ) ;
if ( V_75 )
F_34 ( & V_94 -> V_34 , L_12 , V_16 ) ;
}
F_45 ( V_97 ) ;
V_104:
F_46 ( V_94 , V_42 ) ;
V_102:
F_47 ( V_94 ) ;
V_100:
F_48 ( V_94 ) ;
V_98:
F_34 ( & V_94 -> V_34 , L_13 , V_56 , V_75 ) ;
return V_75 ;
}
static void T_5 F_49 ( struct V_93 * V_94 )
{
int V_111 ;
int V_16 ;
struct V_6 * V_7 = F_50 ( V_94 ) ;
void T_4 * V_97 ;
V_97 = V_7 ;
F_51 ( V_94 -> V_52 , V_7 ) ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ , V_7 ++ ) {
F_43 ( V_7 -> V_31 , V_15 [ V_16 ] ) ;
V_111 = F_44 ( & V_7 -> V_2 ) ;
if ( V_111 )
F_34 ( & V_94 -> V_34 , L_14 ) ;
}
V_7 = V_97 ;
F_46 ( V_94 , V_7 -> V_42 ) ;
F_47 ( V_94 ) ;
F_48 ( V_94 ) ;
F_45 ( V_7 ) ;
}
static int F_52 ( struct V_93 * V_94 , T_6 V_112 )
{
T_7 V_75 ;
struct V_6 * V_7 = F_50 ( V_94 ) ;
unsigned long V_51 ;
F_18 ( & V_7 -> V_57 , V_51 ) ;
F_10 ( V_7 ) ;
F_21 ( & V_7 -> V_57 , V_51 ) ;
V_75 = F_53 ( V_94 ) ;
if ( V_75 ) {
F_34 ( & V_94 -> V_34 , L_15 , V_75 ) ;
return V_75 ;
}
F_48 ( V_94 ) ;
F_54 ( V_94 , V_113 ) ;
V_75 = F_55 ( V_94 , V_113 , 1 ) ;
if ( V_75 )
F_34 ( & V_94 -> V_34 , L_16 , V_75 ) ;
return 0 ;
}
static int F_56 ( struct V_93 * V_94 )
{
T_7 V_75 ;
struct V_6 * V_7 = F_50 ( V_94 ) ;
unsigned long V_51 ;
V_75 = F_55 ( V_94 , V_113 , 0 ) ;
F_54 ( V_94 , V_113 ) ;
V_75 = F_33 ( V_94 ) ;
if ( V_75 ) {
F_34 ( & V_94 -> V_34 , L_17 , V_75 ) ;
return V_75 ;
}
F_57 ( V_94 ) ;
F_18 ( & V_7 -> V_57 , V_51 ) ;
F_5 ( 0x01 , & V_7 -> V_9 -> V_114 ) ;
F_5 ( 0x00 , & V_7 -> V_9 -> V_114 ) ;
F_11 ( V_7 ) ;
F_21 ( & V_7 -> V_57 , V_51 ) ;
return 0 ;
}
static int T_8 F_58 ( void )
{
return F_59 ( & V_115 ) ;
}
static void T_9 F_60 ( void )
{
F_61 ( & V_115 ) ;
}
