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
static int F_9 ( struct V_7 * V_8 , V_11 * V_19 ,
struct V_20 * V_21 , bool V_22 )
{
if ( F_10 ( V_21 ) > V_23 ) {
F_11 ( F_1 ( & V_8 -> V_3 ) , L_3 ) ;
return - V_24 ;
}
if ( F_10 ( V_21 ) % sizeof( T_1 ) ) {
F_11 ( F_1 ( & V_8 -> V_3 ) , L_4 ,
F_10 ( V_21 ) ) ;
return - V_24 ;
}
F_6 ( F_1 ( & V_8 -> V_3 ) , L_5 ,
V_19 , ( unsigned long long ) F_12 ( V_21 ) ) ;
V_19 [ 7 ] = ( F_12 ( V_21 ) >> 24 ) & 0xff ;
V_19 [ 6 ] = ( F_12 ( V_21 ) >> 16 ) & 0xff ;
V_19 [ 5 ] = ( F_12 ( V_21 ) >> 8 ) & 0xff ;
V_19 [ 4 ] = ( F_12 ( V_21 ) >> 0 ) & 0xff ;
V_19 [ 3 ] = ( F_10 ( V_21 ) >> 8 ) & 0xff ;
V_19 [ 2 ] = ( F_10 ( V_21 ) >> 0 ) & 0xff ;
V_19 [ 1 ] = 0x00 ;
V_19 [ 0 ] = 0x21 | ( V_22 ? 0x02 : 0 ) ;
return 0 ;
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_25 * V_26 ;
if ( V_8 -> V_27 ) {
F_11 ( F_1 ( & V_8 -> V_3 ) ,
L_6 ) ;
return;
}
V_26 = F_14 ( V_8 -> V_28 . V_29 , struct V_25 ,
V_30 ) ;
F_6 ( F_1 ( & V_8 -> V_3 ) ,
L_7 ,
V_8 , V_8 -> V_3 . V_10 , V_8 -> V_14 ) ;
if ( V_8 -> V_31 == V_32 ) {
F_7 ( 0 , V_8 -> V_14 + V_33 ) ;
F_7 ( V_26 -> V_34 . V_35 , V_8 -> V_14 +
V_36 ) ;
F_7 ( V_8 -> V_37 , V_8 -> V_14 +
V_38 ) ;
F_7 ( V_39 , V_8 -> V_14 + V_40 ) ;
} else {
F_7 ( 0 , V_8 -> V_14 + V_41 ) ;
F_7 ( V_26 -> V_34 . V_35 , V_8 -> V_14 +
V_42 ) ;
}
V_8 -> V_27 = true ;
if ( V_26 -> V_43 )
F_4 ( V_8 ) ;
}
static void F_15 ( struct V_7 * V_8 )
{
T_2 V_44 ;
void * V_45 ;
struct V_46 * V_34 ;
struct V_25 * V_26 ;
if ( F_16 ( & V_8 -> V_28 ) )
return;
V_26 = F_14 ( V_8 -> V_28 . V_29 , struct V_25 ,
V_30 ) ;
V_34 = & V_26 -> V_34 ;
F_6 ( F_1 ( & V_8 -> V_3 ) , L_8 ,
V_34 -> V_47 ) ;
if ( V_8 -> V_31 == V_32 )
F_7 ( 0 , V_8 -> V_14 + V_40 ) ;
F_17 ( V_34 ) ;
V_8 -> V_27 = false ;
V_44 = V_34 -> V_44 ;
V_45 = V_34 -> V_48 ;
F_18 ( & V_26 -> V_30 , & V_8 -> V_49 ) ;
F_19 ( V_34 ) ;
if ( V_44 )
V_44 ( V_45 ) ;
}
static T_1 F_20 ( struct V_6 * V_12 )
{
int V_50 ;
T_1 V_51 = 0 ;
for ( V_50 = 0 ; V_50 < V_12 -> V_52 . V_53 ; V_50 ++ ) {
struct V_7 * V_8 = V_12 -> V_54 + V_50 ;
if ( V_8 -> V_27 ) {
struct V_25 * V_26 =
F_14 ( V_8 -> V_28 . V_29 ,
struct V_25 , V_30 ) ;
if ( V_26 -> V_43 )
V_51 |= 1 << V_50 ;
}
}
return V_51 ;
}
static void F_21 ( struct V_7 * V_8 )
{
struct V_25 * V_26 ;
F_22 ( F_16 ( & V_8 -> V_55 ) ) ;
F_22 ( V_8 -> V_27 ) ;
V_26 = F_14 ( V_8 -> V_55 . V_29 , struct V_25 ,
V_30 ) ;
F_6 ( F_1 ( & V_8 -> V_3 ) , L_9 ,
V_56 , V_26 -> V_34 . V_47 ) ;
F_18 ( & V_26 -> V_30 , & V_8 -> V_28 ) ;
F_13 ( V_8 ) ;
}
static T_3 F_23 ( struct V_46 * V_34 )
{
struct V_25 * V_26 = F_24 ( V_34 , struct V_25 ,
V_34 ) ;
struct V_7 * V_8 = F_24 ( V_34 -> V_3 ,
struct V_7 , V_3 ) ;
T_3 V_47 ;
F_25 ( & V_8 -> V_57 ) ;
V_47 = F_26 ( V_34 ) ;
if ( F_16 ( & V_8 -> V_28 ) ) {
F_6 ( F_1 ( V_34 -> V_3 ) , L_9 , V_56 ,
V_34 -> V_47 ) ;
F_27 ( & V_26 -> V_30 , & V_8 -> V_28 ) ;
F_13 ( V_8 ) ;
} else {
F_6 ( F_1 ( V_34 -> V_3 ) , L_10 ,
V_34 -> V_47 ) ;
F_27 ( & V_26 -> V_30 , & V_8 -> V_55 ) ;
}
F_28 ( & V_8 -> V_57 ) ;
return V_47 ;
}
static struct V_25 * F_29 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
struct V_25 * V_26 ;
int V_58 ;
V_26 = F_30 ( sizeof( struct V_25 ) , V_59 ) ;
if ( ! V_26 ) {
F_11 ( F_1 ( V_3 ) , L_11 ) ;
goto V_60;
}
V_26 -> V_61 = V_8 -> V_62 * V_63 ;
V_26 -> V_64 = F_30 ( V_26 -> V_61 , V_59 ) ;
if ( ! V_26 -> V_64 ) {
F_11 ( F_1 ( V_3 ) , L_11 ) ;
goto V_58;
}
F_31 ( & V_26 -> V_34 , V_3 ) ;
V_26 -> V_34 . V_65 = F_23 ;
V_26 -> V_34 . V_66 = V_67 ;
V_26 -> V_34 . V_35 = F_32 ( F_2 ( V_3 ) ,
V_26 -> V_64 , V_26 -> V_61 , V_68 ) ;
V_58 = F_33 ( F_2 ( V_3 ) , V_26 -> V_34 . V_35 ) ;
if ( V_58 ) {
F_11 ( F_1 ( V_3 ) , L_12 , V_58 ) ;
goto V_58;
}
return V_26 ;
V_58:
F_34 ( V_26 -> V_64 ) ;
F_34 ( V_26 ) ;
V_60:
return NULL ;
}
static void F_35 ( struct V_25 * V_26 )
{
F_6 ( F_1 ( V_26 -> V_34 . V_3 ) , L_13 , V_26 ) ;
F_36 ( F_2 ( V_26 -> V_34 . V_3 ) , V_26 -> V_34 . V_35 ,
V_26 -> V_61 , V_68 ) ;
F_34 ( V_26 -> V_64 ) ;
F_34 ( V_26 ) ;
}
static void F_37 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
F_6 ( F_1 ( & V_8 -> V_3 ) , L_14 , V_26 ) ;
F_25 ( & V_8 -> V_57 ) ;
F_38 ( & V_26 -> V_30 , & V_8 -> V_49 ) ;
F_28 ( & V_8 -> V_57 ) ;
}
static struct V_25 * F_39 ( struct V_7 * V_8 )
{
struct V_25 * V_26 , * V_69 ;
struct V_25 * V_51 = NULL ;
F_25 ( & V_8 -> V_57 ) ;
F_40 (td_desc, _td_desc, &td_chan->free_list,
desc_node) {
if ( F_41 ( & V_26 -> V_34 ) ) {
F_42 ( & V_26 -> V_30 ) ;
V_51 = V_26 ;
break;
}
F_6 ( F_1 ( & V_8 -> V_3 ) , L_15 ,
V_26 ) ;
}
F_28 ( & V_8 -> V_57 ) ;
return V_51 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_24 ( V_3 , struct V_7 , V_3 ) ;
int V_50 ;
F_6 ( F_1 ( V_3 ) , L_16 , V_56 ) ;
F_22 ( ! F_16 ( & V_8 -> V_49 ) ) ;
for ( V_50 = 0 ; V_50 < V_8 -> V_70 ; V_50 ++ ) {
struct V_25 * V_26 = F_29 ( V_8 ) ;
if ( ! V_26 ) {
if ( V_50 )
break;
else {
F_11 ( F_1 ( V_3 ) ,
L_17 ) ;
return - V_71 ;
}
}
F_37 ( V_8 , V_26 ) ;
}
F_25 ( & V_8 -> V_57 ) ;
F_44 ( V_3 ) ;
F_28 ( & V_8 -> V_57 ) ;
return 0 ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_24 ( V_3 , struct V_7 , V_3 ) ;
struct V_25 * V_26 , * V_69 ;
F_46 ( V_72 ) ;
F_6 ( F_1 ( V_3 ) , L_18 , V_56 ) ;
F_22 ( ! F_16 ( & V_8 -> V_28 ) ) ;
F_22 ( ! F_16 ( & V_8 -> V_55 ) ) ;
F_25 ( & V_8 -> V_57 ) ;
F_47 ( & V_8 -> V_49 , & V_72 ) ;
F_28 ( & V_8 -> V_57 ) ;
F_40 (td_desc, _td_desc, &list, desc_node) {
F_6 ( F_1 ( V_3 ) , L_19 , V_56 ,
V_26 ) ;
F_35 ( V_26 ) ;
}
}
static enum V_73 F_48 ( struct V_2 * V_3 , T_3 V_47 ,
struct V_74 * V_75 )
{
enum V_73 V_51 ;
F_6 ( F_1 ( V_3 ) , L_18 , V_56 ) ;
V_51 = F_49 ( V_3 , V_47 , V_75 ) ;
F_6 ( F_1 ( V_3 ) , L_20 , V_56 , V_51 ) ;
return V_51 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_24 ( V_3 , struct V_7 , V_3 ) ;
F_6 ( F_1 ( V_3 ) , L_18 , V_56 ) ;
F_25 ( & V_8 -> V_57 ) ;
if ( ! F_16 ( & V_8 -> V_28 ) )
if ( F_8 ( V_8 ) )
F_15 ( V_8 ) ;
if ( F_16 ( & V_8 -> V_28 ) && ! F_16 ( & V_8 -> V_55 ) )
F_21 ( V_8 ) ;
F_28 ( & V_8 -> V_57 ) ;
}
static struct V_46 * F_51 ( struct V_2 * V_3 ,
struct V_20 * V_76 , unsigned int V_77 ,
enum V_78 V_31 , unsigned long V_66 ,
void * V_79 )
{
struct V_7 * V_8 =
F_24 ( V_3 , struct V_7 , V_3 ) ;
struct V_25 * V_26 ;
struct V_20 * V_21 ;
unsigned int V_50 ;
unsigned int V_80 = 0 ;
if ( ! V_76 || ! V_77 ) {
F_11 ( F_1 ( V_3 ) , L_21 , V_56 ) ;
return NULL ;
}
if ( V_8 -> V_31 != V_31 ) {
F_11 ( F_1 ( V_3 ) ,
L_22 ) ;
return NULL ;
}
V_26 = F_39 ( V_8 ) ;
if ( ! V_26 ) {
F_11 ( F_1 ( V_3 ) , L_23 ) ;
return NULL ;
}
V_26 -> V_43 = ( V_66 & V_81 ) != 0 ;
F_52 (sgl, sg, sg_len, i) {
int V_58 ;
if ( V_80 > V_26 -> V_61 ) {
F_11 ( F_1 ( V_3 ) , L_24 ) ;
return NULL ;
}
V_58 = F_9 ( V_8 , V_26 -> V_64 + V_80 , V_21 ,
V_50 == ( V_77 - 1 ) ) ;
if ( V_58 ) {
F_11 ( F_1 ( V_3 ) , L_25 ,
V_58 ) ;
F_37 ( V_8 , V_26 ) ;
return NULL ;
}
V_80 += V_63 ;
}
F_53 ( F_2 ( V_3 ) , V_26 -> V_34 . V_35 ,
V_26 -> V_61 , V_82 ) ;
return & V_26 -> V_34 ;
}
static int F_54 ( struct V_2 * V_3 , enum V_83 V_84 ,
unsigned long V_85 )
{
struct V_7 * V_8 =
F_24 ( V_3 , struct V_7 , V_3 ) ;
struct V_25 * V_26 , * V_69 ;
F_6 ( F_1 ( V_3 ) , L_18 , V_56 ) ;
if ( V_84 != V_86 )
return - V_87 ;
F_25 ( & V_8 -> V_57 ) ;
F_40 (td_desc, _td_desc, &td_chan->queue,
desc_node)
F_18 ( & V_26 -> V_30 , & V_8 -> V_49 ) ;
F_15 ( V_8 ) ;
F_28 ( & V_8 -> V_57 ) ;
return 0 ;
}
static void F_55 ( unsigned long V_88 )
{
struct V_6 * V_12 = (struct V_6 * ) V_88 ;
T_1 V_16 ;
T_1 V_89 ;
T_1 V_13 ;
int V_50 ;
V_16 = F_5 ( V_12 -> V_14 + V_18 ) ;
V_89 = V_16 & F_20 ( V_12 ) ;
F_7 ( V_89 , V_12 -> V_14 + V_18 ) ;
for ( V_50 = 0 ; V_50 < V_12 -> V_52 . V_53 ; V_50 ++ )
if ( V_89 & ( 1 << V_50 ) ) {
struct V_7 * V_8 = V_12 -> V_54 + V_50 ;
F_56 ( & V_8 -> V_57 ) ;
F_15 ( V_8 ) ;
if ( ! F_16 ( & V_8 -> V_55 ) )
F_21 ( V_8 ) ;
F_57 ( & V_8 -> V_57 ) ;
}
V_13 = F_20 ( V_12 ) ;
F_7 ( V_13 , V_12 -> V_14 + V_15 ) ;
}
static T_4 F_58 ( int V_90 , void * V_91 )
{
struct V_6 * V_12 = V_91 ;
T_1 V_89 = F_5 ( V_12 -> V_14 + V_92 ) ;
if ( V_89 ) {
F_7 ( 0 , V_12 -> V_14 + V_15 ) ;
F_59 ( & V_12 -> V_93 ) ;
return V_94 ;
} else
return V_95 ;
}
static int F_60 ( struct V_96 * V_97 )
{
struct V_98 * V_99 = F_61 ( & V_97 -> V_4 ) ;
struct V_6 * V_12 ;
struct V_100 * V_101 ;
int V_90 ;
int V_58 ;
int V_50 ;
if ( ! V_99 ) {
F_11 ( & V_97 -> V_4 , L_26 ) ;
return - V_24 ;
}
V_101 = F_62 ( V_97 , V_102 , 0 ) ;
if ( ! V_101 )
return - V_24 ;
V_90 = F_63 ( V_97 , 0 ) ;
if ( V_90 < 0 )
return V_90 ;
if ( ! F_64 ( V_101 -> V_103 , F_65 ( V_101 ) ,
V_104 ) )
return - V_105 ;
V_12 = F_30 ( sizeof( struct V_6 ) +
sizeof( struct V_7 ) * V_99 -> V_106 , V_59 ) ;
if ( ! V_12 ) {
V_58 = - V_71 ;
goto V_107;
}
F_6 ( & V_97 -> V_4 , L_27 , V_12 ) ;
V_12 -> V_14 = F_66 ( V_101 -> V_103 , F_65 ( V_101 ) ) ;
if ( ! V_12 -> V_14 ) {
F_11 ( & V_97 -> V_4 , L_28 ) ;
V_58 = - V_71 ;
goto V_108;
}
F_7 ( V_109 , V_12 -> V_14 + V_110 ) ;
F_7 ( 0x0 , V_12 -> V_14 + V_15 ) ;
F_7 ( 0xFFFFFFFF , V_12 -> V_14 + V_18 ) ;
F_67 ( & V_12 -> V_93 , F_55 , ( unsigned long ) V_12 ) ;
V_58 = F_68 ( V_90 , F_58 , V_111 , V_104 , V_12 ) ;
if ( V_58 ) {
F_11 ( & V_97 -> V_4 , L_29 ) ;
goto V_112;
}
V_12 -> V_52 . V_113 = F_43 ;
V_12 -> V_52 . V_114 = F_45 ;
V_12 -> V_52 . V_115 = F_48 ;
V_12 -> V_52 . V_116 = F_50 ;
F_69 ( V_117 , V_12 -> V_52 . V_118 ) ;
F_69 ( V_119 , V_12 -> V_52 . V_118 ) ;
V_12 -> V_52 . V_120 = F_51 ;
V_12 -> V_52 . V_121 = F_54 ;
V_12 -> V_52 . V_4 = & V_97 -> V_4 ;
F_70 ( & V_12 -> V_52 . V_54 ) ;
for ( V_50 = 0 ; V_50 < V_99 -> V_106 ; V_50 ++ ) {
struct V_7 * V_8 = & V_12 -> V_54 [ V_50 ] ;
struct V_122 * V_123 =
V_99 -> V_54 + V_50 ;
if ( ( V_50 % 2 ) == V_123 -> V_124 ) {
F_11 ( & V_97 -> V_4 , L_30 ) ;
V_58 = - V_24 ;
goto V_125;
}
V_8 -> V_3 . V_1 = & V_12 -> V_52 ;
F_44 ( & V_8 -> V_3 ) ;
F_71 ( & V_8 -> V_57 ) ;
F_70 ( & V_8 -> V_28 ) ;
F_70 ( & V_8 -> V_55 ) ;
F_70 ( & V_8 -> V_49 ) ;
V_8 -> V_70 = V_123 -> V_126 ;
V_8 -> V_62 = V_123 -> V_127 ;
V_8 -> V_37 = V_123 -> V_37 ;
V_8 -> V_31 = V_123 -> V_124 ? V_32 :
V_82 ;
V_8 -> V_14 = V_12 -> V_14 +
( V_50 / 2 ) * V_128 +
( V_123 -> V_124 ? 0 : V_129 ) ;
F_6 ( & V_97 -> V_4 , L_31 ,
V_50 , V_8 -> V_14 ) ;
F_27 ( & V_8 -> V_3 . V_130 , & V_12 -> V_52 . V_54 ) ;
}
V_58 = F_72 ( & V_12 -> V_52 ) ;
if ( V_58 ) {
F_11 ( & V_97 -> V_4 , L_32 ) ;
goto V_125;
}
F_73 ( V_97 , V_12 ) ;
F_6 ( & V_97 -> V_4 , L_33 , V_58 ) ;
return V_58 ;
V_125:
F_74 ( V_90 , V_12 ) ;
V_112:
F_75 ( & V_12 -> V_93 ) ;
F_76 ( V_12 -> V_14 ) ;
V_108:
F_34 ( V_12 ) ;
V_107:
F_77 ( V_101 -> V_103 , F_65 ( V_101 ) ) ;
return V_58 ;
}
static int F_78 ( struct V_96 * V_97 )
{
struct V_6 * V_12 = F_79 ( V_97 ) ;
struct V_100 * V_101 = F_62 ( V_97 , V_102 , 0 ) ;
int V_90 = F_63 ( V_97 , 0 ) ;
F_80 ( & V_12 -> V_52 ) ;
F_74 ( V_90 , V_12 ) ;
F_75 ( & V_12 -> V_93 ) ;
F_76 ( V_12 -> V_14 ) ;
F_34 ( V_12 ) ;
F_77 ( V_101 -> V_103 , F_65 ( V_101 ) ) ;
F_6 ( & V_97 -> V_4 , L_34 ) ;
return 0 ;
}
