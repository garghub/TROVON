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
static void F_16 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_17 ( V_29 , struct V_30 , V_32 ) ;
struct V_1 * V_2 = V_31 -> V_2 ;
char V_33 [ V_34 ] ;
if ( ! F_18 ( V_35 , & V_31 -> V_36 . V_37 ) ) {
F_19 ( L_1 ,
F_20 ( V_2 -> V_38 , V_33 ) ) ;
V_31 -> V_2 -> V_30 = 0 ;
}
F_11 ( & V_2 -> V_7 -> V_22 ) ;
F_21 ( & V_2 -> free , V_31 -> V_3 ) ;
F_22 ( & V_31 -> V_39 , & V_2 -> V_40 ) ;
F_23 ( & V_2 -> V_41 ) ;
F_15 ( & V_2 -> V_7 -> V_22 ) ;
F_24 ( & V_2 -> V_7 -> V_42 ) ;
F_25 ( & V_2 -> V_7 -> V_43 ) ;
F_26 ( & V_2 -> V_7 -> V_44 ) ;
}
static void F_27 ( struct V_36 * V_36 , int error )
{
struct V_30 * V_31 = F_17 ( V_36 , struct V_30 , V_36 ) ;
F_28 ( & V_31 -> V_32 ) ;
}
static void F_29 ( struct V_1 * V_2 , long V_3 )
{
struct V_30 * V_31 = F_30 ( & V_2 -> V_40 ,
struct V_30 , V_39 ) ;
F_31 ( & V_31 -> V_39 ) ;
V_31 -> V_3 = V_3 ;
F_32 ( & V_2 -> V_41 ) ;
F_33 ( & V_2 -> V_7 -> V_44 ) ;
F_34 ( & V_31 -> V_36 ) ;
V_31 -> V_36 . V_45 = F_35 ( V_2 -> V_7 , V_31 -> V_3 ) ;
V_31 -> V_36 . V_46 = V_2 -> V_38 ;
V_31 -> V_36 . V_47 = V_48 | V_49 ;
V_31 -> V_36 . V_50 = 1 ;
V_31 -> V_36 . V_51 = V_31 -> V_36 . V_52 ;
V_31 -> V_36 . V_53 = F_36 ( V_2 ) ;
V_31 -> V_36 . V_54 = F_27 ;
F_37 ( & V_31 -> V_36 , F_38 ( V_55 , 0 ) ) ;
F_39 ( 0 , & V_31 -> V_36 ) ;
}
static inline bool F_40 ( struct V_3 * V_4 )
{
return F_3 ( V_4 ) < V_9 &&
F_6 ( V_4 ) < V_12 ;
}
bool F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_42 ( F_43 ( V_4 ) || F_44 ( V_4 ) ) ;
if ( F_45 ( & V_2 -> free ) > V_2 -> V_56 [ V_57 ] &&
F_46 ( & V_2 -> V_10 ) == V_58 )
return false ;
V_4 -> V_25 = 0 ;
if ( F_40 ( V_4 ) &&
F_21 ( & V_2 -> V_59 , V_4 - V_2 -> V_60 ) ) {
F_32 ( & V_4 -> V_27 ) ;
return true ;
}
return false ;
}
static bool F_47 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_43 ( V_4 ) == V_61 &&
! F_9 ( & V_4 -> V_27 ) &&
F_40 ( V_4 ) ;
}
static void F_48 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
V_4 -> V_25 = V_62 ;
F_32 ( & V_4 -> V_27 ) ;
F_21 ( & V_2 -> V_63 , V_4 - V_2 -> V_60 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_2 V_19 ;
V_2 -> V_64 . V_65 = 0 ;
F_13 (b, ca) {
if ( F_50 ( & V_2 -> V_59 ) )
return;
if ( ! F_47 ( V_2 , V_4 ) )
continue;
if ( ! F_44 ( V_4 ) &&
F_41 ( V_2 , V_4 ) )
continue;
if ( ! F_51 ( & V_2 -> V_64 ) )
F_52 ( & V_2 -> V_64 , V_4 , V_66 ) ;
else if ( V_66 ( V_4 , F_53 ( & V_2 -> V_64 ) ) ) {
V_2 -> V_64 . V_67 [ 0 ] = V_4 ;
F_54 ( & V_2 -> V_64 , 0 , V_66 ) ;
}
}
for ( V_19 = V_2 -> V_64 . V_65 / 2 - 1 ; V_19 >= 0 ; -- V_19 )
F_54 ( & V_2 -> V_64 , V_19 , V_68 ) ;
while ( ! F_50 ( & V_2 -> V_63 ) ) {
if ( ! F_55 ( & V_2 -> V_64 , V_4 , V_68 ) ) {
V_2 -> V_69 = 1 ;
F_56 ( V_2 -> V_7 ) ;
return;
}
F_48 ( V_2 , V_4 ) ;
}
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_3 V_70 = 0 ;
while ( ! F_50 ( & V_2 -> V_63 ) ) {
if ( V_2 -> V_71 < V_2 -> V_10 . V_72 ||
V_2 -> V_71 >= V_2 -> V_10 . V_17 )
V_2 -> V_71 = V_2 -> V_10 . V_72 ;
V_4 = V_2 -> V_60 + V_2 -> V_71 ++ ;
if ( F_47 ( V_2 , V_4 ) )
F_48 ( V_2 , V_4 ) ;
if ( ++ V_70 >= V_2 -> V_10 . V_17 ) {
V_2 -> V_69 = 1 ;
F_56 ( V_2 -> V_7 ) ;
return;
}
}
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_3 V_70 = 0 ;
while ( ! F_50 ( & V_2 -> V_63 ) ) {
T_3 V_73 ;
F_59 ( & V_73 , sizeof( V_73 ) ) ;
V_73 %= ( T_3 ) ( V_2 -> V_10 . V_17 - V_2 -> V_10 . V_72 ) ;
V_73 += V_2 -> V_10 . V_72 ;
V_4 = V_2 -> V_60 + V_73 ;
if ( F_47 ( V_2 , V_4 ) )
F_48 ( V_2 , V_4 ) ;
if ( ++ V_70 >= V_2 -> V_10 . V_17 / 2 ) {
V_2 -> V_69 = 1 ;
F_56 ( V_2 -> V_7 ) ;
return;
}
}
}
static void F_60 ( struct V_1 * V_2 )
{
if ( V_2 -> V_69 )
return;
switch ( F_46 ( & V_2 -> V_10 ) ) {
case V_74 :
F_49 ( V_2 ) ;
break;
case V_58 :
F_57 ( V_2 ) ;
break;
case V_75 :
F_58 ( V_2 ) ;
break;
}
F_61 ( L_2 ,
F_45 ( & V_2 -> free ) , V_2 -> free . V_76 ,
F_45 ( & V_2 -> V_63 ) , V_2 -> V_63 . V_76 ,
F_45 ( & V_2 -> V_59 ) , V_2 -> V_59 . V_76 ) ;
}
void F_62 ( struct V_77 * V_44 )
{
struct V_1 * V_2 = F_17 ( V_44 , struct V_1 , V_78 ) ;
F_11 ( & V_2 -> V_7 -> V_22 ) ;
while ( 1 ) {
while ( 1 ) {
long V_3 ;
if ( ( ! F_9 ( & V_2 -> V_7 -> V_79 ) ||
! F_5 ( & V_2 -> V_7 -> V_10 ) ) &&
! F_63 ( & V_2 -> V_59 ) )
F_64 ( & V_2 -> V_59 , V_3 ) ;
else if ( ! F_63 ( & V_2 -> V_63 ) )
F_64 ( & V_2 -> V_63 , V_3 ) ;
else
break;
F_65 ( V_2 , ( int ) F_66 ( & V_2 -> free ) >
F_9 ( & V_2 -> V_41 ) ) ;
if ( V_2 -> V_30 ) {
F_65 ( V_2 , ! F_67 ( & V_2 -> V_40 ) ) ;
F_29 ( V_2 , V_3 ) ;
} else {
F_21 ( & V_2 -> free , V_3 ) ;
F_24 ( & V_2 -> V_7 -> V_42 ) ;
}
}
F_65 ( V_2 , V_2 -> V_7 -> V_80 &&
( V_2 -> V_11 > 64 ||
! V_2 -> V_69 ) ) ;
F_60 ( V_2 ) ;
F_65 ( V_2 , ! F_9 ( & V_2 -> V_7 -> V_79 ) ) ;
if ( F_5 ( & V_2 -> V_7 -> V_10 ) &&
( ! F_63 ( & V_2 -> V_63 ) ||
V_2 -> V_11 > 64 ) )
F_68 ( V_2 ) ;
}
}
long F_69 ( struct V_1 * V_2 , unsigned V_56 , struct V_77 * V_44 )
{
long V_20 = - 1 ;
V_81:
F_25 ( & V_2 -> V_7 -> V_43 ) ;
if ( F_45 ( & V_2 -> free ) > V_2 -> V_56 [ V_56 ] &&
F_64 ( & V_2 -> free , V_20 ) ) {
struct V_3 * V_4 = V_2 -> V_60 + V_20 ;
#ifdef F_70
T_3 V_82 ;
long V_19 ;
for ( V_82 = 0 ; V_82 < F_71 ( V_2 ) * 2 ; V_82 ++ )
F_42 ( V_2 -> F_71 [ V_82 ] == ( V_83 ) V_20 ) ;
F_72 (i, &ca->free, iter)
F_42 ( V_19 == V_20 ) ;
F_72 (i, &ca->free_inc, iter)
F_42 ( V_19 == V_20 ) ;
F_72 (i, &ca->unused, iter)
F_42 ( V_19 == V_20 ) ;
#endif
F_42 ( F_9 ( & V_4 -> V_27 ) != 1 ) ;
F_73 ( V_4 , V_2 -> V_10 . V_18 ) ;
if ( V_56 <= V_84 ) {
F_74 ( V_4 , V_85 ) ;
V_4 -> V_25 = V_26 ;
} else {
F_74 ( V_4 , V_61 ) ;
V_4 -> V_25 = V_62 ;
}
return V_20 ;
}
F_61 ( L_3 ,
F_9 ( & V_2 -> V_7 -> V_79 ) , F_45 ( & V_2 -> free ) ,
F_45 ( & V_2 -> V_63 ) , F_45 ( & V_2 -> V_59 ) ) ;
if ( V_44 ) {
F_75 ( & V_2 -> V_7 -> V_42 , V_44 ) ;
if ( F_76 ( V_44 ) ) {
F_15 ( & V_2 -> V_7 -> V_22 ) ;
F_77 ( V_44 ) ;
F_11 ( & V_2 -> V_7 -> V_22 ) ;
goto V_81;
}
}
return - 1 ;
}
void F_78 ( struct V_13 * V_14 , struct V_86 * V_87 )
{
unsigned V_19 ;
for ( V_19 = 0 ; V_19 < F_79 ( V_87 ) ; V_19 ++ ) {
struct V_3 * V_4 = F_80 ( V_14 , V_87 , V_19 ) ;
F_74 ( V_4 , V_61 ) ;
F_73 ( V_4 , 0 ) ;
F_41 ( F_81 ( V_14 , V_87 , V_19 ) , V_4 ) ;
}
}
int F_82 ( struct V_13 * V_14 , unsigned V_56 ,
struct V_86 * V_87 , int V_73 , struct V_77 * V_44 )
{
int V_19 ;
F_83 ( & V_14 -> V_22 ) ;
F_42 ( ! V_73 || V_73 > V_14 -> V_88 || V_73 > 8 ) ;
F_84 ( V_87 ) ;
for ( V_19 = 0 ; V_19 < V_73 ; V_19 ++ ) {
struct V_1 * V_2 = V_14 -> V_89 [ V_19 ] ;
long V_4 = F_69 ( V_2 , V_56 , V_44 ) ;
if ( V_4 == - 1 )
goto V_90;
V_87 -> V_91 [ V_19 ] = F_85 ( V_2 -> V_60 [ V_4 ] . V_6 ,
F_35 ( V_14 , V_4 ) ,
V_2 -> V_10 . V_92 ) ;
F_86 ( V_87 , V_19 + 1 ) ;
}
return 0 ;
V_90:
F_78 ( V_14 , V_87 ) ;
F_87 ( V_14 , V_87 ) ;
return - 1 ;
}
int F_88 ( struct V_13 * V_14 , unsigned V_56 ,
struct V_86 * V_87 , int V_73 , struct V_77 * V_44 )
{
int V_5 ;
F_11 ( & V_14 -> V_22 ) ;
V_5 = F_82 ( V_14 , V_56 , V_87 , V_73 , V_44 ) ;
F_15 ( & V_14 -> V_22 ) ;
return V_5 ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
while ( ! F_67 ( & V_2 -> V_40 ) ) {
V_31 = F_30 ( & V_2 -> V_40 , struct V_30 , V_39 ) ;
F_90 ( & V_31 -> V_32 ) ;
F_31 ( & V_31 -> V_39 ) ;
F_91 ( V_31 ) ;
}
}
int F_92 ( struct V_1 * V_2 )
{
unsigned V_19 ;
V_2 -> V_56 [ V_93 ] = 0 ;
V_2 -> V_56 [ V_84 ] = F_71 ( V_2 ) ;
V_2 -> V_56 [ V_57 ] = 8 +
V_2 -> V_56 [ V_84 ] ;
V_2 -> V_56 [ V_94 ] = V_2 -> free . V_76 / 2 +
V_2 -> V_56 [ V_57 ] ;
for ( V_19 = 0 ; V_19 < V_95 ; V_19 ++ ) {
struct V_30 * V_31 = F_93 ( sizeof( * V_31 ) , V_96 ) ;
if ( ! V_31 )
return - V_97 ;
V_31 -> V_2 = V_2 ;
F_94 ( & V_31 -> V_32 , F_16 ) ;
F_22 ( & V_31 -> V_39 , & V_2 -> V_40 ) ;
}
return 0 ;
}
