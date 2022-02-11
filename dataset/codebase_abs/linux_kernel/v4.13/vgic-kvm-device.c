int F_1 ( struct V_1 * V_1 , T_1 * V_2 ,
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
static int F_4 ( struct V_1 * V_1 , int V_9 )
{
if ( V_1 -> V_10 . V_11 . V_12 != V_9 )
return - V_13 ;
else
return 0 ;
}
int F_5 ( struct V_1 * V_1 , unsigned long type , T_2 * V_3 , bool V_14 )
{
int V_15 = 0 ;
struct V_16 * V_11 = & V_1 -> V_10 . V_11 ;
T_1 * V_17 , V_4 ;
F_6 ( & V_1 -> V_18 ) ;
switch ( type ) {
case V_19 :
V_15 = F_4 ( V_1 , V_20 ) ;
V_17 = & V_11 -> V_21 ;
V_4 = V_22 ;
break;
case V_23 :
V_15 = F_4 ( V_1 , V_20 ) ;
V_17 = & V_11 -> V_24 ;
V_4 = V_22 ;
break;
case V_25 :
V_15 = F_4 ( V_1 , V_26 ) ;
V_17 = & V_11 -> V_21 ;
V_4 = V_27 ;
break;
case V_28 :
V_15 = F_4 ( V_1 , V_26 ) ;
if ( V_15 )
break;
if ( V_14 ) {
V_15 = F_7 ( V_1 , * V_3 ) ;
goto V_29;
}
V_17 = & V_11 -> V_30 ;
break;
default:
V_15 = - V_13 ;
}
if ( V_15 )
goto V_29;
if ( V_14 ) {
V_15 = F_1 ( V_1 , V_17 , * V_3 , V_4 ) ;
if ( ! V_15 )
* V_17 = * V_3 ;
} else {
* V_3 = * V_17 ;
}
V_29:
F_8 ( & V_1 -> V_18 ) ;
return V_15 ;
}
static int F_9 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_15 ;
switch ( V_34 -> V_35 ) {
case V_36 : {
T_2 T_3 * V_37 = ( T_2 T_3 * ) ( long ) V_34 -> V_3 ;
T_2 V_3 ;
unsigned long type = ( unsigned long ) V_34 -> V_34 ;
if ( F_10 ( & V_3 , V_37 , sizeof( V_3 ) ) )
return - V_38 ;
V_15 = F_5 ( V_32 -> V_1 , type , & V_3 , true ) ;
return ( V_15 == - V_13 ) ? - V_39 : V_15 ;
}
case V_40 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
T_4 V_41 ;
int V_42 = 0 ;
if ( F_11 ( V_41 , V_37 ) )
return - V_38 ;
if ( V_41 < ( V_43 + 32 ) ||
V_41 > V_44 ||
( V_41 & 31 ) )
return - V_7 ;
F_6 ( & V_32 -> V_1 -> V_18 ) ;
if ( F_12 ( V_32 -> V_1 ) || V_32 -> V_1 -> V_10 . V_11 . V_45 )
V_42 = - V_46 ;
else
V_32 -> V_1 -> V_10 . V_11 . V_45 =
V_41 - V_43 ;
F_8 ( & V_32 -> V_1 -> V_18 ) ;
return V_42 ;
}
case V_47 : {
switch ( V_34 -> V_34 ) {
case V_48 :
F_6 ( & V_32 -> V_1 -> V_18 ) ;
V_15 = F_13 ( V_32 -> V_1 ) ;
F_8 ( & V_32 -> V_1 -> V_18 ) ;
return V_15 ;
}
break;
}
}
return - V_39 ;
}
static int F_14 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_15 = - V_39 ;
switch ( V_34 -> V_35 ) {
case V_36 : {
T_2 T_3 * V_37 = ( T_2 T_3 * ) ( long ) V_34 -> V_3 ;
T_2 V_3 ;
unsigned long type = ( unsigned long ) V_34 -> V_34 ;
V_15 = F_5 ( V_32 -> V_1 , type , & V_3 , false ) ;
if ( V_15 )
return ( V_15 == - V_13 ) ? - V_39 : V_15 ;
if ( F_15 ( V_37 , & V_3 , sizeof( V_3 ) ) )
return - V_38 ;
break;
}
case V_40 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
V_15 = F_16 ( V_32 -> V_1 -> V_10 . V_11 . V_45 +
V_43 , V_37 ) ;
break;
}
}
return V_15 ;
}
static int F_17 ( struct V_31 * V_32 , T_4 type )
{
return F_18 ( V_32 -> V_1 , type ) ;
}
static void F_19 ( struct V_31 * V_32 )
{
F_20 ( V_32 ) ;
}
int F_21 ( unsigned long type )
{
int V_42 = - V_13 ;
switch ( type ) {
case V_20 :
V_42 = F_22 ( & V_49 ,
V_20 ) ;
break;
case V_26 :
V_42 = F_22 ( & V_50 ,
V_26 ) ;
if ( V_42 )
break;
V_42 = F_23 () ;
break;
}
return V_42 ;
}
int F_24 ( struct V_31 * V_32 , struct V_33 * V_34 ,
struct V_51 * V_52 )
{
int V_53 ;
V_53 = ( V_34 -> V_34 & V_54 ) >>
V_55 ;
if ( V_53 >= F_25 ( & V_32 -> V_1 -> V_56 ) )
return - V_7 ;
V_52 -> V_57 = F_26 ( V_32 -> V_1 , V_53 ) ;
V_52 -> V_3 = V_34 -> V_34 & V_58 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_1 , int V_59 )
{
struct V_60 * V_61 ;
for (; V_59 >= 0 ; V_59 -- ) {
V_61 = F_26 ( V_1 , V_59 ) ;
F_8 ( & V_61 -> V_62 ) ;
}
}
void F_28 ( struct V_1 * V_1 )
{
F_27 ( V_1 , F_25 ( & V_1 -> V_56 ) - 1 ) ;
}
bool F_29 ( struct V_1 * V_1 )
{
struct V_60 * V_61 ;
int V_63 ;
F_30 (c, tmp_vcpu, kvm) {
if ( ! F_31 ( & V_61 -> V_62 ) ) {
F_27 ( V_1 , V_63 - 1 ) ;
return false ;
}
}
return true ;
}
static int F_32 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_4 * V_64 , bool V_65 )
{
struct V_51 V_52 ;
T_5 V_3 ;
struct V_60 * V_57 ;
int V_42 ;
V_42 = F_24 ( V_32 , V_34 , & V_52 ) ;
if ( V_42 )
return V_42 ;
V_57 = V_52 . V_57 ;
V_3 = V_52 . V_3 ;
F_6 ( & V_32 -> V_1 -> V_18 ) ;
V_42 = F_13 ( V_32 -> V_1 ) ;
if ( V_42 )
goto V_29;
if ( ! F_29 ( V_32 -> V_1 ) ) {
V_42 = - V_46 ;
goto V_29;
}
switch ( V_34 -> V_35 ) {
case V_66 :
V_42 = F_33 ( V_57 , V_65 , V_3 , V_64 ) ;
break;
case V_67 :
V_42 = F_34 ( V_57 , V_65 , V_3 , V_64 ) ;
break;
default:
V_42 = - V_7 ;
break;
}
F_28 ( V_32 -> V_1 ) ;
V_29:
F_8 ( & V_32 -> V_1 -> V_18 ) ;
return V_42 ;
}
static int F_35 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_42 ;
V_42 = F_9 ( V_32 , V_34 ) ;
if ( V_42 != - V_39 )
return V_42 ;
switch ( V_34 -> V_35 ) {
case V_67 :
case V_66 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
T_4 V_64 ;
if ( F_11 ( V_64 , V_37 ) )
return - V_38 ;
return F_32 ( V_32 , V_34 , & V_64 , true ) ;
}
}
return - V_39 ;
}
static int F_36 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_42 ;
V_42 = F_14 ( V_32 , V_34 ) ;
if ( V_42 != - V_39 )
return V_42 ;
switch ( V_34 -> V_35 ) {
case V_67 :
case V_66 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
T_4 V_64 = 0 ;
V_42 = F_32 ( V_32 , V_34 , & V_64 , false ) ;
if ( V_42 )
return V_42 ;
return F_16 ( V_64 , V_37 ) ;
}
}
return - V_39 ;
}
static int F_37 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
switch ( V_34 -> V_35 ) {
case V_36 :
switch ( V_34 -> V_34 ) {
case V_19 :
case V_23 :
return 0 ;
}
break;
case V_67 :
case V_66 :
return F_38 ( V_32 , V_34 ) ;
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
int F_39 ( struct V_31 * V_32 , struct V_33 * V_34 ,
struct V_51 * V_52 )
{
unsigned long V_68 , V_69 ;
if ( V_34 -> V_35 != V_67 ) {
V_68 = ( V_34 -> V_34 & V_70 ) >>
V_71 ;
V_69 = F_40 ( V_68 ) ;
V_52 -> V_57 = F_41 ( V_32 -> V_1 , V_69 ) ;
} else {
V_52 -> V_57 = F_26 ( V_32 -> V_1 , 0 ) ;
}
if ( ! V_52 -> V_57 )
return - V_7 ;
V_52 -> V_3 = V_34 -> V_34 & V_58 ;
return 0 ;
}
static int F_42 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
T_2 * V_64 , bool V_65 )
{
struct V_51 V_52 ;
T_5 V_3 ;
struct V_60 * V_57 ;
int V_42 ;
T_4 V_72 ;
V_42 = F_39 ( V_32 , V_34 , & V_52 ) ;
if ( V_42 )
return V_42 ;
V_57 = V_52 . V_57 ;
V_3 = V_52 . V_3 ;
F_6 ( & V_32 -> V_1 -> V_18 ) ;
if ( F_43 ( ! F_44 ( V_32 -> V_1 ) ) ) {
V_42 = - V_46 ;
goto V_29;
}
if ( ! F_29 ( V_32 -> V_1 ) ) {
V_42 = - V_46 ;
goto V_29;
}
switch ( V_34 -> V_35 ) {
case V_67 :
if ( V_65 )
V_72 = * V_64 ;
V_42 = F_45 ( V_57 , V_65 , V_3 , & V_72 ) ;
if ( ! V_65 )
* V_64 = V_72 ;
break;
case V_73 :
if ( V_65 )
V_72 = * V_64 ;
V_42 = F_46 ( V_57 , V_65 , V_3 , & V_72 ) ;
if ( ! V_65 )
* V_64 = V_72 ;
break;
case V_74 : {
T_2 V_75 ;
V_75 = ( V_34 -> V_34 & V_76 ) ;
V_42 = F_47 ( V_57 , V_65 ,
V_75 , V_64 ) ;
break;
}
case V_77 : {
unsigned int V_78 , V_79 ;
V_78 = ( V_34 -> V_34 & V_80 ) >>
V_81 ;
if ( V_78 == V_82 ) {
V_79 = V_34 -> V_34 &
V_83 ;
V_42 = F_48 ( V_57 , V_65 ,
V_79 , V_64 ) ;
} else {
V_42 = - V_7 ;
}
break;
}
default:
V_42 = - V_7 ;
break;
}
F_28 ( V_32 -> V_1 ) ;
V_29:
F_8 ( & V_32 -> V_1 -> V_18 ) ;
return V_42 ;
}
static int F_49 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_42 ;
V_42 = F_9 ( V_32 , V_34 ) ;
if ( V_42 != - V_39 )
return V_42 ;
switch ( V_34 -> V_35 ) {
case V_67 :
case V_73 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
T_4 V_72 ;
T_2 V_64 ;
if ( F_11 ( V_72 , V_37 ) )
return - V_38 ;
V_64 = V_72 ;
return F_42 ( V_32 , V_34 , & V_64 , true ) ;
}
case V_74 : {
T_2 T_3 * V_37 = ( T_2 T_3 * ) ( long ) V_34 -> V_3 ;
T_2 V_64 ;
if ( F_11 ( V_64 , V_37 ) )
return - V_38 ;
return F_42 ( V_32 , V_34 , & V_64 , true ) ;
}
case V_77 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
T_2 V_64 ;
T_4 V_72 ;
if ( F_11 ( V_72 , V_37 ) )
return - V_38 ;
V_64 = V_72 ;
return F_42 ( V_32 , V_34 , & V_64 , true ) ;
}
case V_47 : {
int V_42 ;
switch ( V_34 -> V_34 ) {
case V_84 :
F_6 ( & V_32 -> V_1 -> V_18 ) ;
if ( ! F_29 ( V_32 -> V_1 ) ) {
F_8 ( & V_32 -> V_1 -> V_18 ) ;
return - V_46 ;
}
V_42 = F_50 ( V_32 -> V_1 ) ;
F_28 ( V_32 -> V_1 ) ;
F_8 ( & V_32 -> V_1 -> V_18 ) ;
return V_42 ;
}
break;
}
}
return - V_39 ;
}
static int F_51 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_42 ;
V_42 = F_14 ( V_32 , V_34 ) ;
if ( V_42 != - V_39 )
return V_42 ;
switch ( V_34 -> V_35 ) {
case V_67 :
case V_73 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
T_2 V_64 ;
T_4 V_72 ;
V_42 = F_42 ( V_32 , V_34 , & V_64 , false ) ;
if ( V_42 )
return V_42 ;
V_72 = V_64 ;
return F_16 ( V_72 , V_37 ) ;
}
case V_74 : {
T_2 T_3 * V_37 = ( T_2 T_3 * ) ( long ) V_34 -> V_3 ;
T_2 V_64 ;
V_42 = F_42 ( V_32 , V_34 , & V_64 , false ) ;
if ( V_42 )
return V_42 ;
return F_16 ( V_64 , V_37 ) ;
}
case V_77 : {
T_4 T_3 * V_37 = ( T_4 T_3 * ) ( long ) V_34 -> V_3 ;
T_2 V_64 ;
T_4 V_72 ;
V_42 = F_42 ( V_32 , V_34 , & V_64 , false ) ;
if ( V_42 )
return V_42 ;
V_72 = V_64 ;
return F_16 ( V_72 , V_37 ) ;
}
}
return - V_39 ;
}
static int F_52 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
switch ( V_34 -> V_35 ) {
case V_36 :
switch ( V_34 -> V_34 ) {
case V_25 :
case V_28 :
return 0 ;
}
break;
case V_67 :
case V_73 :
case V_74 :
return F_53 ( V_32 , V_34 ) ;
case V_40 :
return 0 ;
case V_77 : {
if ( ( ( V_34 -> V_34 & V_80 ) >>
V_81 ) ==
V_82 )
return 0 ;
break;
}
case V_47 :
switch ( V_34 -> V_34 ) {
case V_48 :
return 0 ;
case V_84 :
return 0 ;
}
}
return - V_39 ;
}
