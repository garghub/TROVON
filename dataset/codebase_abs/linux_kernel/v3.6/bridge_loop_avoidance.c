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
static inline T_1 F_2 ( const void * V_1 ,
T_1 V_2 )
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
static int F_3 ( const struct V_7 * V_8 ,
const void * V_9 )
{
const void * V_10 = F_4 ( V_8 , struct V_11 ,
V_12 ) ;
return ( memcmp ( V_10 , V_9 , V_6 + sizeof( short ) ) == 0 ? 1 : 0 ) ;
}
static int F_5 ( const struct V_7 * V_8 ,
const void * V_9 )
{
const void * V_10 = F_4 ( V_8 , struct V_13 ,
V_12 ) ;
return ( memcmp ( V_10 , V_9 , V_6 + sizeof( short ) ) == 0 ? 1 : 0 ) ;
}
static void F_6 ( struct V_11 * V_14 )
{
if ( F_7 ( & V_14 -> V_15 ) )
F_8 ( V_14 , V_16 ) ;
}
static void F_9 ( struct V_17 * V_16 )
{
struct V_13 * V_18 ;
V_18 = F_4 ( V_16 , struct V_13 , V_16 ) ;
F_6 ( V_18 -> V_14 ) ;
F_10 ( V_18 ) ;
}
static void F_11 ( struct V_13 * V_18 )
{
if ( F_7 ( & V_18 -> V_15 ) )
F_12 ( & V_18 -> V_16 , F_9 ) ;
}
static struct V_13 * F_13 ( struct V_19 * V_20 ,
struct V_13 * V_1 )
{
struct V_21 * V_4 = V_20 -> V_22 ;
struct V_23 * V_24 ;
struct V_7 * V_8 ;
struct V_13 * V_18 ;
struct V_13 * V_25 = NULL ;
int V_26 ;
if ( ! V_4 )
return NULL ;
V_26 = F_1 ( V_1 , V_4 -> V_2 ) ;
V_24 = & V_4 -> V_27 [ V_26 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
if ( ! F_5 ( & V_18 -> V_12 , V_1 ) )
continue;
if ( ! F_16 ( & V_18 -> V_15 ) )
continue;
V_25 = V_18 ;
break;
}
F_17 () ;
return V_25 ;
}
static struct V_11 *
F_18 ( struct V_19 * V_20 ,
T_3 * V_28 , short V_29 )
{
struct V_21 * V_4 = V_20 -> V_30 ;
struct V_23 * V_24 ;
struct V_7 * V_8 ;
struct V_11 V_31 , * V_14 ;
struct V_11 * V_32 = NULL ;
int V_26 ;
if ( ! V_4 )
return NULL ;
memcpy ( V_31 . V_33 , V_28 , V_6 ) ;
V_31 . V_29 = V_29 ;
V_26 = F_2 ( & V_31 , V_4 -> V_2 ) ;
V_24 = & V_4 -> V_27 [ V_26 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( ! F_3 ( & V_14 -> V_12 ,
& V_31 ) )
continue;
if ( ! F_16 ( & V_14 -> V_15 ) )
continue;
V_32 = V_14 ;
break;
}
F_17 () ;
return V_32 ;
}
static void
F_19 ( struct V_11 * V_14 )
{
struct V_21 * V_4 ;
struct V_7 * V_8 , * V_34 ;
struct V_23 * V_24 ;
struct V_13 * V_18 ;
int V_5 ;
T_4 * V_35 ;
V_4 = V_14 -> V_20 -> V_22 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_24 = & V_4 -> V_27 [ V_5 ] ;
V_35 = & V_4 -> V_36 [ V_5 ] ;
F_20 ( V_35 ) ;
F_21 (claim, node, node_tmp,
head, hash_entry) {
if ( V_18 -> V_14 != V_14 )
continue;
F_11 ( V_18 ) ;
F_22 ( V_8 ) ;
}
F_23 ( V_35 ) ;
}
V_14 -> V_37 = V_38 ;
}
static void F_24 ( struct V_19 * V_20 , T_3 * V_39 ,
short V_29 , int V_40 )
{
struct V_41 * V_42 ;
struct V_43 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
T_3 * V_48 ;
struct V_49 V_50 ;
T_5 V_51 = 0 ;
V_45 = F_25 ( V_20 ) ;
if ( ! V_45 )
return;
memcpy ( & V_50 , & V_20 -> V_52 ,
sizeof( V_50 ) ) ;
V_50 . type = V_40 ;
V_47 = V_45 -> V_47 ;
V_42 = F_26 ( V_53 , V_54 ,
V_51 ,
V_45 -> V_47 ,
V_51 ,
NULL ,
V_45 -> V_55 -> V_56 ,
( T_3 * ) & V_50 ) ;
if ( ! V_42 )
goto V_57;
V_43 = (struct V_43 * ) V_42 -> V_1 ;
V_48 = ( T_3 * ) V_43 + V_58 + sizeof( struct V_59 ) ;
switch ( V_40 ) {
case V_60 :
memcpy ( V_43 -> V_61 , V_39 , V_6 ) ;
F_27 ( V_62 , V_20 ,
L_1 , V_39 , V_29 ) ;
break;
case V_63 :
memcpy ( V_48 , V_39 , V_6 ) ;
F_27 ( V_62 , V_20 ,
L_2 , V_39 ,
V_29 ) ;
break;
case V_64 :
memcpy ( V_48 , V_39 , V_6 ) ;
F_27 ( V_62 , V_20 ,
L_3 ,
V_43 -> V_61 , V_29 ) ;
break;
case V_65 :
memcpy ( V_48 , V_39 , V_6 ) ;
memcpy ( V_43 -> V_66 , V_39 , V_6 ) ;
F_27 ( V_62 , V_20 ,
L_4 ,
V_43 -> V_61 , V_43 -> V_66 , V_29 ) ;
break;
}
if ( V_29 != - 1 )
V_42 = F_28 ( V_42 , V_29 ) ;
F_29 ( V_42 ) ;
V_42 -> V_67 = F_30 ( V_42 , V_47 ) ;
V_20 -> V_68 . V_69 ++ ;
V_20 -> V_68 . V_70 += V_42 -> V_71 + V_58 ;
V_47 -> V_72 = V_73 ;
F_31 ( V_42 ) ;
V_57:
if ( V_45 )
F_32 ( V_45 ) ;
}
static struct V_11 *
F_33 ( struct V_19 * V_20 , T_3 * V_33 ,
short V_29 )
{
struct V_11 * V_74 ;
struct V_75 * V_76 ;
int V_77 ;
V_74 = F_18 ( V_20 , V_33 , V_29 ) ;
if ( V_74 )
return V_74 ;
F_27 ( V_62 , V_20 ,
L_5 ,
V_33 , V_29 ) ;
V_74 = F_34 ( sizeof( * V_74 ) , V_78 ) ;
if ( ! V_74 )
return NULL ;
V_74 -> V_29 = V_29 ;
V_74 -> V_79 = V_73 ;
V_74 -> V_37 = V_38 ;
V_74 -> V_20 = V_20 ;
F_35 ( & V_74 -> V_80 , 0 ) ;
memcpy ( V_74 -> V_33 , V_33 , V_6 ) ;
F_35 ( & V_74 -> V_15 , 2 ) ;
V_77 = F_36 ( V_20 -> V_30 ,
F_3 ,
F_2 , V_74 ,
& V_74 -> V_12 ) ;
if ( F_37 ( V_77 != 0 ) ) {
F_10 ( V_74 ) ;
return NULL ;
}
V_76 = F_38 ( V_20 , V_33 ) ;
if ( V_76 ) {
F_39 ( V_20 , V_76 ,
L_6 ) ;
F_40 ( V_76 ) ;
}
return V_74 ;
}
static void
F_41 ( struct V_19 * V_20 ,
struct V_44 * V_45 ,
short V_29 )
{
struct V_11 * V_14 ;
V_14 = F_33 ( V_20 ,
V_45 -> V_55 -> V_56 ,
V_29 ) ;
if ( F_37 ( ! V_14 ) )
return;
V_14 -> V_79 = V_73 ;
F_6 ( V_14 ) ;
}
static void F_42 ( struct V_19 * V_20 ,
struct V_44 * V_45 ,
short V_29 )
{
struct V_7 * V_8 ;
struct V_23 * V_24 ;
struct V_21 * V_4 ;
struct V_13 * V_18 ;
struct V_11 * V_14 ;
int V_5 ;
F_27 ( V_62 , V_20 ,
L_7 ) ;
V_14 = F_18 ( V_20 ,
V_45 -> V_55 -> V_56 ,
V_29 ) ;
if ( ! V_14 )
return;
V_4 = V_20 -> V_22 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_24 = & V_4 -> V_27 [ V_5 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
if ( V_18 -> V_14 != V_14 )
continue;
F_24 ( V_20 , V_18 -> V_28 , V_18 -> V_29 ,
V_60 ) ;
}
F_17 () ;
}
F_43 ( V_20 , V_14 ) ;
F_6 ( V_14 ) ;
}
static void F_44 ( struct V_11 * V_14 )
{
F_19 ( V_14 ) ;
F_27 ( V_62 , V_14 -> V_20 ,
L_8 , V_14 -> V_33 ) ;
F_24 ( V_14 -> V_20 , V_14 -> V_33 ,
V_14 -> V_29 , V_65 ) ;
if ( ! F_45 ( & V_14 -> V_80 ) ) {
F_46 ( & V_14 -> V_20 -> V_81 ) ;
F_35 ( & V_14 -> V_80 , 1 ) ;
}
}
static void F_43 ( struct V_19 * V_20 ,
struct V_11 * V_14 )
{
T_3 V_39 [ V_6 ] ;
T_6 V_37 ;
memcpy ( V_39 , V_82 , 4 ) ;
V_37 = F_47 ( V_14 -> V_37 ) ;
memcpy ( & V_39 [ 4 ] , & V_37 , 2 ) ;
F_24 ( V_20 , V_39 , V_14 -> V_29 ,
V_64 ) ;
}
static void F_48 ( struct V_19 * V_20 ,
const T_3 * V_39 , const short V_29 ,
struct V_11 * V_14 )
{
struct V_13 * V_18 ;
struct V_13 V_83 ;
int V_77 ;
memcpy ( V_83 . V_28 , V_39 , V_6 ) ;
V_83 . V_29 = V_29 ;
V_18 = F_13 ( V_20 , & V_83 ) ;
if ( ! V_18 ) {
V_18 = F_34 ( sizeof( * V_18 ) , V_78 ) ;
if ( ! V_18 )
return;
memcpy ( V_18 -> V_28 , V_39 , V_6 ) ;
V_18 -> V_29 = V_29 ;
V_18 -> V_79 = V_73 ;
V_18 -> V_14 = V_14 ;
F_35 ( & V_18 -> V_15 , 2 ) ;
F_27 ( V_62 , V_20 ,
L_9 ,
V_39 , V_29 ) ;
V_77 = F_36 ( V_20 -> V_22 ,
F_5 ,
F_1 , V_18 ,
& V_18 -> V_12 ) ;
if ( F_37 ( V_77 != 0 ) ) {
F_10 ( V_18 ) ;
return;
}
} else {
V_18 -> V_79 = V_73 ;
if ( V_18 -> V_14 == V_14 )
goto V_84;
F_27 ( V_62 , V_20 ,
L_10 ,
V_39 , V_29 ) ;
V_18 -> V_14 -> V_37 ^=
F_49 ( 0 , V_18 -> V_28 , V_6 ) ;
F_6 ( V_18 -> V_14 ) ;
}
F_46 ( & V_14 -> V_15 ) ;
V_18 -> V_14 = V_14 ;
V_14 -> V_37 ^= F_49 ( 0 , V_18 -> V_28 , V_6 ) ;
V_14 -> V_79 = V_73 ;
V_84:
F_11 ( V_18 ) ;
}
static void F_50 ( struct V_19 * V_20 ,
const T_3 * V_39 , const short V_29 )
{
struct V_13 V_83 , * V_18 ;
memcpy ( V_83 . V_28 , V_39 , V_6 ) ;
V_83 . V_29 = V_29 ;
V_18 = F_13 ( V_20 , & V_83 ) ;
if ( ! V_18 )
return;
F_27 ( V_62 , V_20 , L_11 ,
V_39 , V_29 ) ;
F_51 ( V_20 -> V_22 , F_5 ,
F_1 , V_18 ) ;
F_11 ( V_18 ) ;
V_18 -> V_14 -> V_37 ^= F_49 ( 0 , V_18 -> V_28 , V_6 ) ;
F_11 ( V_18 ) ;
}
static int F_52 ( struct V_19 * V_20 ,
T_3 * V_85 , T_3 * V_86 ,
short V_29 )
{
struct V_11 * V_14 ;
T_7 V_37 ;
if ( memcmp ( V_85 , V_82 , 4 ) != 0 )
return 0 ;
V_14 = F_33 ( V_20 , V_86 , V_29 ) ;
if ( F_37 ( ! V_14 ) )
return 1 ;
V_14 -> V_79 = V_73 ;
V_37 = F_53 ( * ( ( T_6 * ) ( & V_85 [ 4 ] ) ) ) ;
F_27 ( V_62 , V_20 ,
L_12 ,
V_29 , V_14 -> V_33 , V_37 ) ;
if ( V_14 -> V_37 != V_37 ) {
F_27 ( V_62 , V_14 -> V_20 ,
L_13 ,
V_14 -> V_33 , V_14 -> V_29 ,
V_14 -> V_37 , V_37 ) ;
F_44 ( V_14 ) ;
} else {
if ( F_45 ( & V_14 -> V_80 ) ) {
F_54 ( & V_14 -> V_20 -> V_81 ) ;
F_35 ( & V_14 -> V_80 , 0 ) ;
}
}
F_6 ( V_14 ) ;
return 1 ;
}
static int F_55 ( struct V_19 * V_20 ,
struct V_44 * V_45 ,
T_3 * V_86 ,
struct V_43 * V_43 , short V_29 )
{
if ( ! F_56 ( V_86 , V_43 -> V_66 ) )
return 0 ;
if ( ! F_56 ( V_43 -> V_66 , V_45 -> V_55 -> V_56 ) )
return 1 ;
F_27 ( V_62 , V_20 ,
L_14 ,
V_29 , V_43 -> V_61 ) ;
F_42 ( V_20 , V_45 , V_29 ) ;
return 1 ;
}
static int F_57 ( struct V_19 * V_20 ,
struct V_44 * V_45 ,
T_3 * V_86 ,
T_3 * V_87 , short V_29 )
{
struct V_11 * V_14 ;
if ( V_45 && F_56 ( V_86 ,
V_45 -> V_55 -> V_56 ) )
F_24 ( V_20 , V_87 , V_29 ,
V_63 ) ;
V_14 = F_18 ( V_20 , V_86 , V_29 ) ;
if ( ! V_14 )
return 1 ;
F_27 ( V_62 , V_20 ,
L_15 ,
V_87 , V_29 , V_14 -> V_33 ) ;
F_50 ( V_20 , V_87 , V_29 ) ;
F_6 ( V_14 ) ;
return 1 ;
}
static int F_58 ( struct V_19 * V_20 ,
struct V_44 * V_45 ,
T_3 * V_86 , T_3 * V_87 ,
short V_29 )
{
struct V_11 * V_14 ;
V_14 = F_33 ( V_20 , V_86 , V_29 ) ;
if ( F_37 ( ! V_14 ) )
return 1 ;
F_48 ( V_20 , V_87 , V_29 , V_14 ) ;
if ( F_56 ( V_86 , V_45 -> V_55 -> V_56 ) )
F_24 ( V_20 , V_87 , V_29 ,
V_60 ) ;
F_6 ( V_14 ) ;
return 1 ;
}
static int F_59 ( struct V_19 * V_20 ,
struct V_44 * V_45 ,
T_3 * V_48 , T_3 * V_88 ,
struct V_43 * V_43 )
{
T_3 * V_86 ;
struct V_75 * V_76 ;
struct V_49 * V_89 , * V_90 ;
V_89 = (struct V_49 * ) V_88 ;
V_90 = & V_20 -> V_52 ;
if ( memcmp ( V_89 -> V_91 , V_90 -> V_91 ,
sizeof( V_89 -> V_91 ) ) != 0 )
return 0 ;
switch ( V_89 -> type ) {
case V_60 :
V_86 = V_48 ;
break;
case V_65 :
case V_64 :
case V_63 :
V_86 = V_43 -> V_61 ;
break;
default:
return 0 ;
}
if ( F_56 ( V_86 , V_45 -> V_55 -> V_56 ) )
return 0 ;
if ( V_89 -> V_92 == V_90 -> V_92 )
return 2 ;
V_76 = F_38 ( V_20 , V_86 ) ;
if ( ! V_76 )
return 1 ;
if ( F_53 ( V_89 -> V_92 ) > F_53 ( V_90 -> V_92 ) ) {
F_27 ( V_62 , V_20 ,
L_16 ,
F_53 ( V_89 -> V_92 ) ) ;
V_90 -> V_92 = V_89 -> V_92 ;
}
F_40 ( V_76 ) ;
return 2 ;
}
static int F_60 ( struct V_19 * V_20 ,
struct V_44 * V_45 ,
struct V_41 * V_42 )
{
struct V_43 * V_43 ;
struct V_93 * V_94 ;
struct V_59 * V_59 ;
T_3 * V_48 , * V_88 ;
struct V_49 * V_89 ;
T_7 V_95 ;
int V_96 ;
short V_29 = - 1 ;
int V_97 ;
V_43 = (struct V_43 * ) F_61 ( V_42 ) ;
if ( F_53 ( V_43 -> V_98 ) == V_99 ) {
V_94 = (struct V_93 * ) V_43 ;
V_29 = F_53 ( V_94 -> V_100 ) & V_101 ;
V_95 = F_53 ( V_94 -> V_102 ) ;
V_96 = sizeof( * V_94 ) ;
} else {
V_95 = F_53 ( V_43 -> V_98 ) ;
V_96 = V_58 ;
}
if ( V_95 != V_54 )
return 0 ;
if ( F_37 ( ! F_62 ( V_42 , V_96 + F_63 ( V_42 -> V_103 ) ) ) )
return 0 ;
V_43 = (struct V_43 * ) F_61 ( V_42 ) ;
V_59 = (struct V_59 * ) ( ( T_3 * ) V_43 + V_96 ) ;
if ( V_59 -> V_104 != F_47 ( V_105 ) )
return 0 ;
if ( V_59 -> V_106 != F_47 ( V_107 ) )
return 0 ;
if ( V_59 -> V_108 != V_6 )
return 0 ;
if ( V_59 -> V_109 != 4 )
return 0 ;
V_48 = ( T_3 * ) V_59 + sizeof( struct V_59 ) ;
V_88 = V_48 + V_6 + 4 ;
V_89 = (struct V_49 * ) V_88 ;
V_97 = F_59 ( V_20 , V_45 , V_48 , V_88 ,
V_43 ) ;
if ( V_97 == 1 )
F_27 ( V_62 , V_20 ,
L_17 ,
V_43 -> V_61 , V_29 , V_48 , V_88 ) ;
if ( V_97 < 2 )
return V_97 ;
F_41 ( V_20 , V_45 , V_29 ) ;
switch ( V_89 -> type ) {
case V_60 :
if ( F_58 ( V_20 , V_45 , V_48 ,
V_43 -> V_61 , V_29 ) )
return 1 ;
break;
case V_63 :
if ( F_57 ( V_20 , V_45 ,
V_43 -> V_61 , V_48 , V_29 ) )
return 1 ;
break;
case V_64 :
if ( F_52 ( V_20 , V_48 , V_43 -> V_61 ,
V_29 ) )
return 1 ;
break;
case V_65 :
if ( F_55 ( V_20 , V_45 , V_48 , V_43 ,
V_29 ) )
return 1 ;
break;
}
F_27 ( V_62 , V_20 ,
L_18 ,
V_43 -> V_61 , V_29 , V_48 , V_88 ) ;
return 1 ;
}
static void F_64 ( struct V_19 * V_20 , int V_110 )
{
struct V_11 * V_14 ;
struct V_7 * V_8 , * V_34 ;
struct V_23 * V_24 ;
struct V_21 * V_4 ;
T_4 * V_35 ;
int V_5 ;
V_4 = V_20 -> V_30 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_24 = & V_4 -> V_27 [ V_5 ] ;
V_35 = & V_4 -> V_36 [ V_5 ] ;
F_20 ( V_35 ) ;
F_21 (backbone_gw, node, node_tmp,
head, hash_entry) {
if ( V_110 )
goto V_111;
if ( ! F_65 ( V_14 -> V_79 ,
V_112 ) )
continue;
F_27 ( V_62 , V_14 -> V_20 ,
L_19 ,
V_14 -> V_33 ) ;
V_111:
if ( F_45 ( & V_14 -> V_80 ) )
F_54 ( & V_20 -> V_81 ) ;
F_19 ( V_14 ) ;
F_22 ( V_8 ) ;
F_6 ( V_14 ) ;
}
F_23 ( V_35 ) ;
}
}
static void F_66 ( struct V_19 * V_20 ,
struct V_44 * V_45 ,
int V_110 )
{
struct V_13 * V_18 ;
struct V_7 * V_8 ;
struct V_23 * V_24 ;
struct V_21 * V_4 ;
int V_5 ;
V_4 = V_20 -> V_22 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_24 = & V_4 -> V_27 [ V_5 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
if ( V_110 )
goto V_111;
if ( ! F_56 ( V_18 -> V_14 -> V_33 ,
V_45 -> V_55 -> V_56 ) )
continue;
if ( ! F_65 ( V_18 -> V_79 ,
V_113 ) )
continue;
F_27 ( V_62 , V_20 ,
L_20 ,
V_18 -> V_28 , V_18 -> V_29 ) ;
V_111:
F_57 ( V_20 , V_45 ,
V_18 -> V_14 -> V_33 ,
V_18 -> V_28 , V_18 -> V_29 ) ;
}
F_17 () ;
}
}
void F_67 ( struct V_19 * V_20 ,
struct V_44 * V_45 ,
struct V_44 * V_114 )
{
struct V_11 * V_14 ;
struct V_7 * V_8 ;
struct V_23 * V_24 ;
struct V_21 * V_4 ;
int V_5 ;
V_20 -> V_52 . V_92 =
F_47 ( F_49 ( 0 , V_45 -> V_55 -> V_56 , V_6 ) ) ;
if ( ! V_114 ) {
F_66 ( V_20 , NULL , 1 ) ;
F_64 ( V_20 , 1 ) ;
return;
}
V_4 = V_20 -> V_30 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_24 = & V_4 -> V_27 [ V_5 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( ! F_56 ( V_14 -> V_33 ,
V_114 -> V_55 -> V_56 ) )
continue;
memcpy ( V_14 -> V_33 ,
V_45 -> V_55 -> V_56 , V_6 ) ;
F_43 ( V_20 , V_14 ) ;
}
F_17 () ;
}
}
static void F_68 ( struct V_19 * V_20 )
{
F_69 ( & V_20 -> V_115 , V_116 ) ;
F_70 ( V_117 , & V_20 -> V_115 ,
F_71 ( V_118 ) ) ;
}
static void V_116 ( struct V_119 * V_120 )
{
struct V_121 * V_121 =
F_4 ( V_120 , struct V_121 , V_120 ) ;
struct V_19 * V_20 ;
struct V_7 * V_8 ;
struct V_23 * V_24 ;
struct V_11 * V_14 ;
struct V_21 * V_4 ;
struct V_44 * V_45 ;
int V_5 ;
V_20 = F_4 ( V_121 , struct V_19 , V_115 ) ;
V_45 = F_25 ( V_20 ) ;
if ( ! V_45 )
goto V_57;
F_66 ( V_20 , V_45 , 0 ) ;
F_64 ( V_20 , 0 ) ;
if ( ! F_45 ( & V_20 -> V_122 ) )
goto V_57;
V_4 = V_20 -> V_30 ;
if ( ! V_4 )
goto V_57;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_24 = & V_4 -> V_27 [ V_5 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( ! F_56 ( V_14 -> V_33 ,
V_45 -> V_55 -> V_56 ) )
continue;
V_14 -> V_79 = V_73 ;
F_43 ( V_20 , V_14 ) ;
}
F_17 () ;
}
V_57:
if ( V_45 )
F_32 ( V_45 ) ;
F_68 ( V_20 ) ;
}
int F_72 ( struct V_19 * V_20 )
{
int V_5 ;
T_3 V_52 [ V_6 ] = { 0xff , 0x43 , 0x05 , 0x00 , 0x00 , 0x00 } ;
struct V_44 * V_45 ;
F_27 ( V_62 , V_20 , L_21 ) ;
memcpy ( & V_20 -> V_52 . V_91 , V_52 , 3 ) ;
V_20 -> V_52 . type = 0 ;
V_45 = F_25 ( V_20 ) ;
if ( V_45 ) {
V_20 -> V_52 . V_92 =
F_47 ( F_49 ( 0 , V_45 -> V_55 -> V_56 ,
V_6 ) ) ;
F_32 ( V_45 ) ;
} else {
V_20 -> V_52 . V_92 = 0 ;
}
for ( V_5 = 0 ; V_5 < V_123 ; V_5 ++ )
V_20 -> V_124 [ V_5 ] . V_125 =
V_73 - F_71 ( V_126 ) ;
V_20 -> V_127 = 0 ;
if ( V_20 -> V_22 )
return 0 ;
V_20 -> V_22 = F_73 ( 128 ) ;
V_20 -> V_30 = F_73 ( 32 ) ;
if ( ! V_20 -> V_22 || ! V_20 -> V_30 )
return - V_128 ;
F_74 ( V_20 -> V_22 ,
& V_129 ) ;
F_74 ( V_20 -> V_30 ,
& V_130 ) ;
F_27 ( V_62 , V_20 , L_22 ) ;
F_68 ( V_20 ) ;
return 0 ;
}
int F_75 ( struct V_19 * V_20 ,
struct V_131 * V_132 ,
int V_133 )
{
int V_5 , V_134 , V_135 ;
T_3 * V_136 ;
T_7 V_37 ;
struct V_137 * V_74 ;
V_134 = V_133 - sizeof( * V_132 ) ;
V_136 = ( T_3 * ) V_132 ;
V_136 += sizeof( * V_132 ) ;
V_37 = F_49 ( 0 , V_136 , V_134 ) ;
for ( V_5 = 0 ; V_5 < V_123 ; V_5 ++ ) {
V_135 = ( V_20 -> V_127 + V_5 ) % V_123 ;
V_74 = & V_20 -> V_124 [ V_135 ] ;
if ( F_65 ( V_74 -> V_125 ,
V_126 ) )
break;
if ( V_74 -> V_37 != V_37 )
continue;
if ( F_56 ( V_74 -> V_33 , V_132 -> V_33 ) )
continue;
return 1 ;
}
V_135 = ( V_20 -> V_127 + V_123 - 1 ) ;
V_135 %= V_123 ;
V_74 = & V_20 -> V_124 [ V_135 ] ;
V_74 -> V_37 = V_37 ;
V_74 -> V_125 = V_73 ;
memcpy ( V_74 -> V_33 , V_132 -> V_33 , V_6 ) ;
V_20 -> V_127 = V_135 ;
return 0 ;
}
int F_76 ( struct V_19 * V_20 , T_3 * V_33 )
{
struct V_21 * V_4 = V_20 -> V_30 ;
struct V_23 * V_24 ;
struct V_7 * V_8 ;
struct V_11 * V_14 ;
int V_5 ;
if ( ! F_45 ( & V_20 -> V_122 ) )
return 0 ;
if ( ! V_4 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_24 = & V_4 -> V_27 [ V_5 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( F_56 ( V_14 -> V_33 , V_33 ) ) {
F_17 () ;
return 1 ;
}
}
F_17 () ;
}
return 0 ;
}
int F_77 ( struct V_41 * V_42 ,
struct V_75 * V_76 , int V_133 )
{
struct V_43 * V_43 ;
struct V_93 * V_94 ;
struct V_11 * V_14 ;
short V_29 = - 1 ;
if ( ! F_45 ( & V_76 -> V_20 -> V_122 ) )
return 0 ;
if ( ! F_62 ( V_42 , V_133 + V_58 ) )
return 0 ;
V_43 = (struct V_43 * ) ( ( ( T_3 * ) V_42 -> V_1 ) + V_133 ) ;
if ( F_53 ( V_43 -> V_98 ) == V_99 ) {
if ( ! F_62 ( V_42 , V_133 + sizeof( struct V_93 ) ) )
return 0 ;
V_94 = (struct V_93 * ) ( ( ( T_3 * ) V_42 -> V_1 ) +
V_133 ) ;
V_29 = F_53 ( V_94 -> V_100 ) & V_101 ;
}
V_14 = F_18 ( V_76 -> V_20 ,
V_76 -> V_33 , V_29 ) ;
if ( ! V_14 )
return 0 ;
F_6 ( V_14 ) ;
return 1 ;
}
void F_78 ( struct V_19 * V_20 )
{
struct V_44 * V_45 ;
F_79 ( & V_20 -> V_115 ) ;
V_45 = F_25 ( V_20 ) ;
if ( V_20 -> V_22 ) {
F_66 ( V_20 , V_45 , 1 ) ;
F_80 ( V_20 -> V_22 ) ;
V_20 -> V_22 = NULL ;
}
if ( V_20 -> V_30 ) {
F_64 ( V_20 , 1 ) ;
F_80 ( V_20 -> V_30 ) ;
V_20 -> V_30 = NULL ;
}
if ( V_45 )
F_32 ( V_45 ) ;
}
int F_81 ( struct V_19 * V_20 , struct V_41 * V_42 , short V_29 ,
bool V_138 )
{
struct V_43 * V_43 ;
struct V_13 V_83 , * V_18 = NULL ;
struct V_44 * V_45 ;
int V_97 ;
V_43 = (struct V_43 * ) F_61 ( V_42 ) ;
V_45 = F_25 ( V_20 ) ;
if ( ! V_45 )
goto V_139;
if ( ! F_45 ( & V_20 -> V_122 ) )
goto V_140;
if ( F_37 ( F_45 ( & V_20 -> V_81 ) ) )
if ( F_82 ( V_43 -> V_66 ) && V_138 )
goto V_139;
memcpy ( V_83 . V_28 , V_43 -> V_61 , V_6 ) ;
V_83 . V_29 = V_29 ;
V_18 = F_13 ( V_20 , & V_83 ) ;
if ( ! V_18 ) {
F_58 ( V_20 , V_45 ,
V_45 -> V_55 -> V_56 ,
V_43 -> V_61 , V_29 ) ;
goto V_140;
}
if ( F_56 ( V_18 -> V_14 -> V_33 ,
V_45 -> V_55 -> V_56 ) ) {
V_18 -> V_79 = V_73 ;
goto V_140;
}
if ( F_82 ( V_43 -> V_66 ) && V_138 ) {
goto V_139;
} else {
F_58 ( V_20 , V_45 ,
V_45 -> V_55 -> V_56 ,
V_43 -> V_61 , V_29 ) ;
goto V_140;
}
V_140:
F_41 ( V_20 , V_45 , V_29 ) ;
V_97 = 0 ;
goto V_57;
V_139:
F_83 ( V_42 ) ;
V_97 = 1 ;
V_57:
if ( V_45 )
F_32 ( V_45 ) ;
if ( V_18 )
F_11 ( V_18 ) ;
return V_97 ;
}
int F_84 ( struct V_19 * V_20 , struct V_41 * V_42 , short V_29 )
{
struct V_43 * V_43 ;
struct V_13 V_83 , * V_18 = NULL ;
struct V_44 * V_45 ;
int V_97 = 0 ;
V_45 = F_25 ( V_20 ) ;
if ( ! V_45 )
goto V_57;
if ( ! F_45 ( & V_20 -> V_122 ) )
goto V_140;
F_29 ( V_42 ) ;
if ( F_60 ( V_20 , V_45 , V_42 ) )
goto V_139;
V_43 = (struct V_43 * ) F_61 ( V_42 ) ;
if ( F_37 ( F_45 ( & V_20 -> V_81 ) ) )
if ( F_82 ( V_43 -> V_66 ) )
goto V_139;
memcpy ( V_83 . V_28 , V_43 -> V_61 , V_6 ) ;
V_83 . V_29 = V_29 ;
V_18 = F_13 ( V_20 , & V_83 ) ;
if ( ! V_18 )
goto V_140;
if ( F_56 ( V_18 -> V_14 -> V_33 ,
V_45 -> V_55 -> V_56 ) ) {
F_57 ( V_20 , V_45 ,
V_45 -> V_55 -> V_56 ,
V_43 -> V_61 , V_29 ) ;
goto V_140;
}
if ( F_82 ( V_43 -> V_66 ) ) {
goto V_139;
} else {
goto V_140;
}
V_140:
F_41 ( V_20 , V_45 , V_29 ) ;
V_97 = 0 ;
goto V_57;
V_139:
V_97 = 1 ;
V_57:
if ( V_45 )
F_32 ( V_45 ) ;
if ( V_18 )
F_11 ( V_18 ) ;
return V_97 ;
}
int F_85 ( struct V_141 * V_142 , void * V_143 )
{
struct V_46 * V_55 = (struct V_46 * ) V_142 -> V_144 ;
struct V_19 * V_20 = F_86 ( V_55 ) ;
struct V_21 * V_4 = V_20 -> V_22 ;
struct V_13 * V_18 ;
struct V_44 * V_45 ;
struct V_7 * V_8 ;
struct V_23 * V_24 ;
T_1 V_5 ;
bool V_145 ;
int V_97 = 0 ;
T_3 * V_146 ;
V_45 = F_25 ( V_20 ) ;
if ( ! V_45 ) {
V_97 = F_87 ( V_142 ,
L_23 ,
V_55 -> V_147 ) ;
goto V_57;
}
if ( V_45 -> V_148 != V_149 ) {
V_97 = F_87 ( V_142 ,
L_24 ,
V_55 -> V_147 ) ;
goto V_57;
}
V_146 = V_45 -> V_55 -> V_56 ;
F_87 ( V_142 ,
L_25 ,
V_55 -> V_147 , V_146 ,
F_53 ( V_20 -> V_52 . V_92 ) ) ;
F_87 ( V_142 , L_26 ,
L_27 , L_28 , L_29 , L_30 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_24 = & V_4 -> V_27 [ V_5 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
V_145 = F_56 ( V_18 -> V_14 -> V_33 ,
V_146 ) ;
F_87 ( V_142 , L_31 ,
V_18 -> V_28 , V_18 -> V_29 ,
V_18 -> V_14 -> V_33 ,
( V_145 ? 'x' : ' ' ) ,
V_18 -> V_14 -> V_37 ) ;
}
F_17 () ;
}
V_57:
if ( V_45 )
F_32 ( V_45 ) ;
return V_97 ;
}
