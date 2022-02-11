static inline int F_1 ( const struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) && F_3 ( V_2 ) )
return 1 ;
return 0 ;
}
static inline int F_4 ( const struct V_3 * V_4 , const struct V_3 * V_5 )
{
if ( V_4 -> V_6 != V_5 -> V_6 )
return 0 ;
switch ( V_4 -> V_6 ) {
case F_5 ( V_7 ) :
return V_4 -> V_8 . V_9 == V_5 -> V_8 . V_9 ;
#if F_6 ( V_10 )
case F_5 ( V_11 ) :
return F_7 ( & V_4 -> V_8 . V_12 , & V_5 -> V_8 . V_12 ) ;
#endif
}
return 0 ;
}
static inline int F_8 ( struct V_13 * V_14 , T_1 V_15 )
{
return F_9 ( V_14 -> V_16 , ( V_17 V_18 ) V_15 ) & ( V_14 -> V_19 - 1 ) ;
}
static inline int F_10 ( struct V_13 * V_14 ,
const struct V_1 * V_15 )
{
return F_11 ( ( V_17 V_18 * ) V_15 -> V_20 , 4 , V_14 -> V_16 ) & ( V_14 -> V_19 - 1 ) ;
}
static inline int F_12 ( struct V_13 * V_14 ,
struct V_3 * V_15 )
{
switch ( V_15 -> V_6 ) {
case F_5 ( V_7 ) :
return F_8 ( V_14 , V_15 -> V_8 . V_9 ) ;
#if F_6 ( V_10 )
case F_5 ( V_11 ) :
return F_10 ( V_14 , & V_15 -> V_8 . V_12 ) ;
#endif
}
return 0 ;
}
static struct V_21 * F_13 (
struct V_13 * V_14 , struct V_3 * V_22 , int V_23 )
{
struct V_21 * V_24 ;
struct V_25 * V_26 ;
F_14 (mp, p, &mdb->mhash[hash], hlist[mdb->ver]) {
if ( F_4 ( & V_24 -> V_2 , V_22 ) )
return V_24 ;
}
return NULL ;
}
static struct V_21 * F_15 (
struct V_13 * V_14 , struct V_3 * V_22 )
{
if ( ! V_14 )
return NULL ;
return F_13 ( V_14 , V_22 , F_12 ( V_14 , V_22 ) ) ;
}
static struct V_21 * F_16 (
struct V_13 * V_14 , T_1 V_22 )
{
struct V_3 V_27 ;
V_27 . V_8 . V_9 = V_22 ;
V_27 . V_6 = F_5 ( V_7 ) ;
return F_15 ( V_14 , & V_27 ) ;
}
static struct V_21 * F_17 (
struct V_13 * V_14 , const struct V_1 * V_22 )
{
struct V_3 V_27 ;
V_27 . V_8 . V_12 = * V_22 ;
V_27 . V_6 = F_5 ( V_11 ) ;
return F_15 ( V_14 , & V_27 ) ;
}
struct V_21 * F_18 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_13 * V_14 = F_19 ( V_29 -> V_14 ) ;
struct V_3 V_15 ;
if ( V_29 -> V_32 )
return NULL ;
if ( F_20 ( V_31 ) -> V_33 )
return NULL ;
V_15 . V_6 = V_31 -> V_34 ;
switch ( V_31 -> V_34 ) {
case F_5 ( V_7 ) :
V_15 . V_8 . V_9 = F_21 ( V_31 ) -> V_35 ;
break;
#if F_6 ( V_10 )
case F_5 ( V_11 ) :
V_15 . V_8 . V_12 = F_22 ( V_31 ) -> V_35 ;
break;
#endif
default:
return NULL ;
}
return F_15 ( V_14 , & V_15 ) ;
}
static void F_23 ( struct V_36 * V_37 )
{
struct V_13 * V_14 =
F_24 ( V_37 , struct V_13 , V_38 ) ;
struct V_13 * V_39 = V_14 -> V_39 ;
V_14 -> V_39 = NULL ;
F_25 ( V_39 -> V_40 ) ;
F_25 ( V_39 ) ;
}
static int F_26 ( struct V_13 * V_41 ,
struct V_13 * V_39 ,
int V_42 )
{
struct V_21 * V_24 ;
struct V_25 * V_26 ;
int V_43 ;
int V_44 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_39 -> V_19 ; V_45 ++ )
F_27 (mp, p, &old->mhash[i], hlist[old->ver])
F_28 ( & V_24 -> V_46 [ V_41 -> V_47 ] ,
& V_41 -> V_40 [ F_12 ( V_41 , & V_24 -> V_2 ) ] ) ;
if ( ! V_42 )
return 0 ;
V_43 = 0 ;
for ( V_45 = 0 ; V_45 < V_41 -> V_19 ; V_45 ++ ) {
V_44 = 0 ;
F_27 (mp, p, &new->mhash[i], hlist[new->ver])
V_44 ++ ;
if ( V_44 > V_43 )
V_43 = V_44 ;
}
return V_43 > V_42 ? - V_48 : 0 ;
}
static void F_29 ( struct V_36 * V_37 )
{
struct V_49 * V_26 =
F_24 ( V_37 , struct V_49 , V_38 ) ;
F_25 ( V_26 ) ;
}
static void F_30 ( struct V_36 * V_37 )
{
struct V_21 * V_24 =
F_24 ( V_37 , struct V_21 , V_38 ) ;
F_25 ( V_24 ) ;
}
static void F_31 ( unsigned long V_50 )
{
struct V_21 * V_24 = ( void * ) V_50 ;
struct V_28 * V_29 = V_24 -> V_29 ;
struct V_13 * V_14 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) || F_34 ( & V_24 -> V_53 ) )
goto V_54;
V_24 -> V_55 = false ;
if ( V_24 -> V_56 )
goto V_54;
V_14 = F_35 ( V_29 -> V_14 , V_29 ) ;
F_36 ( & V_24 -> V_46 [ V_14 -> V_47 ] ) ;
V_14 -> V_57 -- ;
F_37 ( & V_24 -> V_58 ) ;
F_38 ( & V_24 -> V_38 , F_30 ) ;
V_54:
F_39 ( & V_29 -> V_51 ) ;
}
static void F_40 ( struct V_28 * V_29 ,
struct V_49 * V_59 )
{
struct V_13 * V_14 ;
struct V_21 * V_24 ;
struct V_49 * V_26 ;
struct V_49 T_2 * * V_60 ;
V_14 = F_35 ( V_29 -> V_14 , V_29 ) ;
V_24 = F_15 ( V_14 , & V_59 -> V_2 ) ;
if ( F_41 ( ! V_24 ) )
return;
for ( V_60 = & V_24 -> V_56 ;
( V_26 = F_35 ( * V_60 , V_29 ) ) != NULL ;
V_60 = & V_26 -> V_61 ) {
if ( V_26 != V_59 )
continue;
F_42 ( * V_60 , V_26 -> V_61 ) ;
F_43 ( & V_26 -> V_55 ) ;
F_37 ( & V_26 -> V_53 ) ;
F_37 ( & V_26 -> V_58 ) ;
F_38 ( & V_26 -> V_38 , F_29 ) ;
if ( ! V_24 -> V_56 && ! V_24 -> V_55 &&
F_33 ( V_29 -> V_52 ) )
F_44 ( & V_24 -> V_53 , V_62 ) ;
return;
}
F_41 ( 1 ) ;
}
static void F_45 ( unsigned long V_50 )
{
struct V_49 * V_59 = ( void * ) V_50 ;
struct V_28 * V_29 = V_59 -> V_63 -> V_29 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) || F_34 ( & V_59 -> V_53 ) ||
F_46 ( & V_59 -> V_55 ) )
goto V_54;
F_40 ( V_29 , V_59 ) ;
V_54:
F_39 ( & V_29 -> V_51 ) ;
}
static int F_47 ( struct V_13 T_2 * * V_64 , int V_19 ,
int V_42 )
{
struct V_13 * V_39 = F_48 ( * V_64 , 1 ) ;
struct V_13 * V_14 ;
int V_65 ;
V_14 = F_49 ( sizeof( * V_14 ) , V_66 ) ;
if ( ! V_14 )
return - V_67 ;
V_14 -> V_19 = V_19 ;
V_14 -> V_39 = V_39 ;
V_14 -> V_40 = F_50 ( V_19 * sizeof( * V_14 -> V_40 ) , V_66 ) ;
if ( ! V_14 -> V_40 ) {
F_25 ( V_14 ) ;
return - V_67 ;
}
V_14 -> V_57 = V_39 ? V_39 -> V_57 : 0 ;
V_14 -> V_47 = V_39 ? V_39 -> V_47 ^ 1 : 0 ;
if ( ! V_39 || V_42 )
F_51 ( & V_14 -> V_16 , sizeof( V_14 -> V_16 ) ) ;
else
V_14 -> V_16 = V_39 -> V_16 ;
if ( ! V_39 )
goto V_54;
V_65 = F_26 ( V_14 , V_39 , V_42 ) ;
if ( V_65 ) {
F_25 ( V_14 -> V_40 ) ;
F_25 ( V_14 ) ;
return V_65 ;
}
F_38 ( & V_14 -> V_38 , F_23 ) ;
V_54:
F_42 ( * V_64 , V_14 ) ;
return 0 ;
}
static struct V_30 * F_52 ( struct V_28 * V_29 ,
T_1 V_68 )
{
struct V_30 * V_31 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
V_31 = F_53 ( V_29 -> V_52 , sizeof( * V_72 ) + sizeof( * V_74 ) +
sizeof( * V_70 ) + 4 ) ;
if ( ! V_31 )
goto V_54;
V_31 -> V_34 = F_5 ( V_7 ) ;
F_54 ( V_31 ) ;
V_72 = F_55 ( V_31 ) ;
memcpy ( V_72 -> V_75 , V_29 -> V_52 -> V_76 , 6 ) ;
V_72 -> V_77 [ 0 ] = 1 ;
V_72 -> V_77 [ 1 ] = 0 ;
V_72 -> V_77 [ 2 ] = 0x5e ;
V_72 -> V_77 [ 3 ] = 0 ;
V_72 -> V_77 [ 4 ] = 0 ;
V_72 -> V_77 [ 5 ] = 1 ;
V_72 -> V_78 = F_5 ( V_7 ) ;
F_56 ( V_31 , sizeof( * V_72 ) ) ;
F_57 ( V_31 , V_31 -> V_44 ) ;
V_74 = F_21 ( V_31 ) ;
V_74 -> V_79 = 4 ;
V_74 -> V_80 = 6 ;
V_74 -> V_81 = 0xc0 ;
V_74 -> V_82 = F_5 ( sizeof( * V_74 ) + sizeof( * V_70 ) + 4 ) ;
V_74 -> V_83 = 0 ;
V_74 -> V_84 = F_5 ( V_85 ) ;
V_74 -> V_86 = 1 ;
V_74 -> V_34 = V_87 ;
V_74 -> V_88 = 0 ;
V_74 -> V_35 = F_58 ( V_89 ) ;
( ( V_90 * ) & V_74 [ 1 ] ) [ 0 ] = V_91 ;
( ( V_90 * ) & V_74 [ 1 ] ) [ 1 ] = 4 ;
( ( V_90 * ) & V_74 [ 1 ] ) [ 2 ] = 0 ;
( ( V_90 * ) & V_74 [ 1 ] ) [ 3 ] = 0 ;
F_59 ( V_74 ) ;
F_56 ( V_31 , 24 ) ;
F_60 ( V_31 , V_31 -> V_44 ) ;
V_70 = F_61 ( V_31 ) ;
V_70 -> type = V_92 ;
V_70 -> V_93 = ( V_68 ? V_29 -> V_94 :
V_29 -> V_95 ) /
( V_96 / V_97 ) ;
V_70 -> V_68 = V_68 ;
V_70 -> V_98 = 0 ;
V_70 -> V_98 = F_62 ( ( void * ) V_70 , sizeof( struct V_69 ) ) ;
F_56 ( V_31 , sizeof( * V_70 ) ) ;
F_63 ( V_31 , sizeof( * V_72 ) ) ;
V_54:
return V_31 ;
}
static struct V_30 * F_64 ( struct V_28 * V_29 ,
const struct V_1 * V_68 )
{
struct V_30 * V_31 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_71 * V_72 ;
V_90 * V_103 ;
unsigned long V_104 ;
V_31 = F_53 ( V_29 -> V_52 , sizeof( * V_72 ) + sizeof( * V_100 ) +
8 + sizeof( * V_102 ) ) ;
if ( ! V_31 )
goto V_54;
V_31 -> V_34 = F_5 ( V_11 ) ;
F_54 ( V_31 ) ;
V_72 = F_55 ( V_31 ) ;
memcpy ( V_72 -> V_75 , V_29 -> V_52 -> V_76 , 6 ) ;
V_72 -> V_78 = F_5 ( V_11 ) ;
F_56 ( V_31 , sizeof( * V_72 ) ) ;
F_57 ( V_31 , V_31 -> V_44 ) ;
V_100 = F_22 ( V_31 ) ;
* ( V_17 T_1 * ) V_100 = F_58 ( 0x60000000 ) ;
V_100 -> V_105 = F_5 ( 8 + sizeof( * V_102 ) ) ;
V_100 -> V_106 = V_107 ;
V_100 -> V_108 = 1 ;
F_65 ( & V_100 -> V_35 , F_58 ( 0xff020000 ) , 0 , 0 , F_58 ( 1 ) ) ;
if ( F_66 ( F_67 ( V_29 -> V_52 ) , V_29 -> V_52 , & V_100 -> V_35 , 0 ,
& V_100 -> V_88 ) ) {
F_68 ( V_31 ) ;
return NULL ;
}
F_69 ( & V_100 -> V_35 , V_72 -> V_77 ) ;
V_103 = ( V_90 * ) ( V_100 + 1 ) ;
V_103 [ 0 ] = V_109 ;
V_103 [ 1 ] = 0 ;
V_103 [ 2 ] = V_110 ;
V_103 [ 3 ] = 2 ;
V_103 [ 4 ] = 0 ;
V_103 [ 5 ] = 0 ;
V_103 [ 6 ] = V_111 ;
V_103 [ 7 ] = V_111 ;
F_56 ( V_31 , sizeof( * V_100 ) + 8 ) ;
F_60 ( V_31 , V_31 -> V_44 ) ;
V_102 = (struct V_101 * ) F_70 ( V_31 ) ;
V_104 = F_71 ( V_68 ) ? V_29 -> V_94 :
V_29 -> V_95 ;
V_102 -> V_112 = V_113 ;
V_102 -> V_114 = 0 ;
V_102 -> V_115 = 0 ;
V_102 -> V_116 = F_5 ( ( V_117 ) F_72 ( V_104 ) ) ;
V_102 -> V_118 = 0 ;
V_102 -> V_119 = * V_68 ;
V_102 -> V_115 = F_73 ( & V_100 -> V_88 , & V_100 -> V_35 ,
sizeof( * V_102 ) , V_109 ,
F_74 ( V_102 ,
sizeof( * V_102 ) , 0 ) ) ;
F_56 ( V_31 , sizeof( * V_102 ) ) ;
F_63 ( V_31 , sizeof( * V_72 ) ) ;
V_54:
return V_31 ;
}
static struct V_30 * F_75 ( struct V_28 * V_29 ,
struct V_3 * V_2 )
{
switch ( V_2 -> V_6 ) {
case F_5 ( V_7 ) :
return F_52 ( V_29 , V_2 -> V_8 . V_9 ) ;
#if F_6 ( V_10 )
case F_5 ( V_11 ) :
return F_64 ( V_29 , & V_2 -> V_8 . V_12 ) ;
#endif
}
return NULL ;
}
static void F_76 ( struct V_21 * V_24 )
{
struct V_28 * V_29 = V_24 -> V_29 ;
struct V_30 * V_31 ;
V_31 = F_75 ( V_29 , & V_24 -> V_2 ) ;
if ( ! V_31 )
goto V_53;
F_77 ( V_31 ) ;
V_53:
if ( ++ V_24 -> V_120 < V_29 -> V_121 )
F_44 ( & V_24 -> V_58 ,
V_62 + V_29 -> V_94 ) ;
}
static void F_78 ( unsigned long V_50 )
{
struct V_21 * V_24 = ( void * ) V_50 ;
struct V_28 * V_29 = V_24 -> V_29 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) || ! V_24 -> V_55 ||
V_24 -> V_120 >= V_29 -> V_121 )
goto V_54;
F_76 ( V_24 ) ;
V_54:
F_39 ( & V_29 -> V_51 ) ;
}
static void F_79 ( struct V_49 * V_59 )
{
struct V_122 * V_63 = V_59 -> V_63 ;
struct V_28 * V_29 = V_63 -> V_29 ;
struct V_30 * V_31 ;
V_31 = F_75 ( V_29 , & V_59 -> V_2 ) ;
if ( ! V_31 )
goto V_53;
F_80 ( V_63 , V_31 ) ;
V_53:
if ( ++ V_59 -> V_120 < V_29 -> V_121 )
F_44 ( & V_59 -> V_58 ,
V_62 + V_29 -> V_94 ) ;
}
static void F_81 ( unsigned long V_50 )
{
struct V_49 * V_59 = ( void * ) V_50 ;
struct V_122 * V_63 = V_59 -> V_63 ;
struct V_28 * V_29 = V_63 -> V_29 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) || F_46 ( & V_59 -> V_55 ) ||
V_59 -> V_120 >= V_29 -> V_121 )
goto V_54;
F_79 ( V_59 ) ;
V_54:
F_39 ( & V_29 -> V_51 ) ;
}
static struct V_21 * F_82 (
struct V_28 * V_29 , struct V_122 * V_63 ,
struct V_3 * V_68 , int V_23 )
{
struct V_13 * V_14 ;
struct V_21 * V_24 ;
struct V_25 * V_26 ;
unsigned V_123 = 0 ;
unsigned V_19 ;
int V_42 ;
int V_65 ;
V_14 = F_48 ( V_29 -> V_14 , 1 ) ;
F_27 (mp, p, &mdb->mhash[hash], hlist[mdb->ver]) {
V_123 ++ ;
if ( F_83 ( F_4 ( V_68 , & V_24 -> V_2 ) ) )
return V_24 ;
}
V_42 = 0 ;
V_19 = V_14 -> V_19 ;
if ( F_83 ( V_123 > V_29 -> V_124 && V_123 ) ) {
if ( F_84 () )
F_85 ( V_29 , L_1
L_2 ,
V_63 ? V_63 -> V_52 -> V_125 : V_29 -> V_52 -> V_125 ) ;
V_42 = V_29 -> V_124 ;
}
if ( V_14 -> V_57 >= V_19 ) {
V_19 *= 2 ;
if ( F_83 ( V_19 >= V_29 -> V_126 ) ) {
F_86 ( V_29 , L_3
L_4 ,
V_63 ? V_63 -> V_52 -> V_125 : V_29 -> V_52 -> V_125 , V_19 ) ;
V_65 = - V_127 ;
V_128:
V_29 -> V_32 = 1 ;
goto V_65;
}
}
if ( V_19 > V_14 -> V_19 || V_42 ) {
if ( V_14 -> V_39 ) {
if ( F_84 () )
F_85 ( V_29 , L_1
L_5 ,
V_63 ? V_63 -> V_52 -> V_125 : V_29 -> V_52 -> V_125 ) ;
V_65 = - V_129 ;
goto V_65;
}
V_65 = F_47 ( & V_29 -> V_14 , V_19 , V_42 ) ;
if ( V_65 ) {
F_86 ( V_29 , L_6
L_7 ,
V_63 ? V_63 -> V_52 -> V_125 : V_29 -> V_52 -> V_125 ,
V_14 -> V_57 , V_65 ) ;
goto V_128;
}
V_65 = - V_130 ;
goto V_65;
}
return NULL ;
V_65:
V_24 = F_87 ( V_65 ) ;
return V_24 ;
}
static struct V_21 * F_88 (
struct V_28 * V_29 , struct V_122 * V_63 ,
struct V_3 * V_68 )
{
struct V_13 * V_14 ;
struct V_21 * V_24 ;
int V_23 ;
int V_65 ;
V_14 = F_48 ( V_29 -> V_14 , 1 ) ;
if ( ! V_14 ) {
V_65 = F_47 ( & V_29 -> V_14 , V_131 , 0 ) ;
if ( V_65 )
return F_87 ( V_65 ) ;
goto V_132;
}
V_23 = F_12 ( V_14 , V_68 ) ;
V_24 = F_82 ( V_29 , V_63 , V_68 , V_23 ) ;
switch ( F_89 ( V_24 ) ) {
case 0 :
break;
case - V_130 :
V_132:
V_14 = F_48 ( V_29 -> V_14 , 1 ) ;
V_23 = F_12 ( V_14 , V_68 ) ;
break;
default:
goto V_54;
}
V_24 = F_50 ( sizeof( * V_24 ) , V_66 ) ;
if ( F_83 ( ! V_24 ) )
return F_87 ( - V_67 ) ;
V_24 -> V_29 = V_29 ;
V_24 -> V_2 = * V_68 ;
F_90 ( & V_24 -> V_53 , F_31 ,
( unsigned long ) V_24 ) ;
F_90 ( & V_24 -> V_58 , F_78 ,
( unsigned long ) V_24 ) ;
F_91 ( & V_24 -> V_46 [ V_14 -> V_47 ] , & V_14 -> V_40 [ V_23 ] ) ;
V_14 -> V_57 ++ ;
V_54:
return V_24 ;
}
static int F_92 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
struct V_3 * V_68 )
{
struct V_21 * V_24 ;
struct V_49 * V_26 ;
struct V_49 T_2 * * V_60 ;
unsigned long V_133 = V_62 ;
int V_65 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) ||
( V_63 && V_63 -> V_134 == V_135 ) )
goto V_54;
V_24 = F_88 ( V_29 , V_63 , V_68 ) ;
V_65 = F_89 ( V_24 ) ;
if ( F_93 ( V_24 ) )
goto V_65;
if ( ! V_63 ) {
V_24 -> V_55 = true ;
F_44 ( & V_24 -> V_53 , V_133 + V_29 -> V_136 ) ;
goto V_54;
}
for ( V_60 = & V_24 -> V_56 ;
( V_26 = F_35 ( * V_60 , V_29 ) ) != NULL ;
V_60 = & V_26 -> V_61 ) {
if ( V_26 -> V_63 == V_63 )
goto V_137;
if ( ( unsigned long ) V_26 -> V_63 < ( unsigned long ) V_63 )
break;
}
V_26 = F_50 ( sizeof( * V_26 ) , V_66 ) ;
V_65 = - V_67 ;
if ( F_83 ( ! V_26 ) )
goto V_65;
V_26 -> V_2 = * V_68 ;
V_26 -> V_63 = V_63 ;
V_26 -> V_61 = * V_60 ;
F_28 ( & V_26 -> V_55 , & V_63 -> V_55 ) ;
F_90 ( & V_26 -> V_53 , F_45 ,
( unsigned long ) V_26 ) ;
F_90 ( & V_26 -> V_58 , F_81 ,
( unsigned long ) V_26 ) ;
F_42 ( * V_60 , V_26 ) ;
V_137:
F_44 ( & V_26 -> V_53 , V_133 + V_29 -> V_136 ) ;
V_54:
V_65 = 0 ;
V_65:
F_39 ( & V_29 -> V_51 ) ;
return V_65 ;
}
static int F_94 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
T_1 V_68 )
{
struct V_3 V_138 ;
if ( F_95 ( V_68 ) )
return 0 ;
V_138 . V_8 . V_9 = V_68 ;
V_138 . V_6 = F_5 ( V_7 ) ;
return F_92 ( V_29 , V_63 , & V_138 ) ;
}
static int F_96 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
const struct V_1 * V_68 )
{
struct V_3 V_138 ;
if ( ! F_1 ( V_68 ) )
return 0 ;
V_138 . V_8 . V_12 = * V_68 ;
V_138 . V_6 = F_5 ( V_11 ) ;
return F_92 ( V_29 , V_63 , & V_138 ) ;
}
static void F_97 ( unsigned long V_50 )
{
struct V_122 * V_63 = ( void * ) V_50 ;
struct V_28 * V_29 = V_63 -> V_29 ;
F_32 ( & V_29 -> V_51 ) ;
if ( V_63 -> V_139 != 1 ||
F_34 ( & V_63 -> V_140 ) ||
F_46 ( & V_63 -> V_141 ) )
goto V_54;
F_98 ( & V_63 -> V_141 ) ;
V_54:
F_39 ( & V_29 -> V_51 ) ;
}
static void F_99 ( unsigned long V_50 )
{
}
static void F_100 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
struct V_3 * V_15 )
{
struct V_30 * V_31 ;
V_31 = F_75 ( V_29 , V_15 ) ;
if ( ! V_31 )
return;
if ( V_63 ) {
F_101 ( V_31 , sizeof( struct V_71 ) ) ;
V_31 -> V_52 = V_63 -> V_52 ;
F_102 ( V_142 , V_143 , V_31 , NULL , V_31 -> V_52 ,
V_144 ) ;
} else
F_77 ( V_31 ) ;
}
static void F_103 ( struct V_28 * V_29 ,
struct V_122 * V_63 , V_18 V_145 )
{
unsigned long time ;
struct V_3 V_138 ;
if ( ! F_33 ( V_29 -> V_52 ) || V_29 -> V_32 ||
F_34 ( & V_29 -> V_146 ) )
return;
memset ( & V_138 . V_8 , 0 , sizeof( V_138 . V_8 ) ) ;
V_138 . V_6 = F_5 ( V_7 ) ;
F_100 ( V_29 , V_63 , & V_138 ) ;
#if F_6 ( V_10 )
V_138 . V_6 = F_5 ( V_11 ) ;
F_100 ( V_29 , V_63 , & V_138 ) ;
#endif
time = V_62 ;
time += V_145 < V_29 -> V_147 ?
V_29 -> V_148 :
V_29 -> V_149 ;
F_44 ( V_63 ? & V_63 -> V_150 :
& V_29 -> V_150 , time ) ;
}
static void F_104 ( unsigned long V_50 )
{
struct V_122 * V_63 = ( void * ) V_50 ;
struct V_28 * V_29 = V_63 -> V_29 ;
F_32 ( & V_29 -> V_51 ) ;
if ( V_63 -> V_134 == V_135 ||
V_63 -> V_134 == V_151 )
goto V_54;
if ( V_63 -> V_152 <
V_29 -> V_147 )
V_63 -> V_152 ++ ;
F_103 ( V_63 -> V_29 , V_63 ,
V_63 -> V_152 ) ;
V_54:
F_39 ( & V_29 -> V_51 ) ;
}
void F_105 ( struct V_122 * V_63 )
{
V_63 -> V_139 = 1 ;
F_90 ( & V_63 -> V_140 , F_97 ,
( unsigned long ) V_63 ) ;
F_90 ( & V_63 -> V_150 ,
F_104 , ( unsigned long ) V_63 ) ;
}
void F_106 ( struct V_122 * V_63 )
{
F_107 ( & V_63 -> V_140 ) ;
}
static void F_108 ( struct V_122 * V_63 )
{
V_63 -> V_152 = 0 ;
if ( F_109 ( & V_63 -> V_150 ) >= 0 ||
F_37 ( & V_63 -> V_150 ) )
F_44 ( & V_63 -> V_150 , V_62 ) ;
}
void F_110 ( struct V_122 * V_63 )
{
struct V_28 * V_29 = V_63 -> V_29 ;
F_32 ( & V_29 -> V_51 ) ;
if ( V_29 -> V_32 || ! F_33 ( V_29 -> V_52 ) )
goto V_54;
F_108 ( V_63 ) ;
V_54:
F_39 ( & V_29 -> V_51 ) ;
}
void F_111 ( struct V_122 * V_63 )
{
struct V_28 * V_29 = V_63 -> V_29 ;
struct V_49 * V_59 ;
struct V_25 * V_26 , * V_153 ;
F_32 ( & V_29 -> V_51 ) ;
F_112 (pg, p, n, &port->mglist, mglist)
F_40 ( V_29 , V_59 ) ;
if ( ! F_46 ( & V_63 -> V_141 ) )
F_98 ( & V_63 -> V_141 ) ;
F_37 ( & V_63 -> V_140 ) ;
F_37 ( & V_63 -> V_150 ) ;
F_39 ( & V_29 -> V_51 ) ;
}
static int F_113 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
struct V_30 * V_31 )
{
struct V_154 * V_70 ;
struct V_155 * V_156 ;
int V_45 ;
int V_44 ;
int V_157 ;
int type ;
int V_65 = 0 ;
T_1 V_68 ;
if ( ! F_114 ( V_31 , sizeof( * V_70 ) ) )
return - V_48 ;
V_70 = F_115 ( V_31 ) ;
V_157 = F_116 ( V_70 -> V_158 ) ;
V_44 = sizeof( * V_70 ) ;
for ( V_45 = 0 ; V_45 < V_157 ; V_45 ++ ) {
V_44 += sizeof( * V_156 ) ;
if ( ! F_114 ( V_31 , V_44 ) )
return - V_48 ;
V_156 = ( void * ) ( V_31 -> V_50 + V_44 - sizeof( * V_156 ) ) ;
V_68 = V_156 -> V_159 ;
type = V_156 -> V_160 ;
V_44 += F_116 ( V_156 -> V_161 ) * 4 ;
if ( ! F_114 ( V_31 , V_44 ) )
return - V_48 ;
switch ( type ) {
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
break;
default:
continue;
}
V_65 = F_94 ( V_29 , V_63 , V_68 ) ;
if ( V_65 )
break;
}
return V_65 ;
}
static int F_117 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
struct V_30 * V_31 )
{
struct V_168 * V_169 ;
struct V_170 * V_156 ;
int V_45 ;
int V_44 ;
int V_157 ;
int V_65 = 0 ;
if ( ! F_114 ( V_31 , sizeof( * V_169 ) ) )
return - V_48 ;
V_169 = F_70 ( V_31 ) ;
V_157 = F_116 ( V_169 -> V_171 . V_172 [ 1 ] ) ;
V_44 = sizeof( * V_169 ) ;
for ( V_45 = 0 ; V_45 < V_157 ; V_45 ++ ) {
T_3 * V_173 , V_174 ;
V_173 = F_118 ( V_31 ,
V_44 + F_119 ( struct V_170 ,
V_161 ) ,
sizeof( V_174 ) , & V_174 ) ;
if ( ! V_173 )
return - V_48 ;
if ( ! F_114 ( V_31 ,
V_44 + sizeof( * V_156 ) +
sizeof( struct V_1 ) * F_116 ( * V_173 ) ) )
return - V_48 ;
V_156 = (struct V_170 * ) ( V_31 -> V_50 + V_44 ) ;
V_44 += sizeof( * V_156 ) +
sizeof( struct V_1 ) * F_116 ( * V_173 ) ;
switch ( V_156 -> V_160 ) {
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
break;
default:
continue;
}
V_65 = F_96 ( V_29 , V_63 , & V_156 -> V_159 ) ;
if ( ! V_65 )
break;
}
return V_65 ;
}
static void F_120 ( struct V_28 * V_29 ,
struct V_122 * V_63 )
{
struct V_122 * V_26 ;
struct V_25 * V_153 , * V_181 = NULL ;
F_27 (p, n, &br->router_list, rlist) {
if ( ( unsigned long ) V_63 >= ( unsigned long ) V_26 )
break;
V_181 = V_153 ;
}
if ( V_181 )
F_121 ( V_181 , & V_63 -> V_141 ) ;
else
F_91 ( & V_63 -> V_141 , & V_29 -> V_182 ) ;
}
static void F_122 ( struct V_28 * V_29 ,
struct V_122 * V_63 )
{
unsigned long V_133 = V_62 ;
if ( ! V_63 ) {
if ( V_29 -> V_139 == 1 )
F_44 ( & V_29 -> V_140 ,
V_133 + V_29 -> V_183 ) ;
return;
}
if ( V_63 -> V_139 != 1 )
return;
if ( ! F_46 ( & V_63 -> V_141 ) )
goto V_53;
F_120 ( V_29 , V_63 ) ;
V_53:
F_44 ( & V_63 -> V_140 ,
V_133 + V_29 -> V_183 ) ;
}
static void F_123 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
int V_88 )
{
if ( V_88 )
F_44 ( & V_29 -> V_146 ,
V_62 + V_29 -> V_183 ) ;
else if ( F_34 ( & V_29 -> V_146 ) )
return;
F_122 ( V_29 , V_63 ) ;
}
static int F_124 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
struct V_30 * V_31 )
{
const struct V_73 * V_74 = F_21 ( V_31 ) ;
struct V_69 * V_70 = F_61 ( V_31 ) ;
struct V_21 * V_24 ;
struct V_184 * V_185 ;
struct V_49 * V_26 ;
struct V_49 T_2 * * V_60 ;
unsigned long V_186 ;
unsigned long V_133 = V_62 ;
T_1 V_68 ;
int V_65 = 0 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) ||
( V_63 && V_63 -> V_134 == V_135 ) )
goto V_54;
F_123 ( V_29 , V_63 , ! ! V_74 -> V_88 ) ;
V_68 = V_70 -> V_68 ;
if ( V_31 -> V_44 == sizeof( * V_70 ) ) {
V_186 = V_70 -> V_93 * ( V_96 / V_97 ) ;
if ( ! V_186 ) {
V_186 = 10 * V_96 ;
V_68 = 0 ;
}
} else {
if ( ! F_114 ( V_31 , sizeof( struct V_184 ) ) ) {
V_65 = - V_48 ;
goto V_54;
}
V_185 = F_125 ( V_31 ) ;
if ( V_185 -> V_173 )
goto V_54;
V_186 = V_185 -> V_93 ?
F_126 ( V_185 -> V_93 ) * ( V_96 / V_97 ) : 1 ;
}
if ( ! V_68 )
goto V_54;
V_24 = F_16 ( F_35 ( V_29 -> V_14 , V_29 ) , V_68 ) ;
if ( ! V_24 )
goto V_54;
V_186 *= V_29 -> V_121 ;
if ( V_24 -> V_55 &&
( F_34 ( & V_24 -> V_53 ) ?
F_127 ( V_24 -> V_53 . V_187 , V_133 + V_186 ) :
F_109 ( & V_24 -> V_53 ) >= 0 ) )
F_44 ( & V_24 -> V_53 , V_133 + V_186 ) ;
for ( V_60 = & V_24 -> V_56 ;
( V_26 = F_35 ( * V_60 , V_29 ) ) != NULL ;
V_60 = & V_26 -> V_61 ) {
if ( F_34 ( & V_26 -> V_53 ) ?
F_127 ( V_26 -> V_53 . V_187 , V_133 + V_186 ) :
F_109 ( & V_26 -> V_53 ) >= 0 )
F_44 ( & V_26 -> V_53 , V_133 + V_186 ) ;
}
V_54:
F_39 ( & V_29 -> V_51 ) ;
return V_65 ;
}
static int F_128 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
struct V_30 * V_31 )
{
const struct V_99 * V_100 = F_22 ( V_31 ) ;
struct V_101 * V_188 = (struct V_101 * ) F_70 ( V_31 ) ;
struct V_21 * V_24 ;
struct V_189 * V_190 ;
struct V_49 * V_26 ;
struct V_49 T_2 * * V_60 ;
unsigned long V_186 ;
unsigned long V_133 = V_62 ;
const struct V_1 * V_68 = NULL ;
int V_65 = 0 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) ||
( V_63 && V_63 -> V_134 == V_135 ) )
goto V_54;
F_123 ( V_29 , V_63 , ! F_71 ( & V_100 -> V_88 ) ) ;
if ( V_31 -> V_44 == sizeof( * V_188 ) ) {
if ( ! F_114 ( V_31 , sizeof( * V_188 ) ) ) {
V_65 = - V_48 ;
goto V_54;
}
V_188 = (struct V_101 * ) F_70 ( V_31 ) ;
V_186 = F_129 ( F_5 ( V_188 -> V_116 ) ) ;
if ( V_186 )
V_68 = & V_188 -> V_119 ;
} else if ( V_31 -> V_44 >= sizeof( * V_190 ) ) {
if ( ! F_114 ( V_31 , sizeof( * V_190 ) ) ) {
V_65 = - V_48 ;
goto V_54;
}
V_190 = (struct V_189 * ) F_70 ( V_31 ) ;
if ( ! V_190 -> V_191 )
V_68 = & V_190 -> V_192 ;
V_186 = V_190 -> V_193 ? F_130 ( V_190 -> V_193 ) : 1 ;
}
if ( ! V_68 )
goto V_54;
V_24 = F_17 ( F_35 ( V_29 -> V_14 , V_29 ) , V_68 ) ;
if ( ! V_24 )
goto V_54;
V_186 *= V_29 -> V_121 ;
if ( V_24 -> V_55 &&
( F_34 ( & V_24 -> V_53 ) ?
F_127 ( V_24 -> V_53 . V_187 , V_133 + V_186 ) :
F_109 ( & V_24 -> V_53 ) >= 0 ) )
F_44 ( & V_24 -> V_53 , V_133 + V_186 ) ;
for ( V_60 = & V_24 -> V_56 ;
( V_26 = F_35 ( * V_60 , V_29 ) ) != NULL ;
V_60 = & V_26 -> V_61 ) {
if ( F_34 ( & V_26 -> V_53 ) ?
F_127 ( V_26 -> V_53 . V_187 , V_133 + V_186 ) :
F_109 ( & V_26 -> V_53 ) >= 0 )
F_44 ( & V_26 -> V_53 , V_133 + V_186 ) ;
}
V_54:
F_39 ( & V_29 -> V_51 ) ;
return V_65 ;
}
static void F_131 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
struct V_3 * V_68 )
{
struct V_13 * V_14 ;
struct V_21 * V_24 ;
struct V_49 * V_26 ;
unsigned long V_133 ;
unsigned long time ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) ||
( V_63 && V_63 -> V_134 == V_135 ) ||
F_34 ( & V_29 -> V_146 ) )
goto V_54;
V_14 = F_35 ( V_29 -> V_14 , V_29 ) ;
V_24 = F_15 ( V_14 , V_68 ) ;
if ( ! V_24 )
goto V_54;
V_133 = V_62 ;
time = V_133 + V_29 -> V_121 *
V_29 -> V_94 ;
if ( ! V_63 ) {
if ( V_24 -> V_55 &&
( F_34 ( & V_24 -> V_53 ) ?
F_127 ( V_24 -> V_53 . V_187 , time ) :
F_109 ( & V_24 -> V_53 ) >= 0 ) ) {
F_44 ( & V_24 -> V_53 , time ) ;
V_24 -> V_120 = 0 ;
F_44 ( & V_24 -> V_58 , V_133 ) ;
}
goto V_54;
}
for ( V_26 = F_35 ( V_24 -> V_56 , V_29 ) ;
V_26 != NULL ;
V_26 = F_35 ( V_26 -> V_61 , V_29 ) ) {
if ( V_26 -> V_63 != V_63 )
continue;
if ( ! F_46 ( & V_26 -> V_55 ) &&
( F_34 ( & V_26 -> V_53 ) ?
F_127 ( V_26 -> V_53 . V_187 , time ) :
F_109 ( & V_26 -> V_53 ) >= 0 ) ) {
F_44 ( & V_26 -> V_53 , time ) ;
V_26 -> V_120 = 0 ;
F_44 ( & V_26 -> V_58 , V_133 ) ;
}
break;
}
V_54:
F_39 ( & V_29 -> V_51 ) ;
}
static void F_132 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
T_1 V_68 )
{
struct V_3 V_138 ;
if ( F_95 ( V_68 ) )
return;
V_138 . V_8 . V_9 = V_68 ;
V_138 . V_6 = F_5 ( V_7 ) ;
F_131 ( V_29 , V_63 , & V_138 ) ;
}
static void F_133 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
const struct V_1 * V_68 )
{
struct V_3 V_138 ;
if ( ! F_1 ( V_68 ) )
return;
V_138 . V_8 . V_12 = * V_68 ;
V_138 . V_6 = F_5 ( V_11 ) ;
F_131 ( V_29 , V_63 , & V_138 ) ;
}
static int F_134 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
struct V_30 * V_31 )
{
struct V_30 * V_194 = V_31 ;
const struct V_73 * V_74 ;
struct V_69 * V_70 ;
unsigned V_44 ;
unsigned V_195 ;
int V_65 ;
if ( ! F_114 ( V_31 , sizeof( * V_74 ) ) )
return - V_48 ;
V_74 = F_21 ( V_31 ) ;
if ( V_74 -> V_80 < 5 || V_74 -> V_79 != 4 )
return - V_48 ;
if ( ! F_114 ( V_31 , F_135 ( V_31 ) ) )
return - V_48 ;
V_74 = F_21 ( V_31 ) ;
if ( F_83 ( F_136 ( ( V_90 * ) V_74 , V_74 -> V_80 ) ) )
return - V_48 ;
if ( V_74 -> V_34 != V_87 ) {
if ( ( V_74 -> V_35 & V_196 ) != V_197 )
F_20 ( V_31 ) -> V_198 = 1 ;
return 0 ;
}
V_44 = F_116 ( V_74 -> V_82 ) ;
if ( V_31 -> V_44 < V_44 || V_44 < F_135 ( V_31 ) )
return - V_48 ;
if ( V_31 -> V_44 > V_44 ) {
V_194 = F_137 ( V_31 , V_66 ) ;
if ( ! V_194 )
return - V_67 ;
V_65 = F_138 ( V_194 , V_44 ) ;
if ( V_65 )
goto V_199;
}
V_44 -= F_135 ( V_194 ) ;
V_195 = F_139 ( V_194 ) + F_135 ( V_194 ) ;
F_63 ( V_194 , V_195 ) ;
F_140 ( V_194 ) ;
V_65 = - V_48 ;
if ( ! F_114 ( V_194 , sizeof( * V_70 ) ) )
goto V_54;
switch ( V_194 -> V_200 ) {
case V_201 :
if ( ! F_141 ( V_194 -> V_98 ) )
break;
case V_202 :
V_194 -> V_98 = 0 ;
if ( F_142 ( V_194 ) )
goto V_54;
}
V_65 = 0 ;
F_20 ( V_31 ) -> V_33 = 1 ;
V_70 = F_61 ( V_194 ) ;
switch ( V_70 -> type ) {
case V_203 :
case V_204 :
F_20 ( V_31 ) -> V_198 = 1 ;
V_65 = F_94 ( V_29 , V_63 , V_70 -> V_68 ) ;
break;
case V_205 :
V_65 = F_113 ( V_29 , V_63 , V_194 ) ;
break;
case V_92 :
V_65 = F_124 ( V_29 , V_63 , V_194 ) ;
break;
case V_206 :
F_132 ( V_29 , V_63 , V_70 -> V_68 ) ;
break;
}
V_54:
F_101 ( V_194 , V_195 ) ;
V_199:
if ( V_194 != V_31 )
F_68 ( V_194 ) ;
return V_65 ;
}
static int F_143 ( struct V_28 * V_29 ,
struct V_122 * V_63 ,
struct V_30 * V_31 )
{
struct V_30 * V_194 ;
const struct V_99 * V_100 ;
V_90 V_207 ;
V_90 V_106 ;
T_3 V_84 ;
unsigned V_44 ;
int V_195 ;
int V_65 ;
if ( ! F_114 ( V_31 , sizeof( * V_100 ) ) )
return - V_48 ;
V_100 = F_22 ( V_31 ) ;
if ( V_100 -> V_79 != 6 ||
V_100 -> V_106 != V_107 ||
V_100 -> V_105 == 0 )
return 0 ;
V_44 = F_116 ( V_100 -> V_105 ) + sizeof( * V_100 ) ;
if ( V_31 -> V_44 < V_44 )
return - V_48 ;
V_106 = V_100 -> V_106 ;
V_195 = F_144 ( V_31 , sizeof( * V_100 ) , & V_106 , & V_84 ) ;
if ( V_195 < 0 || V_106 != V_109 )
return 0 ;
V_194 = F_137 ( V_31 , V_66 ) ;
if ( ! V_194 )
return - V_67 ;
V_65 = - V_48 ;
if ( ! F_114 ( V_194 , V_195 + sizeof( struct V_168 ) ) )
goto V_54;
V_44 -= V_195 - F_139 ( V_194 ) ;
F_63 ( V_194 , V_195 ) ;
F_140 ( V_194 ) ;
F_145 ( V_194 , F_146 ( V_194 ) ,
F_147 ( V_194 ) ) ;
V_207 = F_70 ( V_194 ) -> V_207 ;
switch ( V_207 ) {
case V_113 :
case V_208 :
case V_209 :
case V_210 :
break;
default:
V_65 = 0 ;
goto V_54;
}
if ( V_194 -> V_44 > V_44 ) {
V_65 = F_138 ( V_194 , V_44 ) ;
if ( V_65 )
goto V_54;
V_65 = - V_48 ;
}
V_100 = F_22 ( V_194 ) ;
switch ( V_194 -> V_200 ) {
case V_201 :
if ( ! F_73 ( & V_100 -> V_88 , & V_100 -> V_35 , V_194 -> V_44 ,
V_109 , V_194 -> V_98 ) )
break;
case V_202 :
V_194 -> V_98 = ~ F_148 ( F_73 ( & V_100 -> V_88 ,
& V_100 -> V_35 ,
V_194 -> V_44 ,
V_109 , 0 ) ) ;
if ( F_149 ( V_194 ) )
goto V_54;
}
V_65 = 0 ;
F_20 ( V_31 ) -> V_33 = 1 ;
switch ( V_207 ) {
case V_208 :
{
struct V_101 * V_188 ;
if ( ! F_114 ( V_194 , sizeof( * V_188 ) ) ) {
V_65 = - V_48 ;
goto V_54;
}
V_188 = (struct V_101 * ) F_150 ( V_194 ) ;
F_20 ( V_31 ) -> V_198 = 1 ;
V_65 = F_96 ( V_29 , V_63 , & V_188 -> V_119 ) ;
break;
}
case V_210 :
V_65 = F_117 ( V_29 , V_63 , V_194 ) ;
break;
case V_113 :
V_65 = F_128 ( V_29 , V_63 , V_194 ) ;
break;
case V_209 :
{
struct V_101 * V_188 ;
if ( ! F_114 ( V_194 , sizeof( * V_188 ) ) ) {
V_65 = - V_48 ;
goto V_54;
}
V_188 = (struct V_101 * ) F_150 ( V_194 ) ;
F_133 ( V_29 , V_63 , & V_188 -> V_119 ) ;
}
}
V_54:
F_68 ( V_194 ) ;
return V_65 ;
}
int F_151 ( struct V_28 * V_29 , struct V_122 * V_63 ,
struct V_30 * V_31 )
{
F_20 ( V_31 ) -> V_33 = 0 ;
F_20 ( V_31 ) -> V_198 = 0 ;
if ( V_29 -> V_32 )
return 0 ;
switch ( V_31 -> V_34 ) {
case F_5 ( V_7 ) :
return F_134 ( V_29 , V_63 , V_31 ) ;
#if F_6 ( V_10 )
case F_5 ( V_11 ) :
return F_143 ( V_29 , V_63 , V_31 ) ;
#endif
}
return 0 ;
}
static void F_152 ( unsigned long V_50 )
{
struct V_28 * V_29 = ( void * ) V_50 ;
F_32 ( & V_29 -> V_51 ) ;
if ( V_29 -> V_152 <
V_29 -> V_147 )
V_29 -> V_152 ++ ;
F_103 ( V_29 , NULL , V_29 -> V_152 ) ;
F_39 ( & V_29 -> V_51 ) ;
}
void F_153 ( struct V_28 * V_29 )
{
V_29 -> V_124 = 4 ;
V_29 -> V_126 = 512 ;
V_29 -> V_139 = 1 ;
V_29 -> V_121 = 2 ;
V_29 -> V_147 = 2 ;
V_29 -> V_94 = V_96 ;
V_29 -> V_95 = 10 * V_96 ;
V_29 -> V_148 = 125 * V_96 / 4 ;
V_29 -> V_149 = 125 * V_96 ;
V_29 -> V_183 = 255 * V_96 ;
V_29 -> V_136 = 260 * V_96 ;
F_154 ( & V_29 -> V_51 ) ;
F_90 ( & V_29 -> V_140 ,
F_99 , 0 ) ;
F_90 ( & V_29 -> V_146 ,
F_99 , 0 ) ;
F_90 ( & V_29 -> V_150 , F_152 ,
( unsigned long ) V_29 ) ;
}
void F_155 ( struct V_28 * V_29 )
{
V_29 -> V_152 = 0 ;
if ( V_29 -> V_32 )
return;
F_44 ( & V_29 -> V_150 , V_62 ) ;
}
void F_156 ( struct V_28 * V_29 )
{
struct V_13 * V_14 ;
struct V_21 * V_24 ;
struct V_25 * V_26 , * V_153 ;
V_18 V_47 ;
int V_45 ;
F_107 ( & V_29 -> V_140 ) ;
F_107 ( & V_29 -> V_146 ) ;
F_107 ( & V_29 -> V_150 ) ;
F_157 ( & V_29 -> V_51 ) ;
V_14 = F_35 ( V_29 -> V_14 , V_29 ) ;
if ( ! V_14 )
goto V_54;
V_29 -> V_14 = NULL ;
V_47 = V_14 -> V_47 ;
for ( V_45 = 0 ; V_45 < V_14 -> V_19 ; V_45 ++ ) {
F_112 (mp, p, n, &mdb->mhash[i],
hlist[ver]) {
F_37 ( & V_24 -> V_53 ) ;
F_37 ( & V_24 -> V_58 ) ;
F_38 ( & V_24 -> V_38 , F_30 ) ;
}
}
if ( V_14 -> V_39 ) {
F_158 ( & V_29 -> V_51 ) ;
F_159 () ;
F_157 ( & V_29 -> V_51 ) ;
F_41 ( V_14 -> V_39 ) ;
}
V_14 -> V_39 = V_14 ;
F_38 ( & V_14 -> V_38 , F_23 ) ;
V_54:
F_158 ( & V_29 -> V_51 ) ;
}
int F_160 ( struct V_28 * V_29 , unsigned long V_211 )
{
int V_65 = - V_212 ;
F_157 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) )
goto V_213;
switch ( V_211 ) {
case 0 :
case 2 :
F_37 ( & V_29 -> V_140 ) ;
case 1 :
V_29 -> V_139 = V_211 ;
V_65 = 0 ;
break;
default:
V_65 = - V_48 ;
break;
}
V_213:
F_158 ( & V_29 -> V_51 ) ;
return V_65 ;
}
int F_161 ( struct V_122 * V_26 , unsigned long V_211 )
{
struct V_28 * V_29 = V_26 -> V_29 ;
int V_65 = - V_212 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) || V_26 -> V_134 == V_135 )
goto V_213;
switch ( V_211 ) {
case 0 :
case 1 :
case 2 :
V_26 -> V_139 = V_211 ;
V_65 = 0 ;
if ( V_211 < 2 && ! F_46 ( & V_26 -> V_141 ) )
F_98 ( & V_26 -> V_141 ) ;
if ( V_211 == 1 )
break;
F_37 ( & V_26 -> V_140 ) ;
if ( V_211 == 0 )
break;
F_120 ( V_29 , V_26 ) ;
break;
default:
V_65 = - V_48 ;
break;
}
V_213:
F_39 ( & V_29 -> V_51 ) ;
return V_65 ;
}
int F_162 ( struct V_28 * V_29 , unsigned long V_211 )
{
struct V_122 * V_63 ;
int V_65 = 0 ;
struct V_13 * V_14 ;
F_157 ( & V_29 -> V_51 ) ;
if ( V_29 -> V_32 == ! V_211 )
goto V_213;
V_29 -> V_32 = ! V_211 ;
if ( V_29 -> V_32 )
goto V_213;
if ( ! F_33 ( V_29 -> V_52 ) )
goto V_213;
V_14 = F_35 ( V_29 -> V_14 , V_29 ) ;
if ( V_14 ) {
if ( V_14 -> V_39 ) {
V_65 = - V_129 ;
V_214:
V_29 -> V_32 = ! ! V_211 ;
goto V_213;
}
V_65 = F_47 ( & V_29 -> V_14 , V_14 -> V_19 ,
V_29 -> V_124 ) ;
if ( V_65 )
goto V_214;
}
F_155 ( V_29 ) ;
F_163 (port, &br->port_list, list) {
if ( V_63 -> V_134 == V_135 ||
V_63 -> V_134 == V_151 )
continue;
F_108 ( V_63 ) ;
}
V_213:
F_158 ( & V_29 -> V_51 ) ;
return V_65 ;
}
int F_164 ( struct V_28 * V_29 , unsigned long V_211 )
{
int V_65 = - V_212 ;
V_18 V_39 ;
struct V_13 * V_14 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) )
goto V_213;
V_65 = - V_48 ;
if ( ! F_165 ( V_211 ) )
goto V_213;
V_14 = F_35 ( V_29 -> V_14 , V_29 ) ;
if ( V_14 && V_211 < V_14 -> V_57 )
goto V_213;
V_65 = 0 ;
V_39 = V_29 -> V_126 ;
V_29 -> V_126 = V_211 ;
if ( V_14 ) {
if ( V_14 -> V_39 ) {
V_65 = - V_129 ;
V_214:
V_29 -> V_126 = V_39 ;
goto V_213;
}
V_65 = F_47 ( & V_29 -> V_14 , V_29 -> V_126 ,
V_29 -> V_124 ) ;
if ( V_65 )
goto V_214;
}
V_213:
F_39 ( & V_29 -> V_51 ) ;
return V_65 ;
}
