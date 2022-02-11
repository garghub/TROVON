static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_4 | V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
return F_4 ( V_2 ,
V_6 | V_3 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_8 ;
T_1 V_9 [ 3 ] ;
V_8 = F_6 ( V_2 , V_7 , 3 , V_9 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 != 3 )
return - V_10 ;
return ( ( V_9 [ 0 ] & 0xF ) << 16 ) | ( V_9 [ 1 ] << 8 ) | ( V_9 [ 2 ] ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
int V_8 ;
int V_13 = 0 ;
struct V_14 * V_15 = F_8 ( V_12 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
while ( ++ V_13 <= V_16 ) {
V_8 = F_1 ( V_2 , V_17 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_12 -> V_18 , L_1 , V_8 ) ;
return V_8 ;
}
if ( V_8 & V_19 )
return 0 ;
F_10 ( V_20 , V_20 * 3 / 2 ) ;
}
return - V_21 ;
}
static int F_11 ( struct V_1 * V_2 , bool V_22 )
{
int V_5 ;
V_5 = F_1 ( V_2 , V_23 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_22 )
V_5 |= V_24 ;
else
V_5 &= ~ V_24 ;
return F_3 ( V_2 , V_23 , V_5 ) ;
}
static int F_12 ( struct V_11 * V_12 )
{
int V_8 ;
struct V_14 * V_15 = F_8 ( V_12 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
V_8 = F_13 ( V_2 , V_25 ) ;
if ( V_8 ) {
F_9 ( & V_2 -> V_18 , L_2 , V_8 ) ;
return V_8 ;
}
F_10 ( 400 , 600 ) ;
V_8 = F_7 ( V_12 ) ;
if ( V_8 ) {
F_9 ( & V_2 -> V_18 , L_3 , V_8 ) ;
return V_8 ;
}
V_8 = F_11 ( V_2 , true ) ;
if ( V_8 )
F_9 ( & V_2 -> V_18 , L_4 , V_8 ) ;
return V_8 ;
}
static int F_14 ( struct V_11 * V_12 ,
T_1 V_26 , T_1 V_27 ,
unsigned int V_28 )
{
int V_8 ;
struct V_14 * V_15 = F_8 ( V_12 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
V_8 = F_7 ( V_12 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_12 -> V_18 , L_5 , V_8 ) ;
return V_8 ;
}
V_8 = F_13 ( V_2 , V_26 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_12 -> V_18 , L_6 , V_8 ) ;
return V_8 ;
}
F_10 ( V_28 , V_28 * 3 / 2 ) ;
V_8 = F_7 ( V_12 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_12 -> V_18 , L_5 , V_8 ) ;
return V_8 ;
}
V_8 = F_5 ( V_2 , V_27 ) ;
if ( V_8 < 0 )
F_9 ( & V_12 -> V_18 , L_7 , V_8 ) ;
return V_8 ;
}
static int F_15 ( struct V_11 * V_12 ,
struct V_29 const * V_30 , int * V_5 ,
int * V_31 , long V_32 )
{
int V_8 ;
struct V_14 * V_15 = F_8 ( V_12 ) ;
const struct V_33 * V_34 ;
T_1 V_26 ;
F_16 ( & V_15 -> V_35 ) ;
switch ( V_32 ) {
case V_36 :
switch ( V_30 -> type ) {
case V_37 :
* V_5 = V_38 [ V_15 -> V_39 ] ;
V_8 = V_40 ;
break;
case V_41 :
* V_5 = V_38 [ V_15 -> V_42 ] ;
V_8 = V_40 ;
break;
default:
V_8 = - V_43 ;
}
break;
case V_44 :
switch ( V_30 -> type ) {
case V_37 :
V_34 = & V_45 [ V_15 -> V_39 ] ;
V_26 = V_46 |
V_34 -> V_47 |
V_48 ;
V_8 = F_14 ( V_12 ,
V_26 ,
V_49 ,
V_34 -> V_50 ) ;
if ( V_8 >= 0 ) {
* V_5 = F_17 ( V_8 , 19 ) ;
V_8 = V_40 ;
}
break;
case V_41 :
V_34 = & V_45 [ V_15 -> V_42 ] ;
V_26 = V_46 |
V_34 -> V_47 |
V_51 ;
V_8 = F_14 ( V_12 ,
V_26 ,
V_52 ,
V_34 -> V_53 ) ;
if ( V_8 >= 0 ) {
* V_5 = V_8 ;
V_8 = V_40 ;
}
break;
default:
V_8 = - V_43 ;
}
break;
case V_54 :
switch ( V_30 -> type ) {
case V_37 :
* V_5 = 0 ;
* V_31 = 10000 ;
V_8 = V_55 ;
break;
case V_41 :
* V_5 = 0 ;
* V_31 = 1000 ;
V_8 = V_55 ;
break;
default:
V_8 = - V_43 ;
}
break;
default:
V_8 = - V_43 ;
}
F_18 ( & V_15 -> V_35 ) ;
return V_8 ;
}
static int F_19 ( struct V_11 * V_12 ,
struct V_29 const * V_30 ,
int V_5 , int V_31 , long V_32 )
{
int V_8 = 0 ;
struct V_14 * V_15 = F_8 ( V_12 ) ;
if ( V_32 != V_36 )
return - V_43 ;
F_16 ( & V_15 -> V_35 ) ;
switch ( V_30 -> type ) {
case V_37 :
V_15 -> V_39 = F_20 ( V_5 ,
V_38 , F_21 ( V_38 ) ) ;
break;
case V_41 :
V_15 -> V_42 = F_20 ( V_5 ,
V_38 , F_21 ( V_38 ) ) ;
break;
default:
V_8 = - V_43 ;
}
F_18 ( & V_15 -> V_35 ) ;
return V_8 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_56 * V_57 )
{
struct V_11 * V_12 ;
struct V_14 * V_15 ;
int V_8 ;
if ( ! F_23 ( V_2 -> V_58 ,
V_59 |
V_60 |
V_61 ) ) {
F_9 ( & V_2 -> V_18 , L_8
L_9 ) ;
return - V_62 ;
}
V_12 = F_24 ( & V_2 -> V_18 , sizeof( * V_15 ) ) ;
if ( ! V_12 )
return - V_63 ;
V_15 = F_8 ( V_12 ) ;
V_15 -> V_2 = V_2 ;
F_25 ( & V_15 -> V_35 ) ;
V_12 -> V_64 = & V_65 ;
V_12 -> V_66 = V_57 -> V_66 ;
V_12 -> V_18 . V_67 = & V_2 -> V_18 ;
V_12 -> V_68 = V_69 ;
V_12 -> V_70 = V_71 ;
V_12 -> V_72 = F_21 ( V_71 ) ;
F_26 ( V_2 , V_12 ) ;
V_8 = F_12 ( V_12 ) ;
if ( V_8 ) {
F_9 ( & V_2 -> V_18 , L_10 , V_8 ) ;
return - V_62 ;
}
return F_27 ( & V_2 -> V_18 , V_12 ) ;
}
