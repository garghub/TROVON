struct V_1 * F_1 ( struct V_2 * V_2 , struct V_3 * V_4 ,
T_1 V_5 )
{
if ( V_5 <= V_6 )
return & V_4 -> V_7 . V_8 . V_9 [ V_5 ] ;
if ( V_5 <= V_10 )
return & V_2 -> V_7 . V_11 . V_12 [ V_5 - V_13 ] ;
if ( V_5 >= V_14 )
return NULL ;
F_2 ( 1 , L_1 ) ;
return NULL ;
}
static struct V_3 * F_3 ( struct V_1 * V_15 )
{
F_4 ( ! F_5 ( & V_15 -> V_16 ) ) ;
if ( V_15 -> V_17 )
return V_15 -> V_4 ? : V_15 -> V_18 ;
if ( V_15 -> V_19 && V_15 -> V_20 ) {
if ( F_6 ( V_15 -> V_18 &&
! V_15 -> V_18 -> V_2 -> V_7 . V_11 . V_19 ) )
return NULL ;
return V_15 -> V_18 ;
}
return NULL ;
}
static int F_7 ( void * V_21 , struct V_22 * V_23 , struct V_22 * V_24 )
{
struct V_1 * V_25 = F_8 ( V_23 , struct V_1 , V_26 ) ;
struct V_1 * V_27 = F_8 ( V_24 , struct V_1 , V_26 ) ;
bool V_28 , V_29 ;
int V_30 ;
F_9 ( & V_25 -> V_16 ) ;
F_10 ( & V_27 -> V_16 , V_31 ) ;
if ( V_25 -> V_17 || V_27 -> V_17 ) {
V_30 = ( int ) V_27 -> V_17 - ( int ) V_25 -> V_17 ;
goto V_32;
}
V_28 = V_25 -> V_19 && V_25 -> V_20 ;
V_29 = V_27 -> V_19 && V_27 -> V_20 ;
if ( ! V_28 || ! V_29 ) {
V_30 = ( int ) V_29 - ( int ) V_28 ;
goto V_32;
}
V_30 = V_25 -> V_33 - V_27 -> V_33 ;
V_32:
F_11 ( & V_27 -> V_16 ) ;
F_11 ( & V_25 -> V_16 ) ;
return V_30 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_8 * V_8 = & V_4 -> V_7 . V_8 ;
F_4 ( ! F_5 ( & V_8 -> V_34 ) ) ;
F_13 ( NULL , & V_8 -> V_35 , F_7 ) ;
}
static bool F_14 ( struct V_1 * V_15 , bool V_36 )
{
switch ( V_15 -> V_37 ) {
case V_38 :
return V_15 -> V_39 != V_36 ;
case V_40 :
return V_36 ;
}
return false ;
}
bool F_15 ( struct V_2 * V_2 , struct V_1 * V_15 )
{
struct V_3 * V_4 ;
F_4 ( ! F_5 ( & V_15 -> V_16 ) ) ;
V_41:
V_4 = F_3 ( V_15 ) ;
if ( V_15 -> V_4 || ! V_4 ) {
F_11 ( & V_15 -> V_16 ) ;
return false ;
}
F_11 ( & V_15 -> V_16 ) ;
F_9 ( & V_4 -> V_7 . V_8 . V_34 ) ;
F_9 ( & V_15 -> V_16 ) ;
if ( F_6 ( V_15 -> V_4 || V_4 != F_3 ( V_15 ) ) ) {
F_11 ( & V_15 -> V_16 ) ;
F_11 ( & V_4 -> V_7 . V_8 . V_34 ) ;
F_9 ( & V_15 -> V_16 ) ;
goto V_41;
}
F_16 ( & V_15 -> V_26 , & V_4 -> V_7 . V_8 . V_35 ) ;
V_15 -> V_4 = V_4 ;
F_11 ( & V_15 -> V_16 ) ;
F_11 ( & V_4 -> V_7 . V_8 . V_34 ) ;
F_17 ( V_4 ) ;
return true ;
}
static int F_18 ( struct V_2 * V_2 , int V_42 ,
unsigned int V_5 , bool V_36 ,
bool V_43 )
{
struct V_3 * V_4 ;
struct V_1 * V_15 ;
int V_30 ;
F_19 ( V_42 , V_5 , V_36 ) ;
V_30 = F_20 ( V_2 ) ;
if ( V_30 )
return V_30 ;
V_4 = F_21 ( V_2 , V_42 ) ;
if ( ! V_4 && V_5 < V_13 )
return - V_44 ;
V_15 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( ! V_15 )
return - V_44 ;
if ( V_15 -> V_45 != V_43 )
return - V_44 ;
F_9 ( & V_15 -> V_16 ) ;
if ( ! F_14 ( V_15 , V_36 ) ) {
F_11 ( & V_15 -> V_16 ) ;
return 0 ;
}
if ( V_15 -> V_37 == V_38 ) {
V_15 -> V_39 = V_36 ;
V_15 -> V_20 = V_36 || V_15 -> V_46 ;
} else {
V_15 -> V_20 = true ;
}
F_15 ( V_2 , V_15 ) ;
return 0 ;
}
int F_22 ( struct V_2 * V_2 , int V_42 , unsigned int V_5 ,
bool V_36 )
{
return F_18 ( V_2 , V_42 , V_5 , V_36 , false ) ;
}
int F_23 ( struct V_2 * V_2 , int V_42 , unsigned int V_5 ,
bool V_36 )
{
return F_18 ( V_2 , V_42 , V_5 , V_36 , true ) ;
}
int F_24 ( struct V_3 * V_4 , T_1 V_47 , T_1 V_48 )
{
struct V_1 * V_15 = F_1 ( V_4 -> V_2 , V_4 , V_47 ) ;
F_25 ( ! V_15 ) ;
F_9 ( & V_15 -> V_16 ) ;
V_15 -> V_45 = true ;
V_15 -> V_49 = V_48 ;
F_11 ( & V_15 -> V_16 ) ;
return 0 ;
}
int F_26 ( struct V_3 * V_4 , unsigned int V_47 )
{
struct V_1 * V_15 = F_1 ( V_4 -> V_2 , V_4 , V_47 ) ;
F_25 ( ! V_15 ) ;
if ( ! F_27 ( V_4 -> V_2 ) )
return - V_50 ;
F_9 ( & V_15 -> V_16 ) ;
V_15 -> V_45 = false ;
V_15 -> V_49 = 0 ;
F_11 ( & V_15 -> V_16 ) ;
return 0 ;
}
static void F_28 ( struct V_3 * V_4 )
{
struct V_8 * V_8 = & V_4 -> V_7 . V_8 ;
struct V_1 * V_15 , * V_51 ;
V_41:
F_9 ( & V_8 -> V_34 ) ;
F_29 (irq, tmp, &vgic_cpu->ap_list_head, ap_list) {
struct V_3 * V_18 , * V_52 , * V_53 ;
F_9 ( & V_15 -> V_16 ) ;
F_25 ( V_4 != V_15 -> V_4 ) ;
V_18 = F_3 ( V_15 ) ;
if ( ! V_18 ) {
F_30 ( & V_15 -> V_26 ) ;
V_15 -> V_4 = NULL ;
F_11 ( & V_15 -> V_16 ) ;
continue;
}
if ( V_18 == V_4 ) {
F_11 ( & V_15 -> V_16 ) ;
continue;
}
F_11 ( & V_15 -> V_16 ) ;
F_11 ( & V_8 -> V_34 ) ;
if ( V_4 -> V_54 < V_18 -> V_54 ) {
V_52 = V_4 ;
V_53 = V_18 ;
} else {
V_52 = V_18 ;
V_53 = V_4 ;
}
F_9 ( & V_52 -> V_7 . V_8 . V_34 ) ;
F_10 ( & V_53 -> V_7 . V_8 . V_34 ,
V_31 ) ;
F_9 ( & V_15 -> V_16 ) ;
if ( V_18 == F_3 ( V_15 ) ) {
struct V_8 * V_55 = & V_18 -> V_7 . V_8 ;
F_30 ( & V_15 -> V_26 ) ;
V_15 -> V_4 = V_18 ;
F_16 ( & V_15 -> V_26 , & V_55 -> V_35 ) ;
}
F_11 ( & V_15 -> V_16 ) ;
F_11 ( & V_53 -> V_7 . V_8 . V_34 ) ;
F_11 ( & V_52 -> V_7 . V_8 . V_34 ) ;
goto V_41;
}
F_11 ( & V_8 -> V_34 ) ;
}
static inline void F_31 ( struct V_3 * V_4 )
{
if ( V_56 . type == V_57 )
F_32 ( V_4 ) ;
else
F_33 ( V_4 ) ;
}
static inline void F_34 ( struct V_3 * V_4 )
{
if ( V_56 . type == V_57 )
F_35 ( V_4 ) ;
else
F_36 ( V_4 ) ;
}
static inline void F_37 ( struct V_3 * V_4 ,
struct V_1 * V_15 , int V_58 )
{
F_4 ( ! F_5 ( & V_15 -> V_16 ) ) ;
if ( V_56 . type == V_57 )
F_38 ( V_4 , V_15 , V_58 ) ;
else
F_39 ( V_4 , V_15 , V_58 ) ;
}
static inline void F_40 ( struct V_3 * V_4 , int V_58 )
{
if ( V_56 . type == V_57 )
F_41 ( V_4 , V_58 ) ;
else
F_42 ( V_4 , V_58 ) ;
}
static inline void F_43 ( struct V_3 * V_4 )
{
if ( V_56 . type == V_57 )
F_44 ( V_4 ) ;
else
F_45 ( V_4 ) ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_8 * V_8 = & V_4 -> V_7 . V_8 ;
struct V_1 * V_15 ;
int V_59 = 0 ;
F_4 ( ! F_5 ( & V_8 -> V_34 ) ) ;
F_47 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_9 ( & V_15 -> V_16 ) ;
if ( F_48 ( V_15 -> V_5 ) && V_15 -> V_60 )
V_59 += F_49 ( V_15 -> V_60 ) ;
else
V_59 ++ ;
F_11 ( & V_15 -> V_16 ) ;
}
return V_59 ;
}
static void F_50 ( struct V_3 * V_4 )
{
struct V_8 * V_8 = & V_4 -> V_7 . V_8 ;
struct V_1 * V_15 ;
int V_59 = 0 ;
F_4 ( ! F_5 ( & V_8 -> V_34 ) ) ;
if ( F_46 ( V_4 ) > V_56 . V_61 ) {
F_43 ( V_4 ) ;
F_12 ( V_4 ) ;
}
F_47 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_9 ( & V_15 -> V_16 ) ;
if ( F_6 ( F_3 ( V_15 ) != V_4 ) )
goto V_62;
do {
F_37 ( V_4 , V_15 , V_59 ++ ) ;
} while ( V_15 -> V_60 && V_59 < V_56 . V_61 );
V_62:
F_11 ( & V_15 -> V_16 ) ;
if ( V_59 == V_56 . V_61 )
break;
}
V_4 -> V_7 . V_8 . V_63 = V_59 ;
for ( ; V_59 < V_56 . V_61 ; V_59 ++ )
F_40 ( V_4 , V_59 ) ;
}
void F_51 ( struct V_3 * V_4 )
{
F_31 ( V_4 ) ;
F_34 ( V_4 ) ;
F_28 ( V_4 ) ;
}
void F_52 ( struct V_3 * V_4 )
{
F_9 ( & V_4 -> V_7 . V_8 . V_34 ) ;
F_50 ( V_4 ) ;
F_11 ( & V_4 -> V_7 . V_8 . V_34 ) ;
}
int F_53 ( struct V_3 * V_4 )
{
struct V_8 * V_8 = & V_4 -> V_7 . V_8 ;
struct V_1 * V_15 ;
bool V_20 = false ;
if ( ! V_4 -> V_2 -> V_7 . V_11 . V_19 )
return false ;
F_9 ( & V_8 -> V_34 ) ;
F_47 (irq, &vgic_cpu->ap_list_head, ap_list) {
F_9 ( & V_15 -> V_16 ) ;
V_20 = V_15 -> V_20 && V_15 -> V_19 ;
F_11 ( & V_15 -> V_16 ) ;
if ( V_20 )
break;
}
F_11 ( & V_8 -> V_34 ) ;
return V_20 ;
}
void F_54 ( struct V_2 * V_2 )
{
struct V_3 * V_4 ;
int V_64 ;
F_55 (c, vcpu, kvm) {
if ( F_53 ( V_4 ) )
F_17 ( V_4 ) ;
}
}
bool F_56 ( struct V_3 * V_4 , unsigned int V_47 )
{
struct V_1 * V_15 = F_1 ( V_4 -> V_2 , V_4 , V_47 ) ;
bool V_65 ;
F_9 ( & V_15 -> V_16 ) ;
V_65 = V_15 -> V_45 && V_15 -> V_17 ;
F_11 ( & V_15 -> V_16 ) ;
return V_65 ;
}
