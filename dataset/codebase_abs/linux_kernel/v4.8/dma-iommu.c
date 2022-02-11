int F_1 ( void )
{
return F_2 () ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_5 )
return - V_6 ;
V_4 = F_4 ( sizeof( * V_4 ) , V_7 ) ;
V_2 -> V_5 = V_4 ;
return V_4 ? 0 : - V_8 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 )
return;
if ( V_4 -> V_9 )
F_6 ( V_4 ) ;
F_7 ( V_4 ) ;
V_2 -> V_5 = NULL ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_10 , T_2 V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_12 , V_13 , V_14 ;
if ( ! V_4 )
return - V_15 ;
V_12 = F_9 ( V_2 -> V_16 ) ;
V_13 = F_10 (unsigned long, 1 , base >> order) ;
V_14 = ( V_10 + V_11 - 1 ) >> V_12 ;
if ( V_2 -> V_17 . V_18 ) {
if ( V_10 > V_2 -> V_17 . V_19 ||
V_10 + V_11 <= V_2 -> V_17 . V_20 ) {
F_11 ( L_1 ) ;
return - V_21 ;
}
V_13 = F_10 (unsigned long, base_pfn,
domain->geometry.aperture_start >> order) ;
V_14 = F_12 (unsigned long, end_pfn,
domain->geometry.aperture_end >> order) ;
}
if ( V_4 -> V_22 ) {
if ( 1UL << V_12 != V_4 -> V_9 ||
V_13 != V_4 -> V_22 ||
V_14 < V_4 -> V_23 ) {
F_11 ( L_2 ) ;
return - V_21 ;
}
V_4 -> V_23 = V_14 ;
} else {
F_13 ( V_4 , 1UL << V_12 , V_13 , V_14 ) ;
}
return 0 ;
}
int F_14 ( enum V_24 V_25 , bool V_26 )
{
int V_27 = V_26 ? V_28 : 0 ;
switch ( V_25 ) {
case V_29 :
return V_27 | V_30 | V_31 ;
case V_32 :
return V_27 | V_30 ;
case V_33 :
return V_27 | V_31 ;
default:
return 0 ;
}
}
static struct V_34 * F_15 ( struct V_1 * V_2 , T_3 V_11 ,
T_1 V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_36 = F_16 ( V_4 ) ;
unsigned long V_37 = F_17 ( V_4 , V_11 ) >> V_36 ;
if ( V_2 -> V_17 . V_18 )
V_35 = F_18 ( V_35 , V_2 -> V_17 . V_19 ) ;
return F_19 ( V_4 , V_37 , V_35 >> V_36 , true ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_38 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_36 = F_16 ( V_4 ) ;
unsigned long V_39 = V_38 >> V_36 ;
struct V_34 * V_34 = F_21 ( V_4 , V_39 ) ;
T_3 V_11 ;
if ( F_22 ( ! V_34 ) )
return;
V_11 = F_23 ( V_34 ) << V_36 ;
V_11 -= F_24 ( V_2 , V_39 << V_36 , V_11 ) ;
F_22 ( V_11 > 0 ) ;
F_25 ( V_4 , V_34 ) ;
}
static void F_26 ( struct V_40 * * V_41 , int V_42 )
{
while ( V_42 -- )
F_27 ( V_41 [ V_42 ] ) ;
F_28 ( V_41 ) ;
}
static struct V_40 * * F_29 ( unsigned int V_42 ,
unsigned long V_43 , T_4 V_44 )
{
struct V_40 * * V_41 ;
unsigned int V_45 = 0 , V_46 = V_42 * sizeof( * V_41 ) ;
V_43 &= ( 2U << V_47 ) - 1 ;
if ( ! V_43 )
return NULL ;
if ( V_46 <= V_48 )
V_41 = F_4 ( V_46 , V_7 ) ;
else
V_41 = F_30 ( V_46 ) ;
if ( ! V_41 )
return NULL ;
V_44 |= V_49 | V_50 ;
while ( V_42 ) {
struct V_40 * V_40 = NULL ;
unsigned int V_51 ;
for ( V_43 &= ( 2U << F_31 ( V_42 ) ) - 1 ;
V_43 ; V_43 &= ~ V_51 ) {
unsigned int V_12 = F_31 ( V_43 ) ;
V_51 = 1U << V_12 ;
V_40 = F_32 ( ( V_43 - V_51 ) ?
V_44 | V_52 : V_44 , V_12 ) ;
if ( ! V_40 )
continue;
if ( ! V_12 )
break;
if ( ! F_33 ( V_40 ) ) {
F_34 ( V_40 , V_12 ) ;
break;
} else if ( ! F_35 ( V_40 ) ) {
break;
}
F_36 ( V_40 , V_12 ) ;
}
if ( ! V_40 ) {
F_26 ( V_41 , V_45 ) ;
return NULL ;
}
V_42 -= V_51 ;
while ( V_51 -- )
V_41 [ V_45 ++ ] = V_40 ++ ;
}
return V_41 ;
}
void F_37 ( struct V_53 * V_54 , struct V_40 * * V_41 , T_3 V_11 ,
T_1 * V_55 )
{
F_20 ( F_38 ( V_54 ) , * V_55 ) ;
F_26 ( V_41 , F_39 ( V_11 ) >> V_56 ) ;
* V_55 = V_57 ;
}
struct V_40 * * F_40 ( struct V_53 * V_54 , T_3 V_11 , T_4 V_44 ,
unsigned long V_58 , int V_27 , T_1 * V_55 ,
void (* F_41)( struct V_53 * , const void * , T_5 ) )
{
struct V_1 * V_2 = F_38 ( V_54 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_34 * V_34 ;
struct V_40 * * V_41 ;
struct V_59 V_60 ;
T_1 V_38 ;
unsigned int V_42 , V_61 , V_62 = V_2 -> V_16 ;
* V_55 = V_57 ;
V_61 = V_62 & - V_62 ;
if ( V_61 < V_48 ) {
V_61 = V_48 ;
V_62 |= V_48 ;
} else {
V_11 = F_42 ( V_11 , V_61 ) ;
}
if ( V_58 & V_63 )
V_62 = V_61 ;
V_42 = F_39 ( V_11 ) >> V_56 ;
V_41 = F_29 ( V_42 , V_62 >> V_56 , V_44 ) ;
if ( ! V_41 )
return NULL ;
V_34 = F_15 ( V_2 , V_11 , V_54 -> V_64 ) ;
if ( ! V_34 )
goto V_65;
V_11 = F_17 ( V_4 , V_11 ) ;
if ( F_43 ( & V_60 , V_41 , V_42 , 0 , V_11 , V_7 ) )
goto V_66;
if ( ! ( V_27 & V_28 ) ) {
struct V_67 V_68 ;
F_44 ( & V_68 , V_60 . V_69 , V_60 . V_70 , V_71 ) ;
while ( F_45 ( & V_68 ) )
F_41 ( V_54 , V_68 . V_72 , F_46 ( V_68 . V_40 ) ) ;
F_47 ( & V_68 ) ;
}
V_38 = F_48 ( V_4 , V_34 ) ;
if ( F_49 ( V_2 , V_38 , V_60 . V_69 , V_60 . V_70 , V_27 )
< V_11 )
goto V_73;
* V_55 = V_38 ;
F_50 ( & V_60 ) ;
return V_41 ;
V_73:
F_50 ( & V_60 ) ;
V_66:
F_25 ( V_4 , V_34 ) ;
V_65:
F_26 ( V_41 , V_42 ) ;
return NULL ;
}
int F_51 ( struct V_40 * * V_41 , T_3 V_11 , struct V_74 * V_75 )
{
unsigned long V_76 = V_75 -> V_77 ;
unsigned int V_45 , V_42 = F_39 ( V_11 ) >> V_56 ;
int V_78 = - V_79 ;
for ( V_45 = V_75 -> V_80 ; V_45 < V_42 && V_76 < V_75 -> V_81 ; V_45 ++ ) {
V_78 = F_52 ( V_75 , V_76 , V_41 [ V_45 ] ) ;
if ( V_78 )
break;
V_76 += V_48 ;
}
return V_78 ;
}
T_1 F_53 ( struct V_53 * V_54 , struct V_40 * V_40 ,
unsigned long V_82 , T_3 V_11 , int V_27 )
{
T_1 V_38 ;
struct V_1 * V_2 = F_38 ( V_54 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_83 = F_46 ( V_40 ) + V_82 ;
T_3 V_84 = F_54 ( V_4 , V_83 ) ;
T_3 V_85 = F_17 ( V_4 , V_11 + V_84 ) ;
struct V_34 * V_34 = F_15 ( V_2 , V_85 , F_55 ( V_54 ) ) ;
if ( ! V_34 )
return V_57 ;
V_38 = F_48 ( V_4 , V_34 ) ;
if ( F_56 ( V_2 , V_38 , V_83 - V_84 , V_85 , V_27 ) ) {
F_25 ( V_4 , V_34 ) ;
return V_57 ;
}
return V_38 + V_84 ;
}
void F_57 ( struct V_53 * V_54 , T_1 V_55 , T_3 V_11 ,
enum V_24 V_25 , unsigned long V_58 )
{
F_20 ( F_38 ( V_54 ) , V_55 ) ;
}
static int F_58 ( struct V_53 * V_54 , struct V_86 * V_87 , int V_88 ,
T_1 V_38 )
{
struct V_86 * V_89 , * V_90 = V_87 ;
unsigned long V_91 = F_59 ( V_54 ) ;
unsigned int V_92 = 0 , V_93 = F_60 ( V_54 ) ;
int V_45 , V_42 = 0 ;
F_61 (sg, s, nents, i) {
unsigned int V_94 = F_62 ( V_89 ) ;
unsigned int V_95 = F_63 ( V_89 ) ;
unsigned int V_96 = V_89 -> V_37 ;
V_89 -> V_82 += V_94 ;
V_89 -> V_37 = V_95 ;
F_62 ( V_89 ) = V_57 ;
F_63 ( V_89 ) = 0 ;
if ( V_92 && ! V_94 && ( V_38 & V_91 ) &&
( V_92 + V_95 <= V_93 ) ) {
V_92 += V_95 ;
} else {
if ( V_45 > 0 )
V_90 = F_64 ( V_90 ) ;
V_92 = V_95 ;
V_42 ++ ;
F_62 ( V_90 ) = V_38 + V_94 ;
}
F_63 ( V_90 ) = V_92 ;
V_38 += V_96 ;
if ( V_95 + V_94 < V_96 )
V_92 = 0 ;
}
return V_42 ;
}
static void F_65 ( struct V_86 * V_87 , int V_88 )
{
struct V_86 * V_89 ;
int V_45 ;
F_61 (sg, s, nents, i) {
if ( F_62 ( V_89 ) != V_57 )
V_89 -> V_82 += F_62 ( V_89 ) ;
if ( F_63 ( V_89 ) )
V_89 -> V_37 = F_63 ( V_89 ) ;
F_62 ( V_89 ) = V_57 ;
F_63 ( V_89 ) = 0 ;
}
}
int F_66 ( struct V_53 * V_54 , struct V_86 * V_87 ,
int V_88 , int V_27 )
{
struct V_1 * V_2 = F_38 ( V_54 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_34 * V_34 ;
struct V_86 * V_89 , * V_97 = NULL ;
T_1 V_38 ;
T_3 V_98 = 0 ;
unsigned long V_99 = F_59 ( V_54 ) ;
int V_45 ;
F_61 (sg, s, nents, i) {
T_3 V_94 = F_54 ( V_4 , V_89 -> V_82 ) ;
T_3 V_95 = V_89 -> V_37 ;
T_3 V_100 = ( V_99 - V_98 + 1 ) & V_99 ;
F_62 ( V_89 ) = V_94 ;
F_63 ( V_89 ) = V_95 ;
V_89 -> V_82 -= V_94 ;
V_95 = F_17 ( V_4 , V_95 + V_94 ) ;
V_89 -> V_37 = V_95 ;
if ( V_100 && V_100 < V_95 - 1 ) {
V_97 -> V_37 += V_100 ;
V_98 += V_100 ;
}
V_98 += V_95 ;
V_97 = V_89 ;
}
V_34 = F_15 ( V_2 , V_98 , F_55 ( V_54 ) ) ;
if ( ! V_34 )
goto V_101;
V_38 = F_48 ( V_4 , V_34 ) ;
if ( F_49 ( V_2 , V_38 , V_87 , V_88 , V_27 ) < V_98 )
goto V_66;
return F_58 ( V_54 , V_87 , V_88 , V_38 ) ;
V_66:
F_25 ( V_4 , V_34 ) ;
V_101:
F_65 ( V_87 , V_88 ) ;
return 0 ;
}
void F_67 ( struct V_53 * V_54 , struct V_86 * V_87 , int V_88 ,
enum V_24 V_25 , unsigned long V_58 )
{
F_20 ( F_38 ( V_54 ) , F_62 ( V_87 ) ) ;
}
int F_68 ( struct V_53 * V_54 , T_2 V_99 )
{
return 1 ;
}
int F_69 ( struct V_53 * V_54 , T_1 V_38 )
{
return V_38 == V_57 ;
}
