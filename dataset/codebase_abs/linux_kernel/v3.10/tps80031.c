int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , int V_4 ,
int V_5 , int V_6 )
{
T_1 V_7 = 0 ;
int V_8 = 0 ;
int V_9 ;
if ( ! ( V_3 & V_10 ) )
return 0 ;
if ( V_3 & V_11 ) {
V_7 = V_12 + ( V_4 >> 3 ) ;
V_8 = 5 ;
} else if ( V_3 & V_13 ) {
V_7 = V_14 + ( V_4 >> 3 ) ;
V_8 = 6 ;
} else if ( V_3 & V_15 ) {
V_7 = V_16 + ( V_4 >> 3 ) ;
V_8 = 7 ;
}
V_9 = F_2 ( V_2 , V_17 , V_7 ,
F_3 ( V_4 & 0x7 ) ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_1 ,
V_7 , V_9 ) ;
return V_9 ;
}
V_9 = F_5 ( V_2 , V_17 ,
V_18 , F_3 ( V_8 ) ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_2 ,
V_18 , V_9 ) ;
return V_9 ;
}
if ( V_3 & ( V_13 |
V_15 ) ) {
V_9 = F_6 ( V_2 , V_17 , V_5 ,
0x0 , V_19 ) ;
if ( V_9 < 0 )
F_4 ( V_2 , L_3 ,
V_5 , V_9 ) ;
} else {
V_9 = F_6 ( V_2 , V_17 , V_6 ,
V_20 ,
V_21 ) ;
if ( V_9 < 0 )
F_4 ( V_2 , L_3 ,
V_6 , V_9 ) ;
}
return V_9 ;
}
static void F_7 ( void )
{
F_8 ( V_22 -> V_2 , L_4 ) ;
F_9 ( V_22 -> V_2 , V_17 ,
V_23 , V_24 ) ;
}
static void F_10 ( struct V_25 * V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_29 ;
int V_30 = V_27 -> V_31 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_30 ; ++ V_32 ) {
struct V_28 * V_33 = & V_29 [ V_32 ] ;
const struct V_34 * V_35 =
& V_36 [ V_33 -> V_37 ] ;
T_1 V_38 = 0 ;
T_1 V_39 = V_35 -> V_40 | V_35 -> V_41 ;
if ( V_33 -> V_42 == V_43 )
V_38 = V_35 -> V_40 ;
else if ( V_33 -> V_42 == V_44 )
V_38 = V_35 -> V_41 ;
F_6 ( V_25 -> V_2 , V_17 , V_35 -> V_45 ,
V_38 , V_39 ) ;
}
}
static int F_11 ( struct V_25 * V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_9 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < 9 ; ++ V_32 ) {
V_9 = F_9 ( V_2 , V_17 ,
V_12 + V_32 , 0 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_5 ,
V_12 + V_32 , V_9 ) ;
return V_9 ;
}
}
V_9 = F_2 ( V_2 , V_17 ,
V_18 , 0x7 << 5 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_6 ,
V_18 , V_9 ) ;
return V_9 ;
}
return V_9 ;
}
static int F_12 ( struct V_25 * V_25 , int V_46 , int V_47 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_32 , V_9 ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ )
F_9 ( V_2 , V_48 ,
V_49 + V_32 , 0x00 ) ;
V_9 = F_13 ( V_25 -> V_50 [ V_48 ] , V_46 ,
V_51 , V_47 ,
& V_52 , & V_25 -> V_53 ) ;
if ( V_9 < 0 ) {
F_4 ( V_2 , L_7 , V_9 ) ;
return V_9 ;
}
return V_9 ;
}
static bool F_14 ( struct V_1 * V_2 , unsigned int V_45 )
{
switch ( V_45 ) {
case V_54 ... V_55 :
return true ;
default:
return false ;
}
}
static bool F_15 ( struct V_1 * V_2 , unsigned int V_45 )
{
switch ( V_45 ) {
case V_56 ... V_57 :
case V_58 ... V_59 :
case V_60 ... V_61 :
case V_62 ... V_63 :
case V_64 ... V_65 :
case V_66 ... V_67 :
case V_68 ... V_69 :
case V_12 ... V_70 :
case V_71 ... V_72 :
case V_73 ... V_74 :
case V_75 :
return true ;
default:
return false ;
}
}
static bool F_16 ( struct V_1 * V_2 , unsigned int V_45 )
{
switch ( V_45 ) {
case V_62 ... V_63 :
case V_66 ... V_67 :
case V_68 ... V_69 :
case V_12 ... V_70 :
case V_71 ... V_72 :
case V_73 ... V_74 :
return true ;
default:
return false ;
}
}
static bool F_17 ( struct V_1 * V_2 , unsigned int V_45 )
{
switch ( V_45 ) {
case V_76 ... V_77 :
case V_78 ... V_79 :
case V_80 ... V_81 :
case V_82 ... V_83 :
case V_84 ... V_85 :
case V_86 ... V_87 :
case V_88 ... V_89 :
case V_90 ... V_91 :
return true ;
default:
return false ;
}
}
static bool F_18 ( struct V_1 * V_2 , unsigned int V_45 )
{
switch ( V_45 ) {
case V_92 ... V_93 :
return true ;
default:
return false ;
}
}
static int F_19 ( struct V_94 * V_95 ,
const struct V_96 * V_97 )
{
struct V_26 * V_27 = V_95 -> V_2 . V_98 ;
struct V_25 * V_25 ;
int V_9 ;
T_2 V_99 ;
T_2 V_100 ;
int V_32 ;
if ( ! V_27 ) {
F_4 ( & V_95 -> V_2 , L_8 ) ;
return - V_101 ;
}
V_25 = F_20 ( & V_95 -> V_2 , sizeof( * V_25 ) , V_102 ) ;
if ( ! V_25 ) {
F_4 ( & V_95 -> V_2 , L_9 ) ;
return - V_103 ;
}
for ( V_32 = 0 ; V_32 < V_104 ; V_32 ++ ) {
if ( V_105 [ V_32 ] == V_95 -> V_106 )
V_25 -> V_107 [ V_32 ] = V_95 ;
else
V_25 -> V_107 [ V_32 ] = F_21 ( V_95 -> V_108 ,
V_105 [ V_32 ] ) ;
if ( ! V_25 -> V_107 [ V_32 ] ) {
F_4 ( & V_95 -> V_2 , L_10 , V_32 ) ;
V_9 = - V_103 ;
goto V_109;
}
F_22 ( V_25 -> V_107 [ V_32 ] , V_25 ) ;
V_25 -> V_50 [ V_32 ] = F_23 ( V_25 -> V_107 [ V_32 ] ,
& V_110 [ V_32 ] ) ;
if ( F_24 ( V_25 -> V_50 [ V_32 ] ) ) {
V_9 = F_25 ( V_25 -> V_50 [ V_32 ] ) ;
F_4 ( & V_95 -> V_2 ,
L_11 , V_32 , V_9 ) ;
goto V_109;
}
}
V_9 = F_26 ( & V_95 -> V_2 , V_111 ,
V_112 , & V_99 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_95 -> V_2 ,
L_12 , V_9 ) ;
goto V_109;
}
V_9 = F_26 ( & V_95 -> V_2 , V_111 ,
V_113 , & V_100 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_95 -> V_2 ,
L_13 , V_9 ) ;
goto V_109;
}
F_8 ( & V_95 -> V_2 , L_14 ,
V_99 , V_100 ) ;
V_25 -> V_99 = V_99 ;
V_25 -> V_2 = & V_95 -> V_2 ;
F_22 ( V_95 , V_25 ) ;
V_25 -> V_114 = V_97 -> V_115 ;
V_9 = F_12 ( V_25 , V_95 -> V_46 , V_27 -> V_47 ) ;
if ( V_9 ) {
F_4 ( & V_95 -> V_2 , L_15 , V_9 ) ;
goto V_109;
}
F_10 ( V_25 , V_27 ) ;
F_11 ( V_25 , V_27 ) ;
V_9 = F_27 ( V_25 -> V_2 , - 1 ,
V_116 , F_28 ( V_116 ) ,
NULL , 0 ,
F_29 ( V_25 -> V_53 ) ) ;
if ( V_9 < 0 ) {
F_4 ( & V_95 -> V_2 , L_16 , V_9 ) ;
goto V_117;
}
if ( V_27 -> V_118 && ! V_119 ) {
V_22 = V_25 ;
V_119 = F_7 ;
}
return 0 ;
V_117:
F_30 ( V_95 -> V_46 , V_25 -> V_53 ) ;
V_109:
for ( V_32 = 0 ; V_32 < V_104 ; V_32 ++ ) {
if ( V_25 -> V_107 [ V_32 ] && ( V_25 -> V_107 [ V_32 ] != V_95 ) )
F_31 ( V_25 -> V_107 [ V_32 ] ) ;
}
return V_9 ;
}
static int F_32 ( struct V_94 * V_95 )
{
struct V_25 * V_25 = F_33 ( V_95 ) ;
int V_32 ;
if ( V_22 == V_25 ) {
V_22 = NULL ;
V_119 = NULL ;
}
F_34 ( V_25 -> V_2 ) ;
F_30 ( V_95 -> V_46 , V_25 -> V_53 ) ;
for ( V_32 = 0 ; V_32 < V_104 ; V_32 ++ ) {
if ( V_25 -> V_107 [ V_32 ] != V_95 )
F_31 ( V_25 -> V_107 [ V_32 ] ) ;
}
return 0 ;
}
static int T_3 F_35 ( void )
{
return F_36 ( & V_120 ) ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_120 ) ;
}
