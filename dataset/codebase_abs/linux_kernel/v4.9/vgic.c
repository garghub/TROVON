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
if ( V_8 -> V_28 && V_8 -> V_29 ) {
if ( F_16 ( V_8 -> V_27 &&
! V_8 -> V_27 -> V_2 -> V_6 . V_7 . V_28 ) )
return NULL ;
return V_8 -> V_27 ;
}
return NULL ;
}
static int F_17 ( void * V_30 , struct V_31 * V_32 , struct V_31 * V_33 )
{
struct V_1 * V_34 = F_18 ( V_32 , struct V_1 , V_35 ) ;
struct V_1 * V_36 = F_18 ( V_33 , struct V_1 , V_35 ) ;
bool V_37 , V_38 ;
int V_39 ;
F_2 ( & V_34 -> V_25 ) ;
F_19 ( & V_36 -> V_25 , V_40 ) ;
if ( V_34 -> V_26 || V_36 -> V_26 ) {
V_39 = ( int ) V_36 -> V_26 - ( int ) V_34 -> V_26 ;
goto V_41;
}
V_37 = V_34 -> V_28 && V_34 -> V_29 ;
V_38 = V_36 -> V_28 && V_36 -> V_29 ;
if ( ! V_37 || ! V_38 ) {
V_39 = ( int ) V_38 - ( int ) V_37 ;
goto V_41;
}
V_39 = V_34 -> V_42 - V_36 -> V_42 ;
V_41:
F_5 ( & V_36 -> V_25 ) ;
F_5 ( & V_34 -> V_25 ) ;
return V_39 ;
}
static void F_20 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
F_14 ( ! F_15 ( & V_14 -> V_43 ) ) ;
F_21 ( NULL , & V_14 -> V_44 , F_17 ) ;
}
static bool F_22 ( struct V_1 * V_8 , bool V_45 )
{
switch ( V_8 -> V_46 ) {
case V_47 :
return V_8 -> V_48 != V_45 ;
case V_49 :
return V_45 ;
}
return false ;
}
bool F_23 ( struct V_2 * V_2 , struct V_1 * V_8 )
{
struct V_11 * V_12 ;
F_14 ( ! F_15 ( & V_8 -> V_25 ) ) ;
V_50:
V_12 = F_13 ( V_8 ) ;
if ( V_8 -> V_12 || ! V_12 ) {
F_5 ( & V_8 -> V_25 ) ;
if ( V_12 )
F_24 ( V_12 ) ;
return false ;
}
F_5 ( & V_8 -> V_25 ) ;
F_2 ( & V_12 -> V_6 . V_14 . V_43 ) ;
F_2 ( & V_8 -> V_25 ) ;
if ( F_16 ( V_8 -> V_12 || V_12 != F_13 ( V_8 ) ) ) {
F_5 ( & V_8 -> V_25 ) ;
F_5 ( & V_12 -> V_6 . V_14 . V_43 ) ;
F_2 ( & V_8 -> V_25 ) ;
goto V_50;
}
F_4 ( V_8 ) ;
F_25 ( & V_8 -> V_35 , & V_12 -> V_6 . V_14 . V_44 ) ;
V_8 -> V_12 = V_12 ;
F_5 ( & V_8 -> V_25 ) ;
F_5 ( & V_12 -> V_6 . V_14 . V_43 ) ;
F_24 ( V_12 ) ;
return true ;
}
static int F_26 ( struct V_2 * V_2 , int V_51 ,
unsigned int V_3 , bool V_45 ,
bool V_52 )
{
struct V_11 * V_12 ;
struct V_1 * V_8 ;
int V_39 ;
F_27 ( V_51 , V_3 , V_45 ) ;
V_39 = F_28 ( V_2 ) ;
if ( V_39 )
return V_39 ;
V_12 = F_29 ( V_2 , V_51 ) ;
if ( ! V_12 && V_3 < V_18 )
return - V_53 ;
V_8 = F_6 ( V_2 , V_12 , V_3 ) ;
if ( ! V_8 )
return - V_53 ;
if ( V_8 -> V_54 != V_52 ) {
F_9 ( V_2 , V_8 ) ;
return - V_53 ;
}
F_2 ( & V_8 -> V_25 ) ;
if ( ! F_22 ( V_8 , V_45 ) ) {
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_2 , V_8 ) ;
return 0 ;
}
if ( V_8 -> V_46 == V_47 ) {
V_8 -> V_48 = V_45 ;
V_8 -> V_29 = V_45 || V_8 -> V_55 ;
} else {
V_8 -> V_29 = true ;
}
F_23 ( V_2 , V_8 ) ;
F_9 ( V_2 , V_8 ) ;
return 0 ;
}
int F_30 ( struct V_2 * V_2 , int V_51 , unsigned int V_3 ,
bool V_45 )
{
return F_26 ( V_2 , V_51 , V_3 , V_45 , false ) ;
}
int F_31 ( struct V_2 * V_2 , int V_51 , unsigned int V_3 ,
bool V_45 )
{
return F_26 ( V_2 , V_51 , V_3 , V_45 , true ) ;
}
int F_32 ( struct V_11 * V_12 , T_1 V_56 , T_1 V_57 )
{
struct V_1 * V_8 = F_6 ( V_12 -> V_2 , V_12 , V_56 ) ;
F_33 ( ! V_8 ) ;
F_2 ( & V_8 -> V_25 ) ;
V_8 -> V_54 = true ;
V_8 -> V_58 = V_57 ;
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_12 -> V_2 , V_8 ) ;
return 0 ;
}
int F_34 ( struct V_11 * V_12 , unsigned int V_56 )
{
struct V_1 * V_8 ;
if ( ! F_35 ( V_12 -> V_2 ) )
return - V_59 ;
V_8 = F_6 ( V_12 -> V_2 , V_12 , V_56 ) ;
F_33 ( ! V_8 ) ;
F_2 ( & V_8 -> V_25 ) ;
V_8 -> V_54 = false ;
V_8 -> V_58 = 0 ;
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_12 -> V_2 , V_8 ) ;
return 0 ;
}
static void F_36 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 , * V_60 ;
V_50:
F_2 ( & V_14 -> V_43 ) ;
F_37 (irq, tmp, &vgic_cpu->ap_list_head, ap_list) {
struct V_11 * V_27 , * V_61 , * V_62 ;
F_2 ( & V_8 -> V_25 ) ;
F_33 ( V_12 != V_8 -> V_12 ) ;
V_27 = F_13 ( V_8 ) ;
if ( ! V_27 ) {
F_11 ( & V_8 -> V_35 ) ;
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
F_5 ( & V_14 -> V_43 ) ;
if ( V_12 -> V_63 < V_27 -> V_63 ) {
V_61 = V_12 ;
V_62 = V_27 ;
} else {
V_61 = V_27 ;
V_62 = V_12 ;
}
F_2 ( & V_61 -> V_6 . V_14 . V_43 ) ;
F_19 ( & V_62 -> V_6 . V_14 . V_43 ,
V_40 ) ;
F_2 ( & V_8 -> V_25 ) ;
if ( V_27 == F_13 ( V_8 ) ) {
struct V_14 * V_64 = & V_27 -> V_6 . V_14 ;
F_11 ( & V_8 -> V_35 ) ;
V_8 -> V_12 = V_27 ;
F_25 ( & V_8 -> V_35 , & V_64 -> V_44 ) ;
}
F_5 ( & V_8 -> V_25 ) ;
F_5 ( & V_62 -> V_6 . V_14 . V_43 ) ;
F_5 ( & V_61 -> V_6 . V_14 . V_43 ) ;
goto V_50;
}
F_5 ( & V_14 -> V_43 ) ;
}
static inline void F_38 ( struct V_11 * V_12 )
{
if ( V_65 . type == V_66 )
F_39 ( V_12 ) ;
else
F_40 ( V_12 ) ;
}
static inline void F_41 ( struct V_11 * V_12 )
{
if ( V_65 . type == V_66 )
F_42 ( V_12 ) ;
else
F_43 ( V_12 ) ;
}
static inline void F_44 ( struct V_11 * V_12 ,
struct V_1 * V_8 , int V_67 )
{
F_14 ( ! F_15 ( & V_8 -> V_25 ) ) ;
if ( V_65 . type == V_66 )
F_45 ( V_12 , V_8 , V_67 ) ;
else
F_46 ( V_12 , V_8 , V_67 ) ;
}
static inline void F_47 ( struct V_11 * V_12 , int V_67 )
{
if ( V_65 . type == V_66 )
F_48 ( V_12 , V_67 ) ;
else
F_49 ( V_12 , V_67 ) ;
}
static inline void F_50 ( struct V_11 * V_12 )
{
if ( V_65 . type == V_66 )
F_51 ( V_12 ) ;
else
F_52 ( V_12 ) ;
}
static int F_53 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 ;
int V_68 = 0 ;
F_14 ( ! F_15 ( & V_14 -> V_43 ) ) ;
F_3 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_2 ( & V_8 -> V_25 ) ;
if ( F_54 ( V_8 -> V_3 ) && V_8 -> V_69 )
V_68 += F_55 ( V_8 -> V_69 ) ;
else
V_68 ++ ;
F_5 ( & V_8 -> V_25 ) ;
}
return V_68 ;
}
static void F_56 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 ;
int V_68 = 0 ;
F_14 ( ! F_15 ( & V_14 -> V_43 ) ) ;
if ( F_53 ( V_12 ) > V_65 . V_70 ) {
F_50 ( V_12 ) ;
F_20 ( V_12 ) ;
}
F_3 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_2 ( & V_8 -> V_25 ) ;
if ( F_16 ( F_13 ( V_8 ) != V_12 ) )
goto V_71;
do {
F_44 ( V_12 , V_8 , V_68 ++ ) ;
} while ( V_8 -> V_69 && V_68 < V_65 . V_70 );
V_71:
F_5 ( & V_8 -> V_25 ) ;
if ( V_68 == V_65 . V_70 )
break;
}
V_12 -> V_6 . V_14 . V_72 = V_68 ;
for ( ; V_68 < V_65 . V_70 ; V_68 ++ )
F_47 ( V_12 , V_68 ) ;
}
void F_57 ( struct V_11 * V_12 )
{
if ( F_16 ( ! F_35 ( V_12 -> V_2 ) ) )
return;
F_38 ( V_12 ) ;
F_41 ( V_12 ) ;
F_36 ( V_12 ) ;
}
void F_58 ( struct V_11 * V_12 )
{
if ( F_16 ( ! F_35 ( V_12 -> V_2 ) ) )
return;
F_2 ( & V_12 -> V_6 . V_14 . V_43 ) ;
F_56 ( V_12 ) ;
F_5 ( & V_12 -> V_6 . V_14 . V_43 ) ;
}
int F_59 ( struct V_11 * V_12 )
{
struct V_14 * V_14 = & V_12 -> V_6 . V_14 ;
struct V_1 * V_8 ;
bool V_29 = false ;
if ( ! V_12 -> V_2 -> V_6 . V_7 . V_28 )
return false ;
F_2 ( & V_14 -> V_43 ) ;
F_3 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_2 ( & V_8 -> V_25 ) ;
V_29 = V_8 -> V_29 && V_8 -> V_28 ;
F_5 ( & V_8 -> V_25 ) ;
if ( V_29 )
break;
}
F_5 ( & V_14 -> V_43 ) ;
return V_29 ;
}
void F_60 ( struct V_2 * V_2 )
{
struct V_11 * V_12 ;
int V_73 ;
F_61 (c, vcpu, kvm) {
if ( F_59 ( V_12 ) )
F_24 ( V_12 ) ;
}
}
bool F_62 ( struct V_11 * V_12 , unsigned int V_56 )
{
struct V_1 * V_8 = F_6 ( V_12 -> V_2 , V_12 , V_56 ) ;
bool V_74 ;
F_2 ( & V_8 -> V_25 ) ;
V_74 = V_8 -> V_54 && V_8 -> V_26 ;
F_5 ( & V_8 -> V_25 ) ;
F_9 ( V_12 -> V_2 , V_8 ) ;
return V_74 ;
}
