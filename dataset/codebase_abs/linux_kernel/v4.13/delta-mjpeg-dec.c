static char * F_1 ( struct V_1 * V_2 ,
char * V_3 , unsigned int V_4 )
{
char * V_5 = V_3 ;
if ( ! V_2 )
return L_1 ;
V_5 += snprintf ( V_5 , V_4 ,
L_2
L_3
L_4 ,
V_2 -> V_6 ,
V_2 -> V_7 ) ;
return V_3 ;
}
static char * F_2 ( struct V_8 * V_2 ,
char * V_3 , unsigned int V_4 )
{
char * V_5 = V_3 ;
if ( ! V_2 )
return L_1 ;
V_5 += snprintf ( V_5 , V_4 ,
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14 ,
V_2 -> V_9 ,
V_2 -> V_10 ,
V_2 -> V_11 ,
V_2 -> V_12 . V_13 ,
V_2 -> V_12 . V_14 ,
V_2 -> V_15 , V_2 -> V_16 ,
V_2 -> V_17 ,
V_2 -> V_18 ) ;
return V_3 ;
}
static inline bool F_3 ( enum V_19 V_20 )
{
switch ( V_20 ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
return true ;
default:
return false ;
}
}
static inline const char * F_4 ( enum V_19 V_20 )
{
switch ( V_20 ) {
case V_33 :
return L_15 ;
case V_21 :
return L_16 ;
case V_34 :
return L_17 ;
case V_35 :
return L_18 ;
case V_36 :
return L_19 ;
case V_37 :
return L_20 ;
case V_38 :
return L_21 ;
case V_22 :
return L_22 ;
case V_39 :
return L_23 ;
case V_23 :
return L_24 ;
case V_24 :
return L_25 ;
case V_25 :
return L_26 ;
case V_26 :
return L_27 ;
case V_27 :
return L_28 ;
case V_28 :
return L_29 ;
case V_29 :
return L_30 ;
case V_30 :
return L_31 ;
case V_31 :
return L_32 ;
case V_32 :
return L_33 ;
case V_40 :
return L_34 ;
case V_41 :
return L_35 ;
case V_42 :
return L_36 ;
case V_43 :
return L_37 ;
case V_44 :
return L_38 ;
case V_45 :
return L_39 ;
case V_46 :
return L_40 ;
case V_47 :
return L_41 ;
case V_48 :
return L_42 ;
case V_49 :
return L_43 ;
case V_50 :
return L_44 ;
default:
return L_45 ;
}
}
static bool F_5 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = V_52 -> V_57 ;
bool V_58 = false ;
if ( V_54 -> V_59 == V_33 )
goto V_60;
if ( F_3 ( V_54 -> V_59 ) ) {
F_6 ( V_56 -> V_57 ,
L_46 ,
V_52 -> V_61 , V_52 -> V_62 ,
F_4 ( V_54 -> V_59 ) ) ;
V_52 -> V_63 ++ ;
} else {
F_6 ( V_56 -> V_57 ,
L_47 ,
V_52 -> V_61 , V_52 -> V_62 ,
F_4 ( V_54 -> V_59 ) ) ;
V_52 -> V_64 ++ ;
V_58 = true ;
}
V_60:
F_7 ( V_56 -> V_57 ,
L_48 , V_52 -> V_61 ,
V_54 -> V_65 ) ;
return V_58 ;
}
static int F_8 ( struct V_51 * V_52 )
{
struct V_55 * V_56 = V_52 -> V_57 ;
struct V_66 * V_67 = F_9 ( V_52 ) ;
int V_68 = 0 ;
struct V_1 V_69 ;
struct V_1 * V_70 = & V_69 ;
struct V_71 * V_72 ;
T_1 V_73 ;
struct V_74 V_75 ;
void * V_76 ;
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
V_70 -> V_6 = 0x00000000 ;
V_70 -> V_7 = 0xffffffff ;
F_10 ( V_56 -> V_57 ,
L_49 , V_52 -> V_61 ,
F_1 ( V_70 , V_67 -> V_3 , sizeof( V_67 -> V_3 ) ) ) ;
V_75 . V_77 = sizeof( * V_70 ) ;
V_75 . V_78 = V_70 ;
V_73 = sizeof( struct V_8 ) +
sizeof( struct V_53 ) ;
V_68 = F_11 ( V_52 , L_50 , & V_75 ,
V_73 , & V_72 , & V_76 ) ;
if ( V_68 ) {
F_12 ( V_56 -> V_57 ,
L_51 , V_52 -> V_61 ,
F_1 ( V_70 , V_67 -> V_3 , sizeof( V_67 -> V_3 ) ) ) ;
return V_68 ;
}
V_67 -> V_72 = V_72 ;
V_67 -> V_79 = V_76 ;
return 0 ;
}
static int F_13 ( struct V_51 * V_52 , struct V_80 * V_81 )
{
struct V_55 * V_56 = V_52 -> V_57 ;
struct V_66 * V_67 = F_9 ( V_52 ) ;
int V_68 = 0 ;
struct V_8 * V_70 = V_67 -> V_72 -> V_82 ;
struct V_53 * V_54 =
V_67 -> V_72 -> V_82 + sizeof( * V_70 ) ;
struct V_83 * V_84 ;
struct V_74 V_75 , V_85 ;
V_68 = F_14 ( V_52 , & V_84 ) ;
if ( V_68 )
return V_68 ;
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
V_70 -> V_9 = ( T_1 ) ( V_81 -> V_86 ) ;
V_70 -> V_10 = ( T_1 ) ( V_81 -> V_86 + V_81 -> V_77 - 1 ) ;
V_70 -> V_15 = V_87 ;
V_70 -> V_16 = V_88 ;
V_70 -> V_89 = V_90 ;
V_70 -> V_91 = V_92 ;
V_70 -> V_11 = V_93 ;
V_70 -> V_12 . V_94 =
sizeof( struct V_95 ) ;
V_70 -> V_12 . V_13 =
( T_1 ) V_84 -> V_86 ;
V_70 -> V_12 . V_14 =
( T_1 ) ( V_84 -> V_86
+ V_84 -> V_96 . V_97 * V_84 -> V_96 . V_98 ) ;
F_10 ( V_56 -> V_57 ,
L_49 , V_52 -> V_61 ,
F_2 ( V_70 , V_67 -> V_3 , sizeof( V_67 -> V_3 ) ) ) ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_59 = V_33 ;
V_75 . V_77 = sizeof( * V_70 ) ;
V_75 . V_78 = V_70 ;
V_85 . V_77 = sizeof( * V_54 ) ;
V_85 . V_78 = V_54 ;
V_68 = F_15 ( V_67 -> V_79 , & V_75 , & V_85 ) ;
if ( V_68 ) {
F_12 ( V_56 -> V_57 ,
L_51 , V_52 -> V_61 ,
F_2 ( V_70 , V_67 -> V_3 ,
sizeof( V_67 -> V_3 ) ) ) ;
return V_68 ;
}
V_52 -> V_62 ++ ;
if ( F_5 ( V_52 , V_54 ) ) {
F_12 ( V_56 -> V_57 ,
L_51 , V_52 -> V_61 ,
F_2 ( V_70 , V_67 -> V_3 ,
sizeof( V_67 -> V_3 ) ) ) ;
}
V_84 -> V_99 = V_100 ;
V_84 -> V_101 = V_102 ;
V_84 -> V_103 |= V_104 ;
V_67 -> V_105 = V_84 ;
return 0 ;
}
static int F_16 ( struct V_51 * V_52 )
{
struct V_66 * V_67 ;
V_67 = F_17 ( sizeof( * V_67 ) , V_106 ) ;
if ( ! V_67 )
return - V_107 ;
V_52 -> V_108 = V_67 ;
return 0 ;
}
static int F_18 ( struct V_51 * V_52 )
{
struct V_66 * V_67 = F_9 ( V_52 ) ;
if ( V_67 -> V_79 ) {
F_19 ( V_67 -> V_79 ) ;
V_67 -> V_79 = NULL ;
}
F_20 ( V_67 ) ;
return 0 ;
}
static int F_21 ( struct V_51 * V_52 ,
struct V_109 * V_110 )
{
struct V_66 * V_67 = F_9 ( V_52 ) ;
if ( ! V_67 -> V_111 )
goto V_112;
V_110 -> V_113 = V_114 ;
V_110 -> V_115 = V_67 -> V_111 -> V_116 ;
V_110 -> V_117 = V_67 -> V_111 -> V_118 ;
V_110 -> V_99 = V_100 ;
V_110 -> V_119 = 1 ;
return 0 ;
V_112:
return - V_120 ;
}
static int F_22 ( struct V_51 * V_52 , struct V_80 * V_121 )
{
struct V_55 * V_56 = V_52 -> V_57 ;
struct V_66 * V_67 = F_9 ( V_52 ) ;
int V_68 ;
struct V_80 V_81 = * V_121 ;
unsigned int V_122 = 0 ;
struct V_123 * V_111 = & V_67 -> V_124 ;
if ( ! V_67 -> V_111 ) {
V_68 = F_23 ( V_52 , V_81 . V_82 , V_81 . V_77 ,
V_111 , & V_122 ) ;
if ( V_68 ) {
V_52 -> V_63 ++ ;
goto V_20;
}
if ( V_111 -> V_116 * V_111 -> V_118 >
V_125 ) {
F_12 ( V_56 -> V_57 ,
L_52 ,
V_52 -> V_61 ,
V_111 -> V_116 ,
V_111 -> V_118 , V_125 ) ;
V_68 = - V_126 ;
goto V_20;
}
V_67 -> V_111 = V_111 ;
goto V_60;
}
if ( ! V_67 -> V_79 ) {
V_68 = F_8 ( V_52 ) ;
if ( V_68 )
goto V_20;
}
V_68 = F_23 ( V_52 , V_81 . V_82 , V_81 . V_77 ,
V_67 -> V_111 , & V_122 ) ;
if ( V_68 ) {
V_52 -> V_63 ++ ;
goto V_20;
}
V_81 . V_86 += V_122 ;
V_81 . V_82 += V_122 ;
V_68 = F_13 ( V_52 , & V_81 ) ;
if ( V_68 )
goto V_20;
V_60:
return 0 ;
V_20:
return V_68 ;
}
static int F_24 ( struct V_51 * V_52 ,
struct V_83 * * V_84 )
{
struct V_66 * V_67 = F_9 ( V_52 ) ;
if ( ! V_67 -> V_105 )
return - V_120 ;
* V_84 = V_67 -> V_105 ;
V_67 -> V_105 = NULL ;
return 0 ;
}
