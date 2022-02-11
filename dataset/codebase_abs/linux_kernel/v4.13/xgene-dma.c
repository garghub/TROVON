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
static void F_5 ( T_5 * V_17 , T_3 * V_7 ,
T_6 * V_18 )
{
T_3 V_19 = ( * V_7 < V_8 ) ?
* V_7 : V_8 ;
* V_17 |= F_6 ( * V_18 ) ;
* V_17 |= F_6 ( F_3 ( V_19 ) ) ;
* V_7 -= V_19 ;
* V_18 += V_19 ;
}
static void F_7 ( T_5 * V_17 )
{
* V_17 |= F_6 ( V_20 ) ;
}
static T_5 * F_8 ( struct V_21 * V_22 , int V_23 )
{
switch ( V_23 ) {
case 0 :
return & V_22 -> V_24 ;
case 1 :
return & V_22 -> V_25 ;
case 2 :
return & V_22 -> V_26 ;
case 3 :
return & V_22 -> V_27 ;
default:
F_9 ( L_1 ) ;
}
return NULL ;
}
static void F_10 ( struct V_21 * V_22 ,
T_7 V_28 )
{
V_22 -> V_25 |= F_6 ( V_29 ) ;
V_22 -> V_25 |= F_6 ( ( T_2 ) V_30 <<
V_31 ) ;
V_22 -> V_24 |= F_6 ( V_32 ) ;
V_22 -> V_26 |= F_6 ( ( T_2 ) V_28 <<
V_33 ) ;
}
static void F_11 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
T_6 V_38 , T_6 V_39 ,
T_3 V_7 )
{
struct V_21 * V_40 , * V_41 ;
int V_42 ;
V_40 = & V_37 -> V_40 ;
F_10 ( V_40 , V_35 -> V_43 . V_28 ) ;
V_40 -> V_27 |= F_6 ( V_44 ) ;
V_40 -> V_26 |= F_6 ( V_38 ) ;
F_5 ( & V_40 -> V_24 , & V_7 , & V_39 ) ;
if ( ! V_7 )
return;
V_41 = & V_37 -> V_41 ;
V_40 -> V_25 |= F_6 ( V_45 ) ;
for ( V_42 = 0 ; V_42 < 4 && V_7 ; V_42 ++ )
F_5 ( F_8 ( V_41 , V_42 ) ,
& V_7 , & V_39 ) ;
for (; V_42 < 4 ; V_42 ++ )
F_7 ( F_8 ( V_41 , V_42 ) ) ;
V_37 -> V_46 |= V_47 ;
}
static void F_12 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
T_6 * V_38 , T_6 * V_39 ,
T_1 V_11 , T_3 * V_19 ,
const T_4 * V_48 )
{
struct V_21 * V_40 , * V_41 ;
T_3 V_7 = * V_19 ;
int V_42 ;
V_40 = & V_37 -> V_40 ;
V_41 = & V_37 -> V_41 ;
F_10 ( V_40 , V_35 -> V_43 . V_28 ) ;
V_40 -> V_27 |= F_6 ( V_44 ) ;
V_40 -> V_26 |= F_6 ( * V_38 ) ;
V_40 -> V_25 |= F_6 ( V_45 ) ;
V_40 -> V_27 |= F_6 ( F_4 ( V_11 ) ) ;
for ( V_42 = 0 ; V_42 < V_11 ; V_42 ++ ) {
V_7 = * V_19 ;
F_5 ( ( V_42 == 0 ) ? & V_40 -> V_24 :
F_8 ( V_41 , V_42 - 1 ) ,
& V_7 , & V_39 [ V_42 ] ) ;
V_40 -> V_27 |= F_6 ( ( V_48 [ V_42 ] << ( ( V_42 + 1 ) * 8 ) ) ) ;
}
* V_19 = V_7 ;
* V_38 += V_8 ;
V_37 -> V_46 |= V_47 ;
}
static T_8 F_13 ( struct V_49 * V_50 )
{
struct V_36 * V_22 ;
struct V_34 * V_35 ;
T_8 V_51 ;
if ( F_14 ( ! V_50 ) )
return - V_52 ;
V_35 = F_15 ( V_50 -> V_35 ) ;
V_22 = F_16 ( V_50 ) ;
F_17 ( & V_35 -> V_53 ) ;
V_51 = F_18 ( V_50 ) ;
F_19 ( & V_22 -> V_54 , & V_35 -> V_55 ) ;
F_20 ( & V_35 -> V_53 ) ;
return V_51 ;
}
static void F_21 ( struct V_34 * V_35 ,
struct V_36 * V_22 )
{
F_22 ( & V_22 -> V_56 ) ;
F_23 ( V_35 , L_2 , V_22 ) ;
F_24 ( V_35 -> V_57 , V_22 , V_22 -> V_50 . V_58 ) ;
}
static struct V_36 * F_25 (
struct V_34 * V_35 )
{
struct V_36 * V_22 ;
T_6 V_58 ;
V_22 = F_26 ( V_35 -> V_57 , V_59 , & V_58 ) ;
if ( ! V_22 ) {
F_27 ( V_35 , L_3 ) ;
return NULL ;
}
F_28 ( & V_22 -> V_54 ) ;
V_22 -> V_50 . V_58 = V_58 ;
V_22 -> V_50 . V_60 = F_13 ;
F_29 ( & V_22 -> V_50 , & V_35 -> V_61 ) ;
F_23 ( V_35 , L_4 , V_22 ) ;
return V_22 ;
}
static void F_30 ( struct V_34 * V_35 )
{
struct V_36 * V_22 , * V_62 ;
F_31 (desc, _desc, &chan->ld_completed, node) {
if ( F_32 ( & V_22 -> V_50 ) )
F_21 ( V_35 , V_22 ) ;
}
}
static void F_33 ( struct V_34 * V_35 ,
struct V_36 * V_22 )
{
struct V_49 * V_50 = & V_22 -> V_50 ;
if ( V_50 -> V_51 == 0 )
return;
F_34 ( V_50 ) ;
F_35 ( V_50 ) ;
F_36 ( V_50 , NULL ) ;
F_37 ( V_50 ) ;
}
static void F_38 ( struct V_34 * V_35 ,
struct V_36 * V_22 )
{
F_22 ( & V_22 -> V_56 ) ;
if ( ! F_32 ( & V_22 -> V_50 ) ) {
F_39 ( & V_22 -> V_56 , & V_35 -> V_63 ) ;
return;
}
F_23 ( V_35 , L_2 , V_22 ) ;
F_24 ( V_35 -> V_57 , V_22 , V_22 -> V_50 . V_58 ) ;
}
static void F_40 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_64 * V_65 = & V_35 -> V_43 ;
struct V_21 * V_66 ;
V_66 = & V_65 -> V_66 [ V_65 -> V_67 ] ;
if ( ++ V_65 -> V_67 == V_65 -> V_68 )
V_65 -> V_67 = 0 ;
memcpy ( V_66 , & V_37 -> V_40 , sizeof( * V_66 ) ) ;
if ( V_37 -> V_46 & V_47 ) {
V_66 = & V_65 -> V_66 [ V_65 -> V_67 ] ;
if ( ++ V_65 -> V_67 == V_65 -> V_68 )
V_65 -> V_67 = 0 ;
memcpy ( V_66 , & V_37 -> V_41 , sizeof( * V_66 ) ) ;
}
V_35 -> V_69 += ( ( V_37 -> V_46 &
V_47 ) ? 2 : 1 ) ;
F_41 ( ( V_37 -> V_46 & V_47 ) ?
2 : 1 , V_65 -> V_70 ) ;
}
static void F_42 ( struct V_34 * V_35 )
{
struct V_36 * V_37 , * V_71 ;
if ( F_43 ( & V_35 -> V_55 ) ) {
F_23 ( V_35 , L_5 ) ;
return;
}
F_31 (desc_sw, _desc_sw, &chan->ld_pending, node) {
if ( V_35 -> V_69 >= V_35 -> V_72 )
return;
F_40 ( V_35 , V_37 ) ;
F_44 ( & V_37 -> V_56 , & V_35 -> V_73 ) ;
}
}
static void F_45 ( struct V_34 * V_35 )
{
struct V_64 * V_65 = & V_35 -> V_74 ;
struct V_36 * V_37 , * V_71 ;
struct V_21 * V_66 ;
struct V_75 V_63 ;
T_4 V_76 ;
F_28 ( & V_63 ) ;
F_17 ( & V_35 -> V_53 ) ;
F_30 ( V_35 ) ;
F_31 (desc_sw, _desc_sw, &chan->ld_running, node) {
V_66 = & V_65 -> V_66 [ V_65 -> V_67 ] ;
if ( F_14 ( F_46 ( V_66 -> V_25 ) ==
V_77 ) )
break;
if ( ++ V_65 -> V_67 == V_65 -> V_68 )
V_65 -> V_67 = 0 ;
V_76 = F_47 (
F_48 ( F_46 (
V_66 -> V_25 ) ) ,
F_49 ( F_46 (
V_66 -> V_25 ) ) ) ;
if ( V_76 ) {
F_27 ( V_35 , L_6 , V_78 [ V_76 ] ) ;
F_50 ( & V_37 -> V_40 ,
L_7 ) ;
if ( V_37 -> V_46 & V_47 )
F_50 ( & V_37 -> V_41 ,
L_8 ) ;
F_50 ( V_66 ,
L_9 ) ;
}
F_41 ( - 1 , V_65 -> V_70 ) ;
V_66 -> V_25 = F_6 ( V_77 ) ;
V_35 -> V_69 -= ( ( V_37 -> V_46 &
V_47 ) ? 2 : 1 ) ;
F_44 ( & V_37 -> V_56 , & V_63 ) ;
}
F_42 ( V_35 ) ;
F_20 ( & V_35 -> V_53 ) ;
F_31 (desc_sw, _desc_sw, &ld_completed, node) {
F_33 ( V_35 , V_37 ) ;
F_38 ( V_35 , V_37 ) ;
}
}
static int F_51 ( struct V_61 * V_79 )
{
struct V_34 * V_35 = F_15 ( V_79 ) ;
if ( V_35 -> V_57 )
return 1 ;
V_35 -> V_57 = F_52 ( V_35 -> V_80 , V_35 -> V_81 ,
sizeof( struct V_36 ) ,
0 , 0 ) ;
if ( ! V_35 -> V_57 ) {
F_27 ( V_35 , L_10 ) ;
return - V_82 ;
}
F_23 ( V_35 , L_11 ) ;
return 1 ;
}
static void F_53 ( struct V_34 * V_35 ,
struct V_75 * V_83 )
{
struct V_36 * V_22 , * V_62 ;
F_31 (desc, _desc, list, node)
F_21 ( V_35 , V_22 ) ;
}
static void F_54 ( struct V_61 * V_79 )
{
struct V_34 * V_35 = F_15 ( V_79 ) ;
F_23 ( V_35 , L_12 ) ;
if ( ! V_35 -> V_57 )
return;
F_45 ( V_35 ) ;
F_17 ( & V_35 -> V_53 ) ;
F_53 ( V_35 , & V_35 -> V_55 ) ;
F_53 ( V_35 , & V_35 -> V_73 ) ;
F_53 ( V_35 , & V_35 -> V_63 ) ;
F_20 ( & V_35 -> V_53 ) ;
F_55 ( V_35 -> V_57 ) ;
V_35 -> V_57 = NULL ;
}
static struct V_49 * F_56 (
struct V_61 * V_79 , struct V_84 * V_85 ,
T_1 V_86 , struct V_84 * V_87 ,
T_1 V_88 , unsigned long V_46 )
{
struct V_36 * V_89 = NULL , * V_90 = NULL ;
struct V_34 * V_35 ;
T_3 V_91 , V_92 ;
T_6 V_38 , V_39 ;
T_3 V_7 ;
if ( F_14 ( ! V_79 ) )
return NULL ;
if ( F_14 ( ! V_86 || ! V_88 ) )
return NULL ;
if ( F_14 ( ! V_85 || ! V_87 ) )
return NULL ;
V_35 = F_15 ( V_79 ) ;
V_91 = F_57 ( V_85 ) ;
V_92 = F_57 ( V_87 ) ;
V_86 -- ;
V_88 -- ;
while ( true ) {
V_7 = F_58 ( T_3 , V_92 , V_91 ) ;
V_7 = F_58 ( T_3 , V_7 , V_93 ) ;
if ( V_7 == 0 )
goto V_94;
V_38 = F_59 ( V_85 ) + F_57 ( V_85 ) - V_91 ;
V_39 = F_59 ( V_87 ) + F_57 ( V_87 ) - V_92 ;
V_90 = F_25 ( V_35 ) ;
if ( ! V_90 )
goto V_95;
F_11 ( V_35 , V_90 , V_38 , V_39 , V_7 ) ;
if ( ! V_89 )
V_89 = V_90 ;
V_90 -> V_50 . V_51 = 0 ;
F_60 ( & V_90 -> V_50 ) ;
V_91 -= V_7 ;
V_92 -= V_7 ;
F_39 ( & V_90 -> V_56 , & V_89 -> V_54 ) ;
V_94:
if ( V_91 == 0 ) {
if ( V_86 == 0 )
break;
V_85 = F_61 ( V_85 ) ;
if ( ! V_85 )
break;
V_86 -- ;
V_91 = F_57 ( V_85 ) ;
}
if ( V_92 == 0 ) {
if ( V_88 == 0 )
break;
V_87 = F_61 ( V_87 ) ;
if ( ! V_87 )
break;
V_88 -- ;
V_92 = F_57 ( V_87 ) ;
}
}
if ( ! V_90 )
return NULL ;
V_90 -> V_50 . V_46 = V_46 ;
V_90 -> V_50 . V_51 = - V_96 ;
F_62 ( & V_89 -> V_54 , & V_90 -> V_54 ) ;
return & V_90 -> V_50 ;
V_95:
if ( ! V_89 )
return NULL ;
F_53 ( V_35 , & V_89 -> V_54 ) ;
return NULL ;
}
static struct V_49 * F_63 (
struct V_61 * V_79 , T_6 V_38 , T_6 * V_39 ,
T_1 V_11 , T_3 V_7 , unsigned long V_46 )
{
struct V_36 * V_89 = NULL , * V_90 ;
struct V_34 * V_35 ;
static T_4 V_97 [ V_98 ] = {
0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_14 ( ! V_79 || ! V_7 ) )
return NULL ;
V_35 = F_15 ( V_79 ) ;
do {
V_90 = F_25 ( V_35 ) ;
if ( ! V_90 )
goto V_95;
F_12 ( V_35 , V_90 , & V_38 , V_39 ,
V_11 , & V_7 , V_97 ) ;
if ( ! V_89 )
V_89 = V_90 ;
V_90 -> V_50 . V_51 = 0 ;
F_60 ( & V_90 -> V_50 ) ;
F_39 ( & V_90 -> V_56 , & V_89 -> V_54 ) ;
} while ( V_7 );
V_90 -> V_50 . V_46 = V_46 ;
V_90 -> V_50 . V_51 = - V_96 ;
F_62 ( & V_89 -> V_54 , & V_90 -> V_54 ) ;
return & V_90 -> V_50 ;
V_95:
if ( ! V_89 )
return NULL ;
F_53 ( V_35 , & V_89 -> V_54 ) ;
return NULL ;
}
static struct V_49 * F_64 (
struct V_61 * V_79 , T_6 * V_38 , T_6 * V_39 ,
T_1 V_11 , const T_4 * V_48 , T_3 V_7 , unsigned long V_46 )
{
struct V_36 * V_89 = NULL , * V_90 ;
struct V_34 * V_35 ;
T_3 V_99 = V_7 ;
T_6 V_100 [ V_98 ] ;
static T_4 V_97 [ V_98 ] = { 0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_14 ( ! V_79 || ! V_7 ) )
return NULL ;
V_35 = F_15 ( V_79 ) ;
memcpy ( V_100 , V_39 , sizeof( * V_39 ) * V_11 ) ;
if ( V_46 & V_101 )
V_7 = 0 ;
if ( V_46 & V_102 )
V_99 = 0 ;
do {
V_90 = F_25 ( V_35 ) ;
if ( ! V_90 )
goto V_95;
if ( ! V_89 )
V_89 = V_90 ;
V_90 -> V_50 . V_51 = 0 ;
F_60 ( & V_90 -> V_50 ) ;
F_39 ( & V_90 -> V_56 , & V_89 -> V_54 ) ;
if ( V_7 ) {
F_12 ( V_35 , V_90 , & V_38 [ 0 ] , V_39 ,
V_11 , & V_7 , V_97 ) ;
continue;
}
if ( V_99 ) {
F_12 ( V_35 , V_90 , & V_38 [ 1 ] , V_100 ,
V_11 , & V_99 , V_48 ) ;
}
} while ( V_7 || V_99 );
V_90 -> V_50 . V_46 = V_46 ;
V_90 -> V_50 . V_51 = - V_96 ;
F_62 ( & V_89 -> V_54 , & V_90 -> V_54 ) ;
return & V_90 -> V_50 ;
V_95:
if ( ! V_89 )
return NULL ;
F_53 ( V_35 , & V_89 -> V_54 ) ;
return NULL ;
}
static void F_65 ( struct V_61 * V_79 )
{
struct V_34 * V_35 = F_15 ( V_79 ) ;
F_17 ( & V_35 -> V_53 ) ;
F_42 ( V_35 ) ;
F_20 ( & V_35 -> V_53 ) ;
}
static enum V_103 F_66 ( struct V_61 * V_79 ,
T_8 V_51 ,
struct V_104 * V_105 )
{
return F_67 ( V_79 , V_51 , V_105 ) ;
}
static void F_68 ( unsigned long V_106 )
{
struct V_34 * V_35 = (struct V_34 * ) V_106 ;
F_45 ( V_35 ) ;
F_69 ( V_35 -> V_107 ) ;
}
static T_9 F_70 ( int V_108 , void * V_109 )
{
struct V_34 * V_35 = (struct V_34 * ) V_109 ;
F_71 ( ! V_35 ) ;
F_72 ( V_35 -> V_107 ) ;
F_73 ( & V_35 -> V_110 ) ;
return V_111 ;
}
static T_9 F_74 ( int V_108 , void * V_109 )
{
struct V_1 * V_2 = (struct V_1 * ) V_109 ;
unsigned long V_112 ;
T_1 V_3 , V_42 ;
V_3 = F_2 ( V_2 -> V_113 + V_114 ) ;
F_41 ( V_3 , V_2 -> V_113 + V_114 ) ;
V_112 = V_3 >> V_115 ;
F_75 (i, &int_mask, ARRAY_SIZE(xgene_dma_err))
F_76 ( V_2 -> V_81 ,
L_13 , V_3 , V_116 [ V_42 ] ) ;
return V_111 ;
}
static void F_77 ( struct V_64 * V_65 )
{
int V_42 ;
F_41 ( V_65 -> V_117 , V_65 -> V_2 -> V_118 + V_119 ) ;
for ( V_42 = 0 ; V_42 < V_120 ; V_42 ++ )
F_41 ( V_65 -> V_121 [ V_42 ] , V_65 -> V_2 -> V_118 +
V_122 + ( V_42 * 4 ) ) ;
}
static void F_78 ( struct V_64 * V_65 )
{
memset ( V_65 -> V_121 , 0 , sizeof( T_1 ) * V_120 ) ;
F_77 ( V_65 ) ;
}
static void F_79 ( struct V_64 * V_65 )
{
void * V_123 = V_65 -> V_121 ;
T_2 V_124 = V_65 -> V_125 ;
T_1 V_42 , V_3 ;
V_65 -> V_68 = V_65 -> V_126 / V_127 ;
F_78 ( V_65 ) ;
F_80 ( V_123 , V_128 ) ;
if ( V_65 -> V_129 == V_30 ) {
F_81 ( V_123 ) ;
F_82 ( V_123 ) ;
F_83 ( V_123 ) ;
}
F_84 ( V_123 ) ;
F_85 ( V_123 ) ;
F_86 ( V_123 ) ;
F_87 ( V_123 , V_124 ) ;
F_88 ( V_123 , V_124 ) ;
F_89 ( V_123 , V_65 -> V_130 ) ;
F_77 ( V_65 ) ;
F_41 ( F_90 ( V_65 -> V_109 ) ,
V_65 -> V_2 -> V_118 + V_131 ) ;
F_41 ( F_91 ( V_65 -> V_117 ) ,
V_65 -> V_2 -> V_118 + V_132 ) ;
if ( V_65 -> V_129 != V_133 )
return;
for ( V_42 = 0 ; V_42 < V_65 -> V_68 ; V_42 ++ ) {
struct V_21 * V_22 ;
V_22 = & V_65 -> V_66 [ V_42 ] ;
V_22 -> V_25 = F_6 ( V_77 ) ;
}
V_3 = F_2 ( V_65 -> V_2 -> V_118 + V_134 ) ;
F_92 ( V_3 , V_65 -> V_135 ) ;
F_41 ( V_3 , V_65 -> V_2 -> V_118 + V_134 ) ;
}
static void F_93 ( struct V_64 * V_65 )
{
T_1 V_136 , V_3 ;
if ( V_65 -> V_129 == V_133 ) {
V_3 = F_2 ( V_65 -> V_2 -> V_118 +
V_134 ) ;
F_94 ( V_3 , V_65 -> V_135 ) ;
F_41 ( V_3 , V_65 -> V_2 -> V_118 +
V_134 ) ;
}
V_136 = F_90 ( V_65 -> V_109 ) ;
F_41 ( V_136 , V_65 -> V_2 -> V_118 + V_131 ) ;
F_41 ( 0 , V_65 -> V_2 -> V_118 + V_132 ) ;
F_78 ( V_65 ) ;
}
static void F_95 ( struct V_64 * V_65 )
{
V_65 -> V_137 = V_65 -> V_2 -> V_138 +
F_96 ( ( V_65 -> V_117 -
V_139 ) ) ;
V_65 -> V_70 = V_65 -> V_137 + V_140 ;
}
static int F_97 ( struct V_34 * V_35 ,
enum V_141 V_130 )
{
int V_126 ;
switch ( V_130 ) {
case V_142 :
V_126 = 0x200 ;
break;
case V_143 :
V_126 = 0x800 ;
break;
case V_144 :
V_126 = 0x4000 ;
break;
case V_145 :
V_126 = 0x10000 ;
break;
case V_146 :
V_126 = 0x80000 ;
break;
default:
F_27 ( V_35 , L_14 , V_130 ) ;
return - V_52 ;
}
return V_126 ;
}
static void F_98 ( struct V_64 * V_65 )
{
F_93 ( V_65 ) ;
if ( V_65 -> V_147 ) {
F_99 ( V_65 -> V_2 -> V_81 , V_65 -> V_126 ,
V_65 -> V_147 , V_65 -> V_125 ) ;
V_65 -> V_147 = NULL ;
}
}
static void F_100 ( struct V_34 * V_35 )
{
F_98 ( & V_35 -> V_74 ) ;
F_98 ( & V_35 -> V_43 ) ;
}
static int F_101 ( struct V_34 * V_35 ,
struct V_64 * V_65 ,
enum V_141 V_130 )
{
int V_148 ;
V_65 -> V_2 = V_35 -> V_2 ;
V_65 -> V_130 = V_130 ;
V_65 -> V_117 = V_35 -> V_2 -> V_149 ++ ;
V_65 -> V_109 = F_102 ( V_65 -> V_129 , V_65 -> V_135 ) ;
V_148 = F_97 ( V_35 , V_130 ) ;
if ( V_148 <= 0 )
return V_148 ;
V_65 -> V_126 = V_148 ;
V_65 -> V_147 = F_103 ( V_35 -> V_81 , V_65 -> V_126 ,
& V_65 -> V_125 , V_150 ) ;
if ( ! V_65 -> V_147 ) {
F_27 ( V_35 , L_15 ) ;
return - V_82 ;
}
F_95 ( V_65 ) ;
F_79 ( V_65 ) ;
return 0 ;
}
static int F_104 ( struct V_34 * V_35 )
{
struct V_64 * V_74 = & V_35 -> V_74 ;
struct V_64 * V_43 = & V_35 -> V_43 ;
int V_148 ;
V_74 -> V_129 = V_133 ;
V_74 -> V_135 = V_151 + V_35 -> V_109 ;
V_148 = F_101 ( V_35 , V_74 ,
V_145 ) ;
if ( V_148 )
return V_148 ;
F_23 ( V_35 , L_16 ,
V_74 -> V_109 , V_74 -> V_117 , V_74 -> V_147 ) ;
V_43 -> V_129 = V_30 ;
V_43 -> V_135 = V_152 + V_35 -> V_109 ;
V_148 = F_101 ( V_35 , V_43 ,
V_145 ) ;
if ( V_148 ) {
F_98 ( V_74 ) ;
return V_148 ;
}
V_43 -> V_28 = F_105 ( V_74 -> V_117 ) ;
F_23 ( V_35 ,
L_17 ,
V_43 -> V_109 , V_43 -> V_117 , V_43 -> V_147 ) ;
V_35 -> V_72 = V_43 -> V_68 ;
return V_148 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_148 , V_42 , V_153 ;
for ( V_42 = 0 ; V_42 < V_154 ; V_42 ++ ) {
V_148 = F_104 ( & V_2 -> V_35 [ V_42 ] ) ;
if ( V_148 ) {
for ( V_153 = 0 ; V_153 < V_42 ; V_153 ++ )
F_100 ( & V_2 -> V_35 [ V_153 ] ) ;
return V_148 ;
}
}
return V_148 ;
}
static void F_107 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_113 + V_155 ) ;
F_108 ( V_3 ) ;
F_109 ( V_3 ) ;
F_41 ( V_3 , V_2 -> V_113 + V_155 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_113 + V_155 ) ;
F_111 ( V_3 ) ;
F_41 ( V_3 , V_2 -> V_113 + V_155 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
F_41 ( V_156 ,
V_2 -> V_113 + V_157 ) ;
F_41 ( V_156 ,
V_2 -> V_113 + V_158 ) ;
F_41 ( V_156 ,
V_2 -> V_113 + V_159 ) ;
F_41 ( V_156 ,
V_2 -> V_113 + V_160 ) ;
F_41 ( V_156 ,
V_2 -> V_113 + V_161 ) ;
F_41 ( V_156 , V_2 -> V_113 + V_162 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
F_41 ( V_163 ,
V_2 -> V_113 + V_157 ) ;
F_41 ( V_163 ,
V_2 -> V_113 + V_158 ) ;
F_41 ( V_163 ,
V_2 -> V_113 + V_159 ) ;
F_41 ( V_163 ,
V_2 -> V_113 + V_160 ) ;
F_41 ( V_163 ,
V_2 -> V_113 + V_161 ) ;
F_41 ( V_163 ,
V_2 -> V_113 + V_162 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_41 ( V_164 ,
V_2 -> V_113 + V_165 ) ;
if ( F_1 ( V_2 ) )
F_41 ( F_115 ( 0x1D ) ,
V_2 -> V_113 + V_166 ) ;
else
F_116 ( V_2 -> V_81 , L_18 ) ;
F_107 ( V_2 ) ;
F_113 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_113 + V_167 ) ;
F_116 ( V_2 -> V_81 ,
L_19 ,
F_117 ( V_3 ) , F_118 ( V_3 ) ,
F_119 ( V_3 ) , V_154 ) ;
}
static int F_120 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_118 + V_168 ) &&
( ! F_2 ( V_2 -> V_118 + V_169 ) ) )
return 0 ;
F_41 ( 0x3 , V_2 -> V_118 + V_168 ) ;
F_41 ( 0x0 , V_2 -> V_118 + V_169 ) ;
F_41 ( 0x0 , V_2 -> V_118 + V_170 ) ;
F_2 ( V_2 -> V_118 + V_170 ) ;
F_121 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_118 + V_171 )
!= V_172 ) {
F_76 ( V_2 -> V_81 ,
L_20 ) ;
return - V_173 ;
}
F_41 ( V_174 ,
V_2 -> V_118 + V_175 ) ;
F_41 ( V_176 ,
V_2 -> V_118 + V_177 ) ;
F_41 ( V_178 ,
V_2 -> V_118 + V_179 ) ;
F_41 ( V_180 ,
V_2 -> V_118 + V_181 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 )
{
int V_148 ;
V_148 = F_120 ( V_2 ) ;
if ( V_148 )
return V_148 ;
F_41 ( 0x0 , V_2 -> V_113 + V_182 ) ;
F_2 ( V_2 -> V_113 + V_182 ) ;
F_121 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_113 + V_183 )
!= V_184 ) {
F_76 ( V_2 -> V_81 ,
L_21 ) ;
return - V_173 ;
}
return 0 ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_148 , V_42 , V_153 ;
V_148 = F_124 ( V_2 -> V_81 , V_2 -> V_185 , F_74 ,
0 , L_22 , V_2 ) ;
if ( V_148 ) {
F_76 ( V_2 -> V_81 ,
L_23 , V_2 -> V_185 ) ;
return V_148 ;
}
for ( V_42 = 0 ; V_42 < V_154 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
F_125 ( V_35 -> V_107 , V_186 ) ;
V_148 = F_124 ( V_35 -> V_81 , V_35 -> V_107 ,
F_70 ,
0 , V_35 -> V_80 , V_35 ) ;
if ( V_148 ) {
F_27 ( V_35 , L_24 ,
V_35 -> V_107 ) ;
F_126 ( V_2 -> V_81 , V_2 -> V_185 , V_2 ) ;
for ( V_153 = 0 ; V_153 < V_42 ; V_153 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
F_127 ( V_35 -> V_107 , V_186 ) ;
F_126 ( V_35 -> V_81 , V_35 -> V_107 , V_35 ) ;
}
return V_148 ;
}
}
return 0 ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_42 ;
F_126 ( V_2 -> V_81 , V_2 -> V_185 , V_2 ) ;
for ( V_42 = 0 ; V_42 < V_154 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
F_127 ( V_35 -> V_107 , V_186 ) ;
F_126 ( V_35 -> V_81 , V_35 -> V_107 , V_35 ) ;
}
}
static void F_129 ( struct V_34 * V_35 ,
struct V_187 * V_188 )
{
F_130 ( V_188 -> V_189 ) ;
F_131 ( V_190 , V_188 -> V_189 ) ;
if ( ( V_35 -> V_109 == V_191 ) &&
F_1 ( V_35 -> V_2 ) ) {
F_131 ( V_192 , V_188 -> V_189 ) ;
F_131 ( V_193 , V_188 -> V_189 ) ;
} else if ( ( V_35 -> V_109 == V_194 ) &&
! F_1 ( V_35 -> V_2 ) ) {
F_131 ( V_193 , V_188 -> V_189 ) ;
}
V_188 -> V_81 = V_35 -> V_81 ;
V_188 -> V_195 = F_51 ;
V_188 -> V_196 = F_54 ;
V_188 -> V_197 = F_65 ;
V_188 -> V_198 = F_66 ;
V_188 -> V_199 = F_56 ;
if ( F_132 ( V_193 , V_188 -> V_189 ) ) {
V_188 -> V_200 = F_63 ;
V_188 -> V_201 = V_98 ;
V_188 -> V_202 = V_203 ;
}
if ( F_132 ( V_192 , V_188 -> V_189 ) ) {
V_188 -> V_204 = F_64 ;
V_188 -> V_205 = V_98 ;
V_188 -> V_206 = V_203 ;
}
}
static int F_133 ( struct V_1 * V_2 , int V_109 )
{
struct V_34 * V_35 = & V_2 -> V_35 [ V_109 ] ;
struct V_187 * V_188 = & V_2 -> V_188 [ V_109 ] ;
int V_148 ;
V_35 -> V_61 . V_207 = V_188 ;
F_134 ( & V_35 -> V_53 ) ;
F_28 ( & V_35 -> V_55 ) ;
F_28 ( & V_35 -> V_73 ) ;
F_28 ( & V_35 -> V_63 ) ;
F_135 ( & V_35 -> V_110 , F_68 ,
( unsigned long ) V_35 ) ;
V_35 -> V_69 = 0 ;
V_35 -> V_57 = NULL ;
F_136 ( & V_35 -> V_61 ) ;
F_129 ( V_35 , V_188 ) ;
F_28 ( & V_188 -> V_208 ) ;
F_39 ( & V_35 -> V_61 . V_209 , & V_188 -> V_208 ) ;
V_148 = F_137 ( V_188 ) ;
if ( V_148 ) {
F_27 ( V_35 , L_25 , V_148 ) ;
F_138 ( & V_35 -> V_110 ) ;
return V_148 ;
}
F_116 ( V_2 -> V_81 ,
L_26 , F_139 ( & V_35 -> V_61 ) ,
F_132 ( V_190 , V_188 -> V_189 ) ? L_27 : L_28 ,
F_132 ( V_193 , V_188 -> V_189 ) ? L_29 : L_28 ,
F_132 ( V_192 , V_188 -> V_189 ) ? L_30 : L_28 ) ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 )
{
int V_148 , V_42 , V_153 ;
for ( V_42 = 0 ; V_42 < V_154 ; V_42 ++ ) {
V_148 = F_133 ( V_2 , V_42 ) ;
if ( V_148 ) {
for ( V_153 = 0 ; V_153 < V_42 ; V_153 ++ ) {
F_141 ( & V_2 -> V_188 [ V_153 ] ) ;
F_138 ( & V_2 -> V_35 [ V_153 ] . V_110 ) ;
}
return V_148 ;
}
}
return V_148 ;
}
static void F_142 ( struct V_1 * V_2 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_154 ; V_42 ++ )
F_141 ( & V_2 -> V_188 [ V_42 ] ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_42 ;
V_2 -> V_149 = V_139 ;
for ( V_42 = 0 ; V_42 < V_154 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
V_35 -> V_81 = V_2 -> V_81 ;
V_35 -> V_2 = V_2 ;
V_35 -> V_109 = V_42 ;
snprintf ( V_35 -> V_80 , sizeof( V_35 -> V_80 ) , L_31 , V_35 -> V_109 ) ;
}
}
static int F_144 ( struct V_210 * V_211 ,
struct V_1 * V_2 )
{
struct V_212 * V_213 ;
int V_108 , V_42 ;
V_213 = F_145 ( V_211 , V_214 , 0 ) ;
if ( ! V_213 ) {
F_76 ( & V_211 -> V_81 , L_32 ) ;
return - V_215 ;
}
V_2 -> V_113 = F_146 ( & V_211 -> V_81 , V_213 -> V_216 ,
F_147 ( V_213 ) ) ;
if ( ! V_2 -> V_113 ) {
F_76 ( & V_211 -> V_81 , L_33 ) ;
return - V_82 ;
}
V_213 = F_145 ( V_211 , V_214 , 1 ) ;
if ( ! V_213 ) {
F_76 ( & V_211 -> V_81 , L_34 ) ;
return - V_215 ;
}
V_2 -> V_118 = F_146 ( & V_211 -> V_81 , V_213 -> V_216 ,
F_147 ( V_213 ) ) ;
if ( ! V_2 -> V_118 ) {
F_76 ( & V_211 -> V_81 , L_35 ) ;
return - V_82 ;
}
V_213 = F_145 ( V_211 , V_214 , 2 ) ;
if ( ! V_213 ) {
F_76 ( & V_211 -> V_81 , L_36 ) ;
return - V_215 ;
}
V_2 -> V_138 = F_146 ( & V_211 -> V_81 , V_213 -> V_216 ,
F_147 ( V_213 ) ) ;
if ( ! V_2 -> V_138 ) {
F_76 ( & V_211 -> V_81 , L_37 ) ;
return - V_82 ;
}
V_2 -> V_138 += V_217 ;
V_213 = F_145 ( V_211 , V_214 , 3 ) ;
if ( ! V_213 ) {
F_76 ( & V_211 -> V_81 , L_38 ) ;
return - V_215 ;
}
V_2 -> V_4 = F_146 ( & V_211 -> V_81 , V_213 -> V_216 ,
F_147 ( V_213 ) ) ;
if ( ! V_2 -> V_4 ) {
F_76 ( & V_211 -> V_81 , L_39 ) ;
return - V_82 ;
}
V_108 = F_148 ( V_211 , 0 ) ;
if ( V_108 <= 0 ) {
F_76 ( & V_211 -> V_81 , L_40 ) ;
return - V_215 ;
}
V_2 -> V_185 = V_108 ;
for ( V_42 = 1 ; V_42 <= V_154 ; V_42 ++ ) {
V_108 = F_148 ( V_211 , V_42 ) ;
if ( V_108 <= 0 ) {
F_76 ( & V_211 -> V_81 , L_41 ) ;
return - V_215 ;
}
V_2 -> V_35 [ V_42 - 1 ] . V_107 = V_108 ;
}
return 0 ;
}
static int F_149 ( struct V_210 * V_211 )
{
struct V_1 * V_2 ;
int V_148 , V_42 ;
V_2 = F_150 ( & V_211 -> V_81 , sizeof( * V_2 ) , V_150 ) ;
if ( ! V_2 )
return - V_82 ;
V_2 -> V_81 = & V_211 -> V_81 ;
F_151 ( V_211 , V_2 ) ;
V_148 = F_144 ( V_211 , V_2 ) ;
if ( V_148 )
return V_148 ;
V_2 -> V_218 = F_152 ( & V_211 -> V_81 , NULL ) ;
if ( F_153 ( V_2 -> V_218 ) && ! F_154 ( & V_211 -> V_81 ) ) {
F_76 ( & V_211 -> V_81 , L_42 ) ;
return F_155 ( V_2 -> V_218 ) ;
}
if ( ! F_153 ( V_2 -> V_218 ) ) {
V_148 = F_156 ( V_2 -> V_218 ) ;
if ( V_148 ) {
F_76 ( & V_211 -> V_81 , L_43 , V_148 ) ;
return V_148 ;
}
}
V_148 = F_122 ( V_2 ) ;
if ( V_148 )
goto V_219;
V_148 = F_157 ( & V_211 -> V_81 , F_158 ( 42 ) ) ;
if ( V_148 ) {
F_76 ( & V_211 -> V_81 , L_44 ) ;
goto V_220;
}
F_143 ( V_2 ) ;
V_148 = F_106 ( V_2 ) ;
if ( V_148 )
goto V_219;
V_148 = F_123 ( V_2 ) ;
if ( V_148 )
goto V_221;
F_114 ( V_2 ) ;
V_148 = F_140 ( V_2 ) ;
if ( V_148 )
goto V_222;
return 0 ;
V_222:
F_128 ( V_2 ) ;
V_221:
for ( V_42 = 0 ; V_42 < V_154 ; V_42 ++ )
F_100 ( & V_2 -> V_35 [ V_42 ] ) ;
V_220:
V_219:
if ( ! F_153 ( V_2 -> V_218 ) )
F_159 ( V_2 -> V_218 ) ;
return V_148 ;
}
static int F_160 ( struct V_210 * V_211 )
{
struct V_1 * V_2 = F_161 ( V_211 ) ;
struct V_34 * V_35 ;
int V_42 ;
F_142 ( V_2 ) ;
F_112 ( V_2 ) ;
F_110 ( V_2 ) ;
F_128 ( V_2 ) ;
for ( V_42 = 0 ; V_42 < V_154 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
F_138 ( & V_35 -> V_110 ) ;
F_100 ( V_35 ) ;
}
if ( ! F_153 ( V_2 -> V_218 ) )
F_159 ( V_2 -> V_218 ) ;
return 0 ;
}
