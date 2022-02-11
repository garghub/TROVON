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
F_57 ( V_73 ) ;
F_58 ( V_73 , NULL ) ;
}
F_59 ( V_73 ) ;
return V_74 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_47 ( & V_28 -> V_66 ) ;
if ( ! F_55 ( & V_28 -> V_56 ) ) {
F_61 ( & V_28 -> V_66 , & V_2 -> V_75 ) ;
return;
}
F_48 ( V_2 -> V_67 , V_28 , V_28 -> V_56 . V_57 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
if ( F_35 ( & V_2 -> V_53 ) ) {
F_42 ( V_2 , L_6 ) ;
return;
}
if ( ! V_2 -> V_76 ) {
F_42 ( V_2 , L_7 ) ;
return;
}
F_42 ( V_2 , L_8 ) ;
V_28 = F_63 ( & V_2 -> V_53 , struct V_27 , V_66 ) ;
F_36 ( & V_2 -> V_53 , & V_2 -> V_77 ) ;
if ( ( V_2 -> V_16 & V_17 ) == V_18 ) {
T_1 V_37 ;
V_37 = F_6 ( V_2 ) ;
V_37 &= ~ V_42 ;
F_5 ( V_2 , V_37 ) ;
}
F_7 ( V_2 , V_28 -> V_56 . V_57 ) ;
F_8 ( V_2 ) ;
F_20 ( V_2 ) ;
V_2 -> V_76 = false ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_27 * V_28 , * V_72 ;
T_4 V_62 = 0 ;
T_2 V_78 = F_8 ( V_2 ) ;
int V_79 = 0 ;
F_53 ( V_2 ) ;
F_54 (desc, _desc, &chan->ld_running, node) {
if ( V_79 )
break;
if ( V_28 -> V_56 . V_57 == V_78 ) {
V_79 = 1 ;
if ( ! F_19 ( V_2 ) )
break;
}
V_62 = F_56 ( V_2 , V_28 , V_62 ) ;
F_60 ( V_2 , V_28 ) ;
}
F_62 ( V_2 ) ;
if ( V_62 > 0 )
V_2 -> V_70 . V_80 = V_62 ;
}
static int F_65 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
if ( V_2 -> V_67 )
return 1 ;
V_2 -> V_67 = F_66 ( V_2 -> V_81 , V_2 -> V_82 ,
sizeof( struct V_27 ) ,
F_67 ( struct V_27 ) , 0 ) ;
if ( ! V_2 -> V_67 ) {
F_23 ( V_2 , L_9 ) ;
return - V_83 ;
}
return 1 ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_27 * V_28 , * V_72 ;
F_54 (desc, _desc, list, node)
F_46 ( V_2 , V_28 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_27 * V_28 , * V_72 ;
F_70 (desc, _desc, list, node)
F_46 ( V_2 , V_28 ) ;
}
static void F_71 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
F_42 ( V_2 , L_10 ) ;
F_39 ( & V_2 -> V_63 ) ;
F_64 ( V_2 ) ;
F_68 ( V_2 , & V_2 -> V_53 ) ;
F_68 ( V_2 , & V_2 -> V_77 ) ;
F_68 ( V_2 , & V_2 -> V_75 ) ;
F_43 ( & V_2 -> V_63 ) ;
F_72 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
static struct V_59 *
F_73 ( struct V_49 * V_50 ,
T_2 V_86 , T_2 V_87 ,
T_5 V_88 , unsigned long V_89 )
{
struct V_1 * V_2 ;
struct V_27 * V_90 = NULL , * V_54 = NULL , * V_91 ;
T_5 V_92 ;
if ( ! V_50 )
return NULL ;
if ( ! V_88 )
return NULL ;
V_2 = F_32 ( V_50 ) ;
do {
V_91 = F_49 ( V_2 ) ;
if ( ! V_91 ) {
F_23 ( V_2 , L_11 , V_93 ) ;
goto V_94;
}
V_92 = F_74 ( V_88 , ( T_5 ) V_95 ) ;
F_11 ( V_2 , & V_91 -> V_12 , V_92 ) ;
F_13 ( V_2 , & V_91 -> V_12 , V_87 ) ;
F_14 ( V_2 , & V_91 -> V_12 , V_86 ) ;
if ( ! V_90 )
V_90 = V_91 ;
else
F_15 ( V_2 , & V_54 -> V_12 , V_91 -> V_56 . V_57 ) ;
V_91 -> V_56 . V_62 = 0 ;
F_75 ( & V_91 -> V_56 ) ;
V_54 = V_91 ;
V_88 -= V_92 ;
V_87 += V_92 ;
V_86 += V_92 ;
F_61 ( & V_91 -> V_66 , & V_90 -> V_58 ) ;
} while ( V_88 );
V_91 -> V_56 . V_89 = V_89 ;
V_91 -> V_56 . V_62 = - V_96 ;
F_16 ( V_2 , V_91 ) ;
return & V_90 -> V_56 ;
V_94:
if ( ! V_90 )
return NULL ;
F_69 ( V_2 , & V_90 -> V_58 ) ;
return NULL ;
}
static struct V_59 * F_76 ( struct V_49 * V_50 ,
struct V_97 * V_98 , unsigned int V_99 ,
struct V_97 * V_100 , unsigned int V_101 ,
unsigned long V_89 )
{
struct V_27 * V_90 = NULL , * V_54 = NULL , * V_91 = NULL ;
struct V_1 * V_2 = F_32 ( V_50 ) ;
T_5 V_102 , V_103 ;
T_2 V_21 , V_14 ;
T_5 V_88 ;
if ( V_99 == 0 || V_101 == 0 )
return NULL ;
if ( V_98 == NULL || V_100 == NULL )
return NULL ;
V_102 = F_77 ( V_98 ) ;
V_103 = F_77 ( V_100 ) ;
while ( true ) {
V_88 = F_78 ( T_5 , V_103 , V_102 ) ;
V_88 = F_78 ( T_5 , V_88 , V_95 ) ;
if ( V_88 == 0 )
goto V_104;
V_21 = F_79 ( V_98 ) + F_77 ( V_98 ) - V_102 ;
V_14 = F_79 ( V_100 ) + F_77 ( V_100 ) - V_103 ;
V_91 = F_49 ( V_2 ) ;
if ( ! V_91 ) {
F_23 ( V_2 , L_11 , V_93 ) ;
goto V_94;
}
F_11 ( V_2 , & V_91 -> V_12 , V_88 ) ;
F_13 ( V_2 , & V_91 -> V_12 , V_14 ) ;
F_14 ( V_2 , & V_91 -> V_12 , V_21 ) ;
if ( ! V_90 )
V_90 = V_91 ;
else
F_15 ( V_2 , & V_54 -> V_12 , V_91 -> V_56 . V_57 ) ;
V_91 -> V_56 . V_62 = 0 ;
F_75 ( & V_91 -> V_56 ) ;
V_54 = V_91 ;
F_61 ( & V_91 -> V_66 , & V_90 -> V_58 ) ;
V_102 -= V_88 ;
V_103 -= V_88 ;
V_104:
if ( V_102 == 0 ) {
if ( V_99 == 0 )
break;
V_98 = F_80 ( V_98 ) ;
if ( V_98 == NULL )
break;
V_99 -- ;
V_102 = F_77 ( V_98 ) ;
}
if ( V_103 == 0 ) {
if ( V_101 == 0 )
break;
V_100 = F_80 ( V_100 ) ;
if ( V_100 == NULL )
break;
V_101 -- ;
V_103 = F_77 ( V_100 ) ;
}
}
V_91 -> V_56 . V_89 = V_89 ;
V_91 -> V_56 . V_62 = - V_96 ;
F_16 ( V_2 , V_91 ) ;
return & V_90 -> V_56 ;
V_94:
if ( ! V_90 )
return NULL ;
F_69 ( V_2 , & V_90 -> V_58 ) ;
return NULL ;
}
static int F_81 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
if ( ! V_50 )
return - V_51 ;
V_2 = F_32 ( V_50 ) ;
F_39 ( & V_2 -> V_63 ) ;
F_21 ( V_2 ) ;
F_68 ( V_2 , & V_2 -> V_53 ) ;
F_68 ( V_2 , & V_2 -> V_77 ) ;
F_68 ( V_2 , & V_2 -> V_75 ) ;
V_2 -> V_76 = true ;
F_43 ( & V_2 -> V_63 ) ;
return 0 ;
}
static int F_82 ( struct V_49 * V_50 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 ;
int V_45 ;
if ( ! V_50 )
return - V_51 ;
V_2 = F_32 ( V_50 ) ;
if ( ! V_2 -> V_107 )
return - V_108 ;
if ( V_106 -> V_109 == V_110 )
V_45 = V_106 -> V_111 * V_106 -> V_112 ;
else
V_45 = V_106 -> V_113 * V_106 -> V_114 ;
V_2 -> V_107 ( V_2 , V_45 ) ;
return 0 ;
}
static void F_83 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
F_39 ( & V_2 -> V_63 ) ;
F_62 ( V_2 ) ;
F_43 ( & V_2 -> V_63 ) ;
}
static enum V_115 F_84 ( struct V_49 * V_50 ,
T_4 V_62 ,
struct V_116 * V_117 )
{
struct V_1 * V_2 = F_32 ( V_50 ) ;
enum V_115 V_74 ;
V_74 = F_85 ( V_50 , V_62 , V_117 ) ;
if ( V_74 == V_118 )
return V_74 ;
F_39 ( & V_2 -> V_63 ) ;
F_64 ( V_2 ) ;
F_43 ( & V_2 -> V_63 ) ;
return F_85 ( V_50 , V_62 , V_117 ) ;
}
static T_6 F_86 ( int V_119 , void * V_120 )
{
struct V_1 * V_2 = V_120 ;
T_1 V_121 ;
V_121 = F_3 ( V_2 ) ;
F_1 ( V_2 , V_121 ) ;
F_42 ( V_2 , L_12 , V_121 ) ;
V_121 &= ~ ( V_35 | V_36 ) ;
if ( ! V_121 )
return V_122 ;
if ( V_121 & V_123 )
F_23 ( V_2 , L_13 ) ;
if ( V_121 & V_124 ) {
F_42 ( V_2 , L_14 ) ;
V_121 &= ~ V_124 ;
if ( F_10 ( V_2 ) != 0 )
F_23 ( V_2 , L_15 ) ;
}
if ( V_121 & V_125 ) {
F_42 ( V_2 , L_16 ) ;
V_121 &= ~ V_125 ;
}
if ( V_121 & V_126 ) {
F_42 ( V_2 , L_17 ) ;
V_121 &= ~ V_126 ;
}
if ( ! F_19 ( V_2 ) )
F_23 ( V_2 , L_18 ) ;
if ( V_121 )
F_23 ( V_2 , L_19 , V_121 ) ;
F_87 ( & V_2 -> V_127 ) ;
F_42 ( V_2 , L_20 ) ;
return V_128 ;
}
static void F_88 ( unsigned long V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 ;
F_42 ( V_2 , L_21 ) ;
F_39 ( & V_2 -> V_63 ) ;
V_2 -> V_76 = true ;
F_64 ( V_2 ) ;
F_43 ( & V_2 -> V_63 ) ;
F_42 ( V_2 , L_22 ) ;
}
static T_6 F_89 ( int V_119 , void * V_120 )
{
struct V_129 * V_130 = V_120 ;
struct V_1 * V_2 ;
unsigned int V_131 = 0 ;
T_1 V_132 , V_133 ;
int V_43 ;
V_132 = ( V_130 -> V_16 & V_134 ) ? F_90 ( V_130 -> V_4 )
: F_91 ( V_130 -> V_4 ) ;
V_133 = 0xff000000 ;
F_92 ( V_130 -> V_82 , L_23 , V_132 ) ;
for ( V_43 = 0 ; V_43 < V_135 ; V_43 ++ ) {
V_2 = V_130 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( V_132 & V_133 ) {
F_92 ( V_130 -> V_82 , L_24 , V_2 -> V_136 ) ;
F_86 ( V_119 , V_2 ) ;
V_131 ++ ;
}
V_132 &= ~ V_133 ;
V_133 >>= 8 ;
}
return F_93 ( V_131 ) ;
}
static void F_94 ( struct V_129 * V_130 )
{
struct V_1 * V_2 ;
int V_43 ;
if ( V_130 -> V_119 ) {
F_92 ( V_130 -> V_82 , L_25 ) ;
F_95 ( V_130 -> V_119 , V_130 ) ;
return;
}
for ( V_43 = 0 ; V_43 < V_135 ; V_43 ++ ) {
V_2 = V_130 -> V_2 [ V_43 ] ;
if ( V_2 && V_2 -> V_119 ) {
F_42 ( V_2 , L_26 ) ;
F_95 ( V_2 -> V_119 , V_2 ) ;
}
}
}
static int F_96 ( struct V_129 * V_130 )
{
struct V_1 * V_2 ;
int V_74 ;
int V_43 ;
if ( V_130 -> V_119 ) {
F_92 ( V_130 -> V_82 , L_27 ) ;
V_74 = F_97 ( V_130 -> V_119 , F_89 , V_137 ,
L_28 , V_130 ) ;
return V_74 ;
}
for ( V_43 = 0 ; V_43 < V_135 ; V_43 ++ ) {
V_2 = V_130 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( ! V_2 -> V_119 ) {
F_23 ( V_2 , L_29 ) ;
V_74 = - V_138 ;
goto V_139;
}
F_42 ( V_2 , L_30 ) ;
V_74 = F_97 ( V_2 -> V_119 , F_86 , V_137 ,
L_31 , V_2 ) ;
if ( V_74 ) {
F_23 ( V_2 , L_32 ) ;
goto V_139;
}
}
return 0 ;
V_139:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_130 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
if ( ! V_2 -> V_119 )
continue;
F_95 ( V_2 -> V_119 , V_2 ) ;
}
return V_74 ;
}
static int F_98 ( struct V_129 * V_130 ,
struct V_140 * V_66 , T_1 V_16 , const char * V_141 )
{
struct V_1 * V_2 ;
struct V_142 V_143 ;
int V_144 ;
V_2 = F_99 ( sizeof( * V_2 ) , V_145 ) ;
if ( ! V_2 ) {
V_144 = - V_83 ;
goto V_146;
}
V_2 -> V_4 = F_100 ( V_66 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_101 ( V_130 -> V_82 , L_33 ) ;
V_144 = - V_83 ;
goto V_147;
}
V_144 = F_102 ( V_66 , 0 , & V_143 ) ;
if ( V_144 ) {
F_101 ( V_130 -> V_82 , L_34 ) ;
goto V_148;
}
V_2 -> V_16 = V_16 ;
if ( ! V_130 -> V_16 )
V_130 -> V_16 = V_2 -> V_16 ;
F_103 ( V_130 -> V_16 != V_2 -> V_16 ) ;
V_2 -> V_82 = V_130 -> V_82 ;
V_2 -> V_136 = ( V_143 . V_149 & 0xfff ) < 0x300 ?
( ( V_143 . V_149 - 0x100 ) & 0xfff ) >> 7 :
( ( V_143 . V_149 - 0x200 ) & 0xfff ) >> 7 ;
if ( V_2 -> V_136 >= V_135 ) {
F_101 ( V_130 -> V_82 , L_35 ) ;
V_144 = - V_51 ;
goto V_148;
}
V_130 -> V_2 [ V_2 -> V_136 ] = V_2 ;
F_104 ( & V_2 -> V_127 , F_88 , ( unsigned long ) V_2 ) ;
snprintf ( V_2 -> V_81 , sizeof( V_2 -> V_81 ) , L_36 , V_2 -> V_136 ) ;
F_18 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
switch ( V_2 -> V_16 & V_17 ) {
case V_18 :
V_2 -> V_150 = F_29 ;
case V_25 :
V_2 -> V_151 = F_30 ;
V_2 -> V_152 = F_24 ;
V_2 -> V_153 = F_26 ;
V_2 -> V_107 = F_27 ;
}
F_105 ( & V_2 -> V_63 ) ;
F_51 ( & V_2 -> V_53 ) ;
F_51 ( & V_2 -> V_77 ) ;
F_51 ( & V_2 -> V_75 ) ;
V_2 -> V_76 = true ;
#ifdef F_40
V_2 -> V_64 = V_65 ;
#endif
V_2 -> V_70 . V_154 = & V_130 -> V_70 ;
F_106 ( & V_2 -> V_70 ) ;
V_2 -> V_119 = F_107 ( V_66 , 0 ) ;
F_61 ( & V_2 -> V_70 . V_140 , & V_130 -> V_70 . V_155 ) ;
F_108 ( V_130 -> V_82 , L_37 , V_2 -> V_136 , V_141 ,
V_2 -> V_119 ? V_2 -> V_119 : V_130 -> V_119 ) ;
return 0 ;
V_148:
F_109 ( V_2 -> V_4 ) ;
V_147:
F_110 ( V_2 ) ;
V_146:
return V_144 ;
}
static void F_111 ( struct V_1 * V_2 )
{
F_112 ( V_2 -> V_119 ) ;
F_47 ( & V_2 -> V_70 . V_140 ) ;
F_109 ( V_2 -> V_4 ) ;
F_110 ( V_2 ) ;
}
static int F_113 ( struct V_156 * V_157 )
{
struct V_129 * V_130 ;
struct V_140 * V_61 ;
int V_144 ;
V_130 = F_99 ( sizeof( * V_130 ) , V_145 ) ;
if ( ! V_130 ) {
V_144 = - V_83 ;
goto V_146;
}
V_130 -> V_82 = & V_157 -> V_82 ;
F_51 ( & V_130 -> V_70 . V_155 ) ;
V_130 -> V_4 = F_100 ( V_157 -> V_82 . V_158 , 0 ) ;
if ( ! V_130 -> V_4 ) {
F_101 ( & V_157 -> V_82 , L_33 ) ;
V_144 = - V_83 ;
goto V_159;
}
V_130 -> V_119 = F_107 ( V_157 -> V_82 . V_158 , 0 ) ;
F_114 ( V_160 , V_130 -> V_70 . V_161 ) ;
F_114 ( V_162 , V_130 -> V_70 . V_161 ) ;
F_114 ( V_163 , V_130 -> V_70 . V_161 ) ;
V_130 -> V_70 . V_164 = F_65 ;
V_130 -> V_70 . V_165 = F_71 ;
V_130 -> V_70 . V_166 = F_73 ;
V_130 -> V_70 . V_167 = F_76 ;
V_130 -> V_70 . V_168 = F_84 ;
V_130 -> V_70 . V_169 = F_83 ;
V_130 -> V_70 . V_170 = F_82 ;
V_130 -> V_70 . V_171 = F_81 ;
V_130 -> V_70 . V_82 = & V_157 -> V_82 ;
V_130 -> V_70 . V_172 = V_173 ;
V_130 -> V_70 . V_174 = V_173 ;
V_130 -> V_70 . V_175 = F_115 ( V_176 ) | F_115 ( V_110 ) ;
V_130 -> V_70 . V_177 = V_178 ;
F_116 ( & ( V_157 -> V_82 ) , F_117 ( 36 ) ) ;
F_118 ( V_157 , V_130 ) ;
F_119 (op->dev.of_node, child) {
if ( F_120 ( V_61 , L_38 ) ) {
F_98 ( V_130 , V_61 ,
V_18 | V_134 ,
L_38 ) ;
}
if ( F_120 ( V_61 , L_39 ) ) {
F_98 ( V_130 , V_61 ,
V_25 | V_179 ,
L_39 ) ;
}
}
V_144 = F_96 ( V_130 ) ;
if ( V_144 ) {
F_101 ( V_130 -> V_82 , L_40 ) ;
goto V_180;
}
F_121 ( & V_130 -> V_70 ) ;
return 0 ;
V_180:
F_112 ( V_130 -> V_119 ) ;
F_109 ( V_130 -> V_4 ) ;
V_159:
F_110 ( V_130 ) ;
V_146:
return V_144 ;
}
static int F_122 ( struct V_156 * V_157 )
{
struct V_129 * V_130 ;
unsigned int V_43 ;
V_130 = F_123 ( V_157 ) ;
F_124 ( & V_130 -> V_70 ) ;
F_94 ( V_130 ) ;
for ( V_43 = 0 ; V_43 < V_135 ; V_43 ++ ) {
if ( V_130 -> V_2 [ V_43 ] )
F_111 ( V_130 -> V_2 [ V_43 ] ) ;
}
F_109 ( V_130 -> V_4 ) ;
F_110 ( V_130 ) ;
return 0 ;
}
static int F_125 ( struct V_154 * V_82 )
{
struct V_156 * V_181 = F_126 ( V_82 ) ;
struct V_129 * V_130 = F_123 ( V_181 ) ;
struct V_1 * V_2 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_135 ; V_43 ++ ) {
V_2 = V_130 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
F_39 ( & V_2 -> V_63 ) ;
if ( F_41 ( ! V_2 -> V_76 ) )
goto V_182;
V_2 -> V_183 . V_6 = F_6 ( V_2 ) ;
V_2 -> V_64 = V_184 ;
F_43 ( & V_2 -> V_63 ) ;
}
return 0 ;
V_182:
for (; V_43 >= 0 ; V_43 -- ) {
V_2 = V_130 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
V_2 -> V_64 = V_65 ;
F_43 ( & V_2 -> V_63 ) ;
}
return - V_96 ;
}
static int F_127 ( struct V_154 * V_82 )
{
struct V_156 * V_181 = F_126 ( V_82 ) ;
struct V_129 * V_130 = F_123 ( V_181 ) ;
struct V_1 * V_2 ;
T_1 V_37 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_135 ; V_43 ++ ) {
V_2 = V_130 -> V_2 [ V_43 ] ;
if ( ! V_2 )
continue;
F_39 ( & V_2 -> V_63 ) ;
V_37 = V_2 -> V_183 . V_6
& ~ V_42 & ~ V_185 & ~ V_44 ;
F_5 ( V_2 , V_37 ) ;
V_2 -> V_64 = V_65 ;
F_43 ( & V_2 -> V_63 ) ;
}
return 0 ;
}
static T_7 int F_128 ( void )
{
F_129 ( L_41 ) ;
return F_130 ( & V_186 ) ;
}
static void T_8 F_131 ( void )
{
F_132 ( & V_186 ) ;
}
