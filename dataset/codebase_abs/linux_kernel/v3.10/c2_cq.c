static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
unsigned long V_6 ;
F_2 ( & V_3 -> V_7 , V_6 ) ;
V_5 = V_3 -> V_8 [ V_4 ] ;
if ( ! V_5 ) {
F_3 ( & V_3 -> V_7 , V_6 ) ;
return NULL ;
}
F_4 ( & V_5 -> V_9 ) ;
F_3 ( & V_3 -> V_7 , V_6 ) ;
return V_5 ;
}
static void F_5 ( struct V_1 * V_5 )
{
if ( F_6 ( & V_5 -> V_9 ) )
F_7 ( & V_5 -> V_10 ) ;
}
void F_8 ( struct V_2 * V_3 , T_1 V_11 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 , V_11 ) ;
if ( ! V_5 ) {
F_9 ( L_1 , V_11 ) ;
return;
}
(* V_5 -> V_12 . V_13 ) ( & V_5 -> V_12 , V_5 -> V_12 . V_14 ) ;
F_5 ( V_5 ) ;
}
void F_10 ( struct V_2 * V_3 , struct V_15 * V_16 , T_1 V_11 )
{
struct V_1 * V_5 ;
struct V_17 * V_18 ;
V_5 = F_1 ( V_3 , V_11 ) ;
if ( ! V_5 )
return;
F_11 ( & V_5 -> V_7 ) ;
V_18 = & V_5 -> V_19 ;
if ( V_18 && ! F_12 ( V_18 ) ) {
T_2 V_20 = V_18 -> V_20 ;
struct V_21 * V_22 ;
while ( V_20 != F_13 ( * V_18 -> V_23 ) ) {
V_22 = (struct V_21 * )
( V_18 -> V_24 . V_25 + V_20 * V_18 -> V_26 ) ;
if ( V_22 -> V_27 == ( V_28 ) ( unsigned long ) V_16 ) {
V_22 -> V_27 = ( V_28 ) 0 ;
}
V_20 = ( V_20 + 1 ) % V_18 -> V_29 ;
}
}
F_14 ( & V_5 -> V_7 ) ;
F_5 ( V_5 ) ;
}
static inline enum V_30 F_15 ( T_3 V_31 )
{
switch ( V_31 ) {
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
case V_38 :
return V_39 ;
case V_40 :
return V_41 ;
case V_42 :
return V_43 ;
default:
return V_44 ;
}
}
static inline int F_16 ( struct V_2 * V_3 ,
struct V_1 * V_5 , struct V_45 * V_46 )
{
struct V_21 * V_47 ;
struct V_15 * V_16 ;
int V_48 = 0 ;
V_47 = F_17 ( & V_5 -> V_19 ) ;
if ( ! V_47 ) {
return - V_49 ;
}
while ( ( V_16 =
(struct V_15 * ) ( unsigned long ) V_47 -> V_27 ) == NULL ) {
F_18 ( & V_5 -> V_19 ) ;
V_47 = F_17 ( & V_5 -> V_19 ) ;
if ( ! V_47 )
return - V_49 ;
}
V_46 -> V_31 = F_15 ( F_19 ( V_47 ) ) ;
V_46 -> V_50 = V_47 -> V_51 . V_52 ;
V_46 -> V_16 = & V_16 -> V_53 ;
V_46 -> V_54 = 0 ;
V_46 -> V_55 = 0 ;
V_46 -> V_56 = 0 ;
V_46 -> V_57 = 0 ;
V_46 -> V_58 = 0 ;
V_46 -> V_59 = 0 ;
switch ( F_20 ( V_47 ) ) {
case V_60 :
V_46 -> V_61 = V_62 ;
break;
case V_63 :
V_46 -> V_61 = V_64 ;
break;
case V_65 :
V_46 -> V_61 = V_66 ;
break;
case V_67 :
V_46 -> V_61 = V_68 ;
break;
case V_69 :
V_46 -> V_70 = F_21 ( V_47 -> V_71 ) ;
V_46 -> V_61 = V_72 ;
V_48 = 1 ;
break;
default:
break;
}
if ( V_48 )
F_22 ( & V_16 -> V_73 , 1 ) ;
else
F_22 ( & V_16 -> V_74 ,
F_21 ( F_23 ( V_47 ) ) + 1 ) ;
F_18 ( & V_5 -> V_19 ) ;
return 0 ;
}
int F_24 ( struct V_75 * V_12 , int V_76 , struct V_45 * V_46 )
{
struct V_2 * V_3 = F_25 ( V_12 -> V_77 ) ;
struct V_1 * V_5 = F_26 ( V_12 ) ;
unsigned long V_6 ;
int V_78 , V_79 ;
F_2 ( & V_5 -> V_7 , V_6 ) ;
for ( V_78 = 0 ; V_78 < V_76 ; ++ V_78 ) {
V_79 = F_16 ( V_3 , V_5 , V_46 + V_78 ) ;
if ( V_79 )
break;
}
F_3 ( & V_5 -> V_7 , V_6 ) ;
return V_78 ;
}
int F_27 ( struct V_75 * V_12 , enum V_80 V_81 )
{
struct V_82 T_4 * V_23 ;
struct V_1 * V_5 ;
unsigned long V_6 ;
int V_83 = 0 ;
V_5 = F_26 ( V_12 ) ;
V_23 = V_5 -> V_19 . V_84 ;
if ( ( V_81 & V_85 ) == V_86 )
F_28 ( V_87 , & V_23 -> V_88 ) ;
else if ( ( V_81 & V_85 ) == V_89 )
F_28 ( V_90 , & V_23 -> V_88 ) ;
else
return - V_91 ;
F_28 ( V_92 | V_93 , & V_23 -> V_94 ) ;
F_29 ( & V_23 -> V_94 ) ;
if ( V_81 & V_95 ) {
F_2 ( & V_5 -> V_7 , V_6 ) ;
V_83 = ! F_12 ( & V_5 -> V_19 ) ;
F_3 ( & V_5 -> V_7 , V_6 ) ;
}
return V_83 ;
}
static void F_30 ( struct V_2 * V_3 , struct V_17 * V_19 )
{
F_31 ( & V_3 -> V_96 -> V_97 , V_19 -> V_29 * V_19 -> V_26 ,
V_19 -> V_24 . V_25 , F_32 ( V_19 , V_98 ) ) ;
}
static int F_33 ( struct V_2 * V_3 , struct V_17 * V_19 , int V_29 ,
int V_26 )
{
T_3 * V_99 ;
V_99 = F_34 ( & V_3 -> V_96 -> V_97 , V_29 * V_26 ,
& V_19 -> V_100 , V_101 ) ;
if ( ! V_99 )
return - V_102 ;
F_35 ( V_19 ,
0 ,
V_29 ,
V_26 ,
V_99 ,
NULL ,
V_103 ) ;
F_36 ( V_19 , V_98 , V_19 -> V_100 ) ;
return 0 ;
}
int F_37 ( struct V_2 * V_3 , int V_104 ,
struct V_105 * V_106 , struct V_1 * V_5 )
{
struct V_107 V_108 ;
struct V_109 * V_110 ;
unsigned long V_111 ;
struct V_112 * V_113 ;
int V_79 ;
F_38 () ;
V_5 -> V_12 . V_114 = V_104 - 1 ;
V_5 -> V_115 = ! V_106 ;
V_5 -> V_19 . V_23 = F_39 ( V_3 , V_3 -> V_116 ,
& V_5 -> V_19 . V_117 , V_101 ) ;
if ( ! V_5 -> V_19 . V_23 )
return - V_102 ;
V_79 = F_33 ( V_3 , & V_5 -> V_19 , V_104 + 1 , V_118 ) ;
if ( V_79 )
goto V_119;
V_113 = F_40 ( V_3 ) ;
if ( ! V_113 ) {
V_79 = - V_102 ;
goto V_120;
}
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
F_41 ( & V_108 , V_121 ) ;
V_108 . V_51 . V_52 = ( unsigned long ) V_113 ;
V_108 . V_122 = V_3 -> V_123 ;
V_108 . V_26 = F_42 ( V_5 -> V_19 . V_26 ) ;
V_108 . V_124 = F_42 ( V_5 -> V_19 . V_29 ) ;
V_108 . V_125 = F_43 ( V_5 -> V_19 . V_117 ) ;
V_108 . V_24 = F_43 ( V_5 -> V_19 . V_100 ) ;
V_108 . V_126 = ( V_28 ) ( unsigned long ) ( V_5 ) ;
F_44 ( V_3 , V_113 ) ;
V_79 = F_45 ( V_3 , (union V_127 * ) & V_108 ) ;
if ( V_79 ) {
F_46 ( V_3 , V_113 ) ;
goto V_128;
}
V_79 = F_47 ( V_3 , V_113 ) ;
if ( V_79 )
goto V_128;
V_110 = (struct V_109 * ) ( unsigned long ) ( V_113 -> V_129 ) ;
if ( ! V_110 ) {
V_79 = - V_102 ;
goto V_128;
}
if ( ( V_79 = F_48 ( V_110 ) ) != 0 )
goto V_130;
V_5 -> V_123 = V_110 -> V_131 ;
V_5 -> V_19 . V_132 = F_21 ( V_110 -> V_11 ) ;
V_111 = V_3 -> V_133 + F_21 ( V_110 -> V_134 ) ;
V_5 -> V_19 . V_84 = F_49 ( V_111 , V_135 ) ;
if ( ! V_5 -> V_19 . V_84 ) {
V_79 = - V_102 ;
goto V_130;
}
F_50 ( V_3 , V_110 ) ;
F_51 ( V_3 , V_113 ) ;
F_52 ( & V_5 -> V_7 ) ;
F_53 ( & V_5 -> V_9 , 1 ) ;
F_54 ( & V_5 -> V_10 ) ;
V_5 -> V_4 = V_5 -> V_19 . V_132 ;
V_3 -> V_8 [ V_5 -> V_4 ] = V_5 ;
return 0 ;
V_130:
F_50 ( V_3 , V_110 ) ;
V_128:
F_51 ( V_3 , V_113 ) ;
V_120:
F_30 ( V_3 , & V_5 -> V_19 ) ;
V_119:
F_55 ( V_5 -> V_19 . V_23 ) ;
return V_79 ;
}
void F_56 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
int V_79 ;
struct V_112 * V_113 ;
struct V_136 V_108 ;
struct V_137 * V_110 ;
F_38 () ;
F_11 ( & V_3 -> V_7 ) ;
V_3 -> V_8 [ V_5 -> V_19 . V_132 ] = NULL ;
F_57 ( & V_5 -> V_9 ) ;
F_14 ( & V_3 -> V_7 ) ;
F_58 ( V_5 -> V_10 , ! F_59 ( & V_5 -> V_9 ) ) ;
V_113 = F_40 ( V_3 ) ;
if ( ! V_113 ) {
goto V_119;
}
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
F_41 ( & V_108 , V_138 ) ;
V_108 . V_51 . V_52 = ( unsigned long ) V_113 ;
V_108 . V_122 = V_3 -> V_123 ;
V_108 . V_131 = V_5 -> V_123 ;
F_44 ( V_3 , V_113 ) ;
V_79 = F_45 ( V_3 , (union V_127 * ) & V_108 ) ;
if ( V_79 ) {
F_46 ( V_3 , V_113 ) ;
goto V_120;
}
V_79 = F_47 ( V_3 , V_113 ) ;
if ( V_79 )
goto V_120;
V_110 = (struct V_137 * ) ( unsigned long ) ( V_113 -> V_129 ) ;
if ( V_110 )
F_50 ( V_3 , V_110 ) ;
V_120:
F_51 ( V_3 , V_113 ) ;
V_119:
if ( V_5 -> V_115 ) {
F_30 ( V_3 , & V_5 -> V_19 ) ;
}
return;
}
