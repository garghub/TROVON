static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
unsigned int V_11 ;
int V_12 ;
if ( V_8 -> V_13 ) {
struct V_14 * V_15 = V_10 -> V_16 ;
T_1 V_17 = V_8 -> V_18 * 256 ;
unsigned long V_19 ;
T_1 V_20 ;
T_2 V_21 ;
int V_22 ;
if ( ! V_3 -> V_23 || ! V_3 -> V_23 -> V_24 ) {
V_19 = F_4 ( V_15 ) ;
if ( ! V_19 )
return - V_25 ;
V_20 = ( T_1 ) V_26 * 256 ;
F_5 ( V_20 , V_19 ) ;
}
if ( ( V_3 -> V_23 && V_3 -> V_23 -> V_24 ) ||
V_20 > V_8 -> V_27 ) {
V_15 = V_10 -> V_28 ;
V_19 = F_4 ( V_15 ) ;
if ( ! V_19 )
return - V_25 ;
V_20 = ( T_1 ) V_26 * 256 ;
F_5 ( V_20 , V_19 ) ;
}
for ( V_22 = 0 ; V_22 <= V_29 ; V_22 ++ ) {
if ( ! V_22 && V_3 -> V_23 &&
V_3 -> V_23 -> V_30 )
continue;
if ( ( V_20 << V_22 ) >= V_8 -> V_27 )
break;
}
if ( V_22 > V_29 )
return - V_25 ;
V_21 = F_6 ( V_22 ) ;
if ( V_15 != V_3 -> V_31 ) {
T_2 V_32 = 0 ;
int V_12 ;
V_12 = F_7 ( V_15 ) ;
if ( V_12 )
return V_12 ;
F_8 ( V_3 -> V_31 ) ;
V_3 -> V_31 = V_15 ;
if ( V_15 == V_10 -> V_28 )
V_32 = V_33 ;
V_12 = F_9 ( V_10 -> V_34 ,
F_10 ( 0 ) ,
V_33 ,
V_32 ) ;
if ( V_12 )
return V_12 ;
}
F_5 ( V_17 , V_8 -> V_27 ) ;
if ( V_17 > 255 )
V_17 = 255 ;
V_21 |= F_11 ( V_17 ) ;
if ( V_8 -> V_35 == V_36 )
V_21 |= V_37 ;
V_12 = F_9 ( V_10 -> V_34 , F_10 ( 6 ) ,
V_38 |
V_39 |
V_37 ,
V_21 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_12 ( V_10 -> V_34 , V_40 ,
V_41 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_13 ( V_10 -> V_34 , V_42 ,
V_11 ,
V_11 & V_41 ,
10 , 0 ) ;
if ( V_12 )
return V_12 ;
} else {
V_12 = F_12 ( V_10 -> V_34 , V_43 ,
V_41 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_13 ( V_10 -> V_34 , V_42 ,
V_11 ,
! ( V_11 & V_41 ) ,
10 , 0 ) ;
if ( V_12 )
return V_12 ;
F_8 ( V_3 -> V_31 ) ;
V_3 -> V_31 = NULL ;
}
return 0 ;
}
static int F_14 ( struct V_44 * V_45 )
{
struct V_1 * V_3 = F_15 ( V_45 ) ;
if ( F_16 ( & V_3 -> V_3 . V_46 [ 0 ] ) )
F_8 ( V_3 -> V_10 -> V_47 ) ;
return 0 ;
}
static int F_17 ( struct V_44 * V_45 )
{
struct V_1 * V_3 = F_15 ( V_45 ) ;
struct V_7 V_8 ;
int V_12 ;
F_18 ( & V_3 -> V_3 . V_46 [ 0 ] , & V_8 ) ;
if ( ! V_8 . V_13 ) {
V_12 = F_7 ( V_3 -> V_10 -> V_47 ) ;
if ( V_12 )
return V_12 ;
}
return F_3 ( & V_3 -> V_3 , & V_3 -> V_3 . V_46 [ 0 ] , & V_8 ) ;
}
static int F_19 ( struct V_48 * V_49 )
{
const struct V_50 * V_51 ;
struct V_44 * V_45 = & V_49 -> V_45 ;
struct V_1 * V_3 ;
struct V_9 * V_10 ;
int V_12 ;
V_10 = F_15 ( V_45 -> V_52 ) ;
V_3 = F_20 ( V_45 , sizeof( * V_3 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
V_12 = F_7 ( V_10 -> V_47 ) ;
if ( V_12 )
return V_12 ;
V_51 = F_21 ( V_55 , V_45 -> V_52 -> V_56 ) ;
if ( V_51 )
V_3 -> V_23 = V_51 -> V_57 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_3 . V_58 = & V_59 ;
V_3 -> V_3 . V_45 = V_45 ;
V_3 -> V_3 . V_60 = - 1 ;
V_3 -> V_3 . V_61 = 1 ;
V_3 -> V_3 . V_62 = V_63 ;
V_3 -> V_3 . V_64 = 3 ;
V_12 = F_22 ( & V_3 -> V_3 , V_65 ) ;
if ( V_12 ) {
F_8 ( V_10 -> V_47 ) ;
return V_12 ;
}
F_23 ( V_49 , V_3 ) ;
return 0 ;
}
static int F_24 ( struct V_48 * V_49 )
{
struct V_1 * V_3 = F_25 ( V_49 ) ;
int V_12 ;
V_12 = F_26 ( & V_3 -> V_3 ) ;
if ( V_12 )
return V_12 ;
F_8 ( V_3 -> V_10 -> V_47 ) ;
return 0 ;
}
