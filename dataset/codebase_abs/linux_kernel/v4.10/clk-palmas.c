static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static unsigned long F_3 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
return 32768 ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 ;
V_6 = F_5 ( V_5 -> V_7 , V_8 ,
V_5 -> V_9 -> V_10 ,
V_5 -> V_9 -> V_11 ,
V_5 -> V_9 -> V_11 ) ;
if ( V_6 < 0 )
F_6 ( V_5 -> V_12 , L_1 ,
V_5 -> V_9 -> V_10 , V_6 ) ;
else if ( V_5 -> V_9 -> V_13 )
F_7 ( V_5 -> V_9 -> V_13 ) ;
return V_6 ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 ;
if ( V_5 -> V_14 )
return;
V_6 = F_5 ( V_5 -> V_7 , V_8 ,
V_5 -> V_9 -> V_10 ,
V_5 -> V_9 -> V_11 , 0 ) ;
if ( V_6 < 0 )
F_6 ( V_5 -> V_12 , L_1 ,
V_5 -> V_9 -> V_10 , V_6 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 ;
T_1 V_15 ;
if ( V_5 -> V_14 )
return 1 ;
V_6 = F_10 ( V_5 -> V_7 , V_8 ,
V_5 -> V_9 -> V_10 , & V_15 ) ;
if ( V_6 < 0 ) {
F_6 ( V_5 -> V_12 , L_2 ,
V_5 -> V_9 -> V_10 , V_6 ) ;
return V_6 ;
}
return ! ! ( V_15 & V_5 -> V_9 -> V_11 ) ;
}
static void F_11 ( struct V_16 * V_17 ,
struct V_1 * V_5 )
{
struct V_18 * V_19 = V_17 -> V_12 . V_20 ;
unsigned int V_21 ;
int V_6 ;
V_6 = F_12 ( V_19 , L_3 ,
& V_21 ) ;
if ( V_6 )
return;
switch ( V_21 ) {
case V_22 :
V_21 = V_23 ;
break;
case V_24 :
V_21 = V_25 ;
break;
case V_26 :
V_21 = V_27 ;
break;
default:
F_13 ( & V_17 -> V_12 , L_4 ,
V_19 -> V_28 , V_21 ) ;
V_21 = 0 ;
break;
}
V_5 -> V_14 = V_21 ;
}
static int F_14 ( struct V_1 * V_5 )
{
int V_6 ;
V_6 = F_5 ( V_5 -> V_7 , V_8 ,
V_5 -> V_9 -> V_10 ,
V_5 -> V_9 -> V_29 , 0 ) ;
if ( V_6 < 0 ) {
F_6 ( V_5 -> V_12 , L_1 ,
V_5 -> V_9 -> V_10 , V_6 ) ;
return V_6 ;
}
if ( V_5 -> V_14 ) {
V_6 = F_15 ( V_5 -> V_3 . V_30 ) ;
if ( V_6 < 0 ) {
F_6 ( V_5 -> V_12 , L_5 , V_6 ) ;
return V_6 ;
}
V_6 = F_16 ( V_5 -> V_7 ,
V_5 -> V_9 -> V_31 ,
V_5 -> V_14 , true ) ;
if ( V_6 < 0 ) {
F_6 ( V_5 -> V_12 , L_6 ,
V_5 -> V_9 -> V_32 , V_6 ) ;
return V_6 ;
}
}
return V_6 ;
}
static int F_17 ( struct V_16 * V_17 )
{
struct V_7 * V_7 = F_18 ( V_17 -> V_12 . V_33 ) ;
struct V_18 * V_19 = V_17 -> V_12 . V_20 ;
const struct V_34 * V_35 ;
struct V_1 * V_5 ;
int V_6 ;
V_35 = F_19 ( & V_17 -> V_12 ) ;
if ( ! V_35 )
return 1 ;
V_5 = F_20 ( & V_17 -> V_12 , sizeof( * V_5 ) , V_36 ) ;
if ( ! V_5 )
return - V_37 ;
F_11 ( V_17 , V_5 ) ;
F_21 ( V_17 , V_5 ) ;
V_5 -> V_12 = & V_17 -> V_12 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_9 = & V_35 -> V_38 ;
V_5 -> V_3 . V_39 = & V_35 -> V_39 ;
V_6 = F_22 ( & V_17 -> V_12 , & V_5 -> V_3 ) ;
if ( V_6 ) {
F_6 ( & V_17 -> V_12 , L_7 ,
V_35 -> V_38 . V_32 , V_6 ) ;
return V_6 ;
}
V_6 = F_14 ( V_5 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_17 -> V_12 , L_8 , V_6 ) ;
return V_6 ;
}
V_6 = F_23 ( V_19 , V_40 , & V_5 -> V_3 ) ;
if ( V_6 < 0 )
F_6 ( & V_17 -> V_12 , L_9 , V_6 ) ;
return V_6 ;
}
static int F_24 ( struct V_16 * V_17 )
{
F_25 ( V_17 -> V_12 . V_20 ) ;
return 0 ;
}
