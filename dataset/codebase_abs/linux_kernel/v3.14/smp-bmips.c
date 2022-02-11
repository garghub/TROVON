static void T_1 F_1 ( void )
{
int V_1 , V_2 = 1 , V_3 = 0 ;
int V_4 ;
switch ( F_2 () ) {
case V_5 :
case V_6 :
F_3 ( 0x30 ) ;
F_4 ( 0x30000 ) ;
V_3 = ! ! ( F_5 () & ( 1 << 31 ) ) ;
if ( V_3 == 0 )
V_4 = 0x02 ;
else
V_4 = 0x1d ;
F_6 ( 0xf8018000 ,
( V_4 << 27 ) | ( 0x03 << 15 ) ) ;
V_7 = 2 ;
break;
case V_8 :
F_7 ( 0x03 << 22 ) ;
F_8 ( 0x1f << 27 , 0x02 << 27 ) ;
V_7 = ( ( ( F_9 () >> 6 ) & 0x03 ) + 1 ) << 1 ;
for ( V_1 = 0 ; V_1 < V_7 ; V_1 ++ ) {
F_10 ( F_11 ( V_1 , 0 ) ) ;
F_10 ( F_11 ( V_1 , 1 ) ) ;
}
break;
default:
V_7 = 1 ;
}
if ( ! V_9 )
V_7 = 1 ;
if ( ! V_10 )
V_10 = & V_11 ;
V_12 [ V_3 ] = 0 ;
V_13 [ 0 ] = V_3 ;
for ( V_1 = 0 ; V_1 < V_7 ; V_1 ++ ) {
if ( V_1 != V_3 ) {
V_12 [ V_1 ] = V_2 ;
V_13 [ V_2 ] = V_1 ;
V_2 ++ ;
}
F_12 ( V_1 , 1 ) ;
F_13 ( V_1 , 1 ) ;
}
}
static void F_14 ( unsigned int V_7 )
{
T_2 (* F_15)( int V_14 , void * V_15 );
switch ( F_2 () ) {
case V_5 :
case V_6 :
F_15 = V_16 ;
break;
case V_8 :
F_15 = V_17 ;
break;
default:
return;
}
if ( F_16 ( V_18 , F_15 , V_19 ,
L_1 , NULL ) )
F_17 ( L_2 ) ;
if ( F_16 ( V_20 , F_15 , V_19 ,
L_3 , NULL ) )
F_17 ( L_4 ) ;
}
static void F_18 ( int V_2 , struct V_21 * V_22 )
{
V_23 = F_19 ( V_22 ) ;
V_24 = ( unsigned long ) F_20 ( V_22 ) ;
F_21 () ;
F_22 ( L_5 , V_2 ) ;
if ( F_23 ( V_2 , & V_25 ) ) {
switch ( F_2 () ) {
case V_5 :
case V_6 :
F_24 ( V_2 , 0 ) ;
break;
case V_8 :
F_25 ( V_2 , 0 ) ;
break;
}
}
else {
switch ( F_2 () ) {
case V_5 :
case V_6 :
if ( F_26 ( V_2 ) == 1 )
F_27 ( 0x01 ) ;
break;
case V_8 :
if ( V_2 & 0x01 )
F_10 ( F_28 ( V_2 ) ) ;
else {
F_29 ( 0x210 , 0xc0000000 ) ;
F_30 ( 10 ) ;
F_29 ( 0x210 , 0x00 ) ;
}
break;
}
F_31 ( V_2 , & V_25 ) ;
}
}
static void F_32 ( void )
{
void T_3 * V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
int V_3 ;
switch ( F_2 () ) {
case V_5 :
case V_6 :
V_26 = F_33 () ;
V_3 = ! ! ( F_5 () & ( 1 << 31 ) ) ;
V_28 = V_3 ? V_29 :
V_30 ;
V_27 = F_34 ( V_26 + V_28 ) ;
F_35 ( V_27 & ~ 0x20000000 , V_26 + V_28 ) ;
F_36 ( F_37 () ? V_31 : V_32 ) ;
break;
case V_8 :
F_38 ( F_39 () &
( F_37 () & 0x01 ? ~ 0x20000000 : ~ 0x2000 ) ) ;
F_10 ( F_11 ( F_37 () , 0 ) ) ;
break;
}
}
static void F_40 ( void )
{
F_22 ( L_6 , F_37 () ) ;
F_41 ( F_42 () + V_33 / V_34 ) ;
F_43 () ;
F_44 ( V_35 | V_36 | V_37 | V_38 | V_39 ) ;
F_43 () ;
}
static void F_45 ( void )
{
}
static void F_25 ( int V_2 , unsigned int V_40 )
{
F_10 ( F_46 ( V_2 , V_40 == V_41 ) ) ;
}
static T_2 V_17 ( int V_14 , void * V_15 )
{
int V_40 = V_14 - V_18 ;
F_10 ( F_11 ( F_37 () , V_40 ) ) ;
if ( V_40 == 0 )
F_47 () ;
else
F_48 () ;
return V_42 ;
}
static void F_49 ( const struct V_43 * V_44 ,
unsigned int V_40 )
{
unsigned int V_1 ;
F_50 (i, mask)
F_25 ( V_1 , V_40 ) ;
}
static void F_24 ( int V_2 , unsigned int V_40 )
{
unsigned long V_45 ;
F_51 ( & V_46 , V_45 ) ;
F_52 ( V_2 ? V_31 : V_32 ) ;
F_53 ( V_47 , V_2 ) |= V_40 ;
F_43 () ;
F_54 ( & V_46 , V_45 ) ;
}
static T_2 V_16 ( int V_14 , void * V_15 )
{
unsigned long V_45 ;
int V_40 , V_2 = V_14 - V_18 ;
F_51 ( & V_46 , V_45 ) ;
V_40 = F_55 ( V_47 ) ;
F_53 ( V_47 , V_2 ) = 0 ;
F_36 ( V_2 ? V_31 : V_32 ) ;
F_54 ( & V_46 , V_45 ) ;
if ( V_40 & V_48 )
F_47 () ;
if ( V_40 & V_41 )
F_48 () ;
return V_42 ;
}
static void F_56 ( const struct V_43 * V_44 ,
unsigned int V_40 )
{
unsigned int V_1 ;
F_50 (i, mask)
F_24 ( V_1 , V_40 ) ;
}
static int F_57 ( void )
{
unsigned int V_2 = F_37 () ;
if ( V_2 == 0 )
return - V_49 ;
F_22 ( L_7 , V_2 ) ;
F_58 ( V_2 , false ) ;
F_59 ( V_2 , V_50 ) ;
F_60 () ;
F_61 ( 0 , ~ 0 ) ;
return 0 ;
}
static void F_62 ( unsigned int V_2 )
{
}
void T_4 F_63 ( void )
{
F_64 () ;
F_65 ( 0 , ~ 0 ) ;
F_36 ( V_51 | V_32 | V_31 ) ;
F_66 ( V_38 | V_37 | V_35 | V_36 | V_39 | V_52 ,
V_35 | V_36 | V_39 | V_52 ) ;
F_67 () ;
__asm__ __volatile__(
" wait\n"
" j bmips_secondary_reentry\n"
: : : "memory");
}
static void F_68 ( unsigned long V_53 , char * V_54 , char * V_55 )
{
memcpy ( ( void * ) V_53 , V_54 , V_55 - V_54 ) ;
F_69 ( ( unsigned long ) V_54 , V_55 - V_54 ) ;
F_61 ( V_53 , V_53 + ( V_55 - V_54 ) ) ;
F_70 () ;
}
static inline void F_71 ( void )
{
F_68 ( V_56 , & V_57 ,
& V_58 ) ;
F_68 ( V_59 , & V_60 ,
& V_61 ) ;
}
void V_11 ( void )
{
unsigned long V_62 = V_63 ;
void T_3 T_5 * V_26 ;
F_72 ( V_63 != V_64 ) ;
switch ( F_2 () ) {
case V_5 :
F_73 ( V_59 - V_64 ,
& V_60 , 0x80 ) ;
F_74 () ;
return;
case V_6 :
V_62 = 0x80000400 ;
V_26 = F_33 () ;
F_35 ( 0x80080800 , V_26 + V_29 ) ;
F_35 ( 0xa0080800 , V_26 + V_30 ) ;
break;
case V_8 :
V_62 = 0x80001000 ;
F_38 ( 0xa0088008 ) ;
F_75 ( V_62 ) ;
if ( V_7 > 2 )
F_29 ( 0xa0 , 0xa008a008 ) ;
break;
default:
return;
}
V_65 = & F_71 ;
V_63 = V_62 ;
}
T_6 void __weak F_76 ( void )
{
}
