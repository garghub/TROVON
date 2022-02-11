bool F_1 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = * V_2 ;
T_1 V_4 = V_3 -> V_4 ;
T_2 V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_3 ( V_3 -> V_10 , V_4 , V_5 ) ;
if ( ! V_7 )
return false ;
V_3 = * V_2 = F_4 ( V_3 , V_11 ) ;
if ( F_5 ( ! V_3 ) )
return false ;
if ( F_5 ( ! ( V_7 -> V_12 & V_13 ) ) ) {
F_6 ( V_3 ) ;
* V_2 = NULL ;
return false ;
}
V_3 -> V_10 = V_7 ;
if ( F_5 ( V_3 -> V_14 == V_15 ) ) {
if ( F_7 ( F_8 ( V_3 ) -> V_16 , V_7 -> V_17 ) )
V_3 -> V_14 = V_18 ;
}
if ( ! ( F_9 ( V_7 ) -> V_12 & V_19 ) &&
! F_10 ( V_7 ) &&
! F_11 ( V_7 ) ) {
unsigned int V_20 = V_3 -> V_21 - F_12 ( V_3 ) ;
F_13 ( V_3 , V_20 ) ;
V_3 = * V_2 = F_14 ( V_3 , V_3 -> V_4 ,
V_3 -> V_22 ) ;
if ( ! V_3 )
return false ;
F_15 ( V_3 , V_20 + V_23 ) ;
F_16 ( V_3 ) ;
}
V_3 -> V_24 = F_17 ( V_7 , V_3 -> V_22 ) ;
V_3 -> V_22 = 0 ;
V_9 = F_18 ( F_9 ( V_7 ) -> V_8 ) ;
F_19 ( & V_9 -> V_25 ) ;
V_9 -> V_26 ++ ;
V_9 -> V_27 += V_3 -> V_28 ;
if ( V_3 -> V_14 == V_29 )
V_9 -> V_30 ++ ;
F_20 ( & V_9 -> V_25 ) ;
return true ;
}
struct V_6 * F_21 ( struct V_6 * V_10 ,
T_1 V_4 , T_2 V_5 )
{
struct V_31 * V_31 = F_22 ( V_10 -> V_31 ) ;
if ( V_31 ) {
return F_23 ( & V_31 -> V_32 ,
V_4 , V_5 ) ;
} else {
struct V_6 * V_33 ;
V_33 = F_24 ( V_10 ) ;
if ( V_33 )
return F_21 ( V_33 ,
V_4 , V_5 ) ;
}
return NULL ;
}
struct V_6 * F_25 ( const struct V_6 * V_10 )
{
struct V_6 * V_34 = F_9 ( V_10 ) -> V_35 ;
while ( F_26 ( V_34 ) )
V_34 = F_9 ( V_34 ) -> V_35 ;
return V_34 ;
}
T_2 F_27 ( const struct V_6 * V_10 )
{
return F_9 ( V_10 ) -> V_5 ;
}
T_1 F_28 ( const struct V_6 * V_10 )
{
return F_9 ( V_10 ) -> V_4 ;
}
static void F_29 ( struct V_36 * V_32 )
{
int V_37 , V_38 ;
for ( V_37 = 0 ; V_37 < V_39 ; V_37 ++ )
for ( V_38 = 0 ; V_38 < V_40 ; V_38 ++ )
F_30 ( V_32 -> V_41 [ V_37 ] [ V_38 ] ) ;
}
static void F_31 ( struct V_31 * V_31 )
{
F_29 ( & V_31 -> V_32 ) ;
F_30 ( V_31 ) ;
}
static void F_32 ( struct V_42 * V_43 )
{
F_31 ( F_33 ( V_43 , struct V_31 , V_43 ) ) ;
}
static struct V_31 * F_34 ( struct V_6 * V_10 )
{
struct V_31 * V_31 ;
V_31 = F_35 ( sizeof( struct V_31 ) , V_44 ) ;
if ( ! V_31 )
return NULL ;
V_31 -> V_35 = V_10 ;
F_36 ( & V_31 -> V_45 ) ;
return V_31 ;
}
static bool F_37 ( const struct V_6 * V_10 ,
const struct V_46 * V_47 )
{
if ( V_47 -> V_48 == F_38 ( V_49 ) &&
V_10 -> V_50 & V_51 )
return true ;
if ( V_47 -> V_48 == F_38 ( V_52 ) &&
V_10 -> V_50 & V_53 )
return true ;
return false ;
}
static struct V_46 * F_39 ( struct V_31 * V_31 ,
T_1 V_48 , T_2 V_54 )
{
struct V_46 * V_47 ;
F_40 (vid_info, &vlan_info->vid_list, list) {
if ( V_47 -> V_48 == V_48 && V_47 -> V_54 == V_54 )
return V_47 ;
}
return NULL ;
}
static struct V_46 * F_41 ( T_1 V_48 , T_2 V_54 )
{
struct V_46 * V_47 ;
V_47 = F_35 ( sizeof( struct V_46 ) , V_44 ) ;
if ( ! V_47 )
return NULL ;
V_47 -> V_48 = V_48 ;
V_47 -> V_54 = V_54 ;
return V_47 ;
}
static int F_42 ( struct V_31 * V_31 , T_1 V_48 , T_2 V_54 ,
struct V_46 * * V_55 )
{
struct V_6 * V_10 = V_31 -> V_35 ;
const struct V_56 * V_57 = V_10 -> V_58 ;
struct V_46 * V_47 ;
int V_59 ;
V_47 = F_41 ( V_48 , V_54 ) ;
if ( ! V_47 )
return - V_60 ;
if ( F_37 ( V_10 , V_47 ) ) {
if ( F_43 ( V_10 ) )
V_59 = V_57 -> V_61 ( V_10 , V_48 , V_54 ) ;
else
V_59 = - V_62 ;
if ( V_59 ) {
F_30 ( V_47 ) ;
return V_59 ;
}
}
F_44 ( & V_47 -> V_63 , & V_31 -> V_45 ) ;
V_31 -> V_64 ++ ;
* V_55 = V_47 ;
return 0 ;
}
int F_45 ( struct V_6 * V_10 , T_1 V_48 , T_2 V_54 )
{
struct V_31 * V_31 ;
struct V_46 * V_47 ;
bool V_65 = false ;
int V_59 ;
F_46 () ;
V_31 = F_47 ( V_10 -> V_31 ) ;
if ( ! V_31 ) {
V_31 = F_34 ( V_10 ) ;
if ( ! V_31 )
return - V_60 ;
V_65 = true ;
}
V_47 = F_39 ( V_31 , V_48 , V_54 ) ;
if ( ! V_47 ) {
V_59 = F_42 ( V_31 , V_48 , V_54 , & V_47 ) ;
if ( V_59 )
goto V_66;
}
V_47 -> V_67 ++ ;
if ( V_65 )
F_48 ( V_10 -> V_31 , V_31 ) ;
return 0 ;
V_66:
if ( V_65 )
F_30 ( V_31 ) ;
return V_59 ;
}
static void F_49 ( struct V_31 * V_31 ,
struct V_46 * V_47 )
{
struct V_6 * V_10 = V_31 -> V_35 ;
const struct V_56 * V_57 = V_10 -> V_58 ;
T_1 V_48 = V_47 -> V_48 ;
T_2 V_54 = V_47 -> V_54 ;
int V_59 ;
if ( F_37 ( V_10 , V_47 ) ) {
if ( F_43 ( V_10 ) )
V_59 = V_57 -> V_68 ( V_10 , V_48 , V_54 ) ;
else
V_59 = - V_62 ;
if ( V_59 ) {
F_50 ( L_1 ,
V_48 , V_54 , V_10 -> V_69 ) ;
}
}
F_51 ( & V_47 -> V_63 ) ;
F_30 ( V_47 ) ;
V_31 -> V_64 -- ;
}
void F_52 ( struct V_6 * V_10 , T_1 V_48 , T_2 V_54 )
{
struct V_31 * V_31 ;
struct V_46 * V_47 ;
F_46 () ;
V_31 = F_47 ( V_10 -> V_31 ) ;
if ( ! V_31 )
return;
V_47 = F_39 ( V_31 , V_48 , V_54 ) ;
if ( ! V_47 )
return;
V_47 -> V_67 -- ;
if ( V_47 -> V_67 == 0 ) {
F_49 ( V_31 , V_47 ) ;
if ( V_31 -> V_64 == 0 ) {
F_53 ( V_10 -> V_31 , NULL ) ;
F_54 ( & V_31 -> V_43 , F_32 ) ;
}
}
}
int F_55 ( struct V_6 * V_10 ,
const struct V_6 * V_70 )
{
struct V_46 * V_47 ;
struct V_31 * V_31 ;
int V_59 ;
F_46 () ;
V_31 = F_47 ( V_70 -> V_31 ) ;
if ( ! V_31 )
return 0 ;
F_40 (vid_info, &vlan_info->vid_list, list) {
V_59 = F_45 ( V_10 , V_47 -> V_48 , V_47 -> V_54 ) ;
if ( V_59 )
goto V_71;
}
return 0 ;
V_71:
F_56 (vid_info,
&vlan_info->vid_list,
list) {
F_52 ( V_10 , V_47 -> V_48 , V_47 -> V_54 ) ;
}
return V_59 ;
}
void F_57 ( struct V_6 * V_10 ,
const struct V_6 * V_70 )
{
struct V_46 * V_47 ;
struct V_31 * V_31 ;
F_46 () ;
V_31 = F_47 ( V_70 -> V_31 ) ;
if ( ! V_31 )
return;
F_40 (vid_info, &vlan_info->vid_list, list)
F_52 ( V_10 , V_47 -> V_48 , V_47 -> V_54 ) ;
}
bool F_58 ( const struct V_6 * V_10 )
{
struct V_31 * V_31 ;
F_46 () ;
V_31 = F_47 ( V_10 -> V_31 ) ;
if ( ! V_31 )
return false ;
return V_31 -> V_32 . V_72 ? true : false ;
}
