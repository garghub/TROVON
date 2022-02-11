static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( & V_4 -> V_5 ) ;
F_3 ( V_4 -> V_1 ) ;
return V_6 ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_11 ;
V_11 = F_6 ( V_10 , V_12 ) & ~ V_13 ;
if ( V_11 & V_14 )
return 0 ;
if ( ! ( V_11 & V_15 ) ) {
V_11 |= V_15 | V_16 ;
F_7 ( V_10 , V_12 , V_11 ) ;
}
while ( ! ( F_6 ( V_10 , V_17 ) & V_18 ) ) {
F_8 ( V_4 -> V_1 ) ;
F_9 ( V_4 -> V_5 ,
F_6 ( V_10 , V_17 ) & V_18 ) ;
}
return 0 ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_11 = F_6 ( V_10 , V_12 ) ;
if ( V_11 & V_14 )
return;
if ( ! ( V_11 & V_15 ) )
return;
V_11 &= ~ ( V_16 | V_15 ) ;
F_7 ( V_10 , V_12 , V_11 | V_16 ) ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_11 = F_6 ( V_10 , V_12 ) ;
if ( V_11 & V_14 )
return 1 ;
return ! ! ( ( F_6 ( V_10 , V_17 ) & V_18 ) &&
( F_6 ( V_10 , V_12 ) & V_15 ) ) ;
}
static struct V_19 * T_3
F_12 ( struct V_9 * V_10 ,
unsigned int V_1 ,
const char * V_20 ,
const char * V_21 ,
bool V_22 )
{
int V_23 ;
struct V_3 * V_4 ;
struct V_19 * V_19 = NULL ;
struct V_24 V_25 ;
if ( ! V_10 || ! V_1 || ! V_20 || ! V_21 )
return F_13 ( - V_26 ) ;
V_4 = F_14 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return F_13 ( - V_28 ) ;
V_25 . V_20 = V_20 ;
V_25 . V_29 = & V_30 ;
V_25 . V_31 = & V_21 ;
V_25 . V_32 = 1 ;
V_25 . V_33 = V_34 ;
V_4 -> V_8 . V_25 = & V_25 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_1 = V_1 ;
F_15 ( & V_4 -> V_5 ) ;
F_16 ( V_4 -> V_1 , V_35 ) ;
V_23 = F_17 ( V_4 -> V_1 , F_1 ,
V_36 , V_20 , V_4 ) ;
if ( V_23 )
return F_13 ( V_23 ) ;
if ( V_22 )
F_7 ( V_10 , V_12 ,
( F_6 ( V_10 , V_12 ) &
~ ( V_13 | V_15 ) ) |
V_14 | V_16 ) ;
V_19 = F_18 ( NULL , & V_4 -> V_8 ) ;
if ( F_19 ( V_19 ) ) {
F_20 ( V_1 , V_4 ) ;
F_21 ( V_4 ) ;
}
return V_19 ;
}
void T_3 F_22 ( struct V_37 * V_38 ,
struct V_9 * V_10 )
{
struct V_19 * V_19 ;
unsigned int V_1 ;
const char * V_20 = V_38 -> V_20 ;
const char * V_21 ;
bool V_22 ;
F_23 ( V_38 , L_1 , & V_20 ) ;
V_22 = F_24 ( V_38 , L_2 ) ;
V_21 = F_25 ( V_38 , 0 ) ;
V_1 = F_26 ( V_38 , 0 ) ;
if ( ! V_1 )
return;
V_19 = F_12 ( V_10 , V_1 , V_20 , V_21 , V_22 ) ;
if ( F_19 ( V_19 ) )
return;
F_27 ( V_38 , V_39 , V_19 ) ;
}
static T_1 F_28 ( int V_1 , void * V_2 )
{
struct V_40 * V_4 = V_2 ;
F_2 ( & V_4 -> V_5 ) ;
F_3 ( V_4 -> V_1 ) ;
return V_6 ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_40 * V_4 = F_30 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_11 ;
V_11 = F_6 ( V_10 , V_12 ) & ~ V_13 ;
if ( ! ( V_11 & V_41 ) ) {
V_11 |= V_41 | V_16 ;
F_7 ( V_10 , V_12 , V_11 ) ;
}
while ( ! ( F_6 ( V_10 , V_17 ) & V_42 ) ) {
F_8 ( V_4 -> V_1 ) ;
F_9 ( V_4 -> V_5 ,
F_6 ( V_10 , V_17 ) & V_42 ) ;
}
return 0 ;
}
static void F_31 ( struct V_7 * V_8 )
{
struct V_40 * V_4 = F_30 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_11 = F_6 ( V_10 , V_12 ) ;
if ( ! ( V_11 & V_41 ) )
return;
V_11 &= ~ ( V_13 | V_41 ) ;
F_7 ( V_10 , V_12 , V_11 | V_16 ) ;
}
static int F_32 ( struct V_7 * V_8 )
{
struct V_40 * V_4 = F_30 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
return ! ! ( ( F_6 ( V_10 , V_17 ) & V_42 ) &&
( F_6 ( V_10 , V_12 ) & V_41 ) ) ;
}
static unsigned long F_33 ( struct V_7 * V_8 ,
unsigned long V_43 )
{
struct V_40 * V_4 = F_30 ( V_8 ) ;
return V_4 -> V_44 ;
}
static unsigned long F_34 ( struct V_7 * V_8 ,
unsigned long V_45 )
{
struct V_40 * V_4 = F_30 ( V_8 ) ;
return V_4 -> V_46 ;
}
static struct V_19 * T_3
F_35 ( struct V_9 * V_10 ,
unsigned int V_1 ,
const char * V_20 ,
T_2 V_44 , T_2 V_46 )
{
int V_23 ;
struct V_40 * V_4 ;
struct V_19 * V_19 = NULL ;
struct V_24 V_25 ;
if ( ! V_10 || ! V_1 || ! V_20 || ! V_44 )
return F_13 ( - V_26 ) ;
V_4 = F_14 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return F_13 ( - V_28 ) ;
V_25 . V_20 = V_20 ;
V_25 . V_29 = & V_47 ;
V_25 . V_31 = NULL ;
V_25 . V_32 = 0 ;
V_25 . V_33 = V_48 | V_34 ;
V_4 -> V_8 . V_25 = & V_25 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_1 = V_1 ;
V_4 -> V_44 = V_44 ;
V_4 -> V_46 = V_46 ;
F_15 ( & V_4 -> V_5 ) ;
F_16 ( V_4 -> V_1 , V_35 ) ;
V_23 = F_17 ( V_4 -> V_1 , F_28 ,
V_36 , V_20 , V_4 ) ;
if ( V_23 )
return F_13 ( V_23 ) ;
V_19 = F_18 ( NULL , & V_4 -> V_8 ) ;
if ( F_19 ( V_19 ) ) {
F_20 ( V_1 , V_4 ) ;
F_21 ( V_4 ) ;
}
return V_19 ;
}
void T_3 F_36 ( struct V_37 * V_38 ,
struct V_9 * V_10 )
{
struct V_19 * V_19 ;
unsigned int V_1 ;
T_2 V_44 = 0 ;
T_2 V_46 = 0 ;
const char * V_20 = V_38 -> V_20 ;
F_23 ( V_38 , L_1 , & V_20 ) ;
F_37 ( V_38 , L_3 , & V_44 ) ;
F_37 ( V_38 , L_4 , & V_46 ) ;
V_1 = F_26 ( V_38 , 0 ) ;
if ( ! V_1 )
return;
V_19 = F_35 ( V_10 , V_1 , V_20 , V_44 ,
V_46 ) ;
if ( F_19 ( V_19 ) )
return;
F_27 ( V_38 , V_39 , V_19 ) ;
}
static int F_38 ( struct V_9 * V_10 )
{
unsigned long V_49 , V_50 ;
T_2 V_11 ;
V_50 = V_51 + F_39 ( V_52 ) ;
do {
V_49 = V_51 ;
V_11 = F_6 ( V_10 , V_53 ) ;
if ( V_11 & V_54 )
return 0 ;
F_40 ( V_55 , V_56 ) ;
} while ( F_41 ( V_49 , V_50 ) );
return - V_57 ;
}
static unsigned long F_42 ( struct V_9 * V_10 ,
unsigned long V_43 )
{
T_2 V_11 ;
if ( V_43 )
return V_43 ;
F_43 ( L_5 ) ;
V_11 = F_6 ( V_10 , V_53 ) ;
if ( ! ( V_11 & V_54 ) )
return 0 ;
return ( ( V_11 & V_58 ) * V_59 ) / V_60 ;
}
static int F_44 ( struct V_7 * V_8 )
{
struct V_61 * V_62 = F_45 ( V_8 ) ;
return F_38 ( V_62 -> V_10 ) ;
}
static int F_46 ( struct V_7 * V_8 )
{
struct V_61 * V_62 = F_45 ( V_8 ) ;
return ! ! ( F_6 ( V_62 -> V_10 , V_53 ) & V_54 ) ;
}
static unsigned long F_47 ( struct V_7 * V_8 ,
unsigned long V_43 )
{
struct V_61 * V_62 = F_45 ( V_8 ) ;
return F_42 ( V_62 -> V_10 , V_43 ) ;
}
static struct V_19 * T_3
F_48 ( struct V_9 * V_10 ,
const char * V_20 ,
const char * V_21 )
{
struct V_61 * V_62 ;
struct V_19 * V_19 = NULL ;
struct V_24 V_25 ;
if ( ! V_10 || ! V_20 )
return F_13 ( - V_26 ) ;
if ( ! V_21 )
return F_13 ( - V_26 ) ;
V_62 = F_14 ( sizeof( * V_62 ) , V_27 ) ;
if ( ! V_62 )
return F_13 ( - V_28 ) ;
V_25 . V_20 = V_20 ;
V_25 . V_29 = & V_63 ;
V_25 . V_31 = & V_21 ;
V_25 . V_32 = 1 ;
V_25 . V_33 = 0 ;
V_62 -> V_8 . V_25 = & V_25 ;
V_62 -> V_10 = V_10 ;
V_19 = F_18 ( NULL , & V_62 -> V_8 ) ;
if ( F_19 ( V_19 ) )
F_21 ( V_62 ) ;
return V_19 ;
}
void T_3 F_49 ( struct V_37 * V_38 ,
struct V_9 * V_10 )
{
struct V_19 * V_19 ;
const char * V_21 ;
const char * V_20 = V_38 -> V_20 ;
V_21 = F_25 ( V_38 , 0 ) ;
F_23 ( V_38 , L_1 , & V_20 ) ;
V_19 = F_48 ( V_10 , V_20 , V_21 ) ;
if ( F_19 ( V_19 ) )
return;
F_27 ( V_38 , V_39 , V_19 ) ;
}
static T_1 F_50 ( int V_1 , void * V_2 )
{
struct V_64 * V_62 = V_2 ;
F_2 ( & V_62 -> V_5 ) ;
F_3 ( V_62 -> V_1 ) ;
return V_6 ;
}
static int F_51 ( struct V_7 * V_8 )
{
struct V_64 * V_62 = F_52 ( V_8 ) ;
struct V_9 * V_10 = V_62 -> V_10 ;
while ( ! ( F_6 ( V_10 , V_17 ) & V_65 ) ) {
F_8 ( V_62 -> V_1 ) ;
F_9 ( V_62 -> V_5 ,
F_6 ( V_10 , V_17 ) & V_65 ) ;
}
return F_38 ( V_10 ) ;
}
static int F_53 ( struct V_7 * V_8 )
{
struct V_64 * V_62 = F_52 ( V_8 ) ;
return ! ! ( F_6 ( V_62 -> V_10 , V_17 ) & V_65 ) ;
}
static unsigned long F_54 ( struct V_7 * V_8 ,
unsigned long V_43 )
{
struct V_64 * V_62 = F_52 ( V_8 ) ;
return F_42 ( V_62 -> V_10 , V_43 ) ;
}
static int F_55 ( struct V_7 * V_8 , T_4 V_66 )
{
struct V_64 * V_62 = F_52 ( V_8 ) ;
struct V_9 * V_10 = V_62 -> V_10 ;
T_2 V_11 ;
if ( V_66 > 1 )
return - V_26 ;
V_11 = F_6 ( V_10 , V_12 ) & ~ V_13 ;
if ( V_66 && ! ( V_11 & V_67 ) )
F_7 ( V_10 , V_12 , V_11 | V_67 ) ;
else if ( ! V_66 && ( V_11 & V_67 ) )
F_7 ( V_10 , V_12 , V_11 & ~ V_67 ) ;
while ( ! ( F_6 ( V_10 , V_17 ) & V_65 ) ) {
F_8 ( V_62 -> V_1 ) ;
F_9 ( V_62 -> V_5 ,
F_6 ( V_10 , V_17 ) & V_65 ) ;
}
return 0 ;
}
static T_4 F_56 ( struct V_7 * V_8 )
{
struct V_64 * V_62 = F_52 ( V_8 ) ;
return ! ! ( F_6 ( V_62 -> V_10 , V_12 ) & V_15 ) ;
}
static struct V_19 * T_3
F_57 ( struct V_9 * V_10 ,
unsigned int V_1 ,
const char * V_20 ,
const char * * V_31 ,
int V_32 )
{
int V_23 ;
struct V_64 * V_62 ;
struct V_19 * V_19 = NULL ;
struct V_24 V_25 ;
if ( ! V_10 || ! V_1 || ! V_20 )
return F_13 ( - V_26 ) ;
if ( ! V_31 || ! V_32 )
return F_13 ( - V_26 ) ;
V_62 = F_14 ( sizeof( * V_62 ) , V_27 ) ;
if ( ! V_62 )
return F_13 ( - V_28 ) ;
V_25 . V_20 = V_20 ;
V_25 . V_29 = & V_68 ;
V_25 . V_31 = V_31 ;
V_25 . V_32 = V_32 ;
V_25 . V_33 = V_69 ;
V_62 -> V_8 . V_25 = & V_25 ;
V_62 -> V_10 = V_10 ;
V_62 -> V_1 = V_1 ;
V_62 -> V_70 = ! ! ( F_6 ( V_62 -> V_10 , V_12 ) &
V_15 ) ;
F_15 ( & V_62 -> V_5 ) ;
F_16 ( V_62 -> V_1 , V_35 ) ;
V_23 = F_17 ( V_62 -> V_1 , F_50 ,
V_36 , V_20 , V_62 ) ;
if ( V_23 )
return F_13 ( V_23 ) ;
V_19 = F_18 ( NULL , & V_62 -> V_8 ) ;
if ( F_19 ( V_19 ) ) {
F_20 ( V_62 -> V_1 , V_62 ) ;
F_21 ( V_62 ) ;
}
return V_19 ;
}
void T_3 F_58 ( struct V_37 * V_38 ,
struct V_9 * V_10 )
{
struct V_19 * V_19 ;
const char * V_31 [ 2 ] ;
int V_32 ;
unsigned int V_1 ;
const char * V_20 = V_38 -> V_20 ;
int V_71 ;
V_32 = F_59 ( V_38 , L_6 , L_7 ) ;
if ( V_32 <= 0 || V_32 > 2 )
return;
for ( V_71 = 0 ; V_71 < V_32 ; ++ V_71 ) {
V_31 [ V_71 ] = F_25 ( V_38 , V_71 ) ;
if ( ! V_31 [ V_71 ] )
return;
}
F_23 ( V_38 , L_1 , & V_20 ) ;
V_1 = F_26 ( V_38 , 0 ) ;
if ( ! V_1 )
return;
V_19 = F_57 ( V_10 , V_1 , V_20 , V_31 ,
V_32 ) ;
if ( F_19 ( V_19 ) )
return;
F_27 ( V_38 , V_39 , V_19 ) ;
}
