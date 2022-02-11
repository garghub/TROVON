static unsigned int F_1 ( const struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 &&
V_2 -> V_3 -> V_4 &&
V_2 -> V_3 -> V_4 -> V_5 ) )
return F_3 ( V_2 , V_6 ) ;
else
return V_7 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_4 ;
struct V_1 * V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
unsigned int type ;
if ( ! V_11 )
return;
type = F_1 ( V_2 ) ;
switch ( type ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
V_4 = V_2 -> V_3 -> V_4 ;
if ( F_2 ( V_4 -> V_5 -> V_18 ) ) {
V_9 = F_5 ( V_2 , V_19 ) ;
if ( ! V_9 )
return;
V_9 -> V_11 = V_11 ;
V_4 -> V_5 -> V_18 ( V_4 , V_9 , type ) ;
}
break;
default:
break;
}
}
void F_6 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_22 * V_23 ;
int V_24 ;
if ( ! V_21 )
return;
* F_7 ( V_2 ) = * V_21 ;
V_23 = F_8 ( V_2 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_25 . V_26 = V_27 ;
V_23 -> V_25 . V_28 = V_29 ;
V_2 -> V_11 = NULL ;
V_24 = F_9 ( V_11 , V_2 ) ;
if ( V_24 )
F_10 ( V_2 ) ;
}
bool F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_4 ;
unsigned int type ;
if ( F_12 ( V_2 ) < V_30 )
return false ;
F_13 ( V_2 , V_30 ) ;
type = F_1 ( V_2 ) ;
F_14 ( V_2 , V_30 ) ;
switch ( type ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
V_4 = V_2 -> V_3 -> V_4 ;
if ( F_2 ( V_4 -> V_5 -> V_31 ) )
return V_4 -> V_5 -> V_31 ( V_4 , V_2 , type ) ;
break;
default:
break;
}
return false ;
}
void T_1 F_15 ( void )
{
F_16 ( F_17 ( V_6 , F_18 ( V_6 ) ) ) ;
}
