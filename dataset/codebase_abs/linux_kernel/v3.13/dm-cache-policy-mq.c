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
if ( V_15 -> V_16 == F_7 ( V_4 -> V_11 ) + 1 )
V_4 -> V_9 ++ ;
else {
if ( V_4 -> V_9 ) {
V_4 -> V_9 = 0 ;
V_4 -> V_10 = 0 ;
}
V_4 -> V_10 ++ ;
}
V_4 -> V_11 = F_8 ( V_15 -> V_16 + F_9 ( V_15 ) - 1 ) ;
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
static void F_12 ( struct V_17 * V_18 )
{
unsigned V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
F_13 ( V_18 -> V_21 + V_19 ) ;
}
static bool F_14 ( struct V_17 * V_18 )
{
unsigned V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
if ( ! F_15 ( V_18 -> V_21 + V_19 ) )
return false ;
return true ;
}
static void F_16 ( struct V_17 * V_18 , unsigned V_22 , struct V_23 * V_24 )
{
F_17 ( V_24 , V_18 -> V_21 + V_22 ) ;
}
static void F_18 ( struct V_23 * V_24 )
{
F_19 ( V_24 ) ;
}
static void F_20 ( struct V_17 * V_18 )
{
unsigned V_22 ;
for ( V_22 = 1 ; V_22 < V_20 ; V_22 ++ )
F_21 ( V_18 -> V_21 + V_22 , V_18 -> V_21 + V_22 - 1 ) ;
}
static struct V_23 * F_22 ( struct V_17 * V_18 )
{
unsigned V_22 ;
struct V_23 * V_25 ;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ )
if ( ! F_15 ( V_18 -> V_21 + V_22 ) ) {
V_25 = V_18 -> V_21 [ V_22 ] . V_26 ;
F_19 ( V_25 ) ;
if ( V_22 == 0 && F_15 ( V_18 -> V_21 ) )
F_20 ( V_18 ) ;
return V_25 ;
}
return NULL ;
}
static struct V_23 * F_23 ( struct V_23 * V_27 )
{
struct V_23 * V_25 = V_27 -> V_26 ;
F_24 ( ! V_25 ) ;
F_25 ( V_25 ) ;
return V_25 ;
}
static int F_26 ( struct V_28 * V_29 , unsigned V_30 )
{
unsigned V_19 ;
V_29 -> V_31 = F_27 ( sizeof( struct V_32 ) * V_30 ) ;
if ( ! V_29 -> V_31 )
return - V_33 ;
V_29 -> V_34 = V_29 -> V_31 + V_30 ;
F_13 ( & V_29 -> free ) ;
for ( V_19 = 0 ; V_19 < V_30 ; V_19 ++ )
F_28 ( & V_29 -> V_31 [ V_19 ] . V_35 , & V_29 -> free ) ;
V_29 -> V_36 = 0 ;
return 0 ;
}
static void F_29 ( struct V_28 * V_29 )
{
F_30 ( V_29 -> V_31 ) ;
}
static struct V_32 * F_31 ( struct V_28 * V_29 )
{
struct V_32 * V_37 ;
if ( F_15 ( & V_29 -> free ) )
return NULL ;
V_37 = F_32 ( F_23 ( & V_29 -> free ) , struct V_32 , V_35 ) ;
F_13 ( & V_37 -> V_35 ) ;
F_33 ( & V_37 -> V_38 ) ;
V_29 -> V_36 ++ ;
return V_37 ;
}
static struct V_32 * F_34 ( struct V_28 * V_29 , T_1 V_39 )
{
struct V_32 * V_37 = V_29 -> V_31 + F_35 ( V_39 ) ;
F_19 ( & V_37 -> V_35 ) ;
F_13 ( & V_37 -> V_35 ) ;
F_33 ( & V_37 -> V_38 ) ;
V_29 -> V_36 ++ ;
return V_37 ;
}
static void F_36 ( struct V_28 * V_29 , struct V_32 * V_37 )
{
F_24 ( ! V_29 -> V_36 ) ;
V_29 -> V_36 -- ;
F_33 ( & V_37 -> V_38 ) ;
F_28 ( & V_37 -> V_35 , & V_29 -> free ) ;
}
static struct V_32 * F_37 ( struct V_28 * V_29 , T_1 V_39 )
{
struct V_32 * V_37 = V_29 -> V_31 + F_35 ( V_39 ) ;
return ! F_38 ( & V_37 -> V_38 ) ? V_37 : NULL ;
}
static bool F_39 ( struct V_28 * V_29 )
{
return F_15 ( & V_29 -> free ) ;
}
static bool F_40 ( struct V_28 * V_29 , struct V_32 * V_37 )
{
return V_37 >= V_29 -> V_31 && V_37 < V_29 -> V_34 ;
}
static T_1 F_41 ( struct V_28 * V_29 , struct V_32 * V_37 )
{
return F_42 ( V_37 - V_29 -> V_31 ) ;
}
static void F_43 ( struct V_40 * V_41 , struct V_32 * V_37 )
{
unsigned V_42 = F_44 ( F_7 ( V_37 -> V_43 ) , V_41 -> V_44 ) ;
F_45 ( & V_37 -> V_38 , V_41 -> V_45 + V_42 ) ;
}
static struct V_32 * F_46 ( struct V_40 * V_41 , T_2 V_43 )
{
unsigned V_42 = F_44 ( F_7 ( V_43 ) , V_41 -> V_44 ) ;
struct V_46 * V_47 = V_41 -> V_45 + V_42 ;
struct V_32 * V_37 ;
F_47 (e, bucket, hlist)
if ( V_37 -> V_43 == V_43 ) {
F_48 ( & V_37 -> V_38 ) ;
F_45 ( & V_37 -> V_38 , V_47 ) ;
return V_37 ;
}
return NULL ;
}
static void F_49 ( struct V_32 * V_37 )
{
F_48 ( & V_37 -> V_38 ) ;
}
static bool F_50 ( struct V_40 * V_41 )
{
return ! F_39 ( & V_41 -> V_48 ) ;
}
static bool F_51 ( struct V_40 * V_41 )
{
return ! F_14 ( & V_41 -> V_49 ) ;
}
static unsigned F_52 ( struct V_32 * V_37 )
{
return V_2 ( ( unsigned ) F_53 ( V_37 -> V_50 ) , V_20 - 1u ) ;
}
static bool F_54 ( struct V_40 * V_41 , struct V_32 * V_37 )
{
return F_40 ( & V_41 -> V_48 , V_37 ) ;
}
static void F_55 ( struct V_40 * V_41 , struct V_32 * V_37 )
{
V_37 -> V_51 = V_41 -> V_51 ;
F_43 ( V_41 , V_37 ) ;
if ( F_54 ( V_41 , V_37 ) )
F_16 ( V_37 -> V_52 ? & V_41 -> V_53 : & V_41 -> V_49 ,
F_52 ( V_37 ) , & V_37 -> V_35 ) ;
else
F_16 ( & V_41 -> V_54 , F_52 ( V_37 ) , & V_37 -> V_35 ) ;
}
static void F_56 ( struct V_40 * V_41 , struct V_32 * V_37 )
{
F_18 ( & V_37 -> V_35 ) ;
F_49 ( V_37 ) ;
}
static struct V_32 * F_57 ( struct V_40 * V_41 , struct V_17 * V_18 )
{
struct V_32 * V_37 ;
struct V_23 * V_42 = F_22 ( V_18 ) ;
if ( ! V_42 )
return NULL ;
V_37 = F_58 ( V_42 , struct V_32 , V_35 ) ;
F_49 ( V_37 ) ;
return V_37 ;
}
static bool F_59 ( struct V_40 * V_41 , struct V_32 * V_37 )
{
return V_41 -> V_51 == V_37 -> V_51 ;
}
static void F_60 ( struct V_40 * V_41 )
{
unsigned V_55 = 0 , V_56 = 0 , V_57 = 0 , V_22 ;
struct V_23 * V_58 ;
struct V_32 * V_37 ;
if ( ( V_41 -> V_50 >= V_41 -> V_59 ) && ( F_39 ( & V_41 -> V_48 ) ) ) {
V_41 -> V_50 = 0 ;
V_41 -> V_60 ++ ;
for ( V_22 = 0 ; V_22 < V_20 && V_57 < V_61 ; V_22 ++ ) {
V_58 = V_41 -> V_49 . V_21 + V_22 ;
F_61 (e, head, list) {
V_56 ++ ;
V_55 += V_37 -> V_50 ;
if ( ++ V_57 >= V_61 )
break;
}
V_58 = V_41 -> V_53 . V_21 + V_22 ;
F_61 (e, head, list) {
V_56 ++ ;
V_55 += V_37 -> V_50 ;
if ( ++ V_57 >= V_61 )
break;
}
}
V_41 -> V_62 = V_56 ? V_55 / V_56 : 1 ;
if ( V_41 -> V_62 * V_56 < V_55 )
V_41 -> V_62 ++ ;
}
}
static void F_62 ( struct V_40 * V_41 , struct V_32 * V_37 )
{
if ( F_59 ( V_41 , V_37 ) )
return;
V_37 -> V_50 ++ ;
V_41 -> V_50 ++ ;
F_60 ( V_41 ) ;
V_37 -> V_60 = V_41 -> V_60 ;
F_56 ( V_41 , V_37 ) ;
F_55 ( V_41 , V_37 ) ;
}
static int F_63 ( struct V_40 * V_41 , T_2 * V_43 )
{
struct V_32 * V_63 = F_57 ( V_41 , & V_41 -> V_49 ) ;
if ( ! V_63 )
return - V_64 ;
* V_43 = V_63 -> V_43 ;
F_36 ( & V_41 -> V_48 , V_63 ) ;
return 0 ;
}
static unsigned F_64 ( struct V_40 * V_41 ,
bool V_65 , int V_66 )
{
if ( V_66 == V_67 )
return V_41 -> V_62 + V_68 ;
if ( V_65 && ( F_50 ( V_41 ) || F_51 ( V_41 ) ) ) {
return V_69 ;
}
return V_41 -> V_62 + V_70 ;
}
static bool F_65 ( struct V_40 * V_41 , struct V_32 * V_37 ,
bool V_65 , int V_66 )
{
return V_37 -> V_50 >=
F_64 ( V_41 , V_65 , V_66 ) ;
}
static int F_66 ( struct V_40 * V_41 ,
struct V_32 * V_37 ,
struct V_71 * V_72 )
{
F_62 ( V_41 , V_37 ) ;
if ( F_54 ( V_41 , V_37 ) ) {
V_72 -> V_73 = V_74 ;
V_72 -> V_39 = F_41 ( & V_41 -> V_48 , V_37 ) ;
}
return 0 ;
}
static int F_67 ( struct V_40 * V_41 , struct V_32 * V_37 ,
struct V_71 * V_72 )
{
int V_25 ;
struct V_32 * V_75 ;
if ( F_39 ( & V_41 -> V_48 ) ) {
V_72 -> V_73 = V_76 ;
V_25 = F_63 ( V_41 , & V_72 -> V_77 ) ;
if ( V_25 ) {
V_72 -> V_73 = V_78 ;
return 0 ;
}
} else
V_72 -> V_73 = V_79 ;
V_75 = F_31 ( & V_41 -> V_48 ) ;
F_24 ( ! V_75 ) ;
V_75 -> V_43 = V_37 -> V_43 ;
V_75 -> V_52 = false ;
V_75 -> V_50 = V_37 -> V_50 ;
V_75 -> V_60 = V_37 -> V_60 ;
V_75 -> V_51 = V_37 -> V_51 ;
F_56 ( V_41 , V_37 ) ;
F_36 ( & V_41 -> V_80 , V_37 ) ;
F_55 ( V_41 , V_75 ) ;
V_72 -> V_39 = F_41 ( & V_41 -> V_48 , V_75 ) ;
return 0 ;
}
static int F_68 ( struct V_40 * V_41 , struct V_32 * V_37 ,
bool V_81 , bool V_65 ,
int V_66 , struct V_71 * V_72 )
{
int V_25 = 0 ;
bool V_82 = F_59 ( V_41 , V_37 ) ;
if ( ( ! V_65 && V_82 ) ||
! F_65 ( V_41 , V_37 , V_65 , V_66 ) ) {
F_62 ( V_41 , V_37 ) ;
V_72 -> V_73 = V_78 ;
} else if ( ! V_81 )
V_25 = - V_83 ;
else {
F_62 ( V_41 , V_37 ) ;
V_25 = F_67 ( V_41 , V_37 , V_72 ) ;
}
return V_25 ;
}
static void F_69 ( struct V_40 * V_41 ,
T_2 V_43 )
{
struct V_32 * V_37 = F_31 ( & V_41 -> V_80 ) ;
if ( ! V_37 )
V_37 = F_57 ( V_41 , & V_41 -> V_54 ) ;
if ( F_70 ( ! V_37 ) ) {
F_71 ( L_1 ) ;
return;
}
V_37 -> V_52 = false ;
V_37 -> V_43 = V_43 ;
V_37 -> V_50 = 1 ;
V_37 -> V_60 = V_41 -> V_60 ;
F_55 ( V_41 , V_37 ) ;
}
static void F_72 ( struct V_40 * V_41 , T_2 V_43 ,
struct V_71 * V_72 )
{
int V_25 ;
struct V_32 * V_37 ;
if ( F_39 ( & V_41 -> V_48 ) ) {
V_72 -> V_73 = V_76 ;
V_25 = F_63 ( V_41 , & V_72 -> V_77 ) ;
if ( F_70 ( V_25 ) ) {
V_72 -> V_73 = V_78 ;
F_69 ( V_41 , V_43 ) ;
return;
}
V_37 = F_31 ( & V_41 -> V_48 ) ;
F_24 ( ! V_37 ) ;
} else {
V_37 = F_31 ( & V_41 -> V_48 ) ;
V_72 -> V_73 = V_79 ;
}
V_37 -> V_43 = V_43 ;
V_37 -> V_52 = false ;
V_37 -> V_50 = 1 ;
V_37 -> V_60 = V_41 -> V_60 ;
F_55 ( V_41 , V_37 ) ;
V_72 -> V_39 = F_41 ( & V_41 -> V_48 , V_37 ) ;
}
static int F_73 ( struct V_40 * V_41 , T_2 V_43 ,
bool V_81 , bool V_65 ,
int V_66 , struct V_71 * V_72 )
{
if ( F_64 ( V_41 , V_65 , V_66 ) == 1 ) {
if ( V_81 )
F_72 ( V_41 , V_43 , V_72 ) ;
else
return - V_83 ;
} else {
F_69 ( V_41 , V_43 ) ;
V_72 -> V_73 = V_78 ;
}
return 0 ;
}
static int F_74 ( struct V_40 * V_41 , T_2 V_43 ,
bool V_81 , bool V_65 ,
int V_66 , struct V_71 * V_72 )
{
int V_25 = 0 ;
struct V_32 * V_37 = F_46 ( V_41 , V_43 ) ;
if ( V_37 && F_54 ( V_41 , V_37 ) )
V_25 = F_66 ( V_41 , V_37 , V_72 ) ;
else if ( F_5 ( & V_41 -> V_84 ) == V_13 )
V_72 -> V_73 = V_78 ;
else if ( V_37 )
V_25 = F_68 ( V_41 , V_37 , V_81 , V_65 ,
V_66 , V_72 ) ;
else
V_25 = F_73 ( V_41 , V_43 , V_81 , V_65 ,
V_66 , V_72 ) ;
if ( V_25 == - V_83 )
V_72 -> V_73 = V_78 ;
return V_25 ;
}
static struct V_40 * F_75 ( struct V_85 * V_86 )
{
return F_58 ( V_86 , struct V_40 , V_87 ) ;
}
static void F_76 ( struct V_85 * V_86 )
{
struct V_40 * V_41 = F_75 ( V_86 ) ;
F_77 ( V_41 -> V_45 ) ;
F_29 ( & V_41 -> V_48 ) ;
F_29 ( & V_41 -> V_80 ) ;
F_77 ( V_41 ) ;
}
static void F_78 ( struct V_40 * V_41 )
{
unsigned long V_88 ;
F_79 ( & V_41 -> V_89 , V_88 ) ;
V_41 -> V_51 = V_41 -> V_90 ;
F_80 ( & V_41 -> V_89 , V_88 ) ;
}
static int F_81 ( struct V_85 * V_86 , T_2 V_43 ,
bool V_91 , bool V_81 , bool V_65 ,
struct V_15 * V_15 , struct V_71 * V_72 )
{
int V_25 ;
struct V_40 * V_41 = F_75 ( V_86 ) ;
V_72 -> V_73 = V_78 ;
if ( V_91 )
F_82 ( & V_41 -> V_92 ) ;
else if ( ! F_83 ( & V_41 -> V_92 ) )
return - V_83 ;
F_78 ( V_41 ) ;
F_11 ( & V_41 -> V_84 , V_15 ) ;
V_25 = F_74 ( V_41 , V_43 , V_81 , V_65 ,
F_84 ( V_15 ) , V_72 ) ;
F_85 ( & V_41 -> V_92 ) ;
return V_25 ;
}
static int F_86 ( struct V_85 * V_86 , T_2 V_43 , T_1 * V_39 )
{
int V_25 ;
struct V_40 * V_41 = F_75 ( V_86 ) ;
struct V_32 * V_37 ;
if ( ! F_83 ( & V_41 -> V_92 ) )
return - V_83 ;
V_37 = F_46 ( V_41 , V_43 ) ;
if ( V_37 && F_54 ( V_41 , V_37 ) ) {
* V_39 = F_41 ( & V_41 -> V_48 , V_37 ) ;
V_25 = 0 ;
} else
V_25 = - V_93 ;
F_85 ( & V_41 -> V_92 ) ;
return V_25 ;
}
static void F_87 ( struct V_40 * V_41 , T_2 V_43 , bool V_94 )
{
struct V_32 * V_37 ;
V_37 = F_46 ( V_41 , V_43 ) ;
F_24 ( ! V_37 || ! F_54 ( V_41 , V_37 ) ) ;
F_56 ( V_41 , V_37 ) ;
V_37 -> V_52 = V_94 ;
F_55 ( V_41 , V_37 ) ;
}
static void F_88 ( struct V_85 * V_86 , T_2 V_43 )
{
struct V_40 * V_41 = F_75 ( V_86 ) ;
F_82 ( & V_41 -> V_92 ) ;
F_87 ( V_41 , V_43 , true ) ;
F_85 ( & V_41 -> V_92 ) ;
}
static void F_89 ( struct V_85 * V_86 , T_2 V_43 )
{
struct V_40 * V_41 = F_75 ( V_86 ) ;
F_82 ( & V_41 -> V_92 ) ;
F_87 ( V_41 , V_43 , false ) ;
F_85 ( & V_41 -> V_92 ) ;
}
static int F_90 ( struct V_85 * V_86 ,
T_2 V_43 , T_1 V_39 ,
T_3 V_95 , bool V_96 )
{
struct V_40 * V_41 = F_75 ( V_86 ) ;
struct V_32 * V_37 ;
V_37 = F_34 ( & V_41 -> V_48 , V_39 ) ;
V_37 -> V_43 = V_43 ;
V_37 -> V_52 = false ;
V_37 -> V_50 = V_96 ? V_95 : 1 ;
V_37 -> V_60 = V_41 -> V_60 ;
F_55 ( V_41 , V_37 ) ;
return 0 ;
}
static int F_91 ( struct V_40 * V_41 , struct V_17 * V_18 ,
T_4 V_97 , void * V_98 )
{
int V_25 ;
unsigned V_22 ;
struct V_32 * V_37 ;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ )
F_61 (e, q->qs + level, list) {
V_25 = V_97 ( V_98 , F_41 ( & V_41 -> V_48 , V_37 ) ,
V_37 -> V_43 , V_37 -> V_50 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
static int F_92 ( struct V_85 * V_86 , T_4 V_97 ,
void * V_98 )
{
struct V_40 * V_41 = F_75 ( V_86 ) ;
int V_25 = 0 ;
F_82 ( & V_41 -> V_92 ) ;
V_25 = F_91 ( V_41 , & V_41 -> V_49 , V_97 , V_98 ) ;
if ( ! V_25 )
V_25 = F_91 ( V_41 , & V_41 -> V_53 , V_97 , V_98 ) ;
F_85 ( & V_41 -> V_92 ) ;
return V_25 ;
}
static void F_93 ( struct V_40 * V_41 , T_2 V_43 )
{
struct V_32 * V_37 ;
V_37 = F_46 ( V_41 , V_43 ) ;
F_24 ( ! V_37 || ! F_54 ( V_41 , V_37 ) ) ;
F_56 ( V_41 , V_37 ) ;
F_36 ( & V_41 -> V_48 , V_37 ) ;
}
static void F_94 ( struct V_85 * V_86 , T_2 V_43 )
{
struct V_40 * V_41 = F_75 ( V_86 ) ;
F_82 ( & V_41 -> V_92 ) ;
F_93 ( V_41 , V_43 ) ;
F_85 ( & V_41 -> V_92 ) ;
}
static int F_95 ( struct V_40 * V_41 , T_1 V_39 )
{
struct V_32 * V_37 = F_37 ( & V_41 -> V_48 , V_39 ) ;
if ( ! V_37 )
return - V_99 ;
F_56 ( V_41 , V_37 ) ;
F_36 ( & V_41 -> V_48 , V_37 ) ;
return 0 ;
}
static int F_96 ( struct V_85 * V_86 , T_1 V_39 )
{
int V_25 ;
struct V_40 * V_41 = F_75 ( V_86 ) ;
F_82 ( & V_41 -> V_92 ) ;
V_25 = F_95 ( V_41 , V_39 ) ;
F_85 ( & V_41 -> V_92 ) ;
return V_25 ;
}
static int F_97 ( struct V_40 * V_41 , T_2 * V_43 ,
T_1 * V_39 )
{
struct V_32 * V_37 = F_57 ( V_41 , & V_41 -> V_53 ) ;
if ( ! V_37 )
return - V_99 ;
* V_43 = V_37 -> V_43 ;
* V_39 = F_41 ( & V_41 -> V_48 , V_37 ) ;
V_37 -> V_52 = false ;
F_55 ( V_41 , V_37 ) ;
return 0 ;
}
static int F_98 ( struct V_85 * V_86 , T_2 * V_43 ,
T_1 * V_39 )
{
int V_25 ;
struct V_40 * V_41 = F_75 ( V_86 ) ;
F_82 ( & V_41 -> V_92 ) ;
V_25 = F_97 ( V_41 , V_43 , V_39 ) ;
F_85 ( & V_41 -> V_92 ) ;
return V_25 ;
}
static void F_99 ( struct V_40 * V_41 ,
T_2 V_100 , T_2 V_101 )
{
struct V_32 * V_37 = F_46 ( V_41 , V_100 ) ;
if ( V_37 && F_54 ( V_41 , V_37 ) ) {
F_56 ( V_41 , V_37 ) ;
V_37 -> V_43 = V_101 ;
V_37 -> V_52 = true ;
F_55 ( V_41 , V_37 ) ;
}
}
static void F_100 ( struct V_85 * V_86 ,
T_2 V_100 , T_2 V_101 )
{
struct V_40 * V_41 = F_75 ( V_86 ) ;
F_82 ( & V_41 -> V_92 ) ;
F_99 ( V_41 , V_100 , V_101 ) ;
F_85 ( & V_41 -> V_92 ) ;
}
static T_1 F_101 ( struct V_85 * V_86 )
{
T_1 V_25 ;
struct V_40 * V_41 = F_75 ( V_86 ) ;
F_82 ( & V_41 -> V_92 ) ;
V_25 = F_42 ( V_41 -> V_48 . V_36 ) ;
F_85 ( & V_41 -> V_92 ) ;
return V_25 ;
}
static void F_102 ( struct V_85 * V_86 )
{
struct V_40 * V_41 = F_75 ( V_86 ) ;
unsigned long V_88 ;
F_79 ( & V_41 -> V_89 , V_88 ) ;
V_41 -> V_90 ++ ;
F_80 ( & V_41 -> V_89 , V_88 ) ;
}
static int F_103 ( struct V_85 * V_86 ,
const char * V_102 , const char * V_103 )
{
struct V_40 * V_41 = F_75 ( V_86 ) ;
enum V_14 V_7 ;
unsigned long V_104 ;
if ( ! strcasecmp ( V_102 , L_2 ) )
V_7 = V_8 ;
else if ( ! strcasecmp ( V_102 , L_3 ) )
V_7 = V_13 ;
else
return - V_105 ;
if ( F_104 ( V_103 , 10 , & V_104 ) )
return - V_105 ;
V_41 -> V_84 . V_12 [ V_7 ] = V_104 ;
return 0 ;
}
static int F_105 ( struct V_85 * V_86 , char * V_72 , unsigned V_106 )
{
T_5 V_107 = 0 ;
struct V_40 * V_41 = F_75 ( V_86 ) ;
F_106 ( L_4 ,
V_41 -> V_84 . V_12 [ V_8 ] ,
V_41 -> V_84 . V_12 [ V_13 ] ) ;
return 0 ;
}
static void F_107 ( struct V_40 * V_41 )
{
V_41 -> V_87 . V_108 = F_76 ;
V_41 -> V_87 . F_74 = F_81 ;
V_41 -> V_87 . V_109 = F_86 ;
V_41 -> V_87 . V_110 = F_88 ;
V_41 -> V_87 . V_111 = F_89 ;
V_41 -> V_87 . V_112 = F_90 ;
V_41 -> V_87 . V_113 = F_92 ;
V_41 -> V_87 . V_114 = F_94 ;
V_41 -> V_87 . V_115 = F_96 ;
V_41 -> V_87 . V_116 = F_98 ;
V_41 -> V_87 . V_117 = F_100 ;
V_41 -> V_87 . V_118 = F_101 ;
V_41 -> V_87 . V_51 = F_102 ;
V_41 -> V_87 . V_119 = F_105 ;
V_41 -> V_87 . V_120 = F_103 ;
}
static struct V_85 * F_108 ( T_1 V_121 ,
T_6 V_122 ,
T_6 V_123 )
{
struct V_40 * V_41 = F_109 ( sizeof( * V_41 ) , V_124 ) ;
if ( ! V_41 )
return NULL ;
F_107 ( V_41 ) ;
F_4 ( & V_41 -> V_84 , V_125 , V_126 ) ;
V_41 -> V_121 = V_121 ;
if ( F_26 ( & V_41 -> V_80 , F_35 ( V_121 ) ) ) {
F_110 ( L_5 ) ;
goto V_127;
}
if ( F_26 ( & V_41 -> V_48 , F_35 ( V_121 ) ) ) {
F_110 ( L_6 ) ;
goto V_128;
}
V_41 -> V_90 = 0 ;
V_41 -> V_51 = 0 ;
V_41 -> V_50 = 0 ;
V_41 -> V_60 = 0 ;
V_41 -> V_62 = 0 ;
F_111 ( & V_41 -> V_92 ) ;
F_112 ( & V_41 -> V_89 ) ;
F_12 ( & V_41 -> V_54 ) ;
F_12 ( & V_41 -> V_49 ) ;
F_12 ( & V_41 -> V_53 ) ;
V_41 -> V_59 = F_3 ( ( unsigned ) F_35 ( V_121 ) , 1024U ) ;
V_41 -> V_129 = F_1 ( F_35 ( V_121 ) / 2 , 16 ) ;
V_41 -> V_44 = F_113 ( V_41 -> V_129 ) - 1 ;
V_41 -> V_45 = F_109 ( sizeof( * V_41 -> V_45 ) * V_41 -> V_129 , V_124 ) ;
if ( ! V_41 -> V_45 )
goto V_130;
return & V_41 -> V_87 ;
V_130:
F_29 ( & V_41 -> V_48 ) ;
V_128:
F_29 ( & V_41 -> V_80 ) ;
V_127:
F_77 ( V_41 ) ;
return NULL ;
}
static int T_7 F_114 ( void )
{
int V_25 ;
V_131 = F_115 ( L_7 ,
sizeof( struct V_32 ) ,
F_116 ( struct V_32 ) ,
0 , NULL ) ;
if ( ! V_131 )
goto V_132;
V_25 = F_117 ( & V_133 ) ;
if ( V_25 ) {
F_110 ( L_8 , V_25 ) ;
goto V_134;
}
V_25 = F_117 ( & V_135 ) ;
if ( ! V_25 ) {
F_118 ( L_9 ,
V_133 . V_136 [ 0 ] ,
V_133 . V_136 [ 1 ] ,
V_133 . V_136 [ 2 ] ) ;
return 0 ;
}
F_110 ( L_10 , V_25 ) ;
F_119 ( & V_133 ) ;
V_134:
F_120 ( V_131 ) ;
V_132:
return - V_33 ;
}
static void T_8 F_121 ( void )
{
F_119 ( & V_133 ) ;
F_119 ( & V_135 ) ;
F_120 ( V_131 ) ;
}
