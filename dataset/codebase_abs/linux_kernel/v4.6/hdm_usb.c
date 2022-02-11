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
F_20 ( & V_23 -> V_35 ) ;
F_6 ( V_23 ) ;
}
F_12 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
}
static unsigned int F_21 ( struct V_36 * V_37 )
{
unsigned int V_38 = 0 ;
unsigned int V_39 = V_37 -> V_40 ;
if ( ! V_39 ) {
F_22 ( L_1 ) ;
return V_38 ;
}
switch ( V_37 -> V_41 ) {
case V_42 :
V_38 = V_43 * V_39 ;
break;
case V_44 :
if ( V_37 -> V_45 == 0 ) {
F_22 ( L_2 ) ;
V_38 = 0 ;
} else if ( V_37 -> V_45 == 0xFF ) {
V_38 = ( V_46 / V_39 ) * V_39 ;
} else {
V_38 = V_37 -> V_45 * V_39 ;
}
break;
default:
F_22 ( L_3 ) ;
break;
}
return V_38 ;
}
static int F_23 ( struct V_47 * V_48 , int V_20 )
{
struct V_18 * V_19 ;
V_19 = F_24 ( V_48 ) ;
if ( F_25 ( ! V_48 ) ) {
F_26 ( & V_19 -> V_1 -> V_2 , L_4 ) ;
return - V_49 ;
}
if ( F_25 ( ( V_20 < 0 ) || ( V_20 >= V_48 -> V_50 ) ) ) {
F_26 ( & V_19 -> V_1 -> V_2 , L_5 ) ;
return - V_51 ;
}
V_19 -> V_52 [ V_20 ] = false ;
F_27 ( & V_19 -> V_53 ) ;
F_9 ( V_19 , V_20 ) ;
if ( V_19 -> V_54 [ V_20 ] )
V_19 -> V_54 [ V_20 ] = false ;
if ( V_19 -> V_55 [ V_20 ] . V_41 == V_56 ) {
F_28 ( & V_19 -> V_57 ) ;
F_20 ( & V_19 -> V_58 ) ;
}
F_29 ( & V_19 -> V_53 ) ;
return 0 ;
}
static int F_30 ( struct V_18 * V_19 , int V_20 , struct V_21 * V_21 )
{
struct V_36 * V_55 = & V_19 -> V_55 [ V_20 ] ;
unsigned int V_59 , V_60 , V_38 ;
T_1 V_61 , V_62 ;
V_38 = F_21 ( V_55 ) ;
if ( ! V_38 )
return - V_49 ;
V_60 = V_21 -> V_63 / V_38 ;
if ( V_60 < 1 ) {
F_31 ( & V_19 -> V_1 -> V_2 ,
L_6 ) ;
return - V_49 ;
}
for ( V_59 = 1 ; V_59 < V_60 ; V_59 ++ ) {
V_62 = ( V_60 - V_59 ) * V_46 ;
V_61 = ( V_60 - V_59 ) * V_38 ;
memmove ( V_21 -> V_64 + V_62 ,
V_21 -> V_64 + V_61 ,
V_38 ) ;
}
V_21 -> V_63 = V_60 * V_46 ;
return 0 ;
}
static int F_32 ( struct V_18 * V_19 , int V_20 ,
struct V_21 * V_21 )
{
unsigned int V_59 , V_60 , V_38 ;
struct V_36 * const V_55 = & V_19 -> V_55 [ V_20 ] ;
V_38 = F_21 ( V_55 ) ;
if ( ! V_38 )
return - V_49 ;
V_60 = V_21 -> V_33 / V_46 ;
for ( V_59 = 1 ; V_59 < V_60 ; V_59 ++ )
memmove ( V_21 -> V_64 + V_38 * V_59 ,
V_21 -> V_64 + V_46 * V_59 ,
V_38 ) ;
V_21 -> V_33 = V_38 * V_60 ;
return 0 ;
}
static void F_33 ( struct V_27 * V_27 )
{
struct V_21 * V_21 ;
struct V_22 * V_23 ;
struct V_18 * V_19 ;
struct V_65 * V_2 ;
unsigned int V_20 ;
unsigned long V_25 ;
V_21 = V_27 -> V_28 ;
V_23 = V_21 -> V_66 ;
V_19 = F_24 ( V_21 -> V_67 ) ;
V_20 = V_21 -> V_68 ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( ( V_27 -> V_31 == - V_69 ) || ( V_27 -> V_31 == - V_70 ) ||
( ! V_19 -> V_52 [ V_20 ] ) ) {
V_30 ( & V_23 -> V_29 ) ;
return;
}
if ( F_25 ( V_27 -> V_31 && ! ( V_27 -> V_31 == - V_69 ||
V_27 -> V_31 == - V_70 ||
V_27 -> V_31 == - V_71 ) ) ) {
V_21 -> V_33 = 0 ;
switch ( V_27 -> V_31 ) {
case - V_72 :
F_26 ( V_2 , L_7 ) ;
F_34 ( & V_19 -> V_48 , V_20 ) ;
V_21 -> V_31 = V_73 ;
F_16 ( V_27 ) ;
F_35 ( & V_23 -> V_35 , V_74 ) ;
F_36 ( & V_23 -> V_35 ) ;
return;
case - V_75 :
case - V_76 :
V_21 -> V_31 = V_32 ;
break;
default:
V_21 -> V_31 = V_73 ;
break;
}
} else {
V_21 -> V_31 = V_77 ;
V_21 -> V_33 = V_27 -> V_78 ;
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
struct V_65 * V_2 ;
unsigned long V_25 ;
unsigned int V_20 ;
V_21 = V_27 -> V_28 ;
V_23 = V_21 -> V_66 ;
V_19 = F_24 ( V_21 -> V_67 ) ;
V_20 = V_21 -> V_68 ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( ( V_27 -> V_31 == - V_69 ) || ( V_27 -> V_31 == - V_70 ) ||
( ! V_19 -> V_52 [ V_20 ] ) ) {
V_30 ( & V_23 -> V_29 ) ;
return;
}
if ( F_25 ( V_27 -> V_31 && ! ( V_27 -> V_31 == - V_69 ||
V_27 -> V_31 == - V_70 ||
V_27 -> V_31 == - V_71 ) ) ) {
V_21 -> V_33 = 0 ;
switch ( V_27 -> V_31 ) {
case - V_72 :
F_26 ( V_2 , L_8 ) ;
V_21 -> V_31 = V_73 ;
F_16 ( V_27 ) ;
F_35 ( & V_23 -> V_35 , V_74 ) ;
F_36 ( & V_23 -> V_35 ) ;
return;
case - V_75 :
case - V_76 :
V_21 -> V_31 = V_32 ;
break;
case - V_79 :
F_26 ( V_2 , L_9 ) ;
default:
V_21 -> V_31 = V_73 ;
break;
}
} else {
V_21 -> V_33 = V_27 -> V_78 ;
if ( ! V_19 -> V_54 [ V_20 ] ) {
V_21 -> V_31 = V_77 ;
} else {
if ( F_32 ( V_19 , V_20 , V_21 ) ) {
V_21 -> V_33 = 0 ;
V_21 -> V_31 = V_73 ;
} else {
V_21 -> V_31 = V_77 ;
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
static int F_38 ( struct V_47 * V_48 , int V_20 ,
struct V_21 * V_21 )
{
struct V_18 * V_19 ;
struct V_22 * V_23 ;
struct V_36 * V_55 ;
struct V_65 * V_2 ;
int V_5 = 0 ;
struct V_27 * V_27 ;
unsigned long V_25 ;
unsigned long V_80 ;
void * V_64 ;
if ( F_25 ( ! V_48 || ! V_21 ) )
return - V_49 ;
if ( F_25 ( V_48 -> V_50 <= V_20 ) || ( V_20 < 0 ) )
return - V_51 ;
V_19 = F_24 ( V_48 ) ;
V_55 = & V_19 -> V_55 [ V_20 ] ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( ! V_19 -> V_1 )
return - V_75 ;
V_27 = F_39 ( V_81 , V_82 ) ;
if ( ! V_27 ) {
F_31 ( V_2 , L_10 ) ;
return - V_12 ;
}
V_23 = F_2 ( sizeof( * V_23 ) , V_82 ) ;
if ( ! V_23 ) {
V_5 = - V_12 ;
goto V_83;
}
V_23 -> V_27 = V_27 ;
F_40 ( & V_23 -> V_29 ) ;
V_21 -> V_66 = V_23 ;
F_10 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_41 ( & V_23 -> V_34 , & V_19 -> V_84 [ V_20 ] ) ;
F_12 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
if ( ( V_19 -> V_54 [ V_20 ] ) &&
( V_55 -> V_85 & V_86 ) )
if ( F_30 ( V_19 , V_20 , V_21 ) ) {
V_5 = - V_49 ;
goto V_87;
}
V_27 -> V_88 = V_21 -> V_89 ;
V_64 = V_21 -> V_64 ;
V_80 = V_21 -> V_63 ;
if ( V_55 -> V_85 & V_86 ) {
F_42 ( V_27 , V_19 -> V_1 ,
F_43 ( V_19 -> V_1 ,
V_19 -> V_90 [ V_20 ] ) ,
V_64 ,
V_80 ,
F_33 ,
V_21 ) ;
if ( V_55 -> V_41 != V_42 )
V_27 -> V_91 |= V_92 ;
} else {
F_42 ( V_27 , V_19 -> V_1 ,
F_44 ( V_19 -> V_1 ,
V_19 -> V_90 [ V_20 ] ) ,
V_64 ,
V_80 + V_55 -> V_93 ,
F_37 ,
V_21 ) ;
}
V_27 -> V_91 |= V_94 ;
V_5 = F_45 ( V_27 , V_7 ) ;
if ( V_5 ) {
F_31 ( V_2 , L_11 , V_5 ) ;
goto V_87;
}
return 0 ;
V_87:
F_10 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_19 ( & V_23 -> V_34 ) ;
F_12 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_6 ( V_23 ) ;
V_83:
F_18 ( V_27 ) ;
return V_5 ;
}
static int F_46 ( struct V_47 * V_48 , int V_20 ,
struct V_36 * V_55 )
{
unsigned int V_60 ;
unsigned int V_38 ;
unsigned int V_95 ;
unsigned int V_96 ;
struct V_18 * V_19 ;
struct V_65 * V_2 ;
V_19 = F_24 ( V_48 ) ;
V_19 -> V_52 [ V_20 ] = true ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( F_25 ( ! V_48 || ! V_55 ) ) {
F_31 ( V_2 , L_12 ) ;
return - V_97 ;
}
if ( F_25 ( ( V_20 < 0 ) || ( V_20 >= V_48 -> V_50 ) ) ) {
F_31 ( V_2 , L_5 ) ;
return - V_97 ;
}
if ( ( ! V_55 -> V_98 ) || ( ! V_55 -> V_99 ) ) {
F_31 ( V_2 , L_13 ) ;
return - V_97 ;
}
if ( ! ( V_55 -> V_41 == V_44 ) &&
! ( ( V_55 -> V_41 == V_42 ) &&
( V_55 -> V_45 != 0xFF ) ) ) {
V_19 -> V_54 [ V_20 ] = false ;
goto exit;
}
V_19 -> V_54 [ V_20 ] = true ;
V_95 = V_55 -> V_99 ;
V_38 = F_21 ( V_55 ) ;
if ( ( V_38 == 0 ) || ( V_38 > V_46 ) ) {
F_26 ( V_2 , L_14 ) ;
return - V_97 ;
}
if ( V_55 -> V_99 % V_38 ) {
T_1 V_100 ;
V_100 = V_55 -> V_99 / V_38 ;
V_55 -> V_99 = V_100 * V_38 ;
F_47 ( V_2 ,
L_15 ,
V_20 ,
V_55 -> V_99 ,
V_95 ) ;
}
V_60 = V_55 -> V_99 / V_38 ;
V_96 = V_60 * ( V_46 - V_38 ) ;
V_95 += V_96 ;
V_55 -> V_93 = ( F_48 ( V_95 , V_46 ) * V_46 )
- V_55 -> V_99 ;
exit:
V_19 -> V_55 [ V_20 ] = * V_55 ;
return 0 ;
}
static int F_49 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = V_19 -> V_1 ;
struct V_65 * V_2 = & V_1 -> V_2 ;
T_1 V_101 , V_102 , V_103 , V_104 ;
if ( ! F_50 ( V_19 -> V_105 ) ) {
if ( F_1 ( V_1 , V_106 , & V_101 ) < 0 ) {
F_31 ( V_2 , L_16 ) ;
return - 1 ;
}
if ( F_1 ( V_1 , V_107 , & V_102 ) < 0 ) {
F_31 ( V_2 , L_17 ) ;
return - 1 ;
}
if ( F_1 ( V_1 , V_108 , & V_103 ) < 0 ) {
F_31 ( V_2 , L_18 ) ;
return - 1 ;
}
F_27 ( & V_19 -> V_53 ) ;
V_19 -> V_105 [ 0 ] = V_101 >> 8 ;
V_19 -> V_105 [ 1 ] = V_101 ;
V_19 -> V_105 [ 2 ] = V_102 >> 8 ;
V_19 -> V_105 [ 3 ] = V_102 ;
V_19 -> V_105 [ 4 ] = V_103 >> 8 ;
V_19 -> V_105 [ 5 ] = V_103 ;
F_29 ( & V_19 -> V_53 ) ;
}
if ( F_1 ( V_1 , V_109 , & V_104 ) < 0 ) {
F_31 ( V_2 , L_19 ) ;
return - 1 ;
}
F_27 ( & V_19 -> V_53 ) ;
V_19 -> V_110 = V_104 ;
F_29 ( & V_19 -> V_53 ) ;
return 0 ;
}
static void F_51 ( struct V_47 * V_48 , int V_20 )
{
struct V_18 * V_19 ;
F_52 ( ! V_48 ) ;
V_19 = F_24 ( V_48 ) ;
V_19 -> V_57 . V_111 = V_112 + V_14 ;
F_53 ( & V_19 -> V_57 , V_19 -> V_57 . V_111 ) ;
}
static void F_54 ( unsigned long V_15 )
{
struct V_18 * V_19 = (struct V_18 * ) V_15 ;
F_36 ( & V_19 -> V_58 ) ;
V_19 -> V_57 . V_111 = V_112 + ( 2 * V_14 ) ;
F_55 ( & V_19 -> V_57 ) ;
}
static void F_56 ( struct V_113 * V_114 )
{
struct V_18 * V_19 ;
int V_115 , V_116 ;
T_2 V_117 [ 6 ] ;
V_19 = F_57 ( V_114 ) ;
V_116 = V_19 -> V_110 ;
for ( V_115 = 0 ; V_115 < 6 ; V_115 ++ )
V_117 [ V_115 ] = V_19 -> V_105 [ V_115 ] ;
if ( F_49 ( V_19 ) < 0 )
return;
if ( ( V_116 != V_19 -> V_110 ) ||
( V_117 [ 0 ] != V_19 -> V_105 [ 0 ] ) ||
( V_117 [ 1 ] != V_19 -> V_105 [ 1 ] ) ||
( V_117 [ 2 ] != V_19 -> V_105 [ 2 ] ) ||
( V_117 [ 3 ] != V_19 -> V_105 [ 3 ] ) ||
( V_117 [ 4 ] != V_19 -> V_105 [ 4 ] ) ||
( V_117 [ 5 ] != V_19 -> V_105 [ 5 ] ) )
F_58 ( & V_19 -> V_48 , V_19 -> V_110 ,
& V_19 -> V_105 [ 0 ] ) ;
}
static void V_74 ( struct V_113 * V_114 )
{
struct V_22 * V_23 ;
struct V_18 * V_19 ;
struct V_21 * V_21 ;
struct V_27 * V_27 ;
unsigned int V_20 ;
unsigned long V_25 ;
V_23 = F_59 ( V_114 ) ;
V_27 = V_23 -> V_27 ;
V_21 = V_27 -> V_28 ;
V_19 = F_24 ( V_21 -> V_67 ) ;
V_20 = V_21 -> V_68 ;
if ( F_60 ( V_27 -> V_2 , V_27 -> V_118 ) )
F_26 ( & V_19 -> V_1 -> V_2 , L_20 ) ;
F_18 ( V_27 ) ;
F_10 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_19 ( & V_23 -> V_34 ) ;
F_12 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
if ( F_13 ( V_21 -> V_30 ) )
V_21 -> V_30 ( V_21 ) ;
if ( V_19 -> V_55 [ V_20 ] . V_85 & V_86 )
F_61 ( & V_19 -> V_48 , V_20 ) ;
F_6 ( V_23 ) ;
}
static T_3 F_62 ( struct V_119 * V_120 , struct V_121 * V_122 ,
char * V_4 )
{
struct V_123 * V_124 = F_63 ( V_122 ) ;
struct V_125 * V_126 = F_64 ( V_120 ) ;
if ( ! V_124 -> V_127 )
return - V_49 ;
return V_124 -> V_127 ( V_126 , V_124 , V_4 ) ;
}
static T_3 F_65 ( struct V_119 * V_120 ,
struct V_121 * V_122 ,
const char * V_4 ,
T_4 V_128 )
{
struct V_123 * V_124 = F_63 ( V_122 ) ;
struct V_125 * V_126 = F_64 ( V_120 ) ;
if ( ! V_124 -> V_129 )
return - V_49 ;
return V_124 -> V_129 ( V_126 , V_124 , V_4 , V_128 ) ;
}
static void F_66 ( struct V_119 * V_120 )
{
struct V_125 * V_126 = F_64 ( V_120 ) ;
F_6 ( V_126 ) ;
}
static T_3 F_67 ( struct V_125 * V_126 ,
struct V_123 * V_122 , char * V_4 )
{
T_1 V_100 ;
T_1 V_130 ;
int V_131 ;
if ( ! strcmp ( V_122 -> V_122 . V_132 , L_21 ) )
V_130 = V_109 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_22 ) )
V_130 = V_133 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_23 ) )
V_130 = V_134 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_24 ) )
V_130 = V_135 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_25 ) )
V_130 = V_136 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_26 ) )
V_130 = V_137 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_27 ) )
V_130 = V_138 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_28 ) )
V_130 = V_139 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_29 ) )
V_130 = V_140 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_30 ) )
V_130 = V_106 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_31 ) )
V_130 = V_107 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_32 ) )
V_130 = V_108 ;
else
return - V_49 ;
V_131 = F_1 ( V_126 -> V_1 , V_130 , & V_100 ) ;
if ( V_131 < 0 )
return V_131 ;
return snprintf ( V_4 , V_141 , L_33 , V_100 ) ;
}
static T_3 F_68 ( struct V_125 * V_126 ,
struct V_123 * V_122 ,
const char * V_4 , T_4 V_142 )
{
T_1 V_143 ;
T_1 V_130 ;
int V_131 ;
if ( ! strcmp ( V_122 -> V_122 . V_132 , L_25 ) )
V_130 = V_136 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_26 ) )
V_130 = V_137 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_27 ) )
V_130 = V_138 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_28 ) )
V_130 = V_139 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_29 ) )
V_130 = V_140 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_30 ) )
V_130 = V_106 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_31 ) )
V_130 = V_107 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_32 ) )
V_130 = V_108 ;
else
return - V_49 ;
V_131 = F_69 ( V_4 , 16 , & V_143 ) ;
if ( V_131 )
return V_131 ;
V_131 = F_7 ( V_126 -> V_1 , V_130 , V_143 ) ;
if ( V_131 < 0 )
return V_131 ;
return V_142 ;
}
static struct
V_125 * F_70 ( struct V_119 * V_144 )
{
struct V_125 * V_145 ;
int V_5 ;
V_145 = F_2 ( sizeof( * V_145 ) , V_7 ) ;
if ( ! V_145 )
return NULL ;
V_5 = F_71 ( & V_145 -> V_120 , & V_146 , V_144 ,
L_34 ) ;
if ( V_5 ) {
F_72 ( & V_145 -> V_120 ) ;
return NULL ;
}
return V_145 ;
}
static void F_73 ( struct V_125 * V_147 )
{
F_72 ( & V_147 -> V_120 ) ;
}
static int
F_74 ( struct V_148 * V_149 , const struct V_150 * V_151 )
{
unsigned int V_115 ;
unsigned int V_152 ;
struct V_153 * V_154 ;
struct V_18 * V_19 ;
struct V_1 * V_155 ;
struct V_65 * V_2 ;
struct V_156 * V_157 ;
struct V_158 * V_159 ;
int V_160 = 0 ;
int V_131 ;
V_157 = V_149 -> V_161 ;
V_155 = F_75 ( V_149 ) ;
V_2 = & V_155 -> V_2 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_7 ) ;
if ( ! V_19 )
goto V_162;
F_76 ( V_149 , V_19 ) ;
V_152 = V_157 -> V_163 . V_164 ;
F_77 ( & V_19 -> V_53 ) ;
F_35 ( & V_19 -> V_58 , F_56 ) ;
F_78 ( & V_19 -> V_57 , F_54 ,
( unsigned long ) V_19 ) ;
V_19 -> V_1 = V_155 ;
V_19 -> V_57 . V_111 = V_112 + ( 2 * V_14 ) ;
V_19 -> V_48 . V_165 = V_166 . V_167 ;
V_19 -> V_48 . V_149 = V_168 ;
V_19 -> V_48 . V_169 = F_46 ;
V_19 -> V_48 . V_170 = F_51 ;
V_19 -> V_48 . V_171 = F_38 ;
V_19 -> V_48 . V_172 = F_23 ;
V_19 -> V_48 . V_173 = V_19 -> V_173 ;
V_19 -> V_48 . V_50 = V_152 ;
snprintf ( V_19 -> V_173 , sizeof( V_19 -> V_173 ) ,
L_35 ,
V_155 -> V_174 -> V_175 ,
V_155 -> V_176 ,
V_155 -> V_177 -> V_163 . V_178 ,
V_157 -> V_163 . V_179 ) ;
V_19 -> V_55 = F_79 ( V_152 , sizeof( * V_19 -> V_55 ) , V_7 ) ;
if ( ! V_19 -> V_55 )
goto V_180;
V_19 -> V_181 = F_79 ( V_152 , sizeof( * V_19 -> V_181 ) , V_7 ) ;
if ( ! V_19 -> V_181 )
goto V_182;
V_19 -> V_48 . V_183 = V_19 -> V_181 ;
V_19 -> V_48 . V_66 = NULL ;
V_19 -> V_90 =
F_79 ( V_152 , sizeof( * V_19 -> V_90 ) , V_7 ) ;
if ( ! V_19 -> V_90 )
goto V_184;
V_19 -> V_84 =
F_79 ( V_152 , sizeof( * V_19 -> V_84 ) , V_7 ) ;
if ( ! V_19 -> V_84 )
goto V_185;
V_154 = V_19 -> V_181 ;
for ( V_115 = 0 ; V_115 < V_152 ; V_115 ++ ) {
V_159 = & V_157 -> V_186 [ V_115 ] . V_163 ;
V_19 -> V_90 [ V_115 ] = V_159 -> V_187 ;
V_19 -> V_54 [ V_115 ] = false ;
V_19 -> V_52 [ V_115 ] = true ;
snprintf ( & V_19 -> V_188 [ V_115 ] [ 0 ] , V_189 , L_36 ,
V_19 -> V_90 [ V_115 ] ) ;
V_154 -> V_190 = & V_19 -> V_188 [ V_115 ] [ 0 ] ;
V_154 -> V_191 = V_192 ;
V_154 -> V_193 = V_192 ;
V_154 -> V_194 = V_195 ;
V_154 -> V_196 = V_195 ;
V_154 -> V_41 = V_197 | V_56 |
V_42 | V_44 ;
if ( F_80 ( V_159 ) )
V_154 -> V_85 = V_198 ;
else
V_154 -> V_85 = V_86 ;
V_154 ++ ;
F_81 ( & V_19 -> V_84 [ V_115 ] ) ;
F_82 ( & V_19 -> V_26 [ V_115 ] ) ;
V_131 = F_7 ( V_155 ,
V_199 + V_200 +
V_159 -> V_187 * 16 ,
1 ) ;
if ( V_131 < 0 )
F_22 ( L_37 ,
V_159 -> V_187 ) ;
}
F_47 ( V_2 , L_38 ,
F_5 ( V_155 -> V_201 . V_202 ) ,
F_5 ( V_155 -> V_201 . V_203 ) ,
V_155 -> V_174 -> V_175 ,
V_155 -> V_204 ) ;
F_47 ( V_2 , L_39 ,
V_155 -> V_174 -> V_175 ,
V_155 -> V_176 ,
V_155 -> V_177 -> V_163 . V_178 ,
V_157 -> V_163 . V_179 ) ;
V_19 -> V_144 = F_83 ( & V_19 -> V_48 ) ;
if ( F_84 ( V_19 -> V_144 ) ) {
V_160 = F_85 ( V_19 -> V_144 ) ;
goto V_205;
}
F_27 ( & V_19 -> V_53 ) ;
if ( F_5 ( V_155 -> V_201 . V_203 ) == V_206 ) {
V_19 -> V_207 = F_70 ( V_19 -> V_144 ) ;
if ( ! V_19 -> V_207 ) {
F_29 ( & V_19 -> V_53 ) ;
F_86 ( & V_19 -> V_48 ) ;
V_160 = - V_12 ;
goto V_205;
}
F_87 ( & V_19 -> V_207 -> V_120 , V_208 ) ;
V_19 -> V_207 -> V_1 = V_19 -> V_1 ;
}
F_29 ( & V_19 -> V_53 ) ;
return 0 ;
V_205:
F_6 ( V_19 -> V_84 ) ;
V_185:
F_6 ( V_19 -> V_90 ) ;
V_184:
F_6 ( V_19 -> V_181 ) ;
V_182:
F_6 ( V_19 -> V_55 ) ;
V_180:
F_6 ( V_19 ) ;
V_162:
if ( V_160 == 0 || V_160 == - V_12 ) {
V_160 = - V_12 ;
F_31 ( V_2 , L_40 ) ;
}
return V_160 ;
}
static void F_88 ( struct V_148 * V_149 )
{
struct V_18 * V_19 ;
V_19 = F_89 ( V_149 ) ;
F_27 ( & V_19 -> V_53 ) ;
F_76 ( V_149 , NULL ) ;
V_19 -> V_1 = NULL ;
F_29 ( & V_19 -> V_53 ) ;
F_28 ( & V_19 -> V_57 ) ;
F_20 ( & V_19 -> V_58 ) ;
F_73 ( V_19 -> V_207 ) ;
F_86 ( & V_19 -> V_48 ) ;
F_6 ( V_19 -> V_84 ) ;
F_6 ( V_19 -> V_181 ) ;
F_6 ( V_19 -> V_55 ) ;
F_6 ( V_19 -> V_90 ) ;
F_6 ( V_19 ) ;
}
static int T_5 F_90 ( void )
{
F_91 ( L_41 ) ;
if ( F_92 ( & V_209 ) ) {
F_93 ( L_42 ) ;
return - V_49 ;
}
return 0 ;
}
static void T_6 F_94 ( void )
{
F_91 ( L_43 ) ;
F_95 ( & V_209 ) ;
}
