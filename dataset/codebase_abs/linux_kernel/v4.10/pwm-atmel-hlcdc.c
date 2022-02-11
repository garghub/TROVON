static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_4 ,
struct V_5 * V_6 ,
int V_7 , int V_8 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_14 = V_7 * 256 ;
unsigned long V_15 ;
T_1 V_16 ;
T_2 V_17 ;
int V_18 ;
if ( ! V_3 -> V_19 || ! V_3 -> V_19 -> V_20 ) {
V_15 = F_4 ( V_12 ) ;
if ( ! V_15 )
return - V_21 ;
V_16 = ( T_1 ) V_22 * 256 ;
F_5 ( V_16 , V_15 ) ;
}
if ( ( V_3 -> V_19 && V_3 -> V_19 -> V_20 ) ||
V_16 > V_8 ) {
V_12 = V_10 -> V_23 ;
V_15 = F_4 ( V_12 ) ;
if ( ! V_15 )
return - V_21 ;
V_16 = ( T_1 ) V_22 * 256 ;
F_5 ( V_16 , V_15 ) ;
}
for ( V_18 = 0 ; V_18 <= V_24 ; V_18 ++ ) {
if ( ! V_18 && V_3 -> V_19 && V_3 -> V_19 -> V_25 )
continue;
if ( ( V_16 << V_18 ) >= V_8 )
break;
}
if ( V_18 > V_24 )
return - V_21 ;
V_17 = F_6 ( V_18 ) ;
if ( V_12 != V_3 -> V_26 ) {
T_2 V_27 = 0 ;
int V_28 ;
V_28 = F_7 ( V_12 ) ;
if ( V_28 )
return V_28 ;
F_8 ( V_3 -> V_26 ) ;
V_3 -> V_26 = V_12 ;
if ( V_12 == V_10 -> V_23 )
V_27 = V_29 ;
V_28 = F_9 ( V_10 -> V_30 , F_10 ( 0 ) ,
V_29 , V_27 ) ;
if ( V_28 )
return V_28 ;
}
F_5 ( V_14 , V_8 ) ;
if ( V_14 > 255 )
V_14 = 255 ;
V_17 |= F_11 ( V_14 ) ;
return F_9 ( V_10 -> V_30 , F_10 ( 6 ) ,
V_31 |
V_32 ,
V_17 ) ;
}
static int F_12 ( struct V_2 * V_4 ,
struct V_5 * V_6 ,
enum V_33 V_34 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
T_2 V_35 = 0 ;
if ( V_34 == V_36 )
V_35 = V_37 ;
return F_9 ( V_10 -> V_30 , F_10 ( 6 ) ,
V_37 , V_35 ) ;
}
static int F_13 ( struct V_2 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
T_2 V_38 ;
int V_28 ;
V_28 = F_14 ( V_10 -> V_30 , V_39 , V_40 ) ;
if ( V_28 )
return V_28 ;
while ( true ) {
V_28 = F_15 ( V_10 -> V_30 , V_41 , & V_38 ) ;
if ( V_28 )
return V_28 ;
if ( ( V_38 & V_40 ) != 0 )
break;
F_16 ( 1 , 10 ) ;
}
return 0 ;
}
static void F_17 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
T_2 V_38 ;
int V_28 ;
V_28 = F_14 ( V_10 -> V_30 , V_42 , V_40 ) ;
if ( V_28 )
return;
while ( true ) {
V_28 = F_15 ( V_10 -> V_30 , V_41 , & V_38 ) ;
if ( V_28 )
return;
if ( ( V_38 & V_40 ) == 0 )
break;
F_16 ( 1 , 10 ) ;
}
}
static int F_18 ( struct V_43 * V_44 )
{
const struct V_45 * V_46 ;
struct V_47 * V_48 = & V_44 -> V_48 ;
struct V_1 * V_3 ;
struct V_9 * V_10 ;
int V_28 ;
V_10 = F_19 ( V_48 -> V_49 ) ;
V_3 = F_20 ( V_48 , sizeof( * V_3 ) , V_50 ) ;
if ( ! V_3 )
return - V_51 ;
V_28 = F_7 ( V_10 -> V_52 ) ;
if ( V_28 )
return V_28 ;
V_46 = F_21 ( V_53 , V_48 -> V_49 -> V_54 ) ;
if ( V_46 )
V_3 -> V_19 = V_46 -> V_55 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_3 . V_56 = & V_57 ;
V_3 -> V_3 . V_48 = V_48 ;
V_3 -> V_3 . V_58 = - 1 ;
V_3 -> V_3 . V_59 = 1 ;
V_3 -> V_3 . V_60 = V_61 ;
V_3 -> V_3 . V_62 = 3 ;
V_3 -> V_3 . V_63 = 1 ;
V_28 = F_22 ( & V_3 -> V_3 , V_64 ) ;
if ( V_28 ) {
F_8 ( V_10 -> V_52 ) ;
return V_28 ;
}
F_23 ( V_44 , V_3 ) ;
return 0 ;
}
static int F_24 ( struct V_43 * V_44 )
{
struct V_1 * V_3 = F_25 ( V_44 ) ;
int V_28 ;
V_28 = F_26 ( & V_3 -> V_3 ) ;
if ( V_28 )
return V_28 ;
F_8 ( V_3 -> V_10 -> V_52 ) ;
return 0 ;
}
