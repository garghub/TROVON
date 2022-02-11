static unsigned F_1 ( unsigned V_1 , unsigned V_2 )
{
return F_2 ( F_3 ( V_1 , V_2 ) ) ;
}
static struct V_3 * F_4 ( struct V_4 * V_5 )
{
return F_5 ( V_5 , struct V_3 , V_3 ) ;
}
static struct V_6 * F_6 ( struct V_6 * V_7 )
{
struct V_6 * V_8 = V_7 -> V_9 ;
F_7 ( V_8 ) ;
return V_8 ;
}
static int F_8 ( struct V_10 * V_10 , unsigned V_11 )
{
V_10 -> V_12 = F_1 ( V_11 >> 4 , 16 ) ;
V_10 -> V_13 = F_9 ( V_10 -> V_12 ) ;
V_10 -> V_14 = F_10 ( sizeof( * V_10 -> V_14 ) * V_10 -> V_12 ) ;
return V_10 -> V_14 ? 0 : - V_15 ;
}
static void F_11 ( struct V_10 * V_10 )
{
F_12 ( V_10 -> V_14 ) ;
}
static int F_13 ( struct V_3 * V_5 , T_1 V_16 )
{
int V_8 = - V_15 ;
V_5 -> V_17 = F_10 ( sizeof( * V_5 -> V_17 ) * F_14 ( V_16 ) ) ;
if ( V_5 -> V_17 ) {
unsigned V_18 = F_14 ( V_16 ) ;
while ( V_18 -- )
F_15 ( & V_5 -> V_17 [ V_18 ] . V_19 , & V_5 -> free ) ;
V_5 -> V_20 = 0 ;
V_8 = F_8 ( & V_5 -> V_21 , F_14 ( V_16 ) ) ;
if ( V_8 )
F_12 ( V_5 -> V_17 ) ;
}
return V_8 ;
}
static void F_16 ( struct V_3 * V_5 )
{
F_11 ( & V_5 -> V_21 ) ;
F_12 ( V_5 -> V_17 ) ;
}
static struct V_22 * F_17 ( struct V_3 * V_5 )
{
struct V_22 * V_23 ;
F_18 ( F_14 ( V_5 -> V_20 ) >= F_14 ( V_5 -> V_16 ) ) ;
V_23 = F_19 ( F_6 ( & V_5 -> free ) , struct V_22 , V_19 ) ;
V_5 -> V_20 = F_20 ( F_14 ( V_5 -> V_20 ) + 1 ) ;
return V_23 ;
}
static struct V_22 * F_21 ( struct V_3 * V_5 , T_2 V_24 )
{
struct V_10 * V_10 = & V_5 -> V_21 ;
unsigned V_25 = F_22 ( F_23 ( V_24 ) , V_10 -> V_13 ) ;
struct V_22 * V_26 ;
struct V_27 * V_28 = & V_10 -> V_14 [ V_25 ] ;
F_24 (cur, bucket, hlist) {
if ( V_26 -> V_24 == V_24 ) {
F_25 ( & V_26 -> V_29 ) ;
F_26 ( & V_26 -> V_29 , V_28 ) ;
return V_26 ;
}
}
return NULL ;
}
static void F_27 ( struct V_3 * V_5 , struct V_22 * V_23 )
{
unsigned V_25 = F_22 ( F_23 ( V_23 -> V_24 ) , V_5 -> V_21 . V_13 ) ;
F_26 ( & V_23 -> V_29 , & V_5 -> V_21 . V_14 [ V_25 ] ) ;
}
static void F_28 ( struct V_22 * V_23 )
{
F_25 ( & V_23 -> V_29 ) ;
}
static int F_29 ( struct V_4 * V_30 , T_2 V_24 ,
bool V_31 , bool V_32 , bool V_33 ,
struct V_34 * V_34 , struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_3 * V_5 = F_4 ( V_30 ) ;
struct V_22 * V_23 ;
unsigned long V_39 ;
V_38 -> V_40 = V_41 ;
if ( V_31 )
F_30 ( & V_5 -> V_42 , V_39 ) ;
else if ( ! F_31 ( & V_5 -> V_42 , V_39 ) )
return - V_43 ;
V_23 = F_21 ( V_5 , V_24 ) ;
if ( V_23 ) {
V_38 -> V_40 = V_44 ;
V_38 -> V_45 = V_23 -> V_45 ;
}
F_32 ( & V_5 -> V_42 , V_39 ) ;
return 0 ;
}
static int F_33 ( struct V_4 * V_30 , T_2 V_24 , T_1 * V_45 )
{
int V_8 ;
struct V_3 * V_5 = F_4 ( V_30 ) ;
struct V_22 * V_23 ;
unsigned long V_39 ;
if ( ! F_31 ( & V_5 -> V_42 , V_39 ) )
return - V_43 ;
V_23 = F_21 ( V_5 , V_24 ) ;
if ( V_23 ) {
* V_45 = V_23 -> V_45 ;
V_8 = 0 ;
} else
V_8 = - V_46 ;
F_32 ( & V_5 -> V_42 , V_39 ) ;
return V_8 ;
}
static void F_34 ( struct V_4 * V_30 , T_2 V_24 , bool V_47 )
{
struct V_3 * V_5 = F_4 ( V_30 ) ;
struct V_22 * V_23 ;
V_23 = F_21 ( V_5 , V_24 ) ;
F_18 ( ! V_23 ) ;
if ( V_47 ) {
if ( ! V_23 -> V_48 ) {
V_23 -> V_48 = true ;
F_35 ( & V_23 -> V_19 , & V_5 -> V_48 ) ;
}
} else {
if ( V_23 -> V_48 ) {
V_23 -> V_49 = false ;
V_23 -> V_48 = false ;
F_35 ( & V_23 -> V_19 , & V_5 -> V_50 ) ;
}
}
}
static void F_36 ( struct V_4 * V_30 , T_2 V_24 )
{
struct V_3 * V_5 = F_4 ( V_30 ) ;
unsigned long V_39 ;
F_30 ( & V_5 -> V_42 , V_39 ) ;
F_34 ( V_30 , V_24 , true ) ;
F_32 ( & V_5 -> V_42 , V_39 ) ;
}
static void F_37 ( struct V_4 * V_30 , T_2 V_24 )
{
struct V_3 * V_5 = F_4 ( V_30 ) ;
unsigned long V_39 ;
F_30 ( & V_5 -> V_42 , V_39 ) ;
F_34 ( V_30 , V_24 , false ) ;
F_32 ( & V_5 -> V_42 , V_39 ) ;
}
static void F_38 ( struct V_3 * V_5 , struct V_22 * V_23 )
{
F_27 ( V_5 , V_23 ) ;
if ( V_23 -> V_48 )
F_15 ( & V_23 -> V_19 , & V_5 -> V_48 ) ;
else
F_15 ( & V_23 -> V_19 , & V_5 -> V_50 ) ;
}
static int F_39 ( struct V_4 * V_30 ,
T_2 V_24 , T_1 V_45 ,
T_3 V_51 , bool V_52 )
{
int V_8 ;
struct V_3 * V_5 = F_4 ( V_30 ) ;
struct V_22 * V_23 = F_17 ( V_5 ) ;
if ( V_23 ) {
V_23 -> V_45 = V_45 ;
V_23 -> V_24 = V_24 ;
V_23 -> V_48 = false ;
F_38 ( V_5 , V_23 ) ;
V_8 = 0 ;
} else
V_8 = - V_15 ;
return V_8 ;
}
static void F_40 ( struct V_4 * V_30 )
{
struct V_3 * V_5 = F_4 ( V_30 ) ;
F_16 ( V_5 ) ;
F_41 ( V_5 ) ;
}
static struct V_22 * F_42 ( struct V_3 * V_5 , T_2 V_24 )
{
struct V_22 * V_8 = F_21 ( V_5 , V_24 ) ;
F_18 ( ! V_8 ) ;
F_28 ( V_8 ) ;
F_7 ( & V_8 -> V_19 ) ;
return V_8 ;
}
static void F_43 ( struct V_4 * V_30 , T_2 V_24 )
{
struct V_3 * V_5 = F_4 ( V_30 ) ;
struct V_22 * V_23 ;
unsigned long V_39 ;
F_30 ( & V_5 -> V_42 , V_39 ) ;
V_23 = F_42 ( V_5 , V_24 ) ;
F_44 ( & V_23 -> V_19 , & V_5 -> free ) ;
F_18 ( ! F_14 ( V_5 -> V_20 ) ) ;
V_5 -> V_20 = F_20 ( F_14 ( V_5 -> V_20 ) - 1 ) ;
F_32 ( & V_5 -> V_42 , V_39 ) ;
}
static void F_45 ( struct V_4 * V_30 ,
T_2 V_53 , T_2 V_24 )
{
struct V_3 * V_5 = F_4 ( V_30 ) ;
struct V_22 * V_23 ;
unsigned long V_39 ;
F_30 ( & V_5 -> V_42 , V_39 ) ;
V_23 = F_42 ( V_5 , V_53 ) ;
V_23 -> V_24 = V_24 ;
F_38 ( V_5 , V_23 ) ;
F_32 ( & V_5 -> V_42 , V_39 ) ;
}
static struct V_22 * F_46 ( struct V_3 * V_5 )
{
struct V_6 * V_54 ;
struct V_22 * V_8 ;
if ( F_47 ( & V_5 -> V_48 ) )
return NULL ;
V_54 = F_6 ( & V_5 -> V_48 ) ;
V_8 = F_5 ( V_54 , struct V_22 , V_19 ) ;
F_15 ( V_54 , & V_5 -> V_55 ) ;
return V_8 ;
}
static int F_48 ( struct V_4 * V_30 ,
T_2 * V_24 ,
T_1 * V_45 ,
bool V_56 )
{
int V_8 = - V_46 ;
struct V_3 * V_5 = F_4 ( V_30 ) ;
struct V_22 * V_23 ;
unsigned long V_39 ;
F_30 ( & V_5 -> V_42 , V_39 ) ;
V_23 = F_46 ( V_5 ) ;
if ( V_23 ) {
* V_24 = V_23 -> V_24 ;
* V_45 = V_23 -> V_45 ;
V_8 = 0 ;
}
F_32 ( & V_5 -> V_42 , V_39 ) ;
return V_8 ;
}
static T_1 F_49 ( struct V_4 * V_30 )
{
return F_4 ( V_30 ) -> V_20 ;
}
static void F_50 ( struct V_3 * V_5 )
{
V_5 -> V_3 . V_57 = F_40 ;
V_5 -> V_3 . V_58 = F_29 ;
V_5 -> V_3 . V_59 = F_33 ;
V_5 -> V_3 . V_60 = F_36 ;
V_5 -> V_3 . V_61 = F_37 ;
V_5 -> V_3 . V_62 = F_39 ;
V_5 -> V_3 . V_63 = NULL ;
V_5 -> V_3 . V_64 = F_43 ;
V_5 -> V_3 . V_65 = F_48 ;
V_5 -> V_3 . V_66 = F_45 ;
V_5 -> V_3 . V_67 = F_49 ;
V_5 -> V_3 . V_68 = NULL ;
}
static struct V_4 * F_51 ( T_1 V_16 ,
T_4 V_69 ,
T_4 V_70 )
{
int V_8 ;
struct V_3 * V_5 = F_52 ( sizeof( * V_5 ) , V_71 ) ;
if ( ! V_5 )
return NULL ;
F_50 ( V_5 ) ;
F_53 ( & V_5 -> free ) ;
F_53 ( & V_5 -> V_50 ) ;
F_53 ( & V_5 -> V_55 ) ;
F_53 ( & V_5 -> V_48 ) ;
V_5 -> V_16 = V_16 ;
F_54 ( & V_5 -> V_42 ) ;
V_8 = F_13 ( V_5 , V_16 ) ;
if ( ! V_8 )
return & V_5 -> V_3 ;
F_41 ( V_5 ) ;
return NULL ;
}
static int T_5 F_55 ( void )
{
int V_8 = F_56 ( & V_72 ) ;
if ( V_8 < 0 )
F_57 ( L_1 , V_8 ) ;
else
F_58 ( L_2 ,
V_72 . V_73 [ 0 ] ,
V_72 . V_73 [ 1 ] ,
V_72 . V_73 [ 2 ] ) ;
return V_8 ;
}
static void T_6 F_59 ( void )
{
F_60 ( & V_72 ) ;
}
