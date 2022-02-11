bool F_1 ( struct V_1 * V_2 , const struct V_1 * V_3 )
{
V_2 -> V_4 = F_2 ( V_2 -> V_4 , V_3 -> V_4 ) ;
V_2 -> y1 = F_2 ( V_2 -> y1 , V_3 -> y1 ) ;
V_2 -> V_5 = F_3 ( V_2 -> V_5 , V_3 -> V_5 ) ;
V_2 -> V_6 = F_3 ( V_2 -> V_6 , V_3 -> V_6 ) ;
return F_4 ( V_2 ) ;
}
bool F_5 ( struct V_1 * V_7 , struct V_1 * V_8 ,
const struct V_1 * V_9 ,
int V_10 , int V_11 )
{
int V_12 ;
V_12 = V_9 -> V_4 - V_8 -> V_4 ;
if ( V_12 > 0 ) {
T_1 V_13 = V_7 -> V_4 + ( T_1 ) V_12 * V_10 ;
V_7 -> V_4 = F_6 ( T_1 , V_13 , V_14 , V_15 ) ;
}
V_12 = V_9 -> y1 - V_8 -> y1 ;
if ( V_12 > 0 ) {
T_1 V_13 = V_7 -> y1 + ( T_1 ) V_12 * V_11 ;
V_7 -> y1 = F_6 ( T_1 , V_13 , V_14 , V_15 ) ;
}
V_12 = V_8 -> V_5 - V_9 -> V_5 ;
if ( V_12 > 0 ) {
T_1 V_13 = V_7 -> V_5 - ( T_1 ) V_12 * V_10 ;
V_7 -> V_5 = F_6 ( T_1 , V_13 , V_14 , V_15 ) ;
}
V_12 = V_8 -> V_6 - V_9 -> V_6 ;
if ( V_12 > 0 ) {
T_1 V_13 = V_7 -> V_6 - ( T_1 ) V_12 * V_11 ;
V_7 -> V_6 = F_6 ( T_1 , V_13 , V_14 , V_15 ) ;
}
return F_1 ( V_8 , V_9 ) ;
}
static int F_7 ( int V_7 , int V_8 )
{
int V_16 = 0 ;
if ( F_8 ( V_7 < 0 || V_8 < 0 ) )
return - V_17 ;
if ( V_8 == 0 )
return 0 ;
V_16 = V_7 / V_8 ;
return V_16 ;
}
int F_9 ( const struct V_1 * V_7 ,
const struct V_1 * V_8 ,
int V_18 , int V_19 )
{
int V_20 = F_10 ( V_7 ) ;
int V_21 = F_10 ( V_8 ) ;
int V_10 = F_7 ( V_20 , V_21 ) ;
if ( V_10 < 0 || V_21 == 0 )
return V_10 ;
if ( V_10 < V_18 || V_10 > V_19 )
return - V_22 ;
return V_10 ;
}
int F_11 ( const struct V_1 * V_7 ,
const struct V_1 * V_8 ,
int V_23 , int V_24 )
{
int V_25 = F_12 ( V_7 ) ;
int V_26 = F_12 ( V_8 ) ;
int V_11 = F_7 ( V_25 , V_26 ) ;
if ( V_11 < 0 || V_26 == 0 )
return V_11 ;
if ( V_11 < V_23 || V_11 > V_24 )
return - V_22 ;
return V_11 ;
}
int F_13 ( struct V_1 * V_7 ,
struct V_1 * V_8 ,
int V_18 , int V_19 )
{
int V_20 = F_10 ( V_7 ) ;
int V_21 = F_10 ( V_8 ) ;
int V_10 = F_7 ( V_20 , V_21 ) ;
if ( V_10 < 0 || V_21 == 0 )
return V_10 ;
if ( V_10 < V_18 ) {
int V_27 = V_20 / V_18 ;
F_14 ( V_8 , V_27 - V_21 , 0 ) ;
return V_18 ;
}
if ( V_10 > V_19 ) {
int V_28 = V_21 * V_19 ;
F_14 ( V_7 , V_28 - V_20 , 0 ) ;
return V_19 ;
}
return V_10 ;
}
int F_15 ( struct V_1 * V_7 ,
struct V_1 * V_8 ,
int V_23 , int V_24 )
{
int V_25 = F_12 ( V_7 ) ;
int V_26 = F_12 ( V_8 ) ;
int V_11 = F_7 ( V_25 , V_26 ) ;
if ( V_11 < 0 || V_26 == 0 )
return V_11 ;
if ( V_11 < V_23 ) {
int V_29 = V_25 / V_23 ;
F_14 ( V_8 , 0 , V_29 - V_26 ) ;
return V_23 ;
}
if ( V_11 > V_24 ) {
int V_30 = V_26 * V_24 ;
F_14 ( V_7 , 0 , V_30 - V_25 ) ;
return V_24 ;
}
return V_11 ;
}
void F_16 ( const char * V_31 , const struct V_1 * V_32 , bool V_33 )
{
if ( V_33 )
F_17 ( L_1 V_34 L_2 , V_31 , F_18 ( V_32 ) ) ;
else
F_17 ( L_1 V_35 L_2 , V_31 , F_19 ( V_32 ) ) ;
}
void F_20 ( struct V_1 * V_32 ,
int V_36 , int V_37 ,
unsigned int V_38 )
{
struct V_1 V_13 ;
if ( V_38 & ( V_39 | V_40 ) ) {
V_13 = * V_32 ;
if ( V_38 & V_39 ) {
V_32 -> V_4 = V_36 - V_13 . V_5 ;
V_32 -> V_5 = V_36 - V_13 . V_4 ;
}
if ( V_38 & V_40 ) {
V_32 -> y1 = V_37 - V_13 . V_6 ;
V_32 -> V_6 = V_37 - V_13 . y1 ;
}
}
switch ( V_38 & V_41 ) {
case V_42 :
break;
case V_43 :
V_13 = * V_32 ;
V_32 -> V_4 = V_13 . y1 ;
V_32 -> V_5 = V_13 . V_6 ;
V_32 -> y1 = V_36 - V_13 . V_5 ;
V_32 -> V_6 = V_36 - V_13 . V_4 ;
break;
case V_44 :
V_13 = * V_32 ;
V_32 -> V_4 = V_36 - V_13 . V_5 ;
V_32 -> V_5 = V_36 - V_13 . V_4 ;
V_32 -> y1 = V_37 - V_13 . V_6 ;
V_32 -> V_6 = V_37 - V_13 . y1 ;
break;
case V_45 :
V_13 = * V_32 ;
V_32 -> V_4 = V_37 - V_13 . V_6 ;
V_32 -> V_5 = V_37 - V_13 . y1 ;
V_32 -> y1 = V_13 . V_4 ;
V_32 -> V_6 = V_13 . V_5 ;
break;
default:
break;
}
}
void F_21 ( struct V_1 * V_32 ,
int V_36 , int V_37 ,
unsigned int V_38 )
{
struct V_1 V_13 ;
switch ( V_38 & V_41 ) {
case V_42 :
break;
case V_43 :
V_13 = * V_32 ;
V_32 -> V_4 = V_36 - V_13 . V_6 ;
V_32 -> V_5 = V_36 - V_13 . y1 ;
V_32 -> y1 = V_13 . V_4 ;
V_32 -> V_6 = V_13 . V_5 ;
break;
case V_44 :
V_13 = * V_32 ;
V_32 -> V_4 = V_36 - V_13 . V_5 ;
V_32 -> V_5 = V_36 - V_13 . V_4 ;
V_32 -> y1 = V_37 - V_13 . V_6 ;
V_32 -> V_6 = V_37 - V_13 . y1 ;
break;
case V_45 :
V_13 = * V_32 ;
V_32 -> V_4 = V_13 . y1 ;
V_32 -> V_5 = V_13 . V_6 ;
V_32 -> y1 = V_37 - V_13 . V_5 ;
V_32 -> V_6 = V_37 - V_13 . V_4 ;
break;
default:
break;
}
if ( V_38 & ( V_39 | V_40 ) ) {
V_13 = * V_32 ;
if ( V_38 & V_39 ) {
V_32 -> V_4 = V_36 - V_13 . V_5 ;
V_32 -> V_5 = V_36 - V_13 . V_4 ;
}
if ( V_38 & V_40 ) {
V_32 -> y1 = V_37 - V_13 . V_6 ;
V_32 -> V_6 = V_37 - V_13 . y1 ;
}
}
}
