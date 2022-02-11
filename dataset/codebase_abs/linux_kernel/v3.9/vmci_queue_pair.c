static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 ) {
T_1 V_5 = F_2 ( V_2 , V_6 ) ;
if ( V_4 -> V_7 -> V_8 ) {
F_3 ( V_4 -> V_7 -> V_9 ) ;
V_4 -> V_7 -> V_9 = NULL ;
}
while ( V_5 )
F_4 ( V_4 -> V_7 -> V_10 [ -- V_5 ] ) ;
F_5 ( V_4 -> V_11 ) ;
}
}
static void * F_6 ( T_1 V_2 , T_2 V_12 )
{
T_1 V_5 ;
struct V_3 * V_4 ;
struct V_13 * V_11 ;
const T_1 V_14 = F_2 ( V_2 , V_6 ) ;
const T_3 V_15 =
V_6 +
sizeof( * V_4 ) + sizeof( * ( V_4 -> V_7 ) ) +
V_14 * sizeof( * ( V_4 -> V_7 -> V_10 ) ) ;
V_11 = F_7 ( V_15 ) ;
if ( ! V_11 )
return NULL ;
V_4 = ( void * ) V_11 + V_6 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_16 = NULL ;
V_4 -> V_7 = (struct V_17 * ) ( V_4 + 1 ) ;
V_4 -> V_7 -> V_18 = NULL ;
V_4 -> V_7 -> V_10 = (struct V_10 * * ) ( V_4 -> V_7 + 1 ) ;
V_4 -> V_7 -> V_19 = false ;
V_4 -> V_7 -> V_9 = NULL ;
V_4 -> V_7 -> V_8 = false ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_4 -> V_7 -> V_10 [ V_5 ] = F_8 ( V_20 , 0 ) ;
if ( ! V_4 -> V_7 -> V_10 [ V_5 ] )
goto V_21;
}
if ( F_9 ( V_12 ) ) {
V_4 -> V_7 -> V_9 =
F_10 ( V_4 -> V_7 -> V_10 , V_14 , V_22 ,
V_23 ) ;
if ( ! V_4 -> V_7 -> V_9 )
goto V_21;
V_4 -> V_7 -> V_8 = true ;
}
return ( void * ) V_4 ;
V_21:
F_1 ( V_4 , V_5 * V_6 ) ;
return NULL ;
}
static int F_11 ( struct V_3 * V_4 ,
T_1 V_24 ,
const void * V_25 ,
T_4 V_2 ,
bool V_26 )
{
struct V_17 * V_7 = V_4 -> V_7 ;
T_4 V_27 = 0 ;
while ( V_27 < V_2 ) {
T_1 V_28 = ( V_24 + V_27 ) / V_6 ;
T_4 V_29 =
( V_24 + V_27 ) & ( V_6 - 1 ) ;
void * V_9 ;
T_4 V_30 ;
if ( ! V_7 -> V_8 )
V_9 = F_12 ( V_7 -> V_10 [ V_28 ] ) ;
else
V_9 = ( void * ) ( ( V_31 * ) V_7 -> V_9 +
( V_28 * V_6 ) ) ;
if ( V_2 - V_27 > V_6 - V_29 )
V_30 = V_6 - V_29 ;
else
V_30 = V_2 - V_27 ;
if ( V_26 ) {
struct V_32 * V_33 = (struct V_32 * ) V_25 ;
int V_34 ;
V_34 = F_13 ( ( V_31 * ) V_9 + V_29 ,
V_33 , V_30 ) ;
if ( V_34 != 0 ) {
F_14 ( V_7 -> V_10 [ V_28 ] ) ;
return V_35 ;
}
} else {
memcpy ( ( V_31 * ) V_9 + V_29 ,
( V_31 * ) V_25 + V_27 , V_30 ) ;
}
V_27 += V_30 ;
if ( ! V_7 -> V_8 )
F_14 ( V_7 -> V_10 [ V_28 ] ) ;
}
return V_36 ;
}
static int F_15 ( void * V_37 ,
const struct V_3 * V_4 ,
T_1 V_24 ,
T_4 V_2 ,
bool V_26 )
{
struct V_17 * V_7 = V_4 -> V_7 ;
T_4 V_27 = 0 ;
while ( V_27 < V_2 ) {
T_1 V_28 = ( V_24 + V_27 ) / V_6 ;
T_4 V_29 =
( V_24 + V_27 ) & ( V_6 - 1 ) ;
void * V_9 ;
T_4 V_30 ;
if ( ! V_7 -> V_8 )
V_9 = F_12 ( V_7 -> V_10 [ V_28 ] ) ;
else
V_9 = ( void * ) ( ( V_31 * ) V_7 -> V_9 +
( V_28 * V_6 ) ) ;
if ( V_2 - V_27 > V_6 - V_29 )
V_30 = V_6 - V_29 ;
else
V_30 = V_2 - V_27 ;
if ( V_26 ) {
struct V_32 * V_33 = (struct V_32 * ) V_37 ;
int V_34 ;
V_34 = F_16 ( V_33 , ( V_31 * ) V_9 + V_29 ,
V_30 ) ;
if ( V_34 != 0 ) {
F_14 ( V_7 -> V_10 [ V_28 ] ) ;
return V_35 ;
}
} else {
memcpy ( ( V_31 * ) V_37 + V_27 ,
( V_31 * ) V_9 + V_29 , V_30 ) ;
}
V_27 += V_30 ;
if ( ! V_7 -> V_8 )
F_14 ( V_7 -> V_10 [ V_28 ] ) ;
}
return V_36 ;
}
static int F_17 ( void * V_38 ,
T_1 V_39 ,
void * V_40 ,
T_1 V_41 , struct V_42 * V_42 )
{
T_2 * V_43 ;
T_2 * V_44 ;
struct V_3 * V_45 = V_38 ;
struct V_3 * V_46 = V_40 ;
T_1 V_5 ;
if ( ! V_45 || ! V_39 || ! V_46 ||
! V_41 || ! V_42 )
return V_35 ;
if ( V_42 -> V_47 )
return V_48 ;
V_43 =
F_18 ( V_39 * sizeof( * V_43 ) , V_20 ) ;
if ( ! V_43 )
return V_49 ;
V_44 =
F_18 ( V_41 * sizeof( * V_44 ) , V_20 ) ;
if ( ! V_44 ) {
F_19 ( V_43 ) ;
return V_49 ;
}
V_43 [ 0 ] = F_20 ( F_21 ( V_45 -> V_11 ) ) ;
for ( V_5 = 1 ; V_5 < V_39 ; V_5 ++ ) {
unsigned long V_50 ;
V_43 [ V_5 ] =
F_20 ( V_45 -> V_7 -> V_10 [ V_5 - 1 ] ) ;
V_50 = V_43 [ V_5 ] ;
if ( sizeof( V_50 ) > sizeof( * V_43 )
&& V_50 != V_43 [ V_5 ] )
goto V_51;
}
V_44 [ 0 ] = F_20 ( F_21 ( V_46 -> V_11 ) ) ;
for ( V_5 = 1 ; V_5 < V_41 ; V_5 ++ ) {
unsigned long V_50 ;
V_44 [ V_5 ] =
F_20 ( V_46 -> V_7 -> V_10 [ V_5 - 1 ] ) ;
V_50 = V_44 [ V_5 ] ;
if ( sizeof( V_50 ) > sizeof( * V_44 )
&& V_50 != V_44 [ V_5 ] )
goto V_51;
}
V_42 -> V_39 = V_39 ;
V_42 -> V_41 = V_41 ;
V_42 -> V_43 = V_43 ;
V_42 -> V_44 = V_44 ;
V_42 -> V_47 = true ;
return V_36 ;
V_51:
F_19 ( V_43 ) ;
F_19 ( V_44 ) ;
return V_35 ;
}
static void F_22 ( struct V_42 * V_42 )
{
if ( V_42 -> V_47 ) {
F_19 ( V_42 -> V_43 ) ;
F_19 ( V_42 -> V_44 ) ;
}
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
}
static int F_23 ( V_31 * V_52 , const struct V_42 * V_42 )
{
memcpy ( V_52 , V_42 -> V_43 ,
V_42 -> V_39 * sizeof( * V_42 -> V_43 ) ) ;
memcpy ( V_52 +
V_42 -> V_39 * sizeof( * V_42 -> V_43 ) ,
V_42 -> V_44 ,
V_42 -> V_41 * sizeof( * V_42 -> V_44 ) ) ;
return V_36 ;
}
static int F_24 ( struct V_3 * V_4 ,
T_1 V_24 ,
const void * V_25 , T_4 V_53 , T_4 V_2 )
{
return F_11 ( V_4 , V_24 ,
( V_31 * ) V_25 + V_53 , V_2 , false ) ;
}
static int F_25 ( void * V_37 ,
T_4 V_54 ,
const struct V_3 * V_4 ,
T_1 V_24 , T_4 V_2 )
{
return F_15 ( ( V_31 * ) V_37 + V_54 ,
V_4 , V_24 , V_2 , false ) ;
}
static int F_26 ( struct V_3 * V_4 ,
T_1 V_24 ,
const void * V_25 ,
T_4 V_53 , T_4 V_2 )
{
return F_11 ( V_4 , V_24 , V_25 , V_2 , true ) ;
}
static int F_27 ( void * V_37 ,
T_4 V_54 ,
const struct V_3 * V_4 ,
T_1 V_24 , T_4 V_2 )
{
return F_15 ( V_37 , V_4 , V_24 , V_2 , true ) ;
}
static struct V_3 * F_28 ( T_1 V_2 )
{
struct V_3 * V_4 ;
const T_4 V_55 = F_2 ( V_2 , V_6 ) + 1 ;
const T_4 V_15 = sizeof( * V_4 ) + sizeof( * ( V_4 -> V_7 ) ) ;
const T_4 V_56 =
V_55 * sizeof( * V_4 -> V_7 -> V_10 ) ;
V_4 = F_29 ( V_15 + V_56 , V_20 ) ;
if ( V_4 ) {
V_4 -> V_11 = NULL ;
V_4 -> V_16 = NULL ;
V_4 -> V_7 =
(struct V_17 * ) ( ( V_31 * ) V_4 +
sizeof( * V_4 ) ) ;
V_4 -> V_7 -> V_19 = true ;
V_4 -> V_7 -> V_57 = NULL ;
V_4 -> V_7 -> V_55 = V_55 ;
V_4 -> V_7 -> V_18 =
(struct V_10 * * ) ( ( V_31 * ) V_4 + V_15 ) ;
V_4 -> V_7 -> V_10 = & V_4 -> V_7 -> V_18 [ 1 ] ;
V_4 -> V_7 -> V_9 = NULL ;
V_4 -> V_7 -> V_8 = false ;
}
return V_4 ;
}
static void F_30 ( struct V_3 * V_4 , T_1 V_15 )
{
F_19 ( V_4 ) ;
}
static void F_31 ( struct V_3 * V_45 ,
struct V_3 * V_46 )
{
if ( V_45 -> V_7 -> V_19 ) {
V_45 -> V_7 -> V_57 = & V_45 -> V_7 -> V_58 ;
V_46 -> V_7 -> V_57 = & V_45 -> V_7 -> V_58 ;
F_32 ( V_45 -> V_7 -> V_57 ) ;
}
}
static void F_33 ( struct V_3 * V_45 ,
struct V_3 * V_46 )
{
if ( V_45 -> V_7 -> V_19 ) {
V_45 -> V_7 -> V_57 = NULL ;
V_46 -> V_7 -> V_57 = NULL ;
}
}
static void F_34 ( struct V_3 * V_4 )
{
if ( V_4 -> V_7 -> V_19 )
F_35 ( V_4 -> V_7 -> V_57 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
if ( V_4 -> V_7 -> V_19 )
F_37 ( V_4 -> V_7 -> V_57 ) ;
}
static void F_38 ( struct V_10 * * V_59 ,
T_1 V_55 , bool V_60 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_55 ; V_5 ++ ) {
if ( V_60 )
F_39 ( V_59 [ V_5 ] ) ;
F_40 ( V_59 [ V_5 ] ) ;
V_59 [ V_5 ] = NULL ;
}
}
static int F_41 ( T_1 V_61 ,
T_1 V_62 ,
struct V_3 * V_45 ,
struct V_3 * V_46 )
{
int V_63 ;
int V_34 = V_36 ;
F_42 ( & V_64 -> V_65 -> V_66 ) ;
V_63 = F_43 ( V_64 ,
V_64 -> V_65 ,
( V_67 ) V_61 ,
V_45 -> V_7 -> V_55 ,
1 , 0 , V_45 -> V_7 -> V_18 , NULL ) ;
if ( V_63 < V_45 -> V_7 -> V_55 ) {
F_44 ( L_1 , V_63 ) ;
F_38 ( V_45 -> V_7 -> V_18 , V_63 ,
false ) ;
V_34 = V_49 ;
goto V_68;
}
V_63 = F_43 ( V_64 ,
V_64 -> V_65 ,
( V_67 ) V_62 ,
V_46 -> V_7 -> V_55 ,
1 , 0 , V_46 -> V_7 -> V_18 , NULL ) ;
if ( V_63 < V_46 -> V_7 -> V_55 ) {
F_44 ( L_2 , V_63 ) ;
F_38 ( V_46 -> V_7 -> V_18 , V_63 ,
false ) ;
F_38 ( V_45 -> V_7 -> V_18 ,
V_45 -> V_7 -> V_55 , false ) ;
V_34 = V_49 ;
}
V_68:
F_45 ( & V_64 -> V_65 -> V_66 ) ;
return V_34 ;
}
static int F_46 ( struct V_69 * V_70 ,
struct V_3 * V_45 ,
struct V_3 * V_46 )
{
T_1 V_61 ;
T_1 V_62 ;
V_61 = V_70 -> V_59 ;
V_62 = V_70 -> V_59 +
V_45 -> V_7 -> V_55 * V_6 ;
return F_41 ( V_61 , V_62 , V_45 ,
V_46 ) ;
}
static void F_47 ( struct V_3 * V_45 ,
struct V_3 * V_46 )
{
F_38 ( V_45 -> V_7 -> V_18 ,
V_45 -> V_7 -> V_55 , true ) ;
memset ( V_45 -> V_7 -> V_18 , 0 ,
sizeof( * V_45 -> V_7 -> V_18 ) *
V_45 -> V_7 -> V_55 ) ;
F_38 ( V_46 -> V_7 -> V_18 ,
V_46 -> V_7 -> V_55 , true ) ;
memset ( V_46 -> V_7 -> V_18 , 0 ,
sizeof( * V_46 -> V_7 -> V_18 ) *
V_46 -> V_7 -> V_55 ) ;
}
static int F_48 ( struct V_3 * V_45 ,
struct V_3 * V_46 )
{
int V_71 ;
if ( ! V_45 -> V_11 || ! V_46 -> V_11 ) {
struct V_10 * V_72 [ 2 ] ;
if ( V_45 -> V_11 != V_46 -> V_11 )
return V_73 ;
if ( V_45 -> V_7 -> V_18 == NULL ||
* V_45 -> V_7 -> V_18 == NULL )
return V_74 ;
V_72 [ 0 ] = * V_45 -> V_7 -> V_18 ;
V_72 [ 1 ] = * V_46 -> V_7 -> V_18 ;
V_45 -> V_11 = F_10 ( V_72 , 2 , V_22 , V_23 ) ;
if ( V_45 -> V_11 != NULL ) {
V_46 -> V_11 =
(struct V_13 * ) ( ( V_31 * )
V_45 -> V_11 +
V_6 ) ;
V_71 = V_36 ;
} else {
F_44 ( L_3 ) ;
V_71 = V_49 ;
}
} else {
V_71 = V_36 ;
}
return V_71 ;
}
static int F_49 ( T_2 V_75 ,
struct V_3 * V_45 ,
struct V_3 * V_46 )
{
if ( V_45 -> V_11 ) {
if ( V_45 -> V_11 < V_46 -> V_11 )
F_3 ( V_45 -> V_11 ) ;
else
F_3 ( V_46 -> V_11 ) ;
V_45 -> V_11 = NULL ;
V_46 -> V_11 = NULL ;
}
return V_36 ;
}
static struct V_76 * F_50 ( struct V_77 * V_77 ,
struct V_78 V_79 )
{
struct V_76 * V_80 ;
if ( F_51 ( V_79 ) )
return NULL ;
F_52 (entry, &qp_list->head, list_item) {
if ( F_53 ( V_80 -> V_79 , V_79 ) )
return V_80 ;
}
return NULL ;
}
static struct V_81 *
F_54 ( struct V_78 V_79 )
{
struct V_81 * V_80 ;
struct V_76 * V_82 = F_50 ( & V_83 , V_79 ) ;
V_80 = V_82 ? F_55 (
V_82 , struct V_81 , V_82 ) : NULL ;
return V_80 ;
}
static struct V_84 *
F_56 ( struct V_78 V_79 )
{
struct V_84 * V_80 ;
struct V_76 * V_82 = F_50 ( & V_85 , V_79 ) ;
V_80 = V_82 ? F_55 (
V_82 , struct V_84 , V_82 ) : NULL ;
return V_80 ;
}
static int F_57 ( bool V_86 , struct V_78 V_79 )
{
T_2 V_87 = F_58 () ;
struct V_88 V_89 ;
V_89 . V_90 . V_91 . V_92 = F_59 ( V_87 , V_93 ) ;
V_89 . V_90 . V_91 . V_25 = F_59 ( V_94 ,
V_95 ) ;
V_89 . V_90 . V_91 . V_96 = sizeof( V_89 ) - sizeof( V_89 . V_90 . V_91 ) ;
V_89 . V_90 . V_97 . V_98 =
V_86 ? V_99 : V_100 ;
V_89 . V_101 . V_102 = V_87 ;
V_89 . V_101 . V_79 = V_79 ;
return F_60 ( & V_89 . V_90 . V_91 ) ;
}
static struct V_81 *
F_61 ( struct V_78 V_79 ,
T_2 V_103 ,
T_2 V_12 ,
T_1 V_104 ,
T_1 V_105 ,
void * V_45 ,
void * V_46 )
{
int V_71 ;
struct V_81 * V_80 ;
const T_1 V_106 = F_2 ( V_104 , V_6 ) +
F_2 ( V_105 , V_6 ) + 2 ;
if ( F_51 ( V_79 ) ) {
T_2 V_87 = F_58 () ;
V_79 = F_59 ( V_87 , V_107 ) ;
}
V_80 = F_29 ( sizeof( * V_80 ) , V_20 ) ;
if ( V_80 ) {
V_80 -> V_82 . V_103 = V_103 ;
V_80 -> V_82 . V_12 = V_12 ;
V_80 -> V_82 . V_104 = V_104 ;
V_80 -> V_82 . V_105 = V_105 ;
V_80 -> V_82 . V_108 = 0 ;
V_80 -> V_106 = V_106 ;
V_80 -> V_45 = V_45 ;
V_80 -> V_46 = V_46 ;
F_62 ( & V_80 -> V_82 . V_109 ) ;
V_71 = F_63 ( & V_80 -> V_110 ,
V_111 ,
V_79 ) ;
V_80 -> V_82 . V_79 = F_64 ( & V_80 -> V_110 ) ;
if ( ( V_71 != V_36 ) ||
F_50 ( & V_83 , V_80 -> V_82 . V_79 ) ) {
F_44 ( L_4 ,
V_79 . V_112 , V_79 . V_110 , V_71 ) ;
F_19 ( V_80 ) ;
V_80 = NULL ;
}
}
return V_80 ;
}
static void F_65 ( struct V_81 * V_80 )
{
F_22 ( & V_80 -> V_42 ) ;
F_33 ( V_80 -> V_45 , V_80 -> V_46 ) ;
F_1 ( V_80 -> V_45 , V_80 -> V_82 . V_104 ) ;
F_1 ( V_80 -> V_46 , V_80 -> V_82 . V_105 ) ;
F_66 ( & V_80 -> V_110 ) ;
F_19 ( V_80 ) ;
}
static int F_67 ( const struct V_81 * V_80 )
{
struct V_113 * V_114 ;
T_4 V_115 ;
int V_71 ;
if ( ! V_80 || V_80 -> V_106 <= 2 )
return V_35 ;
V_115 = sizeof( * V_114 ) +
( T_4 ) V_80 -> V_106 * sizeof( T_2 ) ;
V_114 = F_18 ( V_115 , V_20 ) ;
if ( ! V_114 )
return V_49 ;
V_114 -> V_91 . V_92 = F_59 ( V_94 ,
V_116 ) ;
V_114 -> V_91 . V_25 = V_117 ;
V_114 -> V_91 . V_96 = V_115 - V_118 ;
V_114 -> V_79 = V_80 -> V_82 . V_79 ;
V_114 -> V_103 = V_80 -> V_82 . V_103 ;
V_114 -> V_12 = V_80 -> V_82 . V_12 ;
V_114 -> V_104 = V_80 -> V_82 . V_104 ;
V_114 -> V_105 = V_80 -> V_82 . V_105 ;
V_114 -> V_106 = V_80 -> V_106 ;
V_71 = F_23 ( ( V_31 * ) V_114 + sizeof( * V_114 ) ,
& V_80 -> V_42 ) ;
if ( V_71 == V_36 )
V_71 = F_68 ( & V_114 -> V_91 ) ;
F_19 ( V_114 ) ;
return V_71 ;
}
static int F_69 ( struct V_78 V_79 )
{
struct V_119 V_120 ;
V_120 . V_91 . V_92 = F_59 ( V_94 ,
V_121 ) ;
V_120 . V_91 . V_25 = V_117 ;
V_120 . V_91 . V_96 = sizeof( V_79 ) ;
V_120 . V_79 = V_79 ;
return F_68 ( & V_120 . V_91 ) ;
}
static void F_70 ( struct V_77 * V_77 , struct V_76 * V_80 )
{
if ( V_80 )
F_71 ( & V_80 -> V_109 , & V_77 -> V_122 ) ;
}
static void F_72 ( struct V_77 * V_77 ,
struct V_76 * V_80 )
{
if ( V_80 )
F_73 ( & V_80 -> V_109 ) ;
}
static int F_74 ( struct V_78 V_79 )
{
int V_71 ;
struct V_81 * V_80 ;
T_2 V_108 = ~ 0 ;
F_35 ( & V_83 . V_57 ) ;
V_80 = F_54 ( V_79 ) ;
if ( ! V_80 ) {
F_37 ( & V_83 . V_57 ) ;
return V_123 ;
}
if ( V_80 -> V_82 . V_12 & V_124 ) {
V_71 = V_36 ;
if ( V_80 -> V_82 . V_108 > 1 ) {
V_71 = F_57 ( false , V_79 ) ;
}
} else {
V_71 = F_69 ( V_79 ) ;
if ( V_71 < V_36 ) {
F_37 ( & V_83 . V_57 ) ;
return V_71 ;
}
}
V_80 -> V_82 . V_108 -- ;
if ( V_80 -> V_82 . V_108 == 0 )
F_72 ( & V_83 , & V_80 -> V_82 ) ;
if ( V_80 )
V_108 = V_80 -> V_82 . V_108 ;
F_37 ( & V_83 . V_57 ) ;
if ( V_108 == 0 )
F_65 ( V_80 ) ;
return V_71 ;
}
static int F_75 ( struct V_78 * V_79 ,
struct V_3 * * V_45 ,
T_1 V_104 ,
struct V_3 * * V_46 ,
T_1 V_105 ,
T_2 V_103 ,
T_2 V_12 ,
T_2 V_125 )
{
const T_1 V_39 =
F_2 ( V_104 , V_6 ) + 1 ;
const T_1 V_41 =
F_2 ( V_105 , V_6 ) + 1 ;
void * V_126 = NULL ;
void * V_127 = NULL ;
int V_71 ;
struct V_81 * V_128 = NULL ;
if ( V_125 != V_129 )
return V_130 ;
F_35 ( & V_83 . V_57 ) ;
V_128 = F_54 ( * V_79 ) ;
if ( V_128 ) {
if ( V_128 -> V_82 . V_12 & V_124 ) {
if ( V_128 -> V_82 . V_108 > 1 ) {
F_76 ( L_5 ) ;
V_71 = V_74 ;
goto V_131;
}
if ( V_128 -> V_82 . V_104 != V_105 ||
V_128 -> V_82 . V_105 !=
V_104 ||
V_128 -> V_82 . V_12 !=
( V_12 & ~ V_132 ) ) {
F_76 ( L_6 ) ;
V_71 = V_73 ;
goto V_131;
}
V_71 = F_57 ( true , * V_79 ) ;
if ( V_71 < V_36 )
goto V_131;
V_126 = V_128 -> V_46 ;
V_127 = V_128 -> V_45 ;
goto V_68;
}
V_71 = V_48 ;
goto V_131;
}
V_126 = F_6 ( V_104 , V_12 ) ;
if ( ! V_126 ) {
F_44 ( L_7 ) ;
V_71 = V_49 ;
goto error;
}
V_127 = F_6 ( V_105 , V_12 ) ;
if ( ! V_127 ) {
F_44 ( L_8 ) ;
V_71 = V_49 ;
goto error;
}
V_128 = F_61 ( * V_79 , V_103 , V_12 ,
V_104 , V_105 ,
V_126 , V_127 ) ;
if ( ! V_128 ) {
F_44 ( L_9 , V_133 ) ;
V_71 = V_49 ;
goto error;
}
V_71 = F_17 ( V_126 , V_39 , V_127 ,
V_41 ,
& V_128 -> V_42 ) ;
if ( V_71 < V_36 ) {
F_44 ( L_10 ) ;
goto error;
}
if ( V_128 -> V_82 . V_12 & V_124 ) {
T_2 V_87 = F_58 () ;
if ( V_128 -> V_82 . V_79 . V_112 != V_87 ||
( V_128 -> V_82 . V_103 != V_107 &&
V_128 -> V_82 . V_103 != V_87 ) ) {
V_71 = V_130 ;
goto error;
}
if ( V_128 -> V_82 . V_12 & V_132 ) {
V_71 = V_123 ;
goto error;
}
} else {
V_71 = F_67 ( V_128 ) ;
if ( V_71 < V_36 ) {
F_44 ( L_11 , V_71 ) ;
goto error;
}
}
F_31 ( (struct V_3 * ) V_126 ,
(struct V_3 * ) V_127 ) ;
F_70 ( & V_83 , & V_128 -> V_82 ) ;
V_68:
V_128 -> V_82 . V_108 ++ ;
* V_79 = V_128 -> V_82 . V_79 ;
* V_45 = (struct V_3 * ) V_126 ;
* V_46 = (struct V_3 * ) V_127 ;
if ( ( V_128 -> V_82 . V_12 & V_124 ) &&
V_128 -> V_82 . V_108 == 1 ) {
F_77 ( ( * V_45 ) -> V_11 , * V_79 ) ;
F_77 ( ( * V_46 ) -> V_11 , * V_79 ) ;
}
F_37 ( & V_83 . V_57 ) ;
return V_36 ;
error:
F_37 ( & V_83 . V_57 ) ;
if ( V_128 ) {
F_65 ( V_128 ) ;
} else {
F_1 ( V_126 , V_104 ) ;
F_1 ( V_127 , V_105 ) ;
}
return V_71 ;
V_131:
F_37 ( & V_83 . V_57 ) ;
return V_71 ;
}
static int F_78 ( struct V_78 V_79 ,
T_2 V_103 ,
T_2 V_12 ,
T_2 V_125 ,
T_1 V_104 ,
T_1 V_105 ,
struct V_69 * V_70 ,
struct V_134 * V_112 ,
T_5 V_135 ,
void * V_136 , struct V_84 * * V_137 )
{
struct V_84 * V_80 = NULL ;
const T_2 V_87 = F_79 ( V_112 ) ;
bool V_138 = V_12 & V_124 ;
int V_71 ;
T_1 V_139 ;
T_1 V_140 ;
if ( V_12 & V_132 )
return V_123 ;
if ( V_79 . V_112 != V_87 && V_79 . V_112 != V_103 )
return V_130 ;
if ( F_80 ( V_87 ) && F_80 ( V_103 ) )
return V_141 ;
if ( V_138 && V_103 != V_107 && V_87 != V_103 )
return V_130 ;
V_80 = F_29 ( sizeof( * V_80 ) , V_142 ) ;
if ( ! V_80 )
return V_49 ;
if ( F_79 ( V_112 ) == V_143 && ! V_138 ) {
V_139 = V_105 ;
V_140 = V_104 ;
} else {
V_139 = V_104 ;
V_140 = V_105 ;
}
V_80 -> V_82 . V_79 = V_79 ;
V_80 -> V_82 . V_103 = V_103 ;
V_80 -> V_82 . V_12 = V_12 ;
V_80 -> V_82 . V_104 = V_139 ;
V_80 -> V_82 . V_105 = V_140 ;
V_80 -> V_82 . V_108 = 1 ;
V_80 -> V_144 = V_87 ;
V_80 -> V_145 = V_107 ;
V_80 -> V_146 = V_147 ;
V_80 -> V_148 =
! ! ( V_112 -> V_125 & V_149 ) ;
V_80 -> V_150 =
! ! ( V_125 & V_151 ) ;
V_80 -> V_152 = false ;
V_80 -> V_135 = V_135 ;
V_80 -> V_136 = V_136 ;
V_80 -> V_45 = F_28 ( V_139 ) ;
if ( V_80 -> V_45 == NULL ) {
V_71 = V_49 ;
goto error;
}
V_80 -> V_46 = F_28 ( V_140 ) ;
if ( V_80 -> V_46 == NULL ) {
V_71 = V_49 ;
goto error;
}
F_31 ( V_80 -> V_45 , V_80 -> V_46 ) ;
F_62 ( & V_80 -> V_82 . V_109 ) ;
if ( V_138 ) {
V_31 * V_153 ;
V_80 -> V_154 = F_81 ( F_82 ( V_80 -> V_82 ) ,
V_6 , V_20 ) ;
if ( V_80 -> V_154 == NULL ) {
V_71 = V_49 ;
goto error;
}
V_80 -> V_146 = V_155 ;
V_80 -> V_45 -> V_11 = V_80 -> V_154 ;
V_153 = ( V_31 * ) V_80 -> V_154 + V_6 *
( F_2 ( V_80 -> V_82 . V_104 , V_6 ) + 1 ) ;
V_80 -> V_46 -> V_11 = (struct V_13 * ) V_153 ;
} else if ( V_70 ) {
V_71 = F_46 ( V_70 ,
V_80 -> V_45 ,
V_80 -> V_46 ) ;
if ( V_71 < V_36 )
goto error;
V_80 -> V_146 = V_155 ;
} else {
V_80 -> V_146 = V_156 ;
}
F_70 ( & V_85 , & V_80 -> V_82 ) ;
if ( V_137 != NULL )
* V_137 = V_80 ;
V_71 = F_63 ( & V_80 -> V_110 ,
V_157 ,
V_79 ) ;
if ( V_71 != V_36 ) {
F_44 ( L_4 ,
V_79 . V_112 , V_79 . V_110 , V_71 ) ;
goto error;
}
V_80 -> V_82 . V_79 = F_64 ( & V_80 -> V_110 ) ;
if ( V_138 ) {
F_77 ( V_80 -> V_45 -> V_11 ,
V_80 -> V_82 . V_79 ) ;
F_77 ( V_80 -> V_46 -> V_11 ,
V_80 -> V_82 . V_79 ) ;
}
F_83 ( V_112 , V_80 -> V_82 . V_79 ) ;
return V_36 ;
error:
if ( V_80 != NULL ) {
F_30 ( V_80 -> V_45 , V_139 ) ;
F_30 ( V_80 -> V_46 , V_140 ) ;
F_19 ( V_80 ) ;
}
return V_71 ;
}
static int F_84 ( bool V_86 ,
struct V_78 V_79 ,
T_2 V_158 ,
T_2 V_102 )
{
int V_159 ;
struct V_88 V_89 ;
if ( F_51 ( V_79 ) || V_158 == V_107 ||
V_102 == V_107 )
return V_35 ;
V_89 . V_90 . V_91 . V_92 = F_59 ( V_102 , V_93 ) ;
V_89 . V_90 . V_91 . V_25 = F_59 ( V_94 ,
V_95 ) ;
V_89 . V_90 . V_91 . V_96 = sizeof( V_89 ) - sizeof( V_89 . V_90 . V_91 ) ;
V_89 . V_90 . V_97 . V_98 = V_86 ?
V_99 : V_100 ;
V_89 . V_101 . V_79 = V_79 ;
V_89 . V_101 . V_102 = V_158 ;
V_159 = F_85 ( V_94 ,
& V_89 . V_90 . V_91 , false ) ;
if ( V_159 < V_36 )
F_44 ( L_12 ,
V_86 ? L_13 : L_14 , V_102 ) ;
return V_159 ;
}
static int F_86 ( struct V_84 * V_80 ,
T_2 V_103 ,
T_2 V_12 ,
T_2 V_125 ,
T_1 V_104 ,
T_1 V_105 ,
struct V_69 * V_70 ,
struct V_134 * V_112 ,
T_5 V_135 ,
void * V_136 ,
struct V_84 * * V_137 )
{
const T_2 V_87 = F_79 ( V_112 ) ;
bool V_138 = V_12 & V_124 ;
int V_71 ;
if ( V_80 -> V_146 != V_156 &&
V_80 -> V_146 != V_155 )
return V_74 ;
if ( V_138 ) {
if ( ! ( V_80 -> V_82 . V_12 & V_124 ) ||
V_87 != V_80 -> V_144 ) {
return V_35 ;
}
} else if ( V_87 == V_80 -> V_144 ||
V_87 == V_80 -> V_145 ) {
return V_48 ;
}
if ( F_80 ( V_87 ) &&
F_80 ( V_80 -> V_144 ) )
return V_141 ;
if ( ( V_112 -> V_125 & V_149 ) &&
! V_80 -> V_150 )
return V_130 ;
if ( V_80 -> V_148 &&
( ! ( V_125 & V_151 ) ) )
return V_130 ;
if ( V_80 -> V_82 . V_103 != V_107 && V_80 -> V_82 . V_103 != V_87 )
return V_130 ;
if ( V_80 -> V_144 == V_143 ) {
if ( ! F_87 ( V_112 ) )
return V_160 ;
} else if ( V_87 == V_143 ) {
struct V_134 * V_161 ;
bool V_162 ;
V_161 = F_88 ( V_80 -> V_144 ) ;
V_162 = F_87 ( V_161 ) ;
F_89 ( V_161 ) ;
if ( ! V_162 )
return V_160 ;
}
if ( ( V_80 -> V_82 . V_12 & ~ V_163 ) != ( V_12 & ~ V_164 ) )
return V_73 ;
if ( V_87 != V_143 ) {
if ( V_80 -> V_82 . V_104 != V_104 ||
V_80 -> V_82 . V_105 != V_105 ) {
return V_73 ;
}
} else if ( V_80 -> V_82 . V_104 != V_105 ||
V_80 -> V_82 . V_105 != V_104 ) {
return V_73 ;
}
if ( V_87 != V_143 ) {
if ( V_80 -> V_146 != V_156 )
return V_35 ;
if ( V_70 != NULL ) {
V_71 = F_46 ( V_70 ,
V_80 -> V_45 ,
V_80 -> V_46 ) ;
if ( V_71 < V_36 )
return V_71 ;
if ( V_80 -> V_82 . V_12 & V_165 ) {
V_71 = F_48 ( V_80 -> V_45 ,
V_80 -> V_46 ) ;
if ( V_71 < V_36 ) {
F_47 (
V_80 -> V_45 ,
V_80 -> V_46 ) ;
return V_71 ;
}
}
V_80 -> V_146 = V_166 ;
} else {
V_80 -> V_146 = V_167 ;
}
} else if ( V_80 -> V_146 == V_156 ) {
return V_74 ;
} else {
if ( V_12 & V_165 ) {
V_71 =
F_48 ( V_80 -> V_45 ,
V_80 -> V_46 ) ;
if ( V_71 < V_36 )
return V_71 ;
V_80 -> V_82 . V_12 |= V_12 &
( V_165 | V_168 ) ;
}
V_80 -> V_146 = V_166 ;
}
if ( V_80 -> V_146 == V_166 ) {
V_71 =
F_84 ( true , V_80 -> V_82 . V_79 , V_87 ,
V_80 -> V_144 ) ;
if ( V_71 < V_36 )
F_44 ( L_15 ,
V_80 -> V_144 , V_80 -> V_82 . V_79 . V_112 ,
V_80 -> V_82 . V_79 . V_110 ) ;
}
V_80 -> V_145 = V_87 ;
V_80 -> V_82 . V_108 ++ ;
if ( V_135 ) {
V_80 -> V_135 = V_135 ;
V_80 -> V_136 = V_136 ;
}
if ( ! V_138 )
F_83 ( V_112 , V_80 -> V_82 . V_79 ) ;
if ( V_137 != NULL )
* V_137 = V_80 ;
return V_36 ;
}
static int F_90 ( struct V_78 V_79 ,
T_2 V_103 ,
T_2 V_12 ,
T_2 V_125 ,
T_1 V_104 ,
T_1 V_105 ,
struct V_69 * V_70 ,
struct V_134 * V_112 ,
T_5 V_135 ,
void * V_136 ,
struct V_84 * * V_137 ,
bool * V_169 )
{
const T_2 V_87 = F_79 ( V_112 ) ;
bool V_170 ;
struct V_84 * V_80 = NULL ;
bool V_138 = V_12 & V_124 ;
int V_71 ;
if ( F_51 ( V_79 ) ||
( V_12 & ~ V_171 ) || V_138 ||
! ( V_104 || V_105 ) ||
! V_112 || V_87 == V_107 ||
V_79 . V_112 == V_107 ) {
return V_35 ;
}
if ( V_70 && ! F_91 ( V_70 ) )
return V_35 ;
F_35 ( & V_85 . V_57 ) ;
if ( ! V_138 && F_92 ( V_112 , V_79 ) ) {
F_76 ( L_16 ,
V_87 , V_79 . V_112 , V_79 . V_110 ) ;
F_37 ( & V_85 . V_57 ) ;
return V_48 ;
}
if ( V_79 . V_110 != V_107 )
V_80 = F_56 ( V_79 ) ;
if ( ! V_80 ) {
V_170 = true ;
V_71 =
F_78 ( V_79 , V_103 , V_12 , V_125 ,
V_104 , V_105 , V_70 ,
V_112 , V_135 , V_136 , V_137 ) ;
} else {
V_170 = false ;
V_71 =
F_86 ( V_80 , V_103 , V_12 , V_125 ,
V_104 , V_105 , V_70 ,
V_112 , V_135 , V_136 , V_137 ) ;
}
F_37 ( & V_85 . V_57 ) ;
if ( V_169 )
* V_169 = ( V_87 == V_143 ) &&
! ( V_170 && V_138 ) ;
return V_71 ;
}
static int F_93 ( struct V_78 * V_79 ,
struct V_3 * * V_45 ,
T_1 V_104 ,
struct V_3 * * V_46 ,
T_1 V_105 ,
T_2 V_103 ,
T_2 V_12 ,
T_2 V_125 ,
T_5 V_135 ,
void * V_136 )
{
struct V_78 V_172 ;
struct V_134 * V_112 ;
struct V_84 * V_80 ;
int V_71 ;
bool V_169 ;
if ( F_51 ( * V_79 ) ) {
V_172 = F_59 (
V_143 , V_107 ) ;
} else
V_172 = * V_79 ;
V_112 = F_88 ( V_143 ) ;
V_80 = NULL ;
V_71 =
F_90 ( V_172 , V_103 , V_12 , V_125 ,
V_104 , V_105 , NULL , V_112 ,
V_135 , V_136 , & V_80 , & V_169 ) ;
if ( V_71 == V_36 ) {
if ( V_169 ) {
* V_45 = V_80 -> V_46 ;
* V_46 = V_80 -> V_45 ;
} else {
* V_45 = V_80 -> V_45 ;
* V_46 = V_80 -> V_46 ;
}
* V_79 = F_64 ( & V_80 -> V_110 ) ;
} else {
* V_79 = V_173 ;
F_76 ( L_17 ,
V_71 ) ;
}
F_89 ( V_112 ) ;
return V_71 ;
}
int F_94 ( struct V_78 * V_79 ,
struct V_3 * * V_45 ,
T_1 V_104 ,
struct V_3 * * V_46 ,
T_1 V_105 ,
T_2 V_103 ,
T_2 V_12 ,
T_2 V_125 ,
bool V_174 ,
T_5 V_135 ,
void * V_136 )
{
if ( ! V_79 || ! V_45 || ! V_46 ||
( ! V_104 && ! V_105 ) || ( V_12 & ~ V_171 ) )
return V_35 ;
if ( V_174 ) {
return F_75 ( V_79 , V_45 ,
V_104 , V_46 ,
V_105 , V_103 ,
V_12 , V_125 ) ;
} else {
return F_93 ( V_79 , V_45 ,
V_104 , V_46 ,
V_105 , V_103 , V_12 ,
V_125 , V_135 , V_136 ) ;
}
}
static int F_95 ( struct V_78 V_79 )
{
int V_71 ;
struct V_134 * V_112 ;
V_112 = F_88 ( V_143 ) ;
V_71 = F_96 ( V_79 , V_112 ) ;
F_89 ( V_112 ) ;
return V_71 ;
}
static int F_97 ( struct V_78 V_79 , bool V_174 )
{
if ( F_51 ( V_79 ) )
return V_35 ;
if ( V_174 )
return F_74 ( V_79 ) ;
else
return F_95 ( V_79 ) ;
}
static struct V_76 * F_98 ( struct V_77 * V_77 )
{
if ( ! F_99 ( & V_77 -> V_122 ) ) {
struct V_76 * V_80 =
F_100 ( & V_77 -> V_122 , struct V_76 ,
V_109 ) ;
return V_80 ;
}
return NULL ;
}
void F_101 ( void )
{
struct V_76 * V_80 ;
struct V_84 * V_175 ;
F_35 ( & V_85 . V_57 ) ;
while ( ( V_80 = F_98 ( & V_85 ) ) ) {
V_175 = (struct V_84 * ) V_80 ;
F_72 ( & V_85 , V_80 ) ;
F_19 ( V_175 ) ;
}
F_37 ( & V_85 . V_57 ) ;
}
int F_102 ( struct V_78 V_79 ,
T_2 V_103 ,
T_2 V_12 ,
T_2 V_125 ,
T_1 V_104 ,
T_1 V_105 ,
struct V_69 * V_70 ,
struct V_134 * V_112 )
{
return F_90 ( V_79 , V_103 , V_12 , V_125 ,
V_104 , V_105 ,
V_70 , V_112 , NULL , NULL , NULL , NULL ) ;
}
int F_103 ( struct V_78 V_79 ,
T_1 V_61 ,
T_1 V_62 ,
struct V_134 * V_112 )
{
struct V_84 * V_80 ;
int V_71 ;
const T_2 V_87 = F_79 ( V_112 ) ;
if ( F_51 ( V_79 ) || ! V_112 ||
V_87 == V_107 )
return V_35 ;
if ( V_61 == 0 || V_62 == 0 )
return V_35 ;
F_35 ( & V_85 . V_57 ) ;
if ( ! F_92 ( V_112 , V_79 ) ) {
F_44 ( L_18 ,
V_87 , V_79 . V_112 , V_79 . V_110 ) ;
V_71 = V_123 ;
goto V_68;
}
V_80 = F_56 ( V_79 ) ;
if ( ! V_80 ) {
V_71 = V_123 ;
goto V_68;
}
if ( V_80 -> V_144 != V_87 &&
( V_80 -> V_144 != V_143 ||
V_80 -> V_145 != V_87 ) ) {
V_71 = V_176 ;
goto V_68;
}
if ( V_80 -> V_146 != V_156 &&
V_80 -> V_146 != V_167 ) {
V_71 = V_74 ;
goto V_68;
}
V_71 = F_41 ( V_61 , V_62 ,
V_80 -> V_45 , V_80 -> V_46 ) ;
if ( V_71 < V_36 )
goto V_68;
V_71 = F_48 ( V_80 -> V_45 , V_80 -> V_46 ) ;
if ( V_71 < V_36 ) {
F_47 ( V_80 -> V_45 ,
V_80 -> V_46 ) ;
goto V_68;
}
if ( V_80 -> V_146 == V_156 )
V_80 -> V_146 = V_155 ;
else
V_80 -> V_146 = V_166 ;
V_80 -> V_152 = true ;
if ( V_80 -> V_146 == V_166 ) {
V_71 =
F_84 ( true , V_79 , V_87 , V_80 -> V_144 ) ;
if ( V_71 < V_36 ) {
F_44 ( L_15 ,
V_80 -> V_144 , V_80 -> V_82 . V_79 . V_112 ,
V_80 -> V_82 . V_79 . V_110 ) ;
}
}
V_71 = V_36 ;
V_68:
F_37 ( & V_85 . V_57 ) ;
return V_71 ;
}
static void F_104 ( struct V_84 * V_80 )
{
V_80 -> V_45 -> V_16 = NULL ;
V_80 -> V_46 -> V_16 = NULL ;
}
int F_96 ( struct V_78 V_79 , struct V_134 * V_112 )
{
struct V_84 * V_80 ;
const T_2 V_87 = F_79 ( V_112 ) ;
T_2 V_102 ;
bool V_138 = false ;
int V_71 ;
if ( F_51 ( V_79 ) || ! V_112 ||
V_87 == V_107 ) {
return V_35 ;
}
F_35 ( & V_85 . V_57 ) ;
if ( ! F_92 ( V_112 , V_79 ) ) {
F_76 ( L_18 ,
V_87 , V_79 . V_112 , V_79 . V_110 ) ;
V_71 = V_123 ;
goto V_68;
}
V_80 = F_56 ( V_79 ) ;
if ( ! V_80 ) {
F_76 ( L_19 ,
V_87 , V_79 . V_112 , V_79 . V_110 ) ;
V_71 = V_123 ;
goto V_68;
}
if ( V_87 != V_80 -> V_144 && V_87 != V_80 -> V_145 ) {
V_71 = V_177 ;
goto V_68;
}
if ( V_87 == V_80 -> V_144 ) {
V_102 = V_80 -> V_145 ;
V_80 -> V_144 = V_107 ;
} else {
V_102 = V_80 -> V_144 ;
V_80 -> V_145 = V_107 ;
}
V_80 -> V_82 . V_108 -- ;
V_138 = V_80 -> V_82 . V_12 & V_124 ;
if ( V_87 != V_143 ) {
bool V_178 ;
F_34 ( V_80 -> V_45 ) ;
V_178 = V_80 -> V_45 -> V_11 ||
V_80 -> V_46 -> V_11 ;
if ( F_105 ( V_80 ) ) {
V_71 =
F_49 ( V_179 ,
V_80 -> V_45 ,
V_80 -> V_46 ) ;
if ( V_71 < V_36 )
F_44 ( L_20 ,
V_79 . V_112 , V_79 . V_110 ,
V_71 ) ;
if ( V_80 -> V_152 )
F_47 ( V_80 -> V_45 ,
V_80 ->
V_46 ) ;
else
F_47 ( V_80 -> V_45 ,
V_80 ->
V_46 ) ;
}
if ( ! V_178 )
F_104 ( V_80 ) ;
F_36 ( V_80 -> V_45 ) ;
if ( ! V_178 && V_80 -> V_135 )
V_80 -> V_135 ( V_80 -> V_136 ) ;
} else {
if ( V_80 -> V_135 ) {
V_80 -> V_135 = NULL ;
V_80 -> V_136 = NULL ;
}
}
if ( V_80 -> V_82 . V_108 == 0 ) {
F_72 ( & V_85 , & V_80 -> V_82 ) ;
if ( V_138 )
F_19 ( V_80 -> V_154 ) ;
F_33 ( V_80 -> V_45 , V_80 -> V_46 ) ;
F_30 ( V_80 -> V_45 , V_80 -> V_82 . V_104 ) ;
F_30 ( V_80 -> V_46 , V_80 -> V_82 . V_105 ) ;
F_66 ( & V_80 -> V_110 ) ;
F_19 ( V_80 ) ;
F_106 ( V_112 , V_79 ) ;
} else {
F_84 ( false , V_79 , V_87 , V_102 ) ;
if ( V_87 == V_143 &&
F_105 ( V_80 ) ) {
V_80 -> V_146 = V_180 ;
} else {
V_80 -> V_146 = V_181 ;
}
if ( ! V_138 )
F_106 ( V_112 , V_79 ) ;
}
V_71 = V_36 ;
V_68:
F_37 ( & V_85 . V_57 ) ;
return V_71 ;
}
int F_107 ( struct V_78 V_79 ,
struct V_134 * V_112 ,
T_1 V_182 )
{
struct V_84 * V_80 ;
const T_2 V_87 = F_79 ( V_112 ) ;
bool V_138 = false ;
int V_71 ;
if ( F_51 ( V_79 ) || ! V_112 ||
V_87 == V_107 )
return V_35 ;
F_35 ( & V_85 . V_57 ) ;
if ( ! F_92 ( V_112 , V_79 ) ) {
F_76 ( L_18 ,
V_87 , V_79 . V_112 , V_79 . V_110 ) ;
V_71 = V_123 ;
goto V_68;
}
V_80 = F_56 ( V_79 ) ;
if ( ! V_80 ) {
F_76 ( L_21 ,
V_87 , V_79 . V_112 , V_79 . V_110 ) ;
V_71 = V_123 ;
goto V_68;
}
if ( V_87 != V_80 -> V_144 && V_87 != V_80 -> V_145 ) {
V_71 = V_177 ;
goto V_68;
}
V_138 = V_80 -> V_82 . V_12 & V_124 ;
V_71 = V_36 ;
if ( V_87 != V_143 ) {
struct V_69 V_70 ;
V_70 . V_59 = V_182 ;
V_70 . V_183 = F_82 ( V_80 -> V_82 ) ;
F_34 ( V_80 -> V_45 ) ;
F_104 ( V_80 ) ;
V_71 =
F_46 ( & V_70 ,
V_80 -> V_45 ,
V_80 -> V_46 ) ;
F_36 ( V_80 -> V_45 ) ;
if ( V_71 == V_36 ) {
V_80 -> V_146 ++ ;
if ( V_80 -> V_135 )
V_80 -> V_135 ( V_80 -> V_136 ) ;
}
}
V_68:
F_37 ( & V_85 . V_57 ) ;
return V_71 ;
}
static int F_108 ( struct V_84 * V_80 )
{
int V_71 ;
if ( V_80 -> V_45 -> V_16 != NULL &&
V_80 -> V_46 -> V_16 != NULL ) {
return V_36 ;
}
if ( NULL == V_80 -> V_45 -> V_11 ||
NULL == V_80 -> V_46 -> V_11 ) {
V_71 = F_48 ( V_80 -> V_45 , V_80 -> V_46 ) ;
if ( V_71 < V_36 )
return V_71 ;
}
memcpy ( & V_80 -> V_184 , V_80 -> V_45 -> V_11 ,
sizeof( V_80 -> V_184 ) ) ;
V_80 -> V_45 -> V_16 = & V_80 -> V_184 ;
memcpy ( & V_80 -> V_185 , V_80 -> V_46 -> V_11 ,
sizeof( V_80 -> V_185 ) ) ;
V_80 -> V_46 -> V_16 = & V_80 -> V_185 ;
return V_36 ;
}
int F_109 ( struct V_78 V_79 ,
struct V_134 * V_112 ,
T_2 V_75 )
{
struct V_84 * V_80 ;
const T_2 V_87 = F_79 ( V_112 ) ;
bool V_138 = false ;
int V_71 ;
if ( F_51 ( V_79 ) || ! V_112 ||
V_87 == V_107 )
return V_35 ;
F_35 ( & V_85 . V_57 ) ;
if ( ! F_92 ( V_112 , V_79 ) ) {
F_76 ( L_18 ,
V_87 , V_79 . V_112 , V_79 . V_110 ) ;
V_71 = V_123 ;
goto V_68;
}
V_80 = F_56 ( V_79 ) ;
if ( ! V_80 ) {
F_76 ( L_21 ,
V_87 , V_79 . V_112 , V_79 . V_110 ) ;
V_71 = V_123 ;
goto V_68;
}
if ( V_87 != V_80 -> V_144 && V_87 != V_80 -> V_145 ) {
V_71 = V_177 ;
goto V_68;
}
V_138 = V_80 -> V_82 . V_12 & V_124 ;
if ( V_87 != V_143 ) {
F_34 ( V_80 -> V_45 ) ;
V_71 = F_108 ( V_80 ) ;
if ( V_71 < V_36 )
F_44 ( L_22 ,
V_79 . V_112 , V_79 . V_110 , V_71 ) ;
F_49 ( V_75 , V_80 -> V_45 , V_80 -> V_46 ) ;
F_47 ( V_80 -> V_45 ,
V_80 -> V_46 ) ;
V_80 -> V_146 -- ;
F_36 ( V_80 -> V_45 ) ;
}
V_71 = V_36 ;
V_68:
F_37 ( & V_85 . V_57 ) ;
return V_71 ;
}
void F_110 ( void )
{
struct V_76 * V_80 ;
struct V_81 * V_186 ;
F_35 ( & V_83 . V_57 ) ;
while ( ( V_80 = F_98 ( & V_83 ) ) ) {
V_186 = (struct V_81 * ) V_80 ;
if ( ! ( V_80 -> V_12 & V_124 ) )
F_69 ( V_80 -> V_79 ) ;
V_80 -> V_108 = 0 ;
F_72 ( & V_83 , V_80 ) ;
F_65 ( V_186 ) ;
}
F_37 ( & V_83 . V_57 ) ;
}
static void F_111 ( const struct V_187 * V_188 )
{
if ( F_112 ( V_188 -> V_12 ) )
F_34 ( V_188 -> V_45 ) ;
}
static void F_113 ( const struct V_187 * V_188 )
{
if ( F_112 ( V_188 -> V_12 ) )
F_36 ( V_188 -> V_45 ) ;
}
static int F_114 ( struct V_3 * V_45 ,
struct V_3 * V_46 ,
bool V_189 )
{
int V_71 ;
if ( NULL == V_45 -> V_11 || NULL == V_46 -> V_11 ) {
if ( V_189 )
V_71 = F_48 ( V_45 , V_46 ) ;
else
V_71 = V_190 ;
if ( V_71 < V_36 )
return ( V_45 -> V_16 &&
V_46 -> V_16 ) ?
V_190 :
V_177 ;
}
return V_36 ;
}
static int F_115 ( const struct V_187 * V_188 ,
struct V_13 * * V_191 ,
struct V_13 * * V_192 )
{
int V_71 ;
V_71 = F_114 ( V_188 -> V_45 , V_188 -> V_46 ,
F_112 ( V_188 -> V_12 ) ) ;
if ( V_71 == V_36 ) {
* V_191 = V_188 -> V_45 -> V_11 ;
* V_192 = V_188 -> V_46 -> V_11 ;
} else if ( V_188 -> V_45 -> V_16 &&
V_188 -> V_46 -> V_16 ) {
* V_191 = V_188 -> V_45 -> V_16 ;
* V_192 = V_188 -> V_46 -> V_16 ;
V_71 = V_36 ;
}
return V_71 ;
}
static int F_116 ( void * V_136 )
{
struct V_187 * V_188 = (struct V_187 * ) V_136 ;
F_111 ( V_188 ) ;
while ( V_188 -> V_193 > 0 ) {
V_188 -> V_193 -- ;
V_188 -> V_194 ++ ;
F_117 ( & V_188 -> V_98 ) ;
}
F_113 ( V_188 ) ;
return V_36 ;
}
static bool F_118 ( struct V_187 * V_188 )
{
unsigned int V_194 ;
if ( V_188 -> V_12 & V_165 )
return false ;
V_188 -> V_193 ++ ;
V_194 = V_188 -> V_194 ;
F_113 ( V_188 ) ;
F_119 ( V_188 -> V_98 , V_194 != V_188 -> V_194 ) ;
F_111 ( V_188 ) ;
return true ;
}
static T_6 F_120 ( struct V_3 * V_45 ,
struct V_3 * V_46 ,
const T_1 V_195 ,
const void * V_196 ,
T_4 V_197 ,
T_7 V_198 ,
bool V_189 )
{
T_8 V_199 ;
T_1 V_200 ;
T_4 V_201 ;
T_6 V_71 ;
V_71 = F_114 ( V_45 , V_46 , V_189 ) ;
if ( F_121 ( V_71 != V_36 ) )
return V_71 ;
V_199 = F_122 ( V_45 -> V_11 ,
V_46 -> V_11 ,
V_195 ) ;
if ( V_199 == 0 )
return V_202 ;
if ( V_199 < V_36 )
return ( T_6 ) V_199 ;
V_201 = ( T_4 ) ( V_199 > V_197 ? V_197 : V_199 ) ;
V_200 = F_123 ( V_45 -> V_11 ) ;
if ( F_124 ( V_200 + V_201 < V_195 ) ) {
V_71 = V_198 ( V_45 , V_200 , V_196 , 0 , V_201 ) ;
} else {
const T_4 V_153 = ( T_4 ) ( V_195 - V_200 ) ;
V_71 = V_198 ( V_45 , V_200 , V_196 , 0 , V_153 ) ;
if ( V_71 >= V_36 )
V_71 = V_198 ( V_45 , 0 , V_196 , V_153 ,
V_201 - V_153 ) ;
}
if ( V_71 < V_36 )
return V_71 ;
F_125 ( V_45 -> V_11 , V_201 ,
V_195 ) ;
return V_201 ;
}
static T_6 F_126 ( struct V_3 * V_45 ,
struct V_3 * V_46 ,
const T_1 V_203 ,
void * V_196 ,
T_4 V_197 ,
T_9 V_204 ,
bool V_205 ,
bool V_189 )
{
T_8 V_206 ;
T_1 V_122 ;
T_4 V_207 ;
T_6 V_71 ;
V_71 = F_114 ( V_45 , V_46 , V_189 ) ;
if ( F_121 ( V_71 != V_36 ) )
return V_71 ;
V_206 = F_127 ( V_46 -> V_11 ,
V_45 -> V_11 ,
V_203 ) ;
if ( V_206 == 0 )
return V_208 ;
if ( V_206 < V_36 )
return ( T_6 ) V_206 ;
V_207 = ( T_4 ) ( V_206 > V_197 ? V_197 : V_206 ) ;
V_122 = F_128 ( V_45 -> V_11 ) ;
if ( F_124 ( V_122 + V_207 < V_203 ) ) {
V_71 = V_204 ( V_196 , 0 , V_46 , V_122 , V_207 ) ;
} else {
const T_4 V_153 = ( T_4 ) ( V_203 - V_122 ) ;
V_71 = V_204 ( V_196 , 0 , V_46 , V_122 , V_153 ) ;
if ( V_71 >= V_36 )
V_71 = V_204 ( V_196 , V_153 , V_46 , 0 ,
V_207 - V_153 ) ;
}
if ( V_71 < V_36 )
return V_71 ;
if ( V_205 )
F_129 ( V_45 -> V_11 ,
V_207 , V_203 ) ;
return V_207 ;
}
int F_130 ( struct V_187 * * V_188 ,
struct V_78 * V_79 ,
T_1 V_209 ,
T_1 V_210 ,
T_2 V_103 ,
T_2 V_12 ,
T_2 V_125 )
{
struct V_187 * V_211 ;
int V_63 ;
struct V_78 V_25 = V_173 ;
struct V_78 V_92 = F_59 ( V_103 , V_107 ) ;
enum V_212 V_213 ;
T_5 V_135 ;
void * V_136 ;
if ( V_209 + V_210 < V_214 ( V_209, V_210 ) ||
V_209 + V_210 > V_215 )
return V_216 ;
V_63 = V_212 ( & V_25 , & V_92 , false , & V_213 ) ;
if ( V_63 < V_36 )
V_213 = F_131 () ?
V_217 : V_218 ;
if ( ( ! F_112 ( V_12 ) || F_9 ( V_12 ) ) &&
V_217 != V_213 ) {
F_76 ( L_23 ) ;
return V_35 ;
}
if ( F_9 ( V_12 ) ) {
if ( F_112 ( V_12 ) ) {
F_132 ( L_24 ) ;
return V_35 ;
}
if ( V_209 + V_210 > V_219 )
return V_216 ;
}
V_211 = F_29 ( sizeof( * V_211 ) , V_20 ) ;
if ( ! V_211 )
return V_49 ;
V_211 -> V_195 = V_209 ;
V_211 -> V_203 = V_210 ;
V_211 -> V_103 = V_103 ;
V_211 -> V_12 = V_12 ;
V_211 -> V_125 = V_125 ;
V_135 = NULL ;
V_136 = NULL ;
if ( V_218 == V_213 ) {
V_211 -> V_174 = false ;
if ( ! ( V_12 & V_124 ) ) {
V_211 -> V_193 = 0 ;
V_211 -> V_194 = 0 ;
F_133 ( & V_211 -> V_98 ) ;
V_135 = F_116 ;
V_136 = ( void * ) V_211 ;
}
} else {
V_211 -> V_174 = true ;
}
V_63 = F_94 ( V_79 ,
& V_211 -> V_45 ,
V_211 -> V_195 ,
& V_211 -> V_46 ,
V_211 -> V_203 ,
V_211 -> V_103 ,
V_211 -> V_12 ,
V_211 -> V_125 ,
V_211 -> V_174 ,
V_135 , V_136 ) ;
if ( V_63 < V_36 ) {
F_19 ( V_211 ) ;
return V_63 ;
}
* V_188 = V_211 ;
V_211 -> V_79 = * V_79 ;
return V_63 ;
}
int F_134 ( struct V_187 * * V_188 )
{
int V_71 ;
struct V_187 * V_220 ;
if ( ! V_188 || ! ( * V_188 ) )
return V_35 ;
V_220 = * V_188 ;
V_71 = F_97 ( V_220 -> V_79 , V_220 -> V_174 ) ;
memset ( V_220 , 0 , sizeof( * V_220 ) ) ;
V_220 -> V_79 = V_173 ;
V_220 -> V_103 = V_107 ;
F_19 ( V_220 ) ;
* V_188 = NULL ;
return V_71 ;
}
int F_135 ( const struct V_187 * V_188 ,
T_1 * V_221 ,
T_1 * V_222 )
{
struct V_13 * V_191 ;
struct V_13 * V_192 ;
int V_71 ;
if ( ! V_188 )
return V_35 ;
F_111 ( V_188 ) ;
V_71 =
F_115 ( V_188 , & V_191 , & V_192 ) ;
if ( V_71 == V_36 )
F_136 ( V_191 , V_192 ,
V_221 , V_222 ) ;
F_113 ( V_188 ) ;
if ( V_71 == V_36 &&
( ( V_221 && * V_221 >= V_188 -> V_195 ) ||
( V_222 && * V_222 >= V_188 -> V_195 ) ) )
return V_223 ;
return V_71 ;
}
int F_137 ( const struct V_187 * V_188 ,
T_1 * V_224 ,
T_1 * V_225 )
{
struct V_13 * V_191 ;
struct V_13 * V_192 ;
int V_71 ;
if ( ! V_188 )
return V_35 ;
F_111 ( V_188 ) ;
V_71 =
F_115 ( V_188 , & V_191 , & V_192 ) ;
if ( V_71 == V_36 )
F_136 ( V_192 , V_191 ,
V_224 , V_225 ) ;
F_113 ( V_188 ) ;
if ( V_71 == V_36 &&
( ( V_224 && * V_224 >= V_188 -> V_203 ) ||
( V_225 && * V_225 >= V_188 -> V_203 ) ) )
return V_223 ;
return V_71 ;
}
T_8 F_138 ( const struct V_187 * V_188 )
{
struct V_13 * V_191 ;
struct V_13 * V_192 ;
T_8 V_71 ;
if ( ! V_188 )
return V_35 ;
F_111 ( V_188 ) ;
V_71 =
F_115 ( V_188 , & V_191 , & V_192 ) ;
if ( V_71 == V_36 )
V_71 = F_122 ( V_191 ,
V_192 ,
V_188 -> V_195 ) ;
else
V_71 = 0 ;
F_113 ( V_188 ) ;
return V_71 ;
}
T_8 F_139 ( const struct V_187 * V_188 )
{
struct V_13 * V_191 ;
struct V_13 * V_192 ;
T_8 V_71 ;
if ( ! V_188 )
return V_35 ;
F_111 ( V_188 ) ;
V_71 =
F_115 ( V_188 , & V_191 , & V_192 ) ;
if ( V_71 == V_36 )
V_71 = F_122 ( V_192 ,
V_191 ,
V_188 -> V_203 ) ;
else
V_71 = 0 ;
F_113 ( V_188 ) ;
return V_71 ;
}
T_8 F_140 ( const struct V_187 * V_188 )
{
struct V_13 * V_191 ;
struct V_13 * V_192 ;
T_8 V_71 ;
if ( ! V_188 )
return V_35 ;
F_111 ( V_188 ) ;
V_71 =
F_115 ( V_188 , & V_191 , & V_192 ) ;
if ( V_71 == V_36 )
V_71 = F_127 ( V_191 ,
V_192 ,
V_188 -> V_195 ) ;
else
V_71 = 0 ;
F_113 ( V_188 ) ;
return V_71 ;
}
T_8 F_141 ( const struct V_187 * V_188 )
{
struct V_13 * V_191 ;
struct V_13 * V_192 ;
T_8 V_71 ;
if ( ! V_188 )
return V_35 ;
F_111 ( V_188 ) ;
V_71 =
F_115 ( V_188 , & V_191 , & V_192 ) ;
if ( V_71 == V_36 )
V_71 = F_127 ( V_192 ,
V_191 ,
V_188 -> V_203 ) ;
else
V_71 = 0 ;
F_113 ( V_188 ) ;
return V_71 ;
}
T_6 F_142 ( struct V_187 * V_188 ,
const void * V_196 ,
T_4 V_197 ,
int V_226 )
{
T_6 V_71 ;
if ( ! V_188 || ! V_196 )
return V_35 ;
F_111 ( V_188 ) ;
do {
V_71 = F_120 ( V_188 -> V_45 ,
V_188 -> V_46 ,
V_188 -> V_195 ,
V_196 , V_197 ,
F_24 ,
F_112 ( V_188 -> V_12 ) ) ;
if ( V_71 == V_190 &&
! F_118 ( V_188 ) )
V_71 = V_227 ;
} while ( V_71 == V_190 );
F_113 ( V_188 ) ;
return V_71 ;
}
T_6 F_143 ( struct V_187 * V_188 ,
void * V_196 ,
T_4 V_197 ,
int V_226 )
{
T_6 V_71 ;
if ( ! V_188 || ! V_196 )
return V_35 ;
F_111 ( V_188 ) ;
do {
V_71 = F_126 ( V_188 -> V_45 ,
V_188 -> V_46 ,
V_188 -> V_203 ,
V_196 , V_197 ,
F_25 , true ,
F_112 ( V_188 -> V_12 ) ) ;
if ( V_71 == V_190 &&
! F_118 ( V_188 ) )
V_71 = V_227 ;
} while ( V_71 == V_190 );
F_113 ( V_188 ) ;
return V_71 ;
}
T_6 F_144 ( struct V_187 * V_188 ,
void * V_196 ,
T_4 V_197 ,
int V_226 )
{
T_6 V_71 ;
if ( ! V_188 || ! V_196 )
return V_35 ;
F_111 ( V_188 ) ;
do {
V_71 = F_126 ( V_188 -> V_45 ,
V_188 -> V_46 ,
V_188 -> V_203 ,
V_196 , V_197 ,
F_25 , false ,
F_112 ( V_188 -> V_12 ) ) ;
if ( V_71 == V_190 &&
! F_118 ( V_188 ) )
V_71 = V_227 ;
} while ( V_71 == V_190 );
F_113 ( V_188 ) ;
return V_71 ;
}
T_6 F_145 ( struct V_187 * V_188 ,
void * V_33 ,
T_4 V_228 ,
int V_226 )
{
T_6 V_71 ;
if ( ! V_188 || ! V_33 )
return V_35 ;
F_111 ( V_188 ) ;
do {
V_71 = F_120 ( V_188 -> V_45 ,
V_188 -> V_46 ,
V_188 -> V_195 ,
V_33 , V_228 ,
F_26 ,
F_112 ( V_188 -> V_12 ) ) ;
if ( V_71 == V_190 &&
! F_118 ( V_188 ) )
V_71 = V_227 ;
} while ( V_71 == V_190 );
F_113 ( V_188 ) ;
return V_71 ;
}
T_6 F_146 ( struct V_187 * V_188 ,
void * V_33 ,
T_4 V_228 ,
int V_226 )
{
T_6 V_71 ;
if ( ! V_188 || ! V_33 )
return V_35 ;
F_111 ( V_188 ) ;
do {
V_71 = F_126 ( V_188 -> V_45 ,
V_188 -> V_46 ,
V_188 -> V_203 ,
V_33 , V_228 ,
F_27 ,
true , F_112 ( V_188 -> V_12 ) ) ;
if ( V_71 == V_190 &&
! F_118 ( V_188 ) )
V_71 = V_227 ;
} while ( V_71 == V_190 );
F_113 ( V_188 ) ;
return V_71 ;
}
T_6 F_147 ( struct V_187 * V_188 ,
void * V_33 ,
T_4 V_228 ,
int V_226 )
{
T_6 V_71 ;
if ( ! V_188 || ! V_33 )
return V_35 ;
F_111 ( V_188 ) ;
do {
V_71 = F_126 ( V_188 -> V_45 ,
V_188 -> V_46 ,
V_188 -> V_203 ,
V_33 , V_228 ,
F_27 ,
false , F_112 ( V_188 -> V_12 ) ) ;
if ( V_71 == V_190 &&
! F_118 ( V_188 ) )
V_71 = V_227 ;
} while ( V_71 == V_190 );
F_113 ( V_188 ) ;
return V_71 ;
}
