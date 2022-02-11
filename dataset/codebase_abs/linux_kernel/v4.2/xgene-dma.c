static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
return ! ( V_3 & V_6 ) ;
}
static T_2 F_3 ( T_3 V_7 )
{
return ( V_7 < V_8 ) ?
( ( T_2 ) V_7 << V_9 ) :
V_10 ;
}
static T_4 F_4 ( T_1 V_11 )
{
static T_4 V_12 [] = {
V_13 ,
V_13 ,
V_13 ,
V_14 ,
V_15 ,
V_16
} ;
return V_12 [ V_11 ] ;
}
static T_1 F_5 ( struct V_17 * V_18 )
{
T_1 T_5 * V_19 = V_18 -> V_19 ;
T_1 V_20 = F_2 ( & V_19 [ 1 ] ) ;
return F_6 ( V_20 ) ;
}
static void F_7 ( T_6 * V_21 , T_3 * V_7 ,
T_7 * V_22 )
{
T_3 V_23 = ( * V_7 < V_8 ) ?
* V_7 : V_8 ;
* V_21 |= F_8 ( * V_22 ) ;
* V_21 |= F_8 ( F_3 ( V_23 ) ) ;
* V_7 -= V_23 ;
* V_22 += V_23 ;
}
static void F_9 ( T_6 * V_21 )
{
* V_21 |= F_8 ( V_24 ) ;
}
static T_6 * F_10 ( struct V_25 * V_26 , int V_27 )
{
switch ( V_27 ) {
case 0 :
return & V_26 -> V_28 ;
case 1 :
return & V_26 -> V_29 ;
case 2 :
return & V_26 -> V_30 ;
case 3 :
return & V_26 -> V_31 ;
default:
F_11 ( L_1 ) ;
}
return NULL ;
}
static void F_12 ( struct V_25 * V_26 ,
T_8 V_32 )
{
V_26 -> V_29 |= F_8 ( V_33 ) ;
V_26 -> V_29 |= F_8 ( ( T_2 ) V_34 <<
V_35 ) ;
V_26 -> V_28 |= F_8 ( V_36 ) ;
V_26 -> V_30 |= F_8 ( ( T_2 ) V_32 <<
V_37 ) ;
}
static void F_13 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
T_7 V_42 , T_7 V_43 ,
T_3 V_7 )
{
struct V_25 * V_44 , * V_45 ;
int V_46 ;
V_44 = & V_41 -> V_44 ;
F_12 ( V_44 , V_39 -> V_47 . V_32 ) ;
V_44 -> V_31 |= F_8 ( V_48 ) ;
V_44 -> V_30 |= F_8 ( V_42 ) ;
F_7 ( & V_44 -> V_28 , & V_7 , & V_43 ) ;
if ( ! V_7 )
return;
V_45 = & V_41 -> V_45 ;
V_44 -> V_29 |= F_8 ( V_49 ) ;
for ( V_46 = 0 ; V_46 < 4 && V_7 ; V_46 ++ )
F_7 ( F_10 ( V_45 , V_46 ) ,
& V_7 , & V_43 ) ;
for (; V_46 < 4 ; V_46 ++ )
F_9 ( F_10 ( V_45 , V_46 ) ) ;
V_41 -> V_50 |= V_51 ;
}
static void F_14 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
T_7 * V_42 , T_7 * V_43 ,
T_1 V_11 , T_3 * V_23 ,
const T_4 * V_52 )
{
struct V_25 * V_44 , * V_45 ;
T_3 V_7 = * V_23 ;
int V_46 ;
V_44 = & V_41 -> V_44 ;
V_45 = & V_41 -> V_45 ;
F_12 ( V_44 , V_39 -> V_47 . V_32 ) ;
V_44 -> V_31 |= F_8 ( V_48 ) ;
V_44 -> V_30 |= F_8 ( * V_42 ) ;
V_44 -> V_29 |= F_8 ( V_49 ) ;
V_44 -> V_31 |= F_8 ( F_4 ( V_11 ) ) ;
for ( V_46 = 0 ; V_46 < V_11 ; V_46 ++ ) {
V_7 = * V_23 ;
F_7 ( ( V_46 == 0 ) ? & V_44 -> V_28 :
F_10 ( V_45 , V_46 - 1 ) ,
& V_7 , & V_43 [ V_46 ] ) ;
V_44 -> V_31 |= F_8 ( ( V_52 [ V_46 ] << ( ( V_46 + 1 ) * 8 ) ) ) ;
}
* V_23 = V_7 ;
* V_42 += V_8 ;
V_41 -> V_50 |= V_51 ;
}
static T_9 F_15 ( struct V_53 * V_54 )
{
struct V_40 * V_26 ;
struct V_38 * V_39 ;
T_9 V_55 ;
if ( F_16 ( ! V_54 ) )
return - V_56 ;
V_39 = F_17 ( V_54 -> V_39 ) ;
V_26 = F_18 ( V_54 ) ;
F_19 ( & V_39 -> V_57 ) ;
V_55 = F_20 ( V_54 ) ;
F_21 ( & V_26 -> V_58 , & V_39 -> V_59 ) ;
F_22 ( & V_39 -> V_57 ) ;
return V_55 ;
}
static void F_23 ( struct V_38 * V_39 ,
struct V_40 * V_26 )
{
F_24 ( & V_26 -> V_60 ) ;
F_25 ( V_39 , L_2 , V_26 ) ;
F_26 ( V_39 -> V_61 , V_26 , V_26 -> V_54 . V_62 ) ;
}
static struct V_40 * F_27 (
struct V_38 * V_39 )
{
struct V_40 * V_26 ;
T_7 V_62 ;
V_26 = F_28 ( V_39 -> V_61 , V_63 , & V_62 ) ;
if ( ! V_26 ) {
F_29 ( V_39 , L_3 ) ;
return NULL ;
}
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
F_30 ( & V_26 -> V_58 ) ;
V_26 -> V_54 . V_62 = V_62 ;
V_26 -> V_54 . V_64 = F_15 ;
F_31 ( & V_26 -> V_54 , & V_39 -> V_65 ) ;
F_25 ( V_39 , L_4 , V_26 ) ;
return V_26 ;
}
static void F_32 ( struct V_38 * V_39 )
{
struct V_40 * V_26 , * V_66 ;
F_33 (desc, _desc, &chan->ld_completed, node) {
if ( F_34 ( & V_26 -> V_54 ) )
F_23 ( V_39 , V_26 ) ;
}
}
static void F_35 ( struct V_38 * V_39 ,
struct V_40 * V_26 )
{
struct V_53 * V_54 = & V_26 -> V_54 ;
if ( V_54 -> V_55 == 0 )
return;
F_36 ( V_54 ) ;
if ( V_54 -> V_67 )
V_54 -> V_67 ( V_54 -> V_68 ) ;
F_37 ( V_54 ) ;
F_38 ( V_54 ) ;
}
static void F_39 ( struct V_38 * V_39 ,
struct V_40 * V_26 )
{
F_24 ( & V_26 -> V_60 ) ;
if ( ! F_34 ( & V_26 -> V_54 ) ) {
F_40 ( & V_26 -> V_60 , & V_39 -> V_69 ) ;
return;
}
F_25 ( V_39 , L_2 , V_26 ) ;
F_26 ( V_39 -> V_61 , V_26 , V_26 -> V_54 . V_62 ) ;
}
static int F_41 ( struct V_17 * V_18 ,
struct V_40 * V_41 )
{
struct V_25 * V_70 ;
if ( F_5 ( V_18 ) > ( V_18 -> V_71 - 2 ) )
return - V_72 ;
V_70 = & V_18 -> V_70 [ V_18 -> V_73 ] ;
if ( ++ V_18 -> V_73 == V_18 -> V_71 )
V_18 -> V_73 = 0 ;
memcpy ( V_70 , & V_41 -> V_44 , sizeof( * V_70 ) ) ;
if ( V_41 -> V_50 & V_51 ) {
V_70 = & V_18 -> V_70 [ V_18 -> V_73 ] ;
if ( ++ V_18 -> V_73 == V_18 -> V_71 )
V_18 -> V_73 = 0 ;
memcpy ( V_70 , & V_41 -> V_45 , sizeof( * V_70 ) ) ;
}
F_42 ( ( V_41 -> V_50 & V_51 ) ?
2 : 1 , V_18 -> V_74 ) ;
return 0 ;
}
static void F_43 ( struct V_38 * V_39 )
{
struct V_40 * V_41 , * V_75 ;
int V_76 ;
if ( F_44 ( & V_39 -> V_59 ) ) {
F_25 ( V_39 , L_5 ) ;
return;
}
F_33 (desc_sw, _desc_sw, &chan->ld_pending, node) {
if ( V_39 -> V_77 >= V_39 -> V_78 )
return;
V_76 = F_41 ( & V_39 -> V_47 , V_41 ) ;
if ( V_76 )
return;
F_45 ( & V_41 -> V_60 , & V_39 -> V_79 ) ;
V_39 -> V_77 ++ ;
}
}
static void F_46 ( struct V_38 * V_39 )
{
struct V_17 * V_18 = & V_39 -> V_80 ;
struct V_40 * V_41 , * V_75 ;
struct V_25 * V_70 ;
T_4 V_81 ;
F_32 ( V_39 ) ;
F_33 (desc_sw, _desc_sw, &chan->ld_running, node) {
V_70 = & V_18 -> V_70 [ V_18 -> V_73 ] ;
if ( F_16 ( F_47 ( V_70 -> V_29 ) ==
V_82 ) )
break;
if ( ++ V_18 -> V_73 == V_18 -> V_71 )
V_18 -> V_73 = 0 ;
V_81 = F_48 (
F_49 ( F_47 (
V_70 -> V_29 ) ) ,
F_50 ( F_47 (
V_70 -> V_29 ) ) ) ;
if ( V_81 ) {
F_29 ( V_39 , L_6 , V_83 [ V_81 ] ) ;
F_51 ( & V_41 -> V_44 ,
L_7 ) ;
if ( V_41 -> V_50 & V_51 )
F_51 ( & V_41 -> V_45 ,
L_8 ) ;
F_51 ( V_70 ,
L_9 ) ;
}
F_42 ( - 1 , V_18 -> V_74 ) ;
V_70 -> V_29 = F_8 ( V_82 ) ;
F_35 ( V_39 , V_41 ) ;
F_39 ( V_39 , V_41 ) ;
V_39 -> V_77 -- ;
}
F_43 ( V_39 ) ;
}
static int F_52 ( struct V_65 * V_84 )
{
struct V_38 * V_39 = F_17 ( V_84 ) ;
if ( V_39 -> V_61 )
return 1 ;
V_39 -> V_61 = F_53 ( V_39 -> V_85 , V_39 -> V_86 ,
sizeof( struct V_40 ) ,
0 , 0 ) ;
if ( ! V_39 -> V_61 ) {
F_29 ( V_39 , L_10 ) ;
return - V_87 ;
}
F_25 ( V_39 , L_11 ) ;
return 1 ;
}
static void F_54 ( struct V_38 * V_39 ,
struct V_88 * V_89 )
{
struct V_40 * V_26 , * V_66 ;
F_33 (desc, _desc, list, node)
F_23 ( V_39 , V_26 ) ;
}
static void F_55 ( struct V_65 * V_84 )
{
struct V_38 * V_39 = F_17 ( V_84 ) ;
F_25 ( V_39 , L_12 ) ;
if ( ! V_39 -> V_61 )
return;
F_19 ( & V_39 -> V_57 ) ;
F_46 ( V_39 ) ;
F_54 ( V_39 , & V_39 -> V_59 ) ;
F_54 ( V_39 , & V_39 -> V_79 ) ;
F_54 ( V_39 , & V_39 -> V_69 ) ;
F_22 ( & V_39 -> V_57 ) ;
F_56 ( V_39 -> V_61 ) ;
V_39 -> V_61 = NULL ;
}
static struct V_53 * F_57 (
struct V_65 * V_84 , T_7 V_42 , T_7 V_43 ,
T_3 V_7 , unsigned long V_50 )
{
struct V_40 * V_90 = NULL , * V_91 ;
struct V_38 * V_39 ;
T_3 V_92 ;
if ( F_16 ( ! V_84 || ! V_7 ) )
return NULL ;
V_39 = F_17 ( V_84 ) ;
do {
V_91 = F_27 ( V_39 ) ;
if ( ! V_91 )
goto V_93;
V_92 = F_58 ( T_3 , V_7 , V_94 ) ;
F_13 ( V_39 , V_91 , V_42 , V_43 , V_92 ) ;
if ( ! V_90 )
V_90 = V_91 ;
V_91 -> V_54 . V_55 = 0 ;
F_59 ( & V_91 -> V_54 ) ;
V_7 -= V_92 ;
V_42 += V_92 ;
V_43 += V_92 ;
F_40 ( & V_91 -> V_60 , & V_90 -> V_58 ) ;
} while ( V_7 );
V_91 -> V_54 . V_50 = V_50 ;
V_91 -> V_54 . V_55 = - V_72 ;
F_60 ( & V_90 -> V_58 , & V_91 -> V_58 ) ;
return & V_91 -> V_54 ;
V_93:
if ( ! V_90 )
return NULL ;
F_54 ( V_39 , & V_90 -> V_58 ) ;
return NULL ;
}
static struct V_53 * F_61 (
struct V_65 * V_84 , struct V_95 * V_96 ,
T_1 V_97 , struct V_95 * V_98 ,
T_1 V_99 , unsigned long V_50 )
{
struct V_40 * V_90 = NULL , * V_91 = NULL ;
struct V_38 * V_39 ;
T_3 V_100 , V_101 ;
T_7 V_42 , V_43 ;
T_3 V_7 ;
if ( F_16 ( ! V_84 ) )
return NULL ;
if ( F_16 ( ! V_97 || ! V_99 ) )
return NULL ;
if ( F_16 ( ! V_96 || ! V_98 ) )
return NULL ;
V_39 = F_17 ( V_84 ) ;
V_100 = F_62 ( V_96 ) ;
V_101 = F_62 ( V_98 ) ;
V_97 -- ;
V_99 -- ;
while ( true ) {
V_7 = F_58 ( T_3 , V_101 , V_100 ) ;
V_7 = F_58 ( T_3 , V_7 , V_94 ) ;
if ( V_7 == 0 )
goto V_102;
V_42 = F_63 ( V_96 ) + F_62 ( V_96 ) - V_100 ;
V_43 = F_63 ( V_98 ) + F_62 ( V_98 ) - V_101 ;
V_91 = F_27 ( V_39 ) ;
if ( ! V_91 )
goto V_93;
F_13 ( V_39 , V_91 , V_42 , V_43 , V_7 ) ;
if ( ! V_90 )
V_90 = V_91 ;
V_91 -> V_54 . V_55 = 0 ;
F_59 ( & V_91 -> V_54 ) ;
V_100 -= V_7 ;
V_101 -= V_7 ;
F_40 ( & V_91 -> V_60 , & V_90 -> V_58 ) ;
V_102:
if ( V_100 == 0 ) {
if ( V_97 == 0 )
break;
V_96 = F_64 ( V_96 ) ;
if ( ! V_96 )
break;
V_97 -- ;
V_100 = F_62 ( V_96 ) ;
}
if ( V_101 == 0 ) {
if ( V_99 == 0 )
break;
V_98 = F_64 ( V_98 ) ;
if ( ! V_98 )
break;
V_99 -- ;
V_101 = F_62 ( V_98 ) ;
}
}
if ( ! V_91 )
return NULL ;
V_91 -> V_54 . V_50 = V_50 ;
V_91 -> V_54 . V_55 = - V_72 ;
F_60 ( & V_90 -> V_58 , & V_91 -> V_58 ) ;
return & V_91 -> V_54 ;
V_93:
if ( ! V_90 )
return NULL ;
F_54 ( V_39 , & V_90 -> V_58 ) ;
return NULL ;
}
static struct V_53 * F_65 (
struct V_65 * V_84 , T_7 V_42 , T_7 * V_43 ,
T_1 V_11 , T_3 V_7 , unsigned long V_50 )
{
struct V_40 * V_90 = NULL , * V_91 ;
struct V_38 * V_39 ;
static T_4 V_103 [ V_104 ] = {
0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_16 ( ! V_84 || ! V_7 ) )
return NULL ;
V_39 = F_17 ( V_84 ) ;
do {
V_91 = F_27 ( V_39 ) ;
if ( ! V_91 )
goto V_93;
F_14 ( V_39 , V_91 , & V_42 , V_43 ,
V_11 , & V_7 , V_103 ) ;
if ( ! V_90 )
V_90 = V_91 ;
V_91 -> V_54 . V_55 = 0 ;
F_59 ( & V_91 -> V_54 ) ;
F_40 ( & V_91 -> V_60 , & V_90 -> V_58 ) ;
} while ( V_7 );
V_91 -> V_54 . V_50 = V_50 ;
V_91 -> V_54 . V_55 = - V_72 ;
F_60 ( & V_90 -> V_58 , & V_91 -> V_58 ) ;
return & V_91 -> V_54 ;
V_93:
if ( ! V_90 )
return NULL ;
F_54 ( V_39 , & V_90 -> V_58 ) ;
return NULL ;
}
static struct V_53 * F_66 (
struct V_65 * V_84 , T_7 * V_42 , T_7 * V_43 ,
T_1 V_11 , const T_4 * V_52 , T_3 V_7 , unsigned long V_50 )
{
struct V_40 * V_90 = NULL , * V_91 ;
struct V_38 * V_39 ;
T_3 V_105 = V_7 ;
T_7 V_106 [ V_104 ] ;
static T_4 V_103 [ V_104 ] = { 0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_16 ( ! V_84 || ! V_7 ) )
return NULL ;
V_39 = F_17 ( V_84 ) ;
memcpy ( V_106 , V_43 , sizeof( * V_43 ) * V_11 ) ;
if ( V_50 & V_107 )
V_7 = 0 ;
if ( V_50 & V_108 )
V_105 = 0 ;
do {
V_91 = F_27 ( V_39 ) ;
if ( ! V_91 )
goto V_93;
if ( ! V_90 )
V_90 = V_91 ;
V_91 -> V_54 . V_55 = 0 ;
F_59 ( & V_91 -> V_54 ) ;
F_40 ( & V_91 -> V_60 , & V_90 -> V_58 ) ;
if ( V_7 ) {
F_14 ( V_39 , V_91 , & V_42 [ 0 ] , V_43 ,
V_11 , & V_7 , V_103 ) ;
continue;
}
if ( V_105 ) {
F_14 ( V_39 , V_91 , & V_42 [ 1 ] , V_106 ,
V_11 , & V_105 , V_52 ) ;
}
} while ( V_7 || V_105 );
V_91 -> V_54 . V_50 = V_50 ;
V_91 -> V_54 . V_55 = - V_72 ;
F_60 ( & V_90 -> V_58 , & V_91 -> V_58 ) ;
return & V_91 -> V_54 ;
V_93:
if ( ! V_90 )
return NULL ;
F_54 ( V_39 , & V_90 -> V_58 ) ;
return NULL ;
}
static void F_67 ( struct V_65 * V_84 )
{
struct V_38 * V_39 = F_17 ( V_84 ) ;
F_19 ( & V_39 -> V_57 ) ;
F_43 ( V_39 ) ;
F_22 ( & V_39 -> V_57 ) ;
}
static enum V_109 F_68 ( struct V_65 * V_84 ,
T_9 V_55 ,
struct V_110 * V_111 )
{
return F_69 ( V_84 , V_55 , V_111 ) ;
}
static void F_70 ( unsigned long V_112 )
{
struct V_38 * V_39 = (struct V_38 * ) V_112 ;
F_19 ( & V_39 -> V_57 ) ;
F_46 ( V_39 ) ;
F_71 ( V_39 -> V_113 ) ;
F_22 ( & V_39 -> V_57 ) ;
}
static T_10 F_72 ( int V_114 , void * V_115 )
{
struct V_38 * V_39 = (struct V_38 * ) V_115 ;
F_73 ( ! V_39 ) ;
F_74 ( V_39 -> V_113 ) ;
F_75 ( & V_39 -> V_116 ) ;
return V_117 ;
}
static T_10 F_76 ( int V_114 , void * V_115 )
{
struct V_1 * V_2 = (struct V_1 * ) V_115 ;
unsigned long V_118 ;
T_1 V_3 , V_46 ;
V_3 = F_2 ( V_2 -> V_119 + V_120 ) ;
F_42 ( V_3 , V_2 -> V_119 + V_120 ) ;
V_118 = V_3 >> V_121 ;
F_77 (i, &int_mask, ARRAY_SIZE(xgene_dma_err))
F_78 ( V_2 -> V_86 ,
L_13 , V_3 , V_122 [ V_46 ] ) ;
return V_117 ;
}
static void F_79 ( struct V_17 * V_18 )
{
int V_46 ;
F_42 ( V_18 -> V_123 , V_18 -> V_2 -> V_124 + V_125 ) ;
for ( V_46 = 0 ; V_46 < V_126 ; V_46 ++ )
F_42 ( V_18 -> V_127 [ V_46 ] , V_18 -> V_2 -> V_124 +
V_128 + ( V_46 * 4 ) ) ;
}
static void F_80 ( struct V_17 * V_18 )
{
memset ( V_18 -> V_127 , 0 , sizeof( T_1 ) * V_126 ) ;
F_79 ( V_18 ) ;
}
static void F_81 ( struct V_17 * V_18 )
{
void * V_129 = V_18 -> V_127 ;
T_2 V_130 = V_18 -> V_131 ;
T_1 V_46 , V_3 ;
V_18 -> V_71 = V_18 -> V_132 / V_133 ;
F_80 ( V_18 ) ;
F_82 ( V_129 , V_134 ) ;
if ( V_18 -> V_135 == V_34 ) {
F_83 ( V_129 ) ;
F_84 ( V_129 ) ;
F_85 ( V_129 ) ;
}
F_86 ( V_129 ) ;
F_87 ( V_129 ) ;
F_88 ( V_129 ) ;
F_89 ( V_129 , V_130 ) ;
F_90 ( V_129 , V_130 ) ;
F_91 ( V_129 , V_18 -> V_136 ) ;
F_79 ( V_18 ) ;
F_42 ( F_92 ( V_18 -> V_115 ) ,
V_18 -> V_2 -> V_124 + V_137 ) ;
F_42 ( F_93 ( V_18 -> V_123 ) ,
V_18 -> V_2 -> V_124 + V_138 ) ;
if ( V_18 -> V_135 != V_139 )
return;
for ( V_46 = 0 ; V_46 < V_18 -> V_71 ; V_46 ++ ) {
struct V_25 * V_26 ;
V_26 = & V_18 -> V_70 [ V_46 ] ;
V_26 -> V_29 = F_8 ( V_82 ) ;
}
V_3 = F_2 ( V_18 -> V_2 -> V_124 + V_140 ) ;
F_94 ( V_3 , V_18 -> V_141 ) ;
F_42 ( V_3 , V_18 -> V_2 -> V_124 + V_140 ) ;
}
static void F_95 ( struct V_17 * V_18 )
{
T_1 V_142 , V_3 ;
if ( V_18 -> V_135 == V_139 ) {
V_3 = F_2 ( V_18 -> V_2 -> V_124 +
V_140 ) ;
F_96 ( V_3 , V_18 -> V_141 ) ;
F_42 ( V_3 , V_18 -> V_2 -> V_124 +
V_140 ) ;
}
V_142 = F_92 ( V_18 -> V_115 ) ;
F_42 ( V_142 , V_18 -> V_2 -> V_124 + V_137 ) ;
F_42 ( 0 , V_18 -> V_2 -> V_124 + V_138 ) ;
F_80 ( V_18 ) ;
}
static void F_97 ( struct V_17 * V_18 )
{
V_18 -> V_19 = V_18 -> V_2 -> V_143 +
F_98 ( ( V_18 -> V_123 -
V_144 ) ) ;
V_18 -> V_74 = V_18 -> V_19 + V_145 ;
}
static int F_99 ( struct V_38 * V_39 ,
enum V_146 V_136 )
{
int V_132 ;
switch ( V_136 ) {
case V_147 :
V_132 = 0x200 ;
break;
case V_148 :
V_132 = 0x800 ;
break;
case V_149 :
V_132 = 0x4000 ;
break;
case V_150 :
V_132 = 0x10000 ;
break;
case V_151 :
V_132 = 0x80000 ;
break;
default:
F_29 ( V_39 , L_14 , V_136 ) ;
return - V_56 ;
}
return V_132 ;
}
static void F_100 ( struct V_17 * V_18 )
{
F_95 ( V_18 ) ;
if ( V_18 -> V_152 ) {
F_101 ( V_18 -> V_2 -> V_86 , V_18 -> V_132 ,
V_18 -> V_152 , V_18 -> V_131 ) ;
V_18 -> V_152 = NULL ;
}
}
static void F_102 ( struct V_38 * V_39 )
{
F_100 ( & V_39 -> V_80 ) ;
F_100 ( & V_39 -> V_47 ) ;
}
static int F_103 ( struct V_38 * V_39 ,
struct V_17 * V_18 ,
enum V_146 V_136 )
{
V_18 -> V_2 = V_39 -> V_2 ;
V_18 -> V_136 = V_136 ;
V_18 -> V_123 = V_39 -> V_2 -> V_153 ++ ;
V_18 -> V_115 = F_104 ( V_18 -> V_135 , V_18 -> V_141 ) ;
V_18 -> V_132 = F_99 ( V_39 , V_136 ) ;
if ( V_18 -> V_132 <= 0 )
return V_18 -> V_132 ;
V_18 -> V_152 = F_105 ( V_39 -> V_86 , V_18 -> V_132 ,
& V_18 -> V_131 , V_154 ) ;
if ( ! V_18 -> V_152 ) {
F_29 ( V_39 , L_15 ) ;
return - V_87 ;
}
F_97 ( V_18 ) ;
F_81 ( V_18 ) ;
return 0 ;
}
static int F_106 ( struct V_38 * V_39 )
{
struct V_17 * V_80 = & V_39 -> V_80 ;
struct V_17 * V_47 = & V_39 -> V_47 ;
int V_76 ;
V_80 -> V_135 = V_139 ;
V_80 -> V_141 = V_155 + V_39 -> V_115 ;
V_76 = F_103 ( V_39 , V_80 ,
V_150 ) ;
if ( V_76 )
return V_76 ;
F_25 ( V_39 , L_16 ,
V_80 -> V_115 , V_80 -> V_123 , V_80 -> V_152 ) ;
V_47 -> V_135 = V_34 ;
V_47 -> V_141 = V_156 + V_39 -> V_115 ;
V_76 = F_103 ( V_39 , V_47 ,
V_150 ) ;
if ( V_76 ) {
F_100 ( V_80 ) ;
return V_76 ;
}
V_47 -> V_32 = F_107 ( V_80 -> V_123 ) ;
F_25 ( V_39 ,
L_17 ,
V_47 -> V_115 , V_47 -> V_123 , V_47 -> V_152 ) ;
V_39 -> V_78 = V_80 -> V_71 ;
return V_76 ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_76 , V_46 , V_157 ;
for ( V_46 = 0 ; V_46 < V_158 ; V_46 ++ ) {
V_76 = F_106 ( & V_2 -> V_39 [ V_46 ] ) ;
if ( V_76 ) {
for ( V_157 = 0 ; V_157 < V_46 ; V_157 ++ )
F_102 ( & V_2 -> V_39 [ V_157 ] ) ;
return V_76 ;
}
}
return V_76 ;
}
static void F_109 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_119 + V_159 ) ;
F_110 ( V_3 ) ;
F_111 ( V_3 ) ;
F_42 ( V_3 , V_2 -> V_119 + V_159 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_119 + V_159 ) ;
F_113 ( V_3 ) ;
F_42 ( V_3 , V_2 -> V_119 + V_159 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
F_42 ( V_160 ,
V_2 -> V_119 + V_161 ) ;
F_42 ( V_160 ,
V_2 -> V_119 + V_162 ) ;
F_42 ( V_160 ,
V_2 -> V_119 + V_163 ) ;
F_42 ( V_160 ,
V_2 -> V_119 + V_164 ) ;
F_42 ( V_160 ,
V_2 -> V_119 + V_165 ) ;
F_42 ( V_160 , V_2 -> V_119 + V_166 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
F_42 ( V_167 ,
V_2 -> V_119 + V_161 ) ;
F_42 ( V_167 ,
V_2 -> V_119 + V_162 ) ;
F_42 ( V_167 ,
V_2 -> V_119 + V_163 ) ;
F_42 ( V_167 ,
V_2 -> V_119 + V_164 ) ;
F_42 ( V_167 ,
V_2 -> V_119 + V_165 ) ;
F_42 ( V_167 ,
V_2 -> V_119 + V_166 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_42 ( V_168 ,
V_2 -> V_119 + V_169 ) ;
if ( F_1 ( V_2 ) )
F_42 ( F_117 ( 0x1D ) ,
V_2 -> V_119 + V_170 ) ;
else
F_118 ( V_2 -> V_86 , L_18 ) ;
F_109 ( V_2 ) ;
F_115 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_119 + V_171 ) ;
F_118 ( V_2 -> V_86 ,
L_19 ,
F_119 ( V_3 ) , F_120 ( V_3 ) ,
F_121 ( V_3 ) , V_158 ) ;
}
static int F_122 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_124 + V_172 ) &&
( ! F_2 ( V_2 -> V_124 + V_173 ) ) )
return 0 ;
F_42 ( 0x3 , V_2 -> V_124 + V_172 ) ;
F_42 ( 0x0 , V_2 -> V_124 + V_173 ) ;
F_42 ( 0x0 , V_2 -> V_124 + V_174 ) ;
F_2 ( V_2 -> V_124 + V_174 ) ;
F_123 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_124 + V_175 )
!= V_176 ) {
F_78 ( V_2 -> V_86 ,
L_20 ) ;
return - V_177 ;
}
F_42 ( V_178 ,
V_2 -> V_124 + V_179 ) ;
F_42 ( V_180 ,
V_2 -> V_124 + V_181 ) ;
F_42 ( V_182 ,
V_2 -> V_124 + V_183 ) ;
F_42 ( V_184 ,
V_2 -> V_124 + V_185 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 )
{
int V_76 ;
V_76 = F_122 ( V_2 ) ;
if ( V_76 )
return V_76 ;
F_42 ( 0x0 , V_2 -> V_119 + V_186 ) ;
F_2 ( V_2 -> V_119 + V_186 ) ;
F_123 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_119 + V_187 )
!= V_188 ) {
F_78 ( V_2 -> V_86 ,
L_21 ) ;
return - V_177 ;
}
return 0 ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
int V_76 , V_46 , V_157 ;
V_76 = F_126 ( V_2 -> V_86 , V_2 -> V_189 , F_76 ,
0 , L_22 , V_2 ) ;
if ( V_76 ) {
F_78 ( V_2 -> V_86 ,
L_23 , V_2 -> V_189 ) ;
return V_76 ;
}
for ( V_46 = 0 ; V_46 < V_158 ; V_46 ++ ) {
V_39 = & V_2 -> V_39 [ V_46 ] ;
V_76 = F_126 ( V_39 -> V_86 , V_39 -> V_113 ,
F_72 ,
0 , V_39 -> V_85 , V_39 ) ;
if ( V_76 ) {
F_29 ( V_39 , L_24 ,
V_39 -> V_113 ) ;
F_127 ( V_2 -> V_86 , V_2 -> V_189 , V_2 ) ;
for ( V_157 = 0 ; V_157 < V_46 ; V_157 ++ ) {
V_39 = & V_2 -> V_39 [ V_46 ] ;
F_127 ( V_39 -> V_86 , V_39 -> V_113 , V_39 ) ;
}
return V_76 ;
}
}
return 0 ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
int V_46 ;
F_127 ( V_2 -> V_86 , V_2 -> V_189 , V_2 ) ;
for ( V_46 = 0 ; V_46 < V_158 ; V_46 ++ ) {
V_39 = & V_2 -> V_39 [ V_46 ] ;
F_127 ( V_39 -> V_86 , V_39 -> V_113 , V_39 ) ;
}
}
static void F_129 ( struct V_38 * V_39 ,
struct V_190 * V_191 )
{
F_130 ( V_191 -> V_192 ) ;
F_131 ( V_193 , V_191 -> V_192 ) ;
F_131 ( V_194 , V_191 -> V_192 ) ;
if ( ( V_39 -> V_115 == V_195 ) &&
F_1 ( V_39 -> V_2 ) ) {
F_131 ( V_196 , V_191 -> V_192 ) ;
F_131 ( V_197 , V_191 -> V_192 ) ;
} else if ( ( V_39 -> V_115 == V_198 ) &&
! F_1 ( V_39 -> V_2 ) ) {
F_131 ( V_197 , V_191 -> V_192 ) ;
}
V_191 -> V_86 = V_39 -> V_86 ;
V_191 -> V_199 = F_52 ;
V_191 -> V_200 = F_55 ;
V_191 -> V_201 = F_67 ;
V_191 -> V_202 = F_68 ;
V_191 -> V_203 = F_57 ;
V_191 -> V_204 = F_61 ;
if ( F_132 ( V_197 , V_191 -> V_192 ) ) {
V_191 -> V_205 = F_65 ;
V_191 -> V_206 = V_104 ;
V_191 -> V_207 = V_208 ;
}
if ( F_132 ( V_196 , V_191 -> V_192 ) ) {
V_191 -> V_209 = F_66 ;
V_191 -> V_210 = V_104 ;
V_191 -> V_211 = V_208 ;
}
}
static int F_133 ( struct V_1 * V_2 , int V_115 )
{
struct V_38 * V_39 = & V_2 -> V_39 [ V_115 ] ;
struct V_190 * V_191 = & V_2 -> V_191 [ V_115 ] ;
int V_76 ;
V_39 -> V_65 . V_212 = V_191 ;
F_134 ( & V_39 -> V_57 ) ;
F_30 ( & V_39 -> V_59 ) ;
F_30 ( & V_39 -> V_79 ) ;
F_30 ( & V_39 -> V_69 ) ;
F_135 ( & V_39 -> V_116 , F_70 ,
( unsigned long ) V_39 ) ;
V_39 -> V_77 = 0 ;
V_39 -> V_61 = NULL ;
F_136 ( & V_39 -> V_65 ) ;
F_129 ( V_39 , V_191 ) ;
F_30 ( & V_191 -> V_213 ) ;
F_40 ( & V_39 -> V_65 . V_214 , & V_191 -> V_213 ) ;
V_76 = F_137 ( V_191 ) ;
if ( V_76 ) {
F_29 ( V_39 , L_25 , V_76 ) ;
F_138 ( & V_39 -> V_116 ) ;
return V_76 ;
}
F_118 ( V_2 -> V_86 ,
L_26 , F_139 ( & V_39 -> V_65 ) ,
F_132 ( V_193 , V_191 -> V_192 ) ? L_27 : L_28 ,
F_132 ( V_194 , V_191 -> V_192 ) ? L_29 : L_28 ,
F_132 ( V_197 , V_191 -> V_192 ) ? L_30 : L_28 ,
F_132 ( V_196 , V_191 -> V_192 ) ? L_31 : L_28 ) ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 )
{
int V_76 , V_46 , V_157 ;
for ( V_46 = 0 ; V_46 < V_158 ; V_46 ++ ) {
V_76 = F_133 ( V_2 , V_46 ) ;
if ( V_76 ) {
for ( V_157 = 0 ; V_157 < V_46 ; V_157 ++ ) {
F_141 ( & V_2 -> V_191 [ V_157 ] ) ;
F_138 ( & V_2 -> V_39 [ V_157 ] . V_116 ) ;
}
return V_76 ;
}
}
return V_76 ;
}
static void F_142 ( struct V_1 * V_2 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_158 ; V_46 ++ )
F_141 ( & V_2 -> V_191 [ V_46 ] ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
int V_46 ;
V_2 -> V_153 = V_144 ;
for ( V_46 = 0 ; V_46 < V_158 ; V_46 ++ ) {
V_39 = & V_2 -> V_39 [ V_46 ] ;
V_39 -> V_86 = V_2 -> V_86 ;
V_39 -> V_2 = V_2 ;
V_39 -> V_115 = V_46 ;
snprintf ( V_39 -> V_85 , sizeof( V_39 -> V_85 ) , L_32 , V_39 -> V_115 ) ;
}
}
static int F_144 ( struct V_215 * V_216 ,
struct V_1 * V_2 )
{
struct V_217 * V_218 ;
int V_114 , V_46 ;
V_218 = F_145 ( V_216 , V_219 , 0 ) ;
if ( ! V_218 ) {
F_78 ( & V_216 -> V_86 , L_33 ) ;
return - V_220 ;
}
V_2 -> V_119 = F_146 ( & V_216 -> V_86 , V_218 -> V_221 ,
F_147 ( V_218 ) ) ;
if ( ! V_2 -> V_119 ) {
F_78 ( & V_216 -> V_86 , L_34 ) ;
return - V_87 ;
}
V_218 = F_145 ( V_216 , V_219 , 1 ) ;
if ( ! V_218 ) {
F_78 ( & V_216 -> V_86 , L_35 ) ;
return - V_220 ;
}
V_2 -> V_124 = F_146 ( & V_216 -> V_86 , V_218 -> V_221 ,
F_147 ( V_218 ) ) ;
if ( ! V_2 -> V_124 ) {
F_78 ( & V_216 -> V_86 , L_36 ) ;
return - V_87 ;
}
V_218 = F_145 ( V_216 , V_219 , 2 ) ;
if ( ! V_218 ) {
F_78 ( & V_216 -> V_86 , L_37 ) ;
return - V_220 ;
}
V_2 -> V_143 = F_146 ( & V_216 -> V_86 , V_218 -> V_221 ,
F_147 ( V_218 ) ) ;
if ( ! V_2 -> V_143 ) {
F_78 ( & V_216 -> V_86 , L_38 ) ;
return - V_87 ;
}
V_2 -> V_143 += V_222 ;
V_218 = F_145 ( V_216 , V_219 , 3 ) ;
if ( ! V_218 ) {
F_78 ( & V_216 -> V_86 , L_39 ) ;
return - V_220 ;
}
V_2 -> V_4 = F_146 ( & V_216 -> V_86 , V_218 -> V_221 ,
F_147 ( V_218 ) ) ;
if ( ! V_2 -> V_4 ) {
F_78 ( & V_216 -> V_86 , L_40 ) ;
return - V_87 ;
}
V_114 = F_148 ( V_216 , 0 ) ;
if ( V_114 <= 0 ) {
F_78 ( & V_216 -> V_86 , L_41 ) ;
return - V_220 ;
}
V_2 -> V_189 = V_114 ;
for ( V_46 = 1 ; V_46 <= V_158 ; V_46 ++ ) {
V_114 = F_148 ( V_216 , V_46 ) ;
if ( V_114 <= 0 ) {
F_78 ( & V_216 -> V_86 , L_42 ) ;
return - V_220 ;
}
V_2 -> V_39 [ V_46 - 1 ] . V_113 = V_114 ;
}
return 0 ;
}
static int F_149 ( struct V_215 * V_216 )
{
struct V_1 * V_2 ;
int V_76 , V_46 ;
V_2 = F_150 ( & V_216 -> V_86 , sizeof( * V_2 ) , V_154 ) ;
if ( ! V_2 )
return - V_87 ;
V_2 -> V_86 = & V_216 -> V_86 ;
F_151 ( V_216 , V_2 ) ;
V_76 = F_144 ( V_216 , V_2 ) ;
if ( V_76 )
return V_76 ;
V_2 -> V_223 = F_152 ( & V_216 -> V_86 , NULL ) ;
if ( F_153 ( V_2 -> V_223 ) ) {
F_78 ( & V_216 -> V_86 , L_43 ) ;
return F_154 ( V_2 -> V_223 ) ;
}
V_76 = F_155 ( V_2 -> V_223 ) ;
if ( V_76 ) {
F_78 ( & V_216 -> V_86 , L_44 , V_76 ) ;
return V_76 ;
}
V_76 = F_124 ( V_2 ) ;
if ( V_76 )
goto V_224;
V_76 = F_156 ( & V_216 -> V_86 , F_157 ( 42 ) ) ;
if ( V_76 ) {
F_78 ( & V_216 -> V_86 , L_45 ) ;
goto V_225;
}
F_143 ( V_2 ) ;
V_76 = F_108 ( V_2 ) ;
if ( V_76 )
goto V_224;
V_76 = F_125 ( V_2 ) ;
if ( V_76 )
goto V_226;
F_116 ( V_2 ) ;
V_76 = F_140 ( V_2 ) ;
if ( V_76 )
goto V_227;
return 0 ;
V_227:
F_128 ( V_2 ) ;
V_226:
for ( V_46 = 0 ; V_46 < V_158 ; V_46 ++ )
F_102 ( & V_2 -> V_39 [ V_46 ] ) ;
V_225:
V_224:
F_158 ( V_2 -> V_223 ) ;
return V_76 ;
}
static int F_159 ( struct V_215 * V_216 )
{
struct V_1 * V_2 = F_160 ( V_216 ) ;
struct V_38 * V_39 ;
int V_46 ;
F_142 ( V_2 ) ;
F_114 ( V_2 ) ;
F_112 ( V_2 ) ;
F_128 ( V_2 ) ;
for ( V_46 = 0 ; V_46 < V_158 ; V_46 ++ ) {
V_39 = & V_2 -> V_39 [ V_46 ] ;
F_138 ( & V_39 -> V_116 ) ;
F_102 ( V_39 ) ;
}
F_158 ( V_2 -> V_223 ) ;
return 0 ;
}
