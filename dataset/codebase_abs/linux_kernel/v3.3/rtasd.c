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
}
return V_1 [ 0 ] ;
}
static void F_2 ( char * V_8 , int V_9 )
{
int V_10 , V_11 , V_12 = 0 ;
int V_13 = 16 ;
char V_14 [ 64 ] ;
char * V_15 = L_7 ;
if ( V_16 ) {
F_3 ( V_17 L_8 ,
V_18 , V_15 ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
V_11 = V_10 % V_13 ;
if ( V_11 == 0 ) {
memset ( V_14 , 0 , sizeof( V_14 ) ) ;
V_12 = sprintf ( V_14 , L_9 , V_10 / V_13 ) ;
}
if ( ( V_10 % 4 ) == 0 )
V_12 += sprintf ( V_14 + V_12 , L_10 ) ;
V_12 += sprintf ( V_14 + V_12 , L_11 , ( unsigned char ) V_8 [ V_10 ] ) ;
if ( V_11 == ( V_13 - 1 ) )
F_3 ( V_19 L_12 , V_14 ) ;
}
if ( ( V_10 % V_13 ) != 0 )
F_3 ( V_19 L_12 , V_14 ) ;
F_3 ( V_17 L_13 ,
V_18 , V_15 ) ;
} else {
struct V_20 * V_21 = (struct V_20 * ) V_8 ;
F_3 ( V_17 L_14 ,
V_18 , F_1 ( V_21 -> type ) ,
V_21 -> V_22 ) ;
}
}
static int F_4 ( char * V_8 )
{
int V_9 ;
struct V_20 * V_23 ;
V_9 = 8 ;
V_23 = (struct V_20 * ) V_8 ;
if ( V_23 -> V_24 && V_23 -> V_25 ) {
V_9 += V_23 -> V_25 ;
}
if ( V_26 == 0 )
V_26 = F_5 () ;
if ( V_9 > V_26 )
V_9 = V_26 ;
return V_9 ;
}
void F_6 ( char * V_8 , unsigned int V_27 , int V_28 )
{
unsigned long V_29 ;
unsigned long V_30 ;
int V_9 = 0 ;
F_7 ( L_15 ) ;
if ( V_8 == NULL )
return;
F_8 ( & V_31 , V_30 ) ;
switch ( V_27 & V_32 ) {
case V_33 :
V_9 = F_4 ( V_8 ) ;
if ( ! ( V_27 & V_34 ) )
V_18 ++ ;
break;
case V_35 :
default:
F_9 ( ! F_10 () ) ;
F_11 ( & V_31 , V_30 ) ;
return;
}
#ifdef F_12
if ( V_36 && ! ( V_27 & V_34 ) )
F_13 ( V_8 , V_9 , V_27 , V_18 ) ;
#endif
if ( ( V_27 & V_32 ) == V_33 )
F_2 ( V_8 , V_9 ) ;
if ( V_28 || ! V_36 ) {
V_36 = 0 ;
F_9 ( ! F_10 () ) ;
F_11 ( & V_31 , V_30 ) ;
return;
}
switch ( V_27 & V_32 ) {
case V_33 :
V_29 = V_37 *
( ( V_38 + V_39 ) & V_40 ) ;
memcpy ( & V_41 [ V_29 ] , ( void * ) & V_18 , sizeof( int ) ) ;
V_29 += sizeof( int ) ;
memcpy ( & V_41 [ V_29 ] , V_8 , V_9 ) ;
if ( V_39 < V_42 )
V_39 += 1 ;
else
V_38 += 1 ;
F_9 ( ! F_10 () ) ;
F_11 ( & V_31 , V_30 ) ;
F_14 ( & V_43 ) ;
break;
case V_35 :
default:
F_9 ( ! F_10 () ) ;
F_11 ( & V_31 , V_30 ) ;
return;
}
}
static int F_15 ( struct V_44 * V_44 , struct V_45 * V_45 )
{
return 0 ;
}
static int F_16 ( struct V_44 * V_44 , struct V_45 * V_45 )
{
return 0 ;
}
static T_1 F_17 ( struct V_45 * V_45 , char T_2 * V_8 ,
T_3 V_46 , T_4 * V_47 )
{
int error ;
char * V_48 ;
unsigned long V_30 ;
unsigned long V_29 ;
if ( ! V_8 || V_46 < V_37 )
return - V_49 ;
V_46 = V_37 ;
if ( ! F_18 ( V_50 , V_8 , V_46 ) )
return - V_51 ;
V_48 = F_19 ( V_46 , V_52 ) ;
if ( ! V_48 )
return - V_53 ;
F_8 ( & V_31 , V_30 ) ;
while ( V_39 == 0 ) {
if ( V_45 -> V_54 & V_55 ) {
F_11 ( & V_31 , V_30 ) ;
error = - V_56 ;
goto V_57;
}
if ( ! V_36 ) {
F_11 ( & V_31 , V_30 ) ;
error = - V_58 ;
goto V_57;
}
#ifdef F_12
F_20 () ;
#endif
F_11 ( & V_31 , V_30 ) ;
error = F_21 ( V_43 , V_39 ) ;
if ( error )
goto V_57;
F_8 ( & V_31 , V_30 ) ;
}
V_29 = V_37 * ( V_38 & V_40 ) ;
memcpy ( V_48 , & V_41 [ V_29 ] , V_46 ) ;
V_38 += 1 ;
V_39 -= 1 ;
F_11 ( & V_31 , V_30 ) ;
error = F_22 ( V_8 , V_48 , V_46 ) ? - V_51 : V_46 ;
V_57:
F_23 ( V_48 ) ;
return error ;
}
static unsigned int F_24 ( struct V_45 * V_45 , T_5 * V_59 )
{
F_25 ( V_45 , & V_43 , V_59 ) ;
if ( V_39 )
return V_60 | V_61 ;
return 0 ;
}
static int F_26 ( int V_62 )
{
int error ;
error = F_27 ( V_63 , 0 , V_62 ) ;
if ( error == 0 )
return 0 ;
if ( error == - V_49 ) {
F_3 ( V_19 L_16 ) ;
return 0 ;
}
F_3 ( V_64 L_17 ) ;
return - 1 ;
}
static void F_28 ( void )
{
int error ;
do {
memset ( V_65 , 0 , V_26 ) ;
error = F_29 ( V_66 , 4 , 1 , NULL ,
V_67 , 0 ,
F_30 ( V_65 ) , V_26 ) ;
if ( error == - 1 ) {
F_3 ( V_64 L_18 ) ;
break;
}
if ( error == 0 )
F_6 ( V_65 , V_33 , 0 ) ;
} while( error == 0 );
}
static void F_31 ( struct V_68 * V_69 )
{
unsigned int V_70 ;
F_28 () ;
F_32 () ;
V_70 = F_33 ( F_34 () , V_71 ) ;
if ( V_70 >= V_72 ) {
V_70 = F_35 ( V_71 ) ;
if ( V_73 ) {
V_73 = 0 ;
V_74 = 30 * V_75 / V_76 ;
if ( V_77 != - 1 ) {
F_7 ( L_19 ) ;
F_26 ( V_77 ) ;
F_7 ( L_20 ) ;
}
}
}
F_36 ( V_70 , & V_78 ,
F_37 ( V_74 , V_70 ) ) ;
F_38 () ;
}
static void F_39 ( void )
{
unsigned int V_27 ;
int V_79 ;
memset ( V_65 , 0 , V_26 ) ;
V_79 = F_40 ( V_65 , V_26 ,
& V_27 , & V_18 ) ;
V_36 = 1 ;
if ( ! V_79 ) {
if ( V_27 != V_80 ) {
F_6 ( V_65 , V_27 | V_34 , 0 ) ;
}
}
}
static void F_39 ( void )
{
}
static void F_41 ( void )
{
F_3 ( V_19 L_21 ) ;
F_7 ( L_22 ,
( 30000 / V_76 ) ) ;
F_39 () ;
F_36 ( F_35 ( V_71 ) ,
& V_78 , V_74 ) ;
}
void F_42 ( void )
{
F_43 ( & V_78 ) ;
}
static int T_6 F_44 ( void )
{
struct V_81 * V_82 ;
if ( ! F_45 ( V_83 ) && ! F_45 ( V_84 ) )
return 0 ;
V_66 = F_46 ( L_23 ) ;
if ( V_66 == V_85 ) {
F_3 ( V_86 L_24 ) ;
return - V_87 ;
}
V_76 = F_46 ( L_25 ) ;
if ( V_76 == V_85 ) {
F_3 ( V_64 L_26 ) ;
return - V_87 ;
}
if ( ! V_76 ) {
F_3 ( V_19 L_27 ) ;
return 0 ;
}
V_26 = F_5 () ;
V_37 = V_26 + sizeof( int ) ;
V_41 = F_47 ( V_37 * V_42 ) ;
if ( ! V_41 ) {
F_3 ( V_64 L_28 ) ;
return - V_53 ;
}
V_82 = F_48 ( L_29 , V_88 , NULL ,
& V_89 ) ;
if ( ! V_82 )
F_3 ( V_64 L_30 ) ;
F_41 () ;
return 0 ;
}
static int T_6 F_49 ( char * V_15 )
{
int V_10 ;
if ( ! F_45 ( V_83 ) )
return 0 ;
if ( F_50 ( & V_15 , & V_10 ) ) {
if ( V_10 >= 0 && V_10 <= 255 )
V_77 = V_10 ;
}
return 1 ;
}
static int T_6 F_51 ( char * V_15 )
{
if ( strcmp ( V_15 , L_31 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( V_15 , L_32 ) == 0 )
V_16 = 0 ;
return 1 ;
}
