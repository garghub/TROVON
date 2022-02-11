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
static void F_8 ( enum V_21 V_22 , struct V_15 * V_16 )
{
T_4 V_5 = F_2 ( V_17 + V_11 ) & ~ V_6 ;
F_4 ( V_5 , V_17 + V_11 ) ;
switch ( V_22 ) {
case V_23 :
F_4 ( V_24 , V_17 + V_10 ) ;
V_5 |= V_7 | V_6 ;
F_4 ( V_5 , V_17 + V_11 ) ;
break;
case V_25 :
V_5 &= ~ V_7 ;
F_4 ( V_5 , V_17 + V_11 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
default:
break;
}
}
static int F_9 ( unsigned long V_29 , struct V_15 * V_16 )
{
unsigned long V_5 = F_2 ( V_17 + V_11 ) ;
F_4 ( V_5 & ~ V_6 , V_17 + V_11 ) ;
F_4 ( V_29 , V_17 + V_10 ) ;
F_4 ( V_5 | V_6 , V_17 + V_11 ) ;
return 0 ;
}
static void F_10 ( unsigned long V_3 ,
void T_3 * V_4 , int V_13 )
{
unsigned long V_8 = V_3 ;
unsigned int V_5 = 0 ;
V_17 = V_4 ;
if ( V_8 > 0x100000 * V_30 ) {
V_8 /= 256 ;
V_5 |= V_31 ;
} else if ( V_8 > 0x10000 * V_30 ) {
V_8 /= 16 ;
V_5 |= V_9 ;
}
V_24 = V_8 / V_30 ;
F_4 ( V_5 , V_17 + V_11 ) ;
F_11 ( V_13 , & V_32 ) ;
F_12 ( & V_33 ,
V_8 ,
1 ,
0xffffU ) ;
}
static void T_6 F_13 ( struct V_34 * V_35 )
{
const char * V_36 ;
void T_3 * V_4 ;
int V_37 ;
int V_13 ;
struct V_38 * V_38 ;
unsigned long V_8 ;
struct V_34 * V_39 ;
struct V_34 * V_40 ;
V_4 = F_14 ( V_35 , 0 , L_2 ) ;
if ( F_15 ( V_4 ) )
return;
V_38 = F_16 ( V_35 , 0 ) ;
if ( F_15 ( V_38 ) ) {
F_17 ( L_3 , V_35 -> V_41 ) ;
return;
}
F_18 ( V_38 ) ;
V_8 = F_19 ( V_38 ) ;
F_4 ( 0 , V_4 + V_11 ) ;
V_37 = F_20 ( V_42 ,
L_4 , & V_36 ) ;
if ( F_21 ( V_37 ) )
return;
V_39 = F_22 ( V_36 ) ;
V_37 = F_20 ( V_42 ,
L_5 , & V_36 ) ;
if ( F_21 ( V_37 ) )
return;
V_40 = F_22 ( V_36 ) ;
if ( V_35 == V_39 ) {
F_3 ( V_8 , V_4 ) ;
return;
}
if ( V_35 == V_40 ) {
V_13 = F_23 ( V_35 , 0 ) ;
F_10 ( V_8 , V_4 , V_13 ) ;
return;
}
F_24 ( L_6 , V_4 ) ;
F_25 ( V_38 ) ;
}
