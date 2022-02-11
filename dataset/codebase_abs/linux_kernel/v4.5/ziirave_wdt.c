static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
int V_6 ;
V_6 = F_2 ( V_2 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_7 = V_6 ;
V_6 = F_2 ( V_2 , V_5 + 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_8 = V_6 ;
return 0 ;
}
static int F_3 ( struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
return F_5 ( V_2 , V_13 , V_11 ) ;
}
static int F_6 ( struct V_9 * V_10 )
{
return F_3 ( V_10 , V_14 ) ;
}
static int F_7 ( struct V_9 * V_10 )
{
return F_3 ( V_10 , V_15 ) ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
return F_5 ( V_2 , V_16 ,
V_17 ) ;
}
static int F_9 ( struct V_9 * V_10 ,
unsigned int V_18 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
int V_6 ;
V_6 = F_5 ( V_2 , V_19 , V_18 ) ;
if ( ! V_6 )
V_10 -> V_18 = V_18 ;
return V_6 ;
}
static unsigned int F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 -> V_12 ) ;
int V_6 ;
V_6 = F_2 ( V_2 , V_20 ) ;
if ( V_6 < 0 )
V_6 = 0 ;
return V_6 ;
}
static T_2 F_11 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
char * V_25 )
{
struct V_1 * V_2 = F_4 ( V_22 -> V_12 ) ;
struct V_26 * V_27 = F_12 ( V_2 ) ;
return sprintf ( V_25 , L_1 , V_27 -> V_28 . V_7 ,
V_27 -> V_28 . V_8 ) ;
}
static T_2 F_13 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
char * V_25 )
{
struct V_1 * V_2 = F_4 ( V_22 -> V_12 ) ;
struct V_26 * V_27 = F_12 ( V_2 ) ;
return sprintf ( V_25 , L_2 , V_27 -> V_29 . V_7 ,
V_27 -> V_29 . V_8 ) ;
}
static T_2 F_14 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
char * V_25 )
{
struct V_1 * V_2 = F_4 ( V_22 -> V_12 ) ;
struct V_26 * V_27 = F_12 ( V_2 ) ;
return sprintf ( V_25 , L_3 , V_30 [ V_27 -> V_31 ] ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_32 ) {
if ( ! V_2 -> V_22 . V_33 )
V_6 = - V_34 ;
else
V_6 = F_16 ( V_2 -> V_22 . V_33 ,
L_4 ,
& V_32 ) ;
if ( V_6 ) {
F_17 ( & V_2 -> V_22 ,
L_5 ) ;
return 0 ;
}
}
if ( V_32 < 1 || V_32 > 255 )
return - V_35 ;
F_17 ( & V_2 -> V_22 , L_6 ,
V_32 ) ;
return F_5 ( V_2 , V_36 ,
V_32 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_37 * V_38 )
{
int V_6 ;
struct V_26 * V_27 ;
int V_39 ;
if ( ! F_19 ( V_2 -> V_40 , V_41 ) )
return - V_34 ;
V_27 = F_20 ( & V_2 -> V_22 , sizeof( * V_27 ) , V_42 ) ;
if ( ! V_27 )
return - V_43 ;
V_27 -> V_10 . V_44 = & V_45 ;
V_27 -> V_10 . V_46 = & V_47 ;
V_27 -> V_10 . V_48 = V_49 ;
V_27 -> V_10 . V_50 = V_51 ;
V_27 -> V_10 . V_12 = & V_2 -> V_22 ;
V_27 -> V_10 . V_52 = V_53 ;
V_6 = F_21 ( & V_27 -> V_10 , V_54 , & V_2 -> V_22 ) ;
if ( V_6 ) {
F_17 ( & V_2 -> V_22 ,
L_7 ) ;
}
if ( V_27 -> V_10 . V_18 == 0 ) {
V_39 = F_2 ( V_2 , V_19 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 < V_49 )
return - V_34 ;
V_27 -> V_10 . V_18 = V_39 ;
} else {
V_6 = F_9 ( & V_27 -> V_10 ,
V_27 -> V_10 . V_18 ) ;
if ( V_6 )
return V_6 ;
F_17 ( & V_2 -> V_22 , L_8 ,
V_27 -> V_10 . V_18 ) ;
}
F_22 ( & V_27 -> V_10 , V_55 ) ;
F_23 ( V_2 , V_27 ) ;
V_39 = F_2 ( V_2 , V_13 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 == V_56 )
F_7 ( & V_27 -> V_10 ) ;
V_6 = F_15 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , & V_27 -> V_28 ,
V_57 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , & V_27 -> V_29 ,
V_58 ) ;
if ( V_6 )
return V_6 ;
V_27 -> V_31 = F_2 ( V_2 ,
V_59 ) ;
if ( V_27 -> V_31 < 0 )
return V_27 -> V_31 ;
if ( V_27 -> V_31 >= F_24 ( V_30 ) ||
! V_30 [ V_27 -> V_31 ] )
return - V_34 ;
V_6 = F_25 ( & V_27 -> V_10 ) ;
return V_6 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_12 ( V_2 ) ;
F_27 ( & V_27 -> V_10 ) ;
return 0 ;
}
