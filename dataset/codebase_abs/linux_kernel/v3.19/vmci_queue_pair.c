static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 ) {
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_2 , V_6 ) + 1 ; V_5 ++ ) {
F_3 ( & V_7 -> V_8 , V_6 ,
V_4 -> V_9 -> V_10 . V_11 . V_12 [ V_5 ] ,
V_4 -> V_9 -> V_10 . V_11 . V_13 [ V_5 ] ) ;
}
F_4 ( V_4 ) ;
}
}
static void * F_5 ( T_1 V_2 , T_2 V_14 )
{
T_1 V_5 ;
struct V_3 * V_4 ;
const T_3 V_15 = F_2 ( V_2 , V_6 ) + 1 ;
const T_3 V_16 = V_15 * sizeof( * V_4 -> V_9 -> V_10 . V_11 . V_13 ) ;
const T_3 V_17 = V_15 * sizeof( * V_4 -> V_9 -> V_10 . V_11 . V_12 ) ;
const T_3 V_18 =
sizeof( * V_4 ) + sizeof( * V_4 -> V_9 ) +
V_16 + V_17 ;
V_4 = F_6 ( V_18 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_19 = NULL ;
V_4 -> V_20 = NULL ;
V_4 -> V_9 = (struct V_21 * ) ( V_4 + 1 ) ;
V_4 -> V_9 -> V_22 = NULL ;
V_4 -> V_9 -> V_15 = V_15 ;
V_4 -> V_9 -> V_10 . V_11 . V_13 = ( V_23 * ) ( V_4 -> V_9 + 1 ) ;
V_4 -> V_9 -> V_10 . V_11 . V_12 =
( void * * ) ( ( V_24 * ) V_4 -> V_9 -> V_10 . V_11 . V_13 + V_16 ) ;
V_4 -> V_9 -> V_25 = false ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
V_4 -> V_9 -> V_10 . V_11 . V_12 [ V_5 ] =
F_7 ( & V_7 -> V_8 , V_6 ,
& V_4 -> V_9 -> V_10 . V_11 . V_13 [ V_5 ] ,
V_26 ) ;
if ( ! V_4 -> V_9 -> V_10 . V_11 . V_12 [ V_5 ] ) {
F_1 ( V_4 , V_5 * V_6 ) ;
return NULL ;
}
}
V_4 -> V_19 = V_4 -> V_9 -> V_10 . V_11 . V_12 [ 0 ] ;
return V_4 ;
}
static int F_8 ( struct V_3 * V_4 ,
T_1 V_27 ,
const void * V_28 ,
T_3 V_2 ,
bool V_29 )
{
struct V_21 * V_9 = V_4 -> V_9 ;
T_3 V_30 = 0 ;
while ( V_30 < V_2 ) {
const T_1 V_31 =
( V_27 + V_30 ) / V_6 ;
const T_3 V_32 =
( V_27 + V_30 ) & ( V_6 - 1 ) ;
void * V_33 ;
T_3 V_34 ;
if ( V_9 -> V_25 )
V_33 = F_9 ( V_9 -> V_10 . V_35 . V_36 [ V_31 ] ) ;
else
V_33 = V_9 -> V_10 . V_11 . V_12 [ V_31 + 1 ] ;
if ( V_2 - V_30 > V_6 - V_32 )
V_34 = V_6 - V_32 ;
else
V_34 = V_2 - V_30 ;
if ( V_29 ) {
struct V_37 * V_38 = (struct V_37 * ) V_28 ;
int V_39 ;
V_39 = F_10 ( ( V_24 * ) V_33 + V_32 ,
V_38 , V_34 ) ;
if ( V_39 != 0 ) {
if ( V_9 -> V_25 )
F_11 ( V_9 -> V_10 . V_35 . V_36 [ V_31 ] ) ;
return V_40 ;
}
} else {
memcpy ( ( V_24 * ) V_33 + V_32 ,
( V_24 * ) V_28 + V_30 , V_34 ) ;
}
V_30 += V_34 ;
if ( V_9 -> V_25 )
F_11 ( V_9 -> V_10 . V_35 . V_36 [ V_31 ] ) ;
}
return V_41 ;
}
static int F_12 ( void * V_42 ,
const struct V_3 * V_4 ,
T_1 V_27 ,
T_3 V_2 ,
bool V_29 )
{
struct V_21 * V_9 = V_4 -> V_9 ;
T_3 V_30 = 0 ;
while ( V_30 < V_2 ) {
const T_1 V_31 =
( V_27 + V_30 ) / V_6 ;
const T_3 V_32 =
( V_27 + V_30 ) & ( V_6 - 1 ) ;
void * V_33 ;
T_3 V_34 ;
if ( V_9 -> V_25 )
V_33 = F_9 ( V_9 -> V_10 . V_35 . V_36 [ V_31 ] ) ;
else
V_33 = V_9 -> V_10 . V_11 . V_12 [ V_31 + 1 ] ;
if ( V_2 - V_30 > V_6 - V_32 )
V_34 = V_6 - V_32 ;
else
V_34 = V_2 - V_30 ;
if ( V_29 ) {
struct V_43 * V_44 = V_42 ;
int V_39 ;
V_39 = F_13 ( V_44 , ( V_24 * ) V_33 + V_32 ,
V_34 ) ;
if ( V_39 != 0 ) {
if ( V_9 -> V_25 )
F_11 ( V_9 -> V_10 . V_35 . V_36 [ V_31 ] ) ;
return V_40 ;
}
} else {
memcpy ( ( V_24 * ) V_42 + V_30 ,
( V_24 * ) V_33 + V_32 , V_34 ) ;
}
V_30 += V_34 ;
if ( V_9 -> V_25 )
F_11 ( V_9 -> V_10 . V_35 . V_36 [ V_31 ] ) ;
}
return V_41 ;
}
static int F_14 ( void * V_45 ,
T_1 V_46 ,
void * V_47 ,
T_1 V_48 , struct V_49 * V_49 )
{
T_2 * V_50 ;
T_2 * V_51 ;
struct V_3 * V_52 = V_45 ;
struct V_3 * V_53 = V_47 ;
T_1 V_5 ;
if ( ! V_52 || ! V_46 || ! V_53 ||
! V_48 || ! V_49 )
return V_40 ;
if ( V_49 -> V_54 )
return V_55 ;
V_50 =
F_15 ( V_46 * sizeof( * V_50 ) , V_26 ) ;
if ( ! V_50 )
return V_56 ;
V_51 =
F_15 ( V_48 * sizeof( * V_51 ) , V_26 ) ;
if ( ! V_51 ) {
F_16 ( V_50 ) ;
return V_56 ;
}
for ( V_5 = 0 ; V_5 < V_46 ; V_5 ++ ) {
unsigned long V_57 ;
V_50 [ V_5 ] =
V_52 -> V_9 -> V_10 . V_11 . V_13 [ V_5 ] >> V_58 ;
V_57 = V_50 [ V_5 ] ;
if ( sizeof( V_57 ) > sizeof( * V_50 )
&& V_57 != V_50 [ V_5 ] )
goto V_59;
}
for ( V_5 = 0 ; V_5 < V_48 ; V_5 ++ ) {
unsigned long V_57 ;
V_51 [ V_5 ] =
V_53 -> V_9 -> V_10 . V_11 . V_13 [ V_5 ] >> V_58 ;
V_57 = V_51 [ V_5 ] ;
if ( sizeof( V_57 ) > sizeof( * V_51 )
&& V_57 != V_51 [ V_5 ] )
goto V_59;
}
V_49 -> V_46 = V_46 ;
V_49 -> V_48 = V_48 ;
V_49 -> V_50 = V_50 ;
V_49 -> V_51 = V_51 ;
V_49 -> V_54 = true ;
return V_41 ;
V_59:
F_16 ( V_50 ) ;
F_16 ( V_51 ) ;
return V_40 ;
}
static void F_17 ( struct V_49 * V_49 )
{
if ( V_49 -> V_54 ) {
F_16 ( V_49 -> V_50 ) ;
F_16 ( V_49 -> V_51 ) ;
}
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
}
static int F_18 ( V_24 * V_60 , const struct V_49 * V_49 )
{
memcpy ( V_60 , V_49 -> V_50 ,
V_49 -> V_46 * sizeof( * V_49 -> V_50 ) ) ;
memcpy ( V_60 +
V_49 -> V_46 * sizeof( * V_49 -> V_50 ) ,
V_49 -> V_51 ,
V_49 -> V_48 * sizeof( * V_49 -> V_51 ) ) ;
return V_41 ;
}
static int F_19 ( struct V_3 * V_4 ,
T_1 V_27 ,
const void * V_28 , T_3 V_61 , T_3 V_2 )
{
return F_8 ( V_4 , V_27 ,
( V_24 * ) V_28 + V_61 , V_2 , false ) ;
}
static int F_20 ( void * V_42 ,
T_3 V_62 ,
const struct V_3 * V_4 ,
T_1 V_27 , T_3 V_2 )
{
return F_12 ( ( V_24 * ) V_42 + V_62 ,
V_4 , V_27 , V_2 , false ) ;
}
static int F_21 ( struct V_3 * V_4 ,
T_1 V_27 ,
const void * V_28 ,
T_3 V_61 , T_3 V_2 )
{
return F_8 ( V_4 , V_27 , V_28 , V_2 , true ) ;
}
static int F_22 ( void * V_42 ,
T_3 V_62 ,
const struct V_3 * V_4 ,
T_1 V_27 , T_3 V_2 )
{
return F_12 ( V_42 , V_4 , V_27 , V_2 , true ) ;
}
static struct V_3 * F_23 ( T_1 V_2 )
{
struct V_3 * V_4 ;
const T_3 V_15 = F_2 ( V_2 , V_6 ) + 1 ;
const T_3 V_18 = sizeof( * V_4 ) + sizeof( * ( V_4 -> V_9 ) ) ;
const T_3 V_63 =
V_15 * sizeof( * V_4 -> V_9 -> V_10 . V_35 . V_36 ) ;
V_4 = F_24 ( V_18 + V_63 , V_26 ) ;
if ( V_4 ) {
V_4 -> V_19 = NULL ;
V_4 -> V_20 = NULL ;
V_4 -> V_9 = (struct V_21 * ) ( V_4 + 1 ) ;
V_4 -> V_9 -> V_25 = true ;
V_4 -> V_9 -> V_22 = NULL ;
V_4 -> V_9 -> V_15 = V_15 ;
V_4 -> V_9 -> V_10 . V_35 . V_64 =
(struct V_36 * * ) ( ( V_24 * ) V_4 + V_18 ) ;
V_4 -> V_9 -> V_10 . V_35 . V_36 =
& V_4 -> V_9 -> V_10 . V_35 . V_64 [ 1 ] ;
}
return V_4 ;
}
static void F_25 ( struct V_3 * V_4 , T_1 V_18 )
{
F_16 ( V_4 ) ;
}
static void F_26 ( struct V_3 * V_52 ,
struct V_3 * V_53 )
{
if ( V_52 -> V_9 -> V_25 ) {
V_52 -> V_9 -> V_22 = & V_52 -> V_9 -> V_65 ;
V_53 -> V_9 -> V_22 = & V_52 -> V_9 -> V_65 ;
F_27 ( V_52 -> V_9 -> V_22 ) ;
}
}
static void F_28 ( struct V_3 * V_52 ,
struct V_3 * V_53 )
{
if ( V_52 -> V_9 -> V_25 ) {
V_52 -> V_9 -> V_22 = NULL ;
V_53 -> V_9 -> V_22 = NULL ;
}
}
static void F_29 ( struct V_3 * V_4 )
{
if ( V_4 -> V_9 -> V_25 )
F_30 ( V_4 -> V_9 -> V_22 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
if ( V_4 -> V_9 -> V_25 )
F_32 ( V_4 -> V_9 -> V_22 ) ;
}
static void F_33 ( struct V_36 * * V_66 ,
T_1 V_15 , bool V_67 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
if ( V_67 )
F_34 ( V_66 [ V_5 ] ) ;
F_35 ( V_66 [ V_5 ] ) ;
V_66 [ V_5 ] = NULL ;
}
}
static int F_36 ( T_1 V_68 ,
T_1 V_69 ,
struct V_3 * V_52 ,
struct V_3 * V_53 )
{
int V_70 ;
int V_39 = V_41 ;
V_70 = F_37 ( ( V_71 ) V_68 ,
V_52 -> V_9 -> V_15 , 1 ,
V_52 -> V_9 -> V_10 . V_35 . V_64 ) ;
if ( V_70 < V_52 -> V_9 -> V_15 ) {
F_38 ( L_1 , V_70 ) ;
F_33 ( V_52 -> V_9 -> V_10 . V_35 . V_64 ,
V_70 , false ) ;
V_39 = V_56 ;
goto V_72;
}
V_70 = F_37 ( ( V_71 ) V_69 ,
V_53 -> V_9 -> V_15 , 1 ,
V_53 -> V_9 -> V_10 . V_35 . V_64 ) ;
if ( V_70 < V_53 -> V_9 -> V_15 ) {
F_38 ( L_2 , V_70 ) ;
F_33 ( V_53 -> V_9 -> V_10 . V_35 . V_64 ,
V_70 , false ) ;
F_33 ( V_52 -> V_9 -> V_10 . V_35 . V_64 ,
V_52 -> V_9 -> V_15 , false ) ;
V_39 = V_56 ;
}
V_72:
return V_39 ;
}
static int F_39 ( struct V_73 * V_74 ,
struct V_3 * V_52 ,
struct V_3 * V_53 )
{
T_1 V_68 ;
T_1 V_69 ;
V_68 = V_74 -> V_66 ;
V_69 = V_74 -> V_66 +
V_52 -> V_9 -> V_15 * V_6 ;
return F_36 ( V_68 , V_69 , V_52 ,
V_53 ) ;
}
static void F_40 ( struct V_3 * V_52 ,
struct V_3 * V_53 )
{
F_33 ( V_52 -> V_9 -> V_10 . V_35 . V_64 ,
V_52 -> V_9 -> V_15 , true ) ;
memset ( V_52 -> V_9 -> V_10 . V_35 . V_64 , 0 ,
sizeof( * V_52 -> V_9 -> V_10 . V_35 . V_64 ) *
V_52 -> V_9 -> V_15 ) ;
F_33 ( V_53 -> V_9 -> V_10 . V_35 . V_64 ,
V_53 -> V_9 -> V_15 , true ) ;
memset ( V_53 -> V_9 -> V_10 . V_35 . V_64 , 0 ,
sizeof( * V_53 -> V_9 -> V_10 . V_35 . V_64 ) *
V_53 -> V_9 -> V_15 ) ;
}
static int F_41 ( struct V_3 * V_52 ,
struct V_3 * V_53 )
{
int V_75 ;
if ( ! V_52 -> V_19 || ! V_53 -> V_19 ) {
struct V_36 * V_76 [ 2 ] ;
if ( V_52 -> V_19 != V_53 -> V_19 )
return V_77 ;
if ( V_52 -> V_9 -> V_10 . V_35 . V_64 == NULL ||
* V_52 -> V_9 -> V_10 . V_35 . V_64 == NULL )
return V_78 ;
V_76 [ 0 ] = * V_52 -> V_9 -> V_10 . V_35 . V_64 ;
V_76 [ 1 ] = * V_53 -> V_9 -> V_10 . V_35 . V_64 ;
V_52 -> V_19 = F_42 ( V_76 , 2 , V_79 , V_80 ) ;
if ( V_52 -> V_19 != NULL ) {
V_53 -> V_19 =
(struct V_81 * ) ( ( V_24 * )
V_52 -> V_19 +
V_6 ) ;
V_75 = V_41 ;
} else {
F_38 ( L_3 ) ;
V_75 = V_56 ;
}
} else {
V_75 = V_41 ;
}
return V_75 ;
}
static int F_43 ( T_2 V_82 ,
struct V_3 * V_52 ,
struct V_3 * V_53 )
{
if ( V_52 -> V_19 ) {
if ( V_52 -> V_19 < V_53 -> V_19 )
F_44 ( V_52 -> V_19 ) ;
else
F_44 ( V_53 -> V_19 ) ;
V_52 -> V_19 = NULL ;
V_53 -> V_19 = NULL ;
}
return V_41 ;
}
static struct V_83 * F_45 ( struct V_84 * V_84 ,
struct V_85 V_86 )
{
struct V_83 * V_87 ;
if ( F_46 ( V_86 ) )
return NULL ;
F_47 (entry, &qp_list->head, list_item) {
if ( F_48 ( V_87 -> V_86 , V_86 ) )
return V_87 ;
}
return NULL ;
}
static struct V_88 *
F_49 ( struct V_85 V_86 )
{
struct V_88 * V_87 ;
struct V_83 * V_89 = F_45 ( & V_90 , V_86 ) ;
V_87 = V_89 ? F_50 (
V_89 , struct V_88 , V_89 ) : NULL ;
return V_87 ;
}
static struct V_91 *
F_51 ( struct V_85 V_86 )
{
struct V_91 * V_87 ;
struct V_83 * V_89 = F_45 ( & V_92 , V_86 ) ;
V_87 = V_89 ? F_50 (
V_89 , struct V_91 , V_89 ) : NULL ;
return V_87 ;
}
static int F_52 ( bool V_93 , struct V_85 V_86 )
{
T_2 V_94 = F_53 () ;
struct V_95 V_96 ;
V_96 . V_44 . V_97 . V_98 = F_54 ( V_94 , V_99 ) ;
V_96 . V_44 . V_97 . V_28 = F_54 ( V_100 ,
V_101 ) ;
V_96 . V_44 . V_97 . V_102 = sizeof( V_96 ) - sizeof( V_96 . V_44 . V_97 ) ;
V_96 . V_44 . V_103 . V_104 =
V_93 ? V_105 : V_106 ;
V_96 . V_107 . V_108 = V_94 ;
V_96 . V_107 . V_86 = V_86 ;
return F_55 ( & V_96 . V_44 . V_97 ) ;
}
static struct V_88 *
F_56 ( struct V_85 V_86 ,
T_2 V_109 ,
T_2 V_14 ,
T_1 V_110 ,
T_1 V_111 ,
void * V_52 ,
void * V_53 )
{
int V_75 ;
struct V_88 * V_87 ;
const T_1 V_112 = F_2 ( V_110 , V_6 ) +
F_2 ( V_111 , V_6 ) + 2 ;
if ( F_46 ( V_86 ) ) {
T_2 V_94 = F_53 () ;
V_86 = F_54 ( V_94 , V_113 ) ;
}
V_87 = F_24 ( sizeof( * V_87 ) , V_26 ) ;
if ( V_87 ) {
V_87 -> V_89 . V_109 = V_109 ;
V_87 -> V_89 . V_14 = V_14 ;
V_87 -> V_89 . V_110 = V_110 ;
V_87 -> V_89 . V_111 = V_111 ;
V_87 -> V_89 . V_114 = 0 ;
V_87 -> V_112 = V_112 ;
V_87 -> V_52 = V_52 ;
V_87 -> V_53 = V_53 ;
F_57 ( & V_87 -> V_89 . V_115 ) ;
V_75 = F_58 ( & V_87 -> V_116 ,
V_117 ,
V_86 ) ;
V_87 -> V_89 . V_86 = F_59 ( & V_87 -> V_116 ) ;
if ( ( V_75 != V_41 ) ||
F_45 ( & V_90 , V_87 -> V_89 . V_86 ) ) {
F_38 ( L_4 ,
V_86 . V_118 , V_86 . V_116 , V_75 ) ;
F_16 ( V_87 ) ;
V_87 = NULL ;
}
}
return V_87 ;
}
static void F_60 ( struct V_88 * V_87 )
{
F_17 ( & V_87 -> V_49 ) ;
F_28 ( V_87 -> V_52 , V_87 -> V_53 ) ;
F_1 ( V_87 -> V_52 , V_87 -> V_89 . V_110 ) ;
F_1 ( V_87 -> V_53 , V_87 -> V_89 . V_111 ) ;
F_61 ( & V_87 -> V_116 ) ;
F_16 ( V_87 ) ;
}
static int F_62 ( const struct V_88 * V_87 )
{
struct V_119 * V_120 ;
T_3 V_121 ;
int V_75 ;
if ( ! V_87 || V_87 -> V_112 <= 2 )
return V_40 ;
V_121 = sizeof( * V_120 ) +
( T_3 ) V_87 -> V_112 * sizeof( T_2 ) ;
V_120 = F_15 ( V_121 , V_26 ) ;
if ( ! V_120 )
return V_56 ;
V_120 -> V_97 . V_98 = F_54 ( V_100 ,
V_122 ) ;
V_120 -> V_97 . V_28 = V_123 ;
V_120 -> V_97 . V_102 = V_121 - V_124 ;
V_120 -> V_86 = V_87 -> V_89 . V_86 ;
V_120 -> V_109 = V_87 -> V_89 . V_109 ;
V_120 -> V_14 = V_87 -> V_89 . V_14 ;
V_120 -> V_110 = V_87 -> V_89 . V_110 ;
V_120 -> V_111 = V_87 -> V_89 . V_111 ;
V_120 -> V_112 = V_87 -> V_112 ;
V_75 = F_18 ( ( V_24 * ) V_120 + sizeof( * V_120 ) ,
& V_87 -> V_49 ) ;
if ( V_75 == V_41 )
V_75 = F_63 ( & V_120 -> V_97 ) ;
F_16 ( V_120 ) ;
return V_75 ;
}
static int F_64 ( struct V_85 V_86 )
{
struct V_125 V_126 ;
V_126 . V_97 . V_98 = F_54 ( V_100 ,
V_127 ) ;
V_126 . V_97 . V_28 = V_123 ;
V_126 . V_97 . V_102 = sizeof( V_86 ) ;
V_126 . V_86 = V_86 ;
return F_63 ( & V_126 . V_97 ) ;
}
static void F_65 ( struct V_84 * V_84 , struct V_83 * V_87 )
{
if ( V_87 )
F_66 ( & V_87 -> V_115 , & V_84 -> V_128 ) ;
}
static void F_67 ( struct V_84 * V_84 ,
struct V_83 * V_87 )
{
if ( V_87 )
F_68 ( & V_87 -> V_115 ) ;
}
static int F_69 ( struct V_85 V_86 )
{
int V_75 ;
struct V_88 * V_87 ;
T_2 V_114 = ~ 0 ;
F_30 ( & V_90 . V_22 ) ;
V_87 = F_49 ( V_86 ) ;
if ( ! V_87 ) {
F_32 ( & V_90 . V_22 ) ;
return V_129 ;
}
if ( V_87 -> V_89 . V_14 & V_130 ) {
V_75 = V_41 ;
if ( V_87 -> V_89 . V_114 > 1 ) {
V_75 = F_52 ( false , V_86 ) ;
}
} else {
V_75 = F_64 ( V_86 ) ;
if ( V_75 < V_41 ) {
F_32 ( & V_90 . V_22 ) ;
return V_75 ;
}
}
V_87 -> V_89 . V_114 -- ;
if ( V_87 -> V_89 . V_114 == 0 )
F_67 ( & V_90 , & V_87 -> V_89 ) ;
if ( V_87 )
V_114 = V_87 -> V_89 . V_114 ;
F_32 ( & V_90 . V_22 ) ;
if ( V_114 == 0 )
F_60 ( V_87 ) ;
return V_75 ;
}
static int F_70 ( struct V_85 * V_86 ,
struct V_3 * * V_52 ,
T_1 V_110 ,
struct V_3 * * V_53 ,
T_1 V_111 ,
T_2 V_109 ,
T_2 V_14 ,
T_2 V_131 )
{
const T_1 V_46 =
F_2 ( V_110 , V_6 ) + 1 ;
const T_1 V_48 =
F_2 ( V_111 , V_6 ) + 1 ;
void * V_132 = NULL ;
void * V_133 = NULL ;
int V_75 ;
struct V_88 * V_134 = NULL ;
if ( V_131 != V_135 )
return V_136 ;
F_30 ( & V_90 . V_22 ) ;
V_134 = F_49 ( * V_86 ) ;
if ( V_134 ) {
if ( V_134 -> V_89 . V_14 & V_130 ) {
if ( V_134 -> V_89 . V_114 > 1 ) {
F_71 ( L_5 ) ;
V_75 = V_78 ;
goto V_137;
}
if ( V_134 -> V_89 . V_110 != V_111 ||
V_134 -> V_89 . V_111 !=
V_110 ||
V_134 -> V_89 . V_14 !=
( V_14 & ~ V_138 ) ) {
F_71 ( L_6 ) ;
V_75 = V_77 ;
goto V_137;
}
V_75 = F_52 ( true , * V_86 ) ;
if ( V_75 < V_41 )
goto V_137;
V_132 = V_134 -> V_53 ;
V_133 = V_134 -> V_52 ;
goto V_72;
}
V_75 = V_55 ;
goto V_137;
}
V_132 = F_5 ( V_110 , V_14 ) ;
if ( ! V_132 ) {
F_38 ( L_7 ) ;
V_75 = V_56 ;
goto error;
}
V_133 = F_5 ( V_111 , V_14 ) ;
if ( ! V_133 ) {
F_38 ( L_8 ) ;
V_75 = V_56 ;
goto error;
}
V_134 = F_56 ( * V_86 , V_109 , V_14 ,
V_110 , V_111 ,
V_132 , V_133 ) ;
if ( ! V_134 ) {
F_38 ( L_9 , V_139 ) ;
V_75 = V_56 ;
goto error;
}
V_75 = F_14 ( V_132 , V_46 , V_133 ,
V_48 ,
& V_134 -> V_49 ) ;
if ( V_75 < V_41 ) {
F_38 ( L_10 ) ;
goto error;
}
if ( V_134 -> V_89 . V_14 & V_130 ) {
T_2 V_94 = F_53 () ;
if ( V_134 -> V_89 . V_86 . V_118 != V_94 ||
( V_134 -> V_89 . V_109 != V_113 &&
V_134 -> V_89 . V_109 != V_94 ) ) {
V_75 = V_136 ;
goto error;
}
if ( V_134 -> V_89 . V_14 & V_138 ) {
V_75 = V_129 ;
goto error;
}
} else {
V_75 = F_62 ( V_134 ) ;
if ( V_75 < V_41 ) {
F_38 ( L_11 , V_75 ) ;
goto error;
}
}
F_26 ( (struct V_3 * ) V_132 ,
(struct V_3 * ) V_133 ) ;
F_65 ( & V_90 , & V_134 -> V_89 ) ;
V_72:
V_134 -> V_89 . V_114 ++ ;
* V_86 = V_134 -> V_89 . V_86 ;
* V_52 = (struct V_3 * ) V_132 ;
* V_53 = (struct V_3 * ) V_133 ;
if ( ( V_134 -> V_89 . V_14 & V_130 ) &&
V_134 -> V_89 . V_114 == 1 ) {
F_72 ( ( * V_52 ) -> V_19 , * V_86 ) ;
F_72 ( ( * V_53 ) -> V_19 , * V_86 ) ;
}
F_32 ( & V_90 . V_22 ) ;
return V_41 ;
error:
F_32 ( & V_90 . V_22 ) ;
if ( V_134 ) {
F_60 ( V_134 ) ;
} else {
F_1 ( V_132 , V_110 ) ;
F_1 ( V_133 , V_111 ) ;
}
return V_75 ;
V_137:
F_32 ( & V_90 . V_22 ) ;
return V_75 ;
}
static int F_73 ( struct V_85 V_86 ,
T_2 V_109 ,
T_2 V_14 ,
T_2 V_131 ,
T_1 V_110 ,
T_1 V_111 ,
struct V_73 * V_74 ,
struct V_140 * V_118 ,
T_4 V_141 ,
void * V_142 , struct V_91 * * V_143 )
{
struct V_91 * V_87 = NULL ;
const T_2 V_94 = F_74 ( V_118 ) ;
bool V_144 = V_14 & V_130 ;
int V_75 ;
T_1 V_145 ;
T_1 V_146 ;
if ( V_14 & V_138 )
return V_129 ;
if ( V_86 . V_118 != V_94 && V_86 . V_118 != V_109 )
return V_136 ;
if ( F_75 ( V_94 ) && F_75 ( V_109 ) )
return V_147 ;
if ( V_144 && V_109 != V_113 && V_94 != V_109 )
return V_136 ;
V_87 = F_24 ( sizeof( * V_87 ) , V_148 ) ;
if ( ! V_87 )
return V_56 ;
if ( F_74 ( V_118 ) == V_149 && ! V_144 ) {
V_145 = V_111 ;
V_146 = V_110 ;
} else {
V_145 = V_110 ;
V_146 = V_111 ;
}
V_87 -> V_89 . V_86 = V_86 ;
V_87 -> V_89 . V_109 = V_109 ;
V_87 -> V_89 . V_14 = V_14 ;
V_87 -> V_89 . V_110 = V_145 ;
V_87 -> V_89 . V_111 = V_146 ;
V_87 -> V_89 . V_114 = 1 ;
V_87 -> V_150 = V_94 ;
V_87 -> V_151 = V_113 ;
V_87 -> V_152 = V_153 ;
V_87 -> V_154 =
! ! ( V_118 -> V_131 & V_155 ) ;
V_87 -> V_156 =
! ! ( V_131 & V_157 ) ;
V_87 -> V_158 = false ;
V_87 -> V_141 = V_141 ;
V_87 -> V_142 = V_142 ;
V_87 -> V_52 = F_23 ( V_145 ) ;
if ( V_87 -> V_52 == NULL ) {
V_75 = V_56 ;
goto error;
}
V_87 -> V_53 = F_23 ( V_146 ) ;
if ( V_87 -> V_53 == NULL ) {
V_75 = V_56 ;
goto error;
}
F_26 ( V_87 -> V_52 , V_87 -> V_53 ) ;
F_57 ( & V_87 -> V_89 . V_115 ) ;
if ( V_144 ) {
V_24 * V_159 ;
V_87 -> V_160 = F_76 ( F_77 ( V_87 -> V_89 ) ,
V_6 , V_26 ) ;
if ( V_87 -> V_160 == NULL ) {
V_75 = V_56 ;
goto error;
}
V_87 -> V_152 = V_161 ;
V_87 -> V_52 -> V_19 = V_87 -> V_160 ;
V_159 = ( V_24 * ) V_87 -> V_160 + V_6 *
( F_2 ( V_87 -> V_89 . V_110 , V_6 ) + 1 ) ;
V_87 -> V_53 -> V_19 = (struct V_81 * ) V_159 ;
} else if ( V_74 ) {
V_75 = F_39 ( V_74 ,
V_87 -> V_52 ,
V_87 -> V_53 ) ;
if ( V_75 < V_41 )
goto error;
V_87 -> V_152 = V_161 ;
} else {
V_87 -> V_152 = V_162 ;
}
F_65 ( & V_92 , & V_87 -> V_89 ) ;
if ( V_143 != NULL )
* V_143 = V_87 ;
V_75 = F_58 ( & V_87 -> V_116 ,
V_163 ,
V_86 ) ;
if ( V_75 != V_41 ) {
F_38 ( L_4 ,
V_86 . V_118 , V_86 . V_116 , V_75 ) ;
goto error;
}
V_87 -> V_89 . V_86 = F_59 ( & V_87 -> V_116 ) ;
if ( V_144 ) {
F_72 ( V_87 -> V_52 -> V_19 ,
V_87 -> V_89 . V_86 ) ;
F_72 ( V_87 -> V_53 -> V_19 ,
V_87 -> V_89 . V_86 ) ;
}
F_78 ( V_118 , V_87 -> V_89 . V_86 ) ;
return V_41 ;
error:
if ( V_87 != NULL ) {
F_25 ( V_87 -> V_52 , V_145 ) ;
F_25 ( V_87 -> V_53 , V_146 ) ;
F_16 ( V_87 ) ;
}
return V_75 ;
}
static int F_79 ( bool V_93 ,
struct V_85 V_86 ,
T_2 V_164 ,
T_2 V_108 )
{
int V_165 ;
struct V_95 V_96 ;
if ( F_46 ( V_86 ) || V_164 == V_113 ||
V_108 == V_113 )
return V_40 ;
V_96 . V_44 . V_97 . V_98 = F_54 ( V_108 , V_99 ) ;
V_96 . V_44 . V_97 . V_28 = F_54 ( V_100 ,
V_101 ) ;
V_96 . V_44 . V_97 . V_102 = sizeof( V_96 ) - sizeof( V_96 . V_44 . V_97 ) ;
V_96 . V_44 . V_103 . V_104 = V_93 ?
V_105 : V_106 ;
V_96 . V_107 . V_86 = V_86 ;
V_96 . V_107 . V_108 = V_164 ;
V_165 = F_80 ( V_100 ,
& V_96 . V_44 . V_97 , false ) ;
if ( V_165 < V_41 )
F_38 ( L_12 ,
V_93 ? L_13 : L_14 , V_108 ) ;
return V_165 ;
}
static int F_81 ( struct V_91 * V_87 ,
T_2 V_109 ,
T_2 V_14 ,
T_2 V_131 ,
T_1 V_110 ,
T_1 V_111 ,
struct V_73 * V_74 ,
struct V_140 * V_118 ,
T_4 V_141 ,
void * V_142 ,
struct V_91 * * V_143 )
{
const T_2 V_94 = F_74 ( V_118 ) ;
bool V_144 = V_14 & V_130 ;
int V_75 ;
if ( V_87 -> V_152 != V_162 &&
V_87 -> V_152 != V_161 )
return V_78 ;
if ( V_144 ) {
if ( ! ( V_87 -> V_89 . V_14 & V_130 ) ||
V_94 != V_87 -> V_150 ) {
return V_40 ;
}
} else if ( V_94 == V_87 -> V_150 ||
V_94 == V_87 -> V_151 ) {
return V_55 ;
}
if ( F_75 ( V_94 ) &&
F_75 ( V_87 -> V_150 ) )
return V_147 ;
if ( ( V_118 -> V_131 & V_155 ) &&
! V_87 -> V_156 )
return V_136 ;
if ( V_87 -> V_154 &&
( ! ( V_131 & V_157 ) ) )
return V_136 ;
if ( V_87 -> V_89 . V_109 != V_113 && V_87 -> V_89 . V_109 != V_94 )
return V_136 ;
if ( V_87 -> V_150 == V_149 ) {
if ( ! F_82 ( V_118 ) )
return V_166 ;
} else if ( V_94 == V_149 ) {
struct V_140 * V_167 ;
bool V_168 ;
V_167 = F_83 ( V_87 -> V_150 ) ;
V_168 = F_82 ( V_167 ) ;
F_84 ( V_167 ) ;
if ( ! V_168 )
return V_166 ;
}
if ( ( V_87 -> V_89 . V_14 & ~ V_169 ) != ( V_14 & ~ V_170 ) )
return V_77 ;
if ( V_94 != V_149 ) {
if ( V_87 -> V_89 . V_110 != V_110 ||
V_87 -> V_89 . V_111 != V_111 ) {
return V_77 ;
}
} else if ( V_87 -> V_89 . V_110 != V_111 ||
V_87 -> V_89 . V_111 != V_110 ) {
return V_77 ;
}
if ( V_94 != V_149 ) {
if ( V_87 -> V_152 != V_162 )
return V_40 ;
if ( V_74 != NULL ) {
V_75 = F_39 ( V_74 ,
V_87 -> V_52 ,
V_87 -> V_53 ) ;
if ( V_75 < V_41 )
return V_75 ;
V_87 -> V_152 = V_171 ;
} else {
V_87 -> V_152 = V_172 ;
}
} else if ( V_87 -> V_152 == V_162 ) {
return V_78 ;
} else {
V_87 -> V_152 = V_171 ;
}
if ( V_87 -> V_152 == V_171 ) {
V_75 =
F_79 ( true , V_87 -> V_89 . V_86 , V_94 ,
V_87 -> V_150 ) ;
if ( V_75 < V_41 )
F_38 ( L_15 ,
V_87 -> V_150 , V_87 -> V_89 . V_86 . V_118 ,
V_87 -> V_89 . V_86 . V_116 ) ;
}
V_87 -> V_151 = V_94 ;
V_87 -> V_89 . V_114 ++ ;
if ( V_141 ) {
V_87 -> V_141 = V_141 ;
V_87 -> V_142 = V_142 ;
}
if ( ! V_144 )
F_78 ( V_118 , V_87 -> V_89 . V_86 ) ;
if ( V_143 != NULL )
* V_143 = V_87 ;
return V_41 ;
}
static int F_85 ( struct V_85 V_86 ,
T_2 V_109 ,
T_2 V_14 ,
T_2 V_131 ,
T_1 V_110 ,
T_1 V_111 ,
struct V_73 * V_74 ,
struct V_140 * V_118 ,
T_4 V_141 ,
void * V_142 ,
struct V_91 * * V_143 ,
bool * V_173 )
{
const T_2 V_94 = F_74 ( V_118 ) ;
bool V_174 ;
struct V_91 * V_87 = NULL ;
bool V_144 = V_14 & V_130 ;
int V_75 ;
if ( F_46 ( V_86 ) ||
( V_14 & ~ V_175 ) || V_144 ||
! ( V_110 || V_111 ) ||
! V_118 || V_94 == V_113 ||
V_86 . V_118 == V_113 ) {
return V_40 ;
}
if ( V_74 && ! F_86 ( V_74 ) )
return V_40 ;
F_30 ( & V_92 . V_22 ) ;
if ( ! V_144 && F_87 ( V_118 , V_86 ) ) {
F_71 ( L_16 ,
V_94 , V_86 . V_118 , V_86 . V_116 ) ;
F_32 ( & V_92 . V_22 ) ;
return V_55 ;
}
if ( V_86 . V_116 != V_113 )
V_87 = F_51 ( V_86 ) ;
if ( ! V_87 ) {
V_174 = true ;
V_75 =
F_73 ( V_86 , V_109 , V_14 , V_131 ,
V_110 , V_111 , V_74 ,
V_118 , V_141 , V_142 , V_143 ) ;
} else {
V_174 = false ;
V_75 =
F_81 ( V_87 , V_109 , V_14 , V_131 ,
V_110 , V_111 , V_74 ,
V_118 , V_141 , V_142 , V_143 ) ;
}
F_32 ( & V_92 . V_22 ) ;
if ( V_173 )
* V_173 = ( V_94 == V_149 ) &&
! ( V_174 && V_144 ) ;
return V_75 ;
}
static int F_88 ( struct V_85 * V_86 ,
struct V_3 * * V_52 ,
T_1 V_110 ,
struct V_3 * * V_53 ,
T_1 V_111 ,
T_2 V_109 ,
T_2 V_14 ,
T_2 V_131 ,
T_4 V_141 ,
void * V_142 )
{
struct V_85 V_176 ;
struct V_140 * V_118 ;
struct V_91 * V_87 ;
int V_75 ;
bool V_173 ;
if ( F_46 ( * V_86 ) ) {
V_176 = F_54 (
V_149 , V_113 ) ;
} else
V_176 = * V_86 ;
V_118 = F_83 ( V_149 ) ;
V_87 = NULL ;
V_75 =
F_85 ( V_176 , V_109 , V_14 , V_131 ,
V_110 , V_111 , NULL , V_118 ,
V_141 , V_142 , & V_87 , & V_173 ) ;
if ( V_75 == V_41 ) {
if ( V_173 ) {
* V_52 = V_87 -> V_53 ;
* V_53 = V_87 -> V_52 ;
} else {
* V_52 = V_87 -> V_52 ;
* V_53 = V_87 -> V_53 ;
}
* V_86 = F_59 ( & V_87 -> V_116 ) ;
} else {
* V_86 = V_177 ;
F_71 ( L_17 ,
V_75 ) ;
}
F_84 ( V_118 ) ;
return V_75 ;
}
int F_89 ( struct V_85 * V_86 ,
struct V_3 * * V_52 ,
T_1 V_110 ,
struct V_3 * * V_53 ,
T_1 V_111 ,
T_2 V_109 ,
T_2 V_14 ,
T_2 V_131 ,
bool V_178 ,
T_4 V_141 ,
void * V_142 )
{
if ( ! V_86 || ! V_52 || ! V_53 ||
( ! V_110 && ! V_111 ) || ( V_14 & ~ V_175 ) )
return V_40 ;
if ( V_178 ) {
return F_70 ( V_86 , V_52 ,
V_110 , V_53 ,
V_111 , V_109 ,
V_14 , V_131 ) ;
} else {
return F_88 ( V_86 , V_52 ,
V_110 , V_53 ,
V_111 , V_109 , V_14 ,
V_131 , V_141 , V_142 ) ;
}
}
static int F_90 ( struct V_85 V_86 )
{
int V_75 ;
struct V_140 * V_118 ;
V_118 = F_83 ( V_149 ) ;
V_75 = F_91 ( V_86 , V_118 ) ;
F_84 ( V_118 ) ;
return V_75 ;
}
static int F_92 ( struct V_85 V_86 , bool V_178 )
{
if ( F_46 ( V_86 ) )
return V_40 ;
if ( V_178 )
return F_69 ( V_86 ) ;
else
return F_90 ( V_86 ) ;
}
static struct V_83 * F_93 ( struct V_84 * V_84 )
{
if ( ! F_94 ( & V_84 -> V_128 ) ) {
struct V_83 * V_87 =
F_95 ( & V_84 -> V_128 , struct V_83 ,
V_115 ) ;
return V_87 ;
}
return NULL ;
}
void F_96 ( void )
{
struct V_83 * V_87 ;
struct V_91 * V_179 ;
F_30 ( & V_92 . V_22 ) ;
while ( ( V_87 = F_93 ( & V_92 ) ) ) {
V_179 = (struct V_91 * ) V_87 ;
F_67 ( & V_92 , V_87 ) ;
F_16 ( V_179 ) ;
}
F_32 ( & V_92 . V_22 ) ;
}
int F_97 ( struct V_85 V_86 ,
T_2 V_109 ,
T_2 V_14 ,
T_2 V_131 ,
T_1 V_110 ,
T_1 V_111 ,
struct V_73 * V_74 ,
struct V_140 * V_118 )
{
return F_85 ( V_86 , V_109 , V_14 , V_131 ,
V_110 , V_111 ,
V_74 , V_118 , NULL , NULL , NULL , NULL ) ;
}
int F_98 ( struct V_85 V_86 ,
T_1 V_68 ,
T_1 V_69 ,
struct V_140 * V_118 )
{
struct V_91 * V_87 ;
int V_75 ;
const T_2 V_94 = F_74 ( V_118 ) ;
if ( F_46 ( V_86 ) || ! V_118 ||
V_94 == V_113 )
return V_40 ;
if ( V_68 == 0 || V_69 == 0 )
return V_40 ;
F_30 ( & V_92 . V_22 ) ;
if ( ! F_87 ( V_118 , V_86 ) ) {
F_38 ( L_18 ,
V_94 , V_86 . V_118 , V_86 . V_116 ) ;
V_75 = V_129 ;
goto V_72;
}
V_87 = F_51 ( V_86 ) ;
if ( ! V_87 ) {
V_75 = V_129 ;
goto V_72;
}
if ( V_87 -> V_150 != V_94 &&
( V_87 -> V_150 != V_149 ||
V_87 -> V_151 != V_94 ) ) {
V_75 = V_180 ;
goto V_72;
}
if ( V_87 -> V_152 != V_162 &&
V_87 -> V_152 != V_172 ) {
V_75 = V_78 ;
goto V_72;
}
V_75 = F_36 ( V_68 , V_69 ,
V_87 -> V_52 , V_87 -> V_53 ) ;
if ( V_75 < V_41 )
goto V_72;
V_75 = F_41 ( V_87 -> V_52 , V_87 -> V_53 ) ;
if ( V_75 < V_41 ) {
F_40 ( V_87 -> V_52 ,
V_87 -> V_53 ) ;
goto V_72;
}
if ( V_87 -> V_152 == V_162 )
V_87 -> V_152 = V_161 ;
else
V_87 -> V_152 = V_171 ;
V_87 -> V_158 = true ;
if ( V_87 -> V_152 == V_171 ) {
V_75 =
F_79 ( true , V_86 , V_94 , V_87 -> V_150 ) ;
if ( V_75 < V_41 ) {
F_38 ( L_15 ,
V_87 -> V_150 , V_87 -> V_89 . V_86 . V_118 ,
V_87 -> V_89 . V_86 . V_116 ) ;
}
}
V_75 = V_41 ;
V_72:
F_32 ( & V_92 . V_22 ) ;
return V_75 ;
}
static void F_99 ( struct V_91 * V_87 )
{
V_87 -> V_52 -> V_20 = NULL ;
V_87 -> V_53 -> V_20 = NULL ;
}
int F_91 ( struct V_85 V_86 , struct V_140 * V_118 )
{
struct V_91 * V_87 ;
const T_2 V_94 = F_74 ( V_118 ) ;
T_2 V_108 ;
bool V_144 = false ;
int V_75 ;
if ( F_46 ( V_86 ) || ! V_118 ||
V_94 == V_113 ) {
return V_40 ;
}
F_30 ( & V_92 . V_22 ) ;
if ( ! F_87 ( V_118 , V_86 ) ) {
F_71 ( L_18 ,
V_94 , V_86 . V_118 , V_86 . V_116 ) ;
V_75 = V_129 ;
goto V_72;
}
V_87 = F_51 ( V_86 ) ;
if ( ! V_87 ) {
F_71 ( L_19 ,
V_94 , V_86 . V_118 , V_86 . V_116 ) ;
V_75 = V_129 ;
goto V_72;
}
if ( V_94 != V_87 -> V_150 && V_94 != V_87 -> V_151 ) {
V_75 = V_181 ;
goto V_72;
}
if ( V_94 == V_87 -> V_150 ) {
V_108 = V_87 -> V_151 ;
V_87 -> V_150 = V_113 ;
} else {
V_108 = V_87 -> V_150 ;
V_87 -> V_151 = V_113 ;
}
V_87 -> V_89 . V_114 -- ;
V_144 = V_87 -> V_89 . V_14 & V_130 ;
if ( V_94 != V_149 ) {
bool V_182 ;
F_29 ( V_87 -> V_52 ) ;
V_182 = V_87 -> V_52 -> V_19 ||
V_87 -> V_53 -> V_19 ;
if ( F_100 ( V_87 ) ) {
V_75 =
F_43 ( V_183 ,
V_87 -> V_52 ,
V_87 -> V_53 ) ;
if ( V_75 < V_41 )
F_38 ( L_20 ,
V_86 . V_118 , V_86 . V_116 ,
V_75 ) ;
if ( V_87 -> V_158 )
F_40 ( V_87 -> V_52 ,
V_87 ->
V_53 ) ;
else
F_40 ( V_87 -> V_52 ,
V_87 ->
V_53 ) ;
}
if ( ! V_182 )
F_99 ( V_87 ) ;
F_31 ( V_87 -> V_52 ) ;
if ( ! V_182 && V_87 -> V_141 )
V_87 -> V_141 ( V_87 -> V_142 ) ;
} else {
if ( V_87 -> V_141 ) {
V_87 -> V_141 = NULL ;
V_87 -> V_142 = NULL ;
}
}
if ( V_87 -> V_89 . V_114 == 0 ) {
F_67 ( & V_92 , & V_87 -> V_89 ) ;
if ( V_144 )
F_16 ( V_87 -> V_160 ) ;
F_28 ( V_87 -> V_52 , V_87 -> V_53 ) ;
F_25 ( V_87 -> V_52 , V_87 -> V_89 . V_110 ) ;
F_25 ( V_87 -> V_53 , V_87 -> V_89 . V_111 ) ;
F_61 ( & V_87 -> V_116 ) ;
F_16 ( V_87 ) ;
F_101 ( V_118 , V_86 ) ;
} else {
F_79 ( false , V_86 , V_94 , V_108 ) ;
if ( V_94 == V_149 &&
F_100 ( V_87 ) ) {
V_87 -> V_152 = V_184 ;
} else {
V_87 -> V_152 = V_185 ;
}
if ( ! V_144 )
F_101 ( V_118 , V_86 ) ;
}
V_75 = V_41 ;
V_72:
F_32 ( & V_92 . V_22 ) ;
return V_75 ;
}
int F_102 ( struct V_85 V_86 ,
struct V_140 * V_118 ,
T_1 V_186 )
{
struct V_91 * V_87 ;
const T_2 V_94 = F_74 ( V_118 ) ;
bool V_144 = false ;
int V_75 ;
if ( F_46 ( V_86 ) || ! V_118 ||
V_94 == V_113 )
return V_40 ;
F_30 ( & V_92 . V_22 ) ;
if ( ! F_87 ( V_118 , V_86 ) ) {
F_71 ( L_18 ,
V_94 , V_86 . V_118 , V_86 . V_116 ) ;
V_75 = V_129 ;
goto V_72;
}
V_87 = F_51 ( V_86 ) ;
if ( ! V_87 ) {
F_71 ( L_21 ,
V_94 , V_86 . V_118 , V_86 . V_116 ) ;
V_75 = V_129 ;
goto V_72;
}
if ( V_94 != V_87 -> V_150 && V_94 != V_87 -> V_151 ) {
V_75 = V_181 ;
goto V_72;
}
V_144 = V_87 -> V_89 . V_14 & V_130 ;
V_75 = V_41 ;
if ( V_94 != V_149 ) {
struct V_73 V_74 ;
V_74 . V_66 = V_186 ;
V_74 . V_187 = F_77 ( V_87 -> V_89 ) ;
F_29 ( V_87 -> V_52 ) ;
F_99 ( V_87 ) ;
V_75 =
F_39 ( & V_74 ,
V_87 -> V_52 ,
V_87 -> V_53 ) ;
F_31 ( V_87 -> V_52 ) ;
if ( V_75 == V_41 ) {
V_87 -> V_152 ++ ;
if ( V_87 -> V_141 )
V_87 -> V_141 ( V_87 -> V_142 ) ;
}
}
V_72:
F_32 ( & V_92 . V_22 ) ;
return V_75 ;
}
static int F_103 ( struct V_91 * V_87 )
{
int V_75 ;
if ( V_87 -> V_52 -> V_20 != NULL &&
V_87 -> V_53 -> V_20 != NULL ) {
return V_41 ;
}
if ( NULL == V_87 -> V_52 -> V_19 ||
NULL == V_87 -> V_53 -> V_19 ) {
V_75 = F_41 ( V_87 -> V_52 , V_87 -> V_53 ) ;
if ( V_75 < V_41 )
return V_75 ;
}
memcpy ( & V_87 -> V_188 , V_87 -> V_52 -> V_19 ,
sizeof( V_87 -> V_188 ) ) ;
V_87 -> V_52 -> V_20 = & V_87 -> V_188 ;
memcpy ( & V_87 -> V_189 , V_87 -> V_53 -> V_19 ,
sizeof( V_87 -> V_189 ) ) ;
V_87 -> V_53 -> V_20 = & V_87 -> V_189 ;
return V_41 ;
}
int F_104 ( struct V_85 V_86 ,
struct V_140 * V_118 ,
T_2 V_82 )
{
struct V_91 * V_87 ;
const T_2 V_94 = F_74 ( V_118 ) ;
bool V_144 = false ;
int V_75 ;
if ( F_46 ( V_86 ) || ! V_118 ||
V_94 == V_113 )
return V_40 ;
F_30 ( & V_92 . V_22 ) ;
if ( ! F_87 ( V_118 , V_86 ) ) {
F_71 ( L_18 ,
V_94 , V_86 . V_118 , V_86 . V_116 ) ;
V_75 = V_129 ;
goto V_72;
}
V_87 = F_51 ( V_86 ) ;
if ( ! V_87 ) {
F_71 ( L_21 ,
V_94 , V_86 . V_118 , V_86 . V_116 ) ;
V_75 = V_129 ;
goto V_72;
}
if ( V_94 != V_87 -> V_150 && V_94 != V_87 -> V_151 ) {
V_75 = V_181 ;
goto V_72;
}
V_144 = V_87 -> V_89 . V_14 & V_130 ;
if ( V_94 != V_149 ) {
F_29 ( V_87 -> V_52 ) ;
V_75 = F_103 ( V_87 ) ;
if ( V_75 < V_41 )
F_38 ( L_22 ,
V_86 . V_118 , V_86 . V_116 , V_75 ) ;
F_43 ( V_82 , V_87 -> V_52 , V_87 -> V_53 ) ;
F_40 ( V_87 -> V_52 ,
V_87 -> V_53 ) ;
V_87 -> V_152 -- ;
F_31 ( V_87 -> V_52 ) ;
}
V_75 = V_41 ;
V_72:
F_32 ( & V_92 . V_22 ) ;
return V_75 ;
}
void F_105 ( void )
{
struct V_83 * V_87 ;
struct V_88 * V_190 ;
F_30 ( & V_90 . V_22 ) ;
while ( ( V_87 = F_93 ( & V_90 ) ) ) {
V_190 = (struct V_88 * ) V_87 ;
if ( ! ( V_87 -> V_14 & V_130 ) )
F_64 ( V_87 -> V_86 ) ;
V_87 -> V_114 = 0 ;
F_67 ( & V_90 , V_87 ) ;
F_60 ( V_190 ) ;
}
F_32 ( & V_90 . V_22 ) ;
}
static void F_106 ( const struct V_191 * V_192 )
{
F_29 ( V_192 -> V_52 ) ;
}
static void F_107 ( const struct V_191 * V_192 )
{
F_31 ( V_192 -> V_52 ) ;
}
static int F_108 ( struct V_3 * V_52 ,
struct V_3 * V_53 )
{
int V_75 ;
if ( NULL == V_52 -> V_19 || NULL == V_53 -> V_19 ) {
V_75 = F_41 ( V_52 , V_53 ) ;
if ( V_75 < V_41 )
return ( V_52 -> V_20 &&
V_53 -> V_20 ) ?
V_193 :
V_181 ;
}
return V_41 ;
}
static int F_109 ( const struct V_191 * V_192 ,
struct V_81 * * V_194 ,
struct V_81 * * V_195 )
{
int V_75 ;
V_75 = F_108 ( V_192 -> V_52 , V_192 -> V_53 ) ;
if ( V_75 == V_41 ) {
* V_194 = V_192 -> V_52 -> V_19 ;
* V_195 = V_192 -> V_53 -> V_19 ;
} else if ( V_192 -> V_52 -> V_20 &&
V_192 -> V_53 -> V_20 ) {
* V_194 = V_192 -> V_52 -> V_20 ;
* V_195 = V_192 -> V_53 -> V_20 ;
V_75 = V_41 ;
}
return V_75 ;
}
static int F_110 ( void * V_142 )
{
struct V_191 * V_192 = (struct V_191 * ) V_142 ;
F_106 ( V_192 ) ;
while ( V_192 -> V_196 > 0 ) {
V_192 -> V_196 -- ;
V_192 -> V_197 ++ ;
F_111 ( & V_192 -> V_104 ) ;
}
F_107 ( V_192 ) ;
return V_41 ;
}
static bool F_112 ( struct V_191 * V_192 )
{
unsigned int V_197 ;
V_192 -> V_196 ++ ;
V_197 = V_192 -> V_197 ;
F_107 ( V_192 ) ;
F_113 ( V_192 -> V_104 , V_197 != V_192 -> V_197 ) ;
F_106 ( V_192 ) ;
return true ;
}
static T_5 F_114 ( struct V_3 * V_52 ,
struct V_3 * V_53 ,
const T_1 V_198 ,
const void * V_199 ,
T_3 V_200 ,
T_6 V_201 )
{
T_7 V_202 ;
T_1 V_203 ;
T_3 V_204 ;
T_5 V_75 ;
V_75 = F_108 ( V_52 , V_53 ) ;
if ( F_115 ( V_75 != V_41 ) )
return V_75 ;
V_202 = F_116 ( V_52 -> V_19 ,
V_53 -> V_19 ,
V_198 ) ;
if ( V_202 == 0 )
return V_205 ;
if ( V_202 < V_41 )
return ( T_5 ) V_202 ;
V_204 = ( T_3 ) ( V_202 > V_200 ? V_200 : V_202 ) ;
V_203 = F_117 ( V_52 -> V_19 ) ;
if ( F_118 ( V_203 + V_204 < V_198 ) ) {
V_75 = V_201 ( V_52 , V_203 , V_199 , 0 , V_204 ) ;
} else {
const T_3 V_159 = ( T_3 ) ( V_198 - V_203 ) ;
V_75 = V_201 ( V_52 , V_203 , V_199 , 0 , V_159 ) ;
if ( V_75 >= V_41 )
V_75 = V_201 ( V_52 , 0 , V_199 , V_159 ,
V_204 - V_159 ) ;
}
if ( V_75 < V_41 )
return V_75 ;
F_119 ( V_52 -> V_19 , V_204 ,
V_198 ) ;
return V_204 ;
}
static T_5 F_120 ( struct V_3 * V_52 ,
struct V_3 * V_53 ,
const T_1 V_206 ,
void * V_199 ,
T_3 V_200 ,
T_8 V_207 ,
bool V_208 )
{
T_7 V_209 ;
T_1 V_128 ;
T_3 V_210 ;
T_5 V_75 ;
V_75 = F_108 ( V_52 , V_53 ) ;
if ( F_115 ( V_75 != V_41 ) )
return V_75 ;
V_209 = F_121 ( V_53 -> V_19 ,
V_52 -> V_19 ,
V_206 ) ;
if ( V_209 == 0 )
return V_211 ;
if ( V_209 < V_41 )
return ( T_5 ) V_209 ;
V_210 = ( T_3 ) ( V_209 > V_200 ? V_200 : V_209 ) ;
V_128 = F_122 ( V_52 -> V_19 ) ;
if ( F_118 ( V_128 + V_210 < V_206 ) ) {
V_75 = V_207 ( V_199 , 0 , V_53 , V_128 , V_210 ) ;
} else {
const T_3 V_159 = ( T_3 ) ( V_206 - V_128 ) ;
V_75 = V_207 ( V_199 , 0 , V_53 , V_128 , V_159 ) ;
if ( V_75 >= V_41 )
V_75 = V_207 ( V_199 , V_159 , V_53 , 0 ,
V_210 - V_159 ) ;
}
if ( V_75 < V_41 )
return V_75 ;
if ( V_208 )
F_123 ( V_52 -> V_19 ,
V_210 , V_206 ) ;
return V_210 ;
}
int F_124 ( struct V_191 * * V_192 ,
struct V_85 * V_86 ,
T_1 V_212 ,
T_1 V_213 ,
T_2 V_109 ,
T_2 V_14 ,
T_2 V_131 )
{
struct V_191 * V_214 ;
int V_70 ;
struct V_85 V_28 = V_177 ;
struct V_85 V_98 = F_54 ( V_109 , V_113 ) ;
enum V_215 V_216 ;
T_4 V_141 ;
void * V_142 ;
if ( V_212 + V_213 < V_217 ( V_212, V_213 ) ||
V_212 + V_213 > V_218 )
return V_219 ;
V_70 = V_215 ( & V_28 , & V_98 , false , & V_216 ) ;
if ( V_70 < V_41 )
V_216 = F_125 () ?
V_220 : V_221 ;
if ( V_14 & ( V_222 | V_223 ) ) {
F_71 ( L_23 ) ;
return V_40 ;
}
V_214 = F_24 ( sizeof( * V_214 ) , V_26 ) ;
if ( ! V_214 )
return V_56 ;
V_214 -> V_198 = V_212 ;
V_214 -> V_206 = V_213 ;
V_214 -> V_109 = V_109 ;
V_214 -> V_14 = V_14 ;
V_214 -> V_131 = V_131 ;
V_141 = NULL ;
V_142 = NULL ;
if ( V_221 == V_216 ) {
V_214 -> V_178 = false ;
if ( ! ( V_14 & V_130 ) ) {
V_214 -> V_196 = 0 ;
V_214 -> V_197 = 0 ;
F_126 ( & V_214 -> V_104 ) ;
V_141 = F_110 ;
V_142 = ( void * ) V_214 ;
}
} else {
V_214 -> V_178 = true ;
}
V_70 = F_89 ( V_86 ,
& V_214 -> V_52 ,
V_214 -> V_198 ,
& V_214 -> V_53 ,
V_214 -> V_206 ,
V_214 -> V_109 ,
V_214 -> V_14 ,
V_214 -> V_131 ,
V_214 -> V_178 ,
V_141 , V_142 ) ;
if ( V_70 < V_41 ) {
F_16 ( V_214 ) ;
return V_70 ;
}
* V_192 = V_214 ;
V_214 -> V_86 = * V_86 ;
return V_70 ;
}
int F_127 ( struct V_191 * * V_192 )
{
int V_75 ;
struct V_191 * V_224 ;
if ( ! V_192 || ! ( * V_192 ) )
return V_40 ;
V_224 = * V_192 ;
V_75 = F_92 ( V_224 -> V_86 , V_224 -> V_178 ) ;
memset ( V_224 , 0 , sizeof( * V_224 ) ) ;
V_224 -> V_86 = V_177 ;
V_224 -> V_109 = V_113 ;
F_16 ( V_224 ) ;
* V_192 = NULL ;
return V_75 ;
}
int F_128 ( const struct V_191 * V_192 ,
T_1 * V_225 ,
T_1 * V_226 )
{
struct V_81 * V_194 ;
struct V_81 * V_195 ;
int V_75 ;
if ( ! V_192 )
return V_40 ;
F_106 ( V_192 ) ;
V_75 =
F_109 ( V_192 , & V_194 , & V_195 ) ;
if ( V_75 == V_41 )
F_129 ( V_194 , V_195 ,
V_225 , V_226 ) ;
F_107 ( V_192 ) ;
if ( V_75 == V_41 &&
( ( V_225 && * V_225 >= V_192 -> V_198 ) ||
( V_226 && * V_226 >= V_192 -> V_198 ) ) )
return V_227 ;
return V_75 ;
}
int F_130 ( const struct V_191 * V_192 ,
T_1 * V_228 ,
T_1 * V_229 )
{
struct V_81 * V_194 ;
struct V_81 * V_195 ;
int V_75 ;
if ( ! V_192 )
return V_40 ;
F_106 ( V_192 ) ;
V_75 =
F_109 ( V_192 , & V_194 , & V_195 ) ;
if ( V_75 == V_41 )
F_129 ( V_195 , V_194 ,
V_228 , V_229 ) ;
F_107 ( V_192 ) ;
if ( V_75 == V_41 &&
( ( V_228 && * V_228 >= V_192 -> V_206 ) ||
( V_229 && * V_229 >= V_192 -> V_206 ) ) )
return V_227 ;
return V_75 ;
}
T_7 F_131 ( const struct V_191 * V_192 )
{
struct V_81 * V_194 ;
struct V_81 * V_195 ;
T_7 V_75 ;
if ( ! V_192 )
return V_40 ;
F_106 ( V_192 ) ;
V_75 =
F_109 ( V_192 , & V_194 , & V_195 ) ;
if ( V_75 == V_41 )
V_75 = F_116 ( V_194 ,
V_195 ,
V_192 -> V_198 ) ;
else
V_75 = 0 ;
F_107 ( V_192 ) ;
return V_75 ;
}
T_7 F_132 ( const struct V_191 * V_192 )
{
struct V_81 * V_194 ;
struct V_81 * V_195 ;
T_7 V_75 ;
if ( ! V_192 )
return V_40 ;
F_106 ( V_192 ) ;
V_75 =
F_109 ( V_192 , & V_194 , & V_195 ) ;
if ( V_75 == V_41 )
V_75 = F_116 ( V_195 ,
V_194 ,
V_192 -> V_206 ) ;
else
V_75 = 0 ;
F_107 ( V_192 ) ;
return V_75 ;
}
T_7 F_133 ( const struct V_191 * V_192 )
{
struct V_81 * V_194 ;
struct V_81 * V_195 ;
T_7 V_75 ;
if ( ! V_192 )
return V_40 ;
F_106 ( V_192 ) ;
V_75 =
F_109 ( V_192 , & V_194 , & V_195 ) ;
if ( V_75 == V_41 )
V_75 = F_121 ( V_194 ,
V_195 ,
V_192 -> V_198 ) ;
else
V_75 = 0 ;
F_107 ( V_192 ) ;
return V_75 ;
}
T_7 F_134 ( const struct V_191 * V_192 )
{
struct V_81 * V_194 ;
struct V_81 * V_195 ;
T_7 V_75 ;
if ( ! V_192 )
return V_40 ;
F_106 ( V_192 ) ;
V_75 =
F_109 ( V_192 , & V_194 , & V_195 ) ;
if ( V_75 == V_41 )
V_75 = F_121 ( V_195 ,
V_194 ,
V_192 -> V_206 ) ;
else
V_75 = 0 ;
F_107 ( V_192 ) ;
return V_75 ;
}
T_5 F_135 ( struct V_191 * V_192 ,
const void * V_199 ,
T_3 V_200 ,
int V_230 )
{
T_5 V_75 ;
if ( ! V_192 || ! V_199 )
return V_40 ;
F_106 ( V_192 ) ;
do {
V_75 = F_114 ( V_192 -> V_52 ,
V_192 -> V_53 ,
V_192 -> V_198 ,
V_199 , V_200 ,
F_19 ) ;
if ( V_75 == V_193 &&
! F_112 ( V_192 ) )
V_75 = V_231 ;
} while ( V_75 == V_193 );
F_107 ( V_192 ) ;
return V_75 ;
}
T_5 F_136 ( struct V_191 * V_192 ,
void * V_199 ,
T_3 V_200 ,
int V_230 )
{
T_5 V_75 ;
if ( ! V_192 || ! V_199 )
return V_40 ;
F_106 ( V_192 ) ;
do {
V_75 = F_120 ( V_192 -> V_52 ,
V_192 -> V_53 ,
V_192 -> V_206 ,
V_199 , V_200 ,
F_20 , true ) ;
if ( V_75 == V_193 &&
! F_112 ( V_192 ) )
V_75 = V_231 ;
} while ( V_75 == V_193 );
F_107 ( V_192 ) ;
return V_75 ;
}
T_5 F_137 ( struct V_191 * V_192 ,
void * V_199 ,
T_3 V_200 ,
int V_230 )
{
T_5 V_75 ;
if ( ! V_192 || ! V_199 )
return V_40 ;
F_106 ( V_192 ) ;
do {
V_75 = F_120 ( V_192 -> V_52 ,
V_192 -> V_53 ,
V_192 -> V_206 ,
V_199 , V_200 ,
F_20 , false ) ;
if ( V_75 == V_193 &&
! F_112 ( V_192 ) )
V_75 = V_231 ;
} while ( V_75 == V_193 );
F_107 ( V_192 ) ;
return V_75 ;
}
T_5 F_138 ( struct V_191 * V_192 ,
void * V_38 ,
T_3 V_232 ,
int V_230 )
{
T_5 V_75 ;
if ( ! V_192 || ! V_38 )
return V_40 ;
F_106 ( V_192 ) ;
do {
V_75 = F_114 ( V_192 -> V_52 ,
V_192 -> V_53 ,
V_192 -> V_198 ,
V_38 , V_232 ,
F_21 ) ;
if ( V_75 == V_193 &&
! F_112 ( V_192 ) )
V_75 = V_231 ;
} while ( V_75 == V_193 );
F_107 ( V_192 ) ;
return V_75 ;
}
T_5 F_139 ( struct V_191 * V_192 ,
struct V_43 * V_44 ,
T_3 V_232 ,
int V_230 )
{
T_5 V_75 ;
if ( ! V_192 )
return V_40 ;
F_106 ( V_192 ) ;
do {
V_75 = F_120 ( V_192 -> V_52 ,
V_192 -> V_53 ,
V_192 -> V_206 ,
V_44 , V_232 ,
F_22 ,
true ) ;
if ( V_75 == V_193 &&
! F_112 ( V_192 ) )
V_75 = V_231 ;
} while ( V_75 == V_193 );
F_107 ( V_192 ) ;
return V_75 ;
}
T_5 F_140 ( struct V_191 * V_192 ,
struct V_43 * V_44 ,
T_3 V_232 ,
int V_230 )
{
T_5 V_75 ;
if ( ! V_192 )
return V_40 ;
F_106 ( V_192 ) ;
do {
V_75 = F_120 ( V_192 -> V_52 ,
V_192 -> V_53 ,
V_192 -> V_206 ,
V_44 , V_232 ,
F_22 ,
false ) ;
if ( V_75 == V_193 &&
! F_112 ( V_192 ) )
V_75 = V_231 ;
} while ( V_75 == V_193 );
F_107 ( V_192 ) ;
return V_75 ;
}
