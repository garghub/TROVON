static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
V_2 -> V_4 = & V_2 -> V_3 ;
}
static inline void F_2 ( struct V_1 * V_2 , struct V_5 * V_3 )
{
* V_2 -> V_4 = V_3 ;
V_2 -> V_4 = & V_3 -> V_6 ;
}
static inline bool F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_4 == & V_2 -> V_3 ;
}
static inline struct V_5 * F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_3 ;
if ( F_3 ( V_2 ) )
return NULL ;
V_3 = V_2 -> V_3 ;
V_2 -> V_3 = V_3 -> V_6 ;
if ( V_2 -> V_4 == & V_3 -> V_6 )
F_1 ( V_2 ) ;
return V_3 ;
}
static inline void F_5 ( struct V_1 * V_7 , struct V_1 * V_8 )
{
if ( ! F_3 ( V_8 ) ) {
* V_7 -> V_4 = V_8 -> V_3 ;
V_7 -> V_4 = V_8 -> V_4 ;
F_1 ( V_8 ) ;
}
}
static int F_6 ( struct V_9 * V_10 )
{
V_10 -> V_11 = 0 ;
F_7 ( & V_10 -> V_12 ) ;
V_10 -> V_13 = false ;
F_1 ( & V_10 -> V_14 ) ;
F_1 ( & V_10 -> V_15 ) ;
F_1 ( & V_10 -> V_16 ) ;
F_1 ( & V_10 -> V_17 ) ;
F_8 ( & V_10 -> V_18 , V_19 ) ;
V_10 -> V_20 = F_9 ( struct V_21 ) ;
return V_10 -> V_20 ? 0 : - V_22 ;
}
int F_10 ( struct V_9 * V_10 , const char * V_23 ,
struct V_24 * V_25 )
{
F_11 ( ( void * ) V_10 , sizeof( * V_10 ) ) ;
F_12 ( & V_10 -> V_26 , V_23 , V_25 , 0 ) ;
return F_6 ( V_10 ) ;
}
int F_13 ( struct V_9 * V_10 )
{
return F_6 ( V_10 ) ;
}
static unsigned long F_14 ( struct V_9 * V_10 , int V_27 )
{
int V_28 ;
unsigned long V_29 = 0 ;
unsigned long V_30 ;
F_15 (cpu) {
V_30 = F_16 ( F_17 ( V_10 -> V_20 , V_28 ) -> V_31 [ V_27 ] ) ;
V_29 += V_30 ;
}
return V_29 ;
}
static unsigned long F_18 ( struct V_9 * V_10 , int V_27 )
{
int V_28 ;
unsigned long V_29 = 0 ;
unsigned long V_30 ;
F_15 (cpu) {
V_30 = F_16 ( F_17 ( V_10 -> V_20 , V_28 ) -> V_32 [ V_27 ] ) ;
V_29 += V_30 ;
}
return V_29 ;
}
static bool F_19 ( struct V_9 * V_10 , int V_27 )
{
unsigned long V_31 ;
V_31 = F_14 ( V_10 , V_27 ) ;
F_20 () ;
if ( F_18 ( V_10 , V_27 ) != 0 )
return false ;
F_20 () ;
return F_14 ( V_10 , V_27 ) == V_31 ;
}
static bool F_21 ( struct V_9 * V_10 )
{
int V_28 ;
unsigned long V_29 = 0 ;
F_15 (cpu) {
V_29 += F_16 ( F_17 ( V_10 -> V_20 , V_28 ) -> V_32 [ 0 ] ) ;
V_29 += F_16 ( F_17 ( V_10 -> V_20 , V_28 ) -> V_32 [ 1 ] ) ;
}
return V_29 ;
}
void F_22 ( struct V_9 * V_10 )
{
if ( F_23 ( F_21 ( V_10 ) ) )
return;
F_24 ( V_10 -> V_20 ) ;
V_10 -> V_20 = NULL ;
}
int F_25 ( struct V_9 * V_10 )
{
int V_27 ;
V_27 = F_16 ( V_10 -> V_11 ) & 0x1 ;
F_26 ( V_10 -> V_20 -> V_32 [ V_27 ] ) ;
F_20 () ;
F_26 ( V_10 -> V_20 -> V_31 [ V_27 ] ) ;
return V_27 ;
}
void F_27 ( struct V_9 * V_10 , int V_27 )
{
F_20 () ;
F_28 ( V_10 -> V_20 -> V_32 [ V_27 ] ) ;
}
static bool F_29 ( struct V_9 * V_10 , int V_27 , int V_33 )
{
for (; ; ) {
if ( F_19 ( V_10 , V_27 ) )
return true ;
if ( -- V_33 <= 0 )
return false ;
F_30 ( V_34 ) ;
}
}
static void F_31 ( struct V_9 * V_10 )
{
V_10 -> V_11 ++ ;
}
void F_32 ( struct V_9 * V_10 , struct V_5 * V_3 ,
T_1 V_35 )
{
unsigned long V_36 ;
V_3 -> V_6 = NULL ;
V_3 -> V_35 = V_35 ;
F_33 ( & V_10 -> V_12 , V_36 ) ;
F_2 ( & V_10 -> V_14 , V_3 ) ;
if ( ! V_10 -> V_13 ) {
V_10 -> V_13 = true ;
F_34 ( V_37 , & V_10 -> V_18 , 0 ) ;
}
F_35 ( & V_10 -> V_12 , V_36 ) ;
}
static void F_36 ( struct V_9 * V_10 , int V_33 )
{
struct V_38 V_39 ;
struct V_5 * V_3 = & V_39 . V_3 ;
bool V_40 = false ;
F_37 ( F_38 ( & V_10 -> V_26 ) ||
F_38 ( & V_41 ) ||
F_38 ( & V_42 ) ||
F_38 ( & V_43 ) ,
L_1 ) ;
F_39 () ;
F_40 ( & V_39 . V_44 ) ;
V_3 -> V_6 = NULL ;
V_3 -> V_35 = V_45 ;
F_41 ( & V_10 -> V_12 ) ;
if ( ! V_10 -> V_13 ) {
V_10 -> V_13 = true ;
F_2 ( & V_10 -> V_15 , V_3 ) ;
F_42 ( & V_10 -> V_12 ) ;
F_43 ( V_10 , V_33 ) ;
if ( ! F_3 ( & V_10 -> V_17 ) ) {
F_44 ( V_10 -> V_17 . V_3 != V_3 ) ;
F_4 ( & V_10 -> V_17 ) ;
V_40 = true ;
}
F_45 ( V_10 ) ;
} else {
F_2 ( & V_10 -> V_14 , V_3 ) ;
F_42 ( & V_10 -> V_12 ) ;
}
if ( ! V_40 )
F_46 ( & V_39 . V_44 ) ;
}
void F_47 ( struct V_9 * V_10 )
{
F_36 ( V_10 , F_48 ()
? V_46
: V_47 ) ;
}
void F_49 ( struct V_9 * V_10 )
{
F_36 ( V_10 , V_46 ) ;
}
void F_50 ( struct V_9 * V_10 )
{
F_47 ( V_10 ) ;
}
unsigned long F_51 ( struct V_9 * V_10 )
{
return V_10 -> V_11 ;
}
static void F_52 ( struct V_9 * V_10 )
{
if ( ! F_3 ( & V_10 -> V_14 ) ) {
F_41 ( & V_10 -> V_12 ) ;
F_5 ( & V_10 -> V_15 , & V_10 -> V_14 ) ;
F_42 ( & V_10 -> V_12 ) ;
}
}
static void F_43 ( struct V_9 * V_10 , int V_33 )
{
int V_27 = 1 ^ ( V_10 -> V_11 & 1 ) ;
if ( F_3 ( & V_10 -> V_15 ) &&
F_3 ( & V_10 -> V_16 ) )
return;
if ( ! F_29 ( V_10 , V_27 , V_33 ) )
return;
F_5 ( & V_10 -> V_17 , & V_10 -> V_16 ) ;
if ( F_3 ( & V_10 -> V_15 ) )
return;
F_31 ( V_10 ) ;
F_5 ( & V_10 -> V_16 , & V_10 -> V_15 ) ;
V_33 = V_33 < 2 ? 2 : V_33 ;
if ( ! F_29 ( V_10 , V_27 ^ 1 , V_33 ) )
return;
F_5 ( & V_10 -> V_17 , & V_10 -> V_16 ) ;
}
static void F_53 ( struct V_9 * V_10 )
{
int V_48 ;
struct V_5 * V_3 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_3 = F_4 ( & V_10 -> V_17 ) ;
if ( ! V_3 )
break;
F_54 () ;
V_3 -> V_35 ( V_3 ) ;
F_55 () ;
}
}
static void F_45 ( struct V_9 * V_10 )
{
bool V_50 = true ;
if ( F_3 ( & V_10 -> V_17 ) &&
F_3 ( & V_10 -> V_16 ) &&
F_3 ( & V_10 -> V_15 ) &&
F_3 ( & V_10 -> V_14 ) ) {
F_41 ( & V_10 -> V_12 ) ;
if ( F_3 ( & V_10 -> V_17 ) &&
F_3 ( & V_10 -> V_16 ) &&
F_3 ( & V_10 -> V_15 ) &&
F_3 ( & V_10 -> V_14 ) ) {
V_10 -> V_13 = false ;
V_50 = false ;
}
F_42 ( & V_10 -> V_12 ) ;
}
if ( V_50 )
F_34 ( V_37 ,
& V_10 -> V_18 , V_51 ) ;
}
void V_19 ( struct V_52 * V_18 )
{
struct V_9 * V_10 ;
V_10 = F_56 ( V_18 , struct V_9 , V_18 . V_18 ) ;
F_52 ( V_10 ) ;
F_43 ( V_10 , 1 ) ;
F_53 ( V_10 ) ;
F_45 ( V_10 ) ;
}
