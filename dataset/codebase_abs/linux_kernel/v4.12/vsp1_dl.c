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
} else {
V_20 -> V_29 -> V_32 = V_49 ;
}
}
void F_31 ( struct V_17 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_19 ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned long V_32 ;
bool V_50 ;
F_16 ( & V_19 -> V_33 , V_32 ) ;
if ( V_20 -> V_19 -> V_23 == V_24 ) {
struct V_17 * V_36 ;
F_29 ( V_20 , F_17 ( & V_20 -> V_35 ) ) ;
F_22 (dl_child, &dl->chain, chain) {
bool V_51 = F_32 ( & V_36 -> V_35 , & V_20 -> V_35 ) ;
F_29 ( V_36 , V_51 ) ;
}
F_33 ( V_2 , F_34 ( V_19 -> V_52 ) , V_20 -> V_10 ) ;
V_19 -> V_53 = V_20 ;
goto V_54;
}
V_50 = ! ! ( F_35 ( V_2 , V_55 ) & V_56 ) ;
if ( V_50 ) {
F_21 ( V_19 -> V_57 ) ;
V_19 -> V_57 = V_20 ;
goto V_54;
}
F_33 ( V_2 , F_34 ( 0 ) , V_20 -> V_26 . V_10 ) ;
F_33 ( V_2 , V_55 , V_56 |
( V_20 -> V_26 . V_5 * sizeof( * V_20 -> V_29 -> V_30 ) ) ) ;
F_21 ( V_19 -> V_58 ) ;
V_19 -> V_58 = V_20 ;
V_54:
F_20 ( & V_19 -> V_33 , V_32 ) ;
}
void F_36 ( struct V_18 * V_19 )
{
F_37 ( & V_19 -> V_33 ) ;
F_21 ( V_19 -> V_53 ) ;
V_19 -> V_53 = NULL ;
F_38 ( & V_19 -> V_33 ) ;
}
void F_39 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
F_37 ( & V_19 -> V_33 ) ;
F_21 ( V_19 -> V_53 ) ;
V_19 -> V_53 = NULL ;
if ( V_19 -> V_23 == V_24 )
goto V_54;
if ( F_35 ( V_2 , V_55 ) & V_56 )
goto V_54;
if ( V_19 -> V_58 ) {
V_19 -> V_53 = V_19 -> V_58 ;
V_19 -> V_58 = NULL ;
}
if ( V_19 -> V_57 ) {
struct V_17 * V_20 = V_19 -> V_57 ;
F_33 ( V_2 , F_34 ( 0 ) , V_20 -> V_26 . V_10 ) ;
F_33 ( V_2 , V_55 , V_56 |
( V_20 -> V_26 . V_5 *
sizeof( * V_20 -> V_29 -> V_30 ) ) ) ;
V_19 -> V_58 = V_20 ;
V_19 -> V_57 = NULL ;
}
V_54:
F_38 ( & V_19 -> V_33 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
T_2 V_59 = ( 256 << V_60 )
| V_61 | V_62 | V_63
| V_64 ;
if ( V_2 -> V_65 )
V_59 |= V_66 | V_67 ;
F_33 ( V_2 , V_68 , V_59 ) ;
F_33 ( V_2 , V_69 , V_70 ) ;
}
void F_41 ( struct V_18 * V_19 )
{
unsigned long V_32 ;
F_16 ( & V_19 -> V_33 , V_32 ) ;
F_21 ( V_19 -> V_53 ) ;
F_21 ( V_19 -> V_58 ) ;
F_21 ( V_19 -> V_57 ) ;
F_20 ( & V_19 -> V_33 , V_32 ) ;
V_19 -> V_53 = NULL ;
V_19 -> V_58 = NULL ;
V_19 -> V_57 = NULL ;
}
static void F_42 ( struct V_18 * V_19 )
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
static void F_43 ( struct V_71 * V_72 )
{
struct V_18 * V_19 =
F_44 ( V_72 , struct V_18 , V_38 ) ;
F_42 ( V_19 ) ;
}
struct V_18 * F_45 ( struct V_1 * V_2 ,
unsigned int V_52 ,
unsigned int V_73 )
{
struct V_18 * V_19 ;
unsigned int V_74 ;
V_19 = F_46 ( V_2 -> V_9 , sizeof( * V_19 ) , V_11 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_52 = V_52 ;
V_19 -> V_23 = V_52 == 0 && ! V_2 -> V_75 -> V_76
? V_77 : V_24 ;
V_19 -> V_2 = V_2 ;
F_47 ( & V_19 -> V_33 ) ;
F_11 ( & V_19 -> free ) ;
F_11 ( & V_19 -> V_31 ) ;
F_48 ( & V_19 -> V_38 , F_43 ) ;
for ( V_74 = 0 ; V_74 < V_73 ; ++ V_74 ) {
struct V_17 * V_20 ;
V_20 = F_10 ( V_19 ) ;
if ( ! V_20 )
return NULL ;
F_24 ( & V_20 -> V_34 , & V_19 -> free ) ;
}
return V_19 ;
}
void F_49 ( struct V_18 * V_19 )
{
struct V_17 * V_20 , * V_46 ;
if ( ! V_19 )
return;
F_50 ( & V_19 -> V_38 ) ;
F_51 (dl, next, &dlm->free, list) {
F_19 ( & V_20 -> V_34 ) ;
F_13 ( V_20 ) ;
}
F_42 ( V_19 ) ;
}
