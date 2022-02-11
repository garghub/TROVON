void F_1 ( const struct V_1 * V_2 )
{
F_2 ( F_3 ( V_3 ) ) ;
F_4 ( V_3 , V_2 ) ;
}
void F_5 ( void )
{
F_6 ( V_3 , NULL ) ;
F_7 () ;
}
void F_8 ( struct V_4 * V_5 )
{
if ( V_5 -> V_6 )
F_9 ( V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
F_9 ( V_5 -> V_7 ) ;
#if F_10 ( V_8 )
if ( V_5 -> V_9 -> V_10 ) {
struct V_11 * V_10 = V_5 -> V_9 -> V_10 ;
if ( V_10 -> V_12 )
F_9 ( V_10 -> V_12 ) ;
if ( V_10 -> V_13 )
F_9 ( V_10 -> V_13 ) ;
}
#endif
F_11 ( V_5 -> V_14 -> V_15 ) ;
}
bool F_12 ( struct V_4 * V_5 )
{
if ( ! F_13 ( V_5 -> V_14 -> V_15 ) )
return false ;
if ( V_5 -> V_6 )
F_14 ( V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
F_14 ( V_5 -> V_7 ) ;
#if F_10 ( V_8 )
if ( V_5 -> V_9 -> V_10 ) {
struct V_11 * V_10 = V_5 -> V_9 -> V_10 ;
struct V_16 * V_17 ;
V_17 = V_10 -> V_12 ;
if ( V_17 )
F_14 ( V_17 ) ;
V_17 = V_10 -> V_13 ;
if ( V_17 )
F_14 ( V_17 ) ;
}
#endif
return true ;
}
int F_15 ( struct V_18 * V_9 ,
struct V_19 * V_14 ,
T_1 V_20 , unsigned int V_21 ,
struct V_16 * V_6 ,
struct V_16 * V_7 ,
int (* F_16)( struct V_18 * ) ,
unsigned int V_22 )
{
int V_23 = - V_24 ;
struct V_4 * V_5 = NULL ;
const struct V_25 * V_26 ;
const struct V_1 * V_2 ;
F_17 () ;
V_2 = F_18 ( V_3 ) ;
if ( ! V_2 ) {
V_23 = - V_27 ;
goto V_28;
}
V_26 = F_19 ( V_20 ) ;
if ( ! V_26 )
goto V_28;
V_5 = F_20 ( sizeof( * V_5 ) + V_26 -> V_29 , V_30 ) ;
if ( ! V_5 ) {
V_23 = - V_31 ;
goto V_28;
}
* V_5 = (struct V_4 ) {
. V_9 = V_9 ,
. V_14 = V_14 ,
. V_20 = V_20 ,
. V_21 = V_21 ,
. V_6 = V_6 ,
. V_7 = V_7 ,
. F_16 = F_16 ,
. V_32 = sizeof( * V_5 ) + V_26 -> V_29 ,
} ;
if ( ! F_12 ( V_5 ) ) {
V_23 = - V_33 ;
goto V_28;
}
F_21 ( V_9 ) ;
V_26 -> V_34 ( V_9 , V_5 ) ;
V_23 = V_2 -> V_35 ( V_5 , V_22 ) ;
F_22 () ;
if ( V_23 < 0 ) {
F_8 ( V_5 ) ;
goto V_36;
}
return 0 ;
V_28:
F_22 () ;
V_36:
F_23 ( V_5 ) ;
return V_23 ;
}
void F_24 ( struct V_4 * V_5 , unsigned int V_37 )
{
struct V_18 * V_9 = V_5 -> V_9 ;
struct V_19 * V_14 = V_5 -> V_14 ;
const struct V_25 * V_26 ;
int V_36 ;
F_17 () ;
F_8 ( V_5 ) ;
if ( V_37 == V_38 ) {
V_14 = F_25 ( V_14 -> V_39 . V_40 , struct V_19 , V_39 ) ;
V_37 = V_41 ;
}
if ( V_37 == V_41 ) {
V_26 = F_19 ( V_5 -> V_20 ) ;
if ( ! V_26 || V_26 -> V_42 ( V_9 , V_5 ) < 0 )
V_37 = V_43 ;
}
if ( V_37 == V_41 ) {
V_44:
V_37 = F_26 ( & V_45 [ V_5 -> V_20 ] [ V_5 -> V_21 ] ,
V_9 , V_5 -> V_21 ,
V_5 -> V_6 , V_5 -> V_7 , & V_14 ,
V_5 -> F_16 , V_46 ) ;
}
switch ( V_37 & V_47 ) {
case V_41 :
case V_48 :
F_27 () ;
V_5 -> F_16 ( V_9 ) ;
F_28 () ;
break;
case V_49 :
V_36 = F_15 ( V_9 , V_14 , V_5 -> V_20 , V_5 -> V_21 ,
V_5 -> V_6 , V_5 -> V_7 , V_5 -> F_16 ,
V_37 >> V_50 ) ;
if ( V_36 < 0 ) {
if ( V_36 == - V_33 )
goto V_44;
if ( V_36 == - V_27 &&
( V_37 & V_51 ) )
goto V_44;
F_29 ( V_9 ) ;
}
break;
case V_52 :
break;
default:
F_29 ( V_9 ) ;
}
F_22 () ;
F_23 ( V_5 ) ;
}
