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
if ( V_3 -> V_12 == V_13 ) {
if ( F_6 ( F_7 ( V_3 ) -> V_14 , V_7 -> V_15 ) )
V_3 -> V_12 = V_16 ;
}
if ( ! ( F_8 ( V_7 ) -> V_17 & V_18 ) ) {
unsigned int V_19 = V_3 -> V_20 - F_9 ( V_3 ) ;
F_10 ( V_3 , V_19 ) ;
V_3 = * V_2 = F_11 ( V_3 , V_3 -> V_4 ,
V_3 -> V_21 ) ;
if ( ! V_3 )
return false ;
F_12 ( V_3 , V_19 + V_22 ) ;
F_13 ( V_3 ) ;
}
V_3 -> V_23 = F_14 ( V_7 , V_3 -> V_21 ) ;
V_3 -> V_21 = 0 ;
V_9 = F_15 ( F_8 ( V_7 ) -> V_8 ) ;
F_16 ( & V_9 -> V_24 ) ;
V_9 -> V_25 ++ ;
V_9 -> V_26 += V_3 -> V_27 ;
if ( V_3 -> V_12 == V_28 )
V_9 -> V_29 ++ ;
F_17 ( & V_9 -> V_24 ) ;
return true ;
}
struct V_6 * F_18 ( struct V_6 * V_10 ,
T_1 V_4 , T_2 V_5 )
{
struct V_30 * V_30 = F_19 ( V_10 -> V_30 ) ;
if ( V_30 ) {
return F_20 ( & V_30 -> V_31 ,
V_4 , V_5 ) ;
} else {
struct V_6 * V_32 ;
V_32 = F_21 ( V_10 ) ;
if ( V_32 )
return F_18 ( V_32 ,
V_4 , V_5 ) ;
}
return NULL ;
}
struct V_6 * F_22 ( const struct V_6 * V_10 )
{
struct V_6 * V_33 = F_8 ( V_10 ) -> V_34 ;
while ( F_23 ( V_33 ) )
V_33 = F_8 ( V_33 ) -> V_34 ;
return V_33 ;
}
T_2 F_24 ( const struct V_6 * V_10 )
{
return F_8 ( V_10 ) -> V_5 ;
}
static struct V_1 * F_25 ( struct V_1 * V_3 )
{
if ( F_26 ( V_3 , F_27 ( V_3 ) ) < 0 )
return NULL ;
memmove ( V_3 -> V_20 - V_35 , V_3 -> V_20 - V_36 , 2 * V_37 ) ;
V_3 -> V_38 += V_22 ;
return V_3 ;
}
struct V_1 * F_28 ( struct V_1 * V_3 )
{
struct V_39 * V_40 ;
T_2 V_21 ;
if ( F_5 ( F_29 ( V_3 ) ) ) {
return V_3 ;
}
V_3 = F_4 ( V_3 , V_11 ) ;
if ( F_5 ( ! V_3 ) )
goto V_41;
if ( F_5 ( ! F_30 ( V_3 , V_22 ) ) )
goto V_41;
V_40 = (struct V_39 * ) V_3 -> V_20 ;
V_21 = F_31 ( V_40 -> V_42 ) ;
F_32 ( V_3 , V_3 -> V_43 , V_21 ) ;
F_33 ( V_3 , V_22 ) ;
F_34 ( V_3 , V_40 ) ;
V_3 = F_25 ( V_3 ) ;
if ( F_5 ( ! V_3 ) )
goto V_41;
F_35 ( V_3 ) ;
F_36 ( V_3 ) ;
F_13 ( V_3 ) ;
return V_3 ;
V_41:
F_37 ( V_3 ) ;
return NULL ;
}
static void F_38 ( struct V_44 * V_31 )
{
int V_45 , V_46 ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ )
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ )
F_39 ( V_31 -> V_49 [ V_45 ] [ V_46 ] ) ;
}
static void F_40 ( struct V_30 * V_30 )
{
F_38 ( & V_30 -> V_31 ) ;
F_39 ( V_30 ) ;
}
static void F_41 ( struct V_50 * V_51 )
{
F_40 ( F_42 ( V_51 , struct V_30 , V_51 ) ) ;
}
static struct V_30 * F_43 ( struct V_6 * V_10 )
{
struct V_30 * V_30 ;
V_30 = F_44 ( sizeof( struct V_30 ) , V_52 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_34 = V_10 ;
F_45 ( & V_30 -> V_53 ) ;
return V_30 ;
}
static bool F_46 ( const struct V_6 * V_10 ,
const struct V_54 * V_55 )
{
if ( V_55 -> V_56 == F_47 ( V_57 ) &&
V_10 -> V_58 & V_59 )
return true ;
if ( V_55 -> V_56 == F_47 ( V_60 ) &&
V_10 -> V_58 & V_61 )
return true ;
return false ;
}
static struct V_54 * F_48 ( struct V_30 * V_30 ,
T_1 V_56 , T_2 V_62 )
{
struct V_54 * V_55 ;
F_49 (vid_info, &vlan_info->vid_list, list) {
if ( V_55 -> V_56 == V_56 && V_55 -> V_62 == V_62 )
return V_55 ;
}
return NULL ;
}
static struct V_54 * F_50 ( T_1 V_56 , T_2 V_62 )
{
struct V_54 * V_55 ;
V_55 = F_44 ( sizeof( struct V_54 ) , V_52 ) ;
if ( ! V_55 )
return NULL ;
V_55 -> V_56 = V_56 ;
V_55 -> V_62 = V_62 ;
return V_55 ;
}
static int F_51 ( struct V_30 * V_30 , T_1 V_56 , T_2 V_62 ,
struct V_54 * * V_63 )
{
struct V_6 * V_10 = V_30 -> V_34 ;
const struct V_64 * V_65 = V_10 -> V_66 ;
struct V_54 * V_55 ;
int V_67 ;
V_55 = F_50 ( V_56 , V_62 ) ;
if ( ! V_55 )
return - V_68 ;
if ( F_46 ( V_10 , V_55 ) ) {
V_67 = V_65 -> V_69 ( V_10 , V_56 , V_62 ) ;
if ( V_67 ) {
F_39 ( V_55 ) ;
return V_67 ;
}
}
F_52 ( & V_55 -> V_70 , & V_30 -> V_53 ) ;
V_30 -> V_71 ++ ;
* V_63 = V_55 ;
return 0 ;
}
int F_53 ( struct V_6 * V_10 , T_1 V_56 , T_2 V_62 )
{
struct V_30 * V_30 ;
struct V_54 * V_55 ;
bool V_72 = false ;
int V_67 ;
F_54 () ;
V_30 = F_55 ( V_10 -> V_30 ) ;
if ( ! V_30 ) {
V_30 = F_43 ( V_10 ) ;
if ( ! V_30 )
return - V_68 ;
V_72 = true ;
}
V_55 = F_48 ( V_30 , V_56 , V_62 ) ;
if ( ! V_55 ) {
V_67 = F_51 ( V_30 , V_56 , V_62 , & V_55 ) ;
if ( V_67 )
goto V_73;
}
V_55 -> V_74 ++ ;
if ( V_72 )
F_56 ( V_10 -> V_30 , V_30 ) ;
return 0 ;
V_73:
if ( V_72 )
F_39 ( V_30 ) ;
return V_67 ;
}
static void F_57 ( struct V_30 * V_30 ,
struct V_54 * V_55 )
{
struct V_6 * V_10 = V_30 -> V_34 ;
const struct V_64 * V_65 = V_10 -> V_66 ;
T_1 V_56 = V_55 -> V_56 ;
T_2 V_62 = V_55 -> V_62 ;
int V_67 ;
if ( F_46 ( V_10 , V_55 ) ) {
V_67 = V_65 -> V_75 ( V_10 , V_56 , V_62 ) ;
if ( V_67 ) {
F_58 ( L_1 ,
V_56 , V_62 , V_10 -> V_76 ) ;
}
}
F_59 ( & V_55 -> V_70 ) ;
F_39 ( V_55 ) ;
V_30 -> V_71 -- ;
}
void F_60 ( struct V_6 * V_10 , T_1 V_56 , T_2 V_62 )
{
struct V_30 * V_30 ;
struct V_54 * V_55 ;
F_54 () ;
V_30 = F_55 ( V_10 -> V_30 ) ;
if ( ! V_30 )
return;
V_55 = F_48 ( V_30 , V_56 , V_62 ) ;
if ( ! V_55 )
return;
V_55 -> V_74 -- ;
if ( V_55 -> V_74 == 0 ) {
F_57 ( V_30 , V_55 ) ;
if ( V_30 -> V_71 == 0 ) {
F_61 ( V_10 -> V_30 , NULL ) ;
F_62 ( & V_30 -> V_51 , F_41 ) ;
}
}
}
int F_63 ( struct V_6 * V_10 ,
const struct V_6 * V_77 )
{
struct V_54 * V_55 ;
struct V_30 * V_30 ;
int V_67 ;
F_54 () ;
V_30 = F_55 ( V_77 -> V_30 ) ;
if ( ! V_30 )
return 0 ;
F_49 (vid_info, &vlan_info->vid_list, list) {
V_67 = F_53 ( V_10 , V_55 -> V_56 , V_55 -> V_62 ) ;
if ( V_67 )
goto V_78;
}
return 0 ;
V_78:
F_64 (vid_info,
&vlan_info->vid_list,
list) {
F_60 ( V_10 , V_55 -> V_56 , V_55 -> V_62 ) ;
}
return V_67 ;
}
void F_65 ( struct V_6 * V_10 ,
const struct V_6 * V_77 )
{
struct V_54 * V_55 ;
struct V_30 * V_30 ;
F_54 () ;
V_30 = F_55 ( V_77 -> V_30 ) ;
if ( ! V_30 )
return;
F_49 (vid_info, &vlan_info->vid_list, list)
F_60 ( V_10 , V_55 -> V_56 , V_55 -> V_62 ) ;
}
bool F_66 ( const struct V_6 * V_10 )
{
struct V_30 * V_30 ;
F_54 () ;
V_30 = F_55 ( V_10 -> V_30 ) ;
if ( ! V_30 )
return false ;
return V_30 -> V_31 . V_79 ? true : false ;
}
