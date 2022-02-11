static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = & V_7 -> V_10 ;
struct V_11 * V_12 ;
F_3 ( & V_10 -> V_13 ) ;
if ( V_10 -> V_14 ) {
F_4 (connector, &mode_config->connector_list, head)
F_5 ( V_12 ) ;
}
F_6 ( & V_10 -> V_13 ) ;
F_7 ( V_7 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_15 ) ;
F_9 ( V_4 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
unsigned long V_16 ;
unsigned V_17 , V_18 ;
int V_19 ;
F_11 ( & V_4 -> V_20 . V_21 , V_16 ) ;
for ( V_17 = 0 ; V_17 < V_22 ; ++ V_17 ) {
struct V_23 * V_24 = V_4 -> V_20 . V_25 [ V_17 ] ;
if ( ! V_24 || ! V_24 -> V_26 -> V_27 || ! V_24 -> V_28 )
continue;
for ( V_18 = 0 ; V_18 < V_24 -> V_28 ; ++ V_18 ) {
F_12 ( & V_24 -> V_29 [ V_18 ] , 0 ) ;
V_19 = V_24 -> V_26 -> V_27 ( V_4 , V_24 , V_18 ,
V_30 ) ;
if ( V_19 )
F_13 ( L_1 ,
V_19 ) ;
}
}
F_14 ( & V_4 -> V_20 . V_21 , V_16 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_31 ;
F_10 ( V_4 ) ;
F_16 ( V_4 ) ;
}
int F_17 ( struct V_6 * V_7 )
{
V_7 -> V_32 = 0x00ffffff ;
return 0 ;
}
void F_18 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_31 ;
if ( V_4 == NULL ) {
return;
}
F_10 ( V_4 ) ;
}
T_1 F_19 ( int V_20 , void * V_33 )
{
struct V_6 * V_7 = (struct V_6 * ) V_33 ;
struct V_3 * V_4 = V_7 -> V_31 ;
T_1 V_34 ;
V_34 = F_16 ( V_4 ) ;
if ( V_34 == V_35 )
F_20 ( V_7 -> V_7 ) ;
return V_34 ;
}
static bool F_21 ( struct V_3 * V_4 )
{
if ( V_36 == 1 )
return true ;
else if ( V_36 == 0 )
return false ;
return true ;
}
int F_22 ( struct V_3 * V_4 )
{
int V_19 = 0 ;
F_23 ( & V_4 -> V_20 . V_21 ) ;
V_19 = F_24 ( V_4 -> V_8 , V_4 -> V_37 . V_38 ) ;
if ( V_19 ) {
return V_19 ;
}
V_4 -> V_20 . V_39 = false ;
if ( F_21 ( V_4 ) ) {
int V_34 = F_25 ( V_4 -> V_40 ) ;
if ( ! V_34 ) {
V_4 -> V_20 . V_39 = true ;
F_26 ( V_4 -> V_7 , L_2 ) ;
}
}
F_27 ( & V_4 -> V_5 , F_1 ) ;
F_27 ( & V_4 -> V_15 , F_8 ) ;
V_4 -> V_20 . V_41 = true ;
V_19 = F_28 ( V_4 -> V_8 , V_4 -> V_8 -> V_40 -> V_20 ) ;
if ( V_19 ) {
V_4 -> V_20 . V_41 = false ;
F_29 ( & V_4 -> V_5 ) ;
return V_19 ;
}
F_30 ( L_3 ) ;
return 0 ;
}
void F_31 ( struct V_3 * V_4 )
{
unsigned V_17 ;
F_32 ( V_4 -> V_8 ) ;
if ( V_4 -> V_20 . V_41 ) {
F_33 ( V_4 -> V_8 ) ;
V_4 -> V_20 . V_41 = false ;
if ( V_4 -> V_20 . V_39 )
F_34 ( V_4 -> V_40 ) ;
F_29 ( & V_4 -> V_5 ) ;
}
for ( V_17 = 0 ; V_17 < V_22 ; ++ V_17 ) {
struct V_23 * V_24 = V_4 -> V_20 . V_25 [ V_17 ] ;
if ( ! V_24 )
continue;
F_35 ( V_24 -> V_29 ) ;
V_24 -> V_29 = NULL ;
if ( V_24 -> V_42 ) {
F_35 ( V_24 -> V_42 ) ;
F_35 ( V_24 ) ;
V_4 -> V_20 . V_25 [ V_17 ] = NULL ;
}
}
}
int F_36 ( struct V_3 * V_4 , unsigned V_43 ,
struct V_23 * V_44 )
{
if ( V_43 >= V_22 )
return - V_45 ;
if ( V_4 -> V_20 . V_25 [ V_43 ] != NULL )
return - V_45 ;
if ( ! V_44 -> V_26 )
return - V_45 ;
if ( V_44 -> V_28 && ! V_44 -> V_29 ) {
T_2 * V_46 ;
V_46 = F_37 ( V_44 -> V_28 , sizeof( T_2 ) ,
V_47 ) ;
if ( ! V_46 )
return - V_48 ;
V_44 -> V_29 = V_46 ;
}
V_4 -> V_20 . V_25 [ V_43 ] = V_44 ;
return 0 ;
}
void F_38 ( struct V_3 * V_4 ,
struct V_49 * V_50 )
{
unsigned V_43 = V_50 -> V_43 ;
struct V_23 * V_24 ;
int V_19 ;
if ( V_43 >= V_22 ) {
F_39 ( L_4 , V_43 ) ;
return;
}
if ( V_4 -> V_20 . V_51 [ V_43 ] ) {
F_40 ( F_41 ( V_4 -> V_20 . V_52 , V_43 ) ) ;
} else {
V_24 = V_4 -> V_20 . V_25 [ V_43 ] ;
if ( ! V_24 ) {
F_39 ( L_5 , V_43 ) ;
return;
}
V_19 = V_24 -> V_26 -> V_53 ( V_4 , V_24 , V_50 ) ;
if ( V_19 )
F_13 ( L_6 , V_19 ) ;
}
}
int F_42 ( struct V_3 * V_4 ,
struct V_23 * V_24 , unsigned type )
{
unsigned long V_16 ;
enum V_54 V_55 ;
int V_19 ;
F_11 ( & V_4 -> V_20 . V_21 , V_16 ) ;
if ( F_43 ( V_4 , V_24 , type ) )
V_55 = V_56 ;
else
V_55 = V_30 ;
V_19 = V_24 -> V_26 -> V_27 ( V_4 , V_24 , type , V_55 ) ;
F_14 ( & V_4 -> V_20 . V_21 , V_16 ) ;
return V_19 ;
}
int F_44 ( struct V_3 * V_4 , struct V_23 * V_24 ,
unsigned type )
{
if ( ! V_4 -> V_8 -> V_57 )
return - V_58 ;
if ( type >= V_24 -> V_28 )
return - V_45 ;
if ( ! V_24 -> V_29 || ! V_24 -> V_26 -> V_27 )
return - V_45 ;
if ( F_45 ( & V_24 -> V_29 [ type ] ) == 1 )
return F_42 ( V_4 , V_24 , type ) ;
return 0 ;
}
bool F_46 ( struct V_3 * V_4 ,
struct V_23 * V_24 ,
unsigned type )
{
if ( ( type >= V_24 -> V_28 ) || ! V_24 -> V_29 )
return false ;
return F_45 ( & V_24 -> V_29 [ type ] ) == 1 ;
}
int F_47 ( struct V_3 * V_4 , struct V_23 * V_24 ,
unsigned type )
{
if ( ! V_4 -> V_8 -> V_57 )
return - V_58 ;
if ( type >= V_24 -> V_28 )
return - V_45 ;
if ( ! V_24 -> V_29 || ! V_24 -> V_26 -> V_27 )
return - V_45 ;
if ( F_48 ( & V_24 -> V_29 [ type ] ) )
return F_42 ( V_4 , V_24 , type ) ;
return 0 ;
}
bool F_43 ( struct V_3 * V_4 , struct V_23 * V_24 ,
unsigned type )
{
if ( ! V_4 -> V_8 -> V_57 )
return false ;
if ( type >= V_24 -> V_28 )
return false ;
if ( ! V_24 -> V_29 || ! V_24 -> V_26 -> V_27 )
return false ;
return ! ! F_49 ( & V_24 -> V_29 [ type ] ) ;
}
static void F_50 ( struct V_59 * V_60 )
{
}
static void F_51 ( struct V_59 * V_60 )
{
}
static int F_52 ( struct V_61 * V_62 ,
unsigned int V_20 , T_3 V_63 )
{
if ( V_63 >= V_22 )
return - V_64 ;
F_53 ( V_20 ,
& V_65 , V_66 ) ;
return 0 ;
}
int F_54 ( struct V_3 * V_4 )
{
V_4 -> V_20 . V_52 = F_55 ( NULL , V_22 ,
& V_67 , V_4 ) ;
if ( ! V_4 -> V_20 . V_52 ) {
F_13 ( L_7 ) ;
return - V_68 ;
}
return 0 ;
}
void F_56 ( struct V_3 * V_4 )
{
if ( V_4 -> V_20 . V_52 ) {
F_57 ( V_4 -> V_20 . V_52 ) ;
V_4 -> V_20 . V_52 = NULL ;
}
}
unsigned F_58 ( struct V_3 * V_4 , unsigned V_43 )
{
V_4 -> V_20 . V_51 [ V_43 ] = F_59 ( V_4 -> V_20 . V_52 , V_43 ) ;
return V_4 -> V_20 . V_51 [ V_43 ] ;
}
