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
int V_8 = - V_11 ;
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
int V_8 ;
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
* V_18 = ( ( V_16 >> V_17 ) & 0x1 ) ? true : false ;
return true ;
}
return false ;
}
static T_2 F_7 ( struct V_19 * V_20 , struct V_21 * V_22 ,
char * V_23 )
{
int V_4 , V_24 = 0 ;
struct V_1 * V_2 = F_8 ( V_20 ) ;
if ( V_2 -> V_9 == 0 )
return sprintf ( V_23 , L_1 , V_2 -> V_25 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ ) {
V_24 += sprintf ( V_23 + V_24 , L_2 ,
V_13 [ V_2 -> V_10 [ V_4 ] ] ,
! ! ( V_2 -> V_25 & ( 1 << V_4 ) ) ) ;
}
return V_24 ;
}
static T_2 F_9 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_23 , T_3 V_24 )
{
T_1 V_25 ;
T_2 V_26 = 0 ;
struct V_1 * V_2 = F_8 ( V_20 ) ;
V_26 = sscanf ( V_23 , L_3 , & V_25 ) ;
if ( V_26 == 0 )
V_26 = - V_11 ;
else
V_26 = F_10 ( V_2 , V_25 ) ;
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
struct V_27 * V_28 = F_13 ( V_22 , struct V_27 ,
V_29 ) ;
int V_4 = V_28 -> V_30 ;
return sprintf ( V_23 , L_4 ,
V_13 [ V_28 -> V_2 -> V_10 [ V_4 ] ] ) ;
}
static T_2 F_14 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_27 * V_28 = F_13 ( V_22 , struct V_27 ,
V_31 ) ;
int V_4 = V_28 -> V_30 ;
return sprintf ( V_23 , L_5 ,
F_15 ( V_28 -> V_2 ,
V_28 -> V_2 -> V_10 [ V_4 ] ) ) ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_32 , T_1 V_25 )
{
char V_33 [ 120 ] ;
char V_34 [ 120 ] ;
char * V_35 ;
char * V_36 [ 3 ] ;
int V_37 = 0 ;
int V_38 ;
int V_39 ;
unsigned long V_40 ;
bool V_18 ;
if ( ! V_2 )
return - V_11 ;
F_17 ( & V_2 -> V_41 , V_40 ) ;
if ( V_2 -> V_25 != ( ( V_2 -> V_25 & ~ V_32 ) | ( V_25 & V_32 ) ) ) {
T_1 V_42 ;
if ( F_1 ( V_2 , ( V_2 -> V_25 & ~ V_32 ) |
( V_25 & V_32 ) ) ) {
F_18 ( & V_2 -> V_41 , V_40 ) ;
return - V_43 ;
}
V_42 = V_2 -> V_25 ;
V_2 -> V_25 &= ~ V_32 ;
V_2 -> V_25 |= V_25 & V_32 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_9 ; V_39 ++ ) {
if ( F_6 ( V_42 , V_2 -> V_25 , V_39 ,
& V_18 ) )
F_19 ( & V_2 -> V_44 [ V_39 ] ,
V_18 , V_2 ) ;
}
V_35 = ( char * ) F_20 ( V_45 ) ;
if ( V_35 ) {
V_38 = F_11 ( & V_2 -> V_20 , NULL , V_35 ) ;
if ( V_38 > 0 ) {
if ( V_35 [ V_38 - 1 ] == '\n' )
V_35 [ V_38 - 1 ] = 0 ;
snprintf ( V_33 , sizeof( V_33 ) ,
L_6 , V_35 ) ;
V_36 [ V_37 ++ ] = V_33 ;
}
V_38 = F_7 ( & V_2 -> V_20 , NULL , V_35 ) ;
if ( V_38 > 0 ) {
if ( V_35 [ V_38 - 1 ] == '\n' )
V_35 [ V_38 - 1 ] = 0 ;
snprintf ( V_34 , sizeof( V_34 ) ,
L_7 , V_35 ) ;
V_36 [ V_37 ++ ] = V_34 ;
}
V_36 [ V_37 ] = NULL ;
F_18 ( & V_2 -> V_41 , V_40 ) ;
F_21 ( & V_2 -> V_20 . V_46 , V_47 , V_36 ) ;
F_22 ( ( unsigned long ) V_35 ) ;
} else {
F_18 ( & V_2 -> V_41 , V_40 ) ;
F_23 ( & V_2 -> V_20 , L_8 ) ;
F_24 ( & V_2 -> V_20 . V_46 , V_47 ) ;
}
} else {
F_18 ( & V_2 -> V_41 , V_40 ) ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_25 )
{
if ( ! V_2 )
return - V_11 ;
return F_16 ( V_2 , 0xffffffff , V_25 ) ;
}
int F_15 ( struct V_1 * V_2 , const unsigned int V_8 )
{
int V_39 ;
if ( ! V_2 )
return - V_11 ;
V_39 = F_3 ( V_2 , V_8 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_2 -> V_9 && V_2 -> V_9 <= V_39 )
return - V_11 ;
return ! ! ( V_2 -> V_25 & ( 1 << V_39 ) ) ;
}
int F_25 ( struct V_1 * V_2 , const char * V_48 )
{
int V_8 ;
V_8 = F_4 ( V_2 , V_48 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_15 ( V_2 , V_8 ) ;
}
int F_26 ( struct V_1 * V_2 , unsigned int V_8 ,
bool V_49 )
{
T_1 V_25 ;
int V_39 ;
if ( ! V_2 )
return - V_11 ;
V_39 = F_3 ( V_2 , V_8 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_2 -> V_9 && V_2 -> V_9 <= V_39 )
return - V_11 ;
V_25 = V_49 ? ( 1 << V_39 ) : 0 ;
return F_16 ( V_2 , 1 << V_39 , V_25 ) ;
}
int F_27 ( struct V_1 * V_2 ,
const char * V_48 , bool V_49 )
{
int V_8 ;
V_8 = F_4 ( V_2 , V_48 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_26 ( V_2 , V_8 , V_49 ) ;
}
struct V_1 * F_28 ( const char * V_13 )
{
struct V_1 * V_50 ;
if ( ! V_13 )
return F_29 ( - V_11 ) ;
F_30 ( & V_51 ) ;
F_31 (sd, &extcon_dev_list, entry) {
if ( ! strcmp ( V_50 -> V_12 , V_13 ) )
goto V_52;
}
V_50 = NULL ;
V_52:
F_32 ( & V_51 ) ;
return V_50 ;
}
int F_33 ( struct V_53 * V_54 ,
const char * V_13 , const char * V_48 ,
struct V_55 * V_56 )
{
unsigned long V_40 ;
int V_26 ;
if ( ! V_54 || ! V_48 || ! V_56 )
return - V_11 ;
if ( V_13 ) {
V_54 -> V_2 = F_28 ( V_13 ) ;
if ( ! V_54 -> V_2 )
return - V_57 ;
V_54 -> V_30 = F_5 ( V_54 -> V_2 ,
V_48 ) ;
if ( V_54 -> V_30 < 0 )
return V_54 -> V_30 ;
V_54 -> V_58 = V_56 ;
F_17 ( & V_54 -> V_2 -> V_41 , V_40 ) ;
V_26 = F_34 (
& V_54 -> V_2 -> V_44 [ V_54 -> V_30 ] ,
V_54 -> V_58 ) ;
F_18 ( & V_54 -> V_2 -> V_41 , V_40 ) ;
} else {
struct V_59 V_60 ;
struct V_1 * V_61 ;
struct V_19 * V_20 ;
if ( ! V_62 )
return - V_57 ;
F_35 ( & V_60 , V_62 , NULL , NULL ) ;
while ( ( V_20 = F_36 ( & V_60 ) ) ) {
V_61 = F_8 ( V_20 ) ;
if ( F_5 ( V_61 , V_48 ) < 0 )
continue;
F_37 ( & V_60 ) ;
return F_33 ( V_54 , V_61 -> V_12 ,
V_48 , V_56 ) ;
}
V_26 = - V_57 ;
}
return V_26 ;
}
int F_38 ( struct V_53 * V_54 )
{
unsigned long V_40 ;
int V_26 ;
if ( ! V_54 )
return - V_11 ;
F_17 ( & V_54 -> V_2 -> V_41 , V_40 ) ;
V_26 = F_39 (
& V_54 -> V_2 -> V_44 [ V_54 -> V_30 ] , V_54 -> V_58 ) ;
F_18 ( & V_54 -> V_2 -> V_41 , V_40 ) ;
return V_26 ;
}
int F_40 ( struct V_1 * V_2 , unsigned int V_8 ,
struct V_55 * V_56 )
{
unsigned long V_40 ;
int V_26 , V_17 ;
if ( ! V_2 || ! V_56 )
return - V_11 ;
V_17 = F_3 ( V_2 , V_8 ) ;
F_17 ( & V_2 -> V_41 , V_40 ) ;
V_26 = F_34 ( & V_2 -> V_44 [ V_17 ] , V_56 ) ;
F_18 ( & V_2 -> V_41 , V_40 ) ;
return V_26 ;
}
int F_41 ( struct V_1 * V_2 , unsigned int V_8 ,
struct V_55 * V_56 )
{
unsigned long V_40 ;
int V_26 , V_17 ;
if ( ! V_2 || ! V_56 )
return - V_11 ;
V_17 = F_3 ( V_2 , V_8 ) ;
F_17 ( & V_2 -> V_41 , V_40 ) ;
V_26 = F_39 ( & V_2 -> V_44 [ V_17 ] , V_56 ) ;
F_18 ( & V_2 -> V_41 , V_40 ) ;
return V_26 ;
}
static int F_42 ( void )
{
if ( ! V_62 ) {
V_62 = F_43 ( V_63 , L_9 ) ;
if ( F_44 ( V_62 ) )
return F_45 ( V_62 ) ;
V_62 -> V_64 = V_65 ;
#if F_46 ( V_66 )
V_67 = F_47 ( L_10 ) ;
if ( F_48 ( ! V_67 , L_11 ) )
return - V_68 ;
#endif
}
return 0 ;
}
static void F_49 ( struct V_19 * V_20 )
{
}
static void F_50 ( struct V_19 * V_20 )
{
}
struct V_1 * F_51 ( const unsigned int * V_10 )
{
struct V_1 * V_2 ;
if ( ! V_10 )
return F_29 ( - V_11 ) ;
V_2 = F_52 ( sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
return F_29 ( - V_68 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = V_10 ;
return V_2 ;
}
void F_53 ( struct V_1 * V_2 )
{
F_54 ( V_2 ) ;
}
static int F_55 ( struct V_19 * V_20 , void * V_70 , void * V_71 )
{
struct V_1 * * V_72 = V_70 ;
if ( F_56 ( ! V_72 || ! * V_72 ) )
return 0 ;
return * V_72 == V_71 ;
}
static void F_57 ( struct V_19 * V_20 , void * V_70 )
{
F_53 ( * (struct V_1 * * ) V_70 ) ;
}
struct V_1 * F_58 ( struct V_19 * V_20 ,
const unsigned int * V_10 )
{
struct V_1 * * V_73 , * V_2 ;
V_73 = F_59 ( F_57 , sizeof( * V_73 ) , V_69 ) ;
if ( ! V_73 )
return F_29 ( - V_68 ) ;
V_2 = F_51 ( V_10 ) ;
if ( F_44 ( V_2 ) ) {
F_60 ( V_73 ) ;
return V_2 ;
}
V_2 -> V_20 . V_74 = V_20 ;
* V_73 = V_2 ;
F_61 ( V_20 , V_73 ) ;
return V_2 ;
}
void F_62 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
F_56 ( F_63 ( V_20 , F_57 ,
F_55 , V_2 ) ) ;
}
int F_64 ( struct V_1 * V_2 )
{
int V_26 , V_39 = 0 ;
static T_4 V_75 = F_65 ( - 1 ) ;
if ( ! V_62 ) {
V_26 = F_42 () ;
if ( V_26 < 0 )
return V_26 ;
}
if ( ! V_2 || ! V_2 -> V_10 )
return - V_11 ;
for (; V_2 -> V_10 [ V_39 ] != V_76 ; V_39 ++ ) ;
V_2 -> V_9 = V_39 ;
if ( V_39 > V_77 ) {
F_23 ( & V_2 -> V_20 ,
L_12 ) ;
return - V_11 ;
}
V_2 -> V_20 . V_78 = V_62 ;
V_2 -> V_20 . V_79 = F_49 ;
V_2 -> V_12 = F_66 ( V_2 -> V_20 . V_74 ) ;
if ( F_67 ( V_2 -> V_12 ) ) {
F_23 ( & V_2 -> V_20 ,
L_13 ) ;
return - V_11 ;
}
F_68 ( & V_2 -> V_20 , L_14 ,
( unsigned long ) F_69 ( & V_75 ) ) ;
if ( V_2 -> V_9 ) {
char V_23 [ 10 ] ;
char * V_80 ;
struct V_27 * V_28 ;
V_2 -> V_81 = F_52 ( sizeof( struct V_27 ) *
V_2 -> V_9 , V_69 ) ;
if ( ! V_2 -> V_81 ) {
V_26 = - V_68 ;
goto V_82;
}
for ( V_39 = 0 ; V_39 < V_2 -> V_9 ; V_39 ++ ) {
V_28 = & V_2 -> V_81 [ V_39 ] ;
snprintf ( V_23 , 10 , L_15 , V_39 ) ;
V_80 = F_52 ( sizeof( char ) * ( strlen ( V_23 ) + 1 ) ,
V_69 ) ;
if ( ! V_80 ) {
for ( V_39 -- ; V_39 >= 0 ; V_39 -- ) {
V_28 = & V_2 -> V_81 [ V_39 ] ;
F_54 ( V_28 -> V_83 . V_12 ) ;
}
V_26 = - V_68 ;
goto V_84;
}
strcpy ( V_80 , V_23 ) ;
V_28 -> V_2 = V_2 ;
V_28 -> V_30 = V_39 ;
V_28 -> V_85 [ 0 ] = & V_28 -> V_29 . V_22 ;
V_28 -> V_85 [ 1 ] = & V_28 -> V_31 . V_22 ;
V_28 -> V_85 [ 2 ] = NULL ;
V_28 -> V_83 . V_12 = V_80 ;
V_28 -> V_83 . V_85 = V_28 -> V_85 ;
F_70 ( & V_28 -> V_29 . V_22 ) ;
V_28 -> V_29 . V_22 . V_12 = L_16 ;
V_28 -> V_29 . V_22 . V_86 = 0444 ;
V_28 -> V_29 . V_87 = F_12 ;
F_70 ( & V_28 -> V_31 . V_22 ) ;
V_28 -> V_31 . V_22 . V_12 = L_17 ;
V_28 -> V_31 . V_22 . V_86 = 0444 ;
V_28 -> V_31 . V_87 = F_14 ;
}
}
if ( V_2 -> V_9 && V_2 -> V_5 ) {
char V_23 [ 80 ] ;
char * V_12 ;
for ( V_39 = 0 ; V_2 -> V_5 [ V_39 ] ; V_39 ++ )
;
V_2 -> V_88 = F_52 ( sizeof( struct V_89 * ) *
( V_39 + 1 ) , V_69 ) ;
if ( ! V_2 -> V_88 ) {
V_26 = - V_68 ;
goto V_90;
}
V_2 -> V_91 = F_52 ( sizeof( struct V_21 ) *
V_39 , V_69 ) ;
if ( ! V_2 -> V_91 ) {
V_26 = - V_68 ;
F_54 ( V_2 -> V_88 ) ;
goto V_90;
}
for ( V_39 = 0 ; V_2 -> V_5 [ V_39 ] ; V_39 ++ ) {
sprintf ( V_23 , L_3 , V_2 -> V_5 [ V_39 ] ) ;
V_12 = F_52 ( sizeof( char ) * ( strlen ( V_23 ) + 1 ) ,
V_69 ) ;
if ( ! V_12 ) {
for ( V_39 -- ; V_39 >= 0 ; V_39 -- ) {
F_54 ( V_2 -> V_91 [ V_39 ] . V_22 .
V_12 ) ;
}
F_54 ( V_2 -> V_91 ) ;
F_54 ( V_2 -> V_88 ) ;
V_26 = - V_68 ;
goto V_90;
}
strcpy ( V_12 , V_23 ) ;
F_70 ( & V_2 -> V_91 [ V_39 ] . V_22 ) ;
V_2 -> V_91 [ V_39 ] . V_22 . V_12 = V_12 ;
V_2 -> V_91 [ V_39 ] . V_22 . V_86 = 0000 ;
V_2 -> V_88 [ V_39 ] = & V_2 -> V_91 [ V_39 ]
. V_22 ;
}
V_2 -> V_92 . V_12 = V_93 ;
V_2 -> V_92 . V_85 = V_2 -> V_88 ;
}
if ( V_2 -> V_9 ) {
V_2 -> V_94 . V_95 =
F_52 ( sizeof( struct V_96 * ) *
( V_2 -> V_9 + 2 ) , V_69 ) ;
if ( ! V_2 -> V_94 . V_95 ) {
V_26 = - V_68 ;
goto V_97;
}
V_2 -> V_94 . V_12 = F_66 ( & V_2 -> V_20 ) ;
V_2 -> V_94 . V_79 = F_50 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_9 ; V_39 ++ )
V_2 -> V_94 . V_95 [ V_39 ] =
& V_2 -> V_81 [ V_39 ] . V_83 ;
if ( V_2 -> V_5 )
V_2 -> V_94 . V_95 [ V_39 ] =
& V_2 -> V_92 ;
V_2 -> V_20 . type = & V_2 -> V_94 ;
}
V_26 = F_71 ( & V_2 -> V_20 ) ;
if ( V_26 ) {
F_72 ( & V_2 -> V_20 ) ;
goto V_98;
}
#if F_46 ( V_66 )
if ( V_67 )
V_26 = F_73 ( V_67 , & V_2 -> V_20 , NULL ) ;
#endif
F_74 ( & V_2 -> V_41 ) ;
V_2 -> V_44 = F_75 ( & V_2 -> V_20 ,
sizeof( * V_2 -> V_44 ) * V_2 -> V_9 , V_69 ) ;
if ( ! V_2 -> V_44 ) {
V_26 = - V_68 ;
goto V_98;
}
for ( V_39 = 0 ; V_39 < V_2 -> V_9 ; V_39 ++ )
F_76 ( & V_2 -> V_44 [ V_39 ] ) ;
F_77 ( & V_2 -> V_20 , V_2 ) ;
V_2 -> V_25 = 0 ;
F_30 ( & V_51 ) ;
F_78 ( & V_2 -> V_99 , & V_100 ) ;
F_32 ( & V_51 ) ;
return 0 ;
V_98:
if ( V_2 -> V_9 )
F_54 ( V_2 -> V_94 . V_95 ) ;
V_97:
if ( V_2 -> V_9 && V_2 -> V_5 ) {
for ( V_39 = 0 ; V_2 -> V_5 [ V_39 ] ; V_39 ++ )
F_54 ( V_2 -> V_91 [ V_39 ] . V_22 . V_12 ) ;
F_54 ( V_2 -> V_91 ) ;
F_54 ( V_2 -> V_88 ) ;
}
V_90:
for ( V_39 = 0 ; V_39 < V_2 -> V_9 ; V_39 ++ )
F_54 ( V_2 -> V_81 [ V_39 ] . V_83 . V_12 ) ;
V_84:
if ( V_2 -> V_9 )
F_54 ( V_2 -> V_81 ) ;
V_82:
return V_26 ;
}
void F_79 ( struct V_1 * V_2 )
{
int V_39 ;
if ( ! V_2 )
return;
F_30 ( & V_51 ) ;
F_80 ( & V_2 -> V_99 ) ;
F_32 ( & V_51 ) ;
if ( F_67 ( F_81 ( & V_2 -> V_20 ) ) ) {
F_23 ( & V_2 -> V_20 , L_18 ,
F_66 ( & V_2 -> V_20 ) ) ;
return;
}
F_82 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_5 && V_2 -> V_9 ) {
for ( V_39 = 0 ; V_2 -> V_5 [ V_39 ] ;
V_39 ++ )
F_54 ( V_2 -> V_91 [ V_39 ] . V_22 . V_12 ) ;
F_54 ( V_2 -> V_91 ) ;
F_54 ( V_2 -> V_88 ) ;
}
for ( V_39 = 0 ; V_39 < V_2 -> V_9 ; V_39 ++ )
F_54 ( V_2 -> V_81 [ V_39 ] . V_83 . V_12 ) ;
if ( V_2 -> V_9 ) {
F_54 ( V_2 -> V_94 . V_95 ) ;
F_54 ( V_2 -> V_81 ) ;
}
#if F_46 ( V_66 )
if ( V_67 )
F_83 ( V_67 , & V_2 -> V_20 , NULL ) ;
#endif
F_72 ( & V_2 -> V_20 ) ;
}
static void F_84 ( struct V_19 * V_20 , void * V_70 )
{
F_79 ( * (struct V_1 * * ) V_70 ) ;
}
int F_85 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_1 * * V_73 ;
int V_26 ;
V_73 = F_59 ( F_84 , sizeof( * V_73 ) , V_69 ) ;
if ( ! V_73 )
return - V_68 ;
V_26 = F_64 ( V_2 ) ;
if ( V_26 ) {
F_60 ( V_73 ) ;
return V_26 ;
}
* V_73 = V_2 ;
F_61 ( V_20 , V_73 ) ;
return 0 ;
}
void F_86 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
F_56 ( F_63 ( V_20 , F_84 ,
F_55 , V_2 ) ) ;
}
struct V_1 * F_87 ( struct V_19 * V_20 , int V_39 )
{
struct V_101 * V_102 ;
struct V_1 * V_2 ;
if ( ! V_20 )
return F_29 ( - V_11 ) ;
if ( ! V_20 -> V_103 ) {
F_23 ( V_20 , L_19 ) ;
return F_29 ( - V_11 ) ;
}
V_102 = F_88 ( V_20 -> V_103 , L_9 , V_39 ) ;
if ( ! V_102 ) {
F_23 ( V_20 , L_20 ,
V_20 -> V_103 -> V_104 ) ;
return F_29 ( - V_57 ) ;
}
F_30 ( & V_51 ) ;
F_31 (edev, &extcon_dev_list, entry) {
if ( V_2 -> V_20 . V_74 && V_2 -> V_20 . V_74 -> V_103 == V_102 ) {
F_32 ( & V_51 ) ;
return V_2 ;
}
}
F_32 ( & V_51 ) ;
return F_29 ( - V_105 ) ;
}
struct V_1 * F_87 ( struct V_19 * V_20 , int V_39 )
{
return F_29 ( - V_106 ) ;
}
const char * F_89 ( struct V_1 * V_2 )
{
return ! V_2 ? NULL : V_2 -> V_12 ;
}
static int T_5 F_90 ( void )
{
return F_42 () ;
}
static void T_6 F_91 ( void )
{
#if F_46 ( V_66 )
F_92 ( V_67 ) ;
#endif
F_93 ( V_62 ) ;
}
