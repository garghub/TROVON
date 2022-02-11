struct V_1 * F_1 ( const char * V_2 )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( ! strcmp ( V_5 [ V_3 ] -> V_2 , V_2 ) )
return V_5 [ V_3 ] ;
}
return NULL ;
}
static struct V_1 * F_2 ( T_2 type )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( V_5 [ V_3 ] -> V_6 == type )
return V_5 [ V_3 ] ;
}
return NULL ;
}
int F_3 ( struct V_1 * V_7 )
{
int V_8 = - V_9 ;
F_4 ( & V_10 ) ;
if ( ( strlen ( V_7 -> V_2 ) + 1 ) > V_11 )
goto exit;
if ( V_7 -> V_12 > V_13 )
goto exit;
if ( ( V_7 -> V_14 < V_15 ) ||
( V_7 -> V_14 > V_16 ) )
goto exit;
if ( V_4 >= V_17 )
goto exit;
if ( F_1 ( V_7 -> V_2 ) || F_2 ( V_7 -> V_6 ) )
goto exit;
V_5 [ V_4 ] = V_7 ;
V_4 ++ ;
V_8 = 0 ;
exit:
F_5 ( & V_10 ) ;
if ( V_8 )
F_6 ( L_1 , V_7 -> V_2 ) ;
return V_8 ;
}
void F_7 ( char * V_18 , int V_19 , struct V_20 * V_21 )
{
char V_22 [ V_23 ] ;
struct V_1 * V_7 ;
int V_24 ;
V_7 = F_2 ( V_21 -> V_25 ) ;
if ( V_7 && ! V_7 -> V_26 ( V_21 , V_22 , sizeof( V_22 ) ) )
V_24 = F_8 ( V_18 , V_19 , L_2 , V_7 -> V_2 , V_22 ) ;
else {
T_1 V_3 ;
V_24 = F_8 ( V_18 , V_19 , L_3 , V_21 -> V_25 ) ;
for ( V_3 = 0 ; V_3 < sizeof( V_21 -> V_27 ) ; V_3 ++ )
V_24 += F_8 ( V_18 - V_24 , V_19 + V_24 ,
L_4 , V_21 -> V_27 [ V_3 ] ) ;
}
}
struct V_28 * F_9 ( void )
{
struct V_28 * V_18 ;
int V_3 ;
V_18 = F_10 ( V_17 * F_11 ( V_11 ) ) ;
if ( ! V_18 )
return NULL ;
F_12 ( & V_10 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_13 ( V_18 , V_29 ,
V_5 [ V_3 ] -> V_2 ,
strlen ( V_5 [ V_3 ] -> V_2 ) + 1 ) ;
}
F_14 ( & V_10 ) ;
return V_18 ;
}
static int F_15 ( const char * V_2 ,
struct V_30 * V_31 )
{
char V_32 [ V_33 ] ;
char * V_34 ;
char * V_35 ;
T_1 V_36 ;
T_1 V_37 ;
V_32 [ V_33 - 1 ] = 0 ;
strncpy ( V_32 , V_2 , V_33 ) ;
if ( V_32 [ V_33 - 1 ] != 0 )
return 0 ;
V_34 = V_32 ;
V_35 = strchr ( V_34 , ':' ) ;
if ( V_35 == NULL )
return 0 ;
* ( V_35 ++ ) = 0 ;
V_36 = V_35 - V_34 ;
V_37 = strlen ( V_35 ) + 1 ;
if ( ( V_36 <= 1 ) || ( V_36 > V_11 ) ||
( V_37 <= 1 ) || ( V_37 > V_38 ) )
return 0 ;
if ( V_31 ) {
strcpy ( V_31 -> V_34 , V_34 ) ;
strcpy ( V_31 -> V_35 , V_35 ) ;
}
return 1 ;
}
struct V_39 * F_16 ( const char * V_2 )
{
struct V_39 * V_40 ;
T_1 V_3 ;
for ( V_3 = 0 , V_40 = V_41 ; V_3 < V_42 ; V_3 ++ , V_40 ++ ) {
if ( V_40 -> V_43 && ( ! strcmp ( V_40 -> V_2 , V_2 ) ) )
return V_40 ;
}
return NULL ;
}
struct V_39 * F_17 ( const char * V_35 )
{
struct V_39 * V_40 ;
char * V_44 ;
T_1 V_3 ;
for ( V_3 = 0 , V_40 = V_41 ; V_3 < V_42 ; V_3 ++ , V_40 ++ ) {
if ( ! V_40 -> V_43 )
continue;
V_44 = strchr ( V_40 -> V_2 , ':' ) + 1 ;
if ( ! strcmp ( V_44 , V_35 ) )
return V_40 ;
}
return NULL ;
}
struct V_28 * F_18 ( void )
{
struct V_28 * V_18 ;
struct V_39 * V_40 ;
int V_3 , V_45 ;
V_18 = F_10 ( V_42 * F_11 ( V_33 ) ) ;
if ( ! V_18 )
return NULL ;
F_12 ( & V_10 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
for ( V_45 = 0 ; V_45 < V_42 ; V_45 ++ ) {
V_40 = & V_41 [ V_45 ] ;
if ( V_40 -> V_43 && ( V_40 -> V_46 == V_5 [ V_3 ] ) ) {
F_13 ( V_18 , V_47 ,
V_40 -> V_2 ,
strlen ( V_40 -> V_2 ) + 1 ) ;
}
}
}
F_14 ( & V_10 ) ;
return V_18 ;
}
void F_19 ( struct V_39 * V_40 , T_1 V_48 )
{
F_20 ( & V_40 -> V_49 , V_48 ) ;
F_21 () ;
F_22 ( V_40 -> V_50 ) ;
}
void F_23 ( struct V_39 * V_40 , T_1 V_48 )
{
F_24 ( & V_40 -> V_49 , V_48 ) ;
F_21 () ;
F_25 ( V_40 -> V_50 ) ;
}
void F_26 ( struct V_39 * V_51 )
{
F_27 ( & V_51 -> V_52 ) ;
V_51 -> V_53 = 0 ;
F_28 ( & V_51 -> V_52 ) ;
}
int F_29 ( struct V_39 * V_51 )
{
int V_8 ;
F_27 ( & V_51 -> V_52 ) ;
V_8 = V_51 -> V_53 ;
F_28 ( & V_51 -> V_52 ) ;
return V_8 ;
}
int F_30 ( const char * V_2 , T_1 V_54 , T_1 V_12 )
{
struct V_39 * V_40 ;
struct V_1 * V_7 ;
struct V_30 V_55 ;
char V_56 [ 16 ] ;
T_1 V_57 ;
T_1 V_58 ;
T_1 V_3 ;
int V_8 = - V_9 ;
if ( ! V_59 ) {
F_6 ( L_5 ,
V_2 ) ;
return - V_60 ;
}
if ( ! F_15 ( V_2 , & V_55 ) ) {
F_6 ( L_6 , V_2 ) ;
return - V_9 ;
}
if ( F_31 ( V_54 ) &&
( V_54 != V_59 ) ) {
if ( F_32 ( V_54 , V_59 ) ) {
V_54 = V_59 & V_61 ;
V_8 = 0 ;
} else if ( F_33 ( V_54 ) )
V_8 = 0 ;
}
if ( V_8 ) {
F_6 ( L_7 ,
V_2 ) ;
return - V_9 ;
}
if ( ( V_12 > V_13 ) &&
( V_12 != V_62 ) ) {
F_6 ( L_8 , V_2 ) ;
return - V_9 ;
}
F_4 ( & V_10 ) ;
V_7 = F_1 ( V_55 . V_34 ) ;
if ( ! V_7 ) {
F_6 ( L_9 ,
V_2 , V_55 . V_34 ) ;
goto exit;
}
if ( V_12 == V_62 )
V_12 = V_7 -> V_12 ;
V_63:
V_57 = V_42 ;
V_58 = 1 ;
for ( V_3 = V_42 ; V_3 -- != 0 ; ) {
if ( ! V_41 [ V_3 ] . V_43 ) {
V_57 = V_3 ;
continue;
}
if ( ! strcmp ( V_2 , V_41 [ V_3 ] . V_2 ) ) {
F_6 ( L_10 ,
V_2 ) ;
goto exit;
}
if ( ( V_41 [ V_3 ] . V_12 == V_12 ) &&
( ++ V_58 > 2 ) ) {
if ( V_12 -- == 0 ) {
F_6 ( L_11 ,
V_2 ) ;
goto exit;
}
F_6 ( L_12 ,
V_2 , V_12 + 1 , V_12 ) ;
goto V_63;
}
}
if ( V_57 >= V_42 ) {
F_6 ( L_13 ,
V_2 , V_42 ) ;
goto exit;
}
V_40 = & V_41 [ V_57 ] ;
strcpy ( V_40 -> V_2 , V_2 ) ;
V_8 = V_7 -> V_64 ( V_40 ) ;
if ( V_8 ) {
F_6 ( L_14 ,
V_2 , - V_8 ) ;
goto exit;
}
V_40 -> V_65 = V_57 ;
V_40 -> V_46 = V_7 ;
V_40 -> V_14 = V_7 -> V_14 ;
V_40 -> V_66 = V_7 -> V_66 ;
V_40 -> V_67 = V_57 + 'A' ;
V_40 -> V_43 = 1 ;
V_40 -> V_12 = V_12 ;
F_34 ( & V_40 -> V_68 ) ;
F_35 ( & V_40 -> V_52 ) ;
V_8 = F_36 ( V_40 , & V_40 -> V_69 , V_54 ) ;
if ( V_8 ) {
F_37 ( V_40 ) ;
F_6 ( L_15 ,
V_2 ) ;
goto exit;
}
F_38 ( L_16 ,
V_2 ,
F_39 ( V_56 , V_54 ) , V_12 ) ;
exit:
F_5 ( & V_10 ) ;
return V_8 ;
}
int F_40 ( const char * V_2 )
{
struct V_39 * V_40 = NULL ;
struct V_70 * V_71 ;
struct V_70 * V_72 ;
F_12 ( & V_10 ) ;
V_40 = F_16 ( V_2 ) ;
if ( ! V_40 ) {
F_6 ( L_17 , V_2 ) ;
F_14 ( & V_10 ) ;
return - V_9 ;
}
F_38 ( L_18 , V_2 ) ;
F_27 ( & V_40 -> V_52 ) ;
V_40 -> V_53 = 1 ;
F_41 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
struct V_73 * V_74 = V_71 -> V_75 ;
F_27 ( & V_74 -> V_52 ) ;
F_42 ( V_71 ) ;
F_28 ( & V_74 -> V_52 ) ;
}
F_28 ( & V_40 -> V_52 ) ;
F_14 ( & V_10 ) ;
return 0 ;
}
static void F_37 ( struct V_39 * V_40 )
{
struct V_70 * V_71 ;
struct V_70 * V_72 ;
F_38 ( L_19 , V_40 -> V_2 ) ;
F_27 ( & V_40 -> V_52 ) ;
V_40 -> V_53 = 1 ;
V_40 -> V_46 -> V_76 ( V_40 ) ;
F_41 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
F_43 ( V_71 ) ;
}
if ( V_40 -> V_50 )
F_44 ( V_40 -> V_50 ) ;
F_28 ( & V_40 -> V_52 ) ;
memset ( V_40 , 0 , sizeof( struct V_39 ) ) ;
}
int F_45 ( const char * V_2 )
{
struct V_39 * V_40 ;
int V_8 ;
F_4 ( & V_10 ) ;
V_40 = F_16 ( V_2 ) ;
if ( V_40 == NULL ) {
F_6 ( L_20 , V_2 ) ;
V_8 = - V_9 ;
} else {
F_37 ( V_40 ) ;
V_8 = 0 ;
}
F_5 ( & V_10 ) ;
return V_8 ;
}
void F_46 ( void )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_42 ; V_3 ++ ) {
if ( V_41 [ V_3 ] . V_43 )
F_37 ( & V_41 [ V_3 ] ) ;
}
V_4 = 0 ;
}
