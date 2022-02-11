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
V_37 &= ~ V_47 ;
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
V_37 &= ~ V_48 ;
break;
case 1 :
case 2 :
case 4 :
case 8 :
V_37 &= ~ V_49 ;
V_37 |= V_48 | ( F_25 ( V_45 ) << 16 ) ;
break;
}
F_5 ( V_2 , V_37 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_45 )
{
T_1 V_37 ;
F_28 ( V_45 > 1024 ) ;
V_37 = F_6 ( V_2 ) ;
V_37 &= ~ V_50 ;
V_37 |= ( F_25 ( V_45 ) << 24 ) & V_50 ;
F_5 ( V_2 , V_37 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_51 )
{
if ( V_51 )
V_2 -> V_16 |= V_38 ;
else
V_2 -> V_16 &= ~ V_38 ;
}
static void F_30 ( struct V_1 * V_2 , int V_51 )
{
if ( V_51 )
V_2 -> V_16 |= V_40 ;
else
V_2 -> V_16 &= ~ V_40 ;
}
int F_31 ( struct V_52 * V_53 , int V_51 )
{
struct V_1 * V_2 ;
if ( ! V_53 )
return - V_54 ;
V_2 = F_32 ( V_53 ) ;
F_30 ( V_2 , V_51 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_27 * V_55 = F_34 ( V_2 -> V_56 . V_57 ) ;
if ( F_35 ( & V_2 -> V_56 ) )
goto V_58;
F_15 ( V_2 , & V_55 -> V_12 , V_28 -> V_59 . V_60 ) ;
V_58:
F_36 ( & V_28 -> V_61 , & V_2 -> V_56 ) ;
}
static T_4 F_37 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_32 ( V_63 -> V_2 ) ;
struct V_27 * V_28 = F_38 ( V_63 ) ;
struct V_27 * V_64 ;
T_4 V_65 = - V_54 ;
F_39 ( & V_2 -> V_66 ) ;
#ifdef F_40
if ( F_41 ( V_2 -> V_67 != V_68 ) ) {
F_42 ( V_2 , L_2 ) ;
F_43 ( & V_2 -> V_66 ) ;
return - 1 ;
}
#endif
F_44 (child, &desc->tx_list, node) {
V_65 = F_45 ( & V_64 -> V_59 ) ;
}
F_33 ( V_2 , V_28 ) ;
F_43 ( & V_2 -> V_66 ) ;
return V_65 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_47 ( & V_28 -> V_69 ) ;
F_42 ( V_2 , L_3 , V_28 ) ;
F_48 ( V_2 -> V_70 , V_28 , V_28 -> V_59 . V_60 ) ;
}
static struct V_27 * F_49 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
T_2 V_71 ;
V_28 = F_50 ( V_2 -> V_70 , V_72 , & V_71 ) ;
if ( ! V_28 ) {
F_42 ( V_2 , L_4 ) ;
return NULL ;
}
F_51 ( & V_28 -> V_61 ) ;
F_52 ( & V_28 -> V_59 , & V_2 -> V_73 ) ;
V_28 -> V_59 . V_74 = F_37 ;
V_28 -> V_59 . V_60 = V_71 ;
F_42 ( V_2 , L_5 , V_28 ) ;
return V_28 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_27 * V_28 , * V_75 ;
F_54 (desc, _desc, &chan->ld_completed, node)
if ( F_55 ( & V_28 -> V_59 ) )
F_46 ( V_2 , V_28 ) ;
}
static T_4 F_56 ( struct V_1 * V_2 ,
struct V_27 * V_28 , T_4 V_65 )
{
struct V_62 * V_76 = & V_28 -> V_59 ;
T_4 V_77 = V_65 ;
F_28 ( V_76 -> V_65 < 0 ) ;
if ( V_76 -> V_65 > 0 ) {
V_77 = V_76 -> V_65 ;
F_57 ( V_76 ) ;
F_58 ( V_76 , NULL ) ;
}
F_59 ( V_76 ) ;
return V_77 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_47 ( & V_28 -> V_69 ) ;
if ( ! F_55 ( & V_28 -> V_59 ) ) {
F_61 ( & V_28 -> V_69 , & V_2 -> V_78 ) ;
return;
}
F_48 ( V_2 -> V_70 , V_28 , V_28 -> V_59 . V_60 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
if ( F_35 ( & V_2 -> V_56 ) ) {
F_42 ( V_2 , L_6 ) ;
return;
}
if ( ! V_2 -> V_79 ) {
F_42 ( V_2 , L_7 ) ;
return;
}
F_42 ( V_2 , L_8 ) ;
V_28 = F_63 ( & V_2 -> V_56 , struct V_27 , V_69 ) ;
F_36 ( & V_2 -> V_56 , & V_2 -> V_80 ) ;
if ( ( V_2 -> V_16 & V_17 ) == V_18 ) {
T_1 V_37 ;
V_37 = F_6 ( V_2 ) ;
V_37 &= ~ V_42 ;
F_5 ( V_2 , V_37 ) ;
}
F_7 ( V_2 , V_28 -> V_59 . V_60 ) ;
F_8 ( V_2 ) ;
F_20 ( V_2 ) ;
V_2 -> V_79 = false ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_27 * V_28 , * V_75 ;
T_4 V_65 = 0 ;
T_2 V_81 = F_8 ( V_2 ) ;
int V_82 = 0 ;
F_53 ( V_2 ) ;
F_54 (desc, _desc, &chan->ld_running, node) {
if ( V_82 )
break;
if ( V_28 -> V_59 . V_60 == V_81 ) {
V_82 = 1 ;
if ( ! F_19 ( V_2 ) )
break;
}
V_65 = F_56 ( V_2 , V_28 , V_65 ) ;
F_60 ( V_2 , V_28 ) ;
}
F_62 ( V_2 ) ;
if ( V_65 > 0 )
V_2 -> V_73 . V_83 = V_65 ;
}
static int F_65 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_32 ( V_53 ) ;
if ( V_2 -> V_70 )
return 1 ;
V_2 -> V_70 = F_66 ( V_2 -> V_84 , V_2 -> V_85 ,
sizeof( struct V_27 ) ,
F_67 ( struct V_27 ) , 0 ) ;
if ( ! V_2 -> V_70 ) {
F_23 ( V_2 , L_9 ) ;
return - V_86 ;
}
return 1 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
struct V_27 * V_28 , * V_75 ;
F_54 (desc, _desc, list, node)
F_46 ( V_2 , V_28 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
struct V_27 * V_28 , * V_75 ;
F_70 (desc, _desc, list, node)
F_46 ( V_2 , V_28 ) ;
}
static void F_71 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_32 ( V_53 ) ;
F_42 ( V_2 , L_10 ) ;
F_39 ( & V_2 -> V_66 ) ;
F_64 ( V_2 ) ;
F_68 ( V_2 , & V_2 -> V_56 ) ;
F_68 ( V_2 , & V_2 -> V_80 ) ;
F_68 ( V_2 , & V_2 -> V_78 ) ;
F_43 ( & V_2 -> V_66 ) ;
F_72 ( V_2 -> V_70 ) ;
V_2 -> V_70 = NULL ;
}
static struct V_62 *
F_73 ( struct V_52 * V_53 ,
T_2 V_89 , T_2 V_90 ,
T_5 V_91 , unsigned long V_92 )
{
struct V_1 * V_2 ;
struct V_27 * V_93 = NULL , * V_57 = NULL , * V_94 ;
T_5 V_95 ;
if ( ! V_53 )
return NULL ;
if ( ! V_91 )
return NULL ;
V_2 = F_32 ( V_53 ) ;
do {
V_94 = F_49 ( V_2 ) ;
if ( ! V_94 ) {
F_23 ( V_2 , L_11 , V_96 ) ;
goto V_97;
}
V_95 = F_74 ( V_91 , ( T_5 ) V_98 ) ;
F_11 ( V_2 , & V_94 -> V_12 , V_95 ) ;
F_13 ( V_2 , & V_94 -> V_12 , V_90 ) ;
F_14 ( V_2 , & V_94 -> V_12 , V_89 ) ;
if ( ! V_93 )
V_93 = V_94 ;
else
F_15 ( V_2 , & V_57 -> V_12 , V_94 -> V_59 . V_60 ) ;
V_94 -> V_59 . V_65 = 0 ;
F_75 ( & V_94 -> V_59 ) ;
V_57 = V_94 ;
V_91 -= V_95 ;
V_90 += V_95 ;
V_89 += V_95 ;
F_61 ( & V_94 -> V_69 , & V_93 -> V_61 ) ;
} while ( V_91 );
V_94 -> V_59 . V_92 = V_92 ;
V_94 -> V_59 . V_65 = - V_99 ;
F_16 ( V_2 , V_94 ) ;
return & V_93 -> V_59 ;
V_97:
if ( ! V_93 )
return NULL ;
F_69 ( V_2 , & V_93 -> V_61 ) ;
return NULL ;
}
static struct V_62 * F_76 ( struct V_52 * V_53 ,
struct V_100 * V_101 , unsigned int V_102 ,
struct V_100 * V_103 , unsigned int V_104 ,
unsigned long V_92 )
{
struct V_27 * V_93 = NULL , * V_57 = NULL , * V_94 = NULL ;
struct V_1 * V_2 = F_32 ( V_53 ) ;
T_5 V_105 , V_106 ;
T_2 V_21 , V_14 ;
T_5 V_91 ;
if ( V_102 == 0 || V_104 == 0 )
return NULL ;
if ( V_101 == NULL || V_103 == NULL )
return NULL ;
V_105 = F_77 ( V_101 ) ;
V_106 = F_77 ( V_103 ) ;
while ( true ) {
V_91 = F_78 ( T_5 , V_106 , V_105 ) ;
V_91 = F_78 ( T_5 , V_91 , V_98 ) ;
if ( V_91 == 0 )
goto V_107;
V_21 = F_79 ( V_101 ) + F_77 ( V_101 ) - V_105 ;
V_14 = F_79 ( V_103 ) + F_77 ( V_103 ) - V_106 ;
V_94 = F_49 ( V_2 ) ;
if ( ! V_94 ) {
F_23 ( V_2 , L_11 , V_96 ) ;
goto V_97;
}
F_11 ( V_2 , & V_94 -> V_12 , V_91 ) ;
F_13 ( V_2 , & V_94 -> V_12 , V_14 ) ;
F_14 ( V_2 , & V_94 -> V_12 , V_21 ) ;
if ( ! V_93 )
V_93 = V_94 ;
else
F_15 ( V_2 , & V_57 -> V_12 , V_94 -> V_59 . V_60 ) ;
V_94 -> V_59 . V_65 = 0 ;
F_75 ( & V_94 -> V_59 ) ;
V_57 = V_94 ;
F_61 ( & V_94 -> V_69 , & V_93 -> V_61 ) ;
V_105 -= V_91 ;
V_106 -= V_91 ;
V_107:
if ( V_105 == 0 ) {
if ( V_102 == 0 )
break;
V_101 = F_80 ( V_101 ) ;
if ( V_101 == NULL )
break;
V_102 -- ;
V_105 = F_77 ( V_101 ) ;
}
if ( V_106 == 0 ) {
if ( V_104 == 0 )
break;
V_103 = F_80 ( V_103 ) ;
if ( V_103 == NULL )
break;
V_104 -- ;
V_106 = F_77 ( V_103 ) ;
}
}
V_94 -> V_59 . V_92 = V_92 ;
V_94 -> V_59 . V_65 = - V_99 ;
F_16 ( V_2 , V_94 ) ;
return & V_93 -> V_59 ;
V_97:
if ( ! V_93 )
return NULL ;
F_69 ( V_2 , & V_93 -> V_61 ) ;
return NULL ;
}
static int F_81 ( struct V_52 * V_53 )
{
struct V_1 * V_2 ;
if ( ! V_53 )
return - V_54 ;
V_2 = F_32 ( V_53 ) ;
F_39 ( & V_2 -> V_66 ) ;
F_21 ( V_2 ) ;
F_68 ( V_2 , & V_2 -> V_56 ) ;
F_68 ( V_2 , & V_2 -> V_80 ) ;
F_68 ( V_2 , & V_2 -> V_78 ) ;
V_2 -> V_79 = true ;
F_43 ( & V_2 -> V_66 ) ;
return 0 ;
}
static int F_82 ( struct V_52 * V_53 ,
struct V_108 * V_109 )
{
struct V_1 * V_2 ;
int V_45 ;
if ( ! V_53 )
return - V_54 ;
V_2 = F_32 ( V_53 ) ;
if ( ! V_2 -> V_110 )
return - V_111 ;
if ( V_109 -> V_112 == V_113 )
V_45 = V_109 -> V_114 * V_109 -> V_115 ;
else
V_45 = V_109 -> V_116 * V_109 -> V_117 ;
V_2 -> V_110 ( V_2 , V_45 ) ;
return 0 ;
}
static void F_83 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_32 ( V_53 ) ;
F_39 ( & V_2 -> V_66 ) ;
F_62 ( V_2 ) ;
F_43 ( & V_2 -> V_66 ) ;
}
static enum V_118 F_84 ( struct V_52 * V_53 ,
T_4 V_65 ,
struct V_119 * V_120 )
{
struct V_1 * V_2 = F_32 ( V_53 ) ;
enum V_118 V_77 ;
V_77 = F_85 ( V_53 , V_65 , V_120 ) ;
if ( V_77 == V_121 )
return V_77 ;
F_39 ( & V_2 -> V_66 ) ;
F_64 ( V_2 ) ;
F_43 ( & V_2 -> V_66 ) ;
return F_85 ( V_53 , V_65 , V_120 ) ;
}
static T_6 F_86 ( int V_122 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
T_1 V_124 ;
V_124 = F_3 ( V_2 ) ;
F_1 ( V_2 , V_124 ) ;
F_42 ( V_2 , L_12 , V_124 ) ;
V_124 &= ~ ( V_35 | V_36 ) ;
if ( ! V_124 )
return V_125 ;
if ( V_124 & V_126 )
F_23 ( V_2 , L_13 ) ;
if ( V_124 & V_127 ) {
F_42 ( V_2 , L_14 ) ;
V_124 &= ~ V_127 ;
if ( F_10 ( V_2 ) != 0 )
F_23 ( V_2 , L_15 ) ;
}
if ( V_124 & V_128 ) {
F_42 ( V_2 , L_16 ) ;
V_124 &= ~ V_128 ;
}
if ( V_124 & V_129 ) {
F_42 ( V_2 , L_17 ) ;
V_124 &= ~ V_129 ;
}
if ( ! F_19 ( V_2 ) )
F_23 ( V_2 , L_18 ) ;
if ( V_124 )
F_23 ( V_2 , L_19 , V_124 ) ;
F_87 ( & V_2 -> V_130 ) ;
F_42 ( V_2 , L_20 ) ;
return V_131 ;
}
static void F_88 ( unsigned long V_123 )
{
struct V_1 * V_2 = (struct V_1 * ) V_123 ;
F_42 ( V_2 , L_21 ) ;
F_39 ( & V_2 -> V_66 ) ;
V_2 -> V_79 = true ;
F_64 ( V_2 ) ;
F_43 ( & V_2 -> V_66 ) ;
F_42 ( V_2 , L_22 ) ;
}
static T_6 F_89 ( int V_122 , void * V_123 )
{
struct V_132 * V_133 = V_123 ;
struct V_1 * V_2 ;
unsigned int V_134 = 0 ;
T_1 V_135 , V_136 ;
int V_43 ;
V_135 = ( V_133 -> V_16 & V_137 ) ? F_90 ( V_133 -> V_4 )
: F_91 ( V_133 -> V_4 ) ;
V_136 = 0xff000000 ;
F_92 ( V_133 -> V_85 , L_23 , V_135 ) ;
for ( V_43 = 0 ; V_43 < V_138 ; V_43 ++ ) {
V_2 = V_133 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_135 & V_136 ) {
F_92 ( V_133 -> V_85 , L_24 , V_2 -> V_139 ) ;
F_86 ( V_122 , V_2 ) ;
V_134 ++ ;
}
V_135 &= ~ V_136 ;
V_136 >>= 8 ;
}
return F_93 ( V_134 ) ;
}
static void F_94 ( struct V_132 * V_133 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_133 -> V_122 ) {
F_92 ( V_133 -> V_85 , L_25 ) ;
F_95 ( V_133 -> V_122 , V_133 ) ;
return;
}
for ( V_43 = 0 ; V_43 < V_138 ; V_43 ++ ) {
V_2 = V_133 -> V_2 [ V_43 ] ;
if ( V_2 && V_2 -> V_122 ) {
F_42 ( V_2 , L_26 ) ;
F_95 ( V_2 -> V_122 , V_2 ) ;
}
}
}
static int F_96 ( struct V_132 * V_133 )
{
struct V_1 * V_2 ;
int V_77 ;
int V_43 ;
if ( V_133 -> V_122 ) {
F_92 ( V_133 -> V_85 , L_27 ) ;
V_77 = F_97 ( V_133 -> V_122 , F_89 , V_140 ,
L_28 , V_133 ) ;
return V_77 ;
}
for ( V_43 = 0 ; V_43 < V_138 ; V_43 ++ ) {
V_2 = V_133 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( ! V_2 -> V_122 ) {
F_23 ( V_2 , L_29 ) ;
V_77 = - V_141 ;
goto V_142;
}
F_42 ( V_2 , L_30 ) ;
V_77 = F_97 ( V_2 -> V_122 , F_86 , V_140 ,
L_31 , V_2 ) ;
if ( V_77 ) {
F_23 ( V_2 , L_32 ) ;
goto V_142;
}
}
return 0 ;
V_142:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_133 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( ! V_2 -> V_122 )
continue;
F_95 ( V_2 -> V_122 , V_2 ) ;
}
return V_77 ;
}
static int F_98 ( struct V_132 * V_133 ,
struct V_143 * V_69 , T_1 V_16 , const char * V_144 )
{
struct V_1 * V_2 ;
struct V_145 V_146 ;
int V_147 ;
V_2 = F_99 ( sizeof( * V_2 ) , V_148 ) ;
if ( ! V_2 ) {
V_147 = - V_86 ;
goto V_149;
}
V_2 -> V_4 = F_100 ( V_69 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_101 ( V_133 -> V_85 , L_33 ) ;
V_147 = - V_86 ;
goto V_150;
}
V_147 = F_102 ( V_69 , 0 , & V_146 ) ;
if ( V_147 ) {
F_101 ( V_133 -> V_85 , L_34 ) ;
goto V_151;
}
V_2 -> V_16 = V_16 ;
if ( ! V_133 -> V_16 )
V_133 -> V_16 = V_2 -> V_16 ;
F_103 ( V_133 -> V_16 != V_2 -> V_16 ) ;
V_2 -> V_85 = V_133 -> V_85 ;
V_2 -> V_139 = ( V_146 . V_152 & 0xfff ) < 0x300 ?
( ( V_146 . V_152 - 0x100 ) & 0xfff ) >> 7 :
( ( V_146 . V_152 - 0x200 ) & 0xfff ) >> 7 ;
if ( V_2 -> V_139 >= V_138 ) {
F_101 ( V_133 -> V_85 , L_35 ) ;
V_147 = - V_54 ;
goto V_151;
}
V_133 -> V_2 [ V_2 -> V_139 ] = V_2 ;
F_104 ( & V_2 -> V_130 , F_88 , ( unsigned long ) V_2 ) ;
snprintf ( V_2 -> V_84 , sizeof( V_2 -> V_84 ) , L_36 , V_2 -> V_139 ) ;
F_18 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
switch ( V_2 -> V_16 & V_17 ) {
case V_18 :
V_2 -> V_153 = F_29 ;
case V_25 :
V_2 -> V_154 = F_30 ;
V_2 -> V_155 = F_24 ;
V_2 -> V_156 = F_26 ;
V_2 -> V_110 = F_27 ;
}
F_105 ( & V_2 -> V_66 ) ;
F_51 ( & V_2 -> V_56 ) ;
F_51 ( & V_2 -> V_80 ) ;
F_51 ( & V_2 -> V_78 ) ;
V_2 -> V_79 = true ;
#ifdef F_40
V_2 -> V_67 = V_68 ;
#endif
V_2 -> V_73 . V_157 = & V_133 -> V_73 ;
F_106 ( & V_2 -> V_73 ) ;
V_2 -> V_122 = F_107 ( V_69 , 0 ) ;
F_61 ( & V_2 -> V_73 . V_143 , & V_133 -> V_73 . V_158 ) ;
F_108 ( V_133 -> V_85 , L_37 , V_2 -> V_139 , V_144 ,
V_2 -> V_122 ? V_2 -> V_122 : V_133 -> V_122 ) ;
return 0 ;
V_151:
F_109 ( V_2 -> V_4 ) ;
V_150:
F_110 ( V_2 ) ;
V_149:
return V_147 ;
}
static void F_111 ( struct V_1 * V_2 )
{
F_112 ( V_2 -> V_122 ) ;
F_47 ( & V_2 -> V_73 . V_143 ) ;
F_109 ( V_2 -> V_4 ) ;
F_110 ( V_2 ) ;
}
static int F_113 ( struct V_159 * V_160 )
{
struct V_132 * V_133 ;
struct V_143 * V_64 ;
int V_147 ;
V_133 = F_99 ( sizeof( * V_133 ) , V_148 ) ;
if ( ! V_133 ) {
V_147 = - V_86 ;
goto V_149;
}
V_133 -> V_85 = & V_160 -> V_85 ;
F_51 ( & V_133 -> V_73 . V_158 ) ;
V_133 -> V_4 = F_100 ( V_160 -> V_85 . V_161 , 0 ) ;
if ( ! V_133 -> V_4 ) {
F_101 ( & V_160 -> V_85 , L_33 ) ;
V_147 = - V_86 ;
goto V_162;
}
V_133 -> V_122 = F_107 ( V_160 -> V_85 . V_161 , 0 ) ;
F_114 ( V_163 , V_133 -> V_73 . V_164 ) ;
F_114 ( V_165 , V_133 -> V_73 . V_164 ) ;
F_114 ( V_166 , V_133 -> V_73 . V_164 ) ;
V_133 -> V_73 . V_167 = F_65 ;
V_133 -> V_73 . V_168 = F_71 ;
V_133 -> V_73 . V_169 = F_73 ;
V_133 -> V_73 . V_170 = F_76 ;
V_133 -> V_73 . V_171 = F_84 ;
V_133 -> V_73 . V_172 = F_83 ;
V_133 -> V_73 . V_173 = F_82 ;
V_133 -> V_73 . V_174 = F_81 ;
V_133 -> V_73 . V_85 = & V_160 -> V_85 ;
V_133 -> V_73 . V_175 = V_176 ;
V_133 -> V_73 . V_177 = V_176 ;
V_133 -> V_73 . V_178 = F_115 ( V_179 ) | F_115 ( V_113 ) ;
V_133 -> V_73 . V_180 = V_181 ;
F_116 ( & ( V_160 -> V_85 ) , F_117 ( 36 ) ) ;
F_118 ( V_160 , V_133 ) ;
F_119 (op->dev.of_node, child) {
if ( F_120 ( V_64 , L_38 ) ) {
F_98 ( V_133 , V_64 ,
V_18 | V_137 ,
L_38 ) ;
}
if ( F_120 ( V_64 , L_39 ) ) {
F_98 ( V_133 , V_64 ,
V_25 | V_182 ,
L_39 ) ;
}
}
V_147 = F_96 ( V_133 ) ;
if ( V_147 ) {
F_101 ( V_133 -> V_85 , L_40 ) ;
goto V_183;
}
F_121 ( & V_133 -> V_73 ) ;
return 0 ;
V_183:
F_112 ( V_133 -> V_122 ) ;
F_109 ( V_133 -> V_4 ) ;
V_162:
F_110 ( V_133 ) ;
V_149:
return V_147 ;
}
static int F_122 ( struct V_159 * V_160 )
{
struct V_132 * V_133 ;
unsigned int V_43 ;
V_133 = F_123 ( V_160 ) ;
F_124 ( & V_133 -> V_73 ) ;
F_94 ( V_133 ) ;
for ( V_43 = 0 ; V_43 < V_138 ; V_43 ++ ) {
if ( V_133 -> V_2 [ V_43 ] )
F_111 ( V_133 -> V_2 [ V_43 ] ) ;
}
F_109 ( V_133 -> V_4 ) ;
F_110 ( V_133 ) ;
return 0 ;
}
static int F_125 ( struct V_157 * V_85 )
{
struct V_159 * V_184 = F_126 ( V_85 ) ;
struct V_132 * V_133 = F_123 ( V_184 ) ;
struct V_1 * V_2 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_138 ; V_43 ++ ) {
V_2 = V_133 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
F_39 ( & V_2 -> V_66 ) ;
if ( F_41 ( ! V_2 -> V_79 ) )
goto V_185;
V_2 -> V_186 . V_6 = F_6 ( V_2 ) ;
V_2 -> V_67 = V_187 ;
F_43 ( & V_2 -> V_66 ) ;
}
return 0 ;
V_185:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_133 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
V_2 -> V_67 = V_68 ;
F_43 ( & V_2 -> V_66 ) ;
}
return - V_99 ;
}
static int F_127 ( struct V_157 * V_85 )
{
struct V_159 * V_184 = F_126 ( V_85 ) ;
struct V_132 * V_133 = F_123 ( V_184 ) ;
struct V_1 * V_2 ;
T_1 V_37 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_138 ; V_43 ++ ) {
V_2 = V_133 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
F_39 ( & V_2 -> V_66 ) ;
V_37 = V_2 -> V_186 . V_6
& ~ V_42 & ~ V_188 & ~ V_44 ;
F_5 ( V_2 , V_37 ) ;
V_2 -> V_67 = V_68 ;
F_43 ( & V_2 -> V_66 ) ;
}
return 0 ;
}
static T_7 int F_128 ( void )
{
F_129 ( L_41 ) ;
return F_130 ( & V_189 ) ;
}
static void T_8 F_131 ( void )
{
F_132 ( & V_189 ) ;
}
