static int F_1 ( int V_1 , int V_2 , int V_3 , int V_4 , int V_5 )
{
register long int T_1 V_6 ( L_1 ) = V_1 ;
register long int T_2 V_6 ( L_2 ) = V_2 ;
register long int T_3 V_6 ( L_3 ) = V_3 ;
register long int T_4 V_6 ( L_4 ) = V_4 ;
register long int T_5 V_6 ( L_5 ) = V_5 ;
T_6 V_7 ;
V_7 = F_2 () ;
F_3 ( V_8 ) ;
__asm__ __volatile__ (
" syscall \n"
: "=r" (_num), "=r" (_arg3)
: "r" (_num), "r" (_arg0), "r" (_arg1), "r" (_arg2), "r" (_arg3));
F_3 ( V_7 ) ;
if ( T_5 )
return - T_1 ;
return T_1 ;
}
static int F_4 ( int V_9 )
{
int V_10 ;
int V_11 = - 1 ;
for ( V_10 = 0 ; V_10 < F_5 ( V_12 ) ; V_10 ++ ) {
if ( ( V_9 == V_12 [ V_10 ] . V_13 ) )
return V_12 [ V_10 ] . V_14 ;
}
return V_11 ;
}
static unsigned int F_6 ( int V_15 )
{
int V_10 ;
unsigned int V_11 = 0 ;
for ( V_10 = 0 ; V_10 < F_5 ( V_16 ) ; V_10 ++ ) {
if( ( V_15 & V_16 [ V_10 ] . V_13 ) ) {
V_11 |= V_16 [ V_10 ] . V_14 ;
}
}
return V_11 ;
}
static int F_7 ( T_7 V_17 , T_8 V_18 )
{
struct V_19 * V_20 ;
V_20 = F_8 () ;
if ( ! V_20 )
return - V_21 ;
V_20 -> V_22 = V_17 ;
V_20 -> V_23 = V_18 ;
F_9 ( V_20 ) ;
return 0 ;
}
void F_10 ( void )
{
struct V_24 V_25 ;
struct V_26 V_27 ;
struct V_28 V_11 ;
struct V_29 * V_30 ;
unsigned long V_31 ;
T_6 V_7 ;
struct V_32 V_33 ;
struct V_34 V_35 ;
int V_36 , V_9 ;
char * V_37 ;
int V_38 ;
V_11 . V_39 = - 1 ;
V_7 = F_2 () ;
F_3 ( V_8 ) ;
if ( ! F_11 ( V_40 , & V_25 , sizeof( struct V_24 ) ) ) {
F_3 ( V_7 ) ;
F_12 ( V_41 L_6 ) ;
return;
}
V_38 = V_25 . V_38 ;
if ( V_38 ) {
if ( ! F_11 ( V_40 , & V_27 , V_38 ) ) {
F_3 ( V_7 ) ;
F_12 ( V_41 L_6 ) ;
return;
}
}
if ( F_13 ( V_42 ) ) {
V_36 = F_7 ( F_13 ( V_42 ) , F_14 ( V_42 ) ) ;
if ( ! V_36 )
F_15 ( L_7 ) ;
}
switch ( V_25 . V_9 ) {
case V_43 :
V_11 . V_39 = V_44 * 1000 ;
V_11 . V_45 = 0 ;
break;
case V_46 :
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
if ( ( V_11 . V_39 = F_1 ( V_47 , ( int ) & V_33 ,
( int ) & V_35 , 0 , 0 ) ) == 0 )
V_11 . V_39 = V_33 . V_48 ;
break;
case V_49 :
F_16 (n, &kspd_notifylist, list)
V_30 -> V_50 ( V_42 ) ;
V_51 = 1 ;
F_12 ( V_52 L_8 ,
V_27 . V_2 ) ;
break;
case V_53 :
V_27 . V_3 = F_6 ( V_27 . V_3 ) ;
V_37 = F_17 ( V_42 ) ;
V_7 = F_2 () ;
F_3 ( V_8 ) ;
F_18 ( V_37 ) ;
F_3 ( V_7 ) ;
V_25 . V_9 = V_54 ;
default:
if ( ( V_25 . V_9 >= V_55 ) &&
( V_25 . V_9 <= ( V_55 + V_56 ) ) )
V_9 = V_25 . V_9 ;
else
V_9 = F_4 ( V_25 . V_9 ) ;
if ( V_9 >= 0 ) {
V_11 . V_39 = F_1 ( V_9 , V_27 . V_2 , V_27 . V_3 ,
V_27 . V_4 , V_27 . V_5 ) ;
} else
F_12 ( V_57
L_9 , V_25 . V_9 ) ;
break;
}
if ( F_13 ( V_42 ) ) {
V_36 = F_7 ( 0 , 0 ) ;
if ( ! V_36 )
F_15 ( L_10 ) ;
}
V_7 = F_2 () ;
F_3 ( V_8 ) ;
V_31 = F_19 ( V_40 , & V_11 , sizeof( V_11 ) ) ;
F_3 ( V_7 ) ;
if ( V_31 < sizeof( V_11 ) )
F_12 ( L_11 ) ;
}
static void F_20 ( void )
{
struct V_58 * V_59 = V_60 -> V_59 ;
int V_10 , V_61 ;
struct V_62 * V_63 ;
V_61 = 0 ;
V_63 = F_21 ( V_59 ) ;
for (; ; ) {
unsigned long V_64 ;
V_10 = V_61 * V_65 ;
if ( V_10 >= V_63 -> V_66 )
break;
V_64 = V_63 -> V_67 [ V_61 ++ ] ;
while ( V_64 ) {
if ( V_64 & 1 ) {
struct V_68 * V_68 = F_22 ( & V_63 -> V_69 [ V_10 ] , NULL ) ;
if ( V_68 )
F_23 ( V_68 , V_59 ) ;
}
V_10 ++ ;
V_64 >>= 1 ;
}
}
F_18 ( L_12 ) ;
}
static void F_24 ( struct V_70 * V_71 )
{
if ( ! V_72 ) {
if( F_25 ( V_40 , 1 ) != 0 ) {
F_12 ( L_13 ) ;
V_51 = 1 ;
} else {
V_72 ++ ;
F_12 ( V_52 L_14 ) ;
}
} else {
F_26 ( V_40 , 1 ) ;
if ( ! V_51 )
F_10 () ;
}
if ( ! V_51 )
F_27 ( V_73 , & V_74 ) ;
else
F_20 () ;
}
static void F_28 ( int V_75 )
{
V_51 = V_72 = 0 ;
if ( V_73 == NULL ) {
if ( ( V_73 = F_29 ( L_15 ) ) == NULL ) {
F_12 ( V_41 L_16 ) ;
return;
}
F_30 ( & V_74 , F_24 ) ;
}
F_27 ( V_73 , & V_74 ) ;
}
static void F_31 ( int V_75 )
{
V_51 = 1 ;
F_12 ( V_52 L_17 ) ;
}
void F_32 ( struct V_29 * V_76 )
{
F_33 ( & V_76 -> V_77 , & V_78 ) ;
}
static int F_34 ( void )
{
F_35 ( & V_78 ) ;
V_76 . V_79 = F_28 ;
V_76 . V_80 = F_31 ;
F_36 ( V_42 , & V_76 ) ;
return 0 ;
}
static void F_37 ( void )
{
}
