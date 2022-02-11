static void F_1 ( T_1 * V_1 , const struct V_2 * V_3 ,
unsigned int V_4 )
{
T_2 V_5 ;
if ( ! F_2 ( V_1 ) )
return;
V_5 = V_6 | V_7 |
V_8 | V_9 ;
if ( ! V_3 -> V_10 )
V_5 |= V_11 ;
else
V_5 |= V_12 | V_13 ;
F_3 ( V_5 , V_1 -> V_14 + V_15 ) ;
F_3 ( V_16 |
V_17 |
V_18 |
V_19 , V_1 -> V_14 + V_20 ) ;
F_3 ( F_4 ( 64 ) |
V_21 |
F_5 ( V_3 -> V_22 ) |
F_6 ( 29 ) , V_1 -> V_14 + V_23 ) ;
if ( F_7 ( V_1 ) && V_1 -> V_24 . V_25 > 1 ) {
T_2 V_26 = V_27 * ( V_4 / 1000 ) ;
F_3 ( V_28 | V_29 |
F_8 ( V_26 ) |
F_9 ( V_30 ) ,
V_1 -> V_14 + V_31 ) ;
}
}
void F_10 ( struct V_32 * V_33 )
{
F_11 ( V_33 ) ;
}
struct V_32 * F_12 ( T_1 * V_34 , struct V_2 * V_3 )
{
struct V_32 * V_33 = F_13 ( sizeof( * V_33 ) , V_35 ) ;
if ( ! V_33 )
return NULL ;
V_33 -> V_34 = V_34 ;
return V_33 ;
}
void F_14 ( struct V_32 * V_33 )
{
T_2 V_36 = F_15 ( V_33 -> V_34 -> V_14 + V_37 ) ;
#ifdef F_16
if ( ! F_2 ( V_33 -> V_34 ) ) {
F_3 ( 0xffffffff ,
V_33 -> V_34 -> V_14 + V_38 ) ;
F_3 ( V_36 | V_39 ,
V_33 -> V_34 -> V_14 + V_37 ) ;
} else
#endif
{
F_3 ( 0 , V_33 -> V_34 -> V_14 + V_40 ) ;
F_3 ( V_36 | V_41 ,
V_33 -> V_34 -> V_14 + V_37 ) ;
}
}
void F_17 ( struct V_32 * V_33 )
{
T_2 V_36 = F_15 ( V_33 -> V_34 -> V_14 + V_37 ) ;
#ifdef F_16
if ( ! F_2 ( V_33 -> V_34 ) ) {
F_3 ( 0 , V_33 -> V_34 -> V_14 + V_38 ) ;
F_3 ( V_36 & ~ V_39 ,
V_33 -> V_34 -> V_14 + V_37 ) ;
} else
#endif
{
F_3 ( 0 , V_33 -> V_34 -> V_14 + V_40 ) ;
F_3 ( V_36 & ~ V_41 ,
V_33 -> V_34 -> V_14 + V_37 ) ;
}
}
void F_18 ( struct V_32 * V_33 )
{
#ifdef F_16
if ( ! F_2 ( V_33 -> V_34 ) ) {
F_3 ( 0xffffffff ,
V_33 -> V_34 -> V_14 + V_42 ) ;
F_3 ( V_39 , V_33 -> V_34 -> V_14 + V_43 ) ;
return;
}
#endif
F_3 ( 0xffffffff , V_33 -> V_34 -> V_14 + V_44 ) ;
F_3 ( V_41 , V_33 -> V_34 -> V_14 + V_43 ) ;
}
int F_19 ( struct V_32 * V_33 )
{
T_2 V_45 ;
#ifdef F_16
if ( ! F_2 ( V_33 -> V_34 ) )
return 1 ;
#endif
V_45 = F_15 ( V_33 -> V_34 -> V_14 + V_44 ) ;
F_3 ( V_45 , V_33 -> V_34 -> V_14 + V_44 ) ;
return 0 ;
}
static void F_20 ( struct V_32 * V_33 , T_2 V_46 , int V_47 )
{
T_2 V_5 = F_15 ( V_33 -> V_34 -> V_14 + V_23 ) ;
if ( V_47 )
V_5 |= V_46 ;
else
V_5 &= ~ V_46 ;
F_3 ( V_5 , V_33 -> V_34 -> V_14 + V_23 ) ;
}
void F_21 ( struct V_32 * V_33 , int V_47 )
{
F_20 ( V_33 , V_48 , V_47 ) ;
}
void F_22 ( struct V_32 * V_33 , int V_47 )
{
F_20 ( V_33 , V_49 , V_47 ) ;
}
int F_23 ( struct V_32 * V_33 , struct V_2 * V_3 , unsigned int V_4 )
{
T_1 * V_34 = V_33 -> V_34 ;
F_1 ( V_34 , V_3 , V_4 ) ;
F_3 ( V_50 , V_34 -> V_14 + V_51 ) ;
return 0 ;
}
