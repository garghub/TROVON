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
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
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
struct V_61 * V_81 , T_6 V_38 , T_6 V_39 ,
T_3 V_7 , unsigned long V_46 )
{
struct V_36 * V_86 = NULL , * V_87 ;
struct V_34 * V_35 ;
T_3 V_88 ;
if ( F_14 ( ! V_81 || ! V_7 ) )
return NULL ;
V_35 = F_15 ( V_81 ) ;
do {
V_87 = F_25 ( V_35 ) ;
if ( ! V_87 )
goto V_89;
V_88 = F_56 ( T_3 , V_7 , V_90 ) ;
F_11 ( V_35 , V_87 , V_38 , V_39 , V_88 ) ;
if ( ! V_86 )
V_86 = V_87 ;
V_87 -> V_50 . V_51 = 0 ;
F_57 ( & V_87 -> V_50 ) ;
V_7 -= V_88 ;
V_38 += V_88 ;
V_39 += V_88 ;
F_38 ( & V_87 -> V_56 , & V_86 -> V_54 ) ;
} while ( V_7 );
V_87 -> V_50 . V_46 = V_46 ;
V_87 -> V_50 . V_51 = - V_91 ;
F_58 ( & V_86 -> V_54 , & V_87 -> V_54 ) ;
return & V_87 -> V_50 ;
V_89:
if ( ! V_86 )
return NULL ;
F_52 ( V_35 , & V_86 -> V_54 ) ;
return NULL ;
}
static struct V_49 * F_59 (
struct V_61 * V_81 , struct V_92 * V_93 ,
T_1 V_94 , struct V_92 * V_95 ,
T_1 V_96 , unsigned long V_46 )
{
struct V_36 * V_86 = NULL , * V_87 = NULL ;
struct V_34 * V_35 ;
T_3 V_97 , V_98 ;
T_6 V_38 , V_39 ;
T_3 V_7 ;
if ( F_14 ( ! V_81 ) )
return NULL ;
if ( F_14 ( ! V_94 || ! V_96 ) )
return NULL ;
if ( F_14 ( ! V_93 || ! V_95 ) )
return NULL ;
V_35 = F_15 ( V_81 ) ;
V_97 = F_60 ( V_93 ) ;
V_98 = F_60 ( V_95 ) ;
V_94 -- ;
V_96 -- ;
while ( true ) {
V_7 = F_56 ( T_3 , V_98 , V_97 ) ;
V_7 = F_56 ( T_3 , V_7 , V_90 ) ;
if ( V_7 == 0 )
goto V_99;
V_38 = F_61 ( V_93 ) + F_60 ( V_93 ) - V_97 ;
V_39 = F_61 ( V_95 ) + F_60 ( V_95 ) - V_98 ;
V_87 = F_25 ( V_35 ) ;
if ( ! V_87 )
goto V_89;
F_11 ( V_35 , V_87 , V_38 , V_39 , V_7 ) ;
if ( ! V_86 )
V_86 = V_87 ;
V_87 -> V_50 . V_51 = 0 ;
F_57 ( & V_87 -> V_50 ) ;
V_97 -= V_7 ;
V_98 -= V_7 ;
F_38 ( & V_87 -> V_56 , & V_86 -> V_54 ) ;
V_99:
if ( V_97 == 0 ) {
if ( V_94 == 0 )
break;
V_93 = F_62 ( V_93 ) ;
if ( ! V_93 )
break;
V_94 -- ;
V_97 = F_60 ( V_93 ) ;
}
if ( V_98 == 0 ) {
if ( V_96 == 0 )
break;
V_95 = F_62 ( V_95 ) ;
if ( ! V_95 )
break;
V_96 -- ;
V_98 = F_60 ( V_95 ) ;
}
}
if ( ! V_87 )
return NULL ;
V_87 -> V_50 . V_46 = V_46 ;
V_87 -> V_50 . V_51 = - V_91 ;
F_58 ( & V_86 -> V_54 , & V_87 -> V_54 ) ;
return & V_87 -> V_50 ;
V_89:
if ( ! V_86 )
return NULL ;
F_52 ( V_35 , & V_86 -> V_54 ) ;
return NULL ;
}
static struct V_49 * F_63 (
struct V_61 * V_81 , T_6 V_38 , T_6 * V_39 ,
T_1 V_11 , T_3 V_7 , unsigned long V_46 )
{
struct V_36 * V_86 = NULL , * V_87 ;
struct V_34 * V_35 ;
static T_4 V_100 [ V_101 ] = {
0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_14 ( ! V_81 || ! V_7 ) )
return NULL ;
V_35 = F_15 ( V_81 ) ;
do {
V_87 = F_25 ( V_35 ) ;
if ( ! V_87 )
goto V_89;
F_12 ( V_35 , V_87 , & V_38 , V_39 ,
V_11 , & V_7 , V_100 ) ;
if ( ! V_86 )
V_86 = V_87 ;
V_87 -> V_50 . V_51 = 0 ;
F_57 ( & V_87 -> V_50 ) ;
F_38 ( & V_87 -> V_56 , & V_86 -> V_54 ) ;
} while ( V_7 );
V_87 -> V_50 . V_46 = V_46 ;
V_87 -> V_50 . V_51 = - V_91 ;
F_58 ( & V_86 -> V_54 , & V_87 -> V_54 ) ;
return & V_87 -> V_50 ;
V_89:
if ( ! V_86 )
return NULL ;
F_52 ( V_35 , & V_86 -> V_54 ) ;
return NULL ;
}
static struct V_49 * F_64 (
struct V_61 * V_81 , T_6 * V_38 , T_6 * V_39 ,
T_1 V_11 , const T_4 * V_48 , T_3 V_7 , unsigned long V_46 )
{
struct V_36 * V_86 = NULL , * V_87 ;
struct V_34 * V_35 ;
T_3 V_102 = V_7 ;
T_6 V_103 [ V_101 ] ;
static T_4 V_100 [ V_101 ] = { 0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_14 ( ! V_81 || ! V_7 ) )
return NULL ;
V_35 = F_15 ( V_81 ) ;
memcpy ( V_103 , V_39 , sizeof( * V_39 ) * V_11 ) ;
if ( V_46 & V_104 )
V_7 = 0 ;
if ( V_46 & V_105 )
V_102 = 0 ;
do {
V_87 = F_25 ( V_35 ) ;
if ( ! V_87 )
goto V_89;
if ( ! V_86 )
V_86 = V_87 ;
V_87 -> V_50 . V_51 = 0 ;
F_57 ( & V_87 -> V_50 ) ;
F_38 ( & V_87 -> V_56 , & V_86 -> V_54 ) ;
if ( V_7 ) {
F_12 ( V_35 , V_87 , & V_38 [ 0 ] , V_39 ,
V_11 , & V_7 , V_100 ) ;
continue;
}
if ( V_102 ) {
F_12 ( V_35 , V_87 , & V_38 [ 1 ] , V_103 ,
V_11 , & V_102 , V_48 ) ;
}
} while ( V_7 || V_102 );
V_87 -> V_50 . V_46 = V_46 ;
V_87 -> V_50 . V_51 = - V_91 ;
F_58 ( & V_86 -> V_54 , & V_87 -> V_54 ) ;
return & V_87 -> V_50 ;
V_89:
if ( ! V_86 )
return NULL ;
F_52 ( V_35 , & V_86 -> V_54 ) ;
return NULL ;
}
static void F_65 ( struct V_61 * V_81 )
{
struct V_34 * V_35 = F_15 ( V_81 ) ;
F_17 ( & V_35 -> V_53 ) ;
F_41 ( V_35 ) ;
F_20 ( & V_35 -> V_53 ) ;
}
static enum V_106 F_66 ( struct V_61 * V_81 ,
T_8 V_51 ,
struct V_107 * V_108 )
{
return F_67 ( V_81 , V_51 , V_108 ) ;
}
static void F_68 ( unsigned long V_109 )
{
struct V_34 * V_35 = (struct V_34 * ) V_109 ;
F_44 ( V_35 ) ;
F_69 ( V_35 -> V_110 ) ;
}
static T_9 F_70 ( int V_111 , void * V_112 )
{
struct V_34 * V_35 = (struct V_34 * ) V_112 ;
F_71 ( ! V_35 ) ;
F_72 ( V_35 -> V_110 ) ;
F_73 ( & V_35 -> V_113 ) ;
return V_114 ;
}
static T_9 F_74 ( int V_111 , void * V_112 )
{
struct V_1 * V_2 = (struct V_1 * ) V_112 ;
unsigned long V_115 ;
T_1 V_3 , V_42 ;
V_3 = F_2 ( V_2 -> V_116 + V_117 ) ;
F_40 ( V_3 , V_2 -> V_116 + V_117 ) ;
V_115 = V_3 >> V_118 ;
F_75 (i, &int_mask, ARRAY_SIZE(xgene_dma_err))
F_76 ( V_2 -> V_83 ,
L_13 , V_3 , V_119 [ V_42 ] ) ;
return V_114 ;
}
static void F_77 ( struct V_66 * V_67 )
{
int V_42 ;
F_40 ( V_67 -> V_120 , V_67 -> V_2 -> V_121 + V_122 ) ;
for ( V_42 = 0 ; V_42 < V_123 ; V_42 ++ )
F_40 ( V_67 -> V_124 [ V_42 ] , V_67 -> V_2 -> V_121 +
V_125 + ( V_42 * 4 ) ) ;
}
static void F_78 ( struct V_66 * V_67 )
{
memset ( V_67 -> V_124 , 0 , sizeof( T_1 ) * V_123 ) ;
F_77 ( V_67 ) ;
}
static void F_79 ( struct V_66 * V_67 )
{
void * V_126 = V_67 -> V_124 ;
T_2 V_127 = V_67 -> V_128 ;
T_1 V_42 , V_3 ;
V_67 -> V_70 = V_67 -> V_129 / V_130 ;
F_78 ( V_67 ) ;
F_80 ( V_126 , V_131 ) ;
if ( V_67 -> V_132 == V_30 ) {
F_81 ( V_126 ) ;
F_82 ( V_126 ) ;
F_83 ( V_126 ) ;
}
F_84 ( V_126 ) ;
F_85 ( V_126 ) ;
F_86 ( V_126 ) ;
F_87 ( V_126 , V_127 ) ;
F_88 ( V_126 , V_127 ) ;
F_89 ( V_126 , V_67 -> V_133 ) ;
F_77 ( V_67 ) ;
F_40 ( F_90 ( V_67 -> V_112 ) ,
V_67 -> V_2 -> V_121 + V_134 ) ;
F_40 ( F_91 ( V_67 -> V_120 ) ,
V_67 -> V_2 -> V_121 + V_135 ) ;
if ( V_67 -> V_132 != V_136 )
return;
for ( V_42 = 0 ; V_42 < V_67 -> V_70 ; V_42 ++ ) {
struct V_21 * V_22 ;
V_22 = & V_67 -> V_68 [ V_42 ] ;
V_22 -> V_25 = F_6 ( V_79 ) ;
}
V_3 = F_2 ( V_67 -> V_2 -> V_121 + V_137 ) ;
F_92 ( V_3 , V_67 -> V_138 ) ;
F_40 ( V_3 , V_67 -> V_2 -> V_121 + V_137 ) ;
}
static void F_93 ( struct V_66 * V_67 )
{
T_1 V_139 , V_3 ;
if ( V_67 -> V_132 == V_136 ) {
V_3 = F_2 ( V_67 -> V_2 -> V_121 +
V_137 ) ;
F_94 ( V_3 , V_67 -> V_138 ) ;
F_40 ( V_3 , V_67 -> V_2 -> V_121 +
V_137 ) ;
}
V_139 = F_90 ( V_67 -> V_112 ) ;
F_40 ( V_139 , V_67 -> V_2 -> V_121 + V_134 ) ;
F_40 ( 0 , V_67 -> V_2 -> V_121 + V_135 ) ;
F_78 ( V_67 ) ;
}
static void F_95 ( struct V_66 * V_67 )
{
V_67 -> V_140 = V_67 -> V_2 -> V_141 +
F_96 ( ( V_67 -> V_120 -
V_142 ) ) ;
V_67 -> V_72 = V_67 -> V_140 + V_143 ;
}
static int F_97 ( struct V_34 * V_35 ,
enum V_144 V_133 )
{
int V_129 ;
switch ( V_133 ) {
case V_145 :
V_129 = 0x200 ;
break;
case V_146 :
V_129 = 0x800 ;
break;
case V_147 :
V_129 = 0x4000 ;
break;
case V_148 :
V_129 = 0x10000 ;
break;
case V_149 :
V_129 = 0x80000 ;
break;
default:
F_27 ( V_35 , L_14 , V_133 ) ;
return - V_52 ;
}
return V_129 ;
}
static void F_98 ( struct V_66 * V_67 )
{
F_93 ( V_67 ) ;
if ( V_67 -> V_150 ) {
F_99 ( V_67 -> V_2 -> V_83 , V_67 -> V_129 ,
V_67 -> V_150 , V_67 -> V_128 ) ;
V_67 -> V_150 = NULL ;
}
}
static void F_100 ( struct V_34 * V_35 )
{
F_98 ( & V_35 -> V_76 ) ;
F_98 ( & V_35 -> V_43 ) ;
}
static int F_101 ( struct V_34 * V_35 ,
struct V_66 * V_67 ,
enum V_144 V_133 )
{
int V_151 ;
V_67 -> V_2 = V_35 -> V_2 ;
V_67 -> V_133 = V_133 ;
V_67 -> V_120 = V_35 -> V_2 -> V_152 ++ ;
V_67 -> V_112 = F_102 ( V_67 -> V_132 , V_67 -> V_138 ) ;
V_151 = F_97 ( V_35 , V_133 ) ;
if ( V_151 <= 0 )
return V_151 ;
V_67 -> V_129 = V_151 ;
V_67 -> V_150 = F_103 ( V_35 -> V_83 , V_67 -> V_129 ,
& V_67 -> V_128 , V_153 ) ;
if ( ! V_67 -> V_150 ) {
F_27 ( V_35 , L_15 ) ;
return - V_84 ;
}
F_95 ( V_67 ) ;
F_79 ( V_67 ) ;
return 0 ;
}
static int F_104 ( struct V_34 * V_35 )
{
struct V_66 * V_76 = & V_35 -> V_76 ;
struct V_66 * V_43 = & V_35 -> V_43 ;
int V_151 ;
V_76 -> V_132 = V_136 ;
V_76 -> V_138 = V_154 + V_35 -> V_112 ;
V_151 = F_101 ( V_35 , V_76 ,
V_148 ) ;
if ( V_151 )
return V_151 ;
F_23 ( V_35 , L_16 ,
V_76 -> V_112 , V_76 -> V_120 , V_76 -> V_150 ) ;
V_43 -> V_132 = V_30 ;
V_43 -> V_138 = V_155 + V_35 -> V_112 ;
V_151 = F_101 ( V_35 , V_43 ,
V_148 ) ;
if ( V_151 ) {
F_98 ( V_76 ) ;
return V_151 ;
}
V_43 -> V_28 = F_105 ( V_76 -> V_120 ) ;
F_23 ( V_35 ,
L_17 ,
V_43 -> V_112 , V_43 -> V_120 , V_43 -> V_150 ) ;
V_35 -> V_74 = V_43 -> V_70 ;
return V_151 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_151 , V_42 , V_156 ;
for ( V_42 = 0 ; V_42 < V_157 ; V_42 ++ ) {
V_151 = F_104 ( & V_2 -> V_35 [ V_42 ] ) ;
if ( V_151 ) {
for ( V_156 = 0 ; V_156 < V_42 ; V_156 ++ )
F_100 ( & V_2 -> V_35 [ V_156 ] ) ;
return V_151 ;
}
}
return V_151 ;
}
static void F_107 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_116 + V_158 ) ;
F_108 ( V_3 ) ;
F_109 ( V_3 ) ;
F_40 ( V_3 , V_2 -> V_116 + V_158 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_116 + V_158 ) ;
F_111 ( V_3 ) ;
F_40 ( V_3 , V_2 -> V_116 + V_158 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
F_40 ( V_159 ,
V_2 -> V_116 + V_160 ) ;
F_40 ( V_159 ,
V_2 -> V_116 + V_161 ) ;
F_40 ( V_159 ,
V_2 -> V_116 + V_162 ) ;
F_40 ( V_159 ,
V_2 -> V_116 + V_163 ) ;
F_40 ( V_159 ,
V_2 -> V_116 + V_164 ) ;
F_40 ( V_159 , V_2 -> V_116 + V_165 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
F_40 ( V_166 ,
V_2 -> V_116 + V_160 ) ;
F_40 ( V_166 ,
V_2 -> V_116 + V_161 ) ;
F_40 ( V_166 ,
V_2 -> V_116 + V_162 ) ;
F_40 ( V_166 ,
V_2 -> V_116 + V_163 ) ;
F_40 ( V_166 ,
V_2 -> V_116 + V_164 ) ;
F_40 ( V_166 ,
V_2 -> V_116 + V_165 ) ;
}
static void F_114 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_40 ( V_167 ,
V_2 -> V_116 + V_168 ) ;
if ( F_1 ( V_2 ) )
F_40 ( F_115 ( 0x1D ) ,
V_2 -> V_116 + V_169 ) ;
else
F_116 ( V_2 -> V_83 , L_18 ) ;
F_107 ( V_2 ) ;
F_113 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_116 + V_170 ) ;
F_116 ( V_2 -> V_83 ,
L_19 ,
F_117 ( V_3 ) , F_118 ( V_3 ) ,
F_119 ( V_3 ) , V_157 ) ;
}
static int F_120 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_121 + V_171 ) &&
( ! F_2 ( V_2 -> V_121 + V_172 ) ) )
return 0 ;
F_40 ( 0x3 , V_2 -> V_121 + V_171 ) ;
F_40 ( 0x0 , V_2 -> V_121 + V_172 ) ;
F_40 ( 0x0 , V_2 -> V_121 + V_173 ) ;
F_2 ( V_2 -> V_121 + V_173 ) ;
F_121 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_121 + V_174 )
!= V_175 ) {
F_76 ( V_2 -> V_83 ,
L_20 ) ;
return - V_176 ;
}
F_40 ( V_177 ,
V_2 -> V_121 + V_178 ) ;
F_40 ( V_179 ,
V_2 -> V_121 + V_180 ) ;
F_40 ( V_181 ,
V_2 -> V_121 + V_182 ) ;
F_40 ( V_183 ,
V_2 -> V_121 + V_184 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 )
{
int V_151 ;
V_151 = F_120 ( V_2 ) ;
if ( V_151 )
return V_151 ;
F_40 ( 0x0 , V_2 -> V_116 + V_185 ) ;
F_2 ( V_2 -> V_116 + V_185 ) ;
F_121 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_116 + V_186 )
!= V_187 ) {
F_76 ( V_2 -> V_83 ,
L_21 ) ;
return - V_176 ;
}
return 0 ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_151 , V_42 , V_156 ;
V_151 = F_124 ( V_2 -> V_83 , V_2 -> V_188 , F_74 ,
0 , L_22 , V_2 ) ;
if ( V_151 ) {
F_76 ( V_2 -> V_83 ,
L_23 , V_2 -> V_188 ) ;
return V_151 ;
}
for ( V_42 = 0 ; V_42 < V_157 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
V_151 = F_124 ( V_35 -> V_83 , V_35 -> V_110 ,
F_70 ,
0 , V_35 -> V_82 , V_35 ) ;
if ( V_151 ) {
F_27 ( V_35 , L_24 ,
V_35 -> V_110 ) ;
F_125 ( V_2 -> V_83 , V_2 -> V_188 , V_2 ) ;
for ( V_156 = 0 ; V_156 < V_42 ; V_156 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
F_125 ( V_35 -> V_83 , V_35 -> V_110 , V_35 ) ;
}
return V_151 ;
}
}
return 0 ;
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_42 ;
F_125 ( V_2 -> V_83 , V_2 -> V_188 , V_2 ) ;
for ( V_42 = 0 ; V_42 < V_157 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
F_125 ( V_35 -> V_83 , V_35 -> V_110 , V_35 ) ;
}
}
static void F_127 ( struct V_34 * V_35 ,
struct V_189 * V_190 )
{
F_128 ( V_190 -> V_191 ) ;
F_129 ( V_192 , V_190 -> V_191 ) ;
F_129 ( V_193 , V_190 -> V_191 ) ;
if ( ( V_35 -> V_112 == V_194 ) &&
F_1 ( V_35 -> V_2 ) ) {
F_129 ( V_195 , V_190 -> V_191 ) ;
F_129 ( V_196 , V_190 -> V_191 ) ;
} else if ( ( V_35 -> V_112 == V_197 ) &&
! F_1 ( V_35 -> V_2 ) ) {
F_129 ( V_196 , V_190 -> V_191 ) ;
}
V_190 -> V_83 = V_35 -> V_83 ;
V_190 -> V_198 = F_50 ;
V_190 -> V_199 = F_53 ;
V_190 -> V_200 = F_65 ;
V_190 -> V_201 = F_66 ;
V_190 -> V_202 = F_55 ;
V_190 -> V_203 = F_59 ;
if ( F_130 ( V_196 , V_190 -> V_191 ) ) {
V_190 -> V_204 = F_63 ;
V_190 -> V_205 = V_101 ;
V_190 -> V_206 = V_207 ;
}
if ( F_130 ( V_195 , V_190 -> V_191 ) ) {
V_190 -> V_208 = F_64 ;
V_190 -> V_209 = V_101 ;
V_190 -> V_210 = V_207 ;
}
}
static int F_131 ( struct V_1 * V_2 , int V_112 )
{
struct V_34 * V_35 = & V_2 -> V_35 [ V_112 ] ;
struct V_189 * V_190 = & V_2 -> V_190 [ V_112 ] ;
int V_151 ;
V_35 -> V_61 . V_211 = V_190 ;
F_132 ( & V_35 -> V_53 ) ;
F_28 ( & V_35 -> V_55 ) ;
F_28 ( & V_35 -> V_75 ) ;
F_28 ( & V_35 -> V_65 ) ;
F_133 ( & V_35 -> V_113 , F_68 ,
( unsigned long ) V_35 ) ;
V_35 -> V_71 = 0 ;
V_35 -> V_57 = NULL ;
F_134 ( & V_35 -> V_61 ) ;
F_127 ( V_35 , V_190 ) ;
F_28 ( & V_190 -> V_212 ) ;
F_38 ( & V_35 -> V_61 . V_213 , & V_190 -> V_212 ) ;
V_151 = F_135 ( V_190 ) ;
if ( V_151 ) {
F_27 ( V_35 , L_25 , V_151 ) ;
F_136 ( & V_35 -> V_113 ) ;
return V_151 ;
}
F_116 ( V_2 -> V_83 ,
L_26 , F_137 ( & V_35 -> V_61 ) ,
F_130 ( V_192 , V_190 -> V_191 ) ? L_27 : L_28 ,
F_130 ( V_193 , V_190 -> V_191 ) ? L_29 : L_28 ,
F_130 ( V_196 , V_190 -> V_191 ) ? L_30 : L_28 ,
F_130 ( V_195 , V_190 -> V_191 ) ? L_31 : L_28 ) ;
return 0 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_151 , V_42 , V_156 ;
for ( V_42 = 0 ; V_42 < V_157 ; V_42 ++ ) {
V_151 = F_131 ( V_2 , V_42 ) ;
if ( V_151 ) {
for ( V_156 = 0 ; V_156 < V_42 ; V_156 ++ ) {
F_139 ( & V_2 -> V_190 [ V_156 ] ) ;
F_136 ( & V_2 -> V_35 [ V_156 ] . V_113 ) ;
}
return V_151 ;
}
}
return V_151 ;
}
static void F_140 ( struct V_1 * V_2 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_157 ; V_42 ++ )
F_139 ( & V_2 -> V_190 [ V_42 ] ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_42 ;
V_2 -> V_152 = V_142 ;
for ( V_42 = 0 ; V_42 < V_157 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
V_35 -> V_83 = V_2 -> V_83 ;
V_35 -> V_2 = V_2 ;
V_35 -> V_112 = V_42 ;
snprintf ( V_35 -> V_82 , sizeof( V_35 -> V_82 ) , L_32 , V_35 -> V_112 ) ;
}
}
static int F_142 ( struct V_214 * V_215 ,
struct V_1 * V_2 )
{
struct V_216 * V_217 ;
int V_111 , V_42 ;
V_217 = F_143 ( V_215 , V_218 , 0 ) ;
if ( ! V_217 ) {
F_76 ( & V_215 -> V_83 , L_33 ) ;
return - V_219 ;
}
V_2 -> V_116 = F_144 ( & V_215 -> V_83 , V_217 -> V_220 ,
F_145 ( V_217 ) ) ;
if ( ! V_2 -> V_116 ) {
F_76 ( & V_215 -> V_83 , L_34 ) ;
return - V_84 ;
}
V_217 = F_143 ( V_215 , V_218 , 1 ) ;
if ( ! V_217 ) {
F_76 ( & V_215 -> V_83 , L_35 ) ;
return - V_219 ;
}
V_2 -> V_121 = F_144 ( & V_215 -> V_83 , V_217 -> V_220 ,
F_145 ( V_217 ) ) ;
if ( ! V_2 -> V_121 ) {
F_76 ( & V_215 -> V_83 , L_36 ) ;
return - V_84 ;
}
V_217 = F_143 ( V_215 , V_218 , 2 ) ;
if ( ! V_217 ) {
F_76 ( & V_215 -> V_83 , L_37 ) ;
return - V_219 ;
}
V_2 -> V_141 = F_144 ( & V_215 -> V_83 , V_217 -> V_220 ,
F_145 ( V_217 ) ) ;
if ( ! V_2 -> V_141 ) {
F_76 ( & V_215 -> V_83 , L_38 ) ;
return - V_84 ;
}
V_2 -> V_141 += V_221 ;
V_217 = F_143 ( V_215 , V_218 , 3 ) ;
if ( ! V_217 ) {
F_76 ( & V_215 -> V_83 , L_39 ) ;
return - V_219 ;
}
V_2 -> V_4 = F_144 ( & V_215 -> V_83 , V_217 -> V_220 ,
F_145 ( V_217 ) ) ;
if ( ! V_2 -> V_4 ) {
F_76 ( & V_215 -> V_83 , L_40 ) ;
return - V_84 ;
}
V_111 = F_146 ( V_215 , 0 ) ;
if ( V_111 <= 0 ) {
F_76 ( & V_215 -> V_83 , L_41 ) ;
return - V_219 ;
}
V_2 -> V_188 = V_111 ;
for ( V_42 = 1 ; V_42 <= V_157 ; V_42 ++ ) {
V_111 = F_146 ( V_215 , V_42 ) ;
if ( V_111 <= 0 ) {
F_76 ( & V_215 -> V_83 , L_42 ) ;
return - V_219 ;
}
V_2 -> V_35 [ V_42 - 1 ] . V_110 = V_111 ;
}
return 0 ;
}
static int F_147 ( struct V_214 * V_215 )
{
struct V_1 * V_2 ;
int V_151 , V_42 ;
V_2 = F_148 ( & V_215 -> V_83 , sizeof( * V_2 ) , V_153 ) ;
if ( ! V_2 )
return - V_84 ;
V_2 -> V_83 = & V_215 -> V_83 ;
F_149 ( V_215 , V_2 ) ;
V_151 = F_142 ( V_215 , V_2 ) ;
if ( V_151 )
return V_151 ;
V_2 -> V_222 = F_150 ( & V_215 -> V_83 , NULL ) ;
if ( F_151 ( V_2 -> V_222 ) && ! F_152 ( & V_215 -> V_83 ) ) {
F_76 ( & V_215 -> V_83 , L_43 ) ;
return F_153 ( V_2 -> V_222 ) ;
}
if ( ! F_151 ( V_2 -> V_222 ) ) {
V_151 = F_154 ( V_2 -> V_222 ) ;
if ( V_151 ) {
F_76 ( & V_215 -> V_83 , L_44 , V_151 ) ;
return V_151 ;
}
}
V_151 = F_122 ( V_2 ) ;
if ( V_151 )
goto V_223;
V_151 = F_155 ( & V_215 -> V_83 , F_156 ( 42 ) ) ;
if ( V_151 ) {
F_76 ( & V_215 -> V_83 , L_45 ) ;
goto V_224;
}
F_141 ( V_2 ) ;
V_151 = F_106 ( V_2 ) ;
if ( V_151 )
goto V_223;
V_151 = F_123 ( V_2 ) ;
if ( V_151 )
goto V_225;
F_114 ( V_2 ) ;
V_151 = F_138 ( V_2 ) ;
if ( V_151 )
goto V_226;
return 0 ;
V_226:
F_126 ( V_2 ) ;
V_225:
for ( V_42 = 0 ; V_42 < V_157 ; V_42 ++ )
F_100 ( & V_2 -> V_35 [ V_42 ] ) ;
V_224:
V_223:
if ( ! F_151 ( V_2 -> V_222 ) )
F_157 ( V_2 -> V_222 ) ;
return V_151 ;
}
static int F_158 ( struct V_214 * V_215 )
{
struct V_1 * V_2 = F_159 ( V_215 ) ;
struct V_34 * V_35 ;
int V_42 ;
F_140 ( V_2 ) ;
F_112 ( V_2 ) ;
F_110 ( V_2 ) ;
F_126 ( V_2 ) ;
for ( V_42 = 0 ; V_42 < V_157 ; V_42 ++ ) {
V_35 = & V_2 -> V_35 [ V_42 ] ;
F_136 ( & V_35 -> V_113 ) ;
F_100 ( V_35 ) ;
}
if ( ! F_151 ( V_2 -> V_222 ) )
F_157 ( V_2 -> V_222 ) ;
return 0 ;
}
