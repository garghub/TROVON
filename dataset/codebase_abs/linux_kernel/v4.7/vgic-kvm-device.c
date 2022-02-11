static int F_1 ( struct V_1 * V_1 , T_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
if ( V_3 & ~ V_5 )
return - V_6 ;
if ( ! F_2 ( V_3 , V_4 ) )
return - V_7 ;
if ( ! F_3 ( * V_2 ) )
return - V_8 ;
return 0 ;
}
int F_4 ( struct V_1 * V_1 , unsigned long type , T_2 * V_3 , bool V_9 )
{
int V_10 = 0 ;
struct V_11 * V_12 = & V_1 -> V_13 . V_12 ;
int V_14 ;
T_1 * V_15 , V_4 ;
F_5 ( & V_1 -> V_16 ) ;
switch ( type ) {
case V_17 :
V_14 = V_18 ;
V_15 = & V_12 -> V_19 ;
V_4 = V_20 ;
break;
case V_21 :
V_14 = V_18 ;
V_15 = & V_12 -> V_22 ;
V_4 = V_20 ;
break;
#ifdef F_6
case V_23 :
V_14 = V_24 ;
V_15 = & V_12 -> V_19 ;
V_4 = V_25 ;
break;
case V_26 :
V_14 = V_24 ;
V_15 = & V_12 -> V_27 ;
V_4 = V_25 ;
break;
#endif
default:
V_10 = - V_28 ;
goto V_29;
}
if ( V_12 -> V_30 != V_14 ) {
V_10 = - V_28 ;
goto V_29;
}
if ( V_9 ) {
V_10 = F_1 ( V_1 , V_15 , * V_3 , V_4 ) ;
if ( ! V_10 )
* V_15 = * V_3 ;
} else {
* V_3 = * V_15 ;
}
V_29:
F_7 ( & V_1 -> V_16 ) ;
return V_10 ;
}
static int F_8 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_10 ;
switch ( V_34 -> V_35 ) {
case V_36 : {
T_2 T_3 * V_37 = ( T_2 T_3 * ) ( long ) V_34 -> V_3 ;
T_2 V_3 ;
unsigned long type = ( unsigned long ) V_34 -> V_34 ;
if ( F_9 ( & V_3 , V_37 , sizeof( V_3 ) ) )
return - V_38 ;
V_10 = F_4 ( V_32 -> V_1 , type , & V_3 , true ) ;
return ( V_10 == - V_28 ) ? - V_39 : V_10 ;
}
case V_40 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
T_4 V_41 ;
int V_42 = 0 ;
if ( F_10 ( V_41 , V_37 ) )
return - V_38 ;
if ( V_41 < ( V_43 + 32 ) ||
V_41 > V_44 ||
( V_41 & 31 ) )
return - V_7 ;
F_5 ( & V_32 -> V_1 -> V_16 ) ;
if ( F_11 ( V_32 -> V_1 ) || V_32 -> V_1 -> V_13 . V_12 . V_45 )
V_42 = - V_46 ;
else
V_32 -> V_1 -> V_13 . V_12 . V_45 =
V_41 - V_43 ;
F_7 ( & V_32 -> V_1 -> V_16 ) ;
return V_42 ;
}
case V_47 : {
switch ( V_34 -> V_34 ) {
case V_48 :
F_5 ( & V_32 -> V_1 -> V_16 ) ;
V_10 = F_12 ( V_32 -> V_1 ) ;
F_7 ( & V_32 -> V_1 -> V_16 ) ;
return V_10 ;
}
break;
}
}
return - V_39 ;
}
static int F_13 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_10 = - V_39 ;
switch ( V_34 -> V_35 ) {
case V_36 : {
T_2 T_3 * V_37 = ( T_2 T_3 * ) ( long ) V_34 -> V_3 ;
T_2 V_3 ;
unsigned long type = ( unsigned long ) V_34 -> V_34 ;
V_10 = F_4 ( V_32 -> V_1 , type , & V_3 , false ) ;
if ( V_10 )
return ( V_10 == - V_28 ) ? - V_39 : V_10 ;
if ( F_14 ( V_37 , & V_3 , sizeof( V_3 ) ) )
return - V_38 ;
break;
}
case V_40 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
V_10 = F_15 ( V_32 -> V_1 -> V_13 . V_12 . V_45 +
V_43 , V_37 ) ;
break;
}
}
return V_10 ;
}
static int F_16 ( struct V_31 * V_32 , T_4 type )
{
return F_17 ( V_32 -> V_1 , type ) ;
}
static void F_18 ( struct V_31 * V_32 )
{
F_19 ( V_32 ) ;
}
void F_20 ( unsigned long type )
{
switch ( type ) {
case V_18 :
F_21 ( & V_49 ,
V_18 ) ;
break;
#ifdef F_6
case V_24 :
F_21 ( & V_50 ,
V_24 ) ;
break;
#endif
}
}
static int F_22 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_4 * V_51 , bool V_52 )
{
T_5 V_3 ;
int V_53 , V_42 , V_54 ;
struct V_55 * V_56 , * V_57 ;
int V_58 = - 1 ;
V_53 = ( V_34 -> V_34 & V_59 ) >>
V_60 ;
V_56 = F_23 ( V_32 -> V_1 , V_53 ) ;
V_3 = V_34 -> V_34 & V_61 ;
F_5 ( & V_32 -> V_1 -> V_16 ) ;
V_42 = F_12 ( V_32 -> V_1 ) ;
if ( V_42 )
goto V_29;
if ( V_53 >= F_24 ( & V_32 -> V_1 -> V_62 ) ) {
V_42 = - V_7 ;
goto V_29;
}
V_42 = - V_46 ;
F_25 (c, tmp_vcpu, dev->kvm) {
if ( ! F_26 ( & V_57 -> V_63 ) )
goto V_29;
V_58 = V_54 ;
}
switch ( V_34 -> V_35 ) {
case V_64 :
V_42 = F_27 ( V_56 , V_52 , V_3 , V_51 ) ;
break;
case V_65 :
V_42 = F_28 ( V_56 , V_52 , V_3 , V_51 ) ;
break;
default:
V_42 = - V_7 ;
break;
}
V_29:
for (; V_58 >= 0 ; V_58 -- ) {
V_57 = F_23 ( V_32 -> V_1 , V_58 ) ;
F_7 ( & V_57 -> V_63 ) ;
}
F_7 ( & V_32 -> V_1 -> V_16 ) ;
return V_42 ;
}
static int F_29 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_42 ;
V_42 = F_8 ( V_32 , V_34 ) ;
if ( V_42 != - V_39 )
return V_42 ;
switch ( V_34 -> V_35 ) {
case V_65 :
case V_64 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
T_4 V_51 ;
if ( F_10 ( V_51 , V_37 ) )
return - V_38 ;
return F_22 ( V_32 , V_34 , & V_51 , true ) ;
}
}
return - V_39 ;
}
static int F_30 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_42 ;
V_42 = F_13 ( V_32 , V_34 ) ;
if ( V_42 != - V_39 )
return V_42 ;
switch ( V_34 -> V_35 ) {
case V_65 :
case V_64 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
T_4 V_51 = 0 ;
V_42 = F_22 ( V_32 , V_34 , & V_51 , false ) ;
if ( V_42 )
return V_42 ;
return F_15 ( V_51 , V_37 ) ;
}
}
return - V_39 ;
}
static int F_31 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
switch ( V_34 -> V_35 ) {
case V_36 :
switch ( V_34 -> V_34 ) {
case V_17 :
case V_21 :
return 0 ;
}
break;
case V_65 :
case V_64 :
return F_32 ( V_32 , V_34 ) ;
case V_40 :
return 0 ;
case V_47 :
switch ( V_34 -> V_34 ) {
case V_48 :
return 0 ;
}
}
return - V_39 ;
}
static int F_33 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
return F_8 ( V_32 , V_34 ) ;
}
static int F_34 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
return F_13 ( V_32 , V_34 ) ;
}
static int F_35 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
switch ( V_34 -> V_35 ) {
case V_36 :
switch ( V_34 -> V_34 ) {
case V_23 :
case V_26 :
return 0 ;
}
break;
case V_40 :
return 0 ;
case V_47 :
switch ( V_34 -> V_34 ) {
case V_48 :
return 0 ;
}
}
return - V_39 ;
}
