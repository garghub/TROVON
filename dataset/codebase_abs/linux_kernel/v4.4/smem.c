static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
void * V_4 = V_3 ;
return V_4 + F_2 ( V_3 -> V_5 ) ;
}
static void * F_3 ( struct V_2 * V_3 )
{
void * V_4 = V_3 ;
return V_4 + F_2 ( V_3 -> V_6 ) ;
}
static struct V_1 *
F_4 ( struct V_2 * V_3 )
{
void * V_4 = V_3 ;
return V_4 + sizeof( * V_3 ) ;
}
static struct V_1 *
F_5 ( struct V_1 * V_7 )
{
void * V_4 = V_7 ;
return V_4 + sizeof( * V_7 ) + F_6 ( V_7 -> V_8 ) +
F_2 ( V_7 -> V_9 ) ;
}
static void * F_7 ( struct V_1 * V_7 )
{
void * V_4 = V_7 ;
return V_4 + sizeof( * V_7 ) + F_6 ( V_7 -> V_8 ) ;
}
static int F_8 ( struct V_10 * V_11 ,
unsigned V_12 ,
unsigned V_13 ,
T_1 V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_14 , * V_15 ;
T_1 V_16 ;
void * V_17 ;
V_3 = V_11 -> V_18 [ V_12 ] ;
V_14 = F_4 ( V_3 ) ;
V_15 = F_1 ( V_3 ) ;
V_17 = F_3 ( V_3 ) ;
while ( V_14 < V_15 ) {
if ( V_14 -> V_19 != V_20 ) {
F_9 ( V_11 -> V_21 ,
L_1 ,
V_12 ) ;
return - V_22 ;
}
if ( F_6 ( V_14 -> V_13 ) == V_13 )
return - V_23 ;
V_14 = F_5 ( V_14 ) ;
}
V_16 = sizeof( * V_14 ) + F_10 ( V_9 , 8 ) ;
if ( ( void * ) V_14 + V_16 >= V_17 ) {
F_9 ( V_11 -> V_21 , L_2 ) ;
return - V_24 ;
}
V_14 -> V_19 = V_20 ;
V_14 -> V_13 = F_11 ( V_13 ) ;
V_14 -> V_9 = F_12 ( F_10 ( V_9 , 8 ) ) ;
V_14 -> V_25 = F_11 ( F_2 ( V_14 -> V_9 ) - V_9 ) ;
V_14 -> V_8 = 0 ;
F_13 () ;
F_14 ( & V_3 -> V_5 , V_16 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
unsigned V_13 ,
T_1 V_9 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
if ( F_16 ( V_13 >= V_30 ) )
return - V_22 ;
V_27 = V_11 -> V_31 [ 0 ] . V_32 ;
V_29 = & V_27 -> V_33 [ V_13 ] ;
if ( V_29 -> V_34 )
return - V_23 ;
V_9 = F_10 ( V_9 , 8 ) ;
if ( F_16 ( V_9 > F_2 ( V_27 -> V_35 ) ) )
return - V_36 ;
V_29 -> V_37 = V_27 -> V_38 ;
V_29 -> V_9 = F_12 ( V_9 ) ;
F_13 () ;
V_29 -> V_34 = F_12 ( 1 ) ;
F_14 ( & V_27 -> V_38 , V_9 ) ;
F_14 ( & V_27 -> V_35 , - V_9 ) ;
return 0 ;
}
int F_17 ( unsigned V_12 , unsigned V_13 , T_1 V_9 )
{
unsigned long V_39 ;
int V_40 ;
if ( ! V_41 )
return - V_42 ;
if ( V_13 < V_43 ) {
F_9 ( V_41 -> V_21 ,
L_3 , V_13 ) ;
return - V_22 ;
}
V_40 = F_18 ( V_41 -> V_44 ,
V_45 ,
& V_39 ) ;
if ( V_40 )
return V_40 ;
if ( V_12 < V_46 && V_41 -> V_18 [ V_12 ] )
V_40 = F_8 ( V_41 , V_12 , V_13 , V_9 ) ;
else
V_40 = F_15 ( V_41 , V_13 , V_9 ) ;
F_19 ( V_41 -> V_44 , & V_39 ) ;
return V_40 ;
}
static void * F_20 ( struct V_10 * V_11 ,
unsigned V_13 ,
T_1 * V_9 )
{
struct V_26 * V_27 ;
struct V_47 * V_48 ;
struct V_28 * V_29 ;
T_2 V_49 ;
unsigned V_50 ;
if ( F_16 ( V_13 >= V_30 ) )
return F_21 ( - V_22 ) ;
V_27 = V_11 -> V_31 [ 0 ] . V_32 ;
V_29 = & V_27 -> V_33 [ V_13 ] ;
if ( ! V_29 -> V_34 )
return F_21 ( - V_51 ) ;
V_49 = F_2 ( V_29 -> V_49 ) & V_52 ;
for ( V_50 = 0 ; V_50 < V_11 -> V_53 ; V_50 ++ ) {
V_48 = & V_11 -> V_31 [ V_50 ] ;
if ( V_48 -> V_49 == V_49 || ! V_49 ) {
if ( V_9 != NULL )
* V_9 = F_2 ( V_29 -> V_9 ) ;
return V_48 -> V_32 + F_2 ( V_29 -> V_37 ) ;
}
}
return F_21 ( - V_54 ) ;
}
static void * F_22 ( struct V_10 * V_11 ,
unsigned V_12 ,
unsigned V_13 ,
T_1 * V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 , * V_15 ;
V_3 = V_11 -> V_18 [ V_12 ] ;
V_7 = F_4 ( V_3 ) ;
V_15 = F_1 ( V_3 ) ;
while ( V_7 < V_15 ) {
if ( V_7 -> V_19 != V_20 ) {
F_9 ( V_11 -> V_21 ,
L_1 ,
V_12 ) ;
return F_21 ( - V_22 ) ;
}
if ( F_6 ( V_7 -> V_13 ) == V_13 ) {
if ( V_9 != NULL )
* V_9 = F_2 ( V_7 -> V_9 ) -
F_6 ( V_7 -> V_25 ) ;
return F_7 ( V_7 ) ;
}
V_7 = F_5 ( V_7 ) ;
}
return F_21 ( - V_54 ) ;
}
void * F_23 ( unsigned V_12 , unsigned V_13 , T_1 * V_9 )
{
unsigned long V_39 ;
int V_40 ;
void * V_55 = F_21 ( - V_42 ) ;
if ( ! V_41 )
return V_55 ;
V_40 = F_18 ( V_41 -> V_44 ,
V_45 ,
& V_39 ) ;
if ( V_40 )
return F_21 ( V_40 ) ;
if ( V_12 < V_46 && V_41 -> V_18 [ V_12 ] )
V_55 = F_22 ( V_41 , V_12 , V_13 , V_9 ) ;
else
V_55 = F_20 ( V_41 , V_13 , V_9 ) ;
F_19 ( V_41 -> V_44 , & V_39 ) ;
return V_55 ;
}
int F_24 ( unsigned V_12 )
{
struct V_2 * V_3 ;
struct V_26 * V_27 ;
unsigned V_40 ;
if ( ! V_41 )
return - V_42 ;
if ( V_12 < V_46 && V_41 -> V_18 [ V_12 ] ) {
V_3 = V_41 -> V_18 [ V_12 ] ;
V_40 = F_2 ( V_3 -> V_6 ) -
F_2 ( V_3 -> V_5 ) ;
} else {
V_27 = V_41 -> V_31 [ 0 ] . V_32 ;
V_40 = F_2 ( V_27 -> V_35 ) ;
}
return V_40 ;
}
static int F_25 ( struct V_10 * V_11 )
{
T_3 * V_56 ;
T_1 V_9 ;
V_56 = F_20 ( V_11 , V_57 , & V_9 ) ;
if ( F_26 ( V_56 ) ) {
F_9 ( V_11 -> V_21 , L_4 ) ;
return - V_54 ;
}
if ( V_9 < sizeof( unsigned ) * V_58 ) {
F_9 ( V_11 -> V_21 , L_5 ) ;
return - V_22 ;
}
return F_2 ( V_56 [ V_58 ] ) ;
}
static int F_27 ( struct V_10 * V_11 ,
unsigned V_59 )
{
struct V_2 * V_27 ;
struct V_60 * V_29 ;
struct V_61 * V_62 ;
unsigned V_63 ;
T_2 V_64 , V_65 , V_66 ;
int V_50 ;
V_62 = V_11 -> V_31 [ 0 ] . V_32 + V_11 -> V_31 [ 0 ] . V_9 - V_67 ;
if ( memcmp ( V_62 -> V_68 , V_69 , sizeof( V_62 -> V_68 ) ) )
return 0 ;
V_64 = F_2 ( V_62 -> V_64 ) ;
if ( V_64 != 1 ) {
F_9 ( V_11 -> V_21 ,
L_6 , V_64 ) ;
return - V_22 ;
}
for ( V_50 = 0 ; V_50 < F_2 ( V_62 -> V_70 ) ; V_50 ++ ) {
V_29 = & V_62 -> V_29 [ V_50 ] ;
V_65 = F_6 ( V_29 -> V_65 ) ;
V_66 = F_6 ( V_29 -> V_66 ) ;
if ( V_65 != V_59 && V_66 != V_59 )
continue;
if ( ! F_2 ( V_29 -> V_37 ) )
continue;
if ( ! F_2 ( V_29 -> V_9 ) )
continue;
if ( V_65 == V_59 )
V_63 = V_66 ;
else
V_63 = V_65 ;
if ( V_63 >= V_46 ) {
F_9 ( V_11 -> V_21 ,
L_7 ,
V_63 ) ;
return - V_22 ;
}
if ( V_11 -> V_18 [ V_63 ] ) {
F_9 ( V_11 -> V_21 ,
L_8 ,
V_63 ) ;
return - V_22 ;
}
V_27 = V_11 -> V_31 [ 0 ] . V_32 + F_2 ( V_29 -> V_37 ) ;
V_65 = F_6 ( V_27 -> V_65 ) ;
V_66 = F_6 ( V_27 -> V_66 ) ;
if ( memcmp ( V_27 -> V_68 , V_71 ,
sizeof( V_27 -> V_68 ) ) ) {
F_9 ( V_11 -> V_21 ,
L_9 , V_50 ) ;
return - V_22 ;
}
if ( V_65 != V_59 && V_66 != V_59 ) {
F_9 ( V_11 -> V_21 ,
L_10 , V_50 ) ;
return - V_22 ;
}
if ( V_65 != V_63 && V_66 != V_63 ) {
F_9 ( V_11 -> V_21 ,
L_10 , V_50 ) ;
return - V_22 ;
}
if ( V_27 -> V_9 != V_29 -> V_9 ) {
F_9 ( V_11 -> V_21 ,
L_11 , V_50 ) ;
return - V_22 ;
}
if ( F_2 ( V_27 -> V_5 ) > F_2 ( V_27 -> V_9 ) ) {
F_9 ( V_11 -> V_21 ,
L_12 , V_50 ) ;
return - V_22 ;
}
V_11 -> V_18 [ V_63 ] = V_27 ;
}
return 0 ;
}
static int F_28 ( struct V_10 * V_11 , struct V_72 * V_21 ,
const char * V_73 , int V_50 )
{
struct V_74 * V_75 ;
struct V_76 V_77 ;
int V_40 ;
V_75 = F_29 ( V_21 -> V_78 , V_73 , 0 ) ;
if ( ! V_75 ) {
F_9 ( V_21 , L_13 , V_73 ) ;
return - V_22 ;
}
V_40 = F_30 ( V_75 , 0 , & V_77 ) ;
F_31 ( V_75 ) ;
if ( V_40 )
return V_40 ;
V_11 -> V_31 [ V_50 ] . V_49 = ( T_2 ) V_77 . V_79 ;
V_11 -> V_31 [ V_50 ] . V_9 = F_32 ( & V_77 ) ;
V_11 -> V_31 [ V_50 ] . V_32 = F_33 ( V_21 , V_77 . V_79 ,
F_32 ( & V_77 ) ) ;
if ( ! V_11 -> V_31 [ V_50 ] . V_32 )
return - V_36 ;
return 0 ;
}
static int F_34 ( struct V_80 * V_81 )
{
struct V_26 * V_27 ;
struct V_10 * V_11 ;
T_1 V_82 ;
int V_53 ;
int V_83 ;
T_2 V_64 ;
int V_40 ;
V_53 = 1 ;
if ( F_35 ( V_81 -> V_21 . V_78 , L_14 , NULL ) )
V_53 ++ ;
V_82 = V_53 * sizeof( struct V_47 ) ;
V_11 = F_36 ( & V_81 -> V_21 , sizeof( * V_11 ) + V_82 , V_84 ) ;
if ( ! V_11 )
return - V_36 ;
V_11 -> V_21 = & V_81 -> V_21 ;
V_11 -> V_53 = V_53 ;
V_40 = F_28 ( V_11 , & V_81 -> V_21 , L_15 , 0 ) ;
if ( V_40 )
return V_40 ;
if ( V_53 > 1 && ( V_40 = F_28 ( V_11 , & V_81 -> V_21 ,
L_14 , 1 ) ) )
return V_40 ;
V_27 = V_11 -> V_31 [ 0 ] . V_32 ;
if ( F_2 ( V_27 -> V_85 ) != 1 ||
F_2 ( V_27 -> V_86 ) ) {
F_9 ( & V_81 -> V_21 , L_16 ) ;
return - V_22 ;
}
V_64 = F_25 ( V_11 ) ;
if ( V_64 >> 16 != V_87 ) {
F_9 ( & V_81 -> V_21 , L_17 , V_64 ) ;
return - V_22 ;
}
V_40 = F_27 ( V_11 , V_88 ) ;
if ( V_40 < 0 )
return V_40 ;
V_83 = F_37 ( V_81 -> V_21 . V_78 , 0 ) ;
if ( V_83 < 0 ) {
F_9 ( & V_81 -> V_21 , L_18 ) ;
return V_83 ;
}
V_11 -> V_44 = F_38 ( V_83 ) ;
if ( ! V_11 -> V_44 )
return - V_51 ;
V_41 = V_11 ;
return 0 ;
}
static int F_39 ( struct V_80 * V_81 )
{
F_40 ( V_41 -> V_44 ) ;
V_41 = NULL ;
return 0 ;
}
static int T_4 F_41 ( void )
{
return F_42 ( & V_89 ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( & V_89 ) ;
}
