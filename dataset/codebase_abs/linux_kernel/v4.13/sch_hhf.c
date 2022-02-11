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
static unsigned int F_23 ( struct V_23 * V_24 , struct V_21 * * V_50 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_47 * V_48 ;
V_48 = & V_7 -> V_51 [ V_40 ] ;
if ( ! V_48 -> V_5 )
V_48 = & V_7 -> V_51 [ V_45 ] ;
if ( V_48 -> V_5 ) {
struct V_21 * V_22 = F_21 ( V_48 ) ;
V_24 -> V_7 . V_52 -- ;
F_24 ( V_24 , V_22 ) ;
F_25 ( V_22 , V_24 , V_50 ) ;
}
return V_48 - V_7 -> V_51 ;
}
static int F_26 ( struct V_21 * V_22 , struct V_23 * V_24 ,
struct V_21 * * V_50 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
enum V_20 V_53 ;
struct V_47 * V_48 ;
unsigned int V_54 ;
V_53 = F_14 ( V_22 , V_24 ) ;
V_48 = & V_7 -> V_51 [ V_53 ] ;
F_22 ( V_48 , V_22 ) ;
F_27 ( V_24 , V_22 ) ;
if ( F_3 ( & V_48 -> V_55 ) ) {
unsigned int V_56 ;
if ( V_53 == V_40 ) {
V_56 = 1 ;
F_13 ( & V_48 -> V_55 , & V_7 -> V_57 ) ;
} else {
V_56 = V_7 -> V_58 ;
F_13 ( & V_48 -> V_55 , & V_7 -> V_59 ) ;
}
V_48 -> V_60 = V_56 * V_7 -> V_61 ;
}
if ( ++ V_24 -> V_7 . V_52 <= V_24 -> V_62 )
return V_63 ;
V_54 = V_24 -> V_64 . V_65 ;
V_7 -> V_66 ++ ;
if ( F_23 ( V_24 , V_50 ) == V_53 )
return V_67 ;
F_28 ( V_24 , 1 , V_54 - V_24 -> V_64 . V_65 ) ;
return V_63 ;
}
static struct V_21 * F_29 ( struct V_23 * V_24 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_21 * V_22 = NULL ;
struct V_47 * V_48 ;
struct V_4 * V_5 ;
V_68:
V_5 = & V_7 -> V_59 ;
if ( F_3 ( V_5 ) ) {
V_5 = & V_7 -> V_57 ;
if ( F_3 ( V_5 ) )
return NULL ;
}
V_48 = F_30 ( V_5 , struct V_47 , V_55 ) ;
if ( V_48 -> V_60 <= 0 ) {
int V_56 = ( V_48 - V_7 -> V_51 == V_40 ) ?
1 : V_7 -> V_58 ;
V_48 -> V_60 += V_56 * V_7 -> V_61 ;
F_31 ( & V_48 -> V_55 , & V_7 -> V_57 ) ;
goto V_68;
}
if ( V_48 -> V_5 ) {
V_22 = F_21 ( V_48 ) ;
V_24 -> V_7 . V_52 -- ;
F_24 ( V_24 , V_22 ) ;
}
if ( ! V_22 ) {
if ( ( V_5 == & V_7 -> V_59 ) && ! F_3 ( & V_7 -> V_57 ) )
F_31 ( & V_48 -> V_55 , & V_7 -> V_57 ) ;
else
F_32 ( & V_48 -> V_55 ) ;
goto V_68;
}
F_33 ( V_24 , V_22 ) ;
V_48 -> V_60 -= F_18 ( V_22 ) ;
return V_22 ;
}
static void F_34 ( struct V_23 * V_24 )
{
struct V_21 * V_22 ;
while ( ( V_22 = F_29 ( V_24 ) ) != NULL )
F_35 ( V_22 , V_22 ) ;
}
static void F_36 ( struct V_23 * V_24 )
{
int V_32 ;
struct V_6 * V_7 = F_15 ( V_24 ) ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ ) {
F_37 ( V_7 -> V_43 [ V_32 ] ) ;
F_37 ( V_7 -> V_35 [ V_32 ] ) ;
}
if ( ! V_7 -> V_39 )
return;
for ( V_32 = 0 ; V_32 < V_69 ; V_32 ++ ) {
struct V_2 * V_8 , * V_9 ;
struct V_4 * V_5 = & V_7 -> V_39 [ V_32 ] ;
if ( F_3 ( V_5 ) )
continue;
F_4 (flow, next, head, flowchain) {
F_7 ( & V_8 -> V_14 ) ;
F_8 ( V_8 ) ;
}
}
F_37 ( V_7 -> V_39 ) ;
}
static int F_38 ( struct V_23 * V_24 , struct V_70 * V_71 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_70 * V_72 [ V_73 + 1 ] ;
unsigned int V_52 , V_54 ;
int V_74 ;
T_2 V_75 ;
T_1 V_76 = V_7 -> V_61 ;
T_1 V_77 = V_7 -> V_58 ;
if ( ! V_71 )
return - V_78 ;
V_74 = F_39 ( V_72 , V_73 , V_71 , V_79 , NULL ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_72 [ V_80 ] )
V_76 = F_40 ( V_72 [ V_80 ] ) ;
if ( V_72 [ V_81 ] )
V_77 = F_40 ( V_72 [ V_81 ] ) ;
V_75 = ( T_2 ) V_76 * V_77 ;
if ( V_75 > V_82 )
return - V_78 ;
F_41 ( V_24 ) ;
if ( V_72 [ V_83 ] )
V_24 -> V_62 = F_40 ( V_72 [ V_83 ] ) ;
V_7 -> V_61 = V_76 ;
V_7 -> V_58 = V_77 ;
if ( V_72 [ V_84 ] )
V_7 -> V_17 = F_40 ( V_72 [ V_84 ] ) ;
if ( V_72 [ V_85 ] ) {
T_1 V_86 = F_40 ( V_72 [ V_85 ] ) ;
V_7 -> V_34 = F_42 ( V_86 ) ;
}
if ( V_72 [ V_87 ] )
V_7 -> V_44 = F_40 ( V_72 [ V_87 ] ) ;
if ( V_72 [ V_88 ] ) {
T_1 V_86 = F_40 ( V_72 [ V_88 ] ) ;
V_7 -> V_13 = F_42 ( V_86 ) ;
}
V_52 = V_24 -> V_7 . V_52 ;
V_54 = V_24 -> V_64 . V_65 ;
while ( V_24 -> V_7 . V_52 > V_24 -> V_62 ) {
struct V_21 * V_22 = F_29 ( V_24 ) ;
F_35 ( V_22 , V_22 ) ;
}
F_28 ( V_24 , V_52 - V_24 -> V_7 . V_52 ,
V_54 - V_24 -> V_64 . V_65 ) ;
F_43 ( V_24 ) ;
return 0 ;
}
static int F_44 ( struct V_23 * V_24 , struct V_70 * V_71 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
int V_32 ;
V_24 -> V_62 = 1000 ;
V_7 -> V_61 = F_45 ( F_46 ( V_24 ) ) ;
V_7 -> V_37 = F_47 () ;
F_12 ( & V_7 -> V_59 ) ;
F_12 ( & V_7 -> V_57 ) ;
V_7 -> V_34 = V_89 / 25 ;
V_7 -> V_44 = 131072 ;
V_7 -> V_13 = V_89 ;
V_7 -> V_58 = 2 ;
if ( V_71 ) {
int V_74 = F_38 ( V_24 , V_71 ) ;
if ( V_74 )
return V_74 ;
}
if ( ! V_7 -> V_39 ) {
V_7 -> V_39 = F_48 ( V_69 *
sizeof( struct V_4 ) , V_90 ) ;
if ( ! V_7 -> V_39 )
return - V_91 ;
for ( V_32 = 0 ; V_32 < V_69 ; V_32 ++ )
F_12 ( & V_7 -> V_39 [ V_32 ] ) ;
V_7 -> V_17 = 2 * V_69 ;
V_7 -> V_18 = 0 ;
V_7 -> V_46 = 0 ;
V_7 -> V_15 = 0 ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ ) {
V_7 -> V_43 [ V_32 ] = F_48 ( V_36 *
sizeof( T_1 ) , V_90 ) ;
if ( ! V_7 -> V_43 [ V_32 ] ) {
return - V_91 ;
}
}
V_7 -> V_33 = F_1 () ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ ) {
V_7 -> V_35 [ V_32 ] = F_48 ( V_36 /
V_92 , V_90 ) ;
if ( ! V_7 -> V_35 [ V_32 ] ) {
return - V_91 ;
}
}
for ( V_32 = 0 ; V_32 < V_93 ; V_32 ++ ) {
struct V_47 * V_48 = V_7 -> V_51 + V_32 ;
F_12 ( & V_48 -> V_55 ) ;
}
}
return 0 ;
}
static int F_49 ( struct V_23 * V_24 , struct V_21 * V_22 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_70 * V_94 ;
V_94 = F_50 ( V_22 , V_95 ) ;
if ( V_94 == NULL )
goto V_96;
if ( F_51 ( V_22 , V_83 , V_24 -> V_62 ) ||
F_51 ( V_22 , V_80 , V_7 -> V_61 ) ||
F_51 ( V_22 , V_84 , V_7 -> V_17 ) ||
F_51 ( V_22 , V_85 ,
F_52 ( V_7 -> V_34 ) ) ||
F_51 ( V_22 , V_87 , V_7 -> V_44 ) ||
F_51 ( V_22 , V_88 ,
F_52 ( V_7 -> V_13 ) ) ||
F_51 ( V_22 , V_81 , V_7 -> V_58 ) )
goto V_96;
return F_53 ( V_22 , V_94 ) ;
V_96:
return - 1 ;
}
static int F_54 ( struct V_23 * V_24 , struct V_97 * V_98 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_99 V_100 = {
. V_66 = V_7 -> V_66 ,
. V_101 = V_7 -> V_18 ,
. V_102 = V_7 -> V_46 ,
. V_103 = V_7 -> V_15 ,
} ;
return F_55 ( V_98 , & V_100 , sizeof( V_100 ) ) ;
}
static int T_3 F_56 ( void )
{
return F_57 ( & V_104 ) ;
}
static void T_4 F_58 ( void )
{
F_59 ( & V_104 ) ;
}
