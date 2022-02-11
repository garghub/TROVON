static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , V_6 ;
if ( V_2 -> V_7 <= 0 ) {
V_2 -> V_7 = 0 ;
return 0 ;
}
V_2 -> V_8 [ 0 ] = V_2 -> V_9 >> V_10 ;
for ( V_5 = 1 ; V_5 < V_2 -> V_7 ; V_5 ++ )
V_2 -> V_8 [ V_5 ] = V_2 -> V_8 [ V_5 - 1 ] + 1 ;
V_6 = F_2 ( V_4 , V_2 -> V_8 , V_2 -> V_7 ,
V_11 | V_12 , V_2 -> V_13 ) ;
if ( V_6 > 0 && V_6 != V_2 -> V_7 ) {
F_3 ( V_4 , V_2 -> V_8 , V_6 ) ;
V_2 -> V_7 = 0 ;
return 0 ;
}
return V_6 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_3 ( V_4 , V_2 -> V_8 , V_2 -> V_7 ) ;
V_2 -> V_7 = 0 ;
F_5 ( V_2 -> V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_14 , unsigned int V_15 )
{
int V_6 = 0 ;
if ( ! V_15 || V_2 -> V_7 )
return - V_16 ;
V_2 -> V_9 = V_14 ;
V_2 -> V_7 = ( ( V_14 & ~ V_17 ) + V_15 + ( V_18 - 1 ) ) >> V_10 ;
if ( ! V_2 -> V_7 )
return - V_16 ;
V_2 -> V_8 = F_7 ( V_2 -> V_7 ,
sizeof( * V_2 -> V_8 ) +
sizeof( * V_2 -> V_13 ) ,
V_19 ) ;
if ( F_8 ( ! V_2 -> V_8 ) )
return - V_20 ;
V_2 -> V_13 = V_2 -> V_8 + V_2 -> V_7 ;
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 > 0 )
return V_6 ;
else if ( ! V_6 )
V_6 = - V_16 ;
F_5 ( V_2 -> V_8 ) ;
return V_6 ;
}
static int F_9 ( struct V_21 * V_22 , int V_23 )
{
V_22 -> V_24 = F_7 ( V_23 , sizeof( * V_22 -> V_24 ) , V_19 ) ;
if ( F_8 ( F_10 ( V_22 -> V_24 ) ) ) {
V_22 -> V_25 = 0 ;
return - V_20 ;
}
V_22 -> V_25 = V_23 ;
return 0 ;
}
static void F_11 ( struct V_21 * V_22 ,
struct V_3 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_22 -> V_25 ; V_5 ++ )
F_4 ( V_22 -> V_24 + V_5 , V_4 ) ;
if ( V_22 -> V_25 ) {
F_5 ( V_22 -> V_24 ) ;
V_22 -> V_24 = NULL ;
V_22 -> V_25 = 0 ;
}
}
static bool F_12 ( struct V_21 * V_22 ,
unsigned long V_14 )
{
struct V_1 * V_2 = V_22 -> V_24 ;
unsigned long V_26 = V_14 >> V_10 ;
int V_5 , V_27 ;
for ( V_5 = 0 ; V_5 < V_22 -> V_25 ; V_5 ++ , V_2 ++ )
for ( V_27 = 0 ; V_27 < V_2 -> V_7 ; V_27 ++ )
if ( V_2 -> V_8 [ V_5 ] == V_26 )
return true ;
return false ;
}
static inline void F_13 (
struct V_21 * V_22 ,
unsigned long * V_28 )
{
struct V_1 * V_2 ;
int V_5 , V_27 , V_29 ;
V_29 = 0 ;
for ( V_5 = 0 ; V_5 < V_22 -> V_25 ; V_5 ++ ) {
V_2 = V_22 -> V_24 + V_5 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_7 ; V_27 ++ ) {
V_28 [ V_29 ] = V_2 -> V_13 [ V_27 ] << V_10 ;
if ( V_29 == 0 )
V_28 [ V_29 ] += V_2 -> V_9 & ( V_18 - 1 ) ;
V_29 ++ ;
}
}
}
static long F_14 ( struct V_3 * V_4 ,
void * V_30 , T_1 V_14 ,
unsigned long V_31 )
{
struct V_1 V_2 = { 0 } ;
T_1 V_32 ;
int V_5 , V_6 ;
unsigned long V_33 , V_34 ;
V_6 = F_6 ( & V_2 , V_4 , V_14 , V_31 ) ;
if ( V_6 <= 0 )
return V_6 ;
V_33 = V_31 ;
for ( V_5 = 0 ; V_5 < V_2 . V_7 ; V_5 ++ ) {
V_32 = V_2 . V_13 [ V_5 ] << V_10 ;
V_34 = V_18 ;
if ( V_5 == 0 ) {
V_32 += V_14 & ( V_18 - 1 ) ;
V_34 -= V_14 & ( V_18 - 1 ) ;
}
V_34 = F_15 ( V_33 , V_34 ) ;
memcpy ( V_30 + ( V_31 - V_33 ) , ( void * ) V_32 , V_34 ) ;
V_33 -= V_34 ;
if ( V_33 == 0 )
break;
}
F_4 ( & V_2 , V_4 ) ;
return V_33 ;
}
static long F_16 ( struct V_35 * V_36 ,
struct V_37 * V_30 , T_1 V_14 ,
unsigned long V_15 )
{
struct V_38 V_38 ;
struct V_37 * V_39 ;
int V_6 ;
int V_5 ;
V_6 = F_14 ( V_36 -> V_4 , V_30 , V_14 , V_15 * sizeof( struct V_37 ) ) ;
if ( V_6 )
return V_6 ;
if ( ! V_36 -> V_40 . V_41 . V_42 ) {
V_39 = V_30 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
V_38 = * (struct V_38 * ) V_39 ;
if ( ( V_39 -> V_43 & 0x0f ) == V_44 ) {
V_39 -> V_43 = V_44 ;
V_39 -> V_45 = 0 ;
V_39 -> V_46 = 0 ;
} else {
V_39 -> V_43 = V_38 . V_43 ;
V_39 -> V_45 = V_38 . V_45 ;
V_39 -> V_46 = V_38 . V_46 ;
}
V_39 -> V_47 = V_38 . V_47 ;
V_39 ++ ;
}
}
return V_6 ;
}
static struct V_48 * F_17 ( struct V_35 * V_36 , int V_15 )
{
struct V_48 * V_49 ;
void * V_50 ;
T_2 V_51 ;
V_51 = ( ( sizeof( * V_49 ) + 7L ) & - 8L ) +
sizeof( * V_49 -> V_52 ) * V_15 +
sizeof( * V_49 -> V_53 ) * V_15 ;
V_49 = F_18 ( V_51 , V_54 | V_19 ) ;
if ( ! V_49 )
return NULL ;
V_50 = ( V_55 * ) V_49 + ( ( sizeof( * V_49 ) + 7L ) & - 8L ) ;
V_49 -> V_52 = (struct V_37 * ) V_50 ;
V_50 = ( V_55 * ) ( V_49 -> V_52 ) + sizeof( * V_49 -> V_52 ) * V_15 ;
V_49 -> V_53 = (struct V_21 * ) V_50 ;
V_49 -> V_56 = V_15 ;
F_19 ( & V_49 -> V_57 , & V_36 -> V_58 ) ;
return V_49 ;
}
static void F_20 ( struct V_48 * V_49 )
{
F_21 ( & V_49 -> V_57 ) ;
F_5 ( V_49 ) ;
}
static void F_22 ( struct V_48 * V_49 , int V_59 )
{
struct V_37 * V_60 = V_49 -> V_52 + V_59 ;
if ( ! V_60 -> V_46 )
return;
F_5 ( ( void * ) ( T_1 ) V_60 -> V_47 ) ;
}
static void F_23 ( struct V_35 * V_36 )
{
struct V_48 * V_49 , * V_61 ;
int V_5 ;
F_24 (chain, temp, &cp->ccwchain_list, next) {
for ( V_5 = 0 ; V_5 < V_49 -> V_56 ; V_5 ++ ) {
F_11 ( V_49 -> V_53 + V_5 ,
V_36 -> V_4 ) ;
F_22 ( V_49 , V_5 ) ;
}
F_20 ( V_49 ) ;
}
}
static int F_25 ( T_1 V_14 , struct V_35 * V_36 )
{
struct V_37 * V_60 , * V_62 ;
int V_63 ;
V_62 = V_60 = F_7 ( V_64 , sizeof( * V_60 ) , V_19 ) ;
if ( ! V_60 )
return - V_20 ;
V_63 = F_16 ( V_36 , V_60 , V_14 , V_64 ) ;
if ( V_63 ) {
F_5 ( V_60 ) ;
return V_63 ;
}
V_63 = 0 ;
do {
V_63 ++ ;
if ( ( ! F_26 ( V_60 ) ) && ( ! F_27 ( V_60 ) ) )
break;
V_60 ++ ;
} while ( V_63 < V_64 + 1 );
if ( V_63 == V_64 + 1 )
V_63 = - V_16 ;
F_5 ( V_62 ) ;
return V_63 ;
}
static int F_28 ( struct V_37 * V_65 , struct V_35 * V_36 )
{
struct V_48 * V_49 ;
T_3 V_66 , V_67 ;
F_29 (chain, &cp->ccwchain_list, next) {
V_66 = V_49 -> V_68 ;
V_67 = V_66 + ( V_49 -> V_56 - 1 ) * sizeof( struct V_37 ) ;
if ( ( V_66 <= V_65 -> V_47 ) && ( V_65 -> V_47 <= V_67 ) )
return 1 ;
}
return 0 ;
}
static int F_30 ( struct V_37 * V_65 , struct V_35 * V_36 )
{
struct V_48 * V_49 ;
int V_15 , V_6 ;
if ( F_28 ( V_65 , V_36 ) )
return 0 ;
V_15 = F_25 ( V_65 -> V_47 , V_36 ) ;
if ( V_15 < 0 )
return V_15 ;
V_49 = F_17 ( V_36 , V_15 ) ;
if ( ! V_49 )
return - V_20 ;
V_49 -> V_68 = V_65 -> V_47 ;
V_6 = F_16 ( V_36 , V_49 -> V_52 , V_65 -> V_47 , V_15 ) ;
if ( V_6 ) {
F_20 ( V_49 ) ;
return V_6 ;
}
return F_31 ( V_49 , V_36 ) ;
}
static int F_31 ( struct V_48 * V_49 , struct V_35 * V_36 )
{
struct V_37 * V_65 ;
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_49 -> V_56 ; V_5 ++ ) {
V_65 = V_49 -> V_52 + V_5 ;
if ( ! F_27 ( V_65 ) )
continue;
V_6 = F_30 ( V_65 , V_36 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
static int F_32 ( struct V_48 * V_49 ,
int V_59 ,
struct V_35 * V_36 )
{
struct V_37 * V_60 = V_49 -> V_52 + V_59 ;
struct V_48 * V_69 ;
T_3 V_66 , V_67 ;
F_29 (iter, &cp->ccwchain_list, next) {
V_66 = V_69 -> V_68 ;
V_67 = V_66 + ( V_69 -> V_56 - 1 ) * sizeof( struct V_37 ) ;
if ( ( V_66 <= V_60 -> V_47 ) && ( V_60 -> V_47 <= V_67 ) ) {
V_60 -> V_47 = ( V_70 ) ( V_71 ) ( V_69 -> V_52 +
( V_60 -> V_47 - V_66 ) ) ;
return 0 ;
}
}
return - V_72 ;
}
static int F_33 ( struct V_48 * V_49 ,
int V_59 ,
struct V_35 * V_36 )
{
struct V_37 * V_60 ;
struct V_21 * V_22 ;
unsigned long * V_28 ;
int V_73 ;
V_60 = V_49 -> V_52 + V_59 ;
V_22 = V_49 -> V_53 + V_59 ;
if ( F_9 ( V_22 , 1 ) )
return - V_20 ;
V_73 = F_6 ( V_22 -> V_24 , V_36 -> V_4 ,
V_60 -> V_47 , V_60 -> V_46 ) ;
if ( V_73 < 0 )
return V_73 ;
V_28 = F_7 ( V_73 , sizeof( * V_28 ) , V_54 | V_19 ) ;
if ( ! V_28 ) {
F_11 ( V_22 , V_36 -> V_4 ) ;
return - V_20 ;
}
V_60 -> V_47 = ( V_70 ) F_34 ( V_28 ) ;
V_60 -> V_45 |= V_74 ;
F_13 ( V_22 , V_28 ) ;
return 0 ;
}
static int F_35 ( struct V_48 * V_49 ,
int V_59 ,
struct V_35 * V_36 )
{
struct V_37 * V_60 ;
struct V_21 * V_22 ;
unsigned long * V_28 ;
T_1 V_75 ;
unsigned int V_73 , V_76 ;
int V_5 , V_6 ;
V_60 = V_49 -> V_52 + V_59 ;
V_6 = F_14 ( V_36 -> V_4 , & V_75 , V_60 -> V_47 , sizeof( V_75 ) ) ;
if ( V_6 )
return V_6 ;
V_73 = F_36 ( ( void * ) ( V_75 ) , V_60 -> V_46 ) ;
V_76 = V_73 * sizeof( * V_28 ) ;
V_22 = V_49 -> V_53 + V_59 ;
V_6 = F_9 ( V_22 , V_73 ) ;
if ( V_6 )
return V_6 ;
V_28 = F_18 ( V_76 , V_54 | V_19 ) ;
if ( ! V_28 ) {
V_6 = - V_20 ;
goto V_77;
}
V_6 = F_14 ( V_36 -> V_4 , V_28 , V_60 -> V_47 , V_76 ) ;
if ( V_6 )
goto V_78;
V_60 -> V_47 = F_34 ( V_28 ) ;
for ( V_5 = 0 ; V_5 < V_73 ; V_5 ++ ) {
V_75 = * ( V_28 + V_5 ) ;
if ( F_37 ( V_75 ) ) {
V_6 = - V_72 ;
goto V_78;
}
V_6 = F_6 ( V_22 -> V_24 + V_5 , V_36 -> V_4 ,
V_75 , 1 ) ;
if ( V_6 < 0 )
goto V_78;
}
F_13 ( V_22 , V_28 ) ;
return 0 ;
V_78:
F_5 ( V_28 ) ;
V_77:
F_11 ( V_22 , V_36 -> V_4 ) ;
return V_6 ;
}
static int F_38 ( struct V_48 * V_49 ,
int V_59 ,
struct V_35 * V_36 )
{
struct V_37 * V_60 = V_49 -> V_52 + V_59 ;
if ( F_39 ( V_60 ) || F_40 ( V_60 ) )
return 0 ;
if ( F_27 ( V_60 ) )
return F_32 ( V_49 , V_59 , V_36 ) ;
if ( F_41 ( V_60 ) )
return F_35 ( V_49 , V_59 , V_36 ) ;
return F_33 ( V_49 , V_59 , V_36 ) ;
}
int F_42 ( struct V_35 * V_36 , struct V_3 * V_4 , union V_40 * V_40 )
{
T_1 V_14 = V_40 -> V_41 . V_79 ;
struct V_48 * V_49 ;
int V_15 , V_6 ;
if ( ! V_40 -> V_41 . V_80 || ! V_40 -> V_41 . V_81 || V_40 -> V_41 . V_82 )
return - V_83 ;
F_43 ( & V_36 -> V_58 ) ;
memcpy ( & V_36 -> V_40 , V_40 , sizeof( * V_40 ) ) ;
V_36 -> V_4 = V_4 ;
V_15 = F_25 ( V_14 , V_36 ) ;
if ( V_15 < 0 )
return V_15 ;
V_49 = F_17 ( V_36 , V_15 ) ;
if ( ! V_49 )
return - V_20 ;
V_49 -> V_68 = V_14 ;
V_6 = F_16 ( V_36 , V_49 -> V_52 , V_14 , V_15 ) ;
if ( V_6 ) {
F_20 ( V_49 ) ;
return V_6 ;
}
V_6 = F_31 ( V_49 , V_36 ) ;
if ( V_6 )
F_23 ( V_36 ) ;
return V_6 ;
}
void F_44 ( struct V_35 * V_36 )
{
F_23 ( V_36 ) ;
}
int F_45 ( struct V_35 * V_36 )
{
struct V_48 * V_49 ;
int V_15 , V_59 , V_6 ;
F_29 (chain, &cp->ccwchain_list, next) {
V_15 = V_49 -> V_56 ;
for ( V_59 = 0 ; V_59 < V_15 ; V_59 ++ ) {
V_6 = F_38 ( V_49 , V_59 , V_36 ) ;
if ( V_6 )
return V_6 ;
}
}
return 0 ;
}
union V_40 * F_46 ( struct V_35 * V_36 , T_3 V_84 , V_55 V_85 )
{
union V_40 * V_40 ;
struct V_48 * V_49 ;
struct V_37 * V_79 ;
V_40 = & V_36 -> V_40 ;
V_40 -> V_41 . V_84 = V_84 ;
V_40 -> V_41 . V_42 = 1 ;
V_40 -> V_41 . V_86 = V_87 >> 4 ;
if ( V_40 -> V_41 . V_85 == 0 )
V_40 -> V_41 . V_85 = V_85 ;
V_49 = F_47 ( & V_36 -> V_58 , struct V_48 , V_57 ) ;
V_79 = V_49 -> V_52 ;
V_40 -> V_41 . V_79 = ( V_70 ) F_48 ( V_79 ) ;
return V_40 ;
}
void F_49 ( struct V_35 * V_36 , union V_88 * V_88 )
{
struct V_48 * V_49 ;
T_3 V_79 = V_88 -> V_41 . V_79 ;
T_3 V_66 , V_67 ;
F_29 (chain, &cp->ccwchain_list, next) {
V_66 = ( T_3 ) ( T_1 ) V_49 -> V_52 ;
V_67 = ( T_3 ) ( T_1 ) ( V_49 -> V_52 + V_49 -> V_56 - 1 ) ;
if ( ( V_66 <= V_79 ) && ( V_79 <= V_67 ) ) {
V_79 = V_49 -> V_68 + ( V_79 - V_66 ) ;
break;
}
}
V_88 -> V_41 . V_79 = V_79 ;
}
bool F_50 ( struct V_35 * V_36 , T_1 V_14 )
{
struct V_48 * V_49 ;
int V_5 ;
F_29 (chain, &cp->ccwchain_list, next) {
for ( V_5 = 0 ; V_5 < V_49 -> V_56 ; V_5 ++ )
if ( F_12 ( V_49 -> V_53 + V_5 ,
V_14 ) )
return true ;
}
return false ;
}
