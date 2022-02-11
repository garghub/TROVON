static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_7 ;
int V_8 ;
int V_9 ;
V_7 = F_4 ( V_4 -> V_10 ) ;
V_8 = ( V_7 *
V_4 -> V_11 [ V_6 ] . V_8 ) / 100 ;
V_9 = F_5 ( V_4 -> V_10 , V_8 , V_7 ) ;
if ( V_9 ) {
F_6 ( & V_2 -> V_12 , L_1 ) ;
return V_9 ;
}
V_4 -> V_5 = V_6 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_6 >= V_2 -> V_13 -> V_14 )
return - V_15 ;
return V_4 -> V_11 [ V_6 ] . V_16 ;
}
static int F_8 ( struct V_1 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_12 ) ;
return F_9 ( V_4 -> V_10 ) ;
}
static int F_10 ( struct V_1 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_12 ) ;
F_11 ( V_4 -> V_10 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_12 ) ;
return F_13 ( V_4 -> V_10 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_17 )
{
int V_18 = V_2 -> V_19 -> V_18 ;
int V_20 = V_2 -> V_19 -> V_20 ;
int V_21 = V_20 - V_18 ;
return 100 - ( ( ( V_17 * 100 ) - ( V_18 * 100 ) ) / V_21 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_22 ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_18 , int V_20 ,
unsigned * V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_23 = V_2 -> V_19 -> V_23 ;
unsigned int V_24 = F_4 ( V_4 -> V_10 ) ;
int V_25 ;
int V_9 ;
V_25 = F_14 ( V_2 , V_18 ) ;
V_9 = F_5 ( V_4 -> V_10 , ( V_24 / 100 ) * V_25 , V_24 ) ;
if ( V_9 ) {
F_6 ( & V_2 -> V_12 , L_1 ) ;
return V_9 ;
}
V_9 = F_9 ( V_4 -> V_10 ) ;
if ( V_9 ) {
F_6 ( & V_2 -> V_12 , L_2 ) ;
return V_9 ;
}
V_4 -> V_22 = V_18 ;
F_17 ( V_23 , V_23 + 1000 ) ;
return 0 ;
}
static int F_18 ( struct V_26 * V_27 ,
struct V_3 * V_4 )
{
struct V_28 * V_29 = V_27 -> V_12 . V_30 ;
struct V_31 * V_11 ;
unsigned int V_32 = 0 ;
int V_9 ;
F_19 ( V_29 , L_3 , & V_32 ) ;
if ( ( V_32 < sizeof( * V_11 ) ) ||
( V_32 % sizeof( * V_11 ) ) ) {
F_6 ( & V_27 -> V_12 ,
L_4 ,
V_32 ) ;
return - V_15 ;
}
V_11 = F_20 ( & V_27 -> V_12 , V_32 , V_33 ) ;
if ( ! V_11 )
return - V_34 ;
V_9 = F_21 ( V_29 , L_3 ,
( V_35 * ) V_11 ,
V_32 / sizeof( V_35 ) ) ;
if ( V_9 ) {
F_6 ( & V_27 -> V_12 , L_5 ) ;
return V_9 ;
}
V_4 -> V_11 = V_11 ;
V_36 . V_37 = & V_38 ;
V_36 . V_14 = V_32 / sizeof( * V_11 ) ;
return 0 ;
}
static int F_22 ( struct V_26 * V_27 ,
struct V_3 * V_4 )
{
V_36 . V_37 = & V_39 ;
V_36 . V_40 = true ;
return 0 ;
}
static int F_23 ( struct V_26 * V_27 )
{
const struct V_41 * V_42 ;
struct V_3 * V_4 ;
struct V_1 * V_43 ;
struct V_44 V_45 = { } ;
struct V_28 * V_29 = V_27 -> V_12 . V_30 ;
int V_9 ;
if ( ! V_29 ) {
F_6 ( & V_27 -> V_12 , L_6 ) ;
return - V_15 ;
}
V_4 = F_20 ( & V_27 -> V_12 , sizeof( * V_4 ) , V_33 ) ;
if ( ! V_4 )
return - V_34 ;
if ( F_19 ( V_29 , L_3 , NULL ) )
V_9 = F_18 ( V_27 , V_4 ) ;
else
V_9 = F_22 ( V_27 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_42 = F_24 ( & V_27 -> V_12 , V_29 ,
& V_36 ) ;
if ( ! V_42 )
return - V_34 ;
V_45 . V_30 = V_29 ;
V_45 . V_12 = & V_27 -> V_12 ;
V_45 . V_46 = V_4 ;
V_45 . V_42 = V_42 ;
V_4 -> V_10 = F_25 ( & V_27 -> V_12 , NULL ) ;
if ( F_26 ( V_4 -> V_10 ) ) {
F_6 ( & V_27 -> V_12 , L_7 ) ;
return F_27 ( V_4 -> V_10 ) ;
}
V_43 = F_28 ( & V_27 -> V_12 ,
& V_36 , & V_45 ) ;
if ( F_26 ( V_43 ) ) {
F_6 ( & V_27 -> V_12 , L_8 ,
V_36 . V_47 ) ;
return F_27 ( V_43 ) ;
}
return 0 ;
}
