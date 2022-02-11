int F_1 ( char * V_1 , char * V_2 ,
struct V_3 * V_4 )
{
int V_5 = - V_6 ;
struct V_7 * V_8 ;
F_2 (srp, rule_list, list) {
if ( V_8 -> V_9 -> V_10 == V_2 &&
V_8 -> V_11 -> V_10 == V_1 ) {
V_5 = V_8 -> V_12 ;
break;
}
}
if ( ( V_5 & V_13 ) == V_13 )
V_5 |= V_14 ;
return V_5 ;
}
int V_12 ( struct V_15 * V_16 , struct V_15 * V_17 ,
int V_18 , struct V_19 * V_20 )
{
int V_5 = V_21 ;
int V_22 = 0 ;
if ( V_16 == & V_23 ) {
V_22 = - V_24 ;
goto V_25;
}
if ( V_17 == & V_26 || V_16 == & V_26 )
goto V_25;
if ( V_17 == & V_23 )
goto V_25;
if ( V_16 -> V_10 == V_17 -> V_10 )
goto V_25;
if ( ( V_18 & V_27 ) == V_18 ||
( V_18 & V_14 ) == V_18 ) {
if ( V_17 == & V_28 )
goto V_25;
if ( V_16 == & V_29 )
goto V_25;
}
F_3 () ;
V_5 = F_1 ( V_16 -> V_10 , V_17 -> V_10 ,
& V_16 -> V_30 ) ;
F_4 () ;
if ( V_5 <= 0 || ( V_18 & V_5 ) != V_18 ) {
V_22 = - V_24 ;
goto V_25;
}
#ifdef F_5
if ( V_5 & V_31 )
V_22 = V_32 ;
#endif
V_25:
#ifdef F_5
if ( V_22 < 0 ) {
if ( V_17 == V_33 )
V_22 = V_34 ;
if ( V_16 == V_33 )
V_22 = V_35 ;
}
#endif
#ifdef F_6
if ( V_20 )
F_7 ( V_16 -> V_10 , V_17 -> V_10 ,
V_18 , V_22 , V_20 ) ;
#endif
return V_22 ;
}
int F_8 ( struct V_36 * V_37 , struct V_15 * V_38 ,
T_1 V_39 , struct V_19 * V_20 )
{
struct V_15 * V_40 = F_9 ( V_37 ) ;
int V_5 ;
int V_22 ;
V_22 = V_12 ( V_40 , V_38 , V_39 , NULL ) ;
if ( V_22 >= 0 ) {
V_5 = F_1 ( V_40 -> V_10 ,
V_38 -> V_10 ,
& V_37 -> V_30 ) ;
if ( V_5 < 0 )
goto V_25;
if ( ( V_39 & V_5 ) == V_39 )
goto V_25;
V_22 = - V_24 ;
}
if ( V_22 != 0 && F_10 ( V_41 ) )
V_22 = 0 ;
V_25:
#ifdef F_6
if ( V_20 )
F_7 ( V_40 -> V_10 , V_38 -> V_10 ,
V_39 , V_22 , V_20 ) ;
#endif
return V_22 ;
}
int F_11 ( struct V_15 * V_38 ,
T_1 V_39 , struct V_19 * V_20 )
{
struct V_36 * V_37 = F_12 () ;
return F_8 ( V_37 , V_38 , V_39 , V_20 ) ;
}
static inline void F_13 ( char * string , int V_42 )
{
int V_43 = 0 ;
if ( V_42 & V_44 )
string [ V_43 ++ ] = 'r' ;
if ( V_42 & V_13 )
string [ V_43 ++ ] = 'w' ;
if ( V_42 & V_45 )
string [ V_43 ++ ] = 'x' ;
if ( V_42 & V_46 )
string [ V_43 ++ ] = 'a' ;
if ( V_42 & V_47 )
string [ V_43 ++ ] = 't' ;
if ( V_42 & V_14 )
string [ V_43 ++ ] = 'l' ;
string [ V_43 ] = '\0' ;
}
static void F_14 ( struct V_48 * V_49 , void * V_20 )
{
struct V_50 * V_51 = V_20 ;
struct V_52 * V_53 = V_51 -> V_52 ;
F_15 ( V_49 , L_1 ,
V_51 -> V_52 -> V_54 ,
V_53 -> V_55 ? L_2 : L_3 ) ;
F_15 ( V_49 , L_4 ) ;
F_16 ( V_49 , V_53 -> V_16 ) ;
F_15 ( V_49 , L_5 ) ;
F_16 ( V_49 , V_53 -> V_17 ) ;
if ( V_53 -> V_18 [ 0 ] == '\0' )
F_15 ( V_49 , L_6 ) ;
else
F_15 ( V_49 , L_7 , V_53 -> V_18 ) ;
}
void F_7 ( char * V_1 , char * V_2 , int V_18 ,
int V_55 , struct V_19 * V_51 )
{
#ifdef F_5
char V_56 [ V_57 + 5 ] ;
#else
char V_56 [ V_57 + 1 ] ;
#endif
struct V_52 * V_53 ;
struct V_50 * V_20 = & V_51 -> V_20 ;
if ( V_55 < 0 && ( V_58 & V_59 ) == 0 )
return;
if ( V_55 == 0 && ( V_58 & V_60 ) == 0 )
return;
V_53 = V_20 -> V_52 ;
if ( V_53 -> V_54 == NULL )
V_53 -> V_54 = L_8 ;
F_13 ( V_56 , V_18 ) ;
V_53 -> V_16 = V_1 ;
V_53 -> V_17 = V_2 ;
#ifdef F_5
if ( V_55 == V_35 )
strcat ( V_56 , L_9 ) ;
else if ( V_55 == V_34 )
strcat ( V_56 , L_10 ) ;
if ( V_55 > 0 )
V_55 = 0 ;
#endif
V_53 -> V_18 = V_56 ;
V_53 -> V_55 = V_55 ;
F_17 ( V_20 , F_14 , NULL ) ;
}
void F_7 ( char * V_1 , char * V_2 , int V_18 ,
int V_55 , struct V_19 * V_51 )
{
}
void F_18 ( struct V_15 * V_61 )
{
unsigned int V_62 ;
struct V_63 * V_64 ;
V_62 = F_19 ( NULL , V_61 -> V_10 , strlen ( V_61 -> V_10 ) ) ;
V_64 = & V_65 [ V_62 & ( V_66 - 1 ) ] ;
F_20 ( & V_61 -> V_67 , V_64 ) ;
F_21 ( & V_61 -> V_68 , & V_69 ) ;
}
struct V_15 * F_22 ( const char * string )
{
unsigned int V_62 ;
struct V_63 * V_64 ;
struct V_15 * V_61 ;
V_62 = F_19 ( NULL , string , strlen ( string ) ) ;
V_64 = & V_65 [ V_62 & ( V_66 - 1 ) ] ;
F_23 (skp, head, smk_hashed)
if ( strcmp ( V_61 -> V_10 , string ) == 0 )
return V_61 ;
return NULL ;
}
char * F_24 ( const char * string , int V_70 )
{
char * V_71 ;
int V_43 ;
if ( V_70 <= 0 )
V_70 = strlen ( string ) + 1 ;
if ( string [ 0 ] == '-' )
return F_25 ( - V_72 ) ;
for ( V_43 = 0 ; V_43 < V_70 ; V_43 ++ )
if ( string [ V_43 ] > '~' || string [ V_43 ] <= ' ' || string [ V_43 ] == '/' ||
string [ V_43 ] == '"' || string [ V_43 ] == '\\' || string [ V_43 ] == '\'' )
break;
if ( V_43 == 0 || V_43 >= V_73 )
return F_25 ( - V_72 ) ;
V_71 = F_26 ( V_43 + 1 , V_74 ) ;
if ( V_71 == NULL )
return F_25 ( - V_75 ) ;
strncpy ( V_71 , string , V_43 ) ;
return V_71 ;
}
int F_27 ( int V_76 , char * V_77 , struct V_78 * V_79 ,
int V_70 )
{
unsigned char * V_80 ;
unsigned char V_81 ;
int V_82 ;
int V_22 ;
int V_83 ;
V_79 -> V_84 |= V_85 ;
V_79 -> V_86 . V_87 . V_88 = V_76 ;
V_79 -> V_86 . V_87 . V_82 = NULL ;
for ( V_82 = 1 , V_80 = V_77 , V_83 = 0 ; V_83 < V_70 ; V_80 ++ , V_83 ++ )
for ( V_81 = 0x80 ; V_81 != 0 ; V_81 >>= 1 , V_82 ++ ) {
if ( ( V_81 & * V_80 ) == 0 )
continue;
V_22 = F_28 ( & V_79 -> V_86 . V_87 . V_82 ,
V_82 , V_74 ) ;
if ( V_22 < 0 ) {
F_29 ( V_79 -> V_86 . V_87 . V_82 ) ;
return V_22 ;
}
}
return 0 ;
}
struct V_15 * F_30 ( const char * string , int V_70 )
{
struct V_15 * V_61 ;
char * V_71 ;
int V_89 ;
int V_22 ;
V_71 = F_24 ( string , V_70 ) ;
if ( F_31 ( V_71 ) )
return F_32 ( V_71 ) ;
F_33 ( & V_90 ) ;
V_61 = F_22 ( V_71 ) ;
if ( V_61 != NULL )
goto V_91;
V_61 = F_26 ( sizeof( * V_61 ) , V_74 ) ;
if ( V_61 == NULL ) {
V_61 = F_25 ( - V_75 ) ;
goto V_91;
}
V_61 -> V_10 = V_71 ;
V_61 -> V_92 = V_93 ++ ;
V_61 -> V_94 . V_95 = V_61 -> V_10 ;
V_61 -> V_94 . V_84 =
V_96 | V_97 ;
V_89 = strlen ( V_71 ) ;
if ( V_89 < V_98 )
V_22 = F_27 ( V_99 , V_61 -> V_10 ,
& V_61 -> V_94 , V_89 ) ;
else
V_22 = F_27 ( V_100 , ( char * ) & V_61 -> V_92 ,
& V_61 -> V_94 , sizeof( V_61 -> V_92 ) ) ;
if ( V_22 >= 0 ) {
F_34 ( & V_61 -> V_30 ) ;
F_35 ( & V_61 -> V_101 ) ;
F_18 ( V_61 ) ;
goto V_102;
}
F_36 ( V_61 ) ;
V_61 = F_25 ( V_22 ) ;
V_91:
F_36 ( V_71 ) ;
V_102:
F_37 ( & V_90 ) ;
return V_61 ;
}
struct V_15 * F_38 ( const T_1 V_103 )
{
struct V_15 * V_61 ;
F_3 () ;
F_2 (skp, &smack_known_list, list) {
if ( V_61 -> V_92 == V_103 ) {
F_4 () ;
return V_61 ;
}
}
F_4 () ;
return & V_104 ;
}
int F_10 ( int V_105 )
{
struct V_15 * V_61 = F_39 () ;
struct V_106 * V_107 ;
if ( F_40 ( V_108 -> V_84 & V_109 ) )
return 1 ;
if ( ! F_41 ( V_105 ) )
return 0 ;
F_3 () ;
if ( F_42 ( & V_110 ) ) {
F_4 () ;
return 1 ;
}
F_2 (sklep, &smack_onlycap_list, list) {
if ( V_107 -> V_111 == V_61 ) {
F_4 () ;
return 1 ;
}
}
F_4 () ;
return 0 ;
}
