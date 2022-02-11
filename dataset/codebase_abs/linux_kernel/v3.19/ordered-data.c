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
F_22 ( & V_2 -> V_53 ) ;
F_24 ( V_13 , V_2 ) ;
F_25 ( & V_25 -> V_54 ) ;
V_8 = F_2 ( & V_25 -> V_25 , V_3 ,
& V_2 -> V_5 ) ;
if ( V_8 )
F_6 ( V_13 , - V_55 , V_3 ) ;
F_26 ( & V_25 -> V_54 ) ;
F_27 ( & V_7 -> V_56 ) ;
F_28 ( & V_2 -> V_49 ,
& V_7 -> V_57 ) ;
V_7 -> V_58 ++ ;
if ( V_7 -> V_58 == 1 ) {
F_27 ( & V_7 -> V_17 -> V_59 ) ;
F_29 ( ! F_30 ( & V_7 -> V_60 ) ) ;
F_28 ( & V_7 -> V_60 ,
& V_7 -> V_17 -> V_61 ) ;
F_31 ( & V_7 -> V_17 -> V_59 ) ;
}
F_31 ( & V_7 -> V_56 ) ;
return 0 ;
}
int F_32 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 0 ,
V_62 ) ;
}
int F_33 ( struct V_13 * V_13 , T_1 V_3 ,
T_1 V_28 , T_1 V_4 , T_1 V_29 , int type )
{
return F_15 ( V_13 , V_3 , V_28 , V_4 ,
V_29 , type , 1 ,
V_62 ) ;
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
struct V_63 * V_64 )
{
struct V_24 * V_25 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_54 ) ;
F_28 ( & V_64 -> V_48 , & V_2 -> V_48 ) ;
F_36 ( V_2 -> V_40 < V_64 -> V_4 ) ;
V_2 -> V_40 -= V_64 -> V_4 ;
if ( V_2 -> V_40 == 0 )
F_37 ( & V_2 -> V_47 ) ;
F_26 ( & V_25 -> V_54 ) ;
}
int F_38 ( struct V_13 * V_13 ,
struct V_1 * * V_65 ,
T_1 * V_3 , T_1 V_66 , int V_67 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
int V_26 ;
unsigned long V_37 ;
T_1 V_68 ;
T_1 V_69 ;
T_1 V_70 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_39 ( & V_25 -> V_54 , V_37 ) ;
V_8 = F_14 ( V_25 , * V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_71;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , * V_3 ) ) {
V_26 = 1 ;
goto V_71;
}
V_69 = F_40 ( * V_3 , V_2 -> V_3 ) ;
V_68 = F_41 ( * V_3 + V_66 , V_2 -> V_3 +
V_2 -> V_4 ) ;
* V_3 = V_68 ;
if ( V_69 > V_68 ) {
F_42 ( F_16 ( V_13 ) -> V_7 -> V_17 ,
L_3 , V_69 , V_68 ) ;
}
V_70 = V_68 - V_69 ;
if ( V_70 > V_2 -> V_41 ) {
F_42 ( F_16 ( V_13 ) -> V_7 -> V_17 ,
L_4 ,
V_2 -> V_41 , V_70 ) ;
}
V_2 -> V_41 -= V_70 ;
if ( ! V_67 )
F_19 ( V_72 , & V_2 -> V_37 ) ;
if ( V_2 -> V_41 == 0 ) {
V_26 = F_43 ( V_43 , & V_2 -> V_37 ) ;
if ( F_44 ( & V_2 -> V_47 ) )
F_37 ( & V_2 -> V_47 ) ;
} else {
V_26 = 1 ;
}
V_71:
if ( ! V_26 && V_65 && V_2 ) {
* V_65 = V_2 ;
F_45 ( & V_2 -> V_46 ) ;
}
F_46 ( & V_25 -> V_54 , V_37 ) ;
return V_26 == 0 ;
}
int F_47 ( struct V_13 * V_13 ,
struct V_1 * * V_65 ,
T_1 V_3 , T_1 V_66 , int V_67 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
unsigned long V_37 ;
int V_26 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_39 ( & V_25 -> V_54 , V_37 ) ;
if ( V_65 && * V_65 ) {
V_2 = * V_65 ;
goto V_73;
}
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_26 = 1 ;
goto V_71;
}
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
V_73:
if ( ! F_12 ( V_2 , V_3 ) ) {
V_26 = 1 ;
goto V_71;
}
if ( V_66 > V_2 -> V_41 ) {
F_42 ( F_16 ( V_13 ) -> V_7 -> V_17 ,
L_4 ,
V_2 -> V_41 , V_66 ) ;
}
V_2 -> V_41 -= V_66 ;
if ( ! V_67 )
F_19 ( V_72 , & V_2 -> V_37 ) ;
if ( V_2 -> V_41 == 0 ) {
V_26 = F_43 ( V_43 , & V_2 -> V_37 ) ;
if ( F_44 ( & V_2 -> V_47 ) )
F_37 ( & V_2 -> V_47 ) ;
} else {
V_26 = 1 ;
}
V_71:
if ( ! V_26 && V_65 && V_2 ) {
* V_65 = V_2 ;
F_45 ( & V_2 -> V_46 ) ;
}
F_46 ( & V_25 -> V_54 , V_37 ) ;
return V_26 == 0 ;
}
void F_48 ( struct V_13 * V_13 ,
struct V_74 * V_75 ,
const T_2 V_28 ,
const T_2 V_76 )
{
struct V_24 * V_25 ;
struct V_1 * V_77 ;
struct V_5 * V_20 ;
struct V_5 * V_21 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_54 ) ;
V_20 = F_9 ( & V_25 -> V_25 , V_76 , & V_21 ) ;
if ( ! V_20 )
V_20 = V_21 ;
for (; V_20 ; V_20 = F_11 ( V_20 ) ) {
V_77 = F_3 ( V_20 , struct V_1 , V_5 ) ;
if ( V_77 -> V_3 > V_76 )
continue;
if ( F_1 ( V_77 ) <= V_28 )
break;
if ( ! F_30 ( & V_77 -> V_52 ) )
continue;
if ( F_49 ( V_78 , & V_77 -> V_37 ) )
continue;
F_50 ( & V_77 -> V_52 , V_75 ) ;
F_45 ( & V_77 -> V_46 ) ;
}
F_26 ( & V_25 -> V_54 ) ;
}
void F_51 ( struct V_74 * V_75 )
{
struct V_1 * V_77 ;
while ( ! F_30 ( V_75 ) ) {
V_77 = F_52 ( V_75 ,
struct V_1 ,
V_52 ) ;
F_53 ( & V_77 -> V_52 ) ;
F_54 ( V_77 ) ;
}
}
void F_55 ( struct V_74 * V_75 ,
struct V_32 * log )
{
int V_79 = log -> V_80 % 2 ;
F_25 ( & log -> V_81 [ V_79 ] ) ;
F_56 ( V_75 , & log -> V_75 [ V_79 ] ) ;
F_26 ( & log -> V_81 [ V_79 ] ) ;
}
void F_57 ( struct V_82 * V_83 ,
struct V_32 * log , T_1 V_84 )
{
struct V_1 * V_77 ;
int V_79 = V_84 % 2 ;
F_25 ( & log -> V_81 [ V_79 ] ) ;
while ( ! F_30 ( & log -> V_75 [ V_79 ] ) ) {
V_77 = F_52 ( & log -> V_75 [ V_79 ] ,
struct V_1 ,
V_52 ) ;
F_53 ( & V_77 -> V_52 ) ;
F_26 ( & log -> V_81 [ V_79 ] ) ;
if ( ! F_49 ( V_43 , & V_77 -> V_37 ) &&
! F_49 ( V_45 , & V_77 -> V_37 ) ) {
struct V_13 * V_13 = V_77 -> V_13 ;
T_1 V_28 = V_77 -> V_3 ;
T_1 V_76 = V_77 -> V_3 + V_77 -> V_4 - 1 ;
F_36 ( ! V_13 ) ;
F_58 ( V_13 -> V_85 , V_28 , V_76 ) ;
}
F_59 ( V_77 -> V_47 , F_49 ( V_43 ,
& V_77 -> V_37 ) ) ;
if ( ! F_43 ( V_78 , & V_77 -> V_37 ) )
F_28 ( & V_77 -> V_53 , & V_83 -> V_77 ) ;
F_25 ( & log -> V_81 [ V_79 ] ) ;
}
F_26 ( & log -> V_81 [ V_79 ] ) ;
}
void F_60 ( struct V_32 * log , T_1 V_84 )
{
struct V_1 * V_77 ;
int V_79 = V_84 % 2 ;
F_25 ( & log -> V_81 [ V_79 ] ) ;
while ( ! F_30 ( & log -> V_75 [ V_79 ] ) ) {
V_77 = F_52 ( & log -> V_75 [ V_79 ] ,
struct V_1 ,
V_52 ) ;
F_53 ( & V_77 -> V_52 ) ;
F_26 ( & log -> V_81 [ V_79 ] ) ;
F_54 ( V_77 ) ;
F_25 ( & log -> V_81 [ V_79 ] ) ;
}
F_26 ( & log -> V_81 [ V_79 ] ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_74 * V_86 ;
struct V_63 * V_64 ;
F_61 ( V_2 -> V_13 , V_2 ) ;
if ( F_62 ( & V_2 -> V_46 ) ) {
if ( V_2 -> V_13 )
F_63 ( V_2 -> V_13 ) ;
while ( ! F_30 ( & V_2 -> V_48 ) ) {
V_86 = V_2 -> V_48 . V_87 ;
V_64 = F_64 ( V_86 , struct V_63 , V_48 ) ;
F_65 ( & V_64 -> V_48 ) ;
F_66 ( V_64 ) ;
}
F_67 ( V_34 , V_2 ) ;
}
}
void F_68 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_32 * V_7 = F_16 ( V_13 ) -> V_7 ;
struct V_5 * V_8 ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_54 ) ;
V_8 = & V_2 -> V_5 ;
F_69 ( V_8 , & V_25 -> V_25 ) ;
if ( V_25 -> V_27 == V_8 )
V_25 -> V_27 = NULL ;
F_19 ( V_44 , & V_2 -> V_37 ) ;
F_26 ( & V_25 -> V_54 ) ;
F_27 ( & V_7 -> V_56 ) ;
F_53 ( & V_2 -> V_49 ) ;
V_7 -> V_58 -- ;
F_70 ( V_13 , V_2 ) ;
if ( ! V_7 -> V_58 ) {
F_27 ( & V_7 -> V_17 -> V_59 ) ;
F_29 ( F_30 ( & V_7 -> V_60 ) ) ;
F_53 ( & V_7 -> V_60 ) ;
F_31 ( & V_7 -> V_17 -> V_59 ) ;
}
F_31 ( & V_7 -> V_56 ) ;
F_37 ( & V_2 -> V_47 ) ;
}
static void F_71 ( struct V_88 * V_89 )
{
struct V_1 * V_77 ;
V_77 = F_72 ( V_89 , struct V_1 , V_90 ) ;
F_73 ( V_77 -> V_13 , V_77 , 1 ) ;
F_74 ( & V_77 -> V_51 ) ;
}
int F_75 ( struct V_32 * V_7 , int V_91 )
{
struct V_74 V_92 , V_93 ;
struct V_1 * V_77 , * V_87 ;
int V_94 = 0 ;
F_22 ( & V_92 ) ;
F_22 ( & V_93 ) ;
F_76 ( & V_7 -> V_95 ) ;
F_27 ( & V_7 -> V_56 ) ;
F_77 ( & V_7 -> V_57 , & V_92 ) ;
while ( ! F_30 ( & V_92 ) && V_91 ) {
V_77 = F_52 ( & V_92 , struct V_1 ,
V_49 ) ;
F_78 ( & V_77 -> V_49 ,
& V_7 -> V_57 ) ;
F_45 ( & V_77 -> V_46 ) ;
F_31 ( & V_7 -> V_56 ) ;
F_79 ( & V_77 -> V_90 ,
V_96 ,
F_71 , NULL , NULL ) ;
F_28 ( & V_77 -> V_50 , & V_93 ) ;
F_80 ( V_7 -> V_17 -> V_97 ,
& V_77 -> V_90 ) ;
F_81 () ;
F_27 ( & V_7 -> V_56 ) ;
if ( V_91 != - 1 )
V_91 -- ;
V_94 ++ ;
}
F_56 ( & V_92 , & V_7 -> V_57 ) ;
F_31 ( & V_7 -> V_56 ) ;
F_82 (ordered, next, &works, work_list) {
F_53 ( & V_77 -> V_50 ) ;
F_83 ( & V_77 -> V_51 ) ;
F_54 ( V_77 ) ;
F_81 () ;
}
F_84 ( & V_7 -> V_95 ) ;
return V_94 ;
}
void F_85 ( struct V_16 * V_17 , int V_91 )
{
struct V_32 * V_7 ;
struct V_74 V_92 ;
int V_98 ;
F_22 ( & V_92 ) ;
F_76 ( & V_17 -> V_99 ) ;
F_27 ( & V_17 -> V_59 ) ;
F_77 ( & V_17 -> V_61 , & V_92 ) ;
while ( ! F_30 ( & V_92 ) && V_91 ) {
V_7 = F_52 ( & V_92 , struct V_32 ,
V_60 ) ;
V_7 = F_86 ( V_7 ) ;
F_29 ( ! V_7 ) ;
F_78 ( & V_7 -> V_60 ,
& V_17 -> V_61 ) ;
F_31 ( & V_17 -> V_59 ) ;
V_98 = F_75 ( V_7 , V_91 ) ;
F_87 ( V_7 ) ;
F_27 ( & V_17 -> V_59 ) ;
if ( V_91 != - 1 ) {
V_91 -= V_98 ;
F_36 ( V_91 < 0 ) ;
}
}
F_56 ( & V_92 , & V_17 -> V_61 ) ;
F_31 ( & V_17 -> V_59 ) ;
F_84 ( & V_17 -> V_99 ) ;
}
void F_73 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
int V_47 )
{
T_1 V_28 = V_2 -> V_3 ;
T_1 V_76 = V_28 + V_2 -> V_4 - 1 ;
F_88 ( V_13 , V_2 ) ;
if ( ! F_49 ( V_45 , & V_2 -> V_37 ) )
F_58 ( V_13 -> V_85 , V_28 , V_76 ) ;
if ( V_47 ) {
F_59 ( V_2 -> V_47 , F_49 ( V_44 ,
& V_2 -> V_37 ) ) ;
}
}
int F_89 ( struct V_13 * V_13 , T_1 V_28 , T_1 V_4 )
{
int V_26 = 0 ;
T_1 V_76 ;
T_1 V_100 ;
struct V_1 * V_77 ;
if ( V_28 + V_4 < V_28 ) {
V_100 = F_90 ( T_2 ) ;
} else {
V_100 = V_28 + V_4 - 1 ;
if ( V_100 > F_90 ( T_2 ) )
V_100 = F_90 ( T_2 ) ;
}
V_26 = F_91 ( V_13 , V_28 , V_100 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_92 ( V_13 -> V_85 , V_28 , V_100 ) ;
if ( V_26 )
return V_26 ;
V_76 = V_100 ;
while ( 1 ) {
V_77 = F_93 ( V_13 , V_76 ) ;
if ( ! V_77 )
break;
if ( V_77 -> V_3 > V_100 ) {
F_54 ( V_77 ) ;
break;
}
if ( V_77 -> V_3 + V_77 -> V_4 <= V_28 ) {
F_54 ( V_77 ) ;
break;
}
F_73 ( V_13 , V_77 , 1 ) ;
V_76 = V_77 -> V_3 ;
if ( F_49 ( V_72 , & V_77 -> V_37 ) )
V_26 = - V_101 ;
F_54 ( V_77 ) ;
if ( V_26 || V_76 == 0 || V_76 == V_28 )
break;
V_76 -- ;
}
return V_26 ;
}
struct V_1 * F_94 ( struct V_13 * V_13 ,
T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_54 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_71;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
if ( ! F_12 ( V_2 , V_3 ) )
V_2 = NULL ;
if ( V_2 )
F_45 ( & V_2 -> V_46 ) ;
V_71:
F_26 ( & V_25 -> V_54 ) ;
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
F_25 ( & V_25 -> V_54 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 ) {
V_8 = F_14 ( V_25 , V_3 + V_4 ) ;
if ( ! V_8 )
goto V_71;
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
V_71:
if ( V_2 )
F_45 ( & V_2 -> V_46 ) ;
F_26 ( & V_25 -> V_54 ) ;
return V_2 ;
}
struct V_1 *
F_93 ( struct V_13 * V_13 , T_1 V_3 )
{
struct V_24 * V_25 ;
struct V_5 * V_8 ;
struct V_1 * V_2 = NULL ;
V_25 = & F_16 ( V_13 ) -> V_33 ;
F_25 ( & V_25 -> V_54 ) ;
V_8 = F_14 ( V_25 , V_3 ) ;
if ( ! V_8 )
goto V_71;
V_2 = F_3 ( V_8 , struct V_1 , V_5 ) ;
F_45 ( & V_2 -> V_46 ) ;
V_71:
F_26 ( & V_25 -> V_54 ) ;
return V_2 ;
}
int F_96 ( struct V_13 * V_13 , T_1 V_15 ,
struct V_1 * V_77 )
{
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_33 ;
T_1 V_102 ;
T_1 V_103 ;
T_1 V_104 = F_97 ( V_13 ) ;
struct V_5 * V_8 ;
struct V_5 * V_21 = NULL ;
struct V_1 * V_22 ;
int V_26 = 1 ;
F_25 ( & V_25 -> V_54 ) ;
if ( V_77 ) {
V_15 = F_1 ( V_77 ) ;
if ( F_49 ( V_105 , & V_77 -> V_37 ) )
V_15 = F_41 ( V_15 ,
V_77 -> V_3 +
V_77 -> V_42 ) ;
} else {
V_15 = F_98 ( V_15 , F_16 ( V_13 ) -> V_7 -> V_106 ) ;
}
V_102 = F_16 ( V_13 ) -> V_102 ;
if ( V_102 > V_104 ) {
F_16 ( V_13 ) -> V_102 = V_104 ;
V_26 = 0 ;
goto V_71;
}
if ( V_102 == V_104 )
goto V_71;
if ( V_15 <= V_102 &&
( ! V_77 || V_77 -> V_107 <= V_102 ) )
goto V_71;
if ( V_77 ) {
V_8 = F_11 ( & V_77 -> V_5 ) ;
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
if ( F_49 ( V_108 , & V_22 -> V_37 ) )
continue;
if ( V_22 -> V_3 + V_22 -> V_4 <= V_102 )
break;
if ( V_22 -> V_3 >= V_104 )
break;
if ( F_1 ( V_22 ) > V_102 ) {
if ( V_22 -> V_107 < V_15 )
V_22 -> V_107 = V_15 ;
if ( V_77 &&
V_77 -> V_107 >
V_22 -> V_107 )
V_22 -> V_107 =
V_77 -> V_107 ;
goto V_71;
}
}
V_103 = F_99 ( T_1 , V_15 , V_104 ) ;
if ( V_77 && V_77 -> V_107 > V_103 )
V_103 = F_99 ( T_1 , V_77 -> V_107 , V_104 ) ;
F_16 ( V_13 ) -> V_102 = V_103 ;
V_26 = 0 ;
V_71:
if ( V_77 )
F_19 ( V_108 , & V_77 -> V_37 ) ;
F_26 ( & V_25 -> V_54 ) ;
return V_26 ;
}
int F_100 ( struct V_13 * V_13 , T_1 V_15 , T_1 V_109 ,
T_3 * V_64 , int V_4 )
{
struct V_63 * V_110 ;
struct V_1 * V_77 ;
struct V_24 * V_25 = & F_16 ( V_13 ) -> V_33 ;
unsigned long V_111 ;
unsigned long V_112 ;
T_3 V_106 = F_16 ( V_13 ) -> V_7 -> V_106 ;
int V_79 = 0 ;
V_77 = F_94 ( V_13 , V_15 ) ;
if ( ! V_77 )
return 0 ;
F_25 ( & V_25 -> V_54 ) ;
F_101 (ordered_sum, &ordered->list, list) {
if ( V_109 >= V_110 -> V_113 &&
V_109 < V_110 -> V_113 + V_110 -> V_4 ) {
V_112 = ( V_109 - V_110 -> V_113 ) >>
V_13 -> V_18 -> V_114 ;
V_111 = V_110 -> V_4 >>
V_13 -> V_18 -> V_114 ;
V_111 = F_99 ( int , V_4 - V_79 , V_111 - V_112 ) ;
memcpy ( V_64 + V_79 , V_110 -> V_115 + V_112 ,
V_111 ) ;
V_79 += ( int ) V_111 ;
if ( V_79 == V_4 )
goto V_71;
V_109 += V_111 * V_106 ;
}
}
V_71:
F_26 ( & V_25 -> V_54 ) ;
F_54 ( V_77 ) ;
return V_79 ;
}
int T_4 F_102 ( void )
{
V_34 = F_103 ( L_5 ,
sizeof( struct V_1 ) , 0 ,
V_116 | V_117 ,
NULL ) ;
if ( ! V_34 )
return - V_36 ;
return 0 ;
}
void F_104 ( void )
{
if ( V_34 )
F_105 ( V_34 ) ;
}
