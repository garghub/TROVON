void F_1 ( void )
{
if ( ! V_1 )
V_1 = F_2 ( L_1 ) ;
}
void F_3 ( void )
{
if ( V_1 ) {
F_4 ( V_1 ) ;
F_5 ( V_1 ) ;
V_1 = NULL ;
}
}
struct V_2 * F_6 ( const struct V_3 * V_4 )
{
struct V_2 * V_5 ;
F_7 ( ! V_1 ) ;
if ( V_4 -> V_6 == NULL )
return F_8 ( - V_7 ) ;
if ( V_4 -> V_8 -> V_6 != V_4 -> V_6 )
return F_8 ( - V_7 ) ;
F_9 ( & V_4 -> V_6 -> V_9 ) ;
F_10 ( & V_10 ) ;
V_5 = F_11 ( V_4 ) ;
if ( V_5 )
F_12 ( L_2 ) ;
if ( ! V_5 )
V_5 = F_13 ( V_4 ) ;
F_14 ( & V_10 ) ;
F_15 ( & V_4 -> V_6 -> V_9 ) ;
return V_5 ;
}
struct V_2 * F_16 ( const struct V_3 * V_4 )
{
struct V_2 * V_5 ;
if ( V_4 -> V_6 == NULL )
return F_8 ( - V_7 ) ;
if ( V_4 -> V_8 -> V_6 != V_4 -> V_6 )
return F_8 ( - V_7 ) ;
V_5 = F_11 ( V_4 ) ;
return V_5 ;
}
static struct V_2 * F_17 ( const struct V_11 * V_6 )
{
struct V_2 * V_5 ;
F_18 (kfd_processes_table, process,
kfd_processes, (uintptr_t)mm)
if ( V_5 -> V_6 == V_6 )
return V_5 ;
return NULL ;
}
static struct V_2 * F_11 ( const struct V_3 * V_4 )
{
struct V_2 * V_12 ;
int V_13 ;
V_13 = F_19 ( & V_14 ) ;
V_12 = F_17 ( V_4 -> V_6 ) ;
F_20 ( & V_14 , V_13 ) ;
return V_12 ;
}
static void F_21 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 , * V_21 ;
struct V_2 * V_12 ;
V_18 = (struct V_17 * ) V_16 ;
V_12 = V_18 -> V_12 ;
F_10 ( & V_12 -> V_22 ) ;
F_22 (pdd, temp, &p->per_device_data,
per_device_list) {
F_23 ( V_20 -> V_23 -> V_24 , V_12 -> V_25 ) ;
F_24 ( & V_20 -> V_26 ) ;
F_25 ( V_20 ) ;
}
F_26 ( V_12 -> V_25 ) ;
F_14 ( & V_12 -> V_22 ) ;
F_27 ( & V_12 -> V_22 ) ;
F_25 ( V_12 -> V_27 ) ;
F_25 ( V_12 ) ;
F_25 ( ( void * ) V_16 ) ;
}
static void F_28 ( struct V_28 * V_29 )
{
struct V_17 * V_16 ;
struct V_2 * V_12 ;
F_7 ( ! V_1 ) ;
V_12 = F_29 ( V_29 , struct V_2 , V_29 ) ;
F_7 ( F_30 ( & V_12 -> V_6 -> V_30 ) <= 0 ) ;
F_31 ( V_12 -> V_6 ) ;
V_16 = (struct V_17 * )
F_32 ( sizeof( struct V_17 ) , V_31 ) ;
if ( V_16 ) {
F_33 ( (struct V_15 * ) V_16 , F_21 ) ;
V_16 -> V_12 = V_12 ;
F_34 ( V_1 , (struct V_15 * ) V_16 ) ;
}
}
static void F_35 ( struct V_32 * V_33 ,
struct V_11 * V_6 )
{
struct V_2 * V_12 ;
V_12 = F_29 ( V_33 , struct V_2 , V_32 ) ;
F_7 ( V_12 -> V_6 != V_6 ) ;
F_10 ( & V_10 ) ;
F_36 ( & V_12 -> V_34 ) ;
F_14 ( & V_10 ) ;
F_37 ( & V_14 ) ;
F_10 ( & V_12 -> V_22 ) ;
F_38 ( & V_12 -> V_35 ) ;
F_14 ( & V_12 -> V_22 ) ;
F_39 ( & V_12 -> V_6 -> V_30 ) ;
F_40 ( & V_12 -> V_32 , V_12 -> V_6 ) ;
F_41 ( & V_12 -> V_29 , & F_28 ) ;
}
static struct V_2 * F_13 ( const struct V_3 * V_4 )
{
struct V_2 * V_5 ;
int V_36 = - V_37 ;
V_5 = F_42 ( sizeof( * V_5 ) , V_38 ) ;
if ( ! V_5 )
goto V_39;
V_5 -> V_27 = F_43 ( V_40 ,
sizeof( V_5 -> V_27 [ 0 ] ) , V_38 ) ;
if ( ! V_5 -> V_27 )
goto V_41;
V_5 -> V_25 = F_44 () ;
if ( V_5 -> V_25 == 0 )
goto V_42;
F_45 ( & V_5 -> V_22 ) ;
V_5 -> V_6 = V_4 -> V_6 ;
V_5 -> V_32 . V_43 = & V_44 ;
V_36 = F_46 ( & V_5 -> V_32 , V_5 -> V_6 ) ;
if ( V_36 )
goto V_45;
F_47 ( V_46 , & V_5 -> V_34 ,
( V_47 ) V_5 -> V_6 ) ;
V_5 -> V_48 = V_4 -> V_8 ;
V_5 -> V_49 = V_40 ;
F_48 ( & V_5 -> V_50 ) ;
V_36 = F_49 ( & V_5 -> V_35 , V_5 ) ;
if ( V_36 != 0 )
goto V_51;
V_5 -> V_52 = F_50 () ;
if ( F_51 ( V_5 ) != 0 )
goto V_53;
return V_5 ;
V_53:
F_38 ( & V_5 -> V_35 ) ;
V_51:
F_36 ( & V_5 -> V_34 ) ;
F_52 () ;
F_40 ( & V_5 -> V_32 , V_5 -> V_6 ) ;
V_45:
F_26 ( V_5 -> V_25 ) ;
V_42:
F_25 ( V_5 -> V_27 ) ;
V_41:
F_25 ( V_5 ) ;
V_39:
return F_8 ( V_36 ) ;
}
struct V_19 * F_53 ( struct V_54 * V_23 ,
struct V_2 * V_12 ,
int V_55 )
{
struct V_19 * V_20 = NULL ;
F_54 (pdd, &p->per_device_data, per_device_list)
if ( V_20 -> V_23 == V_23 )
return V_20 ;
if ( V_55 ) {
V_20 = F_42 ( sizeof( * V_20 ) , V_38 ) ;
if ( V_20 != NULL ) {
V_20 -> V_23 = V_23 ;
F_48 ( & V_20 -> V_56 . V_57 ) ;
F_48 ( & V_20 -> V_56 . V_58 ) ;
V_20 -> V_56 . V_59 = V_23 -> V_59 ;
F_55 ( & V_20 -> V_26 , & V_12 -> V_50 ) ;
}
}
return V_20 ;
}
struct V_19 * F_56 ( struct V_54 * V_23 ,
struct V_2 * V_12 )
{
struct V_19 * V_20 = F_53 ( V_23 , V_12 , 1 ) ;
int V_36 ;
if ( V_20 == NULL )
return F_8 ( - V_37 ) ;
if ( V_20 -> V_60 )
return V_20 ;
V_36 = F_57 ( V_23 -> V_24 , V_12 -> V_25 , V_12 -> V_48 ) ;
if ( V_36 < 0 )
return F_8 ( V_36 ) ;
V_20 -> V_60 = true ;
return V_20 ;
}
void F_58 ( struct V_54 * V_23 , unsigned int V_25 )
{
struct V_2 * V_12 ;
struct V_19 * V_20 ;
int V_13 , V_61 ;
F_7 ( V_23 == NULL ) ;
V_13 = F_19 ( & V_14 ) ;
F_59 (kfd_processes_table, i, p, kfd_processes)
if ( V_12 -> V_25 == V_25 )
break;
F_20 ( & V_14 , V_13 ) ;
F_7 ( V_12 -> V_25 != V_25 ) ;
F_10 ( & V_12 -> V_22 ) ;
F_38 ( & V_12 -> V_35 ) ;
V_20 = F_53 ( V_23 , V_12 , 0 ) ;
if ( V_20 )
V_20 -> V_60 = false ;
F_14 ( & V_12 -> V_22 ) ;
}
struct V_19 * F_60 ( struct V_2 * V_12 )
{
return F_61 ( & V_12 -> V_50 ,
struct V_19 ,
V_26 ) ;
}
struct V_19 * F_62 ( struct V_2 * V_12 ,
struct V_19 * V_20 )
{
if ( F_63 ( & V_20 -> V_26 , & V_12 -> V_50 ) )
return NULL ;
return F_64 ( V_20 , V_26 ) ;
}
bool F_65 ( struct V_2 * V_12 )
{
return ! ( F_66 ( & V_12 -> V_50 ) ) ;
}
