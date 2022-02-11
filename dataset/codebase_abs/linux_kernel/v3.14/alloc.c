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
if ( F_21 ( & V_2 -> V_10 ) == V_28 ) {
unsigned V_19 ;
for ( V_19 = 0 ; V_19 < V_29 ; V_19 ++ )
if ( ! F_22 ( & V_2 -> free [ V_19 ] ) )
goto V_30;
return false ;
}
V_30:
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
if ( F_22 ( & V_2 -> V_31 ) )
return;
if ( ! F_25 ( V_2 , V_4 ) )
continue;
if ( ! F_20 ( V_4 ) &&
F_17 ( V_2 , V_4 ) )
continue;
if ( ! F_28 ( & V_2 -> V_36 ) )
F_29 ( & V_2 -> V_36 , V_4 , V_38 ) ;
else if ( V_38 ( V_4 , F_30 ( & V_2 -> V_36 ) ) ) {
V_2 -> V_36 . V_39 [ 0 ] = V_4 ;
F_31 ( & V_2 -> V_36 , 0 , V_38 ) ;
}
}
for ( V_19 = V_2 -> V_36 . V_37 / 2 - 1 ; V_19 >= 0 ; -- V_19 )
F_31 ( & V_2 -> V_36 , V_19 , V_40 ) ;
while ( ! F_22 ( & V_2 -> V_35 ) ) {
if ( ! F_32 ( & V_2 -> V_36 , V_4 , V_40 ) ) {
V_2 -> V_41 = 1 ;
F_33 ( V_2 -> V_7 ) ;
return;
}
F_26 ( V_2 , V_4 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_3 V_42 = 0 ;
while ( ! F_22 ( & V_2 -> V_35 ) ) {
if ( V_2 -> V_43 < V_2 -> V_10 . V_44 ||
V_2 -> V_43 >= V_2 -> V_10 . V_17 )
V_2 -> V_43 = V_2 -> V_10 . V_44 ;
V_4 = V_2 -> V_32 + V_2 -> V_43 ++ ;
if ( F_25 ( V_2 , V_4 ) )
F_26 ( V_2 , V_4 ) ;
if ( ++ V_42 >= V_2 -> V_10 . V_17 ) {
V_2 -> V_41 = 1 ;
F_33 ( V_2 -> V_7 ) ;
return;
}
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_3 V_42 = 0 ;
while ( ! F_22 ( & V_2 -> V_35 ) ) {
T_3 V_45 ;
F_36 ( & V_45 , sizeof( V_45 ) ) ;
V_45 %= ( T_3 ) ( V_2 -> V_10 . V_17 - V_2 -> V_10 . V_44 ) ;
V_45 += V_2 -> V_10 . V_44 ;
V_4 = V_2 -> V_32 + V_45 ;
if ( F_25 ( V_2 , V_4 ) )
F_26 ( V_2 , V_4 ) ;
if ( ++ V_42 >= V_2 -> V_10 . V_17 / 2 ) {
V_2 -> V_41 = 1 ;
F_33 ( V_2 -> V_7 ) ;
return;
}
}
}
static void F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 )
return;
switch ( F_21 ( & V_2 -> V_10 ) ) {
case V_46 :
F_27 ( V_2 ) ;
break;
case V_28 :
F_34 ( V_2 ) ;
break;
case V_47 :
F_35 ( V_2 ) ;
break;
}
F_38 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 , long V_3 )
{
unsigned V_19 ;
if ( F_23 ( & V_2 -> free [ V_48 ] , V_3 ) )
return true ;
for ( V_19 = 0 ; V_19 < V_49 ; V_19 ++ )
if ( F_23 ( & V_2 -> free [ V_19 ] , V_3 ) )
return true ;
return false ;
}
static int F_40 ( void * V_50 )
{
struct V_1 * V_2 = V_50 ;
F_11 ( & V_2 -> V_7 -> V_22 ) ;
while ( 1 ) {
while ( 1 ) {
long V_3 ;
if ( ( ! F_9 ( & V_2 -> V_7 -> V_51 ) ||
! F_5 ( & V_2 -> V_7 -> V_10 ) ) &&
! F_41 ( & V_2 -> V_31 ) )
F_42 ( & V_2 -> V_31 , V_3 ) ;
else if ( ! F_41 ( & V_2 -> V_35 ) )
F_42 ( & V_2 -> V_35 , V_3 ) ;
else
break;
if ( V_2 -> V_52 ) {
F_15 ( & V_2 -> V_7 -> V_22 ) ;
F_43 ( V_2 -> V_53 ,
F_44 ( V_2 -> V_7 , V_3 ) ,
V_2 -> V_10 . V_54 , V_55 , 0 ) ;
F_11 ( & V_2 -> V_7 -> V_22 ) ;
}
F_45 ( V_2 , F_39 ( V_2 , V_3 ) ) ;
F_46 ( & V_2 -> V_7 -> V_56 ) ;
}
F_45 ( V_2 , V_2 -> V_7 -> V_57 &&
( V_2 -> V_11 > 64 ||
! V_2 -> V_41 ) ) ;
F_37 ( V_2 ) ;
F_45 ( V_2 , ! F_9 ( & V_2 -> V_7 -> V_51 ) ) ;
if ( F_5 ( & V_2 -> V_7 -> V_10 ) &&
( ! F_41 ( & V_2 -> V_35 ) ||
V_2 -> V_11 > 64 ) )
F_47 ( V_2 ) ;
}
}
long F_48 ( struct V_1 * V_2 , unsigned V_58 , bool V_59 )
{
F_49 ( V_60 ) ;
struct V_3 * V_4 ;
long V_20 ;
if ( F_42 ( & V_2 -> free [ V_29 ] , V_20 ) ||
F_42 ( & V_2 -> free [ V_58 ] , V_20 ) )
goto V_61;
if ( ! V_59 )
return - 1 ;
do {
F_50 ( & V_2 -> V_7 -> V_56 , & V_60 ,
V_62 ) ;
F_15 ( & V_2 -> V_7 -> V_22 ) ;
F_51 () ;
F_11 ( & V_2 -> V_7 -> V_22 ) ;
} while ( ! F_42 ( & V_2 -> free [ V_29 ] , V_20 ) &&
! F_42 ( & V_2 -> free [ V_58 ] , V_20 ) );
F_52 ( & V_2 -> V_7 -> V_56 , & V_60 ) ;
V_61:
F_53 ( V_2 -> V_63 ) ;
if ( F_54 ( V_2 -> V_7 ) ) {
T_3 V_64 ;
long V_19 ;
unsigned V_65 ;
for ( V_64 = 0 ; V_64 < F_55 ( V_2 ) * 2 ; V_64 ++ )
F_18 ( V_2 -> F_55 [ V_64 ] == ( V_66 ) V_20 ) ;
for ( V_65 = 0 ; V_65 < V_49 ; V_65 ++ )
F_56 (i, &ca->free[j], iter)
F_18 ( V_19 == V_20 ) ;
F_56 (i, &ca->free_inc, iter)
F_18 ( V_19 == V_20 ) ;
F_56 (i, &ca->unused, iter)
F_18 ( V_19 == V_20 ) ;
}
V_4 = V_2 -> V_32 + V_20 ;
F_18 ( F_9 ( & V_4 -> V_27 ) != 1 ) ;
F_57 ( V_4 , V_2 -> V_10 . V_18 ) ;
if ( V_58 <= V_48 ) {
F_58 ( V_4 , V_67 ) ;
F_59 ( V_4 , 0 ) ;
V_4 -> V_25 = V_26 ;
} else {
F_58 ( V_4 , V_33 ) ;
F_59 ( V_4 , 0 ) ;
V_4 -> V_25 = V_34 ;
}
return V_20 ;
}
void F_60 ( struct V_13 * V_14 , struct V_68 * V_69 )
{
unsigned V_19 ;
for ( V_19 = 0 ; V_19 < F_61 ( V_69 ) ; V_19 ++ ) {
struct V_3 * V_4 = F_62 ( V_14 , V_69 , V_19 ) ;
F_58 ( V_4 , V_33 ) ;
F_57 ( V_4 , 0 ) ;
F_17 ( F_63 ( V_14 , V_69 , V_19 ) , V_4 ) ;
}
}
int F_64 ( struct V_13 * V_14 , unsigned V_58 ,
struct V_68 * V_69 , int V_45 , bool V_59 )
{
int V_19 ;
F_65 ( & V_14 -> V_22 ) ;
F_18 ( ! V_45 || V_45 > V_14 -> V_70 || V_45 > 8 ) ;
F_66 ( V_69 ) ;
for ( V_19 = 0 ; V_19 < V_45 ; V_19 ++ ) {
struct V_1 * V_2 = V_14 -> V_71 [ V_19 ] ;
long V_4 = F_48 ( V_2 , V_58 , V_59 ) ;
if ( V_4 == - 1 )
goto V_72;
V_69 -> V_73 [ V_19 ] = F_67 ( V_2 -> V_32 [ V_4 ] . V_6 ,
F_44 ( V_14 , V_4 ) ,
V_2 -> V_10 . V_74 ) ;
F_68 ( V_69 , V_19 + 1 ) ;
}
return 0 ;
V_72:
F_60 ( V_14 , V_69 ) ;
F_69 ( V_14 , V_69 ) ;
return - 1 ;
}
int F_70 ( struct V_13 * V_14 , unsigned V_58 ,
struct V_68 * V_69 , int V_45 , bool V_59 )
{
int V_5 ;
F_11 ( & V_14 -> V_22 ) ;
V_5 = F_64 ( V_14 , V_58 , V_69 , V_45 , V_59 ) ;
F_15 ( & V_14 -> V_22 ) ;
return V_5 ;
}
static struct V_75 * F_71 ( struct V_13 * V_14 ,
const struct V_68 * V_76 ,
unsigned V_77 ,
struct V_68 * V_78 )
{
struct V_75 * V_5 , * V_79 = NULL ;
F_72 (ret, &c->data_buckets, list)
if ( ! F_73 ( & V_5 -> V_80 , V_76 ) )
goto V_81;
else if ( V_5 -> V_82 == V_77 )
V_79 = V_5 ;
V_5 = V_79 ? : F_74 ( & V_14 -> V_83 ,
struct V_75 , V_84 ) ;
V_81:
if ( ! V_5 -> V_85 && F_61 ( V_78 ) ) {
V_5 -> V_85 = V_14 -> V_10 . V_18 ;
F_75 ( & V_5 -> V_80 , V_78 ) ;
F_66 ( V_78 ) ;
}
if ( ! V_5 -> V_85 )
V_5 = NULL ;
return V_5 ;
}
bool F_76 ( struct V_13 * V_14 , struct V_68 * V_69 , unsigned V_15 ,
unsigned V_77 , unsigned V_86 , bool V_59 )
{
struct V_75 * V_4 ;
F_77 (key) V_78 ;
unsigned V_19 ;
F_66 ( & V_78 . V_80 ) ;
F_78 ( & V_14 -> V_87 ) ;
while ( ! ( V_4 = F_71 ( V_14 , V_69 , V_77 , & V_78 . V_80 ) ) ) {
unsigned V_88 = V_86
? V_89
: V_29 ;
F_79 ( & V_14 -> V_87 ) ;
if ( F_70 ( V_14 , V_88 , & V_78 . V_80 , 1 , V_59 ) )
return false ;
F_78 ( & V_14 -> V_87 ) ;
}
if ( F_61 ( & V_78 . V_80 ) )
F_69 ( V_14 , & V_78 . V_80 ) ;
for ( V_19 = 0 ; V_19 < F_61 ( & V_4 -> V_80 ) ; V_19 ++ )
F_80 ( F_81 ( V_14 , & V_4 -> V_80 , V_19 ) ) ;
for ( V_19 = 0 ; V_19 < F_61 ( & V_4 -> V_80 ) ; V_19 ++ )
V_69 -> V_73 [ V_19 ] = V_4 -> V_80 . V_73 [ V_19 ] ;
V_15 = F_14 ( V_15 , V_4 -> V_85 ) ;
F_82 ( V_69 , F_83 ( V_69 ) + V_15 ) ;
F_84 ( V_69 , V_15 ) ;
F_68 ( V_69 , F_61 ( & V_4 -> V_80 ) ) ;
F_85 ( & V_4 -> V_84 , & V_14 -> V_83 ) ;
F_86 ( & V_4 -> V_80 , V_69 ) ;
V_4 -> V_82 = V_77 ;
V_4 -> V_85 -= V_15 ;
for ( V_19 = 0 ; V_19 < F_61 ( & V_4 -> V_80 ) ; V_19 ++ ) {
F_87 ( & V_4 -> V_80 , V_19 , F_88 ( & V_4 -> V_80 , V_19 ) + V_15 ) ;
F_89 ( V_15 ,
& F_63 ( V_14 , & V_4 -> V_80 , V_19 ) -> V_90 ) ;
}
if ( V_4 -> V_85 < V_14 -> V_10 . V_54 )
V_4 -> V_85 = 0 ;
if ( V_4 -> V_85 )
for ( V_19 = 0 ; V_19 < F_61 ( & V_4 -> V_80 ) ; V_19 ++ )
F_24 ( & F_62 ( V_14 , & V_4 -> V_80 , V_19 ) -> V_27 ) ;
F_79 ( & V_14 -> V_87 ) ;
return true ;
}
void F_90 ( struct V_13 * V_14 )
{
struct V_75 * V_4 ;
while ( ! F_91 ( & V_14 -> V_83 ) ) {
V_4 = F_74 ( & V_14 -> V_83 ,
struct V_75 , V_84 ) ;
F_92 ( & V_4 -> V_84 ) ;
F_93 ( V_4 ) ;
}
}
int F_94 ( struct V_13 * V_14 )
{
int V_19 ;
F_95 ( & V_14 -> V_87 ) ;
for ( V_19 = 0 ; V_19 < 6 ; V_19 ++ ) {
struct V_75 * V_4 = F_96 ( sizeof( * V_4 ) , V_55 ) ;
if ( ! V_4 )
return - V_91 ;
F_97 ( & V_4 -> V_84 , & V_14 -> V_83 ) ;
}
return 0 ;
}
int F_98 ( struct V_1 * V_2 )
{
struct V_92 * V_69 = F_99 ( F_40 ,
V_2 , L_1 ) ;
if ( F_100 ( V_69 ) )
return F_101 ( V_69 ) ;
V_2 -> V_63 = V_69 ;
return 0 ;
}
int F_102 ( struct V_1 * V_2 )
{
#if 0
ca->watermark[WATERMARK_PRIO] = 0;
ca->watermark[WATERMARK_METADATA] = prio_buckets(ca);
ca->watermark[WATERMARK_MOVINGGC] = 8 +
ca->watermark[WATERMARK_METADATA];
ca->watermark[WATERMARK_NONE] = ca->free.size / 2 +
ca->watermark[WATERMARK_MOVINGGC];
#endif
return 0 ;
}
