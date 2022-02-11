static int F_1 ( int V_1 )
{
long V_2 ;
static int V_3 = 10 ;
V_1 = ( V_1 + 59 ) / 60 ;
V_2 = F_2 ( V_4 , 3 , 1 , NULL ,
V_5 , 0 , V_1 ) ;
if ( V_2 < 0 && V_3 ) {
F_3 ( V_6 L_1
L_2 , V_1 , V_2 ) ;
V_3 -- ;
}
return V_2 ;
}
static int F_4 ( int V_7 )
{
long V_2 ;
char V_8 [ V_9 ] ;
F_5 ( & V_10 ) ;
memset ( V_11 , 0 , V_9 ) ;
V_2 = F_2 ( V_12 , 3 , 1 , NULL ,
V_13 , F_6 ( V_11 ) ,
V_9 ) ;
memcpy ( V_8 , V_11 , V_9 ) ;
F_7 ( & V_10 ) ;
if ( V_8 [ 0 ] != 0 || V_8 [ 1 ] != 2 || V_8 [ 3 ] != 0 || V_2 < 0 ) {
F_3 ( V_14 L_3
L_4 , V_2 ) ;
return V_7 ;
}
return ( ( int ) V_8 [ 2 ] ) * 60 ;
}
static void F_8 ( void )
{
F_1 ( V_15 ) ;
}
static void F_9 ( void )
{
F_1 ( 0 ) ;
}
static void F_10 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 += 16 )
F_3 ( V_18 L_5
L_6
L_7 ,
( V_16 / 16 ) + 1 , ( V_17 / 16 ) ,
V_19 [ V_16 + 0 ] , V_19 [ V_16 + 1 ] ,
V_19 [ V_16 + 2 ] , V_19 [ V_16 + 3 ] ,
V_19 [ V_16 + 4 ] , V_19 [ V_16 + 5 ] ,
V_19 [ V_16 + 6 ] , V_19 [ V_16 + 7 ] ,
V_19 [ V_16 + 8 ] , V_19 [ V_16 + 9 ] ,
V_19 [ V_16 + 10 ] , V_19 [ V_16 + 11 ] ,
V_19 [ V_16 + 12 ] , V_19 [ V_16 + 13 ] ,
V_19 [ V_16 + 14 ] , V_19 [ V_16 + 15 ] ) ;
}
static void F_11 ( void )
{
long V_2 ;
do {
V_2 = F_2 ( V_20 , 4 , 1 , NULL ,
V_21 , 0 ,
( void * ) F_6 ( V_19 ) ,
V_17 ) ;
if ( V_2 < 0 )
F_3 ( V_6 L_8 ,
V_2 ) ;
if ( V_2 == 0 )
F_10 () ;
} while ( V_2 == 0 );
}
static int F_12 ( void )
{
int V_2 ;
int V_22 = 0 ;
V_2 = F_13 ( V_23 , 0 , & V_22 ) ;
if ( V_2 < 0 )
F_3 ( V_14 L_9
L_10 , V_2 ) ;
else
V_22 = ( ( V_22 * 9 ) / 5 ) + 32 ;
return V_22 ;
}
static int F_14 ( void )
{
return 0 ;
}
static int F_15 ( void )
{
return 0 ;
}
static T_1 F_16 ( struct V_24 * V_24 , const char T_2 * V_25 ,
T_3 V_26 , T_4 * V_27 )
{
int V_16 ;
char V_28 ;
if ( ! V_26 )
goto V_29;
if ( ! V_30 ) {
V_31 = 0 ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
if ( F_17 ( V_28 , V_25 + V_16 ) )
return - V_32 ;
if ( V_28 == 'V' )
V_31 = V_33 ;
}
}
F_11 () ;
V_29:
return V_26 ;
}
static long F_18 ( struct V_24 * V_24 , unsigned int V_34 ,
unsigned long V_35 )
{
int T_2 * V_36 = ( void T_2 * ) V_35 ;
int V_16 ;
static const struct V_37 V_38 = {
. V_39 = V_40 ,
. V_41 = 0 ,
. V_42 = L_11 ,
} ;
switch ( V_34 ) {
case V_43 :
if ( F_19 ( V_36 , & V_38 , sizeof( V_38 ) ) )
return - V_32 ;
return 0 ;
case V_44 :
V_16 = F_14 () ;
return F_20 ( V_16 , V_36 ) ;
case V_45 :
V_16 = F_15 () ;
return F_20 ( V_16 , V_36 ) ;
case V_46 :
if ( V_47 == V_48 )
return - V_49 ;
V_16 = F_12 () ;
return F_20 ( V_16 , V_36 ) ;
case V_50 :
if ( F_17 ( V_16 , V_36 ) )
return - V_32 ;
if ( V_16 & V_51 )
F_9 () ;
if ( V_16 & V_52 ) {
F_11 () ;
F_8 () ;
}
return 0 ;
case V_53 :
F_11 () ;
return 0 ;
case V_54 :
if ( F_17 ( V_16 , V_36 ) )
return - V_32 ;
if ( F_1 ( V_16 ) )
return - V_55 ;
F_11 () ;
if ( V_12 == V_48 )
V_15 = V_16 ;
else
V_15 = F_4 ( V_16 ) ;
case V_56 :
return F_20 ( V_15 , V_36 ) ;
default:
return - V_57 ;
}
}
static int F_21 ( struct V_58 * V_58 , struct V_24 * V_24 )
{
if ( F_22 ( & V_59 ) > 1 ) {
F_23 ( & V_59 ) ;
return - V_60 ;
}
F_8 () ;
F_11 () ;
return F_24 ( V_58 , V_24 ) ;
}
static int F_25 ( struct V_58 * V_58 , struct V_24 * V_24 )
{
if ( V_31 == V_33 )
F_9 () ;
else {
F_3 ( V_14 L_12
L_13 ) ;
F_11 () ;
}
V_31 = 0 ;
F_23 ( & V_59 ) ;
return 0 ;
}
static T_1 F_26 ( struct V_24 * V_24 , char T_2 * V_25 ,
T_3 V_61 , T_4 * V_27 )
{
int V_22 = 0 ;
V_22 = F_12 () ;
if ( V_22 < 0 )
return V_22 ;
if ( F_19 ( V_25 , & V_22 , 1 ) )
return - V_32 ;
return 1 ;
}
static int F_27 ( struct V_58 * V_58 , struct V_24 * V_24 )
{
return F_24 ( V_58 , V_24 ) ;
}
static int F_28 ( struct V_58 * V_58 , struct V_24 * V_24 )
{
return 0 ;
}
static int F_29 ( struct V_62 * V_63 ,
unsigned long V_64 , void * V_65 )
{
if ( V_64 == V_66 || V_64 == V_67 )
F_9 () ;
return V_68 ;
}
static int F_30 ( void )
{
V_47 = F_31 ( L_14 ) ;
if ( V_47 == V_48 ) {
F_3 ( V_14 L_15
L_16
L_17 ) ;
}
V_12 = F_31 ( L_18 ) ;
if ( V_12 == V_48 ) {
F_3 ( V_14 L_15
L_19
L_20 ,
V_69 ) ;
}
V_4 = F_31 ( L_21 ) ;
if ( V_4 == V_48 ) {
F_3 ( V_6 L_15
L_22 ) ;
return - V_70 ;
}
V_20 = F_31 ( L_23 ) ;
if ( V_20 == V_48 ) {
F_3 ( V_6 L_24
L_25 ) ;
return - V_70 ;
}
return 0 ;
}
static void F_32 ( void )
{
F_33 ( & V_71 ) ;
if ( V_47 != V_48 )
F_33 ( & V_72 ) ;
}
static int F_34 ( void )
{
int V_2 ;
V_2 = F_35 ( & V_71 ) ;
if ( V_2 ) {
F_3 ( V_6 L_26
L_27 ) ;
return V_2 ;
}
if ( V_47 != V_48 ) {
V_2 = F_35 ( & V_72 ) ;
if ( V_2 ) {
F_3 ( V_14 L_28
L_29
L_30 ) ;
V_47 = V_48 ;
}
}
return 0 ;
}
static int T_5 F_36 ( void )
{
if ( F_30 () )
return - V_73 ;
if ( F_34 () )
return - V_73 ;
if ( F_37 ( & V_74 ) ) {
F_3 ( V_6 L_31
L_25 ) ;
F_32 () ;
return - V_73 ;
}
if ( V_12 == V_48 )
V_15 = V_69 ;
else
V_15 = F_4 ( V_69 ) ;
return 0 ;
}
static void T_6 F_38 ( void )
{
if ( ! V_30 )
F_9 () ;
F_32 () ;
F_39 ( & V_74 ) ;
}
