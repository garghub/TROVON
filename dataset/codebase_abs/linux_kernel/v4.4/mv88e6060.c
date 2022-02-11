static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
if ( V_6 == NULL )
return - V_8 ;
return F_3 ( V_6 , V_2 -> V_9 -> V_10 + V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
if ( V_6 == NULL )
return - V_8 ;
return F_5 ( V_6 , V_2 -> V_9 -> V_10 + V_3 , V_4 , V_11 ) ;
}
static char * F_6 ( struct V_12 * V_13 , int V_10 )
{
struct V_5 * V_6 = F_2 ( V_13 ) ;
int V_14 ;
if ( V_6 == NULL )
return NULL ;
V_14 = F_7 ( V_6 , V_10 + F_8 ( 0 ) , V_15 ) ;
if ( V_14 >= 0 ) {
if ( V_14 == V_16 )
return L_1 ;
if ( V_14 == V_17 ||
V_14 == V_18 )
return L_2 ;
if ( ( V_14 & V_19 ) == V_16 )
return L_3 ;
}
return NULL ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_20 ;
int V_14 ;
unsigned long V_21 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
V_14 = F_10 ( F_8 ( V_20 ) , V_23 ) ;
F_11 ( F_8 ( V_20 ) , V_23 ,
V_14 & ~ V_24 ) ;
}
F_12 ( 2000 , 4000 ) ;
F_11 ( V_25 , V_26 ,
V_27 |
V_28 |
V_29 ) ;
V_21 = V_30 + 1 * V_31 ;
while ( F_13 ( V_30 , V_21 ) ) {
V_14 = F_10 ( V_25 , V_32 ) ;
if ( V_14 & V_33 )
break;
F_12 ( 1000 , 2000 ) ;
}
if ( F_14 ( V_30 , V_21 ) )
return - V_34 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_11 ( V_25 , V_35 , V_36 ) ;
F_11 ( V_25 , V_26 ,
V_28 |
V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_37 )
{
int V_3 = F_8 ( V_37 ) ;
F_11 ( V_3 , V_23 ,
F_17 ( V_2 , V_37 ) ?
V_38 |
V_39 |
V_40 :
V_40 ) ;
F_11 ( V_3 , V_41 ,
( ( V_37 & 0xf ) << V_42 ) |
( F_17 ( V_2 , V_37 ) ?
V_2 -> V_43 :
F_18 ( V_2 -> V_44 -> V_45 ) ) ) ;
F_11 ( V_3 , V_46 , F_18 ( V_37 ) ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_20 ;
int V_14 ;
V_14 = F_9 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_15 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
V_14 = F_16 ( V_2 , V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_2 * V_3 )
{
F_11 ( V_25 , V_47 , ( V_3 [ 0 ] << 9 ) | V_3 [ 1 ] ) ;
F_11 ( V_25 , V_48 , ( V_3 [ 2 ] << 8 ) | V_3 [ 3 ] ) ;
F_11 ( V_25 , V_49 , ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ) ;
return 0 ;
}
static int F_21 ( int V_50 )
{
if ( V_50 >= 0 && V_50 < V_22 )
return V_50 ;
return - 1 ;
}
static int F_22 ( struct V_1 * V_2 , int V_50 , int V_51 )
{
int V_3 ;
V_3 = F_21 ( V_50 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_1 ( V_2 , V_3 , V_51 ) ;
}
static int
F_23 ( struct V_1 * V_2 , int V_50 , int V_51 , T_1 V_11 )
{
int V_3 ;
V_3 = F_21 ( V_50 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_4 ( V_2 , V_3 , V_51 , V_11 ) ;
}
static int T_3 F_24 ( void )
{
F_25 ( & V_52 ) ;
return 0 ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_52 ) ;
}
