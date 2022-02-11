static char * F_1 ( int type )
{
if ( ( type > 0 ) && ( type < 11 ) )
return V_1 [ type ] ;
switch ( type ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
case V_6 :
return L_5 ;
case V_7 :
return L_6 ;
case V_8 :
return L_7 ;
}
return V_1 [ 0 ] ;
}
static void F_2 ( char * V_9 , int V_10 )
{
int V_11 , V_12 , V_13 = 0 ;
int V_14 = 16 ;
char V_15 [ 64 ] ;
char * V_16 = L_8 ;
if ( V_17 ) {
F_3 ( V_18 L_9 ,
V_19 , V_16 ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ ) {
V_12 = V_11 % V_14 ;
if ( V_12 == 0 ) {
memset ( V_15 , 0 , sizeof( V_15 ) ) ;
V_13 = sprintf ( V_15 , L_10 , V_11 / V_14 ) ;
}
if ( ( V_11 % 4 ) == 0 )
V_13 += sprintf ( V_15 + V_13 , L_11 ) ;
V_13 += sprintf ( V_15 + V_13 , L_12 , ( unsigned char ) V_9 [ V_11 ] ) ;
if ( V_12 == ( V_14 - 1 ) )
F_3 ( V_20 L_13 , V_15 ) ;
}
if ( ( V_11 % V_14 ) != 0 )
F_3 ( V_20 L_13 , V_15 ) ;
F_3 ( V_18 L_14 ,
V_19 , V_16 ) ;
} else {
struct V_21 * V_22 = (struct V_21 * ) V_9 ;
F_3 ( V_18 L_15 ,
V_19 , F_1 ( F_4 ( V_22 ) ) ,
F_5 ( V_22 ) ) ;
}
}
static int F_6 ( char * V_9 )
{
int V_10 ;
struct V_21 * V_23 ;
T_1 V_24 ;
V_10 = 8 ;
V_23 = (struct V_21 * ) V_9 ;
V_24 = F_7 ( V_23 ) ;
if ( F_8 ( V_23 ) && V_24 ) {
V_10 += V_24 ;
}
if ( V_25 == 0 )
V_25 = F_9 () ;
if ( V_10 > V_25 )
V_10 = V_25 ;
return V_10 ;
}
void F_10 ( char * V_9 , unsigned int V_26 , int V_27 )
{
unsigned long V_28 ;
unsigned long V_29 ;
int V_10 = 0 ;
F_11 ( L_16 ) ;
if ( V_9 == NULL )
return;
F_12 ( & V_30 , V_29 ) ;
switch ( V_26 & V_31 ) {
case V_32 :
V_10 = F_6 ( V_9 ) ;
if ( ! ( V_26 & V_33 ) )
V_19 ++ ;
break;
case V_34 :
default:
F_13 ( ! F_14 () ) ;
F_15 ( & V_30 , V_29 ) ;
return;
}
#ifdef F_16
if ( V_35 && ! ( V_26 & V_33 ) )
F_17 ( V_9 , V_10 , V_26 , V_19 ) ;
#endif
if ( ( V_26 & V_31 ) == V_32 )
F_2 ( V_9 , V_10 ) ;
if ( V_27 || ! V_35 ) {
V_35 = 0 ;
F_13 ( ! F_14 () ) ;
F_15 ( & V_30 , V_29 ) ;
return;
}
switch ( V_26 & V_31 ) {
case V_32 :
V_28 = V_36 *
( ( V_37 + V_38 ) & V_39 ) ;
memcpy ( & V_40 [ V_28 ] , ( void * ) & V_19 , sizeof( int ) ) ;
V_28 += sizeof( int ) ;
memcpy ( & V_40 [ V_28 ] , V_9 , V_10 ) ;
if ( V_38 < V_41 )
V_38 += 1 ;
else
V_37 += 1 ;
F_13 ( ! F_14 () ) ;
F_15 ( & V_30 , V_29 ) ;
F_18 ( & V_42 ) ;
break;
case V_34 :
default:
F_13 ( ! F_14 () ) ;
F_15 ( & V_30 , V_29 ) ;
return;
}
}
static void F_19 ( struct V_43 * V_44 )
{
F_20 ( - V_45 ) ;
}
static void F_21 ( T_2 V_46 )
{
F_22 ( & V_47 ) ;
V_45 = V_46 ;
F_23 ( & V_47 ) ;
}
static void F_24 ( const struct V_21 * log )
{
if ( F_4 ( log ) != V_8 || ! F_25 () )
return;
F_21 ( F_7 ( log ) ) ;
}
static void F_24 ( const struct V_21 * log )
{
return;
}
static int F_26 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return 0 ;
}
static int F_27 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return 0 ;
}
static T_3 F_28 ( struct V_49 * V_49 , char T_4 * V_9 ,
T_5 V_50 , T_6 * V_51 )
{
int error ;
char * V_52 ;
unsigned long V_29 ;
unsigned long V_28 ;
if ( ! V_9 || V_50 < V_36 )
return - V_53 ;
V_50 = V_36 ;
if ( ! F_29 ( V_54 , V_9 , V_50 ) )
return - V_55 ;
V_52 = F_30 ( V_50 , V_56 ) ;
if ( ! V_52 )
return - V_57 ;
F_12 ( & V_30 , V_29 ) ;
while ( V_38 == 0 ) {
if ( V_49 -> V_58 & V_59 ) {
F_15 ( & V_30 , V_29 ) ;
error = - V_60 ;
goto V_61;
}
if ( ! V_35 ) {
F_15 ( & V_30 , V_29 ) ;
error = - V_62 ;
goto V_61;
}
#ifdef F_16
F_31 () ;
#endif
F_15 ( & V_30 , V_29 ) ;
error = F_32 ( V_42 , V_38 ) ;
if ( error )
goto V_61;
F_12 ( & V_30 , V_29 ) ;
}
V_28 = V_36 * ( V_37 & V_39 ) ;
memcpy ( V_52 , & V_40 [ V_28 ] , V_50 ) ;
V_37 += 1 ;
V_38 -= 1 ;
F_15 ( & V_30 , V_29 ) ;
error = F_33 ( V_9 , V_52 , V_50 ) ? - V_55 : V_50 ;
V_61:
F_34 ( V_52 ) ;
return error ;
}
static unsigned int F_35 ( struct V_49 * V_49 , T_7 * V_63 )
{
F_36 ( V_49 , & V_42 , V_63 ) ;
if ( V_38 )
return V_64 | V_65 ;
return 0 ;
}
static int F_37 ( int V_66 )
{
int error ;
error = F_38 ( V_67 , 0 , V_66 ) ;
if ( error == 0 )
return 0 ;
if ( error == - V_53 ) {
F_3 ( V_20 L_17 ) ;
return 0 ;
}
F_3 ( V_68 L_18 ) ;
return - 1 ;
}
static void F_39 ( void )
{
int error ;
do {
memset ( V_69 , 0 , V_25 ) ;
error = F_40 ( V_70 , 4 , 1 , NULL ,
V_71 , 0 ,
F_41 ( V_69 ) , V_25 ) ;
if ( error == - 1 ) {
F_3 ( V_68 L_19 ) ;
break;
}
if ( error == 0 ) {
F_10 ( V_69 , V_32 , 0 ) ;
F_24 ( (struct V_21 * ) V_69 ) ;
}
} while( error == 0 );
}
static void F_42 ( struct V_43 * V_72 )
{
unsigned int V_73 ;
F_39 () ;
F_43 () ;
V_73 = F_44 ( F_45 () , V_74 ) ;
if ( V_73 >= V_75 ) {
V_73 = F_46 ( V_74 ) ;
if ( V_76 ) {
V_76 = 0 ;
V_77 = 30 * V_78 / V_79 ;
if ( V_80 != - 1 ) {
F_11 ( L_20 ) ;
F_37 ( V_80 ) ;
F_11 ( L_21 ) ;
}
}
}
F_47 ( V_73 , & V_81 ,
F_48 ( V_77 , V_73 ) ) ;
F_49 () ;
}
static void F_50 ( void )
{
unsigned int V_26 ;
int V_82 ;
memset ( V_69 , 0 , V_25 ) ;
V_82 = F_51 ( V_69 , V_25 ,
& V_26 , & V_19 ) ;
V_35 = 1 ;
if ( ! V_82 ) {
if ( V_26 != V_83 ) {
F_10 ( V_69 , V_26 | V_33 , 0 ) ;
}
}
}
static void F_50 ( void )
{
}
static void F_52 ( void )
{
F_3 ( V_20 L_22 ) ;
F_11 ( L_23 ,
( 30000 / V_79 ) ) ;
F_50 () ;
F_47 ( F_46 ( V_74 ) ,
& V_81 , V_77 ) ;
}
void F_53 ( void )
{
F_54 ( & V_81 ) ;
}
static int T_8 F_55 ( void )
{
struct V_84 * V_85 ;
if ( ! F_56 ( V_86 ) && ! F_56 ( V_87 ) )
return 0 ;
V_70 = F_57 ( L_24 ) ;
if ( V_70 == V_88 ) {
F_3 ( V_89 L_25 ) ;
return - V_90 ;
}
V_79 = F_57 ( L_26 ) ;
if ( V_79 == V_88 ) {
F_3 ( V_68 L_27 ) ;
return - V_90 ;
}
if ( ! V_79 ) {
F_3 ( V_20 L_28 ) ;
return 0 ;
}
V_25 = F_9 () ;
V_36 = V_25 + sizeof( int ) ;
V_40 = F_58 ( V_36 * V_41 ) ;
if ( ! V_40 ) {
F_3 ( V_68 L_29 ) ;
return - V_57 ;
}
V_85 = F_59 ( L_30 , V_91 , NULL ,
& V_92 ) ;
if ( ! V_85 )
F_3 ( V_68 L_31 ) ;
F_52 () ;
return 0 ;
}
static int T_8 F_60 ( char * V_16 )
{
int V_11 ;
if ( ! F_56 ( V_86 ) )
return 0 ;
if ( F_61 ( & V_16 , & V_11 ) ) {
if ( V_11 >= 0 && V_11 <= 255 )
V_80 = V_11 ;
}
return 1 ;
}
static int T_8 F_62 ( char * V_16 )
{
if ( strcmp ( V_16 , L_32 ) == 0 )
V_17 = 1 ;
else if ( strcmp ( V_16 , L_33 ) == 0 )
V_17 = 0 ;
return 1 ;
}
