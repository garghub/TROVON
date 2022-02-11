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
if ( ( V_7 -> V_12 . V_13 != V_7 -> V_6 ) ||
! V_7 -> V_12 . V_14 )
goto exit;
if ( V_7 -> V_15 > V_16 )
goto exit;
if ( ( V_7 -> V_17 < V_18 ) ||
( V_7 -> V_17 > V_19 ) )
goto exit;
if ( V_4 >= V_20 )
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
void F_7 ( char * V_21 , int V_22 , struct V_23 * V_24 )
{
char V_25 [ V_26 ] ;
struct V_1 * V_7 ;
int V_27 ;
V_7 = F_2 ( V_24 -> V_13 ) ;
if ( V_7 && ! V_7 -> V_28 ( V_24 , V_25 , sizeof( V_25 ) ) )
V_27 = F_8 ( V_21 , V_22 , L_2 , V_7 -> V_2 , V_25 ) ;
else {
T_1 V_3 ;
V_27 = F_8 ( V_21 , V_22 , L_3 , V_24 -> V_13 ) ;
for ( V_3 = 0 ; V_3 < sizeof( V_24 -> V_29 ) ; V_3 ++ )
V_27 += F_8 ( V_21 - V_27 , V_22 + V_27 ,
L_4 , V_24 -> V_29 [ V_3 ] ) ;
}
}
struct V_30 * F_9 ( void )
{
struct V_30 * V_21 ;
int V_3 ;
V_21 = F_10 ( V_20 * F_11 ( V_11 ) ) ;
if ( ! V_21 )
return NULL ;
F_12 ( & V_10 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_13 ( V_21 , V_31 ,
V_5 [ V_3 ] -> V_2 ,
strlen ( V_5 [ V_3 ] -> V_2 ) + 1 ) ;
}
F_14 ( & V_10 ) ;
return V_21 ;
}
static int F_15 ( const char * V_2 ,
struct V_32 * V_33 )
{
char V_34 [ V_35 ] ;
char * V_36 ;
char * V_37 ;
T_1 V_38 ;
T_1 V_39 ;
V_34 [ V_35 - 1 ] = 0 ;
strncpy ( V_34 , V_2 , V_35 ) ;
if ( V_34 [ V_35 - 1 ] != 0 )
return 0 ;
V_36 = V_34 ;
V_37 = strchr ( V_36 , ':' ) ;
if ( V_37 == NULL )
return 0 ;
* ( V_37 ++ ) = 0 ;
V_38 = V_37 - V_36 ;
V_39 = strlen ( V_37 ) + 1 ;
if ( ( V_38 <= 1 ) || ( V_38 > V_11 ) ||
( V_39 <= 1 ) || ( V_39 > V_40 ) )
return 0 ;
if ( V_33 ) {
strcpy ( V_33 -> V_36 , V_36 ) ;
strcpy ( V_33 -> V_37 , V_37 ) ;
}
return 1 ;
}
struct V_41 * F_16 ( const char * V_2 )
{
struct V_41 * V_42 ;
T_1 V_3 ;
for ( V_3 = 0 , V_42 = V_43 ; V_3 < V_44 ; V_3 ++ , V_42 ++ ) {
if ( V_42 -> V_45 && ( ! strcmp ( V_42 -> V_2 , V_2 ) ) )
return V_42 ;
}
return NULL ;
}
struct V_41 * F_17 ( const char * V_37 )
{
struct V_41 * V_42 ;
char * V_46 ;
T_1 V_3 ;
for ( V_3 = 0 , V_42 = V_43 ; V_3 < V_44 ; V_3 ++ , V_42 ++ ) {
if ( ! V_42 -> V_45 )
continue;
V_46 = strchr ( V_42 -> V_2 , ':' ) + 1 ;
if ( ! strcmp ( V_46 , V_37 ) )
return V_42 ;
}
return NULL ;
}
struct V_30 * F_18 ( void )
{
struct V_30 * V_21 ;
struct V_41 * V_42 ;
int V_3 , V_47 ;
V_21 = F_10 ( V_44 * F_11 ( V_35 ) ) ;
if ( ! V_21 )
return NULL ;
F_12 ( & V_10 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
for ( V_47 = 0 ; V_47 < V_44 ; V_47 ++ ) {
V_42 = & V_43 [ V_47 ] ;
if ( V_42 -> V_45 && ( V_42 -> V_48 == V_5 [ V_3 ] ) ) {
F_13 ( V_21 , V_49 ,
V_42 -> V_2 ,
strlen ( V_42 -> V_2 ) + 1 ) ;
}
}
}
F_14 ( & V_10 ) ;
return V_21 ;
}
void F_19 ( struct V_41 * V_42 , T_1 V_50 )
{
F_20 ( & V_42 -> V_51 , V_50 ) ;
F_21 () ;
F_22 ( V_42 -> V_52 ) ;
}
void F_23 ( struct V_41 * V_42 , T_1 V_50 )
{
F_24 ( & V_42 -> V_51 , V_50 ) ;
F_21 () ;
F_25 ( V_42 -> V_52 ) ;
}
static int F_26 ( struct V_41 * V_42 )
{
T_1 V_8 = 0 ;
struct V_53 * V_54 , * V_55 ;
if ( V_42 -> V_56 )
return 0 ;
while ( ! F_27 ( & V_42 -> V_57 ) && ( V_8 != V_58 ) ) {
F_28 (ln, tln, &b_ptr->cong_links, link_list) {
V_8 = F_29 ( V_54 ) ;
if ( V_8 == V_58 )
break;
if ( V_8 == V_59 )
F_30 ( & V_54 -> V_60 , & V_42 -> V_61 ) ;
}
}
return F_27 ( & V_42 -> V_57 ) ;
}
void F_31 ( struct V_41 * V_42 )
{
F_32 ( & V_42 -> V_62 ) ;
F_26 ( V_42 ) ;
F_33 ( & V_42 -> V_62 ) ;
}
void F_34 ( struct V_41 * V_42 )
{
F_32 ( & V_42 -> V_62 ) ;
if ( ! F_27 ( & V_42 -> V_57 ) )
F_35 ( ( V_63 ) F_31 , ( unsigned long ) V_42 ) ;
V_42 -> V_56 = 0 ;
F_33 ( & V_42 -> V_62 ) ;
}
static void F_36 ( struct V_41 * V_42 ,
struct V_53 * V_64 )
{
F_30 ( & V_64 -> V_60 , & V_42 -> V_57 ) ;
}
void F_37 ( struct V_41 * V_42 , struct V_53 * V_64 )
{
F_32 ( & V_42 -> V_62 ) ;
F_36 ( V_42 , V_64 ) ;
F_33 ( & V_42 -> V_62 ) ;
}
int F_38 ( struct V_41 * V_42 ,
struct V_53 * V_64 )
{
int V_8 = 1 ;
if ( F_27 ( & V_42 -> V_57 ) )
return 1 ;
F_32 ( & V_42 -> V_62 ) ;
if ( ! F_26 ( V_42 ) ) {
F_36 ( V_42 , V_64 ) ;
V_8 = 0 ;
}
F_33 ( & V_42 -> V_62 ) ;
return V_8 ;
}
int F_39 ( struct V_41 * V_42 , struct V_53 * V_64 )
{
if ( F_40 ( V_42 -> V_56 ) )
return 1 ;
if ( F_41 ( F_27 ( & V_42 -> V_57 ) ) )
return 0 ;
return ! F_38 ( V_42 , V_64 ) ;
}
int F_42 ( const char * V_2 , T_1 V_65 , T_1 V_15 )
{
struct V_41 * V_42 ;
struct V_1 * V_7 ;
struct V_32 V_66 ;
char V_67 [ 16 ] ;
T_1 V_68 ;
T_1 V_69 ;
T_1 V_3 ;
int V_8 = - V_9 ;
if ( ! V_70 ) {
F_6 ( L_5 ,
V_2 ) ;
return - V_71 ;
}
if ( ! F_15 ( V_2 , & V_66 ) ) {
F_6 ( L_6 , V_2 ) ;
return - V_9 ;
}
if ( F_43 ( V_65 ) &&
( V_65 != V_70 ) ) {
if ( F_44 ( V_65 , V_70 ) ) {
V_65 = V_70 & V_72 ;
V_8 = 0 ;
} else if ( F_45 ( V_65 ) )
V_8 = 0 ;
}
if ( V_8 ) {
F_6 ( L_7 ,
V_2 ) ;
return - V_9 ;
}
if ( ( V_15 > V_16 ) &&
( V_15 != V_73 ) ) {
F_6 ( L_8 , V_2 ) ;
return - V_9 ;
}
F_4 ( & V_10 ) ;
V_7 = F_1 ( V_66 . V_36 ) ;
if ( ! V_7 ) {
F_6 ( L_9 ,
V_2 , V_66 . V_36 ) ;
goto exit;
}
if ( V_15 == V_73 )
V_15 = V_7 -> V_15 ;
V_74:
V_68 = V_44 ;
V_69 = 1 ;
for ( V_3 = V_44 ; V_3 -- != 0 ; ) {
if ( ! V_43 [ V_3 ] . V_45 ) {
V_68 = V_3 ;
continue;
}
if ( ! strcmp ( V_2 , V_43 [ V_3 ] . V_2 ) ) {
F_6 ( L_10 ,
V_2 ) ;
goto exit;
}
if ( ( V_43 [ V_3 ] . V_15 == V_15 ) &&
( ++ V_69 > 2 ) ) {
if ( V_15 -- == 0 ) {
F_6 ( L_11 ,
V_2 ) ;
goto exit;
}
F_6 ( L_12 ,
V_2 , V_15 + 1 , V_15 ) ;
goto V_74;
}
}
if ( V_68 >= V_44 ) {
F_6 ( L_13 ,
V_2 , V_44 ) ;
goto exit;
}
V_42 = & V_43 [ V_68 ] ;
strcpy ( V_42 -> V_2 , V_2 ) ;
V_8 = V_7 -> V_75 ( V_42 ) ;
if ( V_8 ) {
F_6 ( L_14 ,
V_2 , - V_8 ) ;
goto exit;
}
V_42 -> V_76 = V_68 ;
V_42 -> V_48 = V_7 ;
V_42 -> V_17 = V_7 -> V_17 ;
V_42 -> V_77 = V_7 -> V_77 ;
V_42 -> V_78 = V_68 + 'A' ;
V_42 -> V_45 = 1 ;
V_42 -> V_15 = V_15 ;
F_46 ( & V_42 -> V_57 ) ;
F_46 ( & V_42 -> V_61 ) ;
F_47 ( & V_42 -> V_62 ) ;
V_8 = F_48 ( V_42 , & V_7 -> V_12 , V_65 ) ;
if ( V_8 ) {
F_49 ( V_42 ) ;
F_6 ( L_15 ,
V_2 ) ;
goto exit;
}
F_50 ( L_16 ,
V_2 ,
F_51 ( V_67 , V_65 ) , V_15 ) ;
exit:
F_5 ( & V_10 ) ;
return V_8 ;
}
int F_52 ( const char * V_2 )
{
struct V_41 * V_42 = NULL ;
struct V_53 * V_64 ;
struct V_53 * V_79 ;
F_12 ( & V_10 ) ;
V_42 = F_16 ( V_2 ) ;
if ( ! V_42 ) {
F_6 ( L_17 , V_2 ) ;
F_14 ( & V_10 ) ;
return - V_9 ;
}
F_50 ( L_18 , V_2 ) ;
F_32 ( & V_42 -> V_62 ) ;
V_42 -> V_56 = 1 ;
F_53 ( & V_42 -> V_57 , & V_42 -> V_61 ) ;
F_28 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
struct V_80 * V_81 = V_64 -> V_82 ;
F_32 ( & V_81 -> V_62 ) ;
F_54 ( V_64 ) ;
F_33 ( & V_81 -> V_62 ) ;
}
F_33 ( & V_42 -> V_62 ) ;
F_14 ( & V_10 ) ;
return 0 ;
}
static void F_49 ( struct V_41 * V_42 )
{
struct V_53 * V_64 ;
struct V_53 * V_79 ;
F_50 ( L_19 , V_42 -> V_2 ) ;
F_32 ( & V_42 -> V_62 ) ;
V_42 -> V_56 = 1 ;
V_42 -> V_48 -> V_83 ( V_42 ) ;
F_53 ( & V_42 -> V_57 , & V_42 -> V_61 ) ;
F_28 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
F_55 ( V_64 ) ;
}
if ( V_42 -> V_52 )
F_56 ( V_42 -> V_52 ) ;
F_33 ( & V_42 -> V_62 ) ;
memset ( V_42 , 0 , sizeof( struct V_41 ) ) ;
}
int F_57 ( const char * V_2 )
{
struct V_41 * V_42 ;
int V_8 ;
F_4 ( & V_10 ) ;
V_42 = F_16 ( V_2 ) ;
if ( V_42 == NULL ) {
F_6 ( L_20 , V_2 ) ;
V_8 = - V_9 ;
} else {
F_49 ( V_42 ) ;
V_8 = 0 ;
}
F_5 ( & V_10 ) ;
return V_8 ;
}
void F_58 ( void )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ ) {
if ( V_43 [ V_3 ] . V_45 )
F_49 ( & V_43 [ V_3 ] ) ;
}
V_4 = 0 ;
}
