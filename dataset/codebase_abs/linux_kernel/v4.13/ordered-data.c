static T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 + V_2 -> V_4 < V_2 -> V_3 )
return ( T_1 ) - 1 ;
return V_2 -> V_3 + V_2 -> V_4 ;
}
static struct V_5 * F_2 ( struct V_6 * V_7 , T_1 V_3 ,
struct V_5 * V_8 )
{
struct V_5 * * V_9 = & V_7 -> V_5 ;
struct V_5 * V_10 = NULL ;
struct V_1 * V_2 ;
while ( * V_9 ) {
V_10 = * V_9 ;
V_2 = F_3 ( V_10 , struct V_1 , V_5 ) ;
if ( V_3 < V_2 -> V_3 )
V_9 = & ( * V_9 ) -> V_11 ;
else if ( V_3 >= F_1 ( V_2 ) )
V_9 = & ( * V_9 ) -> V_12 ;
else
return V_10 ;
}
F_4 ( V_8 , V_10 , V_9 ) ;
F_5 ( V_8 , V_7 ) ;
return NULL ;
}
static void F_6 ( struct V_13 * V_13 , int V_14 ,
T_1 V_15 )
{
struct V_16 * V_17 = F_7 ( V_13 -> V_18 ) ;
F_8 ( V_17 , V_14 ,
L_1 , V_15 ) ;
}
static struct V_5 * F_9 ( struct V_6 * V_7 , T_1 V_3 ,
struct V_5 * * V_19 )
{
struct V_5 * V_20 = V_7 -> V_5 ;
struct V_5 * V_21 = NULL ;
struct V_5 * V_22 ;
struct V_1 * V_2 ;
struct V_1 * V_23 = NULL ;
while ( V_20 ) {
V_2 = F_3 ( V_20 , struct V_1 , V_5 ) ;
V_21 = V_20 ;
V_23 = V_2 ;
if ( V_3 < V_2 -> V_3 )
V_20 = V_20 -> V_11 ;
else if ( V_3 >= F_1 ( V_2 ) )
V_20 = V_20 -> V_12 ;
else
return V_20 ;
}
if ( ! V_19 )
return NULL ;
while ( V_21 && V_3 >= F_1 ( V_23 ) ) {
V_22 = F_10 ( V_21 ) ;
if ( ! V_22 )
break;
V_23 = F_3 ( V_22 , struct V_1 ,
V_5 ) ;
if ( V_3 < F_1 ( V_23 ) )
break;
V_21 = V_22 ;
}
if ( V_21 )
V_23 = F_3 ( V_21 , struct V_1 ,
V_5 ) ;
while ( V_21 && V_3 < F_1 ( V_23 ) ) {
V_22 = F_11 ( V_21 ) ;
if ( ! V_22 )
break;
V_23 = F_3 ( V_22 , struct V_1 ,
V_5 ) ;
V_21 = V_22 ;
}
* V_19 = V_21 ;
return NULL ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 < V_2 -> V_3 ||
V_2 -> V_3 + V_2 -> V_4 <= V_3 )
return 0 ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
if ( V_3 + V_4 <= V_2 -> V_3 ||
V_2 -> V_3 + V_2 -> V_4 <= V_3 )
return 0 ;
return 1 ;
}
static inline struct V_5 * F_14 ( struct V_24 * V_25 ,
T_1 V_3 )
{
struct V_6 * V_7 = & V_25 -> V_25 ;
struct V_5 * V_21 = NULL ;
struct V_5 * V_26 ;
struct V_1 * V_2 ;
if ( V_25 -> V_27 ) {
V_2 = F_3 ( V_25 -> V_27 , struct V_1 ,
V_5 ) ;
if ( F_12 ( V_2 , V_3 ) )
return V_25 -> V_27 ;
}
V_26 = F_9 ( V_7 , V_3 , & V_21 ) ;
if ( ! V_26 )
V_26 = V_21 ;
if ( V_26 )
V_25 -> V_27 = V_26 ;
return V_26 ;
}
static int F_15 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 ,
int type , int V_30 , int V_31 )
{
struct V_16 * V_17 = F_7 ( V_13 -> V_18 ) ;
struct V_32 * V_7 = F_16 ( V_13 ) -> V_7 ;
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
V_2 = F_17 ( V_34 , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_37 = V_4 ;
V_2 -> V_13 = F_18 ( V_13 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_38 = ( T_1 ) - 1 ;
if ( type != V_39 && type != V_40 )
F_19 ( type , & V_2 -> V_41 ) ;
if ( V_30 )
F_19 ( V_42 , & V_2 -> V_41 ) ;
F_20 ( & V_2 -> V_43 , 1 ) ;
F_21 ( & V_2 -> V_44 ) ;
F_22 ( & V_2 -> V_45 ) ;
F_22 ( & V_2 -> V_46 ) ;
F_22 ( & V_2 -> V_47 ) ;
F_23 ( & V_2 -> V_48 ) ;
F_22 ( & V_2 -> V_49 ) ;
F_22 ( & V_2 -> V_50 ) ;
F_24 ( V_13 , V_2 ) ;
F_25 ( & V_25 -> V_51 ) ;
V_8 = F_2 ( & V_25 -> V_25 , V_3 ,
& V_2 -> V_5 ) ;
if ( V_8 )
F_6 ( V_13 , - V_52 , V_3 ) ;
F_26 ( & V_25 -> V_51 ) ;
F_27 ( & V_7 -> V_53 ) ;
F_28 ( & V_2 -> V_46 ,
& V_7 -> V_54 ) ;
V_7 -> V_55 ++ ;
if ( V_7 -> V_55 == 1 ) {
F_27 ( & V_17 -> V_56 ) ;
F_29 ( ! F_30 ( & V_7 -> V_57 ) ) ;
F_28 ( & V_7 -> V_57 , & V_17 -> V_58 ) ;
F_31 ( & V_17 -> V_56 ) ;
}
F_31 ( & V_7 -> V_53 ) ;
return 0 ;
}
int F_32 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_59 ) ;
}
int F_33 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 1 ,
V_59 ) ;
}
int F_34 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 ,
int type , int V_31 )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_31 ) ;
}
void F_35 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_24 * V_25 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_51 ) ;
F_28 ( & V_61 -> V_45 , & V_2 -> V_45 ) ;
F_26 ( & V_25 -> V_51 ) ;
}
int F_36 ( struct V_13 * V_13 ,
struct V_1 * * V_62 ,
T_1 * V_3 , T_1 V_63 , int V_64 )
{
struct V_16 * V_17 = F_7 ( V_13 -> V_18 ) ;
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
int V_26 ;
unsigned long V_41 ;
T_1 V_65 ;
T_1 V_66 ;
T_1 V_67 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_37 ( & V_25 -> V_51 , V_41 ) ;
V_8 = F_14 ( V_25 , * V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_68;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , * V_3 ) ) {
V_26 = 1 ;
goto V_68;
}
V_66 = F_38 ( * V_3 , V_2 -> V_3 ) ;
V_65 = F_39 ( * V_3 + V_63 , V_2 -> V_3 +
V_2 -> V_4 ) ;
* V_3 = V_65 ;
if ( V_66 > V_65 ) {
F_40 ( V_17 , L_2 ,
V_66 , V_65 ) ;
}
V_67 = V_65 - V_66 ;
if ( V_67 > V_2 -> V_37 ) {
F_40 ( V_17 ,
L_3 ,
V_2 -> V_37 , V_67 ) ;
}
V_2 -> V_37 -= V_67 ;
if ( ! V_64 )
F_19 ( V_69 , & V_2 -> V_41 ) ;
if ( V_2 -> V_37 == 0 ) {
V_26 = F_41 ( V_39 , & V_2 -> V_41 ) ;
if ( F_42 ( & V_2 -> V_44 ) )
F_43 ( & V_2 -> V_44 ) ;
} else {
V_26 = 1 ;
}
V_68:
if ( ! V_26 && V_62 && V_2 ) {
* V_62 = V_2 ;
F_44 ( & V_2 -> V_43 ) ;
}
F_45 ( & V_25 -> V_51 , V_41 ) ;
return V_26 == 0 ;
}
int F_46 ( struct V_13 * V_13 ,
struct V_1 * * V_62 ,
T_1 V_3 , T_1 V_63 , int V_64 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
unsigned long V_41 ;
int V_26 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_37 ( & V_25 -> V_51 , V_41 ) ;
if ( V_62 && * V_62 ) {
V_2 = * V_62 ;
goto V_70;
}
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_68;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
V_70:
if ( ! F_12 ( V_2 , V_3 ) ) {
V_26 = 1 ;
goto V_68;
}
if ( V_63 > V_2 -> V_37 ) {
F_40 ( F_16 ( V_13 ) -> V_7 -> V_17 ,
L_3 ,
V_2 -> V_37 , V_63 ) ;
}
V_2 -> V_37 -= V_63 ;
if ( ! V_64 )
F_19 ( V_69 , & V_2 -> V_41 ) ;
if ( V_2 -> V_37 == 0 ) {
V_26 = F_41 ( V_39 , & V_2 -> V_41 ) ;
if ( F_42 ( & V_2 -> V_44 ) )
F_43 ( & V_2 -> V_44 ) ;
} else {
V_26 = 1 ;
}
V_68:
if ( ! V_26 && V_62 && V_2 ) {
* V_62 = V_2 ;
F_44 ( & V_2 -> V_43 ) ;
}
F_45 ( & V_25 -> V_51 , V_41 ) ;
return V_26 == 0 ;
}
void F_47 ( struct V_71 * V_13 ,
struct V_72 * V_73 ,
const T_2 V_28 ,
const T_2 V_74 )
{
struct V_24 * V_25 ;
struct V_1 * V_75 ;
struct V_5 * V_20 ;
struct V_5 * V_21 ;
V_25 = & V_13 -> V_33 ;
F_25 ( & V_25 -> V_51 ) ;
V_20 = F_9 ( & V_25 -> V_25 , V_74 , & V_21 ) ;
if ( ! V_20 )
V_20 = V_21 ;
for (; V_20 ; V_20 = F_11 ( V_20 ) ) {
V_75 = F_3 ( V_20 , struct V_1 , V_5 ) ;
if ( V_75 -> V_3 > V_74 )
continue;
if ( F_1 ( V_75 ) <= V_28 )
break;
if ( F_41 ( V_76 , & V_75 -> V_41 ) )
continue;
F_48 ( & V_75 -> V_49 , V_73 ) ;
F_44 ( & V_75 -> V_43 ) ;
}
F_26 ( & V_25 -> V_51 ) ;
}
void F_49 ( struct V_72 * V_73 )
{
struct V_1 * V_75 ;
while ( ! F_30 ( V_73 ) ) {
V_75 = F_50 ( V_73 ,
struct V_1 ,
V_49 ) ;
F_51 ( & V_75 -> V_49 ) ;
F_52 ( V_75 ) ;
}
}
void F_53 ( struct V_72 * V_73 ,
struct V_32 * log )
{
int V_77 = log -> V_78 % 2 ;
F_25 ( & log -> V_79 [ V_77 ] ) ;
F_54 ( V_73 , & log -> V_73 [ V_77 ] ) ;
F_26 ( & log -> V_79 [ V_77 ] ) ;
}
void F_55 ( struct V_80 * V_81 ,
struct V_32 * log , T_1 V_82 )
{
struct V_1 * V_75 ;
int V_77 = V_82 % 2 ;
F_25 ( & log -> V_79 [ V_77 ] ) ;
while ( ! F_30 ( & log -> V_73 [ V_77 ] ) ) {
struct V_13 * V_13 ;
V_75 = F_50 ( & log -> V_73 [ V_77 ] ,
struct V_1 ,
V_49 ) ;
F_51 ( & V_75 -> V_49 ) ;
V_13 = V_75 -> V_13 ;
F_26 ( & log -> V_79 [ V_77 ] ) ;
if ( ! F_56 ( V_39 , & V_75 -> V_41 ) &&
! F_56 ( V_42 , & V_75 -> V_41 ) ) {
T_1 V_28 = V_75 -> V_3 ;
T_1 V_74 = V_75 -> V_3 + V_75 -> V_4 - 1 ;
F_57 ( ! V_13 ) ;
F_58 ( V_13 -> V_83 , V_28 , V_74 ) ;
}
F_59 ( V_75 -> V_44 , F_56 ( V_39 ,
& V_75 -> V_41 ) ) ;
if ( ! F_56 ( V_40 , & V_75 -> V_41 ) ) {
struct V_24 * V_25 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_51 ) ;
if ( ! F_56 ( V_40 , & V_75 -> V_41 ) ) {
F_19 ( V_84 , & V_75 -> V_41 ) ;
F_60 ( & V_81 -> V_85 -> V_86 ) ;
}
F_26 ( & V_25 -> V_51 ) ;
}
F_52 ( V_75 ) ;
F_25 ( & log -> V_79 [ V_77 ] ) ;
}
F_26 ( & log -> V_79 [ V_77 ] ) ;
}
void F_61 ( struct V_32 * log , T_1 V_82 )
{
struct V_1 * V_75 ;
int V_77 = V_82 % 2 ;
F_25 ( & log -> V_79 [ V_77 ] ) ;
while ( ! F_30 ( & log -> V_73 [ V_77 ] ) ) {
V_75 = F_50 ( & log -> V_73 [ V_77 ] ,
struct V_1 ,
V_49 ) ;
F_51 ( & V_75 -> V_49 ) ;
F_26 ( & log -> V_79 [ V_77 ] ) ;
F_52 ( V_75 ) ;
F_25 ( & log -> V_79 [ V_77 ] ) ;
}
F_26 ( & log -> V_79 [ V_77 ] ) ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_72 * V_87 ;
struct V_60 * V_61 ;
F_62 ( V_2 -> V_13 , V_2 ) ;
if ( F_63 ( & V_2 -> V_43 ) ) {
ASSERT ( F_30 ( & V_2 -> V_49 ) ) ;
ASSERT ( F_30 ( & V_2 -> V_50 ) ) ;
ASSERT ( F_30 ( & V_2 -> V_46 ) ) ;
ASSERT ( F_64 ( & V_2 -> V_5 ) ) ;
if ( V_2 -> V_13 )
F_65 ( V_2 -> V_13 ) ;
while ( ! F_30 ( & V_2 -> V_45 ) ) {
V_87 = V_2 -> V_45 . V_88 ;
V_61 = F_66 ( V_87 , struct V_60 , V_45 ) ;
F_67 ( & V_61 -> V_45 ) ;
F_68 ( V_61 ) ;
}
F_69 ( V_34 , V_2 ) ;
}
}
void F_70 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 = F_7 ( V_13 -> V_18 ) ;
struct V_24 * V_25 ;
struct V_32 * V_7 = F_16 ( V_13 ) -> V_7 ;
struct V_5 * V_8 ;
bool V_89 = false ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_51 ) ;
V_8 = & V_2 -> V_5 ;
F_71 ( V_8 , & V_25 -> V_25 ) ;
F_72 ( V_8 ) ;
if ( V_25 -> V_27 == V_8 )
V_25 -> V_27 = NULL ;
F_19 ( V_40 , & V_2 -> V_41 ) ;
if ( F_73 ( V_84 , & V_2 -> V_41 ) )
V_89 = true ;
F_26 ( & V_25 -> V_51 ) ;
if ( V_89 ) {
struct V_90 * V_81 ;
F_27 ( & V_17 -> V_91 ) ;
V_81 = V_17 -> V_92 ;
if ( V_81 )
F_44 ( & V_81 -> V_93 ) ;
F_31 ( & V_17 -> V_91 ) ;
ASSERT ( V_81 ) ;
if ( V_81 ) {
if ( F_74 ( & V_81 -> V_86 ) )
F_43 ( & V_81 -> V_94 ) ;
F_75 ( V_81 ) ;
}
}
F_27 ( & V_7 -> V_53 ) ;
F_51 ( & V_2 -> V_46 ) ;
V_7 -> V_55 -- ;
F_76 ( V_13 , V_2 ) ;
if ( ! V_7 -> V_55 ) {
F_27 ( & V_17 -> V_56 ) ;
F_29 ( F_30 ( & V_7 -> V_57 ) ) ;
F_51 ( & V_7 -> V_57 ) ;
F_31 ( & V_17 -> V_56 ) ;
}
F_31 ( & V_7 -> V_53 ) ;
F_43 ( & V_2 -> V_44 ) ;
}
static void F_77 ( struct V_95 * V_96 )
{
struct V_1 * V_75 ;
V_75 = F_78 ( V_96 , struct V_1 , V_97 ) ;
F_79 ( V_75 -> V_13 , V_75 , 1 ) ;
F_80 ( & V_75 -> V_48 ) ;
}
T_1 F_81 ( struct V_32 * V_7 , T_1 V_98 ,
const T_1 V_99 , const T_1 V_100 )
{
struct V_16 * V_17 = V_7 -> V_17 ;
F_82 ( V_101 ) ;
F_82 ( V_102 ) ;
F_82 ( V_103 ) ;
struct V_1 * V_75 , * V_88 ;
T_1 V_104 = 0 ;
const T_1 V_105 = V_99 + V_100 ;
F_83 ( & V_7 -> V_106 ) ;
F_27 ( & V_7 -> V_53 ) ;
F_84 ( & V_7 -> V_54 , & V_101 ) ;
while ( ! F_30 ( & V_101 ) && V_98 ) {
V_75 = F_50 ( & V_101 , struct V_1 ,
V_46 ) ;
if ( V_105 <= V_75 -> V_28 ||
V_75 -> V_28 + V_75 -> V_29 <= V_99 ) {
F_85 ( & V_75 -> V_46 , & V_102 ) ;
F_86 ( & V_7 -> V_53 ) ;
continue;
}
F_85 ( & V_75 -> V_46 ,
& V_7 -> V_54 ) ;
F_44 ( & V_75 -> V_43 ) ;
F_31 ( & V_7 -> V_53 ) ;
F_87 ( & V_75 -> V_97 ,
V_107 ,
F_77 , NULL , NULL ) ;
F_28 ( & V_75 -> V_47 , & V_103 ) ;
F_88 ( V_17 -> V_108 , & V_75 -> V_97 ) ;
F_89 () ;
F_27 ( & V_7 -> V_53 ) ;
if ( V_98 != V_109 )
V_98 -- ;
V_104 ++ ;
}
F_54 ( & V_102 , & V_7 -> V_54 ) ;
F_54 ( & V_101 , & V_7 -> V_54 ) ;
F_31 ( & V_7 -> V_53 ) ;
F_90 (ordered, next, &works, work_list) {
F_51 ( & V_75 -> V_47 ) ;
F_91 ( & V_75 -> V_48 ) ;
F_52 ( V_75 ) ;
F_89 () ;
}
F_92 ( & V_7 -> V_106 ) ;
return V_104 ;
}
T_1 F_93 ( struct V_16 * V_17 , T_1 V_98 ,
const T_1 V_99 , const T_1 V_100 )
{
struct V_32 * V_7 ;
struct V_72 V_101 ;
T_1 V_110 = 0 ;
T_1 V_111 ;
F_22 ( & V_101 ) ;
F_83 ( & V_17 -> V_112 ) ;
F_27 ( & V_17 -> V_56 ) ;
F_84 ( & V_17 -> V_58 , & V_101 ) ;
while ( ! F_30 ( & V_101 ) && V_98 ) {
V_7 = F_50 ( & V_101 , struct V_32 ,
V_57 ) ;
V_7 = F_94 ( V_7 ) ;
F_29 ( ! V_7 ) ;
F_85 ( & V_7 -> V_57 ,
& V_17 -> V_58 ) ;
F_31 ( & V_17 -> V_56 ) ;
V_111 = F_81 ( V_7 , V_98 ,
V_99 , V_100 ) ;
F_95 ( V_7 ) ;
V_110 += V_111 ;
F_27 ( & V_17 -> V_56 ) ;
if ( V_98 != V_109 ) {
V_98 -= V_111 ;
}
}
F_54 ( & V_101 , & V_17 -> V_58 ) ;
F_31 ( & V_17 -> V_56 ) ;
F_92 ( & V_17 -> V_112 ) ;
return V_110 ;
}
void F_79 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
int V_44 )
{
T_1 V_28 = V_2 -> V_3 ;
T_1 V_74 = V_28 + V_2 -> V_4 - 1 ;
F_96 ( V_13 , V_2 ) ;
if ( ! F_56 ( V_42 , & V_2 -> V_41 ) )
F_58 ( V_13 -> V_83 , V_28 , V_74 ) ;
if ( V_44 ) {
F_59 ( V_2 -> V_44 , F_56 ( V_40 ,
& V_2 -> V_41 ) ) ;
}
}
int F_97 ( struct V_13 * V_13 , T_1 V_28 , T_1 V_4 )
{
int V_26 = 0 ;
int V_113 = 0 ;
T_1 V_74 ;
T_1 V_114 ;
struct V_1 * V_75 ;
if ( V_28 + V_4 < V_28 ) {
V_114 = F_98 ( T_2 ) ;
} else {
V_114 = V_28 + V_4 - 1 ;
if ( V_114 > F_98 ( T_2 ) )
V_114 = F_98 ( T_2 ) ;
}
V_26 = F_99 ( V_13 , V_28 , V_114 ) ;
if ( V_26 )
return V_26 ;
V_113 = F_100 ( V_13 -> V_83 , V_28 , V_114 ) ;
V_74 = V_114 ;
while ( 1 ) {
V_75 = F_101 ( V_13 , V_74 ) ;
if ( ! V_75 )
break;
if ( V_75 -> V_3 > V_114 ) {
F_52 ( V_75 ) ;
break;
}
if ( V_75 -> V_3 + V_75 -> V_4 <= V_28 ) {
F_52 ( V_75 ) ;
break;
}
F_79 ( V_13 , V_75 , 1 ) ;
V_74 = V_75 -> V_3 ;
if ( F_56 ( V_69 , & V_75 -> V_41 ) )
V_26 = - V_115 ;
F_52 ( V_75 ) ;
if ( V_26 || V_74 == 0 || V_74 == V_28 )
break;
V_74 -- ;
}
return V_113 ? V_113 : V_26 ;
}
struct V_1 * F_102 ( struct V_13 * V_13 ,
T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_51 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_68;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , V_3 ) )
V_2 = NULL ;
if ( V_2 )
F_44 ( & V_2 -> V_43 ) ;
V_68:
F_26 ( & V_25 -> V_51 ) ;
return V_2 ;
}
struct V_1 * F_103 (
struct V_71 * V_13 , T_1 V_3 , T_1 V_4 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & V_13 -> V_33 ;
F_25 ( & V_25 -> V_51 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_8 = F_14 ( V_25 , V_3 + V_4 ) ;
if ( ! V_8 )
goto V_68;
}
while ( 1 ) {
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( F_13 ( V_2 , V_3 , V_4 ) )
break;
if ( V_2 -> V_3 >= V_3 + V_4 ) {
V_2 = NULL ;
break;
}
V_2 = NULL ;
V_8 = F_10 ( V_8 ) ;
if ( ! V_8 )
break;
}
V_68:
if ( V_2 )
F_44 ( & V_2 -> V_43 ) ;
F_26 ( & V_25 -> V_51 ) ;
return V_2 ;
}
bool F_104 ( struct V_13 * V_13 ,
T_1 V_3 ,
T_1 V_4 )
{
struct V_1 * V_116 ;
V_116 = F_103 ( F_16 ( V_13 ) , V_3 , V_4 ) ;
if ( V_116 ) {
F_52 ( V_116 ) ;
return true ;
}
return false ;
}
struct V_1 *
F_101 ( struct V_13 * V_13 , T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_51 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_68;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
F_44 ( & V_2 -> V_43 ) ;
V_68:
F_26 ( & V_25 -> V_51 ) ;
return V_2 ;
}
int F_105 ( struct V_13 * V_13 , T_1 V_15 ,
struct V_1 * V_75 )
{
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_33 ;
T_1 V_117 ;
T_1 V_118 ;
T_1 V_119 = F_106 ( V_13 ) ;
struct V_5 * V_8 ;
struct V_5 * V_21 = NULL ;
struct V_1 * V_22 ;
int V_26 = 1 ;
T_1 V_120 = V_15 ;
F_25 ( & V_25 -> V_51 ) ;
if ( V_75 ) {
V_15 = F_1 ( V_75 ) ;
if ( F_56 ( V_121 , & V_75 -> V_41 ) )
V_15 = F_39 ( V_15 ,
V_75 -> V_3 +
V_75 -> V_38 ) ;
} else {
V_15 = F_107 ( V_15 , F_108 ( V_13 ) ) ;
}
V_117 = F_16 ( V_13 ) -> V_117 ;
if ( ! V_75 && V_117 > V_119 ) {
F_16 ( V_13 ) -> V_117 = V_120 ;
V_26 = 0 ;
goto V_68;
}
if ( V_117 == V_119 )
goto V_68;
if ( V_15 <= V_117 &&
( ! V_75 || V_75 -> V_122 <= V_117 ) )
goto V_68;
if ( V_75 ) {
V_8 = F_11 ( & V_75 -> V_5 ) ;
} else {
V_21 = F_14 ( V_25 , V_15 ) ;
if ( V_21 ) {
V_22 = F_3 ( V_21 , struct V_1 ,
V_5 ) ;
F_29 ( F_12 ( V_22 , V_15 ) ) ;
}
V_8 = V_21 ;
}
for (; V_8 ; V_8 = F_11 ( V_8 ) ) {
V_22 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( F_56 ( V_123 , & V_22 -> V_41 ) )
continue;
if ( F_1 ( V_22 ) <= V_117 )
break;
if ( V_22 -> V_3 >= V_119 )
break;
if ( V_22 -> V_122 < V_15 )
V_22 -> V_122 = V_15 ;
if ( V_75 &&
V_75 -> V_122 > V_22 -> V_122 )
V_22 -> V_122 = V_75 -> V_122 ;
goto V_68;
}
V_118 = F_109 ( T_1 , V_15 , V_119 ) ;
if ( V_75 && V_75 -> V_122 > V_118 )
V_118 = F_109 ( T_1 , V_75 -> V_122 , V_119 ) ;
F_16 ( V_13 ) -> V_117 = V_118 ;
V_26 = 0 ;
V_68:
if ( V_75 )
F_19 ( V_123 , & V_75 -> V_41 ) ;
F_26 ( & V_25 -> V_51 ) ;
return V_26 ;
}
int F_110 ( struct V_13 * V_13 , T_1 V_15 , T_1 V_124 ,
T_3 * V_61 , int V_4 )
{
struct V_60 * V_125 ;
struct V_1 * V_75 ;
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_33 ;
unsigned long V_126 ;
unsigned long V_127 ;
T_3 V_128 = F_108 ( V_13 ) ;
int V_77 = 0 ;
V_75 = F_102 ( V_13 , V_15 ) ;
if ( ! V_75 )
return 0 ;
F_25 ( & V_25 -> V_51 ) ;
F_111 (ordered_sum, &ordered->list, list) {
if ( V_124 >= V_125 -> V_129 &&
V_124 < V_125 -> V_129 + V_125 -> V_4 ) {
V_127 = ( V_124 - V_125 -> V_129 ) >>
V_13 -> V_18 -> V_130 ;
V_126 = V_125 -> V_4 >>
V_13 -> V_18 -> V_130 ;
V_126 = F_109 ( int , V_4 - V_77 , V_126 - V_127 ) ;
memcpy ( V_61 + V_77 , V_125 -> V_131 + V_127 ,
V_126 ) ;
V_77 += ( int ) V_126 ;
if ( V_77 == V_4 )
goto V_68;
V_124 += V_126 * V_128 ;
}
}
V_68:
F_26 ( & V_25 -> V_51 ) ;
F_52 ( V_75 ) ;
return V_77 ;
}
int T_4 F_112 ( void )
{
V_34 = F_113 ( L_4 ,
sizeof( struct V_1 ) , 0 ,
V_132 ,
NULL ) ;
if ( ! V_34 )
return - V_36 ;
return 0 ;
}
void F_114 ( void )
{
F_115 ( V_34 ) ;
}
