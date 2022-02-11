static inline int F_1 ( void T_1 * V_1 )
{
T_2 V_2 ;
unsigned int V_3 = 1000 ;
do {
V_2 = F_2 ( V_1 + V_4 ) ;
if ( ( V_2 & F_3 ( V_5 ) ) == 0 )
return 0 ;
F_4 ( 1000 , 2000 ) ;
} while ( V_3 -- );
return - V_6 ;
}
static inline void F_5 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = ( V_7 << V_8 ) |
F_3 ( V_9 ) ;
F_6 ( V_2 , V_1 + V_4 ) ;
}
static int F_7 ( struct V_10 * V_11 , int V_12 , int V_13 )
{
struct V_14 * V_15 = V_11 -> V_15 ;
T_2 V_16 ;
int V_17 ;
V_17 = F_1 ( V_15 -> V_1 ) ;
if ( V_17 )
return V_17 ;
V_16 = ( V_18 << V_19 ) |
( V_13 << V_20 ) |
( V_12 << V_21 ) |
F_3 ( V_22 ) |
( V_23 << V_24 ) ;
F_6 ( V_16 , V_15 -> V_1 + V_25 ) ;
V_17 = F_1 ( V_15 -> V_1 ) ;
if ( V_17 )
return V_17 ;
V_16 = F_2 ( V_15 -> V_1 + V_25 ) & V_26 ;
return V_16 ;
}
static int F_8 ( struct V_10 * V_11 , int V_12 ,
int V_13 , T_3 V_2 )
{
struct V_14 * V_15 = V_11 -> V_15 ;
T_2 V_16 ;
int V_17 ;
V_17 = F_1 ( V_15 -> V_1 ) ;
if ( V_17 )
return V_17 ;
V_16 = ( V_18 << V_19 ) |
( V_13 << V_20 ) |
( V_12 << V_21 ) |
F_3 ( V_22 ) |
( V_27 << V_24 ) |
( ( T_2 ) ( V_2 ) & V_26 ) ;
F_6 ( V_16 , V_15 -> V_1 + V_25 ) ;
V_17 = F_1 ( V_15 -> V_1 ) ;
if ( V_17 )
return V_17 ;
return 0 ;
}
static int F_9 ( struct V_28 * V_29 )
{
struct V_14 * V_15 ;
struct V_10 * V_11 ;
struct V_30 * V_31 ;
int V_17 ;
V_15 = F_10 ( & V_29 -> V_32 , sizeof( * V_15 ) , V_33 ) ;
if ( ! V_15 )
return - V_34 ;
V_31 = F_11 ( V_29 , V_35 , 0 ) ;
V_15 -> V_1 = F_12 ( & V_29 -> V_32 , V_31 ) ;
if ( F_13 ( V_15 -> V_1 ) ) {
F_14 ( & V_29 -> V_32 , L_1 ) ;
return F_15 ( V_15 -> V_1 ) ;
}
V_15 -> V_10 = F_16 () ;
if ( ! V_15 -> V_10 ) {
F_14 ( & V_29 -> V_32 , L_2 ) ;
return - V_34 ;
}
V_11 = V_15 -> V_10 ;
V_11 -> V_15 = V_15 ;
V_11 -> V_36 = L_3 ;
snprintf ( V_11 -> V_37 , V_38 , L_4 , V_29 -> V_36 , V_29 -> V_37 ) ;
V_11 -> V_39 = & V_29 -> V_32 ;
V_11 -> V_40 = F_7 ;
V_11 -> V_41 = F_8 ;
F_5 ( V_15 -> V_1 ) ;
V_17 = F_17 ( V_11 , V_29 -> V_32 . V_42 ) ;
if ( V_17 ) {
F_14 ( & V_29 -> V_32 , L_5 ) ;
goto V_43;
}
F_18 ( V_29 , V_15 ) ;
F_19 ( & V_29 -> V_32 , L_6 , V_15 -> V_1 ) ;
return 0 ;
V_43:
F_20 ( V_11 ) ;
return V_17 ;
}
static int F_21 ( struct V_28 * V_29 )
{
struct V_14 * V_15 = F_22 ( V_29 ) ;
F_23 ( V_15 -> V_10 ) ;
F_20 ( V_15 -> V_10 ) ;
return 0 ;
}
