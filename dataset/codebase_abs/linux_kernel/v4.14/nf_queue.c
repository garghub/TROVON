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
const struct V_21 * V_22 ,
unsigned int V_23 , unsigned int V_24 )
{
int V_25 = - V_26 ;
struct V_6 * V_7 = NULL ;
const struct V_27 * V_28 ;
const struct V_2 * V_3 ;
struct V_1 * V_1 = V_9 -> V_1 ;
V_3 = F_18 ( V_1 -> V_4 . V_5 ) ;
if ( ! V_3 ) {
V_25 = - V_29 ;
goto V_30;
}
V_28 = F_21 ( V_9 -> V_31 ) ;
if ( ! V_28 )
goto V_30;
V_7 = F_22 ( sizeof( * V_7 ) + V_28 -> V_32 , V_33 ) ;
if ( ! V_7 ) {
V_25 = - V_34 ;
goto V_30;
}
* V_7 = (struct V_6 ) {
. V_14 = V_14 ,
. V_9 = * V_9 ,
. V_35 = V_23 ,
. V_36 = sizeof( * V_7 ) + V_28 -> V_32 ,
} ;
F_13 ( V_7 ) ;
F_23 ( V_14 ) ;
V_28 -> V_37 ( V_14 , V_7 ) ;
V_25 = V_3 -> V_38 ( V_7 , V_24 ) ;
if ( V_25 < 0 ) {
F_7 ( V_7 ) ;
goto V_30;
}
return 0 ;
V_30:
F_24 ( V_7 ) ;
return V_25 ;
}
int F_25 ( struct V_20 * V_14 , struct V_8 * V_9 ,
const struct V_21 * V_22 , unsigned int V_23 ,
unsigned int V_39 )
{
int V_40 ;
V_40 = F_20 ( V_14 , V_9 , V_22 , V_23 , V_39 >> V_41 ) ;
if ( V_40 < 0 ) {
if ( V_40 == - V_29 &&
( V_39 & V_42 ) )
return 1 ;
F_26 ( V_14 ) ;
}
return 0 ;
}
static unsigned int F_27 ( struct V_20 * V_14 ,
struct V_8 * V_9 ,
const struct V_21 * V_43 ,
unsigned int * V_23 )
{
const struct V_44 * V_45 ;
unsigned int V_39 , V_46 = * V_23 ;
while ( V_46 < V_43 -> V_47 ) {
V_45 = & V_43 -> V_43 [ V_46 ] ;
V_48:
V_39 = F_28 ( V_45 , V_14 , V_9 ) ;
if ( V_39 != V_49 ) {
if ( V_39 != V_50 )
return V_39 ;
goto V_48;
}
V_46 ++ ;
}
* V_23 = V_46 ;
return V_49 ;
}
void F_29 ( struct V_6 * V_7 , unsigned int V_39 )
{
const struct V_44 * V_51 ;
const struct V_21 * V_43 ;
struct V_20 * V_14 = V_7 -> V_14 ;
const struct V_27 * V_28 ;
const struct V_1 * V_1 ;
unsigned int V_46 ;
int V_30 ;
T_1 V_31 ;
V_1 = V_7 -> V_9 . V_1 ;
V_31 = V_7 -> V_9 . V_31 ;
V_43 = F_18 ( V_1 -> V_4 . V_43 [ V_31 ] [ V_7 -> V_9 . V_45 ] ) ;
F_7 ( V_7 ) ;
V_46 = V_7 -> V_35 ;
if ( F_30 ( V_46 >= V_43 -> V_47 ) ) {
F_26 ( V_14 ) ;
F_24 ( V_7 ) ;
return;
}
V_51 = & V_43 -> V_43 [ V_46 ] ;
if ( V_39 == V_50 )
V_39 = F_28 ( V_51 , V_14 , & V_7 -> V_9 ) ;
if ( V_39 == V_49 ) {
V_28 = F_21 ( V_7 -> V_9 . V_31 ) ;
if ( ! V_28 || V_28 -> V_52 ( V_7 -> V_9 . V_1 , V_14 , V_7 ) < 0 )
V_39 = V_53 ;
}
if ( V_39 == V_49 ) {
V_54:
++ V_46 ;
V_39 = F_27 ( V_14 , & V_7 -> V_9 , V_43 , & V_46 ) ;
}
switch ( V_39 & V_55 ) {
case V_49 :
case V_56 :
F_31 () ;
V_7 -> V_9 . V_57 ( V_7 -> V_9 . V_1 , V_7 -> V_9 . V_12 , V_14 ) ;
F_32 () ;
break;
case V_58 :
V_30 = F_25 ( V_14 , & V_7 -> V_9 , V_43 , V_46 , V_39 ) ;
if ( V_30 == 1 )
goto V_54;
break;
case V_59 :
break;
default:
F_26 ( V_14 ) ;
}
F_24 ( V_7 ) ;
}
