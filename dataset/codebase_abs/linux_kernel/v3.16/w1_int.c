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
F_5 ( & V_8 -> V_25 ) ;
F_6 ( & V_8 -> V_26 ) ;
F_6 ( & V_8 -> V_27 ) ;
F_6 ( & V_8 -> V_28 ) ;
memcpy ( & V_8 -> V_8 , V_7 , sizeof( struct V_7 ) ) ;
F_7 ( & V_8 -> V_8 , L_2 , V_8 -> V_2 ) ;
snprintf ( V_8 -> V_29 , sizeof( V_8 -> V_29 ) , L_2 , V_8 -> V_2 ) ;
V_8 -> V_8 . V_30 = V_8 -> V_29 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_31 = 1 ;
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
int F_12 ( struct V_10 * V_32 )
{
struct V_1 * V_8 , * V_33 ;
int V_34 = 0 ;
struct V_35 V_36 ;
int V_2 , V_37 ;
if ( ! ( V_32 -> V_38 && V_32 -> V_39 ) &&
! ( V_32 -> V_40 && V_32 -> V_41 ) &&
! ( V_32 -> V_42 && V_32 -> V_43 && V_32 -> V_39 ) ) {
F_3 ( V_12 L_4 ) ;
return ( - V_44 ) ;
}
F_13 ( & V_45 ) ;
V_2 = 0 ;
do {
++ V_2 ;
V_37 = 0 ;
F_14 (entry, &w1_masters, w1_master_entry) {
if ( V_33 -> V_2 == V_2 ) {
V_37 = 1 ;
break;
}
}
} while ( V_37 );
V_8 = F_1 ( V_2 , V_46 , V_47 ,
& V_48 , & V_49 ) ;
if ( ! V_8 ) {
F_15 ( & V_45 ) ;
return - V_50 ;
}
V_34 = F_16 ( V_8 ) ;
if ( V_34 ) {
F_15 ( & V_45 ) ;
goto V_51;
}
memcpy ( V_8 -> V_13 , V_32 , sizeof( struct V_10 ) ) ;
V_8 -> V_18 = 1 ;
V_8 -> V_52 = F_17 ( & V_53 , V_8 , L_5 , V_8 -> V_29 ) ;
if ( F_18 ( V_8 -> V_52 ) ) {
V_34 = F_19 ( V_8 -> V_52 ) ;
F_20 ( & V_8 -> V_8 ,
L_6 ,
V_34 ) ;
F_15 ( & V_45 ) ;
goto V_54;
}
F_21 ( & V_8 -> V_55 , & V_56 ) ;
F_15 ( & V_45 ) ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_2 . V_57 . V_2 = V_8 -> V_2 ;
V_36 . type = V_58 ;
F_22 ( V_8 , & V_36 ) ;
return 0 ;
#if 0
err_out_kill_thread:
set_bit(W1_ABORT_SEARCH, &dev->flags);
kthread_stop(dev->thread);
#endif
V_54:
F_23 ( V_8 ) ;
V_51:
F_10 ( V_8 ) ;
return V_34 ;
}
void F_24 ( struct V_1 * V_8 )
{
struct V_35 V_36 ;
struct V_59 * V_60 , * V_61 ;
F_13 ( & V_45 ) ;
F_25 ( & V_8 -> V_55 ) ;
F_15 ( & V_45 ) ;
F_26 ( V_62 , & V_8 -> V_63 ) ;
F_27 ( V_8 -> V_52 ) ;
F_13 ( & V_8 -> V_26 ) ;
F_13 ( & V_8 -> V_28 ) ;
F_28 (sl, sln, &dev->slist, w1_slave_entry) {
F_15 ( & V_8 -> V_28 ) ;
F_29 ( V_60 ) ;
F_13 ( & V_8 -> V_28 ) ;
}
F_23 ( V_8 ) ;
F_15 ( & V_8 -> V_28 ) ;
F_15 ( & V_8 -> V_26 ) ;
F_30 ( & V_8 -> V_23 ) ;
while ( F_31 ( & V_8 -> V_23 ) ) {
F_32 ( & V_8 -> V_8 , L_7 ,
V_8 -> V_29 , F_31 ( & V_8 -> V_23 ) ) ;
if ( F_33 ( 1000 ) )
F_34 ( V_64 ) ;
F_13 ( & V_8 -> V_28 ) ;
F_35 ( V_8 ) ;
F_15 ( & V_8 -> V_28 ) ;
}
F_13 ( & V_8 -> V_28 ) ;
F_35 ( V_8 ) ;
F_15 ( & V_8 -> V_28 ) ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_2 . V_57 . V_2 = V_8 -> V_2 ;
V_36 . type = V_65 ;
F_22 ( V_8 , & V_36 ) ;
F_10 ( V_8 ) ;
}
void F_36 ( struct V_10 * V_66 )
{
struct V_1 * V_8 , * V_37 = NULL ;
F_14 (dev, &w1_masters, w1_master_entry) {
if ( ! V_8 -> V_18 )
continue;
if ( V_8 -> V_13 -> V_67 == V_66 -> V_67 ) {
V_37 = V_8 ;
break;
}
}
if ( ! V_37 ) {
F_3 ( V_12 L_8 ) ;
return;
}
F_24 ( V_37 ) ;
}
