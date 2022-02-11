static int F_1 ( const char * V_1 )
{
T_1 V_2 ;
V_2 = strlen ( V_1 ) ;
if ( ( V_2 + 1 ) > V_3 )
return 0 ;
return strspn ( V_1 , V_4 ) == V_2 ;
}
struct V_5 * F_2 ( const char * V_1 )
{
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
if ( ! strcmp ( V_8 [ V_6 ] -> V_1 , V_1 ) )
return V_8 [ V_6 ] ;
}
return NULL ;
}
static struct V_5 * F_3 ( T_2 type )
{
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
if ( V_8 [ V_6 ] -> V_9 == type )
return V_8 [ V_6 ] ;
}
return NULL ;
}
int F_4 ( struct V_5 * V_10 )
{
int V_11 = - V_12 ;
F_5 ( & V_13 ) ;
if ( ! F_1 ( V_10 -> V_1 ) )
goto exit;
if ( ( V_10 -> V_14 . V_15 != V_10 -> V_9 ) ||
! V_10 -> V_14 . V_16 )
goto exit;
if ( V_10 -> V_17 > V_18 )
goto exit;
if ( ( V_10 -> V_19 < V_20 ) ||
( V_10 -> V_19 > V_21 ) )
goto exit;
if ( V_7 >= V_22 )
goto exit;
if ( F_2 ( V_10 -> V_1 ) || F_3 ( V_10 -> V_9 ) )
goto exit;
V_8 [ V_7 ] = V_10 ;
V_7 ++ ;
V_11 = 0 ;
exit:
F_6 ( & V_13 ) ;
if ( V_11 )
F_7 ( L_1 , V_10 -> V_1 ) ;
return V_11 ;
}
void F_8 ( struct V_23 * V_24 , struct V_25 * V_26 )
{
char V_27 [ V_28 ] ;
struct V_5 * V_10 ;
V_10 = F_3 ( V_26 -> V_15 ) ;
if ( V_10 && ! V_10 -> V_29 ( V_26 , V_27 , sizeof( V_27 ) ) )
F_9 ( V_24 , L_2 , V_10 -> V_1 , V_27 ) ;
else {
T_1 V_6 ;
F_9 ( V_24 , L_3 , V_26 -> V_15 ) ;
for ( V_6 = 0 ; V_6 < sizeof( V_26 -> V_30 ) ; V_6 ++ )
F_9 ( V_24 , L_4 , V_26 -> V_30 [ V_6 ] ) ;
}
}
struct V_31 * F_10 ( void )
{
struct V_31 * V_32 ;
int V_6 ;
V_32 = F_11 ( V_22 * F_12 ( V_3 ) ) ;
if ( ! V_32 )
return NULL ;
F_13 ( & V_13 ) ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
F_14 ( V_32 , V_33 ,
V_8 [ V_6 ] -> V_1 ,
strlen ( V_8 [ V_6 ] -> V_1 ) + 1 ) ;
}
F_15 ( & V_13 ) ;
return V_32 ;
}
static int F_16 ( const char * V_1 ,
struct V_34 * V_35 )
{
char V_36 [ V_37 ] ;
char * V_38 ;
char * V_39 ;
T_1 V_40 ;
T_1 V_41 ;
V_36 [ V_37 - 1 ] = 0 ;
strncpy ( V_36 , V_1 , V_37 ) ;
if ( V_36 [ V_37 - 1 ] != 0 )
return 0 ;
V_38 = V_36 ;
V_39 = strchr ( V_38 , ':' ) ;
if ( V_39 == NULL )
return 0 ;
* ( V_39 ++ ) = 0 ;
V_40 = V_39 - V_38 ;
V_41 = strlen ( V_39 ) + 1 ;
if ( ( V_40 <= 1 ) || ( V_40 > V_3 ) ||
( V_41 <= 1 ) || ( V_41 > V_42 ) ||
( strspn ( V_38 , V_4 ) != ( V_40 - 1 ) ) ||
( strspn ( V_39 , V_4 ) != ( V_41 - 1 ) ) )
return 0 ;
if ( V_35 ) {
strcpy ( V_35 -> V_38 , V_38 ) ;
strcpy ( V_35 -> V_39 , V_39 ) ;
}
return 1 ;
}
struct V_43 * F_17 ( const char * V_1 )
{
struct V_43 * V_44 ;
T_1 V_6 ;
for ( V_6 = 0 , V_44 = V_45 ; V_6 < V_46 ; V_6 ++ , V_44 ++ ) {
if ( V_44 -> V_47 && ( ! strcmp ( V_44 -> V_1 , V_1 ) ) )
return V_44 ;
}
return NULL ;
}
struct V_43 * F_18 ( const char * V_39 )
{
struct V_43 * V_44 ;
char * V_48 ;
T_1 V_6 ;
for ( V_6 = 0 , V_44 = V_45 ; V_6 < V_46 ; V_6 ++ , V_44 ++ ) {
if ( ! V_44 -> V_47 )
continue;
V_48 = strchr ( V_44 -> V_1 , ':' ) + 1 ;
if ( ! strcmp ( V_48 , V_39 ) )
return V_44 ;
}
return NULL ;
}
struct V_31 * F_19 ( void )
{
struct V_31 * V_32 ;
struct V_43 * V_44 ;
int V_6 , V_49 ;
V_32 = F_11 ( V_46 * F_12 ( V_37 ) ) ;
if ( ! V_32 )
return NULL ;
F_13 ( & V_13 ) ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
for ( V_49 = 0 ; V_49 < V_46 ; V_49 ++ ) {
V_44 = & V_45 [ V_49 ] ;
if ( V_44 -> V_47 && ( V_44 -> V_50 == V_8 [ V_6 ] ) ) {
F_14 ( V_32 , V_51 ,
V_44 -> V_1 ,
strlen ( V_44 -> V_1 ) + 1 ) ;
}
}
}
F_15 ( & V_13 ) ;
return V_32 ;
}
void F_20 ( struct V_43 * V_44 , T_1 V_52 )
{
F_21 ( & V_44 -> V_53 , V_52 ) ;
F_22 () ;
F_23 ( V_44 -> V_54 ) ;
}
void F_24 ( struct V_43 * V_44 , T_1 V_52 )
{
F_25 ( & V_44 -> V_53 , V_52 ) ;
F_22 () ;
F_26 ( V_44 -> V_54 ) ;
}
static int F_27 ( struct V_43 * V_44 )
{
T_1 V_11 = 0 ;
struct V_55 * V_56 , * V_57 ;
if ( V_44 -> V_58 )
return 0 ;
while ( ! F_28 ( & V_44 -> V_59 ) && ( V_11 != V_60 ) ) {
F_29 (ln, tln, &b_ptr->cong_links, link_list) {
V_11 = F_30 ( V_56 ) ;
if ( V_11 == V_60 )
break;
if ( V_11 == V_61 )
F_31 ( & V_56 -> V_62 , & V_44 -> V_63 ) ;
}
}
return F_28 ( & V_44 -> V_59 ) ;
}
void F_32 ( struct V_43 * V_44 )
{
F_33 ( & V_44 -> V_64 ) ;
F_27 ( V_44 ) ;
F_34 ( & V_44 -> V_64 ) ;
}
void F_35 ( struct V_43 * V_44 )
{
F_33 ( & V_44 -> V_64 ) ;
if ( ! F_28 ( & V_44 -> V_59 ) )
F_36 ( ( V_65 ) F_32 , ( unsigned long ) V_44 ) ;
V_44 -> V_58 = 0 ;
F_34 ( & V_44 -> V_64 ) ;
}
static void F_37 ( struct V_43 * V_44 ,
struct V_55 * V_66 )
{
F_31 ( & V_66 -> V_62 , & V_44 -> V_59 ) ;
}
void F_38 ( struct V_43 * V_44 , struct V_55 * V_66 )
{
F_33 ( & V_44 -> V_64 ) ;
F_37 ( V_44 , V_66 ) ;
F_34 ( & V_44 -> V_64 ) ;
}
int F_39 ( struct V_43 * V_44 ,
struct V_55 * V_66 )
{
int V_11 = 1 ;
if ( F_28 ( & V_44 -> V_59 ) )
return 1 ;
F_33 ( & V_44 -> V_64 ) ;
if ( ! F_27 ( V_44 ) ) {
F_37 ( V_44 , V_66 ) ;
V_11 = 0 ;
}
F_34 ( & V_44 -> V_64 ) ;
return V_11 ;
}
int F_40 ( struct V_43 * V_44 , struct V_55 * V_66 )
{
if ( F_41 ( V_44 -> V_58 ) )
return 1 ;
if ( F_42 ( F_28 ( & V_44 -> V_59 ) ) )
return 0 ;
return ! F_39 ( V_44 , V_66 ) ;
}
int F_43 ( const char * V_1 , T_1 V_67 , T_1 V_17 )
{
struct V_43 * V_44 ;
struct V_5 * V_10 ;
struct V_34 V_68 ;
char V_69 [ 16 ] ;
T_1 V_70 ;
T_1 V_71 ;
T_1 V_6 ;
int V_11 = - V_12 ;
if ( ! V_72 ) {
F_7 ( L_5 ,
V_1 ) ;
return - V_73 ;
}
if ( ! F_16 ( V_1 , & V_68 ) ) {
F_7 ( L_6 , V_1 ) ;
return - V_12 ;
}
if ( F_44 ( V_67 ) &&
( V_67 != V_72 ) ) {
if ( F_45 ( V_67 , V_72 ) ) {
V_67 = V_72 & V_74 ;
V_11 = 0 ;
} else if ( F_46 ( V_67 ) )
V_11 = 0 ;
}
if ( V_11 ) {
F_7 ( L_7 , V_1 ) ;
return - V_12 ;
}
if ( ( V_17 > V_18 ) &&
( V_17 != V_75 ) ) {
F_7 ( L_8 , V_1 ) ;
return - V_12 ;
}
F_5 ( & V_13 ) ;
V_10 = F_2 ( V_68 . V_38 ) ;
if ( ! V_10 ) {
F_7 ( L_9 , V_1 ,
V_68 . V_38 ) ;
goto exit;
}
if ( V_17 == V_75 )
V_17 = V_10 -> V_17 ;
V_76:
V_70 = V_46 ;
V_71 = 1 ;
for ( V_6 = V_46 ; V_6 -- != 0 ; ) {
if ( ! V_45 [ V_6 ] . V_47 ) {
V_70 = V_6 ;
continue;
}
if ( ! strcmp ( V_1 , V_45 [ V_6 ] . V_1 ) ) {
F_7 ( L_10 , V_1 ) ;
goto exit;
}
if ( ( V_45 [ V_6 ] . V_17 == V_17 ) &&
( ++ V_71 > 2 ) ) {
if ( V_17 -- == 0 ) {
F_7 ( L_11 ,
V_1 ) ;
goto exit;
}
F_7 ( L_12 ,
V_1 , V_17 + 1 , V_17 ) ;
goto V_76;
}
}
if ( V_70 >= V_46 ) {
F_7 ( L_13 ,
V_1 , V_46 ) ;
goto exit;
}
V_44 = & V_45 [ V_70 ] ;
strcpy ( V_44 -> V_1 , V_1 ) ;
V_11 = V_10 -> V_77 ( V_44 ) ;
if ( V_11 ) {
F_7 ( L_14 , V_1 , - V_11 ) ;
goto exit;
}
V_44 -> V_78 = V_70 ;
V_44 -> V_50 = V_10 ;
V_44 -> V_19 = V_10 -> V_19 ;
V_44 -> V_79 = V_10 -> V_79 ;
V_44 -> V_80 = V_70 + 'A' ;
V_44 -> V_47 = 1 ;
V_44 -> V_17 = V_17 ;
F_47 ( & V_44 -> V_59 ) ;
F_47 ( & V_44 -> V_63 ) ;
F_48 ( & V_44 -> V_64 ) ;
V_11 = F_49 ( V_44 , & V_10 -> V_14 , V_67 ) ;
if ( V_11 ) {
F_50 ( V_44 ) ;
F_7 ( L_15 ,
V_1 ) ;
goto exit;
}
F_51 ( L_16 ,
V_1 , F_52 ( V_69 , V_67 ) , V_17 ) ;
exit:
F_6 ( & V_13 ) ;
return V_11 ;
}
int F_53 ( const char * V_1 )
{
struct V_43 * V_44 = NULL ;
struct V_55 * V_66 ;
struct V_55 * V_81 ;
F_13 ( & V_13 ) ;
V_44 = F_17 ( V_1 ) ;
if ( ! V_44 ) {
F_7 ( L_17 , V_1 ) ;
F_15 ( & V_13 ) ;
return - V_12 ;
}
F_51 ( L_18 , V_1 ) ;
F_33 ( & V_44 -> V_64 ) ;
V_44 -> V_58 = 1 ;
F_54 ( & V_44 -> V_59 , & V_44 -> V_63 ) ;
F_29 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
struct V_82 * V_83 = V_66 -> V_84 ;
F_33 ( & V_83 -> V_64 ) ;
F_55 ( V_66 ) ;
F_34 ( & V_83 -> V_64 ) ;
}
F_34 ( & V_44 -> V_64 ) ;
F_15 ( & V_13 ) ;
return 0 ;
}
static void F_50 ( struct V_43 * V_44 )
{
struct V_55 * V_66 ;
struct V_55 * V_81 ;
F_51 ( L_19 , V_44 -> V_1 ) ;
F_33 ( & V_44 -> V_64 ) ;
V_44 -> V_58 = 1 ;
V_44 -> V_50 -> V_85 ( V_44 ) ;
F_54 ( & V_44 -> V_59 , & V_44 -> V_63 ) ;
F_29 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
F_56 ( V_66 ) ;
}
if ( V_44 -> V_54 )
F_57 ( V_44 -> V_54 ) ;
F_34 ( & V_44 -> V_64 ) ;
memset ( V_44 , 0 , sizeof( struct V_43 ) ) ;
}
int F_58 ( const char * V_1 )
{
struct V_43 * V_44 ;
int V_11 ;
F_5 ( & V_13 ) ;
V_44 = F_17 ( V_1 ) ;
if ( V_44 == NULL ) {
F_7 ( L_20 , V_1 ) ;
V_11 = - V_12 ;
} else {
F_50 ( V_44 ) ;
V_11 = 0 ;
}
F_6 ( & V_13 ) ;
return V_11 ;
}
void F_59 ( void )
{
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_46 ; V_6 ++ ) {
if ( V_45 [ V_6 ] . V_47 )
F_50 ( & V_45 [ V_6 ] ) ;
}
V_7 = 0 ;
}
