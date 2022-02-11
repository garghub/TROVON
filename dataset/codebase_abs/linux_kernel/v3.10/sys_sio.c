static void T_1
F_1 ( void )
{
if ( V_1 )
V_2 . V_3 = V_4 ;
F_2 () ;
F_3 () ;
}
static inline void T_1
F_4 ( void )
{
V_5 . V_6 = 37 ;
V_5 . V_7 = 100 ;
V_5 . V_8 = 37 ;
F_5 () ;
}
static void T_1
F_6 ( void )
{
unsigned int V_9 ;
F_7 ( V_10 -> V_11 , F_8 ( 7 , 0 ) , 0x60 ,
& V_9 ) ;
F_9 ( L_1 , V_12 ,
V_9 , V_2 . V_13 . V_14 . V_15 ) ;
#if F_10 ( V_16 )
V_17 . V_9 = V_9 ;
#endif
F_11 ( V_10 -> V_11 , F_8 ( 7 , 0 ) , 0x60 ,
V_2 . V_13 . V_14 . V_15 ) ;
}
static unsigned int T_1
F_12 ( void )
{
unsigned int V_18 = 0 ;
struct V_19 * V_20 = NULL ;
F_13 (dev) {
if ( ( V_20 -> V_21 >> 16 == V_22 ) &&
( V_20 -> V_21 >> 8 != V_23 ) )
continue;
if ( V_20 -> V_24 )
V_18 |= ( 1 << V_20 -> V_24 ) ;
}
return V_18 ;
}
static void T_1
F_14 ( unsigned int V_18 )
{
unsigned int V_25 ;
V_25 = F_15 ( 0x4d0 ) | ( F_15 ( 0x4d1 ) << 8 ) ;
V_18 |= ( V_25 & 0x71ff ) ;
F_16 ( ( V_18 >> 0 ) & 0xff , 0x4d0 ) ;
F_16 ( ( V_18 >> 8 ) & 0xff , 0x4d1 ) ;
}
static inline int T_1
F_17 ( const struct V_19 * V_20 , T_2 V_26 , T_2 V_27 )
{
static char V_28 [] [ 5 ] V_29 = {
{ 3 , 3 , 3 , 3 , 3 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 2 , 2 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 0 , 0 , 2 , 1 , 0 } ,
{ 1 , 1 , 0 , 2 , 1 } ,
{ 2 , 2 , 1 , 0 , 2 } ,
{ 0 , 0 , 0 , 0 , 0 } ,
} ;
const long V_30 = 6 , V_31 = 14 , V_32 = 5 ;
int V_24 = V_33 , V_34 ;
V_34 = F_18 ( V_2 . V_13 . V_14 . V_15 , V_24 ) ;
return V_24 >= 0 ? V_34 : - 1 ;
}
static inline int T_1
F_19 ( const struct V_19 * V_20 , T_2 V_26 , T_2 V_27 )
{
static char V_28 [] [ 5 ] V_29 = {
{ 0 , 0 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 1 , 1 , 2 , 3 , 0 } ,
{ 2 , 2 , 3 , 0 , 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 3 , 3 , - 1 , - 1 , - 1 } ,
} ;
const long V_30 = 6 , V_31 = 12 , V_32 = 5 ;
int V_24 = V_33 , V_34 ;
V_34 = F_18 ( V_2 . V_13 . V_14 . V_15 , V_24 ) ;
return V_24 >= 0 ? V_34 : - 1 ;
}
static inline void T_1
F_20 ( void )
{
F_21 () ;
F_6 () ;
F_14 ( F_12 () ) ;
if ( F_22 () == - 1 ) {
F_9 ( V_35 L_2 ) ;
} else {
F_9 ( V_36 L_3 ,
F_23 () , F_24 () ) ;
#if ! F_10 ( V_37 )
F_25 () ;
#endif
F_26 () ;
}
}
static inline void T_1
F_27 ( void )
{
struct V_19 * V_20 ;
unsigned char V_38 , V_39 ;
F_21 () ;
F_6 () ;
V_20 = NULL ;
while ( ( V_20 = F_28 ( V_40 , V_41 , V_20 ) ) ) {
if ( V_20 -> V_42 == V_43
|| V_20 -> V_42 == V_44
|| V_20 -> V_42 == V_45
|| V_20 -> V_42 == V_46 ) {
unsigned long V_47 ;
unsigned char V_48 ;
V_47 = V_20 -> V_49 [ 0 ] . V_50 ;
V_48 = F_15 ( V_47 + 0x21 ) ;
if ( ! ( V_48 & 0x80 ) ) {
F_9 ( L_4
L_5 ) ;
F_16 ( V_48 | 0x80 , V_47 + 0x21 ) ;
}
}
}
F_14 ( 0 ) ;
F_16 ( 0x0f , 0x3ce ) ; V_38 = F_15 ( 0x3cf ) ;
F_16 ( 0x0f , 0x3ce ) ; F_16 ( 0x05 , 0x3cf ) ;
F_16 ( 0x0b , 0x3ce ) ; V_39 = F_15 ( 0x3cf ) ;
if ( ( V_39 & 0xc0 ) != 0xc0 ) {
F_9 ( L_6 ) ;
V_39 |= 0xc0 ;
F_16 ( 0x0b , 0x3ce ) ; F_16 ( V_39 , 0x3cf ) ;
}
F_16 ( 0x0f , 0x3ce ) ; F_16 ( V_38 , 0x3cf ) ;
}
void
F_29 ( int V_51 )
{
#if F_10 ( V_16 )
F_11 ( V_10 -> V_11 , F_8 ( 7 , 0 ) , 0x60 ,
V_17 . V_9 ) ;
#endif
}
