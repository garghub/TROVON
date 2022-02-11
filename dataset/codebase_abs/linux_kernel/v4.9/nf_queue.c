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
void F_16 ( struct V_1 * V_1 , const struct V_18 * V_7 )
{
const struct V_2 * V_3 ;
F_17 () ;
V_3 = F_18 ( V_1 -> V_4 . V_5 ) ;
if ( V_3 )
V_3 -> V_19 ( V_1 , V_7 ) ;
F_19 () ;
}
static int F_20 ( struct V_20 * V_14 , const struct V_8 * V_9 ,
unsigned int V_21 )
{
int V_22 = - V_23 ;
struct V_6 * V_7 = NULL ;
const struct V_24 * V_25 ;
const struct V_2 * V_3 ;
struct V_1 * V_1 = V_9 -> V_1 ;
V_3 = F_18 ( V_1 -> V_4 . V_5 ) ;
if ( ! V_3 ) {
V_22 = - V_26 ;
goto V_27;
}
V_25 = F_21 ( V_9 -> V_28 ) ;
if ( ! V_25 )
goto V_27;
V_7 = F_22 ( sizeof( * V_7 ) + V_25 -> V_29 , V_30 ) ;
if ( ! V_7 ) {
V_22 = - V_31 ;
goto V_27;
}
* V_7 = (struct V_6 ) {
. V_14 = V_14 ,
. V_9 = * V_9 ,
. V_32 = sizeof( * V_7 ) + V_25 -> V_29 ,
} ;
F_13 ( V_7 ) ;
F_23 ( V_14 ) ;
V_25 -> V_33 ( V_14 , V_7 ) ;
V_22 = V_3 -> V_34 ( V_7 , V_21 ) ;
if ( V_22 < 0 ) {
F_7 ( V_7 ) ;
goto V_27;
}
return 0 ;
V_27:
F_24 ( V_7 ) ;
return V_22 ;
}
int F_25 ( struct V_20 * V_14 , struct V_8 * V_9 ,
struct V_18 * * V_35 , unsigned int V_36 )
{
struct V_18 * V_7 = * V_35 ;
int V_37 ;
F_6 ( V_9 -> V_38 , V_7 ) ;
V_37 = F_20 ( V_14 , V_9 , V_36 >> V_39 ) ;
if ( V_37 < 0 ) {
if ( V_37 == - V_26 &&
( V_36 & V_40 ) ) {
* V_35 = F_18 ( V_7 -> V_41 ) ;
return 1 ;
}
F_26 ( V_14 ) ;
}
return 0 ;
}
void F_27 ( struct V_6 * V_7 , unsigned int V_36 )
{
struct V_18 * V_42 ;
struct V_20 * V_14 = V_7 -> V_14 ;
const struct V_24 * V_25 ;
struct V_43 * V_44 ;
int V_27 ;
V_42 = F_18 ( V_7 -> V_9 . V_38 ) ;
V_44 = & V_42 -> V_45 ;
F_7 ( V_7 ) ;
if ( V_36 == V_46 )
V_36 = V_44 -> V_47 ( V_44 -> V_48 , V_14 , & V_7 -> V_9 ) ;
if ( V_36 == V_49 ) {
V_25 = F_21 ( V_7 -> V_9 . V_28 ) ;
if ( ! V_25 || V_25 -> V_50 ( V_7 -> V_9 . V_1 , V_14 , V_7 ) < 0 )
V_36 = V_51 ;
}
V_7 -> V_9 . V_52 = V_53 ;
if ( V_36 == V_49 ) {
V_42 = F_18 ( V_42 -> V_41 ) ;
if ( V_42 )
V_54:
V_36 = F_28 ( V_14 , & V_7 -> V_9 , & V_42 ) ;
}
switch ( V_36 & V_55 ) {
case V_49 :
case V_56 :
V_57:
F_29 () ;
V_7 -> V_9 . V_57 ( V_7 -> V_9 . V_1 , V_7 -> V_9 . V_12 , V_14 ) ;
F_30 () ;
break;
case V_58 :
V_27 = F_25 ( V_14 , & V_7 -> V_9 , & V_42 , V_36 ) ;
if ( V_27 == 1 ) {
if ( V_42 )
goto V_54;
goto V_57;
}
break;
case V_59 :
break;
default:
F_26 ( V_14 ) ;
}
F_24 ( V_7 ) ;
}
