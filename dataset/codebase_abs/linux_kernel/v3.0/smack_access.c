int F_1 ( char * V_1 , char * V_2 ,
struct V_3 * V_4 )
{
int V_5 = - V_6 ;
struct V_7 * V_8 ;
F_2 (srp, rule_list, list) {
if ( V_8 -> V_9 == V_1 ||
strcmp ( V_8 -> V_9 , V_1 ) == 0 ) {
if ( V_8 -> V_10 == V_2 ||
strcmp ( V_8 -> V_10 , V_2 ) == 0 ) {
V_5 = V_8 -> V_11 ;
break;
}
}
}
return V_5 ;
}
int V_11 ( char * V_1 , char * V_2 , int V_12 ,
struct V_13 * V_14 )
{
int V_5 = V_15 ;
int V_16 = 0 ;
if ( V_1 == V_17 . V_18 ||
strcmp ( V_1 , V_17 . V_18 ) == 0 ) {
V_16 = - V_19 ;
goto V_20;
}
if ( V_2 == V_21 . V_18 ||
V_1 == V_21 . V_18 ||
strcmp ( V_2 , V_21 . V_18 ) == 0 ||
strcmp ( V_1 , V_21 . V_18 ) == 0 )
goto V_20;
if ( V_2 == V_17 . V_18 ||
strcmp ( V_2 , V_17 . V_18 ) == 0 )
goto V_20;
if ( V_1 == V_2 ||
strcmp ( V_1 , V_2 ) == 0 )
goto V_20;
if ( ( V_12 & V_22 ) == V_12 ) {
if ( V_2 == V_23 . V_18 ||
strcmp ( V_2 , V_23 . V_18 ) == 0 )
goto V_20;
if ( V_1 == V_24 . V_18 ||
strcmp ( V_1 , V_24 . V_18 ) == 0 )
goto V_20;
}
F_3 () ;
V_5 = F_1 ( V_1 , V_2 , & V_25 ) ;
F_4 () ;
if ( V_5 > 0 && ( V_12 & V_5 ) == V_12 )
goto V_20;
V_16 = - V_19 ;
V_20:
#ifdef F_5
if ( V_14 )
F_6 ( V_1 , V_2 , V_12 , V_16 , V_14 ) ;
#endif
return V_16 ;
}
int F_7 ( char * V_26 , T_1 V_27 , struct V_13 * V_14 )
{
struct V_28 * V_29 = F_8 () ;
char * V_30 = F_9 ( V_29 ) ;
int V_5 ;
int V_16 ;
V_16 = V_11 ( V_30 , V_26 , V_27 , NULL ) ;
if ( V_16 == 0 ) {
V_5 = F_1 ( V_30 , V_26 , & V_29 -> V_31 ) ;
if ( V_5 < 0 )
goto V_20;
if ( ( V_27 & V_5 ) == V_27 )
goto V_20;
V_16 = - V_19 ;
}
if ( V_32 != NULL && V_32 != V_30 )
goto V_20;
if ( F_10 ( V_33 ) )
V_16 = 0 ;
V_20:
#ifdef F_5
if ( V_14 )
F_6 ( V_30 , V_26 , V_27 , V_16 , V_14 ) ;
#endif
return V_16 ;
}
static inline void F_11 ( char * string , int V_34 )
{
int V_35 = 0 ;
if ( V_34 & V_36 )
string [ V_35 ++ ] = 'r' ;
if ( V_34 & V_37 )
string [ V_35 ++ ] = 'w' ;
if ( V_34 & V_38 )
string [ V_35 ++ ] = 'x' ;
if ( V_34 & V_39 )
string [ V_35 ++ ] = 'a' ;
string [ V_35 ] = '\0' ;
}
static void F_12 ( struct V_40 * V_41 , void * V_14 )
{
struct V_42 * V_43 = V_14 ;
struct V_44 * V_45 = & V_43 -> V_44 ;
F_13 ( V_41 , L_1 ,
V_43 -> V_44 . V_46 ,
V_45 -> V_47 ? L_2 : L_3 ) ;
F_13 ( V_41 , L_4 ) ;
F_14 ( V_41 , V_45 -> V_48 ) ;
F_13 ( V_41 , L_5 ) ;
F_14 ( V_41 , V_45 -> V_49 ) ;
F_13 ( V_41 , L_6 , V_45 -> V_12 ) ;
}
void F_6 ( char * V_1 , char * V_2 , int V_12 ,
int V_47 , struct V_13 * V_43 )
{
char V_50 [ V_51 + 1 ] ;
struct V_44 * V_45 ;
struct V_42 * V_14 = & V_43 -> V_14 ;
if ( V_47 != 0 && ( V_52 & V_53 ) == 0 )
return;
if ( V_47 == 0 && ( V_52 & V_54 ) == 0 )
return;
if ( V_14 -> V_44 . V_46 == NULL )
V_14 -> V_44 . V_46 = L_7 ;
V_45 = & V_14 -> V_44 ;
F_11 ( V_50 , V_12 ) ;
V_45 -> V_48 = V_1 ;
V_45 -> V_49 = V_2 ;
V_45 -> V_12 = V_50 ;
V_45 -> V_47 = V_47 ;
V_14 -> V_55 = F_12 ;
F_15 ( V_14 ) ;
}
void F_6 ( char * V_1 , char * V_2 , int V_12 ,
int V_47 , struct V_13 * V_43 )
{
}
struct V_56 * F_16 ( const char * string , int V_57 )
{
struct V_56 * V_58 ;
char V_59 [ V_60 ] ;
int V_61 ;
int V_35 ;
if ( V_57 <= 0 || V_57 > V_62 )
V_57 = V_62 ;
for ( V_35 = 0 , V_61 = 0 ; V_35 < V_60 ; V_35 ++ ) {
if ( V_61 )
V_59 [ V_35 ] = '\0' ;
else if ( V_35 >= V_57 || string [ V_35 ] > '~' || string [ V_35 ] <= ' ' ||
string [ V_35 ] == '/' || string [ V_35 ] == '"' ||
string [ V_35 ] == '\\' || string [ V_35 ] == '\'' ) {
V_59 [ V_35 ] = '\0' ;
V_61 = 1 ;
} else
V_59 [ V_35 ] = string [ V_35 ] ;
}
if ( V_59 [ 0 ] == '\0' )
return NULL ;
F_17 ( & V_63 ) ;
V_61 = 0 ;
F_2 (skp, &smack_known_list, list) {
if ( strncmp ( V_58 -> V_18 , V_59 , V_62 ) == 0 ) {
V_61 = 1 ;
break;
}
}
if ( V_61 == 0 ) {
V_58 = F_18 ( sizeof( struct V_56 ) , V_64 ) ;
if ( V_58 != NULL ) {
strncpy ( V_58 -> V_18 , V_59 , V_62 ) ;
V_58 -> V_65 = V_66 ++ ;
V_58 -> V_67 = NULL ;
F_19 ( & V_58 -> V_68 ) ;
F_20 ( & V_58 -> V_69 , & V_70 ) ;
}
}
F_21 ( & V_63 ) ;
return V_58 ;
}
char * F_22 ( const char * string , int V_57 )
{
struct V_56 * V_58 ;
if ( string [ 0 ] == '-' )
return NULL ;
V_58 = F_16 ( string , V_57 ) ;
if ( V_58 == NULL )
return NULL ;
return V_58 -> V_18 ;
}
char * F_23 ( const T_1 V_71 )
{
struct V_56 * V_58 ;
F_3 () ;
F_2 (skp, &smack_known_list, list) {
if ( V_58 -> V_65 == V_71 ) {
F_4 () ;
return V_58 -> V_18 ;
}
}
F_4 () ;
return V_72 . V_18 ;
}
T_1 F_24 ( const char * V_59 )
{
struct V_56 * V_58 ;
F_3 () ;
F_2 (skp, &smack_known_list, list) {
if ( strncmp ( V_58 -> V_18 , V_59 , V_62 ) == 0 ) {
F_4 () ;
return V_58 -> V_65 ;
}
}
F_4 () ;
return 0 ;
}
void F_25 ( T_1 V_73 , char * V_74 , char * V_47 )
{
struct V_56 * V_75 ;
char * V_76 = NULL ;
F_3 () ;
F_26 (kp, &smack_known_list, list) {
if ( V_75 -> V_67 == NULL )
continue;
F_27 ( & V_75 -> V_68 ) ;
if ( V_75 -> V_67 -> V_77 == V_73 &&
memcmp ( V_75 -> V_67 -> V_78 , V_74 , V_60 ) == 0 )
V_76 = V_75 -> V_18 ;
F_28 ( & V_75 -> V_68 ) ;
}
F_4 () ;
if ( V_76 == NULL )
V_76 = V_79 . V_18 ;
strncpy ( V_47 , V_76 , V_62 ) ;
return;
}
int F_29 ( const char * V_59 , struct V_80 * V_74 )
{
struct V_56 * V_75 ;
int V_61 = 0 ;
F_3 () ;
F_2 (kp, &smack_known_list, list) {
if ( V_75 -> V_18 == V_59 ||
strcmp ( V_75 -> V_18 , V_59 ) == 0 ) {
V_61 = 1 ;
break;
}
}
F_4 () ;
if ( V_61 == 0 || V_75 -> V_67 == NULL )
return - V_6 ;
memcpy ( V_74 , V_75 -> V_67 , sizeof( struct V_80 ) ) ;
return 0 ;
}
