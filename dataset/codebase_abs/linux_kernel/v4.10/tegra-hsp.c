static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_4 , unsigned int V_5 )
{
return F_4 ( V_4 -> V_6 + V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_4 , T_1 V_7 ,
unsigned int V_5 )
{
F_6 ( V_7 , V_4 -> V_6 + V_5 ) ;
}
static inline T_1 F_7 ( struct V_8 * V_9 ,
unsigned int V_5 )
{
return F_4 ( V_9 -> V_6 + V_5 ) ;
}
static inline void F_8 ( struct V_8 * V_9 ,
T_1 V_7 , unsigned int V_5 )
{
F_6 ( V_7 , V_9 -> V_6 + V_5 ) ;
}
static bool F_9 ( struct V_10 * V_11 )
{
T_1 V_7 ;
V_7 = F_7 ( & V_11 -> V_9 , V_12 ) ;
return ( V_7 & F_10 ( V_13 ) ) != 0 ;
}
static struct V_10 *
F_11 ( struct V_1 * V_4 , unsigned int V_14 )
{
struct V_10 * V_15 ;
F_12 (entry, &hsp->doorbells, list)
if ( V_15 -> V_14 == V_14 )
return V_15 ;
return NULL ;
}
static struct V_10 *
F_13 ( struct V_1 * V_4 , unsigned int V_14 )
{
struct V_10 * V_11 ;
unsigned long V_16 ;
F_14 ( & V_4 -> V_17 , V_16 ) ;
V_11 = F_11 ( V_4 , V_14 ) ;
F_15 ( & V_4 -> V_17 , V_16 ) ;
return V_11 ;
}
static T_2 F_16 ( int V_18 , void * V_19 )
{
struct V_1 * V_4 = V_19 ;
struct V_10 * V_11 ;
unsigned long V_14 , V_7 ;
V_11 = F_13 ( V_4 , V_13 ) ;
if ( ! V_11 )
return V_20 ;
V_7 = F_7 ( & V_11 -> V_9 , V_21 ) ;
F_8 ( & V_11 -> V_9 , V_7 , V_21 ) ;
F_17 ( & V_4 -> V_17 ) ;
F_18 (master, &value, hsp->mbox.num_chans) {
struct V_10 * V_11 ;
V_11 = F_11 ( V_4 , V_14 ) ;
if ( V_11 && V_11 -> V_9 . V_22 )
F_19 ( V_11 -> V_9 . V_22 , NULL ) ;
}
F_20 ( & V_4 -> V_17 ) ;
return V_23 ;
}
static struct V_8 *
F_21 ( struct V_1 * V_4 , const char * V_24 ,
unsigned int V_14 , unsigned int V_25 )
{
struct V_10 * V_11 ;
unsigned int V_5 ;
unsigned long V_16 ;
V_11 = F_22 ( sizeof( * V_11 ) , V_26 ) ;
if ( ! V_11 )
return F_23 ( - V_27 ) ;
V_5 = ( 1 + ( V_4 -> V_28 / 2 ) + V_4 -> V_29 + V_4 -> V_30 ) << 16 ;
V_5 += V_25 * 0x100 ;
V_11 -> V_9 . V_6 = V_4 -> V_6 + V_5 ;
V_11 -> V_9 . V_4 = V_4 ;
V_11 -> V_24 = F_24 ( V_24 , V_26 ) ;
V_11 -> V_14 = V_14 ;
V_11 -> V_25 = V_25 ;
F_14 ( & V_4 -> V_17 , V_16 ) ;
F_25 ( & V_11 -> V_31 , & V_4 -> V_32 ) ;
F_15 ( & V_4 -> V_17 , V_16 ) ;
return & V_11 -> V_9 ;
}
static void F_26 ( struct V_10 * V_11 )
{
F_27 ( & V_11 -> V_31 ) ;
F_28 ( V_11 -> V_24 ) ;
F_29 ( V_11 ) ;
}
static int F_30 ( struct V_33 * V_22 , void * V_19 )
{
struct V_10 * V_11 = V_22 -> V_34 ;
F_8 ( & V_11 -> V_9 , 1 , V_35 ) ;
return 0 ;
}
static int F_31 ( struct V_33 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_34 ;
struct V_1 * V_4 = V_11 -> V_9 . V_4 ;
struct V_10 * V_36 ;
unsigned long V_16 ;
T_1 V_7 ;
if ( V_11 -> V_14 >= V_4 -> V_3 . V_37 ) {
F_32 ( V_4 -> V_3 . V_38 ,
L_1 ,
V_11 -> V_14 ) ;
return - V_39 ;
}
V_36 = F_13 ( V_4 , V_13 ) ;
if ( ! V_36 )
return - V_40 ;
if ( ! F_9 ( V_11 ) )
return - V_40 ;
F_14 ( & V_4 -> V_17 , V_16 ) ;
V_7 = F_7 ( & V_36 -> V_9 , V_12 ) ;
V_7 |= F_10 ( V_11 -> V_14 ) ;
F_8 ( & V_36 -> V_9 , V_7 , V_12 ) ;
F_15 ( & V_4 -> V_17 , V_16 ) ;
return 0 ;
}
static void F_33 ( struct V_33 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_34 ;
struct V_1 * V_4 = V_11 -> V_9 . V_4 ;
struct V_10 * V_36 ;
unsigned long V_16 ;
T_1 V_7 ;
V_36 = F_13 ( V_4 , V_13 ) ;
if ( ! V_36 )
return;
F_14 ( & V_4 -> V_17 , V_16 ) ;
V_7 = F_7 ( & V_36 -> V_9 , V_12 ) ;
V_7 &= ~ F_10 ( V_11 -> V_14 ) ;
F_8 ( & V_36 -> V_9 , V_7 , V_12 ) ;
F_15 ( & V_4 -> V_17 , V_16 ) ;
}
static struct V_33 * F_34 ( struct V_2 * V_3 ,
const struct V_41 * args )
{
struct V_8 * V_9 = F_23 ( - V_40 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int type = args -> args [ 0 ] ;
unsigned int V_14 = args -> args [ 1 ] ;
struct V_10 * V_11 ;
struct V_33 * V_22 ;
unsigned long V_16 ;
unsigned int V_42 ;
switch ( type ) {
case V_43 :
V_11 = F_13 ( V_4 , V_14 ) ;
if ( V_11 )
V_9 = & V_11 -> V_9 ;
break;
default:
break;
}
if ( F_35 ( V_9 ) )
return F_36 ( V_9 ) ;
F_14 ( & V_4 -> V_17 , V_16 ) ;
for ( V_42 = 0 ; V_42 < V_4 -> V_3 . V_37 ; V_42 ++ ) {
V_22 = & V_4 -> V_3 . V_44 [ V_42 ] ;
if ( ! V_22 -> V_34 ) {
V_22 -> V_34 = V_9 ;
V_9 -> V_22 = V_22 ;
break;
}
V_22 = NULL ;
}
F_15 ( & V_4 -> V_17 , V_16 ) ;
return V_22 ? : F_23 ( - V_45 ) ;
}
static void F_37 ( struct V_1 * V_4 )
{
struct V_10 * V_11 , * V_46 ;
unsigned long V_16 ;
F_14 ( & V_4 -> V_17 , V_16 ) ;
F_38 (db, tmp, &hsp->doorbells, list)
F_26 ( V_11 ) ;
F_15 ( & V_4 -> V_17 , V_16 ) ;
}
static int F_39 ( struct V_1 * V_4 )
{
const struct V_47 * V_48 = V_4 -> V_49 -> V_48 ;
struct V_8 * V_9 ;
while ( V_48 -> V_24 ) {
V_9 = F_21 ( V_4 , V_48 -> V_24 ,
V_48 -> V_14 , V_48 -> V_25 ) ;
if ( F_35 ( V_9 ) ) {
F_37 ( V_4 ) ;
return F_40 ( V_9 ) ;
}
V_48 ++ ;
}
return 0 ;
}
static int F_41 ( struct V_50 * V_51 )
{
struct V_1 * V_4 ;
struct V_52 * V_53 ;
T_1 V_7 ;
int V_54 ;
V_4 = F_42 ( & V_51 -> V_38 , sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
V_4 -> V_49 = F_43 ( & V_51 -> V_38 ) ;
F_44 ( & V_4 -> V_32 ) ;
F_45 ( & V_4 -> V_17 ) ;
V_53 = F_46 ( V_51 , V_55 , 0 ) ;
V_4 -> V_6 = F_47 ( & V_51 -> V_38 , V_53 ) ;
if ( F_35 ( V_4 -> V_6 ) )
return F_40 ( V_4 -> V_6 ) ;
V_7 = F_3 ( V_4 , V_56 ) ;
V_4 -> V_28 = ( V_7 >> V_57 ) & V_58 ;
V_4 -> V_29 = ( V_7 >> V_59 ) & V_58 ;
V_4 -> V_30 = ( V_7 >> V_60 ) & V_58 ;
V_4 -> V_61 = ( V_7 >> V_62 ) & V_58 ;
V_4 -> V_63 = ( V_7 >> V_64 ) & V_58 ;
V_54 = F_48 ( V_51 , L_2 ) ;
if ( V_54 < 0 ) {
F_32 ( & V_51 -> V_38 , L_3 , V_54 ) ;
return V_54 ;
}
V_4 -> V_18 = V_54 ;
V_4 -> V_3 . V_65 = F_34 ;
V_4 -> V_3 . V_37 = 32 ;
V_4 -> V_3 . V_38 = & V_51 -> V_38 ;
V_4 -> V_3 . V_66 = false ;
V_4 -> V_3 . V_67 = false ;
V_4 -> V_3 . V_68 = & V_69 ;
V_4 -> V_3 . V_44 = F_49 ( & V_51 -> V_38 , V_4 -> V_3 . V_37 ,
sizeof( * V_4 -> V_3 . V_44 ) ,
V_26 ) ;
if ( ! V_4 -> V_3 . V_44 )
return - V_27 ;
V_54 = F_39 ( V_4 ) ;
if ( V_54 < 0 ) {
F_32 ( & V_51 -> V_38 , L_4 , V_54 ) ;
return V_54 ;
}
F_50 ( V_51 , V_4 ) ;
V_54 = F_51 ( & V_4 -> V_3 ) ;
if ( V_54 ) {
F_32 ( & V_51 -> V_38 , L_5 , V_54 ) ;
F_37 ( V_4 ) ;
return V_54 ;
}
V_54 = F_52 ( & V_51 -> V_38 , V_4 -> V_18 , F_16 ,
V_70 , F_53 ( & V_51 -> V_38 ) , V_4 ) ;
if ( V_54 < 0 ) {
F_32 ( & V_51 -> V_38 , L_6 ,
V_4 -> V_18 , V_54 ) ;
return V_54 ;
}
return 0 ;
}
static int F_54 ( struct V_50 * V_51 )
{
struct V_1 * V_4 = F_55 ( V_51 ) ;
F_56 ( & V_4 -> V_3 ) ;
F_37 ( V_4 ) ;
return 0 ;
}
static int T_3 F_57 ( void )
{
return F_58 ( & V_71 ) ;
}
