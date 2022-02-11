T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = ++ V_4 -> V_6 ;
V_2 -> V_7 -> V_8 = F_2 ( V_2 -> V_7 -> V_8 , F_3 ( V_4 ) ) ;
F_4 ( V_2 -> V_7 -> V_8 > V_9 ) ;
return V_5 ;
}
void F_5 ( struct V_10 * V_11 , int V_12 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned V_13 = V_11 -> V_14 * V_11 -> V_15 . V_16 / 1024 ;
unsigned V_17 ;
int V_18 ;
F_6 ( V_12 , & V_11 -> V_19 ) ;
do {
V_18 = F_7 ( & V_11 -> V_19 ) ;
if ( V_18 >= 0 )
return;
} while ( F_8 ( & V_11 -> V_19 , V_18 , V_18 + V_13 ) != V_18 );
F_9 ( & V_11 -> V_20 ) ;
V_11 -> V_21 = V_22 ;
F_10 (ca, c, i)
F_11 (b, ca)
if ( V_4 -> V_23 &&
V_4 -> V_23 != V_24 &&
! F_7 ( & V_4 -> V_25 ) ) {
V_4 -> V_23 -- ;
V_11 -> V_21 = F_12 ( V_11 -> V_21 , V_4 -> V_23 ) ;
}
F_13 ( & V_11 -> V_20 ) ;
}
static inline bool F_14 ( struct V_3 * V_4 )
{
return F_3 ( V_4 ) < V_9 ;
}
bool F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_16 ( ! V_2 -> V_7 -> V_26 ) ;
return ( ! F_17 ( V_4 ) ||
F_17 ( V_4 ) == V_27 ) &&
! F_7 ( & V_4 -> V_25 ) &&
F_14 ( V_4 ) ;
}
void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_19 ( & V_2 -> V_7 -> V_20 ) ;
F_16 ( F_17 ( V_4 ) && F_17 ( V_4 ) != V_27 ) ;
if ( F_20 ( V_4 ) )
F_21 ( V_2 , V_4 - V_2 -> V_28 ) ;
F_1 ( V_2 , V_4 ) ;
V_4 -> V_23 = V_29 ;
F_22 ( & V_4 -> V_25 ) ;
}
static void F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_18 ( V_2 , V_4 ) ;
F_24 ( & V_2 -> V_30 , V_4 - V_2 -> V_28 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_2 V_17 ;
V_2 -> V_31 . V_32 = 0 ;
F_11 (b, ca) {
if ( ! F_15 ( V_2 , V_4 ) )
continue;
if ( ! F_26 ( & V_2 -> V_31 ) )
F_27 ( & V_2 -> V_31 , V_4 , V_33 ) ;
else if ( V_33 ( V_4 , F_28 ( & V_2 -> V_31 ) ) ) {
V_2 -> V_31 . V_34 [ 0 ] = V_4 ;
F_29 ( & V_2 -> V_31 , 0 , V_33 ) ;
}
}
for ( V_17 = V_2 -> V_31 . V_32 / 2 - 1 ; V_17 >= 0 ; -- V_17 )
F_29 ( & V_2 -> V_31 , V_17 , V_35 ) ;
while ( ! F_30 ( & V_2 -> V_30 ) ) {
if ( ! F_31 ( & V_2 -> V_31 , V_4 , V_35 ) ) {
V_2 -> V_36 = 1 ;
F_32 ( V_2 -> V_7 ) ;
return;
}
F_23 ( V_2 , V_4 ) ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_3 V_37 = 0 ;
while ( ! F_30 ( & V_2 -> V_30 ) ) {
if ( V_2 -> V_38 < V_2 -> V_15 . V_39 ||
V_2 -> V_38 >= V_2 -> V_15 . V_14 )
V_2 -> V_38 = V_2 -> V_15 . V_39 ;
V_4 = V_2 -> V_28 + V_2 -> V_38 ++ ;
if ( F_15 ( V_2 , V_4 ) )
F_23 ( V_2 , V_4 ) ;
if ( ++ V_37 >= V_2 -> V_15 . V_14 ) {
V_2 -> V_36 = 1 ;
F_32 ( V_2 -> V_7 ) ;
return;
}
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_3 V_37 = 0 ;
while ( ! F_30 ( & V_2 -> V_30 ) ) {
T_3 V_40 ;
F_35 ( & V_40 , sizeof( V_40 ) ) ;
V_40 %= ( T_3 ) ( V_2 -> V_15 . V_14 - V_2 -> V_15 . V_39 ) ;
V_40 += V_2 -> V_15 . V_39 ;
V_4 = V_2 -> V_28 + V_40 ;
if ( F_15 ( V_2 , V_4 ) )
F_23 ( V_2 , V_4 ) ;
if ( ++ V_37 >= V_2 -> V_15 . V_14 / 2 ) {
V_2 -> V_36 = 1 ;
F_32 ( V_2 -> V_7 ) ;
return;
}
}
}
static void F_36 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_36 ) ;
switch ( F_37 ( & V_2 -> V_15 ) ) {
case V_41 :
F_25 ( V_2 ) ;
break;
case V_42 :
F_33 ( V_2 ) ;
break;
case V_43 :
F_34 ( V_2 ) ;
break;
}
}
static int F_38 ( struct V_1 * V_2 , long V_3 )
{
unsigned V_17 ;
if ( F_24 ( & V_2 -> free [ V_44 ] , V_3 ) )
return true ;
for ( V_17 = 0 ; V_17 < V_45 ; V_17 ++ )
if ( F_24 ( & V_2 -> free [ V_17 ] , V_3 ) )
return true ;
return false ;
}
static int F_39 ( void * V_46 )
{
struct V_1 * V_2 = V_46 ;
F_9 ( & V_2 -> V_7 -> V_20 ) ;
while ( 1 ) {
while ( ! F_40 ( & V_2 -> V_30 ) ) {
long V_3 ;
F_41 ( & V_2 -> V_30 , V_3 ) ;
if ( V_2 -> V_47 ) {
F_13 ( & V_2 -> V_7 -> V_20 ) ;
F_42 ( V_2 -> V_48 ,
F_43 ( V_2 -> V_7 , V_3 ) ,
V_2 -> V_15 . V_49 , V_50 , 0 ) ;
F_9 ( & V_2 -> V_7 -> V_20 ) ;
}
F_44 ( V_2 , F_38 ( V_2 , V_3 ) ) ;
F_45 ( & V_2 -> V_7 -> V_51 ) ;
F_45 ( & V_2 -> V_7 -> V_52 ) ;
}
V_53:
F_44 ( V_2 , V_2 -> V_7 -> V_26 &&
! V_2 -> V_36 ) ;
F_36 ( V_2 ) ;
F_44 ( V_2 , ! F_7 ( & V_2 -> V_7 -> V_54 ) ) ;
if ( F_46 ( & V_2 -> V_7 -> V_15 ) ) {
if ( ! F_30 ( & V_2 -> V_30 ) )
goto V_53;
F_47 ( V_2 ) ;
}
}
}
long F_48 ( struct V_1 * V_2 , unsigned V_55 , bool V_56 )
{
F_49 ( V_57 ) ;
struct V_3 * V_4 ;
long V_18 ;
if ( F_41 ( & V_2 -> free [ V_58 ] , V_18 ) ||
F_41 ( & V_2 -> free [ V_55 ] , V_18 ) )
goto V_59;
if ( ! V_56 ) {
F_50 ( V_2 , V_55 ) ;
return - 1 ;
}
do {
F_51 ( & V_2 -> V_7 -> V_52 , & V_57 ,
V_60 ) ;
F_13 ( & V_2 -> V_7 -> V_20 ) ;
F_52 () ;
F_9 ( & V_2 -> V_7 -> V_20 ) ;
} while ( ! F_41 ( & V_2 -> free [ V_58 ] , V_18 ) &&
! F_41 ( & V_2 -> free [ V_55 ] , V_18 ) );
F_53 ( & V_2 -> V_7 -> V_52 , & V_57 ) ;
V_59:
F_54 ( V_2 -> V_61 ) ;
F_55 ( V_2 , V_55 ) ;
if ( F_56 ( V_2 -> V_7 ) ) {
T_3 V_62 ;
long V_17 ;
unsigned V_63 ;
for ( V_62 = 0 ; V_62 < F_57 ( V_2 ) * 2 ; V_62 ++ )
F_16 ( V_2 -> F_57 [ V_62 ] == ( V_64 ) V_18 ) ;
for ( V_63 = 0 ; V_63 < V_45 ; V_63 ++ )
F_58 (i, &ca->free[j], iter)
F_16 ( V_17 == V_18 ) ;
F_58 (i, &ca->free_inc, iter)
F_16 ( V_17 == V_18 ) ;
}
V_4 = V_2 -> V_28 + V_18 ;
F_16 ( F_7 ( & V_4 -> V_25 ) != 1 ) ;
F_59 ( V_4 , V_2 -> V_15 . V_16 ) ;
if ( V_55 <= V_44 ) {
F_60 ( V_4 , V_65 ) ;
F_61 ( V_4 , 0 ) ;
V_4 -> V_23 = V_24 ;
} else {
F_60 ( V_4 , V_27 ) ;
F_61 ( V_4 , 0 ) ;
V_4 -> V_23 = V_29 ;
}
return V_18 ;
}
void F_62 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_60 ( V_4 , 0 ) ;
F_59 ( V_4 , 0 ) ;
}
void F_63 ( struct V_10 * V_11 , struct V_66 * V_67 )
{
unsigned V_17 ;
for ( V_17 = 0 ; V_17 < F_64 ( V_67 ) ; V_17 ++ )
F_62 ( F_65 ( V_11 , V_67 , V_17 ) ,
F_66 ( V_11 , V_67 , V_17 ) ) ;
}
int F_67 ( struct V_10 * V_11 , unsigned V_55 ,
struct V_66 * V_67 , int V_40 , bool V_56 )
{
int V_17 ;
F_19 ( & V_11 -> V_20 ) ;
F_16 ( ! V_40 || V_40 > V_11 -> V_68 || V_40 > 8 ) ;
F_68 ( V_67 ) ;
for ( V_17 = 0 ; V_17 < V_40 ; V_17 ++ ) {
struct V_1 * V_2 = V_11 -> V_69 [ V_17 ] ;
long V_4 = F_48 ( V_2 , V_55 , V_56 ) ;
if ( V_4 == - 1 )
goto V_70;
V_67 -> V_71 [ V_17 ] = F_69 ( V_2 -> V_28 [ V_4 ] . V_6 ,
F_43 ( V_11 , V_4 ) ,
V_2 -> V_15 . V_72 ) ;
F_70 ( V_67 , V_17 + 1 ) ;
}
return 0 ;
V_70:
F_63 ( V_11 , V_67 ) ;
F_71 ( V_11 , V_67 ) ;
return - 1 ;
}
int F_72 ( struct V_10 * V_11 , unsigned V_55 ,
struct V_66 * V_67 , int V_40 , bool V_56 )
{
int V_5 ;
F_9 ( & V_11 -> V_20 ) ;
V_5 = F_67 ( V_11 , V_55 , V_67 , V_40 , V_56 ) ;
F_13 ( & V_11 -> V_20 ) ;
return V_5 ;
}
static struct V_73 * F_73 ( struct V_10 * V_11 ,
const struct V_66 * V_74 ,
unsigned V_75 ,
struct V_66 * V_76 )
{
struct V_73 * V_5 , * V_77 = NULL ;
F_74 (ret, &c->data_buckets, list)
if ( ! F_75 ( & V_5 -> V_78 , V_74 ) )
goto V_79;
else if ( V_5 -> V_80 == V_75 )
V_77 = V_5 ;
V_5 = V_77 ? : F_76 ( & V_11 -> V_81 ,
struct V_73 , V_82 ) ;
V_79:
if ( ! V_5 -> V_83 && F_64 ( V_76 ) ) {
V_5 -> V_83 = V_11 -> V_15 . V_16 ;
F_77 ( & V_5 -> V_78 , V_76 ) ;
F_68 ( V_76 ) ;
}
if ( ! V_5 -> V_83 )
V_5 = NULL ;
return V_5 ;
}
bool F_78 ( struct V_10 * V_11 , struct V_66 * V_67 , unsigned V_12 ,
unsigned V_75 , unsigned V_84 , bool V_56 )
{
struct V_73 * V_4 ;
F_79 (key) V_76 ;
unsigned V_17 ;
F_68 ( & V_76 . V_78 ) ;
F_80 ( & V_11 -> V_85 ) ;
while ( ! ( V_4 = F_73 ( V_11 , V_67 , V_75 , & V_76 . V_78 ) ) ) {
unsigned V_86 = V_84
? V_87
: V_58 ;
F_81 ( & V_11 -> V_85 ) ;
if ( F_72 ( V_11 , V_86 , & V_76 . V_78 , 1 , V_56 ) )
return false ;
F_80 ( & V_11 -> V_85 ) ;
}
if ( F_64 ( & V_76 . V_78 ) )
F_71 ( V_11 , & V_76 . V_78 ) ;
for ( V_17 = 0 ; V_17 < F_64 ( & V_4 -> V_78 ) ; V_17 ++ )
F_82 ( F_83 ( V_11 , & V_4 -> V_78 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < F_64 ( & V_4 -> V_78 ) ; V_17 ++ )
V_67 -> V_71 [ V_17 ] = V_4 -> V_78 . V_71 [ V_17 ] ;
V_12 = F_12 ( V_12 , V_4 -> V_83 ) ;
F_84 ( V_67 , F_85 ( V_67 ) + V_12 ) ;
F_86 ( V_67 , V_12 ) ;
F_70 ( V_67 , F_64 ( & V_4 -> V_78 ) ) ;
F_87 ( & V_4 -> V_82 , & V_11 -> V_81 ) ;
F_88 ( & V_4 -> V_78 , V_67 ) ;
V_4 -> V_80 = V_75 ;
V_4 -> V_83 -= V_12 ;
for ( V_17 = 0 ; V_17 < F_64 ( & V_4 -> V_78 ) ; V_17 ++ ) {
F_89 ( & V_4 -> V_78 , V_17 , F_90 ( & V_4 -> V_78 , V_17 ) + V_12 ) ;
F_91 ( V_12 ,
& F_65 ( V_11 , & V_4 -> V_78 , V_17 ) -> V_88 ) ;
}
if ( V_4 -> V_83 < V_11 -> V_15 . V_49 )
V_4 -> V_83 = 0 ;
if ( V_4 -> V_83 )
for ( V_17 = 0 ; V_17 < F_64 ( & V_4 -> V_78 ) ; V_17 ++ )
F_22 ( & F_66 ( V_11 , & V_4 -> V_78 , V_17 ) -> V_25 ) ;
F_81 ( & V_11 -> V_85 ) ;
return true ;
}
void F_92 ( struct V_10 * V_11 )
{
struct V_73 * V_4 ;
while ( ! F_93 ( & V_11 -> V_81 ) ) {
V_4 = F_76 ( & V_11 -> V_81 ,
struct V_73 , V_82 ) ;
F_94 ( & V_4 -> V_82 ) ;
F_95 ( V_4 ) ;
}
}
int F_96 ( struct V_10 * V_11 )
{
int V_17 ;
F_97 ( & V_11 -> V_85 ) ;
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ ) {
struct V_73 * V_4 = F_98 ( sizeof( * V_4 ) , V_50 ) ;
if ( ! V_4 )
return - V_89 ;
F_99 ( & V_4 -> V_82 , & V_11 -> V_81 ) ;
}
return 0 ;
}
int F_100 ( struct V_1 * V_2 )
{
struct V_90 * V_67 = F_101 ( F_39 ,
V_2 , L_1 ) ;
if ( F_102 ( V_67 ) )
return F_103 ( V_67 ) ;
V_2 -> V_61 = V_67 ;
return 0 ;
}
