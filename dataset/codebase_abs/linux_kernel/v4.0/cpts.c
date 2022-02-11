static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , V_2 -> V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 >> V_6 ) & V_7 ;
}
static int F_4 ( struct V_8 * V_8 , T_1 * V_5 , T_1 * V_9 )
{
T_1 V_10 = F_5 ( V_8 , V_11 ) ;
if ( V_10 & V_12 ) {
* V_5 = F_5 ( V_8 , V_13 ) ;
* V_9 = F_5 ( V_8 , V_14 ) ;
F_6 ( V_8 , V_15 , V_16 ) ;
return 0 ;
}
return - 1 ;
}
static int F_7 ( struct V_8 * V_8 , int V_17 )
{
int V_18 , type = - 1 ;
T_1 V_19 , V_20 ;
struct V_1 * V_2 ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
if ( F_4 ( V_8 , & V_19 , & V_20 ) )
break;
if ( F_8 ( & V_8 -> V_22 ) ) {
F_9 ( L_1 ) ;
return - 1 ;
}
V_2 = F_10 ( & V_8 -> V_22 , struct V_1 , V_23 ) ;
V_2 -> V_4 = V_3 + 2 ;
V_2 -> V_5 = V_19 ;
V_2 -> V_9 = V_20 ;
type = F_3 ( V_2 ) ;
switch ( type ) {
case V_24 :
case V_25 :
case V_26 :
F_11 ( & V_2 -> V_23 ) ;
F_12 ( & V_2 -> V_23 , & V_8 -> V_27 ) ;
break;
case V_28 :
case V_29 :
case V_30 :
break;
default:
F_9 ( L_2 ) ;
break;
}
if ( type == V_17 )
break;
}
return type == V_17 ? 0 : - 1 ;
}
static T_2 F_13 ( const struct V_31 * V_32 )
{
T_3 V_33 = 0 ;
struct V_1 * V_2 ;
struct V_34 * V_35 , * V_36 ;
struct V_8 * V_8 = F_14 ( V_32 , struct V_8 , V_32 ) ;
F_6 ( V_8 , V_37 , V_38 ) ;
if ( F_7 ( V_8 , V_24 ) )
F_9 ( L_3 ) ;
F_15 (this, next, &cpts->events) {
V_2 = F_16 ( V_35 , struct V_1 , V_23 ) ;
if ( F_3 ( V_2 ) == V_24 ) {
F_11 ( & V_2 -> V_23 ) ;
F_17 ( & V_2 -> V_23 , & V_8 -> V_22 ) ;
V_33 = V_2 -> V_9 ;
break;
}
}
return V_33 ;
}
static int F_18 ( struct V_39 * V_40 , T_4 V_41 )
{
T_3 V_42 ;
T_1 V_43 , V_44 ;
int V_45 = 0 ;
unsigned long V_46 ;
struct V_8 * V_8 = F_14 ( V_40 , struct V_8 , V_47 ) ;
if ( V_41 < 0 ) {
V_45 = 1 ;
V_41 = - V_41 ;
}
V_44 = V_8 -> V_48 ;
V_42 = V_44 ;
V_42 *= V_41 ;
V_43 = F_19 ( V_42 , 1000000000ULL ) ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
F_21 ( & V_8 -> V_50 ) ;
V_8 -> V_32 . V_44 = V_45 ? V_44 - V_43 : V_44 + V_43 ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
return 0 ;
}
static int F_23 ( struct V_39 * V_40 , T_5 V_51 )
{
unsigned long V_46 ;
struct V_8 * V_8 = F_14 ( V_40 , struct V_8 , V_47 ) ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
F_24 ( & V_8 -> V_50 , V_51 ) ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
return 0 ;
}
static int F_25 ( struct V_39 * V_40 , struct V_52 * V_53 )
{
T_3 V_54 ;
T_1 V_55 ;
unsigned long V_46 ;
struct V_8 * V_8 = F_14 ( V_40 , struct V_8 , V_47 ) ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
V_54 = F_21 ( & V_8 -> V_50 ) ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
V_53 -> V_56 = F_26 ( V_54 , 1000000000 , & V_55 ) ;
V_53 -> V_57 = V_55 ;
return 0 ;
}
static int F_27 ( struct V_39 * V_40 ,
const struct V_52 * V_53 )
{
T_3 V_54 ;
unsigned long V_46 ;
struct V_8 * V_8 = F_14 ( V_40 , struct V_8 , V_47 ) ;
V_54 = V_53 -> V_56 * 1000000000ULL ;
V_54 += V_53 -> V_57 ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
F_28 ( & V_8 -> V_50 , & V_8 -> V_32 , V_54 ) ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
return 0 ;
}
static int F_29 ( struct V_39 * V_40 ,
struct V_58 * V_59 , int V_60 )
{
return - V_61 ;
}
static void F_30 ( struct V_62 * V_63 )
{
struct V_52 V_53 ;
struct V_8 * V_8 = F_14 ( V_63 , struct V_8 , V_64 . V_63 ) ;
F_6 ( V_8 , V_65 , V_66 ) ;
F_6 ( V_8 , V_67 , V_68 ) ;
F_25 ( & V_8 -> V_47 , & V_53 ) ;
F_31 ( L_4 , V_53 . V_56 , V_53 . V_57 ) ;
F_32 ( & V_8 -> V_64 , V_69 ) ;
}
static void F_33 ( struct V_70 * V_71 , struct V_8 * V_8 )
{
V_8 -> V_72 = F_34 ( V_71 , L_5 ) ;
if ( F_35 ( V_8 -> V_72 ) ) {
F_36 ( V_71 , L_6 ) ;
V_8 -> V_72 = NULL ;
return;
}
F_37 ( V_8 -> V_72 ) ;
}
static void F_38 ( struct V_8 * V_8 )
{
F_39 ( V_8 -> V_72 ) ;
}
static int F_40 ( struct V_73 * V_74 , unsigned int V_75 ,
T_6 V_76 , T_7 V_77 )
{
T_6 * V_78 ;
unsigned int V_79 = 0 ;
T_7 * V_80 , * V_81 = V_74 -> V_81 ;
if ( V_75 & V_82 )
V_79 += V_83 ;
switch ( V_75 & V_84 ) {
case V_85 :
V_79 += V_86 + F_41 ( V_81 + V_79 ) + V_87 ;
break;
case V_88 :
V_79 += V_86 + V_89 + V_87 ;
break;
case V_90 :
V_79 += V_86 ;
break;
default:
return 0 ;
}
if ( V_74 -> V_91 + V_86 < V_79 + V_92 + sizeof( * V_78 ) )
return 0 ;
if ( F_42 ( V_75 & V_93 ) )
V_80 = V_81 + V_79 + V_94 ;
else
V_80 = V_81 + V_79 ;
V_78 = ( T_6 * ) ( V_81 + V_79 + V_92 ) ;
return ( V_77 == ( * V_80 & 0xf ) && V_76 == F_43 ( * V_78 ) ) ;
}
static T_3 F_44 ( struct V_8 * V_8 , struct V_73 * V_74 , int V_95 )
{
T_3 V_54 = 0 ;
struct V_1 * V_2 ;
struct V_34 * V_35 , * V_36 ;
unsigned int V_96 = F_45 ( V_74 ) ;
unsigned long V_46 ;
T_6 V_78 ;
T_7 V_97 ;
if ( V_96 == V_98 )
return 0 ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
F_7 ( V_8 , V_24 ) ;
F_15 (this, next, &cpts->events) {
V_2 = F_16 ( V_35 , struct V_1 , V_23 ) ;
if ( F_1 ( V_2 ) ) {
F_11 ( & V_2 -> V_23 ) ;
F_17 ( & V_2 -> V_23 , & V_8 -> V_22 ) ;
continue;
}
V_97 = ( V_2 -> V_5 >> V_99 ) & V_100 ;
V_78 = ( V_2 -> V_5 >> V_101 ) & V_102 ;
if ( V_95 == F_3 ( V_2 ) &&
F_40 ( V_74 , V_96 , V_78 , V_97 ) ) {
V_54 = F_46 ( & V_8 -> V_50 , V_2 -> V_9 ) ;
F_11 ( & V_2 -> V_23 ) ;
F_17 ( & V_2 -> V_23 , & V_8 -> V_22 ) ;
break;
}
}
F_22 ( & V_8 -> V_49 , V_46 ) ;
return V_54 ;
}
void F_47 ( struct V_8 * V_8 , struct V_73 * V_74 )
{
T_3 V_54 ;
struct V_103 * V_104 ;
if ( ! V_8 -> V_105 )
return;
V_54 = F_44 ( V_8 , V_74 , V_25 ) ;
if ( ! V_54 )
return;
V_104 = F_48 ( V_74 ) ;
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
V_104 -> V_106 = F_49 ( V_54 ) ;
}
void F_50 ( struct V_8 * V_8 , struct V_73 * V_74 )
{
T_3 V_54 ;
struct V_103 V_104 ;
if ( ! ( F_51 ( V_74 ) -> V_107 & V_108 ) )
return;
V_54 = F_44 ( V_8 , V_74 , V_26 ) ;
if ( ! V_54 )
return;
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_106 = F_49 ( V_54 ) ;
F_52 ( V_74 , & V_104 ) ;
}
int F_53 ( struct V_70 * V_71 , struct V_8 * V_8 ,
T_1 V_44 , T_1 V_109 )
{
#ifdef F_54
int V_110 , V_18 ;
unsigned long V_46 ;
V_8 -> V_47 = V_111 ;
V_8 -> clock = F_55 ( & V_8 -> V_47 , V_71 ) ;
if ( F_35 ( V_8 -> clock ) ) {
V_110 = F_56 ( V_8 -> clock ) ;
V_8 -> clock = NULL ;
return V_110 ;
}
F_57 ( & V_8 -> V_49 ) ;
V_8 -> V_32 . V_112 = F_13 ;
V_8 -> V_32 . V_113 = F_58 ( 32 ) ;
V_8 -> V_48 = V_44 ;
V_8 -> V_32 . V_44 = V_44 ;
V_8 -> V_32 . V_109 = V_109 ;
F_59 ( & V_8 -> V_27 ) ;
F_59 ( & V_8 -> V_22 ) ;
for ( V_18 = 0 ; V_18 < V_114 ; V_18 ++ )
F_17 ( & V_8 -> V_115 [ V_18 ] . V_23 , & V_8 -> V_22 ) ;
F_33 ( V_71 , V_8 ) ;
F_6 ( V_8 , V_65 , V_66 ) ;
F_6 ( V_8 , V_67 , V_68 ) ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
F_28 ( & V_8 -> V_50 , & V_8 -> V_32 , F_60 ( F_61 () ) ) ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
F_62 ( & V_8 -> V_64 , F_30 ) ;
F_32 ( & V_8 -> V_64 , V_69 ) ;
V_8 -> V_116 = F_63 ( V_8 -> clock ) ;
#endif
return 0 ;
}
void F_64 ( struct V_8 * V_8 )
{
#ifdef F_54
if ( V_8 -> clock ) {
F_65 ( V_8 -> clock ) ;
F_66 ( & V_8 -> V_64 ) ;
}
if ( V_8 -> V_72 )
F_38 ( V_8 ) ;
#endif
}
