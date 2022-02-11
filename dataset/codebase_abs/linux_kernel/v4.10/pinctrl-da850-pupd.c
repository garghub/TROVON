static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned int V_4 )
{
return V_3 [ V_4 ] ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_4 ,
const unsigned int * * V_5 ,
unsigned int * V_6 )
{
* V_6 = 0 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_4 ,
unsigned long * V_7 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
enum V_10 V_11 = F_7 ( * V_7 ) ;
T_1 V_12 ;
T_2 V_13 ;
V_12 = F_8 ( V_9 -> V_14 + V_15 ) ;
V_13 = ! ! ( ~ V_12 & F_9 ( V_4 ) ) ;
switch ( V_11 ) {
case V_16 :
break;
case V_17 :
case V_18 :
if ( V_13 ) {
V_13 = 0 ;
break;
}
V_12 = F_8 ( V_9 -> V_14 + V_19 ) ;
if ( V_11 == V_18 )
V_12 = ~ V_12 ;
V_13 = ! ! ( V_12 & F_9 ( V_4 ) ) ;
break;
default:
return - V_20 ;
}
* V_7 = F_10 ( V_11 , V_13 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_4 ,
unsigned long * V_21 ,
unsigned int V_22 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
T_1 V_23 , V_24 ;
enum V_10 V_11 ;
T_2 V_13 ;
int V_25 ;
V_23 = F_8 ( V_9 -> V_14 + V_15 ) ;
V_24 = F_8 ( V_9 -> V_14 + V_19 ) ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
V_11 = F_7 ( V_21 [ V_25 ] ) ;
V_13 = F_12 ( V_21 [ V_25 ] ) ;
switch ( V_11 ) {
case V_16 :
V_23 &= ~ F_9 ( V_4 ) ;
break;
case V_17 :
V_23 |= F_9 ( V_4 ) ;
V_24 |= F_9 ( V_4 ) ;
break;
case V_18 :
V_23 |= F_9 ( V_4 ) ;
V_24 &= ~ F_9 ( V_4 ) ;
break;
default:
return - V_20 ;
}
}
F_13 ( V_24 , V_9 -> V_14 + V_19 ) ;
F_13 ( V_23 , V_9 -> V_14 + V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = & V_27 -> V_29 ;
struct V_8 * V_9 ;
struct V_30 * V_31 ;
V_9 = F_15 ( V_29 , sizeof( * V_9 ) , V_32 ) ;
if ( ! V_9 )
return - V_33 ;
V_31 = F_16 ( V_27 , V_34 , 0 ) ;
V_9 -> V_14 = F_17 ( V_29 , V_31 ) ;
if ( F_18 ( V_9 -> V_14 ) ) {
F_19 ( V_29 , L_1 ) ;
return F_20 ( V_9 -> V_14 ) ;
}
V_9 -> V_35 . V_36 = F_21 ( V_29 ) ;
V_9 -> V_35 . V_37 = & V_38 ;
V_9 -> V_35 . V_39 = & V_40 ;
V_9 -> V_35 . V_41 = V_42 ;
V_9 -> V_43 = F_22 ( V_29 , & V_9 -> V_35 , V_9 ) ;
if ( F_18 ( V_9 -> V_43 ) ) {
F_19 ( V_29 , L_2 ) ;
return F_20 ( V_9 -> V_43 ) ;
}
F_23 ( V_27 , V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_26 * V_27 )
{
return 0 ;
}
