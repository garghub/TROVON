static inline int F_1 ( T_1 * V_1 , unsigned long long V_2 )
{
return F_2 ( V_2 , V_1 -> V_3 -> V_4 ) ;
}
static int F_3 ( T_1 * V_1 , unsigned long long V_5 ,
T_2 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_11:
V_10 = F_4 ( V_12 , V_13 ) ;
if ( ! V_10 )
goto V_14;
V_10 -> V_15 = V_6 ;
V_10 -> V_5 = V_5 ;
V_8 = & V_1 -> V_3 -> V_16 [ F_1 ( V_1 , V_5 ) ] ;
F_5 ( & V_1 -> V_17 ) ;
F_6 ( & V_10 -> F_1 , V_8 ) ;
F_7 ( & V_1 -> V_17 ) ;
return 0 ;
V_14:
if ( ! V_18 )
return - V_19 ;
F_8 ( 1 , L_1 , V_20 ) ;
F_9 () ;
goto V_11;
}
static struct V_9 * F_10 ( T_1 * V_1 ,
unsigned long long V_5 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_8 = & V_1 -> V_3 -> V_16 [ F_1 ( V_1 , V_5 ) ] ;
F_5 ( & V_1 -> V_17 ) ;
V_10 = (struct V_9 * ) V_8 -> V_21 ;
while ( & ( V_10 -> F_1 ) != V_8 ) {
if ( V_10 -> V_5 == V_5 ) {
F_7 ( & V_1 -> V_17 ) ;
return V_10 ;
}
V_10 = (struct V_9 * ) V_10 -> F_1 . V_21 ;
}
F_7 ( & V_1 -> V_17 ) ;
return NULL ;
}
void F_11 ( void )
{
if ( V_12 ) {
F_12 ( V_12 ) ;
V_12 = NULL ;
}
if ( V_22 ) {
F_12 ( V_22 ) ;
V_22 = NULL ;
}
}
int T_3 F_13 ( void )
{
F_14 ( ! V_12 ) ;
F_14 ( ! V_22 ) ;
V_12 = F_15 ( V_9 ,
V_23 | V_24 ) ;
if ( ! V_12 )
goto V_25;
V_22 = F_15 ( V_26 ,
V_24 ) ;
if ( ! V_22 )
goto V_27;
return 0 ;
V_27:
F_11 () ;
V_25:
return - V_19 ;
}
static struct V_26 * F_16 ( int V_28 )
{
int V_29 = 0 ;
int V_30 = V_28 ;
struct V_26 * V_31 ;
V_31 = F_4 ( V_22 , V_32 ) ;
if ( ! V_31 )
goto V_33;
while( ( V_30 >>= 1UL ) != 0UL )
V_29 ++ ;
V_31 -> V_28 = V_28 ;
V_31 -> V_4 = V_29 ;
V_31 -> V_16 =
F_17 ( V_28 * sizeof( struct V_7 ) , V_32 ) ;
if ( ! V_31 -> V_16 ) {
F_18 ( V_22 , V_31 ) ;
V_31 = NULL ;
goto V_33;
}
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ )
F_19 ( & V_31 -> V_16 [ V_30 ] ) ;
V_33:
return V_31 ;
}
static void F_20 ( struct V_26 * V_31 )
{
int V_34 ;
struct V_7 * V_8 ;
for ( V_34 = 0 ; V_34 < V_31 -> V_28 ; V_34 ++ ) {
V_8 = & V_31 -> V_16 [ V_34 ] ;
F_14 ( F_21 ( V_8 ) ) ;
}
F_22 ( V_31 -> V_16 ) ;
F_18 ( V_22 , V_31 ) ;
}
int F_23 ( T_1 * V_1 , int V_28 )
{
F_14 ( V_1 -> V_35 [ 0 ] == NULL ) ;
F_14 ( F_24 ( V_28 ) ) ;
V_1 -> V_35 [ 0 ] = F_16 ( V_28 ) ;
if ( ! V_1 -> V_35 [ 0 ] )
goto V_36;
V_1 -> V_35 [ 1 ] = F_16 ( V_28 ) ;
if ( ! V_1 -> V_35 [ 1 ] )
goto V_37;
V_1 -> V_3 = V_1 -> V_35 [ 1 ] ;
F_25 ( & V_1 -> V_17 ) ;
return 0 ;
V_37:
F_20 ( V_1 -> V_35 [ 0 ] ) ;
V_36:
return - V_19 ;
}
void F_26 ( T_1 * V_1 )
{
V_1 -> V_3 = NULL ;
if ( V_1 -> V_35 [ 0 ] )
F_20 ( V_1 -> V_35 [ 0 ] ) ;
if ( V_1 -> V_35 [ 1 ] )
F_20 ( V_1 -> V_35 [ 1 ] ) ;
}
int F_27 ( T_4 * V_38 , unsigned long long V_5 ,
struct V_39 * V_40 )
{
struct V_39 * V_41 = NULL ;
T_1 * V_1 ;
struct V_42 * V_43 ;
int V_44 ;
F_28 () ;
if ( V_40 )
F_29 ( V_40 , L_2 ) ;
V_1 = V_38 -> V_45 -> V_46 ;
if ( ! F_30 ( V_1 , 0 , 0 , V_47 ) ) {
F_14 ( ! L_3 ) ;
return - V_48 ;
}
V_43 = V_1 -> V_49 ;
V_41 = V_40 ;
if ( ! V_41 ) {
V_41 = F_31 ( V_43 , V_5 , V_1 -> V_50 ) ;
if ( V_41 )
F_29 ( V_41 , L_4 ) ;
}
#ifdef F_32
else {
struct V_39 * V_51 ;
V_51 = F_31 ( V_43 , V_5 , V_1 -> V_50 ) ;
if ( V_51 ) {
if ( V_51 != V_41 && F_33 ( V_51 ) )
F_34 ( V_51 , F_35 ( V_51 ) ) ;
F_36 ( V_51 ) ;
}
}
#endif
if ( V_41 ) {
if ( ! F_37 ( V_41 , ! F_35 ( V_41 ) ,
L_5 ) ) {
if ( ! V_40 )
F_38 ( V_41 ) ;
return - V_52 ;
}
F_39 ( V_41 ) ;
F_40 ( V_41 ) ;
if ( V_40 ) {
F_29 ( V_40 , L_6 ) ;
F_41 ( V_38 , V_40 ) ;
} else {
F_29 ( V_41 , L_7 ) ;
F_42 ( V_41 ) ;
}
}
F_8 ( 2 , L_8 , V_5 , V_40 ) ;
V_44 = F_3 ( V_1 , V_5 ,
V_38 -> V_45 -> V_53 ) ;
F_29 ( V_40 , L_9 ) ;
return V_44 ;
}
int F_43 ( T_4 * V_38 , struct V_54 * V_55 )
{
struct V_9 * V_10 ;
T_1 * V_1 = V_38 -> V_45 -> V_46 ;
int V_56 ;
int V_57 = 0 ;
struct V_39 * V_41 = F_44 ( V_55 ) ;
F_8 ( 4 , L_10 , V_55 ) ;
if ( F_45 ( V_41 ) ) {
V_56 = F_46 ( V_41 ) ;
} else {
V_56 = 1 ;
F_47 ( V_41 ) ;
}
if ( V_56 ) {
V_10 = F_10 ( V_1 , V_41 -> V_58 ) ;
if ( V_10 ) {
F_8 ( 4 , L_11
L_12 , ( unsigned long long ) V_41 -> V_58 ) ;
F_5 ( & V_1 -> V_17 ) ;
F_48 ( & V_10 -> F_1 ) ;
F_7 ( & V_1 -> V_17 ) ;
F_18 ( V_12 , V_10 ) ;
V_57 = 1 ;
}
}
#ifdef F_32
V_10 = F_10 ( V_1 , V_41 -> V_58 ) ;
F_49 ( V_55 , V_10 == NULL ) ;
#endif
if ( V_56 ) {
struct V_39 * V_51 ;
V_51 = F_31 ( V_41 -> V_59 , V_41 -> V_58 , V_41 -> V_60 ) ;
if ( V_51 ) {
if ( V_51 != V_41 )
F_47 ( V_51 ) ;
F_42 ( V_51 ) ;
}
}
return V_57 ;
}
void F_50 ( T_1 * V_1 )
{
struct V_26 * V_61 = V_1 -> V_3 ;
int V_34 = 0 ;
for ( V_34 = 0 ; V_34 < V_61 -> V_28 ; V_34 ++ ) {
struct V_7 * V_8 ;
struct V_7 * V_62 ;
V_8 = & V_61 -> V_16 [ V_34 ] ;
F_51 (list_entry, hash_list) {
struct V_9 * V_10 ;
struct V_39 * V_41 ;
V_10 = (struct V_9 * ) V_62 ;
V_41 = F_31 ( V_1 -> V_49 ,
V_10 -> V_5 ,
V_1 -> V_50 ) ;
if ( V_41 ) {
F_47 ( V_41 ) ;
F_42 ( V_41 ) ;
}
}
}
}
void F_52 ( T_1 * V_1 )
{
int V_34 ;
if ( V_1 -> V_3 == V_1 -> V_35 [ 0 ] )
V_1 -> V_3 = V_1 -> V_35 [ 1 ] ;
else
V_1 -> V_3 = V_1 -> V_35 [ 0 ] ;
for ( V_34 = 0 ; V_34 < V_1 -> V_3 -> V_28 ; V_34 ++ )
F_19 ( & V_1 -> V_3 -> V_16 [ V_34 ] ) ;
}
void F_53 ( T_1 * V_1 ,
T_5 * V_63 ,
struct V_7 * V_64 ,
int V_65 )
{
struct V_39 * V_66 ;
struct V_9 * V_10 ;
struct V_26 * V_61 ;
struct V_7 * V_8 ;
int V_34 , V_67 , V_68 ;
V_66 = NULL ;
V_67 = 0 ;
V_68 = 0 ;
V_61 = V_1 -> V_3 == V_1 -> V_35 [ 0 ] ?
V_1 -> V_35 [ 1 ] : V_1 -> V_35 [ 0 ] ;
for ( V_34 = 0 ; V_34 < V_61 -> V_28 ; V_34 ++ ) {
V_8 = & V_61 -> V_16 [ V_34 ] ;
while ( ! F_21 ( V_8 ) ) {
V_10 = (struct V_9 * )
V_8 -> V_21 ;
F_54 ( V_1 , V_63 , V_64 ,
& V_66 , & V_67 ,
V_10 , V_65 ) ;
V_68 ++ ;
F_48 ( & V_10 -> F_1 ) ;
F_18 ( V_12 , V_10 ) ;
}
}
if ( V_66 )
F_55 ( V_1 , V_66 , V_67 , V_65 ) ;
F_8 ( 1 , L_13 , V_68 ) ;
}
static void F_54 ( T_1 * V_1 ,
T_5 * V_63 ,
struct V_7 * V_64 ,
struct V_39 * * V_69 ,
int * V_70 ,
struct V_9 * V_10 ,
int V_65 )
{
int V_71 = 0 ;
struct V_39 * V_66 ;
int V_67 ;
T_6 * V_72 ;
if ( F_56 ( V_1 ) )
return;
V_66 = * V_69 ;
V_67 = * V_70 ;
if ( F_57 ( V_1 ) )
V_71 = sizeof( struct V_73 ) ;
if ( V_66 ) {
if ( V_67 >= V_1 -> V_50 - V_71 ) {
F_55 ( V_1 , V_66 , V_67 , V_65 ) ;
V_66 = NULL ;
}
}
if ( ! V_66 ) {
V_66 = F_58 ( V_1 ) ;
if ( ! V_66 )
return;
V_72 = ( T_6 * ) V_66 -> V_74 ;
V_72 -> V_75 = F_59 ( V_76 ) ;
V_72 -> V_77 = F_59 ( V_78 ) ;
V_72 -> V_79 = F_59 ( V_63 -> V_53 ) ;
F_29 ( V_66 , L_14 ) ;
F_60 ( V_64 , V_66 ) ;
V_67 = sizeof( V_80 ) ;
* V_69 = V_66 ;
}
if ( F_61 ( V_1 , V_81 ) ) {
* ( ( V_82 * ) ( & V_66 -> V_74 [ V_67 ] ) ) =
F_62 ( V_10 -> V_5 ) ;
V_67 += 8 ;
} else {
* ( ( V_83 * ) ( & V_66 -> V_74 [ V_67 ] ) ) =
F_59 ( V_10 -> V_5 ) ;
V_67 += 4 ;
}
* V_70 = V_67 ;
}
static void F_63 ( T_1 * V_84 , struct V_39 * V_41 )
{
struct V_73 * V_85 ;
T_7 V_86 ;
if ( ! F_57 ( V_84 ) )
return;
V_85 = (struct V_73 * ) ( V_41 -> V_74 + V_84 -> V_50 -
sizeof( struct V_73 ) ) ;
V_85 -> V_87 = 0 ;
V_86 = F_64 ( V_84 , V_84 -> V_88 , V_41 -> V_74 , V_84 -> V_50 ) ;
V_85 -> V_87 = F_59 ( V_86 ) ;
}
static void F_55 ( T_1 * V_1 ,
struct V_39 * V_66 ,
int V_67 , int V_65 )
{
V_80 * V_72 ;
if ( F_56 ( V_1 ) ) {
F_36 ( V_66 ) ;
return;
}
V_72 = ( V_80 * ) V_66 -> V_74 ;
V_72 -> V_89 = F_59 ( V_67 ) ;
F_63 ( V_1 , V_66 ) ;
F_65 ( V_66 ) ;
F_29 ( V_66 , L_15 ) ;
F_66 ( V_66 ) ;
F_67 ( V_66 , V_65 ) ;
}
int F_68 ( T_1 * V_1 ,
unsigned long long V_5 ,
T_2 V_15 )
{
struct V_9 * V_10 ;
V_10 = F_10 ( V_1 , V_5 ) ;
if ( V_10 ) {
if ( F_69 ( V_15 , V_10 -> V_15 ) )
V_10 -> V_15 = V_15 ;
return 0 ;
}
return F_3 ( V_1 , V_5 , V_15 ) ;
}
int F_70 ( T_1 * V_1 ,
unsigned long long V_5 ,
T_2 V_15 )
{
struct V_9 * V_10 ;
V_10 = F_10 ( V_1 , V_5 ) ;
if ( ! V_10 )
return 0 ;
if ( F_69 ( V_15 , V_10 -> V_15 ) )
return 0 ;
return 1 ;
}
void F_71 ( T_1 * V_1 )
{
int V_34 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_26 * V_61 ;
V_61 = V_1 -> V_3 ;
for ( V_34 = 0 ; V_34 < V_61 -> V_28 ; V_34 ++ ) {
V_8 = & V_61 -> V_16 [ V_34 ] ;
while ( ! F_21 ( V_8 ) ) {
V_10 = (struct V_9 * ) V_8 -> V_21 ;
F_48 ( & V_10 -> F_1 ) ;
F_18 ( V_12 , V_10 ) ;
}
}
}
