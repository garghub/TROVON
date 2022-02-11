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
int F_31 ( struct V_49 * V_50 , int V_48 )
{
struct V_1 * V_2 ;
if ( ! V_50 )
return - V_51 ;
V_2 = F_32 ( V_50 ) ;
F_30 ( V_2 , V_48 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_27 * V_52 = F_34 ( V_2 -> V_53 . V_54 ) ;
if ( F_35 ( & V_2 -> V_53 ) )
goto V_55;
F_15 ( V_2 , & V_52 -> V_12 , V_28 -> V_56 . V_57 ) ;
V_55:
F_36 ( & V_28 -> V_58 , & V_2 -> V_53 ) ;
}
static T_4 F_37 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_32 ( V_60 -> V_2 ) ;
struct V_27 * V_28 = F_38 ( V_60 ) ;
struct V_27 * V_61 ;
T_4 V_62 = - V_51 ;
F_39 ( & V_2 -> V_63 ) ;
#ifdef F_40
if ( F_41 ( V_2 -> V_64 != V_65 ) ) {
F_42 ( V_2 , L_2 ) ;
F_43 ( & V_2 -> V_63 ) ;
return - 1 ;
}
#endif
F_44 (child, &desc->tx_list, node) {
V_62 = F_45 ( & V_61 -> V_56 ) ;
}
F_33 ( V_2 , V_28 ) ;
F_43 ( & V_2 -> V_63 ) ;
return V_62 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_47 ( & V_28 -> V_66 ) ;
F_42 ( V_2 , L_3 , V_28 ) ;
F_48 ( V_2 -> V_67 , V_28 , V_28 -> V_56 . V_57 ) ;
}
static struct V_27 * F_49 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
T_2 V_68 ;
V_28 = F_50 ( V_2 -> V_67 , V_69 , & V_68 ) ;
if ( ! V_28 ) {
F_42 ( V_2 , L_4 ) ;
return NULL ;
}
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
F_51 ( & V_28 -> V_58 ) ;
F_52 ( & V_28 -> V_56 , & V_2 -> V_70 ) ;
V_28 -> V_56 . V_71 = F_37 ;
V_28 -> V_56 . V_57 = V_68 ;
F_42 ( V_2 , L_5 , V_28 ) ;
return V_28 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_27 * V_28 , * V_72 ;
F_54 (desc, _desc, &chan->ld_completed, node)
if ( F_55 ( & V_28 -> V_56 ) )
F_46 ( V_2 , V_28 ) ;
}
static T_4 F_56 ( struct V_1 * V_2 ,
struct V_27 * V_28 , T_4 V_62 )
{
struct V_59 * V_73 = & V_28 -> V_56 ;
T_4 V_74 = V_62 ;
F_28 ( V_73 -> V_62 < 0 ) ;
if ( V_73 -> V_62 > 0 ) {
V_74 = V_73 -> V_62 ;
if ( V_73 -> V_75 ) {
F_42 ( V_2 , L_6 , V_28 ) ;
V_73 -> V_75 ( V_73 -> V_76 ) ;
}
}
F_57 ( V_73 ) ;
return V_74 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_47 ( & V_28 -> V_66 ) ;
if ( ! F_55 ( & V_28 -> V_56 ) ) {
F_59 ( & V_28 -> V_66 , & V_2 -> V_77 ) ;
return;
}
F_48 ( V_2 -> V_67 , V_28 , V_28 -> V_56 . V_57 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
if ( F_35 ( & V_2 -> V_53 ) ) {
F_42 ( V_2 , L_7 ) ;
return;
}
if ( ! V_2 -> V_78 ) {
F_42 ( V_2 , L_8 ) ;
return;
}
F_42 ( V_2 , L_9 ) ;
V_28 = F_61 ( & V_2 -> V_53 , struct V_27 , V_66 ) ;
F_36 ( & V_2 -> V_53 , & V_2 -> V_79 ) ;
if ( ( V_2 -> V_16 & V_17 ) == V_18 ) {
T_1 V_37 ;
V_37 = F_6 ( V_2 ) ;
V_37 &= ~ V_42 ;
F_5 ( V_2 , V_37 ) ;
}
F_7 ( V_2 , V_28 -> V_56 . V_57 ) ;
F_8 ( V_2 ) ;
F_20 ( V_2 ) ;
V_2 -> V_78 = false ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_27 * V_28 , * V_72 ;
T_4 V_62 = 0 ;
T_2 V_80 = F_8 ( V_2 ) ;
int V_81 = 0 ;
F_53 ( V_2 ) ;
F_54 (desc, _desc, &chan->ld_running, node) {
if ( V_81 )
break;
if ( V_28 -> V_56 . V_57 == V_80 ) {
V_81 = 1 ;
if ( ! F_19 ( V_2 ) )
break;
}
V_62 = F_56 ( V_2 , V_28 , V_62 ) ;
F_58 ( V_2 , V_28 ) ;
}
F_60 ( V_2 ) ;
if ( V_62 > 0 )
V_2 -> V_70 . V_82 = V_62 ;
}
static int F_63 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
if ( V_2 -> V_67 )
return 1 ;
V_2 -> V_67 = F_64 ( V_2 -> V_83 , V_2 -> V_84 ,
sizeof( struct V_27 ) ,
F_65 ( struct V_27 ) , 0 ) ;
if ( ! V_2 -> V_67 ) {
F_23 ( V_2 , L_10 ) ;
return - V_85 ;
}
return 1 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_27 * V_28 , * V_72 ;
F_54 (desc, _desc, list, node)
F_46 ( V_2 , V_28 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_27 * V_28 , * V_72 ;
F_68 (desc, _desc, list, node)
F_46 ( V_2 , V_28 ) ;
}
static void F_69 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
F_42 ( V_2 , L_11 ) ;
F_39 ( & V_2 -> V_63 ) ;
F_62 ( V_2 ) ;
F_66 ( V_2 , & V_2 -> V_53 ) ;
F_66 ( V_2 , & V_2 -> V_79 ) ;
F_66 ( V_2 , & V_2 -> V_77 ) ;
F_43 ( & V_2 -> V_63 ) ;
F_70 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
static struct V_59 *
F_71 ( struct V_49 * V_50 ,
T_2 V_88 , T_2 V_89 ,
T_5 V_90 , unsigned long V_91 )
{
struct V_1 * V_2 ;
struct V_27 * V_92 = NULL , * V_54 = NULL , * V_93 ;
T_5 V_94 ;
if ( ! V_50 )
return NULL ;
if ( ! V_90 )
return NULL ;
V_2 = F_32 ( V_50 ) ;
do {
V_93 = F_49 ( V_2 ) ;
if ( ! V_93 ) {
F_23 ( V_2 , L_12 , V_95 ) ;
goto V_96;
}
V_94 = F_72 ( V_90 , ( T_5 ) V_97 ) ;
F_11 ( V_2 , & V_93 -> V_12 , V_94 ) ;
F_13 ( V_2 , & V_93 -> V_12 , V_89 ) ;
F_14 ( V_2 , & V_93 -> V_12 , V_88 ) ;
if ( ! V_92 )
V_92 = V_93 ;
else
F_15 ( V_2 , & V_54 -> V_12 , V_93 -> V_56 . V_57 ) ;
V_93 -> V_56 . V_62 = 0 ;
F_73 ( & V_93 -> V_56 ) ;
V_54 = V_93 ;
V_90 -= V_94 ;
V_89 += V_94 ;
V_88 += V_94 ;
F_59 ( & V_93 -> V_66 , & V_92 -> V_58 ) ;
} while ( V_90 );
V_93 -> V_56 . V_91 = V_91 ;
V_93 -> V_56 . V_62 = - V_98 ;
F_16 ( V_2 , V_93 ) ;
return & V_92 -> V_56 ;
V_96:
if ( ! V_92 )
return NULL ;
F_67 ( V_2 , & V_92 -> V_58 ) ;
return NULL ;
}
static struct V_59 * F_74 ( struct V_49 * V_50 ,
struct V_99 * V_100 , unsigned int V_101 ,
struct V_99 * V_102 , unsigned int V_103 ,
unsigned long V_91 )
{
struct V_27 * V_92 = NULL , * V_54 = NULL , * V_93 = NULL ;
struct V_1 * V_2 = F_32 ( V_50 ) ;
T_5 V_104 , V_105 ;
T_2 V_21 , V_14 ;
T_5 V_90 ;
if ( V_101 == 0 || V_103 == 0 )
return NULL ;
if ( V_100 == NULL || V_102 == NULL )
return NULL ;
V_104 = F_75 ( V_100 ) ;
V_105 = F_75 ( V_102 ) ;
while ( true ) {
V_90 = F_76 ( T_5 , V_105 , V_104 ) ;
V_90 = F_76 ( T_5 , V_90 , V_97 ) ;
if ( V_90 == 0 )
goto V_106;
V_21 = F_77 ( V_100 ) + F_75 ( V_100 ) - V_104 ;
V_14 = F_77 ( V_102 ) + F_75 ( V_102 ) - V_105 ;
V_93 = F_49 ( V_2 ) ;
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
F_15 ( V_2 , & V_54 -> V_12 , V_93 -> V_56 . V_57 ) ;
V_93 -> V_56 . V_62 = 0 ;
F_73 ( & V_93 -> V_56 ) ;
V_54 = V_93 ;
F_59 ( & V_93 -> V_66 , & V_92 -> V_58 ) ;
V_104 -= V_90 ;
V_105 -= V_90 ;
V_106:
if ( V_104 == 0 ) {
if ( V_101 == 0 )
break;
V_100 = F_78 ( V_100 ) ;
if ( V_100 == NULL )
break;
V_101 -- ;
V_104 = F_75 ( V_100 ) ;
}
if ( V_105 == 0 ) {
if ( V_103 == 0 )
break;
V_102 = F_78 ( V_102 ) ;
if ( V_102 == NULL )
break;
V_103 -- ;
V_105 = F_75 ( V_102 ) ;
}
}
V_93 -> V_56 . V_91 = V_91 ;
V_93 -> V_56 . V_62 = - V_98 ;
F_16 ( V_2 , V_93 ) ;
return & V_92 -> V_56 ;
V_96:
if ( ! V_92 )
return NULL ;
F_67 ( V_2 , & V_92 -> V_58 ) ;
return NULL ;
}
static struct V_59 * F_79 (
struct V_49 * V_50 , struct V_99 * V_107 , unsigned int V_108 ,
enum V_109 V_110 , unsigned long V_91 ,
void * V_111 )
{
return NULL ;
}
static int F_80 ( struct V_49 * V_50 ,
enum V_112 V_113 , unsigned long V_114 )
{
struct V_115 * V_116 ;
struct V_1 * V_2 ;
int V_45 ;
if ( ! V_50 )
return - V_51 ;
V_2 = F_32 ( V_50 ) ;
switch ( V_113 ) {
case V_117 :
F_39 ( & V_2 -> V_63 ) ;
F_21 ( V_2 ) ;
F_66 ( V_2 , & V_2 -> V_53 ) ;
F_66 ( V_2 , & V_2 -> V_79 ) ;
F_66 ( V_2 , & V_2 -> V_77 ) ;
V_2 -> V_78 = true ;
F_43 ( & V_2 -> V_63 ) ;
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
default:
return - V_120 ;
}
return 0 ;
}
static void F_81 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
F_39 ( & V_2 -> V_63 ) ;
F_60 ( V_2 ) ;
F_43 ( & V_2 -> V_63 ) ;
}
static enum V_126 F_82 ( struct V_49 * V_50 ,
T_4 V_62 ,
struct V_127 * V_128 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
enum V_126 V_74 ;
V_74 = F_83 ( V_50 , V_62 , V_128 ) ;
if ( V_74 == V_129 )
return V_74 ;
F_39 ( & V_2 -> V_63 ) ;
F_62 ( V_2 ) ;
F_43 ( & V_2 -> V_63 ) ;
return F_83 ( V_50 , V_62 , V_128 ) ;
}
static T_6 F_84 ( int V_130 , void * V_131 )
{
struct V_1 * V_2 = V_131 ;
T_1 V_132 ;
V_132 = F_3 ( V_2 ) ;
F_1 ( V_2 , V_132 ) ;
F_42 ( V_2 , L_13 , V_132 ) ;
V_132 &= ~ ( V_35 | V_36 ) ;
if ( ! V_132 )
return V_133 ;
if ( V_132 & V_134 )
F_23 ( V_2 , L_14 ) ;
if ( V_132 & V_135 ) {
F_42 ( V_2 , L_15 ) ;
V_132 &= ~ V_135 ;
if ( F_10 ( V_2 ) != 0 )
F_23 ( V_2 , L_16 ) ;
}
if ( V_132 & V_136 ) {
F_42 ( V_2 , L_17 ) ;
V_132 &= ~ V_136 ;
}
if ( V_132 & V_137 ) {
F_42 ( V_2 , L_18 ) ;
V_132 &= ~ V_137 ;
}
if ( ! F_19 ( V_2 ) )
F_23 ( V_2 , L_19 ) ;
if ( V_132 )
F_23 ( V_2 , L_20 , V_132 ) ;
F_85 ( & V_2 -> V_138 ) ;
F_42 ( V_2 , L_21 ) ;
return V_139 ;
}
static void F_86 ( unsigned long V_131 )
{
struct V_1 * V_2 = (struct V_1 * ) V_131 ;
F_42 ( V_2 , L_22 ) ;
F_39 ( & V_2 -> V_63 ) ;
V_2 -> V_78 = true ;
F_62 ( V_2 ) ;
F_43 ( & V_2 -> V_63 ) ;
F_42 ( V_2 , L_23 ) ;
}
static T_6 F_87 ( int V_130 , void * V_131 )
{
struct V_140 * V_141 = V_131 ;
struct V_1 * V_2 ;
unsigned int V_142 = 0 ;
T_1 V_143 , V_144 ;
int V_43 ;
V_143 = ( V_141 -> V_16 & V_145 ) ? F_88 ( V_141 -> V_4 )
: F_89 ( V_141 -> V_4 ) ;
V_144 = 0xff000000 ;
F_90 ( V_141 -> V_84 , L_24 , V_143 ) ;
for ( V_43 = 0 ; V_43 < V_146 ; V_43 ++ ) {
V_2 = V_141 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_143 & V_144 ) {
F_90 ( V_141 -> V_84 , L_25 , V_2 -> V_147 ) ;
F_84 ( V_130 , V_2 ) ;
V_142 ++ ;
}
V_143 &= ~ V_144 ;
V_144 >>= 8 ;
}
return F_91 ( V_142 ) ;
}
static void F_92 ( struct V_140 * V_141 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_141 -> V_130 != V_148 ) {
F_90 ( V_141 -> V_84 , L_26 ) ;
F_93 ( V_141 -> V_130 , V_141 ) ;
return;
}
for ( V_43 = 0 ; V_43 < V_146 ; V_43 ++ ) {
V_2 = V_141 -> V_2 [ V_43 ] ;
if ( V_2 && V_2 -> V_130 != V_148 ) {
F_42 ( V_2 , L_27 ) ;
F_93 ( V_2 -> V_130 , V_2 ) ;
}
}
}
static int F_94 ( struct V_140 * V_141 )
{
struct V_1 * V_2 ;
int V_74 ;
int V_43 ;
if ( V_141 -> V_130 != V_148 ) {
F_90 ( V_141 -> V_84 , L_28 ) ;
V_74 = F_95 ( V_141 -> V_130 , F_87 , V_149 ,
L_29 , V_141 ) ;
return V_74 ;
}
for ( V_43 = 0 ; V_43 < V_146 ; V_43 ++ ) {
V_2 = V_141 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_130 == V_148 ) {
F_23 ( V_2 , L_30 ) ;
V_74 = - V_150 ;
goto V_151;
}
F_42 ( V_2 , L_31 ) ;
V_74 = F_95 ( V_2 -> V_130 , F_84 , V_149 ,
L_32 , V_2 ) ;
if ( V_74 ) {
F_23 ( V_2 , L_33 ) ;
goto V_151;
}
}
return 0 ;
V_151:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_141 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_130 == V_148 )
continue;
F_93 ( V_2 -> V_130 , V_2 ) ;
}
return V_74 ;
}
static int F_96 ( struct V_140 * V_141 ,
struct V_152 * V_66 , T_1 V_16 , const char * V_153 )
{
struct V_1 * V_2 ;
struct V_154 V_155 ;
int V_156 ;
V_2 = F_97 ( sizeof( * V_2 ) , V_157 ) ;
if ( ! V_2 ) {
F_98 ( V_141 -> V_84 , L_34 ) ;
V_156 = - V_85 ;
goto V_158;
}
V_2 -> V_4 = F_99 ( V_66 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_98 ( V_141 -> V_84 , L_35 ) ;
V_156 = - V_85 ;
goto V_159;
}
V_156 = F_100 ( V_66 , 0 , & V_155 ) ;
if ( V_156 ) {
F_98 ( V_141 -> V_84 , L_36 ) ;
goto V_160;
}
V_2 -> V_16 = V_16 ;
if ( ! V_141 -> V_16 )
V_141 -> V_16 = V_2 -> V_16 ;
F_101 ( V_141 -> V_16 != V_2 -> V_16 ) ;
V_2 -> V_84 = V_141 -> V_84 ;
V_2 -> V_147 = ( V_155 . V_161 & 0xfff ) < 0x300 ?
( ( V_155 . V_161 - 0x100 ) & 0xfff ) >> 7 :
( ( V_155 . V_161 - 0x200 ) & 0xfff ) >> 7 ;
if ( V_2 -> V_147 >= V_146 ) {
F_98 ( V_141 -> V_84 , L_37 ) ;
V_156 = - V_51 ;
goto V_160;
}
V_141 -> V_2 [ V_2 -> V_147 ] = V_2 ;
F_102 ( & V_2 -> V_138 , F_86 , ( unsigned long ) V_2 ) ;
snprintf ( V_2 -> V_83 , sizeof( V_2 -> V_83 ) , L_38 , V_2 -> V_147 ) ;
F_18 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
switch ( V_2 -> V_16 & V_17 ) {
case V_18 :
V_2 -> V_162 = F_29 ;
case V_25 :
V_2 -> V_163 = F_30 ;
V_2 -> V_164 = F_24 ;
V_2 -> V_165 = F_26 ;
V_2 -> V_119 = F_27 ;
}
F_103 ( & V_2 -> V_63 ) ;
F_51 ( & V_2 -> V_53 ) ;
F_51 ( & V_2 -> V_79 ) ;
F_51 ( & V_2 -> V_77 ) ;
V_2 -> V_78 = true ;
#ifdef F_40
V_2 -> V_64 = V_65 ;
#endif
V_2 -> V_70 . V_166 = & V_141 -> V_70 ;
F_104 ( & V_2 -> V_70 ) ;
V_2 -> V_130 = F_105 ( V_66 , 0 ) ;
F_59 ( & V_2 -> V_70 . V_152 , & V_141 -> V_70 . V_167 ) ;
V_141 -> V_70 . V_168 ++ ;
F_106 ( V_141 -> V_84 , L_39 , V_2 -> V_147 , V_153 ,
V_2 -> V_130 != V_148 ? V_2 -> V_130 : V_141 -> V_130 ) ;
return 0 ;
V_160:
F_107 ( V_2 -> V_4 ) ;
V_159:
F_108 ( V_2 ) ;
V_158:
return V_156 ;
}
static void F_109 ( struct V_1 * V_2 )
{
F_110 ( V_2 -> V_130 ) ;
F_47 ( & V_2 -> V_70 . V_152 ) ;
F_107 ( V_2 -> V_4 ) ;
F_108 ( V_2 ) ;
}
static int F_111 ( struct V_169 * V_170 )
{
struct V_140 * V_141 ;
struct V_152 * V_61 ;
int V_156 ;
V_141 = F_97 ( sizeof( * V_141 ) , V_157 ) ;
if ( ! V_141 ) {
F_98 ( & V_170 -> V_84 , L_40 ) ;
V_156 = - V_85 ;
goto V_158;
}
V_141 -> V_84 = & V_170 -> V_84 ;
F_51 ( & V_141 -> V_70 . V_167 ) ;
V_141 -> V_4 = F_99 ( V_170 -> V_84 . V_171 , 0 ) ;
if ( ! V_141 -> V_4 ) {
F_98 ( & V_170 -> V_84 , L_35 ) ;
V_156 = - V_85 ;
goto V_172;
}
V_141 -> V_130 = F_105 ( V_170 -> V_84 . V_171 , 0 ) ;
F_112 ( V_173 , V_141 -> V_70 . V_174 ) ;
F_112 ( V_175 , V_141 -> V_70 . V_174 ) ;
F_112 ( V_176 , V_141 -> V_70 . V_174 ) ;
V_141 -> V_70 . V_177 = F_63 ;
V_141 -> V_70 . V_178 = F_69 ;
V_141 -> V_70 . V_179 = F_71 ;
V_141 -> V_70 . V_180 = F_74 ;
V_141 -> V_70 . V_181 = F_82 ;
V_141 -> V_70 . V_182 = F_81 ;
V_141 -> V_70 . V_183 = F_79 ;
V_141 -> V_70 . V_184 = F_80 ;
V_141 -> V_70 . V_84 = & V_170 -> V_84 ;
F_113 ( & ( V_170 -> V_84 ) , F_114 ( 36 ) ) ;
F_115 ( V_170 , V_141 ) ;
F_116 (op->dev.of_node, child) {
if ( F_117 ( V_61 , L_41 ) ) {
F_96 ( V_141 , V_61 ,
V_18 | V_145 ,
L_41 ) ;
}
if ( F_117 ( V_61 , L_42 ) ) {
F_96 ( V_141 , V_61 ,
V_25 | V_185 ,
L_42 ) ;
}
}
V_156 = F_94 ( V_141 ) ;
if ( V_156 ) {
F_98 ( V_141 -> V_84 , L_43 ) ;
goto V_172;
}
F_118 ( & V_141 -> V_70 ) ;
return 0 ;
V_172:
F_110 ( V_141 -> V_130 ) ;
F_108 ( V_141 ) ;
V_158:
return V_156 ;
}
static int F_119 ( struct V_169 * V_170 )
{
struct V_140 * V_141 ;
unsigned int V_43 ;
V_141 = F_120 ( V_170 ) ;
F_121 ( & V_141 -> V_70 ) ;
F_92 ( V_141 ) ;
for ( V_43 = 0 ; V_43 < V_146 ; V_43 ++ ) {
if ( V_141 -> V_2 [ V_43 ] )
F_109 ( V_141 -> V_2 [ V_43 ] ) ;
}
F_107 ( V_141 -> V_4 ) ;
F_108 ( V_141 ) ;
return 0 ;
}
static int F_122 ( struct V_166 * V_84 )
{
struct V_169 * V_186 = F_123 ( V_84 ) ;
struct V_140 * V_141 = F_120 ( V_186 ) ;
struct V_1 * V_2 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_146 ; V_43 ++ ) {
V_2 = V_141 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
F_39 ( & V_2 -> V_63 ) ;
if ( F_41 ( ! V_2 -> V_78 ) )
goto V_187;
V_2 -> V_188 . V_6 = F_6 ( V_2 ) ;
V_2 -> V_64 = V_189 ;
F_43 ( & V_2 -> V_63 ) ;
}
return 0 ;
V_187:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_141 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
V_2 -> V_64 = V_65 ;
F_43 ( & V_2 -> V_63 ) ;
}
return - V_98 ;
}
static int F_124 ( struct V_166 * V_84 )
{
struct V_169 * V_186 = F_123 ( V_84 ) ;
struct V_140 * V_141 = F_120 ( V_186 ) ;
struct V_1 * V_2 ;
T_1 V_37 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_146 ; V_43 ++ ) {
V_2 = V_141 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
F_39 ( & V_2 -> V_63 ) ;
V_37 = V_2 -> V_188 . V_6
& ~ V_42 & ~ V_190 & ~ V_44 ;
F_5 ( V_2 , V_37 ) ;
V_2 -> V_64 = V_65 ;
F_43 ( & V_2 -> V_63 ) ;
}
return 0 ;
}
static T_7 int F_125 ( void )
{
F_126 ( L_44 ) ;
return F_127 ( & V_191 ) ;
}
static void T_8 F_128 ( void )
{
F_129 ( & V_191 ) ;
}
