void F_1 ( struct V_1 * V_2 )
{
}
void F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_4 , V_7 , V_6 -> V_8 . V_9 ) ;
* V_6 -> V_10 &= ~ V_7 ;
F_7 ( V_4 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
* V_6 -> V_10 |= V_7 ;
F_6 ( V_4 , * V_6 -> V_10 , V_6 -> V_8 . V_7 ) ;
F_7 ( V_4 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
* V_6 -> V_10 &= ~ V_7 ;
F_6 ( V_4 , * V_6 -> V_10 , V_6 -> V_8 . V_7 ) ;
F_7 ( V_4 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_4 , V_7 , V_6 -> V_8 . V_11 ) ;
* V_6 -> V_10 |= V_7 ;
F_7 ( V_4 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_4 , V_7 , V_6 -> V_8 . V_12 ) ;
F_7 ( V_4 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = ~ V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_4 , V_7 , V_6 -> V_8 . V_12 ) ;
F_7 ( V_4 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_4 , V_7 , V_6 -> V_8 . V_7 ) ;
F_6 ( V_4 , V_7 , V_6 -> V_8 . V_12 ) ;
F_7 ( V_4 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_4 , V_7 , V_6 -> V_8 . V_13 ) ;
F_7 ( V_4 ) ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
T_1 V_7 = V_2 -> V_7 ;
if ( ! ( V_7 & V_4 -> V_15 ) )
return - V_16 ;
F_5 ( V_4 ) ;
if ( V_14 )
V_4 -> V_17 |= V_7 ;
else
V_4 -> V_17 &= ~ V_7 ;
F_7 ( V_4 ) ;
return 0 ;
}
static T_1 F_16 ( void T_2 * V_18 )
{
return F_17 ( V_18 ) ;
}
static void F_18 ( T_1 V_19 , void T_2 * V_18 )
{
F_19 ( V_19 , V_18 ) ;
}
void F_20 ( struct V_3 * V_4 , const char * V_20 ,
int V_21 , unsigned int V_22 ,
void T_2 * V_23 , T_3 V_24 )
{
F_21 ( & V_4 -> V_25 ) ;
V_4 -> V_21 = V_21 ;
V_4 -> V_22 = V_22 ;
V_4 -> V_23 = V_23 ;
V_4 -> V_26 -> V_27 . V_20 = V_20 ;
V_4 -> V_26 -> V_24 = V_24 ;
}
struct V_3 *
F_22 ( const char * V_20 , int V_21 , unsigned int V_22 ,
void T_2 * V_23 , T_3 V_24 )
{
struct V_3 * V_4 ;
unsigned long V_28 = sizeof( * V_4 ) + V_21 * sizeof( struct V_5 ) ;
V_4 = F_23 ( V_28 , V_29 ) ;
if ( V_4 ) {
F_20 ( V_4 , V_20 , V_21 , V_22 , V_23 ,
V_24 ) ;
}
return V_4 ;
}
static void
F_24 ( struct V_3 * V_4 , enum V_30 V_31 )
{
struct V_5 * V_6 = V_4 -> V_26 ;
T_1 * V_32 = & V_4 -> V_10 , V_33 = V_6 -> V_8 . V_7 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_4 -> V_21 ; V_34 ++ ) {
if ( V_31 & V_35 ) {
V_32 = & V_6 [ V_34 ] . V_36 ;
V_33 = V_6 [ V_34 ] . V_8 . V_7 ;
}
V_6 [ V_34 ] . V_10 = V_32 ;
if ( V_31 & V_37 )
* V_32 = F_25 ( V_4 , V_33 ) ;
}
}
int F_26 ( struct V_38 * V_2 , int V_39 ,
int V_21 , const char * V_20 ,
T_3 V_24 ,
unsigned int V_40 , unsigned int V_41 ,
enum V_30 V_42 )
{
struct V_43 * V_44 ;
struct V_3 * V_4 ;
int V_45 , V_28 , V_34 ;
unsigned long V_31 ;
void * V_46 ;
if ( V_2 -> V_4 )
return - V_47 ;
V_45 = F_27 ( V_2 -> V_48 , V_39 ) ;
if ( ! V_45 )
return - V_16 ;
V_28 = sizeof( * V_44 ) + V_45 * sizeof( V_4 ) ;
V_28 += V_45 * ( sizeof( * V_4 ) + V_21 * sizeof( struct V_5 ) ) ;
V_46 = V_44 = F_23 ( V_28 , V_29 ) ;
if ( ! V_44 )
return - V_49 ;
V_44 -> V_39 = V_39 ;
V_44 -> V_50 = V_45 ;
V_44 -> V_51 = V_41 ;
V_44 -> V_52 = V_40 ;
V_44 -> V_53 = V_42 ;
V_2 -> V_4 = V_44 ;
V_46 += sizeof( * V_44 ) + V_45 * sizeof( V_4 ) ;
for ( V_34 = 0 ; V_34 < V_45 ; V_34 ++ ) {
V_44 -> V_4 [ V_34 ] = V_4 = V_46 ;
F_20 ( V_4 , V_20 , V_21 , V_34 * V_39 ,
NULL , V_24 ) ;
V_4 -> V_54 = V_2 ;
if ( V_42 & V_55 ) {
V_4 -> V_56 = & F_16 ;
V_4 -> V_57 = & F_18 ;
}
F_28 ( & V_58 , V_31 ) ;
F_29 ( & V_4 -> V_59 , & V_60 ) ;
F_30 ( & V_58 , V_31 ) ;
V_46 += sizeof( * V_4 ) + V_21 * sizeof( struct V_5 ) ;
}
V_2 -> V_20 = V_20 ;
return 0 ;
}
static struct V_3 *
F_31 ( struct V_38 * V_2 , unsigned int V_61 )
{
struct V_43 * V_44 = V_2 -> V_4 ;
int V_62 ;
if ( ! V_44 )
return F_32 ( - V_63 ) ;
V_62 = V_61 / V_44 -> V_39 ;
if ( V_62 >= V_44 -> V_50 )
return F_32 ( - V_16 ) ;
return V_44 -> V_4 [ V_62 ] ;
}
struct V_3 *
F_33 ( struct V_38 * V_2 , unsigned int V_61 )
{
struct V_3 * V_4 = F_31 ( V_2 , V_61 ) ;
return ! F_34 ( V_4 ) ? V_4 : NULL ;
}
int F_35 ( struct V_38 * V_2 , unsigned int V_64 ,
T_4 V_61 )
{
struct V_1 * V_65 = F_36 ( V_2 , V_64 ) ;
struct V_43 * V_44 = V_2 -> V_4 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_66 * V_27 ;
unsigned long V_31 ;
int V_62 ;
V_4 = F_31 ( V_2 , V_61 ) ;
if ( F_34 ( V_4 ) )
return F_37 ( V_4 ) ;
V_62 = V_61 % V_44 -> V_39 ;
if ( F_38 ( V_62 , & V_4 -> V_67 ) )
return - V_68 ;
if ( F_38 ( V_62 , & V_4 -> V_69 ) )
return - V_47 ;
V_6 = V_4 -> V_26 ;
V_27 = & V_6 -> V_27 ;
if ( ! V_4 -> V_69 ) {
F_28 ( & V_4 -> V_25 , V_31 ) ;
F_24 ( V_4 , V_44 -> V_53 ) ;
F_30 ( & V_4 -> V_25 , V_31 ) ;
}
F_39 ( V_62 , & V_4 -> V_69 ) ;
if ( V_44 -> V_53 & V_70 )
F_40 ( V_64 , & V_71 ) ;
if ( V_27 -> V_72 )
V_27 -> V_72 ( V_65 ) ;
else
V_65 -> V_7 = 1 << V_62 ;
F_41 ( V_2 , V_64 , V_61 , V_27 , V_4 , V_6 -> V_24 , NULL , NULL ) ;
F_42 ( V_64 , V_44 -> V_52 , V_44 -> V_51 ) ;
return 0 ;
}
static void F_43 ( struct V_38 * V_2 , unsigned int V_64 )
{
struct V_1 * V_65 = F_36 ( V_2 , V_64 ) ;
struct V_43 * V_44 = V_2 -> V_4 ;
unsigned int V_61 = V_65 -> V_73 ;
struct V_3 * V_4 ;
int V_74 ;
V_4 = F_33 ( V_2 , V_61 ) ;
if ( ! V_4 )
return;
V_74 = V_61 % V_44 -> V_39 ;
F_44 ( V_74 , & V_4 -> V_69 ) ;
F_41 ( V_2 , V_64 , V_61 , & V_75 , NULL , NULL , NULL ,
NULL ) ;
}
void F_45 ( struct V_3 * V_4 , T_1 V_76 ,
enum V_30 V_31 , unsigned int V_40 ,
unsigned int V_41 )
{
struct V_5 * V_6 = V_4 -> V_26 ;
struct V_66 * V_27 = & V_6 -> V_27 ;
unsigned int V_34 ;
F_46 ( & V_58 ) ;
F_29 ( & V_4 -> V_59 , & V_60 ) ;
F_47 ( & V_58 ) ;
F_24 ( V_4 , V_31 ) ;
for ( V_34 = V_4 -> V_22 ; V_76 ; V_76 >>= 1 , V_34 ++ ) {
if ( ! ( V_76 & 0x01 ) )
continue;
if ( V_31 & V_70 )
F_40 ( V_34 , & V_71 ) ;
if ( ! ( V_31 & V_77 ) ) {
struct V_1 * V_2 = F_48 ( V_34 ) ;
if ( V_27 -> V_72 )
V_27 -> V_72 ( V_2 ) ;
else
V_2 -> V_7 = 1 << ( V_34 - V_4 -> V_22 ) ;
}
F_49 ( V_34 , V_27 , V_6 -> V_24 ) ;
F_50 ( V_34 , V_4 ) ;
F_42 ( V_34 , V_40 , V_41 ) ;
}
V_4 -> V_78 = V_34 - V_4 -> V_22 ;
}
int F_51 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_26 ;
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < V_4 -> V_21 ; V_34 ++ , V_6 ++ ) {
if ( V_6 -> type & type ) {
V_2 -> V_27 = & V_6 -> V_27 ;
F_52 ( V_2 ) -> V_79 = V_6 -> V_24 ;
return 0 ;
}
}
return - V_16 ;
}
void F_53 ( struct V_3 * V_4 , T_1 V_76 ,
unsigned int V_40 , unsigned int V_41 )
{
unsigned int V_34 = V_4 -> V_22 ;
F_46 ( & V_58 ) ;
F_54 ( & V_4 -> V_59 ) ;
F_47 ( & V_58 ) ;
for (; V_76 ; V_76 >>= 1 , V_34 ++ ) {
if ( ! ( V_76 & 0x01 ) )
continue;
F_55 ( V_34 , NULL ) ;
F_56 ( V_34 , & V_75 ) ;
F_50 ( V_34 , NULL ) ;
F_42 ( V_34 , V_40 , V_41 ) ;
}
}
static struct V_1 * F_57 ( struct V_3 * V_4 )
{
unsigned int V_64 ;
if ( ! V_4 -> V_54 )
return F_48 ( V_4 -> V_22 ) ;
if ( ! V_4 -> V_69 )
return NULL ;
V_64 = F_58 ( V_4 -> V_54 , V_4 -> V_22 + F_59 ( V_4 -> V_69 ) ) ;
return V_64 ? F_48 ( V_64 ) : NULL ;
}
static int F_60 ( void )
{
struct V_3 * V_4 ;
F_61 (gc, &gc_list, list) {
struct V_5 * V_6 = V_4 -> V_26 ;
if ( V_6 -> V_27 . V_80 ) {
struct V_1 * V_65 = F_57 ( V_4 ) ;
if ( V_65 )
V_6 -> V_27 . V_80 ( V_65 ) ;
}
if ( V_4 -> V_81 )
V_4 -> V_81 ( V_4 ) ;
}
return 0 ;
}
static void F_62 ( void )
{
struct V_3 * V_4 ;
F_61 (gc, &gc_list, list) {
struct V_5 * V_6 = V_4 -> V_26 ;
if ( V_4 -> V_82 )
V_4 -> V_82 ( V_4 ) ;
if ( V_6 -> V_27 . V_83 ) {
struct V_1 * V_65 = F_57 ( V_4 ) ;
if ( V_65 )
V_6 -> V_27 . V_83 ( V_65 ) ;
}
}
}
static void F_63 ( void )
{
struct V_3 * V_4 ;
F_61 (gc, &gc_list, list) {
struct V_5 * V_6 = V_4 -> V_26 ;
if ( V_6 -> V_27 . V_84 ) {
struct V_1 * V_65 = F_57 ( V_4 ) ;
if ( V_65 )
V_6 -> V_27 . V_84 ( V_65 ) ;
}
}
}
static int T_5 F_64 ( void )
{
F_65 ( & V_85 ) ;
return 0 ;
}
