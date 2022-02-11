static inline T_1 F_1 ( const void * V_1 , T_1 V_2 )
{
const unsigned char * V_3 = V_1 ;
T_1 V_4 = 0 ;
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < V_6 + sizeof( short ) ; V_5 ++ ) {
V_4 += V_3 [ V_5 ] ;
V_4 += ( V_4 << 10 ) ;
V_4 ^= ( V_4 >> 6 ) ;
}
V_4 += ( V_4 << 3 ) ;
V_4 ^= ( V_4 >> 11 ) ;
V_4 += ( V_4 << 15 ) ;
return V_4 % V_2 ;
}
static inline T_1 F_2 ( const void * V_1 , T_1 V_2 )
{
const unsigned char * V_3 = V_1 ;
T_1 V_4 = 0 ;
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < V_6 + sizeof( short ) ; V_5 ++ ) {
V_4 += V_3 [ V_5 ] ;
V_4 += ( V_4 << 10 ) ;
V_4 ^= ( V_4 >> 6 ) ;
}
V_4 += ( V_4 << 3 ) ;
V_4 ^= ( V_4 >> 11 ) ;
V_4 += ( V_4 << 15 ) ;
return V_4 % V_2 ;
}
static int F_3 ( const struct V_7 * V_8 , const void * V_9 )
{
const void * V_10 = F_4 ( V_8 , struct V_11 ,
V_12 ) ;
return ( memcmp ( V_10 , V_9 , V_6 + sizeof( short ) ) == 0 ? 1 : 0 ) ;
}
static int F_5 ( const struct V_7 * V_8 , const void * V_9 )
{
const void * V_10 = F_4 ( V_8 , struct V_13 ,
V_12 ) ;
return ( memcmp ( V_10 , V_9 , V_6 + sizeof( short ) ) == 0 ? 1 : 0 ) ;
}
static void F_6 ( struct V_11 * V_11 )
{
if ( F_7 ( & V_11 -> V_14 ) )
F_8 ( V_11 , V_15 ) ;
}
static void F_9 ( struct V_16 * V_15 )
{
struct V_13 * V_13 ;
V_13 = F_4 ( V_15 , struct V_13 , V_15 ) ;
F_6 ( V_13 -> V_11 ) ;
F_10 ( V_13 ) ;
}
static void F_11 ( struct V_13 * V_13 )
{
if ( F_7 ( & V_13 -> V_14 ) )
F_12 ( & V_13 -> V_15 , F_9 ) ;
}
static struct V_13 * F_13 ( struct V_17 * V_17 ,
struct V_13 * V_1 )
{
struct V_18 * V_4 = V_17 -> V_19 ;
struct V_20 * V_21 ;
struct V_7 * V_8 ;
struct V_13 * V_13 ;
struct V_13 * V_22 = NULL ;
int V_23 ;
if ( ! V_4 )
return NULL ;
V_23 = F_1 ( V_1 , V_4 -> V_2 ) ;
V_21 = & V_4 -> V_24 [ V_23 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
if ( ! F_5 ( & V_13 -> V_12 , V_1 ) )
continue;
if ( ! F_16 ( & V_13 -> V_14 ) )
continue;
V_22 = V_13 ;
break;
}
F_17 () ;
return V_22 ;
}
static struct V_11 * F_18 ( struct V_17 * V_17 ,
T_3 * V_25 , short V_26 )
{
struct V_18 * V_4 = V_17 -> V_27 ;
struct V_20 * V_21 ;
struct V_7 * V_8 ;
struct V_11 V_28 , * V_11 ;
struct V_11 * V_29 = NULL ;
int V_23 ;
if ( ! V_4 )
return NULL ;
memcpy ( V_28 . V_30 , V_25 , V_6 ) ;
V_28 . V_26 = V_26 ;
V_23 = F_2 ( & V_28 , V_4 -> V_2 ) ;
V_21 = & V_4 -> V_24 [ V_23 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( ! F_3 ( & V_11 -> V_12 ,
& V_28 ) )
continue;
if ( ! F_16 ( & V_11 -> V_14 ) )
continue;
V_29 = V_11 ;
break;
}
F_17 () ;
return V_29 ;
}
static void F_19 ( struct V_11 * V_11 )
{
struct V_18 * V_4 ;
struct V_7 * V_8 , * V_31 ;
struct V_20 * V_21 ;
struct V_13 * V_13 ;
int V_5 ;
T_4 * V_32 ;
V_4 = V_11 -> V_17 -> V_19 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_21 = & V_4 -> V_24 [ V_5 ] ;
V_32 = & V_4 -> V_33 [ V_5 ] ;
F_20 ( V_32 ) ;
F_21 (claim, node, node_tmp,
head, hash_entry) {
if ( V_13 -> V_11 != V_11 )
continue;
F_11 ( V_13 ) ;
F_22 ( V_8 ) ;
}
F_23 ( V_32 ) ;
}
V_11 -> V_34 = V_35 ;
}
static void F_24 ( struct V_17 * V_17 , T_3 * V_36 ,
short V_26 , int V_37 )
{
struct V_38 * V_39 ;
struct V_40 * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
T_3 * V_45 ;
struct V_46 V_47 ;
T_1 V_48 = 0 ;
V_42 = F_25 ( V_17 ) ;
if ( ! V_42 )
return;
memcpy ( & V_47 , & V_17 -> V_49 ,
sizeof( V_47 ) ) ;
V_47 . type = V_37 ;
V_44 = V_42 -> V_44 ;
V_39 = F_26 ( V_50 , V_51 ,
V_48 ,
V_42 -> V_44 ,
V_48 ,
NULL ,
V_42 -> V_52 -> V_53 ,
( T_3 * ) & V_47 ) ;
if ( ! V_39 )
goto V_54;
V_40 = (struct V_40 * ) V_39 -> V_1 ;
V_45 = ( T_3 * ) V_40 + V_55 + sizeof( struct V_56 ) ;
switch ( V_37 ) {
case V_57 :
memcpy ( V_40 -> V_58 , V_36 , V_6 ) ;
F_27 ( V_59 , V_17 ,
L_1 , V_36 , V_26 ) ;
break;
case V_60 :
memcpy ( V_45 , V_36 , V_6 ) ;
F_27 ( V_59 , V_17 ,
L_2 , V_36 , V_26 ) ;
break;
case V_61 :
memcpy ( V_45 , V_36 , V_6 ) ;
F_27 ( V_59 , V_17 ,
L_3 ,
V_40 -> V_58 , V_26 ) ;
break;
case V_62 :
memcpy ( V_45 , V_36 , V_6 ) ;
memcpy ( V_40 -> V_63 , V_36 , V_6 ) ;
F_27 ( V_59 , V_17 ,
L_4 ,
V_40 -> V_58 , V_40 -> V_63 , V_26 ) ;
break;
}
if ( V_26 != - 1 )
V_39 = F_28 ( V_39 , V_26 ) ;
F_29 ( V_39 ) ;
V_39 -> V_64 = F_30 ( V_39 , V_44 ) ;
V_17 -> V_65 . V_66 ++ ;
V_17 -> V_65 . V_67 += V_39 -> V_68 + V_55 ;
V_44 -> V_69 = V_70 ;
F_31 ( V_39 ) ;
V_54:
if ( V_42 )
F_32 ( V_42 ) ;
}
static struct V_11 * F_33 ( struct V_17 * V_17 ,
T_3 * V_30 , short V_26 )
{
struct V_11 * V_71 ;
struct V_72 * V_72 ;
int V_73 ;
V_71 = F_18 ( V_17 , V_30 , V_26 ) ;
if ( V_71 )
return V_71 ;
F_27 ( V_59 , V_17 ,
L_5 ,
V_30 , V_26 ) ;
V_71 = F_34 ( sizeof( * V_71 ) , V_74 ) ;
if ( ! V_71 )
return NULL ;
V_71 -> V_26 = V_26 ;
V_71 -> V_75 = V_70 ;
V_71 -> V_34 = V_35 ;
V_71 -> V_17 = V_17 ;
F_35 ( & V_71 -> V_76 , 0 ) ;
memcpy ( V_71 -> V_30 , V_30 , V_6 ) ;
F_35 ( & V_71 -> V_14 , 2 ) ;
V_73 = F_36 ( V_17 -> V_27 , F_3 ,
F_2 , V_71 , & V_71 -> V_12 ) ;
if ( F_37 ( V_73 != 0 ) ) {
F_10 ( V_71 ) ;
return NULL ;
}
V_72 = F_38 ( V_17 , V_30 ) ;
if ( V_72 ) {
F_39 ( V_17 , V_72 ,
L_6 ) ;
F_40 ( V_72 ) ;
}
return V_71 ;
}
static void F_41 ( struct V_17 * V_17 ,
struct V_41 * V_42 ,
short V_26 )
{
struct V_11 * V_11 ;
V_11 = F_33 ( V_17 ,
V_42 -> V_52 -> V_53 , V_26 ) ;
if ( F_37 ( ! V_11 ) )
return;
V_11 -> V_75 = V_70 ;
F_6 ( V_11 ) ;
}
static void F_42 ( struct V_17 * V_17 ,
struct V_41 * V_42 , short V_26 )
{
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_18 * V_4 ;
struct V_13 * V_13 ;
struct V_11 * V_11 ;
int V_5 ;
F_27 ( V_59 , V_17 ,
L_7 ) ;
V_11 = F_18 ( V_17 ,
V_42 -> V_52 -> V_53 , V_26 ) ;
if ( ! V_11 )
return;
V_4 = V_17 -> V_19 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_21 = & V_4 -> V_24 [ V_5 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
if ( V_13 -> V_11 != V_11 )
continue;
F_24 ( V_17 , V_13 -> V_25 , V_13 -> V_26 ,
V_57 ) ;
}
F_17 () ;
}
F_43 ( V_17 , V_11 ) ;
F_6 ( V_11 ) ;
}
static void F_44 ( struct V_11 * V_11 )
{
F_19 ( V_11 ) ;
F_27 ( V_59 , V_11 -> V_17 ,
L_8 ,
V_11 -> V_30 ) ;
F_24 ( V_11 -> V_17 , V_11 -> V_30 ,
V_11 -> V_26 , V_62 ) ;
if ( ! F_45 ( & V_11 -> V_76 ) ) {
F_46 ( & V_11 -> V_17 -> V_77 ) ;
F_35 ( & V_11 -> V_76 , 1 ) ;
}
}
static void F_43 ( struct V_17 * V_17 ,
struct V_11 * V_11 )
{
T_3 V_36 [ V_6 ] ;
T_5 V_34 ;
memcpy ( V_36 , V_78 , 4 ) ;
V_34 = F_47 ( V_11 -> V_34 ) ;
memcpy ( & V_36 [ 4 ] , ( T_3 * ) & V_34 , 2 ) ;
F_24 ( V_17 , V_36 , V_11 -> V_26 , V_61 ) ;
}
static void F_48 ( struct V_17 * V_17 , const T_3 * V_36 ,
const short V_26 , struct V_11 * V_11 )
{
struct V_13 * V_13 ;
struct V_13 V_79 ;
int V_73 ;
memcpy ( V_79 . V_25 , V_36 , V_6 ) ;
V_79 . V_26 = V_26 ;
V_13 = F_13 ( V_17 , & V_79 ) ;
if ( ! V_13 ) {
V_13 = F_34 ( sizeof( * V_13 ) , V_74 ) ;
if ( ! V_13 )
return;
memcpy ( V_13 -> V_25 , V_36 , V_6 ) ;
V_13 -> V_26 = V_26 ;
V_13 -> V_75 = V_70 ;
V_13 -> V_11 = V_11 ;
F_35 ( & V_13 -> V_14 , 2 ) ;
F_27 ( V_59 , V_17 ,
L_9 ,
V_36 , V_26 ) ;
V_73 = F_36 ( V_17 -> V_19 , F_5 ,
F_1 , V_13 , & V_13 -> V_12 ) ;
if ( F_37 ( V_73 != 0 ) ) {
F_10 ( V_13 ) ;
return;
}
} else {
V_13 -> V_75 = V_70 ;
if ( V_13 -> V_11 == V_11 )
goto F_11;
F_27 ( V_59 , V_17 ,
L_10 ,
V_36 , V_26 ) ;
V_13 -> V_11 -> V_34 ^=
F_49 ( 0 , V_13 -> V_25 , V_6 ) ;
F_6 ( V_13 -> V_11 ) ;
}
F_46 ( & V_11 -> V_14 ) ;
V_13 -> V_11 = V_11 ;
V_11 -> V_34 ^= F_49 ( 0 , V_13 -> V_25 , V_6 ) ;
V_11 -> V_75 = V_70 ;
F_11:
F_11 ( V_13 ) ;
}
static void F_50 ( struct V_17 * V_17 , const T_3 * V_36 ,
const short V_26 )
{
struct V_13 V_79 , * V_13 ;
memcpy ( V_79 . V_25 , V_36 , V_6 ) ;
V_79 . V_26 = V_26 ;
V_13 = F_13 ( V_17 , & V_79 ) ;
if ( ! V_13 )
return;
F_27 ( V_59 , V_17 , L_11 , V_36 , V_26 ) ;
F_51 ( V_17 -> V_19 , F_5 , F_1 , V_13 ) ;
F_11 ( V_13 ) ;
V_13 -> V_11 -> V_34 ^= F_49 ( 0 , V_13 -> V_25 , V_6 ) ;
F_11 ( V_13 ) ;
}
static int F_52 ( struct V_17 * V_17 ,
T_3 * V_80 , T_3 * V_81 , short V_26 )
{
struct V_11 * V_11 ;
T_5 V_34 ;
if ( memcmp ( V_80 , V_78 , 4 ) != 0 )
return 0 ;
V_11 = F_33 ( V_17 , V_81 , V_26 ) ;
if ( F_37 ( ! V_11 ) )
return 1 ;
V_11 -> V_75 = V_70 ;
V_34 = F_53 ( * ( ( T_5 * ) ( & V_80 [ 4 ] ) ) ) ;
F_27 ( V_59 , V_17 ,
L_12 ,
V_26 , V_11 -> V_30 , V_34 ) ;
if ( V_11 -> V_34 != V_34 ) {
F_27 ( V_59 , V_11 -> V_17 ,
L_13 ,
V_11 -> V_30 , V_11 -> V_26 , V_11 -> V_34 ,
V_34 ) ;
F_44 ( V_11 ) ;
} else {
if ( F_45 ( & V_11 -> V_76 ) ) {
F_54 ( & V_11 -> V_17 -> V_77 ) ;
F_35 ( & V_11 -> V_76 , 0 ) ;
}
}
F_6 ( V_11 ) ;
return 1 ;
}
static int F_55 ( struct V_17 * V_17 ,
struct V_41 * V_42 ,
T_3 * V_81 ,
struct V_40 * V_40 , short V_26 )
{
if ( ! F_56 ( V_81 , V_40 -> V_63 ) )
return 0 ;
if ( ! F_56 ( V_40 -> V_63 , V_42 -> V_52 -> V_53 ) )
return 1 ;
F_27 ( V_59 , V_17 ,
L_14 ,
V_26 , V_40 -> V_58 ) ;
F_42 ( V_17 , V_42 , V_26 ) ;
return 1 ;
}
static int F_57 ( struct V_17 * V_17 ,
struct V_41 * V_42 ,
T_3 * V_81 ,
T_3 * V_82 , short V_26 )
{
struct V_11 * V_11 ;
if ( V_42 && F_56 ( V_81 ,
V_42 -> V_52 -> V_53 ) )
F_24 ( V_17 , V_82 , V_26 , V_60 ) ;
V_11 = F_18 ( V_17 , V_81 , V_26 ) ;
if ( ! V_11 )
return 1 ;
F_27 ( V_59 , V_17 ,
L_15 ,
V_82 , V_26 , V_11 -> V_30 ) ;
F_50 ( V_17 , V_82 , V_26 ) ;
F_6 ( V_11 ) ;
return 1 ;
}
static int F_58 ( struct V_17 * V_17 ,
struct V_41 * V_42 , T_3 * V_81 ,
T_3 * V_82 , short V_26 )
{
struct V_11 * V_11 ;
V_11 = F_33 ( V_17 , V_81 , V_26 ) ;
if ( F_37 ( ! V_11 ) )
return 1 ;
F_48 ( V_17 , V_82 , V_26 , V_11 ) ;
if ( F_56 ( V_81 , V_42 -> V_52 -> V_53 ) )
F_24 ( V_17 , V_82 , V_26 , V_57 ) ;
F_6 ( V_11 ) ;
return 1 ;
}
static int F_59 ( struct V_17 * V_17 ,
struct V_41 * V_42 ,
T_3 * V_45 , T_3 * V_83 ,
struct V_40 * V_40 )
{
T_3 * V_81 ;
struct V_72 * V_72 ;
struct V_46 * V_84 , * V_85 ;
V_84 = (struct V_46 * ) V_83 ;
V_85 = & V_17 -> V_49 ;
if ( memcmp ( V_84 -> V_86 , V_85 -> V_86 ,
sizeof( V_84 -> V_86 ) ) != 0 )
return 0 ;
switch ( V_84 -> type ) {
case V_57 :
V_81 = V_45 ;
break;
case V_62 :
case V_61 :
case V_60 :
V_81 = V_40 -> V_58 ;
break;
default:
return 0 ;
}
if ( F_56 ( V_81 , V_42 -> V_52 -> V_53 ) )
return 0 ;
if ( V_84 -> V_87 == V_85 -> V_87 )
return 2 ;
V_72 = F_38 ( V_17 , V_81 ) ;
if ( ! V_72 )
return 1 ;
if ( F_53 ( V_84 -> V_87 ) > F_53 ( V_85 -> V_87 ) ) {
F_27 ( V_59 , V_17 ,
L_16 ,
F_53 ( V_84 -> V_87 ) ) ;
V_85 -> V_87 = V_84 -> V_87 ;
}
F_40 ( V_72 ) ;
return 2 ;
}
static int F_60 ( struct V_17 * V_17 ,
struct V_41 * V_42 ,
struct V_38 * V_39 )
{
struct V_40 * V_40 ;
struct V_88 * V_89 ;
struct V_56 * V_56 ;
T_3 * V_45 , * V_83 ;
struct V_46 * V_84 ;
T_5 V_90 ;
int V_91 ;
short V_26 = - 1 ;
int V_92 ;
V_40 = (struct V_40 * ) F_61 ( V_39 ) ;
if ( F_53 ( V_40 -> V_93 ) == V_94 ) {
V_89 = (struct V_88 * ) V_40 ;
V_26 = F_53 ( V_89 -> V_95 ) & V_96 ;
V_90 = F_53 ( V_89 -> V_97 ) ;
V_91 = sizeof( * V_89 ) ;
} else {
V_90 = F_53 ( V_40 -> V_93 ) ;
V_91 = V_55 ;
}
if ( V_90 != V_51 )
return 0 ;
if ( F_37 ( ! F_62 ( V_39 , V_91 + F_63 ( V_39 -> V_98 ) ) ) )
return 0 ;
V_40 = (struct V_40 * ) F_61 ( V_39 ) ;
V_56 = (struct V_56 * ) ( ( T_3 * ) V_40 + V_91 ) ;
if ( V_56 -> V_99 != F_47 ( V_100 ) )
return 0 ;
if ( V_56 -> V_101 != F_47 ( V_102 ) )
return 0 ;
if ( V_56 -> V_103 != V_6 )
return 0 ;
if ( V_56 -> V_104 != 4 )
return 0 ;
V_45 = ( T_3 * ) V_56 + sizeof( struct V_56 ) ;
V_83 = V_45 + V_6 + 4 ;
V_84 = (struct V_46 * ) V_83 ;
V_92 = F_59 ( V_17 , V_42 , V_45 , V_83 , V_40 ) ;
if ( V_92 == 1 )
F_27 ( V_59 , V_17 ,
L_17 ,
V_40 -> V_58 , V_26 , V_45 , V_83 ) ;
if ( V_92 < 2 )
return V_92 ;
F_41 ( V_17 , V_42 , V_26 ) ;
switch ( V_84 -> type ) {
case V_57 :
if ( F_58 ( V_17 , V_42 , V_45 ,
V_40 -> V_58 , V_26 ) )
return 1 ;
break;
case V_60 :
if ( F_57 ( V_17 , V_42 ,
V_40 -> V_58 , V_45 , V_26 ) )
return 1 ;
break;
case V_61 :
if ( F_52 ( V_17 , V_45 , V_40 -> V_58 , V_26 ) )
return 1 ;
break;
case V_62 :
if ( F_55 ( V_17 , V_42 , V_45 , V_40 , V_26 ) )
return 1 ;
break;
}
F_27 ( V_59 , V_17 ,
L_18 ,
V_40 -> V_58 , V_26 , V_45 , V_83 ) ;
return 1 ;
}
static void F_64 ( struct V_17 * V_17 , int V_105 )
{
struct V_11 * V_11 ;
struct V_7 * V_8 , * V_31 ;
struct V_20 * V_21 ;
struct V_18 * V_4 ;
T_4 * V_32 ;
int V_5 ;
V_4 = V_17 -> V_27 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_21 = & V_4 -> V_24 [ V_5 ] ;
V_32 = & V_4 -> V_33 [ V_5 ] ;
F_20 ( V_32 ) ;
F_21 (backbone_gw, node, node_tmp,
head, hash_entry) {
if ( V_105 )
goto V_106;
if ( ! F_65 ( V_11 -> V_75 ,
V_107 ) )
continue;
F_27 ( V_59 , V_11 -> V_17 ,
L_19 ,
V_11 -> V_30 ) ;
V_106:
if ( F_45 ( & V_11 -> V_76 ) )
F_54 ( & V_17 -> V_77 ) ;
F_19 ( V_11 ) ;
F_22 ( V_8 ) ;
F_6 ( V_11 ) ;
}
F_23 ( V_32 ) ;
}
}
static void F_66 ( struct V_17 * V_17 ,
struct V_41 * V_42 , int V_105 )
{
struct V_13 * V_13 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_18 * V_4 ;
int V_5 ;
V_4 = V_17 -> V_19 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_21 = & V_4 -> V_24 [ V_5 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
if ( V_105 )
goto V_106;
if ( ! F_56 ( V_13 -> V_11 -> V_30 ,
V_42 -> V_52 -> V_53 ) )
continue;
if ( ! F_65 ( V_13 -> V_75 ,
V_108 ) )
continue;
F_27 ( V_59 , V_17 ,
L_20 ,
V_13 -> V_25 , V_13 -> V_26 ) ;
V_106:
F_57 ( V_17 , V_42 ,
V_13 -> V_11 -> V_30 ,
V_13 -> V_25 , V_13 -> V_26 ) ;
}
F_17 () ;
}
}
void F_67 ( struct V_17 * V_17 ,
struct V_41 * V_42 ,
struct V_41 * V_109 )
{
struct V_11 * V_11 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_18 * V_4 ;
int V_5 ;
V_17 -> V_49 . V_87 =
F_47 ( F_49 ( 0 , V_42 -> V_52 -> V_53 , V_6 ) ) ;
if ( ! V_109 ) {
F_66 ( V_17 , NULL , 1 ) ;
F_64 ( V_17 , 1 ) ;
return;
}
V_4 = V_17 -> V_27 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_21 = & V_4 -> V_24 [ V_5 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( ! F_56 ( V_11 -> V_30 ,
V_109 -> V_52 -> V_53 ) )
continue;
memcpy ( V_11 -> V_30 ,
V_42 -> V_52 -> V_53 , V_6 ) ;
F_43 ( V_17 , V_11 ) ;
}
F_17 () ;
}
}
static void F_68 ( struct V_17 * V_17 )
{
F_69 ( & V_17 -> V_110 , V_111 ) ;
F_70 ( V_112 , & V_17 -> V_110 ,
F_71 ( V_113 ) ) ;
}
static void V_111 ( struct V_114 * V_115 )
{
struct V_116 * V_116 =
F_4 ( V_115 , struct V_116 , V_115 ) ;
struct V_17 * V_17 =
F_4 ( V_116 , struct V_17 , V_110 ) ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_11 * V_11 ;
struct V_18 * V_4 ;
struct V_41 * V_42 ;
int V_5 ;
V_42 = F_25 ( V_17 ) ;
if ( ! V_42 )
goto V_54;
F_66 ( V_17 , V_42 , 0 ) ;
F_64 ( V_17 , 0 ) ;
if ( ! F_45 ( & V_17 -> V_117 ) )
goto V_54;
V_4 = V_17 -> V_27 ;
if ( ! V_4 )
goto V_54;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_21 = & V_4 -> V_24 [ V_5 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( ! F_56 ( V_11 -> V_30 ,
V_42 -> V_52 -> V_53 ) )
continue;
V_11 -> V_75 = V_70 ;
F_43 ( V_17 , V_11 ) ;
}
F_17 () ;
}
V_54:
if ( V_42 )
F_32 ( V_42 ) ;
F_68 ( V_17 ) ;
}
int F_72 ( struct V_17 * V_17 )
{
int V_5 ;
T_3 V_49 [ V_6 ] = { 0xff , 0x43 , 0x05 , 0x00 , 0x00 , 0x00 } ;
struct V_41 * V_42 ;
F_27 ( V_59 , V_17 , L_21 ) ;
memcpy ( & V_17 -> V_49 . V_86 , V_49 , 3 ) ;
V_17 -> V_49 . type = 0 ;
V_42 = F_25 ( V_17 ) ;
if ( V_42 ) {
V_17 -> V_49 . V_87 =
F_47 ( F_49 ( 0 , V_42 -> V_52 -> V_53 ,
V_6 ) ) ;
F_32 ( V_42 ) ;
} else {
V_17 -> V_49 . V_87 = 0 ;
}
for ( V_5 = 0 ; V_5 < V_118 ; V_5 ++ )
V_17 -> V_119 [ V_5 ] . V_120 =
V_70 - F_71 ( V_121 ) ;
V_17 -> V_122 = 0 ;
if ( V_17 -> V_19 )
return 1 ;
V_17 -> V_19 = F_73 ( 128 ) ;
V_17 -> V_27 = F_73 ( 32 ) ;
if ( ! V_17 -> V_19 || ! V_17 -> V_27 )
return - 1 ;
F_27 ( V_59 , V_17 , L_22 ) ;
F_68 ( V_17 ) ;
return 1 ;
}
int F_74 ( struct V_17 * V_17 ,
struct V_123 * V_123 ,
int V_124 )
{
int V_5 , V_125 , V_126 ;
T_3 * V_127 ;
T_5 V_34 ;
struct V_128 * V_71 ;
V_125 = V_124 - sizeof( * V_123 ) ;
V_127 = ( T_3 * ) V_123 ;
V_127 += sizeof( * V_123 ) ;
V_34 = F_49 ( 0 , V_127 , V_125 ) ;
for ( V_5 = 0 ; V_5 < V_118 ; V_5 ++ ) {
V_126 = ( V_17 -> V_122 + V_5 ) % V_118 ;
V_71 = & V_17 -> V_119 [ V_126 ] ;
if ( F_65 ( V_71 -> V_120 , V_121 ) )
break;
if ( V_71 -> V_34 != V_34 )
continue;
if ( F_56 ( V_71 -> V_30 , V_123 -> V_30 ) )
continue;
return 1 ;
}
V_126 = ( V_17 -> V_122 + V_118 - 1 ) % V_118 ;
V_71 = & V_17 -> V_119 [ V_126 ] ;
V_71 -> V_34 = V_34 ;
V_71 -> V_120 = V_70 ;
memcpy ( V_71 -> V_30 , V_123 -> V_30 , V_6 ) ;
V_17 -> V_122 = V_126 ;
return 0 ;
}
int F_75 ( struct V_17 * V_17 , T_3 * V_30 )
{
struct V_18 * V_4 = V_17 -> V_27 ;
struct V_20 * V_21 ;
struct V_7 * V_8 ;
struct V_11 * V_11 ;
int V_5 ;
if ( ! F_45 ( & V_17 -> V_117 ) )
return 0 ;
if ( ! V_4 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_21 = & V_4 -> V_24 [ V_5 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( F_56 ( V_11 -> V_30 , V_30 ) ) {
F_17 () ;
return 1 ;
}
}
F_17 () ;
}
return 0 ;
}
int F_76 ( struct V_38 * V_39 ,
struct V_72 * V_72 , int V_124 )
{
struct V_40 * V_40 ;
struct V_88 * V_89 ;
struct V_11 * V_11 ;
short V_26 = - 1 ;
if ( ! F_45 ( & V_72 -> V_17 -> V_117 ) )
return 0 ;
if ( ! F_62 ( V_39 , V_124 + V_55 ) )
return 0 ;
V_40 = (struct V_40 * ) ( ( ( T_3 * ) V_39 -> V_1 ) + V_124 ) ;
if ( F_53 ( V_40 -> V_93 ) == V_94 ) {
if ( ! F_62 ( V_39 , V_124 + sizeof( struct V_88 ) ) )
return 0 ;
V_89 = (struct V_88 * ) ( ( ( T_3 * ) V_39 -> V_1 ) +
V_124 ) ;
V_26 = F_53 ( V_89 -> V_95 ) & V_96 ;
}
V_11 = F_18 ( V_72 -> V_17 ,
V_72 -> V_30 , V_26 ) ;
if ( ! V_11 )
return 0 ;
F_6 ( V_11 ) ;
return 1 ;
}
void F_77 ( struct V_17 * V_17 )
{
struct V_41 * V_42 ;
F_78 ( & V_17 -> V_110 ) ;
V_42 = F_25 ( V_17 ) ;
if ( V_17 -> V_19 ) {
F_66 ( V_17 , V_42 , 1 ) ;
F_79 ( V_17 -> V_19 ) ;
V_17 -> V_19 = NULL ;
}
if ( V_17 -> V_27 ) {
F_64 ( V_17 , 1 ) ;
F_79 ( V_17 -> V_27 ) ;
V_17 -> V_27 = NULL ;
}
if ( V_42 )
F_32 ( V_42 ) ;
}
int F_80 ( struct V_17 * V_17 , struct V_38 * V_39 , short V_26 ,
bool V_129 )
{
struct V_40 * V_40 ;
struct V_13 V_79 , * V_13 = NULL ;
struct V_41 * V_42 ;
int V_92 ;
V_40 = (struct V_40 * ) F_61 ( V_39 ) ;
V_42 = F_25 ( V_17 ) ;
if ( ! V_42 )
goto V_130;
if ( ! F_45 ( & V_17 -> V_117 ) )
goto V_131;
if ( F_37 ( F_45 ( & V_17 -> V_77 ) ) )
if ( F_81 ( V_40 -> V_63 ) && V_129 )
goto V_130;
memcpy ( V_79 . V_25 , V_40 -> V_58 , V_6 ) ;
V_79 . V_26 = V_26 ;
V_13 = F_13 ( V_17 , & V_79 ) ;
if ( ! V_13 ) {
F_58 ( V_17 , V_42 ,
V_42 -> V_52 -> V_53 ,
V_40 -> V_58 , V_26 ) ;
goto V_131;
}
if ( F_56 ( V_13 -> V_11 -> V_30 ,
V_42 -> V_52 -> V_53 ) ) {
V_13 -> V_75 = V_70 ;
goto V_131;
}
if ( F_81 ( V_40 -> V_63 ) && V_129 ) {
goto V_130;
} else {
F_58 ( V_17 , V_42 ,
V_42 -> V_52 -> V_53 ,
V_40 -> V_58 , V_26 ) ;
goto V_131;
}
V_131:
F_41 ( V_17 , V_42 , V_26 ) ;
V_92 = 0 ;
goto V_54;
V_130:
F_82 ( V_39 ) ;
V_92 = 1 ;
V_54:
if ( V_42 )
F_32 ( V_42 ) ;
if ( V_13 )
F_11 ( V_13 ) ;
return V_92 ;
}
int F_83 ( struct V_17 * V_17 , struct V_38 * V_39 , short V_26 )
{
struct V_40 * V_40 ;
struct V_13 V_79 , * V_13 = NULL ;
struct V_41 * V_42 ;
int V_92 = 0 ;
V_42 = F_25 ( V_17 ) ;
if ( ! V_42 )
goto V_54;
if ( ! F_45 ( & V_17 -> V_117 ) )
goto V_131;
F_29 ( V_39 ) ;
if ( F_60 ( V_17 , V_42 , V_39 ) )
goto V_130;
V_40 = (struct V_40 * ) F_61 ( V_39 ) ;
if ( F_37 ( F_45 ( & V_17 -> V_77 ) ) )
if ( F_81 ( V_40 -> V_63 ) )
goto V_130;
memcpy ( V_79 . V_25 , V_40 -> V_58 , V_6 ) ;
V_79 . V_26 = V_26 ;
V_13 = F_13 ( V_17 , & V_79 ) ;
if ( ! V_13 )
goto V_131;
if ( F_56 ( V_13 -> V_11 -> V_30 ,
V_42 -> V_52 -> V_53 ) ) {
F_57 ( V_17 , V_42 ,
V_42 -> V_52 -> V_53 ,
V_40 -> V_58 , V_26 ) ;
goto V_131;
}
if ( F_81 ( V_40 -> V_63 ) ) {
goto V_130;
} else {
goto V_131;
}
V_131:
F_41 ( V_17 , V_42 , V_26 ) ;
V_92 = 0 ;
goto V_54;
V_130:
V_92 = 1 ;
V_54:
if ( V_42 )
F_32 ( V_42 ) ;
if ( V_13 )
F_11 ( V_13 ) ;
return V_92 ;
}
int F_84 ( struct V_132 * V_133 , void * V_134 )
{
struct V_43 * V_52 = (struct V_43 * ) V_133 -> V_135 ;
struct V_17 * V_17 = F_85 ( V_52 ) ;
struct V_18 * V_4 = V_17 -> V_19 ;
struct V_13 * V_13 ;
struct V_41 * V_42 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
T_1 V_5 ;
bool V_136 ;
int V_92 = 0 ;
V_42 = F_25 ( V_17 ) ;
if ( ! V_42 ) {
V_92 = F_86 ( V_133 ,
L_23 ,
V_52 -> V_137 ) ;
goto V_54;
}
if ( V_42 -> V_138 != V_139 ) {
V_92 = F_86 ( V_133 ,
L_24 ,
V_52 -> V_137 ) ;
goto V_54;
}
F_86 ( V_133 ,
L_25 ,
V_52 -> V_137 , V_42 -> V_52 -> V_53 ,
F_53 ( V_17 -> V_49 . V_87 ) ) ;
F_86 ( V_133 , L_26 ,
L_27 , L_28 , L_29 , L_30 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_21 = & V_4 -> V_24 [ V_5 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
V_136 = F_56 ( V_13 -> V_11 -> V_30 ,
V_42 -> V_52 -> V_53 ) ;
F_86 ( V_133 , L_31 ,
V_13 -> V_25 , V_13 -> V_26 ,
V_13 -> V_11 -> V_30 ,
( V_136 ? 'x' : ' ' ) ,
V_13 -> V_11 -> V_34 ) ;
}
F_17 () ;
}
V_54:
if ( V_42 )
F_32 ( V_42 ) ;
return V_92 ;
}
