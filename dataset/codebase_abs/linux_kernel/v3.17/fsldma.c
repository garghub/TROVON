static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , & V_2 -> V_4 -> V_5 , V_3 , 32 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , & V_2 -> V_4 -> V_5 , 32 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , & V_2 -> V_4 -> V_6 , V_3 , 32 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , & V_2 -> V_4 -> V_6 , 32 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_7 )
{
F_2 ( V_2 , & V_2 -> V_4 -> V_8 , V_7 | V_9 , 64 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , & V_2 -> V_4 -> V_8 , 64 ) & ~ V_9 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , & V_2 -> V_4 -> V_10 , V_3 , 32 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , & V_2 -> V_4 -> V_10 , 32 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_1 V_13 )
{
V_12 -> V_13 = F_12 ( V_2 , V_13 , 32 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_2 V_14 )
{
T_3 V_15 ;
V_15 = ( ( V_2 -> V_16 & V_17 ) == V_18 )
? ( ( T_3 ) V_19 << 32 ) : 0 ;
V_12 -> V_20 = F_12 ( V_2 , V_15 | V_14 , 64 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_2 V_21 )
{
T_3 V_15 ;
V_15 = ( ( V_2 -> V_16 & V_17 ) == V_18 )
? ( ( T_3 ) V_22 << 32 ) : 0 ;
V_12 -> V_23 = F_12 ( V_2 , V_15 | V_21 , 64 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_2 V_24 )
{
T_3 V_15 ;
V_15 = ( ( V_2 -> V_16 & V_17 ) == V_25 )
? V_9 : 0 ;
V_12 -> V_26 = F_12 ( V_2 , V_15 | V_24 , 64 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
T_3 V_15 ;
V_15 = ( ( V_2 -> V_16 & V_17 ) == V_25 )
? V_9 : 0 ;
V_28 -> V_12 . V_26 = F_12 ( V_2 ,
F_17 ( V_2 , V_28 -> V_12 . V_26 , 64 ) | V_29
| V_15 , 64 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 ) ;
switch ( V_2 -> V_16 & V_17 ) {
case V_18 :
F_5 ( V_2 , V_30 | V_31
| V_32 ) ;
break;
case V_25 :
F_5 ( V_2 , V_33 | V_34 ) ;
break;
}
}
static int F_19 ( struct V_1 * V_2 )
{
T_1 V_5 = F_3 ( V_2 ) ;
return ( ! ( V_5 & V_35 ) ) || ( V_5 & V_36 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_37 ;
V_37 = F_6 ( V_2 ) ;
if ( V_2 -> V_16 & V_38 ) {
F_9 ( V_2 , 0 ) ;
V_37 |= V_39 ;
} else {
V_37 &= ~ V_39 ;
}
if ( V_2 -> V_16 & V_40 ) {
V_37 |= V_41 ;
} else {
V_37 &= ~ V_41 ;
V_37 |= V_42 ;
}
F_5 ( V_2 , V_37 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_37 ;
int V_43 ;
V_37 = F_6 ( V_2 ) ;
if ( ( V_2 -> V_16 & V_17 ) == V_18 ) {
V_37 |= V_44 ;
F_5 ( V_2 , V_37 ) ;
V_37 &= ~ V_44 ;
}
V_37 &= ~ ( V_42 | V_41 ) ;
F_5 ( V_2 , V_37 ) ;
for ( V_43 = 0 ; V_43 < 100 ; V_43 ++ ) {
if ( F_19 ( V_2 ) )
return;
F_22 ( 10 ) ;
}
if ( ! F_19 ( V_2 ) )
F_23 ( V_2 , L_1 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_45 )
{
T_1 V_37 ;
V_37 = F_6 ( V_2 ) ;
switch ( V_45 ) {
case 0 :
V_37 &= ~ V_46 ;
break;
case 1 :
case 2 :
case 4 :
case 8 :
V_37 |= V_46 | ( F_25 ( V_45 ) << 14 ) ;
break;
}
F_5 ( V_2 , V_37 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_45 )
{
T_1 V_37 ;
V_37 = F_6 ( V_2 ) ;
switch ( V_45 ) {
case 0 :
V_37 &= ~ V_47 ;
break;
case 1 :
case 2 :
case 4 :
case 8 :
V_37 |= V_47 | ( F_25 ( V_45 ) << 16 ) ;
break;
}
F_5 ( V_2 , V_37 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_45 )
{
T_1 V_37 ;
F_28 ( V_45 > 1024 ) ;
V_37 = F_6 ( V_2 ) ;
V_37 |= ( F_25 ( V_45 ) << 24 ) & 0x0f000000 ;
F_5 ( V_2 , V_37 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_48 )
{
if ( V_48 )
V_2 -> V_16 |= V_38 ;
else
V_2 -> V_16 &= ~ V_38 ;
}
static void F_30 ( struct V_1 * V_2 , int V_48 )
{
if ( V_48 )
V_2 -> V_16 |= V_40 ;
else
V_2 -> V_16 &= ~ V_40 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_27 * V_49 = F_32 ( V_2 -> V_50 . V_51 ) ;
if ( F_33 ( & V_2 -> V_50 ) )
goto V_52;
F_15 ( V_2 , & V_49 -> V_12 , V_28 -> V_53 . V_54 ) ;
V_52:
F_34 ( & V_28 -> V_55 , & V_2 -> V_50 ) ;
}
static T_4 F_35 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_36 ( V_57 -> V_2 ) ;
struct V_27 * V_28 = F_37 ( V_57 ) ;
struct V_27 * V_58 ;
T_4 V_59 = - V_60 ;
F_38 ( & V_2 -> V_61 ) ;
#ifdef F_39
if ( F_40 ( V_2 -> V_62 != V_63 ) ) {
F_41 ( V_2 , L_2 ) ;
F_42 ( & V_2 -> V_61 ) ;
return - 1 ;
}
#endif
F_43 (child, &desc->tx_list, node) {
V_59 = F_44 ( & V_58 -> V_53 ) ;
}
F_31 ( V_2 , V_28 ) ;
F_42 ( & V_2 -> V_61 ) ;
return V_59 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_46 ( & V_28 -> V_64 ) ;
F_41 ( V_2 , L_3 , V_28 ) ;
F_47 ( V_2 -> V_65 , V_28 , V_28 -> V_53 . V_54 ) ;
}
static struct V_27 * F_48 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
T_2 V_66 ;
V_28 = F_49 ( V_2 -> V_65 , V_67 , & V_66 ) ;
if ( ! V_28 ) {
F_41 ( V_2 , L_4 ) ;
return NULL ;
}
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
F_50 ( & V_28 -> V_55 ) ;
F_51 ( & V_28 -> V_53 , & V_2 -> V_68 ) ;
V_28 -> V_53 . V_69 = F_35 ;
V_28 -> V_53 . V_54 = V_66 ;
F_41 ( V_2 , L_5 , V_28 ) ;
return V_28 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_27 * V_28 , * V_70 ;
F_53 (desc, _desc, &chan->ld_completed, node)
if ( F_54 ( & V_28 -> V_53 ) )
F_45 ( V_2 , V_28 ) ;
}
static T_4 F_55 ( struct V_1 * V_2 ,
struct V_27 * V_28 , T_4 V_59 )
{
struct V_56 * V_71 = & V_28 -> V_53 ;
T_4 V_72 = V_59 ;
F_28 ( V_71 -> V_59 < 0 ) ;
if ( V_71 -> V_59 > 0 ) {
V_72 = V_71 -> V_59 ;
if ( V_71 -> V_73 ) {
F_41 ( V_2 , L_6 , V_28 ) ;
V_71 -> V_73 ( V_71 -> V_74 ) ;
}
}
F_56 ( V_71 ) ;
return V_72 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_46 ( & V_28 -> V_64 ) ;
if ( ! F_54 ( & V_28 -> V_53 ) ) {
F_58 ( & V_28 -> V_64 , & V_2 -> V_75 ) ;
return;
}
F_47 ( V_2 -> V_65 , V_28 , V_28 -> V_53 . V_54 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
if ( F_33 ( & V_2 -> V_50 ) ) {
F_41 ( V_2 , L_7 ) ;
return;
}
if ( ! V_2 -> V_76 ) {
F_41 ( V_2 , L_8 ) ;
return;
}
F_41 ( V_2 , L_9 ) ;
V_28 = F_60 ( & V_2 -> V_50 , struct V_27 , V_64 ) ;
F_34 ( & V_2 -> V_50 , & V_2 -> V_77 ) ;
if ( ( V_2 -> V_16 & V_17 ) == V_18 ) {
T_1 V_37 ;
V_37 = F_6 ( V_2 ) ;
V_37 &= ~ V_42 ;
F_5 ( V_2 , V_37 ) ;
}
F_7 ( V_2 , V_28 -> V_53 . V_54 ) ;
F_8 ( V_2 ) ;
F_20 ( V_2 ) ;
V_2 -> V_76 = false ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_27 * V_28 , * V_70 ;
T_4 V_59 = 0 ;
T_2 V_78 = F_8 ( V_2 ) ;
int V_79 = 0 ;
F_52 ( V_2 ) ;
F_53 (desc, _desc, &chan->ld_running, node) {
if ( V_79 )
break;
if ( V_28 -> V_53 . V_54 == V_78 ) {
V_79 = 1 ;
if ( ! F_19 ( V_2 ) )
break;
}
V_59 = F_55 ( V_2 , V_28 , V_59 ) ;
F_57 ( V_2 , V_28 ) ;
}
F_59 ( V_2 ) ;
if ( V_59 > 0 )
V_2 -> V_68 . V_80 = V_59 ;
}
static int F_62 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_36 ( V_82 ) ;
if ( V_2 -> V_65 )
return 1 ;
V_2 -> V_65 = F_63 ( V_2 -> V_83 , V_2 -> V_84 ,
sizeof( struct V_27 ) ,
F_64 ( struct V_27 ) , 0 ) ;
if ( ! V_2 -> V_65 ) {
F_23 ( V_2 , L_10 ) ;
return - V_85 ;
}
return 1 ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_27 * V_28 , * V_70 ;
F_53 (desc, _desc, list, node)
F_45 ( V_2 , V_28 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_27 * V_28 , * V_70 ;
F_67 (desc, _desc, list, node)
F_45 ( V_2 , V_28 ) ;
}
static void F_68 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_36 ( V_82 ) ;
F_41 ( V_2 , L_11 ) ;
F_38 ( & V_2 -> V_61 ) ;
F_61 ( V_2 ) ;
F_65 ( V_2 , & V_2 -> V_50 ) ;
F_65 ( V_2 , & V_2 -> V_77 ) ;
F_65 ( V_2 , & V_2 -> V_75 ) ;
F_42 ( & V_2 -> V_61 ) ;
F_69 ( V_2 -> V_65 ) ;
V_2 -> V_65 = NULL ;
}
static struct V_56 *
F_70 ( struct V_81 * V_82 ,
T_2 V_88 , T_2 V_89 ,
T_5 V_90 , unsigned long V_91 )
{
struct V_1 * V_2 ;
struct V_27 * V_92 = NULL , * V_51 = NULL , * V_93 ;
T_5 V_94 ;
if ( ! V_82 )
return NULL ;
if ( ! V_90 )
return NULL ;
V_2 = F_36 ( V_82 ) ;
do {
V_93 = F_48 ( V_2 ) ;
if ( ! V_93 ) {
F_23 ( V_2 , L_12 , V_95 ) ;
goto V_96;
}
V_94 = F_71 ( V_90 , ( T_5 ) V_97 ) ;
F_11 ( V_2 , & V_93 -> V_12 , V_94 ) ;
F_13 ( V_2 , & V_93 -> V_12 , V_89 ) ;
F_14 ( V_2 , & V_93 -> V_12 , V_88 ) ;
if ( ! V_92 )
V_92 = V_93 ;
else
F_15 ( V_2 , & V_51 -> V_12 , V_93 -> V_53 . V_54 ) ;
V_93 -> V_53 . V_59 = 0 ;
F_72 ( & V_93 -> V_53 ) ;
V_51 = V_93 ;
V_90 -= V_94 ;
V_89 += V_94 ;
V_88 += V_94 ;
F_58 ( & V_93 -> V_64 , & V_92 -> V_55 ) ;
} while ( V_90 );
V_93 -> V_53 . V_91 = V_91 ;
V_93 -> V_53 . V_59 = - V_98 ;
F_16 ( V_2 , V_93 ) ;
return & V_92 -> V_53 ;
V_96:
if ( ! V_92 )
return NULL ;
F_66 ( V_2 , & V_92 -> V_55 ) ;
return NULL ;
}
static struct V_56 * F_73 ( struct V_81 * V_82 ,
struct V_99 * V_100 , unsigned int V_101 ,
struct V_99 * V_102 , unsigned int V_103 ,
unsigned long V_91 )
{
struct V_27 * V_92 = NULL , * V_51 = NULL , * V_93 = NULL ;
struct V_1 * V_2 = F_36 ( V_82 ) ;
T_5 V_104 , V_105 ;
T_2 V_21 , V_14 ;
T_5 V_90 ;
if ( V_101 == 0 || V_103 == 0 )
return NULL ;
if ( V_100 == NULL || V_102 == NULL )
return NULL ;
V_104 = F_74 ( V_100 ) ;
V_105 = F_74 ( V_102 ) ;
while ( true ) {
V_90 = F_75 ( T_5 , V_105 , V_104 ) ;
V_90 = F_75 ( T_5 , V_90 , V_97 ) ;
if ( V_90 == 0 )
goto V_106;
V_21 = F_76 ( V_100 ) + F_74 ( V_100 ) - V_104 ;
V_14 = F_76 ( V_102 ) + F_74 ( V_102 ) - V_105 ;
V_93 = F_48 ( V_2 ) ;
if ( ! V_93 ) {
F_23 ( V_2 , L_12 , V_95 ) ;
goto V_96;
}
F_11 ( V_2 , & V_93 -> V_12 , V_90 ) ;
F_13 ( V_2 , & V_93 -> V_12 , V_14 ) ;
F_14 ( V_2 , & V_93 -> V_12 , V_21 ) ;
if ( ! V_92 )
V_92 = V_93 ;
else
F_15 ( V_2 , & V_51 -> V_12 , V_93 -> V_53 . V_54 ) ;
V_93 -> V_53 . V_59 = 0 ;
F_72 ( & V_93 -> V_53 ) ;
V_51 = V_93 ;
F_58 ( & V_93 -> V_64 , & V_92 -> V_55 ) ;
V_104 -= V_90 ;
V_105 -= V_90 ;
V_106:
if ( V_104 == 0 ) {
if ( V_101 == 0 )
break;
V_100 = F_77 ( V_100 ) ;
if ( V_100 == NULL )
break;
V_101 -- ;
V_104 = F_74 ( V_100 ) ;
}
if ( V_105 == 0 ) {
if ( V_103 == 0 )
break;
V_102 = F_77 ( V_102 ) ;
if ( V_102 == NULL )
break;
V_103 -- ;
V_105 = F_74 ( V_102 ) ;
}
}
V_93 -> V_53 . V_91 = V_91 ;
V_93 -> V_53 . V_59 = - V_98 ;
F_16 ( V_2 , V_93 ) ;
return & V_92 -> V_53 ;
V_96:
if ( ! V_92 )
return NULL ;
F_66 ( V_2 , & V_92 -> V_55 ) ;
return NULL ;
}
static struct V_56 * F_78 (
struct V_81 * V_82 , struct V_99 * V_107 , unsigned int V_108 ,
enum V_109 V_110 , unsigned long V_91 ,
void * V_111 )
{
return NULL ;
}
static int F_79 ( struct V_81 * V_82 ,
enum V_112 V_113 , unsigned long V_114 )
{
struct V_115 * V_116 ;
struct V_1 * V_2 ;
int V_45 ;
if ( ! V_82 )
return - V_60 ;
V_2 = F_36 ( V_82 ) ;
switch ( V_113 ) {
case V_117 :
F_38 ( & V_2 -> V_61 ) ;
F_21 ( V_2 ) ;
F_65 ( V_2 , & V_2 -> V_50 ) ;
F_65 ( V_2 , & V_2 -> V_77 ) ;
F_65 ( V_2 , & V_2 -> V_75 ) ;
V_2 -> V_76 = true ;
F_42 ( & V_2 -> V_61 ) ;
return 0 ;
case V_118 :
V_116 = (struct V_115 * ) V_114 ;
if ( ! V_2 -> V_119 )
return - V_120 ;
if ( V_116 -> V_110 == V_121 )
V_45 = V_116 -> V_122 * V_116 -> V_123 ;
else
V_45 = V_116 -> V_124 * V_116 -> V_125 ;
V_2 -> V_119 ( V_2 , V_45 ) ;
return 0 ;
case V_126 :
if ( ! V_2 -> V_127 )
return - V_120 ;
V_2 -> V_127 ( V_2 , V_114 ) ;
return 0 ;
default:
return - V_120 ;
}
return 0 ;
}
static void F_80 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_36 ( V_82 ) ;
F_38 ( & V_2 -> V_61 ) ;
F_59 ( V_2 ) ;
F_42 ( & V_2 -> V_61 ) ;
}
static enum V_128 F_81 ( struct V_81 * V_82 ,
T_4 V_59 ,
struct V_129 * V_130 )
{
struct V_1 * V_2 = F_36 ( V_82 ) ;
enum V_128 V_72 ;
V_72 = F_82 ( V_82 , V_59 , V_130 ) ;
if ( V_72 == V_131 )
return V_72 ;
F_38 ( & V_2 -> V_61 ) ;
F_61 ( V_2 ) ;
F_42 ( & V_2 -> V_61 ) ;
return F_82 ( V_82 , V_59 , V_130 ) ;
}
static T_6 F_83 ( int V_132 , void * V_133 )
{
struct V_1 * V_2 = V_133 ;
T_1 V_134 ;
V_134 = F_3 ( V_2 ) ;
F_1 ( V_2 , V_134 ) ;
F_41 ( V_2 , L_13 , V_134 ) ;
V_134 &= ~ ( V_35 | V_36 ) ;
if ( ! V_134 )
return V_135 ;
if ( V_134 & V_136 )
F_23 ( V_2 , L_14 ) ;
if ( V_134 & V_137 ) {
F_41 ( V_2 , L_15 ) ;
V_134 &= ~ V_137 ;
if ( F_10 ( V_2 ) != 0 )
F_23 ( V_2 , L_16 ) ;
}
if ( V_134 & V_138 ) {
F_41 ( V_2 , L_17 ) ;
V_134 &= ~ V_138 ;
}
if ( V_134 & V_139 ) {
F_41 ( V_2 , L_18 ) ;
V_134 &= ~ V_139 ;
}
if ( ! F_19 ( V_2 ) )
F_23 ( V_2 , L_19 ) ;
if ( V_134 )
F_23 ( V_2 , L_20 , V_134 ) ;
F_84 ( & V_2 -> V_140 ) ;
F_41 ( V_2 , L_21 ) ;
return V_141 ;
}
static void F_85 ( unsigned long V_133 )
{
struct V_1 * V_2 = (struct V_1 * ) V_133 ;
F_41 ( V_2 , L_22 ) ;
F_38 ( & V_2 -> V_61 ) ;
V_2 -> V_76 = true ;
F_61 ( V_2 ) ;
F_42 ( & V_2 -> V_61 ) ;
F_41 ( V_2 , L_23 ) ;
}
static T_6 F_86 ( int V_132 , void * V_133 )
{
struct V_142 * V_143 = V_133 ;
struct V_1 * V_2 ;
unsigned int V_144 = 0 ;
T_1 V_145 , V_146 ;
int V_43 ;
V_145 = ( V_143 -> V_16 & V_147 ) ? F_87 ( V_143 -> V_4 )
: F_88 ( V_143 -> V_4 ) ;
V_146 = 0xff000000 ;
F_89 ( V_143 -> V_84 , L_24 , V_145 ) ;
for ( V_43 = 0 ; V_43 < V_148 ; V_43 ++ ) {
V_2 = V_143 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_145 & V_146 ) {
F_89 ( V_143 -> V_84 , L_25 , V_2 -> V_149 ) ;
F_83 ( V_132 , V_2 ) ;
V_144 ++ ;
}
V_145 &= ~ V_146 ;
V_146 >>= 8 ;
}
return F_90 ( V_144 ) ;
}
static void F_91 ( struct V_142 * V_143 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_143 -> V_132 != V_150 ) {
F_89 ( V_143 -> V_84 , L_26 ) ;
F_92 ( V_143 -> V_132 , V_143 ) ;
return;
}
for ( V_43 = 0 ; V_43 < V_148 ; V_43 ++ ) {
V_2 = V_143 -> V_2 [ V_43 ] ;
if ( V_2 && V_2 -> V_132 != V_150 ) {
F_41 ( V_2 , L_27 ) ;
F_92 ( V_2 -> V_132 , V_2 ) ;
}
}
}
static int F_93 ( struct V_142 * V_143 )
{
struct V_1 * V_2 ;
int V_72 ;
int V_43 ;
if ( V_143 -> V_132 != V_150 ) {
F_89 ( V_143 -> V_84 , L_28 ) ;
V_72 = F_94 ( V_143 -> V_132 , F_86 , V_151 ,
L_29 , V_143 ) ;
return V_72 ;
}
for ( V_43 = 0 ; V_43 < V_148 ; V_43 ++ ) {
V_2 = V_143 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_132 == V_150 ) {
F_23 ( V_2 , L_30 ) ;
V_72 = - V_152 ;
goto V_153;
}
F_41 ( V_2 , L_31 ) ;
V_72 = F_94 ( V_2 -> V_132 , F_83 , V_151 ,
L_32 , V_2 ) ;
if ( V_72 ) {
F_23 ( V_2 , L_33 ) ;
goto V_153;
}
}
return 0 ;
V_153:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_143 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_132 == V_150 )
continue;
F_92 ( V_2 -> V_132 , V_2 ) ;
}
return V_72 ;
}
static int F_95 ( struct V_142 * V_143 ,
struct V_154 * V_64 , T_1 V_16 , const char * V_155 )
{
struct V_1 * V_2 ;
struct V_156 V_157 ;
int V_158 ;
V_2 = F_96 ( sizeof( * V_2 ) , V_159 ) ;
if ( ! V_2 ) {
F_97 ( V_143 -> V_84 , L_34 ) ;
V_158 = - V_85 ;
goto V_160;
}
V_2 -> V_4 = F_98 ( V_64 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_97 ( V_143 -> V_84 , L_35 ) ;
V_158 = - V_85 ;
goto V_161;
}
V_158 = F_99 ( V_64 , 0 , & V_157 ) ;
if ( V_158 ) {
F_97 ( V_143 -> V_84 , L_36 ) ;
goto V_162;
}
V_2 -> V_16 = V_16 ;
if ( ! V_143 -> V_16 )
V_143 -> V_16 = V_2 -> V_16 ;
F_100 ( V_143 -> V_16 != V_2 -> V_16 ) ;
V_2 -> V_84 = V_143 -> V_84 ;
V_2 -> V_149 = ( V_157 . V_163 & 0xfff ) < 0x300 ?
( ( V_157 . V_163 - 0x100 ) & 0xfff ) >> 7 :
( ( V_157 . V_163 - 0x200 ) & 0xfff ) >> 7 ;
if ( V_2 -> V_149 >= V_148 ) {
F_97 ( V_143 -> V_84 , L_37 ) ;
V_158 = - V_60 ;
goto V_162;
}
V_143 -> V_2 [ V_2 -> V_149 ] = V_2 ;
F_101 ( & V_2 -> V_140 , F_85 , ( unsigned long ) V_2 ) ;
snprintf ( V_2 -> V_83 , sizeof( V_2 -> V_83 ) , L_38 , V_2 -> V_149 ) ;
F_18 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
switch ( V_2 -> V_16 & V_17 ) {
case V_18 :
V_2 -> V_164 = F_29 ;
case V_25 :
V_2 -> V_127 = F_30 ;
V_2 -> V_165 = F_24 ;
V_2 -> V_166 = F_26 ;
V_2 -> V_119 = F_27 ;
}
F_102 ( & V_2 -> V_61 ) ;
F_50 ( & V_2 -> V_50 ) ;
F_50 ( & V_2 -> V_77 ) ;
F_50 ( & V_2 -> V_75 ) ;
V_2 -> V_76 = true ;
#ifdef F_39
V_2 -> V_62 = V_63 ;
#endif
V_2 -> V_68 . V_167 = & V_143 -> V_68 ;
F_103 ( & V_2 -> V_68 ) ;
V_2 -> V_132 = F_104 ( V_64 , 0 ) ;
F_58 ( & V_2 -> V_68 . V_154 , & V_143 -> V_68 . V_168 ) ;
V_143 -> V_68 . V_169 ++ ;
F_105 ( V_143 -> V_84 , L_39 , V_2 -> V_149 , V_155 ,
V_2 -> V_132 != V_150 ? V_2 -> V_132 : V_143 -> V_132 ) ;
return 0 ;
V_162:
F_106 ( V_2 -> V_4 ) ;
V_161:
F_107 ( V_2 ) ;
V_160:
return V_158 ;
}
static void F_108 ( struct V_1 * V_2 )
{
F_109 ( V_2 -> V_132 ) ;
F_46 ( & V_2 -> V_68 . V_154 ) ;
F_106 ( V_2 -> V_4 ) ;
F_107 ( V_2 ) ;
}
static int F_110 ( struct V_170 * V_171 )
{
struct V_142 * V_143 ;
struct V_154 * V_58 ;
int V_158 ;
V_143 = F_96 ( sizeof( * V_143 ) , V_159 ) ;
if ( ! V_143 ) {
F_97 ( & V_171 -> V_84 , L_40 ) ;
V_158 = - V_85 ;
goto V_160;
}
V_143 -> V_84 = & V_171 -> V_84 ;
F_50 ( & V_143 -> V_68 . V_168 ) ;
V_143 -> V_4 = F_98 ( V_171 -> V_84 . V_172 , 0 ) ;
if ( ! V_143 -> V_4 ) {
F_97 ( & V_171 -> V_84 , L_35 ) ;
V_158 = - V_85 ;
goto V_173;
}
V_143 -> V_132 = F_104 ( V_171 -> V_84 . V_172 , 0 ) ;
F_111 ( V_174 , V_143 -> V_68 . V_175 ) ;
F_111 ( V_176 , V_143 -> V_68 . V_175 ) ;
F_111 ( V_177 , V_143 -> V_68 . V_175 ) ;
V_143 -> V_68 . V_178 = F_62 ;
V_143 -> V_68 . V_179 = F_68 ;
V_143 -> V_68 . V_180 = F_70 ;
V_143 -> V_68 . V_181 = F_73 ;
V_143 -> V_68 . V_182 = F_81 ;
V_143 -> V_68 . V_183 = F_80 ;
V_143 -> V_68 . V_184 = F_78 ;
V_143 -> V_68 . V_185 = F_79 ;
V_143 -> V_68 . V_84 = & V_171 -> V_84 ;
F_112 ( & ( V_171 -> V_84 ) , F_113 ( 36 ) ) ;
F_114 ( V_171 , V_143 ) ;
F_115 (op->dev.of_node, child) {
if ( F_116 ( V_58 , L_41 ) ) {
F_95 ( V_143 , V_58 ,
V_18 | V_147 ,
L_41 ) ;
}
if ( F_116 ( V_58 , L_42 ) ) {
F_95 ( V_143 , V_58 ,
V_25 | V_186 ,
L_42 ) ;
}
}
V_158 = F_93 ( V_143 ) ;
if ( V_158 ) {
F_97 ( V_143 -> V_84 , L_43 ) ;
goto V_173;
}
F_117 ( & V_143 -> V_68 ) ;
return 0 ;
V_173:
F_109 ( V_143 -> V_132 ) ;
F_107 ( V_143 ) ;
V_160:
return V_158 ;
}
static int F_118 ( struct V_170 * V_171 )
{
struct V_142 * V_143 ;
unsigned int V_43 ;
V_143 = F_119 ( V_171 ) ;
F_120 ( & V_143 -> V_68 ) ;
F_91 ( V_143 ) ;
for ( V_43 = 0 ; V_43 < V_148 ; V_43 ++ ) {
if ( V_143 -> V_2 [ V_43 ] )
F_108 ( V_143 -> V_2 [ V_43 ] ) ;
}
F_106 ( V_143 -> V_4 ) ;
F_107 ( V_143 ) ;
return 0 ;
}
static int F_121 ( struct V_167 * V_84 )
{
struct V_170 * V_187 = F_122 ( V_84 ) ;
struct V_142 * V_143 = F_119 ( V_187 ) ;
struct V_1 * V_2 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_148 ; V_43 ++ ) {
V_2 = V_143 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
F_38 ( & V_2 -> V_61 ) ;
if ( F_40 ( ! V_2 -> V_76 ) )
goto V_188;
V_2 -> V_189 . V_6 = F_6 ( V_2 ) ;
V_2 -> V_62 = V_190 ;
F_42 ( & V_2 -> V_61 ) ;
}
return 0 ;
V_188:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_143 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
V_2 -> V_62 = V_63 ;
F_42 ( & V_2 -> V_61 ) ;
}
return - V_98 ;
}
static int F_123 ( struct V_167 * V_84 )
{
struct V_170 * V_187 = F_122 ( V_84 ) ;
struct V_142 * V_143 = F_119 ( V_187 ) ;
struct V_1 * V_2 ;
T_1 V_37 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_148 ; V_43 ++ ) {
V_2 = V_143 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
F_38 ( & V_2 -> V_61 ) ;
V_37 = V_2 -> V_189 . V_6
& ~ V_42 & ~ V_191 & ~ V_44 ;
F_5 ( V_2 , V_37 ) ;
V_2 -> V_62 = V_63 ;
F_42 ( & V_2 -> V_61 ) ;
}
return 0 ;
}
static T_7 int F_124 ( void )
{
F_125 ( L_44 ) ;
return F_126 ( & V_192 ) ;
}
static void T_8 F_127 ( void )
{
F_128 ( & V_192 ) ;
}
