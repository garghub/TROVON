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
T_3 V_15 ;
T_3 V_16 ;
T_3 V_17 = sizeof( * V_4 ) + sizeof( * V_4 -> V_9 ) ;
T_1 V_18 ;
if ( V_2 > V_19 - V_6 )
return NULL ;
V_18 = F_2 ( V_2 , V_6 ) + 1 ;
if ( V_18 >
( V_19 - V_17 ) /
( sizeof( * V_4 -> V_9 -> V_10 . V_11 . V_13 ) +
sizeof( * V_4 -> V_9 -> V_10 . V_11 . V_12 ) ) )
return NULL ;
V_15 = V_18 * sizeof( * V_4 -> V_9 -> V_10 . V_11 . V_13 ) ;
V_16 = V_18 * sizeof( * V_4 -> V_9 -> V_10 . V_11 . V_12 ) ;
V_17 += V_15 + V_16 ;
V_4 = F_6 ( V_17 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_20 = NULL ;
V_4 -> V_21 = NULL ;
V_4 -> V_9 = (struct V_22 * ) ( V_4 + 1 ) ;
V_4 -> V_9 -> V_23 = NULL ;
V_4 -> V_9 -> V_18 = V_18 ;
V_4 -> V_9 -> V_10 . V_11 . V_13 = ( V_24 * ) ( V_4 -> V_9 + 1 ) ;
V_4 -> V_9 -> V_10 . V_11 . V_12 =
( void * * ) ( ( V_25 * ) V_4 -> V_9 -> V_10 . V_11 . V_13 + V_15 ) ;
V_4 -> V_9 -> V_26 = false ;
for ( V_5 = 0 ; V_5 < V_18 ; V_5 ++ ) {
V_4 -> V_9 -> V_10 . V_11 . V_12 [ V_5 ] =
F_7 ( & V_7 -> V_8 , V_6 ,
& V_4 -> V_9 -> V_10 . V_11 . V_13 [ V_5 ] ,
V_27 ) ;
if ( ! V_4 -> V_9 -> V_10 . V_11 . V_12 [ V_5 ] ) {
F_1 ( V_4 , V_5 * V_6 ) ;
return NULL ;
}
}
V_4 -> V_20 = V_4 -> V_9 -> V_10 . V_11 . V_12 [ 0 ] ;
return V_4 ;
}
static int F_8 ( struct V_3 * V_4 ,
T_1 V_28 ,
const void * V_29 ,
T_3 V_2 ,
bool V_30 )
{
struct V_22 * V_9 = V_4 -> V_9 ;
T_3 V_31 = 0 ;
while ( V_31 < V_2 ) {
const T_1 V_32 =
( V_28 + V_31 ) / V_6 ;
const T_3 V_33 =
( V_28 + V_31 ) & ( V_6 - 1 ) ;
void * V_34 ;
T_3 V_35 ;
if ( V_9 -> V_26 )
V_34 = F_9 ( V_9 -> V_10 . V_36 . V_37 [ V_32 ] ) ;
else
V_34 = V_9 -> V_10 . V_11 . V_12 [ V_32 + 1 ] ;
if ( V_2 - V_31 > V_6 - V_33 )
V_35 = V_6 - V_33 ;
else
V_35 = V_2 - V_31 ;
if ( V_30 ) {
struct V_38 * V_39 = (struct V_38 * ) V_29 ;
int V_40 ;
V_40 = F_10 ( ( V_25 * ) V_34 + V_33 ,
V_39 , V_35 ) ;
if ( V_40 != 0 ) {
if ( V_9 -> V_26 )
F_11 ( V_9 -> V_10 . V_36 . V_37 [ V_32 ] ) ;
return V_41 ;
}
} else {
memcpy ( ( V_25 * ) V_34 + V_33 ,
( V_25 * ) V_29 + V_31 , V_35 ) ;
}
V_31 += V_35 ;
if ( V_9 -> V_26 )
F_11 ( V_9 -> V_10 . V_36 . V_37 [ V_32 ] ) ;
}
return V_42 ;
}
static int F_12 ( void * V_43 ,
const struct V_3 * V_4 ,
T_1 V_28 ,
T_3 V_2 ,
bool V_30 )
{
struct V_22 * V_9 = V_4 -> V_9 ;
T_3 V_31 = 0 ;
while ( V_31 < V_2 ) {
const T_1 V_32 =
( V_28 + V_31 ) / V_6 ;
const T_3 V_33 =
( V_28 + V_31 ) & ( V_6 - 1 ) ;
void * V_34 ;
T_3 V_35 ;
if ( V_9 -> V_26 )
V_34 = F_9 ( V_9 -> V_10 . V_36 . V_37 [ V_32 ] ) ;
else
V_34 = V_9 -> V_10 . V_11 . V_12 [ V_32 + 1 ] ;
if ( V_2 - V_31 > V_6 - V_33 )
V_35 = V_6 - V_33 ;
else
V_35 = V_2 - V_31 ;
if ( V_30 ) {
struct V_38 * V_39 = V_43 ;
int V_40 ;
V_40 = F_13 ( V_39 , ( V_25 * ) V_34 + V_33 ,
V_35 ) ;
if ( V_40 != 0 ) {
if ( V_9 -> V_26 )
F_11 ( V_9 -> V_10 . V_36 . V_37 [ V_32 ] ) ;
return V_41 ;
}
} else {
memcpy ( ( V_25 * ) V_43 + V_31 ,
( V_25 * ) V_34 + V_33 , V_35 ) ;
}
V_31 += V_35 ;
if ( V_9 -> V_26 )
F_11 ( V_9 -> V_10 . V_36 . V_37 [ V_32 ] ) ;
}
return V_42 ;
}
static int F_14 ( void * V_44 ,
T_1 V_45 ,
void * V_46 ,
T_1 V_47 , struct V_48 * V_48 )
{
T_2 * V_49 ;
T_2 * V_50 ;
struct V_3 * V_51 = V_44 ;
struct V_3 * V_52 = V_46 ;
T_1 V_5 ;
if ( ! V_51 || ! V_45 || ! V_52 ||
! V_47 || ! V_48 )
return V_41 ;
if ( V_48 -> V_53 )
return V_54 ;
V_49 =
F_15 ( V_45 * sizeof( * V_49 ) , V_27 ) ;
if ( ! V_49 )
return V_55 ;
V_50 =
F_15 ( V_47 * sizeof( * V_50 ) , V_27 ) ;
if ( ! V_50 ) {
F_16 ( V_49 ) ;
return V_55 ;
}
for ( V_5 = 0 ; V_5 < V_45 ; V_5 ++ ) {
unsigned long V_56 ;
V_49 [ V_5 ] =
V_51 -> V_9 -> V_10 . V_11 . V_13 [ V_5 ] >> V_57 ;
V_56 = V_49 [ V_5 ] ;
if ( sizeof( V_56 ) > sizeof( * V_49 )
&& V_56 != V_49 [ V_5 ] )
goto V_58;
}
for ( V_5 = 0 ; V_5 < V_47 ; V_5 ++ ) {
unsigned long V_56 ;
V_50 [ V_5 ] =
V_52 -> V_9 -> V_10 . V_11 . V_13 [ V_5 ] >> V_57 ;
V_56 = V_50 [ V_5 ] ;
if ( sizeof( V_56 ) > sizeof( * V_50 )
&& V_56 != V_50 [ V_5 ] )
goto V_58;
}
V_48 -> V_45 = V_45 ;
V_48 -> V_47 = V_47 ;
V_48 -> V_49 = V_49 ;
V_48 -> V_50 = V_50 ;
V_48 -> V_53 = true ;
return V_42 ;
V_58:
F_16 ( V_49 ) ;
F_16 ( V_50 ) ;
return V_41 ;
}
static void F_17 ( struct V_48 * V_48 )
{
if ( V_48 -> V_53 ) {
F_16 ( V_48 -> V_49 ) ;
F_16 ( V_48 -> V_50 ) ;
}
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
}
static int F_18 ( V_25 * V_59 , const struct V_48 * V_48 )
{
memcpy ( V_59 , V_48 -> V_49 ,
V_48 -> V_45 * sizeof( * V_48 -> V_49 ) ) ;
memcpy ( V_59 +
V_48 -> V_45 * sizeof( * V_48 -> V_49 ) ,
V_48 -> V_50 ,
V_48 -> V_47 * sizeof( * V_48 -> V_50 ) ) ;
return V_42 ;
}
static int F_19 ( struct V_3 * V_4 ,
T_1 V_28 ,
const void * V_29 , T_3 V_60 , T_3 V_2 )
{
return F_8 ( V_4 , V_28 ,
( V_25 * ) V_29 + V_60 , V_2 , false ) ;
}
static int F_20 ( void * V_43 ,
T_3 V_61 ,
const struct V_3 * V_4 ,
T_1 V_28 , T_3 V_2 )
{
return F_12 ( ( V_25 * ) V_43 + V_61 ,
V_4 , V_28 , V_2 , false ) ;
}
static int F_21 ( struct V_3 * V_4 ,
T_1 V_28 ,
const void * V_39 ,
T_3 V_60 , T_3 V_2 )
{
return F_8 ( V_4 , V_28 , V_39 , V_2 , true ) ;
}
static int F_22 ( void * V_43 ,
T_3 V_61 ,
const struct V_3 * V_4 ,
T_1 V_28 , T_3 V_2 )
{
return F_12 ( V_43 , V_4 , V_28 , V_2 , true ) ;
}
static struct V_3 * F_23 ( T_1 V_2 )
{
struct V_3 * V_4 ;
T_3 V_62 ;
T_1 V_18 ;
const T_3 V_17 = sizeof( * V_4 ) + sizeof( * ( V_4 -> V_9 ) ) ;
if ( V_2 > V_19 - V_6 )
return NULL ;
V_18 = F_2 ( V_2 , V_6 ) + 1 ;
if ( V_18 > ( V_19 - V_17 ) /
sizeof( * V_4 -> V_9 -> V_10 . V_36 . V_37 ) )
return NULL ;
V_62 = V_18 * sizeof( * V_4 -> V_9 -> V_10 . V_36 . V_37 ) ;
V_4 = F_24 ( V_17 + V_62 , V_27 ) ;
if ( V_4 ) {
V_4 -> V_20 = NULL ;
V_4 -> V_21 = NULL ;
V_4 -> V_9 = (struct V_22 * ) ( V_4 + 1 ) ;
V_4 -> V_9 -> V_26 = true ;
V_4 -> V_9 -> V_23 = NULL ;
V_4 -> V_9 -> V_18 = V_18 ;
V_4 -> V_9 -> V_10 . V_36 . V_63 =
(struct V_37 * * ) ( ( V_25 * ) V_4 + V_17 ) ;
V_4 -> V_9 -> V_10 . V_36 . V_37 =
& V_4 -> V_9 -> V_10 . V_36 . V_63 [ 1 ] ;
}
return V_4 ;
}
static void F_25 ( struct V_3 * V_4 , T_1 V_17 )
{
F_16 ( V_4 ) ;
}
static void F_26 ( struct V_3 * V_51 ,
struct V_3 * V_52 )
{
if ( V_51 -> V_9 -> V_26 ) {
V_51 -> V_9 -> V_23 = & V_51 -> V_9 -> V_64 ;
V_52 -> V_9 -> V_23 = & V_51 -> V_9 -> V_64 ;
F_27 ( V_51 -> V_9 -> V_23 ) ;
}
}
static void F_28 ( struct V_3 * V_51 ,
struct V_3 * V_52 )
{
if ( V_51 -> V_9 -> V_26 ) {
V_51 -> V_9 -> V_23 = NULL ;
V_52 -> V_9 -> V_23 = NULL ;
}
}
static void F_29 ( struct V_3 * V_4 )
{
if ( V_4 -> V_9 -> V_26 )
F_30 ( V_4 -> V_9 -> V_23 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
if ( V_4 -> V_9 -> V_26 )
F_32 ( V_4 -> V_9 -> V_23 ) ;
}
static void F_33 ( struct V_37 * * V_65 ,
T_1 V_18 , bool V_66 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 ; V_5 ++ ) {
if ( V_66 )
F_34 ( V_65 [ V_5 ] ) ;
F_35 ( V_65 [ V_5 ] ) ;
V_65 [ V_5 ] = NULL ;
}
}
static int F_36 ( T_1 V_67 ,
T_1 V_68 ,
struct V_3 * V_51 ,
struct V_3 * V_52 )
{
int V_69 ;
int V_40 = V_42 ;
V_69 = F_37 ( ( V_70 ) V_67 ,
V_51 -> V_9 -> V_18 , 1 ,
V_51 -> V_9 -> V_10 . V_36 . V_63 ) ;
if ( V_69 < V_51 -> V_9 -> V_18 ) {
F_38 ( L_1 ,
V_69 ) ;
F_33 ( V_51 -> V_9 -> V_10 . V_36 . V_63 ,
V_69 , false ) ;
V_40 = V_55 ;
goto V_71;
}
V_69 = F_37 ( ( V_70 ) V_68 ,
V_52 -> V_9 -> V_18 , 1 ,
V_52 -> V_9 -> V_10 . V_36 . V_63 ) ;
if ( V_69 < V_52 -> V_9 -> V_18 ) {
F_38 ( L_2 ,
V_69 ) ;
F_33 ( V_52 -> V_9 -> V_10 . V_36 . V_63 ,
V_69 , false ) ;
F_33 ( V_51 -> V_9 -> V_10 . V_36 . V_63 ,
V_51 -> V_9 -> V_18 , false ) ;
V_40 = V_55 ;
}
V_71:
return V_40 ;
}
static int F_39 ( struct V_72 * V_73 ,
struct V_3 * V_51 ,
struct V_3 * V_52 )
{
T_1 V_67 ;
T_1 V_68 ;
V_67 = V_73 -> V_65 ;
V_68 = V_73 -> V_65 +
V_51 -> V_9 -> V_18 * V_6 ;
return F_36 ( V_67 , V_68 , V_51 ,
V_52 ) ;
}
static void F_40 ( struct V_3 * V_51 ,
struct V_3 * V_52 )
{
F_33 ( V_51 -> V_9 -> V_10 . V_36 . V_63 ,
V_51 -> V_9 -> V_18 , true ) ;
memset ( V_51 -> V_9 -> V_10 . V_36 . V_63 , 0 ,
sizeof( * V_51 -> V_9 -> V_10 . V_36 . V_63 ) *
V_51 -> V_9 -> V_18 ) ;
F_33 ( V_52 -> V_9 -> V_10 . V_36 . V_63 ,
V_52 -> V_9 -> V_18 , true ) ;
memset ( V_52 -> V_9 -> V_10 . V_36 . V_63 , 0 ,
sizeof( * V_52 -> V_9 -> V_10 . V_36 . V_63 ) *
V_52 -> V_9 -> V_18 ) ;
}
static int F_41 ( struct V_3 * V_51 ,
struct V_3 * V_52 )
{
int V_74 ;
if ( ! V_51 -> V_20 || ! V_52 -> V_20 ) {
struct V_37 * V_75 [ 2 ] ;
if ( V_51 -> V_20 != V_52 -> V_20 )
return V_76 ;
if ( V_51 -> V_9 -> V_10 . V_36 . V_63 == NULL ||
* V_51 -> V_9 -> V_10 . V_36 . V_63 == NULL )
return V_77 ;
V_75 [ 0 ] = * V_51 -> V_9 -> V_10 . V_36 . V_63 ;
V_75 [ 1 ] = * V_52 -> V_9 -> V_10 . V_36 . V_63 ;
V_51 -> V_20 = F_42 ( V_75 , 2 , V_78 , V_79 ) ;
if ( V_51 -> V_20 != NULL ) {
V_52 -> V_20 =
(struct V_80 * ) ( ( V_25 * )
V_51 -> V_20 +
V_6 ) ;
V_74 = V_42 ;
} else {
F_43 ( L_3 ) ;
V_74 = V_55 ;
}
} else {
V_74 = V_42 ;
}
return V_74 ;
}
static int F_44 ( T_2 V_81 ,
struct V_3 * V_51 ,
struct V_3 * V_52 )
{
if ( V_51 -> V_20 ) {
if ( V_51 -> V_20 < V_52 -> V_20 )
F_45 ( V_51 -> V_20 ) ;
else
F_45 ( V_52 -> V_20 ) ;
V_51 -> V_20 = NULL ;
V_52 -> V_20 = NULL ;
}
return V_42 ;
}
static struct V_82 * F_46 ( struct V_83 * V_83 ,
struct V_84 V_85 )
{
struct V_82 * V_86 ;
if ( F_47 ( V_85 ) )
return NULL ;
F_48 (entry, &qp_list->head, list_item) {
if ( F_49 ( V_86 -> V_85 , V_85 ) )
return V_86 ;
}
return NULL ;
}
static struct V_87 *
F_50 ( struct V_84 V_85 )
{
struct V_87 * V_86 ;
struct V_82 * V_88 = F_46 ( & V_89 , V_85 ) ;
V_86 = V_88 ? F_51 (
V_88 , struct V_87 , V_88 ) : NULL ;
return V_86 ;
}
static struct V_90 *
F_52 ( struct V_84 V_85 )
{
struct V_90 * V_86 ;
struct V_82 * V_88 = F_46 ( & V_91 , V_85 ) ;
V_86 = V_88 ? F_51 (
V_88 , struct V_90 , V_88 ) : NULL ;
return V_86 ;
}
static int F_53 ( bool V_92 , struct V_84 V_85 )
{
T_2 V_93 = F_54 () ;
struct V_94 V_95 ;
V_95 . V_39 . V_96 . V_97 = F_55 ( V_93 , V_98 ) ;
V_95 . V_39 . V_96 . V_29 = F_55 ( V_99 ,
V_100 ) ;
V_95 . V_39 . V_96 . V_101 = sizeof( V_95 ) - sizeof( V_95 . V_39 . V_96 ) ;
V_95 . V_39 . V_102 . V_103 =
V_92 ? V_104 : V_105 ;
V_95 . V_106 . V_107 = V_93 ;
V_95 . V_106 . V_85 = V_85 ;
return F_56 ( & V_95 . V_39 . V_96 ) ;
}
static struct V_87 *
F_57 ( struct V_84 V_85 ,
T_2 V_108 ,
T_2 V_14 ,
T_1 V_109 ,
T_1 V_110 ,
void * V_51 ,
void * V_52 )
{
int V_74 ;
struct V_87 * V_86 ;
const T_1 V_111 = F_2 ( V_109 , V_6 ) +
F_2 ( V_110 , V_6 ) + 2 ;
if ( F_47 ( V_85 ) ) {
T_2 V_93 = F_54 () ;
V_85 = F_55 ( V_93 , V_112 ) ;
}
V_86 = F_24 ( sizeof( * V_86 ) , V_27 ) ;
if ( V_86 ) {
V_86 -> V_88 . V_108 = V_108 ;
V_86 -> V_88 . V_14 = V_14 ;
V_86 -> V_88 . V_109 = V_109 ;
V_86 -> V_88 . V_110 = V_110 ;
V_86 -> V_88 . V_113 = 0 ;
V_86 -> V_111 = V_111 ;
V_86 -> V_51 = V_51 ;
V_86 -> V_52 = V_52 ;
F_58 ( & V_86 -> V_88 . V_114 ) ;
V_74 = F_59 ( & V_86 -> V_115 ,
V_116 ,
V_85 ) ;
V_86 -> V_88 . V_85 = F_60 ( & V_86 -> V_115 ) ;
if ( ( V_74 != V_42 ) ||
F_46 ( & V_89 , V_86 -> V_88 . V_85 ) ) {
F_43 ( L_4 ,
V_85 . V_117 , V_85 . V_115 , V_74 ) ;
F_16 ( V_86 ) ;
V_86 = NULL ;
}
}
return V_86 ;
}
static void F_61 ( struct V_87 * V_86 )
{
F_17 ( & V_86 -> V_48 ) ;
F_28 ( V_86 -> V_51 , V_86 -> V_52 ) ;
F_1 ( V_86 -> V_51 , V_86 -> V_88 . V_109 ) ;
F_1 ( V_86 -> V_52 , V_86 -> V_88 . V_110 ) ;
F_62 ( & V_86 -> V_115 ) ;
F_16 ( V_86 ) ;
}
static int F_63 ( const struct V_87 * V_86 )
{
struct V_118 * V_119 ;
T_3 V_120 ;
int V_74 ;
if ( ! V_86 || V_86 -> V_111 <= 2 )
return V_41 ;
V_120 = sizeof( * V_119 ) +
( T_3 ) V_86 -> V_111 * sizeof( T_2 ) ;
V_119 = F_15 ( V_120 , V_27 ) ;
if ( ! V_119 )
return V_55 ;
V_119 -> V_96 . V_97 = F_55 ( V_99 ,
V_121 ) ;
V_119 -> V_96 . V_29 = V_122 ;
V_119 -> V_96 . V_101 = V_120 - V_123 ;
V_119 -> V_85 = V_86 -> V_88 . V_85 ;
V_119 -> V_108 = V_86 -> V_88 . V_108 ;
V_119 -> V_14 = V_86 -> V_88 . V_14 ;
V_119 -> V_109 = V_86 -> V_88 . V_109 ;
V_119 -> V_110 = V_86 -> V_88 . V_110 ;
V_119 -> V_111 = V_86 -> V_111 ;
V_74 = F_18 ( ( V_25 * ) V_119 + sizeof( * V_119 ) ,
& V_86 -> V_48 ) ;
if ( V_74 == V_42 )
V_74 = F_64 ( & V_119 -> V_96 ) ;
F_16 ( V_119 ) ;
return V_74 ;
}
static int F_65 ( struct V_84 V_85 )
{
struct V_124 V_125 ;
V_125 . V_96 . V_97 = F_55 ( V_99 ,
V_126 ) ;
V_125 . V_96 . V_29 = V_122 ;
V_125 . V_96 . V_101 = sizeof( V_85 ) ;
V_125 . V_85 = V_85 ;
return F_64 ( & V_125 . V_96 ) ;
}
static void F_66 ( struct V_83 * V_83 , struct V_82 * V_86 )
{
if ( V_86 )
F_67 ( & V_86 -> V_114 , & V_83 -> V_127 ) ;
}
static void F_68 ( struct V_83 * V_83 ,
struct V_82 * V_86 )
{
if ( V_86 )
F_69 ( & V_86 -> V_114 ) ;
}
static int F_70 ( struct V_84 V_85 )
{
int V_74 ;
struct V_87 * V_86 ;
T_2 V_113 = ~ 0 ;
F_30 ( & V_89 . V_23 ) ;
V_86 = F_50 ( V_85 ) ;
if ( ! V_86 ) {
F_32 ( & V_89 . V_23 ) ;
return V_128 ;
}
if ( V_86 -> V_88 . V_14 & V_129 ) {
V_74 = V_42 ;
if ( V_86 -> V_88 . V_113 > 1 ) {
V_74 = F_53 ( false , V_85 ) ;
}
} else {
V_74 = F_65 ( V_85 ) ;
if ( V_74 < V_42 ) {
F_32 ( & V_89 . V_23 ) ;
return V_74 ;
}
}
V_86 -> V_88 . V_113 -- ;
if ( V_86 -> V_88 . V_113 == 0 )
F_68 ( & V_89 , & V_86 -> V_88 ) ;
if ( V_86 )
V_113 = V_86 -> V_88 . V_113 ;
F_32 ( & V_89 . V_23 ) ;
if ( V_113 == 0 )
F_61 ( V_86 ) ;
return V_74 ;
}
static int F_71 ( struct V_84 * V_85 ,
struct V_3 * * V_51 ,
T_1 V_109 ,
struct V_3 * * V_52 ,
T_1 V_110 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 )
{
const T_1 V_45 =
F_2 ( V_109 , V_6 ) + 1 ;
const T_1 V_47 =
F_2 ( V_110 , V_6 ) + 1 ;
void * V_131 = NULL ;
void * V_132 = NULL ;
int V_74 ;
struct V_87 * V_133 = NULL ;
if ( V_130 != V_134 )
return V_135 ;
F_30 ( & V_89 . V_23 ) ;
V_133 = F_50 ( * V_85 ) ;
if ( V_133 ) {
if ( V_133 -> V_88 . V_14 & V_129 ) {
if ( V_133 -> V_88 . V_113 > 1 ) {
F_72 ( L_5 ) ;
V_74 = V_77 ;
goto V_136;
}
if ( V_133 -> V_88 . V_109 != V_110 ||
V_133 -> V_88 . V_110 !=
V_109 ||
V_133 -> V_88 . V_14 !=
( V_14 & ~ V_137 ) ) {
F_72 ( L_6 ) ;
V_74 = V_76 ;
goto V_136;
}
V_74 = F_53 ( true , * V_85 ) ;
if ( V_74 < V_42 )
goto V_136;
V_131 = V_133 -> V_52 ;
V_132 = V_133 -> V_51 ;
goto V_71;
}
V_74 = V_54 ;
goto V_136;
}
V_131 = F_5 ( V_109 , V_14 ) ;
if ( ! V_131 ) {
F_43 ( L_7 ) ;
V_74 = V_55 ;
goto error;
}
V_132 = F_5 ( V_110 , V_14 ) ;
if ( ! V_132 ) {
F_43 ( L_8 ) ;
V_74 = V_55 ;
goto error;
}
V_133 = F_57 ( * V_85 , V_108 , V_14 ,
V_109 , V_110 ,
V_131 , V_132 ) ;
if ( ! V_133 ) {
F_43 ( L_9 , V_138 ) ;
V_74 = V_55 ;
goto error;
}
V_74 = F_14 ( V_131 , V_45 , V_132 ,
V_47 ,
& V_133 -> V_48 ) ;
if ( V_74 < V_42 ) {
F_43 ( L_10 ) ;
goto error;
}
if ( V_133 -> V_88 . V_14 & V_129 ) {
T_2 V_93 = F_54 () ;
if ( V_133 -> V_88 . V_85 . V_117 != V_93 ||
( V_133 -> V_88 . V_108 != V_112 &&
V_133 -> V_88 . V_108 != V_93 ) ) {
V_74 = V_135 ;
goto error;
}
if ( V_133 -> V_88 . V_14 & V_137 ) {
V_74 = V_128 ;
goto error;
}
} else {
V_74 = F_63 ( V_133 ) ;
if ( V_74 < V_42 ) {
F_43 ( L_11 , V_74 ) ;
goto error;
}
}
F_26 ( (struct V_3 * ) V_131 ,
(struct V_3 * ) V_132 ) ;
F_66 ( & V_89 , & V_133 -> V_88 ) ;
V_71:
V_133 -> V_88 . V_113 ++ ;
* V_85 = V_133 -> V_88 . V_85 ;
* V_51 = (struct V_3 * ) V_131 ;
* V_52 = (struct V_3 * ) V_132 ;
if ( ( V_133 -> V_88 . V_14 & V_129 ) &&
V_133 -> V_88 . V_113 == 1 ) {
F_73 ( ( * V_51 ) -> V_20 , * V_85 ) ;
F_73 ( ( * V_52 ) -> V_20 , * V_85 ) ;
}
F_32 ( & V_89 . V_23 ) ;
return V_42 ;
error:
F_32 ( & V_89 . V_23 ) ;
if ( V_133 ) {
F_61 ( V_133 ) ;
} else {
F_1 ( V_131 , V_109 ) ;
F_1 ( V_132 , V_110 ) ;
}
return V_74 ;
V_136:
F_32 ( & V_89 . V_23 ) ;
return V_74 ;
}
static int F_74 ( struct V_84 V_85 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
T_1 V_109 ,
T_1 V_110 ,
struct V_72 * V_73 ,
struct V_139 * V_117 ,
T_4 V_140 ,
void * V_141 , struct V_90 * * V_142 )
{
struct V_90 * V_86 = NULL ;
const T_2 V_93 = F_75 ( V_117 ) ;
bool V_143 = V_14 & V_129 ;
int V_74 ;
T_1 V_144 ;
T_1 V_145 ;
if ( V_14 & V_137 )
return V_128 ;
if ( V_85 . V_117 != V_93 && V_85 . V_117 != V_108 )
return V_135 ;
if ( F_76 ( V_93 ) && F_76 ( V_108 ) )
return V_146 ;
if ( V_143 && V_108 != V_112 && V_93 != V_108 )
return V_135 ;
V_86 = F_24 ( sizeof( * V_86 ) , V_147 ) ;
if ( ! V_86 )
return V_55 ;
if ( F_75 ( V_117 ) == V_148 && ! V_143 ) {
V_144 = V_110 ;
V_145 = V_109 ;
} else {
V_144 = V_109 ;
V_145 = V_110 ;
}
V_86 -> V_88 . V_85 = V_85 ;
V_86 -> V_88 . V_108 = V_108 ;
V_86 -> V_88 . V_14 = V_14 ;
V_86 -> V_88 . V_109 = V_144 ;
V_86 -> V_88 . V_110 = V_145 ;
V_86 -> V_88 . V_113 = 1 ;
V_86 -> V_149 = V_93 ;
V_86 -> V_150 = V_112 ;
V_86 -> V_151 = V_152 ;
V_86 -> V_153 =
! ! ( V_117 -> V_130 & V_154 ) ;
V_86 -> V_155 =
! ! ( V_130 & V_156 ) ;
V_86 -> V_157 = false ;
V_86 -> V_140 = V_140 ;
V_86 -> V_141 = V_141 ;
V_86 -> V_51 = F_23 ( V_144 ) ;
if ( V_86 -> V_51 == NULL ) {
V_74 = V_55 ;
goto error;
}
V_86 -> V_52 = F_23 ( V_145 ) ;
if ( V_86 -> V_52 == NULL ) {
V_74 = V_55 ;
goto error;
}
F_26 ( V_86 -> V_51 , V_86 -> V_52 ) ;
F_58 ( & V_86 -> V_88 . V_114 ) ;
if ( V_143 ) {
V_25 * V_158 ;
V_86 -> V_159 = F_77 ( F_78 ( V_86 -> V_88 ) ,
V_6 , V_27 ) ;
if ( V_86 -> V_159 == NULL ) {
V_74 = V_55 ;
goto error;
}
V_86 -> V_151 = V_160 ;
V_86 -> V_51 -> V_20 = V_86 -> V_159 ;
V_158 = ( V_25 * ) V_86 -> V_159 + V_6 *
( F_2 ( V_86 -> V_88 . V_109 , V_6 ) + 1 ) ;
V_86 -> V_52 -> V_20 = (struct V_80 * ) V_158 ;
} else if ( V_73 ) {
V_74 = F_39 ( V_73 ,
V_86 -> V_51 ,
V_86 -> V_52 ) ;
if ( V_74 < V_42 )
goto error;
V_86 -> V_151 = V_160 ;
} else {
V_86 -> V_151 = V_161 ;
}
F_66 ( & V_91 , & V_86 -> V_88 ) ;
if ( V_142 != NULL )
* V_142 = V_86 ;
V_74 = F_59 ( & V_86 -> V_115 ,
V_162 ,
V_85 ) ;
if ( V_74 != V_42 ) {
F_43 ( L_4 ,
V_85 . V_117 , V_85 . V_115 , V_74 ) ;
goto error;
}
V_86 -> V_88 . V_85 = F_60 ( & V_86 -> V_115 ) ;
if ( V_143 ) {
F_73 ( V_86 -> V_51 -> V_20 ,
V_86 -> V_88 . V_85 ) ;
F_73 ( V_86 -> V_52 -> V_20 ,
V_86 -> V_88 . V_85 ) ;
}
F_79 ( V_117 , V_86 -> V_88 . V_85 ) ;
return V_42 ;
error:
if ( V_86 != NULL ) {
F_25 ( V_86 -> V_51 , V_144 ) ;
F_25 ( V_86 -> V_52 , V_145 ) ;
F_16 ( V_86 ) ;
}
return V_74 ;
}
static int F_80 ( bool V_92 ,
struct V_84 V_85 ,
T_2 V_163 ,
T_2 V_107 )
{
int V_164 ;
struct V_94 V_95 ;
if ( F_47 ( V_85 ) || V_163 == V_112 ||
V_107 == V_112 )
return V_41 ;
V_95 . V_39 . V_96 . V_97 = F_55 ( V_107 , V_98 ) ;
V_95 . V_39 . V_96 . V_29 = F_55 ( V_99 ,
V_100 ) ;
V_95 . V_39 . V_96 . V_101 = sizeof( V_95 ) - sizeof( V_95 . V_39 . V_96 ) ;
V_95 . V_39 . V_102 . V_103 = V_92 ?
V_104 : V_105 ;
V_95 . V_106 . V_85 = V_85 ;
V_95 . V_106 . V_107 = V_163 ;
V_164 = F_81 ( V_99 ,
& V_95 . V_39 . V_96 , false ) ;
if ( V_164 < V_42 )
F_43 ( L_12 ,
V_92 ? L_13 : L_14 , V_107 ) ;
return V_164 ;
}
static int F_82 ( struct V_90 * V_86 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
T_1 V_109 ,
T_1 V_110 ,
struct V_72 * V_73 ,
struct V_139 * V_117 ,
T_4 V_140 ,
void * V_141 ,
struct V_90 * * V_142 )
{
const T_2 V_93 = F_75 ( V_117 ) ;
bool V_143 = V_14 & V_129 ;
int V_74 ;
if ( V_86 -> V_151 != V_161 &&
V_86 -> V_151 != V_160 )
return V_77 ;
if ( V_143 ) {
if ( ! ( V_86 -> V_88 . V_14 & V_129 ) ||
V_93 != V_86 -> V_149 ) {
return V_41 ;
}
} else if ( V_93 == V_86 -> V_149 ||
V_93 == V_86 -> V_150 ) {
return V_54 ;
}
if ( F_76 ( V_93 ) &&
F_76 ( V_86 -> V_149 ) )
return V_146 ;
if ( ( V_117 -> V_130 & V_154 ) &&
! V_86 -> V_155 )
return V_135 ;
if ( V_86 -> V_153 &&
( ! ( V_130 & V_156 ) ) )
return V_135 ;
if ( V_86 -> V_88 . V_108 != V_112 && V_86 -> V_88 . V_108 != V_93 )
return V_135 ;
if ( V_86 -> V_149 == V_148 ) {
if ( ! F_83 ( V_117 ) )
return V_165 ;
} else if ( V_93 == V_148 ) {
struct V_139 * V_166 ;
bool V_167 ;
V_166 = F_84 ( V_86 -> V_149 ) ;
V_167 = F_83 ( V_166 ) ;
F_85 ( V_166 ) ;
if ( ! V_167 )
return V_165 ;
}
if ( ( V_86 -> V_88 . V_14 & ~ V_168 ) != ( V_14 & ~ V_169 ) )
return V_76 ;
if ( V_93 != V_148 ) {
if ( V_86 -> V_88 . V_109 != V_109 ||
V_86 -> V_88 . V_110 != V_110 ) {
return V_76 ;
}
} else if ( V_86 -> V_88 . V_109 != V_110 ||
V_86 -> V_88 . V_110 != V_109 ) {
return V_76 ;
}
if ( V_93 != V_148 ) {
if ( V_86 -> V_151 != V_161 )
return V_41 ;
if ( V_73 != NULL ) {
V_74 = F_39 ( V_73 ,
V_86 -> V_51 ,
V_86 -> V_52 ) ;
if ( V_74 < V_42 )
return V_74 ;
V_86 -> V_151 = V_170 ;
} else {
V_86 -> V_151 = V_171 ;
}
} else if ( V_86 -> V_151 == V_161 ) {
return V_77 ;
} else {
V_86 -> V_151 = V_170 ;
}
if ( V_86 -> V_151 == V_170 ) {
V_74 =
F_80 ( true , V_86 -> V_88 . V_85 , V_93 ,
V_86 -> V_149 ) ;
if ( V_74 < V_42 )
F_43 ( L_15 ,
V_86 -> V_149 , V_86 -> V_88 . V_85 . V_117 ,
V_86 -> V_88 . V_85 . V_115 ) ;
}
V_86 -> V_150 = V_93 ;
V_86 -> V_88 . V_113 ++ ;
if ( V_140 ) {
V_86 -> V_140 = V_140 ;
V_86 -> V_141 = V_141 ;
}
if ( ! V_143 )
F_79 ( V_117 , V_86 -> V_88 . V_85 ) ;
if ( V_142 != NULL )
* V_142 = V_86 ;
return V_42 ;
}
static int F_86 ( struct V_84 V_85 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
T_1 V_109 ,
T_1 V_110 ,
struct V_72 * V_73 ,
struct V_139 * V_117 ,
T_4 V_140 ,
void * V_141 ,
struct V_90 * * V_142 ,
bool * V_172 )
{
const T_2 V_93 = F_75 ( V_117 ) ;
bool V_173 ;
struct V_90 * V_86 = NULL ;
bool V_143 = V_14 & V_129 ;
int V_74 ;
if ( F_47 ( V_85 ) ||
( V_14 & ~ V_174 ) || V_143 ||
! ( V_109 || V_110 ) ||
! V_117 || V_93 == V_112 ||
V_85 . V_117 == V_112 ) {
return V_41 ;
}
if ( V_73 && ! F_87 ( V_73 ) )
return V_41 ;
F_30 ( & V_91 . V_23 ) ;
if ( ! V_143 && F_88 ( V_117 , V_85 ) ) {
F_72 ( L_16 ,
V_93 , V_85 . V_117 , V_85 . V_115 ) ;
F_32 ( & V_91 . V_23 ) ;
return V_54 ;
}
if ( V_85 . V_115 != V_112 )
V_86 = F_52 ( V_85 ) ;
if ( ! V_86 ) {
V_173 = true ;
V_74 =
F_74 ( V_85 , V_108 , V_14 , V_130 ,
V_109 , V_110 , V_73 ,
V_117 , V_140 , V_141 , V_142 ) ;
} else {
V_173 = false ;
V_74 =
F_82 ( V_86 , V_108 , V_14 , V_130 ,
V_109 , V_110 , V_73 ,
V_117 , V_140 , V_141 , V_142 ) ;
}
F_32 ( & V_91 . V_23 ) ;
if ( V_172 )
* V_172 = ( V_93 == V_148 ) &&
! ( V_173 && V_143 ) ;
return V_74 ;
}
static int F_89 ( struct V_84 * V_85 ,
struct V_3 * * V_51 ,
T_1 V_109 ,
struct V_3 * * V_52 ,
T_1 V_110 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
T_4 V_140 ,
void * V_141 )
{
struct V_84 V_175 ;
struct V_139 * V_117 ;
struct V_90 * V_86 ;
int V_74 ;
bool V_172 ;
if ( F_47 ( * V_85 ) ) {
V_175 = F_55 (
V_148 , V_112 ) ;
} else
V_175 = * V_85 ;
V_117 = F_84 ( V_148 ) ;
V_86 = NULL ;
V_74 =
F_86 ( V_175 , V_108 , V_14 , V_130 ,
V_109 , V_110 , NULL , V_117 ,
V_140 , V_141 , & V_86 , & V_172 ) ;
if ( V_74 == V_42 ) {
if ( V_172 ) {
* V_51 = V_86 -> V_52 ;
* V_52 = V_86 -> V_51 ;
} else {
* V_51 = V_86 -> V_51 ;
* V_52 = V_86 -> V_52 ;
}
* V_85 = F_60 ( & V_86 -> V_115 ) ;
} else {
* V_85 = V_176 ;
F_72 ( L_17 ,
V_74 ) ;
}
F_85 ( V_117 ) ;
return V_74 ;
}
int F_90 ( struct V_84 * V_85 ,
struct V_3 * * V_51 ,
T_1 V_109 ,
struct V_3 * * V_52 ,
T_1 V_110 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
bool V_177 ,
T_4 V_140 ,
void * V_141 )
{
if ( ! V_85 || ! V_51 || ! V_52 ||
( ! V_109 && ! V_110 ) || ( V_14 & ~ V_174 ) )
return V_41 ;
if ( V_177 ) {
return F_71 ( V_85 , V_51 ,
V_109 , V_52 ,
V_110 , V_108 ,
V_14 , V_130 ) ;
} else {
return F_89 ( V_85 , V_51 ,
V_109 , V_52 ,
V_110 , V_108 , V_14 ,
V_130 , V_140 , V_141 ) ;
}
}
static int F_91 ( struct V_84 V_85 )
{
int V_74 ;
struct V_139 * V_117 ;
V_117 = F_84 ( V_148 ) ;
V_74 = F_92 ( V_85 , V_117 ) ;
F_85 ( V_117 ) ;
return V_74 ;
}
static int F_93 ( struct V_84 V_85 , bool V_177 )
{
if ( F_47 ( V_85 ) )
return V_41 ;
if ( V_177 )
return F_70 ( V_85 ) ;
else
return F_91 ( V_85 ) ;
}
static struct V_82 * F_94 ( struct V_83 * V_83 )
{
if ( ! F_95 ( & V_83 -> V_127 ) ) {
struct V_82 * V_86 =
F_96 ( & V_83 -> V_127 , struct V_82 ,
V_114 ) ;
return V_86 ;
}
return NULL ;
}
void F_97 ( void )
{
struct V_82 * V_86 ;
struct V_90 * V_178 ;
F_30 ( & V_91 . V_23 ) ;
while ( ( V_86 = F_94 ( & V_91 ) ) ) {
V_178 = (struct V_90 * ) V_86 ;
F_68 ( & V_91 , V_86 ) ;
F_16 ( V_178 ) ;
}
F_32 ( & V_91 . V_23 ) ;
}
int F_98 ( struct V_84 V_85 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
T_1 V_109 ,
T_1 V_110 ,
struct V_72 * V_73 ,
struct V_139 * V_117 )
{
return F_86 ( V_85 , V_108 , V_14 , V_130 ,
V_109 , V_110 ,
V_73 , V_117 , NULL , NULL , NULL , NULL ) ;
}
int F_99 ( struct V_84 V_85 ,
T_1 V_67 ,
T_1 V_68 ,
struct V_139 * V_117 )
{
struct V_90 * V_86 ;
int V_74 ;
const T_2 V_93 = F_75 ( V_117 ) ;
if ( F_47 ( V_85 ) || ! V_117 ||
V_93 == V_112 )
return V_41 ;
if ( V_67 == 0 || V_68 == 0 )
return V_41 ;
F_30 ( & V_91 . V_23 ) ;
if ( ! F_88 ( V_117 , V_85 ) ) {
F_43 ( L_18 ,
V_93 , V_85 . V_117 , V_85 . V_115 ) ;
V_74 = V_128 ;
goto V_71;
}
V_86 = F_52 ( V_85 ) ;
if ( ! V_86 ) {
V_74 = V_128 ;
goto V_71;
}
if ( V_86 -> V_149 != V_93 &&
( V_86 -> V_149 != V_148 ||
V_86 -> V_150 != V_93 ) ) {
V_74 = V_179 ;
goto V_71;
}
if ( V_86 -> V_151 != V_161 &&
V_86 -> V_151 != V_171 ) {
V_74 = V_77 ;
goto V_71;
}
V_74 = F_36 ( V_67 , V_68 ,
V_86 -> V_51 , V_86 -> V_52 ) ;
if ( V_74 < V_42 )
goto V_71;
V_74 = F_41 ( V_86 -> V_51 , V_86 -> V_52 ) ;
if ( V_74 < V_42 ) {
F_40 ( V_86 -> V_51 ,
V_86 -> V_52 ) ;
goto V_71;
}
if ( V_86 -> V_151 == V_161 )
V_86 -> V_151 = V_160 ;
else
V_86 -> V_151 = V_170 ;
V_86 -> V_157 = true ;
if ( V_86 -> V_151 == V_170 ) {
V_74 =
F_80 ( true , V_85 , V_93 , V_86 -> V_149 ) ;
if ( V_74 < V_42 ) {
F_43 ( L_15 ,
V_86 -> V_149 , V_86 -> V_88 . V_85 . V_117 ,
V_86 -> V_88 . V_85 . V_115 ) ;
}
}
V_74 = V_42 ;
V_71:
F_32 ( & V_91 . V_23 ) ;
return V_74 ;
}
static void F_100 ( struct V_90 * V_86 )
{
V_86 -> V_51 -> V_21 = NULL ;
V_86 -> V_52 -> V_21 = NULL ;
}
int F_92 ( struct V_84 V_85 , struct V_139 * V_117 )
{
struct V_90 * V_86 ;
const T_2 V_93 = F_75 ( V_117 ) ;
T_2 V_107 ;
bool V_143 = false ;
int V_74 ;
if ( F_47 ( V_85 ) || ! V_117 ||
V_93 == V_112 ) {
return V_41 ;
}
F_30 ( & V_91 . V_23 ) ;
if ( ! F_88 ( V_117 , V_85 ) ) {
F_72 ( L_18 ,
V_93 , V_85 . V_117 , V_85 . V_115 ) ;
V_74 = V_128 ;
goto V_71;
}
V_86 = F_52 ( V_85 ) ;
if ( ! V_86 ) {
F_72 ( L_19 ,
V_93 , V_85 . V_117 , V_85 . V_115 ) ;
V_74 = V_128 ;
goto V_71;
}
if ( V_93 != V_86 -> V_149 && V_93 != V_86 -> V_150 ) {
V_74 = V_180 ;
goto V_71;
}
if ( V_93 == V_86 -> V_149 ) {
V_107 = V_86 -> V_150 ;
V_86 -> V_149 = V_112 ;
} else {
V_107 = V_86 -> V_149 ;
V_86 -> V_150 = V_112 ;
}
V_86 -> V_88 . V_113 -- ;
V_143 = V_86 -> V_88 . V_14 & V_129 ;
if ( V_93 != V_148 ) {
bool V_181 ;
F_29 ( V_86 -> V_51 ) ;
V_181 = V_86 -> V_51 -> V_20 ||
V_86 -> V_52 -> V_20 ;
if ( F_101 ( V_86 ) ) {
V_74 =
F_44 ( V_182 ,
V_86 -> V_51 ,
V_86 -> V_52 ) ;
if ( V_74 < V_42 )
F_43 ( L_20 ,
V_85 . V_117 , V_85 . V_115 ,
V_74 ) ;
F_40 ( V_86 -> V_51 ,
V_86 -> V_52 ) ;
}
if ( ! V_181 )
F_100 ( V_86 ) ;
F_31 ( V_86 -> V_51 ) ;
if ( ! V_181 && V_86 -> V_140 )
V_86 -> V_140 ( V_86 -> V_141 ) ;
} else {
if ( V_86 -> V_140 ) {
V_86 -> V_140 = NULL ;
V_86 -> V_141 = NULL ;
}
}
if ( V_86 -> V_88 . V_113 == 0 ) {
F_68 ( & V_91 , & V_86 -> V_88 ) ;
if ( V_143 )
F_16 ( V_86 -> V_159 ) ;
F_28 ( V_86 -> V_51 , V_86 -> V_52 ) ;
F_25 ( V_86 -> V_51 , V_86 -> V_88 . V_109 ) ;
F_25 ( V_86 -> V_52 , V_86 -> V_88 . V_110 ) ;
F_62 ( & V_86 -> V_115 ) ;
F_16 ( V_86 ) ;
F_102 ( V_117 , V_85 ) ;
} else {
F_80 ( false , V_85 , V_93 , V_107 ) ;
if ( V_93 == V_148 &&
F_101 ( V_86 ) ) {
V_86 -> V_151 = V_183 ;
} else {
V_86 -> V_151 = V_184 ;
}
if ( ! V_143 )
F_102 ( V_117 , V_85 ) ;
}
V_74 = V_42 ;
V_71:
F_32 ( & V_91 . V_23 ) ;
return V_74 ;
}
int F_103 ( struct V_84 V_85 ,
struct V_139 * V_117 ,
T_1 V_185 )
{
struct V_90 * V_86 ;
const T_2 V_93 = F_75 ( V_117 ) ;
bool V_143 = false ;
int V_74 ;
if ( F_47 ( V_85 ) || ! V_117 ||
V_93 == V_112 )
return V_41 ;
F_30 ( & V_91 . V_23 ) ;
if ( ! F_88 ( V_117 , V_85 ) ) {
F_72 ( L_18 ,
V_93 , V_85 . V_117 , V_85 . V_115 ) ;
V_74 = V_128 ;
goto V_71;
}
V_86 = F_52 ( V_85 ) ;
if ( ! V_86 ) {
F_72 ( L_21 ,
V_93 , V_85 . V_117 , V_85 . V_115 ) ;
V_74 = V_128 ;
goto V_71;
}
if ( V_93 != V_86 -> V_149 && V_93 != V_86 -> V_150 ) {
V_74 = V_180 ;
goto V_71;
}
V_143 = V_86 -> V_88 . V_14 & V_129 ;
V_74 = V_42 ;
if ( V_93 != V_148 ) {
struct V_72 V_73 ;
V_73 . V_65 = V_185 ;
V_73 . V_186 = F_78 ( V_86 -> V_88 ) ;
F_29 ( V_86 -> V_51 ) ;
F_100 ( V_86 ) ;
V_74 =
F_39 ( & V_73 ,
V_86 -> V_51 ,
V_86 -> V_52 ) ;
F_31 ( V_86 -> V_51 ) ;
if ( V_74 == V_42 ) {
V_86 -> V_151 ++ ;
if ( V_86 -> V_140 )
V_86 -> V_140 ( V_86 -> V_141 ) ;
}
}
V_71:
F_32 ( & V_91 . V_23 ) ;
return V_74 ;
}
static int F_104 ( struct V_90 * V_86 )
{
int V_74 ;
if ( V_86 -> V_51 -> V_21 != NULL &&
V_86 -> V_52 -> V_21 != NULL ) {
return V_42 ;
}
if ( NULL == V_86 -> V_51 -> V_20 ||
NULL == V_86 -> V_52 -> V_20 ) {
V_74 = F_41 ( V_86 -> V_51 , V_86 -> V_52 ) ;
if ( V_74 < V_42 )
return V_74 ;
}
memcpy ( & V_86 -> V_187 , V_86 -> V_51 -> V_20 ,
sizeof( V_86 -> V_187 ) ) ;
V_86 -> V_51 -> V_21 = & V_86 -> V_187 ;
memcpy ( & V_86 -> V_188 , V_86 -> V_52 -> V_20 ,
sizeof( V_86 -> V_188 ) ) ;
V_86 -> V_52 -> V_21 = & V_86 -> V_188 ;
return V_42 ;
}
int F_105 ( struct V_84 V_85 ,
struct V_139 * V_117 ,
T_2 V_81 )
{
struct V_90 * V_86 ;
const T_2 V_93 = F_75 ( V_117 ) ;
bool V_143 = false ;
int V_74 ;
if ( F_47 ( V_85 ) || ! V_117 ||
V_93 == V_112 )
return V_41 ;
F_30 ( & V_91 . V_23 ) ;
if ( ! F_88 ( V_117 , V_85 ) ) {
F_72 ( L_18 ,
V_93 , V_85 . V_117 , V_85 . V_115 ) ;
V_74 = V_128 ;
goto V_71;
}
V_86 = F_52 ( V_85 ) ;
if ( ! V_86 ) {
F_72 ( L_21 ,
V_93 , V_85 . V_117 , V_85 . V_115 ) ;
V_74 = V_128 ;
goto V_71;
}
if ( V_93 != V_86 -> V_149 && V_93 != V_86 -> V_150 ) {
V_74 = V_180 ;
goto V_71;
}
V_143 = V_86 -> V_88 . V_14 & V_129 ;
if ( V_93 != V_148 ) {
F_29 ( V_86 -> V_51 ) ;
V_74 = F_104 ( V_86 ) ;
if ( V_74 < V_42 )
F_43 ( L_22 ,
V_85 . V_117 , V_85 . V_115 , V_74 ) ;
F_44 ( V_81 , V_86 -> V_51 , V_86 -> V_52 ) ;
F_40 ( V_86 -> V_51 ,
V_86 -> V_52 ) ;
V_86 -> V_151 -- ;
F_31 ( V_86 -> V_51 ) ;
}
V_74 = V_42 ;
V_71:
F_32 ( & V_91 . V_23 ) ;
return V_74 ;
}
void F_106 ( void )
{
struct V_82 * V_86 ;
struct V_87 * V_189 ;
F_30 ( & V_89 . V_23 ) ;
while ( ( V_86 = F_94 ( & V_89 ) ) ) {
V_189 = (struct V_87 * ) V_86 ;
if ( ! ( V_86 -> V_14 & V_129 ) )
F_65 ( V_86 -> V_85 ) ;
V_86 -> V_113 = 0 ;
F_68 ( & V_89 , V_86 ) ;
F_61 ( V_189 ) ;
}
F_32 ( & V_89 . V_23 ) ;
}
static void F_107 ( const struct V_190 * V_191 )
{
F_29 ( V_191 -> V_51 ) ;
}
static void F_108 ( const struct V_190 * V_191 )
{
F_31 ( V_191 -> V_51 ) ;
}
static int F_109 ( struct V_3 * V_51 ,
struct V_3 * V_52 )
{
int V_74 ;
if ( NULL == V_51 -> V_20 || NULL == V_52 -> V_20 ) {
V_74 = F_41 ( V_51 , V_52 ) ;
if ( V_74 < V_42 )
return ( V_51 -> V_21 &&
V_52 -> V_21 ) ?
V_192 :
V_180 ;
}
return V_42 ;
}
static int F_110 ( const struct V_190 * V_191 ,
struct V_80 * * V_193 ,
struct V_80 * * V_194 )
{
int V_74 ;
V_74 = F_109 ( V_191 -> V_51 , V_191 -> V_52 ) ;
if ( V_74 == V_42 ) {
* V_193 = V_191 -> V_51 -> V_20 ;
* V_194 = V_191 -> V_52 -> V_20 ;
} else if ( V_191 -> V_51 -> V_21 &&
V_191 -> V_52 -> V_21 ) {
* V_193 = V_191 -> V_51 -> V_21 ;
* V_194 = V_191 -> V_52 -> V_21 ;
V_74 = V_42 ;
}
return V_74 ;
}
static int F_111 ( void * V_141 )
{
struct V_190 * V_191 = (struct V_190 * ) V_141 ;
F_107 ( V_191 ) ;
while ( V_191 -> V_195 > 0 ) {
V_191 -> V_195 -- ;
V_191 -> V_196 ++ ;
F_112 ( & V_191 -> V_103 ) ;
}
F_108 ( V_191 ) ;
return V_42 ;
}
static bool F_113 ( struct V_190 * V_191 )
{
unsigned int V_196 ;
V_191 -> V_195 ++ ;
V_196 = V_191 -> V_196 ;
F_108 ( V_191 ) ;
F_114 ( V_191 -> V_103 , V_196 != V_191 -> V_196 ) ;
F_107 ( V_191 ) ;
return true ;
}
static T_5 F_115 ( struct V_3 * V_51 ,
struct V_3 * V_52 ,
const T_1 V_197 ,
const void * V_198 ,
T_3 V_199 ,
T_6 V_200 )
{
T_7 V_201 ;
T_1 V_202 ;
T_3 V_203 ;
T_5 V_74 ;
V_74 = F_109 ( V_51 , V_52 ) ;
if ( F_116 ( V_74 != V_42 ) )
return V_74 ;
V_201 = F_117 ( V_51 -> V_20 ,
V_52 -> V_20 ,
V_197 ) ;
if ( V_201 == 0 )
return V_204 ;
if ( V_201 < V_42 )
return ( T_5 ) V_201 ;
V_203 = ( T_3 ) ( V_201 > V_199 ? V_199 : V_201 ) ;
V_202 = F_118 ( V_51 -> V_20 ) ;
if ( F_119 ( V_202 + V_203 < V_197 ) ) {
V_74 = V_200 ( V_51 , V_202 , V_198 , 0 , V_203 ) ;
} else {
const T_3 V_158 = ( T_3 ) ( V_197 - V_202 ) ;
V_74 = V_200 ( V_51 , V_202 , V_198 , 0 , V_158 ) ;
if ( V_74 >= V_42 )
V_74 = V_200 ( V_51 , 0 , V_198 , V_158 ,
V_203 - V_158 ) ;
}
if ( V_74 < V_42 )
return V_74 ;
F_120 ( V_51 -> V_20 , V_203 ,
V_197 ) ;
return V_203 ;
}
static T_5 F_121 ( struct V_3 * V_51 ,
struct V_3 * V_52 ,
const T_1 V_205 ,
void * V_198 ,
T_3 V_199 ,
T_8 V_206 ,
bool V_207 )
{
T_7 V_208 ;
T_1 V_127 ;
T_3 V_209 ;
T_5 V_74 ;
V_74 = F_109 ( V_51 , V_52 ) ;
if ( F_116 ( V_74 != V_42 ) )
return V_74 ;
V_208 = F_122 ( V_52 -> V_20 ,
V_51 -> V_20 ,
V_205 ) ;
if ( V_208 == 0 )
return V_210 ;
if ( V_208 < V_42 )
return ( T_5 ) V_208 ;
V_209 = ( T_3 ) ( V_208 > V_199 ? V_199 : V_208 ) ;
V_127 = F_123 ( V_51 -> V_20 ) ;
if ( F_119 ( V_127 + V_209 < V_205 ) ) {
V_74 = V_206 ( V_198 , 0 , V_52 , V_127 , V_209 ) ;
} else {
const T_3 V_158 = ( T_3 ) ( V_205 - V_127 ) ;
V_74 = V_206 ( V_198 , 0 , V_52 , V_127 , V_158 ) ;
if ( V_74 >= V_42 )
V_74 = V_206 ( V_198 , V_158 , V_52 , 0 ,
V_209 - V_158 ) ;
}
if ( V_74 < V_42 )
return V_74 ;
if ( V_207 )
F_124 ( V_51 -> V_20 ,
V_209 , V_205 ) ;
return V_209 ;
}
int F_125 ( struct V_190 * * V_191 ,
struct V_84 * V_85 ,
T_1 V_211 ,
T_1 V_212 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 )
{
struct V_190 * V_213 ;
int V_69 ;
struct V_84 V_29 = V_176 ;
struct V_84 V_97 = F_55 ( V_108 , V_112 ) ;
enum V_214 V_215 ;
T_4 V_140 ;
void * V_141 ;
if ( V_211 + V_212 < V_216 ( V_211, V_212 ) ||
V_211 + V_212 > V_217 )
return V_218 ;
V_69 = V_214 ( & V_29 , & V_97 , false , & V_215 ) ;
if ( V_69 < V_42 )
V_215 = F_126 () ?
V_219 : V_220 ;
if ( V_14 & ( V_221 | V_222 ) ) {
F_72 ( L_23 ) ;
return V_41 ;
}
V_213 = F_24 ( sizeof( * V_213 ) , V_27 ) ;
if ( ! V_213 )
return V_55 ;
V_213 -> V_197 = V_211 ;
V_213 -> V_205 = V_212 ;
V_213 -> V_108 = V_108 ;
V_213 -> V_14 = V_14 ;
V_213 -> V_130 = V_130 ;
V_140 = NULL ;
V_141 = NULL ;
if ( V_220 == V_215 ) {
V_213 -> V_177 = false ;
if ( ! ( V_14 & V_129 ) ) {
V_213 -> V_195 = 0 ;
V_213 -> V_196 = 0 ;
F_127 ( & V_213 -> V_103 ) ;
V_140 = F_111 ;
V_141 = ( void * ) V_213 ;
}
} else {
V_213 -> V_177 = true ;
}
V_69 = F_90 ( V_85 ,
& V_213 -> V_51 ,
V_213 -> V_197 ,
& V_213 -> V_52 ,
V_213 -> V_205 ,
V_213 -> V_108 ,
V_213 -> V_14 ,
V_213 -> V_130 ,
V_213 -> V_177 ,
V_140 , V_141 ) ;
if ( V_69 < V_42 ) {
F_16 ( V_213 ) ;
return V_69 ;
}
* V_191 = V_213 ;
V_213 -> V_85 = * V_85 ;
return V_69 ;
}
int F_128 ( struct V_190 * * V_191 )
{
int V_74 ;
struct V_190 * V_223 ;
if ( ! V_191 || ! ( * V_191 ) )
return V_41 ;
V_223 = * V_191 ;
V_74 = F_93 ( V_223 -> V_85 , V_223 -> V_177 ) ;
memset ( V_223 , 0 , sizeof( * V_223 ) ) ;
V_223 -> V_85 = V_176 ;
V_223 -> V_108 = V_112 ;
F_16 ( V_223 ) ;
* V_191 = NULL ;
return V_74 ;
}
int F_129 ( const struct V_190 * V_191 ,
T_1 * V_224 ,
T_1 * V_225 )
{
struct V_80 * V_193 ;
struct V_80 * V_194 ;
int V_74 ;
if ( ! V_191 )
return V_41 ;
F_107 ( V_191 ) ;
V_74 =
F_110 ( V_191 , & V_193 , & V_194 ) ;
if ( V_74 == V_42 )
F_130 ( V_193 , V_194 ,
V_224 , V_225 ) ;
F_108 ( V_191 ) ;
if ( V_74 == V_42 &&
( ( V_224 && * V_224 >= V_191 -> V_197 ) ||
( V_225 && * V_225 >= V_191 -> V_197 ) ) )
return V_226 ;
return V_74 ;
}
int F_131 ( const struct V_190 * V_191 ,
T_1 * V_227 ,
T_1 * V_228 )
{
struct V_80 * V_193 ;
struct V_80 * V_194 ;
int V_74 ;
if ( ! V_191 )
return V_41 ;
F_107 ( V_191 ) ;
V_74 =
F_110 ( V_191 , & V_193 , & V_194 ) ;
if ( V_74 == V_42 )
F_130 ( V_194 , V_193 ,
V_227 , V_228 ) ;
F_108 ( V_191 ) ;
if ( V_74 == V_42 &&
( ( V_227 && * V_227 >= V_191 -> V_205 ) ||
( V_228 && * V_228 >= V_191 -> V_205 ) ) )
return V_226 ;
return V_74 ;
}
T_7 F_132 ( const struct V_190 * V_191 )
{
struct V_80 * V_193 ;
struct V_80 * V_194 ;
T_7 V_74 ;
if ( ! V_191 )
return V_41 ;
F_107 ( V_191 ) ;
V_74 =
F_110 ( V_191 , & V_193 , & V_194 ) ;
if ( V_74 == V_42 )
V_74 = F_117 ( V_193 ,
V_194 ,
V_191 -> V_197 ) ;
else
V_74 = 0 ;
F_108 ( V_191 ) ;
return V_74 ;
}
T_7 F_133 ( const struct V_190 * V_191 )
{
struct V_80 * V_193 ;
struct V_80 * V_194 ;
T_7 V_74 ;
if ( ! V_191 )
return V_41 ;
F_107 ( V_191 ) ;
V_74 =
F_110 ( V_191 , & V_193 , & V_194 ) ;
if ( V_74 == V_42 )
V_74 = F_117 ( V_194 ,
V_193 ,
V_191 -> V_205 ) ;
else
V_74 = 0 ;
F_108 ( V_191 ) ;
return V_74 ;
}
T_7 F_134 ( const struct V_190 * V_191 )
{
struct V_80 * V_193 ;
struct V_80 * V_194 ;
T_7 V_74 ;
if ( ! V_191 )
return V_41 ;
F_107 ( V_191 ) ;
V_74 =
F_110 ( V_191 , & V_193 , & V_194 ) ;
if ( V_74 == V_42 )
V_74 = F_122 ( V_193 ,
V_194 ,
V_191 -> V_197 ) ;
else
V_74 = 0 ;
F_108 ( V_191 ) ;
return V_74 ;
}
T_7 F_135 ( const struct V_190 * V_191 )
{
struct V_80 * V_193 ;
struct V_80 * V_194 ;
T_7 V_74 ;
if ( ! V_191 )
return V_41 ;
F_107 ( V_191 ) ;
V_74 =
F_110 ( V_191 , & V_193 , & V_194 ) ;
if ( V_74 == V_42 )
V_74 = F_122 ( V_194 ,
V_193 ,
V_191 -> V_205 ) ;
else
V_74 = 0 ;
F_108 ( V_191 ) ;
return V_74 ;
}
T_5 F_136 ( struct V_190 * V_191 ,
const void * V_198 ,
T_3 V_199 ,
int V_229 )
{
T_5 V_74 ;
if ( ! V_191 || ! V_198 )
return V_41 ;
F_107 ( V_191 ) ;
do {
V_74 = F_115 ( V_191 -> V_51 ,
V_191 -> V_52 ,
V_191 -> V_197 ,
V_198 , V_199 ,
F_19 ) ;
if ( V_74 == V_192 &&
! F_113 ( V_191 ) )
V_74 = V_230 ;
} while ( V_74 == V_192 );
F_108 ( V_191 ) ;
return V_74 ;
}
T_5 F_137 ( struct V_190 * V_191 ,
void * V_198 ,
T_3 V_199 ,
int V_229 )
{
T_5 V_74 ;
if ( ! V_191 || ! V_198 )
return V_41 ;
F_107 ( V_191 ) ;
do {
V_74 = F_121 ( V_191 -> V_51 ,
V_191 -> V_52 ,
V_191 -> V_205 ,
V_198 , V_199 ,
F_20 , true ) ;
if ( V_74 == V_192 &&
! F_113 ( V_191 ) )
V_74 = V_230 ;
} while ( V_74 == V_192 );
F_108 ( V_191 ) ;
return V_74 ;
}
T_5 F_138 ( struct V_190 * V_191 ,
void * V_198 ,
T_3 V_199 ,
int V_229 )
{
T_5 V_74 ;
if ( ! V_191 || ! V_198 )
return V_41 ;
F_107 ( V_191 ) ;
do {
V_74 = F_121 ( V_191 -> V_51 ,
V_191 -> V_52 ,
V_191 -> V_205 ,
V_198 , V_199 ,
F_20 , false ) ;
if ( V_74 == V_192 &&
! F_113 ( V_191 ) )
V_74 = V_230 ;
} while ( V_74 == V_192 );
F_108 ( V_191 ) ;
return V_74 ;
}
T_5 F_139 ( struct V_190 * V_191 ,
struct V_38 * V_39 ,
T_3 V_231 ,
int V_229 )
{
T_5 V_74 ;
if ( ! V_191 )
return V_41 ;
F_107 ( V_191 ) ;
do {
V_74 = F_115 ( V_191 -> V_51 ,
V_191 -> V_52 ,
V_191 -> V_197 ,
V_39 , V_231 ,
F_21 ) ;
if ( V_74 == V_192 &&
! F_113 ( V_191 ) )
V_74 = V_230 ;
} while ( V_74 == V_192 );
F_108 ( V_191 ) ;
return V_74 ;
}
T_5 F_140 ( struct V_190 * V_191 ,
struct V_38 * V_39 ,
T_3 V_231 ,
int V_229 )
{
T_5 V_74 ;
if ( ! V_191 )
return V_41 ;
F_107 ( V_191 ) ;
do {
V_74 = F_121 ( V_191 -> V_51 ,
V_191 -> V_52 ,
V_191 -> V_205 ,
V_39 , V_231 ,
F_22 ,
true ) ;
if ( V_74 == V_192 &&
! F_113 ( V_191 ) )
V_74 = V_230 ;
} while ( V_74 == V_192 );
F_108 ( V_191 ) ;
return V_74 ;
}
T_5 F_141 ( struct V_190 * V_191 ,
struct V_38 * V_39 ,
T_3 V_231 ,
int V_229 )
{
T_5 V_74 ;
if ( ! V_191 )
return V_41 ;
F_107 ( V_191 ) ;
do {
V_74 = F_121 ( V_191 -> V_51 ,
V_191 -> V_52 ,
V_191 -> V_205 ,
V_39 , V_231 ,
F_22 ,
false ) ;
if ( V_74 == V_192 &&
! F_113 ( V_191 ) )
V_74 = V_230 ;
} while ( V_74 == V_192 );
F_108 ( V_191 ) ;
return V_74 ;
}
