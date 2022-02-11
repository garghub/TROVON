static inline int F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
if ( V_2 -> V_4 != V_3 -> V_4 )
return 0 ;
if ( V_2 -> V_5 != V_3 -> V_5 )
return 0 ;
switch ( V_2 -> V_4 ) {
case F_2 ( V_6 ) :
return V_2 -> V_7 . V_8 == V_3 -> V_7 . V_8 ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_4 ( & V_2 -> V_7 . V_11 , & V_3 -> V_7 . V_11 ) ;
#endif
}
return 0 ;
}
static inline int F_5 ( struct V_12 * V_13 , T_1 V_14 ,
T_2 V_5 )
{
return F_6 ( ( V_15 V_16 ) V_14 , V_5 , V_13 -> V_17 ) & ( V_13 -> V_18 - 1 ) ;
}
static inline int F_7 ( struct V_12 * V_13 ,
const struct V_19 * V_14 ,
T_2 V_5 )
{
return F_6 ( F_8 ( V_14 ) , V_5 ,
V_13 -> V_17 ) & ( V_13 -> V_18 - 1 ) ;
}
static inline int F_9 ( struct V_12 * V_13 ,
struct V_1 * V_14 )
{
switch ( V_14 -> V_4 ) {
case F_2 ( V_6 ) :
return F_5 ( V_13 , V_14 -> V_7 . V_8 , V_14 -> V_5 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_7 ( V_13 , & V_14 -> V_7 . V_11 , V_14 -> V_5 ) ;
#endif
}
return 0 ;
}
static struct V_20 * F_10 (
struct V_12 * V_13 , struct V_1 * V_21 , int V_22 )
{
struct V_20 * V_23 ;
F_11 (mp, &mdb->mhash[hash], hlist[mdb->ver]) {
if ( F_1 ( & V_23 -> V_24 , V_21 ) )
return V_23 ;
}
return NULL ;
}
struct V_20 * F_12 ( struct V_12 * V_13 ,
struct V_1 * V_21 )
{
if ( ! V_13 )
return NULL ;
return F_10 ( V_13 , V_21 , F_9 ( V_13 , V_21 ) ) ;
}
static struct V_20 * F_13 (
struct V_12 * V_13 , T_1 V_21 , T_2 V_5 )
{
struct V_1 V_25 ;
V_25 . V_7 . V_8 = V_21 ;
V_25 . V_4 = F_2 ( V_6 ) ;
V_25 . V_5 = V_5 ;
return F_12 ( V_13 , & V_25 ) ;
}
static struct V_20 * F_14 (
struct V_12 * V_13 , const struct V_19 * V_21 ,
T_2 V_5 )
{
struct V_1 V_25 ;
V_25 . V_7 . V_11 = * V_21 ;
V_25 . V_4 = F_2 ( V_10 ) ;
V_25 . V_5 = V_5 ;
return F_12 ( V_13 , & V_25 ) ;
}
struct V_20 * F_15 ( struct V_26 * V_27 ,
struct V_28 * V_29 , T_3 V_5 )
{
struct V_12 * V_13 = F_16 ( V_27 -> V_13 ) ;
struct V_1 V_14 ;
if ( V_27 -> V_30 )
return NULL ;
if ( F_17 ( V_29 ) -> V_31 )
return NULL ;
V_14 . V_4 = V_29 -> V_32 ;
V_14 . V_5 = V_5 ;
switch ( V_29 -> V_32 ) {
case F_2 ( V_6 ) :
V_14 . V_7 . V_8 = F_18 ( V_29 ) -> V_33 ;
break;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
V_14 . V_7 . V_11 = F_19 ( V_29 ) -> V_33 ;
break;
#endif
default:
return NULL ;
}
return F_12 ( V_13 , & V_14 ) ;
}
static void F_20 ( struct V_34 * V_35 )
{
struct V_12 * V_13 =
F_21 ( V_35 , struct V_12 , V_36 ) ;
struct V_12 * V_37 = V_13 -> V_37 ;
V_13 -> V_37 = NULL ;
F_22 ( V_37 -> V_38 ) ;
F_22 ( V_37 ) ;
}
static int F_23 ( struct V_12 * V_39 ,
struct V_12 * V_37 ,
int V_40 )
{
struct V_20 * V_23 ;
int V_41 ;
int V_42 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_37 -> V_18 ; V_43 ++ )
F_24 (mp, &old->mhash[i], hlist[old->ver])
F_25 ( & V_23 -> V_44 [ V_39 -> V_45 ] ,
& V_39 -> V_38 [ F_9 ( V_39 , & V_23 -> V_24 ) ] ) ;
if ( ! V_40 )
return 0 ;
V_41 = 0 ;
for ( V_43 = 0 ; V_43 < V_39 -> V_18 ; V_43 ++ ) {
V_42 = 0 ;
F_24 (mp, &new->mhash[i], hlist[new->ver])
V_42 ++ ;
if ( V_42 > V_41 )
V_41 = V_42 ;
}
return V_41 > V_40 ? - V_46 : 0 ;
}
void F_26 ( struct V_34 * V_35 )
{
struct V_47 * V_48 =
F_21 ( V_35 , struct V_47 , V_36 ) ;
F_22 ( V_48 ) ;
}
static void F_27 ( struct V_34 * V_35 )
{
struct V_20 * V_23 =
F_21 ( V_35 , struct V_20 , V_36 ) ;
F_22 ( V_23 ) ;
}
static void F_28 ( unsigned long V_49 )
{
struct V_20 * V_23 = ( void * ) V_49 ;
struct V_26 * V_27 = V_23 -> V_27 ;
struct V_12 * V_13 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || F_31 ( & V_23 -> V_52 ) )
goto V_53;
V_23 -> V_54 = false ;
if ( V_23 -> V_55 )
goto V_53;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
F_33 ( & V_23 -> V_44 [ V_13 -> V_45 ] ) ;
V_13 -> V_56 -- ;
F_34 ( & V_23 -> V_36 , F_27 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_36 ( struct V_26 * V_27 ,
struct V_47 * V_57 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
V_23 = F_12 ( V_13 , & V_57 -> V_24 ) ;
if ( F_37 ( ! V_23 ) )
return;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 != V_57 )
continue;
F_38 ( * V_58 , V_48 -> V_59 ) ;
F_39 ( & V_48 -> V_54 ) ;
F_40 ( & V_48 -> V_52 ) ;
F_34 ( & V_48 -> V_36 , F_26 ) ;
if ( ! V_23 -> V_55 && ! V_23 -> V_54 &&
F_30 ( V_27 -> V_51 ) )
F_41 ( & V_23 -> V_52 , V_60 ) ;
return;
}
F_37 ( 1 ) ;
}
static void F_42 ( unsigned long V_49 )
{
struct V_47 * V_57 = ( void * ) V_49 ;
struct V_26 * V_27 = V_57 -> V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || F_31 ( & V_57 -> V_52 ) ||
F_43 ( & V_57 -> V_54 ) || V_57 -> V_62 & V_63 )
goto V_53;
F_36 ( V_27 , V_57 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static int F_44 ( struct V_12 T_4 * * V_64 , int V_18 ,
int V_40 )
{
struct V_12 * V_37 = F_45 ( * V_64 , 1 ) ;
struct V_12 * V_13 ;
int V_65 ;
V_13 = F_46 ( sizeof( * V_13 ) , V_66 ) ;
if ( ! V_13 )
return - V_67 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_37 = V_37 ;
V_13 -> V_38 = F_47 ( V_18 * sizeof( * V_13 -> V_38 ) , V_66 ) ;
if ( ! V_13 -> V_38 ) {
F_22 ( V_13 ) ;
return - V_67 ;
}
V_13 -> V_56 = V_37 ? V_37 -> V_56 : 0 ;
V_13 -> V_45 = V_37 ? V_37 -> V_45 ^ 1 : 0 ;
if ( ! V_37 || V_40 )
F_48 ( & V_13 -> V_17 , sizeof( V_13 -> V_17 ) ) ;
else
V_13 -> V_17 = V_37 -> V_17 ;
if ( ! V_37 )
goto V_53;
V_65 = F_23 ( V_13 , V_37 , V_40 ) ;
if ( V_65 ) {
F_22 ( V_13 -> V_38 ) ;
F_22 ( V_13 ) ;
return V_65 ;
}
V_68 ++ ;
F_34 ( & V_13 -> V_36 , F_20 ) ;
V_53:
F_38 ( * V_64 , V_13 ) ;
return 0 ;
}
static struct V_28 * F_49 ( struct V_26 * V_27 ,
T_1 V_69 )
{
struct V_28 * V_29 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
V_29 = F_50 ( V_27 -> V_51 , sizeof( * V_73 ) + sizeof( * V_75 ) +
sizeof( * V_71 ) + 4 ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_6 ) ;
F_51 ( V_29 ) ;
V_73 = F_52 ( V_29 ) ;
memcpy ( V_73 -> V_76 , V_27 -> V_51 -> V_77 , 6 ) ;
V_73 -> V_78 [ 0 ] = 1 ;
V_73 -> V_78 [ 1 ] = 0 ;
V_73 -> V_78 [ 2 ] = 0x5e ;
V_73 -> V_78 [ 3 ] = 0 ;
V_73 -> V_78 [ 4 ] = 0 ;
V_73 -> V_78 [ 5 ] = 1 ;
V_73 -> V_79 = F_2 ( V_6 ) ;
F_53 ( V_29 , sizeof( * V_73 ) ) ;
F_54 ( V_29 , V_29 -> V_42 ) ;
V_75 = F_18 ( V_29 ) ;
V_75 -> V_80 = 4 ;
V_75 -> V_81 = 6 ;
V_75 -> V_82 = 0xc0 ;
V_75 -> V_83 = F_2 ( sizeof( * V_75 ) + sizeof( * V_71 ) + 4 ) ;
V_75 -> V_84 = 0 ;
V_75 -> V_85 = F_2 ( V_86 ) ;
V_75 -> V_87 = 1 ;
V_75 -> V_32 = V_88 ;
V_75 -> V_89 = 0 ;
V_75 -> V_33 = F_55 ( V_90 ) ;
( ( V_91 * ) & V_75 [ 1 ] ) [ 0 ] = V_92 ;
( ( V_91 * ) & V_75 [ 1 ] ) [ 1 ] = 4 ;
( ( V_91 * ) & V_75 [ 1 ] ) [ 2 ] = 0 ;
( ( V_91 * ) & V_75 [ 1 ] ) [ 3 ] = 0 ;
F_56 ( V_75 ) ;
F_53 ( V_29 , 24 ) ;
F_57 ( V_29 , V_29 -> V_42 ) ;
V_71 = F_58 ( V_29 ) ;
V_71 -> type = V_93 ;
V_71 -> V_94 = ( V_69 ? V_27 -> V_95 :
V_27 -> V_96 ) /
( V_97 / V_98 ) ;
V_71 -> V_69 = V_69 ;
V_71 -> V_99 = 0 ;
V_71 -> V_99 = F_59 ( ( void * ) V_71 , sizeof( struct V_70 ) ) ;
F_53 ( V_29 , sizeof( * V_71 ) ) ;
F_60 ( V_29 , sizeof( * V_73 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_61 ( struct V_26 * V_27 ,
const struct V_19 * V_69 )
{
struct V_28 * V_29 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
struct V_72 * V_73 ;
V_91 * V_104 ;
unsigned long V_105 ;
V_29 = F_50 ( V_27 -> V_51 , sizeof( * V_73 ) + sizeof( * V_101 ) +
8 + sizeof( * V_103 ) ) ;
if ( ! V_29 )
goto V_53;
V_29 -> V_32 = F_2 ( V_10 ) ;
F_51 ( V_29 ) ;
V_73 = F_52 ( V_29 ) ;
memcpy ( V_73 -> V_76 , V_27 -> V_51 -> V_77 , 6 ) ;
V_73 -> V_79 = F_2 ( V_10 ) ;
F_53 ( V_29 , sizeof( * V_73 ) ) ;
F_54 ( V_29 , V_29 -> V_42 ) ;
V_101 = F_19 ( V_29 ) ;
* ( V_15 T_1 * ) V_101 = F_55 ( 0x60000000 ) ;
V_101 -> V_106 = F_2 ( 8 + sizeof( * V_103 ) ) ;
V_101 -> V_107 = V_108 ;
V_101 -> V_109 = 1 ;
F_62 ( & V_101 -> V_33 , F_55 ( 0xff020000 ) , 0 , 0 , F_55 ( 1 ) ) ;
if ( F_63 ( F_64 ( V_27 -> V_51 ) , V_27 -> V_51 , & V_101 -> V_33 , 0 ,
& V_101 -> V_89 ) ) {
F_65 ( V_29 ) ;
return NULL ;
}
F_66 ( & V_101 -> V_33 , V_73 -> V_78 ) ;
V_104 = ( V_91 * ) ( V_101 + 1 ) ;
V_104 [ 0 ] = V_110 ;
V_104 [ 1 ] = 0 ;
V_104 [ 2 ] = V_111 ;
V_104 [ 3 ] = 2 ;
V_104 [ 4 ] = 0 ;
V_104 [ 5 ] = 0 ;
V_104 [ 6 ] = V_112 ;
V_104 [ 7 ] = V_112 ;
F_53 ( V_29 , sizeof( * V_101 ) + 8 ) ;
F_57 ( V_29 , V_29 -> V_42 ) ;
V_103 = (struct V_102 * ) F_67 ( V_29 ) ;
V_105 = F_68 ( V_69 ) ?
V_27 -> V_96 :
V_27 -> V_95 ;
V_103 -> V_113 = V_114 ;
V_103 -> V_115 = 0 ;
V_103 -> V_116 = 0 ;
V_103 -> V_117 = F_2 ( ( T_3 ) F_69 ( V_105 ) ) ;
V_103 -> V_118 = 0 ;
V_103 -> V_119 = * V_69 ;
V_103 -> V_116 = F_70 ( & V_101 -> V_89 , & V_101 -> V_33 ,
sizeof( * V_103 ) , V_110 ,
F_71 ( V_103 ,
sizeof( * V_103 ) , 0 ) ) ;
F_53 ( V_29 , sizeof( * V_103 ) ) ;
F_60 ( V_29 , sizeof( * V_73 ) ) ;
V_53:
return V_29 ;
}
static struct V_28 * F_72 ( struct V_26 * V_27 ,
struct V_1 * V_24 )
{
switch ( V_24 -> V_4 ) {
case F_2 ( V_6 ) :
return F_49 ( V_27 , V_24 -> V_7 . V_8 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_61 ( V_27 , & V_24 -> V_7 . V_11 ) ;
#endif
}
return NULL ;
}
static struct V_20 * F_73 (
struct V_26 * V_27 , struct V_120 * V_61 ,
struct V_1 * V_69 , int V_22 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
unsigned int V_121 = 0 ;
unsigned int V_18 ;
int V_40 ;
int V_65 ;
V_13 = F_45 ( V_27 -> V_13 , 1 ) ;
F_24 (mp, &mdb->mhash[hash], hlist[mdb->ver]) {
V_121 ++ ;
if ( F_74 ( F_1 ( V_69 , & V_23 -> V_24 ) ) )
return V_23 ;
}
V_40 = 0 ;
V_18 = V_13 -> V_18 ;
if ( F_74 ( V_121 > V_27 -> V_122 && V_121 ) ) {
if ( F_75 () )
F_76 ( V_27 , L_1
L_2 ,
V_61 ? V_61 -> V_51 -> V_123 : V_27 -> V_51 -> V_123 ) ;
V_40 = V_27 -> V_122 ;
}
if ( V_13 -> V_56 >= V_18 ) {
V_18 *= 2 ;
if ( F_74 ( V_18 > V_27 -> V_124 ) ) {
F_77 ( V_27 , L_3
L_4 ,
V_27 -> V_124 ,
V_61 ? V_61 -> V_51 -> V_123 : V_27 -> V_51 -> V_123 ) ;
V_65 = - V_125 ;
V_126:
V_27 -> V_30 = 1 ;
goto V_65;
}
}
if ( V_18 > V_13 -> V_18 || V_40 ) {
if ( V_13 -> V_37 ) {
if ( F_75 () )
F_76 ( V_27 , L_1
L_5 ,
V_61 ? V_61 -> V_51 -> V_123 : V_27 -> V_51 -> V_123 ) ;
V_65 = - V_127 ;
goto V_65;
}
V_65 = F_44 ( & V_27 -> V_13 , V_18 , V_40 ) ;
if ( V_65 ) {
F_77 ( V_27 , L_6
L_7 ,
V_61 ? V_61 -> V_51 -> V_123 : V_27 -> V_51 -> V_123 ,
V_13 -> V_56 , V_65 ) ;
goto V_126;
}
V_65 = - V_128 ;
goto V_65;
}
return NULL ;
V_65:
V_23 = F_78 ( V_65 ) ;
return V_23 ;
}
struct V_20 * F_79 ( struct V_26 * V_27 ,
struct V_120 * V_61 , struct V_1 * V_69 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
int V_22 ;
int V_65 ;
V_13 = F_45 ( V_27 -> V_13 , 1 ) ;
if ( ! V_13 ) {
V_65 = F_44 ( & V_27 -> V_13 , V_129 , 0 ) ;
if ( V_65 )
return F_78 ( V_65 ) ;
goto V_130;
}
V_22 = F_9 ( V_13 , V_69 ) ;
V_23 = F_73 ( V_27 , V_61 , V_69 , V_22 ) ;
switch ( F_80 ( V_23 ) ) {
case 0 :
break;
case - V_128 :
V_130:
V_13 = F_45 ( V_27 -> V_13 , 1 ) ;
V_22 = F_9 ( V_13 , V_69 ) ;
break;
default:
goto V_53;
}
V_23 = F_47 ( sizeof( * V_23 ) , V_66 ) ;
if ( F_74 ( ! V_23 ) )
return F_78 ( - V_67 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_24 = * V_69 ;
F_81 ( & V_23 -> V_52 , F_28 ,
( unsigned long ) V_23 ) ;
F_82 ( & V_23 -> V_44 [ V_13 -> V_45 ] , & V_13 -> V_38 [ V_22 ] ) ;
V_13 -> V_56 ++ ;
V_53:
return V_23 ;
}
struct V_47 * F_83 (
struct V_120 * V_61 ,
struct V_1 * V_69 ,
struct V_47 T_4 * V_59 ,
unsigned char V_62 )
{
struct V_47 * V_48 ;
V_48 = F_47 ( sizeof( * V_48 ) , V_66 ) ;
if ( F_74 ( ! V_48 ) )
return NULL ;
V_48 -> V_24 = * V_69 ;
V_48 -> V_61 = V_61 ;
V_48 -> V_62 = V_62 ;
F_38 ( V_48 -> V_59 , V_59 ) ;
F_25 ( & V_48 -> V_54 , & V_61 -> V_54 ) ;
F_81 ( & V_48 -> V_52 , F_42 ,
( unsigned long ) V_48 ) ;
return V_48 ;
}
static int F_84 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
struct V_1 * V_69 )
{
struct V_20 * V_23 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_131 = V_60 ;
int V_65 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_132 ) )
goto V_53;
V_23 = F_79 ( V_27 , V_61 , V_69 ) ;
V_65 = F_80 ( V_23 ) ;
if ( F_85 ( V_23 ) )
goto V_65;
if ( ! V_61 ) {
V_23 -> V_54 = true ;
F_41 ( & V_23 -> V_52 , V_131 + V_27 -> V_133 ) ;
goto V_53;
}
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 -> V_61 == V_61 )
goto V_134;
if ( ( unsigned long ) V_48 -> V_61 < ( unsigned long ) V_61 )
break;
}
V_48 = F_83 ( V_61 , V_69 , * V_58 , V_135 ) ;
if ( F_74 ( ! V_48 ) )
goto V_65;
F_38 ( * V_58 , V_48 ) ;
F_86 ( V_27 -> V_51 , V_61 , V_69 , V_136 ) ;
V_134:
F_41 ( & V_48 -> V_52 , V_131 + V_27 -> V_133 ) ;
V_53:
V_65 = 0 ;
V_65:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static int F_87 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
T_1 V_69 ,
T_2 V_5 )
{
struct V_1 V_137 ;
if ( F_88 ( V_69 ) )
return 0 ;
V_137 . V_7 . V_8 = V_69 ;
V_137 . V_4 = F_2 ( V_6 ) ;
V_137 . V_5 = V_5 ;
return F_84 ( V_27 , V_61 , & V_137 ) ;
}
static int F_89 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
const struct V_19 * V_69 ,
T_2 V_5 )
{
struct V_1 V_137 ;
if ( ! F_90 ( V_69 ) )
return 0 ;
V_137 . V_7 . V_11 = * V_69 ;
V_137 . V_4 = F_2 ( V_10 ) ;
V_137 . V_5 = V_5 ;
return F_84 ( V_27 , V_61 , & V_137 ) ;
}
static void F_91 ( unsigned long V_49 )
{
struct V_120 * V_61 = ( void * ) V_49 ;
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_61 -> V_138 != 1 ||
F_31 ( & V_61 -> V_139 ) ||
F_43 ( & V_61 -> V_140 ) )
goto V_53;
F_92 ( & V_61 -> V_140 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_93 ( unsigned long V_49 )
{
}
static void F_94 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 )
goto V_53;
F_95 ( V_27 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_96 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
struct V_1 * V_14 )
{
struct V_28 * V_29 ;
V_29 = F_72 ( V_27 , V_14 ) ;
if ( ! V_29 )
return;
if ( V_61 ) {
F_97 ( V_29 , sizeof( struct V_72 ) ) ;
V_29 -> V_51 = V_61 -> V_51 ;
F_98 ( V_141 , V_142 , V_29 , NULL , V_29 -> V_51 ,
V_143 ) ;
} else
F_99 ( V_29 ) ;
}
static void F_100 ( struct V_26 * V_27 ,
struct V_120 * V_61 , V_16 V_144 )
{
unsigned long time ;
struct V_1 V_137 ;
if ( ! F_30 ( V_27 -> V_51 ) || V_27 -> V_30 ||
! V_27 -> V_145 ||
F_31 ( & V_27 -> V_146 ) )
return;
memset ( & V_137 . V_7 , 0 , sizeof( V_137 . V_7 ) ) ;
V_137 . V_4 = F_2 ( V_6 ) ;
F_96 ( V_27 , V_61 , & V_137 ) ;
#if F_3 ( V_9 )
V_137 . V_4 = F_2 ( V_10 ) ;
F_96 ( V_27 , V_61 , & V_137 ) ;
#endif
time = V_60 ;
time += V_144 < V_27 -> V_147 ?
V_27 -> V_148 :
V_27 -> V_149 ;
F_41 ( V_61 ? & V_61 -> V_150 :
& V_27 -> V_150 , time ) ;
}
static void F_101 ( unsigned long V_49 )
{
struct V_120 * V_61 = ( void * ) V_49 ;
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_61 -> V_62 == V_132 ||
V_61 -> V_62 == V_151 )
goto V_53;
if ( V_61 -> V_152 <
V_27 -> V_147 )
V_61 -> V_152 ++ ;
F_100 ( V_61 -> V_27 , V_61 ,
V_61 -> V_152 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
void F_102 ( struct V_120 * V_61 )
{
V_61 -> V_138 = 1 ;
F_81 ( & V_61 -> V_139 , F_91 ,
( unsigned long ) V_61 ) ;
F_81 ( & V_61 -> V_150 ,
F_101 , ( unsigned long ) V_61 ) ;
}
void F_103 ( struct V_120 * V_61 )
{
F_104 ( & V_61 -> V_139 ) ;
}
static void F_105 ( struct V_120 * V_61 )
{
V_61 -> V_152 = 0 ;
if ( F_106 ( & V_61 -> V_150 ) >= 0 ||
F_40 ( & V_61 -> V_150 ) )
F_41 ( & V_61 -> V_150 , V_60 ) ;
}
void F_107 ( struct V_120 * V_61 )
{
struct V_26 * V_27 = V_61 -> V_27 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 || ! F_30 ( V_27 -> V_51 ) )
goto V_53;
F_105 ( V_61 ) ;
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
void F_108 ( struct V_120 * V_61 )
{
struct V_26 * V_27 = V_61 -> V_27 ;
struct V_47 * V_57 ;
struct V_153 * V_154 ;
F_29 ( & V_27 -> V_50 ) ;
F_109 (pg, n, &port->mglist, mglist)
F_36 ( V_27 , V_57 ) ;
if ( ! F_43 ( & V_61 -> V_140 ) )
F_92 ( & V_61 -> V_140 ) ;
F_40 ( & V_61 -> V_139 ) ;
F_40 ( & V_61 -> V_150 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
static int F_110 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
struct V_28 * V_29 )
{
struct V_155 * V_71 ;
struct V_156 * V_157 ;
int V_43 ;
int V_42 ;
int V_158 ;
int type ;
int V_65 = 0 ;
T_1 V_69 ;
T_3 V_5 = 0 ;
if ( ! F_111 ( V_29 , sizeof( * V_71 ) ) )
return - V_46 ;
F_112 ( V_29 , & V_5 ) ;
V_71 = F_113 ( V_29 ) ;
V_158 = F_114 ( V_71 -> V_159 ) ;
V_42 = sizeof( * V_71 ) ;
for ( V_43 = 0 ; V_43 < V_158 ; V_43 ++ ) {
V_42 += sizeof( * V_157 ) ;
if ( ! F_111 ( V_29 , V_42 ) )
return - V_46 ;
V_157 = ( void * ) ( V_29 -> V_49 + V_42 - sizeof( * V_157 ) ) ;
V_69 = V_157 -> V_160 ;
type = V_157 -> V_161 ;
V_42 += F_114 ( V_157 -> V_162 ) * 4 ;
if ( ! F_111 ( V_29 , V_42 ) )
return - V_46 ;
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
V_65 = F_87 ( V_27 , V_61 , V_69 , V_5 ) ;
if ( V_65 )
break;
}
return V_65 ;
}
static int F_115 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
struct V_28 * V_29 )
{
struct V_169 * V_170 ;
struct V_171 * V_157 ;
int V_43 ;
int V_42 ;
int V_158 ;
int V_65 = 0 ;
T_3 V_5 = 0 ;
if ( ! F_111 ( V_29 , sizeof( * V_170 ) ) )
return - V_46 ;
F_112 ( V_29 , & V_5 ) ;
V_170 = F_67 ( V_29 ) ;
V_158 = F_114 ( V_170 -> V_172 . V_173 [ 1 ] ) ;
V_42 = sizeof( * V_170 ) ;
for ( V_43 = 0 ; V_43 < V_158 ; V_43 ++ ) {
T_5 * V_174 , V_175 ;
V_174 = F_116 ( V_29 ,
V_42 + F_117 ( struct V_171 ,
V_162 ) ,
sizeof( V_175 ) , & V_175 ) ;
if ( ! V_174 )
return - V_46 ;
if ( ! F_111 ( V_29 ,
V_42 + sizeof( * V_157 ) +
sizeof( struct V_19 ) * F_114 ( * V_174 ) ) )
return - V_46 ;
V_157 = (struct V_171 * ) ( V_29 -> V_49 + V_42 ) ;
V_42 += sizeof( * V_157 ) +
sizeof( struct V_19 ) * F_114 ( * V_174 ) ;
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
V_65 = F_89 ( V_27 , V_61 , & V_157 -> V_160 ,
V_5 ) ;
if ( ! V_65 )
break;
}
return V_65 ;
}
static void F_118 ( struct V_26 * V_27 ,
struct V_120 * V_61 )
{
struct V_120 * V_48 ;
struct V_153 * V_182 = NULL ;
F_24 (p, &br->router_list, rlist) {
if ( ( unsigned long ) V_61 >= ( unsigned long ) V_48 )
break;
V_182 = & V_48 -> V_140 ;
}
if ( V_182 )
F_119 ( V_182 , & V_61 -> V_140 ) ;
else
F_82 ( & V_61 -> V_140 , & V_27 -> V_183 ) ;
}
static void F_120 ( struct V_26 * V_27 ,
struct V_120 * V_61 )
{
unsigned long V_131 = V_60 ;
if ( ! V_61 ) {
if ( V_27 -> V_138 == 1 )
F_41 ( & V_27 -> V_139 ,
V_131 + V_27 -> V_184 ) ;
return;
}
if ( V_61 -> V_138 != 1 )
return;
if ( ! F_43 ( & V_61 -> V_140 ) )
goto V_52;
F_118 ( V_27 , V_61 ) ;
V_52:
F_41 ( & V_61 -> V_139 ,
V_131 + V_27 -> V_184 ) ;
}
static void F_121 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
int V_89 )
{
if ( V_89 )
F_41 ( & V_27 -> V_146 ,
V_60 + V_27 -> V_184 ) ;
else if ( F_31 ( & V_27 -> V_146 ) )
return;
F_120 ( V_27 , V_61 ) ;
}
static int F_122 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
struct V_28 * V_29 )
{
const struct V_74 * V_75 = F_18 ( V_29 ) ;
struct V_70 * V_71 = F_58 ( V_29 ) ;
struct V_20 * V_23 ;
struct V_185 * V_186 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_187 ;
unsigned long V_131 = V_60 ;
T_1 V_69 ;
int V_65 = 0 ;
T_3 V_5 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_132 ) )
goto V_53;
F_121 ( V_27 , V_61 , ! ! V_75 -> V_89 ) ;
V_69 = V_71 -> V_69 ;
if ( V_29 -> V_42 == sizeof( * V_71 ) ) {
V_187 = V_71 -> V_94 * ( V_97 / V_98 ) ;
if ( ! V_187 ) {
V_187 = 10 * V_97 ;
V_69 = 0 ;
}
} else {
if ( ! F_111 ( V_29 , sizeof( struct V_185 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_186 = F_123 ( V_29 ) ;
if ( V_186 -> V_174 )
goto V_53;
V_187 = V_186 -> V_94 ?
F_124 ( V_186 -> V_94 ) * ( V_97 / V_98 ) : 1 ;
}
if ( ! V_69 )
goto V_53;
F_112 ( V_29 , & V_5 ) ;
V_23 = F_13 ( F_32 ( V_27 -> V_13 , V_27 ) , V_69 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_187 *= V_27 -> V_188 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_125 ( V_23 -> V_52 . V_189 , V_131 + V_187 ) :
F_106 ( & V_23 -> V_52 ) >= 0 ) )
F_41 ( & V_23 -> V_52 , V_131 + V_187 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_125 ( V_48 -> V_52 . V_189 , V_131 + V_187 ) :
F_106 ( & V_48 -> V_52 ) >= 0 )
F_41 ( & V_48 -> V_52 , V_131 + V_187 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static int F_126 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
struct V_28 * V_29 )
{
const struct V_100 * V_101 = F_19 ( V_29 ) ;
struct V_102 * V_190 ;
struct V_20 * V_23 ;
struct V_191 * V_192 ;
struct V_47 * V_48 ;
struct V_47 T_4 * * V_58 ;
unsigned long V_187 ;
unsigned long V_131 = V_60 ;
const struct V_19 * V_69 = NULL ;
int V_65 = 0 ;
T_3 V_5 = 0 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_132 ) )
goto V_53;
F_121 ( V_27 , V_61 , ! F_68 ( & V_101 -> V_89 ) ) ;
if ( V_29 -> V_42 == sizeof( * V_190 ) ) {
if ( ! F_111 ( V_29 , sizeof( * V_190 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_190 = (struct V_102 * ) F_67 ( V_29 ) ;
V_187 = F_127 ( F_114 ( V_190 -> V_117 ) ) ;
if ( V_187 )
V_69 = & V_190 -> V_119 ;
} else if ( V_29 -> V_42 >= sizeof( * V_192 ) ) {
if ( ! F_111 ( V_29 , sizeof( * V_192 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_192 = (struct V_191 * ) F_67 ( V_29 ) ;
if ( ! V_192 -> V_193 )
V_69 = & V_192 -> V_194 ;
V_187 = V_192 -> V_195 ? F_128 ( F_114 ( V_192 -> V_195 ) ) : 1 ;
}
if ( ! V_69 )
goto V_53;
F_112 ( V_29 , & V_5 ) ;
V_23 = F_14 ( F_32 ( V_27 -> V_13 , V_27 ) , V_69 , V_5 ) ;
if ( ! V_23 )
goto V_53;
V_187 *= V_27 -> V_188 ;
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_125 ( V_23 -> V_52 . V_189 , V_131 + V_187 ) :
F_106 ( & V_23 -> V_52 ) >= 0 ) )
F_41 ( & V_23 -> V_52 , V_131 + V_187 ) ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( F_31 ( & V_48 -> V_52 ) ?
F_125 ( V_48 -> V_52 . V_189 , V_131 + V_187 ) :
F_106 ( & V_48 -> V_52 ) >= 0 )
F_41 ( & V_48 -> V_52 , V_131 + V_187 ) ;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static void F_129 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
struct V_1 * V_69 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_47 * V_48 ;
unsigned long V_131 ;
unsigned long time ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) ||
( V_61 && V_61 -> V_62 == V_132 ) ||
F_31 ( & V_27 -> V_146 ) )
goto V_53;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
V_23 = F_12 ( V_13 , V_69 ) ;
if ( ! V_23 )
goto V_53;
if ( V_61 && ( V_61 -> V_196 & V_197 ) ) {
struct V_47 T_4 * * V_58 ;
for ( V_58 = & V_23 -> V_55 ;
( V_48 = F_32 ( * V_58 , V_27 ) ) != NULL ;
V_58 = & V_48 -> V_59 ) {
if ( V_48 -> V_61 != V_61 )
continue;
F_38 ( * V_58 , V_48 -> V_59 ) ;
F_39 ( & V_48 -> V_54 ) ;
F_40 ( & V_48 -> V_52 ) ;
F_34 ( & V_48 -> V_36 , F_26 ) ;
F_86 ( V_27 -> V_51 , V_61 , V_69 , V_198 ) ;
if ( ! V_23 -> V_55 && ! V_23 -> V_54 &&
F_30 ( V_27 -> V_51 ) )
F_41 ( & V_23 -> V_52 , V_60 ) ;
}
goto V_53;
}
V_131 = V_60 ;
time = V_131 + V_27 -> V_188 *
V_27 -> V_95 ;
if ( ! V_61 ) {
if ( V_23 -> V_54 &&
( F_31 ( & V_23 -> V_52 ) ?
F_125 ( V_23 -> V_52 . V_189 , time ) :
F_106 ( & V_23 -> V_52 ) >= 0 ) ) {
F_41 ( & V_23 -> V_52 , time ) ;
}
goto V_53;
}
for ( V_48 = F_32 ( V_23 -> V_55 , V_27 ) ;
V_48 != NULL ;
V_48 = F_32 ( V_48 -> V_59 , V_27 ) ) {
if ( V_48 -> V_61 != V_61 )
continue;
if ( ! F_43 ( & V_48 -> V_54 ) &&
( F_31 ( & V_48 -> V_52 ) ?
F_125 ( V_48 -> V_52 . V_189 , time ) :
F_106 ( & V_48 -> V_52 ) >= 0 ) ) {
F_41 ( & V_48 -> V_52 , time ) ;
}
break;
}
V_53:
F_35 ( & V_27 -> V_50 ) ;
}
static void F_130 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
T_1 V_69 ,
T_2 V_5 )
{
struct V_1 V_137 ;
if ( F_88 ( V_69 ) )
return;
V_137 . V_7 . V_8 = V_69 ;
V_137 . V_4 = F_2 ( V_6 ) ;
V_137 . V_5 = V_5 ;
F_129 ( V_27 , V_61 , & V_137 ) ;
}
static void F_131 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
const struct V_19 * V_69 ,
T_2 V_5 )
{
struct V_1 V_137 ;
if ( ! F_90 ( V_69 ) )
return;
V_137 . V_7 . V_11 = * V_69 ;
V_137 . V_4 = F_2 ( V_10 ) ;
V_137 . V_5 = V_5 ;
F_129 ( V_27 , V_61 , & V_137 ) ;
}
static int F_132 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
struct V_28 * V_29 )
{
struct V_28 * V_199 = V_29 ;
const struct V_74 * V_75 ;
struct V_70 * V_71 ;
unsigned int V_42 ;
unsigned int V_200 ;
int V_65 ;
T_3 V_5 = 0 ;
if ( ! F_111 ( V_29 , sizeof( * V_75 ) ) )
return - V_46 ;
V_75 = F_18 ( V_29 ) ;
if ( V_75 -> V_81 < 5 || V_75 -> V_80 != 4 )
return - V_46 ;
if ( ! F_111 ( V_29 , F_133 ( V_29 ) ) )
return - V_46 ;
V_75 = F_18 ( V_29 ) ;
if ( F_74 ( F_134 ( ( V_91 * ) V_75 , V_75 -> V_81 ) ) )
return - V_46 ;
if ( V_75 -> V_32 != V_88 ) {
if ( ! F_88 ( V_75 -> V_33 ) )
F_17 ( V_29 ) -> V_201 = 1 ;
return 0 ;
}
V_42 = F_114 ( V_75 -> V_83 ) ;
if ( V_29 -> V_42 < V_42 || V_42 < F_133 ( V_29 ) )
return - V_46 ;
if ( V_29 -> V_42 > V_42 ) {
V_199 = F_135 ( V_29 , V_66 ) ;
if ( ! V_199 )
return - V_67 ;
V_65 = F_136 ( V_199 , V_42 ) ;
if ( V_65 )
goto V_202;
}
V_42 -= F_133 ( V_199 ) ;
V_200 = F_137 ( V_199 ) + F_133 ( V_199 ) ;
F_60 ( V_199 , V_200 ) ;
F_138 ( V_199 ) ;
V_65 = - V_46 ;
if ( ! F_111 ( V_199 , sizeof( * V_71 ) ) )
goto V_53;
switch ( V_199 -> V_203 ) {
case V_204 :
if ( ! F_139 ( V_199 -> V_99 ) )
break;
case V_205 :
V_199 -> V_99 = 0 ;
if ( F_140 ( V_199 ) )
goto V_53;
}
V_65 = 0 ;
F_112 ( V_199 , & V_5 ) ;
F_17 ( V_29 ) -> V_31 = 1 ;
V_71 = F_58 ( V_199 ) ;
switch ( V_71 -> type ) {
case V_206 :
case V_207 :
F_17 ( V_29 ) -> V_201 = 1 ;
V_65 = F_87 ( V_27 , V_61 , V_71 -> V_69 , V_5 ) ;
break;
case V_208 :
V_65 = F_110 ( V_27 , V_61 , V_199 ) ;
break;
case V_93 :
V_65 = F_122 ( V_27 , V_61 , V_199 ) ;
break;
case V_209 :
F_130 ( V_27 , V_61 , V_71 -> V_69 , V_5 ) ;
break;
}
V_53:
F_97 ( V_199 , V_200 ) ;
V_202:
if ( V_199 != V_29 )
F_65 ( V_199 ) ;
return V_65 ;
}
static int F_141 ( struct V_26 * V_27 ,
struct V_120 * V_61 ,
struct V_28 * V_29 )
{
struct V_28 * V_199 ;
const struct V_100 * V_101 ;
V_91 V_210 ;
V_91 V_107 ;
T_5 V_85 ;
unsigned int V_42 ;
int V_200 ;
int V_65 ;
T_3 V_5 = 0 ;
if ( ! F_111 ( V_29 , sizeof( * V_101 ) ) )
return - V_46 ;
V_101 = F_19 ( V_29 ) ;
if ( V_101 -> V_80 != 6 ||
V_101 -> V_107 != V_108 ||
V_101 -> V_106 == 0 )
return 0 ;
V_42 = F_114 ( V_101 -> V_106 ) + sizeof( * V_101 ) ;
if ( V_29 -> V_42 < V_42 )
return - V_46 ;
V_107 = V_101 -> V_107 ;
V_200 = F_142 ( V_29 , sizeof( * V_101 ) , & V_107 , & V_85 ) ;
if ( V_200 < 0 || V_107 != V_110 )
return 0 ;
V_199 = F_135 ( V_29 , V_66 ) ;
if ( ! V_199 )
return - V_67 ;
V_65 = - V_46 ;
if ( ! F_111 ( V_199 , V_200 + sizeof( struct V_169 ) ) )
goto V_53;
V_42 -= V_200 - F_137 ( V_199 ) ;
F_60 ( V_199 , V_200 ) ;
F_138 ( V_199 ) ;
F_143 ( V_199 , F_144 ( V_199 ) ,
F_145 ( V_199 ) ) ;
V_210 = F_67 ( V_199 ) -> V_210 ;
switch ( V_210 ) {
case V_114 :
case V_211 :
case V_212 :
case V_213 :
break;
default:
V_65 = 0 ;
goto V_53;
}
if ( V_199 -> V_42 > V_42 ) {
V_65 = F_136 ( V_199 , V_42 ) ;
if ( V_65 )
goto V_53;
V_65 = - V_46 ;
}
V_101 = F_19 ( V_199 ) ;
switch ( V_199 -> V_203 ) {
case V_204 :
if ( ! F_70 ( & V_101 -> V_89 , & V_101 -> V_33 , V_199 -> V_42 ,
V_110 , V_199 -> V_99 ) )
break;
case V_205 :
V_199 -> V_99 = ~ F_146 ( F_70 ( & V_101 -> V_89 ,
& V_101 -> V_33 ,
V_199 -> V_42 ,
V_110 , 0 ) ) ;
if ( F_147 ( V_199 ) )
goto V_53;
}
V_65 = 0 ;
F_112 ( V_29 , & V_5 ) ;
F_17 ( V_29 ) -> V_31 = 1 ;
switch ( V_210 ) {
case V_211 :
{
struct V_102 * V_190 ;
if ( ! F_111 ( V_199 , sizeof( * V_190 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_190 = (struct V_102 * ) F_148 ( V_199 ) ;
F_17 ( V_29 ) -> V_201 = 1 ;
V_65 = F_89 ( V_27 , V_61 , & V_190 -> V_119 , V_5 ) ;
break;
}
case V_213 :
V_65 = F_115 ( V_27 , V_61 , V_199 ) ;
break;
case V_114 :
V_65 = F_126 ( V_27 , V_61 , V_199 ) ;
break;
case V_212 :
{
struct V_102 * V_190 ;
if ( ! F_111 ( V_199 , sizeof( * V_190 ) ) ) {
V_65 = - V_46 ;
goto V_53;
}
V_190 = (struct V_102 * ) F_148 ( V_199 ) ;
F_131 ( V_27 , V_61 , & V_190 -> V_119 , V_5 ) ;
}
}
V_53:
F_65 ( V_199 ) ;
return V_65 ;
}
int F_149 ( struct V_26 * V_27 , struct V_120 * V_61 ,
struct V_28 * V_29 )
{
F_17 ( V_29 ) -> V_31 = 0 ;
F_17 ( V_29 ) -> V_201 = 0 ;
if ( V_27 -> V_30 )
return 0 ;
switch ( V_29 -> V_32 ) {
case F_2 ( V_6 ) :
return F_132 ( V_27 , V_61 , V_29 ) ;
#if F_3 ( V_9 )
case F_2 ( V_10 ) :
return F_141 ( V_27 , V_61 , V_29 ) ;
#endif
}
return 0 ;
}
static void F_150 ( unsigned long V_49 )
{
struct V_26 * V_27 = ( void * ) V_49 ;
F_29 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_152 <
V_27 -> V_147 )
V_27 -> V_152 ++ ;
F_100 ( V_27 , NULL , V_27 -> V_152 ) ;
F_35 ( & V_27 -> V_50 ) ;
}
void F_151 ( struct V_26 * V_27 )
{
V_27 -> V_122 = 4 ;
V_27 -> V_124 = 512 ;
V_27 -> V_138 = 1 ;
V_27 -> V_145 = 0 ;
V_27 -> V_188 = 2 ;
V_27 -> V_147 = 2 ;
V_27 -> V_95 = V_97 ;
V_27 -> V_96 = 10 * V_97 ;
V_27 -> V_148 = 125 * V_97 / 4 ;
V_27 -> V_149 = 125 * V_97 ;
V_27 -> V_184 = 255 * V_97 ;
V_27 -> V_133 = 260 * V_97 ;
F_152 ( & V_27 -> V_50 ) ;
F_81 ( & V_27 -> V_139 ,
F_93 , 0 ) ;
F_81 ( & V_27 -> V_146 ,
F_94 , ( unsigned long ) V_27 ) ;
F_81 ( & V_27 -> V_150 , F_150 ,
( unsigned long ) V_27 ) ;
}
void F_153 ( struct V_26 * V_27 )
{
V_27 -> V_152 = 0 ;
if ( V_27 -> V_30 )
return;
F_41 ( & V_27 -> V_150 , V_60 ) ;
}
void F_154 ( struct V_26 * V_27 )
{
struct V_12 * V_13 ;
struct V_20 * V_23 ;
struct V_153 * V_154 ;
V_16 V_45 ;
int V_43 ;
F_104 ( & V_27 -> V_139 ) ;
F_104 ( & V_27 -> V_146 ) ;
F_104 ( & V_27 -> V_150 ) ;
F_155 ( & V_27 -> V_50 ) ;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( ! V_13 )
goto V_53;
V_27 -> V_13 = NULL ;
V_45 = V_13 -> V_45 ;
for ( V_43 = 0 ; V_43 < V_13 -> V_18 ; V_43 ++ ) {
F_109 (mp, n, &mdb->mhash[i],
hlist[ver]) {
F_40 ( & V_23 -> V_52 ) ;
F_34 ( & V_23 -> V_36 , F_27 ) ;
}
}
if ( V_13 -> V_37 ) {
F_156 ( & V_27 -> V_50 ) ;
F_157 () ;
F_155 ( & V_27 -> V_50 ) ;
F_37 ( V_13 -> V_37 ) ;
}
V_13 -> V_37 = V_13 ;
F_34 ( & V_13 -> V_36 , F_20 ) ;
V_53:
F_156 ( & V_27 -> V_50 ) ;
}
int F_158 ( struct V_26 * V_27 , unsigned long V_214 )
{
int V_65 = - V_215 ;
F_155 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_216;
switch ( V_214 ) {
case 0 :
case 2 :
F_40 ( & V_27 -> V_139 ) ;
case 1 :
V_27 -> V_138 = V_214 ;
V_65 = 0 ;
break;
default:
V_65 = - V_46 ;
break;
}
V_216:
F_156 ( & V_27 -> V_50 ) ;
return V_65 ;
}
int F_159 ( struct V_120 * V_48 , unsigned long V_214 )
{
struct V_26 * V_27 = V_48 -> V_27 ;
int V_65 = - V_215 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) || V_48 -> V_62 == V_132 )
goto V_216;
switch ( V_214 ) {
case 0 :
case 1 :
case 2 :
V_48 -> V_138 = V_214 ;
V_65 = 0 ;
if ( V_214 < 2 && ! F_43 ( & V_48 -> V_140 ) )
F_92 ( & V_48 -> V_140 ) ;
if ( V_214 == 1 )
break;
F_40 ( & V_48 -> V_139 ) ;
if ( V_214 == 0 )
break;
F_118 ( V_27 , V_48 ) ;
break;
default:
V_65 = - V_46 ;
break;
}
V_216:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
static void F_95 ( struct V_26 * V_27 )
{
struct V_120 * V_61 ;
F_153 ( V_27 ) ;
F_160 (port, &br->port_list, list) {
if ( V_61 -> V_62 == V_132 ||
V_61 -> V_62 == V_151 )
continue;
F_105 ( V_61 ) ;
}
}
int F_161 ( struct V_26 * V_27 , unsigned long V_214 )
{
int V_65 = 0 ;
struct V_12 * V_13 ;
F_155 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_30 == ! V_214 )
goto V_216;
V_27 -> V_30 = ! V_214 ;
if ( V_27 -> V_30 )
goto V_216;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_216;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_65 = - V_127 ;
V_217:
V_27 -> V_30 = ! ! V_214 ;
goto V_216;
}
V_65 = F_44 ( & V_27 -> V_13 , V_13 -> V_18 ,
V_27 -> V_122 ) ;
if ( V_65 )
goto V_217;
}
F_95 ( V_27 ) ;
V_216:
F_156 ( & V_27 -> V_50 ) ;
return V_65 ;
}
int F_162 ( struct V_26 * V_27 , unsigned long V_214 )
{
V_214 = ! ! V_214 ;
F_155 ( & V_27 -> V_50 ) ;
if ( V_27 -> V_145 == V_214 )
goto V_216;
V_27 -> V_145 = V_214 ;
if ( V_214 )
F_95 ( V_27 ) ;
V_216:
F_156 ( & V_27 -> V_50 ) ;
return 0 ;
}
int F_163 ( struct V_26 * V_27 , unsigned long V_214 )
{
int V_65 = - V_215 ;
V_16 V_37 ;
struct V_12 * V_13 ;
F_29 ( & V_27 -> V_50 ) ;
if ( ! F_30 ( V_27 -> V_51 ) )
goto V_216;
V_65 = - V_46 ;
if ( ! F_164 ( V_214 ) )
goto V_216;
V_13 = F_32 ( V_27 -> V_13 , V_27 ) ;
if ( V_13 && V_214 < V_13 -> V_56 )
goto V_216;
V_65 = 0 ;
V_37 = V_27 -> V_124 ;
V_27 -> V_124 = V_214 ;
if ( V_13 ) {
if ( V_13 -> V_37 ) {
V_65 = - V_127 ;
V_217:
V_27 -> V_124 = V_37 ;
goto V_216;
}
V_65 = F_44 ( & V_27 -> V_13 , V_27 -> V_124 ,
V_27 -> V_122 ) ;
if ( V_65 )
goto V_217;
}
V_216:
F_35 ( & V_27 -> V_50 ) ;
return V_65 ;
}
