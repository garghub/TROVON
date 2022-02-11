void F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 )
{
F_2 ( F_3 ( V_1 -> V_4 . V_5 ) ) ;
F_4 ( V_1 -> V_4 . V_5 , V_3 ) ;
}
void F_5 ( struct V_1 * V_1 )
{
F_6 ( V_1 -> V_4 . V_5 , NULL ) ;
}
void F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( V_9 -> V_10 )
F_8 ( V_9 -> V_10 ) ;
if ( V_9 -> V_11 )
F_8 ( V_9 -> V_11 ) ;
if ( V_9 -> V_12 )
F_9 ( V_9 -> V_12 ) ;
#if F_10 ( V_13 )
if ( V_7 -> V_14 -> V_15 ) {
struct V_16 * V_17 ;
V_17 = F_11 ( V_7 -> V_14 ) ;
if ( V_17 )
F_8 ( V_17 ) ;
V_17 = F_12 ( V_7 -> V_14 ) ;
if ( V_17 )
F_8 ( V_17 ) ;
}
#endif
}
void F_13 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
if ( V_9 -> V_10 )
F_14 ( V_9 -> V_10 ) ;
if ( V_9 -> V_11 )
F_14 ( V_9 -> V_11 ) ;
if ( V_9 -> V_12 )
F_15 ( V_9 -> V_12 ) ;
#if F_10 ( V_13 )
if ( V_7 -> V_14 -> V_15 ) {
struct V_16 * V_17 ;
V_17 = F_11 ( V_7 -> V_14 ) ;
if ( V_17 )
F_14 ( V_17 ) ;
V_17 = F_12 ( V_7 -> V_14 ) ;
if ( V_17 )
F_14 ( V_17 ) ;
}
#endif
}
void F_16 ( struct V_1 * V_1 , struct V_18 * V_19 )
{
const struct V_2 * V_3 ;
F_17 () ;
V_3 = F_18 ( V_1 -> V_4 . V_5 ) ;
if ( V_3 )
V_3 -> V_20 ( V_1 , V_19 ) ;
F_19 () ;
}
int F_20 ( struct V_21 * V_14 ,
struct V_18 * V_22 ,
struct V_8 * V_9 ,
unsigned int V_23 )
{
int V_24 = - V_25 ;
struct V_6 * V_7 = NULL ;
const struct V_26 * V_27 ;
const struct V_2 * V_3 ;
struct V_1 * V_1 = V_9 -> V_1 ;
V_3 = F_18 ( V_1 -> V_4 . V_5 ) ;
if ( ! V_3 ) {
V_24 = - V_28 ;
goto V_29;
}
V_27 = F_21 ( V_9 -> V_30 ) ;
if ( ! V_27 )
goto V_29;
V_7 = F_22 ( sizeof( * V_7 ) + V_27 -> V_31 , V_32 ) ;
if ( ! V_7 ) {
V_24 = - V_33 ;
goto V_29;
}
* V_7 = (struct V_6 ) {
. V_14 = V_14 ,
. V_22 = V_22 ,
. V_9 = * V_9 ,
. V_34 = sizeof( * V_7 ) + V_27 -> V_31 ,
} ;
F_13 ( V_7 ) ;
F_23 ( V_14 ) ;
V_27 -> V_35 ( V_14 , V_7 ) ;
V_24 = V_3 -> V_36 ( V_7 , V_23 ) ;
if ( V_24 < 0 ) {
F_7 ( V_7 ) ;
goto V_29;
}
return 0 ;
V_29:
F_24 ( V_7 ) ;
return V_24 ;
}
void F_25 ( struct V_6 * V_7 , unsigned int V_37 )
{
struct V_21 * V_14 = V_7 -> V_14 ;
struct V_18 * V_22 = V_7 -> V_22 ;
const struct V_26 * V_27 ;
int V_29 ;
F_7 ( V_7 ) ;
if ( V_37 == V_38 )
V_37 = V_22 -> V_39 ( V_22 -> V_40 , V_14 , & V_7 -> V_9 ) ;
if ( V_37 == V_41 ) {
V_27 = F_21 ( V_7 -> V_9 . V_30 ) ;
if ( ! V_27 || V_27 -> V_42 ( V_7 -> V_9 . V_1 , V_14 , V_7 ) < 0 )
V_37 = V_43 ;
}
V_7 -> V_9 . V_44 = V_45 ;
if ( V_37 == V_41 ) {
V_46:
V_37 = F_26 ( V_7 -> V_9 . V_47 ,
V_14 , & V_7 -> V_9 , & V_22 ) ;
}
switch ( V_37 & V_48 ) {
case V_41 :
case V_49 :
F_27 () ;
V_7 -> V_9 . V_50 ( V_7 -> V_9 . V_1 , V_7 -> V_9 . V_12 , V_14 ) ;
F_28 () ;
break;
case V_51 :
V_29 = F_20 ( V_14 , V_22 , & V_7 -> V_9 ,
V_37 >> V_52 ) ;
if ( V_29 < 0 ) {
if ( V_29 == - V_28 &&
( V_37 & V_53 ) )
goto V_46;
F_29 ( V_14 ) ;
}
break;
case V_54 :
break;
default:
F_29 ( V_14 ) ;
}
F_24 ( V_7 ) ;
}
