static unsigned F_1 ( unsigned V_1 , unsigned V_2 )
{
return F_2 ( F_3 ( V_1 , V_2 ) ) ;
}
static void F_4 ( struct V_3 * V_4 ,
int V_5 , int V_6 )
{
V_4 -> V_7 = V_8 ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
V_4 -> V_12 [ V_8 ] = V_6 ;
V_4 -> V_12 [ V_13 ] = V_5 ;
}
static enum V_14 F_5 ( struct V_3 * V_4 )
{
return V_4 -> V_7 ;
}
static void F_6 ( struct V_3 * V_4 , struct V_15 * V_15 )
{
if ( V_15 -> V_16 . V_17 == F_7 ( V_4 -> V_11 ) + 1 )
V_4 -> V_9 ++ ;
else {
if ( V_4 -> V_9 ) {
V_4 -> V_9 = 0 ;
V_4 -> V_10 = 0 ;
}
V_4 -> V_10 ++ ;
}
V_4 -> V_11 = F_8 ( F_9 ( V_15 ) - 1 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_7 ) {
case V_13 :
if ( V_4 -> V_10 >= V_4 -> V_12 [ V_8 ] ) {
V_4 -> V_7 = V_8 ;
V_4 -> V_9 = V_4 -> V_10 = 0 ;
}
break;
case V_8 :
if ( V_4 -> V_9 >= V_4 -> V_12 [ V_13 ] ) {
V_4 -> V_7 = V_13 ;
V_4 -> V_9 = V_4 -> V_10 = 0 ;
}
break;
}
}
static void F_11 ( struct V_3 * V_4 , struct V_15 * V_15 )
{
F_6 ( V_4 , V_15 ) ;
F_10 ( V_4 ) ;
}
static void F_12 ( struct V_18 * V_19 )
{
unsigned V_20 ;
V_19 -> V_21 = 0 ;
V_19 -> V_22 = false ;
V_19 -> V_23 = 0 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
F_13 ( V_19 -> V_25 + V_20 ) ;
F_13 ( V_19 -> V_26 + V_20 ) ;
F_13 ( V_19 -> V_26 + V_24 + V_20 ) ;
F_13 ( V_19 -> V_26 + ( 2 * V_24 ) + V_20 ) ;
}
}
static unsigned F_14 ( struct V_18 * V_19 )
{
return V_19 -> V_21 ;
}
static bool F_15 ( struct V_18 * V_19 )
{
return V_19 -> V_21 == 0 ;
}
static void F_16 ( struct V_18 * V_19 , unsigned V_27 , struct V_28 * V_29 )
{
V_19 -> V_21 ++ ;
F_17 ( V_29 , V_19 -> V_25 + V_27 ) ;
}
static void F_18 ( struct V_18 * V_19 , struct V_28 * V_29 )
{
V_19 -> V_21 -- ;
F_19 ( V_29 ) ;
}
static bool F_20 ( struct V_18 * V_19 , struct V_28 * V_30 )
{
return ( V_30 >= V_19 -> V_26 ) && ( V_30 < ( V_19 -> V_26 + V_31 ) ) ;
}
static struct V_28 * F_21 ( struct V_18 * V_19 )
{
unsigned V_27 ;
struct V_28 * V_30 ;
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ )
F_22 (h, q->qs + level)
if ( ! F_20 ( V_19 , V_30 ) )
return V_30 ;
return NULL ;
}
static struct V_28 * F_23 ( struct V_18 * V_19 )
{
struct V_28 * V_32 = F_21 ( V_19 ) ;
if ( V_32 ) {
V_19 -> V_21 -- ;
F_19 ( V_32 ) ;
}
return V_32 ;
}
static struct V_28 * F_24 ( struct V_18 * V_19 )
{
unsigned V_27 ;
struct V_28 * V_30 ;
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ )
F_22 (h, q->qs + level) {
if ( F_20 ( V_19 , V_30 ) )
break;
V_19 -> V_21 -- ;
F_19 ( V_30 ) ;
return V_30 ;
}
return NULL ;
}
static struct V_28 * F_25 ( struct V_28 * V_33 )
{
struct V_28 * V_32 = V_33 -> V_34 ;
F_26 ( ! V_32 ) ;
F_27 ( V_32 ) ;
return V_32 ;
}
static struct V_28 * F_28 ( struct V_18 * V_19 , unsigned V_27 )
{
if ( V_19 -> V_22 )
return V_19 -> V_26 + V_24 + V_27 ;
else
return V_19 -> V_26 + 2 * V_24 + V_27 ;
}
static void F_29 ( struct V_18 * V_19 )
{
unsigned V_20 ;
struct V_28 * V_30 ;
if ( F_30 ( V_35 , V_19 -> V_23 ) ) {
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
V_30 = F_28 ( V_19 , V_20 ) ;
F_19 ( V_30 ) ;
F_17 ( V_30 , V_19 -> V_25 + V_20 ) ;
}
V_19 -> V_23 = V_35 + V_36 ;
V_19 -> V_22 = ! V_19 -> V_22 ;
}
}
static void F_31 ( struct V_18 * V_19 )
{
unsigned V_20 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
F_19 ( V_19 -> V_26 + V_20 ) ;
F_17 ( V_19 -> V_26 + V_20 , V_19 -> V_25 + V_20 ) ;
}
}
static void F_32 ( struct V_18 * V_19 , T_1 V_37 , void * V_38 )
{
unsigned V_20 ;
struct V_28 * V_30 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ ) {
F_33 (h, q->qs + i) {
if ( F_20 ( V_19 , V_30 ) )
break;
V_37 ( V_30 , V_38 ) ;
}
}
}
static int F_34 ( struct V_39 * V_40 , unsigned V_41 )
{
unsigned V_20 ;
V_40 -> V_42 = F_35 ( sizeof( struct V_43 ) * V_41 ) ;
if ( ! V_40 -> V_42 )
return - V_44 ;
V_40 -> V_45 = V_40 -> V_42 + V_41 ;
F_13 ( & V_40 -> free ) ;
for ( V_20 = 0 ; V_20 < V_41 ; V_20 ++ )
F_36 ( & V_40 -> V_42 [ V_20 ] . V_46 , & V_40 -> free ) ;
V_40 -> V_47 = 0 ;
return 0 ;
}
static void F_37 ( struct V_39 * V_40 )
{
F_38 ( V_40 -> V_42 ) ;
}
static struct V_43 * F_39 ( struct V_39 * V_40 )
{
struct V_43 * V_48 ;
if ( F_40 ( & V_40 -> free ) )
return NULL ;
V_48 = F_41 ( F_25 ( & V_40 -> free ) , struct V_43 , V_46 ) ;
F_13 ( & V_48 -> V_46 ) ;
F_42 ( & V_48 -> V_49 ) ;
V_40 -> V_47 ++ ;
return V_48 ;
}
static struct V_43 * F_43 ( struct V_39 * V_40 , T_2 V_50 )
{
struct V_43 * V_48 = V_40 -> V_42 + F_44 ( V_50 ) ;
F_27 ( & V_48 -> V_46 ) ;
F_42 ( & V_48 -> V_49 ) ;
V_40 -> V_47 ++ ;
return V_48 ;
}
static void F_45 ( struct V_39 * V_40 , struct V_43 * V_48 )
{
F_26 ( ! V_40 -> V_47 ) ;
V_40 -> V_47 -- ;
F_42 ( & V_48 -> V_49 ) ;
F_36 ( & V_48 -> V_46 , & V_40 -> free ) ;
}
static struct V_43 * F_46 ( struct V_39 * V_40 , T_2 V_50 )
{
struct V_43 * V_48 = V_40 -> V_42 + F_44 ( V_50 ) ;
return ! F_47 ( & V_48 -> V_49 ) ? V_48 : NULL ;
}
static bool F_48 ( struct V_39 * V_40 )
{
return F_40 ( & V_40 -> free ) ;
}
static bool F_49 ( struct V_39 * V_40 , struct V_43 * V_48 )
{
return V_48 >= V_40 -> V_42 && V_48 < V_40 -> V_45 ;
}
static T_2 F_50 ( struct V_39 * V_40 , struct V_43 * V_48 )
{
return F_51 ( V_48 - V_40 -> V_42 ) ;
}
static void F_52 ( struct V_51 * V_52 , struct V_43 * V_48 )
{
unsigned V_30 = F_53 ( F_7 ( V_48 -> V_53 ) , V_52 -> V_54 ) ;
F_54 ( & V_48 -> V_49 , V_52 -> V_55 + V_30 ) ;
}
static struct V_43 * F_55 ( struct V_51 * V_52 , T_3 V_53 )
{
unsigned V_30 = F_53 ( F_7 ( V_53 ) , V_52 -> V_54 ) ;
struct V_56 * V_57 = V_52 -> V_55 + V_30 ;
struct V_43 * V_48 ;
F_56 (e, bucket, hlist)
if ( V_48 -> V_53 == V_53 ) {
F_57 ( & V_48 -> V_49 ) ;
F_54 ( & V_48 -> V_49 , V_57 ) ;
return V_48 ;
}
return NULL ;
}
static void F_58 ( struct V_43 * V_48 )
{
F_57 ( & V_48 -> V_49 ) ;
}
static bool F_59 ( struct V_51 * V_52 )
{
return ! F_48 ( & V_52 -> V_58 ) ;
}
static bool F_60 ( struct V_51 * V_52 )
{
return ! F_15 ( & V_52 -> V_59 ) ;
}
static unsigned F_61 ( struct V_43 * V_48 )
{
return V_2 ( ( unsigned ) F_62 ( V_48 -> V_60 ) , V_24 - 1u ) ;
}
static bool F_63 ( struct V_51 * V_52 , struct V_43 * V_48 )
{
return F_49 ( & V_52 -> V_58 , V_48 ) ;
}
static void F_64 ( struct V_51 * V_52 , struct V_43 * V_48 )
{
F_52 ( V_52 , V_48 ) ;
if ( F_63 ( V_52 , V_48 ) )
F_16 ( V_48 -> V_61 ? & V_52 -> V_62 : & V_52 -> V_59 ,
F_61 ( V_48 ) , & V_48 -> V_46 ) ;
else
F_16 ( & V_52 -> V_63 , F_61 ( V_48 ) , & V_48 -> V_46 ) ;
}
static void F_65 ( struct V_51 * V_52 , struct V_43 * V_48 )
{
if ( F_63 ( V_52 , V_48 ) )
F_18 ( V_48 -> V_61 ? & V_52 -> V_62 : & V_52 -> V_59 , & V_48 -> V_46 ) ;
else
F_18 ( & V_52 -> V_63 , & V_48 -> V_46 ) ;
F_58 ( V_48 ) ;
}
static struct V_43 * F_66 ( struct V_51 * V_52 , struct V_18 * V_19 )
{
struct V_43 * V_48 ;
struct V_28 * V_30 = F_23 ( V_19 ) ;
if ( ! V_30 )
return NULL ;
V_48 = F_67 ( V_30 , struct V_43 , V_46 ) ;
F_58 ( V_48 ) ;
return V_48 ;
}
static struct V_43 * F_68 ( struct V_51 * V_52 , struct V_18 * V_19 )
{
struct V_43 * V_48 ;
struct V_28 * V_30 = F_24 ( V_19 ) ;
if ( ! V_30 )
return NULL ;
V_48 = F_67 ( V_30 , struct V_43 , V_46 ) ;
F_58 ( V_48 ) ;
return V_48 ;
}
static struct V_43 * F_69 ( struct V_18 * V_19 )
{
struct V_28 * V_30 = F_21 ( V_19 ) ;
return V_30 ? F_67 ( V_30 , struct V_43 , V_46 ) : NULL ;
}
static void F_70 ( struct V_51 * V_52 )
{
unsigned V_64 = 0 , V_65 = 0 , V_66 = 0 , V_27 ;
struct V_28 * V_67 ;
struct V_43 * V_48 ;
if ( ( V_52 -> V_60 >= V_52 -> V_68 ) && ( F_48 ( & V_52 -> V_58 ) ) ) {
V_52 -> V_60 = 0 ;
V_52 -> V_69 ++ ;
for ( V_27 = 0 ; V_27 < V_24 && V_66 < V_70 ; V_27 ++ ) {
V_67 = V_52 -> V_59 . V_25 + V_27 ;
F_71 (e, head, list) {
V_65 ++ ;
V_64 += V_48 -> V_60 ;
if ( ++ V_66 >= V_70 )
break;
}
V_67 = V_52 -> V_62 . V_25 + V_27 ;
F_71 (e, head, list) {
V_65 ++ ;
V_64 += V_48 -> V_60 ;
if ( ++ V_66 >= V_70 )
break;
}
}
}
}
static void F_72 ( struct V_51 * V_52 , struct V_43 * V_48 )
{
F_70 ( V_52 ) ;
F_65 ( V_52 , V_48 ) ;
F_64 ( V_52 , V_48 ) ;
}
static int F_73 ( struct V_51 * V_52 , T_3 * V_53 )
{
struct V_43 * V_71 = F_66 ( V_52 , & V_52 -> V_59 ) ;
if ( ! V_71 )
return - V_72 ;
* V_53 = V_71 -> V_53 ;
F_45 ( & V_52 -> V_58 , V_71 ) ;
return 0 ;
}
static unsigned F_74 ( struct V_51 * V_52 )
{
struct V_43 * V_48 ;
if ( F_59 ( V_52 ) )
return 0 ;
V_48 = F_69 ( & V_52 -> V_59 ) ;
if ( V_48 )
return V_48 -> V_60 ;
V_48 = F_69 ( & V_52 -> V_62 ) ;
if ( V_48 )
return V_48 -> V_60 + V_73 ;
return 0 ;
}
static unsigned F_75 ( struct V_51 * V_52 ,
bool V_74 , int V_75 )
{
if ( V_75 == V_76 )
return F_74 ( V_52 ) + V_52 -> V_77 ;
if ( V_74 && ( F_59 ( V_52 ) || F_60 ( V_52 ) ) ) {
return V_52 -> V_78 ;
}
return F_74 ( V_52 ) + V_52 -> V_79 ;
}
static bool F_76 ( struct V_51 * V_52 , struct V_43 * V_48 ,
bool V_74 , int V_75 )
{
return V_48 -> V_60 >=
F_75 ( V_52 , V_74 , V_75 ) ;
}
static int F_77 ( struct V_51 * V_52 ,
struct V_43 * V_48 ,
struct V_80 * V_81 )
{
F_72 ( V_52 , V_48 ) ;
if ( F_63 ( V_52 , V_48 ) ) {
V_81 -> V_82 = V_83 ;
V_81 -> V_50 = F_50 ( & V_52 -> V_58 , V_48 ) ;
}
return 0 ;
}
static int F_78 ( struct V_51 * V_52 , struct V_43 * V_48 ,
struct V_80 * V_81 )
{
int V_32 ;
struct V_43 * V_84 ;
if ( F_48 ( & V_52 -> V_58 ) ) {
V_81 -> V_82 = V_85 ;
V_32 = F_73 ( V_52 , & V_81 -> V_86 ) ;
if ( V_32 ) {
V_81 -> V_82 = V_87 ;
return 0 ;
}
} else
V_81 -> V_82 = V_88 ;
V_84 = F_39 ( & V_52 -> V_58 ) ;
F_26 ( ! V_84 ) ;
V_84 -> V_53 = V_48 -> V_53 ;
V_84 -> V_61 = false ;
V_84 -> V_60 = V_48 -> V_60 ;
F_65 ( V_52 , V_48 ) ;
F_45 ( & V_52 -> V_89 , V_48 ) ;
F_64 ( V_52 , V_84 ) ;
V_81 -> V_50 = F_50 ( & V_52 -> V_58 , V_84 ) ;
return 0 ;
}
static int F_79 ( struct V_51 * V_52 , struct V_43 * V_48 ,
bool V_90 , bool V_74 ,
int V_75 , struct V_80 * V_81 )
{
int V_32 = 0 ;
if ( ! F_76 ( V_52 , V_48 , V_74 , V_75 ) ) {
F_72 ( V_52 , V_48 ) ;
V_81 -> V_82 = V_87 ;
} else if ( ! V_90 )
V_32 = - V_91 ;
else {
F_72 ( V_52 , V_48 ) ;
V_32 = F_78 ( V_52 , V_48 , V_81 ) ;
}
return V_32 ;
}
static void F_80 ( struct V_51 * V_52 ,
T_3 V_53 )
{
struct V_43 * V_48 = F_39 ( & V_52 -> V_89 ) ;
if ( ! V_48 )
V_48 = F_66 ( V_52 , & V_52 -> V_63 ) ;
if ( F_81 ( ! V_48 ) ) {
F_82 ( L_1 ) ;
return;
}
V_48 -> V_61 = false ;
V_48 -> V_53 = V_53 ;
V_48 -> V_60 = 1 ;
F_64 ( V_52 , V_48 ) ;
}
static void F_83 ( struct V_51 * V_52 , T_3 V_53 ,
struct V_80 * V_81 )
{
int V_32 ;
struct V_43 * V_48 ;
if ( F_48 ( & V_52 -> V_58 ) ) {
V_81 -> V_82 = V_85 ;
V_32 = F_73 ( V_52 , & V_81 -> V_86 ) ;
if ( F_81 ( V_32 ) ) {
V_81 -> V_82 = V_87 ;
F_80 ( V_52 , V_53 ) ;
return;
}
V_48 = F_39 ( & V_52 -> V_58 ) ;
F_26 ( ! V_48 ) ;
} else {
V_48 = F_39 ( & V_52 -> V_58 ) ;
V_81 -> V_82 = V_88 ;
}
V_48 -> V_53 = V_53 ;
V_48 -> V_61 = false ;
V_48 -> V_60 = 1 ;
F_64 ( V_52 , V_48 ) ;
V_81 -> V_50 = F_50 ( & V_52 -> V_58 , V_48 ) ;
}
static int F_84 ( struct V_51 * V_52 , T_3 V_53 ,
bool V_90 , bool V_74 ,
int V_75 , struct V_80 * V_81 )
{
if ( F_75 ( V_52 , V_74 , V_75 ) <= 1 ) {
if ( V_90 )
F_83 ( V_52 , V_53 , V_81 ) ;
else
return - V_91 ;
} else {
F_80 ( V_52 , V_53 ) ;
V_81 -> V_82 = V_87 ;
}
return 0 ;
}
static int F_85 ( struct V_51 * V_52 , T_3 V_53 ,
bool V_90 , bool V_74 ,
int V_75 , struct V_80 * V_81 )
{
int V_32 = 0 ;
struct V_43 * V_48 = F_55 ( V_52 , V_53 ) ;
if ( V_48 && F_63 ( V_52 , V_48 ) )
V_32 = F_77 ( V_52 , V_48 , V_81 ) ;
else if ( V_52 -> V_92 . V_12 [ V_13 ] &&
F_5 ( & V_52 -> V_92 ) == V_13 )
V_81 -> V_82 = V_87 ;
else if ( V_48 )
V_32 = F_79 ( V_52 , V_48 , V_90 , V_74 ,
V_75 , V_81 ) ;
else
V_32 = F_84 ( V_52 , V_53 , V_90 , V_74 ,
V_75 , V_81 ) ;
if ( V_32 == - V_91 )
V_81 -> V_82 = V_87 ;
return V_32 ;
}
static struct V_51 * F_86 ( struct V_93 * V_94 )
{
return F_67 ( V_94 , struct V_51 , V_95 ) ;
}
static void F_87 ( struct V_93 * V_94 )
{
struct V_51 * V_52 = F_86 ( V_94 ) ;
F_38 ( V_52 -> V_55 ) ;
F_37 ( & V_52 -> V_58 ) ;
F_37 ( & V_52 -> V_89 ) ;
F_88 ( V_52 ) ;
}
static void F_89 ( struct V_28 * V_30 , void * V_38 )
{
struct V_43 * V_48 = F_67 ( V_30 , struct V_43 , V_46 ) ;
V_48 -> V_60 ++ ;
}
static void F_90 ( struct V_28 * V_30 , void * V_38 )
{
struct V_51 * V_52 = V_38 ;
struct V_43 * V_48 = F_67 ( V_30 , struct V_43 , V_46 ) ;
V_48 -> V_60 ++ ;
V_52 -> V_60 ++ ;
}
static void F_91 ( struct V_51 * V_52 )
{
unsigned long V_96 , V_97 ;
F_92 ( & V_52 -> V_98 , V_96 ) ;
V_97 = V_52 -> V_99 ;
if ( V_97 != V_52 -> V_97 ) {
F_32 ( & V_52 -> V_63 , F_89 , V_52 ) ;
F_32 ( & V_52 -> V_62 , F_90 , V_52 ) ;
F_32 ( & V_52 -> V_59 , F_90 , V_52 ) ;
V_52 -> V_97 = V_97 ;
}
F_31 ( & V_52 -> V_63 ) ;
F_31 ( & V_52 -> V_62 ) ;
F_31 ( & V_52 -> V_59 ) ;
F_29 ( & V_52 -> V_62 ) ;
F_93 ( & V_52 -> V_98 , V_96 ) ;
}
static int F_94 ( struct V_93 * V_94 , T_3 V_53 ,
bool V_100 , bool V_90 , bool V_74 ,
struct V_15 * V_15 , struct V_80 * V_81 )
{
int V_32 ;
struct V_51 * V_52 = F_86 ( V_94 ) ;
V_81 -> V_82 = V_87 ;
if ( V_100 )
F_95 ( & V_52 -> V_101 ) ;
else if ( ! F_96 ( & V_52 -> V_101 ) )
return - V_91 ;
F_91 ( V_52 ) ;
F_11 ( & V_52 -> V_92 , V_15 ) ;
V_32 = F_85 ( V_52 , V_53 , V_90 , V_74 ,
F_97 ( V_15 ) , V_81 ) ;
F_98 ( & V_52 -> V_101 ) ;
return V_32 ;
}
static int F_99 ( struct V_93 * V_94 , T_3 V_53 , T_2 * V_50 )
{
int V_32 ;
struct V_51 * V_52 = F_86 ( V_94 ) ;
struct V_43 * V_48 ;
if ( ! F_96 ( & V_52 -> V_101 ) )
return - V_91 ;
V_48 = F_55 ( V_52 , V_53 ) ;
if ( V_48 && F_63 ( V_52 , V_48 ) ) {
* V_50 = F_50 ( & V_52 -> V_58 , V_48 ) ;
V_32 = 0 ;
} else
V_32 = - V_102 ;
F_98 ( & V_52 -> V_101 ) ;
return V_32 ;
}
static void F_100 ( struct V_51 * V_52 , T_3 V_53 , bool V_103 )
{
struct V_43 * V_48 ;
V_48 = F_55 ( V_52 , V_53 ) ;
F_26 ( ! V_48 || ! F_63 ( V_52 , V_48 ) ) ;
F_65 ( V_52 , V_48 ) ;
V_48 -> V_61 = V_103 ;
F_64 ( V_52 , V_48 ) ;
}
static void F_101 ( struct V_93 * V_94 , T_3 V_53 )
{
struct V_51 * V_52 = F_86 ( V_94 ) ;
F_95 ( & V_52 -> V_101 ) ;
F_100 ( V_52 , V_53 , true ) ;
F_98 ( & V_52 -> V_101 ) ;
}
static void F_102 ( struct V_93 * V_94 , T_3 V_53 )
{
struct V_51 * V_52 = F_86 ( V_94 ) ;
F_95 ( & V_52 -> V_101 ) ;
F_100 ( V_52 , V_53 , false ) ;
F_98 ( & V_52 -> V_101 ) ;
}
static int F_103 ( struct V_93 * V_94 ,
T_3 V_53 , T_2 V_50 ,
T_4 V_104 , bool V_105 )
{
struct V_51 * V_52 = F_86 ( V_94 ) ;
struct V_43 * V_48 ;
V_48 = F_43 ( & V_52 -> V_58 , V_50 ) ;
V_48 -> V_53 = V_53 ;
V_48 -> V_61 = false ;
V_48 -> V_60 = V_105 ? V_104 : 1 ;
F_64 ( V_52 , V_48 ) ;
return 0 ;
}
static int F_104 ( struct V_51 * V_52 , struct V_18 * V_19 ,
T_5 V_37 , void * V_38 )
{
int V_32 ;
unsigned V_27 ;
struct V_28 * V_30 ;
struct V_43 * V_48 ;
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ )
F_22 (h, q->qs + level) {
if ( F_20 ( V_19 , V_30 ) )
continue;
V_48 = F_67 ( V_30 , struct V_43 , V_46 ) ;
V_32 = V_37 ( V_38 , F_50 ( & V_52 -> V_58 , V_48 ) ,
V_48 -> V_53 , V_48 -> V_60 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_105 ( struct V_93 * V_94 , T_5 V_37 ,
void * V_38 )
{
struct V_51 * V_52 = F_86 ( V_94 ) ;
int V_32 = 0 ;
F_95 ( & V_52 -> V_101 ) ;
V_32 = F_104 ( V_52 , & V_52 -> V_59 , V_37 , V_38 ) ;
if ( ! V_32 )
V_32 = F_104 ( V_52 , & V_52 -> V_62 , V_37 , V_38 ) ;
F_98 ( & V_52 -> V_101 ) ;
return V_32 ;
}
static void F_106 ( struct V_51 * V_52 , T_3 V_53 )
{
struct V_43 * V_48 ;
V_48 = F_55 ( V_52 , V_53 ) ;
F_26 ( ! V_48 || ! F_63 ( V_52 , V_48 ) ) ;
F_65 ( V_52 , V_48 ) ;
F_45 ( & V_52 -> V_58 , V_48 ) ;
}
static void F_107 ( struct V_93 * V_94 , T_3 V_53 )
{
struct V_51 * V_52 = F_86 ( V_94 ) ;
F_95 ( & V_52 -> V_101 ) ;
F_106 ( V_52 , V_53 ) ;
F_98 ( & V_52 -> V_101 ) ;
}
static int F_108 ( struct V_51 * V_52 , T_2 V_50 )
{
struct V_43 * V_48 = F_46 ( & V_52 -> V_58 , V_50 ) ;
if ( ! V_48 )
return - V_106 ;
F_65 ( V_52 , V_48 ) ;
F_45 ( & V_52 -> V_58 , V_48 ) ;
return 0 ;
}
static int F_109 ( struct V_93 * V_94 , T_2 V_50 )
{
int V_32 ;
struct V_51 * V_52 = F_86 ( V_94 ) ;
F_95 ( & V_52 -> V_101 ) ;
V_32 = F_108 ( V_52 , V_50 ) ;
F_98 ( & V_52 -> V_101 ) ;
return V_32 ;
}
static bool F_110 ( struct V_51 * V_52 )
{
unsigned V_107 = F_44 ( V_52 -> V_108 ) - F_14 ( & V_52 -> V_62 ) ;
unsigned V_109 = F_44 ( V_52 -> V_108 ) * V_110 / 100 ;
return V_107 >= V_109 ;
}
static int F_111 ( struct V_51 * V_52 , T_3 * V_53 ,
T_2 * V_50 )
{
struct V_43 * V_48 = F_68 ( V_52 , & V_52 -> V_62 ) ;
if ( ! V_48 && ! F_110 ( V_52 ) )
V_48 = F_66 ( V_52 , & V_52 -> V_62 ) ;
if ( ! V_48 )
return - V_106 ;
* V_53 = V_48 -> V_53 ;
* V_50 = F_50 ( & V_52 -> V_58 , V_48 ) ;
V_48 -> V_61 = false ;
F_64 ( V_52 , V_48 ) ;
return 0 ;
}
static int F_112 ( struct V_93 * V_94 , T_3 * V_53 ,
T_2 * V_50 )
{
int V_32 ;
struct V_51 * V_52 = F_86 ( V_94 ) ;
F_95 ( & V_52 -> V_101 ) ;
V_32 = F_111 ( V_52 , V_53 , V_50 ) ;
F_98 ( & V_52 -> V_101 ) ;
return V_32 ;
}
static void F_113 ( struct V_51 * V_52 ,
T_3 V_111 , T_3 V_112 )
{
struct V_43 * V_48 = F_55 ( V_52 , V_111 ) ;
if ( V_48 && F_63 ( V_52 , V_48 ) ) {
F_65 ( V_52 , V_48 ) ;
V_48 -> V_53 = V_112 ;
V_48 -> V_61 = true ;
F_64 ( V_52 , V_48 ) ;
}
}
static void F_114 ( struct V_93 * V_94 ,
T_3 V_111 , T_3 V_112 )
{
struct V_51 * V_52 = F_86 ( V_94 ) ;
F_95 ( & V_52 -> V_101 ) ;
F_113 ( V_52 , V_111 , V_112 ) ;
F_98 ( & V_52 -> V_101 ) ;
}
static T_2 F_115 ( struct V_93 * V_94 )
{
T_2 V_32 ;
struct V_51 * V_52 = F_86 ( V_94 ) ;
F_95 ( & V_52 -> V_101 ) ;
V_32 = F_51 ( V_52 -> V_58 . V_47 ) ;
F_98 ( & V_52 -> V_101 ) ;
return V_32 ;
}
static void F_116 ( struct V_93 * V_94 )
{
struct V_51 * V_52 = F_86 ( V_94 ) ;
unsigned long V_96 ;
F_92 ( & V_52 -> V_98 , V_96 ) ;
V_52 -> V_99 ++ ;
F_93 ( & V_52 -> V_98 , V_96 ) ;
}
static int F_117 ( struct V_93 * V_94 ,
const char * V_113 , const char * V_114 )
{
struct V_51 * V_52 = F_86 ( V_94 ) ;
unsigned long V_115 ;
if ( F_118 ( V_114 , 10 , & V_115 ) )
return - V_116 ;
if ( ! strcasecmp ( V_113 , L_2 ) ) {
V_52 -> V_92 . V_12 [ V_8 ] = V_115 ;
} else if ( ! strcasecmp ( V_113 , L_3 ) ) {
V_52 -> V_92 . V_12 [ V_13 ] = V_115 ;
} else if ( ! strcasecmp ( V_113 , L_4 ) )
V_52 -> V_78 = V_115 ;
else if ( ! strcasecmp ( V_113 , L_5 ) )
V_52 -> V_77 = V_115 ;
else if ( ! strcasecmp ( V_113 , L_6 ) )
V_52 -> V_79 = V_115 ;
else
return - V_116 ;
return 0 ;
}
static int F_119 ( struct V_93 * V_94 , char * V_81 , unsigned V_117 )
{
T_6 V_118 = 0 ;
struct V_51 * V_52 = F_86 ( V_94 ) ;
F_120 ( L_7
L_8
L_9
L_10
L_11 ,
V_52 -> V_92 . V_12 [ V_8 ] ,
V_52 -> V_92 . V_12 [ V_13 ] ,
V_52 -> V_78 ,
V_52 -> V_77 ,
V_52 -> V_79 ) ;
return 0 ;
}
static void F_121 ( struct V_51 * V_52 )
{
V_52 -> V_95 . V_119 = F_87 ;
V_52 -> V_95 . F_85 = F_94 ;
V_52 -> V_95 . V_120 = F_99 ;
V_52 -> V_95 . V_121 = F_101 ;
V_52 -> V_95 . V_122 = F_102 ;
V_52 -> V_95 . V_123 = F_103 ;
V_52 -> V_95 . V_124 = F_105 ;
V_52 -> V_95 . V_125 = F_107 ;
V_52 -> V_95 . V_126 = F_109 ;
V_52 -> V_95 . V_127 = F_112 ;
V_52 -> V_95 . V_128 = F_114 ;
V_52 -> V_95 . V_129 = F_115 ;
V_52 -> V_95 . V_97 = F_116 ;
V_52 -> V_95 . V_130 = F_119 ;
V_52 -> V_95 . V_131 = F_117 ;
}
static struct V_93 * F_122 ( T_2 V_108 ,
T_7 V_132 ,
T_7 V_133 )
{
struct V_51 * V_52 = F_123 ( sizeof( * V_52 ) , V_134 ) ;
if ( ! V_52 )
return NULL ;
F_121 ( V_52 ) ;
F_4 ( & V_52 -> V_92 , V_135 , V_136 ) ;
V_52 -> V_108 = V_108 ;
if ( F_34 ( & V_52 -> V_89 , F_44 ( V_108 ) ) ) {
F_124 ( L_12 ) ;
goto V_137;
}
if ( F_34 ( & V_52 -> V_58 , F_44 ( V_108 ) ) ) {
F_124 ( L_13 ) ;
goto V_138;
}
V_52 -> V_99 = 0 ;
V_52 -> V_97 = 0 ;
V_52 -> V_60 = 0 ;
V_52 -> V_69 = 0 ;
V_52 -> V_78 = V_139 ;
V_52 -> V_77 = V_140 ;
V_52 -> V_79 = V_141 ;
F_125 ( & V_52 -> V_101 ) ;
F_126 ( & V_52 -> V_98 ) ;
F_12 ( & V_52 -> V_63 ) ;
F_12 ( & V_52 -> V_59 ) ;
F_12 ( & V_52 -> V_62 ) ;
V_52 -> V_68 = F_3 ( ( unsigned ) F_44 ( V_108 ) , 1024U ) ;
V_52 -> V_142 = F_1 ( F_44 ( V_108 ) / 2 , 16 ) ;
V_52 -> V_54 = F_127 ( V_52 -> V_142 ) - 1 ;
V_52 -> V_55 = F_35 ( sizeof( * V_52 -> V_55 ) * V_52 -> V_142 ) ;
if ( ! V_52 -> V_55 )
goto V_143;
return & V_52 -> V_95 ;
V_143:
F_37 ( & V_52 -> V_58 ) ;
V_138:
F_37 ( & V_52 -> V_89 ) ;
V_137:
F_88 ( V_52 ) ;
return NULL ;
}
static int T_8 F_128 ( void )
{
int V_32 ;
V_144 = F_129 ( L_14 ,
sizeof( struct V_43 ) ,
F_130 ( struct V_43 ) ,
0 , NULL ) ;
if ( ! V_144 )
goto V_145;
V_32 = F_131 ( & V_146 ) ;
if ( V_32 ) {
F_124 ( L_15 , V_32 ) ;
goto V_147;
}
V_32 = F_131 ( & V_148 ) ;
if ( ! V_32 ) {
F_132 ( L_16 ,
V_146 . V_149 [ 0 ] ,
V_146 . V_149 [ 1 ] ,
V_146 . V_149 [ 2 ] ) ;
return 0 ;
}
F_124 ( L_17 , V_32 ) ;
F_133 ( & V_146 ) ;
V_147:
F_134 ( V_144 ) ;
V_145:
return - V_44 ;
}
static void T_9 F_135 ( void )
{
F_133 ( & V_146 ) ;
F_133 ( & V_148 ) ;
F_134 ( V_144 ) ;
}
