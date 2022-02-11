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
struct V_37 * V_38 = V_42 ;
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
const void * V_38 ,
T_3 V_59 , T_3 V_2 )
{
return F_8 ( V_4 , V_27 , V_38 , V_2 , true ) ;
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
V_68 = F_37 ( ( V_69 ) V_66 ,
V_50 -> V_9 -> V_15 , 1 ,
V_50 -> V_9 -> V_10 . V_35 . V_62 ) ;
if ( V_68 < V_50 -> V_9 -> V_15 ) {
F_38 ( L_1 , V_68 ) ;
F_33 ( V_50 -> V_9 -> V_10 . V_35 . V_62 ,
V_68 , false ) ;
V_39 = V_54 ;
goto V_70;
}
V_68 = F_37 ( ( V_69 ) V_67 ,
V_51 -> V_9 -> V_15 , 1 ,
V_51 -> V_9 -> V_10 . V_35 . V_62 ) ;
if ( V_68 < V_51 -> V_9 -> V_15 ) {
F_38 ( L_2 , V_68 ) ;
F_33 ( V_51 -> V_9 -> V_10 . V_35 . V_62 ,
V_68 , false ) ;
F_33 ( V_50 -> V_9 -> V_10 . V_35 . V_62 ,
V_50 -> V_9 -> V_15 , false ) ;
V_39 = V_54 ;
}
V_70:
return V_39 ;
}
static int F_39 ( struct V_71 * V_72 ,
struct V_3 * V_50 ,
struct V_3 * V_51 )
{
T_1 V_66 ;
T_1 V_67 ;
V_66 = V_72 -> V_64 ;
V_67 = V_72 -> V_64 +
V_50 -> V_9 -> V_15 * V_6 ;
return F_36 ( V_66 , V_67 , V_50 ,
V_51 ) ;
}
static void F_40 ( struct V_3 * V_50 ,
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
static int F_41 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
int V_73 ;
if ( ! V_50 -> V_19 || ! V_51 -> V_19 ) {
struct V_36 * V_74 [ 2 ] ;
if ( V_50 -> V_19 != V_51 -> V_19 )
return V_75 ;
if ( V_50 -> V_9 -> V_10 . V_35 . V_62 == NULL ||
* V_50 -> V_9 -> V_10 . V_35 . V_62 == NULL )
return V_76 ;
V_74 [ 0 ] = * V_50 -> V_9 -> V_10 . V_35 . V_62 ;
V_74 [ 1 ] = * V_51 -> V_9 -> V_10 . V_35 . V_62 ;
V_50 -> V_19 = F_42 ( V_74 , 2 , V_77 , V_78 ) ;
if ( V_50 -> V_19 != NULL ) {
V_51 -> V_19 =
(struct V_79 * ) ( ( V_24 * )
V_50 -> V_19 +
V_6 ) ;
V_73 = V_41 ;
} else {
F_38 ( L_3 ) ;
V_73 = V_54 ;
}
} else {
V_73 = V_41 ;
}
return V_73 ;
}
static int F_43 ( T_2 V_80 ,
struct V_3 * V_50 ,
struct V_3 * V_51 )
{
if ( V_50 -> V_19 ) {
if ( V_50 -> V_19 < V_51 -> V_19 )
F_44 ( V_50 -> V_19 ) ;
else
F_44 ( V_51 -> V_19 ) ;
V_50 -> V_19 = NULL ;
V_51 -> V_19 = NULL ;
}
return V_41 ;
}
static struct V_81 * F_45 ( struct V_82 * V_82 ,
struct V_83 V_84 )
{
struct V_81 * V_85 ;
if ( F_46 ( V_84 ) )
return NULL ;
F_47 (entry, &qp_list->head, list_item) {
if ( F_48 ( V_85 -> V_84 , V_84 ) )
return V_85 ;
}
return NULL ;
}
static struct V_86 *
F_49 ( struct V_83 V_84 )
{
struct V_86 * V_85 ;
struct V_81 * V_87 = F_45 ( & V_88 , V_84 ) ;
V_85 = V_87 ? F_50 (
V_87 , struct V_86 , V_87 ) : NULL ;
return V_85 ;
}
static struct V_89 *
F_51 ( struct V_83 V_84 )
{
struct V_89 * V_85 ;
struct V_81 * V_87 = F_45 ( & V_90 , V_84 ) ;
V_85 = V_87 ? F_50 (
V_87 , struct V_89 , V_87 ) : NULL ;
return V_85 ;
}
static int F_52 ( bool V_91 , struct V_83 V_84 )
{
T_2 V_92 = F_53 () ;
struct V_93 V_94 ;
V_94 . V_38 . V_95 . V_96 = F_54 ( V_92 , V_97 ) ;
V_94 . V_38 . V_95 . V_28 = F_54 ( V_98 ,
V_99 ) ;
V_94 . V_38 . V_95 . V_100 = sizeof( V_94 ) - sizeof( V_94 . V_38 . V_95 ) ;
V_94 . V_38 . V_101 . V_102 =
V_91 ? V_103 : V_104 ;
V_94 . V_105 . V_106 = V_92 ;
V_94 . V_105 . V_84 = V_84 ;
return F_55 ( & V_94 . V_38 . V_95 ) ;
}
static struct V_86 *
F_56 ( struct V_83 V_84 ,
T_2 V_107 ,
T_2 V_14 ,
T_1 V_108 ,
T_1 V_109 ,
void * V_50 ,
void * V_51 )
{
int V_73 ;
struct V_86 * V_85 ;
const T_1 V_110 = F_2 ( V_108 , V_6 ) +
F_2 ( V_109 , V_6 ) + 2 ;
if ( F_46 ( V_84 ) ) {
T_2 V_92 = F_53 () ;
V_84 = F_54 ( V_92 , V_111 ) ;
}
V_85 = F_24 ( sizeof( * V_85 ) , V_26 ) ;
if ( V_85 ) {
V_85 -> V_87 . V_107 = V_107 ;
V_85 -> V_87 . V_14 = V_14 ;
V_85 -> V_87 . V_108 = V_108 ;
V_85 -> V_87 . V_109 = V_109 ;
V_85 -> V_87 . V_112 = 0 ;
V_85 -> V_110 = V_110 ;
V_85 -> V_50 = V_50 ;
V_85 -> V_51 = V_51 ;
F_57 ( & V_85 -> V_87 . V_113 ) ;
V_73 = F_58 ( & V_85 -> V_114 ,
V_115 ,
V_84 ) ;
V_85 -> V_87 . V_84 = F_59 ( & V_85 -> V_114 ) ;
if ( ( V_73 != V_41 ) ||
F_45 ( & V_88 , V_85 -> V_87 . V_84 ) ) {
F_38 ( L_4 ,
V_84 . V_116 , V_84 . V_114 , V_73 ) ;
F_16 ( V_85 ) ;
V_85 = NULL ;
}
}
return V_85 ;
}
static void F_60 ( struct V_86 * V_85 )
{
F_17 ( & V_85 -> V_47 ) ;
F_28 ( V_85 -> V_50 , V_85 -> V_51 ) ;
F_1 ( V_85 -> V_50 , V_85 -> V_87 . V_108 ) ;
F_1 ( V_85 -> V_51 , V_85 -> V_87 . V_109 ) ;
F_61 ( & V_85 -> V_114 ) ;
F_16 ( V_85 ) ;
}
static int F_62 ( const struct V_86 * V_85 )
{
struct V_117 * V_118 ;
T_3 V_119 ;
int V_73 ;
if ( ! V_85 || V_85 -> V_110 <= 2 )
return V_40 ;
V_119 = sizeof( * V_118 ) +
( T_3 ) V_85 -> V_110 * sizeof( T_2 ) ;
V_118 = F_15 ( V_119 , V_26 ) ;
if ( ! V_118 )
return V_54 ;
V_118 -> V_95 . V_96 = F_54 ( V_98 ,
V_120 ) ;
V_118 -> V_95 . V_28 = V_121 ;
V_118 -> V_95 . V_100 = V_119 - V_122 ;
V_118 -> V_84 = V_85 -> V_87 . V_84 ;
V_118 -> V_107 = V_85 -> V_87 . V_107 ;
V_118 -> V_14 = V_85 -> V_87 . V_14 ;
V_118 -> V_108 = V_85 -> V_87 . V_108 ;
V_118 -> V_109 = V_85 -> V_87 . V_109 ;
V_118 -> V_110 = V_85 -> V_110 ;
V_73 = F_18 ( ( V_24 * ) V_118 + sizeof( * V_118 ) ,
& V_85 -> V_47 ) ;
if ( V_73 == V_41 )
V_73 = F_63 ( & V_118 -> V_95 ) ;
F_16 ( V_118 ) ;
return V_73 ;
}
static int F_64 ( struct V_83 V_84 )
{
struct V_123 V_124 ;
V_124 . V_95 . V_96 = F_54 ( V_98 ,
V_125 ) ;
V_124 . V_95 . V_28 = V_121 ;
V_124 . V_95 . V_100 = sizeof( V_84 ) ;
V_124 . V_84 = V_84 ;
return F_63 ( & V_124 . V_95 ) ;
}
static void F_65 ( struct V_82 * V_82 , struct V_81 * V_85 )
{
if ( V_85 )
F_66 ( & V_85 -> V_113 , & V_82 -> V_126 ) ;
}
static void F_67 ( struct V_82 * V_82 ,
struct V_81 * V_85 )
{
if ( V_85 )
F_68 ( & V_85 -> V_113 ) ;
}
static int F_69 ( struct V_83 V_84 )
{
int V_73 ;
struct V_86 * V_85 ;
T_2 V_112 = ~ 0 ;
F_30 ( & V_88 . V_22 ) ;
V_85 = F_49 ( V_84 ) ;
if ( ! V_85 ) {
F_32 ( & V_88 . V_22 ) ;
return V_127 ;
}
if ( V_85 -> V_87 . V_14 & V_128 ) {
V_73 = V_41 ;
if ( V_85 -> V_87 . V_112 > 1 ) {
V_73 = F_52 ( false , V_84 ) ;
}
} else {
V_73 = F_64 ( V_84 ) ;
if ( V_73 < V_41 ) {
F_32 ( & V_88 . V_22 ) ;
return V_73 ;
}
}
V_85 -> V_87 . V_112 -- ;
if ( V_85 -> V_87 . V_112 == 0 )
F_67 ( & V_88 , & V_85 -> V_87 ) ;
if ( V_85 )
V_112 = V_85 -> V_87 . V_112 ;
F_32 ( & V_88 . V_22 ) ;
if ( V_112 == 0 )
F_60 ( V_85 ) ;
return V_73 ;
}
static int F_70 ( struct V_83 * V_84 ,
struct V_3 * * V_50 ,
T_1 V_108 ,
struct V_3 * * V_51 ,
T_1 V_109 ,
T_2 V_107 ,
T_2 V_14 ,
T_2 V_129 )
{
const T_1 V_44 =
F_2 ( V_108 , V_6 ) + 1 ;
const T_1 V_46 =
F_2 ( V_109 , V_6 ) + 1 ;
void * V_130 = NULL ;
void * V_131 = NULL ;
int V_73 ;
struct V_86 * V_132 = NULL ;
if ( V_129 != V_133 )
return V_134 ;
F_30 ( & V_88 . V_22 ) ;
V_132 = F_49 ( * V_84 ) ;
if ( V_132 ) {
if ( V_132 -> V_87 . V_14 & V_128 ) {
if ( V_132 -> V_87 . V_112 > 1 ) {
F_71 ( L_5 ) ;
V_73 = V_76 ;
goto V_135;
}
if ( V_132 -> V_87 . V_108 != V_109 ||
V_132 -> V_87 . V_109 !=
V_108 ||
V_132 -> V_87 . V_14 !=
( V_14 & ~ V_136 ) ) {
F_71 ( L_6 ) ;
V_73 = V_75 ;
goto V_135;
}
V_73 = F_52 ( true , * V_84 ) ;
if ( V_73 < V_41 )
goto V_135;
V_130 = V_132 -> V_51 ;
V_131 = V_132 -> V_50 ;
goto V_70;
}
V_73 = V_53 ;
goto V_135;
}
V_130 = F_5 ( V_108 , V_14 ) ;
if ( ! V_130 ) {
F_38 ( L_7 ) ;
V_73 = V_54 ;
goto error;
}
V_131 = F_5 ( V_109 , V_14 ) ;
if ( ! V_131 ) {
F_38 ( L_8 ) ;
V_73 = V_54 ;
goto error;
}
V_132 = F_56 ( * V_84 , V_107 , V_14 ,
V_108 , V_109 ,
V_130 , V_131 ) ;
if ( ! V_132 ) {
F_38 ( L_9 , V_137 ) ;
V_73 = V_54 ;
goto error;
}
V_73 = F_14 ( V_130 , V_44 , V_131 ,
V_46 ,
& V_132 -> V_47 ) ;
if ( V_73 < V_41 ) {
F_38 ( L_10 ) ;
goto error;
}
if ( V_132 -> V_87 . V_14 & V_128 ) {
T_2 V_92 = F_53 () ;
if ( V_132 -> V_87 . V_84 . V_116 != V_92 ||
( V_132 -> V_87 . V_107 != V_111 &&
V_132 -> V_87 . V_107 != V_92 ) ) {
V_73 = V_134 ;
goto error;
}
if ( V_132 -> V_87 . V_14 & V_136 ) {
V_73 = V_127 ;
goto error;
}
} else {
V_73 = F_62 ( V_132 ) ;
if ( V_73 < V_41 ) {
F_38 ( L_11 , V_73 ) ;
goto error;
}
}
F_26 ( (struct V_3 * ) V_130 ,
(struct V_3 * ) V_131 ) ;
F_65 ( & V_88 , & V_132 -> V_87 ) ;
V_70:
V_132 -> V_87 . V_112 ++ ;
* V_84 = V_132 -> V_87 . V_84 ;
* V_50 = (struct V_3 * ) V_130 ;
* V_51 = (struct V_3 * ) V_131 ;
if ( ( V_132 -> V_87 . V_14 & V_128 ) &&
V_132 -> V_87 . V_112 == 1 ) {
F_72 ( ( * V_50 ) -> V_19 , * V_84 ) ;
F_72 ( ( * V_51 ) -> V_19 , * V_84 ) ;
}
F_32 ( & V_88 . V_22 ) ;
return V_41 ;
error:
F_32 ( & V_88 . V_22 ) ;
if ( V_132 ) {
F_60 ( V_132 ) ;
} else {
F_1 ( V_130 , V_108 ) ;
F_1 ( V_131 , V_109 ) ;
}
return V_73 ;
V_135:
F_32 ( & V_88 . V_22 ) ;
return V_73 ;
}
static int F_73 ( struct V_83 V_84 ,
T_2 V_107 ,
T_2 V_14 ,
T_2 V_129 ,
T_1 V_108 ,
T_1 V_109 ,
struct V_71 * V_72 ,
struct V_138 * V_116 ,
T_4 V_139 ,
void * V_140 , struct V_89 * * V_141 )
{
struct V_89 * V_85 = NULL ;
const T_2 V_92 = F_74 ( V_116 ) ;
bool V_142 = V_14 & V_128 ;
int V_73 ;
T_1 V_143 ;
T_1 V_144 ;
if ( V_14 & V_136 )
return V_127 ;
if ( V_84 . V_116 != V_92 && V_84 . V_116 != V_107 )
return V_134 ;
if ( F_75 ( V_92 ) && F_75 ( V_107 ) )
return V_145 ;
if ( V_142 && V_107 != V_111 && V_92 != V_107 )
return V_134 ;
V_85 = F_24 ( sizeof( * V_85 ) , V_146 ) ;
if ( ! V_85 )
return V_54 ;
if ( F_74 ( V_116 ) == V_147 && ! V_142 ) {
V_143 = V_109 ;
V_144 = V_108 ;
} else {
V_143 = V_108 ;
V_144 = V_109 ;
}
V_85 -> V_87 . V_84 = V_84 ;
V_85 -> V_87 . V_107 = V_107 ;
V_85 -> V_87 . V_14 = V_14 ;
V_85 -> V_87 . V_108 = V_143 ;
V_85 -> V_87 . V_109 = V_144 ;
V_85 -> V_87 . V_112 = 1 ;
V_85 -> V_148 = V_92 ;
V_85 -> V_149 = V_111 ;
V_85 -> V_150 = V_151 ;
V_85 -> V_152 =
! ! ( V_116 -> V_129 & V_153 ) ;
V_85 -> V_154 =
! ! ( V_129 & V_155 ) ;
V_85 -> V_156 = false ;
V_85 -> V_139 = V_139 ;
V_85 -> V_140 = V_140 ;
V_85 -> V_50 = F_23 ( V_143 ) ;
if ( V_85 -> V_50 == NULL ) {
V_73 = V_54 ;
goto error;
}
V_85 -> V_51 = F_23 ( V_144 ) ;
if ( V_85 -> V_51 == NULL ) {
V_73 = V_54 ;
goto error;
}
F_26 ( V_85 -> V_50 , V_85 -> V_51 ) ;
F_57 ( & V_85 -> V_87 . V_113 ) ;
if ( V_142 ) {
V_24 * V_157 ;
V_85 -> V_158 = F_76 ( F_77 ( V_85 -> V_87 ) ,
V_6 , V_26 ) ;
if ( V_85 -> V_158 == NULL ) {
V_73 = V_54 ;
goto error;
}
V_85 -> V_150 = V_159 ;
V_85 -> V_50 -> V_19 = V_85 -> V_158 ;
V_157 = ( V_24 * ) V_85 -> V_158 + V_6 *
( F_2 ( V_85 -> V_87 . V_108 , V_6 ) + 1 ) ;
V_85 -> V_51 -> V_19 = (struct V_79 * ) V_157 ;
} else if ( V_72 ) {
V_73 = F_39 ( V_72 ,
V_85 -> V_50 ,
V_85 -> V_51 ) ;
if ( V_73 < V_41 )
goto error;
V_85 -> V_150 = V_159 ;
} else {
V_85 -> V_150 = V_160 ;
}
F_65 ( & V_90 , & V_85 -> V_87 ) ;
if ( V_141 != NULL )
* V_141 = V_85 ;
V_73 = F_58 ( & V_85 -> V_114 ,
V_161 ,
V_84 ) ;
if ( V_73 != V_41 ) {
F_38 ( L_4 ,
V_84 . V_116 , V_84 . V_114 , V_73 ) ;
goto error;
}
V_85 -> V_87 . V_84 = F_59 ( & V_85 -> V_114 ) ;
if ( V_142 ) {
F_72 ( V_85 -> V_50 -> V_19 ,
V_85 -> V_87 . V_84 ) ;
F_72 ( V_85 -> V_51 -> V_19 ,
V_85 -> V_87 . V_84 ) ;
}
F_78 ( V_116 , V_85 -> V_87 . V_84 ) ;
return V_41 ;
error:
if ( V_85 != NULL ) {
F_25 ( V_85 -> V_50 , V_143 ) ;
F_25 ( V_85 -> V_51 , V_144 ) ;
F_16 ( V_85 ) ;
}
return V_73 ;
}
static int F_79 ( bool V_91 ,
struct V_83 V_84 ,
T_2 V_162 ,
T_2 V_106 )
{
int V_163 ;
struct V_93 V_94 ;
if ( F_46 ( V_84 ) || V_162 == V_111 ||
V_106 == V_111 )
return V_40 ;
V_94 . V_38 . V_95 . V_96 = F_54 ( V_106 , V_97 ) ;
V_94 . V_38 . V_95 . V_28 = F_54 ( V_98 ,
V_99 ) ;
V_94 . V_38 . V_95 . V_100 = sizeof( V_94 ) - sizeof( V_94 . V_38 . V_95 ) ;
V_94 . V_38 . V_101 . V_102 = V_91 ?
V_103 : V_104 ;
V_94 . V_105 . V_84 = V_84 ;
V_94 . V_105 . V_106 = V_162 ;
V_163 = F_80 ( V_98 ,
& V_94 . V_38 . V_95 , false ) ;
if ( V_163 < V_41 )
F_38 ( L_12 ,
V_91 ? L_13 : L_14 , V_106 ) ;
return V_163 ;
}
static int F_81 ( struct V_89 * V_85 ,
T_2 V_107 ,
T_2 V_14 ,
T_2 V_129 ,
T_1 V_108 ,
T_1 V_109 ,
struct V_71 * V_72 ,
struct V_138 * V_116 ,
T_4 V_139 ,
void * V_140 ,
struct V_89 * * V_141 )
{
const T_2 V_92 = F_74 ( V_116 ) ;
bool V_142 = V_14 & V_128 ;
int V_73 ;
if ( V_85 -> V_150 != V_160 &&
V_85 -> V_150 != V_159 )
return V_76 ;
if ( V_142 ) {
if ( ! ( V_85 -> V_87 . V_14 & V_128 ) ||
V_92 != V_85 -> V_148 ) {
return V_40 ;
}
} else if ( V_92 == V_85 -> V_148 ||
V_92 == V_85 -> V_149 ) {
return V_53 ;
}
if ( F_75 ( V_92 ) &&
F_75 ( V_85 -> V_148 ) )
return V_145 ;
if ( ( V_116 -> V_129 & V_153 ) &&
! V_85 -> V_154 )
return V_134 ;
if ( V_85 -> V_152 &&
( ! ( V_129 & V_155 ) ) )
return V_134 ;
if ( V_85 -> V_87 . V_107 != V_111 && V_85 -> V_87 . V_107 != V_92 )
return V_134 ;
if ( V_85 -> V_148 == V_147 ) {
if ( ! F_82 ( V_116 ) )
return V_164 ;
} else if ( V_92 == V_147 ) {
struct V_138 * V_165 ;
bool V_166 ;
V_165 = F_83 ( V_85 -> V_148 ) ;
V_166 = F_82 ( V_165 ) ;
F_84 ( V_165 ) ;
if ( ! V_166 )
return V_164 ;
}
if ( ( V_85 -> V_87 . V_14 & ~ V_167 ) != ( V_14 & ~ V_168 ) )
return V_75 ;
if ( V_92 != V_147 ) {
if ( V_85 -> V_87 . V_108 != V_108 ||
V_85 -> V_87 . V_109 != V_109 ) {
return V_75 ;
}
} else if ( V_85 -> V_87 . V_108 != V_109 ||
V_85 -> V_87 . V_109 != V_108 ) {
return V_75 ;
}
if ( V_92 != V_147 ) {
if ( V_85 -> V_150 != V_160 )
return V_40 ;
if ( V_72 != NULL ) {
V_73 = F_39 ( V_72 ,
V_85 -> V_50 ,
V_85 -> V_51 ) ;
if ( V_73 < V_41 )
return V_73 ;
V_85 -> V_150 = V_169 ;
} else {
V_85 -> V_150 = V_170 ;
}
} else if ( V_85 -> V_150 == V_160 ) {
return V_76 ;
} else {
V_85 -> V_150 = V_169 ;
}
if ( V_85 -> V_150 == V_169 ) {
V_73 =
F_79 ( true , V_85 -> V_87 . V_84 , V_92 ,
V_85 -> V_148 ) ;
if ( V_73 < V_41 )
F_38 ( L_15 ,
V_85 -> V_148 , V_85 -> V_87 . V_84 . V_116 ,
V_85 -> V_87 . V_84 . V_114 ) ;
}
V_85 -> V_149 = V_92 ;
V_85 -> V_87 . V_112 ++ ;
if ( V_139 ) {
V_85 -> V_139 = V_139 ;
V_85 -> V_140 = V_140 ;
}
if ( ! V_142 )
F_78 ( V_116 , V_85 -> V_87 . V_84 ) ;
if ( V_141 != NULL )
* V_141 = V_85 ;
return V_41 ;
}
static int F_85 ( struct V_83 V_84 ,
T_2 V_107 ,
T_2 V_14 ,
T_2 V_129 ,
T_1 V_108 ,
T_1 V_109 ,
struct V_71 * V_72 ,
struct V_138 * V_116 ,
T_4 V_139 ,
void * V_140 ,
struct V_89 * * V_141 ,
bool * V_171 )
{
const T_2 V_92 = F_74 ( V_116 ) ;
bool V_172 ;
struct V_89 * V_85 = NULL ;
bool V_142 = V_14 & V_128 ;
int V_73 ;
if ( F_46 ( V_84 ) ||
( V_14 & ~ V_173 ) || V_142 ||
! ( V_108 || V_109 ) ||
! V_116 || V_92 == V_111 ||
V_84 . V_116 == V_111 ) {
return V_40 ;
}
if ( V_72 && ! F_86 ( V_72 ) )
return V_40 ;
F_30 ( & V_90 . V_22 ) ;
if ( ! V_142 && F_87 ( V_116 , V_84 ) ) {
F_71 ( L_16 ,
V_92 , V_84 . V_116 , V_84 . V_114 ) ;
F_32 ( & V_90 . V_22 ) ;
return V_53 ;
}
if ( V_84 . V_114 != V_111 )
V_85 = F_51 ( V_84 ) ;
if ( ! V_85 ) {
V_172 = true ;
V_73 =
F_73 ( V_84 , V_107 , V_14 , V_129 ,
V_108 , V_109 , V_72 ,
V_116 , V_139 , V_140 , V_141 ) ;
} else {
V_172 = false ;
V_73 =
F_81 ( V_85 , V_107 , V_14 , V_129 ,
V_108 , V_109 , V_72 ,
V_116 , V_139 , V_140 , V_141 ) ;
}
F_32 ( & V_90 . V_22 ) ;
if ( V_171 )
* V_171 = ( V_92 == V_147 ) &&
! ( V_172 && V_142 ) ;
return V_73 ;
}
static int F_88 ( struct V_83 * V_84 ,
struct V_3 * * V_50 ,
T_1 V_108 ,
struct V_3 * * V_51 ,
T_1 V_109 ,
T_2 V_107 ,
T_2 V_14 ,
T_2 V_129 ,
T_4 V_139 ,
void * V_140 )
{
struct V_83 V_174 ;
struct V_138 * V_116 ;
struct V_89 * V_85 ;
int V_73 ;
bool V_171 ;
if ( F_46 ( * V_84 ) ) {
V_174 = F_54 (
V_147 , V_111 ) ;
} else
V_174 = * V_84 ;
V_116 = F_83 ( V_147 ) ;
V_85 = NULL ;
V_73 =
F_85 ( V_174 , V_107 , V_14 , V_129 ,
V_108 , V_109 , NULL , V_116 ,
V_139 , V_140 , & V_85 , & V_171 ) ;
if ( V_73 == V_41 ) {
if ( V_171 ) {
* V_50 = V_85 -> V_51 ;
* V_51 = V_85 -> V_50 ;
} else {
* V_50 = V_85 -> V_50 ;
* V_51 = V_85 -> V_51 ;
}
* V_84 = F_59 ( & V_85 -> V_114 ) ;
} else {
* V_84 = V_175 ;
F_71 ( L_17 ,
V_73 ) ;
}
F_84 ( V_116 ) ;
return V_73 ;
}
int F_89 ( struct V_83 * V_84 ,
struct V_3 * * V_50 ,
T_1 V_108 ,
struct V_3 * * V_51 ,
T_1 V_109 ,
T_2 V_107 ,
T_2 V_14 ,
T_2 V_129 ,
bool V_176 ,
T_4 V_139 ,
void * V_140 )
{
if ( ! V_84 || ! V_50 || ! V_51 ||
( ! V_108 && ! V_109 ) || ( V_14 & ~ V_173 ) )
return V_40 ;
if ( V_176 ) {
return F_70 ( V_84 , V_50 ,
V_108 , V_51 ,
V_109 , V_107 ,
V_14 , V_129 ) ;
} else {
return F_88 ( V_84 , V_50 ,
V_108 , V_51 ,
V_109 , V_107 , V_14 ,
V_129 , V_139 , V_140 ) ;
}
}
static int F_90 ( struct V_83 V_84 )
{
int V_73 ;
struct V_138 * V_116 ;
V_116 = F_83 ( V_147 ) ;
V_73 = F_91 ( V_84 , V_116 ) ;
F_84 ( V_116 ) ;
return V_73 ;
}
static int F_92 ( struct V_83 V_84 , bool V_176 )
{
if ( F_46 ( V_84 ) )
return V_40 ;
if ( V_176 )
return F_69 ( V_84 ) ;
else
return F_90 ( V_84 ) ;
}
static struct V_81 * F_93 ( struct V_82 * V_82 )
{
if ( ! F_94 ( & V_82 -> V_126 ) ) {
struct V_81 * V_85 =
F_95 ( & V_82 -> V_126 , struct V_81 ,
V_113 ) ;
return V_85 ;
}
return NULL ;
}
void F_96 ( void )
{
struct V_81 * V_85 ;
struct V_89 * V_177 ;
F_30 ( & V_90 . V_22 ) ;
while ( ( V_85 = F_93 ( & V_90 ) ) ) {
V_177 = (struct V_89 * ) V_85 ;
F_67 ( & V_90 , V_85 ) ;
F_16 ( V_177 ) ;
}
F_32 ( & V_90 . V_22 ) ;
}
int F_97 ( struct V_83 V_84 ,
T_2 V_107 ,
T_2 V_14 ,
T_2 V_129 ,
T_1 V_108 ,
T_1 V_109 ,
struct V_71 * V_72 ,
struct V_138 * V_116 )
{
return F_85 ( V_84 , V_107 , V_14 , V_129 ,
V_108 , V_109 ,
V_72 , V_116 , NULL , NULL , NULL , NULL ) ;
}
int F_98 ( struct V_83 V_84 ,
T_1 V_66 ,
T_1 V_67 ,
struct V_138 * V_116 )
{
struct V_89 * V_85 ;
int V_73 ;
const T_2 V_92 = F_74 ( V_116 ) ;
if ( F_46 ( V_84 ) || ! V_116 ||
V_92 == V_111 )
return V_40 ;
if ( V_66 == 0 || V_67 == 0 )
return V_40 ;
F_30 ( & V_90 . V_22 ) ;
if ( ! F_87 ( V_116 , V_84 ) ) {
F_38 ( L_18 ,
V_92 , V_84 . V_116 , V_84 . V_114 ) ;
V_73 = V_127 ;
goto V_70;
}
V_85 = F_51 ( V_84 ) ;
if ( ! V_85 ) {
V_73 = V_127 ;
goto V_70;
}
if ( V_85 -> V_148 != V_92 &&
( V_85 -> V_148 != V_147 ||
V_85 -> V_149 != V_92 ) ) {
V_73 = V_178 ;
goto V_70;
}
if ( V_85 -> V_150 != V_160 &&
V_85 -> V_150 != V_170 ) {
V_73 = V_76 ;
goto V_70;
}
V_73 = F_36 ( V_66 , V_67 ,
V_85 -> V_50 , V_85 -> V_51 ) ;
if ( V_73 < V_41 )
goto V_70;
V_73 = F_41 ( V_85 -> V_50 , V_85 -> V_51 ) ;
if ( V_73 < V_41 ) {
F_40 ( V_85 -> V_50 ,
V_85 -> V_51 ) ;
goto V_70;
}
if ( V_85 -> V_150 == V_160 )
V_85 -> V_150 = V_159 ;
else
V_85 -> V_150 = V_169 ;
V_85 -> V_156 = true ;
if ( V_85 -> V_150 == V_169 ) {
V_73 =
F_79 ( true , V_84 , V_92 , V_85 -> V_148 ) ;
if ( V_73 < V_41 ) {
F_38 ( L_15 ,
V_85 -> V_148 , V_85 -> V_87 . V_84 . V_116 ,
V_85 -> V_87 . V_84 . V_114 ) ;
}
}
V_73 = V_41 ;
V_70:
F_32 ( & V_90 . V_22 ) ;
return V_73 ;
}
static void F_99 ( struct V_89 * V_85 )
{
V_85 -> V_50 -> V_20 = NULL ;
V_85 -> V_51 -> V_20 = NULL ;
}
int F_91 ( struct V_83 V_84 , struct V_138 * V_116 )
{
struct V_89 * V_85 ;
const T_2 V_92 = F_74 ( V_116 ) ;
T_2 V_106 ;
bool V_142 = false ;
int V_73 ;
if ( F_46 ( V_84 ) || ! V_116 ||
V_92 == V_111 ) {
return V_40 ;
}
F_30 ( & V_90 . V_22 ) ;
if ( ! F_87 ( V_116 , V_84 ) ) {
F_71 ( L_18 ,
V_92 , V_84 . V_116 , V_84 . V_114 ) ;
V_73 = V_127 ;
goto V_70;
}
V_85 = F_51 ( V_84 ) ;
if ( ! V_85 ) {
F_71 ( L_19 ,
V_92 , V_84 . V_116 , V_84 . V_114 ) ;
V_73 = V_127 ;
goto V_70;
}
if ( V_92 != V_85 -> V_148 && V_92 != V_85 -> V_149 ) {
V_73 = V_179 ;
goto V_70;
}
if ( V_92 == V_85 -> V_148 ) {
V_106 = V_85 -> V_149 ;
V_85 -> V_148 = V_111 ;
} else {
V_106 = V_85 -> V_148 ;
V_85 -> V_149 = V_111 ;
}
V_85 -> V_87 . V_112 -- ;
V_142 = V_85 -> V_87 . V_14 & V_128 ;
if ( V_92 != V_147 ) {
bool V_180 ;
F_29 ( V_85 -> V_50 ) ;
V_180 = V_85 -> V_50 -> V_19 ||
V_85 -> V_51 -> V_19 ;
if ( F_100 ( V_85 ) ) {
V_73 =
F_43 ( V_181 ,
V_85 -> V_50 ,
V_85 -> V_51 ) ;
if ( V_73 < V_41 )
F_38 ( L_20 ,
V_84 . V_116 , V_84 . V_114 ,
V_73 ) ;
if ( V_85 -> V_156 )
F_40 ( V_85 -> V_50 ,
V_85 ->
V_51 ) ;
else
F_40 ( V_85 -> V_50 ,
V_85 ->
V_51 ) ;
}
if ( ! V_180 )
F_99 ( V_85 ) ;
F_31 ( V_85 -> V_50 ) ;
if ( ! V_180 && V_85 -> V_139 )
V_85 -> V_139 ( V_85 -> V_140 ) ;
} else {
if ( V_85 -> V_139 ) {
V_85 -> V_139 = NULL ;
V_85 -> V_140 = NULL ;
}
}
if ( V_85 -> V_87 . V_112 == 0 ) {
F_67 ( & V_90 , & V_85 -> V_87 ) ;
if ( V_142 )
F_16 ( V_85 -> V_158 ) ;
F_28 ( V_85 -> V_50 , V_85 -> V_51 ) ;
F_25 ( V_85 -> V_50 , V_85 -> V_87 . V_108 ) ;
F_25 ( V_85 -> V_51 , V_85 -> V_87 . V_109 ) ;
F_61 ( & V_85 -> V_114 ) ;
F_16 ( V_85 ) ;
F_101 ( V_116 , V_84 ) ;
} else {
F_79 ( false , V_84 , V_92 , V_106 ) ;
if ( V_92 == V_147 &&
F_100 ( V_85 ) ) {
V_85 -> V_150 = V_182 ;
} else {
V_85 -> V_150 = V_183 ;
}
if ( ! V_142 )
F_101 ( V_116 , V_84 ) ;
}
V_73 = V_41 ;
V_70:
F_32 ( & V_90 . V_22 ) ;
return V_73 ;
}
int F_102 ( struct V_83 V_84 ,
struct V_138 * V_116 ,
T_1 V_184 )
{
struct V_89 * V_85 ;
const T_2 V_92 = F_74 ( V_116 ) ;
bool V_142 = false ;
int V_73 ;
if ( F_46 ( V_84 ) || ! V_116 ||
V_92 == V_111 )
return V_40 ;
F_30 ( & V_90 . V_22 ) ;
if ( ! F_87 ( V_116 , V_84 ) ) {
F_71 ( L_18 ,
V_92 , V_84 . V_116 , V_84 . V_114 ) ;
V_73 = V_127 ;
goto V_70;
}
V_85 = F_51 ( V_84 ) ;
if ( ! V_85 ) {
F_71 ( L_21 ,
V_92 , V_84 . V_116 , V_84 . V_114 ) ;
V_73 = V_127 ;
goto V_70;
}
if ( V_92 != V_85 -> V_148 && V_92 != V_85 -> V_149 ) {
V_73 = V_179 ;
goto V_70;
}
V_142 = V_85 -> V_87 . V_14 & V_128 ;
V_73 = V_41 ;
if ( V_92 != V_147 ) {
struct V_71 V_72 ;
V_72 . V_64 = V_184 ;
V_72 . V_185 = F_77 ( V_85 -> V_87 ) ;
F_29 ( V_85 -> V_50 ) ;
F_99 ( V_85 ) ;
V_73 =
F_39 ( & V_72 ,
V_85 -> V_50 ,
V_85 -> V_51 ) ;
F_31 ( V_85 -> V_50 ) ;
if ( V_73 == V_41 ) {
V_85 -> V_150 ++ ;
if ( V_85 -> V_139 )
V_85 -> V_139 ( V_85 -> V_140 ) ;
}
}
V_70:
F_32 ( & V_90 . V_22 ) ;
return V_73 ;
}
static int F_103 ( struct V_89 * V_85 )
{
int V_73 ;
if ( V_85 -> V_50 -> V_20 != NULL &&
V_85 -> V_51 -> V_20 != NULL ) {
return V_41 ;
}
if ( NULL == V_85 -> V_50 -> V_19 ||
NULL == V_85 -> V_51 -> V_19 ) {
V_73 = F_41 ( V_85 -> V_50 , V_85 -> V_51 ) ;
if ( V_73 < V_41 )
return V_73 ;
}
memcpy ( & V_85 -> V_186 , V_85 -> V_50 -> V_19 ,
sizeof( V_85 -> V_186 ) ) ;
V_85 -> V_50 -> V_20 = & V_85 -> V_186 ;
memcpy ( & V_85 -> V_187 , V_85 -> V_51 -> V_19 ,
sizeof( V_85 -> V_187 ) ) ;
V_85 -> V_51 -> V_20 = & V_85 -> V_187 ;
return V_41 ;
}
int F_104 ( struct V_83 V_84 ,
struct V_138 * V_116 ,
T_2 V_80 )
{
struct V_89 * V_85 ;
const T_2 V_92 = F_74 ( V_116 ) ;
bool V_142 = false ;
int V_73 ;
if ( F_46 ( V_84 ) || ! V_116 ||
V_92 == V_111 )
return V_40 ;
F_30 ( & V_90 . V_22 ) ;
if ( ! F_87 ( V_116 , V_84 ) ) {
F_71 ( L_18 ,
V_92 , V_84 . V_116 , V_84 . V_114 ) ;
V_73 = V_127 ;
goto V_70;
}
V_85 = F_51 ( V_84 ) ;
if ( ! V_85 ) {
F_71 ( L_21 ,
V_92 , V_84 . V_116 , V_84 . V_114 ) ;
V_73 = V_127 ;
goto V_70;
}
if ( V_92 != V_85 -> V_148 && V_92 != V_85 -> V_149 ) {
V_73 = V_179 ;
goto V_70;
}
V_142 = V_85 -> V_87 . V_14 & V_128 ;
if ( V_92 != V_147 ) {
F_29 ( V_85 -> V_50 ) ;
V_73 = F_103 ( V_85 ) ;
if ( V_73 < V_41 )
F_38 ( L_22 ,
V_84 . V_116 , V_84 . V_114 , V_73 ) ;
F_43 ( V_80 , V_85 -> V_50 , V_85 -> V_51 ) ;
F_40 ( V_85 -> V_50 ,
V_85 -> V_51 ) ;
V_85 -> V_150 -- ;
F_31 ( V_85 -> V_50 ) ;
}
V_73 = V_41 ;
V_70:
F_32 ( & V_90 . V_22 ) ;
return V_73 ;
}
void F_105 ( void )
{
struct V_81 * V_85 ;
struct V_86 * V_188 ;
F_30 ( & V_88 . V_22 ) ;
while ( ( V_85 = F_93 ( & V_88 ) ) ) {
V_188 = (struct V_86 * ) V_85 ;
if ( ! ( V_85 -> V_14 & V_128 ) )
F_64 ( V_85 -> V_84 ) ;
V_85 -> V_112 = 0 ;
F_67 ( & V_88 , V_85 ) ;
F_60 ( V_188 ) ;
}
F_32 ( & V_88 . V_22 ) ;
}
static void F_106 ( const struct V_189 * V_190 )
{
F_29 ( V_190 -> V_50 ) ;
}
static void F_107 ( const struct V_189 * V_190 )
{
F_31 ( V_190 -> V_50 ) ;
}
static int F_108 ( struct V_3 * V_50 ,
struct V_3 * V_51 )
{
int V_73 ;
if ( NULL == V_50 -> V_19 || NULL == V_51 -> V_19 ) {
V_73 = F_41 ( V_50 , V_51 ) ;
if ( V_73 < V_41 )
return ( V_50 -> V_20 &&
V_51 -> V_20 ) ?
V_191 :
V_179 ;
}
return V_41 ;
}
static int F_109 ( const struct V_189 * V_190 ,
struct V_79 * * V_192 ,
struct V_79 * * V_193 )
{
int V_73 ;
V_73 = F_108 ( V_190 -> V_50 , V_190 -> V_51 ) ;
if ( V_73 == V_41 ) {
* V_192 = V_190 -> V_50 -> V_19 ;
* V_193 = V_190 -> V_51 -> V_19 ;
} else if ( V_190 -> V_50 -> V_20 &&
V_190 -> V_51 -> V_20 ) {
* V_192 = V_190 -> V_50 -> V_20 ;
* V_193 = V_190 -> V_51 -> V_20 ;
V_73 = V_41 ;
}
return V_73 ;
}
static int F_110 ( void * V_140 )
{
struct V_189 * V_190 = (struct V_189 * ) V_140 ;
F_106 ( V_190 ) ;
while ( V_190 -> V_194 > 0 ) {
V_190 -> V_194 -- ;
V_190 -> V_195 ++ ;
F_111 ( & V_190 -> V_102 ) ;
}
F_107 ( V_190 ) ;
return V_41 ;
}
static bool F_112 ( struct V_189 * V_190 )
{
unsigned int V_195 ;
V_190 -> V_194 ++ ;
V_195 = V_190 -> V_195 ;
F_107 ( V_190 ) ;
F_113 ( V_190 -> V_102 , V_195 != V_190 -> V_195 ) ;
F_106 ( V_190 ) ;
return true ;
}
static T_5 F_114 ( struct V_3 * V_50 ,
struct V_3 * V_51 ,
const T_1 V_196 ,
const void * V_197 ,
T_3 V_198 ,
T_6 V_199 )
{
T_7 V_200 ;
T_1 V_201 ;
T_3 V_202 ;
T_5 V_73 ;
V_73 = F_108 ( V_50 , V_51 ) ;
if ( F_115 ( V_73 != V_41 ) )
return V_73 ;
V_200 = F_116 ( V_50 -> V_19 ,
V_51 -> V_19 ,
V_196 ) ;
if ( V_200 == 0 )
return V_203 ;
if ( V_200 < V_41 )
return ( T_5 ) V_200 ;
V_202 = ( T_3 ) ( V_200 > V_198 ? V_198 : V_200 ) ;
V_201 = F_117 ( V_50 -> V_19 ) ;
if ( F_118 ( V_201 + V_202 < V_196 ) ) {
V_73 = V_199 ( V_50 , V_201 , V_197 , 0 , V_202 ) ;
} else {
const T_3 V_157 = ( T_3 ) ( V_196 - V_201 ) ;
V_73 = V_199 ( V_50 , V_201 , V_197 , 0 , V_157 ) ;
if ( V_73 >= V_41 )
V_73 = V_199 ( V_50 , 0 , V_197 , V_157 ,
V_202 - V_157 ) ;
}
if ( V_73 < V_41 )
return V_73 ;
F_119 ( V_50 -> V_19 , V_202 ,
V_196 ) ;
return V_202 ;
}
static T_5 F_120 ( struct V_3 * V_50 ,
struct V_3 * V_51 ,
const T_1 V_204 ,
void * V_197 ,
T_3 V_198 ,
T_8 V_205 ,
bool V_206 )
{
T_7 V_207 ;
T_1 V_126 ;
T_3 V_208 ;
T_5 V_73 ;
V_73 = F_108 ( V_50 , V_51 ) ;
if ( F_115 ( V_73 != V_41 ) )
return V_73 ;
V_207 = F_121 ( V_51 -> V_19 ,
V_50 -> V_19 ,
V_204 ) ;
if ( V_207 == 0 )
return V_209 ;
if ( V_207 < V_41 )
return ( T_5 ) V_207 ;
V_208 = ( T_3 ) ( V_207 > V_198 ? V_198 : V_207 ) ;
V_126 = F_122 ( V_50 -> V_19 ) ;
if ( F_118 ( V_126 + V_208 < V_204 ) ) {
V_73 = V_205 ( V_197 , 0 , V_51 , V_126 , V_208 ) ;
} else {
const T_3 V_157 = ( T_3 ) ( V_204 - V_126 ) ;
V_73 = V_205 ( V_197 , 0 , V_51 , V_126 , V_157 ) ;
if ( V_73 >= V_41 )
V_73 = V_205 ( V_197 , V_157 , V_51 , 0 ,
V_208 - V_157 ) ;
}
if ( V_73 < V_41 )
return V_73 ;
if ( V_206 )
F_123 ( V_50 -> V_19 ,
V_208 , V_204 ) ;
return V_208 ;
}
int F_124 ( struct V_189 * * V_190 ,
struct V_83 * V_84 ,
T_1 V_210 ,
T_1 V_211 ,
T_2 V_107 ,
T_2 V_14 ,
T_2 V_129 )
{
struct V_189 * V_212 ;
int V_68 ;
struct V_83 V_28 = V_175 ;
struct V_83 V_96 = F_54 ( V_107 , V_111 ) ;
enum V_213 V_214 ;
T_4 V_139 ;
void * V_140 ;
if ( V_210 + V_211 < V_215 ( V_210, V_211 ) ||
V_210 + V_211 > V_216 )
return V_217 ;
V_68 = V_213 ( & V_28 , & V_96 , false , & V_214 ) ;
if ( V_68 < V_41 )
V_214 = F_125 () ?
V_218 : V_219 ;
if ( V_14 & ( V_220 | V_221 ) ) {
F_71 ( L_23 ) ;
return V_40 ;
}
V_212 = F_24 ( sizeof( * V_212 ) , V_26 ) ;
if ( ! V_212 )
return V_54 ;
V_212 -> V_196 = V_210 ;
V_212 -> V_204 = V_211 ;
V_212 -> V_107 = V_107 ;
V_212 -> V_14 = V_14 ;
V_212 -> V_129 = V_129 ;
V_139 = NULL ;
V_140 = NULL ;
if ( V_219 == V_214 ) {
V_212 -> V_176 = false ;
if ( ! ( V_14 & V_128 ) ) {
V_212 -> V_194 = 0 ;
V_212 -> V_195 = 0 ;
F_126 ( & V_212 -> V_102 ) ;
V_139 = F_110 ;
V_140 = ( void * ) V_212 ;
}
} else {
V_212 -> V_176 = true ;
}
V_68 = F_89 ( V_84 ,
& V_212 -> V_50 ,
V_212 -> V_196 ,
& V_212 -> V_51 ,
V_212 -> V_204 ,
V_212 -> V_107 ,
V_212 -> V_14 ,
V_212 -> V_129 ,
V_212 -> V_176 ,
V_139 , V_140 ) ;
if ( V_68 < V_41 ) {
F_16 ( V_212 ) ;
return V_68 ;
}
* V_190 = V_212 ;
V_212 -> V_84 = * V_84 ;
return V_68 ;
}
int F_127 ( struct V_189 * * V_190 )
{
int V_73 ;
struct V_189 * V_222 ;
if ( ! V_190 || ! ( * V_190 ) )
return V_40 ;
V_222 = * V_190 ;
V_73 = F_92 ( V_222 -> V_84 , V_222 -> V_176 ) ;
memset ( V_222 , 0 , sizeof( * V_222 ) ) ;
V_222 -> V_84 = V_175 ;
V_222 -> V_107 = V_111 ;
F_16 ( V_222 ) ;
* V_190 = NULL ;
return V_73 ;
}
int F_128 ( const struct V_189 * V_190 ,
T_1 * V_223 ,
T_1 * V_224 )
{
struct V_79 * V_192 ;
struct V_79 * V_193 ;
int V_73 ;
if ( ! V_190 )
return V_40 ;
F_106 ( V_190 ) ;
V_73 =
F_109 ( V_190 , & V_192 , & V_193 ) ;
if ( V_73 == V_41 )
F_129 ( V_192 , V_193 ,
V_223 , V_224 ) ;
F_107 ( V_190 ) ;
if ( V_73 == V_41 &&
( ( V_223 && * V_223 >= V_190 -> V_196 ) ||
( V_224 && * V_224 >= V_190 -> V_196 ) ) )
return V_225 ;
return V_73 ;
}
int F_130 ( const struct V_189 * V_190 ,
T_1 * V_226 ,
T_1 * V_227 )
{
struct V_79 * V_192 ;
struct V_79 * V_193 ;
int V_73 ;
if ( ! V_190 )
return V_40 ;
F_106 ( V_190 ) ;
V_73 =
F_109 ( V_190 , & V_192 , & V_193 ) ;
if ( V_73 == V_41 )
F_129 ( V_193 , V_192 ,
V_226 , V_227 ) ;
F_107 ( V_190 ) ;
if ( V_73 == V_41 &&
( ( V_226 && * V_226 >= V_190 -> V_204 ) ||
( V_227 && * V_227 >= V_190 -> V_204 ) ) )
return V_225 ;
return V_73 ;
}
T_7 F_131 ( const struct V_189 * V_190 )
{
struct V_79 * V_192 ;
struct V_79 * V_193 ;
T_7 V_73 ;
if ( ! V_190 )
return V_40 ;
F_106 ( V_190 ) ;
V_73 =
F_109 ( V_190 , & V_192 , & V_193 ) ;
if ( V_73 == V_41 )
V_73 = F_116 ( V_192 ,
V_193 ,
V_190 -> V_196 ) ;
else
V_73 = 0 ;
F_107 ( V_190 ) ;
return V_73 ;
}
T_7 F_132 ( const struct V_189 * V_190 )
{
struct V_79 * V_192 ;
struct V_79 * V_193 ;
T_7 V_73 ;
if ( ! V_190 )
return V_40 ;
F_106 ( V_190 ) ;
V_73 =
F_109 ( V_190 , & V_192 , & V_193 ) ;
if ( V_73 == V_41 )
V_73 = F_116 ( V_193 ,
V_192 ,
V_190 -> V_204 ) ;
else
V_73 = 0 ;
F_107 ( V_190 ) ;
return V_73 ;
}
T_7 F_133 ( const struct V_189 * V_190 )
{
struct V_79 * V_192 ;
struct V_79 * V_193 ;
T_7 V_73 ;
if ( ! V_190 )
return V_40 ;
F_106 ( V_190 ) ;
V_73 =
F_109 ( V_190 , & V_192 , & V_193 ) ;
if ( V_73 == V_41 )
V_73 = F_121 ( V_192 ,
V_193 ,
V_190 -> V_196 ) ;
else
V_73 = 0 ;
F_107 ( V_190 ) ;
return V_73 ;
}
T_7 F_134 ( const struct V_189 * V_190 )
{
struct V_79 * V_192 ;
struct V_79 * V_193 ;
T_7 V_73 ;
if ( ! V_190 )
return V_40 ;
F_106 ( V_190 ) ;
V_73 =
F_109 ( V_190 , & V_192 , & V_193 ) ;
if ( V_73 == V_41 )
V_73 = F_121 ( V_193 ,
V_192 ,
V_190 -> V_204 ) ;
else
V_73 = 0 ;
F_107 ( V_190 ) ;
return V_73 ;
}
T_5 F_135 ( struct V_189 * V_190 ,
const void * V_197 ,
T_3 V_198 ,
int V_228 )
{
T_5 V_73 ;
if ( ! V_190 || ! V_197 )
return V_40 ;
F_106 ( V_190 ) ;
do {
V_73 = F_114 ( V_190 -> V_50 ,
V_190 -> V_51 ,
V_190 -> V_196 ,
V_197 , V_198 ,
F_19 ) ;
if ( V_73 == V_191 &&
! F_112 ( V_190 ) )
V_73 = V_229 ;
} while ( V_73 == V_191 );
F_107 ( V_190 ) ;
return V_73 ;
}
T_5 F_136 ( struct V_189 * V_190 ,
void * V_197 ,
T_3 V_198 ,
int V_228 )
{
T_5 V_73 ;
if ( ! V_190 || ! V_197 )
return V_40 ;
F_106 ( V_190 ) ;
do {
V_73 = F_120 ( V_190 -> V_50 ,
V_190 -> V_51 ,
V_190 -> V_204 ,
V_197 , V_198 ,
F_20 , true ) ;
if ( V_73 == V_191 &&
! F_112 ( V_190 ) )
V_73 = V_229 ;
} while ( V_73 == V_191 );
F_107 ( V_190 ) ;
return V_73 ;
}
T_5 F_137 ( struct V_189 * V_190 ,
void * V_197 ,
T_3 V_198 ,
int V_228 )
{
T_5 V_73 ;
if ( ! V_190 || ! V_197 )
return V_40 ;
F_106 ( V_190 ) ;
do {
V_73 = F_120 ( V_190 -> V_50 ,
V_190 -> V_51 ,
V_190 -> V_204 ,
V_197 , V_198 ,
F_20 , false ) ;
if ( V_73 == V_191 &&
! F_112 ( V_190 ) )
V_73 = V_229 ;
} while ( V_73 == V_191 );
F_107 ( V_190 ) ;
return V_73 ;
}
T_5 F_138 ( struct V_189 * V_190 ,
struct V_37 * V_38 ,
T_3 V_230 ,
int V_228 )
{
T_5 V_73 ;
if ( ! V_190 )
return V_40 ;
F_106 ( V_190 ) ;
do {
V_73 = F_114 ( V_190 -> V_50 ,
V_190 -> V_51 ,
V_190 -> V_196 ,
V_38 , V_230 ,
F_21 ) ;
if ( V_73 == V_191 &&
! F_112 ( V_190 ) )
V_73 = V_229 ;
} while ( V_73 == V_191 );
F_107 ( V_190 ) ;
return V_73 ;
}
T_5 F_139 ( struct V_189 * V_190 ,
struct V_37 * V_38 ,
T_3 V_230 ,
int V_228 )
{
T_5 V_73 ;
if ( ! V_190 )
return V_40 ;
F_106 ( V_190 ) ;
do {
V_73 = F_120 ( V_190 -> V_50 ,
V_190 -> V_51 ,
V_190 -> V_204 ,
V_38 , V_230 ,
F_22 ,
true ) ;
if ( V_73 == V_191 &&
! F_112 ( V_190 ) )
V_73 = V_229 ;
} while ( V_73 == V_191 );
F_107 ( V_190 ) ;
return V_73 ;
}
T_5 F_140 ( struct V_189 * V_190 ,
struct V_37 * V_38 ,
T_3 V_230 ,
int V_228 )
{
T_5 V_73 ;
if ( ! V_190 )
return V_40 ;
F_106 ( V_190 ) ;
do {
V_73 = F_120 ( V_190 -> V_50 ,
V_190 -> V_51 ,
V_190 -> V_204 ,
V_38 , V_230 ,
F_22 ,
false ) ;
if ( V_73 == V_191 &&
! F_112 ( V_190 ) )
V_73 = V_229 ;
} while ( V_73 == V_191 );
F_107 ( V_190 ) ;
return V_73 ;
}
