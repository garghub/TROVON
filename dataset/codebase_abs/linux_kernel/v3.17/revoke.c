static inline int F_1 ( T_1 * V_1 , unsigned long long V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
int V_6 = V_4 -> V_6 ;
int F_1 = ( int ) V_2 ^ ( int ) ( ( V_2 >> 31 ) >> 1 ) ;
return ( ( F_1 << ( V_6 - 6 ) ) ^
( F_1 >> 13 ) ^
( F_1 << ( V_6 - 12 ) ) ) & ( V_4 -> V_7 - 1 ) ;
}
static int F_2 ( T_1 * V_1 , unsigned long long V_8 ,
T_2 V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_14:
V_13 = F_3 ( V_15 , V_16 ) ;
if ( ! V_13 )
goto V_17;
V_13 -> V_18 = V_9 ;
V_13 -> V_8 = V_8 ;
V_11 = & V_1 -> V_5 -> V_19 [ F_1 ( V_1 , V_8 ) ] ;
F_4 ( & V_1 -> V_20 ) ;
F_5 ( & V_13 -> F_1 , V_11 ) ;
F_6 ( & V_1 -> V_20 ) ;
return 0 ;
V_17:
if ( ! V_21 )
return - V_22 ;
F_7 ( 1 , L_1 , V_23 ) ;
F_8 () ;
goto V_14;
}
static struct V_12 * F_9 ( T_1 * V_1 ,
unsigned long long V_8 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_11 = & V_1 -> V_5 -> V_19 [ F_1 ( V_1 , V_8 ) ] ;
F_4 ( & V_1 -> V_20 ) ;
V_13 = (struct V_12 * ) V_11 -> V_24 ;
while ( & ( V_13 -> F_1 ) != V_11 ) {
if ( V_13 -> V_8 == V_8 ) {
F_6 ( & V_1 -> V_20 ) ;
return V_13 ;
}
V_13 = (struct V_12 * ) V_13 -> F_1 . V_24 ;
}
F_6 ( & V_1 -> V_20 ) ;
return NULL ;
}
void F_10 ( void )
{
if ( V_15 ) {
F_11 ( V_15 ) ;
V_15 = NULL ;
}
if ( V_25 ) {
F_11 ( V_25 ) ;
V_25 = NULL ;
}
}
int T_3 F_12 ( void )
{
F_13 ( ! V_15 ) ;
F_13 ( ! V_25 ) ;
V_15 = F_14 ( V_12 ,
V_26 | V_27 ) ;
if ( ! V_15 )
goto V_28;
V_25 = F_14 ( V_3 ,
V_27 ) ;
if ( ! V_25 )
goto V_29;
return 0 ;
V_29:
F_10 () ;
V_28:
return - V_22 ;
}
static struct V_3 * F_15 ( int V_7 )
{
int V_30 = 0 ;
int V_31 = V_7 ;
struct V_3 * V_4 ;
V_4 = F_3 ( V_25 , V_32 ) ;
if ( ! V_4 )
goto V_33;
while( ( V_31 >>= 1UL ) != 0UL )
V_30 ++ ;
V_4 -> V_7 = V_7 ;
V_4 -> V_6 = V_30 ;
V_4 -> V_19 =
F_16 ( V_7 * sizeof( struct V_10 ) , V_32 ) ;
if ( ! V_4 -> V_19 ) {
F_17 ( V_25 , V_4 ) ;
V_4 = NULL ;
goto V_33;
}
for ( V_31 = 0 ; V_31 < V_7 ; V_31 ++ )
F_18 ( & V_4 -> V_19 [ V_31 ] ) ;
V_33:
return V_4 ;
}
static void F_19 ( struct V_3 * V_4 )
{
int V_34 ;
struct V_10 * V_11 ;
for ( V_34 = 0 ; V_34 < V_4 -> V_7 ; V_34 ++ ) {
V_11 = & V_4 -> V_19 [ V_34 ] ;
F_13 ( F_20 ( V_11 ) ) ;
}
F_21 ( V_4 -> V_19 ) ;
F_17 ( V_25 , V_4 ) ;
}
int F_22 ( T_1 * V_1 , int V_7 )
{
F_13 ( V_1 -> V_35 [ 0 ] == NULL ) ;
F_13 ( F_23 ( V_7 ) ) ;
V_1 -> V_35 [ 0 ] = F_15 ( V_7 ) ;
if ( ! V_1 -> V_35 [ 0 ] )
goto V_36;
V_1 -> V_35 [ 1 ] = F_15 ( V_7 ) ;
if ( ! V_1 -> V_35 [ 1 ] )
goto V_37;
V_1 -> V_5 = V_1 -> V_35 [ 1 ] ;
F_24 ( & V_1 -> V_20 ) ;
return 0 ;
V_37:
F_19 ( V_1 -> V_35 [ 0 ] ) ;
V_36:
return - V_22 ;
}
void F_25 ( T_1 * V_1 )
{
V_1 -> V_5 = NULL ;
if ( V_1 -> V_35 [ 0 ] )
F_19 ( V_1 -> V_35 [ 0 ] ) ;
if ( V_1 -> V_35 [ 1 ] )
F_19 ( V_1 -> V_35 [ 1 ] ) ;
}
int F_26 ( T_4 * V_38 , unsigned long long V_8 ,
struct V_39 * V_40 )
{
struct V_39 * V_41 = NULL ;
T_1 * V_1 ;
struct V_42 * V_43 ;
int V_44 ;
F_27 () ;
if ( V_40 )
F_28 ( V_40 , L_2 ) ;
V_1 = V_38 -> V_45 -> V_46 ;
if ( ! F_29 ( V_1 , 0 , 0 , V_47 ) ) {
F_13 ( ! L_3 ) ;
return - V_48 ;
}
V_43 = V_1 -> V_49 ;
V_41 = V_40 ;
if ( ! V_41 ) {
V_41 = F_30 ( V_43 , V_8 , V_1 -> V_50 ) ;
if ( V_41 )
F_28 ( V_41 , L_4 ) ;
}
#ifdef F_31
else {
struct V_39 * V_51 ;
V_51 = F_30 ( V_43 , V_8 , V_1 -> V_50 ) ;
if ( V_51 ) {
if ( V_51 != V_41 && F_32 ( V_51 ) )
F_33 ( V_51 , F_34 ( V_51 ) ) ;
F_35 ( V_51 ) ;
}
}
#endif
if ( V_41 ) {
if ( ! F_36 ( V_41 , ! F_34 ( V_41 ) ,
L_5 ) ) {
if ( ! V_40 )
F_37 ( V_41 ) ;
return - V_52 ;
}
F_38 ( V_41 ) ;
F_39 ( V_41 ) ;
if ( V_40 ) {
F_28 ( V_40 , L_6 ) ;
F_40 ( V_38 , V_40 ) ;
} else {
F_28 ( V_41 , L_7 ) ;
F_41 ( V_41 ) ;
}
}
F_7 ( 2 , L_8 , V_8 , V_40 ) ;
V_44 = F_2 ( V_1 , V_8 ,
V_38 -> V_45 -> V_53 ) ;
F_28 ( V_40 , L_9 ) ;
return V_44 ;
}
int F_42 ( T_4 * V_38 , struct V_54 * V_55 )
{
struct V_12 * V_13 ;
T_1 * V_1 = V_38 -> V_45 -> V_46 ;
int V_56 ;
int V_57 = 0 ;
struct V_39 * V_41 = F_43 ( V_55 ) ;
F_7 ( 4 , L_10 , V_55 ) ;
if ( F_44 ( V_41 ) ) {
V_56 = F_45 ( V_41 ) ;
} else {
V_56 = 1 ;
F_46 ( V_41 ) ;
}
if ( V_56 ) {
V_13 = F_9 ( V_1 , V_41 -> V_58 ) ;
if ( V_13 ) {
F_7 ( 4 , L_11
L_12 , ( unsigned long long ) V_41 -> V_58 ) ;
F_4 ( & V_1 -> V_20 ) ;
F_47 ( & V_13 -> F_1 ) ;
F_6 ( & V_1 -> V_20 ) ;
F_17 ( V_15 , V_13 ) ;
V_57 = 1 ;
}
}
#ifdef F_31
V_13 = F_9 ( V_1 , V_41 -> V_58 ) ;
F_48 ( V_55 , V_13 == NULL ) ;
#endif
if ( V_56 ) {
struct V_39 * V_51 ;
V_51 = F_30 ( V_41 -> V_59 , V_41 -> V_58 , V_41 -> V_60 ) ;
if ( V_51 ) {
if ( V_51 != V_41 )
F_46 ( V_51 ) ;
F_41 ( V_51 ) ;
}
}
return V_57 ;
}
void F_49 ( T_1 * V_1 )
{
struct V_3 * V_61 = V_1 -> V_5 ;
int V_34 = 0 ;
for ( V_34 = 0 ; V_34 < V_61 -> V_7 ; V_34 ++ ) {
struct V_10 * V_11 ;
struct V_10 * V_62 ;
V_11 = & V_61 -> V_19 [ V_34 ] ;
F_50 (list_entry, hash_list) {
struct V_12 * V_13 ;
struct V_39 * V_41 ;
V_13 = (struct V_12 * ) V_62 ;
V_41 = F_30 ( V_1 -> V_49 ,
V_13 -> V_8 ,
V_1 -> V_50 ) ;
if ( V_41 ) {
F_46 ( V_41 ) ;
F_41 ( V_41 ) ;
}
}
}
}
void F_51 ( T_1 * V_1 )
{
int V_34 ;
if ( V_1 -> V_5 == V_1 -> V_35 [ 0 ] )
V_1 -> V_5 = V_1 -> V_35 [ 1 ] ;
else
V_1 -> V_5 = V_1 -> V_35 [ 0 ] ;
for ( V_34 = 0 ; V_34 < V_1 -> V_5 -> V_7 ; V_34 ++ )
F_18 ( & V_1 -> V_5 -> V_19 [ V_34 ] ) ;
}
void F_52 ( T_1 * V_1 ,
T_5 * V_63 ,
struct V_10 * V_64 ,
int V_65 )
{
struct V_39 * V_66 ;
struct V_12 * V_13 ;
struct V_3 * V_61 ;
struct V_10 * V_11 ;
int V_34 , V_67 , V_68 ;
V_66 = NULL ;
V_67 = 0 ;
V_68 = 0 ;
V_61 = V_1 -> V_5 == V_1 -> V_35 [ 0 ] ?
V_1 -> V_35 [ 1 ] : V_1 -> V_35 [ 0 ] ;
for ( V_34 = 0 ; V_34 < V_61 -> V_7 ; V_34 ++ ) {
V_11 = & V_61 -> V_19 [ V_34 ] ;
while ( ! F_20 ( V_11 ) ) {
V_13 = (struct V_12 * )
V_11 -> V_24 ;
F_53 ( V_1 , V_63 , V_64 ,
& V_66 , & V_67 ,
V_13 , V_65 ) ;
V_68 ++ ;
F_47 ( & V_13 -> F_1 ) ;
F_17 ( V_15 , V_13 ) ;
}
}
if ( V_66 )
F_54 ( V_1 , V_66 , V_67 , V_65 ) ;
F_7 ( 1 , L_13 , V_68 ) ;
}
static void F_53 ( T_1 * V_1 ,
T_5 * V_63 ,
struct V_10 * V_64 ,
struct V_39 * * V_69 ,
int * V_70 ,
struct V_12 * V_13 ,
int V_65 )
{
int V_71 = 0 ;
struct V_39 * V_66 ;
int V_67 ;
T_6 * V_72 ;
if ( F_55 ( V_1 ) )
return;
V_66 = * V_69 ;
V_67 = * V_70 ;
if ( F_56 ( V_1 ) )
V_71 = sizeof( struct V_73 ) ;
if ( V_66 ) {
if ( V_67 >= V_1 -> V_50 - V_71 ) {
F_54 ( V_1 , V_66 , V_67 , V_65 ) ;
V_66 = NULL ;
}
}
if ( ! V_66 ) {
V_66 = F_57 ( V_1 ) ;
if ( ! V_66 )
return;
V_72 = ( T_6 * ) V_66 -> V_74 ;
V_72 -> V_75 = F_58 ( V_76 ) ;
V_72 -> V_77 = F_58 ( V_78 ) ;
V_72 -> V_79 = F_58 ( V_63 -> V_53 ) ;
F_28 ( V_66 , L_14 ) ;
F_59 ( V_64 , V_66 ) ;
V_67 = sizeof( V_80 ) ;
* V_69 = V_66 ;
}
if ( F_60 ( V_1 , V_81 ) ) {
* ( ( V_82 * ) ( & V_66 -> V_74 [ V_67 ] ) ) =
F_61 ( V_13 -> V_8 ) ;
V_67 += 8 ;
} else {
* ( ( V_83 * ) ( & V_66 -> V_74 [ V_67 ] ) ) =
F_58 ( V_13 -> V_8 ) ;
V_67 += 4 ;
}
* V_70 = V_67 ;
}
static void F_62 ( T_1 * V_84 , struct V_39 * V_41 )
{
struct V_73 * V_85 ;
T_7 V_86 ;
if ( ! F_56 ( V_84 ) )
return;
V_85 = (struct V_73 * ) ( V_41 -> V_74 + V_84 -> V_50 -
sizeof( struct V_73 ) ) ;
V_85 -> V_87 = 0 ;
V_86 = F_63 ( V_84 , V_84 -> V_88 , V_41 -> V_74 , V_84 -> V_50 ) ;
V_85 -> V_87 = F_58 ( V_86 ) ;
}
static void F_54 ( T_1 * V_1 ,
struct V_39 * V_66 ,
int V_67 , int V_65 )
{
V_80 * V_72 ;
if ( F_55 ( V_1 ) ) {
F_35 ( V_66 ) ;
return;
}
V_72 = ( V_80 * ) V_66 -> V_74 ;
V_72 -> V_89 = F_58 ( V_67 ) ;
F_62 ( V_1 , V_66 ) ;
F_64 ( V_66 ) ;
F_28 ( V_66 , L_15 ) ;
F_65 ( V_66 ) ;
F_66 ( V_66 , V_65 ) ;
}
int F_67 ( T_1 * V_1 ,
unsigned long long V_8 ,
T_2 V_18 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_1 , V_8 ) ;
if ( V_13 ) {
if ( F_68 ( V_18 , V_13 -> V_18 ) )
V_13 -> V_18 = V_18 ;
return 0 ;
}
return F_2 ( V_1 , V_8 , V_18 ) ;
}
int F_69 ( T_1 * V_1 ,
unsigned long long V_8 ,
T_2 V_18 )
{
struct V_12 * V_13 ;
V_13 = F_9 ( V_1 , V_8 ) ;
if ( ! V_13 )
return 0 ;
if ( F_68 ( V_18 , V_13 -> V_18 ) )
return 0 ;
return 1 ;
}
void F_70 ( T_1 * V_1 )
{
int V_34 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_3 * V_61 ;
V_61 = V_1 -> V_5 ;
for ( V_34 = 0 ; V_34 < V_61 -> V_7 ; V_34 ++ ) {
V_11 = & V_61 -> V_19 [ V_34 ] ;
while ( ! F_20 ( V_11 ) ) {
V_13 = (struct V_12 * ) V_11 -> V_24 ;
F_47 ( & V_13 -> F_1 ) ;
F_17 ( V_15 , V_13 ) ;
}
}
}
