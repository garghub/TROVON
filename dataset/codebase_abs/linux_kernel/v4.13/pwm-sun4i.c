static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_3 ,
unsigned long V_4 )
{
return F_4 ( V_3 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_3 ,
T_1 V_6 , unsigned long V_4 )
{
F_6 ( V_6 , V_3 -> V_5 + V_4 ) ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_2 V_12 , V_13 ;
T_1 V_6 ;
unsigned int V_14 ;
V_12 = F_8 ( V_11 -> V_15 ) ;
V_6 = F_3 ( V_11 , V_16 ) ;
if ( ( V_6 == V_17 ) && V_11 -> V_18 -> V_19 )
V_14 = 1 ;
else
V_14 = V_20 [ F_9 ( V_6 , V_8 -> V_21 ) ] ;
if ( V_14 == 0 )
return;
if ( V_6 & F_10 ( V_22 , V_8 -> V_21 ) )
V_10 -> V_23 = V_24 ;
else
V_10 -> V_23 = V_25 ;
if ( V_6 & F_10 ( V_26 | V_27 , V_8 -> V_21 ) )
V_10 -> V_28 = true ;
else
V_10 -> V_28 = false ;
V_6 = F_3 ( V_11 , F_11 ( V_8 -> V_21 ) ) ;
V_13 = V_14 * V_29 * F_12 ( V_6 ) ;
V_10 -> V_30 = F_13 ( V_13 , V_12 ) ;
V_13 = V_14 * V_29 * F_14 ( V_6 ) ;
V_10 -> V_31 = F_13 ( V_13 , V_12 ) ;
}
static int F_15 ( struct V_1 * V_11 ,
struct V_9 * V_10 ,
T_1 * V_32 , T_1 * V_33 , unsigned int * V_34 )
{
T_2 V_12 , div = 0 ;
unsigned int V_35 , V_14 = 0 ;
V_12 = F_8 ( V_11 -> V_15 ) ;
if ( V_11 -> V_18 -> V_19 ) {
V_14 = V_17 ;
V_35 = 1 ;
div = V_12 * V_10 -> V_31 + V_29 / 2 ;
F_16 ( div , V_29 ) ;
if ( div - 1 > V_36 )
V_14 = 0 ;
}
if ( V_14 == 0 ) {
for ( V_14 = 0 ; V_14 < V_17 ; V_14 ++ ) {
if ( ! V_20 [ V_14 ] )
continue;
V_35 = V_20 [ V_14 ] ;
div = V_12 ;
F_16 ( div , V_35 ) ;
div = div * V_10 -> V_31 ;
F_16 ( div , V_29 ) ;
if ( div - 1 <= V_36 )
break;
}
if ( div - 1 > V_36 )
return - V_37 ;
}
* V_33 = div ;
div *= V_10 -> V_30 ;
F_16 ( div , V_10 -> V_31 ) ;
* V_32 = div ;
* V_34 = V_14 ;
div = ( T_2 ) V_35 * V_29 * * V_33 ;
V_10 -> V_31 = F_13 ( div , V_12 ) ;
div = ( T_2 ) V_35 * V_29 * * V_32 ;
V_10 -> V_30 = F_13 ( div , V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_9 V_38 ;
T_1 V_39 ;
int V_40 ;
unsigned int V_41 ;
unsigned long V_42 ;
F_18 ( V_8 , & V_38 ) ;
if ( ! V_38 . V_28 ) {
V_40 = F_19 ( V_11 -> V_15 ) ;
if ( V_40 ) {
F_20 ( V_3 -> V_43 , L_1 ) ;
return V_40 ;
}
}
F_21 ( & V_11 -> V_44 ) ;
V_39 = F_3 ( V_11 , V_16 ) ;
if ( ( V_38 . V_31 != V_10 -> V_31 ) ||
( V_38 . V_30 != V_10 -> V_30 ) ) {
T_1 V_31 , V_45 , V_6 ;
unsigned int V_14 ;
V_40 = F_15 ( V_11 , V_10 ,
& V_45 , & V_31 , & V_14 ) ;
if ( V_40 ) {
F_20 ( V_3 -> V_43 , L_2 ) ;
F_22 ( & V_11 -> V_44 ) ;
if ( ! V_38 . V_28 )
F_23 ( V_11 -> V_15 ) ;
return V_40 ;
}
if ( F_9 ( V_39 , V_8 -> V_21 ) != V_14 ) {
V_39 &= ~ F_10 ( V_26 , V_8 -> V_21 ) ;
F_5 ( V_11 , V_39 , V_16 ) ;
V_39 &= ~ F_10 ( V_17 , V_8 -> V_21 ) ;
V_39 |= F_10 ( V_14 , V_8 -> V_21 ) ;
}
V_6 = ( V_45 & V_46 ) | F_24 ( V_31 ) ;
F_5 ( V_11 , V_6 , F_11 ( V_8 -> V_21 ) ) ;
V_11 -> V_47 [ V_8 -> V_21 ] = V_48 +
F_25 ( V_38 . V_31 / 1000 + 1 ) ;
V_11 -> V_49 [ V_8 -> V_21 ] = true ;
}
if ( V_10 -> V_23 != V_24 )
V_39 &= ~ F_10 ( V_22 , V_8 -> V_21 ) ;
else
V_39 |= F_10 ( V_22 , V_8 -> V_21 ) ;
V_39 |= F_10 ( V_26 , V_8 -> V_21 ) ;
if ( V_10 -> V_28 ) {
V_39 |= F_10 ( V_27 , V_8 -> V_21 ) ;
} else if ( ! V_11 -> V_49 [ V_8 -> V_21 ] ) {
V_39 &= ~ F_10 ( V_27 , V_8 -> V_21 ) ;
V_39 &= ~ F_10 ( V_26 , V_8 -> V_21 ) ;
}
F_5 ( V_11 , V_39 , V_16 ) ;
F_22 ( & V_11 -> V_44 ) ;
if ( V_10 -> V_28 )
return 0 ;
if ( ! V_11 -> V_49 [ V_8 -> V_21 ] ) {
F_23 ( V_11 -> V_15 ) ;
return 0 ;
}
V_42 = V_48 ;
if ( V_11 -> V_49 [ V_8 -> V_21 ] &&
F_26 ( V_42 , V_11 -> V_47 [ V_8 -> V_21 ] ) ) {
V_41 = F_27 ( V_11 -> V_47 [ V_8 -> V_21 ] -
V_42 ) ;
if ( ( V_41 / 500 ) > V_50 )
F_28 ( V_41 / 1000 + 1 ) ;
else
F_29 ( V_41 , V_41 * 2 ) ;
}
V_11 -> V_49 [ V_8 -> V_21 ] = false ;
F_21 ( & V_11 -> V_44 ) ;
V_39 = F_3 ( V_11 , V_16 ) ;
V_39 &= ~ F_10 ( V_26 , V_8 -> V_21 ) ;
V_39 &= ~ F_10 ( V_27 , V_8 -> V_21 ) ;
F_5 ( V_11 , V_39 , V_16 ) ;
F_22 ( & V_11 -> V_44 ) ;
F_23 ( V_11 -> V_15 ) ;
return 0 ;
}
static int F_30 ( struct V_51 * V_52 )
{
struct V_1 * V_8 ;
struct V_53 * V_54 ;
int V_40 ;
const struct V_55 * V_56 ;
V_56 = F_31 ( V_57 , & V_52 -> V_43 ) ;
V_8 = F_32 ( & V_52 -> V_43 , sizeof( * V_8 ) , V_58 ) ;
if ( ! V_8 )
return - V_59 ;
V_54 = F_33 ( V_52 , V_60 , 0 ) ;
V_8 -> V_5 = F_34 ( & V_52 -> V_43 , V_54 ) ;
if ( F_35 ( V_8 -> V_5 ) )
return F_36 ( V_8 -> V_5 ) ;
V_8 -> V_15 = F_37 ( & V_52 -> V_43 , NULL ) ;
if ( F_35 ( V_8 -> V_15 ) )
return F_36 ( V_8 -> V_15 ) ;
V_8 -> V_18 = V_56 -> V_18 ;
V_8 -> V_3 . V_43 = & V_52 -> V_43 ;
V_8 -> V_3 . V_61 = & V_62 ;
V_8 -> V_3 . V_5 = - 1 ;
V_8 -> V_3 . V_63 = V_8 -> V_18 -> V_63 ;
V_8 -> V_3 . V_64 = V_65 ;
V_8 -> V_3 . V_66 = 3 ;
F_38 ( & V_8 -> V_44 ) ;
V_40 = F_39 ( & V_8 -> V_3 ) ;
if ( V_40 < 0 ) {
F_20 ( & V_52 -> V_43 , L_3 , V_40 ) ;
return V_40 ;
}
F_40 ( V_52 , V_8 ) ;
return 0 ;
}
static int F_41 ( struct V_51 * V_52 )
{
struct V_1 * V_8 = F_42 ( V_52 ) ;
return F_43 ( & V_8 -> V_3 ) ;
}
