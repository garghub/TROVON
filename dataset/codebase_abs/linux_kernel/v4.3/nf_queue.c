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
F_14 ( V_5 -> V_16 -> V_17 ) ;
}
bool F_15 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
if ( ! F_16 ( V_5 -> V_16 -> V_17 ) )
return false ;
if ( V_7 -> V_8 )
F_17 ( V_7 -> V_8 ) ;
if ( V_7 -> V_9 )
F_17 ( V_7 -> V_9 ) ;
if ( V_7 -> V_10 )
F_18 ( V_7 -> V_10 ) ;
#if F_11 ( V_11 )
if ( V_5 -> V_12 -> V_13 ) {
struct V_14 * V_15 ;
V_15 = F_12 ( V_5 -> V_12 ) ;
if ( V_15 )
F_17 ( V_15 ) ;
V_15 = F_13 ( V_5 -> V_12 ) ;
if ( V_15 )
F_17 ( V_15 ) ;
}
#endif
return true ;
}
void F_19 ( struct V_18 * V_18 , struct V_19 * V_20 )
{
const struct V_1 * V_2 ;
F_20 () ;
V_2 = F_21 ( V_3 ) ;
if ( V_2 )
V_2 -> V_21 ( V_18 , V_20 ) ;
F_22 () ;
}
int F_23 ( struct V_22 * V_12 ,
struct V_19 * V_16 ,
struct V_6 * V_7 ,
unsigned int V_23 )
{
int V_24 = - V_25 ;
struct V_4 * V_5 = NULL ;
const struct V_26 * V_27 ;
const struct V_1 * V_2 ;
F_20 () ;
V_2 = F_21 ( V_3 ) ;
if ( ! V_2 ) {
V_24 = - V_28 ;
goto V_29;
}
V_27 = F_24 ( V_7 -> V_30 ) ;
if ( ! V_27 )
goto V_29;
V_5 = F_25 ( sizeof( * V_5 ) + V_27 -> V_31 , V_32 ) ;
if ( ! V_5 ) {
V_24 = - V_33 ;
goto V_29;
}
* V_5 = (struct V_4 ) {
. V_12 = V_12 ,
. V_16 = V_16 ,
. V_7 = * V_7 ,
. V_34 = sizeof( * V_5 ) + V_27 -> V_31 ,
} ;
if ( ! F_15 ( V_5 ) ) {
V_24 = - V_35 ;
goto V_29;
}
F_26 ( V_12 ) ;
V_27 -> V_36 ( V_12 , V_5 ) ;
V_24 = V_2 -> V_37 ( V_5 , V_23 ) ;
F_22 () ;
if ( V_24 < 0 ) {
F_8 ( V_5 ) ;
goto V_38;
}
return 0 ;
V_29:
F_22 () ;
V_38:
F_27 ( V_5 ) ;
return V_24 ;
}
void F_28 ( struct V_4 * V_5 , unsigned int V_39 )
{
struct V_22 * V_12 = V_5 -> V_12 ;
struct V_19 * V_16 = V_5 -> V_16 ;
const struct V_26 * V_27 ;
int V_38 ;
F_20 () ;
F_8 ( V_5 ) ;
if ( V_39 == V_40 ) {
V_16 = F_29 ( V_16 -> V_41 . V_42 , struct V_19 , V_41 ) ;
V_39 = V_43 ;
}
if ( V_39 == V_43 ) {
V_27 = F_24 ( V_5 -> V_7 . V_30 ) ;
if ( ! V_27 || V_27 -> V_44 ( V_12 , V_5 ) < 0 )
V_39 = V_45 ;
}
V_5 -> V_7 . V_46 = V_47 ;
if ( V_39 == V_43 ) {
V_48:
V_39 = F_30 ( V_5 -> V_7 . V_49 ,
V_12 , & V_5 -> V_7 , & V_16 ) ;
}
switch ( V_39 & V_50 ) {
case V_43 :
case V_51 :
F_31 () ;
V_5 -> V_7 . V_52 ( V_5 -> V_7 . V_10 , V_12 ) ;
F_32 () ;
break;
case V_53 :
V_38 = F_23 ( V_12 , V_16 , & V_5 -> V_7 ,
V_39 >> V_54 ) ;
if ( V_38 < 0 ) {
if ( V_38 == - V_35 )
goto V_48;
if ( V_38 == - V_28 &&
( V_39 & V_55 ) )
goto V_48;
F_33 ( V_12 ) ;
}
break;
case V_56 :
break;
default:
F_33 ( V_12 ) ;
}
F_22 () ;
F_27 ( V_5 ) ;
}
