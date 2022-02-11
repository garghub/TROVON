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
V_94 . V_95 . V_96 . V_97 = F_54 ( V_92 , V_98 ) ;
V_94 . V_95 . V_96 . V_28 = F_54 ( V_99 ,
V_100 ) ;
V_94 . V_95 . V_96 . V_101 = sizeof( V_94 ) - sizeof( V_94 . V_95 . V_96 ) ;
V_94 . V_95 . V_102 . V_103 =
V_91 ? V_104 : V_105 ;
V_94 . V_106 . V_107 = V_92 ;
V_94 . V_106 . V_84 = V_84 ;
return F_55 ( & V_94 . V_95 . V_96 ) ;
}
static struct V_86 *
F_56 ( struct V_83 V_84 ,
T_2 V_108 ,
T_2 V_14 ,
T_1 V_109 ,
T_1 V_110 ,
void * V_50 ,
void * V_51 )
{
int V_73 ;
struct V_86 * V_85 ;
const T_1 V_111 = F_2 ( V_109 , V_6 ) +
F_2 ( V_110 , V_6 ) + 2 ;
if ( F_46 ( V_84 ) ) {
T_2 V_92 = F_53 () ;
V_84 = F_54 ( V_92 , V_112 ) ;
}
V_85 = F_24 ( sizeof( * V_85 ) , V_26 ) ;
if ( V_85 ) {
V_85 -> V_87 . V_108 = V_108 ;
V_85 -> V_87 . V_14 = V_14 ;
V_85 -> V_87 . V_109 = V_109 ;
V_85 -> V_87 . V_110 = V_110 ;
V_85 -> V_87 . V_113 = 0 ;
V_85 -> V_111 = V_111 ;
V_85 -> V_50 = V_50 ;
V_85 -> V_51 = V_51 ;
F_57 ( & V_85 -> V_87 . V_114 ) ;
V_73 = F_58 ( & V_85 -> V_115 ,
V_116 ,
V_84 ) ;
V_85 -> V_87 . V_84 = F_59 ( & V_85 -> V_115 ) ;
if ( ( V_73 != V_41 ) ||
F_45 ( & V_88 , V_85 -> V_87 . V_84 ) ) {
F_38 ( L_4 ,
V_84 . V_117 , V_84 . V_115 , V_73 ) ;
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
F_1 ( V_85 -> V_50 , V_85 -> V_87 . V_109 ) ;
F_1 ( V_85 -> V_51 , V_85 -> V_87 . V_110 ) ;
F_61 ( & V_85 -> V_115 ) ;
F_16 ( V_85 ) ;
}
static int F_62 ( const struct V_86 * V_85 )
{
struct V_118 * V_119 ;
T_3 V_120 ;
int V_73 ;
if ( ! V_85 || V_85 -> V_111 <= 2 )
return V_40 ;
V_120 = sizeof( * V_119 ) +
( T_3 ) V_85 -> V_111 * sizeof( T_2 ) ;
V_119 = F_15 ( V_120 , V_26 ) ;
if ( ! V_119 )
return V_54 ;
V_119 -> V_96 . V_97 = F_54 ( V_99 ,
V_121 ) ;
V_119 -> V_96 . V_28 = V_122 ;
V_119 -> V_96 . V_101 = V_120 - V_123 ;
V_119 -> V_84 = V_85 -> V_87 . V_84 ;
V_119 -> V_108 = V_85 -> V_87 . V_108 ;
V_119 -> V_14 = V_85 -> V_87 . V_14 ;
V_119 -> V_109 = V_85 -> V_87 . V_109 ;
V_119 -> V_110 = V_85 -> V_87 . V_110 ;
V_119 -> V_111 = V_85 -> V_111 ;
V_73 = F_18 ( ( V_24 * ) V_119 + sizeof( * V_119 ) ,
& V_85 -> V_47 ) ;
if ( V_73 == V_41 )
V_73 = F_63 ( & V_119 -> V_96 ) ;
F_16 ( V_119 ) ;
return V_73 ;
}
static int F_64 ( struct V_83 V_84 )
{
struct V_124 V_125 ;
V_125 . V_96 . V_97 = F_54 ( V_99 ,
V_126 ) ;
V_125 . V_96 . V_28 = V_122 ;
V_125 . V_96 . V_101 = sizeof( V_84 ) ;
V_125 . V_84 = V_84 ;
return F_63 ( & V_125 . V_96 ) ;
}
static void F_65 ( struct V_82 * V_82 , struct V_81 * V_85 )
{
if ( V_85 )
F_66 ( & V_85 -> V_114 , & V_82 -> V_127 ) ;
}
static void F_67 ( struct V_82 * V_82 ,
struct V_81 * V_85 )
{
if ( V_85 )
F_68 ( & V_85 -> V_114 ) ;
}
static int F_69 ( struct V_83 V_84 )
{
int V_73 ;
struct V_86 * V_85 ;
T_2 V_113 = ~ 0 ;
F_30 ( & V_88 . V_22 ) ;
V_85 = F_49 ( V_84 ) ;
if ( ! V_85 ) {
F_32 ( & V_88 . V_22 ) ;
return V_128 ;
}
if ( V_85 -> V_87 . V_14 & V_129 ) {
V_73 = V_41 ;
if ( V_85 -> V_87 . V_113 > 1 ) {
V_73 = F_52 ( false , V_84 ) ;
}
} else {
V_73 = F_64 ( V_84 ) ;
if ( V_73 < V_41 ) {
F_32 ( & V_88 . V_22 ) ;
return V_73 ;
}
}
V_85 -> V_87 . V_113 -- ;
if ( V_85 -> V_87 . V_113 == 0 )
F_67 ( & V_88 , & V_85 -> V_87 ) ;
if ( V_85 )
V_113 = V_85 -> V_87 . V_113 ;
F_32 ( & V_88 . V_22 ) ;
if ( V_113 == 0 )
F_60 ( V_85 ) ;
return V_73 ;
}
static int F_70 ( struct V_83 * V_84 ,
struct V_3 * * V_50 ,
T_1 V_109 ,
struct V_3 * * V_51 ,
T_1 V_110 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 )
{
const T_1 V_44 =
F_2 ( V_109 , V_6 ) + 1 ;
const T_1 V_46 =
F_2 ( V_110 , V_6 ) + 1 ;
void * V_131 = NULL ;
void * V_132 = NULL ;
int V_73 ;
struct V_86 * V_133 = NULL ;
if ( V_130 != V_134 )
return V_135 ;
F_30 ( & V_88 . V_22 ) ;
V_133 = F_49 ( * V_84 ) ;
if ( V_133 ) {
if ( V_133 -> V_87 . V_14 & V_129 ) {
if ( V_133 -> V_87 . V_113 > 1 ) {
F_71 ( L_5 ) ;
V_73 = V_76 ;
goto V_136;
}
if ( V_133 -> V_87 . V_109 != V_110 ||
V_133 -> V_87 . V_110 !=
V_109 ||
V_133 -> V_87 . V_14 !=
( V_14 & ~ V_137 ) ) {
F_71 ( L_6 ) ;
V_73 = V_75 ;
goto V_136;
}
V_73 = F_52 ( true , * V_84 ) ;
if ( V_73 < V_41 )
goto V_136;
V_131 = V_133 -> V_51 ;
V_132 = V_133 -> V_50 ;
goto V_70;
}
V_73 = V_53 ;
goto V_136;
}
V_131 = F_5 ( V_109 , V_14 ) ;
if ( ! V_131 ) {
F_38 ( L_7 ) ;
V_73 = V_54 ;
goto error;
}
V_132 = F_5 ( V_110 , V_14 ) ;
if ( ! V_132 ) {
F_38 ( L_8 ) ;
V_73 = V_54 ;
goto error;
}
V_133 = F_56 ( * V_84 , V_108 , V_14 ,
V_109 , V_110 ,
V_131 , V_132 ) ;
if ( ! V_133 ) {
F_38 ( L_9 , V_138 ) ;
V_73 = V_54 ;
goto error;
}
V_73 = F_14 ( V_131 , V_44 , V_132 ,
V_46 ,
& V_133 -> V_47 ) ;
if ( V_73 < V_41 ) {
F_38 ( L_10 ) ;
goto error;
}
if ( V_133 -> V_87 . V_14 & V_129 ) {
T_2 V_92 = F_53 () ;
if ( V_133 -> V_87 . V_84 . V_117 != V_92 ||
( V_133 -> V_87 . V_108 != V_112 &&
V_133 -> V_87 . V_108 != V_92 ) ) {
V_73 = V_135 ;
goto error;
}
if ( V_133 -> V_87 . V_14 & V_137 ) {
V_73 = V_128 ;
goto error;
}
} else {
V_73 = F_62 ( V_133 ) ;
if ( V_73 < V_41 ) {
F_38 ( L_11 , V_73 ) ;
goto error;
}
}
F_26 ( (struct V_3 * ) V_131 ,
(struct V_3 * ) V_132 ) ;
F_65 ( & V_88 , & V_133 -> V_87 ) ;
V_70:
V_133 -> V_87 . V_113 ++ ;
* V_84 = V_133 -> V_87 . V_84 ;
* V_50 = (struct V_3 * ) V_131 ;
* V_51 = (struct V_3 * ) V_132 ;
if ( ( V_133 -> V_87 . V_14 & V_129 ) &&
V_133 -> V_87 . V_113 == 1 ) {
F_72 ( ( * V_50 ) -> V_19 , * V_84 ) ;
F_72 ( ( * V_51 ) -> V_19 , * V_84 ) ;
}
F_32 ( & V_88 . V_22 ) ;
return V_41 ;
error:
F_32 ( & V_88 . V_22 ) ;
if ( V_133 ) {
F_60 ( V_133 ) ;
} else {
F_1 ( V_131 , V_109 ) ;
F_1 ( V_132 , V_110 ) ;
}
return V_73 ;
V_136:
F_32 ( & V_88 . V_22 ) ;
return V_73 ;
}
static int F_73 ( struct V_83 V_84 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
T_1 V_109 ,
T_1 V_110 ,
struct V_71 * V_72 ,
struct V_139 * V_117 ,
T_4 V_140 ,
void * V_141 , struct V_89 * * V_142 )
{
struct V_89 * V_85 = NULL ;
const T_2 V_92 = F_74 ( V_117 ) ;
bool V_143 = V_14 & V_129 ;
int V_73 ;
T_1 V_144 ;
T_1 V_145 ;
if ( V_14 & V_137 )
return V_128 ;
if ( V_84 . V_117 != V_92 && V_84 . V_117 != V_108 )
return V_135 ;
if ( F_75 ( V_92 ) && F_75 ( V_108 ) )
return V_146 ;
if ( V_143 && V_108 != V_112 && V_92 != V_108 )
return V_135 ;
V_85 = F_24 ( sizeof( * V_85 ) , V_147 ) ;
if ( ! V_85 )
return V_54 ;
if ( F_74 ( V_117 ) == V_148 && ! V_143 ) {
V_144 = V_110 ;
V_145 = V_109 ;
} else {
V_144 = V_109 ;
V_145 = V_110 ;
}
V_85 -> V_87 . V_84 = V_84 ;
V_85 -> V_87 . V_108 = V_108 ;
V_85 -> V_87 . V_14 = V_14 ;
V_85 -> V_87 . V_109 = V_144 ;
V_85 -> V_87 . V_110 = V_145 ;
V_85 -> V_87 . V_113 = 1 ;
V_85 -> V_149 = V_92 ;
V_85 -> V_150 = V_112 ;
V_85 -> V_151 = V_152 ;
V_85 -> V_153 =
! ! ( V_117 -> V_130 & V_154 ) ;
V_85 -> V_155 =
! ! ( V_130 & V_156 ) ;
V_85 -> V_157 = false ;
V_85 -> V_140 = V_140 ;
V_85 -> V_141 = V_141 ;
V_85 -> V_50 = F_23 ( V_144 ) ;
if ( V_85 -> V_50 == NULL ) {
V_73 = V_54 ;
goto error;
}
V_85 -> V_51 = F_23 ( V_145 ) ;
if ( V_85 -> V_51 == NULL ) {
V_73 = V_54 ;
goto error;
}
F_26 ( V_85 -> V_50 , V_85 -> V_51 ) ;
F_57 ( & V_85 -> V_87 . V_114 ) ;
if ( V_143 ) {
V_24 * V_158 ;
V_85 -> V_159 = F_76 ( F_77 ( V_85 -> V_87 ) ,
V_6 , V_26 ) ;
if ( V_85 -> V_159 == NULL ) {
V_73 = V_54 ;
goto error;
}
V_85 -> V_151 = V_160 ;
V_85 -> V_50 -> V_19 = V_85 -> V_159 ;
V_158 = ( V_24 * ) V_85 -> V_159 + V_6 *
( F_2 ( V_85 -> V_87 . V_109 , V_6 ) + 1 ) ;
V_85 -> V_51 -> V_19 = (struct V_79 * ) V_158 ;
} else if ( V_72 ) {
V_73 = F_39 ( V_72 ,
V_85 -> V_50 ,
V_85 -> V_51 ) ;
if ( V_73 < V_41 )
goto error;
V_85 -> V_151 = V_160 ;
} else {
V_85 -> V_151 = V_161 ;
}
F_65 ( & V_90 , & V_85 -> V_87 ) ;
if ( V_142 != NULL )
* V_142 = V_85 ;
V_73 = F_58 ( & V_85 -> V_115 ,
V_162 ,
V_84 ) ;
if ( V_73 != V_41 ) {
F_38 ( L_4 ,
V_84 . V_117 , V_84 . V_115 , V_73 ) ;
goto error;
}
V_85 -> V_87 . V_84 = F_59 ( & V_85 -> V_115 ) ;
if ( V_143 ) {
F_72 ( V_85 -> V_50 -> V_19 ,
V_85 -> V_87 . V_84 ) ;
F_72 ( V_85 -> V_51 -> V_19 ,
V_85 -> V_87 . V_84 ) ;
}
F_78 ( V_117 , V_85 -> V_87 . V_84 ) ;
return V_41 ;
error:
if ( V_85 != NULL ) {
F_25 ( V_85 -> V_50 , V_144 ) ;
F_25 ( V_85 -> V_51 , V_145 ) ;
F_16 ( V_85 ) ;
}
return V_73 ;
}
static int F_79 ( bool V_91 ,
struct V_83 V_84 ,
T_2 V_163 ,
T_2 V_107 )
{
int V_164 ;
struct V_93 V_94 ;
if ( F_46 ( V_84 ) || V_163 == V_112 ||
V_107 == V_112 )
return V_40 ;
V_94 . V_95 . V_96 . V_97 = F_54 ( V_107 , V_98 ) ;
V_94 . V_95 . V_96 . V_28 = F_54 ( V_99 ,
V_100 ) ;
V_94 . V_95 . V_96 . V_101 = sizeof( V_94 ) - sizeof( V_94 . V_95 . V_96 ) ;
V_94 . V_95 . V_102 . V_103 = V_91 ?
V_104 : V_105 ;
V_94 . V_106 . V_84 = V_84 ;
V_94 . V_106 . V_107 = V_163 ;
V_164 = F_80 ( V_99 ,
& V_94 . V_95 . V_96 , false ) ;
if ( V_164 < V_41 )
F_38 ( L_12 ,
V_91 ? L_13 : L_14 , V_107 ) ;
return V_164 ;
}
static int F_81 ( struct V_89 * V_85 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
T_1 V_109 ,
T_1 V_110 ,
struct V_71 * V_72 ,
struct V_139 * V_117 ,
T_4 V_140 ,
void * V_141 ,
struct V_89 * * V_142 )
{
const T_2 V_92 = F_74 ( V_117 ) ;
bool V_143 = V_14 & V_129 ;
int V_73 ;
if ( V_85 -> V_151 != V_161 &&
V_85 -> V_151 != V_160 )
return V_76 ;
if ( V_143 ) {
if ( ! ( V_85 -> V_87 . V_14 & V_129 ) ||
V_92 != V_85 -> V_149 ) {
return V_40 ;
}
} else if ( V_92 == V_85 -> V_149 ||
V_92 == V_85 -> V_150 ) {
return V_53 ;
}
if ( F_75 ( V_92 ) &&
F_75 ( V_85 -> V_149 ) )
return V_146 ;
if ( ( V_117 -> V_130 & V_154 ) &&
! V_85 -> V_155 )
return V_135 ;
if ( V_85 -> V_153 &&
( ! ( V_130 & V_156 ) ) )
return V_135 ;
if ( V_85 -> V_87 . V_108 != V_112 && V_85 -> V_87 . V_108 != V_92 )
return V_135 ;
if ( V_85 -> V_149 == V_148 ) {
if ( ! F_82 ( V_117 ) )
return V_165 ;
} else if ( V_92 == V_148 ) {
struct V_139 * V_166 ;
bool V_167 ;
V_166 = F_83 ( V_85 -> V_149 ) ;
V_167 = F_82 ( V_166 ) ;
F_84 ( V_166 ) ;
if ( ! V_167 )
return V_165 ;
}
if ( ( V_85 -> V_87 . V_14 & ~ V_168 ) != ( V_14 & ~ V_169 ) )
return V_75 ;
if ( V_92 != V_148 ) {
if ( V_85 -> V_87 . V_109 != V_109 ||
V_85 -> V_87 . V_110 != V_110 ) {
return V_75 ;
}
} else if ( V_85 -> V_87 . V_109 != V_110 ||
V_85 -> V_87 . V_110 != V_109 ) {
return V_75 ;
}
if ( V_92 != V_148 ) {
if ( V_85 -> V_151 != V_161 )
return V_40 ;
if ( V_72 != NULL ) {
V_73 = F_39 ( V_72 ,
V_85 -> V_50 ,
V_85 -> V_51 ) ;
if ( V_73 < V_41 )
return V_73 ;
V_85 -> V_151 = V_170 ;
} else {
V_85 -> V_151 = V_171 ;
}
} else if ( V_85 -> V_151 == V_161 ) {
return V_76 ;
} else {
V_85 -> V_151 = V_170 ;
}
if ( V_85 -> V_151 == V_170 ) {
V_73 =
F_79 ( true , V_85 -> V_87 . V_84 , V_92 ,
V_85 -> V_149 ) ;
if ( V_73 < V_41 )
F_38 ( L_15 ,
V_85 -> V_149 , V_85 -> V_87 . V_84 . V_117 ,
V_85 -> V_87 . V_84 . V_115 ) ;
}
V_85 -> V_150 = V_92 ;
V_85 -> V_87 . V_113 ++ ;
if ( V_140 ) {
V_85 -> V_140 = V_140 ;
V_85 -> V_141 = V_141 ;
}
if ( ! V_143 )
F_78 ( V_117 , V_85 -> V_87 . V_84 ) ;
if ( V_142 != NULL )
* V_142 = V_85 ;
return V_41 ;
}
static int F_85 ( struct V_83 V_84 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
T_1 V_109 ,
T_1 V_110 ,
struct V_71 * V_72 ,
struct V_139 * V_117 ,
T_4 V_140 ,
void * V_141 ,
struct V_89 * * V_142 ,
bool * V_172 )
{
const T_2 V_92 = F_74 ( V_117 ) ;
bool V_173 ;
struct V_89 * V_85 = NULL ;
bool V_143 = V_14 & V_129 ;
int V_73 ;
if ( F_46 ( V_84 ) ||
( V_14 & ~ V_174 ) || V_143 ||
! ( V_109 || V_110 ) ||
! V_117 || V_92 == V_112 ||
V_84 . V_117 == V_112 ) {
return V_40 ;
}
if ( V_72 && ! F_86 ( V_72 ) )
return V_40 ;
F_30 ( & V_90 . V_22 ) ;
if ( ! V_143 && F_87 ( V_117 , V_84 ) ) {
F_71 ( L_16 ,
V_92 , V_84 . V_117 , V_84 . V_115 ) ;
F_32 ( & V_90 . V_22 ) ;
return V_53 ;
}
if ( V_84 . V_115 != V_112 )
V_85 = F_51 ( V_84 ) ;
if ( ! V_85 ) {
V_173 = true ;
V_73 =
F_73 ( V_84 , V_108 , V_14 , V_130 ,
V_109 , V_110 , V_72 ,
V_117 , V_140 , V_141 , V_142 ) ;
} else {
V_173 = false ;
V_73 =
F_81 ( V_85 , V_108 , V_14 , V_130 ,
V_109 , V_110 , V_72 ,
V_117 , V_140 , V_141 , V_142 ) ;
}
F_32 ( & V_90 . V_22 ) ;
if ( V_172 )
* V_172 = ( V_92 == V_148 ) &&
! ( V_173 && V_143 ) ;
return V_73 ;
}
static int F_88 ( struct V_83 * V_84 ,
struct V_3 * * V_50 ,
T_1 V_109 ,
struct V_3 * * V_51 ,
T_1 V_110 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
T_4 V_140 ,
void * V_141 )
{
struct V_83 V_175 ;
struct V_139 * V_117 ;
struct V_89 * V_85 ;
int V_73 ;
bool V_172 ;
if ( F_46 ( * V_84 ) ) {
V_175 = F_54 (
V_148 , V_112 ) ;
} else
V_175 = * V_84 ;
V_117 = F_83 ( V_148 ) ;
V_85 = NULL ;
V_73 =
F_85 ( V_175 , V_108 , V_14 , V_130 ,
V_109 , V_110 , NULL , V_117 ,
V_140 , V_141 , & V_85 , & V_172 ) ;
if ( V_73 == V_41 ) {
if ( V_172 ) {
* V_50 = V_85 -> V_51 ;
* V_51 = V_85 -> V_50 ;
} else {
* V_50 = V_85 -> V_50 ;
* V_51 = V_85 -> V_51 ;
}
* V_84 = F_59 ( & V_85 -> V_115 ) ;
} else {
* V_84 = V_176 ;
F_71 ( L_17 ,
V_73 ) ;
}
F_84 ( V_117 ) ;
return V_73 ;
}
int F_89 ( struct V_83 * V_84 ,
struct V_3 * * V_50 ,
T_1 V_109 ,
struct V_3 * * V_51 ,
T_1 V_110 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
bool V_177 ,
T_4 V_140 ,
void * V_141 )
{
if ( ! V_84 || ! V_50 || ! V_51 ||
( ! V_109 && ! V_110 ) || ( V_14 & ~ V_174 ) )
return V_40 ;
if ( V_177 ) {
return F_70 ( V_84 , V_50 ,
V_109 , V_51 ,
V_110 , V_108 ,
V_14 , V_130 ) ;
} else {
return F_88 ( V_84 , V_50 ,
V_109 , V_51 ,
V_110 , V_108 , V_14 ,
V_130 , V_140 , V_141 ) ;
}
}
static int F_90 ( struct V_83 V_84 )
{
int V_73 ;
struct V_139 * V_117 ;
V_117 = F_83 ( V_148 ) ;
V_73 = F_91 ( V_84 , V_117 ) ;
F_84 ( V_117 ) ;
return V_73 ;
}
static int F_92 ( struct V_83 V_84 , bool V_177 )
{
if ( F_46 ( V_84 ) )
return V_40 ;
if ( V_177 )
return F_69 ( V_84 ) ;
else
return F_90 ( V_84 ) ;
}
static struct V_81 * F_93 ( struct V_82 * V_82 )
{
if ( ! F_94 ( & V_82 -> V_127 ) ) {
struct V_81 * V_85 =
F_95 ( & V_82 -> V_127 , struct V_81 ,
V_114 ) ;
return V_85 ;
}
return NULL ;
}
void F_96 ( void )
{
struct V_81 * V_85 ;
struct V_89 * V_178 ;
F_30 ( & V_90 . V_22 ) ;
while ( ( V_85 = F_93 ( & V_90 ) ) ) {
V_178 = (struct V_89 * ) V_85 ;
F_67 ( & V_90 , V_85 ) ;
F_16 ( V_178 ) ;
}
F_32 ( & V_90 . V_22 ) ;
}
int F_97 ( struct V_83 V_84 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 ,
T_1 V_109 ,
T_1 V_110 ,
struct V_71 * V_72 ,
struct V_139 * V_117 )
{
return F_85 ( V_84 , V_108 , V_14 , V_130 ,
V_109 , V_110 ,
V_72 , V_117 , NULL , NULL , NULL , NULL ) ;
}
int F_98 ( struct V_83 V_84 ,
T_1 V_66 ,
T_1 V_67 ,
struct V_139 * V_117 )
{
struct V_89 * V_85 ;
int V_73 ;
const T_2 V_92 = F_74 ( V_117 ) ;
if ( F_46 ( V_84 ) || ! V_117 ||
V_92 == V_112 )
return V_40 ;
if ( V_66 == 0 || V_67 == 0 )
return V_40 ;
F_30 ( & V_90 . V_22 ) ;
if ( ! F_87 ( V_117 , V_84 ) ) {
F_38 ( L_18 ,
V_92 , V_84 . V_117 , V_84 . V_115 ) ;
V_73 = V_128 ;
goto V_70;
}
V_85 = F_51 ( V_84 ) ;
if ( ! V_85 ) {
V_73 = V_128 ;
goto V_70;
}
if ( V_85 -> V_149 != V_92 &&
( V_85 -> V_149 != V_148 ||
V_85 -> V_150 != V_92 ) ) {
V_73 = V_179 ;
goto V_70;
}
if ( V_85 -> V_151 != V_161 &&
V_85 -> V_151 != V_171 ) {
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
if ( V_85 -> V_151 == V_161 )
V_85 -> V_151 = V_160 ;
else
V_85 -> V_151 = V_170 ;
V_85 -> V_157 = true ;
if ( V_85 -> V_151 == V_170 ) {
V_73 =
F_79 ( true , V_84 , V_92 , V_85 -> V_149 ) ;
if ( V_73 < V_41 ) {
F_38 ( L_15 ,
V_85 -> V_149 , V_85 -> V_87 . V_84 . V_117 ,
V_85 -> V_87 . V_84 . V_115 ) ;
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
int F_91 ( struct V_83 V_84 , struct V_139 * V_117 )
{
struct V_89 * V_85 ;
const T_2 V_92 = F_74 ( V_117 ) ;
T_2 V_107 ;
bool V_143 = false ;
int V_73 ;
if ( F_46 ( V_84 ) || ! V_117 ||
V_92 == V_112 ) {
return V_40 ;
}
F_30 ( & V_90 . V_22 ) ;
if ( ! F_87 ( V_117 , V_84 ) ) {
F_71 ( L_18 ,
V_92 , V_84 . V_117 , V_84 . V_115 ) ;
V_73 = V_128 ;
goto V_70;
}
V_85 = F_51 ( V_84 ) ;
if ( ! V_85 ) {
F_71 ( L_19 ,
V_92 , V_84 . V_117 , V_84 . V_115 ) ;
V_73 = V_128 ;
goto V_70;
}
if ( V_92 != V_85 -> V_149 && V_92 != V_85 -> V_150 ) {
V_73 = V_180 ;
goto V_70;
}
if ( V_92 == V_85 -> V_149 ) {
V_107 = V_85 -> V_150 ;
V_85 -> V_149 = V_112 ;
} else {
V_107 = V_85 -> V_149 ;
V_85 -> V_150 = V_112 ;
}
V_85 -> V_87 . V_113 -- ;
V_143 = V_85 -> V_87 . V_14 & V_129 ;
if ( V_92 != V_148 ) {
bool V_181 ;
F_29 ( V_85 -> V_50 ) ;
V_181 = V_85 -> V_50 -> V_19 ||
V_85 -> V_51 -> V_19 ;
if ( F_100 ( V_85 ) ) {
V_73 =
F_43 ( V_182 ,
V_85 -> V_50 ,
V_85 -> V_51 ) ;
if ( V_73 < V_41 )
F_38 ( L_20 ,
V_84 . V_117 , V_84 . V_115 ,
V_73 ) ;
if ( V_85 -> V_157 )
F_40 ( V_85 -> V_50 ,
V_85 ->
V_51 ) ;
else
F_40 ( V_85 -> V_50 ,
V_85 ->
V_51 ) ;
}
if ( ! V_181 )
F_99 ( V_85 ) ;
F_31 ( V_85 -> V_50 ) ;
if ( ! V_181 && V_85 -> V_140 )
V_85 -> V_140 ( V_85 -> V_141 ) ;
} else {
if ( V_85 -> V_140 ) {
V_85 -> V_140 = NULL ;
V_85 -> V_141 = NULL ;
}
}
if ( V_85 -> V_87 . V_113 == 0 ) {
F_67 ( & V_90 , & V_85 -> V_87 ) ;
if ( V_143 )
F_16 ( V_85 -> V_159 ) ;
F_28 ( V_85 -> V_50 , V_85 -> V_51 ) ;
F_25 ( V_85 -> V_50 , V_85 -> V_87 . V_109 ) ;
F_25 ( V_85 -> V_51 , V_85 -> V_87 . V_110 ) ;
F_61 ( & V_85 -> V_115 ) ;
F_16 ( V_85 ) ;
F_101 ( V_117 , V_84 ) ;
} else {
F_79 ( false , V_84 , V_92 , V_107 ) ;
if ( V_92 == V_148 &&
F_100 ( V_85 ) ) {
V_85 -> V_151 = V_183 ;
} else {
V_85 -> V_151 = V_184 ;
}
if ( ! V_143 )
F_101 ( V_117 , V_84 ) ;
}
V_73 = V_41 ;
V_70:
F_32 ( & V_90 . V_22 ) ;
return V_73 ;
}
int F_102 ( struct V_83 V_84 ,
struct V_139 * V_117 ,
T_1 V_185 )
{
struct V_89 * V_85 ;
const T_2 V_92 = F_74 ( V_117 ) ;
bool V_143 = false ;
int V_73 ;
if ( F_46 ( V_84 ) || ! V_117 ||
V_92 == V_112 )
return V_40 ;
F_30 ( & V_90 . V_22 ) ;
if ( ! F_87 ( V_117 , V_84 ) ) {
F_71 ( L_18 ,
V_92 , V_84 . V_117 , V_84 . V_115 ) ;
V_73 = V_128 ;
goto V_70;
}
V_85 = F_51 ( V_84 ) ;
if ( ! V_85 ) {
F_71 ( L_21 ,
V_92 , V_84 . V_117 , V_84 . V_115 ) ;
V_73 = V_128 ;
goto V_70;
}
if ( V_92 != V_85 -> V_149 && V_92 != V_85 -> V_150 ) {
V_73 = V_180 ;
goto V_70;
}
V_143 = V_85 -> V_87 . V_14 & V_129 ;
V_73 = V_41 ;
if ( V_92 != V_148 ) {
struct V_71 V_72 ;
V_72 . V_64 = V_185 ;
V_72 . V_186 = F_77 ( V_85 -> V_87 ) ;
F_29 ( V_85 -> V_50 ) ;
F_99 ( V_85 ) ;
V_73 =
F_39 ( & V_72 ,
V_85 -> V_50 ,
V_85 -> V_51 ) ;
F_31 ( V_85 -> V_50 ) ;
if ( V_73 == V_41 ) {
V_85 -> V_151 ++ ;
if ( V_85 -> V_140 )
V_85 -> V_140 ( V_85 -> V_141 ) ;
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
memcpy ( & V_85 -> V_187 , V_85 -> V_50 -> V_19 ,
sizeof( V_85 -> V_187 ) ) ;
V_85 -> V_50 -> V_20 = & V_85 -> V_187 ;
memcpy ( & V_85 -> V_188 , V_85 -> V_51 -> V_19 ,
sizeof( V_85 -> V_188 ) ) ;
V_85 -> V_51 -> V_20 = & V_85 -> V_188 ;
return V_41 ;
}
int F_104 ( struct V_83 V_84 ,
struct V_139 * V_117 ,
T_2 V_80 )
{
struct V_89 * V_85 ;
const T_2 V_92 = F_74 ( V_117 ) ;
bool V_143 = false ;
int V_73 ;
if ( F_46 ( V_84 ) || ! V_117 ||
V_92 == V_112 )
return V_40 ;
F_30 ( & V_90 . V_22 ) ;
if ( ! F_87 ( V_117 , V_84 ) ) {
F_71 ( L_18 ,
V_92 , V_84 . V_117 , V_84 . V_115 ) ;
V_73 = V_128 ;
goto V_70;
}
V_85 = F_51 ( V_84 ) ;
if ( ! V_85 ) {
F_71 ( L_21 ,
V_92 , V_84 . V_117 , V_84 . V_115 ) ;
V_73 = V_128 ;
goto V_70;
}
if ( V_92 != V_85 -> V_149 && V_92 != V_85 -> V_150 ) {
V_73 = V_180 ;
goto V_70;
}
V_143 = V_85 -> V_87 . V_14 & V_129 ;
if ( V_92 != V_148 ) {
F_29 ( V_85 -> V_50 ) ;
V_73 = F_103 ( V_85 ) ;
if ( V_73 < V_41 )
F_38 ( L_22 ,
V_84 . V_117 , V_84 . V_115 , V_73 ) ;
F_43 ( V_80 , V_85 -> V_50 , V_85 -> V_51 ) ;
F_40 ( V_85 -> V_50 ,
V_85 -> V_51 ) ;
V_85 -> V_151 -- ;
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
struct V_86 * V_189 ;
F_30 ( & V_88 . V_22 ) ;
while ( ( V_85 = F_93 ( & V_88 ) ) ) {
V_189 = (struct V_86 * ) V_85 ;
if ( ! ( V_85 -> V_14 & V_129 ) )
F_64 ( V_85 -> V_84 ) ;
V_85 -> V_113 = 0 ;
F_67 ( & V_88 , V_85 ) ;
F_60 ( V_189 ) ;
}
F_32 ( & V_88 . V_22 ) ;
}
static void F_106 ( const struct V_190 * V_191 )
{
F_29 ( V_191 -> V_50 ) ;
}
static void F_107 ( const struct V_190 * V_191 )
{
F_31 ( V_191 -> V_50 ) ;
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
V_192 :
V_180 ;
}
return V_41 ;
}
static int F_109 ( const struct V_190 * V_191 ,
struct V_79 * * V_193 ,
struct V_79 * * V_194 )
{
int V_73 ;
V_73 = F_108 ( V_191 -> V_50 , V_191 -> V_51 ) ;
if ( V_73 == V_41 ) {
* V_193 = V_191 -> V_50 -> V_19 ;
* V_194 = V_191 -> V_51 -> V_19 ;
} else if ( V_191 -> V_50 -> V_20 &&
V_191 -> V_51 -> V_20 ) {
* V_193 = V_191 -> V_50 -> V_20 ;
* V_194 = V_191 -> V_51 -> V_20 ;
V_73 = V_41 ;
}
return V_73 ;
}
static int F_110 ( void * V_141 )
{
struct V_190 * V_191 = (struct V_190 * ) V_141 ;
F_106 ( V_191 ) ;
while ( V_191 -> V_195 > 0 ) {
V_191 -> V_195 -- ;
V_191 -> V_196 ++ ;
F_111 ( & V_191 -> V_103 ) ;
}
F_107 ( V_191 ) ;
return V_41 ;
}
static bool F_112 ( struct V_190 * V_191 )
{
unsigned int V_196 ;
V_191 -> V_195 ++ ;
V_196 = V_191 -> V_196 ;
F_107 ( V_191 ) ;
F_113 ( V_191 -> V_103 , V_196 != V_191 -> V_196 ) ;
F_106 ( V_191 ) ;
return true ;
}
static T_5 F_114 ( struct V_3 * V_50 ,
struct V_3 * V_51 ,
const T_1 V_197 ,
const void * V_198 ,
T_3 V_199 ,
T_6 V_200 )
{
T_7 V_201 ;
T_1 V_202 ;
T_3 V_203 ;
T_5 V_73 ;
V_73 = F_108 ( V_50 , V_51 ) ;
if ( F_115 ( V_73 != V_41 ) )
return V_73 ;
V_201 = F_116 ( V_50 -> V_19 ,
V_51 -> V_19 ,
V_197 ) ;
if ( V_201 == 0 )
return V_204 ;
if ( V_201 < V_41 )
return ( T_5 ) V_201 ;
V_203 = ( T_3 ) ( V_201 > V_199 ? V_199 : V_201 ) ;
V_202 = F_117 ( V_50 -> V_19 ) ;
if ( F_118 ( V_202 + V_203 < V_197 ) ) {
V_73 = V_200 ( V_50 , V_202 , V_198 , 0 , V_203 ) ;
} else {
const T_3 V_158 = ( T_3 ) ( V_197 - V_202 ) ;
V_73 = V_200 ( V_50 , V_202 , V_198 , 0 , V_158 ) ;
if ( V_73 >= V_41 )
V_73 = V_200 ( V_50 , 0 , V_198 , V_158 ,
V_203 - V_158 ) ;
}
if ( V_73 < V_41 )
return V_73 ;
F_119 ( V_50 -> V_19 , V_203 ,
V_197 ) ;
return V_203 ;
}
static T_5 F_120 ( struct V_3 * V_50 ,
struct V_3 * V_51 ,
const T_1 V_205 ,
void * V_198 ,
T_3 V_199 ,
T_8 V_206 ,
bool V_207 )
{
T_7 V_208 ;
T_1 V_127 ;
T_3 V_209 ;
T_5 V_73 ;
V_73 = F_108 ( V_50 , V_51 ) ;
if ( F_115 ( V_73 != V_41 ) )
return V_73 ;
V_208 = F_121 ( V_51 -> V_19 ,
V_50 -> V_19 ,
V_205 ) ;
if ( V_208 == 0 )
return V_210 ;
if ( V_208 < V_41 )
return ( T_5 ) V_208 ;
V_209 = ( T_3 ) ( V_208 > V_199 ? V_199 : V_208 ) ;
V_127 = F_122 ( V_50 -> V_19 ) ;
if ( F_118 ( V_127 + V_209 < V_205 ) ) {
V_73 = V_206 ( V_198 , 0 , V_51 , V_127 , V_209 ) ;
} else {
const T_3 V_158 = ( T_3 ) ( V_205 - V_127 ) ;
V_73 = V_206 ( V_198 , 0 , V_51 , V_127 , V_158 ) ;
if ( V_73 >= V_41 )
V_73 = V_206 ( V_198 , V_158 , V_51 , 0 ,
V_209 - V_158 ) ;
}
if ( V_73 < V_41 )
return V_73 ;
if ( V_207 )
F_123 ( V_50 -> V_19 ,
V_209 , V_205 ) ;
return V_209 ;
}
int F_124 ( struct V_190 * * V_191 ,
struct V_83 * V_84 ,
T_1 V_211 ,
T_1 V_212 ,
T_2 V_108 ,
T_2 V_14 ,
T_2 V_130 )
{
struct V_190 * V_213 ;
int V_68 ;
struct V_83 V_28 = V_176 ;
struct V_83 V_97 = F_54 ( V_108 , V_112 ) ;
enum V_214 V_215 ;
T_4 V_140 ;
void * V_141 ;
if ( V_211 + V_212 < V_216 ( V_211, V_212 ) ||
V_211 + V_212 > V_217 )
return V_218 ;
V_68 = V_214 ( & V_28 , & V_97 , false , & V_215 ) ;
if ( V_68 < V_41 )
V_215 = F_125 () ?
V_219 : V_220 ;
if ( V_14 & ( V_221 | V_222 ) ) {
F_71 ( L_23 ) ;
return V_40 ;
}
V_213 = F_24 ( sizeof( * V_213 ) , V_26 ) ;
if ( ! V_213 )
return V_54 ;
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
F_126 ( & V_213 -> V_103 ) ;
V_140 = F_110 ;
V_141 = ( void * ) V_213 ;
}
} else {
V_213 -> V_177 = true ;
}
V_68 = F_89 ( V_84 ,
& V_213 -> V_50 ,
V_213 -> V_197 ,
& V_213 -> V_51 ,
V_213 -> V_205 ,
V_213 -> V_108 ,
V_213 -> V_14 ,
V_213 -> V_130 ,
V_213 -> V_177 ,
V_140 , V_141 ) ;
if ( V_68 < V_41 ) {
F_16 ( V_213 ) ;
return V_68 ;
}
* V_191 = V_213 ;
V_213 -> V_84 = * V_84 ;
return V_68 ;
}
int F_127 ( struct V_190 * * V_191 )
{
int V_73 ;
struct V_190 * V_223 ;
if ( ! V_191 || ! ( * V_191 ) )
return V_40 ;
V_223 = * V_191 ;
V_73 = F_92 ( V_223 -> V_84 , V_223 -> V_177 ) ;
memset ( V_223 , 0 , sizeof( * V_223 ) ) ;
V_223 -> V_84 = V_176 ;
V_223 -> V_108 = V_112 ;
F_16 ( V_223 ) ;
* V_191 = NULL ;
return V_73 ;
}
int F_128 ( const struct V_190 * V_191 ,
T_1 * V_224 ,
T_1 * V_225 )
{
struct V_79 * V_193 ;
struct V_79 * V_194 ;
int V_73 ;
if ( ! V_191 )
return V_40 ;
F_106 ( V_191 ) ;
V_73 =
F_109 ( V_191 , & V_193 , & V_194 ) ;
if ( V_73 == V_41 )
F_129 ( V_193 , V_194 ,
V_224 , V_225 ) ;
F_107 ( V_191 ) ;
if ( V_73 == V_41 &&
( ( V_224 && * V_224 >= V_191 -> V_197 ) ||
( V_225 && * V_225 >= V_191 -> V_197 ) ) )
return V_226 ;
return V_73 ;
}
int F_130 ( const struct V_190 * V_191 ,
T_1 * V_227 ,
T_1 * V_228 )
{
struct V_79 * V_193 ;
struct V_79 * V_194 ;
int V_73 ;
if ( ! V_191 )
return V_40 ;
F_106 ( V_191 ) ;
V_73 =
F_109 ( V_191 , & V_193 , & V_194 ) ;
if ( V_73 == V_41 )
F_129 ( V_194 , V_193 ,
V_227 , V_228 ) ;
F_107 ( V_191 ) ;
if ( V_73 == V_41 &&
( ( V_227 && * V_227 >= V_191 -> V_205 ) ||
( V_228 && * V_228 >= V_191 -> V_205 ) ) )
return V_226 ;
return V_73 ;
}
T_7 F_131 ( const struct V_190 * V_191 )
{
struct V_79 * V_193 ;
struct V_79 * V_194 ;
T_7 V_73 ;
if ( ! V_191 )
return V_40 ;
F_106 ( V_191 ) ;
V_73 =
F_109 ( V_191 , & V_193 , & V_194 ) ;
if ( V_73 == V_41 )
V_73 = F_116 ( V_193 ,
V_194 ,
V_191 -> V_197 ) ;
else
V_73 = 0 ;
F_107 ( V_191 ) ;
return V_73 ;
}
T_7 F_132 ( const struct V_190 * V_191 )
{
struct V_79 * V_193 ;
struct V_79 * V_194 ;
T_7 V_73 ;
if ( ! V_191 )
return V_40 ;
F_106 ( V_191 ) ;
V_73 =
F_109 ( V_191 , & V_193 , & V_194 ) ;
if ( V_73 == V_41 )
V_73 = F_116 ( V_194 ,
V_193 ,
V_191 -> V_205 ) ;
else
V_73 = 0 ;
F_107 ( V_191 ) ;
return V_73 ;
}
T_7 F_133 ( const struct V_190 * V_191 )
{
struct V_79 * V_193 ;
struct V_79 * V_194 ;
T_7 V_73 ;
if ( ! V_191 )
return V_40 ;
F_106 ( V_191 ) ;
V_73 =
F_109 ( V_191 , & V_193 , & V_194 ) ;
if ( V_73 == V_41 )
V_73 = F_121 ( V_193 ,
V_194 ,
V_191 -> V_197 ) ;
else
V_73 = 0 ;
F_107 ( V_191 ) ;
return V_73 ;
}
T_7 F_134 ( const struct V_190 * V_191 )
{
struct V_79 * V_193 ;
struct V_79 * V_194 ;
T_7 V_73 ;
if ( ! V_191 )
return V_40 ;
F_106 ( V_191 ) ;
V_73 =
F_109 ( V_191 , & V_193 , & V_194 ) ;
if ( V_73 == V_41 )
V_73 = F_121 ( V_194 ,
V_193 ,
V_191 -> V_205 ) ;
else
V_73 = 0 ;
F_107 ( V_191 ) ;
return V_73 ;
}
T_5 F_135 ( struct V_190 * V_191 ,
const void * V_198 ,
T_3 V_199 ,
int V_229 )
{
T_5 V_73 ;
if ( ! V_191 || ! V_198 )
return V_40 ;
F_106 ( V_191 ) ;
do {
V_73 = F_114 ( V_191 -> V_50 ,
V_191 -> V_51 ,
V_191 -> V_197 ,
V_198 , V_199 ,
F_19 ) ;
if ( V_73 == V_192 &&
! F_112 ( V_191 ) )
V_73 = V_230 ;
} while ( V_73 == V_192 );
F_107 ( V_191 ) ;
return V_73 ;
}
T_5 F_136 ( struct V_190 * V_191 ,
void * V_198 ,
T_3 V_199 ,
int V_229 )
{
T_5 V_73 ;
if ( ! V_191 || ! V_198 )
return V_40 ;
F_106 ( V_191 ) ;
do {
V_73 = F_120 ( V_191 -> V_50 ,
V_191 -> V_51 ,
V_191 -> V_205 ,
V_198 , V_199 ,
F_20 , true ) ;
if ( V_73 == V_192 &&
! F_112 ( V_191 ) )
V_73 = V_230 ;
} while ( V_73 == V_192 );
F_107 ( V_191 ) ;
return V_73 ;
}
T_5 F_137 ( struct V_190 * V_191 ,
void * V_198 ,
T_3 V_199 ,
int V_229 )
{
T_5 V_73 ;
if ( ! V_191 || ! V_198 )
return V_40 ;
F_106 ( V_191 ) ;
do {
V_73 = F_120 ( V_191 -> V_50 ,
V_191 -> V_51 ,
V_191 -> V_205 ,
V_198 , V_199 ,
F_20 , false ) ;
if ( V_73 == V_192 &&
! F_112 ( V_191 ) )
V_73 = V_230 ;
} while ( V_73 == V_192 );
F_107 ( V_191 ) ;
return V_73 ;
}
T_5 F_138 ( struct V_190 * V_191 ,
void * V_38 ,
T_3 V_231 ,
int V_229 )
{
T_5 V_73 ;
if ( ! V_191 || ! V_38 )
return V_40 ;
F_106 ( V_191 ) ;
do {
V_73 = F_114 ( V_191 -> V_50 ,
V_191 -> V_51 ,
V_191 -> V_197 ,
V_38 , V_231 ,
F_21 ) ;
if ( V_73 == V_192 &&
! F_112 ( V_191 ) )
V_73 = V_230 ;
} while ( V_73 == V_192 );
F_107 ( V_191 ) ;
return V_73 ;
}
T_5 F_139 ( struct V_190 * V_191 ,
void * V_38 ,
T_3 V_231 ,
int V_229 )
{
T_5 V_73 ;
if ( ! V_191 || ! V_38 )
return V_40 ;
F_106 ( V_191 ) ;
do {
V_73 = F_120 ( V_191 -> V_50 ,
V_191 -> V_51 ,
V_191 -> V_205 ,
V_38 , V_231 ,
F_22 ,
true ) ;
if ( V_73 == V_192 &&
! F_112 ( V_191 ) )
V_73 = V_230 ;
} while ( V_73 == V_192 );
F_107 ( V_191 ) ;
return V_73 ;
}
T_5 F_140 ( struct V_190 * V_191 ,
void * V_38 ,
T_3 V_231 ,
int V_229 )
{
T_5 V_73 ;
if ( ! V_191 || ! V_38 )
return V_40 ;
F_106 ( V_191 ) ;
do {
V_73 = F_120 ( V_191 -> V_50 ,
V_191 -> V_51 ,
V_191 -> V_205 ,
V_38 , V_231 ,
F_22 ,
false ) ;
if ( V_73 == V_192 &&
! F_112 ( V_191 ) )
V_73 = V_230 ;
} while ( V_73 == V_192 );
F_107 ( V_191 ) ;
return V_73 ;
}
