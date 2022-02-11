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
#ifdef F_10
if ( V_5 -> V_8 -> V_9 ) {
struct V_10 * V_9 = V_5 -> V_8 -> V_9 ;
if ( V_9 -> V_11 )
F_9 ( V_9 -> V_11 ) ;
if ( V_9 -> V_12 )
F_9 ( V_9 -> V_12 ) ;
}
#endif
F_11 ( V_5 -> V_13 -> V_14 ) ;
}
bool F_12 ( struct V_4 * V_5 )
{
if ( ! F_13 ( V_5 -> V_13 -> V_14 ) )
return false ;
if ( V_5 -> V_6 )
F_14 ( V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
F_14 ( V_5 -> V_7 ) ;
#ifdef F_10
if ( V_5 -> V_8 -> V_9 ) {
struct V_10 * V_9 = V_5 -> V_8 -> V_9 ;
struct V_15 * V_16 ;
V_16 = V_9 -> V_11 ;
if ( V_16 )
F_14 ( V_16 ) ;
V_16 = V_9 -> V_12 ;
if ( V_16 )
F_14 ( V_16 ) ;
}
#endif
return true ;
}
int F_15 ( struct V_17 * V_8 ,
struct V_18 * V_13 ,
T_1 V_19 , unsigned int V_20 ,
struct V_15 * V_6 ,
struct V_15 * V_7 ,
int (* F_16)( struct V_17 * ) ,
unsigned int V_21 )
{
int V_22 = - V_23 ;
struct V_4 * V_5 = NULL ;
const struct V_24 * V_25 ;
const struct V_1 * V_2 ;
F_17 () ;
V_2 = F_18 ( V_3 ) ;
if ( ! V_2 ) {
V_22 = - V_26 ;
goto V_27;
}
V_25 = F_19 ( V_19 ) ;
if ( ! V_25 )
goto V_27;
V_5 = F_20 ( sizeof( * V_5 ) + V_25 -> V_28 , V_29 ) ;
if ( ! V_5 ) {
V_22 = - V_30 ;
goto V_27;
}
* V_5 = (struct V_4 ) {
. V_8 = V_8 ,
. V_13 = V_13 ,
. V_19 = V_19 ,
. V_20 = V_20 ,
. V_6 = V_6 ,
. V_7 = V_7 ,
. F_16 = F_16 ,
. V_31 = sizeof( * V_5 ) + V_25 -> V_28 ,
} ;
if ( ! F_12 ( V_5 ) ) {
V_22 = - V_32 ;
goto V_27;
}
F_21 ( V_8 ) ;
V_25 -> V_33 ( V_8 , V_5 ) ;
V_22 = V_2 -> V_34 ( V_5 , V_21 ) ;
F_22 () ;
if ( V_22 < 0 ) {
F_8 ( V_5 ) ;
goto V_35;
}
return 0 ;
V_27:
F_22 () ;
V_35:
F_23 ( V_5 ) ;
return V_22 ;
}
void F_24 ( struct V_4 * V_5 , unsigned int V_36 )
{
struct V_17 * V_8 = V_5 -> V_8 ;
struct V_18 * V_13 = V_5 -> V_13 ;
const struct V_24 * V_25 ;
int V_35 ;
F_17 () ;
F_8 ( V_5 ) ;
if ( V_36 == V_37 ) {
V_13 = F_25 ( V_13 -> V_38 . V_39 , struct V_18 , V_38 ) ;
V_36 = V_40 ;
}
if ( V_36 == V_40 ) {
V_25 = F_19 ( V_5 -> V_19 ) ;
if ( ! V_25 || V_25 -> V_41 ( V_8 , V_5 ) < 0 )
V_36 = V_42 ;
}
if ( V_36 == V_40 ) {
V_43:
V_36 = F_26 ( & V_44 [ V_5 -> V_19 ] [ V_5 -> V_20 ] ,
V_8 , V_5 -> V_20 ,
V_5 -> V_6 , V_5 -> V_7 , & V_13 ,
V_5 -> F_16 , V_45 ) ;
}
switch ( V_36 & V_46 ) {
case V_40 :
case V_47 :
F_27 () ;
V_5 -> F_16 ( V_8 ) ;
F_28 () ;
break;
case V_48 :
V_35 = F_15 ( V_8 , V_13 , V_5 -> V_19 , V_5 -> V_20 ,
V_5 -> V_6 , V_5 -> V_7 , V_5 -> F_16 ,
V_36 >> V_49 ) ;
if ( V_35 < 0 ) {
if ( V_35 == - V_32 )
goto V_43;
if ( V_35 == - V_26 &&
( V_36 & V_50 ) )
goto V_43;
F_29 ( V_8 ) ;
}
break;
case V_51 :
break;
default:
F_29 ( V_8 ) ;
}
F_22 () ;
F_23 ( V_5 ) ;
}
