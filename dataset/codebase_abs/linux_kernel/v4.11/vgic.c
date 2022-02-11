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
static bool F_23 ( struct V_1 * V_8 , bool V_44 )
{
switch ( V_8 -> V_45 ) {
case V_46 :
return V_8 -> V_47 != V_44 ;
case V_48 :
return V_44 ;
}
return false ;
}
bool F_24 ( struct V_2 * V_2 , struct V_1 * V_8 )
{
struct V_11 * V_12 ;
F_14 ( ! F_15 ( & V_8 -> V_25 ) ) ;
V_49:
V_12 = F_13 ( V_8 ) ;
if ( V_8 -> V_12 || ! V_12 ) {
F_5 ( & V_8 -> V_25 ) ;
if ( V_12 )
F_25 ( V_12 ) ;
return false ;
}
F_5 ( & V_8 -> V_25 ) ;
F_2 ( & V_12 -> V_6 . V_14 . V_42 ) ;
F_2 ( & V_8 -> V_25 ) ;
if ( F_17 ( V_8 -> V_12 || V_12 != F_13 ( V_8 ) ) ) {
F_5 ( & V_8 -> V_25 ) ;
F_5 ( & V_12 -> V_6 . V_14 . V_42 ) ;
F_2 ( & V_8 -> V_25 ) ;
goto V_49;
}
F_4 ( V_8 ) ;
F_26 ( & V_8 -> V_34 , & V_12 -> V_6 . V_14 . V_43 ) ;
V_8 -> V_12 = V_12 ;
F_5 ( & V_8 -> V_25 ) ;
F_5 ( & V_12 -> V_6 . V_14 . V_42 ) ;
F_25 ( V_12 ) ;
return true ;
}
int F_27 ( struct V_2 * V_2 , int V_50 , unsigned int V_3 ,
bool V_44 )
{
struct V_11 * V_12 ;
struct V_1 * V_8 ;
int V_38 ;
F_28 ( V_50 , V_3 , V_44 ) ;
V_38 = F_29 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_12 = F_30 ( V_2 , V_50 ) ;
if ( ! V_12 && V_3 < V_18 )
return - V_51 ;
V_8 = F_6 ( V_2 , V_12 , V_3 ) ;
if ( ! V_8 )
return - V_51 ;
F_2 ( & V_8 -> V_25 ) ;
if ( ! F_23 ( V_8 , V_44 ) ) {
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_2 , V_8 ) ;
return 0 ;
}
if ( V_8 -> V_45 == V_46 )
V_8 -> V_47 = V_44 ;
else
V_8 -> V_52 = true ;
F_24 ( V_2 , V_8 ) ;
F_9 ( V_2 , V_8 ) ;
return 0 ;
}
int F_31 ( struct V_11 * V_12 , T_1 V_53 , T_1 V_54 )
{
struct V_1 * V_8 = F_6 ( V_12 -> V_2 , V_12 , V_53 ) ;
F_32 ( ! V_8 ) ;
F_2 ( & V_8 -> V_25 ) ;
V_8 -> V_55 = true ;
V_8 -> V_56 = V_54 ;
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_12 -> V_2 , V_8 ) ;
return 0 ;
}
int F_33 ( struct V_11 * V_12 , unsigned int V_53 )
{
struct V_1 * V_8 ;
if ( ! F_34 ( V_12 -> V_2 ) )
return - V_57 ;
V_8 = F_6 ( V_12 -> V_2 , V_12 , V_53 ) ;
F_32 ( ! V_8 ) ;
F_2 ( & V_8 -> V_25 ) ;
V_8 -> V_55 = false ;
V_8 -> V_56 = 0 ;
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_12 -> V_2 , V_8 ) ;
return 0 ;
}
static void F_35 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 , * V_58 ;
V_49:
F_2 ( & V_14 -> V_42 ) ;
F_36 (irq, tmp, &vgic_cpu->ap_list_head, ap_list) {
struct V_11 * V_27 , * V_59 , * V_60 ;
F_2 ( & V_8 -> V_25 ) ;
F_32 ( V_12 != V_8 -> V_12 ) ;
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
if ( V_12 -> V_61 < V_27 -> V_61 ) {
V_59 = V_12 ;
V_60 = V_27 ;
} else {
V_59 = V_27 ;
V_60 = V_12 ;
}
F_2 ( & V_59 -> V_6 . V_14 . V_42 ) ;
F_20 ( & V_60 -> V_6 . V_14 . V_42 ,
V_39 ) ;
F_2 ( & V_8 -> V_25 ) ;
if ( V_27 == F_13 ( V_8 ) ) {
struct V_14 * V_62 = & V_27 -> V_6 . V_14 ;
F_11 ( & V_8 -> V_34 ) ;
V_8 -> V_12 = V_27 ;
F_26 ( & V_8 -> V_34 , & V_62 -> V_43 ) ;
}
F_5 ( & V_8 -> V_25 ) ;
F_5 ( & V_60 -> V_6 . V_14 . V_42 ) ;
F_5 ( & V_59 -> V_6 . V_14 . V_42 ) ;
goto V_49;
}
F_5 ( & V_14 -> V_42 ) ;
}
static inline void F_37 ( struct V_11 * V_12 )
{
if ( V_63 . type == V_64 )
F_38 ( V_12 ) ;
else
F_39 ( V_12 ) ;
}
static inline void F_40 ( struct V_11 * V_12 )
{
if ( V_63 . type == V_64 )
F_41 ( V_12 ) ;
else
F_42 ( V_12 ) ;
}
static inline void F_43 ( struct V_11 * V_12 ,
struct V_1 * V_8 , int V_65 )
{
F_14 ( ! F_15 ( & V_8 -> V_25 ) ) ;
if ( V_63 . type == V_64 )
F_44 ( V_12 , V_8 , V_65 ) ;
else
F_45 ( V_12 , V_8 , V_65 ) ;
}
static inline void F_46 ( struct V_11 * V_12 , int V_65 )
{
if ( V_63 . type == V_64 )
F_47 ( V_12 , V_65 ) ;
else
F_48 ( V_12 , V_65 ) ;
}
static inline void F_49 ( struct V_11 * V_12 )
{
if ( V_63 . type == V_64 )
F_50 ( V_12 ) ;
else
F_51 ( V_12 ) ;
}
static int F_52 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 ;
int V_66 = 0 ;
F_14 ( ! F_15 ( & V_14 -> V_42 ) ) ;
F_3 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_2 ( & V_8 -> V_25 ) ;
if ( F_53 ( V_8 -> V_3 ) && V_8 -> V_67 )
V_66 += F_54 ( V_8 -> V_67 ) ;
else
V_66 ++ ;
F_5 ( & V_8 -> V_25 ) ;
}
return V_66 ;
}
static void F_55 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 ;
int V_66 = 0 ;
F_14 ( ! F_15 ( & V_14 -> V_42 ) ) ;
if ( F_52 ( V_12 ) > V_63 . V_68 ) {
F_49 ( V_12 ) ;
F_21 ( V_12 ) ;
}
F_3 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_2 ( & V_8 -> V_25 ) ;
if ( F_17 ( F_13 ( V_8 ) != V_12 ) )
goto V_69;
do {
F_43 ( V_12 , V_8 , V_66 ++ ) ;
} while ( V_8 -> V_67 && V_66 < V_63 . V_68 );
V_69:
F_5 ( & V_8 -> V_25 ) ;
if ( V_66 == V_63 . V_68 )
break;
}
V_12 -> V_6 . V_14 . V_70 = V_66 ;
for ( ; V_66 < V_63 . V_68 ; V_66 ++ )
F_46 ( V_12 , V_66 ) ;
}
void F_56 ( struct V_11 * V_12 )
{
if ( F_17 ( ! F_34 ( V_12 -> V_2 ) ) )
return;
F_37 ( V_12 ) ;
F_40 ( V_12 ) ;
F_35 ( V_12 ) ;
}
void F_57 ( struct V_11 * V_12 )
{
if ( F_17 ( ! F_34 ( V_12 -> V_2 ) ) )
return;
F_2 ( & V_12 -> V_6 . V_14 . V_42 ) ;
F_55 ( V_12 ) ;
F_5 ( & V_12 -> V_6 . V_14 . V_42 ) ;
}
int F_58 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 ;
bool V_71 = false ;
if ( ! V_12 -> V_2 -> V_6 . V_7 . V_28 )
return false ;
F_2 ( & V_14 -> V_42 ) ;
F_3 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_2 ( & V_8 -> V_25 ) ;
V_71 = F_16 ( V_8 ) && V_8 -> V_28 ;
F_5 ( & V_8 -> V_25 ) ;
if ( V_71 )
break;
}
F_5 ( & V_14 -> V_42 ) ;
return V_71 ;
}
void F_59 ( struct V_2 * V_2 )
{
struct V_11 * V_12 ;
int V_72 ;
F_60 (c, vcpu, kvm) {
if ( F_58 ( V_12 ) )
F_25 ( V_12 ) ;
}
}
bool F_61 ( struct V_11 * V_12 , unsigned int V_53 )
{
struct V_1 * V_8 = F_6 ( V_12 -> V_2 , V_12 , V_53 ) ;
bool V_73 ;
F_2 ( & V_8 -> V_25 ) ;
V_73 = V_8 -> V_55 && V_8 -> V_26 ;
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_12 -> V_2 , V_8 ) ;
return V_73 ;
}
