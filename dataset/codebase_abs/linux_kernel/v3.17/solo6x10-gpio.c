static void F_1 ( struct V_1 * V_1 ,
unsigned int V_2 , unsigned int V_3 )
{
int V_4 ;
unsigned int V_5 ;
V_5 = F_2 ( V_1 , V_6 ) ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
if ( ! ( ( 1 << V_4 ) & V_2 ) )
continue;
V_5 &= ( ~ ( 3 << ( V_4 << 1 ) ) ) ;
V_5 |= ( ( V_3 & 3 ) << ( V_4 << 1 ) ) ;
}
F_3 ( V_1 , V_6 , V_5 ) ;
V_5 = F_2 ( V_1 , V_7 ) ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
if ( ! ( ( 1 << ( V_4 + 16 ) ) & V_2 ) )
continue;
if ( ! V_3 )
V_5 &= ~ ( 1 << V_4 ) ;
else
V_5 |= 1 << V_4 ;
}
F_3 ( V_1 , V_7 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_1 , unsigned int V_8 )
{
F_3 ( V_1 , V_9 ,
F_2 ( V_1 , V_9 ) | V_8 ) ;
}
static void F_5 ( struct V_1 * V_1 , unsigned int V_8 )
{
F_3 ( V_1 , V_9 ,
F_2 ( V_1 , V_9 ) & ~ V_8 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0x30 , 1 ) ;
F_5 ( V_1 , 0x30 ) ;
F_7 ( 100 ) ;
F_4 ( V_1 , 0x30 ) ;
F_7 ( 100 ) ;
F_1 ( V_1 , 0x0f , 2 ) ;
F_1 ( V_1 , 0xff00 , 1 ) ;
F_5 ( V_1 , 0xff00 ) ;
}
int F_8 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0x30 ) ;
F_6 ( V_1 ) ;
}
