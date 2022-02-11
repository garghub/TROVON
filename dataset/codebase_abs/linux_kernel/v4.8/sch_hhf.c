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
static void * F_36 ( T_2 V_69 )
{
void * V_70 = F_11 ( V_69 , V_71 | V_72 ) ;
if ( ! V_70 )
V_70 = F_37 ( V_69 ) ;
return V_70 ;
}
static void F_38 ( void * V_73 )
{
F_39 ( V_73 ) ;
}
static void F_40 ( struct V_23 * V_24 )
{
int V_32 ;
struct V_6 * V_7 = F_15 ( V_24 ) ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ ) {
F_38 ( V_7 -> V_43 [ V_32 ] ) ;
F_38 ( V_7 -> V_35 [ V_32 ] ) ;
}
for ( V_32 = 0 ; V_32 < V_74 ; V_32 ++ ) {
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
static int F_41 ( struct V_23 * V_24 , struct V_75 * V_76 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_75 * V_77 [ V_78 + 1 ] ;
unsigned int V_52 , V_54 ;
int V_79 ;
T_3 V_80 ;
T_1 V_81 = V_7 -> V_61 ;
T_1 V_82 = V_7 -> V_58 ;
if ( ! V_76 )
return - V_83 ;
V_79 = F_42 ( V_77 , V_78 , V_76 , V_84 ) ;
if ( V_79 < 0 )
return V_79 ;
if ( V_77 [ V_85 ] )
V_81 = F_43 ( V_77 [ V_85 ] ) ;
if ( V_77 [ V_86 ] )
V_82 = F_43 ( V_77 [ V_86 ] ) ;
V_80 = ( T_3 ) V_81 * V_82 ;
if ( V_80 > V_87 )
return - V_83 ;
F_44 ( V_24 ) ;
if ( V_77 [ V_88 ] )
V_24 -> V_62 = F_43 ( V_77 [ V_88 ] ) ;
V_7 -> V_61 = V_81 ;
V_7 -> V_58 = V_82 ;
if ( V_77 [ V_89 ] )
V_7 -> V_17 = F_43 ( V_77 [ V_89 ] ) ;
if ( V_77 [ V_90 ] ) {
T_1 V_91 = F_43 ( V_77 [ V_90 ] ) ;
V_7 -> V_34 = F_45 ( V_91 ) ;
}
if ( V_77 [ V_92 ] )
V_7 -> V_44 = F_43 ( V_77 [ V_92 ] ) ;
if ( V_77 [ V_93 ] ) {
T_1 V_91 = F_43 ( V_77 [ V_93 ] ) ;
V_7 -> V_13 = F_45 ( V_91 ) ;
}
V_52 = V_24 -> V_7 . V_52 ;
V_54 = V_24 -> V_64 . V_65 ;
while ( V_24 -> V_7 . V_52 > V_24 -> V_62 ) {
struct V_21 * V_22 = F_29 ( V_24 ) ;
F_35 ( V_22 , V_22 ) ;
}
F_28 ( V_24 , V_52 - V_24 -> V_7 . V_52 ,
V_54 - V_24 -> V_64 . V_65 ) ;
F_46 ( V_24 ) ;
return 0 ;
}
static int F_47 ( struct V_23 * V_24 , struct V_75 * V_76 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
int V_32 ;
V_24 -> V_62 = 1000 ;
V_7 -> V_61 = F_48 ( F_49 ( V_24 ) ) ;
V_7 -> V_37 = F_50 () ;
F_12 ( & V_7 -> V_59 ) ;
F_12 ( & V_7 -> V_57 ) ;
V_7 -> V_34 = V_94 / 25 ;
V_7 -> V_44 = 131072 ;
V_7 -> V_13 = V_94 ;
V_7 -> V_58 = 2 ;
if ( V_76 ) {
int V_79 = F_41 ( V_24 , V_76 ) ;
if ( V_79 )
return V_79 ;
}
if ( ! V_7 -> V_39 ) {
V_7 -> V_39 = F_36 ( V_74 *
sizeof( struct V_4 ) ) ;
if ( ! V_7 -> V_39 )
return - V_95 ;
for ( V_32 = 0 ; V_32 < V_74 ; V_32 ++ )
F_12 ( & V_7 -> V_39 [ V_32 ] ) ;
V_7 -> V_17 = 2 * V_74 ;
V_7 -> V_18 = 0 ;
V_7 -> V_46 = 0 ;
V_7 -> V_15 = 0 ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ ) {
V_7 -> V_43 [ V_32 ] = F_36 ( V_36 *
sizeof( T_1 ) ) ;
if ( ! V_7 -> V_43 [ V_32 ] ) {
F_40 ( V_24 ) ;
return - V_95 ;
}
}
V_7 -> V_33 = F_1 () ;
for ( V_32 = 0 ; V_32 < V_28 ; V_32 ++ ) {
V_7 -> V_35 [ V_32 ] = F_36 ( V_36 /
V_96 ) ;
if ( ! V_7 -> V_35 [ V_32 ] ) {
F_40 ( V_24 ) ;
return - V_95 ;
}
}
for ( V_32 = 0 ; V_32 < V_97 ; V_32 ++ ) {
struct V_47 * V_48 = V_7 -> V_51 + V_32 ;
F_12 ( & V_48 -> V_55 ) ;
}
}
return 0 ;
}
static int F_51 ( struct V_23 * V_24 , struct V_21 * V_22 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_75 * V_98 ;
V_98 = F_52 ( V_22 , V_99 ) ;
if ( V_98 == NULL )
goto V_100;
if ( F_53 ( V_22 , V_88 , V_24 -> V_62 ) ||
F_53 ( V_22 , V_85 , V_7 -> V_61 ) ||
F_53 ( V_22 , V_89 , V_7 -> V_17 ) ||
F_53 ( V_22 , V_90 ,
F_54 ( V_7 -> V_34 ) ) ||
F_53 ( V_22 , V_92 , V_7 -> V_44 ) ||
F_53 ( V_22 , V_93 ,
F_54 ( V_7 -> V_13 ) ) ||
F_53 ( V_22 , V_86 , V_7 -> V_58 ) )
goto V_100;
return F_55 ( V_22 , V_98 ) ;
V_100:
return - 1 ;
}
static int F_56 ( struct V_23 * V_24 , struct V_101 * V_102 )
{
struct V_6 * V_7 = F_15 ( V_24 ) ;
struct V_103 V_104 = {
. V_66 = V_7 -> V_66 ,
. V_105 = V_7 -> V_18 ,
. V_106 = V_7 -> V_46 ,
. V_107 = V_7 -> V_15 ,
} ;
return F_57 ( V_102 , & V_104 , sizeof( V_104 ) ) ;
}
static int T_4 F_58 ( void )
{
return F_59 ( & V_108 ) ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_108 ) ;
}
