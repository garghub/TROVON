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
V_8 -> V_23 ) ;
else
F_11 ( F_1 ( & V_8 -> V_3 ) , V_21 , V_22 ,
V_8 -> V_23 ) ;
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
if ( V_8 -> V_23 == V_39 ) {
F_7 ( 0 , V_8 -> V_14 + V_40 ) ;
F_7 ( V_25 -> V_26 . V_41 , V_8 -> V_14 +
V_42 ) ;
F_7 ( V_8 -> V_43 , V_8 -> V_14 +
V_44 ) ;
F_7 ( V_45 , V_8 -> V_14 + V_46 ) ;
} else {
F_7 ( 0 , V_8 -> V_14 + V_47 ) ;
F_7 ( V_25 -> V_26 . V_41 , V_8 -> V_14 +
V_48 ) ;
}
V_8 -> V_35 = true ;
if ( V_25 -> V_49 )
F_4 ( V_8 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
T_3 V_50 ;
void * V_51 ;
struct V_52 * V_26 ;
struct V_24 * V_25 ;
if ( F_21 ( & V_8 -> V_36 ) )
return;
V_25 = F_19 ( V_8 -> V_36 . V_37 , struct V_24 ,
V_38 ) ;
V_26 = & V_25 -> V_26 ;
F_6 ( F_1 ( & V_8 -> V_3 ) , L_8 ,
V_26 -> V_53 ) ;
if ( V_8 -> V_23 == V_39 )
F_7 ( 0 , V_8 -> V_14 + V_46 ) ;
V_8 -> V_54 = V_26 -> V_53 ;
V_8 -> V_35 = false ;
V_50 = V_26 -> V_50 ;
V_51 = V_26 -> V_55 ;
F_22 ( & V_25 -> V_38 , & V_8 -> V_56 ) ;
if ( ! ( V_26 -> V_57 & V_58 ) )
F_12 ( V_25 ,
V_26 -> V_57 & V_59 ) ;
if ( V_50 )
V_50 ( V_51 ) ;
}
static T_1 F_23 ( struct V_6 * V_12 )
{
int V_60 ;
T_1 V_61 = 0 ;
for ( V_60 = 0 ; V_60 < V_12 -> V_62 . V_63 ; V_60 ++ ) {
struct V_7 * V_8 = V_12 -> V_64 + V_60 ;
if ( V_8 -> V_35 ) {
struct V_24 * V_25 =
F_19 ( V_8 -> V_36 . V_37 ,
struct V_24 , V_38 ) ;
if ( V_25 -> V_49 )
V_61 |= 1 << V_60 ;
}
}
return V_61 ;
}
static void F_24 ( struct V_7 * V_8 )
{
struct V_24 * V_25 ;
F_25 ( F_21 ( & V_8 -> V_65 ) ) ;
F_25 ( V_8 -> V_35 ) ;
V_25 = F_19 ( V_8 -> V_65 . V_37 , struct V_24 ,
V_38 ) ;
F_6 ( F_1 ( & V_8 -> V_3 ) , L_9 ,
V_66 , V_25 -> V_26 . V_53 ) ;
F_22 ( & V_25 -> V_38 , & V_8 -> V_36 ) ;
F_18 ( V_8 ) ;
}
static T_4 F_26 ( struct V_52 * V_26 )
{
struct V_24 * V_25 = F_13 ( V_26 , struct V_24 ,
V_26 ) ;
struct V_7 * V_8 = F_13 ( V_26 -> V_3 ,
struct V_7 , V_3 ) ;
T_4 V_53 ;
F_27 ( & V_8 -> V_67 ) ;
V_53 = V_26 -> V_3 -> V_53 ;
if ( ++ V_53 < 0 )
V_53 = 1 ;
V_26 -> V_3 -> V_53 = V_53 ;
V_26 -> V_53 = V_53 ;
if ( F_21 ( & V_8 -> V_36 ) ) {
F_6 ( F_1 ( V_26 -> V_3 ) , L_9 , V_66 ,
V_26 -> V_53 ) ;
F_28 ( & V_25 -> V_38 , & V_8 -> V_36 ) ;
F_18 ( V_8 ) ;
} else {
F_6 ( F_1 ( V_26 -> V_3 ) , L_10 ,
V_26 -> V_53 ) ;
F_28 ( & V_25 -> V_38 , & V_8 -> V_65 ) ;
}
F_29 ( & V_8 -> V_67 ) ;
return V_53 ;
}
static struct V_24 * F_30 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
struct V_24 * V_25 ;
int V_68 ;
V_25 = F_31 ( sizeof( struct V_24 ) , V_69 ) ;
if ( ! V_25 ) {
F_16 ( F_1 ( V_3 ) , L_11 ) ;
goto V_70;
}
V_25 -> V_71 = V_8 -> V_72 * V_29 ;
V_25 -> V_28 = F_31 ( V_25 -> V_71 , V_69 ) ;
if ( ! V_25 -> V_28 ) {
F_16 ( F_1 ( V_3 ) , L_11 ) ;
goto V_68;
}
F_32 ( & V_25 -> V_26 , V_3 ) ;
V_25 -> V_26 . V_73 = F_26 ;
V_25 -> V_26 . V_57 = V_74 ;
V_25 -> V_26 . V_41 = F_33 ( F_2 ( V_3 ) ,
V_25 -> V_28 , V_25 -> V_71 , V_75 ) ;
V_68 = F_34 ( F_2 ( V_3 ) , V_25 -> V_26 . V_41 ) ;
if ( V_68 ) {
F_16 ( F_1 ( V_3 ) , L_12 , V_68 ) ;
goto V_68;
}
return V_25 ;
V_68:
F_35 ( V_25 -> V_28 ) ;
F_35 ( V_25 ) ;
V_70:
return NULL ;
}
static void F_36 ( struct V_24 * V_25 )
{
F_6 ( F_1 ( V_25 -> V_26 . V_3 ) , L_13 , V_25 ) ;
F_10 ( F_2 ( V_25 -> V_26 . V_3 ) , V_25 -> V_26 . V_41 ,
V_25 -> V_71 , V_75 ) ;
F_35 ( V_25 -> V_28 ) ;
F_35 ( V_25 ) ;
}
static void F_37 ( struct V_7 * V_8 ,
struct V_24 * V_25 )
{
F_6 ( F_1 ( & V_8 -> V_3 ) , L_14 , V_25 ) ;
F_27 ( & V_8 -> V_67 ) ;
F_38 ( & V_25 -> V_38 , & V_8 -> V_56 ) ;
F_29 ( & V_8 -> V_67 ) ;
}
static struct V_24 * F_39 ( struct V_7 * V_8 )
{
struct V_24 * V_25 , * V_76 ;
struct V_24 * V_61 = NULL ;
F_27 ( & V_8 -> V_67 ) ;
F_40 (td_desc, _td_desc, &td_chan->free_list,
desc_node) {
if ( F_41 ( & V_25 -> V_26 ) ) {
F_42 ( & V_25 -> V_38 ) ;
V_61 = V_25 ;
break;
}
F_6 ( F_1 ( & V_8 -> V_3 ) , L_15 ,
V_25 ) ;
}
F_29 ( & V_8 -> V_67 ) ;
return V_61 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
int V_60 ;
F_6 ( F_1 ( V_3 ) , L_16 , V_66 ) ;
F_25 ( ! F_21 ( & V_8 -> V_56 ) ) ;
for ( V_60 = 0 ; V_60 < V_8 -> V_27 ; V_60 ++ ) {
struct V_24 * V_25 = F_30 ( V_8 ) ;
if ( ! V_25 ) {
if ( V_60 )
break;
else {
F_16 ( F_1 ( V_3 ) ,
L_17 ) ;
return - V_77 ;
}
}
F_37 ( V_8 , V_25 ) ;
}
F_27 ( & V_8 -> V_67 ) ;
V_8 -> V_54 = 1 ;
V_3 -> V_53 = 1 ;
F_29 ( & V_8 -> V_67 ) ;
return 0 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
struct V_24 * V_25 , * V_76 ;
F_45 ( V_78 ) ;
F_6 ( F_1 ( V_3 ) , L_18 , V_66 ) ;
F_25 ( ! F_21 ( & V_8 -> V_36 ) ) ;
F_25 ( ! F_21 ( & V_8 -> V_65 ) ) ;
F_27 ( & V_8 -> V_67 ) ;
F_46 ( & V_8 -> V_56 , & V_78 ) ;
F_29 ( & V_8 -> V_67 ) ;
F_40 (td_desc, _td_desc, &list, desc_node) {
F_6 ( F_1 ( V_3 ) , L_19 , V_66 ,
V_25 ) ;
F_36 ( V_25 ) ;
}
}
static enum V_79 F_47 ( struct V_2 * V_3 , T_4 V_53 ,
struct V_80 * V_81 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
T_4 V_82 ;
T_4 V_83 ;
int V_61 ;
F_6 ( F_1 ( V_3 ) , L_18 , V_66 ) ;
V_83 = V_8 -> V_54 ;
V_82 = V_3 -> V_53 ;
V_61 = F_48 ( V_53 , V_83 , V_82 ) ;
F_49 ( V_81 , V_83 , V_82 , 0 ) ;
F_6 ( F_1 ( V_3 ) ,
L_20 ,
V_66 , V_61 , V_83 , V_82 ) ;
return V_61 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
F_6 ( F_1 ( V_3 ) , L_18 , V_66 ) ;
F_27 ( & V_8 -> V_67 ) ;
if ( ! F_21 ( & V_8 -> V_36 ) )
if ( F_8 ( V_8 ) )
F_20 ( V_8 ) ;
if ( F_21 ( & V_8 -> V_36 ) && ! F_21 ( & V_8 -> V_65 ) )
F_24 ( V_8 ) ;
F_29 ( & V_8 -> V_67 ) ;
}
static struct V_52 * F_51 ( struct V_2 * V_3 ,
struct V_30 * V_84 , unsigned int V_85 ,
enum V_86 V_23 , unsigned long V_57 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
struct V_24 * V_25 ;
struct V_30 * V_31 ;
unsigned int V_60 ;
unsigned int V_87 = 0 ;
if ( ! V_84 || ! V_85 ) {
F_16 ( F_1 ( V_3 ) , L_21 , V_66 ) ;
return NULL ;
}
if ( V_8 -> V_23 != V_23 ) {
F_16 ( F_1 ( V_3 ) ,
L_22 ) ;
return NULL ;
}
V_25 = F_39 ( V_8 ) ;
if ( ! V_25 ) {
F_16 ( F_1 ( V_3 ) , L_23 ) ;
return NULL ;
}
V_25 -> V_49 = ( V_57 & V_88 ) != 0 ;
F_52 (sgl, sg, sg_len, i) {
int V_68 ;
if ( V_87 > V_25 -> V_71 ) {
F_16 ( F_1 ( V_3 ) , L_24 ) ;
return NULL ;
}
V_68 = F_14 ( V_8 , V_25 -> V_28 + V_87 , V_31 ,
V_60 == ( V_85 - 1 ) ) ;
if ( V_68 ) {
F_16 ( F_1 ( V_3 ) , L_25 ,
V_68 ) ;
F_37 ( V_8 , V_25 ) ;
return NULL ;
}
V_87 += V_29 ;
}
F_53 ( F_2 ( V_3 ) , V_25 -> V_26 . V_41 ,
V_25 -> V_71 , V_75 ) ;
return & V_25 -> V_26 ;
}
static int F_54 ( struct V_2 * V_3 , enum V_89 V_90 ,
unsigned long V_91 )
{
struct V_7 * V_8 =
F_13 ( V_3 , struct V_7 , V_3 ) ;
struct V_24 * V_25 , * V_76 ;
F_6 ( F_1 ( V_3 ) , L_18 , V_66 ) ;
if ( V_90 != V_92 )
return - V_93 ;
F_27 ( & V_8 -> V_67 ) ;
F_40 (td_desc, _td_desc, &td_chan->queue,
desc_node)
F_22 ( & V_25 -> V_38 , & V_8 -> V_56 ) ;
F_20 ( V_8 ) ;
F_29 ( & V_8 -> V_67 ) ;
return 0 ;
}
static void F_55 ( unsigned long V_94 )
{
struct V_6 * V_12 = (struct V_6 * ) V_94 ;
T_1 V_16 ;
T_1 V_95 ;
T_1 V_13 ;
int V_60 ;
V_16 = F_5 ( V_12 -> V_14 + V_18 ) ;
V_95 = V_16 & F_23 ( V_12 ) ;
F_7 ( V_95 , V_12 -> V_14 + V_18 ) ;
for ( V_60 = 0 ; V_60 < V_12 -> V_62 . V_63 ; V_60 ++ )
if ( V_95 & ( 1 << V_60 ) ) {
struct V_7 * V_8 = V_12 -> V_64 + V_60 ;
F_56 ( & V_8 -> V_67 ) ;
F_20 ( V_8 ) ;
if ( ! F_21 ( & V_8 -> V_65 ) )
F_24 ( V_8 ) ;
F_57 ( & V_8 -> V_67 ) ;
}
V_13 = F_23 ( V_12 ) ;
F_7 ( V_13 , V_12 -> V_14 + V_15 ) ;
}
static T_5 F_58 ( int V_96 , void * V_97 )
{
struct V_6 * V_12 = V_97 ;
T_1 V_95 = F_5 ( V_12 -> V_14 + V_98 ) ;
if ( V_95 ) {
F_7 ( 0 , V_12 -> V_14 + V_15 ) ;
F_59 ( & V_12 -> V_99 ) ;
return V_100 ;
} else
return V_101 ;
}
static int T_6 F_60 ( struct V_102 * V_103 )
{
struct V_104 * V_105 = V_103 -> V_4 . V_106 ;
struct V_6 * V_12 ;
struct V_107 * V_108 ;
int V_96 ;
int V_68 ;
int V_60 ;
if ( ! V_105 ) {
F_16 ( & V_103 -> V_4 , L_26 ) ;
return - V_34 ;
}
V_108 = F_61 ( V_103 , V_109 , 0 ) ;
if ( ! V_108 )
return - V_34 ;
V_96 = F_62 ( V_103 , 0 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! F_63 ( V_108 -> V_110 , F_64 ( V_108 ) ,
V_111 ) )
return - V_112 ;
V_12 = F_31 ( sizeof( struct V_6 ) +
sizeof( struct V_7 ) * V_105 -> V_113 , V_69 ) ;
if ( ! V_12 ) {
V_68 = - V_77 ;
goto V_114;
}
F_6 ( & V_103 -> V_4 , L_27 , V_12 ) ;
V_12 -> V_14 = F_65 ( V_108 -> V_110 , F_64 ( V_108 ) ) ;
if ( ! V_12 -> V_14 ) {
F_16 ( & V_103 -> V_4 , L_28 ) ;
V_68 = - V_77 ;
goto V_115;
}
F_7 ( V_116 , V_12 -> V_14 + V_117 ) ;
F_7 ( 0x0 , V_12 -> V_14 + V_15 ) ;
F_7 ( 0xFFFFFFFF , V_12 -> V_14 + V_18 ) ;
F_66 ( & V_12 -> V_99 , F_55 , ( unsigned long ) V_12 ) ;
V_68 = F_67 ( V_96 , F_58 , V_118 , V_111 , V_12 ) ;
if ( V_68 ) {
F_16 ( & V_103 -> V_4 , L_29 ) ;
goto V_119;
}
V_12 -> V_62 . V_120 = F_43 ;
V_12 -> V_62 . V_121 = F_44 ;
V_12 -> V_62 . V_122 = F_47 ;
V_12 -> V_62 . V_123 = F_50 ;
F_68 ( V_124 , V_12 -> V_62 . V_125 ) ;
F_68 ( V_126 , V_12 -> V_62 . V_125 ) ;
V_12 -> V_62 . V_127 = F_51 ;
V_12 -> V_62 . V_128 = F_54 ;
V_12 -> V_62 . V_4 = & V_103 -> V_4 ;
F_69 ( & V_12 -> V_62 . V_64 ) ;
for ( V_60 = 0 ; V_60 < V_105 -> V_113 ; V_60 ++ , V_12 -> V_62 . V_63 ++ ) {
struct V_7 * V_8 = & V_12 -> V_64 [ V_60 ] ;
struct V_129 * V_130 =
V_105 -> V_64 + V_60 ;
if ( ( V_60 % 2 ) == V_130 -> V_131 ) {
F_16 ( & V_103 -> V_4 , L_30 ) ;
V_68 = - V_34 ;
goto V_119;
}
V_8 -> V_3 . V_1 = & V_12 -> V_62 ;
V_8 -> V_3 . V_53 = 1 ;
V_8 -> V_3 . V_10 = V_60 ;
F_70 ( & V_8 -> V_67 ) ;
F_69 ( & V_8 -> V_36 ) ;
F_69 ( & V_8 -> V_65 ) ;
F_69 ( & V_8 -> V_56 ) ;
V_8 -> V_27 = V_130 -> V_132 ;
V_8 -> V_72 = V_130 -> V_133 ;
V_8 -> V_43 = V_130 -> V_43 ;
V_8 -> V_23 = V_130 -> V_131 ? V_39 :
V_75 ;
V_8 -> V_14 = V_12 -> V_14 +
( V_60 / 2 ) * V_134 +
( V_130 -> V_131 ? 0 : V_135 ) ;
F_6 ( & V_103 -> V_4 , L_31 ,
V_60 , V_8 -> V_14 ) ;
F_28 ( & V_8 -> V_3 . V_136 , & V_12 -> V_62 . V_64 ) ;
}
V_68 = F_71 ( & V_12 -> V_62 ) ;
if ( V_68 ) {
F_16 ( & V_103 -> V_4 , L_32 ) ;
goto V_137;
}
F_72 ( V_103 , V_12 ) ;
F_6 ( & V_103 -> V_4 , L_33 , V_68 ) ;
return V_68 ;
V_137:
F_73 ( V_96 , V_12 ) ;
V_119:
F_74 ( & V_12 -> V_99 ) ;
F_75 ( V_12 -> V_14 ) ;
V_115:
F_35 ( V_12 ) ;
V_114:
F_76 ( V_108 -> V_110 , F_64 ( V_108 ) ) ;
return V_68 ;
}
static int T_7 F_77 ( struct V_102 * V_103 )
{
struct V_6 * V_12 = F_78 ( V_103 ) ;
struct V_107 * V_108 = F_61 ( V_103 , V_109 , 0 ) ;
int V_96 = F_62 ( V_103 , 0 ) ;
F_79 ( & V_12 -> V_62 ) ;
F_73 ( V_96 , V_12 ) ;
F_74 ( & V_12 -> V_99 ) ;
F_75 ( V_12 -> V_14 ) ;
F_35 ( V_12 ) ;
F_76 ( V_108 -> V_110 , F_64 ( V_108 ) ) ;
F_72 ( V_103 , NULL ) ;
F_6 ( & V_103 -> V_4 , L_34 ) ;
return 0 ;
}
static int T_8 F_80 ( void )
{
return F_81 ( & V_138 ) ;
}
static void T_9 F_82 ( void )
{
F_83 ( & V_138 ) ;
}
