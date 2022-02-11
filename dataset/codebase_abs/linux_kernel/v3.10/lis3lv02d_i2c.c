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
if ( V_2 -> V_17 == V_20 )
V_7 |= V_21 | V_22 | V_23 | V_24 ;
else
V_7 |= V_25 | V_22 | V_23 | V_24 ;
return V_2 -> V_26 ( V_2 , V_19 , V_7 ) ;
}
static int F_14 ( struct V_9 * V_27 ,
const struct V_28 * V_29 )
{
int V_4 = 0 ;
struct V_30 * V_31 = V_27 -> V_32 . V_33 ;
#ifdef F_15
if ( F_16 ( V_34 , & V_27 -> V_32 ) ) {
V_35 . V_36 = V_27 -> V_32 . V_36 ;
V_4 = F_17 ( & V_35 ) ;
if ( V_4 )
return V_4 ;
V_31 = V_35 . V_31 ;
}
#endif
if ( V_31 ) {
if ( ( V_31 -> V_37 & V_38 ) &&
( F_18 ( V_27 -> V_39 ,
V_40 ) ) )
V_35 . V_41 = F_10 ;
if ( V_31 -> V_42 )
V_43 . V_44 = V_31 -> V_42 ;
if ( V_31 -> V_45 )
V_43 . V_46 = V_31 -> V_45 ;
if ( V_31 -> V_47 )
V_43 . V_48 = V_31 -> V_47 ;
if ( V_31 -> V_49 )
V_4 = V_31 -> V_49 () ;
if ( V_4 )
goto V_50;
}
V_35 . V_6 [ 0 ] . V_51 = V_52 ;
V_35 . V_6 [ 1 ] . V_51 = V_53 ;
V_4 = F_19 ( & V_27 -> V_32 ,
F_3 ( V_35 . V_6 ) ,
V_35 . V_6 ) ;
if ( V_4 < 0 )
goto V_50;
V_35 . V_31 = V_31 ;
V_35 . V_11 = V_27 ;
V_35 . V_54 = F_12 ;
V_35 . V_15 = F_8 ;
V_35 . V_26 = F_6 ;
V_35 . V_55 = V_27 -> V_55 ;
V_35 . V_56 = V_43 ;
V_35 . V_57 = & V_27 -> V_32 ;
F_20 ( V_27 , & V_35 ) ;
F_1 ( & V_35 , V_14 ) ;
V_4 = F_21 ( & V_35 ) ;
F_1 ( & V_35 , V_5 ) ;
if ( V_4 )
goto V_58;
return 0 ;
V_58:
F_22 ( F_3 ( V_35 . V_6 ) ,
V_35 . V_6 ) ;
V_50:
if ( V_31 && V_31 -> V_59 )
V_31 -> V_59 () ;
return V_4 ;
}
static int F_23 ( struct V_9 * V_27 )
{
struct V_1 * V_2 = F_24 ( V_27 ) ;
struct V_30 * V_31 = V_27 -> V_32 . V_33 ;
if ( V_31 && V_31 -> V_59 )
V_31 -> V_59 () ;
F_25 ( V_2 ) ;
F_26 ( & V_35 ) ;
F_22 ( F_3 ( V_2 -> V_6 ) ,
V_35 . V_6 ) ;
return 0 ;
}
static int F_27 ( struct V_60 * V_32 )
{
struct V_9 * V_27 = F_28 ( V_32 , struct V_9 , V_32 ) ;
struct V_1 * V_2 = F_24 ( V_27 ) ;
if ( ! V_2 -> V_31 || ! V_2 -> V_31 -> V_61 )
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_60 * V_32 )
{
struct V_9 * V_27 = F_28 ( V_32 , struct V_9 , V_32 ) ;
struct V_1 * V_2 = F_24 ( V_27 ) ;
if ( ! V_2 -> V_31 || ! V_2 -> V_31 -> V_61 ||
F_31 ( V_32 ) )
F_32 ( V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_60 * V_32 )
{
struct V_9 * V_27 = F_28 ( V_32 , struct V_9 , V_32 ) ;
struct V_1 * V_2 = F_24 ( V_27 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_60 * V_32 )
{
struct V_9 * V_27 = F_28 ( V_32 , struct V_9 , V_32 ) ;
struct V_1 * V_2 = F_24 ( V_27 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
