static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 V_8 ;
int V_9 ;
int V_10 ;
F_4 ( V_4 -> V_11 , & V_8 ) ;
V_9 = ( V_8 . V_12 *
V_4 -> V_13 [ V_6 ] . V_9 ) / 100 ;
V_10 = F_5 ( V_4 -> V_11 , V_9 , V_8 . V_12 ) ;
if ( V_10 ) {
F_6 ( & V_2 -> V_14 , L_1 , V_10 ) ;
return V_10 ;
}
V_4 -> V_5 = V_6 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_6 >= V_2 -> V_15 -> V_16 )
return - V_17 ;
return V_4 -> V_13 [ V_6 ] . V_18 ;
}
static int F_8 ( struct V_1 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_14 ) ;
return F_9 ( V_4 -> V_11 ) ;
}
static int F_10 ( struct V_1 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_14 ) ;
F_11 ( V_4 -> V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_14 ) ;
return F_13 ( V_4 -> V_11 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_19 ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_20 , int V_21 ,
unsigned * V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_22 = V_2 -> V_23 -> V_22 ;
struct V_7 V_8 ;
unsigned int V_24 = V_20 - V_2 -> V_23 -> V_20 ;
unsigned int V_25 ;
unsigned int V_26 ;
T_1 V_27 ;
T_2 V_28 ;
int V_10 ;
F_4 ( V_4 -> V_11 , & V_8 ) ;
V_25 = V_2 -> V_23 -> V_21 - V_2 -> V_23 -> V_20 ;
V_27 = V_24 * V_8 . V_12 ;
F_16 ( V_27 , V_25 , & V_28 ) ;
if ( ! V_28 ) {
F_17 ( V_27 , V_25 ) ;
V_26 = ( unsigned int ) V_27 ;
} else {
V_26 = ( V_8 . V_12 / 100 ) * ( ( V_24 * 100 ) / V_25 ) ;
}
V_10 = F_5 ( V_4 -> V_11 , V_26 , V_8 . V_12 ) ;
if ( V_10 ) {
F_6 ( & V_2 -> V_14 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_9 ( V_4 -> V_11 ) ;
if ( V_10 ) {
F_6 ( & V_2 -> V_14 , L_2 , V_10 ) ;
return V_10 ;
}
V_4 -> V_19 = V_20 ;
F_18 ( V_22 , V_22 + 1000 ) ;
return 0 ;
}
static int F_19 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
struct V_31 * V_32 = V_30 -> V_14 . V_33 ;
struct V_34 * V_13 ;
unsigned int V_35 = 0 ;
int V_10 ;
F_20 ( V_32 , L_3 , & V_35 ) ;
if ( ( V_35 < sizeof( * V_13 ) ) ||
( V_35 % sizeof( * V_13 ) ) ) {
F_6 ( & V_30 -> V_14 , L_4 ,
V_35 ) ;
return - V_17 ;
}
V_13 = F_21 ( & V_30 -> V_14 , V_35 , V_36 ) ;
if ( ! V_13 )
return - V_37 ;
V_10 = F_22 ( V_32 , L_3 ,
( T_2 * ) V_13 ,
V_35 / sizeof( T_2 ) ) ;
if ( V_10 ) {
F_6 ( & V_30 -> V_14 , L_5 , V_10 ) ;
return V_10 ;
}
V_4 -> V_13 = V_13 ;
memcpy ( & V_4 -> V_38 , & V_39 ,
sizeof( V_4 -> V_38 ) ) ;
V_4 -> V_15 . V_38 = & V_4 -> V_38 ;
V_4 -> V_15 . V_16 = V_35 / sizeof( * V_13 ) ;
return 0 ;
}
static int F_23 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
memcpy ( & V_4 -> V_38 , & V_40 ,
sizeof( V_4 -> V_38 ) ) ;
V_4 -> V_15 . V_38 = & V_4 -> V_38 ;
V_4 -> V_15 . V_41 = true ;
return 0 ;
}
static int F_24 ( struct V_29 * V_30 )
{
const struct V_42 * V_43 ;
struct V_3 * V_4 ;
struct V_1 * V_44 ;
struct V_45 V_46 = { } ;
struct V_31 * V_32 = V_30 -> V_14 . V_33 ;
int V_10 ;
if ( ! V_32 ) {
F_6 ( & V_30 -> V_14 , L_6 ) ;
return - V_17 ;
}
V_4 = F_21 ( & V_30 -> V_14 , sizeof( * V_4 ) , V_36 ) ;
if ( ! V_4 )
return - V_37 ;
memcpy ( & V_4 -> V_15 , & V_47 , sizeof( V_4 -> V_15 ) ) ;
if ( F_20 ( V_32 , L_3 , NULL ) )
V_10 = F_19 ( V_30 , V_4 ) ;
else
V_10 = F_23 ( V_30 , V_4 ) ;
if ( V_10 )
return V_10 ;
V_43 = F_25 ( & V_30 -> V_14 , V_32 ,
& V_4 -> V_15 ) ;
if ( ! V_43 )
return - V_37 ;
V_46 . V_33 = V_32 ;
V_46 . V_14 = & V_30 -> V_14 ;
V_46 . V_48 = V_4 ;
V_46 . V_43 = V_43 ;
V_4 -> V_11 = F_26 ( & V_30 -> V_14 , NULL ) ;
if ( F_27 ( V_4 -> V_11 ) ) {
V_10 = F_28 ( V_4 -> V_11 ) ;
F_6 ( & V_30 -> V_14 , L_7 , V_10 ) ;
return V_10 ;
}
F_29 ( V_4 -> V_11 ) ;
V_44 = F_30 ( & V_30 -> V_14 ,
& V_4 -> V_15 , & V_46 ) ;
if ( F_27 ( V_44 ) ) {
V_10 = F_28 ( V_44 ) ;
F_6 ( & V_30 -> V_14 , L_8 ,
V_4 -> V_15 . V_49 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
