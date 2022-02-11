static inline T_1 F_1 ( const void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
T_1 V_5 = 0 ;
V_5 = F_2 ( & V_4 -> V_6 , sizeof( V_4 -> V_6 ) , V_5 ) ;
V_5 = F_2 ( & V_4 -> V_7 , sizeof( V_4 -> V_7 ) , V_5 ) ;
return V_5 % V_2 ;
}
static inline T_1 F_3 ( const void * V_1 , T_1 V_2 )
{
const struct V_3 * V_4 = (struct V_3 * ) V_1 ;
T_1 V_5 = 0 ;
V_5 = F_2 ( & V_4 -> V_6 , sizeof( V_4 -> V_6 ) , V_5 ) ;
V_5 = F_2 ( & V_4 -> V_7 , sizeof( V_4 -> V_7 ) , V_5 ) ;
return V_5 % V_2 ;
}
static bool F_4 ( const struct V_8 * V_9 ,
const void * V_10 )
{
const void * V_11 = F_5 ( V_9 , struct V_12 ,
V_13 ) ;
const struct V_12 * V_14 = V_11 ;
const struct V_12 * V_15 = V_10 ;
if ( ! F_6 ( V_14 -> V_16 , V_15 -> V_16 ) )
return false ;
if ( V_14 -> V_7 != V_15 -> V_7 )
return false ;
return true ;
}
static bool F_7 ( const struct V_8 * V_9 ,
const void * V_10 )
{
const void * V_11 = F_5 ( V_9 , struct V_3 ,
V_13 ) ;
const struct V_3 * V_17 = V_11 ;
const struct V_3 * V_18 = V_10 ;
if ( ! F_6 ( V_17 -> V_6 , V_18 -> V_6 ) )
return false ;
if ( V_17 -> V_7 != V_18 -> V_7 )
return false ;
return true ;
}
static void F_8 ( struct V_19 * V_20 )
{
struct V_12 * V_21 ;
V_21 = F_5 ( V_20 , struct V_12 ,
V_22 ) ;
F_9 ( V_21 , V_23 ) ;
}
static void F_10 ( struct V_12 * V_21 )
{
F_11 ( & V_21 -> V_22 , F_8 ) ;
}
static void F_12 ( struct V_19 * V_20 )
{
struct V_3 * V_4 ;
struct V_12 * V_24 ;
V_4 = F_5 ( V_20 , struct V_3 , V_22 ) ;
F_13 ( & V_4 -> V_25 ) ;
V_24 = V_4 -> V_21 ;
V_4 -> V_21 = NULL ;
F_14 ( & V_4 -> V_25 ) ;
F_13 ( & V_24 -> V_26 ) ;
V_24 -> V_27 ^= F_15 ( 0 , V_4 -> V_6 , V_28 ) ;
F_14 ( & V_24 -> V_26 ) ;
F_10 ( V_24 ) ;
F_9 ( V_4 , V_23 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
F_11 ( & V_4 -> V_22 , F_12 ) ;
}
static struct V_3 *
F_17 ( struct V_29 * V_30 ,
struct V_3 * V_1 )
{
struct V_31 * V_5 = V_30 -> V_32 . V_33 ;
struct V_34 * V_35 ;
struct V_3 * V_4 ;
struct V_3 * V_36 = NULL ;
int V_37 ;
if ( ! V_5 )
return NULL ;
V_37 = F_1 ( V_1 , V_5 -> V_2 ) ;
V_35 = & V_5 -> V_38 [ V_37 ] ;
F_18 () ;
F_19 (claim, head, hash_entry) {
if ( ! F_7 ( & V_4 -> V_13 , V_1 ) )
continue;
if ( ! F_20 ( & V_4 -> V_22 ) )
continue;
V_36 = V_4 ;
break;
}
F_21 () ;
return V_36 ;
}
static struct V_12 *
F_22 ( struct V_29 * V_30 , T_2 * V_6 ,
unsigned short V_7 )
{
struct V_31 * V_5 = V_30 -> V_32 . V_39 ;
struct V_34 * V_35 ;
struct V_12 V_40 , * V_21 ;
struct V_12 * V_41 = NULL ;
int V_37 ;
if ( ! V_5 )
return NULL ;
F_23 ( V_40 . V_16 , V_6 ) ;
V_40 . V_7 = V_7 ;
V_37 = F_3 ( & V_40 , V_5 -> V_2 ) ;
V_35 = & V_5 -> V_38 [ V_37 ] ;
F_18 () ;
F_19 (backbone_gw, head, hash_entry) {
if ( ! F_4 ( & V_21 -> V_13 ,
& V_40 ) )
continue;
if ( ! F_20 ( & V_21 -> V_22 ) )
continue;
V_41 = V_21 ;
break;
}
F_21 () ;
return V_41 ;
}
static void
F_24 ( struct V_12 * V_21 )
{
struct V_31 * V_5 ;
struct V_8 * V_42 ;
struct V_34 * V_35 ;
struct V_3 * V_4 ;
int V_43 ;
T_3 * V_44 ;
V_5 = V_21 -> V_30 -> V_32 . V_33 ;
if ( ! V_5 )
return;
for ( V_43 = 0 ; V_43 < V_5 -> V_2 ; V_43 ++ ) {
V_35 = & V_5 -> V_38 [ V_43 ] ;
V_44 = & V_5 -> V_45 [ V_43 ] ;
F_13 ( V_44 ) ;
F_25 (claim, node_tmp,
head, hash_entry) {
if ( V_4 -> V_21 != V_21 )
continue;
F_16 ( V_4 ) ;
F_26 ( & V_4 -> V_13 ) ;
}
F_14 ( V_44 ) ;
}
F_13 ( & V_21 -> V_26 ) ;
V_21 -> V_27 = V_46 ;
F_14 ( & V_21 -> V_26 ) ;
}
static void F_27 ( struct V_29 * V_30 , T_2 * V_47 ,
unsigned short V_7 , int V_48 )
{
struct V_49 * V_50 ;
struct V_51 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
T_2 * V_56 ;
struct V_57 V_58 ;
T_4 V_59 = 0 ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 )
return;
memcpy ( & V_58 , & V_30 -> V_32 . V_60 ,
sizeof( V_58 ) ) ;
V_58 . type = V_48 ;
V_55 = V_53 -> V_55 ;
V_50 = F_29 ( V_61 , V_62 ,
V_59 ,
V_53 -> V_55 ,
V_59 ,
NULL ,
V_53 -> V_63 -> V_64 ,
( T_2 * ) & V_58 ) ;
if ( ! V_50 )
goto V_65;
V_51 = (struct V_51 * ) V_50 -> V_1 ;
V_56 = ( T_2 * ) V_51 + V_66 + sizeof( struct V_67 ) ;
switch ( V_48 ) {
case V_68 :
F_23 ( V_51 -> V_69 , V_47 ) ;
F_30 ( V_70 , V_30 ,
L_1 , V_47 ,
F_31 ( V_7 ) ) ;
break;
case V_71 :
F_23 ( V_56 , V_47 ) ;
F_30 ( V_70 , V_30 ,
L_2 , V_47 ,
F_31 ( V_7 ) ) ;
break;
case V_72 :
F_23 ( V_56 , V_47 ) ;
F_30 ( V_70 , V_30 ,
L_3 ,
V_51 -> V_69 , F_31 ( V_7 ) ) ;
break;
case V_73 :
F_23 ( V_56 , V_47 ) ;
F_23 ( V_51 -> V_74 , V_47 ) ;
F_30 ( V_70 , V_30 ,
L_4 ,
V_51 -> V_69 , V_51 -> V_74 ,
F_31 ( V_7 ) ) ;
break;
case V_75 :
F_23 ( V_51 -> V_69 , V_47 ) ;
F_30 ( V_70 , V_30 ,
L_5 ,
V_51 -> V_69 , V_51 -> V_74 ,
F_31 ( V_7 ) ) ;
break;
}
if ( V_7 & V_76 ) {
V_50 = F_32 ( V_50 , F_33 ( V_77 ) ,
V_7 & V_78 ) ;
if ( ! V_50 )
goto V_65;
}
F_34 ( V_50 ) ;
V_50 -> V_79 = F_35 ( V_50 , V_55 ) ;
F_36 ( V_30 , V_80 ) ;
F_37 ( V_30 , V_81 ,
V_50 -> V_82 + V_66 ) ;
V_55 -> V_83 = V_84 ;
F_38 ( V_50 ) ;
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
}
static void F_40 ( struct V_85 * V_86 )
{
struct V_12 * V_21 ;
struct V_29 * V_30 ;
char V_87 [ 6 ] = { '\0' } ;
V_21 = F_5 ( V_86 , struct V_12 ,
V_88 ) ;
V_30 = V_21 -> V_30 ;
F_41 ( V_30 -> V_55 ,
L_6 ,
F_31 ( V_21 -> V_7 ) ) ;
snprintf ( V_87 , sizeof( V_87 ) , L_7 ,
F_31 ( V_21 -> V_7 ) ) ;
V_87 [ sizeof( V_87 ) - 1 ] = 0 ;
F_42 ( V_30 , V_89 , V_90 ,
V_87 ) ;
F_10 ( V_21 ) ;
}
static struct V_12 *
F_43 ( struct V_29 * V_30 , T_2 * V_16 ,
unsigned short V_7 , bool V_91 )
{
struct V_12 * V_92 ;
struct V_93 * V_94 ;
int V_95 ;
V_92 = F_22 ( V_30 , V_16 , V_7 ) ;
if ( V_92 )
return V_92 ;
F_30 ( V_70 , V_30 ,
L_8 ,
V_16 , F_31 ( V_7 ) ) ;
V_92 = F_44 ( sizeof( * V_92 ) , V_96 ) ;
if ( ! V_92 )
return NULL ;
V_92 -> V_7 = V_7 ;
V_92 -> V_97 = V_84 ;
V_92 -> V_27 = V_46 ;
V_92 -> V_30 = V_30 ;
F_45 ( & V_92 -> V_26 ) ;
F_46 ( & V_92 -> V_98 , 0 ) ;
F_46 ( & V_92 -> V_99 , 0 ) ;
F_23 ( V_92 -> V_16 , V_16 ) ;
F_47 ( & V_92 -> V_88 , F_40 ) ;
F_48 ( & V_92 -> V_22 ) ;
F_49 ( & V_92 -> V_22 ) ;
V_95 = F_50 ( V_30 -> V_32 . V_39 ,
F_4 ,
F_3 , V_92 ,
& V_92 -> V_13 ) ;
if ( F_51 ( V_95 != 0 ) ) {
F_52 ( V_92 ) ;
return NULL ;
}
V_94 = F_53 ( V_30 , V_16 ) ;
if ( V_94 ) {
F_54 ( V_30 , V_94 , V_7 ,
L_9 ) ;
F_55 ( V_94 ) ;
}
if ( V_91 ) {
F_56 ( V_30 , V_92 ) ;
F_57 ( & V_92 -> V_98 ) ;
F_46 ( & V_92 -> V_99 , V_100 ) ;
F_57 ( & V_30 -> V_32 . V_101 ) ;
}
return V_92 ;
}
static void
F_58 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
unsigned short V_7 )
{
struct V_12 * V_21 ;
V_21 = F_43 ( V_30 ,
V_53 -> V_63 -> V_64 ,
V_7 , true ) ;
if ( F_51 ( ! V_21 ) )
return;
V_21 -> V_97 = V_84 ;
F_10 ( V_21 ) ;
}
static void F_59 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
unsigned short V_7 )
{
struct V_34 * V_35 ;
struct V_31 * V_5 ;
struct V_3 * V_4 ;
struct V_12 * V_21 ;
int V_43 ;
F_30 ( V_70 , V_30 ,
L_10 ) ;
V_21 = F_22 ( V_30 ,
V_53 -> V_63 -> V_64 ,
V_7 ) ;
if ( ! V_21 )
return;
V_5 = V_30 -> V_32 . V_33 ;
for ( V_43 = 0 ; V_43 < V_5 -> V_2 ; V_43 ++ ) {
V_35 = & V_5 -> V_38 [ V_43 ] ;
F_18 () ;
F_19 (claim, head, hash_entry) {
if ( V_4 -> V_21 != V_21 )
continue;
F_27 ( V_30 , V_4 -> V_6 , V_4 -> V_7 ,
V_68 ) ;
}
F_21 () ;
}
F_56 ( V_30 , V_21 ) ;
F_10 ( V_21 ) ;
}
static void F_60 ( struct V_12 * V_21 )
{
F_24 ( V_21 ) ;
F_30 ( V_70 , V_21 -> V_30 ,
L_11 , V_21 -> V_16 ) ;
F_27 ( V_21 -> V_30 , V_21 -> V_16 ,
V_21 -> V_7 , V_73 ) ;
if ( ! F_61 ( & V_21 -> V_98 ) ) {
F_57 ( & V_21 -> V_30 -> V_32 . V_101 ) ;
F_46 ( & V_21 -> V_98 , 1 ) ;
}
}
static void F_56 ( struct V_29 * V_30 ,
struct V_12 * V_21 )
{
T_2 V_47 [ V_28 ] ;
T_5 V_27 ;
memcpy ( V_47 , V_102 , 4 ) ;
F_13 ( & V_21 -> V_26 ) ;
V_27 = F_33 ( V_21 -> V_27 ) ;
F_14 ( & V_21 -> V_26 ) ;
memcpy ( & V_47 [ 4 ] , & V_27 , 2 ) ;
F_27 ( V_30 , V_47 , V_21 -> V_7 ,
V_72 ) ;
}
static void F_62 ( struct V_29 * V_30 ,
const T_2 * V_47 , const unsigned short V_7 ,
struct V_12 * V_21 )
{
struct V_12 * V_24 ;
struct V_3 * V_4 ;
struct V_3 V_103 ;
bool V_104 = false ;
int V_95 ;
F_23 ( V_103 . V_6 , V_47 ) ;
V_103 . V_7 = V_7 ;
V_4 = F_17 ( V_30 , & V_103 ) ;
if ( ! V_4 ) {
V_4 = F_44 ( sizeof( * V_4 ) , V_96 ) ;
if ( ! V_4 )
return;
F_23 ( V_4 -> V_6 , V_47 ) ;
F_45 ( & V_4 -> V_25 ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_97 = V_84 ;
F_49 ( & V_21 -> V_22 ) ;
V_4 -> V_21 = V_21 ;
F_48 ( & V_4 -> V_22 ) ;
F_30 ( V_70 , V_30 ,
L_12 ,
V_47 , F_31 ( V_7 ) ) ;
F_49 ( & V_4 -> V_22 ) ;
V_95 = F_50 ( V_30 -> V_32 . V_33 ,
F_7 ,
F_1 , V_4 ,
& V_4 -> V_13 ) ;
if ( F_51 ( V_95 != 0 ) ) {
F_52 ( V_4 ) ;
return;
}
} else {
V_4 -> V_97 = V_84 ;
if ( V_4 -> V_21 == V_21 )
goto V_105;
F_30 ( V_70 , V_30 ,
L_13 ,
V_47 , F_31 ( V_7 ) ) ;
V_104 = true ;
}
F_13 ( & V_4 -> V_25 ) ;
V_24 = V_4 -> V_21 ;
F_49 ( & V_21 -> V_22 ) ;
V_4 -> V_21 = V_21 ;
F_14 ( & V_4 -> V_25 ) ;
if ( V_104 ) {
F_13 ( & V_24 -> V_26 ) ;
V_24 -> V_27 ^= F_15 ( 0 , V_4 -> V_6 , V_28 ) ;
F_14 ( & V_24 -> V_26 ) ;
}
F_10 ( V_24 ) ;
F_13 ( & V_21 -> V_26 ) ;
V_21 -> V_27 ^= F_15 ( 0 , V_4 -> V_6 , V_28 ) ;
F_14 ( & V_21 -> V_26 ) ;
V_21 -> V_97 = V_84 ;
V_105:
F_16 ( V_4 ) ;
}
static struct V_12 *
F_63 ( struct V_3 * V_4 )
{
struct V_12 * V_21 ;
F_13 ( & V_4 -> V_25 ) ;
V_21 = V_4 -> V_21 ;
F_49 ( & V_21 -> V_22 ) ;
F_14 ( & V_4 -> V_25 ) ;
return V_21 ;
}
static void F_64 ( struct V_29 * V_30 ,
const T_2 * V_47 , const unsigned short V_7 )
{
struct V_3 V_103 , * V_4 ;
F_23 ( V_103 . V_6 , V_47 ) ;
V_103 . V_7 = V_7 ;
V_4 = F_17 ( V_30 , & V_103 ) ;
if ( ! V_4 )
return;
F_30 ( V_70 , V_30 , L_14 ,
V_47 , F_31 ( V_7 ) ) ;
F_65 ( V_30 -> V_32 . V_33 , F_7 ,
F_1 , V_4 ) ;
F_16 ( V_4 ) ;
F_16 ( V_4 ) ;
}
static bool F_66 ( struct V_29 * V_30 , T_2 * V_106 ,
T_2 * V_107 , unsigned short V_7 )
{
struct V_12 * V_21 ;
T_6 V_108 , V_27 ;
if ( memcmp ( V_106 , V_102 , 4 ) != 0 )
return false ;
V_21 = F_43 ( V_30 , V_107 , V_7 ,
false ) ;
if ( F_51 ( ! V_21 ) )
return true ;
V_21 -> V_97 = V_84 ;
V_27 = F_67 ( * ( ( T_5 * ) ( & V_106 [ 4 ] ) ) ) ;
F_30 ( V_70 , V_30 ,
L_15 ,
F_31 ( V_7 ) , V_21 -> V_16 , V_27 ) ;
F_13 ( & V_21 -> V_26 ) ;
V_108 = V_21 -> V_27 ;
F_14 ( & V_21 -> V_26 ) ;
if ( V_108 != V_27 ) {
F_30 ( V_70 , V_21 -> V_30 ,
L_16 ,
V_21 -> V_16 ,
F_31 ( V_21 -> V_7 ) ,
V_108 , V_27 ) ;
F_60 ( V_21 ) ;
} else {
if ( F_61 ( & V_21 -> V_98 ) ) {
F_68 ( & V_21 -> V_30 -> V_32 . V_101 ) ;
F_46 ( & V_21 -> V_98 , 0 ) ;
}
}
F_10 ( V_21 ) ;
return true ;
}
static bool F_69 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
T_2 * V_107 , struct V_51 * V_51 ,
unsigned short V_7 )
{
if ( ! F_6 ( V_107 , V_51 -> V_74 ) )
return false ;
if ( ! F_6 ( V_51 -> V_74 , V_53 -> V_63 -> V_64 ) )
return true ;
F_30 ( V_70 , V_30 ,
L_17 ,
F_31 ( V_7 ) , V_51 -> V_69 ) ;
F_59 ( V_30 , V_53 , V_7 ) ;
return true ;
}
static bool F_70 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
T_2 * V_107 , T_2 * V_109 ,
unsigned short V_7 )
{
struct V_12 * V_21 ;
if ( V_53 && F_6 ( V_107 ,
V_53 -> V_63 -> V_64 ) )
F_27 ( V_30 , V_109 , V_7 ,
V_71 ) ;
V_21 = F_22 ( V_30 , V_107 , V_7 ) ;
if ( ! V_21 )
return true ;
F_30 ( V_70 , V_30 ,
L_18 ,
V_109 , F_31 ( V_7 ) , V_21 -> V_16 ) ;
F_64 ( V_30 , V_109 , V_7 ) ;
F_10 ( V_21 ) ;
return true ;
}
static bool F_71 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
T_2 * V_107 , T_2 * V_109 ,
unsigned short V_7 )
{
struct V_12 * V_21 ;
V_21 = F_43 ( V_30 , V_107 , V_7 ,
false ) ;
if ( F_51 ( ! V_21 ) )
return true ;
F_62 ( V_30 , V_109 , V_7 , V_21 ) ;
if ( F_6 ( V_107 , V_53 -> V_63 -> V_64 ) )
F_27 ( V_30 , V_109 , V_7 ,
V_68 ) ;
F_10 ( V_21 ) ;
return true ;
}
static int F_72 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
T_2 * V_56 , T_2 * V_110 ,
struct V_51 * V_51 )
{
T_2 * V_107 ;
struct V_93 * V_94 ;
struct V_57 * V_111 , * V_112 ;
V_111 = (struct V_57 * ) V_110 ;
V_112 = & V_30 -> V_32 . V_60 ;
switch ( V_111 -> type ) {
case V_68 :
V_107 = V_56 ;
break;
case V_73 :
case V_72 :
case V_71 :
V_107 = V_51 -> V_69 ;
break;
default:
return 0 ;
}
if ( F_6 ( V_107 , V_53 -> V_63 -> V_64 ) )
return 0 ;
if ( V_111 -> V_113 == V_112 -> V_113 )
return 2 ;
V_94 = F_53 ( V_30 , V_107 ) ;
if ( ! V_94 )
return 1 ;
if ( F_67 ( V_111 -> V_113 ) > F_67 ( V_112 -> V_113 ) ) {
F_30 ( V_70 , V_30 ,
L_19 ,
F_67 ( V_111 -> V_113 ) ) ;
V_112 -> V_113 = V_111 -> V_113 ;
}
F_55 ( V_94 ) ;
return 2 ;
}
static bool F_73 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
struct V_49 * V_50 )
{
struct V_57 * V_111 , * V_112 ;
T_2 * V_56 , * V_110 ;
struct V_114 * V_115 , V_116 ;
struct V_51 * V_51 ;
struct V_67 * V_67 ;
unsigned short V_7 ;
int V_117 = 0 ;
T_5 V_118 ;
int V_119 ;
int V_120 ;
V_7 = F_74 ( V_50 , 0 ) ;
V_51 = F_75 ( V_50 ) ;
V_118 = V_51 -> V_121 ;
V_119 = V_66 ;
if ( V_7 & V_76 ) {
do {
V_115 = F_76 ( V_50 , V_119 , V_122 ,
& V_116 ) ;
if ( ! V_115 )
return false ;
V_118 = V_115 -> V_123 ;
V_119 += V_122 ;
V_117 ++ ;
} while ( V_118 == F_33 ( V_77 ) );
}
if ( V_118 != F_33 ( V_62 ) )
return false ;
if ( F_51 ( ! F_77 ( V_50 , V_119 + F_78 ( V_50 -> V_124 ) ) ) )
return false ;
V_51 = F_75 ( V_50 ) ;
V_67 = (struct V_67 * ) ( ( T_2 * ) V_51 + V_119 ) ;
if ( V_67 -> V_125 != F_33 ( V_126 ) )
return false ;
if ( V_67 -> V_127 != F_33 ( V_128 ) )
return false ;
if ( V_67 -> V_129 != V_28 )
return false ;
if ( V_67 -> V_130 != 4 )
return false ;
V_56 = ( T_2 * ) V_67 + sizeof( struct V_67 ) ;
V_110 = V_56 + V_28 + 4 ;
V_111 = (struct V_57 * ) V_110 ;
V_112 = & V_30 -> V_32 . V_60 ;
if ( memcmp ( V_111 -> V_131 , V_112 -> V_131 ,
sizeof( V_111 -> V_131 ) ) != 0 )
return false ;
if ( V_117 > 1 )
return true ;
if ( V_111 -> type == V_75 )
return false ;
V_120 = F_72 ( V_30 , V_53 , V_56 , V_110 ,
V_51 ) ;
if ( V_120 == 1 )
F_30 ( V_70 , V_30 ,
L_20 ,
V_51 -> V_69 , F_31 ( V_7 ) , V_56 ,
V_110 ) ;
if ( V_120 < 2 )
return ! ! V_120 ;
F_58 ( V_30 , V_53 , V_7 ) ;
switch ( V_111 -> type ) {
case V_68 :
if ( F_71 ( V_30 , V_53 , V_56 ,
V_51 -> V_69 , V_7 ) )
return true ;
break;
case V_71 :
if ( F_70 ( V_30 , V_53 ,
V_51 -> V_69 , V_56 , V_7 ) )
return true ;
break;
case V_72 :
if ( F_66 ( V_30 , V_56 , V_51 -> V_69 ,
V_7 ) )
return true ;
break;
case V_73 :
if ( F_69 ( V_30 , V_53 , V_56 , V_51 ,
V_7 ) )
return true ;
break;
}
F_30 ( V_70 , V_30 ,
L_21 ,
V_51 -> V_69 , F_31 ( V_7 ) , V_56 , V_110 ) ;
return true ;
}
static void F_79 ( struct V_29 * V_30 , int V_132 )
{
struct V_12 * V_21 ;
struct V_8 * V_42 ;
struct V_34 * V_35 ;
struct V_31 * V_5 ;
T_3 * V_44 ;
int V_43 ;
V_5 = V_30 -> V_32 . V_39 ;
if ( ! V_5 )
return;
for ( V_43 = 0 ; V_43 < V_5 -> V_2 ; V_43 ++ ) {
V_35 = & V_5 -> V_38 [ V_43 ] ;
V_44 = & V_5 -> V_45 [ V_43 ] ;
F_13 ( V_44 ) ;
F_25 (backbone_gw, node_tmp,
head, hash_entry) {
if ( V_132 )
goto V_133;
if ( ! F_80 ( V_21 -> V_97 ,
V_134 ) )
continue;
F_30 ( V_70 , V_21 -> V_30 ,
L_22 ,
V_21 -> V_16 ) ;
V_133:
if ( F_61 ( & V_21 -> V_98 ) )
F_68 ( & V_30 -> V_32 . V_101 ) ;
F_24 ( V_21 ) ;
F_26 ( & V_21 -> V_13 ) ;
F_10 ( V_21 ) ;
}
F_14 ( V_44 ) ;
}
}
static void F_81 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
int V_132 )
{
struct V_12 * V_21 ;
struct V_3 * V_4 ;
struct V_34 * V_35 ;
struct V_31 * V_5 ;
int V_43 ;
V_5 = V_30 -> V_32 . V_33 ;
if ( ! V_5 )
return;
for ( V_43 = 0 ; V_43 < V_5 -> V_2 ; V_43 ++ ) {
V_35 = & V_5 -> V_38 [ V_43 ] ;
F_18 () ;
F_19 (claim, head, hash_entry) {
V_21 = F_63 ( V_4 ) ;
if ( V_132 )
goto V_133;
if ( ! F_6 ( V_21 -> V_16 ,
V_53 -> V_63 -> V_64 ) )
goto V_135;
if ( ! F_80 ( V_4 -> V_97 ,
V_136 ) )
goto V_135;
F_30 ( V_70 , V_30 ,
L_23 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
V_133:
F_70 ( V_30 , V_53 ,
V_21 -> V_16 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
V_135:
F_10 ( V_21 ) ;
}
F_21 () ;
}
}
void F_82 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
struct V_52 * V_137 )
{
struct V_12 * V_21 ;
struct V_34 * V_35 ;
struct V_31 * V_5 ;
T_5 V_113 ;
int V_43 ;
V_113 = F_33 ( F_15 ( 0 , V_53 -> V_63 -> V_64 , V_28 ) ) ;
V_30 -> V_32 . V_60 . V_113 = V_113 ;
if ( ! F_61 ( & V_30 -> V_138 ) )
V_137 = NULL ;
if ( ! V_137 ) {
F_81 ( V_30 , NULL , 1 ) ;
F_79 ( V_30 , 1 ) ;
return;
}
V_5 = V_30 -> V_32 . V_39 ;
if ( ! V_5 )
return;
for ( V_43 = 0 ; V_43 < V_5 -> V_2 ; V_43 ++ ) {
V_35 = & V_5 -> V_38 [ V_43 ] ;
F_18 () ;
F_19 (backbone_gw, head, hash_entry) {
if ( ! F_6 ( V_21 -> V_16 ,
V_137 -> V_63 -> V_64 ) )
continue;
F_23 ( V_21 -> V_16 ,
V_53 -> V_63 -> V_64 ) ;
F_56 ( V_30 , V_21 ) ;
}
F_21 () ;
}
}
static void
F_83 ( struct V_29 * V_30 ,
struct V_12 * V_21 )
{
F_30 ( V_70 , V_30 , L_24 ,
V_21 -> V_7 ) ;
F_27 ( V_30 , V_30 -> V_32 . V_139 ,
V_21 -> V_7 , V_75 ) ;
}
void F_84 ( struct V_54 * V_63 )
{
struct V_29 * V_30 = F_85 ( V_63 ) ;
struct V_52 * V_53 ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 )
return;
F_82 ( V_30 , V_53 , V_53 ) ;
F_39 ( V_53 ) ;
}
static void F_86 ( struct V_85 * V_86 )
{
struct V_140 * V_140 ;
struct V_29 * V_30 ;
struct V_141 * V_142 ;
struct V_34 * V_35 ;
struct V_12 * V_21 ;
struct V_31 * V_5 ;
struct V_52 * V_53 ;
bool V_143 = false ;
int V_43 ;
V_140 = F_87 ( V_86 ) ;
V_142 = F_5 ( V_140 , struct V_141 , V_86 ) ;
V_30 = F_5 ( V_142 , struct V_29 , V_32 ) ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 )
goto V_65;
F_81 ( V_30 , V_53 , 0 ) ;
F_79 ( V_30 , 0 ) ;
if ( ! F_61 ( & V_30 -> V_138 ) )
goto V_65;
if ( F_88 ( & V_30 -> V_32 . V_144 ) ) {
F_89 ( V_30 -> V_32 . V_139 ) ;
V_30 -> V_32 . V_139 [ 0 ] = 0xba ;
V_30 -> V_32 . V_139 [ 1 ] = 0xbe ;
V_30 -> V_32 . V_145 = V_84 ;
F_46 ( & V_30 -> V_32 . V_144 ,
V_146 ) ;
V_143 = true ;
}
V_5 = V_30 -> V_32 . V_39 ;
if ( ! V_5 )
goto V_65;
for ( V_43 = 0 ; V_43 < V_5 -> V_2 ; V_43 ++ ) {
V_35 = & V_5 -> V_38 [ V_43 ] ;
F_18 () ;
F_19 (backbone_gw, head, hash_entry) {
if ( ! F_6 ( V_21 -> V_16 ,
V_53 -> V_63 -> V_64 ) )
continue;
V_21 -> V_97 = V_84 ;
F_56 ( V_30 , V_21 ) ;
if ( V_143 )
F_83 ( V_30 ,
V_21 ) ;
if ( F_61 ( & V_21 -> V_98 ) == 0 )
continue;
if ( ! F_88 ( & V_21 -> V_99 ) )
continue;
F_68 ( & V_21 -> V_30 -> V_32 . V_101 ) ;
F_46 ( & V_21 -> V_98 , 0 ) ;
}
F_21 () ;
}
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
F_90 ( V_147 , & V_30 -> V_32 . V_86 ,
F_91 ( V_148 ) ) ;
}
int F_92 ( struct V_29 * V_30 )
{
int V_43 ;
T_2 V_60 [ V_28 ] = { 0xff , 0x43 , 0x05 , 0x00 , 0x00 , 0x00 } ;
struct V_52 * V_53 ;
T_6 V_27 ;
unsigned long V_149 ;
F_45 ( & V_30 -> V_32 . V_150 ) ;
F_30 ( V_70 , V_30 , L_25 ) ;
memcpy ( & V_30 -> V_32 . V_60 . V_131 , V_60 , 3 ) ;
V_30 -> V_32 . V_60 . type = 0 ;
V_53 = F_28 ( V_30 ) ;
if ( V_53 ) {
V_27 = F_15 ( 0 , V_53 -> V_63 -> V_64 , V_28 ) ;
V_30 -> V_32 . V_60 . V_113 = F_33 ( V_27 ) ;
F_39 ( V_53 ) ;
} else {
V_30 -> V_32 . V_60 . V_113 = 0 ;
}
V_149 = V_84 - F_91 ( V_151 ) ;
for ( V_43 = 0 ; V_43 < V_152 ; V_43 ++ )
V_30 -> V_32 . V_153 [ V_43 ] . V_149 = V_149 ;
V_30 -> V_32 . V_154 = 0 ;
F_46 ( & V_30 -> V_32 . V_144 ,
V_146 ) ;
if ( V_30 -> V_32 . V_33 )
return 0 ;
V_30 -> V_32 . V_33 = F_93 ( 128 ) ;
V_30 -> V_32 . V_39 = F_93 ( 32 ) ;
if ( ! V_30 -> V_32 . V_33 || ! V_30 -> V_32 . V_39 )
return - V_155 ;
F_94 ( V_30 -> V_32 . V_33 ,
& V_156 ) ;
F_94 ( V_30 -> V_32 . V_39 ,
& V_157 ) ;
F_30 ( V_70 , V_30 , L_26 ) ;
F_95 ( & V_30 -> V_32 . V_86 , F_86 ) ;
F_90 ( V_147 , & V_30 -> V_32 . V_86 ,
F_91 ( V_148 ) ) ;
return 0 ;
}
bool F_96 ( struct V_29 * V_30 ,
struct V_49 * V_50 )
{
int V_43 , V_158 ;
T_4 V_27 ;
struct V_159 * V_160 ;
struct V_161 * V_92 ;
bool V_120 = false ;
V_160 = (struct V_159 * ) V_50 -> V_1 ;
V_27 = F_97 ( V_50 , ( T_2 * ) ( V_160 + 1 ) ) ;
F_13 ( & V_30 -> V_32 . V_150 ) ;
for ( V_43 = 0 ; V_43 < V_152 ; V_43 ++ ) {
V_158 = ( V_30 -> V_32 . V_154 + V_43 ) ;
V_158 %= V_152 ;
V_92 = & V_30 -> V_32 . V_153 [ V_158 ] ;
if ( F_80 ( V_92 -> V_149 ,
V_151 ) )
break;
if ( V_92 -> V_27 != V_27 )
continue;
if ( F_6 ( V_92 -> V_16 , V_160 -> V_16 ) )
continue;
V_120 = true ;
goto V_65;
}
V_158 = ( V_30 -> V_32 . V_154 + V_152 - 1 ) ;
V_158 %= V_152 ;
V_92 = & V_30 -> V_32 . V_153 [ V_158 ] ;
V_92 -> V_27 = V_27 ;
V_92 -> V_149 = V_84 ;
F_23 ( V_92 -> V_16 , V_160 -> V_16 ) ;
V_30 -> V_32 . V_154 = V_158 ;
V_65:
F_14 ( & V_30 -> V_32 . V_150 ) ;
return V_120 ;
}
bool F_98 ( struct V_29 * V_30 , T_2 * V_16 ,
unsigned short V_7 )
{
struct V_31 * V_5 = V_30 -> V_32 . V_39 ;
struct V_34 * V_35 ;
struct V_12 * V_21 ;
int V_43 ;
if ( ! F_61 ( & V_30 -> V_138 ) )
return false ;
if ( ! V_5 )
return false ;
for ( V_43 = 0 ; V_43 < V_5 -> V_2 ; V_43 ++ ) {
V_35 = & V_5 -> V_38 [ V_43 ] ;
F_18 () ;
F_19 (backbone_gw, head, hash_entry) {
if ( F_6 ( V_21 -> V_16 , V_16 ) &&
V_21 -> V_7 == V_7 ) {
F_21 () ;
return true ;
}
}
F_21 () ;
}
return false ;
}
bool F_99 ( struct V_49 * V_50 ,
struct V_93 * V_94 , int V_162 )
{
struct V_12 * V_21 ;
unsigned short V_7 ;
if ( ! F_61 ( & V_94 -> V_30 -> V_138 ) )
return false ;
if ( ! F_77 ( V_50 , V_162 + V_66 ) )
return false ;
V_7 = F_74 ( V_50 , V_162 ) ;
V_21 = F_22 ( V_94 -> V_30 ,
V_94 -> V_16 , V_7 ) ;
if ( ! V_21 )
return false ;
F_10 ( V_21 ) ;
return true ;
}
void F_100 ( struct V_29 * V_30 )
{
struct V_52 * V_53 ;
F_101 ( & V_30 -> V_32 . V_86 ) ;
V_53 = F_28 ( V_30 ) ;
if ( V_30 -> V_32 . V_33 ) {
F_81 ( V_30 , V_53 , 1 ) ;
F_102 ( V_30 -> V_32 . V_33 ) ;
V_30 -> V_32 . V_33 = NULL ;
}
if ( V_30 -> V_32 . V_39 ) {
F_79 ( V_30 , 1 ) ;
F_102 ( V_30 -> V_32 . V_39 ) ;
V_30 -> V_32 . V_39 = NULL ;
}
if ( V_53 )
F_39 ( V_53 ) ;
}
static bool
F_103 ( struct V_29 * V_30 , struct V_49 * V_50 ,
struct V_52 * V_53 ,
unsigned short V_7 )
{
struct V_12 * V_21 ;
struct V_51 * V_51 ;
V_51 = F_75 ( V_50 ) ;
if ( ! F_6 ( V_51 -> V_69 ,
V_30 -> V_32 . V_139 ) )
return false ;
if ( F_80 ( V_30 -> V_32 . V_145 ,
V_163 ) )
return true ;
V_21 = F_43 ( V_30 ,
V_53 -> V_63 -> V_64 ,
V_7 , true ) ;
if ( F_51 ( ! V_21 ) )
return true ;
F_104 ( V_147 , & V_21 -> V_88 ) ;
return true ;
}
bool F_105 ( struct V_29 * V_30 , struct V_49 * V_50 ,
unsigned short V_7 , bool V_164 )
{
struct V_12 * V_21 ;
struct V_51 * V_51 ;
struct V_3 V_103 , * V_4 = NULL ;
struct V_52 * V_53 ;
bool V_165 ;
bool V_120 ;
V_51 = F_75 ( V_50 ) ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 )
goto V_166;
if ( ! F_61 ( & V_30 -> V_138 ) )
goto V_167;
if ( F_103 ( V_30 , V_50 , V_53 , V_7 ) )
goto V_166;
if ( F_51 ( F_61 ( & V_30 -> V_32 . V_101 ) ) )
if ( F_106 ( V_51 -> V_74 ) && V_164 )
goto V_166;
F_23 ( V_103 . V_6 , V_51 -> V_69 ) ;
V_103 . V_7 = V_7 ;
V_4 = F_17 ( V_30 , & V_103 ) ;
if ( ! V_4 ) {
F_71 ( V_30 , V_53 ,
V_53 -> V_63 -> V_64 ,
V_51 -> V_69 , V_7 ) ;
goto V_167;
}
V_21 = F_63 ( V_4 ) ;
V_165 = F_6 ( V_21 -> V_16 ,
V_53 -> V_63 -> V_64 ) ;
F_10 ( V_21 ) ;
if ( V_165 ) {
V_4 -> V_97 = V_84 ;
goto V_167;
}
if ( F_106 ( V_51 -> V_74 ) && V_164 ) {
goto V_166;
} else {
F_71 ( V_30 , V_53 ,
V_53 -> V_63 -> V_64 ,
V_51 -> V_69 , V_7 ) ;
goto V_167;
}
V_167:
F_58 ( V_30 , V_53 , V_7 ) ;
V_120 = false ;
goto V_65;
V_166:
F_107 ( V_50 ) ;
V_120 = true ;
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
if ( V_4 )
F_16 ( V_4 ) ;
return V_120 ;
}
bool F_108 ( struct V_29 * V_30 , struct V_49 * V_50 ,
unsigned short V_7 )
{
struct V_51 * V_51 ;
struct V_3 V_103 , * V_4 = NULL ;
struct V_12 * V_21 ;
struct V_52 * V_53 ;
bool V_168 ;
bool V_120 = false ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 )
goto V_65;
if ( ! F_61 ( & V_30 -> V_138 ) )
goto V_167;
if ( F_73 ( V_30 , V_53 , V_50 ) )
goto V_166;
V_51 = F_75 ( V_50 ) ;
if ( F_51 ( F_61 ( & V_30 -> V_32 . V_101 ) ) )
if ( F_106 ( V_51 -> V_74 ) )
goto V_166;
F_23 ( V_103 . V_6 , V_51 -> V_69 ) ;
V_103 . V_7 = V_7 ;
V_4 = F_17 ( V_30 , & V_103 ) ;
if ( ! V_4 )
goto V_167;
V_21 = F_63 ( V_4 ) ;
V_168 = F_6 ( V_21 -> V_16 ,
V_53 -> V_63 -> V_64 ) ;
F_10 ( V_21 ) ;
if ( V_168 ) {
F_70 ( V_30 , V_53 ,
V_53 -> V_63 -> V_64 ,
V_51 -> V_69 , V_7 ) ;
goto V_167;
}
if ( F_106 ( V_51 -> V_74 ) ) {
goto V_166;
} else {
goto V_167;
}
V_167:
F_58 ( V_30 , V_53 , V_7 ) ;
V_120 = false ;
goto V_65;
V_166:
V_120 = true ;
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
if ( V_4 )
F_16 ( V_4 ) ;
return V_120 ;
}
int F_109 ( struct V_169 * V_170 , void * V_171 )
{
struct V_54 * V_63 = (struct V_54 * ) V_170 -> V_172 ;
struct V_29 * V_30 = F_85 ( V_63 ) ;
struct V_31 * V_5 = V_30 -> V_32 . V_33 ;
struct V_12 * V_21 ;
struct V_3 * V_4 ;
struct V_52 * V_53 ;
struct V_34 * V_35 ;
T_6 V_108 ;
T_1 V_43 ;
bool V_173 ;
T_2 * V_174 ;
V_53 = F_110 ( V_170 ) ;
if ( ! V_53 )
goto V_65;
V_174 = V_53 -> V_63 -> V_64 ;
F_111 ( V_170 ,
L_27 ,
V_63 -> V_175 , V_174 ,
F_67 ( V_30 -> V_32 . V_60 . V_113 ) ) ;
F_112 ( V_170 ,
L_28 ) ;
for ( V_43 = 0 ; V_43 < V_5 -> V_2 ; V_43 ++ ) {
V_35 = & V_5 -> V_38 [ V_43 ] ;
F_18 () ;
F_19 (claim, head, hash_entry) {
V_21 = F_63 ( V_4 ) ;
V_173 = F_6 ( V_21 -> V_16 ,
V_174 ) ;
F_13 ( & V_21 -> V_26 ) ;
V_108 = V_21 -> V_27 ;
F_14 ( & V_21 -> V_26 ) ;
F_111 ( V_170 , L_29 ,
V_4 -> V_6 , F_31 ( V_4 -> V_7 ) ,
V_21 -> V_16 ,
( V_173 ? 'x' : ' ' ) ,
V_108 ) ;
F_10 ( V_21 ) ;
}
F_21 () ;
}
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
return 0 ;
}
static int
F_113 ( struct V_49 * V_176 , T_1 V_177 , T_1 V_170 ,
struct V_52 * V_53 ,
struct V_3 * V_4 )
{
T_2 * V_174 = V_53 -> V_63 -> V_64 ;
T_6 V_108 ;
bool V_173 ;
void * V_178 ;
int V_120 = - V_179 ;
V_178 = F_114 ( V_176 , V_177 , V_170 , & V_180 ,
V_181 , V_182 ) ;
if ( ! V_178 ) {
V_120 = - V_183 ;
goto V_65;
}
V_173 = F_6 ( V_4 -> V_21 -> V_16 ,
V_174 ) ;
F_13 ( & V_4 -> V_21 -> V_26 ) ;
V_108 = V_4 -> V_21 -> V_27 ;
F_14 ( & V_4 -> V_21 -> V_26 ) ;
if ( V_173 )
if ( F_115 ( V_176 , V_184 ) ) {
F_116 ( V_176 , V_178 ) ;
goto V_65;
}
if ( F_117 ( V_176 , V_185 , V_28 , V_4 -> V_6 ) ||
F_118 ( V_176 , V_186 , V_4 -> V_7 ) ||
F_117 ( V_176 , V_187 , V_28 ,
V_4 -> V_21 -> V_16 ) ||
F_118 ( V_176 , V_188 ,
V_108 ) ) {
F_116 ( V_176 , V_178 ) ;
goto V_65;
}
F_119 ( V_176 , V_178 ) ;
V_120 = 0 ;
V_65:
return V_120 ;
}
static int
F_120 ( struct V_49 * V_176 , T_1 V_177 , T_1 V_170 ,
struct V_52 * V_53 ,
struct V_34 * V_35 , int * V_189 )
{
struct V_3 * V_4 ;
int V_190 = 0 ;
F_18 () ;
F_19 (claim, head, hash_entry) {
if ( V_190 ++ < * V_189 )
continue;
if ( F_113 ( V_176 , V_177 , V_170 ,
V_53 , V_4 ) ) {
* V_189 = V_190 - 1 ;
goto V_191;
}
}
* V_189 = V_190 ;
V_191:
F_21 () ;
return 0 ;
}
int F_121 ( struct V_49 * V_176 , struct V_192 * V_193 )
{
struct V_52 * V_53 = NULL ;
int V_177 = F_122 ( V_193 -> V_50 ) . V_177 ;
struct V_194 * V_194 = F_123 ( V_193 -> V_50 -> V_195 ) ;
struct V_54 * V_55 ;
struct V_31 * V_5 ;
struct V_29 * V_30 ;
int V_196 = V_193 -> args [ 0 ] ;
struct V_34 * V_35 ;
int V_190 = V_193 -> args [ 1 ] ;
int V_197 ;
int V_120 = 0 ;
V_197 = F_124 ( V_193 -> V_198 ,
V_199 ) ;
if ( ! V_197 )
return - V_179 ;
V_55 = F_125 ( V_194 , V_197 ) ;
if ( ! V_55 || ! F_126 ( V_55 ) ) {
V_120 = - V_200 ;
goto V_65;
}
V_30 = F_85 ( V_55 ) ;
V_5 = V_30 -> V_32 . V_33 ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 || V_53 -> V_201 != V_202 ) {
V_120 = - V_203 ;
goto V_65;
}
while ( V_196 < V_5 -> V_2 ) {
V_35 = & V_5 -> V_38 [ V_196 ] ;
if ( F_120 ( V_176 , V_177 ,
V_193 -> V_198 -> V_204 ,
V_53 , V_35 , & V_190 ) )
break;
V_196 ++ ;
}
V_193 -> args [ 0 ] = V_196 ;
V_193 -> args [ 1 ] = V_190 ;
V_120 = V_176 -> V_82 ;
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
if ( V_55 )
F_127 ( V_55 ) ;
return V_120 ;
}
int F_128 ( struct V_169 * V_170 , void * V_171 )
{
struct V_54 * V_63 = (struct V_54 * ) V_170 -> V_172 ;
struct V_29 * V_30 = F_85 ( V_63 ) ;
struct V_31 * V_5 = V_30 -> V_32 . V_39 ;
struct V_12 * V_21 ;
struct V_52 * V_53 ;
struct V_34 * V_35 ;
int V_205 , V_206 ;
T_6 V_108 ;
T_1 V_43 ;
bool V_173 ;
T_2 * V_174 ;
V_53 = F_110 ( V_170 ) ;
if ( ! V_53 )
goto V_65;
V_174 = V_53 -> V_63 -> V_64 ;
F_111 ( V_170 ,
L_30 ,
V_63 -> V_175 , V_174 ,
F_67 ( V_30 -> V_32 . V_60 . V_113 ) ) ;
F_112 ( V_170 , L_31 ) ;
for ( V_43 = 0 ; V_43 < V_5 -> V_2 ; V_43 ++ ) {
V_35 = & V_5 -> V_38 [ V_43 ] ;
F_18 () ;
F_19 (backbone_gw, head, hash_entry) {
V_206 = F_129 ( V_84 -
V_21 -> V_97 ) ;
V_205 = V_206 / 1000 ;
V_206 = V_206 % 1000 ;
V_173 = F_6 ( V_21 -> V_16 ,
V_174 ) ;
if ( V_173 )
continue;
F_13 ( & V_21 -> V_26 ) ;
V_108 = V_21 -> V_27 ;
F_14 ( & V_21 -> V_26 ) ;
F_111 ( V_170 , L_32 ,
V_21 -> V_16 ,
F_31 ( V_21 -> V_7 ) , V_205 ,
V_206 , V_108 ) ;
}
F_21 () ;
}
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
return 0 ;
}
static int
F_130 ( struct V_49 * V_176 , T_1 V_177 , T_1 V_170 ,
struct V_52 * V_53 ,
struct V_12 * V_21 )
{
T_2 * V_174 = V_53 -> V_63 -> V_64 ;
T_6 V_108 ;
bool V_173 ;
int V_206 ;
void * V_178 ;
int V_120 = - V_179 ;
V_178 = F_114 ( V_176 , V_177 , V_170 , & V_180 ,
V_181 , V_207 ) ;
if ( ! V_178 ) {
V_120 = - V_183 ;
goto V_65;
}
V_173 = F_6 ( V_21 -> V_16 , V_174 ) ;
F_13 ( & V_21 -> V_26 ) ;
V_108 = V_21 -> V_27 ;
F_14 ( & V_21 -> V_26 ) ;
V_206 = F_129 ( V_84 - V_21 -> V_97 ) ;
if ( V_173 )
if ( F_115 ( V_176 , V_184 ) ) {
F_116 ( V_176 , V_178 ) ;
goto V_65;
}
if ( F_117 ( V_176 , V_187 , V_28 ,
V_21 -> V_16 ) ||
F_118 ( V_176 , V_186 , V_21 -> V_7 ) ||
F_118 ( V_176 , V_188 ,
V_108 ) ||
F_131 ( V_176 , V_208 , V_206 ) ) {
F_116 ( V_176 , V_178 ) ;
goto V_65;
}
F_119 ( V_176 , V_178 ) ;
V_120 = 0 ;
V_65:
return V_120 ;
}
static int
F_132 ( struct V_49 * V_176 , T_1 V_177 , T_1 V_170 ,
struct V_52 * V_53 ,
struct V_34 * V_35 , int * V_189 )
{
struct V_12 * V_21 ;
int V_190 = 0 ;
F_18 () ;
F_19 (backbone_gw, head, hash_entry) {
if ( V_190 ++ < * V_189 )
continue;
if ( F_130 ( V_176 , V_177 , V_170 ,
V_53 , V_21 ) ) {
* V_189 = V_190 - 1 ;
goto V_191;
}
}
* V_189 = V_190 ;
V_191:
F_21 () ;
return 0 ;
}
int F_133 ( struct V_49 * V_176 , struct V_192 * V_193 )
{
struct V_52 * V_53 = NULL ;
int V_177 = F_122 ( V_193 -> V_50 ) . V_177 ;
struct V_194 * V_194 = F_123 ( V_193 -> V_50 -> V_195 ) ;
struct V_54 * V_55 ;
struct V_31 * V_5 ;
struct V_29 * V_30 ;
int V_196 = V_193 -> args [ 0 ] ;
struct V_34 * V_35 ;
int V_190 = V_193 -> args [ 1 ] ;
int V_197 ;
int V_120 = 0 ;
V_197 = F_124 ( V_193 -> V_198 ,
V_199 ) ;
if ( ! V_197 )
return - V_179 ;
V_55 = F_125 ( V_194 , V_197 ) ;
if ( ! V_55 || ! F_126 ( V_55 ) ) {
V_120 = - V_200 ;
goto V_65;
}
V_30 = F_85 ( V_55 ) ;
V_5 = V_30 -> V_32 . V_39 ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 || V_53 -> V_201 != V_202 ) {
V_120 = - V_203 ;
goto V_65;
}
while ( V_196 < V_5 -> V_2 ) {
V_35 = & V_5 -> V_38 [ V_196 ] ;
if ( F_132 ( V_176 , V_177 ,
V_193 -> V_198 -> V_204 ,
V_53 , V_35 , & V_190 ) )
break;
V_196 ++ ;
}
V_193 -> args [ 0 ] = V_196 ;
V_193 -> args [ 1 ] = V_190 ;
V_120 = V_176 -> V_82 ;
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
if ( V_55 )
F_127 ( V_55 ) ;
return V_120 ;
}
