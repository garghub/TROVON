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
unsigned V_16 , V_17 , V_18 ;
int V_19 ;
F_11 ( & V_4 -> V_20 . V_21 , V_15 ) ;
for ( V_16 = 0 ; V_16 < V_22 ; ++ V_16 ) {
if ( ! V_4 -> V_20 . V_23 [ V_16 ] . V_24 )
continue;
for ( V_17 = 0 ; V_17 < V_25 ; ++ V_17 ) {
struct V_26 * V_27 = V_4 -> V_20 . V_23 [ V_16 ] . V_24 [ V_17 ] ;
if ( ! V_27 || ! V_27 -> V_28 -> V_29 || ! V_27 -> V_30 )
continue;
for ( V_18 = 0 ; V_18 < V_27 -> V_30 ; ++ V_18 ) {
F_12 ( & V_27 -> V_31 [ V_18 ] , 0 ) ;
V_19 = V_27 -> V_28 -> V_29 ( V_4 , V_27 , V_18 ,
V_32 ) ;
if ( V_19 )
F_13 ( L_1 ,
V_19 ) ;
}
}
}
F_14 ( & V_4 -> V_20 . V_21 , V_15 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_33 ;
F_10 ( V_4 ) ;
F_16 ( V_4 ) ;
}
int F_17 ( struct V_6 * V_7 )
{
V_7 -> V_34 = 0x00ffffff ;
return 0 ;
}
void F_18 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_33 ;
if ( V_4 == NULL ) {
return;
}
F_10 ( V_4 ) ;
}
T_1 F_19 ( int V_20 , void * V_35 )
{
struct V_6 * V_7 = (struct V_6 * ) V_35 ;
struct V_3 * V_4 = V_7 -> V_33 ;
T_1 V_36 ;
V_36 = F_16 ( V_4 ) ;
if ( V_36 == V_37 )
F_20 ( V_7 -> V_7 ) ;
return V_36 ;
}
static bool F_21 ( struct V_3 * V_4 )
{
if ( V_38 == 1 )
return true ;
else if ( V_38 == 0 )
return false ;
return true ;
}
int F_22 ( struct V_3 * V_4 )
{
int V_19 = 0 ;
F_23 ( & V_4 -> V_20 . V_21 ) ;
V_19 = F_24 ( V_4 -> V_8 , V_4 -> V_39 . V_40 ) ;
if ( V_19 ) {
return V_19 ;
}
V_4 -> V_20 . V_41 = false ;
if ( F_21 ( V_4 ) ) {
int V_36 = F_25 ( V_4 -> V_42 ) ;
if ( ! V_36 ) {
V_4 -> V_20 . V_41 = true ;
F_26 ( V_4 -> V_7 , L_2 ) ;
}
}
F_27 ( & V_4 -> V_5 , F_1 ) ;
F_27 ( & V_4 -> V_14 , F_8 ) ;
V_4 -> V_20 . V_43 = true ;
V_19 = F_28 ( V_4 -> V_8 , V_4 -> V_8 -> V_42 -> V_20 ) ;
if ( V_19 ) {
V_4 -> V_20 . V_43 = false ;
F_29 ( & V_4 -> V_5 ) ;
F_30 ( & V_4 -> V_14 ) ;
return V_19 ;
}
F_31 ( L_3 ) ;
return 0 ;
}
void F_32 ( struct V_3 * V_4 )
{
unsigned V_16 , V_17 ;
F_33 ( V_4 -> V_8 ) ;
if ( V_4 -> V_20 . V_43 ) {
F_34 ( V_4 -> V_8 ) ;
V_4 -> V_20 . V_43 = false ;
if ( V_4 -> V_20 . V_41 )
F_35 ( V_4 -> V_42 ) ;
F_29 ( & V_4 -> V_5 ) ;
F_30 ( & V_4 -> V_14 ) ;
}
for ( V_16 = 0 ; V_16 < V_22 ; ++ V_16 ) {
if ( ! V_4 -> V_20 . V_23 [ V_16 ] . V_24 )
continue;
for ( V_17 = 0 ; V_17 < V_25 ; ++ V_17 ) {
struct V_26 * V_27 = V_4 -> V_20 . V_23 [ V_16 ] . V_24 [ V_17 ] ;
if ( ! V_27 )
continue;
F_36 ( V_27 -> V_31 ) ;
V_27 -> V_31 = NULL ;
if ( V_27 -> V_44 ) {
F_36 ( V_27 -> V_44 ) ;
F_36 ( V_27 ) ;
V_4 -> V_20 . V_23 [ V_16 ] . V_24 [ V_17 ] = NULL ;
}
}
F_36 ( V_4 -> V_20 . V_23 [ V_16 ] . V_24 ) ;
}
}
int F_37 ( struct V_3 * V_4 ,
unsigned V_45 , unsigned V_46 ,
struct V_26 * V_47 )
{
if ( V_45 >= V_22 )
return - V_48 ;
if ( V_46 >= V_25 )
return - V_48 ;
if ( ! V_47 -> V_28 )
return - V_48 ;
if ( ! V_4 -> V_20 . V_23 [ V_45 ] . V_24 ) {
V_4 -> V_20 . V_23 [ V_45 ] . V_24 =
F_38 ( V_25 ,
sizeof( struct V_26 * ) ,
V_49 ) ;
if ( ! V_4 -> V_20 . V_23 [ V_45 ] . V_24 )
return - V_50 ;
}
if ( V_4 -> V_20 . V_23 [ V_45 ] . V_24 [ V_46 ] != NULL )
return - V_48 ;
if ( V_47 -> V_30 && ! V_47 -> V_31 ) {
T_2 * V_51 ;
V_51 = F_38 ( V_47 -> V_30 , sizeof( T_2 ) ,
V_49 ) ;
if ( ! V_51 )
return - V_50 ;
V_47 -> V_31 = V_51 ;
}
V_4 -> V_20 . V_23 [ V_45 ] . V_24 [ V_46 ] = V_47 ;
return 0 ;
}
void F_39 ( struct V_3 * V_4 ,
struct V_52 * V_53 )
{
unsigned V_45 = V_53 -> V_45 ;
unsigned V_46 = V_53 -> V_46 ;
struct V_26 * V_27 ;
int V_19 ;
F_40 ( V_53 ) ;
if ( V_45 >= V_22 ) {
F_41 ( L_4 , V_45 ) ;
return;
}
if ( V_46 >= V_25 ) {
F_41 ( L_5 , V_46 ) ;
return;
}
if ( V_4 -> V_20 . V_54 [ V_46 ] ) {
F_42 ( F_43 ( V_4 -> V_20 . V_55 , V_46 ) ) ;
} else {
if ( ! V_4 -> V_20 . V_23 [ V_45 ] . V_24 ) {
F_41 ( L_6 ,
V_45 , V_46 ) ;
return;
}
V_27 = V_4 -> V_20 . V_23 [ V_45 ] . V_24 [ V_46 ] ;
if ( ! V_27 ) {
F_41 ( L_7 , V_46 ) ;
return;
}
V_19 = V_27 -> V_28 -> V_56 ( V_4 , V_27 , V_53 ) ;
if ( V_19 )
F_13 ( L_8 , V_19 ) ;
}
}
int F_44 ( struct V_3 * V_4 ,
struct V_26 * V_27 , unsigned type )
{
unsigned long V_15 ;
enum V_57 V_58 ;
int V_19 ;
F_11 ( & V_4 -> V_20 . V_21 , V_15 ) ;
if ( F_45 ( V_4 , V_27 , type ) )
V_58 = V_59 ;
else
V_58 = V_32 ;
V_19 = V_27 -> V_28 -> V_29 ( V_4 , V_27 , type , V_58 ) ;
F_14 ( & V_4 -> V_20 . V_21 , V_15 ) ;
return V_19 ;
}
void F_46 ( struct V_3 * V_4 )
{
int V_16 , V_17 , V_18 ;
for ( V_16 = 0 ; V_16 < V_22 ; ++ V_16 ) {
if ( ! V_4 -> V_20 . V_23 [ V_16 ] . V_24 )
continue;
for ( V_17 = 0 ; V_17 < V_25 ; ++ V_17 ) {
struct V_26 * V_27 = V_4 -> V_20 . V_23 [ V_16 ] . V_24 [ V_17 ] ;
if ( ! V_27 )
continue;
for ( V_18 = 0 ; V_18 < V_27 -> V_30 ; V_18 ++ )
F_44 ( V_4 , V_27 , V_18 ) ;
}
}
}
int F_47 ( struct V_3 * V_4 , struct V_26 * V_27 ,
unsigned type )
{
if ( ! V_4 -> V_8 -> V_60 )
return - V_61 ;
if ( type >= V_27 -> V_30 )
return - V_48 ;
if ( ! V_27 -> V_31 || ! V_27 -> V_28 -> V_29 )
return - V_48 ;
if ( F_48 ( & V_27 -> V_31 [ type ] ) == 1 )
return F_44 ( V_4 , V_27 , type ) ;
return 0 ;
}
int F_49 ( struct V_3 * V_4 , struct V_26 * V_27 ,
unsigned type )
{
if ( ! V_4 -> V_8 -> V_60 )
return - V_61 ;
if ( type >= V_27 -> V_30 )
return - V_48 ;
if ( ! V_27 -> V_31 || ! V_27 -> V_28 -> V_29 )
return - V_48 ;
if ( F_50 ( & V_27 -> V_31 [ type ] ) )
return F_44 ( V_4 , V_27 , type ) ;
return 0 ;
}
bool F_45 ( struct V_3 * V_4 , struct V_26 * V_27 ,
unsigned type )
{
if ( ! V_4 -> V_8 -> V_60 )
return false ;
if ( type >= V_27 -> V_30 )
return false ;
if ( ! V_27 -> V_31 || ! V_27 -> V_28 -> V_29 )
return false ;
return ! ! F_51 ( & V_27 -> V_31 [ type ] ) ;
}
static void F_52 ( struct V_62 * V_63 )
{
}
static void F_53 ( struct V_62 * V_63 )
{
}
static int F_54 ( struct V_64 * V_65 ,
unsigned int V_20 , T_3 V_66 )
{
if ( V_66 >= V_25 )
return - V_67 ;
F_55 ( V_20 ,
& V_68 , V_69 ) ;
return 0 ;
}
int F_56 ( struct V_3 * V_4 )
{
V_4 -> V_20 . V_55 = F_57 ( NULL , V_25 ,
& V_70 , V_4 ) ;
if ( ! V_4 -> V_20 . V_55 ) {
F_13 ( L_9 ) ;
return - V_71 ;
}
return 0 ;
}
void F_58 ( struct V_3 * V_4 )
{
if ( V_4 -> V_20 . V_55 ) {
F_59 ( V_4 -> V_20 . V_55 ) ;
V_4 -> V_20 . V_55 = NULL ;
}
}
unsigned F_60 ( struct V_3 * V_4 , unsigned V_46 )
{
V_4 -> V_20 . V_54 [ V_46 ] = F_61 ( V_4 -> V_20 . V_55 , V_46 ) ;
return V_4 -> V_20 . V_54 [ V_46 ] ;
}
