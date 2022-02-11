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
( V_9 -> V_18 + V_9 -> V_19 == V_7 . V_20 . V_21 ) ) {
V_9 -> V_19 += V_7 . V_20 . V_22 ;
return V_14 ;
}
}
V_10 = F_5 ( sizeof( struct V_8 ) , V_23 ) ;
if ( ! V_10 )
return V_24 ;
F_6 ( & V_10 -> V_25 ) ;
V_10 -> V_15 = V_7 . V_9 . V_16 . V_15 ;
V_10 -> V_17 = V_7 . V_9 . V_16 . V_17 ;
V_10 -> V_18 = V_7 . V_20 . V_21 ;
V_10 -> V_19 = V_7 . V_20 . V_22 ;
F_7 ( & V_10 -> V_25 , & V_5 -> V_26 ) ;
return V_14 ;
}
static void
F_8 ( struct V_4 * V_5 )
{
struct V_8 * V_9 , * V_27 ;
F_9 (info, n, &mem_device->res_list, list)
F_10 ( V_9 ) ;
F_6 ( & V_5 -> V_26 ) ;
}
static int
F_11 ( struct V_4 * V_5 )
{
T_1 V_11 ;
if ( ! F_12 ( & V_5 -> V_26 ) )
return 0 ;
V_11 = F_13 ( V_5 -> V_28 -> V_29 , V_30 ,
F_1 , V_5 ) ;
if ( F_3 ( V_11 ) ) {
F_8 ( V_5 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
unsigned long long V_32 ;
if ( F_3 ( F_15 ( V_5 -> V_28 -> V_29 ,
V_33 , NULL ,
& V_32 ) ) )
return - V_34 ;
if ( ! ( ( V_32 & V_35 )
&& ( V_32 & V_36 )
&& ( V_32 & V_37 ) ) )
return - V_34 ;
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
static int F_20 ( struct V_38 * V_16 , void * V_39 )
{
return F_21 ( & V_16 -> V_40 , V_39 ) ;
}
static int F_22 ( struct V_8 * V_9 ,
struct V_41 * V_42 )
{
return F_23 ( F_16 ( V_9 ) ,
F_18 ( V_9 ) , V_42 ,
F_20 ) ;
}
static int F_24 ( struct V_38 * V_16 , void * V_39 )
{
F_25 ( & V_16 -> V_40 ) ;
return 0 ;
}
static void F_26 ( struct V_8 * V_9 )
{
F_23 ( F_16 ( V_9 ) ,
F_18 ( V_9 ) , NULL , F_24 ) ;
}
static int F_27 ( struct V_4 * V_5 )
{
T_2 V_29 = V_5 -> V_28 -> V_29 ;
int V_43 , V_44 = 0 ;
struct V_8 * V_9 ;
int V_45 ;
V_45 = F_28 ( V_29 ) ;
F_4 (info, &mem_device->res_list, list) {
if ( V_9 -> V_46 ) {
V_44 ++ ;
continue;
}
if ( ! V_9 -> V_19 )
continue;
if ( V_45 < 0 )
V_45 = F_29 ( V_9 -> V_18 ) ;
V_43 = F_30 ( V_45 , V_9 -> V_18 , V_9 -> V_19 ) ;
if ( V_43 && V_43 != - V_47 )
continue;
V_43 = F_22 ( V_9 , V_5 -> V_28 ) ;
if ( V_43 ) {
F_26 ( V_9 ) ;
return - V_34 ;
}
V_9 -> V_46 = 1 ;
V_44 ++ ;
}
if ( ! V_44 ) {
F_31 ( & V_5 -> V_28 -> V_40 , L_1 ) ;
V_5 -> V_48 = V_49 ;
return - V_31 ;
}
return 0 ;
}
static void F_32 ( struct V_4 * V_5 )
{
T_2 V_29 = V_5 -> V_28 -> V_29 ;
struct V_8 * V_9 , * V_27 ;
int V_50 = F_28 ( V_29 ) ;
F_9 (info, n, &mem_device->res_list, list) {
if ( ! V_9 -> V_46 )
continue;
if ( V_50 == V_51 )
V_50 = F_29 ( V_9 -> V_18 ) ;
F_26 ( V_9 ) ;
F_33 ( V_50 , V_9 -> V_18 , V_9 -> V_19 ) ;
F_34 ( & V_9 -> V_25 ) ;
F_10 ( V_9 ) ;
}
}
static void F_35 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_8 ( V_5 ) ;
V_5 -> V_28 -> V_52 = NULL ;
F_10 ( V_5 ) ;
}
static int F_36 ( struct V_41 * V_28 ,
const struct V_53 * V_54 )
{
struct V_4 * V_5 ;
int V_43 ;
if ( ! V_28 )
return - V_31 ;
V_5 = F_5 ( sizeof( struct V_4 ) , V_23 ) ;
if ( ! V_5 )
return - V_55 ;
F_6 ( & V_5 -> V_26 ) ;
V_5 -> V_28 = V_28 ;
sprintf ( F_37 ( V_28 ) , L_2 , V_56 ) ;
sprintf ( F_38 ( V_28 ) , L_2 , V_57 ) ;
V_28 -> V_52 = V_5 ;
V_43 = F_11 ( V_5 ) ;
if ( V_43 ) {
V_28 -> V_52 = NULL ;
F_10 ( V_5 ) ;
return V_43 ;
}
V_5 -> V_48 = V_58 ;
V_43 = F_14 ( V_5 ) ;
if ( V_43 ) {
F_35 ( V_5 ) ;
return 0 ;
}
V_43 = F_27 ( V_5 ) ;
if ( V_43 ) {
F_31 ( & V_28 -> V_40 , L_3 ) ;
F_35 ( V_5 ) ;
return V_43 ;
}
F_39 ( & V_28 -> V_40 , L_4 ) ;
return 1 ;
}
static void F_40 ( struct V_41 * V_28 )
{
struct V_4 * V_5 ;
if ( ! V_28 || ! F_41 ( V_28 ) )
return;
V_5 = F_41 ( V_28 ) ;
F_32 ( V_5 ) ;
F_35 ( V_5 ) ;
}
void T_3 F_42 ( void )
{
if ( V_59 ) {
V_60 . V_61 = NULL ;
F_43 ( & V_60 ) ;
return;
}
F_44 ( & V_60 , L_5 ) ;
}
static int T_3 F_45 ( char * V_62 )
{
V_59 = true ;
return 1 ;
}
void T_3 F_42 ( void )
{
F_43 ( & V_60 ) ;
}
