T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = ++ V_4 -> V_6 ;
V_2 -> V_7 -> V_8 = F_2 ( V_2 -> V_7 -> V_8 , F_3 ( V_4 ) ) ;
F_4 ( V_2 -> V_7 -> V_8 > V_9 ) ;
if ( F_5 ( & V_2 -> V_7 -> V_10 ) ) {
V_2 -> V_11 = F_2 ( V_2 -> V_11 ,
F_6 ( V_4 ) ) ;
F_4 ( V_2 -> V_11 > V_12 ) ;
}
return V_5 ;
}
void F_7 ( struct V_13 * V_14 , int V_15 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned V_16 = V_14 -> V_17 * V_14 -> V_10 . V_18 / 1024 ;
unsigned V_19 ;
int V_20 ;
F_8 ( V_15 , & V_14 -> V_21 ) ;
do {
V_20 = F_9 ( & V_14 -> V_21 ) ;
if ( V_20 >= 0 )
return;
} while ( F_10 ( & V_14 -> V_21 , V_20 , V_20 + V_16 ) != V_20 );
F_11 ( & V_14 -> V_22 ) ;
V_14 -> V_23 = V_24 ;
F_12 (ca, c, i)
F_13 (b, ca)
if ( V_4 -> V_25 &&
V_4 -> V_25 != V_26 &&
! F_9 ( & V_4 -> V_27 ) ) {
V_4 -> V_25 -- ;
V_14 -> V_23 = F_14 ( V_14 -> V_23 , V_4 -> V_25 ) ;
}
F_15 ( & V_14 -> V_22 ) ;
}
static inline bool F_16 ( struct V_3 * V_4 )
{
return F_3 ( V_4 ) < V_9 &&
F_6 ( V_4 ) < V_12 ;
}
bool F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_18 ( F_19 ( V_4 ) || F_20 ( V_4 ) ) ;
if ( F_21 ( & V_2 -> free ) > V_2 -> V_28 [ V_29 ] &&
F_22 ( & V_2 -> V_10 ) == V_30 )
return false ;
V_4 -> V_25 = 0 ;
if ( F_16 ( V_4 ) &&
F_23 ( & V_2 -> V_31 , V_4 - V_2 -> V_32 ) ) {
F_24 ( & V_4 -> V_27 ) ;
return true ;
}
return false ;
}
static bool F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_19 ( V_4 ) == V_33 &&
! F_9 ( & V_4 -> V_27 ) &&
F_16 ( V_4 ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
V_4 -> V_25 = V_34 ;
F_24 ( & V_4 -> V_27 ) ;
F_23 ( & V_2 -> V_35 , V_4 - V_2 -> V_32 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_2 V_19 ;
V_2 -> V_36 . V_37 = 0 ;
F_13 (b, ca) {
if ( F_28 ( & V_2 -> V_31 ) )
return;
if ( ! F_25 ( V_2 , V_4 ) )
continue;
if ( ! F_20 ( V_4 ) &&
F_17 ( V_2 , V_4 ) )
continue;
if ( ! F_29 ( & V_2 -> V_36 ) )
F_30 ( & V_2 -> V_36 , V_4 , V_38 ) ;
else if ( V_38 ( V_4 , F_31 ( & V_2 -> V_36 ) ) ) {
V_2 -> V_36 . V_39 [ 0 ] = V_4 ;
F_32 ( & V_2 -> V_36 , 0 , V_38 ) ;
}
}
for ( V_19 = V_2 -> V_36 . V_37 / 2 - 1 ; V_19 >= 0 ; -- V_19 )
F_32 ( & V_2 -> V_36 , V_19 , V_40 ) ;
while ( ! F_28 ( & V_2 -> V_35 ) ) {
if ( ! F_33 ( & V_2 -> V_36 , V_4 , V_40 ) ) {
V_2 -> V_41 = 1 ;
F_34 ( V_2 -> V_7 ) ;
return;
}
F_26 ( V_2 , V_4 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_3 V_42 = 0 ;
while ( ! F_28 ( & V_2 -> V_35 ) ) {
if ( V_2 -> V_43 < V_2 -> V_10 . V_44 ||
V_2 -> V_43 >= V_2 -> V_10 . V_17 )
V_2 -> V_43 = V_2 -> V_10 . V_44 ;
V_4 = V_2 -> V_32 + V_2 -> V_43 ++ ;
if ( F_25 ( V_2 , V_4 ) )
F_26 ( V_2 , V_4 ) ;
if ( ++ V_42 >= V_2 -> V_10 . V_17 ) {
V_2 -> V_41 = 1 ;
F_34 ( V_2 -> V_7 ) ;
return;
}
}
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_3 V_42 = 0 ;
while ( ! F_28 ( & V_2 -> V_35 ) ) {
T_3 V_45 ;
F_37 ( & V_45 , sizeof( V_45 ) ) ;
V_45 %= ( T_3 ) ( V_2 -> V_10 . V_17 - V_2 -> V_10 . V_44 ) ;
V_45 += V_2 -> V_10 . V_44 ;
V_4 = V_2 -> V_32 + V_45 ;
if ( F_25 ( V_2 , V_4 ) )
F_26 ( V_2 , V_4 ) ;
if ( ++ V_42 >= V_2 -> V_10 . V_17 / 2 ) {
V_2 -> V_41 = 1 ;
F_34 ( V_2 -> V_7 ) ;
return;
}
}
}
static void F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 )
return;
switch ( F_22 ( & V_2 -> V_10 ) ) {
case V_46 :
F_27 ( V_2 ) ;
break;
case V_30 :
F_35 ( V_2 ) ;
break;
case V_47 :
F_36 ( V_2 ) ;
break;
}
F_39 ( V_2 ) ;
}
static int F_40 ( void * V_48 )
{
struct V_1 * V_2 = V_48 ;
F_11 ( & V_2 -> V_7 -> V_22 ) ;
while ( 1 ) {
while ( 1 ) {
long V_3 ;
if ( ( ! F_9 ( & V_2 -> V_7 -> V_49 ) ||
! F_5 ( & V_2 -> V_7 -> V_10 ) ) &&
! F_41 ( & V_2 -> V_31 ) )
F_42 ( & V_2 -> V_31 , V_3 ) ;
else if ( ! F_41 ( & V_2 -> V_35 ) )
F_42 ( & V_2 -> V_35 , V_3 ) ;
else
break;
if ( V_2 -> V_50 ) {
F_15 ( & V_2 -> V_7 -> V_22 ) ;
F_43 ( V_2 -> V_51 ,
F_44 ( V_2 -> V_7 , V_3 ) ,
V_2 -> V_10 . V_52 , V_53 , 0 ) ;
F_11 ( & V_2 -> V_7 -> V_22 ) ;
}
F_45 ( V_2 , ! F_28 ( & V_2 -> free ) ) ;
F_23 ( & V_2 -> free , V_3 ) ;
F_46 ( & V_2 -> V_7 -> V_54 ) ;
}
F_45 ( V_2 , V_2 -> V_7 -> V_55 &&
( V_2 -> V_11 > 64 ||
! V_2 -> V_41 ) ) ;
F_38 ( V_2 ) ;
F_45 ( V_2 , ! F_9 ( & V_2 -> V_7 -> V_49 ) ) ;
if ( F_5 ( & V_2 -> V_7 -> V_10 ) &&
( ! F_41 ( & V_2 -> V_35 ) ||
V_2 -> V_11 > 64 ) )
F_47 ( V_2 ) ;
}
}
long F_48 ( struct V_1 * V_2 , unsigned V_28 , bool V_56 )
{
F_49 ( V_57 ) ;
struct V_3 * V_4 ;
long V_20 ;
if ( F_21 ( & V_2 -> free ) > V_2 -> V_28 [ V_28 ] ) {
F_42 ( & V_2 -> free , V_20 ) ;
goto V_58;
}
if ( ! V_56 )
return - 1 ;
while ( 1 ) {
if ( F_21 ( & V_2 -> free ) > V_2 -> V_28 [ V_28 ] ) {
F_42 ( & V_2 -> free , V_20 ) ;
break;
}
F_50 ( & V_2 -> V_7 -> V_54 , & V_57 ,
V_59 ) ;
F_15 ( & V_2 -> V_7 -> V_22 ) ;
F_51 () ;
F_11 ( & V_2 -> V_7 -> V_22 ) ;
}
F_52 ( & V_2 -> V_7 -> V_54 , & V_57 ) ;
V_58:
F_53 ( V_2 -> V_60 ) ;
if ( F_54 ( V_2 -> V_7 ) ) {
T_3 V_61 ;
long V_19 ;
for ( V_61 = 0 ; V_61 < F_55 ( V_2 ) * 2 ; V_61 ++ )
F_18 ( V_2 -> F_55 [ V_61 ] == ( V_62 ) V_20 ) ;
F_56 (i, &ca->free, iter)
F_18 ( V_19 == V_20 ) ;
F_56 (i, &ca->free_inc, iter)
F_18 ( V_19 == V_20 ) ;
F_56 (i, &ca->unused, iter)
F_18 ( V_19 == V_20 ) ;
}
V_4 = V_2 -> V_32 + V_20 ;
F_18 ( F_9 ( & V_4 -> V_27 ) != 1 ) ;
F_57 ( V_4 , V_2 -> V_10 . V_18 ) ;
if ( V_28 <= V_63 ) {
F_58 ( V_4 , V_64 ) ;
F_59 ( V_4 , 0 ) ;
V_4 -> V_25 = V_26 ;
} else {
F_58 ( V_4 , V_33 ) ;
F_59 ( V_4 , 0 ) ;
V_4 -> V_25 = V_34 ;
}
return V_20 ;
}
void F_60 ( struct V_13 * V_14 , struct V_65 * V_66 )
{
unsigned V_19 ;
for ( V_19 = 0 ; V_19 < F_61 ( V_66 ) ; V_19 ++ ) {
struct V_3 * V_4 = F_62 ( V_14 , V_66 , V_19 ) ;
F_58 ( V_4 , V_33 ) ;
F_57 ( V_4 , 0 ) ;
F_17 ( F_63 ( V_14 , V_66 , V_19 ) , V_4 ) ;
}
}
int F_64 ( struct V_13 * V_14 , unsigned V_28 ,
struct V_65 * V_66 , int V_45 , bool V_56 )
{
int V_19 ;
F_65 ( & V_14 -> V_22 ) ;
F_18 ( ! V_45 || V_45 > V_14 -> V_67 || V_45 > 8 ) ;
F_66 ( V_66 ) ;
for ( V_19 = 0 ; V_19 < V_45 ; V_19 ++ ) {
struct V_1 * V_2 = V_14 -> V_68 [ V_19 ] ;
long V_4 = F_48 ( V_2 , V_28 , V_56 ) ;
if ( V_4 == - 1 )
goto V_69;
V_66 -> V_70 [ V_19 ] = F_67 ( V_2 -> V_32 [ V_4 ] . V_6 ,
F_44 ( V_14 , V_4 ) ,
V_2 -> V_10 . V_71 ) ;
F_68 ( V_66 , V_19 + 1 ) ;
}
return 0 ;
V_69:
F_60 ( V_14 , V_66 ) ;
F_69 ( V_14 , V_66 ) ;
return - 1 ;
}
int F_70 ( struct V_13 * V_14 , unsigned V_28 ,
struct V_65 * V_66 , int V_45 , bool V_56 )
{
int V_5 ;
F_11 ( & V_14 -> V_22 ) ;
V_5 = F_64 ( V_14 , V_28 , V_66 , V_45 , V_56 ) ;
F_15 ( & V_14 -> V_22 ) ;
return V_5 ;
}
static struct V_72 * F_71 ( struct V_13 * V_14 ,
const struct V_65 * V_73 ,
unsigned V_74 ,
struct V_65 * V_75 )
{
struct V_72 * V_5 , * V_76 = NULL ;
F_72 (ret, &c->data_buckets, list)
if ( ! F_73 ( & V_5 -> V_77 , V_73 ) )
goto V_78;
else if ( V_5 -> V_79 == V_74 )
V_76 = V_5 ;
V_5 = V_76 ? : F_74 ( & V_14 -> V_80 ,
struct V_72 , V_81 ) ;
V_78:
if ( ! V_5 -> V_82 && F_61 ( V_75 ) ) {
V_5 -> V_82 = V_14 -> V_10 . V_18 ;
F_75 ( & V_5 -> V_77 , V_75 ) ;
F_66 ( V_75 ) ;
}
if ( ! V_5 -> V_82 )
V_5 = NULL ;
return V_5 ;
}
bool F_76 ( struct V_13 * V_14 , struct V_65 * V_66 , unsigned V_15 ,
unsigned V_74 , unsigned V_83 , bool V_56 )
{
struct V_72 * V_4 ;
F_77 (key) V_75 ;
unsigned V_19 ;
F_66 ( & V_75 . V_77 ) ;
F_78 ( & V_14 -> V_84 ) ;
while ( ! ( V_4 = F_71 ( V_14 , V_66 , V_74 , & V_75 . V_77 ) ) ) {
unsigned V_28 = V_83
? V_29
: V_85 ;
F_79 ( & V_14 -> V_84 ) ;
if ( F_70 ( V_14 , V_28 , & V_75 . V_77 , 1 , V_56 ) )
return false ;
F_78 ( & V_14 -> V_84 ) ;
}
if ( F_61 ( & V_75 . V_77 ) )
F_69 ( V_14 , & V_75 . V_77 ) ;
for ( V_19 = 0 ; V_19 < F_61 ( & V_4 -> V_77 ) ; V_19 ++ )
F_80 ( F_81 ( V_14 , & V_4 -> V_77 , V_19 ) ) ;
for ( V_19 = 0 ; V_19 < F_61 ( & V_4 -> V_77 ) ; V_19 ++ )
V_66 -> V_70 [ V_19 ] = V_4 -> V_77 . V_70 [ V_19 ] ;
V_15 = F_14 ( V_15 , V_4 -> V_82 ) ;
F_82 ( V_66 , F_83 ( V_66 ) + V_15 ) ;
F_84 ( V_66 , V_15 ) ;
F_68 ( V_66 , F_61 ( & V_4 -> V_77 ) ) ;
F_85 ( & V_4 -> V_81 , & V_14 -> V_80 ) ;
F_86 ( & V_4 -> V_77 , V_66 ) ;
V_4 -> V_79 = V_74 ;
V_4 -> V_82 -= V_15 ;
for ( V_19 = 0 ; V_19 < F_61 ( & V_4 -> V_77 ) ; V_19 ++ ) {
F_87 ( & V_4 -> V_77 , V_19 , F_88 ( & V_4 -> V_77 , V_19 ) + V_15 ) ;
F_89 ( V_15 ,
& F_63 ( V_14 , & V_4 -> V_77 , V_19 ) -> V_86 ) ;
}
if ( V_4 -> V_82 < V_14 -> V_10 . V_52 )
V_4 -> V_82 = 0 ;
if ( V_4 -> V_82 )
for ( V_19 = 0 ; V_19 < F_61 ( & V_4 -> V_77 ) ; V_19 ++ )
F_24 ( & F_62 ( V_14 , & V_4 -> V_77 , V_19 ) -> V_27 ) ;
F_79 ( & V_14 -> V_84 ) ;
return true ;
}
void F_90 ( struct V_13 * V_14 )
{
struct V_72 * V_4 ;
while ( ! F_91 ( & V_14 -> V_80 ) ) {
V_4 = F_74 ( & V_14 -> V_80 ,
struct V_72 , V_81 ) ;
F_92 ( & V_4 -> V_81 ) ;
F_93 ( V_4 ) ;
}
}
int F_94 ( struct V_13 * V_14 )
{
int V_19 ;
F_95 ( & V_14 -> V_84 ) ;
for ( V_19 = 0 ; V_19 < 6 ; V_19 ++ ) {
struct V_72 * V_4 = F_96 ( sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return - V_87 ;
F_97 ( & V_4 -> V_81 , & V_14 -> V_80 ) ;
}
return 0 ;
}
int F_98 ( struct V_1 * V_2 )
{
struct V_88 * V_66 = F_99 ( F_40 ,
V_2 , L_1 ) ;
if ( F_100 ( V_66 ) )
return F_101 ( V_66 ) ;
V_2 -> V_60 = V_66 ;
return 0 ;
}
int F_102 ( struct V_1 * V_2 )
{
V_2 -> V_28 [ V_89 ] = 0 ;
V_2 -> V_28 [ V_63 ] = F_55 ( V_2 ) ;
V_2 -> V_28 [ V_29 ] = 8 +
V_2 -> V_28 [ V_63 ] ;
V_2 -> V_28 [ V_85 ] = V_2 -> free . V_90 / 2 +
V_2 -> V_28 [ V_29 ] ;
return 0 ;
}
