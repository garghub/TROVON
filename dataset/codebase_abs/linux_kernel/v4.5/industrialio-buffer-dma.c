static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ,
struct V_2 , V_1 ) ;
F_3 ( V_3 -> V_4 != V_5 ) ;
F_4 ( V_3 -> V_6 -> V_7 , F_5 ( V_3 -> V_8 ) ,
V_3 -> V_9 , V_3 -> V_10 ) ;
F_6 ( & V_3 -> V_6 -> V_11 ) ;
F_7 ( V_3 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
F_9 ( & V_3 -> V_1 ) ;
}
static void F_10 ( struct V_2 * V_3 )
{
F_11 ( & V_3 -> V_1 , F_1 ) ;
}
static void F_12 ( struct V_12 * V_13 )
{
struct V_2 * V_3 , * V_14 ;
F_13 ( V_15 ) ;
F_14 ( & V_16 ) ;
F_15 ( & V_17 , & V_15 ) ;
F_16 ( & V_16 ) ;
F_17 (block, _block, &block_list, head)
F_1 ( & V_3 -> V_1 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
unsigned long V_18 ;
V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
F_19 ( & V_16 , V_18 ) ;
F_20 ( & V_3 -> V_19 , & V_17 ) ;
F_21 ( & V_16 , V_18 ) ;
F_22 ( & V_20 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
F_11 ( & V_3 -> V_1 , F_18 ) ;
}
static struct V_21 * F_24 ( struct V_22 * V_23 )
{
return F_2 ( V_23 , struct V_21 , V_11 ) ;
}
static struct V_2 * F_25 (
struct V_21 * V_6 , T_1 V_8 )
{
struct V_2 * V_3 ;
V_3 = F_26 ( sizeof( * V_3 ) , V_24 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_9 = F_27 ( V_6 -> V_7 , F_5 ( V_8 ) ,
& V_3 -> V_10 , V_24 ) ;
if ( ! V_3 -> V_9 ) {
F_7 ( V_3 ) ;
return NULL ;
}
V_3 -> V_8 = V_8 ;
V_3 -> V_4 = V_25 ;
V_3 -> V_6 = V_6 ;
F_28 ( & V_3 -> V_19 ) ;
F_29 ( & V_3 -> V_1 ) ;
F_30 ( & V_6 -> V_11 ) ;
return V_3 ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_21 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_4 != V_5 ) {
V_3 -> V_4 = V_26 ;
F_20 ( & V_3 -> V_19 , & V_6 -> V_27 ) ;
}
}
void F_32 ( struct V_2 * V_3 )
{
struct V_21 * V_6 = V_3 -> V_6 ;
unsigned long V_18 ;
F_19 ( & V_6 -> V_28 , V_18 ) ;
F_31 ( V_3 ) ;
F_21 ( & V_6 -> V_28 , V_18 ) ;
F_23 ( V_3 ) ;
F_33 ( & V_6 -> V_11 . V_29 , V_30 | V_31 ) ;
}
void F_34 ( struct V_21 * V_6 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 , * V_14 ;
unsigned long V_18 ;
F_19 ( & V_6 -> V_28 , V_18 ) ;
F_17 (block, _block, list, head) {
F_35 ( & V_3 -> V_19 ) ;
V_3 -> V_34 = 0 ;
F_31 ( V_3 ) ;
F_23 ( V_3 ) ;
}
F_21 ( & V_6 -> V_28 , V_18 ) ;
F_33 ( & V_6 -> V_11 . V_29 , V_30 | V_31 ) ;
}
static bool F_36 ( struct V_2 * V_3 )
{
switch ( V_3 -> V_4 ) {
case V_25 :
case V_35 :
case V_26 :
return true ;
default:
return false ;
}
}
int F_37 ( struct V_22 * V_11 )
{
struct V_21 * V_6 = F_24 ( V_11 ) ;
struct V_2 * V_3 ;
bool V_36 = false ;
T_1 V_8 ;
int V_37 = 0 ;
int V_38 ;
V_8 = F_38 ( V_6 -> V_11 . V_39 *
V_6 -> V_11 . V_40 , 2 ) ;
F_39 ( & V_6 -> V_41 ) ;
if ( F_5 ( V_6 -> V_42 . V_43 ) == F_5 ( V_8 ) )
V_36 = true ;
V_6 -> V_42 . V_43 = V_8 ;
V_6 -> V_42 . V_44 = NULL ;
F_14 ( & V_6 -> V_28 ) ;
for ( V_38 = 0 ; V_38 < 2 ; V_38 ++ ) {
V_3 = V_6 -> V_42 . V_45 [ V_38 ] ;
if ( V_3 && ( ! F_36 ( V_3 ) || ! V_36 ) )
V_3 -> V_4 = V_5 ;
}
F_28 ( & V_6 -> V_27 ) ;
F_16 ( & V_6 -> V_28 ) ;
F_28 ( & V_6 -> V_46 ) ;
for ( V_38 = 0 ; V_38 < 2 ; V_38 ++ ) {
if ( V_6 -> V_42 . V_45 [ V_38 ] ) {
V_3 = V_6 -> V_42 . V_45 [ V_38 ] ;
if ( V_3 -> V_4 == V_5 ) {
F_10 ( V_3 ) ;
V_3 = NULL ;
} else {
V_3 -> V_8 = V_8 ;
}
} else {
V_3 = NULL ;
}
if ( ! V_3 ) {
V_3 = F_25 ( V_6 , V_8 ) ;
if ( ! V_3 ) {
V_37 = - V_47 ;
goto V_48;
}
V_6 -> V_42 . V_45 [ V_38 ] = V_3 ;
}
V_3 -> V_4 = V_35 ;
F_20 ( & V_3 -> V_19 , & V_6 -> V_46 ) ;
}
V_48:
F_40 ( & V_6 -> V_41 ) ;
return V_37 ;
}
static void F_41 ( struct V_21 * V_6 ,
struct V_2 * V_3 )
{
int V_37 ;
if ( ! V_6 -> V_49 )
return;
V_3 -> V_4 = V_50 ;
F_8 ( V_3 ) ;
V_37 = V_6 -> V_49 -> V_51 ( V_6 , V_3 ) ;
if ( V_37 ) {
F_10 ( V_3 ) ;
}
}
int F_42 ( struct V_22 * V_11 ,
struct V_52 * V_53 )
{
struct V_21 * V_6 = F_24 ( V_11 ) ;
struct V_2 * V_3 , * V_14 ;
F_39 ( & V_6 -> V_41 ) ;
V_6 -> V_54 = true ;
F_17 (block, _block, &queue->incoming, head) {
F_35 ( & V_3 -> V_19 ) ;
F_41 ( V_6 , V_3 ) ;
}
F_40 ( & V_6 -> V_41 ) ;
return 0 ;
}
int F_43 ( struct V_22 * V_11 ,
struct V_52 * V_53 )
{
struct V_21 * V_6 = F_24 ( V_11 ) ;
F_39 ( & V_6 -> V_41 ) ;
V_6 -> V_54 = false ;
if ( V_6 -> V_49 && V_6 -> V_49 -> abort )
V_6 -> V_49 -> abort ( V_6 ) ;
F_40 ( & V_6 -> V_41 ) ;
return 0 ;
}
static void F_44 ( struct V_21 * V_6 ,
struct V_2 * V_3 )
{
if ( V_3 -> V_4 == V_5 ) {
F_10 ( V_3 ) ;
} else if ( V_6 -> V_54 ) {
F_41 ( V_6 , V_3 ) ;
} else {
V_3 -> V_4 = V_35 ;
F_20 ( & V_3 -> V_19 , & V_6 -> V_46 ) ;
}
}
static struct V_2 * F_45 (
struct V_21 * V_6 )
{
struct V_2 * V_3 ;
F_14 ( & V_6 -> V_28 ) ;
V_3 = F_46 ( & V_6 -> V_27 , struct
V_2 , V_19 ) ;
if ( V_3 != NULL ) {
F_35 ( & V_3 -> V_19 ) ;
V_3 -> V_4 = V_25 ;
}
F_16 ( & V_6 -> V_28 ) ;
return V_3 ;
}
int F_47 ( struct V_22 * V_11 , T_1 V_55 ,
char T_2 * V_56 )
{
struct V_21 * V_6 = F_24 ( V_11 ) ;
struct V_2 * V_3 ;
int V_37 ;
if ( V_55 < V_11 -> V_39 )
return - V_57 ;
F_39 ( & V_6 -> V_41 ) ;
if ( ! V_6 -> V_42 . V_44 ) {
V_3 = F_45 ( V_6 ) ;
if ( V_3 == NULL ) {
V_37 = 0 ;
goto V_48;
}
V_6 -> V_42 . V_58 = 0 ;
V_6 -> V_42 . V_44 = V_3 ;
} else {
V_3 = V_6 -> V_42 . V_44 ;
}
V_55 = F_48 ( V_55 , V_11 -> V_39 ) ;
if ( V_55 > V_3 -> V_34 - V_6 -> V_42 . V_58 )
V_55 = V_3 -> V_34 - V_6 -> V_42 . V_58 ;
if ( F_49 ( V_56 , V_3 -> V_9 + V_6 -> V_42 . V_58 , V_55 ) ) {
V_37 = - V_59 ;
goto V_48;
}
V_6 -> V_42 . V_58 += V_55 ;
if ( V_6 -> V_42 . V_58 == V_3 -> V_34 ) {
V_6 -> V_42 . V_44 = NULL ;
F_44 ( V_6 , V_3 ) ;
}
V_37 = V_55 ;
V_48:
F_40 ( & V_6 -> V_41 ) ;
return V_37 ;
}
T_1 F_50 ( struct V_22 * V_23 )
{
struct V_21 * V_6 = F_24 ( V_23 ) ;
struct V_2 * V_3 ;
T_1 V_60 = 0 ;
F_39 ( & V_6 -> V_41 ) ;
if ( V_6 -> V_42 . V_44 )
V_60 += V_6 -> V_42 . V_44 -> V_8 ;
F_14 ( & V_6 -> V_28 ) ;
F_51 (block, &queue->outgoing, head)
V_60 += V_3 -> V_8 ;
F_16 ( & V_6 -> V_28 ) ;
F_40 ( & V_6 -> V_41 ) ;
return V_60 ;
}
int F_52 ( struct V_22 * V_11 , T_1 V_61 )
{
V_11 -> V_39 = V_61 ;
return 0 ;
}
int F_53 ( struct V_22 * V_11 , int V_40 )
{
if ( V_40 < 2 )
V_40 = 2 ;
V_11 -> V_40 = V_40 ;
V_11 -> V_62 = V_40 / 2 ;
return 0 ;
}
int F_54 ( struct V_21 * V_6 ,
struct V_63 * V_7 , const struct V_64 * V_49 )
{
F_55 ( & V_6 -> V_11 ) ;
V_6 -> V_11 . V_40 = V_65 ;
V_6 -> V_11 . V_62 = V_6 -> V_11 . V_40 / 2 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_49 = V_49 ;
F_28 ( & V_6 -> V_46 ) ;
F_28 ( & V_6 -> V_27 ) ;
F_56 ( & V_6 -> V_41 ) ;
F_57 ( & V_6 -> V_28 ) ;
return 0 ;
}
void F_58 ( struct V_21 * V_6 )
{
unsigned int V_38 ;
F_39 ( & V_6 -> V_41 ) ;
F_14 ( & V_6 -> V_28 ) ;
for ( V_38 = 0 ; V_38 < F_59 ( V_6 -> V_42 . V_45 ) ; V_38 ++ ) {
if ( ! V_6 -> V_42 . V_45 [ V_38 ] )
continue;
V_6 -> V_42 . V_45 [ V_38 ] -> V_4 = V_5 ;
}
F_28 ( & V_6 -> V_27 ) ;
F_16 ( & V_6 -> V_28 ) ;
F_28 ( & V_6 -> V_46 ) ;
for ( V_38 = 0 ; V_38 < F_59 ( V_6 -> V_42 . V_45 ) ; V_38 ++ ) {
if ( ! V_6 -> V_42 . V_45 [ V_38 ] )
continue;
F_10 ( V_6 -> V_42 . V_45 [ V_38 ] ) ;
V_6 -> V_42 . V_45 [ V_38 ] = NULL ;
}
V_6 -> V_42 . V_44 = NULL ;
V_6 -> V_49 = NULL ;
F_40 ( & V_6 -> V_41 ) ;
}
void F_60 ( struct V_21 * V_6 )
{
F_61 ( & V_6 -> V_41 ) ;
}
