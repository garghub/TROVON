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
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ )
F_13 ( V_19 -> V_22 + V_20 ) ;
}
static bool F_14 ( struct V_18 * V_19 )
{
unsigned V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ )
if ( ! F_15 ( V_19 -> V_22 + V_20 ) )
return false ;
return true ;
}
static void F_16 ( struct V_18 * V_19 , unsigned V_23 , struct V_24 * V_25 )
{
F_17 ( V_25 , V_19 -> V_22 + V_23 ) ;
}
static void F_18 ( struct V_24 * V_25 )
{
F_19 ( V_25 ) ;
}
static void F_20 ( struct V_18 * V_19 )
{
unsigned V_23 ;
for ( V_23 = 1 ; V_23 < V_21 ; V_23 ++ )
F_21 ( V_19 -> V_22 + V_23 , V_19 -> V_22 + V_23 - 1 ) ;
}
static struct V_24 * F_22 ( struct V_18 * V_19 )
{
unsigned V_23 ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ )
if ( ! F_15 ( V_19 -> V_22 + V_23 ) )
return V_19 -> V_22 [ V_23 ] . V_26 ;
return NULL ;
}
static struct V_24 * F_23 ( struct V_18 * V_19 )
{
struct V_24 * V_27 = F_22 ( V_19 ) ;
if ( V_27 ) {
F_19 ( V_27 ) ;
if ( F_15 ( V_19 -> V_22 ) )
F_20 ( V_19 ) ;
}
return V_27 ;
}
static struct V_24 * F_24 ( struct V_24 * V_28 )
{
struct V_24 * V_27 = V_28 -> V_26 ;
F_25 ( ! V_27 ) ;
F_26 ( V_27 ) ;
return V_27 ;
}
static int F_27 ( struct V_29 * V_30 , unsigned V_31 )
{
unsigned V_20 ;
V_30 -> V_32 = F_28 ( sizeof( struct V_33 ) * V_31 ) ;
if ( ! V_30 -> V_32 )
return - V_34 ;
V_30 -> V_35 = V_30 -> V_32 + V_31 ;
F_13 ( & V_30 -> free ) ;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ )
F_29 ( & V_30 -> V_32 [ V_20 ] . V_36 , & V_30 -> free ) ;
V_30 -> V_37 = 0 ;
return 0 ;
}
static void F_30 ( struct V_29 * V_30 )
{
F_31 ( V_30 -> V_32 ) ;
}
static struct V_33 * F_32 ( struct V_29 * V_30 )
{
struct V_33 * V_38 ;
if ( F_15 ( & V_30 -> free ) )
return NULL ;
V_38 = F_33 ( F_24 ( & V_30 -> free ) , struct V_33 , V_36 ) ;
F_13 ( & V_38 -> V_36 ) ;
F_34 ( & V_38 -> V_39 ) ;
V_30 -> V_37 ++ ;
return V_38 ;
}
static struct V_33 * F_35 ( struct V_29 * V_30 , T_1 V_40 )
{
struct V_33 * V_38 = V_30 -> V_32 + F_36 ( V_40 ) ;
F_26 ( & V_38 -> V_36 ) ;
F_34 ( & V_38 -> V_39 ) ;
V_30 -> V_37 ++ ;
return V_38 ;
}
static void F_37 ( struct V_29 * V_30 , struct V_33 * V_38 )
{
F_25 ( ! V_30 -> V_37 ) ;
V_30 -> V_37 -- ;
F_34 ( & V_38 -> V_39 ) ;
F_29 ( & V_38 -> V_36 , & V_30 -> free ) ;
}
static struct V_33 * F_38 ( struct V_29 * V_30 , T_1 V_40 )
{
struct V_33 * V_38 = V_30 -> V_32 + F_36 ( V_40 ) ;
return ! F_39 ( & V_38 -> V_39 ) ? V_38 : NULL ;
}
static bool F_40 ( struct V_29 * V_30 )
{
return F_15 ( & V_30 -> free ) ;
}
static bool F_41 ( struct V_29 * V_30 , struct V_33 * V_38 )
{
return V_38 >= V_30 -> V_32 && V_38 < V_30 -> V_35 ;
}
static T_1 F_42 ( struct V_29 * V_30 , struct V_33 * V_38 )
{
return F_43 ( V_38 - V_30 -> V_32 ) ;
}
static void F_44 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
unsigned V_43 = F_45 ( F_7 ( V_38 -> V_44 ) , V_42 -> V_45 ) ;
F_46 ( & V_38 -> V_39 , V_42 -> V_46 + V_43 ) ;
}
static struct V_33 * F_47 ( struct V_41 * V_42 , T_2 V_44 )
{
unsigned V_43 = F_45 ( F_7 ( V_44 ) , V_42 -> V_45 ) ;
struct V_47 * V_48 = V_42 -> V_46 + V_43 ;
struct V_33 * V_38 ;
F_48 (e, bucket, hlist)
if ( V_38 -> V_44 == V_44 ) {
F_49 ( & V_38 -> V_39 ) ;
F_46 ( & V_38 -> V_39 , V_48 ) ;
return V_38 ;
}
return NULL ;
}
static void F_50 ( struct V_33 * V_38 )
{
F_49 ( & V_38 -> V_39 ) ;
}
static bool F_51 ( struct V_41 * V_42 )
{
return ! F_40 ( & V_42 -> V_49 ) ;
}
static bool F_52 ( struct V_41 * V_42 )
{
return ! F_14 ( & V_42 -> V_50 ) ;
}
static unsigned F_53 ( struct V_33 * V_38 )
{
return V_2 ( ( unsigned ) F_54 ( V_38 -> V_51 ) , V_21 - 1u ) ;
}
static bool F_55 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
return F_41 ( & V_42 -> V_49 , V_38 ) ;
}
static void F_56 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
V_38 -> V_52 = V_42 -> V_52 ;
F_44 ( V_42 , V_38 ) ;
if ( F_55 ( V_42 , V_38 ) )
F_16 ( V_38 -> V_53 ? & V_42 -> V_54 : & V_42 -> V_50 ,
F_53 ( V_38 ) , & V_38 -> V_36 ) ;
else
F_16 ( & V_42 -> V_55 , F_53 ( V_38 ) , & V_38 -> V_36 ) ;
}
static void F_57 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
F_18 ( & V_38 -> V_36 ) ;
F_50 ( V_38 ) ;
}
static struct V_33 * F_58 ( struct V_41 * V_42 , struct V_18 * V_19 )
{
struct V_33 * V_38 ;
struct V_24 * V_43 = F_23 ( V_19 ) ;
if ( ! V_43 )
return NULL ;
V_38 = F_59 ( V_43 , struct V_33 , V_36 ) ;
F_50 ( V_38 ) ;
return V_38 ;
}
static struct V_33 * F_60 ( struct V_18 * V_19 )
{
struct V_24 * V_43 = F_22 ( V_19 ) ;
return V_43 ? F_59 ( V_43 , struct V_33 , V_36 ) : NULL ;
}
static bool F_61 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
return V_42 -> V_52 == V_38 -> V_52 ;
}
static void F_62 ( struct V_41 * V_42 )
{
unsigned V_56 = 0 , V_57 = 0 , V_58 = 0 , V_23 ;
struct V_24 * V_59 ;
struct V_33 * V_38 ;
if ( ( V_42 -> V_51 >= V_42 -> V_60 ) && ( F_40 ( & V_42 -> V_49 ) ) ) {
V_42 -> V_51 = 0 ;
V_42 -> V_61 ++ ;
for ( V_23 = 0 ; V_23 < V_21 && V_58 < V_62 ; V_23 ++ ) {
V_59 = V_42 -> V_50 . V_22 + V_23 ;
F_63 (e, head, list) {
V_57 ++ ;
V_56 += V_38 -> V_51 ;
if ( ++ V_58 >= V_62 )
break;
}
V_59 = V_42 -> V_54 . V_22 + V_23 ;
F_63 (e, head, list) {
V_57 ++ ;
V_56 += V_38 -> V_51 ;
if ( ++ V_58 >= V_62 )
break;
}
}
}
}
static void F_64 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
if ( F_61 ( V_42 , V_38 ) )
return;
V_38 -> V_51 ++ ;
V_42 -> V_51 ++ ;
F_62 ( V_42 ) ;
V_38 -> V_61 = V_42 -> V_61 ;
F_57 ( V_42 , V_38 ) ;
F_56 ( V_42 , V_38 ) ;
}
static int F_65 ( struct V_41 * V_42 , T_2 * V_44 )
{
struct V_33 * V_63 = F_58 ( V_42 , & V_42 -> V_50 ) ;
if ( ! V_63 )
return - V_64 ;
* V_44 = V_63 -> V_44 ;
F_37 ( & V_42 -> V_49 , V_63 ) ;
return 0 ;
}
static unsigned F_66 ( struct V_41 * V_42 )
{
struct V_33 * V_38 ;
if ( F_51 ( V_42 ) )
return 0 ;
V_38 = F_60 ( & V_42 -> V_50 ) ;
if ( V_38 )
return V_38 -> V_51 ;
V_38 = F_60 ( & V_42 -> V_54 ) ;
if ( V_38 )
return V_38 -> V_51 + V_65 ;
return 0 ;
}
static unsigned F_67 ( struct V_41 * V_42 ,
bool V_66 , int V_67 )
{
if ( V_67 == V_68 )
return F_66 ( V_42 ) + V_42 -> V_69 ;
if ( V_66 && ( F_51 ( V_42 ) || F_52 ( V_42 ) ) ) {
return V_42 -> V_70 ;
}
return F_66 ( V_42 ) + V_42 -> V_71 ;
}
static bool F_68 ( struct V_41 * V_42 , struct V_33 * V_38 ,
bool V_66 , int V_67 )
{
return V_38 -> V_51 >=
F_67 ( V_42 , V_66 , V_67 ) ;
}
static int F_69 ( struct V_41 * V_42 ,
struct V_33 * V_38 ,
struct V_72 * V_73 )
{
F_64 ( V_42 , V_38 ) ;
if ( F_55 ( V_42 , V_38 ) ) {
V_73 -> V_74 = V_75 ;
V_73 -> V_40 = F_42 ( & V_42 -> V_49 , V_38 ) ;
}
return 0 ;
}
static int F_70 ( struct V_41 * V_42 , struct V_33 * V_38 ,
struct V_72 * V_73 )
{
int V_27 ;
struct V_33 * V_76 ;
if ( F_40 ( & V_42 -> V_49 ) ) {
V_73 -> V_74 = V_77 ;
V_27 = F_65 ( V_42 , & V_73 -> V_78 ) ;
if ( V_27 ) {
V_73 -> V_74 = V_79 ;
return 0 ;
}
} else
V_73 -> V_74 = V_80 ;
V_76 = F_32 ( & V_42 -> V_49 ) ;
F_25 ( ! V_76 ) ;
V_76 -> V_44 = V_38 -> V_44 ;
V_76 -> V_53 = false ;
V_76 -> V_51 = V_38 -> V_51 ;
V_76 -> V_61 = V_38 -> V_61 ;
V_76 -> V_52 = V_38 -> V_52 ;
F_57 ( V_42 , V_38 ) ;
F_37 ( & V_42 -> V_81 , V_38 ) ;
F_56 ( V_42 , V_76 ) ;
V_73 -> V_40 = F_42 ( & V_42 -> V_49 , V_76 ) ;
return 0 ;
}
static int F_71 ( struct V_41 * V_42 , struct V_33 * V_38 ,
bool V_82 , bool V_66 ,
int V_67 , struct V_72 * V_73 )
{
int V_27 = 0 ;
bool V_83 = F_61 ( V_42 , V_38 ) ;
if ( ( ! V_66 && V_83 ) ||
! F_68 ( V_42 , V_38 , V_66 , V_67 ) ) {
F_64 ( V_42 , V_38 ) ;
V_73 -> V_74 = V_79 ;
} else if ( ! V_82 )
V_27 = - V_84 ;
else {
F_64 ( V_42 , V_38 ) ;
V_27 = F_70 ( V_42 , V_38 , V_73 ) ;
}
return V_27 ;
}
static void F_72 ( struct V_41 * V_42 ,
T_2 V_44 )
{
struct V_33 * V_38 = F_32 ( & V_42 -> V_81 ) ;
if ( ! V_38 )
V_38 = F_58 ( V_42 , & V_42 -> V_55 ) ;
if ( F_73 ( ! V_38 ) ) {
F_74 ( L_1 ) ;
return;
}
V_38 -> V_53 = false ;
V_38 -> V_44 = V_44 ;
V_38 -> V_51 = 1 ;
V_38 -> V_61 = V_42 -> V_61 ;
F_56 ( V_42 , V_38 ) ;
}
static void F_75 ( struct V_41 * V_42 , T_2 V_44 ,
struct V_72 * V_73 )
{
int V_27 ;
struct V_33 * V_38 ;
if ( F_40 ( & V_42 -> V_49 ) ) {
V_73 -> V_74 = V_77 ;
V_27 = F_65 ( V_42 , & V_73 -> V_78 ) ;
if ( F_73 ( V_27 ) ) {
V_73 -> V_74 = V_79 ;
F_72 ( V_42 , V_44 ) ;
return;
}
V_38 = F_32 ( & V_42 -> V_49 ) ;
F_25 ( ! V_38 ) ;
} else {
V_38 = F_32 ( & V_42 -> V_49 ) ;
V_73 -> V_74 = V_80 ;
}
V_38 -> V_44 = V_44 ;
V_38 -> V_53 = false ;
V_38 -> V_51 = 1 ;
V_38 -> V_61 = V_42 -> V_61 ;
F_56 ( V_42 , V_38 ) ;
V_73 -> V_40 = F_42 ( & V_42 -> V_49 , V_38 ) ;
}
static int F_76 ( struct V_41 * V_42 , T_2 V_44 ,
bool V_82 , bool V_66 ,
int V_67 , struct V_72 * V_73 )
{
if ( F_67 ( V_42 , V_66 , V_67 ) <= 1 ) {
if ( V_82 )
F_75 ( V_42 , V_44 , V_73 ) ;
else
return - V_84 ;
} else {
F_72 ( V_42 , V_44 ) ;
V_73 -> V_74 = V_79 ;
}
return 0 ;
}
static int F_77 ( struct V_41 * V_42 , T_2 V_44 ,
bool V_82 , bool V_66 ,
int V_67 , struct V_72 * V_73 )
{
int V_27 = 0 ;
struct V_33 * V_38 = F_47 ( V_42 , V_44 ) ;
if ( V_38 && F_55 ( V_42 , V_38 ) )
V_27 = F_69 ( V_42 , V_38 , V_73 ) ;
else if ( V_42 -> V_85 . V_12 [ V_13 ] &&
F_5 ( & V_42 -> V_85 ) == V_13 )
V_73 -> V_74 = V_79 ;
else if ( V_38 )
V_27 = F_71 ( V_42 , V_38 , V_82 , V_66 ,
V_67 , V_73 ) ;
else
V_27 = F_76 ( V_42 , V_44 , V_82 , V_66 ,
V_67 , V_73 ) ;
if ( V_27 == - V_84 )
V_73 -> V_74 = V_79 ;
return V_27 ;
}
static struct V_41 * F_78 ( struct V_86 * V_87 )
{
return F_59 ( V_87 , struct V_41 , V_88 ) ;
}
static void F_79 ( struct V_86 * V_87 )
{
struct V_41 * V_42 = F_78 ( V_87 ) ;
F_31 ( V_42 -> V_46 ) ;
F_30 ( & V_42 -> V_49 ) ;
F_30 ( & V_42 -> V_81 ) ;
F_80 ( V_42 ) ;
}
static void F_81 ( struct V_41 * V_42 )
{
unsigned long V_89 ;
F_82 ( & V_42 -> V_90 , V_89 ) ;
V_42 -> V_52 = V_42 -> V_91 ;
F_83 ( & V_42 -> V_90 , V_89 ) ;
}
static int F_84 ( struct V_86 * V_87 , T_2 V_44 ,
bool V_92 , bool V_82 , bool V_66 ,
struct V_15 * V_15 , struct V_72 * V_73 )
{
int V_27 ;
struct V_41 * V_42 = F_78 ( V_87 ) ;
V_73 -> V_74 = V_79 ;
if ( V_92 )
F_85 ( & V_42 -> V_93 ) ;
else if ( ! F_86 ( & V_42 -> V_93 ) )
return - V_84 ;
F_81 ( V_42 ) ;
F_11 ( & V_42 -> V_85 , V_15 ) ;
V_27 = F_77 ( V_42 , V_44 , V_82 , V_66 ,
F_87 ( V_15 ) , V_73 ) ;
F_88 ( & V_42 -> V_93 ) ;
return V_27 ;
}
static int F_89 ( struct V_86 * V_87 , T_2 V_44 , T_1 * V_40 )
{
int V_27 ;
struct V_41 * V_42 = F_78 ( V_87 ) ;
struct V_33 * V_38 ;
if ( ! F_86 ( & V_42 -> V_93 ) )
return - V_84 ;
V_38 = F_47 ( V_42 , V_44 ) ;
if ( V_38 && F_55 ( V_42 , V_38 ) ) {
* V_40 = F_42 ( & V_42 -> V_49 , V_38 ) ;
V_27 = 0 ;
} else
V_27 = - V_94 ;
F_88 ( & V_42 -> V_93 ) ;
return V_27 ;
}
static void F_90 ( struct V_41 * V_42 , T_2 V_44 , bool V_95 )
{
struct V_33 * V_38 ;
V_38 = F_47 ( V_42 , V_44 ) ;
F_25 ( ! V_38 || ! F_55 ( V_42 , V_38 ) ) ;
F_57 ( V_42 , V_38 ) ;
V_38 -> V_53 = V_95 ;
F_56 ( V_42 , V_38 ) ;
}
static void F_91 ( struct V_86 * V_87 , T_2 V_44 )
{
struct V_41 * V_42 = F_78 ( V_87 ) ;
F_85 ( & V_42 -> V_93 ) ;
F_90 ( V_42 , V_44 , true ) ;
F_88 ( & V_42 -> V_93 ) ;
}
static void F_92 ( struct V_86 * V_87 , T_2 V_44 )
{
struct V_41 * V_42 = F_78 ( V_87 ) ;
F_85 ( & V_42 -> V_93 ) ;
F_90 ( V_42 , V_44 , false ) ;
F_88 ( & V_42 -> V_93 ) ;
}
static int F_93 ( struct V_86 * V_87 ,
T_2 V_44 , T_1 V_40 ,
T_3 V_96 , bool V_97 )
{
struct V_41 * V_42 = F_78 ( V_87 ) ;
struct V_33 * V_38 ;
V_38 = F_35 ( & V_42 -> V_49 , V_40 ) ;
V_38 -> V_44 = V_44 ;
V_38 -> V_53 = false ;
V_38 -> V_51 = V_97 ? V_96 : 1 ;
V_38 -> V_61 = V_42 -> V_61 ;
F_56 ( V_42 , V_38 ) ;
return 0 ;
}
static int F_94 ( struct V_41 * V_42 , struct V_18 * V_19 ,
T_4 V_98 , void * V_99 )
{
int V_27 ;
unsigned V_23 ;
struct V_33 * V_38 ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ )
F_63 (e, q->qs + level, list) {
V_27 = V_98 ( V_99 , F_42 ( & V_42 -> V_49 , V_38 ) ,
V_38 -> V_44 , V_38 -> V_51 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_95 ( struct V_86 * V_87 , T_4 V_98 ,
void * V_99 )
{
struct V_41 * V_42 = F_78 ( V_87 ) ;
int V_27 = 0 ;
F_85 ( & V_42 -> V_93 ) ;
V_27 = F_94 ( V_42 , & V_42 -> V_50 , V_98 , V_99 ) ;
if ( ! V_27 )
V_27 = F_94 ( V_42 , & V_42 -> V_54 , V_98 , V_99 ) ;
F_88 ( & V_42 -> V_93 ) ;
return V_27 ;
}
static void F_96 ( struct V_41 * V_42 , T_2 V_44 )
{
struct V_33 * V_38 ;
V_38 = F_47 ( V_42 , V_44 ) ;
F_25 ( ! V_38 || ! F_55 ( V_42 , V_38 ) ) ;
F_57 ( V_42 , V_38 ) ;
F_37 ( & V_42 -> V_49 , V_38 ) ;
}
static void F_97 ( struct V_86 * V_87 , T_2 V_44 )
{
struct V_41 * V_42 = F_78 ( V_87 ) ;
F_85 ( & V_42 -> V_93 ) ;
F_96 ( V_42 , V_44 ) ;
F_88 ( & V_42 -> V_93 ) ;
}
static int F_98 ( struct V_41 * V_42 , T_1 V_40 )
{
struct V_33 * V_38 = F_38 ( & V_42 -> V_49 , V_40 ) ;
if ( ! V_38 )
return - V_100 ;
F_57 ( V_42 , V_38 ) ;
F_37 ( & V_42 -> V_49 , V_38 ) ;
return 0 ;
}
static int F_99 ( struct V_86 * V_87 , T_1 V_40 )
{
int V_27 ;
struct V_41 * V_42 = F_78 ( V_87 ) ;
F_85 ( & V_42 -> V_93 ) ;
V_27 = F_98 ( V_42 , V_40 ) ;
F_88 ( & V_42 -> V_93 ) ;
return V_27 ;
}
static int F_100 ( struct V_41 * V_42 , T_2 * V_44 ,
T_1 * V_40 )
{
struct V_33 * V_38 = F_58 ( V_42 , & V_42 -> V_54 ) ;
if ( ! V_38 )
return - V_100 ;
* V_44 = V_38 -> V_44 ;
* V_40 = F_42 ( & V_42 -> V_49 , V_38 ) ;
V_38 -> V_53 = false ;
F_56 ( V_42 , V_38 ) ;
return 0 ;
}
static int F_101 ( struct V_86 * V_87 , T_2 * V_44 ,
T_1 * V_40 )
{
int V_27 ;
struct V_41 * V_42 = F_78 ( V_87 ) ;
F_85 ( & V_42 -> V_93 ) ;
V_27 = F_100 ( V_42 , V_44 , V_40 ) ;
F_88 ( & V_42 -> V_93 ) ;
return V_27 ;
}
static void F_102 ( struct V_41 * V_42 ,
T_2 V_101 , T_2 V_102 )
{
struct V_33 * V_38 = F_47 ( V_42 , V_101 ) ;
if ( V_38 && F_55 ( V_42 , V_38 ) ) {
F_57 ( V_42 , V_38 ) ;
V_38 -> V_44 = V_102 ;
V_38 -> V_53 = true ;
F_56 ( V_42 , V_38 ) ;
}
}
static void F_103 ( struct V_86 * V_87 ,
T_2 V_101 , T_2 V_102 )
{
struct V_41 * V_42 = F_78 ( V_87 ) ;
F_85 ( & V_42 -> V_93 ) ;
F_102 ( V_42 , V_101 , V_102 ) ;
F_88 ( & V_42 -> V_93 ) ;
}
static T_1 F_104 ( struct V_86 * V_87 )
{
T_1 V_27 ;
struct V_41 * V_42 = F_78 ( V_87 ) ;
F_85 ( & V_42 -> V_93 ) ;
V_27 = F_43 ( V_42 -> V_49 . V_37 ) ;
F_88 ( & V_42 -> V_93 ) ;
return V_27 ;
}
static void F_105 ( struct V_86 * V_87 )
{
struct V_41 * V_42 = F_78 ( V_87 ) ;
unsigned long V_89 ;
F_82 ( & V_42 -> V_90 , V_89 ) ;
V_42 -> V_91 ++ ;
F_83 ( & V_42 -> V_90 , V_89 ) ;
}
static int F_106 ( struct V_86 * V_87 ,
const char * V_103 , const char * V_104 )
{
struct V_41 * V_42 = F_78 ( V_87 ) ;
unsigned long V_105 ;
if ( F_107 ( V_104 , 10 , & V_105 ) )
return - V_106 ;
if ( ! strcasecmp ( V_103 , L_2 ) ) {
V_42 -> V_85 . V_12 [ V_8 ] = V_105 ;
} else if ( ! strcasecmp ( V_103 , L_3 ) ) {
V_42 -> V_85 . V_12 [ V_13 ] = V_105 ;
} else if ( ! strcasecmp ( V_103 , L_4 ) )
V_42 -> V_70 = V_105 ;
else if ( ! strcasecmp ( V_103 , L_5 ) )
V_42 -> V_69 = V_105 ;
else if ( ! strcasecmp ( V_103 , L_6 ) )
V_42 -> V_71 = V_105 ;
else
return - V_106 ;
return 0 ;
}
static int F_108 ( struct V_86 * V_87 , char * V_73 , unsigned V_107 )
{
T_5 V_108 = 0 ;
struct V_41 * V_42 = F_78 ( V_87 ) ;
F_109 ( L_7
L_8
L_9
L_10
L_11 ,
V_42 -> V_85 . V_12 [ V_8 ] ,
V_42 -> V_85 . V_12 [ V_13 ] ,
V_42 -> V_70 ,
V_42 -> V_69 ,
V_42 -> V_71 ) ;
return 0 ;
}
static void F_110 ( struct V_41 * V_42 )
{
V_42 -> V_88 . V_109 = F_79 ;
V_42 -> V_88 . F_77 = F_84 ;
V_42 -> V_88 . V_110 = F_89 ;
V_42 -> V_88 . V_111 = F_91 ;
V_42 -> V_88 . V_112 = F_92 ;
V_42 -> V_88 . V_113 = F_93 ;
V_42 -> V_88 . V_114 = F_95 ;
V_42 -> V_88 . V_115 = F_97 ;
V_42 -> V_88 . V_116 = F_99 ;
V_42 -> V_88 . V_117 = F_101 ;
V_42 -> V_88 . V_118 = F_103 ;
V_42 -> V_88 . V_119 = F_104 ;
V_42 -> V_88 . V_52 = F_105 ;
V_42 -> V_88 . V_120 = F_108 ;
V_42 -> V_88 . V_121 = F_106 ;
}
static struct V_86 * F_111 ( T_1 V_122 ,
T_6 V_123 ,
T_6 V_124 )
{
struct V_41 * V_42 = F_112 ( sizeof( * V_42 ) , V_125 ) ;
if ( ! V_42 )
return NULL ;
F_110 ( V_42 ) ;
F_4 ( & V_42 -> V_85 , V_126 , V_127 ) ;
V_42 -> V_122 = V_122 ;
if ( F_27 ( & V_42 -> V_81 , F_36 ( V_122 ) ) ) {
F_113 ( L_12 ) ;
goto V_128;
}
if ( F_27 ( & V_42 -> V_49 , F_36 ( V_122 ) ) ) {
F_113 ( L_13 ) ;
goto V_129;
}
V_42 -> V_91 = 0 ;
V_42 -> V_52 = 0 ;
V_42 -> V_51 = 0 ;
V_42 -> V_61 = 0 ;
V_42 -> V_70 = V_130 ;
V_42 -> V_69 = V_131 ;
V_42 -> V_71 = V_132 ;
F_114 ( & V_42 -> V_93 ) ;
F_115 ( & V_42 -> V_90 ) ;
F_12 ( & V_42 -> V_55 ) ;
F_12 ( & V_42 -> V_50 ) ;
F_12 ( & V_42 -> V_54 ) ;
V_42 -> V_60 = F_3 ( ( unsigned ) F_36 ( V_122 ) , 1024U ) ;
V_42 -> V_133 = F_1 ( F_36 ( V_122 ) / 2 , 16 ) ;
V_42 -> V_45 = F_116 ( V_42 -> V_133 ) - 1 ;
V_42 -> V_46 = F_28 ( sizeof( * V_42 -> V_46 ) * V_42 -> V_133 ) ;
if ( ! V_42 -> V_46 )
goto V_134;
return & V_42 -> V_88 ;
V_134:
F_30 ( & V_42 -> V_49 ) ;
V_129:
F_30 ( & V_42 -> V_81 ) ;
V_128:
F_80 ( V_42 ) ;
return NULL ;
}
static int T_7 F_117 ( void )
{
int V_27 ;
V_135 = F_118 ( L_14 ,
sizeof( struct V_33 ) ,
F_119 ( struct V_33 ) ,
0 , NULL ) ;
if ( ! V_135 )
goto V_136;
V_27 = F_120 ( & V_137 ) ;
if ( V_27 ) {
F_113 ( L_15 , V_27 ) ;
goto V_138;
}
V_27 = F_120 ( & V_139 ) ;
if ( ! V_27 ) {
F_121 ( L_16 ,
V_137 . V_140 [ 0 ] ,
V_137 . V_140 [ 1 ] ,
V_137 . V_140 [ 2 ] ) ;
return 0 ;
}
F_113 ( L_17 , V_27 ) ;
F_122 ( & V_137 ) ;
V_138:
F_123 ( V_135 ) ;
V_136:
return - V_34 ;
}
static void T_8 F_124 ( void )
{
F_122 ( & V_137 ) ;
F_122 ( & V_139 ) ;
F_123 ( V_135 ) ;
}
