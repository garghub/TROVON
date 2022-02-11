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
if ( ! F_7 ( V_12 , V_20 ) ) {
struct V_21 V_22 ;
T_2 V_23 ;
F_8 ( V_8 , & V_22 ) ;
if ( V_9 == V_24 )
V_23 = F_9 ( V_22 . V_25 , V_22 . V_26 ) ;
else
V_23 = V_22 . V_25 ;
if ( F_10 ( V_12 , V_23 ) )
V_12 = V_27 ;
else
V_12 = F_11 ( V_12 , V_23 ) ;
}
F_12 ( & V_8 -> V_16 -> V_17 ) ;
F_13 ( V_12 , & V_11 -> V_28 ) ;
F_13 ( V_13 , & V_11 -> V_29 ) ;
}
int F_14 ( int V_30 , struct V_10 * V_11 )
{
struct V_7 * V_8 = V_31 ;
switch ( V_30 ) {
case V_32 :
F_6 ( & V_8 -> V_16 -> V_17 ) ;
V_11 -> V_28 = F_1 ( & V_8 -> signal -> V_33 ) ;
V_11 -> V_29 =
F_4 ( V_8 -> signal -> V_34 ) ;
F_12 ( & V_8 -> V_16 -> V_17 ) ;
break;
case V_35 :
F_5 ( V_8 , V_36 , V_11 ) ;
break;
case V_37 :
F_5 ( V_8 , V_24 , V_11 ) ;
break;
default:
return ( - V_38 ) ;
}
return 0 ;
}
enum V_39 F_15 ( struct V_2 * V_3 )
{
struct V_40 * V_41 =
F_16 ( V_3 , struct V_40 , V_33 ) ;
F_17 ( V_32 , V_41 -> V_42 , 0 ) ;
F_18 ( V_43 , V_44 , V_41 -> V_42 ) ;
return V_45 ;
}
static inline T_3 F_19 ( T_2 V_46 , T_4 V_47 )
{
struct V_48 V_49 ;
T_4 V_50 ;
F_20 ( V_46 , & V_49 ) ;
V_50 = F_21 ( & V_49 ) ;
return ( V_50 <= V_47 ) ? 0 : V_50 - V_47 ;
}
static void F_22 ( struct V_7 * V_8 , unsigned int V_9 ,
const struct V_10 * const V_11 ,
struct V_10 * const V_51 )
{
T_2 V_12 , V_52 , V_13 , V_53 ;
T_4 V_54 , V_55 ;
T_3 error , V_56 ;
struct V_14 * V_15 = & V_8 -> signal -> V_15 [ V_9 ] ;
V_52 = F_23 ( & V_11 -> V_28 ) ;
V_55 = F_24 ( & V_11 -> V_28 ) ;
V_53 = F_23 ( & V_11 -> V_29 ) ;
V_54 = F_24 ( & V_11 -> V_29 ) ;
error = F_19 ( V_52 , V_55 ) ;
V_56 = F_19 ( V_53 , V_54 ) ;
F_6 ( & V_8 -> V_16 -> V_17 ) ;
V_12 = V_15 -> V_18 ;
V_13 = V_15 -> V_19 ;
if ( ! F_7 ( V_12 , V_20 ) ||
! F_7 ( V_52 , V_20 ) ) {
if ( F_25 ( V_52 , V_20 ) )
V_52 = F_9 ( V_52 , V_27 ) ;
F_26 ( V_8 , V_9 , & V_52 , & V_12 ) ;
}
V_15 -> V_18 = V_52 ;
V_15 -> V_19 = V_53 ;
V_15 -> error = error ;
V_15 -> V_56 = V_56 ;
F_27 ( V_9 == V_36 ?
V_35 : V_37 , V_11 , V_52 ) ;
F_12 ( & V_8 -> V_16 -> V_17 ) ;
if ( V_51 ) {
F_13 ( V_12 , & V_51 -> V_28 ) ;
F_13 ( V_13 , & V_51 -> V_29 ) ;
}
}
int F_28 ( int V_30 , struct V_10 * V_11 , struct V_10 * V_51 )
{
struct V_7 * V_8 = V_31 ;
struct V_2 * V_3 ;
T_1 V_18 ;
if ( ! F_29 ( & V_11 -> V_28 ) ||
! F_29 ( & V_11 -> V_29 ) )
return - V_38 ;
switch ( V_30 ) {
case V_32 :
V_57:
F_6 ( & V_8 -> V_16 -> V_17 ) ;
V_3 = & V_8 -> signal -> V_33 ;
if ( V_51 ) {
V_51 -> V_28 = F_1 ( V_3 ) ;
V_51 -> V_29
= F_4 ( V_8 -> signal -> V_34 ) ;
}
if ( F_30 ( V_3 ) < 0 ) {
F_12 ( & V_8 -> V_16 -> V_17 ) ;
goto V_57;
}
V_18 = F_31 ( V_11 -> V_28 ) ;
if ( V_18 . V_5 != 0 ) {
V_8 -> signal -> V_34 =
F_31 ( V_11 -> V_29 ) ;
F_32 ( V_3 , V_18 , V_58 ) ;
} else
V_8 -> signal -> V_34 . V_5 = 0 ;
F_27 ( V_32 , V_11 , 0 ) ;
F_12 ( & V_8 -> V_16 -> V_17 ) ;
break;
case V_35 :
F_22 ( V_8 , V_36 , V_11 , V_51 ) ;
break;
case V_37 :
F_22 ( V_8 , V_24 , V_11 , V_51 ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
unsigned int F_33 ( unsigned int V_59 )
{
struct V_10 V_60 , V_61 ;
#if V_62 < 64
if ( V_59 > V_63 )
V_59 = V_63 ;
#endif
V_60 . V_28 . V_64 = V_59 ;
V_60 . V_28 . V_65 = 0 ;
V_60 . V_29 . V_64 = V_60 . V_29 . V_65 = 0 ;
F_28 ( V_32 , & V_60 , & V_61 ) ;
if ( ( ! V_61 . V_28 . V_64 && V_61 . V_28 . V_65 ) ||
V_61 . V_28 . V_65 >= 500000 )
V_61 . V_28 . V_64 ++ ;
return V_61 . V_28 . V_64 ;
}
