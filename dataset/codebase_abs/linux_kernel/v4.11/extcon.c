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
static int F_4 ( unsigned int V_12 )
{
switch ( V_12 ) {
case V_13 ... V_14 :
return V_15 ;
case V_16 ... V_17 :
return V_18 ;
case V_19 ... V_20 :
return V_21 ;
case V_22 ... V_23 :
return V_24 ;
default:
return - V_11 ;
}
}
static bool F_5 ( struct V_1 * V_2 , unsigned int V_25 )
{
return ! ! ( V_2 -> V_26 & F_6 ( V_25 ) ) ;
}
static bool F_7 ( struct V_1 * V_2 , int V_25 ,
bool V_3 )
{
int V_26 = ! ! ( V_2 -> V_26 & F_6 ( V_25 ) ) ;
return ( V_26 != V_3 ) ;
}
static bool F_8 ( unsigned int V_8 , unsigned int V_12 )
{
int type ;
type = F_4 ( V_12 ) ;
if ( type < 0 )
return false ;
return ! ! ( V_27 [ V_8 ] . type & type ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_8 , int V_25 , unsigned int V_12 )
{
struct V_28 * V_29 ;
int type , V_30 ;
type = F_4 ( V_12 ) ;
if ( type < 0 )
return type ;
V_29 = & V_2 -> V_31 [ V_25 ] ;
switch ( type ) {
case V_15 :
V_30 = F_10 ( V_12 - V_13 , V_29 -> V_32 ) ;
break;
case V_18 :
V_30 = F_10 ( V_12 - V_16 , V_29 -> V_33 ) ;
break;
case V_21 :
V_30 = F_10 ( V_12 - V_19 , V_29 -> V_34 ) ;
break;
case V_24 :
V_30 = F_10 ( V_12 - V_22 , V_29 -> V_35 ) ;
break;
default:
V_30 = - V_11 ;
}
return V_30 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_8 , int V_25 )
{
unsigned int type = V_27 [ V_8 ] . type ;
struct V_28 * V_29 = & V_2 -> V_31 [ V_25 ] ;
if ( V_15 & type )
memset ( V_29 -> V_36 , 0 , sizeof( V_29 -> V_36 ) ) ;
if ( V_18 & type )
memset ( V_29 -> V_37 , 0 , sizeof( V_29 -> V_37 ) ) ;
if ( V_21 & type )
memset ( V_29 -> V_38 , 0 , sizeof( V_29 -> V_38 ) ) ;
if ( V_24 & type )
memset ( V_29 -> V_39 , 0 , sizeof( V_29 -> V_39 ) ) ;
}
static T_2 F_12 ( struct V_40 * V_41 , struct V_42 * V_43 ,
char * V_44 )
{
int V_4 , V_45 = 0 ;
struct V_1 * V_2 = F_13 ( V_41 ) ;
if ( V_2 -> V_9 == 0 )
return sprintf ( V_44 , L_1 , V_2 -> V_26 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ ) {
V_45 += sprintf ( V_44 + V_45 , L_2 ,
V_27 [ V_2 -> V_10 [ V_4 ] ] . V_46 ,
! ! ( V_2 -> V_26 & ( 1 << V_4 ) ) ) ;
}
return V_45 ;
}
static T_2 F_14 ( struct V_40 * V_41 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_2 = F_13 ( V_41 ) ;
return sprintf ( V_44 , L_3 , V_2 -> V_46 ) ;
}
static T_2 F_15 ( struct V_40 * V_41 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_28 * V_29 = F_16 ( V_43 , struct V_28 ,
V_47 ) ;
int V_4 = V_29 -> V_48 ;
return sprintf ( V_44 , L_3 ,
V_27 [ V_29 -> V_2 -> V_10 [ V_4 ] ] . V_46 ) ;
}
static T_2 F_17 ( struct V_40 * V_41 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_28 * V_29 = F_16 ( V_43 , struct V_28 ,
V_49 ) ;
int V_4 = V_29 -> V_48 ;
return sprintf ( V_44 , L_4 ,
F_18 ( V_29 -> V_2 , V_29 -> V_2 -> V_10 [ V_4 ] ) ) ;
}
int F_19 ( struct V_1 * V_2 , unsigned int V_8 )
{
char V_50 [ 120 ] ;
char V_51 [ 120 ] ;
char * V_52 ;
char * V_53 [ 3 ] ;
int V_54 = 0 ;
int V_55 ;
int V_25 ;
int V_26 ;
unsigned long V_56 ;
if ( ! V_2 )
return - V_11 ;
V_25 = F_3 ( V_2 , V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
V_26 = ! ! ( V_2 -> V_26 & F_6 ( V_25 ) ) ;
F_21 ( & V_2 -> V_58 [ V_25 ] , V_26 , V_2 ) ;
V_52 = ( char * ) F_22 ( V_59 ) ;
if ( ! V_52 ) {
F_23 ( & V_2 -> V_57 , V_56 ) ;
F_24 ( & V_2 -> V_41 , L_5 ) ;
F_25 ( & V_2 -> V_41 . V_60 , V_61 ) ;
return - V_62 ;
}
V_55 = F_14 ( & V_2 -> V_41 , NULL , V_52 ) ;
if ( V_55 > 0 ) {
if ( V_52 [ V_55 - 1 ] == '\n' )
V_52 [ V_55 - 1 ] = 0 ;
snprintf ( V_50 , sizeof( V_50 ) , L_6 , V_52 ) ;
V_53 [ V_54 ++ ] = V_50 ;
}
V_55 = F_12 ( & V_2 -> V_41 , NULL , V_52 ) ;
if ( V_55 > 0 ) {
if ( V_52 [ V_55 - 1 ] == '\n' )
V_52 [ V_55 - 1 ] = 0 ;
snprintf ( V_51 , sizeof( V_51 ) , L_7 , V_52 ) ;
V_53 [ V_54 ++ ] = V_51 ;
}
V_53 [ V_54 ] = NULL ;
F_23 ( & V_2 -> V_57 , V_56 ) ;
F_26 ( & V_2 -> V_41 . V_60 , V_61 , V_53 ) ;
F_27 ( ( unsigned long ) V_52 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , const unsigned int V_8 )
{
int V_25 , V_26 ;
unsigned long V_56 ;
if ( ! V_2 )
return - V_11 ;
V_25 = F_3 ( V_2 , V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
V_26 = F_5 ( V_2 , V_25 ) ;
F_23 ( & V_2 -> V_57 , V_56 ) ;
return V_26 ;
}
int F_28 ( struct V_1 * V_2 , unsigned int V_8 ,
bool V_63 )
{
unsigned long V_56 ;
int V_25 , V_30 = 0 ;
if ( ! V_2 )
return - V_11 ;
V_25 = F_3 ( V_2 , V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
if ( ! F_7 ( V_2 , V_25 , V_63 ) )
goto V_64;
if ( F_1 ( V_2 ,
( V_2 -> V_26 & ~ F_6 ( V_25 ) ) | ( V_63 & F_6 ( V_25 ) ) ) ) {
V_30 = - V_65 ;
goto V_64;
}
if ( ! V_63 )
F_11 ( V_2 , V_8 , V_25 ) ;
if ( V_63 )
V_2 -> V_26 |= F_6 ( V_25 ) ;
else
V_2 -> V_26 &= ~ ( F_6 ( V_25 ) ) ;
V_64:
F_23 ( & V_2 -> V_57 , V_56 ) ;
return V_30 ;
}
int F_29 ( struct V_1 * V_2 , unsigned int V_8 ,
bool V_63 )
{
int V_30 , V_25 ;
unsigned long V_56 ;
V_25 = F_3 ( V_2 , V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
V_30 = F_7 ( V_2 , V_25 , V_63 ) ;
F_23 ( & V_2 -> V_57 , V_56 ) ;
if ( ! V_30 )
return 0 ;
V_30 = F_28 ( V_2 , V_8 , V_63 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_19 ( V_2 , V_8 ) ;
}
int F_30 ( struct V_1 * V_2 , unsigned int V_8 ,
unsigned int V_12 ,
union V_66 * V_67 )
{
struct V_28 * V_29 ;
unsigned long V_56 ;
int V_25 , V_30 = 0 ;
* V_67 = (union V_66 ) ( 0 ) ;
if ( ! V_2 )
return - V_11 ;
if ( ! F_8 ( V_8 , V_12 ) )
return - V_11 ;
V_25 = F_3 ( V_2 , V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
if ( ! F_9 ( V_2 , V_8 , V_25 , V_12 ) ) {
F_23 ( & V_2 -> V_57 , V_56 ) ;
return - V_65 ;
}
if ( ! F_5 ( V_2 , V_25 ) ) {
F_23 ( & V_2 -> V_57 , V_56 ) ;
return 0 ;
}
V_29 = & V_2 -> V_31 [ V_25 ] ;
switch ( V_12 ) {
case V_13 ... V_14 :
* V_67 = V_29 -> V_36 [ V_12 - V_13 ] ;
break;
case V_16 ... V_17 :
* V_67 = V_29 -> V_37 [ V_12 - V_16 ] ;
break;
case V_19 ... V_20 :
* V_67 = V_29 -> V_38 [ V_12 - V_19 ] ;
break;
case V_22 ... V_23 :
* V_67 = V_29 -> V_39 [ V_12 - V_22 ] ;
break;
default:
V_30 = - V_11 ;
break;
}
F_23 ( & V_2 -> V_57 , V_56 ) ;
return V_30 ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_8 ,
unsigned int V_12 ,
union V_66 V_67 )
{
struct V_28 * V_29 ;
unsigned long V_56 ;
int V_25 , V_30 = 0 ;
if ( ! V_2 )
return - V_11 ;
if ( ! F_8 ( V_8 , V_12 ) )
return - V_11 ;
V_25 = F_3 ( V_2 , V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
if ( ! F_9 ( V_2 , V_8 , V_25 , V_12 ) ) {
F_23 ( & V_2 -> V_57 , V_56 ) ;
return - V_65 ;
}
V_29 = & V_2 -> V_31 [ V_25 ] ;
switch ( V_12 ) {
case V_13 ... V_14 :
V_29 -> V_36 [ V_12 - V_13 ] = V_67 ;
break;
case V_16 ... V_17 :
V_29 -> V_37 [ V_12 - V_16 ] = V_67 ;
break;
case V_19 ... V_20 :
V_29 -> V_38 [ V_12 - V_19 ] = V_67 ;
break;
case V_22 ... V_23 :
V_29 -> V_39 [ V_12 - V_22 ] = V_67 ;
break;
default:
V_30 = - V_11 ;
break;
}
F_23 ( & V_2 -> V_57 , V_56 ) ;
return V_30 ;
}
int F_32 ( struct V_1 * V_2 , unsigned int V_8 ,
unsigned int V_12 ,
union V_66 V_67 )
{
int V_30 ;
V_30 = F_31 ( V_2 , V_8 , V_12 , V_67 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_19 ( V_2 , V_8 ) ;
}
int F_33 ( struct V_1 * V_2 , unsigned int V_8 ,
unsigned int V_12 )
{
int V_25 ;
if ( ! V_2 )
return - V_11 ;
if ( ! F_8 ( V_8 , V_12 ) )
return - V_11 ;
V_25 = F_3 ( V_2 , V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
return F_9 ( V_2 , V_8 , V_25 , V_12 ) ;
}
int F_34 ( struct V_1 * V_2 , unsigned int V_8 ,
unsigned int V_12 )
{
struct V_28 * V_29 ;
int V_25 , type , V_30 = 0 ;
if ( ! V_2 )
return - V_11 ;
if ( ! F_8 ( V_8 , V_12 ) )
return - V_11 ;
V_25 = F_3 ( V_2 , V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
type = F_4 ( V_12 ) ;
if ( type < 0 )
return type ;
V_29 = & V_2 -> V_31 [ V_25 ] ;
switch ( type ) {
case V_15 :
F_35 ( V_12 - V_13 , V_29 -> V_32 ) ;
break;
case V_18 :
F_35 ( V_12 - V_16 , V_29 -> V_33 ) ;
break;
case V_21 :
F_35 ( V_12 - V_19 , V_29 -> V_34 ) ;
break;
case V_24 :
F_35 ( V_12 - V_22 , V_29 -> V_35 ) ;
break;
default:
V_30 = - V_11 ;
}
return V_30 ;
}
struct V_1 * F_36 ( const char * V_68 )
{
struct V_1 * V_69 ;
if ( ! V_68 )
return F_37 ( - V_11 ) ;
F_38 ( & V_70 ) ;
F_39 (sd, &extcon_dev_list, entry) {
if ( ! strcmp ( V_69 -> V_46 , V_68 ) )
goto V_64;
}
V_69 = NULL ;
V_64:
F_40 ( & V_70 ) ;
return V_69 ;
}
int F_41 ( struct V_1 * V_2 , unsigned int V_8 ,
struct V_71 * V_72 )
{
unsigned long V_56 ;
int V_30 , V_73 = - V_11 ;
if ( ! V_2 || ! V_72 )
return - V_11 ;
V_73 = F_3 ( V_2 , V_8 ) ;
if ( V_73 < 0 )
return V_73 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
V_30 = F_42 ( & V_2 -> V_58 [ V_73 ] , V_72 ) ;
F_23 ( & V_2 -> V_57 , V_56 ) ;
return V_30 ;
}
int F_43 ( struct V_1 * V_2 , unsigned int V_8 ,
struct V_71 * V_72 )
{
unsigned long V_56 ;
int V_30 , V_73 ;
if ( ! V_2 || ! V_72 )
return - V_11 ;
V_73 = F_3 ( V_2 , V_8 ) ;
if ( V_73 < 0 )
return V_73 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
V_30 = F_44 ( & V_2 -> V_58 [ V_73 ] , V_72 ) ;
F_23 ( & V_2 -> V_57 , V_56 ) ;
return V_30 ;
}
static int F_45 ( void )
{
if ( ! V_74 ) {
V_74 = F_46 ( V_75 , L_8 ) ;
if ( F_47 ( V_74 ) )
return F_48 ( V_74 ) ;
V_74 -> V_76 = V_77 ;
#if F_49 ( V_78 )
V_79 = F_50 ( L_9 ) ;
if ( F_51 ( ! V_79 , L_10 ) )
return - V_62 ;
#endif
}
return 0 ;
}
static void F_52 ( struct V_40 * V_41 )
{
}
static void F_53 ( struct V_40 * V_41 )
{
}
struct V_1 * F_54 ( const unsigned int * V_10 )
{
struct V_1 * V_2 ;
if ( ! V_10 )
return F_37 ( - V_11 ) ;
V_2 = F_55 ( sizeof( * V_2 ) , V_80 ) ;
if ( ! V_2 )
return F_37 ( - V_62 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = V_10 ;
return V_2 ;
}
void F_56 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
}
int F_58 ( struct V_1 * V_2 )
{
int V_30 , V_25 = 0 ;
static T_3 V_81 = F_59 ( - 1 ) ;
if ( ! V_74 ) {
V_30 = F_45 () ;
if ( V_30 < 0 )
return V_30 ;
}
if ( ! V_2 || ! V_2 -> V_10 )
return - V_11 ;
for (; V_2 -> V_10 [ V_25 ] != V_82 ; V_25 ++ ) ;
V_2 -> V_9 = V_25 ;
if ( V_25 > V_83 ) {
F_24 ( & V_2 -> V_41 ,
L_11 ) ;
return - V_11 ;
}
V_2 -> V_41 . V_84 = V_74 ;
V_2 -> V_41 . V_85 = F_52 ;
V_2 -> V_46 = F_60 ( V_2 -> V_41 . V_86 ) ;
if ( F_61 ( V_2 -> V_46 ) ) {
F_24 ( & V_2 -> V_41 ,
L_12 ) ;
return - V_11 ;
}
F_62 ( & V_2 -> V_41 , L_13 ,
( unsigned long ) F_63 ( & V_81 ) ) ;
if ( V_2 -> V_9 ) {
char V_44 [ 10 ] ;
char * V_87 ;
struct V_28 * V_29 ;
V_2 -> V_31 = F_55 ( sizeof( struct V_28 ) *
V_2 -> V_9 , V_80 ) ;
if ( ! V_2 -> V_31 ) {
V_30 = - V_62 ;
goto V_88;
}
for ( V_25 = 0 ; V_25 < V_2 -> V_9 ; V_25 ++ ) {
V_29 = & V_2 -> V_31 [ V_25 ] ;
snprintf ( V_44 , 10 , L_14 , V_25 ) ;
V_87 = F_55 ( sizeof( char ) * ( strlen ( V_44 ) + 1 ) ,
V_80 ) ;
if ( ! V_87 ) {
for ( V_25 -- ; V_25 >= 0 ; V_25 -- ) {
V_29 = & V_2 -> V_31 [ V_25 ] ;
F_57 ( V_29 -> V_89 . V_46 ) ;
}
V_30 = - V_62 ;
goto V_90;
}
strcpy ( V_87 , V_44 ) ;
V_29 -> V_2 = V_2 ;
V_29 -> V_48 = V_25 ;
V_29 -> V_91 [ 0 ] = & V_29 -> V_47 . V_43 ;
V_29 -> V_91 [ 1 ] = & V_29 -> V_49 . V_43 ;
V_29 -> V_91 [ 2 ] = NULL ;
V_29 -> V_89 . V_46 = V_87 ;
V_29 -> V_89 . V_91 = V_29 -> V_91 ;
F_64 ( & V_29 -> V_47 . V_43 ) ;
V_29 -> V_47 . V_43 . V_46 = L_15 ;
V_29 -> V_47 . V_43 . V_92 = 0444 ;
V_29 -> V_47 . V_93 = F_15 ;
F_64 ( & V_29 -> V_49 . V_43 ) ;
V_29 -> V_49 . V_43 . V_46 = L_16 ;
V_29 -> V_49 . V_43 . V_92 = 0444 ;
V_29 -> V_49 . V_93 = F_17 ;
}
}
if ( V_2 -> V_9 && V_2 -> V_5 ) {
char V_44 [ 80 ] ;
char * V_46 ;
for ( V_25 = 0 ; V_2 -> V_5 [ V_25 ] ; V_25 ++ )
;
V_2 -> V_94 = F_55 ( sizeof( struct V_95 * ) *
( V_25 + 1 ) , V_80 ) ;
if ( ! V_2 -> V_94 ) {
V_30 = - V_62 ;
goto V_96;
}
V_2 -> V_97 = F_55 ( sizeof( struct V_42 ) *
V_25 , V_80 ) ;
if ( ! V_2 -> V_97 ) {
V_30 = - V_62 ;
F_57 ( V_2 -> V_94 ) ;
goto V_96;
}
for ( V_25 = 0 ; V_2 -> V_5 [ V_25 ] ; V_25 ++ ) {
sprintf ( V_44 , L_17 , V_2 -> V_5 [ V_25 ] ) ;
V_46 = F_55 ( sizeof( char ) * ( strlen ( V_44 ) + 1 ) ,
V_80 ) ;
if ( ! V_46 ) {
for ( V_25 -- ; V_25 >= 0 ; V_25 -- ) {
F_57 ( V_2 -> V_97 [ V_25 ] . V_43 .
V_46 ) ;
}
F_57 ( V_2 -> V_97 ) ;
F_57 ( V_2 -> V_94 ) ;
V_30 = - V_62 ;
goto V_96;
}
strcpy ( V_46 , V_44 ) ;
F_64 ( & V_2 -> V_97 [ V_25 ] . V_43 ) ;
V_2 -> V_97 [ V_25 ] . V_43 . V_46 = V_46 ;
V_2 -> V_97 [ V_25 ] . V_43 . V_92 = 0000 ;
V_2 -> V_94 [ V_25 ] = & V_2 -> V_97 [ V_25 ]
. V_43 ;
}
V_2 -> V_98 . V_46 = V_99 ;
V_2 -> V_98 . V_91 = V_2 -> V_94 ;
}
if ( V_2 -> V_9 ) {
V_2 -> V_100 . V_101 =
F_55 ( sizeof( struct V_102 * ) *
( V_2 -> V_9 + 2 ) , V_80 ) ;
if ( ! V_2 -> V_100 . V_101 ) {
V_30 = - V_62 ;
goto V_103;
}
V_2 -> V_100 . V_46 = F_60 ( & V_2 -> V_41 ) ;
V_2 -> V_100 . V_85 = F_53 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_9 ; V_25 ++ )
V_2 -> V_100 . V_101 [ V_25 ] =
& V_2 -> V_31 [ V_25 ] . V_89 ;
if ( V_2 -> V_5 )
V_2 -> V_100 . V_101 [ V_25 ] =
& V_2 -> V_98 ;
V_2 -> V_41 . type = & V_2 -> V_100 ;
}
V_30 = F_65 ( & V_2 -> V_41 ) ;
if ( V_30 ) {
F_66 ( & V_2 -> V_41 ) ;
goto V_104;
}
#if F_49 ( V_78 )
if ( V_79 )
V_30 = F_67 ( V_79 , & V_2 -> V_41 , NULL ) ;
#endif
F_68 ( & V_2 -> V_57 ) ;
V_2 -> V_58 = F_69 ( & V_2 -> V_41 ,
sizeof( * V_2 -> V_58 ) * V_2 -> V_9 , V_80 ) ;
if ( ! V_2 -> V_58 ) {
V_30 = - V_62 ;
goto V_104;
}
for ( V_25 = 0 ; V_25 < V_2 -> V_9 ; V_25 ++ )
F_70 ( & V_2 -> V_58 [ V_25 ] ) ;
F_71 ( & V_2 -> V_41 , V_2 ) ;
V_2 -> V_26 = 0 ;
F_38 ( & V_70 ) ;
F_72 ( & V_2 -> V_105 , & V_106 ) ;
F_40 ( & V_70 ) ;
return 0 ;
V_104:
if ( V_2 -> V_9 )
F_57 ( V_2 -> V_100 . V_101 ) ;
V_103:
if ( V_2 -> V_9 && V_2 -> V_5 ) {
for ( V_25 = 0 ; V_2 -> V_5 [ V_25 ] ; V_25 ++ )
F_57 ( V_2 -> V_97 [ V_25 ] . V_43 . V_46 ) ;
F_57 ( V_2 -> V_97 ) ;
F_57 ( V_2 -> V_94 ) ;
}
V_96:
for ( V_25 = 0 ; V_25 < V_2 -> V_9 ; V_25 ++ )
F_57 ( V_2 -> V_31 [ V_25 ] . V_89 . V_46 ) ;
V_90:
if ( V_2 -> V_9 )
F_57 ( V_2 -> V_31 ) ;
V_88:
return V_30 ;
}
void F_73 ( struct V_1 * V_2 )
{
int V_25 ;
if ( ! V_2 )
return;
F_38 ( & V_70 ) ;
F_74 ( & V_2 -> V_105 ) ;
F_40 ( & V_70 ) ;
if ( F_61 ( F_75 ( & V_2 -> V_41 ) ) ) {
F_24 ( & V_2 -> V_41 , L_18 ,
F_60 ( & V_2 -> V_41 ) ) ;
return;
}
F_76 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_5 && V_2 -> V_9 ) {
for ( V_25 = 0 ; V_2 -> V_5 [ V_25 ] ;
V_25 ++ )
F_57 ( V_2 -> V_97 [ V_25 ] . V_43 . V_46 ) ;
F_57 ( V_2 -> V_97 ) ;
F_57 ( V_2 -> V_94 ) ;
}
for ( V_25 = 0 ; V_25 < V_2 -> V_9 ; V_25 ++ )
F_57 ( V_2 -> V_31 [ V_25 ] . V_89 . V_46 ) ;
if ( V_2 -> V_9 ) {
F_57 ( V_2 -> V_100 . V_101 ) ;
F_57 ( V_2 -> V_31 ) ;
}
#if F_49 ( V_78 )
if ( V_79 )
F_77 ( V_79 , & V_2 -> V_41 , NULL ) ;
#endif
F_66 ( & V_2 -> V_41 ) ;
}
struct V_1 * F_78 ( struct V_40 * V_41 , int V_25 )
{
struct V_107 * V_108 ;
struct V_1 * V_2 ;
if ( ! V_41 )
return F_37 ( - V_11 ) ;
if ( ! V_41 -> V_109 ) {
F_79 ( V_41 , L_19 ) ;
return F_37 ( - V_11 ) ;
}
V_108 = F_80 ( V_41 -> V_109 , L_8 , V_25 ) ;
if ( ! V_108 ) {
F_79 ( V_41 , L_20 ,
V_41 -> V_109 -> V_110 ) ;
return F_37 ( - V_111 ) ;
}
F_38 ( & V_70 ) ;
F_39 (edev, &extcon_dev_list, entry) {
if ( V_2 -> V_41 . V_86 && V_2 -> V_41 . V_86 -> V_109 == V_108 ) {
F_40 ( & V_70 ) ;
F_81 ( V_108 ) ;
return V_2 ;
}
}
F_40 ( & V_70 ) ;
F_81 ( V_108 ) ;
return F_37 ( - V_112 ) ;
}
struct V_1 * F_78 ( struct V_40 * V_41 , int V_25 )
{
return F_37 ( - V_113 ) ;
}
const char * F_82 ( struct V_1 * V_2 )
{
return ! V_2 ? NULL : V_2 -> V_46 ;
}
static int T_4 F_83 ( void )
{
return F_45 () ;
}
static void T_5 F_84 ( void )
{
#if F_49 ( V_78 )
F_85 ( V_79 ) ;
#endif
F_86 ( V_74 ) ;
}
