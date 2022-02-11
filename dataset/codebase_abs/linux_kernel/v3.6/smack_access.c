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
if ( V_18 != 0 && F_11 ( V_33 ) )
V_18 = 0 ;
V_22:
#ifdef F_6
if ( V_14 )
F_7 ( V_32 , V_28 , V_29 , V_18 , V_14 ) ;
#endif
return V_18 ;
}
static inline void F_12 ( char * string , int V_34 )
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
static void F_13 ( struct V_40 * V_41 , void * V_14 )
{
struct V_42 * V_43 = V_14 ;
struct V_44 * V_45 = V_43 -> V_44 ;
F_14 ( V_41 , L_1 ,
V_43 -> V_44 -> V_46 ,
V_45 -> V_47 ? L_2 : L_3 ) ;
F_14 ( V_41 , L_4 ) ;
F_15 ( V_41 , V_45 -> V_48 ) ;
F_14 ( V_41 , L_5 ) ;
F_15 ( V_41 , V_45 -> V_49 ) ;
F_14 ( V_41 , L_6 , V_45 -> V_12 ) ;
}
void F_7 ( char * V_1 , char * V_2 , int V_12 ,
int V_47 , struct V_13 * V_43 )
{
char V_50 [ V_51 + 1 ] ;
struct V_44 * V_45 ;
struct V_42 * V_14 = & V_43 -> V_14 ;
if ( V_47 != 0 && ( V_52 & V_53 ) == 0 )
return;
if ( V_47 == 0 && ( V_52 & V_54 ) == 0 )
return;
V_45 = V_14 -> V_44 ;
if ( V_45 -> V_46 == NULL )
V_45 -> V_46 = L_7 ;
F_12 ( V_50 , V_12 ) ;
V_45 -> V_48 = V_1 ;
V_45 -> V_49 = V_2 ;
V_45 -> V_12 = V_50 ;
V_45 -> V_47 = V_47 ;
F_16 ( V_14 , F_13 , NULL ) ;
}
void F_7 ( char * V_1 , char * V_2 , int V_12 ,
int V_47 , struct V_13 * V_43 )
{
}
struct V_15 * F_3 ( const char * string )
{
struct V_15 * V_16 ;
F_2 (skp, &smack_known_list, list) {
if ( strcmp ( V_16 -> V_20 , string ) == 0 )
return V_16 ;
}
return NULL ;
}
char * F_17 ( const char * string , int V_55 )
{
char * V_56 ;
int V_35 ;
if ( V_55 <= 0 )
V_55 = strlen ( string ) + 1 ;
if ( string [ 0 ] == '-' )
return NULL ;
for ( V_35 = 0 ; V_35 < V_55 ; V_35 ++ )
if ( string [ V_35 ] > '~' || string [ V_35 ] <= ' ' || string [ V_35 ] == '/' ||
string [ V_35 ] == '"' || string [ V_35 ] == '\\' || string [ V_35 ] == '\'' )
break;
if ( V_35 == 0 || V_35 >= V_57 )
return NULL ;
V_56 = F_18 ( V_35 + 1 , V_58 ) ;
if ( V_56 != NULL ) {
strncpy ( V_56 , string , V_35 + 1 ) ;
V_56 [ V_35 ] = '\0' ;
}
return V_56 ;
}
int F_19 ( int V_59 , char * V_60 , struct V_61 * V_62 ,
int V_55 )
{
unsigned char * V_63 ;
unsigned char V_64 ;
int V_65 ;
int V_18 ;
int V_66 ;
V_62 -> V_67 |= V_68 ;
V_62 -> V_69 . V_70 . V_71 = V_59 ;
V_62 -> V_69 . V_70 . V_65 = F_20 ( V_72 ) ;
V_62 -> V_69 . V_70 . V_65 -> V_73 = 0 ;
for ( V_65 = 1 , V_63 = V_60 , V_66 = 0 ; V_66 < V_55 ; V_63 ++ , V_66 ++ )
for ( V_64 = 0x80 ; V_64 != 0 ; V_64 >>= 1 , V_65 ++ ) {
if ( ( V_64 & * V_63 ) == 0 )
continue;
V_18 = F_21 ( V_62 -> V_69 . V_70 . V_65 ,
V_65 , V_72 ) ;
if ( V_18 < 0 ) {
F_22 ( V_62 -> V_69 . V_70 . V_65 ) ;
return V_18 ;
}
}
return 0 ;
}
struct V_15 * F_23 ( const char * string , int V_55 )
{
struct V_15 * V_16 ;
char * V_56 ;
int V_74 ;
int V_18 ;
V_56 = F_17 ( string , V_55 ) ;
if ( V_56 == NULL )
return NULL ;
F_24 ( & V_75 ) ;
V_16 = F_3 ( V_56 ) ;
if ( V_16 != NULL )
goto V_76;
V_16 = F_18 ( sizeof( * V_16 ) , V_58 ) ;
if ( V_16 == NULL )
goto V_76;
V_16 -> V_20 = V_56 ;
V_16 -> V_77 = V_78 ++ ;
V_16 -> V_79 . V_80 = V_16 -> V_20 ;
V_16 -> V_79 . V_67 =
V_81 | V_82 ;
V_74 = strlen ( V_56 ) ;
if ( V_74 < V_83 )
V_18 = F_19 ( V_84 , V_16 -> V_20 ,
& V_16 -> V_79 , V_74 ) ;
else
V_18 = F_19 ( V_85 , ( char * ) & V_16 -> V_77 ,
& V_16 -> V_79 , sizeof( V_16 -> V_77 ) ) ;
if ( V_18 >= 0 ) {
F_25 ( & V_16 -> V_27 ) ;
F_26 ( & V_16 -> V_86 ) ;
F_27 ( & V_16 -> V_87 , & V_88 ) ;
goto V_89;
}
F_28 ( V_16 ) ;
V_16 = NULL ;
V_76:
F_28 ( V_56 ) ;
V_89:
F_29 ( & V_75 ) ;
return V_16 ;
}
char * F_30 ( const char * string , int V_55 )
{
struct V_15 * V_16 ;
if ( string [ 0 ] == '-' )
return NULL ;
V_16 = F_23 ( string , V_55 ) ;
if ( V_16 == NULL )
return NULL ;
return V_16 -> V_20 ;
}
char * F_31 ( const T_1 V_90 )
{
struct V_15 * V_16 ;
F_4 () ;
F_2 (skp, &smack_known_list, list) {
if ( V_16 -> V_77 == V_90 ) {
F_5 () ;
return V_16 -> V_20 ;
}
}
F_5 () ;
return V_91 . V_20 ;
}
T_1 F_32 ( const char * V_56 )
{
struct V_15 * V_16 = F_3 ( V_56 ) ;
if ( V_16 == NULL )
return 0 ;
return V_16 -> V_77 ;
}
