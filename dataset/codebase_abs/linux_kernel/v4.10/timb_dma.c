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
struct V_44 V_45 ;
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
F_18 ( V_34 , & V_45 ) ;
F_19 ( & V_26 -> V_30 , & V_8 -> V_48 ) ;
F_20 ( V_34 ) ;
F_21 ( & V_45 , NULL ) ;
}
static T_1 F_22 ( struct V_6 * V_12 )
{
int V_49 ;
T_1 V_50 = 0 ;
for ( V_49 = 0 ; V_49 < V_12 -> V_51 . V_52 ; V_49 ++ ) {
struct V_7 * V_8 = V_12 -> V_53 + V_49 ;
if ( V_8 -> V_27 ) {
struct V_25 * V_26 =
F_14 ( V_8 -> V_28 . V_29 ,
struct V_25 , V_30 ) ;
if ( V_26 -> V_43 )
V_50 |= 1 << V_49 ;
}
}
return V_50 ;
}
static void F_23 ( struct V_7 * V_8 )
{
struct V_25 * V_26 ;
F_24 ( F_16 ( & V_8 -> V_54 ) ) ;
F_24 ( V_8 -> V_27 ) ;
V_26 = F_14 ( V_8 -> V_54 . V_29 , struct V_25 ,
V_30 ) ;
F_6 ( F_1 ( & V_8 -> V_3 ) , L_9 ,
V_55 , V_26 -> V_34 . V_47 ) ;
F_19 ( & V_26 -> V_30 , & V_8 -> V_28 ) ;
F_13 ( V_8 ) ;
}
static T_2 F_25 ( struct V_46 * V_34 )
{
struct V_25 * V_26 = F_26 ( V_34 , struct V_25 ,
V_34 ) ;
struct V_7 * V_8 = F_26 ( V_34 -> V_3 ,
struct V_7 , V_3 ) ;
T_2 V_47 ;
F_27 ( & V_8 -> V_56 ) ;
V_47 = F_28 ( V_34 ) ;
if ( F_16 ( & V_8 -> V_28 ) ) {
F_6 ( F_1 ( V_34 -> V_3 ) , L_9 , V_55 ,
V_34 -> V_47 ) ;
F_29 ( & V_26 -> V_30 , & V_8 -> V_28 ) ;
F_13 ( V_8 ) ;
} else {
F_6 ( F_1 ( V_34 -> V_3 ) , L_10 ,
V_34 -> V_47 ) ;
F_29 ( & V_26 -> V_30 , & V_8 -> V_54 ) ;
}
F_30 ( & V_8 -> V_56 ) ;
return V_47 ;
}
static struct V_25 * F_31 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = & V_8 -> V_3 ;
struct V_25 * V_26 ;
int V_57 ;
V_26 = F_32 ( sizeof( struct V_25 ) , V_58 ) ;
if ( ! V_26 )
goto V_59;
V_26 -> V_60 = V_8 -> V_61 * V_62 ;
V_26 -> V_63 = F_32 ( V_26 -> V_60 , V_58 ) ;
if ( ! V_26 -> V_63 )
goto V_57;
F_33 ( & V_26 -> V_34 , V_3 ) ;
V_26 -> V_34 . V_64 = F_25 ;
V_26 -> V_34 . V_65 = V_66 ;
V_26 -> V_34 . V_35 = F_34 ( F_2 ( V_3 ) ,
V_26 -> V_63 , V_26 -> V_60 , V_67 ) ;
V_57 = F_35 ( F_2 ( V_3 ) , V_26 -> V_34 . V_35 ) ;
if ( V_57 ) {
F_11 ( F_1 ( V_3 ) , L_11 , V_57 ) ;
goto V_57;
}
return V_26 ;
V_57:
F_36 ( V_26 -> V_63 ) ;
F_36 ( V_26 ) ;
V_59:
return NULL ;
}
static void F_37 ( struct V_25 * V_26 )
{
F_6 ( F_1 ( V_26 -> V_34 . V_3 ) , L_12 , V_26 ) ;
F_38 ( F_2 ( V_26 -> V_34 . V_3 ) , V_26 -> V_34 . V_35 ,
V_26 -> V_60 , V_67 ) ;
F_36 ( V_26 -> V_63 ) ;
F_36 ( V_26 ) ;
}
static void F_39 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
F_6 ( F_1 ( & V_8 -> V_3 ) , L_13 , V_26 ) ;
F_27 ( & V_8 -> V_56 ) ;
F_40 ( & V_26 -> V_30 , & V_8 -> V_48 ) ;
F_30 ( & V_8 -> V_56 ) ;
}
static struct V_25 * F_41 ( struct V_7 * V_8 )
{
struct V_25 * V_26 , * V_68 ;
struct V_25 * V_50 = NULL ;
F_27 ( & V_8 -> V_56 ) ;
F_42 (td_desc, _td_desc, &td_chan->free_list,
desc_node) {
if ( F_43 ( & V_26 -> V_34 ) ) {
F_44 ( & V_26 -> V_30 ) ;
V_50 = V_26 ;
break;
}
F_6 ( F_1 ( & V_8 -> V_3 ) , L_14 ,
V_26 ) ;
}
F_30 ( & V_8 -> V_56 ) ;
return V_50 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_26 ( V_3 , struct V_7 , V_3 ) ;
int V_49 ;
F_6 ( F_1 ( V_3 ) , L_15 , V_55 ) ;
F_24 ( ! F_16 ( & V_8 -> V_48 ) ) ;
for ( V_49 = 0 ; V_49 < V_8 -> V_69 ; V_49 ++ ) {
struct V_25 * V_26 = F_31 ( V_8 ) ;
if ( ! V_26 ) {
if ( V_49 )
break;
else {
F_11 ( F_1 ( V_3 ) ,
L_16 ) ;
return - V_70 ;
}
}
F_39 ( V_8 , V_26 ) ;
}
F_27 ( & V_8 -> V_56 ) ;
F_46 ( V_3 ) ;
F_30 ( & V_8 -> V_56 ) ;
return 0 ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_26 ( V_3 , struct V_7 , V_3 ) ;
struct V_25 * V_26 , * V_68 ;
F_48 ( V_71 ) ;
F_6 ( F_1 ( V_3 ) , L_17 , V_55 ) ;
F_24 ( ! F_16 ( & V_8 -> V_28 ) ) ;
F_24 ( ! F_16 ( & V_8 -> V_54 ) ) ;
F_27 ( & V_8 -> V_56 ) ;
F_49 ( & V_8 -> V_48 , & V_71 ) ;
F_30 ( & V_8 -> V_56 ) ;
F_42 (td_desc, _td_desc, &list, desc_node) {
F_6 ( F_1 ( V_3 ) , L_18 , V_55 ,
V_26 ) ;
F_37 ( V_26 ) ;
}
}
static enum V_72 F_50 ( struct V_2 * V_3 , T_2 V_47 ,
struct V_73 * V_74 )
{
enum V_72 V_50 ;
F_6 ( F_1 ( V_3 ) , L_17 , V_55 ) ;
V_50 = F_51 ( V_3 , V_47 , V_74 ) ;
F_6 ( F_1 ( V_3 ) , L_19 , V_55 , V_50 ) ;
return V_50 ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_26 ( V_3 , struct V_7 , V_3 ) ;
F_6 ( F_1 ( V_3 ) , L_17 , V_55 ) ;
F_27 ( & V_8 -> V_56 ) ;
if ( ! F_16 ( & V_8 -> V_28 ) )
if ( F_8 ( V_8 ) )
F_15 ( V_8 ) ;
if ( F_16 ( & V_8 -> V_28 ) && ! F_16 ( & V_8 -> V_54 ) )
F_23 ( V_8 ) ;
F_30 ( & V_8 -> V_56 ) ;
}
static struct V_46 * F_53 ( struct V_2 * V_3 ,
struct V_20 * V_75 , unsigned int V_76 ,
enum V_77 V_31 , unsigned long V_65 ,
void * V_78 )
{
struct V_7 * V_8 =
F_26 ( V_3 , struct V_7 , V_3 ) ;
struct V_25 * V_26 ;
struct V_20 * V_21 ;
unsigned int V_49 ;
unsigned int V_79 = 0 ;
if ( ! V_75 || ! V_76 ) {
F_11 ( F_1 ( V_3 ) , L_20 , V_55 ) ;
return NULL ;
}
if ( V_8 -> V_31 != V_31 ) {
F_11 ( F_1 ( V_3 ) ,
L_21 ) ;
return NULL ;
}
V_26 = F_41 ( V_8 ) ;
if ( ! V_26 ) {
F_11 ( F_1 ( V_3 ) , L_22 ) ;
return NULL ;
}
V_26 -> V_43 = ( V_65 & V_80 ) != 0 ;
F_54 (sgl, sg, sg_len, i) {
int V_57 ;
if ( V_79 > V_26 -> V_60 ) {
F_11 ( F_1 ( V_3 ) , L_23 ) ;
return NULL ;
}
V_57 = F_9 ( V_8 , V_26 -> V_63 + V_79 , V_21 ,
V_49 == ( V_76 - 1 ) ) ;
if ( V_57 ) {
F_11 ( F_1 ( V_3 ) , L_24 ,
V_57 ) ;
F_39 ( V_8 , V_26 ) ;
return NULL ;
}
V_79 += V_62 ;
}
F_55 ( F_2 ( V_3 ) , V_26 -> V_34 . V_35 ,
V_26 -> V_60 , V_81 ) ;
return & V_26 -> V_34 ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_7 * V_8 =
F_26 ( V_3 , struct V_7 , V_3 ) ;
struct V_25 * V_26 , * V_68 ;
F_6 ( F_1 ( V_3 ) , L_17 , V_55 ) ;
F_27 ( & V_8 -> V_56 ) ;
F_42 (td_desc, _td_desc, &td_chan->queue,
desc_node)
F_19 ( & V_26 -> V_30 , & V_8 -> V_48 ) ;
F_15 ( V_8 ) ;
F_30 ( & V_8 -> V_56 ) ;
return 0 ;
}
static void F_57 ( unsigned long V_82 )
{
struct V_6 * V_12 = (struct V_6 * ) V_82 ;
T_1 V_16 ;
T_1 V_83 ;
T_1 V_13 ;
int V_49 ;
V_16 = F_5 ( V_12 -> V_14 + V_18 ) ;
V_83 = V_16 & F_22 ( V_12 ) ;
F_7 ( V_83 , V_12 -> V_14 + V_18 ) ;
for ( V_49 = 0 ; V_49 < V_12 -> V_51 . V_52 ; V_49 ++ )
if ( V_83 & ( 1 << V_49 ) ) {
struct V_7 * V_8 = V_12 -> V_53 + V_49 ;
F_58 ( & V_8 -> V_56 ) ;
F_15 ( V_8 ) ;
if ( ! F_16 ( & V_8 -> V_54 ) )
F_23 ( V_8 ) ;
F_59 ( & V_8 -> V_56 ) ;
}
V_13 = F_22 ( V_12 ) ;
F_7 ( V_13 , V_12 -> V_14 + V_15 ) ;
}
static T_3 F_60 ( int V_84 , void * V_85 )
{
struct V_6 * V_12 = V_85 ;
T_1 V_83 = F_5 ( V_12 -> V_14 + V_86 ) ;
if ( V_83 ) {
F_7 ( 0 , V_12 -> V_14 + V_15 ) ;
F_61 ( & V_12 -> V_87 ) ;
return V_88 ;
} else
return V_89 ;
}
static int F_62 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = F_63 ( & V_91 -> V_4 ) ;
struct V_6 * V_12 ;
struct V_94 * V_95 ;
int V_84 ;
int V_57 ;
int V_49 ;
if ( ! V_93 ) {
F_11 ( & V_91 -> V_4 , L_25 ) ;
return - V_24 ;
}
V_95 = F_64 ( V_91 , V_96 , 0 ) ;
if ( ! V_95 )
return - V_24 ;
V_84 = F_65 ( V_91 , 0 ) ;
if ( V_84 < 0 )
return V_84 ;
if ( ! F_66 ( V_95 -> V_97 , F_67 ( V_95 ) ,
V_98 ) )
return - V_99 ;
V_12 = F_32 ( sizeof( struct V_6 ) +
sizeof( struct V_7 ) * V_93 -> V_100 , V_58 ) ;
if ( ! V_12 ) {
V_57 = - V_70 ;
goto V_101;
}
F_6 ( & V_91 -> V_4 , L_26 , V_12 ) ;
V_12 -> V_14 = F_68 ( V_95 -> V_97 , F_67 ( V_95 ) ) ;
if ( ! V_12 -> V_14 ) {
F_11 ( & V_91 -> V_4 , L_27 ) ;
V_57 = - V_70 ;
goto V_102;
}
F_7 ( V_103 , V_12 -> V_14 + V_104 ) ;
F_7 ( 0x0 , V_12 -> V_14 + V_15 ) ;
F_7 ( 0xFFFFFFFF , V_12 -> V_14 + V_18 ) ;
F_69 ( & V_12 -> V_87 , F_57 , ( unsigned long ) V_12 ) ;
V_57 = F_70 ( V_84 , F_60 , V_105 , V_98 , V_12 ) ;
if ( V_57 ) {
F_11 ( & V_91 -> V_4 , L_28 ) ;
goto V_106;
}
V_12 -> V_51 . V_107 = F_45 ;
V_12 -> V_51 . V_108 = F_47 ;
V_12 -> V_51 . V_109 = F_50 ;
V_12 -> V_51 . V_110 = F_52 ;
F_71 ( V_111 , V_12 -> V_51 . V_112 ) ;
F_71 ( V_113 , V_12 -> V_51 . V_112 ) ;
V_12 -> V_51 . V_114 = F_53 ;
V_12 -> V_51 . V_115 = F_56 ;
V_12 -> V_51 . V_4 = & V_91 -> V_4 ;
F_72 ( & V_12 -> V_51 . V_53 ) ;
for ( V_49 = 0 ; V_49 < V_93 -> V_100 ; V_49 ++ ) {
struct V_7 * V_8 = & V_12 -> V_53 [ V_49 ] ;
struct V_116 * V_117 =
V_93 -> V_53 + V_49 ;
if ( ( V_49 % 2 ) == V_117 -> V_118 ) {
F_11 ( & V_91 -> V_4 , L_29 ) ;
V_57 = - V_24 ;
goto V_119;
}
V_8 -> V_3 . V_1 = & V_12 -> V_51 ;
F_46 ( & V_8 -> V_3 ) ;
F_73 ( & V_8 -> V_56 ) ;
F_72 ( & V_8 -> V_28 ) ;
F_72 ( & V_8 -> V_54 ) ;
F_72 ( & V_8 -> V_48 ) ;
V_8 -> V_69 = V_117 -> V_120 ;
V_8 -> V_61 = V_117 -> V_121 ;
V_8 -> V_37 = V_117 -> V_37 ;
V_8 -> V_31 = V_117 -> V_118 ? V_32 :
V_81 ;
V_8 -> V_14 = V_12 -> V_14 +
( V_49 / 2 ) * V_122 +
( V_117 -> V_118 ? 0 : V_123 ) ;
F_6 ( & V_91 -> V_4 , L_30 ,
V_49 , V_8 -> V_14 ) ;
F_29 ( & V_8 -> V_3 . V_124 , & V_12 -> V_51 . V_53 ) ;
}
V_57 = F_74 ( & V_12 -> V_51 ) ;
if ( V_57 ) {
F_11 ( & V_91 -> V_4 , L_31 ) ;
goto V_119;
}
F_75 ( V_91 , V_12 ) ;
F_6 ( & V_91 -> V_4 , L_32 , V_57 ) ;
return V_57 ;
V_119:
F_76 ( V_84 , V_12 ) ;
V_106:
F_77 ( & V_12 -> V_87 ) ;
F_78 ( V_12 -> V_14 ) ;
V_102:
F_36 ( V_12 ) ;
V_101:
F_79 ( V_95 -> V_97 , F_67 ( V_95 ) ) ;
return V_57 ;
}
static int F_80 ( struct V_90 * V_91 )
{
struct V_6 * V_12 = F_81 ( V_91 ) ;
struct V_94 * V_95 = F_64 ( V_91 , V_96 , 0 ) ;
int V_84 = F_65 ( V_91 , 0 ) ;
F_82 ( & V_12 -> V_51 ) ;
F_76 ( V_84 , V_12 ) ;
F_77 ( & V_12 -> V_87 ) ;
F_78 ( V_12 -> V_14 ) ;
F_36 ( V_12 ) ;
F_79 ( V_95 -> V_97 , F_67 ( V_95 ) ) ;
F_6 ( & V_91 -> V_4 , L_33 ) ;
return 0 ;
}
