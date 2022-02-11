static void F_1 ( struct V_1 * V_2 , void T_1 * V_3 ,
void T_1 * V_4 , T_2 V_5 )
{
unsigned int V_6 ;
V_6 = F_2 ( V_3 ) ;
V_6 &= ~ F_3 ( 0 ) ;
F_4 ( V_6 , V_3 ) ;
V_6 = F_5 ( V_5 ) | F_6 ( 1 ) | F_7 ( 4 ) |
F_8 ( 1 ) | F_9 ( 3 ) | F_10 ( 1 ) ;
F_4 ( V_6 , V_4 + V_7 ) ;
}
static T_2 F_11 ( unsigned long V_8 )
{
T_2 V_9 = 1500000000 , V_10 ;
F_12 ( ( V_8 % 10 ) != 0 , L_1 ) ;
V_10 = V_9 / ( V_8 / 10 ) ;
switch ( V_10 ) {
case 50 :
return 0x1 ;
case 60 :
return 0x2 ;
case 80 :
return 0x4 ;
case 100 :
return 0x5 ;
case 120 :
return 0x6 ;
case 125 :
return 0x7 ;
case 150 :
return 0x8 ;
case 200 :
return 0x9 ;
case 250 :
return 0xa ;
default:
return 0 ;
}
}
static int F_13 ( struct V_11 * V_12 ,
unsigned int * V_13 , unsigned long V_14 )
{
int V_15 , V_16 ;
V_15 = F_14 ( V_12 ) ;
V_16 = F_15 ( V_12 , V_13 , V_15 , V_14 , V_17 ) ;
if ( V_15 && V_16 == - V_18 )
return F_15 ( V_12 , V_13 , 0 ,
V_14 , V_17 ) ;
return V_16 ;
}
static int F_16 ( struct V_11 * V_12 ,
unsigned int * V_13 , unsigned long V_14 )
{
int V_16 , V_19 = V_20 ;
bool V_21 ;
do {
V_16 = F_17 ( V_12 , V_13 , V_14 , & V_21 ) ;
if ( V_21 )
return V_16 ;
} while ( V_19 -- );
return V_16 ;
}
static int F_18 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = & V_23 -> V_2 ;
struct V_24 * V_25 ;
void T_1 * V_3 ;
struct V_26 * V_27 ;
struct V_28 * V_28 ;
T_2 V_5 ;
int V_29 ;
V_25 = F_19 ( V_23 ) ;
if ( F_20 ( V_25 ) )
return F_21 ( V_25 ) ;
if ( ! V_25 -> V_30 [ 0 ] ) {
V_28 = F_22 ( V_2 , L_2 ) ;
if ( F_20 ( V_28 ) )
return F_21 ( V_28 ) ;
V_25 -> V_30 [ 0 ] = V_28 ;
}
if ( ! V_25 -> V_30 [ 1 ] ) {
V_28 = F_22 ( V_2 , L_3 ) ;
if ( F_20 ( V_28 ) ) {
F_23 ( V_2 , L_4 ) ;
return - V_31 ;
}
V_25 -> V_30 [ 1 ] = V_28 ;
}
V_5 = F_11 ( F_24 ( V_25 -> V_30 [ 1 ] ) ) ;
if ( V_5 == 0 ) {
F_23 ( V_2 , L_5 , V_5 ) ;
return - V_32 ;
}
V_29 = F_25 ( V_25 ) ;
if ( V_29 )
return V_29 ;
V_27 = F_26 ( V_23 , V_33 , 1 ) ;
if ( ! V_27 ) {
V_29 = - V_31 ;
goto V_34;
}
V_3 = F_27 ( V_2 , V_27 -> V_35 , F_28 ( V_27 ) ) ;
if ( ! V_3 ) {
V_29 = - V_36 ;
goto V_34;
}
F_1 ( V_2 , V_3 , V_25 -> V_37 , V_5 ) ;
V_29 = F_29 ( V_23 , V_25 , & V_38 ,
& V_39 ) ;
if ( V_29 )
goto V_34;
return 0 ;
V_34:
F_30 ( V_25 ) ;
return V_29 ;
}
