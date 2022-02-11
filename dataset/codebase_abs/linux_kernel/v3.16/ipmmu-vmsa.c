static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_1 F_5 ( struct V_6 * V_7 , unsigned int V_8 )
{
return F_1 ( V_7 -> V_2 , V_7 -> V_9 * V_10 + V_8 ) ;
}
static void F_6 ( struct V_6 * V_7 , unsigned int V_8 ,
T_1 V_5 )
{
F_3 ( V_7 -> V_2 , V_7 -> V_9 * V_10 + V_8 , V_5 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
unsigned int V_11 = 0 ;
while ( F_5 ( V_7 , V_12 ) & V_13 ) {
F_8 () ;
if ( ++ V_11 == V_14 ) {
F_9 ( V_7 -> V_2 -> V_15 ,
L_1 ) ;
return;
}
F_10 ( 1 ) ;
}
}
static void F_11 ( struct V_6 * V_7 )
{
T_1 V_8 ;
V_8 = F_5 ( V_7 , V_12 ) ;
V_8 |= V_13 ;
F_6 ( V_7 , V_12 , V_8 ) ;
F_7 ( V_7 ) ;
}
static void F_12 ( struct V_6 * V_7 ,
unsigned int V_16 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , F_13 ( V_16 ) , 0 ) ;
F_3 ( V_2 , F_14 ( V_16 ) ,
F_15 ( V_7 -> V_9 ) | V_17 |
V_18 ) ;
}
static void F_16 ( struct V_6 * V_7 ,
unsigned int V_16 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
F_3 ( V_2 , F_14 ( V_16 ) , 0 ) ;
}
static void F_17 ( struct V_1 * V_2 , void * V_19 ,
T_2 V_20 )
{
unsigned long V_3 = ( unsigned long ) V_19 & ~ V_21 ;
F_18 ( V_2 -> V_15 , F_19 ( V_19 ) , V_3 , V_20 , V_22 ) ;
}
static int F_20 ( struct V_6 * V_7 )
{
T_3 V_23 ;
T_1 V_8 ;
V_7 -> V_9 = 0 ;
F_17 ( V_7 -> V_2 , V_7 -> V_24 ,
V_25 * sizeof( * V_7 -> V_24 ) ) ;
V_23 = F_21 ( V_7 -> V_24 ) ;
F_6 ( V_7 , V_26 , V_23 ) ;
F_6 ( V_7 , V_27 , V_23 >> 32 ) ;
F_6 ( V_7 , V_28 , V_29 |
V_30 | V_31 |
V_32 | V_33 ) ;
V_8 = ( V_34 << F_22 ( V_35 ) )
| ( V_36 << F_22 ( V_37 ) )
| ( V_38 << F_22 ( V_39 ) ) ;
F_6 ( V_7 , V_40 , V_8 ) ;
F_6 ( V_7 , V_41 ,
F_5 ( V_7 , V_41 ) &
~ ( V_42 | V_43 ) ) ;
F_6 ( V_7 , V_44 , F_5 ( V_7 , V_44 ) ) ;
F_6 ( V_7 , V_12 , V_45 | V_13 | V_46 ) ;
return 0 ;
}
static void F_23 ( struct V_6 * V_7 )
{
F_6 ( V_7 , V_12 , V_13 ) ;
F_7 ( V_7 ) ;
}
static T_4 F_24 ( struct V_6 * V_7 )
{
const T_1 V_47 = V_48 | V_49 | V_50 | V_51 ;
struct V_1 * V_2 = V_7 -> V_2 ;
T_1 V_52 ;
T_1 V_53 ;
V_52 = F_5 ( V_7 , V_44 ) ;
if ( ! ( V_52 & V_47 ) )
return V_54 ;
V_53 = F_5 ( V_7 , V_55 ) ;
F_6 ( V_7 , V_44 , 0 ) ;
if ( V_52 & V_48 )
F_9 ( V_2 -> V_15 , L_2 ,
V_53 ) ;
if ( V_52 & V_49 )
F_9 ( V_2 -> V_15 , L_3 ,
V_53 ) ;
if ( ! ( V_52 & ( V_50 | V_51 ) ) )
return V_54 ;
if ( ! F_25 ( V_7 -> V_56 , V_2 -> V_15 , V_53 , 0 ) )
return V_57 ;
F_9 ( V_2 -> V_15 ,
L_4 ,
V_52 , V_53 ) ;
return V_57 ;
}
static T_4 F_26 ( int V_58 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
struct V_59 * V_56 ;
struct V_6 * V_7 ;
if ( ! V_2 -> V_60 )
return V_54 ;
V_56 = V_2 -> V_60 -> V_7 ;
V_7 = V_56 -> V_61 ;
return F_24 ( V_7 ) ;
}
static void F_27 ( T_5 * V_62 )
{
T_6 V_63 = F_28 ( * V_62 ) ;
F_29 ( V_63 ) ;
}
static void F_30 ( T_7 * V_64 )
{
T_5 * V_62 = F_31 ( V_64 , 0 ) ;
T_6 V_63 ;
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < V_66 ; ++ V_65 ) {
if ( ! F_32 ( * V_62 ) )
continue;
F_27 ( V_62 ) ;
V_62 ++ ;
}
V_63 = F_33 ( * V_64 ) ;
F_29 ( V_63 ) ;
}
static void F_34 ( struct V_6 * V_7 )
{
T_8 * V_24 , * V_67 = V_7 -> V_24 ;
unsigned int V_65 ;
V_24 = V_67 ;
for ( V_65 = 0 ; V_65 < V_25 ; ++ V_65 ) {
if ( F_35 ( * V_24 ) )
continue;
F_30 ( ( T_7 * ) V_24 ) ;
V_24 ++ ;
}
F_36 ( V_67 ) ;
}
static T_9 * F_37 ( struct V_1 * V_2 , T_5 * V_62 ,
unsigned long V_53 )
{
T_9 * V_68 ;
if ( ! F_38 ( * V_62 ) )
return F_39 ( V_62 , V_53 ) ;
V_68 = ( T_9 * ) F_40 ( V_69 ) ;
if ( ! V_68 )
return NULL ;
F_17 ( V_2 , V_68 , V_70 ) ;
* V_62 = F_41 ( F_21 ( V_68 ) | V_71 | V_72 ) ;
F_17 ( V_2 , V_62 , sizeof( * V_62 ) ) ;
return V_68 + F_42 ( V_53 ) ;
}
static T_5 * F_43 ( struct V_1 * V_2 , T_8 * V_24 ,
unsigned long V_53 )
{
T_7 * V_64 = ( T_7 * ) V_24 ;
T_5 * V_62 ;
if ( ! F_44 ( * V_64 ) )
return F_31 ( V_64 , V_53 ) ;
V_62 = ( T_5 * ) F_40 ( V_69 ) ;
if ( ! V_62 )
return NULL ;
F_17 ( V_2 , V_62 , V_70 ) ;
* V_64 = F_45 ( F_21 ( V_62 ) | V_71 | V_72 ) ;
F_17 ( V_2 , V_64 , sizeof( * V_64 ) ) ;
return V_62 + F_46 ( V_53 ) ;
}
static T_10 F_47 ( unsigned int V_73 , T_10 type )
{
T_10 V_74 = V_75 | V_76 | V_77
| V_78 | V_79
| V_80 | type ;
if ( ! ( V_73 & V_81 ) && ( V_73 & V_82 ) )
V_74 |= V_83 ;
if ( V_73 & V_84 )
V_74 |= V_37 << V_85 ;
if ( V_73 & V_86 )
V_74 &= ~ V_75 ;
else if ( ! ( V_73 & ( V_82 | V_81 ) ) )
V_74 &= ~ V_87 ;
return V_74 ;
}
static int F_48 ( struct V_1 * V_2 , T_5 * V_62 ,
unsigned long V_53 , unsigned long V_88 ,
T_2 V_20 , int V_73 )
{
T_11 V_89 = F_47 ( V_73 , V_87 ) ;
unsigned int V_90 = 1 ;
T_9 * V_68 , * V_91 ;
unsigned int V_65 ;
V_68 = F_37 ( V_2 , V_62 , V_53 ) ;
if ( ! V_68 )
return - V_92 ;
V_91 = V_68 ;
if ( V_20 == V_93 ) {
V_89 |= V_94 ;
V_90 = V_95 ;
}
for ( V_65 = V_90 ; V_65 ; -- V_65 )
* V_68 ++ = F_49 ( V_88 ++ , F_50 ( V_89 ) ) ;
F_17 ( V_2 , V_91 , sizeof( * V_68 ) * V_90 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , T_5 * V_62 ,
unsigned long V_53 , unsigned long V_88 ,
int V_73 )
{
T_12 V_96 = F_47 ( V_73 , V_97 ) ;
* V_62 = F_52 ( V_88 , F_50 ( V_96 ) ) ;
F_17 ( V_2 , V_62 , sizeof( * V_62 ) ) ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 ,
unsigned long V_53 , T_3 V_98 ,
T_2 V_20 , int V_73 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
T_8 * V_24 = V_7 -> V_24 ;
unsigned long V_99 ;
unsigned long V_88 ;
T_5 * V_62 ;
int V_100 ;
if ( ! V_24 )
return - V_101 ;
if ( V_20 & ~ V_21 )
return - V_101 ;
if ( V_98 & ~ ( ( 1ULL << 40 ) - 1 ) )
return - V_102 ;
V_88 = F_54 ( V_98 ) ;
V_24 += F_55 ( V_53 ) ;
F_56 ( & V_7 -> V_103 , V_99 ) ;
V_62 = F_43 ( V_2 , V_24 , V_53 ) ;
if ( ! V_62 ) {
V_100 = - V_92 ;
goto V_104;
}
switch ( V_20 ) {
case V_105 :
V_100 = F_51 ( V_2 , V_62 , V_53 , V_88 , V_73 ) ;
break;
case V_93 :
case V_106 :
V_100 = F_48 ( V_2 , V_62 , V_53 , V_88 , V_20 , V_73 ) ;
break;
default:
V_100 = - V_101 ;
break;
}
V_104:
F_57 ( & V_7 -> V_103 , V_99 ) ;
if ( ! V_100 )
F_11 ( V_7 ) ;
return V_100 ;
}
static void F_58 ( struct V_1 * V_2 , T_7 * V_64 )
{
T_6 V_63 = F_33 ( * V_64 ) ;
F_29 ( V_63 ) ;
* V_64 = F_45 ( 0 ) ;
F_17 ( V_2 , V_64 , sizeof( * V_64 ) ) ;
}
static void F_59 ( struct V_1 * V_2 , T_7 * V_64 ,
T_5 * V_62 )
{
unsigned int V_65 ;
if ( F_32 ( * V_62 ) ) {
T_6 V_63 = F_28 ( * V_62 ) ;
F_29 ( V_63 ) ;
}
* V_62 = F_41 ( 0 ) ;
F_17 ( V_2 , V_62 , sizeof( * V_62 ) ) ;
V_62 = F_31 ( V_64 , 0 ) ;
for ( V_65 = 0 ; V_65 < V_66 ; ++ V_65 ) {
if ( ! F_38 ( V_62 [ V_65 ] ) )
return;
}
F_58 ( V_2 , V_64 ) ;
}
static void F_60 ( struct V_1 * V_2 , T_7 * V_64 ,
T_5 * V_62 , T_9 * V_68 , unsigned int V_90 )
{
unsigned int V_65 ;
for ( V_65 = V_90 ; V_65 ; -- V_65 )
V_68 [ V_65 - 1 ] = F_61 ( 0 ) ;
F_17 ( V_2 , V_68 , sizeof( * V_68 ) * V_90 ) ;
V_68 = F_39 ( V_62 , 0 ) ;
for ( V_65 = 0 ; V_65 < V_107 ; ++ V_65 ) {
if ( ! F_62 ( V_68 [ V_65 ] ) )
return;
}
F_59 ( V_2 , V_64 , V_62 ) ;
}
static int F_63 ( struct V_1 * V_2 , T_5 * V_62 )
{
T_9 * V_68 , * V_91 ;
T_11 V_89 ;
unsigned long V_88 ;
unsigned int V_65 ;
V_68 = ( T_9 * ) F_40 ( V_69 ) ;
if ( ! V_68 )
return - V_92 ;
V_89 = ( F_64 ( * V_62 ) & V_108 )
| V_94 | V_87 ;
V_88 = F_65 ( * V_62 ) ;
V_91 = V_68 ;
for ( V_65 = V_107 ; V_65 ; -- V_65 )
* V_68 ++ = F_49 ( V_88 ++ , F_50 ( V_89 ) ) ;
F_17 ( V_2 , V_91 , V_70 ) ;
* V_62 = F_41 ( F_21 ( V_91 ) | V_71 | V_72 ) ;
F_17 ( V_2 , V_62 , sizeof( * V_62 ) ) ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 , T_9 * V_68 )
{
unsigned int V_65 ;
for ( V_65 = V_95 ; V_65 ; -- V_65 )
V_68 [ V_65 - 1 ] = F_61 ( F_67 ( * V_68 ) & ~ V_94 ) ;
F_17 ( V_2 , V_68 , sizeof( * V_68 ) * V_95 ) ;
}
static int F_68 ( struct V_6 * V_7 ,
unsigned long V_53 , T_2 V_20 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned long V_99 ;
T_8 * V_24 = V_7 -> V_24 ;
T_7 * V_64 ;
T_5 * V_62 ;
T_9 * V_68 ;
int V_100 = 0 ;
if ( ! V_24 )
return - V_101 ;
if ( V_20 & ~ V_21 )
return - V_101 ;
V_24 += F_55 ( V_53 ) ;
V_64 = ( T_7 * ) V_24 ;
F_56 ( & V_7 -> V_103 , V_99 ) ;
if ( F_44 ( * V_64 ) )
goto V_104;
V_62 = F_31 ( V_64 , V_53 ) ;
if ( F_38 ( * V_62 ) )
goto V_104;
if ( V_20 == V_105 ) {
F_59 ( V_2 , V_64 , V_62 ) ;
goto V_104;
}
if ( F_69 ( * V_62 ) )
F_63 ( V_2 , V_62 ) ;
V_68 = F_39 ( V_62 , V_53 ) ;
if ( V_20 == V_93 ) {
F_60 ( V_2 , V_64 , V_62 , V_68 , V_95 ) ;
goto V_104;
}
if ( F_67 ( * V_68 ) & V_94 )
F_66 ( V_2 , V_68 ) ;
F_60 ( V_2 , V_64 , V_62 , V_68 , 1 ) ;
V_104:
F_57 ( & V_7 -> V_103 , V_99 ) ;
if ( V_100 )
F_11 ( V_7 ) ;
return 0 ;
}
static int F_70 ( struct V_59 * V_56 )
{
struct V_6 * V_7 ;
V_7 = F_71 ( sizeof( * V_7 ) , V_109 ) ;
if ( ! V_7 )
return - V_92 ;
F_72 ( & V_7 -> V_103 ) ;
V_7 -> V_24 = F_71 ( V_25 * sizeof( T_8 ) , V_109 ) ;
if ( ! V_7 -> V_24 ) {
F_36 ( V_7 ) ;
return - V_92 ;
}
V_56 -> V_61 = V_7 ;
V_7 -> V_56 = V_56 ;
return 0 ;
}
static void F_73 ( struct V_59 * V_56 )
{
struct V_6 * V_7 = V_56 -> V_61 ;
F_23 ( V_7 ) ;
F_34 ( V_7 ) ;
F_36 ( V_7 ) ;
}
static int F_74 ( struct V_59 * V_56 ,
struct V_110 * V_15 )
{
struct V_111 * V_112 = V_15 -> V_112 . V_113 ;
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_6 * V_7 = V_56 -> V_61 ;
unsigned long V_99 ;
int V_100 = 0 ;
if ( ! V_2 ) {
F_75 ( V_15 , L_5 ) ;
return - V_114 ;
}
F_56 ( & V_7 -> V_103 , V_99 ) ;
if ( ! V_7 -> V_2 ) {
V_7 -> V_2 = V_2 ;
V_100 = F_20 ( V_7 ) ;
} else if ( V_7 -> V_2 != V_2 ) {
F_75 ( V_15 , L_6 ,
F_76 ( V_2 -> V_15 ) , F_76 ( V_7 -> V_2 -> V_15 ) ) ;
V_100 = - V_101 ;
}
F_57 ( & V_7 -> V_103 , V_99 ) ;
if ( V_100 < 0 )
return V_100 ;
F_12 ( V_7 , V_112 -> V_16 ) ;
return 0 ;
}
static void F_77 ( struct V_59 * V_56 ,
struct V_110 * V_15 )
{
struct V_111 * V_112 = V_15 -> V_112 . V_113 ;
struct V_6 * V_7 = V_56 -> V_61 ;
F_16 ( V_7 , V_112 -> V_16 ) ;
}
static int F_78 ( struct V_59 * V_56 , unsigned long V_53 ,
T_3 V_98 , T_2 V_20 , int V_73 )
{
struct V_6 * V_7 = V_56 -> V_61 ;
if ( ! V_7 )
return - V_115 ;
return F_53 ( V_7 , V_53 , V_98 , V_20 , V_73 ) ;
}
static T_2 F_79 ( struct V_59 * V_56 , unsigned long V_53 ,
T_2 V_20 )
{
struct V_6 * V_7 = V_56 -> V_61 ;
int V_100 ;
V_100 = F_68 ( V_7 , V_53 , V_20 ) ;
return V_100 ? 0 : V_20 ;
}
static T_3 F_80 ( struct V_59 * V_56 ,
T_13 V_53 )
{
struct V_6 * V_7 = V_56 -> V_61 ;
T_8 V_24 ;
T_7 V_64 ;
T_5 V_62 ;
T_9 V_68 ;
if ( ! V_7 -> V_24 )
return 0 ;
V_24 = * ( V_7 -> V_24 + F_55 ( V_53 ) ) ;
if ( F_35 ( V_24 ) )
return 0 ;
V_64 = * F_81 ( & V_24 , V_53 ) ;
if ( F_44 ( V_64 ) )
return 0 ;
V_62 = * F_31 ( & V_64 , V_53 ) ;
if ( F_38 ( V_62 ) )
return 0 ;
if ( F_69 ( V_62 ) )
return F_82 ( F_65 ( V_62 ) ) | ( V_53 & ~ V_116 ) ;
V_68 = * ( F_83 ( V_62 ) + F_42 ( V_53 ) ) ;
if ( F_62 ( V_68 ) )
return 0 ;
return F_82 ( F_84 ( V_68 ) ) | ( V_53 & ~ V_21 ) ;
}
static int F_85 ( struct V_1 * V_2 , struct V_110 * V_15 )
{
const struct V_117 * V_118 = V_2 -> V_119 -> V_120 ;
const char * V_121 = F_76 ( V_15 ) ;
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < V_2 -> V_119 -> V_122 ; ++ V_65 , ++ V_118 ) {
if ( strcmp ( V_118 -> V_123 , V_121 ) == 0 )
return V_118 -> V_16 ;
}
return - 1 ;
}
static int F_86 ( struct V_110 * V_15 )
{
struct V_111 * V_112 ;
struct V_1 * V_2 ;
struct V_124 * V_125 ;
int V_16 = - 1 ;
int V_100 ;
if ( V_15 -> V_112 . V_113 ) {
F_87 ( V_15 , L_7 ,
F_76 ( V_15 ) ) ;
return - V_101 ;
}
F_88 ( & V_126 ) ;
F_89 (mmu, &ipmmu_devices, list) {
V_16 = F_85 ( V_2 , V_15 ) ;
if ( V_16 >= 0 ) {
break;
}
}
F_90 ( & V_126 ) ;
if ( V_16 < 0 )
return - V_115 ;
if ( V_16 >= V_2 -> V_127 )
return - V_101 ;
V_125 = F_91 () ;
if ( F_92 ( V_125 ) ) {
F_75 ( V_15 , L_8 ) ;
return F_93 ( V_125 ) ;
}
V_100 = F_94 ( V_125 , V_15 ) ;
F_95 ( V_125 ) ;
if ( V_100 < 0 ) {
F_75 ( V_15 , L_9 ) ;
return V_100 ;
}
V_112 = F_71 ( sizeof( * V_112 ) , V_109 ) ;
if ( ! V_112 ) {
V_100 = - V_92 ;
goto error;
}
V_112 -> V_2 = V_2 ;
V_112 -> V_16 = V_16 ;
V_15 -> V_112 . V_113 = V_112 ;
if ( ! V_2 -> V_60 ) {
struct V_128 * V_60 ;
V_60 = F_96 ( & V_129 ,
V_130 , V_131 ) ;
if ( F_92 ( V_60 ) ) {
F_75 ( V_2 -> V_15 , L_10 ) ;
return F_93 ( V_60 ) ;
}
V_2 -> V_60 = V_60 ;
}
V_100 = F_97 ( V_15 , V_2 -> V_60 ) ;
if ( V_100 < 0 ) {
F_75 ( V_15 , L_11 ) ;
goto error;
}
return 0 ;
error:
F_36 ( V_15 -> V_112 . V_113 ) ;
V_15 -> V_112 . V_113 = NULL ;
F_98 ( V_15 ) ;
return V_100 ;
}
static void F_99 ( struct V_110 * V_15 )
{
F_100 ( V_15 ) ;
F_98 ( V_15 ) ;
F_36 ( V_15 -> V_112 . V_113 ) ;
V_15 -> V_112 . V_113 = NULL ;
}
static void F_101 ( struct V_1 * V_2 )
{
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < 4 ; ++ V_65 )
F_3 ( V_2 , V_65 * V_10 + V_12 , 0 ) ;
}
static int F_102 ( struct V_132 * V_133 )
{
struct V_1 * V_2 ;
struct V_134 * V_135 ;
int V_58 ;
int V_100 ;
if ( ! V_133 -> V_15 . V_136 ) {
F_75 ( & V_133 -> V_15 , L_12 ) ;
return - V_101 ;
}
V_2 = F_103 ( & V_133 -> V_15 , sizeof( * V_2 ) , V_109 ) ;
if ( ! V_2 ) {
F_75 ( & V_133 -> V_15 , L_13 ) ;
return - V_92 ;
}
V_2 -> V_15 = & V_133 -> V_15 ;
V_2 -> V_119 = V_133 -> V_15 . V_136 ;
V_2 -> V_127 = 32 ;
V_135 = F_104 ( V_133 , V_137 , 0 ) ;
V_2 -> V_4 = F_105 ( & V_133 -> V_15 , V_135 ) ;
if ( F_92 ( V_2 -> V_4 ) )
return F_93 ( V_2 -> V_4 ) ;
V_58 = F_106 ( V_133 , 0 ) ;
if ( V_58 < 0 ) {
F_75 ( & V_133 -> V_15 , L_14 ) ;
return V_58 ;
}
V_100 = F_107 ( & V_133 -> V_15 , V_58 , F_26 , 0 ,
F_76 ( & V_133 -> V_15 ) , V_2 ) ;
if ( V_100 < 0 ) {
F_75 ( & V_133 -> V_15 , L_15 , V_58 ) ;
return V_58 ;
}
F_101 ( V_2 ) ;
F_88 ( & V_126 ) ;
F_108 ( & V_2 -> V_138 , & V_139 ) ;
F_90 ( & V_126 ) ;
F_109 ( V_133 , V_2 ) ;
return 0 ;
}
static int F_110 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = F_111 ( V_133 ) ;
F_88 ( & V_126 ) ;
F_112 ( & V_2 -> V_138 ) ;
F_90 ( & V_126 ) ;
F_113 ( V_2 -> V_60 ) ;
F_101 ( V_2 ) ;
return 0 ;
}
static int T_14 F_114 ( void )
{
int V_100 ;
V_100 = F_115 ( & V_140 ) ;
if ( V_100 < 0 )
return V_100 ;
if ( ! F_116 ( & V_129 ) )
F_117 ( & V_129 , & V_141 ) ;
return 0 ;
}
static void T_15 F_118 ( void )
{
return F_119 ( & V_140 ) ;
}
