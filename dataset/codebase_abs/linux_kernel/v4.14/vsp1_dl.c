static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 ,
T_1 V_6 )
{
T_1 V_7 = V_5 * sizeof( * V_4 -> V_8 ) + V_6 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = F_2 ( V_2 -> V_9 , V_4 -> V_7 , & V_4 -> V_10 ,
V_11 ) ;
if ( ! V_4 -> V_8 )
return - V_12 ;
return 0 ;
}
static void F_3 ( struct V_3 * V_4 )
{
F_4 ( V_4 -> V_2 -> V_9 , V_4 -> V_7 , V_4 -> V_8 , V_4 -> V_10 ) ;
}
struct V_3 * F_5 ( struct V_1 * V_2 ,
unsigned int V_5 )
{
struct V_3 * V_4 ;
int V_13 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_11 ) ;
if ( ! V_4 )
return NULL ;
V_13 = F_1 ( V_2 , V_4 , V_5 , 0 ) ;
if ( V_13 < 0 ) {
F_7 ( V_4 ) ;
return NULL ;
}
return V_4 ;
}
void F_8 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
F_3 ( V_4 ) ;
F_7 ( V_4 ) ;
}
void F_9 ( struct V_3 * V_4 , T_2 V_14 , T_2 V_15 )
{
V_4 -> V_8 [ V_4 -> V_5 ] . V_16 = V_14 ;
V_4 -> V_8 [ V_4 -> V_5 ] . V_15 = V_15 ;
V_4 -> V_5 ++ ;
}
static struct V_17 * F_10 ( struct V_18 * V_19 )
{
struct V_17 * V_20 ;
T_1 V_21 ;
int V_13 ;
V_20 = F_6 ( sizeof( * V_20 ) , V_11 ) ;
if ( ! V_20 )
return NULL ;
F_11 ( & V_20 -> V_22 ) ;
V_20 -> V_19 = V_19 ;
V_21 = V_19 -> V_23 == V_24
? F_12 ( sizeof( struct V_25 ) , 8 )
: 0 ;
V_13 = F_1 ( V_19 -> V_2 , & V_20 -> V_26 , V_27 ,
V_21 ) ;
if ( V_13 < 0 ) {
F_7 ( V_20 ) ;
return NULL ;
}
if ( V_19 -> V_23 == V_24 ) {
T_1 V_28 = V_27
* sizeof( * V_20 -> V_26 . V_8 ) ;
V_20 -> V_29 = ( ( void * ) V_20 -> V_26 . V_8 ) + V_28 ;
V_20 -> V_10 = V_20 -> V_26 . V_10 + V_28 ;
memset ( V_20 -> V_29 , 0 , sizeof( * V_20 -> V_29 ) ) ;
V_20 -> V_29 -> V_30 [ 0 ] . V_16 = V_20 -> V_26 . V_10 ;
}
return V_20 ;
}
static void F_13 ( struct V_17 * V_20 )
{
F_3 ( & V_20 -> V_26 ) ;
F_14 ( & V_20 -> V_22 , & V_20 -> V_19 -> V_31 ) ;
F_7 ( V_20 ) ;
}
struct V_17 * F_15 ( struct V_18 * V_19 )
{
struct V_17 * V_20 = NULL ;
unsigned long V_32 ;
F_16 ( & V_19 -> V_33 , V_32 ) ;
if ( ! F_17 ( & V_19 -> free ) ) {
V_20 = F_18 ( & V_19 -> free , struct V_17 , V_34 ) ;
F_19 ( & V_20 -> V_34 ) ;
F_11 ( & V_20 -> V_35 ) ;
}
F_20 ( & V_19 -> V_33 , V_32 ) ;
return V_20 ;
}
static void F_21 ( struct V_17 * V_20 )
{
struct V_17 * V_36 ;
if ( ! V_20 )
return;
if ( V_20 -> V_37 ) {
F_22 (dl_child, &dl->chain, chain)
F_21 ( V_36 ) ;
}
V_20 -> V_37 = false ;
if ( ! F_17 ( & V_20 -> V_22 ) ) {
F_14 ( & V_20 -> V_22 , & V_20 -> V_19 -> V_31 ) ;
F_23 ( & V_20 -> V_19 -> V_38 ) ;
}
V_20 -> V_26 . V_5 = 0 ;
F_24 ( & V_20 -> V_34 , & V_20 -> V_19 -> free ) ;
}
void F_25 ( struct V_17 * V_20 )
{
unsigned long V_32 ;
if ( ! V_20 )
return;
F_16 ( & V_20 -> V_19 -> V_33 , V_32 ) ;
F_21 ( V_20 ) ;
F_20 ( & V_20 -> V_19 -> V_33 , V_32 ) ;
}
void F_26 ( struct V_17 * V_20 , T_2 V_14 , T_2 V_15 )
{
F_9 ( & V_20 -> V_26 , V_14 , V_15 ) ;
}
int F_27 ( struct V_17 * V_20 ,
struct V_3 * V_4 )
{
if ( V_20 -> V_19 -> V_23 != V_24 )
return - V_39 ;
F_24 ( & V_4 -> V_34 , & V_20 -> V_22 ) ;
return 0 ;
}
int F_28 ( struct V_17 * V_40 ,
struct V_17 * V_20 )
{
if ( V_40 -> V_19 -> V_23 != V_24 )
return - V_39 ;
V_40 -> V_37 = true ;
F_24 ( & V_20 -> V_35 , & V_40 -> V_35 ) ;
return 0 ;
}
static void F_29 ( struct V_17 * V_20 , bool V_41 )
{
struct V_18 * V_19 = V_20 -> V_19 ;
struct V_42 * V_43 = V_20 -> V_29 -> V_30 ;
struct V_3 * V_4 ;
unsigned int V_44 = 0 ;
V_43 -> V_45 = V_20 -> V_26 . V_5
* sizeof( * V_20 -> V_29 -> V_30 ) ;
F_22 (dlb, &dl->fragments, list) {
V_44 ++ ;
V_43 ++ ;
V_43 -> V_16 = V_4 -> V_10 ;
V_43 -> V_45 = V_4 -> V_5
* sizeof( * V_20 -> V_29 -> V_30 ) ;
}
V_20 -> V_29 -> V_44 = V_44 ;
if ( ! F_17 ( & V_20 -> V_35 ) && ! V_41 ) {
struct V_17 * V_46 = F_30 ( V_20 , V_35 ) ;
V_20 -> V_29 -> V_47 = V_46 -> V_10 ;
V_20 -> V_29 -> V_32 = V_48 ;
} else if ( ! V_19 -> V_49 ) {
V_20 -> V_29 -> V_47 = V_20 -> V_10 ;
V_20 -> V_29 -> V_32 = V_50 | V_48 ;
} else {
V_20 -> V_29 -> V_32 = V_50 ;
}
}
static bool F_31 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
if ( ! V_19 -> V_51 )
return false ;
if ( V_19 -> V_23 == V_52 )
return ! ! ( F_32 ( V_2 , V_53 )
& V_54 ) ;
else
return ! ! ( F_32 ( V_2 , F_33 ( V_19 -> V_55 ) & V_56 ) ) ;
}
static void F_34 ( struct V_17 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_19 -> V_23 == V_52 ) {
F_35 ( V_2 , F_36 ( 0 ) , V_20 -> V_26 . V_10 ) ;
F_35 ( V_2 , V_53 , V_54 |
( V_20 -> V_26 . V_5 * sizeof( * V_20 -> V_29 -> V_30 ) ) ) ;
} else {
F_35 ( V_2 , F_36 ( V_19 -> V_55 ) , V_20 -> V_10 ) ;
}
}
static void F_37 ( struct V_17 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_19 ;
if ( F_31 ( V_19 ) ) {
F_21 ( V_19 -> V_57 ) ;
V_19 -> V_57 = V_20 ;
return;
}
F_34 ( V_20 ) ;
F_21 ( V_19 -> V_51 ) ;
V_19 -> V_51 = V_20 ;
}
static void F_38 ( struct V_17 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_19 ;
F_34 ( V_20 ) ;
V_19 -> V_58 = V_20 ;
}
void F_39 ( struct V_17 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_19 ;
struct V_17 * V_36 ;
unsigned long V_32 ;
if ( V_19 -> V_23 == V_24 ) {
F_29 ( V_20 , F_17 ( & V_20 -> V_35 ) ) ;
F_22 (dl_child, &dl->chain, chain) {
bool V_59 = F_40 ( & V_36 -> V_35 , & V_20 -> V_35 ) ;
F_29 ( V_36 , V_59 ) ;
}
}
F_16 ( & V_19 -> V_33 , V_32 ) ;
if ( V_19 -> V_49 )
F_38 ( V_20 ) ;
else
F_37 ( V_20 ) ;
F_20 ( & V_19 -> V_33 , V_32 ) ;
}
bool F_41 ( struct V_18 * V_19 )
{
bool V_60 = false ;
F_42 ( & V_19 -> V_33 ) ;
if ( V_19 -> V_49 ) {
F_21 ( V_19 -> V_58 ) ;
V_19 -> V_58 = NULL ;
V_60 = true ;
goto V_61;
}
if ( F_31 ( V_19 ) )
goto V_61;
if ( V_19 -> V_51 ) {
F_21 ( V_19 -> V_58 ) ;
V_19 -> V_58 = V_19 -> V_51 ;
V_19 -> V_51 = NULL ;
V_60 = true ;
}
if ( V_19 -> V_57 ) {
F_34 ( V_19 -> V_57 ) ;
V_19 -> V_51 = V_19 -> V_57 ;
V_19 -> V_57 = NULL ;
}
V_61:
F_43 ( & V_19 -> V_33 ) ;
return V_60 ;
}
void F_44 ( struct V_1 * V_2 )
{
T_2 V_62 = ( 256 << V_63 )
| V_64 | V_65 | V_66
| V_67 ;
if ( V_2 -> V_68 )
V_62 |= V_69 | V_70 ;
F_35 ( V_2 , V_71 , V_62 ) ;
F_35 ( V_2 , V_72 , V_73 ) ;
}
void F_45 ( struct V_18 * V_19 )
{
unsigned long V_32 ;
F_16 ( & V_19 -> V_33 , V_32 ) ;
F_21 ( V_19 -> V_58 ) ;
F_21 ( V_19 -> V_51 ) ;
F_21 ( V_19 -> V_57 ) ;
F_20 ( & V_19 -> V_33 , V_32 ) ;
V_19 -> V_58 = NULL ;
V_19 -> V_51 = NULL ;
V_19 -> V_57 = NULL ;
}
static void F_46 ( struct V_18 * V_19 )
{
unsigned long V_32 ;
F_16 ( & V_19 -> V_33 , V_32 ) ;
while ( ! F_17 ( & V_19 -> V_31 ) ) {
struct V_3 * V_4 ;
V_4 = F_18 ( & V_19 -> V_31 , struct V_3 ,
V_34 ) ;
F_19 ( & V_4 -> V_34 ) ;
F_20 ( & V_19 -> V_33 , V_32 ) ;
F_8 ( V_4 ) ;
F_16 ( & V_19 -> V_33 , V_32 ) ;
}
F_20 ( & V_19 -> V_33 , V_32 ) ;
}
static void F_47 ( struct V_74 * V_75 )
{
struct V_18 * V_19 =
F_48 ( V_75 , struct V_18 , V_38 ) ;
F_46 ( V_19 ) ;
}
struct V_18 * F_49 ( struct V_1 * V_2 ,
unsigned int V_55 ,
unsigned int V_76 )
{
struct V_18 * V_19 ;
unsigned int V_77 ;
V_19 = F_50 ( V_2 -> V_78 , sizeof( * V_19 ) , V_11 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_55 = V_55 ;
V_19 -> V_23 = V_55 == 0 && ! V_2 -> V_79 -> V_80
? V_52 : V_24 ;
V_19 -> V_49 = V_2 -> V_79 -> V_80 ;
V_19 -> V_2 = V_2 ;
F_51 ( & V_19 -> V_33 ) ;
F_11 ( & V_19 -> free ) ;
F_11 ( & V_19 -> V_31 ) ;
F_52 ( & V_19 -> V_38 , F_47 ) ;
for ( V_77 = 0 ; V_77 < V_76 ; ++ V_77 ) {
struct V_17 * V_20 ;
V_20 = F_10 ( V_19 ) ;
if ( ! V_20 )
return NULL ;
F_24 ( & V_20 -> V_34 , & V_19 -> free ) ;
}
return V_19 ;
}
void F_53 ( struct V_18 * V_19 )
{
struct V_17 * V_20 , * V_46 ;
if ( ! V_19 )
return;
F_54 ( & V_19 -> V_38 ) ;
F_55 (dl, next, &dlm->free, list) {
F_19 ( & V_20 -> V_34 ) ;
F_13 ( V_20 ) ;
}
F_46 ( V_19 ) ;
}
