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
struct V_24 * V_26 ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ )
if ( ! F_15 ( V_19 -> V_22 + V_23 ) ) {
V_26 = V_19 -> V_22 [ V_23 ] . V_27 ;
F_19 ( V_26 ) ;
if ( V_23 == 0 && F_15 ( V_19 -> V_22 ) )
F_20 ( V_19 ) ;
return V_26 ;
}
return NULL ;
}
static struct V_24 * F_23 ( struct V_24 * V_28 )
{
struct V_24 * V_26 = V_28 -> V_27 ;
F_24 ( ! V_26 ) ;
F_25 ( V_26 ) ;
return V_26 ;
}
static int F_26 ( struct V_29 * V_30 , unsigned V_31 )
{
unsigned V_20 ;
V_30 -> V_32 = F_27 ( sizeof( struct V_33 ) * V_31 ) ;
if ( ! V_30 -> V_32 )
return - V_34 ;
V_30 -> V_35 = V_30 -> V_32 + V_31 ;
F_13 ( & V_30 -> free ) ;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ )
F_28 ( & V_30 -> V_32 [ V_20 ] . V_36 , & V_30 -> free ) ;
V_30 -> V_37 = 0 ;
return 0 ;
}
static void F_29 ( struct V_29 * V_30 )
{
F_30 ( V_30 -> V_32 ) ;
}
static struct V_33 * F_31 ( struct V_29 * V_30 )
{
struct V_33 * V_38 ;
if ( F_15 ( & V_30 -> free ) )
return NULL ;
V_38 = F_32 ( F_23 ( & V_30 -> free ) , struct V_33 , V_36 ) ;
F_13 ( & V_38 -> V_36 ) ;
F_33 ( & V_38 -> V_39 ) ;
V_30 -> V_37 ++ ;
return V_38 ;
}
static struct V_33 * F_34 ( struct V_29 * V_30 , T_1 V_40 )
{
struct V_33 * V_38 = V_30 -> V_32 + F_35 ( V_40 ) ;
F_25 ( & V_38 -> V_36 ) ;
F_33 ( & V_38 -> V_39 ) ;
V_30 -> V_37 ++ ;
return V_38 ;
}
static void F_36 ( struct V_29 * V_30 , struct V_33 * V_38 )
{
F_24 ( ! V_30 -> V_37 ) ;
V_30 -> V_37 -- ;
F_33 ( & V_38 -> V_39 ) ;
F_28 ( & V_38 -> V_36 , & V_30 -> free ) ;
}
static struct V_33 * F_37 ( struct V_29 * V_30 , T_1 V_40 )
{
struct V_33 * V_38 = V_30 -> V_32 + F_35 ( V_40 ) ;
return ! F_38 ( & V_38 -> V_39 ) ? V_38 : NULL ;
}
static bool F_39 ( struct V_29 * V_30 )
{
return F_15 ( & V_30 -> free ) ;
}
static bool F_40 ( struct V_29 * V_30 , struct V_33 * V_38 )
{
return V_38 >= V_30 -> V_32 && V_38 < V_30 -> V_35 ;
}
static T_1 F_41 ( struct V_29 * V_30 , struct V_33 * V_38 )
{
return F_42 ( V_38 - V_30 -> V_32 ) ;
}
static void F_43 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
unsigned V_43 = F_44 ( F_7 ( V_38 -> V_44 ) , V_42 -> V_45 ) ;
F_45 ( & V_38 -> V_39 , V_42 -> V_46 + V_43 ) ;
}
static struct V_33 * F_46 ( struct V_41 * V_42 , T_2 V_44 )
{
unsigned V_43 = F_44 ( F_7 ( V_44 ) , V_42 -> V_45 ) ;
struct V_47 * V_48 = V_42 -> V_46 + V_43 ;
struct V_33 * V_38 ;
F_47 (e, bucket, hlist)
if ( V_38 -> V_44 == V_44 ) {
F_48 ( & V_38 -> V_39 ) ;
F_45 ( & V_38 -> V_39 , V_48 ) ;
return V_38 ;
}
return NULL ;
}
static void F_49 ( struct V_33 * V_38 )
{
F_48 ( & V_38 -> V_39 ) ;
}
static bool F_50 ( struct V_41 * V_42 )
{
return ! F_39 ( & V_42 -> V_49 ) ;
}
static bool F_51 ( struct V_41 * V_42 )
{
return ! F_14 ( & V_42 -> V_50 ) ;
}
static unsigned F_52 ( struct V_33 * V_38 )
{
return V_2 ( ( unsigned ) F_53 ( V_38 -> V_51 ) , V_21 - 1u ) ;
}
static bool F_54 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
return F_40 ( & V_42 -> V_49 , V_38 ) ;
}
static void F_55 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
V_38 -> V_52 = V_42 -> V_52 ;
F_43 ( V_42 , V_38 ) ;
if ( F_54 ( V_42 , V_38 ) )
F_16 ( V_38 -> V_53 ? & V_42 -> V_54 : & V_42 -> V_50 ,
F_52 ( V_38 ) , & V_38 -> V_36 ) ;
else
F_16 ( & V_42 -> V_55 , F_52 ( V_38 ) , & V_38 -> V_36 ) ;
}
static void F_56 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
F_18 ( & V_38 -> V_36 ) ;
F_49 ( V_38 ) ;
}
static struct V_33 * F_57 ( struct V_41 * V_42 , struct V_18 * V_19 )
{
struct V_33 * V_38 ;
struct V_24 * V_43 = F_22 ( V_19 ) ;
if ( ! V_43 )
return NULL ;
V_38 = F_58 ( V_43 , struct V_33 , V_36 ) ;
F_49 ( V_38 ) ;
return V_38 ;
}
static bool F_59 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
return V_42 -> V_52 == V_38 -> V_52 ;
}
static void F_60 ( struct V_41 * V_42 )
{
unsigned V_56 = 0 , V_57 = 0 , V_58 = 0 , V_23 ;
struct V_24 * V_59 ;
struct V_33 * V_38 ;
if ( ( V_42 -> V_51 >= V_42 -> V_60 ) && ( F_39 ( & V_42 -> V_49 ) ) ) {
V_42 -> V_51 = 0 ;
V_42 -> V_61 ++ ;
for ( V_23 = 0 ; V_23 < V_21 && V_58 < V_62 ; V_23 ++ ) {
V_59 = V_42 -> V_50 . V_22 + V_23 ;
F_61 (e, head, list) {
V_57 ++ ;
V_56 += V_38 -> V_51 ;
if ( ++ V_58 >= V_62 )
break;
}
V_59 = V_42 -> V_54 . V_22 + V_23 ;
F_61 (e, head, list) {
V_57 ++ ;
V_56 += V_38 -> V_51 ;
if ( ++ V_58 >= V_62 )
break;
}
}
V_42 -> V_63 = V_57 ? V_56 / V_57 : 1 ;
if ( V_42 -> V_63 * V_57 < V_56 )
V_42 -> V_63 ++ ;
}
}
static void F_62 ( struct V_41 * V_42 , struct V_33 * V_38 )
{
if ( F_59 ( V_42 , V_38 ) )
return;
V_38 -> V_51 ++ ;
V_42 -> V_51 ++ ;
F_60 ( V_42 ) ;
V_38 -> V_61 = V_42 -> V_61 ;
F_56 ( V_42 , V_38 ) ;
F_55 ( V_42 , V_38 ) ;
}
static int F_63 ( struct V_41 * V_42 , T_2 * V_44 )
{
struct V_33 * V_64 = F_57 ( V_42 , & V_42 -> V_50 ) ;
if ( ! V_64 )
return - V_65 ;
* V_44 = V_64 -> V_44 ;
F_36 ( & V_42 -> V_49 , V_64 ) ;
return 0 ;
}
static unsigned F_64 ( struct V_41 * V_42 ,
bool V_66 , int V_67 )
{
if ( V_67 == V_68 )
return V_42 -> V_63 + V_42 -> V_69 ;
if ( V_66 && ( F_50 ( V_42 ) || F_51 ( V_42 ) ) ) {
return V_42 -> V_70 ;
}
return V_42 -> V_63 + V_42 -> V_71 ;
}
static bool F_65 ( struct V_41 * V_42 , struct V_33 * V_38 ,
bool V_66 , int V_67 )
{
return V_38 -> V_51 >=
F_64 ( V_42 , V_66 , V_67 ) ;
}
static int F_66 ( struct V_41 * V_42 ,
struct V_33 * V_38 ,
struct V_72 * V_73 )
{
F_62 ( V_42 , V_38 ) ;
if ( F_54 ( V_42 , V_38 ) ) {
V_73 -> V_74 = V_75 ;
V_73 -> V_40 = F_41 ( & V_42 -> V_49 , V_38 ) ;
}
return 0 ;
}
static int F_67 ( struct V_41 * V_42 , struct V_33 * V_38 ,
struct V_72 * V_73 )
{
int V_26 ;
struct V_33 * V_76 ;
if ( F_39 ( & V_42 -> V_49 ) ) {
V_73 -> V_74 = V_77 ;
V_26 = F_63 ( V_42 , & V_73 -> V_78 ) ;
if ( V_26 ) {
V_73 -> V_74 = V_79 ;
return 0 ;
}
} else
V_73 -> V_74 = V_80 ;
V_76 = F_31 ( & V_42 -> V_49 ) ;
F_24 ( ! V_76 ) ;
V_76 -> V_44 = V_38 -> V_44 ;
V_76 -> V_53 = false ;
V_76 -> V_51 = V_38 -> V_51 ;
V_76 -> V_61 = V_38 -> V_61 ;
V_76 -> V_52 = V_38 -> V_52 ;
F_56 ( V_42 , V_38 ) ;
F_36 ( & V_42 -> V_81 , V_38 ) ;
F_55 ( V_42 , V_76 ) ;
V_73 -> V_40 = F_41 ( & V_42 -> V_49 , V_76 ) ;
return 0 ;
}
static int F_68 ( struct V_41 * V_42 , struct V_33 * V_38 ,
bool V_82 , bool V_66 ,
int V_67 , struct V_72 * V_73 )
{
int V_26 = 0 ;
bool V_83 = F_59 ( V_42 , V_38 ) ;
if ( ( ! V_66 && V_83 ) ||
! F_65 ( V_42 , V_38 , V_66 , V_67 ) ) {
F_62 ( V_42 , V_38 ) ;
V_73 -> V_74 = V_79 ;
} else if ( ! V_82 )
V_26 = - V_84 ;
else {
F_62 ( V_42 , V_38 ) ;
V_26 = F_67 ( V_42 , V_38 , V_73 ) ;
}
return V_26 ;
}
static void F_69 ( struct V_41 * V_42 ,
T_2 V_44 )
{
struct V_33 * V_38 = F_31 ( & V_42 -> V_81 ) ;
if ( ! V_38 )
V_38 = F_57 ( V_42 , & V_42 -> V_55 ) ;
if ( F_70 ( ! V_38 ) ) {
F_71 ( L_1 ) ;
return;
}
V_38 -> V_53 = false ;
V_38 -> V_44 = V_44 ;
V_38 -> V_51 = 1 ;
V_38 -> V_61 = V_42 -> V_61 ;
F_55 ( V_42 , V_38 ) ;
}
static void F_72 ( struct V_41 * V_42 , T_2 V_44 ,
struct V_72 * V_73 )
{
int V_26 ;
struct V_33 * V_38 ;
if ( F_39 ( & V_42 -> V_49 ) ) {
V_73 -> V_74 = V_77 ;
V_26 = F_63 ( V_42 , & V_73 -> V_78 ) ;
if ( F_70 ( V_26 ) ) {
V_73 -> V_74 = V_79 ;
F_69 ( V_42 , V_44 ) ;
return;
}
V_38 = F_31 ( & V_42 -> V_49 ) ;
F_24 ( ! V_38 ) ;
} else {
V_38 = F_31 ( & V_42 -> V_49 ) ;
V_73 -> V_74 = V_80 ;
}
V_38 -> V_44 = V_44 ;
V_38 -> V_53 = false ;
V_38 -> V_51 = 1 ;
V_38 -> V_61 = V_42 -> V_61 ;
F_55 ( V_42 , V_38 ) ;
V_73 -> V_40 = F_41 ( & V_42 -> V_49 , V_38 ) ;
}
static int F_73 ( struct V_41 * V_42 , T_2 V_44 ,
bool V_82 , bool V_66 ,
int V_67 , struct V_72 * V_73 )
{
if ( F_64 ( V_42 , V_66 , V_67 ) <= 1 ) {
if ( V_82 )
F_72 ( V_42 , V_44 , V_73 ) ;
else
return - V_84 ;
} else {
F_69 ( V_42 , V_44 ) ;
V_73 -> V_74 = V_79 ;
}
return 0 ;
}
static int F_74 ( struct V_41 * V_42 , T_2 V_44 ,
bool V_82 , bool V_66 ,
int V_67 , struct V_72 * V_73 )
{
int V_26 = 0 ;
struct V_33 * V_38 = F_46 ( V_42 , V_44 ) ;
if ( V_38 && F_54 ( V_42 , V_38 ) )
V_26 = F_66 ( V_42 , V_38 , V_73 ) ;
else if ( F_5 ( & V_42 -> V_85 ) == V_13 )
V_73 -> V_74 = V_79 ;
else if ( V_38 )
V_26 = F_68 ( V_42 , V_38 , V_82 , V_66 ,
V_67 , V_73 ) ;
else
V_26 = F_73 ( V_42 , V_44 , V_82 , V_66 ,
V_67 , V_73 ) ;
if ( V_26 == - V_84 )
V_73 -> V_74 = V_79 ;
return V_26 ;
}
static struct V_41 * F_75 ( struct V_86 * V_87 )
{
return F_58 ( V_87 , struct V_41 , V_88 ) ;
}
static void F_76 ( struct V_86 * V_87 )
{
struct V_41 * V_42 = F_75 ( V_87 ) ;
F_30 ( V_42 -> V_46 ) ;
F_29 ( & V_42 -> V_49 ) ;
F_29 ( & V_42 -> V_81 ) ;
F_77 ( V_42 ) ;
}
static void F_78 ( struct V_41 * V_42 )
{
unsigned long V_89 ;
F_79 ( & V_42 -> V_90 , V_89 ) ;
V_42 -> V_52 = V_42 -> V_91 ;
F_80 ( & V_42 -> V_90 , V_89 ) ;
}
static int F_81 ( struct V_86 * V_87 , T_2 V_44 ,
bool V_92 , bool V_82 , bool V_66 ,
struct V_15 * V_15 , struct V_72 * V_73 )
{
int V_26 ;
struct V_41 * V_42 = F_75 ( V_87 ) ;
V_73 -> V_74 = V_79 ;
if ( V_92 )
F_82 ( & V_42 -> V_93 ) ;
else if ( ! F_83 ( & V_42 -> V_93 ) )
return - V_84 ;
F_78 ( V_42 ) ;
F_11 ( & V_42 -> V_85 , V_15 ) ;
V_26 = F_74 ( V_42 , V_44 , V_82 , V_66 ,
F_84 ( V_15 ) , V_73 ) ;
F_85 ( & V_42 -> V_93 ) ;
return V_26 ;
}
static int F_86 ( struct V_86 * V_87 , T_2 V_44 , T_1 * V_40 )
{
int V_26 ;
struct V_41 * V_42 = F_75 ( V_87 ) ;
struct V_33 * V_38 ;
if ( ! F_83 ( & V_42 -> V_93 ) )
return - V_84 ;
V_38 = F_46 ( V_42 , V_44 ) ;
if ( V_38 && F_54 ( V_42 , V_38 ) ) {
* V_40 = F_41 ( & V_42 -> V_49 , V_38 ) ;
V_26 = 0 ;
} else
V_26 = - V_94 ;
F_85 ( & V_42 -> V_93 ) ;
return V_26 ;
}
static void F_87 ( struct V_41 * V_42 , T_2 V_44 , bool V_95 )
{
struct V_33 * V_38 ;
V_38 = F_46 ( V_42 , V_44 ) ;
F_24 ( ! V_38 || ! F_54 ( V_42 , V_38 ) ) ;
F_56 ( V_42 , V_38 ) ;
V_38 -> V_53 = V_95 ;
F_55 ( V_42 , V_38 ) ;
}
static void F_88 ( struct V_86 * V_87 , T_2 V_44 )
{
struct V_41 * V_42 = F_75 ( V_87 ) ;
F_82 ( & V_42 -> V_93 ) ;
F_87 ( V_42 , V_44 , true ) ;
F_85 ( & V_42 -> V_93 ) ;
}
static void F_89 ( struct V_86 * V_87 , T_2 V_44 )
{
struct V_41 * V_42 = F_75 ( V_87 ) ;
F_82 ( & V_42 -> V_93 ) ;
F_87 ( V_42 , V_44 , false ) ;
F_85 ( & V_42 -> V_93 ) ;
}
static int F_90 ( struct V_86 * V_87 ,
T_2 V_44 , T_1 V_40 ,
T_3 V_96 , bool V_97 )
{
struct V_41 * V_42 = F_75 ( V_87 ) ;
struct V_33 * V_38 ;
V_38 = F_34 ( & V_42 -> V_49 , V_40 ) ;
V_38 -> V_44 = V_44 ;
V_38 -> V_53 = false ;
V_38 -> V_51 = V_97 ? V_96 : 1 ;
V_38 -> V_61 = V_42 -> V_61 ;
F_55 ( V_42 , V_38 ) ;
return 0 ;
}
static int F_91 ( struct V_41 * V_42 , struct V_18 * V_19 ,
T_4 V_98 , void * V_99 )
{
int V_26 ;
unsigned V_23 ;
struct V_33 * V_38 ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ )
F_61 (e, q->qs + level, list) {
V_26 = V_98 ( V_99 , F_41 ( & V_42 -> V_49 , V_38 ) ,
V_38 -> V_44 , V_38 -> V_51 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_92 ( struct V_86 * V_87 , T_4 V_98 ,
void * V_99 )
{
struct V_41 * V_42 = F_75 ( V_87 ) ;
int V_26 = 0 ;
F_82 ( & V_42 -> V_93 ) ;
V_26 = F_91 ( V_42 , & V_42 -> V_50 , V_98 , V_99 ) ;
if ( ! V_26 )
V_26 = F_91 ( V_42 , & V_42 -> V_54 , V_98 , V_99 ) ;
F_85 ( & V_42 -> V_93 ) ;
return V_26 ;
}
static void F_93 ( struct V_41 * V_42 , T_2 V_44 )
{
struct V_33 * V_38 ;
V_38 = F_46 ( V_42 , V_44 ) ;
F_24 ( ! V_38 || ! F_54 ( V_42 , V_38 ) ) ;
F_56 ( V_42 , V_38 ) ;
F_36 ( & V_42 -> V_49 , V_38 ) ;
}
static void F_94 ( struct V_86 * V_87 , T_2 V_44 )
{
struct V_41 * V_42 = F_75 ( V_87 ) ;
F_82 ( & V_42 -> V_93 ) ;
F_93 ( V_42 , V_44 ) ;
F_85 ( & V_42 -> V_93 ) ;
}
static int F_95 ( struct V_41 * V_42 , T_1 V_40 )
{
struct V_33 * V_38 = F_37 ( & V_42 -> V_49 , V_40 ) ;
if ( ! V_38 )
return - V_100 ;
F_56 ( V_42 , V_38 ) ;
F_36 ( & V_42 -> V_49 , V_38 ) ;
return 0 ;
}
static int F_96 ( struct V_86 * V_87 , T_1 V_40 )
{
int V_26 ;
struct V_41 * V_42 = F_75 ( V_87 ) ;
F_82 ( & V_42 -> V_93 ) ;
V_26 = F_95 ( V_42 , V_40 ) ;
F_85 ( & V_42 -> V_93 ) ;
return V_26 ;
}
static int F_97 ( struct V_41 * V_42 , T_2 * V_44 ,
T_1 * V_40 )
{
struct V_33 * V_38 = F_57 ( V_42 , & V_42 -> V_54 ) ;
if ( ! V_38 )
return - V_100 ;
* V_44 = V_38 -> V_44 ;
* V_40 = F_41 ( & V_42 -> V_49 , V_38 ) ;
V_38 -> V_53 = false ;
F_55 ( V_42 , V_38 ) ;
return 0 ;
}
static int F_98 ( struct V_86 * V_87 , T_2 * V_44 ,
T_1 * V_40 )
{
int V_26 ;
struct V_41 * V_42 = F_75 ( V_87 ) ;
F_82 ( & V_42 -> V_93 ) ;
V_26 = F_97 ( V_42 , V_44 , V_40 ) ;
F_85 ( & V_42 -> V_93 ) ;
return V_26 ;
}
static void F_99 ( struct V_41 * V_42 ,
T_2 V_101 , T_2 V_102 )
{
struct V_33 * V_38 = F_46 ( V_42 , V_101 ) ;
if ( V_38 && F_54 ( V_42 , V_38 ) ) {
F_56 ( V_42 , V_38 ) ;
V_38 -> V_44 = V_102 ;
V_38 -> V_53 = true ;
F_55 ( V_42 , V_38 ) ;
}
}
static void F_100 ( struct V_86 * V_87 ,
T_2 V_101 , T_2 V_102 )
{
struct V_41 * V_42 = F_75 ( V_87 ) ;
F_82 ( & V_42 -> V_93 ) ;
F_99 ( V_42 , V_101 , V_102 ) ;
F_85 ( & V_42 -> V_93 ) ;
}
static T_1 F_101 ( struct V_86 * V_87 )
{
T_1 V_26 ;
struct V_41 * V_42 = F_75 ( V_87 ) ;
F_82 ( & V_42 -> V_93 ) ;
V_26 = F_42 ( V_42 -> V_49 . V_37 ) ;
F_85 ( & V_42 -> V_93 ) ;
return V_26 ;
}
static void F_102 ( struct V_86 * V_87 )
{
struct V_41 * V_42 = F_75 ( V_87 ) ;
unsigned long V_89 ;
F_79 ( & V_42 -> V_90 , V_89 ) ;
V_42 -> V_91 ++ ;
F_80 ( & V_42 -> V_90 , V_89 ) ;
}
static int F_103 ( struct V_86 * V_87 ,
const char * V_103 , const char * V_104 )
{
struct V_41 * V_42 = F_75 ( V_87 ) ;
unsigned long V_105 ;
if ( F_104 ( V_104 , 10 , & V_105 ) )
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
static int F_105 ( struct V_86 * V_87 , char * V_73 , unsigned V_107 )
{
T_5 V_108 = 0 ;
struct V_41 * V_42 = F_75 ( V_87 ) ;
F_106 ( L_7
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
static void F_107 ( struct V_41 * V_42 )
{
V_42 -> V_88 . V_109 = F_76 ;
V_42 -> V_88 . F_74 = F_81 ;
V_42 -> V_88 . V_110 = F_86 ;
V_42 -> V_88 . V_111 = F_88 ;
V_42 -> V_88 . V_112 = F_89 ;
V_42 -> V_88 . V_113 = F_90 ;
V_42 -> V_88 . V_114 = F_92 ;
V_42 -> V_88 . V_115 = F_94 ;
V_42 -> V_88 . V_116 = F_96 ;
V_42 -> V_88 . V_117 = F_98 ;
V_42 -> V_88 . V_118 = F_100 ;
V_42 -> V_88 . V_119 = F_101 ;
V_42 -> V_88 . V_52 = F_102 ;
V_42 -> V_88 . V_120 = F_105 ;
V_42 -> V_88 . V_121 = F_103 ;
}
static struct V_86 * F_108 ( T_1 V_122 ,
T_6 V_123 ,
T_6 V_124 )
{
struct V_41 * V_42 = F_109 ( sizeof( * V_42 ) , V_125 ) ;
if ( ! V_42 )
return NULL ;
F_107 ( V_42 ) ;
F_4 ( & V_42 -> V_85 , V_126 , V_127 ) ;
V_42 -> V_122 = V_122 ;
if ( F_26 ( & V_42 -> V_81 , F_35 ( V_122 ) ) ) {
F_110 ( L_12 ) ;
goto V_128;
}
if ( F_26 ( & V_42 -> V_49 , F_35 ( V_122 ) ) ) {
F_110 ( L_13 ) ;
goto V_129;
}
V_42 -> V_91 = 0 ;
V_42 -> V_52 = 0 ;
V_42 -> V_51 = 0 ;
V_42 -> V_61 = 0 ;
V_42 -> V_63 = 0 ;
V_42 -> V_70 = V_130 ;
V_42 -> V_69 = V_131 ;
V_42 -> V_71 = V_132 ;
F_111 ( & V_42 -> V_93 ) ;
F_112 ( & V_42 -> V_90 ) ;
F_12 ( & V_42 -> V_55 ) ;
F_12 ( & V_42 -> V_50 ) ;
F_12 ( & V_42 -> V_54 ) ;
V_42 -> V_60 = F_3 ( ( unsigned ) F_35 ( V_122 ) , 1024U ) ;
V_42 -> V_133 = F_1 ( F_35 ( V_122 ) / 2 , 16 ) ;
V_42 -> V_45 = F_113 ( V_42 -> V_133 ) - 1 ;
V_42 -> V_46 = F_27 ( sizeof( * V_42 -> V_46 ) * V_42 -> V_133 ) ;
if ( ! V_42 -> V_46 )
goto V_134;
return & V_42 -> V_88 ;
V_134:
F_29 ( & V_42 -> V_49 ) ;
V_129:
F_29 ( & V_42 -> V_81 ) ;
V_128:
F_77 ( V_42 ) ;
return NULL ;
}
static int T_7 F_114 ( void )
{
int V_26 ;
V_135 = F_115 ( L_14 ,
sizeof( struct V_33 ) ,
F_116 ( struct V_33 ) ,
0 , NULL ) ;
if ( ! V_135 )
goto V_136;
V_26 = F_117 ( & V_137 ) ;
if ( V_26 ) {
F_110 ( L_15 , V_26 ) ;
goto V_138;
}
V_26 = F_117 ( & V_139 ) ;
if ( ! V_26 ) {
F_118 ( L_16 ,
V_137 . V_140 [ 0 ] ,
V_137 . V_140 [ 1 ] ,
V_137 . V_140 [ 2 ] ) ;
return 0 ;
}
F_110 ( L_17 , V_26 ) ;
F_119 ( & V_137 ) ;
V_138:
F_120 ( V_135 ) ;
V_136:
return - V_34 ;
}
static void T_8 F_121 ( void )
{
F_119 ( & V_137 ) ;
F_119 ( & V_139 ) ;
F_120 ( V_135 ) ;
}
