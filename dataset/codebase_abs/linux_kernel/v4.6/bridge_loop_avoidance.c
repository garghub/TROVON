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
static int F_4 ( const struct V_8 * V_9 ,
const void * V_10 )
{
const void * V_11 = F_5 ( V_9 , struct V_12 ,
V_13 ) ;
const struct V_12 * V_14 = V_11 ;
const struct V_12 * V_15 = V_10 ;
if ( ! F_6 ( V_14 -> V_16 , V_15 -> V_16 ) )
return 0 ;
if ( V_14 -> V_7 != V_15 -> V_7 )
return 0 ;
return 1 ;
}
static int F_7 ( const struct V_8 * V_9 ,
const void * V_10 )
{
const void * V_11 = F_5 ( V_9 , struct V_3 ,
V_13 ) ;
const struct V_3 * V_17 = V_11 ;
const struct V_3 * V_18 = V_10 ;
if ( ! F_6 ( V_17 -> V_6 , V_18 -> V_6 ) )
return 0 ;
if ( V_17 -> V_7 != V_18 -> V_7 )
return 0 ;
return 1 ;
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
V_4 = F_5 ( V_20 , struct V_3 , V_22 ) ;
F_10 ( V_4 -> V_21 ) ;
F_9 ( V_4 , V_23 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
F_11 ( & V_4 -> V_22 , F_12 ) ;
}
static struct V_3
* F_14 ( struct V_24 * V_25 ,
struct V_3 * V_1 )
{
struct V_26 * V_5 = V_25 -> V_27 . V_28 ;
struct V_29 * V_30 ;
struct V_3 * V_4 ;
struct V_3 * V_31 = NULL ;
int V_32 ;
if ( ! V_5 )
return NULL ;
V_32 = F_1 ( V_1 , V_5 -> V_2 ) ;
V_30 = & V_5 -> V_33 [ V_32 ] ;
F_15 () ;
F_16 (claim, head, hash_entry) {
if ( ! F_7 ( & V_4 -> V_13 , V_1 ) )
continue;
if ( ! F_17 ( & V_4 -> V_22 ) )
continue;
V_31 = V_4 ;
break;
}
F_18 () ;
return V_31 ;
}
static struct V_12 *
F_19 ( struct V_24 * V_25 , T_2 * V_6 ,
unsigned short V_7 )
{
struct V_26 * V_5 = V_25 -> V_27 . V_34 ;
struct V_29 * V_30 ;
struct V_12 V_35 , * V_21 ;
struct V_12 * V_36 = NULL ;
int V_32 ;
if ( ! V_5 )
return NULL ;
F_20 ( V_35 . V_16 , V_6 ) ;
V_35 . V_7 = V_7 ;
V_32 = F_3 ( & V_35 , V_5 -> V_2 ) ;
V_30 = & V_5 -> V_33 [ V_32 ] ;
F_15 () ;
F_16 (backbone_gw, head, hash_entry) {
if ( ! F_4 ( & V_21 -> V_13 ,
& V_35 ) )
continue;
if ( ! F_17 ( & V_21 -> V_22 ) )
continue;
V_36 = V_21 ;
break;
}
F_18 () ;
return V_36 ;
}
static void
F_21 ( struct V_12 * V_21 )
{
struct V_26 * V_5 ;
struct V_8 * V_37 ;
struct V_29 * V_30 ;
struct V_3 * V_4 ;
int V_38 ;
T_3 * V_39 ;
V_5 = V_21 -> V_25 -> V_27 . V_28 ;
if ( ! V_5 )
return;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_30 = & V_5 -> V_33 [ V_38 ] ;
V_39 = & V_5 -> V_40 [ V_38 ] ;
F_22 ( V_39 ) ;
F_23 (claim, node_tmp,
head, hash_entry) {
if ( V_4 -> V_21 != V_21 )
continue;
F_13 ( V_4 ) ;
F_24 ( & V_4 -> V_13 ) ;
}
F_25 ( V_39 ) ;
}
F_22 ( & V_21 -> V_41 ) ;
V_21 -> V_42 = V_43 ;
F_25 ( & V_21 -> V_41 ) ;
}
static void F_26 ( struct V_24 * V_25 , T_2 * V_44 ,
unsigned short V_7 , int V_45 )
{
struct V_46 * V_47 ;
struct V_48 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
T_2 * V_53 ;
struct V_54 V_55 ;
T_4 V_56 = 0 ;
V_50 = F_27 ( V_25 ) ;
if ( ! V_50 )
return;
memcpy ( & V_55 , & V_25 -> V_27 . V_57 ,
sizeof( V_55 ) ) ;
V_55 . type = V_45 ;
V_52 = V_50 -> V_52 ;
V_47 = F_28 ( V_58 , V_59 ,
V_56 ,
V_50 -> V_52 ,
V_56 ,
NULL ,
V_50 -> V_60 -> V_61 ,
( T_2 * ) & V_55 ) ;
if ( ! V_47 )
goto V_62;
V_48 = (struct V_48 * ) V_47 -> V_1 ;
V_53 = ( T_2 * ) V_48 + V_63 + sizeof( struct V_64 ) ;
switch ( V_45 ) {
case V_65 :
F_20 ( V_48 -> V_66 , V_44 ) ;
F_29 ( V_67 , V_25 ,
L_1 , V_44 ,
F_30 ( V_7 ) ) ;
break;
case V_68 :
F_20 ( V_53 , V_44 ) ;
F_29 ( V_67 , V_25 ,
L_2 , V_44 ,
F_30 ( V_7 ) ) ;
break;
case V_69 :
F_20 ( V_53 , V_44 ) ;
F_29 ( V_67 , V_25 ,
L_3 ,
V_48 -> V_66 , F_30 ( V_7 ) ) ;
break;
case V_70 :
F_20 ( V_53 , V_44 ) ;
F_20 ( V_48 -> V_71 , V_44 ) ;
F_29 ( V_67 , V_25 ,
L_4 ,
V_48 -> V_66 , V_48 -> V_71 ,
F_30 ( V_7 ) ) ;
break;
}
if ( V_7 & V_72 )
V_47 = F_31 ( V_47 , F_32 ( V_73 ) ,
V_7 & V_74 ) ;
F_33 ( V_47 ) ;
V_47 -> V_75 = F_34 ( V_47 , V_52 ) ;
F_35 ( V_25 , V_76 ) ;
F_36 ( V_25 , V_77 ,
V_47 -> V_78 + V_63 ) ;
V_52 -> V_79 = V_80 ;
F_37 ( V_47 ) ;
V_62:
if ( V_50 )
F_38 ( V_50 ) ;
}
static struct V_12 *
F_39 ( struct V_24 * V_25 , T_2 * V_16 ,
unsigned short V_7 , bool V_81 )
{
struct V_12 * V_82 ;
struct V_83 * V_84 ;
int V_85 ;
V_82 = F_19 ( V_25 , V_16 , V_7 ) ;
if ( V_82 )
return V_82 ;
F_29 ( V_67 , V_25 ,
L_5 ,
V_16 , F_30 ( V_7 ) ) ;
V_82 = F_40 ( sizeof( * V_82 ) , V_86 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_7 = V_7 ;
V_82 -> V_87 = V_80 ;
V_82 -> V_42 = V_43 ;
V_82 -> V_25 = V_25 ;
F_41 ( & V_82 -> V_41 ) ;
F_42 ( & V_82 -> V_88 , 0 ) ;
F_42 ( & V_82 -> V_89 , 0 ) ;
F_20 ( V_82 -> V_16 , V_16 ) ;
F_43 ( & V_82 -> V_22 ) ;
F_44 ( & V_82 -> V_22 ) ;
V_85 = F_45 ( V_25 -> V_27 . V_34 ,
F_4 ,
F_3 , V_82 ,
& V_82 -> V_13 ) ;
if ( F_46 ( V_85 != 0 ) ) {
F_47 ( V_82 ) ;
return NULL ;
}
V_84 = F_48 ( V_25 , V_16 ) ;
if ( V_84 ) {
F_49 ( V_25 , V_84 , V_7 ,
L_6 ) ;
F_50 ( V_84 ) ;
}
if ( V_81 ) {
F_51 ( V_25 , V_82 ) ;
F_52 ( & V_82 -> V_88 ) ;
F_42 ( & V_82 -> V_89 , V_90 ) ;
F_52 ( & V_25 -> V_27 . V_91 ) ;
}
return V_82 ;
}
static void
F_53 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
unsigned short V_7 )
{
struct V_12 * V_21 ;
V_21 = F_39 ( V_25 ,
V_50 -> V_60 -> V_61 ,
V_7 , true ) ;
if ( F_46 ( ! V_21 ) )
return;
V_21 -> V_87 = V_80 ;
F_10 ( V_21 ) ;
}
static void F_54 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
unsigned short V_7 )
{
struct V_29 * V_30 ;
struct V_26 * V_5 ;
struct V_3 * V_4 ;
struct V_12 * V_21 ;
int V_38 ;
F_29 ( V_67 , V_25 ,
L_7 ) ;
V_21 = F_19 ( V_25 ,
V_50 -> V_60 -> V_61 ,
V_7 ) ;
if ( ! V_21 )
return;
V_5 = V_25 -> V_27 . V_28 ;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_30 = & V_5 -> V_33 [ V_38 ] ;
F_15 () ;
F_16 (claim, head, hash_entry) {
if ( V_4 -> V_21 != V_21 )
continue;
F_26 ( V_25 , V_4 -> V_6 , V_4 -> V_7 ,
V_65 ) ;
}
F_18 () ;
}
F_51 ( V_25 , V_21 ) ;
F_10 ( V_21 ) ;
}
static void F_55 ( struct V_12 * V_21 )
{
F_21 ( V_21 ) ;
F_29 ( V_67 , V_21 -> V_25 ,
L_8 , V_21 -> V_16 ) ;
F_26 ( V_21 -> V_25 , V_21 -> V_16 ,
V_21 -> V_7 , V_70 ) ;
if ( ! F_56 ( & V_21 -> V_88 ) ) {
F_52 ( & V_21 -> V_25 -> V_27 . V_91 ) ;
F_42 ( & V_21 -> V_88 , 1 ) ;
}
}
static void F_51 ( struct V_24 * V_25 ,
struct V_12 * V_21 )
{
T_2 V_44 [ V_92 ] ;
T_5 V_42 ;
memcpy ( V_44 , V_93 , 4 ) ;
F_22 ( & V_21 -> V_41 ) ;
V_42 = F_32 ( V_21 -> V_42 ) ;
F_25 ( & V_21 -> V_41 ) ;
memcpy ( & V_44 [ 4 ] , & V_42 , 2 ) ;
F_26 ( V_25 , V_44 , V_21 -> V_7 ,
V_69 ) ;
}
static void F_57 ( struct V_24 * V_25 ,
const T_2 * V_44 , const unsigned short V_7 ,
struct V_12 * V_21 )
{
struct V_3 * V_4 ;
struct V_3 V_94 ;
int V_85 ;
F_20 ( V_94 . V_6 , V_44 ) ;
V_94 . V_7 = V_7 ;
V_4 = F_14 ( V_25 , & V_94 ) ;
if ( ! V_4 ) {
V_4 = F_40 ( sizeof( * V_4 ) , V_86 ) ;
if ( ! V_4 )
return;
F_20 ( V_4 -> V_6 , V_44 ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_87 = V_80 ;
V_4 -> V_21 = V_21 ;
F_43 ( & V_4 -> V_22 ) ;
F_44 ( & V_4 -> V_22 ) ;
F_29 ( V_67 , V_25 ,
L_9 ,
V_44 , F_30 ( V_7 ) ) ;
V_85 = F_45 ( V_25 -> V_27 . V_28 ,
F_7 ,
F_1 , V_4 ,
& V_4 -> V_13 ) ;
if ( F_46 ( V_85 != 0 ) ) {
F_47 ( V_4 ) ;
return;
}
} else {
V_4 -> V_87 = V_80 ;
if ( V_4 -> V_21 == V_21 )
goto V_95;
F_29 ( V_67 , V_25 ,
L_10 ,
V_44 , F_30 ( V_7 ) ) ;
F_22 ( & V_4 -> V_21 -> V_41 ) ;
V_4 -> V_21 -> V_42 ^= F_58 ( 0 , V_4 -> V_6 , V_92 ) ;
F_25 ( & V_4 -> V_21 -> V_41 ) ;
F_10 ( V_4 -> V_21 ) ;
}
F_44 ( & V_21 -> V_22 ) ;
V_4 -> V_21 = V_21 ;
F_22 ( & V_21 -> V_41 ) ;
V_21 -> V_42 ^= F_58 ( 0 , V_4 -> V_6 , V_92 ) ;
F_25 ( & V_21 -> V_41 ) ;
V_21 -> V_87 = V_80 ;
V_95:
F_13 ( V_4 ) ;
}
static void F_59 ( struct V_24 * V_25 ,
const T_2 * V_44 , const unsigned short V_7 )
{
struct V_3 V_94 , * V_4 ;
F_20 ( V_94 . V_6 , V_44 ) ;
V_94 . V_7 = V_7 ;
V_4 = F_14 ( V_25 , & V_94 ) ;
if ( ! V_4 )
return;
F_29 ( V_67 , V_25 , L_11 ,
V_44 , F_30 ( V_7 ) ) ;
F_60 ( V_25 -> V_27 . V_28 , F_7 ,
F_1 , V_4 ) ;
F_13 ( V_4 ) ;
F_22 ( & V_4 -> V_21 -> V_41 ) ;
V_4 -> V_21 -> V_42 ^= F_58 ( 0 , V_4 -> V_6 , V_92 ) ;
F_25 ( & V_4 -> V_21 -> V_41 ) ;
F_13 ( V_4 ) ;
}
static int F_61 ( struct V_24 * V_25 , T_2 * V_96 ,
T_2 * V_97 , unsigned short V_7 )
{
struct V_12 * V_21 ;
T_6 V_98 , V_42 ;
if ( memcmp ( V_96 , V_93 , 4 ) != 0 )
return 0 ;
V_21 = F_39 ( V_25 , V_97 , V_7 ,
false ) ;
if ( F_46 ( ! V_21 ) )
return 1 ;
V_21 -> V_87 = V_80 ;
V_42 = F_62 ( * ( ( T_5 * ) ( & V_96 [ 4 ] ) ) ) ;
F_29 ( V_67 , V_25 ,
L_12 ,
F_30 ( V_7 ) , V_21 -> V_16 , V_42 ) ;
F_22 ( & V_21 -> V_41 ) ;
V_98 = V_21 -> V_42 ;
F_25 ( & V_21 -> V_41 ) ;
if ( V_98 != V_42 ) {
F_29 ( V_67 , V_21 -> V_25 ,
L_13 ,
V_21 -> V_16 ,
F_30 ( V_21 -> V_7 ) ,
V_98 , V_42 ) ;
F_55 ( V_21 ) ;
} else {
if ( F_56 ( & V_21 -> V_88 ) ) {
F_63 ( & V_21 -> V_25 -> V_27 . V_91 ) ;
F_42 ( & V_21 -> V_88 , 0 ) ;
}
}
F_10 ( V_21 ) ;
return 1 ;
}
static int F_64 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
T_2 * V_97 , struct V_48 * V_48 ,
unsigned short V_7 )
{
if ( ! F_6 ( V_97 , V_48 -> V_71 ) )
return 0 ;
if ( ! F_6 ( V_48 -> V_71 , V_50 -> V_60 -> V_61 ) )
return 1 ;
F_29 ( V_67 , V_25 ,
L_14 ,
F_30 ( V_7 ) , V_48 -> V_66 ) ;
F_54 ( V_25 , V_50 , V_7 ) ;
return 1 ;
}
static int F_65 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
T_2 * V_97 , T_2 * V_99 ,
unsigned short V_7 )
{
struct V_12 * V_21 ;
if ( V_50 && F_6 ( V_97 ,
V_50 -> V_60 -> V_61 ) )
F_26 ( V_25 , V_99 , V_7 ,
V_68 ) ;
V_21 = F_19 ( V_25 , V_97 , V_7 ) ;
if ( ! V_21 )
return 1 ;
F_29 ( V_67 , V_25 ,
L_15 ,
V_99 , F_30 ( V_7 ) , V_21 -> V_16 ) ;
F_59 ( V_25 , V_99 , V_7 ) ;
F_10 ( V_21 ) ;
return 1 ;
}
static int F_66 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
T_2 * V_97 , T_2 * V_99 ,
unsigned short V_7 )
{
struct V_12 * V_21 ;
V_21 = F_39 ( V_25 , V_97 , V_7 ,
false ) ;
if ( F_46 ( ! V_21 ) )
return 1 ;
F_57 ( V_25 , V_99 , V_7 , V_21 ) ;
if ( F_6 ( V_97 , V_50 -> V_60 -> V_61 ) )
F_26 ( V_25 , V_99 , V_7 ,
V_65 ) ;
F_10 ( V_21 ) ;
return 1 ;
}
static int F_67 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
T_2 * V_53 , T_2 * V_100 ,
struct V_48 * V_48 )
{
T_2 * V_97 ;
struct V_83 * V_84 ;
struct V_54 * V_101 , * V_102 ;
V_101 = (struct V_54 * ) V_100 ;
V_102 = & V_25 -> V_27 . V_57 ;
switch ( V_101 -> type ) {
case V_65 :
V_97 = V_53 ;
break;
case V_70 :
case V_69 :
case V_68 :
V_97 = V_48 -> V_66 ;
break;
default:
return 0 ;
}
if ( F_6 ( V_97 , V_50 -> V_60 -> V_61 ) )
return 0 ;
if ( V_101 -> V_103 == V_102 -> V_103 )
return 2 ;
V_84 = F_48 ( V_25 , V_97 ) ;
if ( ! V_84 )
return 1 ;
if ( F_62 ( V_101 -> V_103 ) > F_62 ( V_102 -> V_103 ) ) {
F_29 ( V_67 , V_25 ,
L_16 ,
F_62 ( V_101 -> V_103 ) ) ;
V_102 -> V_103 = V_101 -> V_103 ;
}
F_50 ( V_84 ) ;
return 2 ;
}
static int F_68 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_46 * V_47 )
{
struct V_54 * V_101 , * V_102 ;
T_2 * V_53 , * V_100 ;
struct V_104 * V_105 , V_106 ;
struct V_48 * V_48 ;
struct V_64 * V_64 ;
unsigned short V_7 ;
int V_107 = 0 ;
T_5 V_108 ;
int V_109 ;
int V_110 ;
V_7 = F_69 ( V_47 , 0 ) ;
V_48 = F_70 ( V_47 ) ;
V_108 = V_48 -> V_111 ;
V_109 = V_63 ;
if ( V_7 & V_72 ) {
do {
V_105 = F_71 ( V_47 , V_109 , V_112 ,
& V_106 ) ;
if ( ! V_105 )
return 0 ;
V_108 = V_105 -> V_113 ;
V_109 += V_112 ;
V_107 ++ ;
} while ( V_108 == F_32 ( V_73 ) );
}
if ( V_108 != F_32 ( V_59 ) )
return 0 ;
if ( F_46 ( ! F_72 ( V_47 , V_109 + F_73 ( V_47 -> V_114 ) ) ) )
return 0 ;
V_48 = F_70 ( V_47 ) ;
V_64 = (struct V_64 * ) ( ( T_2 * ) V_48 + V_109 ) ;
if ( V_64 -> V_115 != F_32 ( V_116 ) )
return 0 ;
if ( V_64 -> V_117 != F_32 ( V_118 ) )
return 0 ;
if ( V_64 -> V_119 != V_92 )
return 0 ;
if ( V_64 -> V_120 != 4 )
return 0 ;
V_53 = ( T_2 * ) V_64 + sizeof( struct V_64 ) ;
V_100 = V_53 + V_92 + 4 ;
V_101 = (struct V_54 * ) V_100 ;
V_102 = & V_25 -> V_27 . V_57 ;
if ( memcmp ( V_101 -> V_121 , V_102 -> V_121 ,
sizeof( V_101 -> V_121 ) ) != 0 )
return 0 ;
if ( V_107 > 1 )
return 1 ;
V_110 = F_67 ( V_25 , V_50 , V_53 , V_100 ,
V_48 ) ;
if ( V_110 == 1 )
F_29 ( V_67 , V_25 ,
L_17 ,
V_48 -> V_66 , F_30 ( V_7 ) , V_53 ,
V_100 ) ;
if ( V_110 < 2 )
return V_110 ;
F_53 ( V_25 , V_50 , V_7 ) ;
switch ( V_101 -> type ) {
case V_65 :
if ( F_66 ( V_25 , V_50 , V_53 ,
V_48 -> V_66 , V_7 ) )
return 1 ;
break;
case V_68 :
if ( F_65 ( V_25 , V_50 ,
V_48 -> V_66 , V_53 , V_7 ) )
return 1 ;
break;
case V_69 :
if ( F_61 ( V_25 , V_53 , V_48 -> V_66 ,
V_7 ) )
return 1 ;
break;
case V_70 :
if ( F_64 ( V_25 , V_50 , V_53 , V_48 ,
V_7 ) )
return 1 ;
break;
}
F_29 ( V_67 , V_25 ,
L_18 ,
V_48 -> V_66 , F_30 ( V_7 ) , V_53 , V_100 ) ;
return 1 ;
}
static void F_74 ( struct V_24 * V_25 , int V_122 )
{
struct V_12 * V_21 ;
struct V_8 * V_37 ;
struct V_29 * V_30 ;
struct V_26 * V_5 ;
T_3 * V_39 ;
int V_38 ;
V_5 = V_25 -> V_27 . V_34 ;
if ( ! V_5 )
return;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_30 = & V_5 -> V_33 [ V_38 ] ;
V_39 = & V_5 -> V_40 [ V_38 ] ;
F_22 ( V_39 ) ;
F_23 (backbone_gw, node_tmp,
head, hash_entry) {
if ( V_122 )
goto V_123;
if ( ! F_75 ( V_21 -> V_87 ,
V_124 ) )
continue;
F_29 ( V_67 , V_21 -> V_25 ,
L_19 ,
V_21 -> V_16 ) ;
V_123:
if ( F_56 ( & V_21 -> V_88 ) )
F_63 ( & V_25 -> V_27 . V_91 ) ;
F_21 ( V_21 ) ;
F_24 ( & V_21 -> V_13 ) ;
F_10 ( V_21 ) ;
}
F_25 ( V_39 ) ;
}
}
static void F_76 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
int V_122 )
{
struct V_3 * V_4 ;
struct V_29 * V_30 ;
struct V_26 * V_5 ;
int V_38 ;
V_5 = V_25 -> V_27 . V_28 ;
if ( ! V_5 )
return;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_30 = & V_5 -> V_33 [ V_38 ] ;
F_15 () ;
F_16 (claim, head, hash_entry) {
if ( V_122 )
goto V_123;
if ( ! F_6 ( V_4 -> V_21 -> V_16 ,
V_50 -> V_60 -> V_61 ) )
continue;
if ( ! F_75 ( V_4 -> V_87 ,
V_125 ) )
continue;
F_29 ( V_67 , V_25 ,
L_20 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
V_123:
F_65 ( V_25 , V_50 ,
V_4 -> V_21 -> V_16 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
}
F_18 () ;
}
}
void F_77 ( struct V_24 * V_25 ,
struct V_49 * V_50 ,
struct V_49 * V_126 )
{
struct V_12 * V_21 ;
struct V_29 * V_30 ;
struct V_26 * V_5 ;
T_5 V_103 ;
int V_38 ;
V_103 = F_32 ( F_58 ( 0 , V_50 -> V_60 -> V_61 , V_92 ) ) ;
V_25 -> V_27 . V_57 . V_103 = V_103 ;
if ( ! F_56 ( & V_25 -> V_127 ) )
V_126 = NULL ;
if ( ! V_126 ) {
F_76 ( V_25 , NULL , 1 ) ;
F_74 ( V_25 , 1 ) ;
return;
}
V_5 = V_25 -> V_27 . V_34 ;
if ( ! V_5 )
return;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_30 = & V_5 -> V_33 [ V_38 ] ;
F_15 () ;
F_16 (backbone_gw, head, hash_entry) {
if ( ! F_6 ( V_21 -> V_16 ,
V_126 -> V_60 -> V_61 ) )
continue;
F_20 ( V_21 -> V_16 ,
V_50 -> V_60 -> V_61 ) ;
F_51 ( V_25 , V_21 ) ;
}
F_18 () ;
}
}
void F_78 ( struct V_51 * V_60 )
{
struct V_24 * V_25 = F_79 ( V_60 ) ;
struct V_49 * V_50 ;
V_50 = F_27 ( V_25 ) ;
if ( ! V_50 )
return;
F_77 ( V_25 , V_50 , V_50 ) ;
F_38 ( V_50 ) ;
}
static void F_80 ( struct V_128 * V_129 )
{
struct V_130 * V_130 ;
struct V_24 * V_25 ;
struct V_131 * V_132 ;
struct V_29 * V_30 ;
struct V_12 * V_21 ;
struct V_26 * V_5 ;
struct V_49 * V_50 ;
int V_38 ;
V_130 = F_5 ( V_129 , struct V_130 , V_129 ) ;
V_132 = F_5 ( V_130 , struct V_131 , V_129 ) ;
V_25 = F_5 ( V_132 , struct V_24 , V_27 ) ;
V_50 = F_27 ( V_25 ) ;
if ( ! V_50 )
goto V_62;
F_76 ( V_25 , V_50 , 0 ) ;
F_74 ( V_25 , 0 ) ;
if ( ! F_56 ( & V_25 -> V_127 ) )
goto V_62;
V_5 = V_25 -> V_27 . V_34 ;
if ( ! V_5 )
goto V_62;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_30 = & V_5 -> V_33 [ V_38 ] ;
F_15 () ;
F_16 (backbone_gw, head, hash_entry) {
if ( ! F_6 ( V_21 -> V_16 ,
V_50 -> V_60 -> V_61 ) )
continue;
V_21 -> V_87 = V_80 ;
F_51 ( V_25 , V_21 ) ;
if ( F_56 ( & V_21 -> V_88 ) == 0 )
continue;
if ( ! F_81 ( & V_21 -> V_89 ) )
continue;
F_63 ( & V_21 -> V_25 -> V_27 . V_91 ) ;
F_42 ( & V_21 -> V_88 , 0 ) ;
}
F_18 () ;
}
V_62:
if ( V_50 )
F_38 ( V_50 ) ;
F_82 ( V_133 , & V_25 -> V_27 . V_129 ,
F_83 ( V_134 ) ) ;
}
int F_84 ( struct V_24 * V_25 )
{
int V_38 ;
T_2 V_57 [ V_92 ] = { 0xff , 0x43 , 0x05 , 0x00 , 0x00 , 0x00 } ;
struct V_49 * V_50 ;
T_6 V_42 ;
unsigned long V_135 ;
F_41 ( & V_25 -> V_27 . V_136 ) ;
F_29 ( V_67 , V_25 , L_21 ) ;
memcpy ( & V_25 -> V_27 . V_57 . V_121 , V_57 , 3 ) ;
V_25 -> V_27 . V_57 . type = 0 ;
V_50 = F_27 ( V_25 ) ;
if ( V_50 ) {
V_42 = F_58 ( 0 , V_50 -> V_60 -> V_61 , V_92 ) ;
V_25 -> V_27 . V_57 . V_103 = F_32 ( V_42 ) ;
F_38 ( V_50 ) ;
} else {
V_25 -> V_27 . V_57 . V_103 = 0 ;
}
V_135 = V_80 - F_83 ( V_137 ) ;
for ( V_38 = 0 ; V_38 < V_138 ; V_38 ++ )
V_25 -> V_27 . V_139 [ V_38 ] . V_135 = V_135 ;
V_25 -> V_27 . V_140 = 0 ;
if ( V_25 -> V_27 . V_28 )
return 0 ;
V_25 -> V_27 . V_28 = F_85 ( 128 ) ;
V_25 -> V_27 . V_34 = F_85 ( 32 ) ;
if ( ! V_25 -> V_27 . V_28 || ! V_25 -> V_27 . V_34 )
return - V_141 ;
F_86 ( V_25 -> V_27 . V_28 ,
& V_142 ) ;
F_86 ( V_25 -> V_27 . V_34 ,
& V_143 ) ;
F_29 ( V_67 , V_25 , L_22 ) ;
F_87 ( & V_25 -> V_27 . V_129 , F_80 ) ;
F_82 ( V_133 , & V_25 -> V_27 . V_129 ,
F_83 ( V_134 ) ) ;
return 0 ;
}
int F_88 ( struct V_24 * V_25 ,
struct V_46 * V_47 )
{
int V_38 , V_144 , V_110 = 0 ;
T_4 V_42 ;
struct V_145 * V_146 ;
struct V_147 * V_82 ;
V_146 = (struct V_145 * ) V_47 -> V_1 ;
V_42 = F_89 ( V_47 , ( T_2 * ) ( V_146 + 1 ) ) ;
F_22 ( & V_25 -> V_27 . V_136 ) ;
for ( V_38 = 0 ; V_38 < V_138 ; V_38 ++ ) {
V_144 = ( V_25 -> V_27 . V_140 + V_38 ) ;
V_144 %= V_138 ;
V_82 = & V_25 -> V_27 . V_139 [ V_144 ] ;
if ( F_75 ( V_82 -> V_135 ,
V_137 ) )
break;
if ( V_82 -> V_42 != V_42 )
continue;
if ( F_6 ( V_82 -> V_16 , V_146 -> V_16 ) )
continue;
V_110 = 1 ;
goto V_62;
}
V_144 = ( V_25 -> V_27 . V_140 + V_138 - 1 ) ;
V_144 %= V_138 ;
V_82 = & V_25 -> V_27 . V_139 [ V_144 ] ;
V_82 -> V_42 = V_42 ;
V_82 -> V_135 = V_80 ;
F_20 ( V_82 -> V_16 , V_146 -> V_16 ) ;
V_25 -> V_27 . V_140 = V_144 ;
V_62:
F_25 ( & V_25 -> V_27 . V_136 ) ;
return V_110 ;
}
bool F_90 ( struct V_24 * V_25 , T_2 * V_16 ,
unsigned short V_7 )
{
struct V_26 * V_5 = V_25 -> V_27 . V_34 ;
struct V_29 * V_30 ;
struct V_12 * V_21 ;
int V_38 ;
if ( ! F_56 ( & V_25 -> V_127 ) )
return false ;
if ( ! V_5 )
return false ;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_30 = & V_5 -> V_33 [ V_38 ] ;
F_15 () ;
F_16 (backbone_gw, head, hash_entry) {
if ( F_6 ( V_21 -> V_16 , V_16 ) &&
V_21 -> V_7 == V_7 ) {
F_18 () ;
return true ;
}
}
F_18 () ;
}
return false ;
}
int F_91 ( struct V_46 * V_47 ,
struct V_83 * V_84 , int V_148 )
{
struct V_12 * V_21 ;
unsigned short V_7 ;
if ( ! F_56 ( & V_84 -> V_25 -> V_127 ) )
return 0 ;
if ( ! F_72 ( V_47 , V_148 + V_63 ) )
return 0 ;
V_7 = F_69 ( V_47 , V_148 ) ;
V_21 = F_19 ( V_84 -> V_25 ,
V_84 -> V_16 , V_7 ) ;
if ( ! V_21 )
return 0 ;
F_10 ( V_21 ) ;
return 1 ;
}
void F_92 ( struct V_24 * V_25 )
{
struct V_49 * V_50 ;
F_93 ( & V_25 -> V_27 . V_129 ) ;
V_50 = F_27 ( V_25 ) ;
if ( V_25 -> V_27 . V_28 ) {
F_76 ( V_25 , V_50 , 1 ) ;
F_94 ( V_25 -> V_27 . V_28 ) ;
V_25 -> V_27 . V_28 = NULL ;
}
if ( V_25 -> V_27 . V_34 ) {
F_74 ( V_25 , 1 ) ;
F_94 ( V_25 -> V_27 . V_34 ) ;
V_25 -> V_27 . V_34 = NULL ;
}
if ( V_50 )
F_38 ( V_50 ) ;
}
int F_95 ( struct V_24 * V_25 , struct V_46 * V_47 ,
unsigned short V_7 , bool V_149 )
{
struct V_48 * V_48 ;
struct V_3 V_94 , * V_4 = NULL ;
struct V_49 * V_50 ;
int V_110 ;
V_48 = F_70 ( V_47 ) ;
V_50 = F_27 ( V_25 ) ;
if ( ! V_50 )
goto V_150;
if ( ! F_56 ( & V_25 -> V_127 ) )
goto V_151;
if ( F_46 ( F_56 ( & V_25 -> V_27 . V_91 ) ) )
if ( F_96 ( V_48 -> V_71 ) && V_149 )
goto V_150;
F_20 ( V_94 . V_6 , V_48 -> V_66 ) ;
V_94 . V_7 = V_7 ;
V_4 = F_14 ( V_25 , & V_94 ) ;
if ( ! V_4 ) {
F_66 ( V_25 , V_50 ,
V_50 -> V_60 -> V_61 ,
V_48 -> V_66 , V_7 ) ;
goto V_151;
}
if ( F_6 ( V_4 -> V_21 -> V_16 ,
V_50 -> V_60 -> V_61 ) ) {
V_4 -> V_87 = V_80 ;
goto V_151;
}
if ( F_96 ( V_48 -> V_71 ) && V_149 ) {
goto V_150;
} else {
F_66 ( V_25 , V_50 ,
V_50 -> V_60 -> V_61 ,
V_48 -> V_66 , V_7 ) ;
goto V_151;
}
V_151:
F_53 ( V_25 , V_50 , V_7 ) ;
V_110 = 0 ;
goto V_62;
V_150:
F_97 ( V_47 ) ;
V_110 = 1 ;
V_62:
if ( V_50 )
F_38 ( V_50 ) ;
if ( V_4 )
F_13 ( V_4 ) ;
return V_110 ;
}
int F_98 ( struct V_24 * V_25 , struct V_46 * V_47 ,
unsigned short V_7 )
{
struct V_48 * V_48 ;
struct V_3 V_94 , * V_4 = NULL ;
struct V_49 * V_50 ;
int V_110 = 0 ;
V_50 = F_27 ( V_25 ) ;
if ( ! V_50 )
goto V_62;
if ( ! F_56 ( & V_25 -> V_127 ) )
goto V_151;
if ( F_68 ( V_25 , V_50 , V_47 ) )
goto V_150;
V_48 = F_70 ( V_47 ) ;
if ( F_46 ( F_56 ( & V_25 -> V_27 . V_91 ) ) )
if ( F_96 ( V_48 -> V_71 ) )
goto V_150;
F_20 ( V_94 . V_6 , V_48 -> V_66 ) ;
V_94 . V_7 = V_7 ;
V_4 = F_14 ( V_25 , & V_94 ) ;
if ( ! V_4 )
goto V_151;
if ( F_6 ( V_4 -> V_21 -> V_16 ,
V_50 -> V_60 -> V_61 ) ) {
F_65 ( V_25 , V_50 ,
V_50 -> V_60 -> V_61 ,
V_48 -> V_66 , V_7 ) ;
goto V_151;
}
if ( F_96 ( V_48 -> V_71 ) ) {
goto V_150;
} else {
goto V_151;
}
V_151:
F_53 ( V_25 , V_50 , V_7 ) ;
V_110 = 0 ;
goto V_62;
V_150:
V_110 = 1 ;
V_62:
if ( V_50 )
F_38 ( V_50 ) ;
if ( V_4 )
F_13 ( V_4 ) ;
return V_110 ;
}
int F_99 ( struct V_152 * V_153 , void * V_154 )
{
struct V_51 * V_60 = (struct V_51 * ) V_153 -> V_155 ;
struct V_24 * V_25 = F_79 ( V_60 ) ;
struct V_26 * V_5 = V_25 -> V_27 . V_28 ;
struct V_3 * V_4 ;
struct V_49 * V_50 ;
struct V_29 * V_30 ;
T_6 V_98 ;
T_1 V_38 ;
bool V_156 ;
T_2 * V_157 ;
V_50 = F_100 ( V_153 ) ;
if ( ! V_50 )
goto V_62;
V_157 = V_50 -> V_60 -> V_61 ;
F_101 ( V_153 ,
L_23 ,
V_60 -> V_158 , V_157 ,
F_62 ( V_25 -> V_27 . V_57 . V_103 ) ) ;
F_101 ( V_153 , L_24 ,
L_25 , L_26 , L_27 , L_28 ) ;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_30 = & V_5 -> V_33 [ V_38 ] ;
F_15 () ;
F_16 (claim, head, hash_entry) {
V_156 = F_6 ( V_4 -> V_21 -> V_16 ,
V_157 ) ;
F_22 ( & V_4 -> V_21 -> V_41 ) ;
V_98 = V_4 -> V_21 -> V_42 ;
F_25 ( & V_4 -> V_21 -> V_41 ) ;
F_101 ( V_153 , L_29 ,
V_4 -> V_6 , F_30 ( V_4 -> V_7 ) ,
V_4 -> V_21 -> V_16 ,
( V_156 ? 'x' : ' ' ) ,
V_98 ) ;
}
F_18 () ;
}
V_62:
if ( V_50 )
F_38 ( V_50 ) ;
return 0 ;
}
int F_102 ( struct V_152 * V_153 , void * V_154 )
{
struct V_51 * V_60 = (struct V_51 * ) V_153 -> V_155 ;
struct V_24 * V_25 = F_79 ( V_60 ) ;
struct V_26 * V_5 = V_25 -> V_27 . V_34 ;
struct V_12 * V_21 ;
struct V_49 * V_50 ;
struct V_29 * V_30 ;
int V_159 , V_160 ;
T_6 V_98 ;
T_1 V_38 ;
bool V_156 ;
T_2 * V_157 ;
V_50 = F_100 ( V_153 ) ;
if ( ! V_50 )
goto V_62;
V_157 = V_50 -> V_60 -> V_61 ;
F_101 ( V_153 ,
L_30 ,
V_60 -> V_158 , V_157 ,
F_62 ( V_25 -> V_27 . V_57 . V_103 ) ) ;
F_101 ( V_153 , L_31 ,
L_27 , L_26 , L_32 , L_28 ) ;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_30 = & V_5 -> V_33 [ V_38 ] ;
F_15 () ;
F_16 (backbone_gw, head, hash_entry) {
V_160 = F_103 ( V_80 -
V_21 -> V_87 ) ;
V_159 = V_160 / 1000 ;
V_160 = V_160 % 1000 ;
V_156 = F_6 ( V_21 -> V_16 ,
V_157 ) ;
if ( V_156 )
continue;
F_22 ( & V_21 -> V_41 ) ;
V_98 = V_21 -> V_42 ;
F_25 ( & V_21 -> V_41 ) ;
F_101 ( V_153 , L_33 ,
V_21 -> V_16 ,
F_30 ( V_21 -> V_7 ) , V_159 ,
V_160 , V_98 ) ;
}
F_18 () ;
}
V_62:
if ( V_50 )
F_38 ( V_50 ) ;
return 0 ;
}
