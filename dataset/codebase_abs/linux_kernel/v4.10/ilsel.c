static inline unsigned int F_1 ( unsigned int V_1 )
{
return V_2 - V_1 - 1 ;
}
static inline unsigned long F_2 ( unsigned int V_1 )
{
return V_3 + ( ( F_1 ( V_1 ) >> 1 ) & ~ 0x1 ) ;
}
static inline unsigned int F_3 ( unsigned int V_1 )
{
return ( F_1 ( V_1 ) & 0x3 ) << 2 ;
}
static void F_4 ( T_1 V_4 , unsigned int V_1 )
{
unsigned int V_5 , V_6 ;
unsigned long V_7 ;
F_5 ( L_1 , V_4 ) ;
V_7 = F_2 ( V_1 ) ;
V_6 = F_3 ( V_1 ) ;
F_6 ( L_2 ,
V_8 , V_1 , V_7 , V_6 , V_4 ) ;
V_5 = F_7 ( V_7 ) ;
V_5 &= ~ ( 0xf << V_6 ) ;
V_5 |= V_4 << V_6 ;
F_8 ( V_5 , V_7 ) ;
}
int F_9 ( T_1 V_4 )
{
unsigned int V_1 ;
if ( F_10 ( V_4 > V_9 ) ) {
F_11 ( L_3 ) ;
return - V_10 ;
}
do {
V_1 = F_12 ( & V_11 , V_2 ) ;
} while ( F_13 ( V_1 , & V_11 ) );
F_4 ( V_4 , V_1 ) ;
return V_1 ;
}
int F_14 ( T_1 V_4 , unsigned int V_12 )
{
unsigned int V_1 = F_1 ( V_12 - 1 ) ;
if ( F_13 ( V_1 , & V_11 ) )
return - V_13 ;
F_4 ( V_4 , V_1 ) ;
return V_1 ;
}
void F_15 ( unsigned int V_14 )
{
unsigned long V_7 ;
unsigned int V_5 ;
F_5 ( L_4 , V_14 ) ;
V_7 = F_2 ( V_14 ) ;
V_5 = F_7 ( V_7 ) ;
V_5 &= ~ ( 0xf << F_3 ( V_14 ) ) ;
F_8 ( V_5 , V_7 ) ;
F_16 ( V_14 , & V_11 ) ;
}
