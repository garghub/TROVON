static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ,
F_3 ( V_2 -> V_4 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_5 ,
F_3 ( V_2 -> V_4 ) ) ;
}
static void F_6 ( unsigned int V_4 , struct V_6 * V_7 )
{
T_1 V_8 ;
int V_9 ;
V_7 -> V_1 . V_10 -> V_11 ( & V_7 -> V_1 ) ;
V_8 = * V_12 & V_13 ;
if ( ! V_8 ) {
F_7 ( V_14 L_1 ) ;
return;
}
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ ) {
if ( V_8 & ( 1 << V_9 ) ) {
int V_16 = F_8 ( 0 ) + V_9 ;
F_9 ( V_16 ) ;
}
}
V_7 -> V_1 . V_10 -> V_17 ( & V_7 -> V_1 ) ;
}
void T_2 F_10 ( void )
{
int V_4 = 0 ;
F_11 () ;
if ( F_12 () )
V_13 = V_18 ;
else
V_13 = V_19 ;
F_5 ( V_3 , 0xffffffff ) ;
F_2 ( V_20 , 0 ) ;
for ( V_4 = V_21 ; V_4 < V_22 ; V_4 ++ ) {
if ( V_4 & V_13 ) {
F_13 ( V_4 , & V_23 ,
V_24 ) ;
F_14 ( V_4 , V_25 ) ;
} else {
F_14 ( V_4 , 0 ) ;
}
}
F_15 ( V_26 , F_6 ) ;
}
static void T_2 F_16 ( void )
{
F_17 () ;
F_18 ( & V_27 , 1 ) ;
}
static void F_19 ( void )
{
F_20 ( & V_28 ) ;
F_20 ( & V_29 ) ;
}
static int T_2 F_21 ( char * V_30 )
{
V_31 = F_22 ( V_30 , NULL , 10 ) ;
return 1 ;
}
static void T_2 F_23 ( void )
{
if ( ! V_31 )
V_31 = 50000000 ;
F_24 ( V_31 ) ;
}
void T_2 F_25 ( void )
{
F_5 ( V_32 , 0x00000000 ) ;
F_26 () ;
F_27 ( L_2 ) ;
}
static int T_2 F_28 ( const struct V_33 * V_34 , T_3 V_35 ,
T_3 V_36 )
{
T_3 V_37 = V_34 -> V_37 -> V_38 ;
T_1 V_39 = F_29 ( F_30 ( V_34 -> V_40 ) , V_36 ) ;
struct V_41 * V_42 = V_34 -> V_37 ;
if ( V_37 == 0 ) {
return - 1 ;
}
while ( ( V_42 -> V_43 != NULL ) && ( V_42 -> V_43 -> V_43 != NULL ) ) {
V_42 = V_42 -> V_43 ;
}
switch ( V_42 -> V_44 -> V_40 | ( V_42 -> V_44 -> V_37 -> V_38 << 8 ) ) {
case 0x0008 :
if ( V_42 == V_34 -> V_37 ) {
switch ( V_39 ) {
case F_29 ( 1 , 1 ) :
if ( F_12 () )
return V_45 ;
return - 1 ;
case F_29 ( 1 , 2 ) :
if ( F_12 () )
return V_46 ;
return - 1 ;
case F_29 ( 0 , 1 ) :
return V_47 ;
case F_29 ( 0 , 2 ) :
return V_48 ;
case F_29 ( 0 , 3 ) :
return V_49 ;
case F_29 ( 0 , 4 ) :
return V_50 ;
}
}
break;
case 0x0010 :
if ( V_42 == V_34 -> V_37 ) {
switch ( V_39 ) {
case F_29 ( 0 , 1 ) :
return V_51 ;
case F_29 ( 1 , 1 ) :
return V_52 ;
}
} else {
}
break;
}
return - 1 ;
}
static int F_31 ( int V_53 , struct V_54 * V_55 )
{
V_55 -> V_56 = 0xe0000000 ;
if ( F_32 () || F_33 () )
V_55 -> V_56 -= ( ( * V_32 & 0xE000 ) << 16 ) ;
return F_34 ( V_53 , V_55 ) ;
}
int T_2 F_35 ( void )
{
if ( F_12 () || F_32 () ||\
F_33 () )
F_36 ( & V_57 ) ;
return 0 ;
}
static unsigned long F_37 ( unsigned long V_58 )
{
F_2 ( V_59 ,
( ( V_58 >> V_60 ) | V_61 ) ) ;
return ( V_58 & V_62 ) ;
}
static void T_2 F_38 ( void )
{
F_2 ( V_59 ,
( V_63 | V_61 ) ) ;
V_64 . V_65 =
( ( * V_59 & V_63 ) + 1 ) ;
F_39 ( V_66 , F_40 ( V_66 ) ) ;
F_41 () ;
F_19 () ;
}
static void F_42 ( char V_67 , const char * V_68 )
{
F_5 ( V_59 ,
( ( 0 >> V_60 )
| V_61 ) ) ;
F_2 ( V_69 , 0xffffffff ) ;
F_43 ( V_67 , V_68 ) ;
}
static void F_44 ( char V_67 , const char * V_68 )
{
unsigned long V_70 = * V_69 ;
V_70 = 0x55AA0000 | ( V_70 & 0x0000FFFF ) ;
F_5 ( V_69 , V_70 ) ;
F_2 ( V_69 , 0x80000000 ) ;
F_43 ( V_67 , V_68 ) ;
}
