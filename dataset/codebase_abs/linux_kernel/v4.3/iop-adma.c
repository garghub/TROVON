static void F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 ;
while ( V_3 -- ) {
V_2 -> V_4 = 0 ;
V_2 = F_2 ( V_2 -> V_5 . V_6 ,
struct V_1 ,
V_5 ) ;
}
}
static T_1
F_3 ( struct V_1 * V_7 ,
struct V_8 * V_9 , T_1 V_10 )
{
struct V_11 * V_12 = & V_7 -> V_13 ;
F_4 ( V_12 -> V_10 < 0 ) ;
if ( V_12 -> V_10 > 0 ) {
V_10 = V_12 -> V_10 ;
V_12 -> V_10 = 0 ;
if ( V_12 -> V_14 )
V_12 -> V_14 ( V_12 -> V_15 ) ;
F_5 ( V_12 ) ;
if ( V_7 -> V_16 )
V_7 -> V_16 = NULL ;
}
F_6 ( V_12 ) ;
return V_10 ;
}
static int
F_7 ( struct V_1 * V_7 ,
struct V_8 * V_9 )
{
if ( ! F_8 ( & V_7 -> V_13 ) )
return 0 ;
if ( V_7 -> V_17 . V_6 == & V_9 -> V_18 )
return 1 ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 ,
L_1 ,
V_7 -> V_22 , V_7 -> V_4 ) ;
F_10 ( & V_7 -> V_17 ) ;
F_1 ( V_7 ) ;
return 0 ;
}
static void F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_23 , * V_24 , * V_25 = NULL ;
T_1 V_10 = 0 ;
T_2 V_26 = F_12 ( V_9 ) ;
int V_27 = F_13 ( V_9 ) ;
int V_28 = 0 , V_29 = 0 , V_4 = 0 ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 , L_2 , V_30 ) ;
F_14 (iter, _iter, &iop_chan->chain,
chain_node) {
F_15 ( L_3
L_4 ,
V_23 -> V_13 . V_10 , V_23 -> V_22 , V_27 ,
V_23 -> V_13 . V_31 , F_16 ( V_23 ) ,
F_8 ( & V_23 -> V_13 ) ) ;
F_17 ( V_24 ) ;
F_17 ( & V_24 -> V_13 ) ;
if ( V_28 )
break;
if ( V_23 -> V_13 . V_31 == V_26 ) {
F_4 ( V_28 ++ ) ;
if ( V_27 || F_16 ( V_23 ) )
break;
}
if ( ! V_29 && ! V_4 ) {
V_29 = V_23 -> V_29 ;
V_4 = V_23 -> V_4 ;
if ( V_29 <= V_4 ) {
V_29 = 0 ;
V_4 = 0 ;
}
}
if ( V_29 ) {
F_15 ( L_5 ) ;
if ( ! V_25 )
V_25 = V_23 ;
V_29 -= V_4 ;
}
if ( V_4 != 0 && V_29 == 0 ) {
struct V_1 * V_32 , * V_33 ;
int V_34 = 0 ;
F_15 ( L_6 ) ;
if ( V_25 -> V_35 ) {
T_2 V_36 = 0 ;
V_29 = V_25 -> V_29 ;
V_32 = V_25 ;
F_18 (grp_iter,
&iop_chan->chain, chain_node) {
V_36 |=
F_19 ( V_32 ) ;
F_15 ( L_7 ,
V_32 -> V_22 , V_36 ) ;
V_29 -= V_4 ;
if ( V_29 == 0 )
break;
}
F_15 ( L_8 ,
V_25 -> V_35 ) ;
* V_25 -> V_35 = V_36 ;
}
V_29 = V_25 -> V_29 ;
V_32 = V_25 ;
F_20 (grp_iter, _grp_iter,
&iop_chan->chain, chain_node) {
V_10 = F_3 (
V_32 , V_9 , V_10 ) ;
V_29 -= V_4 ;
V_34 = F_7 ( V_32 ,
V_9 ) ;
if ( V_29 == 0 || V_34 )
break;
}
F_4 ( V_29 ) ;
V_4 = 0 ;
V_25 = NULL ;
if ( V_34 )
break;
else
continue;
} else if ( V_4 )
continue;
if ( V_23 -> V_35 && V_23 -> V_13 . V_10 )
* V_23 -> V_35 =
F_19 ( V_23 ) ;
V_10 = F_3 (
V_23 , V_9 , V_10 ) ;
if ( F_7 ( V_23 , V_9 ) )
break;
}
if ( V_10 > 0 ) {
V_9 -> V_20 . V_37 = V_10 ;
F_15 ( L_9 , V_10 ) ;
}
}
static void
F_21 ( struct V_8 * V_9 )
{
F_22 ( & V_9 -> V_38 ) ;
F_11 ( V_9 ) ;
F_23 ( & V_9 -> V_38 ) ;
}
static void F_24 ( unsigned long V_39 )
{
struct V_8 * V_9 = (struct V_8 * ) V_39 ;
F_25 ( & V_9 -> V_38 , V_40 ) ;
F_11 ( V_9 ) ;
F_26 ( & V_9 -> V_38 ) ;
}
static struct V_1 *
F_27 ( struct V_8 * V_9 , int V_41 ,
int V_4 )
{
struct V_1 * V_23 , * V_24 , * V_42 = NULL ;
F_28 ( V_18 ) ;
int V_43 , V_44 = 0 ;
V_44:
V_43 = 0 ;
if ( V_44 == 0 )
V_23 = V_9 -> V_45 ;
else
V_23 = F_2 ( & V_9 -> V_46 ,
struct V_1 ,
V_5 ) ;
F_29 (
iter, _iter, &iop_chan->all_slots, slot_node) {
F_17 ( V_24 ) ;
F_17 ( & V_24 -> V_13 ) ;
if ( V_23 -> V_4 ) {
if ( V_44 )
break;
V_43 = 0 ;
continue;
}
if ( ! V_43 ++ ) {
if ( F_30 ( V_23 , V_4 ) )
V_42 = V_23 ;
else {
V_43 = 0 ;
continue;
}
}
if ( V_43 == V_41 ) {
struct V_1 * V_47 = NULL ;
struct V_1 * V_45 = NULL ;
V_23 = V_42 ;
while ( V_41 ) {
int V_48 ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 ,
L_10
L_11 ,
V_23 -> V_22 , V_23 -> V_49 ,
V_23 -> V_13 . V_31 , V_4 ) ;
if ( V_41 != V_4 )
F_31 ( & V_23 -> V_13 ) ;
F_32 ( & V_23 -> V_17 , & V_18 ) ;
V_47 = V_23 ;
V_23 -> V_13 . V_10 = 0 ;
V_23 -> V_29 = V_41 ;
V_23 -> V_35 = NULL ;
for ( V_48 = 0 ; V_48 < V_4 ; V_48 ++ ) {
V_23 -> V_4 = V_4 - V_48 ;
V_45 = V_23 ;
V_23 = F_2 ( V_23 -> V_5 . V_6 ,
struct V_1 ,
V_5 ) ;
}
V_41 -= V_4 ;
}
V_47 -> V_16 = V_42 ;
V_47 -> V_13 . V_10 = - V_50 ;
F_33 ( & V_18 , & V_47 -> V_51 ) ;
V_9 -> V_45 = V_45 ;
F_34 ( V_42 ) ;
F_34 ( V_47 ) ;
return V_47 ;
}
}
if ( ! V_44 ++ )
goto V_44;
F_11 ( V_9 ) ;
return NULL ;
}
static void F_35 ( struct V_8 * V_9 )
{
F_9 ( V_9 -> V_19 -> V_20 . V_21 , L_12 ,
V_9 -> V_52 ) ;
if ( V_9 -> V_52 >= V_53 ) {
V_9 -> V_52 = 0 ;
F_36 ( V_9 ) ;
}
}
static T_1
F_37 ( struct V_11 * V_12 )
{
struct V_1 * V_54 = F_38 ( V_12 ) ;
struct V_8 * V_9 = F_39 ( V_12 -> V_55 ) ;
struct V_1 * V_25 , * V_56 ;
int V_29 ;
int V_4 ;
T_1 V_10 ;
T_3 V_57 ;
V_25 = V_54 -> V_16 ;
V_29 = V_25 -> V_29 ;
V_4 = V_25 -> V_4 ;
F_22 ( & V_9 -> V_38 ) ;
V_10 = F_40 ( V_12 ) ;
V_56 = F_2 ( V_9 -> V_18 . V_58 ,
struct V_1 , V_17 ) ;
F_41 ( & V_54 -> V_51 ,
& V_56 -> V_17 ) ;
V_57 = V_25 -> V_13 . V_31 ;
F_42 ( V_56 , V_57 ) ;
F_4 ( F_16 ( V_56 ) != V_57 ) ;
F_43 ( F_16 ( V_54 ) ) ;
V_9 -> V_52 += V_29 ;
F_35 ( V_9 ) ;
F_23 ( & V_9 -> V_38 ) ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 , L_13 ,
V_30 , V_54 -> V_13 . V_10 , V_54 -> V_22 ) ;
return V_10 ;
}
static int F_44 ( struct V_59 * V_55 )
{
char * V_49 ;
int V_22 ;
struct V_8 * V_9 = F_39 ( V_55 ) ;
struct V_1 * V_2 = NULL ;
int V_60 = V_9 -> V_61 ? 0 : 1 ;
struct V_62 * V_63 =
F_45 ( & V_9 -> V_19 -> V_64 -> V_21 ) ;
int V_65 = V_63 -> V_66 / V_67 ;
do {
V_22 = V_9 -> V_61 ;
if ( V_22 == V_65 )
break;
V_2 = F_46 ( sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 ) {
F_47 ( V_69 L_14
L_15 , V_22 ) ;
break;
}
V_49 = ( char * ) V_9 -> V_19 -> V_70 ;
V_2 -> V_49 = ( void * ) & V_49 [ V_22 * V_67 ] ;
F_48 ( & V_2 -> V_13 , V_55 ) ;
V_2 -> V_13 . V_71 = F_37 ;
F_49 ( & V_2 -> V_51 ) ;
F_49 ( & V_2 -> V_17 ) ;
F_49 ( & V_2 -> V_5 ) ;
V_49 = ( char * ) V_9 -> V_19 -> V_72 ;
V_2 -> V_13 . V_31 =
( T_3 ) & V_49 [ V_22 * V_67 ] ;
V_2 -> V_22 = V_22 ;
F_22 ( & V_9 -> V_38 ) ;
V_9 -> V_61 ++ ;
F_32 ( & V_2 -> V_5 , & V_9 -> V_46 ) ;
F_23 ( & V_9 -> V_38 ) ;
} while ( V_9 -> V_61 < V_65 );
if ( V_22 && ! V_9 -> V_45 )
V_9 -> V_45 = F_2 ( V_9 -> V_46 . V_6 ,
struct V_1 ,
V_5 ) ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 ,
L_16 ,
V_9 -> V_61 , V_9 -> V_45 ) ;
if ( V_60 ) {
if ( F_50 ( V_73 ,
V_9 -> V_19 -> V_20 . V_74 ) )
F_51 ( V_9 ) ;
else if ( F_50 ( V_75 ,
V_9 -> V_19 -> V_20 . V_74 ) )
F_52 ( V_9 ) ;
else
F_53 () ;
}
return ( V_22 > 0 ) ? V_22 : - V_76 ;
}
static struct V_11 *
F_54 ( struct V_59 * V_55 , unsigned long V_77 )
{
struct V_8 * V_9 = F_39 ( V_55 ) ;
struct V_1 * V_54 , * V_25 ;
int V_29 , V_4 ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 , L_2 , V_30 ) ;
F_22 ( & V_9 -> V_38 ) ;
V_29 = F_55 ( & V_4 , V_9 ) ;
V_54 = F_27 ( V_9 , V_29 , V_4 ) ;
if ( V_54 ) {
V_25 = V_54 -> V_16 ;
F_56 ( V_25 , V_9 ) ;
V_54 -> V_13 . V_77 = V_77 ;
}
F_23 ( & V_9 -> V_38 ) ;
return V_54 ? & V_54 -> V_13 : NULL ;
}
static struct V_11 *
F_57 ( struct V_59 * V_55 , T_3 V_78 ,
T_3 V_79 , T_4 V_80 , unsigned long V_77 )
{
struct V_8 * V_9 = F_39 ( V_55 ) ;
struct V_1 * V_54 , * V_25 ;
int V_29 , V_4 ;
if ( F_58 ( ! V_80 ) )
return NULL ;
F_4 ( V_80 > V_81 ) ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 , L_17 ,
V_30 , V_80 ) ;
F_22 ( & V_9 -> V_38 ) ;
V_29 = F_59 ( V_80 , & V_4 ) ;
V_54 = F_27 ( V_9 , V_29 , V_4 ) ;
if ( V_54 ) {
V_25 = V_54 -> V_16 ;
F_60 ( V_25 , V_77 ) ;
F_61 ( V_25 , V_9 , V_80 ) ;
F_62 ( V_25 , V_9 , V_78 ) ;
F_63 ( V_25 , V_79 ) ;
V_54 -> V_13 . V_77 = V_77 ;
}
F_23 ( & V_9 -> V_38 ) ;
return V_54 ? & V_54 -> V_13 : NULL ;
}
static struct V_11 *
F_64 ( struct V_59 * V_55 , T_3 V_78 ,
T_3 * V_79 , unsigned int V_82 , T_4 V_80 ,
unsigned long V_77 )
{
struct V_8 * V_9 = F_39 ( V_55 ) ;
struct V_1 * V_54 , * V_25 ;
int V_29 , V_4 ;
if ( F_58 ( ! V_80 ) )
return NULL ;
F_4 ( V_80 > V_83 ) ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 ,
L_18 ,
V_30 , V_82 , V_80 , V_77 ) ;
F_22 ( & V_9 -> V_38 ) ;
V_29 = F_65 ( V_80 , V_82 , & V_4 ) ;
V_54 = F_27 ( V_9 , V_29 , V_4 ) ;
if ( V_54 ) {
V_25 = V_54 -> V_16 ;
F_66 ( V_25 , V_82 , V_77 ) ;
F_61 ( V_25 , V_9 , V_80 ) ;
F_62 ( V_25 , V_9 , V_78 ) ;
V_54 -> V_13 . V_77 = V_77 ;
while ( V_82 -- )
F_67 ( V_25 , V_82 ,
V_79 [ V_82 ] ) ;
}
F_23 ( & V_9 -> V_38 ) ;
return V_54 ? & V_54 -> V_13 : NULL ;
}
static struct V_11 *
F_68 ( struct V_59 * V_55 , T_3 * V_79 ,
unsigned int V_82 , T_4 V_80 , T_2 * V_84 ,
unsigned long V_77 )
{
struct V_8 * V_9 = F_39 ( V_55 ) ;
struct V_1 * V_54 , * V_25 ;
int V_29 , V_4 ;
if ( F_58 ( ! V_80 ) )
return NULL ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 , L_19 ,
V_30 , V_82 , V_80 ) ;
F_22 ( & V_9 -> V_38 ) ;
V_29 = F_69 ( V_80 , V_82 , & V_4 ) ;
V_54 = F_27 ( V_9 , V_29 , V_4 ) ;
if ( V_54 ) {
V_25 = V_54 -> V_16 ;
F_70 ( V_25 , V_82 , V_77 ) ;
F_71 ( V_25 , V_80 ) ;
V_25 -> V_35 = V_84 ;
F_15 ( L_20 ,
V_30 , V_25 -> V_35 ) ;
V_54 -> V_13 . V_77 = V_77 ;
while ( V_82 -- )
F_72 ( V_25 , V_82 ,
V_79 [ V_82 ] ) ;
}
F_23 ( & V_9 -> V_38 ) ;
return V_54 ? & V_54 -> V_13 : NULL ;
}
static struct V_11 *
F_73 ( struct V_59 * V_55 , T_3 * V_85 , T_3 * V_86 ,
unsigned int V_82 , const unsigned char * V_87 , T_4 V_80 ,
unsigned long V_77 )
{
struct V_8 * V_9 = F_39 ( V_55 ) ;
struct V_1 * V_54 , * V_88 ;
int V_29 , V_4 ;
int V_89 ;
if ( F_58 ( ! V_80 ) )
return NULL ;
F_4 ( V_80 > V_83 ) ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 ,
L_18 ,
V_30 , V_82 , V_80 , V_77 ) ;
if ( F_74 ( V_77 ) )
V_89 = 1 + V_82 ;
else if ( F_75 ( V_77 ) )
V_89 = 3 + V_82 ;
else
V_89 = 0 + V_82 ;
F_22 ( & V_9 -> V_38 ) ;
V_29 = F_76 ( V_80 , V_89 , & V_4 ) ;
V_54 = F_27 ( V_9 , V_29 , V_4 ) ;
if ( V_54 ) {
int V_48 ;
V_88 = V_54 -> V_16 ;
F_61 ( V_88 , V_9 , V_80 ) ;
if ( V_77 & V_90 )
V_85 [ 0 ] = V_85 [ 1 ] & 0x7 ;
F_77 ( V_88 , V_85 ) ;
V_54 -> V_13 . V_77 = V_77 ;
for ( V_48 = 0 ; V_48 < V_82 ; V_48 ++ )
F_78 ( V_88 , V_48 , V_86 [ V_48 ] , V_87 [ V_48 ] ) ;
if ( F_74 ( V_77 ) )
F_78 ( V_88 , V_48 ++ , V_85 [ 1 ] , 1 ) ;
else if ( F_75 ( V_77 ) ) {
F_78 ( V_88 , V_48 ++ , V_85 [ 0 ] , 0 ) ;
F_78 ( V_88 , V_48 ++ , V_85 [ 1 ] , 1 ) ;
F_78 ( V_88 , V_48 ++ , V_85 [ 1 ] , 0 ) ;
}
F_79 ( V_88 , V_48 , V_77 ) ;
}
F_23 ( & V_9 -> V_38 ) ;
return V_54 ? & V_54 -> V_13 : NULL ;
}
static struct V_11 *
F_80 ( struct V_59 * V_55 , T_3 * V_91 , T_3 * V_86 ,
unsigned int V_82 , const unsigned char * V_87 ,
T_4 V_80 , enum V_92 * V_93 ,
unsigned long V_77 )
{
struct V_8 * V_9 = F_39 ( V_55 ) ;
struct V_1 * V_54 , * V_88 ;
int V_29 , V_4 ;
if ( F_58 ( ! V_80 ) )
return NULL ;
F_4 ( V_80 > V_83 ) ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 , L_19 ,
V_30 , V_82 , V_80 ) ;
F_22 ( & V_9 -> V_38 ) ;
V_29 = F_81 ( V_80 , V_82 + 2 , & V_4 ) ;
V_54 = F_27 ( V_9 , V_29 , V_4 ) ;
if ( V_54 ) {
int V_94 = V_82 ;
V_88 = V_54 -> V_16 ;
F_82 ( V_88 , V_82 + 2 , V_77 ) ;
F_83 ( V_88 , V_80 ) ;
V_88 -> V_95 = V_93 ;
F_15 ( L_21 ,
V_30 , V_88 -> V_95 ) ;
V_54 -> V_13 . V_77 = V_77 ;
while ( V_82 -- )
F_84 ( V_88 , V_82 ,
V_86 [ V_82 ] ,
V_87 [ V_82 ] ) ;
F_85 ( V_88 , V_94 , V_86 ) ;
}
F_23 ( & V_9 -> V_38 ) ;
return V_54 ? & V_54 -> V_13 : NULL ;
}
static void F_86 ( struct V_59 * V_55 )
{
struct V_8 * V_9 = F_39 ( V_55 ) ;
struct V_1 * V_23 , * V_24 ;
int V_96 = 0 ;
F_21 ( V_9 ) ;
F_22 ( & V_9 -> V_38 ) ;
F_14 (iter, _iter, &iop_chan->chain,
chain_node) {
V_96 ++ ;
F_10 ( & V_23 -> V_17 ) ;
}
F_87 (
iter, _iter, &iop_chan->all_slots, slot_node) {
F_10 ( & V_23 -> V_5 ) ;
F_88 ( V_23 ) ;
V_9 -> V_61 -- ;
}
V_9 -> V_45 = NULL ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 , L_22 ,
V_30 , V_9 -> V_61 ) ;
F_23 ( & V_9 -> V_38 ) ;
if ( V_96 > 1 )
F_47 ( V_97 L_23 ,
V_96 - 1 ) ;
}
static enum V_98 F_89 ( struct V_59 * V_55 ,
T_1 V_10 ,
struct V_99 * V_100 )
{
struct V_8 * V_9 = F_39 ( V_55 ) ;
int V_101 ;
V_101 = F_90 ( V_55 , V_10 , V_100 ) ;
if ( V_101 == V_102 )
return V_101 ;
F_21 ( V_9 ) ;
return F_90 ( V_55 , V_10 , V_100 ) ;
}
static T_5 F_91 ( int V_103 , void * V_39 )
{
struct V_8 * V_55 = V_39 ;
F_9 ( V_55 -> V_19 -> V_20 . V_21 , L_2 , V_30 ) ;
F_92 ( & V_55 -> V_104 ) ;
F_93 ( V_55 ) ;
return V_105 ;
}
static T_5 F_94 ( int V_103 , void * V_39 )
{
struct V_8 * V_55 = V_39 ;
F_9 ( V_55 -> V_19 -> V_20 . V_21 , L_2 , V_30 ) ;
F_92 ( & V_55 -> V_104 ) ;
F_95 ( V_55 ) ;
return V_105 ;
}
static T_5 F_96 ( int V_103 , void * V_39 )
{
struct V_8 * V_55 = V_39 ;
unsigned long V_106 = F_97 ( V_55 ) ;
F_98 ( V_55 -> V_19 -> V_20 . V_21 ,
L_24 ,
F_99 ( V_106 , V_55 ) ? L_25 : L_26 ,
F_100 ( V_106 , V_55 ) ? L_27 : L_26 ,
F_101 ( V_106 , V_55 ) ? L_28 : L_26 ,
F_102 ( V_106 , V_55 ) ? L_29 : L_26 ,
F_103 ( V_106 , V_55 ) ? L_30 : L_26 ,
F_104 ( V_106 , V_55 ) ? L_31 : L_26 ,
F_105 ( V_106 , V_55 ) ? L_32 : L_26 ) ;
F_106 ( V_55 ) ;
F_53 () ;
return V_105 ;
}
static void F_107 ( struct V_59 * V_55 )
{
struct V_8 * V_9 = F_39 ( V_55 ) ;
if ( V_9 -> V_52 ) {
V_9 -> V_52 = 0 ;
F_36 ( V_9 ) ;
}
}
static int F_108 ( struct V_107 * V_19 )
{
int V_48 ;
void * V_86 , * V_108 ;
T_3 V_109 , V_110 ;
struct V_59 * V_59 ;
T_1 V_10 ;
struct V_11 * V_12 ;
int V_111 = 0 ;
struct V_8 * V_9 ;
F_9 ( V_19 -> V_20 . V_21 , L_2 , V_30 ) ;
V_86 = F_109 ( V_112 , V_68 ) ;
if ( ! V_86 )
return - V_76 ;
V_108 = F_46 ( V_112 , V_68 ) ;
if ( ! V_108 ) {
F_88 ( V_86 ) ;
return - V_76 ;
}
for ( V_48 = 0 ; V_48 < V_112 ; V_48 ++ )
( ( V_113 * ) V_86 ) [ V_48 ] = ( V_113 ) V_48 ;
V_59 = F_110 ( V_19 -> V_20 . V_114 . V_6 ,
struct V_59 ,
V_115 ) ;
if ( F_44 ( V_59 ) < 1 ) {
V_111 = - V_116 ;
goto V_117;
}
V_110 = F_111 ( V_59 -> V_19 -> V_21 , V_108 ,
V_112 , V_118 ) ;
V_109 = F_111 ( V_59 -> V_19 -> V_21 , V_86 ,
V_112 , V_119 ) ;
V_12 = F_57 ( V_59 , V_110 , V_109 ,
V_112 ,
V_120 | V_121 ) ;
V_10 = F_37 ( V_12 ) ;
F_107 ( V_59 ) ;
F_112 ( 1 ) ;
if ( F_89 ( V_59 , V_10 , NULL ) !=
V_102 ) {
F_98 ( V_59 -> V_19 -> V_21 ,
L_33 ) ;
V_111 = - V_116 ;
goto V_122;
}
V_9 = F_39 ( V_59 ) ;
F_113 ( & V_9 -> V_19 -> V_64 -> V_21 , V_110 ,
V_112 , V_118 ) ;
if ( memcmp ( V_86 , V_108 , V_112 ) ) {
F_98 ( V_59 -> V_19 -> V_21 ,
L_34 ) ;
V_111 = - V_116 ;
goto V_122;
}
V_122:
F_86 ( V_59 ) ;
V_117:
F_88 ( V_86 ) ;
F_88 ( V_108 ) ;
return V_111 ;
}
static int
F_114 ( struct V_107 * V_19 )
{
int V_48 , V_123 ;
struct V_124 * V_108 ;
struct V_124 * V_125 [ V_126 ] ;
struct V_124 * V_127 [ V_126 + 1 ] ;
T_3 V_128 [ V_126 + 1 ] ;
T_3 V_110 ;
struct V_11 * V_12 ;
struct V_59 * V_59 ;
T_1 V_10 ;
V_113 V_129 = 0 ;
T_2 V_130 ;
T_2 V_36 ;
int V_111 = 0 ;
struct V_8 * V_9 ;
F_9 ( V_19 -> V_20 . V_21 , L_2 , V_30 ) ;
for ( V_123 = 0 ; V_123 < V_126 ; V_123 ++ ) {
V_125 [ V_123 ] = F_115 ( V_68 ) ;
if ( ! V_125 [ V_123 ] ) {
while ( V_123 -- )
F_116 ( V_125 [ V_123 ] ) ;
return - V_76 ;
}
}
V_108 = F_115 ( V_68 ) ;
if ( ! V_108 ) {
while ( V_123 -- )
F_116 ( V_125 [ V_123 ] ) ;
return - V_76 ;
}
for ( V_123 = 0 ; V_123 < V_126 ; V_123 ++ ) {
V_113 * V_131 = F_117 ( V_125 [ V_123 ] ) ;
for ( V_48 = 0 ; V_48 < V_132 ; V_48 ++ )
V_131 [ V_48 ] = ( 1 << V_123 ) ;
}
for ( V_123 = 0 ; V_123 < V_126 ; V_123 ++ )
V_129 ^= ( V_113 ) ( 1 << V_123 ) ;
V_130 = ( V_129 << 24 ) | ( V_129 << 16 ) |
( V_129 << 8 ) | V_129 ;
memset ( F_117 ( V_108 ) , 0 , V_132 ) ;
V_59 = F_110 ( V_19 -> V_20 . V_114 . V_6 ,
struct V_59 ,
V_115 ) ;
if ( F_44 ( V_59 ) < 1 ) {
V_111 = - V_116 ;
goto V_117;
}
V_110 = F_118 ( V_59 -> V_19 -> V_21 , V_108 , 0 ,
V_132 , V_118 ) ;
for ( V_48 = 0 ; V_48 < V_126 ; V_48 ++ )
V_128 [ V_48 ] = F_118 ( V_59 -> V_19 -> V_21 , V_125 [ V_48 ] ,
0 , V_132 , V_119 ) ;
V_12 = F_64 ( V_59 , V_110 , V_128 ,
V_126 , V_132 ,
V_120 | V_121 ) ;
V_10 = F_37 ( V_12 ) ;
F_107 ( V_59 ) ;
F_112 ( 8 ) ;
if ( F_89 ( V_59 , V_10 , NULL ) !=
V_102 ) {
F_98 ( V_59 -> V_19 -> V_21 ,
L_35 ) ;
V_111 = - V_116 ;
goto V_122;
}
V_9 = F_39 ( V_59 ) ;
F_113 ( & V_9 -> V_19 -> V_64 -> V_21 , V_110 ,
V_132 , V_118 ) ;
for ( V_48 = 0 ; V_48 < ( V_132 / sizeof( T_2 ) ) ; V_48 ++ ) {
T_2 * V_131 = F_117 ( V_108 ) ;
if ( V_131 [ V_48 ] != V_130 ) {
F_98 ( V_59 -> V_19 -> V_21 ,
L_36 ) ;
V_111 = - V_116 ;
goto V_122;
}
}
F_119 ( & V_9 -> V_19 -> V_64 -> V_21 , V_110 ,
V_132 , V_119 ) ;
if ( ! F_50 ( V_133 , V_59 -> V_19 -> V_74 ) )
goto V_122;
for ( V_48 = 0 ; V_48 < V_126 ; V_48 ++ )
V_127 [ V_48 ] = V_125 [ V_48 ] ;
V_127 [ V_48 ] = V_108 ;
V_36 = 1 ;
for ( V_48 = 0 ; V_48 < V_126 + 1 ; V_48 ++ )
V_128 [ V_48 ] = F_118 ( V_59 -> V_19 -> V_21 ,
V_127 [ V_48 ] , 0 , V_132 ,
V_119 ) ;
V_12 = F_68 ( V_59 , V_128 ,
V_126 + 1 , V_132 ,
& V_36 ,
V_120 | V_121 ) ;
V_10 = F_37 ( V_12 ) ;
F_107 ( V_59 ) ;
F_112 ( 8 ) ;
if ( F_89 ( V_59 , V_10 , NULL ) != V_102 ) {
F_98 ( V_59 -> V_19 -> V_21 ,
L_37 ) ;
V_111 = - V_116 ;
goto V_122;
}
if ( V_36 != 0 ) {
F_98 ( V_59 -> V_19 -> V_21 ,
L_38 ) ;
V_111 = - V_116 ;
goto V_122;
}
V_36 = 0 ;
for ( V_48 = 0 ; V_48 < V_126 + 1 ; V_48 ++ )
V_128 [ V_48 ] = F_118 ( V_59 -> V_19 -> V_21 ,
V_127 [ V_48 ] , 0 , V_132 ,
V_119 ) ;
V_12 = F_68 ( V_59 , V_128 ,
V_126 + 1 , V_132 ,
& V_36 ,
V_120 | V_121 ) ;
V_10 = F_37 ( V_12 ) ;
F_107 ( V_59 ) ;
F_112 ( 8 ) ;
if ( F_89 ( V_59 , V_10 , NULL ) != V_102 ) {
F_98 ( V_59 -> V_19 -> V_21 ,
L_39 ) ;
V_111 = - V_116 ;
goto V_122;
}
if ( V_36 != 1 ) {
F_98 ( V_59 -> V_19 -> V_21 ,
L_40 ) ;
V_111 = - V_116 ;
goto V_122;
}
V_122:
F_86 ( V_59 ) ;
V_117:
V_123 = V_126 ;
while ( V_123 -- )
F_116 ( V_125 [ V_123 ] ) ;
F_116 ( V_108 ) ;
return V_111 ;
}
static int
F_120 ( struct V_107 * V_19 )
{
struct V_124 * V_91 [ V_126 + 2 + 2 ] ;
struct V_124 * * V_134 = & V_91 [ V_126 + 2 ] ;
void * V_135 [ V_126 + 2 ] ;
T_3 V_136 [ V_126 + 2 ] ;
T_3 * V_137 = & V_136 [ V_126 ] ;
int V_48 ;
struct V_11 * V_12 ;
struct V_59 * V_59 ;
T_1 V_10 ;
T_2 V_36 ;
int V_111 = 0 ;
struct V_19 * V_21 ;
F_9 ( V_19 -> V_20 . V_21 , L_2 , V_30 ) ;
for ( V_48 = 0 ; V_48 < F_121 ( V_91 ) ; V_48 ++ ) {
V_91 [ V_48 ] = F_115 ( V_68 ) ;
if ( ! V_91 [ V_48 ] ) {
while ( V_48 -- )
F_116 ( V_91 [ V_48 ] ) ;
return - V_76 ;
}
}
for ( V_48 = 0 ; V_48 < V_126 ; V_48 ++ ) {
V_135 [ V_48 ] = F_117 ( V_91 [ V_48 ] ) ;
memset ( V_135 [ V_48 ] , 0x11111111 * ( 1 << V_48 ) , V_132 ) ;
}
V_135 [ V_48 ] = F_117 ( V_91 [ V_48 ] ) ;
V_135 [ V_48 + 1 ] = F_117 ( V_91 [ V_48 + 1 ] ) ;
V_59 = F_110 ( V_19 -> V_20 . V_114 . V_6 ,
struct V_59 ,
V_115 ) ;
if ( F_44 ( V_59 ) < 1 ) {
V_111 = - V_116 ;
goto V_117;
}
V_21 = V_59 -> V_19 -> V_21 ;
memset ( F_117 ( V_134 [ 0 ] ) , 0 , V_132 ) ;
memset ( F_117 ( V_134 [ 1 ] ) , 0 , V_132 ) ;
V_137 [ 0 ] = F_118 ( V_21 , V_134 [ 0 ] , 0 , V_132 , V_118 ) ;
V_137 [ 1 ] = F_118 ( V_21 , V_134 [ 1 ] , 0 , V_132 , V_118 ) ;
for ( V_48 = 0 ; V_48 < V_126 ; V_48 ++ )
V_136 [ V_48 ] = F_118 ( V_21 , V_91 [ V_48 ] , 0 , V_132 ,
V_119 ) ;
V_12 = F_73 ( V_59 , V_137 , V_136 ,
V_126 , ( V_113 * ) V_138 ,
V_132 ,
V_120 |
V_121 ) ;
V_10 = F_37 ( V_12 ) ;
F_107 ( V_59 ) ;
F_112 ( 8 ) ;
if ( F_89 ( V_59 , V_10 , NULL ) !=
V_102 ) {
F_98 ( V_21 , L_41 ) ;
V_111 = - V_116 ;
goto V_122;
}
V_139 . V_140 ( V_126 + 2 , V_132 , V_135 ) ;
if ( memcmp ( V_135 [ V_126 ] ,
F_117 ( V_134 [ 0 ] ) , V_132 ) != 0 ) {
F_98 ( V_21 , L_42 ) ;
V_111 = - V_116 ;
goto V_122;
}
if ( memcmp ( V_135 [ V_126 + 1 ] ,
F_117 ( V_134 [ 1 ] ) , V_132 ) != 0 ) {
F_98 ( V_21 , L_43 ) ;
V_111 = - V_116 ;
goto V_122;
}
for ( V_48 = 0 ; V_48 < V_126 + 2 ; V_48 ++ )
V_136 [ V_48 ] = F_118 ( V_21 , V_91 [ V_48 ] , 0 , V_132 ,
V_119 ) ;
V_36 = ~ 0 ;
V_12 = F_80 ( V_59 , & V_136 [ V_126 ] ,
V_136 , V_126 ,
V_138 , V_132 , & V_36 ,
V_120 | V_121 ) ;
V_10 = F_37 ( V_12 ) ;
F_107 ( V_59 ) ;
F_112 ( 8 ) ;
if ( F_89 ( V_59 , V_10 , NULL ) !=
V_102 ) {
F_98 ( V_21 , L_44 ) ;
V_111 = - V_116 ;
goto V_122;
}
if ( V_36 != 0 ) {
F_98 ( V_21 , L_45 ,
V_36 ) ;
V_111 = - V_116 ;
goto V_122;
}
V_48 = V_126 ;
memset ( V_135 [ V_48 ] + 100 , 0 , 100 ) ;
memset ( V_135 [ V_48 + 1 ] + 200 , 0 , 200 ) ;
for ( V_48 = 0 ; V_48 < V_126 + 2 ; V_48 ++ )
V_136 [ V_48 ] = F_118 ( V_21 , V_91 [ V_48 ] , 0 , V_132 ,
V_119 ) ;
V_36 = 0 ;
V_12 = F_80 ( V_59 , & V_136 [ V_126 ] ,
V_136 , V_126 ,
V_138 , V_132 , & V_36 ,
V_120 | V_121 ) ;
V_10 = F_37 ( V_12 ) ;
F_107 ( V_59 ) ;
F_112 ( 8 ) ;
if ( F_89 ( V_59 , V_10 , NULL ) !=
V_102 ) {
F_98 ( V_21 , L_46 ) ;
V_111 = - V_116 ;
goto V_122;
}
if ( V_36 != ( V_141 | V_142 ) ) {
F_98 ( V_21 , L_47 ,
V_36 ) ;
V_111 = - V_116 ;
goto V_122;
}
V_122:
F_86 ( V_59 ) ;
V_117:
V_48 = F_121 ( V_91 ) ;
while ( V_48 -- )
F_116 ( V_91 [ V_48 ] ) ;
return V_111 ;
}
static int F_122 ( struct V_143 * V_21 )
{
struct V_107 * V_19 = F_123 ( V_21 ) ;
struct V_59 * V_55 , * V_144 ;
struct V_8 * V_9 ;
struct V_62 * V_63 = F_45 ( & V_21 -> V_21 ) ;
F_124 ( & V_19 -> V_20 ) ;
F_125 ( & V_21 -> V_21 , V_63 -> V_66 ,
V_19 -> V_70 , V_19 -> V_72 ) ;
F_14 (chan, _chan, &device->common.channels,
device_node) {
V_9 = F_39 ( V_55 ) ;
F_10 ( & V_55 -> V_115 ) ;
F_88 ( V_9 ) ;
}
F_88 ( V_19 ) ;
return 0 ;
}
static int F_126 ( struct V_143 * V_64 )
{
struct V_145 * V_146 ;
int V_101 = 0 , V_48 ;
struct V_107 * V_147 ;
struct V_8 * V_9 ;
struct V_148 * V_149 ;
struct V_62 * V_63 = F_45 ( & V_64 -> V_21 ) ;
V_146 = F_127 ( V_64 , V_150 , 0 ) ;
if ( ! V_146 )
return - V_116 ;
if ( ! F_128 ( & V_64 -> V_21 , V_146 -> V_151 ,
F_129 ( V_146 ) , V_64 -> V_152 ) )
return - V_50 ;
V_147 = F_46 ( sizeof( * V_147 ) , V_68 ) ;
if ( ! V_147 )
return - V_76 ;
V_149 = & V_147 -> V_20 ;
V_147 -> V_70 = F_130 ( & V_64 -> V_21 ,
V_63 -> V_66 ,
& V_147 -> V_72 ,
V_68 ) ;
if ( ! V_147 -> V_70 ) {
V_101 = - V_76 ;
goto V_153;
}
F_9 ( & V_64 -> V_21 , L_48 ,
V_30 , V_147 -> V_70 ,
( void * ) V_147 -> V_72 ) ;
V_147 -> V_154 = V_63 -> V_155 ;
V_149 -> V_74 = V_63 -> V_74 ;
V_147 -> V_64 = V_64 ;
F_131 ( V_64 , V_147 ) ;
F_49 ( & V_149 -> V_114 ) ;
V_149 -> V_156 = F_44 ;
V_149 -> V_157 = F_86 ;
V_149 -> V_158 = F_89 ;
V_149 -> V_159 = F_107 ;
V_149 -> V_21 = & V_64 -> V_21 ;
if ( F_50 ( V_73 , V_149 -> V_74 ) )
V_149 -> V_160 = F_57 ;
if ( F_50 ( V_75 , V_149 -> V_74 ) ) {
V_149 -> V_161 = F_132 () ;
V_149 -> V_162 = F_64 ;
}
if ( F_50 ( V_133 , V_149 -> V_74 ) )
V_149 -> V_163 =
F_68 ;
if ( F_50 ( V_164 , V_149 -> V_74 ) ) {
F_133 ( V_149 , F_134 () , 0 ) ;
V_149 -> V_165 = F_73 ;
}
if ( F_50 ( V_166 , V_149 -> V_74 ) )
V_149 -> V_167 =
F_80 ;
if ( F_50 ( V_168 , V_149 -> V_74 ) )
V_149 -> V_169 =
F_54 ;
V_9 = F_46 ( sizeof( * V_9 ) , V_68 ) ;
if ( ! V_9 ) {
V_101 = - V_76 ;
goto V_170;
}
V_9 -> V_19 = V_147 ;
V_9 -> V_171 = F_135 ( & V_64 -> V_21 , V_146 -> V_151 ,
F_129 ( V_146 ) ) ;
if ( ! V_9 -> V_171 ) {
V_101 = - V_76 ;
goto V_172;
}
F_136 ( & V_9 -> V_104 , F_24 , ( unsigned long )
V_9 ) ;
F_106 ( V_9 ) ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
T_6 V_173 [] = { F_91 ,
F_94 ,
F_96 } ;
int V_103 = F_137 ( V_64 , V_48 ) ;
if ( V_103 < 0 ) {
V_101 = - V_174 ;
goto V_172;
} else {
V_101 = F_138 ( & V_64 -> V_21 , V_103 ,
V_173 [ V_48 ] , 0 , V_64 -> V_152 , V_9 ) ;
if ( V_101 )
goto V_172;
}
}
F_139 ( & V_9 -> V_38 ) ;
F_49 ( & V_9 -> V_18 ) ;
F_49 ( & V_9 -> V_46 ) ;
V_9 -> V_20 . V_19 = V_149 ;
F_140 ( & V_9 -> V_20 ) ;
F_32 ( & V_9 -> V_20 . V_115 , & V_149 -> V_114 ) ;
if ( F_50 ( V_73 , V_149 -> V_74 ) ) {
V_101 = F_108 ( V_147 ) ;
F_9 ( & V_64 -> V_21 , L_49 , V_101 ) ;
if ( V_101 )
goto V_172;
}
if ( F_50 ( V_75 , V_149 -> V_74 ) ) {
V_101 = F_114 ( V_147 ) ;
F_9 ( & V_64 -> V_21 , L_50 , V_101 ) ;
if ( V_101 )
goto V_172;
}
if ( F_50 ( V_164 , V_149 -> V_74 ) &&
F_50 ( V_166 , V_149 -> V_74 ) ) {
#ifdef F_141
V_101 = F_120 ( V_147 ) ;
F_9 ( & V_64 -> V_21 , L_51 , V_101 ) ;
#else
F_142 ( V_164 , V_149 -> V_74 ) ;
F_142 ( V_166 , V_149 -> V_74 ) ;
V_101 = 0 ;
#endif
if ( V_101 )
goto V_172;
}
F_143 ( & V_64 -> V_21 , L_52 ,
F_50 ( V_164 , V_149 -> V_74 ) ? L_53 : L_26 ,
F_50 ( V_166 , V_149 -> V_74 ) ? L_54 : L_26 ,
F_50 ( V_75 , V_149 -> V_74 ) ? L_55 : L_26 ,
F_50 ( V_133 , V_149 -> V_74 ) ? L_56 : L_26 ,
F_50 ( V_73 , V_149 -> V_74 ) ? L_57 : L_26 ,
F_50 ( V_168 , V_149 -> V_74 ) ? L_58 : L_26 ) ;
F_144 ( V_149 ) ;
goto V_117;
V_172:
F_88 ( V_9 ) ;
V_170:
F_125 ( & V_147 -> V_64 -> V_21 , V_63 -> V_66 ,
V_147 -> V_70 , V_147 -> V_72 ) ;
V_153:
F_88 ( V_147 ) ;
V_117:
return V_101 ;
}
static void F_51 ( struct V_8 * V_9 )
{
struct V_1 * V_54 , * V_25 ;
T_1 V_10 ;
int V_29 , V_4 ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 , L_2 , V_30 ) ;
F_22 ( & V_9 -> V_38 ) ;
V_29 = F_59 ( 0 , & V_4 ) ;
V_54 = F_27 ( V_9 , V_29 , V_4 ) ;
if ( V_54 ) {
V_25 = V_54 -> V_16 ;
F_41 ( & V_54 -> V_51 , & V_9 -> V_18 ) ;
F_31 ( & V_54 -> V_13 ) ;
F_60 ( V_25 , 0 ) ;
F_61 ( V_25 , V_9 , 0 ) ;
F_62 ( V_25 , V_9 , 0 ) ;
F_63 ( V_25 , 0 ) ;
V_10 = F_40 ( & V_54 -> V_13 ) ;
V_9 -> V_20 . V_37 = V_10 - 1 ;
F_4 ( F_13 ( V_9 ) ) ;
F_106 ( V_9 ) ;
F_145 ( V_9 ) ;
F_146 ( V_9 , V_54 -> V_13 . V_31 ) ;
F_4 ( F_16 ( V_54 ) ) ;
F_147 ( V_9 ) ;
} else
F_98 ( V_9 -> V_19 -> V_20 . V_21 ,
L_59 ) ;
F_23 ( & V_9 -> V_38 ) ;
}
static void F_52 ( struct V_8 * V_9 )
{
struct V_1 * V_54 , * V_25 ;
T_1 V_10 ;
int V_29 , V_4 ;
F_9 ( V_9 -> V_19 -> V_20 . V_21 , L_2 , V_30 ) ;
F_22 ( & V_9 -> V_38 ) ;
V_29 = F_65 ( 0 , 2 , & V_4 ) ;
V_54 = F_27 ( V_9 , V_29 , V_4 ) ;
if ( V_54 ) {
V_25 = V_54 -> V_16 ;
F_41 ( & V_54 -> V_51 , & V_9 -> V_18 ) ;
F_31 ( & V_54 -> V_13 ) ;
F_148 ( V_25 , 2 , 0 ) ;
F_61 ( V_25 , V_9 , 0 ) ;
F_62 ( V_25 , V_9 , 0 ) ;
F_67 ( V_25 , 0 , 0 ) ;
F_67 ( V_25 , 1 , 0 ) ;
V_10 = F_40 ( & V_54 -> V_13 ) ;
V_9 -> V_20 . V_37 = V_10 - 1 ;
F_4 ( F_13 ( V_9 ) ) ;
F_106 ( V_9 ) ;
F_145 ( V_9 ) ;
F_146 ( V_9 , V_54 -> V_13 . V_31 ) ;
F_4 ( F_16 ( V_54 ) ) ;
F_147 ( V_9 ) ;
} else
F_98 ( V_9 -> V_19 -> V_20 . V_21 ,
L_59 ) ;
F_23 ( & V_9 -> V_38 ) ;
}
