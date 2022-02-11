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
V_19 , F_1 ( V_22 -> type ) ,
V_22 -> V_23 ) ;
}
}
static int F_4 ( char * V_9 )
{
int V_10 ;
struct V_21 * V_24 ;
V_10 = 8 ;
V_24 = (struct V_21 * ) V_9 ;
if ( V_24 -> V_25 && V_24 -> V_26 ) {
V_10 += V_24 -> V_26 ;
}
if ( V_27 == 0 )
V_27 = F_5 () ;
if ( V_10 > V_27 )
V_10 = V_27 ;
return V_10 ;
}
void F_6 ( char * V_9 , unsigned int V_28 , int V_29 )
{
unsigned long V_30 ;
unsigned long V_31 ;
int V_10 = 0 ;
F_7 ( L_16 ) ;
if ( V_9 == NULL )
return;
F_8 ( & V_32 , V_31 ) ;
switch ( V_28 & V_33 ) {
case V_34 :
V_10 = F_4 ( V_9 ) ;
if ( ! ( V_28 & V_35 ) )
V_19 ++ ;
break;
case V_36 :
default:
F_9 ( ! F_10 () ) ;
F_11 ( & V_32 , V_31 ) ;
return;
}
#ifdef F_12
if ( V_37 && ! ( V_28 & V_35 ) )
F_13 ( V_9 , V_10 , V_28 , V_19 ) ;
#endif
if ( ( V_28 & V_33 ) == V_34 )
F_2 ( V_9 , V_10 ) ;
if ( V_29 || ! V_37 ) {
V_37 = 0 ;
F_9 ( ! F_10 () ) ;
F_11 ( & V_32 , V_31 ) ;
return;
}
switch ( V_28 & V_33 ) {
case V_34 :
V_30 = V_38 *
( ( V_39 + V_40 ) & V_41 ) ;
memcpy ( & V_42 [ V_30 ] , ( void * ) & V_19 , sizeof( int ) ) ;
V_30 += sizeof( int ) ;
memcpy ( & V_42 [ V_30 ] , V_9 , V_10 ) ;
if ( V_40 < V_43 )
V_40 += 1 ;
else
V_39 += 1 ;
F_9 ( ! F_10 () ) ;
F_11 ( & V_32 , V_31 ) ;
F_14 ( & V_44 ) ;
break;
case V_36 :
default:
F_9 ( ! F_10 () ) ;
F_11 ( & V_32 , V_31 ) ;
return;
}
}
static void F_15 ( struct V_45 * V_46 )
{
F_16 ( - V_47 ) ;
}
void F_17 ( T_1 V_48 )
{
F_18 ( & V_49 ) ;
V_47 = V_48 ;
F_19 ( & V_49 ) ;
}
static void F_20 ( const struct V_21 * log )
{
if ( log -> type == V_8 ) {
if ( F_21 () )
F_17 ( log -> V_26 ) ;
}
return;
}
static void F_20 ( const struct V_21 * log )
{
return;
}
static int F_22 ( struct V_50 * V_50 , struct V_51 * V_51 )
{
return 0 ;
}
static int F_23 ( struct V_50 * V_50 , struct V_51 * V_51 )
{
return 0 ;
}
static T_2 F_24 ( struct V_51 * V_51 , char T_3 * V_9 ,
T_4 V_52 , T_5 * V_53 )
{
int error ;
char * V_54 ;
unsigned long V_31 ;
unsigned long V_30 ;
if ( ! V_9 || V_52 < V_38 )
return - V_55 ;
V_52 = V_38 ;
if ( ! F_25 ( V_56 , V_9 , V_52 ) )
return - V_57 ;
V_54 = F_26 ( V_52 , V_58 ) ;
if ( ! V_54 )
return - V_59 ;
F_8 ( & V_32 , V_31 ) ;
while ( V_40 == 0 ) {
if ( V_51 -> V_60 & V_61 ) {
F_11 ( & V_32 , V_31 ) ;
error = - V_62 ;
goto V_63;
}
if ( ! V_37 ) {
F_11 ( & V_32 , V_31 ) ;
error = - V_64 ;
goto V_63;
}
#ifdef F_12
F_27 () ;
#endif
F_11 ( & V_32 , V_31 ) ;
error = F_28 ( V_44 , V_40 ) ;
if ( error )
goto V_63;
F_8 ( & V_32 , V_31 ) ;
}
V_30 = V_38 * ( V_39 & V_41 ) ;
memcpy ( V_54 , & V_42 [ V_30 ] , V_52 ) ;
V_39 += 1 ;
V_40 -= 1 ;
F_11 ( & V_32 , V_31 ) ;
error = F_29 ( V_9 , V_54 , V_52 ) ? - V_57 : V_52 ;
V_63:
F_30 ( V_54 ) ;
return error ;
}
static unsigned int F_31 ( struct V_51 * V_51 , T_6 * V_65 )
{
F_32 ( V_51 , & V_44 , V_65 ) ;
if ( V_40 )
return V_66 | V_67 ;
return 0 ;
}
static int F_33 ( int V_68 )
{
int error ;
error = F_34 ( V_69 , 0 , V_68 ) ;
if ( error == 0 )
return 0 ;
if ( error == - V_55 ) {
F_3 ( V_20 L_17 ) ;
return 0 ;
}
F_3 ( V_70 L_18 ) ;
return - 1 ;
}
static void F_35 ( void )
{
int error ;
do {
memset ( V_71 , 0 , V_27 ) ;
error = F_36 ( V_72 , 4 , 1 , NULL ,
V_73 , 0 ,
F_37 ( V_71 ) , V_27 ) ;
if ( error == - 1 ) {
F_3 ( V_70 L_19 ) ;
break;
}
if ( error == 0 ) {
F_6 ( V_71 , V_34 , 0 ) ;
F_20 ( (struct V_21 * ) V_71 ) ;
}
} while( error == 0 );
}
static void F_38 ( struct V_45 * V_74 )
{
unsigned int V_75 ;
F_35 () ;
F_39 () ;
V_75 = F_40 ( F_41 () , V_76 ) ;
if ( V_75 >= V_77 ) {
V_75 = F_42 ( V_76 ) ;
if ( V_78 ) {
V_78 = 0 ;
V_79 = 30 * V_80 / V_81 ;
if ( V_82 != - 1 ) {
F_7 ( L_20 ) ;
F_33 ( V_82 ) ;
F_7 ( L_21 ) ;
}
}
}
F_43 ( V_75 , & V_83 ,
F_44 ( V_79 , V_75 ) ) ;
F_45 () ;
}
static void F_46 ( void )
{
unsigned int V_28 ;
int V_84 ;
memset ( V_71 , 0 , V_27 ) ;
V_84 = F_47 ( V_71 , V_27 ,
& V_28 , & V_19 ) ;
V_37 = 1 ;
if ( ! V_84 ) {
if ( V_28 != V_85 ) {
F_6 ( V_71 , V_28 | V_35 , 0 ) ;
}
}
}
static void F_46 ( void )
{
}
static void F_48 ( void )
{
F_3 ( V_20 L_22 ) ;
F_7 ( L_23 ,
( 30000 / V_81 ) ) ;
F_46 () ;
F_43 ( F_42 ( V_76 ) ,
& V_83 , V_79 ) ;
}
void F_49 ( void )
{
F_50 ( & V_83 ) ;
}
static int T_7 F_51 ( void )
{
struct V_86 * V_87 ;
if ( ! F_52 ( V_88 ) && ! F_52 ( V_89 ) )
return 0 ;
V_72 = F_53 ( L_24 ) ;
if ( V_72 == V_90 ) {
F_3 ( V_91 L_25 ) ;
return - V_92 ;
}
V_81 = F_53 ( L_26 ) ;
if ( V_81 == V_90 ) {
F_3 ( V_70 L_27 ) ;
return - V_92 ;
}
if ( ! V_81 ) {
F_3 ( V_20 L_28 ) ;
return 0 ;
}
V_27 = F_5 () ;
V_38 = V_27 + sizeof( int ) ;
V_42 = F_54 ( V_38 * V_43 ) ;
if ( ! V_42 ) {
F_3 ( V_70 L_29 ) ;
return - V_59 ;
}
V_87 = F_55 ( L_30 , V_93 , NULL ,
& V_94 ) ;
if ( ! V_87 )
F_3 ( V_70 L_31 ) ;
F_48 () ;
return 0 ;
}
static int T_7 F_56 ( char * V_16 )
{
int V_11 ;
if ( ! F_52 ( V_88 ) )
return 0 ;
if ( F_57 ( & V_16 , & V_11 ) ) {
if ( V_11 >= 0 && V_11 <= 255 )
V_82 = V_11 ;
}
return 1 ;
}
static int T_7 F_58 ( char * V_16 )
{
if ( strcmp ( V_16 , L_32 ) == 0 )
V_17 = 1 ;
else if ( strcmp ( V_16 , L_33 ) == 0 )
V_17 = 0 ;
return 1 ;
}
