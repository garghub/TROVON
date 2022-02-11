static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
if ( V_2 -> V_6 != 0 )
F_4 ( V_5 -> V_7 , V_2 -> V_8 + 4 , V_2 -> V_9 ,
V_2 -> V_6 ) ;
V_2 -> V_9 = NULL ;
V_2 -> V_6 = 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
V_2 -> V_9 = NULL ;
V_2 -> V_6 = 0 ;
V_2 -> V_8 = V_10 * 8 ;
V_2 -> V_11 = V_2 -> V_8 - 8 ;
V_2 -> V_12 = 0 ;
V_2 -> V_9 = F_6 ( V_5 -> V_7 , V_2 -> V_8 + 4 , & V_2 -> V_6 ,
V_13 ) ;
if ( ! V_2 -> V_9 )
goto V_14;
F_7 ( V_5 , V_2 ) ;
return 0 ;
V_14:
F_1 ( V_2 ) ;
return - V_15 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 )
{
T_1 * V_18 = ( T_1 * ) ( ( void * ) V_2 -> V_9 + V_2 -> V_12 ) ;
F_9 ( V_2 -> V_12 == V_2 -> V_11 ) ;
* ( V_18 ++ ) = V_16 ;
* ( V_18 ++ ) = V_17 ;
V_2 -> V_12 = ( V_2 -> V_12 + 8 ) & ( V_2 -> V_8 - 1 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_19 )
{
V_2 -> V_11 = ( V_2 -> V_11 + V_19 * 8 ) & ( V_2 -> V_8 - 1 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_11 - V_2 -> V_12 ) & ( V_2 -> V_8 - 1 ) ) / 8 ;
}
unsigned int F_12 ( struct V_3 * V_4 ,
enum V_20 V_21 )
{
for (; ; ) {
struct V_1 * V_2 = & V_4 -> V_1 ;
unsigned int V_22 ;
switch ( V_21 ) {
case V_23 :
V_22 = F_13 ( & V_4 -> V_24 ) ? 1 : 0 ;
break;
case V_25 :
V_22 = F_11 ( V_2 ) ;
break;
default:
F_9 ( 1 ) ;
return - V_26 ;
}
if ( V_22 )
return V_22 ;
F_14 ( F_15 ( F_16 ( V_4 ) -> V_7 ) ,
V_21 ) ;
if ( V_4 -> V_21 != V_27 ) {
F_17 ( & V_4 -> V_28 ) ;
F_18 () ;
F_19 ( & V_4 -> V_28 ) ;
continue;
}
V_4 -> V_21 = V_21 ;
F_17 ( & V_4 -> V_28 ) ;
F_20 ( & V_4 -> V_29 ) ;
F_19 ( & V_4 -> V_28 ) ;
}
return 0 ;
}
static void F_21 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
struct V_5 * V_32 = F_3 ( V_4 ) ;
if ( V_4 -> V_33 . V_34 ) {
return;
}
V_4 -> V_33 . V_34 = V_31 -> V_34 ;
V_4 -> V_33 . V_35 = F_22 ( V_32 , V_31 -> V_36 ) ;
V_4 -> V_33 . V_37 = V_31 -> V_38 ;
V_4 -> V_33 . V_39 = F_23 () ;
F_24 ( & V_4 -> V_33 . V_40 ,
F_25 ( V_31 -> V_33 ) ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
F_27 ( & V_4 -> V_33 . V_40 ) ;
V_4 -> V_33 . V_34 = 0 ;
}
static void F_28 ( struct V_3 * V_4 )
{
bool signal = false ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
struct V_30 * V_31 , * V_41 ;
if ( ! V_4 -> V_42 )
return;
F_29 (job, n, &cdma->sync_queue, list) {
struct V_43 * V_44 =
F_22 ( V_5 , V_31 -> V_36 ) ;
if ( ! F_30 ( V_44 , V_31 -> V_38 ) ) {
if ( V_31 -> V_33 )
F_21 ( V_4 , V_31 ) ;
break;
}
if ( V_4 -> V_33 . V_34 )
F_26 ( V_4 ) ;
F_31 ( V_31 ) ;
if ( V_31 -> V_45 ) {
struct V_1 * V_2 = & V_4 -> V_1 ;
F_10 ( V_2 , V_31 -> V_45 ) ;
if ( V_4 -> V_21 == V_25 )
signal = true ;
}
F_32 ( & V_31 -> V_46 ) ;
F_33 ( V_31 ) ;
}
if ( V_4 -> V_21 == V_23 &&
F_13 ( & V_4 -> V_24 ) )
signal = true ;
if ( signal ) {
V_4 -> V_21 = V_27 ;
F_34 ( & V_4 -> V_29 ) ;
}
}
void F_35 ( struct V_3 * V_4 ,
struct V_47 * V_7 )
{
struct V_5 * V_5 = F_3 ( V_4 ) ;
T_1 V_48 , V_49 , V_37 ;
struct V_30 * V_31 = NULL ;
V_37 = F_36 ( V_4 -> V_33 . V_35 ) ;
F_37 ( V_7 , L_1 ,
V_50 , V_37 ) ;
F_37 ( V_7 , L_2 ,
V_50 ) ;
F_38 (job, &cdma->sync_queue, list) {
if ( V_37 < V_31 -> V_38 )
break;
F_39 ( V_7 , V_31 ) ;
}
F_37 ( V_7 , L_3 ,
V_50 ) ;
if ( ! F_13 ( & V_4 -> V_24 ) )
V_48 = V_31 -> V_51 ;
else
V_48 = V_4 -> V_52 ;
F_40 (job, &cdma->sync_queue, list) {
if ( V_31 -> V_34 != V_4 -> V_33 . V_34 )
break;
V_31 -> V_33 = 0 ;
V_49 = V_31 -> V_38 - V_37 ;
F_37 ( V_7 , L_4 , V_50 , V_49 ) ;
F_39 ( V_7 , V_31 ) ;
F_41 ( V_5 , V_4 , V_31 -> V_51 ,
V_49 , V_31 -> V_38 ,
V_31 -> V_45 ) ;
V_37 += V_49 ;
}
F_40 (job, &cdma->sync_queue, list)
if ( V_31 -> V_34 == V_4 -> V_33 . V_34 )
V_31 -> V_33 = F_42 (unsigned int, job->timeout, 500 ) ;
F_37 ( V_7 , L_5 , V_50 ) ;
F_43 ( V_5 , V_4 , V_48 ) ;
}
int F_44 ( struct V_3 * V_4 )
{
int V_53 ;
F_45 ( & V_4 -> V_28 ) ;
F_46 ( & V_4 -> V_29 , 0 ) ;
F_47 ( & V_4 -> V_24 ) ;
V_4 -> V_21 = V_27 ;
V_4 -> V_42 = false ;
V_4 -> V_54 = false ;
V_53 = F_5 ( & V_4 -> V_1 ) ;
if ( V_53 )
return V_53 ;
return 0 ;
}
int F_48 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_1 ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
if ( V_4 -> V_42 ) {
F_49 ( L_6 , V_50 ) ;
return - V_55 ;
}
F_1 ( V_2 ) ;
F_50 ( V_5 , V_4 ) ;
return 0 ;
}
int F_51 ( struct V_3 * V_4 , struct V_30 * V_31 )
{
struct V_5 * V_5 = F_3 ( V_4 ) ;
F_19 ( & V_4 -> V_28 ) ;
if ( V_31 -> V_33 ) {
if ( ! V_4 -> V_33 . V_56 ) {
int V_53 ;
V_53 = F_52 ( V_5 , V_4 ,
V_31 -> V_36 ) ;
if ( V_53 ) {
F_17 ( & V_4 -> V_28 ) ;
return V_53 ;
}
}
}
if ( ! V_4 -> V_42 )
F_53 ( V_5 , V_4 ) ;
V_4 -> V_57 = 0 ;
V_4 -> V_58 = 0 ;
V_4 -> V_51 = V_4 -> V_1 . V_12 ;
F_54 ( F_15 ( V_31 -> V_59 -> V_7 ) ) ;
return 0 ;
}
void F_55 ( struct V_3 * V_4 , T_1 V_16 , T_1 V_17 )
{
struct V_5 * V_5 = F_3 ( V_4 ) ;
struct V_1 * V_2 = & V_4 -> V_1 ;
T_1 V_57 = V_4 -> V_57 ;
if ( V_60 )
F_56 ( F_15 ( F_16 ( V_4 ) -> V_7 ) ,
V_16 , V_17 ) ;
if ( V_57 == 0 ) {
F_57 ( V_5 , V_4 ) ;
V_57 = F_12 ( V_4 ,
V_25 ) ;
}
V_4 -> V_57 = V_57 - 1 ;
V_4 -> V_58 ++ ;
F_8 ( V_2 , V_16 , V_17 ) ;
}
void F_58 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
struct V_5 * V_5 = F_3 ( V_4 ) ;
bool V_61 = F_13 ( & V_4 -> V_24 ) ;
F_57 ( V_5 , V_4 ) ;
V_31 -> V_51 = V_4 -> V_51 ;
V_31 -> V_45 = V_4 -> V_58 ;
F_59 ( V_31 ) ;
F_60 ( & V_31 -> V_46 , & V_4 -> V_24 ) ;
if ( V_31 -> V_33 && V_61 )
F_21 ( V_4 , V_31 ) ;
F_61 ( F_15 ( V_31 -> V_59 -> V_7 ) ) ;
F_17 ( & V_4 -> V_28 ) ;
}
void F_62 ( struct V_3 * V_4 )
{
F_19 ( & V_4 -> V_28 ) ;
F_28 ( V_4 ) ;
F_17 ( & V_4 -> V_28 ) ;
}
