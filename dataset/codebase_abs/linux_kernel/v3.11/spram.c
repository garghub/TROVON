static unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
V_2 = F_2 () ;
F_3 ( V_2 | V_1 ) ;
return V_2 ;
}
static void F_4 ( unsigned int V_3 , unsigned int V_4 )
{
unsigned int V_5 ;
V_5 = F_1 ( V_6 ) ;
F_5 () ;
F_6 ( V_4 ) ;
F_5 () ;
F_7 ( V_7 , V_8 | V_3 ) ;
F_5 () ;
F_3 ( V_5 ) ;
F_5 () ;
}
static unsigned int F_8 ( unsigned int V_3 )
{
unsigned int V_4 ;
unsigned int V_5 ;
V_5 = F_1 ( V_6 ) ;
F_5 () ;
F_7 ( V_9 , V_8 | V_3 ) ;
F_5 () ;
V_4 = F_9 () ;
F_5 () ;
F_3 ( V_5 ) ;
F_5 () ;
return V_4 ;
}
static void F_10 ( unsigned int V_3 , unsigned int V_4 )
{
unsigned int V_5 ;
V_5 = F_1 ( V_6 ) ;
F_5 () ;
F_11 ( V_4 ) ;
F_5 () ;
F_7 ( V_10 , V_8 | V_3 ) ;
F_5 () ;
F_3 ( V_5 ) ;
F_5 () ;
}
static unsigned int F_12 ( unsigned int V_3 )
{
unsigned int V_4 ;
unsigned int V_5 ;
V_5 = F_1 ( V_6 ) ;
F_5 () ;
F_7 ( V_11 , V_8 | V_3 ) ;
F_5 () ;
V_4 = F_13 () ;
F_5 () ;
F_3 ( V_5 ) ;
F_5 () ;
return V_4 ;
}
void F_14 ( void )
{
struct V_12 * V_13 = & V_14 ;
unsigned int V_15 ;
switch ( V_13 -> V_16 ) {
case V_17 :
case V_18 :
case V_19 :
case V_20 :
V_15 = F_15 () ;
if ( V_15 & ( 1 << 24 ) ) {
F_16 ( L_1 , 0x1c000000 ,
& F_8 , & F_4 ) ;
}
if ( V_15 & ( 1 << 23 ) )
F_16 ( L_2 , 0x1c100000 ,
& F_12 , & F_10 ) ;
}
}
