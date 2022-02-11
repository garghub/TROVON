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
F_6 ( V_4 ) ;
F_7 ( V_4 ) ;
V_2 -> V_5 = NULL ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_9 , T_2 V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_11 , V_12 , V_13 ;
if ( ! V_4 )
return - V_14 ;
V_11 = F_9 ( V_2 -> V_15 -> V_16 ) ;
V_12 = F_10 (unsigned long, 1 , base >> order) ;
V_13 = ( V_9 + V_10 - 1 ) >> V_11 ;
if ( V_2 -> V_17 . V_18 ) {
if ( V_9 > V_2 -> V_17 . V_19 ||
V_9 + V_10 <= V_2 -> V_17 . V_20 ) {
F_11 ( L_1 ) ;
return - V_21 ;
}
V_12 = F_10 (unsigned long, base_pfn,
domain->geometry.aperture_start >> order) ;
V_13 = F_12 (unsigned long, end_pfn,
domain->geometry.aperture_end >> order) ;
}
if ( V_4 -> V_22 ) {
if ( 1UL << V_11 != V_4 -> V_23 ||
V_12 != V_4 -> V_22 ||
V_13 < V_4 -> V_24 ) {
F_11 ( L_2 ) ;
return - V_21 ;
}
V_4 -> V_24 = V_13 ;
} else {
F_13 ( V_4 , 1UL << V_11 , V_12 , V_13 ) ;
}
return 0 ;
}
int F_14 ( enum V_25 V_26 , bool V_27 )
{
int V_28 = V_27 ? V_29 : 0 ;
switch ( V_26 ) {
case V_30 :
return V_28 | V_31 | V_32 ;
case V_33 :
return V_28 | V_31 ;
case V_34 :
return V_28 | V_32 ;
default:
return 0 ;
}
}
static struct V_35 * F_15 ( struct V_3 * V_4 , T_3 V_10 ,
T_1 V_36 )
{
unsigned long V_37 = F_16 ( V_4 ) ;
unsigned long V_38 = F_17 ( V_4 , V_10 ) >> V_37 ;
return F_18 ( V_4 , V_38 , V_36 >> V_37 , true ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_37 = F_16 ( V_4 ) ;
unsigned long V_40 = V_39 >> V_37 ;
struct V_35 * V_35 = F_20 ( V_4 , V_40 ) ;
T_3 V_10 ;
if ( F_21 ( ! V_35 ) )
return;
V_10 = F_22 ( V_35 ) << V_37 ;
V_10 -= F_23 ( V_2 , V_40 << V_37 , V_10 ) ;
F_21 ( V_10 > 0 ) ;
F_24 ( V_4 , V_35 ) ;
}
static void F_25 ( struct V_41 * * V_42 , int V_43 )
{
while ( V_43 -- )
F_26 ( V_42 [ V_43 ] ) ;
F_27 ( V_42 ) ;
}
static struct V_41 * * F_28 ( unsigned int V_43 , T_4 V_44 )
{
struct V_41 * * V_42 ;
unsigned int V_45 = 0 , V_46 = V_43 * sizeof( * V_42 ) ;
unsigned int V_11 = V_47 ;
if ( V_46 <= V_48 )
V_42 = F_4 ( V_46 , V_7 ) ;
else
V_42 = F_29 ( V_46 ) ;
if ( ! V_42 )
return NULL ;
V_44 |= V_49 | V_50 ;
while ( V_43 ) {
struct V_41 * V_41 = NULL ;
int V_51 ;
for ( V_11 = F_12 (unsigned int, order, __fls(count)) ;
V_11 > 0 ; V_11 -- ) {
V_41 = F_30 ( V_44 | V_52 , V_11 ) ;
if ( ! V_41 )
continue;
if ( F_31 ( V_41 ) ) {
if ( ! F_32 ( V_41 ) )
break;
F_33 ( V_41 , V_11 ) ;
} else {
F_34 ( V_41 , V_11 ) ;
break;
}
}
if ( ! V_41 )
V_41 = F_35 ( V_44 ) ;
if ( ! V_41 ) {
F_25 ( V_42 , V_45 ) ;
return NULL ;
}
V_51 = 1 << V_11 ;
V_43 -= V_51 ;
while ( V_51 -- )
V_42 [ V_45 ++ ] = V_41 ++ ;
}
return V_42 ;
}
void F_36 ( struct V_53 * V_54 , struct V_41 * * V_42 , T_3 V_10 ,
T_1 * V_55 )
{
F_19 ( F_37 ( V_54 ) , * V_55 ) ;
F_25 ( V_42 , F_38 ( V_10 ) >> V_56 ) ;
* V_55 = V_57 ;
}
struct V_41 * * F_39 ( struct V_53 * V_54 , T_3 V_10 ,
T_4 V_44 , int V_28 , T_1 * V_55 ,
void (* F_40)( struct V_53 * , const void * , T_5 ) )
{
struct V_1 * V_2 = F_37 ( V_54 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_35 ;
struct V_41 * * V_42 ;
struct V_58 V_59 ;
T_1 V_39 ;
unsigned int V_43 = F_38 ( V_10 ) >> V_56 ;
* V_55 = V_57 ;
V_42 = F_28 ( V_43 , V_44 ) ;
if ( ! V_42 )
return NULL ;
V_35 = F_15 ( V_4 , V_10 , V_54 -> V_60 ) ;
if ( ! V_35 )
goto V_61;
V_10 = F_17 ( V_4 , V_10 ) ;
if ( F_41 ( & V_59 , V_42 , V_43 , 0 , V_10 , V_7 ) )
goto V_62;
if ( ! ( V_28 & V_29 ) ) {
struct V_63 V_64 ;
F_42 ( & V_64 , V_59 . V_65 , V_59 . V_66 , V_67 ) ;
while ( F_43 ( & V_64 ) )
F_40 ( V_54 , V_64 . V_68 , F_44 ( V_64 . V_41 ) ) ;
F_45 ( & V_64 ) ;
}
V_39 = F_46 ( V_4 , V_35 ) ;
if ( F_47 ( V_2 , V_39 , V_59 . V_65 , V_59 . V_66 , V_28 )
< V_10 )
goto V_69;
* V_55 = V_39 ;
F_48 ( & V_59 ) ;
return V_42 ;
V_69:
F_48 ( & V_59 ) ;
V_62:
F_24 ( V_4 , V_35 ) ;
V_61:
F_25 ( V_42 , V_43 ) ;
return NULL ;
}
int F_49 ( struct V_41 * * V_42 , T_3 V_10 , struct V_70 * V_71 )
{
unsigned long V_72 = V_71 -> V_73 ;
unsigned int V_45 , V_43 = F_38 ( V_10 ) >> V_56 ;
int V_74 = - V_75 ;
for ( V_45 = V_71 -> V_76 ; V_45 < V_43 && V_72 < V_71 -> V_77 ; V_45 ++ ) {
V_74 = F_50 ( V_71 , V_72 , V_42 [ V_45 ] ) ;
if ( V_74 )
break;
V_72 += V_48 ;
}
return V_74 ;
}
T_1 F_51 ( struct V_53 * V_54 , struct V_41 * V_41 ,
unsigned long V_78 , T_3 V_10 , int V_28 )
{
T_1 V_39 ;
struct V_1 * V_2 = F_37 ( V_54 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_5 V_79 = F_44 ( V_41 ) + V_78 ;
T_3 V_80 = F_52 ( V_4 , V_79 ) ;
T_3 V_81 = F_17 ( V_4 , V_10 + V_80 ) ;
struct V_35 * V_35 = F_15 ( V_4 , V_81 , F_53 ( V_54 ) ) ;
if ( ! V_35 )
return V_57 ;
V_39 = F_46 ( V_4 , V_35 ) ;
if ( F_54 ( V_2 , V_39 , V_79 - V_80 , V_81 , V_28 ) ) {
F_24 ( V_4 , V_35 ) ;
return V_57 ;
}
return V_39 + V_80 ;
}
void F_55 ( struct V_53 * V_54 , T_1 V_55 , T_3 V_10 ,
enum V_25 V_26 , struct V_82 * V_83 )
{
F_19 ( F_37 ( V_54 ) , V_55 ) ;
}
static int F_56 ( struct V_53 * V_54 , struct V_84 * V_85 , int V_86 ,
T_1 V_39 )
{
struct V_84 * V_87 ;
int V_45 ;
F_57 (sg, s, nents, i) {
unsigned int V_88 = F_58 ( V_87 ) ;
unsigned int V_89 = F_59 ( V_87 ) ;
unsigned int V_90 = V_87 -> V_38 ;
V_87 -> V_78 = V_88 ;
V_87 -> V_38 = V_89 ;
F_58 ( V_87 ) = V_39 + V_88 ;
V_39 += V_90 ;
}
return V_45 ;
}
static void F_60 ( struct V_84 * V_85 , int V_86 )
{
struct V_84 * V_87 ;
int V_45 ;
F_57 (sg, s, nents, i) {
if ( F_58 ( V_87 ) != V_57 )
V_87 -> V_78 = F_58 ( V_87 ) ;
if ( F_59 ( V_87 ) )
V_87 -> V_38 = F_59 ( V_87 ) ;
F_58 ( V_87 ) = V_57 ;
F_59 ( V_87 ) = 0 ;
}
}
int F_61 ( struct V_53 * V_54 , struct V_84 * V_85 ,
int V_86 , int V_28 )
{
struct V_1 * V_2 = F_37 ( V_54 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_35 ;
struct V_84 * V_87 , * V_91 = NULL ;
T_1 V_39 ;
T_3 V_92 = 0 ;
int V_45 ;
F_57 (sg, s, nents, i) {
T_3 V_88 = F_52 ( V_4 , V_87 -> V_78 ) ;
T_3 V_89 = V_87 -> V_38 ;
F_58 ( V_87 ) = V_88 ;
F_59 ( V_87 ) = V_89 ;
V_87 -> V_78 -= V_88 ;
V_89 = F_17 ( V_4 , V_89 + V_88 ) ;
V_87 -> V_38 = V_89 ;
if ( V_91 ) {
T_3 V_93 = F_62 ( V_89 ) ;
V_93 = ( V_93 - V_92 ) & ( V_93 - 1 ) ;
V_91 -> V_38 += V_93 ;
V_92 += V_93 ;
}
V_92 += V_89 ;
V_91 = V_87 ;
}
V_35 = F_15 ( V_4 , V_92 , F_53 ( V_54 ) ) ;
if ( ! V_35 )
goto V_94;
V_39 = F_46 ( V_4 , V_35 ) ;
if ( F_47 ( V_2 , V_39 , V_85 , V_86 , V_28 ) < V_92 )
goto V_62;
return F_56 ( V_54 , V_85 , V_86 , V_39 ) ;
V_62:
F_24 ( V_4 , V_35 ) ;
V_94:
F_60 ( V_85 , V_86 ) ;
return 0 ;
}
void F_63 ( struct V_53 * V_54 , struct V_84 * V_85 , int V_86 ,
enum V_25 V_26 , struct V_82 * V_83 )
{
F_19 ( F_37 ( V_54 ) , F_58 ( V_85 ) ) ;
}
int F_64 ( struct V_53 * V_54 , T_2 V_95 )
{
return 1 ;
}
int F_65 ( struct V_53 * V_54 , T_1 V_39 )
{
return V_39 == V_57 ;
}
