static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
if ( V_3 == V_5 ) {
V_4 = F_2 ( F_3 ( V_2 -> V_6 ) ,
V_2 -> V_6 ) ;
} else {
V_4 = F_4 ( F_3 ( V_2 -> V_6 ) ,
V_2 -> V_6 ) ;
F_5 ( 10000 , 20000 ) ;
}
return V_4 ;
}
static inline T_1 F_6 ( struct V_1 * V_2 , int V_7 , T_2 V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
return F_7 ( V_10 , V_7 , V_8 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_2 , int V_7 , T_2 * V_12 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
* V_12 = F_9 ( V_10 , V_7 ) ;
return 0 ;
}
static inline T_1 F_10 ( struct V_1 * V_2 , int V_7 , int V_13 ,
T_2 * V_12 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_7 |= ( 1 << 7 ) ;
return F_11 ( V_10 , V_7 , V_13 , V_12 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_2 V_7 ;
int V_4 ;
F_1 ( V_2 , V_14 ) ;
V_2 -> V_15 ( V_2 , V_16 , & V_7 ) ;
if ( V_7 != V_2 -> V_17 )
F_13 ( V_18 L_1 ) ;
V_4 = V_2 -> V_15 ( V_2 , V_19 , & V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
V_7 |= V_20 | V_21 | V_22 | V_23 ;
return V_2 -> V_24 ( V_2 , V_19 , V_7 ) ;
}
static int T_3 F_14 ( struct V_9 * V_25 ,
const struct V_26 * V_27 )
{
int V_4 = 0 ;
struct V_28 * V_29 = V_25 -> V_30 . V_31 ;
if ( V_29 ) {
if ( ( V_29 -> V_32 & V_33 ) &&
( F_15 ( V_25 -> V_34 ,
V_35 ) ) )
V_36 . V_37 = F_10 ;
if ( V_29 -> V_38 )
V_39 . V_40 = V_29 -> V_38 ;
if ( V_29 -> V_41 )
V_39 . V_42 = V_29 -> V_41 ;
if ( V_29 -> V_43 )
V_39 . V_44 = V_29 -> V_43 ;
if ( V_29 -> V_45 )
V_4 = V_29 -> V_45 () ;
if ( V_4 )
goto V_46;
}
V_36 . V_6 [ 0 ] . V_47 = V_48 ;
V_36 . V_6 [ 1 ] . V_47 = V_49 ;
V_4 = F_16 ( & V_25 -> V_30 ,
F_3 ( V_36 . V_6 ) ,
V_36 . V_6 ) ;
if ( V_4 < 0 )
goto V_46;
V_36 . V_29 = V_29 ;
V_36 . V_11 = V_25 ;
V_36 . V_50 = F_12 ;
V_36 . V_15 = F_8 ;
V_36 . V_24 = F_6 ;
V_36 . V_51 = V_25 -> V_51 ;
V_36 . V_52 = V_39 ;
V_36 . V_53 = & V_25 -> V_30 ;
F_17 ( V_25 , & V_36 ) ;
F_1 ( & V_36 , V_14 ) ;
V_4 = F_18 ( & V_36 ) ;
F_1 ( & V_36 , V_5 ) ;
if ( V_4 )
goto V_54;
return 0 ;
V_54:
F_19 ( F_3 ( V_36 . V_6 ) ,
V_36 . V_6 ) ;
V_46:
if ( V_29 && V_29 -> V_55 )
V_29 -> V_55 () ;
return V_4 ;
}
static int T_4 F_20 ( struct V_9 * V_25 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
struct V_28 * V_29 = V_25 -> V_30 . V_31 ;
if ( V_29 && V_29 -> V_55 )
V_29 -> V_55 () ;
F_22 ( V_2 ) ;
F_23 ( & V_36 ) ;
F_19 ( F_3 ( V_2 -> V_6 ) ,
V_36 . V_6 ) ;
return 0 ;
}
static int F_24 ( struct V_56 * V_30 )
{
struct V_9 * V_25 = F_25 ( V_30 , struct V_9 , V_30 ) ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
if ( ! V_2 -> V_29 || ! V_2 -> V_29 -> V_57 )
F_26 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_56 * V_30 )
{
struct V_9 * V_25 = F_25 ( V_30 , struct V_9 , V_30 ) ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
if ( ! V_2 -> V_29 || ! V_2 -> V_29 -> V_57 ||
F_28 ( V_30 ) )
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_56 * V_30 )
{
struct V_9 * V_25 = F_25 ( V_30 , struct V_9 , V_30 ) ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_56 * V_30 )
{
struct V_9 * V_25 = F_25 ( V_30 , struct V_9 , V_30 ) ;
struct V_1 * V_2 = F_21 ( V_25 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
