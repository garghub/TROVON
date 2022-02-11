inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + ( V_3 << 2 ) ) ;
}
inline T_1 F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_4 ( V_2 -> V_5 + ( V_3 << 2 ) ) ;
}
void F_5 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , V_8 ) ;
if ( V_6 )
V_7 |= V_9 ;
else
V_7 &= ~ V_9 ;
F_1 ( V_2 , V_8 , V_7 ) ;
}
int F_6 ( struct V_1 * V_2 , int V_6 ,
int V_10 )
{
unsigned long V_11 ;
int V_12 ;
V_11 = V_13 + F_7 ( V_10 ) ;
for (; ; ) {
V_12 = F_3 ( V_2 , V_14 ) & V_15 ;
if ( V_6 ) {
if ( V_12 )
return 0 ;
} else {
if ( ! V_12 )
return 0 ;
}
if ( F_8 ( V_13 , V_11 ) )
return - V_16 ;
F_9 ( 1 ) ;
}
}
void F_10 ( struct V_1 * V_2 , int V_17 , T_1 V_18 )
{
T_1 V_19 , V_7 ;
V_19 = F_3 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_20 , 0xbf ) ;
V_7 = F_3 ( V_2 , V_21 ) ;
if ( V_17 )
V_7 |= V_18 ;
else
V_7 &= ~ V_18 ;
F_1 ( V_2 , V_21 , V_7 ) ;
F_1 ( V_2 , V_20 , V_19 ) ;
}
void F_11 ( struct V_1 * V_2 , int V_17 , T_1 V_18 )
{
unsigned long V_22 ;
F_12 ( & V_2 -> V_23 , V_22 ) ;
F_10 ( V_2 , V_17 , V_18 ) ;
F_13 ( & V_2 -> V_23 , V_22 ) ;
}
void F_14 ( struct V_1 * V_2 , unsigned long V_24 )
{
unsigned int V_25 ;
T_1 V_19 , V_26 ;
F_15 ( L_1 , V_24 ) ;
if ( V_24 >= 460800 ) {
V_25 = V_27 / 13 / V_24 ;
V_26 = 3 ;
} else {
V_25 = V_27 / 16 / V_24 ;
V_26 = 0 ;
}
F_1 ( V_2 , V_28 , 7 ) ;
V_19 = F_3 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_20 , V_29 ) ;
F_1 ( V_2 , V_30 , V_25 & 0xff ) ;
F_1 ( V_2 , V_31 , V_25 >> 8 ) ;
F_1 ( V_2 , V_20 , V_19 ) ;
F_1 ( V_2 , V_28 , V_26 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
F_1 ( V_2 , V_33 , V_34 ) ;
while ( ! ( F_3 ( V_2 , V_35 ) & V_36 ) ) {
if ( V_32 ++ > 100 ) {
F_17 ( V_2 -> V_37 , L_2 ) ;
return - V_38 ;
}
F_18 ( 1 ) ;
}
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
V_19 = F_3 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_20 , 0xBF ) ;
V_2 -> V_39 = F_3 ( V_2 , V_30 ) ;
V_2 -> V_40 = F_3 ( V_2 , V_31 ) ;
V_2 -> V_41 = F_3 ( V_2 , V_21 ) ;
F_1 ( V_2 , V_20 , V_19 ) ;
V_2 -> V_26 = F_3 ( V_2 , V_28 ) ;
V_2 -> V_42 = F_3 ( V_2 , V_43 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
T_2 V_19 = 0 ;
F_21 ( V_2 ) ;
F_1 ( V_2 , V_28 , 7 ) ;
V_19 = F_3 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_20 , 0xBF ) ;
F_1 ( V_2 , V_30 , V_2 -> V_39 ) ;
F_1 ( V_2 , V_31 , V_2 -> V_40 ) ;
F_1 ( V_2 , V_21 , V_2 -> V_41 ) ;
F_1 ( V_2 , V_20 , V_19 ) ;
F_1 ( V_2 , V_28 , V_2 -> V_26 ) ;
F_1 ( V_2 , V_43 , V_2 -> V_42 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
T_1 V_44 , V_41 ;
F_1 ( V_2 , V_28 , 0x00 ) ;
F_1 ( V_2 , V_20 , 0xbf ) ;
V_41 = F_3 ( V_2 , V_21 ) ;
F_1 ( V_2 , V_21 , V_45 ) ;
F_1 ( V_2 , V_20 , V_29 ) ;
V_44 = F_3 ( V_2 , V_8 ) ;
F_1 ( V_2 , V_8 , V_46 ) ;
F_1 ( V_2 , V_47 , V_48 |
V_49 | V_50 |
( 3 << 6 ) | ( 0 << 4 ) ) ;
F_1 ( V_2 , V_20 , 0xbf ) ;
F_1 ( V_2 , V_51 , 0xed ) ;
F_1 ( V_2 , V_52 , 0xef ) ;
F_1 ( V_2 , V_21 , V_41 ) ;
F_1 ( V_2 , V_20 , V_29 ) ;
F_1 ( V_2 , V_8 , 0x00 ) ;
F_1 ( V_2 , V_20 , V_53 ) ;
F_1 ( V_2 , V_43 , V_54 ) ;
F_1 ( V_2 , V_33 , ( 1 << 0 ) | ( 1 << 2 ) | ( 2 << 3 ) ) ;
}
