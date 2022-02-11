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
void F_8 ( char * V_23 , int V_2 , struct V_24 * V_25 )
{
char V_26 [ V_27 ] ;
struct V_5 * V_10 ;
int V_28 ;
V_10 = F_3 ( V_25 -> V_15 ) ;
if ( V_10 && ! V_10 -> V_29 ( V_25 , V_26 , sizeof( V_26 ) ) )
V_28 = F_9 ( V_23 , V_2 , L_2 , V_10 -> V_1 , V_26 ) ;
else {
T_1 V_6 ;
V_28 = F_9 ( V_23 , V_2 , L_3 , V_25 -> V_15 ) ;
for ( V_6 = 0 ; V_6 < sizeof( V_25 -> V_30 ) ; V_6 ++ )
V_28 += F_9 ( V_23 - V_28 , V_2 + V_28 ,
L_4 , V_25 -> V_30 [ V_6 ] ) ;
}
}
struct V_31 * F_10 ( void )
{
struct V_31 * V_23 ;
int V_6 ;
V_23 = F_11 ( V_22 * F_12 ( V_3 ) ) ;
if ( ! V_23 )
return NULL ;
F_13 ( & V_13 ) ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
F_14 ( V_23 , V_32 ,
V_8 [ V_6 ] -> V_1 ,
strlen ( V_8 [ V_6 ] -> V_1 ) + 1 ) ;
}
F_15 ( & V_13 ) ;
return V_23 ;
}
static int F_16 ( const char * V_1 ,
struct V_33 * V_34 )
{
char V_35 [ V_36 ] ;
char * V_37 ;
char * V_38 ;
T_1 V_39 ;
T_1 V_40 ;
V_35 [ V_36 - 1 ] = 0 ;
strncpy ( V_35 , V_1 , V_36 ) ;
if ( V_35 [ V_36 - 1 ] != 0 )
return 0 ;
V_37 = V_35 ;
V_38 = strchr ( V_37 , ':' ) ;
if ( V_38 == NULL )
return 0 ;
* ( V_38 ++ ) = 0 ;
V_39 = V_38 - V_37 ;
V_40 = strlen ( V_38 ) + 1 ;
if ( ( V_39 <= 1 ) || ( V_39 > V_3 ) ||
( V_40 <= 1 ) || ( V_40 > V_41 ) ||
( strspn ( V_37 , V_4 ) != ( V_39 - 1 ) ) ||
( strspn ( V_38 , V_4 ) != ( V_40 - 1 ) ) )
return 0 ;
if ( V_34 ) {
strcpy ( V_34 -> V_37 , V_37 ) ;
strcpy ( V_34 -> V_38 , V_38 ) ;
}
return 1 ;
}
struct V_42 * F_17 ( const char * V_1 )
{
struct V_42 * V_43 ;
T_1 V_6 ;
for ( V_6 = 0 , V_43 = V_44 ; V_6 < V_45 ; V_6 ++ , V_43 ++ ) {
if ( V_43 -> V_46 && ( ! strcmp ( V_43 -> V_1 , V_1 ) ) )
return V_43 ;
}
return NULL ;
}
struct V_42 * F_18 ( const char * V_38 )
{
struct V_42 * V_43 ;
char * V_47 ;
T_1 V_6 ;
for ( V_6 = 0 , V_43 = V_44 ; V_6 < V_45 ; V_6 ++ , V_43 ++ ) {
if ( ! V_43 -> V_46 )
continue;
V_47 = strchr ( V_43 -> V_1 , ':' ) + 1 ;
if ( ! strcmp ( V_47 , V_38 ) )
return V_43 ;
}
return NULL ;
}
struct V_31 * F_19 ( void )
{
struct V_31 * V_23 ;
struct V_42 * V_43 ;
int V_6 , V_48 ;
V_23 = F_11 ( V_45 * F_12 ( V_36 ) ) ;
if ( ! V_23 )
return NULL ;
F_13 ( & V_13 ) ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
for ( V_48 = 0 ; V_48 < V_45 ; V_48 ++ ) {
V_43 = & V_44 [ V_48 ] ;
if ( V_43 -> V_46 && ( V_43 -> V_49 == V_8 [ V_6 ] ) ) {
F_14 ( V_23 , V_50 ,
V_43 -> V_1 ,
strlen ( V_43 -> V_1 ) + 1 ) ;
}
}
}
F_15 ( & V_13 ) ;
return V_23 ;
}
void F_20 ( struct V_42 * V_43 , T_1 V_51 )
{
F_21 ( & V_43 -> V_52 , V_51 ) ;
F_22 () ;
F_23 ( V_43 -> V_53 ) ;
}
void F_24 ( struct V_42 * V_43 , T_1 V_51 )
{
F_25 ( & V_43 -> V_52 , V_51 ) ;
F_22 () ;
F_26 ( V_43 -> V_53 ) ;
}
static int F_27 ( struct V_42 * V_43 )
{
T_1 V_11 = 0 ;
struct V_54 * V_55 , * V_56 ;
if ( V_43 -> V_57 )
return 0 ;
while ( ! F_28 ( & V_43 -> V_58 ) && ( V_11 != V_59 ) ) {
F_29 (ln, tln, &b_ptr->cong_links, link_list) {
V_11 = F_30 ( V_55 ) ;
if ( V_11 == V_59 )
break;
if ( V_11 == V_60 )
F_31 ( & V_55 -> V_61 , & V_43 -> V_62 ) ;
}
}
return F_28 ( & V_43 -> V_58 ) ;
}
void F_32 ( struct V_42 * V_43 )
{
F_33 ( & V_43 -> V_63 ) ;
F_27 ( V_43 ) ;
F_34 ( & V_43 -> V_63 ) ;
}
void F_35 ( struct V_42 * V_43 )
{
F_33 ( & V_43 -> V_63 ) ;
if ( ! F_28 ( & V_43 -> V_58 ) )
F_36 ( ( V_64 ) F_32 , ( unsigned long ) V_43 ) ;
V_43 -> V_57 = 0 ;
F_34 ( & V_43 -> V_63 ) ;
}
static void F_37 ( struct V_42 * V_43 ,
struct V_54 * V_65 )
{
F_31 ( & V_65 -> V_61 , & V_43 -> V_58 ) ;
}
void F_38 ( struct V_42 * V_43 , struct V_54 * V_65 )
{
F_33 ( & V_43 -> V_63 ) ;
F_37 ( V_43 , V_65 ) ;
F_34 ( & V_43 -> V_63 ) ;
}
int F_39 ( struct V_42 * V_43 ,
struct V_54 * V_65 )
{
int V_11 = 1 ;
if ( F_28 ( & V_43 -> V_58 ) )
return 1 ;
F_33 ( & V_43 -> V_63 ) ;
if ( ! F_27 ( V_43 ) ) {
F_37 ( V_43 , V_65 ) ;
V_11 = 0 ;
}
F_34 ( & V_43 -> V_63 ) ;
return V_11 ;
}
int F_40 ( struct V_42 * V_43 , struct V_54 * V_65 )
{
if ( F_41 ( V_43 -> V_57 ) )
return 1 ;
if ( F_42 ( F_28 ( & V_43 -> V_58 ) ) )
return 0 ;
return ! F_39 ( V_43 , V_65 ) ;
}
int F_43 ( const char * V_1 , T_1 V_66 , T_1 V_17 )
{
struct V_42 * V_43 ;
struct V_5 * V_10 ;
struct V_33 V_67 ;
char V_68 [ 16 ] ;
T_1 V_69 ;
T_1 V_70 ;
T_1 V_6 ;
int V_11 = - V_12 ;
if ( ! V_71 ) {
F_7 ( L_5 ,
V_1 ) ;
return - V_72 ;
}
if ( ! F_16 ( V_1 , & V_67 ) ) {
F_7 ( L_6 , V_1 ) ;
return - V_12 ;
}
if ( F_44 ( V_66 ) &&
( V_66 != V_71 ) ) {
if ( F_45 ( V_66 , V_71 ) ) {
V_66 = V_71 & V_73 ;
V_11 = 0 ;
} else if ( F_46 ( V_66 ) )
V_11 = 0 ;
}
if ( V_11 ) {
F_7 ( L_7 ,
V_1 ) ;
return - V_12 ;
}
if ( ( V_17 > V_18 ) &&
( V_17 != V_74 ) ) {
F_7 ( L_8 , V_1 ) ;
return - V_12 ;
}
F_5 ( & V_13 ) ;
V_10 = F_2 ( V_67 . V_37 ) ;
if ( ! V_10 ) {
F_7 ( L_9 ,
V_1 , V_67 . V_37 ) ;
goto exit;
}
if ( V_17 == V_74 )
V_17 = V_10 -> V_17 ;
V_75:
V_69 = V_45 ;
V_70 = 1 ;
for ( V_6 = V_45 ; V_6 -- != 0 ; ) {
if ( ! V_44 [ V_6 ] . V_46 ) {
V_69 = V_6 ;
continue;
}
if ( ! strcmp ( V_1 , V_44 [ V_6 ] . V_1 ) ) {
F_7 ( L_10 ,
V_1 ) ;
goto exit;
}
if ( ( V_44 [ V_6 ] . V_17 == V_17 ) &&
( ++ V_70 > 2 ) ) {
if ( V_17 -- == 0 ) {
F_7 ( L_11 ,
V_1 ) ;
goto exit;
}
F_7 ( L_12 ,
V_1 , V_17 + 1 , V_17 ) ;
goto V_75;
}
}
if ( V_69 >= V_45 ) {
F_7 ( L_13 ,
V_1 , V_45 ) ;
goto exit;
}
V_43 = & V_44 [ V_69 ] ;
strcpy ( V_43 -> V_1 , V_1 ) ;
V_11 = V_10 -> V_76 ( V_43 ) ;
if ( V_11 ) {
F_7 ( L_14 ,
V_1 , - V_11 ) ;
goto exit;
}
V_43 -> V_77 = V_69 ;
V_43 -> V_49 = V_10 ;
V_43 -> V_19 = V_10 -> V_19 ;
V_43 -> V_78 = V_10 -> V_78 ;
V_43 -> V_79 = V_69 + 'A' ;
V_43 -> V_46 = 1 ;
V_43 -> V_17 = V_17 ;
F_47 ( & V_43 -> V_58 ) ;
F_47 ( & V_43 -> V_62 ) ;
F_48 ( & V_43 -> V_63 ) ;
V_11 = F_49 ( V_43 , & V_10 -> V_14 , V_66 ) ;
if ( V_11 ) {
F_50 ( V_43 ) ;
F_7 ( L_15 ,
V_1 ) ;
goto exit;
}
F_51 ( L_16 ,
V_1 ,
F_52 ( V_68 , V_66 ) , V_17 ) ;
exit:
F_6 ( & V_13 ) ;
return V_11 ;
}
int F_53 ( const char * V_1 )
{
struct V_42 * V_43 = NULL ;
struct V_54 * V_65 ;
struct V_54 * V_80 ;
F_13 ( & V_13 ) ;
V_43 = F_17 ( V_1 ) ;
if ( ! V_43 ) {
F_7 ( L_17 , V_1 ) ;
F_15 ( & V_13 ) ;
return - V_12 ;
}
F_51 ( L_18 , V_1 ) ;
F_33 ( & V_43 -> V_63 ) ;
V_43 -> V_57 = 1 ;
F_54 ( & V_43 -> V_58 , & V_43 -> V_62 ) ;
F_29 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
struct V_81 * V_82 = V_65 -> V_83 ;
F_33 ( & V_82 -> V_63 ) ;
F_55 ( V_65 ) ;
F_34 ( & V_82 -> V_63 ) ;
}
F_34 ( & V_43 -> V_63 ) ;
F_15 ( & V_13 ) ;
return 0 ;
}
static void F_50 ( struct V_42 * V_43 )
{
struct V_54 * V_65 ;
struct V_54 * V_80 ;
F_51 ( L_19 , V_43 -> V_1 ) ;
F_33 ( & V_43 -> V_63 ) ;
V_43 -> V_57 = 1 ;
V_43 -> V_49 -> V_84 ( V_43 ) ;
F_54 ( & V_43 -> V_58 , & V_43 -> V_62 ) ;
F_29 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
F_56 ( V_65 ) ;
}
if ( V_43 -> V_53 )
F_57 ( V_43 -> V_53 ) ;
F_34 ( & V_43 -> V_63 ) ;
memset ( V_43 , 0 , sizeof( struct V_42 ) ) ;
}
int F_58 ( const char * V_1 )
{
struct V_42 * V_43 ;
int V_11 ;
F_5 ( & V_13 ) ;
V_43 = F_17 ( V_1 ) ;
if ( V_43 == NULL ) {
F_7 ( L_20 , V_1 ) ;
V_11 = - V_12 ;
} else {
F_50 ( V_43 ) ;
V_11 = 0 ;
}
F_6 ( & V_13 ) ;
return V_11 ;
}
void F_59 ( void )
{
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_45 ; V_6 ++ ) {
if ( V_44 [ V_6 ] . V_46 )
F_50 ( & V_44 [ V_6 ] ) ;
}
V_7 = 0 ;
}
