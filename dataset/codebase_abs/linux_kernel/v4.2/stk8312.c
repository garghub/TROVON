static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = 10 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_3 = F_2 ( V_6 , V_7 , 0x70 ) ;
if ( V_3 < 0 )
goto V_8;
V_3 = F_2 ( V_6 , V_9 , 0x02 ) ;
if ( V_3 < 0 )
goto V_8;
do {
F_3 ( 1000 , 5000 ) ;
V_3 = F_4 ( V_6 , V_9 ) ;
if ( V_3 < 0 )
goto V_8;
V_4 -- ;
} while ( ! ( V_3 & 0x80 ) && V_4 > 0 );
if ( V_4 == 0 )
goto V_8;
V_3 = F_4 ( V_6 , V_10 ) ;
if ( V_3 < 0 )
goto V_8;
V_3 = F_2 ( V_2 -> V_6 ,
V_11 , V_3 ) ;
if ( V_3 < 0 )
goto V_8;
F_5 ( 150 ) ;
return V_3 ;
V_8:
F_6 ( & V_6 -> V_12 , L_1 ) ;
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_13 )
{
int V_3 ;
T_1 V_14 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_13 > 1 )
return - V_15 ;
else if ( V_13 == V_2 -> V_13 )
return 0 ;
V_3 = F_4 ( V_6 , V_16 ) ;
if ( V_3 < 0 ) {
F_6 ( & V_6 -> V_12 , L_2 ) ;
return V_3 ;
}
V_14 = V_3 & ( ~ V_17 ) ;
V_14 |= V_13 ;
V_3 = F_2 ( V_6 ,
V_16 , V_14 ) ;
if ( V_3 < 0 ) {
F_6 ( & V_6 -> V_12 , L_2 ) ;
return V_3 ;
}
V_2 -> V_13 = V_13 ;
if ( V_13 == V_18 ) {
F_3 ( 1000 , 5000 ) ;
V_3 = F_1 ( V_2 ) ;
}
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_19 )
{
int V_3 ;
T_1 V_14 ;
T_1 V_13 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_19 != 1 && V_19 != 2 )
return - V_15 ;
else if ( V_19 == V_2 -> V_19 )
return 0 ;
V_13 = V_2 -> V_13 ;
V_3 = F_7 ( V_2 , V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_6 , V_21 ) ;
if ( V_3 < 0 ) {
F_6 ( & V_6 -> V_12 , L_3 ) ;
return V_3 ;
}
V_14 = V_3 & ( ~ V_22 ) ;
V_14 |= V_19 << V_23 ;
V_3 = F_2 ( V_6 , V_21 , V_14 ) ;
if ( V_3 < 0 )
F_6 ( & V_6 -> V_12 , L_3 ) ;
else
V_2 -> V_19 = V_19 ;
return F_7 ( V_2 , V_13 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_24 )
{
int V_3 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_24 > 2 )
return - V_15 ;
V_3 = F_4 ( V_6 , V_24 ) ;
if ( V_3 < 0 ) {
F_6 ( & V_6 -> V_12 , L_4 ) ;
return V_3 ;
}
return F_10 ( V_3 , 7 ) ;
}
static int F_11 ( struct V_25 * V_26 ,
struct V_27 const * V_28 ,
int * V_29 , int * V_30 , long V_31 )
{
struct V_1 * V_2 = F_12 ( V_26 ) ;
if ( V_28 -> type != V_32 )
return - V_15 ;
switch ( V_31 ) {
case V_33 :
F_13 ( & V_2 -> V_34 ) ;
* V_29 = F_9 ( V_2 , V_28 -> V_24 ) ;
F_14 ( & V_2 -> V_34 ) ;
return V_35 ;
case V_36 :
* V_29 = V_37 [ V_2 -> V_19 - 1 ] [ 0 ] ;
* V_30 = V_37 [ V_2 -> V_19 - 1 ] [ 1 ] ;
return V_38 ;
}
return - V_15 ;
}
static int F_15 ( struct V_25 * V_26 ,
struct V_27 const * V_28 ,
int V_29 , int V_30 , long V_31 )
{
int V_39 ;
int V_40 = - 1 ;
int V_3 ;
struct V_1 * V_2 = F_12 ( V_26 ) ;
switch ( V_31 ) {
case V_36 :
for ( V_39 = 0 ; V_39 < F_16 ( V_37 ) ; V_39 ++ )
if ( V_29 == V_37 [ V_39 ] [ 0 ] &&
V_30 == V_37 [ V_39 ] [ 1 ] ) {
V_40 = V_39 + 1 ;
break;
}
if ( V_40 < 0 )
return - V_15 ;
F_13 ( & V_2 -> V_34 ) ;
V_3 = F_8 ( V_2 , V_40 ) ;
F_14 ( & V_2 -> V_34 ) ;
return V_3 ;
}
return - V_15 ;
}
static int F_17 ( struct V_5 * V_6 ,
const struct V_41 * V_42 )
{
int V_3 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
V_26 = F_18 ( & V_6 -> V_12 , sizeof( * V_2 ) ) ;
if ( ! V_26 ) {
F_6 ( & V_6 -> V_12 , L_5 ) ;
return - V_43 ;
}
V_2 = F_12 ( V_26 ) ;
V_2 -> V_6 = V_6 ;
F_19 ( V_6 , V_26 ) ;
F_20 ( & V_2 -> V_34 ) ;
V_26 -> V_12 . V_44 = & V_6 -> V_12 ;
V_26 -> V_45 = & V_46 ;
V_26 -> V_47 = V_48 ;
V_26 -> V_49 = V_50 ;
V_26 -> V_51 = V_52 ;
V_26 -> V_53 = F_16 ( V_52 ) ;
V_3 = F_2 ( V_2 -> V_6 , V_54 , 0x00 ) ;
if ( V_3 < 0 ) {
F_6 ( & V_6 -> V_12 , L_6 ) ;
return V_3 ;
}
V_3 = F_8 ( V_2 , 1 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_7 ( V_2 , V_18 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_21 ( V_26 ) ;
if ( V_3 < 0 ) {
F_6 ( & V_6 -> V_12 , L_7 ) ;
F_7 ( V_2 , V_20 ) ;
}
return V_3 ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_25 * V_26 = F_23 ( V_6 ) ;
F_24 ( V_26 ) ;
return F_7 ( F_12 ( V_26 ) , V_20 ) ;
}
static int F_25 ( struct V_55 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( F_23 ( F_26 ( V_12 ) ) ) ;
return F_7 ( V_2 , V_20 ) ;
}
static int F_27 ( struct V_55 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( F_23 ( F_26 ( V_12 ) ) ) ;
return F_7 ( V_2 , V_18 ) ;
}
