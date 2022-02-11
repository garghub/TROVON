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
static void
F_8 ( struct V_12 * V_19 )
{
if ( F_9 ( & V_19 -> V_20 ) )
F_10 ( V_19 , V_21 ) ;
}
static void F_11 ( struct V_3 * V_4 )
{
F_8 ( V_4 -> V_19 ) ;
F_10 ( V_4 , V_21 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
if ( F_9 ( & V_4 -> V_20 ) )
F_11 ( V_4 ) ;
}
static struct V_3
* F_13 ( struct V_22 * V_23 ,
struct V_3 * V_1 )
{
struct V_24 * V_5 = V_23 -> V_25 . V_26 ;
struct V_27 * V_28 ;
struct V_3 * V_4 ;
struct V_3 * V_29 = NULL ;
int V_30 ;
if ( ! V_5 )
return NULL ;
V_30 = F_1 ( V_1 , V_5 -> V_2 ) ;
V_28 = & V_5 -> V_31 [ V_30 ] ;
F_14 () ;
F_15 (claim, head, hash_entry) {
if ( ! F_7 ( & V_4 -> V_13 , V_1 ) )
continue;
if ( ! F_16 ( & V_4 -> V_20 ) )
continue;
V_29 = V_4 ;
break;
}
F_17 () ;
return V_29 ;
}
static struct V_12 *
F_18 ( struct V_22 * V_23 , T_2 * V_6 ,
unsigned short V_7 )
{
struct V_24 * V_5 = V_23 -> V_25 . V_32 ;
struct V_27 * V_28 ;
struct V_12 V_33 , * V_19 ;
struct V_12 * V_34 = NULL ;
int V_30 ;
if ( ! V_5 )
return NULL ;
F_19 ( V_33 . V_16 , V_6 ) ;
V_33 . V_7 = V_7 ;
V_30 = F_3 ( & V_33 , V_5 -> V_2 ) ;
V_28 = & V_5 -> V_31 [ V_30 ] ;
F_14 () ;
F_15 (backbone_gw, head, hash_entry) {
if ( ! F_4 ( & V_19 -> V_13 ,
& V_33 ) )
continue;
if ( ! F_16 ( & V_19 -> V_20 ) )
continue;
V_34 = V_19 ;
break;
}
F_17 () ;
return V_34 ;
}
static void
F_20 ( struct V_12 * V_19 )
{
struct V_24 * V_5 ;
struct V_8 * V_35 ;
struct V_27 * V_28 ;
struct V_3 * V_4 ;
int V_36 ;
T_3 * V_37 ;
V_5 = V_19 -> V_23 -> V_25 . V_26 ;
if ( ! V_5 )
return;
for ( V_36 = 0 ; V_36 < V_5 -> V_2 ; V_36 ++ ) {
V_28 = & V_5 -> V_31 [ V_36 ] ;
V_37 = & V_5 -> V_38 [ V_36 ] ;
F_21 ( V_37 ) ;
F_22 (claim, node_tmp,
head, hash_entry) {
if ( V_4 -> V_19 != V_19 )
continue;
F_12 ( V_4 ) ;
F_23 ( & V_4 -> V_13 ) ;
}
F_24 ( V_37 ) ;
}
F_21 ( & V_19 -> V_39 ) ;
V_19 -> V_40 = V_41 ;
F_24 ( & V_19 -> V_39 ) ;
}
static void F_25 ( struct V_22 * V_23 , T_2 * V_42 ,
unsigned short V_7 , int V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
T_2 * V_51 ;
struct V_52 V_53 ;
T_4 V_54 = 0 ;
V_48 = F_26 ( V_23 ) ;
if ( ! V_48 )
return;
memcpy ( & V_53 , & V_23 -> V_25 . V_55 ,
sizeof( V_53 ) ) ;
V_53 . type = V_43 ;
V_50 = V_48 -> V_50 ;
V_45 = F_27 ( V_56 , V_57 ,
V_54 ,
V_48 -> V_50 ,
V_54 ,
NULL ,
V_48 -> V_58 -> V_59 ,
( T_2 * ) & V_53 ) ;
if ( ! V_45 )
goto V_60;
V_46 = (struct V_46 * ) V_45 -> V_1 ;
V_51 = ( T_2 * ) V_46 + V_61 + sizeof( struct V_62 ) ;
switch ( V_43 ) {
case V_63 :
F_19 ( V_46 -> V_64 , V_42 ) ;
F_28 ( V_65 , V_23 ,
L_1 , V_42 ,
F_29 ( V_7 ) ) ;
break;
case V_66 :
F_19 ( V_51 , V_42 ) ;
F_28 ( V_65 , V_23 ,
L_2 , V_42 ,
F_29 ( V_7 ) ) ;
break;
case V_67 :
F_19 ( V_51 , V_42 ) ;
F_28 ( V_65 , V_23 ,
L_3 ,
V_46 -> V_64 , F_29 ( V_7 ) ) ;
break;
case V_68 :
F_19 ( V_51 , V_42 ) ;
F_19 ( V_46 -> V_69 , V_42 ) ;
F_28 ( V_65 , V_23 ,
L_4 ,
V_46 -> V_64 , V_46 -> V_69 ,
F_29 ( V_7 ) ) ;
break;
}
if ( V_7 & V_70 )
V_45 = F_30 ( V_45 , F_31 ( V_71 ) ,
V_7 & V_72 ) ;
F_32 ( V_45 ) ;
V_45 -> V_73 = F_33 ( V_45 , V_50 ) ;
F_34 ( V_23 , V_74 ) ;
F_35 ( V_23 , V_75 ,
V_45 -> V_76 + V_61 ) ;
V_50 -> V_77 = V_78 ;
F_36 ( V_45 ) ;
V_60:
if ( V_48 )
F_37 ( V_48 ) ;
}
static struct V_12 *
F_38 ( struct V_22 * V_23 , T_2 * V_16 ,
unsigned short V_7 , bool V_79 )
{
struct V_12 * V_80 ;
struct V_81 * V_82 ;
int V_83 ;
V_80 = F_18 ( V_23 , V_16 , V_7 ) ;
if ( V_80 )
return V_80 ;
F_28 ( V_65 , V_23 ,
L_5 ,
V_16 , F_29 ( V_7 ) ) ;
V_80 = F_39 ( sizeof( * V_80 ) , V_84 ) ;
if ( ! V_80 )
return NULL ;
V_80 -> V_7 = V_7 ;
V_80 -> V_85 = V_78 ;
V_80 -> V_40 = V_41 ;
V_80 -> V_23 = V_23 ;
F_40 ( & V_80 -> V_39 ) ;
F_41 ( & V_80 -> V_86 , 0 ) ;
F_41 ( & V_80 -> V_87 , 0 ) ;
F_19 ( V_80 -> V_16 , V_16 ) ;
F_41 ( & V_80 -> V_20 , 2 ) ;
V_83 = F_42 ( V_23 -> V_25 . V_32 ,
F_4 ,
F_3 , V_80 ,
& V_80 -> V_13 ) ;
if ( F_43 ( V_83 != 0 ) ) {
F_44 ( V_80 ) ;
return NULL ;
}
V_82 = F_45 ( V_23 , V_16 ) ;
if ( V_82 ) {
F_46 ( V_23 , V_82 , V_7 ,
L_6 ) ;
F_47 ( V_82 ) ;
}
if ( V_79 ) {
F_48 ( V_23 , V_80 ) ;
F_49 ( & V_80 -> V_86 ) ;
F_41 ( & V_80 -> V_87 , V_88 ) ;
F_49 ( & V_23 -> V_25 . V_89 ) ;
}
return V_80 ;
}
static void
F_50 ( struct V_22 * V_23 ,
struct V_47 * V_48 ,
unsigned short V_7 )
{
struct V_12 * V_19 ;
V_19 = F_38 ( V_23 ,
V_48 -> V_58 -> V_59 ,
V_7 , true ) ;
if ( F_43 ( ! V_19 ) )
return;
V_19 -> V_85 = V_78 ;
F_8 ( V_19 ) ;
}
static void F_51 ( struct V_22 * V_23 ,
struct V_47 * V_48 ,
unsigned short V_7 )
{
struct V_27 * V_28 ;
struct V_24 * V_5 ;
struct V_3 * V_4 ;
struct V_12 * V_19 ;
int V_36 ;
F_28 ( V_65 , V_23 ,
L_7 ) ;
V_19 = F_18 ( V_23 ,
V_48 -> V_58 -> V_59 ,
V_7 ) ;
if ( ! V_19 )
return;
V_5 = V_23 -> V_25 . V_26 ;
for ( V_36 = 0 ; V_36 < V_5 -> V_2 ; V_36 ++ ) {
V_28 = & V_5 -> V_31 [ V_36 ] ;
F_14 () ;
F_15 (claim, head, hash_entry) {
if ( V_4 -> V_19 != V_19 )
continue;
F_25 ( V_23 , V_4 -> V_6 , V_4 -> V_7 ,
V_63 ) ;
}
F_17 () ;
}
F_48 ( V_23 , V_19 ) ;
F_8 ( V_19 ) ;
}
static void F_52 ( struct V_12 * V_19 )
{
F_20 ( V_19 ) ;
F_28 ( V_65 , V_19 -> V_23 ,
L_8 , V_19 -> V_16 ) ;
F_25 ( V_19 -> V_23 , V_19 -> V_16 ,
V_19 -> V_7 , V_68 ) ;
if ( ! F_53 ( & V_19 -> V_86 ) ) {
F_49 ( & V_19 -> V_23 -> V_25 . V_89 ) ;
F_41 ( & V_19 -> V_86 , 1 ) ;
}
}
static void F_48 ( struct V_22 * V_23 ,
struct V_12 * V_19 )
{
T_2 V_42 [ V_90 ] ;
T_5 V_40 ;
memcpy ( V_42 , V_91 , 4 ) ;
F_21 ( & V_19 -> V_39 ) ;
V_40 = F_31 ( V_19 -> V_40 ) ;
F_24 ( & V_19 -> V_39 ) ;
memcpy ( & V_42 [ 4 ] , & V_40 , 2 ) ;
F_25 ( V_23 , V_42 , V_19 -> V_7 ,
V_67 ) ;
}
static void F_54 ( struct V_22 * V_23 ,
const T_2 * V_42 , const unsigned short V_7 ,
struct V_12 * V_19 )
{
struct V_3 * V_4 ;
struct V_3 V_92 ;
int V_83 ;
F_19 ( V_92 . V_6 , V_42 ) ;
V_92 . V_7 = V_7 ;
V_4 = F_13 ( V_23 , & V_92 ) ;
if ( ! V_4 ) {
V_4 = F_39 ( sizeof( * V_4 ) , V_84 ) ;
if ( ! V_4 )
return;
F_19 ( V_4 -> V_6 , V_42 ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_85 = V_78 ;
V_4 -> V_19 = V_19 ;
F_41 ( & V_4 -> V_20 , 2 ) ;
F_28 ( V_65 , V_23 ,
L_9 ,
V_42 , F_29 ( V_7 ) ) ;
V_83 = F_42 ( V_23 -> V_25 . V_26 ,
F_7 ,
F_1 , V_4 ,
& V_4 -> V_13 ) ;
if ( F_43 ( V_83 != 0 ) ) {
F_44 ( V_4 ) ;
return;
}
} else {
V_4 -> V_85 = V_78 ;
if ( V_4 -> V_19 == V_19 )
goto V_93;
F_28 ( V_65 , V_23 ,
L_10 ,
V_42 , F_29 ( V_7 ) ) ;
F_21 ( & V_4 -> V_19 -> V_39 ) ;
V_4 -> V_19 -> V_40 ^= F_55 ( 0 , V_4 -> V_6 , V_90 ) ;
F_24 ( & V_4 -> V_19 -> V_39 ) ;
F_8 ( V_4 -> V_19 ) ;
}
F_49 ( & V_19 -> V_20 ) ;
V_4 -> V_19 = V_19 ;
F_21 ( & V_19 -> V_39 ) ;
V_19 -> V_40 ^= F_55 ( 0 , V_4 -> V_6 , V_90 ) ;
F_24 ( & V_19 -> V_39 ) ;
V_19 -> V_85 = V_78 ;
V_93:
F_12 ( V_4 ) ;
}
static void F_56 ( struct V_22 * V_23 ,
const T_2 * V_42 , const unsigned short V_7 )
{
struct V_3 V_92 , * V_4 ;
F_19 ( V_92 . V_6 , V_42 ) ;
V_92 . V_7 = V_7 ;
V_4 = F_13 ( V_23 , & V_92 ) ;
if ( ! V_4 )
return;
F_28 ( V_65 , V_23 , L_11 ,
V_42 , F_29 ( V_7 ) ) ;
F_57 ( V_23 -> V_25 . V_26 , F_7 ,
F_1 , V_4 ) ;
F_12 ( V_4 ) ;
F_21 ( & V_4 -> V_19 -> V_39 ) ;
V_4 -> V_19 -> V_40 ^= F_55 ( 0 , V_4 -> V_6 , V_90 ) ;
F_24 ( & V_4 -> V_19 -> V_39 ) ;
F_12 ( V_4 ) ;
}
static int F_58 ( struct V_22 * V_23 , T_2 * V_94 ,
T_2 * V_95 , unsigned short V_7 )
{
struct V_12 * V_19 ;
T_6 V_96 , V_40 ;
if ( memcmp ( V_94 , V_91 , 4 ) != 0 )
return 0 ;
V_19 = F_38 ( V_23 , V_95 , V_7 ,
false ) ;
if ( F_43 ( ! V_19 ) )
return 1 ;
V_19 -> V_85 = V_78 ;
V_40 = F_59 ( * ( ( T_5 * ) ( & V_94 [ 4 ] ) ) ) ;
F_28 ( V_65 , V_23 ,
L_12 ,
F_29 ( V_7 ) , V_19 -> V_16 , V_40 ) ;
F_21 ( & V_19 -> V_39 ) ;
V_96 = V_19 -> V_40 ;
F_24 ( & V_19 -> V_39 ) ;
if ( V_96 != V_40 ) {
F_28 ( V_65 , V_19 -> V_23 ,
L_13 ,
V_19 -> V_16 ,
F_29 ( V_19 -> V_7 ) ,
V_96 , V_40 ) ;
F_52 ( V_19 ) ;
} else {
if ( F_53 ( & V_19 -> V_86 ) ) {
F_60 ( & V_19 -> V_23 -> V_25 . V_89 ) ;
F_41 ( & V_19 -> V_86 , 0 ) ;
}
}
F_8 ( V_19 ) ;
return 1 ;
}
static int F_61 ( struct V_22 * V_23 ,
struct V_47 * V_48 ,
T_2 * V_95 , struct V_46 * V_46 ,
unsigned short V_7 )
{
if ( ! F_6 ( V_95 , V_46 -> V_69 ) )
return 0 ;
if ( ! F_6 ( V_46 -> V_69 , V_48 -> V_58 -> V_59 ) )
return 1 ;
F_28 ( V_65 , V_23 ,
L_14 ,
F_29 ( V_7 ) , V_46 -> V_64 ) ;
F_51 ( V_23 , V_48 , V_7 ) ;
return 1 ;
}
static int F_62 ( struct V_22 * V_23 ,
struct V_47 * V_48 ,
T_2 * V_95 , T_2 * V_97 ,
unsigned short V_7 )
{
struct V_12 * V_19 ;
if ( V_48 && F_6 ( V_95 ,
V_48 -> V_58 -> V_59 ) )
F_25 ( V_23 , V_97 , V_7 ,
V_66 ) ;
V_19 = F_18 ( V_23 , V_95 , V_7 ) ;
if ( ! V_19 )
return 1 ;
F_28 ( V_65 , V_23 ,
L_15 ,
V_97 , F_29 ( V_7 ) , V_19 -> V_16 ) ;
F_56 ( V_23 , V_97 , V_7 ) ;
F_8 ( V_19 ) ;
return 1 ;
}
static int F_63 ( struct V_22 * V_23 ,
struct V_47 * V_48 ,
T_2 * V_95 , T_2 * V_97 ,
unsigned short V_7 )
{
struct V_12 * V_19 ;
V_19 = F_38 ( V_23 , V_95 , V_7 ,
false ) ;
if ( F_43 ( ! V_19 ) )
return 1 ;
F_54 ( V_23 , V_97 , V_7 , V_19 ) ;
if ( F_6 ( V_95 , V_48 -> V_58 -> V_59 ) )
F_25 ( V_23 , V_97 , V_7 ,
V_63 ) ;
F_8 ( V_19 ) ;
return 1 ;
}
static int F_64 ( struct V_22 * V_23 ,
struct V_47 * V_48 ,
T_2 * V_51 , T_2 * V_98 ,
struct V_46 * V_46 )
{
T_2 * V_95 ;
struct V_81 * V_82 ;
struct V_52 * V_99 , * V_100 ;
V_99 = (struct V_52 * ) V_98 ;
V_100 = & V_23 -> V_25 . V_55 ;
switch ( V_99 -> type ) {
case V_63 :
V_95 = V_51 ;
break;
case V_68 :
case V_67 :
case V_66 :
V_95 = V_46 -> V_64 ;
break;
default:
return 0 ;
}
if ( F_6 ( V_95 , V_48 -> V_58 -> V_59 ) )
return 0 ;
if ( V_99 -> V_101 == V_100 -> V_101 )
return 2 ;
V_82 = F_45 ( V_23 , V_95 ) ;
if ( ! V_82 )
return 1 ;
if ( F_59 ( V_99 -> V_101 ) > F_59 ( V_100 -> V_101 ) ) {
F_28 ( V_65 , V_23 ,
L_16 ,
F_59 ( V_99 -> V_101 ) ) ;
V_100 -> V_101 = V_99 -> V_101 ;
}
F_47 ( V_82 ) ;
return 2 ;
}
static int F_65 ( struct V_22 * V_23 ,
struct V_47 * V_48 ,
struct V_44 * V_45 )
{
struct V_52 * V_99 , * V_100 ;
T_2 * V_51 , * V_98 ;
struct V_102 * V_103 , V_104 ;
struct V_46 * V_46 ;
struct V_62 * V_62 ;
unsigned short V_7 ;
int V_105 = 0 ;
T_5 V_106 ;
int V_107 ;
int V_108 ;
V_7 = F_66 ( V_45 , 0 ) ;
V_46 = F_67 ( V_45 ) ;
V_106 = V_46 -> V_109 ;
V_107 = V_61 ;
if ( V_7 & V_70 ) {
do {
V_103 = F_68 ( V_45 , V_107 , V_110 ,
& V_104 ) ;
if ( ! V_103 )
return 0 ;
V_106 = V_103 -> V_111 ;
V_107 += V_110 ;
V_105 ++ ;
} while ( V_106 == F_31 ( V_71 ) );
}
if ( V_106 != F_31 ( V_57 ) )
return 0 ;
if ( F_43 ( ! F_69 ( V_45 , V_107 + F_70 ( V_45 -> V_112 ) ) ) )
return 0 ;
V_46 = F_67 ( V_45 ) ;
V_62 = (struct V_62 * ) ( ( T_2 * ) V_46 + V_107 ) ;
if ( V_62 -> V_113 != F_31 ( V_114 ) )
return 0 ;
if ( V_62 -> V_115 != F_31 ( V_116 ) )
return 0 ;
if ( V_62 -> V_117 != V_90 )
return 0 ;
if ( V_62 -> V_118 != 4 )
return 0 ;
V_51 = ( T_2 * ) V_62 + sizeof( struct V_62 ) ;
V_98 = V_51 + V_90 + 4 ;
V_99 = (struct V_52 * ) V_98 ;
V_100 = & V_23 -> V_25 . V_55 ;
if ( memcmp ( V_99 -> V_119 , V_100 -> V_119 ,
sizeof( V_99 -> V_119 ) ) != 0 )
return 0 ;
if ( V_105 > 1 )
return 1 ;
V_108 = F_64 ( V_23 , V_48 , V_51 , V_98 ,
V_46 ) ;
if ( V_108 == 1 )
F_28 ( V_65 , V_23 ,
L_17 ,
V_46 -> V_64 , F_29 ( V_7 ) , V_51 ,
V_98 ) ;
if ( V_108 < 2 )
return V_108 ;
F_50 ( V_23 , V_48 , V_7 ) ;
switch ( V_99 -> type ) {
case V_63 :
if ( F_63 ( V_23 , V_48 , V_51 ,
V_46 -> V_64 , V_7 ) )
return 1 ;
break;
case V_66 :
if ( F_62 ( V_23 , V_48 ,
V_46 -> V_64 , V_51 , V_7 ) )
return 1 ;
break;
case V_67 :
if ( F_58 ( V_23 , V_51 , V_46 -> V_64 ,
V_7 ) )
return 1 ;
break;
case V_68 :
if ( F_61 ( V_23 , V_48 , V_51 , V_46 ,
V_7 ) )
return 1 ;
break;
}
F_28 ( V_65 , V_23 ,
L_18 ,
V_46 -> V_64 , F_29 ( V_7 ) , V_51 , V_98 ) ;
return 1 ;
}
static void F_71 ( struct V_22 * V_23 , int V_120 )
{
struct V_12 * V_19 ;
struct V_8 * V_35 ;
struct V_27 * V_28 ;
struct V_24 * V_5 ;
T_3 * V_37 ;
int V_36 ;
V_5 = V_23 -> V_25 . V_32 ;
if ( ! V_5 )
return;
for ( V_36 = 0 ; V_36 < V_5 -> V_2 ; V_36 ++ ) {
V_28 = & V_5 -> V_31 [ V_36 ] ;
V_37 = & V_5 -> V_38 [ V_36 ] ;
F_21 ( V_37 ) ;
F_22 (backbone_gw, node_tmp,
head, hash_entry) {
if ( V_120 )
goto V_121;
if ( ! F_72 ( V_19 -> V_85 ,
V_122 ) )
continue;
F_28 ( V_65 , V_19 -> V_23 ,
L_19 ,
V_19 -> V_16 ) ;
V_121:
if ( F_53 ( & V_19 -> V_86 ) )
F_60 ( & V_23 -> V_25 . V_89 ) ;
F_20 ( V_19 ) ;
F_23 ( & V_19 -> V_13 ) ;
F_8 ( V_19 ) ;
}
F_24 ( V_37 ) ;
}
}
static void F_73 ( struct V_22 * V_23 ,
struct V_47 * V_48 ,
int V_120 )
{
struct V_3 * V_4 ;
struct V_27 * V_28 ;
struct V_24 * V_5 ;
int V_36 ;
V_5 = V_23 -> V_25 . V_26 ;
if ( ! V_5 )
return;
for ( V_36 = 0 ; V_36 < V_5 -> V_2 ; V_36 ++ ) {
V_28 = & V_5 -> V_31 [ V_36 ] ;
F_14 () ;
F_15 (claim, head, hash_entry) {
if ( V_120 )
goto V_121;
if ( ! F_6 ( V_4 -> V_19 -> V_16 ,
V_48 -> V_58 -> V_59 ) )
continue;
if ( ! F_72 ( V_4 -> V_85 ,
V_123 ) )
continue;
F_28 ( V_65 , V_23 ,
L_20 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
V_121:
F_62 ( V_23 , V_48 ,
V_4 -> V_19 -> V_16 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
}
F_17 () ;
}
}
void F_74 ( struct V_22 * V_23 ,
struct V_47 * V_48 ,
struct V_47 * V_124 )
{
struct V_12 * V_19 ;
struct V_27 * V_28 ;
struct V_24 * V_5 ;
T_5 V_101 ;
int V_36 ;
V_101 = F_31 ( F_55 ( 0 , V_48 -> V_58 -> V_59 , V_90 ) ) ;
V_23 -> V_25 . V_55 . V_101 = V_101 ;
if ( ! F_53 ( & V_23 -> V_125 ) )
V_124 = NULL ;
if ( ! V_124 ) {
F_73 ( V_23 , NULL , 1 ) ;
F_71 ( V_23 , 1 ) ;
return;
}
V_5 = V_23 -> V_25 . V_32 ;
if ( ! V_5 )
return;
for ( V_36 = 0 ; V_36 < V_5 -> V_2 ; V_36 ++ ) {
V_28 = & V_5 -> V_31 [ V_36 ] ;
F_14 () ;
F_15 (backbone_gw, head, hash_entry) {
if ( ! F_6 ( V_19 -> V_16 ,
V_124 -> V_58 -> V_59 ) )
continue;
F_19 ( V_19 -> V_16 ,
V_48 -> V_58 -> V_59 ) ;
F_48 ( V_23 , V_19 ) ;
}
F_17 () ;
}
}
void F_75 ( struct V_49 * V_58 )
{
struct V_22 * V_23 = F_76 ( V_58 ) ;
struct V_47 * V_48 ;
V_48 = F_26 ( V_23 ) ;
if ( ! V_48 )
return;
F_74 ( V_23 , V_48 , V_48 ) ;
F_37 ( V_48 ) ;
}
static void F_77 ( struct V_126 * V_127 )
{
struct V_128 * V_128 ;
struct V_22 * V_23 ;
struct V_129 * V_130 ;
struct V_27 * V_28 ;
struct V_12 * V_19 ;
struct V_24 * V_5 ;
struct V_47 * V_48 ;
int V_36 ;
V_128 = F_5 ( V_127 , struct V_128 , V_127 ) ;
V_130 = F_5 ( V_128 , struct V_129 , V_127 ) ;
V_23 = F_5 ( V_130 , struct V_22 , V_25 ) ;
V_48 = F_26 ( V_23 ) ;
if ( ! V_48 )
goto V_60;
F_73 ( V_23 , V_48 , 0 ) ;
F_71 ( V_23 , 0 ) ;
if ( ! F_53 ( & V_23 -> V_125 ) )
goto V_60;
V_5 = V_23 -> V_25 . V_32 ;
if ( ! V_5 )
goto V_60;
for ( V_36 = 0 ; V_36 < V_5 -> V_2 ; V_36 ++ ) {
V_28 = & V_5 -> V_31 [ V_36 ] ;
F_14 () ;
F_15 (backbone_gw, head, hash_entry) {
if ( ! F_6 ( V_19 -> V_16 ,
V_48 -> V_58 -> V_59 ) )
continue;
V_19 -> V_85 = V_78 ;
F_48 ( V_23 , V_19 ) ;
if ( F_53 ( & V_19 -> V_86 ) == 0 )
continue;
if ( ! F_9 ( & V_19 -> V_87 ) )
continue;
F_60 ( & V_19 -> V_23 -> V_25 . V_89 ) ;
F_41 ( & V_19 -> V_86 , 0 ) ;
}
F_17 () ;
}
V_60:
if ( V_48 )
F_37 ( V_48 ) ;
F_78 ( V_131 , & V_23 -> V_25 . V_127 ,
F_79 ( V_132 ) ) ;
}
int F_80 ( struct V_22 * V_23 )
{
int V_36 ;
T_2 V_55 [ V_90 ] = { 0xff , 0x43 , 0x05 , 0x00 , 0x00 , 0x00 } ;
struct V_47 * V_48 ;
T_6 V_40 ;
unsigned long V_133 ;
F_40 ( & V_23 -> V_25 . V_134 ) ;
F_28 ( V_65 , V_23 , L_21 ) ;
memcpy ( & V_23 -> V_25 . V_55 . V_119 , V_55 , 3 ) ;
V_23 -> V_25 . V_55 . type = 0 ;
V_48 = F_26 ( V_23 ) ;
if ( V_48 ) {
V_40 = F_55 ( 0 , V_48 -> V_58 -> V_59 , V_90 ) ;
V_23 -> V_25 . V_55 . V_101 = F_31 ( V_40 ) ;
F_37 ( V_48 ) ;
} else {
V_23 -> V_25 . V_55 . V_101 = 0 ;
}
V_133 = V_78 - F_79 ( V_135 ) ;
for ( V_36 = 0 ; V_36 < V_136 ; V_36 ++ )
V_23 -> V_25 . V_137 [ V_36 ] . V_133 = V_133 ;
V_23 -> V_25 . V_138 = 0 ;
if ( V_23 -> V_25 . V_26 )
return 0 ;
V_23 -> V_25 . V_26 = F_81 ( 128 ) ;
V_23 -> V_25 . V_32 = F_81 ( 32 ) ;
if ( ! V_23 -> V_25 . V_26 || ! V_23 -> V_25 . V_32 )
return - V_139 ;
F_82 ( V_23 -> V_25 . V_26 ,
& V_140 ) ;
F_82 ( V_23 -> V_25 . V_32 ,
& V_141 ) ;
F_28 ( V_65 , V_23 , L_22 ) ;
F_83 ( & V_23 -> V_25 . V_127 , F_77 ) ;
F_78 ( V_131 , & V_23 -> V_25 . V_127 ,
F_79 ( V_132 ) ) ;
return 0 ;
}
int F_84 ( struct V_22 * V_23 ,
struct V_44 * V_45 )
{
int V_36 , V_142 , V_108 = 0 ;
T_4 V_40 ;
struct V_143 * V_144 ;
struct V_145 * V_80 ;
V_144 = (struct V_143 * ) V_45 -> V_1 ;
V_40 = F_85 ( V_45 , ( T_2 * ) ( V_144 + 1 ) ) ;
F_21 ( & V_23 -> V_25 . V_134 ) ;
for ( V_36 = 0 ; V_36 < V_136 ; V_36 ++ ) {
V_142 = ( V_23 -> V_25 . V_138 + V_36 ) ;
V_142 %= V_136 ;
V_80 = & V_23 -> V_25 . V_137 [ V_142 ] ;
if ( F_72 ( V_80 -> V_133 ,
V_135 ) )
break;
if ( V_80 -> V_40 != V_40 )
continue;
if ( F_6 ( V_80 -> V_16 , V_144 -> V_16 ) )
continue;
V_108 = 1 ;
goto V_60;
}
V_142 = ( V_23 -> V_25 . V_138 + V_136 - 1 ) ;
V_142 %= V_136 ;
V_80 = & V_23 -> V_25 . V_137 [ V_142 ] ;
V_80 -> V_40 = V_40 ;
V_80 -> V_133 = V_78 ;
F_19 ( V_80 -> V_16 , V_144 -> V_16 ) ;
V_23 -> V_25 . V_138 = V_142 ;
V_60:
F_24 ( & V_23 -> V_25 . V_134 ) ;
return V_108 ;
}
bool F_86 ( struct V_22 * V_23 , T_2 * V_16 ,
unsigned short V_7 )
{
struct V_24 * V_5 = V_23 -> V_25 . V_32 ;
struct V_27 * V_28 ;
struct V_12 * V_19 ;
int V_36 ;
if ( ! F_53 ( & V_23 -> V_125 ) )
return false ;
if ( ! V_5 )
return false ;
for ( V_36 = 0 ; V_36 < V_5 -> V_2 ; V_36 ++ ) {
V_28 = & V_5 -> V_31 [ V_36 ] ;
F_14 () ;
F_15 (backbone_gw, head, hash_entry) {
if ( F_6 ( V_19 -> V_16 , V_16 ) &&
V_19 -> V_7 == V_7 ) {
F_17 () ;
return true ;
}
}
F_17 () ;
}
return false ;
}
int F_87 ( struct V_44 * V_45 ,
struct V_81 * V_82 , int V_146 )
{
struct V_12 * V_19 ;
unsigned short V_7 ;
if ( ! F_53 ( & V_82 -> V_23 -> V_125 ) )
return 0 ;
if ( ! F_69 ( V_45 , V_146 + V_61 ) )
return 0 ;
V_7 = F_66 ( V_45 , V_146 ) ;
V_19 = F_18 ( V_82 -> V_23 ,
V_82 -> V_16 , V_7 ) ;
if ( ! V_19 )
return 0 ;
F_8 ( V_19 ) ;
return 1 ;
}
void F_88 ( struct V_22 * V_23 )
{
struct V_47 * V_48 ;
F_89 ( & V_23 -> V_25 . V_127 ) ;
V_48 = F_26 ( V_23 ) ;
if ( V_23 -> V_25 . V_26 ) {
F_73 ( V_23 , V_48 , 1 ) ;
F_90 ( V_23 -> V_25 . V_26 ) ;
V_23 -> V_25 . V_26 = NULL ;
}
if ( V_23 -> V_25 . V_32 ) {
F_71 ( V_23 , 1 ) ;
F_90 ( V_23 -> V_25 . V_32 ) ;
V_23 -> V_25 . V_32 = NULL ;
}
if ( V_48 )
F_37 ( V_48 ) ;
}
int F_91 ( struct V_22 * V_23 , struct V_44 * V_45 ,
unsigned short V_7 , bool V_147 )
{
struct V_46 * V_46 ;
struct V_3 V_92 , * V_4 = NULL ;
struct V_47 * V_48 ;
int V_108 ;
V_46 = F_67 ( V_45 ) ;
V_48 = F_26 ( V_23 ) ;
if ( ! V_48 )
goto V_148;
if ( ! F_53 ( & V_23 -> V_125 ) )
goto V_149;
if ( F_43 ( F_53 ( & V_23 -> V_25 . V_89 ) ) )
if ( F_92 ( V_46 -> V_69 ) && V_147 )
goto V_148;
F_19 ( V_92 . V_6 , V_46 -> V_64 ) ;
V_92 . V_7 = V_7 ;
V_4 = F_13 ( V_23 , & V_92 ) ;
if ( ! V_4 ) {
F_63 ( V_23 , V_48 ,
V_48 -> V_58 -> V_59 ,
V_46 -> V_64 , V_7 ) ;
goto V_149;
}
if ( F_6 ( V_4 -> V_19 -> V_16 ,
V_48 -> V_58 -> V_59 ) ) {
V_4 -> V_85 = V_78 ;
goto V_149;
}
if ( F_92 ( V_46 -> V_69 ) && V_147 ) {
goto V_148;
} else {
F_63 ( V_23 , V_48 ,
V_48 -> V_58 -> V_59 ,
V_46 -> V_64 , V_7 ) ;
goto V_149;
}
V_149:
F_50 ( V_23 , V_48 , V_7 ) ;
V_108 = 0 ;
goto V_60;
V_148:
F_93 ( V_45 ) ;
V_108 = 1 ;
V_60:
if ( V_48 )
F_37 ( V_48 ) ;
if ( V_4 )
F_12 ( V_4 ) ;
return V_108 ;
}
int F_94 ( struct V_22 * V_23 , struct V_44 * V_45 ,
unsigned short V_7 )
{
struct V_46 * V_46 ;
struct V_3 V_92 , * V_4 = NULL ;
struct V_47 * V_48 ;
int V_108 = 0 ;
V_48 = F_26 ( V_23 ) ;
if ( ! V_48 )
goto V_60;
if ( ! F_53 ( & V_23 -> V_125 ) )
goto V_149;
if ( F_65 ( V_23 , V_48 , V_45 ) )
goto V_148;
V_46 = F_67 ( V_45 ) ;
if ( F_43 ( F_53 ( & V_23 -> V_25 . V_89 ) ) )
if ( F_92 ( V_46 -> V_69 ) )
goto V_148;
F_19 ( V_92 . V_6 , V_46 -> V_64 ) ;
V_92 . V_7 = V_7 ;
V_4 = F_13 ( V_23 , & V_92 ) ;
if ( ! V_4 )
goto V_149;
if ( F_6 ( V_4 -> V_19 -> V_16 ,
V_48 -> V_58 -> V_59 ) ) {
F_62 ( V_23 , V_48 ,
V_48 -> V_58 -> V_59 ,
V_46 -> V_64 , V_7 ) ;
goto V_149;
}
if ( F_92 ( V_46 -> V_69 ) ) {
goto V_148;
} else {
goto V_149;
}
V_149:
F_50 ( V_23 , V_48 , V_7 ) ;
V_108 = 0 ;
goto V_60;
V_148:
V_108 = 1 ;
V_60:
if ( V_48 )
F_37 ( V_48 ) ;
if ( V_4 )
F_12 ( V_4 ) ;
return V_108 ;
}
int F_95 ( struct V_150 * V_151 , void * V_152 )
{
struct V_49 * V_58 = (struct V_49 * ) V_151 -> V_153 ;
struct V_22 * V_23 = F_76 ( V_58 ) ;
struct V_24 * V_5 = V_23 -> V_25 . V_26 ;
struct V_3 * V_4 ;
struct V_47 * V_48 ;
struct V_27 * V_28 ;
T_6 V_96 ;
T_1 V_36 ;
bool V_154 ;
T_2 * V_155 ;
V_48 = F_96 ( V_151 ) ;
if ( ! V_48 )
goto V_60;
V_155 = V_48 -> V_58 -> V_59 ;
F_97 ( V_151 ,
L_23 ,
V_58 -> V_156 , V_155 ,
F_59 ( V_23 -> V_25 . V_55 . V_101 ) ) ;
F_97 ( V_151 , L_24 ,
L_25 , L_26 , L_27 , L_28 ) ;
for ( V_36 = 0 ; V_36 < V_5 -> V_2 ; V_36 ++ ) {
V_28 = & V_5 -> V_31 [ V_36 ] ;
F_14 () ;
F_15 (claim, head, hash_entry) {
V_154 = F_6 ( V_4 -> V_19 -> V_16 ,
V_155 ) ;
F_21 ( & V_4 -> V_19 -> V_39 ) ;
V_96 = V_4 -> V_19 -> V_40 ;
F_24 ( & V_4 -> V_19 -> V_39 ) ;
F_97 ( V_151 , L_29 ,
V_4 -> V_6 , F_29 ( V_4 -> V_7 ) ,
V_4 -> V_19 -> V_16 ,
( V_154 ? 'x' : ' ' ) ,
V_96 ) ;
}
F_17 () ;
}
V_60:
if ( V_48 )
F_37 ( V_48 ) ;
return 0 ;
}
int F_98 ( struct V_150 * V_151 , void * V_152 )
{
struct V_49 * V_58 = (struct V_49 * ) V_151 -> V_153 ;
struct V_22 * V_23 = F_76 ( V_58 ) ;
struct V_24 * V_5 = V_23 -> V_25 . V_32 ;
struct V_12 * V_19 ;
struct V_47 * V_48 ;
struct V_27 * V_28 ;
int V_157 , V_158 ;
T_6 V_96 ;
T_1 V_36 ;
bool V_154 ;
T_2 * V_155 ;
V_48 = F_96 ( V_151 ) ;
if ( ! V_48 )
goto V_60;
V_155 = V_48 -> V_58 -> V_59 ;
F_97 ( V_151 ,
L_30 ,
V_58 -> V_156 , V_155 ,
F_59 ( V_23 -> V_25 . V_55 . V_101 ) ) ;
F_97 ( V_151 , L_31 ,
L_27 , L_26 , L_32 , L_28 ) ;
for ( V_36 = 0 ; V_36 < V_5 -> V_2 ; V_36 ++ ) {
V_28 = & V_5 -> V_31 [ V_36 ] ;
F_14 () ;
F_15 (backbone_gw, head, hash_entry) {
V_158 = F_99 ( V_78 -
V_19 -> V_85 ) ;
V_157 = V_158 / 1000 ;
V_158 = V_158 % 1000 ;
V_154 = F_6 ( V_19 -> V_16 ,
V_155 ) ;
if ( V_154 )
continue;
F_21 ( & V_19 -> V_39 ) ;
V_96 = V_19 -> V_40 ;
F_24 ( & V_19 -> V_39 ) ;
F_97 ( V_151 , L_33 ,
V_19 -> V_16 ,
F_29 ( V_19 -> V_7 ) , V_157 ,
V_158 , V_96 ) ;
}
F_17 () ;
}
V_60:
if ( V_48 )
F_37 ( V_48 ) ;
return 0 ;
}
