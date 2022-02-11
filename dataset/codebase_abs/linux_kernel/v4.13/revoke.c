static inline int F_1 ( T_1 * V_1 , unsigned long long V_2 )
{
return F_2 ( V_2 , V_1 -> V_3 -> V_4 ) ;
}
static int F_3 ( T_1 * V_1 , unsigned long long V_5 ,
T_2 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
T_3 V_11 = V_12 ;
if ( V_13 )
V_11 |= V_14 ;
V_10 = F_4 ( V_15 , V_11 ) ;
if ( ! V_10 )
return - V_16 ;
V_10 -> V_17 = V_6 ;
V_10 -> V_5 = V_5 ;
V_8 = & V_1 -> V_3 -> V_18 [ F_1 ( V_1 , V_5 ) ] ;
F_5 ( & V_1 -> V_19 ) ;
F_6 ( & V_10 -> F_1 , V_8 ) ;
F_7 ( & V_1 -> V_19 ) ;
return 0 ;
}
static struct V_9 * F_8 ( T_1 * V_1 ,
unsigned long long V_5 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_8 = & V_1 -> V_3 -> V_18 [ F_1 ( V_1 , V_5 ) ] ;
F_5 ( & V_1 -> V_19 ) ;
V_10 = (struct V_9 * ) V_8 -> V_20 ;
while ( & ( V_10 -> F_1 ) != V_8 ) {
if ( V_10 -> V_5 == V_5 ) {
F_7 ( & V_1 -> V_19 ) ;
return V_10 ;
}
V_10 = (struct V_9 * ) V_10 -> F_1 . V_20 ;
}
F_7 ( & V_1 -> V_19 ) ;
return NULL ;
}
void F_9 ( void )
{
if ( V_15 ) {
F_10 ( V_15 ) ;
V_15 = NULL ;
}
if ( V_21 ) {
F_10 ( V_21 ) ;
V_21 = NULL ;
}
}
int T_4 F_11 ( void )
{
F_12 ( ! V_15 ) ;
F_12 ( ! V_21 ) ;
V_15 = F_13 ( V_9 ,
V_22 | V_23 ) ;
if ( ! V_15 )
goto V_24;
V_21 = F_13 ( V_25 ,
V_23 ) ;
if ( ! V_21 )
goto V_26;
return 0 ;
V_26:
F_9 () ;
V_24:
return - V_16 ;
}
static struct V_25 * F_14 ( int V_27 )
{
int V_28 = 0 ;
int V_29 = V_27 ;
struct V_25 * V_30 ;
V_30 = F_4 ( V_21 , V_31 ) ;
if ( ! V_30 )
goto V_32;
while( ( V_29 >>= 1UL ) != 0UL )
V_28 ++ ;
V_30 -> V_27 = V_27 ;
V_30 -> V_4 = V_28 ;
V_30 -> V_18 =
F_15 ( V_27 * sizeof( struct V_7 ) , V_31 ) ;
if ( ! V_30 -> V_18 ) {
F_16 ( V_21 , V_30 ) ;
V_30 = NULL ;
goto V_32;
}
for ( V_29 = 0 ; V_29 < V_27 ; V_29 ++ )
F_17 ( & V_30 -> V_18 [ V_29 ] ) ;
V_32:
return V_30 ;
}
static void F_18 ( struct V_25 * V_30 )
{
int V_33 ;
struct V_7 * V_8 ;
for ( V_33 = 0 ; V_33 < V_30 -> V_27 ; V_33 ++ ) {
V_8 = & V_30 -> V_18 [ V_33 ] ;
F_12 ( F_19 ( V_8 ) ) ;
}
F_20 ( V_30 -> V_18 ) ;
F_16 ( V_21 , V_30 ) ;
}
int F_21 ( T_1 * V_1 , int V_27 )
{
F_12 ( V_1 -> V_34 [ 0 ] == NULL ) ;
F_12 ( F_22 ( V_27 ) ) ;
V_1 -> V_34 [ 0 ] = F_14 ( V_27 ) ;
if ( ! V_1 -> V_34 [ 0 ] )
goto V_35;
V_1 -> V_34 [ 1 ] = F_14 ( V_27 ) ;
if ( ! V_1 -> V_34 [ 1 ] )
goto V_36;
V_1 -> V_3 = V_1 -> V_34 [ 1 ] ;
F_23 ( & V_1 -> V_19 ) ;
return 0 ;
V_36:
F_18 ( V_1 -> V_34 [ 0 ] ) ;
V_1 -> V_34 [ 0 ] = NULL ;
V_35:
return - V_16 ;
}
void F_24 ( T_1 * V_1 )
{
V_1 -> V_3 = NULL ;
if ( V_1 -> V_34 [ 0 ] )
F_18 ( V_1 -> V_34 [ 0 ] ) ;
if ( V_1 -> V_34 [ 1 ] )
F_18 ( V_1 -> V_34 [ 1 ] ) ;
}
int F_25 ( T_5 * V_37 , unsigned long long V_5 ,
struct V_38 * V_39 )
{
struct V_38 * V_40 = NULL ;
T_1 * V_1 ;
struct V_41 * V_42 ;
int V_43 ;
F_26 () ;
if ( V_39 )
F_27 ( V_39 , L_1 ) ;
V_1 = V_37 -> V_44 -> V_45 ;
if ( ! F_28 ( V_1 , 0 , 0 , V_46 ) ) {
F_12 ( ! L_2 ) ;
return - V_47 ;
}
V_42 = V_1 -> V_48 ;
V_40 = V_39 ;
if ( ! V_40 ) {
V_40 = F_29 ( V_42 , V_5 , V_1 -> V_49 ) ;
if ( V_40 )
F_27 ( V_40 , L_3 ) ;
}
#ifdef F_30
else {
struct V_38 * V_50 ;
V_50 = F_29 ( V_42 , V_5 , V_1 -> V_49 ) ;
if ( V_50 ) {
if ( V_50 != V_40 && F_31 ( V_50 ) )
F_32 ( V_50 , F_33 ( V_50 ) ) ;
F_34 ( V_50 ) ;
}
}
#endif
if ( V_40 ) {
if ( ! F_35 ( V_40 , ! F_33 ( V_40 ) ,
L_4 ) ) {
if ( ! V_39 )
F_36 ( V_40 ) ;
return - V_51 ;
}
F_37 ( V_40 ) ;
F_38 ( V_40 ) ;
if ( V_39 ) {
F_27 ( V_39 , L_5 ) ;
F_39 ( V_37 , V_39 ) ;
} else {
F_27 ( V_40 , L_6 ) ;
F_40 ( V_40 ) ;
}
}
F_41 ( 2 , L_7 , V_5 , V_39 ) ;
V_43 = F_3 ( V_1 , V_5 ,
V_37 -> V_44 -> V_52 ) ;
F_27 ( V_39 , L_8 ) ;
return V_43 ;
}
int F_42 ( T_5 * V_37 , struct V_53 * V_54 )
{
struct V_9 * V_10 ;
T_1 * V_1 = V_37 -> V_44 -> V_45 ;
int V_55 ;
int V_56 = 0 ;
struct V_38 * V_40 = F_43 ( V_54 ) ;
F_41 ( 4 , L_9 , V_54 ) ;
if ( F_44 ( V_40 ) ) {
V_55 = F_45 ( V_40 ) ;
} else {
V_55 = 1 ;
F_46 ( V_40 ) ;
}
if ( V_55 ) {
V_10 = F_8 ( V_1 , V_40 -> V_57 ) ;
if ( V_10 ) {
F_41 ( 4 , L_10
L_11 , ( unsigned long long ) V_40 -> V_57 ) ;
F_5 ( & V_1 -> V_19 ) ;
F_47 ( & V_10 -> F_1 ) ;
F_7 ( & V_1 -> V_19 ) ;
F_16 ( V_15 , V_10 ) ;
V_56 = 1 ;
}
}
#ifdef F_30
V_10 = F_8 ( V_1 , V_40 -> V_57 ) ;
F_48 ( V_54 , V_10 == NULL ) ;
#endif
if ( V_55 ) {
struct V_38 * V_50 ;
V_50 = F_29 ( V_40 -> V_58 , V_40 -> V_57 , V_40 -> V_59 ) ;
if ( V_50 ) {
if ( V_50 != V_40 )
F_46 ( V_50 ) ;
F_40 ( V_50 ) ;
}
}
return V_56 ;
}
void F_49 ( T_1 * V_1 )
{
struct V_25 * V_60 = V_1 -> V_3 ;
int V_33 = 0 ;
for ( V_33 = 0 ; V_33 < V_60 -> V_27 ; V_33 ++ ) {
struct V_7 * V_8 ;
struct V_7 * V_61 ;
V_8 = & V_60 -> V_18 [ V_33 ] ;
F_50 (list_entry, hash_list) {
struct V_9 * V_10 ;
struct V_38 * V_40 ;
V_10 = (struct V_9 * ) V_61 ;
V_40 = F_29 ( V_1 -> V_48 ,
V_10 -> V_5 ,
V_1 -> V_49 ) ;
if ( V_40 ) {
F_46 ( V_40 ) ;
F_40 ( V_40 ) ;
}
}
}
}
void F_51 ( T_1 * V_1 )
{
int V_33 ;
if ( V_1 -> V_3 == V_1 -> V_34 [ 0 ] )
V_1 -> V_3 = V_1 -> V_34 [ 1 ] ;
else
V_1 -> V_3 = V_1 -> V_34 [ 0 ] ;
for ( V_33 = 0 ; V_33 < V_1 -> V_3 -> V_27 ; V_33 ++ )
F_17 ( & V_1 -> V_3 -> V_18 [ V_33 ] ) ;
}
void F_52 ( T_6 * V_62 ,
struct V_7 * V_63 )
{
T_1 * V_1 = V_62 -> V_45 ;
struct V_38 * V_64 ;
struct V_9 * V_10 ;
struct V_25 * V_60 ;
struct V_7 * V_8 ;
int V_33 , V_65 , V_66 ;
V_64 = NULL ;
V_65 = 0 ;
V_66 = 0 ;
V_60 = V_1 -> V_3 == V_1 -> V_34 [ 0 ] ?
V_1 -> V_34 [ 1 ] : V_1 -> V_34 [ 0 ] ;
for ( V_33 = 0 ; V_33 < V_60 -> V_27 ; V_33 ++ ) {
V_8 = & V_60 -> V_18 [ V_33 ] ;
while ( ! F_19 ( V_8 ) ) {
V_10 = (struct V_9 * )
V_8 -> V_20 ;
F_53 ( V_62 , V_63 ,
& V_64 , & V_65 , V_10 ) ;
V_66 ++ ;
F_47 ( & V_10 -> F_1 ) ;
F_16 ( V_15 , V_10 ) ;
}
}
if ( V_64 )
F_54 ( V_1 , V_64 , V_65 ) ;
F_41 ( 1 , L_12 , V_66 ) ;
}
static void F_53 ( T_6 * V_62 ,
struct V_7 * V_63 ,
struct V_38 * * V_67 ,
int * V_68 ,
struct V_9 * V_10 )
{
T_1 * V_1 = V_62 -> V_45 ;
int V_69 = 0 ;
struct V_38 * V_64 ;
int V_70 , V_65 ;
if ( F_55 ( V_1 ) )
return;
V_64 = * V_67 ;
V_65 = * V_68 ;
if ( F_56 ( V_1 ) )
V_69 = sizeof( struct V_71 ) ;
if ( F_57 ( V_1 ) )
V_70 = 8 ;
else
V_70 = 4 ;
if ( V_64 ) {
if ( V_65 + V_70 > V_1 -> V_49 - V_69 ) {
F_54 ( V_1 , V_64 , V_65 ) ;
V_64 = NULL ;
}
}
if ( ! V_64 ) {
V_64 = F_58 ( V_62 ,
V_72 ) ;
if ( ! V_64 )
return;
F_27 ( V_64 , L_13 ) ;
F_59 ( V_63 , V_64 ) ;
V_65 = sizeof( V_73 ) ;
* V_67 = V_64 ;
}
if ( F_57 ( V_1 ) )
* ( ( V_74 * ) ( & V_64 -> V_75 [ V_65 ] ) ) =
F_60 ( V_10 -> V_5 ) ;
else
* ( ( V_76 * ) ( & V_64 -> V_75 [ V_65 ] ) ) =
F_61 ( V_10 -> V_5 ) ;
V_65 += V_70 ;
* V_68 = V_65 ;
}
static void F_54 ( T_1 * V_1 ,
struct V_38 * V_64 ,
int V_65 )
{
V_73 * V_77 ;
if ( F_55 ( V_1 ) ) {
F_34 ( V_64 ) ;
return;
}
V_77 = ( V_73 * ) V_64 -> V_75 ;
V_77 -> V_78 = F_61 ( V_65 ) ;
F_62 ( V_1 , V_64 ) ;
F_63 ( V_64 ) ;
F_27 ( V_64 , L_14 ) ;
F_64 ( V_64 ) ;
F_65 ( V_64 , V_79 ) ;
}
int F_66 ( T_1 * V_1 ,
unsigned long long V_5 ,
T_2 V_17 )
{
struct V_9 * V_10 ;
V_10 = F_8 ( V_1 , V_5 ) ;
if ( V_10 ) {
if ( F_67 ( V_17 , V_10 -> V_17 ) )
V_10 -> V_17 = V_17 ;
return 0 ;
}
return F_3 ( V_1 , V_5 , V_17 ) ;
}
int F_68 ( T_1 * V_1 ,
unsigned long long V_5 ,
T_2 V_17 )
{
struct V_9 * V_10 ;
V_10 = F_8 ( V_1 , V_5 ) ;
if ( ! V_10 )
return 0 ;
if ( F_67 ( V_17 , V_10 -> V_17 ) )
return 0 ;
return 1 ;
}
void F_69 ( T_1 * V_1 )
{
int V_33 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_25 * V_60 ;
V_60 = V_1 -> V_3 ;
for ( V_33 = 0 ; V_33 < V_60 -> V_27 ; V_33 ++ ) {
V_8 = & V_60 -> V_18 [ V_33 ] ;
while ( ! F_19 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 -> V_20 ;
F_47 ( & V_10 -> F_1 ) ;
F_16 ( V_15 , V_10 ) ;
}
}
}
