int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ? V_2 -> V_5 -> V_4 : NULL ;
if ( V_4 && V_4 -> V_6 ) {
int V_7 = V_4 -> V_6 ( V_2 ) ;
if ( V_7 )
return V_7 ;
}
F_2 ( V_2 ) ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ? V_2 -> V_5 -> V_4 : NULL ;
int V_7 ;
V_7 = V_4 && V_4 -> V_8 ? V_4 -> V_8 ( V_2 ) : 0 ;
return V_7 ;
}
int F_4 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ? V_2 -> V_5 -> V_4 : NULL ;
int V_7 ;
V_7 = V_4 && V_4 -> V_9 ? V_4 -> V_9 ( V_2 ) : 0 ;
return V_7 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_5 ;
int V_7 = 0 ;
if ( V_11 && V_11 -> V_4 && V_11 -> V_4 -> V_12 )
V_7 = V_11 -> V_4 -> V_12 ( V_2 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 , int V_13 , bool V_14 )
{
const struct V_3 * V_4 = V_2 -> V_5 ? V_2 -> V_5 -> V_4 : NULL ;
int (* F_7)( struct V_1 * );
if ( ! V_4 || F_8 ( V_2 ) )
return 0 ;
switch ( V_13 ) {
case V_15 :
F_7 = V_14 ? V_4 -> V_16 : V_4 -> V_17 ;
break;
case V_18 :
F_7 = V_14 ? V_4 -> V_19 : V_4 -> V_20 ;
break;
case V_21 :
F_7 = V_14 ? V_4 -> V_22 : V_4 -> V_23 ;
break;
case V_24 :
F_7 = V_14 ? V_4 -> V_25 : V_4 -> V_26 ;
break;
default:
F_7 = NULL ;
break;
}
return F_7 ? F_7 ( V_2 ) : 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_15 , true ) ;
}
int F_10 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_15 , false ) ;
}
int F_11 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_18 , true ) ;
}
int F_12 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_18 , false ) ;
}
int F_13 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_21 , true ) ;
}
int F_14 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_21 , false ) ;
}
int F_15 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_24 , true ) ;
}
int F_16 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_24 , false ) ;
}
static int F_17 ( struct V_1 * V_2 , int V_13 , bool V_14 )
{
const struct V_3 * V_4 = V_2 -> V_5 ? V_2 -> V_5 -> V_4 : NULL ;
int (* F_7)( struct V_1 * );
int V_7 ;
if ( ! V_4 )
return 0 ;
switch ( V_13 ) {
case V_27 :
F_7 = V_14 ? V_4 -> V_28 : V_4 -> V_29 ;
break;
case V_30 :
F_7 = V_14 ? V_4 -> V_31 : V_4 -> V_32 ;
break;
default:
F_7 = NULL ;
break;
}
if ( ! F_7 )
return 0 ;
V_7 = F_7 ( V_2 ) ;
if ( ! V_7 && ! V_14 && F_18 ( V_2 ) ) {
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
}
return V_7 ;
}
int F_22 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_27 , true ) ;
}
int F_23 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_27 , false ) ;
}
int F_24 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_30 , true ) ;
}
int F_25 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_30 , false ) ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_5 ;
if ( V_11 && V_11 -> V_4 && V_11 -> V_4 -> V_33 )
V_11 -> V_4 -> V_33 ( V_2 ) ;
F_27 ( V_2 ) ;
}
