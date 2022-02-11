static void F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
return;
}
int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_2 ,
int V_8 , int V_9 , enum V_10 V_11 )
{
struct V_12 * V_13 = V_6 -> V_13 ;
int V_14 ;
V_2 -> V_15 = V_8 ;
V_2 -> V_16 = V_2 -> V_15 * V_13 -> V_17 -> V_18 . V_19 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_20 = V_11 ;
F_3 ( & V_2 -> V_21 ) ;
V_14 = F_4 ( V_13 -> V_17 , & V_2 -> V_22 ,
V_2 -> V_16 , 2 * V_23 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_5 ( & V_2 -> V_22 . V_24 ) ;
if ( V_14 )
F_6 ( V_13 -> V_17 , & V_2 -> V_22 , V_2 -> V_16 ) ;
else
V_2 -> V_24 = (struct V_25 * ) V_2 -> V_22 . V_24 . V_26 . V_24 ;
return V_14 ;
}
int F_7 ( struct V_5 * V_6 , struct V_7 * V_2 ,
int V_27 )
{
struct V_12 * V_13 = V_6 -> V_13 ;
int V_14 = 0 ;
char V_28 [ 25 ] ;
struct V_29 * V_30 =
#ifdef F_8
V_6 -> V_17 -> V_31 ;
#else
NULL ;
#endif
V_2 -> V_17 = V_13 -> V_32 [ V_6 -> V_33 ] ;
V_2 -> V_34 . V_35 = V_2 -> V_22 . V_36 . V_36 ;
V_2 -> V_34 . V_37 = V_2 -> V_22 . V_36 . V_36 + 1 ;
* V_2 -> V_34 . V_35 = 0 ;
* V_2 -> V_34 . V_37 = 0 ;
memset ( V_2 -> V_24 , 0 , V_2 -> V_16 ) ;
if ( V_2 -> V_20 == V_38 ) {
if ( V_13 -> V_17 -> V_18 . V_39 ) {
if ( ! V_2 -> V_40 ) {
sprintf ( V_28 , L_1 , V_6 -> V_17 -> V_28 ,
V_2 -> V_9 ) ;
if ( F_9 ( V_13 -> V_17 , V_28 , V_30 ,
& V_2 -> V_40 ) ) {
V_2 -> V_40 = ( V_2 -> V_9 + 1 + V_6 -> V_33 )
% V_13 -> V_17 -> V_18 . V_41 ;
F_10 ( V_13 , L_2
L_3 ,
V_28 ) ;
}
}
} else {
V_2 -> V_40 = ( V_2 -> V_9 + 1 + V_6 -> V_33 ) %
V_13 -> V_17 -> V_18 . V_41 ;
}
} else {
struct V_7 * V_42 ;
V_27 = V_27 % V_6 -> V_43 ;
V_42 = & V_6 -> V_42 [ V_27 ] ;
V_2 -> V_40 = V_42 -> V_40 ;
}
if ( ! V_2 -> V_20 )
V_2 -> V_15 = V_6 -> V_44 [ V_2 -> V_9 ] . V_45 ;
V_14 = F_11 ( V_13 -> V_17 , V_2 -> V_15 , & V_2 -> V_22 . V_46 , & V_13 -> V_47 ,
V_2 -> V_22 . V_36 . V_48 , & V_2 -> V_34 , V_2 -> V_40 , 0 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_34 . V_49 = V_2 -> V_20 ? V_50 : V_51 ;
V_2 -> V_34 . V_4 = F_1 ;
if ( ! V_2 -> V_20 ) {
F_12 ( V_2 -> V_17 , & V_2 -> V_52 , V_53 , 64 ) ;
F_13 ( & V_2 -> V_52 ) ;
}
return 0 ;
}
void F_14 ( struct V_5 * V_6 , struct V_7 * V_2 )
{
struct V_12 * V_13 = V_6 -> V_13 ;
F_15 ( & V_2 -> V_22 . V_24 ) ;
F_6 ( V_13 -> V_17 , & V_2 -> V_22 , V_2 -> V_16 ) ;
if ( V_6 -> V_13 -> V_17 -> V_18 . V_39 && V_2 -> V_40 )
F_16 ( V_6 -> V_13 -> V_17 , V_2 -> V_40 ) ;
V_2 -> V_40 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_24 = NULL ;
}
void F_17 ( struct V_5 * V_6 , struct V_7 * V_2 )
{
if ( ! V_2 -> V_20 ) {
F_18 ( & V_2 -> V_52 ) ;
F_19 ( & V_2 -> V_52 ) ;
}
F_20 ( V_6 -> V_13 -> V_17 , & V_2 -> V_34 ) ;
}
int F_21 ( struct V_5 * V_6 , struct V_7 * V_2 )
{
return F_22 ( V_6 -> V_13 -> V_17 , & V_2 -> V_34 ,
V_2 -> V_54 , V_2 -> V_55 ) ;
}
int F_23 ( struct V_5 * V_6 , struct V_7 * V_2 )
{
F_24 ( & V_2 -> V_34 , V_56 , V_6 -> V_13 -> V_57 ,
& V_6 -> V_13 -> V_58 ) ;
return 0 ;
}
