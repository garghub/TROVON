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
static bool F_4 ( T_1 V_12 , T_1 V_13 , int V_14 , bool * V_15 )
{
if ( ( ( V_12 >> V_14 ) & 0x1 ) != ( ( V_13 >> V_14 ) & 0x1 ) ) {
* V_15 = ( ( V_13 >> V_14 ) & 0x1 ) ? true : false ;
return true ;
}
return false ;
}
static T_2 F_5 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
int V_4 , V_21 = 0 ;
struct V_1 * V_2 = F_6 ( V_17 ) ;
if ( V_2 -> V_9 == 0 )
return sprintf ( V_20 , L_1 , V_2 -> V_22 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ ) {
V_21 += sprintf ( V_20 + V_21 , L_2 ,
V_23 [ V_2 -> V_10 [ V_4 ] ] ,
! ! ( V_2 -> V_22 & ( 1 << V_4 ) ) ) ;
}
return V_21 ;
}
static T_2 F_7 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_3 V_21 )
{
T_1 V_22 ;
T_2 V_24 = 0 ;
struct V_1 * V_2 = F_6 ( V_17 ) ;
V_24 = sscanf ( V_20 , L_3 , & V_22 ) ;
if ( V_24 == 0 )
V_24 = - V_11 ;
else
V_24 = F_8 ( V_2 , V_22 ) ;
if ( V_24 < 0 )
return V_24 ;
return V_21 ;
}
static T_2 F_9 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
return sprintf ( V_20 , L_4 , V_2 -> V_25 ) ;
}
static T_2 F_10 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_26 * V_27 = F_11 ( V_19 , struct V_26 ,
V_28 ) ;
int V_4 = V_27 -> V_29 ;
return sprintf ( V_20 , L_4 ,
V_23 [ V_27 -> V_2 -> V_10 [ V_4 ] ] ) ;
}
static T_2 F_12 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_26 * V_27 = F_11 ( V_19 , struct V_26 ,
V_30 ) ;
int V_4 = V_27 -> V_29 ;
return sprintf ( V_20 , L_5 ,
F_13 ( V_27 -> V_2 ,
V_27 -> V_2 -> V_10 [ V_4 ] ) ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_31 , T_1 V_22 )
{
char V_32 [ 120 ] ;
char V_33 [ 120 ] ;
char * V_34 ;
char * V_35 [ 3 ] ;
int V_36 = 0 ;
int V_37 ;
int V_38 ;
unsigned long V_39 ;
bool V_15 ;
if ( ! V_2 )
return - V_11 ;
F_15 ( & V_2 -> V_40 , V_39 ) ;
if ( V_2 -> V_22 != ( ( V_2 -> V_22 & ~ V_31 ) | ( V_22 & V_31 ) ) ) {
T_1 V_41 ;
if ( F_1 ( V_2 , ( V_2 -> V_22 & ~ V_31 ) |
( V_22 & V_31 ) ) ) {
F_16 ( & V_2 -> V_40 , V_39 ) ;
return - V_42 ;
}
V_41 = V_2 -> V_22 ;
V_2 -> V_22 &= ~ V_31 ;
V_2 -> V_22 |= V_22 & V_31 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_9 ; V_38 ++ ) {
if ( F_4 ( V_41 , V_2 -> V_22 , V_38 ,
& V_15 ) )
F_17 ( & V_2 -> V_43 [ V_38 ] ,
V_15 , V_2 ) ;
}
V_34 = ( char * ) F_18 ( V_44 ) ;
if ( V_34 ) {
V_37 = F_9 ( & V_2 -> V_17 , NULL , V_34 ) ;
if ( V_37 > 0 ) {
if ( V_34 [ V_37 - 1 ] == '\n' )
V_34 [ V_37 - 1 ] = 0 ;
snprintf ( V_32 , sizeof( V_32 ) ,
L_6 , V_34 ) ;
V_35 [ V_36 ++ ] = V_32 ;
}
V_37 = F_5 ( & V_2 -> V_17 , NULL , V_34 ) ;
if ( V_37 > 0 ) {
if ( V_34 [ V_37 - 1 ] == '\n' )
V_34 [ V_37 - 1 ] = 0 ;
snprintf ( V_33 , sizeof( V_33 ) ,
L_7 , V_34 ) ;
V_35 [ V_36 ++ ] = V_33 ;
}
V_35 [ V_36 ] = NULL ;
F_16 ( & V_2 -> V_40 , V_39 ) ;
F_19 ( & V_2 -> V_17 . V_45 , V_46 , V_35 ) ;
F_20 ( ( unsigned long ) V_34 ) ;
} else {
F_16 ( & V_2 -> V_40 , V_39 ) ;
F_21 ( & V_2 -> V_17 , L_8 ) ;
F_22 ( & V_2 -> V_17 . V_45 , V_46 ) ;
}
} else {
F_16 ( & V_2 -> V_40 , V_39 ) ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_22 )
{
if ( ! V_2 )
return - V_11 ;
return F_14 ( V_2 , 0xffffffff , V_22 ) ;
}
int F_13 ( struct V_1 * V_2 , const unsigned int V_8 )
{
int V_38 ;
if ( ! V_2 )
return - V_11 ;
V_38 = F_3 ( V_2 , V_8 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_2 -> V_9 && V_2 -> V_9 <= V_38 )
return - V_11 ;
return ! ! ( V_2 -> V_22 & ( 1 << V_38 ) ) ;
}
int F_23 ( struct V_1 * V_2 , unsigned int V_8 ,
bool V_47 )
{
T_1 V_22 ;
int V_38 ;
if ( ! V_2 )
return - V_11 ;
V_38 = F_3 ( V_2 , V_8 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_2 -> V_9 && V_2 -> V_9 <= V_38 )
return - V_11 ;
V_22 = V_47 ? ( 1 << V_38 ) : 0 ;
return F_14 ( V_2 , 1 << V_38 , V_22 ) ;
}
struct V_1 * F_24 ( const char * V_23 )
{
struct V_1 * V_48 ;
if ( ! V_23 )
return F_25 ( - V_11 ) ;
F_26 ( & V_49 ) ;
F_27 (sd, &extcon_dev_list, entry) {
if ( ! strcmp ( V_48 -> V_25 , V_23 ) )
goto V_50;
}
V_48 = NULL ;
V_50:
F_28 ( & V_49 ) ;
return V_48 ;
}
int F_29 ( struct V_1 * V_2 , unsigned int V_8 ,
struct V_51 * V_52 )
{
unsigned long V_39 ;
int V_24 , V_14 ;
if ( ! V_52 )
return - V_11 ;
if ( V_2 ) {
V_14 = F_3 ( V_2 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
F_15 ( & V_2 -> V_40 , V_39 ) ;
V_24 = F_30 ( & V_2 -> V_43 [ V_14 ] , V_52 ) ;
F_16 ( & V_2 -> V_40 , V_39 ) ;
} else {
struct V_1 * V_53 ;
F_26 ( & V_49 ) ;
F_27 (extd, &extcon_dev_list, entry) {
V_14 = F_3 ( V_53 , V_8 ) ;
if ( V_14 >= 0 )
break;
}
F_28 ( & V_49 ) ;
if ( V_14 >= 0 ) {
V_2 = V_53 ;
return F_29 ( V_53 , V_8 , V_52 ) ;
} else {
V_24 = - V_54 ;
}
}
return V_24 ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_8 ,
struct V_51 * V_52 )
{
unsigned long V_39 ;
int V_24 , V_14 ;
if ( ! V_2 || ! V_52 )
return - V_11 ;
V_14 = F_3 ( V_2 , V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
F_15 ( & V_2 -> V_40 , V_39 ) ;
V_24 = F_32 ( & V_2 -> V_43 [ V_14 ] , V_52 ) ;
F_16 ( & V_2 -> V_40 , V_39 ) ;
return V_24 ;
}
static int F_33 ( void )
{
if ( ! V_55 ) {
V_55 = F_34 ( V_56 , L_9 ) ;
if ( F_35 ( V_55 ) )
return F_36 ( V_55 ) ;
V_55 -> V_57 = V_58 ;
#if F_37 ( V_59 )
V_60 = F_38 ( L_10 ) ;
if ( F_39 ( ! V_60 , L_11 ) )
return - V_61 ;
#endif
}
return 0 ;
}
static void F_40 ( struct V_16 * V_17 )
{
}
static void F_41 ( struct V_16 * V_17 )
{
}
struct V_1 * F_42 ( const unsigned int * V_10 )
{
struct V_1 * V_2 ;
if ( ! V_10 )
return F_25 ( - V_11 ) ;
V_2 = F_43 ( sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return F_25 ( - V_61 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = V_10 ;
return V_2 ;
}
void F_44 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_24 , V_38 = 0 ;
static T_4 V_63 = F_47 ( - 1 ) ;
if ( ! V_55 ) {
V_24 = F_33 () ;
if ( V_24 < 0 )
return V_24 ;
}
if ( ! V_2 || ! V_2 -> V_10 )
return - V_11 ;
for (; V_2 -> V_10 [ V_38 ] != V_64 ; V_38 ++ ) ;
V_2 -> V_9 = V_38 ;
if ( V_38 > V_65 ) {
F_21 ( & V_2 -> V_17 ,
L_12 ) ;
return - V_11 ;
}
V_2 -> V_17 . V_66 = V_55 ;
V_2 -> V_17 . V_67 = F_40 ;
V_2 -> V_25 = F_48 ( V_2 -> V_17 . V_68 ) ;
if ( F_49 ( V_2 -> V_25 ) ) {
F_21 ( & V_2 -> V_17 ,
L_13 ) ;
return - V_11 ;
}
F_50 ( & V_2 -> V_17 , L_14 ,
( unsigned long ) F_51 ( & V_63 ) ) ;
if ( V_2 -> V_9 ) {
char V_20 [ 10 ] ;
char * V_69 ;
struct V_26 * V_27 ;
V_2 -> V_70 = F_43 ( sizeof( struct V_26 ) *
V_2 -> V_9 , V_62 ) ;
if ( ! V_2 -> V_70 ) {
V_24 = - V_61 ;
goto V_71;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_9 ; V_38 ++ ) {
V_27 = & V_2 -> V_70 [ V_38 ] ;
snprintf ( V_20 , 10 , L_15 , V_38 ) ;
V_69 = F_43 ( sizeof( char ) * ( strlen ( V_20 ) + 1 ) ,
V_62 ) ;
if ( ! V_69 ) {
for ( V_38 -- ; V_38 >= 0 ; V_38 -- ) {
V_27 = & V_2 -> V_70 [ V_38 ] ;
F_45 ( V_27 -> V_72 . V_25 ) ;
}
V_24 = - V_61 ;
goto V_73;
}
strcpy ( V_69 , V_20 ) ;
V_27 -> V_2 = V_2 ;
V_27 -> V_29 = V_38 ;
V_27 -> V_74 [ 0 ] = & V_27 -> V_28 . V_19 ;
V_27 -> V_74 [ 1 ] = & V_27 -> V_30 . V_19 ;
V_27 -> V_74 [ 2 ] = NULL ;
V_27 -> V_72 . V_25 = V_69 ;
V_27 -> V_72 . V_74 = V_27 -> V_74 ;
F_52 ( & V_27 -> V_28 . V_19 ) ;
V_27 -> V_28 . V_19 . V_25 = L_16 ;
V_27 -> V_28 . V_19 . V_75 = 0444 ;
V_27 -> V_28 . V_76 = F_10 ;
F_52 ( & V_27 -> V_30 . V_19 ) ;
V_27 -> V_30 . V_19 . V_25 = L_17 ;
V_27 -> V_30 . V_19 . V_75 = 0444 ;
V_27 -> V_30 . V_76 = F_12 ;
}
}
if ( V_2 -> V_9 && V_2 -> V_5 ) {
char V_20 [ 80 ] ;
char * V_25 ;
for ( V_38 = 0 ; V_2 -> V_5 [ V_38 ] ; V_38 ++ )
;
V_2 -> V_77 = F_43 ( sizeof( struct V_78 * ) *
( V_38 + 1 ) , V_62 ) ;
if ( ! V_2 -> V_77 ) {
V_24 = - V_61 ;
goto V_79;
}
V_2 -> V_80 = F_43 ( sizeof( struct V_18 ) *
V_38 , V_62 ) ;
if ( ! V_2 -> V_80 ) {
V_24 = - V_61 ;
F_45 ( V_2 -> V_77 ) ;
goto V_79;
}
for ( V_38 = 0 ; V_2 -> V_5 [ V_38 ] ; V_38 ++ ) {
sprintf ( V_20 , L_3 , V_2 -> V_5 [ V_38 ] ) ;
V_25 = F_43 ( sizeof( char ) * ( strlen ( V_20 ) + 1 ) ,
V_62 ) ;
if ( ! V_25 ) {
for ( V_38 -- ; V_38 >= 0 ; V_38 -- ) {
F_45 ( V_2 -> V_80 [ V_38 ] . V_19 .
V_25 ) ;
}
F_45 ( V_2 -> V_80 ) ;
F_45 ( V_2 -> V_77 ) ;
V_24 = - V_61 ;
goto V_79;
}
strcpy ( V_25 , V_20 ) ;
F_52 ( & V_2 -> V_80 [ V_38 ] . V_19 ) ;
V_2 -> V_80 [ V_38 ] . V_19 . V_25 = V_25 ;
V_2 -> V_80 [ V_38 ] . V_19 . V_75 = 0000 ;
V_2 -> V_77 [ V_38 ] = & V_2 -> V_80 [ V_38 ]
. V_19 ;
}
V_2 -> V_81 . V_25 = V_82 ;
V_2 -> V_81 . V_74 = V_2 -> V_77 ;
}
if ( V_2 -> V_9 ) {
V_2 -> V_83 . V_84 =
F_43 ( sizeof( struct V_85 * ) *
( V_2 -> V_9 + 2 ) , V_62 ) ;
if ( ! V_2 -> V_83 . V_84 ) {
V_24 = - V_61 ;
goto V_86;
}
V_2 -> V_83 . V_25 = F_48 ( & V_2 -> V_17 ) ;
V_2 -> V_83 . V_67 = F_41 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_9 ; V_38 ++ )
V_2 -> V_83 . V_84 [ V_38 ] =
& V_2 -> V_70 [ V_38 ] . V_72 ;
if ( V_2 -> V_5 )
V_2 -> V_83 . V_84 [ V_38 ] =
& V_2 -> V_81 ;
V_2 -> V_17 . type = & V_2 -> V_83 ;
}
V_24 = F_53 ( & V_2 -> V_17 ) ;
if ( V_24 ) {
F_54 ( & V_2 -> V_17 ) ;
goto V_87;
}
#if F_37 ( V_59 )
if ( V_60 )
V_24 = F_55 ( V_60 , & V_2 -> V_17 , NULL ) ;
#endif
F_56 ( & V_2 -> V_40 ) ;
V_2 -> V_43 = F_57 ( & V_2 -> V_17 ,
sizeof( * V_2 -> V_43 ) * V_2 -> V_9 , V_62 ) ;
if ( ! V_2 -> V_43 ) {
V_24 = - V_61 ;
goto V_87;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_9 ; V_38 ++ )
F_58 ( & V_2 -> V_43 [ V_38 ] ) ;
F_59 ( & V_2 -> V_17 , V_2 ) ;
V_2 -> V_22 = 0 ;
F_26 ( & V_49 ) ;
F_60 ( & V_2 -> V_88 , & V_89 ) ;
F_28 ( & V_49 ) ;
return 0 ;
V_87:
if ( V_2 -> V_9 )
F_45 ( V_2 -> V_83 . V_84 ) ;
V_86:
if ( V_2 -> V_9 && V_2 -> V_5 ) {
for ( V_38 = 0 ; V_2 -> V_5 [ V_38 ] ; V_38 ++ )
F_45 ( V_2 -> V_80 [ V_38 ] . V_19 . V_25 ) ;
F_45 ( V_2 -> V_80 ) ;
F_45 ( V_2 -> V_77 ) ;
}
V_79:
for ( V_38 = 0 ; V_38 < V_2 -> V_9 ; V_38 ++ )
F_45 ( V_2 -> V_70 [ V_38 ] . V_72 . V_25 ) ;
V_73:
if ( V_2 -> V_9 )
F_45 ( V_2 -> V_70 ) ;
V_71:
return V_24 ;
}
void F_61 ( struct V_1 * V_2 )
{
int V_38 ;
if ( ! V_2 )
return;
F_26 ( & V_49 ) ;
F_62 ( & V_2 -> V_88 ) ;
F_28 ( & V_49 ) ;
if ( F_49 ( F_63 ( & V_2 -> V_17 ) ) ) {
F_21 ( & V_2 -> V_17 , L_18 ,
F_48 ( & V_2 -> V_17 ) ) ;
return;
}
F_64 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_5 && V_2 -> V_9 ) {
for ( V_38 = 0 ; V_2 -> V_5 [ V_38 ] ;
V_38 ++ )
F_45 ( V_2 -> V_80 [ V_38 ] . V_19 . V_25 ) ;
F_45 ( V_2 -> V_80 ) ;
F_45 ( V_2 -> V_77 ) ;
}
for ( V_38 = 0 ; V_38 < V_2 -> V_9 ; V_38 ++ )
F_45 ( V_2 -> V_70 [ V_38 ] . V_72 . V_25 ) ;
if ( V_2 -> V_9 ) {
F_45 ( V_2 -> V_83 . V_84 ) ;
F_45 ( V_2 -> V_70 ) ;
}
#if F_37 ( V_59 )
if ( V_60 )
F_65 ( V_60 , & V_2 -> V_17 , NULL ) ;
#endif
F_54 ( & V_2 -> V_17 ) ;
}
struct V_1 * F_66 ( struct V_16 * V_17 , int V_38 )
{
struct V_90 * V_91 ;
struct V_1 * V_2 ;
if ( ! V_17 )
return F_25 ( - V_11 ) ;
if ( ! V_17 -> V_92 ) {
F_21 ( V_17 , L_19 ) ;
return F_25 ( - V_11 ) ;
}
V_91 = F_67 ( V_17 -> V_92 , L_9 , V_38 ) ;
if ( ! V_91 ) {
F_21 ( V_17 , L_20 ,
V_17 -> V_92 -> V_93 ) ;
return F_25 ( - V_54 ) ;
}
F_26 ( & V_49 ) ;
F_27 (edev, &extcon_dev_list, entry) {
if ( V_2 -> V_17 . V_68 && V_2 -> V_17 . V_68 -> V_92 == V_91 ) {
F_28 ( & V_49 ) ;
F_68 ( V_91 ) ;
return V_2 ;
}
}
F_28 ( & V_49 ) ;
F_68 ( V_91 ) ;
return F_25 ( - V_94 ) ;
}
struct V_1 * F_66 ( struct V_16 * V_17 , int V_38 )
{
return F_25 ( - V_95 ) ;
}
const char * F_69 ( struct V_1 * V_2 )
{
return ! V_2 ? NULL : V_2 -> V_25 ;
}
static int T_5 F_70 ( void )
{
return F_33 () ;
}
static void T_6 F_71 ( void )
{
#if F_37 ( V_59 )
F_72 ( V_60 ) ;
#endif
F_73 ( V_55 ) ;
}
