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
F_24 ( V_2 , V_26 ) ;
switch ( F_2 () ) {
case V_5 :
case V_6 :
F_25 ( V_2 , 0 ) ;
break;
case V_8 :
F_26 ( V_2 , 0 ) ;
break;
}
} else {
F_24 ( V_2 , V_27 ) ;
switch ( F_2 () ) {
case V_5 :
case V_6 :
if ( F_27 ( V_2 ) == 1 )
F_28 ( 0x01 ) ;
break;
case V_8 :
F_10 ( F_29 ( V_2 ) ) ;
break;
}
F_30 ( V_2 , & V_25 ) ;
}
}
static void F_31 ( void )
{
switch ( F_2 () ) {
case V_5 :
case V_6 :
F_32 ( F_33 () ? V_28 : V_29 ) ;
break;
case V_8 :
F_10 ( F_11 ( F_33 () , 0 ) ) ;
break;
}
}
static void F_34 ( void )
{
F_22 ( L_6 , F_33 () ) ;
F_35 ( F_36 () + V_30 / V_31 ) ;
F_37 () ;
F_38 ( V_32 | V_33 | V_34 | V_35 | V_36 ) ;
F_37 () ;
}
static void F_26 ( int V_2 , unsigned int V_37 )
{
F_10 ( F_39 ( V_2 , V_37 == V_38 ) ) ;
}
static T_2 V_17 ( int V_14 , void * V_15 )
{
int V_37 = V_14 - V_18 ;
F_10 ( F_11 ( F_33 () , V_37 ) ) ;
if ( V_37 == 0 )
F_40 () ;
else
F_41 () ;
return V_39 ;
}
static void F_42 ( const struct V_40 * V_41 ,
unsigned int V_37 )
{
unsigned int V_1 ;
F_43 (i, mask)
F_26 ( V_1 , V_37 ) ;
}
static void F_25 ( int V_2 , unsigned int V_37 )
{
unsigned long V_42 ;
F_44 ( & V_43 , V_42 ) ;
F_45 ( V_2 ? V_28 : V_29 ) ;
F_46 ( V_44 , V_2 ) |= V_37 ;
F_37 () ;
F_47 ( & V_43 , V_42 ) ;
}
static T_2 V_16 ( int V_14 , void * V_15 )
{
unsigned long V_42 ;
int V_37 , V_2 = V_14 - V_18 ;
F_44 ( & V_43 , V_42 ) ;
V_37 = F_48 ( V_44 ) ;
F_46 ( V_44 , V_2 ) = 0 ;
F_32 ( V_2 ? V_28 : V_29 ) ;
F_47 ( & V_43 , V_42 ) ;
if ( V_37 & V_45 )
F_40 () ;
if ( V_37 & V_38 )
F_41 () ;
return V_39 ;
}
static void F_49 ( const struct V_40 * V_41 ,
unsigned int V_37 )
{
unsigned int V_1 ;
F_43 (i, mask)
F_25 ( V_1 , V_37 ) ;
}
static int F_50 ( void )
{
unsigned int V_2 = F_33 () ;
if ( V_2 == 0 )
return - V_46 ;
F_22 ( L_7 , V_2 ) ;
F_51 ( V_2 , false ) ;
F_52 ( V_2 , & V_47 ) ;
F_53 ( V_35 ) ;
F_54 () ;
F_55 ( 0 , ~ 0 ) ;
return 0 ;
}
static void F_56 ( unsigned int V_2 )
{
}
void T_3 F_57 ( void )
{
F_58 () ;
F_59 ( 0 , ~ 0 ) ;
F_32 ( V_48 | V_29 | V_28 ) ;
F_60 (
V_35 | V_34 | V_32 | V_33 | V_36 | V_49 ,
V_32 | V_33 | V_36 | V_49 ) ;
F_61 () ;
__asm__ __volatile__(
" wait\n"
" j bmips_secondary_reentry\n"
: : : "memory");
}
static void F_62 ( unsigned long V_50 , char * V_51 , char * V_52 )
{
memcpy ( ( void * ) V_50 , V_51 , V_52 - V_51 ) ;
F_63 ( V_50 , V_52 - V_51 ) ;
F_55 ( V_50 , V_50 + ( V_52 - V_51 ) ) ;
F_64 () ;
}
static inline void F_65 ( void )
{
F_62 ( V_53 , & V_54 ,
& V_55 ) ;
F_62 ( V_56 , & V_57 ,
& V_58 ) ;
}
static void F_66 ( void * V_59 )
{
struct V_60 * V_61 = V_59 ;
int V_62 = V_61 -> V_2 & 0x01 ? 16 : 0 ;
T_4 V_41 = ~ ( 0xffff << V_62 ) , V_63 = V_61 -> V_63 >> 16 ;
F_67 () ;
if ( F_33 () > 0 ) {
F_68 ( 0 , & F_66 ,
V_61 , 1 ) ;
} else {
if ( V_61 -> V_2 & 0x02 ) {
F_69 ( 0xa0 , ( V_63 << 16 ) | V_63 ) ;
F_70 ( 0xa0 ) ;
} else {
F_71 ( ( F_72 () & V_41 ) |
( V_63 << V_62 ) ) ;
}
}
F_73 () ;
}
static void F_24 ( int V_2 , T_4 V_63 )
{
struct V_60 V_61 ;
if ( F_2 () == V_8 ) {
V_61 . V_2 = V_2 ;
V_61 . V_63 = V_63 ;
F_66 ( & V_61 ) ;
} else {
void T_5 * V_64 = F_74 () ;
if ( V_2 == 0 )
F_75 ( V_63 , V_64 + V_65 ) ;
else {
if ( F_2 () != V_6 )
return;
F_75 ( V_63 , V_64 + V_66 ) ;
}
}
F_76 () ;
F_77 () ;
}
void V_11 ( void )
{
unsigned long V_67 = V_68 ;
F_78 ( V_68 != V_69 ) ;
switch ( F_2 () ) {
case V_5 :
F_79 ( V_56 - V_69 ,
& V_57 , 0x80 ) ;
F_76 () ;
return;
case V_70 :
case V_6 :
V_67 = 0x80000400 ;
F_24 ( 0 , V_26 ) ;
break;
case V_8 :
V_67 = 0x80001000 ;
F_24 ( 0 , V_26 ) ;
F_80 ( V_67 ) ;
break;
default:
return;
}
V_71 = & F_65 ;
V_68 = V_67 ;
}
T_6 void __weak F_81 ( void )
{
}
