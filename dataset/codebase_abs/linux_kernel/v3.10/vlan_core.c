bool F_1 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = * V_2 ;
T_1 V_4 = V_3 -> V_4 ;
T_2 V_5 = V_3 -> V_6 & V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_9 = F_2 ( V_3 -> V_12 , V_4 , V_5 ) ;
if ( ! V_9 )
return false ;
V_3 = * V_2 = F_3 ( V_3 , V_13 ) ;
if ( F_4 ( ! V_3 ) )
return false ;
V_3 -> V_12 = V_9 ;
if ( V_3 -> V_14 == V_15 ) {
if ( F_5 ( F_6 ( V_3 ) -> V_16 , V_9 -> V_17 ) )
V_3 -> V_14 = V_18 ;
}
if ( ! ( F_7 ( V_9 ) -> V_19 & V_20 ) ) {
unsigned int V_21 = V_3 -> V_22 - F_8 ( V_3 ) ;
F_9 ( V_3 , V_21 ) ;
V_3 = * V_2 = F_10 ( V_3 , V_3 -> V_4 ,
V_3 -> V_6 ) ;
if ( ! V_3 )
return false ;
F_11 ( V_3 , V_21 + V_23 ) ;
F_12 ( V_3 ) ;
}
V_3 -> V_24 = F_13 ( V_9 , V_3 -> V_6 ) ;
V_3 -> V_6 = 0 ;
V_11 = F_14 ( F_7 ( V_9 ) -> V_10 ) ;
F_15 ( & V_11 -> V_25 ) ;
V_11 -> V_26 ++ ;
V_11 -> V_27 += V_3 -> V_28 ;
if ( V_3 -> V_14 == V_29 )
V_11 -> V_30 ++ ;
F_16 ( & V_11 -> V_25 ) ;
return true ;
}
struct V_8 * F_17 ( struct V_8 * V_12 ,
T_1 V_4 , T_2 V_5 )
{
struct V_31 * V_31 = F_18 ( V_12 -> V_31 ) ;
if ( V_31 ) {
return F_19 ( & V_31 -> V_32 ,
V_4 , V_5 ) ;
} else {
struct V_8 * V_33 ;
V_33 = F_20 ( V_12 ) ;
if ( V_33 )
return F_17 ( V_33 ,
V_4 , V_5 ) ;
}
return NULL ;
}
struct V_8 * F_21 ( const struct V_8 * V_12 )
{
return F_7 ( V_12 ) -> V_34 ;
}
T_2 F_22 ( const struct V_8 * V_12 )
{
return F_7 ( V_12 ) -> V_5 ;
}
static struct V_1 * F_23 ( struct V_1 * V_3 )
{
if ( F_24 ( V_3 , F_25 ( V_3 ) ) < 0 )
return NULL ;
memmove ( V_3 -> V_22 - V_35 , V_3 -> V_22 - V_36 , 2 * V_37 ) ;
V_3 -> V_38 += V_23 ;
return V_3 ;
}
struct V_1 * F_26 ( struct V_1 * V_3 )
{
struct V_39 * V_40 ;
T_2 V_6 ;
if ( F_4 ( F_27 ( V_3 ) ) ) {
return V_3 ;
}
V_3 = F_3 ( V_3 , V_13 ) ;
if ( F_4 ( ! V_3 ) )
goto V_41;
if ( F_4 ( ! F_28 ( V_3 , V_23 ) ) )
goto V_41;
V_40 = (struct V_39 * ) V_3 -> V_22 ;
V_6 = F_29 ( V_40 -> V_42 ) ;
F_30 ( V_3 , V_3 -> V_43 , V_6 ) ;
F_31 ( V_3 , V_23 ) ;
F_32 ( V_3 , V_40 ) ;
V_3 = F_23 ( V_3 ) ;
if ( F_4 ( ! V_3 ) )
goto V_41;
F_33 ( V_3 ) ;
F_34 ( V_3 ) ;
F_12 ( V_3 ) ;
return V_3 ;
V_41:
F_35 ( V_3 ) ;
return NULL ;
}
static void F_36 ( struct V_44 * V_32 )
{
int V_45 , V_46 ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ )
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ )
F_37 ( V_32 -> V_49 [ V_45 ] [ V_46 ] ) ;
}
static void F_38 ( struct V_31 * V_31 )
{
F_36 ( & V_31 -> V_32 ) ;
F_37 ( V_31 ) ;
}
static void F_39 ( struct V_50 * V_51 )
{
F_38 ( F_40 ( V_51 , struct V_31 , V_51 ) ) ;
}
static struct V_31 * F_41 ( struct V_8 * V_12 )
{
struct V_31 * V_31 ;
V_31 = F_42 ( sizeof( struct V_31 ) , V_52 ) ;
if ( ! V_31 )
return NULL ;
V_31 -> V_34 = V_12 ;
F_43 ( & V_31 -> V_53 ) ;
return V_31 ;
}
static bool F_44 ( const struct V_8 * V_12 ,
const struct V_54 * V_55 )
{
if ( V_55 -> V_56 == F_45 ( V_57 ) &&
V_12 -> V_58 & V_59 )
return true ;
if ( V_55 -> V_56 == F_45 ( V_60 ) &&
V_12 -> V_58 & V_61 )
return true ;
return false ;
}
static struct V_54 * F_46 ( struct V_31 * V_31 ,
T_1 V_56 , T_2 V_62 )
{
struct V_54 * V_55 ;
F_47 (vid_info, &vlan_info->vid_list, list) {
if ( V_55 -> V_56 == V_56 && V_55 -> V_62 == V_62 )
return V_55 ;
}
return NULL ;
}
static struct V_54 * F_48 ( T_1 V_56 , T_2 V_62 )
{
struct V_54 * V_55 ;
V_55 = F_42 ( sizeof( struct V_54 ) , V_52 ) ;
if ( ! V_55 )
return NULL ;
V_55 -> V_56 = V_56 ;
V_55 -> V_62 = V_62 ;
return V_55 ;
}
static int F_49 ( struct V_31 * V_31 , T_1 V_56 , T_2 V_62 ,
struct V_54 * * V_63 )
{
struct V_8 * V_12 = V_31 -> V_34 ;
const struct V_64 * V_65 = V_12 -> V_66 ;
struct V_54 * V_55 ;
int V_67 ;
V_55 = F_48 ( V_56 , V_62 ) ;
if ( ! V_55 )
return - V_68 ;
if ( F_44 ( V_12 , V_55 ) ) {
V_67 = V_65 -> V_69 ( V_12 , V_56 , V_62 ) ;
if ( V_67 ) {
F_37 ( V_55 ) ;
return V_67 ;
}
}
F_50 ( & V_55 -> V_70 , & V_31 -> V_53 ) ;
V_31 -> V_71 ++ ;
* V_63 = V_55 ;
return 0 ;
}
int F_51 ( struct V_8 * V_12 , T_1 V_56 , T_2 V_62 )
{
struct V_31 * V_31 ;
struct V_54 * V_55 ;
bool V_72 = false ;
int V_67 ;
F_52 () ;
V_31 = F_53 ( V_12 -> V_31 ) ;
if ( ! V_31 ) {
V_31 = F_41 ( V_12 ) ;
if ( ! V_31 )
return - V_68 ;
V_72 = true ;
}
V_55 = F_46 ( V_31 , V_56 , V_62 ) ;
if ( ! V_55 ) {
V_67 = F_49 ( V_31 , V_56 , V_62 , & V_55 ) ;
if ( V_67 )
goto V_73;
}
V_55 -> V_74 ++ ;
if ( V_72 )
F_54 ( V_12 -> V_31 , V_31 ) ;
return 0 ;
V_73:
if ( V_72 )
F_37 ( V_31 ) ;
return V_67 ;
}
static void F_55 ( struct V_31 * V_31 ,
struct V_54 * V_55 )
{
struct V_8 * V_12 = V_31 -> V_34 ;
const struct V_64 * V_65 = V_12 -> V_66 ;
T_1 V_56 = V_55 -> V_56 ;
T_2 V_62 = V_55 -> V_62 ;
int V_67 ;
if ( F_44 ( V_12 , V_55 ) ) {
V_67 = V_65 -> V_75 ( V_12 , V_56 , V_62 ) ;
if ( V_67 ) {
F_56 ( L_1 ,
V_56 , V_62 , V_12 -> V_76 ) ;
}
}
F_57 ( & V_55 -> V_70 ) ;
F_37 ( V_55 ) ;
V_31 -> V_71 -- ;
}
void F_58 ( struct V_8 * V_12 , T_1 V_56 , T_2 V_62 )
{
struct V_31 * V_31 ;
struct V_54 * V_55 ;
F_52 () ;
V_31 = F_53 ( V_12 -> V_31 ) ;
if ( ! V_31 )
return;
V_55 = F_46 ( V_31 , V_56 , V_62 ) ;
if ( ! V_55 )
return;
V_55 -> V_74 -- ;
if ( V_55 -> V_74 == 0 ) {
F_55 ( V_31 , V_55 ) ;
if ( V_31 -> V_71 == 0 ) {
F_59 ( V_12 -> V_31 , NULL ) ;
F_60 ( & V_31 -> V_51 , F_39 ) ;
}
}
}
int F_61 ( struct V_8 * V_12 ,
const struct V_8 * V_77 )
{
struct V_54 * V_55 ;
struct V_31 * V_31 ;
int V_67 ;
F_52 () ;
V_31 = F_53 ( V_77 -> V_31 ) ;
if ( ! V_31 )
return 0 ;
F_47 (vid_info, &vlan_info->vid_list, list) {
V_67 = F_51 ( V_12 , V_55 -> V_56 , V_55 -> V_62 ) ;
if ( V_67 )
goto V_78;
}
return 0 ;
V_78:
F_62 (vid_info,
&vlan_info->vid_list,
list) {
F_58 ( V_12 , V_55 -> V_56 , V_55 -> V_62 ) ;
}
return V_67 ;
}
void F_63 ( struct V_8 * V_12 ,
const struct V_8 * V_77 )
{
struct V_54 * V_55 ;
struct V_31 * V_31 ;
F_52 () ;
V_31 = F_53 ( V_77 -> V_31 ) ;
if ( ! V_31 )
return;
F_47 (vid_info, &vlan_info->vid_list, list)
F_58 ( V_12 , V_55 -> V_56 , V_55 -> V_62 ) ;
}
bool F_64 ( const struct V_8 * V_12 )
{
struct V_31 * V_31 ;
F_52 () ;
V_31 = F_53 ( V_12 -> V_31 ) ;
if ( ! V_31 )
return false ;
return V_31 -> V_32 . V_79 ? true : false ;
}
