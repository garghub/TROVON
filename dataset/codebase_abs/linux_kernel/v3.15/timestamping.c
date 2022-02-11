static unsigned int F_1 ( const struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 && V_2 -> V_3 -> V_4 &&
V_2 -> V_3 -> V_4 -> V_5 ) )
return F_3 ( V_2 ) ;
else
return V_6 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_4 ;
struct V_1 * V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
unsigned int type ;
if ( ! V_10 )
return;
type = F_1 ( V_2 ) ;
switch ( type ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
V_4 = V_2 -> V_3 -> V_4 ;
if ( F_2 ( V_4 -> V_5 -> V_17 ) ) {
if ( ! F_5 ( & V_10 -> V_18 ) )
return;
V_8 = F_6 ( V_2 , V_19 ) ;
if ( ! V_8 ) {
F_7 ( V_10 ) ;
return;
}
V_8 -> V_10 = V_10 ;
V_4 -> V_5 -> V_17 ( V_4 , V_8 , type ) ;
}
break;
default:
break;
}
}
void F_8 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_22 * V_23 ;
int V_24 ;
if ( ! V_21 ) {
F_7 ( V_10 ) ;
F_9 ( V_2 ) ;
return;
}
* F_10 ( V_2 ) = * V_21 ;
V_23 = F_11 ( V_2 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_25 . V_26 = V_27 ;
V_23 -> V_25 . V_28 = V_29 ;
V_2 -> V_10 = NULL ;
V_24 = F_12 ( V_10 , V_2 ) ;
F_7 ( V_10 ) ;
if ( V_24 )
F_9 ( V_2 ) ;
}
bool F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_4 ;
unsigned int type ;
if ( F_14 ( V_2 ) < V_30 )
return false ;
F_15 ( V_2 , V_30 ) ;
type = F_1 ( V_2 ) ;
F_16 ( V_2 , V_30 ) ;
switch ( type ) {
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
V_4 = V_2 -> V_3 -> V_4 ;
if ( F_2 ( V_4 -> V_5 -> V_31 ) )
return V_4 -> V_5 -> V_31 ( V_4 , V_2 , type ) ;
break;
default:
break;
}
return false ;
}
