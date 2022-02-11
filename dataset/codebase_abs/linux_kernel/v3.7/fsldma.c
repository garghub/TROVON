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
F_39 (child, &desc->tx_list, node) {
V_60 = F_40 ( & V_58 -> V_53 ) ;
}
F_31 ( V_2 , V_14 ) ;
F_41 ( & V_2 -> V_61 , V_59 ) ;
return V_60 ;
}
static struct V_13 * F_42 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
T_2 V_62 ;
V_14 = F_43 ( V_2 -> V_63 , V_64 , & V_62 ) ;
if ( ! V_14 ) {
F_44 ( V_2 , L_2 ) ;
return NULL ;
}
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
F_45 ( & V_14 -> V_55 ) ;
F_46 ( & V_14 -> V_53 , & V_2 -> V_65 ) ;
V_14 -> V_53 . V_66 = F_35 ;
V_14 -> V_53 . V_54 = V_62 ;
#ifdef F_47
F_44 ( V_2 , L_3 , V_14 ) ;
#endif
return V_14 ;
}
static int F_48 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
if ( V_2 -> V_63 )
return 1 ;
V_2 -> V_63 = F_49 ( V_2 -> V_69 , V_2 -> V_70 ,
sizeof( struct V_13 ) ,
F_50 ( struct V_13 ) , 0 ) ;
if ( ! V_2 -> V_63 ) {
F_23 ( V_2 , L_4 ) ;
return - V_71 ;
}
return 1 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
struct V_13 * V_14 , * V_74 ;
F_52 (desc, _desc, list, node) {
F_53 ( & V_14 -> V_75 ) ;
#ifdef F_47
F_44 ( V_2 , L_5 , V_14 ) ;
#endif
F_54 ( V_2 -> V_63 , V_14 , V_14 -> V_53 . V_54 ) ;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
struct V_13 * V_14 , * V_74 ;
F_56 (desc, _desc, list, node) {
F_53 ( & V_14 -> V_75 ) ;
#ifdef F_47
F_44 ( V_2 , L_5 , V_14 ) ;
#endif
F_54 ( V_2 -> V_63 , V_14 , V_14 -> V_53 . V_54 ) ;
}
}
static void F_57 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
unsigned long V_59 ;
F_44 ( V_2 , L_6 ) ;
F_38 ( & V_2 -> V_61 , V_59 ) ;
F_51 ( V_2 , & V_2 -> V_50 ) ;
F_51 ( V_2 , & V_2 -> V_76 ) ;
F_41 ( & V_2 -> V_61 , V_59 ) ;
F_58 ( V_2 -> V_63 ) ;
V_2 -> V_63 = NULL ;
}
static struct V_56 *
F_59 ( struct V_67 * V_68 , unsigned long V_59 )
{
struct V_1 * V_2 ;
struct V_13 * V_77 ;
if ( ! V_68 )
return NULL ;
V_2 = F_36 ( V_68 ) ;
V_77 = F_42 ( V_2 ) ;
if ( ! V_77 ) {
F_23 ( V_2 , L_7 , V_78 ) ;
return NULL ;
}
V_77 -> V_53 . V_60 = - V_79 ;
V_77 -> V_53 . V_59 = V_59 ;
F_60 ( & V_77 -> V_75 , & V_77 -> V_55 ) ;
F_17 ( V_2 , V_77 ) ;
return & V_77 -> V_53 ;
}
static struct V_56 *
F_61 ( struct V_67 * V_68 ,
T_2 V_80 , T_2 V_81 ,
T_5 V_82 , unsigned long V_59 )
{
struct V_1 * V_2 ;
struct V_13 * V_83 = NULL , * V_51 = NULL , * V_77 ;
T_5 V_84 ;
if ( ! V_68 )
return NULL ;
if ( ! V_82 )
return NULL ;
V_2 = F_36 ( V_68 ) ;
do {
V_77 = F_42 ( V_2 ) ;
if ( ! V_77 ) {
F_23 ( V_2 , L_7 , V_78 ) ;
goto V_85;
}
V_84 = F_62 ( V_82 , ( T_5 ) V_86 ) ;
F_8 ( V_2 , & V_77 -> V_11 , V_84 ) ;
F_12 ( V_2 , & V_77 -> V_11 , V_81 ) ;
F_14 ( V_2 , & V_77 -> V_11 , V_80 ) ;
if ( ! V_83 )
V_83 = V_77 ;
else
F_16 ( V_2 , & V_51 -> V_11 , V_77 -> V_53 . V_54 ) ;
V_77 -> V_53 . V_60 = 0 ;
F_63 ( & V_77 -> V_53 ) ;
V_51 = V_77 ;
V_82 -= V_84 ;
V_81 += V_84 ;
V_80 += V_84 ;
F_60 ( & V_77 -> V_75 , & V_83 -> V_55 ) ;
} while ( V_82 );
V_77 -> V_53 . V_59 = V_59 ;
V_77 -> V_53 . V_60 = - V_79 ;
F_17 ( V_2 , V_77 ) ;
return & V_83 -> V_53 ;
V_85:
if ( ! V_83 )
return NULL ;
F_55 ( V_2 , & V_83 -> V_55 ) ;
return NULL ;
}
static struct V_56 * F_64 ( struct V_67 * V_68 ,
struct V_87 * V_88 , unsigned int V_89 ,
struct V_87 * V_90 , unsigned int V_91 ,
unsigned long V_59 )
{
struct V_13 * V_83 = NULL , * V_51 = NULL , * V_77 = NULL ;
struct V_1 * V_2 = F_36 ( V_68 ) ;
T_5 V_92 , V_93 ;
T_2 V_22 , V_15 ;
T_5 V_82 ;
if ( V_89 == 0 || V_91 == 0 )
return NULL ;
if ( V_88 == NULL || V_90 == NULL )
return NULL ;
V_92 = F_65 ( V_88 ) ;
V_93 = F_65 ( V_90 ) ;
while ( true ) {
V_82 = F_66 ( T_5 , V_93 , V_92 ) ;
V_82 = F_66 ( T_5 , V_82 , V_86 ) ;
if ( V_82 == 0 )
goto V_94;
V_22 = F_67 ( V_88 ) + F_65 ( V_88 ) - V_92 ;
V_15 = F_67 ( V_90 ) + F_65 ( V_90 ) - V_93 ;
V_77 = F_42 ( V_2 ) ;
if ( ! V_77 ) {
F_23 ( V_2 , L_7 , V_78 ) ;
goto V_85;
}
F_8 ( V_2 , & V_77 -> V_11 , V_82 ) ;
F_12 ( V_2 , & V_77 -> V_11 , V_15 ) ;
F_14 ( V_2 , & V_77 -> V_11 , V_22 ) ;
if ( ! V_83 )
V_83 = V_77 ;
else
F_16 ( V_2 , & V_51 -> V_11 , V_77 -> V_53 . V_54 ) ;
V_77 -> V_53 . V_60 = 0 ;
F_63 ( & V_77 -> V_53 ) ;
V_51 = V_77 ;
F_60 ( & V_77 -> V_75 , & V_83 -> V_55 ) ;
V_92 -= V_82 ;
V_93 -= V_82 ;
V_94:
if ( V_92 == 0 ) {
if ( V_89 == 0 )
break;
V_88 = F_68 ( V_88 ) ;
if ( V_88 == NULL )
break;
V_89 -- ;
V_92 = F_65 ( V_88 ) ;
}
if ( V_93 == 0 ) {
if ( V_91 == 0 )
break;
V_90 = F_68 ( V_90 ) ;
if ( V_90 == NULL )
break;
V_91 -- ;
V_93 = F_65 ( V_90 ) ;
}
}
V_77 -> V_53 . V_59 = V_59 ;
V_77 -> V_53 . V_60 = - V_79 ;
F_17 ( V_2 , V_77 ) ;
return & V_83 -> V_53 ;
V_85:
if ( ! V_83 )
return NULL ;
F_55 ( V_2 , & V_83 -> V_55 ) ;
return NULL ;
}
static struct V_56 * F_69 (
struct V_67 * V_68 , struct V_87 * V_95 , unsigned int V_96 ,
enum V_97 V_98 , unsigned long V_59 ,
void * V_99 )
{
return NULL ;
}
static int F_70 ( struct V_67 * V_68 ,
enum V_100 V_101 , unsigned long V_102 )
{
struct V_103 * V_104 ;
struct V_1 * V_2 ;
unsigned long V_59 ;
int V_45 ;
if ( ! V_68 )
return - V_105 ;
V_2 = F_36 ( V_68 ) ;
switch ( V_101 ) {
case V_106 :
F_38 ( & V_2 -> V_61 , V_59 ) ;
F_21 ( V_2 ) ;
F_51 ( V_2 , & V_2 -> V_50 ) ;
F_51 ( V_2 , & V_2 -> V_76 ) ;
V_2 -> V_107 = true ;
F_41 ( & V_2 -> V_61 , V_59 ) ;
return 0 ;
case V_108 :
V_104 = (struct V_103 * ) V_102 ;
if ( ! V_2 -> V_109 )
return - V_110 ;
if ( V_104 -> V_98 == V_111 )
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
static void F_71 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_56 * V_118 = & V_14 -> V_53 ;
struct V_119 * V_70 = V_2 -> V_65 . V_119 -> V_70 ;
T_2 V_15 = F_13 ( V_2 , V_14 ) ;
T_2 V_22 = F_15 ( V_2 , V_14 ) ;
T_1 V_82 = F_10 ( V_2 , V_14 ) ;
if ( V_118 -> V_120 ) {
#ifdef F_47
F_44 ( V_2 , L_8 , V_14 ) ;
#endif
V_118 -> V_120 ( V_118 -> V_121 ) ;
}
F_72 ( V_118 ) ;
if ( ! ( V_118 -> V_59 & V_122 ) ) {
if ( V_118 -> V_59 & V_123 )
F_73 ( V_70 , V_22 , V_82 , V_124 ) ;
else
F_74 ( V_70 , V_22 , V_82 , V_124 ) ;
}
if ( ! ( V_118 -> V_59 & V_125 ) ) {
if ( V_118 -> V_59 & V_126 )
F_73 ( V_70 , V_15 , V_82 , V_127 ) ;
else
F_74 ( V_70 , V_15 , V_82 , V_127 ) ;
}
#ifdef F_47
F_44 ( V_2 , L_5 , V_14 ) ;
#endif
F_54 ( V_2 -> V_63 , V_14 , V_118 -> V_54 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
if ( F_33 ( & V_2 -> V_50 ) ) {
F_44 ( V_2 , L_9 ) ;
return;
}
if ( ! V_2 -> V_107 ) {
F_44 ( V_2 , L_10 ) ;
return;
}
F_44 ( V_2 , L_11 ) ;
V_14 = F_76 ( & V_2 -> V_50 , struct V_13 , V_75 ) ;
F_34 ( & V_2 -> V_50 , & V_2 -> V_76 ) ;
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
static void F_77 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
unsigned long V_59 ;
F_38 ( & V_2 -> V_61 , V_59 ) ;
F_75 ( V_2 ) ;
F_41 ( & V_2 -> V_61 , V_59 ) ;
}
static enum V_128 F_78 ( struct V_67 * V_68 ,
T_4 V_60 ,
struct V_129 * V_130 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
enum V_128 V_131 ;
unsigned long V_59 ;
F_38 ( & V_2 -> V_61 , V_59 ) ;
V_131 = F_79 ( V_68 , V_60 , V_130 ) ;
F_41 ( & V_2 -> V_61 , V_59 ) ;
return V_131 ;
}
static T_6 F_80 ( int V_132 , void * V_133 )
{
struct V_1 * V_2 = V_133 ;
T_1 V_134 ;
V_134 = F_3 ( V_2 ) ;
F_1 ( V_2 , V_134 ) ;
F_44 ( V_2 , L_12 , V_134 ) ;
V_134 &= ~ ( V_35 | V_36 ) ;
if ( ! V_134 )
return V_135 ;
if ( V_134 & V_136 )
F_23 ( V_2 , L_13 ) ;
if ( V_134 & V_137 ) {
F_44 ( V_2 , L_14 ) ;
V_134 &= ~ V_137 ;
if ( F_7 ( V_2 ) != 0 )
F_23 ( V_2 , L_15 ) ;
}
if ( V_134 & V_138 ) {
F_44 ( V_2 , L_16 ) ;
V_134 &= ~ V_138 ;
}
if ( V_134 & V_139 ) {
F_44 ( V_2 , L_17 ) ;
V_134 &= ~ V_139 ;
}
if ( ! F_19 ( V_2 ) )
F_23 ( V_2 , L_18 ) ;
if ( V_134 )
F_23 ( V_2 , L_19 , V_134 ) ;
F_81 ( & V_2 -> V_140 ) ;
F_44 ( V_2 , L_20 ) ;
return V_141 ;
}
static void F_82 ( unsigned long V_133 )
{
struct V_1 * V_2 = (struct V_1 * ) V_133 ;
struct V_13 * V_14 , * V_74 ;
F_83 ( V_142 ) ;
unsigned long V_59 ;
F_44 ( V_2 , L_21 ) ;
F_38 ( & V_2 -> V_61 , V_59 ) ;
if ( ! F_33 ( & V_2 -> V_76 ) ) {
T_4 V_60 ;
V_14 = F_32 ( V_2 -> V_76 . V_51 ) ;
V_60 = V_14 -> V_53 . V_60 ;
F_84 ( & V_14 -> V_53 ) ;
F_44 ( V_2 , L_22 , V_60 ) ;
}
F_34 ( & V_2 -> V_76 , & V_142 ) ;
V_2 -> V_107 = true ;
F_75 ( V_2 ) ;
F_41 ( & V_2 -> V_61 , V_59 ) ;
F_52 (desc, _desc, &ld_cleanup, node) {
F_53 ( & V_14 -> V_75 ) ;
F_71 ( V_2 , V_14 ) ;
}
F_44 ( V_2 , L_23 ) ;
}
static T_6 F_85 ( int V_132 , void * V_133 )
{
struct V_143 * V_144 = V_133 ;
struct V_1 * V_2 ;
unsigned int V_145 = 0 ;
T_1 V_146 , V_147 ;
int V_43 ;
V_146 = ( V_144 -> V_17 & V_148 ) ? F_86 ( V_144 -> V_4 )
: F_87 ( V_144 -> V_4 ) ;
V_147 = 0xff000000 ;
F_88 ( V_144 -> V_70 , L_24 , V_146 ) ;
for ( V_43 = 0 ; V_43 < V_149 ; V_43 ++ ) {
V_2 = V_144 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_146 & V_147 ) {
F_88 ( V_144 -> V_70 , L_25 , V_2 -> V_150 ) ;
F_80 ( V_132 , V_2 ) ;
V_145 ++ ;
}
V_146 &= ~ V_147 ;
V_147 >>= 8 ;
}
return F_89 ( V_145 ) ;
}
static void F_90 ( struct V_143 * V_144 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_144 -> V_132 != V_151 ) {
F_88 ( V_144 -> V_70 , L_26 ) ;
F_91 ( V_144 -> V_132 , V_144 ) ;
return;
}
for ( V_43 = 0 ; V_43 < V_149 ; V_43 ++ ) {
V_2 = V_144 -> V_2 [ V_43 ] ;
if ( V_2 && V_2 -> V_132 != V_151 ) {
F_44 ( V_2 , L_27 ) ;
F_91 ( V_2 -> V_132 , V_2 ) ;
}
}
}
static int F_92 ( struct V_143 * V_144 )
{
struct V_1 * V_2 ;
int V_131 ;
int V_43 ;
if ( V_144 -> V_132 != V_151 ) {
F_88 ( V_144 -> V_70 , L_28 ) ;
V_131 = F_93 ( V_144 -> V_132 , F_85 , V_152 ,
L_29 , V_144 ) ;
return V_131 ;
}
for ( V_43 = 0 ; V_43 < V_149 ; V_43 ++ ) {
V_2 = V_144 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_132 == V_151 ) {
F_23 ( V_2 , L_30 ) ;
V_131 = - V_153 ;
goto V_154;
}
F_44 ( V_2 , L_31 ) ;
V_131 = F_93 ( V_2 -> V_132 , F_80 , V_152 ,
L_32 , V_2 ) ;
if ( V_131 ) {
F_23 ( V_2 , L_33 ) ;
goto V_154;
}
}
return 0 ;
V_154:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_144 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_132 == V_151 )
continue;
F_91 ( V_2 -> V_132 , V_2 ) ;
}
return V_131 ;
}
static int T_7 F_94 ( struct V_143 * V_144 ,
struct V_155 * V_75 , T_1 V_17 , const char * V_156 )
{
struct V_1 * V_2 ;
struct V_157 V_158 ;
int V_159 ;
V_2 = F_95 ( sizeof( * V_2 ) , V_160 ) ;
if ( ! V_2 ) {
F_96 ( V_144 -> V_70 , L_34 ) ;
V_159 = - V_71 ;
goto V_161;
}
V_2 -> V_4 = F_97 ( V_75 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_96 ( V_144 -> V_70 , L_35 ) ;
V_159 = - V_71 ;
goto V_162;
}
V_159 = F_98 ( V_75 , 0 , & V_158 ) ;
if ( V_159 ) {
F_96 ( V_144 -> V_70 , L_36 ) ;
goto V_163;
}
V_2 -> V_17 = V_17 ;
if ( ! V_144 -> V_17 )
V_144 -> V_17 = V_2 -> V_17 ;
F_99 ( V_144 -> V_17 != V_2 -> V_17 ) ;
V_2 -> V_70 = V_144 -> V_70 ;
V_2 -> V_150 = ( ( V_158 . V_164 - 0x100 ) & 0xfff ) >> 7 ;
if ( V_2 -> V_150 >= V_149 ) {
F_96 ( V_144 -> V_70 , L_37 ) ;
V_159 = - V_105 ;
goto V_163;
}
V_144 -> V_2 [ V_2 -> V_150 ] = V_2 ;
F_100 ( & V_2 -> V_140 , F_82 , ( unsigned long ) V_2 ) ;
snprintf ( V_2 -> V_69 , sizeof( V_2 -> V_69 ) , L_38 , V_2 -> V_150 ) ;
F_18 ( V_2 ) ;
F_5 ( V_2 , 0 ) ;
switch ( V_2 -> V_17 & V_18 ) {
case V_19 :
V_2 -> V_165 = F_29 ;
case V_26 :
V_2 -> V_117 = F_30 ;
V_2 -> V_166 = F_24 ;
V_2 -> V_167 = F_26 ;
V_2 -> V_109 = F_27 ;
}
F_101 ( & V_2 -> V_61 ) ;
F_45 ( & V_2 -> V_50 ) ;
F_45 ( & V_2 -> V_76 ) ;
V_2 -> V_107 = true ;
V_2 -> V_65 . V_119 = & V_144 -> V_65 ;
F_102 ( & V_2 -> V_65 ) ;
V_2 -> V_132 = F_103 ( V_75 , 0 ) ;
F_60 ( & V_2 -> V_65 . V_155 , & V_144 -> V_65 . V_168 ) ;
V_144 -> V_65 . V_169 ++ ;
F_104 ( V_144 -> V_70 , L_39 , V_2 -> V_150 , V_156 ,
V_2 -> V_132 != V_151 ? V_2 -> V_132 : V_144 -> V_132 ) ;
return 0 ;
V_163:
F_105 ( V_2 -> V_4 ) ;
V_162:
F_106 ( V_2 ) ;
V_161:
return V_159 ;
}
static void F_107 ( struct V_1 * V_2 )
{
F_108 ( V_2 -> V_132 ) ;
F_53 ( & V_2 -> V_65 . V_155 ) ;
F_105 ( V_2 -> V_4 ) ;
F_106 ( V_2 ) ;
}
static int T_7 F_109 ( struct V_170 * V_171 )
{
struct V_143 * V_144 ;
struct V_155 * V_58 ;
int V_159 ;
V_144 = F_95 ( sizeof( * V_144 ) , V_160 ) ;
if ( ! V_144 ) {
F_96 ( & V_171 -> V_70 , L_40 ) ;
V_159 = - V_71 ;
goto V_161;
}
V_144 -> V_70 = & V_171 -> V_70 ;
F_45 ( & V_144 -> V_65 . V_168 ) ;
V_144 -> V_4 = F_97 ( V_171 -> V_70 . V_172 , 0 ) ;
if ( ! V_144 -> V_4 ) {
F_96 ( & V_171 -> V_70 , L_35 ) ;
V_159 = - V_71 ;
goto V_173;
}
V_144 -> V_132 = F_103 ( V_171 -> V_70 . V_172 , 0 ) ;
F_110 ( V_174 , V_144 -> V_65 . V_175 ) ;
F_110 ( V_176 , V_144 -> V_65 . V_175 ) ;
F_110 ( V_177 , V_144 -> V_65 . V_175 ) ;
F_110 ( V_178 , V_144 -> V_65 . V_175 ) ;
V_144 -> V_65 . V_179 = F_48 ;
V_144 -> V_65 . V_180 = F_57 ;
V_144 -> V_65 . V_181 = F_59 ;
V_144 -> V_65 . V_182 = F_61 ;
V_144 -> V_65 . V_183 = F_64 ;
V_144 -> V_65 . V_184 = F_78 ;
V_144 -> V_65 . V_185 = F_77 ;
V_144 -> V_65 . V_186 = F_69 ;
V_144 -> V_65 . V_187 = F_70 ;
V_144 -> V_65 . V_70 = & V_171 -> V_70 ;
F_111 ( & ( V_171 -> V_70 ) , F_112 ( 36 ) ) ;
F_113 ( & V_171 -> V_70 , V_144 ) ;
F_114 (op->dev.of_node, child) {
if ( F_115 ( V_58 , L_41 ) ) {
F_94 ( V_144 , V_58 ,
V_19 | V_148 ,
L_41 ) ;
}
if ( F_115 ( V_58 , L_42 ) ) {
F_94 ( V_144 , V_58 ,
V_26 | V_188 ,
L_42 ) ;
}
}
V_159 = F_92 ( V_144 ) ;
if ( V_159 ) {
F_96 ( V_144 -> V_70 , L_43 ) ;
goto V_173;
}
F_116 ( & V_144 -> V_65 ) ;
return 0 ;
V_173:
F_108 ( V_144 -> V_132 ) ;
F_106 ( V_144 ) ;
V_161:
return V_159 ;
}
static int F_117 ( struct V_170 * V_171 )
{
struct V_143 * V_144 ;
unsigned int V_43 ;
V_144 = F_118 ( & V_171 -> V_70 ) ;
F_119 ( & V_144 -> V_65 ) ;
F_90 ( V_144 ) ;
for ( V_43 = 0 ; V_43 < V_149 ; V_43 ++ ) {
if ( V_144 -> V_2 [ V_43 ] )
F_107 ( V_144 -> V_2 [ V_43 ] ) ;
}
F_105 ( V_144 -> V_4 ) ;
F_113 ( & V_171 -> V_70 , NULL ) ;
F_106 ( V_144 ) ;
return 0 ;
}
static T_8 int F_120 ( void )
{
F_121 ( L_44 ) ;
return F_122 ( & V_189 ) ;
}
static void T_9 F_123 ( void )
{
F_124 ( & V_189 ) ;
}
