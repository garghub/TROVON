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
struct V_6 * V_7 = & V_5 -> V_7 ;
if ( V_7 -> V_8 )
F_9 ( V_7 -> V_8 ) ;
if ( V_7 -> V_9 )
F_9 ( V_7 -> V_9 ) ;
if ( V_7 -> V_10 )
F_10 ( V_7 -> V_10 ) ;
#if F_11 ( V_11 )
if ( V_5 -> V_12 -> V_13 ) {
struct V_14 * V_15 ;
V_15 = F_12 ( V_5 -> V_12 ) ;
if ( V_15 )
F_9 ( V_15 ) ;
V_15 = F_13 ( V_5 -> V_12 ) ;
if ( V_15 )
F_9 ( V_15 ) ;
}
#endif
}
void F_14 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
if ( V_7 -> V_8 )
F_15 ( V_7 -> V_8 ) ;
if ( V_7 -> V_9 )
F_15 ( V_7 -> V_9 ) ;
if ( V_7 -> V_10 )
F_16 ( V_7 -> V_10 ) ;
#if F_11 ( V_11 )
if ( V_5 -> V_12 -> V_13 ) {
struct V_14 * V_15 ;
V_15 = F_12 ( V_5 -> V_12 ) ;
if ( V_15 )
F_15 ( V_15 ) ;
V_15 = F_13 ( V_5 -> V_12 ) ;
if ( V_15 )
F_15 ( V_15 ) ;
}
#endif
}
void F_17 ( struct V_16 * V_16 , struct V_17 * V_18 )
{
const struct V_1 * V_2 ;
F_18 () ;
V_2 = F_19 ( V_3 ) ;
if ( V_2 )
V_2 -> V_19 ( V_16 , V_18 ) ;
F_20 () ;
}
int F_21 ( struct V_20 * V_12 ,
struct V_17 * V_21 ,
struct V_6 * V_7 ,
unsigned int V_22 )
{
int V_23 = - V_24 ;
struct V_4 * V_5 = NULL ;
const struct V_25 * V_26 ;
const struct V_1 * V_2 ;
V_2 = F_19 ( V_3 ) ;
if ( ! V_2 ) {
V_23 = - V_27 ;
goto V_28;
}
V_26 = F_22 ( V_7 -> V_29 ) ;
if ( ! V_26 )
goto V_28;
V_5 = F_23 ( sizeof( * V_5 ) + V_26 -> V_30 , V_31 ) ;
if ( ! V_5 ) {
V_23 = - V_32 ;
goto V_28;
}
* V_5 = (struct V_4 ) {
. V_12 = V_12 ,
. V_21 = V_21 ,
. V_7 = * V_7 ,
. V_33 = sizeof( * V_5 ) + V_26 -> V_30 ,
} ;
F_14 ( V_5 ) ;
F_24 ( V_12 ) ;
V_26 -> V_34 ( V_12 , V_5 ) ;
V_23 = V_2 -> V_35 ( V_5 , V_22 ) ;
if ( V_23 < 0 ) {
F_8 ( V_5 ) ;
goto V_28;
}
return 0 ;
V_28:
F_25 ( V_5 ) ;
return V_23 ;
}
void F_26 ( struct V_4 * V_5 , unsigned int V_36 )
{
struct V_20 * V_12 = V_5 -> V_12 ;
struct V_17 * V_21 = V_5 -> V_21 ;
const struct V_25 * V_26 ;
int V_28 ;
F_8 ( V_5 ) ;
if ( V_36 == V_37 )
V_36 = V_21 -> V_38 ( V_21 -> V_39 , V_12 , & V_5 -> V_7 ) ;
if ( V_36 == V_40 ) {
V_26 = F_22 ( V_5 -> V_7 . V_29 ) ;
if ( ! V_26 || V_26 -> V_41 ( V_5 -> V_7 . V_16 , V_12 , V_5 ) < 0 )
V_36 = V_42 ;
}
V_5 -> V_7 . V_43 = V_44 ;
if ( V_36 == V_40 ) {
V_45:
V_36 = F_27 ( V_5 -> V_7 . V_46 ,
V_12 , & V_5 -> V_7 , & V_21 ) ;
}
switch ( V_36 & V_47 ) {
case V_40 :
case V_48 :
F_28 () ;
V_5 -> V_7 . V_49 ( V_5 -> V_7 . V_16 , V_5 -> V_7 . V_10 , V_12 ) ;
F_29 () ;
break;
case V_50 :
V_28 = F_21 ( V_12 , V_21 , & V_5 -> V_7 ,
V_36 >> V_51 ) ;
if ( V_28 < 0 ) {
if ( V_28 == - V_27 &&
( V_36 & V_52 ) )
goto V_45;
F_30 ( V_12 ) ;
}
break;
case V_53 :
break;
default:
F_30 ( V_12 ) ;
}
F_25 ( V_5 ) ;
}
