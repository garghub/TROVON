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
if ( F_3 ( F_15 ( V_5 -> V_27 -> V_28 , L_1 ,
NULL , & V_31 ) ) )
return - V_32 ;
if ( ! ( ( V_31 & V_33 )
&& ( V_31 & V_34 )
&& ( V_31 & V_35 ) ) )
return - V_32 ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 )
{
int V_36 , V_37 = 0 ;
struct V_8 * V_9 ;
int V_38 ;
V_38 = F_17 ( V_5 -> V_27 -> V_28 ) ;
F_4 (info, &mem_device->res_list, list) {
if ( V_9 -> V_39 ) {
V_37 ++ ;
continue;
}
if ( ! V_9 -> V_19 )
continue;
if ( V_38 < 0 )
V_38 = F_18 ( V_9 -> V_18 ) ;
V_36 = F_19 ( V_38 , V_9 -> V_18 , V_9 -> V_19 ) ;
if ( V_36 && V_36 != - V_40 )
continue;
V_9 -> V_39 = 1 ;
V_37 ++ ;
}
if ( ! V_37 ) {
F_20 ( & V_5 -> V_27 -> V_41 , L_2 ) ;
V_5 -> V_42 = V_43 ;
return - V_30 ;
}
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
int V_36 = 0 , V_44 ;
struct V_8 * V_9 , * V_26 ;
V_44 = F_17 ( V_5 -> V_27 -> V_28 ) ;
F_9 (info, n, &mem_device->res_list, list) {
if ( ! V_9 -> V_39 )
continue;
if ( V_44 < 0 )
V_44 = F_18 ( V_9 -> V_18 ) ;
V_36 = F_22 ( V_44 , V_9 -> V_18 , V_9 -> V_19 ) ;
if ( V_36 )
return V_36 ;
F_23 ( & V_9 -> V_24 ) ;
F_10 ( V_9 ) ;
}
return V_36 ;
}
static void F_24 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_8 ( V_5 ) ;
V_5 -> V_27 -> V_45 = NULL ;
F_10 ( V_5 ) ;
}
static int F_25 ( struct V_46 * V_27 ,
const struct V_47 * V_48 )
{
struct V_4 * V_5 ;
int V_36 ;
if ( ! V_27 )
return - V_30 ;
V_5 = F_5 ( sizeof( struct V_4 ) , V_22 ) ;
if ( ! V_5 )
return - V_49 ;
F_6 ( & V_5 -> V_25 ) ;
V_5 -> V_27 = V_27 ;
sprintf ( F_26 ( V_27 ) , L_3 , V_50 ) ;
sprintf ( F_27 ( V_27 ) , L_3 , V_51 ) ;
V_27 -> V_45 = V_5 ;
V_36 = F_11 ( V_5 ) ;
if ( V_36 ) {
F_10 ( V_5 ) ;
return V_36 ;
}
V_5 -> V_42 = V_52 ;
V_36 = F_14 ( V_5 ) ;
if ( V_36 ) {
F_24 ( V_5 ) ;
return 0 ;
}
V_36 = F_16 ( V_5 ) ;
if ( V_36 ) {
F_20 ( & V_27 -> V_41 , L_4 ) ;
F_24 ( V_5 ) ;
return - V_32 ;
}
F_28 ( & V_27 -> V_41 , L_5 ) ;
return 1 ;
}
static void F_29 ( struct V_46 * V_27 )
{
struct V_4 * V_5 ;
if ( ! V_27 || ! F_30 ( V_27 ) )
return;
V_5 = F_30 ( V_27 ) ;
F_21 ( V_5 ) ;
F_24 ( V_5 ) ;
}
void T_2 F_31 ( void )
{
F_32 ( & V_53 , L_6 ) ;
}
