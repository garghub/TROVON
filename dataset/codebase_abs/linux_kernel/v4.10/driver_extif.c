static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_5 )
{
F_4 ( V_2 -> V_4 , V_3 , V_5 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_6 , T_1 V_5 )
{
V_5 &= V_6 ;
V_5 |= F_1 ( V_2 , V_3 ) & ~ V_6 ;
F_3 ( V_2 , V_3 , V_5 ) ;
return V_5 ;
}
static bool F_6 ( T_3 * V_7 )
{
T_3 V_8 , V_9 = 0 ;
if ( V_7 ) {
V_8 = V_7 [ V_10 ] ;
V_7 [ V_10 ] = ( V_11 | V_12 | V_13 ) ;
V_9 = V_7 [ V_14 ] & ( V_15 | V_16
| V_17 | V_18 ) ;
V_7 [ V_10 ] = V_8 ;
}
return ( V_9 == ( V_15 | V_17 ) ) ;
}
int F_7 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
T_1 V_21 , V_22 = 0 ;
F_3 ( V_2 , V_23 , 0 ) ;
F_3 ( V_2 , V_24 , 0 ) ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
void T_4 * V_25 ;
V_25 = F_8 ( V_26 , 16 ) ;
if ( V_25 ) {
V_25 += ( V_21 * 8 ) ;
if ( F_6 ( V_25 ) && V_20 ) {
F_3 ( V_2 , V_24 , 2 ) ;
V_22 ++ ;
V_20 [ V_21 ] . V_7 = V_25 ;
V_20 [ V_21 ] . V_27 = 2 ;
V_20 [ V_21 ] . V_28 = 13500000 ;
V_20 [ V_21 ] . V_29 = 0 ;
}
F_9 ( V_25 ) ;
}
}
return V_22 ;
}
void F_10 ( struct V_1 * V_2 , unsigned long V_30 )
{
T_1 V_31 ;
F_3 ( V_2 , V_32 , V_33 ) ;
V_31 = F_11 ( 10 , V_30 ) << V_34 ;
V_31 |= F_11 ( 40 , V_30 ) << V_35 ;
V_31 |= F_11 ( 120 , V_30 ) ;
F_3 ( V_2 , V_36 , V_31 ) ;
V_31 = F_11 ( 10 , V_30 ) << V_34 ;
V_31 |= F_11 ( 20 , V_30 ) << V_37 ;
V_31 |= F_11 ( 100 , V_30 ) << V_35 ;
V_31 |= F_11 ( 120 , V_30 ) ;
F_3 ( V_2 , V_36 , V_31 ) ;
}
void F_12 ( struct V_1 * V_2 ,
T_1 * V_38 , T_1 * V_39 , T_1 * V_40 )
{
* V_38 = V_41 ;
* V_39 = F_1 ( V_2 , V_42 ) ;
* V_40 = F_1 ( V_2 , V_43 ) ;
}
T_1 F_13 ( struct V_44 * V_45 , T_1 V_46 )
{
struct V_1 * V_2 = F_14 ( V_45 ) ;
return F_15 ( V_2 , V_46 ) ;
}
T_1 F_16 ( struct V_44 * V_45 , T_1 V_47 )
{
struct V_1 * V_2 = F_14 ( V_45 ) ;
T_1 V_46 = ( V_48 / 1000 ) * V_47 ;
V_46 = F_15 ( V_2 , V_46 ) ;
return ( V_46 * 1000 ) / V_48 ;
}
T_1 F_15 ( struct V_1 * V_2 , T_1 V_46 )
{
if ( V_46 > V_49 )
V_46 = V_49 ;
F_3 ( V_2 , V_50 , V_46 ) ;
return V_46 ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return;
F_18 ( & V_2 -> V_51 ) ;
}
T_1 F_19 ( struct V_1 * V_2 , T_1 V_6 )
{
return F_1 ( V_2 , V_52 ) & V_6 ;
}
T_1 F_20 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_5 )
{
unsigned long V_53 ;
T_1 V_54 = 0 ;
F_21 ( & V_2 -> V_51 , V_53 ) ;
V_54 = F_5 ( V_2 , F_22 ( 0 ) ,
V_6 , V_5 ) ;
F_23 ( & V_2 -> V_51 , V_53 ) ;
return V_54 ;
}
T_1 F_24 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_5 )
{
unsigned long V_53 ;
T_1 V_54 = 0 ;
F_21 ( & V_2 -> V_51 , V_53 ) ;
V_54 = F_5 ( V_2 , F_25 ( 0 ) ,
V_6 , V_5 ) ;
F_23 ( & V_2 -> V_51 , V_53 ) ;
return V_54 ;
}
T_1 F_26 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_5 )
{
unsigned long V_53 ;
T_1 V_54 = 0 ;
F_21 ( & V_2 -> V_51 , V_53 ) ;
V_54 = F_5 ( V_2 , V_23 , V_6 , V_5 ) ;
F_23 ( & V_2 -> V_51 , V_53 ) ;
return V_54 ;
}
T_1 F_27 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_5 )
{
unsigned long V_53 ;
T_1 V_54 = 0 ;
F_21 ( & V_2 -> V_51 , V_53 ) ;
V_54 = F_5 ( V_2 , V_24 , V_6 , V_5 ) ;
F_23 ( & V_2 -> V_51 , V_53 ) ;
return V_54 ;
}
