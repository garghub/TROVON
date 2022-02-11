static T_1 T_2 F_1 ( void )
{
return - F_2 ( V_1 + V_2 ) ;
}
static int T_3 F_3 ( unsigned long V_3 ,
void T_4 * V_4 )
{
T_5 V_5 = V_6 | V_7 ;
unsigned long V_8 = V_3 ;
int V_9 ;
if ( V_8 >= 1500000 ) {
V_8 /= 16 ;
V_5 |= V_10 ;
}
F_4 ( 0xffff , V_4 + V_11 ) ;
F_4 ( V_5 , V_4 + V_12 ) ;
V_9 = F_5 ( V_4 + V_2 , L_1 ,
V_8 , 200 , 16 , V_13 ) ;
if ( V_9 )
return V_9 ;
V_1 = V_4 ;
F_6 ( F_1 , 16 , V_8 ) ;
return 0 ;
}
static T_6 F_7 ( int V_14 , void * V_15 )
{
struct V_16 * V_17 = V_15 ;
F_4 ( 1 , V_18 + V_19 ) ;
V_17 -> V_20 ( V_17 ) ;
return V_21 ;
}
static int F_8 ( struct V_16 * V_17 )
{
T_5 V_5 = F_2 ( V_18 + V_12 ) & ~ V_6 ;
F_4 ( V_5 , V_18 + V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_16 * V_17 )
{
T_5 V_5 = F_2 ( V_18 + V_12 ) &
~ ( V_6 | V_7 ) ;
F_4 ( V_5 , V_18 + V_12 ) ;
return 0 ;
}
static int F_10 ( struct V_16 * V_17 )
{
T_5 V_5 = F_2 ( V_18 + V_12 ) & ~ V_6 ;
F_4 ( V_5 , V_18 + V_12 ) ;
F_4 ( V_22 , V_18 + V_11 ) ;
V_5 |= V_7 | V_6 ;
F_4 ( V_5 , V_18 + V_12 ) ;
return 0 ;
}
static int F_11 ( unsigned long V_23 , struct V_16 * V_17 )
{
unsigned long V_5 = F_2 ( V_18 + V_12 ) ;
F_4 ( V_5 & ~ V_6 , V_18 + V_12 ) ;
F_4 ( V_23 , V_18 + V_11 ) ;
F_4 ( V_5 | V_6 , V_18 + V_12 ) ;
return 0 ;
}
static int F_12 ( unsigned long V_3 ,
void T_4 * V_4 , int V_14 )
{
unsigned long V_8 = V_3 ;
unsigned int V_5 = 0 ;
int V_9 ;
V_18 = V_4 ;
if ( V_8 > 0x100000 * V_24 ) {
V_8 /= 256 ;
V_5 |= V_25 ;
} else if ( V_8 > 0x10000 * V_24 ) {
V_8 /= 16 ;
V_5 |= V_10 ;
}
V_22 = V_8 / V_24 ;
F_4 ( V_5 , V_18 + V_12 ) ;
V_9 = F_13 ( V_14 , & V_26 ) ;
if ( V_9 )
return V_9 ;
F_14 ( & V_27 ,
V_8 ,
1 ,
0xffffU ) ;
return 0 ;
}
static int T_3 F_15 ( struct V_28 * V_29 )
{
const char * V_30 ;
void T_4 * V_4 ;
int V_31 ;
int V_14 ;
struct V_32 * V_32 ;
unsigned long V_8 ;
struct V_28 * V_33 ;
struct V_28 * V_34 ;
V_4 = F_16 ( V_29 , 0 , L_2 ) ;
if ( F_17 ( V_4 ) )
return F_18 ( V_4 ) ;
V_32 = F_19 ( V_29 , 0 ) ;
if ( F_17 ( V_32 ) ) {
F_20 ( L_3 , V_29 -> V_35 ) ;
return F_18 ( V_32 ) ;
}
F_21 ( V_32 ) ;
V_8 = F_22 ( V_32 ) ;
F_4 ( 0 , V_4 + V_12 ) ;
V_31 = F_23 ( V_36 ,
L_4 , & V_30 ) ;
if ( V_31 ) {
F_24 ( L_5 ) ;
return V_31 ;
}
V_33 = F_25 ( V_30 ) ;
V_31 = F_23 ( V_36 ,
L_6 , & V_30 ) ;
if ( V_31 ) {
F_24 ( L_5 ) ;
return V_31 ;
}
V_34 = F_25 ( V_30 ) ;
if ( V_29 == V_33 )
return F_3 ( V_8 , V_4 ) ;
if ( V_29 == V_34 ) {
V_14 = F_26 ( V_29 , 0 ) ;
return F_12 ( V_8 , V_4 , V_14 ) ;
}
F_27 ( L_7 , V_4 ) ;
F_28 ( V_32 ) ;
return 0 ;
}
