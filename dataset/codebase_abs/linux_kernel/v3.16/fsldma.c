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
unsigned long V_59 ;
T_4 V_60 = - V_61 ;
F_38 ( & V_2 -> V_62 , V_59 ) ;
F_39 (child, &desc->tx_list, node) {
V_60 = F_40 ( & V_58 -> V_53 ) ;
}
F_31 ( V_2 , V_28 ) ;
F_41 ( & V_2 -> V_62 , V_59 ) ;
return V_60 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_43 ( & V_28 -> V_63 ) ;
F_44 ( V_2 , L_2 , V_28 ) ;
F_45 ( V_2 -> V_64 , V_28 , V_28 -> V_53 . V_54 ) ;
}
static struct V_27 * F_46 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
T_2 V_65 ;
V_28 = F_47 ( V_2 -> V_64 , V_66 , & V_65 ) ;
if ( ! V_28 ) {
F_44 ( V_2 , L_3 ) ;
return NULL ;
}
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
F_48 ( & V_28 -> V_55 ) ;
F_49 ( & V_28 -> V_53 , & V_2 -> V_67 ) ;
V_28 -> V_53 . V_68 = F_35 ;
V_28 -> V_53 . V_54 = V_65 ;
F_44 ( V_2 , L_4 , V_28 ) ;
return V_28 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
if ( F_33 ( & V_2 -> V_50 ) ) {
F_44 ( V_2 , L_5 ) ;
return;
}
if ( ! V_2 -> V_69 ) {
F_44 ( V_2 , L_6 ) ;
return;
}
F_44 ( V_2 , L_7 ) ;
V_28 = F_51 ( & V_2 -> V_50 , struct V_27 , V_63 ) ;
F_34 ( & V_2 -> V_50 , & V_2 -> V_70 ) ;
if ( ( V_2 -> V_16 & V_17 ) == V_18 ) {
T_1 V_37 ;
V_37 = F_6 ( V_2 ) ;
V_37 &= ~ V_42 ;
F_5 ( V_2 , V_37 ) ;
}
F_7 ( V_2 , V_28 -> V_53 . V_54 ) ;
F_8 ( V_2 ) ;
F_20 ( V_2 ) ;
V_2 -> V_69 = false ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_56 * V_71 = & V_28 -> V_53 ;
if ( V_71 -> V_72 ) {
F_44 ( V_2 , L_8 , V_28 ) ;
V_71 -> V_72 ( V_71 -> V_73 ) ;
}
F_53 ( V_71 ) ;
F_54 ( V_71 ) ;
F_44 ( V_2 , L_2 , V_28 ) ;
F_45 ( V_2 -> V_64 , V_28 , V_71 -> V_54 ) ;
}
static int F_55 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_36 ( V_75 ) ;
if ( V_2 -> V_64 )
return 1 ;
V_2 -> V_64 = F_56 ( V_2 -> V_76 , V_2 -> V_77 ,
sizeof( struct V_27 ) ,
F_57 ( struct V_27 ) , 0 ) ;
if ( ! V_2 -> V_64 ) {
F_23 ( V_2 , L_9 ) ;
return - V_78 ;
}
return 1 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_27 * V_28 , * V_81 ;
F_59 (desc, _desc, list, node)
F_42 ( V_2 , V_28 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_27 * V_28 , * V_81 ;
F_61 (desc, _desc, list, node)
F_42 ( V_2 , V_28 ) ;
}
static void F_62 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_36 ( V_75 ) ;
unsigned long V_59 ;
F_44 ( V_2 , L_10 ) ;
F_38 ( & V_2 -> V_62 , V_59 ) ;
F_58 ( V_2 , & V_2 -> V_50 ) ;
F_58 ( V_2 , & V_2 -> V_70 ) ;
F_41 ( & V_2 -> V_62 , V_59 ) ;
F_63 ( V_2 -> V_64 ) ;
V_2 -> V_64 = NULL ;
}
static struct V_56 *
F_64 ( struct V_74 * V_75 ,
T_2 V_82 , T_2 V_83 ,
T_5 V_84 , unsigned long V_59 )
{
struct V_1 * V_2 ;
struct V_27 * V_85 = NULL , * V_51 = NULL , * V_86 ;
T_5 V_87 ;
if ( ! V_75 )
return NULL ;
if ( ! V_84 )
return NULL ;
V_2 = F_36 ( V_75 ) ;
do {
V_86 = F_46 ( V_2 ) ;
if ( ! V_86 ) {
F_23 ( V_2 , L_11 , V_88 ) ;
goto V_89;
}
V_87 = F_65 ( V_84 , ( T_5 ) V_90 ) ;
F_11 ( V_2 , & V_86 -> V_12 , V_87 ) ;
F_13 ( V_2 , & V_86 -> V_12 , V_83 ) ;
F_14 ( V_2 , & V_86 -> V_12 , V_82 ) ;
if ( ! V_85 )
V_85 = V_86 ;
else
F_15 ( V_2 , & V_51 -> V_12 , V_86 -> V_53 . V_54 ) ;
V_86 -> V_53 . V_60 = 0 ;
F_66 ( & V_86 -> V_53 ) ;
V_51 = V_86 ;
V_84 -= V_87 ;
V_83 += V_87 ;
V_82 += V_87 ;
F_67 ( & V_86 -> V_63 , & V_85 -> V_55 ) ;
} while ( V_84 );
V_86 -> V_53 . V_59 = V_59 ;
V_86 -> V_53 . V_60 = - V_91 ;
F_16 ( V_2 , V_86 ) ;
return & V_85 -> V_53 ;
V_89:
if ( ! V_85 )
return NULL ;
F_60 ( V_2 , & V_85 -> V_55 ) ;
return NULL ;
}
static struct V_56 * F_68 ( struct V_74 * V_75 ,
struct V_92 * V_93 , unsigned int V_94 ,
struct V_92 * V_95 , unsigned int V_96 ,
unsigned long V_59 )
{
struct V_27 * V_85 = NULL , * V_51 = NULL , * V_86 = NULL ;
struct V_1 * V_2 = F_36 ( V_75 ) ;
T_5 V_97 , V_98 ;
T_2 V_21 , V_14 ;
T_5 V_84 ;
if ( V_94 == 0 || V_96 == 0 )
return NULL ;
if ( V_93 == NULL || V_95 == NULL )
return NULL ;
V_97 = F_69 ( V_93 ) ;
V_98 = F_69 ( V_95 ) ;
while ( true ) {
V_84 = F_70 ( T_5 , V_98 , V_97 ) ;
V_84 = F_70 ( T_5 , V_84 , V_90 ) ;
if ( V_84 == 0 )
goto V_99;
V_21 = F_71 ( V_93 ) + F_69 ( V_93 ) - V_97 ;
V_14 = F_71 ( V_95 ) + F_69 ( V_95 ) - V_98 ;
V_86 = F_46 ( V_2 ) ;
if ( ! V_86 ) {
F_23 ( V_2 , L_11 , V_88 ) ;
goto V_89;
}
F_11 ( V_2 , & V_86 -> V_12 , V_84 ) ;
F_13 ( V_2 , & V_86 -> V_12 , V_14 ) ;
F_14 ( V_2 , & V_86 -> V_12 , V_21 ) ;
if ( ! V_85 )
V_85 = V_86 ;
else
F_15 ( V_2 , & V_51 -> V_12 , V_86 -> V_53 . V_54 ) ;
V_86 -> V_53 . V_60 = 0 ;
F_66 ( & V_86 -> V_53 ) ;
V_51 = V_86 ;
F_67 ( & V_86 -> V_63 , & V_85 -> V_55 ) ;
V_97 -= V_84 ;
V_98 -= V_84 ;
V_99:
if ( V_97 == 0 ) {
if ( V_94 == 0 )
break;
V_93 = F_72 ( V_93 ) ;
if ( V_93 == NULL )
break;
V_94 -- ;
V_97 = F_69 ( V_93 ) ;
}
if ( V_98 == 0 ) {
if ( V_96 == 0 )
break;
V_95 = F_72 ( V_95 ) ;
if ( V_95 == NULL )
break;
V_96 -- ;
V_98 = F_69 ( V_95 ) ;
}
}
V_86 -> V_53 . V_59 = V_59 ;
V_86 -> V_53 . V_60 = - V_91 ;
F_16 ( V_2 , V_86 ) ;
return & V_85 -> V_53 ;
V_89:
if ( ! V_85 )
return NULL ;
F_60 ( V_2 , & V_85 -> V_55 ) ;
return NULL ;
}
static struct V_56 * F_73 (
struct V_74 * V_75 , struct V_92 * V_100 , unsigned int V_101 ,
enum V_102 V_103 , unsigned long V_59 ,
void * V_104 )
{
return NULL ;
}
static int F_74 ( struct V_74 * V_75 ,
enum V_105 V_106 , unsigned long V_107 )
{
struct V_108 * V_109 ;
struct V_1 * V_2 ;
unsigned long V_59 ;
int V_45 ;
if ( ! V_75 )
return - V_61 ;
V_2 = F_36 ( V_75 ) ;
switch ( V_106 ) {
case V_110 :
F_38 ( & V_2 -> V_62 , V_59 ) ;
F_21 ( V_2 ) ;
F_58 ( V_2 , & V_2 -> V_50 ) ;
F_58 ( V_2 , & V_2 -> V_70 ) ;
V_2 -> V_69 = true ;
F_41 ( & V_2 -> V_62 , V_59 ) ;
return 0 ;
case V_111 :
V_109 = (struct V_108 * ) V_107 ;
if ( ! V_2 -> V_112 )
return - V_113 ;
if ( V_109 -> V_103 == V_114 )
V_45 = V_109 -> V_115 * V_109 -> V_116 ;
else
V_45 = V_109 -> V_117 * V_109 -> V_118 ;
V_2 -> V_112 ( V_2 , V_45 ) ;
return 0 ;
case V_119 :
if ( ! V_2 -> V_120 )
return - V_113 ;
V_2 -> V_120 ( V_2 , V_107 ) ;
return 0 ;
default:
return - V_113 ;
}
return 0 ;
}
static void F_75 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_36 ( V_75 ) ;
unsigned long V_59 ;
F_38 ( & V_2 -> V_62 , V_59 ) ;
F_50 ( V_2 ) ;
F_41 ( & V_2 -> V_62 , V_59 ) ;
}
static enum V_121 F_76 ( struct V_74 * V_75 ,
T_4 V_60 ,
struct V_122 * V_123 )
{
return F_77 ( V_75 , V_60 , V_123 ) ;
}
static T_6 F_78 ( int V_124 , void * V_125 )
{
struct V_1 * V_2 = V_125 ;
T_1 V_126 ;
V_126 = F_3 ( V_2 ) ;
F_1 ( V_2 , V_126 ) ;
F_44 ( V_2 , L_12 , V_126 ) ;
V_126 &= ~ ( V_35 | V_36 ) ;
if ( ! V_126 )
return V_127 ;
if ( V_126 & V_128 )
F_23 ( V_2 , L_13 ) ;
if ( V_126 & V_129 ) {
F_44 ( V_2 , L_14 ) ;
V_126 &= ~ V_129 ;
if ( F_10 ( V_2 ) != 0 )
F_23 ( V_2 , L_15 ) ;
}
if ( V_126 & V_130 ) {
F_44 ( V_2 , L_16 ) ;
V_126 &= ~ V_130 ;
}
if ( V_126 & V_131 ) {
F_44 ( V_2 , L_17 ) ;
V_126 &= ~ V_131 ;
}
if ( ! F_19 ( V_2 ) )
F_23 ( V_2 , L_18 ) ;
if ( V_126 )
F_23 ( V_2 , L_19 , V_126 ) ;
F_79 ( & V_2 -> V_132 ) ;
F_44 ( V_2 , L_20 ) ;
return V_133 ;
}
static void F_80 ( unsigned long V_125 )
{
struct V_1 * V_2 = (struct V_1 * ) V_125 ;
struct V_27 * V_28 , * V_81 ;
F_81 ( V_134 ) ;
unsigned long V_59 ;
F_44 ( V_2 , L_21 ) ;
F_38 ( & V_2 -> V_62 , V_59 ) ;
if ( ! F_33 ( & V_2 -> V_70 ) ) {
T_4 V_60 ;
V_28 = F_32 ( V_2 -> V_70 . V_51 ) ;
V_60 = V_28 -> V_53 . V_60 ;
F_82 ( & V_28 -> V_53 ) ;
F_44 ( V_2 , L_22 , V_60 ) ;
}
F_34 ( & V_2 -> V_70 , & V_134 ) ;
V_2 -> V_69 = true ;
F_50 ( V_2 ) ;
F_41 ( & V_2 -> V_62 , V_59 ) ;
F_59 (desc, _desc, &ld_cleanup, node) {
F_43 ( & V_28 -> V_63 ) ;
F_52 ( V_2 , V_28 ) ;
}
F_44 ( V_2 , L_23 ) ;
}
static T_6 F_83 ( int V_124 , void * V_125 )
{
struct V_135 * V_136 = V_125 ;
struct V_1 * V_2 ;
unsigned int V_137 = 0 ;
T_1 V_138 , V_139 ;
int V_43 ;
V_138 = ( V_136 -> V_16 & V_140 ) ? F_84 ( V_136 -> V_4 )
: F_85 ( V_136 -> V_4 ) ;
V_139 = 0xff000000 ;
F_86 ( V_136 -> V_77 , L_24 , V_138 ) ;
for ( V_43 = 0 ; V_43 < V_141 ; V_43 ++ ) {
V_2 = V_136 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_138 & V_139 ) {
F_86 ( V_136 -> V_77 , L_25 , V_2 -> V_142 ) ;
F_78 ( V_124 , V_2 ) ;
V_137 ++ ;
}
V_138 &= ~ V_139 ;
V_139 >>= 8 ;
}
return F_87 ( V_137 ) ;
}
static void F_88 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_136 -> V_124 != V_143 ) {
F_86 ( V_136 -> V_77 , L_26 ) ;
F_89 ( V_136 -> V_124 , V_136 ) ;
return;
}
for ( V_43 = 0 ; V_43 < V_141 ; V_43 ++ ) {
V_2 = V_136 -> V_2 [ V_43 ] ;
if ( V_2 && V_2 -> V_124 != V_143 ) {
F_44 ( V_2 , L_27 ) ;
F_89 ( V_2 -> V_124 , V_2 ) ;
}
}
}
static int F_90 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
int V_144 ;
int V_43 ;
if ( V_136 -> V_124 != V_143 ) {
F_86 ( V_136 -> V_77 , L_28 ) ;
V_144 = F_91 ( V_136 -> V_124 , F_83 , V_145 ,
L_29 , V_136 ) ;
return V_144 ;
}
for ( V_43 = 0 ; V_43 < V_141 ; V_43 ++ ) {
V_2 = V_136 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_124 == V_143 ) {
F_23 ( V_2 , L_30 ) ;
V_144 = - V_146 ;
goto V_147;
}
F_44 ( V_2 , L_31 ) ;
V_144 = F_91 ( V_2 -> V_124 , F_78 , V_145 ,
L_32 , V_2 ) ;
if ( V_144 ) {
F_23 ( V_2 , L_33 ) ;
goto V_147;
}
}
return 0 ;
V_147:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_136 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_124 == V_143 )
continue;
F_89 ( V_2 -> V_124 , V_2 ) ;
}
return V_144 ;
}
static int F_92 ( struct V_135 * V_136 ,
struct V_148 * V_63 , T_1 V_16 , const char * V_149 )
{
struct V_1 * V_2 ;
struct V_150 V_151 ;
int V_152 ;
V_2 = F_93 ( sizeof( * V_2 ) , V_153 ) ;
if ( ! V_2 ) {
F_94 ( V_136 -> V_77 , L_34 ) ;
V_152 = - V_78 ;
goto V_154;
}
V_2 -> V_4 = F_95 ( V_63 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_94 ( V_136 -> V_77 , L_35 ) ;
V_152 = - V_78 ;
goto V_155;
}
V_152 = F_96 ( V_63 , 0 , & V_151 ) ;
if ( V_152 ) {
F_94 ( V_136 -> V_77 , L_36 ) ;
goto V_156;
}
V_2 -> V_16 = V_16 ;
if ( ! V_136 -> V_16 )
V_136 -> V_16 = V_2 -> V_16 ;
F_97 ( V_136 -> V_16 != V_2 -> V_16 ) ;
V_2 -> V_77 = V_136 -> V_77 ;
V_2 -> V_142 = ( V_151 . V_157 & 0xfff ) < 0x300 ?
( ( V_151 . V_157 - 0x100 ) & 0xfff ) >> 7 :
( ( V_151 . V_157 - 0x200 ) & 0xfff ) >> 7 ;
if ( V_2 -> V_142 >= V_141 ) {
F_94 ( V_136 -> V_77 , L_37 ) ;
V_152 = - V_61 ;
goto V_156;
}
V_136 -> V_2 [ V_2 -> V_142 ] = V_2 ;
F_98 ( & V_2 -> V_132 , F_80 , ( unsigned long ) V_2 ) ;
snprintf ( V_2 -> V_76 , sizeof( V_2 -> V_76 ) , L_38 , V_2 -> V_142 ) ;
F_18 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
switch ( V_2 -> V_16 & V_17 ) {
case V_18 :
V_2 -> V_158 = F_29 ;
case V_25 :
V_2 -> V_120 = F_30 ;
V_2 -> V_159 = F_24 ;
V_2 -> V_160 = F_26 ;
V_2 -> V_112 = F_27 ;
}
F_99 ( & V_2 -> V_62 ) ;
F_48 ( & V_2 -> V_50 ) ;
F_48 ( & V_2 -> V_70 ) ;
V_2 -> V_69 = true ;
V_2 -> V_67 . V_161 = & V_136 -> V_67 ;
F_100 ( & V_2 -> V_67 ) ;
V_2 -> V_124 = F_101 ( V_63 , 0 ) ;
F_67 ( & V_2 -> V_67 . V_148 , & V_136 -> V_67 . V_162 ) ;
V_136 -> V_67 . V_163 ++ ;
F_102 ( V_136 -> V_77 , L_39 , V_2 -> V_142 , V_149 ,
V_2 -> V_124 != V_143 ? V_2 -> V_124 : V_136 -> V_124 ) ;
return 0 ;
V_156:
F_103 ( V_2 -> V_4 ) ;
V_155:
F_104 ( V_2 ) ;
V_154:
return V_152 ;
}
static void F_105 ( struct V_1 * V_2 )
{
F_106 ( V_2 -> V_124 ) ;
F_43 ( & V_2 -> V_67 . V_148 ) ;
F_103 ( V_2 -> V_4 ) ;
F_104 ( V_2 ) ;
}
static int F_107 ( struct V_164 * V_165 )
{
struct V_135 * V_136 ;
struct V_148 * V_58 ;
int V_152 ;
V_136 = F_93 ( sizeof( * V_136 ) , V_153 ) ;
if ( ! V_136 ) {
F_94 ( & V_165 -> V_77 , L_40 ) ;
V_152 = - V_78 ;
goto V_154;
}
V_136 -> V_77 = & V_165 -> V_77 ;
F_48 ( & V_136 -> V_67 . V_162 ) ;
V_136 -> V_4 = F_95 ( V_165 -> V_77 . V_166 , 0 ) ;
if ( ! V_136 -> V_4 ) {
F_94 ( & V_165 -> V_77 , L_35 ) ;
V_152 = - V_78 ;
goto V_167;
}
V_136 -> V_124 = F_101 ( V_165 -> V_77 . V_166 , 0 ) ;
F_108 ( V_168 , V_136 -> V_67 . V_169 ) ;
F_108 ( V_170 , V_136 -> V_67 . V_169 ) ;
F_108 ( V_171 , V_136 -> V_67 . V_169 ) ;
V_136 -> V_67 . V_172 = F_55 ;
V_136 -> V_67 . V_173 = F_62 ;
V_136 -> V_67 . V_174 = F_64 ;
V_136 -> V_67 . V_175 = F_68 ;
V_136 -> V_67 . V_176 = F_76 ;
V_136 -> V_67 . V_177 = F_75 ;
V_136 -> V_67 . V_178 = F_73 ;
V_136 -> V_67 . V_179 = F_74 ;
V_136 -> V_67 . V_77 = & V_165 -> V_77 ;
F_109 ( & ( V_165 -> V_77 ) , F_110 ( 36 ) ) ;
F_111 ( V_165 , V_136 ) ;
F_112 (op->dev.of_node, child) {
if ( F_113 ( V_58 , L_41 ) ) {
F_92 ( V_136 , V_58 ,
V_18 | V_140 ,
L_41 ) ;
}
if ( F_113 ( V_58 , L_42 ) ) {
F_92 ( V_136 , V_58 ,
V_25 | V_180 ,
L_42 ) ;
}
}
V_152 = F_90 ( V_136 ) ;
if ( V_152 ) {
F_94 ( V_136 -> V_77 , L_43 ) ;
goto V_167;
}
F_114 ( & V_136 -> V_67 ) ;
return 0 ;
V_167:
F_106 ( V_136 -> V_124 ) ;
F_104 ( V_136 ) ;
V_154:
return V_152 ;
}
static int F_115 ( struct V_164 * V_165 )
{
struct V_135 * V_136 ;
unsigned int V_43 ;
V_136 = F_116 ( V_165 ) ;
F_117 ( & V_136 -> V_67 ) ;
F_88 ( V_136 ) ;
for ( V_43 = 0 ; V_43 < V_141 ; V_43 ++ ) {
if ( V_136 -> V_2 [ V_43 ] )
F_105 ( V_136 -> V_2 [ V_43 ] ) ;
}
F_103 ( V_136 -> V_4 ) ;
F_104 ( V_136 ) ;
return 0 ;
}
static T_7 int F_118 ( void )
{
F_119 ( L_44 ) ;
return F_120 ( & V_181 ) ;
}
static void T_8 F_121 ( void )
{
F_122 ( & V_181 ) ;
}
