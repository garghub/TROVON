static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_4 -> V_11 . V_12 . V_13 [ 0 ] = V_10 -> V_14 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_2 -> V_17 ;
unsigned int V_18 = V_4 -> V_11 . V_12 . V_13 [ 0 ] ;
if ( V_18 >= V_16 -> V_19 )
return - V_20 ;
F_5 ( V_10 -> V_21 , V_18 ) ;
V_10 -> V_14 = V_18 ;
return F_6 ( V_2 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_4 -> V_11 . V_12 . V_13 [ 0 ] = V_10 -> V_22 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_2 -> V_17 ;
unsigned int V_18 = V_4 -> V_11 . V_12 . V_13 [ 0 ] ;
if ( V_18 >= V_16 -> V_19 )
return - V_20 ;
F_5 ( V_10 -> V_23 , V_18 ) ;
V_10 -> V_22 = V_18 ;
return F_6 ( V_2 , V_4 ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_4 -> V_11 . V_12 . V_13 [ 0 ] = V_10 -> V_24 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_25 = ! ! V_4 -> V_11 . integer . V_11 [ 0 ] ;
if ( V_10 -> V_24 == V_25 )
return 0 ;
F_5 ( V_10 -> V_26 , V_25 ) ;
V_10 -> V_24 = V_25 ;
F_11 ( V_6 , V_2 , V_25 , NULL ) ;
return 1 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_27 ;
V_27 = F_13 ( V_10 -> V_28 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_27 < 11000000 )
V_27 = 11000000 ;
else if ( V_27 > 20000000 )
V_27 = 20000000 ;
V_27 -= 11000000 ;
V_27 = ( V_27 + 500000 ) / 1000000 ;
V_4 -> V_11 . V_12 . V_13 [ 0 ] = V_27 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_2 -> V_17 ;
unsigned int V_29 = V_4 -> V_11 . V_12 . V_13 [ 0 ] ;
int V_27 ;
if ( V_29 >= V_16 -> V_19 )
return - V_20 ;
if ( V_29 )
V_29 = 11000000 + ( 1000000 * V_29 ) ;
else
V_29 = 2000000 ;
V_27 = F_15 ( V_10 -> V_28 , V_29 , V_29 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_6 ( V_2 , V_4 ) ;
}
static int F_16 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_34 . V_35 ;
struct V_32 * V_36 , * V_37 ;
struct V_7 * V_8 = & V_38 ;
struct V_39 * V_40 = & V_41 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
if ( ! V_33 ) {
F_17 ( & V_31 -> V_34 , L_1 ) ;
return - V_20 ;
}
V_37 = F_18 ( V_33 , L_2 , 0 ) ;
if ( ! V_37 ) {
F_17 ( & V_31 -> V_34 , L_3 ) ;
return - V_20 ;
}
V_40 -> V_42 = V_37 ;
V_40 -> V_43 = V_37 ;
V_10 -> V_44 = F_19 ( V_37 , L_4 ) ;
F_20 ( V_37 ) ;
V_36 = F_18 ( V_33 , L_5 , 0 ) ;
if ( ! V_36 ) {
F_17 ( & V_31 -> V_34 , L_6 ) ;
return - V_20 ;
}
V_40 -> V_45 = V_36 ;
F_20 ( V_36 ) ;
return 0 ;
}
static int F_21 ( struct V_30 * V_31 )
{
struct V_7 * V_8 = & V_38 ;
struct V_46 * V_34 = V_8 -> V_34 = & V_31 -> V_34 ;
struct V_9 * V_10 ;
int V_27 ;
V_10 = F_22 ( V_34 , sizeof( * V_10 ) , V_47 ) ;
if ( ! V_10 )
return - V_48 ;
F_23 ( V_8 , V_10 ) ;
V_27 = F_16 ( V_31 ) ;
if ( V_27 ) {
F_17 ( V_34 , L_7 ) ;
return V_27 ;
}
V_10 -> V_26 = F_24 ( V_34 , L_8 , V_49 ) ;
if ( F_25 ( V_10 -> V_26 ) ) {
if ( F_26 ( V_10 -> V_26 ) != - V_50 )
F_17 ( V_34 , L_9 ) ;
return F_26 ( V_10 -> V_26 ) ;
}
V_10 -> V_24 = 1 ;
V_10 -> V_21 = F_24 ( V_34 , L_10 , V_49 ) ;
if ( F_25 ( V_10 -> V_21 ) ) {
if ( F_26 ( V_10 -> V_21 ) != - V_50 )
F_17 ( V_34 , L_11 ) ;
return F_26 ( V_10 -> V_21 ) ;
}
V_10 -> V_14 = 1 ;
V_10 -> V_23 = F_24 ( V_34 , L_12 , V_49 ) ;
if ( F_25 ( V_10 -> V_23 ) ) {
if ( F_26 ( V_10 -> V_23 ) != - V_50 )
F_17 ( V_34 , L_13 ) ;
return F_26 ( V_10 -> V_23 ) ;
}
V_10 -> V_22 = 1 ;
V_10 -> V_28 = F_27 ( V_34 , L_14 ) ;
if ( F_25 ( V_10 -> V_28 ) ) {
if ( F_26 ( V_10 -> V_28 ) != - V_50 )
F_17 ( V_34 , L_15 ) ;
return F_26 ( V_10 -> V_28 ) ;
}
V_27 = F_28 ( V_10 -> V_28 ) ;
if ( V_27 < 0 ) {
F_17 ( V_34 , L_16 ) ;
return V_27 ;
}
V_27 = F_29 ( V_10 -> V_44 ) ;
if ( V_27 != 0 ) {
F_17 ( V_34 ,
L_17 , V_10 -> V_44 ) ;
goto V_51;
}
V_27 = F_30 ( V_8 ) ;
if ( V_27 ) {
F_17 ( V_34 , L_18 ) ;
goto V_52;
}
return 0 ;
V_52:
F_31 ( V_10 -> V_44 ) ;
V_51:
F_32 ( V_10 -> V_28 ) ;
return V_27 ;
}
static int F_33 ( struct V_30 * V_31 )
{
struct V_7 * V_8 = F_34 ( V_31 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_35 ( V_8 ) ;
F_31 ( V_10 -> V_44 ) ;
F_32 ( V_10 -> V_28 ) ;
return 0 ;
}
