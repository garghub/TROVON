int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 = 0 ;
switch ( V_3 ) {
case V_5 :
V_2 -> V_6 = F_2 () ;
break;
case V_7 :
V_2 -> V_6 = F_3 () ;
break;
case V_8 :
V_2 -> V_6 = F_4 () ;
break;
default:
return - V_9 ;
}
F_5 ( V_2 ) ;
F_6 ( & V_2 -> V_10 -> V_11 ) ;
V_4 = V_2 -> V_6 -> V_12 ( V_2 , & V_2 -> V_13 ) ;
F_7 ( & V_2 -> V_10 -> V_11 ) ;
F_8 ( V_2 ) ;
return V_4 ;
}
int F_9 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_16 * V_17 , bool * V_18 )
{
int V_4 = 0 ;
if ( V_15 ) {
if ( ( V_15 -> V_19 & 63 ) != 0 ) {
F_10 ( L_1 ) ;
return - V_9 ;
}
}
if ( V_17 ) {
if ( ( ( V_17 -> V_20 . V_19 & 511 ) != 0 ) ||
( ( V_17 -> V_21 . V_19 & 511 ) != 0 ) ) {
F_10 ( L_2 ) ;
return - V_9 ;
}
}
if ( V_2 -> V_13 == 0 )
return - V_22 ;
F_5 ( V_2 ) ;
F_11 ( V_2 -> V_10 , V_2 ) ;
F_6 ( & V_2 -> V_10 -> V_11 ) ;
F_12 ( V_2 -> V_10 -> V_23 ) ;
V_4 = V_2 -> V_6 -> V_24 ( V_2 -> V_13 , V_15 , V_17 , V_18 ) ;
F_13 ( V_2 -> V_10 -> V_23 ) ;
F_7 ( & V_2 -> V_10 -> V_11 ) ;
F_11 ( V_2 -> V_10 , NULL ) ;
F_8 ( V_2 ) ;
return V_4 ;
}
int F_14 ( struct V_1 * V_2 , enum V_25 type ,
void * V_26 )
{
int V_4 = 0 ;
if ( V_2 -> V_13 == 0 )
return - V_22 ;
F_5 ( V_2 ) ;
V_4 = V_2 -> V_6 -> V_27 ( V_2 -> V_13 , type , V_26 ) ;
F_8 ( V_2 ) ;
return V_4 ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 == 0 )
return;
F_5 ( V_2 ) ;
F_6 ( & V_2 -> V_10 -> V_11 ) ;
V_2 -> V_6 -> V_28 ( V_2 -> V_13 ) ;
F_7 ( & V_2 -> V_10 -> V_11 ) ;
F_8 ( V_2 ) ;
V_2 -> V_13 = 0 ;
}
