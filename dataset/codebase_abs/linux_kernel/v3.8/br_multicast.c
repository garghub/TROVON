static inline int F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
if ( V_2 -> V_4 != V_3 -> V_4 )
return 0 ;
switch ( V_2 -> V_4 ) {
case F_2 ( V_5 ) :
return V_2 -> V_6 . V_7 == V_3 -> V_6 . V_7 ;
#if F_3 ( V_8 )
case F_2 ( V_9 ) :
return F_4 ( & V_2 -> V_6 . V_10 , & V_3 -> V_6 . V_10 ) ;
#endif
}
return 0 ;
}
static inline int F_5 ( struct V_11 * V_12 , T_1 V_13 )
{
return F_6 ( V_12 -> V_14 , ( V_15 V_16 ) V_13 ) & ( V_12 -> V_17 - 1 ) ;
}
static inline int F_7 ( struct V_11 * V_12 ,
const struct V_18 * V_13 )
{
return F_8 ( ( V_15 V_16 * ) V_13 -> V_19 , 4 , V_12 -> V_14 ) & ( V_12 -> V_17 - 1 ) ;
}
static inline int F_9 ( struct V_11 * V_12 ,
struct V_1 * V_13 )
{
switch ( V_13 -> V_4 ) {
case F_2 ( V_5 ) :
return F_5 ( V_12 , V_13 -> V_6 . V_7 ) ;
#if F_3 ( V_8 )
case F_2 ( V_9 ) :
return F_7 ( V_12 , & V_13 -> V_6 . V_10 ) ;
#endif
}
return 0 ;
}
static struct V_20 * F_10 (
struct V_11 * V_12 , struct V_1 * V_21 , int V_22 )
{
struct V_20 * V_23 ;
struct V_24 * V_25 ;
F_11 (mp, p, &mdb->mhash[hash], hlist[mdb->ver]) {
if ( F_1 ( & V_23 -> V_26 , V_21 ) )
return V_23 ;
}
return NULL ;
}
struct V_20 * F_12 ( struct V_11 * V_12 ,
struct V_1 * V_21 )
{
if ( ! V_12 )
return NULL ;
return F_10 ( V_12 , V_21 , F_9 ( V_12 , V_21 ) ) ;
}
static struct V_20 * F_13 (
struct V_11 * V_12 , T_1 V_21 )
{
struct V_1 V_27 ;
V_27 . V_6 . V_7 = V_21 ;
V_27 . V_4 = F_2 ( V_5 ) ;
return F_12 ( V_12 , & V_27 ) ;
}
static struct V_20 * F_14 (
struct V_11 * V_12 , const struct V_18 * V_21 )
{
struct V_1 V_27 ;
V_27 . V_6 . V_10 = * V_21 ;
V_27 . V_4 = F_2 ( V_9 ) ;
return F_12 ( V_12 , & V_27 ) ;
}
struct V_20 * F_15 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_11 * V_12 = F_16 ( V_29 -> V_12 ) ;
struct V_1 V_13 ;
if ( V_29 -> V_32 )
return NULL ;
if ( F_17 ( V_31 ) -> V_33 )
return NULL ;
V_13 . V_4 = V_31 -> V_34 ;
switch ( V_31 -> V_34 ) {
case F_2 ( V_5 ) :
V_13 . V_6 . V_7 = F_18 ( V_31 ) -> V_35 ;
break;
#if F_3 ( V_8 )
case F_2 ( V_9 ) :
V_13 . V_6 . V_10 = F_19 ( V_31 ) -> V_35 ;
break;
#endif
default:
return NULL ;
}
return F_12 ( V_12 , & V_13 ) ;
}
static void F_20 ( struct V_36 * V_37 )
{
struct V_11 * V_12 =
F_21 ( V_37 , struct V_11 , V_38 ) ;
struct V_11 * V_39 = V_12 -> V_39 ;
V_12 -> V_39 = NULL ;
F_22 ( V_39 -> V_40 ) ;
F_22 ( V_39 ) ;
}
static int F_23 ( struct V_11 * V_41 ,
struct V_11 * V_39 ,
int V_42 )
{
struct V_20 * V_23 ;
struct V_24 * V_25 ;
int V_43 ;
int V_44 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_39 -> V_17 ; V_45 ++ )
F_24 (mp, p, &old->mhash[i], hlist[old->ver])
F_25 ( & V_23 -> V_46 [ V_41 -> V_47 ] ,
& V_41 -> V_40 [ F_9 ( V_41 , & V_23 -> V_26 ) ] ) ;
if ( ! V_42 )
return 0 ;
V_43 = 0 ;
for ( V_45 = 0 ; V_45 < V_41 -> V_17 ; V_45 ++ ) {
V_44 = 0 ;
F_24 (mp, p, &new->mhash[i], hlist[new->ver])
V_44 ++ ;
if ( V_44 > V_43 )
V_43 = V_44 ;
}
return V_43 > V_42 ? - V_48 : 0 ;
}
void F_26 ( struct V_36 * V_37 )
{
struct V_49 * V_25 =
F_21 ( V_37 , struct V_49 , V_38 ) ;
F_22 ( V_25 ) ;
}
static void F_27 ( struct V_36 * V_37 )
{
struct V_20 * V_23 =
F_21 ( V_37 , struct V_20 , V_38 ) ;
F_22 ( V_23 ) ;
}
static void F_28 ( unsigned long V_50 )
{
struct V_20 * V_23 = ( void * ) V_50 ;
struct V_28 * V_29 = V_23 -> V_29 ;
struct V_11 * V_12 ;
F_29 ( & V_29 -> V_51 ) ;
if ( ! F_30 ( V_29 -> V_52 ) || F_31 ( & V_23 -> V_53 ) )
goto V_54;
V_23 -> V_55 = false ;
if ( V_23 -> V_56 )
goto V_54;
V_12 = F_32 ( V_29 -> V_12 , V_29 ) ;
F_33 ( & V_23 -> V_46 [ V_12 -> V_47 ] ) ;
V_12 -> V_57 -- ;
F_34 ( & V_23 -> V_38 , F_27 ) ;
V_54:
F_35 ( & V_29 -> V_51 ) ;
}
static void F_36 ( struct V_28 * V_29 ,
struct V_49 * V_58 )
{
struct V_11 * V_12 ;
struct V_20 * V_23 ;
struct V_49 * V_25 ;
struct V_49 T_2 * * V_59 ;
V_12 = F_32 ( V_29 -> V_12 , V_29 ) ;
V_23 = F_12 ( V_12 , & V_58 -> V_26 ) ;
if ( F_37 ( ! V_23 ) )
return;
for ( V_59 = & V_23 -> V_56 ;
( V_25 = F_32 ( * V_59 , V_29 ) ) != NULL ;
V_59 = & V_25 -> V_60 ) {
if ( V_25 != V_58 )
continue;
F_38 ( * V_59 , V_25 -> V_60 ) ;
F_39 ( & V_25 -> V_55 ) ;
F_40 ( & V_25 -> V_53 ) ;
F_34 ( & V_25 -> V_38 , F_26 ) ;
if ( ! V_23 -> V_56 && ! V_23 -> V_55 &&
F_30 ( V_29 -> V_52 ) )
F_41 ( & V_23 -> V_53 , V_61 ) ;
return;
}
F_37 ( 1 ) ;
}
static void F_42 ( unsigned long V_50 )
{
struct V_49 * V_58 = ( void * ) V_50 ;
struct V_28 * V_29 = V_58 -> V_62 -> V_29 ;
F_29 ( & V_29 -> V_51 ) ;
if ( ! F_30 ( V_29 -> V_52 ) || F_31 ( & V_58 -> V_53 ) ||
F_43 ( & V_58 -> V_55 ) || V_58 -> V_63 & V_64 )
goto V_54;
F_36 ( V_29 , V_58 ) ;
V_54:
F_35 ( & V_29 -> V_51 ) ;
}
static int F_44 ( struct V_11 T_2 * * V_65 , int V_17 ,
int V_42 )
{
struct V_11 * V_39 = F_45 ( * V_65 , 1 ) ;
struct V_11 * V_12 ;
int V_66 ;
V_12 = F_46 ( sizeof( * V_12 ) , V_67 ) ;
if ( ! V_12 )
return - V_68 ;
V_12 -> V_17 = V_17 ;
V_12 -> V_39 = V_39 ;
V_12 -> V_40 = F_47 ( V_17 * sizeof( * V_12 -> V_40 ) , V_67 ) ;
if ( ! V_12 -> V_40 ) {
F_22 ( V_12 ) ;
return - V_68 ;
}
V_12 -> V_57 = V_39 ? V_39 -> V_57 : 0 ;
V_12 -> V_47 = V_39 ? V_39 -> V_47 ^ 1 : 0 ;
if ( ! V_39 || V_42 )
F_48 ( & V_12 -> V_14 , sizeof( V_12 -> V_14 ) ) ;
else
V_12 -> V_14 = V_39 -> V_14 ;
if ( ! V_39 )
goto V_54;
V_66 = F_23 ( V_12 , V_39 , V_42 ) ;
if ( V_66 ) {
F_22 ( V_12 -> V_40 ) ;
F_22 ( V_12 ) ;
return V_66 ;
}
V_69 ++ ;
F_34 ( & V_12 -> V_38 , F_20 ) ;
V_54:
F_38 ( * V_65 , V_12 ) ;
return 0 ;
}
static struct V_30 * F_49 ( struct V_28 * V_29 ,
T_1 V_70 )
{
struct V_30 * V_31 ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
V_31 = F_50 ( V_29 -> V_52 , sizeof( * V_74 ) + sizeof( * V_76 ) +
sizeof( * V_72 ) + 4 ) ;
if ( ! V_31 )
goto V_54;
V_31 -> V_34 = F_2 ( V_5 ) ;
F_51 ( V_31 ) ;
V_74 = F_52 ( V_31 ) ;
memcpy ( V_74 -> V_77 , V_29 -> V_52 -> V_78 , 6 ) ;
V_74 -> V_79 [ 0 ] = 1 ;
V_74 -> V_79 [ 1 ] = 0 ;
V_74 -> V_79 [ 2 ] = 0x5e ;
V_74 -> V_79 [ 3 ] = 0 ;
V_74 -> V_79 [ 4 ] = 0 ;
V_74 -> V_79 [ 5 ] = 1 ;
V_74 -> V_80 = F_2 ( V_5 ) ;
F_53 ( V_31 , sizeof( * V_74 ) ) ;
F_54 ( V_31 , V_31 -> V_44 ) ;
V_76 = F_18 ( V_31 ) ;
V_76 -> V_81 = 4 ;
V_76 -> V_82 = 6 ;
V_76 -> V_83 = 0xc0 ;
V_76 -> V_84 = F_2 ( sizeof( * V_76 ) + sizeof( * V_72 ) + 4 ) ;
V_76 -> V_85 = 0 ;
V_76 -> V_86 = F_2 ( V_87 ) ;
V_76 -> V_88 = 1 ;
V_76 -> V_34 = V_89 ;
V_76 -> V_90 = 0 ;
V_76 -> V_35 = F_55 ( V_91 ) ;
( ( V_92 * ) & V_76 [ 1 ] ) [ 0 ] = V_93 ;
( ( V_92 * ) & V_76 [ 1 ] ) [ 1 ] = 4 ;
( ( V_92 * ) & V_76 [ 1 ] ) [ 2 ] = 0 ;
( ( V_92 * ) & V_76 [ 1 ] ) [ 3 ] = 0 ;
F_56 ( V_76 ) ;
F_53 ( V_31 , 24 ) ;
F_57 ( V_31 , V_31 -> V_44 ) ;
V_72 = F_58 ( V_31 ) ;
V_72 -> type = V_94 ;
V_72 -> V_95 = ( V_70 ? V_29 -> V_96 :
V_29 -> V_97 ) /
( V_98 / V_99 ) ;
V_72 -> V_70 = V_70 ;
V_72 -> V_100 = 0 ;
V_72 -> V_100 = F_59 ( ( void * ) V_72 , sizeof( struct V_71 ) ) ;
F_53 ( V_31 , sizeof( * V_72 ) ) ;
F_60 ( V_31 , sizeof( * V_74 ) ) ;
V_54:
return V_31 ;
}
static struct V_30 * F_61 ( struct V_28 * V_29 ,
const struct V_18 * V_70 )
{
struct V_30 * V_31 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_73 * V_74 ;
V_92 * V_105 ;
unsigned long V_106 ;
V_31 = F_50 ( V_29 -> V_52 , sizeof( * V_74 ) + sizeof( * V_102 ) +
8 + sizeof( * V_104 ) ) ;
if ( ! V_31 )
goto V_54;
V_31 -> V_34 = F_2 ( V_9 ) ;
F_51 ( V_31 ) ;
V_74 = F_52 ( V_31 ) ;
memcpy ( V_74 -> V_77 , V_29 -> V_52 -> V_78 , 6 ) ;
V_74 -> V_80 = F_2 ( V_9 ) ;
F_53 ( V_31 , sizeof( * V_74 ) ) ;
F_54 ( V_31 , V_31 -> V_44 ) ;
V_102 = F_19 ( V_31 ) ;
* ( V_15 T_1 * ) V_102 = F_55 ( 0x60000000 ) ;
V_102 -> V_107 = F_2 ( 8 + sizeof( * V_104 ) ) ;
V_102 -> V_108 = V_109 ;
V_102 -> V_110 = 1 ;
F_62 ( & V_102 -> V_35 , F_55 ( 0xff020000 ) , 0 , 0 , F_55 ( 1 ) ) ;
if ( F_63 ( F_64 ( V_29 -> V_52 ) , V_29 -> V_52 , & V_102 -> V_35 , 0 ,
& V_102 -> V_90 ) ) {
F_65 ( V_31 ) ;
return NULL ;
}
F_66 ( & V_102 -> V_35 , V_74 -> V_79 ) ;
V_105 = ( V_92 * ) ( V_102 + 1 ) ;
V_105 [ 0 ] = V_111 ;
V_105 [ 1 ] = 0 ;
V_105 [ 2 ] = V_112 ;
V_105 [ 3 ] = 2 ;
V_105 [ 4 ] = 0 ;
V_105 [ 5 ] = 0 ;
V_105 [ 6 ] = V_113 ;
V_105 [ 7 ] = V_113 ;
F_53 ( V_31 , sizeof( * V_102 ) + 8 ) ;
F_57 ( V_31 , V_31 -> V_44 ) ;
V_104 = (struct V_103 * ) F_67 ( V_31 ) ;
V_106 = F_68 ( V_70 ) ? V_29 -> V_96 :
V_29 -> V_97 ;
V_104 -> V_114 = V_115 ;
V_104 -> V_116 = 0 ;
V_104 -> V_117 = 0 ;
V_104 -> V_118 = F_2 ( ( V_119 ) F_69 ( V_106 ) ) ;
V_104 -> V_120 = 0 ;
V_104 -> V_121 = * V_70 ;
V_104 -> V_117 = F_70 ( & V_102 -> V_90 , & V_102 -> V_35 ,
sizeof( * V_104 ) , V_111 ,
F_71 ( V_104 ,
sizeof( * V_104 ) , 0 ) ) ;
F_53 ( V_31 , sizeof( * V_104 ) ) ;
F_60 ( V_31 , sizeof( * V_74 ) ) ;
V_54:
return V_31 ;
}
static struct V_30 * F_72 ( struct V_28 * V_29 ,
struct V_1 * V_26 )
{
switch ( V_26 -> V_4 ) {
case F_2 ( V_5 ) :
return F_49 ( V_29 , V_26 -> V_6 . V_7 ) ;
#if F_3 ( V_8 )
case F_2 ( V_9 ) :
return F_61 ( V_29 , & V_26 -> V_6 . V_10 ) ;
#endif
}
return NULL ;
}
static struct V_20 * F_73 (
struct V_28 * V_29 , struct V_122 * V_62 ,
struct V_1 * V_70 , int V_22 )
{
struct V_11 * V_12 ;
struct V_20 * V_23 ;
struct V_24 * V_25 ;
unsigned int V_123 = 0 ;
unsigned int V_17 ;
int V_42 ;
int V_66 ;
V_12 = F_45 ( V_29 -> V_12 , 1 ) ;
F_24 (mp, p, &mdb->mhash[hash], hlist[mdb->ver]) {
V_123 ++ ;
if ( F_74 ( F_1 ( V_70 , & V_23 -> V_26 ) ) )
return V_23 ;
}
V_42 = 0 ;
V_17 = V_12 -> V_17 ;
if ( F_74 ( V_123 > V_29 -> V_124 && V_123 ) ) {
if ( F_75 () )
F_76 ( V_29 , L_1
L_2 ,
V_62 ? V_62 -> V_52 -> V_125 : V_29 -> V_52 -> V_125 ) ;
V_42 = V_29 -> V_124 ;
}
if ( V_12 -> V_57 >= V_17 ) {
V_17 *= 2 ;
if ( F_74 ( V_17 > V_29 -> V_126 ) ) {
F_77 ( V_29 , L_3
L_4 ,
V_29 -> V_126 ,
V_62 ? V_62 -> V_52 -> V_125 : V_29 -> V_52 -> V_125 ) ;
V_66 = - V_127 ;
V_128:
V_29 -> V_32 = 1 ;
goto V_66;
}
}
if ( V_17 > V_12 -> V_17 || V_42 ) {
if ( V_12 -> V_39 ) {
if ( F_75 () )
F_76 ( V_29 , L_1
L_5 ,
V_62 ? V_62 -> V_52 -> V_125 : V_29 -> V_52 -> V_125 ) ;
V_66 = - V_129 ;
goto V_66;
}
V_66 = F_44 ( & V_29 -> V_12 , V_17 , V_42 ) ;
if ( V_66 ) {
F_77 ( V_29 , L_6
L_7 ,
V_62 ? V_62 -> V_52 -> V_125 : V_29 -> V_52 -> V_125 ,
V_12 -> V_57 , V_66 ) ;
goto V_128;
}
V_66 = - V_130 ;
goto V_66;
}
return NULL ;
V_66:
V_23 = F_78 ( V_66 ) ;
return V_23 ;
}
struct V_20 * F_79 ( struct V_28 * V_29 ,
struct V_122 * V_62 , struct V_1 * V_70 )
{
struct V_11 * V_12 ;
struct V_20 * V_23 ;
int V_22 ;
int V_66 ;
V_12 = F_45 ( V_29 -> V_12 , 1 ) ;
if ( ! V_12 ) {
V_66 = F_44 ( & V_29 -> V_12 , V_131 , 0 ) ;
if ( V_66 )
return F_78 ( V_66 ) ;
goto V_132;
}
V_22 = F_9 ( V_12 , V_70 ) ;
V_23 = F_73 ( V_29 , V_62 , V_70 , V_22 ) ;
switch ( F_80 ( V_23 ) ) {
case 0 :
break;
case - V_130 :
V_132:
V_12 = F_45 ( V_29 -> V_12 , 1 ) ;
V_22 = F_9 ( V_12 , V_70 ) ;
break;
default:
goto V_54;
}
V_23 = F_47 ( sizeof( * V_23 ) , V_67 ) ;
if ( F_74 ( ! V_23 ) )
return F_78 ( - V_68 ) ;
V_23 -> V_29 = V_29 ;
V_23 -> V_26 = * V_70 ;
F_81 ( & V_23 -> V_53 , F_28 ,
( unsigned long ) V_23 ) ;
F_82 ( & V_23 -> V_46 [ V_12 -> V_47 ] , & V_12 -> V_40 [ V_22 ] ) ;
V_12 -> V_57 ++ ;
V_54:
return V_23 ;
}
struct V_49 * F_83 (
struct V_122 * V_62 ,
struct V_1 * V_70 ,
struct V_49 T_2 * V_60 ,
unsigned char V_63 )
{
struct V_49 * V_25 ;
V_25 = F_47 ( sizeof( * V_25 ) , V_67 ) ;
if ( F_74 ( ! V_25 ) )
return NULL ;
V_25 -> V_26 = * V_70 ;
V_25 -> V_62 = V_62 ;
V_25 -> V_63 = V_63 ;
F_38 ( V_25 -> V_60 , V_60 ) ;
F_25 ( & V_25 -> V_55 , & V_62 -> V_55 ) ;
F_81 ( & V_25 -> V_53 , F_42 ,
( unsigned long ) V_25 ) ;
return V_25 ;
}
static int F_84 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
struct V_1 * V_70 )
{
struct V_20 * V_23 ;
struct V_49 * V_25 ;
struct V_49 T_2 * * V_59 ;
unsigned long V_133 = V_61 ;
int V_66 ;
F_29 ( & V_29 -> V_51 ) ;
if ( ! F_30 ( V_29 -> V_52 ) ||
( V_62 && V_62 -> V_63 == V_134 ) )
goto V_54;
V_23 = F_79 ( V_29 , V_62 , V_70 ) ;
V_66 = F_80 ( V_23 ) ;
if ( F_85 ( V_23 ) )
goto V_66;
if ( ! V_62 ) {
V_23 -> V_55 = true ;
F_41 ( & V_23 -> V_53 , V_133 + V_29 -> V_135 ) ;
goto V_54;
}
for ( V_59 = & V_23 -> V_56 ;
( V_25 = F_32 ( * V_59 , V_29 ) ) != NULL ;
V_59 = & V_25 -> V_60 ) {
if ( V_25 -> V_62 == V_62 )
goto V_136;
if ( ( unsigned long ) V_25 -> V_62 < ( unsigned long ) V_62 )
break;
}
V_25 = F_83 ( V_62 , V_70 , * V_59 , V_137 ) ;
if ( F_74 ( ! V_25 ) )
goto V_66;
F_38 ( * V_59 , V_25 ) ;
F_86 ( V_29 -> V_52 , V_62 , V_70 , V_138 ) ;
V_136:
F_41 ( & V_25 -> V_53 , V_133 + V_29 -> V_135 ) ;
V_54:
V_66 = 0 ;
V_66:
F_35 ( & V_29 -> V_51 ) ;
return V_66 ;
}
static int F_87 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
T_1 V_70 )
{
struct V_1 V_139 ;
if ( F_88 ( V_70 ) )
return 0 ;
V_139 . V_6 . V_7 = V_70 ;
V_139 . V_4 = F_2 ( V_5 ) ;
return F_84 ( V_29 , V_62 , & V_139 ) ;
}
static int F_89 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
const struct V_18 * V_70 )
{
struct V_1 V_139 ;
if ( ! F_90 ( V_70 ) )
return 0 ;
V_139 . V_6 . V_10 = * V_70 ;
V_139 . V_4 = F_2 ( V_9 ) ;
return F_84 ( V_29 , V_62 , & V_139 ) ;
}
static void F_91 ( unsigned long V_50 )
{
struct V_122 * V_62 = ( void * ) V_50 ;
struct V_28 * V_29 = V_62 -> V_29 ;
F_29 ( & V_29 -> V_51 ) ;
if ( V_62 -> V_140 != 1 ||
F_31 ( & V_62 -> V_141 ) ||
F_43 ( & V_62 -> V_142 ) )
goto V_54;
F_92 ( & V_62 -> V_142 ) ;
V_54:
F_35 ( & V_29 -> V_51 ) ;
}
static void F_93 ( unsigned long V_50 )
{
}
static void F_94 ( unsigned long V_50 )
{
struct V_28 * V_29 = ( void * ) V_50 ;
F_29 ( & V_29 -> V_51 ) ;
if ( ! F_30 ( V_29 -> V_52 ) || V_29 -> V_32 )
goto V_54;
F_95 ( V_29 ) ;
V_54:
F_35 ( & V_29 -> V_51 ) ;
}
static void F_96 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
struct V_1 * V_13 )
{
struct V_30 * V_31 ;
V_31 = F_72 ( V_29 , V_13 ) ;
if ( ! V_31 )
return;
if ( V_62 ) {
F_97 ( V_31 , sizeof( struct V_73 ) ) ;
V_31 -> V_52 = V_62 -> V_52 ;
F_98 ( V_143 , V_144 , V_31 , NULL , V_31 -> V_52 ,
V_145 ) ;
} else
F_99 ( V_31 ) ;
}
static void F_100 ( struct V_28 * V_29 ,
struct V_122 * V_62 , V_16 V_146 )
{
unsigned long time ;
struct V_1 V_139 ;
if ( ! F_30 ( V_29 -> V_52 ) || V_29 -> V_32 ||
! V_29 -> V_147 ||
F_31 ( & V_29 -> V_148 ) )
return;
memset ( & V_139 . V_6 , 0 , sizeof( V_139 . V_6 ) ) ;
V_139 . V_4 = F_2 ( V_5 ) ;
F_96 ( V_29 , V_62 , & V_139 ) ;
#if F_3 ( V_8 )
V_139 . V_4 = F_2 ( V_9 ) ;
F_96 ( V_29 , V_62 , & V_139 ) ;
#endif
time = V_61 ;
time += V_146 < V_29 -> V_149 ?
V_29 -> V_150 :
V_29 -> V_151 ;
F_41 ( V_62 ? & V_62 -> V_152 :
& V_29 -> V_152 , time ) ;
}
static void F_101 ( unsigned long V_50 )
{
struct V_122 * V_62 = ( void * ) V_50 ;
struct V_28 * V_29 = V_62 -> V_29 ;
F_29 ( & V_29 -> V_51 ) ;
if ( V_62 -> V_63 == V_134 ||
V_62 -> V_63 == V_153 )
goto V_54;
if ( V_62 -> V_154 <
V_29 -> V_149 )
V_62 -> V_154 ++ ;
F_100 ( V_62 -> V_29 , V_62 ,
V_62 -> V_154 ) ;
V_54:
F_35 ( & V_29 -> V_51 ) ;
}
void F_102 ( struct V_122 * V_62 )
{
V_62 -> V_140 = 1 ;
F_81 ( & V_62 -> V_141 , F_91 ,
( unsigned long ) V_62 ) ;
F_81 ( & V_62 -> V_152 ,
F_101 , ( unsigned long ) V_62 ) ;
}
void F_103 ( struct V_122 * V_62 )
{
F_104 ( & V_62 -> V_141 ) ;
}
static void F_105 ( struct V_122 * V_62 )
{
V_62 -> V_154 = 0 ;
if ( F_106 ( & V_62 -> V_152 ) >= 0 ||
F_40 ( & V_62 -> V_152 ) )
F_41 ( & V_62 -> V_152 , V_61 ) ;
}
void F_107 ( struct V_122 * V_62 )
{
struct V_28 * V_29 = V_62 -> V_29 ;
F_29 ( & V_29 -> V_51 ) ;
if ( V_29 -> V_32 || ! F_30 ( V_29 -> V_52 ) )
goto V_54;
F_105 ( V_62 ) ;
V_54:
F_35 ( & V_29 -> V_51 ) ;
}
void F_108 ( struct V_122 * V_62 )
{
struct V_28 * V_29 = V_62 -> V_29 ;
struct V_49 * V_58 ;
struct V_24 * V_25 , * V_155 ;
F_29 ( & V_29 -> V_51 ) ;
F_109 (pg, p, n, &port->mglist, mglist)
F_36 ( V_29 , V_58 ) ;
if ( ! F_43 ( & V_62 -> V_142 ) )
F_92 ( & V_62 -> V_142 ) ;
F_40 ( & V_62 -> V_141 ) ;
F_40 ( & V_62 -> V_152 ) ;
F_35 ( & V_29 -> V_51 ) ;
}
static int F_110 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
struct V_30 * V_31 )
{
struct V_156 * V_72 ;
struct V_157 * V_158 ;
int V_45 ;
int V_44 ;
int V_159 ;
int type ;
int V_66 = 0 ;
T_1 V_70 ;
if ( ! F_111 ( V_31 , sizeof( * V_72 ) ) )
return - V_48 ;
V_72 = F_112 ( V_31 ) ;
V_159 = F_113 ( V_72 -> V_160 ) ;
V_44 = sizeof( * V_72 ) ;
for ( V_45 = 0 ; V_45 < V_159 ; V_45 ++ ) {
V_44 += sizeof( * V_158 ) ;
if ( ! F_111 ( V_31 , V_44 ) )
return - V_48 ;
V_158 = ( void * ) ( V_31 -> V_50 + V_44 - sizeof( * V_158 ) ) ;
V_70 = V_158 -> V_161 ;
type = V_158 -> V_162 ;
V_44 += F_113 ( V_158 -> V_163 ) * 4 ;
if ( ! F_111 ( V_31 , V_44 ) )
return - V_48 ;
switch ( type ) {
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
break;
default:
continue;
}
V_66 = F_87 ( V_29 , V_62 , V_70 ) ;
if ( V_66 )
break;
}
return V_66 ;
}
static int F_114 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
struct V_30 * V_31 )
{
struct V_170 * V_171 ;
struct V_172 * V_158 ;
int V_45 ;
int V_44 ;
int V_159 ;
int V_66 = 0 ;
if ( ! F_111 ( V_31 , sizeof( * V_171 ) ) )
return - V_48 ;
V_171 = F_67 ( V_31 ) ;
V_159 = F_113 ( V_171 -> V_173 . V_174 [ 1 ] ) ;
V_44 = sizeof( * V_171 ) ;
for ( V_45 = 0 ; V_45 < V_159 ; V_45 ++ ) {
T_3 * V_175 , V_176 ;
V_175 = F_115 ( V_31 ,
V_44 + F_116 ( struct V_172 ,
V_163 ) ,
sizeof( V_176 ) , & V_176 ) ;
if ( ! V_175 )
return - V_48 ;
if ( ! F_111 ( V_31 ,
V_44 + sizeof( * V_158 ) +
sizeof( struct V_18 ) * F_113 ( * V_175 ) ) )
return - V_48 ;
V_158 = (struct V_172 * ) ( V_31 -> V_50 + V_44 ) ;
V_44 += sizeof( * V_158 ) +
sizeof( struct V_18 ) * F_113 ( * V_175 ) ;
switch ( V_158 -> V_162 ) {
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
break;
default:
continue;
}
V_66 = F_89 ( V_29 , V_62 , & V_158 -> V_161 ) ;
if ( ! V_66 )
break;
}
return V_66 ;
}
static void F_117 ( struct V_28 * V_29 ,
struct V_122 * V_62 )
{
struct V_122 * V_25 ;
struct V_24 * V_155 , * V_183 = NULL ;
F_24 (p, n, &br->router_list, rlist) {
if ( ( unsigned long ) V_62 >= ( unsigned long ) V_25 )
break;
V_183 = V_155 ;
}
if ( V_183 )
F_118 ( V_183 , & V_62 -> V_142 ) ;
else
F_82 ( & V_62 -> V_142 , & V_29 -> V_184 ) ;
}
static void F_119 ( struct V_28 * V_29 ,
struct V_122 * V_62 )
{
unsigned long V_133 = V_61 ;
if ( ! V_62 ) {
if ( V_29 -> V_140 == 1 )
F_41 ( & V_29 -> V_141 ,
V_133 + V_29 -> V_185 ) ;
return;
}
if ( V_62 -> V_140 != 1 )
return;
if ( ! F_43 ( & V_62 -> V_142 ) )
goto V_53;
F_117 ( V_29 , V_62 ) ;
V_53:
F_41 ( & V_62 -> V_141 ,
V_133 + V_29 -> V_185 ) ;
}
static void F_120 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
int V_90 )
{
if ( V_90 )
F_41 ( & V_29 -> V_148 ,
V_61 + V_29 -> V_185 ) ;
else if ( F_31 ( & V_29 -> V_148 ) )
return;
F_119 ( V_29 , V_62 ) ;
}
static int F_121 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
struct V_30 * V_31 )
{
const struct V_75 * V_76 = F_18 ( V_31 ) ;
struct V_71 * V_72 = F_58 ( V_31 ) ;
struct V_20 * V_23 ;
struct V_186 * V_187 ;
struct V_49 * V_25 ;
struct V_49 T_2 * * V_59 ;
unsigned long V_188 ;
unsigned long V_133 = V_61 ;
T_1 V_70 ;
int V_66 = 0 ;
F_29 ( & V_29 -> V_51 ) ;
if ( ! F_30 ( V_29 -> V_52 ) ||
( V_62 && V_62 -> V_63 == V_134 ) )
goto V_54;
F_120 ( V_29 , V_62 , ! ! V_76 -> V_90 ) ;
V_70 = V_72 -> V_70 ;
if ( V_31 -> V_44 == sizeof( * V_72 ) ) {
V_188 = V_72 -> V_95 * ( V_98 / V_99 ) ;
if ( ! V_188 ) {
V_188 = 10 * V_98 ;
V_70 = 0 ;
}
} else {
if ( ! F_111 ( V_31 , sizeof( struct V_186 ) ) ) {
V_66 = - V_48 ;
goto V_54;
}
V_187 = F_122 ( V_31 ) ;
if ( V_187 -> V_175 )
goto V_54;
V_188 = V_187 -> V_95 ?
F_123 ( V_187 -> V_95 ) * ( V_98 / V_99 ) : 1 ;
}
if ( ! V_70 )
goto V_54;
V_23 = F_13 ( F_32 ( V_29 -> V_12 , V_29 ) , V_70 ) ;
if ( ! V_23 )
goto V_54;
V_188 *= V_29 -> V_189 ;
if ( V_23 -> V_55 &&
( F_31 ( & V_23 -> V_53 ) ?
F_124 ( V_23 -> V_53 . V_190 , V_133 + V_188 ) :
F_106 ( & V_23 -> V_53 ) >= 0 ) )
F_41 ( & V_23 -> V_53 , V_133 + V_188 ) ;
for ( V_59 = & V_23 -> V_56 ;
( V_25 = F_32 ( * V_59 , V_29 ) ) != NULL ;
V_59 = & V_25 -> V_60 ) {
if ( F_31 ( & V_25 -> V_53 ) ?
F_124 ( V_25 -> V_53 . V_190 , V_133 + V_188 ) :
F_106 ( & V_25 -> V_53 ) >= 0 )
F_41 ( & V_25 -> V_53 , V_133 + V_188 ) ;
}
V_54:
F_35 ( & V_29 -> V_51 ) ;
return V_66 ;
}
static int F_125 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
struct V_30 * V_31 )
{
const struct V_101 * V_102 = F_19 ( V_31 ) ;
struct V_103 * V_191 ;
struct V_20 * V_23 ;
struct V_192 * V_193 ;
struct V_49 * V_25 ;
struct V_49 T_2 * * V_59 ;
unsigned long V_188 ;
unsigned long V_133 = V_61 ;
const struct V_18 * V_70 = NULL ;
int V_66 = 0 ;
F_29 ( & V_29 -> V_51 ) ;
if ( ! F_30 ( V_29 -> V_52 ) ||
( V_62 && V_62 -> V_63 == V_134 ) )
goto V_54;
F_120 ( V_29 , V_62 , ! F_68 ( & V_102 -> V_90 ) ) ;
if ( V_31 -> V_44 == sizeof( * V_191 ) ) {
if ( ! F_111 ( V_31 , sizeof( * V_191 ) ) ) {
V_66 = - V_48 ;
goto V_54;
}
V_191 = (struct V_103 * ) F_67 ( V_31 ) ;
V_188 = F_126 ( F_113 ( V_191 -> V_118 ) ) ;
if ( V_188 )
V_70 = & V_191 -> V_121 ;
} else if ( V_31 -> V_44 >= sizeof( * V_193 ) ) {
if ( ! F_111 ( V_31 , sizeof( * V_193 ) ) ) {
V_66 = - V_48 ;
goto V_54;
}
V_193 = (struct V_192 * ) F_67 ( V_31 ) ;
if ( ! V_193 -> V_194 )
V_70 = & V_193 -> V_195 ;
V_188 = V_193 -> V_196 ? F_127 ( F_113 ( V_193 -> V_196 ) ) : 1 ;
}
if ( ! V_70 )
goto V_54;
V_23 = F_14 ( F_32 ( V_29 -> V_12 , V_29 ) , V_70 ) ;
if ( ! V_23 )
goto V_54;
V_188 *= V_29 -> V_189 ;
if ( V_23 -> V_55 &&
( F_31 ( & V_23 -> V_53 ) ?
F_124 ( V_23 -> V_53 . V_190 , V_133 + V_188 ) :
F_106 ( & V_23 -> V_53 ) >= 0 ) )
F_41 ( & V_23 -> V_53 , V_133 + V_188 ) ;
for ( V_59 = & V_23 -> V_56 ;
( V_25 = F_32 ( * V_59 , V_29 ) ) != NULL ;
V_59 = & V_25 -> V_60 ) {
if ( F_31 ( & V_25 -> V_53 ) ?
F_124 ( V_25 -> V_53 . V_190 , V_133 + V_188 ) :
F_106 ( & V_25 -> V_53 ) >= 0 )
F_41 ( & V_25 -> V_53 , V_133 + V_188 ) ;
}
V_54:
F_35 ( & V_29 -> V_51 ) ;
return V_66 ;
}
static void F_128 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
struct V_1 * V_70 )
{
struct V_11 * V_12 ;
struct V_20 * V_23 ;
struct V_49 * V_25 ;
unsigned long V_133 ;
unsigned long time ;
F_29 ( & V_29 -> V_51 ) ;
if ( ! F_30 ( V_29 -> V_52 ) ||
( V_62 && V_62 -> V_63 == V_134 ) ||
F_31 ( & V_29 -> V_148 ) )
goto V_54;
V_12 = F_32 ( V_29 -> V_12 , V_29 ) ;
V_23 = F_12 ( V_12 , V_70 ) ;
if ( ! V_23 )
goto V_54;
if ( V_62 && ( V_62 -> V_197 & V_198 ) ) {
struct V_49 T_2 * * V_59 ;
for ( V_59 = & V_23 -> V_56 ;
( V_25 = F_32 ( * V_59 , V_29 ) ) != NULL ;
V_59 = & V_25 -> V_60 ) {
if ( V_25 -> V_62 != V_62 )
continue;
F_38 ( * V_59 , V_25 -> V_60 ) ;
F_39 ( & V_25 -> V_55 ) ;
F_40 ( & V_25 -> V_53 ) ;
F_34 ( & V_25 -> V_38 , F_26 ) ;
F_86 ( V_29 -> V_52 , V_62 , V_70 , V_199 ) ;
if ( ! V_23 -> V_56 && ! V_23 -> V_55 &&
F_30 ( V_29 -> V_52 ) )
F_41 ( & V_23 -> V_53 , V_61 ) ;
}
goto V_54;
}
V_133 = V_61 ;
time = V_133 + V_29 -> V_189 *
V_29 -> V_96 ;
if ( ! V_62 ) {
if ( V_23 -> V_55 &&
( F_31 ( & V_23 -> V_53 ) ?
F_124 ( V_23 -> V_53 . V_190 , time ) :
F_106 ( & V_23 -> V_53 ) >= 0 ) ) {
F_41 ( & V_23 -> V_53 , time ) ;
}
goto V_54;
}
for ( V_25 = F_32 ( V_23 -> V_56 , V_29 ) ;
V_25 != NULL ;
V_25 = F_32 ( V_25 -> V_60 , V_29 ) ) {
if ( V_25 -> V_62 != V_62 )
continue;
if ( ! F_43 ( & V_25 -> V_55 ) &&
( F_31 ( & V_25 -> V_53 ) ?
F_124 ( V_25 -> V_53 . V_190 , time ) :
F_106 ( & V_25 -> V_53 ) >= 0 ) ) {
F_41 ( & V_25 -> V_53 , time ) ;
}
break;
}
V_54:
F_35 ( & V_29 -> V_51 ) ;
}
static void F_129 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
T_1 V_70 )
{
struct V_1 V_139 ;
if ( F_88 ( V_70 ) )
return;
V_139 . V_6 . V_7 = V_70 ;
V_139 . V_4 = F_2 ( V_5 ) ;
F_128 ( V_29 , V_62 , & V_139 ) ;
}
static void F_130 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
const struct V_18 * V_70 )
{
struct V_1 V_139 ;
if ( ! F_90 ( V_70 ) )
return;
V_139 . V_6 . V_10 = * V_70 ;
V_139 . V_4 = F_2 ( V_9 ) ;
F_128 ( V_29 , V_62 , & V_139 ) ;
}
static int F_131 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
struct V_30 * V_31 )
{
struct V_30 * V_200 = V_31 ;
const struct V_75 * V_76 ;
struct V_71 * V_72 ;
unsigned int V_44 ;
unsigned int V_201 ;
int V_66 ;
if ( ! F_111 ( V_31 , sizeof( * V_76 ) ) )
return - V_48 ;
V_76 = F_18 ( V_31 ) ;
if ( V_76 -> V_82 < 5 || V_76 -> V_81 != 4 )
return - V_48 ;
if ( ! F_111 ( V_31 , F_132 ( V_31 ) ) )
return - V_48 ;
V_76 = F_18 ( V_31 ) ;
if ( F_74 ( F_133 ( ( V_92 * ) V_76 , V_76 -> V_82 ) ) )
return - V_48 ;
if ( V_76 -> V_34 != V_89 ) {
if ( ( V_76 -> V_35 & V_202 ) != V_203 )
F_17 ( V_31 ) -> V_204 = 1 ;
return 0 ;
}
V_44 = F_113 ( V_76 -> V_84 ) ;
if ( V_31 -> V_44 < V_44 || V_44 < F_132 ( V_31 ) )
return - V_48 ;
if ( V_31 -> V_44 > V_44 ) {
V_200 = F_134 ( V_31 , V_67 ) ;
if ( ! V_200 )
return - V_68 ;
V_66 = F_135 ( V_200 , V_44 ) ;
if ( V_66 )
goto V_205;
}
V_44 -= F_132 ( V_200 ) ;
V_201 = F_136 ( V_200 ) + F_132 ( V_200 ) ;
F_60 ( V_200 , V_201 ) ;
F_137 ( V_200 ) ;
V_66 = - V_48 ;
if ( ! F_111 ( V_200 , sizeof( * V_72 ) ) )
goto V_54;
switch ( V_200 -> V_206 ) {
case V_207 :
if ( ! F_138 ( V_200 -> V_100 ) )
break;
case V_208 :
V_200 -> V_100 = 0 ;
if ( F_139 ( V_200 ) )
goto V_54;
}
V_66 = 0 ;
F_17 ( V_31 ) -> V_33 = 1 ;
V_72 = F_58 ( V_200 ) ;
switch ( V_72 -> type ) {
case V_209 :
case V_210 :
F_17 ( V_31 ) -> V_204 = 1 ;
V_66 = F_87 ( V_29 , V_62 , V_72 -> V_70 ) ;
break;
case V_211 :
V_66 = F_110 ( V_29 , V_62 , V_200 ) ;
break;
case V_94 :
V_66 = F_121 ( V_29 , V_62 , V_200 ) ;
break;
case V_212 :
F_129 ( V_29 , V_62 , V_72 -> V_70 ) ;
break;
}
V_54:
F_97 ( V_200 , V_201 ) ;
V_205:
if ( V_200 != V_31 )
F_65 ( V_200 ) ;
return V_66 ;
}
static int F_140 ( struct V_28 * V_29 ,
struct V_122 * V_62 ,
struct V_30 * V_31 )
{
struct V_30 * V_200 ;
const struct V_101 * V_102 ;
V_92 V_213 ;
V_92 V_108 ;
T_3 V_86 ;
unsigned int V_44 ;
int V_201 ;
int V_66 ;
if ( ! F_111 ( V_31 , sizeof( * V_102 ) ) )
return - V_48 ;
V_102 = F_19 ( V_31 ) ;
if ( V_102 -> V_81 != 6 ||
V_102 -> V_108 != V_109 ||
V_102 -> V_107 == 0 )
return 0 ;
V_44 = F_113 ( V_102 -> V_107 ) + sizeof( * V_102 ) ;
if ( V_31 -> V_44 < V_44 )
return - V_48 ;
V_108 = V_102 -> V_108 ;
V_201 = F_141 ( V_31 , sizeof( * V_102 ) , & V_108 , & V_86 ) ;
if ( V_201 < 0 || V_108 != V_111 )
return 0 ;
V_200 = F_134 ( V_31 , V_67 ) ;
if ( ! V_200 )
return - V_68 ;
V_66 = - V_48 ;
if ( ! F_111 ( V_200 , V_201 + sizeof( struct V_170 ) ) )
goto V_54;
V_44 -= V_201 - F_136 ( V_200 ) ;
F_60 ( V_200 , V_201 ) ;
F_137 ( V_200 ) ;
F_142 ( V_200 , F_143 ( V_200 ) ,
F_144 ( V_200 ) ) ;
V_213 = F_67 ( V_200 ) -> V_213 ;
switch ( V_213 ) {
case V_115 :
case V_214 :
case V_215 :
case V_216 :
break;
default:
V_66 = 0 ;
goto V_54;
}
if ( V_200 -> V_44 > V_44 ) {
V_66 = F_135 ( V_200 , V_44 ) ;
if ( V_66 )
goto V_54;
V_66 = - V_48 ;
}
V_102 = F_19 ( V_200 ) ;
switch ( V_200 -> V_206 ) {
case V_207 :
if ( ! F_70 ( & V_102 -> V_90 , & V_102 -> V_35 , V_200 -> V_44 ,
V_111 , V_200 -> V_100 ) )
break;
case V_208 :
V_200 -> V_100 = ~ F_145 ( F_70 ( & V_102 -> V_90 ,
& V_102 -> V_35 ,
V_200 -> V_44 ,
V_111 , 0 ) ) ;
if ( F_146 ( V_200 ) )
goto V_54;
}
V_66 = 0 ;
F_17 ( V_31 ) -> V_33 = 1 ;
switch ( V_213 ) {
case V_214 :
{
struct V_103 * V_191 ;
if ( ! F_111 ( V_200 , sizeof( * V_191 ) ) ) {
V_66 = - V_48 ;
goto V_54;
}
V_191 = (struct V_103 * ) F_147 ( V_200 ) ;
F_17 ( V_31 ) -> V_204 = 1 ;
V_66 = F_89 ( V_29 , V_62 , & V_191 -> V_121 ) ;
break;
}
case V_216 :
V_66 = F_114 ( V_29 , V_62 , V_200 ) ;
break;
case V_115 :
V_66 = F_125 ( V_29 , V_62 , V_200 ) ;
break;
case V_215 :
{
struct V_103 * V_191 ;
if ( ! F_111 ( V_200 , sizeof( * V_191 ) ) ) {
V_66 = - V_48 ;
goto V_54;
}
V_191 = (struct V_103 * ) F_147 ( V_200 ) ;
F_130 ( V_29 , V_62 , & V_191 -> V_121 ) ;
}
}
V_54:
F_65 ( V_200 ) ;
return V_66 ;
}
int F_148 ( struct V_28 * V_29 , struct V_122 * V_62 ,
struct V_30 * V_31 )
{
F_17 ( V_31 ) -> V_33 = 0 ;
F_17 ( V_31 ) -> V_204 = 0 ;
if ( V_29 -> V_32 )
return 0 ;
switch ( V_31 -> V_34 ) {
case F_2 ( V_5 ) :
return F_131 ( V_29 , V_62 , V_31 ) ;
#if F_3 ( V_8 )
case F_2 ( V_9 ) :
return F_140 ( V_29 , V_62 , V_31 ) ;
#endif
}
return 0 ;
}
static void F_149 ( unsigned long V_50 )
{
struct V_28 * V_29 = ( void * ) V_50 ;
F_29 ( & V_29 -> V_51 ) ;
if ( V_29 -> V_154 <
V_29 -> V_149 )
V_29 -> V_154 ++ ;
F_100 ( V_29 , NULL , V_29 -> V_154 ) ;
F_35 ( & V_29 -> V_51 ) ;
}
void F_150 ( struct V_28 * V_29 )
{
V_29 -> V_124 = 4 ;
V_29 -> V_126 = 512 ;
V_29 -> V_140 = 1 ;
V_29 -> V_147 = 0 ;
V_29 -> V_189 = 2 ;
V_29 -> V_149 = 2 ;
V_29 -> V_96 = V_98 ;
V_29 -> V_97 = 10 * V_98 ;
V_29 -> V_150 = 125 * V_98 / 4 ;
V_29 -> V_151 = 125 * V_98 ;
V_29 -> V_185 = 255 * V_98 ;
V_29 -> V_135 = 260 * V_98 ;
F_151 ( & V_29 -> V_51 ) ;
F_81 ( & V_29 -> V_141 ,
F_93 , 0 ) ;
F_81 ( & V_29 -> V_148 ,
F_94 , ( unsigned long ) V_29 ) ;
F_81 ( & V_29 -> V_152 , F_149 ,
( unsigned long ) V_29 ) ;
}
void F_152 ( struct V_28 * V_29 )
{
V_29 -> V_154 = 0 ;
if ( V_29 -> V_32 )
return;
F_41 ( & V_29 -> V_152 , V_61 ) ;
}
void F_153 ( struct V_28 * V_29 )
{
struct V_11 * V_12 ;
struct V_20 * V_23 ;
struct V_24 * V_25 , * V_155 ;
V_16 V_47 ;
int V_45 ;
F_104 ( & V_29 -> V_141 ) ;
F_104 ( & V_29 -> V_148 ) ;
F_104 ( & V_29 -> V_152 ) ;
F_154 ( & V_29 -> V_51 ) ;
V_12 = F_32 ( V_29 -> V_12 , V_29 ) ;
if ( ! V_12 )
goto V_54;
V_29 -> V_12 = NULL ;
V_47 = V_12 -> V_47 ;
for ( V_45 = 0 ; V_45 < V_12 -> V_17 ; V_45 ++ ) {
F_109 (mp, p, n, &mdb->mhash[i],
hlist[ver]) {
F_40 ( & V_23 -> V_53 ) ;
F_34 ( & V_23 -> V_38 , F_27 ) ;
}
}
if ( V_12 -> V_39 ) {
F_155 ( & V_29 -> V_51 ) ;
F_156 () ;
F_154 ( & V_29 -> V_51 ) ;
F_37 ( V_12 -> V_39 ) ;
}
V_12 -> V_39 = V_12 ;
F_34 ( & V_12 -> V_38 , F_20 ) ;
V_54:
F_155 ( & V_29 -> V_51 ) ;
}
int F_157 ( struct V_28 * V_29 , unsigned long V_217 )
{
int V_66 = - V_218 ;
F_154 ( & V_29 -> V_51 ) ;
if ( ! F_30 ( V_29 -> V_52 ) )
goto V_219;
switch ( V_217 ) {
case 0 :
case 2 :
F_40 ( & V_29 -> V_141 ) ;
case 1 :
V_29 -> V_140 = V_217 ;
V_66 = 0 ;
break;
default:
V_66 = - V_48 ;
break;
}
V_219:
F_155 ( & V_29 -> V_51 ) ;
return V_66 ;
}
int F_158 ( struct V_122 * V_25 , unsigned long V_217 )
{
struct V_28 * V_29 = V_25 -> V_29 ;
int V_66 = - V_218 ;
F_29 ( & V_29 -> V_51 ) ;
if ( ! F_30 ( V_29 -> V_52 ) || V_25 -> V_63 == V_134 )
goto V_219;
switch ( V_217 ) {
case 0 :
case 1 :
case 2 :
V_25 -> V_140 = V_217 ;
V_66 = 0 ;
if ( V_217 < 2 && ! F_43 ( & V_25 -> V_142 ) )
F_92 ( & V_25 -> V_142 ) ;
if ( V_217 == 1 )
break;
F_40 ( & V_25 -> V_141 ) ;
if ( V_217 == 0 )
break;
F_117 ( V_29 , V_25 ) ;
break;
default:
V_66 = - V_48 ;
break;
}
V_219:
F_35 ( & V_29 -> V_51 ) ;
return V_66 ;
}
static void F_95 ( struct V_28 * V_29 )
{
struct V_122 * V_62 ;
F_152 ( V_29 ) ;
F_159 (port, &br->port_list, list) {
if ( V_62 -> V_63 == V_134 ||
V_62 -> V_63 == V_153 )
continue;
F_105 ( V_62 ) ;
}
}
int F_160 ( struct V_28 * V_29 , unsigned long V_217 )
{
int V_66 = 0 ;
struct V_11 * V_12 ;
F_154 ( & V_29 -> V_51 ) ;
if ( V_29 -> V_32 == ! V_217 )
goto V_219;
V_29 -> V_32 = ! V_217 ;
if ( V_29 -> V_32 )
goto V_219;
if ( ! F_30 ( V_29 -> V_52 ) )
goto V_219;
V_12 = F_32 ( V_29 -> V_12 , V_29 ) ;
if ( V_12 ) {
if ( V_12 -> V_39 ) {
V_66 = - V_129 ;
V_220:
V_29 -> V_32 = ! ! V_217 ;
goto V_219;
}
V_66 = F_44 ( & V_29 -> V_12 , V_12 -> V_17 ,
V_29 -> V_124 ) ;
if ( V_66 )
goto V_220;
}
F_95 ( V_29 ) ;
V_219:
F_155 ( & V_29 -> V_51 ) ;
return V_66 ;
}
int F_161 ( struct V_28 * V_29 , unsigned long V_217 )
{
V_217 = ! ! V_217 ;
F_154 ( & V_29 -> V_51 ) ;
if ( V_29 -> V_147 == V_217 )
goto V_219;
V_29 -> V_147 = V_217 ;
if ( V_217 )
F_95 ( V_29 ) ;
V_219:
F_155 ( & V_29 -> V_51 ) ;
return 0 ;
}
int F_162 ( struct V_28 * V_29 , unsigned long V_217 )
{
int V_66 = - V_218 ;
V_16 V_39 ;
struct V_11 * V_12 ;
F_29 ( & V_29 -> V_51 ) ;
if ( ! F_30 ( V_29 -> V_52 ) )
goto V_219;
V_66 = - V_48 ;
if ( ! F_163 ( V_217 ) )
goto V_219;
V_12 = F_32 ( V_29 -> V_12 , V_29 ) ;
if ( V_12 && V_217 < V_12 -> V_57 )
goto V_219;
V_66 = 0 ;
V_39 = V_29 -> V_126 ;
V_29 -> V_126 = V_217 ;
if ( V_12 ) {
if ( V_12 -> V_39 ) {
V_66 = - V_129 ;
V_220:
V_29 -> V_126 = V_39 ;
goto V_219;
}
V_66 = F_44 ( & V_29 -> V_12 , V_29 -> V_126 ,
V_29 -> V_124 ) ;
if ( V_66 )
goto V_220;
}
V_219:
F_35 ( & V_29 -> V_51 ) ;
return V_66 ;
}
