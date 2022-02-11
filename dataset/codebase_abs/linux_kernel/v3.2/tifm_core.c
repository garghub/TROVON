static const char * F_1 ( unsigned char type , unsigned char V_1 )
{
const char * V_2 [ 3 ] [ 3 ] = {
{ L_1 , L_2 , L_3 } ,
{ L_4 , L_5 , L_6 } ,
{ L_7 , L_8 , L_9 }
} ;
if ( V_1 > 2 || type < 1 || type > 3 )
return NULL ;
return V_2 [ V_1 ] [ type - 1 ] ;
}
static int F_2 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
if ( V_4 -> type == V_6 -> type )
return 1 ;
return 0 ;
}
static int F_3 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_3 * V_4 = F_4 ( V_8 , struct V_3 , V_8 ) ;
struct V_11 * V_12 = F_4 ( V_10 , struct V_11 ,
V_13 ) ;
struct V_5 * V_14 = V_12 -> V_15 ;
if ( V_14 ) {
while ( V_14 -> type ) {
if ( F_2 ( V_4 , V_14 ) )
return 1 ;
++ V_14 ;
}
}
return 0 ;
}
static int F_5 ( struct V_7 * V_8 , struct V_16 * V_17 )
{
struct V_3 * V_4 = F_4 ( V_8 , struct V_3 , V_8 ) ;
if ( F_6 ( V_17 , L_10 , F_1 ( V_4 -> type , 1 ) ) )
return - V_18 ;
return 0 ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_4 ( V_8 , struct V_3 , V_8 ) ;
struct V_11 * V_10 = F_4 ( V_8 -> V_13 , struct V_11 ,
V_13 ) ;
int V_19 = - V_20 ;
F_8 ( V_8 ) ;
if ( V_8 -> V_13 && V_10 -> V_21 ) {
V_19 = V_10 -> V_21 ( V_4 ) ;
if ( ! V_19 )
return 0 ;
}
F_9 ( V_8 ) ;
return V_19 ;
}
static void F_10 ( struct V_3 * V_4 )
{
return;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_4 ( V_8 , struct V_3 , V_8 ) ;
struct V_11 * V_10 = F_4 ( V_8 -> V_13 , struct V_11 ,
V_13 ) ;
if ( V_8 -> V_13 && V_10 -> remove ) {
V_4 -> V_22 = F_10 ;
V_4 -> V_23 = F_10 ;
V_10 -> remove ( V_4 ) ;
V_4 -> V_8 . V_13 = NULL ;
}
F_9 ( V_8 ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 , T_1 V_24 )
{
struct V_3 * V_4 = F_4 ( V_8 , struct V_3 , V_8 ) ;
struct V_11 * V_10 = F_4 ( V_8 -> V_13 , struct V_11 ,
V_13 ) ;
if ( V_8 -> V_13 && V_10 -> V_25 )
return V_10 -> V_25 ( V_4 , V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_4 ( V_8 , struct V_3 , V_8 ) ;
struct V_11 * V_10 = F_4 ( V_8 -> V_13 , struct V_11 ,
V_13 ) ;
if ( V_8 -> V_13 && V_10 -> V_26 )
return V_10 -> V_26 ( V_4 ) ;
return 0 ;
}
static T_2 F_14 ( struct V_7 * V_8 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_3 * V_4 = F_4 ( V_8 , struct V_3 , V_8 ) ;
return sprintf ( V_29 , L_11 , V_4 -> type ) ;
}
static void F_15 ( struct V_7 * V_8 )
{
struct V_30 * V_31 = F_4 ( V_8 , struct V_30 , V_8 ) ;
F_16 ( V_31 ) ;
}
struct V_30 * F_17 ( unsigned int V_32 ,
struct V_7 * V_8 )
{
struct V_30 * V_31 ;
V_31 = F_18 ( sizeof( struct V_30 )
+ sizeof( struct V_3 * ) * V_32 , V_33 ) ;
if ( V_31 ) {
V_31 -> V_8 . V_34 = & V_35 ;
V_31 -> V_8 . V_36 = V_8 ;
F_19 ( & V_31 -> V_8 ) ;
F_20 ( & V_31 -> V_37 ) ;
V_31 -> V_32 = V_32 ;
}
return V_31 ;
}
int F_21 ( struct V_30 * V_31 )
{
int V_19 ;
if ( ! F_22 ( & V_38 , V_33 ) )
return - V_18 ;
F_23 ( & V_39 ) ;
V_19 = F_24 ( & V_38 , V_31 , & V_31 -> V_6 ) ;
F_25 ( & V_39 ) ;
if ( V_19 )
return V_19 ;
F_26 ( & V_31 -> V_8 , L_12 , V_31 -> V_6 ) ;
V_19 = F_27 ( & V_31 -> V_8 ) ;
if ( V_19 ) {
F_23 ( & V_39 ) ;
F_28 ( & V_38 , V_31 -> V_6 ) ;
F_25 ( & V_39 ) ;
}
return V_19 ;
}
void F_29 ( struct V_30 * V_31 )
{
unsigned int V_40 ;
F_30 ( V_41 ) ;
for ( V_40 = 0 ; V_40 < V_31 -> V_32 ; ++ V_40 ) {
if ( V_31 -> V_42 [ V_40 ] )
F_31 ( & V_31 -> V_42 [ V_40 ] -> V_8 ) ;
}
F_23 ( & V_39 ) ;
F_28 ( & V_38 , V_31 -> V_6 ) ;
F_25 ( & V_39 ) ;
F_32 ( & V_31 -> V_8 ) ;
}
void F_33 ( struct V_30 * V_31 )
{
F_9 ( & V_31 -> V_8 ) ;
}
void F_34 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_4 ( V_8 , struct V_3 , V_8 ) ;
F_16 ( V_4 ) ;
}
struct V_3 * F_35 ( struct V_30 * V_31 , unsigned int V_6 ,
unsigned char type )
{
struct V_3 * V_4 = NULL ;
if ( ! F_1 ( type , 0 ) )
return V_4 ;
V_4 = F_18 ( sizeof( struct V_3 ) , V_33 ) ;
if ( V_4 ) {
F_20 ( & V_4 -> V_37 ) ;
V_4 -> type = type ;
V_4 -> V_43 = V_6 ;
V_4 -> V_22 = F_10 ;
V_4 -> V_23 = F_10 ;
V_4 -> V_8 . V_36 = V_31 -> V_8 . V_36 ;
V_4 -> V_8 . V_44 = & V_45 ;
V_4 -> V_8 . V_46 = V_31 -> V_8 . V_36 -> V_46 ;
V_4 -> V_8 . V_47 = F_34 ;
F_26 ( & V_4 -> V_8 , L_13 ,
F_1 ( type , 2 ) , V_31 -> V_6 , V_6 ) ;
F_36 (KERN_INFO DRIVER_NAME
L_14 ,
tifm_media_type_name(type, 0), fm->id, id) ;
}
return V_4 ;
}
void F_37 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = F_38 ( V_4 -> V_8 . V_36 ) ;
V_31 -> V_48 ( V_31 , V_4 ) ;
}
int F_39 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = F_38 ( V_4 -> V_8 . V_36 ) ;
return V_31 -> V_49 ( V_31 , V_4 ) ;
}
int F_40 ( struct V_3 * V_4 , struct V_50 * V_51 , int V_52 ,
int V_53 )
{
return F_41 ( F_42 ( V_4 -> V_8 . V_36 ) , V_51 , V_52 , V_53 ) ;
}
void F_43 ( struct V_3 * V_4 , struct V_50 * V_51 , int V_52 ,
int V_53 )
{
F_44 ( F_42 ( V_4 -> V_8 . V_36 ) , V_51 , V_52 , V_53 ) ;
}
void F_45 ( struct V_54 * V_55 )
{
F_46 ( V_41 , V_55 ) ;
}
int F_47 ( struct V_11 * V_10 )
{
V_10 -> V_13 . V_44 = & V_45 ;
return F_48 ( & V_10 -> V_13 ) ;
}
void F_49 ( struct V_11 * V_10 )
{
F_50 ( & V_10 -> V_13 ) ;
}
static int T_3 F_51 ( void )
{
int V_19 ;
V_41 = F_52 ( L_15 ) ;
if ( ! V_41 )
return - V_18 ;
V_19 = F_53 ( & V_45 ) ;
if ( V_19 )
goto V_56;
V_19 = F_54 ( & V_35 ) ;
if ( ! V_19 )
return 0 ;
F_55 ( & V_45 ) ;
V_56:
F_56 ( V_41 ) ;
return V_19 ;
}
static void T_4 F_57 ( void )
{
F_58 ( & V_35 ) ;
F_55 ( & V_45 ) ;
F_56 ( V_41 ) ;
}
