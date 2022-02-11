void F_1 ( void )
{
if ( ! V_1 )
V_1 = F_2 ( L_1 , 0 , 0 ) ;
}
void F_3 ( void )
{
if ( V_1 ) {
F_4 ( V_1 ) ;
V_1 = NULL ;
}
}
struct V_2 * F_5 ( const struct V_3 * V_4 )
{
struct V_2 * V_5 ;
F_6 ( ! V_1 ) ;
if ( V_4 -> V_6 == NULL )
return F_7 ( - V_7 ) ;
if ( V_4 -> V_8 -> V_6 != V_4 -> V_6 )
return F_7 ( - V_7 ) ;
F_8 ( & V_4 -> V_6 -> V_9 ) ;
F_9 ( & V_10 ) ;
V_5 = F_10 ( V_4 ) ;
if ( V_5 )
F_11 ( L_2 ) ;
if ( ! V_5 )
V_5 = F_12 ( V_4 ) ;
F_13 ( & V_10 ) ;
F_14 ( & V_4 -> V_6 -> V_9 ) ;
return V_5 ;
}
struct V_2 * F_15 ( const struct V_3 * V_4 )
{
struct V_2 * V_5 ;
if ( V_4 -> V_6 == NULL )
return F_7 ( - V_7 ) ;
if ( V_4 -> V_8 -> V_6 != V_4 -> V_6 )
return F_7 ( - V_7 ) ;
V_5 = F_10 ( V_4 ) ;
return V_5 ;
}
static struct V_2 * F_16 ( const struct V_11 * V_6 )
{
struct V_2 * V_5 ;
F_17 (kfd_processes_table, process,
kfd_processes, (uintptr_t)mm)
if ( V_5 -> V_6 == V_6 )
return V_5 ;
return NULL ;
}
static struct V_2 * F_10 ( const struct V_3 * V_4 )
{
struct V_2 * V_12 ;
int V_13 ;
V_13 = F_18 ( & V_14 ) ;
V_12 = F_16 ( V_4 -> V_6 ) ;
F_19 ( & V_14 , V_13 ) ;
return V_12 ;
}
static void F_20 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 , * V_21 ;
struct V_2 * V_12 ;
V_18 = (struct V_17 * ) V_16 ;
V_12 = V_18 -> V_12 ;
F_11 ( L_3 ,
V_12 -> V_22 ) ;
F_9 ( & V_12 -> V_23 ) ;
F_21 (pdd, temp, &p->per_device_data,
per_device_list) {
F_11 ( L_4 ,
V_20 -> V_24 -> V_25 , V_12 -> V_22 ) ;
if ( V_20 -> V_26 )
F_22 ( V_20 -> V_24 , V_12 ) ;
F_23 ( V_20 -> V_24 -> V_27 , V_12 -> V_22 ) ;
F_24 ( & V_20 -> V_28 ) ;
F_25 ( V_20 ) ;
}
F_26 ( V_12 ) ;
F_27 ( V_12 -> V_22 ) ;
F_13 ( & V_12 -> V_23 ) ;
F_28 ( & V_12 -> V_23 ) ;
F_25 ( V_12 -> V_29 ) ;
F_25 ( V_12 ) ;
F_25 ( V_16 ) ;
}
static void F_29 ( struct V_30 * V_31 )
{
struct V_17 * V_16 ;
struct V_2 * V_12 ;
F_6 ( ! V_1 ) ;
V_12 = F_30 ( V_31 , struct V_2 , V_31 ) ;
F_6 ( F_31 ( & V_12 -> V_6 -> V_32 ) <= 0 ) ;
F_32 ( V_12 -> V_6 ) ;
V_16 = F_33 ( sizeof( struct V_17 ) , V_33 ) ;
if ( V_16 ) {
F_34 ( (struct V_15 * ) V_16 , F_20 ) ;
V_16 -> V_12 = V_12 ;
F_35 ( V_1 , (struct V_15 * ) V_16 ) ;
}
}
static void F_36 ( struct V_34 * V_35 ,
struct V_11 * V_6 )
{
struct V_2 * V_12 ;
struct V_19 * V_20 = NULL ;
V_12 = F_30 ( V_35 , struct V_2 , V_34 ) ;
F_6 ( V_12 -> V_6 != V_6 ) ;
F_9 ( & V_10 ) ;
F_37 ( & V_12 -> V_36 ) ;
F_13 ( & V_10 ) ;
F_38 ( & V_14 ) ;
F_9 ( & V_12 -> V_23 ) ;
F_39 ( & V_12 -> V_37 ) ;
F_40 (pdd, &p->per_device_data, per_device_list) {
if ( ( V_20 -> V_24 -> V_38 ) &&
( V_20 -> V_24 -> V_38 -> V_22 == V_12 -> V_22 ) )
F_41 ( V_20 -> V_24 -> V_38 ) ;
if ( V_20 -> V_26 ) {
F_42 ( L_5 ) ;
F_22 ( V_20 -> V_24 , V_12 ) ;
V_20 -> V_26 = false ;
}
}
F_13 ( & V_12 -> V_23 ) ;
F_43 ( V_12 -> V_6 ) ;
F_44 ( & V_12 -> V_34 , V_12 -> V_6 ) ;
F_45 ( & V_12 -> V_31 , & F_29 ) ;
}
static struct V_2 * F_12 ( const struct V_3 * V_4 )
{
struct V_2 * V_5 ;
int V_39 = - V_40 ;
V_5 = F_46 ( sizeof( * V_5 ) , V_41 ) ;
if ( ! V_5 )
goto V_42;
V_5 -> V_29 = F_47 ( V_43 ,
sizeof( V_5 -> V_29 [ 0 ] ) , V_41 ) ;
if ( ! V_5 -> V_29 )
goto V_44;
V_5 -> V_22 = F_48 () ;
if ( V_5 -> V_22 == 0 )
goto V_45;
F_49 ( & V_5 -> V_23 ) ;
V_5 -> V_6 = V_4 -> V_6 ;
V_5 -> V_34 . V_46 = & V_47 ;
V_39 = F_50 ( & V_5 -> V_34 , V_5 -> V_6 ) ;
if ( V_39 )
goto V_48;
F_51 ( V_49 , & V_5 -> V_36 ,
( V_50 ) V_5 -> V_6 ) ;
V_5 -> V_51 = V_4 -> V_8 ;
V_5 -> V_52 = V_43 ;
F_52 ( & V_5 -> V_53 ) ;
F_53 ( V_5 ) ;
V_39 = F_54 ( & V_5 -> V_37 , V_5 ) ;
if ( V_39 != 0 )
goto V_54;
V_5 -> V_55 = F_55 () ;
if ( F_56 ( V_5 ) != 0 )
goto V_56;
return V_5 ;
V_56:
F_39 ( & V_5 -> V_37 ) ;
V_54:
F_37 ( & V_5 -> V_36 ) ;
F_57 () ;
F_44 ( & V_5 -> V_34 , V_5 -> V_6 ) ;
V_48:
F_28 ( & V_5 -> V_23 ) ;
F_27 ( V_5 -> V_22 ) ;
V_45:
F_25 ( V_5 -> V_29 ) ;
V_44:
F_25 ( V_5 ) ;
V_42:
return F_7 ( V_39 ) ;
}
struct V_19 * F_58 ( struct V_57 * V_24 ,
struct V_2 * V_12 )
{
struct V_19 * V_20 = NULL ;
F_40 (pdd, &p->per_device_data, per_device_list)
if ( V_20 -> V_24 == V_24 )
break;
return V_20 ;
}
struct V_19 * F_59 ( struct V_57 * V_24 ,
struct V_2 * V_12 )
{
struct V_19 * V_20 = NULL ;
V_20 = F_46 ( sizeof( * V_20 ) , V_41 ) ;
if ( V_20 != NULL ) {
V_20 -> V_24 = V_24 ;
F_52 ( & V_20 -> V_58 . V_59 ) ;
F_52 ( & V_20 -> V_58 . V_60 ) ;
V_20 -> V_58 . V_61 = V_24 -> V_61 ;
V_20 -> V_26 = false ;
F_60 ( & V_20 -> V_28 , & V_12 -> V_53 ) ;
}
return V_20 ;
}
struct V_19 * F_61 ( struct V_57 * V_24 ,
struct V_2 * V_12 )
{
struct V_19 * V_20 ;
int V_39 ;
V_20 = F_58 ( V_24 , V_12 ) ;
if ( ! V_20 ) {
F_62 ( L_6 ) ;
return F_7 ( - V_40 ) ;
}
if ( V_20 -> V_62 )
return V_20 ;
V_39 = F_63 ( V_24 -> V_27 , V_12 -> V_22 , V_12 -> V_51 ) ;
if ( V_39 < 0 )
return F_7 ( V_39 ) ;
V_20 -> V_62 = true ;
return V_20 ;
}
void F_64 ( struct V_57 * V_24 , unsigned int V_22 )
{
struct V_2 * V_12 ;
struct V_19 * V_20 ;
F_6 ( V_24 == NULL ) ;
V_12 = F_65 ( V_22 ) ;
if ( ! V_12 )
return;
F_11 ( L_7 , V_22 ) ;
if ( ( V_24 -> V_38 ) && ( V_24 -> V_38 -> V_22 == V_12 -> V_22 ) )
F_41 ( V_24 -> V_38 ) ;
F_39 ( & V_12 -> V_37 ) ;
V_20 = F_58 ( V_24 , V_12 ) ;
if ( ! V_20 ) {
F_13 ( & V_12 -> V_23 ) ;
return;
}
if ( V_20 -> V_26 ) {
F_22 ( V_20 -> V_24 , V_12 ) ;
V_20 -> V_26 = false ;
}
V_20 -> V_62 = false ;
F_13 ( & V_12 -> V_23 ) ;
}
struct V_19 * F_66 ( struct V_2 * V_12 )
{
return F_67 ( & V_12 -> V_53 ,
struct V_19 ,
V_28 ) ;
}
struct V_19 * F_68 ( struct V_2 * V_12 ,
struct V_19 * V_20 )
{
if ( F_69 ( & V_20 -> V_28 , & V_12 -> V_53 ) )
return NULL ;
return F_70 ( V_20 , V_28 ) ;
}
bool F_71 ( struct V_2 * V_12 )
{
return ! ( F_72 ( & V_12 -> V_53 ) ) ;
}
struct V_2 * F_65 ( unsigned int V_22 )
{
struct V_2 * V_12 ;
unsigned int V_21 ;
int V_13 = F_18 ( & V_14 ) ;
F_73 (kfd_processes_table, temp, p, kfd_processes) {
if ( V_12 -> V_22 == V_22 ) {
F_9 ( & V_12 -> V_23 ) ;
break;
}
}
F_19 ( & V_14 , V_13 ) ;
return V_12 ;
}
