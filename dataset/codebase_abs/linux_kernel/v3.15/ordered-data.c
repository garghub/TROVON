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
F_42 ( F_16 ( V_13 ) -> V_7 -> V_17 ,
L_3 , V_68 , V_67 ) ;
}
V_69 = V_67 - V_68 ;
if ( V_69 > V_2 -> V_41 ) {
F_42 ( F_16 ( V_13 ) -> V_7 -> V_17 ,
L_4 ,
V_2 -> V_41 , V_69 ) ;
}
V_2 -> V_41 -= V_69 ;
if ( ! V_66 )
F_19 ( V_71 , & V_2 -> V_37 ) ;
if ( V_2 -> V_41 == 0 ) {
V_26 = F_43 ( V_43 , & V_2 -> V_37 ) ;
if ( F_44 ( & V_2 -> V_47 ) )
F_37 ( & V_2 -> V_47 ) ;
} else {
V_26 = 1 ;
}
V_70:
if ( ! V_26 && V_64 && V_2 ) {
* V_64 = V_2 ;
F_45 ( & V_2 -> V_46 ) ;
}
F_46 ( & V_25 -> V_53 , V_37 ) ;
return V_26 == 0 ;
}
int F_47 ( struct V_13 * V_13 ,
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
goto V_72;
}
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_70;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
V_72:
if ( ! F_12 ( V_2 , V_3 ) ) {
V_26 = 1 ;
goto V_70;
}
if ( V_65 > V_2 -> V_41 ) {
F_42 ( F_16 ( V_13 ) -> V_7 -> V_17 ,
L_4 ,
V_2 -> V_41 , V_65 ) ;
}
V_2 -> V_41 -= V_65 ;
if ( ! V_66 )
F_19 ( V_71 , & V_2 -> V_37 ) ;
if ( V_2 -> V_41 == 0 ) {
V_26 = F_43 ( V_43 , & V_2 -> V_37 ) ;
if ( F_44 ( & V_2 -> V_47 ) )
F_37 ( & V_2 -> V_47 ) ;
} else {
V_26 = 1 ;
}
V_70:
if ( ! V_26 && V_64 && V_2 ) {
* V_64 = V_2 ;
F_45 ( & V_2 -> V_46 ) ;
}
F_46 ( & V_25 -> V_53 , V_37 ) ;
return V_26 == 0 ;
}
void F_48 ( struct V_13 * V_13 ,
struct V_73 * V_74 )
{
struct V_24 * V_25 ;
struct V_1 * V_75 ;
struct V_5 * V_20 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_53 ) ;
for ( V_20 = F_49 ( & V_25 -> V_25 ) ; V_20 ; V_20 = F_10 ( V_20 ) ) {
V_75 = F_3 ( V_20 , struct V_1 , V_5 ) ;
if ( ! F_30 ( & V_75 -> V_52 ) )
continue;
F_28 ( & V_75 -> V_52 , V_74 ) ;
F_45 ( & V_75 -> V_46 ) ;
}
F_26 ( & V_25 -> V_53 ) ;
}
void F_50 ( struct V_73 * V_74 )
{
struct V_1 * V_75 ;
while ( ! F_30 ( V_74 ) ) {
V_75 = F_51 ( V_74 ,
struct V_1 ,
V_52 ) ;
F_52 ( & V_75 -> V_52 ) ;
F_53 ( V_75 ) ;
}
}
void F_54 ( struct V_73 * V_74 ,
struct V_32 * log )
{
int V_76 = log -> V_77 % 2 ;
F_25 ( & log -> V_78 [ V_76 ] ) ;
F_55 ( V_74 , & log -> V_74 [ V_76 ] ) ;
F_26 ( & log -> V_78 [ V_76 ] ) ;
}
void F_56 ( struct V_32 * log , T_1 V_79 )
{
struct V_1 * V_75 ;
int V_76 = V_79 % 2 ;
F_25 ( & log -> V_78 [ V_76 ] ) ;
while ( ! F_30 ( & log -> V_74 [ V_76 ] ) ) {
V_75 = F_51 ( & log -> V_74 [ V_76 ] ,
struct V_1 ,
V_52 ) ;
F_52 ( & V_75 -> V_52 ) ;
F_26 ( & log -> V_78 [ V_76 ] ) ;
F_57 ( V_75 -> V_47 , F_58 ( V_43 ,
& V_75 -> V_37 ) ) ;
F_53 ( V_75 ) ;
F_25 ( & log -> V_78 [ V_76 ] ) ;
}
F_26 ( & log -> V_78 [ V_76 ] ) ;
}
void F_59 ( struct V_32 * log , T_1 V_79 )
{
struct V_1 * V_75 ;
int V_76 = V_79 % 2 ;
F_25 ( & log -> V_78 [ V_76 ] ) ;
while ( ! F_30 ( & log -> V_74 [ V_76 ] ) ) {
V_75 = F_51 ( & log -> V_74 [ V_76 ] ,
struct V_1 ,
V_52 ) ;
F_52 ( & V_75 -> V_52 ) ;
F_26 ( & log -> V_78 [ V_76 ] ) ;
F_53 ( V_75 ) ;
F_25 ( & log -> V_78 [ V_76 ] ) ;
}
F_26 ( & log -> V_78 [ V_76 ] ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_73 * V_80 ;
struct V_62 * V_63 ;
F_60 ( V_2 -> V_13 , V_2 ) ;
if ( F_61 ( & V_2 -> V_46 ) ) {
if ( V_2 -> V_13 )
F_62 ( V_2 -> V_13 ) ;
while ( ! F_30 ( & V_2 -> V_48 ) ) {
V_80 = V_2 -> V_48 . V_81 ;
V_63 = F_63 ( V_80 , struct V_62 , V_48 ) ;
F_64 ( & V_63 -> V_48 ) ;
F_65 ( V_63 ) ;
}
F_66 ( V_34 , V_2 ) ;
}
}
void F_67 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_32 * V_7 = F_16 ( V_13 ) -> V_7 ;
struct V_5 * V_8 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_53 ) ;
V_8 = & V_2 -> V_5 ;
F_68 ( V_8 , & V_25 -> V_25 ) ;
if ( V_25 -> V_27 == V_8 )
V_25 -> V_27 = NULL ;
F_19 ( V_44 , & V_2 -> V_37 ) ;
F_26 ( & V_25 -> V_53 ) ;
F_27 ( & V_7 -> V_55 ) ;
F_52 ( & V_2 -> V_49 ) ;
V_7 -> V_57 -- ;
F_69 ( V_13 , V_2 ) ;
if ( F_70 ( & V_25 -> V_25 ) &&
! F_71 ( V_13 -> V_82 , V_83 ) ) {
F_27 ( & V_7 -> V_17 -> V_58 ) ;
F_52 ( & F_16 ( V_13 ) -> V_84 ) ;
F_31 ( & V_7 -> V_17 -> V_58 ) ;
}
if ( ! V_7 -> V_57 ) {
F_27 ( & V_7 -> V_17 -> V_58 ) ;
F_29 ( F_30 ( & V_7 -> V_59 ) ) ;
F_52 ( & V_7 -> V_59 ) ;
F_31 ( & V_7 -> V_17 -> V_58 ) ;
}
F_31 ( & V_7 -> V_55 ) ;
F_37 ( & V_2 -> V_47 ) ;
}
static void F_72 ( struct V_85 * V_86 )
{
struct V_1 * V_75 ;
V_75 = F_73 ( V_86 , struct V_1 , V_87 ) ;
F_74 ( V_75 -> V_13 , V_75 , 1 ) ;
F_75 ( & V_75 -> V_51 ) ;
}
int F_76 ( struct V_32 * V_7 , int V_88 )
{
struct V_73 V_89 , V_90 ;
struct V_1 * V_75 , * V_81 ;
int V_91 = 0 ;
F_22 ( & V_89 ) ;
F_22 ( & V_90 ) ;
F_77 ( & V_7 -> V_92 ) ;
F_27 ( & V_7 -> V_55 ) ;
F_78 ( & V_7 -> V_56 , & V_89 ) ;
while ( ! F_30 ( & V_89 ) && V_88 ) {
V_75 = F_51 ( & V_89 , struct V_1 ,
V_49 ) ;
F_79 ( & V_75 -> V_49 ,
& V_7 -> V_56 ) ;
F_45 ( & V_75 -> V_46 ) ;
F_31 ( & V_7 -> V_55 ) ;
F_80 ( & V_75 -> V_87 ,
F_72 , NULL , NULL ) ;
F_28 ( & V_75 -> V_50 , & V_90 ) ;
F_81 ( V_7 -> V_17 -> V_93 ,
& V_75 -> V_87 ) ;
F_82 () ;
F_27 ( & V_7 -> V_55 ) ;
if ( V_88 != - 1 )
V_88 -- ;
V_91 ++ ;
}
F_55 ( & V_89 , & V_7 -> V_56 ) ;
F_31 ( & V_7 -> V_55 ) ;
F_83 (ordered, next, &works, work_list) {
F_52 ( & V_75 -> V_50 ) ;
F_84 ( & V_75 -> V_51 ) ;
F_53 ( V_75 ) ;
F_82 () ;
}
F_85 ( & V_7 -> V_92 ) ;
return V_91 ;
}
void F_86 ( struct V_16 * V_17 , int V_88 )
{
struct V_32 * V_7 ;
struct V_73 V_89 ;
int V_94 ;
F_22 ( & V_89 ) ;
F_77 ( & V_17 -> V_95 ) ;
F_27 ( & V_17 -> V_58 ) ;
F_78 ( & V_17 -> V_60 , & V_89 ) ;
while ( ! F_30 ( & V_89 ) && V_88 ) {
V_7 = F_51 ( & V_89 , struct V_32 ,
V_59 ) ;
V_7 = F_87 ( V_7 ) ;
F_29 ( ! V_7 ) ;
F_79 ( & V_7 -> V_59 ,
& V_17 -> V_60 ) ;
F_31 ( & V_17 -> V_58 ) ;
V_94 = F_76 ( V_7 , V_88 ) ;
F_88 ( V_7 ) ;
F_27 ( & V_17 -> V_58 ) ;
if ( V_88 != - 1 ) {
V_88 -= V_94 ;
F_36 ( V_88 < 0 ) ;
}
}
F_55 ( & V_89 , & V_17 -> V_60 ) ;
F_31 ( & V_17 -> V_58 ) ;
F_85 ( & V_17 -> V_95 ) ;
}
int F_89 ( struct V_96 * V_97 ,
struct V_32 * V_7 , int V_47 )
{
struct V_98 * V_98 ;
struct V_13 * V_13 ;
struct V_99 * V_100 = V_97 -> V_101 ;
struct V_73 V_89 ;
struct V_73 V_90 ;
struct V_102 * V_86 , * V_81 ;
int V_26 = 0 ;
F_22 ( & V_89 ) ;
F_22 ( & V_90 ) ;
F_77 ( & V_7 -> V_17 -> V_103 ) ;
F_27 ( & V_7 -> V_17 -> V_58 ) ;
F_78 ( & V_100 -> V_84 , & V_89 ) ;
while ( ! F_30 ( & V_89 ) ) {
V_98 = F_63 ( V_89 . V_81 , struct V_98 ,
V_84 ) ;
V_13 = & V_98 -> V_104 ;
F_52 ( & V_98 -> V_84 ) ;
V_13 = F_18 ( V_13 ) ;
if ( ! V_13 )
continue;
if ( ! V_47 )
F_28 ( & F_16 ( V_13 ) -> V_84 ,
& V_100 -> V_84 ) ;
F_31 ( & V_7 -> V_17 -> V_58 ) ;
V_86 = F_90 ( V_13 , V_47 , 1 ) ;
if ( ! V_86 ) {
F_27 ( & V_7 -> V_17 -> V_58 ) ;
if ( F_30 ( & F_16 ( V_13 ) -> V_84 ) )
F_28 ( & V_98 -> V_84 ,
& V_89 ) ;
F_55 ( & V_89 ,
& V_100 -> V_84 ) ;
F_31 ( & V_7 -> V_17 -> V_58 ) ;
V_26 = - V_36 ;
goto V_70;
}
F_28 ( & V_86 -> V_48 , & V_90 ) ;
F_81 ( V_7 -> V_17 -> V_93 ,
& V_86 -> V_86 ) ;
F_82 () ;
F_27 ( & V_7 -> V_17 -> V_58 ) ;
}
F_31 ( & V_7 -> V_17 -> V_58 ) ;
V_70:
F_83 (work, next, &works, list) {
F_52 ( & V_86 -> V_48 ) ;
F_91 ( V_86 ) ;
}
F_85 ( & V_7 -> V_17 -> V_103 ) ;
return V_26 ;
}
void F_74 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
int V_47 )
{
T_1 V_28 = V_2 -> V_3 ;
T_1 V_105 = V_28 + V_2 -> V_4 - 1 ;
F_92 ( V_13 , V_2 ) ;
if ( ! F_58 ( V_45 , & V_2 -> V_37 ) )
F_93 ( V_13 -> V_82 , V_28 , V_105 ) ;
if ( V_47 ) {
F_57 ( V_2 -> V_47 , F_58 ( V_44 ,
& V_2 -> V_37 ) ) ;
}
}
int F_94 ( struct V_13 * V_13 , T_1 V_28 , T_1 V_4 )
{
int V_26 = 0 ;
T_1 V_105 ;
T_1 V_106 ;
struct V_1 * V_75 ;
if ( V_28 + V_4 < V_28 ) {
V_106 = F_95 ( V_107 ) ;
} else {
V_106 = V_28 + V_4 - 1 ;
if ( V_106 > F_95 ( V_107 ) )
V_106 = F_95 ( V_107 ) ;
}
V_26 = F_93 ( V_13 -> V_82 , V_28 , V_106 ) ;
if ( V_26 )
return V_26 ;
if ( F_58 ( V_108 ,
& F_16 ( V_13 ) -> V_109 ) ) {
V_26 = F_93 ( V_13 -> V_82 , V_28 ,
V_106 ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_96 ( V_13 -> V_82 , V_28 , V_106 ) ;
if ( V_26 )
return V_26 ;
V_105 = V_106 ;
while ( 1 ) {
V_75 = F_97 ( V_13 , V_105 ) ;
if ( ! V_75 )
break;
if ( V_75 -> V_3 > V_106 ) {
F_53 ( V_75 ) ;
break;
}
if ( V_75 -> V_3 + V_75 -> V_4 <= V_28 ) {
F_53 ( V_75 ) ;
break;
}
F_74 ( V_13 , V_75 , 1 ) ;
V_105 = V_75 -> V_3 ;
if ( F_58 ( V_71 , & V_75 -> V_37 ) )
V_26 = - V_110 ;
F_53 ( V_75 ) ;
if ( V_26 || V_105 == 0 || V_105 == V_28 )
break;
V_105 -- ;
}
return V_26 ;
}
struct V_1 * F_98 ( struct V_13 * V_13 ,
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
F_45 ( & V_2 -> V_46 ) ;
V_70:
F_26 ( & V_25 -> V_53 ) ;
return V_2 ;
}
struct V_1 * F_99 ( struct V_13 * V_13 ,
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
F_45 ( & V_2 -> V_46 ) ;
F_26 ( & V_25 -> V_53 ) ;
return V_2 ;
}
struct V_1 *
F_97 ( struct V_13 * V_13 , T_1 V_3 )
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
F_45 ( & V_2 -> V_46 ) ;
V_70:
F_26 ( & V_25 -> V_53 ) ;
return V_2 ;
}
int F_100 ( struct V_13 * V_13 , T_1 V_15 ,
struct V_1 * V_75 )
{
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_33 ;
T_1 V_111 ;
T_1 V_112 ;
T_1 V_113 = F_101 ( V_13 ) ;
struct V_5 * V_8 ;
struct V_5 * V_21 = NULL ;
struct V_1 * V_22 ;
int V_26 = 1 ;
F_25 ( & V_25 -> V_53 ) ;
if ( V_75 ) {
V_15 = F_1 ( V_75 ) ;
if ( F_58 ( V_114 , & V_75 -> V_37 ) )
V_15 = F_41 ( V_15 ,
V_75 -> V_3 +
V_75 -> V_42 ) ;
} else {
V_15 = F_102 ( V_15 , F_16 ( V_13 ) -> V_7 -> V_115 ) ;
}
V_111 = F_16 ( V_13 ) -> V_111 ;
if ( V_111 > V_113 ) {
F_16 ( V_13 ) -> V_111 = V_113 ;
V_26 = 0 ;
goto V_70;
}
if ( V_111 == V_113 )
goto V_70;
if ( V_15 <= V_111 &&
( ! V_75 || V_75 -> V_116 <= V_111 ) )
goto V_70;
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
if ( F_58 ( V_117 , & V_22 -> V_37 ) )
continue;
if ( V_22 -> V_3 + V_22 -> V_4 <= V_111 )
break;
if ( V_22 -> V_3 >= V_113 )
break;
if ( F_1 ( V_22 ) > V_111 ) {
if ( V_22 -> V_116 < V_15 )
V_22 -> V_116 = V_15 ;
if ( V_75 &&
V_75 -> V_116 >
V_22 -> V_116 )
V_22 -> V_116 =
V_75 -> V_116 ;
goto V_70;
}
}
V_112 = F_103 ( T_1 , V_15 , V_113 ) ;
if ( V_75 && V_75 -> V_116 > V_112 )
V_112 = F_103 ( T_1 , V_75 -> V_116 , V_113 ) ;
F_16 ( V_13 ) -> V_111 = V_112 ;
V_26 = 0 ;
V_70:
if ( V_75 )
F_19 ( V_117 , & V_75 -> V_37 ) ;
F_26 ( & V_25 -> V_53 ) ;
return V_26 ;
}
int F_104 ( struct V_13 * V_13 , T_1 V_15 , T_1 V_118 ,
T_2 * V_63 , int V_4 )
{
struct V_62 * V_119 ;
struct V_1 * V_75 ;
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_33 ;
unsigned long V_120 ;
unsigned long V_121 ;
T_2 V_115 = F_16 ( V_13 ) -> V_7 -> V_115 ;
int V_76 = 0 ;
V_75 = F_98 ( V_13 , V_15 ) ;
if ( ! V_75 )
return 0 ;
F_25 ( & V_25 -> V_53 ) ;
F_105 (ordered_sum, &ordered->list, list) {
if ( V_118 >= V_119 -> V_122 &&
V_118 < V_119 -> V_122 + V_119 -> V_4 ) {
V_121 = ( V_118 - V_119 -> V_122 ) >>
V_13 -> V_18 -> V_123 ;
V_120 = V_119 -> V_4 >>
V_13 -> V_18 -> V_123 ;
V_120 = F_103 ( int , V_4 - V_76 , V_120 - V_121 ) ;
memcpy ( V_63 + V_76 , V_119 -> V_124 + V_121 ,
V_120 ) ;
V_76 += ( int ) V_120 ;
if ( V_76 == V_4 )
goto V_70;
V_118 += V_120 * V_115 ;
}
}
V_70:
F_26 ( & V_25 -> V_53 ) ;
F_53 ( V_75 ) ;
return V_76 ;
}
void F_106 ( struct V_96 * V_97 ,
struct V_32 * V_7 , struct V_13 * V_13 )
{
struct V_99 * V_100 = V_97 -> V_101 ;
T_1 V_125 ;
V_125 = F_40 ( F_16 ( V_13 ) -> V_126 , F_16 ( V_13 ) -> V_127 ) ;
if ( V_125 <= V_7 -> V_17 -> V_128 )
return;
F_27 ( & V_7 -> V_17 -> V_58 ) ;
if ( F_30 ( & F_16 ( V_13 ) -> V_84 ) ) {
F_28 ( & F_16 ( V_13 ) -> V_84 ,
& V_100 -> V_84 ) ;
}
F_31 ( & V_7 -> V_17 -> V_58 ) ;
}
int T_3 F_107 ( void )
{
V_34 = F_108 ( L_5 ,
sizeof( struct V_1 ) , 0 ,
V_129 | V_130 ,
NULL ) ;
if ( ! V_34 )
return - V_36 ;
return 0 ;
}
void F_109 ( void )
{
if ( V_34 )
F_110 ( V_34 ) ;
}
