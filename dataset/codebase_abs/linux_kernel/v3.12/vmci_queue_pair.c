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
struct V_37 * V_38 = (struct V_37 * ) V_42 ;
int V_39 ;
V_39 = F_13 ( V_38 , ( V_24 * ) V_33 + V_32 ,
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
static int F_14 ( void * V_43 ,
T_1 V_44 ,
void * V_45 ,
T_1 V_46 , struct V_47 * V_47 )
{
T_2 * V_48 ;
T_2 * V_49 ;
struct V_3 * V_50 = V_43 ;
struct V_3 * V_51 = V_45 ;
T_1 V_5 ;
if ( ! V_50 || ! V_44 || ! V_51 ||
! V_46 || ! V_47 )
return V_40 ;
if ( V_47 -> V_52 )
return V_53 ;
V_48 =
F_15 ( V_44 * sizeof( * V_48 ) , V_26 ) ;
if ( ! V_48 )
return V_54 ;
V_49 =
F_15 ( V_46 * sizeof( * V_49 ) , V_26 ) ;
if ( ! V_49 ) {
F_16 ( V_48 ) ;
return V_54 ;
}
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ ) {
unsigned long V_55 ;
V_48 [ V_5 ] =
V_50 -> V_9 -> V_10 . V_11 . V_13 [ V_5 ] >> V_56 ;
V_55 = V_48 [ V_5 ] ;
if ( sizeof( V_55 ) > sizeof( * V_48 )
&& V_55 != V_48 [ V_5 ] )
goto V_57;
}
for ( V_5 = 0 ; V_5 < V_46 ; V_5 ++ ) {
unsigned long V_55 ;
V_49 [ V_5 ] =
V_51 -> V_9 -> V_10 . V_11 . V_13 [ V_5 ] >> V_56 ;
V_55 = V_49 [ V_5 ] ;
if ( sizeof( V_55 ) > sizeof( * V_49 )
&& V_55 != V_49 [ V_5 ] )
goto V_57;
}
V_47 -> V_44 = V_44 ;
V_47 -> V_46 = V_46 ;
V_47 -> V_48 = V_48 ;
V_47 -> V_49 = V_49 ;
V_47 -> V_52 = true ;
return V_41 ;
V_57:
F_16 ( V_48 ) ;
F_16 ( V_49 ) ;
return V_40 ;
}
static void F_17 ( struct V_47 * V_47 )
{
if ( V_47 -> V_52 ) {
F_16 ( V_47 -> V_48 ) ;
F_16 ( V_47 -> V_49 ) ;
}
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
}
static int F_18 ( V_24 * V_58 , const struct V_47 * V_47 )
{
memcpy ( V_58 , V_47 -> V_48 ,
V_47 -> V_44 * sizeof( * V_47 -> V_48 ) ) ;
memcpy ( V_58 +
V_47 -> V_44 * sizeof( * V_47 -> V_48 ) ,
V_47 -> V_49 ,
V_47 -> V_46 * sizeof( * V_47 -> V_49 ) ) ;
return V_41 ;
}
static int F_19 ( struct V_3 * V_4 ,
T_1 V_27 ,
const void * V_28 , T_3 V_59 , T_3 V_2 )
{
return F_8 ( V_4 , V_27 ,
( V_24 * ) V_28 + V_59 , V_2 , false ) ;
}
static int F_20 ( void * V_42 ,
T_3 V_60 ,
const struct V_3 * V_4 ,
T_1 V_27 , T_3 V_2 )
{
return F_12 ( ( V_24 * ) V_42 + V_60 ,
V_4 , V_27 , V_2 , false ) ;
}
static int F_21 ( struct V_3 * V_4 ,
T_1 V_27 ,
const void * V_28 ,
T_3 V_59 , T_3 V_2 )
{
return F_8 ( V_4 , V_27 , V_28 , V_2 , true ) ;
}
static int F_22 ( void * V_42 ,
T_3 V_60 ,
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
const T_3 V_61 =
V_15 * sizeof( * V_4 -> V_9 -> V_10 . V_35 . V_36 ) ;
V_4 = F_24 ( V_18 + V_61 , V_26 ) ;
if ( V_4 ) {
V_4 -> V_19 = NULL ;
V_4 -> V_20 = NULL ;
V_4 -> V_9 = (struct V_21 * ) ( V_4 + 1 ) ;
V_4 -> V_9 -> V_25 = true ;
V_4 -> V_9 -> V_22 = NULL ;
V_4 -> V_9 -> V_15 = V_15 ;
V_4 -> V_9 -> V_10 . V_35 . V_62 =
(struct V_36 * * ) ( ( V_24 * ) V_4 + V_18 ) ;
V_4 -> V_9 -> V_10 . V_35 . V_36 =
& V_4 -> V_9 -> V_10 . V_35 . V_62 [ 1 ] ;
}
return V_4 ;
}
static void F_25 ( struct V_3 * V_4 , T_1 V_18 )
{
F_16 ( V_4 ) ;
}
static void F_26 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
if ( V_50 -> V_9 -> V_25 ) {
V_50 -> V_9 -> V_22 = & V_50 -> V_9 -> V_63 ;
V_51 -> V_9 -> V_22 = & V_50 -> V_9 -> V_63 ;
F_27 ( V_50 -> V_9 -> V_22 ) ;
}
}
static void F_28 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
if ( V_50 -> V_9 -> V_25 ) {
V_50 -> V_9 -> V_22 = NULL ;
V_51 -> V_9 -> V_22 = NULL ;
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
static void F_33 ( struct V_36 * * V_64 ,
T_1 V_15 , bool V_65 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
if ( V_65 )
F_34 ( V_64 [ V_5 ] ) ;
F_35 ( V_64 [ V_5 ] ) ;
V_64 [ V_5 ] = NULL ;
}
}
static int F_36 ( T_1 V_66 ,
T_1 V_67 ,
struct V_3 * V_50 ,
struct V_3 * V_51 )
{
int V_68 ;
int V_39 = V_41 ;
F_37 ( & V_69 -> V_70 -> V_71 ) ;
V_68 = F_38 ( V_69 ,
V_69 -> V_70 ,
( V_72 ) V_66 ,
V_50 -> V_9 -> V_15 ,
1 , 0 ,
V_50 -> V_9 -> V_10 . V_35 . V_62 , NULL ) ;
if ( V_68 < V_50 -> V_9 -> V_15 ) {
F_39 ( L_1 , V_68 ) ;
F_33 ( V_50 -> V_9 -> V_10 . V_35 . V_62 ,
V_68 , false ) ;
V_39 = V_54 ;
goto V_73;
}
V_68 = F_38 ( V_69 ,
V_69 -> V_70 ,
( V_72 ) V_67 ,
V_51 -> V_9 -> V_15 ,
1 , 0 ,
V_51 -> V_9 -> V_10 . V_35 . V_62 , NULL ) ;
if ( V_68 < V_51 -> V_9 -> V_15 ) {
F_39 ( L_2 , V_68 ) ;
F_33 ( V_51 -> V_9 -> V_10 . V_35 . V_62 ,
V_68 , false ) ;
F_33 ( V_50 -> V_9 -> V_10 . V_35 . V_62 ,
V_50 -> V_9 -> V_15 , false ) ;
V_39 = V_54 ;
}
V_73:
F_40 ( & V_69 -> V_70 -> V_71 ) ;
return V_39 ;
}
static int F_41 ( struct V_74 * V_75 ,
struct V_3 * V_50 ,
struct V_3 * V_51 )
{
T_1 V_66 ;
T_1 V_67 ;
V_66 = V_75 -> V_64 ;
V_67 = V_75 -> V_64 +
V_50 -> V_9 -> V_15 * V_6 ;
return F_36 ( V_66 , V_67 , V_50 ,
V_51 ) ;
}
static void F_42 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
F_33 ( V_50 -> V_9 -> V_10 . V_35 . V_62 ,
V_50 -> V_9 -> V_15 , true ) ;
memset ( V_50 -> V_9 -> V_10 . V_35 . V_62 , 0 ,
sizeof( * V_50 -> V_9 -> V_10 . V_35 . V_62 ) *
V_50 -> V_9 -> V_15 ) ;
F_33 ( V_51 -> V_9 -> V_10 . V_35 . V_62 ,
V_51 -> V_9 -> V_15 , true ) ;
memset ( V_51 -> V_9 -> V_10 . V_35 . V_62 , 0 ,
sizeof( * V_51 -> V_9 -> V_10 . V_35 . V_62 ) *
V_51 -> V_9 -> V_15 ) ;
}
static int F_43 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
int V_76 ;
if ( ! V_50 -> V_19 || ! V_51 -> V_19 ) {
struct V_36 * V_77 [ 2 ] ;
if ( V_50 -> V_19 != V_51 -> V_19 )
return V_78 ;
if ( V_50 -> V_9 -> V_10 . V_35 . V_62 == NULL ||
* V_50 -> V_9 -> V_10 . V_35 . V_62 == NULL )
return V_79 ;
V_77 [ 0 ] = * V_50 -> V_9 -> V_10 . V_35 . V_62 ;
V_77 [ 1 ] = * V_51 -> V_9 -> V_10 . V_35 . V_62 ;
V_50 -> V_19 = F_44 ( V_77 , 2 , V_80 , V_81 ) ;
if ( V_50 -> V_19 != NULL ) {
V_51 -> V_19 =
(struct V_82 * ) ( ( V_24 * )
V_50 -> V_19 +
V_6 ) ;
V_76 = V_41 ;
} else {
F_39 ( L_3 ) ;
V_76 = V_54 ;
}
} else {
V_76 = V_41 ;
}
return V_76 ;
}
static int F_45 ( T_2 V_83 ,
struct V_3 * V_50 ,
struct V_3 * V_51 )
{
if ( V_50 -> V_19 ) {
if ( V_50 -> V_19 < V_51 -> V_19 )
F_46 ( V_50 -> V_19 ) ;
else
F_46 ( V_51 -> V_19 ) ;
V_50 -> V_19 = NULL ;
V_51 -> V_19 = NULL ;
}
return V_41 ;
}
static struct V_84 * F_47 ( struct V_85 * V_85 ,
struct V_86 V_87 )
{
struct V_84 * V_88 ;
if ( F_48 ( V_87 ) )
return NULL ;
F_49 (entry, &qp_list->head, list_item) {
if ( F_50 ( V_88 -> V_87 , V_87 ) )
return V_88 ;
}
return NULL ;
}
static struct V_89 *
F_51 ( struct V_86 V_87 )
{
struct V_89 * V_88 ;
struct V_84 * V_90 = F_47 ( & V_91 , V_87 ) ;
V_88 = V_90 ? F_52 (
V_90 , struct V_89 , V_90 ) : NULL ;
return V_88 ;
}
static struct V_92 *
F_53 ( struct V_86 V_87 )
{
struct V_92 * V_88 ;
struct V_84 * V_90 = F_47 ( & V_93 , V_87 ) ;
V_88 = V_90 ? F_52 (
V_90 , struct V_92 , V_90 ) : NULL ;
return V_88 ;
}
static int F_54 ( bool V_94 , struct V_86 V_87 )
{
T_2 V_95 = F_55 () ;
struct V_96 V_97 ;
V_97 . V_98 . V_99 . V_100 = F_56 ( V_95 , V_101 ) ;
V_97 . V_98 . V_99 . V_28 = F_56 ( V_102 ,
V_103 ) ;
V_97 . V_98 . V_99 . V_104 = sizeof( V_97 ) - sizeof( V_97 . V_98 . V_99 ) ;
V_97 . V_98 . V_105 . V_106 =
V_94 ? V_107 : V_108 ;
V_97 . V_109 . V_110 = V_95 ;
V_97 . V_109 . V_87 = V_87 ;
return F_57 ( & V_97 . V_98 . V_99 ) ;
}
static struct V_89 *
F_58 ( struct V_86 V_87 ,
T_2 V_111 ,
T_2 V_14 ,
T_1 V_112 ,
T_1 V_113 ,
void * V_50 ,
void * V_51 )
{
int V_76 ;
struct V_89 * V_88 ;
const T_1 V_114 = F_2 ( V_112 , V_6 ) +
F_2 ( V_113 , V_6 ) + 2 ;
if ( F_48 ( V_87 ) ) {
T_2 V_95 = F_55 () ;
V_87 = F_56 ( V_95 , V_115 ) ;
}
V_88 = F_24 ( sizeof( * V_88 ) , V_26 ) ;
if ( V_88 ) {
V_88 -> V_90 . V_111 = V_111 ;
V_88 -> V_90 . V_14 = V_14 ;
V_88 -> V_90 . V_112 = V_112 ;
V_88 -> V_90 . V_113 = V_113 ;
V_88 -> V_90 . V_116 = 0 ;
V_88 -> V_114 = V_114 ;
V_88 -> V_50 = V_50 ;
V_88 -> V_51 = V_51 ;
F_59 ( & V_88 -> V_90 . V_117 ) ;
V_76 = F_60 ( & V_88 -> V_118 ,
V_119 ,
V_87 ) ;
V_88 -> V_90 . V_87 = F_61 ( & V_88 -> V_118 ) ;
if ( ( V_76 != V_41 ) ||
F_47 ( & V_91 , V_88 -> V_90 . V_87 ) ) {
F_39 ( L_4 ,
V_87 . V_120 , V_87 . V_118 , V_76 ) ;
F_16 ( V_88 ) ;
V_88 = NULL ;
}
}
return V_88 ;
}
static void F_62 ( struct V_89 * V_88 )
{
F_17 ( & V_88 -> V_47 ) ;
F_28 ( V_88 -> V_50 , V_88 -> V_51 ) ;
F_1 ( V_88 -> V_50 , V_88 -> V_90 . V_112 ) ;
F_1 ( V_88 -> V_51 , V_88 -> V_90 . V_113 ) ;
F_63 ( & V_88 -> V_118 ) ;
F_16 ( V_88 ) ;
}
static int F_64 ( const struct V_89 * V_88 )
{
struct V_121 * V_122 ;
T_3 V_123 ;
int V_76 ;
if ( ! V_88 || V_88 -> V_114 <= 2 )
return V_40 ;
V_123 = sizeof( * V_122 ) +
( T_3 ) V_88 -> V_114 * sizeof( T_2 ) ;
V_122 = F_15 ( V_123 , V_26 ) ;
if ( ! V_122 )
return V_54 ;
V_122 -> V_99 . V_100 = F_56 ( V_102 ,
V_124 ) ;
V_122 -> V_99 . V_28 = V_125 ;
V_122 -> V_99 . V_104 = V_123 - V_126 ;
V_122 -> V_87 = V_88 -> V_90 . V_87 ;
V_122 -> V_111 = V_88 -> V_90 . V_111 ;
V_122 -> V_14 = V_88 -> V_90 . V_14 ;
V_122 -> V_112 = V_88 -> V_90 . V_112 ;
V_122 -> V_113 = V_88 -> V_90 . V_113 ;
V_122 -> V_114 = V_88 -> V_114 ;
V_76 = F_18 ( ( V_24 * ) V_122 + sizeof( * V_122 ) ,
& V_88 -> V_47 ) ;
if ( V_76 == V_41 )
V_76 = F_65 ( & V_122 -> V_99 ) ;
F_16 ( V_122 ) ;
return V_76 ;
}
static int F_66 ( struct V_86 V_87 )
{
struct V_127 V_128 ;
V_128 . V_99 . V_100 = F_56 ( V_102 ,
V_129 ) ;
V_128 . V_99 . V_28 = V_125 ;
V_128 . V_99 . V_104 = sizeof( V_87 ) ;
V_128 . V_87 = V_87 ;
return F_65 ( & V_128 . V_99 ) ;
}
static void F_67 ( struct V_85 * V_85 , struct V_84 * V_88 )
{
if ( V_88 )
F_68 ( & V_88 -> V_117 , & V_85 -> V_130 ) ;
}
static void F_69 ( struct V_85 * V_85 ,
struct V_84 * V_88 )
{
if ( V_88 )
F_70 ( & V_88 -> V_117 ) ;
}
static int F_71 ( struct V_86 V_87 )
{
int V_76 ;
struct V_89 * V_88 ;
T_2 V_116 = ~ 0 ;
F_30 ( & V_91 . V_22 ) ;
V_88 = F_51 ( V_87 ) ;
if ( ! V_88 ) {
F_32 ( & V_91 . V_22 ) ;
return V_131 ;
}
if ( V_88 -> V_90 . V_14 & V_132 ) {
V_76 = V_41 ;
if ( V_88 -> V_90 . V_116 > 1 ) {
V_76 = F_54 ( false , V_87 ) ;
}
} else {
V_76 = F_66 ( V_87 ) ;
if ( V_76 < V_41 ) {
F_32 ( & V_91 . V_22 ) ;
return V_76 ;
}
}
V_88 -> V_90 . V_116 -- ;
if ( V_88 -> V_90 . V_116 == 0 )
F_69 ( & V_91 , & V_88 -> V_90 ) ;
if ( V_88 )
V_116 = V_88 -> V_90 . V_116 ;
F_32 ( & V_91 . V_22 ) ;
if ( V_116 == 0 )
F_62 ( V_88 ) ;
return V_76 ;
}
static int F_72 ( struct V_86 * V_87 ,
struct V_3 * * V_50 ,
T_1 V_112 ,
struct V_3 * * V_51 ,
T_1 V_113 ,
T_2 V_111 ,
T_2 V_14 ,
T_2 V_133 )
{
const T_1 V_44 =
F_2 ( V_112 , V_6 ) + 1 ;
const T_1 V_46 =
F_2 ( V_113 , V_6 ) + 1 ;
void * V_134 = NULL ;
void * V_135 = NULL ;
int V_76 ;
struct V_89 * V_136 = NULL ;
if ( V_133 != V_137 )
return V_138 ;
F_30 ( & V_91 . V_22 ) ;
V_136 = F_51 ( * V_87 ) ;
if ( V_136 ) {
if ( V_136 -> V_90 . V_14 & V_132 ) {
if ( V_136 -> V_90 . V_116 > 1 ) {
F_73 ( L_5 ) ;
V_76 = V_79 ;
goto V_139;
}
if ( V_136 -> V_90 . V_112 != V_113 ||
V_136 -> V_90 . V_113 !=
V_112 ||
V_136 -> V_90 . V_14 !=
( V_14 & ~ V_140 ) ) {
F_73 ( L_6 ) ;
V_76 = V_78 ;
goto V_139;
}
V_76 = F_54 ( true , * V_87 ) ;
if ( V_76 < V_41 )
goto V_139;
V_134 = V_136 -> V_51 ;
V_135 = V_136 -> V_50 ;
goto V_73;
}
V_76 = V_53 ;
goto V_139;
}
V_134 = F_5 ( V_112 , V_14 ) ;
if ( ! V_134 ) {
F_39 ( L_7 ) ;
V_76 = V_54 ;
goto error;
}
V_135 = F_5 ( V_113 , V_14 ) ;
if ( ! V_135 ) {
F_39 ( L_8 ) ;
V_76 = V_54 ;
goto error;
}
V_136 = F_58 ( * V_87 , V_111 , V_14 ,
V_112 , V_113 ,
V_134 , V_135 ) ;
if ( ! V_136 ) {
F_39 ( L_9 , V_141 ) ;
V_76 = V_54 ;
goto error;
}
V_76 = F_14 ( V_134 , V_44 , V_135 ,
V_46 ,
& V_136 -> V_47 ) ;
if ( V_76 < V_41 ) {
F_39 ( L_10 ) ;
goto error;
}
if ( V_136 -> V_90 . V_14 & V_132 ) {
T_2 V_95 = F_55 () ;
if ( V_136 -> V_90 . V_87 . V_120 != V_95 ||
( V_136 -> V_90 . V_111 != V_115 &&
V_136 -> V_90 . V_111 != V_95 ) ) {
V_76 = V_138 ;
goto error;
}
if ( V_136 -> V_90 . V_14 & V_140 ) {
V_76 = V_131 ;
goto error;
}
} else {
V_76 = F_64 ( V_136 ) ;
if ( V_76 < V_41 ) {
F_39 ( L_11 , V_76 ) ;
goto error;
}
}
F_26 ( (struct V_3 * ) V_134 ,
(struct V_3 * ) V_135 ) ;
F_67 ( & V_91 , & V_136 -> V_90 ) ;
V_73:
V_136 -> V_90 . V_116 ++ ;
* V_87 = V_136 -> V_90 . V_87 ;
* V_50 = (struct V_3 * ) V_134 ;
* V_51 = (struct V_3 * ) V_135 ;
if ( ( V_136 -> V_90 . V_14 & V_132 ) &&
V_136 -> V_90 . V_116 == 1 ) {
F_74 ( ( * V_50 ) -> V_19 , * V_87 ) ;
F_74 ( ( * V_51 ) -> V_19 , * V_87 ) ;
}
F_32 ( & V_91 . V_22 ) ;
return V_41 ;
error:
F_32 ( & V_91 . V_22 ) ;
if ( V_136 ) {
F_62 ( V_136 ) ;
} else {
F_1 ( V_134 , V_112 ) ;
F_1 ( V_135 , V_113 ) ;
}
return V_76 ;
V_139:
F_32 ( & V_91 . V_22 ) ;
return V_76 ;
}
static int F_75 ( struct V_86 V_87 ,
T_2 V_111 ,
T_2 V_14 ,
T_2 V_133 ,
T_1 V_112 ,
T_1 V_113 ,
struct V_74 * V_75 ,
struct V_142 * V_120 ,
T_4 V_143 ,
void * V_144 , struct V_92 * * V_145 )
{
struct V_92 * V_88 = NULL ;
const T_2 V_95 = F_76 ( V_120 ) ;
bool V_146 = V_14 & V_132 ;
int V_76 ;
T_1 V_147 ;
T_1 V_148 ;
if ( V_14 & V_140 )
return V_131 ;
if ( V_87 . V_120 != V_95 && V_87 . V_120 != V_111 )
return V_138 ;
if ( F_77 ( V_95 ) && F_77 ( V_111 ) )
return V_149 ;
if ( V_146 && V_111 != V_115 && V_95 != V_111 )
return V_138 ;
V_88 = F_24 ( sizeof( * V_88 ) , V_150 ) ;
if ( ! V_88 )
return V_54 ;
if ( F_76 ( V_120 ) == V_151 && ! V_146 ) {
V_147 = V_113 ;
V_148 = V_112 ;
} else {
V_147 = V_112 ;
V_148 = V_113 ;
}
V_88 -> V_90 . V_87 = V_87 ;
V_88 -> V_90 . V_111 = V_111 ;
V_88 -> V_90 . V_14 = V_14 ;
V_88 -> V_90 . V_112 = V_147 ;
V_88 -> V_90 . V_113 = V_148 ;
V_88 -> V_90 . V_116 = 1 ;
V_88 -> V_152 = V_95 ;
V_88 -> V_153 = V_115 ;
V_88 -> V_154 = V_155 ;
V_88 -> V_156 =
! ! ( V_120 -> V_133 & V_157 ) ;
V_88 -> V_158 =
! ! ( V_133 & V_159 ) ;
V_88 -> V_160 = false ;
V_88 -> V_143 = V_143 ;
V_88 -> V_144 = V_144 ;
V_88 -> V_50 = F_23 ( V_147 ) ;
if ( V_88 -> V_50 == NULL ) {
V_76 = V_54 ;
goto error;
}
V_88 -> V_51 = F_23 ( V_148 ) ;
if ( V_88 -> V_51 == NULL ) {
V_76 = V_54 ;
goto error;
}
F_26 ( V_88 -> V_50 , V_88 -> V_51 ) ;
F_59 ( & V_88 -> V_90 . V_117 ) ;
if ( V_146 ) {
V_24 * V_161 ;
V_88 -> V_162 = F_78 ( F_79 ( V_88 -> V_90 ) ,
V_6 , V_26 ) ;
if ( V_88 -> V_162 == NULL ) {
V_76 = V_54 ;
goto error;
}
V_88 -> V_154 = V_163 ;
V_88 -> V_50 -> V_19 = V_88 -> V_162 ;
V_161 = ( V_24 * ) V_88 -> V_162 + V_6 *
( F_2 ( V_88 -> V_90 . V_112 , V_6 ) + 1 ) ;
V_88 -> V_51 -> V_19 = (struct V_82 * ) V_161 ;
} else if ( V_75 ) {
V_76 = F_41 ( V_75 ,
V_88 -> V_50 ,
V_88 -> V_51 ) ;
if ( V_76 < V_41 )
goto error;
V_88 -> V_154 = V_163 ;
} else {
V_88 -> V_154 = V_164 ;
}
F_67 ( & V_93 , & V_88 -> V_90 ) ;
if ( V_145 != NULL )
* V_145 = V_88 ;
V_76 = F_60 ( & V_88 -> V_118 ,
V_165 ,
V_87 ) ;
if ( V_76 != V_41 ) {
F_39 ( L_4 ,
V_87 . V_120 , V_87 . V_118 , V_76 ) ;
goto error;
}
V_88 -> V_90 . V_87 = F_61 ( & V_88 -> V_118 ) ;
if ( V_146 ) {
F_74 ( V_88 -> V_50 -> V_19 ,
V_88 -> V_90 . V_87 ) ;
F_74 ( V_88 -> V_51 -> V_19 ,
V_88 -> V_90 . V_87 ) ;
}
F_80 ( V_120 , V_88 -> V_90 . V_87 ) ;
return V_41 ;
error:
if ( V_88 != NULL ) {
F_25 ( V_88 -> V_50 , V_147 ) ;
F_25 ( V_88 -> V_51 , V_148 ) ;
F_16 ( V_88 ) ;
}
return V_76 ;
}
static int F_81 ( bool V_94 ,
struct V_86 V_87 ,
T_2 V_166 ,
T_2 V_110 )
{
int V_167 ;
struct V_96 V_97 ;
if ( F_48 ( V_87 ) || V_166 == V_115 ||
V_110 == V_115 )
return V_40 ;
V_97 . V_98 . V_99 . V_100 = F_56 ( V_110 , V_101 ) ;
V_97 . V_98 . V_99 . V_28 = F_56 ( V_102 ,
V_103 ) ;
V_97 . V_98 . V_99 . V_104 = sizeof( V_97 ) - sizeof( V_97 . V_98 . V_99 ) ;
V_97 . V_98 . V_105 . V_106 = V_94 ?
V_107 : V_108 ;
V_97 . V_109 . V_87 = V_87 ;
V_97 . V_109 . V_110 = V_166 ;
V_167 = F_82 ( V_102 ,
& V_97 . V_98 . V_99 , false ) ;
if ( V_167 < V_41 )
F_39 ( L_12 ,
V_94 ? L_13 : L_14 , V_110 ) ;
return V_167 ;
}
static int F_83 ( struct V_92 * V_88 ,
T_2 V_111 ,
T_2 V_14 ,
T_2 V_133 ,
T_1 V_112 ,
T_1 V_113 ,
struct V_74 * V_75 ,
struct V_142 * V_120 ,
T_4 V_143 ,
void * V_144 ,
struct V_92 * * V_145 )
{
const T_2 V_95 = F_76 ( V_120 ) ;
bool V_146 = V_14 & V_132 ;
int V_76 ;
if ( V_88 -> V_154 != V_164 &&
V_88 -> V_154 != V_163 )
return V_79 ;
if ( V_146 ) {
if ( ! ( V_88 -> V_90 . V_14 & V_132 ) ||
V_95 != V_88 -> V_152 ) {
return V_40 ;
}
} else if ( V_95 == V_88 -> V_152 ||
V_95 == V_88 -> V_153 ) {
return V_53 ;
}
if ( F_77 ( V_95 ) &&
F_77 ( V_88 -> V_152 ) )
return V_149 ;
if ( ( V_120 -> V_133 & V_157 ) &&
! V_88 -> V_158 )
return V_138 ;
if ( V_88 -> V_156 &&
( ! ( V_133 & V_159 ) ) )
return V_138 ;
if ( V_88 -> V_90 . V_111 != V_115 && V_88 -> V_90 . V_111 != V_95 )
return V_138 ;
if ( V_88 -> V_152 == V_151 ) {
if ( ! F_84 ( V_120 ) )
return V_168 ;
} else if ( V_95 == V_151 ) {
struct V_142 * V_169 ;
bool V_170 ;
V_169 = F_85 ( V_88 -> V_152 ) ;
V_170 = F_84 ( V_169 ) ;
F_86 ( V_169 ) ;
if ( ! V_170 )
return V_168 ;
}
if ( ( V_88 -> V_90 . V_14 & ~ V_171 ) != ( V_14 & ~ V_172 ) )
return V_78 ;
if ( V_95 != V_151 ) {
if ( V_88 -> V_90 . V_112 != V_112 ||
V_88 -> V_90 . V_113 != V_113 ) {
return V_78 ;
}
} else if ( V_88 -> V_90 . V_112 != V_113 ||
V_88 -> V_90 . V_113 != V_112 ) {
return V_78 ;
}
if ( V_95 != V_151 ) {
if ( V_88 -> V_154 != V_164 )
return V_40 ;
if ( V_75 != NULL ) {
V_76 = F_41 ( V_75 ,
V_88 -> V_50 ,
V_88 -> V_51 ) ;
if ( V_76 < V_41 )
return V_76 ;
V_88 -> V_154 = V_173 ;
} else {
V_88 -> V_154 = V_174 ;
}
} else if ( V_88 -> V_154 == V_164 ) {
return V_79 ;
} else {
V_88 -> V_154 = V_173 ;
}
if ( V_88 -> V_154 == V_173 ) {
V_76 =
F_81 ( true , V_88 -> V_90 . V_87 , V_95 ,
V_88 -> V_152 ) ;
if ( V_76 < V_41 )
F_39 ( L_15 ,
V_88 -> V_152 , V_88 -> V_90 . V_87 . V_120 ,
V_88 -> V_90 . V_87 . V_118 ) ;
}
V_88 -> V_153 = V_95 ;
V_88 -> V_90 . V_116 ++ ;
if ( V_143 ) {
V_88 -> V_143 = V_143 ;
V_88 -> V_144 = V_144 ;
}
if ( ! V_146 )
F_80 ( V_120 , V_88 -> V_90 . V_87 ) ;
if ( V_145 != NULL )
* V_145 = V_88 ;
return V_41 ;
}
static int F_87 ( struct V_86 V_87 ,
T_2 V_111 ,
T_2 V_14 ,
T_2 V_133 ,
T_1 V_112 ,
T_1 V_113 ,
struct V_74 * V_75 ,
struct V_142 * V_120 ,
T_4 V_143 ,
void * V_144 ,
struct V_92 * * V_145 ,
bool * V_175 )
{
const T_2 V_95 = F_76 ( V_120 ) ;
bool V_176 ;
struct V_92 * V_88 = NULL ;
bool V_146 = V_14 & V_132 ;
int V_76 ;
if ( F_48 ( V_87 ) ||
( V_14 & ~ V_177 ) || V_146 ||
! ( V_112 || V_113 ) ||
! V_120 || V_95 == V_115 ||
V_87 . V_120 == V_115 ) {
return V_40 ;
}
if ( V_75 && ! F_88 ( V_75 ) )
return V_40 ;
F_30 ( & V_93 . V_22 ) ;
if ( ! V_146 && F_89 ( V_120 , V_87 ) ) {
F_73 ( L_16 ,
V_95 , V_87 . V_120 , V_87 . V_118 ) ;
F_32 ( & V_93 . V_22 ) ;
return V_53 ;
}
if ( V_87 . V_118 != V_115 )
V_88 = F_53 ( V_87 ) ;
if ( ! V_88 ) {
V_176 = true ;
V_76 =
F_75 ( V_87 , V_111 , V_14 , V_133 ,
V_112 , V_113 , V_75 ,
V_120 , V_143 , V_144 , V_145 ) ;
} else {
V_176 = false ;
V_76 =
F_83 ( V_88 , V_111 , V_14 , V_133 ,
V_112 , V_113 , V_75 ,
V_120 , V_143 , V_144 , V_145 ) ;
}
F_32 ( & V_93 . V_22 ) ;
if ( V_175 )
* V_175 = ( V_95 == V_151 ) &&
! ( V_176 && V_146 ) ;
return V_76 ;
}
static int F_90 ( struct V_86 * V_87 ,
struct V_3 * * V_50 ,
T_1 V_112 ,
struct V_3 * * V_51 ,
T_1 V_113 ,
T_2 V_111 ,
T_2 V_14 ,
T_2 V_133 ,
T_4 V_143 ,
void * V_144 )
{
struct V_86 V_178 ;
struct V_142 * V_120 ;
struct V_92 * V_88 ;
int V_76 ;
bool V_175 ;
if ( F_48 ( * V_87 ) ) {
V_178 = F_56 (
V_151 , V_115 ) ;
} else
V_178 = * V_87 ;
V_120 = F_85 ( V_151 ) ;
V_88 = NULL ;
V_76 =
F_87 ( V_178 , V_111 , V_14 , V_133 ,
V_112 , V_113 , NULL , V_120 ,
V_143 , V_144 , & V_88 , & V_175 ) ;
if ( V_76 == V_41 ) {
if ( V_175 ) {
* V_50 = V_88 -> V_51 ;
* V_51 = V_88 -> V_50 ;
} else {
* V_50 = V_88 -> V_50 ;
* V_51 = V_88 -> V_51 ;
}
* V_87 = F_61 ( & V_88 -> V_118 ) ;
} else {
* V_87 = V_179 ;
F_73 ( L_17 ,
V_76 ) ;
}
F_86 ( V_120 ) ;
return V_76 ;
}
int F_91 ( struct V_86 * V_87 ,
struct V_3 * * V_50 ,
T_1 V_112 ,
struct V_3 * * V_51 ,
T_1 V_113 ,
T_2 V_111 ,
T_2 V_14 ,
T_2 V_133 ,
bool V_180 ,
T_4 V_143 ,
void * V_144 )
{
if ( ! V_87 || ! V_50 || ! V_51 ||
( ! V_112 && ! V_113 ) || ( V_14 & ~ V_177 ) )
return V_40 ;
if ( V_180 ) {
return F_72 ( V_87 , V_50 ,
V_112 , V_51 ,
V_113 , V_111 ,
V_14 , V_133 ) ;
} else {
return F_90 ( V_87 , V_50 ,
V_112 , V_51 ,
V_113 , V_111 , V_14 ,
V_133 , V_143 , V_144 ) ;
}
}
static int F_92 ( struct V_86 V_87 )
{
int V_76 ;
struct V_142 * V_120 ;
V_120 = F_85 ( V_151 ) ;
V_76 = F_93 ( V_87 , V_120 ) ;
F_86 ( V_120 ) ;
return V_76 ;
}
static int F_94 ( struct V_86 V_87 , bool V_180 )
{
if ( F_48 ( V_87 ) )
return V_40 ;
if ( V_180 )
return F_71 ( V_87 ) ;
else
return F_92 ( V_87 ) ;
}
static struct V_84 * F_95 ( struct V_85 * V_85 )
{
if ( ! F_96 ( & V_85 -> V_130 ) ) {
struct V_84 * V_88 =
F_97 ( & V_85 -> V_130 , struct V_84 ,
V_117 ) ;
return V_88 ;
}
return NULL ;
}
void F_98 ( void )
{
struct V_84 * V_88 ;
struct V_92 * V_181 ;
F_30 ( & V_93 . V_22 ) ;
while ( ( V_88 = F_95 ( & V_93 ) ) ) {
V_181 = (struct V_92 * ) V_88 ;
F_69 ( & V_93 , V_88 ) ;
F_16 ( V_181 ) ;
}
F_32 ( & V_93 . V_22 ) ;
}
int F_99 ( struct V_86 V_87 ,
T_2 V_111 ,
T_2 V_14 ,
T_2 V_133 ,
T_1 V_112 ,
T_1 V_113 ,
struct V_74 * V_75 ,
struct V_142 * V_120 )
{
return F_87 ( V_87 , V_111 , V_14 , V_133 ,
V_112 , V_113 ,
V_75 , V_120 , NULL , NULL , NULL , NULL ) ;
}
int F_100 ( struct V_86 V_87 ,
T_1 V_66 ,
T_1 V_67 ,
struct V_142 * V_120 )
{
struct V_92 * V_88 ;
int V_76 ;
const T_2 V_95 = F_76 ( V_120 ) ;
if ( F_48 ( V_87 ) || ! V_120 ||
V_95 == V_115 )
return V_40 ;
if ( V_66 == 0 || V_67 == 0 )
return V_40 ;
F_30 ( & V_93 . V_22 ) ;
if ( ! F_89 ( V_120 , V_87 ) ) {
F_39 ( L_18 ,
V_95 , V_87 . V_120 , V_87 . V_118 ) ;
V_76 = V_131 ;
goto V_73;
}
V_88 = F_53 ( V_87 ) ;
if ( ! V_88 ) {
V_76 = V_131 ;
goto V_73;
}
if ( V_88 -> V_152 != V_95 &&
( V_88 -> V_152 != V_151 ||
V_88 -> V_153 != V_95 ) ) {
V_76 = V_182 ;
goto V_73;
}
if ( V_88 -> V_154 != V_164 &&
V_88 -> V_154 != V_174 ) {
V_76 = V_79 ;
goto V_73;
}
V_76 = F_36 ( V_66 , V_67 ,
V_88 -> V_50 , V_88 -> V_51 ) ;
if ( V_76 < V_41 )
goto V_73;
V_76 = F_43 ( V_88 -> V_50 , V_88 -> V_51 ) ;
if ( V_76 < V_41 ) {
F_42 ( V_88 -> V_50 ,
V_88 -> V_51 ) ;
goto V_73;
}
if ( V_88 -> V_154 == V_164 )
V_88 -> V_154 = V_163 ;
else
V_88 -> V_154 = V_173 ;
V_88 -> V_160 = true ;
if ( V_88 -> V_154 == V_173 ) {
V_76 =
F_81 ( true , V_87 , V_95 , V_88 -> V_152 ) ;
if ( V_76 < V_41 ) {
F_39 ( L_15 ,
V_88 -> V_152 , V_88 -> V_90 . V_87 . V_120 ,
V_88 -> V_90 . V_87 . V_118 ) ;
}
}
V_76 = V_41 ;
V_73:
F_32 ( & V_93 . V_22 ) ;
return V_76 ;
}
static void F_101 ( struct V_92 * V_88 )
{
V_88 -> V_50 -> V_20 = NULL ;
V_88 -> V_51 -> V_20 = NULL ;
}
int F_93 ( struct V_86 V_87 , struct V_142 * V_120 )
{
struct V_92 * V_88 ;
const T_2 V_95 = F_76 ( V_120 ) ;
T_2 V_110 ;
bool V_146 = false ;
int V_76 ;
if ( F_48 ( V_87 ) || ! V_120 ||
V_95 == V_115 ) {
return V_40 ;
}
F_30 ( & V_93 . V_22 ) ;
if ( ! F_89 ( V_120 , V_87 ) ) {
F_73 ( L_18 ,
V_95 , V_87 . V_120 , V_87 . V_118 ) ;
V_76 = V_131 ;
goto V_73;
}
V_88 = F_53 ( V_87 ) ;
if ( ! V_88 ) {
F_73 ( L_19 ,
V_95 , V_87 . V_120 , V_87 . V_118 ) ;
V_76 = V_131 ;
goto V_73;
}
if ( V_95 != V_88 -> V_152 && V_95 != V_88 -> V_153 ) {
V_76 = V_183 ;
goto V_73;
}
if ( V_95 == V_88 -> V_152 ) {
V_110 = V_88 -> V_153 ;
V_88 -> V_152 = V_115 ;
} else {
V_110 = V_88 -> V_152 ;
V_88 -> V_153 = V_115 ;
}
V_88 -> V_90 . V_116 -- ;
V_146 = V_88 -> V_90 . V_14 & V_132 ;
if ( V_95 != V_151 ) {
bool V_184 ;
F_29 ( V_88 -> V_50 ) ;
V_184 = V_88 -> V_50 -> V_19 ||
V_88 -> V_51 -> V_19 ;
if ( F_102 ( V_88 ) ) {
V_76 =
F_45 ( V_185 ,
V_88 -> V_50 ,
V_88 -> V_51 ) ;
if ( V_76 < V_41 )
F_39 ( L_20 ,
V_87 . V_120 , V_87 . V_118 ,
V_76 ) ;
if ( V_88 -> V_160 )
F_42 ( V_88 -> V_50 ,
V_88 ->
V_51 ) ;
else
F_42 ( V_88 -> V_50 ,
V_88 ->
V_51 ) ;
}
if ( ! V_184 )
F_101 ( V_88 ) ;
F_31 ( V_88 -> V_50 ) ;
if ( ! V_184 && V_88 -> V_143 )
V_88 -> V_143 ( V_88 -> V_144 ) ;
} else {
if ( V_88 -> V_143 ) {
V_88 -> V_143 = NULL ;
V_88 -> V_144 = NULL ;
}
}
if ( V_88 -> V_90 . V_116 == 0 ) {
F_69 ( & V_93 , & V_88 -> V_90 ) ;
if ( V_146 )
F_16 ( V_88 -> V_162 ) ;
F_28 ( V_88 -> V_50 , V_88 -> V_51 ) ;
F_25 ( V_88 -> V_50 , V_88 -> V_90 . V_112 ) ;
F_25 ( V_88 -> V_51 , V_88 -> V_90 . V_113 ) ;
F_63 ( & V_88 -> V_118 ) ;
F_16 ( V_88 ) ;
F_103 ( V_120 , V_87 ) ;
} else {
F_81 ( false , V_87 , V_95 , V_110 ) ;
if ( V_95 == V_151 &&
F_102 ( V_88 ) ) {
V_88 -> V_154 = V_186 ;
} else {
V_88 -> V_154 = V_187 ;
}
if ( ! V_146 )
F_103 ( V_120 , V_87 ) ;
}
V_76 = V_41 ;
V_73:
F_32 ( & V_93 . V_22 ) ;
return V_76 ;
}
int F_104 ( struct V_86 V_87 ,
struct V_142 * V_120 ,
T_1 V_188 )
{
struct V_92 * V_88 ;
const T_2 V_95 = F_76 ( V_120 ) ;
bool V_146 = false ;
int V_76 ;
if ( F_48 ( V_87 ) || ! V_120 ||
V_95 == V_115 )
return V_40 ;
F_30 ( & V_93 . V_22 ) ;
if ( ! F_89 ( V_120 , V_87 ) ) {
F_73 ( L_18 ,
V_95 , V_87 . V_120 , V_87 . V_118 ) ;
V_76 = V_131 ;
goto V_73;
}
V_88 = F_53 ( V_87 ) ;
if ( ! V_88 ) {
F_73 ( L_21 ,
V_95 , V_87 . V_120 , V_87 . V_118 ) ;
V_76 = V_131 ;
goto V_73;
}
if ( V_95 != V_88 -> V_152 && V_95 != V_88 -> V_153 ) {
V_76 = V_183 ;
goto V_73;
}
V_146 = V_88 -> V_90 . V_14 & V_132 ;
V_76 = V_41 ;
if ( V_95 != V_151 ) {
struct V_74 V_75 ;
V_75 . V_64 = V_188 ;
V_75 . V_189 = F_79 ( V_88 -> V_90 ) ;
F_29 ( V_88 -> V_50 ) ;
F_101 ( V_88 ) ;
V_76 =
F_41 ( & V_75 ,
V_88 -> V_50 ,
V_88 -> V_51 ) ;
F_31 ( V_88 -> V_50 ) ;
if ( V_76 == V_41 ) {
V_88 -> V_154 ++ ;
if ( V_88 -> V_143 )
V_88 -> V_143 ( V_88 -> V_144 ) ;
}
}
V_73:
F_32 ( & V_93 . V_22 ) ;
return V_76 ;
}
static int F_105 ( struct V_92 * V_88 )
{
int V_76 ;
if ( V_88 -> V_50 -> V_20 != NULL &&
V_88 -> V_51 -> V_20 != NULL ) {
return V_41 ;
}
if ( NULL == V_88 -> V_50 -> V_19 ||
NULL == V_88 -> V_51 -> V_19 ) {
V_76 = F_43 ( V_88 -> V_50 , V_88 -> V_51 ) ;
if ( V_76 < V_41 )
return V_76 ;
}
memcpy ( & V_88 -> V_190 , V_88 -> V_50 -> V_19 ,
sizeof( V_88 -> V_190 ) ) ;
V_88 -> V_50 -> V_20 = & V_88 -> V_190 ;
memcpy ( & V_88 -> V_191 , V_88 -> V_51 -> V_19 ,
sizeof( V_88 -> V_191 ) ) ;
V_88 -> V_51 -> V_20 = & V_88 -> V_191 ;
return V_41 ;
}
int F_106 ( struct V_86 V_87 ,
struct V_142 * V_120 ,
T_2 V_83 )
{
struct V_92 * V_88 ;
const T_2 V_95 = F_76 ( V_120 ) ;
bool V_146 = false ;
int V_76 ;
if ( F_48 ( V_87 ) || ! V_120 ||
V_95 == V_115 )
return V_40 ;
F_30 ( & V_93 . V_22 ) ;
if ( ! F_89 ( V_120 , V_87 ) ) {
F_73 ( L_18 ,
V_95 , V_87 . V_120 , V_87 . V_118 ) ;
V_76 = V_131 ;
goto V_73;
}
V_88 = F_53 ( V_87 ) ;
if ( ! V_88 ) {
F_73 ( L_21 ,
V_95 , V_87 . V_120 , V_87 . V_118 ) ;
V_76 = V_131 ;
goto V_73;
}
if ( V_95 != V_88 -> V_152 && V_95 != V_88 -> V_153 ) {
V_76 = V_183 ;
goto V_73;
}
V_146 = V_88 -> V_90 . V_14 & V_132 ;
if ( V_95 != V_151 ) {
F_29 ( V_88 -> V_50 ) ;
V_76 = F_105 ( V_88 ) ;
if ( V_76 < V_41 )
F_39 ( L_22 ,
V_87 . V_120 , V_87 . V_118 , V_76 ) ;
F_45 ( V_83 , V_88 -> V_50 , V_88 -> V_51 ) ;
F_42 ( V_88 -> V_50 ,
V_88 -> V_51 ) ;
V_88 -> V_154 -- ;
F_31 ( V_88 -> V_50 ) ;
}
V_76 = V_41 ;
V_73:
F_32 ( & V_93 . V_22 ) ;
return V_76 ;
}
void F_107 ( void )
{
struct V_84 * V_88 ;
struct V_89 * V_192 ;
F_30 ( & V_91 . V_22 ) ;
while ( ( V_88 = F_95 ( & V_91 ) ) ) {
V_192 = (struct V_89 * ) V_88 ;
if ( ! ( V_88 -> V_14 & V_132 ) )
F_66 ( V_88 -> V_87 ) ;
V_88 -> V_116 = 0 ;
F_69 ( & V_91 , V_88 ) ;
F_62 ( V_192 ) ;
}
F_32 ( & V_91 . V_22 ) ;
}
static void F_108 ( const struct V_193 * V_194 )
{
F_29 ( V_194 -> V_50 ) ;
}
static void F_109 ( const struct V_193 * V_194 )
{
F_31 ( V_194 -> V_50 ) ;
}
static int F_110 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
int V_76 ;
if ( NULL == V_50 -> V_19 || NULL == V_51 -> V_19 ) {
V_76 = F_43 ( V_50 , V_51 ) ;
if ( V_76 < V_41 )
return ( V_50 -> V_20 &&
V_51 -> V_20 ) ?
V_195 :
V_183 ;
}
return V_41 ;
}
static int F_111 ( const struct V_193 * V_194 ,
struct V_82 * * V_196 ,
struct V_82 * * V_197 )
{
int V_76 ;
V_76 = F_110 ( V_194 -> V_50 , V_194 -> V_51 ) ;
if ( V_76 == V_41 ) {
* V_196 = V_194 -> V_50 -> V_19 ;
* V_197 = V_194 -> V_51 -> V_19 ;
} else if ( V_194 -> V_50 -> V_20 &&
V_194 -> V_51 -> V_20 ) {
* V_196 = V_194 -> V_50 -> V_20 ;
* V_197 = V_194 -> V_51 -> V_20 ;
V_76 = V_41 ;
}
return V_76 ;
}
static int F_112 ( void * V_144 )
{
struct V_193 * V_194 = (struct V_193 * ) V_144 ;
F_108 ( V_194 ) ;
while ( V_194 -> V_198 > 0 ) {
V_194 -> V_198 -- ;
V_194 -> V_199 ++ ;
F_113 ( & V_194 -> V_106 ) ;
}
F_109 ( V_194 ) ;
return V_41 ;
}
static bool F_114 ( struct V_193 * V_194 )
{
unsigned int V_199 ;
V_194 -> V_198 ++ ;
V_199 = V_194 -> V_199 ;
F_109 ( V_194 ) ;
F_115 ( V_194 -> V_106 , V_199 != V_194 -> V_199 ) ;
F_108 ( V_194 ) ;
return true ;
}
static T_5 F_116 ( struct V_3 * V_50 ,
struct V_3 * V_51 ,
const T_1 V_200 ,
const void * V_201 ,
T_3 V_202 ,
T_6 V_203 )
{
T_7 V_204 ;
T_1 V_205 ;
T_3 V_206 ;
T_5 V_76 ;
V_76 = F_110 ( V_50 , V_51 ) ;
if ( F_117 ( V_76 != V_41 ) )
return V_76 ;
V_204 = F_118 ( V_50 -> V_19 ,
V_51 -> V_19 ,
V_200 ) ;
if ( V_204 == 0 )
return V_207 ;
if ( V_204 < V_41 )
return ( T_5 ) V_204 ;
V_206 = ( T_3 ) ( V_204 > V_202 ? V_202 : V_204 ) ;
V_205 = F_119 ( V_50 -> V_19 ) ;
if ( F_120 ( V_205 + V_206 < V_200 ) ) {
V_76 = V_203 ( V_50 , V_205 , V_201 , 0 , V_206 ) ;
} else {
const T_3 V_161 = ( T_3 ) ( V_200 - V_205 ) ;
V_76 = V_203 ( V_50 , V_205 , V_201 , 0 , V_161 ) ;
if ( V_76 >= V_41 )
V_76 = V_203 ( V_50 , 0 , V_201 , V_161 ,
V_206 - V_161 ) ;
}
if ( V_76 < V_41 )
return V_76 ;
F_121 ( V_50 -> V_19 , V_206 ,
V_200 ) ;
return V_206 ;
}
static T_5 F_122 ( struct V_3 * V_50 ,
struct V_3 * V_51 ,
const T_1 V_208 ,
void * V_201 ,
T_3 V_202 ,
T_8 V_209 ,
bool V_210 )
{
T_7 V_211 ;
T_1 V_130 ;
T_3 V_212 ;
T_5 V_76 ;
V_76 = F_110 ( V_50 , V_51 ) ;
if ( F_117 ( V_76 != V_41 ) )
return V_76 ;
V_211 = F_123 ( V_51 -> V_19 ,
V_50 -> V_19 ,
V_208 ) ;
if ( V_211 == 0 )
return V_213 ;
if ( V_211 < V_41 )
return ( T_5 ) V_211 ;
V_212 = ( T_3 ) ( V_211 > V_202 ? V_202 : V_211 ) ;
V_130 = F_124 ( V_50 -> V_19 ) ;
if ( F_120 ( V_130 + V_212 < V_208 ) ) {
V_76 = V_209 ( V_201 , 0 , V_51 , V_130 , V_212 ) ;
} else {
const T_3 V_161 = ( T_3 ) ( V_208 - V_130 ) ;
V_76 = V_209 ( V_201 , 0 , V_51 , V_130 , V_161 ) ;
if ( V_76 >= V_41 )
V_76 = V_209 ( V_201 , V_161 , V_51 , 0 ,
V_212 - V_161 ) ;
}
if ( V_76 < V_41 )
return V_76 ;
if ( V_210 )
F_125 ( V_50 -> V_19 ,
V_212 , V_208 ) ;
return V_212 ;
}
int F_126 ( struct V_193 * * V_194 ,
struct V_86 * V_87 ,
T_1 V_214 ,
T_1 V_215 ,
T_2 V_111 ,
T_2 V_14 ,
T_2 V_133 )
{
struct V_193 * V_216 ;
int V_68 ;
struct V_86 V_28 = V_179 ;
struct V_86 V_100 = F_56 ( V_111 , V_115 ) ;
enum V_217 V_218 ;
T_4 V_143 ;
void * V_144 ;
if ( V_214 + V_215 < V_219 ( V_214, V_215 ) ||
V_214 + V_215 > V_220 )
return V_221 ;
V_68 = V_217 ( & V_28 , & V_100 , false , & V_218 ) ;
if ( V_68 < V_41 )
V_218 = F_127 () ?
V_222 : V_223 ;
if ( V_14 & ( V_224 | V_225 ) ) {
F_73 ( L_23 ) ;
return V_40 ;
}
V_216 = F_24 ( sizeof( * V_216 ) , V_26 ) ;
if ( ! V_216 )
return V_54 ;
V_216 -> V_200 = V_214 ;
V_216 -> V_208 = V_215 ;
V_216 -> V_111 = V_111 ;
V_216 -> V_14 = V_14 ;
V_216 -> V_133 = V_133 ;
V_143 = NULL ;
V_144 = NULL ;
if ( V_223 == V_218 ) {
V_216 -> V_180 = false ;
if ( ! ( V_14 & V_132 ) ) {
V_216 -> V_198 = 0 ;
V_216 -> V_199 = 0 ;
F_128 ( & V_216 -> V_106 ) ;
V_143 = F_112 ;
V_144 = ( void * ) V_216 ;
}
} else {
V_216 -> V_180 = true ;
}
V_68 = F_91 ( V_87 ,
& V_216 -> V_50 ,
V_216 -> V_200 ,
& V_216 -> V_51 ,
V_216 -> V_208 ,
V_216 -> V_111 ,
V_216 -> V_14 ,
V_216 -> V_133 ,
V_216 -> V_180 ,
V_143 , V_144 ) ;
if ( V_68 < V_41 ) {
F_16 ( V_216 ) ;
return V_68 ;
}
* V_194 = V_216 ;
V_216 -> V_87 = * V_87 ;
return V_68 ;
}
int F_129 ( struct V_193 * * V_194 )
{
int V_76 ;
struct V_193 * V_226 ;
if ( ! V_194 || ! ( * V_194 ) )
return V_40 ;
V_226 = * V_194 ;
V_76 = F_94 ( V_226 -> V_87 , V_226 -> V_180 ) ;
memset ( V_226 , 0 , sizeof( * V_226 ) ) ;
V_226 -> V_87 = V_179 ;
V_226 -> V_111 = V_115 ;
F_16 ( V_226 ) ;
* V_194 = NULL ;
return V_76 ;
}
int F_130 ( const struct V_193 * V_194 ,
T_1 * V_227 ,
T_1 * V_228 )
{
struct V_82 * V_196 ;
struct V_82 * V_197 ;
int V_76 ;
if ( ! V_194 )
return V_40 ;
F_108 ( V_194 ) ;
V_76 =
F_111 ( V_194 , & V_196 , & V_197 ) ;
if ( V_76 == V_41 )
F_131 ( V_196 , V_197 ,
V_227 , V_228 ) ;
F_109 ( V_194 ) ;
if ( V_76 == V_41 &&
( ( V_227 && * V_227 >= V_194 -> V_200 ) ||
( V_228 && * V_228 >= V_194 -> V_200 ) ) )
return V_229 ;
return V_76 ;
}
int F_132 ( const struct V_193 * V_194 ,
T_1 * V_230 ,
T_1 * V_231 )
{
struct V_82 * V_196 ;
struct V_82 * V_197 ;
int V_76 ;
if ( ! V_194 )
return V_40 ;
F_108 ( V_194 ) ;
V_76 =
F_111 ( V_194 , & V_196 , & V_197 ) ;
if ( V_76 == V_41 )
F_131 ( V_197 , V_196 ,
V_230 , V_231 ) ;
F_109 ( V_194 ) ;
if ( V_76 == V_41 &&
( ( V_230 && * V_230 >= V_194 -> V_208 ) ||
( V_231 && * V_231 >= V_194 -> V_208 ) ) )
return V_229 ;
return V_76 ;
}
T_7 F_133 ( const struct V_193 * V_194 )
{
struct V_82 * V_196 ;
struct V_82 * V_197 ;
T_7 V_76 ;
if ( ! V_194 )
return V_40 ;
F_108 ( V_194 ) ;
V_76 =
F_111 ( V_194 , & V_196 , & V_197 ) ;
if ( V_76 == V_41 )
V_76 = F_118 ( V_196 ,
V_197 ,
V_194 -> V_200 ) ;
else
V_76 = 0 ;
F_109 ( V_194 ) ;
return V_76 ;
}
T_7 F_134 ( const struct V_193 * V_194 )
{
struct V_82 * V_196 ;
struct V_82 * V_197 ;
T_7 V_76 ;
if ( ! V_194 )
return V_40 ;
F_108 ( V_194 ) ;
V_76 =
F_111 ( V_194 , & V_196 , & V_197 ) ;
if ( V_76 == V_41 )
V_76 = F_118 ( V_197 ,
V_196 ,
V_194 -> V_208 ) ;
else
V_76 = 0 ;
F_109 ( V_194 ) ;
return V_76 ;
}
T_7 F_135 ( const struct V_193 * V_194 )
{
struct V_82 * V_196 ;
struct V_82 * V_197 ;
T_7 V_76 ;
if ( ! V_194 )
return V_40 ;
F_108 ( V_194 ) ;
V_76 =
F_111 ( V_194 , & V_196 , & V_197 ) ;
if ( V_76 == V_41 )
V_76 = F_123 ( V_196 ,
V_197 ,
V_194 -> V_200 ) ;
else
V_76 = 0 ;
F_109 ( V_194 ) ;
return V_76 ;
}
T_7 F_136 ( const struct V_193 * V_194 )
{
struct V_82 * V_196 ;
struct V_82 * V_197 ;
T_7 V_76 ;
if ( ! V_194 )
return V_40 ;
F_108 ( V_194 ) ;
V_76 =
F_111 ( V_194 , & V_196 , & V_197 ) ;
if ( V_76 == V_41 )
V_76 = F_123 ( V_197 ,
V_196 ,
V_194 -> V_208 ) ;
else
V_76 = 0 ;
F_109 ( V_194 ) ;
return V_76 ;
}
T_5 F_137 ( struct V_193 * V_194 ,
const void * V_201 ,
T_3 V_202 ,
int V_232 )
{
T_5 V_76 ;
if ( ! V_194 || ! V_201 )
return V_40 ;
F_108 ( V_194 ) ;
do {
V_76 = F_116 ( V_194 -> V_50 ,
V_194 -> V_51 ,
V_194 -> V_200 ,
V_201 , V_202 ,
F_19 ) ;
if ( V_76 == V_195 &&
! F_114 ( V_194 ) )
V_76 = V_233 ;
} while ( V_76 == V_195 );
F_109 ( V_194 ) ;
return V_76 ;
}
T_5 F_138 ( struct V_193 * V_194 ,
void * V_201 ,
T_3 V_202 ,
int V_232 )
{
T_5 V_76 ;
if ( ! V_194 || ! V_201 )
return V_40 ;
F_108 ( V_194 ) ;
do {
V_76 = F_122 ( V_194 -> V_50 ,
V_194 -> V_51 ,
V_194 -> V_208 ,
V_201 , V_202 ,
F_20 , true ) ;
if ( V_76 == V_195 &&
! F_114 ( V_194 ) )
V_76 = V_233 ;
} while ( V_76 == V_195 );
F_109 ( V_194 ) ;
return V_76 ;
}
T_5 F_139 ( struct V_193 * V_194 ,
void * V_201 ,
T_3 V_202 ,
int V_232 )
{
T_5 V_76 ;
if ( ! V_194 || ! V_201 )
return V_40 ;
F_108 ( V_194 ) ;
do {
V_76 = F_122 ( V_194 -> V_50 ,
V_194 -> V_51 ,
V_194 -> V_208 ,
V_201 , V_202 ,
F_20 , false ) ;
if ( V_76 == V_195 &&
! F_114 ( V_194 ) )
V_76 = V_233 ;
} while ( V_76 == V_195 );
F_109 ( V_194 ) ;
return V_76 ;
}
T_5 F_140 ( struct V_193 * V_194 ,
void * V_38 ,
T_3 V_234 ,
int V_232 )
{
T_5 V_76 ;
if ( ! V_194 || ! V_38 )
return V_40 ;
F_108 ( V_194 ) ;
do {
V_76 = F_116 ( V_194 -> V_50 ,
V_194 -> V_51 ,
V_194 -> V_200 ,
V_38 , V_234 ,
F_21 ) ;
if ( V_76 == V_195 &&
! F_114 ( V_194 ) )
V_76 = V_233 ;
} while ( V_76 == V_195 );
F_109 ( V_194 ) ;
return V_76 ;
}
T_5 F_141 ( struct V_193 * V_194 ,
void * V_38 ,
T_3 V_234 ,
int V_232 )
{
T_5 V_76 ;
if ( ! V_194 || ! V_38 )
return V_40 ;
F_108 ( V_194 ) ;
do {
V_76 = F_122 ( V_194 -> V_50 ,
V_194 -> V_51 ,
V_194 -> V_208 ,
V_38 , V_234 ,
F_22 ,
true ) ;
if ( V_76 == V_195 &&
! F_114 ( V_194 ) )
V_76 = V_233 ;
} while ( V_76 == V_195 );
F_109 ( V_194 ) ;
return V_76 ;
}
T_5 F_142 ( struct V_193 * V_194 ,
void * V_38 ,
T_3 V_234 ,
int V_232 )
{
T_5 V_76 ;
if ( ! V_194 || ! V_38 )
return V_40 ;
F_108 ( V_194 ) ;
do {
V_76 = F_122 ( V_194 -> V_50 ,
V_194 -> V_51 ,
V_194 -> V_208 ,
V_38 , V_234 ,
F_22 ,
false ) ;
if ( V_76 == V_195 &&
! F_114 ( V_194 ) )
V_76 = V_233 ;
} while ( V_76 == V_195 );
F_109 ( V_194 ) ;
return V_76 ;
}
