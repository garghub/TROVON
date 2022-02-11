static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 = F_2 ( V_2 -> V_6 ,
V_7 | V_3 ,
V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 -> V_8 ,
L_1
L_2 ,
V_5 , V_3 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 = F_5 ( V_2 -> V_6 ,
V_7 | V_3 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 -> V_8 ,
L_3
L_2 ,
V_5 , V_3 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 = F_7 ( V_2 -> V_6 ,
V_7 | V_3 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_6 -> V_8 ,
L_4
L_2 ,
V_5 , V_3 ) ;
return V_5 ;
}
static int F_8 ( struct V_9 * V_10 ,
unsigned int V_3 , unsigned int V_11 ,
unsigned int * V_12 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
int V_5 ;
if ( ! V_12 )
return F_1 ( V_2 , ( T_1 ) V_3 , ( T_1 ) V_11 ) ;
V_5 = F_4 ( V_2 , ( T_1 ) V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_12 = V_5 ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 ,
struct V_13 const * V_14 ,
int * V_4 , int * V_15 , long V_16 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
int V_17 ;
switch ( V_16 ) {
case V_18 :
switch ( V_14 -> type ) {
case V_19 :
F_11 ( & V_2 -> V_6 -> V_8 ) ;
V_17 = F_6 ( V_2 , V_20 ) ;
if ( V_17 < 0 )
return V_17 ;
F_12 ( & V_2 -> V_6 -> V_8 ) ;
F_13 ( & V_2 -> V_6 -> V_8 ) ;
* V_4 = V_17 ;
return V_21 ;
default:
return - V_22 ;
}
case V_23 :
* V_4 = 0 ;
* V_15 = V_24 * 1000 ;
return V_25 ;
default:
return - V_22 ;
}
}
static int F_14 ( struct V_26 * V_6 ,
const struct V_27 * V_28 )
{
int V_5 ;
struct V_1 * V_2 ;
struct V_29 * V_30 = F_15 ( V_6 -> V_8 . V_31 ) ;
struct V_9 * V_10 ;
if ( ! F_16 ( V_30 , V_32 ) )
return - V_33 ;
V_10 = F_17 ( & V_6 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_10 )
return - V_34 ;
V_2 = F_9 ( V_10 ) ;
V_2 -> V_6 = V_6 ;
F_18 ( V_6 , V_10 ) ;
V_5 = F_1 ( V_2 , V_35 , V_36 ) ;
if ( V_5 < 0 )
return V_5 ;
F_19 ( V_37 ) ;
F_20 ( & V_6 -> V_8 ) ;
F_21 ( & V_6 -> V_8 ) ;
F_22 ( & V_6 -> V_8 ) ;
V_5 = F_4 ( V_2 , V_38 ) ;
if ( V_5 < 0 )
goto V_39;
F_23 ( & V_6 -> V_8 ,
L_5 ,
( V_5 & V_40 ) ) ;
F_24 ( & V_6 -> V_8 , 5000 ) ;
F_25 ( & V_6 -> V_8 ) ;
F_26 ( & V_6 -> V_8 ) ;
V_10 -> V_8 . V_31 = & V_6 -> V_8 ;
V_10 -> V_41 = & V_42 ;
V_10 -> V_43 = L_6 ;
V_10 -> V_44 = V_45 ;
V_10 -> V_46 = F_27 ( V_45 ) ;
V_10 -> V_47 = V_48 ;
V_5 = F_28 ( V_10 ) ;
if ( V_5 )
goto V_39;
return 0 ;
V_39:
F_29 ( & V_6 -> V_8 ) ;
F_30 ( & V_6 -> V_8 ) ;
return V_5 ;
}
static int F_31 ( struct V_26 * V_6 )
{
struct V_9 * V_10 = F_32 ( V_6 ) ;
struct V_1 * V_2 = F_9 ( V_10 ) ;
int V_5 ;
F_33 ( V_10 ) ;
F_11 ( & V_6 -> V_8 ) ;
F_29 ( & V_6 -> V_8 ) ;
F_30 ( & V_6 -> V_8 ) ;
V_5 = F_1 ( V_2 , V_35 , V_49 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_6 -> V_8 , L_7 ) ;
return V_5 ;
}
return 0 ;
}
static int F_34 ( struct V_50 * V_8 )
{
struct V_26 * V_6 = F_35 ( V_8 ) ;
struct V_9 * V_10 = F_32 ( V_6 ) ;
struct V_1 * V_2 = F_9 ( V_10 ) ;
int V_5 ;
V_5 = F_1 ( V_2 , V_35 , V_49 ) ;
if ( V_5 < 0 ) {
F_3 ( V_8 , L_8 ) ;
return V_5 ;
}
return 0 ;
}
static int F_36 ( struct V_50 * V_8 )
{
struct V_26 * V_6 = F_35 ( V_8 ) ;
struct V_9 * V_10 = F_32 ( V_6 ) ;
struct V_1 * V_2 = F_9 ( V_10 ) ;
int V_5 ;
V_5 = F_1 ( V_2 , V_35 , V_36 ) ;
if ( V_5 < 0 ) {
F_3 ( V_8 , L_9 ) ;
return V_5 ;
}
F_19 ( V_37 + V_24 ) ;
return 0 ;
}
