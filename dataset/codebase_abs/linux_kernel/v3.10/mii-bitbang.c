static inline void F_1 ( T_1 T_2 * V_1 , T_1 V_2 )
{
F_2 ( V_1 , F_3 ( V_1 ) | V_2 ) ;
}
static inline void F_4 ( T_1 T_2 * V_1 , T_1 V_2 )
{
F_2 ( V_1 , F_3 ( V_1 ) & ~ V_2 ) ;
}
static inline int F_5 ( T_1 T_2 * V_1 , T_1 V_2 )
{
return ( F_3 ( V_1 ) & V_2 ) != 0 ;
}
static inline void F_6 ( struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_7 ( V_4 , struct V_6 , V_4 ) ;
if ( V_5 )
F_1 ( V_7 -> V_5 , V_7 -> V_8 ) ;
else
F_4 ( V_7 -> V_5 , V_7 -> V_8 ) ;
F_3 ( V_7 -> V_5 ) ;
}
static inline int F_8 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_7 ( V_4 , struct V_6 , V_4 ) ;
return F_5 ( V_7 -> V_9 , V_7 -> V_8 ) ;
}
static inline void F_9 ( struct V_3 * V_4 , int V_10 )
{
struct V_6 * V_7 = F_7 ( V_4 , struct V_6 , V_4 ) ;
if ( V_10 )
F_1 ( V_7 -> V_9 , V_7 -> V_8 ) ;
else
F_4 ( V_7 -> V_9 , V_7 -> V_8 ) ;
F_3 ( V_7 -> V_9 ) ;
}
static inline void F_10 ( struct V_3 * V_4 , int V_10 )
{
struct V_6 * V_7 = F_7 ( V_4 , struct V_6 , V_4 ) ;
if ( V_10 )
F_1 ( V_7 -> V_9 , V_7 -> V_11 ) ;
else
F_4 ( V_7 -> V_9 , V_7 -> V_11 ) ;
F_3 ( V_7 -> V_9 ) ;
}
static int F_11 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_16 V_17 ;
const T_1 * V_18 ;
int V_19 , V_20 , V_21 ;
struct V_6 * V_7 = V_13 -> V_22 ;
int V_23 = F_12 ( V_15 , 0 , & V_17 ) ;
if ( V_23 )
return V_23 ;
if ( F_13 ( & V_17 ) <= 13 )
return - V_24 ;
snprintf ( V_13 -> V_25 , V_26 , L_1 , V_17 . V_27 ) ;
V_18 = F_14 ( V_15 , L_2 , & V_21 ) ;
if ( ! V_18 || V_21 != 4 )
return - V_24 ;
V_19 = * V_18 ;
V_18 = F_14 ( V_15 , L_3 , & V_21 ) ;
if ( ! V_18 || V_21 != 4 )
return - V_24 ;
V_20 = * V_18 ;
V_7 -> V_5 = F_15 ( V_17 . V_27 , F_13 ( & V_17 ) ) ;
if ( ! V_7 -> V_5 )
return - V_28 ;
V_7 -> V_9 = V_7 -> V_5 + 4 ;
V_7 -> V_8 = 1 << ( 31 - V_19 ) ;
V_7 -> V_11 = 1 << ( 31 - V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_29 * V_30 )
{
struct V_12 * V_31 ;
struct V_6 * V_7 ;
int V_23 = - V_28 ;
V_7 = F_17 ( sizeof( struct V_6 ) , V_32 ) ;
if ( ! V_7 )
goto V_33;
V_7 -> V_4 . V_34 = & V_35 ;
V_31 = F_18 ( & V_7 -> V_4 ) ;
if ( ! V_31 )
goto V_36;
V_31 -> V_37 = L_4 ,
V_23 = F_11 ( V_31 , V_30 -> V_38 . V_39 ) ;
if ( V_23 )
goto V_40;
V_31 -> V_41 = ~ 0 ;
V_31 -> V_42 = F_19 ( sizeof( int ) * V_43 , V_32 ) ;
if ( ! V_31 -> V_42 ) {
V_23 = - V_28 ;
goto V_44;
}
V_31 -> V_45 = & V_30 -> V_38 ;
F_20 ( & V_30 -> V_38 , V_31 ) ;
V_23 = F_21 ( V_31 , V_30 -> V_38 . V_39 ) ;
if ( V_23 )
goto V_46;
return 0 ;
V_46:
F_20 ( & V_30 -> V_38 , NULL ) ;
F_22 ( V_31 -> V_42 ) ;
V_44:
F_23 ( V_7 -> V_5 ) ;
V_40:
F_24 ( V_31 ) ;
V_36:
F_22 ( V_7 ) ;
V_33:
return V_23 ;
}
static int F_25 ( struct V_29 * V_30 )
{
struct V_12 * V_13 = F_26 ( & V_30 -> V_38 ) ;
struct V_6 * V_7 = V_13 -> V_22 ;
F_27 ( V_13 ) ;
F_20 ( & V_30 -> V_38 , NULL ) ;
F_22 ( V_13 -> V_42 ) ;
F_24 ( V_13 ) ;
F_23 ( V_7 -> V_5 ) ;
F_22 ( V_7 ) ;
return 0 ;
}
