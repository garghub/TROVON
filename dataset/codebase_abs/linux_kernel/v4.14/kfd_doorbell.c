static inline T_1 F_1 ( void )
{
return F_2 ( V_1 *
V_2 ,
V_3 ) ;
}
int F_3 ( struct V_4 * V_5 )
{
T_1 V_6 ;
T_1 V_7 ;
T_1 V_8 ;
V_6 =
F_2 ( V_5 -> V_9 . V_6 ,
F_1 () ) ;
V_7 =
F_4 ( V_5 -> V_9 . V_7 ,
F_1 () ) ;
if ( V_7 > V_6 )
V_8 =
( V_7 - V_6 ) /
F_1 () ;
else
V_8 = 0 ;
V_5 -> V_10 = V_5 -> V_9 . V_11 +
V_6 ;
V_5 -> V_12 = V_6 / sizeof( V_13 ) ;
V_5 -> V_8 = V_8 - 1 ;
V_5 -> V_14 = F_5 ( V_5 -> V_10 ,
F_1 () ) ;
if ( ! V_5 -> V_14 )
return - V_15 ;
F_6 ( L_1 ) ;
F_6 ( L_2 ,
( V_16 ) V_5 -> V_10 ) ;
F_6 ( L_3 ,
V_5 -> V_12 ) ;
F_6 ( L_4 ,
V_8 ) ;
F_6 ( L_5 ,
( V_16 ) V_5 -> V_10 ) ;
F_6 ( L_6 ,
V_5 -> V_9 . V_7 ) ;
F_6 ( L_7 ,
( V_16 ) V_5 -> V_14 ) ;
return 0 ;
}
void F_7 ( struct V_4 * V_5 )
{
if ( V_5 -> V_14 )
F_8 ( V_5 -> V_14 ) ;
}
int F_9 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
T_2 V_21 ;
struct V_4 * V_22 ;
if ( V_20 -> V_23 - V_20 -> V_24 != F_1 () )
return - V_25 ;
V_22 = F_10 ( V_20 -> V_26 ) ;
if ( ! V_22 )
return - V_25 ;
V_21 = F_11 ( V_22 , V_18 ) ;
V_20 -> V_27 |= V_28 | V_29 | V_30 | V_31 |
V_32 | V_33 ;
V_20 -> V_34 = F_12 ( V_20 -> V_34 ) ;
F_6 ( L_8
L_9
L_10
L_11
L_12 ,
( unsigned long long ) V_20 -> V_24 , V_21 , V_20 -> V_27 ,
F_1 () ) ;
return F_13 ( V_20 ,
V_20 -> V_24 ,
V_21 >> V_35 ,
F_1 () ,
V_20 -> V_34 ) ;
}
V_13 T_3 * F_14 ( struct V_4 * V_5 ,
unsigned int * V_36 )
{
V_13 V_37 ;
F_15 ( & V_5 -> V_38 ) ;
V_37 = F_16 ( V_5 -> V_39 ,
V_2 ) ;
F_17 ( V_37 , V_5 -> V_39 ) ;
F_18 ( & V_5 -> V_38 ) ;
if ( V_37 >= V_2 )
return NULL ;
* V_36 = V_40 * ( F_1 () /
sizeof( V_13 ) ) + V_37 ;
F_6 ( L_13
L_14
L_15 ,
* V_36 , ( V_16 ) ( V_5 -> V_14 + V_37 ) ) ;
return V_5 -> V_14 + V_37 ;
}
void F_19 ( struct V_4 * V_5 , V_13 T_3 * V_41 )
{
unsigned int V_37 ;
V_37 = ( unsigned int ) ( V_41 - V_5 -> V_14 ) ;
F_15 ( & V_5 -> V_38 ) ;
F_20 ( V_37 , V_5 -> V_39 ) ;
F_18 ( & V_5 -> V_38 ) ;
}
inline void F_21 ( V_13 T_3 * V_42 , V_13 V_43 )
{
if ( V_42 ) {
F_22 ( V_43 , V_42 ) ;
F_6 ( L_16 , V_43 , V_42 ) ;
}
}
unsigned int F_23 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
unsigned int V_44 )
{
return V_5 -> V_12 +
V_18 -> V_45 * ( F_1 () / sizeof( V_13 ) ) +
V_44 ;
}
T_4 F_24 ( struct V_4 * V_5 )
{
T_4 V_46 = ( V_5 -> V_9 . V_7 -
V_5 -> V_9 . V_6 ) /
F_1 () + 1 ;
return V_46 ;
}
T_2 F_11 ( struct V_4 * V_22 ,
struct V_17 * V_18 )
{
return V_22 -> V_10 +
V_18 -> V_45 * F_1 () ;
}
