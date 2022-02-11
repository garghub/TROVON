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
T_5 V_52 ;
unsigned long V_46 ;
struct V_8 * V_8 = F_14 ( V_40 , struct V_8 , V_47 ) ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
V_52 = F_21 ( & V_8 -> V_50 ) ;
V_52 += V_51 ;
F_24 ( & V_8 -> V_50 , & V_8 -> V_32 , V_52 ) ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
return 0 ;
}
static int F_25 ( struct V_39 * V_40 , struct V_53 * V_54 )
{
T_3 V_55 ;
T_1 V_56 ;
unsigned long V_46 ;
struct V_8 * V_8 = F_14 ( V_40 , struct V_8 , V_47 ) ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
V_55 = F_21 ( & V_8 -> V_50 ) ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
V_54 -> V_57 = F_26 ( V_55 , 1000000000 , & V_56 ) ;
V_54 -> V_58 = V_56 ;
return 0 ;
}
static int F_27 ( struct V_39 * V_40 ,
const struct V_53 * V_54 )
{
T_3 V_55 ;
unsigned long V_46 ;
struct V_8 * V_8 = F_14 ( V_40 , struct V_8 , V_47 ) ;
V_55 = V_54 -> V_57 * 1000000000ULL ;
V_55 += V_54 -> V_58 ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
F_24 ( & V_8 -> V_50 , & V_8 -> V_32 , V_55 ) ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
return 0 ;
}
static int F_28 ( struct V_39 * V_40 ,
struct V_59 * V_60 , int V_61 )
{
return - V_62 ;
}
static void F_29 ( struct V_63 * V_64 )
{
struct V_53 V_54 ;
struct V_8 * V_8 = F_14 ( V_64 , struct V_8 , V_65 . V_64 ) ;
F_6 ( V_8 , V_66 , V_67 ) ;
F_6 ( V_8 , V_68 , V_69 ) ;
F_25 ( & V_8 -> V_47 , & V_54 ) ;
F_30 ( L_4 , V_54 . V_57 , V_54 . V_58 ) ;
F_31 ( & V_8 -> V_65 , V_70 ) ;
}
static void F_32 ( struct V_71 * V_72 , struct V_8 * V_8 )
{
V_8 -> V_73 = F_33 ( V_72 , L_5 ) ;
if ( F_34 ( V_8 -> V_73 ) ) {
F_35 ( V_72 , L_6 ) ;
V_8 -> V_73 = NULL ;
return;
}
F_36 ( V_8 -> V_73 ) ;
}
static void F_37 ( struct V_8 * V_8 )
{
F_38 ( V_8 -> V_73 ) ;
}
static int F_39 ( struct V_74 * V_75 , unsigned int V_76 ,
T_6 V_77 , T_7 V_78 )
{
T_6 * V_79 ;
unsigned int V_80 ;
T_7 * V_81 , * V_82 = V_75 -> V_82 ;
switch ( V_76 ) {
case V_83 :
case V_84 :
V_80 = V_85 + F_40 ( V_82 ) + V_86 ;
break;
case V_87 :
case V_88 :
V_80 = V_89 ;
break;
case V_90 :
V_80 = V_85 ;
break;
case V_91 :
V_80 = V_85 + V_92 ;
break;
default:
return 0 ;
}
if ( V_75 -> V_93 + V_85 < V_80 + V_94 + sizeof( * V_79 ) )
return 0 ;
if ( F_41 ( V_76 & V_95 ) )
V_81 = V_82 + V_80 + V_96 ;
else
V_81 = V_82 + V_80 ;
V_79 = ( T_6 * ) ( V_82 + V_80 + V_94 ) ;
return ( V_78 == ( * V_81 & 0xf ) && V_77 == F_42 ( * V_79 ) ) ;
}
static T_3 F_43 ( struct V_8 * V_8 , struct V_74 * V_75 , int V_97 )
{
T_3 V_55 = 0 ;
struct V_1 * V_2 ;
struct V_34 * V_35 , * V_36 ;
unsigned int V_98 = F_44 ( V_75 ) ;
unsigned long V_46 ;
T_6 V_79 ;
T_7 V_99 ;
if ( V_98 == V_100 )
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
V_99 = ( V_2 -> V_5 >> V_101 ) & V_102 ;
V_79 = ( V_2 -> V_5 >> V_103 ) & V_104 ;
if ( V_97 == F_3 ( V_2 ) &&
F_39 ( V_75 , V_98 , V_79 , V_99 ) ) {
V_55 = F_45 ( & V_8 -> V_50 , V_2 -> V_9 ) ;
F_11 ( & V_2 -> V_23 ) ;
F_17 ( & V_2 -> V_23 , & V_8 -> V_22 ) ;
break;
}
}
F_22 ( & V_8 -> V_49 , V_46 ) ;
return V_55 ;
}
void F_46 ( struct V_8 * V_8 , struct V_74 * V_75 )
{
T_3 V_55 ;
struct V_105 * V_106 ;
if ( ! V_8 -> V_107 )
return;
V_55 = F_43 ( V_8 , V_75 , V_25 ) ;
if ( ! V_55 )
return;
V_106 = F_47 ( V_75 ) ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_108 = F_48 ( V_55 ) ;
}
void F_49 ( struct V_8 * V_8 , struct V_74 * V_75 )
{
T_3 V_55 ;
struct V_105 V_106 ;
if ( ! ( F_50 ( V_75 ) -> V_109 & V_110 ) )
return;
V_55 = F_43 ( V_8 , V_75 , V_26 ) ;
if ( ! V_55 )
return;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . V_108 = F_48 ( V_55 ) ;
F_51 ( V_75 , & V_106 ) ;
}
int F_52 ( struct V_71 * V_72 , struct V_8 * V_8 ,
T_1 V_44 , T_1 V_111 )
{
#ifdef F_53
int V_112 , V_18 ;
unsigned long V_46 ;
V_8 -> V_47 = V_113 ;
V_8 -> clock = F_54 ( & V_8 -> V_47 , V_72 ) ;
if ( F_34 ( V_8 -> clock ) ) {
V_112 = F_55 ( V_8 -> clock ) ;
V_8 -> clock = NULL ;
return V_112 ;
}
F_56 ( & V_8 -> V_49 ) ;
V_8 -> V_32 . V_114 = F_13 ;
V_8 -> V_32 . V_115 = F_57 ( 32 ) ;
V_8 -> V_48 = V_44 ;
V_8 -> V_32 . V_44 = V_44 ;
V_8 -> V_32 . V_111 = V_111 ;
F_58 ( & V_8 -> V_27 ) ;
F_58 ( & V_8 -> V_22 ) ;
for ( V_18 = 0 ; V_18 < V_116 ; V_18 ++ )
F_17 ( & V_8 -> V_117 [ V_18 ] . V_23 , & V_8 -> V_22 ) ;
F_32 ( V_72 , V_8 ) ;
F_6 ( V_8 , V_66 , V_67 ) ;
F_6 ( V_8 , V_68 , V_69 ) ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
F_24 ( & V_8 -> V_50 , & V_8 -> V_32 , F_59 ( F_60 () ) ) ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
F_61 ( & V_8 -> V_65 , F_29 ) ;
F_31 ( & V_8 -> V_65 , V_70 ) ;
V_8 -> V_118 = F_62 ( V_8 -> clock ) ;
#endif
return 0 ;
}
void F_63 ( struct V_8 * V_8 )
{
#ifdef F_53
if ( V_8 -> clock ) {
F_64 ( V_8 -> clock ) ;
F_65 ( & V_8 -> V_65 ) ;
}
if ( V_8 -> V_73 )
F_37 ( V_8 ) ;
#endif
}
