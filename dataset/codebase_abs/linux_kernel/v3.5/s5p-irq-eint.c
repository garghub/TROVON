static inline void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( F_3 ( F_4 ( V_2 -> V_4 ) ) ) ;
V_3 |= F_5 ( V_2 -> V_4 ) ;
F_6 ( V_3 , F_3 ( F_4 ( V_2 -> V_4 ) ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( F_3 ( F_4 ( V_2 -> V_4 ) ) ) ;
V_3 &= ~ ( F_5 ( V_2 -> V_4 ) ) ;
F_6 ( V_3 , F_3 ( F_4 ( V_2 -> V_4 ) ) ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_6 ( F_5 ( V_2 -> V_4 ) ,
F_9 ( F_4 ( V_2 -> V_4 ) ) ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int type )
{
int V_5 = F_12 ( V_2 -> V_4 ) ;
int V_6 ;
T_1 V_7 , V_3 ;
T_1 V_8 = 0 ;
switch ( type ) {
case V_9 :
V_8 = V_10 ;
break;
case V_11 :
V_8 = V_12 ;
break;
case V_13 :
V_8 = V_14 ;
break;
case V_15 :
V_8 = V_16 ;
break;
case V_17 :
V_8 = V_18 ;
break;
default:
F_13 ( V_19 L_1 , type ) ;
return - V_20 ;
}
V_6 = ( V_5 & 0x7 ) * 4 ;
V_3 = 0x7 << V_6 ;
V_7 = F_2 ( F_14 ( F_4 ( V_2 -> V_4 ) ) ) ;
V_7 &= ~ V_3 ;
V_7 |= V_8 << V_6 ;
F_6 ( V_7 , F_14 ( F_4 ( V_2 -> V_4 ) ) ) ;
if ( ( 0 <= V_5 ) && ( V_5 < 8 ) )
F_15 ( F_16 ( V_5 & 0x7 ) , V_21 ) ;
else if ( ( 8 <= V_5 ) && ( V_5 < 16 ) )
F_15 ( F_17 ( V_5 & 0x7 ) , V_21 ) ;
else if ( ( 16 <= V_5 ) && ( V_5 < 24 ) )
F_15 ( F_18 ( V_5 & 0x7 ) , V_21 ) ;
else if ( ( 24 <= V_5 ) && ( V_5 < 32 ) )
F_15 ( F_19 ( V_5 & 0x7 ) , V_21 ) ;
else
F_13 ( V_19 L_2 , V_5 ) ;
return 0 ;
}
static inline void F_20 ( unsigned int V_22 )
{
T_1 V_23 = F_2 ( F_9 ( F_4 ( V_22 ) ) ) ;
T_1 V_3 = F_2 ( F_3 ( F_4 ( V_22 ) ) ) ;
unsigned int V_4 ;
V_23 &= ~ V_3 ;
V_23 &= 0xff ;
while ( V_23 ) {
V_4 = F_21 ( V_23 ) - 1 ;
F_22 ( V_4 + V_22 ) ;
V_23 &= ~ ( 1 << V_4 ) ;
}
}
static void F_23 ( unsigned int V_4 , struct V_24 * V_25 )
{
F_20 ( F_24 ( 16 ) ) ;
F_20 ( F_24 ( 24 ) ) ;
}
static inline void F_25 ( struct V_1 * V_2 )
{
void T_2 * V_26 = F_26 ( V_2 ) ;
F_1 ( V_2 ) ;
F_27 ( 1 << F_12 ( V_2 -> V_4 ) , V_26 + V_27 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
void T_2 * V_26 = F_26 ( V_2 ) ;
F_7 ( V_2 ) ;
F_27 ( 1 << F_12 ( V_2 -> V_4 ) , V_26 + V_28 ) ;
}
static inline void F_29 ( struct V_1 * V_2 )
{
F_6 ( F_5 ( V_2 -> V_4 ) ,
F_9 ( F_4 ( V_2 -> V_4 ) ) ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_29 ( V_2 ) ;
}
static int T_3 F_31 ( void )
{
int V_4 ;
for ( V_4 = F_24 ( 0 ) ; V_4 <= F_24 ( 15 ) ; V_4 ++ )
F_32 ( V_4 , & V_29 ) ;
for ( V_4 = F_24 ( 16 ) ; V_4 <= F_24 ( 31 ) ; V_4 ++ ) {
F_33 ( V_4 , & V_30 , V_31 ) ;
F_34 ( V_4 , V_32 ) ;
}
F_35 ( V_33 , F_23 ) ;
return 0 ;
}
