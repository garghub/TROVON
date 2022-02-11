static struct V_1 F_1 ( struct V_2 * V_3 )
{
T_1 V_4 = F_2 ( V_3 , true ) ;
if ( F_3 ( V_3 ) ) {
if ( V_4 <= 0 )
V_4 = V_5 ;
} else
V_4 = 0 ;
return F_4 ( V_4 ) ;
}
static void F_5 ( struct V_6 * V_7 , unsigned int V_8 ,
struct V_9 * const V_10 )
{
T_2 V_11 , V_12 ;
struct V_13 * V_14 = & V_7 -> signal -> V_14 [ V_8 ] ;
F_6 ( & V_7 -> V_15 -> V_16 ) ;
V_11 = V_14 -> V_17 ;
V_12 = V_14 -> V_18 ;
if ( V_11 ) {
struct V_19 V_20 ;
T_2 V_21 ;
F_7 ( V_7 , & V_20 ) ;
if ( V_8 == V_22 )
V_21 = V_20 . V_23 + V_20 . V_24 ;
else
V_21 = V_20 . V_23 ;
if ( V_11 < V_21 )
V_11 = V_25 ;
else
V_11 = V_11 - V_21 ;
}
F_8 ( & V_7 -> V_15 -> V_16 ) ;
F_9 ( V_11 , & V_10 -> V_26 ) ;
F_9 ( V_12 , & V_10 -> V_27 ) ;
}
int F_10 ( int V_28 , struct V_9 * V_10 )
{
struct V_6 * V_7 = V_29 ;
switch ( V_28 ) {
case V_30 :
F_6 ( & V_7 -> V_15 -> V_16 ) ;
V_10 -> V_26 = F_1 ( & V_7 -> signal -> V_31 ) ;
V_10 -> V_27 =
F_4 ( V_7 -> signal -> V_32 ) ;
F_8 ( & V_7 -> V_15 -> V_16 ) ;
break;
case V_33 :
F_5 ( V_7 , V_34 , V_10 ) ;
break;
case V_35 :
F_5 ( V_7 , V_22 , V_10 ) ;
break;
default:
return ( - V_36 ) ;
}
return 0 ;
}
enum V_37 F_11 ( struct V_2 * V_3 )
{
struct V_38 * V_39 =
F_12 ( V_3 , struct V_38 , V_31 ) ;
F_13 ( V_30 , V_39 -> V_40 , 0 ) ;
F_14 ( V_41 , V_42 , V_39 -> V_40 ) ;
return V_43 ;
}
static inline T_3 F_15 ( T_2 V_44 , T_4 V_45 )
{
struct V_46 V_47 ;
T_4 V_48 ;
F_16 ( V_44 , & V_47 ) ;
V_48 = F_17 ( & V_47 ) ;
return ( V_48 <= V_45 ) ? 0 : V_48 - V_45 ;
}
static void F_18 ( struct V_6 * V_7 , unsigned int V_8 ,
const struct V_9 * const V_10 ,
struct V_9 * const V_49 )
{
T_2 V_11 , V_50 , V_12 , V_51 ;
T_4 V_52 , V_53 ;
T_3 error , V_54 ;
struct V_13 * V_14 = & V_7 -> signal -> V_14 [ V_8 ] ;
V_50 = F_19 ( & V_10 -> V_26 ) ;
V_53 = F_20 ( & V_10 -> V_26 ) ;
V_51 = F_19 ( & V_10 -> V_27 ) ;
V_52 = F_20 ( & V_10 -> V_27 ) ;
error = F_15 ( V_50 , V_53 ) ;
V_54 = F_15 ( V_51 , V_52 ) ;
F_6 ( & V_7 -> V_15 -> V_16 ) ;
V_11 = V_14 -> V_17 ;
V_12 = V_14 -> V_18 ;
if ( V_11 || V_50 ) {
if ( V_50 > 0 )
V_50 += V_25 ;
F_21 ( V_7 , V_8 , & V_50 , & V_11 ) ;
}
V_14 -> V_17 = V_50 ;
V_14 -> V_18 = V_51 ;
V_14 -> error = error ;
V_14 -> V_54 = V_54 ;
F_22 ( V_8 == V_34 ?
V_33 : V_35 , V_10 , V_50 ) ;
F_8 ( & V_7 -> V_15 -> V_16 ) ;
if ( V_49 ) {
F_9 ( V_11 , & V_49 -> V_26 ) ;
F_9 ( V_12 , & V_49 -> V_27 ) ;
}
}
int F_23 ( int V_28 , struct V_9 * V_10 , struct V_9 * V_49 )
{
struct V_6 * V_7 = V_29 ;
struct V_2 * V_3 ;
T_1 V_17 ;
if ( ! F_24 ( & V_10 -> V_26 ) ||
! F_24 ( & V_10 -> V_27 ) )
return - V_36 ;
switch ( V_28 ) {
case V_30 :
V_55:
F_6 ( & V_7 -> V_15 -> V_16 ) ;
V_3 = & V_7 -> signal -> V_31 ;
if ( V_49 ) {
V_49 -> V_26 = F_1 ( V_3 ) ;
V_49 -> V_27
= F_4 ( V_7 -> signal -> V_32 ) ;
}
if ( F_25 ( V_3 ) < 0 ) {
F_8 ( & V_7 -> V_15 -> V_16 ) ;
goto V_55;
}
V_17 = F_26 ( V_10 -> V_26 ) ;
if ( V_17 != 0 ) {
V_7 -> signal -> V_32 =
F_26 ( V_10 -> V_27 ) ;
F_27 ( V_3 , V_17 , V_56 ) ;
} else
V_7 -> signal -> V_32 = 0 ;
F_22 ( V_30 , V_10 , 0 ) ;
F_8 ( & V_7 -> V_15 -> V_16 ) ;
break;
case V_33 :
F_18 ( V_7 , V_34 , V_10 , V_49 ) ;
break;
case V_35 :
F_18 ( V_7 , V_22 , V_10 , V_49 ) ;
break;
default:
return - V_36 ;
}
return 0 ;
}
static unsigned int F_28 ( unsigned int V_57 )
{
struct V_9 V_58 , V_59 ;
#if V_60 < 64
if ( V_57 > V_61 )
V_57 = V_61 ;
#endif
V_58 . V_26 . V_62 = V_57 ;
V_58 . V_26 . V_63 = 0 ;
V_58 . V_27 . V_62 = V_58 . V_27 . V_63 = 0 ;
F_23 ( V_30 , & V_58 , & V_59 ) ;
if ( ( ! V_59 . V_26 . V_62 && V_59 . V_26 . V_63 ) ||
V_59 . V_26 . V_63 >= 500000 )
V_59 . V_26 . V_62 ++ ;
return V_59 . V_26 . V_62 ;
}
