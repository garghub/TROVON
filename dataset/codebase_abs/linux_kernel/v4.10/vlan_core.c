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
V_3 -> V_10 = V_7 ;
if ( F_5 ( V_3 -> V_12 == V_13 ) ) {
if ( F_6 ( F_7 ( V_3 ) -> V_14 , V_7 -> V_15 ) )
V_3 -> V_12 = V_16 ;
}
if ( ! ( F_8 ( V_7 ) -> V_17 & V_18 ) &&
! F_9 ( V_7 ) &&
! F_10 ( V_7 ) ) {
unsigned int V_19 = V_3 -> V_20 - F_11 ( V_3 ) ;
F_12 ( V_3 , V_19 ) ;
V_3 = * V_2 = F_13 ( V_3 , V_3 -> V_4 ,
V_3 -> V_21 ) ;
if ( ! V_3 )
return false ;
F_14 ( V_3 , V_19 + V_22 ) ;
F_15 ( V_3 ) ;
}
V_3 -> V_23 = F_16 ( V_7 , V_3 -> V_21 ) ;
V_3 -> V_21 = 0 ;
V_9 = F_17 ( F_8 ( V_7 ) -> V_8 ) ;
F_18 ( & V_9 -> V_24 ) ;
V_9 -> V_25 ++ ;
V_9 -> V_26 += V_3 -> V_27 ;
if ( V_3 -> V_12 == V_28 )
V_9 -> V_29 ++ ;
F_19 ( & V_9 -> V_24 ) ;
return true ;
}
struct V_6 * F_20 ( struct V_6 * V_10 ,
T_1 V_4 , T_2 V_5 )
{
struct V_30 * V_30 = F_21 ( V_10 -> V_30 ) ;
if ( V_30 ) {
return F_22 ( & V_30 -> V_31 ,
V_4 , V_5 ) ;
} else {
struct V_6 * V_32 ;
V_32 = F_23 ( V_10 ) ;
if ( V_32 )
return F_20 ( V_32 ,
V_4 , V_5 ) ;
}
return NULL ;
}
struct V_6 * F_24 ( const struct V_6 * V_10 )
{
struct V_6 * V_33 = F_8 ( V_10 ) -> V_34 ;
while ( F_25 ( V_33 ) )
V_33 = F_8 ( V_33 ) -> V_34 ;
return V_33 ;
}
T_2 F_26 ( const struct V_6 * V_10 )
{
return F_8 ( V_10 ) -> V_5 ;
}
T_1 F_27 ( const struct V_6 * V_10 )
{
return F_8 ( V_10 ) -> V_4 ;
}
static void F_28 ( struct V_35 * V_31 )
{
int V_36 , V_37 ;
for ( V_36 = 0 ; V_36 < V_38 ; V_36 ++ )
for ( V_37 = 0 ; V_37 < V_39 ; V_37 ++ )
F_29 ( V_31 -> V_40 [ V_36 ] [ V_37 ] ) ;
}
static void F_30 ( struct V_30 * V_30 )
{
F_28 ( & V_30 -> V_31 ) ;
F_29 ( V_30 ) ;
}
static void F_31 ( struct V_41 * V_42 )
{
F_30 ( F_32 ( V_42 , struct V_30 , V_42 ) ) ;
}
static struct V_30 * F_33 ( struct V_6 * V_10 )
{
struct V_30 * V_30 ;
V_30 = F_34 ( sizeof( struct V_30 ) , V_43 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_34 = V_10 ;
F_35 ( & V_30 -> V_44 ) ;
return V_30 ;
}
static bool F_36 ( const struct V_6 * V_10 ,
const struct V_45 * V_46 )
{
if ( V_46 -> V_47 == F_37 ( V_48 ) &&
V_10 -> V_49 & V_50 )
return true ;
if ( V_46 -> V_47 == F_37 ( V_51 ) &&
V_10 -> V_49 & V_52 )
return true ;
return false ;
}
static struct V_45 * F_38 ( struct V_30 * V_30 ,
T_1 V_47 , T_2 V_53 )
{
struct V_45 * V_46 ;
F_39 (vid_info, &vlan_info->vid_list, list) {
if ( V_46 -> V_47 == V_47 && V_46 -> V_53 == V_53 )
return V_46 ;
}
return NULL ;
}
static struct V_45 * F_40 ( T_1 V_47 , T_2 V_53 )
{
struct V_45 * V_46 ;
V_46 = F_34 ( sizeof( struct V_45 ) , V_43 ) ;
if ( ! V_46 )
return NULL ;
V_46 -> V_47 = V_47 ;
V_46 -> V_53 = V_53 ;
return V_46 ;
}
static int F_41 ( struct V_30 * V_30 , T_1 V_47 , T_2 V_53 ,
struct V_45 * * V_54 )
{
struct V_6 * V_10 = V_30 -> V_34 ;
const struct V_55 * V_56 = V_10 -> V_57 ;
struct V_45 * V_46 ;
int V_58 ;
V_46 = F_40 ( V_47 , V_53 ) ;
if ( ! V_46 )
return - V_59 ;
if ( F_36 ( V_10 , V_46 ) ) {
if ( F_42 ( V_10 ) )
V_58 = V_56 -> V_60 ( V_10 , V_47 , V_53 ) ;
else
V_58 = - V_61 ;
if ( V_58 ) {
F_29 ( V_46 ) ;
return V_58 ;
}
}
F_43 ( & V_46 -> V_62 , & V_30 -> V_44 ) ;
V_30 -> V_63 ++ ;
* V_54 = V_46 ;
return 0 ;
}
int F_44 ( struct V_6 * V_10 , T_1 V_47 , T_2 V_53 )
{
struct V_30 * V_30 ;
struct V_45 * V_46 ;
bool V_64 = false ;
int V_58 ;
F_45 () ;
V_30 = F_46 ( V_10 -> V_30 ) ;
if ( ! V_30 ) {
V_30 = F_33 ( V_10 ) ;
if ( ! V_30 )
return - V_59 ;
V_64 = true ;
}
V_46 = F_38 ( V_30 , V_47 , V_53 ) ;
if ( ! V_46 ) {
V_58 = F_41 ( V_30 , V_47 , V_53 , & V_46 ) ;
if ( V_58 )
goto V_65;
}
V_46 -> V_66 ++ ;
if ( V_64 )
F_47 ( V_10 -> V_30 , V_30 ) ;
return 0 ;
V_65:
if ( V_64 )
F_29 ( V_30 ) ;
return V_58 ;
}
static void F_48 ( struct V_30 * V_30 ,
struct V_45 * V_46 )
{
struct V_6 * V_10 = V_30 -> V_34 ;
const struct V_55 * V_56 = V_10 -> V_57 ;
T_1 V_47 = V_46 -> V_47 ;
T_2 V_53 = V_46 -> V_53 ;
int V_58 ;
if ( F_36 ( V_10 , V_46 ) ) {
if ( F_42 ( V_10 ) )
V_58 = V_56 -> V_67 ( V_10 , V_47 , V_53 ) ;
else
V_58 = - V_61 ;
if ( V_58 ) {
F_49 ( L_1 ,
V_47 , V_53 , V_10 -> V_68 ) ;
}
}
F_50 ( & V_46 -> V_62 ) ;
F_29 ( V_46 ) ;
V_30 -> V_63 -- ;
}
void F_51 ( struct V_6 * V_10 , T_1 V_47 , T_2 V_53 )
{
struct V_30 * V_30 ;
struct V_45 * V_46 ;
F_45 () ;
V_30 = F_46 ( V_10 -> V_30 ) ;
if ( ! V_30 )
return;
V_46 = F_38 ( V_30 , V_47 , V_53 ) ;
if ( ! V_46 )
return;
V_46 -> V_66 -- ;
if ( V_46 -> V_66 == 0 ) {
F_48 ( V_30 , V_46 ) ;
if ( V_30 -> V_63 == 0 ) {
F_52 ( V_10 -> V_30 , NULL ) ;
F_53 ( & V_30 -> V_42 , F_31 ) ;
}
}
}
int F_54 ( struct V_6 * V_10 ,
const struct V_6 * V_69 )
{
struct V_45 * V_46 ;
struct V_30 * V_30 ;
int V_58 ;
F_45 () ;
V_30 = F_46 ( V_69 -> V_30 ) ;
if ( ! V_30 )
return 0 ;
F_39 (vid_info, &vlan_info->vid_list, list) {
V_58 = F_44 ( V_10 , V_46 -> V_47 , V_46 -> V_53 ) ;
if ( V_58 )
goto V_70;
}
return 0 ;
V_70:
F_55 (vid_info,
&vlan_info->vid_list,
list) {
F_51 ( V_10 , V_46 -> V_47 , V_46 -> V_53 ) ;
}
return V_58 ;
}
void F_56 ( struct V_6 * V_10 ,
const struct V_6 * V_69 )
{
struct V_45 * V_46 ;
struct V_30 * V_30 ;
F_45 () ;
V_30 = F_46 ( V_69 -> V_30 ) ;
if ( ! V_30 )
return;
F_39 (vid_info, &vlan_info->vid_list, list)
F_51 ( V_10 , V_46 -> V_47 , V_46 -> V_53 ) ;
}
bool F_57 ( const struct V_6 * V_10 )
{
struct V_30 * V_30 ;
F_45 () ;
V_30 = F_46 ( V_10 -> V_30 ) ;
if ( ! V_30 )
return false ;
return V_30 -> V_31 . V_71 ? true : false ;
}
