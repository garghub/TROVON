int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return 0 ;
if ( V_4 -> V_6 == NULL )
goto V_7;
F_2 ( V_2 -> V_2 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
V_7:
F_6 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_3 * V_4 ;
int V_9 , V_10 ;
V_4 = F_8 ( sizeof( struct V_3 ) , V_11 ) ;
if ( V_4 == NULL ) {
return - V_12 ;
}
V_2 -> V_5 = ( void * ) V_4 ;
if ( F_9 ( V_2 ) ) {
V_8 |= V_13 ;
} else if ( F_10 ( V_2 -> V_14 ) ) {
V_8 |= V_15 ;
} else {
V_8 |= V_16 ;
}
V_9 = F_11 ( V_4 , V_2 , V_2 -> V_14 , V_8 ) ;
if ( V_9 ) {
F_12 ( & V_2 -> V_14 -> V_2 , L_1 ) ;
goto V_17;
}
V_9 = F_13 ( V_4 ) ;
if ( V_9 )
F_12 ( & V_2 -> V_14 -> V_2 , L_2 ) ;
if ( ! V_9 ) {
V_10 = F_14 ( V_4 ) ;
if ( V_10 )
F_15 ( & V_2 -> V_14 -> V_2 ,
L_3 ) ;
}
if ( V_18 != 0 ) {
F_16 ( V_2 -> V_2 ) ;
F_17 ( V_2 -> V_2 , 5000 ) ;
F_18 ( V_2 -> V_2 ) ;
F_19 ( V_2 -> V_2 ) ;
F_20 ( V_2 -> V_2 ) ;
F_21 ( V_2 -> V_2 ) ;
}
V_17:
if ( V_9 )
F_1 ( V_2 ) ;
return V_9 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_19 * * V_20 ,
struct V_19 * V_21 ,
T_1 * V_22 )
{
F_23 ( & V_2 -> V_23 ) ;
if ( * V_22 == 1 ) {
if ( ! * V_20 )
* V_20 = V_21 ;
} else if ( * V_22 == 0 ) {
if ( * V_20 == V_21 )
* V_20 = NULL ;
}
* V_22 = * V_20 == V_21 ? 1 : 0 ;
F_24 ( & V_2 -> V_23 ) ;
}
int F_25 ( struct V_1 * V_2 , void * V_24 , struct V_19 * V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_26 * V_27 = V_24 ;
struct V_28 * V_29 = & V_4 -> V_30 ;
T_1 * V_22 , V_31 , * V_32 , V_33 ;
T_2 V_34 ;
struct V_35 * V_36 ;
int V_37 , V_38 ;
V_32 = ( T_1 * ) ( ( unsigned long ) V_27 -> V_22 ) ;
V_22 = & V_31 ;
V_33 = sizeof( T_1 ) ;
switch ( V_27 -> V_39 ) {
case V_40 :
* V_22 = V_2 -> V_14 -> V_41 ;
break;
case V_42 :
* V_22 = V_4 -> V_43 ;
break;
case V_44 :
* V_22 = V_4 -> V_45 ;
break;
case V_46 :
if ( ( V_4 -> V_47 >= V_48 ) && ( V_4 -> V_47 <= V_49 ) )
* V_22 = false ;
else
* V_22 = V_4 -> V_50 ;
break;
case V_51 :
if ( F_26 ( V_22 , V_32 , sizeof( T_1 ) ) ) {
F_27 ( L_4 , V_52 , __LINE__ ) ;
return - V_53 ;
}
for ( V_37 = 0 , V_38 = 0 ; V_37 < V_4 -> V_54 ; V_37 ++ ) {
V_36 = (struct V_35 * ) V_29 -> V_55 [ V_37 ] ;
if ( V_36 && V_36 -> V_56 . V_57 == * V_22 ) {
struct V_58 * V_58 = F_28 ( V_36 ) ;
* V_22 = V_58 -> V_59 ;
V_38 = 1 ;
break;
}
}
if ( ! V_38 ) {
F_29 ( L_5 , * V_22 ) ;
return - V_60 ;
}
break;
case V_61 :
* V_22 = V_4 -> V_50 ;
break;
case V_62 :
if ( V_4 -> V_47 >= V_63 )
* V_22 = V_4 -> V_64 . V_65 . V_66 ;
else if ( V_4 -> V_47 >= V_67 )
* V_22 = V_4 -> V_64 . V_68 . V_66 ;
else if ( V_4 -> V_47 >= V_69 )
* V_22 = V_4 -> V_64 . V_70 . V_66 ;
else if ( V_4 -> V_47 >= V_48 )
* V_22 = V_4 -> V_64 . V_71 . V_66 ;
else if ( V_4 -> V_47 >= V_72 )
* V_22 = V_4 -> V_64 . V_73 . V_66 ;
else if ( V_4 -> V_47 >= V_74 )
* V_22 = V_4 -> V_64 . V_75 . V_66 ;
else {
F_29 ( L_6 ) ;
return - V_60 ;
}
break;
case V_76 :
if ( F_26 ( V_22 , V_32 , sizeof( T_1 ) ) ) {
F_27 ( L_4 , V_52 , __LINE__ ) ;
return - V_53 ;
}
if ( * V_22 >= 2 ) {
F_29 ( L_7 , * V_22 ) ;
return - V_60 ;
}
F_22 ( V_2 , & V_4 -> V_77 , V_25 , V_22 ) ;
break;
case V_78 :
if ( F_26 ( V_22 , V_32 , sizeof( T_1 ) ) ) {
F_27 ( L_4 , V_52 , __LINE__ ) ;
return - V_53 ;
}
if ( * V_22 >= 2 ) {
F_29 ( L_8 , * V_22 ) ;
return - V_60 ;
}
F_22 ( V_2 , & V_4 -> V_79 , V_25 , V_22 ) ;
break;
case V_80 :
if ( V_4 -> V_81 -> V_82 )
* V_22 = F_30 ( V_4 ) * 10 ;
else
* V_22 = V_4 -> clock . V_83 . V_84 * 10 ;
break;
case V_85 :
if ( V_4 -> V_47 >= V_63 )
* V_22 = V_4 -> V_64 . V_65 . V_86 *
V_4 -> V_64 . V_65 . V_87 ;
else if ( V_4 -> V_47 >= V_67 )
* V_22 = V_4 -> V_64 . V_68 . V_86 *
V_4 -> V_64 . V_68 . V_87 ;
else if ( V_4 -> V_47 >= V_69 )
* V_22 = V_4 -> V_64 . V_70 . V_86 *
V_4 -> V_64 . V_70 . V_87 ;
else if ( V_4 -> V_47 >= V_48 )
* V_22 = V_4 -> V_64 . V_71 . V_88 ;
else if ( V_4 -> V_47 >= V_72 )
* V_22 = V_4 -> V_64 . V_73 . V_88 ;
else if ( V_4 -> V_47 >= V_74 )
* V_22 = V_4 -> V_64 . V_75 . V_88 ;
else {
return - V_60 ;
}
break;
case V_89 :
if ( V_4 -> V_47 >= V_63 )
* V_22 = V_4 -> V_64 . V_65 . V_90 ;
else if ( V_4 -> V_47 >= V_67 )
* V_22 = V_4 -> V_64 . V_68 . V_90 ;
else if ( V_4 -> V_47 >= V_69 )
* V_22 = V_4 -> V_64 . V_70 . V_90 ;
else if ( V_4 -> V_47 >= V_48 )
* V_22 = V_4 -> V_64 . V_71 . V_90 ;
else if ( V_4 -> V_47 >= V_72 )
* V_22 = V_4 -> V_64 . V_73 . V_90 ;
else if ( V_4 -> V_47 >= V_74 )
* V_22 = V_4 -> V_64 . V_75 . V_90 ;
else {
return - V_60 ;
}
break;
case V_91 :
* V_22 = 1 ;
break;
case V_92 :
if ( V_4 -> V_47 >= V_63 )
* V_22 = V_4 -> V_64 . V_65 . V_93 ;
else if ( V_4 -> V_47 >= V_67 )
* V_22 = V_4 -> V_64 . V_68 . V_93 ;
else if ( V_4 -> V_47 >= V_69 )
* V_22 = V_4 -> V_64 . V_70 . V_93 ;
else if ( V_4 -> V_47 >= V_48 )
* V_22 = V_4 -> V_64 . V_71 . V_93 ;
else if ( V_4 -> V_47 >= V_72 )
* V_22 = V_4 -> V_64 . V_73 . V_93 ;
else if ( V_4 -> V_47 >= V_74 )
* V_22 = V_4 -> V_64 . V_75 . V_93 ;
else {
return - V_60 ;
}
break;
case V_94 :
if ( V_4 -> V_47 < V_69 )
return - V_60 ;
* V_22 = V_95 ;
break;
case V_96 :
if ( V_4 -> V_47 < V_69 )
return - V_60 ;
* V_22 = V_97 ;
break;
case V_98 :
if ( V_4 -> V_47 >= V_63 )
* V_22 = V_4 -> V_64 . V_65 . V_99 ;
else if ( V_4 -> V_47 >= V_67 )
* V_22 = V_4 -> V_64 . V_68 . V_99 ;
else if ( V_4 -> V_47 >= V_69 )
* V_22 = V_4 -> V_64 . V_70 . V_100 ;
else if ( V_4 -> V_47 >= V_48 )
* V_22 = V_4 -> V_64 . V_71 . V_101 ;
else if ( V_4 -> V_47 >= V_72 )
* V_22 = V_4 -> V_64 . V_73 . V_101 ;
else if ( V_4 -> V_47 >= V_74 )
* V_22 = V_4 -> V_64 . V_75 . V_101 ;
else {
return - V_60 ;
}
break;
case V_102 :
if ( V_4 -> V_47 < V_74 ) {
F_29 ( L_9 ) ;
return - V_60 ;
}
V_22 = ( T_1 * ) & V_34 ;
V_33 = sizeof( T_2 ) ;
V_34 = F_31 ( V_4 ) ;
break;
case V_103 :
if ( V_4 -> V_47 >= V_63 )
* V_22 = V_4 -> V_64 . V_65 . V_87 ;
else if ( V_4 -> V_47 >= V_67 )
* V_22 = V_4 -> V_64 . V_68 . V_87 ;
else if ( V_4 -> V_47 >= V_69 )
* V_22 = V_4 -> V_64 . V_70 . V_87 ;
else if ( V_4 -> V_47 >= V_48 )
* V_22 = V_4 -> V_64 . V_71 . V_104 ;
else
* V_22 = 1 ;
break;
case V_105 :
if ( V_4 -> V_47 >= V_63 )
* V_22 = V_4 -> V_64 . V_65 . V_106 ;
else if ( V_4 -> V_47 >= V_67 )
* V_22 = V_4 -> V_64 . V_68 . V_106 ;
else
return - V_60 ;
break;
case V_107 :
* V_22 = V_4 -> V_108 ;
break;
case V_109 :
if ( F_26 ( V_22 , V_32 , sizeof( T_1 ) ) ) {
F_27 ( L_4 , V_52 , __LINE__ ) ;
return - V_53 ;
}
switch ( * V_22 ) {
case V_110 :
case V_111 :
* V_22 = V_4 -> V_112 [ V_113 ] . V_114 ;
break;
case V_115 :
* V_22 = V_4 -> V_112 [ V_116 ] . V_114 ;
* V_22 |= V_4 -> V_112 [ V_117 ] . V_114 ;
break;
case V_118 :
* V_22 = V_4 -> V_112 [ V_119 ] . V_114 ;
break;
default:
return - V_60 ;
}
break;
case V_120 :
if ( V_4 -> V_47 >= V_63 ) {
V_22 = V_4 -> V_64 . V_65 . V_121 ;
V_33 = sizeof( T_1 ) * 32 ;
} else if ( V_4 -> V_47 >= V_67 ) {
V_22 = V_4 -> V_64 . V_68 . V_121 ;
V_33 = sizeof( T_1 ) * 32 ;
} else {
F_29 ( L_10 ) ;
return - V_60 ;
}
break;
case V_122 :
if ( V_4 -> V_47 >= V_63 ) {
V_22 = V_4 -> V_64 . V_65 . V_123 ;
V_33 = sizeof( T_1 ) * 16 ;
} else {
F_29 ( L_11 ) ;
return - V_60 ;
}
break;
case V_124 :
* V_22 = 1 ;
break;
case V_125 :
if ( V_4 -> V_47 >= V_63 ) {
* V_22 = V_4 -> V_64 . V_65 . V_126 ;
} else if ( V_4 -> V_47 >= V_67 ) {
* V_22 = V_4 -> V_64 . V_68 . V_126 ;
} else {
F_29 ( L_12 ) ;
}
break;
default:
F_29 ( L_13 , V_27 -> V_39 ) ;
return - V_60 ;
}
if ( F_32 ( V_32 , ( char * ) V_22 , V_33 ) ) {
F_27 ( L_14 , V_52 , __LINE__ ) ;
return - V_53 ;
}
return 0 ;
}
void F_33 ( struct V_1 * V_2 )
{
F_34 () ;
}
int F_35 ( struct V_1 * V_2 , struct V_19 * V_127 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
V_127 -> V_128 = NULL ;
V_9 = F_2 ( V_2 -> V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_4 -> V_47 >= V_69 ) {
struct V_129 * V_130 ;
struct V_131 * V_132 ;
int V_9 ;
V_130 = F_8 ( sizeof( * V_130 ) , V_11 ) ;
if ( F_36 ( ! V_130 ) ) {
return - V_12 ;
}
F_37 ( V_4 , & V_130 -> V_133 ) ;
V_132 = F_38 ( V_4 , & V_130 -> V_133 ,
V_4 -> V_134 . V_135 ) ;
V_9 = F_39 ( V_4 , V_132 , V_136 ,
V_137 |
V_138 ) ;
if ( V_9 ) {
F_40 ( V_4 , & V_130 -> V_133 ) ;
F_6 ( V_130 ) ;
return V_9 ;
}
V_127 -> V_128 = V_130 ;
}
F_20 ( V_2 -> V_2 ) ;
F_21 ( V_2 -> V_2 ) ;
return 0 ;
}
void F_41 ( struct V_1 * V_2 ,
struct V_19 * V_127 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_47 >= V_69 && V_127 -> V_128 ) {
struct V_129 * V_130 = V_127 -> V_128 ;
struct V_131 * V_132 ;
int V_9 ;
V_9 = F_42 ( V_4 -> V_134 . V_135 , false ) ;
if ( ! V_9 ) {
V_132 = F_43 ( & V_130 -> V_133 ,
V_4 -> V_134 . V_135 ) ;
if ( V_132 )
F_44 ( V_4 , V_132 ) ;
F_45 ( V_4 -> V_134 . V_135 ) ;
}
F_40 ( V_4 , & V_130 -> V_133 ) ;
F_6 ( V_130 ) ;
V_127 -> V_128 = NULL ;
}
}
void F_46 ( struct V_1 * V_2 ,
struct V_19 * V_127 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_77 == V_127 )
V_4 -> V_77 = NULL ;
if ( V_4 -> V_79 == V_127 )
V_4 -> V_79 = NULL ;
F_47 ( V_4 , V_127 ) ;
}
T_3 F_48 ( struct V_1 * V_2 , int V_36 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_36 < 0 || V_36 >= V_4 -> V_54 ) {
F_27 ( L_15 , V_36 ) ;
return - V_60 ;
}
return F_49 ( V_4 , V_36 ) ;
}
int F_50 ( struct V_1 * V_2 , int V_36 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_139 ;
int V_9 ;
if ( V_36 < 0 || V_36 >= V_4 -> V_54 ) {
F_27 ( L_15 , V_36 ) ;
return - V_60 ;
}
F_51 ( & V_4 -> V_140 . V_141 , V_139 ) ;
V_4 -> V_140 . V_142 [ V_36 ] = true ;
V_9 = F_52 ( V_4 ) ;
F_53 ( & V_4 -> V_140 . V_141 , V_139 ) ;
return V_9 ;
}
void F_54 ( struct V_1 * V_2 , int V_36 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_139 ;
if ( V_36 < 0 || V_36 >= V_4 -> V_54 ) {
F_27 ( L_15 , V_36 ) ;
return;
}
F_51 ( & V_4 -> V_140 . V_141 , V_139 ) ;
V_4 -> V_140 . V_142 [ V_36 ] = false ;
F_52 ( V_4 ) ;
F_53 ( & V_4 -> V_140 . V_141 , V_139 ) ;
}
int F_55 ( struct V_1 * V_2 , int V_36 ,
int * V_143 ,
struct V_144 * V_145 ,
unsigned V_8 )
{
struct V_35 * V_146 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_36 < 0 || V_36 >= V_2 -> V_147 ) {
F_27 ( L_15 , V_36 ) ;
return - V_60 ;
}
V_146 = & V_4 -> V_30 . V_55 [ V_36 ] -> V_56 ;
return F_56 ( V_2 , V_36 , V_143 ,
V_145 , V_8 ,
V_146 ) ;
}
