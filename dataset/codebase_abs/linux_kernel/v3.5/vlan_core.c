bool F_1 ( struct V_1 * * V_2 , bool V_3 )
{
struct V_1 * V_4 = * V_2 ;
T_1 V_5 = V_4 -> V_6 & V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_9 = F_2 ( V_4 -> V_12 , V_5 ) ;
if ( ! V_9 ) {
if ( V_5 && V_3 )
V_4 -> V_13 = V_14 ;
return false ;
}
V_4 = * V_2 = F_3 ( V_4 , V_15 ) ;
if ( F_4 ( ! V_4 ) )
return false ;
V_4 -> V_12 = V_9 ;
if ( V_4 -> V_13 == V_14 ) {
if ( F_5 ( F_6 ( V_4 ) -> V_16 , V_9 -> V_17 ) )
V_4 -> V_13 = V_18 ;
}
if ( ! ( F_7 ( V_9 ) -> V_19 & V_20 ) ) {
unsigned int V_21 = V_4 -> V_22 - F_8 ( V_4 ) ;
F_9 ( V_4 , V_21 ) ;
V_4 = * V_2 = F_10 ( V_4 , V_4 -> V_6 ) ;
if ( ! V_4 )
return false ;
F_11 ( V_4 , V_21 + V_23 ) ;
F_12 ( V_4 ) ;
}
V_4 -> V_24 = F_13 ( V_9 , V_4 -> V_6 ) ;
V_4 -> V_6 = 0 ;
V_11 = F_14 ( F_7 ( V_9 ) -> V_10 ) ;
F_15 ( & V_11 -> V_25 ) ;
V_11 -> V_26 ++ ;
V_11 -> V_27 += V_4 -> V_28 ;
if ( V_4 -> V_13 == V_29 )
V_11 -> V_30 ++ ;
F_16 ( & V_11 -> V_25 ) ;
return true ;
}
struct V_8 * F_17 ( struct V_8 * V_31 ,
T_1 V_5 )
{
struct V_32 * V_32 = F_18 ( V_31 -> V_32 ) ;
if ( V_32 ) {
return F_19 ( & V_32 -> V_33 , V_5 ) ;
} else {
if ( F_20 ( V_31 ) )
return F_17 ( V_31 -> V_34 , V_5 ) ;
}
return NULL ;
}
struct V_8 * F_21 ( const struct V_8 * V_12 )
{
return F_7 ( V_12 ) -> V_31 ;
}
T_1 F_22 ( const struct V_8 * V_12 )
{
return F_7 ( V_12 ) -> V_5 ;
}
static struct V_1 * F_23 ( struct V_1 * V_4 )
{
if ( F_24 ( V_4 , F_25 ( V_4 ) ) < 0 )
return NULL ;
memmove ( V_4 -> V_22 - V_35 , V_4 -> V_22 - V_36 , 2 * V_37 ) ;
V_4 -> V_38 += V_23 ;
F_12 ( V_4 ) ;
return V_4 ;
}
struct V_1 * F_26 ( struct V_1 * V_4 )
{
struct V_39 * V_40 ;
T_1 V_6 ;
if ( F_4 ( F_27 ( V_4 ) ) ) {
return V_4 ;
}
V_4 = F_3 ( V_4 , V_15 ) ;
if ( F_4 ( ! V_4 ) )
goto V_41;
if ( F_4 ( ! F_28 ( V_4 , V_23 ) ) )
goto V_41;
V_40 = (struct V_39 * ) V_4 -> V_22 ;
V_6 = F_29 ( V_40 -> V_42 ) ;
F_30 ( V_4 , V_6 ) ;
F_31 ( V_4 , V_23 ) ;
F_32 ( V_4 , V_40 ) ;
V_4 = F_23 ( V_4 ) ;
if ( F_4 ( ! V_4 ) )
goto V_41;
F_33 ( V_4 ) ;
F_34 ( V_4 ) ;
return V_4 ;
V_41:
F_35 ( V_4 ) ;
return NULL ;
}
static void F_36 ( struct V_43 * V_33 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ )
F_37 ( V_33 -> V_46 [ V_44 ] ) ;
}
static void F_38 ( struct V_32 * V_32 )
{
F_36 ( & V_32 -> V_33 ) ;
F_37 ( V_32 ) ;
}
static void F_39 ( struct V_47 * V_48 )
{
F_38 ( F_40 ( V_48 , struct V_32 , V_48 ) ) ;
}
static struct V_32 * F_41 ( struct V_8 * V_12 )
{
struct V_32 * V_32 ;
V_32 = F_42 ( sizeof( struct V_32 ) , V_49 ) ;
if ( ! V_32 )
return NULL ;
V_32 -> V_31 = V_12 ;
F_43 ( & V_32 -> V_50 ) ;
return V_32 ;
}
static struct V_51 * F_44 ( struct V_32 * V_32 ,
unsigned short V_52 )
{
struct V_51 * V_53 ;
F_45 (vid_info, &vlan_info->vid_list, list) {
if ( V_53 -> V_52 == V_52 )
return V_53 ;
}
return NULL ;
}
static struct V_51 * F_46 ( unsigned short V_52 )
{
struct V_51 * V_53 ;
V_53 = F_42 ( sizeof( struct V_51 ) , V_49 ) ;
if ( ! V_53 )
return NULL ;
V_53 -> V_52 = V_52 ;
return V_53 ;
}
static int F_47 ( struct V_32 * V_32 , unsigned short V_52 ,
struct V_51 * * V_54 )
{
struct V_8 * V_12 = V_32 -> V_31 ;
const struct V_55 * V_56 = V_12 -> V_57 ;
struct V_51 * V_53 ;
int V_58 ;
V_53 = F_46 ( V_52 ) ;
if ( ! V_53 )
return - V_59 ;
if ( ( V_12 -> V_60 & V_61 ) &&
V_56 -> V_62 ) {
V_58 = V_56 -> V_62 ( V_12 , V_52 ) ;
if ( V_58 ) {
F_37 ( V_53 ) ;
return V_58 ;
}
}
F_48 ( & V_53 -> V_63 , & V_32 -> V_50 ) ;
V_32 -> V_64 ++ ;
* V_54 = V_53 ;
return 0 ;
}
int F_49 ( struct V_8 * V_12 , unsigned short V_52 )
{
struct V_32 * V_32 ;
struct V_51 * V_53 ;
bool V_65 = false ;
int V_58 ;
F_50 () ;
V_32 = F_51 ( V_12 -> V_32 ) ;
if ( ! V_32 ) {
V_32 = F_41 ( V_12 ) ;
if ( ! V_32 )
return - V_59 ;
V_65 = true ;
}
V_53 = F_44 ( V_32 , V_52 ) ;
if ( ! V_53 ) {
V_58 = F_47 ( V_32 , V_52 , & V_53 ) ;
if ( V_58 )
goto V_66;
}
V_53 -> V_67 ++ ;
if ( V_65 )
F_52 ( V_12 -> V_32 , V_32 ) ;
return 0 ;
V_66:
if ( V_65 )
F_37 ( V_32 ) ;
return V_58 ;
}
static void F_53 ( struct V_32 * V_32 ,
struct V_51 * V_53 )
{
struct V_8 * V_12 = V_32 -> V_31 ;
const struct V_55 * V_56 = V_12 -> V_57 ;
unsigned short V_52 = V_53 -> V_52 ;
int V_58 ;
if ( ( V_12 -> V_60 & V_61 ) &&
V_56 -> V_68 ) {
V_58 = V_56 -> V_68 ( V_12 , V_52 ) ;
if ( V_58 ) {
F_54 ( L_1 ,
V_52 , V_12 -> V_69 ) ;
}
}
F_55 ( & V_53 -> V_63 ) ;
F_37 ( V_53 ) ;
V_32 -> V_64 -- ;
}
void F_56 ( struct V_8 * V_12 , unsigned short V_52 )
{
struct V_32 * V_32 ;
struct V_51 * V_53 ;
F_50 () ;
V_32 = F_51 ( V_12 -> V_32 ) ;
if ( ! V_32 )
return;
V_53 = F_44 ( V_32 , V_52 ) ;
if ( ! V_53 )
return;
V_53 -> V_67 -- ;
if ( V_53 -> V_67 == 0 ) {
F_53 ( V_32 , V_53 ) ;
if ( V_32 -> V_64 == 0 ) {
F_57 ( V_12 -> V_32 , NULL ) ;
F_58 ( & V_32 -> V_48 , F_39 ) ;
}
}
}
int F_59 ( struct V_8 * V_12 ,
const struct V_8 * V_70 )
{
struct V_51 * V_53 ;
struct V_32 * V_32 ;
int V_58 ;
F_50 () ;
V_32 = F_51 ( V_70 -> V_32 ) ;
if ( ! V_32 )
return 0 ;
F_45 (vid_info, &vlan_info->vid_list, list) {
V_58 = F_49 ( V_12 , V_53 -> V_52 ) ;
if ( V_58 )
goto V_71;
}
return 0 ;
V_71:
F_60 (vid_info,
&vlan_info->vid_list,
list) {
F_56 ( V_12 , V_53 -> V_52 ) ;
}
return V_58 ;
}
void F_61 ( struct V_8 * V_12 ,
const struct V_8 * V_70 )
{
struct V_51 * V_53 ;
struct V_32 * V_32 ;
F_50 () ;
V_32 = F_51 ( V_70 -> V_32 ) ;
if ( ! V_32 )
return;
F_45 (vid_info, &vlan_info->vid_list, list)
F_56 ( V_12 , V_53 -> V_52 ) ;
}
