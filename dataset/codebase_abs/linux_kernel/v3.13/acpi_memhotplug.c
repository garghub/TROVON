static T_1
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 V_7 ;
struct V_8 * V_9 , * V_10 ;
T_1 V_11 ;
V_11 = F_2 ( V_2 , & V_7 ) ;
if ( F_3 ( V_11 ) ||
( V_7 . V_12 != V_13 ) )
return V_14 ;
F_4 (info, &mem_device->res_list, list) {
if ( ( V_9 -> V_15 == V_7 . V_9 . V_16 . V_15 ) &&
( V_9 -> V_17 == V_7 . V_9 . V_16 . V_17 ) &&
( V_9 -> V_18 + V_9 -> V_19 == V_7 . V_20 ) ) {
V_9 -> V_19 += V_7 . V_21 ;
return V_14 ;
}
}
V_10 = F_5 ( sizeof( struct V_8 ) , V_22 ) ;
if ( ! V_10 )
return V_23 ;
F_6 ( & V_10 -> V_24 ) ;
V_10 -> V_15 = V_7 . V_9 . V_16 . V_15 ;
V_10 -> V_17 = V_7 . V_9 . V_16 . V_17 ;
V_10 -> V_18 = V_7 . V_20 ;
V_10 -> V_19 = V_7 . V_21 ;
F_7 ( & V_10 -> V_24 , & V_5 -> V_25 ) ;
return V_14 ;
}
static void
F_8 ( struct V_4 * V_5 )
{
struct V_8 * V_9 , * V_26 ;
F_9 (info, n, &mem_device->res_list, list)
F_10 ( V_9 ) ;
F_6 ( & V_5 -> V_25 ) ;
}
static int
F_11 ( struct V_4 * V_5 )
{
T_1 V_11 ;
if ( ! F_12 ( & V_5 -> V_25 ) )
return 0 ;
V_11 = F_13 ( V_5 -> V_27 -> V_28 , V_29 ,
F_1 , V_5 ) ;
if ( F_3 ( V_11 ) ) {
F_8 ( V_5 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
unsigned long long V_31 ;
if ( F_3 ( F_15 ( V_5 -> V_27 -> V_28 ,
V_32 , NULL ,
& V_31 ) ) )
return - V_33 ;
if ( ! ( ( V_31 & V_34 )
&& ( V_31 & V_35 )
&& ( V_31 & V_36 ) ) )
return - V_33 ;
return 0 ;
}
static unsigned long F_16 ( struct V_8 * V_9 )
{
return F_17 ( V_9 -> V_18 ) ;
}
static unsigned long F_18 ( struct V_8 * V_9 )
{
return F_19 ( V_9 -> V_18 + V_9 -> V_19 - 1 ) ;
}
static int F_20 ( struct V_37 * V_16 , void * V_38 )
{
return F_21 ( & V_16 -> V_39 , ( V_40 ) V_38 ) ;
}
static int F_22 ( struct V_8 * V_9 ,
V_40 V_28 )
{
return F_23 ( F_16 ( V_9 ) ,
F_18 ( V_9 ) , ( void * ) V_28 ,
F_20 ) ;
}
static int F_24 ( struct V_37 * V_16 , void * V_38 )
{
F_25 ( & V_16 -> V_39 ) ;
return 0 ;
}
static void F_26 ( struct V_8 * V_9 ,
V_40 V_28 )
{
F_23 ( F_16 ( V_9 ) ,
F_18 ( V_9 ) , NULL , F_24 ) ;
}
static int F_27 ( struct V_4 * V_5 )
{
V_40 V_28 = V_5 -> V_27 -> V_28 ;
int V_41 , V_42 = 0 ;
struct V_8 * V_9 ;
int V_43 ;
V_43 = F_28 ( V_28 ) ;
F_4 (info, &mem_device->res_list, list) {
if ( V_9 -> V_44 ) {
V_42 ++ ;
continue;
}
if ( ! V_9 -> V_19 )
continue;
if ( V_43 < 0 )
V_43 = F_29 ( V_9 -> V_18 ) ;
V_41 = F_30 ( V_43 , V_9 -> V_18 , V_9 -> V_19 ) ;
if ( V_41 && V_41 != - V_45 )
continue;
V_41 = F_22 ( V_9 , V_28 ) ;
if ( V_41 ) {
F_26 ( V_9 , V_28 ) ;
return - V_33 ;
}
V_9 -> V_44 = 1 ;
V_42 ++ ;
}
if ( ! V_42 ) {
F_31 ( & V_5 -> V_27 -> V_39 , L_1 ) ;
V_5 -> V_46 = V_47 ;
return - V_30 ;
}
return 0 ;
}
static void F_32 ( struct V_4 * V_5 )
{
V_40 V_28 = V_5 -> V_27 -> V_28 ;
struct V_8 * V_9 , * V_26 ;
int V_48 = F_28 ( V_28 ) ;
F_9 (info, n, &mem_device->res_list, list) {
if ( ! V_9 -> V_44 )
continue;
if ( V_48 == V_49 )
V_48 = F_29 ( V_9 -> V_18 ) ;
F_26 ( V_9 , V_28 ) ;
F_33 ( V_48 , V_9 -> V_18 , V_9 -> V_19 ) ;
F_34 ( & V_9 -> V_24 ) ;
F_10 ( V_9 ) ;
}
}
static void F_35 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_8 ( V_5 ) ;
V_5 -> V_27 -> V_50 = NULL ;
F_10 ( V_5 ) ;
}
static int F_36 ( struct V_51 * V_27 ,
const struct V_52 * V_53 )
{
struct V_4 * V_5 ;
int V_41 ;
if ( ! V_27 )
return - V_30 ;
V_5 = F_5 ( sizeof( struct V_4 ) , V_22 ) ;
if ( ! V_5 )
return - V_54 ;
F_6 ( & V_5 -> V_25 ) ;
V_5 -> V_27 = V_27 ;
sprintf ( F_37 ( V_27 ) , L_2 , V_55 ) ;
sprintf ( F_38 ( V_27 ) , L_2 , V_56 ) ;
V_27 -> V_50 = V_5 ;
V_41 = F_11 ( V_5 ) ;
if ( V_41 ) {
V_27 -> V_50 = NULL ;
F_10 ( V_5 ) ;
return V_41 ;
}
V_5 -> V_46 = V_57 ;
V_41 = F_14 ( V_5 ) ;
if ( V_41 ) {
F_35 ( V_5 ) ;
return 0 ;
}
V_41 = F_27 ( V_5 ) ;
if ( V_41 ) {
F_31 ( & V_27 -> V_39 , L_3 ) ;
F_35 ( V_5 ) ;
return V_41 ;
}
F_39 ( & V_27 -> V_39 , L_4 ) ;
return 1 ;
}
static void F_40 ( struct V_51 * V_27 )
{
struct V_4 * V_5 ;
if ( ! V_27 || ! F_41 ( V_27 ) )
return;
V_5 = F_41 ( V_27 ) ;
F_32 ( V_5 ) ;
F_35 ( V_5 ) ;
}
void T_2 F_42 ( void )
{
F_43 ( & V_58 , L_5 ) ;
}
