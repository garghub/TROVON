static int F_1 ( int V_1 )
{
long V_2 ;
static int V_3 = 10 ;
V_1 = ( V_1 + 59 ) / 60 ;
V_2 = F_2 ( V_4 , 3 , 1 , NULL ,
V_5 , 0 , V_1 ) ;
if ( V_2 < 0 && V_3 ) {
F_3 ( L_1 ,
V_1 , V_2 ) ;
V_3 -- ;
}
return V_2 ;
}
static int F_4 ( int V_6 )
{
long V_2 ;
char V_7 [ V_8 ] ;
F_5 ( & V_9 ) ;
memset ( V_10 , 0 , V_8 ) ;
V_2 = F_2 ( V_11 , 3 , 1 , NULL ,
V_12 , F_6 ( V_10 ) ,
V_8 ) ;
memcpy ( V_7 , V_10 , V_8 ) ;
F_7 ( & V_9 ) ;
if ( V_7 [ 0 ] != 0 || V_7 [ 1 ] != 2 || V_7 [ 3 ] != 0 || V_2 < 0 ) {
F_8 ( L_2 ,
V_2 ) ;
return V_6 ;
}
return ( ( int ) V_7 [ 2 ] ) * 60 ;
}
static void F_9 ( void )
{
F_1 ( V_13 ) ;
}
static void F_10 ( void )
{
F_1 ( 0 ) ;
}
static void F_11 ( void )
{
long V_2 ;
do {
V_2 = F_2 ( V_14 , 4 , 1 , NULL ,
V_15 , 0 ,
( void * ) F_6 ( V_16 ) ,
V_17 ) ;
if ( V_2 < 0 )
F_3 ( L_3 , V_2 ) ;
if ( V_2 == 0 )
F_12 ( V_18 , L_4 ,
V_19 , 16 , 1 ,
V_16 , V_17 , false ) ;
} while ( V_2 == 0 );
}
static int F_13 ( void )
{
int V_2 ;
int V_20 = 0 ;
V_2 = F_14 ( V_21 , 0 , & V_20 ) ;
if ( V_2 < 0 )
F_8 ( L_5 , V_2 ) ;
else
V_20 = ( ( V_20 * 9 ) / 5 ) + 32 ;
return V_20 ;
}
static int F_15 ( void )
{
return 0 ;
}
static int F_16 ( void )
{
return 0 ;
}
static T_1 F_17 ( struct V_22 * V_22 , const char T_2 * V_23 ,
T_3 V_24 , T_4 * V_25 )
{
int V_26 ;
char V_27 ;
if ( ! V_24 )
goto V_28;
if ( ! V_29 ) {
V_30 = 0 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ ) {
if ( F_18 ( V_27 , V_23 + V_26 ) )
return - V_31 ;
if ( V_27 == 'V' )
V_30 = V_32 ;
}
}
F_11 () ;
V_28:
return V_24 ;
}
static long F_19 ( struct V_22 * V_22 , unsigned int V_33 ,
unsigned long V_34 )
{
int T_2 * V_35 = ( void T_2 * ) V_34 ;
int V_26 ;
static const struct V_36 V_37 = {
. V_38 = V_39 ,
. V_40 = 0 ,
. V_41 = L_6 ,
} ;
switch ( V_33 ) {
case V_42 :
if ( F_20 ( V_35 , & V_37 , sizeof( V_37 ) ) )
return - V_31 ;
return 0 ;
case V_43 :
V_26 = F_15 () ;
return F_21 ( V_26 , V_35 ) ;
case V_44 :
V_26 = F_16 () ;
return F_21 ( V_26 , V_35 ) ;
case V_45 :
if ( V_46 == V_47 )
return - V_48 ;
V_26 = F_13 () ;
return F_21 ( V_26 , V_35 ) ;
case V_49 :
if ( F_18 ( V_26 , V_35 ) )
return - V_31 ;
if ( V_26 & V_50 )
F_10 () ;
if ( V_26 & V_51 ) {
F_11 () ;
F_9 () ;
}
return 0 ;
case V_52 :
F_11 () ;
return 0 ;
case V_53 :
if ( F_18 ( V_26 , V_35 ) )
return - V_31 ;
if ( F_1 ( V_26 ) )
return - V_54 ;
F_11 () ;
if ( V_11 == V_47 )
V_13 = V_26 ;
else
V_13 = F_4 ( V_26 ) ;
case V_55 :
return F_21 ( V_13 , V_35 ) ;
default:
return - V_56 ;
}
}
static int F_22 ( struct V_57 * V_57 , struct V_22 * V_22 )
{
if ( F_23 ( & V_58 ) > 1 ) {
F_24 ( & V_58 ) ;
return - V_59 ;
}
F_9 () ;
F_11 () ;
return F_25 ( V_57 , V_22 ) ;
}
static int F_26 ( struct V_57 * V_57 , struct V_22 * V_22 )
{
if ( V_30 == V_32 )
F_10 () ;
else {
F_8 ( L_7 ) ;
F_11 () ;
}
V_30 = 0 ;
F_24 ( & V_58 ) ;
return 0 ;
}
static T_1 F_27 ( struct V_22 * V_22 , char T_2 * V_23 ,
T_3 V_60 , T_4 * V_25 )
{
int V_20 = 0 ;
V_20 = F_13 () ;
if ( V_20 < 0 )
return V_20 ;
if ( F_20 ( V_23 , & V_20 , 1 ) )
return - V_31 ;
return 1 ;
}
static int F_28 ( struct V_57 * V_57 , struct V_22 * V_22 )
{
return F_25 ( V_57 , V_22 ) ;
}
static int F_29 ( struct V_57 * V_57 , struct V_22 * V_22 )
{
return 0 ;
}
static int F_30 ( struct V_61 * V_62 ,
unsigned long V_63 , void * V_64 )
{
if ( V_63 == V_65 || V_63 == V_66 )
F_10 () ;
return V_67 ;
}
static int F_31 ( void )
{
V_46 = F_32 ( L_8 ) ;
if ( V_46 == V_47 ) {
F_8 ( L_9 ) ;
}
V_11 = F_32 ( L_10 ) ;
if ( V_11 == V_47 ) {
F_8 ( L_11 ,
V_68 ) ;
}
V_4 = F_32 ( L_12 ) ;
if ( V_4 == V_47 ) {
F_3 ( L_13 ) ;
return - V_69 ;
}
V_14 = F_32 ( L_14 ) ;
if ( V_14 == V_47 ) {
F_3 ( L_15 ) ;
return - V_69 ;
}
return 0 ;
}
static void F_33 ( void )
{
F_34 ( & V_70 ) ;
if ( V_46 != V_47 )
F_34 ( & V_71 ) ;
}
static int F_35 ( void )
{
int V_2 ;
V_2 = F_36 ( & V_70 ) ;
if ( V_2 ) {
F_3 ( L_16 ) ;
return V_2 ;
}
if ( V_46 != V_47 ) {
V_2 = F_36 ( & V_71 ) ;
if ( V_2 ) {
F_8 ( L_17 ) ;
V_46 = V_47 ;
}
}
return 0 ;
}
static int T_5 F_37 ( void )
{
if ( F_31 () )
return - V_72 ;
if ( F_35 () )
return - V_72 ;
if ( F_38 ( & V_73 ) ) {
F_3 ( L_18 ) ;
F_33 () ;
return - V_72 ;
}
if ( V_11 == V_47 )
V_13 = V_68 ;
else
V_13 = F_4 ( V_68 ) ;
return 0 ;
}
static void T_6 F_39 ( void )
{
if ( ! V_29 )
F_10 () ;
F_33 () ;
F_40 ( & V_73 ) ;
}
