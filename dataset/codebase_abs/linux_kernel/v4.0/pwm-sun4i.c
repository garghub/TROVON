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
static int F_7 ( struct V_2 * V_3 , struct V_7 * V_8 ,
int V_9 , int V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_12 , V_13 , V_6 , V_14 ;
T_2 V_15 , div = 0 ;
unsigned int V_16 = 0 ;
int V_17 ;
V_15 = F_8 ( V_11 -> V_18 ) ;
if ( V_11 -> V_19 -> V_20 ) {
V_16 = V_21 ;
div = V_15 * V_10 + V_22 / 2 ;
F_9 ( div , V_22 ) ;
if ( div - 1 > V_23 )
V_16 = 0 ;
}
if ( V_16 == 0 ) {
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ ) {
if ( ! V_24 [ V_16 ] )
continue;
div = V_15 ;
F_9 ( div , V_24 [ V_16 ] ) ;
div = div * V_10 ;
F_9 ( div , V_22 ) ;
if ( div - 1 <= V_23 )
break;
}
if ( div - 1 > V_23 ) {
F_10 ( V_3 -> V_25 , L_1 ) ;
return - V_26 ;
}
}
V_12 = div ;
div *= V_9 ;
F_9 ( div , V_10 ) ;
V_13 = div ;
V_17 = F_11 ( V_11 -> V_18 ) ;
if ( V_17 ) {
F_10 ( V_3 -> V_25 , L_2 ) ;
return V_17 ;
}
F_12 ( & V_11 -> V_27 ) ;
V_6 = F_3 ( V_11 , V_28 ) ;
if ( V_11 -> V_19 -> V_29 && ( V_6 & F_13 ( V_8 -> V_30 ) ) ) {
F_14 ( & V_11 -> V_27 ) ;
F_15 ( V_11 -> V_18 ) ;
return - V_31 ;
}
V_14 = V_6 & F_16 ( V_32 , V_8 -> V_30 ) ;
if ( V_14 ) {
V_6 &= ~ F_16 ( V_32 , V_8 -> V_30 ) ;
F_5 ( V_11 , V_6 , V_28 ) ;
}
V_6 = F_3 ( V_11 , V_28 ) ;
V_6 &= ~ F_16 ( V_21 , V_8 -> V_30 ) ;
V_6 |= F_16 ( V_16 , V_8 -> V_30 ) ;
F_5 ( V_11 , V_6 , V_28 ) ;
V_6 = ( V_13 & V_33 ) | F_17 ( V_12 ) ;
F_5 ( V_11 , V_6 , F_18 ( V_8 -> V_30 ) ) ;
if ( V_14 ) {
V_6 = F_3 ( V_11 , V_28 ) ;
V_6 |= V_14 ;
F_5 ( V_11 , V_6 , V_28 ) ;
}
F_14 ( & V_11 -> V_27 ) ;
F_15 ( V_11 -> V_18 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_7 * V_8 ,
enum V_34 V_35 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_6 ;
int V_36 ;
V_36 = F_11 ( V_11 -> V_18 ) ;
if ( V_36 ) {
F_10 ( V_3 -> V_25 , L_2 ) ;
return V_36 ;
}
F_12 ( & V_11 -> V_27 ) ;
V_6 = F_3 ( V_11 , V_28 ) ;
if ( V_35 != V_37 )
V_6 &= ~ F_16 ( V_38 , V_8 -> V_30 ) ;
else
V_6 |= F_16 ( V_38 , V_8 -> V_30 ) ;
F_5 ( V_11 , V_6 , V_28 ) ;
F_14 ( & V_11 -> V_27 ) ;
F_15 ( V_11 -> V_18 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_6 ;
int V_36 ;
V_36 = F_11 ( V_11 -> V_18 ) ;
if ( V_36 ) {
F_10 ( V_3 -> V_25 , L_2 ) ;
return V_36 ;
}
F_12 ( & V_11 -> V_27 ) ;
V_6 = F_3 ( V_11 , V_28 ) ;
V_6 |= F_16 ( V_39 , V_8 -> V_30 ) ;
V_6 |= F_16 ( V_32 , V_8 -> V_30 ) ;
F_5 ( V_11 , V_6 , V_28 ) ;
F_14 ( & V_11 -> V_27 ) ;
return 0 ;
}
static void F_21 ( struct V_2 * V_3 , struct V_7 * V_8 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_6 ;
F_12 ( & V_11 -> V_27 ) ;
V_6 = F_3 ( V_11 , V_28 ) ;
V_6 &= ~ F_16 ( V_39 , V_8 -> V_30 ) ;
V_6 &= ~ F_16 ( V_32 , V_8 -> V_30 ) ;
F_5 ( V_11 , V_6 , V_28 ) ;
F_14 ( & V_11 -> V_27 ) ;
F_15 ( V_11 -> V_18 ) ;
}
static int F_22 ( struct V_40 * V_41 )
{
struct V_1 * V_8 ;
struct V_42 * V_43 ;
T_1 V_6 ;
int V_44 , V_36 ;
const struct V_45 * V_46 ;
V_46 = F_23 ( V_47 , & V_41 -> V_25 ) ;
V_8 = F_24 ( & V_41 -> V_25 , sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 )
return - V_49 ;
V_43 = F_25 ( V_41 , V_50 , 0 ) ;
V_8 -> V_5 = F_26 ( & V_41 -> V_25 , V_43 ) ;
if ( F_27 ( V_8 -> V_5 ) )
return F_28 ( V_8 -> V_5 ) ;
V_8 -> V_18 = F_29 ( & V_41 -> V_25 , NULL ) ;
if ( F_27 ( V_8 -> V_18 ) )
return F_28 ( V_8 -> V_18 ) ;
V_8 -> V_3 . V_25 = & V_41 -> V_25 ;
V_8 -> V_3 . V_51 = & V_52 ;
V_8 -> V_3 . V_5 = - 1 ;
V_8 -> V_3 . V_53 = 2 ;
V_8 -> V_3 . V_54 = true ;
V_8 -> V_3 . V_55 = V_56 ;
V_8 -> V_3 . V_57 = 3 ;
V_8 -> V_19 = V_46 -> V_19 ;
F_30 ( & V_8 -> V_27 ) ;
V_36 = F_31 ( & V_8 -> V_3 ) ;
if ( V_36 < 0 ) {
F_10 ( & V_41 -> V_25 , L_3 , V_36 ) ;
return V_36 ;
}
F_32 ( V_41 , V_8 ) ;
V_36 = F_11 ( V_8 -> V_18 ) ;
if ( V_36 ) {
F_10 ( & V_41 -> V_25 , L_2 ) ;
goto V_58;
}
V_6 = F_3 ( V_8 , V_28 ) ;
for ( V_44 = 0 ; V_44 < V_8 -> V_3 . V_53 ; V_44 ++ )
if ( ! ( V_6 & F_16 ( V_38 , V_44 ) ) )
V_8 -> V_3 . V_59 [ V_44 ] . V_35 = V_60 ;
F_15 ( V_8 -> V_18 ) ;
return 0 ;
V_58:
F_33 ( & V_8 -> V_3 ) ;
return V_36 ;
}
static int F_34 ( struct V_40 * V_41 )
{
struct V_1 * V_8 = F_35 ( V_41 ) ;
return F_33 ( & V_8 -> V_3 ) ;
}
