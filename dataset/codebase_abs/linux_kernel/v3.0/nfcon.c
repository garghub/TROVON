static void F_1 ( const char * V_1 , unsigned int V_2 )
{
char V_3 [ 68 ] ;
V_3 [ 64 ] = 0 ;
while ( V_2 > 64 ) {
memcpy ( V_3 , V_1 , 64 ) ;
F_2 ( V_4 , V_3 ) ;
V_1 += 64 ;
V_2 -= 64 ;
}
memcpy ( V_3 , V_1 , V_2 ) ;
V_3 [ V_2 ] = 0 ;
F_2 ( V_4 , V_3 ) ;
}
static void F_3 ( struct V_5 * V_6 , const char * V_1 ,
unsigned int V_2 )
{
F_1 ( V_1 , V_2 ) ;
}
static struct V_7 * F_4 ( struct V_5 * V_6 , int * V_8 )
{
* V_8 = 0 ;
return ( V_6 -> V_9 & V_10 ) ? V_11 : NULL ;
}
static int F_5 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
return 0 ;
}
static void F_6 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
}
static int F_7 ( struct V_12 * V_13 , const unsigned char * V_3 ,
int V_2 )
{
F_1 ( V_3 , V_2 ) ;
return V_2 ;
}
static int F_8 ( struct V_12 * V_13 , unsigned char V_16 )
{
char V_17 [ 2 ] = { V_16 , 0 } ;
F_2 ( V_4 , V_17 ) ;
return 1 ;
}
static int F_9 ( struct V_12 * V_13 )
{
return 64 ;
}
static int T_1 F_10 ( char * V_18 )
{
if ( strcmp ( V_18 , L_1 ) )
return 0 ;
V_4 = F_11 ( L_2 ) ;
if ( V_4 ) {
V_19 . V_9 |= V_10 ;
F_12 ( & V_19 ) ;
}
return 0 ;
}
static int T_1 F_13 ( void )
{
int V_20 ;
V_4 = F_11 ( L_2 ) ;
if ( ! V_4 )
return - V_21 ;
V_11 = F_14 ( 1 ) ;
if ( ! V_11 )
return - V_22 ;
V_11 -> V_23 = V_24 ;
V_11 -> V_25 = L_1 ;
V_11 -> V_26 = L_1 ;
V_11 -> type = V_27 ;
V_11 -> V_28 = V_29 ;
V_11 -> V_30 = V_31 ;
V_11 -> V_9 = V_32 ;
F_15 ( V_11 , & V_33 ) ;
V_20 = F_16 ( V_11 ) ;
if ( V_20 ) {
F_17 ( L_3 ) ;
F_18 ( V_11 ) ;
return V_20 ;
}
if ( ! ( V_19 . V_9 & V_10 ) )
F_12 ( & V_19 ) ;
return 0 ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_19 ) ;
F_21 ( V_11 ) ;
F_18 ( V_11 ) ;
}
