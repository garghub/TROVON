static void F_1 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
T_1 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_8 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_5 = F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_13 ) ;
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_5 ( V_5 , & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_13 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return ! ! ( F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_14 ) & ( 1 << V_3 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_15 ;
T_1 V_5 ;
unsigned long V_8 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_15 = F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_15 ) &
( ( 1 << V_16 [ V_7 -> V_12 ] ) - 1 ) ;
V_15 |= ( 1 << V_3 ) ;
F_5 ( V_15 , & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_15 ) ;
V_5 = F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_13 ) ;
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_5 ( V_5 , & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_13 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_15 ;
unsigned long V_8 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_15 = F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_15 ) &
( ( 1 << V_16 [ V_7 -> V_12 ] ) - 1 ) ;
V_15 &= ~ ( 1 << V_3 ) ;
F_5 ( V_15 , & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_15 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ , V_7 ++ ) {
V_7 -> V_18 . V_19 =
F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_13 ) ;
V_7 -> V_18 . V_20 =
F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_15 ) ;
V_7 -> V_18 . V_21 =
F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_22 ) ;
V_7 -> V_18 . V_23 =
F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_24 ) ;
V_7 -> V_18 . V_25 =
F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_26 ) ;
V_7 -> V_18 . V_27 =
F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_28 ) ;
if ( V_17 < 4 )
V_7 -> V_18 . V_29 =
F_4 ( & V_7 -> V_10 -> V_30 [ V_17 ] ) ;
}
}
static void F_11 ( struct V_6 * V_7 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ , V_7 ++ ) {
F_5 ( V_7 -> V_18 . V_19 ,
& V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_13 ) ;
F_5 ( V_7 -> V_18 . V_20 ,
& V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_15 ) ;
F_5 ( V_7 -> V_18 . V_21 ,
& V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_22 ) ;
F_5 ( V_7 -> V_18 . V_23 ,
& V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_24 ) ;
F_5 ( V_7 -> V_18 . V_25 ,
& V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_26 ) ;
F_5 ( V_7 -> V_18 . V_27 ,
& V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_28 ) ;
if ( V_17 < 4 )
F_5 ( V_7 -> V_18 . V_29 ,
& V_7 -> V_10 -> V_30 [ V_17 ] ) ;
}
}
static int F_12 ( struct V_1 * V_2 , unsigned V_31 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_32 + V_31 ;
}
static void F_13 ( struct V_6 * V_7 , int V_33 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
V_2 -> V_34 = F_14 ( V_7 -> V_35 ) ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = F_9 ;
V_2 -> V_39 = F_7 ;
V_2 -> V_40 = F_8 ;
V_2 -> V_41 = F_1 ;
V_2 -> V_42 = NULL ;
V_2 -> V_43 = - 1 ;
V_2 -> V_44 = V_33 ;
V_2 -> V_45 = false ;
V_2 -> V_46 = F_12 ;
}
static int F_15 ( struct V_47 * V_48 , unsigned int type )
{
T_1 V_49 ;
void T_2 * V_50 ;
T_1 V_22 ;
T_1 V_51 ;
int V_12 ;
unsigned long V_8 ;
T_1 V_4 ;
int V_52 = V_48 -> V_52 ;
struct V_53 * V_54 = F_16 ( V_48 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
V_12 = V_52 - V_7 -> V_32 ;
if ( V_52 <= V_7 -> V_32 + 7 ) {
V_50 = & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_26 ;
V_51 = V_12 ;
} else {
V_50 = & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_28 ;
V_51 = V_12 - 8 ;
}
F_17 ( V_7 -> V_35 , L_1 ,
V_56 , V_52 , type , V_12 , V_51 , type ) ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
switch ( type ) {
case V_57 :
V_4 = V_58 ;
break;
case V_59 :
V_4 = V_60 ;
break;
case V_61 :
V_4 = V_62 ;
break;
case V_63 :
V_4 = V_64 ;
break;
case V_65 :
V_4 = V_66 ;
break;
case V_67 :
goto V_68;
default:
F_18 ( V_7 -> V_35 , L_2 ,
V_56 , type ) ;
goto V_68;
}
V_49 = F_4 ( V_50 ) & ~ ( V_69 << ( V_51 * 4 ) ) ;
F_5 ( V_49 | ( V_4 << ( V_51 * 4 ) ) , V_50 ) ;
F_5 ( F_19 ( V_12 ) , & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_70 ) ;
F_5 ( F_19 ( V_12 ) , & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_71 ) ;
V_22 = F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_22 ) ;
F_5 ( V_22 | F_19 ( V_12 ) , & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_22 ) ;
V_68:
F_6 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_20 ( struct V_47 * V_48 )
{
struct V_53 * V_54 = F_16 ( V_48 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
F_5 ( 1 << ( V_48 -> V_52 - V_7 -> V_32 ) ,
& V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_71 ) ;
}
static void F_21 ( struct V_47 * V_48 )
{
struct V_53 * V_54 = F_16 ( V_48 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
F_5 ( 1 << ( V_48 -> V_52 - V_7 -> V_32 ) ,
& V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_24 ) ;
}
static void F_22 ( struct V_47 * V_48 )
{
struct V_53 * V_54 = F_16 ( V_48 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
unsigned long V_8 ;
T_1 V_22 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_22 = F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_22 ) ;
V_22 &= ~ ( 1 << ( V_48 -> V_52 - V_7 -> V_32 ) ) ;
F_5 ( V_22 , & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_22 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static void F_23 ( struct V_47 * V_48 )
{
struct V_53 * V_54 = F_16 ( V_48 ) ;
struct V_6 * V_7 = V_54 -> V_55 ;
unsigned long V_8 ;
T_1 V_22 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
V_22 = F_4 ( & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_22 ) ;
V_22 |= 1 << ( V_48 -> V_52 - V_7 -> V_32 ) ;
F_5 ( V_22 , & V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_22 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
}
static T_3 F_24 ( int V_52 , void * V_72 )
{
struct V_6 * V_7 = V_72 ;
T_1 V_5 ;
int V_17 , V_73 ;
int V_74 = V_75 ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ , V_7 ++ ) {
V_5 = F_4 ( & V_7 -> V_10 -> V_11 [ V_17 ] . V_76 ) ;
for ( V_73 = 0 ; V_73 < V_16 [ V_17 ] ; V_73 ++ ) {
if ( V_5 & F_19 ( V_73 ) ) {
F_17 ( V_7 -> V_35 ,
L_3 ,
V_56 , V_73 , V_52 , V_5 ) ;
F_5 ( F_19 ( V_73 ) ,
& V_7 -> V_10 -> V_11 [ V_7 -> V_12 ] . V_70 ) ;
F_25 ( V_7 -> V_32 + V_73 ) ;
V_74 = V_77 ;
}
}
}
return V_74 ;
}
static void F_26 ( struct V_6 * V_7 ,
unsigned int V_78 , unsigned int V_79 )
{
struct V_53 * V_54 ;
struct V_80 * V_81 ;
V_54 = F_27 ( L_4 , 1 , V_78 , V_7 -> V_43 ,
V_82 ) ;
V_54 -> V_55 = V_7 ;
V_81 = V_54 -> V_83 ;
V_81 -> V_7 . V_84 = F_21 ;
V_81 -> V_7 . V_85 = F_20 ;
V_81 -> V_7 . V_86 = F_15 ;
V_81 -> V_7 . V_87 = F_22 ;
V_81 -> V_7 . V_88 = F_23 ;
F_28 ( V_54 , F_29 ( V_79 ) , V_89 ,
V_90 | V_91 , 0 ) ;
}
static int F_30 ( struct V_92 * V_93 ,
const struct V_94 * V_95 )
{
int V_74 ;
int V_17 , V_73 ;
struct V_6 * V_7 ;
void T_2 * V_43 ;
void * V_96 ;
int V_32 ;
V_74 = F_31 ( V_93 ) ;
if ( V_74 ) {
F_32 ( & V_93 -> V_35 , L_5 , V_56 ) ;
goto V_97;
}
V_74 = F_33 ( V_93 , V_98 ) ;
if ( V_74 ) {
F_32 ( & V_93 -> V_35 , L_6 , V_74 ) ;
goto V_99;
}
V_43 = F_34 ( V_93 , 1 , 0 ) ;
if ( ! V_43 ) {
F_32 ( & V_93 -> V_35 , L_7 , V_56 ) ;
V_74 = - V_100 ;
goto V_101;
}
V_96 = F_35 ( sizeof( * V_7 ) * 8 , V_102 ) ;
if ( V_96 == NULL ) {
F_32 ( & V_93 -> V_35 , L_8 , V_56 ) ;
V_74 = - V_100 ;
goto V_103;
}
V_7 = V_96 ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ , V_7 ++ ) {
V_7 -> V_35 = & V_93 -> V_35 ;
V_7 -> V_43 = V_43 ;
V_7 -> V_10 = V_7 -> V_43 ;
V_7 -> V_12 = V_17 ;
F_36 ( & V_7 -> V_9 ) ;
F_13 ( V_7 , V_16 [ V_17 ] ) ;
V_74 = F_37 ( & V_7 -> V_2 , V_7 ) ;
if ( V_74 ) {
F_32 ( & V_93 -> V_35 , L_9 ) ;
goto V_104;
}
}
V_7 = V_96 ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ , V_7 ++ ) {
V_32 = F_38 ( & V_93 -> V_35 , - 1 , V_105 ,
V_16 [ V_73 ] , V_106 ) ;
if ( V_32 < 0 ) {
F_18 ( & V_93 -> V_35 ,
L_10 ) ;
V_74 = V_32 ;
goto V_104;
}
V_7 -> V_32 = V_32 ;
F_26 ( V_7 , V_32 , V_16 [ V_73 ] ) ;
}
V_7 = V_96 ;
V_74 = F_39 ( & V_93 -> V_35 , V_93 -> V_52 , F_24 ,
V_107 , V_98 , V_7 ) ;
if ( V_74 != 0 ) {
F_32 ( & V_93 -> V_35 ,
L_11 , V_56 ) ;
goto V_104;
}
F_40 ( V_93 , V_7 ) ;
return 0 ;
V_104:
while ( -- V_17 >= 0 ) {
V_7 -- ;
F_41 ( & V_7 -> V_2 ) ;
}
F_42 ( V_96 ) ;
V_103:
F_43 ( V_93 , V_43 ) ;
V_101:
F_44 ( V_93 ) ;
V_99:
F_45 ( V_93 ) ;
V_97:
F_32 ( & V_93 -> V_35 , L_12 , V_56 , V_74 ) ;
return V_74 ;
}
static void F_46 ( struct V_92 * V_93 )
{
int V_17 ;
struct V_6 * V_7 = F_47 ( V_93 ) ;
void * V_96 ;
V_96 = V_7 ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ , V_7 ++ )
F_41 ( & V_7 -> V_2 ) ;
V_7 = V_96 ;
F_43 ( V_93 , V_7 -> V_43 ) ;
F_44 ( V_93 ) ;
F_45 ( V_93 ) ;
F_42 ( V_7 ) ;
}
static int F_48 ( struct V_92 * V_93 , T_4 V_108 )
{
T_5 V_74 ;
struct V_6 * V_7 = F_47 ( V_93 ) ;
unsigned long V_8 ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_10 ( V_7 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
V_74 = F_49 ( V_93 ) ;
if ( V_74 ) {
F_32 ( & V_93 -> V_35 , L_13 , V_74 ) ;
return V_74 ;
}
F_45 ( V_93 ) ;
F_50 ( V_93 , V_109 ) ;
V_74 = F_51 ( V_93 , V_109 , 1 ) ;
if ( V_74 )
F_32 ( & V_93 -> V_35 , L_14 , V_74 ) ;
return 0 ;
}
static int F_52 ( struct V_92 * V_93 )
{
T_5 V_74 ;
struct V_6 * V_7 = F_47 ( V_93 ) ;
unsigned long V_8 ;
V_74 = F_51 ( V_93 , V_109 , 0 ) ;
F_50 ( V_93 , V_109 ) ;
V_74 = F_31 ( V_93 ) ;
if ( V_74 ) {
F_32 ( & V_93 -> V_35 , L_15 , V_74 ) ;
return V_74 ;
}
F_53 ( V_93 ) ;
F_3 ( & V_7 -> V_9 , V_8 ) ;
F_5 ( 0x01 , & V_7 -> V_10 -> V_110 ) ;
F_5 ( 0x00 , & V_7 -> V_10 -> V_110 ) ;
F_11 ( V_7 ) ;
F_6 ( & V_7 -> V_9 , V_8 ) ;
return 0 ;
}
