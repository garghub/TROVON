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
return F_1 ( V_2 , V_6 -> V_7 - V_2 -> V_8 ) ;
}
void * F_4 ( struct V_9 * V_10 )
{
return V_10 -> V_2 -> V_11 ;
}
T_1 F_5 ( struct V_9 * V_10 )
{
return V_10 -> V_12 ;
}
T_2 F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_13 ;
}
struct V_1 * F_7 (
void * V_11 , void (* F_8)( void * V_11 ,
struct V_14 * V_15 ) ,
void (* F_9)( void * V_11 ) ,
void (* F_10)( void * V_11 ) ,
T_2 V_8 , unsigned V_16 ,
struct V_17 * log , T_3 V_13 ,
T_1 V_18 )
{
struct V_1 * V_2 ;
unsigned V_19 , V_20 ;
T_4 V_21 ;
V_20 = V_18 >> 6 ;
for ( V_19 = 128u ; V_19 < V_20 ; V_19 <<= 1 )
;
V_19 >>= 1 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 ) {
F_12 ( L_1 ) ;
return F_13 ( - V_23 ) ;
}
V_2 -> V_11 = V_11 ;
V_2 -> F_8 = F_8 ;
V_2 -> F_9 = F_9 ;
V_2 -> F_10 = F_10 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_16 = V_16 ;
V_2 -> log = log ;
V_2 -> V_13 = V_13 ;
V_2 -> V_4 = F_14 ( V_13 ) - 1 ;
F_15 ( & V_2 -> V_24 ) ;
V_2 -> V_25 = V_19 - 1 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = F_16 ( V_19 * sizeof( * V_2 -> V_30 ) ) ;
if ( ! V_2 -> V_30 ) {
F_12 ( L_2 ) ;
F_17 ( V_2 ) ;
return F_13 ( - V_23 ) ;
}
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ )
F_18 ( V_2 -> V_30 + V_21 ) ;
F_19 ( & V_2 -> V_31 ) ;
F_20 ( & V_2 -> V_32 , 0 ) ;
F_21 ( & V_2 -> V_33 , 0 ) ;
F_18 ( & V_2 -> V_34 ) ;
F_18 ( & V_2 -> V_35 ) ;
F_18 ( & V_2 -> V_36 ) ;
F_18 ( & V_2 -> V_37 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = F_22 ( V_40 ,
sizeof( struct V_9 ) ) ;
if ( ! V_2 -> V_39 ) {
F_23 ( V_2 -> V_30 ) ;
F_17 ( V_2 ) ;
V_2 = F_13 ( - V_23 ) ;
}
return V_2 ;
}
void F_24 ( struct V_1 * V_2 )
{
unsigned V_41 ;
struct V_9 * V_10 , * V_42 ;
F_25 ( ! F_26 ( & V_2 -> V_35 ) ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_19 ; V_41 ++ ) {
F_27 (reg, nreg, rh->buckets + h,
hash_list) {
F_25 ( F_28 ( & V_10 -> V_43 ) ) ;
F_29 ( V_10 , V_2 -> V_39 ) ;
}
}
if ( V_2 -> log )
F_30 ( V_2 -> log ) ;
if ( V_2 -> V_39 )
F_31 ( V_2 -> V_39 ) ;
F_23 ( V_2 -> V_30 ) ;
F_17 ( V_2 ) ;
}
struct V_17 * F_32 ( struct V_1 * V_2 )
{
return V_2 -> log ;
}
static unsigned F_33 ( struct V_1 * V_2 , T_1 V_5 )
{
return ( unsigned ) ( ( V_5 * V_2 -> V_28 ) >> V_2 -> V_26 ) & V_2 -> V_25 ;
}
static struct V_9 * F_34 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_9 * V_10 ;
struct V_44 * V_45 = V_2 -> V_30 + F_33 ( V_2 , V_5 ) ;
F_35 (reg, bucket, hash_list)
if ( V_10 -> V_12 == V_5 )
return V_10 ;
return NULL ;
}
static void F_36 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_37 ( & V_10 -> V_46 , V_2 -> V_30 + F_33 ( V_2 , V_10 -> V_12 ) ) ;
}
static struct V_9 * F_38 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_9 * V_10 , * V_42 ;
V_42 = F_39 ( V_2 -> V_39 , V_47 ) ;
if ( F_40 ( ! V_42 ) )
V_42 = F_11 ( sizeof( * V_42 ) , V_48 | V_49 ) ;
V_42 -> V_50 = V_2 -> log -> type -> V_51 ( V_2 -> log , V_5 , 1 ) ?
V_52 : V_53 ;
V_42 -> V_2 = V_2 ;
V_42 -> V_12 = V_5 ;
F_18 ( & V_42 -> V_54 ) ;
F_21 ( & V_42 -> V_43 , 0 ) ;
F_41 ( & V_42 -> V_55 ) ;
F_42 ( & V_2 -> V_24 ) ;
V_10 = F_34 ( V_2 , V_5 ) ;
if ( V_10 )
F_29 ( V_42 , V_2 -> V_39 ) ;
else {
F_36 ( V_2 , V_42 ) ;
if ( V_42 -> V_50 == V_52 ) {
F_43 ( & V_2 -> V_31 ) ;
F_37 ( & V_42 -> V_54 , & V_2 -> V_34 ) ;
F_44 ( & V_2 -> V_31 ) ;
}
V_10 = V_42 ;
}
F_45 ( & V_2 -> V_24 ) ;
return V_10 ;
}
static struct V_9 * F_46 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_9 * V_10 ;
V_10 = F_34 ( V_2 , V_5 ) ;
if ( ! V_10 ) {
F_47 ( & V_2 -> V_24 ) ;
V_10 = F_38 ( V_2 , V_5 ) ;
F_48 ( & V_2 -> V_24 ) ;
}
return V_10 ;
}
int F_49 ( struct V_1 * V_2 , T_1 V_5 , int V_56 )
{
int V_57 ;
struct V_9 * V_10 ;
F_48 ( & V_2 -> V_24 ) ;
V_10 = F_34 ( V_2 , V_5 ) ;
F_47 ( & V_2 -> V_24 ) ;
if ( V_10 )
return V_10 -> V_50 ;
V_57 = V_2 -> log -> type -> V_51 ( V_2 -> log , V_5 , V_56 ) ;
return V_57 == 1 ? V_52 : V_53 ;
}
static void F_50 ( struct V_9 * V_10 , int V_58 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> log -> type -> V_59 ( V_2 -> log , V_10 -> V_12 , V_58 ) ;
V_2 -> F_8 ( V_2 -> V_11 , & V_10 -> V_55 ) ;
if ( F_51 ( & V_2 -> V_33 ) )
V_2 -> F_10 ( V_2 -> V_11 ) ;
F_52 ( & V_2 -> V_32 ) ;
}
void F_53 ( struct V_1 * V_2 , struct V_6 * V_6 )
{
unsigned long V_60 ;
struct V_17 * log = V_2 -> log ;
struct V_9 * V_10 ;
T_1 V_5 = F_3 ( V_2 , V_6 ) ;
int V_61 = 0 ;
if ( V_6 -> V_62 & V_63 ) {
V_2 -> V_38 = 1 ;
return;
}
if ( V_6 -> V_62 & V_64 )
return;
log -> type -> V_59 ( log , V_5 , 0 ) ;
F_48 ( & V_2 -> V_24 ) ;
V_10 = F_46 ( V_2 , V_5 ) ;
F_47 ( & V_2 -> V_24 ) ;
F_25 ( ! V_10 ) ;
F_25 ( ! F_26 ( & V_10 -> V_54 ) ) ;
F_54 ( & V_2 -> V_31 , V_60 ) ;
V_61 = ( V_10 -> V_50 == V_65 ) ;
V_10 -> V_50 = V_53 ;
F_25 ( ! F_26 ( & V_10 -> V_54 ) ) ;
F_55 ( & V_2 -> V_31 , V_60 ) ;
if ( V_61 )
F_50 ( V_10 , 0 ) ;
}
void F_56 ( struct V_1 * V_2 , int V_66 )
{
struct V_9 * V_10 , * V_67 ;
F_57 ( V_68 ) ;
F_57 ( V_69 ) ;
F_57 ( V_70 ) ;
F_42 ( & V_2 -> V_24 ) ;
F_43 ( & V_2 -> V_31 ) ;
if ( ! F_26 ( & V_2 -> V_34 ) ) {
F_58 ( & V_2 -> V_34 , & V_68 ) ;
F_35 (reg, &clean, list)
F_59 ( & V_10 -> V_46 ) ;
}
if ( ! F_26 ( & V_2 -> V_36 ) ) {
F_58 ( & V_2 -> V_36 , & V_69 ) ;
F_35 (reg, &recovered, list)
F_59 ( & V_10 -> V_46 ) ;
}
if ( ! F_26 ( & V_2 -> V_37 ) ) {
F_58 ( & V_2 -> V_37 ,
& V_70 ) ;
F_35 (reg, &failed_recovered, list)
F_59 ( & V_10 -> V_46 ) ;
}
F_44 ( & V_2 -> V_31 ) ;
F_45 ( & V_2 -> V_24 ) ;
F_27 (reg, next, &recovered, list) {
V_2 -> log -> type -> V_71 ( V_2 -> log , V_10 -> V_12 ) ;
F_50 ( V_10 , 1 ) ;
F_29 ( V_10 , V_2 -> V_39 ) ;
}
F_27 (reg, next, &failed_recovered, list) {
F_50 ( V_10 , V_66 ? 0 : 1 ) ;
F_29 ( V_10 , V_2 -> V_39 ) ;
}
F_27 (reg, next, &clean, list) {
V_2 -> log -> type -> V_71 ( V_2 -> log , V_10 -> V_12 ) ;
F_29 ( V_10 , V_2 -> V_39 ) ;
}
V_2 -> log -> type -> V_72 ( V_2 -> log ) ;
}
static void F_60 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_9 * V_10 ;
F_48 ( & V_2 -> V_24 ) ;
V_10 = F_46 ( V_2 , V_5 ) ;
F_61 ( & V_2 -> V_31 ) ;
F_62 ( & V_10 -> V_43 ) ;
if ( V_10 -> V_50 == V_52 ) {
V_10 -> V_50 = V_73 ;
F_63 ( & V_10 -> V_54 ) ;
F_64 ( & V_2 -> V_31 ) ;
V_2 -> log -> type -> V_74 ( V_2 -> log , V_10 -> V_12 ) ;
} else
F_64 ( & V_2 -> V_31 ) ;
F_47 ( & V_2 -> V_24 ) ;
}
void F_65 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_6 * V_6 ;
for ( V_6 = V_15 -> V_75 ; V_6 ; V_6 = V_6 -> V_76 ) {
if ( V_6 -> V_62 & ( V_63 | V_64 ) )
continue;
F_60 ( V_2 , F_3 ( V_2 , V_6 ) ) ;
}
}
void F_66 ( struct V_1 * V_2 , T_1 V_5 )
{
unsigned long V_60 ;
struct V_9 * V_10 ;
int V_77 = 0 ;
F_48 ( & V_2 -> V_24 ) ;
V_10 = F_34 ( V_2 , V_5 ) ;
F_47 ( & V_2 -> V_24 ) ;
F_54 ( & V_2 -> V_31 , V_60 ) ;
if ( F_51 ( & V_10 -> V_43 ) ) {
if ( F_40 ( V_2 -> V_38 ) ) {
V_10 -> V_50 = V_53 ;
} else if ( V_10 -> V_50 == V_65 ) {
F_67 ( & V_10 -> V_54 , & V_2 -> V_35 ) ;
} else if ( V_10 -> V_50 == V_73 ) {
V_10 -> V_50 = V_52 ;
F_37 ( & V_10 -> V_54 , & V_2 -> V_34 ) ;
}
V_77 = 1 ;
}
F_55 ( & V_2 -> V_31 , V_60 ) ;
if ( V_77 )
V_2 -> F_9 ( V_2 -> V_11 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_57 ;
T_1 V_5 ;
struct V_9 * V_10 ;
V_57 = V_2 -> log -> type -> V_78 ( V_2 -> log , & V_5 ) ;
if ( V_57 <= 0 )
return V_57 ;
F_48 ( & V_2 -> V_24 ) ;
V_10 = F_46 ( V_2 , V_5 ) ;
F_47 ( & V_2 -> V_24 ) ;
F_61 ( & V_2 -> V_31 ) ;
V_10 -> V_50 = V_65 ;
if ( F_28 ( & V_10 -> V_43 ) )
F_63 ( & V_10 -> V_54 ) ;
else
F_69 ( & V_10 -> V_54 , & V_2 -> V_35 ) ;
F_64 ( & V_2 -> V_31 ) ;
return 1 ;
}
void F_70 ( struct V_1 * V_2 )
{
F_62 ( & V_2 -> V_33 ) ;
while ( ! F_71 ( & V_2 -> V_32 ) ) {
F_62 ( & V_2 -> V_33 ) ;
if ( F_68 ( V_2 ) <= 0 ) {
F_72 ( & V_2 -> V_33 ) ;
F_52 ( & V_2 -> V_32 ) ;
break;
}
}
if ( F_51 ( & V_2 -> V_33 ) )
V_2 -> F_10 ( V_2 -> V_11 ) ;
}
struct V_9 * F_73 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = NULL ;
F_61 ( & V_2 -> V_31 ) ;
if ( ! F_26 ( & V_2 -> V_35 ) ) {
V_10 = F_74 ( V_2 -> V_35 . V_67 ,
struct V_9 , V_54 ) ;
F_63 ( & V_10 -> V_54 ) ;
}
F_64 ( & V_2 -> V_31 ) ;
return V_10 ;
}
void F_75 ( struct V_9 * V_10 , int V_58 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_61 ( & V_2 -> V_31 ) ;
if ( V_58 )
F_37 ( & V_10 -> V_54 , & V_10 -> V_2 -> V_36 ) ;
else
F_37 ( & V_10 -> V_54 , & V_10 -> V_2 -> V_37 ) ;
F_64 ( & V_2 -> V_31 ) ;
V_2 -> F_9 ( V_2 -> V_11 ) ;
}
int F_76 ( struct V_1 * V_2 )
{
return F_28 ( & V_2 -> V_33 ) ;
}
int F_77 ( struct V_1 * V_2 )
{
return V_2 -> log -> type -> V_72 ( V_2 -> log ) ;
}
void F_78 ( struct V_1 * V_2 , struct V_6 * V_6 )
{
struct V_9 * V_10 ;
F_48 ( & V_2 -> V_24 ) ;
V_10 = F_46 ( V_2 , F_3 ( V_2 , V_6 ) ) ;
F_79 ( & V_10 -> V_55 , V_6 ) ;
F_47 ( & V_2 -> V_24 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_16 ; V_21 ++ )
F_81 ( & V_2 -> V_32 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_16 ; V_21 ++ )
F_52 ( & V_2 -> V_32 ) ;
V_2 -> F_9 ( V_2 -> V_11 ) ;
}
