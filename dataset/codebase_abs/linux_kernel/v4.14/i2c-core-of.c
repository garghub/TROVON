static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
struct V_7 V_8 = {} ;
struct V_9 V_10 = {} ;
const T_1 * V_11 ;
T_2 V_12 ;
int V_13 ;
F_2 ( & V_3 -> V_14 , L_1 , V_5 ) ;
if ( F_3 ( V_5 , V_8 . type , sizeof( V_8 . type ) ) < 0 ) {
F_4 ( & V_3 -> V_14 , L_2 ,
V_5 ) ;
return F_5 ( - V_15 ) ;
}
V_11 = F_6 ( V_5 , L_3 , & V_13 ) ;
if ( ! V_11 || ( V_13 < sizeof( * V_11 ) ) ) {
F_4 ( & V_3 -> V_14 , L_4 , V_5 ) ;
return F_5 ( - V_15 ) ;
}
V_12 = F_7 ( V_11 ) ;
if ( V_12 & V_16 ) {
V_12 &= ~ V_16 ;
V_8 . V_17 |= V_18 ;
}
if ( V_12 & V_19 ) {
V_12 &= ~ V_19 ;
V_8 . V_17 |= V_20 ;
}
if ( F_8 ( V_12 , V_8 . V_17 ) ) {
F_4 ( & V_3 -> V_14 , L_5 ,
V_12 , V_5 ) ;
return F_5 ( - V_15 ) ;
}
V_8 . V_12 = V_12 ;
V_8 . V_21 = F_9 ( V_5 ) ;
V_8 . V_22 = & V_10 ;
if ( F_10 ( V_5 , L_6 ) )
V_8 . V_17 |= V_23 ;
if ( F_6 ( V_5 , L_7 , NULL ) )
V_8 . V_17 |= V_24 ;
V_6 = F_11 ( V_3 , & V_8 ) ;
if ( V_6 == NULL ) {
F_4 ( & V_3 -> V_14 , L_8 , V_5 ) ;
F_12 ( V_5 ) ;
return F_5 ( - V_15 ) ;
}
return V_6 ;
}
void F_13 ( struct V_2 * V_3 )
{
struct V_4 * V_25 , * V_5 ;
struct V_1 * V_26 ;
if ( ! V_3 -> V_14 . V_21 )
return;
F_2 ( & V_3 -> V_14 , L_9 ) ;
V_25 = F_14 ( V_3 -> V_14 . V_21 , L_10 ) ;
if ( ! V_25 )
V_25 = F_9 ( V_3 -> V_14 . V_21 ) ;
F_15 (bus, node) {
if ( F_16 ( V_5 , V_27 ) )
continue;
V_26 = F_1 ( V_3 , V_5 ) ;
if ( F_17 ( V_26 ) ) {
F_18 ( & V_3 -> V_14 ,
L_11 ,
V_5 ) ;
F_19 ( V_5 , V_27 ) ;
}
}
F_12 ( V_25 ) ;
}
static int F_20 ( struct V_28 * V_14 , void * V_29 )
{
return V_14 -> V_21 == V_29 ;
}
struct V_1 * F_21 ( struct V_4 * V_5 )
{
struct V_28 * V_14 ;
struct V_1 * V_26 ;
V_14 = F_22 ( & V_30 , NULL , V_5 , F_20 ) ;
if ( ! V_14 )
return NULL ;
V_26 = F_23 ( V_14 ) ;
if ( ! V_26 )
F_24 ( V_14 ) ;
return V_26 ;
}
struct V_2 * F_25 ( struct V_4 * V_5 )
{
struct V_28 * V_14 ;
struct V_2 * V_31 ;
V_14 = F_22 ( & V_30 , NULL , V_5 , F_20 ) ;
if ( ! V_14 )
return NULL ;
V_31 = F_26 ( V_14 ) ;
if ( ! V_31 )
F_24 ( V_14 ) ;
return V_31 ;
}
struct V_2 * F_27 ( struct V_4 * V_5 )
{
struct V_2 * V_31 ;
V_31 = F_25 ( V_5 ) ;
if ( ! V_31 )
return NULL ;
if ( ! F_28 ( V_31 -> V_32 ) ) {
F_24 ( & V_31 -> V_14 ) ;
V_31 = NULL ;
}
return V_31 ;
}
static const struct V_33 *
F_29 ( const struct V_33 * V_34 ,
struct V_1 * V_26 )
{
const char * V_35 ;
for (; V_34 -> V_36 [ 0 ] ; V_34 ++ ) {
if ( F_30 ( V_26 -> V_35 , V_34 -> V_36 ) )
return V_34 ;
V_35 = strchr ( V_34 -> V_36 , ',' ) ;
if ( ! V_35 )
V_35 = V_34 -> V_36 ;
else
V_35 ++ ;
if ( F_30 ( V_26 -> V_35 , V_35 ) )
return V_34 ;
}
return NULL ;
}
const struct V_33
* F_31 ( const struct V_33 * V_34 ,
struct V_1 * V_26 )
{
const struct V_33 * V_37 ;
if ( ! ( V_26 && V_34 ) )
return NULL ;
V_37 = F_32 ( V_34 , & V_26 -> V_14 ) ;
if ( V_37 )
return V_37 ;
return F_29 ( V_34 , V_26 ) ;
}
static int F_33 ( struct V_38 * V_39 , unsigned long V_40 ,
void * V_41 )
{
struct V_42 * V_43 = V_41 ;
struct V_2 * V_3 ;
struct V_1 * V_26 ;
switch ( F_34 ( V_40 , V_43 ) ) {
case V_44 :
V_3 = F_25 ( V_43 -> V_45 -> V_46 ) ;
if ( V_3 == NULL )
return V_47 ;
if ( F_16 ( V_43 -> V_45 , V_27 ) ) {
F_24 ( & V_3 -> V_14 ) ;
return V_47 ;
}
V_26 = F_1 ( V_3 , V_43 -> V_45 ) ;
F_24 ( & V_3 -> V_14 ) ;
if ( F_17 ( V_26 ) ) {
F_4 ( & V_3 -> V_14 , L_12 ,
V_43 -> V_45 ) ;
F_19 ( V_43 -> V_45 , V_27 ) ;
return F_35 ( F_36 ( V_26 ) ) ;
}
break;
case V_48 :
if ( ! F_37 ( V_43 -> V_45 , V_27 ) )
return V_47 ;
V_26 = F_21 ( V_43 -> V_45 ) ;
if ( V_26 == NULL )
return V_47 ;
F_38 ( V_26 ) ;
F_24 ( & V_26 -> V_14 ) ;
break;
}
return V_47 ;
}
