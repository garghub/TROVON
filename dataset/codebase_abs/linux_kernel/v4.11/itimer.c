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
V_11 -= V_21 ;
}
F_8 ( & V_7 -> V_15 -> V_16 ) ;
V_10 -> V_26 = F_9 ( V_11 ) ;
V_10 -> V_27 = F_9 ( V_12 ) ;
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
static void F_15 ( struct V_6 * V_7 , unsigned int V_8 ,
const struct V_9 * const V_10 ,
struct V_9 * const V_44 )
{
T_2 V_45 , V_46 , V_47 , V_48 ;
struct V_13 * V_14 = & V_7 -> signal -> V_14 [ V_8 ] ;
V_46 = F_16 ( & V_10 -> V_26 ) ;
V_48 = F_16 ( & V_10 -> V_27 ) ;
F_6 ( & V_7 -> V_15 -> V_16 ) ;
V_45 = V_14 -> V_17 ;
V_47 = V_14 -> V_18 ;
if ( V_45 || V_46 ) {
if ( V_46 > 0 )
V_46 += V_25 ;
F_17 ( V_7 , V_8 , & V_46 , & V_45 ) ;
}
V_14 -> V_17 = V_46 ;
V_14 -> V_18 = V_48 ;
F_18 ( V_8 == V_34 ?
V_33 : V_35 , V_10 , V_46 ) ;
F_8 ( & V_7 -> V_15 -> V_16 ) ;
if ( V_44 ) {
V_44 -> V_26 = F_9 ( V_45 ) ;
V_44 -> V_27 = F_9 ( V_47 ) ;
}
}
int F_19 ( int V_28 , struct V_9 * V_10 , struct V_9 * V_44 )
{
struct V_6 * V_7 = V_29 ;
struct V_2 * V_3 ;
T_1 V_17 ;
if ( ! F_20 ( & V_10 -> V_26 ) ||
! F_20 ( & V_10 -> V_27 ) )
return - V_36 ;
switch ( V_28 ) {
case V_30 :
V_49:
F_6 ( & V_7 -> V_15 -> V_16 ) ;
V_3 = & V_7 -> signal -> V_31 ;
if ( V_44 ) {
V_44 -> V_26 = F_1 ( V_3 ) ;
V_44 -> V_27
= F_4 ( V_7 -> signal -> V_32 ) ;
}
if ( F_21 ( V_3 ) < 0 ) {
F_8 ( & V_7 -> V_15 -> V_16 ) ;
goto V_49;
}
V_17 = F_22 ( V_10 -> V_26 ) ;
if ( V_17 != 0 ) {
V_7 -> signal -> V_32 =
F_22 ( V_10 -> V_27 ) ;
F_23 ( V_3 , V_17 , V_50 ) ;
} else
V_7 -> signal -> V_32 = 0 ;
F_18 ( V_30 , V_10 , 0 ) ;
F_8 ( & V_7 -> V_15 -> V_16 ) ;
break;
case V_33 :
F_15 ( V_7 , V_34 , V_10 , V_44 ) ;
break;
case V_35 :
F_15 ( V_7 , V_22 , V_10 , V_44 ) ;
break;
default:
return - V_36 ;
}
return 0 ;
}
static unsigned int F_24 ( unsigned int V_51 )
{
struct V_9 V_52 , V_53 ;
#if V_54 < 64
if ( V_51 > V_55 )
V_51 = V_55 ;
#endif
V_52 . V_26 . V_56 = V_51 ;
V_52 . V_26 . V_57 = 0 ;
V_52 . V_27 . V_56 = V_52 . V_27 . V_57 = 0 ;
F_19 ( V_30 , & V_52 , & V_53 ) ;
if ( ( ! V_53 . V_26 . V_56 && V_53 . V_26 . V_57 ) ||
V_53 . V_26 . V_57 >= 500000 )
V_53 . V_26 . V_56 ++ ;
return V_53 . V_26 . V_56 ;
}
