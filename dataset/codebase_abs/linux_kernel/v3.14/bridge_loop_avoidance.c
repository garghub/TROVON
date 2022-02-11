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
T_2 * V_6 , unsigned short V_7 )
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
unsigned short V_7 , int V_44 )
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
L_1 , V_43 ,
F_30 ( V_7 ) ) ;
break;
case V_67 :
memcpy ( V_52 , V_43 , V_36 ) ;
F_29 ( V_66 , V_24 ,
L_2 , V_43 ,
F_30 ( V_7 ) ) ;
break;
case V_68 :
memcpy ( V_52 , V_43 , V_36 ) ;
F_29 ( V_66 , V_24 ,
L_3 ,
V_47 -> V_65 , F_30 ( V_7 ) ) ;
break;
case V_69 :
memcpy ( V_52 , V_43 , V_36 ) ;
memcpy ( V_47 -> V_70 , V_43 , V_36 ) ;
F_29 ( V_66 , V_24 ,
L_4 ,
V_47 -> V_65 , V_47 -> V_70 ,
F_30 ( V_7 ) ) ;
break;
}
if ( V_7 & V_71 )
V_46 = F_31 ( V_46 , F_32 ( V_72 ) ,
V_7 & V_73 ) ;
F_33 ( V_46 ) ;
V_46 -> V_74 = F_34 ( V_46 , V_51 ) ;
F_35 ( V_24 , V_75 ) ;
F_36 ( V_24 , V_76 ,
V_46 -> V_77 + V_62 ) ;
V_51 -> V_78 = V_79 ;
F_37 ( V_46 ) ;
V_61:
if ( V_49 )
F_38 ( V_49 ) ;
}
static struct V_12 *
F_39 ( struct V_23 * V_24 , T_2 * V_16 ,
unsigned short V_7 , bool V_80 )
{
struct V_12 * V_81 ;
struct V_82 * V_83 ;
int V_84 ;
V_81 = F_20 ( V_24 , V_16 , V_7 ) ;
if ( V_81 )
return V_81 ;
F_29 ( V_66 , V_24 ,
L_5 ,
V_16 , F_30 ( V_7 ) ) ;
V_81 = F_40 ( sizeof( * V_81 ) , V_85 ) ;
if ( ! V_81 )
return NULL ;
V_81 -> V_7 = V_7 ;
V_81 -> V_86 = V_79 ;
V_81 -> V_41 = V_42 ;
V_81 -> V_24 = V_24 ;
F_41 ( & V_81 -> V_87 , 0 ) ;
F_41 ( & V_81 -> V_88 , 0 ) ;
memcpy ( V_81 -> V_16 , V_16 , V_36 ) ;
F_41 ( & V_81 -> V_20 , 2 ) ;
V_84 = F_42 ( V_24 -> V_26 . V_33 ,
F_4 ,
F_3 , V_81 ,
& V_81 -> V_13 ) ;
if ( F_43 ( V_84 != 0 ) ) {
F_12 ( V_81 ) ;
return NULL ;
}
V_83 = F_44 ( V_24 , V_16 ) ;
if ( V_83 ) {
F_45 ( V_24 , V_83 , V_7 ,
L_6 ) ;
F_46 ( V_83 ) ;
}
if ( V_80 ) {
F_47 ( V_24 , V_81 ) ;
F_48 ( & V_81 -> V_87 ) ;
F_41 ( & V_81 -> V_88 , V_89 ) ;
F_48 ( & V_24 -> V_26 . V_90 ) ;
}
return V_81 ;
}
static void
F_49 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
unsigned short V_7 )
{
struct V_12 * V_19 ;
V_19 = F_39 ( V_24 ,
V_49 -> V_59 -> V_60 ,
V_7 , true ) ;
if ( F_43 ( ! V_19 ) )
return;
V_19 -> V_86 = V_79 ;
F_8 ( V_19 ) ;
}
static void F_50 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
unsigned short V_7 )
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
F_47 ( V_24 , V_19 ) ;
F_8 ( V_19 ) ;
}
static void F_51 ( struct V_12 * V_19 )
{
F_21 ( V_19 ) ;
F_29 ( V_66 , V_19 -> V_24 ,
L_8 , V_19 -> V_16 ) ;
F_26 ( V_19 -> V_24 , V_19 -> V_16 ,
V_19 -> V_7 , V_69 ) ;
if ( ! F_52 ( & V_19 -> V_87 ) ) {
F_48 ( & V_19 -> V_24 -> V_26 . V_90 ) ;
F_41 ( & V_19 -> V_87 , 1 ) ;
}
}
static void F_47 ( struct V_23 * V_24 ,
struct V_12 * V_19 )
{
T_2 V_43 [ V_36 ] ;
T_5 V_41 ;
memcpy ( V_43 , V_91 , 4 ) ;
V_41 = F_32 ( V_19 -> V_41 ) ;
memcpy ( & V_43 [ 4 ] , & V_41 , 2 ) ;
F_26 ( V_24 , V_43 , V_19 -> V_7 ,
V_68 ) ;
}
static void F_53 ( struct V_23 * V_24 ,
const T_2 * V_43 , const unsigned short V_7 ,
struct V_12 * V_19 )
{
struct V_3 * V_4 ;
struct V_3 V_92 ;
int V_84 ;
memcpy ( V_92 . V_6 , V_43 , V_36 ) ;
V_92 . V_7 = V_7 ;
V_4 = F_15 ( V_24 , & V_92 ) ;
if ( ! V_4 ) {
V_4 = F_40 ( sizeof( * V_4 ) , V_85 ) ;
if ( ! V_4 )
return;
memcpy ( V_4 -> V_6 , V_43 , V_36 ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_86 = V_79 ;
V_4 -> V_19 = V_19 ;
F_41 ( & V_4 -> V_20 , 2 ) ;
F_29 ( V_66 , V_24 ,
L_9 ,
V_43 , F_30 ( V_7 ) ) ;
V_84 = F_42 ( V_24 -> V_26 . V_27 ,
F_7 ,
F_1 , V_4 ,
& V_4 -> V_13 ) ;
if ( F_43 ( V_84 != 0 ) ) {
F_12 ( V_4 ) ;
return;
}
} else {
V_4 -> V_86 = V_79 ;
if ( V_4 -> V_19 == V_19 )
goto V_93;
F_29 ( V_66 , V_24 ,
L_10 ,
V_43 , F_30 ( V_7 ) ) ;
V_4 -> V_19 -> V_41 ^= F_54 ( 0 , V_4 -> V_6 , V_36 ) ;
F_8 ( V_4 -> V_19 ) ;
}
F_48 ( & V_19 -> V_20 ) ;
V_4 -> V_19 = V_19 ;
V_19 -> V_41 ^= F_54 ( 0 , V_4 -> V_6 , V_36 ) ;
V_19 -> V_86 = V_79 ;
V_93:
F_13 ( V_4 ) ;
}
static void F_55 ( struct V_23 * V_24 ,
const T_2 * V_43 , const unsigned short V_7 )
{
struct V_3 V_92 , * V_4 ;
memcpy ( V_92 . V_6 , V_43 , V_36 ) ;
V_92 . V_7 = V_7 ;
V_4 = F_15 ( V_24 , & V_92 ) ;
if ( ! V_4 )
return;
F_29 ( V_66 , V_24 , L_11 ,
V_43 , F_30 ( V_7 ) ) ;
F_56 ( V_24 -> V_26 . V_27 , F_7 ,
F_1 , V_4 ) ;
F_13 ( V_4 ) ;
V_4 -> V_19 -> V_41 ^= F_54 ( 0 , V_4 -> V_6 , V_36 ) ;
F_13 ( V_4 ) ;
}
static int F_57 ( struct V_23 * V_24 ,
T_2 * V_94 , T_2 * V_95 ,
unsigned short V_7 )
{
struct V_12 * V_19 ;
T_6 V_41 ;
if ( memcmp ( V_94 , V_91 , 4 ) != 0 )
return 0 ;
V_19 = F_39 ( V_24 , V_95 , V_7 ,
false ) ;
if ( F_43 ( ! V_19 ) )
return 1 ;
V_19 -> V_86 = V_79 ;
V_41 = F_58 ( * ( ( T_5 * ) ( & V_94 [ 4 ] ) ) ) ;
F_29 ( V_66 , V_24 ,
L_12 ,
F_30 ( V_7 ) , V_19 -> V_16 , V_41 ) ;
if ( V_19 -> V_41 != V_41 ) {
F_29 ( V_66 , V_19 -> V_24 ,
L_13 ,
V_19 -> V_16 ,
F_30 ( V_19 -> V_7 ) ,
V_19 -> V_41 , V_41 ) ;
F_51 ( V_19 ) ;
} else {
if ( F_52 ( & V_19 -> V_87 ) ) {
F_59 ( & V_19 -> V_24 -> V_26 . V_90 ) ;
F_41 ( & V_19 -> V_87 , 0 ) ;
}
}
F_8 ( V_19 ) ;
return 1 ;
}
static int F_60 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
T_2 * V_95 ,
struct V_47 * V_47 , unsigned short V_7 )
{
if ( ! F_6 ( V_95 , V_47 -> V_70 ) )
return 0 ;
if ( ! F_6 ( V_47 -> V_70 , V_49 -> V_59 -> V_60 ) )
return 1 ;
F_29 ( V_66 , V_24 ,
L_14 ,
F_30 ( V_7 ) , V_47 -> V_65 ) ;
F_50 ( V_24 , V_49 , V_7 ) ;
return 1 ;
}
static int F_61 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
T_2 * V_95 ,
T_2 * V_96 , unsigned short V_7 )
{
struct V_12 * V_19 ;
if ( V_49 && F_6 ( V_95 ,
V_49 -> V_59 -> V_60 ) )
F_26 ( V_24 , V_96 , V_7 ,
V_67 ) ;
V_19 = F_20 ( V_24 , V_95 , V_7 ) ;
if ( ! V_19 )
return 1 ;
F_29 ( V_66 , V_24 ,
L_15 ,
V_96 , F_30 ( V_7 ) , V_19 -> V_16 ) ;
F_55 ( V_24 , V_96 , V_7 ) ;
F_8 ( V_19 ) ;
return 1 ;
}
static int F_62 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
T_2 * V_95 , T_2 * V_96 ,
unsigned short V_7 )
{
struct V_12 * V_19 ;
V_19 = F_39 ( V_24 , V_95 , V_7 ,
false ) ;
if ( F_43 ( ! V_19 ) )
return 1 ;
F_53 ( V_24 , V_96 , V_7 , V_19 ) ;
if ( F_6 ( V_95 , V_49 -> V_59 -> V_60 ) )
F_26 ( V_24 , V_96 , V_7 ,
V_64 ) ;
F_8 ( V_19 ) ;
return 1 ;
}
static int F_63 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
T_2 * V_52 , T_2 * V_97 ,
struct V_47 * V_47 )
{
T_2 * V_95 ;
struct V_82 * V_83 ;
struct V_53 * V_98 , * V_99 ;
V_98 = (struct V_53 * ) V_97 ;
V_99 = & V_24 -> V_26 . V_56 ;
if ( memcmp ( V_98 -> V_100 , V_99 -> V_100 ,
sizeof( V_98 -> V_100 ) ) != 0 )
return 0 ;
switch ( V_98 -> type ) {
case V_64 :
V_95 = V_52 ;
break;
case V_69 :
case V_68 :
case V_67 :
V_95 = V_47 -> V_65 ;
break;
default:
return 0 ;
}
if ( F_6 ( V_95 , V_49 -> V_59 -> V_60 ) )
return 0 ;
if ( V_98 -> V_101 == V_99 -> V_101 )
return 2 ;
V_83 = F_44 ( V_24 , V_95 ) ;
if ( ! V_83 )
return 1 ;
if ( F_58 ( V_98 -> V_101 ) > F_58 ( V_99 -> V_101 ) ) {
F_29 ( V_66 , V_24 ,
L_16 ,
F_58 ( V_98 -> V_101 ) ) ;
V_99 -> V_101 = V_98 -> V_101 ;
}
F_46 ( V_83 ) ;
return 2 ;
}
static int F_64 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
struct V_45 * V_46 )
{
struct V_53 * V_98 ;
T_2 * V_52 , * V_97 ;
struct V_102 * V_103 ;
struct V_47 * V_47 ;
struct V_63 * V_63 ;
unsigned short V_7 ;
T_5 V_104 ;
int V_105 ;
int V_106 ;
V_7 = F_65 ( V_46 , 0 ) ;
V_47 = F_66 ( V_46 ) ;
V_104 = V_47 -> V_107 ;
V_105 = V_62 ;
if ( V_7 & V_71 ) {
V_103 = (struct V_102 * ) V_47 ;
V_104 = V_103 -> V_108 ;
V_105 += V_109 ;
}
if ( V_104 != F_32 ( V_58 ) )
return 0 ;
if ( F_43 ( ! F_67 ( V_46 , V_105 + F_68 ( V_46 -> V_110 ) ) ) )
return 0 ;
V_47 = F_66 ( V_46 ) ;
V_63 = (struct V_63 * ) ( ( T_2 * ) V_47 + V_105 ) ;
if ( V_63 -> V_111 != F_32 ( V_112 ) )
return 0 ;
if ( V_63 -> V_113 != F_32 ( V_114 ) )
return 0 ;
if ( V_63 -> V_115 != V_36 )
return 0 ;
if ( V_63 -> V_116 != 4 )
return 0 ;
V_52 = ( T_2 * ) V_63 + sizeof( struct V_63 ) ;
V_97 = V_52 + V_36 + 4 ;
V_98 = (struct V_53 * ) V_97 ;
V_106 = F_63 ( V_24 , V_49 , V_52 , V_97 ,
V_47 ) ;
if ( V_106 == 1 )
F_29 ( V_66 , V_24 ,
L_17 ,
V_47 -> V_65 , F_30 ( V_7 ) , V_52 ,
V_97 ) ;
if ( V_106 < 2 )
return V_106 ;
F_49 ( V_24 , V_49 , V_7 ) ;
switch ( V_98 -> type ) {
case V_64 :
if ( F_62 ( V_24 , V_49 , V_52 ,
V_47 -> V_65 , V_7 ) )
return 1 ;
break;
case V_67 :
if ( F_61 ( V_24 , V_49 ,
V_47 -> V_65 , V_52 , V_7 ) )
return 1 ;
break;
case V_68 :
if ( F_57 ( V_24 , V_52 , V_47 -> V_65 ,
V_7 ) )
return 1 ;
break;
case V_69 :
if ( F_60 ( V_24 , V_49 , V_52 , V_47 ,
V_7 ) )
return 1 ;
break;
}
F_29 ( V_66 , V_24 ,
L_18 ,
V_47 -> V_65 , F_30 ( V_7 ) , V_52 , V_97 ) ;
return 1 ;
}
static void F_69 ( struct V_23 * V_24 , int V_117 )
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
if ( V_117 )
goto V_118;
if ( ! F_70 ( V_19 -> V_86 ,
V_119 ) )
continue;
F_29 ( V_66 , V_19 -> V_24 ,
L_19 ,
V_19 -> V_16 ) ;
V_118:
if ( F_52 ( & V_19 -> V_87 ) )
F_59 ( & V_24 -> V_26 . V_90 ) ;
F_21 ( V_19 ) ;
F_24 ( & V_19 -> V_13 ) ;
F_8 ( V_19 ) ;
}
F_25 ( V_39 ) ;
}
}
static void F_71 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
int V_117 )
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
if ( V_117 )
goto V_118;
if ( ! F_6 ( V_4 -> V_19 -> V_16 ,
V_49 -> V_59 -> V_60 ) )
continue;
if ( ! F_70 ( V_4 -> V_86 ,
V_120 ) )
continue;
F_29 ( V_66 , V_24 ,
L_20 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
V_118:
F_61 ( V_24 , V_49 ,
V_4 -> V_19 -> V_16 ,
V_4 -> V_6 , V_4 -> V_7 ) ;
}
F_19 () ;
}
}
void F_72 ( struct V_23 * V_24 ,
struct V_48 * V_49 ,
struct V_48 * V_121 )
{
struct V_12 * V_19 ;
struct V_28 * V_29 ;
struct V_25 * V_5 ;
T_5 V_101 ;
int V_38 ;
V_101 = F_32 ( F_54 ( 0 , V_49 -> V_59 -> V_60 , V_36 ) ) ;
V_24 -> V_26 . V_56 . V_101 = V_101 ;
if ( ! F_52 ( & V_24 -> V_122 ) )
V_121 = NULL ;
if ( ! V_121 ) {
F_71 ( V_24 , NULL , 1 ) ;
F_69 ( V_24 , 1 ) ;
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
V_121 -> V_59 -> V_60 ) )
continue;
memcpy ( V_19 -> V_16 ,
V_49 -> V_59 -> V_60 , V_36 ) ;
F_47 ( V_24 , V_19 ) ;
}
F_19 () ;
}
}
static void F_73 ( struct V_123 * V_124 )
{
struct V_125 * V_125 ;
struct V_23 * V_24 ;
struct V_126 * V_127 ;
struct V_28 * V_29 ;
struct V_12 * V_19 ;
struct V_25 * V_5 ;
struct V_48 * V_49 ;
int V_38 ;
V_125 = F_5 ( V_124 , struct V_125 , V_124 ) ;
V_127 = F_5 ( V_125 , struct V_126 , V_124 ) ;
V_24 = F_5 ( V_127 , struct V_23 , V_26 ) ;
V_49 = F_27 ( V_24 ) ;
if ( ! V_49 )
goto V_61;
F_71 ( V_24 , V_49 , 0 ) ;
F_69 ( V_24 , 0 ) ;
if ( ! F_52 ( & V_24 -> V_122 ) )
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
V_19 -> V_86 = V_79 ;
F_47 ( V_24 , V_19 ) ;
if ( F_52 ( & V_19 -> V_87 ) == 0 )
continue;
if ( ! F_9 ( & V_19 -> V_88 ) )
continue;
F_59 ( & V_19 -> V_24 -> V_26 . V_90 ) ;
F_41 ( & V_19 -> V_87 , 0 ) ;
}
F_19 () ;
}
V_61:
if ( V_49 )
F_38 ( V_49 ) ;
F_74 ( V_128 , & V_24 -> V_26 . V_124 ,
F_75 ( V_129 ) ) ;
}
int F_76 ( struct V_23 * V_24 )
{
int V_38 ;
T_2 V_56 [ V_36 ] = { 0xff , 0x43 , 0x05 , 0x00 , 0x00 , 0x00 } ;
struct V_48 * V_49 ;
T_6 V_41 ;
unsigned long V_130 ;
F_77 ( & V_24 -> V_26 . V_131 ) ;
F_29 ( V_66 , V_24 , L_21 ) ;
memcpy ( & V_24 -> V_26 . V_56 . V_100 , V_56 , 3 ) ;
V_24 -> V_26 . V_56 . type = 0 ;
V_49 = F_27 ( V_24 ) ;
if ( V_49 ) {
V_41 = F_54 ( 0 , V_49 -> V_59 -> V_60 , V_36 ) ;
V_24 -> V_26 . V_56 . V_101 = F_32 ( V_41 ) ;
F_38 ( V_49 ) ;
} else {
V_24 -> V_26 . V_56 . V_101 = 0 ;
}
V_130 = V_79 - F_75 ( V_132 ) ;
for ( V_38 = 0 ; V_38 < V_133 ; V_38 ++ )
V_24 -> V_26 . V_134 [ V_38 ] . V_130 = V_130 ;
V_24 -> V_26 . V_135 = 0 ;
if ( V_24 -> V_26 . V_27 )
return 0 ;
V_24 -> V_26 . V_27 = F_78 ( 128 ) ;
V_24 -> V_26 . V_33 = F_78 ( 32 ) ;
if ( ! V_24 -> V_26 . V_27 || ! V_24 -> V_26 . V_33 )
return - V_136 ;
F_79 ( V_24 -> V_26 . V_27 ,
& V_137 ) ;
F_79 ( V_24 -> V_26 . V_33 ,
& V_138 ) ;
F_29 ( V_66 , V_24 , L_22 ) ;
F_80 ( & V_24 -> V_26 . V_124 , F_73 ) ;
F_74 ( V_128 , & V_24 -> V_26 . V_124 ,
F_75 ( V_129 ) ) ;
return 0 ;
}
int F_81 ( struct V_23 * V_24 ,
struct V_45 * V_46 )
{
int V_38 , V_139 , V_106 = 0 ;
T_4 V_41 ;
struct V_140 * V_141 ;
struct V_142 * V_81 ;
V_141 = (struct V_140 * ) V_46 -> V_1 ;
V_41 = F_82 ( V_46 , ( V_143 * ) ( V_141 + 1 ) ) ;
F_22 ( & V_24 -> V_26 . V_131 ) ;
for ( V_38 = 0 ; V_38 < V_133 ; V_38 ++ ) {
V_139 = ( V_24 -> V_26 . V_135 + V_38 ) ;
V_139 %= V_133 ;
V_81 = & V_24 -> V_26 . V_134 [ V_139 ] ;
if ( F_70 ( V_81 -> V_130 ,
V_132 ) )
break;
if ( V_81 -> V_41 != V_41 )
continue;
if ( F_6 ( V_81 -> V_16 , V_141 -> V_16 ) )
continue;
V_106 = 1 ;
goto V_61;
}
V_139 = ( V_24 -> V_26 . V_135 + V_133 - 1 ) ;
V_139 %= V_133 ;
V_81 = & V_24 -> V_26 . V_134 [ V_139 ] ;
V_81 -> V_41 = V_41 ;
V_81 -> V_130 = V_79 ;
memcpy ( V_81 -> V_16 , V_141 -> V_16 , V_36 ) ;
V_24 -> V_26 . V_135 = V_139 ;
V_61:
F_25 ( & V_24 -> V_26 . V_131 ) ;
return V_106 ;
}
bool F_83 ( struct V_23 * V_24 , T_2 * V_16 ,
unsigned short V_7 )
{
struct V_25 * V_5 = V_24 -> V_26 . V_33 ;
struct V_28 * V_29 ;
struct V_12 * V_19 ;
int V_38 ;
if ( ! F_52 ( & V_24 -> V_122 ) )
return false ;
if ( ! V_5 )
return false ;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
F_16 () ;
F_17 (backbone_gw, head, hash_entry) {
if ( F_6 ( V_19 -> V_16 , V_16 ) &&
V_19 -> V_7 == V_7 ) {
F_19 () ;
return true ;
}
}
F_19 () ;
}
return false ;
}
int F_84 ( struct V_45 * V_46 ,
struct V_82 * V_83 , int V_144 )
{
struct V_12 * V_19 ;
unsigned short V_7 ;
if ( ! F_52 ( & V_83 -> V_24 -> V_122 ) )
return 0 ;
if ( ! F_67 ( V_46 , V_144 + V_62 ) )
return 0 ;
V_7 = F_65 ( V_46 , V_144 ) ;
V_19 = F_20 ( V_83 -> V_24 ,
V_83 -> V_16 , V_7 ) ;
if ( ! V_19 )
return 0 ;
F_8 ( V_19 ) ;
return 1 ;
}
void F_85 ( struct V_23 * V_24 )
{
struct V_48 * V_49 ;
F_86 ( & V_24 -> V_26 . V_124 ) ;
V_49 = F_27 ( V_24 ) ;
if ( V_24 -> V_26 . V_27 ) {
F_71 ( V_24 , V_49 , 1 ) ;
F_87 ( V_24 -> V_26 . V_27 ) ;
V_24 -> V_26 . V_27 = NULL ;
}
if ( V_24 -> V_26 . V_33 ) {
F_69 ( V_24 , 1 ) ;
F_87 ( V_24 -> V_26 . V_33 ) ;
V_24 -> V_26 . V_33 = NULL ;
}
if ( V_49 )
F_38 ( V_49 ) ;
}
int F_88 ( struct V_23 * V_24 , struct V_45 * V_46 ,
unsigned short V_7 , bool V_145 )
{
struct V_47 * V_47 ;
struct V_3 V_92 , * V_4 = NULL ;
struct V_48 * V_49 ;
int V_106 ;
V_47 = F_66 ( V_46 ) ;
V_49 = F_27 ( V_24 ) ;
if ( ! V_49 )
goto V_146;
if ( ! F_52 ( & V_24 -> V_122 ) )
goto V_147;
if ( F_43 ( F_52 ( & V_24 -> V_26 . V_90 ) ) )
if ( F_89 ( V_47 -> V_70 ) && V_145 )
goto V_146;
memcpy ( V_92 . V_6 , V_47 -> V_65 , V_36 ) ;
V_92 . V_7 = V_7 ;
V_4 = F_15 ( V_24 , & V_92 ) ;
if ( ! V_4 ) {
F_62 ( V_24 , V_49 ,
V_49 -> V_59 -> V_60 ,
V_47 -> V_65 , V_7 ) ;
goto V_147;
}
if ( F_6 ( V_4 -> V_19 -> V_16 ,
V_49 -> V_59 -> V_60 ) ) {
V_4 -> V_86 = V_79 ;
goto V_147;
}
if ( F_89 ( V_47 -> V_70 ) && V_145 ) {
goto V_146;
} else {
F_62 ( V_24 , V_49 ,
V_49 -> V_59 -> V_60 ,
V_47 -> V_65 , V_7 ) ;
goto V_147;
}
V_147:
F_49 ( V_24 , V_49 , V_7 ) ;
V_106 = 0 ;
goto V_61;
V_146:
F_90 ( V_46 ) ;
V_106 = 1 ;
V_61:
if ( V_49 )
F_38 ( V_49 ) ;
if ( V_4 )
F_13 ( V_4 ) ;
return V_106 ;
}
int F_91 ( struct V_23 * V_24 , struct V_45 * V_46 ,
unsigned short V_7 )
{
struct V_47 * V_47 ;
struct V_3 V_92 , * V_4 = NULL ;
struct V_48 * V_49 ;
int V_106 = 0 ;
V_49 = F_27 ( V_24 ) ;
if ( ! V_49 )
goto V_61;
if ( ! F_52 ( & V_24 -> V_122 ) )
goto V_147;
F_33 ( V_46 ) ;
if ( F_64 ( V_24 , V_49 , V_46 ) )
goto V_146;
V_47 = F_66 ( V_46 ) ;
if ( F_43 ( F_52 ( & V_24 -> V_26 . V_90 ) ) )
if ( F_89 ( V_47 -> V_70 ) )
goto V_146;
memcpy ( V_92 . V_6 , V_47 -> V_65 , V_36 ) ;
V_92 . V_7 = V_7 ;
V_4 = F_15 ( V_24 , & V_92 ) ;
if ( ! V_4 )
goto V_147;
if ( F_6 ( V_4 -> V_19 -> V_16 ,
V_49 -> V_59 -> V_60 ) ) {
F_61 ( V_24 , V_49 ,
V_49 -> V_59 -> V_60 ,
V_47 -> V_65 , V_7 ) ;
goto V_147;
}
if ( F_89 ( V_47 -> V_70 ) ) {
goto V_146;
} else {
goto V_147;
}
V_147:
F_49 ( V_24 , V_49 , V_7 ) ;
V_106 = 0 ;
goto V_61;
V_146:
V_106 = 1 ;
V_61:
if ( V_49 )
F_38 ( V_49 ) ;
if ( V_4 )
F_13 ( V_4 ) ;
return V_106 ;
}
int F_92 ( struct V_148 * V_149 , void * V_150 )
{
struct V_50 * V_59 = (struct V_50 * ) V_149 -> V_151 ;
struct V_23 * V_24 = F_93 ( V_59 ) ;
struct V_25 * V_5 = V_24 -> V_26 . V_27 ;
struct V_3 * V_4 ;
struct V_48 * V_49 ;
struct V_28 * V_29 ;
T_1 V_38 ;
bool V_152 ;
T_2 * V_153 ;
V_49 = F_94 ( V_149 ) ;
if ( ! V_49 )
goto V_61;
V_153 = V_49 -> V_59 -> V_60 ;
F_95 ( V_149 ,
L_23 ,
V_59 -> V_154 , V_153 ,
F_58 ( V_24 -> V_26 . V_56 . V_101 ) ) ;
F_95 ( V_149 , L_24 ,
L_25 , L_26 , L_27 , L_28 ) ;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
F_16 () ;
F_17 (claim, head, hash_entry) {
V_152 = F_6 ( V_4 -> V_19 -> V_16 ,
V_153 ) ;
F_95 ( V_149 , L_29 ,
V_4 -> V_6 , F_30 ( V_4 -> V_7 ) ,
V_4 -> V_19 -> V_16 ,
( V_152 ? 'x' : ' ' ) ,
V_4 -> V_19 -> V_41 ) ;
}
F_19 () ;
}
V_61:
if ( V_49 )
F_38 ( V_49 ) ;
return 0 ;
}
int F_96 ( struct V_148 * V_149 , void * V_150 )
{
struct V_50 * V_59 = (struct V_50 * ) V_149 -> V_151 ;
struct V_23 * V_24 = F_93 ( V_59 ) ;
struct V_25 * V_5 = V_24 -> V_26 . V_33 ;
struct V_12 * V_19 ;
struct V_48 * V_49 ;
struct V_28 * V_29 ;
int V_155 , V_156 ;
T_1 V_38 ;
bool V_152 ;
T_2 * V_153 ;
V_49 = F_94 ( V_149 ) ;
if ( ! V_49 )
goto V_61;
V_153 = V_49 -> V_59 -> V_60 ;
F_95 ( V_149 ,
L_30 ,
V_59 -> V_154 , V_153 ,
F_58 ( V_24 -> V_26 . V_56 . V_101 ) ) ;
F_95 ( V_149 , L_31 ,
L_27 , L_26 , L_32 , L_28 ) ;
for ( V_38 = 0 ; V_38 < V_5 -> V_2 ; V_38 ++ ) {
V_29 = & V_5 -> V_32 [ V_38 ] ;
F_16 () ;
F_17 (backbone_gw, head, hash_entry) {
V_156 = F_97 ( V_79 -
V_19 -> V_86 ) ;
V_155 = V_156 / 1000 ;
V_156 = V_156 % 1000 ;
V_152 = F_6 ( V_19 -> V_16 ,
V_153 ) ;
if ( V_152 )
continue;
F_95 ( V_149 , L_33 ,
V_19 -> V_16 ,
F_30 ( V_19 -> V_7 ) , V_155 ,
V_156 , V_19 -> V_41 ) ;
}
F_19 () ;
}
V_61:
if ( V_49 )
F_38 ( V_49 ) ;
return 0 ;
}
