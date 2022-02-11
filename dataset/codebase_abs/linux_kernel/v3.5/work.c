static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned long V_4 )
{
F_1 ( V_2 ) ;
if ( ! F_4 ( & V_2 -> V_5 ) ||
F_5 ( V_4 , V_2 -> V_5 . V_6 ) )
F_6 ( & V_2 -> V_5 , V_4 ) ;
}
void F_7 ( struct V_7 * V_8 )
{
F_8 ( V_8 , V_9 ) ;
}
static enum V_10 T_1
F_9 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_11 ) {
V_8 -> V_4 = V_12 + F_10 ( V_8 -> V_13 . V_14 ) ;
F_11 ( V_8 -> V_15 -> V_16 , ( unsigned long ) V_8 ,
V_8 -> V_17 , V_8 -> V_18 ,
V_8 -> V_13 . V_14 , V_19 ) ;
return V_20 ;
}
return V_21 ;
}
static enum V_10 T_1
F_12 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_11 ) {
V_8 -> V_4 = V_12 + F_10 ( V_8 -> V_22 . V_23 ) ;
F_13 ( V_8 -> V_15 , V_8 -> V_22 . V_24 ) ;
return V_20 ;
}
return V_21 ;
}
static void F_14 ( unsigned long V_25 )
{
struct V_1 * V_2 = ( void * ) V_25 ;
if ( V_2 -> V_26 )
return;
F_15 ( & V_2 -> V_27 , & V_2 -> V_28 ) ;
}
static void F_16 ( struct V_29 * V_30 )
{
struct V_1 * V_2 =
F_17 ( V_30 , struct V_1 , V_28 ) ;
struct V_7 * V_8 , * V_31 ;
F_18 ( F_7 ) ;
enum V_10 V_32 ;
bool V_33 = false ;
if ( F_19 ( V_2 -> V_34 , L_1 ) )
return;
F_20 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_35 ) {
F_21 ( & V_2 -> V_3 ) ;
return;
}
F_22 ( V_2 ) ;
F_23 (wk, tmp, &local->work_list, list) {
bool V_11 = V_8 -> V_11 ;
if ( ! V_11 && V_2 -> V_36 &&
V_8 -> V_17 == V_2 -> V_36 &&
V_8 -> V_18 == V_2 -> V_37 ) {
V_11 = true ;
V_8 -> V_4 = V_12 ;
}
if ( ! V_11 && ! V_2 -> V_36 ) {
F_24 ( V_2 , true ) ;
V_2 -> V_36 = V_8 -> V_17 ;
V_2 -> V_37 = V_8 -> V_18 ;
F_25 ( V_2 , 0 ) ;
V_11 = true ;
V_8 -> V_4 = V_12 ;
}
if ( ! V_11 )
continue;
if ( F_26 ( V_8 -> V_4 ) ) {
F_3 ( V_2 , V_8 -> V_4 ) ;
continue;
}
switch ( V_8 -> type ) {
default:
F_27 ( 1 ) ;
V_32 = V_20 ;
break;
case V_38 :
V_32 = V_21 ;
break;
case V_39 :
V_32 = F_9 ( V_8 ) ;
break;
case V_40 :
V_32 = F_12 ( V_8 ) ;
break;
}
V_8 -> V_11 = V_11 ;
switch ( V_32 ) {
case V_20 :
F_3 ( V_2 , V_8 -> V_4 ) ;
break;
case V_21 :
F_28 ( & V_8 -> V_41 ) ;
F_29 () ;
F_30 ( & V_8 -> V_41 , & F_7 ) ;
break;
default:
F_19 ( 1 , L_2 , V_32 ) ;
}
}
F_31 (wk, &local->work_list, list) {
if ( ! V_8 -> V_11 )
continue;
if ( V_8 -> V_17 != V_2 -> V_36 ||
V_8 -> V_18 != V_2 -> V_37 )
continue;
V_33 = true ;
}
if ( ! V_33 && V_2 -> V_36 ) {
V_2 -> V_36 = NULL ;
F_25 ( V_2 , 0 ) ;
F_32 ( V_2 , true ) ;
F_3 ( V_2 , V_12 + V_42 / 2 ) ;
}
F_22 ( V_2 ) ;
F_33 ( V_2 ) ;
F_21 ( & V_2 -> V_3 ) ;
F_23 (wk, tmp, &free_work, list) {
V_8 -> V_43 ( V_8 , NULL ) ;
F_34 ( & V_8 -> V_41 ) ;
F_35 ( V_8 ) ;
}
}
void F_36 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
if ( F_27 ( ! V_8 -> V_17 ) )
return;
if ( F_27 ( ! V_8 -> V_15 ) )
return;
if ( F_27 ( ! V_8 -> V_43 ) )
return;
if ( F_27 ( ! F_37 ( V_8 -> V_15 ) ) )
return;
V_8 -> V_11 = false ;
V_2 = V_8 -> V_15 -> V_2 ;
F_20 ( & V_2 -> V_3 ) ;
F_38 ( & V_8 -> V_41 , & V_2 -> V_44 ) ;
F_21 ( & V_2 -> V_3 ) ;
F_15 ( & V_2 -> V_27 , & V_2 -> V_28 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_44 ) ;
F_41 ( & V_2 -> V_5 , F_14 ,
( unsigned long ) V_2 ) ;
F_42 ( & V_2 -> V_28 , F_16 ) ;
}
void F_43 ( struct V_45 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_7 * V_8 ;
bool V_46 = false ;
F_20 ( & V_2 -> V_3 ) ;
F_31 (wk, &local->work_list, list) {
if ( V_8 -> V_15 != V_15 )
continue;
V_46 = true ;
V_8 -> type = V_38 ;
V_8 -> V_11 = true ;
V_8 -> V_4 = V_12 ;
}
F_21 ( & V_2 -> V_3 ) ;
if ( V_46 )
F_16 ( & V_2 -> V_28 ) ;
F_20 ( & V_2 -> V_3 ) ;
F_31 (wk, &local->work_list, list) {
if ( V_8 -> V_15 != V_15 )
continue;
F_27 ( 1 ) ;
break;
}
F_21 ( & V_2 -> V_3 ) ;
}
static enum V_47 F_44 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
F_45 ( V_8 -> V_15 -> V_16 , ( unsigned long ) V_8 ,
V_8 -> V_17 , V_8 -> V_18 ,
V_19 ) ;
return V_50 ;
}
int F_46 ( struct V_45 * V_15 ,
struct V_51 * V_17 ,
enum V_52 V_53 ,
unsigned int V_14 , T_2 * V_54 )
{
struct V_7 * V_8 ;
V_8 = F_47 ( sizeof( * V_8 ) , V_19 ) ;
if ( ! V_8 )
return - V_55 ;
V_8 -> type = V_39 ;
V_8 -> V_17 = V_17 ;
V_8 -> V_18 = V_53 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_43 = F_44 ;
V_8 -> V_13 . V_14 = V_14 ;
* V_54 = ( unsigned long ) V_8 ;
F_36 ( V_8 ) ;
return 0 ;
}
int F_48 ( struct V_45 * V_15 ,
T_2 V_54 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_7 * V_8 , * V_31 ;
bool V_56 = false ;
F_20 ( & V_2 -> V_3 ) ;
F_23 (wk, tmp, &local->work_list, list) {
if ( ( unsigned long ) V_8 == V_54 ) {
V_8 -> V_4 = V_12 ;
V_56 = true ;
break;
}
}
F_21 ( & V_2 -> V_3 ) ;
if ( ! V_56 )
return - V_57 ;
F_15 ( & V_2 -> V_27 , & V_2 -> V_28 ) ;
return 0 ;
}
