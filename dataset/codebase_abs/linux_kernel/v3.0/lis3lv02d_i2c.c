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
if ( V_2 -> V_14 )
F_1 ( V_2 , V_15 ) ;
V_2 -> V_16 ( V_2 , V_17 , & V_7 ) ;
if ( V_7 != V_2 -> V_18 )
F_13 ( V_19 L_1 ) ;
V_4 = V_2 -> V_16 ( V_2 , V_20 , & V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
V_7 |= V_21 | V_22 | V_23 | V_24 ;
return V_2 -> V_25 ( V_2 , V_20 , V_7 ) ;
}
static int T_3 F_14 ( struct V_9 * V_26 ,
const struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_29 * V_30 = V_26 -> V_31 . V_32 ;
if ( V_30 ) {
if ( V_30 -> V_33 & V_34 )
V_35 . V_14 = F_1 ;
if ( ( V_30 -> V_33 & V_36 ) &&
( F_15 ( V_26 -> V_37 ,
V_38 ) ) )
V_35 . V_39 = F_10 ;
if ( V_30 -> V_40 )
V_41 . V_42 = V_30 -> V_40 ;
if ( V_30 -> V_43 )
V_41 . V_44 = V_30 -> V_43 ;
if ( V_30 -> V_45 )
V_41 . V_46 = V_30 -> V_45 ;
if ( V_30 -> V_47 )
V_4 = V_30 -> V_47 () ;
if ( V_4 )
goto V_48;
}
if ( V_35 . V_14 ) {
V_35 . V_6 [ 0 ] . V_49 = V_50 ;
V_35 . V_6 [ 1 ] . V_49 = V_51 ;
V_4 = F_16 ( & V_26 -> V_31 ,
F_3 ( V_35 . V_6 ) ,
V_35 . V_6 ) ;
if ( V_4 < 0 )
goto V_48;
}
V_35 . V_30 = V_30 ;
V_35 . V_11 = V_26 ;
V_35 . V_52 = F_12 ;
V_35 . V_16 = F_8 ;
V_35 . V_25 = F_6 ;
V_35 . V_53 = V_26 -> V_53 ;
V_35 . V_54 = V_41 ;
V_35 . V_55 = & V_26 -> V_31 ;
F_17 ( V_26 , & V_35 ) ;
if ( V_35 . V_14 )
F_1 ( & V_35 , V_15 ) ;
V_4 = F_18 ( & V_35 ) ;
if ( V_35 . V_14 )
F_1 ( & V_35 , V_5 ) ;
if ( V_4 == 0 )
return 0 ;
V_48:
if ( V_30 && V_30 -> V_56 )
V_30 -> V_56 () ;
return V_4 ;
}
static int T_4 F_19 ( struct V_9 * V_26 )
{
struct V_1 * V_2 = F_20 ( V_26 ) ;
struct V_29 * V_30 = V_26 -> V_31 . V_32 ;
if ( V_30 && V_30 -> V_56 )
V_30 -> V_56 () ;
F_21 () ;
F_22 ( & V_35 ) ;
if ( V_35 . V_14 )
F_23 ( F_3 ( V_2 -> V_6 ) ,
V_35 . V_6 ) ;
return 0 ;
}
static int F_24 ( struct V_57 * V_31 )
{
struct V_9 * V_26 = F_25 ( V_31 , struct V_9 , V_31 ) ;
struct V_1 * V_2 = F_20 ( V_26 ) ;
if ( ! V_2 -> V_30 || ! V_2 -> V_30 -> V_58 )
F_26 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_57 * V_31 )
{
struct V_9 * V_26 = F_25 ( V_31 , struct V_9 , V_31 ) ;
struct V_1 * V_2 = F_20 ( V_26 ) ;
if ( ! V_2 -> V_30 || ! V_2 -> V_30 -> V_58 ||
F_28 ( V_31 ) )
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_57 * V_31 )
{
struct V_9 * V_26 = F_25 ( V_31 , struct V_9 , V_31 ) ;
struct V_1 * V_2 = F_20 ( V_26 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_57 * V_31 )
{
struct V_9 * V_26 = F_25 ( V_31 , struct V_9 , V_31 ) ;
struct V_1 * V_2 = F_20 ( V_26 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static int T_5 F_32 ( void )
{
return F_33 ( & V_59 ) ;
}
static void T_6 F_34 ( void )
{
F_35 ( & V_59 ) ;
}
