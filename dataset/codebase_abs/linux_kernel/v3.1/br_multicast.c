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
#if F_6 ( V_10 ) || F_6 ( V_11 )
case F_5 ( V_12 ) :
return F_7 ( & V_4 -> V_8 . V_13 , & V_5 -> V_8 . V_13 ) ;
#endif
}
return 0 ;
}
static inline int F_8 ( struct V_14 * V_15 , T_1 V_16 )
{
return F_9 ( V_15 -> V_17 , ( V_18 V_19 ) V_16 ) & ( V_15 -> V_20 - 1 ) ;
}
static inline int F_10 ( struct V_14 * V_15 ,
const struct V_1 * V_16 )
{
return F_11 ( ( V_18 V_19 * ) V_16 -> V_21 , 4 , V_15 -> V_17 ) & ( V_15 -> V_20 - 1 ) ;
}
static inline int F_12 ( struct V_14 * V_15 ,
struct V_3 * V_16 )
{
switch ( V_16 -> V_6 ) {
case F_5 ( V_7 ) :
return F_8 ( V_15 , V_16 -> V_8 . V_9 ) ;
#if F_6 ( V_10 ) || F_6 ( V_11 )
case F_5 ( V_12 ) :
return F_10 ( V_15 , & V_16 -> V_8 . V_13 ) ;
#endif
}
return 0 ;
}
static struct V_22 * F_13 (
struct V_14 * V_15 , struct V_3 * V_23 , int V_24 )
{
struct V_22 * V_25 ;
struct V_26 * V_27 ;
F_14 (mp, p, &mdb->mhash[hash], hlist[mdb->ver]) {
if ( F_4 ( & V_25 -> V_2 , V_23 ) )
return V_25 ;
}
return NULL ;
}
static struct V_22 * F_15 (
struct V_14 * V_15 , struct V_3 * V_23 )
{
if ( ! V_15 )
return NULL ;
return F_13 ( V_15 , V_23 , F_12 ( V_15 , V_23 ) ) ;
}
static struct V_22 * F_16 (
struct V_14 * V_15 , T_1 V_23 )
{
struct V_3 V_28 ;
V_28 . V_8 . V_9 = V_23 ;
V_28 . V_6 = F_5 ( V_7 ) ;
return F_15 ( V_15 , & V_28 ) ;
}
static struct V_22 * F_17 (
struct V_14 * V_15 , const struct V_1 * V_23 )
{
struct V_3 V_28 ;
F_18 ( & V_28 . V_8 . V_13 , V_23 ) ;
V_28 . V_6 = F_5 ( V_12 ) ;
return F_15 ( V_15 , & V_28 ) ;
}
struct V_22 * F_19 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_14 * V_15 = F_20 ( V_30 -> V_15 ) ;
struct V_3 V_16 ;
if ( V_30 -> V_33 )
return NULL ;
if ( F_21 ( V_32 ) -> V_34 )
return NULL ;
V_16 . V_6 = V_32 -> V_35 ;
switch ( V_32 -> V_35 ) {
case F_5 ( V_7 ) :
V_16 . V_8 . V_9 = F_22 ( V_32 ) -> V_36 ;
break;
#if F_6 ( V_10 ) || F_6 ( V_11 )
case F_5 ( V_12 ) :
F_18 ( & V_16 . V_8 . V_13 , & F_23 ( V_32 ) -> V_36 ) ;
break;
#endif
default:
return NULL ;
}
return F_15 ( V_15 , & V_16 ) ;
}
static void F_24 ( struct V_37 * V_38 )
{
struct V_14 * V_15 =
F_25 ( V_38 , struct V_14 , V_39 ) ;
struct V_14 * V_40 = V_15 -> V_40 ;
V_15 -> V_40 = NULL ;
F_26 ( V_40 -> V_41 ) ;
F_26 ( V_40 ) ;
}
static int F_27 ( struct V_14 * V_42 ,
struct V_14 * V_40 ,
int V_43 )
{
struct V_22 * V_25 ;
struct V_26 * V_27 ;
int V_44 ;
int V_45 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_40 -> V_20 ; V_46 ++ )
F_28 (mp, p, &old->mhash[i], hlist[old->ver])
F_29 ( & V_25 -> V_47 [ V_42 -> V_48 ] ,
& V_42 -> V_41 [ F_12 ( V_42 , & V_25 -> V_2 ) ] ) ;
if ( ! V_43 )
return 0 ;
V_44 = 0 ;
for ( V_46 = 0 ; V_46 < V_42 -> V_20 ; V_46 ++ ) {
V_45 = 0 ;
F_28 (mp, p, &new->mhash[i], hlist[new->ver])
V_45 ++ ;
if ( V_45 > V_44 )
V_44 = V_45 ;
}
return V_44 > V_43 ? - V_49 : 0 ;
}
static void F_30 ( struct V_37 * V_38 )
{
struct V_50 * V_27 =
F_25 ( V_38 , struct V_50 , V_39 ) ;
F_26 ( V_27 ) ;
}
static void F_31 ( struct V_37 * V_38 )
{
struct V_22 * V_25 =
F_25 ( V_38 , struct V_22 , V_39 ) ;
F_26 ( V_25 ) ;
}
static void F_32 ( unsigned long V_51 )
{
struct V_22 * V_25 = ( void * ) V_51 ;
struct V_29 * V_30 = V_25 -> V_30 ;
struct V_14 * V_15 ;
F_33 ( & V_30 -> V_52 ) ;
if ( ! F_34 ( V_30 -> V_53 ) || F_35 ( & V_25 -> V_54 ) )
goto V_55;
V_25 -> V_56 = false ;
if ( V_25 -> V_57 )
goto V_55;
V_15 = F_36 ( V_30 -> V_15 , V_30 ) ;
F_37 ( & V_25 -> V_47 [ V_15 -> V_48 ] ) ;
V_15 -> V_58 -- ;
F_38 ( & V_25 -> V_59 ) ;
F_39 ( & V_25 -> V_39 , F_31 ) ;
V_55:
F_40 ( & V_30 -> V_52 ) ;
}
static void F_41 ( struct V_29 * V_30 ,
struct V_50 * V_60 )
{
struct V_14 * V_15 ;
struct V_22 * V_25 ;
struct V_50 * V_27 ;
struct V_50 T_2 * * V_61 ;
V_15 = F_36 ( V_30 -> V_15 , V_30 ) ;
V_25 = F_15 ( V_15 , & V_60 -> V_2 ) ;
if ( F_42 ( ! V_25 ) )
return;
for ( V_61 = & V_25 -> V_57 ;
( V_27 = F_36 ( * V_61 , V_30 ) ) != NULL ;
V_61 = & V_27 -> V_62 ) {
if ( V_27 != V_60 )
continue;
F_43 ( * V_61 , V_27 -> V_62 ) ;
F_44 ( & V_27 -> V_56 ) ;
F_38 ( & V_27 -> V_54 ) ;
F_38 ( & V_27 -> V_59 ) ;
F_39 ( & V_27 -> V_39 , F_30 ) ;
if ( ! V_25 -> V_57 && ! V_25 -> V_56 &&
F_34 ( V_30 -> V_53 ) )
F_45 ( & V_25 -> V_54 , V_63 ) ;
return;
}
F_42 ( 1 ) ;
}
static void F_46 ( unsigned long V_51 )
{
struct V_50 * V_60 = ( void * ) V_51 ;
struct V_29 * V_30 = V_60 -> V_64 -> V_30 ;
F_33 ( & V_30 -> V_52 ) ;
if ( ! F_34 ( V_30 -> V_53 ) || F_35 ( & V_60 -> V_54 ) ||
F_47 ( & V_60 -> V_56 ) )
goto V_55;
F_41 ( V_30 , V_60 ) ;
V_55:
F_40 ( & V_30 -> V_52 ) ;
}
static int F_48 ( struct V_14 T_2 * * V_65 , int V_20 ,
int V_43 )
{
struct V_14 * V_40 = F_49 ( * V_65 , 1 ) ;
struct V_14 * V_15 ;
int V_66 ;
V_15 = F_50 ( sizeof( * V_15 ) , V_67 ) ;
if ( ! V_15 )
return - V_68 ;
V_15 -> V_20 = V_20 ;
V_15 -> V_40 = V_40 ;
V_15 -> V_41 = F_51 ( V_20 * sizeof( * V_15 -> V_41 ) , V_67 ) ;
if ( ! V_15 -> V_41 ) {
F_26 ( V_15 ) ;
return - V_68 ;
}
V_15 -> V_58 = V_40 ? V_40 -> V_58 : 0 ;
V_15 -> V_48 = V_40 ? V_40 -> V_48 ^ 1 : 0 ;
if ( ! V_40 || V_43 )
F_52 ( & V_15 -> V_17 , sizeof( V_15 -> V_17 ) ) ;
else
V_15 -> V_17 = V_40 -> V_17 ;
if ( ! V_40 )
goto V_55;
V_66 = F_27 ( V_15 , V_40 , V_43 ) ;
if ( V_66 ) {
F_26 ( V_15 -> V_41 ) ;
F_26 ( V_15 ) ;
return V_66 ;
}
F_39 ( & V_15 -> V_39 , F_24 ) ;
V_55:
F_43 ( * V_65 , V_15 ) ;
return 0 ;
}
static struct V_31 * F_53 ( struct V_29 * V_30 ,
T_1 V_69 )
{
struct V_31 * V_32 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
V_32 = F_54 ( V_30 -> V_53 , sizeof( * V_73 ) + sizeof( * V_75 ) +
sizeof( * V_71 ) + 4 ) ;
if ( ! V_32 )
goto V_55;
V_32 -> V_35 = F_5 ( V_7 ) ;
F_55 ( V_32 ) ;
V_73 = F_56 ( V_32 ) ;
memcpy ( V_73 -> V_76 , V_30 -> V_53 -> V_77 , 6 ) ;
V_73 -> V_78 [ 0 ] = 1 ;
V_73 -> V_78 [ 1 ] = 0 ;
V_73 -> V_78 [ 2 ] = 0x5e ;
V_73 -> V_78 [ 3 ] = 0 ;
V_73 -> V_78 [ 4 ] = 0 ;
V_73 -> V_78 [ 5 ] = 1 ;
V_73 -> V_79 = F_5 ( V_7 ) ;
F_57 ( V_32 , sizeof( * V_73 ) ) ;
F_58 ( V_32 , V_32 -> V_45 ) ;
V_75 = F_22 ( V_32 ) ;
V_75 -> V_80 = 4 ;
V_75 -> V_81 = 6 ;
V_75 -> V_82 = 0xc0 ;
V_75 -> V_83 = F_5 ( sizeof( * V_75 ) + sizeof( * V_71 ) + 4 ) ;
V_75 -> V_84 = 0 ;
V_75 -> V_85 = F_5 ( V_86 ) ;
V_75 -> V_87 = 1 ;
V_75 -> V_35 = V_88 ;
V_75 -> V_89 = 0 ;
V_75 -> V_36 = F_59 ( V_90 ) ;
( ( V_91 * ) & V_75 [ 1 ] ) [ 0 ] = V_92 ;
( ( V_91 * ) & V_75 [ 1 ] ) [ 1 ] = 4 ;
( ( V_91 * ) & V_75 [ 1 ] ) [ 2 ] = 0 ;
( ( V_91 * ) & V_75 [ 1 ] ) [ 3 ] = 0 ;
F_60 ( V_75 ) ;
F_57 ( V_32 , 24 ) ;
F_61 ( V_32 , V_32 -> V_45 ) ;
V_71 = F_62 ( V_32 ) ;
V_71 -> type = V_93 ;
V_71 -> V_94 = ( V_69 ? V_30 -> V_95 :
V_30 -> V_96 ) /
( V_97 / V_98 ) ;
V_71 -> V_69 = V_69 ;
V_71 -> V_99 = 0 ;
V_71 -> V_99 = F_63 ( ( void * ) V_71 , sizeof( struct V_70 ) ) ;
F_57 ( V_32 , sizeof( * V_71 ) ) ;
F_64 ( V_32 , sizeof( * V_73 ) ) ;
V_55:
return V_32 ;
}
static struct V_31 * F_65 ( struct V_29 * V_30 ,
const struct V_1 * V_69 )
{
struct V_31 * V_32 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
struct V_72 * V_73 ;
V_91 * V_104 ;
unsigned long V_105 ;
V_32 = F_54 ( V_30 -> V_53 , sizeof( * V_73 ) + sizeof( * V_101 ) +
8 + sizeof( * V_103 ) ) ;
if ( ! V_32 )
goto V_55;
V_32 -> V_35 = F_5 ( V_12 ) ;
F_55 ( V_32 ) ;
V_73 = F_56 ( V_32 ) ;
memcpy ( V_73 -> V_76 , V_30 -> V_53 -> V_77 , 6 ) ;
V_73 -> V_79 = F_5 ( V_12 ) ;
F_57 ( V_32 , sizeof( * V_73 ) ) ;
F_58 ( V_32 , V_32 -> V_45 ) ;
V_101 = F_23 ( V_32 ) ;
* ( V_18 T_1 * ) V_101 = F_59 ( 0x60000000 ) ;
V_101 -> V_106 = F_5 ( 8 + sizeof( * V_103 ) ) ;
V_101 -> V_107 = V_108 ;
V_101 -> V_109 = 1 ;
F_66 ( & V_101 -> V_36 , F_59 ( 0xff020000 ) , 0 , 0 , F_59 ( 1 ) ) ;
F_67 ( F_68 ( V_30 -> V_53 ) , V_30 -> V_53 , & V_101 -> V_36 , 0 ,
& V_101 -> V_89 ) ;
F_69 ( & V_101 -> V_36 , V_73 -> V_78 ) ;
V_104 = ( V_91 * ) ( V_101 + 1 ) ;
V_104 [ 0 ] = V_110 ;
V_104 [ 1 ] = 0 ;
V_104 [ 2 ] = V_111 ;
V_104 [ 3 ] = 2 ;
V_104 [ 4 ] = 0 ;
V_104 [ 5 ] = 0 ;
V_104 [ 6 ] = V_112 ;
V_104 [ 7 ] = V_112 ;
F_57 ( V_32 , sizeof( * V_101 ) + 8 ) ;
F_61 ( V_32 , V_32 -> V_45 ) ;
V_103 = (struct V_102 * ) F_70 ( V_32 ) ;
V_105 = F_71 ( V_69 ) ? V_30 -> V_95 :
V_30 -> V_96 ;
V_103 -> V_113 = V_114 ;
V_103 -> V_115 = 0 ;
V_103 -> V_116 = 0 ;
V_103 -> V_117 = F_5 ( ( V_118 ) F_72 ( V_105 ) ) ;
V_103 -> V_119 = 0 ;
F_18 ( & V_103 -> V_120 , V_69 ) ;
V_103 -> V_116 = F_73 ( & V_101 -> V_89 , & V_101 -> V_36 ,
sizeof( * V_103 ) , V_110 ,
F_74 ( V_103 ,
sizeof( * V_103 ) , 0 ) ) ;
F_57 ( V_32 , sizeof( * V_103 ) ) ;
F_64 ( V_32 , sizeof( * V_73 ) ) ;
V_55:
return V_32 ;
}
static struct V_31 * F_75 ( struct V_29 * V_30 ,
struct V_3 * V_2 )
{
switch ( V_2 -> V_6 ) {
case F_5 ( V_7 ) :
return F_53 ( V_30 , V_2 -> V_8 . V_9 ) ;
#if F_6 ( V_10 ) || F_6 ( V_11 )
case F_5 ( V_12 ) :
return F_65 ( V_30 , & V_2 -> V_8 . V_13 ) ;
#endif
}
return NULL ;
}
static void F_76 ( struct V_22 * V_25 )
{
struct V_29 * V_30 = V_25 -> V_30 ;
struct V_31 * V_32 ;
V_32 = F_75 ( V_30 , & V_25 -> V_2 ) ;
if ( ! V_32 )
goto V_54;
F_77 ( V_32 ) ;
V_54:
if ( ++ V_25 -> V_121 < V_30 -> V_122 )
F_45 ( & V_25 -> V_59 ,
V_63 + V_30 -> V_95 ) ;
}
static void F_78 ( unsigned long V_51 )
{
struct V_22 * V_25 = ( void * ) V_51 ;
struct V_29 * V_30 = V_25 -> V_30 ;
F_33 ( & V_30 -> V_52 ) ;
if ( ! F_34 ( V_30 -> V_53 ) || ! V_25 -> V_56 ||
V_25 -> V_121 >= V_30 -> V_122 )
goto V_55;
F_76 ( V_25 ) ;
V_55:
F_40 ( & V_30 -> V_52 ) ;
}
static void F_79 ( struct V_50 * V_60 )
{
struct V_123 * V_64 = V_60 -> V_64 ;
struct V_29 * V_30 = V_64 -> V_30 ;
struct V_31 * V_32 ;
V_32 = F_75 ( V_30 , & V_60 -> V_2 ) ;
if ( ! V_32 )
goto V_54;
F_80 ( V_64 , V_32 ) ;
V_54:
if ( ++ V_60 -> V_121 < V_30 -> V_122 )
F_45 ( & V_60 -> V_59 ,
V_63 + V_30 -> V_95 ) ;
}
static void F_81 ( unsigned long V_51 )
{
struct V_50 * V_60 = ( void * ) V_51 ;
struct V_123 * V_64 = V_60 -> V_64 ;
struct V_29 * V_30 = V_64 -> V_30 ;
F_33 ( & V_30 -> V_52 ) ;
if ( ! F_34 ( V_30 -> V_53 ) || F_47 ( & V_60 -> V_56 ) ||
V_60 -> V_121 >= V_30 -> V_122 )
goto V_55;
F_79 ( V_60 ) ;
V_55:
F_40 ( & V_30 -> V_52 ) ;
}
static struct V_22 * F_82 (
struct V_29 * V_30 , struct V_123 * V_64 ,
struct V_3 * V_69 , int V_24 )
{
struct V_14 * V_15 ;
struct V_22 * V_25 ;
struct V_26 * V_27 ;
unsigned V_124 = 0 ;
unsigned V_20 ;
int V_43 ;
int V_66 ;
V_15 = F_49 ( V_30 -> V_15 , 1 ) ;
F_28 (mp, p, &mdb->mhash[hash], hlist[mdb->ver]) {
V_124 ++ ;
if ( F_83 ( F_4 ( V_69 , & V_25 -> V_2 ) ) )
return V_25 ;
}
V_43 = 0 ;
V_20 = V_15 -> V_20 ;
if ( F_83 ( V_124 > V_30 -> V_125 && V_124 ) ) {
if ( F_84 () )
F_85 ( V_30 , L_1
L_2 ,
V_64 ? V_64 -> V_53 -> V_126 : V_30 -> V_53 -> V_126 ) ;
V_43 = V_30 -> V_125 ;
}
if ( V_15 -> V_58 >= V_20 ) {
V_20 *= 2 ;
if ( F_83 ( V_20 >= V_30 -> V_127 ) ) {
F_86 ( V_30 , L_3
L_4 ,
V_64 ? V_64 -> V_53 -> V_126 : V_30 -> V_53 -> V_126 , V_20 ) ;
V_66 = - V_128 ;
V_129:
V_30 -> V_33 = 1 ;
goto V_66;
}
}
if ( V_20 > V_15 -> V_20 || V_43 ) {
if ( V_15 -> V_40 ) {
if ( F_84 () )
F_85 ( V_30 , L_1
L_5 ,
V_64 ? V_64 -> V_53 -> V_126 : V_30 -> V_53 -> V_126 ) ;
V_66 = - V_130 ;
goto V_66;
}
V_66 = F_48 ( & V_30 -> V_15 , V_20 , V_43 ) ;
if ( V_66 ) {
F_86 ( V_30 , L_6
L_7 ,
V_64 ? V_64 -> V_53 -> V_126 : V_30 -> V_53 -> V_126 ,
V_15 -> V_58 , V_66 ) ;
goto V_129;
}
V_66 = - V_131 ;
goto V_66;
}
return NULL ;
V_66:
V_25 = F_87 ( V_66 ) ;
return V_25 ;
}
static struct V_22 * F_88 (
struct V_29 * V_30 , struct V_123 * V_64 ,
struct V_3 * V_69 )
{
struct V_14 * V_15 ;
struct V_22 * V_25 ;
int V_24 ;
int V_66 ;
V_15 = F_49 ( V_30 -> V_15 , 1 ) ;
if ( ! V_15 ) {
V_66 = F_48 ( & V_30 -> V_15 , V_132 , 0 ) ;
if ( V_66 )
return F_87 ( V_66 ) ;
goto V_133;
}
V_24 = F_12 ( V_15 , V_69 ) ;
V_25 = F_82 ( V_30 , V_64 , V_69 , V_24 ) ;
switch ( F_89 ( V_25 ) ) {
case 0 :
break;
case - V_131 :
V_133:
V_15 = F_49 ( V_30 -> V_15 , 1 ) ;
V_24 = F_12 ( V_15 , V_69 ) ;
break;
default:
goto V_55;
}
V_25 = F_51 ( sizeof( * V_25 ) , V_67 ) ;
if ( F_83 ( ! V_25 ) )
return F_87 ( - V_68 ) ;
V_25 -> V_30 = V_30 ;
V_25 -> V_2 = * V_69 ;
F_90 ( & V_25 -> V_54 , F_32 ,
( unsigned long ) V_25 ) ;
F_90 ( & V_25 -> V_59 , F_78 ,
( unsigned long ) V_25 ) ;
F_91 ( & V_25 -> V_47 [ V_15 -> V_48 ] , & V_15 -> V_41 [ V_24 ] ) ;
V_15 -> V_58 ++ ;
V_55:
return V_25 ;
}
static int F_92 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
struct V_3 * V_69 )
{
struct V_22 * V_25 ;
struct V_50 * V_27 ;
struct V_50 T_2 * * V_61 ;
unsigned long V_134 = V_63 ;
int V_66 ;
F_33 ( & V_30 -> V_52 ) ;
if ( ! F_34 ( V_30 -> V_53 ) ||
( V_64 && V_64 -> V_135 == V_136 ) )
goto V_55;
V_25 = F_88 ( V_30 , V_64 , V_69 ) ;
V_66 = F_89 ( V_25 ) ;
if ( F_93 ( V_25 ) )
goto V_66;
if ( ! V_64 ) {
V_25 -> V_56 = true ;
F_45 ( & V_25 -> V_54 , V_134 + V_30 -> V_137 ) ;
goto V_55;
}
for ( V_61 = & V_25 -> V_57 ;
( V_27 = F_36 ( * V_61 , V_30 ) ) != NULL ;
V_61 = & V_27 -> V_62 ) {
if ( V_27 -> V_64 == V_64 )
goto V_138;
if ( ( unsigned long ) V_27 -> V_64 < ( unsigned long ) V_64 )
break;
}
V_27 = F_51 ( sizeof( * V_27 ) , V_67 ) ;
V_66 = - V_68 ;
if ( F_83 ( ! V_27 ) )
goto V_66;
V_27 -> V_2 = * V_69 ;
V_27 -> V_64 = V_64 ;
V_27 -> V_62 = * V_61 ;
F_29 ( & V_27 -> V_56 , & V_64 -> V_56 ) ;
F_90 ( & V_27 -> V_54 , F_46 ,
( unsigned long ) V_27 ) ;
F_90 ( & V_27 -> V_59 , F_81 ,
( unsigned long ) V_27 ) ;
F_43 ( * V_61 , V_27 ) ;
V_138:
F_45 ( & V_27 -> V_54 , V_134 + V_30 -> V_137 ) ;
V_55:
V_66 = 0 ;
V_66:
F_40 ( & V_30 -> V_52 ) ;
return V_66 ;
}
static int F_94 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
T_1 V_69 )
{
struct V_3 V_139 ;
if ( F_95 ( V_69 ) )
return 0 ;
V_139 . V_8 . V_9 = V_69 ;
V_139 . V_6 = F_5 ( V_7 ) ;
return F_92 ( V_30 , V_64 , & V_139 ) ;
}
static int F_96 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
const struct V_1 * V_69 )
{
struct V_3 V_139 ;
if ( ! F_1 ( V_69 ) )
return 0 ;
F_18 ( & V_139 . V_8 . V_13 , V_69 ) ;
V_139 . V_6 = F_5 ( V_12 ) ;
return F_92 ( V_30 , V_64 , & V_139 ) ;
}
static void F_97 ( unsigned long V_51 )
{
struct V_123 * V_64 = ( void * ) V_51 ;
struct V_29 * V_30 = V_64 -> V_30 ;
F_33 ( & V_30 -> V_52 ) ;
if ( V_64 -> V_140 != 1 ||
F_35 ( & V_64 -> V_141 ) ||
F_47 ( & V_64 -> V_142 ) )
goto V_55;
F_98 ( & V_64 -> V_142 ) ;
V_55:
F_40 ( & V_30 -> V_52 ) ;
}
static void F_99 ( unsigned long V_51 )
{
}
static void F_100 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
struct V_3 * V_16 )
{
struct V_31 * V_32 ;
V_32 = F_75 ( V_30 , V_16 ) ;
if ( ! V_32 )
return;
if ( V_64 ) {
F_101 ( V_32 , sizeof( struct V_72 ) ) ;
V_32 -> V_53 = V_64 -> V_53 ;
F_102 ( V_143 , V_144 , V_32 , NULL , V_32 -> V_53 ,
V_145 ) ;
} else
F_77 ( V_32 ) ;
}
static void F_103 ( struct V_29 * V_30 ,
struct V_123 * V_64 , V_19 V_146 )
{
unsigned long time ;
struct V_3 V_139 ;
if ( ! F_34 ( V_30 -> V_53 ) || V_30 -> V_33 ||
F_35 ( & V_30 -> V_147 ) )
return;
memset ( & V_139 . V_8 , 0 , sizeof( V_139 . V_8 ) ) ;
V_139 . V_6 = F_5 ( V_7 ) ;
F_100 ( V_30 , V_64 , & V_139 ) ;
#if F_6 ( V_10 ) || F_6 ( V_11 )
V_139 . V_6 = F_5 ( V_12 ) ;
F_100 ( V_30 , V_64 , & V_139 ) ;
#endif
time = V_63 ;
time += V_146 < V_30 -> V_148 ?
V_30 -> V_149 :
V_30 -> V_150 ;
F_45 ( V_64 ? & V_64 -> V_151 :
& V_30 -> V_151 , time ) ;
}
static void F_104 ( unsigned long V_51 )
{
struct V_123 * V_64 = ( void * ) V_51 ;
struct V_29 * V_30 = V_64 -> V_30 ;
F_33 ( & V_30 -> V_52 ) ;
if ( V_64 -> V_135 == V_136 ||
V_64 -> V_135 == V_152 )
goto V_55;
if ( V_64 -> V_153 <
V_30 -> V_148 )
V_64 -> V_153 ++ ;
F_103 ( V_64 -> V_30 , V_64 ,
V_64 -> V_153 ) ;
V_55:
F_40 ( & V_30 -> V_52 ) ;
}
void F_105 ( struct V_123 * V_64 )
{
V_64 -> V_140 = 1 ;
F_90 ( & V_64 -> V_141 , F_97 ,
( unsigned long ) V_64 ) ;
F_90 ( & V_64 -> V_151 ,
F_104 , ( unsigned long ) V_64 ) ;
}
void F_106 ( struct V_123 * V_64 )
{
F_107 ( & V_64 -> V_141 ) ;
}
static void F_108 ( struct V_123 * V_64 )
{
V_64 -> V_153 = 0 ;
if ( F_109 ( & V_64 -> V_151 ) >= 0 ||
F_38 ( & V_64 -> V_151 ) )
F_45 ( & V_64 -> V_151 , V_63 ) ;
}
void F_110 ( struct V_123 * V_64 )
{
struct V_29 * V_30 = V_64 -> V_30 ;
F_33 ( & V_30 -> V_52 ) ;
if ( V_30 -> V_33 || ! F_34 ( V_30 -> V_53 ) )
goto V_55;
F_108 ( V_64 ) ;
V_55:
F_40 ( & V_30 -> V_52 ) ;
}
void F_111 ( struct V_123 * V_64 )
{
struct V_29 * V_30 = V_64 -> V_30 ;
struct V_50 * V_60 ;
struct V_26 * V_27 , * V_154 ;
F_33 ( & V_30 -> V_52 ) ;
F_112 (pg, p, n, &port->mglist, mglist)
F_41 ( V_30 , V_60 ) ;
if ( ! F_47 ( & V_64 -> V_142 ) )
F_98 ( & V_64 -> V_142 ) ;
F_38 ( & V_64 -> V_141 ) ;
F_38 ( & V_64 -> V_151 ) ;
F_40 ( & V_30 -> V_52 ) ;
}
static int F_113 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
struct V_31 * V_32 )
{
struct V_155 * V_71 ;
struct V_156 * V_157 ;
int V_46 ;
int V_45 ;
int V_158 ;
int type ;
int V_66 = 0 ;
T_1 V_69 ;
if ( ! F_114 ( V_32 , sizeof( * V_71 ) ) )
return - V_49 ;
V_71 = F_115 ( V_32 ) ;
V_158 = F_116 ( V_71 -> V_159 ) ;
V_45 = sizeof( * V_71 ) ;
for ( V_46 = 0 ; V_46 < V_158 ; V_46 ++ ) {
V_45 += sizeof( * V_157 ) ;
if ( ! F_114 ( V_32 , V_45 ) )
return - V_49 ;
V_157 = ( void * ) ( V_32 -> V_51 + V_45 - sizeof( * V_157 ) ) ;
V_69 = V_157 -> V_160 ;
type = V_157 -> V_161 ;
V_45 += F_116 ( V_157 -> V_162 ) * 4 ;
if ( ! F_114 ( V_32 , V_45 ) )
return - V_49 ;
switch ( type ) {
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
break;
default:
continue;
}
V_66 = F_94 ( V_30 , V_64 , V_69 ) ;
if ( V_66 )
break;
}
return V_66 ;
}
static int F_117 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
struct V_31 * V_32 )
{
struct V_169 * V_170 ;
struct V_171 * V_157 ;
int V_46 ;
int V_45 ;
int V_158 ;
int V_66 = 0 ;
if ( ! F_114 ( V_32 , sizeof( * V_170 ) ) )
return - V_49 ;
V_170 = F_70 ( V_32 ) ;
V_158 = F_116 ( V_170 -> V_172 . V_173 [ 1 ] ) ;
V_45 = sizeof( * V_170 ) ;
for ( V_46 = 0 ; V_46 < V_158 ; V_46 ++ ) {
T_3 * V_174 , V_175 ;
V_174 = F_118 ( V_32 ,
V_45 + F_119 ( struct V_171 ,
V_162 ) ,
sizeof( V_175 ) , & V_175 ) ;
if ( ! V_174 )
return - V_49 ;
if ( ! F_114 ( V_32 ,
V_45 + sizeof( * V_157 ) +
sizeof( struct V_1 ) * F_116 ( * V_174 ) ) )
return - V_49 ;
V_157 = (struct V_171 * ) ( V_32 -> V_51 + V_45 ) ;
V_45 += sizeof( * V_157 ) +
sizeof( struct V_1 ) * F_116 ( * V_174 ) ;
switch ( V_157 -> V_161 ) {
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
break;
default:
continue;
}
V_66 = F_96 ( V_30 , V_64 , & V_157 -> V_160 ) ;
if ( ! V_66 )
break;
}
return V_66 ;
}
static void F_120 ( struct V_29 * V_30 ,
struct V_123 * V_64 )
{
struct V_123 * V_27 ;
struct V_26 * V_154 , * V_182 = NULL ;
F_28 (p, n, &br->router_list, rlist) {
if ( ( unsigned long ) V_64 >= ( unsigned long ) V_27 )
break;
V_182 = V_154 ;
}
if ( V_182 )
F_121 ( V_182 , & V_64 -> V_142 ) ;
else
F_91 ( & V_64 -> V_142 , & V_30 -> V_183 ) ;
}
static void F_122 ( struct V_29 * V_30 ,
struct V_123 * V_64 )
{
unsigned long V_134 = V_63 ;
if ( ! V_64 ) {
if ( V_30 -> V_140 == 1 )
F_45 ( & V_30 -> V_141 ,
V_134 + V_30 -> V_184 ) ;
return;
}
if ( V_64 -> V_140 != 1 )
return;
if ( ! F_47 ( & V_64 -> V_142 ) )
goto V_54;
F_120 ( V_30 , V_64 ) ;
V_54:
F_45 ( & V_64 -> V_141 ,
V_134 + V_30 -> V_184 ) ;
}
static void F_123 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
int V_89 )
{
if ( V_89 )
F_45 ( & V_30 -> V_147 ,
V_63 + V_30 -> V_184 ) ;
else if ( F_35 ( & V_30 -> V_147 ) )
return;
F_122 ( V_30 , V_64 ) ;
}
static int F_124 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
struct V_31 * V_32 )
{
const struct V_74 * V_75 = F_22 ( V_32 ) ;
struct V_70 * V_71 = F_62 ( V_32 ) ;
struct V_22 * V_25 ;
struct V_185 * V_186 ;
struct V_50 * V_27 ;
struct V_50 T_2 * * V_61 ;
unsigned long V_187 ;
unsigned long V_134 = V_63 ;
T_1 V_69 ;
int V_66 = 0 ;
F_33 ( & V_30 -> V_52 ) ;
if ( ! F_34 ( V_30 -> V_53 ) ||
( V_64 && V_64 -> V_135 == V_136 ) )
goto V_55;
F_123 ( V_30 , V_64 , ! ! V_75 -> V_89 ) ;
V_69 = V_71 -> V_69 ;
if ( V_32 -> V_45 == sizeof( * V_71 ) ) {
V_187 = V_71 -> V_94 * ( V_97 / V_98 ) ;
if ( ! V_187 ) {
V_187 = 10 * V_97 ;
V_69 = 0 ;
}
} else {
if ( ! F_114 ( V_32 , sizeof( struct V_185 ) ) ) {
V_66 = - V_49 ;
goto V_55;
}
V_186 = F_125 ( V_32 ) ;
if ( V_186 -> V_174 )
goto V_55;
V_187 = V_186 -> V_94 ?
F_126 ( V_186 -> V_94 ) * ( V_97 / V_98 ) : 1 ;
}
if ( ! V_69 )
goto V_55;
V_25 = F_16 ( F_36 ( V_30 -> V_15 , V_30 ) , V_69 ) ;
if ( ! V_25 )
goto V_55;
V_187 *= V_30 -> V_122 ;
if ( V_25 -> V_56 &&
( F_35 ( & V_25 -> V_54 ) ?
F_127 ( V_25 -> V_54 . V_188 , V_134 + V_187 ) :
F_109 ( & V_25 -> V_54 ) >= 0 ) )
F_45 ( & V_25 -> V_54 , V_134 + V_187 ) ;
for ( V_61 = & V_25 -> V_57 ;
( V_27 = F_36 ( * V_61 , V_30 ) ) != NULL ;
V_61 = & V_27 -> V_62 ) {
if ( F_35 ( & V_27 -> V_54 ) ?
F_127 ( V_27 -> V_54 . V_188 , V_134 + V_187 ) :
F_109 ( & V_27 -> V_54 ) >= 0 )
F_45 ( & V_27 -> V_54 , V_134 + V_187 ) ;
}
V_55:
F_40 ( & V_30 -> V_52 ) ;
return V_66 ;
}
static int F_128 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
struct V_31 * V_32 )
{
const struct V_100 * V_101 = F_23 ( V_32 ) ;
struct V_102 * V_189 = (struct V_102 * ) F_70 ( V_32 ) ;
struct V_22 * V_25 ;
struct V_190 * V_191 ;
struct V_50 * V_27 ;
struct V_50 T_2 * * V_61 ;
unsigned long V_187 ;
unsigned long V_134 = V_63 ;
const struct V_1 * V_69 = NULL ;
int V_66 = 0 ;
F_33 ( & V_30 -> V_52 ) ;
if ( ! F_34 ( V_30 -> V_53 ) ||
( V_64 && V_64 -> V_135 == V_136 ) )
goto V_55;
F_123 ( V_30 , V_64 , ! F_71 ( & V_101 -> V_89 ) ) ;
if ( V_32 -> V_45 == sizeof( * V_189 ) ) {
if ( ! F_114 ( V_32 , sizeof( * V_189 ) ) ) {
V_66 = - V_49 ;
goto V_55;
}
V_189 = (struct V_102 * ) F_70 ( V_32 ) ;
V_187 = F_129 ( F_5 ( V_189 -> V_117 ) ) ;
if ( V_187 )
V_69 = & V_189 -> V_120 ;
} else if ( V_32 -> V_45 >= sizeof( * V_191 ) ) {
if ( ! F_114 ( V_32 , sizeof( * V_191 ) ) ) {
V_66 = - V_49 ;
goto V_55;
}
V_191 = (struct V_190 * ) F_70 ( V_32 ) ;
if ( ! V_191 -> V_192 )
V_69 = & V_191 -> V_193 ;
V_187 = V_191 -> V_194 ? F_130 ( V_191 -> V_194 ) : 1 ;
}
if ( ! V_69 )
goto V_55;
V_25 = F_17 ( F_36 ( V_30 -> V_15 , V_30 ) , V_69 ) ;
if ( ! V_25 )
goto V_55;
V_187 *= V_30 -> V_122 ;
if ( V_25 -> V_56 &&
( F_35 ( & V_25 -> V_54 ) ?
F_127 ( V_25 -> V_54 . V_188 , V_134 + V_187 ) :
F_109 ( & V_25 -> V_54 ) >= 0 ) )
F_45 ( & V_25 -> V_54 , V_134 + V_187 ) ;
for ( V_61 = & V_25 -> V_57 ;
( V_27 = F_36 ( * V_61 , V_30 ) ) != NULL ;
V_61 = & V_27 -> V_62 ) {
if ( F_35 ( & V_27 -> V_54 ) ?
F_127 ( V_27 -> V_54 . V_188 , V_134 + V_187 ) :
F_109 ( & V_27 -> V_54 ) >= 0 )
F_45 ( & V_27 -> V_54 , V_134 + V_187 ) ;
}
V_55:
F_40 ( & V_30 -> V_52 ) ;
return V_66 ;
}
static void F_131 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
struct V_3 * V_69 )
{
struct V_14 * V_15 ;
struct V_22 * V_25 ;
struct V_50 * V_27 ;
unsigned long V_134 ;
unsigned long time ;
F_33 ( & V_30 -> V_52 ) ;
if ( ! F_34 ( V_30 -> V_53 ) ||
( V_64 && V_64 -> V_135 == V_136 ) ||
F_35 ( & V_30 -> V_147 ) )
goto V_55;
V_15 = F_36 ( V_30 -> V_15 , V_30 ) ;
V_25 = F_15 ( V_15 , V_69 ) ;
if ( ! V_25 )
goto V_55;
V_134 = V_63 ;
time = V_134 + V_30 -> V_122 *
V_30 -> V_95 ;
if ( ! V_64 ) {
if ( V_25 -> V_56 &&
( F_35 ( & V_25 -> V_54 ) ?
F_127 ( V_25 -> V_54 . V_188 , time ) :
F_109 ( & V_25 -> V_54 ) >= 0 ) ) {
F_45 ( & V_25 -> V_54 , time ) ;
V_25 -> V_121 = 0 ;
F_45 ( & V_25 -> V_59 , V_134 ) ;
}
goto V_55;
}
for ( V_27 = F_36 ( V_25 -> V_57 , V_30 ) ;
V_27 != NULL ;
V_27 = F_36 ( V_27 -> V_62 , V_30 ) ) {
if ( V_27 -> V_64 != V_64 )
continue;
if ( ! F_47 ( & V_27 -> V_56 ) &&
( F_35 ( & V_27 -> V_54 ) ?
F_127 ( V_27 -> V_54 . V_188 , time ) :
F_109 ( & V_27 -> V_54 ) >= 0 ) ) {
F_45 ( & V_27 -> V_54 , time ) ;
V_27 -> V_121 = 0 ;
F_45 ( & V_27 -> V_59 , V_134 ) ;
}
break;
}
V_55:
F_40 ( & V_30 -> V_52 ) ;
}
static void F_132 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
T_1 V_69 )
{
struct V_3 V_139 ;
if ( F_95 ( V_69 ) )
return;
V_139 . V_8 . V_9 = V_69 ;
V_139 . V_6 = F_5 ( V_7 ) ;
F_131 ( V_30 , V_64 , & V_139 ) ;
}
static void F_133 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
const struct V_1 * V_69 )
{
struct V_3 V_139 ;
if ( ! F_1 ( V_69 ) )
return;
F_18 ( & V_139 . V_8 . V_13 , V_69 ) ;
V_139 . V_6 = F_5 ( V_12 ) ;
F_131 ( V_30 , V_64 , & V_139 ) ;
}
static int F_134 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
struct V_31 * V_32 )
{
struct V_31 * V_195 = V_32 ;
const struct V_74 * V_75 ;
struct V_70 * V_71 ;
unsigned V_45 ;
unsigned V_196 ;
int V_66 ;
if ( ! F_114 ( V_32 , sizeof( * V_75 ) ) )
return - V_49 ;
V_75 = F_22 ( V_32 ) ;
if ( V_75 -> V_81 < 5 || V_75 -> V_80 != 4 )
return - V_49 ;
if ( ! F_114 ( V_32 , F_135 ( V_32 ) ) )
return - V_49 ;
V_75 = F_22 ( V_32 ) ;
if ( F_83 ( F_136 ( ( V_91 * ) V_75 , V_75 -> V_81 ) ) )
return - V_49 ;
if ( V_75 -> V_35 != V_88 ) {
if ( ( V_75 -> V_36 & V_197 ) != V_198 )
F_21 ( V_32 ) -> V_199 = 1 ;
return 0 ;
}
V_45 = F_116 ( V_75 -> V_83 ) ;
if ( V_32 -> V_45 < V_45 || V_45 < F_135 ( V_32 ) )
return - V_49 ;
if ( V_32 -> V_45 > V_45 ) {
V_195 = F_137 ( V_32 , V_67 ) ;
if ( ! V_195 )
return - V_68 ;
V_66 = F_138 ( V_195 , V_45 ) ;
if ( V_66 )
goto V_200;
}
V_45 -= F_135 ( V_195 ) ;
V_196 = F_139 ( V_195 ) + F_135 ( V_195 ) ;
F_64 ( V_195 , V_196 ) ;
F_140 ( V_195 ) ;
V_66 = - V_49 ;
if ( ! F_114 ( V_195 , sizeof( * V_71 ) ) )
goto V_55;
switch ( V_195 -> V_201 ) {
case V_202 :
if ( ! F_141 ( V_195 -> V_99 ) )
break;
case V_203 :
V_195 -> V_99 = 0 ;
if ( F_142 ( V_195 ) )
goto V_55;
}
V_66 = 0 ;
F_21 ( V_32 ) -> V_34 = 1 ;
V_71 = F_62 ( V_195 ) ;
switch ( V_71 -> type ) {
case V_204 :
case V_205 :
F_21 ( V_32 ) -> V_199 = 1 ;
V_66 = F_94 ( V_30 , V_64 , V_71 -> V_69 ) ;
break;
case V_206 :
V_66 = F_113 ( V_30 , V_64 , V_195 ) ;
break;
case V_93 :
V_66 = F_124 ( V_30 , V_64 , V_195 ) ;
break;
case V_207 :
F_132 ( V_30 , V_64 , V_71 -> V_69 ) ;
break;
}
V_55:
F_101 ( V_195 , V_196 ) ;
V_200:
if ( V_195 != V_32 )
F_143 ( V_195 ) ;
return V_66 ;
}
static int F_144 ( struct V_29 * V_30 ,
struct V_123 * V_64 ,
struct V_31 * V_32 )
{
struct V_31 * V_195 ;
const struct V_100 * V_101 ;
V_91 V_208 ;
V_91 V_107 ;
unsigned V_45 ;
int V_196 ;
int V_66 ;
if ( ! F_114 ( V_32 , sizeof( * V_101 ) ) )
return - V_49 ;
V_101 = F_23 ( V_32 ) ;
if ( V_101 -> V_80 != 6 ||
V_101 -> V_107 != V_108 ||
V_101 -> V_106 == 0 )
return 0 ;
V_45 = F_116 ( V_101 -> V_106 ) + sizeof( * V_101 ) ;
if ( V_32 -> V_45 < V_45 )
return - V_49 ;
V_107 = V_101 -> V_107 ;
V_196 = F_145 ( V_32 , sizeof( * V_101 ) , & V_107 ) ;
if ( V_196 < 0 || V_107 != V_110 )
return 0 ;
V_195 = F_137 ( V_32 , V_67 ) ;
if ( ! V_195 )
return - V_68 ;
V_66 = - V_49 ;
if ( ! F_114 ( V_195 , V_196 + sizeof( struct V_169 ) ) )
goto V_55;
V_45 -= V_196 - F_139 ( V_195 ) ;
F_64 ( V_195 , V_196 ) ;
F_140 ( V_195 ) ;
V_208 = F_70 ( V_195 ) -> V_208 ;
switch ( V_208 ) {
case V_114 :
case V_209 :
case V_210 :
case V_211 :
break;
default:
V_66 = 0 ;
goto V_55;
}
if ( V_195 -> V_45 > V_45 ) {
V_66 = F_138 ( V_195 , V_45 ) ;
if ( V_66 )
goto V_55;
V_66 = - V_49 ;
}
V_101 = F_23 ( V_195 ) ;
switch ( V_195 -> V_201 ) {
case V_202 :
if ( ! F_73 ( & V_101 -> V_89 , & V_101 -> V_36 , V_195 -> V_45 ,
V_110 , V_195 -> V_99 ) )
break;
case V_203 :
V_195 -> V_99 = ~ F_146 ( F_73 ( & V_101 -> V_89 ,
& V_101 -> V_36 ,
V_195 -> V_45 ,
V_110 , 0 ) ) ;
if ( F_147 ( V_195 ) )
goto V_55;
}
V_66 = 0 ;
F_21 ( V_32 ) -> V_34 = 1 ;
switch ( V_208 ) {
case V_209 :
{
struct V_102 * V_189 ;
if ( ! F_114 ( V_195 , sizeof( * V_189 ) ) ) {
V_66 = - V_49 ;
goto V_55;
}
V_189 = (struct V_102 * ) F_148 ( V_195 ) ;
F_21 ( V_32 ) -> V_199 = 1 ;
V_66 = F_96 ( V_30 , V_64 , & V_189 -> V_120 ) ;
break;
}
case V_211 :
V_66 = F_117 ( V_30 , V_64 , V_195 ) ;
break;
case V_114 :
V_66 = F_128 ( V_30 , V_64 , V_195 ) ;
break;
case V_210 :
{
struct V_102 * V_189 ;
if ( ! F_114 ( V_195 , sizeof( * V_189 ) ) ) {
V_66 = - V_49 ;
goto V_55;
}
V_189 = (struct V_102 * ) F_148 ( V_195 ) ;
F_133 ( V_30 , V_64 , & V_189 -> V_120 ) ;
}
}
V_55:
F_143 ( V_195 ) ;
return V_66 ;
}
int F_149 ( struct V_29 * V_30 , struct V_123 * V_64 ,
struct V_31 * V_32 )
{
F_21 ( V_32 ) -> V_34 = 0 ;
F_21 ( V_32 ) -> V_199 = 0 ;
if ( V_30 -> V_33 )
return 0 ;
switch ( V_32 -> V_35 ) {
case F_5 ( V_7 ) :
return F_134 ( V_30 , V_64 , V_32 ) ;
#if F_6 ( V_10 ) || F_6 ( V_11 )
case F_5 ( V_12 ) :
return F_144 ( V_30 , V_64 , V_32 ) ;
#endif
}
return 0 ;
}
static void F_150 ( unsigned long V_51 )
{
struct V_29 * V_30 = ( void * ) V_51 ;
F_33 ( & V_30 -> V_52 ) ;
if ( V_30 -> V_153 <
V_30 -> V_148 )
V_30 -> V_153 ++ ;
F_103 ( V_30 , NULL , V_30 -> V_153 ) ;
F_40 ( & V_30 -> V_52 ) ;
}
void F_151 ( struct V_29 * V_30 )
{
V_30 -> V_125 = 4 ;
V_30 -> V_127 = 512 ;
V_30 -> V_140 = 1 ;
V_30 -> V_122 = 2 ;
V_30 -> V_148 = 2 ;
V_30 -> V_95 = V_97 ;
V_30 -> V_96 = 10 * V_97 ;
V_30 -> V_149 = 125 * V_97 / 4 ;
V_30 -> V_150 = 125 * V_97 ;
V_30 -> V_184 = 255 * V_97 ;
V_30 -> V_137 = 260 * V_97 ;
F_152 ( & V_30 -> V_52 ) ;
F_90 ( & V_30 -> V_141 ,
F_99 , 0 ) ;
F_90 ( & V_30 -> V_147 ,
F_99 , 0 ) ;
F_90 ( & V_30 -> V_151 , F_150 ,
( unsigned long ) V_30 ) ;
}
void F_153 ( struct V_29 * V_30 )
{
V_30 -> V_153 = 0 ;
if ( V_30 -> V_33 )
return;
F_45 ( & V_30 -> V_151 , V_63 ) ;
}
void F_154 ( struct V_29 * V_30 )
{
struct V_14 * V_15 ;
struct V_22 * V_25 ;
struct V_26 * V_27 , * V_154 ;
V_19 V_48 ;
int V_46 ;
F_107 ( & V_30 -> V_141 ) ;
F_107 ( & V_30 -> V_147 ) ;
F_107 ( & V_30 -> V_151 ) ;
F_155 ( & V_30 -> V_52 ) ;
V_15 = F_36 ( V_30 -> V_15 , V_30 ) ;
if ( ! V_15 )
goto V_55;
V_30 -> V_15 = NULL ;
V_48 = V_15 -> V_48 ;
for ( V_46 = 0 ; V_46 < V_15 -> V_20 ; V_46 ++ ) {
F_112 (mp, p, n, &mdb->mhash[i],
hlist[ver]) {
F_38 ( & V_25 -> V_54 ) ;
F_38 ( & V_25 -> V_59 ) ;
F_39 ( & V_25 -> V_39 , F_31 ) ;
}
}
if ( V_15 -> V_40 ) {
F_156 ( & V_30 -> V_52 ) ;
F_157 () ;
F_155 ( & V_30 -> V_52 ) ;
F_42 ( V_15 -> V_40 ) ;
}
V_15 -> V_40 = V_15 ;
F_39 ( & V_15 -> V_39 , F_24 ) ;
V_55:
F_156 ( & V_30 -> V_52 ) ;
}
int F_158 ( struct V_29 * V_30 , unsigned long V_212 )
{
int V_66 = - V_213 ;
F_155 ( & V_30 -> V_52 ) ;
if ( ! F_34 ( V_30 -> V_53 ) )
goto V_214;
switch ( V_212 ) {
case 0 :
case 2 :
F_38 ( & V_30 -> V_141 ) ;
case 1 :
V_30 -> V_140 = V_212 ;
V_66 = 0 ;
break;
default:
V_66 = - V_49 ;
break;
}
V_214:
F_156 ( & V_30 -> V_52 ) ;
return V_66 ;
}
int F_159 ( struct V_123 * V_27 , unsigned long V_212 )
{
struct V_29 * V_30 = V_27 -> V_30 ;
int V_66 = - V_213 ;
F_33 ( & V_30 -> V_52 ) ;
if ( ! F_34 ( V_30 -> V_53 ) || V_27 -> V_135 == V_136 )
goto V_214;
switch ( V_212 ) {
case 0 :
case 1 :
case 2 :
V_27 -> V_140 = V_212 ;
V_66 = 0 ;
if ( V_212 < 2 && ! F_47 ( & V_27 -> V_142 ) )
F_98 ( & V_27 -> V_142 ) ;
if ( V_212 == 1 )
break;
F_38 ( & V_27 -> V_141 ) ;
if ( V_212 == 0 )
break;
F_120 ( V_30 , V_27 ) ;
break;
default:
V_66 = - V_49 ;
break;
}
V_214:
F_40 ( & V_30 -> V_52 ) ;
return V_66 ;
}
int F_160 ( struct V_29 * V_30 , unsigned long V_212 )
{
struct V_123 * V_64 ;
int V_66 = 0 ;
struct V_14 * V_15 ;
F_33 ( & V_30 -> V_52 ) ;
if ( V_30 -> V_33 == ! V_212 )
goto V_214;
V_30 -> V_33 = ! V_212 ;
if ( V_30 -> V_33 )
goto V_214;
if ( ! F_34 ( V_30 -> V_53 ) )
goto V_214;
V_15 = F_36 ( V_30 -> V_15 , V_30 ) ;
if ( V_15 ) {
if ( V_15 -> V_40 ) {
V_66 = - V_130 ;
V_215:
V_30 -> V_33 = ! ! V_212 ;
goto V_214;
}
V_66 = F_48 ( & V_30 -> V_15 , V_15 -> V_20 ,
V_30 -> V_125 ) ;
if ( V_66 )
goto V_215;
}
F_153 ( V_30 ) ;
F_161 (port, &br->port_list, list) {
if ( V_64 -> V_135 == V_136 ||
V_64 -> V_135 == V_152 )
continue;
F_108 ( V_64 ) ;
}
V_214:
F_40 ( & V_30 -> V_52 ) ;
return V_66 ;
}
int F_162 ( struct V_29 * V_30 , unsigned long V_212 )
{
int V_66 = - V_213 ;
V_19 V_40 ;
struct V_14 * V_15 ;
F_33 ( & V_30 -> V_52 ) ;
if ( ! F_34 ( V_30 -> V_53 ) )
goto V_214;
V_66 = - V_49 ;
if ( ! F_163 ( V_212 ) )
goto V_214;
V_15 = F_36 ( V_30 -> V_15 , V_30 ) ;
if ( V_15 && V_212 < V_15 -> V_58 )
goto V_214;
V_66 = 0 ;
V_40 = V_30 -> V_127 ;
V_30 -> V_127 = V_212 ;
if ( V_15 ) {
if ( V_15 -> V_40 ) {
V_66 = - V_130 ;
V_215:
V_30 -> V_127 = V_40 ;
goto V_214;
}
V_66 = F_48 ( & V_30 -> V_15 , V_30 -> V_127 ,
V_30 -> V_125 ) ;
if ( V_66 )
goto V_215;
}
V_214:
F_40 ( & V_30 -> V_52 ) ;
return V_66 ;
}
