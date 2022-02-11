int F_1 ( char * V_1 , char * V_2 ,
struct V_3 * V_4 )
{
int V_5 = - V_6 ;
struct V_7 * V_8 ;
F_2 (srp, rule_list, list) {
if ( V_8 -> V_9 == V_2 &&
V_8 -> V_10 -> V_11 == V_1 ) {
V_5 = V_8 -> V_12 ;
break;
}
}
return V_5 ;
}
int V_12 ( struct V_13 * V_14 , char * V_2 ,
int V_15 , struct V_16 * V_17 )
{
int V_5 = V_18 ;
int V_19 = 0 ;
if ( V_14 == & V_20 ) {
V_19 = - V_21 ;
goto V_22;
}
if ( V_2 == V_23 . V_11 ||
V_14 == & V_23 )
goto V_22;
if ( V_2 == V_20 . V_11 )
goto V_22;
if ( V_14 -> V_11 == V_2 )
goto V_22;
if ( ( V_15 & V_24 ) == V_15 ) {
if ( V_2 == V_25 . V_11 )
goto V_22;
if ( V_14 == & V_26 )
goto V_22;
}
F_3 () ;
V_5 = F_1 ( V_14 -> V_11 , V_2 ,
& V_14 -> V_27 ) ;
F_4 () ;
if ( V_5 > 0 && ( V_15 & V_5 ) == V_15 )
goto V_22;
V_19 = - V_21 ;
V_22:
#ifdef F_5
if ( V_17 )
F_6 ( V_14 -> V_11 , V_2 , V_15 ,
V_19 , V_17 ) ;
#endif
return V_19 ;
}
int F_7 ( char * V_28 , T_1 V_29 , struct V_16 * V_17 )
{
struct V_30 * V_31 = F_8 () ;
struct V_13 * V_32 = F_9 ( V_31 ) ;
int V_5 ;
int V_19 ;
V_19 = V_12 ( V_32 , V_28 , V_29 , NULL ) ;
if ( V_19 == 0 ) {
V_5 = F_1 ( V_32 -> V_11 , V_28 ,
& V_31 -> V_27 ) ;
if ( V_5 < 0 )
goto V_22;
if ( ( V_29 & V_5 ) == V_29 )
goto V_22;
V_19 = - V_21 ;
}
if ( V_19 != 0 && F_10 ( V_33 ) )
V_19 = 0 ;
V_22:
#ifdef F_5
if ( V_17 )
F_6 ( V_32 -> V_11 , V_28 , V_29 , V_19 , V_17 ) ;
#endif
return V_19 ;
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
if ( V_34 & V_40 )
string [ V_35 ++ ] = 't' ;
string [ V_35 ] = '\0' ;
}
static void F_12 ( struct V_41 * V_42 , void * V_17 )
{
struct V_43 * V_44 = V_17 ;
struct V_45 * V_46 = V_44 -> V_45 ;
F_13 ( V_42 , L_1 ,
V_44 -> V_45 -> V_47 ,
V_46 -> V_48 ? L_2 : L_3 ) ;
F_13 ( V_42 , L_4 ) ;
F_14 ( V_42 , V_46 -> V_49 ) ;
F_13 ( V_42 , L_5 ) ;
F_14 ( V_42 , V_46 -> V_50 ) ;
F_13 ( V_42 , L_6 , V_46 -> V_15 ) ;
}
void F_6 ( char * V_1 , char * V_2 , int V_15 ,
int V_48 , struct V_16 * V_44 )
{
char V_51 [ V_52 + 1 ] ;
struct V_45 * V_46 ;
struct V_43 * V_17 = & V_44 -> V_17 ;
if ( V_48 != 0 && ( V_53 & V_54 ) == 0 )
return;
if ( V_48 == 0 && ( V_53 & V_55 ) == 0 )
return;
V_46 = V_17 -> V_45 ;
if ( V_46 -> V_47 == NULL )
V_46 -> V_47 = L_7 ;
F_11 ( V_51 , V_15 ) ;
V_46 -> V_49 = V_1 ;
V_46 -> V_50 = V_2 ;
V_46 -> V_15 = V_51 ;
V_46 -> V_48 = V_48 ;
F_15 ( V_17 , F_12 , NULL ) ;
}
void F_6 ( char * V_1 , char * V_2 , int V_15 ,
int V_48 , struct V_16 * V_44 )
{
}
void F_16 ( struct V_13 * V_32 )
{
unsigned int V_56 ;
struct V_57 * V_58 ;
V_56 = F_17 ( V_32 -> V_11 , strlen ( V_32 -> V_11 ) ) ;
V_58 = & V_59 [ V_56 & ( V_60 - 1 ) ] ;
F_18 ( & V_32 -> V_61 , V_58 ) ;
F_19 ( & V_32 -> V_62 , & V_63 ) ;
}
struct V_13 * F_20 ( const char * string )
{
unsigned int V_56 ;
struct V_57 * V_58 ;
struct V_13 * V_32 ;
V_56 = F_17 ( string , strlen ( string ) ) ;
V_58 = & V_59 [ V_56 & ( V_60 - 1 ) ] ;
F_21 (skp, head, smk_hashed)
if ( strcmp ( V_32 -> V_11 , string ) == 0 )
return V_32 ;
return NULL ;
}
char * F_22 ( const char * string , int V_64 )
{
char * V_65 ;
int V_35 ;
if ( V_64 <= 0 )
V_64 = strlen ( string ) + 1 ;
if ( string [ 0 ] == '-' )
return NULL ;
for ( V_35 = 0 ; V_35 < V_64 ; V_35 ++ )
if ( string [ V_35 ] > '~' || string [ V_35 ] <= ' ' || string [ V_35 ] == '/' ||
string [ V_35 ] == '"' || string [ V_35 ] == '\\' || string [ V_35 ] == '\'' )
break;
if ( V_35 == 0 || V_35 >= V_66 )
return NULL ;
V_65 = F_23 ( V_35 + 1 , V_67 ) ;
if ( V_65 != NULL ) {
strncpy ( V_65 , string , V_35 + 1 ) ;
V_65 [ V_35 ] = '\0' ;
}
return V_65 ;
}
int F_24 ( int V_68 , char * V_69 , struct V_70 * V_71 ,
int V_64 )
{
unsigned char * V_72 ;
unsigned char V_73 ;
int V_74 ;
int V_19 ;
int V_75 ;
V_71 -> V_76 |= V_77 ;
V_71 -> V_78 . V_79 . V_80 = V_68 ;
V_71 -> V_78 . V_79 . V_74 = F_25 ( V_81 ) ;
if ( ! V_71 -> V_78 . V_79 . V_74 )
return - V_82 ;
V_71 -> V_78 . V_79 . V_74 -> V_83 = 0 ;
for ( V_74 = 1 , V_72 = V_69 , V_75 = 0 ; V_75 < V_64 ; V_72 ++ , V_75 ++ )
for ( V_73 = 0x80 ; V_73 != 0 ; V_73 >>= 1 , V_74 ++ ) {
if ( ( V_73 & * V_72 ) == 0 )
continue;
V_19 = F_26 ( V_71 -> V_78 . V_79 . V_74 ,
V_74 , V_81 ) ;
if ( V_19 < 0 ) {
F_27 ( V_71 -> V_78 . V_79 . V_74 ) ;
return V_19 ;
}
}
return 0 ;
}
struct V_13 * F_28 ( const char * string , int V_64 )
{
struct V_13 * V_32 ;
char * V_65 ;
int V_84 ;
int V_19 ;
V_65 = F_22 ( string , V_64 ) ;
if ( V_65 == NULL )
return NULL ;
F_29 ( & V_85 ) ;
V_32 = F_20 ( V_65 ) ;
if ( V_32 != NULL )
goto V_86;
V_32 = F_23 ( sizeof( * V_32 ) , V_67 ) ;
if ( V_32 == NULL )
goto V_86;
V_32 -> V_11 = V_65 ;
V_32 -> V_87 = V_88 ++ ;
V_32 -> V_89 . V_90 = V_32 -> V_11 ;
V_32 -> V_89 . V_76 =
V_91 | V_92 ;
V_84 = strlen ( V_65 ) ;
if ( V_84 < V_93 )
V_19 = F_24 ( V_94 , V_32 -> V_11 ,
& V_32 -> V_89 , V_84 ) ;
else
V_19 = F_24 ( V_95 , ( char * ) & V_32 -> V_87 ,
& V_32 -> V_89 , sizeof( V_32 -> V_87 ) ) ;
if ( V_19 >= 0 ) {
F_30 ( & V_32 -> V_27 ) ;
F_31 ( & V_32 -> V_96 ) ;
F_16 ( V_32 ) ;
goto V_97;
}
F_32 ( V_32 ) ;
V_32 = NULL ;
V_86:
F_32 ( V_65 ) ;
V_97:
F_33 ( & V_85 ) ;
return V_32 ;
}
char * F_34 ( const char * string , int V_64 )
{
struct V_13 * V_32 ;
if ( string [ 0 ] == '-' )
return NULL ;
V_32 = F_28 ( string , V_64 ) ;
if ( V_32 == NULL )
return NULL ;
return V_32 -> V_11 ;
}
struct V_13 * F_35 ( const T_1 V_98 )
{
struct V_13 * V_32 ;
F_3 () ;
F_2 (skp, &smack_known_list, list) {
if ( V_32 -> V_87 == V_98 ) {
F_4 () ;
return V_32 ;
}
}
F_4 () ;
return & V_99 ;
}
T_1 F_36 ( const char * V_65 )
{
struct V_13 * V_32 = F_20 ( V_65 ) ;
if ( V_32 == NULL )
return 0 ;
return V_32 -> V_87 ;
}
