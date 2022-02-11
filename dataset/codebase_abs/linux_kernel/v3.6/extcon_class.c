static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = 0 ;
if ( ! V_2 -> V_5 )
return 0 ;
for ( V_4 = 0 ; V_2 -> V_5 [ V_4 ] ; V_4 ++ ) {
int V_6 = 0 , V_7 ;
T_1 V_8 = V_3 & V_2 -> V_5 [ V_4 ] ;
T_1 exp = 1 ;
for ( V_7 = 0 ; V_7 < 32 ; V_7 ++ ) {
if ( exp & V_8 )
V_6 ++ ;
if ( V_6 > 1 )
return V_4 + 1 ;
exp <<= 1 ;
}
}
return 0 ;
}
static T_2 F_2 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
int V_4 , V_6 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
if ( V_2 -> V_14 ) {
int V_15 = V_2 -> V_14 ( V_2 , V_13 ) ;
if ( V_15 >= 0 )
return V_15 ;
}
if ( V_2 -> V_16 == 0 )
return sprintf ( V_13 , L_1 , V_2 -> V_17 ) ;
for ( V_4 = 0 ; V_4 < V_18 ; V_4 ++ ) {
if ( ! V_2 -> V_19 [ V_4 ] )
break;
V_6 += sprintf ( V_13 + V_6 , L_2 ,
V_2 -> V_19 [ V_4 ] ,
! ! ( V_2 -> V_17 & ( 1 << V_4 ) ) ) ;
}
return V_6 ;
}
static T_2 F_4 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_13 , T_3 V_6 )
{
T_1 V_17 ;
T_2 V_15 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
V_15 = sscanf ( V_13 , L_3 , & V_17 ) ;
if ( V_15 == 0 )
V_15 = - V_20 ;
else
V_15 = F_5 ( V_2 , V_17 ) ;
if ( V_15 < 0 )
return V_15 ;
return V_6 ;
}
static T_2 F_6 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
if ( V_2 -> V_21 ) {
int V_15 = V_2 -> V_21 ( V_2 , V_13 ) ;
if ( V_15 >= 0 )
return V_15 ;
}
return sprintf ( V_13 , L_4 , F_7 ( V_2 -> V_10 ) ) ;
}
static T_2 F_8 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_22 * V_23 = F_9 ( V_12 , struct V_22 ,
V_24 ) ;
return sprintf ( V_13 , L_4 ,
V_23 -> V_2 -> V_19 [ V_23 -> V_25 ] ) ;
}
static T_2 F_10 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_22 * V_23 = F_9 ( V_12 , struct V_22 ,
V_26 ) ;
return sprintf ( V_13 , L_5 ,
F_11 ( V_23 -> V_2 ,
V_23 -> V_25 ) ) ;
}
static T_2 F_12 ( struct V_9 * V_10 ,
struct V_11 * V_12 , const char * V_13 ,
T_3 V_6 )
{
struct V_22 * V_23 = F_9 ( V_12 , struct V_22 ,
V_26 ) ;
int V_15 , V_17 ;
V_15 = sscanf ( V_13 , L_6 , & V_17 ) ;
if ( V_15 == 0 )
V_15 = - V_20 ;
else
V_15 = F_13 ( V_23 -> V_2 , V_23 -> V_25 ,
V_17 ) ;
if ( V_15 < 0 )
return V_15 ;
return V_6 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_27 , T_1 V_17 )
{
char V_28 [ 120 ] ;
char V_29 [ 120 ] ;
char * V_30 ;
char * V_31 [ 3 ] ;
int V_32 = 0 ;
int V_33 ;
unsigned long V_34 ;
F_15 ( & V_2 -> V_35 , V_34 ) ;
if ( V_2 -> V_17 != ( ( V_2 -> V_17 & ~ V_27 ) | ( V_17 & V_27 ) ) ) {
T_1 V_36 = V_2 -> V_17 ;
if ( F_1 ( V_2 , ( V_2 -> V_17 & ~ V_27 ) |
( V_17 & V_27 ) ) ) {
F_16 ( & V_2 -> V_35 , V_34 ) ;
return - V_37 ;
}
V_2 -> V_17 &= ~ V_27 ;
V_2 -> V_17 |= V_17 & V_27 ;
F_17 ( & V_2 -> V_38 , V_36 , V_2 ) ;
V_30 = ( char * ) F_18 ( V_39 ) ;
if ( V_30 ) {
V_33 = F_6 ( V_2 -> V_10 , NULL , V_30 ) ;
if ( V_33 > 0 ) {
if ( V_30 [ V_33 - 1 ] == '\n' )
V_30 [ V_33 - 1 ] = 0 ;
snprintf ( V_28 , sizeof( V_28 ) ,
L_7 , V_30 ) ;
V_31 [ V_32 ++ ] = V_28 ;
}
V_33 = F_2 ( V_2 -> V_10 , NULL , V_30 ) ;
if ( V_33 > 0 ) {
if ( V_30 [ V_33 - 1 ] == '\n' )
V_30 [ V_33 - 1 ] = 0 ;
snprintf ( V_29 , sizeof( V_29 ) ,
L_8 , V_30 ) ;
V_31 [ V_32 ++ ] = V_29 ;
}
V_31 [ V_32 ] = NULL ;
F_16 ( & V_2 -> V_35 , V_34 ) ;
F_19 ( & V_2 -> V_10 -> V_40 , V_41 , V_31 ) ;
F_20 ( ( unsigned long ) V_30 ) ;
} else {
F_16 ( & V_2 -> V_35 , V_34 ) ;
F_21 ( V_2 -> V_10 , L_9 ) ;
F_22 ( & V_2 -> V_10 -> V_40 , V_41 ) ;
}
} else {
F_16 ( & V_2 -> V_35 , V_34 ) ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_17 )
{
return F_14 ( V_2 , 0xffffffff , V_17 ) ;
}
int F_23 ( struct V_1 * V_2 , const char * V_42 )
{
int V_4 ;
if ( V_2 -> V_19 ) {
for ( V_4 = 0 ; V_2 -> V_19 [ V_4 ] ; V_4 ++ ) {
if ( ! strncmp ( V_2 -> V_19 [ V_4 ] ,
V_42 , V_43 ) )
return V_4 ;
}
}
return - V_20 ;
}
int F_11 ( struct V_1 * V_2 , int V_44 )
{
if ( V_44 < 0 || ( V_2 -> V_16 && V_2 -> V_16 <= V_44 ) )
return - V_20 ;
return ! ! ( V_2 -> V_17 & ( 1 << V_44 ) ) ;
}
int F_24 ( struct V_1 * V_2 , const char * V_42 )
{
return F_11 ( V_2 , F_23
( V_2 , V_42 ) ) ;
}
int F_13 ( struct V_1 * V_2 ,
int V_44 , bool V_45 )
{
T_1 V_17 ;
if ( V_44 < 0 || ( V_2 -> V_16 && V_2 -> V_16 <= V_44 ) )
return - V_20 ;
V_17 = V_45 ? ( 1 << V_44 ) : 0 ;
return F_14 ( V_2 , 1 << V_44 , V_17 ) ;
}
int F_25 ( struct V_1 * V_2 ,
const char * V_42 , bool V_45 )
{
return F_13 ( V_2 , F_23
( V_2 , V_42 ) , V_45 ) ;
}
struct V_1 * F_26 ( const char * V_46 )
{
struct V_1 * V_47 ;
F_27 ( & V_48 ) ;
F_28 (sd, &extcon_dev_list, entry) {
if ( ! strcmp ( V_47 -> V_49 , V_46 ) )
goto V_50;
}
V_47 = NULL ;
V_50:
F_29 ( & V_48 ) ;
return V_47 ;
}
static int F_30 ( struct V_51 * V_52 , unsigned long V_53 ,
void * V_54 )
{
struct V_55 * V_56 = F_9 ( V_52 ,
struct V_55 , V_57 ) ;
struct V_1 * V_2 = V_54 ;
if ( ( V_53 & ( 1 << V_56 -> V_25 ) ) !=
( V_2 -> V_17 & ( 1 << V_56 -> V_25 ) ) ) {
bool V_45 = true ;
V_56 -> V_58 = V_53 ;
if ( V_53 & ( 1 << V_56 -> V_25 ) )
V_45 = false ;
return V_56 -> V_59 -> V_60 ( V_56 -> V_59 ,
V_45 , V_54 ) ;
}
return V_61 ;
}
int F_31 ( struct V_55 * V_56 ,
const char * V_46 , const char * V_42 ,
struct V_51 * V_52 )
{
if ( ! V_56 || ! V_46 || ! V_42 || ! V_52 )
return - V_20 ;
V_56 -> V_2 = F_26 ( V_46 ) ;
if ( ! V_56 -> V_2 )
return - V_62 ;
V_56 -> V_25 = F_23 ( V_56 -> V_2 , V_42 ) ;
if ( V_56 -> V_25 < 0 )
return - V_62 ;
V_56 -> V_59 = V_52 ;
V_56 -> V_57 . V_60 = F_30 ;
return F_32 ( & V_56 -> V_2 -> V_38 , & V_56 -> V_57 ) ;
}
int F_33 ( struct V_55 * V_56 )
{
if ( ! V_56 )
return - V_20 ;
return F_34 ( & V_56 -> V_2 -> V_38 , & V_56 -> V_57 ) ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
return F_32 ( & V_2 -> V_38 , V_52 ) ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
return F_34 ( & V_2 -> V_38 , V_52 ) ;
}
static int F_37 ( void )
{
if ( ! V_63 ) {
V_63 = F_38 ( V_64 , L_10 ) ;
if ( F_39 ( V_63 ) )
return F_40 ( V_63 ) ;
V_63 -> V_65 = V_66 ;
#if F_41 ( V_67 )
V_68 = F_42 ( L_11 ) ;
if ( F_43 ( ! V_68 , L_12 ) )
return - V_69 ;
#endif
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , bool V_70 )
{
F_27 ( & V_48 ) ;
F_45 ( & V_2 -> V_71 ) ;
F_29 ( & V_48 ) ;
if ( ! V_70 && F_46 ( V_2 -> V_10 ) ) {
int V_44 ;
if ( V_2 -> V_5 && V_2 -> V_16 ) {
for ( V_44 = 0 ; V_2 -> V_5 [ V_44 ] ;
V_44 ++ )
F_47 ( V_2 -> V_72 [ V_44 ] . V_12 . V_49 ) ;
F_47 ( V_2 -> V_72 ) ;
F_47 ( V_2 -> V_73 ) ;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_16 ; V_44 ++ )
F_47 ( V_2 -> V_74 [ V_44 ] . V_75 . V_49 ) ;
if ( V_2 -> V_16 ) {
F_47 ( V_2 -> V_76 . V_77 ) ;
F_47 ( V_2 -> V_74 ) ;
}
F_48 ( V_2 -> V_10 ) ;
F_49 ( V_2 -> V_10 ) ;
}
F_47 ( V_2 -> V_10 ) ;
}
static void F_50 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = (struct V_1 * ) F_3 ( V_10 ) ;
F_44 ( V_2 , true ) ;
}
static void F_51 ( struct V_9 * V_10 )
{
}
int F_52 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_15 , V_44 = 0 ;
if ( ! V_63 ) {
V_15 = F_37 () ;
if ( V_15 < 0 )
return V_15 ;
}
if ( V_2 -> V_19 ) {
for ( V_44 = 0 ; V_2 -> V_19 [ V_44 ] ; V_44 ++ )
;
V_2 -> V_16 = V_44 ;
} else {
V_2 -> V_16 = 0 ;
}
if ( V_44 > V_18 ) {
F_21 ( V_2 -> V_10 , L_13 ) ;
return - V_20 ;
}
V_2 -> V_10 = F_53 ( sizeof( struct V_9 ) , V_78 ) ;
if ( ! V_2 -> V_10 )
return - V_69 ;
V_2 -> V_10 -> V_79 = V_10 ;
V_2 -> V_10 -> V_80 = V_63 ;
V_2 -> V_10 -> V_81 = F_50 ;
F_54 ( V_2 -> V_10 , V_2 -> V_49 ? V_2 -> V_49 : F_7 ( V_10 ) ) ;
if ( V_2 -> V_16 ) {
char V_13 [ 10 ] ;
char * V_82 ;
struct V_22 * V_23 ;
V_2 -> V_74 = F_53 ( sizeof( struct V_22 ) *
V_2 -> V_16 , V_78 ) ;
if ( ! V_2 -> V_74 ) {
V_15 = - V_69 ;
goto V_83;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_16 ; V_44 ++ ) {
V_23 = & V_2 -> V_74 [ V_44 ] ;
snprintf ( V_13 , 10 , L_14 , V_44 ) ;
V_82 = F_53 ( sizeof( char ) * ( strlen ( V_13 ) + 1 ) ,
V_78 ) ;
if ( ! V_82 ) {
for ( V_44 -- ; V_44 >= 0 ; V_44 -- ) {
V_23 = & V_2 -> V_74 [ V_44 ] ;
F_47 ( V_23 -> V_75 . V_49 ) ;
}
V_15 = - V_69 ;
goto V_84;
}
strcpy ( V_82 , V_13 ) ;
V_23 -> V_2 = V_2 ;
V_23 -> V_25 = V_44 ;
V_23 -> V_85 [ 0 ] = & V_23 -> V_24 . V_12 ;
V_23 -> V_85 [ 1 ] = & V_23 -> V_26 . V_12 ;
V_23 -> V_85 [ 2 ] = NULL ;
V_23 -> V_75 . V_49 = V_82 ;
V_23 -> V_75 . V_85 = V_23 -> V_85 ;
V_23 -> V_24 . V_12 . V_49 = L_15 ;
V_23 -> V_24 . V_12 . V_86 = 0444 ;
V_23 -> V_24 . V_87 = F_8 ;
V_23 -> V_26 . V_12 . V_49 = L_16 ;
V_23 -> V_26 . V_12 . V_86 = 0644 ;
V_23 -> V_26 . V_87 = F_10 ;
V_23 -> V_26 . V_88 = F_12 ;
}
}
if ( V_2 -> V_16 && V_2 -> V_5 ) {
char V_13 [ 80 ] ;
char * V_49 ;
for ( V_44 = 0 ; V_2 -> V_5 [ V_44 ] ; V_44 ++ )
;
V_2 -> V_73 = F_53 ( sizeof( struct V_89 * ) *
( V_44 + 1 ) , V_78 ) ;
if ( ! V_2 -> V_73 ) {
V_15 = - V_69 ;
goto V_90;
}
V_2 -> V_72 = F_53 ( sizeof( struct V_11 ) *
V_44 , V_78 ) ;
if ( ! V_2 -> V_72 ) {
V_15 = - V_69 ;
F_47 ( V_2 -> V_73 ) ;
goto V_90;
}
for ( V_44 = 0 ; V_2 -> V_5 [ V_44 ] ; V_44 ++ ) {
sprintf ( V_13 , L_3 , V_2 -> V_5 [ V_44 ] ) ;
V_49 = F_53 ( sizeof( char ) * ( strlen ( V_13 ) + 1 ) ,
V_78 ) ;
if ( ! V_49 ) {
for ( V_44 -- ; V_44 >= 0 ; V_44 -- ) {
F_47 ( V_2 -> V_72 [ V_44 ] . V_12 .
V_49 ) ;
}
F_47 ( V_2 -> V_72 ) ;
F_47 ( V_2 -> V_73 ) ;
V_15 = - V_69 ;
goto V_90;
}
strcpy ( V_49 , V_13 ) ;
V_2 -> V_72 [ V_44 ] . V_12 . V_49 = V_49 ;
V_2 -> V_72 [ V_44 ] . V_12 . V_86 = 0000 ;
V_2 -> V_73 [ V_44 ] = & V_2 -> V_72 [ V_44 ]
. V_12 ;
}
V_2 -> V_91 . V_49 = V_92 ;
V_2 -> V_91 . V_85 = V_2 -> V_73 ;
}
if ( V_2 -> V_16 ) {
V_2 -> V_76 . V_77 =
F_53 ( sizeof( struct V_93 * ) *
( V_2 -> V_16 + 2 ) , V_78 ) ;
if ( ! V_2 -> V_76 . V_77 ) {
V_15 = - V_69 ;
goto V_94;
}
V_2 -> V_76 . V_49 = F_7 ( V_2 -> V_10 ) ;
V_2 -> V_76 . V_81 = F_51 ;
for ( V_44 = 0 ; V_44 < V_2 -> V_16 ; V_44 ++ )
V_2 -> V_76 . V_77 [ V_44 ] =
& V_2 -> V_74 [ V_44 ] . V_75 ;
if ( V_2 -> V_5 )
V_2 -> V_76 . V_77 [ V_44 ] =
& V_2 -> V_91 ;
V_2 -> V_10 -> type = & V_2 -> V_76 ;
}
V_15 = F_55 ( V_2 -> V_10 ) ;
if ( V_15 ) {
F_49 ( V_2 -> V_10 ) ;
goto V_95;
}
#if F_41 ( V_67 )
if ( V_68 )
V_15 = F_56 ( V_68 , V_2 -> V_10 ,
NULL ) ;
#endif
F_57 ( & V_2 -> V_35 ) ;
F_58 ( & V_2 -> V_38 ) ;
F_59 ( V_2 -> V_10 , V_2 ) ;
V_2 -> V_17 = 0 ;
F_27 ( & V_48 ) ;
F_60 ( & V_2 -> V_71 , & V_96 ) ;
F_29 ( & V_48 ) ;
return 0 ;
V_95:
if ( V_2 -> V_16 )
F_47 ( V_2 -> V_76 . V_77 ) ;
V_94:
if ( V_2 -> V_16 && V_2 -> V_5 ) {
for ( V_44 = 0 ; V_2 -> V_5 [ V_44 ] ; V_44 ++ )
F_47 ( V_2 -> V_72 [ V_44 ] . V_12 . V_49 ) ;
F_47 ( V_2 -> V_72 ) ;
F_47 ( V_2 -> V_73 ) ;
}
V_90:
for ( V_44 = 0 ; V_44 < V_2 -> V_16 ; V_44 ++ )
F_47 ( V_2 -> V_74 [ V_44 ] . V_75 . V_49 ) ;
V_84:
if ( V_2 -> V_16 )
F_47 ( V_2 -> V_74 ) ;
V_83:
F_47 ( V_2 -> V_10 ) ;
return V_15 ;
}
void F_61 ( struct V_1 * V_2 )
{
F_44 ( V_2 , false ) ;
}
static int T_4 F_62 ( void )
{
return F_37 () ;
}
static void T_5 F_63 ( void )
{
F_64 ( V_63 ) ;
}
