int F_1 ( struct V_1 * V_2 )
{
F_2 () ;
return 0 ;
}
void F_3 ( struct V_1 * V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
if ( V_5 ) {
if ( V_5 -> V_6 . V_7 )
F_5 ( & V_5 -> V_6 , V_5 -> V_8 . V_9 ) ;
F_6 ( & V_5 ) ;
}
}
int F_7 ( struct V_10 * V_11 , int V_12 ,
int V_13 , int V_14 ,
bool V_15 , bool V_16 ,
struct V_1 * * V_2 )
{
struct V_4 * V_5 ;
int V_17 ;
* V_2 = NULL ;
if ( V_13 < V_18 ) {
V_13 = V_18 ;
}
V_17 = F_8 ( V_11 , V_12 , V_13 , V_16 , V_14 , NULL , & V_5 ) ;
if ( V_17 ) {
if ( V_17 != - V_19 )
F_9 ( L_1 ,
V_12 , V_14 , V_13 , V_17 ) ;
return V_17 ;
}
* V_2 = & V_5 -> V_6 ;
F_10 ( & V_11 -> V_20 . V_21 ) ;
F_11 ( & V_5 -> V_22 , & V_11 -> V_20 . V_23 ) ;
F_12 ( & V_11 -> V_20 . V_21 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_3 ,
T_1 V_24 , T_1 V_25 )
{
struct V_4 * V_5 ;
T_1 V_26 ;
int V_17 ;
V_5 = F_4 ( V_3 ) ;
V_26 = V_25 ;
if ( ! V_26 ) {
V_26 = V_24 ;
}
if ( ! V_26 ) {
F_14 ( V_27 L_2 ) ;
return 0 ;
}
if ( V_26 == V_28 ) {
V_17 = F_15 ( V_5 , NULL , false ) ;
if ( V_17 ) {
F_14 ( V_29 L_3 ) ;
return V_17 ;
}
}
return 0 ;
}
int F_16 ( struct V_10 * V_11 )
{
F_17 ( & V_11 -> V_20 . V_23 ) ;
return 0 ;
}
void F_18 ( struct V_10 * V_11 )
{
F_19 ( V_11 ) ;
}
int F_20 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
return 0 ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_4 * V_32 = F_4 ( V_2 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_33 * V_34 = V_31 -> V_35 ;
struct V_36 * V_37 = & V_34 -> V_37 ;
struct V_38 * V_39 , * V_40 ;
if ( V_11 -> V_41 < V_42 ) {
return;
}
if ( F_22 ( V_32 , false ) ) {
return;
}
F_23 (bo_va, tmp, &rbo->va, bo_list) {
if ( V_39 -> V_37 == V_37 ) {
F_10 ( & V_37 -> V_21 ) ;
F_24 ( & V_39 -> V_43 ) ;
F_12 ( & V_37 -> V_21 ) ;
F_24 ( & V_39 -> V_44 ) ;
F_25 ( V_39 ) ;
}
}
F_26 ( V_32 ) ;
}
static int F_27 ( struct V_10 * V_11 , int V_17 )
{
if ( V_17 == - V_45 ) {
F_28 ( & V_11 -> V_46 ) ;
V_17 = F_29 ( V_11 ) ;
if ( ! V_17 )
V_17 = - V_47 ;
F_30 ( & V_11 -> V_46 ) ;
}
return V_17 ;
}
int F_31 ( struct V_48 * V_49 , void * V_50 ,
struct V_30 * V_51 )
{
struct V_10 * V_11 = V_49 -> V_52 ;
struct V_53 * args = V_50 ;
struct V_54 * V_55 ;
unsigned V_56 ;
V_55 = & V_11 -> V_57 . V_58 . V_55 [ V_59 ] ;
args -> V_60 = V_11 -> V_61 . V_62 ;
args -> V_63 = ( V_64 ) V_55 -> V_12 << V_65 ;
if ( V_11 -> V_66 )
args -> V_63 -= F_32 ( V_11 -> V_66 ) ;
args -> V_63 -= F_33 ( V_11 ) ;
args -> V_67 = V_11 -> V_61 . V_68 - 4096 - V_69 * 64 * 1024 ;
for( V_56 = 0 ; V_56 < V_70 ; ++ V_56 )
args -> V_67 -= V_11 -> V_71 [ V_56 ] . V_72 ;
return 0 ;
}
int F_34 ( struct V_48 * V_49 , void * V_50 ,
struct V_30 * V_51 )
{
F_9 ( L_4 , V_73 ) ;
return - V_74 ;
}
int F_35 ( struct V_48 * V_49 , void * V_50 ,
struct V_30 * V_51 )
{
F_9 ( L_4 , V_73 ) ;
return - V_74 ;
}
int F_36 ( struct V_48 * V_49 , void * V_50 ,
struct V_30 * V_51 )
{
struct V_10 * V_11 = V_49 -> V_52 ;
struct V_75 * args = V_50 ;
struct V_1 * V_3 ;
T_1 V_76 ;
int V_17 ;
args -> V_12 = F_37 ( args -> V_12 , V_18 ) ;
V_17 = F_7 ( V_11 , args -> V_12 , args -> V_13 ,
args -> V_14 , false ,
false , & V_3 ) ;
if ( V_17 ) {
V_17 = F_27 ( V_11 , V_17 ) ;
return V_17 ;
}
V_17 = F_38 ( V_51 , V_3 , & V_76 ) ;
F_39 ( V_3 ) ;
if ( V_17 ) {
V_17 = F_27 ( V_11 , V_17 ) ;
return V_17 ;
}
args -> V_76 = V_76 ;
return 0 ;
}
int F_40 ( struct V_48 * V_49 , void * V_50 ,
struct V_30 * V_51 )
{
struct V_77 * args = V_50 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_17 ;
V_3 = F_41 ( V_49 , V_51 , args -> V_76 ) ;
if ( V_3 == NULL ) {
return - V_78 ;
}
V_5 = F_4 ( V_3 ) ;
V_17 = F_13 ( V_3 , args -> V_79 , args -> V_80 ) ;
F_39 ( V_3 ) ;
V_17 = F_27 ( V_5 -> V_11 , V_17 ) ;
return V_17 ;
}
int F_42 ( struct V_30 * V_51 ,
struct V_48 * V_49 ,
T_1 V_76 , T_2 * V_81 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
V_3 = F_41 ( V_49 , V_51 , V_76 ) ;
if ( V_3 == NULL ) {
return - V_78 ;
}
V_5 = F_4 ( V_3 ) ;
* V_81 = F_43 ( V_5 ) ;
F_39 ( V_3 ) ;
return 0 ;
}
int F_44 ( struct V_48 * V_49 , void * V_50 ,
struct V_30 * V_51 )
{
struct V_82 * args = V_50 ;
return F_42 ( V_51 , V_49 , args -> V_76 , & args -> V_83 ) ;
}
int F_45 ( struct V_48 * V_49 , void * V_50 ,
struct V_30 * V_51 )
{
struct V_10 * V_11 = V_49 -> V_52 ;
struct V_84 * args = V_50 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_17 ;
T_1 V_85 = 0 ;
V_3 = F_41 ( V_49 , V_51 , args -> V_76 ) ;
if ( V_3 == NULL ) {
return - V_78 ;
}
V_5 = F_4 ( V_3 ) ;
V_17 = F_15 ( V_5 , & V_85 , true ) ;
switch ( V_85 ) {
case V_59 :
args -> V_26 = V_86 ;
break;
case V_87 :
args -> V_26 = V_88 ;
break;
case V_89 :
args -> V_26 = V_28 ;
default:
break;
}
F_39 ( V_3 ) ;
V_17 = F_27 ( V_11 , V_17 ) ;
return V_17 ;
}
int F_46 ( struct V_48 * V_49 , void * V_50 ,
struct V_30 * V_51 )
{
struct V_10 * V_11 = V_49 -> V_52 ;
struct V_90 * args = V_50 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_17 ;
V_3 = F_41 ( V_49 , V_51 , args -> V_76 ) ;
if ( V_3 == NULL ) {
return - V_78 ;
}
V_5 = F_4 ( V_3 ) ;
V_17 = F_15 ( V_5 , NULL , false ) ;
if ( V_11 -> V_91 -> V_92 )
V_5 -> V_11 -> V_91 -> V_92 ( V_11 , V_5 ) ;
F_39 ( V_3 ) ;
V_17 = F_27 ( V_11 , V_17 ) ;
return V_17 ;
}
int F_47 ( struct V_48 * V_49 , void * V_50 ,
struct V_30 * V_51 )
{
struct V_93 * args = V_50 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_17 = 0 ;
F_48 ( L_5 , args -> V_76 ) ;
V_3 = F_41 ( V_49 , V_51 , args -> V_76 ) ;
if ( V_3 == NULL )
return - V_78 ;
V_5 = F_4 ( V_3 ) ;
V_17 = F_49 ( V_5 , args -> V_94 , args -> V_95 ) ;
F_39 ( V_3 ) ;
return V_17 ;
}
int F_50 ( struct V_48 * V_49 , void * V_50 ,
struct V_30 * V_51 )
{
struct V_96 * args = V_50 ;
struct V_1 * V_3 ;
struct V_4 * V_32 ;
int V_17 = 0 ;
F_48 ( L_6 ) ;
V_3 = F_41 ( V_49 , V_51 , args -> V_76 ) ;
if ( V_3 == NULL )
return - V_78 ;
V_32 = F_4 ( V_3 ) ;
V_17 = F_22 ( V_32 , false ) ;
if ( F_51 ( V_17 != 0 ) )
goto V_97;
F_52 ( V_32 , & args -> V_94 , & args -> V_95 ) ;
F_26 ( V_32 ) ;
V_97:
F_39 ( V_3 ) ;
return V_17 ;
}
int F_53 ( struct V_48 * V_49 , void * V_50 ,
struct V_30 * V_51 )
{
struct V_98 * args = V_50 ;
struct V_1 * V_3 ;
struct V_10 * V_11 = V_49 -> V_52 ;
struct V_33 * V_34 = V_51 -> V_35 ;
struct V_4 * V_32 ;
struct V_38 * V_39 ;
T_3 V_99 ;
int V_17 = 0 ;
if ( ! V_11 -> V_100 . V_101 ) {
args -> V_102 = V_103 ;
return - V_104 ;
}
if ( args -> V_105 ) {
args -> V_102 = V_103 ;
return - V_106 ;
}
if ( args -> V_107 < V_108 ) {
F_54 ( & V_49 -> V_109 -> V_49 ,
L_7 ,
( unsigned long ) args -> V_107 ,
V_108 ) ;
args -> V_102 = V_103 ;
return - V_106 ;
}
V_99 = V_110 | V_111 ;
if ( ( args -> V_112 & V_99 ) ) {
F_54 ( & V_49 -> V_109 -> V_49 , L_8 ,
args -> V_112 , V_99 ) ;
args -> V_102 = V_103 ;
return - V_106 ;
}
if ( ! ( args -> V_112 & V_113 ) ) {
F_54 ( & V_49 -> V_109 -> V_49 , L_9 ) ;
args -> V_102 = V_103 ;
return - V_106 ;
}
switch ( args -> V_102 ) {
case V_114 :
case V_115 :
break;
default:
F_54 ( & V_49 -> V_109 -> V_49 , L_10 ,
args -> V_102 ) ;
args -> V_102 = V_103 ;
return - V_106 ;
}
V_3 = F_41 ( V_49 , V_51 , args -> V_76 ) ;
if ( V_3 == NULL ) {
args -> V_102 = V_103 ;
return - V_78 ;
}
V_32 = F_4 ( V_3 ) ;
V_17 = F_22 ( V_32 , false ) ;
if ( V_17 ) {
args -> V_102 = V_103 ;
F_39 ( V_3 ) ;
return V_17 ;
}
switch ( args -> V_102 ) {
case V_114 :
V_39 = V_38 ( V_32 , & V_34 -> V_37 ) ;
if ( V_39 ) {
args -> V_102 = V_116 ;
args -> V_107 = V_39 -> V_117 ;
goto V_97;
}
V_17 = F_55 ( V_11 , & V_34 -> V_37 , V_32 ,
args -> V_107 , args -> V_112 ) ;
break;
case V_115 :
V_17 = F_56 ( V_11 , & V_34 -> V_37 , V_32 ) ;
break;
default:
break;
}
args -> V_102 = V_118 ;
if ( V_17 ) {
args -> V_102 = V_103 ;
}
V_97:
F_26 ( V_32 ) ;
F_39 ( V_3 ) ;
return V_17 ;
}
int F_57 ( struct V_30 * V_31 ,
struct V_48 * V_49 ,
struct V_119 * args )
{
struct V_10 * V_11 = V_49 -> V_52 ;
struct V_1 * V_3 ;
T_1 V_76 ;
int V_17 ;
args -> V_95 = F_58 ( V_11 , args -> V_120 , args -> V_121 , 0 ) * ( ( args -> V_121 + 1 ) / 8 ) ;
args -> V_12 = args -> V_95 * args -> V_122 ;
args -> V_12 = F_59 ( args -> V_12 , V_18 ) ;
V_17 = F_7 ( V_11 , args -> V_12 , 0 ,
V_86 ,
false , V_123 ,
& V_3 ) ;
if ( V_17 )
return - V_124 ;
V_17 = F_38 ( V_31 , V_3 , & V_76 ) ;
F_39 ( V_3 ) ;
if ( V_17 ) {
return V_17 ;
}
args -> V_76 = V_76 ;
return 0 ;
}
int F_60 ( struct V_30 * V_31 ,
struct V_48 * V_49 ,
T_1 V_76 )
{
return F_61 ( V_31 , V_76 ) ;
}
