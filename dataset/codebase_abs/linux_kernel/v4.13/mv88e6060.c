static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
return F_2 ( V_6 -> V_7 , V_6 -> V_8 + V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_9 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
return F_4 ( V_6 -> V_7 , V_6 -> V_8 + V_3 , V_4 , V_9 ) ;
}
static const char * F_5 ( struct V_10 * V_7 , int V_8 )
{
int V_11 ;
V_11 = F_6 ( V_7 , V_8 + F_7 ( 0 ) , V_12 ) ;
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
static enum V_17 F_8 ( struct V_1 * V_2 )
{
return V_18 ;
}
static const char * F_9 ( struct V_19 * V_20 ,
struct V_19 * V_21 , int V_8 ,
void * * V_22 )
{
struct V_10 * V_7 = F_10 ( V_21 ) ;
struct V_5 * V_6 ;
const char * V_23 ;
V_23 = F_5 ( V_7 , V_8 ) ;
if ( V_23 ) {
V_6 = F_11 ( V_20 , sizeof( * V_6 ) , V_24 ) ;
if ( ! V_6 )
return NULL ;
* V_22 = V_6 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_8 = V_8 ;
}
return V_23 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_25 ;
int V_11 ;
unsigned long V_26 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
V_11 = F_13 ( F_7 ( V_25 ) , V_28 ) ;
F_14 ( F_7 ( V_25 ) , V_28 ,
V_11 & ~ V_29 ) ;
}
F_15 ( 2000 , 4000 ) ;
F_14 ( V_30 , V_31 ,
V_32 |
V_33 |
V_34 ) ;
V_26 = V_35 + 1 * V_36 ;
while ( F_16 ( V_35 , V_26 ) ) {
V_11 = F_13 ( V_30 , V_37 ) ;
if ( V_11 & V_38 )
break;
F_15 ( 1000 , 2000 ) ;
}
if ( F_17 ( V_35 , V_26 ) )
return - V_39 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_14 ( V_30 , V_40 , V_41 ) ;
F_14 ( V_30 , V_31 ,
V_33 |
V_34 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_42 )
{
int V_3 = F_7 ( V_42 ) ;
F_14 ( V_3 , V_28 ,
F_20 ( V_2 , V_42 ) ?
V_43 |
V_44 |
V_45 :
V_45 ) ;
F_14 ( V_3 , V_46 ,
( ( V_42 & 0xf ) << V_47 ) |
( F_20 ( V_2 , V_42 ) ?
V_2 -> V_48 :
F_21 ( V_2 -> V_49 -> V_50 -> V_51 ) ) ) ;
F_14 ( V_3 , V_52 , F_21 ( V_42 ) ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_11 ;
int V_25 ;
V_11 = F_12 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_18 ( V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
V_11 = F_19 ( V_2 , V_25 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 * V_3 )
{
F_14 ( V_30 , V_53 , ( V_3 [ 0 ] << 9 ) | V_3 [ 1 ] ) ;
F_14 ( V_30 , V_54 , ( V_3 [ 2 ] << 8 ) | V_3 [ 3 ] ) ;
F_14 ( V_30 , V_55 , ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ) ;
return 0 ;
}
static int F_24 ( int V_56 )
{
if ( V_56 >= 0 && V_56 < V_27 )
return V_56 ;
return - 1 ;
}
static int F_25 ( struct V_1 * V_2 , int V_56 , int V_57 )
{
int V_3 ;
V_3 = F_24 ( V_56 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_1 ( V_2 , V_3 , V_57 ) ;
}
static int
F_26 ( struct V_1 * V_2 , int V_56 , int V_57 , T_1 V_9 )
{
int V_3 ;
V_3 = F_24 ( V_56 ) ;
if ( V_3 == - 1 )
return 0xffff ;
return F_3 ( V_2 , V_3 , V_57 , V_9 ) ;
}
static int T_3 F_27 ( void )
{
F_28 ( & V_58 ) ;
return 0 ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_58 ) ;
}
