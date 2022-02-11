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
! ! ( V_2 -> V_26 & F_6 ( V_4 ) ) ) ;
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
F_21 ( & V_2 -> V_59 , V_26 , V_2 ) ;
V_52 = ( char * ) F_22 ( V_60 ) ;
if ( ! V_52 ) {
F_23 ( & V_2 -> V_57 , V_56 ) ;
F_24 ( & V_2 -> V_41 , L_5 ) ;
F_25 ( & V_2 -> V_41 . V_61 , V_62 ) ;
return - V_63 ;
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
F_26 ( & V_2 -> V_41 . V_61 , V_62 , V_53 ) ;
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
bool V_64 )
{
unsigned long V_56 ;
int V_25 , V_30 = 0 ;
if ( ! V_2 )
return - V_11 ;
V_25 = F_3 ( V_2 , V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
if ( ! F_7 ( V_2 , V_25 , V_64 ) )
goto V_65;
if ( F_1 ( V_2 ,
( V_2 -> V_26 & ~ F_6 ( V_25 ) ) | ( V_64 & F_6 ( V_25 ) ) ) ) {
V_30 = - V_66 ;
goto V_65;
}
if ( ! V_64 )
F_11 ( V_2 , V_8 , V_25 ) ;
if ( V_64 )
V_2 -> V_26 |= F_6 ( V_25 ) ;
else
V_2 -> V_26 &= ~ ( F_6 ( V_25 ) ) ;
V_65:
F_23 ( & V_2 -> V_57 , V_56 ) ;
return V_30 ;
}
int F_29 ( struct V_1 * V_2 , unsigned int V_8 ,
bool V_64 )
{
int V_30 , V_25 ;
unsigned long V_56 ;
V_25 = F_3 ( V_2 , V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
V_30 = F_7 ( V_2 , V_25 , V_64 ) ;
F_23 ( & V_2 -> V_57 , V_56 ) ;
if ( ! V_30 )
return 0 ;
V_30 = F_28 ( V_2 , V_8 , V_64 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_19 ( V_2 , V_8 ) ;
}
int F_30 ( struct V_1 * V_2 , unsigned int V_8 ,
unsigned int V_12 ,
union V_67 * V_68 )
{
struct V_28 * V_29 ;
unsigned long V_56 ;
int V_25 , V_30 = 0 ;
* V_68 = (union V_67 ) ( 0 ) ;
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
return - V_66 ;
}
if ( ! F_5 ( V_2 , V_25 ) ) {
F_23 ( & V_2 -> V_57 , V_56 ) ;
return 0 ;
}
V_29 = & V_2 -> V_31 [ V_25 ] ;
switch ( V_12 ) {
case V_13 ... V_14 :
* V_68 = V_29 -> V_36 [ V_12 - V_13 ] ;
break;
case V_16 ... V_17 :
* V_68 = V_29 -> V_37 [ V_12 - V_16 ] ;
break;
case V_19 ... V_20 :
* V_68 = V_29 -> V_38 [ V_12 - V_19 ] ;
break;
case V_22 ... V_23 :
* V_68 = V_29 -> V_39 [ V_12 - V_22 ] ;
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
union V_67 V_68 )
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
return - V_66 ;
}
V_29 = & V_2 -> V_31 [ V_25 ] ;
switch ( V_12 ) {
case V_13 ... V_14 :
V_29 -> V_36 [ V_12 - V_13 ] = V_68 ;
break;
case V_16 ... V_17 :
V_29 -> V_37 [ V_12 - V_16 ] = V_68 ;
break;
case V_19 ... V_20 :
V_29 -> V_38 [ V_12 - V_19 ] = V_68 ;
break;
case V_22 ... V_23 :
V_29 -> V_39 [ V_12 - V_22 ] = V_68 ;
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
union V_67 V_68 )
{
int V_30 ;
V_30 = F_31 ( V_2 , V_8 , V_12 , V_68 ) ;
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
struct V_1 * F_36 ( const char * V_69 )
{
struct V_1 * V_70 ;
if ( ! V_69 )
return F_37 ( - V_11 ) ;
F_38 ( & V_71 ) ;
F_39 (sd, &extcon_dev_list, entry) {
if ( ! strcmp ( V_70 -> V_46 , V_69 ) )
goto V_65;
}
V_70 = NULL ;
V_65:
F_40 ( & V_71 ) ;
return V_70 ;
}
int F_41 ( struct V_1 * V_2 , unsigned int V_8 ,
struct V_72 * V_73 )
{
unsigned long V_56 ;
int V_30 , V_74 = - V_11 ;
if ( ! V_2 || ! V_73 )
return - V_11 ;
V_74 = F_3 ( V_2 , V_8 ) ;
if ( V_74 < 0 )
return V_74 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
V_30 = F_42 ( & V_2 -> V_58 [ V_74 ] , V_73 ) ;
F_23 ( & V_2 -> V_57 , V_56 ) ;
return V_30 ;
}
int F_43 ( struct V_1 * V_2 , unsigned int V_8 ,
struct V_72 * V_73 )
{
unsigned long V_56 ;
int V_30 , V_74 ;
if ( ! V_2 || ! V_73 )
return - V_11 ;
V_74 = F_3 ( V_2 , V_8 ) ;
if ( V_74 < 0 )
return V_74 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
V_30 = F_44 ( & V_2 -> V_58 [ V_74 ] , V_73 ) ;
F_23 ( & V_2 -> V_57 , V_56 ) ;
return V_30 ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
unsigned long V_56 ;
int V_30 ;
if ( ! V_2 || ! V_73 )
return - V_11 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
V_30 = F_42 ( & V_2 -> V_59 , V_73 ) ;
F_23 ( & V_2 -> V_57 , V_56 ) ;
return V_30 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
unsigned long V_56 ;
int V_30 ;
if ( ! V_2 || ! V_73 )
return - V_11 ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
V_30 = F_44 ( & V_2 -> V_59 , V_73 ) ;
F_23 ( & V_2 -> V_57 , V_56 ) ;
return V_30 ;
}
static int F_47 ( void )
{
if ( ! V_75 ) {
V_75 = F_48 ( V_76 , L_8 ) ;
if ( F_49 ( V_75 ) )
return F_50 ( V_75 ) ;
V_75 -> V_77 = V_78 ;
}
return 0 ;
}
static void F_51 ( struct V_40 * V_41 )
{
}
static void F_52 ( struct V_40 * V_41 )
{
}
struct V_1 * F_53 ( const unsigned int * V_10 )
{
struct V_1 * V_2 ;
if ( ! V_10 )
return F_37 ( - V_11 ) ;
V_2 = F_54 ( sizeof( * V_2 ) , V_79 ) ;
if ( ! V_2 )
return F_37 ( - V_63 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = V_10 ;
return V_2 ;
}
void F_55 ( struct V_1 * V_2 )
{
F_56 ( V_2 ) ;
}
int F_57 ( struct V_1 * V_2 )
{
int V_30 , V_25 = 0 ;
static T_3 V_80 = F_58 ( - 1 ) ;
if ( ! V_75 ) {
V_30 = F_47 () ;
if ( V_30 < 0 )
return V_30 ;
}
if ( ! V_2 || ! V_2 -> V_10 )
return - V_11 ;
for (; V_2 -> V_10 [ V_25 ] != V_81 ; V_25 ++ ) ;
V_2 -> V_9 = V_25 ;
if ( V_25 > V_82 ) {
F_24 ( & V_2 -> V_41 ,
L_9 ) ;
return - V_11 ;
}
V_2 -> V_41 . V_83 = V_75 ;
V_2 -> V_41 . V_84 = F_51 ;
V_2 -> V_46 = F_59 ( V_2 -> V_41 . V_85 ) ;
if ( F_60 ( V_2 -> V_46 ) ) {
F_24 ( & V_2 -> V_41 ,
L_10 ) ;
return - V_11 ;
}
F_61 ( & V_2 -> V_41 , L_11 ,
( unsigned long ) F_62 ( & V_80 ) ) ;
if ( V_2 -> V_9 ) {
char V_44 [ 10 ] ;
char * V_86 ;
struct V_28 * V_29 ;
V_2 -> V_31 = F_54 ( sizeof( struct V_28 ) *
V_2 -> V_9 , V_79 ) ;
if ( ! V_2 -> V_31 ) {
V_30 = - V_63 ;
goto V_87;
}
for ( V_25 = 0 ; V_25 < V_2 -> V_9 ; V_25 ++ ) {
V_29 = & V_2 -> V_31 [ V_25 ] ;
snprintf ( V_44 , 10 , L_12 , V_25 ) ;
V_86 = F_54 ( sizeof( char ) * ( strlen ( V_44 ) + 1 ) ,
V_79 ) ;
if ( ! V_86 ) {
for ( V_25 -- ; V_25 >= 0 ; V_25 -- ) {
V_29 = & V_2 -> V_31 [ V_25 ] ;
F_56 ( V_29 -> V_88 . V_46 ) ;
}
V_30 = - V_63 ;
goto V_89;
}
strcpy ( V_86 , V_44 ) ;
V_29 -> V_2 = V_2 ;
V_29 -> V_48 = V_25 ;
V_29 -> V_90 [ 0 ] = & V_29 -> V_47 . V_43 ;
V_29 -> V_90 [ 1 ] = & V_29 -> V_49 . V_43 ;
V_29 -> V_90 [ 2 ] = NULL ;
V_29 -> V_88 . V_46 = V_86 ;
V_29 -> V_88 . V_90 = V_29 -> V_90 ;
F_63 ( & V_29 -> V_47 . V_43 ) ;
V_29 -> V_47 . V_43 . V_46 = L_13 ;
V_29 -> V_47 . V_43 . V_91 = 0444 ;
V_29 -> V_47 . V_92 = F_15 ;
F_63 ( & V_29 -> V_49 . V_43 ) ;
V_29 -> V_49 . V_43 . V_46 = L_14 ;
V_29 -> V_49 . V_43 . V_91 = 0444 ;
V_29 -> V_49 . V_92 = F_17 ;
}
}
if ( V_2 -> V_9 && V_2 -> V_5 ) {
char V_44 [ 80 ] ;
char * V_46 ;
for ( V_25 = 0 ; V_2 -> V_5 [ V_25 ] ; V_25 ++ )
;
V_2 -> V_93 = F_54 ( sizeof( struct V_94 * ) *
( V_25 + 1 ) , V_79 ) ;
if ( ! V_2 -> V_93 ) {
V_30 = - V_63 ;
goto V_95;
}
V_2 -> V_96 = F_54 ( sizeof( struct V_42 ) *
V_25 , V_79 ) ;
if ( ! V_2 -> V_96 ) {
V_30 = - V_63 ;
F_56 ( V_2 -> V_93 ) ;
goto V_95;
}
for ( V_25 = 0 ; V_2 -> V_5 [ V_25 ] ; V_25 ++ ) {
sprintf ( V_44 , L_15 , V_2 -> V_5 [ V_25 ] ) ;
V_46 = F_54 ( sizeof( char ) * ( strlen ( V_44 ) + 1 ) ,
V_79 ) ;
if ( ! V_46 ) {
for ( V_25 -- ; V_25 >= 0 ; V_25 -- ) {
F_56 ( V_2 -> V_96 [ V_25 ] . V_43 .
V_46 ) ;
}
F_56 ( V_2 -> V_96 ) ;
F_56 ( V_2 -> V_93 ) ;
V_30 = - V_63 ;
goto V_95;
}
strcpy ( V_46 , V_44 ) ;
F_63 ( & V_2 -> V_96 [ V_25 ] . V_43 ) ;
V_2 -> V_96 [ V_25 ] . V_43 . V_46 = V_46 ;
V_2 -> V_96 [ V_25 ] . V_43 . V_91 = 0000 ;
V_2 -> V_93 [ V_25 ] = & V_2 -> V_96 [ V_25 ]
. V_43 ;
}
V_2 -> V_97 . V_46 = V_98 ;
V_2 -> V_97 . V_90 = V_2 -> V_93 ;
}
if ( V_2 -> V_9 ) {
V_2 -> V_99 . V_100 =
F_54 ( sizeof( struct V_101 * ) *
( V_2 -> V_9 + 2 ) , V_79 ) ;
if ( ! V_2 -> V_99 . V_100 ) {
V_30 = - V_63 ;
goto V_102;
}
V_2 -> V_99 . V_46 = F_59 ( & V_2 -> V_41 ) ;
V_2 -> V_99 . V_84 = F_52 ;
for ( V_25 = 0 ; V_25 < V_2 -> V_9 ; V_25 ++ )
V_2 -> V_99 . V_100 [ V_25 ] =
& V_2 -> V_31 [ V_25 ] . V_88 ;
if ( V_2 -> V_5 )
V_2 -> V_99 . V_100 [ V_25 ] =
& V_2 -> V_97 ;
V_2 -> V_41 . type = & V_2 -> V_99 ;
}
V_30 = F_64 ( & V_2 -> V_41 ) ;
if ( V_30 ) {
F_65 ( & V_2 -> V_41 ) ;
goto V_103;
}
F_66 ( & V_2 -> V_57 ) ;
V_2 -> V_58 = F_67 ( & V_2 -> V_41 ,
sizeof( * V_2 -> V_58 ) * V_2 -> V_9 , V_79 ) ;
if ( ! V_2 -> V_58 ) {
V_30 = - V_63 ;
goto V_103;
}
for ( V_25 = 0 ; V_25 < V_2 -> V_9 ; V_25 ++ )
F_68 ( & V_2 -> V_58 [ V_25 ] ) ;
F_68 ( & V_2 -> V_59 ) ;
F_69 ( & V_2 -> V_41 , V_2 ) ;
V_2 -> V_26 = 0 ;
F_38 ( & V_71 ) ;
F_70 ( & V_2 -> V_104 , & V_105 ) ;
F_40 ( & V_71 ) ;
return 0 ;
V_103:
if ( V_2 -> V_9 )
F_56 ( V_2 -> V_99 . V_100 ) ;
V_102:
if ( V_2 -> V_9 && V_2 -> V_5 ) {
for ( V_25 = 0 ; V_2 -> V_5 [ V_25 ] ; V_25 ++ )
F_56 ( V_2 -> V_96 [ V_25 ] . V_43 . V_46 ) ;
F_56 ( V_2 -> V_96 ) ;
F_56 ( V_2 -> V_93 ) ;
}
V_95:
for ( V_25 = 0 ; V_25 < V_2 -> V_9 ; V_25 ++ )
F_56 ( V_2 -> V_31 [ V_25 ] . V_88 . V_46 ) ;
V_89:
if ( V_2 -> V_9 )
F_56 ( V_2 -> V_31 ) ;
V_87:
return V_30 ;
}
void F_71 ( struct V_1 * V_2 )
{
int V_25 ;
if ( ! V_2 )
return;
F_38 ( & V_71 ) ;
F_72 ( & V_2 -> V_104 ) ;
F_40 ( & V_71 ) ;
if ( F_60 ( F_73 ( & V_2 -> V_41 ) ) ) {
F_24 ( & V_2 -> V_41 , L_16 ,
F_59 ( & V_2 -> V_41 ) ) ;
return;
}
F_74 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_5 && V_2 -> V_9 ) {
for ( V_25 = 0 ; V_2 -> V_5 [ V_25 ] ;
V_25 ++ )
F_56 ( V_2 -> V_96 [ V_25 ] . V_43 . V_46 ) ;
F_56 ( V_2 -> V_96 ) ;
F_56 ( V_2 -> V_93 ) ;
}
for ( V_25 = 0 ; V_25 < V_2 -> V_9 ; V_25 ++ )
F_56 ( V_2 -> V_31 [ V_25 ] . V_88 . V_46 ) ;
if ( V_2 -> V_9 ) {
F_56 ( V_2 -> V_99 . V_100 ) ;
F_56 ( V_2 -> V_31 ) ;
}
F_65 ( & V_2 -> V_41 ) ;
}
struct V_1 * F_75 ( struct V_40 * V_41 , int V_25 )
{
struct V_106 * V_107 ;
struct V_1 * V_2 ;
if ( ! V_41 )
return F_37 ( - V_11 ) ;
if ( ! V_41 -> V_108 ) {
F_76 ( V_41 , L_17 ) ;
return F_37 ( - V_11 ) ;
}
V_107 = F_77 ( V_41 -> V_108 , L_8 , V_25 ) ;
if ( ! V_107 ) {
F_76 ( V_41 , L_18 ,
V_41 -> V_108 -> V_109 ) ;
return F_37 ( - V_110 ) ;
}
F_38 ( & V_71 ) ;
F_39 (edev, &extcon_dev_list, entry) {
if ( V_2 -> V_41 . V_85 && V_2 -> V_41 . V_85 -> V_108 == V_107 ) {
F_40 ( & V_71 ) ;
F_78 ( V_107 ) ;
return V_2 ;
}
}
F_40 ( & V_71 ) ;
F_78 ( V_107 ) ;
return F_37 ( - V_111 ) ;
}
struct V_1 * F_75 ( struct V_40 * V_41 , int V_25 )
{
return F_37 ( - V_112 ) ;
}
const char * F_79 ( struct V_1 * V_2 )
{
return ! V_2 ? NULL : V_2 -> V_46 ;
}
static int T_4 F_80 ( void )
{
return F_47 () ;
}
static void T_5 F_81 ( void )
{
F_82 ( V_75 ) ;
}
