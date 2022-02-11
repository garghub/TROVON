int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return 0 ;
if ( V_4 -> V_6 == NULL )
goto V_7;
F_2 ( V_4 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
V_7:
F_5 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_3 * V_4 ;
int V_9 , V_10 ;
V_4 = F_7 ( sizeof( struct V_3 ) , V_11 ) ;
if ( V_4 == NULL ) {
return - V_12 ;
}
V_2 -> V_5 = ( void * ) V_4 ;
if ( F_8 ( V_2 ) ) {
V_8 |= V_13 ;
} else if ( F_9 ( V_2 -> V_14 ) ) {
V_8 |= V_15 ;
} else {
V_8 |= V_16 ;
}
V_9 = F_10 ( V_4 , V_2 , V_2 -> V_14 , V_8 ) ;
if ( V_9 ) {
F_11 ( & V_2 -> V_14 -> V_2 , L_1 ) ;
goto V_17;
}
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
F_11 ( & V_2 -> V_14 -> V_2 , L_2 ) ;
if ( ! V_9 ) {
V_10 = F_13 ( V_4 ) ;
if ( V_10 )
F_14 ( & V_2 -> V_14 -> V_2 ,
L_3 ) ;
}
V_17:
if ( V_9 )
F_1 ( V_2 ) ;
return V_9 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_18 * * V_19 ,
struct V_18 * V_20 ,
T_1 * V_21 )
{
F_16 ( & V_2 -> V_22 ) ;
if ( * V_21 == 1 ) {
if ( ! * V_19 )
* V_19 = V_20 ;
} else if ( * V_21 == 0 ) {
if ( * V_19 == V_20 )
* V_19 = NULL ;
}
* V_21 = * V_19 == V_20 ? 1 : 0 ;
F_17 ( & V_2 -> V_22 ) ;
}
int F_18 ( struct V_1 * V_2 , void * V_23 , struct V_18 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_25 * V_26 = V_23 ;
struct V_27 * V_28 = & V_4 -> V_29 ;
T_1 * V_21 , V_30 , * V_31 , V_32 ;
T_2 V_33 ;
struct V_34 * V_35 ;
int V_36 , V_37 ;
V_31 = ( T_1 * ) ( ( unsigned long ) V_26 -> V_21 ) ;
V_21 = & V_30 ;
V_32 = sizeof( T_1 ) ;
switch ( V_26 -> V_38 ) {
case V_39 :
* V_21 = V_2 -> V_40 ;
break;
case V_41 :
* V_21 = V_4 -> V_42 ;
break;
case V_43 :
* V_21 = V_4 -> V_44 ;
break;
case V_45 :
if ( ( V_4 -> V_46 >= V_47 ) && ( V_4 -> V_46 <= V_48 ) )
* V_21 = false ;
else
* V_21 = V_4 -> V_49 ;
break;
case V_50 :
if ( F_19 ( V_21 , V_31 , sizeof( T_1 ) ) ) {
F_20 ( L_4 , V_51 , __LINE__ ) ;
return - V_52 ;
}
for ( V_36 = 0 , V_37 = 0 ; V_36 < V_4 -> V_53 ; V_36 ++ ) {
V_35 = (struct V_34 * ) V_28 -> V_54 [ V_36 ] ;
if ( V_35 && V_35 -> V_55 . V_56 == * V_21 ) {
struct V_57 * V_57 = F_21 ( V_35 ) ;
* V_21 = V_57 -> V_58 ;
V_37 = 1 ;
break;
}
}
if ( ! V_37 ) {
F_22 ( L_5 , * V_21 ) ;
return - V_59 ;
}
break;
case V_60 :
* V_21 = V_4 -> V_49 ;
break;
case V_61 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_65 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_65 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_68 . V_65 ;
else if ( V_4 -> V_46 >= V_69 )
* V_21 = V_4 -> V_63 . V_70 . V_65 ;
else if ( V_4 -> V_46 >= V_71 )
* V_21 = V_4 -> V_63 . V_72 . V_65 ;
else {
F_22 ( L_6 ) ;
return - V_59 ;
}
break;
case V_73 :
if ( F_19 ( V_21 , V_31 , sizeof( T_1 ) ) ) {
F_20 ( L_4 , V_51 , __LINE__ ) ;
return - V_52 ;
}
if ( * V_21 >= 2 ) {
F_22 ( L_7 , * V_21 ) ;
return - V_59 ;
}
F_15 ( V_2 , & V_4 -> V_74 , V_24 , V_21 ) ;
break;
case V_75 :
if ( F_19 ( V_21 , V_31 , sizeof( T_1 ) ) ) {
F_20 ( L_4 , V_51 , __LINE__ ) ;
return - V_52 ;
}
if ( * V_21 >= 2 ) {
F_22 ( L_8 , * V_21 ) ;
return - V_59 ;
}
F_15 ( V_2 , & V_4 -> V_76 , V_24 , V_21 ) ;
break;
case V_77 :
if ( V_4 -> V_78 -> V_79 )
* V_21 = F_23 ( V_4 ) * 10 ;
else
* V_21 = V_4 -> clock . V_80 . V_81 * 10 ;
break;
case V_82 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_83 *
V_4 -> V_63 . V_64 . V_84 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_83 *
V_4 -> V_63 . V_67 . V_84 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_68 . V_85 ;
else if ( V_4 -> V_46 >= V_69 )
* V_21 = V_4 -> V_63 . V_70 . V_85 ;
else if ( V_4 -> V_46 >= V_71 )
* V_21 = V_4 -> V_63 . V_72 . V_85 ;
else {
return - V_59 ;
}
break;
case V_86 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_87 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_87 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_68 . V_87 ;
else if ( V_4 -> V_46 >= V_69 )
* V_21 = V_4 -> V_63 . V_70 . V_87 ;
else if ( V_4 -> V_46 >= V_71 )
* V_21 = V_4 -> V_63 . V_72 . V_87 ;
else {
return - V_59 ;
}
break;
case V_88 :
* V_21 = 1 ;
break;
case V_89 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_90 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_90 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_68 . V_90 ;
else if ( V_4 -> V_46 >= V_69 )
* V_21 = V_4 -> V_63 . V_70 . V_90 ;
else if ( V_4 -> V_46 >= V_71 )
* V_21 = V_4 -> V_63 . V_72 . V_90 ;
else {
return - V_59 ;
}
break;
case V_91 :
if ( V_4 -> V_46 < V_66 )
return - V_59 ;
* V_21 = V_92 ;
break;
case V_93 :
if ( V_4 -> V_46 < V_66 )
return - V_59 ;
* V_21 = V_94 ;
break;
case V_95 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_96 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_97 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_68 . V_98 ;
else if ( V_4 -> V_46 >= V_69 )
* V_21 = V_4 -> V_63 . V_70 . V_98 ;
else if ( V_4 -> V_46 >= V_71 )
* V_21 = V_4 -> V_63 . V_72 . V_98 ;
else {
return - V_59 ;
}
break;
case V_99 :
if ( V_4 -> V_46 < V_71 ) {
F_22 ( L_9 ) ;
return - V_59 ;
}
V_21 = ( T_1 * ) & V_33 ;
V_32 = sizeof( T_2 ) ;
V_33 = F_24 ( V_4 ) ;
break;
case V_100 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_84 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_84 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_68 . V_101 ;
else
* V_21 = 1 ;
break;
case V_102 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_103 ;
else
return - V_59 ;
break;
case V_104 :
* V_21 = V_4 -> V_105 ;
break;
case V_106 :
if ( F_19 ( V_21 , V_31 , sizeof( T_1 ) ) ) {
F_20 ( L_4 , V_51 , __LINE__ ) ;
return - V_52 ;
}
switch ( * V_21 ) {
case V_107 :
case V_108 :
* V_21 = V_4 -> V_109 [ V_110 ] . V_111 ;
break;
case V_112 :
* V_21 = V_4 -> V_109 [ V_113 ] . V_111 ;
* V_21 |= V_4 -> V_109 [ V_114 ] . V_111 ;
break;
case V_115 :
* V_21 = V_4 -> V_109 [ V_116 ] . V_111 ;
break;
default:
return - V_59 ;
}
break;
case V_117 :
if ( V_4 -> V_46 < V_62 ) {
F_22 ( L_10 ) ;
return - V_59 ;
}
V_21 = V_4 -> V_63 . V_64 . V_118 ;
V_32 = sizeof( T_1 ) * 32 ;
break;
default:
F_22 ( L_11 , V_26 -> V_38 ) ;
return - V_59 ;
}
if ( F_25 ( V_31 , ( char * ) V_21 , V_32 ) ) {
F_20 ( L_12 , V_51 , __LINE__ ) ;
return - V_52 ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
F_28 () ;
}
int F_29 ( struct V_1 * V_2 , struct V_18 * V_119 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_119 -> V_120 = NULL ;
if ( V_4 -> V_46 >= V_66 ) {
struct V_121 * V_122 ;
struct V_123 * V_124 ;
int V_9 ;
V_122 = F_7 ( sizeof( * V_122 ) , V_11 ) ;
if ( F_30 ( ! V_122 ) ) {
return - V_12 ;
}
F_31 ( V_4 , & V_122 -> V_125 ) ;
V_124 = F_32 ( V_4 , & V_122 -> V_125 ,
V_4 -> V_126 . V_127 ) ;
V_9 = F_33 ( V_4 , V_124 , V_128 ,
V_129 |
V_130 ) ;
if ( V_9 ) {
F_34 ( V_4 , & V_122 -> V_125 ) ;
F_5 ( V_122 ) ;
return V_9 ;
}
V_119 -> V_120 = V_122 ;
}
return 0 ;
}
void F_35 ( struct V_1 * V_2 ,
struct V_18 * V_119 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_46 >= V_66 && V_119 -> V_120 ) {
struct V_121 * V_122 = V_119 -> V_120 ;
struct V_123 * V_124 ;
int V_9 ;
V_9 = F_36 ( V_4 -> V_126 . V_127 , false ) ;
if ( ! V_9 ) {
V_124 = F_37 ( & V_122 -> V_125 ,
V_4 -> V_126 . V_127 ) ;
if ( V_124 )
F_38 ( V_4 , V_124 ) ;
F_39 ( V_4 -> V_126 . V_127 ) ;
}
F_34 ( V_4 , & V_122 -> V_125 ) ;
F_5 ( V_122 ) ;
V_119 -> V_120 = NULL ;
}
}
void F_40 ( struct V_1 * V_2 ,
struct V_18 * V_119 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_74 == V_119 )
V_4 -> V_74 = NULL ;
if ( V_4 -> V_76 == V_119 )
V_4 -> V_76 = NULL ;
F_41 ( V_4 , V_119 ) ;
}
T_3 F_42 ( struct V_1 * V_2 , int V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_35 < 0 || V_35 >= V_4 -> V_53 ) {
F_20 ( L_13 , V_35 ) ;
return - V_59 ;
}
return F_43 ( V_4 , V_35 ) ;
}
int F_44 ( struct V_1 * V_2 , int V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_131 ;
int V_9 ;
if ( V_35 < 0 || V_35 >= V_4 -> V_53 ) {
F_20 ( L_13 , V_35 ) ;
return - V_59 ;
}
F_45 ( & V_4 -> V_132 . V_133 , V_131 ) ;
V_4 -> V_132 . V_134 [ V_35 ] = true ;
V_9 = F_46 ( V_4 ) ;
F_47 ( & V_4 -> V_132 . V_133 , V_131 ) ;
return V_9 ;
}
void F_48 ( struct V_1 * V_2 , int V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_131 ;
if ( V_35 < 0 || V_35 >= V_4 -> V_53 ) {
F_20 ( L_13 , V_35 ) ;
return;
}
F_45 ( & V_4 -> V_132 . V_133 , V_131 ) ;
V_4 -> V_132 . V_134 [ V_35 ] = false ;
F_46 ( V_4 ) ;
F_47 ( & V_4 -> V_132 . V_133 , V_131 ) ;
}
int F_49 ( struct V_1 * V_2 , int V_35 ,
int * V_135 ,
struct V_136 * V_137 ,
unsigned V_8 )
{
struct V_34 * V_138 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_35 < 0 || V_35 >= V_2 -> V_139 ) {
F_20 ( L_13 , V_35 ) ;
return - V_59 ;
}
V_138 = & V_4 -> V_29 . V_54 [ V_35 ] -> V_55 ;
return F_50 ( V_2 , V_35 , V_135 ,
V_137 , V_8 ,
V_138 ) ;
}
int F_51 ( struct V_1 * V_2 , void * V_23 ,
struct V_18 * V_119 )
{
return - V_59 ;
}
