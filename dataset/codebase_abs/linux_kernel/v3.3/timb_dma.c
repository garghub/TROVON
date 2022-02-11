static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 -> V_1 ;
}
static struct V_1 * F_2 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_5 -> V_5 ;
}
static struct V_6 * F_3 ( struct V_7 * V_8 )
{
int V_9 = V_8 -> V_3 . V_10 ;
return (struct V_6 * ) ( ( V_11 * ) V_8 -
V_9 * sizeof( struct V_7 ) - sizeof( struct V_6 ) ) ;
}
static void F_4 ( struct V_7 * V_8 )
{
int V_9 = V_8 -> V_3 . V_10 ;
struct V_6 * V_12 = F_3 ( V_8 ) ;
T_1 V_13 ;
V_13 = F_5 ( V_12 -> V_14 + V_15 ) ;
V_13 |= 1 << V_9 ;
F_6 ( F_1 ( & V_8 -> V_3 ) , L_1 , V_9 ,
V_13 ) ;
F_7 ( V_13 , V_12 -> V_14 + V_15 ) ;
}
static bool F_8 ( struct V_7 * V_8 )
{
int V_9 = V_8 -> V_3 . V_10 ;
struct V_6 * V_12 = (struct V_6 * ) ( ( V_11 * ) V_8 -
V_9 * sizeof( struct V_7 ) - sizeof( struct V_6 ) ) ;
T_1 V_16 ;
bool V_17 = false ;
F_6 ( F_1 ( & V_8 -> V_3 ) , L_2 , V_9 , V_12 ) ;
V_16 = F_5 ( V_12 -> V_14 + V_18 ) & ( 1 << V_9 ) ;
if ( V_16 ) {
F_7 ( V_16 , V_12 -> V_14 + V_18 ) ;
V_17 = true ;
}
return V_17 ;
}
static void F_9 ( struct V_7 * V_8 , const V_11 * V_19 ,
bool V_20 )
{
T_2 V_21 ;
int V_22 ;
V_21 = ( V_19 [ 7 ] << 24 ) | ( V_19 [ 6 ] << 16 ) | ( V_19 [ 5 ] << 8 ) |
V_19 [ 4 ] ;
V_22 = ( V_19 [ 3 ] << 8 ) | V_19 [ 2 ] ;
if ( V_20 )
F_10 ( F_1 ( & V_8 -> V_3 ) , V_21 , V_22 ,
V_23 ) ;
else
F_11 ( F_1 ( & V_8 -> V_3 ) , V_21 , V_22 ,
V_23 ) ;
}
static void F_12 ( struct V_24 * V_25 , bool V_20 )
{
struct V_7 * V_8 = F_13 ( V_25 -> V_26 . V_3 ,
struct V_7 , V_3 ) ;
V_11 * V_27 ;
for ( V_27 = V_25 -> V_28 ; ; V_27 += V_29 ) {
F_9 ( V_8 , V_27 , V_20 ) ;
if ( V_27 [ 0 ] & 0x02 )
break;
}
}
static int F_14 ( struct V_7 * V_8 , V_11 * V_19 ,
struct V_30 * V_31 , bool V_32 )
{
if ( F_15 ( V_31 ) > V_33 ) {
F_16 ( F_1 ( & V_8 -> V_3 ) , L_3 ) ;
return - V_34 ;
}
if ( F_15 ( V_31 ) % sizeof( T_1 ) ) {
F_16 ( F_1 ( & V_8 -> V_3 ) , L_4 ,
F_15 ( V_31 ) ) ;
return - V_34 ;
}
F_6 ( F_1 ( & V_8 -> V_3 ) , L_5 ,
V_19 , ( unsigned long long ) F_17 ( V_31 ) ) ;
V_19 [ 7 ] = ( F_17 ( V_31 ) >> 24 ) & 0xff ;
V_19 [ 6 ] = ( F_17 ( V_31 ) >> 16 ) & 0xff ;
V_19 [ 5 ] = ( F_17 ( V_31 ) >> 8 ) & 0xff ;
V_19 [ 4 ] = ( F_17 ( V_31 ) >> 0 ) & 0xff ;
V_19 [ 3 ] = ( F_15 ( V_31 ) >> 8 ) & 0xff ;
V_19 [ 2 ] = ( F_15 ( V_31 ) >> 0 ) & 0xff ;
V_19 [ 1 ] = 0x00 ;
V_19 [ 0 ] = 0x21 | ( V_32 ? 0x02 : 0 ) ;
return 0 ;
}
static void F_18 ( struct V_7 * V_8 )
{
struct V_24 * V_25 ;
if ( V_8 -> V_35 ) {
F_16 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ) ;
return;
}
V_25 = F_19 ( V_8 -> V_36 . V_37 , struct V_24 ,
V_38 ) ;
F_6 ( F_1 ( & V_8 -> V_3 ) ,
L_7 ,
V_8 , V_8 -> V_3 . V_10 , V_8 -> V_14 ) ;
if ( V_8 -> V_39 == V_40 ) {
F_7 ( 0 , V_8 -> V_14 + V_41 ) ;
F_7 ( V_25 -> V_26 . V_42 , V_8 -> V_14 +
V_43 ) ;
F_7 ( V_8 -> V_44 , V_8 -> V_14 +
V_45 ) ;
F_7 ( V_46 , V_8 -> V_14 + V_47 ) ;
} else {
F_7 ( 0 , V_8 -> V_14 + V_48 ) ;
F_7 ( V_25 -> V_26 . V_42 , V_8 -> V_14 +
V_49 ) ;
}
V_8 -> V_35 = true ;
if ( V_25 -> V_50 )
F_4 ( V_8 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
T_3 V_51 ;
void * V_52 ;
struct V_53 * V_26 ;
struct V_24 * V_25 ;
if ( F_21 ( & V_8 -> V_36 ) )
return;
V_25 = F_19 ( V_8 -> V_36 . V_37 , struct V_24 ,
V_38 ) ;
V_26 = & V_25 -> V_26 ;
F_6 ( F_1 ( & V_8 -> V_3 ) , L_8 ,
V_26 -> V_54 ) ;
if ( V_8 -> V_39 == V_40 )
F_7 ( 0 , V_8 -> V_14 + V_47 ) ;
V_8 -> V_55 = V_26 -> V_54 ;
V_8 -> V_35 = false ;
V_51 = V_26 -> V_51 ;
V_52 = V_26 -> V_56 ;
F_22 ( & V_25 -> V_38 , & V_8 -> V_57 ) ;
if ( ! ( V_26 -> V_58 & V_59 ) )
F_12 ( V_25 ,
V_26 -> V_58 & V_60 ) ;
if ( V_51 )
V_51 ( V_52 ) ;
}
static T_1 F_23 ( struct V_6 * V_12 )
{
int V_61 ;
T_1 V_62 = 0 ;
for ( V_61 = 0 ; V_61 < V_12 -> V_63 . V_64 ; V_61 ++ ) {
struct V_7 * V_8 = V_12 -> V_65 + V_61 ;
if ( V_8 -> V_35 ) {
struct V_24 * V_25 =
F_19 ( V_8 -> V_36 . V_37 ,
struct V_24 , V_38 ) ;
if ( V_25 -> V_50 )
V_62 |= 1 << V_61 ;
}
}
return V_62 ;
}
static void F_24 ( struct V_7 * V_8 )
{
struct V_24 * V_25 ;
F_25 ( F_21 ( & V_8 -> V_66 ) ) ;
F_25 ( V_8 -> V_35 ) ;
V_25 = F_19 ( V_8 -> V_66 . V_37 , struct V_24 ,
V_38 ) ;
F_6 ( F_1 ( & V_8 -> V_3 ) , L_9 ,
V_67 , V_25 -> V_26 . V_54 ) ;
F_22 ( & V_25 -> V_38 , & V_8 -> V_36 ) ;
F_18 ( V_8 ) ;
}
static T_4 F_26 ( struct V_53 * V_26 )
{
struct V_24 * V_25 = F_13 ( V_26 , struct V_24 ,
V_26 ) ;
struct V_7 * V_8 = F_13 ( V_26 -> V_3 ,
struct V_7 , V_3 ) ;
T_4 V_54 ;
F_27 ( & V_8 -> V_68 ) ;
V_54 = V_26 -> V_3 -> V_54 ;
if ( ++ V_54 < 0 )
V_54 = 1 ;
V_26 -> V_3 -> V_54 = V_54 ;
V_26 -> V_54 = V_54 ;
if ( F_21 ( & V_8 -> V_36 ) ) {
F_6 ( F_1 ( V_26 -> V_3 ) , L_9 , V_67 ,
V_26 -> V_54 ) ;
F_28 ( & V_25 -> V_38 , & V_8 -> V_36 ) ;
F_18 ( V_8 ) ;
} else {
F_6 ( F_1 ( V_26 -> V_3 ) , L_10 ,
V_26 -> V_54 ) ;
F_28 ( & V_25 -> V_38 , & V_8 -> V_66 ) ;
}
F_29 ( & V_8 -> V_68 ) ;
return V_54 ;
}
static struct V_24 * F_30 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
struct V_24 * V_25 ;
int V_69 ;
V_25 = F_31 ( sizeof( struct V_24 ) , V_70 ) ;
if ( ! V_25 ) {
F_16 ( F_1 ( V_3 ) , L_11 ) ;
goto V_71;
}
V_25 -> V_72 = V_8 -> V_73 * V_29 ;
V_25 -> V_28 = F_31 ( V_25 -> V_72 , V_70 ) ;
if ( ! V_25 -> V_28 ) {
F_16 ( F_1 ( V_3 ) , L_11 ) ;
goto V_69;
}
F_32 ( & V_25 -> V_26 , V_3 ) ;
V_25 -> V_26 . V_74 = F_26 ;
V_25 -> V_26 . V_58 = V_75 ;
V_25 -> V_26 . V_42 = F_33 ( F_2 ( V_3 ) ,
V_25 -> V_28 , V_25 -> V_72 , V_23 ) ;
V_69 = F_34 ( F_2 ( V_3 ) , V_25 -> V_26 . V_42 ) ;
if ( V_69 ) {
F_16 ( F_1 ( V_3 ) , L_12 , V_69 ) ;
goto V_69;
}
return V_25 ;
V_69:
F_35 ( V_25 -> V_28 ) ;
F_35 ( V_25 ) ;
V_71:
return NULL ;
}
static void F_36 ( struct V_24 * V_25 )
{
F_6 ( F_1 ( V_25 -> V_26 . V_3 ) , L_13 , V_25 ) ;
F_10 ( F_2 ( V_25 -> V_26 . V_3 ) , V_25 -> V_26 . V_42 ,
V_25 -> V_72 , V_23 ) ;
F_35 ( V_25 -> V_28 ) ;
F_35 ( V_25 ) ;
}
static void F_37 ( struct V_7 * V_8 ,
struct V_24 * V_25 )
{
F_6 ( F_1 ( & V_8 -> V_3 ) , L_14 , V_25 ) ;
F_27 ( & V_8 -> V_68 ) ;
F_38 ( & V_25 -> V_38 , & V_8 -> V_57 ) ;
F_29 ( & V_8 -> V_68 ) ;
}
static struct V_24 * F_39 ( struct V_7 * V_8 )
{
struct V_24 * V_25 , * V_76 ;
struct V_24 * V_62 = NULL ;
F_27 ( & V_8 -> V_68 ) ;
F_40 (td_desc, _td_desc, &td_chan->free_list,
desc_node) {
if ( F_41 ( & V_25 -> V_26 ) ) {
F_42 ( & V_25 -> V_38 ) ;
V_62 = V_25 ;
break;
}
F_6 ( F_1 ( & V_8 -> V_3 ) , L_15 ,
V_25 ) ;
}
F_29 ( & V_8 -> V_68 ) ;
return V_62 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
int V_61 ;
F_6 ( F_1 ( V_3 ) , L_16 , V_67 ) ;
F_25 ( ! F_21 ( & V_8 -> V_57 ) ) ;
for ( V_61 = 0 ; V_61 < V_8 -> V_27 ; V_61 ++ ) {
struct V_24 * V_25 = F_30 ( V_8 ) ;
if ( ! V_25 ) {
if ( V_61 )
break;
else {
F_16 ( F_1 ( V_3 ) ,
L_17 ) ;
return - V_77 ;
}
}
F_37 ( V_8 , V_25 ) ;
}
F_27 ( & V_8 -> V_68 ) ;
V_8 -> V_55 = 1 ;
V_3 -> V_54 = 1 ;
F_29 ( & V_8 -> V_68 ) ;
return 0 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
struct V_24 * V_25 , * V_76 ;
F_45 ( V_78 ) ;
F_6 ( F_1 ( V_3 ) , L_18 , V_67 ) ;
F_25 ( ! F_21 ( & V_8 -> V_36 ) ) ;
F_25 ( ! F_21 ( & V_8 -> V_66 ) ) ;
F_27 ( & V_8 -> V_68 ) ;
F_46 ( & V_8 -> V_57 , & V_78 ) ;
F_29 ( & V_8 -> V_68 ) ;
F_40 (td_desc, _td_desc, &list, desc_node) {
F_6 ( F_1 ( V_3 ) , L_19 , V_67 ,
V_25 ) ;
F_36 ( V_25 ) ;
}
}
static enum V_79 F_47 ( struct V_2 * V_3 , T_4 V_54 ,
struct V_80 * V_81 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
T_4 V_82 ;
T_4 V_83 ;
int V_62 ;
F_6 ( F_1 ( V_3 ) , L_18 , V_67 ) ;
V_83 = V_8 -> V_55 ;
V_82 = V_3 -> V_54 ;
V_62 = F_48 ( V_54 , V_83 , V_82 ) ;
F_49 ( V_81 , V_83 , V_82 , 0 ) ;
F_6 ( F_1 ( V_3 ) ,
L_20 ,
V_67 , V_62 , V_83 , V_82 ) ;
return V_62 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
F_6 ( F_1 ( V_3 ) , L_18 , V_67 ) ;
F_27 ( & V_8 -> V_68 ) ;
if ( ! F_21 ( & V_8 -> V_36 ) )
if ( F_8 ( V_8 ) )
F_20 ( V_8 ) ;
if ( F_21 ( & V_8 -> V_36 ) && ! F_21 ( & V_8 -> V_66 ) )
F_24 ( V_8 ) ;
F_29 ( & V_8 -> V_68 ) ;
}
static struct V_53 * F_51 ( struct V_2 * V_3 ,
struct V_30 * V_84 , unsigned int V_85 ,
enum V_86 V_39 , unsigned long V_58 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
struct V_24 * V_25 ;
struct V_30 * V_31 ;
unsigned int V_61 ;
unsigned int V_87 = 0 ;
if ( ! V_84 || ! V_85 ) {
F_16 ( F_1 ( V_3 ) , L_21 , V_67 ) ;
return NULL ;
}
if ( V_8 -> V_39 != V_39 ) {
F_16 ( F_1 ( V_3 ) ,
L_22 ) ;
return NULL ;
}
V_25 = F_39 ( V_8 ) ;
if ( ! V_25 ) {
F_16 ( F_1 ( V_3 ) , L_23 ) ;
return NULL ;
}
V_25 -> V_50 = ( V_58 & V_88 ) != 0 ;
F_52 (sgl, sg, sg_len, i) {
int V_69 ;
if ( V_87 > V_25 -> V_72 ) {
F_16 ( F_1 ( V_3 ) , L_24 ) ;
return NULL ;
}
V_69 = F_14 ( V_8 , V_25 -> V_28 + V_87 , V_31 ,
V_61 == ( V_85 - 1 ) ) ;
if ( V_69 ) {
F_16 ( F_1 ( V_3 ) , L_25 ,
V_69 ) ;
F_37 ( V_8 , V_25 ) ;
return NULL ;
}
V_87 += V_29 ;
}
F_53 ( F_2 ( V_3 ) , V_25 -> V_26 . V_42 ,
V_25 -> V_72 , V_89 ) ;
return & V_25 -> V_26 ;
}
static int F_54 ( struct V_2 * V_3 , enum V_90 V_91 ,
unsigned long V_92 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
struct V_24 * V_25 , * V_76 ;
F_6 ( F_1 ( V_3 ) , L_18 , V_67 ) ;
if ( V_91 != V_93 )
return - V_94 ;
F_27 ( & V_8 -> V_68 ) ;
F_40 (td_desc, _td_desc, &td_chan->queue,
desc_node)
F_22 ( & V_25 -> V_38 , & V_8 -> V_57 ) ;
F_20 ( V_8 ) ;
F_29 ( & V_8 -> V_68 ) ;
return 0 ;
}
static void F_55 ( unsigned long V_95 )
{
struct V_6 * V_12 = (struct V_6 * ) V_95 ;
T_1 V_16 ;
T_1 V_96 ;
T_1 V_13 ;
int V_61 ;
V_16 = F_5 ( V_12 -> V_14 + V_18 ) ;
V_96 = V_16 & F_23 ( V_12 ) ;
F_7 ( V_96 , V_12 -> V_14 + V_18 ) ;
for ( V_61 = 0 ; V_61 < V_12 -> V_63 . V_64 ; V_61 ++ )
if ( V_96 & ( 1 << V_61 ) ) {
struct V_7 * V_8 = V_12 -> V_65 + V_61 ;
F_56 ( & V_8 -> V_68 ) ;
F_20 ( V_8 ) ;
if ( ! F_21 ( & V_8 -> V_66 ) )
F_24 ( V_8 ) ;
F_57 ( & V_8 -> V_68 ) ;
}
V_13 = F_23 ( V_12 ) ;
F_7 ( V_13 , V_12 -> V_14 + V_15 ) ;
}
static T_5 F_58 ( int V_97 , void * V_98 )
{
struct V_6 * V_12 = V_98 ;
T_1 V_96 = F_5 ( V_12 -> V_14 + V_99 ) ;
if ( V_96 ) {
F_7 ( 0 , V_12 -> V_14 + V_15 ) ;
F_59 ( & V_12 -> V_100 ) ;
return V_101 ;
} else
return V_102 ;
}
static int T_6 F_60 ( struct V_103 * V_104 )
{
struct V_105 * V_106 = V_104 -> V_4 . V_107 ;
struct V_6 * V_12 ;
struct V_108 * V_109 ;
int V_97 ;
int V_69 ;
int V_61 ;
if ( ! V_106 ) {
F_16 ( & V_104 -> V_4 , L_26 ) ;
return - V_34 ;
}
V_109 = F_61 ( V_104 , V_110 , 0 ) ;
if ( ! V_109 )
return - V_34 ;
V_97 = F_62 ( V_104 , 0 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( ! F_63 ( V_109 -> V_111 , F_64 ( V_109 ) ,
V_112 ) )
return - V_113 ;
V_12 = F_31 ( sizeof( struct V_6 ) +
sizeof( struct V_7 ) * V_106 -> V_114 , V_70 ) ;
if ( ! V_12 ) {
V_69 = - V_77 ;
goto V_115;
}
F_6 ( & V_104 -> V_4 , L_27 , V_12 ) ;
V_12 -> V_14 = F_65 ( V_109 -> V_111 , F_64 ( V_109 ) ) ;
if ( ! V_12 -> V_14 ) {
F_16 ( & V_104 -> V_4 , L_28 ) ;
V_69 = - V_77 ;
goto V_116;
}
F_7 ( V_117 , V_12 -> V_14 + V_118 ) ;
F_7 ( 0x0 , V_12 -> V_14 + V_15 ) ;
F_7 ( 0xFFFFFFFF , V_12 -> V_14 + V_18 ) ;
F_66 ( & V_12 -> V_100 , F_55 , ( unsigned long ) V_12 ) ;
V_69 = F_67 ( V_97 , F_58 , V_119 , V_112 , V_12 ) ;
if ( V_69 ) {
F_16 ( & V_104 -> V_4 , L_29 ) ;
goto V_120;
}
V_12 -> V_63 . V_121 = F_43 ;
V_12 -> V_63 . V_122 = F_44 ;
V_12 -> V_63 . V_123 = F_47 ;
V_12 -> V_63 . V_124 = F_50 ;
F_68 ( V_125 , V_12 -> V_63 . V_126 ) ;
F_68 ( V_127 , V_12 -> V_63 . V_126 ) ;
V_12 -> V_63 . V_128 = F_51 ;
V_12 -> V_63 . V_129 = F_54 ;
V_12 -> V_63 . V_4 = & V_104 -> V_4 ;
F_69 ( & V_12 -> V_63 . V_65 ) ;
for ( V_61 = 0 ; V_61 < V_106 -> V_114 ; V_61 ++ ) {
struct V_7 * V_8 = & V_12 -> V_65 [ V_61 ] ;
struct V_130 * V_131 =
V_106 -> V_65 + V_61 ;
if ( ( V_61 % 2 ) == V_131 -> V_132 ) {
F_16 ( & V_104 -> V_4 , L_30 ) ;
V_69 = - V_34 ;
goto V_133;
}
V_8 -> V_3 . V_1 = & V_12 -> V_63 ;
V_8 -> V_3 . V_54 = 1 ;
F_70 ( & V_8 -> V_68 ) ;
F_69 ( & V_8 -> V_36 ) ;
F_69 ( & V_8 -> V_66 ) ;
F_69 ( & V_8 -> V_57 ) ;
V_8 -> V_27 = V_131 -> V_134 ;
V_8 -> V_73 = V_131 -> V_135 ;
V_8 -> V_44 = V_131 -> V_44 ;
V_8 -> V_39 = V_131 -> V_132 ? V_40 :
V_89 ;
V_8 -> V_14 = V_12 -> V_14 +
( V_61 / 2 ) * V_136 +
( V_131 -> V_132 ? 0 : V_137 ) ;
F_6 ( & V_104 -> V_4 , L_31 ,
V_61 , V_8 -> V_14 ) ;
F_28 ( & V_8 -> V_3 . V_138 , & V_12 -> V_63 . V_65 ) ;
}
V_69 = F_71 ( & V_12 -> V_63 ) ;
if ( V_69 ) {
F_16 ( & V_104 -> V_4 , L_32 ) ;
goto V_133;
}
F_72 ( V_104 , V_12 ) ;
F_6 ( & V_104 -> V_4 , L_33 , V_69 ) ;
return V_69 ;
V_133:
F_73 ( V_97 , V_12 ) ;
V_120:
F_74 ( & V_12 -> V_100 ) ;
F_75 ( V_12 -> V_14 ) ;
V_116:
F_35 ( V_12 ) ;
V_115:
F_76 ( V_109 -> V_111 , F_64 ( V_109 ) ) ;
return V_69 ;
}
static int T_7 F_77 ( struct V_103 * V_104 )
{
struct V_6 * V_12 = F_78 ( V_104 ) ;
struct V_108 * V_109 = F_61 ( V_104 , V_110 , 0 ) ;
int V_97 = F_62 ( V_104 , 0 ) ;
F_79 ( & V_12 -> V_63 ) ;
F_73 ( V_97 , V_12 ) ;
F_74 ( & V_12 -> V_100 ) ;
F_75 ( V_12 -> V_14 ) ;
F_35 ( V_12 ) ;
F_76 ( V_109 -> V_111 , F_64 ( V_109 ) ) ;
F_72 ( V_104 , NULL ) ;
F_6 ( & V_104 -> V_4 , L_34 ) ;
return 0 ;
}
