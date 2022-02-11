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
V_22 = V_31 ;
#endif
V_25:
#ifdef F_6
if ( V_20 )
F_7 ( V_16 -> V_10 , V_17 -> V_10 ,
V_18 , V_22 , V_20 ) ;
#endif
return V_22 ;
}
int F_8 ( struct V_32 * V_33 , struct V_15 * V_34 ,
T_1 V_35 , struct V_19 * V_20 )
{
struct V_15 * V_36 = F_9 ( V_33 ) ;
int V_5 ;
int V_22 ;
V_22 = V_12 ( V_36 , V_34 , V_35 , NULL ) ;
if ( V_22 >= 0 ) {
V_5 = F_1 ( V_36 -> V_10 ,
V_34 -> V_10 ,
& V_33 -> V_30 ) ;
if ( V_5 < 0 )
goto V_25;
if ( ( V_35 & V_5 ) == V_35 )
goto V_25;
V_22 = - V_24 ;
}
if ( V_22 != 0 && F_10 ( V_37 ) )
V_22 = 0 ;
V_25:
#ifdef F_6
if ( V_20 )
F_7 ( V_36 -> V_10 , V_34 -> V_10 ,
V_35 , V_22 , V_20 ) ;
#endif
return V_22 ;
}
int F_11 ( struct V_15 * V_34 ,
T_1 V_35 , struct V_19 * V_20 )
{
struct V_32 * V_33 = F_12 () ;
return F_8 ( V_33 , V_34 , V_35 , V_20 ) ;
}
static inline void F_13 ( char * string , int V_38 )
{
int V_39 = 0 ;
if ( V_38 & V_40 )
string [ V_39 ++ ] = 'r' ;
if ( V_38 & V_13 )
string [ V_39 ++ ] = 'w' ;
if ( V_38 & V_41 )
string [ V_39 ++ ] = 'x' ;
if ( V_38 & V_42 )
string [ V_39 ++ ] = 'a' ;
if ( V_38 & V_43 )
string [ V_39 ++ ] = 't' ;
if ( V_38 & V_14 )
string [ V_39 ++ ] = 'l' ;
string [ V_39 ] = '\0' ;
}
static void F_14 ( struct V_44 * V_45 , void * V_20 )
{
struct V_46 * V_47 = V_20 ;
struct V_48 * V_49 = V_47 -> V_48 ;
F_15 ( V_45 , L_1 ,
V_47 -> V_48 -> V_50 ,
V_49 -> V_51 ? L_2 : L_3 ) ;
F_15 ( V_45 , L_4 ) ;
F_16 ( V_45 , V_49 -> V_16 ) ;
F_15 ( V_45 , L_5 ) ;
F_16 ( V_45 , V_49 -> V_17 ) ;
if ( V_49 -> V_18 [ 0 ] == '\0' )
F_15 ( V_45 , L_6 ) ;
else
F_15 ( V_45 , L_7 , V_49 -> V_18 ) ;
}
void F_7 ( char * V_1 , char * V_2 , int V_18 ,
int V_51 , struct V_19 * V_47 )
{
char V_52 [ V_53 + 1 ] ;
struct V_48 * V_49 ;
struct V_46 * V_20 = & V_47 -> V_20 ;
#ifdef F_5
if ( V_51 > 0 )
V_51 = 0 ;
#endif
if ( V_51 != 0 && ( V_54 & V_55 ) == 0 )
return;
if ( V_51 == 0 && ( V_54 & V_56 ) == 0 )
return;
V_49 = V_20 -> V_48 ;
if ( V_49 -> V_50 == NULL )
V_49 -> V_50 = L_8 ;
F_13 ( V_52 , V_18 ) ;
V_49 -> V_16 = V_1 ;
V_49 -> V_17 = V_2 ;
V_49 -> V_18 = V_52 ;
V_49 -> V_51 = V_51 ;
F_17 ( V_20 , F_14 , NULL ) ;
}
void F_7 ( char * V_1 , char * V_2 , int V_18 ,
int V_51 , struct V_19 * V_47 )
{
}
void F_18 ( struct V_15 * V_57 )
{
unsigned int V_58 ;
struct V_59 * V_60 ;
V_58 = F_19 ( V_57 -> V_10 , strlen ( V_57 -> V_10 ) ) ;
V_60 = & V_61 [ V_58 & ( V_62 - 1 ) ] ;
F_20 ( & V_57 -> V_63 , V_60 ) ;
F_21 ( & V_57 -> V_64 , & V_65 ) ;
}
struct V_15 * F_22 ( const char * string )
{
unsigned int V_58 ;
struct V_59 * V_60 ;
struct V_15 * V_57 ;
V_58 = F_19 ( string , strlen ( string ) ) ;
V_60 = & V_61 [ V_58 & ( V_62 - 1 ) ] ;
F_23 (skp, head, smk_hashed)
if ( strcmp ( V_57 -> V_10 , string ) == 0 )
return V_57 ;
return NULL ;
}
char * F_24 ( const char * string , int V_66 )
{
char * V_67 ;
int V_39 ;
if ( V_66 <= 0 )
V_66 = strlen ( string ) + 1 ;
if ( string [ 0 ] == '-' )
return NULL ;
for ( V_39 = 0 ; V_39 < V_66 ; V_39 ++ )
if ( string [ V_39 ] > '~' || string [ V_39 ] <= ' ' || string [ V_39 ] == '/' ||
string [ V_39 ] == '"' || string [ V_39 ] == '\\' || string [ V_39 ] == '\'' )
break;
if ( V_39 == 0 || V_39 >= V_68 )
return NULL ;
V_67 = F_25 ( V_39 + 1 , V_69 ) ;
if ( V_67 != NULL )
strncpy ( V_67 , string , V_39 ) ;
return V_67 ;
}
int F_26 ( int V_70 , char * V_71 , struct V_72 * V_73 ,
int V_66 )
{
unsigned char * V_74 ;
unsigned char V_75 ;
int V_76 ;
int V_22 ;
int V_77 ;
V_73 -> V_78 |= V_79 ;
V_73 -> V_80 . V_81 . V_82 = V_70 ;
V_73 -> V_80 . V_81 . V_76 = NULL ;
for ( V_76 = 1 , V_74 = V_71 , V_77 = 0 ; V_77 < V_66 ; V_74 ++ , V_77 ++ )
for ( V_75 = 0x80 ; V_75 != 0 ; V_75 >>= 1 , V_76 ++ ) {
if ( ( V_75 & * V_74 ) == 0 )
continue;
V_22 = F_27 ( & V_73 -> V_80 . V_81 . V_76 ,
V_76 , V_83 ) ;
if ( V_22 < 0 ) {
F_28 ( V_73 -> V_80 . V_81 . V_76 ) ;
return V_22 ;
}
}
return 0 ;
}
struct V_15 * F_29 ( const char * string , int V_66 )
{
struct V_15 * V_57 ;
char * V_67 ;
int V_84 ;
int V_22 ;
V_67 = F_24 ( string , V_66 ) ;
if ( V_67 == NULL )
return NULL ;
F_30 ( & V_85 ) ;
V_57 = F_22 ( V_67 ) ;
if ( V_57 != NULL )
goto V_86;
V_57 = F_25 ( sizeof( * V_57 ) , V_69 ) ;
if ( V_57 == NULL )
goto V_86;
V_57 -> V_10 = V_67 ;
V_57 -> V_87 = V_88 ++ ;
V_57 -> V_89 . V_90 = V_57 -> V_10 ;
V_57 -> V_89 . V_78 =
V_91 | V_92 ;
V_84 = strlen ( V_67 ) ;
if ( V_84 < V_93 )
V_22 = F_26 ( V_94 , V_57 -> V_10 ,
& V_57 -> V_89 , V_84 ) ;
else
V_22 = F_26 ( V_95 , ( char * ) & V_57 -> V_87 ,
& V_57 -> V_89 , sizeof( V_57 -> V_87 ) ) ;
if ( V_22 >= 0 ) {
F_31 ( & V_57 -> V_30 ) ;
F_32 ( & V_57 -> V_96 ) ;
F_18 ( V_57 ) ;
goto V_97;
}
F_33 ( V_57 ) ;
V_57 = NULL ;
V_86:
F_33 ( V_67 ) ;
V_97:
F_34 ( & V_85 ) ;
return V_57 ;
}
struct V_15 * F_35 ( const T_1 V_98 )
{
struct V_15 * V_57 ;
F_3 () ;
F_2 (skp, &smack_known_list, list) {
if ( V_57 -> V_87 == V_98 ) {
F_4 () ;
return V_57 ;
}
}
F_4 () ;
return & V_99 ;
}
