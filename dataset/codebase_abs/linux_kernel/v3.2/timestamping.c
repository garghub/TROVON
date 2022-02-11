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
if ( ! F_5 ( & V_11 -> V_19 ) )
return;
V_9 = F_6 ( V_2 , V_20 ) ;
if ( ! V_9 ) {
F_7 ( V_11 ) ;
return;
}
V_9 -> V_11 = V_11 ;
V_4 -> V_5 -> V_18 ( V_4 , V_9 , type ) ;
}
break;
default:
break;
}
}
void F_8 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_23 * V_24 ;
int V_25 ;
if ( ! V_22 ) {
F_7 ( V_11 ) ;
F_9 ( V_2 ) ;
return;
}
* F_10 ( V_2 ) = * V_22 ;
V_24 = F_11 ( V_2 ) ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_26 . V_27 = V_28 ;
V_24 -> V_26 . V_29 = V_30 ;
V_2 -> V_11 = NULL ;
V_25 = F_12 ( V_11 , V_2 ) ;
F_7 ( V_11 ) ;
if ( V_25 )
F_9 ( V_2 ) ;
}
bool F_13 ( struct V_1 * V_2 )
{
struct V_8 * V_4 ;
unsigned int type ;
if ( F_14 ( V_2 ) < V_31 )
return false ;
F_15 ( V_2 , V_31 ) ;
type = F_1 ( V_2 ) ;
F_16 ( V_2 , V_31 ) ;
switch ( type ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
V_4 = V_2 -> V_3 -> V_4 ;
if ( F_2 ( V_4 -> V_5 -> V_32 ) )
return V_4 -> V_5 -> V_32 ( V_4 , V_2 , type ) ;
break;
default:
break;
}
return false ;
}
void T_1 F_17 ( void )
{
F_18 ( F_19 ( V_6 , F_20 ( V_6 ) ) ) ;
}
