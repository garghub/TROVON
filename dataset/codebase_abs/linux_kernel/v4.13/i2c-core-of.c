static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
struct V_7 V_8 = {} ;
struct V_9 V_10 = {} ;
const T_1 * V_11 ;
T_2 V_12 ;
int V_13 ;
F_2 ( & V_3 -> V_14 , L_1 , V_5 -> V_15 ) ;
if ( F_3 ( V_5 , V_8 . type , sizeof( V_8 . type ) ) < 0 ) {
F_4 ( & V_3 -> V_14 , L_2 ,
V_5 -> V_15 ) ;
return F_5 ( - V_16 ) ;
}
V_11 = F_6 ( V_5 , L_3 , & V_13 ) ;
if ( ! V_11 || ( V_13 < sizeof( * V_11 ) ) ) {
F_4 ( & V_3 -> V_14 , L_4 ,
V_5 -> V_15 ) ;
return F_5 ( - V_16 ) ;
}
V_12 = F_7 ( V_11 ) ;
if ( V_12 & V_17 ) {
V_12 &= ~ V_17 ;
V_8 . V_18 |= V_19 ;
}
if ( V_12 & V_20 ) {
V_12 &= ~ V_20 ;
V_8 . V_18 |= V_21 ;
}
if ( F_8 ( V_12 , V_8 . V_18 ) ) {
F_4 ( & V_3 -> V_14 , L_5 ,
V_12 , V_5 -> V_15 ) ;
return F_5 ( - V_16 ) ;
}
V_8 . V_12 = V_12 ;
V_8 . V_22 = F_9 ( V_5 ) ;
V_8 . V_23 = & V_10 ;
if ( F_10 ( V_5 , L_6 ) )
V_8 . V_18 |= V_24 ;
if ( F_6 ( V_5 , L_7 , NULL ) )
V_8 . V_18 |= V_25 ;
V_6 = F_11 ( V_3 , & V_8 ) ;
if ( V_6 == NULL ) {
F_4 ( & V_3 -> V_14 , L_8 ,
V_5 -> V_15 ) ;
F_12 ( V_5 ) ;
return F_5 ( - V_16 ) ;
}
return V_6 ;
}
void F_13 ( struct V_2 * V_3 )
{
struct V_4 * V_26 , * V_5 ;
struct V_1 * V_27 ;
if ( ! V_3 -> V_14 . V_22 )
return;
F_2 ( & V_3 -> V_14 , L_9 ) ;
V_26 = F_14 ( V_3 -> V_14 . V_22 , L_10 ) ;
if ( ! V_26 )
V_26 = F_9 ( V_3 -> V_14 . V_22 ) ;
F_15 (bus, node) {
if ( F_16 ( V_5 , V_28 ) )
continue;
V_27 = F_1 ( V_3 , V_5 ) ;
if ( F_17 ( V_27 ) ) {
F_18 ( & V_3 -> V_14 ,
L_11 ,
V_5 -> V_15 ) ;
F_19 ( V_5 , V_28 ) ;
}
}
F_12 ( V_26 ) ;
}
static int F_20 ( struct V_29 * V_14 , void * V_30 )
{
return V_14 -> V_22 == V_30 ;
}
struct V_1 * F_21 ( struct V_4 * V_5 )
{
struct V_29 * V_14 ;
struct V_1 * V_27 ;
V_14 = F_22 ( & V_31 , NULL , V_5 , F_20 ) ;
if ( ! V_14 )
return NULL ;
V_27 = F_23 ( V_14 ) ;
if ( ! V_27 )
F_24 ( V_14 ) ;
return V_27 ;
}
struct V_2 * F_25 ( struct V_4 * V_5 )
{
struct V_29 * V_14 ;
struct V_2 * V_32 ;
V_14 = F_22 ( & V_31 , NULL , V_5 , F_20 ) ;
if ( ! V_14 )
return NULL ;
V_32 = F_26 ( V_14 ) ;
if ( ! V_32 )
F_24 ( V_14 ) ;
return V_32 ;
}
struct V_2 * F_27 ( struct V_4 * V_5 )
{
struct V_2 * V_32 ;
V_32 = F_25 ( V_5 ) ;
if ( ! V_32 )
return NULL ;
if ( ! F_28 ( V_32 -> V_33 ) ) {
F_24 ( & V_32 -> V_14 ) ;
V_32 = NULL ;
}
return V_32 ;
}
static const struct V_34 *
F_29 ( const struct V_34 * V_35 ,
struct V_1 * V_27 )
{
const char * V_36 ;
for (; V_35 -> V_37 [ 0 ] ; V_35 ++ ) {
if ( F_30 ( V_27 -> V_36 , V_35 -> V_37 ) )
return V_35 ;
V_36 = strchr ( V_35 -> V_37 , ',' ) ;
if ( ! V_36 )
V_36 = V_35 -> V_37 ;
else
V_36 ++ ;
if ( F_30 ( V_27 -> V_36 , V_36 ) )
return V_35 ;
}
return NULL ;
}
const struct V_34
* F_31 ( const struct V_34 * V_35 ,
struct V_1 * V_27 )
{
const struct V_34 * V_38 ;
if ( ! ( V_27 && V_35 ) )
return NULL ;
V_38 = F_32 ( V_35 , & V_27 -> V_14 ) ;
if ( V_38 )
return V_38 ;
return F_29 ( V_35 , V_27 ) ;
}
static int F_33 ( struct V_39 * V_40 , unsigned long V_41 ,
void * V_42 )
{
struct V_43 * V_44 = V_42 ;
struct V_2 * V_3 ;
struct V_1 * V_27 ;
switch ( F_34 ( V_41 , V_44 ) ) {
case V_45 :
V_3 = F_25 ( V_44 -> V_46 -> V_47 ) ;
if ( V_3 == NULL )
return V_48 ;
if ( F_16 ( V_44 -> V_46 , V_28 ) ) {
F_24 ( & V_3 -> V_14 ) ;
return V_48 ;
}
V_27 = F_1 ( V_3 , V_44 -> V_46 ) ;
F_24 ( & V_3 -> V_14 ) ;
if ( F_17 ( V_27 ) ) {
F_4 ( & V_3 -> V_14 , L_12 ,
V_44 -> V_46 -> V_15 ) ;
F_19 ( V_44 -> V_46 , V_28 ) ;
return F_35 ( F_36 ( V_27 ) ) ;
}
break;
case V_49 :
if ( ! F_37 ( V_44 -> V_46 , V_28 ) )
return V_48 ;
V_27 = F_21 ( V_44 -> V_46 ) ;
if ( V_27 == NULL )
return V_48 ;
F_38 ( V_27 ) ;
F_24 ( & V_27 -> V_14 ) ;
break;
}
return V_48 ;
}
