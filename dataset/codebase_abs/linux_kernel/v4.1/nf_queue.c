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
int F_19 ( struct V_18 * V_12 ,
struct V_19 * V_16 ,
struct V_6 * V_7 ,
unsigned int V_20 )
{
int V_21 = - V_22 ;
struct V_4 * V_5 = NULL ;
const struct V_23 * V_24 ;
const struct V_1 * V_2 ;
F_20 () ;
V_2 = F_21 ( V_3 ) ;
if ( ! V_2 ) {
V_21 = - V_25 ;
goto V_26;
}
V_24 = F_22 ( V_7 -> V_27 ) ;
if ( ! V_24 )
goto V_26;
V_5 = F_23 ( sizeof( * V_5 ) + V_24 -> V_28 , V_29 ) ;
if ( ! V_5 ) {
V_21 = - V_30 ;
goto V_26;
}
* V_5 = (struct V_4 ) {
. V_12 = V_12 ,
. V_16 = V_16 ,
. V_7 = * V_7 ,
. V_31 = sizeof( * V_5 ) + V_24 -> V_28 ,
} ;
if ( ! F_15 ( V_5 ) ) {
V_21 = - V_32 ;
goto V_26;
}
F_24 ( V_12 ) ;
V_24 -> V_33 ( V_12 , V_5 ) ;
V_21 = V_2 -> V_34 ( V_5 , V_20 ) ;
F_25 () ;
if ( V_21 < 0 ) {
F_8 ( V_5 ) ;
goto V_35;
}
return 0 ;
V_26:
F_25 () ;
V_35:
F_26 ( V_5 ) ;
return V_21 ;
}
void F_27 ( struct V_4 * V_5 , unsigned int V_36 )
{
struct V_18 * V_12 = V_5 -> V_12 ;
struct V_19 * V_16 = V_5 -> V_16 ;
const struct V_23 * V_24 ;
int V_35 ;
F_20 () ;
F_8 ( V_5 ) ;
if ( V_36 == V_37 ) {
V_16 = F_28 ( V_16 -> V_38 . V_39 , struct V_19 , V_38 ) ;
V_36 = V_40 ;
}
if ( V_36 == V_40 ) {
V_24 = F_22 ( V_5 -> V_7 . V_27 ) ;
if ( ! V_24 || V_24 -> V_41 ( V_12 , V_5 ) < 0 )
V_36 = V_42 ;
}
V_5 -> V_7 . V_43 = V_44 ;
if ( V_36 == V_40 ) {
V_45:
V_36 = F_29 ( & V_46 [ V_5 -> V_7 . V_27 ] [ V_5 -> V_7 . V_47 ] ,
V_12 , & V_5 -> V_7 , & V_16 ) ;
}
switch ( V_36 & V_48 ) {
case V_40 :
case V_49 :
F_30 () ;
V_5 -> V_7 . V_50 ( V_5 -> V_7 . V_10 , V_12 ) ;
F_31 () ;
break;
case V_51 :
V_35 = F_19 ( V_12 , V_16 , & V_5 -> V_7 ,
V_36 >> V_52 ) ;
if ( V_35 < 0 ) {
if ( V_35 == - V_32 )
goto V_45;
if ( V_35 == - V_25 &&
( V_36 & V_53 ) )
goto V_45;
F_32 ( V_12 ) ;
}
break;
case V_54 :
break;
default:
F_32 ( V_12 ) ;
}
F_25 () ;
F_26 ( V_5 ) ;
}
