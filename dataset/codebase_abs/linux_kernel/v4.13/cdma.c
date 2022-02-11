static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
if ( ! V_2 -> V_6 )
return;
if ( V_5 -> V_7 ) {
F_4 ( V_5 -> V_7 , V_2 -> V_8 , V_2 -> V_9 ) ;
F_5 ( & V_5 -> V_10 , F_6 ( & V_5 -> V_10 , V_2 -> V_8 ) ) ;
}
F_7 ( V_5 -> V_11 , V_2 -> V_9 , V_2 -> V_12 , V_2 -> V_6 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_6 = 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
struct V_10 * V_13 ;
T_1 V_14 ;
int V_15 ;
V_2 -> V_12 = NULL ;
V_2 -> V_6 = 0 ;
V_2 -> V_14 = V_16 * 8 ;
V_14 = V_2 -> V_14 + 4 ;
V_2 -> V_17 = V_2 -> V_14 - 8 ;
V_2 -> V_18 = 0 ;
if ( V_5 -> V_7 ) {
unsigned long V_19 ;
V_14 = F_9 ( & V_5 -> V_10 , V_14 ) ;
V_2 -> V_12 = F_10 ( V_5 -> V_11 , V_14 , & V_2 -> V_6 ,
V_20 ) ;
if ( ! V_2 -> V_12 )
return - V_21 ;
V_19 = F_11 ( & V_5 -> V_10 ) ;
V_13 = F_12 ( & V_5 -> V_10 , V_14 >> V_19 ,
V_5 -> V_22 >> V_19 , true ) ;
if ( ! V_13 ) {
V_15 = - V_21 ;
goto V_23;
}
V_2 -> V_8 = F_13 ( & V_5 -> V_10 , V_13 ) ;
V_15 = F_14 ( V_5 -> V_7 , V_2 -> V_8 , V_2 -> V_6 , V_14 ,
V_24 ) ;
if ( V_15 )
goto V_25;
} else {
V_2 -> V_12 = F_10 ( V_5 -> V_11 , V_14 , & V_2 -> V_6 ,
V_20 ) ;
if ( ! V_2 -> V_12 )
return - V_21 ;
V_2 -> V_8 = V_2 -> V_6 ;
}
V_2 -> V_9 = V_14 ;
F_15 ( V_5 , V_2 ) ;
return 0 ;
V_25:
F_16 ( & V_5 -> V_10 , V_13 ) ;
V_23:
F_7 ( V_5 -> V_11 , V_2 -> V_9 , V_2 -> V_12 , V_2 -> V_6 ) ;
return V_15 ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_27 )
{
T_1 * V_28 = ( T_1 * ) ( ( void * ) V_2 -> V_12 + V_2 -> V_18 ) ;
F_18 ( V_2 -> V_18 == V_2 -> V_17 ) ;
* ( V_28 ++ ) = V_26 ;
* ( V_28 ++ ) = V_27 ;
V_2 -> V_18 = ( V_2 -> V_18 + 8 ) & ( V_2 -> V_14 - 1 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_29 )
{
V_2 -> V_17 = ( V_2 -> V_17 + V_29 * 8 ) & ( V_2 -> V_14 - 1 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_17 - V_2 -> V_18 ) & ( V_2 -> V_14 - 1 ) ) / 8 ;
}
unsigned int F_21 ( struct V_3 * V_4 ,
enum V_30 V_31 )
{
for (; ; ) {
struct V_1 * V_2 = & V_4 -> V_1 ;
unsigned int V_32 ;
switch ( V_31 ) {
case V_33 :
V_32 = F_22 ( & V_4 -> V_34 ) ? 1 : 0 ;
break;
case V_35 :
V_32 = F_20 ( V_2 ) ;
break;
default:
F_18 ( 1 ) ;
return - V_36 ;
}
if ( V_32 )
return V_32 ;
F_23 ( F_24 ( F_25 ( V_4 ) -> V_11 ) ,
V_31 ) ;
if ( V_4 -> V_31 != V_37 ) {
F_26 ( & V_4 -> V_38 ) ;
F_27 () ;
F_28 ( & V_4 -> V_38 ) ;
continue;
}
V_4 -> V_31 = V_31 ;
F_26 ( & V_4 -> V_38 ) ;
F_29 ( & V_4 -> V_39 ) ;
F_28 ( & V_4 -> V_38 ) ;
}
return 0 ;
}
static void F_30 ( struct V_3 * V_4 ,
struct V_40 * V_41 )
{
struct V_5 * V_42 = F_3 ( V_4 ) ;
if ( V_4 -> V_43 . V_44 ) {
return;
}
V_4 -> V_43 . V_44 = V_41 -> V_44 ;
V_4 -> V_43 . V_45 = F_31 ( V_42 , V_41 -> V_46 ) ;
V_4 -> V_43 . V_47 = V_41 -> V_48 ;
V_4 -> V_43 . V_49 = F_32 () ;
F_33 ( & V_4 -> V_43 . V_50 ,
F_34 ( V_41 -> V_43 ) ) ;
}
static void F_35 ( struct V_3 * V_4 )
{
F_36 ( & V_4 -> V_43 . V_50 ) ;
V_4 -> V_43 . V_44 = 0 ;
}
static void F_37 ( struct V_3 * V_4 )
{
bool signal = false ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
struct V_40 * V_41 , * V_51 ;
if ( ! V_4 -> V_52 )
return;
F_38 (job, n, &cdma->sync_queue, list) {
struct V_53 * V_54 =
F_31 ( V_5 , V_41 -> V_46 ) ;
if ( ! F_39 ( V_54 , V_41 -> V_48 ) ) {
if ( V_41 -> V_43 )
F_30 ( V_4 , V_41 ) ;
break;
}
if ( V_4 -> V_43 . V_44 )
F_35 ( V_4 ) ;
F_40 ( V_41 ) ;
if ( V_41 -> V_55 ) {
struct V_1 * V_2 = & V_4 -> V_1 ;
F_19 ( V_2 , V_41 -> V_55 ) ;
if ( V_4 -> V_31 == V_35 )
signal = true ;
}
F_41 ( & V_41 -> V_56 ) ;
F_42 ( V_41 ) ;
}
if ( V_4 -> V_31 == V_33 &&
F_22 ( & V_4 -> V_34 ) )
signal = true ;
if ( signal ) {
V_4 -> V_31 = V_37 ;
F_43 ( & V_4 -> V_39 ) ;
}
}
void F_44 ( struct V_3 * V_4 ,
struct V_57 * V_11 )
{
struct V_5 * V_5 = F_3 ( V_4 ) ;
T_1 V_58 , V_59 , V_47 ;
struct V_40 * V_41 = NULL ;
V_47 = F_45 ( V_4 -> V_43 . V_45 ) ;
F_46 ( V_11 , L_1 ,
V_60 , V_47 ) ;
F_46 ( V_11 , L_2 ,
V_60 ) ;
F_47 (job, &cdma->sync_queue, list) {
if ( V_47 < V_41 -> V_48 )
break;
F_48 ( V_11 , V_41 ) ;
}
F_46 ( V_11 , L_3 ,
V_60 ) ;
if ( ! F_22 ( & V_4 -> V_34 ) )
V_58 = V_41 -> V_61 ;
else
V_58 = V_4 -> V_62 ;
F_49 (job, &cdma->sync_queue, list) {
if ( V_41 -> V_44 != V_4 -> V_43 . V_44 )
break;
V_41 -> V_43 = 0 ;
V_59 = V_41 -> V_48 - V_47 ;
F_46 ( V_11 , L_4 , V_60 , V_59 ) ;
F_48 ( V_11 , V_41 ) ;
F_50 ( V_5 , V_4 , V_41 -> V_61 ,
V_59 , V_41 -> V_48 ,
V_41 -> V_55 ) ;
V_47 += V_59 ;
}
F_49 (job, &cdma->sync_queue, list)
if ( V_41 -> V_44 == V_4 -> V_43 . V_44 )
V_41 -> V_43 = F_51 (unsigned int, job->timeout, 500 ) ;
F_46 ( V_11 , L_5 , V_60 ) ;
F_52 ( V_5 , V_4 , V_58 ) ;
}
int F_53 ( struct V_3 * V_4 )
{
int V_15 ;
F_54 ( & V_4 -> V_38 ) ;
F_55 ( & V_4 -> V_39 , 0 ) ;
F_56 ( & V_4 -> V_34 ) ;
V_4 -> V_31 = V_37 ;
V_4 -> V_52 = false ;
V_4 -> V_63 = false ;
V_15 = F_8 ( & V_4 -> V_1 ) ;
if ( V_15 )
return V_15 ;
return 0 ;
}
int F_57 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_1 ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
if ( V_4 -> V_52 ) {
F_58 ( L_6 , V_60 ) ;
return - V_64 ;
}
F_1 ( V_2 ) ;
F_59 ( V_5 , V_4 ) ;
return 0 ;
}
int F_60 ( struct V_3 * V_4 , struct V_40 * V_41 )
{
struct V_5 * V_5 = F_3 ( V_4 ) ;
F_28 ( & V_4 -> V_38 ) ;
if ( V_41 -> V_43 ) {
if ( ! V_4 -> V_43 . V_65 ) {
int V_15 ;
V_15 = F_61 ( V_5 , V_4 ,
V_41 -> V_46 ) ;
if ( V_15 ) {
F_26 ( & V_4 -> V_38 ) ;
return V_15 ;
}
}
}
if ( ! V_4 -> V_52 )
F_62 ( V_5 , V_4 ) ;
V_4 -> V_66 = 0 ;
V_4 -> V_67 = 0 ;
V_4 -> V_61 = V_4 -> V_1 . V_18 ;
F_63 ( F_24 ( V_41 -> V_68 -> V_11 ) ) ;
return 0 ;
}
void F_64 ( struct V_3 * V_4 , T_1 V_26 , T_1 V_27 )
{
struct V_5 * V_5 = F_3 ( V_4 ) ;
struct V_1 * V_2 = & V_4 -> V_1 ;
T_1 V_66 = V_4 -> V_66 ;
if ( V_69 )
F_65 ( F_24 ( F_25 ( V_4 ) -> V_11 ) ,
V_26 , V_27 ) ;
if ( V_66 == 0 ) {
F_66 ( V_5 , V_4 ) ;
V_66 = F_21 ( V_4 ,
V_35 ) ;
}
V_4 -> V_66 = V_66 - 1 ;
V_4 -> V_67 ++ ;
F_17 ( V_2 , V_26 , V_27 ) ;
}
void F_67 ( struct V_3 * V_4 ,
struct V_40 * V_41 )
{
struct V_5 * V_5 = F_3 ( V_4 ) ;
bool V_70 = F_22 ( & V_4 -> V_34 ) ;
F_66 ( V_5 , V_4 ) ;
V_41 -> V_61 = V_4 -> V_61 ;
V_41 -> V_55 = V_4 -> V_67 ;
F_68 ( V_41 ) ;
F_69 ( & V_41 -> V_56 , & V_4 -> V_34 ) ;
if ( V_41 -> V_43 && V_70 )
F_30 ( V_4 , V_41 ) ;
F_70 ( F_24 ( V_41 -> V_68 -> V_11 ) ) ;
F_26 ( & V_4 -> V_38 ) ;
}
void F_71 ( struct V_3 * V_4 )
{
F_28 ( & V_4 -> V_38 ) ;
F_37 ( V_4 ) ;
F_26 ( & V_4 -> V_38 ) ;
}
