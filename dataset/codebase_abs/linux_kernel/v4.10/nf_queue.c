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
struct V_18 * V_21 , unsigned int V_22 )
{
int V_23 = - V_24 ;
struct V_6 * V_7 = NULL ;
const struct V_25 * V_26 ;
const struct V_2 * V_3 ;
struct V_1 * V_1 = V_9 -> V_1 ;
V_3 = F_18 ( V_1 -> V_4 . V_5 ) ;
if ( ! V_3 ) {
V_23 = - V_27 ;
goto V_28;
}
V_26 = F_21 ( V_9 -> V_29 ) ;
if ( ! V_26 )
goto V_28;
V_7 = F_22 ( sizeof( * V_7 ) + V_26 -> V_30 , V_31 ) ;
if ( ! V_7 ) {
V_23 = - V_32 ;
goto V_28;
}
* V_7 = (struct V_6 ) {
. V_14 = V_14 ,
. V_9 = * V_9 ,
. V_33 = V_21 ,
. V_34 = sizeof( * V_7 ) + V_26 -> V_30 ,
} ;
F_13 ( V_7 ) ;
F_23 ( V_14 ) ;
V_26 -> V_35 ( V_14 , V_7 ) ;
V_23 = V_3 -> V_36 ( V_7 , V_22 ) ;
if ( V_23 < 0 ) {
F_7 ( V_7 ) ;
goto V_28;
}
return 0 ;
V_28:
F_24 ( V_7 ) ;
return V_23 ;
}
int F_25 ( struct V_20 * V_14 , struct V_8 * V_9 ,
struct V_18 * * V_37 , unsigned int V_38 )
{
struct V_18 * V_7 = * V_37 ;
int V_39 ;
V_39 = F_20 ( V_14 , V_9 , V_7 , V_38 >> V_40 ) ;
if ( V_39 < 0 ) {
if ( V_39 == - V_27 &&
( V_38 & V_41 ) ) {
* V_37 = F_18 ( V_7 -> V_42 ) ;
return 1 ;
}
F_26 ( V_14 ) ;
}
return 0 ;
}
static unsigned int F_27 ( struct V_20 * V_14 ,
struct V_8 * V_9 ,
struct V_18 * * V_37 )
{
unsigned int V_38 ;
do {
V_43:
V_38 = F_28 ( ( * V_37 ) , V_14 , V_9 ) ;
if ( V_38 != V_44 ) {
if ( V_38 != V_45 )
return V_38 ;
goto V_43;
}
* V_37 = F_18 ( ( * V_37 ) -> V_42 ) ;
} while ( * V_37 );
return V_44 ;
}
void F_29 ( struct V_6 * V_7 , unsigned int V_38 )
{
struct V_18 * V_21 = V_7 -> V_33 ;
struct V_20 * V_14 = V_7 -> V_14 ;
const struct V_25 * V_26 ;
int V_28 ;
F_7 ( V_7 ) ;
if ( V_38 == V_45 )
V_38 = F_28 ( V_21 , V_14 , & V_7 -> V_9 ) ;
if ( V_38 == V_44 ) {
V_26 = F_21 ( V_7 -> V_9 . V_29 ) ;
if ( ! V_26 || V_26 -> V_46 ( V_7 -> V_9 . V_1 , V_14 , V_7 ) < 0 )
V_38 = V_47 ;
}
if ( V_38 == V_44 ) {
V_21 = F_18 ( V_21 -> V_42 ) ;
if ( V_21 )
V_48:
V_38 = F_27 ( V_14 , & V_7 -> V_9 , & V_21 ) ;
}
switch ( V_38 & V_49 ) {
case V_44 :
case V_50 :
V_51:
F_30 () ;
V_7 -> V_9 . V_51 ( V_7 -> V_9 . V_1 , V_7 -> V_9 . V_12 , V_14 ) ;
F_31 () ;
break;
case V_52 :
V_28 = F_25 ( V_14 , & V_7 -> V_9 , & V_21 , V_38 ) ;
if ( V_28 == 1 ) {
if ( V_21 )
goto V_48;
goto V_51;
}
break;
case V_53 :
break;
default:
F_26 ( V_14 ) ;
}
F_24 ( V_7 ) ;
}
