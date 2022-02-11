struct V_1 * F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_3 * V_5 ,
bool V_6 )
{
struct V_1 * V_1 ;
T_1 V_7 ;
const char * V_8 ;
char * V_9 , * V_10 ;
int V_11 ;
if ( V_4 ) {
V_8 = V_4 -> V_12 ;
V_11 = V_4 -> V_11 ;
} else {
V_8 = V_5 -> V_12 ;
V_11 = V_5 -> V_11 ;
}
V_10 = V_9 = F_2 ( 2 + 1 + V_11 * 2 + 1 , V_13 ) ;
if ( ! V_9 )
return F_3 ( - V_14 ) ;
if ( V_6 ) {
* V_10 ++ = 'i' ;
* V_10 ++ = 'd' ;
} else {
* V_10 ++ = 'e' ;
* V_10 ++ = 'x' ;
}
* V_10 ++ = ':' ;
V_10 = F_4 ( V_10 , V_8 , V_11 ) ;
* V_10 = 0 ;
F_5 ( L_1 , V_9 ) ;
V_7 = F_6 ( F_7 ( V_2 , 1 ) ,
& V_15 , V_9 ) ;
if ( F_8 ( V_7 ) )
F_5 ( L_2 , V_9 , F_9 ( V_7 ) ) ;
F_10 ( V_9 ) ;
if ( F_8 ( V_7 ) ) {
switch ( F_9 ( V_7 ) ) {
case - V_16 :
case - V_17 :
case - V_18 :
return F_3 ( - V_19 ) ;
default:
return F_11 ( V_7 ) ;
}
}
V_1 = F_12 ( V_7 ) ;
if ( V_4 && V_5 ) {
const struct V_20 * V_21 = V_20 ( V_1 ) ;
if ( ! V_21 -> V_22 [ 0 ] ) {
F_5 ( L_3 ) ;
goto V_23;
}
if ( ! F_13 ( V_5 , V_21 -> V_22 [ 1 ] ) ) {
F_5 ( L_4 ) ;
goto V_23;
}
}
F_14 ( L_5 , V_24 , F_15 ( V_1 ) ) ;
return V_1 ;
V_23:
F_16 ( V_1 ) ;
return F_3 ( - V_25 ) ;
}
struct V_3 * F_17 ( const void * V_26 ,
T_2 V_27 ,
const void * V_28 ,
T_2 V_29 )
{
struct V_3 * V_30 ;
V_30 = F_2 ( sizeof( struct V_3 ) + V_27 + V_29 ,
V_13 ) ;
if ( ! V_30 )
return F_3 ( - V_14 ) ;
V_30 -> V_11 = V_27 + V_29 ;
memcpy ( V_30 -> V_12 , V_26 , V_27 ) ;
memcpy ( V_30 -> V_12 + V_27 , V_28 , V_29 ) ;
return V_30 ;
}
bool F_13 ( const struct V_3 * V_31 ,
const struct V_3 * V_32 )
{
if ( ! V_31 || ! V_32 )
return false ;
if ( V_31 -> V_11 != V_32 -> V_11 )
return false ;
return memcmp ( V_31 -> V_12 , V_32 -> V_12 , V_31 -> V_11 ) == 0 ;
}
bool F_18 ( const struct V_3 * V_31 ,
const struct V_3 * V_32 )
{
if ( ! V_31 || ! V_32 )
return false ;
if ( V_31 -> V_11 < V_32 -> V_11 )
return false ;
return memcmp ( V_31 -> V_12 + ( V_31 -> V_11 - V_32 -> V_11 ) ,
V_32 -> V_12 , V_32 -> V_11 ) == 0 ;
}
static bool F_19 (
const struct V_20 * V_21 ,
const struct V_3 * V_33 ,
bool (* F_20)( const struct V_3 * V_31 ,
const struct V_3 * V_32 ) )
{
int V_34 ;
if ( ! V_21 || ! V_33 )
return false ;
for ( V_34 = 0 ; V_34 < F_21 ( V_21 -> V_22 ) ; V_34 ++ )
if ( F_20 ( V_21 -> V_22 [ V_34 ] , V_33 ) )
return true ;
return false ;
}
inline int F_22 ( const char * V_22 ,
struct V_3 * V_33 ,
T_2 V_35 )
{
V_33 -> V_11 = V_35 ;
return F_23 ( V_33 -> V_12 , V_22 , V_35 ) ;
}
struct V_3 * F_24 ( const char * V_22 )
{
struct V_3 * V_33 ;
T_2 V_36 ;
int V_37 ;
if ( ! * V_22 )
return F_3 ( - V_38 ) ;
V_36 = strlen ( V_22 ) ;
if ( V_36 & 1 )
return F_3 ( - V_38 ) ;
V_33 = F_2 ( sizeof( struct V_3 ) + V_36 / 2 ,
V_13 ) ;
if ( ! V_33 )
return F_3 ( - V_14 ) ;
V_37 = F_22 ( V_22 , V_33 , V_36 / 2 ) ;
if ( V_37 < 0 ) {
F_10 ( V_33 ) ;
return F_3 ( - V_38 ) ;
}
return V_33 ;
}
static bool F_25 ( const struct V_1 * V_1 ,
const struct V_39 * V_40 )
{
const struct V_20 * V_21 = V_20 ( V_1 ) ;
const struct V_3 * V_33 = V_40 -> V_41 ;
return F_19 ( V_21 , V_33 ,
F_13 ) ;
}
static bool F_26 ( const struct V_1 * V_1 ,
const struct V_39 * V_40 )
{
const struct V_20 * V_21 = V_20 ( V_1 ) ;
const struct V_3 * V_33 = V_40 -> V_41 ;
return F_19 ( V_21 , V_33 ,
F_18 ) ;
}
static int F_27 ( struct V_39 * V_40 )
{
struct V_3 * V_33 ;
const char * V_42 = V_40 -> V_43 ;
const char * V_22 ;
bool (* F_28)( const struct V_1 * , const struct V_39 * ) =
F_25 ;
if ( ! V_42 || ! * V_42 )
return - V_38 ;
if ( V_42 [ 0 ] == 'i' &&
V_42 [ 1 ] == 'd' &&
V_42 [ 2 ] == ':' ) {
V_22 = V_42 + 3 ;
F_28 = F_26 ;
} else if ( V_42 [ 0 ] == 'e' &&
V_42 [ 1 ] == 'x' &&
V_42 [ 2 ] == ':' ) {
V_22 = V_42 + 3 ;
} else {
goto V_44;
}
V_33 = F_24 ( V_22 ) ;
if ( F_8 ( V_33 ) )
return F_9 ( V_33 ) ;
V_40 -> V_41 = V_33 ;
V_40 -> F_28 = F_28 ;
V_40 -> V_45 = V_46 ;
return 0 ;
V_44:
return 0 ;
}
static void F_29 ( struct V_39 * V_40 )
{
F_10 ( V_40 -> V_41 ) ;
}
static void F_30 ( const struct V_1 * V_1 , struct V_47 * V_48 )
{
const struct V_49 * V_50 = V_49 ( V_1 ) ;
const struct V_20 * V_21 = V_20 ( V_1 ) ;
const struct V_3 * V_30 ;
const unsigned char * V_10 ;
int V_51 ;
F_31 ( V_48 , V_1 -> V_52 ) ;
if ( V_50 ) {
F_31 ( V_48 , L_6 ) ;
V_50 -> V_53 ( V_1 , V_48 ) ;
if ( V_21 && V_21 -> V_22 [ 1 ] ) {
V_30 = V_21 -> V_22 [ 1 ] ;
F_32 ( V_48 , ' ' ) ;
V_51 = V_30 -> V_11 ;
V_10 = V_30 -> V_12 ;
if ( V_51 > 4 ) {
V_10 += V_51 - 4 ;
V_51 = 4 ;
}
F_33 ( V_48 , L_7 , V_51 , V_10 ) ;
}
F_31 ( V_48 , L_8 ) ;
F_32 ( V_48 , ']' ) ;
}
}
static int F_34 ( struct V_54 * V_55 )
{
struct V_56 * V_57 ;
int V_37 ;
F_14 ( L_9 , V_24 ) ;
if ( V_55 -> V_58 == 0 )
return - V_38 ;
F_35 ( & V_59 ) ;
V_37 = - V_60 ;
F_36 (parser, &asymmetric_key_parsers, link) {
F_5 ( L_10 , V_57 -> V_61 ) ;
V_37 = V_57 -> V_62 ( V_55 ) ;
if ( V_37 != - V_60 ) {
F_5 ( L_11 ,
V_37 ) ;
break;
}
}
F_37 ( & V_59 ) ;
F_14 ( L_12 , V_24 , V_37 ) ;
return V_37 ;
}
static void F_38 ( struct V_20 * V_21 )
{
int V_34 ;
if ( V_21 ) {
for ( V_34 = 0 ; V_34 < F_21 ( V_21 -> V_22 ) ; V_34 ++ )
F_10 ( V_21 -> V_22 [ V_34 ] ) ;
F_10 ( V_21 ) ;
}
}
static void F_39 ( struct V_54 * V_55 )
{
struct V_49 * V_50 = V_55 -> V_63 . V_12 [ V_64 ] ;
struct V_20 * V_21 = V_55 -> V_63 . V_12 [ V_65 ] ;
F_14 ( L_9 , V_24 ) ;
if ( V_50 ) {
V_50 -> V_66 ( V_55 -> V_63 . V_12 [ V_67 ] ,
V_55 -> V_63 . V_12 [ V_68 ] ) ;
F_40 ( V_50 -> V_69 ) ;
}
F_38 ( V_21 ) ;
F_10 ( V_55 -> V_52 ) ;
}
static void F_41 ( struct V_1 * V_1 )
{
struct V_49 * V_50 = V_49 ( V_1 ) ;
struct V_20 * V_21 = V_1 -> V_63 . V_12 [ V_65 ] ;
void * V_12 = V_1 -> V_63 . V_12 [ V_67 ] ;
void * V_70 = V_1 -> V_63 . V_12 [ V_68 ] ;
V_1 -> V_63 . V_12 [ V_67 ] = NULL ;
V_1 -> V_63 . V_12 [ V_64 ] = NULL ;
V_1 -> V_63 . V_12 [ V_65 ] = NULL ;
V_1 -> V_63 . V_12 [ V_68 ] = NULL ;
if ( V_50 ) {
V_50 -> V_66 ( V_12 , V_70 ) ;
F_40 ( V_50 -> V_69 ) ;
}
F_38 ( V_21 ) ;
}
static struct V_71 * F_42 (
T_3 V_72 ,
struct V_1 * V_1 )
{
struct V_71 * V_73 =
F_43 ( sizeof( struct V_71 ) , V_13 ) ;
if ( ! V_73 )
return F_3 ( - V_14 ) ;
V_73 -> V_72 = V_72 ;
V_73 -> V_1 = V_1 ;
V_73 -> V_74 = & V_15 ;
return V_73 ;
}
static struct V_71 * F_44 (
const char * V_75 )
{
char * V_76 ;
char * V_77 ;
char * V_78 ;
struct V_71 * V_37 = F_3 ( - V_38 ) ;
if ( strcmp ( L_13 , V_75 ) == 0 )
return F_42 (
V_79 , NULL ) ;
if ( strcmp ( L_14 , V_75 ) == 0 )
return F_42 (
V_80 , NULL ) ;
V_77 = F_45 ( V_75 , V_81 , V_13 ) ;
if ( ! V_77 )
return F_3 ( - V_14 ) ;
V_78 = V_77 ;
V_76 = F_46 ( & V_78 , L_15 ) ;
if ( ( strcmp ( V_76 , L_16 ) == 0 ) && V_78 ) {
char * V_82 ;
T_4 V_83 ;
struct V_1 * V_1 ;
T_3 V_84 =
V_85 ;
bool V_86 = false ;
V_82 = F_46 ( & V_78 , L_15 ) ;
if ( V_78 ) {
if ( strcmp ( V_78 , L_17 ) != 0 )
goto V_87;
V_84 = V_88 ;
V_86 = true ;
}
if ( F_47 ( V_82 , 0 , & V_83 ) < 0 )
goto V_87;
if ( ( V_83 == 0 ) && V_86 ) {
V_1 = NULL ;
} else {
V_1 = F_48 ( V_83 ) ;
if ( F_8 ( V_1 ) ) {
V_37 = F_11 ( V_1 ) ;
goto V_87;
}
}
V_37 = F_42 ( V_84 , V_1 ) ;
if ( F_8 ( V_37 ) )
F_16 ( V_1 ) ;
}
V_87:
F_10 ( V_77 ) ;
return V_37 ;
}
int F_49 ( struct V_56 * V_57 )
{
struct V_56 * V_89 ;
int V_37 ;
F_50 ( & V_59 ) ;
F_36 (cursor, &asymmetric_key_parsers, link) {
if ( strcmp ( V_89 -> V_61 , V_57 -> V_61 ) == 0 ) {
F_51 ( L_18 ,
V_57 -> V_61 ) ;
V_37 = - V_90 ;
goto V_87;
}
}
F_52 ( & V_57 -> V_91 , & V_92 ) ;
F_53 ( L_19 , V_57 -> V_61 ) ;
V_37 = 0 ;
V_87:
F_54 ( & V_59 ) ;
return V_37 ;
}
void F_55 ( struct V_56 * V_57 )
{
F_50 ( & V_59 ) ;
F_56 ( & V_57 -> V_91 ) ;
F_54 ( & V_59 ) ;
F_53 ( L_20 , V_57 -> V_61 ) ;
}
static int T_5 F_57 ( void )
{
return F_58 ( & V_15 ) ;
}
static void T_6 F_59 ( void )
{
F_60 ( & V_15 ) ;
}
