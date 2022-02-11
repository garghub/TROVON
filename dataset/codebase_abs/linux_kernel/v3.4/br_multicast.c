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
F_37 ( & V_24 -> V_38 , F_30 ) ;
V_54:
F_38 ( & V_29 -> V_51 ) ;
}
static void F_39 ( struct V_28 * V_29 ,
struct V_49 * V_58 )
{
struct V_13 * V_14 ;
struct V_21 * V_24 ;
struct V_49 * V_26 ;
struct V_49 T_2 * * V_59 ;
V_14 = F_35 ( V_29 -> V_14 , V_29 ) ;
V_24 = F_15 ( V_14 , & V_58 -> V_2 ) ;
if ( F_40 ( ! V_24 ) )
return;
for ( V_59 = & V_24 -> V_56 ;
( V_26 = F_35 ( * V_59 , V_29 ) ) != NULL ;
V_59 = & V_26 -> V_60 ) {
if ( V_26 != V_58 )
continue;
F_41 ( * V_59 , V_26 -> V_60 ) ;
F_42 ( & V_26 -> V_55 ) ;
F_43 ( & V_26 -> V_53 ) ;
F_37 ( & V_26 -> V_38 , F_29 ) ;
if ( ! V_24 -> V_56 && ! V_24 -> V_55 &&
F_33 ( V_29 -> V_52 ) )
F_44 ( & V_24 -> V_53 , V_61 ) ;
return;
}
F_40 ( 1 ) ;
}
static void F_45 ( unsigned long V_50 )
{
struct V_49 * V_58 = ( void * ) V_50 ;
struct V_28 * V_29 = V_58 -> V_62 -> V_29 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) || F_34 ( & V_58 -> V_53 ) ||
F_46 ( & V_58 -> V_55 ) )
goto V_54;
F_39 ( V_29 , V_58 ) ;
V_54:
F_38 ( & V_29 -> V_51 ) ;
}
static int F_47 ( struct V_13 T_2 * * V_63 , int V_19 ,
int V_42 )
{
struct V_13 * V_39 = F_48 ( * V_63 , 1 ) ;
struct V_13 * V_14 ;
int V_64 ;
V_14 = F_49 ( sizeof( * V_14 ) , V_65 ) ;
if ( ! V_14 )
return - V_66 ;
V_14 -> V_19 = V_19 ;
V_14 -> V_39 = V_39 ;
V_14 -> V_40 = F_50 ( V_19 * sizeof( * V_14 -> V_40 ) , V_65 ) ;
if ( ! V_14 -> V_40 ) {
F_25 ( V_14 ) ;
return - V_66 ;
}
V_14 -> V_57 = V_39 ? V_39 -> V_57 : 0 ;
V_14 -> V_47 = V_39 ? V_39 -> V_47 ^ 1 : 0 ;
if ( ! V_39 || V_42 )
F_51 ( & V_14 -> V_16 , sizeof( V_14 -> V_16 ) ) ;
else
V_14 -> V_16 = V_39 -> V_16 ;
if ( ! V_39 )
goto V_54;
V_64 = F_26 ( V_14 , V_39 , V_42 ) ;
if ( V_64 ) {
F_25 ( V_14 -> V_40 ) ;
F_25 ( V_14 ) ;
return V_64 ;
}
F_37 ( & V_14 -> V_38 , F_23 ) ;
V_54:
F_41 ( * V_63 , V_14 ) ;
return 0 ;
}
static struct V_30 * F_52 ( struct V_28 * V_29 ,
T_1 V_67 )
{
struct V_30 * V_31 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
V_31 = F_53 ( V_29 -> V_52 , sizeof( * V_71 ) + sizeof( * V_73 ) +
sizeof( * V_69 ) + 4 ) ;
if ( ! V_31 )
goto V_54;
V_31 -> V_34 = F_5 ( V_7 ) ;
F_54 ( V_31 ) ;
V_71 = F_55 ( V_31 ) ;
memcpy ( V_71 -> V_74 , V_29 -> V_52 -> V_75 , 6 ) ;
V_71 -> V_76 [ 0 ] = 1 ;
V_71 -> V_76 [ 1 ] = 0 ;
V_71 -> V_76 [ 2 ] = 0x5e ;
V_71 -> V_76 [ 3 ] = 0 ;
V_71 -> V_76 [ 4 ] = 0 ;
V_71 -> V_76 [ 5 ] = 1 ;
V_71 -> V_77 = F_5 ( V_7 ) ;
F_56 ( V_31 , sizeof( * V_71 ) ) ;
F_57 ( V_31 , V_31 -> V_44 ) ;
V_73 = F_21 ( V_31 ) ;
V_73 -> V_78 = 4 ;
V_73 -> V_79 = 6 ;
V_73 -> V_80 = 0xc0 ;
V_73 -> V_81 = F_5 ( sizeof( * V_73 ) + sizeof( * V_69 ) + 4 ) ;
V_73 -> V_82 = 0 ;
V_73 -> V_83 = F_5 ( V_84 ) ;
V_73 -> V_85 = 1 ;
V_73 -> V_34 = V_86 ;
V_73 -> V_87 = 0 ;
V_73 -> V_35 = F_58 ( V_88 ) ;
( ( V_89 * ) & V_73 [ 1 ] ) [ 0 ] = V_90 ;
( ( V_89 * ) & V_73 [ 1 ] ) [ 1 ] = 4 ;
( ( V_89 * ) & V_73 [ 1 ] ) [ 2 ] = 0 ;
( ( V_89 * ) & V_73 [ 1 ] ) [ 3 ] = 0 ;
F_59 ( V_73 ) ;
F_56 ( V_31 , 24 ) ;
F_60 ( V_31 , V_31 -> V_44 ) ;
V_69 = F_61 ( V_31 ) ;
V_69 -> type = V_91 ;
V_69 -> V_92 = ( V_67 ? V_29 -> V_93 :
V_29 -> V_94 ) /
( V_95 / V_96 ) ;
V_69 -> V_67 = V_67 ;
V_69 -> V_97 = 0 ;
V_69 -> V_97 = F_62 ( ( void * ) V_69 , sizeof( struct V_68 ) ) ;
F_56 ( V_31 , sizeof( * V_69 ) ) ;
F_63 ( V_31 , sizeof( * V_71 ) ) ;
V_54:
return V_31 ;
}
static struct V_30 * F_64 ( struct V_28 * V_29 ,
const struct V_1 * V_67 )
{
struct V_30 * V_31 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_70 * V_71 ;
V_89 * V_102 ;
unsigned long V_103 ;
V_31 = F_53 ( V_29 -> V_52 , sizeof( * V_71 ) + sizeof( * V_99 ) +
8 + sizeof( * V_101 ) ) ;
if ( ! V_31 )
goto V_54;
V_31 -> V_34 = F_5 ( V_11 ) ;
F_54 ( V_31 ) ;
V_71 = F_55 ( V_31 ) ;
memcpy ( V_71 -> V_74 , V_29 -> V_52 -> V_75 , 6 ) ;
V_71 -> V_77 = F_5 ( V_11 ) ;
F_56 ( V_31 , sizeof( * V_71 ) ) ;
F_57 ( V_31 , V_31 -> V_44 ) ;
V_99 = F_22 ( V_31 ) ;
* ( V_17 T_1 * ) V_99 = F_58 ( 0x60000000 ) ;
V_99 -> V_104 = F_5 ( 8 + sizeof( * V_101 ) ) ;
V_99 -> V_105 = V_106 ;
V_99 -> V_107 = 1 ;
F_65 ( & V_99 -> V_35 , F_58 ( 0xff020000 ) , 0 , 0 , F_58 ( 1 ) ) ;
if ( F_66 ( F_67 ( V_29 -> V_52 ) , V_29 -> V_52 , & V_99 -> V_35 , 0 ,
& V_99 -> V_87 ) ) {
F_68 ( V_31 ) ;
return NULL ;
}
F_69 ( & V_99 -> V_35 , V_71 -> V_76 ) ;
V_102 = ( V_89 * ) ( V_99 + 1 ) ;
V_102 [ 0 ] = V_108 ;
V_102 [ 1 ] = 0 ;
V_102 [ 2 ] = V_109 ;
V_102 [ 3 ] = 2 ;
V_102 [ 4 ] = 0 ;
V_102 [ 5 ] = 0 ;
V_102 [ 6 ] = V_110 ;
V_102 [ 7 ] = V_110 ;
F_56 ( V_31 , sizeof( * V_99 ) + 8 ) ;
F_60 ( V_31 , V_31 -> V_44 ) ;
V_101 = (struct V_100 * ) F_70 ( V_31 ) ;
V_103 = F_71 ( V_67 ) ? V_29 -> V_93 :
V_29 -> V_94 ;
V_101 -> V_111 = V_112 ;
V_101 -> V_113 = 0 ;
V_101 -> V_114 = 0 ;
V_101 -> V_115 = F_5 ( ( V_116 ) F_72 ( V_103 ) ) ;
V_101 -> V_117 = 0 ;
V_101 -> V_118 = * V_67 ;
V_101 -> V_114 = F_73 ( & V_99 -> V_87 , & V_99 -> V_35 ,
sizeof( * V_101 ) , V_108 ,
F_74 ( V_101 ,
sizeof( * V_101 ) , 0 ) ) ;
F_56 ( V_31 , sizeof( * V_101 ) ) ;
F_63 ( V_31 , sizeof( * V_71 ) ) ;
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
static struct V_21 * F_76 (
struct V_28 * V_29 , struct V_119 * V_62 ,
struct V_3 * V_67 , int V_23 )
{
struct V_13 * V_14 ;
struct V_21 * V_24 ;
struct V_25 * V_26 ;
unsigned V_120 = 0 ;
unsigned V_19 ;
int V_42 ;
int V_64 ;
V_14 = F_48 ( V_29 -> V_14 , 1 ) ;
F_27 (mp, p, &mdb->mhash[hash], hlist[mdb->ver]) {
V_120 ++ ;
if ( F_77 ( F_4 ( V_67 , & V_24 -> V_2 ) ) )
return V_24 ;
}
V_42 = 0 ;
V_19 = V_14 -> V_19 ;
if ( F_77 ( V_120 > V_29 -> V_121 && V_120 ) ) {
if ( F_78 () )
F_79 ( V_29 , L_1
L_2 ,
V_62 ? V_62 -> V_52 -> V_122 : V_29 -> V_52 -> V_122 ) ;
V_42 = V_29 -> V_121 ;
}
if ( V_14 -> V_57 >= V_19 ) {
V_19 *= 2 ;
if ( F_77 ( V_19 >= V_29 -> V_123 ) ) {
F_80 ( V_29 , L_3
L_4 ,
V_62 ? V_62 -> V_52 -> V_122 : V_29 -> V_52 -> V_122 , V_19 ) ;
V_64 = - V_124 ;
V_125:
V_29 -> V_32 = 1 ;
goto V_64;
}
}
if ( V_19 > V_14 -> V_19 || V_42 ) {
if ( V_14 -> V_39 ) {
if ( F_78 () )
F_79 ( V_29 , L_1
L_5 ,
V_62 ? V_62 -> V_52 -> V_122 : V_29 -> V_52 -> V_122 ) ;
V_64 = - V_126 ;
goto V_64;
}
V_64 = F_47 ( & V_29 -> V_14 , V_19 , V_42 ) ;
if ( V_64 ) {
F_80 ( V_29 , L_6
L_7 ,
V_62 ? V_62 -> V_52 -> V_122 : V_29 -> V_52 -> V_122 ,
V_14 -> V_57 , V_64 ) ;
goto V_125;
}
V_64 = - V_127 ;
goto V_64;
}
return NULL ;
V_64:
V_24 = F_81 ( V_64 ) ;
return V_24 ;
}
static struct V_21 * F_82 (
struct V_28 * V_29 , struct V_119 * V_62 ,
struct V_3 * V_67 )
{
struct V_13 * V_14 ;
struct V_21 * V_24 ;
int V_23 ;
int V_64 ;
V_14 = F_48 ( V_29 -> V_14 , 1 ) ;
if ( ! V_14 ) {
V_64 = F_47 ( & V_29 -> V_14 , V_128 , 0 ) ;
if ( V_64 )
return F_81 ( V_64 ) ;
goto V_129;
}
V_23 = F_12 ( V_14 , V_67 ) ;
V_24 = F_76 ( V_29 , V_62 , V_67 , V_23 ) ;
switch ( F_83 ( V_24 ) ) {
case 0 :
break;
case - V_127 :
V_129:
V_14 = F_48 ( V_29 -> V_14 , 1 ) ;
V_23 = F_12 ( V_14 , V_67 ) ;
break;
default:
goto V_54;
}
V_24 = F_50 ( sizeof( * V_24 ) , V_65 ) ;
if ( F_77 ( ! V_24 ) )
return F_81 ( - V_66 ) ;
V_24 -> V_29 = V_29 ;
V_24 -> V_2 = * V_67 ;
F_84 ( & V_24 -> V_53 , F_31 ,
( unsigned long ) V_24 ) ;
F_85 ( & V_24 -> V_46 [ V_14 -> V_47 ] , & V_14 -> V_40 [ V_23 ] ) ;
V_14 -> V_57 ++ ;
V_54:
return V_24 ;
}
static int F_86 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
struct V_3 * V_67 )
{
struct V_21 * V_24 ;
struct V_49 * V_26 ;
struct V_49 T_2 * * V_59 ;
unsigned long V_130 = V_61 ;
int V_64 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) ||
( V_62 && V_62 -> V_131 == V_132 ) )
goto V_54;
V_24 = F_82 ( V_29 , V_62 , V_67 ) ;
V_64 = F_83 ( V_24 ) ;
if ( F_87 ( V_24 ) )
goto V_64;
if ( ! V_62 ) {
V_24 -> V_55 = true ;
F_44 ( & V_24 -> V_53 , V_130 + V_29 -> V_133 ) ;
goto V_54;
}
for ( V_59 = & V_24 -> V_56 ;
( V_26 = F_35 ( * V_59 , V_29 ) ) != NULL ;
V_59 = & V_26 -> V_60 ) {
if ( V_26 -> V_62 == V_62 )
goto V_134;
if ( ( unsigned long ) V_26 -> V_62 < ( unsigned long ) V_62 )
break;
}
V_26 = F_50 ( sizeof( * V_26 ) , V_65 ) ;
V_64 = - V_66 ;
if ( F_77 ( ! V_26 ) )
goto V_64;
V_26 -> V_2 = * V_67 ;
V_26 -> V_62 = V_62 ;
V_26 -> V_60 = * V_59 ;
F_28 ( & V_26 -> V_55 , & V_62 -> V_55 ) ;
F_84 ( & V_26 -> V_53 , F_45 ,
( unsigned long ) V_26 ) ;
F_41 ( * V_59 , V_26 ) ;
V_134:
F_44 ( & V_26 -> V_53 , V_130 + V_29 -> V_133 ) ;
V_54:
V_64 = 0 ;
V_64:
F_38 ( & V_29 -> V_51 ) ;
return V_64 ;
}
static int F_88 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
T_1 V_67 )
{
struct V_3 V_135 ;
if ( F_89 ( V_67 ) )
return 0 ;
V_135 . V_8 . V_9 = V_67 ;
V_135 . V_6 = F_5 ( V_7 ) ;
return F_86 ( V_29 , V_62 , & V_135 ) ;
}
static int F_90 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
const struct V_1 * V_67 )
{
struct V_3 V_135 ;
if ( ! F_1 ( V_67 ) )
return 0 ;
V_135 . V_8 . V_12 = * V_67 ;
V_135 . V_6 = F_5 ( V_11 ) ;
return F_86 ( V_29 , V_62 , & V_135 ) ;
}
static void F_91 ( unsigned long V_50 )
{
struct V_119 * V_62 = ( void * ) V_50 ;
struct V_28 * V_29 = V_62 -> V_29 ;
F_32 ( & V_29 -> V_51 ) ;
if ( V_62 -> V_136 != 1 ||
F_34 ( & V_62 -> V_137 ) ||
F_46 ( & V_62 -> V_138 ) )
goto V_54;
F_92 ( & V_62 -> V_138 ) ;
V_54:
F_38 ( & V_29 -> V_51 ) ;
}
static void F_93 ( unsigned long V_50 )
{
}
static void F_94 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
struct V_3 * V_15 )
{
struct V_30 * V_31 ;
V_31 = F_75 ( V_29 , V_15 ) ;
if ( ! V_31 )
return;
if ( V_62 ) {
F_95 ( V_31 , sizeof( struct V_70 ) ) ;
V_31 -> V_52 = V_62 -> V_52 ;
F_96 ( V_139 , V_140 , V_31 , NULL , V_31 -> V_52 ,
V_141 ) ;
} else
F_97 ( V_31 ) ;
}
static void F_98 ( struct V_28 * V_29 ,
struct V_119 * V_62 , V_18 V_142 )
{
unsigned long time ;
struct V_3 V_135 ;
if ( ! F_33 ( V_29 -> V_52 ) || V_29 -> V_32 ||
F_34 ( & V_29 -> V_143 ) )
return;
memset ( & V_135 . V_8 , 0 , sizeof( V_135 . V_8 ) ) ;
V_135 . V_6 = F_5 ( V_7 ) ;
F_94 ( V_29 , V_62 , & V_135 ) ;
#if F_6 ( V_10 )
V_135 . V_6 = F_5 ( V_11 ) ;
F_94 ( V_29 , V_62 , & V_135 ) ;
#endif
time = V_61 ;
time += V_142 < V_29 -> V_144 ?
V_29 -> V_145 :
V_29 -> V_146 ;
F_44 ( V_62 ? & V_62 -> V_147 :
& V_29 -> V_147 , time ) ;
}
static void F_99 ( unsigned long V_50 )
{
struct V_119 * V_62 = ( void * ) V_50 ;
struct V_28 * V_29 = V_62 -> V_29 ;
F_32 ( & V_29 -> V_51 ) ;
if ( V_62 -> V_131 == V_132 ||
V_62 -> V_131 == V_148 )
goto V_54;
if ( V_62 -> V_149 <
V_29 -> V_144 )
V_62 -> V_149 ++ ;
F_98 ( V_62 -> V_29 , V_62 ,
V_62 -> V_149 ) ;
V_54:
F_38 ( & V_29 -> V_51 ) ;
}
void F_100 ( struct V_119 * V_62 )
{
V_62 -> V_136 = 1 ;
F_84 ( & V_62 -> V_137 , F_91 ,
( unsigned long ) V_62 ) ;
F_84 ( & V_62 -> V_147 ,
F_99 , ( unsigned long ) V_62 ) ;
}
void F_101 ( struct V_119 * V_62 )
{
F_102 ( & V_62 -> V_137 ) ;
}
static void F_103 ( struct V_119 * V_62 )
{
V_62 -> V_149 = 0 ;
if ( F_104 ( & V_62 -> V_147 ) >= 0 ||
F_43 ( & V_62 -> V_147 ) )
F_44 ( & V_62 -> V_147 , V_61 ) ;
}
void F_105 ( struct V_119 * V_62 )
{
struct V_28 * V_29 = V_62 -> V_29 ;
F_32 ( & V_29 -> V_51 ) ;
if ( V_29 -> V_32 || ! F_33 ( V_29 -> V_52 ) )
goto V_54;
F_103 ( V_62 ) ;
V_54:
F_38 ( & V_29 -> V_51 ) ;
}
void F_106 ( struct V_119 * V_62 )
{
struct V_28 * V_29 = V_62 -> V_29 ;
struct V_49 * V_58 ;
struct V_25 * V_26 , * V_150 ;
F_32 ( & V_29 -> V_51 ) ;
F_107 (pg, p, n, &port->mglist, mglist)
F_39 ( V_29 , V_58 ) ;
if ( ! F_46 ( & V_62 -> V_138 ) )
F_92 ( & V_62 -> V_138 ) ;
F_43 ( & V_62 -> V_137 ) ;
F_43 ( & V_62 -> V_147 ) ;
F_38 ( & V_29 -> V_51 ) ;
}
static int F_108 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
struct V_30 * V_31 )
{
struct V_151 * V_69 ;
struct V_152 * V_153 ;
int V_45 ;
int V_44 ;
int V_154 ;
int type ;
int V_64 = 0 ;
T_1 V_67 ;
if ( ! F_109 ( V_31 , sizeof( * V_69 ) ) )
return - V_48 ;
V_69 = F_110 ( V_31 ) ;
V_154 = F_111 ( V_69 -> V_155 ) ;
V_44 = sizeof( * V_69 ) ;
for ( V_45 = 0 ; V_45 < V_154 ; V_45 ++ ) {
V_44 += sizeof( * V_153 ) ;
if ( ! F_109 ( V_31 , V_44 ) )
return - V_48 ;
V_153 = ( void * ) ( V_31 -> V_50 + V_44 - sizeof( * V_153 ) ) ;
V_67 = V_153 -> V_156 ;
type = V_153 -> V_157 ;
V_44 += F_111 ( V_153 -> V_158 ) * 4 ;
if ( ! F_109 ( V_31 , V_44 ) )
return - V_48 ;
switch ( type ) {
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
break;
default:
continue;
}
V_64 = F_88 ( V_29 , V_62 , V_67 ) ;
if ( V_64 )
break;
}
return V_64 ;
}
static int F_112 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
struct V_30 * V_31 )
{
struct V_165 * V_166 ;
struct V_167 * V_153 ;
int V_45 ;
int V_44 ;
int V_154 ;
int V_64 = 0 ;
if ( ! F_109 ( V_31 , sizeof( * V_166 ) ) )
return - V_48 ;
V_166 = F_70 ( V_31 ) ;
V_154 = F_111 ( V_166 -> V_168 . V_169 [ 1 ] ) ;
V_44 = sizeof( * V_166 ) ;
for ( V_45 = 0 ; V_45 < V_154 ; V_45 ++ ) {
T_3 * V_170 , V_171 ;
V_170 = F_113 ( V_31 ,
V_44 + F_114 ( struct V_167 ,
V_158 ) ,
sizeof( V_171 ) , & V_171 ) ;
if ( ! V_170 )
return - V_48 ;
if ( ! F_109 ( V_31 ,
V_44 + sizeof( * V_153 ) +
sizeof( struct V_1 ) * F_111 ( * V_170 ) ) )
return - V_48 ;
V_153 = (struct V_167 * ) ( V_31 -> V_50 + V_44 ) ;
V_44 += sizeof( * V_153 ) +
sizeof( struct V_1 ) * F_111 ( * V_170 ) ;
switch ( V_153 -> V_157 ) {
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
break;
default:
continue;
}
V_64 = F_90 ( V_29 , V_62 , & V_153 -> V_156 ) ;
if ( ! V_64 )
break;
}
return V_64 ;
}
static void F_115 ( struct V_28 * V_29 ,
struct V_119 * V_62 )
{
struct V_119 * V_26 ;
struct V_25 * V_150 , * V_178 = NULL ;
F_27 (p, n, &br->router_list, rlist) {
if ( ( unsigned long ) V_62 >= ( unsigned long ) V_26 )
break;
V_178 = V_150 ;
}
if ( V_178 )
F_116 ( V_178 , & V_62 -> V_138 ) ;
else
F_85 ( & V_62 -> V_138 , & V_29 -> V_179 ) ;
}
static void F_117 ( struct V_28 * V_29 ,
struct V_119 * V_62 )
{
unsigned long V_130 = V_61 ;
if ( ! V_62 ) {
if ( V_29 -> V_136 == 1 )
F_44 ( & V_29 -> V_137 ,
V_130 + V_29 -> V_180 ) ;
return;
}
if ( V_62 -> V_136 != 1 )
return;
if ( ! F_46 ( & V_62 -> V_138 ) )
goto V_53;
F_115 ( V_29 , V_62 ) ;
V_53:
F_44 ( & V_62 -> V_137 ,
V_130 + V_29 -> V_180 ) ;
}
static void F_118 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
int V_87 )
{
if ( V_87 )
F_44 ( & V_29 -> V_143 ,
V_61 + V_29 -> V_180 ) ;
else if ( F_34 ( & V_29 -> V_143 ) )
return;
F_117 ( V_29 , V_62 ) ;
}
static int F_119 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
struct V_30 * V_31 )
{
const struct V_72 * V_73 = F_21 ( V_31 ) ;
struct V_68 * V_69 = F_61 ( V_31 ) ;
struct V_21 * V_24 ;
struct V_181 * V_182 ;
struct V_49 * V_26 ;
struct V_49 T_2 * * V_59 ;
unsigned long V_183 ;
unsigned long V_130 = V_61 ;
T_1 V_67 ;
int V_64 = 0 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) ||
( V_62 && V_62 -> V_131 == V_132 ) )
goto V_54;
F_118 ( V_29 , V_62 , ! ! V_73 -> V_87 ) ;
V_67 = V_69 -> V_67 ;
if ( V_31 -> V_44 == sizeof( * V_69 ) ) {
V_183 = V_69 -> V_92 * ( V_95 / V_96 ) ;
if ( ! V_183 ) {
V_183 = 10 * V_95 ;
V_67 = 0 ;
}
} else {
if ( ! F_109 ( V_31 , sizeof( struct V_181 ) ) ) {
V_64 = - V_48 ;
goto V_54;
}
V_182 = F_120 ( V_31 ) ;
if ( V_182 -> V_170 )
goto V_54;
V_183 = V_182 -> V_92 ?
F_121 ( V_182 -> V_92 ) * ( V_95 / V_96 ) : 1 ;
}
if ( ! V_67 )
goto V_54;
V_24 = F_16 ( F_35 ( V_29 -> V_14 , V_29 ) , V_67 ) ;
if ( ! V_24 )
goto V_54;
V_183 *= V_29 -> V_184 ;
if ( V_24 -> V_55 &&
( F_34 ( & V_24 -> V_53 ) ?
F_122 ( V_24 -> V_53 . V_185 , V_130 + V_183 ) :
F_104 ( & V_24 -> V_53 ) >= 0 ) )
F_44 ( & V_24 -> V_53 , V_130 + V_183 ) ;
for ( V_59 = & V_24 -> V_56 ;
( V_26 = F_35 ( * V_59 , V_29 ) ) != NULL ;
V_59 = & V_26 -> V_60 ) {
if ( F_34 ( & V_26 -> V_53 ) ?
F_122 ( V_26 -> V_53 . V_185 , V_130 + V_183 ) :
F_104 ( & V_26 -> V_53 ) >= 0 )
F_44 ( & V_26 -> V_53 , V_130 + V_183 ) ;
}
V_54:
F_38 ( & V_29 -> V_51 ) ;
return V_64 ;
}
static int F_123 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
struct V_30 * V_31 )
{
const struct V_98 * V_99 = F_22 ( V_31 ) ;
struct V_100 * V_186 = (struct V_100 * ) F_70 ( V_31 ) ;
struct V_21 * V_24 ;
struct V_187 * V_188 ;
struct V_49 * V_26 ;
struct V_49 T_2 * * V_59 ;
unsigned long V_183 ;
unsigned long V_130 = V_61 ;
const struct V_1 * V_67 = NULL ;
int V_64 = 0 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) ||
( V_62 && V_62 -> V_131 == V_132 ) )
goto V_54;
F_118 ( V_29 , V_62 , ! F_71 ( & V_99 -> V_87 ) ) ;
if ( V_31 -> V_44 == sizeof( * V_186 ) ) {
if ( ! F_109 ( V_31 , sizeof( * V_186 ) ) ) {
V_64 = - V_48 ;
goto V_54;
}
V_186 = (struct V_100 * ) F_70 ( V_31 ) ;
V_183 = F_124 ( F_5 ( V_186 -> V_115 ) ) ;
if ( V_183 )
V_67 = & V_186 -> V_118 ;
} else if ( V_31 -> V_44 >= sizeof( * V_188 ) ) {
if ( ! F_109 ( V_31 , sizeof( * V_188 ) ) ) {
V_64 = - V_48 ;
goto V_54;
}
V_188 = (struct V_187 * ) F_70 ( V_31 ) ;
if ( ! V_188 -> V_189 )
V_67 = & V_188 -> V_190 ;
V_183 = V_188 -> V_191 ? F_125 ( V_188 -> V_191 ) : 1 ;
}
if ( ! V_67 )
goto V_54;
V_24 = F_17 ( F_35 ( V_29 -> V_14 , V_29 ) , V_67 ) ;
if ( ! V_24 )
goto V_54;
V_183 *= V_29 -> V_184 ;
if ( V_24 -> V_55 &&
( F_34 ( & V_24 -> V_53 ) ?
F_122 ( V_24 -> V_53 . V_185 , V_130 + V_183 ) :
F_104 ( & V_24 -> V_53 ) >= 0 ) )
F_44 ( & V_24 -> V_53 , V_130 + V_183 ) ;
for ( V_59 = & V_24 -> V_56 ;
( V_26 = F_35 ( * V_59 , V_29 ) ) != NULL ;
V_59 = & V_26 -> V_60 ) {
if ( F_34 ( & V_26 -> V_53 ) ?
F_122 ( V_26 -> V_53 . V_185 , V_130 + V_183 ) :
F_104 ( & V_26 -> V_53 ) >= 0 )
F_44 ( & V_26 -> V_53 , V_130 + V_183 ) ;
}
V_54:
F_38 ( & V_29 -> V_51 ) ;
return V_64 ;
}
static void F_126 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
struct V_3 * V_67 )
{
struct V_13 * V_14 ;
struct V_21 * V_24 ;
struct V_49 * V_26 ;
unsigned long V_130 ;
unsigned long time ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) ||
( V_62 && V_62 -> V_131 == V_132 ) ||
F_34 ( & V_29 -> V_143 ) )
goto V_54;
V_14 = F_35 ( V_29 -> V_14 , V_29 ) ;
V_24 = F_15 ( V_14 , V_67 ) ;
if ( ! V_24 )
goto V_54;
V_130 = V_61 ;
time = V_130 + V_29 -> V_184 *
V_29 -> V_93 ;
if ( ! V_62 ) {
if ( V_24 -> V_55 &&
( F_34 ( & V_24 -> V_53 ) ?
F_122 ( V_24 -> V_53 . V_185 , time ) :
F_104 ( & V_24 -> V_53 ) >= 0 ) ) {
F_44 ( & V_24 -> V_53 , time ) ;
}
goto V_54;
}
for ( V_26 = F_35 ( V_24 -> V_56 , V_29 ) ;
V_26 != NULL ;
V_26 = F_35 ( V_26 -> V_60 , V_29 ) ) {
if ( V_26 -> V_62 != V_62 )
continue;
if ( ! F_46 ( & V_26 -> V_55 ) &&
( F_34 ( & V_26 -> V_53 ) ?
F_122 ( V_26 -> V_53 . V_185 , time ) :
F_104 ( & V_26 -> V_53 ) >= 0 ) ) {
F_44 ( & V_26 -> V_53 , time ) ;
}
break;
}
V_54:
F_38 ( & V_29 -> V_51 ) ;
}
static void F_127 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
T_1 V_67 )
{
struct V_3 V_135 ;
if ( F_89 ( V_67 ) )
return;
V_135 . V_8 . V_9 = V_67 ;
V_135 . V_6 = F_5 ( V_7 ) ;
F_126 ( V_29 , V_62 , & V_135 ) ;
}
static void F_128 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
const struct V_1 * V_67 )
{
struct V_3 V_135 ;
if ( ! F_1 ( V_67 ) )
return;
V_135 . V_8 . V_12 = * V_67 ;
V_135 . V_6 = F_5 ( V_11 ) ;
F_126 ( V_29 , V_62 , & V_135 ) ;
}
static int F_129 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
struct V_30 * V_31 )
{
struct V_30 * V_192 = V_31 ;
const struct V_72 * V_73 ;
struct V_68 * V_69 ;
unsigned V_44 ;
unsigned V_193 ;
int V_64 ;
if ( ! F_109 ( V_31 , sizeof( * V_73 ) ) )
return - V_48 ;
V_73 = F_21 ( V_31 ) ;
if ( V_73 -> V_79 < 5 || V_73 -> V_78 != 4 )
return - V_48 ;
if ( ! F_109 ( V_31 , F_130 ( V_31 ) ) )
return - V_48 ;
V_73 = F_21 ( V_31 ) ;
if ( F_77 ( F_131 ( ( V_89 * ) V_73 , V_73 -> V_79 ) ) )
return - V_48 ;
if ( V_73 -> V_34 != V_86 ) {
if ( ( V_73 -> V_35 & V_194 ) != V_195 )
F_20 ( V_31 ) -> V_196 = 1 ;
return 0 ;
}
V_44 = F_111 ( V_73 -> V_81 ) ;
if ( V_31 -> V_44 < V_44 || V_44 < F_130 ( V_31 ) )
return - V_48 ;
if ( V_31 -> V_44 > V_44 ) {
V_192 = F_132 ( V_31 , V_65 ) ;
if ( ! V_192 )
return - V_66 ;
V_64 = F_133 ( V_192 , V_44 ) ;
if ( V_64 )
goto V_197;
}
V_44 -= F_130 ( V_192 ) ;
V_193 = F_134 ( V_192 ) + F_130 ( V_192 ) ;
F_63 ( V_192 , V_193 ) ;
F_135 ( V_192 ) ;
V_64 = - V_48 ;
if ( ! F_109 ( V_192 , sizeof( * V_69 ) ) )
goto V_54;
switch ( V_192 -> V_198 ) {
case V_199 :
if ( ! F_136 ( V_192 -> V_97 ) )
break;
case V_200 :
V_192 -> V_97 = 0 ;
if ( F_137 ( V_192 ) )
goto V_54;
}
V_64 = 0 ;
F_20 ( V_31 ) -> V_33 = 1 ;
V_69 = F_61 ( V_192 ) ;
switch ( V_69 -> type ) {
case V_201 :
case V_202 :
F_20 ( V_31 ) -> V_196 = 1 ;
V_64 = F_88 ( V_29 , V_62 , V_69 -> V_67 ) ;
break;
case V_203 :
V_64 = F_108 ( V_29 , V_62 , V_192 ) ;
break;
case V_91 :
V_64 = F_119 ( V_29 , V_62 , V_192 ) ;
break;
case V_204 :
F_127 ( V_29 , V_62 , V_69 -> V_67 ) ;
break;
}
V_54:
F_95 ( V_192 , V_193 ) ;
V_197:
if ( V_192 != V_31 )
F_68 ( V_192 ) ;
return V_64 ;
}
static int F_138 ( struct V_28 * V_29 ,
struct V_119 * V_62 ,
struct V_30 * V_31 )
{
struct V_30 * V_192 ;
const struct V_98 * V_99 ;
V_89 V_205 ;
V_89 V_105 ;
T_3 V_83 ;
unsigned V_44 ;
int V_193 ;
int V_64 ;
if ( ! F_109 ( V_31 , sizeof( * V_99 ) ) )
return - V_48 ;
V_99 = F_22 ( V_31 ) ;
if ( V_99 -> V_78 != 6 ||
V_99 -> V_105 != V_106 ||
V_99 -> V_104 == 0 )
return 0 ;
V_44 = F_111 ( V_99 -> V_104 ) + sizeof( * V_99 ) ;
if ( V_31 -> V_44 < V_44 )
return - V_48 ;
V_105 = V_99 -> V_105 ;
V_193 = F_139 ( V_31 , sizeof( * V_99 ) , & V_105 , & V_83 ) ;
if ( V_193 < 0 || V_105 != V_108 )
return 0 ;
V_192 = F_132 ( V_31 , V_65 ) ;
if ( ! V_192 )
return - V_66 ;
V_64 = - V_48 ;
if ( ! F_109 ( V_192 , V_193 + sizeof( struct V_165 ) ) )
goto V_54;
V_44 -= V_193 - F_134 ( V_192 ) ;
F_63 ( V_192 , V_193 ) ;
F_135 ( V_192 ) ;
F_140 ( V_192 , F_141 ( V_192 ) ,
F_142 ( V_192 ) ) ;
V_205 = F_70 ( V_192 ) -> V_205 ;
switch ( V_205 ) {
case V_112 :
case V_206 :
case V_207 :
case V_208 :
break;
default:
V_64 = 0 ;
goto V_54;
}
if ( V_192 -> V_44 > V_44 ) {
V_64 = F_133 ( V_192 , V_44 ) ;
if ( V_64 )
goto V_54;
V_64 = - V_48 ;
}
V_99 = F_22 ( V_192 ) ;
switch ( V_192 -> V_198 ) {
case V_199 :
if ( ! F_73 ( & V_99 -> V_87 , & V_99 -> V_35 , V_192 -> V_44 ,
V_108 , V_192 -> V_97 ) )
break;
case V_200 :
V_192 -> V_97 = ~ F_143 ( F_73 ( & V_99 -> V_87 ,
& V_99 -> V_35 ,
V_192 -> V_44 ,
V_108 , 0 ) ) ;
if ( F_144 ( V_192 ) )
goto V_54;
}
V_64 = 0 ;
F_20 ( V_31 ) -> V_33 = 1 ;
switch ( V_205 ) {
case V_206 :
{
struct V_100 * V_186 ;
if ( ! F_109 ( V_192 , sizeof( * V_186 ) ) ) {
V_64 = - V_48 ;
goto V_54;
}
V_186 = (struct V_100 * ) F_145 ( V_192 ) ;
F_20 ( V_31 ) -> V_196 = 1 ;
V_64 = F_90 ( V_29 , V_62 , & V_186 -> V_118 ) ;
break;
}
case V_208 :
V_64 = F_112 ( V_29 , V_62 , V_192 ) ;
break;
case V_112 :
V_64 = F_123 ( V_29 , V_62 , V_192 ) ;
break;
case V_207 :
{
struct V_100 * V_186 ;
if ( ! F_109 ( V_192 , sizeof( * V_186 ) ) ) {
V_64 = - V_48 ;
goto V_54;
}
V_186 = (struct V_100 * ) F_145 ( V_192 ) ;
F_128 ( V_29 , V_62 , & V_186 -> V_118 ) ;
}
}
V_54:
F_68 ( V_192 ) ;
return V_64 ;
}
int F_146 ( struct V_28 * V_29 , struct V_119 * V_62 ,
struct V_30 * V_31 )
{
F_20 ( V_31 ) -> V_33 = 0 ;
F_20 ( V_31 ) -> V_196 = 0 ;
if ( V_29 -> V_32 )
return 0 ;
switch ( V_31 -> V_34 ) {
case F_5 ( V_7 ) :
return F_129 ( V_29 , V_62 , V_31 ) ;
#if F_6 ( V_10 )
case F_5 ( V_11 ) :
return F_138 ( V_29 , V_62 , V_31 ) ;
#endif
}
return 0 ;
}
static void F_147 ( unsigned long V_50 )
{
struct V_28 * V_29 = ( void * ) V_50 ;
F_32 ( & V_29 -> V_51 ) ;
if ( V_29 -> V_149 <
V_29 -> V_144 )
V_29 -> V_149 ++ ;
F_98 ( V_29 , NULL , V_29 -> V_149 ) ;
F_38 ( & V_29 -> V_51 ) ;
}
void F_148 ( struct V_28 * V_29 )
{
V_29 -> V_121 = 4 ;
V_29 -> V_123 = 512 ;
V_29 -> V_136 = 1 ;
V_29 -> V_184 = 2 ;
V_29 -> V_144 = 2 ;
V_29 -> V_93 = V_95 ;
V_29 -> V_94 = 10 * V_95 ;
V_29 -> V_145 = 125 * V_95 / 4 ;
V_29 -> V_146 = 125 * V_95 ;
V_29 -> V_180 = 255 * V_95 ;
V_29 -> V_133 = 260 * V_95 ;
F_149 ( & V_29 -> V_51 ) ;
F_84 ( & V_29 -> V_137 ,
F_93 , 0 ) ;
F_84 ( & V_29 -> V_143 ,
F_93 , 0 ) ;
F_84 ( & V_29 -> V_147 , F_147 ,
( unsigned long ) V_29 ) ;
}
void F_150 ( struct V_28 * V_29 )
{
V_29 -> V_149 = 0 ;
if ( V_29 -> V_32 )
return;
F_44 ( & V_29 -> V_147 , V_61 ) ;
}
void F_151 ( struct V_28 * V_29 )
{
struct V_13 * V_14 ;
struct V_21 * V_24 ;
struct V_25 * V_26 , * V_150 ;
V_18 V_47 ;
int V_45 ;
F_102 ( & V_29 -> V_137 ) ;
F_102 ( & V_29 -> V_143 ) ;
F_102 ( & V_29 -> V_147 ) ;
F_152 ( & V_29 -> V_51 ) ;
V_14 = F_35 ( V_29 -> V_14 , V_29 ) ;
if ( ! V_14 )
goto V_54;
V_29 -> V_14 = NULL ;
V_47 = V_14 -> V_47 ;
for ( V_45 = 0 ; V_45 < V_14 -> V_19 ; V_45 ++ ) {
F_107 (mp, p, n, &mdb->mhash[i],
hlist[ver]) {
F_43 ( & V_24 -> V_53 ) ;
F_37 ( & V_24 -> V_38 , F_30 ) ;
}
}
if ( V_14 -> V_39 ) {
F_153 ( & V_29 -> V_51 ) ;
F_154 () ;
F_152 ( & V_29 -> V_51 ) ;
F_40 ( V_14 -> V_39 ) ;
}
V_14 -> V_39 = V_14 ;
F_37 ( & V_14 -> V_38 , F_23 ) ;
V_54:
F_153 ( & V_29 -> V_51 ) ;
}
int F_155 ( struct V_28 * V_29 , unsigned long V_209 )
{
int V_64 = - V_210 ;
F_152 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) )
goto V_211;
switch ( V_209 ) {
case 0 :
case 2 :
F_43 ( & V_29 -> V_137 ) ;
case 1 :
V_29 -> V_136 = V_209 ;
V_64 = 0 ;
break;
default:
V_64 = - V_48 ;
break;
}
V_211:
F_153 ( & V_29 -> V_51 ) ;
return V_64 ;
}
int F_156 ( struct V_119 * V_26 , unsigned long V_209 )
{
struct V_28 * V_29 = V_26 -> V_29 ;
int V_64 = - V_210 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) || V_26 -> V_131 == V_132 )
goto V_211;
switch ( V_209 ) {
case 0 :
case 1 :
case 2 :
V_26 -> V_136 = V_209 ;
V_64 = 0 ;
if ( V_209 < 2 && ! F_46 ( & V_26 -> V_138 ) )
F_92 ( & V_26 -> V_138 ) ;
if ( V_209 == 1 )
break;
F_43 ( & V_26 -> V_137 ) ;
if ( V_209 == 0 )
break;
F_115 ( V_29 , V_26 ) ;
break;
default:
V_64 = - V_48 ;
break;
}
V_211:
F_38 ( & V_29 -> V_51 ) ;
return V_64 ;
}
int F_157 ( struct V_28 * V_29 , unsigned long V_209 )
{
struct V_119 * V_62 ;
int V_64 = 0 ;
struct V_13 * V_14 ;
F_152 ( & V_29 -> V_51 ) ;
if ( V_29 -> V_32 == ! V_209 )
goto V_211;
V_29 -> V_32 = ! V_209 ;
if ( V_29 -> V_32 )
goto V_211;
if ( ! F_33 ( V_29 -> V_52 ) )
goto V_211;
V_14 = F_35 ( V_29 -> V_14 , V_29 ) ;
if ( V_14 ) {
if ( V_14 -> V_39 ) {
V_64 = - V_126 ;
V_212:
V_29 -> V_32 = ! ! V_209 ;
goto V_211;
}
V_64 = F_47 ( & V_29 -> V_14 , V_14 -> V_19 ,
V_29 -> V_121 ) ;
if ( V_64 )
goto V_212;
}
F_150 ( V_29 ) ;
F_158 (port, &br->port_list, list) {
if ( V_62 -> V_131 == V_132 ||
V_62 -> V_131 == V_148 )
continue;
F_103 ( V_62 ) ;
}
V_211:
F_153 ( & V_29 -> V_51 ) ;
return V_64 ;
}
int F_159 ( struct V_28 * V_29 , unsigned long V_209 )
{
int V_64 = - V_210 ;
V_18 V_39 ;
struct V_13 * V_14 ;
F_32 ( & V_29 -> V_51 ) ;
if ( ! F_33 ( V_29 -> V_52 ) )
goto V_211;
V_64 = - V_48 ;
if ( ! F_160 ( V_209 ) )
goto V_211;
V_14 = F_35 ( V_29 -> V_14 , V_29 ) ;
if ( V_14 && V_209 < V_14 -> V_57 )
goto V_211;
V_64 = 0 ;
V_39 = V_29 -> V_123 ;
V_29 -> V_123 = V_209 ;
if ( V_14 ) {
if ( V_14 -> V_39 ) {
V_64 = - V_126 ;
V_212:
V_29 -> V_123 = V_39 ;
goto V_211;
}
V_64 = F_47 ( & V_29 -> V_14 , V_29 -> V_123 ,
V_29 -> V_121 ) ;
if ( V_64 )
goto V_212;
}
V_211:
F_38 ( & V_29 -> V_51 ) ;
return V_64 ;
}
