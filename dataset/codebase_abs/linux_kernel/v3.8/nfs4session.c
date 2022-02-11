static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * * V_5 ;
if ( V_3 >= V_2 -> V_6 )
return;
V_5 = & V_2 -> V_7 ;
while ( V_3 -- )
V_5 = & ( * V_5 ) -> V_8 ;
while ( * V_5 ) {
struct V_4 * V_9 = * V_5 ;
* V_5 = V_9 -> V_8 ;
F_2 ( V_9 ) ;
V_2 -> V_6 -- ;
}
}
void F_3 ( struct V_1 * V_2 , struct V_4 * V_9 )
{
T_1 V_10 = V_9 -> V_11 ;
F_4 ( V_10 , V_2 -> V_12 ) ;
if ( V_10 == V_2 -> V_13 ) {
T_1 V_14 = F_5 ( V_2 -> V_12 , V_10 ) ;
if ( V_14 < V_10 )
V_2 -> V_13 = V_14 ;
else {
V_2 -> V_13 = V_15 ;
F_6 ( V_2 -> V_16 , V_2 ) ;
}
}
F_7 ( L_1 , V_17 ,
V_10 , V_2 -> V_13 ) ;
}
static struct V_4 * F_8 ( struct V_1 * V_2 ,
T_1 V_10 , T_1 V_18 , T_2 V_19 )
{
struct V_4 * V_9 ;
V_9 = F_9 ( sizeof( * V_9 ) , V_19 ) ;
if ( V_9 ) {
V_9 -> V_20 = V_2 ;
V_9 -> V_11 = V_10 ;
V_9 -> V_21 = V_18 ;
}
return V_9 ;
}
static struct V_4 * F_10 ( struct V_1 * V_2 ,
T_1 V_10 , T_1 V_18 , T_2 V_19 )
{
struct V_4 * * V_5 , * V_9 ;
V_5 = & V_2 -> V_7 ;
for (; ; ) {
if ( * V_5 == NULL ) {
* V_5 = F_8 ( V_2 , V_2 -> V_6 ,
V_18 , V_19 ) ;
if ( * V_5 == NULL )
break;
V_2 -> V_6 ++ ;
}
V_9 = * V_5 ;
if ( V_9 -> V_11 == V_10 )
return V_9 ;
V_5 = & V_9 -> V_8 ;
}
return F_11 ( - V_22 ) ;
}
struct V_4 * F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_23 = F_11 ( - V_24 ) ;
T_1 V_10 ;
F_7 ( L_2 ,
V_17 , V_2 -> V_12 [ 0 ] , V_2 -> V_13 ,
V_2 -> V_25 + 1 ) ;
V_10 = F_13 ( V_2 -> V_12 , V_2 -> V_25 + 1 ) ;
if ( V_10 > V_2 -> V_25 )
goto V_26;
V_23 = F_10 ( V_2 , V_10 , 1 , V_27 ) ;
if ( F_14 ( V_23 ) )
goto V_26;
F_15 ( V_10 , V_2 -> V_12 ) ;
if ( V_10 > V_2 -> V_13 ||
V_2 -> V_13 == V_15 )
V_2 -> V_13 = V_10 ;
V_23 -> V_28 = V_2 -> V_28 ;
V_26:
F_7 ( L_3 ,
V_17 , V_2 -> V_12 [ 0 ] , V_2 -> V_13 ,
! F_14 ( V_23 ) ? V_23 -> V_11 : - 1 ) ;
return V_23 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 V_30 )
{
if ( V_29 <= V_2 -> V_6 )
return 0 ;
if ( ! F_14 ( F_10 ( V_2 , V_29 - 1 , V_30 , V_31 ) ) )
return 0 ;
return - V_22 ;
}
static void F_17 ( struct V_1 * V_2 ,
T_1 V_32 ,
T_1 V_30 )
{
struct V_4 * * V_5 ;
F_1 ( V_2 , V_32 + 1 ) ;
V_5 = & V_2 -> V_7 ;
while ( * V_5 ) {
( * V_5 ) -> V_21 = V_30 ;
( * V_5 ) -> V_33 = 0 ;
V_5 = & ( * V_5 ) -> V_8 ;
}
V_2 -> V_13 = V_15 ;
V_2 -> V_34 = V_32 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = 0 ;
V_2 -> V_25 = V_32 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 V_30 )
{
int V_23 ;
F_7 ( L_4 , V_17 ,
V_29 , V_2 -> V_6 ) ;
if ( V_29 > V_37 )
V_29 = V_37 ;
V_23 = F_16 ( V_2 , V_29 , V_30 ) ;
if ( V_23 )
goto V_26;
F_19 ( & V_2 -> V_38 ) ;
F_17 ( V_2 , V_29 - 1 , V_30 ) ;
F_20 ( & V_2 -> V_38 ) ;
F_7 ( L_5 , V_17 ,
V_2 , V_2 -> V_7 , V_2 -> V_6 ) ;
V_26:
F_7 ( L_6 , V_17 , V_23 ) ;
return V_23 ;
}
static void F_21 ( struct V_39 * V_16 )
{
F_1 ( & V_16 -> V_40 , 0 ) ;
F_1 ( & V_16 -> V_41 , 0 ) ;
}
static bool F_22 ( struct V_42 * V_43 , void * V_44 )
{
struct V_45 * args = V_43 -> V_46 . V_47 ;
struct V_48 * V_49 = V_43 -> V_46 . V_50 ;
struct V_4 * V_9 = V_44 ;
struct V_1 * V_2 = V_9 -> V_20 ;
if ( F_23 ( V_2 -> V_16 ) && ! args -> V_51 )
return false ;
V_9 -> V_28 = V_2 -> V_28 ;
args -> V_52 = V_9 ;
V_49 -> V_53 = V_54 ;
V_49 -> V_55 = V_9 ;
V_49 -> V_56 = 0 ;
V_49 -> V_57 = 1 ;
return true ;
}
static bool F_24 ( struct V_1 * V_2 ,
struct V_4 * V_9 )
{
if ( F_25 ( & V_2 -> V_58 , F_22 , V_9 ) )
return true ;
return false ;
}
bool F_26 ( struct V_1 * V_2 ,
struct V_4 * V_9 )
{
if ( V_9 -> V_11 > V_2 -> V_25 )
return false ;
return F_24 ( V_2 , V_9 ) ;
}
static bool F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_9 = F_12 ( V_2 ) ;
if ( ! F_14 ( V_9 ) ) {
bool V_23 = F_24 ( V_2 , V_9 ) ;
if ( V_23 )
return V_23 ;
F_3 ( V_2 , V_9 ) ;
}
return false ;
}
void F_28 ( struct V_1 * V_2 )
{
for (; ; ) {
if ( ! F_27 ( V_2 ) )
break;
}
}
static void F_29 ( struct V_1 * V_2 ,
T_1 V_34 )
{
T_1 V_25 ;
V_25 = F_30 ( V_37 - 1 , V_34 ) ;
if ( V_25 > V_2 -> V_32 )
V_25 = V_2 -> V_32 ;
if ( V_25 > V_2 -> V_34 )
V_25 = V_2 -> V_34 ;
V_2 -> V_25 = V_25 ;
F_28 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
T_1 V_34 )
{
if ( V_2 -> V_34 == V_34 )
return;
V_2 -> V_34 = V_34 ;
V_2 -> V_28 ++ ;
}
void F_32 ( struct V_1 * V_2 ,
T_1 V_34 )
{
F_19 ( & V_2 -> V_38 ) ;
F_31 ( V_2 , V_34 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = 0 ;
F_29 ( V_2 , V_34 ) ;
F_20 ( & V_2 -> V_38 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
T_1 V_59 )
{
if ( V_2 -> V_32 == V_59 )
return;
if ( V_2 -> V_13 > V_59 )
return;
F_1 ( V_2 , V_59 + 1 ) ;
V_2 -> V_32 = V_59 ;
}
static T_3 F_34 ( T_3 V_60 , T_3 V_61 )
{
V_60 -= V_61 ;
if ( V_60 == 0 )
return 0 ;
if ( V_60 < 0 )
return ( V_60 - 1 ) >> 1 ;
return ( V_60 + 1 ) >> 1 ;
}
static int F_35 ( T_3 V_60 )
{
if ( V_60 > 0 )
return 1 ;
if ( V_60 < 0 )
return - 1 ;
return 0 ;
}
static bool F_36 ( T_3 V_60 , T_3 V_61 )
{
if ( ! V_60 || ! V_61 )
return true ;
return F_35 ( V_60 ) == F_35 ( V_61 ) ;
}
static bool F_37 ( struct V_1 * V_2 ,
T_1 V_62 )
{
T_3 V_63 , V_64 ;
bool V_23 = true ;
V_63 = F_34 ( V_62 ,
V_2 -> V_34 ) ;
V_64 = F_34 ( V_63 ,
V_2 -> V_35 ) ;
if ( F_36 ( V_63 , V_2 -> V_35 ) )
V_23 = false ;
if ( F_36 ( V_64 , V_2 -> V_36 ) )
V_23 = false ;
V_2 -> V_35 = V_63 ;
V_2 -> V_36 = V_64 ;
return V_23 ;
}
void F_38 ( struct V_1 * V_2 ,
struct V_4 * V_9 ,
struct V_48 * V_49 )
{
F_19 ( & V_2 -> V_38 ) ;
if ( ! F_37 ( V_2 , V_49 -> V_65 ) )
F_31 ( V_2 , V_49 -> V_65 ) ;
if ( V_2 -> V_28 == V_9 -> V_28 )
F_33 ( V_2 , V_49 -> V_66 ) ;
F_29 ( V_2 , V_49 -> V_65 ) ;
F_20 ( & V_2 -> V_38 ) ;
}
int F_39 ( struct V_39 * V_67 )
{
struct V_1 * V_2 ;
int V_68 ;
F_7 ( L_7 , V_17 ) ;
V_2 = & V_67 -> V_40 ;
V_2 -> V_16 = V_67 ;
V_68 = F_18 ( V_2 , V_67 -> V_69 . V_29 , 1 ) ;
if ( V_68 )
return V_68 ;
V_2 = & V_67 -> V_41 ;
V_2 -> V_16 = V_67 ;
V_68 = F_18 ( V_2 , V_67 -> V_70 . V_29 , 0 ) ;
if ( V_68 && V_2 -> V_7 == NULL )
F_21 ( V_67 ) ;
return V_68 ;
}
struct V_39 * F_40 ( struct V_71 * V_72 )
{
struct V_39 * V_16 ;
struct V_1 * V_2 ;
V_16 = F_9 ( sizeof( struct V_39 ) , V_31 ) ;
if ( ! V_16 )
return NULL ;
V_2 = & V_16 -> V_40 ;
V_2 -> V_13 = V_15 ;
F_41 ( & V_2 -> V_38 ) ;
F_42 ( & V_2 -> V_58 , L_8 ) ;
F_43 ( & V_2 -> V_73 ) ;
V_2 = & V_16 -> V_41 ;
V_2 -> V_13 = V_15 ;
F_41 ( & V_2 -> V_38 ) ;
F_44 ( & V_2 -> V_58 , L_9 ) ;
F_43 ( & V_2 -> V_73 ) ;
V_16 -> V_74 = 1 << V_75 ;
V_16 -> V_72 = V_72 ;
return V_16 ;
}
void F_45 ( struct V_39 * V_16 )
{
struct V_76 * V_77 ;
struct V_78 * V_79 ;
V_79 = F_46 ( V_16 -> V_72 ) ;
F_47 ( V_16 , V_79 ) ;
if ( V_79 )
F_48 ( V_79 ) ;
F_49 () ;
V_77 = F_50 ( V_16 -> V_72 -> V_80 -> V_81 ) ;
F_51 () ;
F_7 ( L_10 ,
V_17 , V_77 ) ;
F_52 ( V_77 , V_82 ) ;
F_21 ( V_16 ) ;
F_2 ( V_16 ) ;
}
static int F_53 ( struct V_71 * V_72 )
{
int V_23 ;
if ( V_72 -> V_83 == V_84 ) {
V_23 = F_54 ( V_72 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_72 -> V_83 < V_85 )
return - V_86 ;
F_55 () ;
return 0 ;
}
int F_56 ( struct V_87 * V_88 )
{
struct V_71 * V_72 = V_88 -> V_71 ;
struct V_39 * V_16 ;
unsigned int V_89 = V_90 ;
unsigned int V_91 = V_90 ;
if ( ! F_57 ( V_72 ) )
return 0 ;
if ( V_88 -> V_92 != 0 )
V_91 = V_88 -> V_92 ;
V_91 += V_93 ;
if ( V_88 -> V_94 != 0 )
V_89 = V_88 -> V_94 ;
V_89 += V_95 ;
V_16 = V_72 -> V_96 ;
F_19 ( & V_72 -> V_97 ) ;
if ( F_58 ( V_75 , & V_16 -> V_74 ) ) {
V_16 -> V_98 = V_89 ;
V_16 -> V_69 . V_99 = V_89 ;
V_16 -> V_100 = V_91 ;
V_16 -> V_69 . V_101 = V_91 ;
} else {
if ( V_89 > V_16 -> V_98 ) {
V_16 -> V_98 = V_89 ;
F_59 ( V_102 , & V_72 -> V_103 ) ;
}
if ( V_91 > V_16 -> V_100 ) {
V_16 -> V_100 = V_91 ;
F_59 ( V_102 , & V_72 -> V_103 ) ;
}
}
F_20 ( & V_72 -> V_97 ) ;
if ( F_60 ( V_102 , & V_72 -> V_103 ) )
F_61 ( V_72 ) ;
return F_53 ( V_72 ) ;
}
int F_62 ( struct V_71 * V_72 , unsigned long V_104 )
{
struct V_39 * V_16 = V_72 -> V_96 ;
int V_23 ;
F_19 ( & V_72 -> V_97 ) ;
if ( F_58 ( V_75 , & V_16 -> V_74 ) ) {
V_72 -> V_105 = V_104 ;
V_72 -> V_106 = V_54 ;
}
F_20 ( & V_72 -> V_97 ) ;
V_23 = F_53 ( V_72 ) ;
if ( V_23 )
return V_23 ;
if ( ! F_63 ( V_72 ) )
return - V_107 ;
return 0 ;
}
