static T_1 F_1 ( void )
{
return V_1 ;
}
static unsigned int F_2 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 V_7 ;
unsigned int V_8 ;
if ( V_5 -> V_9 && V_5 -> V_9 -> V_10 )
return V_5 -> V_9 -> V_10 ;
F_3 ( V_5 , & V_7 ) ;
V_8 = F_4 ( ( V_11 T_1 ) V_7 . V_12 ,
( V_11 T_1 ) V_7 . V_13 ^ V_7 . V_14 ,
( V_11 T_1 ) V_7 . V_15 , V_3 -> V_16 ) ;
return V_8 ;
}
static struct V_17 * F_5 ( const T_1 V_8 ,
struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_17 * V_20 , * V_21 ;
T_1 V_22 = F_1 () ;
if ( F_6 ( V_19 ) )
return NULL ;
F_7 (flow, next, head, flowchain) {
T_1 V_23 = V_20 -> V_24 + V_3 -> V_25 ;
if ( F_8 ( V_23 , V_22 ) ) {
if ( F_9 ( & V_20 -> V_26 , V_19 ) )
return NULL ;
F_10 ( & V_20 -> V_26 ) ;
F_11 ( V_20 ) ;
V_3 -> V_27 -- ;
} else if ( V_20 -> V_28 == V_8 ) {
return V_20 ;
}
}
return NULL ;
}
static struct V_17 * F_12 ( struct V_18 * V_19 ,
struct V_2 * V_3 )
{
struct V_17 * V_20 ;
T_1 V_22 = F_1 () ;
if ( ! F_6 ( V_19 ) ) {
F_13 (flow, head, flowchain) {
T_1 V_23 = V_20 -> V_24 + V_3 -> V_25 ;
if ( F_8 ( V_23 , V_22 ) )
return V_20 ;
}
}
if ( V_3 -> V_27 >= V_3 -> V_29 ) {
V_3 -> V_30 ++ ;
return NULL ;
}
V_20 = F_14 ( sizeof( struct V_17 ) , V_31 ) ;
if ( ! V_20 )
return NULL ;
V_3 -> V_27 ++ ;
F_15 ( & V_20 -> V_26 ) ;
F_16 ( & V_20 -> V_26 , V_19 ) ;
return V_20 ;
}
static enum V_32 F_17 ( struct V_4 * V_5 , struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_34 ) ;
T_1 V_35 , V_8 ;
T_1 V_36 , V_37 [ V_38 ] , V_39 ;
struct V_17 * V_20 ;
T_1 V_40 , V_41 ;
int V_42 ;
T_1 V_23 ;
T_1 V_22 = F_1 () ;
V_23 = V_3 -> V_43 + V_3 -> V_44 ;
if ( F_8 ( V_23 , V_22 ) ) {
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ )
F_19 ( V_3 -> V_45 [ V_42 ] , V_46 ) ;
V_3 -> V_43 = V_22 ;
}
V_8 = F_2 ( V_3 , V_5 ) ;
V_39 = V_8 & V_47 ;
V_20 = F_5 ( V_8 , & V_3 -> V_48 [ V_39 ] , V_3 ) ;
if ( V_20 ) {
V_20 -> V_24 = V_22 ;
return V_49 ;
}
V_35 = V_8 ;
V_36 = 0 ;
for ( V_42 = 0 ; V_42 < V_38 - 1 ; V_42 ++ ) {
V_37 [ V_42 ] = V_35 & V_47 ;
V_36 ^= V_37 [ V_42 ] ;
V_35 >>= V_50 ;
}
V_37 [ V_38 - 1 ] = V_36 ^ V_35 ;
V_40 = F_20 ( V_5 ) ;
V_41 = ~ 0U ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ ) {
T_1 V_51 ;
if ( ! F_21 ( V_37 [ V_42 ] , V_3 -> V_45 [ V_42 ] ) ) {
V_3 -> V_52 [ V_42 ] [ V_37 [ V_42 ] ] = 0 ;
F_22 ( V_37 [ V_42 ] , V_3 -> V_45 [ V_42 ] ) ;
}
V_51 = V_3 -> V_52 [ V_42 ] [ V_37 [ V_42 ] ] + V_40 ;
if ( V_41 > V_51 )
V_41 = V_51 ;
}
if ( V_41 > V_3 -> V_53 ) {
V_20 = F_12 ( & V_3 -> V_48 [ V_39 ] , V_3 ) ;
if ( ! V_20 )
return V_54 ;
V_20 -> V_28 = V_8 ;
V_20 -> V_24 = V_22 ;
V_3 -> V_55 ++ ;
return V_49 ;
}
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ ) {
if ( V_3 -> V_52 [ V_42 ] [ V_37 [ V_42 ] ] < V_41 )
V_3 -> V_52 [ V_42 ] [ V_37 [ V_42 ] ] = V_41 ;
}
return V_54 ;
}
static struct V_4 * F_23 ( struct V_56 * V_57 )
{
struct V_4 * V_5 = V_57 -> V_19 ;
V_57 -> V_19 = V_5 -> V_21 ;
V_5 -> V_21 = NULL ;
return V_5 ;
}
static void F_24 ( struct V_56 * V_57 , struct V_4 * V_5 )
{
if ( V_57 -> V_19 == NULL )
V_57 -> V_19 = V_5 ;
else
V_57 -> V_58 -> V_21 = V_5 ;
V_57 -> V_58 = V_5 ;
V_5 -> V_21 = NULL ;
}
static unsigned int F_25 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_34 ) ;
struct V_56 * V_57 ;
V_57 = & V_3 -> V_59 [ V_49 ] ;
if ( ! V_57 -> V_19 )
V_57 = & V_3 -> V_59 [ V_54 ] ;
if ( V_57 -> V_19 ) {
struct V_4 * V_5 = F_23 ( V_57 ) ;
V_34 -> V_3 . V_60 -- ;
V_34 -> V_61 . V_62 ++ ;
V_34 -> V_61 . V_63 -= F_20 ( V_5 ) ;
F_26 ( V_5 ) ;
}
return V_57 - V_3 -> V_59 ;
}
static int F_27 ( struct V_4 * V_5 , struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_34 ) ;
enum V_32 V_64 ;
struct V_56 * V_57 ;
V_64 = F_17 ( V_5 , V_34 ) ;
V_57 = & V_3 -> V_59 [ V_64 ] ;
F_24 ( V_57 , V_5 ) ;
V_34 -> V_61 . V_63 += F_20 ( V_5 ) ;
if ( F_6 ( & V_57 -> V_65 ) ) {
unsigned int V_66 ;
if ( V_64 == V_49 ) {
V_66 = 1 ;
F_16 ( & V_57 -> V_65 , & V_3 -> V_67 ) ;
} else {
V_66 = V_3 -> V_68 ;
F_16 ( & V_57 -> V_65 , & V_3 -> V_69 ) ;
}
V_57 -> V_70 = V_66 * V_3 -> V_71 ;
}
if ( ++ V_34 -> V_3 . V_60 < V_34 -> V_72 )
return V_73 ;
V_3 -> V_74 ++ ;
if ( F_25 ( V_34 ) == V_64 )
return V_75 ;
F_28 ( V_34 , 1 ) ;
return V_73 ;
}
static struct V_4 * F_29 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_18 ( V_34 ) ;
struct V_4 * V_5 = NULL ;
struct V_56 * V_57 ;
struct V_18 * V_19 ;
V_76:
V_19 = & V_3 -> V_69 ;
if ( F_6 ( V_19 ) ) {
V_19 = & V_3 -> V_67 ;
if ( F_6 ( V_19 ) )
return NULL ;
}
V_57 = F_30 ( V_19 , struct V_56 , V_65 ) ;
if ( V_57 -> V_70 <= 0 ) {
int V_66 = ( V_57 - V_3 -> V_59 == V_49 ) ?
1 : V_3 -> V_68 ;
V_57 -> V_70 += V_66 * V_3 -> V_71 ;
F_31 ( & V_57 -> V_65 , & V_3 -> V_67 ) ;
goto V_76;
}
if ( V_57 -> V_19 ) {
V_5 = F_23 ( V_57 ) ;
V_34 -> V_3 . V_60 -- ;
V_34 -> V_61 . V_63 -= F_20 ( V_5 ) ;
}
if ( ! V_5 ) {
if ( ( V_19 == & V_3 -> V_69 ) && ! F_6 ( & V_3 -> V_67 ) )
F_31 ( & V_57 -> V_65 , & V_3 -> V_67 ) ;
else
F_32 ( & V_57 -> V_65 ) ;
goto V_76;
}
F_33 ( V_34 , V_5 ) ;
V_57 -> V_70 -= F_20 ( V_5 ) ;
return V_5 ;
}
static void F_34 ( struct V_33 * V_34 )
{
struct V_4 * V_5 ;
while ( ( V_5 = F_29 ( V_34 ) ) != NULL )
F_26 ( V_5 ) ;
}
static void * F_35 ( T_2 V_77 )
{
void * V_78 = F_14 ( V_77 , V_79 | V_80 ) ;
if ( ! V_78 )
V_78 = F_36 ( V_77 ) ;
return V_78 ;
}
static void F_37 ( void * V_81 )
{
if ( V_81 ) {
if ( F_38 ( V_81 ) )
F_39 ( V_81 ) ;
else
F_11 ( V_81 ) ;
}
}
static void F_40 ( struct V_33 * V_34 )
{
int V_42 ;
struct V_2 * V_3 = F_18 ( V_34 ) ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ ) {
F_37 ( V_3 -> V_52 [ V_42 ] ) ;
F_37 ( V_3 -> V_45 [ V_42 ] ) ;
}
for ( V_42 = 0 ; V_42 < V_82 ; V_42 ++ ) {
struct V_17 * V_20 , * V_21 ;
struct V_18 * V_19 = & V_3 -> V_48 [ V_42 ] ;
if ( F_6 ( V_19 ) )
continue;
F_7 (flow, next, head, flowchain) {
F_10 ( & V_20 -> V_26 ) ;
F_11 ( V_20 ) ;
}
}
F_37 ( V_3 -> V_48 ) ;
}
static int F_41 ( struct V_33 * V_34 , struct V_83 * V_84 )
{
struct V_2 * V_3 = F_18 ( V_34 ) ;
struct V_83 * V_85 [ V_86 + 1 ] ;
unsigned int V_60 ;
int V_87 ;
T_3 V_88 ;
T_1 V_89 = V_3 -> V_71 ;
T_1 V_90 = V_3 -> V_68 ;
if ( ! V_84 )
return - V_91 ;
V_87 = F_42 ( V_85 , V_86 , V_84 , V_92 ) ;
if ( V_87 < 0 )
return V_87 ;
F_43 ( V_34 ) ;
if ( V_85 [ V_93 ] )
V_34 -> V_72 = F_44 ( V_85 [ V_93 ] ) ;
if ( V_85 [ V_94 ] )
V_89 = F_44 ( V_85 [ V_94 ] ) ;
if ( V_85 [ V_95 ] )
V_90 = F_44 ( V_85 [ V_95 ] ) ;
V_88 = ( T_3 ) V_89 * V_90 ;
if ( V_88 > V_96 )
return - V_91 ;
V_3 -> V_71 = V_89 ;
V_3 -> V_68 = V_90 ;
if ( V_85 [ V_97 ] )
V_3 -> V_29 = F_44 ( V_85 [ V_97 ] ) ;
if ( V_85 [ V_98 ] ) {
T_1 V_99 = F_44 ( V_85 [ V_98 ] ) ;
V_3 -> V_44 = F_45 ( V_99 ) ;
}
if ( V_85 [ V_100 ] )
V_3 -> V_53 = F_44 ( V_85 [ V_100 ] ) ;
if ( V_85 [ V_101 ] ) {
T_1 V_99 = F_44 ( V_85 [ V_101 ] ) ;
V_3 -> V_25 = F_45 ( V_99 ) ;
}
V_60 = V_34 -> V_3 . V_60 ;
while ( V_34 -> V_3 . V_60 > V_34 -> V_72 ) {
struct V_4 * V_5 = F_29 ( V_34 ) ;
F_26 ( V_5 ) ;
}
F_28 ( V_34 , V_60 - V_34 -> V_3 . V_60 ) ;
F_46 ( V_34 ) ;
return 0 ;
}
static int F_47 ( struct V_33 * V_34 , struct V_83 * V_84 )
{
struct V_2 * V_3 = F_18 ( V_34 ) ;
int V_42 ;
V_34 -> V_72 = 1000 ;
V_3 -> V_71 = F_48 ( F_49 ( V_34 ) ) ;
V_3 -> V_16 = F_50 () ;
F_15 ( & V_3 -> V_69 ) ;
F_15 ( & V_3 -> V_67 ) ;
V_3 -> V_44 = V_102 / 25 ;
V_3 -> V_53 = 131072 ;
V_3 -> V_25 = V_102 ;
V_3 -> V_68 = 2 ;
if ( V_84 ) {
int V_87 = F_41 ( V_34 , V_84 ) ;
if ( V_87 )
return V_87 ;
}
if ( ! V_3 -> V_48 ) {
V_3 -> V_48 = F_35 ( V_82 *
sizeof( struct V_18 ) ) ;
if ( ! V_3 -> V_48 )
return - V_103 ;
for ( V_42 = 0 ; V_42 < V_82 ; V_42 ++ )
F_15 ( & V_3 -> V_48 [ V_42 ] ) ;
V_3 -> V_29 = 2 * V_82 ;
V_3 -> V_30 = 0 ;
V_3 -> V_55 = 0 ;
V_3 -> V_27 = 0 ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ ) {
V_3 -> V_52 [ V_42 ] = F_35 ( V_46 *
sizeof( T_1 ) ) ;
if ( ! V_3 -> V_52 [ V_42 ] ) {
F_40 ( V_34 ) ;
return - V_103 ;
}
}
V_3 -> V_43 = F_1 () ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ ) {
V_3 -> V_45 [ V_42 ] = F_35 ( V_46 /
V_104 ) ;
if ( ! V_3 -> V_45 [ V_42 ] ) {
F_40 ( V_34 ) ;
return - V_103 ;
}
}
for ( V_42 = 0 ; V_42 < V_105 ; V_42 ++ ) {
struct V_56 * V_57 = V_3 -> V_59 + V_42 ;
F_15 ( & V_57 -> V_65 ) ;
}
}
return 0 ;
}
static int F_51 ( struct V_33 * V_34 , struct V_4 * V_5 )
{
struct V_2 * V_3 = F_18 ( V_34 ) ;
struct V_83 * V_106 ;
V_106 = F_52 ( V_5 , V_107 ) ;
if ( V_106 == NULL )
goto V_108;
if ( F_53 ( V_5 , V_93 , V_34 -> V_72 ) ||
F_53 ( V_5 , V_94 , V_3 -> V_71 ) ||
F_53 ( V_5 , V_97 , V_3 -> V_29 ) ||
F_53 ( V_5 , V_98 ,
F_54 ( V_3 -> V_44 ) ) ||
F_53 ( V_5 , V_100 , V_3 -> V_53 ) ||
F_53 ( V_5 , V_101 ,
F_54 ( V_3 -> V_25 ) ) ||
F_53 ( V_5 , V_95 , V_3 -> V_68 ) )
goto V_108;
F_55 ( V_5 , V_106 ) ;
return V_5 -> V_109 ;
V_108:
return - 1 ;
}
static int F_56 ( struct V_33 * V_34 , struct V_110 * V_111 )
{
struct V_2 * V_3 = F_18 ( V_34 ) ;
struct V_112 V_113 = {
. V_74 = V_3 -> V_74 ,
. V_114 = V_3 -> V_30 ,
. V_115 = V_3 -> V_55 ,
. V_116 = V_3 -> V_27 ,
} ;
return F_57 ( V_111 , & V_113 , sizeof( V_113 ) ) ;
}
static int T_4 F_58 ( void )
{
return F_59 ( & V_117 ) ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_117 ) ;
}
