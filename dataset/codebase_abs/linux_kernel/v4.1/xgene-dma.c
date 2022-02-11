static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
return ! ( V_3 & V_6 ) ;
}
static void F_3 ( T_2 * V_7 , int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
V_7 [ V_9 ] = F_4 ( V_7 [ V_9 ] ) ;
}
static T_3 F_5 ( T_1 V_10 )
{
return ( V_10 < V_11 ) ?
V_10 : V_12 ;
}
static T_4 F_6 ( T_1 V_13 )
{
static T_4 V_14 [] = {
V_15 ,
V_15 ,
V_15 ,
V_16 ,
V_17 ,
V_18
} ;
return V_14 [ V_13 ] ;
}
static T_1 F_7 ( struct V_19 * V_20 )
{
T_1 T_5 * V_21 = V_20 -> V_21 ;
T_1 V_22 = F_2 ( & V_21 [ 1 ] ) ;
return F_8 ( V_22 ) ;
}
static void F_9 ( void * V_23 , T_6 * V_10 ,
T_7 * V_24 )
{
T_6 V_25 = ( * V_10 < V_11 ) ?
* V_10 : V_11 ;
F_10 ( V_23 , * V_24 ) ;
F_11 ( V_23 , F_5 ( V_25 ) ) ;
* V_10 -= V_25 ;
* V_24 += V_25 ;
}
static void F_12 ( void * V_23 )
{
F_11 ( V_23 , V_26 ) ;
}
static void * F_13 ( T_2 * V_7 , int V_27 )
{
return ( V_27 % 2 ) ? ( V_7 + V_27 - 1 ) : ( V_7 + V_27 + 1 ) ;
}
static void F_14 ( void * V_7 , T_3 V_28 )
{
F_15 ( V_7 ) ;
F_16 ( V_7 ) ;
F_17 ( V_7 , V_28 ) ;
F_18 ( V_7 , V_29 ) ;
}
static void F_19 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
T_7 V_34 , T_7 V_35 ,
T_6 V_10 )
{
void * V_36 , * V_37 ;
int V_9 ;
V_36 = & V_33 -> V_36 ;
F_14 ( V_36 , V_31 -> V_38 . V_28 ) ;
F_20 ( V_36 ) ;
F_21 ( V_36 , V_34 ) ;
F_9 ( V_36 + 8 , & V_10 , & V_35 ) ;
if ( V_10 <= 0 ) {
V_37 = NULL ;
goto V_39;
}
V_37 = & V_33 -> V_37 ;
F_22 ( V_36 ) ;
for ( V_9 = 0 ; V_9 < 4 && V_10 ; V_9 ++ )
F_9 ( F_13 ( V_37 , V_9 ) ,
& V_10 , & V_35 ) ;
for (; V_9 < 4 ; V_9 ++ )
F_12 ( F_13 ( V_37 , V_9 ) ) ;
V_33 -> V_40 |= V_41 ;
V_39:
F_3 ( V_36 , 4 ) ;
if ( V_37 )
F_3 ( V_37 , 4 ) ;
}
static void F_23 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
T_7 * V_34 , T_7 * V_35 ,
T_1 V_13 , T_6 * V_25 ,
const T_4 * V_42 )
{
void * V_36 , * V_37 ;
T_6 V_10 = * V_25 ;
int V_9 ;
V_36 = & V_33 -> V_36 ;
V_37 = & V_33 -> V_37 ;
F_14 ( V_36 , V_31 -> V_38 . V_28 ) ;
F_20 ( V_36 ) ;
F_21 ( V_36 , * V_34 ) ;
F_22 ( V_36 ) ;
F_24 ( V_36 , F_6 ( V_13 ) ) ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
V_10 = * V_25 ;
F_9 ( ( V_9 == 0 ) ? ( V_36 + 8 ) :
F_13 ( V_37 , V_9 - 1 ) ,
& V_10 , & V_35 [ V_9 ] ) ;
F_25 ( V_36 , V_42 [ V_9 ] , V_9 ) ;
}
F_3 ( V_36 , 4 ) ;
F_3 ( V_37 , 4 ) ;
* V_25 = V_10 ;
* V_34 += V_11 ;
V_33 -> V_40 |= V_41 ;
}
static T_8 F_26 ( struct V_43 * V_44 )
{
struct V_32 * V_7 ;
struct V_30 * V_31 ;
T_8 V_45 ;
if ( F_27 ( ! V_44 ) )
return - V_46 ;
V_31 = F_28 ( V_44 -> V_31 ) ;
V_7 = F_29 ( V_44 ) ;
F_30 ( & V_31 -> V_47 ) ;
V_45 = F_31 ( V_44 ) ;
F_32 ( & V_7 -> V_48 , & V_31 -> V_49 ) ;
F_33 ( & V_31 -> V_47 ) ;
return V_45 ;
}
static void F_34 ( struct V_30 * V_31 ,
struct V_32 * V_7 )
{
F_35 ( & V_7 -> V_50 ) ;
F_36 ( V_31 , L_1 , V_7 ) ;
F_37 ( V_31 -> V_51 , V_7 , V_7 -> V_44 . V_52 ) ;
}
static struct V_32 * F_38 (
struct V_30 * V_31 )
{
struct V_32 * V_7 ;
T_7 V_52 ;
V_7 = F_39 ( V_31 -> V_51 , V_53 , & V_52 ) ;
if ( ! V_7 ) {
F_40 ( V_31 , L_2 ) ;
return NULL ;
}
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
F_41 ( & V_7 -> V_48 ) ;
V_7 -> V_44 . V_52 = V_52 ;
V_7 -> V_44 . V_54 = F_26 ;
F_42 ( & V_7 -> V_44 , & V_31 -> V_55 ) ;
F_36 ( V_31 , L_3 , V_7 ) ;
return V_7 ;
}
static void F_43 ( struct V_30 * V_31 )
{
struct V_32 * V_7 , * V_56 ;
F_44 (desc, _desc, &chan->ld_completed, node) {
if ( F_45 ( & V_7 -> V_44 ) )
F_34 ( V_31 , V_7 ) ;
}
}
static void F_46 ( struct V_30 * V_31 ,
struct V_32 * V_7 )
{
struct V_43 * V_44 = & V_7 -> V_44 ;
if ( V_44 -> V_45 == 0 )
return;
F_47 ( V_44 ) ;
if ( V_44 -> V_57 )
V_44 -> V_57 ( V_44 -> V_58 ) ;
F_48 ( V_44 ) ;
F_49 ( V_44 ) ;
}
static void F_50 ( struct V_30 * V_31 ,
struct V_32 * V_7 )
{
F_35 ( & V_7 -> V_50 ) ;
if ( ! F_45 ( & V_7 -> V_44 ) ) {
F_51 ( & V_7 -> V_50 , & V_31 -> V_59 ) ;
return;
}
F_36 ( V_31 , L_1 , V_7 ) ;
F_37 ( V_31 -> V_51 , V_7 , V_7 -> V_44 . V_52 ) ;
}
static int F_52 ( struct V_19 * V_20 ,
struct V_32 * V_33 )
{
struct V_60 * V_61 ;
if ( F_7 ( V_20 ) > ( V_20 -> V_62 - 2 ) )
return - V_63 ;
V_61 = & V_20 -> V_61 [ V_20 -> V_64 ] ;
if ( ++ V_20 -> V_64 == V_20 -> V_62 )
V_20 -> V_64 = 0 ;
memcpy ( V_61 , & V_33 -> V_36 , sizeof( * V_61 ) ) ;
if ( V_33 -> V_40 & V_41 ) {
V_61 = & V_20 -> V_61 [ V_20 -> V_64 ] ;
if ( ++ V_20 -> V_64 == V_20 -> V_62 )
V_20 -> V_64 = 0 ;
memcpy ( V_61 , & V_33 -> V_37 , sizeof( * V_61 ) ) ;
}
F_53 ( ( V_33 -> V_40 & V_41 ) ?
2 : 1 , V_20 -> V_65 ) ;
return 0 ;
}
static void F_54 ( struct V_30 * V_31 )
{
struct V_32 * V_33 , * V_66 ;
int V_67 ;
if ( F_55 ( & V_31 -> V_49 ) ) {
F_36 ( V_31 , L_4 ) ;
return;
}
F_44 (desc_sw, _desc_sw, &chan->ld_pending, node) {
if ( V_31 -> V_68 >= V_31 -> V_69 )
return;
V_67 = F_52 ( & V_31 -> V_38 , V_33 ) ;
if ( V_67 )
return;
F_56 ( & V_33 -> V_50 , & V_31 -> V_70 ) ;
V_31 -> V_68 ++ ;
}
}
static void F_57 ( struct V_30 * V_31 )
{
struct V_19 * V_20 = & V_31 -> V_71 ;
struct V_32 * V_33 , * V_66 ;
struct V_60 * V_61 ;
T_4 V_72 ;
F_43 ( V_31 ) ;
F_44 (desc_sw, _desc_sw, &chan->ld_running, node) {
V_61 = & V_20 -> V_61 [ V_20 -> V_64 ] ;
if ( F_27 ( F_58 ( V_61 ) ) )
break;
if ( ++ V_20 -> V_64 == V_20 -> V_62 )
V_20 -> V_64 = 0 ;
V_72 = F_59 (
F_60 ( F_61 (
V_61 -> V_73 ) ) ,
F_62 ( F_61 (
V_61 -> V_73 ) ) ) ;
if ( V_72 ) {
F_40 ( V_31 , L_5 , V_74 [ V_72 ] ) ;
F_63 ( & V_33 -> V_36 ,
L_6 ) ;
if ( V_33 -> V_40 & V_41 )
F_63 ( & V_33 -> V_37 ,
L_7 ) ;
F_63 ( V_61 ,
L_8 ) ;
}
F_53 ( - 1 , V_20 -> V_65 ) ;
F_64 ( V_61 ) ;
F_46 ( V_31 , V_33 ) ;
F_50 ( V_31 , V_33 ) ;
V_31 -> V_68 -- ;
}
F_54 ( V_31 ) ;
}
static int F_65 ( struct V_55 * V_75 )
{
struct V_30 * V_31 = F_28 ( V_75 ) ;
if ( V_31 -> V_51 )
return 1 ;
V_31 -> V_51 = F_66 ( V_31 -> V_76 , V_31 -> V_77 ,
sizeof( struct V_32 ) ,
0 , 0 ) ;
if ( ! V_31 -> V_51 ) {
F_40 ( V_31 , L_9 ) ;
return - V_78 ;
}
F_36 ( V_31 , L_10 ) ;
return 1 ;
}
static void F_67 ( struct V_30 * V_31 ,
struct V_79 * V_80 )
{
struct V_32 * V_7 , * V_56 ;
F_44 (desc, _desc, list, node)
F_34 ( V_31 , V_7 ) ;
}
static void F_68 ( struct V_30 * V_31 ,
struct V_79 * V_80 )
{
struct V_32 * V_7 , * V_56 ;
F_44 (desc, _desc, list, node)
F_34 ( V_31 , V_7 ) ;
}
static void F_69 ( struct V_55 * V_75 )
{
struct V_30 * V_31 = F_28 ( V_75 ) ;
F_36 ( V_31 , L_11 ) ;
if ( ! V_31 -> V_51 )
return;
F_30 ( & V_31 -> V_47 ) ;
F_57 ( V_31 ) ;
F_67 ( V_31 , & V_31 -> V_49 ) ;
F_67 ( V_31 , & V_31 -> V_70 ) ;
F_67 ( V_31 , & V_31 -> V_59 ) ;
F_33 ( & V_31 -> V_47 ) ;
F_70 ( V_31 -> V_51 ) ;
V_31 -> V_51 = NULL ;
}
static struct V_43 * F_71 (
struct V_55 * V_75 , T_7 V_34 , T_7 V_35 ,
T_6 V_10 , unsigned long V_40 )
{
struct V_32 * V_81 = NULL , * V_82 ;
struct V_30 * V_31 ;
T_6 V_83 ;
if ( F_27 ( ! V_75 || ! V_10 ) )
return NULL ;
V_31 = F_28 ( V_75 ) ;
do {
V_82 = F_38 ( V_31 ) ;
if ( ! V_82 )
goto V_84;
V_83 = F_72 ( T_6 , V_10 , V_85 ) ;
F_19 ( V_31 , V_82 , V_34 , V_35 , V_83 ) ;
if ( ! V_81 )
V_81 = V_82 ;
V_82 -> V_44 . V_45 = 0 ;
F_73 ( & V_82 -> V_44 ) ;
V_10 -= V_83 ;
V_34 += V_83 ;
V_35 += V_83 ;
F_51 ( & V_82 -> V_50 , & V_81 -> V_48 ) ;
} while ( V_10 );
V_82 -> V_44 . V_40 = V_40 ;
V_82 -> V_44 . V_45 = - V_63 ;
F_74 ( & V_81 -> V_48 , & V_82 -> V_48 ) ;
return & V_82 -> V_44 ;
V_84:
if ( ! V_81 )
return NULL ;
F_68 ( V_31 , & V_81 -> V_48 ) ;
return NULL ;
}
static struct V_43 * F_75 (
struct V_55 * V_75 , struct V_86 * V_87 ,
T_1 V_88 , struct V_86 * V_89 ,
T_1 V_90 , unsigned long V_40 )
{
struct V_32 * V_81 = NULL , * V_82 = NULL ;
struct V_30 * V_31 ;
T_6 V_91 , V_92 ;
T_7 V_34 , V_35 ;
T_6 V_10 ;
if ( F_27 ( ! V_75 ) )
return NULL ;
if ( F_27 ( ! V_88 || ! V_90 ) )
return NULL ;
if ( F_27 ( ! V_87 || ! V_89 ) )
return NULL ;
V_31 = F_28 ( V_75 ) ;
V_91 = F_76 ( V_87 ) ;
V_92 = F_76 ( V_89 ) ;
V_88 -- ;
V_90 -- ;
while ( true ) {
V_10 = F_72 ( T_6 , V_92 , V_91 ) ;
V_10 = F_72 ( T_6 , V_10 , V_85 ) ;
if ( V_10 == 0 )
goto V_93;
V_34 = F_77 ( V_87 ) + F_76 ( V_87 ) - V_91 ;
V_35 = F_77 ( V_89 ) + F_76 ( V_89 ) - V_92 ;
V_82 = F_38 ( V_31 ) ;
if ( ! V_82 )
goto V_84;
F_19 ( V_31 , V_82 , V_34 , V_35 , V_10 ) ;
if ( ! V_81 )
V_81 = V_82 ;
V_82 -> V_44 . V_45 = 0 ;
F_73 ( & V_82 -> V_44 ) ;
V_91 -= V_10 ;
V_92 -= V_10 ;
F_51 ( & V_82 -> V_50 , & V_81 -> V_48 ) ;
V_93:
if ( V_91 == 0 ) {
if ( V_88 == 0 )
break;
V_87 = F_78 ( V_87 ) ;
if ( ! V_87 )
break;
V_88 -- ;
V_91 = F_76 ( V_87 ) ;
}
if ( V_92 == 0 ) {
if ( V_90 == 0 )
break;
V_89 = F_78 ( V_89 ) ;
if ( ! V_89 )
break;
V_90 -- ;
V_92 = F_76 ( V_89 ) ;
}
}
if ( ! V_82 )
return NULL ;
V_82 -> V_44 . V_40 = V_40 ;
V_82 -> V_44 . V_45 = - V_63 ;
F_74 ( & V_81 -> V_48 , & V_82 -> V_48 ) ;
return & V_82 -> V_44 ;
V_84:
if ( ! V_81 )
return NULL ;
F_68 ( V_31 , & V_81 -> V_48 ) ;
return NULL ;
}
static struct V_43 * F_79 (
struct V_55 * V_75 , T_7 V_34 , T_7 * V_35 ,
T_1 V_13 , T_6 V_10 , unsigned long V_40 )
{
struct V_32 * V_81 = NULL , * V_82 ;
struct V_30 * V_31 ;
static T_4 V_94 [ V_95 ] = {
0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_27 ( ! V_75 || ! V_10 ) )
return NULL ;
V_31 = F_28 ( V_75 ) ;
do {
V_82 = F_38 ( V_31 ) ;
if ( ! V_82 )
goto V_84;
F_23 ( V_31 , V_82 , & V_34 , V_35 ,
V_13 , & V_10 , V_94 ) ;
if ( ! V_81 )
V_81 = V_82 ;
V_82 -> V_44 . V_45 = 0 ;
F_73 ( & V_82 -> V_44 ) ;
F_51 ( & V_82 -> V_50 , & V_81 -> V_48 ) ;
} while ( V_10 );
V_82 -> V_44 . V_40 = V_40 ;
V_82 -> V_44 . V_45 = - V_63 ;
F_74 ( & V_81 -> V_48 , & V_82 -> V_48 ) ;
return & V_82 -> V_44 ;
V_84:
if ( ! V_81 )
return NULL ;
F_68 ( V_31 , & V_81 -> V_48 ) ;
return NULL ;
}
static struct V_43 * F_80 (
struct V_55 * V_75 , T_7 * V_34 , T_7 * V_35 ,
T_1 V_13 , const T_4 * V_42 , T_6 V_10 , unsigned long V_40 )
{
struct V_32 * V_81 = NULL , * V_82 ;
struct V_30 * V_31 ;
T_6 V_96 = V_10 ;
T_7 V_97 [ V_95 ] ;
static T_4 V_94 [ V_95 ] = { 0x01 , 0x01 , 0x01 , 0x01 , 0x01 } ;
if ( F_27 ( ! V_75 || ! V_10 ) )
return NULL ;
V_31 = F_28 ( V_75 ) ;
memcpy ( V_97 , V_35 , sizeof( * V_35 ) * V_13 ) ;
if ( V_40 & V_98 )
V_10 = 0 ;
if ( V_40 & V_99 )
V_96 = 0 ;
do {
V_82 = F_38 ( V_31 ) ;
if ( ! V_82 )
goto V_84;
if ( ! V_81 )
V_81 = V_82 ;
V_82 -> V_44 . V_45 = 0 ;
F_73 ( & V_82 -> V_44 ) ;
F_51 ( & V_82 -> V_50 , & V_81 -> V_48 ) ;
if ( V_10 ) {
F_23 ( V_31 , V_82 , & V_34 [ 0 ] , V_35 ,
V_13 , & V_10 , V_94 ) ;
continue;
}
if ( V_96 ) {
F_23 ( V_31 , V_82 , & V_34 [ 1 ] , V_97 ,
V_13 , & V_96 , V_42 ) ;
}
} while ( V_10 || V_96 );
V_82 -> V_44 . V_40 = V_40 ;
V_82 -> V_44 . V_45 = - V_63 ;
F_74 ( & V_81 -> V_48 , & V_82 -> V_48 ) ;
return & V_82 -> V_44 ;
V_84:
if ( ! V_81 )
return NULL ;
F_68 ( V_31 , & V_81 -> V_48 ) ;
return NULL ;
}
static void F_81 ( struct V_55 * V_75 )
{
struct V_30 * V_31 = F_28 ( V_75 ) ;
F_30 ( & V_31 -> V_47 ) ;
F_54 ( V_31 ) ;
F_33 ( & V_31 -> V_47 ) ;
}
static enum V_100 F_82 ( struct V_55 * V_75 ,
T_8 V_45 ,
struct V_101 * V_102 )
{
return F_83 ( V_75 , V_45 , V_102 ) ;
}
static void F_84 ( unsigned long V_103 )
{
struct V_30 * V_31 = (struct V_30 * ) V_103 ;
F_30 ( & V_31 -> V_47 ) ;
F_57 ( V_31 ) ;
F_85 ( V_31 -> V_104 ) ;
F_33 ( & V_31 -> V_47 ) ;
}
static T_9 F_86 ( int V_105 , void * V_106 )
{
struct V_30 * V_31 = (struct V_30 * ) V_106 ;
F_87 ( ! V_31 ) ;
F_88 ( V_31 -> V_104 ) ;
F_89 ( & V_31 -> V_107 ) ;
return V_108 ;
}
static T_9 F_90 ( int V_105 , void * V_106 )
{
struct V_1 * V_2 = (struct V_1 * ) V_106 ;
unsigned long V_109 ;
T_1 V_3 , V_9 ;
V_3 = F_2 ( V_2 -> V_110 + V_111 ) ;
F_53 ( V_3 , V_2 -> V_110 + V_111 ) ;
V_109 = V_3 >> V_112 ;
F_91 (i, &int_mask, ARRAY_SIZE(xgene_dma_err))
F_92 ( V_2 -> V_77 ,
L_12 , V_3 , V_113 [ V_9 ] ) ;
return V_108 ;
}
static void F_93 ( struct V_19 * V_20 )
{
int V_9 ;
F_53 ( V_20 -> V_114 , V_20 -> V_2 -> V_115 + V_116 ) ;
for ( V_9 = 0 ; V_9 < V_117 ; V_9 ++ )
F_53 ( V_20 -> V_118 [ V_9 ] , V_20 -> V_2 -> V_115 +
V_119 + ( V_9 * 4 ) ) ;
}
static void F_94 ( struct V_19 * V_20 )
{
memset ( V_20 -> V_118 , 0 , sizeof( T_1 ) * V_117 ) ;
F_93 ( V_20 ) ;
}
static void F_95 ( struct V_19 * V_20 )
{
void * V_120 = V_20 -> V_118 ;
T_2 V_121 = V_20 -> V_122 ;
void * V_7 ;
T_1 V_9 , V_3 ;
V_20 -> V_62 = V_20 -> V_123 / V_124 ;
F_94 ( V_20 ) ;
F_96 ( V_120 , V_125 ) ;
if ( V_20 -> V_126 == V_29 ) {
F_97 ( V_120 ) ;
F_98 ( V_120 ) ;
F_99 ( V_120 ) ;
}
F_100 ( V_120 ) ;
F_101 ( V_120 ) ;
F_102 ( V_120 ) ;
F_103 ( V_120 , V_121 ) ;
F_104 ( V_120 , V_121 ) ;
F_105 ( V_120 , V_20 -> V_127 ) ;
F_93 ( V_20 ) ;
F_53 ( F_106 ( V_20 -> V_106 ) ,
V_20 -> V_2 -> V_115 + V_128 ) ;
F_53 ( F_107 ( V_20 -> V_114 ) ,
V_20 -> V_2 -> V_115 + V_129 ) ;
if ( V_20 -> V_126 != V_130 )
return;
for ( V_9 = 0 ; V_9 < V_20 -> V_62 ; V_9 ++ ) {
V_7 = & V_20 -> V_61 [ V_9 ] ;
F_64 ( V_7 ) ;
}
V_3 = F_2 ( V_20 -> V_2 -> V_115 + V_131 ) ;
F_108 ( V_3 , V_20 -> V_132 ) ;
F_53 ( V_3 , V_20 -> V_2 -> V_115 + V_131 ) ;
}
static void F_109 ( struct V_19 * V_20 )
{
T_1 V_133 , V_3 ;
if ( V_20 -> V_126 == V_130 ) {
V_3 = F_2 ( V_20 -> V_2 -> V_115 +
V_131 ) ;
F_110 ( V_3 , V_20 -> V_132 ) ;
F_53 ( V_3 , V_20 -> V_2 -> V_115 +
V_131 ) ;
}
V_133 = F_106 ( V_20 -> V_106 ) ;
F_53 ( V_133 , V_20 -> V_2 -> V_115 + V_128 ) ;
F_53 ( 0 , V_20 -> V_2 -> V_115 + V_129 ) ;
F_94 ( V_20 ) ;
}
static void F_111 ( struct V_19 * V_20 )
{
V_20 -> V_21 = V_20 -> V_2 -> V_134 +
F_112 ( ( V_20 -> V_114 -
V_135 ) ) ;
V_20 -> V_65 = V_20 -> V_21 + V_136 ;
}
static int F_113 ( struct V_30 * V_31 ,
enum V_137 V_127 )
{
int V_123 ;
switch ( V_127 ) {
case V_138 :
V_123 = 0x200 ;
break;
case V_139 :
V_123 = 0x800 ;
break;
case V_140 :
V_123 = 0x4000 ;
break;
case V_141 :
V_123 = 0x10000 ;
break;
case V_142 :
V_123 = 0x80000 ;
break;
default:
F_40 ( V_31 , L_13 , V_127 ) ;
return - V_46 ;
}
return V_123 ;
}
static void F_114 ( struct V_19 * V_20 )
{
F_109 ( V_20 ) ;
if ( V_20 -> V_143 ) {
F_115 ( V_20 -> V_2 -> V_77 , V_20 -> V_123 ,
V_20 -> V_143 , V_20 -> V_122 ) ;
V_20 -> V_143 = NULL ;
}
}
static void F_116 ( struct V_30 * V_31 )
{
F_114 ( & V_31 -> V_71 ) ;
F_114 ( & V_31 -> V_38 ) ;
}
static int F_117 ( struct V_30 * V_31 ,
struct V_19 * V_20 ,
enum V_137 V_127 )
{
V_20 -> V_2 = V_31 -> V_2 ;
V_20 -> V_127 = V_127 ;
V_20 -> V_114 = V_31 -> V_2 -> V_144 ++ ;
V_20 -> V_106 = F_118 ( V_20 -> V_126 , V_20 -> V_132 ) ;
V_20 -> V_123 = F_113 ( V_31 , V_127 ) ;
if ( V_20 -> V_123 <= 0 )
return V_20 -> V_123 ;
V_20 -> V_143 = F_119 ( V_31 -> V_77 , V_20 -> V_123 ,
& V_20 -> V_122 , V_145 ) ;
if ( ! V_20 -> V_143 ) {
F_40 ( V_31 , L_14 ) ;
return - V_78 ;
}
F_111 ( V_20 ) ;
F_95 ( V_20 ) ;
return 0 ;
}
static int F_120 ( struct V_30 * V_31 )
{
struct V_19 * V_71 = & V_31 -> V_71 ;
struct V_19 * V_38 = & V_31 -> V_38 ;
int V_67 ;
V_71 -> V_126 = V_130 ;
V_71 -> V_132 = V_146 + V_31 -> V_106 ;
V_67 = F_117 ( V_31 , V_71 ,
V_141 ) ;
if ( V_67 )
return V_67 ;
F_36 ( V_31 , L_15 ,
V_71 -> V_106 , V_71 -> V_114 , V_71 -> V_143 ) ;
V_38 -> V_126 = V_29 ;
V_38 -> V_132 = V_147 + V_31 -> V_106 ;
V_67 = F_117 ( V_31 , V_38 ,
V_141 ) ;
if ( V_67 ) {
F_114 ( V_71 ) ;
return V_67 ;
}
V_38 -> V_28 = F_121 ( V_71 -> V_114 ) ;
F_36 ( V_31 ,
L_16 ,
V_38 -> V_106 , V_38 -> V_114 , V_38 -> V_143 ) ;
V_31 -> V_69 = V_71 -> V_62 ;
return V_67 ;
}
static int F_122 ( struct V_1 * V_2 )
{
int V_67 , V_9 , V_148 ;
for ( V_9 = 0 ; V_9 < V_149 ; V_9 ++ ) {
V_67 = F_120 ( & V_2 -> V_31 [ V_9 ] ) ;
if ( V_67 ) {
for ( V_148 = 0 ; V_148 < V_9 ; V_148 ++ )
F_116 ( & V_2 -> V_31 [ V_148 ] ) ;
return V_67 ;
}
}
return V_67 ;
}
static void F_123 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_110 + V_150 ) ;
F_124 ( V_3 ) ;
F_125 ( V_3 ) ;
F_53 ( V_3 , V_2 -> V_110 + V_150 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_110 + V_150 ) ;
F_127 ( V_3 ) ;
F_53 ( V_3 , V_2 -> V_110 + V_150 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
F_53 ( V_151 ,
V_2 -> V_110 + V_152 ) ;
F_53 ( V_151 ,
V_2 -> V_110 + V_153 ) ;
F_53 ( V_151 ,
V_2 -> V_110 + V_154 ) ;
F_53 ( V_151 ,
V_2 -> V_110 + V_155 ) ;
F_53 ( V_151 ,
V_2 -> V_110 + V_156 ) ;
F_53 ( V_151 , V_2 -> V_110 + V_157 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
F_53 ( V_158 ,
V_2 -> V_110 + V_152 ) ;
F_53 ( V_158 ,
V_2 -> V_110 + V_153 ) ;
F_53 ( V_158 ,
V_2 -> V_110 + V_154 ) ;
F_53 ( V_158 ,
V_2 -> V_110 + V_155 ) ;
F_53 ( V_158 ,
V_2 -> V_110 + V_156 ) ;
F_53 ( V_158 ,
V_2 -> V_110 + V_157 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_53 ( V_159 ,
V_2 -> V_110 + V_160 ) ;
if ( F_1 ( V_2 ) )
F_53 ( F_131 ( 0x1D ) ,
V_2 -> V_110 + V_161 ) ;
else
F_132 ( V_2 -> V_77 , L_17 ) ;
F_123 ( V_2 ) ;
F_129 ( V_2 ) ;
V_3 = F_2 ( V_2 -> V_110 + V_162 ) ;
F_132 ( V_2 -> V_77 ,
L_18 ,
F_133 ( V_3 ) , F_134 ( V_3 ) ,
F_135 ( V_3 ) , V_149 ) ;
}
static int F_136 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_115 + V_163 ) &&
( ! F_2 ( V_2 -> V_115 + V_164 ) ) )
return 0 ;
F_53 ( 0x3 , V_2 -> V_115 + V_163 ) ;
F_53 ( 0x0 , V_2 -> V_115 + V_164 ) ;
F_53 ( 0x0 , V_2 -> V_115 + V_165 ) ;
F_2 ( V_2 -> V_115 + V_165 ) ;
F_137 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_115 + V_166 )
!= V_167 ) {
F_92 ( V_2 -> V_77 ,
L_19 ) ;
return - V_168 ;
}
F_53 ( V_169 ,
V_2 -> V_115 + V_170 ) ;
F_53 ( V_171 ,
V_2 -> V_115 + V_172 ) ;
F_53 ( V_173 ,
V_2 -> V_115 + V_174 ) ;
F_53 ( V_175 ,
V_2 -> V_115 + V_176 ) ;
return 0 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_67 ;
V_67 = F_136 ( V_2 ) ;
if ( V_67 )
return V_67 ;
F_53 ( 0x0 , V_2 -> V_110 + V_177 ) ;
F_2 ( V_2 -> V_110 + V_177 ) ;
F_137 ( 1000 , 1100 ) ;
if ( F_2 ( V_2 -> V_110 + V_178 )
!= V_179 ) {
F_92 ( V_2 -> V_77 ,
L_20 ) ;
return - V_168 ;
}
return 0 ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
int V_67 , V_9 , V_148 ;
V_67 = F_140 ( V_2 -> V_77 , V_2 -> V_180 , F_90 ,
0 , L_21 , V_2 ) ;
if ( V_67 ) {
F_92 ( V_2 -> V_77 ,
L_22 , V_2 -> V_180 ) ;
return V_67 ;
}
for ( V_9 = 0 ; V_9 < V_149 ; V_9 ++ ) {
V_31 = & V_2 -> V_31 [ V_9 ] ;
V_67 = F_140 ( V_31 -> V_77 , V_31 -> V_104 ,
F_86 ,
0 , V_31 -> V_76 , V_31 ) ;
if ( V_67 ) {
F_40 ( V_31 , L_23 ,
V_31 -> V_104 ) ;
F_141 ( V_2 -> V_77 , V_2 -> V_180 , V_2 ) ;
for ( V_148 = 0 ; V_148 < V_9 ; V_148 ++ ) {
V_31 = & V_2 -> V_31 [ V_9 ] ;
F_141 ( V_31 -> V_77 , V_31 -> V_104 , V_31 ) ;
}
return V_67 ;
}
}
return 0 ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
int V_9 ;
F_141 ( V_2 -> V_77 , V_2 -> V_180 , V_2 ) ;
for ( V_9 = 0 ; V_9 < V_149 ; V_9 ++ ) {
V_31 = & V_2 -> V_31 [ V_9 ] ;
F_141 ( V_31 -> V_77 , V_31 -> V_104 , V_31 ) ;
}
}
static void F_143 ( struct V_30 * V_31 ,
struct V_181 * V_182 )
{
F_144 ( V_182 -> V_183 ) ;
F_145 ( V_184 , V_182 -> V_183 ) ;
F_145 ( V_185 , V_182 -> V_183 ) ;
if ( ( V_31 -> V_106 == V_186 ) &&
F_1 ( V_31 -> V_2 ) ) {
F_145 ( V_187 , V_182 -> V_183 ) ;
F_145 ( V_188 , V_182 -> V_183 ) ;
} else if ( ( V_31 -> V_106 == V_189 ) &&
! F_1 ( V_31 -> V_2 ) ) {
F_145 ( V_188 , V_182 -> V_183 ) ;
}
V_182 -> V_77 = V_31 -> V_77 ;
V_182 -> V_190 = F_65 ;
V_182 -> V_191 = F_69 ;
V_182 -> V_192 = F_81 ;
V_182 -> V_193 = F_82 ;
V_182 -> V_194 = F_71 ;
V_182 -> V_195 = F_75 ;
if ( F_146 ( V_188 , V_182 -> V_183 ) ) {
V_182 -> V_196 = F_79 ;
V_182 -> V_197 = V_95 ;
V_182 -> V_198 = V_199 ;
}
if ( F_146 ( V_187 , V_182 -> V_183 ) ) {
V_182 -> V_200 = F_80 ;
V_182 -> V_201 = V_95 ;
V_182 -> V_202 = V_199 ;
}
}
static int F_147 ( struct V_1 * V_2 , int V_106 )
{
struct V_30 * V_31 = & V_2 -> V_31 [ V_106 ] ;
struct V_181 * V_182 = & V_2 -> V_182 [ V_106 ] ;
int V_67 ;
V_31 -> V_55 . V_203 = V_182 ;
F_148 ( & V_31 -> V_47 ) ;
F_41 ( & V_31 -> V_49 ) ;
F_41 ( & V_31 -> V_70 ) ;
F_41 ( & V_31 -> V_59 ) ;
F_149 ( & V_31 -> V_107 , F_84 ,
( unsigned long ) V_31 ) ;
V_31 -> V_68 = 0 ;
V_31 -> V_51 = NULL ;
F_150 ( & V_31 -> V_55 ) ;
F_143 ( V_31 , V_182 ) ;
F_41 ( & V_182 -> V_204 ) ;
F_51 ( & V_31 -> V_55 . V_205 , & V_182 -> V_204 ) ;
V_67 = F_151 ( V_182 ) ;
if ( V_67 ) {
F_40 ( V_31 , L_24 , V_67 ) ;
F_152 ( & V_31 -> V_107 ) ;
return V_67 ;
}
F_132 ( V_2 -> V_77 ,
L_25 , F_153 ( & V_31 -> V_55 ) ,
F_146 ( V_184 , V_182 -> V_183 ) ? L_26 : L_27 ,
F_146 ( V_185 , V_182 -> V_183 ) ? L_28 : L_27 ,
F_146 ( V_188 , V_182 -> V_183 ) ? L_29 : L_27 ,
F_146 ( V_187 , V_182 -> V_183 ) ? L_30 : L_27 ) ;
return 0 ;
}
static int F_154 ( struct V_1 * V_2 )
{
int V_67 , V_9 , V_148 ;
for ( V_9 = 0 ; V_9 < V_149 ; V_9 ++ ) {
V_67 = F_147 ( V_2 , V_9 ) ;
if ( V_67 ) {
for ( V_148 = 0 ; V_148 < V_9 ; V_148 ++ ) {
F_155 ( & V_2 -> V_182 [ V_148 ] ) ;
F_152 ( & V_2 -> V_31 [ V_148 ] . V_107 ) ;
}
return V_67 ;
}
}
return V_67 ;
}
static void F_156 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_149 ; V_9 ++ )
F_155 ( & V_2 -> V_182 [ V_9 ] ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
int V_9 ;
V_2 -> V_144 = V_135 ;
for ( V_9 = 0 ; V_9 < V_149 ; V_9 ++ ) {
V_31 = & V_2 -> V_31 [ V_9 ] ;
V_31 -> V_77 = V_2 -> V_77 ;
V_31 -> V_2 = V_2 ;
V_31 -> V_106 = V_9 ;
snprintf ( V_31 -> V_76 , sizeof( V_31 -> V_76 ) , L_31 , V_31 -> V_106 ) ;
}
}
static int F_158 ( struct V_206 * V_207 ,
struct V_1 * V_2 )
{
struct V_208 * V_209 ;
int V_105 , V_9 ;
V_209 = F_159 ( V_207 , V_210 , 0 ) ;
if ( ! V_209 ) {
F_92 ( & V_207 -> V_77 , L_32 ) ;
return - V_211 ;
}
V_2 -> V_110 = F_160 ( & V_207 -> V_77 , V_209 -> V_212 ,
F_161 ( V_209 ) ) ;
if ( ! V_2 -> V_110 ) {
F_92 ( & V_207 -> V_77 , L_33 ) ;
return - V_78 ;
}
V_209 = F_159 ( V_207 , V_210 , 1 ) ;
if ( ! V_209 ) {
F_92 ( & V_207 -> V_77 , L_34 ) ;
return - V_211 ;
}
V_2 -> V_115 = F_160 ( & V_207 -> V_77 , V_209 -> V_212 ,
F_161 ( V_209 ) ) ;
if ( ! V_2 -> V_115 ) {
F_92 ( & V_207 -> V_77 , L_35 ) ;
return - V_78 ;
}
V_209 = F_159 ( V_207 , V_210 , 2 ) ;
if ( ! V_209 ) {
F_92 ( & V_207 -> V_77 , L_36 ) ;
return - V_211 ;
}
V_2 -> V_134 = F_160 ( & V_207 -> V_77 , V_209 -> V_212 ,
F_161 ( V_209 ) ) ;
if ( ! V_2 -> V_134 ) {
F_92 ( & V_207 -> V_77 , L_37 ) ;
return - V_78 ;
}
V_209 = F_159 ( V_207 , V_210 , 3 ) ;
if ( ! V_209 ) {
F_92 ( & V_207 -> V_77 , L_38 ) ;
return - V_211 ;
}
V_2 -> V_4 = F_160 ( & V_207 -> V_77 , V_209 -> V_212 ,
F_161 ( V_209 ) ) ;
if ( ! V_2 -> V_4 ) {
F_92 ( & V_207 -> V_77 , L_39 ) ;
return - V_78 ;
}
V_105 = F_162 ( V_207 , 0 ) ;
if ( V_105 <= 0 ) {
F_92 ( & V_207 -> V_77 , L_40 ) ;
return - V_211 ;
}
V_2 -> V_180 = V_105 ;
for ( V_9 = 1 ; V_9 <= V_149 ; V_9 ++ ) {
V_105 = F_162 ( V_207 , V_9 ) ;
if ( V_105 <= 0 ) {
F_92 ( & V_207 -> V_77 , L_41 ) ;
return - V_211 ;
}
V_2 -> V_31 [ V_9 - 1 ] . V_104 = V_105 ;
}
return 0 ;
}
static int F_163 ( struct V_206 * V_207 )
{
struct V_1 * V_2 ;
int V_67 , V_9 ;
V_2 = F_164 ( & V_207 -> V_77 , sizeof( * V_2 ) , V_145 ) ;
if ( ! V_2 )
return - V_78 ;
V_2 -> V_77 = & V_207 -> V_77 ;
F_165 ( V_207 , V_2 ) ;
V_67 = F_158 ( V_207 , V_2 ) ;
if ( V_67 )
return V_67 ;
V_2 -> V_213 = F_166 ( & V_207 -> V_77 , NULL ) ;
if ( F_167 ( V_2 -> V_213 ) ) {
F_92 ( & V_207 -> V_77 , L_42 ) ;
return F_168 ( V_2 -> V_213 ) ;
}
V_67 = F_169 ( V_2 -> V_213 ) ;
if ( V_67 ) {
F_92 ( & V_207 -> V_77 , L_43 , V_67 ) ;
return V_67 ;
}
V_67 = F_138 ( V_2 ) ;
if ( V_67 )
goto V_214;
V_67 = F_170 ( & V_207 -> V_77 , F_171 ( 42 ) ) ;
if ( V_67 ) {
F_92 ( & V_207 -> V_77 , L_44 ) ;
goto V_215;
}
F_157 ( V_2 ) ;
V_67 = F_122 ( V_2 ) ;
if ( V_67 )
goto V_214;
V_67 = F_139 ( V_2 ) ;
if ( V_67 )
goto V_216;
F_130 ( V_2 ) ;
V_67 = F_154 ( V_2 ) ;
if ( V_67 )
goto V_217;
return 0 ;
V_217:
F_142 ( V_2 ) ;
V_216:
for ( V_9 = 0 ; V_9 < V_149 ; V_9 ++ )
F_116 ( & V_2 -> V_31 [ V_9 ] ) ;
V_215:
V_214:
F_172 ( V_2 -> V_213 ) ;
return V_67 ;
}
static int F_173 ( struct V_206 * V_207 )
{
struct V_1 * V_2 = F_174 ( V_207 ) ;
struct V_30 * V_31 ;
int V_9 ;
F_156 ( V_2 ) ;
F_128 ( V_2 ) ;
F_126 ( V_2 ) ;
F_142 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_149 ; V_9 ++ ) {
V_31 = & V_2 -> V_31 [ V_9 ] ;
F_152 ( & V_31 -> V_107 ) ;
F_116 ( V_31 ) ;
}
F_172 ( V_2 -> V_213 ) ;
return 0 ;
}
