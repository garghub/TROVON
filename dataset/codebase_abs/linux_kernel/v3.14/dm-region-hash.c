static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return V_3 >> V_2 -> V_4 ;
}
T_2 F_2 ( struct V_1 * V_2 , T_1 V_5 )
{
return V_5 << V_2 -> V_4 ;
}
T_1 F_3 ( struct V_1 * V_2 , struct V_6 * V_6 )
{
return F_1 ( V_2 , V_6 -> V_7 . V_8 -
V_2 -> V_9 ) ;
}
void * F_4 ( struct V_10 * V_11 )
{
return V_11 -> V_2 -> V_12 ;
}
T_1 F_5 ( struct V_10 * V_11 )
{
return V_11 -> V_13 ;
}
T_2 F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_14 ;
}
struct V_1 * F_7 (
void * V_12 , void (* F_8)( void * V_12 ,
struct V_15 * V_16 ) ,
void (* F_9)( void * V_12 ) ,
void (* F_10)( void * V_12 ) ,
T_2 V_9 , unsigned V_17 ,
struct V_18 * log , T_3 V_14 ,
T_1 V_19 )
{
struct V_1 * V_2 ;
unsigned V_20 , V_21 ;
T_4 V_22 ;
V_21 = V_19 >> 6 ;
for ( V_20 = 128u ; V_20 < V_21 ; V_20 <<= 1 )
;
V_20 >>= 1 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 ) {
F_12 ( L_1 ) ;
return F_13 ( - V_24 ) ;
}
V_2 -> V_12 = V_12 ;
V_2 -> F_8 = F_8 ;
V_2 -> F_9 = F_9 ;
V_2 -> F_10 = F_10 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_17 = V_17 ;
V_2 -> log = log ;
V_2 -> V_14 = V_14 ;
V_2 -> V_4 = F_14 ( V_14 ) - 1 ;
F_15 ( & V_2 -> V_25 ) ;
V_2 -> V_26 = V_20 - 1 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = F_16 ( V_20 * sizeof( * V_2 -> V_31 ) ) ;
if ( ! V_2 -> V_31 ) {
F_12 ( L_2 ) ;
F_17 ( V_2 ) ;
return F_13 ( - V_24 ) ;
}
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ )
F_18 ( V_2 -> V_31 + V_22 ) ;
F_19 ( & V_2 -> V_32 ) ;
F_20 ( & V_2 -> V_33 , 0 ) ;
F_21 ( & V_2 -> V_34 , 0 ) ;
F_18 ( & V_2 -> V_35 ) ;
F_18 ( & V_2 -> V_36 ) ;
F_18 ( & V_2 -> V_37 ) ;
F_18 ( & V_2 -> V_38 ) ;
V_2 -> V_39 = 0 ;
V_2 -> V_40 = F_22 ( V_41 ,
sizeof( struct V_10 ) ) ;
if ( ! V_2 -> V_40 ) {
F_23 ( V_2 -> V_31 ) ;
F_17 ( V_2 ) ;
V_2 = F_13 ( - V_24 ) ;
}
return V_2 ;
}
void F_24 ( struct V_1 * V_2 )
{
unsigned V_42 ;
struct V_10 * V_11 , * V_43 ;
F_25 ( ! F_26 ( & V_2 -> V_36 ) ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_20 ; V_42 ++ ) {
F_27 (reg, nreg, rh->buckets + h,
hash_list) {
F_25 ( F_28 ( & V_11 -> V_44 ) ) ;
F_29 ( V_11 , V_2 -> V_40 ) ;
}
}
if ( V_2 -> log )
F_30 ( V_2 -> log ) ;
if ( V_2 -> V_40 )
F_31 ( V_2 -> V_40 ) ;
F_23 ( V_2 -> V_31 ) ;
F_17 ( V_2 ) ;
}
struct V_18 * F_32 ( struct V_1 * V_2 )
{
return V_2 -> log ;
}
static unsigned F_33 ( struct V_1 * V_2 , T_1 V_5 )
{
return ( unsigned ) ( ( V_5 * V_2 -> V_29 ) >> V_2 -> V_27 ) & V_2 -> V_26 ;
}
static struct V_10 * F_34 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_10 * V_11 ;
struct V_45 * V_46 = V_2 -> V_31 + F_33 ( V_2 , V_5 ) ;
F_35 (reg, bucket, hash_list)
if ( V_11 -> V_13 == V_5 )
return V_11 ;
return NULL ;
}
static void F_36 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_37 ( & V_11 -> V_47 , V_2 -> V_31 + F_33 ( V_2 , V_11 -> V_13 ) ) ;
}
static struct V_10 * F_38 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_10 * V_11 , * V_43 ;
V_43 = F_39 ( V_2 -> V_40 , V_48 ) ;
if ( F_40 ( ! V_43 ) )
V_43 = F_11 ( sizeof( * V_43 ) , V_49 | V_50 ) ;
V_43 -> V_51 = V_2 -> log -> type -> V_52 ( V_2 -> log , V_5 , 1 ) ?
V_53 : V_54 ;
V_43 -> V_2 = V_2 ;
V_43 -> V_13 = V_5 ;
F_18 ( & V_43 -> V_55 ) ;
F_21 ( & V_43 -> V_44 , 0 ) ;
F_41 ( & V_43 -> V_56 ) ;
F_42 ( & V_2 -> V_25 ) ;
V_11 = F_34 ( V_2 , V_5 ) ;
if ( V_11 )
F_29 ( V_43 , V_2 -> V_40 ) ;
else {
F_36 ( V_2 , V_43 ) ;
if ( V_43 -> V_51 == V_53 ) {
F_43 ( & V_2 -> V_32 ) ;
F_37 ( & V_43 -> V_55 , & V_2 -> V_35 ) ;
F_44 ( & V_2 -> V_32 ) ;
}
V_11 = V_43 ;
}
F_45 ( & V_2 -> V_25 ) ;
return V_11 ;
}
static struct V_10 * F_46 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_10 * V_11 ;
V_11 = F_34 ( V_2 , V_5 ) ;
if ( ! V_11 ) {
F_47 ( & V_2 -> V_25 ) ;
V_11 = F_38 ( V_2 , V_5 ) ;
F_48 ( & V_2 -> V_25 ) ;
}
return V_11 ;
}
int F_49 ( struct V_1 * V_2 , T_1 V_5 , int V_57 )
{
int V_58 ;
struct V_10 * V_11 ;
F_48 ( & V_2 -> V_25 ) ;
V_11 = F_34 ( V_2 , V_5 ) ;
F_47 ( & V_2 -> V_25 ) ;
if ( V_11 )
return V_11 -> V_51 ;
V_58 = V_2 -> log -> type -> V_52 ( V_2 -> log , V_5 , V_57 ) ;
return V_58 == 1 ? V_53 : V_54 ;
}
static void F_50 ( struct V_10 * V_11 , int V_59 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
V_2 -> log -> type -> V_60 ( V_2 -> log , V_11 -> V_13 , V_59 ) ;
V_2 -> F_8 ( V_2 -> V_12 , & V_11 -> V_56 ) ;
if ( F_51 ( & V_2 -> V_34 ) )
V_2 -> F_10 ( V_2 -> V_12 ) ;
F_52 ( & V_2 -> V_33 ) ;
}
void F_53 ( struct V_1 * V_2 , struct V_6 * V_6 )
{
unsigned long V_61 ;
struct V_18 * log = V_2 -> log ;
struct V_10 * V_11 ;
T_1 V_5 = F_3 ( V_2 , V_6 ) ;
int V_62 = 0 ;
if ( V_6 -> V_63 & V_64 ) {
V_2 -> V_39 = 1 ;
return;
}
if ( V_6 -> V_63 & V_65 )
return;
log -> type -> V_60 ( log , V_5 , 0 ) ;
F_48 ( & V_2 -> V_25 ) ;
V_11 = F_46 ( V_2 , V_5 ) ;
F_47 ( & V_2 -> V_25 ) ;
F_25 ( ! V_11 ) ;
F_25 ( ! F_26 ( & V_11 -> V_55 ) ) ;
F_54 ( & V_2 -> V_32 , V_61 ) ;
V_62 = ( V_11 -> V_51 == V_66 ) ;
V_11 -> V_51 = V_54 ;
F_25 ( ! F_26 ( & V_11 -> V_55 ) ) ;
F_55 ( & V_2 -> V_32 , V_61 ) ;
if ( V_62 )
F_50 ( V_11 , 0 ) ;
}
void F_56 ( struct V_1 * V_2 , int V_67 )
{
struct V_10 * V_11 , * V_68 ;
F_57 ( V_69 ) ;
F_57 ( V_70 ) ;
F_57 ( V_71 ) ;
F_42 ( & V_2 -> V_25 ) ;
F_43 ( & V_2 -> V_32 ) ;
if ( ! F_26 ( & V_2 -> V_35 ) ) {
F_58 ( & V_2 -> V_35 , & V_69 ) ;
F_35 (reg, &clean, list)
F_59 ( & V_11 -> V_47 ) ;
}
if ( ! F_26 ( & V_2 -> V_37 ) ) {
F_58 ( & V_2 -> V_37 , & V_70 ) ;
F_35 (reg, &recovered, list)
F_59 ( & V_11 -> V_47 ) ;
}
if ( ! F_26 ( & V_2 -> V_38 ) ) {
F_58 ( & V_2 -> V_38 ,
& V_71 ) ;
F_35 (reg, &failed_recovered, list)
F_59 ( & V_11 -> V_47 ) ;
}
F_44 ( & V_2 -> V_32 ) ;
F_45 ( & V_2 -> V_25 ) ;
F_27 (reg, next, &recovered, list) {
V_2 -> log -> type -> V_72 ( V_2 -> log , V_11 -> V_13 ) ;
F_50 ( V_11 , 1 ) ;
F_29 ( V_11 , V_2 -> V_40 ) ;
}
F_27 (reg, next, &failed_recovered, list) {
F_50 ( V_11 , V_67 ? 0 : 1 ) ;
F_29 ( V_11 , V_2 -> V_40 ) ;
}
F_27 (reg, next, &clean, list) {
V_2 -> log -> type -> V_72 ( V_2 -> log , V_11 -> V_13 ) ;
F_29 ( V_11 , V_2 -> V_40 ) ;
}
V_2 -> log -> type -> V_73 ( V_2 -> log ) ;
}
static void F_60 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_10 * V_11 ;
F_48 ( & V_2 -> V_25 ) ;
V_11 = F_46 ( V_2 , V_5 ) ;
F_61 ( & V_2 -> V_32 ) ;
F_62 ( & V_11 -> V_44 ) ;
if ( V_11 -> V_51 == V_53 ) {
V_11 -> V_51 = V_74 ;
F_63 ( & V_11 -> V_55 ) ;
F_64 ( & V_2 -> V_32 ) ;
V_2 -> log -> type -> V_75 ( V_2 -> log , V_11 -> V_13 ) ;
} else
F_64 ( & V_2 -> V_32 ) ;
F_47 ( & V_2 -> V_25 ) ;
}
void F_65 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_6 * V_6 ;
for ( V_6 = V_16 -> V_76 ; V_6 ; V_6 = V_6 -> V_77 ) {
if ( V_6 -> V_63 & ( V_64 | V_65 ) )
continue;
F_60 ( V_2 , F_3 ( V_2 , V_6 ) ) ;
}
}
void F_66 ( struct V_1 * V_2 , T_1 V_5 )
{
unsigned long V_61 ;
struct V_10 * V_11 ;
int V_78 = 0 ;
F_48 ( & V_2 -> V_25 ) ;
V_11 = F_34 ( V_2 , V_5 ) ;
F_47 ( & V_2 -> V_25 ) ;
F_54 ( & V_2 -> V_32 , V_61 ) ;
if ( F_51 ( & V_11 -> V_44 ) ) {
if ( F_40 ( V_2 -> V_39 ) ) {
V_11 -> V_51 = V_54 ;
} else if ( V_11 -> V_51 == V_66 ) {
F_67 ( & V_11 -> V_55 , & V_2 -> V_36 ) ;
} else if ( V_11 -> V_51 == V_74 ) {
V_11 -> V_51 = V_53 ;
F_37 ( & V_11 -> V_55 , & V_2 -> V_35 ) ;
}
V_78 = 1 ;
}
F_55 ( & V_2 -> V_32 , V_61 ) ;
if ( V_78 )
V_2 -> F_9 ( V_2 -> V_12 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_58 ;
T_1 V_5 ;
struct V_10 * V_11 ;
V_58 = V_2 -> log -> type -> V_79 ( V_2 -> log , & V_5 ) ;
if ( V_58 <= 0 )
return V_58 ;
F_48 ( & V_2 -> V_25 ) ;
V_11 = F_46 ( V_2 , V_5 ) ;
F_47 ( & V_2 -> V_25 ) ;
F_61 ( & V_2 -> V_32 ) ;
V_11 -> V_51 = V_66 ;
if ( F_28 ( & V_11 -> V_44 ) )
F_63 ( & V_11 -> V_55 ) ;
else
F_69 ( & V_11 -> V_55 , & V_2 -> V_36 ) ;
F_64 ( & V_2 -> V_32 ) ;
return 1 ;
}
void F_70 ( struct V_1 * V_2 )
{
F_62 ( & V_2 -> V_34 ) ;
while ( ! F_71 ( & V_2 -> V_33 ) ) {
F_62 ( & V_2 -> V_34 ) ;
if ( F_68 ( V_2 ) <= 0 ) {
F_72 ( & V_2 -> V_34 ) ;
F_52 ( & V_2 -> V_33 ) ;
break;
}
}
if ( F_51 ( & V_2 -> V_34 ) )
V_2 -> F_10 ( V_2 -> V_12 ) ;
}
struct V_10 * F_73 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = NULL ;
F_61 ( & V_2 -> V_32 ) ;
if ( ! F_26 ( & V_2 -> V_36 ) ) {
V_11 = F_74 ( V_2 -> V_36 . V_68 ,
struct V_10 , V_55 ) ;
F_63 ( & V_11 -> V_55 ) ;
}
F_64 ( & V_2 -> V_32 ) ;
return V_11 ;
}
void F_75 ( struct V_10 * V_11 , int V_59 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
F_61 ( & V_2 -> V_32 ) ;
if ( V_59 )
F_37 ( & V_11 -> V_55 , & V_11 -> V_2 -> V_37 ) ;
else
F_37 ( & V_11 -> V_55 , & V_11 -> V_2 -> V_38 ) ;
F_64 ( & V_2 -> V_32 ) ;
V_2 -> F_9 ( V_2 -> V_12 ) ;
}
int F_76 ( struct V_1 * V_2 )
{
return F_28 ( & V_2 -> V_34 ) ;
}
int F_77 ( struct V_1 * V_2 )
{
return V_2 -> log -> type -> V_73 ( V_2 -> log ) ;
}
void F_78 ( struct V_1 * V_2 , struct V_6 * V_6 )
{
struct V_10 * V_11 ;
F_48 ( & V_2 -> V_25 ) ;
V_11 = F_46 ( V_2 , F_3 ( V_2 , V_6 ) ) ;
F_79 ( & V_11 -> V_56 , V_6 ) ;
F_47 ( & V_2 -> V_25 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_17 ; V_22 ++ )
F_81 ( & V_2 -> V_33 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_17 ; V_22 ++ )
F_52 ( & V_2 -> V_33 ) ;
V_2 -> F_9 ( V_2 -> V_12 ) ;
}
