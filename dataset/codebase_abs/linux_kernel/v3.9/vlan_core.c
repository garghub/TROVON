bool F_1 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = * V_2 ;
T_1 V_4 = V_3 -> V_5 & V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_8 = F_2 ( V_3 -> V_11 , V_4 ) ;
if ( ! V_8 )
return false ;
V_3 = * V_2 = F_3 ( V_3 , V_12 ) ;
if ( F_4 ( ! V_3 ) )
return false ;
V_3 -> V_11 = V_8 ;
if ( V_3 -> V_13 == V_14 ) {
if ( F_5 ( F_6 ( V_3 ) -> V_15 , V_8 -> V_16 ) )
V_3 -> V_13 = V_17 ;
}
if ( ! ( F_7 ( V_8 ) -> V_18 & V_19 ) ) {
unsigned int V_20 = V_3 -> V_21 - F_8 ( V_3 ) ;
F_9 ( V_3 , V_20 ) ;
V_3 = * V_2 = F_10 ( V_3 , V_3 -> V_5 ) ;
if ( ! V_3 )
return false ;
F_11 ( V_3 , V_20 + V_22 ) ;
F_12 ( V_3 ) ;
}
V_3 -> V_23 = F_13 ( V_8 , V_3 -> V_5 ) ;
V_3 -> V_5 = 0 ;
V_10 = F_14 ( F_7 ( V_8 ) -> V_9 ) ;
F_15 ( & V_10 -> V_24 ) ;
V_10 -> V_25 ++ ;
V_10 -> V_26 += V_3 -> V_27 ;
if ( V_3 -> V_13 == V_28 )
V_10 -> V_29 ++ ;
F_16 ( & V_10 -> V_24 ) ;
return true ;
}
struct V_7 * F_17 ( struct V_7 * V_11 ,
T_1 V_4 )
{
struct V_30 * V_30 = F_18 ( V_11 -> V_30 ) ;
if ( V_30 ) {
return F_19 ( & V_30 -> V_31 , V_4 ) ;
} else {
struct V_7 * V_32 ;
V_32 = F_20 ( V_11 ) ;
if ( V_32 )
return F_17 ( V_32 , V_4 ) ;
}
return NULL ;
}
struct V_7 * F_21 ( const struct V_7 * V_11 )
{
return F_7 ( V_11 ) -> V_33 ;
}
T_1 F_22 ( const struct V_7 * V_11 )
{
return F_7 ( V_11 ) -> V_4 ;
}
static struct V_1 * F_23 ( struct V_1 * V_3 )
{
if ( F_24 ( V_3 , F_25 ( V_3 ) ) < 0 )
return NULL ;
memmove ( V_3 -> V_21 - V_34 , V_3 -> V_21 - V_35 , 2 * V_36 ) ;
V_3 -> V_37 += V_22 ;
return V_3 ;
}
struct V_1 * F_26 ( struct V_1 * V_3 )
{
struct V_38 * V_39 ;
T_1 V_5 ;
if ( F_4 ( F_27 ( V_3 ) ) ) {
return V_3 ;
}
V_3 = F_3 ( V_3 , V_12 ) ;
if ( F_4 ( ! V_3 ) )
goto V_40;
if ( F_4 ( ! F_28 ( V_3 , V_22 ) ) )
goto V_40;
V_39 = (struct V_38 * ) V_3 -> V_21 ;
V_5 = F_29 ( V_39 -> V_41 ) ;
F_30 ( V_3 , V_5 ) ;
F_31 ( V_3 , V_22 ) ;
F_32 ( V_3 , V_39 ) ;
V_3 = F_23 ( V_3 ) ;
if ( F_4 ( ! V_3 ) )
goto V_40;
F_33 ( V_3 ) ;
F_34 ( V_3 ) ;
F_12 ( V_3 ) ;
return V_3 ;
V_40:
F_35 ( V_3 ) ;
return NULL ;
}
static void F_36 ( struct V_42 * V_31 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ )
F_37 ( V_31 -> V_45 [ V_43 ] ) ;
}
static void F_38 ( struct V_30 * V_30 )
{
F_36 ( & V_30 -> V_31 ) ;
F_37 ( V_30 ) ;
}
static void F_39 ( struct V_46 * V_47 )
{
F_38 ( F_40 ( V_47 , struct V_30 , V_47 ) ) ;
}
static struct V_30 * F_41 ( struct V_7 * V_11 )
{
struct V_30 * V_30 ;
V_30 = F_42 ( sizeof( struct V_30 ) , V_48 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_33 = V_11 ;
F_43 ( & V_30 -> V_49 ) ;
return V_30 ;
}
static struct V_50 * F_44 ( struct V_30 * V_30 ,
unsigned short V_51 )
{
struct V_50 * V_52 ;
F_45 (vid_info, &vlan_info->vid_list, list) {
if ( V_52 -> V_51 == V_51 )
return V_52 ;
}
return NULL ;
}
static struct V_50 * F_46 ( unsigned short V_51 )
{
struct V_50 * V_52 ;
V_52 = F_42 ( sizeof( struct V_50 ) , V_48 ) ;
if ( ! V_52 )
return NULL ;
V_52 -> V_51 = V_51 ;
return V_52 ;
}
static int F_47 ( struct V_30 * V_30 , unsigned short V_51 ,
struct V_50 * * V_53 )
{
struct V_7 * V_11 = V_30 -> V_33 ;
const struct V_54 * V_55 = V_11 -> V_56 ;
struct V_50 * V_52 ;
int V_57 ;
V_52 = F_46 ( V_51 ) ;
if ( ! V_52 )
return - V_58 ;
if ( V_11 -> V_59 & V_60 ) {
V_57 = V_55 -> V_61 ( V_11 , V_51 ) ;
if ( V_57 ) {
F_37 ( V_52 ) ;
return V_57 ;
}
}
F_48 ( & V_52 -> V_62 , & V_30 -> V_49 ) ;
V_30 -> V_63 ++ ;
* V_53 = V_52 ;
return 0 ;
}
int F_49 ( struct V_7 * V_11 , unsigned short V_51 )
{
struct V_30 * V_30 ;
struct V_50 * V_52 ;
bool V_64 = false ;
int V_57 ;
F_50 () ;
V_30 = F_51 ( V_11 -> V_30 ) ;
if ( ! V_30 ) {
V_30 = F_41 ( V_11 ) ;
if ( ! V_30 )
return - V_58 ;
V_64 = true ;
}
V_52 = F_44 ( V_30 , V_51 ) ;
if ( ! V_52 ) {
V_57 = F_47 ( V_30 , V_51 , & V_52 ) ;
if ( V_57 )
goto V_65;
}
V_52 -> V_66 ++ ;
if ( V_64 )
F_52 ( V_11 -> V_30 , V_30 ) ;
return 0 ;
V_65:
if ( V_64 )
F_37 ( V_30 ) ;
return V_57 ;
}
static void F_53 ( struct V_30 * V_30 ,
struct V_50 * V_52 )
{
struct V_7 * V_11 = V_30 -> V_33 ;
const struct V_54 * V_55 = V_11 -> V_56 ;
unsigned short V_51 = V_52 -> V_51 ;
int V_57 ;
if ( V_11 -> V_59 & V_60 ) {
V_57 = V_55 -> V_67 ( V_11 , V_51 ) ;
if ( V_57 ) {
F_54 ( L_1 ,
V_51 , V_11 -> V_68 ) ;
}
}
F_55 ( & V_52 -> V_62 ) ;
F_37 ( V_52 ) ;
V_30 -> V_63 -- ;
}
void F_56 ( struct V_7 * V_11 , unsigned short V_51 )
{
struct V_30 * V_30 ;
struct V_50 * V_52 ;
F_50 () ;
V_30 = F_51 ( V_11 -> V_30 ) ;
if ( ! V_30 )
return;
V_52 = F_44 ( V_30 , V_51 ) ;
if ( ! V_52 )
return;
V_52 -> V_66 -- ;
if ( V_52 -> V_66 == 0 ) {
F_53 ( V_30 , V_52 ) ;
if ( V_30 -> V_63 == 0 ) {
F_57 ( V_11 -> V_30 , NULL ) ;
F_58 ( & V_30 -> V_47 , F_39 ) ;
}
}
}
int F_59 ( struct V_7 * V_11 ,
const struct V_7 * V_69 )
{
struct V_50 * V_52 ;
struct V_30 * V_30 ;
int V_57 ;
F_50 () ;
V_30 = F_51 ( V_69 -> V_30 ) ;
if ( ! V_30 )
return 0 ;
F_45 (vid_info, &vlan_info->vid_list, list) {
V_57 = F_49 ( V_11 , V_52 -> V_51 ) ;
if ( V_57 )
goto V_70;
}
return 0 ;
V_70:
F_60 (vid_info,
&vlan_info->vid_list,
list) {
F_56 ( V_11 , V_52 -> V_51 ) ;
}
return V_57 ;
}
void F_61 ( struct V_7 * V_11 ,
const struct V_7 * V_69 )
{
struct V_50 * V_52 ;
struct V_30 * V_30 ;
F_50 () ;
V_30 = F_51 ( V_69 -> V_30 ) ;
if ( ! V_30 )
return;
F_45 (vid_info, &vlan_info->vid_list, list)
F_56 ( V_11 , V_52 -> V_51 ) ;
}
bool F_62 ( const struct V_7 * V_11 )
{
struct V_30 * V_30 ;
F_50 () ;
V_30 = F_51 ( V_11 -> V_30 ) ;
if ( ! V_30 )
return false ;
return V_30 -> V_31 . V_71 ? true : false ;
}
