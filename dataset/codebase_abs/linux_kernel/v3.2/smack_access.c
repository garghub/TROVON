int F_1 ( char * V_1 , char * V_2 ,
struct V_3 * V_4 )
{
int V_5 = - V_6 ;
struct V_7 * V_8 ;
F_2 (srp, rule_list, list) {
if ( V_8 -> V_9 == V_2 &&
V_8 -> V_10 == V_1 ) {
V_5 = V_8 -> V_11 ;
break;
}
}
return V_5 ;
}
int V_11 ( char * V_1 , char * V_2 , int V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_5 = V_17 ;
int V_18 = 0 ;
if ( V_1 == V_19 . V_20 ) {
V_18 = - V_21 ;
goto V_22;
}
if ( V_2 == V_23 . V_20 ||
V_1 == V_23 . V_20 )
goto V_22;
if ( V_2 == V_19 . V_20 )
goto V_22;
if ( V_1 == V_2 )
goto V_22;
if ( ( V_12 & V_24 ) == V_12 ) {
if ( V_2 == V_25 . V_20 )
goto V_22;
if ( V_1 == V_26 . V_20 )
goto V_22;
}
V_16 = F_3 ( V_1 ) ;
F_4 () ;
V_5 = F_1 ( V_1 , V_2 , & V_16 -> V_27 ) ;
F_5 () ;
if ( V_5 > 0 && ( V_12 & V_5 ) == V_12 )
goto V_22;
V_18 = - V_21 ;
V_22:
#ifdef F_6
if ( V_14 )
F_7 ( V_1 , V_2 , V_12 , V_18 , V_14 ) ;
#endif
return V_18 ;
}
int F_8 ( char * V_28 , T_1 V_29 , struct V_13 * V_14 )
{
struct V_30 * V_31 = F_9 () ;
char * V_32 = F_10 ( V_31 ) ;
int V_5 ;
int V_18 ;
V_18 = V_11 ( V_32 , V_28 , V_29 , NULL ) ;
if ( V_18 == 0 ) {
V_5 = F_1 ( V_32 , V_28 , & V_31 -> V_27 ) ;
if ( V_5 < 0 )
goto V_22;
if ( ( V_29 & V_5 ) == V_29 )
goto V_22;
V_18 = - V_21 ;
}
if ( V_33 != NULL && V_33 != V_32 )
goto V_22;
if ( F_11 ( V_34 ) )
V_18 = 0 ;
V_22:
#ifdef F_6
if ( V_14 )
F_7 ( V_32 , V_28 , V_29 , V_18 , V_14 ) ;
#endif
return V_18 ;
}
static inline void F_12 ( char * string , int V_35 )
{
int V_36 = 0 ;
if ( V_35 & V_37 )
string [ V_36 ++ ] = 'r' ;
if ( V_35 & V_38 )
string [ V_36 ++ ] = 'w' ;
if ( V_35 & V_39 )
string [ V_36 ++ ] = 'x' ;
if ( V_35 & V_40 )
string [ V_36 ++ ] = 'a' ;
string [ V_36 ] = '\0' ;
}
static void F_13 ( struct V_41 * V_42 , void * V_14 )
{
struct V_43 * V_44 = V_14 ;
struct V_45 * V_46 = & V_44 -> V_45 ;
F_14 ( V_42 , L_1 ,
V_44 -> V_45 . V_47 ,
V_46 -> V_48 ? L_2 : L_3 ) ;
F_14 ( V_42 , L_4 ) ;
F_15 ( V_42 , V_46 -> V_49 ) ;
F_14 ( V_42 , L_5 ) ;
F_15 ( V_42 , V_46 -> V_50 ) ;
F_14 ( V_42 , L_6 , V_46 -> V_12 ) ;
}
void F_7 ( char * V_1 , char * V_2 , int V_12 ,
int V_48 , struct V_13 * V_44 )
{
char V_51 [ V_52 + 1 ] ;
struct V_45 * V_46 ;
struct V_43 * V_14 = & V_44 -> V_14 ;
if ( V_48 != 0 && ( V_53 & V_54 ) == 0 )
return;
if ( V_48 == 0 && ( V_53 & V_55 ) == 0 )
return;
if ( V_14 -> V_45 . V_47 == NULL )
V_14 -> V_45 . V_47 = L_7 ;
V_46 = & V_14 -> V_45 ;
F_12 ( V_51 , V_12 ) ;
V_46 -> V_49 = V_1 ;
V_46 -> V_50 = V_2 ;
V_46 -> V_12 = V_51 ;
V_46 -> V_48 = V_48 ;
V_14 -> V_56 = F_13 ;
F_16 ( V_14 ) ;
}
void F_7 ( char * V_1 , char * V_2 , int V_12 ,
int V_48 , struct V_13 * V_44 )
{
}
struct V_15 * F_3 ( const char * string )
{
struct V_15 * V_16 ;
F_2 (skp, &smack_known_list, list) {
if ( strncmp ( V_16 -> V_20 , string , V_57 ) == 0 )
return V_16 ;
}
return NULL ;
}
void F_17 ( const char * string , int V_58 , char * V_59 )
{
int V_60 ;
int V_36 ;
if ( V_58 <= 0 || V_58 > V_57 )
V_58 = V_57 ;
for ( V_36 = 0 , V_60 = 0 ; V_36 < V_61 ; V_36 ++ ) {
if ( V_60 )
V_59 [ V_36 ] = '\0' ;
else if ( V_36 >= V_58 || string [ V_36 ] > '~' || string [ V_36 ] <= ' ' ||
string [ V_36 ] == '/' || string [ V_36 ] == '"' ||
string [ V_36 ] == '\\' || string [ V_36 ] == '\'' ) {
V_59 [ V_36 ] = '\0' ;
V_60 = 1 ;
} else
V_59 [ V_36 ] = string [ V_36 ] ;
}
}
struct V_15 * F_18 ( const char * string , int V_58 )
{
struct V_15 * V_16 ;
char V_59 [ V_61 ] ;
F_17 ( string , V_58 , V_59 ) ;
if ( V_59 [ 0 ] == '\0' )
return NULL ;
F_19 ( & V_62 ) ;
V_16 = F_3 ( V_59 ) ;
if ( V_16 == NULL ) {
V_16 = F_20 ( sizeof( struct V_15 ) , V_63 ) ;
if ( V_16 != NULL ) {
strncpy ( V_16 -> V_20 , V_59 , V_57 ) ;
V_16 -> V_64 = V_65 ++ ;
V_16 -> V_66 = NULL ;
F_21 ( & V_16 -> V_27 ) ;
F_22 ( & V_16 -> V_67 ) ;
F_23 ( & V_16 -> V_68 ) ;
F_24 ( & V_16 -> V_69 , & V_70 ) ;
}
}
F_25 ( & V_62 ) ;
return V_16 ;
}
char * F_26 ( const char * string , int V_58 )
{
struct V_15 * V_16 ;
if ( string [ 0 ] == '-' )
return NULL ;
V_16 = F_18 ( string , V_58 ) ;
if ( V_16 == NULL )
return NULL ;
return V_16 -> V_20 ;
}
char * F_27 ( const T_1 V_71 )
{
struct V_15 * V_16 ;
F_4 () ;
F_2 (skp, &smack_known_list, list) {
if ( V_16 -> V_64 == V_71 ) {
F_5 () ;
return V_16 -> V_20 ;
}
}
F_5 () ;
return V_72 . V_20 ;
}
T_1 F_28 ( const char * V_59 )
{
struct V_15 * V_16 ;
F_4 () ;
F_2 (skp, &smack_known_list, list) {
if ( strncmp ( V_16 -> V_20 , V_59 , V_57 ) == 0 ) {
F_5 () ;
return V_16 -> V_64 ;
}
}
F_5 () ;
return 0 ;
}
char * F_29 ( T_1 V_73 , char * V_74 )
{
struct V_15 * V_75 ;
char * V_76 = NULL ;
F_4 () ;
F_30 (kp, &smack_known_list, list) {
if ( V_75 -> V_66 == NULL )
continue;
F_31 ( & V_75 -> V_67 ) ;
if ( V_75 -> V_66 -> V_77 == V_73 &&
memcmp ( V_75 -> V_66 -> V_78 , V_74 , V_61 ) == 0 )
V_76 = V_75 -> V_20 ;
F_32 ( & V_75 -> V_67 ) ;
if ( V_76 != NULL )
break;
}
F_5 () ;
return V_76 ;
}
int F_33 ( const char * V_59 , struct V_79 * V_74 )
{
struct V_15 * V_75 ;
int V_60 = 0 ;
F_4 () ;
F_2 (kp, &smack_known_list, list) {
if ( V_75 -> V_20 == V_59 ||
strcmp ( V_75 -> V_20 , V_59 ) == 0 ) {
V_60 = 1 ;
break;
}
}
F_5 () ;
if ( V_60 == 0 || V_75 -> V_66 == NULL )
return - V_6 ;
memcpy ( V_74 , V_75 -> V_66 , sizeof( struct V_79 ) ) ;
return 0 ;
}
