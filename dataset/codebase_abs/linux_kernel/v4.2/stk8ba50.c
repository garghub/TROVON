static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_4 = F_2 ( V_6 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_7 , L_1 ) ;
return V_4 ;
}
return F_4 ( V_4 >> V_8 , 9 ) ;
}
static int F_5 ( struct V_9 * V_10 ,
struct V_11 const * V_12 ,
int * V_13 , int * V_14 , long V_15 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
switch ( V_15 ) {
case V_16 :
F_7 ( & V_2 -> V_17 ) ;
* V_13 = F_1 ( V_2 , V_12 -> V_18 ) ;
F_8 ( & V_2 -> V_17 ) ;
return V_19 ;
case V_20 :
* V_13 = 0 ;
* V_14 = V_21 [ V_2 -> V_22 ] [ 1 ] ;
return V_23 ;
}
return - V_24 ;
}
static int F_9 ( struct V_9 * V_10 ,
struct V_11 const * V_12 ,
int V_13 , int V_14 , long V_15 )
{
int V_4 ;
int V_25 ;
int V_26 = - 1 ;
struct V_1 * V_2 = F_6 ( V_10 ) ;
switch ( V_15 ) {
case V_20 :
if ( V_13 != 0 )
return - V_24 ;
for ( V_25 = 0 ; V_25 < F_10 ( V_21 ) ; V_25 ++ )
if ( V_14 == V_21 [ V_25 ] [ 1 ] ) {
V_26 = V_25 ;
break;
}
if ( V_26 < 0 )
return - V_24 ;
V_4 = F_11 ( V_2 -> V_6 ,
V_27 ,
V_21 [ V_26 ] [ 0 ] ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_6 -> V_7 ,
L_2 ) ;
else
V_2 -> V_22 = V_26 ;
return V_4 ;
}
return - V_24 ;
}
static int F_12 ( struct V_1 * V_2 , bool V_28 )
{
int V_4 ;
T_1 V_29 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_4 = F_13 ( V_6 , V_30 ) ;
if ( V_4 < 0 )
goto V_31;
if ( V_28 )
V_29 = V_4 | V_32 ;
else
V_29 = V_4 & ( ~ V_32 ) ;
V_4 = F_11 ( V_6 , V_30 ,
V_29 ) ;
if ( V_4 < 0 )
goto V_31;
return V_4 ;
V_31:
F_3 ( & V_6 -> V_7 , L_3 ) ;
return V_4 ;
}
static int F_14 ( struct V_5 * V_6 ,
const struct V_33 * V_34 )
{
int V_4 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_10 = F_15 ( & V_6 -> V_7 , sizeof( * V_2 ) ) ;
if ( ! V_10 ) {
F_3 ( & V_6 -> V_7 , L_4 ) ;
return - V_35 ;
}
V_2 = F_6 ( V_10 ) ;
V_2 -> V_6 = V_6 ;
F_16 ( V_6 , V_10 ) ;
F_17 ( & V_2 -> V_17 ) ;
V_10 -> V_7 . V_36 = & V_6 -> V_7 ;
V_10 -> V_37 = & V_38 ;
V_10 -> V_39 = V_40 ;
V_10 -> V_41 = V_42 ;
V_10 -> V_43 = V_44 ;
V_10 -> V_45 = F_10 ( V_44 ) ;
V_4 = F_11 ( V_6 ,
V_46 , V_47 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_7 , L_5 ) ;
return V_4 ;
}
V_2 -> V_22 = 0 ;
V_4 = F_18 ( V_10 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_6 -> V_7 , L_6 ) ;
F_12 ( V_2 , V_48 ) ;
}
return V_4 ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_20 ( V_6 ) ;
F_21 ( V_10 ) ;
return F_12 ( F_6 ( V_10 ) , V_48 ) ;
}
static int F_22 ( struct V_49 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( F_20 ( F_23 ( V_7 ) ) ) ;
return F_12 ( V_2 , V_48 ) ;
}
static int F_24 ( struct V_49 * V_7 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( F_20 ( F_23 ( V_7 ) ) ) ;
return F_12 ( V_2 , V_50 ) ;
}
