static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
T_1 * V_6 = F_2 ( sizeof( T_1 ) , V_7 ) ;
T_2 V_8 = V_9 | V_10 | V_11 ;
if ( ! V_6 )
return - V_12 ;
V_5 = F_3 ( V_2 , F_4 ( V_2 , 0 ) ,
V_13 , V_8 ,
0x0000 ,
V_3 , V_6 , sizeof( T_1 ) , 5 * V_14 ) ;
* V_4 = F_5 ( * V_6 ) ;
F_6 ( V_6 ) ;
return V_5 ;
}
static inline int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_15 )
{
return F_3 ( V_2 ,
F_8 ( V_2 , 0 ) ,
V_16 ,
V_17 | V_10 | V_11 ,
V_15 ,
V_3 ,
NULL ,
0 ,
5 * V_14 ) ;
}
static void F_9 ( struct V_18 * V_19 , unsigned int V_20 )
{
struct V_21 * V_21 ;
struct V_22 * V_23 , * V_24 ;
unsigned long V_25 ;
F_10 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_11 (anchor, tmp, &mdev->anchor_list[channel],
list) {
struct V_27 * V_27 = V_23 -> V_27 ;
F_12 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
if ( F_13 ( V_27 ) ) {
V_21 = V_27 -> V_28 ;
if ( ! F_14 () ) {
F_15 ( V_27 ) ;
} else {
F_16 ( V_27 ) ;
F_17 ( & V_23 -> V_29 ) ;
}
if ( ( V_21 ) && ( V_21 -> V_30 ) ) {
V_21 -> V_31 = V_32 ;
V_21 -> V_33 = 0 ;
V_21 -> V_30 ( V_21 ) ;
}
F_18 ( V_27 ) ;
}
F_10 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_19 ( & V_23 -> V_34 ) ;
F_6 ( V_23 ) ;
}
F_12 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
}
static unsigned int F_20 ( struct V_35 * V_36 )
{
unsigned int V_37 = 0 ;
unsigned int V_38 = V_36 -> V_39 ;
if ( ! V_38 ) {
F_21 ( L_1 ) ;
return V_37 ;
}
switch ( V_36 -> V_40 ) {
case V_41 :
V_37 = V_42 * V_38 ;
break;
case V_43 :
if ( V_36 -> V_44 == 0 ) {
F_21 ( L_2 ) ;
V_37 = 0 ;
} else if ( V_36 -> V_44 == 0xFF ) {
V_37 = ( V_45 / V_38 ) * V_38 ;
} else {
V_37 = V_36 -> V_44 * V_38 ;
}
break;
default:
F_21 ( L_3 ) ;
break;
}
return V_37 ;
}
static int F_22 ( struct V_46 * V_47 , int V_20 )
{
struct V_18 * V_19 ;
V_19 = F_23 ( V_47 ) ;
if ( F_24 ( ! V_47 ) ) {
F_25 ( & V_19 -> V_1 -> V_2 , L_4 ) ;
return - V_48 ;
}
if ( F_24 ( ( V_20 < 0 ) || ( V_20 >= V_47 -> V_49 ) ) ) {
F_25 ( & V_19 -> V_1 -> V_2 , L_5 ) ;
return - V_50 ;
}
V_19 -> V_51 [ V_20 ] = false ;
F_26 ( & V_19 -> V_52 ) ;
F_9 ( V_19 , V_20 ) ;
if ( V_19 -> V_53 [ V_20 ] )
V_19 -> V_53 [ V_20 ] = false ;
if ( V_19 -> V_54 [ V_20 ] . V_40 == V_55 ) {
F_27 ( & V_19 -> V_56 ) ;
F_28 ( & V_19 -> V_57 ) ;
}
F_29 ( & V_19 -> V_52 ) ;
return 0 ;
}
static int F_30 ( struct V_18 * V_19 , int V_20 , struct V_21 * V_21 )
{
struct V_35 * V_54 = & V_19 -> V_54 [ V_20 ] ;
unsigned int V_58 , V_59 , V_37 ;
T_1 V_60 , V_61 ;
V_37 = F_20 ( V_54 ) ;
if ( ! V_37 )
return - V_48 ;
V_59 = V_21 -> V_62 / V_37 ;
if ( V_59 < 1 ) {
F_31 ( & V_19 -> V_1 -> V_2 ,
L_6 ) ;
return - V_48 ;
}
for ( V_58 = 1 ; V_58 < V_59 ; V_58 ++ ) {
V_61 = ( V_59 - V_58 ) * V_45 ;
V_60 = ( V_59 - V_58 ) * V_37 ;
memmove ( V_21 -> V_63 + V_61 ,
V_21 -> V_63 + V_60 ,
V_37 ) ;
}
V_21 -> V_62 = V_59 * V_45 ;
return 0 ;
}
static int F_32 ( struct V_18 * V_19 , int V_20 ,
struct V_21 * V_21 )
{
unsigned int V_58 , V_59 , V_37 ;
struct V_35 * const V_54 = & V_19 -> V_54 [ V_20 ] ;
V_37 = F_20 ( V_54 ) ;
if ( ! V_37 )
return - V_48 ;
V_59 = V_21 -> V_33 / V_45 ;
for ( V_58 = 1 ; V_58 < V_59 ; V_58 ++ )
memmove ( V_21 -> V_63 + V_37 * V_58 ,
V_21 -> V_63 + V_45 * V_58 ,
V_37 ) ;
V_21 -> V_33 = V_37 * V_59 ;
return 0 ;
}
static void F_33 ( struct V_27 * V_27 )
{
struct V_21 * V_21 ;
struct V_22 * V_23 ;
struct V_18 * V_19 ;
struct V_64 * V_2 ;
unsigned int V_20 ;
unsigned long V_25 ;
V_21 = V_27 -> V_28 ;
V_23 = V_21 -> V_65 ;
V_19 = F_23 ( V_21 -> V_66 ) ;
V_20 = V_21 -> V_67 ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( ( V_27 -> V_31 == - V_68 ) || ( V_27 -> V_31 == - V_69 ) ||
( ! V_19 -> V_51 [ V_20 ] ) ) {
V_30 ( & V_23 -> V_29 ) ;
return;
}
if ( F_24 ( V_27 -> V_31 && ! ( V_27 -> V_31 == - V_68 ||
V_27 -> V_31 == - V_69 ||
V_27 -> V_31 == - V_70 ) ) ) {
V_21 -> V_33 = 0 ;
switch ( V_27 -> V_31 ) {
case - V_71 :
F_25 ( V_2 , L_7 ) ;
F_34 ( & V_19 -> V_47 , V_20 ) ;
V_21 -> V_31 = V_72 ;
F_16 ( V_27 ) ;
F_35 ( & V_23 -> V_73 , V_74 ) ;
F_36 ( V_75 , & V_23 -> V_73 ) ;
return;
case - V_76 :
case - V_77 :
V_21 -> V_31 = V_32 ;
break;
default:
V_21 -> V_31 = V_72 ;
break;
}
} else {
V_21 -> V_31 = V_78 ;
V_21 -> V_33 = V_27 -> V_79 ;
}
F_10 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_19 ( & V_23 -> V_34 ) ;
F_12 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_6 ( V_23 ) ;
if ( F_13 ( V_21 -> V_30 ) )
V_21 -> V_30 ( V_21 ) ;
F_18 ( V_27 ) ;
}
static void F_37 ( struct V_27 * V_27 )
{
struct V_21 * V_21 ;
struct V_22 * V_23 ;
struct V_18 * V_19 ;
struct V_64 * V_2 ;
unsigned long V_25 ;
unsigned int V_20 ;
V_21 = V_27 -> V_28 ;
V_23 = V_21 -> V_65 ;
V_19 = F_23 ( V_21 -> V_66 ) ;
V_20 = V_21 -> V_67 ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( ( V_27 -> V_31 == - V_68 ) || ( V_27 -> V_31 == - V_69 ) ||
( ! V_19 -> V_51 [ V_20 ] ) ) {
V_30 ( & V_23 -> V_29 ) ;
return;
}
if ( F_24 ( V_27 -> V_31 && ! ( V_27 -> V_31 == - V_68 ||
V_27 -> V_31 == - V_69 ||
V_27 -> V_31 == - V_70 ) ) ) {
V_21 -> V_33 = 0 ;
switch ( V_27 -> V_31 ) {
case - V_71 :
F_25 ( V_2 , L_8 ) ;
V_21 -> V_31 = V_72 ;
F_16 ( V_27 ) ;
F_35 ( & V_23 -> V_73 , V_74 ) ;
F_36 ( V_75 , & V_23 -> V_73 ) ;
return;
case - V_76 :
case - V_77 :
V_21 -> V_31 = V_32 ;
break;
case - V_80 :
F_25 ( V_2 , L_9 ) ;
default:
V_21 -> V_31 = V_72 ;
break;
}
} else {
V_21 -> V_33 = V_27 -> V_79 ;
if ( ! V_19 -> V_53 [ V_20 ] ) {
V_21 -> V_31 = V_78 ;
} else {
if ( F_32 ( V_19 , V_20 , V_21 ) ) {
V_21 -> V_33 = 0 ;
V_21 -> V_31 = V_72 ;
} else {
V_21 -> V_31 = V_78 ;
}
}
}
F_10 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_19 ( & V_23 -> V_34 ) ;
F_12 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_6 ( V_23 ) ;
if ( F_13 ( V_21 -> V_30 ) )
V_21 -> V_30 ( V_21 ) ;
F_18 ( V_27 ) ;
}
static int F_38 ( struct V_46 * V_47 , int V_20 ,
struct V_21 * V_21 )
{
struct V_18 * V_19 ;
struct V_22 * V_23 ;
struct V_35 * V_54 ;
struct V_64 * V_2 ;
int V_5 = 0 ;
struct V_27 * V_27 ;
unsigned long V_25 ;
unsigned long V_81 ;
void * V_63 ;
if ( F_24 ( ! V_47 || ! V_21 ) )
return - V_48 ;
if ( F_24 ( V_47 -> V_49 <= V_20 ) || ( V_20 < 0 ) )
return - V_50 ;
V_19 = F_23 ( V_47 ) ;
V_54 = & V_19 -> V_54 [ V_20 ] ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( ! V_19 -> V_1 )
return - V_76 ;
V_27 = F_39 ( V_82 , V_83 ) ;
if ( ! V_27 ) {
F_31 ( V_2 , L_10 ) ;
return - V_12 ;
}
V_23 = F_2 ( sizeof( * V_23 ) , V_83 ) ;
if ( ! V_23 ) {
V_5 = - V_12 ;
goto V_84;
}
V_23 -> V_27 = V_27 ;
F_40 ( & V_23 -> V_29 ) ;
V_21 -> V_65 = V_23 ;
F_10 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_41 ( & V_23 -> V_34 , & V_19 -> V_85 [ V_20 ] ) ;
F_12 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
if ( ( V_19 -> V_53 [ V_20 ] ) &&
( V_54 -> V_86 & V_87 ) )
if ( F_30 ( V_19 , V_20 , V_21 ) ) {
V_5 = - V_48 ;
goto V_88;
}
V_27 -> V_89 = V_21 -> V_90 ;
V_63 = V_21 -> V_63 ;
V_81 = V_21 -> V_62 ;
if ( V_54 -> V_86 & V_87 ) {
F_42 ( V_27 , V_19 -> V_1 ,
F_43 ( V_19 -> V_1 ,
V_19 -> V_91 [ V_20 ] ) ,
V_63 ,
V_81 ,
F_33 ,
V_21 ) ;
if ( V_54 -> V_40 != V_41 )
V_27 -> V_92 |= V_93 ;
} else {
F_42 ( V_27 , V_19 -> V_1 ,
F_44 ( V_19 -> V_1 ,
V_19 -> V_91 [ V_20 ] ) ,
V_63 ,
V_81 + V_54 -> V_94 ,
F_37 ,
V_21 ) ;
}
V_27 -> V_92 |= V_95 ;
V_5 = F_45 ( V_27 , V_7 ) ;
if ( V_5 ) {
F_31 ( V_2 , L_11 , V_5 ) ;
goto V_88;
}
return 0 ;
V_88:
F_10 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_19 ( & V_23 -> V_34 ) ;
F_12 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_6 ( V_23 ) ;
V_84:
F_18 ( V_27 ) ;
return V_5 ;
}
static int F_46 ( struct V_46 * V_47 , int V_20 ,
struct V_35 * V_54 )
{
unsigned int V_59 ;
unsigned int V_37 ;
unsigned int V_96 ;
unsigned int V_97 ;
struct V_18 * V_19 ;
struct V_64 * V_2 ;
V_19 = F_23 ( V_47 ) ;
V_19 -> V_51 [ V_20 ] = true ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( F_24 ( ! V_47 || ! V_54 ) ) {
F_31 ( V_2 , L_12 ) ;
return - V_98 ;
}
if ( F_24 ( ( V_20 < 0 ) || ( V_20 >= V_47 -> V_49 ) ) ) {
F_31 ( V_2 , L_5 ) ;
return - V_98 ;
}
if ( ( ! V_54 -> V_99 ) || ( ! V_54 -> V_100 ) ) {
F_31 ( V_2 , L_13 ) ;
return - V_98 ;
}
if ( ! ( V_54 -> V_40 == V_43 ) &&
! ( ( V_54 -> V_40 == V_41 ) &&
( V_54 -> V_44 != 0xFF ) ) ) {
V_19 -> V_53 [ V_20 ] = false ;
goto exit;
}
V_19 -> V_53 [ V_20 ] = true ;
V_96 = V_54 -> V_100 ;
V_37 = F_20 ( V_54 ) ;
if ( ( V_37 == 0 ) || ( V_37 > V_45 ) ) {
F_25 ( V_2 , L_14 ) ;
return - V_98 ;
}
if ( V_54 -> V_100 % V_37 ) {
T_1 V_101 ;
V_101 = V_54 -> V_100 / V_37 ;
V_54 -> V_100 = V_101 * V_37 ;
F_47 ( V_2 ,
L_15 ,
V_20 ,
V_54 -> V_100 ,
V_96 ) ;
}
V_59 = V_54 -> V_100 / V_37 ;
V_97 = V_59 * ( V_45 - V_37 ) ;
V_96 += V_97 ;
V_54 -> V_94 = ( F_48 ( V_96 , V_45 ) * V_45 )
- V_54 -> V_100 ;
exit:
V_19 -> V_54 [ V_20 ] = * V_54 ;
return 0 ;
}
static int F_49 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_19 -> V_1 ;
struct V_64 * V_2 = & V_1 -> V_2 ;
T_1 V_102 , V_103 , V_104 , V_105 ;
if ( ! F_50 ( V_19 -> V_106 ) ) {
if ( F_1 ( V_1 , V_107 , & V_102 ) < 0 ) {
F_31 ( V_2 , L_16 ) ;
return - 1 ;
}
if ( F_1 ( V_1 , V_108 , & V_103 ) < 0 ) {
F_31 ( V_2 , L_17 ) ;
return - 1 ;
}
if ( F_1 ( V_1 , V_109 , & V_104 ) < 0 ) {
F_31 ( V_2 , L_18 ) ;
return - 1 ;
}
F_26 ( & V_19 -> V_52 ) ;
V_19 -> V_106 [ 0 ] = V_102 >> 8 ;
V_19 -> V_106 [ 1 ] = V_102 ;
V_19 -> V_106 [ 2 ] = V_103 >> 8 ;
V_19 -> V_106 [ 3 ] = V_103 ;
V_19 -> V_106 [ 4 ] = V_104 >> 8 ;
V_19 -> V_106 [ 5 ] = V_104 ;
F_29 ( & V_19 -> V_52 ) ;
}
if ( F_1 ( V_1 , V_110 , & V_105 ) < 0 ) {
F_31 ( V_2 , L_19 ) ;
return - 1 ;
}
F_26 ( & V_19 -> V_52 ) ;
V_19 -> V_111 = V_105 ;
F_29 ( & V_19 -> V_52 ) ;
return 0 ;
}
static void F_51 ( struct V_46 * V_47 , int V_20 )
{
struct V_18 * V_19 ;
F_52 ( ! V_47 ) ;
V_19 = F_23 ( V_47 ) ;
V_19 -> V_56 . V_112 = V_113 + V_14 ;
F_53 ( & V_19 -> V_56 , V_19 -> V_56 . V_112 ) ;
}
static void F_54 ( unsigned long V_15 )
{
struct V_18 * V_19 = (struct V_18 * ) V_15 ;
F_36 ( V_75 , & V_19 -> V_57 ) ;
V_19 -> V_56 . V_112 = V_113 + ( 2 * V_14 ) ;
F_55 ( & V_19 -> V_56 ) ;
}
static void F_56 ( struct V_114 * V_115 )
{
struct V_18 * V_19 ;
int V_116 , V_117 ;
T_2 V_118 [ 6 ] ;
V_19 = F_57 ( V_115 ) ;
V_117 = V_19 -> V_111 ;
for ( V_116 = 0 ; V_116 < 6 ; V_116 ++ )
V_118 [ V_116 ] = V_19 -> V_106 [ V_116 ] ;
if ( F_49 ( V_19 ) < 0 )
return;
if ( ( V_117 != V_19 -> V_111 ) ||
( V_118 [ 0 ] != V_19 -> V_106 [ 0 ] ) ||
( V_118 [ 1 ] != V_19 -> V_106 [ 1 ] ) ||
( V_118 [ 2 ] != V_19 -> V_106 [ 2 ] ) ||
( V_118 [ 3 ] != V_19 -> V_106 [ 3 ] ) ||
( V_118 [ 4 ] != V_19 -> V_106 [ 4 ] ) ||
( V_118 [ 5 ] != V_19 -> V_106 [ 5 ] ) )
F_58 ( & V_19 -> V_47 , V_19 -> V_111 ,
& V_19 -> V_106 [ 0 ] ) ;
}
static void V_74 ( struct V_114 * V_115 )
{
struct V_22 * V_23 ;
struct V_18 * V_19 ;
struct V_21 * V_21 ;
struct V_27 * V_27 ;
unsigned int V_20 ;
unsigned long V_25 ;
V_23 = F_59 ( V_115 ) ;
V_27 = V_23 -> V_27 ;
V_21 = V_27 -> V_28 ;
V_19 = F_23 ( V_21 -> V_66 ) ;
V_20 = V_21 -> V_67 ;
if ( F_60 ( V_27 -> V_2 , V_27 -> V_119 ) )
F_25 ( & V_19 -> V_1 -> V_2 , L_20 ) ;
F_18 ( V_27 ) ;
F_10 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_19 ( & V_23 -> V_34 ) ;
F_12 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
if ( F_13 ( V_21 -> V_30 ) )
V_21 -> V_30 ( V_21 ) ;
if ( V_19 -> V_54 [ V_20 ] . V_86 & V_87 )
F_61 ( & V_19 -> V_47 , V_20 ) ;
F_6 ( V_23 ) ;
}
static T_3 F_62 ( struct V_120 * V_121 , struct V_122 * V_123 ,
char * V_4 )
{
struct V_124 * V_125 = F_63 ( V_123 ) ;
struct V_126 * V_127 = F_64 ( V_121 ) ;
if ( ! V_125 -> V_128 )
return - V_48 ;
return V_125 -> V_128 ( V_127 , V_125 , V_4 ) ;
}
static T_3 F_65 ( struct V_120 * V_121 ,
struct V_122 * V_123 ,
const char * V_4 ,
T_4 V_129 )
{
struct V_124 * V_125 = F_63 ( V_123 ) ;
struct V_126 * V_127 = F_64 ( V_121 ) ;
if ( ! V_125 -> V_130 )
return - V_48 ;
return V_125 -> V_130 ( V_127 , V_125 , V_4 , V_129 ) ;
}
static void F_66 ( struct V_120 * V_121 )
{
struct V_126 * V_127 = F_64 ( V_121 ) ;
F_6 ( V_127 ) ;
}
static T_3 F_67 ( struct V_126 * V_127 ,
struct V_124 * V_123 , char * V_4 )
{
T_1 V_101 ;
T_1 V_131 ;
int V_132 ;
if ( ! strcmp ( V_123 -> V_123 . V_133 , L_21 ) )
V_131 = V_110 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_22 ) )
V_131 = V_134 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_23 ) )
V_131 = V_135 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_24 ) )
V_131 = V_136 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_25 ) )
V_131 = V_137 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_26 ) )
V_131 = V_138 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_27 ) )
V_131 = V_139 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_28 ) )
V_131 = V_140 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_29 ) )
V_131 = V_141 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_30 ) )
V_131 = V_107 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_31 ) )
V_131 = V_108 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_32 ) )
V_131 = V_109 ;
else
return - V_48 ;
V_132 = F_1 ( V_127 -> V_1 , V_131 , & V_101 ) ;
if ( V_132 < 0 )
return V_132 ;
return snprintf ( V_4 , V_142 , L_33 , V_101 ) ;
}
static T_3 F_68 ( struct V_126 * V_127 ,
struct V_124 * V_123 ,
const char * V_4 , T_4 V_143 )
{
T_1 V_144 ;
T_1 V_131 ;
int V_132 ;
if ( ! strcmp ( V_123 -> V_123 . V_133 , L_25 ) )
V_131 = V_137 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_26 ) )
V_131 = V_138 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_27 ) )
V_131 = V_139 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_28 ) )
V_131 = V_140 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_29 ) )
V_131 = V_141 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_30 ) )
V_131 = V_107 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_31 ) )
V_131 = V_108 ;
else if ( ! strcmp ( V_123 -> V_123 . V_133 , L_32 ) )
V_131 = V_109 ;
else
return - V_48 ;
V_132 = F_69 ( V_4 , 16 , & V_144 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_7 ( V_127 -> V_1 , V_131 , V_144 ) ;
if ( V_132 < 0 )
return V_132 ;
return V_143 ;
}
static struct
V_126 * F_70 ( struct V_120 * V_145 )
{
struct V_126 * V_146 ;
int V_5 ;
V_146 = F_2 ( sizeof( * V_146 ) , V_7 ) ;
if ( ! V_146 )
return NULL ;
V_5 = F_71 ( & V_146 -> V_121 , & V_147 , V_145 ,
L_34 ) ;
if ( V_5 ) {
F_72 ( & V_146 -> V_121 ) ;
return NULL ;
}
return V_146 ;
}
static void F_73 ( struct V_126 * V_148 )
{
F_72 ( & V_148 -> V_121 ) ;
}
static int
F_74 ( struct V_149 * V_150 , const struct V_151 * V_152 )
{
unsigned int V_116 ;
unsigned int V_153 ;
struct V_154 * V_155 ;
struct V_18 * V_19 ;
struct V_1 * V_156 ;
struct V_64 * V_2 ;
struct V_157 * V_158 ;
struct V_159 * V_160 ;
int V_161 = 0 ;
int V_132 ;
V_158 = V_150 -> V_162 ;
V_156 = F_75 ( V_150 ) ;
V_2 = & V_156 -> V_2 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_7 ) ;
if ( ! V_19 )
goto V_163;
F_76 ( V_150 , V_19 ) ;
V_153 = V_158 -> V_164 . V_165 ;
F_77 ( & V_19 -> V_52 ) ;
F_35 ( & V_19 -> V_57 , F_56 ) ;
F_78 ( & V_19 -> V_56 , F_54 ,
( unsigned long ) V_19 ) ;
V_19 -> V_1 = V_156 ;
V_19 -> V_56 . V_112 = V_113 + ( 2 * V_14 ) ;
V_19 -> V_47 . V_166 = V_167 . V_168 ;
V_19 -> V_47 . V_150 = V_169 ;
V_19 -> V_47 . V_170 = F_46 ;
V_19 -> V_47 . V_171 = F_51 ;
V_19 -> V_47 . V_172 = F_38 ;
V_19 -> V_47 . V_173 = F_22 ;
V_19 -> V_47 . V_174 = V_19 -> V_174 ;
V_19 -> V_47 . V_49 = V_153 ;
snprintf ( V_19 -> V_174 , sizeof( V_19 -> V_174 ) ,
L_35 ,
V_156 -> V_175 -> V_176 ,
V_156 -> V_177 ,
V_156 -> V_178 -> V_164 . V_179 ,
V_158 -> V_164 . V_180 ) ;
V_19 -> V_54 = F_79 ( V_153 , sizeof( * V_19 -> V_54 ) , V_7 ) ;
if ( ! V_19 -> V_54 )
goto V_181;
V_19 -> V_182 = F_79 ( V_153 , sizeof( * V_19 -> V_182 ) , V_7 ) ;
if ( ! V_19 -> V_182 )
goto V_183;
V_19 -> V_47 . V_184 = V_19 -> V_182 ;
V_19 -> V_47 . V_65 = NULL ;
V_19 -> V_91 =
F_79 ( V_153 , sizeof( * V_19 -> V_91 ) , V_7 ) ;
if ( ! V_19 -> V_91 )
goto V_185;
V_19 -> V_85 =
F_79 ( V_153 , sizeof( * V_19 -> V_85 ) , V_7 ) ;
if ( ! V_19 -> V_85 )
goto V_186;
V_155 = V_19 -> V_182 ;
for ( V_116 = 0 ; V_116 < V_153 ; V_116 ++ ) {
V_160 = & V_158 -> V_187 [ V_116 ] . V_164 ;
V_19 -> V_91 [ V_116 ] = V_160 -> V_188 ;
V_19 -> V_53 [ V_116 ] = false ;
V_19 -> V_51 [ V_116 ] = true ;
snprintf ( & V_19 -> V_189 [ V_116 ] [ 0 ] , V_190 , L_36 ,
V_19 -> V_91 [ V_116 ] ) ;
V_155 -> V_191 = & V_19 -> V_189 [ V_116 ] [ 0 ] ;
V_155 -> V_192 = V_193 ;
V_155 -> V_194 = V_193 ;
V_155 -> V_195 = V_196 ;
V_155 -> V_197 = V_196 ;
V_155 -> V_40 = V_198 | V_55 |
V_41 | V_43 ;
if ( V_160 -> V_188 & V_9 )
V_155 -> V_86 = V_199 ;
else
V_155 -> V_86 = V_87 ;
V_155 ++ ;
F_80 ( & V_19 -> V_85 [ V_116 ] ) ;
F_81 ( & V_19 -> V_26 [ V_116 ] ) ;
V_132 = F_7 ( V_156 ,
V_200 + V_201 +
V_160 -> V_188 * 16 ,
1 ) ;
if ( V_132 < 0 )
F_21 ( L_37 ,
V_160 -> V_188 ) ;
}
F_47 ( V_2 , L_38 ,
F_5 ( V_156 -> V_202 . V_203 ) ,
F_5 ( V_156 -> V_202 . V_204 ) ,
V_156 -> V_175 -> V_176 ,
V_156 -> V_205 ) ;
F_47 ( V_2 , L_39 ,
V_156 -> V_175 -> V_176 ,
V_156 -> V_177 ,
V_156 -> V_178 -> V_164 . V_179 ,
V_158 -> V_164 . V_180 ) ;
V_19 -> V_145 = F_82 ( & V_19 -> V_47 ) ;
if ( F_83 ( V_19 -> V_145 ) ) {
V_161 = F_84 ( V_19 -> V_145 ) ;
goto V_206;
}
F_26 ( & V_19 -> V_52 ) ;
if ( F_5 ( V_156 -> V_202 . V_204 ) == V_207 ) {
V_19 -> V_208 = F_70 ( V_19 -> V_145 ) ;
if ( ! V_19 -> V_208 ) {
F_29 ( & V_19 -> V_52 ) ;
F_85 ( & V_19 -> V_47 ) ;
V_161 = - V_12 ;
goto V_206;
}
F_86 ( & V_19 -> V_208 -> V_121 , V_209 ) ;
V_19 -> V_208 -> V_1 = V_19 -> V_1 ;
}
F_29 ( & V_19 -> V_52 ) ;
return 0 ;
V_206:
F_6 ( V_19 -> V_85 ) ;
V_186:
F_6 ( V_19 -> V_91 ) ;
V_185:
F_6 ( V_19 -> V_182 ) ;
V_183:
F_6 ( V_19 -> V_54 ) ;
V_181:
F_6 ( V_19 ) ;
V_163:
if ( V_161 == 0 || V_161 == - V_12 ) {
V_161 = - V_12 ;
F_31 ( V_2 , L_40 ) ;
}
return V_161 ;
}
static void F_87 ( struct V_149 * V_150 )
{
struct V_18 * V_19 ;
V_19 = F_88 ( V_150 ) ;
F_26 ( & V_19 -> V_52 ) ;
F_76 ( V_150 , NULL ) ;
V_19 -> V_1 = NULL ;
F_29 ( & V_19 -> V_52 ) ;
F_27 ( & V_19 -> V_56 ) ;
F_28 ( & V_19 -> V_57 ) ;
F_73 ( V_19 -> V_208 ) ;
F_85 ( & V_19 -> V_47 ) ;
F_6 ( V_19 -> V_85 ) ;
F_6 ( V_19 -> V_182 ) ;
F_6 ( V_19 -> V_54 ) ;
F_6 ( V_19 -> V_91 ) ;
F_6 ( V_19 ) ;
}
static int T_5 F_89 ( void )
{
F_90 ( L_41 ) ;
if ( F_91 ( & V_210 ) ) {
F_92 ( L_42 ) ;
return - V_48 ;
}
V_75 = F_93 ( L_43 ) ;
if ( ! V_75 ) {
F_92 ( L_44 ) ;
F_94 ( & V_210 ) ;
return - V_12 ;
}
return 0 ;
}
static void T_6 F_95 ( void )
{
F_90 ( L_45 ) ;
F_96 ( V_75 ) ;
F_94 ( & V_210 ) ;
}
