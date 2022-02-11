static struct V_1 * F_1 ( T_1 V_2 , int V_3 , int V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_7 )
{
struct V_1 * V_8 ;
int V_9 ;
V_8 = F_2 ( sizeof( struct V_1 ) + sizeof( struct V_10 ) , V_11 ) ;
if ( ! V_8 ) {
F_3 ( L_1 ,
sizeof( struct V_1 ) ) ;
return NULL ;
}
V_8 -> V_12 = (struct V_10 * ) ( V_8 + 1 ) ;
V_8 -> V_13 = V_14 ;
V_8 -> V_15 = V_3 ;
V_8 -> V_3 = 0 ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_18 = V_19 ;
V_8 -> V_20 = V_21 ;
F_4 ( & V_8 -> V_22 , 2 ) ;
F_5 ( & V_8 -> V_23 ) ;
F_5 ( & V_8 -> V_24 ) ;
F_6 ( & V_8 -> V_25 ) ;
F_6 ( & V_8 -> V_26 ) ;
F_6 ( & V_8 -> V_27 ) ;
memcpy ( & V_8 -> V_8 , V_7 , sizeof( struct V_7 ) ) ;
F_7 ( & V_8 -> V_8 , L_2 , V_8 -> V_2 ) ;
snprintf ( V_8 -> V_28 , sizeof( V_8 -> V_28 ) , L_2 , V_8 -> V_2 ) ;
V_8 -> V_8 . V_29 = V_8 -> V_28 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_30 = 1 ;
V_9 = F_8 ( & V_8 -> V_8 ) ;
if ( V_9 ) {
F_3 ( L_3 , V_9 ) ;
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
int F_12 ( struct V_10 * V_31 )
{
struct V_1 * V_8 , * V_32 ;
int V_33 = 0 ;
struct V_34 V_35 ;
int V_2 , V_36 ;
if ( ! ( V_31 -> V_37 && V_31 -> V_38 ) &&
! ( V_31 -> V_39 && V_31 -> V_40 ) &&
! ( V_31 -> V_41 && V_31 -> V_42 && V_31 -> V_38 ) ) {
F_3 ( L_4 ) ;
return ( - V_43 ) ;
}
F_13 ( & V_44 ) ;
V_2 = 0 ;
do {
++ V_2 ;
V_36 = 0 ;
F_14 (entry, &w1_masters, w1_master_entry) {
if ( V_32 -> V_2 == V_2 ) {
V_36 = 1 ;
break;
}
}
} while ( V_36 );
V_8 = F_1 ( V_2 , V_45 , V_46 ,
& V_47 , & V_48 ) ;
if ( ! V_8 ) {
F_15 ( & V_44 ) ;
return - V_49 ;
}
V_33 = F_16 ( V_8 ) ;
if ( V_33 ) {
F_15 ( & V_44 ) ;
goto V_50;
}
memcpy ( V_8 -> V_12 , V_31 , sizeof( struct V_10 ) ) ;
V_8 -> V_17 = 1 ;
V_8 -> V_51 = F_17 ( & V_52 , V_8 , L_5 , V_8 -> V_28 ) ;
if ( F_18 ( V_8 -> V_51 ) ) {
V_33 = F_19 ( V_8 -> V_51 ) ;
F_20 ( & V_8 -> V_8 ,
L_6 ,
V_33 ) ;
F_15 ( & V_44 ) ;
goto V_53;
}
F_21 ( & V_8 -> V_54 , & V_55 ) ;
F_15 ( & V_44 ) ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_2 . V_56 . V_2 = V_8 -> V_2 ;
V_35 . type = V_57 ;
F_22 ( V_8 , & V_35 ) ;
return 0 ;
#if 0
err_out_kill_thread:
set_bit(W1_ABORT_SEARCH, &dev->flags);
kthread_stop(dev->thread);
#endif
V_53:
F_23 ( V_8 ) ;
V_50:
F_10 ( V_8 ) ;
return V_33 ;
}
void F_24 ( struct V_1 * V_8 )
{
struct V_34 V_35 ;
struct V_58 * V_59 , * V_60 ;
F_13 ( & V_44 ) ;
F_25 ( & V_8 -> V_54 ) ;
F_15 ( & V_44 ) ;
F_26 ( V_61 , & V_8 -> V_62 ) ;
F_27 ( V_8 -> V_51 ) ;
F_13 ( & V_8 -> V_25 ) ;
F_13 ( & V_8 -> V_27 ) ;
F_28 (sl, sln, &dev->slist, w1_slave_entry) {
F_15 ( & V_8 -> V_27 ) ;
F_29 ( V_59 ) ;
F_13 ( & V_8 -> V_27 ) ;
}
F_23 ( V_8 ) ;
F_15 ( & V_8 -> V_27 ) ;
F_15 ( & V_8 -> V_25 ) ;
F_30 ( & V_8 -> V_22 ) ;
while ( F_31 ( & V_8 -> V_22 ) ) {
F_32 ( & V_8 -> V_8 , L_7 ,
V_8 -> V_28 , F_31 ( & V_8 -> V_22 ) ) ;
if ( F_33 ( 1000 ) )
F_34 ( V_63 ) ;
F_13 ( & V_8 -> V_27 ) ;
F_35 ( V_8 ) ;
F_15 ( & V_8 -> V_27 ) ;
}
F_13 ( & V_8 -> V_27 ) ;
F_35 ( V_8 ) ;
F_15 ( & V_8 -> V_27 ) ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_2 . V_56 . V_2 = V_8 -> V_2 ;
V_35 . type = V_64 ;
F_22 ( V_8 , & V_35 ) ;
F_10 ( V_8 ) ;
}
void F_36 ( struct V_10 * V_65 )
{
struct V_1 * V_8 , * V_36 = NULL ;
F_14 (dev, &w1_masters, w1_master_entry) {
if ( ! V_8 -> V_17 )
continue;
if ( V_8 -> V_12 -> V_66 == V_65 -> V_66 ) {
V_36 = V_8 ;
break;
}
}
if ( ! V_36 ) {
F_3 ( L_8 ) ;
return;
}
F_24 ( V_36 ) ;
}
