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
static int F_3 ( struct V_1 * V_2 , const unsigned int V_8 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ ) {
if ( V_2 -> V_10 [ V_4 ] == V_8 )
return V_4 ;
}
return - V_11 ;
}
static int F_4 ( struct V_1 * V_2 , const char * V_12 )
{
unsigned int V_8 = - V_11 ;
int V_4 = 0 ;
while ( V_13 [ V_4 ] ) {
if ( ! strncmp ( V_13 [ V_4 ] , V_12 , V_14 ) ) {
V_8 = V_4 ;
break;
}
V_4 ++ ;
}
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , const char * V_12 )
{
unsigned int V_8 ;
if ( V_2 -> V_9 == 0 )
return - V_11 ;
V_8 = F_4 ( V_2 , V_12 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_3 ( V_2 , V_8 ) ;
}
static bool F_6 ( T_1 V_15 , T_1 V_16 , int V_17 , bool * V_18 )
{
if ( ( ( V_15 >> V_17 ) & 0x1 ) != ( ( V_16 >> V_17 ) & 0x1 ) ) {
* V_18 = V_16 ? true : false ;
return true ;
}
return false ;
}
static T_2 F_7 ( struct V_19 * V_20 , struct V_21 * V_22 ,
char * V_23 )
{
int V_4 , V_24 = 0 ;
struct V_1 * V_2 = F_8 ( V_20 ) ;
if ( V_2 -> V_25 ) {
int V_26 = V_2 -> V_25 ( V_2 , V_23 ) ;
if ( V_26 >= 0 )
return V_26 ;
}
if ( V_2 -> V_9 == 0 )
return sprintf ( V_23 , L_1 , V_2 -> V_27 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ ) {
V_24 += sprintf ( V_23 + V_24 , L_2 ,
V_13 [ V_2 -> V_10 [ V_4 ] ] ,
! ! ( V_2 -> V_27 & ( 1 << V_4 ) ) ) ;
}
return V_24 ;
}
static T_2 F_9 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_23 , T_3 V_24 )
{
T_1 V_27 ;
T_2 V_26 = 0 ;
struct V_1 * V_2 = F_8 ( V_20 ) ;
V_26 = sscanf ( V_23 , L_3 , & V_27 ) ;
if ( V_26 == 0 )
V_26 = - V_11 ;
else
V_26 = F_10 ( V_2 , V_27 ) ;
if ( V_26 < 0 )
return V_26 ;
return V_24 ;
}
static T_2 F_11 ( struct V_19 * V_20 , struct V_21 * V_22 ,
char * V_23 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
return sprintf ( V_23 , L_4 , V_2 -> V_12 ) ;
}
static T_2 F_12 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_28 * V_29 = F_13 ( V_22 , struct V_28 ,
V_30 ) ;
int V_4 = V_29 -> V_31 ;
return sprintf ( V_23 , L_4 ,
V_13 [ V_29 -> V_2 -> V_10 [ V_4 ] ] ) ;
}
static T_2 F_14 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_28 * V_29 = F_13 ( V_22 , struct V_28 ,
V_32 ) ;
int V_4 = V_29 -> V_31 ;
return sprintf ( V_23 , L_5 ,
F_15 ( V_29 -> V_2 ,
V_29 -> V_2 -> V_10 [ V_4 ] ) ) ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_33 , T_1 V_27 )
{
char V_34 [ 120 ] ;
char V_35 [ 120 ] ;
char * V_36 ;
char * V_37 [ 3 ] ;
int V_38 = 0 ;
int V_39 ;
int V_40 ;
unsigned long V_41 ;
bool V_18 ;
F_17 ( & V_2 -> V_42 , V_41 ) ;
if ( V_2 -> V_27 != ( ( V_2 -> V_27 & ~ V_33 ) | ( V_27 & V_33 ) ) ) {
T_1 V_43 ;
if ( F_1 ( V_2 , ( V_2 -> V_27 & ~ V_33 ) |
( V_27 & V_33 ) ) ) {
F_18 ( & V_2 -> V_42 , V_41 ) ;
return - V_44 ;
}
V_43 = V_2 -> V_27 ;
V_2 -> V_27 &= ~ V_33 ;
V_2 -> V_27 |= V_27 & V_33 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_9 ; V_40 ++ ) {
if ( F_6 ( V_43 , V_2 -> V_27 , V_40 ,
& V_18 ) )
F_19 ( & V_2 -> V_45 [ V_40 ] ,
V_18 , V_2 ) ;
}
V_36 = ( char * ) F_20 ( V_46 ) ;
if ( V_36 ) {
V_39 = F_11 ( & V_2 -> V_20 , NULL , V_36 ) ;
if ( V_39 > 0 ) {
if ( V_36 [ V_39 - 1 ] == '\n' )
V_36 [ V_39 - 1 ] = 0 ;
snprintf ( V_34 , sizeof( V_34 ) ,
L_6 , V_36 ) ;
V_37 [ V_38 ++ ] = V_34 ;
}
V_39 = F_7 ( & V_2 -> V_20 , NULL , V_36 ) ;
if ( V_39 > 0 ) {
if ( V_36 [ V_39 - 1 ] == '\n' )
V_36 [ V_39 - 1 ] = 0 ;
snprintf ( V_35 , sizeof( V_35 ) ,
L_7 , V_36 ) ;
V_37 [ V_38 ++ ] = V_35 ;
}
V_37 [ V_38 ] = NULL ;
F_18 ( & V_2 -> V_42 , V_41 ) ;
F_21 ( & V_2 -> V_20 . V_47 , V_48 , V_37 ) ;
F_22 ( ( unsigned long ) V_36 ) ;
} else {
F_18 ( & V_2 -> V_42 , V_41 ) ;
F_23 ( & V_2 -> V_20 , L_8 ) ;
F_24 ( & V_2 -> V_20 . V_47 , V_48 ) ;
}
} else {
F_18 ( & V_2 -> V_42 , V_41 ) ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_27 )
{
return F_16 ( V_2 , 0xffffffff , V_27 ) ;
}
int F_15 ( struct V_1 * V_2 , const unsigned int V_8 )
{
int V_40 ;
V_40 = F_3 ( V_2 , V_8 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_2 -> V_9 && V_2 -> V_9 <= V_40 )
return - V_11 ;
return ! ! ( V_2 -> V_27 & ( 1 << V_40 ) ) ;
}
int F_25 ( struct V_1 * V_2 , const char * V_49 )
{
unsigned int V_8 ;
V_8 = F_4 ( V_2 , V_49 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_15 ( V_2 , V_8 ) ;
}
int F_26 ( struct V_1 * V_2 , unsigned int V_8 ,
bool V_50 )
{
T_1 V_27 ;
int V_40 ;
V_40 = F_3 ( V_2 , V_8 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_2 -> V_9 && V_2 -> V_9 <= V_40 )
return - V_11 ;
V_27 = V_50 ? ( 1 << V_40 ) : 0 ;
return F_16 ( V_2 , 1 << V_40 , V_27 ) ;
}
int F_27 ( struct V_1 * V_2 ,
const char * V_49 , bool V_50 )
{
unsigned int V_8 ;
V_8 = F_4 ( V_2 , V_49 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_26 ( V_2 , V_8 , V_50 ) ;
}
struct V_1 * F_28 ( const char * V_13 )
{
struct V_1 * V_51 ;
F_29 ( & V_52 ) ;
F_30 (sd, &extcon_dev_list, entry) {
if ( ! strcmp ( V_51 -> V_12 , V_13 ) )
goto V_53;
}
V_51 = NULL ;
V_53:
F_31 ( & V_52 ) ;
return V_51 ;
}
int F_32 ( struct V_54 * V_55 ,
const char * V_13 , const char * V_49 ,
struct V_56 * V_57 )
{
unsigned long V_41 ;
int V_26 ;
if ( ! V_55 || ! V_49 || ! V_57 )
return - V_11 ;
if ( V_13 ) {
V_55 -> V_2 = F_28 ( V_13 ) ;
if ( ! V_55 -> V_2 )
return - V_58 ;
V_55 -> V_31 = F_5 ( V_55 -> V_2 ,
V_49 ) ;
if ( V_55 -> V_31 < 0 )
return V_55 -> V_31 ;
V_55 -> V_59 = V_57 ;
F_17 ( & V_55 -> V_2 -> V_42 , V_41 ) ;
V_26 = F_33 (
& V_55 -> V_2 -> V_45 [ V_55 -> V_31 ] ,
V_55 -> V_59 ) ;
F_18 ( & V_55 -> V_2 -> V_42 , V_41 ) ;
} else {
struct V_60 V_61 ;
struct V_1 * V_62 ;
struct V_19 * V_20 ;
if ( ! V_63 )
return - V_58 ;
F_34 ( & V_61 , V_63 , NULL , NULL ) ;
while ( ( V_20 = F_35 ( & V_61 ) ) ) {
V_62 = F_8 ( V_20 ) ;
if ( F_5 ( V_62 , V_49 ) < 0 )
continue;
F_36 ( & V_61 ) ;
return F_32 ( V_55 , V_62 -> V_12 ,
V_49 , V_57 ) ;
}
V_26 = - V_58 ;
}
return V_26 ;
}
int F_37 ( struct V_54 * V_55 )
{
unsigned long V_41 ;
int V_26 ;
if ( ! V_55 )
return - V_11 ;
F_17 ( & V_55 -> V_2 -> V_42 , V_41 ) ;
V_26 = F_38 (
& V_55 -> V_2 -> V_45 [ V_55 -> V_31 ] , V_55 -> V_59 ) ;
F_18 ( & V_55 -> V_2 -> V_42 , V_41 ) ;
return V_26 ;
}
int F_39 ( struct V_1 * V_2 , unsigned int V_8 ,
struct V_56 * V_57 )
{
unsigned long V_41 ;
int V_26 , V_17 ;
V_17 = F_3 ( V_2 , V_8 ) ;
F_17 ( & V_2 -> V_42 , V_41 ) ;
V_26 = F_33 ( & V_2 -> V_45 [ V_17 ] , V_57 ) ;
F_18 ( & V_2 -> V_42 , V_41 ) ;
return V_26 ;
}
int F_40 ( struct V_1 * V_2 , unsigned int V_8 ,
struct V_56 * V_57 )
{
unsigned long V_41 ;
int V_26 , V_17 ;
V_17 = F_3 ( V_2 , V_8 ) ;
F_17 ( & V_2 -> V_42 , V_41 ) ;
V_26 = F_38 ( & V_2 -> V_45 [ V_17 ] , V_57 ) ;
F_18 ( & V_2 -> V_42 , V_41 ) ;
return V_26 ;
}
static int F_41 ( void )
{
if ( ! V_63 ) {
V_63 = F_42 ( V_64 , L_9 ) ;
if ( F_43 ( V_63 ) )
return F_44 ( V_63 ) ;
V_63 -> V_65 = V_66 ;
#if F_45 ( V_67 )
V_68 = F_46 ( L_10 ) ;
if ( F_47 ( ! V_68 , L_11 ) )
return - V_69 ;
#endif
}
return 0 ;
}
static void F_48 ( struct V_19 * V_20 )
{
}
static void F_49 ( struct V_19 * V_20 )
{
}
struct V_1 * F_50 ( const unsigned int * V_10 )
{
struct V_1 * V_2 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return F_52 ( - V_69 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = V_10 ;
return V_2 ;
}
void F_53 ( struct V_1 * V_2 )
{
F_54 ( V_2 ) ;
}
static int F_55 ( struct V_19 * V_20 , void * V_71 , void * V_72 )
{
struct V_1 * * V_73 = V_71 ;
if ( F_56 ( ! V_73 || ! * V_73 ) )
return 0 ;
return * V_73 == V_72 ;
}
static void F_57 ( struct V_19 * V_20 , void * V_71 )
{
F_53 ( * (struct V_1 * * ) V_71 ) ;
}
struct V_1 * F_58 ( struct V_19 * V_20 ,
const unsigned int * V_10 )
{
struct V_1 * * V_74 , * V_2 ;
V_74 = F_59 ( F_57 , sizeof( * V_74 ) , V_70 ) ;
if ( ! V_74 )
return F_52 ( - V_69 ) ;
V_2 = F_50 ( V_10 ) ;
if ( F_43 ( V_2 ) ) {
F_60 ( V_74 ) ;
return V_2 ;
}
V_2 -> V_20 . V_75 = V_20 ;
* V_74 = V_2 ;
F_61 ( V_20 , V_74 ) ;
return V_2 ;
}
void F_62 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
F_56 ( F_63 ( V_20 , F_57 ,
F_55 , V_2 ) ) ;
}
int F_64 ( struct V_1 * V_2 )
{
int V_26 , V_40 = 0 ;
static T_4 V_76 = F_65 ( - 1 ) ;
if ( ! V_63 ) {
V_26 = F_41 () ;
if ( V_26 < 0 )
return V_26 ;
}
if ( ! V_2 -> V_10 )
return - V_11 ;
for (; V_2 -> V_10 [ V_40 ] != V_77 ; V_40 ++ ) ;
V_2 -> V_9 = V_40 ;
if ( V_40 > V_78 ) {
F_23 ( & V_2 -> V_20 ,
L_12 ) ;
return - V_11 ;
}
V_2 -> V_20 . V_79 = V_63 ;
V_2 -> V_20 . V_80 = F_48 ;
V_2 -> V_12 = F_66 ( V_2 -> V_20 . V_75 ) ;
if ( F_67 ( V_2 -> V_12 ) ) {
F_23 ( & V_2 -> V_20 ,
L_13 ) ;
return - V_11 ;
}
F_68 ( & V_2 -> V_20 , L_14 ,
( unsigned long ) F_69 ( & V_76 ) ) ;
if ( V_2 -> V_9 ) {
char V_23 [ 10 ] ;
char * V_81 ;
struct V_28 * V_29 ;
V_2 -> V_82 = F_51 ( sizeof( struct V_28 ) *
V_2 -> V_9 , V_70 ) ;
if ( ! V_2 -> V_82 ) {
V_26 = - V_69 ;
goto V_83;
}
for ( V_40 = 0 ; V_40 < V_2 -> V_9 ; V_40 ++ ) {
V_29 = & V_2 -> V_82 [ V_40 ] ;
snprintf ( V_23 , 10 , L_15 , V_40 ) ;
V_81 = F_51 ( sizeof( char ) * ( strlen ( V_23 ) + 1 ) ,
V_70 ) ;
if ( ! V_81 ) {
for ( V_40 -- ; V_40 >= 0 ; V_40 -- ) {
V_29 = & V_2 -> V_82 [ V_40 ] ;
F_54 ( V_29 -> V_84 . V_12 ) ;
}
V_26 = - V_69 ;
goto V_85;
}
strcpy ( V_81 , V_23 ) ;
V_29 -> V_2 = V_2 ;
V_29 -> V_31 = V_40 ;
V_29 -> V_86 [ 0 ] = & V_29 -> V_30 . V_22 ;
V_29 -> V_86 [ 1 ] = & V_29 -> V_32 . V_22 ;
V_29 -> V_86 [ 2 ] = NULL ;
V_29 -> V_84 . V_12 = V_81 ;
V_29 -> V_84 . V_86 = V_29 -> V_86 ;
F_70 ( & V_29 -> V_30 . V_22 ) ;
V_29 -> V_30 . V_22 . V_12 = L_16 ;
V_29 -> V_30 . V_22 . V_87 = 0444 ;
V_29 -> V_30 . V_88 = F_12 ;
F_70 ( & V_29 -> V_32 . V_22 ) ;
V_29 -> V_32 . V_22 . V_12 = L_17 ;
V_29 -> V_32 . V_22 . V_87 = 0444 ;
V_29 -> V_32 . V_88 = F_14 ;
}
}
if ( V_2 -> V_9 && V_2 -> V_5 ) {
char V_23 [ 80 ] ;
char * V_12 ;
for ( V_40 = 0 ; V_2 -> V_5 [ V_40 ] ; V_40 ++ )
;
V_2 -> V_89 = F_51 ( sizeof( struct V_90 * ) *
( V_40 + 1 ) , V_70 ) ;
if ( ! V_2 -> V_89 ) {
V_26 = - V_69 ;
goto V_91;
}
V_2 -> V_92 = F_51 ( sizeof( struct V_21 ) *
V_40 , V_70 ) ;
if ( ! V_2 -> V_92 ) {
V_26 = - V_69 ;
F_54 ( V_2 -> V_89 ) ;
goto V_91;
}
for ( V_40 = 0 ; V_2 -> V_5 [ V_40 ] ; V_40 ++ ) {
sprintf ( V_23 , L_3 , V_2 -> V_5 [ V_40 ] ) ;
V_12 = F_51 ( sizeof( char ) * ( strlen ( V_23 ) + 1 ) ,
V_70 ) ;
if ( ! V_12 ) {
for ( V_40 -- ; V_40 >= 0 ; V_40 -- ) {
F_54 ( V_2 -> V_92 [ V_40 ] . V_22 .
V_12 ) ;
}
F_54 ( V_2 -> V_92 ) ;
F_54 ( V_2 -> V_89 ) ;
V_26 = - V_69 ;
goto V_91;
}
strcpy ( V_12 , V_23 ) ;
F_70 ( & V_2 -> V_92 [ V_40 ] . V_22 ) ;
V_2 -> V_92 [ V_40 ] . V_22 . V_12 = V_12 ;
V_2 -> V_92 [ V_40 ] . V_22 . V_87 = 0000 ;
V_2 -> V_89 [ V_40 ] = & V_2 -> V_92 [ V_40 ]
. V_22 ;
}
V_2 -> V_93 . V_12 = V_94 ;
V_2 -> V_93 . V_86 = V_2 -> V_89 ;
}
if ( V_2 -> V_9 ) {
V_2 -> V_95 . V_96 =
F_51 ( sizeof( struct V_97 * ) *
( V_2 -> V_9 + 2 ) , V_70 ) ;
if ( ! V_2 -> V_95 . V_96 ) {
V_26 = - V_69 ;
goto V_98;
}
V_2 -> V_95 . V_12 = F_66 ( & V_2 -> V_20 ) ;
V_2 -> V_95 . V_80 = F_49 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_9 ; V_40 ++ )
V_2 -> V_95 . V_96 [ V_40 ] =
& V_2 -> V_82 [ V_40 ] . V_84 ;
if ( V_2 -> V_5 )
V_2 -> V_95 . V_96 [ V_40 ] =
& V_2 -> V_93 ;
V_2 -> V_20 . type = & V_2 -> V_95 ;
}
V_26 = F_71 ( & V_2 -> V_20 ) ;
if ( V_26 ) {
F_72 ( & V_2 -> V_20 ) ;
goto V_99;
}
#if F_45 ( V_67 )
if ( V_68 )
V_26 = F_73 ( V_68 , & V_2 -> V_20 , NULL ) ;
#endif
F_74 ( & V_2 -> V_42 ) ;
V_2 -> V_45 = F_75 ( & V_2 -> V_20 ,
sizeof( * V_2 -> V_45 ) * V_2 -> V_9 , V_70 ) ;
if ( ! V_2 -> V_45 ) {
V_26 = - V_69 ;
goto V_99;
}
for ( V_40 = 0 ; V_40 < V_2 -> V_9 ; V_40 ++ )
F_76 ( & V_2 -> V_45 [ V_40 ] ) ;
F_77 ( & V_2 -> V_20 , V_2 ) ;
V_2 -> V_27 = 0 ;
F_29 ( & V_52 ) ;
F_78 ( & V_2 -> V_100 , & V_101 ) ;
F_31 ( & V_52 ) ;
return 0 ;
V_99:
if ( V_2 -> V_9 )
F_54 ( V_2 -> V_95 . V_96 ) ;
V_98:
if ( V_2 -> V_9 && V_2 -> V_5 ) {
for ( V_40 = 0 ; V_2 -> V_5 [ V_40 ] ; V_40 ++ )
F_54 ( V_2 -> V_92 [ V_40 ] . V_22 . V_12 ) ;
F_54 ( V_2 -> V_92 ) ;
F_54 ( V_2 -> V_89 ) ;
}
V_91:
for ( V_40 = 0 ; V_40 < V_2 -> V_9 ; V_40 ++ )
F_54 ( V_2 -> V_82 [ V_40 ] . V_84 . V_12 ) ;
V_85:
if ( V_2 -> V_9 )
F_54 ( V_2 -> V_82 ) ;
V_83:
return V_26 ;
}
void F_79 ( struct V_1 * V_2 )
{
int V_40 ;
F_29 ( & V_52 ) ;
F_80 ( & V_2 -> V_100 ) ;
F_31 ( & V_52 ) ;
if ( F_67 ( F_81 ( & V_2 -> V_20 ) ) ) {
F_23 ( & V_2 -> V_20 , L_18 ,
F_66 ( & V_2 -> V_20 ) ) ;
return;
}
F_82 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_5 && V_2 -> V_9 ) {
for ( V_40 = 0 ; V_2 -> V_5 [ V_40 ] ;
V_40 ++ )
F_54 ( V_2 -> V_92 [ V_40 ] . V_22 . V_12 ) ;
F_54 ( V_2 -> V_92 ) ;
F_54 ( V_2 -> V_89 ) ;
}
for ( V_40 = 0 ; V_40 < V_2 -> V_9 ; V_40 ++ )
F_54 ( V_2 -> V_82 [ V_40 ] . V_84 . V_12 ) ;
if ( V_2 -> V_9 ) {
F_54 ( V_2 -> V_95 . V_96 ) ;
F_54 ( V_2 -> V_82 ) ;
}
#if F_45 ( V_67 )
if ( V_68 )
F_83 ( V_68 , & V_2 -> V_20 , NULL ) ;
#endif
F_72 ( & V_2 -> V_20 ) ;
}
static void F_84 ( struct V_19 * V_20 , void * V_71 )
{
F_79 ( * (struct V_1 * * ) V_71 ) ;
}
int F_85 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_1 * * V_74 ;
int V_26 ;
V_74 = F_59 ( F_84 , sizeof( * V_74 ) , V_70 ) ;
if ( ! V_74 )
return - V_69 ;
V_26 = F_64 ( V_2 ) ;
if ( V_26 ) {
F_60 ( V_74 ) ;
return V_26 ;
}
* V_74 = V_2 ;
F_61 ( V_20 , V_74 ) ;
return 0 ;
}
void F_86 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
F_56 ( F_63 ( V_20 , F_84 ,
F_55 , V_2 ) ) ;
}
struct V_1 * F_87 ( struct V_19 * V_20 , int V_40 )
{
struct V_102 * V_103 ;
struct V_1 * V_2 ;
if ( ! V_20 -> V_104 ) {
F_23 ( V_20 , L_19 ) ;
return F_52 ( - V_11 ) ;
}
V_103 = F_88 ( V_20 -> V_104 , L_9 , V_40 ) ;
if ( ! V_103 ) {
F_23 ( V_20 , L_20 ,
V_20 -> V_104 -> V_105 ) ;
return F_52 ( - V_58 ) ;
}
F_29 ( & V_52 ) ;
F_30 (edev, &extcon_dev_list, entry) {
if ( V_2 -> V_20 . V_75 && V_2 -> V_20 . V_75 -> V_104 == V_103 ) {
F_31 ( & V_52 ) ;
return V_2 ;
}
}
F_31 ( & V_52 ) ;
return F_52 ( - V_106 ) ;
}
struct V_1 * F_87 ( struct V_19 * V_20 , int V_40 )
{
return F_52 ( - V_107 ) ;
}
const char * F_89 ( struct V_1 * V_2 )
{
return ! V_2 ? NULL : V_2 -> V_12 ;
}
static int T_5 F_90 ( void )
{
return F_41 () ;
}
static void T_6 F_91 ( void )
{
#if F_45 ( V_67 )
F_92 ( V_68 ) ;
#endif
F_93 ( V_63 ) ;
}
