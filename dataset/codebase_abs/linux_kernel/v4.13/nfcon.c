static void F_1 ( const char * V_1 , unsigned int V_2 )
{
char V_3 [ 68 ] ;
unsigned long V_4 = F_2 ( V_3 ) ;
V_3 [ 64 ] = 0 ;
while ( V_2 > 64 ) {
memcpy ( V_3 , V_1 , 64 ) ;
F_3 ( V_5 , V_4 ) ;
V_1 += 64 ;
V_2 -= 64 ;
}
memcpy ( V_3 , V_1 , V_2 ) ;
V_3 [ V_2 ] = 0 ;
F_3 ( V_5 , V_4 ) ;
}
static void F_4 ( struct V_6 * V_7 , const char * V_1 ,
unsigned int V_2 )
{
F_1 ( V_1 , V_2 ) ;
}
static struct V_8 * F_5 ( struct V_6 * V_7 , int * V_9 )
{
* V_9 = 0 ;
return ( V_7 -> V_10 & V_11 ) ? V_12 : NULL ;
}
static int F_6 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
return 0 ;
}
static void F_7 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
}
static int F_8 ( struct V_13 * V_14 , const unsigned char * V_3 ,
int V_2 )
{
F_1 ( V_3 , V_2 ) ;
return V_2 ;
}
static int F_9 ( struct V_13 * V_14 , unsigned char V_17 )
{
char V_18 [ 2 ] = { V_17 , 0 } ;
F_3 ( V_5 , F_2 ( V_18 ) ) ;
return 1 ;
}
static int F_10 ( struct V_13 * V_14 )
{
return 64 ;
}
static int T_1 F_11 ( char * V_19 )
{
if ( strcmp ( V_19 , L_1 ) )
return 0 ;
V_5 = F_12 ( L_2 ) ;
if ( V_5 ) {
V_20 . V_10 |= V_11 ;
F_13 ( & V_20 ) ;
}
return 0 ;
}
static int T_1 F_14 ( void )
{
int V_21 ;
V_5 = F_12 ( L_2 ) ;
if ( ! V_5 )
return - V_22 ;
V_12 = F_15 ( 1 ) ;
if ( ! V_12 )
return - V_23 ;
F_16 ( & V_24 ) ;
V_12 -> V_25 = L_1 ;
V_12 -> V_26 = L_1 ;
V_12 -> type = V_27 ;
V_12 -> V_28 = V_29 ;
V_12 -> V_30 = V_31 ;
V_12 -> V_10 = V_32 ;
F_17 ( V_12 , & V_33 ) ;
F_18 ( & V_24 , V_12 , 0 ) ;
V_21 = F_19 ( V_12 ) ;
if ( V_21 ) {
F_20 ( L_3 ) ;
F_21 ( V_12 ) ;
F_22 ( & V_24 ) ;
return V_21 ;
}
if ( ! ( V_20 . V_10 & V_11 ) )
F_13 ( & V_20 ) ;
return 0 ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_20 ) ;
F_25 ( V_12 ) ;
F_21 ( V_12 ) ;
F_22 ( & V_24 ) ;
}
