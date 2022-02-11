static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = & V_7 -> V_10 ;
struct V_11 * V_12 ;
F_3 ( & V_10 -> V_13 ) ;
F_4 (connector, &mode_config->connector_list, head)
F_5 ( V_12 ) ;
F_6 ( & V_10 -> V_13 ) ;
F_7 ( V_7 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_14 ) ;
F_9 ( V_4 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
unsigned long V_15 ;
unsigned V_16 , V_17 ;
int V_18 ;
F_11 ( & V_4 -> V_19 . V_20 , V_15 ) ;
for ( V_16 = 0 ; V_16 < V_21 ; ++ V_16 ) {
struct V_22 * V_23 = V_4 -> V_19 . V_24 [ V_16 ] ;
if ( ! V_23 || ! V_23 -> V_25 -> V_26 || ! V_23 -> V_27 )
continue;
for ( V_17 = 0 ; V_17 < V_23 -> V_27 ; ++ V_17 ) {
F_12 ( & V_23 -> V_28 [ V_17 ] , 0 ) ;
V_18 = V_23 -> V_25 -> V_26 ( V_4 , V_23 , V_17 ,
V_29 ) ;
if ( V_18 )
F_13 ( L_1 ,
V_18 ) ;
}
}
F_14 ( & V_4 -> V_19 . V_20 , V_15 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_30 ;
F_10 ( V_4 ) ;
F_16 ( V_4 ) ;
}
int F_17 ( struct V_6 * V_7 )
{
V_7 -> V_31 = 0x00ffffff ;
return 0 ;
}
void F_18 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_30 ;
if ( V_4 == NULL ) {
return;
}
F_10 ( V_4 ) ;
}
T_1 F_19 ( int V_19 , void * V_32 )
{
struct V_6 * V_7 = (struct V_6 * ) V_32 ;
struct V_3 * V_4 = V_7 -> V_30 ;
T_1 V_33 ;
V_33 = F_16 ( V_4 ) ;
if ( V_33 == V_34 )
F_20 ( V_7 -> V_7 ) ;
return V_33 ;
}
static bool F_21 ( struct V_3 * V_4 )
{
if ( V_35 == 1 )
return true ;
else if ( V_35 == 0 )
return false ;
return true ;
}
int F_22 ( struct V_3 * V_4 )
{
int V_18 = 0 ;
F_23 ( & V_4 -> V_19 . V_20 ) ;
V_18 = F_24 ( V_4 -> V_8 , V_4 -> V_36 . V_37 ) ;
if ( V_18 ) {
return V_18 ;
}
V_4 -> V_19 . V_38 = false ;
if ( F_21 ( V_4 ) ) {
int V_33 = F_25 ( V_4 -> V_39 ) ;
if ( ! V_33 ) {
V_4 -> V_19 . V_38 = true ;
F_26 ( V_4 -> V_7 , L_2 ) ;
}
}
F_27 ( & V_4 -> V_5 , F_1 ) ;
F_27 ( & V_4 -> V_14 , F_8 ) ;
V_4 -> V_19 . V_40 = true ;
V_18 = F_28 ( V_4 -> V_8 , V_4 -> V_8 -> V_39 -> V_19 ) ;
if ( V_18 ) {
V_4 -> V_19 . V_40 = false ;
F_29 ( & V_4 -> V_5 ) ;
F_30 ( & V_4 -> V_14 ) ;
return V_18 ;
}
F_31 ( L_3 ) ;
return 0 ;
}
void F_32 ( struct V_3 * V_4 )
{
unsigned V_16 ;
F_33 ( V_4 -> V_8 ) ;
if ( V_4 -> V_19 . V_40 ) {
F_34 ( V_4 -> V_8 ) ;
V_4 -> V_19 . V_40 = false ;
if ( V_4 -> V_19 . V_38 )
F_35 ( V_4 -> V_39 ) ;
F_29 ( & V_4 -> V_5 ) ;
F_30 ( & V_4 -> V_14 ) ;
}
for ( V_16 = 0 ; V_16 < V_21 ; ++ V_16 ) {
struct V_22 * V_23 = V_4 -> V_19 . V_24 [ V_16 ] ;
if ( ! V_23 )
continue;
F_36 ( V_23 -> V_28 ) ;
V_23 -> V_28 = NULL ;
if ( V_23 -> V_41 ) {
F_36 ( V_23 -> V_41 ) ;
F_36 ( V_23 ) ;
V_4 -> V_19 . V_24 [ V_16 ] = NULL ;
}
}
}
int F_37 ( struct V_3 * V_4 , unsigned V_42 ,
struct V_22 * V_43 )
{
if ( V_42 >= V_21 )
return - V_44 ;
if ( V_4 -> V_19 . V_24 [ V_42 ] != NULL )
return - V_44 ;
if ( ! V_43 -> V_25 )
return - V_44 ;
if ( V_43 -> V_27 && ! V_43 -> V_28 ) {
T_2 * V_45 ;
V_45 = F_38 ( V_43 -> V_27 , sizeof( T_2 ) ,
V_46 ) ;
if ( ! V_45 )
return - V_47 ;
V_43 -> V_28 = V_45 ;
}
V_4 -> V_19 . V_24 [ V_42 ] = V_43 ;
return 0 ;
}
void F_39 ( struct V_3 * V_4 ,
struct V_48 * V_49 )
{
unsigned V_42 = V_49 -> V_42 ;
struct V_22 * V_23 ;
int V_18 ;
if ( V_42 >= V_21 ) {
F_40 ( L_4 , V_42 ) ;
return;
}
if ( V_4 -> V_19 . V_50 [ V_42 ] ) {
F_41 ( F_42 ( V_4 -> V_19 . V_51 , V_42 ) ) ;
} else {
V_23 = V_4 -> V_19 . V_24 [ V_42 ] ;
if ( ! V_23 ) {
F_40 ( L_5 , V_42 ) ;
return;
}
V_18 = V_23 -> V_25 -> V_52 ( V_4 , V_23 , V_49 ) ;
if ( V_18 )
F_13 ( L_6 , V_18 ) ;
}
}
int F_43 ( struct V_3 * V_4 ,
struct V_22 * V_23 , unsigned type )
{
unsigned long V_15 ;
enum V_53 V_54 ;
int V_18 ;
F_11 ( & V_4 -> V_19 . V_20 , V_15 ) ;
if ( F_44 ( V_4 , V_23 , type ) )
V_54 = V_55 ;
else
V_54 = V_29 ;
V_18 = V_23 -> V_25 -> V_26 ( V_4 , V_23 , type , V_54 ) ;
F_14 ( & V_4 -> V_19 . V_20 , V_15 ) ;
return V_18 ;
}
void F_45 ( struct V_3 * V_4 )
{
int V_16 , V_17 ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ ) {
struct V_22 * V_23 = V_4 -> V_19 . V_24 [ V_16 ] ;
if ( ! V_23 )
continue;
for ( V_17 = 0 ; V_17 < V_23 -> V_27 ; V_17 ++ )
F_43 ( V_4 , V_23 , V_17 ) ;
}
}
int F_46 ( struct V_3 * V_4 , struct V_22 * V_23 ,
unsigned type )
{
if ( ! V_4 -> V_8 -> V_56 )
return - V_57 ;
if ( type >= V_23 -> V_27 )
return - V_44 ;
if ( ! V_23 -> V_28 || ! V_23 -> V_25 -> V_26 )
return - V_44 ;
if ( F_47 ( & V_23 -> V_28 [ type ] ) == 1 )
return F_43 ( V_4 , V_23 , type ) ;
return 0 ;
}
int F_48 ( struct V_3 * V_4 , struct V_22 * V_23 ,
unsigned type )
{
if ( ! V_4 -> V_8 -> V_56 )
return - V_57 ;
if ( type >= V_23 -> V_27 )
return - V_44 ;
if ( ! V_23 -> V_28 || ! V_23 -> V_25 -> V_26 )
return - V_44 ;
if ( F_49 ( & V_23 -> V_28 [ type ] ) )
return F_43 ( V_4 , V_23 , type ) ;
return 0 ;
}
bool F_44 ( struct V_3 * V_4 , struct V_22 * V_23 ,
unsigned type )
{
if ( ! V_4 -> V_8 -> V_56 )
return false ;
if ( type >= V_23 -> V_27 )
return false ;
if ( ! V_23 -> V_28 || ! V_23 -> V_25 -> V_26 )
return false ;
return ! ! F_50 ( & V_23 -> V_28 [ type ] ) ;
}
static void F_51 ( struct V_58 * V_59 )
{
}
static void F_52 ( struct V_58 * V_59 )
{
}
static int F_53 ( struct V_60 * V_61 ,
unsigned int V_19 , T_3 V_62 )
{
if ( V_62 >= V_21 )
return - V_63 ;
F_54 ( V_19 ,
& V_64 , V_65 ) ;
return 0 ;
}
int F_55 ( struct V_3 * V_4 )
{
V_4 -> V_19 . V_51 = F_56 ( NULL , V_21 ,
& V_66 , V_4 ) ;
if ( ! V_4 -> V_19 . V_51 ) {
F_13 ( L_7 ) ;
return - V_67 ;
}
return 0 ;
}
void F_57 ( struct V_3 * V_4 )
{
if ( V_4 -> V_19 . V_51 ) {
F_58 ( V_4 -> V_19 . V_51 ) ;
V_4 -> V_19 . V_51 = NULL ;
}
}
unsigned F_59 ( struct V_3 * V_4 , unsigned V_42 )
{
V_4 -> V_19 . V_50 [ V_42 ] = F_60 ( V_4 -> V_19 . V_51 , V_42 ) ;
return V_4 -> V_19 . V_50 [ V_42 ] ;
}
