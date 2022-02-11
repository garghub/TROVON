static struct V_1 * F_1 ( T_1 V_2 , int V_3 , int V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_7 )
{
struct V_1 * V_8 ;
int V_9 ;
V_8 = F_2 ( sizeof( struct V_1 ) + sizeof( struct V_10 ) , V_11 ) ;
if ( ! V_8 ) {
F_3 ( V_12
L_1 ,
sizeof( struct V_1 ) ) ;
return NULL ;
}
V_8 -> V_13 = (struct V_10 * ) ( V_8 + 1 ) ;
V_8 -> V_14 = V_15 ;
V_8 -> V_16 = V_3 ;
V_8 -> V_3 = 0 ;
V_8 -> V_17 = 0 ;
V_8 -> V_18 = 0 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_19 = V_20 ;
V_8 -> V_21 = V_22 ;
F_4 ( & V_8 -> V_23 , 2 ) ;
F_5 ( & V_8 -> V_24 ) ;
F_6 ( & V_8 -> V_25 ) ;
F_6 ( & V_8 -> V_26 ) ;
memcpy ( & V_8 -> V_8 , V_7 , sizeof( struct V_7 ) ) ;
F_7 ( & V_8 -> V_8 , L_2 , V_8 -> V_2 ) ;
snprintf ( V_8 -> V_27 , sizeof( V_8 -> V_27 ) , L_2 , V_8 -> V_2 ) ;
V_8 -> V_8 . V_28 = V_8 -> V_27 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_29 = 1 ;
V_9 = F_8 ( & V_8 -> V_8 ) ;
if ( V_9 ) {
F_3 ( V_12 L_3 , V_9 ) ;
memset ( V_8 , 0 , sizeof( struct V_1 ) ) ;
F_9 ( V_8 ) ;
V_8 = NULL ;
}
return V_8 ;
}
static void F_10 ( struct V_1 * V_8 )
{
F_11 ( & V_8 -> V_8 ) ;
}
int F_12 ( struct V_10 * V_30 )
{
struct V_1 * V_8 , * V_31 ;
int V_32 = 0 ;
struct V_33 V_34 ;
int V_2 , V_35 ;
if ( ! ( V_30 -> V_36 && V_30 -> V_37 ) &&
! ( V_30 -> V_38 && V_30 -> V_39 ) &&
! ( V_30 -> V_40 && V_30 -> V_41 && V_30 -> V_37 ) ) {
F_3 ( V_12 L_4 ) ;
return ( - V_42 ) ;
}
F_13 ( & V_43 ) ;
V_2 = 0 ;
do {
++ V_2 ;
V_35 = 0 ;
F_14 (entry, &w1_masters, w1_master_entry) {
if ( V_31 -> V_2 == V_2 ) {
V_35 = 1 ;
break;
}
}
} while ( V_35 );
V_8 = F_1 ( V_2 , V_44 , V_45 ,
& V_46 , & V_47 ) ;
if ( ! V_8 ) {
F_15 ( & V_43 ) ;
return - V_48 ;
}
V_32 = F_16 ( V_8 ) ;
if ( V_32 ) {
F_15 ( & V_43 ) ;
goto V_49;
}
memcpy ( V_8 -> V_13 , V_30 , sizeof( struct V_10 ) ) ;
V_8 -> V_18 = 1 ;
V_8 -> V_50 = F_17 ( & V_51 , V_8 , L_5 , V_8 -> V_27 ) ;
if ( F_18 ( V_8 -> V_50 ) ) {
V_32 = F_19 ( V_8 -> V_50 ) ;
F_20 ( & V_8 -> V_8 ,
L_6 ,
V_32 ) ;
F_15 ( & V_43 ) ;
goto V_52;
}
F_21 ( & V_8 -> V_53 , & V_54 ) ;
F_15 ( & V_43 ) ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_2 . V_55 . V_2 = V_8 -> V_2 ;
V_34 . type = V_56 ;
F_22 ( V_8 , & V_34 ) ;
return 0 ;
#if 0
err_out_kill_thread:
kthread_stop(dev->thread);
#endif
V_52:
F_23 ( V_8 ) ;
V_49:
F_10 ( V_8 ) ;
return V_32 ;
}
void F_24 ( struct V_1 * V_8 )
{
struct V_33 V_34 ;
struct V_57 * V_58 , * V_59 ;
F_25 ( V_8 -> V_50 ) ;
F_13 ( & V_43 ) ;
F_26 ( & V_8 -> V_53 ) ;
F_15 ( & V_43 ) ;
F_13 ( & V_8 -> V_25 ) ;
F_27 (sl, sln, &dev->slist, w1_slave_entry)
F_28 ( V_58 ) ;
F_23 ( V_8 ) ;
F_15 ( & V_8 -> V_25 ) ;
F_29 ( & V_8 -> V_23 ) ;
while ( F_30 ( & V_8 -> V_23 ) ) {
F_31 ( & V_8 -> V_8 , L_7 ,
V_8 -> V_27 , F_30 ( & V_8 -> V_23 ) ) ;
if ( F_32 ( 1000 ) )
F_33 ( V_60 ) ;
}
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_2 . V_55 . V_2 = V_8 -> V_2 ;
V_34 . type = V_61 ;
F_22 ( V_8 , & V_34 ) ;
F_10 ( V_8 ) ;
}
void F_34 ( struct V_10 * V_62 )
{
struct V_1 * V_8 , * V_35 = NULL ;
F_14 (dev, &w1_masters, w1_master_entry) {
if ( ! V_8 -> V_18 )
continue;
if ( V_8 -> V_13 -> V_63 == V_62 -> V_63 ) {
V_35 = V_8 ;
break;
}
}
if ( ! V_35 ) {
F_3 ( V_12 L_8 ) ;
return;
}
F_24 ( V_35 ) ;
}
