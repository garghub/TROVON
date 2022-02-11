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
static int T_3 F_11 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_16 V_17 ;
const T_1 * V_18 ;
int V_19 , V_20 , V_21 ;
struct V_6 * V_7 = V_13 -> V_22 ;
int V_23 = F_12 ( V_15 , 0 , & V_17 ) ;
if ( V_23 )
return V_23 ;
if ( V_17 . V_24 - V_17 . V_25 < 13 )
return - V_26 ;
snprintf ( V_13 -> V_27 , V_28 , L_1 , V_17 . V_25 ) ;
V_18 = F_13 ( V_15 , L_2 , & V_21 ) ;
if ( ! V_18 || V_21 != 4 )
return - V_26 ;
V_19 = * V_18 ;
V_18 = F_13 ( V_15 , L_3 , & V_21 ) ;
if ( ! V_18 || V_21 != 4 )
return - V_26 ;
V_20 = * V_18 ;
V_7 -> V_5 = F_14 ( V_17 . V_25 , V_17 . V_24 - V_17 . V_25 + 1 ) ;
if ( ! V_7 -> V_5 )
return - V_29 ;
V_7 -> V_9 = V_7 -> V_5 + 4 ;
V_7 -> V_8 = 1 << ( 31 - V_19 ) ;
V_7 -> V_11 = 1 << ( 31 - V_20 ) ;
return 0 ;
}
static int T_3 F_15 ( struct V_30 * V_31 )
{
struct V_12 * V_32 ;
struct V_6 * V_7 ;
int V_23 = - V_29 ;
V_7 = F_16 ( sizeof( struct V_6 ) , V_33 ) ;
if ( ! V_7 )
goto V_34;
V_7 -> V_4 . V_35 = & V_36 ;
V_32 = F_17 ( & V_7 -> V_4 ) ;
if ( ! V_32 )
goto V_37;
V_32 -> V_38 = L_4 ,
V_23 = F_11 ( V_32 , V_31 -> V_39 . V_40 ) ;
if ( V_23 )
goto V_41;
V_32 -> V_42 = ~ 0 ;
V_32 -> V_43 = F_18 ( sizeof( int ) * V_44 , V_33 ) ;
if ( ! V_32 -> V_43 )
goto V_45;
V_32 -> V_46 = & V_31 -> V_39 ;
F_19 ( & V_31 -> V_39 , V_32 ) ;
V_23 = F_20 ( V_32 , V_31 -> V_39 . V_40 ) ;
if ( V_23 )
goto V_47;
return 0 ;
V_47:
F_19 ( & V_31 -> V_39 , NULL ) ;
F_21 ( V_32 -> V_43 ) ;
V_45:
F_22 ( V_7 -> V_5 ) ;
V_41:
F_23 ( V_32 ) ;
V_37:
F_21 ( V_7 ) ;
V_34:
return V_23 ;
}
static int F_24 ( struct V_30 * V_31 )
{
struct V_12 * V_13 = F_25 ( & V_31 -> V_39 ) ;
struct V_6 * V_7 = V_13 -> V_22 ;
F_26 ( V_13 ) ;
F_19 ( & V_31 -> V_39 , NULL ) ;
F_21 ( V_13 -> V_43 ) ;
F_23 ( V_13 ) ;
F_22 ( V_7 -> V_5 ) ;
F_21 ( V_7 ) ;
return 0 ;
}
static int F_27 ( void )
{
return F_28 ( & V_48 ) ;
}
static void F_29 ( void )
{
F_30 ( & V_48 ) ;
}
