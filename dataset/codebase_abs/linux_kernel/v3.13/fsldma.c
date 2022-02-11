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
static void F_10 ( struct V_1 * V_2 ,
struct V_10 * V_11 , T_2 V_13 )
{
T_3 V_14 ;
V_14 = ( ( V_2 -> V_15 & V_16 ) == V_17 )
? ( ( T_3 ) V_18 << 32 ) : 0 ;
V_11 -> V_19 = F_9 ( V_2 , V_14 | V_13 , 64 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_10 * V_11 , T_2 V_20 )
{
T_3 V_14 ;
V_14 = ( ( V_2 -> V_15 & V_16 ) == V_17 )
? ( ( T_3 ) V_21 << 32 ) : 0 ;
V_11 -> V_22 = F_9 ( V_2 , V_14 | V_20 , 64 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_10 * V_11 , T_2 V_23 )
{
T_3 V_14 ;
V_14 = ( ( V_2 -> V_15 & V_16 ) == V_24 )
? V_8 : 0 ;
V_11 -> V_25 = F_9 ( V_2 , V_14 | V_23 , 64 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
T_3 V_14 ;
V_14 = ( ( V_2 -> V_15 & V_16 ) == V_24 )
? V_8 : 0 ;
V_27 -> V_11 . V_25 = F_9 ( V_2 ,
F_14 ( V_2 , V_27 -> V_11 . V_25 , 64 ) | V_28
| V_14 , 64 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , 0 , 32 ) ;
switch ( V_2 -> V_15 & V_16 ) {
case V_17 :
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_30
| V_31 | V_32 , 32 ) ;
break;
case V_24 :
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_33
| V_34 , 32 ) ;
break;
}
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_5 = F_3 ( V_2 ) ;
return ( ! ( V_5 & V_35 ) ) || ( V_5 & V_36 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_37 ;
V_37 = F_4 ( V_2 , & V_2 -> V_4 -> V_29 , 32 ) ;
if ( V_2 -> V_15 & V_38 ) {
F_2 ( V_2 , & V_2 -> V_4 -> V_9 , 0 , 32 ) ;
V_37 |= V_39 ;
} else {
V_37 &= ~ V_39 ;
}
if ( V_2 -> V_15 & V_40 ) {
V_37 |= V_41 ;
} else {
V_37 &= ~ V_41 ;
V_37 |= V_42 ;
}
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_37 ;
int V_43 ;
V_37 = F_4 ( V_2 , & V_2 -> V_4 -> V_29 , 32 ) ;
if ( ( V_2 -> V_15 & V_16 ) == V_17 ) {
V_37 |= V_44 ;
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
V_37 &= ~ V_44 ;
}
V_37 &= ~ ( V_42 | V_41 ) ;
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
for ( V_43 = 0 ; V_43 < 100 ; V_43 ++ ) {
if ( F_16 ( V_2 ) )
return;
F_19 ( 10 ) ;
}
if ( ! F_16 ( V_2 ) )
F_20 ( V_2 , L_1 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_45 )
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
V_37 |= V_46 | ( F_22 ( V_45 ) << 14 ) ;
break;
}
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_45 )
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
V_37 |= V_47 | ( F_22 ( V_45 ) << 16 ) ;
break;
}
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_45 )
{
T_1 V_37 ;
F_25 ( V_45 > 1024 ) ;
V_37 = F_4 ( V_2 , & V_2 -> V_4 -> V_29 , 32 ) ;
V_37 |= ( F_22 ( V_45 ) << 24 ) & 0x0f000000 ;
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_48 )
{
if ( V_48 )
V_2 -> V_15 |= V_38 ;
else
V_2 -> V_15 &= ~ V_38 ;
}
static void F_27 ( struct V_1 * V_2 , int V_48 )
{
if ( V_48 )
V_2 -> V_15 |= V_40 ;
else
V_2 -> V_15 &= ~ V_40 ;
}
static void F_28 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_26 * V_49 = F_29 ( V_2 -> V_50 . V_51 ) ;
if ( F_30 ( & V_2 -> V_50 ) )
goto V_52;
F_12 ( V_2 , & V_49 -> V_11 , V_27 -> V_53 . V_54 ) ;
V_52:
F_31 ( & V_27 -> V_55 , & V_2 -> V_50 ) ;
}
static T_4 F_32 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_33 ( V_57 -> V_2 ) ;
struct V_26 * V_27 = F_34 ( V_57 ) ;
struct V_26 * V_58 ;
unsigned long V_59 ;
T_4 V_60 = - V_61 ;
F_35 ( & V_2 -> V_62 , V_59 ) ;
F_36 (child, &desc->tx_list, node) {
V_60 = F_37 ( & V_58 -> V_53 ) ;
}
F_28 ( V_2 , V_27 ) ;
F_38 ( & V_2 -> V_62 , V_59 ) ;
return V_60 ;
}
static struct V_26 * F_39 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
T_2 V_63 ;
V_27 = F_40 ( V_2 -> V_64 , V_65 , & V_63 ) ;
if ( ! V_27 ) {
F_41 ( V_2 , L_2 ) ;
return NULL ;
}
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
F_42 ( & V_27 -> V_55 ) ;
F_43 ( & V_27 -> V_53 , & V_2 -> V_66 ) ;
V_27 -> V_53 . V_67 = F_32 ;
V_27 -> V_53 . V_54 = V_63 ;
#ifdef F_44
F_41 ( V_2 , L_3 , V_27 ) ;
#endif
return V_27 ;
}
static int F_45 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_33 ( V_69 ) ;
if ( V_2 -> V_64 )
return 1 ;
V_2 -> V_64 = F_46 ( V_2 -> V_70 , V_2 -> V_71 ,
sizeof( struct V_26 ) ,
F_47 ( struct V_26 ) , 0 ) ;
if ( ! V_2 -> V_64 ) {
F_20 ( V_2 , L_4 ) ;
return - V_72 ;
}
return 1 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_26 * V_27 , * V_75 ;
F_49 (desc, _desc, list, node) {
F_50 ( & V_27 -> V_76 ) ;
#ifdef F_44
F_41 ( V_2 , L_5 , V_27 ) ;
#endif
F_51 ( V_2 -> V_64 , V_27 , V_27 -> V_53 . V_54 ) ;
}
}
static void F_52 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_26 * V_27 , * V_75 ;
F_53 (desc, _desc, list, node) {
F_50 ( & V_27 -> V_76 ) ;
#ifdef F_44
F_41 ( V_2 , L_5 , V_27 ) ;
#endif
F_51 ( V_2 -> V_64 , V_27 , V_27 -> V_53 . V_54 ) ;
}
}
static void F_54 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_33 ( V_69 ) ;
unsigned long V_59 ;
F_41 ( V_2 , L_6 ) ;
F_35 ( & V_2 -> V_62 , V_59 ) ;
F_48 ( V_2 , & V_2 -> V_50 ) ;
F_48 ( V_2 , & V_2 -> V_77 ) ;
F_38 ( & V_2 -> V_62 , V_59 ) ;
F_55 ( V_2 -> V_64 ) ;
V_2 -> V_64 = NULL ;
}
static struct V_56 *
F_56 ( struct V_68 * V_69 , unsigned long V_59 )
{
struct V_1 * V_2 ;
struct V_26 * V_78 ;
if ( ! V_69 )
return NULL ;
V_2 = F_33 ( V_69 ) ;
V_78 = F_39 ( V_2 ) ;
if ( ! V_78 ) {
F_20 ( V_2 , L_7 , V_79 ) ;
return NULL ;
}
V_78 -> V_53 . V_60 = - V_80 ;
V_78 -> V_53 . V_59 = V_59 ;
F_57 ( & V_78 -> V_76 , & V_78 -> V_55 ) ;
F_13 ( V_2 , V_78 ) ;
return & V_78 -> V_53 ;
}
static struct V_56 *
F_58 ( struct V_68 * V_69 ,
T_2 V_81 , T_2 V_82 ,
T_5 V_83 , unsigned long V_59 )
{
struct V_1 * V_2 ;
struct V_26 * V_84 = NULL , * V_51 = NULL , * V_78 ;
T_5 V_85 ;
if ( ! V_69 )
return NULL ;
if ( ! V_83 )
return NULL ;
V_2 = F_33 ( V_69 ) ;
do {
V_78 = F_39 ( V_2 ) ;
if ( ! V_78 ) {
F_20 ( V_2 , L_7 , V_79 ) ;
goto V_86;
}
V_85 = F_59 ( V_83 , ( T_5 ) V_87 ) ;
F_8 ( V_2 , & V_78 -> V_11 , V_85 ) ;
F_10 ( V_2 , & V_78 -> V_11 , V_82 ) ;
F_11 ( V_2 , & V_78 -> V_11 , V_81 ) ;
if ( ! V_84 )
V_84 = V_78 ;
else
F_12 ( V_2 , & V_51 -> V_11 , V_78 -> V_53 . V_54 ) ;
V_78 -> V_53 . V_60 = 0 ;
F_60 ( & V_78 -> V_53 ) ;
V_51 = V_78 ;
V_83 -= V_85 ;
V_82 += V_85 ;
V_81 += V_85 ;
F_57 ( & V_78 -> V_76 , & V_84 -> V_55 ) ;
} while ( V_83 );
V_78 -> V_53 . V_59 = V_59 ;
V_78 -> V_53 . V_60 = - V_80 ;
F_13 ( V_2 , V_78 ) ;
return & V_84 -> V_53 ;
V_86:
if ( ! V_84 )
return NULL ;
F_52 ( V_2 , & V_84 -> V_55 ) ;
return NULL ;
}
static struct V_56 * F_61 ( struct V_68 * V_69 ,
struct V_88 * V_89 , unsigned int V_90 ,
struct V_88 * V_91 , unsigned int V_92 ,
unsigned long V_59 )
{
struct V_26 * V_84 = NULL , * V_51 = NULL , * V_78 = NULL ;
struct V_1 * V_2 = F_33 ( V_69 ) ;
T_5 V_93 , V_94 ;
T_2 V_20 , V_13 ;
T_5 V_83 ;
if ( V_90 == 0 || V_92 == 0 )
return NULL ;
if ( V_89 == NULL || V_91 == NULL )
return NULL ;
V_93 = F_62 ( V_89 ) ;
V_94 = F_62 ( V_91 ) ;
while ( true ) {
V_83 = F_63 ( T_5 , V_94 , V_93 ) ;
V_83 = F_63 ( T_5 , V_83 , V_87 ) ;
if ( V_83 == 0 )
goto V_95;
V_20 = F_64 ( V_89 ) + F_62 ( V_89 ) - V_93 ;
V_13 = F_64 ( V_91 ) + F_62 ( V_91 ) - V_94 ;
V_78 = F_39 ( V_2 ) ;
if ( ! V_78 ) {
F_20 ( V_2 , L_7 , V_79 ) ;
goto V_86;
}
F_8 ( V_2 , & V_78 -> V_11 , V_83 ) ;
F_10 ( V_2 , & V_78 -> V_11 , V_13 ) ;
F_11 ( V_2 , & V_78 -> V_11 , V_20 ) ;
if ( ! V_84 )
V_84 = V_78 ;
else
F_12 ( V_2 , & V_51 -> V_11 , V_78 -> V_53 . V_54 ) ;
V_78 -> V_53 . V_60 = 0 ;
F_60 ( & V_78 -> V_53 ) ;
V_51 = V_78 ;
F_57 ( & V_78 -> V_76 , & V_84 -> V_55 ) ;
V_93 -= V_83 ;
V_94 -= V_83 ;
V_95:
if ( V_93 == 0 ) {
if ( V_90 == 0 )
break;
V_89 = F_65 ( V_89 ) ;
if ( V_89 == NULL )
break;
V_90 -- ;
V_93 = F_62 ( V_89 ) ;
}
if ( V_94 == 0 ) {
if ( V_92 == 0 )
break;
V_91 = F_65 ( V_91 ) ;
if ( V_91 == NULL )
break;
V_92 -- ;
V_94 = F_62 ( V_91 ) ;
}
}
V_78 -> V_53 . V_59 = V_59 ;
V_78 -> V_53 . V_60 = - V_80 ;
F_13 ( V_2 , V_78 ) ;
return & V_84 -> V_53 ;
V_86:
if ( ! V_84 )
return NULL ;
F_52 ( V_2 , & V_84 -> V_55 ) ;
return NULL ;
}
static struct V_56 * F_66 (
struct V_68 * V_69 , struct V_88 * V_96 , unsigned int V_97 ,
enum V_98 V_99 , unsigned long V_59 ,
void * V_100 )
{
return NULL ;
}
static int F_67 ( struct V_68 * V_69 ,
enum V_101 V_102 , unsigned long V_103 )
{
struct V_104 * V_105 ;
struct V_1 * V_2 ;
unsigned long V_59 ;
int V_45 ;
if ( ! V_69 )
return - V_61 ;
V_2 = F_33 ( V_69 ) ;
switch ( V_102 ) {
case V_106 :
F_35 ( & V_2 -> V_62 , V_59 ) ;
F_18 ( V_2 ) ;
F_48 ( V_2 , & V_2 -> V_50 ) ;
F_48 ( V_2 , & V_2 -> V_77 ) ;
V_2 -> V_107 = true ;
F_38 ( & V_2 -> V_62 , V_59 ) ;
return 0 ;
case V_108 :
V_105 = (struct V_104 * ) V_103 ;
if ( ! V_2 -> V_109 )
return - V_110 ;
if ( V_105 -> V_99 == V_111 )
V_45 = V_105 -> V_112 * V_105 -> V_113 ;
else
V_45 = V_105 -> V_114 * V_105 -> V_115 ;
V_2 -> V_109 ( V_2 , V_45 ) ;
return 0 ;
case V_116 :
if ( ! V_2 -> V_117 )
return - V_110 ;
V_2 -> V_117 ( V_2 , V_103 ) ;
return 0 ;
default:
return - V_110 ;
}
return 0 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_56 * V_118 = & V_27 -> V_53 ;
if ( V_118 -> V_119 ) {
#ifdef F_44
F_41 ( V_2 , L_8 , V_27 ) ;
#endif
V_118 -> V_119 ( V_118 -> V_120 ) ;
}
F_69 ( V_118 ) ;
F_70 ( V_118 ) ;
#ifdef F_44
F_41 ( V_2 , L_5 , V_27 ) ;
#endif
F_51 ( V_2 -> V_64 , V_27 , V_118 -> V_54 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
if ( F_30 ( & V_2 -> V_50 ) ) {
F_41 ( V_2 , L_9 ) ;
return;
}
if ( ! V_2 -> V_107 ) {
F_41 ( V_2 , L_10 ) ;
return;
}
F_41 ( V_2 , L_11 ) ;
V_27 = F_72 ( & V_2 -> V_50 , struct V_26 , V_76 ) ;
F_31 ( & V_2 -> V_50 , & V_2 -> V_77 ) ;
if ( ( V_2 -> V_15 & V_16 ) == V_17 ) {
T_1 V_37 ;
V_37 = F_4 ( V_2 , & V_2 -> V_4 -> V_29 , 32 ) ;
V_37 &= ~ V_42 ;
F_2 ( V_2 , & V_2 -> V_4 -> V_29 , V_37 , 32 ) ;
}
F_5 ( V_2 , V_27 -> V_53 . V_54 ) ;
F_6 ( V_2 ) ;
F_17 ( V_2 ) ;
V_2 -> V_107 = false ;
}
static void F_73 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_33 ( V_69 ) ;
unsigned long V_59 ;
F_35 ( & V_2 -> V_62 , V_59 ) ;
F_71 ( V_2 ) ;
F_38 ( & V_2 -> V_62 , V_59 ) ;
}
static enum V_121 F_74 ( struct V_68 * V_69 ,
T_4 V_60 ,
struct V_122 * V_123 )
{
return F_75 ( V_69 , V_60 , V_123 ) ;
}
static T_6 F_76 ( int V_124 , void * V_125 )
{
struct V_1 * V_2 = V_125 ;
T_1 V_126 ;
V_126 = F_3 ( V_2 ) ;
F_1 ( V_2 , V_126 ) ;
F_41 ( V_2 , L_12 , V_126 ) ;
V_126 &= ~ ( V_35 | V_36 ) ;
if ( ! V_126 )
return V_127 ;
if ( V_126 & V_128 )
F_20 ( V_2 , L_13 ) ;
if ( V_126 & V_129 ) {
F_41 ( V_2 , L_14 ) ;
V_126 &= ~ V_129 ;
if ( F_7 ( V_2 ) != 0 )
F_20 ( V_2 , L_15 ) ;
}
if ( V_126 & V_130 ) {
F_41 ( V_2 , L_16 ) ;
V_126 &= ~ V_130 ;
}
if ( V_126 & V_131 ) {
F_41 ( V_2 , L_17 ) ;
V_126 &= ~ V_131 ;
}
if ( ! F_16 ( V_2 ) )
F_20 ( V_2 , L_18 ) ;
if ( V_126 )
F_20 ( V_2 , L_19 , V_126 ) ;
F_77 ( & V_2 -> V_132 ) ;
F_41 ( V_2 , L_20 ) ;
return V_133 ;
}
static void F_78 ( unsigned long V_125 )
{
struct V_1 * V_2 = (struct V_1 * ) V_125 ;
struct V_26 * V_27 , * V_75 ;
F_79 ( V_134 ) ;
unsigned long V_59 ;
F_41 ( V_2 , L_21 ) ;
F_35 ( & V_2 -> V_62 , V_59 ) ;
if ( ! F_30 ( & V_2 -> V_77 ) ) {
T_4 V_60 ;
V_27 = F_29 ( V_2 -> V_77 . V_51 ) ;
V_60 = V_27 -> V_53 . V_60 ;
F_80 ( & V_27 -> V_53 ) ;
F_41 ( V_2 , L_22 , V_60 ) ;
}
F_31 ( & V_2 -> V_77 , & V_134 ) ;
V_2 -> V_107 = true ;
F_71 ( V_2 ) ;
F_38 ( & V_2 -> V_62 , V_59 ) ;
F_49 (desc, _desc, &ld_cleanup, node) {
F_50 ( & V_27 -> V_76 ) ;
F_68 ( V_2 , V_27 ) ;
}
F_41 ( V_2 , L_23 ) ;
}
static T_6 F_81 ( int V_124 , void * V_125 )
{
struct V_135 * V_136 = V_125 ;
struct V_1 * V_2 ;
unsigned int V_137 = 0 ;
T_1 V_138 , V_139 ;
int V_43 ;
V_138 = ( V_136 -> V_15 & V_140 ) ? F_82 ( V_136 -> V_4 )
: F_83 ( V_136 -> V_4 ) ;
V_139 = 0xff000000 ;
F_84 ( V_136 -> V_71 , L_24 , V_138 ) ;
for ( V_43 = 0 ; V_43 < V_141 ; V_43 ++ ) {
V_2 = V_136 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_138 & V_139 ) {
F_84 ( V_136 -> V_71 , L_25 , V_2 -> V_142 ) ;
F_76 ( V_124 , V_2 ) ;
V_137 ++ ;
}
V_138 &= ~ V_139 ;
V_139 >>= 8 ;
}
return F_85 ( V_137 ) ;
}
static void F_86 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_136 -> V_124 != V_143 ) {
F_84 ( V_136 -> V_71 , L_26 ) ;
F_87 ( V_136 -> V_124 , V_136 ) ;
return;
}
for ( V_43 = 0 ; V_43 < V_141 ; V_43 ++ ) {
V_2 = V_136 -> V_2 [ V_43 ] ;
if ( V_2 && V_2 -> V_124 != V_143 ) {
F_41 ( V_2 , L_27 ) ;
F_87 ( V_2 -> V_124 , V_2 ) ;
}
}
}
static int F_88 ( struct V_135 * V_136 )
{
struct V_1 * V_2 ;
int V_144 ;
int V_43 ;
if ( V_136 -> V_124 != V_143 ) {
F_84 ( V_136 -> V_71 , L_28 ) ;
V_144 = F_89 ( V_136 -> V_124 , F_81 , V_145 ,
L_29 , V_136 ) ;
return V_144 ;
}
for ( V_43 = 0 ; V_43 < V_141 ; V_43 ++ ) {
V_2 = V_136 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_124 == V_143 ) {
F_20 ( V_2 , L_30 ) ;
V_144 = - V_146 ;
goto V_147;
}
F_41 ( V_2 , L_31 ) ;
V_144 = F_89 ( V_2 -> V_124 , F_76 , V_145 ,
L_32 , V_2 ) ;
if ( V_144 ) {
F_20 ( V_2 , L_33 ) ;
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
F_87 ( V_2 -> V_124 , V_2 ) ;
}
return V_144 ;
}
static int F_90 ( struct V_135 * V_136 ,
struct V_148 * V_76 , T_1 V_15 , const char * V_149 )
{
struct V_1 * V_2 ;
struct V_150 V_151 ;
int V_152 ;
V_2 = F_91 ( sizeof( * V_2 ) , V_153 ) ;
if ( ! V_2 ) {
F_92 ( V_136 -> V_71 , L_34 ) ;
V_152 = - V_72 ;
goto V_154;
}
V_2 -> V_4 = F_93 ( V_76 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_92 ( V_136 -> V_71 , L_35 ) ;
V_152 = - V_72 ;
goto V_155;
}
V_152 = F_94 ( V_76 , 0 , & V_151 ) ;
if ( V_152 ) {
F_92 ( V_136 -> V_71 , L_36 ) ;
goto V_156;
}
V_2 -> V_15 = V_15 ;
if ( ! V_136 -> V_15 )
V_136 -> V_15 = V_2 -> V_15 ;
F_95 ( V_136 -> V_15 != V_2 -> V_15 ) ;
V_2 -> V_71 = V_136 -> V_71 ;
V_2 -> V_142 = ( V_151 . V_157 & 0xfff ) < 0x300 ?
( ( V_151 . V_157 - 0x100 ) & 0xfff ) >> 7 :
( ( V_151 . V_157 - 0x200 ) & 0xfff ) >> 7 ;
if ( V_2 -> V_142 >= V_141 ) {
F_92 ( V_136 -> V_71 , L_37 ) ;
V_152 = - V_61 ;
goto V_156;
}
V_136 -> V_2 [ V_2 -> V_142 ] = V_2 ;
F_96 ( & V_2 -> V_132 , F_78 , ( unsigned long ) V_2 ) ;
snprintf ( V_2 -> V_70 , sizeof( V_2 -> V_70 ) , L_38 , V_2 -> V_142 ) ;
F_15 ( V_2 ) ;
F_5 ( V_2 , 0 ) ;
switch ( V_2 -> V_15 & V_16 ) {
case V_17 :
V_2 -> V_158 = F_26 ;
case V_24 :
V_2 -> V_117 = F_27 ;
V_2 -> V_159 = F_21 ;
V_2 -> V_160 = F_23 ;
V_2 -> V_109 = F_24 ;
}
F_97 ( & V_2 -> V_62 ) ;
F_42 ( & V_2 -> V_50 ) ;
F_42 ( & V_2 -> V_77 ) ;
V_2 -> V_107 = true ;
V_2 -> V_66 . V_161 = & V_136 -> V_66 ;
F_98 ( & V_2 -> V_66 ) ;
V_2 -> V_124 = F_99 ( V_76 , 0 ) ;
F_57 ( & V_2 -> V_66 . V_148 , & V_136 -> V_66 . V_162 ) ;
V_136 -> V_66 . V_163 ++ ;
F_100 ( V_136 -> V_71 , L_39 , V_2 -> V_142 , V_149 ,
V_2 -> V_124 != V_143 ? V_2 -> V_124 : V_136 -> V_124 ) ;
return 0 ;
V_156:
F_101 ( V_2 -> V_4 ) ;
V_155:
F_102 ( V_2 ) ;
V_154:
return V_152 ;
}
static void F_103 ( struct V_1 * V_2 )
{
F_104 ( V_2 -> V_124 ) ;
F_50 ( & V_2 -> V_66 . V_148 ) ;
F_101 ( V_2 -> V_4 ) ;
F_102 ( V_2 ) ;
}
static int F_105 ( struct V_164 * V_165 )
{
struct V_135 * V_136 ;
struct V_148 * V_58 ;
int V_152 ;
V_136 = F_91 ( sizeof( * V_136 ) , V_153 ) ;
if ( ! V_136 ) {
F_92 ( & V_165 -> V_71 , L_40 ) ;
V_152 = - V_72 ;
goto V_154;
}
V_136 -> V_71 = & V_165 -> V_71 ;
F_42 ( & V_136 -> V_66 . V_162 ) ;
V_136 -> V_4 = F_93 ( V_165 -> V_71 . V_166 , 0 ) ;
if ( ! V_136 -> V_4 ) {
F_92 ( & V_165 -> V_71 , L_35 ) ;
V_152 = - V_72 ;
goto V_167;
}
V_136 -> V_124 = F_99 ( V_165 -> V_71 . V_166 , 0 ) ;
F_106 ( V_168 , V_136 -> V_66 . V_169 ) ;
F_106 ( V_170 , V_136 -> V_66 . V_169 ) ;
F_106 ( V_171 , V_136 -> V_66 . V_169 ) ;
F_106 ( V_172 , V_136 -> V_66 . V_169 ) ;
V_136 -> V_66 . V_173 = F_45 ;
V_136 -> V_66 . V_174 = F_54 ;
V_136 -> V_66 . V_175 = F_56 ;
V_136 -> V_66 . V_176 = F_58 ;
V_136 -> V_66 . V_177 = F_61 ;
V_136 -> V_66 . V_178 = F_74 ;
V_136 -> V_66 . V_179 = F_73 ;
V_136 -> V_66 . V_180 = F_66 ;
V_136 -> V_66 . V_181 = F_67 ;
V_136 -> V_66 . V_71 = & V_165 -> V_71 ;
F_107 ( & ( V_165 -> V_71 ) , F_108 ( 36 ) ) ;
F_109 ( V_165 , V_136 ) ;
F_110 (op->dev.of_node, child) {
if ( F_111 ( V_58 , L_41 ) ) {
F_90 ( V_136 , V_58 ,
V_17 | V_140 ,
L_41 ) ;
}
if ( F_111 ( V_58 , L_42 ) ) {
F_90 ( V_136 , V_58 ,
V_24 | V_182 ,
L_42 ) ;
}
}
V_152 = F_88 ( V_136 ) ;
if ( V_152 ) {
F_92 ( V_136 -> V_71 , L_43 ) ;
goto V_167;
}
F_112 ( & V_136 -> V_66 ) ;
return 0 ;
V_167:
F_104 ( V_136 -> V_124 ) ;
F_102 ( V_136 ) ;
V_154:
return V_152 ;
}
static int F_113 ( struct V_164 * V_165 )
{
struct V_135 * V_136 ;
unsigned int V_43 ;
V_136 = F_114 ( V_165 ) ;
F_115 ( & V_136 -> V_66 ) ;
F_86 ( V_136 ) ;
for ( V_43 = 0 ; V_43 < V_141 ; V_43 ++ ) {
if ( V_136 -> V_2 [ V_43 ] )
F_103 ( V_136 -> V_2 [ V_43 ] ) ;
}
F_101 ( V_136 -> V_4 ) ;
F_102 ( V_136 ) ;
return 0 ;
}
static T_7 int F_116 ( void )
{
F_117 ( L_44 ) ;
return F_118 ( & V_183 ) ;
}
static void T_8 F_119 ( void )
{
F_120 ( & V_183 ) ;
}
