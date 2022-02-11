static inline void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 |= ( T_1 ) V_2 -> V_5 ;
F_3 ( V_3 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 &= ~ ( ( T_1 ) V_2 -> V_5 ) ;
F_3 ( V_3 , V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_3 ( ( T_1 ) V_2 -> V_5 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int type )
{
int V_7 = F_8 ( V_2 -> V_8 ) ;
int V_9 , V_10 ;
int V_11 ;
T_1 V_12 , V_3 ;
T_1 V_13 = 0 ;
void T_2 * V_14 ;
if ( V_7 > 27 )
return - V_15 ;
if ( V_7 <= 15 )
V_14 = V_16 ;
else
V_14 = V_17 ;
switch ( type ) {
case V_18 :
F_9 ( V_19 L_1 ) ;
break;
case V_20 :
V_13 = V_21 ;
break;
case V_22 :
V_13 = V_23 ;
break;
case V_24 :
V_13 = V_25 ;
break;
case V_26 :
V_13 = V_27 ;
break;
case V_28 :
V_13 = V_29 ;
break;
default:
F_9 ( V_30 L_2 , type ) ;
return - 1 ;
}
if ( V_7 <= 15 )
V_11 = ( V_7 / 2 ) * 4 ;
else
V_11 = ( ( V_7 - 16 ) / 2 ) * 4 ;
V_3 = 0x7 << V_11 ;
V_12 = F_2 ( V_14 ) ;
V_12 &= ~ V_3 ;
V_12 |= V_13 << V_11 ;
F_3 ( V_12 , V_14 ) ;
if ( V_7 < 16 ) {
V_9 = F_10 ( V_7 ) ;
V_10 = F_11 ( 2 ) ;
} else if ( V_7 < 23 ) {
V_9 = F_12 ( V_7 + 8 - 16 ) ;
V_10 = F_11 ( 3 ) ;
} else {
V_9 = F_13 ( V_7 - 23 ) ;
V_10 = F_11 ( 3 ) ;
}
F_14 ( V_9 , V_10 ) ;
return 0 ;
}
static inline void F_15 ( unsigned int V_31 , unsigned int V_32 )
{
T_1 V_33 = F_2 ( V_6 ) ;
T_1 V_3 = F_2 ( V_4 ) ;
unsigned int V_8 ;
V_33 &= ~ V_3 ;
V_33 >>= V_31 ;
V_33 &= ( 1 << ( V_32 - V_31 + 1 ) ) - 1 ;
for ( V_8 = F_16 ( V_31 ) ; V_8 <= F_16 ( V_32 ) ; V_8 ++ ) {
if ( V_33 & 1 )
F_17 ( V_8 ) ;
V_33 >>= 1 ;
}
}
static void F_18 ( unsigned int V_8 , struct V_34 * V_35 )
{
F_15 ( 0 , 3 ) ;
}
static void F_19 ( unsigned int V_8 , struct V_34 * V_35 )
{
F_15 ( 4 , 11 ) ;
}
static void F_20 ( unsigned int V_8 , struct V_34 * V_35 )
{
F_15 ( 12 , 19 ) ;
}
static void F_21 ( unsigned int V_8 , struct V_34 * V_35 )
{
F_15 ( 20 , 27 ) ;
}
static int T_3 F_22 ( void )
{
int V_8 ;
for ( V_8 = F_16 ( 0 ) ; V_8 <= F_16 ( 27 ) ; V_8 ++ ) {
F_23 ( V_8 , & V_36 , V_37 ) ;
F_24 ( V_8 , ( void * ) F_25 ( V_8 ) ) ;
F_26 ( V_8 , V_38 ) ;
}
F_27 ( V_39 , F_18 ) ;
F_27 ( V_40 , F_19 ) ;
F_27 ( V_41 , F_20 ) ;
F_27 ( V_42 , F_21 ) ;
return 0 ;
}
