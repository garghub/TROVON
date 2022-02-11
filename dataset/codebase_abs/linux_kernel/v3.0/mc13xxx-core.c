struct V_1 * F_1 ( struct V_2 * V_2 )
{
return & V_2 -> V_1 ;
}
void F_2 ( struct V_1 * V_1 )
{
if ( ! F_3 ( & V_1 -> V_3 ) ) {
F_4 ( & V_1 -> V_4 -> V_5 , L_1 ,
V_6 , F_5 ( 0 ) ) ;
F_6 ( & V_1 -> V_3 ) ;
}
F_4 ( & V_1 -> V_4 -> V_5 , L_2 ,
V_6 , F_5 ( 0 ) ) ;
}
void F_7 ( struct V_1 * V_1 )
{
F_4 ( & V_1 -> V_4 -> V_5 , L_2 ,
V_6 , F_5 ( 0 ) ) ;
F_8 ( & V_1 -> V_3 ) ;
}
int F_9 ( struct V_1 * V_1 , unsigned int V_7 , T_1 * V_8 )
{
struct V_9 V_10 ;
struct V_11 V_12 ;
int V_13 ;
F_10 ( ! F_11 ( & V_1 -> V_3 ) ) ;
if ( V_7 > V_14 )
return - V_15 ;
* V_8 = V_7 << V_16 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_17 = V_8 ;
V_10 . V_18 = V_8 ;
V_10 . V_19 = sizeof( T_1 ) ;
F_12 ( & V_12 ) ;
F_13 ( & V_10 , & V_12 ) ;
V_13 = F_14 ( V_1 -> V_4 , & V_12 ) ;
F_10 ( ! V_13 && V_12 . V_20 ) ;
if ( V_13 )
return V_13 ;
* V_8 &= 0xffffff ;
F_15 ( & V_1 -> V_4 -> V_5 , L_3 , V_7 , * V_8 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_1 , unsigned int V_7 , T_1 V_8 )
{
T_1 V_21 ;
struct V_9 V_10 ;
struct V_11 V_12 ;
int V_13 ;
F_10 ( ! F_11 ( & V_1 -> V_3 ) ) ;
F_15 ( & V_1 -> V_4 -> V_5 , L_4 , V_7 , V_8 ) ;
if ( V_7 > V_14 || V_8 > 0xffffff )
return - V_15 ;
V_21 = 1 << 31 | V_7 << V_16 | V_8 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_17 = & V_21 ;
V_10 . V_18 = & V_21 ;
V_10 . V_19 = sizeof( T_1 ) ;
F_12 ( & V_12 ) ;
F_13 ( & V_10 , & V_12 ) ;
V_13 = F_14 ( V_1 -> V_4 , & V_12 ) ;
F_10 ( ! V_13 && V_12 . V_20 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
int F_17 ( struct V_1 * V_1 , unsigned int V_7 ,
T_1 V_22 , T_1 V_8 )
{
int V_13 ;
T_1 V_23 ;
F_10 ( V_8 & ~ V_22 ) ;
V_13 = F_9 ( V_1 , V_7 , & V_23 ) ;
if ( V_13 )
return V_13 ;
V_23 = ( V_23 & ~ V_22 ) | V_8 ;
return F_16 ( V_1 , V_7 , V_23 ) ;
}
int F_18 ( struct V_1 * V_1 , int V_24 )
{
int V_13 ;
unsigned int V_25 = V_24 < 24 ? V_26 : V_27 ;
T_1 V_28 = 1 << ( V_24 < 24 ? V_24 : V_24 - 24 ) ;
T_1 V_22 ;
if ( V_24 < 0 || V_24 >= V_29 )
return - V_15 ;
V_13 = F_9 ( V_1 , V_25 , & V_22 ) ;
if ( V_13 )
return V_13 ;
if ( V_22 & V_28 )
return 0 ;
return F_16 ( V_1 , V_25 , V_22 | V_28 ) ;
}
int F_19 ( struct V_1 * V_1 , int V_24 )
{
int V_13 ;
unsigned int V_25 = V_24 < 24 ? V_26 : V_27 ;
T_1 V_28 = 1 << ( V_24 < 24 ? V_24 : V_24 - 24 ) ;
T_1 V_22 ;
if ( V_24 < 0 || V_24 >= V_29 )
return - V_15 ;
V_13 = F_9 ( V_1 , V_25 , & V_22 ) ;
if ( V_13 )
return V_13 ;
if ( ! ( V_22 & V_28 ) )
return 0 ;
return F_16 ( V_1 , V_25 , V_22 & ~ V_28 ) ;
}
int F_20 ( struct V_1 * V_1 , int V_24 ,
int * V_30 , int * V_31 )
{
int V_13 ;
unsigned int V_25 = V_24 < 24 ? V_26 : V_27 ;
unsigned int V_32 = V_24 < 24 ? V_33 : V_34 ;
T_1 V_28 = 1 << ( V_24 < 24 ? V_24 : V_24 - 24 ) ;
if ( V_24 < 0 || V_24 >= V_29 )
return - V_15 ;
if ( V_30 ) {
T_1 V_22 ;
V_13 = F_9 ( V_1 , V_25 , & V_22 ) ;
if ( V_13 )
return V_13 ;
* V_30 = V_22 & V_28 ;
}
if ( V_31 ) {
T_1 V_35 ;
V_13 = F_9 ( V_1 , V_32 , & V_35 ) ;
if ( V_13 )
return V_13 ;
* V_31 = V_35 & V_28 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_1 , int V_24 )
{
unsigned int V_32 = V_24 < 24 ? V_33 : V_34 ;
unsigned int V_8 = 1 << ( V_24 < 24 ? V_24 : V_24 - 24 ) ;
F_10 ( V_24 < 0 || V_24 >= V_29 ) ;
return F_16 ( V_1 , V_32 , V_8 ) ;
}
int F_22 ( struct V_1 * V_1 , int V_24 ,
T_2 V_36 , const char * V_37 , void * V_5 )
{
F_10 ( ! F_11 ( & V_1 -> V_3 ) ) ;
F_10 ( ! V_36 ) ;
if ( V_24 < 0 || V_24 >= V_29 )
return - V_15 ;
if ( V_1 -> V_38 [ V_24 ] )
return - V_39 ;
V_1 -> V_38 [ V_24 ] = V_36 ;
V_1 -> V_40 [ V_24 ] = V_5 ;
return 0 ;
}
int F_23 ( struct V_1 * V_1 , int V_24 ,
T_2 V_36 , const char * V_37 , void * V_5 )
{
int V_13 ;
V_13 = F_22 ( V_1 , V_24 , V_36 , V_37 , V_5 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_19 ( V_1 , V_24 ) ;
if ( V_13 ) {
V_1 -> V_38 [ V_24 ] = NULL ;
V_1 -> V_40 [ V_24 ] = NULL ;
return V_13 ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_1 , int V_24 , void * V_5 )
{
int V_13 ;
F_10 ( ! F_11 ( & V_1 -> V_3 ) ) ;
if ( V_24 < 0 || V_24 >= V_29 || ! V_1 -> V_38 [ V_24 ] ||
V_1 -> V_40 [ V_24 ] != V_5 )
return - V_15 ;
V_13 = F_18 ( V_1 , V_24 ) ;
if ( V_13 )
return V_13 ;
V_1 -> V_38 [ V_24 ] = NULL ;
V_1 -> V_40 [ V_24 ] = NULL ;
return 0 ;
}
static inline T_3 F_25 ( struct V_1 * V_1 , int V_24 )
{
return V_1 -> V_38 [ V_24 ] ( V_24 , V_1 -> V_40 [ V_24 ] ) ;
}
static int F_26 ( struct V_1 * V_1 ,
unsigned int V_32 , unsigned int V_25 , int V_41 )
{
T_1 V_35 , V_22 ;
int V_13 = F_9 ( V_1 , V_32 , & V_35 ) ;
int V_42 = 0 ;
if ( V_13 )
return V_13 ;
V_13 = F_9 ( V_1 , V_25 , & V_22 ) ;
if ( V_13 )
return V_13 ;
while ( V_35 & ~ V_22 ) {
int V_24 = F_27 ( V_35 & ~ V_22 ) ;
V_35 &= ~ ( 1 << V_24 ) ;
if ( F_28 ( V_1 -> V_38 [ V_41 + V_24 ] ) ) {
T_3 V_43 ;
V_43 = F_25 ( V_1 , V_41 + V_24 ) ;
if ( V_43 == V_44 )
V_42 ++ ;
} else {
F_29 ( & V_1 -> V_4 -> V_5 ,
L_5 ,
V_41 + V_24 ) ;
V_22 |= 1 << V_24 ;
V_13 = F_16 ( V_1 , V_25 , V_22 ) ;
}
}
return V_42 ;
}
static T_3 F_30 ( int V_24 , void * V_45 )
{
struct V_1 * V_1 = V_45 ;
T_3 V_13 ;
int V_43 = 0 ;
F_2 ( V_1 ) ;
V_13 = F_26 ( V_1 , V_33 ,
V_26 , 0 ) ;
if ( V_13 > 0 )
V_43 = 1 ;
V_13 = F_26 ( V_1 , V_34 ,
V_27 , 24 ) ;
if ( V_13 > 0 )
V_43 = 1 ;
F_7 ( V_1 ) ;
return F_31 ( V_43 ) ;
}
static int F_32 ( struct V_1 * V_1 , enum V_46 * V_47 )
{
T_1 V_48 ;
T_1 V_49 ;
const char * V_37 ;
int V_13 ;
V_13 = F_9 ( V_1 , 46 , & V_48 ) ;
if ( V_13 )
return V_13 ;
V_48 = ( V_48 >> 6 ) & 0x7 ;
switch ( V_48 ) {
case 2 :
* V_47 = V_50 ;
V_37 = L_6 ;
break;
case 7 :
* V_47 = V_51 ;
V_37 = L_7 ;
break;
default:
* V_47 = V_52 ;
break;
}
if ( * V_47 == V_50 || * V_47 == V_51 ) {
V_13 = F_9 ( V_1 , V_53 , & V_49 ) ;
if ( V_13 )
return V_13 ;
F_33 ( & V_1 -> V_4 -> V_5 , L_8
L_9 ,
V_54 [ * V_47 ] ,
F_34 ( V_49 , V_55 ) ,
F_34 ( V_49 , V_56 ) ,
F_34 ( V_49 , V_57 ) ,
F_34 ( V_49 , V_58 ) ,
F_34 ( V_49 , V_59 ) ,
F_34 ( V_49 , V_60 ) ) ;
}
if ( * V_47 != V_52 ) {
const struct V_61 * V_62 =
F_35 ( V_1 -> V_4 ) ;
if ( ! V_62 || V_62 -> V_63 != * V_47 )
F_36 ( & V_1 -> V_4 -> V_5 , L_10
L_11 ) ;
}
return 0 ;
}
static const char * F_37 ( struct V_1 * V_1 )
{
const struct V_61 * V_62 =
F_35 ( V_1 -> V_4 ) ;
if ( ! V_62 )
return NULL ;
return V_54 [ V_62 -> V_63 ] ;
}
int F_38 ( struct V_1 * V_1 )
{
struct V_64 * V_65 =
F_39 ( & V_1 -> V_4 -> V_5 ) ;
return V_65 -> V_66 ;
}
static T_3 F_40 ( int V_24 , void * V_45 )
{
struct V_67 * V_68 = V_45 ;
F_21 ( V_68 -> V_1 , V_24 ) ;
F_41 ( & V_68 -> V_69 ) ;
return V_44 ;
}
int F_42 ( struct V_2 * V_2 , unsigned int V_70 ,
unsigned int V_71 , unsigned int * V_72 )
{
struct V_1 * V_1 = & V_2 -> V_1 ;
T_1 V_73 , V_74 , V_75 ;
int V_76 , V_13 ;
struct V_67 V_68 = {
. V_1 = V_1 ,
} ;
F_43 ( & V_68 . V_69 ) ;
F_4 ( & V_1 -> V_4 -> V_5 , L_12 , V_6 ) ;
F_2 ( V_1 ) ;
if ( V_2 -> V_77 & V_78 ) {
V_13 = - V_39 ;
goto V_79;
}
V_2 -> V_77 |= V_78 ;
F_9 ( V_1 , V_80 , & V_75 ) ;
V_73 = V_81 | V_82 ;
V_74 = V_83 | V_84 | V_85 ;
if ( V_71 > 7 )
V_74 |= V_86 ;
switch ( V_70 ) {
case V_87 :
V_73 |= V_88 | V_89 |
V_90 ;
V_74 |= 4 << V_91 ;
break;
case V_92 :
V_73 |= V_75 & V_93 ;
V_74 |= ( V_71 & 0x7 ) << V_94 ;
V_74 |= V_95 ;
break;
case V_96 :
V_73 |= V_75 & V_93 ;
V_74 |= 4 << V_91 ;
break;
default:
F_44 ( V_2 ) ;
return - V_15 ;
}
F_4 ( & V_2 -> V_1 . V_4 -> V_5 , L_13 , V_6 ) ;
F_23 ( V_1 , V_97 ,
F_40 , V_6 , & V_68 ) ;
F_21 ( V_1 , V_97 ) ;
F_16 ( V_1 , V_80 , V_73 ) ;
F_16 ( V_1 , V_98 , V_74 ) ;
F_7 ( V_1 ) ;
V_13 = F_45 ( & V_68 . V_69 , V_99 ) ;
if ( ! V_13 )
V_13 = - V_100 ;
F_2 ( V_1 ) ;
F_24 ( V_1 , V_97 , & V_68 ) ;
if ( V_13 > 0 )
for ( V_76 = 0 ; V_76 < 4 ; ++ V_76 ) {
V_13 = F_9 ( V_1 ,
V_101 , & V_72 [ V_76 ] ) ;
if ( V_13 )
break;
}
if ( V_70 == V_87 )
F_16 ( V_1 , V_80 , V_75 ) ;
V_2 -> V_77 &= ~ V_78 ;
V_79:
F_7 ( V_1 ) ;
return V_13 ;
}
static int F_46 ( struct V_1 * V_1 ,
const char * V_102 , void * V_65 , T_4 V_103 )
{
char V_21 [ 30 ] ;
const char * V_37 = F_37 ( V_1 ) ;
struct V_104 V_105 = {
. V_106 = V_65 ,
. V_103 = V_103 ,
} ;
if ( snprintf ( V_21 , sizeof( V_21 ) , V_102 , V_37 ) > sizeof( V_21 ) )
return - V_107 ;
V_105 . V_37 = F_47 ( V_21 , strlen ( V_21 ) + 1 , V_108 ) ;
if ( ! V_105 . V_37 )
return - V_109 ;
return F_48 ( & V_1 -> V_4 -> V_5 , - 1 , & V_105 , 1 , NULL , 0 ) ;
}
static int F_49 ( struct V_1 * V_1 , const char * V_102 )
{
return F_46 ( V_1 , V_102 , NULL , 0 ) ;
}
static int F_50 ( struct V_110 * V_111 )
{
struct V_1 * V_1 ;
struct V_64 * V_65 = F_39 ( & V_111 -> V_5 ) ;
enum V_46 V_47 ;
int V_13 ;
V_1 = F_51 ( sizeof( * V_1 ) , V_108 ) ;
if ( ! V_1 )
return - V_109 ;
F_52 ( & V_111 -> V_5 , V_1 ) ;
V_111 -> V_70 = V_112 | V_113 ;
V_111 -> V_114 = 32 ;
F_53 ( V_111 ) ;
V_1 -> V_4 = V_111 ;
F_54 ( & V_1 -> V_3 ) ;
F_2 ( V_1 ) ;
V_13 = F_32 ( V_1 , & V_47 ) ;
if ( V_13 || V_47 == V_52 )
goto V_115;
V_13 = F_16 ( V_1 , V_26 , 0x00ffffff ) ;
if ( V_13 )
goto V_116;
V_13 = F_16 ( V_1 , V_27 , 0x00ffffff ) ;
if ( V_13 )
goto V_116;
V_13 = F_55 ( V_111 -> V_24 , NULL , F_30 ,
V_117 | V_118 , L_14 , V_1 ) ;
if ( V_13 ) {
V_116:
V_115:
F_7 ( V_1 ) ;
F_52 ( & V_111 -> V_5 , NULL ) ;
F_56 ( V_1 ) ;
return V_13 ;
}
F_7 ( V_1 ) ;
if ( V_65 -> V_66 & V_119 )
F_49 ( V_1 , L_15 ) ;
if ( V_65 -> V_66 & V_120 )
F_49 ( V_1 , L_16 ) ;
if ( V_65 -> V_66 & V_121 ) {
F_46 ( V_1 , L_17 ,
& V_65 -> V_122 , sizeof( V_65 -> V_122 ) ) ;
}
if ( V_65 -> V_66 & V_123 )
F_49 ( V_1 , L_18 ) ;
if ( V_65 -> V_66 & V_124 )
F_49 ( V_1 , L_19 ) ;
if ( V_65 -> V_66 & V_125 )
F_46 ( V_1 , L_20 ,
V_65 -> V_126 , sizeof( * V_65 -> V_126 ) ) ;
return 0 ;
}
static int T_5 F_57 ( struct V_110 * V_111 )
{
struct V_1 * V_1 = F_58 ( & V_111 -> V_5 ) ;
F_59 ( V_1 -> V_4 -> V_24 , V_1 ) ;
F_60 ( & V_111 -> V_5 ) ;
F_56 ( V_1 ) ;
return 0 ;
}
static int T_6 F_61 ( void )
{
return F_62 ( & V_127 ) ;
}
static void T_7 F_63 ( void )
{
F_64 ( & V_127 ) ;
}
