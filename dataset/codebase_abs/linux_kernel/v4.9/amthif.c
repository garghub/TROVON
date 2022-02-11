void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = false ;
V_2 -> V_4 = V_5 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
}
int F_2 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_2 -> V_12 ;
int V_13 ;
F_3 ( & V_2 -> V_14 ) ;
if ( F_4 ( V_11 ) ) {
V_13 = 0 ;
goto V_15;
}
V_2 -> V_4 = V_5 ;
F_5 ( V_11 , V_2 ) ;
V_13 = F_6 ( V_11 ) ;
if ( V_13 < 0 ) {
F_7 ( V_2 -> V_2 , L_1 , V_13 ) ;
goto V_15;
}
V_13 = F_8 ( V_11 , V_9 , NULL ) ;
V_15:
F_9 ( & V_2 -> V_14 ) ;
return V_13 ;
}
static int F_10 ( struct V_10 * V_11 , const struct V_16 * V_17 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_18 * V_19 ;
V_19 = F_11 ( V_11 , F_12 ( V_11 ) , V_20 , V_17 ) ;
if ( ! V_19 )
return - V_21 ;
V_11 -> V_22 ++ ;
V_2 -> V_4 = V_23 ;
V_11 -> V_17 = V_19 -> V_17 ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_12 ;
struct V_18 * V_19 ;
int V_13 ;
V_2 -> V_3 = false ;
F_14 ( V_2 -> V_2 , L_2 ) ;
V_19 = F_15 ( & V_2 -> V_24 . V_25 ,
F_16 ( * V_19 ) , V_25 ) ;
if ( ! V_19 ) {
V_2 -> V_4 = V_5 ;
V_11 -> V_17 = NULL ;
return 0 ;
}
F_17 ( & V_19 -> V_25 ) ;
V_2 -> V_4 = V_26 ;
V_11 -> V_17 = V_19 -> V_17 ;
V_13 = F_18 ( V_11 , V_19 , false ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_19 -> V_27 )
V_19 -> V_28 = F_10 ( V_11 , V_19 -> V_17 ) ;
return 0 ;
}
int F_19 ( struct V_10 * V_11 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
F_20 ( & V_19 -> V_25 , & V_2 -> V_24 . V_25 ) ;
if ( V_2 -> V_4 != V_5 )
return 0 ;
return F_13 ( V_2 ) ;
}
unsigned int F_21 ( struct V_16 * V_16 , T_1 * V_29 )
{
struct V_10 * V_11 = V_16 -> V_30 ;
struct V_18 * V_19 = F_22 ( V_11 , V_16 ) ;
unsigned int V_31 = 0 ;
F_23 ( V_16 , & V_11 -> V_32 , V_29 ) ;
if ( V_19 )
V_31 |= V_33 | V_34 ;
return V_31 ;
}
int F_24 ( struct V_10 * V_11 , struct V_18 * V_19 ,
struct V_18 * V_35 )
{
int V_13 ;
V_13 = F_25 ( V_11 , V_19 , V_35 ) ;
if ( V_13 )
return V_13 ;
if ( V_19 -> V_27 )
V_19 -> V_28 = F_10 ( V_11 , V_19 -> V_17 ) ;
return 0 ;
}
int F_26 ( struct V_10 * V_11 ,
struct V_36 * V_37 ,
struct V_18 * V_35 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = V_11 -> V_2 ;
if ( V_2 -> V_4 != V_23 ) {
F_27 ( V_2 , V_37 ) ;
return 0 ;
}
V_13 = F_28 ( V_11 , V_37 , V_35 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_37 -> V_38 )
return 0 ;
F_14 ( V_2 -> V_2 , L_3 ) ;
V_2 -> V_6 = 0 ;
return 0 ;
}
void F_29 ( struct V_10 * V_11 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
F_14 ( V_2 -> V_2 , L_4 ) ;
switch ( V_19 -> V_39 ) {
case V_40 :
if ( ! V_19 -> V_28 ) {
V_2 -> V_6 = V_41 ;
F_30 ( V_2 ) ;
F_31 ( V_19 ) ;
return;
}
V_2 -> V_4 = V_5 ;
V_11 -> V_17 = NULL ;
if ( ! V_2 -> V_3 ) {
F_20 ( & V_19 -> V_25 , & V_11 -> V_42 ) ;
F_32 ( & V_11 -> V_32 ) ;
} else {
F_31 ( V_19 ) ;
}
break;
case V_20 :
if ( ! V_2 -> V_3 ) {
F_20 ( & V_19 -> V_25 , & V_11 -> V_42 ) ;
F_14 ( V_2 -> V_2 , L_5 ) ;
F_32 ( & V_11 -> V_32 ) ;
} else {
F_31 ( V_19 ) ;
}
V_2 -> V_6 = 0 ;
F_13 ( V_2 ) ;
break;
default:
F_33 ( 1 ) ;
}
}
static void F_34 ( const struct V_16 * V_16 ,
struct V_43 * V_44 )
{
struct V_18 * V_19 , * V_45 ;
F_35 (cb, next, mei_cb_list, list)
if ( V_16 == V_19 -> V_17 )
F_31 ( V_19 ) ;
}
int F_36 ( struct V_1 * V_2 , struct V_16 * V_16 )
{
struct V_10 * V_11 = V_16 -> V_30 ;
if ( V_2 -> V_7 > 0 )
V_2 -> V_7 -- ;
if ( V_11 -> V_17 == V_16 && V_2 -> V_4 != V_5 ) {
F_14 ( V_2 -> V_2 , L_6 ,
V_2 -> V_4 ) ;
V_2 -> V_3 = true ;
}
F_34 ( V_16 , & V_2 -> V_24 . V_25 ) ;
F_34 ( V_16 , & V_11 -> V_42 ) ;
F_34 ( V_16 , & V_2 -> V_46 . V_25 ) ;
return 0 ;
}
