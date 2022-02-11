static struct V_1 F_1 ( struct V_2 * V_3 )
{
T_1 V_4 = F_2 ( V_3 ) ;
if ( F_3 ( V_3 ) ) {
if ( V_4 . V_5 <= 0 )
V_4 . V_5 = V_6 ;
} else
V_4 . V_5 = 0 ;
return F_4 ( V_4 ) ;
}
static void F_5 ( struct V_7 * V_8 , unsigned int V_9 ,
struct V_10 * const V_11 )
{
T_2 V_12 , V_13 ;
struct V_14 * V_15 = & V_8 -> signal -> V_15 [ V_9 ] ;
F_6 ( & V_8 -> V_16 -> V_17 ) ;
V_12 = V_15 -> V_18 ;
V_13 = V_15 -> V_19 ;
if ( V_12 ) {
struct V_20 V_21 ;
T_2 V_22 ;
F_7 ( V_8 , & V_21 ) ;
if ( V_9 == V_23 )
V_22 = V_21 . V_24 + V_21 . V_25 ;
else
V_22 = V_21 . V_24 ;
if ( V_12 < V_22 )
V_12 = V_26 ;
else
V_12 = V_12 - V_22 ;
}
F_8 ( & V_8 -> V_16 -> V_17 ) ;
F_9 ( V_12 , & V_11 -> V_27 ) ;
F_9 ( V_13 , & V_11 -> V_28 ) ;
}
int F_10 ( int V_29 , struct V_10 * V_11 )
{
struct V_7 * V_8 = V_30 ;
switch ( V_29 ) {
case V_31 :
F_6 ( & V_8 -> V_16 -> V_17 ) ;
V_11 -> V_27 = F_1 ( & V_8 -> signal -> V_32 ) ;
V_11 -> V_28 =
F_4 ( V_8 -> signal -> V_33 ) ;
F_8 ( & V_8 -> V_16 -> V_17 ) ;
break;
case V_34 :
F_5 ( V_8 , V_35 , V_11 ) ;
break;
case V_36 :
F_5 ( V_8 , V_23 , V_11 ) ;
break;
default:
return ( - V_37 ) ;
}
return 0 ;
}
enum V_38 F_11 ( struct V_2 * V_3 )
{
struct V_39 * V_40 =
F_12 ( V_3 , struct V_39 , V_32 ) ;
F_13 ( V_31 , V_40 -> V_41 , 0 ) ;
F_14 ( V_42 , V_43 , V_40 -> V_41 ) ;
return V_44 ;
}
static inline T_3 F_15 ( T_2 V_45 , T_4 V_46 )
{
struct V_47 V_48 ;
T_4 V_49 ;
F_16 ( V_45 , & V_48 ) ;
V_49 = F_17 ( & V_48 ) ;
return ( V_49 <= V_46 ) ? 0 : V_49 - V_46 ;
}
static void F_18 ( struct V_7 * V_8 , unsigned int V_9 ,
const struct V_10 * const V_11 ,
struct V_10 * const V_50 )
{
T_2 V_12 , V_51 , V_13 , V_52 ;
T_4 V_53 , V_54 ;
T_3 error , V_55 ;
struct V_14 * V_15 = & V_8 -> signal -> V_15 [ V_9 ] ;
V_51 = F_19 ( & V_11 -> V_27 ) ;
V_54 = F_20 ( & V_11 -> V_27 ) ;
V_52 = F_19 ( & V_11 -> V_28 ) ;
V_53 = F_20 ( & V_11 -> V_28 ) ;
error = F_15 ( V_51 , V_54 ) ;
V_55 = F_15 ( V_52 , V_53 ) ;
F_6 ( & V_8 -> V_16 -> V_17 ) ;
V_12 = V_15 -> V_18 ;
V_13 = V_15 -> V_19 ;
if ( V_12 || V_51 ) {
if ( V_51 > 0 )
V_51 += V_26 ;
F_21 ( V_8 , V_9 , & V_51 , & V_12 ) ;
}
V_15 -> V_18 = V_51 ;
V_15 -> V_19 = V_52 ;
V_15 -> error = error ;
V_15 -> V_55 = V_55 ;
F_22 ( V_9 == V_35 ?
V_34 : V_36 , V_11 , V_51 ) ;
F_8 ( & V_8 -> V_16 -> V_17 ) ;
if ( V_50 ) {
F_9 ( V_12 , & V_50 -> V_27 ) ;
F_9 ( V_13 , & V_50 -> V_28 ) ;
}
}
int F_23 ( int V_29 , struct V_10 * V_11 , struct V_10 * V_50 )
{
struct V_7 * V_8 = V_30 ;
struct V_2 * V_3 ;
T_1 V_18 ;
if ( ! F_24 ( & V_11 -> V_27 ) ||
! F_24 ( & V_11 -> V_28 ) )
return - V_37 ;
switch ( V_29 ) {
case V_31 :
V_56:
F_6 ( & V_8 -> V_16 -> V_17 ) ;
V_3 = & V_8 -> signal -> V_32 ;
if ( V_50 ) {
V_50 -> V_27 = F_1 ( V_3 ) ;
V_50 -> V_28
= F_4 ( V_8 -> signal -> V_33 ) ;
}
if ( F_25 ( V_3 ) < 0 ) {
F_8 ( & V_8 -> V_16 -> V_17 ) ;
goto V_56;
}
V_18 = F_26 ( V_11 -> V_27 ) ;
if ( V_18 . V_5 != 0 ) {
V_8 -> signal -> V_33 =
F_26 ( V_11 -> V_28 ) ;
F_27 ( V_3 , V_18 , V_57 ) ;
} else
V_8 -> signal -> V_33 . V_5 = 0 ;
F_22 ( V_31 , V_11 , 0 ) ;
F_8 ( & V_8 -> V_16 -> V_17 ) ;
break;
case V_34 :
F_18 ( V_8 , V_35 , V_11 , V_50 ) ;
break;
case V_36 :
F_18 ( V_8 , V_23 , V_11 , V_50 ) ;
break;
default:
return - V_37 ;
}
return 0 ;
}
unsigned int F_28 ( unsigned int V_58 )
{
struct V_10 V_59 , V_60 ;
#if V_61 < 64
if ( V_58 > V_62 )
V_58 = V_62 ;
#endif
V_59 . V_27 . V_63 = V_58 ;
V_59 . V_27 . V_64 = 0 ;
V_59 . V_28 . V_63 = V_59 . V_28 . V_64 = 0 ;
F_23 ( V_31 , & V_59 , & V_60 ) ;
if ( ( ! V_60 . V_27 . V_63 && V_60 . V_27 . V_64 ) ||
V_60 . V_27 . V_64 >= 500000 )
V_60 . V_27 . V_63 ++ ;
return V_60 . V_27 . V_63 ;
}
