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
F_57 ( V_73 ) ;
}
F_58 ( V_73 ) ;
return V_74 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_47 ( & V_28 -> V_66 ) ;
if ( ! F_55 ( & V_28 -> V_56 ) ) {
F_60 ( & V_28 -> V_66 , & V_2 -> V_77 ) ;
return;
}
F_48 ( V_2 -> V_67 , V_28 , V_28 -> V_56 . V_57 ) ;
}
static void F_61 ( struct V_1 * V_2 )
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
V_28 = F_62 ( & V_2 -> V_53 , struct V_27 , V_66 ) ;
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
static void F_63 ( struct V_1 * V_2 )
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
F_59 ( V_2 , V_28 ) ;
}
F_61 ( V_2 ) ;
if ( V_62 > 0 )
V_2 -> V_70 . V_82 = V_62 ;
}
static int F_64 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
if ( V_2 -> V_67 )
return 1 ;
V_2 -> V_67 = F_65 ( V_2 -> V_83 , V_2 -> V_84 ,
sizeof( struct V_27 ) ,
F_66 ( struct V_27 ) , 0 ) ;
if ( ! V_2 -> V_67 ) {
F_23 ( V_2 , L_10 ) ;
return - V_85 ;
}
return 1 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_27 * V_28 , * V_72 ;
F_54 (desc, _desc, list, node)
F_46 ( V_2 , V_28 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_27 * V_28 , * V_72 ;
F_69 (desc, _desc, list, node)
F_46 ( V_2 , V_28 ) ;
}
static void F_70 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
F_42 ( V_2 , L_11 ) ;
F_39 ( & V_2 -> V_63 ) ;
F_63 ( V_2 ) ;
F_67 ( V_2 , & V_2 -> V_53 ) ;
F_67 ( V_2 , & V_2 -> V_79 ) ;
F_67 ( V_2 , & V_2 -> V_77 ) ;
F_43 ( & V_2 -> V_63 ) ;
F_71 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
static struct V_59 *
F_72 ( struct V_49 * V_50 ,
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
V_94 = F_73 ( V_90 , ( T_5 ) V_97 ) ;
F_11 ( V_2 , & V_93 -> V_12 , V_94 ) ;
F_13 ( V_2 , & V_93 -> V_12 , V_89 ) ;
F_14 ( V_2 , & V_93 -> V_12 , V_88 ) ;
if ( ! V_92 )
V_92 = V_93 ;
else
F_15 ( V_2 , & V_54 -> V_12 , V_93 -> V_56 . V_57 ) ;
V_93 -> V_56 . V_62 = 0 ;
F_74 ( & V_93 -> V_56 ) ;
V_54 = V_93 ;
V_90 -= V_94 ;
V_89 += V_94 ;
V_88 += V_94 ;
F_60 ( & V_93 -> V_66 , & V_92 -> V_58 ) ;
} while ( V_90 );
V_93 -> V_56 . V_91 = V_91 ;
V_93 -> V_56 . V_62 = - V_98 ;
F_16 ( V_2 , V_93 ) ;
return & V_92 -> V_56 ;
V_96:
if ( ! V_92 )
return NULL ;
F_68 ( V_2 , & V_92 -> V_58 ) ;
return NULL ;
}
static struct V_59 * F_75 ( struct V_49 * V_50 ,
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
V_104 = F_76 ( V_100 ) ;
V_105 = F_76 ( V_102 ) ;
while ( true ) {
V_90 = F_77 ( T_5 , V_105 , V_104 ) ;
V_90 = F_77 ( T_5 , V_90 , V_97 ) ;
if ( V_90 == 0 )
goto V_106;
V_21 = F_78 ( V_100 ) + F_76 ( V_100 ) - V_104 ;
V_14 = F_78 ( V_102 ) + F_76 ( V_102 ) - V_105 ;
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
F_74 ( & V_93 -> V_56 ) ;
V_54 = V_93 ;
F_60 ( & V_93 -> V_66 , & V_92 -> V_58 ) ;
V_104 -= V_90 ;
V_105 -= V_90 ;
V_106:
if ( V_104 == 0 ) {
if ( V_101 == 0 )
break;
V_100 = F_79 ( V_100 ) ;
if ( V_100 == NULL )
break;
V_101 -- ;
V_104 = F_76 ( V_100 ) ;
}
if ( V_105 == 0 ) {
if ( V_103 == 0 )
break;
V_102 = F_79 ( V_102 ) ;
if ( V_102 == NULL )
break;
V_103 -- ;
V_105 = F_76 ( V_102 ) ;
}
}
V_93 -> V_56 . V_91 = V_91 ;
V_93 -> V_56 . V_62 = - V_98 ;
F_16 ( V_2 , V_93 ) ;
return & V_92 -> V_56 ;
V_96:
if ( ! V_92 )
return NULL ;
F_68 ( V_2 , & V_92 -> V_58 ) ;
return NULL ;
}
static int F_80 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
if ( ! V_50 )
return - V_51 ;
V_2 = F_32 ( V_50 ) ;
F_39 ( & V_2 -> V_63 ) ;
F_21 ( V_2 ) ;
F_67 ( V_2 , & V_2 -> V_53 ) ;
F_67 ( V_2 , & V_2 -> V_79 ) ;
F_67 ( V_2 , & V_2 -> V_77 ) ;
V_2 -> V_78 = true ;
F_43 ( & V_2 -> V_63 ) ;
return 0 ;
}
static int F_81 ( struct V_49 * V_50 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 ;
int V_45 ;
if ( ! V_50 )
return - V_51 ;
V_2 = F_32 ( V_50 ) ;
if ( ! V_2 -> V_109 )
return - V_110 ;
if ( V_108 -> V_111 == V_112 )
V_45 = V_108 -> V_113 * V_108 -> V_114 ;
else
V_45 = V_108 -> V_115 * V_108 -> V_116 ;
V_2 -> V_109 ( V_2 , V_45 ) ;
return 0 ;
}
static void F_82 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
F_39 ( & V_2 -> V_63 ) ;
F_61 ( V_2 ) ;
F_43 ( & V_2 -> V_63 ) ;
}
static enum V_117 F_83 ( struct V_49 * V_50 ,
T_4 V_62 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
enum V_117 V_74 ;
V_74 = F_84 ( V_50 , V_62 , V_119 ) ;
if ( V_74 == V_120 )
return V_74 ;
F_39 ( & V_2 -> V_63 ) ;
F_63 ( V_2 ) ;
F_43 ( & V_2 -> V_63 ) ;
return F_84 ( V_50 , V_62 , V_119 ) ;
}
static T_6 F_85 ( int V_121 , void * V_122 )
{
struct V_1 * V_2 = V_122 ;
T_1 V_123 ;
V_123 = F_3 ( V_2 ) ;
F_1 ( V_2 , V_123 ) ;
F_42 ( V_2 , L_13 , V_123 ) ;
V_123 &= ~ ( V_35 | V_36 ) ;
if ( ! V_123 )
return V_124 ;
if ( V_123 & V_125 )
F_23 ( V_2 , L_14 ) ;
if ( V_123 & V_126 ) {
F_42 ( V_2 , L_15 ) ;
V_123 &= ~ V_126 ;
if ( F_10 ( V_2 ) != 0 )
F_23 ( V_2 , L_16 ) ;
}
if ( V_123 & V_127 ) {
F_42 ( V_2 , L_17 ) ;
V_123 &= ~ V_127 ;
}
if ( V_123 & V_128 ) {
F_42 ( V_2 , L_18 ) ;
V_123 &= ~ V_128 ;
}
if ( ! F_19 ( V_2 ) )
F_23 ( V_2 , L_19 ) ;
if ( V_123 )
F_23 ( V_2 , L_20 , V_123 ) ;
F_86 ( & V_2 -> V_129 ) ;
F_42 ( V_2 , L_21 ) ;
return V_130 ;
}
static void F_87 ( unsigned long V_122 )
{
struct V_1 * V_2 = (struct V_1 * ) V_122 ;
F_42 ( V_2 , L_22 ) ;
F_39 ( & V_2 -> V_63 ) ;
V_2 -> V_78 = true ;
F_63 ( V_2 ) ;
F_43 ( & V_2 -> V_63 ) ;
F_42 ( V_2 , L_23 ) ;
}
static T_6 F_88 ( int V_121 , void * V_122 )
{
struct V_131 * V_132 = V_122 ;
struct V_1 * V_2 ;
unsigned int V_133 = 0 ;
T_1 V_134 , V_135 ;
int V_43 ;
V_134 = ( V_132 -> V_16 & V_136 ) ? F_89 ( V_132 -> V_4 )
: F_90 ( V_132 -> V_4 ) ;
V_135 = 0xff000000 ;
F_91 ( V_132 -> V_84 , L_24 , V_134 ) ;
for ( V_43 = 0 ; V_43 < V_137 ; V_43 ++ ) {
V_2 = V_132 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_134 & V_135 ) {
F_91 ( V_132 -> V_84 , L_25 , V_2 -> V_138 ) ;
F_85 ( V_121 , V_2 ) ;
V_133 ++ ;
}
V_134 &= ~ V_135 ;
V_135 >>= 8 ;
}
return F_92 ( V_133 ) ;
}
static void F_93 ( struct V_131 * V_132 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_132 -> V_121 != V_139 ) {
F_91 ( V_132 -> V_84 , L_26 ) ;
F_94 ( V_132 -> V_121 , V_132 ) ;
return;
}
for ( V_43 = 0 ; V_43 < V_137 ; V_43 ++ ) {
V_2 = V_132 -> V_2 [ V_43 ] ;
if ( V_2 && V_2 -> V_121 != V_139 ) {
F_42 ( V_2 , L_27 ) ;
F_94 ( V_2 -> V_121 , V_2 ) ;
}
}
}
static int F_95 ( struct V_131 * V_132 )
{
struct V_1 * V_2 ;
int V_74 ;
int V_43 ;
if ( V_132 -> V_121 != V_139 ) {
F_91 ( V_132 -> V_84 , L_28 ) ;
V_74 = F_96 ( V_132 -> V_121 , F_88 , V_140 ,
L_29 , V_132 ) ;
return V_74 ;
}
for ( V_43 = 0 ; V_43 < V_137 ; V_43 ++ ) {
V_2 = V_132 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_121 == V_139 ) {
F_23 ( V_2 , L_30 ) ;
V_74 = - V_141 ;
goto V_142;
}
F_42 ( V_2 , L_31 ) ;
V_74 = F_96 ( V_2 -> V_121 , F_85 , V_140 ,
L_32 , V_2 ) ;
if ( V_74 ) {
F_23 ( V_2 , L_33 ) ;
goto V_142;
}
}
return 0 ;
V_142:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_132 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_2 -> V_121 == V_139 )
continue;
F_94 ( V_2 -> V_121 , V_2 ) ;
}
return V_74 ;
}
static int F_97 ( struct V_131 * V_132 ,
struct V_143 * V_66 , T_1 V_16 , const char * V_144 )
{
struct V_1 * V_2 ;
struct V_145 V_146 ;
int V_147 ;
V_2 = F_98 ( sizeof( * V_2 ) , V_148 ) ;
if ( ! V_2 ) {
F_99 ( V_132 -> V_84 , L_34 ) ;
V_147 = - V_85 ;
goto V_149;
}
V_2 -> V_4 = F_100 ( V_66 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_99 ( V_132 -> V_84 , L_35 ) ;
V_147 = - V_85 ;
goto V_150;
}
V_147 = F_101 ( V_66 , 0 , & V_146 ) ;
if ( V_147 ) {
F_99 ( V_132 -> V_84 , L_36 ) ;
goto V_151;
}
V_2 -> V_16 = V_16 ;
if ( ! V_132 -> V_16 )
V_132 -> V_16 = V_2 -> V_16 ;
F_102 ( V_132 -> V_16 != V_2 -> V_16 ) ;
V_2 -> V_84 = V_132 -> V_84 ;
V_2 -> V_138 = ( V_146 . V_152 & 0xfff ) < 0x300 ?
( ( V_146 . V_152 - 0x100 ) & 0xfff ) >> 7 :
( ( V_146 . V_152 - 0x200 ) & 0xfff ) >> 7 ;
if ( V_2 -> V_138 >= V_137 ) {
F_99 ( V_132 -> V_84 , L_37 ) ;
V_147 = - V_51 ;
goto V_151;
}
V_132 -> V_2 [ V_2 -> V_138 ] = V_2 ;
F_103 ( & V_2 -> V_129 , F_87 , ( unsigned long ) V_2 ) ;
snprintf ( V_2 -> V_83 , sizeof( V_2 -> V_83 ) , L_38 , V_2 -> V_138 ) ;
F_18 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
switch ( V_2 -> V_16 & V_17 ) {
case V_18 :
V_2 -> V_153 = F_29 ;
case V_25 :
V_2 -> V_154 = F_30 ;
V_2 -> V_155 = F_24 ;
V_2 -> V_156 = F_26 ;
V_2 -> V_109 = F_27 ;
}
F_104 ( & V_2 -> V_63 ) ;
F_51 ( & V_2 -> V_53 ) ;
F_51 ( & V_2 -> V_79 ) ;
F_51 ( & V_2 -> V_77 ) ;
V_2 -> V_78 = true ;
#ifdef F_40
V_2 -> V_64 = V_65 ;
#endif
V_2 -> V_70 . V_157 = & V_132 -> V_70 ;
F_105 ( & V_2 -> V_70 ) ;
V_2 -> V_121 = F_106 ( V_66 , 0 ) ;
F_60 ( & V_2 -> V_70 . V_143 , & V_132 -> V_70 . V_158 ) ;
F_107 ( V_132 -> V_84 , L_39 , V_2 -> V_138 , V_144 ,
V_2 -> V_121 != V_139 ? V_2 -> V_121 : V_132 -> V_121 ) ;
return 0 ;
V_151:
F_108 ( V_2 -> V_4 ) ;
V_150:
F_109 ( V_2 ) ;
V_149:
return V_147 ;
}
static void F_110 ( struct V_1 * V_2 )
{
F_111 ( V_2 -> V_121 ) ;
F_47 ( & V_2 -> V_70 . V_143 ) ;
F_108 ( V_2 -> V_4 ) ;
F_109 ( V_2 ) ;
}
static int F_112 ( struct V_159 * V_160 )
{
struct V_131 * V_132 ;
struct V_143 * V_61 ;
int V_147 ;
V_132 = F_98 ( sizeof( * V_132 ) , V_148 ) ;
if ( ! V_132 ) {
F_99 ( & V_160 -> V_84 , L_40 ) ;
V_147 = - V_85 ;
goto V_149;
}
V_132 -> V_84 = & V_160 -> V_84 ;
F_51 ( & V_132 -> V_70 . V_158 ) ;
V_132 -> V_4 = F_100 ( V_160 -> V_84 . V_161 , 0 ) ;
if ( ! V_132 -> V_4 ) {
F_99 ( & V_160 -> V_84 , L_35 ) ;
V_147 = - V_85 ;
goto V_162;
}
V_132 -> V_121 = F_106 ( V_160 -> V_84 . V_161 , 0 ) ;
F_113 ( V_163 , V_132 -> V_70 . V_164 ) ;
F_113 ( V_165 , V_132 -> V_70 . V_164 ) ;
F_113 ( V_166 , V_132 -> V_70 . V_164 ) ;
V_132 -> V_70 . V_167 = F_64 ;
V_132 -> V_70 . V_168 = F_70 ;
V_132 -> V_70 . V_169 = F_72 ;
V_132 -> V_70 . V_170 = F_75 ;
V_132 -> V_70 . V_171 = F_83 ;
V_132 -> V_70 . V_172 = F_82 ;
V_132 -> V_70 . V_173 = F_81 ;
V_132 -> V_70 . V_174 = F_80 ;
V_132 -> V_70 . V_84 = & V_160 -> V_84 ;
V_132 -> V_70 . V_175 = V_176 ;
V_132 -> V_70 . V_177 = V_176 ;
V_132 -> V_70 . V_178 = F_114 ( V_179 ) | F_114 ( V_112 ) ;
V_132 -> V_70 . V_180 = V_181 ;
F_115 ( & ( V_160 -> V_84 ) , F_116 ( 36 ) ) ;
F_117 ( V_160 , V_132 ) ;
F_118 (op->dev.of_node, child) {
if ( F_119 ( V_61 , L_41 ) ) {
F_97 ( V_132 , V_61 ,
V_18 | V_136 ,
L_41 ) ;
}
if ( F_119 ( V_61 , L_42 ) ) {
F_97 ( V_132 , V_61 ,
V_25 | V_182 ,
L_42 ) ;
}
}
V_147 = F_95 ( V_132 ) ;
if ( V_147 ) {
F_99 ( V_132 -> V_84 , L_43 ) ;
goto V_162;
}
F_120 ( & V_132 -> V_70 ) ;
return 0 ;
V_162:
F_111 ( V_132 -> V_121 ) ;
F_109 ( V_132 ) ;
V_149:
return V_147 ;
}
static int F_121 ( struct V_159 * V_160 )
{
struct V_131 * V_132 ;
unsigned int V_43 ;
V_132 = F_122 ( V_160 ) ;
F_123 ( & V_132 -> V_70 ) ;
F_93 ( V_132 ) ;
for ( V_43 = 0 ; V_43 < V_137 ; V_43 ++ ) {
if ( V_132 -> V_2 [ V_43 ] )
F_110 ( V_132 -> V_2 [ V_43 ] ) ;
}
F_108 ( V_132 -> V_4 ) ;
F_109 ( V_132 ) ;
return 0 ;
}
static int F_124 ( struct V_157 * V_84 )
{
struct V_159 * V_183 = F_125 ( V_84 ) ;
struct V_131 * V_132 = F_122 ( V_183 ) ;
struct V_1 * V_2 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_137 ; V_43 ++ ) {
V_2 = V_132 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
F_39 ( & V_2 -> V_63 ) ;
if ( F_41 ( ! V_2 -> V_78 ) )
goto V_184;
V_2 -> V_185 . V_6 = F_6 ( V_2 ) ;
V_2 -> V_64 = V_186 ;
F_43 ( & V_2 -> V_63 ) ;
}
return 0 ;
V_184:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_132 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
V_2 -> V_64 = V_65 ;
F_43 ( & V_2 -> V_63 ) ;
}
return - V_98 ;
}
static int F_126 ( struct V_157 * V_84 )
{
struct V_159 * V_183 = F_125 ( V_84 ) ;
struct V_131 * V_132 = F_122 ( V_183 ) ;
struct V_1 * V_2 ;
T_1 V_37 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_137 ; V_43 ++ ) {
V_2 = V_132 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
F_39 ( & V_2 -> V_63 ) ;
V_37 = V_2 -> V_185 . V_6
& ~ V_42 & ~ V_187 & ~ V_44 ;
F_5 ( V_2 , V_37 ) ;
V_2 -> V_64 = V_65 ;
F_43 ( & V_2 -> V_63 ) ;
}
return 0 ;
}
static T_7 int F_127 ( void )
{
F_128 ( L_44 ) ;
return F_129 ( & V_188 ) ;
}
static void T_8 F_130 ( void )
{
F_131 ( & V_188 ) ;
}
