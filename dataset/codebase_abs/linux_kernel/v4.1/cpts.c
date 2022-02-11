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
unsigned long V_46 ;
struct V_8 * V_8 = F_14 ( V_40 , struct V_8 , V_47 ) ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
V_54 = F_21 ( & V_8 -> V_50 ) ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
* V_53 = F_26 ( V_54 ) ;
return 0 ;
}
static int F_27 ( struct V_39 * V_40 ,
const struct V_52 * V_53 )
{
T_3 V_54 ;
unsigned long V_46 ;
struct V_8 * V_8 = F_14 ( V_40 , struct V_8 , V_47 ) ;
V_54 = F_28 ( V_53 ) ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
F_29 ( & V_8 -> V_50 , & V_8 -> V_32 , V_54 ) ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
return 0 ;
}
static int F_30 ( struct V_39 * V_40 ,
struct V_55 * V_56 , int V_57 )
{
return - V_58 ;
}
static void F_31 ( struct V_59 * V_60 )
{
struct V_52 V_53 ;
struct V_8 * V_8 = F_14 ( V_60 , struct V_8 , V_61 . V_60 ) ;
F_6 ( V_8 , V_62 , V_63 ) ;
F_6 ( V_8 , V_64 , V_65 ) ;
F_25 ( & V_8 -> V_47 , & V_53 ) ;
F_32 ( L_4 , V_53 . V_66 , V_53 . V_67 ) ;
F_33 ( & V_8 -> V_61 , V_68 ) ;
}
static void F_34 ( struct V_69 * V_70 , struct V_8 * V_8 )
{
V_8 -> V_71 = F_35 ( V_70 , L_5 ) ;
if ( F_36 ( V_8 -> V_71 ) ) {
F_37 ( V_70 , L_6 ) ;
V_8 -> V_71 = NULL ;
return;
}
F_38 ( V_8 -> V_71 ) ;
}
static void F_39 ( struct V_8 * V_8 )
{
F_40 ( V_8 -> V_71 ) ;
}
static int F_41 ( struct V_72 * V_73 , unsigned int V_74 ,
T_6 V_75 , T_7 V_76 )
{
T_6 * V_77 ;
unsigned int V_78 = 0 ;
T_7 * V_79 , * V_80 = V_73 -> V_80 ;
if ( V_74 & V_81 )
V_78 += V_82 ;
switch ( V_74 & V_83 ) {
case V_84 :
V_78 += V_85 + F_42 ( V_80 + V_78 ) + V_86 ;
break;
case V_87 :
V_78 += V_85 + V_88 + V_86 ;
break;
case V_89 :
V_78 += V_85 ;
break;
default:
return 0 ;
}
if ( V_73 -> V_90 + V_85 < V_78 + V_91 + sizeof( * V_77 ) )
return 0 ;
if ( F_43 ( V_74 & V_92 ) )
V_79 = V_80 + V_78 + V_93 ;
else
V_79 = V_80 + V_78 ;
V_77 = ( T_6 * ) ( V_80 + V_78 + V_91 ) ;
return ( V_76 == ( * V_79 & 0xf ) && V_75 == F_44 ( * V_77 ) ) ;
}
static T_3 F_45 ( struct V_8 * V_8 , struct V_72 * V_73 , int V_94 )
{
T_3 V_54 = 0 ;
struct V_1 * V_2 ;
struct V_34 * V_35 , * V_36 ;
unsigned int V_95 = F_46 ( V_73 ) ;
unsigned long V_46 ;
T_6 V_77 ;
T_7 V_96 ;
if ( V_95 == V_97 )
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
V_96 = ( V_2 -> V_5 >> V_98 ) & V_99 ;
V_77 = ( V_2 -> V_5 >> V_100 ) & V_101 ;
if ( V_94 == F_3 ( V_2 ) &&
F_41 ( V_73 , V_95 , V_77 , V_96 ) ) {
V_54 = F_47 ( & V_8 -> V_50 , V_2 -> V_9 ) ;
F_11 ( & V_2 -> V_23 ) ;
F_17 ( & V_2 -> V_23 , & V_8 -> V_22 ) ;
break;
}
}
F_22 ( & V_8 -> V_49 , V_46 ) ;
return V_54 ;
}
void F_48 ( struct V_8 * V_8 , struct V_72 * V_73 )
{
T_3 V_54 ;
struct V_102 * V_103 ;
if ( ! V_8 -> V_104 )
return;
V_54 = F_45 ( V_8 , V_73 , V_25 ) ;
if ( ! V_54 )
return;
V_103 = F_49 ( V_73 ) ;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
V_103 -> V_105 = F_50 ( V_54 ) ;
}
void F_51 ( struct V_8 * V_8 , struct V_72 * V_73 )
{
T_3 V_54 ;
struct V_102 V_103 ;
if ( ! ( F_52 ( V_73 ) -> V_106 & V_107 ) )
return;
V_54 = F_45 ( V_8 , V_73 , V_26 ) ;
if ( ! V_54 )
return;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_105 = F_50 ( V_54 ) ;
F_53 ( V_73 , & V_103 ) ;
}
int F_54 ( struct V_69 * V_70 , struct V_8 * V_8 ,
T_1 V_44 , T_1 V_108 )
{
#ifdef F_55
int V_109 , V_18 ;
unsigned long V_46 ;
V_8 -> V_47 = V_110 ;
V_8 -> clock = F_56 ( & V_8 -> V_47 , V_70 ) ;
if ( F_36 ( V_8 -> clock ) ) {
V_109 = F_57 ( V_8 -> clock ) ;
V_8 -> clock = NULL ;
return V_109 ;
}
F_58 ( & V_8 -> V_49 ) ;
V_8 -> V_32 . V_111 = F_13 ;
V_8 -> V_32 . V_112 = F_59 ( 32 ) ;
V_8 -> V_48 = V_44 ;
V_8 -> V_32 . V_44 = V_44 ;
V_8 -> V_32 . V_108 = V_108 ;
F_60 ( & V_8 -> V_27 ) ;
F_60 ( & V_8 -> V_22 ) ;
for ( V_18 = 0 ; V_18 < V_113 ; V_18 ++ )
F_17 ( & V_8 -> V_114 [ V_18 ] . V_23 , & V_8 -> V_22 ) ;
F_34 ( V_70 , V_8 ) ;
F_6 ( V_8 , V_62 , V_63 ) ;
F_6 ( V_8 , V_64 , V_65 ) ;
F_20 ( & V_8 -> V_49 , V_46 ) ;
F_29 ( & V_8 -> V_50 , & V_8 -> V_32 , F_61 ( F_62 () ) ) ;
F_22 ( & V_8 -> V_49 , V_46 ) ;
F_63 ( & V_8 -> V_61 , F_31 ) ;
F_33 ( & V_8 -> V_61 , V_68 ) ;
V_8 -> V_115 = F_64 ( V_8 -> clock ) ;
#endif
return 0 ;
}
void F_65 ( struct V_8 * V_8 )
{
#ifdef F_55
if ( V_8 -> clock ) {
F_66 ( V_8 -> clock ) ;
F_67 ( & V_8 -> V_61 ) ;
}
if ( V_8 -> V_71 )
F_39 ( V_8 ) ;
#endif
}
