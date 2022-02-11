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
F_8 ( V_17 , V_14 , L_1
L_2 , V_15 ) ;
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
if ( ! ( F_16 ( V_13 ) -> V_37 & V_38 ) &&
! ( type == V_39 ) )
V_2 -> V_40 = V_29 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_41 = V_4 ;
V_2 -> V_13 = F_18 ( V_13 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_42 = ( T_1 ) - 1 ;
if ( type != V_43 && type != V_44 )
F_19 ( type , & V_2 -> V_37 ) ;
if ( V_30 )
F_19 ( V_45 , & V_2 -> V_37 ) ;
F_20 ( & V_2 -> V_46 , 1 ) ;
F_21 ( & V_2 -> V_47 ) ;
F_22 ( & V_2 -> V_48 ) ;
F_22 ( & V_2 -> V_49 ) ;
F_22 ( & V_2 -> V_50 ) ;
F_23 ( & V_2 -> V_51 ) ;
F_22 ( & V_2 -> V_52 ) ;
F_24 ( V_13 , V_2 ) ;
F_25 ( & V_25 -> V_53 ) ;
V_8 = F_2 ( & V_25 -> V_25 , V_3 ,
& V_2 -> V_5 ) ;
if ( V_8 )
F_6 ( V_13 , - V_54 , V_3 ) ;
F_26 ( & V_25 -> V_53 ) ;
F_27 ( & V_7 -> V_55 ) ;
F_28 ( & V_2 -> V_49 ,
& V_7 -> V_56 ) ;
V_7 -> V_57 ++ ;
if ( V_7 -> V_57 == 1 ) {
F_27 ( & V_7 -> V_17 -> V_58 ) ;
F_29 ( ! F_30 ( & V_7 -> V_59 ) ) ;
F_28 ( & V_7 -> V_59 ,
& V_7 -> V_17 -> V_60 ) ;
F_31 ( & V_7 -> V_17 -> V_58 ) ;
}
F_31 ( & V_7 -> V_55 ) ;
return 0 ;
}
int F_32 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_61 ) ;
}
int F_33 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 1 ,
V_61 ) ;
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
struct V_62 * V_63 )
{
struct V_24 * V_25 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_53 ) ;
F_28 ( & V_63 -> V_48 , & V_2 -> V_48 ) ;
F_36 ( V_2 -> V_40 < V_63 -> V_4 ) ;
V_2 -> V_40 -= V_63 -> V_4 ;
if ( V_2 -> V_40 == 0 )
F_37 ( & V_2 -> V_47 ) ;
F_26 ( & V_25 -> V_53 ) ;
}
int F_38 ( struct V_13 * V_13 ,
struct V_1 * * V_64 ,
T_1 * V_3 , T_1 V_65 , int V_66 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
int V_26 ;
unsigned long V_37 ;
T_1 V_67 ;
T_1 V_68 ;
T_1 V_69 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_39 ( & V_25 -> V_53 , V_37 ) ;
V_8 = F_14 ( V_25 , * V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_70;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , * V_3 ) ) {
V_26 = 1 ;
goto V_70;
}
V_68 = F_40 ( * V_3 , V_2 -> V_3 ) ;
V_67 = F_41 ( * V_3 + V_65 , V_2 -> V_3 +
V_2 -> V_4 ) ;
* V_3 = V_67 ;
if ( V_68 > V_67 ) {
F_42 ( V_71 L_3 ,
V_68 , V_67 ) ;
}
V_69 = V_67 - V_68 ;
if ( V_69 > V_2 -> V_41 ) {
F_42 ( V_71 L_4 ,
V_2 -> V_41 , V_69 ) ;
}
V_2 -> V_41 -= V_69 ;
if ( ! V_66 )
F_19 ( V_72 , & V_2 -> V_37 ) ;
if ( V_2 -> V_41 == 0 )
V_26 = F_43 ( V_43 , & V_2 -> V_37 ) ;
else
V_26 = 1 ;
V_70:
if ( ! V_26 && V_64 && V_2 ) {
* V_64 = V_2 ;
F_44 ( & V_2 -> V_46 ) ;
}
F_45 ( & V_25 -> V_53 , V_37 ) ;
return V_26 == 0 ;
}
int F_46 ( struct V_13 * V_13 ,
struct V_1 * * V_64 ,
T_1 V_3 , T_1 V_65 , int V_66 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
unsigned long V_37 ;
int V_26 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_39 ( & V_25 -> V_53 , V_37 ) ;
if ( V_64 && * V_64 ) {
V_2 = * V_64 ;
goto V_73;
}
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_70;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
V_73:
if ( ! F_12 ( V_2 , V_3 ) ) {
V_26 = 1 ;
goto V_70;
}
if ( V_65 > V_2 -> V_41 ) {
F_42 ( V_71 L_4 ,
V_2 -> V_41 , V_65 ) ;
}
V_2 -> V_41 -= V_65 ;
if ( ! V_66 )
F_19 ( V_72 , & V_2 -> V_37 ) ;
if ( V_2 -> V_41 == 0 )
V_26 = F_43 ( V_43 , & V_2 -> V_37 ) ;
else
V_26 = 1 ;
V_70:
if ( ! V_26 && V_64 && V_2 ) {
* V_64 = V_2 ;
F_44 ( & V_2 -> V_46 ) ;
}
F_45 ( & V_25 -> V_53 , V_37 ) ;
return V_26 == 0 ;
}
void F_47 ( struct V_32 * log , struct V_13 * V_13 )
{
struct V_24 * V_25 ;
struct V_1 * V_74 ;
struct V_5 * V_20 ;
int V_75 = log -> V_76 % 2 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_53 ) ;
for ( V_20 = F_48 ( & V_25 -> V_25 ) ; V_20 ; V_20 = F_10 ( V_20 ) ) {
V_74 = F_3 ( V_20 , struct V_1 , V_5 ) ;
F_27 ( & log -> V_77 [ V_75 ] ) ;
if ( F_30 ( & V_74 -> V_52 ) ) {
F_28 ( & V_74 -> V_52 , & log -> V_78 [ V_75 ] ) ;
F_44 ( & V_74 -> V_46 ) ;
}
F_31 ( & log -> V_77 [ V_75 ] ) ;
}
F_26 ( & V_25 -> V_53 ) ;
}
void F_49 ( struct V_32 * log , T_1 V_79 )
{
struct V_1 * V_74 ;
int V_75 = V_79 % 2 ;
F_25 ( & log -> V_77 [ V_75 ] ) ;
while ( ! F_30 ( & log -> V_78 [ V_75 ] ) ) {
V_74 = F_50 ( & log -> V_78 [ V_75 ] ,
struct V_1 ,
V_52 ) ;
F_51 ( & V_74 -> V_52 ) ;
F_26 ( & log -> V_77 [ V_75 ] ) ;
F_52 ( V_74 -> V_47 , F_53 ( V_43 ,
& V_74 -> V_37 ) ) ;
F_54 ( V_74 ) ;
F_25 ( & log -> V_77 [ V_75 ] ) ;
}
F_26 ( & log -> V_77 [ V_75 ] ) ;
}
void F_55 ( struct V_32 * log , T_1 V_79 )
{
struct V_1 * V_74 ;
int V_75 = V_79 % 2 ;
F_25 ( & log -> V_77 [ V_75 ] ) ;
while ( ! F_30 ( & log -> V_78 [ V_75 ] ) ) {
V_74 = F_50 ( & log -> V_78 [ V_75 ] ,
struct V_1 ,
V_52 ) ;
F_51 ( & V_74 -> V_52 ) ;
F_26 ( & log -> V_77 [ V_75 ] ) ;
F_54 ( V_74 ) ;
F_25 ( & log -> V_77 [ V_75 ] ) ;
}
F_26 ( & log -> V_77 [ V_75 ] ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_80 * V_81 ;
struct V_62 * V_63 ;
F_56 ( V_2 -> V_13 , V_2 ) ;
if ( F_57 ( & V_2 -> V_46 ) ) {
if ( V_2 -> V_13 )
F_58 ( V_2 -> V_13 ) ;
while ( ! F_30 ( & V_2 -> V_48 ) ) {
V_81 = V_2 -> V_48 . V_82 ;
V_63 = F_59 ( V_81 , struct V_62 , V_48 ) ;
F_60 ( & V_63 -> V_48 ) ;
F_61 ( V_63 ) ;
}
F_62 ( V_34 , V_2 ) ;
}
}
void F_63 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_32 * V_7 = F_16 ( V_13 ) -> V_7 ;
struct V_5 * V_8 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_53 ) ;
V_8 = & V_2 -> V_5 ;
F_64 ( V_8 , & V_25 -> V_25 ) ;
V_25 -> V_27 = NULL ;
F_19 ( V_44 , & V_2 -> V_37 ) ;
F_26 ( & V_25 -> V_53 ) ;
F_27 ( & V_7 -> V_55 ) ;
F_51 ( & V_2 -> V_49 ) ;
V_7 -> V_57 -- ;
F_65 ( V_13 , V_2 ) ;
if ( F_66 ( & V_25 -> V_25 ) &&
! F_67 ( V_13 -> V_83 , V_84 ) ) {
F_51 ( & F_16 ( V_13 ) -> V_85 ) ;
}
if ( ! V_7 -> V_57 ) {
F_27 ( & V_7 -> V_17 -> V_58 ) ;
F_29 ( F_30 ( & V_7 -> V_59 ) ) ;
F_51 ( & V_7 -> V_59 ) ;
F_31 ( & V_7 -> V_17 -> V_58 ) ;
}
F_31 ( & V_7 -> V_55 ) ;
F_37 ( & V_2 -> V_47 ) ;
}
static void F_68 ( struct V_86 * V_87 )
{
struct V_1 * V_74 ;
V_74 = F_69 ( V_87 , struct V_1 , V_88 ) ;
F_70 ( V_74 -> V_13 , V_74 , 1 ) ;
F_71 ( & V_74 -> V_51 ) ;
}
void F_72 ( struct V_32 * V_7 )
{
struct V_80 V_89 , V_90 ;
struct V_1 * V_74 , * V_82 ;
F_22 ( & V_89 ) ;
F_22 ( & V_90 ) ;
F_73 ( & V_7 -> V_17 -> V_91 ) ;
F_27 ( & V_7 -> V_55 ) ;
F_74 ( & V_7 -> V_56 , & V_89 ) ;
while ( ! F_30 ( & V_89 ) ) {
V_74 = F_50 ( & V_89 , struct V_1 ,
V_49 ) ;
F_75 ( & V_74 -> V_49 ,
& V_7 -> V_56 ) ;
F_44 ( & V_74 -> V_46 ) ;
F_31 ( & V_7 -> V_55 ) ;
V_74 -> V_88 . V_92 = F_68 ;
F_28 ( & V_74 -> V_50 , & V_90 ) ;
F_76 ( & V_7 -> V_17 -> V_93 ,
& V_74 -> V_88 ) ;
F_77 () ;
F_27 ( & V_7 -> V_55 ) ;
}
F_31 ( & V_7 -> V_55 ) ;
F_78 (ordered, next, &works, work_list) {
F_51 ( & V_74 -> V_50 ) ;
F_79 ( & V_74 -> V_51 ) ;
F_54 ( V_74 ) ;
F_77 () ;
}
F_80 ( & V_7 -> V_17 -> V_91 ) ;
}
void F_81 ( struct V_16 * V_17 )
{
struct V_32 * V_7 ;
struct V_80 V_89 ;
F_22 ( & V_89 ) ;
F_27 ( & V_17 -> V_58 ) ;
F_74 ( & V_17 -> V_60 , & V_89 ) ;
while ( ! F_30 ( & V_89 ) ) {
V_7 = F_50 ( & V_89 , struct V_32 ,
V_59 ) ;
V_7 = F_82 ( V_7 ) ;
F_29 ( ! V_7 ) ;
F_75 ( & V_7 -> V_59 ,
& V_17 -> V_60 ) ;
F_31 ( & V_17 -> V_58 ) ;
F_72 ( V_7 ) ;
F_83 ( V_7 ) ;
F_27 ( & V_17 -> V_58 ) ;
}
F_31 ( & V_17 -> V_58 ) ;
}
int F_84 ( struct V_94 * V_95 ,
struct V_32 * V_7 , int V_47 )
{
struct V_96 * V_96 ;
struct V_13 * V_13 ;
struct V_97 * V_98 = V_95 -> V_99 ;
struct V_80 V_89 ;
struct V_80 V_90 ;
struct V_100 * V_87 , * V_82 ;
int V_26 = 0 ;
F_22 ( & V_89 ) ;
F_22 ( & V_90 ) ;
F_73 ( & V_7 -> V_17 -> V_101 ) ;
F_27 ( & V_7 -> V_17 -> V_58 ) ;
F_74 ( & V_98 -> V_85 , & V_89 ) ;
while ( ! F_30 ( & V_89 ) ) {
V_96 = F_59 ( V_89 . V_82 , struct V_96 ,
V_85 ) ;
V_13 = & V_96 -> V_102 ;
F_51 ( & V_96 -> V_85 ) ;
V_13 = F_18 ( V_13 ) ;
if ( ! V_13 )
continue;
if ( ! V_47 )
F_28 ( & F_16 ( V_13 ) -> V_85 ,
& V_98 -> V_85 ) ;
F_31 ( & V_7 -> V_17 -> V_58 ) ;
V_87 = F_85 ( V_13 , V_47 , 1 ) ;
if ( ! V_87 ) {
F_27 ( & V_7 -> V_17 -> V_58 ) ;
if ( F_30 ( & F_16 ( V_13 ) -> V_85 ) )
F_28 ( & V_96 -> V_85 ,
& V_89 ) ;
F_86 ( & V_89 ,
& V_98 -> V_85 ) ;
F_31 ( & V_7 -> V_17 -> V_58 ) ;
V_26 = - V_36 ;
goto V_70;
}
F_28 ( & V_87 -> V_48 , & V_90 ) ;
F_76 ( & V_7 -> V_17 -> V_93 ,
& V_87 -> V_87 ) ;
F_77 () ;
F_27 ( & V_7 -> V_17 -> V_58 ) ;
}
F_31 ( & V_7 -> V_17 -> V_58 ) ;
V_70:
F_78 (work, next, &works, list) {
F_51 ( & V_87 -> V_48 ) ;
F_87 ( V_87 ) ;
}
F_80 ( & V_7 -> V_17 -> V_101 ) ;
return V_26 ;
}
void F_70 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
int V_47 )
{
T_1 V_28 = V_2 -> V_3 ;
T_1 V_103 = V_28 + V_2 -> V_4 - 1 ;
F_88 ( V_13 , V_2 ) ;
if ( ! F_53 ( V_45 , & V_2 -> V_37 ) )
F_89 ( V_13 -> V_83 , V_28 , V_103 ) ;
if ( V_47 ) {
F_52 ( V_2 -> V_47 , F_53 ( V_44 ,
& V_2 -> V_37 ) ) ;
}
}
void F_90 ( struct V_13 * V_13 , T_1 V_28 , T_1 V_4 )
{
T_1 V_103 ;
T_1 V_104 ;
struct V_1 * V_74 ;
if ( V_28 + V_4 < V_28 ) {
V_104 = F_91 ( V_105 ) ;
} else {
V_104 = V_28 + V_4 - 1 ;
if ( V_104 > F_91 ( V_105 ) )
V_104 = F_91 ( V_105 ) ;
}
F_89 ( V_13 -> V_83 , V_28 , V_104 ) ;
if ( F_53 ( V_106 ,
& F_16 ( V_13 ) -> V_107 ) )
F_89 ( V_13 -> V_83 , V_28 , V_104 ) ;
F_92 ( V_13 -> V_83 , V_28 , V_104 ) ;
V_103 = V_104 ;
while ( 1 ) {
V_74 = F_93 ( V_13 , V_103 ) ;
if ( ! V_74 )
break;
if ( V_74 -> V_3 > V_104 ) {
F_54 ( V_74 ) ;
break;
}
if ( V_74 -> V_3 + V_74 -> V_4 < V_28 ) {
F_54 ( V_74 ) ;
break;
}
F_70 ( V_13 , V_74 , 1 ) ;
V_103 = V_74 -> V_3 ;
F_54 ( V_74 ) ;
if ( V_103 == 0 || V_103 == V_28 )
break;
V_103 -- ;
}
}
struct V_1 * F_94 ( struct V_13 * V_13 ,
T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_53 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_70;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , V_3 ) )
V_2 = NULL ;
if ( V_2 )
F_44 ( & V_2 -> V_46 ) ;
V_70:
F_26 ( & V_25 -> V_53 ) ;
return V_2 ;
}
struct V_1 * F_95 ( struct V_13 * V_13 ,
T_1 V_3 ,
T_1 V_4 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_53 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_8 = F_14 ( V_25 , V_3 + V_4 ) ;
if ( ! V_8 )
goto V_70;
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
V_70:
if ( V_2 )
F_44 ( & V_2 -> V_46 ) ;
F_26 ( & V_25 -> V_53 ) ;
return V_2 ;
}
struct V_1 *
F_93 ( struct V_13 * V_13 , T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_53 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_70;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
F_44 ( & V_2 -> V_46 ) ;
V_70:
F_26 ( & V_25 -> V_53 ) ;
return V_2 ;
}
int F_96 ( struct V_13 * V_13 , T_1 V_15 ,
struct V_1 * V_74 )
{
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_33 ;
T_1 V_108 ;
T_1 V_109 ;
T_1 V_110 = F_97 ( V_13 ) ;
struct V_5 * V_8 ;
struct V_5 * V_21 = NULL ;
struct V_1 * V_22 ;
int V_26 = 1 ;
F_25 ( & V_25 -> V_53 ) ;
if ( V_74 ) {
V_15 = F_1 ( V_74 ) ;
if ( F_53 ( V_111 , & V_74 -> V_37 ) )
V_15 = F_41 ( V_15 ,
V_74 -> V_3 +
V_74 -> V_42 ) ;
} else {
V_15 = F_98 ( V_15 , F_16 ( V_13 ) -> V_7 -> V_112 ) ;
}
V_108 = F_16 ( V_13 ) -> V_108 ;
if ( V_108 > V_110 ) {
F_16 ( V_13 ) -> V_108 = V_110 ;
V_26 = 0 ;
goto V_70;
}
if ( V_108 == V_110 )
goto V_70;
if ( V_15 <= V_108 &&
( ! V_74 || V_74 -> V_113 <= V_108 ) )
goto V_70;
if ( V_74 ) {
V_8 = F_11 ( & V_74 -> V_5 ) ;
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
if ( F_53 ( V_114 , & V_22 -> V_37 ) )
continue;
if ( V_22 -> V_3 + V_22 -> V_4 <= V_108 )
break;
if ( V_22 -> V_3 >= V_110 )
break;
if ( F_1 ( V_22 ) > V_108 ) {
if ( V_22 -> V_113 < V_15 )
V_22 -> V_113 = V_15 ;
if ( V_74 &&
V_74 -> V_113 >
V_22 -> V_113 )
V_22 -> V_113 =
V_74 -> V_113 ;
goto V_70;
}
}
V_109 = F_99 ( T_1 , V_15 , V_110 ) ;
if ( V_74 && V_74 -> V_113 > V_109 )
V_109 = F_99 ( T_1 , V_74 -> V_113 , V_110 ) ;
F_16 ( V_13 ) -> V_108 = V_109 ;
V_26 = 0 ;
V_70:
if ( V_74 )
F_19 ( V_114 , & V_74 -> V_37 ) ;
F_26 ( & V_25 -> V_53 ) ;
return V_26 ;
}
int F_100 ( struct V_13 * V_13 , T_1 V_15 , T_1 V_115 ,
T_2 * V_63 , int V_4 )
{
struct V_62 * V_116 ;
struct V_1 * V_74 ;
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_33 ;
unsigned long V_117 ;
unsigned long V_118 ;
T_2 V_112 = F_16 ( V_13 ) -> V_7 -> V_112 ;
int V_75 = 0 ;
V_74 = F_94 ( V_13 , V_15 ) ;
if ( ! V_74 )
return 0 ;
F_25 ( & V_25 -> V_53 ) ;
F_101 (ordered_sum, &ordered->list, list) {
if ( V_115 >= V_116 -> V_119 &&
V_115 < V_116 -> V_119 + V_116 -> V_4 ) {
V_118 = ( V_115 - V_116 -> V_119 ) >>
V_13 -> V_18 -> V_120 ;
V_117 = V_116 -> V_4 >>
V_13 -> V_18 -> V_120 ;
V_117 = F_99 ( int , V_4 - V_75 , V_117 - V_118 ) ;
memcpy ( V_63 + V_75 , V_116 -> V_121 + V_118 ,
V_117 ) ;
V_75 += ( int ) V_117 ;
if ( V_75 == V_4 )
goto V_70;
V_115 += V_117 * V_112 ;
}
}
V_70:
F_26 ( & V_25 -> V_53 ) ;
F_54 ( V_74 ) ;
return V_75 ;
}
void F_102 ( struct V_94 * V_95 ,
struct V_32 * V_7 , struct V_13 * V_13 )
{
struct V_97 * V_98 = V_95 -> V_99 ;
T_1 V_122 ;
V_122 = F_40 ( F_16 ( V_13 ) -> V_123 , F_16 ( V_13 ) -> V_124 ) ;
if ( V_122 < V_7 -> V_17 -> V_125 )
return;
F_27 ( & V_7 -> V_17 -> V_58 ) ;
if ( F_30 ( & F_16 ( V_13 ) -> V_85 ) ) {
F_28 ( & F_16 ( V_13 ) -> V_85 ,
& V_98 -> V_85 ) ;
}
F_31 ( & V_7 -> V_17 -> V_58 ) ;
}
int T_3 F_103 ( void )
{
V_34 = F_104 ( L_5 ,
sizeof( struct V_1 ) , 0 ,
V_126 | V_127 ,
NULL ) ;
if ( ! V_34 )
return - V_36 ;
return 0 ;
}
void F_105 ( void )
{
if ( V_34 )
F_106 ( V_34 ) ;
}
