static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , & V_2 -> V_4 -> V_5 , V_3 , 32 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , & V_2 -> V_4 -> V_5 , 32 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_2 V_6 )
{
F_2 ( V_2 , & V_2 -> V_4 -> V_7 , V_6 | V_8 , 64 ) ;
}
static T_2 F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , & V_2 -> V_4 -> V_7 , 64 ) & ~ V_8 ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , & V_2 -> V_4 -> V_9 , 32 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_10 * V_11 , T_1 V_12 )
{
V_11 -> V_12 = F_9 ( V_2 , V_12 , 32 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return F_11 ( V_2 , V_14 -> V_11 . V_12 , 32 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_10 * V_11 , T_2 V_15 )
{
T_3 V_16 ;
V_16 = ( ( V_2 -> V_17 & V_18 ) == V_19 )
? ( ( T_3 ) V_20 << 32 ) : 0 ;
V_11 -> V_21 = F_9 ( V_2 , V_16 | V_15 , 64 ) ;
}
static T_2 F_13 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_3 V_16 ;
V_16 = ( ( V_2 -> V_17 & V_18 ) == V_19 )
? ( ( T_3 ) V_20 << 32 ) : 0 ;
return F_11 ( V_2 , V_14 -> V_11 . V_21 , 64 ) & ~ V_16 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_10 * V_11 , T_2 V_22 )
{
T_3 V_16 ;
V_16 = ( ( V_2 -> V_17 & V_18 ) == V_19 )
? ( ( T_3 ) V_23 << 32 ) : 0 ;
V_11 -> V_24 = F_9 ( V_2 , V_16 | V_22 , 64 ) ;
}
static T_2 F_15 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_3 V_16 ;
V_16 = ( ( V_2 -> V_17 & V_18 ) == V_19 )
? ( ( T_3 ) V_23 << 32 ) : 0 ;
return F_11 ( V_2 , V_14 -> V_11 . V_24 , 64 ) & ~ V_16 ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_10 * V_11 , T_2 V_25 )
{
T_3 V_16 ;
V_16 = ( ( V_2 -> V_17 & V_18 ) == V_26 )
? V_8 : 0 ;
V_11 -> V_27 = F_9 ( V_2 , V_16 | V_25 , 64 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
T_3 V_16 ;
V_16 = ( ( V_2 -> V_17 & V_18 ) == V_26 )
? V_8 : 0 ;
V_14 -> V_11 . V_27 = F_9 ( V_2 ,
F_11 ( V_2 , V_14 -> V_11 . V_27 , 64 ) | V_28
| V_16 , 64 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , 0 , 32 ) ;
switch ( V_2 -> V_17 & V_18 ) {
case V_19 :
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_30
| V_31 | V_32 , 32 ) ;
break;
case V_26 :
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_33
| V_34 , 32 ) ;
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
V_37 = F_4 ( V_2 , & V_2 -> V_4 -> V_29 , 32 ) ;
if ( V_2 -> V_17 & V_38 ) {
F_2 ( V_2 , & V_2 -> V_4 -> V_9 , 0 , 32 ) ;
V_37 |= V_39 ;
} else {
V_37 &= ~ V_39 ;
}
if ( V_2 -> V_17 & V_40 ) {
V_37 |= V_41 ;
} else {
V_37 &= ~ V_41 ;
V_37 |= V_42 ;
}
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_37 ;
int V_43 ;
V_37 = F_4 ( V_2 , & V_2 -> V_4 -> V_29 , 32 ) ;
if ( ( V_2 -> V_17 & V_18 ) == V_19 ) {
V_37 |= V_44 ;
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
V_37 &= ~ V_44 ;
}
V_37 &= ~ ( V_42 | V_41 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
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
V_37 = F_4 ( V_2 , & V_2 -> V_4 -> V_29 , 32 ) ;
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
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_45 )
{
T_1 V_37 ;
V_37 = F_4 ( V_2 , & V_2 -> V_4 -> V_29 , 32 ) ;
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
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_45 )
{
T_1 V_37 ;
F_28 ( V_45 > 1024 ) ;
V_37 = F_4 ( V_2 , & V_2 -> V_4 -> V_29 , 32 ) ;
V_37 |= ( F_25 ( V_45 ) << 24 ) & 0x0f000000 ;
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_48 )
{
if ( V_48 )
V_2 -> V_17 |= V_38 ;
else
V_2 -> V_17 &= ~ V_38 ;
}
static void F_30 ( struct V_1 * V_2 , int V_48 )
{
if ( V_48 )
V_2 -> V_17 |= V_40 ;
else
V_2 -> V_17 &= ~ V_40 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_13 * V_49 = F_32 ( V_2 -> V_50 . V_51 ) ;
if ( F_33 ( & V_2 -> V_50 ) )
goto V_52;
F_16 ( V_2 , & V_49 -> V_11 , V_14 -> V_53 . V_54 ) ;
V_52:
F_34 ( & V_14 -> V_55 , & V_2 -> V_50 ) ;
}
static T_4 F_35 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_36 ( V_57 -> V_2 ) ;
struct V_13 * V_14 = F_37 ( V_57 ) ;
struct V_13 * V_58 ;
unsigned long V_59 ;
T_4 V_60 ;
F_38 ( & V_2 -> V_61 , V_59 ) ;
V_60 = V_2 -> V_62 . V_60 ;
F_39 (child, &desc->tx_list, node) {
V_60 ++ ;
if ( V_60 < V_63 )
V_60 = V_63 ;
V_58 -> V_53 . V_60 = V_60 ;
}
V_2 -> V_62 . V_60 = V_60 ;
F_31 ( V_2 , V_14 ) ;
F_40 ( & V_2 -> V_61 , V_59 ) ;
return V_60 ;
}
static struct V_13 * F_41 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
T_2 V_64 ;
V_14 = F_42 ( V_2 -> V_65 , V_66 , & V_64 ) ;
if ( ! V_14 ) {
F_43 ( V_2 , L_2 ) ;
return NULL ;
}
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
F_44 ( & V_14 -> V_55 ) ;
F_45 ( & V_14 -> V_53 , & V_2 -> V_62 ) ;
V_14 -> V_53 . V_67 = F_35 ;
V_14 -> V_53 . V_54 = V_64 ;
#ifdef F_46
F_43 ( V_2 , L_3 , V_14 ) ;
#endif
return V_14 ;
}
static int F_47 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_36 ( V_69 ) ;
if ( V_2 -> V_65 )
return 1 ;
V_2 -> V_65 = F_48 ( V_2 -> V_70 , V_2 -> V_71 ,
sizeof( struct V_13 ) ,
F_49 ( struct V_13 ) , 0 ) ;
if ( ! V_2 -> V_65 ) {
F_23 ( V_2 , L_4 ) ;
return - V_72 ;
}
return 1 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_13 * V_14 , * V_75 ;
F_51 (desc, _desc, list, node) {
F_52 ( & V_14 -> V_76 ) ;
#ifdef F_46
F_43 ( V_2 , L_5 , V_14 ) ;
#endif
F_53 ( V_2 -> V_65 , V_14 , V_14 -> V_53 . V_54 ) ;
}
}
static void F_54 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_13 * V_14 , * V_75 ;
F_55 (desc, _desc, list, node) {
F_52 ( & V_14 -> V_76 ) ;
#ifdef F_46
F_43 ( V_2 , L_5 , V_14 ) ;
#endif
F_53 ( V_2 -> V_65 , V_14 , V_14 -> V_53 . V_54 ) ;
}
}
static void F_56 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_36 ( V_69 ) ;
unsigned long V_59 ;
F_43 ( V_2 , L_6 ) ;
F_38 ( & V_2 -> V_61 , V_59 ) ;
F_50 ( V_2 , & V_2 -> V_50 ) ;
F_50 ( V_2 , & V_2 -> V_77 ) ;
F_40 ( & V_2 -> V_61 , V_59 ) ;
F_57 ( V_2 -> V_65 ) ;
V_2 -> V_65 = NULL ;
}
static struct V_56 *
F_58 ( struct V_68 * V_69 , unsigned long V_59 )
{
struct V_1 * V_2 ;
struct V_13 * V_78 ;
if ( ! V_69 )
return NULL ;
V_2 = F_36 ( V_69 ) ;
V_78 = F_41 ( V_2 ) ;
if ( ! V_78 ) {
F_23 ( V_2 , L_7 , V_79 ) ;
return NULL ;
}
V_78 -> V_53 . V_60 = - V_80 ;
V_78 -> V_53 . V_59 = V_59 ;
F_59 ( & V_78 -> V_76 , & V_78 -> V_55 ) ;
F_17 ( V_2 , V_78 ) ;
return & V_78 -> V_53 ;
}
static struct V_56 *
F_60 ( struct V_68 * V_69 ,
T_2 V_81 , T_2 V_82 ,
T_5 V_83 , unsigned long V_59 )
{
struct V_1 * V_2 ;
struct V_13 * V_84 = NULL , * V_51 = NULL , * V_78 ;
T_5 V_85 ;
if ( ! V_69 )
return NULL ;
if ( ! V_83 )
return NULL ;
V_2 = F_36 ( V_69 ) ;
do {
V_78 = F_41 ( V_2 ) ;
if ( ! V_78 ) {
F_23 ( V_2 , L_7 , V_79 ) ;
goto V_86;
}
V_85 = F_61 ( V_83 , ( T_5 ) V_87 ) ;
F_8 ( V_2 , & V_78 -> V_11 , V_85 ) ;
F_12 ( V_2 , & V_78 -> V_11 , V_82 ) ;
F_14 ( V_2 , & V_78 -> V_11 , V_81 ) ;
if ( ! V_84 )
V_84 = V_78 ;
else
F_16 ( V_2 , & V_51 -> V_11 , V_78 -> V_53 . V_54 ) ;
V_78 -> V_53 . V_60 = 0 ;
F_62 ( & V_78 -> V_53 ) ;
V_51 = V_78 ;
V_83 -= V_85 ;
V_82 += V_85 ;
V_81 += V_85 ;
F_59 ( & V_78 -> V_76 , & V_84 -> V_55 ) ;
} while ( V_83 );
V_78 -> V_53 . V_59 = V_59 ;
V_78 -> V_53 . V_60 = - V_80 ;
F_17 ( V_2 , V_78 ) ;
return & V_84 -> V_53 ;
V_86:
if ( ! V_84 )
return NULL ;
F_54 ( V_2 , & V_84 -> V_55 ) ;
return NULL ;
}
static struct V_56 * F_63 ( struct V_68 * V_69 ,
struct V_88 * V_89 , unsigned int V_90 ,
struct V_88 * V_91 , unsigned int V_92 ,
unsigned long V_59 )
{
struct V_13 * V_84 = NULL , * V_51 = NULL , * V_78 = NULL ;
struct V_1 * V_2 = F_36 ( V_69 ) ;
T_5 V_93 , V_94 ;
T_2 V_22 , V_15 ;
T_5 V_83 ;
if ( V_90 == 0 || V_92 == 0 )
return NULL ;
if ( V_89 == NULL || V_91 == NULL )
return NULL ;
V_93 = F_64 ( V_89 ) ;
V_94 = F_64 ( V_91 ) ;
while ( true ) {
V_83 = F_65 ( T_5 , V_94 , V_93 ) ;
V_83 = F_65 ( T_5 , V_83 , V_87 ) ;
if ( V_83 == 0 )
goto V_95;
V_22 = F_66 ( V_89 ) + F_64 ( V_89 ) - V_93 ;
V_15 = F_66 ( V_91 ) + F_64 ( V_91 ) - V_94 ;
V_78 = F_41 ( V_2 ) ;
if ( ! V_78 ) {
F_23 ( V_2 , L_7 , V_79 ) ;
goto V_86;
}
F_8 ( V_2 , & V_78 -> V_11 , V_83 ) ;
F_12 ( V_2 , & V_78 -> V_11 , V_15 ) ;
F_14 ( V_2 , & V_78 -> V_11 , V_22 ) ;
if ( ! V_84 )
V_84 = V_78 ;
else
F_16 ( V_2 , & V_51 -> V_11 , V_78 -> V_53 . V_54 ) ;
V_78 -> V_53 . V_60 = 0 ;
F_62 ( & V_78 -> V_53 ) ;
V_51 = V_78 ;
F_59 ( & V_78 -> V_76 , & V_84 -> V_55 ) ;
V_93 -= V_83 ;
V_94 -= V_83 ;
V_95:
if ( V_93 == 0 ) {
if ( V_90 == 0 )
break;
V_89 = F_67 ( V_89 ) ;
if ( V_89 == NULL )
break;
V_90 -- ;
V_93 = F_64 ( V_89 ) ;
}
if ( V_94 == 0 ) {
if ( V_92 == 0 )
break;
V_91 = F_67 ( V_91 ) ;
if ( V_91 == NULL )
break;
V_92 -- ;
V_94 = F_64 ( V_91 ) ;
}
}
V_78 -> V_53 . V_59 = V_59 ;
V_78 -> V_53 . V_60 = - V_80 ;
F_17 ( V_2 , V_78 ) ;
return & V_84 -> V_53 ;
V_86:
if ( ! V_84 )
return NULL ;
F_54 ( V_2 , & V_84 -> V_55 ) ;
return NULL ;
}
static struct V_56 * F_68 (
struct V_68 * V_69 , struct V_88 * V_96 , unsigned int V_97 ,
enum V_98 V_99 , unsigned long V_59 )
{
return NULL ;
}
static int F_69 ( struct V_68 * V_69 ,
enum V_100 V_101 , unsigned long V_102 )
{
struct V_103 * V_104 ;
struct V_1 * V_2 ;
unsigned long V_59 ;
int V_45 ;
if ( ! V_69 )
return - V_105 ;
V_2 = F_36 ( V_69 ) ;
switch ( V_101 ) {
case V_106 :
F_38 ( & V_2 -> V_61 , V_59 ) ;
F_21 ( V_2 ) ;
F_50 ( V_2 , & V_2 -> V_50 ) ;
F_50 ( V_2 , & V_2 -> V_77 ) ;
V_2 -> V_107 = true ;
F_40 ( & V_2 -> V_61 , V_59 ) ;
return 0 ;
case V_108 :
V_104 = (struct V_103 * ) V_102 ;
if ( ! V_2 -> V_109 )
return - V_110 ;
if ( V_104 -> V_99 == V_111 )
V_45 = V_104 -> V_112 * V_104 -> V_113 ;
else
V_45 = V_104 -> V_114 * V_104 -> V_115 ;
V_2 -> V_109 ( V_2 , V_45 ) ;
return 0 ;
case V_116 :
if ( ! V_2 -> V_117 )
return - V_110 ;
V_2 -> V_117 ( V_2 , V_102 ) ;
return 0 ;
default:
return - V_110 ;
}
return 0 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_56 * V_118 = & V_14 -> V_53 ;
struct V_119 * V_71 = V_2 -> V_62 . V_119 -> V_71 ;
T_2 V_15 = F_13 ( V_2 , V_14 ) ;
T_2 V_22 = F_15 ( V_2 , V_14 ) ;
T_1 V_83 = F_10 ( V_2 , V_14 ) ;
if ( V_118 -> V_120 ) {
#ifdef F_46
F_43 ( V_2 , L_8 , V_14 ) ;
#endif
V_118 -> V_120 ( V_118 -> V_121 ) ;
}
F_71 ( V_118 ) ;
if ( ! ( V_118 -> V_59 & V_122 ) ) {
if ( V_118 -> V_59 & V_123 )
F_72 ( V_71 , V_22 , V_83 , V_124 ) ;
else
F_73 ( V_71 , V_22 , V_83 , V_124 ) ;
}
if ( ! ( V_118 -> V_59 & V_125 ) ) {
if ( V_118 -> V_59 & V_126 )
F_72 ( V_71 , V_15 , V_83 , V_127 ) ;
else
F_73 ( V_71 , V_15 , V_83 , V_127 ) ;
}
#ifdef F_46
F_43 ( V_2 , L_5 , V_14 ) ;
#endif
F_53 ( V_2 -> V_65 , V_14 , V_118 -> V_54 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
if ( F_33 ( & V_2 -> V_50 ) ) {
F_43 ( V_2 , L_9 ) ;
return;
}
if ( ! V_2 -> V_107 ) {
F_43 ( V_2 , L_10 ) ;
return;
}
F_43 ( V_2 , L_11 ) ;
V_14 = F_75 ( & V_2 -> V_50 , struct V_13 , V_76 ) ;
F_34 ( & V_2 -> V_50 , & V_2 -> V_77 ) ;
if ( ( V_2 -> V_17 & V_18 ) == V_19 ) {
T_1 V_37 ;
V_37 = F_4 ( V_2 , & V_2 -> V_4 -> V_29 , 32 ) ;
V_37 &= ~ V_42 ;
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
}
F_5 ( V_2 , V_14 -> V_53 . V_54 ) ;
F_6 ( V_2 ) ;
F_20 ( V_2 ) ;
V_2 -> V_107 = false ;
}
static void F_76 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_36 ( V_69 ) ;
unsigned long V_59 ;
F_38 ( & V_2 -> V_61 , V_59 ) ;
F_74 ( V_2 ) ;
F_40 ( & V_2 -> V_61 , V_59 ) ;
}
static enum V_128 F_77 ( struct V_68 * V_69 ,
T_4 V_60 ,
struct V_129 * V_130 )
{
struct V_1 * V_2 = F_36 ( V_69 ) ;
T_4 V_131 ;
T_4 V_132 ;
unsigned long V_59 ;
F_38 ( & V_2 -> V_61 , V_59 ) ;
V_131 = V_2 -> V_133 ;
V_132 = V_69 -> V_60 ;
F_40 ( & V_2 -> V_61 , V_59 ) ;
F_78 ( V_130 , V_131 , V_132 , 0 ) ;
return F_79 ( V_60 , V_131 , V_132 ) ;
}
static T_6 F_80 ( int V_134 , void * V_135 )
{
struct V_1 * V_2 = V_135 ;
T_1 V_136 ;
V_136 = F_3 ( V_2 ) ;
F_1 ( V_2 , V_136 ) ;
F_43 ( V_2 , L_12 , V_136 ) ;
V_136 &= ~ ( V_35 | V_36 ) ;
if ( ! V_136 )
return V_137 ;
if ( V_136 & V_138 )
F_23 ( V_2 , L_13 ) ;
if ( V_136 & V_139 ) {
F_43 ( V_2 , L_14 ) ;
V_136 &= ~ V_139 ;
if ( F_7 ( V_2 ) != 0 )
F_23 ( V_2 , L_15 ) ;
}
if ( V_136 & V_140 ) {
F_43 ( V_2 , L_16 ) ;
V_136 &= ~ V_140 ;
}
if ( V_136 & V_141 ) {
F_43 ( V_2 , L_17 ) ;
V_136 &= ~ V_141 ;
}
if ( ! F_19 ( V_2 ) )
F_23 ( V_2 , L_18 ) ;
if ( V_136 )
F_23 ( V_2 , L_19 , V_136 ) ;
F_81 ( & V_2 -> V_142 ) ;
F_43 ( V_2 , L_20 ) ;
return V_143 ;
}
static void F_82 ( unsigned long V_135 )
{
struct V_1 * V_2 = (struct V_1 * ) V_135 ;
struct V_13 * V_14 , * V_75 ;
F_83 ( V_144 ) ;
unsigned long V_59 ;
F_43 ( V_2 , L_21 ) ;
F_38 ( & V_2 -> V_61 , V_59 ) ;
if ( ! F_33 ( & V_2 -> V_77 ) ) {
T_4 V_60 ;
V_14 = F_32 ( V_2 -> V_77 . V_51 ) ;
V_60 = V_14 -> V_53 . V_60 ;
V_2 -> V_133 = V_60 ;
F_43 ( V_2 , L_22 , V_60 ) ;
}
F_34 ( & V_2 -> V_77 , & V_144 ) ;
V_2 -> V_107 = true ;
F_74 ( V_2 ) ;
F_40 ( & V_2 -> V_61 , V_59 ) ;
F_51 (desc, _desc, &ld_cleanup, node) {
F_52 ( & V_14 -> V_76 ) ;
F_70 ( V_2 , V_14 ) ;
}
F_43 ( V_2 , L_23 ) ;
}
static T_6 F_84 ( int V_134 , void * V_135 )
{
struct V_145 * V_146 = V_135 ;
struct V_1 * V_2 ;
unsigned int V_147 = 0 ;
T_1 V_148 , V_149 ;
int V_43 ;
V_148 = ( V_146 -> V_17 & V_150 ) ? F_85 ( V_146 -> V_4 )
: F_86 ( V_146 -> V_4 ) ;
V_149 = 0xff000000 ;
F_87 ( V_146 -> V_71 , L_24 , V_148 ) ;
for ( V_43 = 0 ; V_43 < V_151 ; V_43 ++ ) {
V_2 = V_146 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_148 & V_149 ) {
F_87 ( V_146 -> V_71 , L_25 , V_2 -> V_152 ) ;
F_80 ( V_134 , V_2 ) ;
V_147 ++ ;
}
V_148 &= ~ V_149 ;
V_149 >>= 8 ;
}
return F_88 ( V_147 ) ;
}
static void F_89 ( struct V_145 * V_146 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_146 -> V_134 != V_153 ) {
F_87 ( V_146 -> V_71 , L_26 ) ;
F_90 ( V_146 -> V_134 , V_146 ) ;
return;
}
for ( V_43 = 0 ; V_43 < V_151 ; V_43 ++ ) {
V_2 = V_146 -> V_2 [ V_43 ] ;
if ( V_2 && V_2 -> V_134 != V_153 ) {
F_43 ( V_2 , L_27 ) ;
F_90 ( V_2 -> V_134 , V_2 ) ;
}
}
}
static int F_91 ( struct V_145 * V_146 )
{
struct V_1 * V_2 ;
int V_154 ;
int V_43 ;
if ( V_146 -> V_134 != V_153 ) {
F_87 ( V_146 -> V_71 , L_28 ) ;
V_154 = F_92 ( V_146 -> V_134 , F_84 , V_155 ,
L_29 , V_146 ) ;
return V_154 ;
}
for ( V_43 = 0 ; V_43 < V_151 ; V_43 ++ ) {
V_2 = V_146 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_134 == V_153 ) {
F_23 ( V_2 , L_30 ) ;
V_154 = - V_156 ;
goto V_157;
}
F_43 ( V_2 , L_31 ) ;
V_154 = F_92 ( V_2 -> V_134 , F_80 , V_155 ,
L_32 , V_2 ) ;
if ( V_154 ) {
F_23 ( V_2 , L_33 ) ;
goto V_157;
}
}
return 0 ;
V_157:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_146 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_134 == V_153 )
continue;
F_90 ( V_2 -> V_134 , V_2 ) ;
}
return V_154 ;
}
static int T_7 F_93 ( struct V_145 * V_146 ,
struct V_158 * V_76 , T_1 V_17 , const char * V_159 )
{
struct V_1 * V_2 ;
struct V_160 V_161 ;
int V_162 ;
V_2 = F_94 ( sizeof( * V_2 ) , V_163 ) ;
if ( ! V_2 ) {
F_95 ( V_146 -> V_71 , L_34 ) ;
V_162 = - V_72 ;
goto V_164;
}
V_2 -> V_4 = F_96 ( V_76 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_95 ( V_146 -> V_71 , L_35 ) ;
V_162 = - V_72 ;
goto V_165;
}
V_162 = F_97 ( V_76 , 0 , & V_161 ) ;
if ( V_162 ) {
F_95 ( V_146 -> V_71 , L_36 ) ;
goto V_166;
}
V_2 -> V_17 = V_17 ;
if ( ! V_146 -> V_17 )
V_146 -> V_17 = V_2 -> V_17 ;
F_98 ( V_146 -> V_17 != V_2 -> V_17 ) ;
V_2 -> V_71 = V_146 -> V_71 ;
V_2 -> V_152 = ( ( V_161 . V_167 - 0x100 ) & 0xfff ) >> 7 ;
if ( V_2 -> V_152 >= V_151 ) {
F_95 ( V_146 -> V_71 , L_37 ) ;
V_162 = - V_105 ;
goto V_166;
}
V_146 -> V_2 [ V_2 -> V_152 ] = V_2 ;
F_99 ( & V_2 -> V_142 , F_82 , ( unsigned long ) V_2 ) ;
snprintf ( V_2 -> V_70 , sizeof( V_2 -> V_70 ) , L_38 , V_2 -> V_152 ) ;
F_18 ( V_2 ) ;
F_5 ( V_2 , 0 ) ;
switch ( V_2 -> V_17 & V_18 ) {
case V_19 :
V_2 -> V_168 = F_29 ;
case V_26 :
V_2 -> V_117 = F_30 ;
V_2 -> V_169 = F_24 ;
V_2 -> V_170 = F_26 ;
V_2 -> V_109 = F_27 ;
}
F_100 ( & V_2 -> V_61 ) ;
F_44 ( & V_2 -> V_50 ) ;
F_44 ( & V_2 -> V_77 ) ;
V_2 -> V_107 = true ;
V_2 -> V_62 . V_119 = & V_146 -> V_62 ;
V_2 -> V_134 = F_101 ( V_76 , 0 ) ;
F_59 ( & V_2 -> V_62 . V_158 , & V_146 -> V_62 . V_171 ) ;
V_146 -> V_62 . V_172 ++ ;
F_102 ( V_146 -> V_71 , L_39 , V_2 -> V_152 , V_159 ,
V_2 -> V_134 != V_153 ? V_2 -> V_134 : V_146 -> V_134 ) ;
return 0 ;
V_166:
F_103 ( V_2 -> V_4 ) ;
V_165:
F_104 ( V_2 ) ;
V_164:
return V_162 ;
}
static void F_105 ( struct V_1 * V_2 )
{
F_106 ( V_2 -> V_134 ) ;
F_52 ( & V_2 -> V_62 . V_158 ) ;
F_103 ( V_2 -> V_4 ) ;
F_104 ( V_2 ) ;
}
static int T_7 F_107 ( struct V_173 * V_174 )
{
struct V_145 * V_146 ;
struct V_158 * V_58 ;
int V_162 ;
V_146 = F_94 ( sizeof( * V_146 ) , V_163 ) ;
if ( ! V_146 ) {
F_95 ( & V_174 -> V_71 , L_40 ) ;
V_162 = - V_72 ;
goto V_164;
}
V_146 -> V_71 = & V_174 -> V_71 ;
F_44 ( & V_146 -> V_62 . V_171 ) ;
V_146 -> V_4 = F_96 ( V_174 -> V_71 . V_175 , 0 ) ;
if ( ! V_146 -> V_4 ) {
F_95 ( & V_174 -> V_71 , L_35 ) ;
V_162 = - V_72 ;
goto V_176;
}
V_146 -> V_134 = F_101 ( V_174 -> V_71 . V_175 , 0 ) ;
F_108 ( V_177 , V_146 -> V_62 . V_178 ) ;
F_108 ( V_179 , V_146 -> V_62 . V_178 ) ;
F_108 ( V_180 , V_146 -> V_62 . V_178 ) ;
F_108 ( V_181 , V_146 -> V_62 . V_178 ) ;
V_146 -> V_62 . V_182 = F_47 ;
V_146 -> V_62 . V_183 = F_56 ;
V_146 -> V_62 . V_184 = F_58 ;
V_146 -> V_62 . V_185 = F_60 ;
V_146 -> V_62 . V_186 = F_63 ;
V_146 -> V_62 . V_187 = F_77 ;
V_146 -> V_62 . V_188 = F_76 ;
V_146 -> V_62 . V_189 = F_68 ;
V_146 -> V_62 . V_190 = F_69 ;
V_146 -> V_62 . V_71 = & V_174 -> V_71 ;
F_109 ( & ( V_174 -> V_71 ) , F_110 ( 36 ) ) ;
F_111 ( & V_174 -> V_71 , V_146 ) ;
F_112 (op->dev.of_node, child) {
if ( F_113 ( V_58 , L_41 ) ) {
F_93 ( V_146 , V_58 ,
V_19 | V_150 ,
L_41 ) ;
}
if ( F_113 ( V_58 , L_42 ) ) {
F_93 ( V_146 , V_58 ,
V_26 | V_191 ,
L_42 ) ;
}
}
V_162 = F_91 ( V_146 ) ;
if ( V_162 ) {
F_95 ( V_146 -> V_71 , L_43 ) ;
goto V_176;
}
F_114 ( & V_146 -> V_62 ) ;
return 0 ;
V_176:
F_106 ( V_146 -> V_134 ) ;
F_104 ( V_146 ) ;
V_164:
return V_162 ;
}
static int F_115 ( struct V_173 * V_174 )
{
struct V_145 * V_146 ;
unsigned int V_43 ;
V_146 = F_116 ( & V_174 -> V_71 ) ;
F_117 ( & V_146 -> V_62 ) ;
F_89 ( V_146 ) ;
for ( V_43 = 0 ; V_43 < V_151 ; V_43 ++ ) {
if ( V_146 -> V_2 [ V_43 ] )
F_105 ( V_146 -> V_2 [ V_43 ] ) ;
}
F_103 ( V_146 -> V_4 ) ;
F_111 ( & V_174 -> V_71 , NULL ) ;
F_104 ( V_146 ) ;
return 0 ;
}
static T_8 int F_118 ( void )
{
F_119 ( L_44 ) ;
return F_120 ( & V_192 ) ;
}
static void T_9 F_121 ( void )
{
F_122 ( & V_192 ) ;
}
