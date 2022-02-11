static inline unsigned int F_1 ( unsigned char V_1 )
{
unsigned long V_2 [ V_3 ] ;
long V_4 ;
unsigned int V_5 = V_6 ;
V_4 = F_2 ( V_7 , V_2 , V_1 ) ;
if ( V_4 == V_8 ) {
V_5 = ( unsigned int ) V_2 [ 0 ] ;
} else {
F_3 ( L_1 ,
V_9 , V_1 , V_4 ) ;
F_4 ( 1 ) ;
}
return V_5 ;
}
static inline void F_5 ( T_1 V_10 )
{
long V_4 = F_6 ( V_11 , V_10 ) ;
if ( V_4 != V_8 ) {
F_3 ( L_2 ,
V_9 , V_10 , V_4 ) ;
F_4 ( 1 ) ;
}
}
static inline void F_7 ( unsigned int V_10 )
{
long V_4 = F_6 ( V_12 , V_10 ) ;
if ( V_4 != V_8 ) {
F_3 ( L_3 ,
V_9 , V_10 , V_4 ) ;
F_4 ( 1 ) ;
F_5 ( V_10 >> 24 ) ;
}
}
static inline void F_8 ( int V_13 , T_1 V_10 )
{
int V_14 = F_9 ( V_13 ) ;
long V_4 ;
F_10 () ;
V_4 = F_6 ( V_15 , V_14 , V_10 ) ;
if ( V_4 != V_8 ) {
F_3 ( L_4
L_5 , V_9 , V_13 , V_14 , V_10 , V_4 ) ;
F_4 ( 1 ) ;
}
}
static void F_11 ( struct V_16 * V_17 )
{
unsigned int V_18 = ( unsigned int ) F_12 ( V_17 ) ;
F_13 () ;
F_7 ( ( F_14 () << 24 ) | V_18 ) ;
}
static void F_15 ( void )
{
int V_19 = F_16 () ;
F_8 ( V_19 , 0xff ) ;
}
static void F_17 ( void )
{
F_7 ( ( 0x00 << 24 ) | V_20 ) ;
}
static unsigned int F_18 ( void )
{
unsigned int V_21 = F_1 ( F_19 () ) ;
unsigned int V_22 = V_21 & 0x00ffffff ;
unsigned int V_23 ;
if ( V_22 == V_6 )
return 0 ;
V_23 = F_20 ( V_24 , V_22 ) ;
if ( F_21 ( V_23 ) ) {
F_22 ( V_22 ) ;
return V_23 ;
}
F_23 ( V_22 ) ;
F_7 ( V_21 ) ;
return 0 ;
}
static void F_24 ( unsigned char V_1 )
{
F_25 ( V_1 ) ;
F_5 ( V_1 ) ;
F_13 () ;
}
static void F_26 ( int V_19 )
{
F_8 ( V_19 , V_25 ) ;
}
static T_2 F_27 ( int V_23 , void * V_26 )
{
int V_19 = F_16 () ;
F_8 ( V_19 , 0xff ) ;
return F_28 () ;
}
int F_29 ( void )
{
struct V_27 * V_28 ;
V_28 = F_30 ( NULL , NULL , L_6 ) ;
if ( ! V_28 )
V_28 = F_31 ( NULL ,
L_7 ) ;
if ( ! V_28 )
return - V_29 ;
V_30 = & V_31 ;
return 0 ;
}
