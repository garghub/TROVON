static inline void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 < ( V_4 + 32 ) )
F_2 ( V_5 , 1 << ( V_3 - V_4 ) ) ;
else
F_2 ( V_6 , 1 << ( V_3 - V_4 - 32 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 < ( V_4 + 32 ) )
F_2 ( V_7 , 1 << ( V_3 - V_4 ) ) ;
else
F_2 ( V_8 , 1 << ( V_3 - V_4 - 32 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
if ( ! V_9 )
F_2 ( V_10 , 0 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
F_1 ( V_2 ) ;
if ( ! V_9 )
F_2 ( V_10 , 0 ) ;
else {
T_1 V_11 ;
F_6 ( V_12 + V_3 * 8 , V_11 ) ;
F_2 ( V_12 + V_3 * 8 , V_11 | ~ V_13 ) ;
F_2 ( V_12 + V_3 * 8 , V_11 ) ;
}
}
void F_7 ( void )
{
unsigned int V_3 ;
F_6 ( V_14 , V_3 ) ;
if ( V_3 < 64 )
F_8 ( V_3 + V_4 ) ;
else {
}
}
static void F_9 ( int V_3 , int V_15 )
{
F_2 ( V_16 ,
( V_3 << V_17 ) | ( V_15 << V_18 ) ) ;
}
void T_2 F_10 ( unsigned long V_19 , unsigned int V_20 , T_3 * V_21 , int V_22 )
{
V_23 = ( unsigned long ) F_11 ( V_19 , 0x40000 ) ;
F_2 ( V_24 , V_25 ) ;
V_26 = & F_9 ;
for (; V_22 > 0 ; V_22 -- , V_21 ++ ) {
int V_27 = V_21 -> V_28 ;
switch ( V_21 -> V_29 ) {
case V_30 :
F_12 ( V_20 + V_27 ,
& V_31 ,
V_32 ,
L_1 ) ;
if ( V_9 )
F_2 ( V_12 + V_27 * 8 , V_13 ) ;
else
F_2 ( V_12 + V_27 * 8 , V_13 | V_21 -> V_33 ) ;
break;
case V_34 :
F_12 ( V_20 + V_27 ,
& V_35 ,
V_36 ,
L_2 ) ;
if ( V_9 )
F_2 ( V_12 + V_27 * 8 , 0 ) ;
else
F_2 ( V_12 + V_27 * 8 , V_21 -> V_33 ) ;
}
}
V_4 = V_20 ;
F_2 ( V_37 , V_38 ) ;
}
