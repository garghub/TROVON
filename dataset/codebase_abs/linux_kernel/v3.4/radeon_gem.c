int F_1 ( struct V_1 * V_2 )
{
F_2 () ;
return 0 ;
}
void F_3 ( struct V_1 * V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
if ( V_5 ) {
F_5 ( & V_5 ) ;
}
}
int F_6 ( struct V_6 * V_7 , int V_8 ,
int V_9 , int V_10 ,
bool V_11 , bool V_12 ,
struct V_1 * * V_2 )
{
struct V_4 * V_5 ;
int V_13 ;
* V_2 = NULL ;
if ( V_9 < V_14 ) {
V_9 = V_14 ;
}
V_13 = F_7 ( V_7 , V_8 , V_9 , V_12 , V_10 , & V_5 ) ;
if ( V_13 ) {
if ( V_13 != - V_15 )
F_8 ( L_1 ,
V_8 , V_10 , V_9 , V_13 ) ;
return V_13 ;
}
* V_2 = & V_5 -> V_16 ;
F_9 ( & V_7 -> V_17 . V_18 ) ;
F_10 ( & V_5 -> V_19 , & V_7 -> V_17 . V_20 ) ;
F_11 ( & V_7 -> V_17 . V_18 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_3 ,
T_1 V_21 , T_1 V_22 )
{
struct V_4 * V_5 ;
T_1 V_23 ;
int V_13 ;
V_5 = F_4 ( V_3 ) ;
V_23 = V_22 ;
if ( ! V_23 ) {
V_23 = V_21 ;
}
if ( ! V_23 ) {
F_13 ( V_24 L_2 ) ;
return 0 ;
}
if ( V_23 == V_25 ) {
V_13 = F_14 ( V_5 , NULL , false ) ;
if ( V_13 ) {
F_13 ( V_26 L_3 ) ;
return V_13 ;
}
}
return 0 ;
}
int F_15 ( struct V_6 * V_7 )
{
F_16 ( & V_7 -> V_17 . V_20 ) ;
return 0 ;
}
void F_17 ( struct V_6 * V_7 )
{
F_18 ( V_7 ) ;
}
int F_19 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
return 0 ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_4 * V_29 = F_4 ( V_2 ) ;
struct V_6 * V_7 = V_29 -> V_7 ;
struct V_30 * V_31 = V_28 -> V_32 ;
struct V_33 * V_34 = & V_31 -> V_34 ;
struct V_35 * V_36 , * V_37 ;
if ( V_7 -> V_38 < V_39 ) {
return;
}
if ( F_21 ( V_29 , false ) ) {
return;
}
F_22 (bo_va, tmp, &rbo->va, bo_list) {
if ( V_36 -> V_34 == V_34 ) {
F_9 ( & V_34 -> V_18 ) ;
F_23 ( & V_36 -> V_40 ) ;
F_11 ( & V_34 -> V_18 ) ;
F_23 ( & V_36 -> V_41 ) ;
F_24 ( V_36 ) ;
}
}
F_25 ( V_29 ) ;
}
int F_26 ( struct V_42 * V_43 , void * V_44 ,
struct V_27 * V_45 )
{
struct V_6 * V_7 = V_43 -> V_46 ;
struct V_47 * args = V_44 ;
struct V_48 * V_49 ;
unsigned V_50 ;
V_49 = & V_7 -> V_51 . V_52 . V_49 [ V_53 ] ;
args -> V_54 = V_7 -> V_55 . V_56 ;
args -> V_57 = ( V_58 ) V_49 -> V_8 << V_59 ;
if ( V_7 -> V_60 )
args -> V_57 -= F_27 ( V_7 -> V_60 ) ;
args -> V_57 -= F_28 ( V_7 ) ;
args -> V_61 = V_7 -> V_55 . V_62 - 4096 - V_63 * 64 * 1024 ;
for( V_50 = 0 ; V_50 < V_64 ; ++ V_50 )
args -> V_61 -= V_7 -> V_65 [ V_50 ] . V_66 ;
return 0 ;
}
int F_29 ( struct V_42 * V_43 , void * V_44 ,
struct V_27 * V_45 )
{
F_8 ( L_4 , V_67 ) ;
return - V_68 ;
}
int F_30 ( struct V_42 * V_43 , void * V_44 ,
struct V_27 * V_45 )
{
F_8 ( L_4 , V_67 ) ;
return - V_68 ;
}
int F_31 ( struct V_42 * V_43 , void * V_44 ,
struct V_27 * V_45 )
{
struct V_6 * V_7 = V_43 -> V_46 ;
struct V_69 * args = V_44 ;
struct V_1 * V_3 ;
T_1 V_70 ;
int V_13 ;
args -> V_8 = F_32 ( args -> V_8 , V_14 ) ;
V_13 = F_6 ( V_7 , args -> V_8 , args -> V_9 ,
args -> V_10 , false ,
false , & V_3 ) ;
if ( V_13 ) {
return V_13 ;
}
V_13 = F_33 ( V_45 , V_3 , & V_70 ) ;
F_34 ( V_3 ) ;
if ( V_13 ) {
return V_13 ;
}
args -> V_70 = V_70 ;
return 0 ;
}
int F_35 ( struct V_42 * V_43 , void * V_44 ,
struct V_27 * V_45 )
{
struct V_71 * args = V_44 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 ;
V_3 = F_36 ( V_43 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL ) {
return - V_72 ;
}
V_5 = F_4 ( V_3 ) ;
V_13 = F_12 ( V_3 , args -> V_73 , args -> V_74 ) ;
F_34 ( V_3 ) ;
return V_13 ;
}
int F_37 ( struct V_27 * V_45 ,
struct V_42 * V_43 ,
T_1 V_70 , T_2 * V_75 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
V_3 = F_36 ( V_43 , V_45 , V_70 ) ;
if ( V_3 == NULL ) {
return - V_72 ;
}
V_5 = F_4 ( V_3 ) ;
* V_75 = F_38 ( V_5 ) ;
F_34 ( V_3 ) ;
return 0 ;
}
int F_39 ( struct V_42 * V_43 , void * V_44 ,
struct V_27 * V_45 )
{
struct V_76 * args = V_44 ;
return F_37 ( V_45 , V_43 , args -> V_70 , & args -> V_77 ) ;
}
int F_40 ( struct V_42 * V_43 , void * V_44 ,
struct V_27 * V_45 )
{
struct V_78 * args = V_44 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 ;
T_1 V_79 = 0 ;
V_3 = F_36 ( V_43 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL ) {
return - V_72 ;
}
V_5 = F_4 ( V_3 ) ;
V_13 = F_14 ( V_5 , & V_79 , true ) ;
switch ( V_79 ) {
case V_53 :
args -> V_23 = V_80 ;
break;
case V_81 :
args -> V_23 = V_82 ;
break;
case V_83 :
args -> V_23 = V_25 ;
default:
break;
}
F_34 ( V_3 ) ;
return V_13 ;
}
int F_41 ( struct V_42 * V_43 , void * V_44 ,
struct V_27 * V_45 )
{
struct V_84 * args = V_44 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 ;
V_3 = F_36 ( V_43 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL ) {
return - V_72 ;
}
V_5 = F_4 ( V_3 ) ;
V_13 = F_14 ( V_5 , NULL , false ) ;
if ( V_5 -> V_7 -> V_85 -> V_86 )
V_5 -> V_7 -> V_85 -> V_86 ( V_5 -> V_7 , V_5 ) ;
F_34 ( V_3 ) ;
return V_13 ;
}
int F_42 ( struct V_42 * V_43 , void * V_44 ,
struct V_27 * V_45 )
{
struct V_87 * args = V_44 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 = 0 ;
F_43 ( L_5 , args -> V_70 ) ;
V_3 = F_36 ( V_43 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL )
return - V_72 ;
V_5 = F_4 ( V_3 ) ;
V_13 = F_44 ( V_5 , args -> V_88 , args -> V_89 ) ;
F_34 ( V_3 ) ;
return V_13 ;
}
int F_45 ( struct V_42 * V_43 , void * V_44 ,
struct V_27 * V_45 )
{
struct V_90 * args = V_44 ;
struct V_1 * V_3 ;
struct V_4 * V_29 ;
int V_13 = 0 ;
F_43 ( L_6 ) ;
V_3 = F_36 ( V_43 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL )
return - V_72 ;
V_29 = F_4 ( V_3 ) ;
V_13 = F_21 ( V_29 , false ) ;
if ( F_46 ( V_13 != 0 ) )
goto V_91;
F_47 ( V_29 , & args -> V_88 , & args -> V_89 ) ;
F_25 ( V_29 ) ;
V_91:
F_34 ( V_3 ) ;
return V_13 ;
}
int F_48 ( struct V_42 * V_43 , void * V_44 ,
struct V_27 * V_45 )
{
struct V_92 * args = V_44 ;
struct V_1 * V_3 ;
struct V_6 * V_7 = V_43 -> V_46 ;
struct V_30 * V_31 = V_45 -> V_32 ;
struct V_4 * V_29 ;
struct V_35 * V_36 ;
T_3 V_93 ;
int V_13 = 0 ;
if ( ! V_7 -> V_94 . V_95 ) {
args -> V_96 = V_97 ;
return - V_98 ;
}
if ( args -> V_99 ) {
args -> V_96 = V_97 ;
return - V_100 ;
}
if ( args -> V_101 < V_102 ) {
F_49 ( & V_43 -> V_103 -> V_43 ,
L_7 ,
( unsigned long ) args -> V_101 ,
V_102 ) ;
args -> V_96 = V_97 ;
return - V_100 ;
}
V_93 = V_104 | V_105 ;
if ( ( args -> V_106 & V_93 ) ) {
F_49 ( & V_43 -> V_103 -> V_43 , L_8 ,
args -> V_106 , V_93 ) ;
args -> V_96 = V_97 ;
return - V_100 ;
}
if ( ! ( args -> V_106 & V_107 ) ) {
F_49 ( & V_43 -> V_103 -> V_43 , L_9 ) ;
args -> V_96 = V_97 ;
return - V_100 ;
}
switch ( args -> V_96 ) {
case V_108 :
case V_109 :
break;
default:
F_49 ( & V_43 -> V_103 -> V_43 , L_10 ,
args -> V_96 ) ;
args -> V_96 = V_97 ;
return - V_100 ;
}
V_3 = F_36 ( V_43 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL ) {
args -> V_96 = V_97 ;
return - V_72 ;
}
V_29 = F_4 ( V_3 ) ;
V_13 = F_21 ( V_29 , false ) ;
if ( V_13 ) {
args -> V_96 = V_97 ;
F_34 ( V_3 ) ;
return V_13 ;
}
switch ( args -> V_96 ) {
case V_108 :
V_36 = V_35 ( V_29 , & V_31 -> V_34 ) ;
if ( V_36 ) {
args -> V_96 = V_110 ;
args -> V_101 = V_36 -> V_111 ;
goto V_91;
}
V_13 = F_50 ( V_7 , & V_31 -> V_34 , V_29 ,
args -> V_101 , args -> V_106 ) ;
break;
case V_109 :
V_13 = F_51 ( V_7 , & V_31 -> V_34 , V_29 ) ;
break;
default:
break;
}
args -> V_96 = V_112 ;
if ( V_13 ) {
args -> V_96 = V_97 ;
}
V_91:
F_25 ( V_29 ) ;
F_34 ( V_3 ) ;
return V_13 ;
}
int F_52 ( struct V_27 * V_28 ,
struct V_42 * V_43 ,
struct V_113 * args )
{
struct V_6 * V_7 = V_43 -> V_46 ;
struct V_1 * V_3 ;
T_1 V_70 ;
int V_13 ;
args -> V_89 = F_53 ( V_7 , args -> V_114 , args -> V_115 , 0 ) * ( ( args -> V_115 + 1 ) / 8 ) ;
args -> V_8 = args -> V_89 * args -> V_116 ;
args -> V_8 = F_54 ( args -> V_8 , V_14 ) ;
V_13 = F_6 ( V_7 , args -> V_8 , 0 ,
V_80 ,
false , V_117 ,
& V_3 ) ;
if ( V_13 )
return - V_118 ;
V_13 = F_33 ( V_28 , V_3 , & V_70 ) ;
F_34 ( V_3 ) ;
if ( V_13 ) {
return V_13 ;
}
args -> V_70 = V_70 ;
return 0 ;
}
int F_55 ( struct V_27 * V_28 ,
struct V_42 * V_43 ,
T_1 V_70 )
{
return F_56 ( V_28 , V_70 ) ;
}
