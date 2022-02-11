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
if ( V_50 -> V_63 )
V_50 -> V_63 ( V_50 -> V_64 ) ;
F_35 ( V_50 ) ;
F_36 ( V_50 ) ;
}
static void F_37 ( struct V_34 * V_35 ,
struct V_36 * V_22 )
{
F_22 ( & V_22 -> V_56 ) ;
if ( ! F_32 ( & V_22 -> V_50 ) ) {
F_38 ( & V_22 -> V_56 , & V_35 -> V_65 ) ;
return;
}
F_23 ( V_35 , L_2 , V_22 ) ;
F_24 ( V_35 -> V_57 , V_22 , V_22 -> V_50 . V_58 ) ;
}
static void F_39 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_66 * V_67 = & V_35 -> V_43 ;
struct V_21 * V_68 ;
V_68 = & V_67 -> V_68 [ V_67 -> V_69 ] ;
if ( ++ V_67 -> V_69 == V_67 -> V_70 )
V_67 -> V_69 = 0 ;
memcpy ( V_68 , & V_37 -> V_40 , sizeof( * V_68 ) ) ;
if ( V_37 -> V_46 & V_47 ) {
V_68 = & V_67 -> V_68 [ V_67 -> V_69 ] ;
if ( ++ V_67 -> V_69 == V_67 -> V_70 )
V_67 -> V_69 = 0 ;
memcpy ( V_68 , & V_37 -> V_41 , sizeof( * V_68 ) ) ;
}
V_35 -> V_71 += ( ( V_37 -> V_46 &
V_47 ) ? 2 : 1 ) ;
F_40 ( ( V_37 -> V_46 & V_47 ) ?
2 : 1 , V_67 -> V_72 ) ;
}
static void F_41 ( struct V_34 * V_35 )
{
struct V_36 * V_37 , * V_73 ;
if ( F_42 ( & V_35 -> V_55 ) ) {
F_23 ( V_35 , L_5 ) ;
return;
}
F_31 (desc_sw, _desc_sw, &chan->ld_pending, node) {
if ( V_35 -> V_71 >= V_35 -> V_74 )
return;
F_39 ( V_35 , V_37 ) ;
F_43 ( & V_37 -> V_56 , & V_35 -> V_75 ) ;
}
}
static void F_44 ( struct V_34 * V_35 )
{
struct V_66 * V_67 = & V_35 -> V_76 ;
struct V_36 * V_37 , * V_73 ;
struct V_21 * V_68 ;
struct V_77 V_65 ;
T_4 V_78 ;
F_28 ( & V_65 ) ;
F_17 ( & V_35 -> V_53 ) ;
F_30 ( V_35 ) ;
F_31 (desc_sw, _desc_sw, &chan->ld_running, node) {
V_68 = & V_67 -> V_68 [ V_67 -> V_69 ] ;
if ( F_14 ( F_45 ( V_68 -> V_25 ) ==
V_79 ) )
break;
if ( ++ V_67 -> V_69 == V_67 -> V_70 )
V_67 -> V_69 = 0 ;
V_78 = F_46 (
F_47 ( F_45 (
V_68 -> V_25 ) ) ,
F_48 ( F_45 (
V_68 -> V_25 ) ) ) ;
if ( V_78 ) {
F_27 ( V_35 , L_6 , V_80 [ V_78 ] ) ;
F_49 ( & V_37 -> V_40 ,
L_7 ) ;
if ( V_37 -> V_46 & V_47 )
F_49 ( & V_37 -> V_41 ,
L_8 ) ;
F_49 ( V_68 ,
L_9 ) ;
}
F_40 ( - 1 , V_67 -> V_72 ) ;
V_68 -> V_25 = F_6 ( V_79 ) ;
V_35 -> V_71 -= ( ( V_37 -> V_46 &
V_47 ) ? 2 : 1 ) ;
F_43 ( & V_37 -> V_56 , & V_65 ) ;
}
F_41 ( V_35 ) ;
F_20 ( & V_35 -> V_53 ) ;
F_31 (desc_sw, _desc_sw, &ld_completed, node) {
F_33 ( V_35 , V_37 ) ;
F_37 ( V_35 , V_37 ) ;
}
}
static int F_50 ( struct V_61 * V_81 )
{
struct V_34 * V_35 = F_15 ( V_81 ) ;
if ( V_35 -> V_57 )
return 1 ;
V_35 -> V_57 = F_51 ( V_35 -> V_82 , V_35 -> V_83 ,
sizeof( struct V_36 ) ,
0 , 0 ) ;
if ( ! V_35 -> V_57 ) {
F_27 ( V_35 , L_10 ) ;
return - V_84 ;
}
F_23 ( V_35 , L_11 ) ;
return 1 ;
}
static void F_52 ( struct V_34 * V_35 ,
struct V_77 * V_85 )
{
struct V_36 * V_22 , * V_62 ;
F_31 (desc, _desc, list, node)
F_21 ( V_35 , V_22 ) ;
}
static void F_53 ( struct V_61 * V_81 )
{
struct V_34 * V_35 = F_15 ( V_81 ) ;
F_23 ( V_35 , L_12 ) ;
if ( ! V_35 -> V_57 )
return;
F_44 ( V_35 ) ;
F_17 ( & V_35 -> V_53 ) ;
F_52 ( V_35 , & V_35 -> V_55 ) ;
F_52 ( V_35 , & V_35 -> V_75 ) ;
F_52 ( V_35 , & V_35 -> V_65 ) ;
F_20 ( & V_35 -> V_53 ) ;
F_54 ( V_35 -> V_57 ) ;
V_35 -> V_57 = NULL ;
}
static struct V_49 * F_55 (
struct V_61 * V_81 , struct V_86 * V_87 ,
T_1 V_88 , struct V_86 * V_89 ,
T_1 V_90 , unsigned long V_46 )
{
struct V_36 * V_91 = NULL , * V_92 = NULL ;
struct V_34 * V_35 ;
T_3 V_93 , V_94 ;
T_6 V_38 , V_39 ;
T_3 V_7 ;
if ( F_14 ( ! V_81 ) )
return NULL ;
if ( F_14 ( ! V_88 || ! V_90 ) )
return NULL ;
if ( F_14 ( ! V_87 || ! V_89 ) )
return NULL ;
V_35 = F_15 ( V_81 ) ;
V_93 = F_56 ( V_87 ) ;
V_94 = F_56 ( V_89 ) ;
V_88 -- ;
V_90 -- ;
while ( true ) {
V_7 = F_57 ( T_3 , V_94 , V_93 ) ;
V_7 = F_57 ( T_3 , V_7 , V_95 ) ;
if ( V_7 == 0 )
goto V_96;
V_38 = F_58 ( V_87 ) + F_56 ( V_87 ) - V_93 ;
V_39 = F_58 ( V_89 ) + F_56 ( V_89 ) - V_94 ;
V_92 = F_25 ( V_35 ) ;
if ( ! V_92 )
goto V_97;
F_11 ( V_35 , V_92 , V_38 , V_39 , V_7 ) ;
if ( ! V_91 )
V_91 = V_92 ;
V_92 -> V_50 . V_51 = 0 ;
F_59 ( & V_92 -> V_50 ) ;
V_93 -= V_7 ;
V_94 -= V_7 ;
F_38 ( & V_92 -> V_56 , & V_91 -> V_54 ) ;
V_96:
if ( V_93 == 0 ) {
if ( V_88 == 0 )
break;
V_87 = F_60 ( V_87 ) ;
if ( ! V_87 )
break;
V_88 -- ;
V_93 = F_56 ( V_87 ) ;
}
if ( V_94 == 0 ) {
if ( V_90 == 0 )
break;
V_89 = F_60 ( V_89 ) ;
if ( ! V_89 )
break;
V_90 -- ;
V_94 = F_56 ( V_89 ) ;
}
}
if ( ! V_92 )
return NULL ;
V_92 -> V_50 . V_46 = V_46 ;
V_92 -> V_50 . V_51 = - V_98 ;
F_61 ( & V_91 -> V_54 , & V_92 -> V_54 ) ;
return & V_92 -> V_50 ;
V_97:
if ( ! V_91 )
return NULL ;
F_52 ( V_35 , & V_91 -> V_54 ) ;
return NULL ;
}
static struct V_49 * F_62 (
struct V_61 * V_81 , T_6 V_38 , T_6 * V_39 ,
T_1 V_11 , T_3 V_7 , unsigned long V_46 )
{
struct V_36 * V_91 = NULL , * V_92 ;
struct V_34 * V_35 ;
static T_4 V_99 [ V_100 ] = {
0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_14 ( ! V_81 || ! V_7 ) )
return NULL ;
V_35 = F_15 ( V_81 ) ;
do {
V_92 = F_25 ( V_35 ) ;
if ( ! V_92 )
goto V_97;
F_12 ( V_35 , V_92 , & V_38 , V_39 ,
V_11 , & V_7 , V_99 ) ;
if ( ! V_91 )
V_91 = V_92 ;
V_92 -> V_50 . V_51 = 0 ;
F_59 ( & V_92 -> V_50 ) ;
F_38 ( & V_92 -> V_56 , & V_91 -> V_54 ) ;
} while ( V_7 );
V_92 -> V_50 . V_46 = V_46 ;
V_92 -> V_50 . V_51 = - V_98 ;
F_61 ( & V_91 -> V_54 , & V_92 -> V_54 ) ;
return & V_92 -> V_50 ;
V_97:
if ( ! V_91 )
return NULL ;
F_52 ( V_35 , & V_91 -> V_54 ) ;
return NULL ;
}
static struct V_49 * F_63 (
struct V_61 * V_81 , T_6 * V_38 , T_6 * V_39 ,
T_1 V_11 , const T_4 * V_48 , T_3 V_7 , unsigned long V_46 )
{
struct V_36 * V_91 = NULL , * V_92 ;
struct V_34 * V_35 ;
T_3 V_101 = V_7 ;
T_6 V_102 [ V_100 ] ;
static T_4 V_99 [ V_100 ] = { 0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_14 ( ! V_81 || ! V_7 ) )
return NULL ;
V_35 = F_15 ( V_81 ) ;
memcpy ( V_102 , V_39 , sizeof( * V_39 ) * V_11 ) ;
if ( V_46 & V_103 )
V_7 = 0 ;
if ( V_46 & V_104 )
V_101 = 0 ;
do {
V_92 = F_25 ( V_35 ) ;
if ( ! V_92 )
goto V_97;
if ( ! V_91 )
V_91 = V_92 ;
V_92 -> V_50 . V_51 = 0 ;
F_59 ( & V_92 -> V_50 ) ;
F_38 ( & V_92 -> V_56 , & V_91 -> V_54 ) ;
if ( V_7 ) {
F_12 ( V_35 , V_92 , & V_38 [ 0 ] , V_39 ,
V_11 , & V_7 , V_99 ) ;
continue;
}
if ( V_101 ) {
F_12 ( V_35 , V_92 , & V_38 [ 1 ] , V_102 ,
V_11 , & V_101 , V_48 ) ;
}
} while ( V_7 || V_101 );
V_92 -> V_50 . V_46 = V_46 ;
V_92 -> V_50 . V_51 = - V_98 ;
F_61 ( & V_91 -> V_54 , & V_92 -> V_54 ) ;
return & V_92 -> V_50 ;
V_97:
if ( ! V_91 )
return NULL ;
F_52 ( V_35 , & V_91 -> V_54 ) ;
return NULL ;
}
static void F_64 ( struct V_61 * V_81 )
{
struct V_34 * V_35 = F_15 ( V_81 ) ;
F_17 ( & V_35 -> V_53 ) ;
F_41 ( V_35 ) ;
F_20 ( & V_35 -> V_53 ) ;
}
static enum V_105 F_65 ( struct V_61 * V_81 ,
T_8 V_51 ,
struct V_106 * V_107 )
{
return F_66 ( V_81 , V_51 , V_107 ) ;
}
static void F_67 ( unsigned long V_108 )
{
struct V_34 * V_35 = (struct V_34 * ) V_108 ;
F_44 ( V_35 ) ;
F_68 ( V_35 -> V_109 ) ;
}
static T_9 F_69 ( int V_110 , void * V_111 )
{
struct V_34 * V_35 = (struct V_34 * ) V_111 ;
F_70 ( ! V_35 ) ;
F_71 ( V_35 -> V_109 ) ;
F_72 ( & V_35 -> V_112 ) ;
return V_113 ;
}
static T_9 F_73 ( int V_110 , void * V_111 )
{
struct V_1 * V_2 = (struct V_1 * ) V_111 ;
unsigned long V_114 ;
T_1 V_3 , V_42 ;
V_3 = F_2 ( V_2 -> V_115 + V_116 ) ;
F_40 ( V_3 , V_2 -> V_115 + V_116 ) ;
V_114 = V_3 >> V_117 ;
F_74 (i, &int_mask, ARRAY_SIZE(xgene_dma_err))
F_75 ( V_2 -> V_83 ,
L_13 , V_3 , V_118 [ V_42 ] ) ;
return V_113 ;
}
static void F_76 ( struct V_66 * V_67 )
{
int V_42 ;
F_40 ( V_67 -> V_119 , V_67 -> V_2 -> V_120 + V_121 ) ;
for ( V_42 = 0 ; V_42 < V_122 ; V_42 ++ )
F_40 ( V_67 -> V_123 [ V_42 ] , V_67 -> V_2 -> V_120 +
V_124 + ( V_42 * 4 ) ) ;
}
static void F_77 ( struct V_66 * V_67 )
{
memset ( V_67 -> V_123 , 0 , sizeof( T_1 ) * V_122 ) ;
F_76 ( V_67 ) ;
}
static void F_78 ( struct V_66 * V_67 )
{
void * V_125 = V_67 -> V_123 ;
T_2 V_126 = V_67 -> V_127 ;
T_1 V_42 , V_3 ;
V_67 -> V_70 = V_67 -> V_128 / V_129 ;
F_77 ( V_67 ) ;
F_79 ( V_125 , V_130 ) ;
if ( V_67 -> V_131 == V_30 ) {
F_80 ( V_125 ) ;
F_81 ( V_125 ) ;
F_82 ( V_125 ) ;
}
F_83 ( V_125 ) ;
F_84 ( V_125 ) ;
F_85 ( V_125 ) ;
F_86 ( V_125 , V_126 ) ;
F_87 ( V_125 , V_126 ) ;
F_88 ( V_125 , V_67 -> V_132 ) ;
F_76 ( V_67 ) ;
F_40 ( F_89 ( V_67 -> V_111 ) ,
V_67 -> V_2 -> V_120 + V_133 ) ;
F_40 ( F_90 ( V_67 -> V_119 ) ,
V_67 -> V_2 -> V_120 + V_134 ) ;
if ( V_67 -> V_131 != V_135 )
return;
for ( V_42 = 0 ; V_42 < V_67 -> V_70 ; V_42 ++ ) {
struct V_21 * V_22 ;
V_22 = & V_67 -> V_68 [ V_42 ] ;
V_22 -> V_25 = F_6 ( V_79 ) ;
}
V_3 = F_2 ( V_67 -> V_2 -> V_120 + V_136 ) ;
F_91 ( V_3 , V_67 -> V_137 ) ;
F_40 ( V_3 , V_67 -> V_2 -> V_120 + V_136 ) ;
}
static void F_92 ( struct V_66 * V_67 )
{
T_1 V_138 , V_3 ;
if ( V_67 -> V_131 == V_135 ) {
V_3 = F_2 ( V_67 -> V_2 -> V_120 +
V_136 ) ;
F_93 ( V_3 , V_67 -> V_137 ) ;
F_40 ( V_3 , V_67 -> V_2 -> V_120 +
V_136 ) ;
}
V_138 = F_89 ( V_67 -> V_111 ) ;
F_40 ( V_138 , V_67 -> V_2 -> V_120 + V_133 ) ;
F_40 ( 0 , V_67 -> V_2 -> V_120 + V_134 ) ;
F_77 ( V_67 ) ;
}
static void F_94 ( struct V_66 * V_67 )
{
V_67 -> V_139 = V_67 -> V_2 -> V_140 +
F_95 ( ( V_67 -> V_119 -
V_141 ) ) ;
V_67 -> V_72 = V_67 -> V_139 + V_142 ;
}
static int F_96 ( struct V_34 * V_35 ,
enum V_143 V_132 )
{
int V_128 ;
switch ( V_132 ) {
case V_144 :
V_128 = 0x200 ;
break;
case V_145 :
V_128 = 0x800 ;
break;
case V_146 :
V_128 = 0x4000 ;
break;
case V_147 :
V_128 = 0x10000 ;
break;
case V_148 :
V_128 = 0x80000 ;
break;
default:
F_27 ( V_35 , L_14 , V_132 ) ;
return - V_52 ;
}
return V_128 ;
}
static void F_97 ( struct V_66 * V_67 )
{
F_92 ( V_67 ) ;
if ( V_67 -> V_149 ) {
F_98 ( V_67 -> V_2 -> V_83 , V_67 -> V_128 ,
V_67 -> V_149 , V_67 -> V_127 ) ;
V_67 -> V_149 = NULL ;
}
}
static void F_99 ( struct V_34 * V_35 )
{
F_97 ( & V_35 -> V_76 ) ;
F_97 ( & V_35 -> V_43 ) ;
}
static int F_100 ( struct V_34 * V_35 ,
struct V_66 * V_67 ,
enum V_143 V_132 )
{
int V_150 ;
V_67 -> V_2 = V_35 -> V_2 ;
V_67 -> V_132 = V_132 ;
V_67 -> V_119 = V_35 -> V_2 -> V_151 ++ ;
V_67 -> V_111 = F_101 ( V_67 -> V_131 , V_67 -> V_137 ) ;
V_150 = F_96 ( V_35 , V_132 ) ;
if ( V_150 <= 0 )
return V_150 ;
V_67 -> V_128 = V_150 ;
V_67 -> V_149 = F_102 ( V_35 -> V_83 , V_67 -> V_128 ,
& V_67 -> V_127 , V_152 ) ;
if ( ! V_67 -> V_149 ) {
F_27 ( V_35 , L_15 ) ;
return - V_84 ;
}
F_94 ( V_67 ) ;
F_78 ( V_67 ) ;
return 0 ;
}
static int F_103 ( struct V_34 * V_35 )
{
struct V_66 * V_76 = & V_35 -> V_76 ;
struct V_66 * V_43 = & V_35 -> V_43 ;
int V_150 ;
V_76 -> V_131 = V_135 ;
V_76 -> V_137 = V_153 + V_35 -> V_111 ;
V_150 = F_100 ( V_35 , V_76 ,
V_147 ) ;
if ( V_150 )
return V_150 ;
F_23 ( V_35 , L_16 ,
V_76 -> V_111 , V_76 -> V_119 , V_76 -> V_149 ) ;
V_43 -> V_131 = V_30 ;
V_43 -> V_137 = V_154 + V_35 -> V_111 ;
V_150 = F_100 ( V_35 , V_43 ,
V_147 ) ;
if ( V_150 ) {
F_97 ( V_76 ) ;
return V_150 ;
}
V_43 -> V_28 = F_104 ( V_76 -> V_119 ) ;
F_23 ( V_35 ,
L_17 ,
V_43 -> V_111 , V_43 -> V_119 , V_43 -> V_149 ) ;
V_35 -> V_74 = V_43 -> V_70 ;
return V_150 ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_150 , V_42 , V_155 ;
for ( V_42 = 0 ; V_42 < V_156 ; V_42 ++ ) {
V_150 = F_103 ( & V_2 -> V_35 [ V_42 ] ) ;
if ( V_150 ) {
for ( V_155 = 0 ; V_155 < V_42 ; V_155 ++ )
F_99 ( & V_2 -> V_35 [ V_155 ] ) ;
return V_150 ;
}
}
return V_150 ;
}
static void F_106 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_115 + V_157 ) ;
F_107 ( V_3 ) ;
F_108 ( V_3 ) ;
F_40 ( V_3 , V_2 -> V_115 + V_157 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_115 + V_157 ) ;
F_110 ( V_3 ) ;
F_40 ( V_3 , V_2 -> V_115 + V_157 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
F_40 ( V_158 ,
V_2 -> V_115 + V_159 ) ;
F_40 ( V_158 ,
V_2 -> V_115 + V_160 ) ;
F_40 ( V_158 ,
V_2 -> V_115 + V_161 ) ;
F_40 ( V_158 ,
V_2 -> V_115 + V_162 ) ;
F_40 ( V_158 ,
V_2 -> V_115 + V_163 ) ;
F_40 ( V_158 , V_2 -> V_115 + V_164 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
F_40 ( V_165 ,
V_2 -> V_115 + V_159 ) ;
F_40 ( V_165 ,
V_2 -> V_115 + V_160 ) ;
F_40 ( V_165 ,
V_2 -> V_115 + V_161 ) ;
F_40 ( V_165 ,
V_2 -> V_115 + V_162 ) ;
F_40 ( V_165 ,
V_2 -> V_115 + V_163 ) ;
F_40 ( V_165 ,
V_2 -> V_115 + V_164 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_40 ( V_166 ,
V_2 -> V_115 + V_167 ) ;
if ( F_1 ( V_2 ) )
F_40 ( F_114 ( 0x1D ) ,
V_2 -> V_115 + V_168 ) ;
else
F_115 ( V_2 -> V_83 , L_18 ) ;
F_106 ( V_2 ) ;
F_112 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_115 + V_169 ) ;
F_115 ( V_2 -> V_83 ,
L_19 ,
F_116 ( V_3 ) , F_117 ( V_3 ) ,
F_118 ( V_3 ) , V_156 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_120 + V_170 ) &&
( ! F_2 ( V_2 -> V_120 + V_171 ) ) )
return 0 ;
F_40 ( 0x3 , V_2 -> V_120 + V_170 ) ;
F_40 ( 0x0 , V_2 -> V_120 + V_171 ) ;
F_40 ( 0x0 , V_2 -> V_120 + V_172 ) ;
F_2 ( V_2 -> V_120 + V_172 ) ;
F_120 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_120 + V_173 )
!= V_174 ) {
F_75 ( V_2 -> V_83 ,
L_20 ) ;
return - V_175 ;
}
F_40 ( V_176 ,
V_2 -> V_120 + V_177 ) ;
F_40 ( V_178 ,
V_2 -> V_120 + V_179 ) ;
F_40 ( V_180 ,
V_2 -> V_120 + V_181 ) ;
F_40 ( V_182 ,
V_2 -> V_120 + V_183 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 )
{
int V_150 ;
V_150 = F_119 ( V_2 ) ;
if ( V_150 )
return V_150 ;
F_40 ( 0x0 , V_2 -> V_115 + V_184 ) ;
F_2 ( V_2 -> V_115 + V_184 ) ;
F_120 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_115 + V_185 )
!= V_186 ) {
F_75 ( V_2 -> V_83 ,
L_21 ) ;
return - V_175 ;
}
return 0 ;
}
static int F_122 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_150 , V_42 , V_155 ;
V_150 = F_123 ( V_2 -> V_83 , V_2 -> V_187 , F_73 ,
0 , L_22 , V_2 ) ;
if ( V_150 ) {
F_75 ( V_2 -> V_83 ,
L_23 , V_2 -> V_187 ) ;
return V_150 ;
}
for ( V_42 = 0 ; V_42 < V_156 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
F_124 ( V_35 -> V_109 , V_188 ) ;
V_150 = F_123 ( V_35 -> V_83 , V_35 -> V_109 ,
F_69 ,
0 , V_35 -> V_82 , V_35 ) ;
if ( V_150 ) {
F_27 ( V_35 , L_24 ,
V_35 -> V_109 ) ;
F_125 ( V_2 -> V_83 , V_2 -> V_187 , V_2 ) ;
for ( V_155 = 0 ; V_155 < V_42 ; V_155 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
F_126 ( V_35 -> V_109 , V_188 ) ;
F_125 ( V_35 -> V_83 , V_35 -> V_109 , V_35 ) ;
}
return V_150 ;
}
}
return 0 ;
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_42 ;
F_125 ( V_2 -> V_83 , V_2 -> V_187 , V_2 ) ;
for ( V_42 = 0 ; V_42 < V_156 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
F_126 ( V_35 -> V_109 , V_188 ) ;
F_125 ( V_35 -> V_83 , V_35 -> V_109 , V_35 ) ;
}
}
static void F_128 ( struct V_34 * V_35 ,
struct V_189 * V_190 )
{
F_129 ( V_190 -> V_191 ) ;
F_130 ( V_192 , V_190 -> V_191 ) ;
if ( ( V_35 -> V_111 == V_193 ) &&
F_1 ( V_35 -> V_2 ) ) {
F_130 ( V_194 , V_190 -> V_191 ) ;
F_130 ( V_195 , V_190 -> V_191 ) ;
} else if ( ( V_35 -> V_111 == V_196 ) &&
! F_1 ( V_35 -> V_2 ) ) {
F_130 ( V_195 , V_190 -> V_191 ) ;
}
V_190 -> V_83 = V_35 -> V_83 ;
V_190 -> V_197 = F_50 ;
V_190 -> V_198 = F_53 ;
V_190 -> V_199 = F_64 ;
V_190 -> V_200 = F_65 ;
V_190 -> V_201 = F_55 ;
if ( F_131 ( V_195 , V_190 -> V_191 ) ) {
V_190 -> V_202 = F_62 ;
V_190 -> V_203 = V_100 ;
V_190 -> V_204 = V_205 ;
}
if ( F_131 ( V_194 , V_190 -> V_191 ) ) {
V_190 -> V_206 = F_63 ;
V_190 -> V_207 = V_100 ;
V_190 -> V_208 = V_205 ;
}
}
static int F_132 ( struct V_1 * V_2 , int V_111 )
{
struct V_34 * V_35 = & V_2 -> V_35 [ V_111 ] ;
struct V_189 * V_190 = & V_2 -> V_190 [ V_111 ] ;
int V_150 ;
V_35 -> V_61 . V_209 = V_190 ;
F_133 ( & V_35 -> V_53 ) ;
F_28 ( & V_35 -> V_55 ) ;
F_28 ( & V_35 -> V_75 ) ;
F_28 ( & V_35 -> V_65 ) ;
F_134 ( & V_35 -> V_112 , F_67 ,
( unsigned long ) V_35 ) ;
V_35 -> V_71 = 0 ;
V_35 -> V_57 = NULL ;
F_135 ( & V_35 -> V_61 ) ;
F_128 ( V_35 , V_190 ) ;
F_28 ( & V_190 -> V_210 ) ;
F_38 ( & V_35 -> V_61 . V_211 , & V_190 -> V_210 ) ;
V_150 = F_136 ( V_190 ) ;
if ( V_150 ) {
F_27 ( V_35 , L_25 , V_150 ) ;
F_137 ( & V_35 -> V_112 ) ;
return V_150 ;
}
F_115 ( V_2 -> V_83 ,
L_26 , F_138 ( & V_35 -> V_61 ) ,
F_131 ( V_192 , V_190 -> V_191 ) ? L_27 : L_28 ,
F_131 ( V_195 , V_190 -> V_191 ) ? L_29 : L_28 ,
F_131 ( V_194 , V_190 -> V_191 ) ? L_30 : L_28 ) ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 )
{
int V_150 , V_42 , V_155 ;
for ( V_42 = 0 ; V_42 < V_156 ; V_42 ++ ) {
V_150 = F_132 ( V_2 , V_42 ) ;
if ( V_150 ) {
for ( V_155 = 0 ; V_155 < V_42 ; V_155 ++ ) {
F_140 ( & V_2 -> V_190 [ V_155 ] ) ;
F_137 ( & V_2 -> V_35 [ V_155 ] . V_112 ) ;
}
return V_150 ;
}
}
return V_150 ;
}
static void F_141 ( struct V_1 * V_2 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_156 ; V_42 ++ )
F_140 ( & V_2 -> V_190 [ V_42 ] ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_42 ;
V_2 -> V_151 = V_141 ;
for ( V_42 = 0 ; V_42 < V_156 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
V_35 -> V_83 = V_2 -> V_83 ;
V_35 -> V_2 = V_2 ;
V_35 -> V_111 = V_42 ;
snprintf ( V_35 -> V_82 , sizeof( V_35 -> V_82 ) , L_31 , V_35 -> V_111 ) ;
}
}
static int F_143 ( struct V_212 * V_213 ,
struct V_1 * V_2 )
{
struct V_214 * V_215 ;
int V_110 , V_42 ;
V_215 = F_144 ( V_213 , V_216 , 0 ) ;
if ( ! V_215 ) {
F_75 ( & V_213 -> V_83 , L_32 ) ;
return - V_217 ;
}
V_2 -> V_115 = F_145 ( & V_213 -> V_83 , V_215 -> V_218 ,
F_146 ( V_215 ) ) ;
if ( ! V_2 -> V_115 ) {
F_75 ( & V_213 -> V_83 , L_33 ) ;
return - V_84 ;
}
V_215 = F_144 ( V_213 , V_216 , 1 ) ;
if ( ! V_215 ) {
F_75 ( & V_213 -> V_83 , L_34 ) ;
return - V_217 ;
}
V_2 -> V_120 = F_145 ( & V_213 -> V_83 , V_215 -> V_218 ,
F_146 ( V_215 ) ) ;
if ( ! V_2 -> V_120 ) {
F_75 ( & V_213 -> V_83 , L_35 ) ;
return - V_84 ;
}
V_215 = F_144 ( V_213 , V_216 , 2 ) ;
if ( ! V_215 ) {
F_75 ( & V_213 -> V_83 , L_36 ) ;
return - V_217 ;
}
V_2 -> V_140 = F_145 ( & V_213 -> V_83 , V_215 -> V_218 ,
F_146 ( V_215 ) ) ;
if ( ! V_2 -> V_140 ) {
F_75 ( & V_213 -> V_83 , L_37 ) ;
return - V_84 ;
}
V_2 -> V_140 += V_219 ;
V_215 = F_144 ( V_213 , V_216 , 3 ) ;
if ( ! V_215 ) {
F_75 ( & V_213 -> V_83 , L_38 ) ;
return - V_217 ;
}
V_2 -> V_4 = F_145 ( & V_213 -> V_83 , V_215 -> V_218 ,
F_146 ( V_215 ) ) ;
if ( ! V_2 -> V_4 ) {
F_75 ( & V_213 -> V_83 , L_39 ) ;
return - V_84 ;
}
V_110 = F_147 ( V_213 , 0 ) ;
if ( V_110 <= 0 ) {
F_75 ( & V_213 -> V_83 , L_40 ) ;
return - V_217 ;
}
V_2 -> V_187 = V_110 ;
for ( V_42 = 1 ; V_42 <= V_156 ; V_42 ++ ) {
V_110 = F_147 ( V_213 , V_42 ) ;
if ( V_110 <= 0 ) {
F_75 ( & V_213 -> V_83 , L_41 ) ;
return - V_217 ;
}
V_2 -> V_35 [ V_42 - 1 ] . V_109 = V_110 ;
}
return 0 ;
}
static int F_148 ( struct V_212 * V_213 )
{
struct V_1 * V_2 ;
int V_150 , V_42 ;
V_2 = F_149 ( & V_213 -> V_83 , sizeof( * V_2 ) , V_152 ) ;
if ( ! V_2 )
return - V_84 ;
V_2 -> V_83 = & V_213 -> V_83 ;
F_150 ( V_213 , V_2 ) ;
V_150 = F_143 ( V_213 , V_2 ) ;
if ( V_150 )
return V_150 ;
V_2 -> V_220 = F_151 ( & V_213 -> V_83 , NULL ) ;
if ( F_152 ( V_2 -> V_220 ) && ! F_153 ( & V_213 -> V_83 ) ) {
F_75 ( & V_213 -> V_83 , L_42 ) ;
return F_154 ( V_2 -> V_220 ) ;
}
if ( ! F_152 ( V_2 -> V_220 ) ) {
V_150 = F_155 ( V_2 -> V_220 ) ;
if ( V_150 ) {
F_75 ( & V_213 -> V_83 , L_43 , V_150 ) ;
return V_150 ;
}
}
V_150 = F_121 ( V_2 ) ;
if ( V_150 )
goto V_221;
V_150 = F_156 ( & V_213 -> V_83 , F_157 ( 42 ) ) ;
if ( V_150 ) {
F_75 ( & V_213 -> V_83 , L_44 ) ;
goto V_222;
}
F_142 ( V_2 ) ;
V_150 = F_105 ( V_2 ) ;
if ( V_150 )
goto V_221;
V_150 = F_122 ( V_2 ) ;
if ( V_150 )
goto V_223;
F_113 ( V_2 ) ;
V_150 = F_139 ( V_2 ) ;
if ( V_150 )
goto V_224;
return 0 ;
V_224:
F_127 ( V_2 ) ;
V_223:
for ( V_42 = 0 ; V_42 < V_156 ; V_42 ++ )
F_99 ( & V_2 -> V_35 [ V_42 ] ) ;
V_222:
V_221:
if ( ! F_152 ( V_2 -> V_220 ) )
F_158 ( V_2 -> V_220 ) ;
return V_150 ;
}
static int F_159 ( struct V_212 * V_213 )
{
struct V_1 * V_2 = F_160 ( V_213 ) ;
struct V_34 * V_35 ;
int V_42 ;
F_141 ( V_2 ) ;
F_111 ( V_2 ) ;
F_109 ( V_2 ) ;
F_127 ( V_2 ) ;
for ( V_42 = 0 ; V_42 < V_156 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
F_137 ( & V_35 -> V_112 ) ;
F_99 ( V_35 ) ;
}
if ( ! F_152 ( V_2 -> V_220 ) )
F_158 ( V_2 -> V_220 ) ;
return 0 ;
}
