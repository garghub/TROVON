static inline T_1 F_1 ( void )
{
return F_2 ( V_1 *
V_2 ,
V_3 ) ;
}
void F_3 ( struct V_4 * V_5 )
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
F_6 ( ! V_5 -> V_14 ) ;
F_7 ( L_1 ) ;
F_7 ( L_2 ,
( V_15 ) V_5 -> V_10 ) ;
F_7 ( L_3 ,
V_5 -> V_12 ) ;
F_7 ( L_4 ,
V_8 ) ;
F_7 ( L_5 ,
( V_15 ) V_5 -> V_10 ) ;
F_7 ( L_6 ,
V_5 -> V_9 . V_7 ) ;
F_7 ( L_7 ,
( V_15 ) V_5 -> V_14 ) ;
}
int F_8 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
T_2 V_20 ;
struct V_4 * V_21 ;
if ( V_19 -> V_22 - V_19 -> V_23 != F_1 () )
return - V_24 ;
V_21 = F_9 ( V_19 -> V_25 ) ;
if ( V_21 == NULL )
return - V_24 ;
V_20 = F_10 ( V_21 , V_17 ) ;
V_19 -> V_26 |= V_27 | V_28 | V_29 | V_30 |
V_31 | V_32 ;
V_19 -> V_33 = F_11 ( V_19 -> V_33 ) ;
F_7 ( L_8
L_9
L_10
L_11
L_12 ,
( unsigned long long ) V_19 -> V_23 , V_20 , V_19 -> V_26 ,
F_1 () ) ;
return F_12 ( V_19 ,
V_19 -> V_23 ,
V_20 >> V_34 ,
F_1 () ,
V_19 -> V_33 ) ;
}
V_13 T_3 * F_13 ( struct V_4 * V_5 ,
unsigned int * V_35 )
{
V_13 V_36 ;
F_6 ( ! V_5 || ! V_35 ) ;
F_14 ( & V_37 ) ;
V_36 = F_15 ( V_38 ,
V_2 ) ;
F_16 ( V_36 , V_38 ) ;
F_17 ( & V_37 ) ;
if ( V_36 >= V_2 )
return NULL ;
* V_35 = V_39 * ( F_1 () /
sizeof( V_13 ) ) + V_36 ;
F_7 ( L_13
L_14
L_15 ,
* V_35 , ( V_15 ) ( V_5 -> V_14 + V_36 ) ) ;
return V_5 -> V_14 + V_36 ;
}
void F_18 ( struct V_4 * V_5 , V_13 T_3 * V_40 )
{
unsigned int V_36 ;
F_6 ( ! V_5 || ! V_40 ) ;
V_36 = ( unsigned int ) ( V_40 - V_5 -> V_14 ) ;
F_14 ( & V_37 ) ;
F_19 ( V_36 , V_38 ) ;
F_17 ( & V_37 ) ;
}
inline void F_20 ( V_13 T_3 * V_41 , V_13 V_42 )
{
if ( V_41 ) {
F_21 ( V_42 , V_41 ) ;
F_7 ( L_16 , V_42 , V_41 ) ;
}
}
unsigned int F_22 ( struct V_4 * V_5 ,
struct V_16 * V_17 ,
unsigned int V_43 )
{
return V_5 -> V_12 +
V_17 -> V_44 * ( F_1 () / sizeof( V_13 ) ) +
V_43 ;
}
T_4 F_23 ( struct V_4 * V_5 )
{
T_4 V_45 = ( V_5 -> V_9 . V_7 -
V_5 -> V_9 . V_6 ) /
F_1 () + 1 ;
return V_45 ;
}
T_2 F_10 ( struct V_4 * V_21 ,
struct V_16 * V_17 )
{
return V_21 -> V_10 +
V_17 -> V_44 * F_1 () ;
}
