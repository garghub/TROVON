static inline void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static inline unsigned int F_4 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_4 + V_5 ) & V_6 ;
}
static int F_5 ( struct V_7 * V_8 , int V_9 , int V_3 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_10 = 1000 ;
T_1 V_11 ;
V_11 = V_12 | ( V_9 << V_13 ) | ( V_3 << V_14 ) ;
F_3 ( V_11 , V_2 -> V_4 + V_5 ) ;
F_1 ( V_2 ) ;
do {
if ( ! F_4 ( V_2 ) )
break;
F_6 ( 1000 , 2000 ) ;
} while ( V_10 -- );
if ( ! V_10 )
return - V_15 ;
V_11 = F_2 ( V_2 -> V_4 + V_5 ) ;
if ( V_11 & V_16 )
return - V_17 ;
return V_11 & 0xffff ;
}
static int F_7 ( struct V_7 * V_8 , int V_9 ,
int V_3 , T_2 V_18 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned int V_10 = 1000 ;
T_1 V_11 ;
V_11 = V_19 | ( V_9 << V_13 ) |
( V_3 << V_14 ) | ( 0xffff & V_18 ) ;
F_3 ( V_11 , V_2 -> V_4 + V_5 ) ;
F_1 ( V_2 ) ;
do {
if ( ! F_4 ( V_2 ) )
break;
F_6 ( 1000 , 2000 ) ;
} while ( V_10 -- );
if ( ! V_10 )
return - V_15 ;
return 0 ;
}
static int F_8 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
struct V_7 * V_8 ;
struct V_24 * V_25 ;
int V_26 ;
V_23 = V_21 -> V_27 . V_28 ;
V_2 = F_9 ( & V_21 -> V_27 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return - V_30 ;
V_25 = F_10 ( V_21 , V_31 , 0 ) ;
V_2 -> V_4 = F_11 ( & V_21 -> V_27 , V_25 -> V_32 , F_12 ( V_25 ) ) ;
if ( ! V_2 -> V_4 ) {
F_13 ( & V_21 -> V_27 , L_1 ) ;
return - V_30 ;
}
V_2 -> V_7 = F_14 () ;
if ( ! V_2 -> V_7 )
return - V_30 ;
V_8 = V_2 -> V_7 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_33 = L_2 ;
V_8 -> V_34 = & V_21 -> V_27 ;
V_8 -> V_35 = F_5 ;
V_8 -> V_36 = F_7 ;
snprintf ( V_8 -> V_37 , V_38 , L_3 , V_21 -> V_33 ) ;
V_8 -> V_39 = F_15 ( V_40 , sizeof( int ) , V_29 ) ;
if ( ! V_8 -> V_39 ) {
V_26 = - V_30 ;
goto V_41;
}
V_26 = F_16 ( V_8 , V_23 ) ;
if ( V_26 ) {
F_13 ( & V_21 -> V_27 , L_4 ) ;
goto V_42;
}
F_17 ( V_21 , V_2 ) ;
F_18 ( & V_21 -> V_27 , L_5 , V_2 -> V_4 ) ;
return 0 ;
V_42:
F_19 ( V_8 -> V_39 ) ;
V_41:
F_20 ( V_8 ) ;
return V_26 ;
}
static int F_21 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_22 ( V_21 ) ;
F_23 ( V_2 -> V_7 ) ;
F_19 ( V_2 -> V_7 -> V_39 ) ;
F_20 ( V_2 -> V_7 ) ;
return 0 ;
}
