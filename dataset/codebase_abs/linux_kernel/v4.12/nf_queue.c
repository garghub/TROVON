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
unsigned int F_16 ( struct V_1 * V_1 )
{
const struct V_2 * V_3 ;
unsigned int V_18 = 0 ;
F_17 () ;
V_3 = F_18 ( V_1 -> V_4 . V_5 ) ;
if ( V_3 )
V_18 = V_3 -> V_19 ( V_1 ) ;
F_19 () ;
return V_18 ;
}
static int F_20 ( struct V_20 * V_14 , const struct V_8 * V_9 ,
struct V_21 * V_22 , unsigned int V_23 )
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
. V_9 = * V_9 ,
. V_34 = V_22 ,
. V_35 = sizeof( * V_7 ) + V_27 -> V_31 ,
} ;
F_13 ( V_7 ) ;
F_23 ( V_14 ) ;
V_27 -> V_36 ( V_14 , V_7 ) ;
V_24 = V_3 -> V_37 ( V_7 , V_23 ) ;
if ( V_24 < 0 ) {
F_7 ( V_7 ) ;
goto V_29;
}
return 0 ;
V_29:
F_24 ( V_7 ) ;
return V_24 ;
}
int F_25 ( struct V_20 * V_14 , struct V_8 * V_9 ,
struct V_21 * * V_38 , unsigned int V_39 )
{
struct V_21 * V_7 = * V_38 ;
int V_40 ;
V_40 = F_20 ( V_14 , V_9 , V_7 , V_39 >> V_41 ) ;
if ( V_40 < 0 ) {
if ( V_40 == - V_28 &&
( V_39 & V_42 ) ) {
* V_38 = F_18 ( V_7 -> V_43 ) ;
return 1 ;
}
F_26 ( V_14 ) ;
}
return 0 ;
}
static unsigned int F_27 ( struct V_20 * V_14 ,
struct V_8 * V_9 ,
struct V_21 * * V_38 )
{
unsigned int V_39 ;
do {
V_44:
V_39 = F_28 ( ( * V_38 ) , V_14 , V_9 ) ;
if ( V_39 != V_45 ) {
if ( V_39 != V_46 )
return V_39 ;
goto V_44;
}
* V_38 = F_18 ( ( * V_38 ) -> V_43 ) ;
} while ( * V_38 );
return V_45 ;
}
void F_29 ( struct V_6 * V_7 , unsigned int V_39 )
{
struct V_21 * V_22 = V_7 -> V_34 ;
struct V_20 * V_14 = V_7 -> V_14 ;
const struct V_26 * V_27 ;
int V_29 ;
F_7 ( V_7 ) ;
if ( V_39 == V_46 )
V_39 = F_28 ( V_22 , V_14 , & V_7 -> V_9 ) ;
if ( V_39 == V_45 ) {
V_27 = F_21 ( V_7 -> V_9 . V_30 ) ;
if ( ! V_27 || V_27 -> V_47 ( V_7 -> V_9 . V_1 , V_14 , V_7 ) < 0 )
V_39 = V_48 ;
}
if ( V_39 == V_45 ) {
V_22 = F_18 ( V_22 -> V_43 ) ;
if ( V_22 )
V_49:
V_39 = F_27 ( V_14 , & V_7 -> V_9 , & V_22 ) ;
}
switch ( V_39 & V_50 ) {
case V_45 :
case V_51 :
V_52:
F_30 () ;
V_7 -> V_9 . V_52 ( V_7 -> V_9 . V_1 , V_7 -> V_9 . V_12 , V_14 ) ;
F_31 () ;
break;
case V_53 :
V_29 = F_25 ( V_14 , & V_7 -> V_9 , & V_22 , V_39 ) ;
if ( V_29 == 1 ) {
if ( V_22 )
goto V_49;
goto V_52;
}
break;
case V_54 :
break;
default:
F_26 ( V_14 ) ;
}
F_24 ( V_7 ) ;
}
