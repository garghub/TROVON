static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned int V_11 ;
switch ( V_7 [ 0 ] ) {
case V_12 :
V_9 -> V_13 = V_14 ;
V_11 = V_7 [ 1 ] & V_4 -> V_15 ;
F_2 ( V_11 , V_9 -> V_16 + V_17 ) ;
F_3 ( V_2 -> V_18 , L_1 ,
20 * V_11 + 20 ) ;
break;
case V_19 :
V_9 -> V_13 = 0 ;
break;
default:
return - V_20 ;
}
F_2 ( V_9 -> V_13 , V_9 -> V_16 + V_21 ) ;
return V_6 -> V_22 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_6 -> V_22 ; V_23 ++ )
V_7 [ V_23 ] = F_5 ( V_9 -> V_16 + V_24 ) ;
return V_6 -> V_22 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
int V_23 ;
if ( V_9 -> V_13 == 0 ) {
F_7 ( V_2 -> V_18 , L_2 ) ;
return - V_20 ;
}
for ( V_23 = 0 ; V_23 < V_6 -> V_22 ; V_23 ++ ) {
F_2 ( V_9 -> V_13 | V_25 ,
V_9 -> V_16 + V_21 ) ;
}
return V_6 -> V_22 ;
}
void F_8 ( unsigned long V_16 )
{
F_2 ( 0x0 , V_16 + V_21 ) ;
F_2 ( 0x0 , V_16 + V_17 ) ;
}
int F_9 ( struct V_3 * V_4 , unsigned long V_16 )
{
struct V_8 * V_9 ;
V_9 = F_10 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
V_9 -> V_16 = V_16 ;
V_4 -> V_10 = V_9 ;
V_4 -> type = V_28 ;
V_4 -> V_29 = V_30 ;
V_4 -> V_31 = 1 ;
V_4 -> V_15 = 0xff ;
V_4 -> V_32 = F_1 ;
V_4 -> V_33 = F_4 ;
V_4 -> V_34 = F_6 ;
return 0 ;
}
static int T_1 F_11 ( void )
{
return 0 ;
}
static void T_2 F_12 ( void )
{
}
