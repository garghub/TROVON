static inline void
F_1 ( unsigned int V_1 , unsigned long V_2 )
{
int V_3 = ( V_1 - 16 ) / 8 ;
F_2 ( V_2 >> ( 16 + V_3 * 8 ) , 0x804 + V_3 ) ;
}
static inline void
F_3 ( struct V_4 * V_5 )
{
F_1 ( V_5 -> V_1 , V_6 &= ~ ( 1UL << V_5 -> V_1 ) ) ;
}
static void
F_4 ( struct V_4 * V_5 )
{
F_1 ( V_5 -> V_1 , V_6 |= 1UL << V_5 -> V_1 ) ;
}
static void
F_5 ( unsigned long V_7 )
{
unsigned long V_8 ;
unsigned int V_9 ;
V_8 = F_6 ( 0x804 ) | ( F_6 ( 0x805 ) << 8 ) | ( F_6 ( 0x806 ) << 16 ) ;
while ( V_8 ) {
V_9 = F_7 ( ~ V_8 ) ;
V_8 &= V_8 - 1 ;
if ( V_9 == 4 ) {
F_8 ( V_7 ) ;
} else {
F_9 ( 16 + V_9 ) ;
}
}
}
static void T_1
F_10 ( void (* F_11)( unsigned long V_7 ) )
{
F_12 () ;
if ( V_10 ) {
V_11 . V_12 = F_11 ;
F_13 ( 35 , 0 ) ;
}
else {
long V_9 ;
F_2 ( 0xff , 0x804 ) ;
F_2 ( 0xff , 0x805 ) ;
F_2 ( 0xff , 0x806 ) ;
for ( V_9 = 16 ; V_9 < 35 ; ++ V_9 ) {
F_14 ( V_9 , & V_13 ,
V_14 ) ;
F_15 ( V_9 , V_15 ) ;
}
}
F_16 () ;
F_17 ( 16 + 4 , & V_16 ) ;
}
static void T_1
F_18 ( void )
{
F_10 ( V_17 ) ;
}
static void
F_19 ( unsigned long V_7 )
{
V_18 = F_20 () ;
V_17 ( V_7 ) ;
V_18 = 0 ;
}
static void
F_21 ( unsigned long V_7 )
{
V_18 = F_20 () ;
F_5 ( V_7 ) ;
V_18 = 0 ;
}
static void T_1
F_22 ( void )
{
F_10 ( F_19 ) ;
}
static inline int
F_23 ( const struct V_19 * V_20 , T_2 V_21 , T_2 V_22 )
{
static char V_23 [ 5 ] [ 5 ] = {
{ 16 + 0 , 16 + 0 , 16 + 5 , 16 + 9 , 16 + 13 } ,
{ 16 + 1 , 16 + 1 , 16 + 6 , 16 + 10 , 16 + 14 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 16 + 2 , 16 + 2 , 16 + 7 , 16 + 11 , 16 + 15 } ,
{ 16 + 3 , 16 + 3 , 16 + 8 , 16 + 12 , 16 + 6 }
} ;
const long V_24 = 6 , V_25 = 10 , V_26 = 5 ;
return V_27 ;
}
static inline int
F_24 ( const struct V_19 * V_20 , T_2 V_21 , T_2 V_22 )
{
static char V_23 [ 5 ] [ 5 ] = {
{ 16 + 2 , 16 + 2 , 16 + 7 , 16 + 11 , 16 + 15 } ,
{ 16 + 0 , 16 + 0 , 16 + 5 , 16 + 9 , 16 + 13 } ,
{ 16 + 1 , 16 + 1 , 16 + 6 , 16 + 10 , 16 + 14 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 16 + 3 , 16 + 3 , 16 + 8 , 16 + 12 , 16 + 16 }
} ;
const long V_24 = 5 , V_25 = 9 , V_26 = 5 ;
return V_27 ;
}
static inline void T_1
F_25 ( void )
{
if ( F_26 () == - 1 ) {
F_27 ( V_28 L_1 ) ;
} else {
F_27 ( V_29 L_2 ,
F_28 () , F_29 () ) ;
F_30 () ;
}
}
static inline void T_1
F_31 ( void )
{
F_32 () ;
F_25 () ;
}
static inline void T_1
F_33 ( void )
{
F_34 () ;
F_25 () ;
}
static inline int
F_35 ( const struct V_19 * V_20 , T_2 V_21 , T_2 V_22 )
{
static char V_23 [ 7 ] [ 5 ] = {
{ 16 + 2 , 16 + 2 , 16 + 9 , 16 + 13 , 16 + 17 } ,
{ 16 + 0 , 16 + 0 , 16 + 7 , 16 + 11 , 16 + 15 } ,
{ 16 + 1 , 16 + 1 , 16 + 8 , 16 + 12 , 16 + 16 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 16 + 3 , 16 + 3 , 16 + 10 , 16 + 14 , 16 + 18 } ,
{ 16 + 6 , 16 + 6 , 16 + 6 , 16 + 6 , 16 + 6 } ,
{ 16 + 5 , 16 + 5 , 16 + 5 , 16 + 5 , 16 + 5 }
} ;
const long V_24 = 5 , V_25 = 11 , V_26 = 5 ;
return V_27 ;
}
static inline void T_1
F_36 ( void )
{
F_34 () ;
F_37 () ;
}
