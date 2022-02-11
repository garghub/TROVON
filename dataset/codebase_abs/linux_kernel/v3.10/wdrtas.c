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
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 += 16 )
F_12 ( L_3
L_4
L_5 ,
( V_14 / 16 ) + 1 , ( V_15 / 16 ) ,
V_16 [ V_14 + 0 ] , V_16 [ V_14 + 1 ] ,
V_16 [ V_14 + 2 ] , V_16 [ V_14 + 3 ] ,
V_16 [ V_14 + 4 ] , V_16 [ V_14 + 5 ] ,
V_16 [ V_14 + 6 ] , V_16 [ V_14 + 7 ] ,
V_16 [ V_14 + 8 ] , V_16 [ V_14 + 9 ] ,
V_16 [ V_14 + 10 ] , V_16 [ V_14 + 11 ] ,
V_16 [ V_14 + 12 ] , V_16 [ V_14 + 13 ] ,
V_16 [ V_14 + 14 ] , V_16 [ V_14 + 15 ] ) ;
}
static void F_13 ( void )
{
long V_2 ;
do {
V_2 = F_2 ( V_17 , 4 , 1 , NULL ,
V_18 , 0 ,
( void * ) F_6 ( V_16 ) ,
V_15 ) ;
if ( V_2 < 0 )
F_3 ( L_6 , V_2 ) ;
if ( V_2 == 0 )
F_11 () ;
} while ( V_2 == 0 );
}
static int F_14 ( void )
{
int V_2 ;
int V_19 = 0 ;
V_2 = F_15 ( V_20 , 0 , & V_19 ) ;
if ( V_2 < 0 )
F_8 ( L_7 , V_2 ) ;
else
V_19 = ( ( V_19 * 9 ) / 5 ) + 32 ;
return V_19 ;
}
static int F_16 ( void )
{
return 0 ;
}
static int F_17 ( void )
{
return 0 ;
}
static T_1 F_18 ( struct V_21 * V_21 , const char T_2 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
int V_14 ;
char V_25 ;
if ( ! V_23 )
goto V_26;
if ( ! V_27 ) {
V_28 = 0 ;
for ( V_14 = 0 ; V_14 < V_23 ; V_14 ++ ) {
if ( F_19 ( V_25 , V_22 + V_14 ) )
return - V_29 ;
if ( V_25 == 'V' )
V_28 = V_30 ;
}
}
F_13 () ;
V_26:
return V_23 ;
}
static long F_20 ( struct V_21 * V_21 , unsigned int V_31 ,
unsigned long V_32 )
{
int T_2 * V_33 = ( void T_2 * ) V_32 ;
int V_14 ;
static const struct V_34 V_35 = {
. V_36 = V_37 ,
. V_38 = 0 ,
. V_39 = L_8 ,
} ;
switch ( V_31 ) {
case V_40 :
if ( F_21 ( V_33 , & V_35 , sizeof( V_35 ) ) )
return - V_29 ;
return 0 ;
case V_41 :
V_14 = F_16 () ;
return F_22 ( V_14 , V_33 ) ;
case V_42 :
V_14 = F_17 () ;
return F_22 ( V_14 , V_33 ) ;
case V_43 :
if ( V_44 == V_45 )
return - V_46 ;
V_14 = F_14 () ;
return F_22 ( V_14 , V_33 ) ;
case V_47 :
if ( F_19 ( V_14 , V_33 ) )
return - V_29 ;
if ( V_14 & V_48 )
F_10 () ;
if ( V_14 & V_49 ) {
F_13 () ;
F_9 () ;
}
return 0 ;
case V_50 :
F_13 () ;
return 0 ;
case V_51 :
if ( F_19 ( V_14 , V_33 ) )
return - V_29 ;
if ( F_1 ( V_14 ) )
return - V_52 ;
F_13 () ;
if ( V_11 == V_45 )
V_13 = V_14 ;
else
V_13 = F_4 ( V_14 ) ;
case V_53 :
return F_22 ( V_13 , V_33 ) ;
default:
return - V_54 ;
}
}
static int F_23 ( struct V_55 * V_55 , struct V_21 * V_21 )
{
if ( F_24 ( & V_56 ) > 1 ) {
F_25 ( & V_56 ) ;
return - V_57 ;
}
F_9 () ;
F_13 () ;
return F_26 ( V_55 , V_21 ) ;
}
static int F_27 ( struct V_55 * V_55 , struct V_21 * V_21 )
{
if ( V_28 == V_30 )
F_10 () ;
else {
F_8 ( L_9 ) ;
F_13 () ;
}
V_28 = 0 ;
F_25 ( & V_56 ) ;
return 0 ;
}
static T_1 F_28 ( struct V_21 * V_21 , char T_2 * V_22 ,
T_3 V_58 , T_4 * V_24 )
{
int V_19 = 0 ;
V_19 = F_14 () ;
if ( V_19 < 0 )
return V_19 ;
if ( F_21 ( V_22 , & V_19 , 1 ) )
return - V_29 ;
return 1 ;
}
static int F_29 ( struct V_55 * V_55 , struct V_21 * V_21 )
{
return F_26 ( V_55 , V_21 ) ;
}
static int F_30 ( struct V_55 * V_55 , struct V_21 * V_21 )
{
return 0 ;
}
static int F_31 ( struct V_59 * V_60 ,
unsigned long V_61 , void * V_62 )
{
if ( V_61 == V_63 || V_61 == V_64 )
F_10 () ;
return V_65 ;
}
static int F_32 ( void )
{
V_44 = F_33 ( L_10 ) ;
if ( V_44 == V_45 ) {
F_8 ( L_11 ) ;
}
V_11 = F_33 ( L_12 ) ;
if ( V_11 == V_45 ) {
F_8 ( L_13 ,
V_66 ) ;
}
V_4 = F_33 ( L_14 ) ;
if ( V_4 == V_45 ) {
F_3 ( L_15 ) ;
return - V_67 ;
}
V_17 = F_33 ( L_16 ) ;
if ( V_17 == V_45 ) {
F_3 ( L_17 ) ;
return - V_67 ;
}
return 0 ;
}
static void F_34 ( void )
{
F_35 ( & V_68 ) ;
if ( V_44 != V_45 )
F_35 ( & V_69 ) ;
}
static int F_36 ( void )
{
int V_2 ;
V_2 = F_37 ( & V_68 ) ;
if ( V_2 ) {
F_3 ( L_18 ) ;
return V_2 ;
}
if ( V_44 != V_45 ) {
V_2 = F_37 ( & V_69 ) ;
if ( V_2 ) {
F_8 ( L_19 ) ;
V_44 = V_45 ;
}
}
return 0 ;
}
static int T_5 F_38 ( void )
{
if ( F_32 () )
return - V_70 ;
if ( F_36 () )
return - V_70 ;
if ( F_39 ( & V_71 ) ) {
F_3 ( L_20 ) ;
F_34 () ;
return - V_70 ;
}
if ( V_11 == V_45 )
V_13 = V_66 ;
else
V_13 = F_4 ( V_66 ) ;
return 0 ;
}
static void T_6 F_40 ( void )
{
if ( ! V_27 )
F_10 () ;
F_34 () ;
F_41 ( & V_71 ) ;
}
