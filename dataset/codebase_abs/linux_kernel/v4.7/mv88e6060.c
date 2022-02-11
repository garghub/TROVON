static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 -> V_7 , V_6 -> V_8 + V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 -> V_7 , V_6 -> V_8 + V_3 , V_4 , V_9 ) ;
}
static const char * F_6 ( struct V_10 * V_7 , int V_8 )
{
int V_11 ;
V_11 = F_7 ( V_7 , V_8 + F_8 ( 0 ) , V_12 ) ;
if ( V_11 >= 0 ) {
if ( V_11 == V_13 )
return L_1 ;
if ( V_11 == V_14 ||
V_11 == V_15 )
return L_2 ;
if ( ( V_11 & V_16 ) == V_13 )
return L_3 ;
}
return NULL ;
}
static const char * F_9 ( struct V_17 * V_18 ,
struct V_17 * V_19 , int V_8 ,
void * * V_20 )
{
struct V_10 * V_7 = F_10 ( V_19 ) ;
struct V_5 * V_6 ;
const char * V_21 ;
V_21 = F_6 ( V_7 , V_8 ) ;
if ( V_21 ) {
V_6 = F_11 ( V_18 , sizeof( * V_6 ) , V_22 ) ;
if ( ! V_6 )
return NULL ;
* V_20 = V_6 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_8 = V_8 ;
}
return V_21 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_23 ;
int V_11 ;
unsigned long V_24 ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
V_11 = F_13 ( F_8 ( V_23 ) , V_26 ) ;
F_14 ( F_8 ( V_23 ) , V_26 ,
V_11 & ~ V_27 ) ;
}
F_15 ( 2000 , 4000 ) ;
F_14 ( V_28 , V_29 ,
V_30 |
V_31 |
V_32 ) ;
V_24 = V_33 + 1 * V_34 ;
while ( F_16 ( V_33 , V_24 ) ) {
V_11 = F_13 ( V_28 , V_35 ) ;
if ( V_11 & V_36 )
break;
F_15 ( 1000 , 2000 ) ;
}
if ( F_17 ( V_33 , V_24 ) )
return - V_37 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_14 ( V_28 , V_38 , V_39 ) ;
F_14 ( V_28 , V_29 ,
V_31 |
V_32 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_40 )
{
int V_3 = F_8 ( V_40 ) ;
F_14 ( V_3 , V_26 ,
F_20 ( V_2 , V_40 ) ?
V_41 |
V_42 |
V_43 :
V_43 ) ;
F_14 ( V_3 , V_44 ,
( ( V_40 & 0xf ) << V_45 ) |
( F_20 ( V_2 , V_40 ) ?
V_2 -> V_46 :
F_21 ( V_2 -> V_47 -> V_48 ) ) ) ;
F_14 ( V_3 , V_49 , F_21 ( V_40 ) ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_11 ;
int V_23 ;
V_11 = F_12 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_18 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
V_11 = F_19 ( V_2 , V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 * V_3 )
{
F_14 ( V_28 , V_50 , ( V_3 [ 0 ] << 9 ) | V_3 [ 1 ] ) ;
F_14 ( V_28 , V_51 , ( V_3 [ 2 ] << 8 ) | V_3 [ 3 ] ) ;
F_14 ( V_28 , V_52 , ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ) ;
return 0 ;
}
static int F_24 ( int V_53 )
{
if ( V_53 >= 0 && V_53 < V_25 )
return V_53 ;
return - 1 ;
}
static int F_25 ( struct V_1 * V_2 , int V_53 , int V_54 )
{
int V_3 ;
V_3 = F_24 ( V_53 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_1 ( V_2 , V_3 , V_54 ) ;
}
static int
F_26 ( struct V_1 * V_2 , int V_53 , int V_54 , T_1 V_9 )
{
int V_3 ;
V_3 = F_24 ( V_53 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_4 ( V_2 , V_3 , V_54 , V_9 ) ;
}
static int T_3 F_27 ( void )
{
F_28 ( & V_55 ) ;
return 0 ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_55 ) ;
}
