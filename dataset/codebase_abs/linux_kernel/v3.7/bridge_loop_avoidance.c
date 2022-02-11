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
struct V_21 * V_4 = V_20 -> V_22 . V_23 ;
struct V_24 * V_25 ;
struct V_7 * V_8 ;
struct V_13 * V_18 ;
struct V_13 * V_26 = NULL ;
int V_27 ;
if ( ! V_4 )
return NULL ;
V_27 = F_1 ( V_1 , V_4 -> V_2 ) ;
V_25 = & V_4 -> V_28 [ V_27 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
if ( ! F_5 ( & V_18 -> V_12 , V_1 ) )
continue;
if ( ! F_16 ( & V_18 -> V_15 ) )
continue;
V_26 = V_18 ;
break;
}
F_17 () ;
return V_26 ;
}
static struct V_11 *
F_18 ( struct V_19 * V_20 ,
T_3 * V_29 , short V_30 )
{
struct V_21 * V_4 = V_20 -> V_22 . V_31 ;
struct V_24 * V_25 ;
struct V_7 * V_8 ;
struct V_11 V_32 , * V_14 ;
struct V_11 * V_33 = NULL ;
int V_27 ;
if ( ! V_4 )
return NULL ;
memcpy ( V_32 . V_34 , V_29 , V_6 ) ;
V_32 . V_30 = V_30 ;
V_27 = F_2 ( & V_32 , V_4 -> V_2 ) ;
V_25 = & V_4 -> V_28 [ V_27 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( ! F_3 ( & V_14 -> V_12 ,
& V_32 ) )
continue;
if ( ! F_16 ( & V_14 -> V_15 ) )
continue;
V_33 = V_14 ;
break;
}
F_17 () ;
return V_33 ;
}
static void
F_19 ( struct V_11 * V_14 )
{
struct V_21 * V_4 ;
struct V_7 * V_8 , * V_35 ;
struct V_24 * V_25 ;
struct V_13 * V_18 ;
int V_5 ;
T_4 * V_36 ;
V_4 = V_14 -> V_20 -> V_22 . V_23 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_25 = & V_4 -> V_28 [ V_5 ] ;
V_36 = & V_4 -> V_37 [ V_5 ] ;
F_20 ( V_36 ) ;
F_21 (claim, node, node_tmp,
head, hash_entry) {
if ( V_18 -> V_14 != V_14 )
continue;
F_11 ( V_18 ) ;
F_22 ( V_8 ) ;
}
F_23 ( V_36 ) ;
}
V_14 -> V_38 = V_39 ;
}
static void F_24 ( struct V_19 * V_20 , T_3 * V_40 ,
short V_30 , int V_41 )
{
struct V_42 * V_43 ;
struct V_44 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
T_3 * V_49 ;
struct V_50 V_51 ;
T_5 V_52 = 0 ;
V_46 = F_25 ( V_20 ) ;
if ( ! V_46 )
return;
memcpy ( & V_51 , & V_20 -> V_22 . V_53 ,
sizeof( V_51 ) ) ;
V_51 . type = V_41 ;
V_48 = V_46 -> V_48 ;
V_43 = F_26 ( V_54 , V_55 ,
V_52 ,
V_46 -> V_48 ,
V_52 ,
NULL ,
V_46 -> V_56 -> V_57 ,
( T_3 * ) & V_51 ) ;
if ( ! V_43 )
goto V_58;
V_44 = (struct V_44 * ) V_43 -> V_1 ;
V_49 = ( T_3 * ) V_44 + V_59 + sizeof( struct V_60 ) ;
switch ( V_41 ) {
case V_61 :
memcpy ( V_44 -> V_62 , V_40 , V_6 ) ;
F_27 ( V_63 , V_20 ,
L_1 , V_40 , V_30 ) ;
break;
case V_64 :
memcpy ( V_49 , V_40 , V_6 ) ;
F_27 ( V_63 , V_20 ,
L_2 , V_40 ,
V_30 ) ;
break;
case V_65 :
memcpy ( V_49 , V_40 , V_6 ) ;
F_27 ( V_63 , V_20 ,
L_3 ,
V_44 -> V_62 , V_30 ) ;
break;
case V_66 :
memcpy ( V_49 , V_40 , V_6 ) ;
memcpy ( V_44 -> V_67 , V_40 , V_6 ) ;
F_27 ( V_63 , V_20 ,
L_4 ,
V_44 -> V_62 , V_44 -> V_67 , V_30 ) ;
break;
}
if ( V_30 != - 1 )
V_43 = F_28 ( V_43 , V_30 ) ;
F_29 ( V_43 ) ;
V_43 -> V_68 = F_30 ( V_43 , V_48 ) ;
F_31 ( V_20 , V_69 ) ;
F_32 ( V_20 , V_70 ,
V_43 -> V_71 + V_59 ) ;
V_48 -> V_72 = V_73 ;
F_33 ( V_43 ) ;
V_58:
if ( V_46 )
F_34 ( V_46 ) ;
}
static struct V_11 *
F_35 ( struct V_19 * V_20 , T_3 * V_34 ,
short V_30 )
{
struct V_11 * V_74 ;
struct V_75 * V_76 ;
int V_77 ;
V_74 = F_18 ( V_20 , V_34 , V_30 ) ;
if ( V_74 )
return V_74 ;
F_27 ( V_63 , V_20 ,
L_5 ,
V_34 , V_30 ) ;
V_74 = F_36 ( sizeof( * V_74 ) , V_78 ) ;
if ( ! V_74 )
return NULL ;
V_74 -> V_30 = V_30 ;
V_74 -> V_79 = V_73 ;
V_74 -> V_38 = V_39 ;
V_74 -> V_20 = V_20 ;
F_37 ( & V_74 -> V_80 , 0 ) ;
memcpy ( V_74 -> V_34 , V_34 , V_6 ) ;
F_37 ( & V_74 -> V_15 , 2 ) ;
V_77 = F_38 ( V_20 -> V_22 . V_31 ,
F_3 ,
F_2 , V_74 ,
& V_74 -> V_12 ) ;
if ( F_39 ( V_77 != 0 ) ) {
F_10 ( V_74 ) ;
return NULL ;
}
V_76 = F_40 ( V_20 , V_34 ) ;
if ( V_76 ) {
F_41 ( V_20 , V_76 ,
L_6 ) ;
F_42 ( V_76 ) ;
}
return V_74 ;
}
static void
F_43 ( struct V_19 * V_20 ,
struct V_45 * V_46 ,
short V_30 )
{
struct V_11 * V_14 ;
V_14 = F_35 ( V_20 ,
V_46 -> V_56 -> V_57 ,
V_30 ) ;
if ( F_39 ( ! V_14 ) )
return;
V_14 -> V_79 = V_73 ;
F_6 ( V_14 ) ;
}
static void F_44 ( struct V_19 * V_20 ,
struct V_45 * V_46 ,
short V_30 )
{
struct V_7 * V_8 ;
struct V_24 * V_25 ;
struct V_21 * V_4 ;
struct V_13 * V_18 ;
struct V_11 * V_14 ;
int V_5 ;
F_27 ( V_63 , V_20 ,
L_7 ) ;
V_14 = F_18 ( V_20 ,
V_46 -> V_56 -> V_57 ,
V_30 ) ;
if ( ! V_14 )
return;
V_4 = V_20 -> V_22 . V_23 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_25 = & V_4 -> V_28 [ V_5 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
if ( V_18 -> V_14 != V_14 )
continue;
F_24 ( V_20 , V_18 -> V_29 , V_18 -> V_30 ,
V_61 ) ;
}
F_17 () ;
}
F_45 ( V_20 , V_14 ) ;
F_6 ( V_14 ) ;
}
static void F_46 ( struct V_11 * V_14 )
{
F_19 ( V_14 ) ;
F_27 ( V_63 , V_14 -> V_20 ,
L_8 , V_14 -> V_34 ) ;
F_24 ( V_14 -> V_20 , V_14 -> V_34 ,
V_14 -> V_30 , V_66 ) ;
if ( ! F_47 ( & V_14 -> V_80 ) ) {
F_48 ( & V_14 -> V_20 -> V_22 . V_81 ) ;
F_37 ( & V_14 -> V_80 , 1 ) ;
}
}
static void F_45 ( struct V_19 * V_20 ,
struct V_11 * V_14 )
{
T_3 V_40 [ V_6 ] ;
T_6 V_38 ;
memcpy ( V_40 , V_82 , 4 ) ;
V_38 = F_49 ( V_14 -> V_38 ) ;
memcpy ( & V_40 [ 4 ] , & V_38 , 2 ) ;
F_24 ( V_20 , V_40 , V_14 -> V_30 ,
V_65 ) ;
}
static void F_50 ( struct V_19 * V_20 ,
const T_3 * V_40 , const short V_30 ,
struct V_11 * V_14 )
{
struct V_13 * V_18 ;
struct V_13 V_83 ;
int V_77 ;
memcpy ( V_83 . V_29 , V_40 , V_6 ) ;
V_83 . V_30 = V_30 ;
V_18 = F_13 ( V_20 , & V_83 ) ;
if ( ! V_18 ) {
V_18 = F_36 ( sizeof( * V_18 ) , V_78 ) ;
if ( ! V_18 )
return;
memcpy ( V_18 -> V_29 , V_40 , V_6 ) ;
V_18 -> V_30 = V_30 ;
V_18 -> V_79 = V_73 ;
V_18 -> V_14 = V_14 ;
F_37 ( & V_18 -> V_15 , 2 ) ;
F_27 ( V_63 , V_20 ,
L_9 ,
V_40 , V_30 ) ;
V_77 = F_38 ( V_20 -> V_22 . V_23 ,
F_5 ,
F_1 , V_18 ,
& V_18 -> V_12 ) ;
if ( F_39 ( V_77 != 0 ) ) {
F_10 ( V_18 ) ;
return;
}
} else {
V_18 -> V_79 = V_73 ;
if ( V_18 -> V_14 == V_14 )
goto V_84;
F_27 ( V_63 , V_20 ,
L_10 ,
V_40 , V_30 ) ;
V_18 -> V_14 -> V_38 ^= F_51 ( 0 , V_18 -> V_29 , V_6 ) ;
F_6 ( V_18 -> V_14 ) ;
}
F_48 ( & V_14 -> V_15 ) ;
V_18 -> V_14 = V_14 ;
V_14 -> V_38 ^= F_51 ( 0 , V_18 -> V_29 , V_6 ) ;
V_14 -> V_79 = V_73 ;
V_84:
F_11 ( V_18 ) ;
}
static void F_52 ( struct V_19 * V_20 ,
const T_3 * V_40 , const short V_30 )
{
struct V_13 V_83 , * V_18 ;
memcpy ( V_83 . V_29 , V_40 , V_6 ) ;
V_83 . V_30 = V_30 ;
V_18 = F_13 ( V_20 , & V_83 ) ;
if ( ! V_18 )
return;
F_27 ( V_63 , V_20 , L_11 ,
V_40 , V_30 ) ;
F_53 ( V_20 -> V_22 . V_23 , F_5 ,
F_1 , V_18 ) ;
F_11 ( V_18 ) ;
V_18 -> V_14 -> V_38 ^= F_51 ( 0 , V_18 -> V_29 , V_6 ) ;
F_11 ( V_18 ) ;
}
static int F_54 ( struct V_19 * V_20 ,
T_3 * V_85 , T_3 * V_86 ,
short V_30 )
{
struct V_11 * V_14 ;
T_7 V_38 ;
if ( memcmp ( V_85 , V_82 , 4 ) != 0 )
return 0 ;
V_14 = F_35 ( V_20 , V_86 , V_30 ) ;
if ( F_39 ( ! V_14 ) )
return 1 ;
V_14 -> V_79 = V_73 ;
V_38 = F_55 ( * ( ( T_6 * ) ( & V_85 [ 4 ] ) ) ) ;
F_27 ( V_63 , V_20 ,
L_12 ,
V_30 , V_14 -> V_34 , V_38 ) ;
if ( V_14 -> V_38 != V_38 ) {
F_27 ( V_63 , V_14 -> V_20 ,
L_13 ,
V_14 -> V_34 , V_14 -> V_30 ,
V_14 -> V_38 , V_38 ) ;
F_46 ( V_14 ) ;
} else {
if ( F_47 ( & V_14 -> V_80 ) ) {
F_56 ( & V_14 -> V_20 -> V_22 . V_81 ) ;
F_37 ( & V_14 -> V_80 , 0 ) ;
}
}
F_6 ( V_14 ) ;
return 1 ;
}
static int F_57 ( struct V_19 * V_20 ,
struct V_45 * V_46 ,
T_3 * V_86 ,
struct V_44 * V_44 , short V_30 )
{
if ( ! F_58 ( V_86 , V_44 -> V_67 ) )
return 0 ;
if ( ! F_58 ( V_44 -> V_67 , V_46 -> V_56 -> V_57 ) )
return 1 ;
F_27 ( V_63 , V_20 ,
L_14 ,
V_30 , V_44 -> V_62 ) ;
F_44 ( V_20 , V_46 , V_30 ) ;
return 1 ;
}
static int F_59 ( struct V_19 * V_20 ,
struct V_45 * V_46 ,
T_3 * V_86 ,
T_3 * V_87 , short V_30 )
{
struct V_11 * V_14 ;
if ( V_46 && F_58 ( V_86 ,
V_46 -> V_56 -> V_57 ) )
F_24 ( V_20 , V_87 , V_30 ,
V_64 ) ;
V_14 = F_18 ( V_20 , V_86 , V_30 ) ;
if ( ! V_14 )
return 1 ;
F_27 ( V_63 , V_20 ,
L_15 ,
V_87 , V_30 , V_14 -> V_34 ) ;
F_52 ( V_20 , V_87 , V_30 ) ;
F_6 ( V_14 ) ;
return 1 ;
}
static int F_60 ( struct V_19 * V_20 ,
struct V_45 * V_46 ,
T_3 * V_86 , T_3 * V_87 ,
short V_30 )
{
struct V_11 * V_14 ;
V_14 = F_35 ( V_20 , V_86 , V_30 ) ;
if ( F_39 ( ! V_14 ) )
return 1 ;
F_50 ( V_20 , V_87 , V_30 , V_14 ) ;
if ( F_58 ( V_86 , V_46 -> V_56 -> V_57 ) )
F_24 ( V_20 , V_87 , V_30 ,
V_61 ) ;
F_6 ( V_14 ) ;
return 1 ;
}
static int F_61 ( struct V_19 * V_20 ,
struct V_45 * V_46 ,
T_3 * V_49 , T_3 * V_88 ,
struct V_44 * V_44 )
{
T_3 * V_86 ;
struct V_75 * V_76 ;
struct V_50 * V_89 , * V_90 ;
V_89 = (struct V_50 * ) V_88 ;
V_90 = & V_20 -> V_22 . V_53 ;
if ( memcmp ( V_89 -> V_91 , V_90 -> V_91 ,
sizeof( V_89 -> V_91 ) ) != 0 )
return 0 ;
switch ( V_89 -> type ) {
case V_61 :
V_86 = V_49 ;
break;
case V_66 :
case V_65 :
case V_64 :
V_86 = V_44 -> V_62 ;
break;
default:
return 0 ;
}
if ( F_58 ( V_86 , V_46 -> V_56 -> V_57 ) )
return 0 ;
if ( V_89 -> V_92 == V_90 -> V_92 )
return 2 ;
V_76 = F_40 ( V_20 , V_86 ) ;
if ( ! V_76 )
return 1 ;
if ( F_55 ( V_89 -> V_92 ) > F_55 ( V_90 -> V_92 ) ) {
F_27 ( V_63 , V_20 ,
L_16 ,
F_55 ( V_89 -> V_92 ) ) ;
V_90 -> V_92 = V_89 -> V_92 ;
}
F_42 ( V_76 ) ;
return 2 ;
}
static int F_62 ( struct V_19 * V_20 ,
struct V_45 * V_46 ,
struct V_42 * V_43 )
{
struct V_44 * V_44 ;
struct V_93 * V_94 ;
struct V_60 * V_60 ;
T_3 * V_49 , * V_88 ;
struct V_50 * V_89 ;
T_7 V_95 ;
int V_96 ;
short V_30 = - 1 ;
int V_97 ;
V_44 = (struct V_44 * ) F_63 ( V_43 ) ;
if ( F_55 ( V_44 -> V_98 ) == V_99 ) {
V_94 = (struct V_93 * ) V_44 ;
V_30 = F_55 ( V_94 -> V_100 ) & V_101 ;
V_95 = F_55 ( V_94 -> V_102 ) ;
V_96 = sizeof( * V_94 ) ;
} else {
V_95 = F_55 ( V_44 -> V_98 ) ;
V_96 = V_59 ;
}
if ( V_95 != V_55 )
return 0 ;
if ( F_39 ( ! F_64 ( V_43 , V_96 + F_65 ( V_43 -> V_103 ) ) ) )
return 0 ;
V_44 = (struct V_44 * ) F_63 ( V_43 ) ;
V_60 = (struct V_60 * ) ( ( T_3 * ) V_44 + V_96 ) ;
if ( V_60 -> V_104 != F_49 ( V_105 ) )
return 0 ;
if ( V_60 -> V_106 != F_49 ( V_107 ) )
return 0 ;
if ( V_60 -> V_108 != V_6 )
return 0 ;
if ( V_60 -> V_109 != 4 )
return 0 ;
V_49 = ( T_3 * ) V_60 + sizeof( struct V_60 ) ;
V_88 = V_49 + V_6 + 4 ;
V_89 = (struct V_50 * ) V_88 ;
V_97 = F_61 ( V_20 , V_46 , V_49 , V_88 ,
V_44 ) ;
if ( V_97 == 1 )
F_27 ( V_63 , V_20 ,
L_17 ,
V_44 -> V_62 , V_30 , V_49 , V_88 ) ;
if ( V_97 < 2 )
return V_97 ;
F_43 ( V_20 , V_46 , V_30 ) ;
switch ( V_89 -> type ) {
case V_61 :
if ( F_60 ( V_20 , V_46 , V_49 ,
V_44 -> V_62 , V_30 ) )
return 1 ;
break;
case V_64 :
if ( F_59 ( V_20 , V_46 ,
V_44 -> V_62 , V_49 , V_30 ) )
return 1 ;
break;
case V_65 :
if ( F_54 ( V_20 , V_49 , V_44 -> V_62 ,
V_30 ) )
return 1 ;
break;
case V_66 :
if ( F_57 ( V_20 , V_46 , V_49 , V_44 ,
V_30 ) )
return 1 ;
break;
}
F_27 ( V_63 , V_20 ,
L_18 ,
V_44 -> V_62 , V_30 , V_49 , V_88 ) ;
return 1 ;
}
static void F_66 ( struct V_19 * V_20 , int V_110 )
{
struct V_11 * V_14 ;
struct V_7 * V_8 , * V_35 ;
struct V_24 * V_25 ;
struct V_21 * V_4 ;
T_4 * V_36 ;
int V_5 ;
V_4 = V_20 -> V_22 . V_31 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_25 = & V_4 -> V_28 [ V_5 ] ;
V_36 = & V_4 -> V_37 [ V_5 ] ;
F_20 ( V_36 ) ;
F_21 (backbone_gw, node, node_tmp,
head, hash_entry) {
if ( V_110 )
goto V_111;
if ( ! F_67 ( V_14 -> V_79 ,
V_112 ) )
continue;
F_27 ( V_63 , V_14 -> V_20 ,
L_19 ,
V_14 -> V_34 ) ;
V_111:
if ( F_47 ( & V_14 -> V_80 ) )
F_56 ( & V_20 -> V_22 . V_81 ) ;
F_19 ( V_14 ) ;
F_22 ( V_8 ) ;
F_6 ( V_14 ) ;
}
F_23 ( V_36 ) ;
}
}
static void F_68 ( struct V_19 * V_20 ,
struct V_45 * V_46 ,
int V_110 )
{
struct V_13 * V_18 ;
struct V_7 * V_8 ;
struct V_24 * V_25 ;
struct V_21 * V_4 ;
int V_5 ;
V_4 = V_20 -> V_22 . V_23 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_25 = & V_4 -> V_28 [ V_5 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
if ( V_110 )
goto V_111;
if ( ! F_58 ( V_18 -> V_14 -> V_34 ,
V_46 -> V_56 -> V_57 ) )
continue;
if ( ! F_67 ( V_18 -> V_79 ,
V_113 ) )
continue;
F_27 ( V_63 , V_20 ,
L_20 ,
V_18 -> V_29 , V_18 -> V_30 ) ;
V_111:
F_59 ( V_20 , V_46 ,
V_18 -> V_14 -> V_34 ,
V_18 -> V_29 , V_18 -> V_30 ) ;
}
F_17 () ;
}
}
void F_69 ( struct V_19 * V_20 ,
struct V_45 * V_46 ,
struct V_45 * V_114 )
{
struct V_11 * V_14 ;
struct V_7 * V_8 ;
struct V_24 * V_25 ;
struct V_21 * V_4 ;
T_6 V_92 ;
int V_5 ;
V_92 = F_49 ( F_51 ( 0 , V_46 -> V_56 -> V_57 , V_6 ) ) ;
V_20 -> V_22 . V_53 . V_92 = V_92 ;
if ( ! V_114 ) {
F_68 ( V_20 , NULL , 1 ) ;
F_66 ( V_20 , 1 ) ;
return;
}
V_4 = V_20 -> V_22 . V_31 ;
if ( ! V_4 )
return;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_25 = & V_4 -> V_28 [ V_5 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( ! F_58 ( V_14 -> V_34 ,
V_114 -> V_56 -> V_57 ) )
continue;
memcpy ( V_14 -> V_34 ,
V_46 -> V_56 -> V_57 , V_6 ) ;
F_45 ( V_20 , V_14 ) ;
}
F_17 () ;
}
}
static void F_70 ( struct V_19 * V_20 )
{
F_71 ( & V_20 -> V_22 . V_115 , V_116 ) ;
F_72 ( V_117 , & V_20 -> V_22 . V_115 ,
F_73 ( V_118 ) ) ;
}
static void V_116 ( struct V_119 * V_115 )
{
struct V_120 * V_120 ;
struct V_19 * V_20 ;
struct V_121 * V_122 ;
struct V_7 * V_8 ;
struct V_24 * V_25 ;
struct V_11 * V_14 ;
struct V_21 * V_4 ;
struct V_45 * V_46 ;
int V_5 ;
V_120 = F_4 ( V_115 , struct V_120 , V_115 ) ;
V_122 = F_4 ( V_120 , struct V_121 , V_115 ) ;
V_20 = F_4 ( V_122 , struct V_19 , V_22 ) ;
V_46 = F_25 ( V_20 ) ;
if ( ! V_46 )
goto V_58;
F_68 ( V_20 , V_46 , 0 ) ;
F_66 ( V_20 , 0 ) ;
if ( ! F_47 ( & V_20 -> V_123 ) )
goto V_58;
V_4 = V_20 -> V_22 . V_31 ;
if ( ! V_4 )
goto V_58;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_25 = & V_4 -> V_28 [ V_5 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( ! F_58 ( V_14 -> V_34 ,
V_46 -> V_56 -> V_57 ) )
continue;
V_14 -> V_79 = V_73 ;
F_45 ( V_20 , V_14 ) ;
}
F_17 () ;
}
V_58:
if ( V_46 )
F_34 ( V_46 ) ;
F_70 ( V_20 ) ;
}
int F_74 ( struct V_19 * V_20 )
{
int V_5 ;
T_3 V_53 [ V_6 ] = { 0xff , 0x43 , 0x05 , 0x00 , 0x00 , 0x00 } ;
struct V_45 * V_46 ;
T_7 V_38 ;
unsigned long V_124 ;
F_75 ( & V_20 -> V_22 . V_125 ) ;
F_27 ( V_63 , V_20 , L_21 ) ;
memcpy ( & V_20 -> V_22 . V_53 . V_91 , V_53 , 3 ) ;
V_20 -> V_22 . V_53 . type = 0 ;
V_46 = F_25 ( V_20 ) ;
if ( V_46 ) {
V_38 = F_51 ( 0 , V_46 -> V_56 -> V_57 , V_6 ) ;
V_20 -> V_22 . V_53 . V_92 = F_49 ( V_38 ) ;
F_34 ( V_46 ) ;
} else {
V_20 -> V_22 . V_53 . V_92 = 0 ;
}
V_124 = V_73 - F_73 ( V_126 ) ;
for ( V_5 = 0 ; V_5 < V_127 ; V_5 ++ )
V_20 -> V_22 . V_128 [ V_5 ] . V_124 = V_124 ;
V_20 -> V_22 . V_129 = 0 ;
if ( V_20 -> V_22 . V_23 )
return 0 ;
V_20 -> V_22 . V_23 = F_76 ( 128 ) ;
V_20 -> V_22 . V_31 = F_76 ( 32 ) ;
if ( ! V_20 -> V_22 . V_23 || ! V_20 -> V_22 . V_31 )
return - V_130 ;
F_77 ( V_20 -> V_22 . V_23 ,
& V_131 ) ;
F_77 ( V_20 -> V_22 . V_31 ,
& V_132 ) ;
F_27 ( V_63 , V_20 , L_22 ) ;
F_70 ( V_20 ) ;
return 0 ;
}
int F_78 ( struct V_19 * V_20 ,
struct V_133 * V_134 ,
int V_135 )
{
int V_5 , V_136 , V_137 , V_97 = 0 ;
T_3 * V_138 ;
T_7 V_38 ;
struct V_139 * V_74 ;
V_136 = V_135 - sizeof( * V_134 ) ;
V_138 = ( T_3 * ) V_134 ;
V_138 += sizeof( * V_134 ) ;
V_38 = F_51 ( 0 , V_138 , V_136 ) ;
F_20 ( & V_20 -> V_22 . V_125 ) ;
for ( V_5 = 0 ; V_5 < V_127 ; V_5 ++ ) {
V_137 = ( V_20 -> V_22 . V_129 + V_5 ) ;
V_137 %= V_127 ;
V_74 = & V_20 -> V_22 . V_128 [ V_137 ] ;
if ( F_67 ( V_74 -> V_124 ,
V_126 ) )
break;
if ( V_74 -> V_38 != V_38 )
continue;
if ( F_58 ( V_74 -> V_34 , V_134 -> V_34 ) )
continue;
V_97 = 1 ;
goto V_58;
}
V_137 = ( V_20 -> V_22 . V_129 + V_127 - 1 ) ;
V_137 %= V_127 ;
V_74 = & V_20 -> V_22 . V_128 [ V_137 ] ;
V_74 -> V_38 = V_38 ;
V_74 -> V_124 = V_73 ;
memcpy ( V_74 -> V_34 , V_134 -> V_34 , V_6 ) ;
V_20 -> V_22 . V_129 = V_137 ;
V_58:
F_23 ( & V_20 -> V_22 . V_125 ) ;
return V_97 ;
}
int F_79 ( struct V_19 * V_20 , T_3 * V_34 )
{
struct V_21 * V_4 = V_20 -> V_22 . V_31 ;
struct V_24 * V_25 ;
struct V_7 * V_8 ;
struct V_11 * V_14 ;
int V_5 ;
if ( ! F_47 ( & V_20 -> V_123 ) )
return 0 ;
if ( ! V_4 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_25 = & V_4 -> V_28 [ V_5 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
if ( F_58 ( V_14 -> V_34 , V_34 ) ) {
F_17 () ;
return 1 ;
}
}
F_17 () ;
}
return 0 ;
}
int F_80 ( struct V_42 * V_43 ,
struct V_75 * V_76 , int V_140 )
{
struct V_44 * V_44 ;
struct V_93 * V_94 ;
struct V_11 * V_14 ;
short V_30 = - 1 ;
if ( ! F_47 ( & V_76 -> V_20 -> V_123 ) )
return 0 ;
if ( ! F_64 ( V_43 , V_140 + V_59 ) )
return 0 ;
V_44 = (struct V_44 * ) ( ( ( T_3 * ) V_43 -> V_1 ) + V_140 ) ;
if ( F_55 ( V_44 -> V_98 ) == V_99 ) {
if ( ! F_64 ( V_43 , V_140 + sizeof( struct V_93 ) ) )
return 0 ;
V_94 = (struct V_93 * ) ( V_43 -> V_1 + V_140 ) ;
V_30 = F_55 ( V_94 -> V_100 ) & V_101 ;
}
V_14 = F_18 ( V_76 -> V_20 ,
V_76 -> V_34 , V_30 ) ;
if ( ! V_14 )
return 0 ;
F_6 ( V_14 ) ;
return 1 ;
}
void F_81 ( struct V_19 * V_20 )
{
struct V_45 * V_46 ;
F_82 ( & V_20 -> V_22 . V_115 ) ;
V_46 = F_25 ( V_20 ) ;
if ( V_20 -> V_22 . V_23 ) {
F_68 ( V_20 , V_46 , 1 ) ;
F_83 ( V_20 -> V_22 . V_23 ) ;
V_20 -> V_22 . V_23 = NULL ;
}
if ( V_20 -> V_22 . V_31 ) {
F_66 ( V_20 , 1 ) ;
F_83 ( V_20 -> V_22 . V_31 ) ;
V_20 -> V_22 . V_31 = NULL ;
}
if ( V_46 )
F_34 ( V_46 ) ;
}
int F_84 ( struct V_19 * V_20 , struct V_42 * V_43 , short V_30 ,
bool V_141 )
{
struct V_44 * V_44 ;
struct V_13 V_83 , * V_18 = NULL ;
struct V_45 * V_46 ;
int V_97 ;
V_44 = (struct V_44 * ) F_63 ( V_43 ) ;
V_46 = F_25 ( V_20 ) ;
if ( ! V_46 )
goto V_142;
if ( ! F_47 ( & V_20 -> V_123 ) )
goto V_143;
if ( F_39 ( F_47 ( & V_20 -> V_22 . V_81 ) ) )
if ( F_85 ( V_44 -> V_67 ) && V_141 )
goto V_142;
memcpy ( V_83 . V_29 , V_44 -> V_62 , V_6 ) ;
V_83 . V_30 = V_30 ;
V_18 = F_13 ( V_20 , & V_83 ) ;
if ( ! V_18 ) {
F_60 ( V_20 , V_46 ,
V_46 -> V_56 -> V_57 ,
V_44 -> V_62 , V_30 ) ;
goto V_143;
}
if ( F_58 ( V_18 -> V_14 -> V_34 ,
V_46 -> V_56 -> V_57 ) ) {
V_18 -> V_79 = V_73 ;
goto V_143;
}
if ( F_85 ( V_44 -> V_67 ) && V_141 ) {
goto V_142;
} else {
F_60 ( V_20 , V_46 ,
V_46 -> V_56 -> V_57 ,
V_44 -> V_62 , V_30 ) ;
goto V_143;
}
V_143:
F_43 ( V_20 , V_46 , V_30 ) ;
V_97 = 0 ;
goto V_58;
V_142:
F_86 ( V_43 ) ;
V_97 = 1 ;
V_58:
if ( V_46 )
F_34 ( V_46 ) ;
if ( V_18 )
F_11 ( V_18 ) ;
return V_97 ;
}
int F_87 ( struct V_19 * V_20 , struct V_42 * V_43 , short V_30 )
{
struct V_44 * V_44 ;
struct V_13 V_83 , * V_18 = NULL ;
struct V_45 * V_46 ;
int V_97 = 0 ;
V_46 = F_25 ( V_20 ) ;
if ( ! V_46 )
goto V_58;
if ( ! F_47 ( & V_20 -> V_123 ) )
goto V_143;
F_29 ( V_43 ) ;
if ( F_62 ( V_20 , V_46 , V_43 ) )
goto V_142;
V_44 = (struct V_44 * ) F_63 ( V_43 ) ;
if ( F_39 ( F_47 ( & V_20 -> V_22 . V_81 ) ) )
if ( F_85 ( V_44 -> V_67 ) )
goto V_142;
memcpy ( V_83 . V_29 , V_44 -> V_62 , V_6 ) ;
V_83 . V_30 = V_30 ;
V_18 = F_13 ( V_20 , & V_83 ) ;
if ( ! V_18 )
goto V_143;
if ( F_58 ( V_18 -> V_14 -> V_34 ,
V_46 -> V_56 -> V_57 ) ) {
F_59 ( V_20 , V_46 ,
V_46 -> V_56 -> V_57 ,
V_44 -> V_62 , V_30 ) ;
goto V_143;
}
if ( F_85 ( V_44 -> V_67 ) ) {
goto V_142;
} else {
goto V_143;
}
V_143:
F_43 ( V_20 , V_46 , V_30 ) ;
V_97 = 0 ;
goto V_58;
V_142:
V_97 = 1 ;
V_58:
if ( V_46 )
F_34 ( V_46 ) ;
if ( V_18 )
F_11 ( V_18 ) ;
return V_97 ;
}
int F_88 ( struct V_144 * V_145 , void * V_146 )
{
struct V_47 * V_56 = (struct V_47 * ) V_145 -> V_147 ;
struct V_19 * V_20 = F_89 ( V_56 ) ;
struct V_21 * V_4 = V_20 -> V_22 . V_23 ;
struct V_13 * V_18 ;
struct V_45 * V_46 ;
struct V_7 * V_8 ;
struct V_24 * V_25 ;
T_1 V_5 ;
bool V_148 ;
int V_97 = 0 ;
T_3 * V_149 ;
V_46 = F_25 ( V_20 ) ;
if ( ! V_46 ) {
V_97 = F_90 ( V_145 ,
L_23 ,
V_56 -> V_150 ) ;
goto V_58;
}
if ( V_46 -> V_151 != V_152 ) {
V_97 = F_90 ( V_145 ,
L_24 ,
V_56 -> V_150 ) ;
goto V_58;
}
V_149 = V_46 -> V_56 -> V_57 ;
F_90 ( V_145 ,
L_25 ,
V_56 -> V_150 , V_149 ,
F_55 ( V_20 -> V_22 . V_53 . V_92 ) ) ;
F_90 ( V_145 , L_26 ,
L_27 , L_28 , L_29 , L_30 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_25 = & V_4 -> V_28 [ V_5 ] ;
F_14 () ;
F_15 (claim, node, head, hash_entry) {
V_148 = F_58 ( V_18 -> V_14 -> V_34 ,
V_149 ) ;
F_90 ( V_145 , L_31 ,
V_18 -> V_29 , V_18 -> V_30 ,
V_18 -> V_14 -> V_34 ,
( V_148 ? 'x' : ' ' ) ,
V_18 -> V_14 -> V_38 ) ;
}
F_17 () ;
}
V_58:
if ( V_46 )
F_34 ( V_46 ) ;
return V_97 ;
}
int F_91 ( struct V_144 * V_145 , void * V_146 )
{
struct V_47 * V_56 = (struct V_47 * ) V_145 -> V_147 ;
struct V_19 * V_20 = F_89 ( V_56 ) ;
struct V_21 * V_4 = V_20 -> V_22 . V_31 ;
struct V_11 * V_14 ;
struct V_45 * V_46 ;
struct V_7 * V_8 ;
struct V_24 * V_25 ;
int V_153 , V_154 ;
T_1 V_5 ;
bool V_148 ;
int V_97 = 0 ;
T_3 * V_149 ;
V_46 = F_25 ( V_20 ) ;
if ( ! V_46 ) {
V_97 = F_90 ( V_145 ,
L_23 ,
V_56 -> V_150 ) ;
goto V_58;
}
if ( V_46 -> V_151 != V_152 ) {
V_97 = F_90 ( V_145 ,
L_24 ,
V_56 -> V_150 ) ;
goto V_58;
}
V_149 = V_46 -> V_56 -> V_57 ;
F_90 ( V_145 ,
L_32 ,
V_56 -> V_150 , V_149 ,
F_55 ( V_20 -> V_22 . V_53 . V_92 ) ) ;
F_90 ( V_145 , L_33 ,
L_29 , L_28 , L_34 , L_30 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_25 = & V_4 -> V_28 [ V_5 ] ;
F_14 () ;
F_15 (backbone_gw, node, head, hash_entry) {
V_154 = F_92 ( V_73 -
V_14 -> V_79 ) ;
V_153 = V_154 / 1000 ;
V_154 = V_154 % 1000 ;
V_148 = F_58 ( V_14 -> V_34 ,
V_149 ) ;
if ( V_148 )
continue;
F_90 ( V_145 ,
L_35 ,
V_14 -> V_34 , V_14 -> V_30 ,
V_153 , V_154 , V_14 -> V_38 ) ;
}
F_17 () ;
}
V_58:
if ( V_46 )
F_34 ( V_46 ) ;
return V_97 ;
}
