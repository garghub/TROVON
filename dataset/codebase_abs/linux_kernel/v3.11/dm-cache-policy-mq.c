static unsigned F_1 ( unsigned V_1 , unsigned V_2 )
{
return F_2 ( F_3 ( V_1 , V_2 ) ) ;
}
static unsigned long * F_4 ( unsigned V_3 )
{
T_1 V_4 = sizeof( unsigned long ) * F_5 ( V_3 , V_5 ) ;
return F_6 ( V_4 ) ;
}
static void F_7 ( unsigned long * V_6 )
{
F_8 ( V_6 ) ;
}
static void F_9 ( struct V_7 * V_8 ,
int V_9 , int V_10 )
{
V_8 -> V_11 = V_12 ;
V_8 -> V_13 = 0 ;
V_8 -> V_14 = 0 ;
V_8 -> V_15 = 0 ;
V_8 -> V_16 [ V_12 ] = V_10 ;
V_8 -> V_16 [ V_17 ] = V_9 ;
}
static enum V_18 F_10 ( struct V_7 * V_8 )
{
return V_8 -> V_11 ;
}
static void F_11 ( struct V_7 * V_8 , struct V_19 * V_19 )
{
if ( V_19 -> V_20 == F_12 ( V_8 -> V_15 ) + 1 )
V_8 -> V_13 ++ ;
else {
if ( V_8 -> V_13 ) {
V_8 -> V_13 = 0 ;
V_8 -> V_14 = 0 ;
}
V_8 -> V_14 ++ ;
}
V_8 -> V_15 = F_13 ( V_19 -> V_20 + F_14 ( V_19 ) - 1 ) ;
}
static void F_15 ( struct V_7 * V_8 )
{
switch ( V_8 -> V_11 ) {
case V_17 :
if ( V_8 -> V_14 >= V_8 -> V_16 [ V_12 ] ) {
V_8 -> V_11 = V_12 ;
V_8 -> V_13 = V_8 -> V_14 = 0 ;
}
break;
case V_12 :
if ( V_8 -> V_13 >= V_8 -> V_16 [ V_17 ] ) {
V_8 -> V_11 = V_17 ;
V_8 -> V_13 = V_8 -> V_14 = 0 ;
}
break;
}
}
static void F_16 ( struct V_7 * V_8 , struct V_19 * V_19 )
{
F_11 ( V_8 , V_19 ) ;
F_15 ( V_8 ) ;
}
static void F_17 ( struct V_21 * V_22 )
{
unsigned V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
F_18 ( V_22 -> V_25 + V_23 ) ;
}
static void F_19 ( struct V_21 * V_22 , unsigned V_26 , struct V_27 * V_28 )
{
F_20 ( V_28 , V_22 -> V_25 + V_26 ) ;
}
static void F_21 ( struct V_27 * V_28 )
{
F_22 ( V_28 ) ;
}
static void F_23 ( struct V_21 * V_22 )
{
unsigned V_26 ;
for ( V_26 = 1 ; V_26 < V_24 ; V_26 ++ )
F_24 ( V_22 -> V_25 + V_26 , V_22 -> V_25 + V_26 - 1 ) ;
}
static struct V_27 * F_25 ( struct V_21 * V_22 )
{
unsigned V_26 ;
struct V_27 * V_29 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
if ( ! F_26 ( V_22 -> V_25 + V_26 ) ) {
V_29 = V_22 -> V_25 [ V_26 ] . V_30 ;
F_22 ( V_29 ) ;
if ( V_26 == 0 && F_26 ( V_22 -> V_25 ) )
F_23 ( V_22 ) ;
return V_29 ;
}
return NULL ;
}
static struct V_27 * F_27 ( struct V_27 * V_31 )
{
struct V_27 * V_29 = V_31 -> V_30 ;
F_28 ( ! V_29 ) ;
F_29 ( V_29 ) ;
return V_29 ;
}
static void F_30 ( struct V_27 * V_31 , struct V_21 * V_22 )
{
unsigned V_26 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
F_31 ( V_22 -> V_25 + V_26 , V_31 ) ;
}
static void F_32 ( struct V_32 * V_33 )
{
struct V_34 * V_35 , * V_36 ;
F_30 ( & V_33 -> free , & V_33 -> V_37 ) ;
F_30 ( & V_33 -> free , & V_33 -> V_38 ) ;
F_33 (e, tmp, &mq->free, list)
F_34 ( V_39 , V_35 ) ;
}
static int F_35 ( struct V_32 * V_33 , unsigned V_40 )
{
unsigned V_41 = V_33 -> V_3 ;
F_18 ( & V_33 -> free ) ;
V_33 -> V_42 = 0 ;
while ( V_41 -- ) {
struct V_34 * V_35 = F_36 ( V_39 , V_43 ) ;
if ( ! V_35 ) {
F_32 ( V_33 ) ;
return - V_44 ;
}
F_37 ( & V_35 -> V_45 , & V_33 -> free ) ;
}
return 0 ;
}
static void F_38 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
unsigned V_46 = F_39 ( F_12 ( V_35 -> V_47 ) , V_33 -> V_48 ) ;
F_40 ( & V_35 -> V_49 , V_33 -> V_50 + V_46 ) ;
}
static struct V_34 * F_41 ( struct V_32 * V_33 , T_2 V_47 )
{
unsigned V_46 = F_39 ( F_12 ( V_47 ) , V_33 -> V_48 ) ;
struct V_51 * V_52 = V_33 -> V_50 + V_46 ;
struct V_34 * V_35 ;
F_42 (e, bucket, hlist)
if ( V_35 -> V_47 == V_47 ) {
F_43 ( & V_35 -> V_49 ) ;
F_40 ( & V_35 -> V_49 , V_52 ) ;
return V_35 ;
}
return NULL ;
}
static void F_44 ( struct V_34 * V_35 )
{
F_43 ( & V_35 -> V_49 ) ;
}
static struct V_34 * F_45 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
if ( V_33 -> V_42 >= V_33 -> V_3 ) {
F_28 ( ! F_26 ( & V_33 -> free ) ) ;
return NULL ;
}
V_35 = F_46 ( F_27 ( & V_33 -> free ) , struct V_34 , V_45 ) ;
F_18 ( & V_35 -> V_45 ) ;
F_47 ( & V_35 -> V_49 ) ;
V_33 -> V_42 ++ ;
return V_35 ;
}
static void F_48 ( struct V_32 * V_33 , T_3 V_53 )
{
F_28 ( F_49 ( V_53 ) > F_49 ( V_33 -> V_54 ) ) ;
F_28 ( F_50 ( F_49 ( V_53 ) , V_33 -> V_55 ) ) ;
F_51 ( F_49 ( V_53 ) , V_33 -> V_55 ) ;
V_33 -> V_56 ++ ;
}
static void F_52 ( struct V_32 * V_33 , T_3 V_53 )
{
F_28 ( F_49 ( V_53 ) > F_49 ( V_33 -> V_54 ) ) ;
F_28 ( ! F_50 ( F_49 ( V_53 ) , V_33 -> V_55 ) ) ;
F_53 ( F_49 ( V_53 ) , V_33 -> V_55 ) ;
V_33 -> V_56 -- ;
}
static bool F_54 ( struct V_32 * V_33 )
{
return V_33 -> V_56 < F_49 ( V_33 -> V_54 ) ;
}
static int F_55 ( struct V_32 * V_33 , unsigned V_57 , unsigned V_58 ,
T_3 * V_59 , unsigned * V_60 )
{
int V_29 = - V_61 ;
unsigned V_62 ;
for ( V_62 = V_57 ; V_62 < V_58 ; V_62 ++ ) {
if ( V_33 -> V_55 [ V_62 ] != ~ 0UL ) {
* V_60 = V_62 ;
* V_59 = F_56 ( ( V_62 * V_5 ) + F_57 ( V_33 -> V_55 [ V_62 ] ) ) ;
if ( F_49 ( * V_59 ) < F_49 ( V_33 -> V_54 ) )
V_29 = 0 ;
break;
}
}
return V_29 ;
}
static int F_58 ( struct V_32 * V_33 , T_3 * V_59 )
{
int V_29 ;
if ( ! F_54 ( V_33 ) )
return - V_61 ;
V_29 = F_55 ( V_33 , V_33 -> V_63 , V_33 -> V_64 , V_59 , & V_33 -> V_63 ) ;
if ( V_29 == - V_61 && V_33 -> V_63 )
V_29 = F_55 ( V_33 , 0 , V_33 -> V_63 , V_59 , & V_33 -> V_63 ) ;
return V_29 ;
}
static unsigned F_59 ( struct V_34 * V_35 )
{
return V_2 ( ( unsigned ) F_60 ( V_35 -> V_65 ) , V_24 - 1u ) ;
}
static void F_61 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
V_35 -> V_66 = V_33 -> V_66 ;
F_38 ( V_33 , V_35 ) ;
if ( V_35 -> V_67 ) {
F_48 ( V_33 , V_35 -> V_53 ) ;
F_19 ( & V_33 -> V_38 , F_59 ( V_35 ) , & V_35 -> V_45 ) ;
} else
F_19 ( & V_33 -> V_37 , F_59 ( V_35 ) , & V_35 -> V_45 ) ;
}
static void F_62 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
F_21 ( & V_35 -> V_45 ) ;
F_44 ( V_35 ) ;
if ( V_35 -> V_67 )
F_52 ( V_33 , V_35 -> V_53 ) ;
}
static struct V_34 * F_63 ( struct V_32 * V_33 , struct V_21 * V_22 )
{
struct V_34 * V_35 = F_64 ( F_25 ( V_22 ) , struct V_34 , V_45 ) ;
if ( V_35 ) {
F_44 ( V_35 ) ;
if ( V_35 -> V_67 )
F_52 ( V_33 , V_35 -> V_53 ) ;
}
return V_35 ;
}
static bool F_65 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
return V_33 -> V_66 == V_35 -> V_66 ;
}
static void F_66 ( struct V_32 * V_33 )
{
unsigned V_68 = 0 , V_69 = 0 , V_70 = 0 , V_26 ;
struct V_27 * V_71 ;
struct V_34 * V_35 ;
if ( ( V_33 -> V_65 >= V_33 -> V_72 ) &&
( V_33 -> V_56 == F_49 ( V_33 -> V_54 ) ) ) {
V_33 -> V_65 = 0 ;
V_33 -> V_73 ++ ;
for ( V_26 = 0 ; V_26 < V_24 && V_70 < V_74 ; V_26 ++ ) {
V_71 = V_33 -> V_38 . V_25 + V_26 ;
F_67 (e, head, list) {
V_69 ++ ;
V_68 += V_35 -> V_65 ;
if ( ++ V_70 >= V_74 )
break;
}
}
V_33 -> V_75 = V_69 ? V_68 / V_69 : 1 ;
if ( V_33 -> V_75 * V_69 < V_68 )
V_33 -> V_75 ++ ;
}
}
static void F_68 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
if ( F_65 ( V_33 , V_35 ) )
return;
V_35 -> V_65 ++ ;
V_33 -> V_65 ++ ;
F_66 ( V_33 ) ;
V_35 -> V_73 = V_33 -> V_73 ;
F_62 ( V_33 , V_35 ) ;
F_61 ( V_33 , V_35 ) ;
}
static T_3 F_69 ( struct V_32 * V_33 , T_2 * V_47 )
{
T_3 V_59 ;
struct V_34 * V_76 = F_63 ( V_33 , & V_33 -> V_38 ) ;
F_28 ( ! V_76 ) ;
V_59 = V_76 -> V_53 ;
* V_47 = V_76 -> V_47 ;
V_76 -> V_67 = false ;
V_76 -> V_65 = 1 ;
F_61 ( V_33 , V_76 ) ;
return V_59 ;
}
static unsigned F_70 ( struct V_32 * V_33 ,
bool V_77 , int V_78 )
{
if ( V_77 && F_54 ( V_33 ) && V_78 == V_79 )
return V_80 ;
return V_78 == V_81 ?
( V_33 -> V_75 + V_82 ) :
( V_33 -> V_75 + V_83 ) ;
}
static bool F_71 ( struct V_32 * V_33 , struct V_34 * V_35 ,
bool V_77 , int V_78 )
{
return V_35 -> V_65 >=
F_70 ( V_33 , V_77 , V_78 ) ;
}
static int F_72 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_84 * V_59 )
{
F_68 ( V_33 , V_35 ) ;
if ( V_35 -> V_67 ) {
V_59 -> V_85 = V_86 ;
V_59 -> V_53 = V_35 -> V_53 ;
}
return 0 ;
}
static int F_73 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_84 * V_59 )
{
T_3 V_53 ;
if ( F_58 ( V_33 , & V_53 ) == - V_61 ) {
V_59 -> V_85 = V_87 ;
V_53 = F_69 ( V_33 , & V_59 -> V_88 ) ;
} else
V_59 -> V_85 = V_89 ;
V_59 -> V_53 = V_35 -> V_53 = V_53 ;
F_62 ( V_33 , V_35 ) ;
V_35 -> V_67 = true ;
F_61 ( V_33 , V_35 ) ;
return 0 ;
}
static int F_74 ( struct V_32 * V_33 , struct V_34 * V_35 ,
bool V_90 , bool V_77 ,
int V_78 , struct V_84 * V_59 )
{
int V_29 = 0 ;
bool V_91 = F_65 ( V_33 , V_35 ) ;
F_68 ( V_33 , V_35 ) ;
if ( ( ! V_77 && V_91 ) ||
! F_71 ( V_33 , V_35 , V_77 , V_78 ) )
V_59 -> V_85 = V_92 ;
else if ( ! V_90 )
V_29 = - V_93 ;
else
V_29 = F_73 ( V_33 , V_35 , V_59 ) ;
return V_29 ;
}
static void F_75 ( struct V_32 * V_33 ,
T_2 V_47 )
{
struct V_34 * V_35 = F_45 ( V_33 ) ;
if ( ! V_35 )
V_35 = F_63 ( V_33 , & V_33 -> V_37 ) ;
if ( F_76 ( ! V_35 ) ) {
F_77 ( L_1 ) ;
return;
}
V_35 -> V_67 = false ;
V_35 -> V_47 = V_47 ;
V_35 -> V_65 = 1 ;
V_35 -> V_73 = V_33 -> V_73 ;
F_61 ( V_33 , V_35 ) ;
}
static void F_78 ( struct V_32 * V_33 , T_2 V_47 ,
struct V_84 * V_59 )
{
struct V_34 * V_35 ;
T_3 V_53 ;
if ( F_58 ( V_33 , & V_53 ) == - V_61 ) {
V_59 -> V_85 = V_92 ;
F_75 ( V_33 , V_47 ) ;
return;
}
V_35 = F_45 ( V_33 ) ;
if ( F_76 ( ! V_35 ) ) {
V_59 -> V_85 = V_92 ;
return;
}
V_35 -> V_47 = V_47 ;
V_35 -> V_53 = V_53 ;
V_35 -> V_67 = true ;
V_35 -> V_65 = 1 ;
V_35 -> V_73 = V_33 -> V_73 ;
F_61 ( V_33 , V_35 ) ;
V_59 -> V_85 = V_89 ;
V_59 -> V_53 = V_35 -> V_53 ;
}
static int F_79 ( struct V_32 * V_33 , T_2 V_47 ,
bool V_90 , bool V_77 ,
int V_78 , struct V_84 * V_59 )
{
if ( F_70 ( V_33 , V_77 , V_78 ) == 1 ) {
if ( V_90 )
F_78 ( V_33 , V_47 , V_59 ) ;
else
return - V_93 ;
} else {
F_75 ( V_33 , V_47 ) ;
V_59 -> V_85 = V_92 ;
}
return 0 ;
}
static int F_80 ( struct V_32 * V_33 , T_2 V_47 ,
bool V_90 , bool V_77 ,
int V_78 , struct V_84 * V_59 )
{
int V_29 = 0 ;
struct V_34 * V_35 = F_41 ( V_33 , V_47 ) ;
if ( V_35 && V_35 -> V_67 )
V_29 = F_72 ( V_33 , V_35 , V_59 ) ;
else if ( F_10 ( & V_33 -> V_94 ) == V_17 )
V_59 -> V_85 = V_92 ;
else if ( V_35 )
V_29 = F_74 ( V_33 , V_35 , V_90 , V_77 ,
V_78 , V_59 ) ;
else
V_29 = F_79 ( V_33 , V_47 , V_90 , V_77 ,
V_78 , V_59 ) ;
if ( V_29 == - V_93 )
V_59 -> V_85 = V_92 ;
return V_29 ;
}
static struct V_32 * F_81 ( struct V_95 * V_96 )
{
return F_64 ( V_96 , struct V_32 , V_97 ) ;
}
static void F_82 ( struct V_95 * V_96 )
{
struct V_32 * V_33 = F_81 ( V_96 ) ;
F_7 ( V_33 -> V_55 ) ;
F_83 ( V_33 -> V_50 ) ;
F_32 ( V_33 ) ;
F_83 ( V_33 ) ;
}
static void F_84 ( struct V_32 * V_33 )
{
unsigned long V_98 ;
F_85 ( & V_33 -> V_99 , V_98 ) ;
V_33 -> V_66 = V_33 -> V_100 ;
F_86 ( & V_33 -> V_99 , V_98 ) ;
}
static int F_87 ( struct V_95 * V_96 , T_2 V_47 ,
bool V_101 , bool V_90 , bool V_77 ,
struct V_19 * V_19 , struct V_84 * V_59 )
{
int V_29 ;
struct V_32 * V_33 = F_81 ( V_96 ) ;
V_59 -> V_85 = V_92 ;
if ( V_101 )
F_88 ( & V_33 -> V_102 ) ;
else if ( ! F_89 ( & V_33 -> V_102 ) )
return - V_93 ;
F_84 ( V_33 ) ;
F_16 ( & V_33 -> V_94 , V_19 ) ;
V_29 = F_80 ( V_33 , V_47 , V_90 , V_77 ,
F_90 ( V_19 ) , V_59 ) ;
F_91 ( & V_33 -> V_102 ) ;
return V_29 ;
}
static int F_92 ( struct V_95 * V_96 , T_2 V_47 , T_3 * V_53 )
{
int V_29 ;
struct V_32 * V_33 = F_81 ( V_96 ) ;
struct V_34 * V_35 ;
if ( ! F_89 ( & V_33 -> V_102 ) )
return - V_93 ;
V_35 = F_41 ( V_33 , V_47 ) ;
if ( V_35 && V_35 -> V_67 ) {
* V_53 = V_35 -> V_53 ;
V_29 = 0 ;
} else
V_29 = - V_103 ;
F_91 ( & V_33 -> V_102 ) ;
return V_29 ;
}
static int F_93 ( struct V_95 * V_96 ,
T_2 V_47 , T_3 V_53 ,
T_4 V_104 , bool V_105 )
{
struct V_32 * V_33 = F_81 ( V_96 ) ;
struct V_34 * V_35 ;
V_35 = F_45 ( V_33 ) ;
if ( ! V_35 )
return - V_44 ;
V_35 -> V_53 = V_53 ;
V_35 -> V_47 = V_47 ;
V_35 -> V_67 = true ;
V_35 -> V_65 = V_105 ? V_104 : 1 ;
V_35 -> V_73 = V_33 -> V_73 ;
F_61 ( V_33 , V_35 ) ;
return 0 ;
}
static int F_94 ( struct V_95 * V_96 , T_5 V_106 ,
void * V_107 )
{
struct V_32 * V_33 = F_81 ( V_96 ) ;
int V_29 = 0 ;
struct V_34 * V_35 ;
unsigned V_26 ;
F_88 ( & V_33 -> V_102 ) ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
F_67 (e, &mq->cache.qs[level], list) {
V_29 = V_106 ( V_107 , V_35 -> V_53 , V_35 -> V_47 , V_35 -> V_65 ) ;
if ( V_29 )
goto V_108;
}
V_108:
F_91 ( & V_33 -> V_102 ) ;
return V_29 ;
}
static void F_95 ( struct V_95 * V_96 , T_2 V_47 )
{
struct V_32 * V_33 = F_81 ( V_96 ) ;
struct V_34 * V_35 ;
F_88 ( & V_33 -> V_102 ) ;
V_35 = F_41 ( V_33 , V_47 ) ;
F_28 ( ! V_35 || ! V_35 -> V_67 ) ;
F_62 ( V_33 , V_35 ) ;
V_35 -> V_67 = false ;
F_61 ( V_33 , V_35 ) ;
F_91 ( & V_33 -> V_102 ) ;
}
static void F_96 ( struct V_32 * V_33 ,
T_2 V_109 , T_2 V_110 )
{
struct V_34 * V_35 = F_41 ( V_33 , V_109 ) ;
F_28 ( ! V_35 || ! V_35 -> V_67 ) ;
F_62 ( V_33 , V_35 ) ;
V_35 -> V_47 = V_110 ;
F_61 ( V_33 , V_35 ) ;
}
static void F_97 ( struct V_95 * V_96 ,
T_2 V_109 , T_2 V_110 )
{
struct V_32 * V_33 = F_81 ( V_96 ) ;
F_88 ( & V_33 -> V_102 ) ;
F_96 ( V_33 , V_109 , V_110 ) ;
F_91 ( & V_33 -> V_102 ) ;
}
static T_3 F_98 ( struct V_95 * V_96 )
{
struct V_32 * V_33 = F_81 ( V_96 ) ;
return F_56 ( V_33 -> V_56 ) ;
}
static void F_99 ( struct V_95 * V_96 )
{
struct V_32 * V_33 = F_81 ( V_96 ) ;
unsigned long V_98 ;
F_85 ( & V_33 -> V_99 , V_98 ) ;
V_33 -> V_100 ++ ;
F_86 ( & V_33 -> V_99 , V_98 ) ;
}
static int F_100 ( struct V_95 * V_96 ,
const char * V_111 , const char * V_112 )
{
struct V_32 * V_33 = F_81 ( V_96 ) ;
enum V_18 V_11 ;
unsigned long V_36 ;
if ( ! strcasecmp ( V_111 , L_2 ) )
V_11 = V_12 ;
else if ( ! strcasecmp ( V_111 , L_3 ) )
V_11 = V_17 ;
else
return - V_113 ;
if ( F_101 ( V_112 , 10 , & V_36 ) )
return - V_113 ;
V_33 -> V_94 . V_16 [ V_11 ] = V_36 ;
return 0 ;
}
static int F_102 ( struct V_95 * V_96 , char * V_59 , unsigned V_114 )
{
T_6 V_115 = 0 ;
struct V_32 * V_33 = F_81 ( V_96 ) ;
F_103 ( L_4 ,
V_33 -> V_94 . V_16 [ V_12 ] ,
V_33 -> V_94 . V_16 [ V_17 ] ) ;
return 0 ;
}
static void F_104 ( struct V_32 * V_33 )
{
V_33 -> V_97 . V_116 = F_82 ;
V_33 -> V_97 . F_80 = F_87 ;
V_33 -> V_97 . V_117 = F_92 ;
V_33 -> V_97 . V_118 = F_93 ;
V_33 -> V_97 . V_119 = F_94 ;
V_33 -> V_97 . V_120 = F_95 ;
V_33 -> V_97 . V_121 = NULL ;
V_33 -> V_97 . F_96 = F_97 ;
V_33 -> V_97 . V_122 = F_98 ;
V_33 -> V_97 . V_66 = F_99 ;
V_33 -> V_97 . V_123 = F_102 ;
V_33 -> V_97 . V_124 = F_100 ;
}
static struct V_95 * F_105 ( T_3 V_54 ,
T_7 V_125 ,
T_7 V_126 )
{
int V_29 ;
struct V_32 * V_33 = F_106 ( sizeof( * V_33 ) , V_43 ) ;
if ( ! V_33 )
return NULL ;
F_104 ( V_33 ) ;
F_9 ( & V_33 -> V_94 , V_127 , V_128 ) ;
V_33 -> V_54 = V_54 ;
V_33 -> V_100 = 0 ;
V_33 -> V_66 = 0 ;
V_33 -> V_65 = 0 ;
V_33 -> V_73 = 0 ;
V_33 -> V_75 = 0 ;
F_107 ( & V_33 -> V_102 ) ;
F_108 ( & V_33 -> V_99 ) ;
V_33 -> V_64 = F_5 ( F_49 ( V_33 -> V_54 ) , V_5 ) ;
V_33 -> V_63 = 0 ;
F_17 ( & V_33 -> V_37 ) ;
F_17 ( & V_33 -> V_38 ) ;
V_33 -> V_72 = F_3 ( ( unsigned ) F_49 ( V_54 ) , 1024U ) ;
V_33 -> V_3 = 2 * F_49 ( V_54 ) ;
V_29 = F_35 ( V_33 , V_33 -> V_3 ) ;
if ( V_29 )
goto V_129;
V_33 -> V_42 = 0 ;
V_33 -> V_56 = 0 ;
V_33 -> V_130 = F_1 ( F_49 ( V_54 ) / 2 , 16 ) ;
V_33 -> V_48 = F_109 ( V_33 -> V_130 ) - 1 ;
V_33 -> V_50 = F_106 ( sizeof( * V_33 -> V_50 ) * V_33 -> V_130 , V_43 ) ;
if ( ! V_33 -> V_50 )
goto V_131;
V_33 -> V_55 = F_4 ( F_49 ( V_54 ) ) ;
if ( ! V_33 -> V_55 )
goto V_132;
return & V_33 -> V_97 ;
V_132:
F_83 ( V_33 -> V_50 ) ;
V_131:
F_32 ( V_33 ) ;
V_129:
F_83 ( V_33 ) ;
return NULL ;
}
static int T_8 F_110 ( void )
{
int V_29 ;
V_39 = F_111 ( L_5 ,
sizeof( struct V_34 ) ,
F_112 ( struct V_34 ) ,
0 , NULL ) ;
if ( ! V_39 )
goto V_133;
V_29 = F_113 ( & V_134 ) ;
if ( V_29 ) {
F_114 ( L_6 , V_29 ) ;
goto V_135;
}
V_29 = F_113 ( & V_136 ) ;
if ( ! V_29 ) {
F_115 ( L_7 ,
V_134 . V_137 [ 0 ] ,
V_134 . V_137 [ 1 ] ,
V_134 . V_137 [ 2 ] ) ;
return 0 ;
}
F_114 ( L_8 , V_29 ) ;
F_116 ( & V_134 ) ;
V_135:
F_117 ( V_39 ) ;
V_133:
return - V_44 ;
}
static void T_9 F_118 ( void )
{
F_116 ( & V_134 ) ;
F_116 ( & V_136 ) ;
F_117 ( V_39 ) ;
}
