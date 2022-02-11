static inline T_1 F_1 ( const void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
T_1 V_5 = 0 ;
V_5 = F_2 ( V_5 , & V_4 -> V_6 , sizeof( V_4 -> V_6 ) ) ;
V_5 = F_2 ( V_5 , & V_4 -> V_7 , sizeof( V_4 -> V_7 ) ) ;
V_5 += ( V_5 << 3 ) ;
V_5 ^= ( V_5 >> 11 ) ;
V_5 += ( V_5 << 15 ) ;
return V_5 % V_2 ;
}
static inline T_1 F_3 ( const void * V_1 ,
T_1 V_2 )
{
const struct V_3 * V_4 = (struct V_3 * ) V_1 ;
T_1 V_5 = 0 ;
V_5 = F_2 ( V_5 , & V_4 -> V_6 , sizeof( V_4 -> V_6 ) ) ;
V_5 = F_2 ( V_5 , & V_4 -> V_7 , sizeof( V_4 -> V_7 ) ) ;
V_5 += ( V_5 << 3 ) ;
V_5 ^= ( V_5 >> 11 ) ;
V_5 += ( V_5 << 15 ) ;
return V_5 % V_2 ;
}
static int F_4 ( const struct V_8 * V_9 ,
const void * V_10 )
{
const void * V_11 = F_5 ( V_9 , struct V_12 ,
V_13 ) ;
const struct V_12 * V_14 = V_11 , * V_15 = V_10 ;
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
const struct V_3 * V_17 = V_11 , * V_18 = V_10 ;
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
static void F_11 ( struct V_22 * V_21 )
{
struct V_3 * V_4 ;
V_4 = F_5 ( V_21 , struct V_3 , V_21 ) ;
F_8 ( V_4 -> V_19 ) ;
F_12 ( V_4 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
if ( F_9 ( & V_4 -> V_20 ) )
F_14 ( & V_4 -> V_21 , F_11 ) ;
}
static struct V_3
* F_15 ( struct V_23 * V_24 ,
struct V_3 * V_1 )
{
struct V_25 * V_5 = V_24 -> V_26 . V_27 ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
struct V_3 * V_30 = NULL ;
int V_31 ;
if ( ! V_5 )
return NULL ;
V_31 = F_1 ( V_1 , V_5 -> V_2 ) ;
V_29 = & V_5 -> V_32 [ V_31 ] ;
F_16 () ;
F_17 (claim, head, hash_entry) {
if ( ! F_7 ( & V_4 -> V_13 , V_1 ) )
continue;
if ( ! F_18 ( & V_4 -> V_20 ) )
continue;
V_30 = V_4 ;
break;
}
F_19 () ;
return V_30 ;
}
static struct V_12 *
F_20 ( struct V_23 * V_24 ,
T_2 * V_6 , short V_7 )
{
struct V_25 * V_5 = V_24 -> V_26 . V_33 ;
struct V_28 * V_29 ;
struct V_12 V_34 , * V_19 ;
struct V_12 * V_35 = NULL ;
int V_31 ;
if ( ! V_5 )
return NULL ;
memcpy ( V_34 . V_16 , V_6 , V_36 ) ;
V_34 . V_7 = V_7 ;
V_31 = F_3 ( & V_34 , V_5 -> V_2 ) ;
V_29 = & V_5 -> V_32 [ V_31 ] ;
F_16 () ;
F_17 (backbone_gw, head, hash_entry) {
if ( ! F_4 ( & V_19 -> V_13 ,
& V_34 ) )
continue;
if ( ! F_18 ( & V_19 -> V_20 ) )
continue;
V_35 = V_19 ;
break;
}
F_19 () ;
return V_35 ;
}
static void
F_21 ( struct V_12 * V_19 )
{
struct V_25 * V_5 ;
struct V_8 * V_37 ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
int V_38 ;
T_3 * V_39 ;
V_5 = V_19 -> V_24 -> V_26 . V_27 ;
if ( ! V_5 )
return;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
V_39 = & V_5 -> V_40 [ V_38 ] ;
F_22 ( V_39 ) ;
F_23 (claim, node_tmp,
head, hash_entry) {
if ( V_4 -> V_19 != V_19 )
continue;
F_13 ( V_4 ) ;
F_24 ( & V_4 -> V_13 ) ;
}
F_25 ( V_39 ) ;
}
V_19 -> V_41 = V_42 ;
}
static void F_26 ( struct V_23 * V_24 , T_2 * V_43 ,
short V_7 , int V_44 )
{
struct V_45 * V_46 ;
struct V_47 * V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
T_2 * V_52 ;
struct V_53 V_54 ;
T_4 V_55 = 0 ;
V_49 = F_27 ( V_24 ) ;
if ( ! V_49 )
return;
memcpy ( & V_54 , & V_24 -> V_26 . V_56 ,
sizeof( V_54 ) ) ;
V_54 . type = V_44 ;
V_51 = V_49 -> V_51 ;
V_46 = F_28 ( V_57 , V_58 ,
V_55 ,
V_49 -> V_51 ,
V_55 ,
NULL ,
V_49 -> V_59 -> V_60 ,
( T_2 * ) & V_54 ) ;
if ( ! V_46 )
goto V_61;
V_47 = (struct V_47 * ) V_46 -> V_1 ;
V_52 = ( T_2 * ) V_47 + V_62 + sizeof( struct V_63 ) ;
switch ( V_44 ) {
case V_64 :
memcpy ( V_47 -> V_65 , V_43 , V_36 ) ;
F_29 ( V_66 , V_24 ,
L_1 , V_43 , V_7 ) ;
break;
case V_67 :
memcpy ( V_52 , V_43 , V_36 ) ;
F_29 ( V_66 , V_24 ,
L_2 , V_43 ,
V_7 ) ;
break;
case V_68 :
memcpy ( V_52 , V_43 , V_36 ) ;
F_29 ( V_66 , V_24 ,
L_3 ,
V_47 -> V_65 , V_7 ) ;
break;
case V_69 :
memcpy ( V_52 , V_43 , V_36 ) ;
memcpy ( V_47 -> V_70 , V_43 , V_36 ) ;
F_29 ( V_66 , V_24 ,
L_4 ,
V_47 -> V_65 , V_47 -> V_70 , V_7 ) ;
break;
}
if ( V_7 != - 1 )
V_46 = F_30 ( V_46 , F_31 ( V_71 ) , V_7 ) ;
F_32 ( V_46 ) ;
V_46 -> V_72 = F_33 ( V_46 , V_51 ) ;
F_34 ( V_24 , V_73 ) ;
F_35 ( V_24 , V_74 ,
V_46 -> V_75 + V_62 ) ;
V_51 -> V_76 = V_77 ;
F_36 ( V_46 ) ;
V_61:
if ( V_49 )
F_37 ( V_49 ) ;
}
static struct V_12 *
F_38 ( struct V_23 * V_24 , T_2 * V_16 ,
short V_7 , bool V_78 )
{
struct V_12 * V_79 ;
struct V_80 * V_81 ;
int V_82 ;
V_79 = F_20 ( V_24 , V_16 , V_7 ) ;
if ( V_79 )
return V_79 ;
F_29 ( V_66 , V_24 ,
L_5 ,
V_16 , V_7 ) ;
V_79 = F_39 ( sizeof( * V_79 ) , V_83 ) ;
if ( ! V_79 )
return NULL ;
V_79 -> V_7 = V_7 ;
V_79 -> V_84 = V_77 ;
V_79 -> V_41 = V_42 ;
V_79 -> V_24 = V_24 ;
F_40 ( & V_79 -> V_85 , 0 ) ;
F_40 ( & V_79 -> V_86 , 0 ) ;
memcpy ( V_79 -> V_16 , V_16 , V_36 ) ;
F_40 ( & V_79 -> V_20 , 2 ) ;
V_82 = F_41 ( V_24 -> V_26 . V_33 ,
F_4 ,
F_3 , V_79 ,
& V_79 -> V_13 ) ;
if ( F_42 ( V_82 != 0 ) ) {
F_12 ( V_79 ) ;
return NULL ;
}
V_81 = F_43 ( V_24 , V_16 ) ;
if ( V_81 ) {
F_44 ( V_24 , V_81 ,
L_6 ) ;
F_45 ( V_81 ) ;
}
if ( V_78 ) {
F_46 ( V_24 , V_79 ) ;
F_47 ( & V_79 -> V_85 ) ;
F_40 ( & V_79 -> V_86 , V_87 ) ;
F_47 ( & V_24 -> V_26 . V_88 ) ;
}
return V_79 ;
}
static void
F_48 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
short V_7 )
{
struct V_12 * V_19 ;
V_19 = F_38 ( V_24 ,
V_49 -> V_59 -> V_60 ,
V_7 , true ) ;
if ( F_42 ( ! V_19 ) )
return;
V_19 -> V_84 = V_77 ;
F_8 ( V_19 ) ;
}
static void F_49 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
short V_7 )
{
struct V_28 * V_29 ;
struct V_25 * V_5 ;
struct V_3 * V_4 ;
struct V_12 * V_19 ;
int V_38 ;
F_29 ( V_66 , V_24 ,
L_7 ) ;
V_19 = F_20 ( V_24 ,
V_49 -> V_59 -> V_60 ,
V_7 ) ;
if ( ! V_19 )
return;
V_5 = V_24 -> V_26 . V_27 ;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
F_16 () ;
F_17 (claim, head, hash_entry) {
if ( V_4 -> V_19 != V_19 )
continue;
F_26 ( V_24 , V_4 -> V_6 , V_4 -> V_7 ,
V_64 ) ;
}
F_19 () ;
}
F_46 ( V_24 , V_19 ) ;
F_8 ( V_19 ) ;
}
static void F_50 ( struct V_12 * V_19 )
{
F_21 ( V_19 ) ;
F_29 ( V_66 , V_19 -> V_24 ,
L_8 , V_19 -> V_16 ) ;
F_26 ( V_19 -> V_24 , V_19 -> V_16 ,
V_19 -> V_7 , V_69 ) ;
if ( ! F_51 ( & V_19 -> V_85 ) ) {
F_47 ( & V_19 -> V_24 -> V_26 . V_88 ) ;
F_40 ( & V_19 -> V_85 , 1 ) ;
}
}
static void F_46 ( struct V_23 * V_24 ,
struct V_12 * V_19 )
{
T_2 V_43 [ V_36 ] ;
T_5 V_41 ;
memcpy ( V_43 , V_89 , 4 ) ;
V_41 = F_31 ( V_19 -> V_41 ) ;
memcpy ( & V_43 [ 4 ] , & V_41 , 2 ) ;
F_26 ( V_24 , V_43 , V_19 -> V_7 ,
V_68 ) ;
}
static void F_52 ( struct V_23 * V_24 ,
const T_2 * V_43 , const short V_7 ,
struct V_12 * V_19 )
{
struct V_3 * V_4 ;
struct V_3 V_90 ;
int V_82 ;
memcpy ( V_90 . V_6 , V_43 , V_36 ) ;
V_90 . V_7 = V_7 ;
V_4 = F_15 ( V_24 , & V_90 ) ;
if ( ! V_4 ) {
V_4 = F_39 ( sizeof( * V_4 ) , V_83 ) ;
if ( ! V_4 )
return;
memcpy ( V_4 -> V_6 , V_43 , V_36 ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_84 = V_77 ;
V_4 -> V_19 = V_19 ;
F_40 ( & V_4 -> V_20 , 2 ) ;
F_29 ( V_66 , V_24 ,
L_9 ,
V_43 , V_7 ) ;
V_82 = F_41 ( V_24 -> V_26 . V_27 ,
F_7 ,
F_1 , V_4 ,
& V_4 -> V_13 ) ;
if ( F_42 ( V_82 != 0 ) ) {
F_12 ( V_4 ) ;
return;
}
} else {
V_4 -> V_84 = V_77 ;
if ( V_4 -> V_19 == V_19 )
goto V_91;
F_29 ( V_66 , V_24 ,
L_10 ,
V_43 , V_7 ) ;
V_4 -> V_19 -> V_41 ^= F_53 ( 0 , V_4 -> V_6 , V_36 ) ;
F_8 ( V_4 -> V_19 ) ;
}
F_47 ( & V_19 -> V_20 ) ;
V_4 -> V_19 = V_19 ;
V_19 -> V_41 ^= F_53 ( 0 , V_4 -> V_6 , V_36 ) ;
V_19 -> V_84 = V_77 ;
V_91:
F_13 ( V_4 ) ;
}
static void F_54 ( struct V_23 * V_24 ,
const T_2 * V_43 , const short V_7 )
{
struct V_3 V_90 , * V_4 ;
memcpy ( V_90 . V_6 , V_43 , V_36 ) ;
V_90 . V_7 = V_7 ;
V_4 = F_15 ( V_24 , & V_90 ) ;
if ( ! V_4 )
return;
F_29 ( V_66 , V_24 , L_11 ,
V_43 , V_7 ) ;
F_55 ( V_24 -> V_26 . V_27 , F_7 ,
F_1 , V_4 ) ;
F_13 ( V_4 ) ;
V_4 -> V_19 -> V_41 ^= F_53 ( 0 , V_4 -> V_6 , V_36 ) ;
F_13 ( V_4 ) ;
}
static int F_56 ( struct V_23 * V_24 ,
T_2 * V_92 , T_2 * V_93 ,
short V_7 )
{
struct V_12 * V_19 ;
T_6 V_41 ;
if ( memcmp ( V_92 , V_89 , 4 ) != 0 )
return 0 ;
V_19 = F_38 ( V_24 , V_93 , V_7 ,
false ) ;
if ( F_42 ( ! V_19 ) )
return 1 ;
V_19 -> V_84 = V_77 ;
V_41 = F_57 ( * ( ( T_5 * ) ( & V_92 [ 4 ] ) ) ) ;
F_29 ( V_66 , V_24 ,
L_12 ,
V_7 , V_19 -> V_16 , V_41 ) ;
if ( V_19 -> V_41 != V_41 ) {
F_29 ( V_66 , V_19 -> V_24 ,
L_13 ,
V_19 -> V_16 , V_19 -> V_7 ,
V_19 -> V_41 , V_41 ) ;
F_50 ( V_19 ) ;
} else {
if ( F_51 ( & V_19 -> V_85 ) ) {
F_58 ( & V_19 -> V_24 -> V_26 . V_88 ) ;
F_40 ( & V_19 -> V_85 , 0 ) ;
}
}
F_8 ( V_19 ) ;
return 1 ;
}
static int F_59 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
T_2 * V_93 ,
struct V_47 * V_47 , short V_7 )
{
if ( ! F_6 ( V_93 , V_47 -> V_70 ) )
return 0 ;
if ( ! F_6 ( V_47 -> V_70 , V_49 -> V_59 -> V_60 ) )
return 1 ;
F_29 ( V_66 , V_24 ,
L_14 ,
V_7 , V_47 -> V_65 ) ;
F_49 ( V_24 , V_49 , V_7 ) ;
return 1 ;
}
static int F_60 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
T_2 * V_93 ,
T_2 * V_94 , short V_7 )
{
struct V_12 * V_19 ;
if ( V_49 && F_6 ( V_93 ,
V_49 -> V_59 -> V_60 ) )
F_26 ( V_24 , V_94 , V_7 ,
V_67 ) ;
V_19 = F_20 ( V_24 , V_93 , V_7 ) ;
if ( ! V_19 )
return 1 ;
F_29 ( V_66 , V_24 ,
L_15 ,
V_94 , V_7 , V_19 -> V_16 ) ;
F_54 ( V_24 , V_94 , V_7 ) ;
F_8 ( V_19 ) ;
return 1 ;
}
static int F_61 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
T_2 * V_93 , T_2 * V_94 ,
short V_7 )
{
struct V_12 * V_19 ;
V_19 = F_38 ( V_24 , V_93 , V_7 ,
false ) ;
if ( F_42 ( ! V_19 ) )
return 1 ;
F_52 ( V_24 , V_94 , V_7 , V_19 ) ;
if ( F_6 ( V_93 , V_49 -> V_59 -> V_60 ) )
F_26 ( V_24 , V_94 , V_7 ,
V_64 ) ;
F_8 ( V_19 ) ;
return 1 ;
}
static int F_62 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
T_2 * V_52 , T_2 * V_95 ,
struct V_47 * V_47 )
{
T_2 * V_93 ;
struct V_80 * V_81 ;
struct V_53 * V_96 , * V_97 ;
V_96 = (struct V_53 * ) V_95 ;
V_97 = & V_24 -> V_26 . V_56 ;
if ( memcmp ( V_96 -> V_98 , V_97 -> V_98 ,
sizeof( V_96 -> V_98 ) ) != 0 )
return 0 ;
switch ( V_96 -> type ) {
case V_64 :
V_93 = V_52 ;
break;
case V_69 :
case V_68 :
case V_67 :
V_93 = V_47 -> V_65 ;
break;
default:
return 0 ;
}
if ( F_6 ( V_93 , V_49 -> V_59 -> V_60 ) )
return 0 ;
if ( V_96 -> V_99 == V_97 -> V_99 )
return 2 ;
V_81 = F_43 ( V_24 , V_93 ) ;
if ( ! V_81 )
return 1 ;
if ( F_57 ( V_96 -> V_99 ) > F_57 ( V_97 -> V_99 ) ) {
F_29 ( V_66 , V_24 ,
L_16 ,
F_57 ( V_96 -> V_99 ) ) ;
V_97 -> V_99 = V_96 -> V_99 ;
}
F_45 ( V_81 ) ;
return 2 ;
}
static int F_63 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
struct V_45 * V_46 )
{
struct V_47 * V_47 ;
struct V_100 * V_101 ;
struct V_63 * V_63 ;
T_2 * V_52 , * V_95 ;
struct V_53 * V_96 ;
T_6 V_102 ;
int V_103 ;
short V_7 = - 1 ;
int V_104 ;
V_47 = (struct V_47 * ) F_64 ( V_46 ) ;
if ( F_57 ( V_47 -> V_105 ) == V_71 ) {
V_101 = (struct V_100 * ) V_47 ;
V_7 = F_57 ( V_101 -> V_106 ) & V_107 ;
V_102 = F_57 ( V_101 -> V_108 ) ;
V_103 = sizeof( * V_101 ) ;
} else {
V_102 = F_57 ( V_47 -> V_105 ) ;
V_103 = V_62 ;
}
if ( V_102 != V_58 )
return 0 ;
if ( F_42 ( ! F_65 ( V_46 , V_103 + F_66 ( V_46 -> V_109 ) ) ) )
return 0 ;
V_47 = (struct V_47 * ) F_64 ( V_46 ) ;
V_63 = (struct V_63 * ) ( ( T_2 * ) V_47 + V_103 ) ;
if ( V_63 -> V_110 != F_31 ( V_111 ) )
return 0 ;
if ( V_63 -> V_112 != F_31 ( V_113 ) )
return 0 ;
if ( V_63 -> V_114 != V_36 )
return 0 ;
if ( V_63 -> V_115 != 4 )
return 0 ;
V_52 = ( T_2 * ) V_63 + sizeof( struct V_63 ) ;
V_95 = V_52 + V_36 + 4 ;
V_96 = (struct V_53 * ) V_95 ;
V_104 = F_62 ( V_24 , V_49 , V_52 , V_95 ,
V_47 ) ;
if ( V_104 == 1 )
F_29 ( V_66 , V_24 ,
L_17 ,
V_47 -> V_65 , V_7 , V_52 , V_95 ) ;
if ( V_104 < 2 )
return V_104 ;
F_48 ( V_24 , V_49 , V_7 ) ;
switch ( V_96 -> type ) {
case V_64 :
if ( F_61 ( V_24 , V_49 , V_52 ,
V_47 -> V_65 , V_7 ) )
return 1 ;
break;
case V_67 :
if ( F_60 ( V_24 , V_49 ,
V_47 -> V_65 , V_52 , V_7 ) )
return 1 ;
break;
case V_68 :
if ( F_56 ( V_24 , V_52 , V_47 -> V_65 ,
V_7 ) )
return 1 ;
break;
case V_69 :
if ( F_59 ( V_24 , V_49 , V_52 , V_47 ,
V_7 ) )
return 1 ;
break;
}
F_29 ( V_66 , V_24 ,
L_18 ,
V_47 -> V_65 , V_7 , V_52 , V_95 ) ;
return 1 ;
}
static void F_67 ( struct V_23 * V_24 , int V_116 )
{
struct V_12 * V_19 ;
struct V_8 * V_37 ;
struct V_28 * V_29 ;
struct V_25 * V_5 ;
T_3 * V_39 ;
int V_38 ;
V_5 = V_24 -> V_26 . V_33 ;
if ( ! V_5 )
return;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
V_39 = & V_5 -> V_40 [ V_38 ] ;
F_22 ( V_39 ) ;
F_23 (backbone_gw, node_tmp,
head, hash_entry) {
if ( V_116 )
goto V_117;
if ( ! F_68 ( V_19 -> V_84 ,
V_118 ) )
continue;
F_29 ( V_66 , V_19 -> V_24 ,
L_19 ,
V_19 -> V_16 ) ;
V_117:
if ( F_51 ( & V_19 -> V_85 ) )
F_58 ( & V_24 -> V_26 . V_88 ) ;
F_21 ( V_19 ) ;
F_24 ( & V_19 -> V_13 ) ;
F_8 ( V_19 ) ;
}
F_25 ( V_39 ) ;
}
}
static void F_69 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
int V_116 )
{
struct V_3 * V_4 ;
struct V_28 * V_29 ;
struct V_25 * V_5 ;
int V_38 ;
V_5 = V_24 -> V_26 . V_27 ;
if ( ! V_5 )
return;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
F_16 () ;
F_17 (claim, head, hash_entry) {
if ( V_116 )
goto V_117;
if ( ! F_6 ( V_4 -> V_19 -> V_16 ,
V_49 -> V_59 -> V_60 ) )
continue;
if ( ! F_68 ( V_4 -> V_84 ,
V_119 ) )
continue;
F_29 ( V_66 , V_24 ,
L_20 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
V_117:
F_60 ( V_24 , V_49 ,
V_4 -> V_19 -> V_16 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
}
F_19 () ;
}
}
void F_70 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
struct V_48 * V_120 )
{
struct V_12 * V_19 ;
struct V_28 * V_29 ;
struct V_25 * V_5 ;
T_5 V_99 ;
int V_38 ;
V_99 = F_31 ( F_53 ( 0 , V_49 -> V_59 -> V_60 , V_36 ) ) ;
V_24 -> V_26 . V_56 . V_99 = V_99 ;
if ( ! F_51 ( & V_24 -> V_121 ) )
V_120 = NULL ;
if ( ! V_120 ) {
F_69 ( V_24 , NULL , 1 ) ;
F_67 ( V_24 , 1 ) ;
return;
}
V_5 = V_24 -> V_26 . V_33 ;
if ( ! V_5 )
return;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
F_16 () ;
F_17 (backbone_gw, head, hash_entry) {
if ( ! F_6 ( V_19 -> V_16 ,
V_120 -> V_59 -> V_60 ) )
continue;
memcpy ( V_19 -> V_16 ,
V_49 -> V_59 -> V_60 , V_36 ) ;
F_46 ( V_24 , V_19 ) ;
}
F_19 () ;
}
}
static void F_71 ( struct V_122 * V_123 )
{
struct V_124 * V_124 ;
struct V_23 * V_24 ;
struct V_125 * V_126 ;
struct V_28 * V_29 ;
struct V_12 * V_19 ;
struct V_25 * V_5 ;
struct V_48 * V_49 ;
int V_38 ;
V_124 = F_5 ( V_123 , struct V_124 , V_123 ) ;
V_126 = F_5 ( V_124 , struct V_125 , V_123 ) ;
V_24 = F_5 ( V_126 , struct V_23 , V_26 ) ;
V_49 = F_27 ( V_24 ) ;
if ( ! V_49 )
goto V_61;
F_69 ( V_24 , V_49 , 0 ) ;
F_67 ( V_24 , 0 ) ;
if ( ! F_51 ( & V_24 -> V_121 ) )
goto V_61;
V_5 = V_24 -> V_26 . V_33 ;
if ( ! V_5 )
goto V_61;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
F_16 () ;
F_17 (backbone_gw, head, hash_entry) {
if ( ! F_6 ( V_19 -> V_16 ,
V_49 -> V_59 -> V_60 ) )
continue;
V_19 -> V_84 = V_77 ;
F_46 ( V_24 , V_19 ) ;
if ( F_51 ( & V_19 -> V_85 ) == 0 )
continue;
if ( ! F_9 ( & V_19 -> V_86 ) )
continue;
F_58 ( & V_19 -> V_24 -> V_26 . V_88 ) ;
F_40 ( & V_19 -> V_85 , 0 ) ;
}
F_19 () ;
}
V_61:
if ( V_49 )
F_37 ( V_49 ) ;
F_72 ( V_127 , & V_24 -> V_26 . V_123 ,
F_73 ( V_128 ) ) ;
}
int F_74 ( struct V_23 * V_24 )
{
int V_38 ;
T_2 V_56 [ V_36 ] = { 0xff , 0x43 , 0x05 , 0x00 , 0x00 , 0x00 } ;
struct V_48 * V_49 ;
T_6 V_41 ;
unsigned long V_129 ;
F_75 ( & V_24 -> V_26 . V_130 ) ;
F_29 ( V_66 , V_24 , L_21 ) ;
memcpy ( & V_24 -> V_26 . V_56 . V_98 , V_56 , 3 ) ;
V_24 -> V_26 . V_56 . type = 0 ;
V_49 = F_27 ( V_24 ) ;
if ( V_49 ) {
V_41 = F_53 ( 0 , V_49 -> V_59 -> V_60 , V_36 ) ;
V_24 -> V_26 . V_56 . V_99 = F_31 ( V_41 ) ;
F_37 ( V_49 ) ;
} else {
V_24 -> V_26 . V_56 . V_99 = 0 ;
}
V_129 = V_77 - F_73 ( V_131 ) ;
for ( V_38 = 0 ; V_38 < V_132 ; V_38 ++ )
V_24 -> V_26 . V_133 [ V_38 ] . V_129 = V_129 ;
V_24 -> V_26 . V_134 = 0 ;
if ( V_24 -> V_26 . V_27 )
return 0 ;
V_24 -> V_26 . V_27 = F_76 ( 128 ) ;
V_24 -> V_26 . V_33 = F_76 ( 32 ) ;
if ( ! V_24 -> V_26 . V_27 || ! V_24 -> V_26 . V_33 )
return - V_135 ;
F_77 ( V_24 -> V_26 . V_27 ,
& V_136 ) ;
F_77 ( V_24 -> V_26 . V_33 ,
& V_137 ) ;
F_29 ( V_66 , V_24 , L_22 ) ;
F_78 ( & V_24 -> V_26 . V_123 , F_71 ) ;
F_72 ( V_127 , & V_24 -> V_26 . V_123 ,
F_73 ( V_128 ) ) ;
return 0 ;
}
int F_79 ( struct V_23 * V_24 ,
struct V_45 * V_46 )
{
int V_38 , V_138 , V_104 = 0 ;
T_4 V_41 ;
struct V_139 * V_140 ;
struct V_141 * V_79 ;
V_140 = (struct V_139 * ) V_46 -> V_1 ;
V_41 = F_80 ( V_46 , ( V_142 * ) ( V_140 + 1 ) ) ;
F_22 ( & V_24 -> V_26 . V_130 ) ;
for ( V_38 = 0 ; V_38 < V_132 ; V_38 ++ ) {
V_138 = ( V_24 -> V_26 . V_134 + V_38 ) ;
V_138 %= V_132 ;
V_79 = & V_24 -> V_26 . V_133 [ V_138 ] ;
if ( F_68 ( V_79 -> V_129 ,
V_131 ) )
break;
if ( V_79 -> V_41 != V_41 )
continue;
if ( F_6 ( V_79 -> V_16 , V_140 -> V_16 ) )
continue;
V_104 = 1 ;
goto V_61;
}
V_138 = ( V_24 -> V_26 . V_134 + V_132 - 1 ) ;
V_138 %= V_132 ;
V_79 = & V_24 -> V_26 . V_133 [ V_138 ] ;
V_79 -> V_41 = V_41 ;
V_79 -> V_129 = V_77 ;
memcpy ( V_79 -> V_16 , V_140 -> V_16 , V_36 ) ;
V_24 -> V_26 . V_134 = V_138 ;
V_61:
F_25 ( & V_24 -> V_26 . V_130 ) ;
return V_104 ;
}
int F_81 ( struct V_23 * V_24 , T_2 * V_16 )
{
struct V_25 * V_5 = V_24 -> V_26 . V_33 ;
struct V_28 * V_29 ;
struct V_12 * V_19 ;
int V_38 ;
if ( ! F_51 ( & V_24 -> V_121 ) )
return 0 ;
if ( ! V_5 )
return 0 ;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
F_16 () ;
F_17 (backbone_gw, head, hash_entry) {
if ( F_6 ( V_19 -> V_16 , V_16 ) ) {
F_19 () ;
return 1 ;
}
}
F_19 () ;
}
return 0 ;
}
int F_82 ( struct V_45 * V_46 ,
struct V_80 * V_81 , int V_143 )
{
struct V_47 * V_47 ;
struct V_100 * V_101 ;
struct V_12 * V_19 ;
short V_7 = - 1 ;
if ( ! F_51 ( & V_81 -> V_24 -> V_121 ) )
return 0 ;
if ( ! F_65 ( V_46 , V_143 + V_62 ) )
return 0 ;
V_47 = (struct V_47 * ) ( ( ( T_2 * ) V_46 -> V_1 ) + V_143 ) ;
if ( F_57 ( V_47 -> V_105 ) == V_71 ) {
if ( ! F_65 ( V_46 , V_143 + sizeof( struct V_100 ) ) )
return 0 ;
V_101 = (struct V_100 * ) ( V_46 -> V_1 + V_143 ) ;
V_7 = F_57 ( V_101 -> V_106 ) & V_107 ;
}
V_19 = F_20 ( V_81 -> V_24 ,
V_81 -> V_16 , V_7 ) ;
if ( ! V_19 )
return 0 ;
F_8 ( V_19 ) ;
return 1 ;
}
void F_83 ( struct V_23 * V_24 )
{
struct V_48 * V_49 ;
F_84 ( & V_24 -> V_26 . V_123 ) ;
V_49 = F_27 ( V_24 ) ;
if ( V_24 -> V_26 . V_27 ) {
F_69 ( V_24 , V_49 , 1 ) ;
F_85 ( V_24 -> V_26 . V_27 ) ;
V_24 -> V_26 . V_27 = NULL ;
}
if ( V_24 -> V_26 . V_33 ) {
F_67 ( V_24 , 1 ) ;
F_85 ( V_24 -> V_26 . V_33 ) ;
V_24 -> V_26 . V_33 = NULL ;
}
if ( V_49 )
F_37 ( V_49 ) ;
}
int F_86 ( struct V_23 * V_24 , struct V_45 * V_46 , short V_7 ,
bool V_144 )
{
struct V_47 * V_47 ;
struct V_3 V_90 , * V_4 = NULL ;
struct V_48 * V_49 ;
int V_104 ;
V_47 = (struct V_47 * ) F_64 ( V_46 ) ;
V_49 = F_27 ( V_24 ) ;
if ( ! V_49 )
goto V_145;
if ( ! F_51 ( & V_24 -> V_121 ) )
goto V_146;
if ( F_42 ( F_51 ( & V_24 -> V_26 . V_88 ) ) )
if ( F_87 ( V_47 -> V_70 ) && V_144 )
goto V_145;
memcpy ( V_90 . V_6 , V_47 -> V_65 , V_36 ) ;
V_90 . V_7 = V_7 ;
V_4 = F_15 ( V_24 , & V_90 ) ;
if ( ! V_4 ) {
F_61 ( V_24 , V_49 ,
V_49 -> V_59 -> V_60 ,
V_47 -> V_65 , V_7 ) ;
goto V_146;
}
if ( F_6 ( V_4 -> V_19 -> V_16 ,
V_49 -> V_59 -> V_60 ) ) {
V_4 -> V_84 = V_77 ;
goto V_146;
}
if ( F_87 ( V_47 -> V_70 ) && V_144 ) {
goto V_145;
} else {
F_61 ( V_24 , V_49 ,
V_49 -> V_59 -> V_60 ,
V_47 -> V_65 , V_7 ) ;
goto V_146;
}
V_146:
F_48 ( V_24 , V_49 , V_7 ) ;
V_104 = 0 ;
goto V_61;
V_145:
F_88 ( V_46 ) ;
V_104 = 1 ;
V_61:
if ( V_49 )
F_37 ( V_49 ) ;
if ( V_4 )
F_13 ( V_4 ) ;
return V_104 ;
}
int F_89 ( struct V_23 * V_24 , struct V_45 * V_46 , short V_7 )
{
struct V_47 * V_47 ;
struct V_3 V_90 , * V_4 = NULL ;
struct V_48 * V_49 ;
int V_104 = 0 ;
V_49 = F_27 ( V_24 ) ;
if ( ! V_49 )
goto V_61;
if ( ! F_51 ( & V_24 -> V_121 ) )
goto V_146;
F_32 ( V_46 ) ;
if ( F_63 ( V_24 , V_49 , V_46 ) )
goto V_145;
V_47 = (struct V_47 * ) F_64 ( V_46 ) ;
if ( F_42 ( F_51 ( & V_24 -> V_26 . V_88 ) ) )
if ( F_87 ( V_47 -> V_70 ) )
goto V_145;
memcpy ( V_90 . V_6 , V_47 -> V_65 , V_36 ) ;
V_90 . V_7 = V_7 ;
V_4 = F_15 ( V_24 , & V_90 ) ;
if ( ! V_4 )
goto V_146;
if ( F_6 ( V_4 -> V_19 -> V_16 ,
V_49 -> V_59 -> V_60 ) ) {
F_60 ( V_24 , V_49 ,
V_49 -> V_59 -> V_60 ,
V_47 -> V_65 , V_7 ) ;
goto V_146;
}
if ( F_87 ( V_47 -> V_70 ) ) {
goto V_145;
} else {
goto V_146;
}
V_146:
F_48 ( V_24 , V_49 , V_7 ) ;
V_104 = 0 ;
goto V_61;
V_145:
V_104 = 1 ;
V_61:
if ( V_49 )
F_37 ( V_49 ) ;
if ( V_4 )
F_13 ( V_4 ) ;
return V_104 ;
}
int F_90 ( struct V_147 * V_148 , void * V_149 )
{
struct V_50 * V_59 = (struct V_50 * ) V_148 -> V_150 ;
struct V_23 * V_24 = F_91 ( V_59 ) ;
struct V_25 * V_5 = V_24 -> V_26 . V_27 ;
struct V_3 * V_4 ;
struct V_48 * V_49 ;
struct V_28 * V_29 ;
T_1 V_38 ;
bool V_151 ;
T_2 * V_152 ;
V_49 = F_92 ( V_148 ) ;
if ( ! V_49 )
goto V_61;
V_152 = V_49 -> V_59 -> V_60 ;
F_93 ( V_148 ,
L_23 ,
V_59 -> V_153 , V_152 ,
F_57 ( V_24 -> V_26 . V_56 . V_99 ) ) ;
F_93 ( V_148 , L_24 ,
L_25 , L_26 , L_27 , L_28 ) ;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
F_16 () ;
F_17 (claim, head, hash_entry) {
V_151 = F_6 ( V_4 -> V_19 -> V_16 ,
V_152 ) ;
F_93 ( V_148 , L_29 ,
V_4 -> V_6 , V_4 -> V_7 ,
V_4 -> V_19 -> V_16 ,
( V_151 ? 'x' : ' ' ) ,
V_4 -> V_19 -> V_41 ) ;
}
F_19 () ;
}
V_61:
if ( V_49 )
F_37 ( V_49 ) ;
return 0 ;
}
int F_94 ( struct V_147 * V_148 , void * V_149 )
{
struct V_50 * V_59 = (struct V_50 * ) V_148 -> V_150 ;
struct V_23 * V_24 = F_91 ( V_59 ) ;
struct V_25 * V_5 = V_24 -> V_26 . V_33 ;
struct V_12 * V_19 ;
struct V_48 * V_49 ;
struct V_28 * V_29 ;
int V_154 , V_155 ;
T_1 V_38 ;
bool V_151 ;
T_2 * V_152 ;
V_49 = F_92 ( V_148 ) ;
if ( ! V_49 )
goto V_61;
V_152 = V_49 -> V_59 -> V_60 ;
F_93 ( V_148 ,
L_30 ,
V_59 -> V_153 , V_152 ,
F_57 ( V_24 -> V_26 . V_56 . V_99 ) ) ;
F_93 ( V_148 , L_31 ,
L_27 , L_26 , L_32 , L_28 ) ;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
F_16 () ;
F_17 (backbone_gw, head, hash_entry) {
V_155 = F_95 ( V_77 -
V_19 -> V_84 ) ;
V_154 = V_155 / 1000 ;
V_155 = V_155 % 1000 ;
V_151 = F_6 ( V_19 -> V_16 ,
V_152 ) ;
if ( V_151 )
continue;
F_93 ( V_148 ,
L_33 ,
V_19 -> V_16 , V_19 -> V_7 ,
V_154 , V_155 , V_19 -> V_41 ) ;
}
F_19 () ;
}
V_61:
if ( V_49 )
F_37 ( V_49 ) ;
return 0 ;
}
