static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = 0 ;
if ( ! V_2 -> V_5 )
return 0 ;
for ( V_4 = 0 ; V_2 -> V_5 [ V_4 ] ; V_4 ++ ) {
int V_6 ;
T_1 V_7 = V_3 & V_2 -> V_5 [ V_4 ] ;
V_6 = F_2 ( V_7 ) ;
if ( V_6 > 1 )
return V_4 + 1 ;
}
return 0 ;
}
static T_2 F_3 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
int V_4 , V_13 = 0 ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
if ( V_2 -> V_14 ) {
int V_15 = V_2 -> V_14 ( V_2 , V_12 ) ;
if ( V_15 >= 0 )
return V_15 ;
}
if ( V_2 -> V_16 == 0 )
return sprintf ( V_12 , L_1 , V_2 -> V_17 ) ;
for ( V_4 = 0 ; V_4 < V_18 ; V_4 ++ ) {
if ( ! V_2 -> V_19 [ V_4 ] )
break;
V_13 += sprintf ( V_12 + V_13 , L_2 ,
V_2 -> V_19 [ V_4 ] ,
! ! ( V_2 -> V_17 & ( 1 << V_4 ) ) ) ;
}
return V_13 ;
}
static T_2 F_5 ( struct V_8 * V_9 , struct V_10 * V_11 ,
const char * V_12 , T_3 V_13 )
{
T_1 V_17 ;
T_2 V_15 = 0 ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
V_15 = sscanf ( V_12 , L_3 , & V_17 ) ;
if ( V_15 == 0 )
V_15 = - V_20 ;
else
V_15 = F_6 ( V_2 , V_17 ) ;
if ( V_15 < 0 )
return V_15 ;
return V_13 ;
}
static T_2 F_7 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
if ( V_2 -> V_21 ) {
int V_15 = V_2 -> V_21 ( V_2 , V_12 ) ;
if ( V_15 >= 0 )
return V_15 ;
}
return sprintf ( V_12 , L_4 , F_8 ( & V_2 -> V_9 ) ) ;
}
static T_2 F_9 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_22 * V_23 = F_10 ( V_11 , struct V_22 ,
V_24 ) ;
return sprintf ( V_12 , L_4 ,
V_23 -> V_2 -> V_19 [ V_23 -> V_25 ] ) ;
}
static T_2 F_11 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_22 * V_23 = F_10 ( V_11 , struct V_22 ,
V_26 ) ;
return sprintf ( V_12 , L_5 ,
F_12 ( V_23 -> V_2 ,
V_23 -> V_25 ) ) ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_27 , T_1 V_17 )
{
char V_28 [ 120 ] ;
char V_29 [ 120 ] ;
char * V_30 ;
char * V_31 [ 3 ] ;
int V_32 = 0 ;
int V_33 ;
unsigned long V_34 ;
F_14 ( & V_2 -> V_35 , V_34 ) ;
if ( V_2 -> V_17 != ( ( V_2 -> V_17 & ~ V_27 ) | ( V_17 & V_27 ) ) ) {
T_1 V_36 = V_2 -> V_17 ;
if ( F_1 ( V_2 , ( V_2 -> V_17 & ~ V_27 ) |
( V_17 & V_27 ) ) ) {
F_15 ( & V_2 -> V_35 , V_34 ) ;
return - V_37 ;
}
V_2 -> V_17 &= ~ V_27 ;
V_2 -> V_17 |= V_17 & V_27 ;
F_16 ( & V_2 -> V_38 , V_36 , V_2 ) ;
V_30 = ( char * ) F_17 ( V_39 ) ;
if ( V_30 ) {
V_33 = F_7 ( & V_2 -> V_9 , NULL , V_30 ) ;
if ( V_33 > 0 ) {
if ( V_30 [ V_33 - 1 ] == '\n' )
V_30 [ V_33 - 1 ] = 0 ;
snprintf ( V_28 , sizeof( V_28 ) ,
L_6 , V_30 ) ;
V_31 [ V_32 ++ ] = V_28 ;
}
V_33 = F_3 ( & V_2 -> V_9 , NULL , V_30 ) ;
if ( V_33 > 0 ) {
if ( V_30 [ V_33 - 1 ] == '\n' )
V_30 [ V_33 - 1 ] = 0 ;
snprintf ( V_29 , sizeof( V_29 ) ,
L_7 , V_30 ) ;
V_31 [ V_32 ++ ] = V_29 ;
}
V_31 [ V_32 ] = NULL ;
F_15 ( & V_2 -> V_35 , V_34 ) ;
F_18 ( & V_2 -> V_9 . V_40 , V_41 , V_31 ) ;
F_19 ( ( unsigned long ) V_30 ) ;
} else {
F_15 ( & V_2 -> V_35 , V_34 ) ;
F_20 ( & V_2 -> V_9 , L_8 ) ;
F_21 ( & V_2 -> V_9 . V_40 , V_41 ) ;
}
} else {
F_15 ( & V_2 -> V_35 , V_34 ) ;
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_17 )
{
return F_13 ( V_2 , 0xffffffff , V_17 ) ;
}
int F_22 ( struct V_1 * V_2 , const char * V_42 )
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
int F_12 ( struct V_1 * V_2 , int V_44 )
{
if ( V_44 < 0 || ( V_2 -> V_16 && V_2 -> V_16 <= V_44 ) )
return - V_20 ;
return ! ! ( V_2 -> V_17 & ( 1 << V_44 ) ) ;
}
int F_23 ( struct V_1 * V_2 , const char * V_42 )
{
return F_12 ( V_2 , F_22
( V_2 , V_42 ) ) ;
}
int F_24 ( struct V_1 * V_2 ,
int V_44 , bool V_45 )
{
T_1 V_17 ;
if ( V_44 < 0 || ( V_2 -> V_16 && V_2 -> V_16 <= V_44 ) )
return - V_20 ;
V_17 = V_45 ? ( 1 << V_44 ) : 0 ;
return F_13 ( V_2 , 1 << V_44 , V_17 ) ;
}
int F_25 ( struct V_1 * V_2 ,
const char * V_42 , bool V_45 )
{
return F_24 ( V_2 , F_22
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
struct V_55 * V_56 = F_10 ( V_52 ,
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
if ( ! V_56 || ! V_42 || ! V_52 )
return - V_20 ;
if ( V_46 ) {
V_56 -> V_2 = F_26 ( V_46 ) ;
if ( ! V_56 -> V_2 )
return - V_62 ;
V_56 -> V_25 = F_22 ( V_56 -> V_2 ,
V_42 ) ;
if ( V_56 -> V_25 < 0 )
return V_56 -> V_25 ;
V_56 -> V_59 = V_52 ;
V_56 -> V_57 . V_60 = F_30 ;
return F_32 ( & V_56 -> V_2 -> V_38 ,
& V_56 -> V_57 ) ;
} else {
struct V_63 V_64 ;
struct V_1 * V_65 ;
struct V_8 * V_9 ;
if ( ! V_66 )
return - V_62 ;
F_33 ( & V_64 , V_66 , NULL , NULL ) ;
while ( ( V_9 = F_34 ( & V_64 ) ) ) {
V_65 = F_4 ( V_9 ) ;
if ( F_22 ( V_65 , V_42 ) < 0 )
continue;
F_35 ( & V_64 ) ;
return F_31 ( V_56 , V_65 -> V_49 ,
V_42 , V_52 ) ;
}
return - V_62 ;
}
}
int F_36 ( struct V_55 * V_56 )
{
if ( ! V_56 )
return - V_20 ;
return F_37 ( & V_56 -> V_2 -> V_38 , & V_56 -> V_57 ) ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
return F_32 ( & V_2 -> V_38 , V_52 ) ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
return F_37 ( & V_2 -> V_38 , V_52 ) ;
}
static int F_40 ( void )
{
if ( ! V_66 ) {
V_66 = F_41 ( V_67 , L_9 ) ;
if ( F_42 ( V_66 ) )
return F_43 ( V_66 ) ;
V_66 -> V_68 = V_69 ;
#if F_44 ( V_70 )
V_71 = F_45 ( L_10 ) ;
if ( F_46 ( ! V_71 , L_11 ) )
return - V_72 ;
#endif
}
return 0 ;
}
static void F_47 ( struct V_8 * V_9 )
{
}
static void F_48 ( struct V_8 * V_9 )
{
}
int F_49 ( struct V_1 * V_2 )
{
int V_15 , V_44 = 0 ;
if ( ! V_66 ) {
V_15 = F_40 () ;
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
F_20 ( & V_2 -> V_9 , L_12 ) ;
return - V_20 ;
}
V_2 -> V_9 . V_73 = V_66 ;
V_2 -> V_9 . V_74 = F_47 ;
V_2 -> V_49 = V_2 -> V_49 ? V_2 -> V_49 : F_8 ( V_2 -> V_9 . V_75 ) ;
if ( F_50 ( V_2 -> V_49 ) ) {
F_20 ( & V_2 -> V_9 ,
L_13 ) ;
return - V_20 ;
}
F_51 ( & V_2 -> V_9 , L_14 , V_2 -> V_49 ) ;
if ( V_2 -> V_16 ) {
char V_12 [ 10 ] ;
char * V_76 ;
struct V_22 * V_23 ;
V_2 -> V_77 = F_52 ( sizeof( struct V_22 ) *
V_2 -> V_16 , V_78 ) ;
if ( ! V_2 -> V_77 ) {
V_15 = - V_72 ;
goto V_79;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_16 ; V_44 ++ ) {
V_23 = & V_2 -> V_77 [ V_44 ] ;
snprintf ( V_12 , 10 , L_15 , V_44 ) ;
V_76 = F_52 ( sizeof( char ) * ( strlen ( V_12 ) + 1 ) ,
V_78 ) ;
if ( ! V_76 ) {
for ( V_44 -- ; V_44 >= 0 ; V_44 -- ) {
V_23 = & V_2 -> V_77 [ V_44 ] ;
F_53 ( V_23 -> V_80 . V_49 ) ;
}
V_15 = - V_72 ;
goto V_81;
}
strcpy ( V_76 , V_12 ) ;
V_23 -> V_2 = V_2 ;
V_23 -> V_25 = V_44 ;
V_23 -> V_82 [ 0 ] = & V_23 -> V_24 . V_11 ;
V_23 -> V_82 [ 1 ] = & V_23 -> V_26 . V_11 ;
V_23 -> V_82 [ 2 ] = NULL ;
V_23 -> V_80 . V_49 = V_76 ;
V_23 -> V_80 . V_82 = V_23 -> V_82 ;
F_54 ( & V_23 -> V_24 . V_11 ) ;
V_23 -> V_24 . V_11 . V_49 = L_16 ;
V_23 -> V_24 . V_11 . V_83 = 0444 ;
V_23 -> V_24 . V_84 = F_9 ;
F_54 ( & V_23 -> V_26 . V_11 ) ;
V_23 -> V_26 . V_11 . V_49 = L_17 ;
V_23 -> V_26 . V_11 . V_83 = 0444 ;
V_23 -> V_26 . V_84 = F_11 ;
}
}
if ( V_2 -> V_16 && V_2 -> V_5 ) {
char V_12 [ 80 ] ;
char * V_49 ;
for ( V_44 = 0 ; V_2 -> V_5 [ V_44 ] ; V_44 ++ )
;
V_2 -> V_85 = F_52 ( sizeof( struct V_86 * ) *
( V_44 + 1 ) , V_78 ) ;
if ( ! V_2 -> V_85 ) {
V_15 = - V_72 ;
goto V_87;
}
V_2 -> V_88 = F_52 ( sizeof( struct V_10 ) *
V_44 , V_78 ) ;
if ( ! V_2 -> V_88 ) {
V_15 = - V_72 ;
F_53 ( V_2 -> V_85 ) ;
goto V_87;
}
for ( V_44 = 0 ; V_2 -> V_5 [ V_44 ] ; V_44 ++ ) {
sprintf ( V_12 , L_3 , V_2 -> V_5 [ V_44 ] ) ;
V_49 = F_52 ( sizeof( char ) * ( strlen ( V_12 ) + 1 ) ,
V_78 ) ;
if ( ! V_49 ) {
for ( V_44 -- ; V_44 >= 0 ; V_44 -- ) {
F_53 ( V_2 -> V_88 [ V_44 ] . V_11 .
V_49 ) ;
}
F_53 ( V_2 -> V_88 ) ;
F_53 ( V_2 -> V_85 ) ;
V_15 = - V_72 ;
goto V_87;
}
strcpy ( V_49 , V_12 ) ;
F_54 ( & V_2 -> V_88 [ V_44 ] . V_11 ) ;
V_2 -> V_88 [ V_44 ] . V_11 . V_49 = V_49 ;
V_2 -> V_88 [ V_44 ] . V_11 . V_83 = 0000 ;
V_2 -> V_85 [ V_44 ] = & V_2 -> V_88 [ V_44 ]
. V_11 ;
}
V_2 -> V_89 . V_49 = V_90 ;
V_2 -> V_89 . V_82 = V_2 -> V_85 ;
}
if ( V_2 -> V_16 ) {
V_2 -> V_91 . V_92 =
F_52 ( sizeof( struct V_93 * ) *
( V_2 -> V_16 + 2 ) , V_78 ) ;
if ( ! V_2 -> V_91 . V_92 ) {
V_15 = - V_72 ;
goto V_94;
}
V_2 -> V_91 . V_49 = F_8 ( & V_2 -> V_9 ) ;
V_2 -> V_91 . V_74 = F_48 ;
for ( V_44 = 0 ; V_44 < V_2 -> V_16 ; V_44 ++ )
V_2 -> V_91 . V_92 [ V_44 ] =
& V_2 -> V_77 [ V_44 ] . V_80 ;
if ( V_2 -> V_5 )
V_2 -> V_91 . V_92 [ V_44 ] =
& V_2 -> V_89 ;
V_2 -> V_9 . type = & V_2 -> V_91 ;
}
V_15 = F_55 ( & V_2 -> V_9 ) ;
if ( V_15 ) {
F_56 ( & V_2 -> V_9 ) ;
goto V_95;
}
#if F_44 ( V_70 )
if ( V_71 )
V_15 = F_57 ( V_71 , & V_2 -> V_9 , NULL ) ;
#endif
F_58 ( & V_2 -> V_35 ) ;
F_59 ( & V_2 -> V_38 ) ;
F_60 ( & V_2 -> V_9 , V_2 ) ;
V_2 -> V_17 = 0 ;
F_27 ( & V_48 ) ;
F_61 ( & V_2 -> V_96 , & V_97 ) ;
F_29 ( & V_48 ) ;
return 0 ;
V_95:
if ( V_2 -> V_16 )
F_53 ( V_2 -> V_91 . V_92 ) ;
V_94:
if ( V_2 -> V_16 && V_2 -> V_5 ) {
for ( V_44 = 0 ; V_2 -> V_5 [ V_44 ] ; V_44 ++ )
F_53 ( V_2 -> V_88 [ V_44 ] . V_11 . V_49 ) ;
F_53 ( V_2 -> V_88 ) ;
F_53 ( V_2 -> V_85 ) ;
}
V_87:
for ( V_44 = 0 ; V_44 < V_2 -> V_16 ; V_44 ++ )
F_53 ( V_2 -> V_77 [ V_44 ] . V_80 . V_49 ) ;
V_81:
if ( V_2 -> V_16 )
F_53 ( V_2 -> V_77 ) ;
V_79:
return V_15 ;
}
void F_62 ( struct V_1 * V_2 )
{
int V_44 ;
F_27 ( & V_48 ) ;
F_63 ( & V_2 -> V_96 ) ;
F_29 ( & V_48 ) ;
if ( F_50 ( F_64 ( & V_2 -> V_9 ) ) ) {
F_20 ( & V_2 -> V_9 , L_18 ,
F_8 ( & V_2 -> V_9 ) ) ;
return;
}
F_65 ( & V_2 -> V_9 ) ;
if ( V_2 -> V_5 && V_2 -> V_16 ) {
for ( V_44 = 0 ; V_2 -> V_5 [ V_44 ] ;
V_44 ++ )
F_53 ( V_2 -> V_88 [ V_44 ] . V_11 . V_49 ) ;
F_53 ( V_2 -> V_88 ) ;
F_53 ( V_2 -> V_85 ) ;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_16 ; V_44 ++ )
F_53 ( V_2 -> V_77 [ V_44 ] . V_80 . V_49 ) ;
if ( V_2 -> V_16 ) {
F_53 ( V_2 -> V_91 . V_92 ) ;
F_53 ( V_2 -> V_77 ) ;
}
#if F_44 ( V_70 )
if ( V_71 )
F_66 ( V_71 , & V_2 -> V_9 , NULL ) ;
#endif
F_56 ( & V_2 -> V_9 ) ;
}
struct V_1 * F_67 ( struct V_8 * V_9 , int V_44 )
{
struct V_98 * V_99 ;
struct V_1 * V_2 ;
if ( ! V_9 -> V_100 ) {
F_20 ( V_9 , L_19 ) ;
return F_68 ( - V_20 ) ;
}
V_99 = F_69 ( V_9 -> V_100 , L_9 , V_44 ) ;
if ( ! V_99 ) {
F_20 ( V_9 , L_20 ,
V_9 -> V_100 -> V_101 ) ;
return F_68 ( - V_62 ) ;
}
V_2 = F_26 ( V_99 -> V_49 ) ;
if ( ! V_2 ) {
F_20 ( V_9 , L_21 , V_99 -> V_49 ) ;
return F_68 ( - V_62 ) ;
}
return V_2 ;
}
struct V_1 * F_67 ( struct V_8 * V_9 , int V_44 )
{
return F_68 ( - V_102 ) ;
}
static int T_4 F_70 ( void )
{
return F_40 () ;
}
static void T_5 F_71 ( void )
{
#if F_44 ( V_70 )
F_72 ( V_71 ) ;
#endif
F_73 ( V_66 ) ;
}
