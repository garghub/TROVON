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
else if ( V_4 -> V_46 >= V_68 )
* V_21 = V_4 -> V_63 . V_69 . V_65 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_70 . V_65 ;
else if ( V_4 -> V_46 >= V_71 )
* V_21 = V_4 -> V_63 . V_72 . V_65 ;
else if ( V_4 -> V_46 >= V_73 )
* V_21 = V_4 -> V_63 . V_74 . V_65 ;
else {
F_22 ( L_6 ) ;
return - V_59 ;
}
break;
case V_75 :
if ( F_19 ( V_21 , V_31 , sizeof( T_1 ) ) ) {
F_20 ( L_4 , V_51 , __LINE__ ) ;
return - V_52 ;
}
if ( * V_21 >= 2 ) {
F_22 ( L_7 , * V_21 ) ;
return - V_59 ;
}
F_15 ( V_2 , & V_4 -> V_76 , V_24 , V_21 ) ;
break;
case V_77 :
if ( F_19 ( V_21 , V_31 , sizeof( T_1 ) ) ) {
F_20 ( L_4 , V_51 , __LINE__ ) ;
return - V_52 ;
}
if ( * V_21 >= 2 ) {
F_22 ( L_8 , * V_21 ) ;
return - V_59 ;
}
F_15 ( V_2 , & V_4 -> V_78 , V_24 , V_21 ) ;
break;
case V_79 :
if ( V_4 -> V_80 -> V_81 )
* V_21 = F_23 ( V_4 ) * 10 ;
else
* V_21 = V_4 -> clock . V_82 . V_83 * 10 ;
break;
case V_84 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_85 *
V_4 -> V_63 . V_64 . V_86 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_85 *
V_4 -> V_63 . V_67 . V_86 ;
else if ( V_4 -> V_46 >= V_68 )
* V_21 = V_4 -> V_63 . V_69 . V_85 *
V_4 -> V_63 . V_69 . V_86 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_70 . V_87 ;
else if ( V_4 -> V_46 >= V_71 )
* V_21 = V_4 -> V_63 . V_72 . V_87 ;
else if ( V_4 -> V_46 >= V_73 )
* V_21 = V_4 -> V_63 . V_74 . V_87 ;
else {
return - V_59 ;
}
break;
case V_88 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_89 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_89 ;
else if ( V_4 -> V_46 >= V_68 )
* V_21 = V_4 -> V_63 . V_69 . V_89 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_70 . V_89 ;
else if ( V_4 -> V_46 >= V_71 )
* V_21 = V_4 -> V_63 . V_72 . V_89 ;
else if ( V_4 -> V_46 >= V_73 )
* V_21 = V_4 -> V_63 . V_74 . V_89 ;
else {
return - V_59 ;
}
break;
case V_90 :
* V_21 = 1 ;
break;
case V_91 :
if ( V_4 -> V_46 >= V_62 )
return - V_59 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_92 ;
else if ( V_4 -> V_46 >= V_68 )
* V_21 = V_4 -> V_63 . V_69 . V_92 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_70 . V_92 ;
else if ( V_4 -> V_46 >= V_71 )
* V_21 = V_4 -> V_63 . V_72 . V_92 ;
else if ( V_4 -> V_46 >= V_73 )
* V_21 = V_4 -> V_63 . V_74 . V_92 ;
else {
return - V_59 ;
}
break;
case V_93 :
if ( V_4 -> V_46 < V_68 )
return - V_59 ;
* V_21 = V_94 ;
break;
case V_95 :
if ( V_4 -> V_46 < V_68 )
return - V_59 ;
* V_21 = V_96 ;
break;
case V_97 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_98 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_98 ;
else if ( V_4 -> V_46 >= V_68 )
* V_21 = V_4 -> V_63 . V_69 . V_99 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_70 . V_100 ;
else if ( V_4 -> V_46 >= V_71 )
* V_21 = V_4 -> V_63 . V_72 . V_100 ;
else if ( V_4 -> V_46 >= V_73 )
* V_21 = V_4 -> V_63 . V_74 . V_100 ;
else {
return - V_59 ;
}
break;
case V_101 :
if ( V_4 -> V_46 < V_73 ) {
F_22 ( L_9 ) ;
return - V_59 ;
}
V_21 = ( T_1 * ) & V_33 ;
V_32 = sizeof( T_2 ) ;
V_33 = F_24 ( V_4 ) ;
break;
case V_102 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_86 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_86 ;
else if ( V_4 -> V_46 >= V_68 )
* V_21 = V_4 -> V_63 . V_69 . V_86 ;
else if ( V_4 -> V_46 >= V_47 )
* V_21 = V_4 -> V_63 . V_70 . V_103 ;
else
* V_21 = 1 ;
break;
case V_104 :
if ( V_4 -> V_46 >= V_62 )
* V_21 = V_4 -> V_63 . V_64 . V_105 ;
else if ( V_4 -> V_46 >= V_66 )
* V_21 = V_4 -> V_63 . V_67 . V_105 ;
else
return - V_59 ;
break;
case V_106 :
* V_21 = V_4 -> V_107 ;
break;
case V_108 :
if ( F_19 ( V_21 , V_31 , sizeof( T_1 ) ) ) {
F_20 ( L_4 , V_51 , __LINE__ ) ;
return - V_52 ;
}
switch ( * V_21 ) {
case V_109 :
case V_110 :
* V_21 = V_4 -> V_111 [ V_112 ] . V_113 ;
break;
case V_114 :
* V_21 = V_4 -> V_111 [ V_115 ] . V_113 ;
* V_21 |= V_4 -> V_111 [ V_116 ] . V_113 ;
break;
case V_117 :
* V_21 = V_4 -> V_111 [ V_118 ] . V_113 ;
break;
default:
return - V_59 ;
}
break;
case V_119 :
if ( V_4 -> V_46 >= V_62 ) {
V_21 = V_4 -> V_63 . V_64 . V_120 ;
V_32 = sizeof( T_1 ) * 32 ;
} else if ( V_4 -> V_46 >= V_66 ) {
V_21 = V_4 -> V_63 . V_67 . V_120 ;
V_32 = sizeof( T_1 ) * 32 ;
} else {
F_22 ( L_10 ) ;
return - V_59 ;
}
break;
case V_121 :
* V_21 = 1 ;
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
void F_26 ( struct V_1 * V_2 )
{
F_27 () ;
}
int F_28 ( struct V_1 * V_2 , struct V_18 * V_122 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_122 -> V_123 = NULL ;
if ( V_4 -> V_46 >= V_68 ) {
struct V_124 * V_125 ;
struct V_126 * V_127 ;
int V_9 ;
V_125 = F_7 ( sizeof( * V_125 ) , V_11 ) ;
if ( F_29 ( ! V_125 ) ) {
return - V_12 ;
}
F_30 ( V_4 , & V_125 -> V_128 ) ;
V_127 = F_31 ( V_4 , & V_125 -> V_128 ,
V_4 -> V_129 . V_130 ) ;
V_9 = F_32 ( V_4 , V_127 , V_131 ,
V_132 |
V_133 ) ;
if ( V_9 ) {
F_33 ( V_4 , & V_125 -> V_128 ) ;
F_5 ( V_125 ) ;
return V_9 ;
}
V_122 -> V_123 = V_125 ;
}
return 0 ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_18 * V_122 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_46 >= V_68 && V_122 -> V_123 ) {
struct V_124 * V_125 = V_122 -> V_123 ;
struct V_126 * V_127 ;
int V_9 ;
V_9 = F_35 ( V_4 -> V_129 . V_130 , false ) ;
if ( ! V_9 ) {
V_127 = F_36 ( & V_125 -> V_128 ,
V_4 -> V_129 . V_130 ) ;
if ( V_127 )
F_37 ( V_4 , V_127 ) ;
F_38 ( V_4 -> V_129 . V_130 ) ;
}
F_33 ( V_4 , & V_125 -> V_128 ) ;
F_5 ( V_125 ) ;
V_122 -> V_123 = NULL ;
}
}
void F_39 ( struct V_1 * V_2 ,
struct V_18 * V_122 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_76 == V_122 )
V_4 -> V_76 = NULL ;
if ( V_4 -> V_78 == V_122 )
V_4 -> V_78 = NULL ;
F_40 ( V_4 , V_122 ) ;
}
T_3 F_41 ( struct V_1 * V_2 , int V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_35 < 0 || V_35 >= V_4 -> V_53 ) {
F_20 ( L_13 , V_35 ) ;
return - V_59 ;
}
return F_42 ( V_4 , V_35 ) ;
}
int F_43 ( struct V_1 * V_2 , int V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_134 ;
int V_9 ;
if ( V_35 < 0 || V_35 >= V_4 -> V_53 ) {
F_20 ( L_13 , V_35 ) ;
return - V_59 ;
}
F_44 ( & V_4 -> V_135 . V_136 , V_134 ) ;
V_4 -> V_135 . V_137 [ V_35 ] = true ;
V_9 = F_45 ( V_4 ) ;
F_46 ( & V_4 -> V_135 . V_136 , V_134 ) ;
return V_9 ;
}
void F_47 ( struct V_1 * V_2 , int V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_134 ;
if ( V_35 < 0 || V_35 >= V_4 -> V_53 ) {
F_20 ( L_13 , V_35 ) ;
return;
}
F_44 ( & V_4 -> V_135 . V_136 , V_134 ) ;
V_4 -> V_135 . V_137 [ V_35 ] = false ;
F_45 ( V_4 ) ;
F_46 ( & V_4 -> V_135 . V_136 , V_134 ) ;
}
int F_48 ( struct V_1 * V_2 , int V_35 ,
int * V_138 ,
struct V_139 * V_140 ,
unsigned V_8 )
{
struct V_34 * V_141 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_35 < 0 || V_35 >= V_2 -> V_142 ) {
F_20 ( L_13 , V_35 ) ;
return - V_59 ;
}
V_141 = & V_4 -> V_29 . V_54 [ V_35 ] -> V_55 ;
return F_49 ( V_2 , V_35 , V_138 ,
V_140 , V_8 ,
V_141 ) ;
}
