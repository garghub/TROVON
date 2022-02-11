static T_1 F_1 ( void )
{
return V_1 ;
}
static struct V_2 * F_2 ( const T_1 V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_2 * V_8 , * V_9 ;
T_1 V_10 = F_1 () ;
if ( F_3 ( V_5 ) )
return NULL ;
F_4 (flow, next, head, flowchain) {
T_1 V_11 = V_8 -> V_12 + V_7 -> V_13 ;
if ( F_5 ( V_11 , V_10 ) ) {
if ( F_6 ( & V_8 -> V_14 , V_5 ) )
return NULL ;
F_7 ( & V_8 -> V_14 ) ;
F_8 ( V_8 ) ;
V_7 -> V_15 -- ;
} else if ( V_8 -> V_16 == V_3 ) {
return V_8 ;
}
}
return NULL ;
}
static struct V_2 * F_9 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_2 * V_8 ;
T_1 V_10 = F_1 () ;
if ( ! F_3 ( V_5 ) ) {
F_10 (flow, head, flowchain) {
T_1 V_11 = V_8 -> V_12 + V_7 -> V_13 ;
if ( F_5 ( V_11 , V_10 ) )
return V_8 ;
}
}
if ( V_7 -> V_15 >= V_7 -> V_17 ) {
V_7 -> V_18 ++ ;
return NULL ;
}
V_8 = F_11 ( sizeof( struct V_2 ) , V_19 ) ;
if ( ! V_8 )
return NULL ;
V_7 -> V_15 ++ ;
F_12 ( & V_8 -> V_14 ) ;
F_13 ( & V_8 -> V_14 , V_5 ) ;
return V_8 ;
}
static enum V_20 F_14 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
T_1 V_25 , V_3 ;
T_1 V_26 , V_27 [ V_28 ] , V_29 ;
struct V_2 * V_8 ;
T_1 V_30 , V_31 ;
int V_32 ;
T_1 V_11 ;
T_1 V_10 = F_1 () ;
V_11 = V_7 -> V_33 + V_7 -> V_34 ;
if ( F_5 ( V_11 , V_10 ) ) {
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ )
F_16 ( V_7 -> V_35 [ V_32 ] , V_36 ) ;
V_7 -> V_33 = V_10 ;
}
V_3 = F_17 ( V_22 , V_7 -> V_37 ) ;
V_29 = V_3 & V_38 ;
V_8 = F_2 ( V_3 , & V_7 -> V_39 [ V_29 ] , V_7 ) ;
if ( V_8 ) {
V_8 -> V_12 = V_10 ;
return V_40 ;
}
V_25 = V_3 ;
V_26 = 0 ;
for ( V_32 = 0 ; V_32 < V_28 - 1 ; V_32 ++ ) {
V_27 [ V_32 ] = V_25 & V_38 ;
V_26 ^= V_27 [ V_32 ] ;
V_25 >>= V_41 ;
}
V_27 [ V_28 - 1 ] = V_26 ^ V_25 ;
V_30 = F_18 ( V_22 ) ;
V_31 = ~ 0U ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ ) {
T_1 V_42 ;
if ( ! F_19 ( V_27 [ V_32 ] , V_7 -> V_35 [ V_32 ] ) ) {
V_7 -> V_43 [ V_32 ] [ V_27 [ V_32 ] ] = 0 ;
F_20 ( V_27 [ V_32 ] , V_7 -> V_35 [ V_32 ] ) ;
}
V_42 = V_7 -> V_43 [ V_32 ] [ V_27 [ V_32 ] ] + V_30 ;
if ( V_31 > V_42 )
V_31 = V_42 ;
}
if ( V_31 > V_7 -> V_44 ) {
V_8 = F_9 ( & V_7 -> V_39 [ V_29 ] , V_7 ) ;
if ( ! V_8 )
return V_45 ;
V_8 -> V_16 = V_3 ;
V_8 -> V_12 = V_10 ;
V_7 -> V_46 ++ ;
return V_40 ;
}
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ ) {
if ( V_7 -> V_43 [ V_32 ] [ V_27 [ V_32 ] ] < V_31 )
V_7 -> V_43 [ V_32 ] [ V_27 [ V_32 ] ] = V_31 ;
}
return V_45 ;
}
static struct V_21 * F_21 ( struct V_47 * V_48 )
{
struct V_21 * V_22 = V_48 -> V_5 ;
V_48 -> V_5 = V_22 -> V_9 ;
V_22 -> V_9 = NULL ;
return V_22 ;
}
static void F_22 ( struct V_47 * V_48 , struct V_21 * V_22 )
{
if ( V_48 -> V_5 == NULL )
V_48 -> V_5 = V_22 ;
else
V_48 -> V_49 -> V_9 = V_22 ;
V_48 -> V_49 = V_22 ;
V_22 -> V_9 = NULL ;
}
static unsigned int F_23 ( struct V_23 * V_24 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_47 * V_48 ;
V_48 = & V_7 -> V_50 [ V_40 ] ;
if ( ! V_48 -> V_5 )
V_48 = & V_7 -> V_50 [ V_45 ] ;
if ( V_48 -> V_5 ) {
struct V_21 * V_22 = F_21 ( V_48 ) ;
V_24 -> V_7 . V_51 -- ;
F_24 ( V_24 ) ;
F_25 ( V_24 , V_22 ) ;
F_26 ( V_22 ) ;
}
return V_48 - V_7 -> V_50 ;
}
static int F_27 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
enum V_20 V_52 ;
struct V_47 * V_48 ;
V_52 = F_14 ( V_22 , V_24 ) ;
V_48 = & V_7 -> V_50 [ V_52 ] ;
F_22 ( V_48 , V_22 ) ;
F_28 ( V_24 , V_22 ) ;
if ( F_3 ( & V_48 -> V_53 ) ) {
unsigned int V_54 ;
if ( V_52 == V_40 ) {
V_54 = 1 ;
F_13 ( & V_48 -> V_53 , & V_7 -> V_55 ) ;
} else {
V_54 = V_7 -> V_56 ;
F_13 ( & V_48 -> V_53 , & V_7 -> V_57 ) ;
}
V_48 -> V_58 = V_54 * V_7 -> V_59 ;
}
if ( ++ V_24 -> V_7 . V_51 <= V_24 -> V_60 )
return V_61 ;
V_7 -> V_62 ++ ;
if ( F_23 ( V_24 ) == V_52 )
return V_63 ;
F_29 ( V_24 , 1 ) ;
return V_61 ;
}
static struct V_21 * F_30 ( struct V_23 * V_24 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_21 * V_22 = NULL ;
struct V_47 * V_48 ;
struct V_4 * V_5 ;
V_64:
V_5 = & V_7 -> V_57 ;
if ( F_3 ( V_5 ) ) {
V_5 = & V_7 -> V_55 ;
if ( F_3 ( V_5 ) )
return NULL ;
}
V_48 = F_31 ( V_5 , struct V_47 , V_53 ) ;
if ( V_48 -> V_58 <= 0 ) {
int V_54 = ( V_48 - V_7 -> V_50 == V_40 ) ?
1 : V_7 -> V_56 ;
V_48 -> V_58 += V_54 * V_7 -> V_59 ;
F_32 ( & V_48 -> V_53 , & V_7 -> V_55 ) ;
goto V_64;
}
if ( V_48 -> V_5 ) {
V_22 = F_21 ( V_48 ) ;
V_24 -> V_7 . V_51 -- ;
F_25 ( V_24 , V_22 ) ;
}
if ( ! V_22 ) {
if ( ( V_5 == & V_7 -> V_57 ) && ! F_3 ( & V_7 -> V_55 ) )
F_32 ( & V_48 -> V_53 , & V_7 -> V_55 ) ;
else
F_33 ( & V_48 -> V_53 ) ;
goto V_64;
}
F_34 ( V_24 , V_22 ) ;
V_48 -> V_58 -= F_18 ( V_22 ) ;
return V_22 ;
}
static void F_35 ( struct V_23 * V_24 )
{
struct V_21 * V_22 ;
while ( ( V_22 = F_30 ( V_24 ) ) != NULL )
F_26 ( V_22 ) ;
}
static void * F_36 ( T_2 V_65 )
{
void * V_66 = F_11 ( V_65 , V_67 | V_68 ) ;
if ( ! V_66 )
V_66 = F_37 ( V_65 ) ;
return V_66 ;
}
static void F_38 ( void * V_69 )
{
F_39 ( V_69 ) ;
}
static void F_40 ( struct V_23 * V_24 )
{
int V_32 ;
struct V_6 * V_7 = F_15 ( V_24 ) ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ ) {
F_38 ( V_7 -> V_43 [ V_32 ] ) ;
F_38 ( V_7 -> V_35 [ V_32 ] ) ;
}
for ( V_32 = 0 ; V_32 < V_70 ; V_32 ++ ) {
struct V_2 * V_8 , * V_9 ;
struct V_4 * V_5 = & V_7 -> V_39 [ V_32 ] ;
if ( F_3 ( V_5 ) )
continue;
F_4 (flow, next, head, flowchain) {
F_7 ( & V_8 -> V_14 ) ;
F_8 ( V_8 ) ;
}
}
F_38 ( V_7 -> V_39 ) ;
}
static int F_41 ( struct V_23 * V_24 , struct V_71 * V_72 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_71 * V_73 [ V_74 + 1 ] ;
unsigned int V_51 ;
int V_75 ;
T_3 V_76 ;
T_1 V_77 = V_7 -> V_59 ;
T_1 V_78 = V_7 -> V_56 ;
if ( ! V_72 )
return - V_79 ;
V_75 = F_42 ( V_73 , V_74 , V_72 , V_80 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( V_73 [ V_81 ] )
V_77 = F_43 ( V_73 [ V_81 ] ) ;
if ( V_73 [ V_82 ] )
V_78 = F_43 ( V_73 [ V_82 ] ) ;
V_76 = ( T_3 ) V_77 * V_78 ;
if ( V_76 > V_83 )
return - V_79 ;
F_44 ( V_24 ) ;
if ( V_73 [ V_84 ] )
V_24 -> V_60 = F_43 ( V_73 [ V_84 ] ) ;
V_7 -> V_59 = V_77 ;
V_7 -> V_56 = V_78 ;
if ( V_73 [ V_85 ] )
V_7 -> V_17 = F_43 ( V_73 [ V_85 ] ) ;
if ( V_73 [ V_86 ] ) {
T_1 V_87 = F_43 ( V_73 [ V_86 ] ) ;
V_7 -> V_34 = F_45 ( V_87 ) ;
}
if ( V_73 [ V_88 ] )
V_7 -> V_44 = F_43 ( V_73 [ V_88 ] ) ;
if ( V_73 [ V_89 ] ) {
T_1 V_87 = F_43 ( V_73 [ V_89 ] ) ;
V_7 -> V_13 = F_45 ( V_87 ) ;
}
V_51 = V_24 -> V_7 . V_51 ;
while ( V_24 -> V_7 . V_51 > V_24 -> V_60 ) {
struct V_21 * V_22 = F_30 ( V_24 ) ;
F_26 ( V_22 ) ;
}
F_29 ( V_24 , V_51 - V_24 -> V_7 . V_51 ) ;
F_46 ( V_24 ) ;
return 0 ;
}
static int F_47 ( struct V_23 * V_24 , struct V_71 * V_72 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
int V_32 ;
V_24 -> V_60 = 1000 ;
V_7 -> V_59 = F_48 ( F_49 ( V_24 ) ) ;
V_7 -> V_37 = F_50 () ;
F_12 ( & V_7 -> V_57 ) ;
F_12 ( & V_7 -> V_55 ) ;
V_7 -> V_34 = V_90 / 25 ;
V_7 -> V_44 = 131072 ;
V_7 -> V_13 = V_90 ;
V_7 -> V_56 = 2 ;
if ( V_72 ) {
int V_75 = F_41 ( V_24 , V_72 ) ;
if ( V_75 )
return V_75 ;
}
if ( ! V_7 -> V_39 ) {
V_7 -> V_39 = F_36 ( V_70 *
sizeof( struct V_4 ) ) ;
if ( ! V_7 -> V_39 )
return - V_91 ;
for ( V_32 = 0 ; V_32 < V_70 ; V_32 ++ )
F_12 ( & V_7 -> V_39 [ V_32 ] ) ;
V_7 -> V_17 = 2 * V_70 ;
V_7 -> V_18 = 0 ;
V_7 -> V_46 = 0 ;
V_7 -> V_15 = 0 ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ ) {
V_7 -> V_43 [ V_32 ] = F_36 ( V_36 *
sizeof( T_1 ) ) ;
if ( ! V_7 -> V_43 [ V_32 ] ) {
F_40 ( V_24 ) ;
return - V_91 ;
}
}
V_7 -> V_33 = F_1 () ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ ) {
V_7 -> V_35 [ V_32 ] = F_36 ( V_36 /
V_92 ) ;
if ( ! V_7 -> V_35 [ V_32 ] ) {
F_40 ( V_24 ) ;
return - V_91 ;
}
}
for ( V_32 = 0 ; V_32 < V_93 ; V_32 ++ ) {
struct V_47 * V_48 = V_7 -> V_50 + V_32 ;
F_12 ( & V_48 -> V_53 ) ;
}
}
return 0 ;
}
static int F_51 ( struct V_23 * V_24 , struct V_21 * V_22 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_71 * V_94 ;
V_94 = F_52 ( V_22 , V_95 ) ;
if ( V_94 == NULL )
goto V_96;
if ( F_53 ( V_22 , V_84 , V_24 -> V_60 ) ||
F_53 ( V_22 , V_81 , V_7 -> V_59 ) ||
F_53 ( V_22 , V_85 , V_7 -> V_17 ) ||
F_53 ( V_22 , V_86 ,
F_54 ( V_7 -> V_34 ) ) ||
F_53 ( V_22 , V_88 , V_7 -> V_44 ) ||
F_53 ( V_22 , V_89 ,
F_54 ( V_7 -> V_13 ) ) ||
F_53 ( V_22 , V_82 , V_7 -> V_56 ) )
goto V_96;
return F_55 ( V_22 , V_94 ) ;
V_96:
return - 1 ;
}
static int F_56 ( struct V_23 * V_24 , struct V_97 * V_98 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_99 V_100 = {
. V_62 = V_7 -> V_62 ,
. V_101 = V_7 -> V_18 ,
. V_102 = V_7 -> V_46 ,
. V_103 = V_7 -> V_15 ,
} ;
return F_57 ( V_98 , & V_100 , sizeof( V_100 ) ) ;
}
static int T_4 F_58 ( void )
{
return F_59 ( & V_104 ) ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_104 ) ;
}
