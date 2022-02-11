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
F_38 ( V_50 ) ;
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
}
static void F_40 ( struct V_83 * V_84 )
{
struct V_12 * V_21 ;
struct V_29 * V_30 ;
char V_85 [ 6 ] = { '\0' } ;
V_21 = F_5 ( V_84 , struct V_12 ,
V_86 ) ;
V_30 = V_21 -> V_30 ;
F_41 ( V_30 -> V_55 ,
L_6 ,
F_31 ( V_21 -> V_7 ) ) ;
snprintf ( V_85 , sizeof( V_85 ) , L_7 ,
F_31 ( V_21 -> V_7 ) ) ;
V_85 [ sizeof( V_85 ) - 1 ] = 0 ;
F_42 ( V_30 , V_87 , V_88 ,
V_85 ) ;
F_10 ( V_21 ) ;
}
static struct V_12 *
F_43 ( struct V_29 * V_30 , T_2 * V_16 ,
unsigned short V_7 , bool V_89 )
{
struct V_12 * V_90 ;
struct V_91 * V_92 ;
int V_93 ;
V_90 = F_22 ( V_30 , V_16 , V_7 ) ;
if ( V_90 )
return V_90 ;
F_30 ( V_70 , V_30 ,
L_8 ,
V_16 , F_31 ( V_7 ) ) ;
V_90 = F_44 ( sizeof( * V_90 ) , V_94 ) ;
if ( ! V_90 )
return NULL ;
V_90 -> V_7 = V_7 ;
V_90 -> V_95 = V_96 ;
V_90 -> V_27 = V_46 ;
V_90 -> V_30 = V_30 ;
F_45 ( & V_90 -> V_26 ) ;
F_46 ( & V_90 -> V_97 , 0 ) ;
F_46 ( & V_90 -> V_98 , 0 ) ;
F_23 ( V_90 -> V_16 , V_16 ) ;
F_47 ( & V_90 -> V_86 , F_40 ) ;
F_48 ( & V_90 -> V_22 ) ;
F_49 ( & V_90 -> V_22 ) ;
V_93 = F_50 ( V_30 -> V_32 . V_39 ,
F_4 ,
F_3 , V_90 ,
& V_90 -> V_13 ) ;
if ( F_51 ( V_93 != 0 ) ) {
F_52 ( V_90 ) ;
return NULL ;
}
V_92 = F_53 ( V_30 , V_16 ) ;
if ( V_92 ) {
F_54 ( V_30 , V_92 , V_7 ,
L_9 ) ;
F_55 ( V_92 ) ;
}
if ( V_89 ) {
F_56 ( V_30 , V_90 ) ;
F_57 ( & V_90 -> V_97 ) ;
F_46 ( & V_90 -> V_98 , V_99 ) ;
F_57 ( & V_30 -> V_32 . V_100 ) ;
}
return V_90 ;
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
V_21 -> V_95 = V_96 ;
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
if ( ! F_61 ( & V_21 -> V_97 ) ) {
F_57 ( & V_21 -> V_30 -> V_32 . V_100 ) ;
F_46 ( & V_21 -> V_97 , 1 ) ;
}
}
static void F_56 ( struct V_29 * V_30 ,
struct V_12 * V_21 )
{
T_2 V_47 [ V_28 ] ;
T_5 V_27 ;
memcpy ( V_47 , V_101 , 4 ) ;
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
struct V_3 V_102 ;
bool V_103 = false ;
int V_93 ;
F_23 ( V_102 . V_6 , V_47 ) ;
V_102 . V_7 = V_7 ;
V_4 = F_17 ( V_30 , & V_102 ) ;
if ( ! V_4 ) {
V_4 = F_44 ( sizeof( * V_4 ) , V_94 ) ;
if ( ! V_4 )
return;
F_23 ( V_4 -> V_6 , V_47 ) ;
F_45 ( & V_4 -> V_25 ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_95 = V_96 ;
F_49 ( & V_21 -> V_22 ) ;
V_4 -> V_21 = V_21 ;
F_48 ( & V_4 -> V_22 ) ;
F_30 ( V_70 , V_30 ,
L_12 ,
V_47 , F_31 ( V_7 ) ) ;
F_49 ( & V_4 -> V_22 ) ;
V_93 = F_50 ( V_30 -> V_32 . V_33 ,
F_7 ,
F_1 , V_4 ,
& V_4 -> V_13 ) ;
if ( F_51 ( V_93 != 0 ) ) {
F_52 ( V_4 ) ;
return;
}
} else {
V_4 -> V_95 = V_96 ;
if ( V_4 -> V_21 == V_21 )
goto V_104;
F_30 ( V_70 , V_30 ,
L_13 ,
V_47 , F_31 ( V_7 ) , V_21 -> V_16 ) ;
V_103 = true ;
}
F_13 ( & V_4 -> V_25 ) ;
V_24 = V_4 -> V_21 ;
F_49 ( & V_21 -> V_22 ) ;
V_4 -> V_21 = V_21 ;
F_14 ( & V_4 -> V_25 ) ;
if ( V_103 ) {
F_13 ( & V_24 -> V_26 ) ;
V_24 -> V_27 ^= F_15 ( 0 , V_4 -> V_6 , V_28 ) ;
F_14 ( & V_24 -> V_26 ) ;
}
F_10 ( V_24 ) ;
F_13 ( & V_21 -> V_26 ) ;
V_21 -> V_27 ^= F_15 ( 0 , V_4 -> V_6 , V_28 ) ;
F_14 ( & V_21 -> V_26 ) ;
V_21 -> V_95 = V_96 ;
V_104:
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
struct V_3 V_102 , * V_4 ;
F_23 ( V_102 . V_6 , V_47 ) ;
V_102 . V_7 = V_7 ;
V_4 = F_17 ( V_30 , & V_102 ) ;
if ( ! V_4 )
return;
F_30 ( V_70 , V_30 , L_14 ,
V_47 , F_31 ( V_7 ) ) ;
F_65 ( V_30 -> V_32 . V_33 , F_7 ,
F_1 , V_4 ) ;
F_16 ( V_4 ) ;
F_16 ( V_4 ) ;
}
static bool F_66 ( struct V_29 * V_30 , T_2 * V_105 ,
T_2 * V_106 , unsigned short V_7 )
{
struct V_12 * V_21 ;
T_6 V_107 , V_27 ;
if ( memcmp ( V_105 , V_101 , 4 ) != 0 )
return false ;
V_21 = F_43 ( V_30 , V_106 , V_7 ,
false ) ;
if ( F_51 ( ! V_21 ) )
return true ;
V_21 -> V_95 = V_96 ;
V_27 = F_67 ( * ( ( T_5 * ) ( & V_105 [ 4 ] ) ) ) ;
F_30 ( V_70 , V_30 ,
L_15 ,
F_31 ( V_7 ) , V_21 -> V_16 , V_27 ) ;
F_13 ( & V_21 -> V_26 ) ;
V_107 = V_21 -> V_27 ;
F_14 ( & V_21 -> V_26 ) ;
if ( V_107 != V_27 ) {
F_30 ( V_70 , V_21 -> V_30 ,
L_16 ,
V_21 -> V_16 ,
F_31 ( V_21 -> V_7 ) ,
V_107 , V_27 ) ;
F_60 ( V_21 ) ;
} else {
if ( F_61 ( & V_21 -> V_97 ) ) {
F_68 ( & V_21 -> V_30 -> V_32 . V_100 ) ;
F_46 ( & V_21 -> V_97 , 0 ) ;
}
}
F_10 ( V_21 ) ;
return true ;
}
static bool F_69 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
T_2 * V_106 , struct V_51 * V_51 ,
unsigned short V_7 )
{
if ( ! F_6 ( V_106 , V_51 -> V_74 ) )
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
T_2 * V_106 , T_2 * V_108 ,
unsigned short V_7 )
{
struct V_12 * V_21 ;
if ( V_53 && F_6 ( V_106 ,
V_53 -> V_63 -> V_64 ) )
F_27 ( V_30 , V_108 , V_7 ,
V_71 ) ;
V_21 = F_22 ( V_30 , V_106 , V_7 ) ;
if ( ! V_21 )
return true ;
F_30 ( V_70 , V_30 ,
L_18 ,
V_108 , F_31 ( V_7 ) , V_21 -> V_16 ) ;
F_64 ( V_30 , V_108 , V_7 ) ;
F_10 ( V_21 ) ;
return true ;
}
static bool F_71 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
T_2 * V_106 , T_2 * V_108 ,
unsigned short V_7 )
{
struct V_12 * V_21 ;
V_21 = F_43 ( V_30 , V_106 , V_7 ,
false ) ;
if ( F_51 ( ! V_21 ) )
return true ;
F_62 ( V_30 , V_108 , V_7 , V_21 ) ;
if ( F_6 ( V_106 , V_53 -> V_63 -> V_64 ) )
F_27 ( V_30 , V_108 , V_7 ,
V_68 ) ;
F_10 ( V_21 ) ;
return true ;
}
static int F_72 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
T_2 * V_56 , T_2 * V_109 ,
struct V_51 * V_51 )
{
T_2 * V_106 ;
struct V_91 * V_92 ;
struct V_57 * V_110 , * V_111 ;
V_110 = (struct V_57 * ) V_109 ;
V_111 = & V_30 -> V_32 . V_60 ;
switch ( V_110 -> type ) {
case V_68 :
V_106 = V_56 ;
break;
case V_73 :
case V_72 :
case V_71 :
V_106 = V_51 -> V_69 ;
break;
default:
return 0 ;
}
if ( F_6 ( V_106 , V_53 -> V_63 -> V_64 ) )
return 0 ;
if ( V_110 -> V_112 == V_111 -> V_112 )
return 2 ;
V_92 = F_53 ( V_30 , V_106 ) ;
if ( ! V_92 )
return 1 ;
if ( F_67 ( V_110 -> V_112 ) > F_67 ( V_111 -> V_112 ) ) {
F_30 ( V_70 , V_30 ,
L_19 ,
F_67 ( V_110 -> V_112 ) ) ;
V_111 -> V_112 = V_110 -> V_112 ;
}
F_55 ( V_92 ) ;
return 2 ;
}
static bool F_73 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
struct V_49 * V_50 )
{
struct V_57 * V_110 , * V_111 ;
T_2 * V_56 , * V_109 ;
struct V_113 * V_114 , V_115 ;
struct V_51 * V_51 ;
struct V_67 * V_67 ;
unsigned short V_7 ;
int V_116 = 0 ;
T_5 V_117 ;
int V_118 ;
int V_119 ;
V_7 = F_74 ( V_50 , 0 ) ;
V_51 = F_75 ( V_50 ) ;
V_117 = V_51 -> V_120 ;
V_118 = V_66 ;
if ( V_7 & V_76 ) {
do {
V_114 = F_76 ( V_50 , V_118 , V_121 ,
& V_115 ) ;
if ( ! V_114 )
return false ;
V_117 = V_114 -> V_122 ;
V_118 += V_121 ;
V_116 ++ ;
} while ( V_117 == F_33 ( V_77 ) );
}
if ( V_117 != F_33 ( V_62 ) )
return false ;
if ( F_51 ( ! F_77 ( V_50 , V_118 + F_78 ( V_50 -> V_123 ) ) ) )
return false ;
V_51 = F_75 ( V_50 ) ;
V_67 = (struct V_67 * ) ( ( T_2 * ) V_51 + V_118 ) ;
if ( V_67 -> V_124 != F_33 ( V_125 ) )
return false ;
if ( V_67 -> V_126 != F_33 ( V_127 ) )
return false ;
if ( V_67 -> V_128 != V_28 )
return false ;
if ( V_67 -> V_129 != 4 )
return false ;
V_56 = ( T_2 * ) V_67 + sizeof( struct V_67 ) ;
V_109 = V_56 + V_28 + 4 ;
V_110 = (struct V_57 * ) V_109 ;
V_111 = & V_30 -> V_32 . V_60 ;
if ( memcmp ( V_110 -> V_130 , V_111 -> V_130 ,
sizeof( V_110 -> V_130 ) ) != 0 )
return false ;
if ( V_116 > 1 )
return true ;
if ( V_110 -> type == V_75 )
return false ;
V_119 = F_72 ( V_30 , V_53 , V_56 , V_109 ,
V_51 ) ;
if ( V_119 == 1 )
F_30 ( V_70 , V_30 ,
L_20 ,
V_51 -> V_69 , F_31 ( V_7 ) , V_56 ,
V_109 ) ;
if ( V_119 < 2 )
return ! ! V_119 ;
F_58 ( V_30 , V_53 , V_7 ) ;
switch ( V_110 -> type ) {
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
V_51 -> V_69 , F_31 ( V_7 ) , V_56 , V_109 ) ;
return true ;
}
static void F_79 ( struct V_29 * V_30 , int V_131 )
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
if ( V_131 )
goto V_132;
if ( ! F_80 ( V_21 -> V_95 ,
V_133 ) )
continue;
F_30 ( V_70 , V_21 -> V_30 ,
L_22 ,
V_21 -> V_16 ) ;
V_132:
if ( F_61 ( & V_21 -> V_97 ) )
F_68 ( & V_30 -> V_32 . V_100 ) ;
F_24 ( V_21 ) ;
F_26 ( & V_21 -> V_13 ) ;
F_10 ( V_21 ) ;
}
F_14 ( V_44 ) ;
}
}
static void F_81 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
int V_131 )
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
if ( V_131 )
goto V_132;
if ( ! F_6 ( V_21 -> V_16 ,
V_53 -> V_63 -> V_64 ) )
goto V_134;
if ( ! F_80 ( V_4 -> V_95 ,
V_135 ) )
goto V_134;
F_30 ( V_70 , V_30 ,
L_23 ) ;
V_132:
F_30 ( V_70 , V_30 ,
L_24 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
F_70 ( V_30 , V_53 ,
V_21 -> V_16 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
V_134:
F_10 ( V_21 ) ;
}
F_21 () ;
}
}
void F_82 ( struct V_29 * V_30 ,
struct V_52 * V_53 ,
struct V_52 * V_136 )
{
struct V_12 * V_21 ;
struct V_34 * V_35 ;
struct V_31 * V_5 ;
T_5 V_112 ;
int V_43 ;
V_112 = F_33 ( F_15 ( 0 , V_53 -> V_63 -> V_64 , V_28 ) ) ;
V_30 -> V_32 . V_60 . V_112 = V_112 ;
if ( ! F_61 ( & V_30 -> V_137 ) )
V_136 = NULL ;
if ( ! V_136 ) {
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
V_136 -> V_63 -> V_64 ) )
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
F_30 ( V_70 , V_30 , L_25 ,
V_21 -> V_7 ) ;
F_27 ( V_30 , V_30 -> V_32 . V_138 ,
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
static void F_86 ( struct V_83 * V_84 )
{
struct V_139 * V_139 ;
struct V_29 * V_30 ;
struct V_140 * V_141 ;
struct V_34 * V_35 ;
struct V_12 * V_21 ;
struct V_31 * V_5 ;
struct V_52 * V_53 ;
bool V_142 = false ;
int V_43 ;
V_139 = F_87 ( V_84 ) ;
V_141 = F_5 ( V_139 , struct V_140 , V_84 ) ;
V_30 = F_5 ( V_141 , struct V_29 , V_32 ) ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 )
goto V_65;
F_81 ( V_30 , V_53 , 0 ) ;
F_79 ( V_30 , 0 ) ;
if ( ! F_61 ( & V_30 -> V_137 ) )
goto V_65;
if ( F_88 ( & V_30 -> V_32 . V_143 ) ) {
F_89 ( V_30 -> V_32 . V_138 ) ;
V_30 -> V_32 . V_138 [ 0 ] = 0xba ;
V_30 -> V_32 . V_138 [ 1 ] = 0xbe ;
V_30 -> V_32 . V_144 = V_96 ;
F_46 ( & V_30 -> V_32 . V_143 ,
V_145 ) ;
V_142 = true ;
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
V_21 -> V_95 = V_96 ;
F_56 ( V_30 , V_21 ) ;
if ( V_142 )
F_83 ( V_30 ,
V_21 ) ;
if ( F_61 ( & V_21 -> V_97 ) == 0 )
continue;
if ( ! F_88 ( & V_21 -> V_98 ) )
continue;
F_68 ( & V_21 -> V_30 -> V_32 . V_100 ) ;
F_46 ( & V_21 -> V_97 , 0 ) ;
}
F_21 () ;
}
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
F_90 ( V_146 , & V_30 -> V_32 . V_84 ,
F_91 ( V_147 ) ) ;
}
int F_92 ( struct V_29 * V_30 )
{
int V_43 ;
T_2 V_60 [ V_28 ] = { 0xff , 0x43 , 0x05 , 0x00 , 0x00 , 0x00 } ;
struct V_52 * V_53 ;
T_6 V_27 ;
unsigned long V_148 ;
F_45 ( & V_30 -> V_32 . V_149 ) ;
F_30 ( V_70 , V_30 , L_26 ) ;
memcpy ( & V_30 -> V_32 . V_60 . V_130 , V_60 , 3 ) ;
V_30 -> V_32 . V_60 . type = 0 ;
V_53 = F_28 ( V_30 ) ;
if ( V_53 ) {
V_27 = F_15 ( 0 , V_53 -> V_63 -> V_64 , V_28 ) ;
V_30 -> V_32 . V_60 . V_112 = F_33 ( V_27 ) ;
F_39 ( V_53 ) ;
} else {
V_30 -> V_32 . V_60 . V_112 = 0 ;
}
V_148 = V_96 - F_91 ( V_150 ) ;
for ( V_43 = 0 ; V_43 < V_151 ; V_43 ++ )
V_30 -> V_32 . V_152 [ V_43 ] . V_148 = V_148 ;
V_30 -> V_32 . V_153 = 0 ;
F_46 ( & V_30 -> V_32 . V_143 ,
V_145 ) ;
if ( V_30 -> V_32 . V_33 )
return 0 ;
V_30 -> V_32 . V_33 = F_93 ( 128 ) ;
V_30 -> V_32 . V_39 = F_93 ( 32 ) ;
if ( ! V_30 -> V_32 . V_33 || ! V_30 -> V_32 . V_39 )
return - V_154 ;
F_94 ( V_30 -> V_32 . V_33 ,
& V_155 ) ;
F_94 ( V_30 -> V_32 . V_39 ,
& V_156 ) ;
F_30 ( V_70 , V_30 , L_27 ) ;
F_95 ( & V_30 -> V_32 . V_84 , F_86 ) ;
F_90 ( V_146 , & V_30 -> V_32 . V_84 ,
F_91 ( V_147 ) ) ;
return 0 ;
}
bool F_96 ( struct V_29 * V_30 ,
struct V_49 * V_50 )
{
int V_43 , V_157 ;
T_4 V_27 ;
struct V_158 * V_159 ;
struct V_160 * V_90 ;
bool V_119 = false ;
V_159 = (struct V_158 * ) V_50 -> V_1 ;
V_27 = F_97 ( V_50 , ( T_2 * ) ( V_159 + 1 ) ) ;
F_13 ( & V_30 -> V_32 . V_149 ) ;
for ( V_43 = 0 ; V_43 < V_151 ; V_43 ++ ) {
V_157 = ( V_30 -> V_32 . V_153 + V_43 ) ;
V_157 %= V_151 ;
V_90 = & V_30 -> V_32 . V_152 [ V_157 ] ;
if ( F_80 ( V_90 -> V_148 ,
V_150 ) )
break;
if ( V_90 -> V_27 != V_27 )
continue;
if ( F_6 ( V_90 -> V_16 , V_159 -> V_16 ) )
continue;
V_119 = true ;
goto V_65;
}
V_157 = ( V_30 -> V_32 . V_153 + V_151 - 1 ) ;
V_157 %= V_151 ;
V_90 = & V_30 -> V_32 . V_152 [ V_157 ] ;
V_90 -> V_27 = V_27 ;
V_90 -> V_148 = V_96 ;
F_23 ( V_90 -> V_16 , V_159 -> V_16 ) ;
V_30 -> V_32 . V_153 = V_157 ;
V_65:
F_14 ( & V_30 -> V_32 . V_149 ) ;
return V_119 ;
}
bool F_98 ( struct V_29 * V_30 , T_2 * V_16 ,
unsigned short V_7 )
{
struct V_31 * V_5 = V_30 -> V_32 . V_39 ;
struct V_34 * V_35 ;
struct V_12 * V_21 ;
int V_43 ;
if ( ! F_61 ( & V_30 -> V_137 ) )
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
struct V_91 * V_92 , int V_161 )
{
struct V_12 * V_21 ;
unsigned short V_7 ;
if ( ! F_61 ( & V_92 -> V_30 -> V_137 ) )
return false ;
if ( ! F_77 ( V_50 , V_161 + V_66 ) )
return false ;
V_7 = F_74 ( V_50 , V_161 ) ;
V_21 = F_22 ( V_92 -> V_30 ,
V_92 -> V_16 , V_7 ) ;
if ( ! V_21 )
return false ;
F_10 ( V_21 ) ;
return true ;
}
void F_100 ( struct V_29 * V_30 )
{
struct V_52 * V_53 ;
F_101 ( & V_30 -> V_32 . V_84 ) ;
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
V_30 -> V_32 . V_138 ) )
return false ;
if ( F_80 ( V_30 -> V_32 . V_144 ,
V_162 ) )
return true ;
V_21 = F_43 ( V_30 ,
V_53 -> V_63 -> V_64 ,
V_7 , true ) ;
if ( F_51 ( ! V_21 ) )
return true ;
F_104 ( V_146 , & V_21 -> V_86 ) ;
return true ;
}
bool F_105 ( struct V_29 * V_30 , struct V_49 * V_50 ,
unsigned short V_7 , bool V_163 )
{
struct V_12 * V_21 ;
struct V_51 * V_51 ;
struct V_3 V_102 , * V_4 = NULL ;
struct V_52 * V_53 ;
bool V_164 ;
bool V_119 ;
V_51 = F_75 ( V_50 ) ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 )
goto V_165;
if ( ! F_61 ( & V_30 -> V_137 ) )
goto V_166;
if ( F_103 ( V_30 , V_50 , V_53 , V_7 ) )
goto V_165;
if ( F_51 ( F_61 ( & V_30 -> V_32 . V_100 ) ) )
if ( F_106 ( V_51 -> V_74 ) && V_163 )
goto V_165;
F_23 ( V_102 . V_6 , V_51 -> V_69 ) ;
V_102 . V_7 = V_7 ;
V_4 = F_17 ( V_30 , & V_102 ) ;
if ( ! V_4 ) {
F_30 ( V_70 , V_30 ,
L_28 ,
V_51 -> V_69 ,
F_107 ( V_30 ,
V_51 -> V_69 , V_7 ) ?
L_29 : L_30 ) ;
F_71 ( V_30 , V_53 ,
V_53 -> V_63 -> V_64 ,
V_51 -> V_69 , V_7 ) ;
goto V_166;
}
V_21 = F_63 ( V_4 ) ;
V_164 = F_6 ( V_21 -> V_16 ,
V_53 -> V_63 -> V_64 ) ;
F_10 ( V_21 ) ;
if ( V_164 ) {
V_4 -> V_95 = V_96 ;
goto V_166;
}
if ( F_106 ( V_51 -> V_74 ) && V_163 ) {
goto V_165;
} else {
F_71 ( V_30 , V_53 ,
V_53 -> V_63 -> V_64 ,
V_51 -> V_69 , V_7 ) ;
goto V_166;
}
V_166:
F_58 ( V_30 , V_53 , V_7 ) ;
V_119 = false ;
goto V_65;
V_165:
F_108 ( V_50 ) ;
V_119 = true ;
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
if ( V_4 )
F_16 ( V_4 ) ;
return V_119 ;
}
bool F_109 ( struct V_29 * V_30 , struct V_49 * V_50 ,
unsigned short V_7 )
{
struct V_51 * V_51 ;
struct V_3 V_102 , * V_4 = NULL ;
struct V_12 * V_21 ;
struct V_52 * V_53 ;
bool V_167 ;
bool V_119 = false ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 )
goto V_65;
if ( ! F_61 ( & V_30 -> V_137 ) )
goto V_166;
if ( F_73 ( V_30 , V_53 , V_50 ) )
goto V_165;
V_51 = F_75 ( V_50 ) ;
if ( F_51 ( F_61 ( & V_30 -> V_32 . V_100 ) ) )
if ( F_106 ( V_51 -> V_74 ) )
goto V_165;
F_23 ( V_102 . V_6 , V_51 -> V_69 ) ;
V_102 . V_7 = V_7 ;
V_4 = F_17 ( V_30 , & V_102 ) ;
if ( ! V_4 )
goto V_166;
V_21 = F_63 ( V_4 ) ;
V_167 = F_6 ( V_21 -> V_16 ,
V_53 -> V_63 -> V_64 ) ;
F_10 ( V_21 ) ;
if ( V_167 ) {
if ( F_80 ( V_4 -> V_95 , 100 ) ) {
F_30 ( V_70 , V_30 , L_31 ,
V_51 -> V_69 ) ;
F_70 ( V_30 , V_53 ,
V_53 -> V_63 -> V_64 ,
V_51 -> V_69 , V_7 ) ;
goto V_166;
} else {
F_30 ( V_70 , V_30 , L_32 ,
V_51 -> V_69 ) ;
goto V_165;
}
}
if ( F_106 ( V_51 -> V_74 ) ) {
goto V_165;
} else {
goto V_166;
}
V_166:
F_58 ( V_30 , V_53 , V_7 ) ;
V_119 = false ;
goto V_65;
V_165:
V_119 = true ;
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
if ( V_4 )
F_16 ( V_4 ) ;
return V_119 ;
}
int F_110 ( struct V_168 * V_169 , void * V_170 )
{
struct V_54 * V_63 = (struct V_54 * ) V_169 -> V_171 ;
struct V_29 * V_30 = F_85 ( V_63 ) ;
struct V_31 * V_5 = V_30 -> V_32 . V_33 ;
struct V_12 * V_21 ;
struct V_3 * V_4 ;
struct V_52 * V_53 ;
struct V_34 * V_35 ;
T_6 V_107 ;
T_1 V_43 ;
bool V_172 ;
T_2 * V_173 ;
V_53 = F_111 ( V_169 ) ;
if ( ! V_53 )
goto V_65;
V_173 = V_53 -> V_63 -> V_64 ;
F_112 ( V_169 ,
L_33 ,
V_63 -> V_174 , V_173 ,
F_67 ( V_30 -> V_32 . V_60 . V_112 ) ) ;
F_113 ( V_169 ,
L_34 ) ;
for ( V_43 = 0 ; V_43 < V_5 -> V_2 ; V_43 ++ ) {
V_35 = & V_5 -> V_38 [ V_43 ] ;
F_18 () ;
F_19 (claim, head, hash_entry) {
V_21 = F_63 ( V_4 ) ;
V_172 = F_6 ( V_21 -> V_16 ,
V_173 ) ;
F_13 ( & V_21 -> V_26 ) ;
V_107 = V_21 -> V_27 ;
F_14 ( & V_21 -> V_26 ) ;
F_112 ( V_169 , L_35 ,
V_4 -> V_6 , F_31 ( V_4 -> V_7 ) ,
V_21 -> V_16 ,
( V_172 ? 'x' : ' ' ) ,
V_107 ) ;
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
F_114 ( struct V_49 * V_175 , T_1 V_176 , T_1 V_169 ,
struct V_52 * V_53 ,
struct V_3 * V_4 )
{
T_2 * V_173 = V_53 -> V_63 -> V_64 ;
T_6 V_107 ;
bool V_172 ;
void * V_177 ;
int V_119 = - V_178 ;
V_177 = F_115 ( V_175 , V_176 , V_169 , & V_179 ,
V_180 , V_181 ) ;
if ( ! V_177 ) {
V_119 = - V_182 ;
goto V_65;
}
V_172 = F_6 ( V_4 -> V_21 -> V_16 ,
V_173 ) ;
F_13 ( & V_4 -> V_21 -> V_26 ) ;
V_107 = V_4 -> V_21 -> V_27 ;
F_14 ( & V_4 -> V_21 -> V_26 ) ;
if ( V_172 )
if ( F_116 ( V_175 , V_183 ) ) {
F_117 ( V_175 , V_177 ) ;
goto V_65;
}
if ( F_118 ( V_175 , V_184 , V_28 , V_4 -> V_6 ) ||
F_119 ( V_175 , V_185 , V_4 -> V_7 ) ||
F_118 ( V_175 , V_186 , V_28 ,
V_4 -> V_21 -> V_16 ) ||
F_119 ( V_175 , V_187 ,
V_107 ) ) {
F_117 ( V_175 , V_177 ) ;
goto V_65;
}
F_120 ( V_175 , V_177 ) ;
V_119 = 0 ;
V_65:
return V_119 ;
}
static int
F_121 ( struct V_49 * V_175 , T_1 V_176 , T_1 V_169 ,
struct V_52 * V_53 ,
struct V_34 * V_35 , int * V_188 )
{
struct V_3 * V_4 ;
int V_189 = 0 ;
F_18 () ;
F_19 (claim, head, hash_entry) {
if ( V_189 ++ < * V_188 )
continue;
if ( F_114 ( V_175 , V_176 , V_169 ,
V_53 , V_4 ) ) {
* V_188 = V_189 - 1 ;
goto V_190;
}
}
* V_188 = V_189 ;
V_190:
F_21 () ;
return 0 ;
}
int F_122 ( struct V_49 * V_175 , struct V_191 * V_192 )
{
struct V_52 * V_53 = NULL ;
int V_176 = F_123 ( V_192 -> V_50 ) . V_176 ;
struct V_193 * V_193 = F_124 ( V_192 -> V_50 -> V_194 ) ;
struct V_54 * V_55 ;
struct V_31 * V_5 ;
struct V_29 * V_30 ;
int V_195 = V_192 -> args [ 0 ] ;
struct V_34 * V_35 ;
int V_189 = V_192 -> args [ 1 ] ;
int V_196 ;
int V_119 = 0 ;
V_196 = F_125 ( V_192 -> V_197 ,
V_198 ) ;
if ( ! V_196 )
return - V_178 ;
V_55 = F_126 ( V_193 , V_196 ) ;
if ( ! V_55 || ! F_127 ( V_55 ) ) {
V_119 = - V_199 ;
goto V_65;
}
V_30 = F_85 ( V_55 ) ;
V_5 = V_30 -> V_32 . V_33 ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 || V_53 -> V_200 != V_201 ) {
V_119 = - V_202 ;
goto V_65;
}
while ( V_195 < V_5 -> V_2 ) {
V_35 = & V_5 -> V_38 [ V_195 ] ;
if ( F_121 ( V_175 , V_176 ,
V_192 -> V_197 -> V_203 ,
V_53 , V_35 , & V_189 ) )
break;
V_195 ++ ;
}
V_192 -> args [ 0 ] = V_195 ;
V_192 -> args [ 1 ] = V_189 ;
V_119 = V_175 -> V_82 ;
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
if ( V_55 )
F_128 ( V_55 ) ;
return V_119 ;
}
int F_129 ( struct V_168 * V_169 , void * V_170 )
{
struct V_54 * V_63 = (struct V_54 * ) V_169 -> V_171 ;
struct V_29 * V_30 = F_85 ( V_63 ) ;
struct V_31 * V_5 = V_30 -> V_32 . V_39 ;
struct V_12 * V_21 ;
struct V_52 * V_53 ;
struct V_34 * V_35 ;
int V_204 , V_205 ;
T_6 V_107 ;
T_1 V_43 ;
bool V_172 ;
T_2 * V_173 ;
V_53 = F_111 ( V_169 ) ;
if ( ! V_53 )
goto V_65;
V_173 = V_53 -> V_63 -> V_64 ;
F_112 ( V_169 ,
L_36 ,
V_63 -> V_174 , V_173 ,
F_67 ( V_30 -> V_32 . V_60 . V_112 ) ) ;
F_113 ( V_169 , L_37 ) ;
for ( V_43 = 0 ; V_43 < V_5 -> V_2 ; V_43 ++ ) {
V_35 = & V_5 -> V_38 [ V_43 ] ;
F_18 () ;
F_19 (backbone_gw, head, hash_entry) {
V_205 = F_130 ( V_96 -
V_21 -> V_95 ) ;
V_204 = V_205 / 1000 ;
V_205 = V_205 % 1000 ;
V_172 = F_6 ( V_21 -> V_16 ,
V_173 ) ;
if ( V_172 )
continue;
F_13 ( & V_21 -> V_26 ) ;
V_107 = V_21 -> V_27 ;
F_14 ( & V_21 -> V_26 ) ;
F_112 ( V_169 , L_38 ,
V_21 -> V_16 ,
F_31 ( V_21 -> V_7 ) , V_204 ,
V_205 , V_107 ) ;
}
F_21 () ;
}
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
return 0 ;
}
static int
F_131 ( struct V_49 * V_175 , T_1 V_176 , T_1 V_169 ,
struct V_52 * V_53 ,
struct V_12 * V_21 )
{
T_2 * V_173 = V_53 -> V_63 -> V_64 ;
T_6 V_107 ;
bool V_172 ;
int V_205 ;
void * V_177 ;
int V_119 = - V_178 ;
V_177 = F_115 ( V_175 , V_176 , V_169 , & V_179 ,
V_180 , V_206 ) ;
if ( ! V_177 ) {
V_119 = - V_182 ;
goto V_65;
}
V_172 = F_6 ( V_21 -> V_16 , V_173 ) ;
F_13 ( & V_21 -> V_26 ) ;
V_107 = V_21 -> V_27 ;
F_14 ( & V_21 -> V_26 ) ;
V_205 = F_130 ( V_96 - V_21 -> V_95 ) ;
if ( V_172 )
if ( F_116 ( V_175 , V_183 ) ) {
F_117 ( V_175 , V_177 ) ;
goto V_65;
}
if ( F_118 ( V_175 , V_186 , V_28 ,
V_21 -> V_16 ) ||
F_119 ( V_175 , V_185 , V_21 -> V_7 ) ||
F_119 ( V_175 , V_187 ,
V_107 ) ||
F_132 ( V_175 , V_207 , V_205 ) ) {
F_117 ( V_175 , V_177 ) ;
goto V_65;
}
F_120 ( V_175 , V_177 ) ;
V_119 = 0 ;
V_65:
return V_119 ;
}
static int
F_133 ( struct V_49 * V_175 , T_1 V_176 , T_1 V_169 ,
struct V_52 * V_53 ,
struct V_34 * V_35 , int * V_188 )
{
struct V_12 * V_21 ;
int V_189 = 0 ;
F_18 () ;
F_19 (backbone_gw, head, hash_entry) {
if ( V_189 ++ < * V_188 )
continue;
if ( F_131 ( V_175 , V_176 , V_169 ,
V_53 , V_21 ) ) {
* V_188 = V_189 - 1 ;
goto V_190;
}
}
* V_188 = V_189 ;
V_190:
F_21 () ;
return 0 ;
}
int F_134 ( struct V_49 * V_175 , struct V_191 * V_192 )
{
struct V_52 * V_53 = NULL ;
int V_176 = F_123 ( V_192 -> V_50 ) . V_176 ;
struct V_193 * V_193 = F_124 ( V_192 -> V_50 -> V_194 ) ;
struct V_54 * V_55 ;
struct V_31 * V_5 ;
struct V_29 * V_30 ;
int V_195 = V_192 -> args [ 0 ] ;
struct V_34 * V_35 ;
int V_189 = V_192 -> args [ 1 ] ;
int V_196 ;
int V_119 = 0 ;
V_196 = F_125 ( V_192 -> V_197 ,
V_198 ) ;
if ( ! V_196 )
return - V_178 ;
V_55 = F_126 ( V_193 , V_196 ) ;
if ( ! V_55 || ! F_127 ( V_55 ) ) {
V_119 = - V_199 ;
goto V_65;
}
V_30 = F_85 ( V_55 ) ;
V_5 = V_30 -> V_32 . V_39 ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 || V_53 -> V_200 != V_201 ) {
V_119 = - V_202 ;
goto V_65;
}
while ( V_195 < V_5 -> V_2 ) {
V_35 = & V_5 -> V_38 [ V_195 ] ;
if ( F_133 ( V_175 , V_176 ,
V_192 -> V_197 -> V_203 ,
V_53 , V_35 , & V_189 ) )
break;
V_195 ++ ;
}
V_192 -> args [ 0 ] = V_195 ;
V_192 -> args [ 1 ] = V_189 ;
V_119 = V_175 -> V_82 ;
V_65:
if ( V_53 )
F_39 ( V_53 ) ;
if ( V_55 )
F_128 ( V_55 ) ;
return V_119 ;
}
bool F_135 ( struct V_29 * V_30 ,
T_2 * V_6 , unsigned short V_7 )
{
struct V_3 V_102 ;
struct V_3 * V_4 = NULL ;
struct V_52 * V_53 = NULL ;
bool V_119 = true ;
if ( ! F_61 ( & V_30 -> V_137 ) )
return V_119 ;
V_53 = F_28 ( V_30 ) ;
if ( ! V_53 )
return V_119 ;
F_23 ( V_102 . V_6 , V_6 ) ;
V_102 . V_7 = V_7 ;
V_4 = F_17 ( V_30 , & V_102 ) ;
if ( V_4 ) {
if ( ! F_6 ( V_4 -> V_21 -> V_16 ,
V_53 -> V_63 -> V_64 ) )
V_119 = false ;
F_16 ( V_4 ) ;
}
F_39 ( V_53 ) ;
return V_119 ;
}
