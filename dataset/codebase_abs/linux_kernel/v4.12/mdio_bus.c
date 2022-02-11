int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 [ V_2 -> V_5 ] )
return - V_6 ;
V_2 -> V_3 -> V_4 [ V_2 -> V_5 ] = V_2 ;
return 0 ;
}
int F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 [ V_2 -> V_5 ] != V_2 )
return - V_7 ;
V_2 -> V_3 -> V_4 [ V_2 -> V_5 ] = NULL ;
return 0 ;
}
struct V_8 * F_3 ( struct V_9 * V_3 , int V_5 )
{
struct V_1 * V_2 = V_3 -> V_4 [ V_5 ] ;
if ( ! V_2 )
return NULL ;
if ( ! ( V_2 -> V_10 & V_11 ) )
return NULL ;
return F_4 ( V_2 , struct V_8 , V_12 ) ;
}
bool F_5 ( struct V_9 * V_3 , int V_5 )
{
return V_3 -> V_4 [ V_5 ] ;
}
struct V_9 * F_6 ( T_1 V_13 )
{
struct V_9 * V_3 ;
T_1 V_14 = F_7 ( sizeof( * V_3 ) , V_15 ) ;
T_1 V_16 ;
int V_17 ;
if ( V_13 )
V_16 = V_14 + V_13 ;
else
V_16 = sizeof( * V_3 ) ;
V_3 = F_8 ( V_16 , V_18 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_19 = V_20 ;
if ( V_13 )
V_3 -> V_21 = ( void * ) V_3 + V_14 ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ )
V_3 -> V_23 [ V_17 ] = V_24 ;
return V_3 ;
}
static void F_9 ( struct V_25 * V_26 , void * V_27 )
{
F_10 ( * (struct V_9 * * ) V_27 ) ;
}
static int F_11 ( struct V_25 * V_26 , void * V_27 , void * V_28 )
{
struct V_9 * * V_29 = V_27 ;
if ( F_12 ( ! V_29 || ! * V_29 ) )
return 0 ;
return * V_29 == V_28 ;
}
struct V_9 * F_13 ( struct V_25 * V_26 , int V_30 )
{
struct V_9 * * V_31 , * V_3 ;
V_31 = F_14 ( F_9 , sizeof( * V_31 ) , V_18 ) ;
if ( ! V_31 )
return NULL ;
V_3 = F_6 ( V_30 ) ;
if ( V_3 ) {
* V_31 = V_3 ;
F_15 ( V_26 , V_31 ) ;
} else {
F_16 ( V_31 ) ;
}
return V_3 ;
}
void F_17 ( struct V_25 * V_26 , struct V_9 * V_3 )
{
int V_32 ;
V_32 = F_18 ( V_26 , F_9 ,
F_11 , V_3 ) ;
F_12 ( V_32 ) ;
}
static void F_19 ( struct V_25 * V_33 )
{
struct V_9 * V_3 = F_20 ( V_33 ) ;
F_21 ( V_3 -> V_19 != V_34 &&
V_3 -> V_19 != V_20 ) ;
F_22 ( V_3 ) ;
}
static int F_23 ( struct V_25 * V_26 , const void * V_35 )
{
return V_26 -> V_36 == V_35 ;
}
struct V_9 * F_24 ( struct V_37 * V_35 )
{
struct V_25 * V_33 ;
if ( ! V_35 )
return NULL ;
V_33 = F_25 ( & V_38 , NULL , V_35 ,
F_23 ) ;
return V_33 ? F_20 ( V_33 ) : NULL ;
}
static void F_26 ( struct V_9 * V_3 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_26 ;
struct V_37 * V_39 ;
if ( V_26 -> V_36 || ! V_3 -> V_26 . V_36 )
return;
F_27 (bus->dev.of_node, child) {
int V_5 ;
int V_40 ;
V_40 = F_28 ( V_39 , L_1 , & V_5 ) ;
if ( V_40 < 0 ) {
F_29 ( V_26 , L_2 ,
V_39 -> V_41 ) ;
continue;
}
if ( V_5 >= V_22 ) {
F_29 ( V_26 , L_3 ,
V_39 -> V_41 , V_5 ) ;
continue;
}
if ( V_5 == V_2 -> V_5 ) {
V_26 -> V_36 = V_39 ;
return;
}
}
}
static inline void F_26 ( struct V_9 * V_12 ,
struct V_1 * V_2 )
{
}
static int F_30 ( struct V_9 * V_3 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 ;
int V_40 = 0 ;
V_2 = F_31 ( V_3 , V_43 -> V_44 ) ;
if ( F_32 ( V_2 ) )
return - V_45 ;
strncpy ( V_2 -> V_46 , V_43 -> V_46 ,
sizeof( V_2 -> V_46 ) ) ;
V_2 -> V_47 = V_48 ;
V_2 -> V_26 . V_49 = ( void * ) V_43 -> V_49 ;
V_40 = F_33 ( V_2 ) ;
if ( V_40 )
F_34 ( V_2 ) ;
return V_40 ;
}
int F_35 ( struct V_9 * V_3 , struct V_50 * V_51 )
{
struct V_1 * V_2 ;
int V_17 , V_52 ;
struct V_53 * V_54 ;
if ( NULL == V_3 || NULL == V_3 -> V_55 ||
NULL == V_3 -> V_56 || NULL == V_3 -> V_57 )
return - V_7 ;
F_21 ( V_3 -> V_19 != V_20 &&
V_3 -> V_19 != V_58 ) ;
V_3 -> V_51 = V_51 ;
V_3 -> V_26 . V_59 = V_3 -> V_59 ;
V_3 -> V_26 . V_60 = & V_38 ;
V_3 -> V_26 . V_61 = NULL ;
F_36 ( & V_3 -> V_26 , L_4 , V_3 -> V_62 ) ;
V_52 = F_37 ( & V_3 -> V_26 ) ;
if ( V_52 ) {
F_38 ( L_5 , V_3 -> V_62 ) ;
F_39 ( & V_3 -> V_26 ) ;
return - V_7 ;
}
F_40 ( & V_3 -> V_63 ) ;
if ( V_3 -> V_64 > 0 ) {
V_3 -> V_65 = F_41 ( & V_3 -> V_26 ,
V_3 -> V_64 ,
sizeof( struct V_53 * ) ,
V_18 ) ;
if ( ! V_3 -> V_65 )
return - V_66 ;
}
for ( V_17 = 0 ; V_17 < V_3 -> V_64 ; V_17 ++ ) {
V_54 = F_42 ( & V_3 -> V_26 , L_6 , V_17 ,
V_67 ) ;
if ( F_32 ( V_54 ) ) {
V_52 = F_43 ( V_54 ) ;
if ( V_52 != - V_68 ) {
F_29 ( & V_3 -> V_26 ,
L_7 ,
V_3 -> V_62 ) ;
return V_52 ;
}
} else {
V_3 -> V_65 [ V_17 ] = V_54 ;
F_44 ( V_54 , 1 ) ;
F_45 ( V_3 -> V_69 ) ;
F_44 ( V_54 , 0 ) ;
}
}
if ( V_3 -> V_70 )
V_3 -> V_70 ( V_3 ) ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ ) {
if ( ( V_3 -> V_71 & ( 1 << V_17 ) ) == 0 ) {
struct V_8 * V_72 ;
V_72 = F_46 ( V_3 , V_17 ) ;
if ( F_32 ( V_72 ) && ( F_43 ( V_72 ) != - V_45 ) ) {
V_52 = F_43 ( V_72 ) ;
goto error;
}
}
}
F_47 ( V_3 , F_30 ) ;
V_3 -> V_19 = V_73 ;
F_48 ( L_8 , V_3 -> V_55 ) ;
return 0 ;
error:
while ( -- V_17 >= 0 ) {
V_2 = V_3 -> V_4 [ V_17 ] ;
if ( ! V_2 )
continue;
V_2 -> V_74 ( V_2 ) ;
V_2 -> V_75 ( V_2 ) ;
}
for ( V_17 = 0 ; V_17 < V_3 -> V_64 ; V_17 ++ ) {
if ( V_3 -> V_65 [ V_17 ] )
F_44 ( V_3 -> V_65 [ V_17 ] , 1 ) ;
}
F_49 ( & V_3 -> V_26 ) ;
return V_52 ;
}
void F_50 ( struct V_9 * V_3 )
{
struct V_1 * V_2 ;
int V_17 ;
F_21 ( V_3 -> V_19 != V_73 ) ;
V_3 -> V_19 = V_58 ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ ) {
V_2 = V_3 -> V_4 [ V_17 ] ;
if ( ! V_2 )
continue;
V_2 -> V_74 ( V_2 ) ;
V_2 -> V_75 ( V_2 ) ;
}
for ( V_17 = 0 ; V_17 < V_3 -> V_64 ; V_17 ++ ) {
if ( V_3 -> V_65 [ V_17 ] )
F_44 ( V_3 -> V_65 [ V_17 ] , 1 ) ;
}
F_49 ( & V_3 -> V_26 ) ;
}
void F_10 ( struct V_9 * V_3 )
{
if ( V_3 -> V_19 == V_20 ) {
F_22 ( V_3 ) ;
return;
}
F_21 ( V_3 -> V_19 != V_58 ) ;
V_3 -> V_19 = V_34 ;
F_39 ( & V_3 -> V_26 ) ;
}
struct V_8 * F_46 ( struct V_9 * V_3 , int V_5 )
{
struct V_8 * V_72 ;
int V_52 ;
V_72 = F_51 ( V_3 , V_5 , false ) ;
if ( F_32 ( V_72 ) )
return V_72 ;
F_26 ( V_3 , & V_72 -> V_12 ) ;
V_52 = F_52 ( V_72 ) ;
if ( V_52 ) {
F_53 ( V_72 ) ;
return F_54 ( - V_45 ) ;
}
return V_72 ;
}
int F_55 ( struct V_9 * V_3 , int V_5 , T_2 V_76 )
{
int V_77 ;
F_21 ( F_56 () ) ;
F_57 ( & V_3 -> V_63 , V_78 ) ;
V_77 = V_3 -> V_56 ( V_3 , V_5 , V_76 ) ;
F_58 ( & V_3 -> V_63 ) ;
F_59 ( V_3 , 1 , V_5 , V_76 , V_77 , V_77 ) ;
return V_77 ;
}
int F_60 ( struct V_9 * V_3 , int V_5 , T_2 V_76 )
{
int V_77 ;
F_21 ( F_56 () ) ;
F_61 ( & V_3 -> V_63 ) ;
V_77 = V_3 -> V_56 ( V_3 , V_5 , V_76 ) ;
F_58 ( & V_3 -> V_63 ) ;
F_59 ( V_3 , 1 , V_5 , V_76 , V_77 , V_77 ) ;
return V_77 ;
}
int F_62 ( struct V_9 * V_3 , int V_5 , T_2 V_76 , T_3 V_79 )
{
int V_52 ;
F_21 ( F_56 () ) ;
F_57 ( & V_3 -> V_63 , V_78 ) ;
V_52 = V_3 -> V_57 ( V_3 , V_5 , V_76 , V_79 ) ;
F_58 ( & V_3 -> V_63 ) ;
F_59 ( V_3 , 0 , V_5 , V_76 , V_79 , V_52 ) ;
return V_52 ;
}
int F_63 ( struct V_9 * V_3 , int V_5 , T_2 V_76 , T_3 V_79 )
{
int V_52 ;
F_21 ( F_56 () ) ;
F_61 ( & V_3 -> V_63 ) ;
V_52 = V_3 -> V_57 ( V_3 , V_5 , V_76 , V_79 ) ;
F_58 ( & V_3 -> V_63 ) ;
F_59 ( V_3 , 0 , V_5 , V_76 , V_79 , V_52 ) ;
return V_52 ;
}
static int F_64 ( struct V_25 * V_26 , struct V_80 * V_81 )
{
struct V_1 * V_12 = F_65 ( V_26 ) ;
if ( F_66 ( V_26 , V_81 ) )
return 1 ;
if ( V_12 -> V_47 )
return V_12 -> V_47 ( V_26 , V_81 ) ;
return 0 ;
}
static int F_67 ( struct V_25 * V_26 , struct V_82 * V_83 )
{
int V_32 ;
V_32 = F_68 ( V_26 , V_83 ) ;
if ( V_32 != - V_45 )
return V_32 ;
return 0 ;
}
static int F_69 ( struct V_25 * V_26 )
{
struct V_1 * V_12 = F_65 ( V_26 ) ;
if ( V_12 -> V_84 && V_12 -> V_84 -> V_85 )
return V_12 -> V_84 -> V_85 ( V_26 ) ;
return 0 ;
}
static int F_70 ( struct V_25 * V_26 )
{
struct V_1 * V_12 = F_65 ( V_26 ) ;
if ( V_12 -> V_84 && V_12 -> V_84 -> V_86 )
return V_12 -> V_84 -> V_86 ( V_26 ) ;
return 0 ;
}
static int F_71 ( struct V_25 * V_26 )
{
struct V_1 * V_12 = F_65 ( V_26 ) ;
if ( V_12 -> V_84 && V_12 -> V_84 -> V_87 )
return V_12 -> V_84 -> V_87 ( V_26 ) ;
return 0 ;
}
int T_4 F_72 ( void )
{
int V_40 ;
V_40 = F_73 ( & V_38 ) ;
if ( ! V_40 ) {
V_40 = F_74 ( & V_88 ) ;
if ( V_40 )
F_75 ( & V_38 ) ;
}
return V_40 ;
}
void F_76 ( void )
{
F_75 ( & V_38 ) ;
F_77 ( & V_88 ) ;
}
