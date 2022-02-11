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
unsigned long V_17 ;
int V_18 ;
* V_2 = NULL ;
if ( V_13 < V_19 ) {
V_13 = V_19 ;
}
V_17 = F_8 ( V_11 -> V_20 . V_21 , V_11 -> V_20 . V_22 ) ;
if ( V_12 > V_17 ) {
F_9 ( V_23 L_1 ,
V_24 , __LINE__ , V_12 >> 20 , V_17 >> 20 ) ;
return - V_25 ;
}
V_26:
V_18 = F_10 ( V_11 , V_12 , V_13 , V_16 , V_14 , NULL , & V_5 ) ;
if ( V_18 ) {
if ( V_18 != - V_27 ) {
if ( V_14 == V_28 ) {
V_14 |= V_29 ;
goto V_26;
}
F_11 ( L_2 ,
V_12 , V_14 , V_13 , V_18 ) ;
}
return V_18 ;
}
* V_2 = & V_5 -> V_6 ;
F_12 ( & V_11 -> V_30 . V_31 ) ;
F_13 ( & V_5 -> V_32 , & V_11 -> V_30 . V_33 ) ;
F_14 ( & V_11 -> V_30 . V_31 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_3 ,
T_1 V_34 , T_1 V_35 )
{
struct V_4 * V_5 ;
T_1 V_36 ;
int V_18 ;
V_5 = F_4 ( V_3 ) ;
V_36 = V_35 ;
if ( ! V_36 ) {
V_36 = V_34 ;
}
if ( ! V_36 ) {
F_9 ( V_23 L_3 ) ;
return 0 ;
}
if ( V_36 == V_37 ) {
V_18 = F_16 ( V_5 , NULL , false ) ;
if ( V_18 ) {
F_9 ( V_38 L_4 ) ;
return V_18 ;
}
}
return 0 ;
}
int F_17 ( struct V_10 * V_11 )
{
F_18 ( & V_11 -> V_30 . V_33 ) ;
return 0 ;
}
void F_19 ( struct V_10 * V_11 )
{
F_20 ( V_11 ) ;
}
int F_21 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_4 * V_41 = F_4 ( V_2 ) ;
struct V_10 * V_11 = V_41 -> V_11 ;
struct V_42 * V_43 = V_40 -> V_44 ;
struct V_45 * V_46 = & V_43 -> V_46 ;
struct V_47 * V_48 ;
int V_18 ;
if ( V_11 -> V_49 < V_50 ) {
return 0 ;
}
V_18 = F_22 ( V_41 , false ) ;
if ( V_18 ) {
return V_18 ;
}
V_48 = F_23 ( V_46 , V_41 ) ;
if ( ! V_48 ) {
V_48 = F_24 ( V_11 , V_46 , V_41 ) ;
} else {
++ V_48 -> V_51 ;
}
F_25 ( V_41 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_4 * V_41 = F_4 ( V_2 ) ;
struct V_10 * V_11 = V_41 -> V_11 ;
struct V_42 * V_43 = V_40 -> V_44 ;
struct V_45 * V_46 = & V_43 -> V_46 ;
struct V_47 * V_48 ;
int V_18 ;
if ( V_11 -> V_49 < V_50 ) {
return;
}
V_18 = F_22 ( V_41 , true ) ;
if ( V_18 ) {
F_27 ( V_11 -> V_52 , L_5
L_6 , V_18 ) ;
return;
}
V_48 = F_23 ( V_46 , V_41 ) ;
if ( V_48 ) {
if ( -- V_48 -> V_51 == 0 ) {
F_28 ( V_11 , V_48 ) ;
}
}
F_25 ( V_41 ) ;
}
static int F_29 ( struct V_10 * V_11 , int V_18 )
{
if ( V_18 == - V_53 ) {
V_18 = F_30 ( V_11 ) ;
if ( ! V_18 )
V_18 = - V_54 ;
}
return V_18 ;
}
int F_31 ( struct V_55 * V_52 , void * V_56 ,
struct V_39 * V_57 )
{
struct V_10 * V_11 = V_52 -> V_58 ;
struct V_59 * args = V_56 ;
struct V_60 * V_61 ;
unsigned V_62 ;
V_61 = & V_11 -> V_63 . V_64 . V_61 [ V_65 ] ;
args -> V_66 = V_11 -> V_20 . V_67 ;
args -> V_68 = ( V_69 ) V_61 -> V_12 << V_70 ;
if ( V_11 -> V_71 )
args -> V_68 -= F_32 ( V_11 -> V_71 ) ;
args -> V_68 -= F_33 ( V_11 ) ;
args -> V_72 = V_11 -> V_20 . V_22 - 4096 - V_73 * 64 * 1024 ;
for( V_62 = 0 ; V_62 < V_74 ; ++ V_62 )
args -> V_72 -= V_11 -> V_75 [ V_62 ] . V_76 ;
return 0 ;
}
int F_34 ( struct V_55 * V_52 , void * V_56 ,
struct V_39 * V_57 )
{
F_11 ( L_7 , V_24 ) ;
return - V_77 ;
}
int F_35 ( struct V_55 * V_52 , void * V_56 ,
struct V_39 * V_57 )
{
F_11 ( L_7 , V_24 ) ;
return - V_77 ;
}
int F_36 ( struct V_55 * V_52 , void * V_56 ,
struct V_39 * V_57 )
{
struct V_10 * V_11 = V_52 -> V_58 ;
struct V_78 * args = V_56 ;
struct V_1 * V_3 ;
T_1 V_79 ;
int V_18 ;
F_37 ( & V_11 -> V_80 ) ;
args -> V_12 = F_38 ( args -> V_12 , V_19 ) ;
V_18 = F_7 ( V_11 , args -> V_12 , args -> V_13 ,
args -> V_14 , false ,
false , & V_3 ) ;
if ( V_18 ) {
F_39 ( & V_11 -> V_80 ) ;
V_18 = F_29 ( V_11 , V_18 ) ;
return V_18 ;
}
V_18 = F_40 ( V_57 , V_3 , & V_79 ) ;
F_41 ( V_3 ) ;
if ( V_18 ) {
F_39 ( & V_11 -> V_80 ) ;
V_18 = F_29 ( V_11 , V_18 ) ;
return V_18 ;
}
args -> V_79 = V_79 ;
F_39 ( & V_11 -> V_80 ) ;
return 0 ;
}
int F_42 ( struct V_55 * V_52 , void * V_56 ,
struct V_39 * V_57 )
{
struct V_10 * V_11 = V_52 -> V_58 ;
struct V_81 * args = V_56 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_18 ;
F_37 ( & V_11 -> V_80 ) ;
V_3 = F_43 ( V_52 , V_57 , args -> V_79 ) ;
if ( V_3 == NULL ) {
F_39 ( & V_11 -> V_80 ) ;
return - V_82 ;
}
V_5 = F_4 ( V_3 ) ;
V_18 = F_15 ( V_3 , args -> V_83 , args -> V_84 ) ;
F_41 ( V_3 ) ;
F_39 ( & V_11 -> V_80 ) ;
V_18 = F_29 ( V_5 -> V_11 , V_18 ) ;
return V_18 ;
}
int F_44 ( struct V_39 * V_57 ,
struct V_55 * V_52 ,
T_1 V_79 , T_2 * V_85 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
V_3 = F_43 ( V_52 , V_57 , V_79 ) ;
if ( V_3 == NULL ) {
return - V_82 ;
}
V_5 = F_4 ( V_3 ) ;
* V_85 = F_45 ( V_5 ) ;
F_41 ( V_3 ) ;
return 0 ;
}
int F_46 ( struct V_55 * V_52 , void * V_56 ,
struct V_39 * V_57 )
{
struct V_86 * args = V_56 ;
return F_44 ( V_57 , V_52 , args -> V_79 , & args -> V_87 ) ;
}
int F_47 ( struct V_55 * V_52 , void * V_56 ,
struct V_39 * V_57 )
{
struct V_10 * V_11 = V_52 -> V_58 ;
struct V_88 * args = V_56 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_18 ;
T_1 V_89 = 0 ;
V_3 = F_43 ( V_52 , V_57 , args -> V_79 ) ;
if ( V_3 == NULL ) {
return - V_82 ;
}
V_5 = F_4 ( V_3 ) ;
V_18 = F_16 ( V_5 , & V_89 , true ) ;
switch ( V_89 ) {
case V_65 :
args -> V_36 = V_28 ;
break;
case V_90 :
args -> V_36 = V_29 ;
break;
case V_91 :
args -> V_36 = V_37 ;
default:
break;
}
F_41 ( V_3 ) ;
V_18 = F_29 ( V_11 , V_18 ) ;
return V_18 ;
}
int F_48 ( struct V_55 * V_52 , void * V_56 ,
struct V_39 * V_57 )
{
struct V_10 * V_11 = V_52 -> V_58 ;
struct V_92 * args = V_56 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_18 ;
V_3 = F_43 ( V_52 , V_57 , args -> V_79 ) ;
if ( V_3 == NULL ) {
return - V_82 ;
}
V_5 = F_4 ( V_3 ) ;
V_18 = F_16 ( V_5 , NULL , false ) ;
if ( V_11 -> V_93 -> V_94 )
V_5 -> V_11 -> V_93 -> V_94 ( V_11 , V_5 ) ;
F_41 ( V_3 ) ;
V_18 = F_29 ( V_11 , V_18 ) ;
return V_18 ;
}
int F_49 ( struct V_55 * V_52 , void * V_56 ,
struct V_39 * V_57 )
{
struct V_95 * args = V_56 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
int V_18 = 0 ;
F_50 ( L_8 , args -> V_79 ) ;
V_3 = F_43 ( V_52 , V_57 , args -> V_79 ) ;
if ( V_3 == NULL )
return - V_82 ;
V_5 = F_4 ( V_3 ) ;
V_18 = F_51 ( V_5 , args -> V_96 , args -> V_97 ) ;
F_41 ( V_3 ) ;
return V_18 ;
}
int F_52 ( struct V_55 * V_52 , void * V_56 ,
struct V_39 * V_57 )
{
struct V_98 * args = V_56 ;
struct V_1 * V_3 ;
struct V_4 * V_41 ;
int V_18 = 0 ;
F_50 ( L_9 ) ;
V_3 = F_43 ( V_52 , V_57 , args -> V_79 ) ;
if ( V_3 == NULL )
return - V_82 ;
V_41 = F_4 ( V_3 ) ;
V_18 = F_22 ( V_41 , false ) ;
if ( F_53 ( V_18 != 0 ) )
goto V_99;
F_54 ( V_41 , & args -> V_96 , & args -> V_97 ) ;
F_25 ( V_41 ) ;
V_99:
F_41 ( V_3 ) ;
return V_18 ;
}
int F_55 ( struct V_55 * V_52 , void * V_56 ,
struct V_39 * V_57 )
{
struct V_100 * args = V_56 ;
struct V_1 * V_3 ;
struct V_10 * V_11 = V_52 -> V_58 ;
struct V_42 * V_43 = V_57 -> V_44 ;
struct V_4 * V_41 ;
struct V_47 * V_48 ;
T_3 V_101 ;
int V_18 = 0 ;
if ( ! V_11 -> V_102 . V_103 ) {
args -> V_104 = V_105 ;
return - V_106 ;
}
if ( args -> V_107 ) {
args -> V_104 = V_105 ;
return - V_108 ;
}
if ( args -> V_109 < V_110 ) {
F_27 ( & V_52 -> V_111 -> V_52 ,
L_10 ,
( unsigned long ) args -> V_109 ,
V_110 ) ;
args -> V_104 = V_105 ;
return - V_108 ;
}
V_101 = V_112 | V_113 ;
if ( ( args -> V_114 & V_101 ) ) {
F_27 ( & V_52 -> V_111 -> V_52 , L_11 ,
args -> V_114 , V_101 ) ;
args -> V_104 = V_105 ;
return - V_108 ;
}
if ( ! ( args -> V_114 & V_115 ) ) {
F_27 ( & V_52 -> V_111 -> V_52 , L_12 ) ;
args -> V_104 = V_105 ;
return - V_108 ;
}
switch ( args -> V_104 ) {
case V_116 :
case V_117 :
break;
default:
F_27 ( & V_52 -> V_111 -> V_52 , L_13 ,
args -> V_104 ) ;
args -> V_104 = V_105 ;
return - V_108 ;
}
V_3 = F_43 ( V_52 , V_57 , args -> V_79 ) ;
if ( V_3 == NULL ) {
args -> V_104 = V_105 ;
return - V_82 ;
}
V_41 = F_4 ( V_3 ) ;
V_18 = F_22 ( V_41 , false ) ;
if ( V_18 ) {
args -> V_104 = V_105 ;
F_41 ( V_3 ) ;
return V_18 ;
}
V_48 = F_23 ( & V_43 -> V_46 , V_41 ) ;
if ( ! V_48 ) {
args -> V_104 = V_105 ;
F_41 ( V_3 ) ;
return - V_82 ;
}
switch ( args -> V_104 ) {
case V_116 :
if ( V_48 -> V_118 ) {
args -> V_104 = V_119 ;
args -> V_109 = V_48 -> V_118 ;
goto V_99;
}
V_18 = F_56 ( V_11 , V_48 , args -> V_109 , args -> V_114 ) ;
break;
case V_117 :
V_18 = F_56 ( V_11 , V_48 , 0 , 0 ) ;
break;
default:
break;
}
args -> V_104 = V_120 ;
if ( V_18 ) {
args -> V_104 = V_105 ;
}
V_99:
F_25 ( V_41 ) ;
F_41 ( V_3 ) ;
return V_18 ;
}
int F_57 ( struct V_39 * V_40 ,
struct V_55 * V_52 ,
struct V_121 * args )
{
struct V_10 * V_11 = V_52 -> V_58 ;
struct V_1 * V_3 ;
T_1 V_79 ;
int V_18 ;
args -> V_97 = F_58 ( V_11 , args -> V_122 , args -> V_123 , 0 ) * ( ( args -> V_123 + 1 ) / 8 ) ;
args -> V_12 = args -> V_97 * args -> V_124 ;
args -> V_12 = F_59 ( args -> V_12 , V_19 ) ;
V_18 = F_7 ( V_11 , args -> V_12 , 0 ,
V_28 ,
false , V_125 ,
& V_3 ) ;
if ( V_18 )
return - V_25 ;
V_18 = F_40 ( V_40 , V_3 , & V_79 ) ;
F_41 ( V_3 ) ;
if ( V_18 ) {
return V_18 ;
}
args -> V_79 = V_79 ;
return 0 ;
}
int F_60 ( struct V_39 * V_40 ,
struct V_55 * V_52 ,
T_1 V_79 )
{
return F_61 ( V_40 , V_79 ) ;
}
