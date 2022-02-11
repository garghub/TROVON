static T_1 T_2 F_1 ( void )
{
return - F_2 ( V_1 + V_2 ) ;
}
static void F_3 ( unsigned long V_3 ,
void T_3 * V_4 )
{
T_4 V_5 = V_6 | V_7 ;
unsigned long V_8 = V_3 ;
if ( V_8 >= 1500000 ) {
V_8 /= 16 ;
V_5 |= V_9 ;
}
F_4 ( 0xffff , V_4 + V_10 ) ;
F_4 ( V_5 , V_4 + V_11 ) ;
F_5 ( V_4 + V_2 , L_1 ,
V_8 , 200 , 16 , V_12 ) ;
V_1 = V_4 ;
F_6 ( F_1 , 16 , V_8 ) ;
}
static T_5 F_7 ( int V_13 , void * V_14 )
{
struct V_15 * V_16 = V_14 ;
F_4 ( 1 , V_17 + V_18 ) ;
V_16 -> V_19 ( V_16 ) ;
return V_20 ;
}
static int F_8 ( struct V_15 * V_16 )
{
T_4 V_5 = F_2 ( V_17 + V_11 ) & ~ V_6 ;
F_4 ( V_5 , V_17 + V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 )
{
T_4 V_5 = F_2 ( V_17 + V_11 ) &
~ ( V_6 | V_7 ) ;
F_4 ( V_5 , V_17 + V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_15 * V_16 )
{
T_4 V_5 = F_2 ( V_17 + V_11 ) & ~ V_6 ;
F_4 ( V_5 , V_17 + V_11 ) ;
F_4 ( V_21 , V_17 + V_10 ) ;
V_5 |= V_7 | V_6 ;
F_4 ( V_5 , V_17 + V_11 ) ;
return 0 ;
}
static int F_11 ( unsigned long V_22 , struct V_15 * V_16 )
{
unsigned long V_5 = F_2 ( V_17 + V_11 ) ;
F_4 ( V_5 & ~ V_6 , V_17 + V_11 ) ;
F_4 ( V_22 , V_17 + V_10 ) ;
F_4 ( V_5 | V_6 , V_17 + V_11 ) ;
return 0 ;
}
static void F_12 ( unsigned long V_3 ,
void T_3 * V_4 , int V_13 )
{
unsigned long V_8 = V_3 ;
unsigned int V_5 = 0 ;
V_17 = V_4 ;
if ( V_8 > 0x100000 * V_23 ) {
V_8 /= 256 ;
V_5 |= V_24 ;
} else if ( V_8 > 0x10000 * V_23 ) {
V_8 /= 16 ;
V_5 |= V_9 ;
}
V_21 = V_8 / V_23 ;
F_4 ( V_5 , V_17 + V_11 ) ;
F_13 ( V_13 , & V_25 ) ;
F_14 ( & V_26 ,
V_8 ,
1 ,
0xffffU ) ;
}
static void T_6 F_15 ( struct V_27 * V_28 )
{
const char * V_29 ;
void T_3 * V_4 ;
int V_30 ;
int V_13 ;
struct V_31 * V_31 ;
unsigned long V_8 ;
struct V_27 * V_32 ;
struct V_27 * V_33 ;
V_4 = F_16 ( V_28 , 0 , L_2 ) ;
if ( F_17 ( V_4 ) )
return;
V_31 = F_18 ( V_28 , 0 ) ;
if ( F_17 ( V_31 ) ) {
F_19 ( L_3 , V_28 -> V_34 ) ;
return;
}
F_20 ( V_31 ) ;
V_8 = F_21 ( V_31 ) ;
F_4 ( 0 , V_4 + V_11 ) ;
V_30 = F_22 ( V_35 ,
L_4 , & V_29 ) ;
if ( F_23 ( V_30 ) )
return;
V_32 = F_24 ( V_29 ) ;
V_30 = F_22 ( V_35 ,
L_5 , & V_29 ) ;
if ( F_23 ( V_30 ) )
return;
V_33 = F_24 ( V_29 ) ;
if ( V_28 == V_32 ) {
F_3 ( V_8 , V_4 ) ;
return;
}
if ( V_28 == V_33 ) {
V_13 = F_25 ( V_28 , 0 ) ;
F_12 ( V_8 , V_4 , V_13 ) ;
return;
}
F_26 ( L_6 , V_4 ) ;
F_27 ( V_31 ) ;
}
