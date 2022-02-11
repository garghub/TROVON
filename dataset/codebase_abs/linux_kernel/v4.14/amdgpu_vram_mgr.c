static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
F_3 ( & V_5 -> V_8 , 0 , V_3 ) ;
F_4 ( & V_5 -> V_9 ) ;
V_2 -> V_10 = V_5 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_10 ;
F_6 ( & V_5 -> V_9 ) ;
if ( ! F_7 ( & V_5 -> V_8 ) ) {
F_8 ( & V_5 -> V_9 ) ;
return - V_11 ;
}
F_9 ( & V_5 -> V_8 ) ;
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_5 ) ;
V_2 -> V_10 = NULL ;
return 0 ;
}
static T_1 F_11 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
T_2 V_16 = V_15 -> V_16 << V_17 ;
T_2 V_18 = ( V_15 -> V_19 + V_15 -> V_16 ) << V_17 ;
if ( V_16 >= V_13 -> V_20 . V_21 )
return 0 ;
return ( V_18 > V_13 -> V_20 . V_21 ?
V_13 -> V_20 . V_21 : V_18 ) - V_16 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
const struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = F_13 ( V_2 -> V_28 ) ;
struct V_4 * V_5 = V_2 -> V_10 ;
struct V_29 * V_8 = & V_5 -> V_8 ;
struct V_14 * V_30 ;
enum V_31 V_32 ;
unsigned long V_33 , V_34 , V_35 , V_36 ;
T_2 V_37 = 0 , V_38 = 0 ;
unsigned V_39 ;
int V_40 ;
V_33 = V_25 -> V_33 ;
if ( ! V_33 )
V_33 = V_2 -> V_19 ;
if ( V_25 -> V_41 & V_42 ||
V_43 == - 1 ) {
V_35 = ~ 0ul ;
V_34 = 1 ;
} else {
V_35 = F_14 ( ( V_44 ) V_43 ,
V_27 -> V_45 ) ;
V_34 = F_15 ( V_27 -> V_46 , V_35 ) ;
}
V_30 = F_16 ( V_34 , sizeof( * V_30 ) , V_6 ) ;
if ( ! V_30 )
return - V_7 ;
V_32 = V_47 ;
if ( V_25 -> V_41 & V_48 )
V_32 = V_49 ;
V_27 -> V_16 = 0 ;
V_36 = V_27 -> V_46 ;
F_6 ( & V_5 -> V_9 ) ;
for ( V_39 = 0 ; V_39 < V_34 ; ++ V_39 ) {
unsigned long V_50 = F_17 ( V_36 , V_35 ) ;
V_44 V_51 = V_27 -> V_45 ;
unsigned long V_16 ;
if ( V_50 == V_35 )
V_51 = V_35 ;
V_40 = F_18 ( V_8 , & V_30 [ V_39 ] ,
V_50 , V_51 , 0 ,
V_25 -> V_52 , V_33 ,
V_32 ) ;
if ( F_19 ( V_40 ) )
goto error;
V_37 += V_30 [ V_39 ] . V_19 << V_17 ;
V_38 += F_11 ( V_13 , & V_30 [ V_39 ] ) ;
V_16 = V_30 [ V_39 ] . V_16 + V_30 [ V_39 ] . V_19 ;
if ( V_16 > V_27 -> V_46 )
V_16 -= V_27 -> V_46 ;
else
V_16 = 0 ;
V_27 -> V_16 = F_14 ( V_27 -> V_16 , V_16 ) ;
V_36 -= V_50 ;
}
F_8 ( & V_5 -> V_9 ) ;
F_20 ( V_37 , & V_5 -> V_37 ) ;
F_20 ( V_38 , & V_5 -> V_38 ) ;
V_27 -> V_53 = V_30 ;
return 0 ;
error:
while ( V_39 -- )
F_21 ( & V_30 [ V_39 ] ) ;
F_8 ( & V_5 -> V_9 ) ;
F_10 ( V_30 ) ;
return V_40 == - V_54 ? 0 : V_40 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_12 * V_13 = F_13 ( V_2 -> V_28 ) ;
struct V_4 * V_5 = V_2 -> V_10 ;
struct V_14 * V_30 = V_27 -> V_53 ;
T_2 V_37 = 0 , V_38 = 0 ;
unsigned V_50 = V_27 -> V_46 ;
if ( ! V_27 -> V_53 )
return;
F_6 ( & V_5 -> V_9 ) ;
while ( V_50 ) {
V_50 -= V_30 -> V_19 ;
F_21 ( V_30 ) ;
V_37 += V_30 -> V_19 << V_17 ;
V_38 += F_11 ( V_13 , V_30 ) ;
++ V_30 ;
}
F_8 ( & V_5 -> V_9 ) ;
F_23 ( V_37 , & V_5 -> V_37 ) ;
F_23 ( V_38 , & V_5 -> V_38 ) ;
F_10 ( V_27 -> V_53 ) ;
V_27 -> V_53 = NULL ;
}
T_2 F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_10 ;
return F_25 ( & V_5 -> V_37 ) ;
}
T_2 F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_10 ;
return F_25 ( & V_5 -> V_38 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_4 * V_5 = V_2 -> V_10 ;
F_6 ( & V_5 -> V_9 ) ;
F_28 ( & V_5 -> V_8 , V_56 ) ;
F_8 ( & V_5 -> V_9 ) ;
F_29 ( V_56 , L_1 ,
V_2 -> V_19 , F_24 ( V_2 ) >> 20 ,
F_26 ( V_2 ) >> 20 ) ;
}
