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
static T_5 * F_7 ( struct V_20 * V_21 , int V_22 )
{
switch ( V_22 ) {
case 0 :
return & V_21 -> V_23 ;
case 1 :
return & V_21 -> V_24 ;
case 2 :
return & V_21 -> V_25 ;
case 3 :
return & V_21 -> V_26 ;
default:
F_8 ( L_1 ) ;
}
return NULL ;
}
static void F_9 ( struct V_20 * V_21 ,
T_7 V_27 )
{
V_21 -> V_24 |= F_6 ( V_28 ) ;
V_21 -> V_24 |= F_6 ( ( T_2 ) V_29 <<
V_30 ) ;
V_21 -> V_23 |= F_6 ( V_31 ) ;
V_21 -> V_25 |= F_6 ( ( T_2 ) V_27 <<
V_32 ) ;
}
static void F_10 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
T_6 * V_37 , T_6 * V_38 ,
T_1 V_11 , T_3 * V_19 ,
const T_4 * V_39 )
{
struct V_20 * V_40 , * V_41 ;
T_3 V_7 = * V_19 ;
int V_42 ;
V_40 = & V_36 -> V_40 ;
V_41 = & V_36 -> V_41 ;
F_9 ( V_40 , V_34 -> V_43 . V_27 ) ;
V_40 -> V_26 |= F_6 ( V_44 ) ;
V_40 -> V_25 |= F_6 ( * V_37 ) ;
V_40 -> V_24 |= F_6 ( V_45 ) ;
V_40 -> V_26 |= F_6 ( F_4 ( V_11 ) ) ;
for ( V_42 = 0 ; V_42 < V_11 ; V_42 ++ ) {
V_7 = * V_19 ;
F_5 ( ( V_42 == 0 ) ? & V_40 -> V_23 :
F_7 ( V_41 , V_42 - 1 ) ,
& V_7 , & V_38 [ V_42 ] ) ;
V_40 -> V_26 |= F_6 ( ( V_39 [ V_42 ] << ( ( V_42 + 1 ) * 8 ) ) ) ;
}
* V_19 = V_7 ;
* V_37 += V_8 ;
V_36 -> V_46 |= V_47 ;
}
static T_8 F_11 ( struct V_48 * V_49 )
{
struct V_35 * V_21 ;
struct V_33 * V_34 ;
T_8 V_50 ;
if ( F_12 ( ! V_49 ) )
return - V_51 ;
V_34 = F_13 ( V_49 -> V_34 ) ;
V_21 = F_14 ( V_49 ) ;
F_15 ( & V_34 -> V_52 ) ;
V_50 = F_16 ( V_49 ) ;
F_17 ( & V_21 -> V_53 , & V_34 -> V_54 ) ;
F_18 ( & V_34 -> V_52 ) ;
return V_50 ;
}
static void F_19 ( struct V_33 * V_34 ,
struct V_35 * V_21 )
{
F_20 ( & V_21 -> V_55 ) ;
F_21 ( V_34 , L_2 , V_21 ) ;
F_22 ( V_34 -> V_56 , V_21 , V_21 -> V_49 . V_57 ) ;
}
static struct V_35 * F_23 (
struct V_33 * V_34 )
{
struct V_35 * V_21 ;
T_6 V_57 ;
V_21 = F_24 ( V_34 -> V_56 , V_58 , & V_57 ) ;
if ( ! V_21 ) {
F_25 ( V_34 , L_3 ) ;
return NULL ;
}
F_26 ( & V_21 -> V_53 ) ;
V_21 -> V_49 . V_57 = V_57 ;
V_21 -> V_49 . V_59 = F_11 ;
F_27 ( & V_21 -> V_49 , & V_34 -> V_60 ) ;
F_21 ( V_34 , L_4 , V_21 ) ;
return V_21 ;
}
static void F_28 ( struct V_33 * V_34 )
{
struct V_35 * V_21 , * V_61 ;
F_29 (desc, _desc, &chan->ld_completed, node) {
if ( F_30 ( & V_21 -> V_49 ) )
F_19 ( V_34 , V_21 ) ;
}
}
static void F_31 ( struct V_33 * V_34 ,
struct V_35 * V_21 )
{
struct V_48 * V_49 = & V_21 -> V_49 ;
if ( V_49 -> V_50 == 0 )
return;
F_32 ( V_49 ) ;
F_33 ( V_49 ) ;
F_34 ( V_49 , NULL ) ;
F_35 ( V_49 ) ;
}
static void F_36 ( struct V_33 * V_34 ,
struct V_35 * V_21 )
{
F_20 ( & V_21 -> V_55 ) ;
if ( ! F_30 ( & V_21 -> V_49 ) ) {
F_37 ( & V_21 -> V_55 , & V_34 -> V_62 ) ;
return;
}
F_21 ( V_34 , L_2 , V_21 ) ;
F_22 ( V_34 -> V_56 , V_21 , V_21 -> V_49 . V_57 ) ;
}
static void F_38 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_63 * V_64 = & V_34 -> V_43 ;
struct V_20 * V_65 ;
V_65 = & V_64 -> V_65 [ V_64 -> V_66 ] ;
if ( ++ V_64 -> V_66 == V_64 -> V_67 )
V_64 -> V_66 = 0 ;
memcpy ( V_65 , & V_36 -> V_40 , sizeof( * V_65 ) ) ;
if ( V_36 -> V_46 & V_47 ) {
V_65 = & V_64 -> V_65 [ V_64 -> V_66 ] ;
if ( ++ V_64 -> V_66 == V_64 -> V_67 )
V_64 -> V_66 = 0 ;
memcpy ( V_65 , & V_36 -> V_41 , sizeof( * V_65 ) ) ;
}
V_34 -> V_68 += ( ( V_36 -> V_46 &
V_47 ) ? 2 : 1 ) ;
F_39 ( ( V_36 -> V_46 & V_47 ) ?
2 : 1 , V_64 -> V_69 ) ;
}
static void F_40 ( struct V_33 * V_34 )
{
struct V_35 * V_36 , * V_70 ;
if ( F_41 ( & V_34 -> V_54 ) ) {
F_21 ( V_34 , L_5 ) ;
return;
}
F_29 (desc_sw, _desc_sw, &chan->ld_pending, node) {
if ( V_34 -> V_68 >= V_34 -> V_71 )
return;
F_38 ( V_34 , V_36 ) ;
F_42 ( & V_36 -> V_55 , & V_34 -> V_72 ) ;
}
}
static void F_43 ( struct V_33 * V_34 )
{
struct V_63 * V_64 = & V_34 -> V_73 ;
struct V_35 * V_36 , * V_70 ;
struct V_20 * V_65 ;
struct V_74 V_62 ;
T_4 V_75 ;
F_26 ( & V_62 ) ;
F_15 ( & V_34 -> V_52 ) ;
F_28 ( V_34 ) ;
F_29 (desc_sw, _desc_sw, &chan->ld_running, node) {
V_65 = & V_64 -> V_65 [ V_64 -> V_66 ] ;
if ( F_12 ( F_44 ( V_65 -> V_24 ) ==
V_76 ) )
break;
if ( ++ V_64 -> V_66 == V_64 -> V_67 )
V_64 -> V_66 = 0 ;
V_75 = F_45 (
F_46 ( F_44 (
V_65 -> V_24 ) ) ,
F_47 ( F_44 (
V_65 -> V_24 ) ) ) ;
if ( V_75 ) {
F_25 ( V_34 , L_6 , V_77 [ V_75 ] ) ;
F_48 ( & V_36 -> V_40 ,
L_7 ) ;
if ( V_36 -> V_46 & V_47 )
F_48 ( & V_36 -> V_41 ,
L_8 ) ;
F_48 ( V_65 ,
L_9 ) ;
}
F_39 ( - 1 , V_64 -> V_69 ) ;
V_65 -> V_24 = F_6 ( V_76 ) ;
V_34 -> V_68 -= ( ( V_36 -> V_46 &
V_47 ) ? 2 : 1 ) ;
F_42 ( & V_36 -> V_55 , & V_62 ) ;
}
F_40 ( V_34 ) ;
F_18 ( & V_34 -> V_52 ) ;
F_29 (desc_sw, _desc_sw, &ld_completed, node) {
F_31 ( V_34 , V_36 ) ;
F_36 ( V_34 , V_36 ) ;
}
}
static int F_49 ( struct V_60 * V_78 )
{
struct V_33 * V_34 = F_13 ( V_78 ) ;
if ( V_34 -> V_56 )
return 1 ;
V_34 -> V_56 = F_50 ( V_34 -> V_79 , V_34 -> V_80 ,
sizeof( struct V_35 ) ,
0 , 0 ) ;
if ( ! V_34 -> V_56 ) {
F_25 ( V_34 , L_10 ) ;
return - V_81 ;
}
F_21 ( V_34 , L_11 ) ;
return 1 ;
}
static void F_51 ( struct V_33 * V_34 ,
struct V_74 * V_82 )
{
struct V_35 * V_21 , * V_61 ;
F_29 (desc, _desc, list, node)
F_19 ( V_34 , V_21 ) ;
}
static void F_52 ( struct V_60 * V_78 )
{
struct V_33 * V_34 = F_13 ( V_78 ) ;
F_21 ( V_34 , L_12 ) ;
if ( ! V_34 -> V_56 )
return;
F_43 ( V_34 ) ;
F_15 ( & V_34 -> V_52 ) ;
F_51 ( V_34 , & V_34 -> V_54 ) ;
F_51 ( V_34 , & V_34 -> V_72 ) ;
F_51 ( V_34 , & V_34 -> V_62 ) ;
F_18 ( & V_34 -> V_52 ) ;
F_53 ( V_34 -> V_56 ) ;
V_34 -> V_56 = NULL ;
}
static struct V_48 * F_54 (
struct V_60 * V_78 , T_6 V_37 , T_6 * V_38 ,
T_1 V_11 , T_3 V_7 , unsigned long V_46 )
{
struct V_35 * V_83 = NULL , * V_84 ;
struct V_33 * V_34 ;
static T_4 V_85 [ V_86 ] = {
0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_12 ( ! V_78 || ! V_7 ) )
return NULL ;
V_34 = F_13 ( V_78 ) ;
do {
V_84 = F_23 ( V_34 ) ;
if ( ! V_84 )
goto V_87;
F_10 ( V_34 , V_84 , & V_37 , V_38 ,
V_11 , & V_7 , V_85 ) ;
if ( ! V_83 )
V_83 = V_84 ;
V_84 -> V_49 . V_50 = 0 ;
F_55 ( & V_84 -> V_49 ) ;
F_37 ( & V_84 -> V_55 , & V_83 -> V_53 ) ;
} while ( V_7 );
V_84 -> V_49 . V_46 = V_46 ;
V_84 -> V_49 . V_50 = - V_88 ;
F_56 ( & V_83 -> V_53 , & V_84 -> V_53 ) ;
return & V_84 -> V_49 ;
V_87:
if ( ! V_83 )
return NULL ;
F_51 ( V_34 , & V_83 -> V_53 ) ;
return NULL ;
}
static struct V_48 * F_57 (
struct V_60 * V_78 , T_6 * V_37 , T_6 * V_38 ,
T_1 V_11 , const T_4 * V_39 , T_3 V_7 , unsigned long V_46 )
{
struct V_35 * V_83 = NULL , * V_84 ;
struct V_33 * V_34 ;
T_3 V_89 = V_7 ;
T_6 V_90 [ V_86 ] ;
static T_4 V_85 [ V_86 ] = { 0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_12 ( ! V_78 || ! V_7 ) )
return NULL ;
V_34 = F_13 ( V_78 ) ;
memcpy ( V_90 , V_38 , sizeof( * V_38 ) * V_11 ) ;
if ( V_46 & V_91 )
V_7 = 0 ;
if ( V_46 & V_92 )
V_89 = 0 ;
do {
V_84 = F_23 ( V_34 ) ;
if ( ! V_84 )
goto V_87;
if ( ! V_83 )
V_83 = V_84 ;
V_84 -> V_49 . V_50 = 0 ;
F_55 ( & V_84 -> V_49 ) ;
F_37 ( & V_84 -> V_55 , & V_83 -> V_53 ) ;
if ( V_7 ) {
F_10 ( V_34 , V_84 , & V_37 [ 0 ] , V_38 ,
V_11 , & V_7 , V_85 ) ;
continue;
}
if ( V_89 ) {
F_10 ( V_34 , V_84 , & V_37 [ 1 ] , V_90 ,
V_11 , & V_89 , V_39 ) ;
}
} while ( V_7 || V_89 );
V_84 -> V_49 . V_46 = V_46 ;
V_84 -> V_49 . V_50 = - V_88 ;
F_56 ( & V_83 -> V_53 , & V_84 -> V_53 ) ;
return & V_84 -> V_49 ;
V_87:
if ( ! V_83 )
return NULL ;
F_51 ( V_34 , & V_83 -> V_53 ) ;
return NULL ;
}
static void F_58 ( struct V_60 * V_78 )
{
struct V_33 * V_34 = F_13 ( V_78 ) ;
F_15 ( & V_34 -> V_52 ) ;
F_40 ( V_34 ) ;
F_18 ( & V_34 -> V_52 ) ;
}
static enum V_93 F_59 ( struct V_60 * V_78 ,
T_8 V_50 ,
struct V_94 * V_95 )
{
return F_60 ( V_78 , V_50 , V_95 ) ;
}
static void F_61 ( unsigned long V_96 )
{
struct V_33 * V_34 = (struct V_33 * ) V_96 ;
F_43 ( V_34 ) ;
F_62 ( V_34 -> V_97 ) ;
}
static T_9 F_63 ( int V_98 , void * V_99 )
{
struct V_33 * V_34 = (struct V_33 * ) V_99 ;
F_64 ( ! V_34 ) ;
F_65 ( V_34 -> V_97 ) ;
F_66 ( & V_34 -> V_100 ) ;
return V_101 ;
}
static T_9 F_67 ( int V_98 , void * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
unsigned long V_102 ;
T_1 V_3 , V_42 ;
V_3 = F_2 ( V_2 -> V_103 + V_104 ) ;
F_39 ( V_3 , V_2 -> V_103 + V_104 ) ;
V_102 = V_3 >> V_105 ;
F_68 (i, &int_mask, ARRAY_SIZE(xgene_dma_err))
F_69 ( V_2 -> V_80 ,
L_13 , V_3 , V_106 [ V_42 ] ) ;
return V_101 ;
}
static void F_70 ( struct V_63 * V_64 )
{
int V_42 ;
F_39 ( V_64 -> V_107 , V_64 -> V_2 -> V_108 + V_109 ) ;
for ( V_42 = 0 ; V_42 < V_110 ; V_42 ++ )
F_39 ( V_64 -> V_111 [ V_42 ] , V_64 -> V_2 -> V_108 +
V_112 + ( V_42 * 4 ) ) ;
}
static void F_71 ( struct V_63 * V_64 )
{
memset ( V_64 -> V_111 , 0 , sizeof( T_1 ) * V_110 ) ;
F_70 ( V_64 ) ;
}
static void F_72 ( struct V_63 * V_64 )
{
void * V_113 = V_64 -> V_111 ;
T_2 V_114 = V_64 -> V_115 ;
T_1 V_42 , V_3 ;
V_64 -> V_67 = V_64 -> V_116 / V_117 ;
F_71 ( V_64 ) ;
F_73 ( V_113 , V_118 ) ;
if ( V_64 -> V_119 == V_29 ) {
F_74 ( V_113 ) ;
F_75 ( V_113 ) ;
F_76 ( V_113 ) ;
}
F_77 ( V_113 ) ;
F_78 ( V_113 ) ;
F_79 ( V_113 ) ;
F_80 ( V_113 , V_114 ) ;
F_81 ( V_113 , V_114 ) ;
F_82 ( V_113 , V_64 -> V_120 ) ;
F_70 ( V_64 ) ;
F_39 ( F_83 ( V_64 -> V_99 ) ,
V_64 -> V_2 -> V_108 + V_121 ) ;
F_39 ( F_84 ( V_64 -> V_107 ) ,
V_64 -> V_2 -> V_108 + V_122 ) ;
if ( V_64 -> V_119 != V_123 )
return;
for ( V_42 = 0 ; V_42 < V_64 -> V_67 ; V_42 ++ ) {
struct V_20 * V_21 ;
V_21 = & V_64 -> V_65 [ V_42 ] ;
V_21 -> V_24 = F_6 ( V_76 ) ;
}
V_3 = F_2 ( V_64 -> V_2 -> V_108 + V_124 ) ;
F_85 ( V_3 , V_64 -> V_125 ) ;
F_39 ( V_3 , V_64 -> V_2 -> V_108 + V_124 ) ;
}
static void F_86 ( struct V_63 * V_64 )
{
T_1 V_126 , V_3 ;
if ( V_64 -> V_119 == V_123 ) {
V_3 = F_2 ( V_64 -> V_2 -> V_108 +
V_124 ) ;
F_87 ( V_3 , V_64 -> V_125 ) ;
F_39 ( V_3 , V_64 -> V_2 -> V_108 +
V_124 ) ;
}
V_126 = F_83 ( V_64 -> V_99 ) ;
F_39 ( V_126 , V_64 -> V_2 -> V_108 + V_121 ) ;
F_39 ( 0 , V_64 -> V_2 -> V_108 + V_122 ) ;
F_71 ( V_64 ) ;
}
static void F_88 ( struct V_63 * V_64 )
{
V_64 -> V_127 = V_64 -> V_2 -> V_128 +
F_89 ( ( V_64 -> V_107 -
V_129 ) ) ;
V_64 -> V_69 = V_64 -> V_127 + V_130 ;
}
static int F_90 ( struct V_33 * V_34 ,
enum V_131 V_120 )
{
int V_116 ;
switch ( V_120 ) {
case V_132 :
V_116 = 0x200 ;
break;
case V_133 :
V_116 = 0x800 ;
break;
case V_134 :
V_116 = 0x4000 ;
break;
case V_135 :
V_116 = 0x10000 ;
break;
case V_136 :
V_116 = 0x80000 ;
break;
default:
F_25 ( V_34 , L_14 , V_120 ) ;
return - V_51 ;
}
return V_116 ;
}
static void F_91 ( struct V_63 * V_64 )
{
F_86 ( V_64 ) ;
if ( V_64 -> V_137 ) {
F_92 ( V_64 -> V_2 -> V_80 , V_64 -> V_116 ,
V_64 -> V_137 , V_64 -> V_115 ) ;
V_64 -> V_137 = NULL ;
}
}
static void F_93 ( struct V_33 * V_34 )
{
F_91 ( & V_34 -> V_73 ) ;
F_91 ( & V_34 -> V_43 ) ;
}
static int F_94 ( struct V_33 * V_34 ,
struct V_63 * V_64 ,
enum V_131 V_120 )
{
int V_138 ;
V_64 -> V_2 = V_34 -> V_2 ;
V_64 -> V_120 = V_120 ;
V_64 -> V_107 = V_34 -> V_2 -> V_139 ++ ;
V_64 -> V_99 = F_95 ( V_64 -> V_119 , V_64 -> V_125 ) ;
V_138 = F_90 ( V_34 , V_120 ) ;
if ( V_138 <= 0 )
return V_138 ;
V_64 -> V_116 = V_138 ;
V_64 -> V_137 = F_96 ( V_34 -> V_80 , V_64 -> V_116 ,
& V_64 -> V_115 , V_140 ) ;
if ( ! V_64 -> V_137 ) {
F_25 ( V_34 , L_15 ) ;
return - V_81 ;
}
F_88 ( V_64 ) ;
F_72 ( V_64 ) ;
return 0 ;
}
static int F_97 ( struct V_33 * V_34 )
{
struct V_63 * V_73 = & V_34 -> V_73 ;
struct V_63 * V_43 = & V_34 -> V_43 ;
int V_138 ;
V_73 -> V_119 = V_123 ;
V_73 -> V_125 = V_141 + V_34 -> V_99 ;
V_138 = F_94 ( V_34 , V_73 ,
V_135 ) ;
if ( V_138 )
return V_138 ;
F_21 ( V_34 , L_16 ,
V_73 -> V_99 , V_73 -> V_107 , V_73 -> V_137 ) ;
V_43 -> V_119 = V_29 ;
V_43 -> V_125 = V_142 + V_34 -> V_99 ;
V_138 = F_94 ( V_34 , V_43 ,
V_135 ) ;
if ( V_138 ) {
F_91 ( V_73 ) ;
return V_138 ;
}
V_43 -> V_27 = F_98 ( V_73 -> V_107 ) ;
F_21 ( V_34 ,
L_17 ,
V_43 -> V_99 , V_43 -> V_107 , V_43 -> V_137 ) ;
V_34 -> V_71 = V_43 -> V_67 ;
return V_138 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_138 , V_42 , V_143 ;
for ( V_42 = 0 ; V_42 < V_144 ; V_42 ++ ) {
V_138 = F_97 ( & V_2 -> V_34 [ V_42 ] ) ;
if ( V_138 ) {
for ( V_143 = 0 ; V_143 < V_42 ; V_143 ++ )
F_93 ( & V_2 -> V_34 [ V_143 ] ) ;
return V_138 ;
}
}
return V_138 ;
}
static void F_100 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_103 + V_145 ) ;
F_101 ( V_3 ) ;
F_102 ( V_3 ) ;
F_39 ( V_3 , V_2 -> V_103 + V_145 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_103 + V_145 ) ;
F_104 ( V_3 ) ;
F_39 ( V_3 , V_2 -> V_103 + V_145 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
F_39 ( V_146 ,
V_2 -> V_103 + V_147 ) ;
F_39 ( V_146 ,
V_2 -> V_103 + V_148 ) ;
F_39 ( V_146 ,
V_2 -> V_103 + V_149 ) ;
F_39 ( V_146 ,
V_2 -> V_103 + V_150 ) ;
F_39 ( V_146 ,
V_2 -> V_103 + V_151 ) ;
F_39 ( V_146 , V_2 -> V_103 + V_152 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
F_39 ( V_153 ,
V_2 -> V_103 + V_147 ) ;
F_39 ( V_153 ,
V_2 -> V_103 + V_148 ) ;
F_39 ( V_153 ,
V_2 -> V_103 + V_149 ) ;
F_39 ( V_153 ,
V_2 -> V_103 + V_150 ) ;
F_39 ( V_153 ,
V_2 -> V_103 + V_151 ) ;
F_39 ( V_153 ,
V_2 -> V_103 + V_152 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_39 ( V_154 ,
V_2 -> V_103 + V_155 ) ;
if ( F_1 ( V_2 ) )
F_39 ( F_108 ( 0x1D ) ,
V_2 -> V_103 + V_156 ) ;
else
F_109 ( V_2 -> V_80 , L_18 ) ;
F_100 ( V_2 ) ;
F_106 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_103 + V_157 ) ;
F_109 ( V_2 -> V_80 ,
L_19 ,
F_110 ( V_3 ) , F_111 ( V_3 ) ,
F_112 ( V_3 ) , V_144 ) ;
}
static int F_113 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_108 + V_158 ) &&
( ! F_2 ( V_2 -> V_108 + V_159 ) ) )
return 0 ;
F_39 ( 0x3 , V_2 -> V_108 + V_158 ) ;
F_39 ( 0x0 , V_2 -> V_108 + V_159 ) ;
F_39 ( 0x0 , V_2 -> V_108 + V_160 ) ;
F_2 ( V_2 -> V_108 + V_160 ) ;
F_114 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_108 + V_161 )
!= V_162 ) {
F_69 ( V_2 -> V_80 ,
L_20 ) ;
return - V_163 ;
}
F_39 ( V_164 ,
V_2 -> V_108 + V_165 ) ;
F_39 ( V_166 ,
V_2 -> V_108 + V_167 ) ;
F_39 ( V_168 ,
V_2 -> V_108 + V_169 ) ;
F_39 ( V_170 ,
V_2 -> V_108 + V_171 ) ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 )
{
int V_138 ;
V_138 = F_113 ( V_2 ) ;
if ( V_138 )
return V_138 ;
F_39 ( 0x0 , V_2 -> V_103 + V_172 ) ;
F_2 ( V_2 -> V_103 + V_172 ) ;
F_114 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_103 + V_173 )
!= V_174 ) {
F_69 ( V_2 -> V_80 ,
L_21 ) ;
return - V_163 ;
}
return 0 ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_33 * V_34 ;
int V_138 , V_42 , V_143 ;
V_138 = F_117 ( V_2 -> V_80 , V_2 -> V_175 , F_67 ,
0 , L_22 , V_2 ) ;
if ( V_138 ) {
F_69 ( V_2 -> V_80 ,
L_23 , V_2 -> V_175 ) ;
return V_138 ;
}
for ( V_42 = 0 ; V_42 < V_144 ; V_42 ++ ) {
V_34 = & V_2 -> V_34 [ V_42 ] ;
F_118 ( V_34 -> V_97 , V_176 ) ;
V_138 = F_117 ( V_34 -> V_80 , V_34 -> V_97 ,
F_63 ,
0 , V_34 -> V_79 , V_34 ) ;
if ( V_138 ) {
F_25 ( V_34 , L_24 ,
V_34 -> V_97 ) ;
F_119 ( V_2 -> V_80 , V_2 -> V_175 , V_2 ) ;
for ( V_143 = 0 ; V_143 < V_42 ; V_143 ++ ) {
V_34 = & V_2 -> V_34 [ V_42 ] ;
F_120 ( V_34 -> V_97 , V_176 ) ;
F_119 ( V_34 -> V_80 , V_34 -> V_97 , V_34 ) ;
}
return V_138 ;
}
}
return 0 ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_33 * V_34 ;
int V_42 ;
F_119 ( V_2 -> V_80 , V_2 -> V_175 , V_2 ) ;
for ( V_42 = 0 ; V_42 < V_144 ; V_42 ++ ) {
V_34 = & V_2 -> V_34 [ V_42 ] ;
F_120 ( V_34 -> V_97 , V_176 ) ;
F_119 ( V_34 -> V_80 , V_34 -> V_97 , V_34 ) ;
}
}
static void F_122 ( struct V_33 * V_34 ,
struct V_177 * V_178 )
{
F_123 ( V_178 -> V_179 ) ;
if ( ( V_34 -> V_99 == V_180 ) &&
F_1 ( V_34 -> V_2 ) ) {
F_124 ( V_181 , V_178 -> V_179 ) ;
F_124 ( V_182 , V_178 -> V_179 ) ;
} else if ( ( V_34 -> V_99 == V_183 ) &&
! F_1 ( V_34 -> V_2 ) ) {
F_124 ( V_182 , V_178 -> V_179 ) ;
}
V_178 -> V_80 = V_34 -> V_80 ;
V_178 -> V_184 = F_49 ;
V_178 -> V_185 = F_52 ;
V_178 -> V_186 = F_58 ;
V_178 -> V_187 = F_59 ;
if ( F_125 ( V_182 , V_178 -> V_179 ) ) {
V_178 -> V_188 = F_54 ;
V_178 -> V_189 = V_86 ;
V_178 -> V_190 = V_191 ;
}
if ( F_125 ( V_181 , V_178 -> V_179 ) ) {
V_178 -> V_192 = F_57 ;
V_178 -> V_193 = V_86 ;
V_178 -> V_194 = V_191 ;
}
}
static int F_126 ( struct V_1 * V_2 , int V_99 )
{
struct V_33 * V_34 = & V_2 -> V_34 [ V_99 ] ;
struct V_177 * V_178 = & V_2 -> V_178 [ V_99 ] ;
int V_138 ;
V_34 -> V_60 . V_195 = V_178 ;
F_127 ( & V_34 -> V_52 ) ;
F_26 ( & V_34 -> V_54 ) ;
F_26 ( & V_34 -> V_72 ) ;
F_26 ( & V_34 -> V_62 ) ;
F_128 ( & V_34 -> V_100 , F_61 ,
( unsigned long ) V_34 ) ;
V_34 -> V_68 = 0 ;
V_34 -> V_56 = NULL ;
F_129 ( & V_34 -> V_60 ) ;
F_122 ( V_34 , V_178 ) ;
F_26 ( & V_178 -> V_196 ) ;
F_37 ( & V_34 -> V_60 . V_197 , & V_178 -> V_196 ) ;
V_138 = F_130 ( V_178 ) ;
if ( V_138 ) {
F_25 ( V_34 , L_25 , V_138 ) ;
F_131 ( & V_34 -> V_100 ) ;
return V_138 ;
}
F_109 ( V_2 -> V_80 ,
L_26 , F_132 ( & V_34 -> V_60 ) ,
F_125 ( V_182 , V_178 -> V_179 ) ? L_27 : L_28 ,
F_125 ( V_181 , V_178 -> V_179 ) ? L_29 : L_28 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 )
{
int V_138 , V_42 , V_143 ;
for ( V_42 = 0 ; V_42 < V_144 ; V_42 ++ ) {
V_138 = F_126 ( V_2 , V_42 ) ;
if ( V_138 ) {
for ( V_143 = 0 ; V_143 < V_42 ; V_143 ++ ) {
F_134 ( & V_2 -> V_178 [ V_143 ] ) ;
F_131 ( & V_2 -> V_34 [ V_143 ] . V_100 ) ;
}
return V_138 ;
}
}
return V_138 ;
}
static void F_135 ( struct V_1 * V_2 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_144 ; V_42 ++ )
F_134 ( & V_2 -> V_178 [ V_42 ] ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_33 * V_34 ;
int V_42 ;
V_2 -> V_139 = V_129 ;
for ( V_42 = 0 ; V_42 < V_144 ; V_42 ++ ) {
V_34 = & V_2 -> V_34 [ V_42 ] ;
V_34 -> V_80 = V_2 -> V_80 ;
V_34 -> V_2 = V_2 ;
V_34 -> V_99 = V_42 ;
snprintf ( V_34 -> V_79 , sizeof( V_34 -> V_79 ) , L_30 , V_34 -> V_99 ) ;
}
}
static int F_137 ( struct V_198 * V_199 ,
struct V_1 * V_2 )
{
struct V_200 * V_201 ;
int V_98 , V_42 ;
V_201 = F_138 ( V_199 , V_202 , 0 ) ;
if ( ! V_201 ) {
F_69 ( & V_199 -> V_80 , L_31 ) ;
return - V_203 ;
}
V_2 -> V_103 = F_139 ( & V_199 -> V_80 , V_201 -> V_204 ,
F_140 ( V_201 ) ) ;
if ( ! V_2 -> V_103 ) {
F_69 ( & V_199 -> V_80 , L_32 ) ;
return - V_81 ;
}
V_201 = F_138 ( V_199 , V_202 , 1 ) ;
if ( ! V_201 ) {
F_69 ( & V_199 -> V_80 , L_33 ) ;
return - V_203 ;
}
V_2 -> V_108 = F_139 ( & V_199 -> V_80 , V_201 -> V_204 ,
F_140 ( V_201 ) ) ;
if ( ! V_2 -> V_108 ) {
F_69 ( & V_199 -> V_80 , L_34 ) ;
return - V_81 ;
}
V_201 = F_138 ( V_199 , V_202 , 2 ) ;
if ( ! V_201 ) {
F_69 ( & V_199 -> V_80 , L_35 ) ;
return - V_203 ;
}
V_2 -> V_128 = F_139 ( & V_199 -> V_80 , V_201 -> V_204 ,
F_140 ( V_201 ) ) ;
if ( ! V_2 -> V_128 ) {
F_69 ( & V_199 -> V_80 , L_36 ) ;
return - V_81 ;
}
V_2 -> V_128 += V_205 ;
V_201 = F_138 ( V_199 , V_202 , 3 ) ;
if ( ! V_201 ) {
F_69 ( & V_199 -> V_80 , L_37 ) ;
return - V_203 ;
}
V_2 -> V_4 = F_139 ( & V_199 -> V_80 , V_201 -> V_204 ,
F_140 ( V_201 ) ) ;
if ( ! V_2 -> V_4 ) {
F_69 ( & V_199 -> V_80 , L_38 ) ;
return - V_81 ;
}
V_98 = F_141 ( V_199 , 0 ) ;
if ( V_98 <= 0 ) {
F_69 ( & V_199 -> V_80 , L_39 ) ;
return - V_203 ;
}
V_2 -> V_175 = V_98 ;
for ( V_42 = 1 ; V_42 <= V_144 ; V_42 ++ ) {
V_98 = F_141 ( V_199 , V_42 ) ;
if ( V_98 <= 0 ) {
F_69 ( & V_199 -> V_80 , L_40 ) ;
return - V_203 ;
}
V_2 -> V_34 [ V_42 - 1 ] . V_97 = V_98 ;
}
return 0 ;
}
static int F_142 ( struct V_198 * V_199 )
{
struct V_1 * V_2 ;
int V_138 , V_42 ;
V_2 = F_143 ( & V_199 -> V_80 , sizeof( * V_2 ) , V_140 ) ;
if ( ! V_2 )
return - V_81 ;
V_2 -> V_80 = & V_199 -> V_80 ;
F_144 ( V_199 , V_2 ) ;
V_138 = F_137 ( V_199 , V_2 ) ;
if ( V_138 )
return V_138 ;
V_2 -> V_206 = F_145 ( & V_199 -> V_80 , NULL ) ;
if ( F_146 ( V_2 -> V_206 ) && ! F_147 ( & V_199 -> V_80 ) ) {
F_69 ( & V_199 -> V_80 , L_41 ) ;
return F_148 ( V_2 -> V_206 ) ;
}
if ( ! F_146 ( V_2 -> V_206 ) ) {
V_138 = F_149 ( V_2 -> V_206 ) ;
if ( V_138 ) {
F_69 ( & V_199 -> V_80 , L_42 , V_138 ) ;
return V_138 ;
}
}
V_138 = F_115 ( V_2 ) ;
if ( V_138 )
goto V_207;
V_138 = F_150 ( & V_199 -> V_80 , F_151 ( 42 ) ) ;
if ( V_138 ) {
F_69 ( & V_199 -> V_80 , L_43 ) ;
goto V_208;
}
F_136 ( V_2 ) ;
V_138 = F_99 ( V_2 ) ;
if ( V_138 )
goto V_207;
V_138 = F_116 ( V_2 ) ;
if ( V_138 )
goto V_209;
F_107 ( V_2 ) ;
V_138 = F_133 ( V_2 ) ;
if ( V_138 )
goto V_210;
return 0 ;
V_210:
F_121 ( V_2 ) ;
V_209:
for ( V_42 = 0 ; V_42 < V_144 ; V_42 ++ )
F_93 ( & V_2 -> V_34 [ V_42 ] ) ;
V_208:
V_207:
if ( ! F_146 ( V_2 -> V_206 ) )
F_152 ( V_2 -> V_206 ) ;
return V_138 ;
}
static int F_153 ( struct V_198 * V_199 )
{
struct V_1 * V_2 = F_154 ( V_199 ) ;
struct V_33 * V_34 ;
int V_42 ;
F_135 ( V_2 ) ;
F_105 ( V_2 ) ;
F_103 ( V_2 ) ;
F_121 ( V_2 ) ;
for ( V_42 = 0 ; V_42 < V_144 ; V_42 ++ ) {
V_34 = & V_2 -> V_34 [ V_42 ] ;
F_131 ( & V_34 -> V_100 ) ;
F_93 ( V_34 ) ;
}
if ( ! F_146 ( V_2 -> V_206 ) )
F_152 ( V_2 -> V_206 ) ;
return 0 ;
}
