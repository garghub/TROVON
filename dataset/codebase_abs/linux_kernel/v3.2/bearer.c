static int F_1 ( const char * V_1 )
{
T_1 V_2 ;
V_2 = strlen ( V_1 ) ;
if ( ( V_2 + 1 ) > V_3 )
return 0 ;
return strspn ( V_1 , V_4 ) == V_2 ;
}
static struct V_5 * F_2 ( const char * V_1 )
{
struct V_5 * V_6 ;
T_1 V_7 ;
for ( V_7 = 0 , V_6 = V_8 ; V_7 < V_9 ; V_7 ++ , V_6 ++ ) {
if ( ! strcmp ( V_6 -> V_1 , V_1 ) )
return V_6 ;
}
return NULL ;
}
int F_3 ( T_1 V_10 ,
char * V_1 ,
int (* F_4)( struct V_11 * ) ,
void (* F_5)( struct V_11 * ) ,
int (* F_6)( struct V_12 * ,
struct V_11 * ,
struct V_13 * ) ,
char * (* F_7)( struct V_13 * V_14 ,
char * V_15 , int V_16 ) ,
struct V_13 * V_17 ,
const T_1 V_18 ,
const T_1 V_19 ,
const T_1 V_20 )
{
struct V_5 * V_6 ;
T_1 V_21 ;
T_1 V_7 ;
int V_22 = - V_23 ;
F_8 ( & V_24 ) ;
if ( V_25 != V_26 ) {
F_9 ( L_1 , V_1 ) ;
goto exit;
}
if ( ! F_1 ( V_1 ) ) {
F_9 ( L_2 , V_1 ) ;
goto exit;
}
if ( ! V_17 ) {
F_9 ( L_3 , V_1 ) ;
goto exit;
}
if ( ( V_18 < V_27 ) ||
( V_18 > V_28 ) ) {
F_9 ( L_4 , V_1 ,
V_18 ) ;
goto exit;
}
if ( ( V_19 < V_29 ) ||
( V_19 > V_30 ) ) {
F_9 ( L_5 , V_1 ,
V_19 ) ;
goto exit;
}
V_21 = V_9 ++ ;
if ( V_21 >= V_31 ) {
F_9 ( L_6 , V_1 ,
V_31 ) ;
V_9 -- ;
goto exit;
}
for ( V_7 = 0 ; V_7 < V_21 ; V_7 ++ ) {
if ( V_8 [ V_7 ] . V_32 == V_10 ) {
F_9 ( L_7 , V_1 ,
V_10 ) ;
V_9 -- ;
goto exit;
}
if ( ! strcmp ( V_1 , V_8 [ V_7 ] . V_1 ) ) {
F_9 ( L_8 , V_1 ) ;
V_9 -- ;
goto exit;
}
}
V_6 = & V_8 [ V_21 ] ;
V_6 -> V_32 = V_10 ;
V_6 -> F_6 = F_6 ;
V_6 -> V_33 = F_4 ;
V_6 -> V_34 = F_5 ;
V_6 -> F_7 = F_7 ;
memcpy ( & V_6 -> V_17 , V_17 , sizeof( * V_17 ) ) ;
strcpy ( V_6 -> V_1 , V_1 ) ;
V_6 -> V_35 = V_18 ;
V_6 -> V_36 = V_19 ;
V_6 -> V_37 = V_20 ;
V_22 = 0 ;
exit:
F_10 ( & V_24 ) ;
return V_22 ;
}
void F_11 ( struct V_38 * V_39 , struct V_13 * V_14 )
{
struct V_5 * V_6 ;
T_1 V_10 ;
T_1 V_7 ;
V_10 = F_12 ( V_14 -> type ) ;
for ( V_7 = 0 , V_6 = V_8 ; V_7 < V_9 ; V_7 ++ , V_6 ++ ) {
if ( V_6 -> V_32 == V_10 )
break;
}
if ( ( V_7 < V_9 ) && ( V_6 -> F_7 != NULL ) ) {
char V_40 [ V_41 ] ;
F_13 ( V_39 , L_9 , V_6 -> V_1 ,
V_6 -> F_7 ( V_14 , V_40 , sizeof( V_40 ) ) ) ;
} else {
T_2 * V_42 = ( T_2 * ) & V_14 -> V_43 ;
F_13 ( V_39 , L_10 , V_10 ) ;
for ( V_7 = 0 ; V_7 < ( sizeof( * V_14 ) - sizeof( V_14 -> type ) ) ; V_7 ++ )
F_13 ( V_39 , L_11 , V_42 [ V_7 ] ) ;
}
}
struct V_12 * F_14 ( void )
{
struct V_12 * V_44 ;
struct V_5 * V_6 ;
int V_7 ;
V_44 = F_15 ( V_31 * F_16 ( V_3 ) ) ;
if ( ! V_44 )
return NULL ;
F_17 ( & V_24 ) ;
for ( V_7 = 0 , V_6 = V_8 ; V_7 < V_9 ; V_7 ++ , V_6 ++ ) {
F_18 ( V_44 , V_45 , V_6 -> V_1 ,
strlen ( V_6 -> V_1 ) + 1 ) ;
}
F_19 ( & V_24 ) ;
return V_44 ;
}
static int F_20 ( const char * V_1 ,
struct V_46 * V_47 )
{
char V_48 [ V_49 ] ;
char * V_50 ;
char * V_51 ;
T_1 V_52 ;
T_1 V_53 ;
V_48 [ V_49 - 1 ] = 0 ;
strncpy ( V_48 , V_1 , V_49 ) ;
if ( V_48 [ V_49 - 1 ] != 0 )
return 0 ;
V_50 = V_48 ;
V_51 = strchr ( V_50 , ':' ) ;
if ( V_51 == NULL )
return 0 ;
* ( V_51 ++ ) = 0 ;
V_52 = V_51 - V_50 ;
V_53 = strlen ( V_51 ) + 1 ;
if ( ( V_52 <= 1 ) || ( V_52 > V_3 ) ||
( V_53 <= 1 ) || ( V_53 > V_54 ) ||
( strspn ( V_50 , V_4 ) != ( V_52 - 1 ) ) ||
( strspn ( V_51 , V_4 ) != ( V_53 - 1 ) ) )
return 0 ;
if ( V_47 ) {
strcpy ( V_47 -> V_50 , V_50 ) ;
strcpy ( V_47 -> V_51 , V_51 ) ;
}
return 1 ;
}
static struct V_11 * F_21 ( const char * V_1 )
{
struct V_11 * V_55 ;
T_1 V_7 ;
for ( V_7 = 0 , V_55 = V_56 ; V_7 < V_57 ; V_7 ++ , V_55 ++ ) {
if ( V_55 -> V_58 && ( ! strcmp ( V_55 -> V_1 , V_1 ) ) )
return V_55 ;
}
return NULL ;
}
struct V_11 * F_22 ( const char * V_51 )
{
struct V_11 * V_55 ;
char * V_59 ;
T_1 V_7 ;
for ( V_7 = 0 , V_55 = V_56 ; V_7 < V_57 ; V_7 ++ , V_55 ++ ) {
if ( ! V_55 -> V_58 )
continue;
V_59 = strchr ( V_55 -> V_1 , ':' ) + 1 ;
if ( ! strcmp ( V_59 , V_51 ) )
return V_55 ;
}
return NULL ;
}
struct V_12 * F_23 ( void )
{
struct V_12 * V_44 ;
struct V_5 * V_6 ;
struct V_11 * V_55 ;
int V_7 , V_60 ;
V_44 = F_15 ( V_57 * F_16 ( V_49 ) ) ;
if ( ! V_44 )
return NULL ;
F_17 ( & V_24 ) ;
for ( V_7 = 0 , V_6 = V_8 ; V_7 < V_9 ; V_7 ++ , V_6 ++ ) {
for ( V_60 = 0 ; V_60 < V_57 ; V_60 ++ ) {
V_55 = & V_56 [ V_60 ] ;
if ( V_55 -> V_58 && ( V_55 -> V_5 == V_6 ) ) {
F_18 ( V_44 , V_61 ,
V_55 -> V_1 ,
strlen ( V_55 -> V_1 ) + 1 ) ;
}
}
}
F_19 ( & V_24 ) ;
return V_44 ;
}
void F_24 ( struct V_11 * V_55 , T_1 V_62 )
{
F_25 ( & V_55 -> V_63 , V_62 ) ;
F_26 () ;
F_27 ( V_55 -> V_64 ) ;
}
void F_28 ( struct V_11 * V_55 , T_1 V_62 )
{
F_29 ( & V_55 -> V_63 , V_62 ) ;
F_26 () ;
F_30 ( V_55 -> V_64 ) ;
}
static int F_31 ( struct V_11 * V_55 )
{
T_1 V_22 = 0 ;
struct V_65 * V_66 , * V_67 ;
if ( V_55 -> V_68 )
return 0 ;
while ( ! F_32 ( & V_55 -> V_69 ) && ( V_22 != V_70 ) ) {
F_33 (ln, tln, &b_ptr->cong_links, link_list) {
V_22 = F_34 ( V_66 ) ;
if ( V_22 == V_70 )
break;
if ( V_22 == V_71 )
F_35 ( & V_66 -> V_72 , & V_55 -> V_73 ) ;
}
}
return F_32 ( & V_55 -> V_69 ) ;
}
void F_36 ( struct V_11 * V_55 )
{
F_37 ( & V_55 -> V_74 ) ;
F_31 ( V_55 ) ;
F_38 ( & V_55 -> V_74 ) ;
}
void F_39 ( struct V_11 * V_55 )
{
F_37 ( & V_55 -> V_74 ) ;
if ( ! F_32 ( & V_55 -> V_69 ) )
F_40 ( ( V_75 ) F_36 , ( unsigned long ) V_55 ) ;
V_55 -> V_68 = 0 ;
F_38 ( & V_55 -> V_74 ) ;
}
static void F_41 ( struct V_11 * V_55 , struct V_65 * V_76 )
{
F_35 ( & V_76 -> V_72 , & V_55 -> V_69 ) ;
}
void F_42 ( struct V_11 * V_55 , struct V_65 * V_76 )
{
F_37 ( & V_55 -> V_74 ) ;
F_41 ( V_55 , V_76 ) ;
F_38 ( & V_55 -> V_74 ) ;
}
int F_43 ( struct V_11 * V_55 , struct V_65 * V_76 )
{
int V_22 = 1 ;
if ( F_32 ( & V_55 -> V_69 ) )
return 1 ;
F_37 ( & V_55 -> V_74 ) ;
if ( ! F_31 ( V_55 ) ) {
F_41 ( V_55 , V_76 ) ;
V_22 = 0 ;
}
F_38 ( & V_55 -> V_74 ) ;
return V_22 ;
}
int F_44 ( struct V_11 * V_55 , struct V_65 * V_76 )
{
if ( F_45 ( V_55 -> V_68 ) )
return 1 ;
if ( F_46 ( F_32 ( & V_55 -> V_69 ) ) )
return 0 ;
return ! F_43 ( V_55 , V_76 ) ;
}
int F_47 ( const char * V_1 , T_1 V_77 , T_1 V_35 )
{
struct V_11 * V_55 ;
struct V_5 * V_6 ;
struct V_46 V_78 ;
char V_79 [ 16 ] ;
T_1 V_80 ;
T_1 V_81 ;
T_1 V_7 ;
int V_22 = - V_23 ;
if ( V_25 != V_26 ) {
F_9 ( L_12 ,
V_1 ) ;
return - V_82 ;
}
if ( ! F_20 ( V_1 , & V_78 ) ) {
F_9 ( L_13 , V_1 ) ;
return - V_23 ;
}
if ( F_48 ( V_77 ) &&
( V_77 != V_83 ) ) {
if ( F_49 ( V_77 , V_83 ) ) {
V_77 = V_83 & V_84 ;
V_22 = 0 ;
} else if ( F_50 ( V_77 ) )
V_22 = 0 ;
}
if ( V_22 ) {
F_9 ( L_14 , V_1 ) ;
return - V_23 ;
}
if ( ( V_35 < V_27 ||
V_35 > V_28 ) &&
( V_35 != V_85 ) ) {
F_9 ( L_15 , V_1 ) ;
return - V_23 ;
}
F_8 ( & V_24 ) ;
V_6 = F_2 ( V_78 . V_50 ) ;
if ( ! V_6 ) {
F_9 ( L_16 , V_1 ,
V_78 . V_50 ) ;
goto exit;
}
if ( V_35 == V_85 )
V_35 = V_6 -> V_35 ;
V_86:
V_80 = V_57 ;
V_81 = 1 ;
for ( V_7 = V_57 ; V_7 -- != 0 ; ) {
if ( ! V_56 [ V_7 ] . V_58 ) {
V_80 = V_7 ;
continue;
}
if ( ! strcmp ( V_1 , V_56 [ V_7 ] . V_1 ) ) {
F_9 ( L_17 , V_1 ) ;
goto exit;
}
if ( ( V_56 [ V_7 ] . V_35 == V_35 ) &&
( ++ V_81 > 2 ) ) {
if ( V_35 -- == 0 ) {
F_9 ( L_18 ,
V_1 ) ;
goto exit;
}
F_9 ( L_19 ,
V_1 , V_35 + 1 , V_35 ) ;
goto V_86;
}
}
if ( V_80 >= V_57 ) {
F_9 ( L_20 ,
V_1 , V_57 ) ;
goto exit;
}
V_55 = & V_56 [ V_80 ] ;
strcpy ( V_55 -> V_1 , V_1 ) ;
V_22 = V_6 -> V_33 ( V_55 ) ;
if ( V_22 ) {
F_9 ( L_21 , V_1 , - V_22 ) ;
goto exit;
}
V_55 -> V_87 = V_80 ;
V_55 -> V_5 = V_6 ;
V_55 -> V_88 = V_80 + 'A' ;
V_55 -> V_58 = 1 ;
V_55 -> V_35 = V_35 ;
F_51 ( & V_55 -> V_69 ) ;
F_51 ( & V_55 -> V_73 ) ;
F_52 ( & V_55 -> V_74 ) ;
V_22 = F_53 ( V_55 , & V_6 -> V_17 , V_77 ) ;
if ( V_22 ) {
F_54 ( V_55 ) ;
F_9 ( L_22 ,
V_1 ) ;
goto exit;
}
F_55 ( L_23 ,
V_1 , F_56 ( V_79 , V_77 ) , V_35 ) ;
exit:
F_10 ( & V_24 ) ;
return V_22 ;
}
int F_57 ( const char * V_1 )
{
struct V_11 * V_55 = NULL ;
struct V_65 * V_76 ;
struct V_65 * V_89 ;
F_17 ( & V_24 ) ;
V_55 = F_21 ( V_1 ) ;
if ( ! V_55 ) {
F_9 ( L_24 , V_1 ) ;
F_19 ( & V_24 ) ;
return - V_23 ;
}
F_55 ( L_25 , V_1 ) ;
F_37 ( & V_55 -> V_74 ) ;
V_55 -> V_68 = 1 ;
F_58 ( & V_55 -> V_69 , & V_55 -> V_73 ) ;
F_33 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
struct V_90 * V_91 = V_76 -> V_92 ;
F_37 ( & V_91 -> V_74 ) ;
F_59 ( V_76 ) ;
F_38 ( & V_91 -> V_74 ) ;
}
F_38 ( & V_55 -> V_74 ) ;
F_19 ( & V_24 ) ;
return 0 ;
}
static void F_54 ( struct V_11 * V_55 )
{
struct V_65 * V_76 ;
struct V_65 * V_89 ;
F_55 ( L_26 , V_55 -> V_1 ) ;
F_37 ( & V_55 -> V_74 ) ;
V_55 -> V_68 = 1 ;
V_55 -> V_5 -> V_34 ( V_55 ) ;
F_58 ( & V_55 -> V_69 , & V_55 -> V_73 ) ;
F_33 (l_ptr, temp_l_ptr, &b_ptr->links, link_list) {
F_60 ( V_76 ) ;
}
if ( V_55 -> V_64 )
F_61 ( V_55 -> V_64 ) ;
F_38 ( & V_55 -> V_74 ) ;
memset ( V_55 , 0 , sizeof( struct V_11 ) ) ;
}
int F_62 ( const char * V_1 )
{
struct V_11 * V_55 ;
int V_22 ;
F_8 ( & V_24 ) ;
V_55 = F_21 ( V_1 ) ;
if ( V_55 == NULL ) {
F_9 ( L_27 , V_1 ) ;
V_22 = - V_23 ;
} else {
F_54 ( V_55 ) ;
V_22 = 0 ;
}
F_10 ( & V_24 ) ;
return V_22 ;
}
void F_63 ( void )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_57 ; V_7 ++ ) {
if ( V_56 [ V_7 ] . V_58 )
F_54 ( & V_56 [ V_7 ] ) ;
}
V_9 = 0 ;
}
