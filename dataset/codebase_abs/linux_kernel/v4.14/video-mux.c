static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_7 * V_9 , T_1 V_10 )
{
struct V_2 * V_3 = F_4 ( V_6 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
int V_12 = 0 ;
if ( V_8 -> V_10 & V_13 )
return 0 ;
F_5 ( V_3 -> V_14 , L_1 ,
V_9 -> V_6 -> V_15 , V_9 -> V_16 , V_8 -> V_6 -> V_15 ,
V_8 -> V_16 , V_10 & V_17 ) ;
F_6 ( & V_11 -> V_18 ) ;
if ( V_10 & V_17 ) {
if ( V_11 -> V_19 == V_8 -> V_16 )
goto V_20;
if ( V_11 -> V_19 >= 0 ) {
V_12 = - V_21 ;
goto V_20;
}
F_5 ( V_3 -> V_14 , L_2 , V_8 -> V_16 ) ;
V_12 = F_7 ( V_11 -> V_22 , V_8 -> V_16 ) ;
if ( V_12 < 0 )
goto V_20;
V_11 -> V_19 = V_8 -> V_16 ;
} else {
if ( V_11 -> V_19 != V_8 -> V_16 )
goto V_20;
F_5 ( V_3 -> V_14 , L_3 ) ;
F_8 ( V_11 -> V_22 ) ;
V_11 -> V_19 = - 1 ;
}
V_20:
F_9 ( & V_11 -> V_18 ) ;
return V_12 ;
}
static int F_10 ( struct V_2 * V_3 , int V_23 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_2 * V_24 ;
struct V_7 * V_25 ;
if ( V_11 -> V_19 == - 1 ) {
F_11 ( V_3 -> V_14 , L_4 ) ;
return - V_26 ;
}
V_25 = F_12 ( & V_3 -> V_6 . V_27 [ V_11 -> V_19 ] ) ;
if ( ! V_25 ) {
F_11 ( V_3 -> V_14 , L_5 ) ;
return - V_28 ;
}
if ( ! F_13 ( V_25 -> V_6 ) ) {
F_11 ( V_3 -> V_14 , L_6 ) ;
return - V_29 ;
}
V_24 = F_4 ( V_25 -> V_6 ) ;
return F_14 ( V_24 , V_30 , V_31 , V_23 ) ;
}
static struct V_32 *
F_15 ( struct V_2 * V_3 ,
struct V_33 * V_34 ,
unsigned int V_25 , T_1 V_35 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
switch ( V_35 ) {
case V_36 :
return F_16 ( V_3 , V_34 , V_25 ) ;
case V_37 :
return & V_11 -> V_38 [ V_25 ] ;
default:
return NULL ;
}
}
static int F_17 ( struct V_2 * V_3 ,
struct V_33 * V_34 ,
struct V_39 * V_40 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
F_6 ( & V_11 -> V_18 ) ;
V_40 -> V_41 = * F_15 ( V_3 , V_34 , V_40 -> V_25 ,
V_40 -> V_35 ) ;
F_9 ( & V_11 -> V_18 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_33 * V_34 ,
struct V_39 * V_40 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_32 * V_42 ;
struct V_7 * V_25 = & V_11 -> V_27 [ V_40 -> V_25 ] ;
V_42 = F_15 ( V_3 , V_34 , V_40 -> V_25 ,
V_40 -> V_35 ) ;
if ( ! V_42 )
return - V_26 ;
F_6 ( & V_11 -> V_18 ) ;
if ( ( V_25 -> V_10 & V_13 ) && V_11 -> V_19 >= 0 )
V_40 -> V_41 = V_11 -> V_38 [ V_11 -> V_19 ] ;
* V_42 = V_40 -> V_41 ;
F_9 ( & V_11 -> V_18 ) ;
return 0 ;
}
static int F_19 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_14 . V_47 ;
struct V_48 * V_14 = & V_44 -> V_14 ;
struct V_45 * V_49 ;
struct V_1 * V_11 ;
unsigned int V_50 = 0 ;
int V_12 ;
int V_51 ;
V_11 = F_20 ( V_14 , sizeof( * V_11 ) , V_52 ) ;
if ( ! V_11 )
return - V_53 ;
F_21 ( V_44 , V_11 ) ;
F_22 ( & V_11 -> V_4 , & V_54 ) ;
snprintf ( V_11 -> V_4 . V_15 , sizeof( V_11 -> V_4 . V_15 ) , L_7 , V_46 -> V_15 ) ;
V_11 -> V_4 . V_10 |= V_55 ;
V_11 -> V_4 . V_14 = V_14 ;
F_23 (np, ep) {
struct V_56 V_57 ;
F_24 ( V_49 , & V_57 ) ;
V_50 = F_25 ( V_50 , V_57 . V_58 + 1 ) ;
}
if ( V_50 < 2 ) {
F_11 ( V_14 , L_8 , V_50 ) ;
return - V_26 ;
}
V_11 -> V_22 = F_26 ( V_14 , NULL ) ;
if ( F_27 ( V_11 -> V_22 ) ) {
V_12 = F_28 ( V_11 -> V_22 ) ;
if ( V_12 != - V_59 )
F_11 ( V_14 , L_9 , V_12 ) ;
return V_12 ;
}
F_29 ( & V_11 -> V_18 ) ;
V_11 -> V_19 = - 1 ;
V_11 -> V_27 = F_30 ( V_14 , V_50 , sizeof( * V_11 -> V_27 ) ,
V_52 ) ;
V_11 -> V_38 = F_30 ( V_14 , V_50 ,
sizeof( * V_11 -> V_38 ) ,
V_52 ) ;
for ( V_51 = 0 ; V_51 < V_50 - 1 ; V_51 ++ )
V_11 -> V_27 [ V_51 ] . V_10 = V_60 ;
V_11 -> V_27 [ V_50 - 1 ] . V_10 = V_13 ;
V_11 -> V_4 . V_6 . V_61 = V_62 ;
V_12 = F_31 ( & V_11 -> V_4 . V_6 , V_50 ,
V_11 -> V_27 ) ;
if ( V_12 < 0 )
return V_12 ;
V_11 -> V_4 . V_6 . V_63 = & V_64 ;
return F_32 ( & V_11 -> V_4 ) ;
}
static int F_33 ( struct V_43 * V_44 )
{
struct V_1 * V_11 = F_34 ( V_44 ) ;
struct V_2 * V_3 = & V_11 -> V_4 ;
F_35 ( V_3 ) ;
F_36 ( & V_3 -> V_6 ) ;
return 0 ;
}
