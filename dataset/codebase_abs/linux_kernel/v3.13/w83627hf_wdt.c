static void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_4 ) ;
}
static inline int F_3 ( int V_1 )
{
F_2 ( V_1 , V_3 ) ;
return F_4 ( V_4 ) ;
}
static int F_5 ( void )
{
if ( ! F_6 ( V_5 , 2 , V_6 ) )
return - V_7 ;
F_7 ( 0x87 , V_3 ) ;
F_7 ( 0x87 , V_3 ) ;
return 0 ;
}
static void F_8 ( int V_8 )
{
F_1 ( 0x07 , V_8 ) ;
}
static void F_9 ( void )
{
F_7 ( 0xAA , V_3 ) ;
F_10 ( V_5 , 2 ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
int V_11 ;
unsigned char V_12 ;
V_11 = F_5 () ;
if ( V_11 )
return V_11 ;
F_8 ( V_13 ) ;
V_12 = F_3 ( 0x20 ) ;
if ( V_12 == 0x82 ) {
V_12 = ( F_3 ( 0x2b ) & 0xf7 ) ;
F_1 ( 0x2b , V_12 | 0x04 ) ;
} else if ( V_12 == 0x88 || V_12 == 0xa0 ) {
V_12 = F_3 ( 0x2d ) ;
F_1 ( 0x2d , V_12 & ~ 0x01 ) ;
}
V_12 = F_3 ( 0x30 ) ;
if ( ! ( V_12 & 0x01 ) )
F_1 ( 0x30 , V_12 | 0x01 ) ;
V_12 = F_3 ( 0xF6 ) ;
if ( V_12 != 0 ) {
F_12 ( L_1 ,
V_10 -> V_14 ) ;
F_1 ( 0xF6 , V_10 -> V_14 ) ;
}
V_12 = F_3 ( 0xF5 ) & ~ 0x0C ;
V_12 |= 0x02 ;
F_1 ( 0xF5 , V_12 ) ;
V_12 = F_3 ( 0xF7 ) & ~ 0xC0 ;
F_1 ( 0xF7 , V_12 ) ;
F_9 () ;
return 0 ;
}
static int F_13 ( unsigned int V_14 )
{
int V_11 ;
V_11 = F_5 () ;
if ( V_11 )
return V_11 ;
F_8 ( V_13 ) ;
F_1 ( 0xF6 , V_14 ) ;
F_9 () ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 )
{
return F_13 ( V_10 -> V_14 ) ;
}
static int F_15 ( struct V_9 * V_10 )
{
return F_13 ( 0 ) ;
}
static int F_16 ( struct V_9 * V_10 , unsigned int V_14 )
{
V_10 -> V_14 = V_14 ;
return 0 ;
}
static unsigned int F_17 ( struct V_9 * V_10 )
{
unsigned int V_15 ;
int V_11 ;
V_11 = F_5 () ;
if ( V_11 )
return 0 ;
F_8 ( V_13 ) ;
V_15 = F_3 ( 0xF6 ) ;
F_9 () ;
return V_15 ;
}
static int F_18 ( struct V_16 * V_17 , unsigned long V_18 ,
void * V_19 )
{
if ( V_18 == V_20 || V_18 == V_21 )
F_13 ( 0 ) ;
return V_22 ;
}
static int T_1 F_19 ( void )
{
int V_11 ;
F_12 ( L_2 ) ;
F_20 ( & V_23 , V_14 , NULL ) ;
F_21 ( & V_23 , V_24 ) ;
V_11 = F_11 ( & V_23 ) ;
if ( V_11 ) {
F_22 ( L_3 , V_11 ) ;
return V_11 ;
}
V_11 = F_23 ( & V_25 ) ;
if ( V_11 != 0 ) {
F_22 ( L_4 , V_11 ) ;
return V_11 ;
}
V_11 = F_24 ( & V_23 ) ;
if ( V_11 )
goto V_26;
F_12 ( L_5 ,
V_23 . V_14 , V_24 ) ;
return V_11 ;
V_26:
F_25 ( & V_25 ) ;
return V_11 ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_23 ) ;
F_25 ( & V_25 ) ;
}
