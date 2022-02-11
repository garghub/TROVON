static void F_1 ( unsigned int V_1 ,
struct V_2 * V_3 )
{
unsigned int V_4 , V_5 ;
V_4 = F_2 ( V_6 ) ;
V_5 = F_2 ( V_7 ) ;
V_4 &= ~ V_5 ;
V_4 >>= 11 ;
V_4 &= 3 ;
if ( V_4 != 0 ) {
if ( V_4 & 1 ) {
F_3 ( V_8 ) ;
}
if ( V_4 & 2 ) {
F_3 ( V_9 ) ;
}
}
}
static void
F_4 ( struct V_10 * V_11 )
{
F_5 ( V_11 -> V_1 , V_12 , 3 << 11 ) ;
}
static void
F_6 ( struct V_10 * V_11 )
{
F_7 ( V_11 -> V_1 , V_12 ) ;
}
static void
F_8 ( struct V_10 * V_11 )
{
F_9 ( V_11 -> V_1 , V_12 , 3 << 11 ) ;
}
static int F_10 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
unsigned int V_17 ;
F_11 ( V_18 , & V_19 ,
V_20 ) ;
F_12 ( V_18 , V_21 ) ;
F_11 ( V_22 , & V_19 ,
V_20 ) ;
F_13 ( V_22 , F_1 ) ;
for ( V_17 = V_8 ; V_17 <= V_9 ; V_17 ++ ) {
F_11 ( V_17 , & V_23 ,
V_20 ) ;
F_12 ( V_17 , V_21 ) ;
}
return 0 ;
}
static int F_14 ( void )
{
return F_15 ( & V_24 ) ;
}
static int F_16 ( void )
{
return F_15 ( & V_25 ) ;
}
