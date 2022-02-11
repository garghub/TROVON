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
int F_7 ( struct V_30 * V_31 , char * V_32 ,
T_1 V_33 , struct V_18 * V_19 )
{
struct V_15 * V_34 = F_8 ( V_31 ) ;
int V_5 ;
int V_21 ;
V_21 = V_12 ( V_34 , V_32 , V_33 , NULL ) ;
if ( V_21 == 0 ) {
V_5 = F_1 ( V_34 -> V_11 , V_32 ,
& V_31 -> V_29 ) ;
if ( V_5 < 0 )
goto V_24;
if ( ( V_33 & V_5 ) == V_33 )
goto V_24;
V_21 = - V_23 ;
}
if ( V_21 != 0 && F_9 ( V_35 ) )
V_21 = 0 ;
V_24:
#ifdef F_5
if ( V_19 )
F_6 ( V_34 -> V_11 , V_32 , V_33 , V_21 , V_19 ) ;
#endif
return V_21 ;
}
int F_10 ( char * V_32 , T_1 V_33 , struct V_18 * V_19 )
{
struct V_30 * V_36 = F_11 () ;
return F_7 ( V_36 , V_32 , V_33 , V_19 ) ;
}
static inline void F_12 ( char * string , int V_37 )
{
int V_38 = 0 ;
if ( V_37 & V_39 )
string [ V_38 ++ ] = 'r' ;
if ( V_37 & V_13 )
string [ V_38 ++ ] = 'w' ;
if ( V_37 & V_40 )
string [ V_38 ++ ] = 'x' ;
if ( V_37 & V_41 )
string [ V_38 ++ ] = 'a' ;
if ( V_37 & V_42 )
string [ V_38 ++ ] = 't' ;
if ( V_37 & V_14 )
string [ V_38 ++ ] = 'l' ;
string [ V_38 ] = '\0' ;
}
static void F_13 ( struct V_43 * V_44 , void * V_19 )
{
struct V_45 * V_46 = V_19 ;
struct V_47 * V_48 = V_46 -> V_47 ;
F_14 ( V_44 , L_1 ,
V_46 -> V_47 -> V_49 ,
V_48 -> V_50 ? L_2 : L_3 ) ;
F_14 ( V_44 , L_4 ) ;
F_15 ( V_44 , V_48 -> V_31 ) ;
F_14 ( V_44 , L_5 ) ;
F_15 ( V_44 , V_48 -> V_51 ) ;
if ( V_48 -> V_17 [ 0 ] == '\0' )
F_14 ( V_44 , L_6 ) ;
else
F_14 ( V_44 , L_7 , V_48 -> V_17 ) ;
}
void F_6 ( char * V_1 , char * V_2 , int V_17 ,
int V_50 , struct V_18 * V_46 )
{
char V_52 [ V_53 + 1 ] ;
struct V_47 * V_48 ;
struct V_45 * V_19 = & V_46 -> V_19 ;
if ( V_50 != 0 && ( V_54 & V_55 ) == 0 )
return;
if ( V_50 == 0 && ( V_54 & V_56 ) == 0 )
return;
V_48 = V_19 -> V_47 ;
if ( V_48 -> V_49 == NULL )
V_48 -> V_49 = L_8 ;
F_12 ( V_52 , V_17 ) ;
V_48 -> V_31 = V_1 ;
V_48 -> V_51 = V_2 ;
V_48 -> V_17 = V_52 ;
V_48 -> V_50 = V_50 ;
F_16 ( V_19 , F_13 , NULL ) ;
}
void F_6 ( char * V_1 , char * V_2 , int V_17 ,
int V_50 , struct V_18 * V_46 )
{
}
void F_17 ( struct V_15 * V_34 )
{
unsigned int V_57 ;
struct V_58 * V_59 ;
V_57 = F_18 ( V_34 -> V_11 , strlen ( V_34 -> V_11 ) ) ;
V_59 = & V_60 [ V_57 & ( V_61 - 1 ) ] ;
F_19 ( & V_34 -> V_62 , V_59 ) ;
F_20 ( & V_34 -> V_63 , & V_64 ) ;
}
struct V_15 * F_21 ( const char * string )
{
unsigned int V_57 ;
struct V_58 * V_59 ;
struct V_15 * V_34 ;
V_57 = F_18 ( string , strlen ( string ) ) ;
V_59 = & V_60 [ V_57 & ( V_61 - 1 ) ] ;
F_22 (skp, head, smk_hashed)
if ( strcmp ( V_34 -> V_11 , string ) == 0 )
return V_34 ;
return NULL ;
}
char * F_23 ( const char * string , int V_65 )
{
char * V_66 ;
int V_38 ;
if ( V_65 <= 0 )
V_65 = strlen ( string ) + 1 ;
if ( string [ 0 ] == '-' )
return NULL ;
for ( V_38 = 0 ; V_38 < V_65 ; V_38 ++ )
if ( string [ V_38 ] > '~' || string [ V_38 ] <= ' ' || string [ V_38 ] == '/' ||
string [ V_38 ] == '"' || string [ V_38 ] == '\\' || string [ V_38 ] == '\'' )
break;
if ( V_38 == 0 || V_38 >= V_67 )
return NULL ;
V_66 = F_24 ( V_38 + 1 , V_68 ) ;
if ( V_66 != NULL ) {
strncpy ( V_66 , string , V_38 + 1 ) ;
V_66 [ V_38 ] = '\0' ;
}
return V_66 ;
}
int F_25 ( int V_69 , char * V_70 , struct V_71 * V_72 ,
int V_65 )
{
unsigned char * V_73 ;
unsigned char V_74 ;
int V_75 ;
int V_21 ;
int V_76 ;
V_72 -> V_77 |= V_78 ;
V_72 -> V_79 . V_80 . V_81 = V_69 ;
V_72 -> V_79 . V_80 . V_75 = F_26 ( V_82 ) ;
if ( ! V_72 -> V_79 . V_80 . V_75 )
return - V_83 ;
V_72 -> V_79 . V_80 . V_75 -> V_84 = 0 ;
for ( V_75 = 1 , V_73 = V_70 , V_76 = 0 ; V_76 < V_65 ; V_73 ++ , V_76 ++ )
for ( V_74 = 0x80 ; V_74 != 0 ; V_74 >>= 1 , V_75 ++ ) {
if ( ( V_74 & * V_73 ) == 0 )
continue;
V_21 = F_27 ( V_72 -> V_79 . V_80 . V_75 ,
V_75 , V_82 ) ;
if ( V_21 < 0 ) {
F_28 ( V_72 -> V_79 . V_80 . V_75 ) ;
return V_21 ;
}
}
return 0 ;
}
struct V_15 * F_29 ( const char * string , int V_65 )
{
struct V_15 * V_34 ;
char * V_66 ;
int V_85 ;
int V_21 ;
V_66 = F_23 ( string , V_65 ) ;
if ( V_66 == NULL )
return NULL ;
F_30 ( & V_86 ) ;
V_34 = F_21 ( V_66 ) ;
if ( V_34 != NULL )
goto V_87;
V_34 = F_24 ( sizeof( * V_34 ) , V_68 ) ;
if ( V_34 == NULL )
goto V_87;
V_34 -> V_11 = V_66 ;
V_34 -> V_88 = V_89 ++ ;
V_34 -> V_90 . V_91 = V_34 -> V_11 ;
V_34 -> V_90 . V_77 =
V_92 | V_93 ;
V_85 = strlen ( V_66 ) ;
if ( V_85 < V_94 )
V_21 = F_25 ( V_95 , V_34 -> V_11 ,
& V_34 -> V_90 , V_85 ) ;
else
V_21 = F_25 ( V_96 , ( char * ) & V_34 -> V_88 ,
& V_34 -> V_90 , sizeof( V_34 -> V_88 ) ) ;
if ( V_21 >= 0 ) {
F_31 ( & V_34 -> V_29 ) ;
F_32 ( & V_34 -> V_97 ) ;
F_17 ( V_34 ) ;
goto V_98;
}
F_33 ( V_34 ) ;
V_34 = NULL ;
V_87:
F_33 ( V_66 ) ;
V_98:
F_34 ( & V_86 ) ;
return V_34 ;
}
char * F_35 ( const char * string , int V_65 )
{
struct V_15 * V_34 ;
if ( string [ 0 ] == '-' )
return NULL ;
V_34 = F_29 ( string , V_65 ) ;
if ( V_34 == NULL )
return NULL ;
return V_34 -> V_11 ;
}
struct V_15 * F_36 ( const T_1 V_99 )
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
T_1 F_37 ( const char * V_66 )
{
struct V_15 * V_34 = F_21 ( V_66 ) ;
if ( V_34 == NULL )
return 0 ;
return V_34 -> V_88 ;
}
