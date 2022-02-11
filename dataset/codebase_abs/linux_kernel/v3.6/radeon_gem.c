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
if ( V_11 -> V_38 < V_39 ) {
return;
}
if ( F_22 ( V_32 , false ) ) {
F_23 ( V_11 -> V_40 , L_4 ) ;
return;
}
F_24 ( V_11 , V_37 , V_32 ) ;
F_25 ( V_32 ) ;
}
static int F_26 ( struct V_10 * V_11 , int V_17 )
{
if ( V_17 == - V_41 ) {
V_17 = F_27 ( V_11 ) ;
if ( ! V_17 )
V_17 = - V_42 ;
}
return V_17 ;
}
int F_28 ( struct V_43 * V_40 , void * V_44 ,
struct V_30 * V_45 )
{
struct V_10 * V_11 = V_40 -> V_46 ;
struct V_47 * args = V_44 ;
struct V_48 * V_49 ;
unsigned V_50 ;
V_49 = & V_11 -> V_51 . V_52 . V_49 [ V_53 ] ;
args -> V_54 = V_11 -> V_55 . V_56 ;
args -> V_57 = ( V_58 ) V_49 -> V_12 << V_59 ;
if ( V_11 -> V_60 )
args -> V_57 -= F_29 ( V_11 -> V_60 ) ;
args -> V_57 -= F_30 ( V_11 ) ;
args -> V_61 = V_11 -> V_55 . V_62 - 4096 - V_63 * 64 * 1024 ;
for( V_50 = 0 ; V_50 < V_64 ; ++ V_50 )
args -> V_61 -= V_11 -> V_65 [ V_50 ] . V_66 ;
return 0 ;
}
int F_31 ( struct V_43 * V_40 , void * V_44 ,
struct V_30 * V_45 )
{
F_9 ( L_5 , V_67 ) ;
return - V_68 ;
}
int F_32 ( struct V_43 * V_40 , void * V_44 ,
struct V_30 * V_45 )
{
F_9 ( L_5 , V_67 ) ;
return - V_68 ;
}
int F_33 ( struct V_43 * V_40 , void * V_44 ,
struct V_30 * V_45 )
{
struct V_10 * V_11 = V_40 -> V_46 ;
struct V_69 * args = V_44 ;
struct V_1 * V_3 ;
T_1 V_70 ;
int V_17 ;
F_34 ( & V_11 -> V_71 ) ;
args -> V_12 = F_35 ( args -> V_12 , V_18 ) ;
V_17 = F_7 ( V_11 , args -> V_12 , args -> V_13 ,
args -> V_14 , false ,
false , & V_3 ) ;
if ( V_17 ) {
F_36 ( & V_11 -> V_71 ) ;
V_17 = F_26 ( V_11 , V_17 ) ;
return V_17 ;
}
V_17 = F_37 ( V_45 , V_3 , & V_70 ) ;
F_38 ( V_3 ) ;
if ( V_17 ) {
F_36 ( & V_11 -> V_71 ) ;
V_17 = F_26 ( V_11 , V_17 ) ;
return V_17 ;
}
args -> V_70 = V_70 ;
F_36 ( & V_11 -> V_71 ) ;
return 0 ;
}
int F_39 ( struct V_43 * V_40 , void * V_44 ,
struct V_30 * V_45 )
{
struct V_10 * V_11 = V_40 -> V_46 ;
struct V_72 * args = V_44 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_17 ;
F_34 ( & V_11 -> V_71 ) ;
V_3 = F_40 ( V_40 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL ) {
F_36 ( & V_11 -> V_71 ) ;
return - V_73 ;
}
V_5 = F_4 ( V_3 ) ;
V_17 = F_13 ( V_3 , args -> V_74 , args -> V_75 ) ;
F_38 ( V_3 ) ;
F_36 ( & V_11 -> V_71 ) ;
V_17 = F_26 ( V_5 -> V_11 , V_17 ) ;
return V_17 ;
}
int F_41 ( struct V_30 * V_45 ,
struct V_43 * V_40 ,
T_1 V_70 , T_2 * V_76 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
V_3 = F_40 ( V_40 , V_45 , V_70 ) ;
if ( V_3 == NULL ) {
return - V_73 ;
}
V_5 = F_4 ( V_3 ) ;
* V_76 = F_42 ( V_5 ) ;
F_38 ( V_3 ) ;
return 0 ;
}
int F_43 ( struct V_43 * V_40 , void * V_44 ,
struct V_30 * V_45 )
{
struct V_77 * args = V_44 ;
return F_41 ( V_45 , V_40 , args -> V_70 , & args -> V_78 ) ;
}
int F_44 ( struct V_43 * V_40 , void * V_44 ,
struct V_30 * V_45 )
{
struct V_10 * V_11 = V_40 -> V_46 ;
struct V_79 * args = V_44 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_17 ;
T_1 V_80 = 0 ;
V_3 = F_40 ( V_40 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL ) {
return - V_73 ;
}
V_5 = F_4 ( V_3 ) ;
V_17 = F_15 ( V_5 , & V_80 , true ) ;
switch ( V_80 ) {
case V_53 :
args -> V_26 = V_81 ;
break;
case V_82 :
args -> V_26 = V_83 ;
break;
case V_84 :
args -> V_26 = V_28 ;
default:
break;
}
F_38 ( V_3 ) ;
V_17 = F_26 ( V_11 , V_17 ) ;
return V_17 ;
}
int F_45 ( struct V_43 * V_40 , void * V_44 ,
struct V_30 * V_45 )
{
struct V_10 * V_11 = V_40 -> V_46 ;
struct V_85 * args = V_44 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_17 ;
V_3 = F_40 ( V_40 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL ) {
return - V_73 ;
}
V_5 = F_4 ( V_3 ) ;
V_17 = F_15 ( V_5 , NULL , false ) ;
if ( V_11 -> V_86 -> V_87 )
V_5 -> V_11 -> V_86 -> V_87 ( V_11 , V_5 ) ;
F_38 ( V_3 ) ;
V_17 = F_26 ( V_11 , V_17 ) ;
return V_17 ;
}
int F_46 ( struct V_43 * V_40 , void * V_44 ,
struct V_30 * V_45 )
{
struct V_88 * args = V_44 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_17 = 0 ;
F_47 ( L_6 , args -> V_70 ) ;
V_3 = F_40 ( V_40 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL )
return - V_73 ;
V_5 = F_4 ( V_3 ) ;
V_17 = F_48 ( V_5 , args -> V_89 , args -> V_90 ) ;
F_38 ( V_3 ) ;
return V_17 ;
}
int F_49 ( struct V_43 * V_40 , void * V_44 ,
struct V_30 * V_45 )
{
struct V_91 * args = V_44 ;
struct V_1 * V_3 ;
struct V_4 * V_32 ;
int V_17 = 0 ;
F_47 ( L_7 ) ;
V_3 = F_40 ( V_40 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL )
return - V_73 ;
V_32 = F_4 ( V_3 ) ;
V_17 = F_22 ( V_32 , false ) ;
if ( F_50 ( V_17 != 0 ) )
goto V_92;
F_51 ( V_32 , & args -> V_89 , & args -> V_90 ) ;
F_25 ( V_32 ) ;
V_92:
F_38 ( V_3 ) ;
return V_17 ;
}
int F_52 ( struct V_43 * V_40 , void * V_44 ,
struct V_30 * V_45 )
{
struct V_93 * args = V_44 ;
struct V_1 * V_3 ;
struct V_10 * V_11 = V_40 -> V_46 ;
struct V_33 * V_34 = V_45 -> V_35 ;
struct V_4 * V_32 ;
struct V_94 * V_95 ;
T_3 V_96 ;
int V_17 = 0 ;
if ( ! V_11 -> V_97 . V_98 ) {
args -> V_99 = V_100 ;
return - V_101 ;
}
if ( args -> V_102 ) {
args -> V_99 = V_100 ;
return - V_103 ;
}
if ( args -> V_104 < V_105 ) {
F_23 ( & V_40 -> V_106 -> V_40 ,
L_8 ,
( unsigned long ) args -> V_104 ,
V_105 ) ;
args -> V_99 = V_100 ;
return - V_103 ;
}
V_96 = V_107 | V_108 ;
if ( ( args -> V_109 & V_96 ) ) {
F_23 ( & V_40 -> V_106 -> V_40 , L_9 ,
args -> V_109 , V_96 ) ;
args -> V_99 = V_100 ;
return - V_103 ;
}
if ( ! ( args -> V_109 & V_110 ) ) {
F_23 ( & V_40 -> V_106 -> V_40 , L_10 ) ;
args -> V_99 = V_100 ;
return - V_103 ;
}
switch ( args -> V_99 ) {
case V_111 :
case V_112 :
break;
default:
F_23 ( & V_40 -> V_106 -> V_40 , L_11 ,
args -> V_99 ) ;
args -> V_99 = V_100 ;
return - V_103 ;
}
V_3 = F_40 ( V_40 , V_45 , args -> V_70 ) ;
if ( V_3 == NULL ) {
args -> V_99 = V_100 ;
return - V_73 ;
}
V_32 = F_4 ( V_3 ) ;
V_17 = F_22 ( V_32 , false ) ;
if ( V_17 ) {
args -> V_99 = V_100 ;
F_38 ( V_3 ) ;
return V_17 ;
}
switch ( args -> V_99 ) {
case V_111 :
V_95 = V_94 ( V_32 , & V_34 -> V_37 ) ;
if ( V_95 ) {
args -> V_99 = V_113 ;
args -> V_104 = V_95 -> V_114 ;
goto V_92;
}
V_17 = F_53 ( V_11 , & V_34 -> V_37 , V_32 ,
args -> V_104 , args -> V_109 ) ;
break;
case V_112 :
V_17 = F_24 ( V_11 , & V_34 -> V_37 , V_32 ) ;
break;
default:
break;
}
args -> V_99 = V_115 ;
if ( V_17 ) {
args -> V_99 = V_100 ;
}
V_92:
F_25 ( V_32 ) ;
F_38 ( V_3 ) ;
return V_17 ;
}
int F_54 ( struct V_30 * V_31 ,
struct V_43 * V_40 ,
struct V_116 * args )
{
struct V_10 * V_11 = V_40 -> V_46 ;
struct V_1 * V_3 ;
T_1 V_70 ;
int V_17 ;
args -> V_90 = F_55 ( V_11 , args -> V_117 , args -> V_118 , 0 ) * ( ( args -> V_118 + 1 ) / 8 ) ;
args -> V_12 = args -> V_90 * args -> V_119 ;
args -> V_12 = F_56 ( args -> V_12 , V_18 ) ;
V_17 = F_7 ( V_11 , args -> V_12 , 0 ,
V_81 ,
false , V_120 ,
& V_3 ) ;
if ( V_17 )
return - V_121 ;
V_17 = F_37 ( V_31 , V_3 , & V_70 ) ;
F_38 ( V_3 ) ;
if ( V_17 ) {
return V_17 ;
}
args -> V_70 = V_70 ;
return 0 ;
}
int F_57 ( struct V_30 * V_31 ,
struct V_43 * V_40 ,
T_1 V_70 )
{
return F_58 ( V_31 , V_70 ) ;
}
