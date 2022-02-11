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
int F_12 ( struct V_1 * V_2 , T_1 V_21 ,
T_2 * V_22 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
int V_13 ;
V_13 = F_13 ( V_5 , false ) ;
if ( F_14 ( V_13 != 0 ) )
return V_13 ;
V_13 = F_15 ( V_5 , V_21 , V_22 ) ;
F_16 ( V_5 ) ;
return V_13 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
int V_13 ;
V_13 = F_13 ( V_5 , false ) ;
if ( F_18 ( V_13 == 0 ) ) {
F_19 ( V_5 ) ;
F_16 ( V_5 ) ;
}
}
int F_20 ( struct V_1 * V_3 ,
T_1 V_23 , T_1 V_24 )
{
struct V_4 * V_5 ;
T_1 V_25 ;
int V_13 ;
V_5 = F_4 ( V_3 ) ;
V_25 = V_24 ;
if ( ! V_25 ) {
V_25 = V_23 ;
}
if ( ! V_25 ) {
F_21 ( V_26 L_2 ) ;
return 0 ;
}
if ( V_25 == V_27 ) {
V_13 = F_22 ( V_5 , NULL , false ) ;
if ( V_13 ) {
F_21 ( V_28 L_3 ) ;
return V_13 ;
}
}
return 0 ;
}
int F_23 ( struct V_6 * V_7 )
{
F_24 ( & V_7 -> V_17 . V_20 ) ;
return 0 ;
}
void F_25 ( struct V_6 * V_7 )
{
F_26 ( V_7 ) ;
}
int F_27 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
return 0 ;
}
void F_28 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_4 * V_31 = F_4 ( V_2 ) ;
struct V_6 * V_7 = V_31 -> V_7 ;
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_35 * V_36 = & V_33 -> V_36 ;
struct V_37 * V_38 , * V_39 ;
if ( V_7 -> V_40 < V_41 ) {
return;
}
if ( F_13 ( V_31 , false ) ) {
return;
}
F_29 (bo_va, tmp, &rbo->va, bo_list) {
if ( V_38 -> V_36 == V_36 ) {
F_9 ( & V_36 -> V_18 ) ;
F_30 ( & V_38 -> V_42 ) ;
F_11 ( & V_36 -> V_18 ) ;
F_30 ( & V_38 -> V_43 ) ;
F_31 ( V_38 ) ;
}
}
F_16 ( V_31 ) ;
}
int F_32 ( struct V_44 * V_45 , void * V_46 ,
struct V_29 * V_47 )
{
struct V_6 * V_7 = V_45 -> V_48 ;
struct V_49 * args = V_46 ;
struct V_50 * V_51 ;
unsigned V_52 ;
V_51 = & V_7 -> V_53 . V_54 . V_51 [ V_55 ] ;
args -> V_56 = V_7 -> V_57 . V_58 ;
args -> V_59 = ( V_60 ) V_51 -> V_8 << V_61 ;
if ( V_7 -> V_62 )
args -> V_59 -= F_33 ( V_7 -> V_62 ) ;
args -> V_59 -= F_34 ( V_7 ) ;
args -> V_63 = V_7 -> V_57 . V_64 - 4096 - V_65 * 64 * 1024 ;
for( V_52 = 0 ; V_52 < V_66 ; ++ V_52 )
args -> V_63 -= V_7 -> V_67 [ V_52 ] . V_68 ;
return 0 ;
}
int F_35 ( struct V_44 * V_45 , void * V_46 ,
struct V_29 * V_47 )
{
F_8 ( L_4 , V_69 ) ;
return - V_70 ;
}
int F_36 ( struct V_44 * V_45 , void * V_46 ,
struct V_29 * V_47 )
{
F_8 ( L_4 , V_69 ) ;
return - V_70 ;
}
int F_37 ( struct V_44 * V_45 , void * V_46 ,
struct V_29 * V_47 )
{
struct V_6 * V_7 = V_45 -> V_48 ;
struct V_71 * args = V_46 ;
struct V_1 * V_3 ;
T_1 V_72 ;
int V_13 ;
args -> V_8 = F_38 ( args -> V_8 , V_14 ) ;
V_13 = F_6 ( V_7 , args -> V_8 , args -> V_9 ,
args -> V_10 , false ,
false , & V_3 ) ;
if ( V_13 ) {
return V_13 ;
}
V_13 = F_39 ( V_47 , V_3 , & V_72 ) ;
F_40 ( V_3 ) ;
if ( V_13 ) {
return V_13 ;
}
args -> V_72 = V_72 ;
return 0 ;
}
int F_41 ( struct V_44 * V_45 , void * V_46 ,
struct V_29 * V_47 )
{
struct V_73 * args = V_46 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 ;
V_3 = F_42 ( V_45 , V_47 , args -> V_72 ) ;
if ( V_3 == NULL ) {
return - V_74 ;
}
V_5 = F_4 ( V_3 ) ;
V_13 = F_20 ( V_3 , args -> V_75 , args -> V_76 ) ;
F_40 ( V_3 ) ;
return V_13 ;
}
int F_43 ( struct V_29 * V_47 ,
struct V_44 * V_45 ,
T_1 V_72 , T_2 * V_77 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
V_3 = F_42 ( V_45 , V_47 , V_72 ) ;
if ( V_3 == NULL ) {
return - V_74 ;
}
V_5 = F_4 ( V_3 ) ;
* V_77 = F_44 ( V_5 ) ;
F_40 ( V_3 ) ;
return 0 ;
}
int F_45 ( struct V_44 * V_45 , void * V_46 ,
struct V_29 * V_47 )
{
struct V_78 * args = V_46 ;
return F_43 ( V_47 , V_45 , args -> V_72 , & args -> V_79 ) ;
}
int F_46 ( struct V_44 * V_45 , void * V_46 ,
struct V_29 * V_47 )
{
struct V_80 * args = V_46 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 ;
T_1 V_81 = 0 ;
V_3 = F_42 ( V_45 , V_47 , args -> V_72 ) ;
if ( V_3 == NULL ) {
return - V_74 ;
}
V_5 = F_4 ( V_3 ) ;
V_13 = F_22 ( V_5 , & V_81 , true ) ;
switch ( V_81 ) {
case V_55 :
args -> V_25 = V_82 ;
break;
case V_83 :
args -> V_25 = V_84 ;
break;
case V_85 :
args -> V_25 = V_27 ;
default:
break;
}
F_40 ( V_3 ) ;
return V_13 ;
}
int F_47 ( struct V_44 * V_45 , void * V_46 ,
struct V_29 * V_47 )
{
struct V_86 * args = V_46 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 ;
V_3 = F_42 ( V_45 , V_47 , args -> V_72 ) ;
if ( V_3 == NULL ) {
return - V_74 ;
}
V_5 = F_4 ( V_3 ) ;
V_13 = F_22 ( V_5 , NULL , false ) ;
if ( V_5 -> V_7 -> V_87 -> V_88 )
V_5 -> V_7 -> V_87 -> V_88 ( V_5 -> V_7 , V_5 ) ;
F_40 ( V_3 ) ;
return V_13 ;
}
int F_48 ( struct V_44 * V_45 , void * V_46 ,
struct V_29 * V_47 )
{
struct V_89 * args = V_46 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_13 = 0 ;
F_49 ( L_5 , args -> V_72 ) ;
V_3 = F_42 ( V_45 , V_47 , args -> V_72 ) ;
if ( V_3 == NULL )
return - V_74 ;
V_5 = F_4 ( V_3 ) ;
V_13 = F_50 ( V_5 , args -> V_90 , args -> V_91 ) ;
F_40 ( V_3 ) ;
return V_13 ;
}
int F_51 ( struct V_44 * V_45 , void * V_46 ,
struct V_29 * V_47 )
{
struct V_92 * args = V_46 ;
struct V_1 * V_3 ;
struct V_4 * V_31 ;
int V_13 = 0 ;
F_49 ( L_6 ) ;
V_3 = F_42 ( V_45 , V_47 , args -> V_72 ) ;
if ( V_3 == NULL )
return - V_74 ;
V_31 = F_4 ( V_3 ) ;
V_13 = F_13 ( V_31 , false ) ;
if ( F_14 ( V_13 != 0 ) )
goto V_93;
F_52 ( V_31 , & args -> V_90 , & args -> V_91 ) ;
F_16 ( V_31 ) ;
V_93:
F_40 ( V_3 ) ;
return V_13 ;
}
int F_53 ( struct V_44 * V_45 , void * V_46 ,
struct V_29 * V_47 )
{
struct V_94 * args = V_46 ;
struct V_1 * V_3 ;
struct V_6 * V_7 = V_45 -> V_48 ;
struct V_32 * V_33 = V_47 -> V_34 ;
struct V_4 * V_31 ;
struct V_37 * V_38 ;
T_3 V_95 ;
int V_13 = 0 ;
if ( ! V_7 -> V_96 . V_97 ) {
args -> V_98 = V_99 ;
return - V_100 ;
}
if ( args -> V_101 ) {
args -> V_98 = V_99 ;
return - V_102 ;
}
if ( args -> V_103 < V_104 ) {
F_54 ( & V_45 -> V_105 -> V_45 ,
L_7 ,
( unsigned long ) args -> V_103 ,
V_104 ) ;
args -> V_98 = V_99 ;
return - V_102 ;
}
V_95 = V_106 | V_107 ;
if ( ( args -> V_108 & V_95 ) ) {
F_54 ( & V_45 -> V_105 -> V_45 , L_8 ,
args -> V_108 , V_95 ) ;
args -> V_98 = V_99 ;
return - V_102 ;
}
if ( ! ( args -> V_108 & V_109 ) ) {
F_54 ( & V_45 -> V_105 -> V_45 , L_9 ) ;
args -> V_98 = V_99 ;
return - V_102 ;
}
switch ( args -> V_98 ) {
case V_110 :
case V_111 :
break;
default:
F_54 ( & V_45 -> V_105 -> V_45 , L_10 ,
args -> V_98 ) ;
args -> V_98 = V_99 ;
return - V_102 ;
}
V_3 = F_42 ( V_45 , V_47 , args -> V_72 ) ;
if ( V_3 == NULL ) {
args -> V_98 = V_99 ;
return - V_74 ;
}
V_31 = F_4 ( V_3 ) ;
V_13 = F_13 ( V_31 , false ) ;
if ( V_13 ) {
args -> V_98 = V_99 ;
F_40 ( V_3 ) ;
return V_13 ;
}
switch ( args -> V_98 ) {
case V_110 :
V_38 = V_37 ( V_31 , & V_33 -> V_36 ) ;
if ( V_38 ) {
args -> V_98 = V_112 ;
args -> V_103 = V_38 -> V_113 ;
goto V_93;
}
V_13 = F_55 ( V_7 , & V_33 -> V_36 , V_31 ,
args -> V_103 , args -> V_108 ) ;
break;
case V_111 :
V_13 = F_56 ( V_7 , & V_33 -> V_36 , V_31 ) ;
break;
default:
break;
}
args -> V_98 = V_114 ;
if ( V_13 ) {
args -> V_98 = V_99 ;
}
V_93:
F_16 ( V_31 ) ;
F_40 ( V_3 ) ;
return V_13 ;
}
int F_57 ( struct V_29 * V_30 ,
struct V_44 * V_45 ,
struct V_115 * args )
{
struct V_6 * V_7 = V_45 -> V_48 ;
struct V_1 * V_3 ;
T_1 V_72 ;
int V_13 ;
args -> V_91 = F_58 ( V_7 , args -> V_116 , args -> V_117 , 0 ) * ( ( args -> V_117 + 1 ) / 8 ) ;
args -> V_8 = args -> V_91 * args -> V_118 ;
args -> V_8 = F_59 ( args -> V_8 , V_14 ) ;
V_13 = F_6 ( V_7 , args -> V_8 , 0 ,
V_82 ,
false , V_119 ,
& V_3 ) ;
if ( V_13 )
return - V_120 ;
V_13 = F_39 ( V_30 , V_3 , & V_72 ) ;
F_40 ( V_3 ) ;
if ( V_13 ) {
return V_13 ;
}
args -> V_72 = V_72 ;
return 0 ;
}
int F_60 ( struct V_29 * V_30 ,
struct V_44 * V_45 ,
T_1 V_72 )
{
return F_61 ( V_30 , V_72 ) ;
}
