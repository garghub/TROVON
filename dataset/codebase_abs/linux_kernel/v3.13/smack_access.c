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
if ( ( V_5 & V_13 ) == V_13 )
V_5 |= V_14 ;
return V_5 ;
}
int V_12 ( struct V_15 * V_16 , char * V_2 ,
int V_17 , struct V_18 * V_19 )
{
int V_5 = V_20 ;
int V_21 = 0 ;
if ( V_16 == & V_22 ) {
V_21 = - V_23 ;
goto V_24;
}
if ( V_2 == V_25 . V_11 ||
V_16 == & V_25 )
goto V_24;
if ( V_2 == V_22 . V_11 )
goto V_24;
if ( V_16 -> V_11 == V_2 )
goto V_24;
if ( ( V_17 & V_26 ) == V_17 ) {
if ( V_2 == V_27 . V_11 )
goto V_24;
if ( V_16 == & V_28 )
goto V_24;
}
F_3 () ;
V_5 = F_1 ( V_16 -> V_11 , V_2 ,
& V_16 -> V_29 ) ;
F_4 () ;
if ( V_5 > 0 && ( V_17 & V_5 ) == V_17 )
goto V_24;
V_21 = - V_23 ;
V_24:
#ifdef F_5
if ( V_19 )
F_6 ( V_16 -> V_11 , V_2 , V_17 ,
V_21 , V_19 ) ;
#endif
return V_21 ;
}
int F_7 ( char * V_30 , T_1 V_31 , struct V_18 * V_19 )
{
struct V_32 * V_33 = F_8 () ;
struct V_15 * V_34 = F_9 ( V_33 ) ;
int V_5 ;
int V_21 ;
V_21 = V_12 ( V_34 , V_30 , V_31 , NULL ) ;
if ( V_21 == 0 ) {
V_5 = F_1 ( V_34 -> V_11 , V_30 ,
& V_33 -> V_29 ) ;
if ( V_5 < 0 )
goto V_24;
if ( ( V_31 & V_5 ) == V_31 )
goto V_24;
V_21 = - V_23 ;
}
if ( V_21 != 0 && F_10 ( V_35 ) )
V_21 = 0 ;
V_24:
#ifdef F_5
if ( V_19 )
F_6 ( V_34 -> V_11 , V_30 , V_31 , V_21 , V_19 ) ;
#endif
return V_21 ;
}
static inline void F_11 ( char * string , int V_36 )
{
int V_37 = 0 ;
if ( V_36 & V_38 )
string [ V_37 ++ ] = 'r' ;
if ( V_36 & V_13 )
string [ V_37 ++ ] = 'w' ;
if ( V_36 & V_39 )
string [ V_37 ++ ] = 'x' ;
if ( V_36 & V_40 )
string [ V_37 ++ ] = 'a' ;
if ( V_36 & V_41 )
string [ V_37 ++ ] = 't' ;
if ( V_36 & V_14 )
string [ V_37 ++ ] = 'l' ;
string [ V_37 ] = '\0' ;
}
static void F_12 ( struct V_42 * V_43 , void * V_19 )
{
struct V_44 * V_45 = V_19 ;
struct V_46 * V_47 = V_45 -> V_46 ;
F_13 ( V_43 , L_1 ,
V_45 -> V_46 -> V_48 ,
V_47 -> V_49 ? L_2 : L_3 ) ;
F_13 ( V_43 , L_4 ) ;
F_14 ( V_43 , V_47 -> V_50 ) ;
F_13 ( V_43 , L_5 ) ;
F_14 ( V_43 , V_47 -> V_51 ) ;
F_13 ( V_43 , L_6 , V_47 -> V_17 ) ;
}
void F_6 ( char * V_1 , char * V_2 , int V_17 ,
int V_49 , struct V_18 * V_45 )
{
char V_52 [ V_53 + 1 ] ;
struct V_46 * V_47 ;
struct V_44 * V_19 = & V_45 -> V_19 ;
if ( V_49 != 0 && ( V_54 & V_55 ) == 0 )
return;
if ( V_49 == 0 && ( V_54 & V_56 ) == 0 )
return;
V_47 = V_19 -> V_46 ;
if ( V_47 -> V_48 == NULL )
V_47 -> V_48 = L_7 ;
F_11 ( V_52 , V_17 ) ;
V_47 -> V_50 = V_1 ;
V_47 -> V_51 = V_2 ;
V_47 -> V_17 = V_52 ;
V_47 -> V_49 = V_49 ;
F_15 ( V_19 , F_12 , NULL ) ;
}
void F_6 ( char * V_1 , char * V_2 , int V_17 ,
int V_49 , struct V_18 * V_45 )
{
}
void F_16 ( struct V_15 * V_34 )
{
unsigned int V_57 ;
struct V_58 * V_59 ;
V_57 = F_17 ( V_34 -> V_11 , strlen ( V_34 -> V_11 ) ) ;
V_59 = & V_60 [ V_57 & ( V_61 - 1 ) ] ;
F_18 ( & V_34 -> V_62 , V_59 ) ;
F_19 ( & V_34 -> V_63 , & V_64 ) ;
}
struct V_15 * F_20 ( const char * string )
{
unsigned int V_57 ;
struct V_58 * V_59 ;
struct V_15 * V_34 ;
V_57 = F_17 ( string , strlen ( string ) ) ;
V_59 = & V_60 [ V_57 & ( V_61 - 1 ) ] ;
F_21 (skp, head, smk_hashed)
if ( strcmp ( V_34 -> V_11 , string ) == 0 )
return V_34 ;
return NULL ;
}
char * F_22 ( const char * string , int V_65 )
{
char * V_66 ;
int V_37 ;
if ( V_65 <= 0 )
V_65 = strlen ( string ) + 1 ;
if ( string [ 0 ] == '-' )
return NULL ;
for ( V_37 = 0 ; V_37 < V_65 ; V_37 ++ )
if ( string [ V_37 ] > '~' || string [ V_37 ] <= ' ' || string [ V_37 ] == '/' ||
string [ V_37 ] == '"' || string [ V_37 ] == '\\' || string [ V_37 ] == '\'' )
break;
if ( V_37 == 0 || V_37 >= V_67 )
return NULL ;
V_66 = F_23 ( V_37 + 1 , V_68 ) ;
if ( V_66 != NULL ) {
strncpy ( V_66 , string , V_37 + 1 ) ;
V_66 [ V_37 ] = '\0' ;
}
return V_66 ;
}
int F_24 ( int V_69 , char * V_70 , struct V_71 * V_72 ,
int V_65 )
{
unsigned char * V_73 ;
unsigned char V_74 ;
int V_75 ;
int V_21 ;
int V_76 ;
V_72 -> V_77 |= V_78 ;
V_72 -> V_79 . V_80 . V_81 = V_69 ;
V_72 -> V_79 . V_80 . V_75 = F_25 ( V_82 ) ;
if ( ! V_72 -> V_79 . V_80 . V_75 )
return - V_83 ;
V_72 -> V_79 . V_80 . V_75 -> V_84 = 0 ;
for ( V_75 = 1 , V_73 = V_70 , V_76 = 0 ; V_76 < V_65 ; V_73 ++ , V_76 ++ )
for ( V_74 = 0x80 ; V_74 != 0 ; V_74 >>= 1 , V_75 ++ ) {
if ( ( V_74 & * V_73 ) == 0 )
continue;
V_21 = F_26 ( V_72 -> V_79 . V_80 . V_75 ,
V_75 , V_82 ) ;
if ( V_21 < 0 ) {
F_27 ( V_72 -> V_79 . V_80 . V_75 ) ;
return V_21 ;
}
}
return 0 ;
}
struct V_15 * F_28 ( const char * string , int V_65 )
{
struct V_15 * V_34 ;
char * V_66 ;
int V_85 ;
int V_21 ;
V_66 = F_22 ( string , V_65 ) ;
if ( V_66 == NULL )
return NULL ;
F_29 ( & V_86 ) ;
V_34 = F_20 ( V_66 ) ;
if ( V_34 != NULL )
goto V_87;
V_34 = F_23 ( sizeof( * V_34 ) , V_68 ) ;
if ( V_34 == NULL )
goto V_87;
V_34 -> V_11 = V_66 ;
V_34 -> V_88 = V_89 ++ ;
V_34 -> V_90 . V_91 = V_34 -> V_11 ;
V_34 -> V_90 . V_77 =
V_92 | V_93 ;
V_85 = strlen ( V_66 ) ;
if ( V_85 < V_94 )
V_21 = F_24 ( V_95 , V_34 -> V_11 ,
& V_34 -> V_90 , V_85 ) ;
else
V_21 = F_24 ( V_96 , ( char * ) & V_34 -> V_88 ,
& V_34 -> V_90 , sizeof( V_34 -> V_88 ) ) ;
if ( V_21 >= 0 ) {
F_30 ( & V_34 -> V_29 ) ;
F_31 ( & V_34 -> V_97 ) ;
F_16 ( V_34 ) ;
goto V_98;
}
F_32 ( V_34 ) ;
V_34 = NULL ;
V_87:
F_32 ( V_66 ) ;
V_98:
F_33 ( & V_86 ) ;
return V_34 ;
}
char * F_34 ( const char * string , int V_65 )
{
struct V_15 * V_34 ;
if ( string [ 0 ] == '-' )
return NULL ;
V_34 = F_28 ( string , V_65 ) ;
if ( V_34 == NULL )
return NULL ;
return V_34 -> V_11 ;
}
struct V_15 * F_35 ( const T_1 V_99 )
{
struct V_15 * V_34 ;
F_3 () ;
F_2 (skp, &smack_known_list, list) {
if ( V_34 -> V_88 == V_99 ) {
F_4 () ;
return V_34 ;
}
}
F_4 () ;
return & V_100 ;
}
T_1 F_36 ( const char * V_66 )
{
struct V_15 * V_34 = F_20 ( V_66 ) ;
if ( V_34 == NULL )
return 0 ;
return V_34 -> V_88 ;
}
