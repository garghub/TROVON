static int F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_4 )
{
return F_2 ( V_2 , V_5 ,
V_6 ,
V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 )
{
return F_4 ( V_2 , V_5 ,
V_6 ,
V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , bool V_7 )
{
T_1 V_4 , V_8 ;
int V_9 ;
V_9 = F_1 ( V_2 , V_10 , & V_4 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 )
V_8 = V_4 & ~ V_11 ;
else
V_8 = V_4 | V_11 ;
if ( V_4 != V_8 )
V_9 = F_3 ( V_2 , V_10 , V_8 ) ;
return V_9 ;
}
int F_6 ( struct V_1 * V_2 , int V_12 , bool V_7 )
{
int V_9 ;
T_2 V_13 ;
V_9 = F_7 ( V_2 , V_12 , & V_13 ) ;
if ( V_9 )
return V_9 ;
if ( ( V_13 == V_14 ) ||
( V_13 == V_15 ) ||
( V_13 == V_16 ) ) {
V_9 = F_5 ( V_2 , V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_17 , bool V_7 )
{
T_1 V_4 , V_8 ;
int V_18 ;
int V_9 ;
V_18 = V_19 | V_20 |
V_21 ;
V_9 = F_9 ( V_2 , V_17 , V_18 , & V_4 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 )
V_8 = V_4 & ~ ( V_22 |
V_23 |
V_24 ) ;
else
V_8 = V_4 | V_24 ;
if ( V_4 != V_8 )
V_9 = F_10 ( V_2 , V_17 , V_18 , V_8 ) ;
return V_9 ;
}
static int F_11 ( struct V_1 * V_2 , int V_17 ,
bool V_7 )
{
T_1 V_4 , V_8 ;
int V_18 ;
int V_9 ;
V_18 = V_19 | V_20 |
V_25 ;
V_9 = F_9 ( V_2 , V_17 , V_18 , & V_4 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 )
V_8 = V_4 & ~ ( V_26 |
V_27 |
V_28 ) ;
else
V_8 = V_4 | V_28 ;
if ( V_4 != V_8 )
V_9 = F_10 ( V_2 , V_17 , V_18 , V_8 ) ;
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_13 ,
int V_29 , int V_30 , bool V_31 , bool V_7 )
{
int V_9 ;
T_2 V_32 ;
V_9 = F_7 ( V_2 , V_29 , & V_32 ) ;
if ( V_9 )
return V_9 ;
switch ( V_32 ) {
case V_33 :
if ( ! V_31 )
break;
case V_15 :
case V_16 :
case V_34 :
if ( V_13 == V_15 ||
V_13 == V_16 )
return F_11 ( V_2 , V_30 , V_7 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_13 ,
bool V_7 )
{
switch ( V_13 ) {
case V_15 :
case V_16 :
return F_11 ( V_2 , V_35 , V_7 ) ;
case V_36 :
case V_33 :
case V_34 :
return F_8 ( V_2 , V_35 , V_7 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_13 ,
bool V_7 )
{
switch ( V_13 ) {
case V_16 :
return F_11 ( V_2 , V_37 , V_7 ) ;
case V_36 :
case V_33 :
case V_15 :
case V_34 :
return F_8 ( V_2 , V_37 , V_7 ) ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 , int V_12 , bool V_7 )
{
T_2 V_13 ;
int V_9 ;
V_9 = F_7 ( V_2 , V_12 , & V_13 ) ;
if ( V_9 )
return V_9 ;
switch ( V_12 ) {
case 2 :
return F_12 ( V_2 , V_13 , 9 ,
V_38 ,
false , V_7 ) ;
case 3 :
return F_12 ( V_2 , V_13 , 9 ,
V_39 ,
true , V_7 ) ;
case 4 :
return F_12 ( V_2 , V_13 , 9 ,
V_40 ,
true , V_7 ) ;
case 5 :
return F_12 ( V_2 , V_13 , 10 ,
V_41 ,
false , V_7 ) ;
case 6 :
return F_12 ( V_2 , V_13 , 10 ,
V_42 ,
true , V_7 ) ;
case 7 :
return F_12 ( V_2 , V_13 , 10 ,
V_43 ,
true , V_7 ) ;
case 9 :
return F_13 ( V_2 , V_13 , V_7 ) ;
case 10 :
return F_14 ( V_2 , V_13 , V_7 ) ;
}
return 0 ;
}
