static struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 ;
struct V_1 * V_8 = NULL ;
F_2 ( & V_5 -> V_9 ) ;
F_3 (irq, &dist->lpi_list_head, lpi_list) {
if ( V_8 -> V_3 != V_3 )
continue;
F_4 ( V_8 ) ;
goto V_10;
}
V_8 = NULL ;
V_10:
F_5 ( & V_5 -> V_9 ) ;
return V_8 ;
}
struct V_1 * F_6 ( struct V_2 * V_2 , struct V_11 * V_12 ,
T_1 V_3 )
{
if ( V_3 <= V_13 )
return & V_12 -> V_6 . V_14 . V_15 [ V_3 ] ;
if ( V_3 <= V_16 )
return & V_2 -> V_6 . V_7 . V_17 [ V_3 - V_18 ] ;
if ( V_3 >= V_19 )
return F_1 ( V_2 , V_3 ) ;
F_7 ( 1 , L_1 ) ;
return NULL ;
}
static void F_8 ( struct V_20 * V_21 )
{
}
void F_9 ( struct V_2 * V_2 , struct V_1 * V_8 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_7 ;
if ( V_8 -> V_3 < V_19 )
return;
F_2 ( & V_5 -> V_9 ) ;
if ( ! F_10 ( & V_8 -> V_22 , F_8 ) ) {
F_5 ( & V_5 -> V_9 ) ;
return;
} ;
F_11 ( & V_8 -> V_23 ) ;
V_5 -> V_24 -- ;
F_5 ( & V_5 -> V_9 ) ;
F_12 ( V_8 ) ;
}
static struct V_11 * F_13 ( struct V_1 * V_8 )
{
F_14 ( ! F_15 ( & V_8 -> V_25 ) ) ;
if ( V_8 -> V_26 )
return V_8 -> V_12 ? : V_8 -> V_27 ;
if ( V_8 -> V_28 && F_16 ( V_8 ) ) {
if ( F_17 ( V_8 -> V_27 &&
! V_8 -> V_27 -> V_2 -> V_6 . V_7 . V_28 ) )
return NULL ;
return V_8 -> V_27 ;
}
return NULL ;
}
static int F_18 ( void * V_29 , struct V_30 * V_31 , struct V_30 * V_32 )
{
struct V_1 * V_33 = F_19 ( V_31 , struct V_1 , V_34 ) ;
struct V_1 * V_35 = F_19 ( V_32 , struct V_1 , V_34 ) ;
bool V_36 , V_37 ;
int V_38 ;
F_2 ( & V_33 -> V_25 ) ;
F_20 ( & V_35 -> V_25 , V_39 ) ;
if ( V_33 -> V_26 || V_35 -> V_26 ) {
V_38 = ( int ) V_35 -> V_26 - ( int ) V_33 -> V_26 ;
goto V_40;
}
V_36 = V_33 -> V_28 && F_16 ( V_33 ) ;
V_37 = V_35 -> V_28 && F_16 ( V_35 ) ;
if ( ! V_36 || ! V_37 ) {
V_38 = ( int ) V_37 - ( int ) V_36 ;
goto V_40;
}
V_38 = V_33 -> V_41 - V_35 -> V_41 ;
V_40:
F_5 ( & V_35 -> V_25 ) ;
F_5 ( & V_33 -> V_25 ) ;
return V_38 ;
}
static void F_21 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
F_14 ( ! F_15 ( & V_14 -> V_42 ) ) ;
F_22 ( NULL , & V_14 -> V_43 , F_18 ) ;
}
static bool F_23 ( struct V_1 * V_8 , bool V_44 , void * V_45 )
{
if ( V_8 -> V_45 != V_45 )
return false ;
switch ( V_8 -> V_46 ) {
case V_47 :
return V_8 -> V_48 != V_44 ;
case V_49 :
return V_44 ;
}
return false ;
}
bool F_24 ( struct V_2 * V_2 , struct V_1 * V_8 )
{
struct V_11 * V_12 ;
F_14 ( ! F_15 ( & V_8 -> V_25 ) ) ;
V_50:
V_12 = F_13 ( V_8 ) ;
if ( V_8 -> V_12 || ! V_12 ) {
F_5 ( & V_8 -> V_25 ) ;
if ( V_12 ) {
F_25 ( V_51 , V_12 ) ;
F_26 ( V_12 ) ;
}
return false ;
}
F_5 ( & V_8 -> V_25 ) ;
F_2 ( & V_12 -> V_6 . V_14 . V_42 ) ;
F_2 ( & V_8 -> V_25 ) ;
if ( F_17 ( V_8 -> V_12 || V_12 != F_13 ( V_8 ) ) ) {
F_5 ( & V_8 -> V_25 ) ;
F_5 ( & V_12 -> V_6 . V_14 . V_42 ) ;
F_2 ( & V_8 -> V_25 ) ;
goto V_50;
}
F_4 ( V_8 ) ;
F_27 ( & V_8 -> V_34 , & V_12 -> V_6 . V_14 . V_43 ) ;
V_8 -> V_12 = V_12 ;
F_5 ( & V_8 -> V_25 ) ;
F_5 ( & V_12 -> V_6 . V_14 . V_42 ) ;
F_25 ( V_51 , V_12 ) ;
F_26 ( V_12 ) ;
return true ;
}
int F_28 ( struct V_2 * V_2 , int V_52 , unsigned int V_3 ,
bool V_44 , void * V_45 )
{
struct V_11 * V_12 ;
struct V_1 * V_8 ;
int V_38 ;
F_29 ( V_52 , V_3 , V_44 ) ;
V_38 = F_30 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_12 = F_31 ( V_2 , V_52 ) ;
if ( ! V_12 && V_3 < V_18 )
return - V_53 ;
V_8 = F_6 ( V_2 , V_12 , V_3 ) ;
if ( ! V_8 )
return - V_53 ;
F_2 ( & V_8 -> V_25 ) ;
if ( ! F_23 ( V_8 , V_44 , V_45 ) ) {
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_2 , V_8 ) ;
return 0 ;
}
if ( V_8 -> V_46 == V_47 )
V_8 -> V_48 = V_44 ;
else
V_8 -> V_54 = true ;
F_24 ( V_2 , V_8 ) ;
F_9 ( V_2 , V_8 ) ;
return 0 ;
}
int F_32 ( struct V_11 * V_12 , T_1 V_55 , T_1 V_56 )
{
struct V_1 * V_8 = F_6 ( V_12 -> V_2 , V_12 , V_55 ) ;
F_33 ( ! V_8 ) ;
F_2 ( & V_8 -> V_25 ) ;
V_8 -> V_57 = true ;
V_8 -> V_58 = V_56 ;
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_12 -> V_2 , V_8 ) ;
return 0 ;
}
int F_34 ( struct V_11 * V_12 , unsigned int V_55 )
{
struct V_1 * V_8 ;
if ( ! F_35 ( V_12 -> V_2 ) )
return - V_59 ;
V_8 = F_6 ( V_12 -> V_2 , V_12 , V_55 ) ;
F_33 ( ! V_8 ) ;
F_2 ( & V_8 -> V_25 ) ;
V_8 -> V_57 = false ;
V_8 -> V_58 = 0 ;
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_12 -> V_2 , V_8 ) ;
return 0 ;
}
int F_36 ( struct V_11 * V_12 , unsigned int V_3 , void * V_45 )
{
struct V_1 * V_8 ;
int V_38 = 0 ;
if ( ! F_35 ( V_12 -> V_2 ) )
return - V_59 ;
if ( ! F_37 ( V_3 ) && ! F_38 ( V_12 -> V_2 , V_3 ) )
return - V_53 ;
V_8 = F_6 ( V_12 -> V_2 , V_12 , V_3 ) ;
F_2 ( & V_8 -> V_25 ) ;
if ( V_8 -> V_45 && V_8 -> V_45 != V_45 )
V_38 = - V_60 ;
else
V_8 -> V_45 = V_45 ;
F_5 ( & V_8 -> V_25 ) ;
return V_38 ;
}
static void F_39 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 , * V_61 ;
V_50:
F_2 ( & V_14 -> V_42 ) ;
F_40 (irq, tmp, &vgic_cpu->ap_list_head, ap_list) {
struct V_11 * V_27 , * V_62 , * V_63 ;
F_2 ( & V_8 -> V_25 ) ;
F_33 ( V_12 != V_8 -> V_12 ) ;
V_27 = F_13 ( V_8 ) ;
if ( ! V_27 ) {
F_11 ( & V_8 -> V_34 ) ;
V_8 -> V_12 = NULL ;
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_12 -> V_2 , V_8 ) ;
continue;
}
if ( V_27 == V_12 ) {
F_5 ( & V_8 -> V_25 ) ;
continue;
}
F_5 ( & V_8 -> V_25 ) ;
F_5 ( & V_14 -> V_42 ) ;
if ( V_12 -> V_64 < V_27 -> V_64 ) {
V_62 = V_12 ;
V_63 = V_27 ;
} else {
V_62 = V_27 ;
V_63 = V_12 ;
}
F_2 ( & V_62 -> V_6 . V_14 . V_42 ) ;
F_20 ( & V_63 -> V_6 . V_14 . V_42 ,
V_39 ) ;
F_2 ( & V_8 -> V_25 ) ;
if ( V_27 == F_13 ( V_8 ) ) {
struct V_14 * V_65 = & V_27 -> V_6 . V_14 ;
F_11 ( & V_8 -> V_34 ) ;
V_8 -> V_12 = V_27 ;
F_27 ( & V_8 -> V_34 , & V_65 -> V_43 ) ;
}
F_5 ( & V_8 -> V_25 ) ;
F_5 ( & V_63 -> V_6 . V_14 . V_42 ) ;
F_5 ( & V_62 -> V_6 . V_14 . V_42 ) ;
goto V_50;
}
F_5 ( & V_14 -> V_42 ) ;
}
static inline void F_41 ( struct V_11 * V_12 )
{
if ( V_66 . type == V_67 )
F_42 ( V_12 ) ;
else
F_43 ( V_12 ) ;
}
static inline void F_44 ( struct V_11 * V_12 ,
struct V_1 * V_8 , int V_68 )
{
F_14 ( ! F_15 ( & V_8 -> V_25 ) ) ;
if ( V_66 . type == V_67 )
F_45 ( V_12 , V_8 , V_68 ) ;
else
F_46 ( V_12 , V_8 , V_68 ) ;
}
static inline void F_47 ( struct V_11 * V_12 , int V_68 )
{
if ( V_66 . type == V_67 )
F_48 ( V_12 , V_68 ) ;
else
F_49 ( V_12 , V_68 ) ;
}
static inline void F_50 ( struct V_11 * V_12 )
{
if ( V_66 . type == V_67 )
F_51 ( V_12 ) ;
else
F_52 ( V_12 ) ;
}
static int F_53 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 ;
int V_69 = 0 ;
F_14 ( ! F_15 ( & V_14 -> V_42 ) ) ;
F_3 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_2 ( & V_8 -> V_25 ) ;
if ( F_54 ( V_8 -> V_3 ) && V_8 -> V_70 )
V_69 += F_55 ( V_8 -> V_70 ) ;
else
V_69 ++ ;
F_5 ( & V_8 -> V_25 ) ;
}
return V_69 ;
}
static void F_56 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 ;
int V_69 = 0 ;
F_14 ( ! F_15 ( & V_14 -> V_42 ) ) ;
if ( F_53 ( V_12 ) > V_66 . V_71 )
F_21 ( V_12 ) ;
F_3 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_2 ( & V_8 -> V_25 ) ;
if ( F_17 ( F_13 ( V_8 ) != V_12 ) )
goto V_72;
do {
F_44 ( V_12 , V_8 , V_69 ++ ) ;
} while ( V_8 -> V_70 && V_69 < V_66 . V_71 );
V_72:
F_5 ( & V_8 -> V_25 ) ;
if ( V_69 == V_66 . V_71 ) {
if ( ! F_57 ( & V_8 -> V_34 ,
& V_14 -> V_43 ) )
F_50 ( V_12 ) ;
break;
}
}
V_12 -> V_6 . V_14 . V_73 = V_69 ;
for ( ; V_69 < V_66 . V_71 ; V_69 ++ )
F_47 ( V_12 , V_69 ) ;
}
void F_58 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
if ( F_59 ( & V_12 -> V_6 . V_14 . V_43 ) )
return;
if ( V_14 -> V_73 )
F_41 ( V_12 ) ;
F_39 ( V_12 ) ;
}
void F_60 ( struct V_11 * V_12 )
{
if ( F_59 ( & V_12 -> V_6 . V_14 . V_43 ) )
return;
F_2 ( & V_12 -> V_6 . V_14 . V_42 ) ;
F_56 ( V_12 ) ;
F_5 ( & V_12 -> V_6 . V_14 . V_42 ) ;
}
void F_61 ( struct V_11 * V_12 )
{
if ( F_17 ( ! F_35 ( V_12 -> V_2 ) ) )
return;
if ( V_66 . type == V_67 )
F_62 ( V_12 ) ;
else
F_63 ( V_12 ) ;
}
void F_64 ( struct V_11 * V_12 )
{
if ( F_17 ( ! F_35 ( V_12 -> V_2 ) ) )
return;
if ( V_66 . type == V_67 )
F_65 ( V_12 ) ;
else
F_66 ( V_12 ) ;
}
int F_67 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 ;
bool V_74 = false ;
if ( ! V_12 -> V_2 -> V_6 . V_7 . V_28 )
return false ;
F_2 ( & V_14 -> V_42 ) ;
F_3 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_2 ( & V_8 -> V_25 ) ;
V_74 = F_16 ( V_8 ) && V_8 -> V_28 ;
F_5 ( & V_8 -> V_25 ) ;
if ( V_74 )
break;
}
F_5 ( & V_14 -> V_42 ) ;
return V_74 ;
}
void F_68 ( struct V_2 * V_2 )
{
struct V_11 * V_12 ;
int V_75 ;
F_69 (c, vcpu, kvm) {
if ( F_67 ( V_12 ) ) {
F_25 ( V_51 , V_12 ) ;
F_26 ( V_12 ) ;
}
}
}
bool F_70 ( struct V_11 * V_12 , unsigned int V_55 )
{
struct V_1 * V_8 = F_6 ( V_12 -> V_2 , V_12 , V_55 ) ;
bool V_76 ;
F_2 ( & V_8 -> V_25 ) ;
V_76 = V_8 -> V_57 && V_8 -> V_26 ;
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_12 -> V_2 , V_8 ) ;
return V_76 ;
}
