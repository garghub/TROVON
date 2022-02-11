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
F_12 ( L_3 ,
V_12 -> V_22 ) ;
F_10 ( & V_12 -> V_23 ) ;
F_22 (pdd, temp, &p->per_device_data,
per_device_list) {
F_12 ( L_4 ,
V_20 -> V_24 -> V_25 , V_12 -> V_22 ) ;
if ( V_20 -> V_26 )
F_23 ( V_20 -> V_24 , V_12 ) ;
F_24 ( V_20 -> V_24 -> V_27 , V_12 -> V_22 ) ;
F_25 ( & V_20 -> V_28 ) ;
F_26 ( V_20 ) ;
}
F_27 ( V_12 ) ;
F_28 ( V_12 -> V_22 ) ;
F_14 ( & V_12 -> V_23 ) ;
F_29 ( & V_12 -> V_23 ) ;
F_26 ( V_12 -> V_29 ) ;
F_26 ( V_12 ) ;
F_26 ( V_16 ) ;
}
static void F_30 ( struct V_30 * V_31 )
{
struct V_17 * V_16 ;
struct V_2 * V_12 ;
F_7 ( ! V_1 ) ;
V_12 = F_31 ( V_31 , struct V_2 , V_31 ) ;
F_7 ( F_32 ( & V_12 -> V_6 -> V_32 ) <= 0 ) ;
F_33 ( V_12 -> V_6 ) ;
V_16 = F_34 ( sizeof( struct V_17 ) , V_33 ) ;
if ( V_16 ) {
F_35 ( (struct V_15 * ) V_16 , F_21 ) ;
V_16 -> V_12 = V_12 ;
F_36 ( V_1 , (struct V_15 * ) V_16 ) ;
}
}
static void F_37 ( struct V_34 * V_35 ,
struct V_11 * V_6 )
{
struct V_2 * V_12 ;
struct V_19 * V_20 = NULL ;
V_12 = F_31 ( V_35 , struct V_2 , V_34 ) ;
F_7 ( V_12 -> V_6 != V_6 ) ;
F_10 ( & V_10 ) ;
F_38 ( & V_12 -> V_36 ) ;
F_14 ( & V_10 ) ;
F_39 ( & V_14 ) ;
F_10 ( & V_12 -> V_23 ) ;
F_40 ( & V_12 -> V_37 ) ;
F_41 (pdd, &p->per_device_data, per_device_list) {
if ( ( V_20 -> V_24 -> V_38 ) &&
( V_20 -> V_24 -> V_38 -> V_22 == V_12 -> V_22 ) )
F_42 ( V_20 -> V_24 -> V_38 ) ;
if ( V_20 -> V_26 ) {
F_43 ( L_5 ) ;
F_23 ( V_20 -> V_24 , V_12 ) ;
V_20 -> V_26 = false ;
}
}
F_14 ( & V_12 -> V_23 ) ;
F_44 ( & V_12 -> V_6 -> V_32 ) ;
F_45 ( & V_12 -> V_34 , V_12 -> V_6 ) ;
F_46 ( & V_12 -> V_31 , & F_30 ) ;
}
static struct V_2 * F_13 ( const struct V_3 * V_4 )
{
struct V_2 * V_5 ;
int V_39 = - V_40 ;
V_5 = F_47 ( sizeof( * V_5 ) , V_41 ) ;
if ( ! V_5 )
goto V_42;
V_5 -> V_29 = F_48 ( V_43 ,
sizeof( V_5 -> V_29 [ 0 ] ) , V_41 ) ;
if ( ! V_5 -> V_29 )
goto V_44;
V_5 -> V_22 = F_49 () ;
if ( V_5 -> V_22 == 0 )
goto V_45;
F_50 ( & V_5 -> V_23 ) ;
V_5 -> V_6 = V_4 -> V_6 ;
V_5 -> V_34 . V_46 = & V_47 ;
V_39 = F_51 ( & V_5 -> V_34 , V_5 -> V_6 ) ;
if ( V_39 )
goto V_48;
F_52 ( V_49 , & V_5 -> V_36 ,
( V_50 ) V_5 -> V_6 ) ;
V_5 -> V_51 = V_4 -> V_8 ;
V_5 -> V_52 = V_43 ;
F_53 ( & V_5 -> V_53 ) ;
F_54 ( V_5 ) ;
V_39 = F_55 ( & V_5 -> V_37 , V_5 ) ;
if ( V_39 != 0 )
goto V_54;
V_5 -> V_55 = F_56 () ;
if ( F_57 ( V_5 ) != 0 )
goto V_56;
return V_5 ;
V_56:
F_40 ( & V_5 -> V_37 ) ;
V_54:
F_38 ( & V_5 -> V_36 ) ;
F_58 () ;
F_45 ( & V_5 -> V_34 , V_5 -> V_6 ) ;
V_48:
F_28 ( V_5 -> V_22 ) ;
V_45:
F_26 ( V_5 -> V_29 ) ;
V_44:
F_26 ( V_5 ) ;
V_42:
return F_8 ( V_39 ) ;
}
struct V_19 * F_59 ( struct V_57 * V_24 ,
struct V_2 * V_12 )
{
struct V_19 * V_20 = NULL ;
F_41 (pdd, &p->per_device_data, per_device_list)
if ( V_20 -> V_24 == V_24 )
break;
return V_20 ;
}
struct V_19 * F_60 ( struct V_57 * V_24 ,
struct V_2 * V_12 )
{
struct V_19 * V_20 = NULL ;
V_20 = F_47 ( sizeof( * V_20 ) , V_41 ) ;
if ( V_20 != NULL ) {
V_20 -> V_24 = V_24 ;
F_53 ( & V_20 -> V_58 . V_59 ) ;
F_53 ( & V_20 -> V_58 . V_60 ) ;
V_20 -> V_58 . V_61 = V_24 -> V_61 ;
V_20 -> V_26 = false ;
F_61 ( & V_20 -> V_28 , & V_12 -> V_53 ) ;
}
return V_20 ;
}
struct V_19 * F_62 ( struct V_57 * V_24 ,
struct V_2 * V_12 )
{
struct V_19 * V_20 ;
int V_39 ;
V_20 = F_59 ( V_24 , V_12 ) ;
if ( ! V_20 ) {
F_63 ( L_6 ) ;
return F_8 ( - V_40 ) ;
}
if ( V_20 -> V_62 )
return V_20 ;
V_39 = F_64 ( V_24 -> V_27 , V_12 -> V_22 , V_12 -> V_51 ) ;
if ( V_39 < 0 )
return F_8 ( V_39 ) ;
V_20 -> V_62 = true ;
return V_20 ;
}
void F_65 ( struct V_57 * V_24 , unsigned int V_22 )
{
struct V_2 * V_12 ;
struct V_19 * V_20 ;
int V_13 , V_63 ;
F_7 ( V_24 == NULL ) ;
V_13 = F_19 ( & V_14 ) ;
F_66 (kfd_processes_table, i, p, kfd_processes)
if ( V_12 -> V_22 == V_22 ) {
F_20 ( & V_14 , V_13 ) ;
F_12 ( L_7 , V_22 ) ;
F_10 ( & V_12 -> V_23 ) ;
if ( ( V_24 -> V_38 ) && ( V_24 -> V_38 -> V_22 == V_12 -> V_22 ) )
F_42 ( V_24 -> V_38 ) ;
F_40 ( & V_12 -> V_37 ) ;
V_20 = F_59 ( V_24 , V_12 ) ;
if ( ! V_20 ) {
F_14 ( & V_12 -> V_23 ) ;
return;
}
if ( V_20 -> V_26 ) {
F_23 ( V_20 -> V_24 , V_12 ) ;
V_20 -> V_26 = false ;
}
V_20 -> V_62 = false ;
F_14 ( & V_12 -> V_23 ) ;
return;
}
F_20 ( & V_14 , V_13 ) ;
}
struct V_19 * F_67 ( struct V_2 * V_12 )
{
return F_68 ( & V_12 -> V_53 ,
struct V_19 ,
V_28 ) ;
}
struct V_19 * F_69 ( struct V_2 * V_12 ,
struct V_19 * V_20 )
{
if ( F_70 ( & V_20 -> V_28 , & V_12 -> V_53 ) )
return NULL ;
return F_71 ( V_20 , V_28 ) ;
}
bool F_72 ( struct V_2 * V_12 )
{
return ! ( F_73 ( & V_12 -> V_53 ) ) ;
}
struct V_2 * F_74 ( unsigned int V_22 )
{
struct V_2 * V_12 ;
unsigned int V_21 ;
int V_13 = F_19 ( & V_14 ) ;
F_66 (kfd_processes_table, temp, p, kfd_processes) {
if ( V_12 -> V_22 == V_22 ) {
F_10 ( & V_12 -> V_23 ) ;
break;
}
}
F_20 ( & V_14 , V_13 ) ;
return V_12 ;
}
