static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 = V_5 | V_6 | V_7 ;
int * V_8 = F_2 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
goto error;
* V_8 = V_10 ;
V_3 = F_3 ( V_2 ,
F_4 ( V_2 , 0 ) ,
0 ,
V_4 ,
0 ,
0 ,
V_8 ,
0 ,
5 * V_11 ) ;
F_5 ( V_8 ) ;
if ( V_3 >= 0 )
return;
error:
F_6 ( & V_2 -> V_2 , L_1 ) ;
}
static inline int F_7 ( struct V_1 * V_2 , T_2 V_12 , void * V_13 )
{
return F_3 ( V_2 ,
F_8 ( V_2 , 0 ) ,
V_14 ,
V_15 | V_6 | V_16 ,
0x0000 ,
V_12 ,
V_13 ,
2 ,
5 * V_11 ) ;
}
static inline int F_9 ( struct V_1 * V_2 , T_2 V_12 , T_2 V_8 )
{
return F_3 ( V_2 ,
F_4 ( V_2 , 0 ) ,
V_17 ,
V_5 | V_6 | V_16 ,
V_8 ,
V_12 ,
NULL ,
0 ,
5 * V_11 ) ;
}
static void F_10 ( struct V_18 * V_19 , unsigned int V_20 )
{
struct V_21 * V_21 ;
struct V_22 * V_23 , * V_24 ;
unsigned long V_25 ;
F_11 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_12 (anchor, tmp, &mdev->anchor_list[channel], list) {
struct V_27 * V_27 = V_23 -> V_27 ;
F_13 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
if ( F_14 ( V_27 ) ) {
V_21 = V_27 -> V_28 ;
if ( ! F_15 () ) {
F_16 ( V_27 ) ;
} else {
F_17 ( V_27 ) ;
F_18 ( & V_23 -> V_29 ) ;
}
if ( ( V_21 ) && ( V_21 -> V_30 ) ) {
V_21 -> V_31 = V_32 ;
V_21 -> V_33 = 0 ;
V_21 -> V_30 ( V_21 ) ;
}
F_19 ( V_27 ) ;
}
F_11 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_20 ( & V_23 -> V_34 ) ;
F_5 ( V_23 ) ;
}
F_13 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
}
static unsigned int F_21 ( struct V_35 * V_36 )
{
unsigned int V_37 = 0 ;
unsigned int V_38 = V_36 -> V_39 ;
if ( ! V_38 ) {
F_22 ( L_2 ) ;
return V_37 ;
}
switch ( V_36 -> V_40 ) {
case V_41 :
V_37 = V_42 * V_38 ;
break;
case V_43 :
if ( V_36 -> V_44 == 0 ) {
F_22 ( L_3 ) ;
V_37 = 0 ;
} else if ( V_36 -> V_44 == 0xFF )
V_37 = ( V_45 / V_38 ) * V_38 ;
else
V_37 = V_36 -> V_44 * V_38 ;
break;
default:
F_22 ( L_4 ) ;
break;
}
return V_37 ;
}
static int F_23 ( struct V_46 * V_47 , int V_20 )
{
struct V_18 * V_19 ;
V_19 = F_24 ( V_47 ) ;
if ( F_25 ( ! V_47 ) ) {
F_26 ( & V_19 -> V_1 -> V_2 , L_5 ) ;
return - V_48 ;
}
if ( F_25 ( ( V_20 < 0 ) || ( V_20 >= V_47 -> V_49 ) ) ) {
F_26 ( & V_19 -> V_1 -> V_2 , L_6 ) ;
return - V_50 ;
}
V_19 -> V_51 [ V_20 ] = false ;
F_27 ( & V_19 -> V_52 ) ;
F_10 ( V_19 , V_20 ) ;
if ( V_19 -> V_53 [ V_20 ] == true )
V_19 -> V_53 [ V_20 ] = false ;
if ( V_19 -> V_54 [ V_20 ] . V_40 == V_55 ) {
F_28 ( & V_19 -> V_56 ) ;
F_29 ( & V_19 -> V_57 ) ;
}
F_30 ( & V_19 -> V_52 ) ;
return 0 ;
}
static int F_31 ( struct V_18 * V_19 , int V_20 , struct V_21 * V_21 )
{
struct V_35 * V_54 = & V_19 -> V_54 [ V_20 ] ;
unsigned int V_58 , V_59 , V_37 ;
T_2 V_60 , V_61 ;
V_37 = F_21 ( V_54 ) ;
if ( ! V_37 )
return - V_48 ;
V_59 = V_21 -> V_62 / V_37 ;
if ( V_59 < 1 ) {
F_6 ( & V_19 -> V_1 -> V_2 ,
L_7 ) ;
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
static int F_32 ( struct V_18 * V_19 , int V_20 , struct V_21 * V_21 )
{
unsigned int V_58 , V_59 , V_37 ;
struct V_35 * const V_54 = & V_19 -> V_54 [ V_20 ] ;
V_37 = F_21 ( V_54 ) ;
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
V_19 = F_24 ( V_21 -> V_66 ) ;
V_20 = V_21 -> V_67 ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( ( V_27 -> V_31 == - V_68 ) || ( V_27 -> V_31 == - V_69 ) ||
( V_19 -> V_51 [ V_20 ] == false ) ) {
V_30 ( & V_23 -> V_29 ) ;
return;
}
if ( F_25 ( V_27 -> V_31 && ! ( V_27 -> V_31 == - V_68 ||
V_27 -> V_31 == - V_69 ||
V_27 -> V_31 == - V_70 ) ) ) {
V_21 -> V_33 = 0 ;
switch ( V_27 -> V_31 ) {
case - V_71 :
F_26 ( V_2 , L_8 ) ;
F_34 ( & V_19 -> V_47 , V_20 ) ;
V_21 -> V_31 = V_72 ;
F_17 ( V_27 ) ;
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
F_11 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_20 ( & V_23 -> V_34 ) ;
F_13 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_5 ( V_23 ) ;
if ( F_14 ( V_21 -> V_30 ) )
V_21 -> V_30 ( V_21 ) ;
F_19 ( V_27 ) ;
}
static void F_37 ( struct V_27 * V_27 )
{
struct V_21 * V_21 ;
struct V_22 * V_23 ;
struct V_18 * V_19 ;
struct V_64 * V_2 ;
unsigned long V_25 ;
unsigned int V_20 ;
struct V_35 * V_54 ;
V_21 = V_27 -> V_28 ;
V_23 = V_21 -> V_65 ;
V_19 = F_24 ( V_21 -> V_66 ) ;
V_20 = V_21 -> V_67 ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( ( V_27 -> V_31 == - V_68 ) || ( V_27 -> V_31 == - V_69 ) ||
( V_19 -> V_51 [ V_20 ] == false ) ) {
V_30 ( & V_23 -> V_29 ) ;
return;
}
V_54 = & V_19 -> V_54 [ V_20 ] ;
if ( F_25 ( V_27 -> V_31 && ! ( V_27 -> V_31 == - V_68 ||
V_27 -> V_31 == - V_69 ||
V_27 -> V_31 == - V_70 ) ) ) {
V_21 -> V_33 = 0 ;
switch ( V_27 -> V_31 ) {
case - V_71 :
F_26 ( V_2 , L_9 ) ;
V_21 -> V_31 = V_72 ;
F_17 ( V_27 ) ;
F_35 ( & V_23 -> V_73 , V_74 ) ;
F_36 ( V_75 , & V_23 -> V_73 ) ;
return;
case - V_76 :
case - V_77 :
V_21 -> V_31 = V_32 ;
break;
case - V_80 :
F_26 ( V_2 , L_10 ) ;
default:
V_21 -> V_31 = V_72 ;
break;
}
} else {
V_21 -> V_33 = V_27 -> V_79 ;
if ( V_19 -> V_53 [ V_20 ] == false ) {
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
F_11 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_20 ( & V_23 -> V_34 ) ;
F_13 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_5 ( V_23 ) ;
if ( F_14 ( V_21 -> V_30 ) )
V_21 -> V_30 ( V_21 ) ;
F_19 ( V_27 ) ;
}
static int F_38 ( struct V_46 * V_47 , int V_20 , struct V_21 * V_21 )
{
struct V_18 * V_19 ;
struct V_22 * V_23 ;
struct V_35 * V_54 ;
struct V_64 * V_2 ;
int V_3 = 0 ;
struct V_27 * V_27 ;
unsigned long V_25 ;
unsigned long V_81 ;
void * V_63 ;
if ( F_25 ( ! V_47 || ! V_21 ) )
return - V_48 ;
if ( F_25 ( V_47 -> V_49 <= V_20 ) || ( V_20 < 0 ) )
return - V_50 ;
V_19 = F_24 ( V_47 ) ;
V_54 = & V_19 -> V_54 [ V_20 ] ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( ! V_19 -> V_1 )
return - V_76 ;
V_27 = F_39 ( V_82 , V_83 ) ;
if ( ! V_27 ) {
F_6 ( V_2 , L_11 ) ;
return - V_84 ;
}
V_23 = F_2 ( sizeof( * V_23 ) , V_83 ) ;
if ( ! V_23 ) {
V_3 = - V_84 ;
goto V_85;
}
V_23 -> V_27 = V_27 ;
F_40 ( & V_23 -> V_29 ) ;
V_21 -> V_65 = V_23 ;
F_11 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_41 ( & V_23 -> V_34 , & V_19 -> V_86 [ V_20 ] ) ;
F_13 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
if ( ( V_19 -> V_53 [ V_20 ] == true ) &&
( V_54 -> V_87 & V_88 ) )
if ( F_31 ( V_19 , V_20 , V_21 ) ) {
V_3 = - V_48 ;
goto V_89;
}
V_27 -> V_90 = V_21 -> V_91 ;
V_63 = V_21 -> V_63 ;
V_81 = V_21 -> V_62 ;
if ( V_54 -> V_87 & V_88 ) {
F_42 ( V_27 , V_19 -> V_1 ,
F_43 ( V_19 -> V_1 ,
V_19 -> V_92 [ V_20 ] ) ,
V_63 ,
V_81 ,
F_33 ,
V_21 ) ;
if ( V_54 -> V_40 != V_41 )
V_27 -> V_93 |= V_94 ;
} else {
F_42 ( V_27 , V_19 -> V_1 ,
F_44 ( V_19 -> V_1 ,
V_19 -> V_92 [ V_20 ] ) ,
V_63 ,
V_81 ,
F_37 ,
V_21 ) ;
}
V_27 -> V_93 |= V_95 ;
V_3 = F_45 ( V_27 , V_9 ) ;
if ( V_3 ) {
F_6 ( V_2 , L_12 , V_3 ) ;
goto V_89;
}
return 0 ;
V_89:
F_11 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_20 ( & V_23 -> V_34 ) ;
F_13 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_5 ( V_23 ) ;
V_85:
F_19 ( V_27 ) ;
return V_3 ;
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
V_19 = F_24 ( V_47 ) ;
V_19 -> V_51 [ V_20 ] = true ;
V_2 = & V_19 -> V_1 -> V_2 ;
if ( F_25 ( ! V_47 || ! V_54 ) ) {
F_6 ( V_2 , L_13 ) ;
return - V_98 ;
}
if ( F_25 ( ( V_20 < 0 ) || ( V_20 >= V_47 -> V_49 ) ) ) {
F_6 ( V_2 , L_6 ) ;
return - V_98 ;
}
if ( ( ! V_54 -> V_99 ) || ( ! V_54 -> V_100 ) ) {
F_6 ( V_2 , L_14 ) ;
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
if ( ( V_54 -> V_40 != V_43 ) &&
( V_54 -> V_40 != V_41 ) ) {
F_26 ( V_2 , L_15 ) ;
return - V_98 ;
}
V_37 = F_21 ( V_54 ) ;
if ( ( V_37 == 0 ) || ( V_37 > V_45 ) ) {
F_26 ( V_2 , L_16 ) ;
return - V_98 ;
}
if ( V_54 -> V_100 % V_37 ) {
T_2 V_101 ;
V_101 = V_54 -> V_100 / V_37 ;
V_54 -> V_100 = V_101 * V_37 ;
F_47 ( V_2 ,
L_17
L_18 ,
V_20 ,
V_54 -> V_100 ,
V_96 ) ;
}
V_59 = V_54 -> V_100 / V_37 ;
V_97 = V_59 * ( V_45 - V_37 ) ;
V_96 += V_97 ;
V_54 -> V_102 = ( F_48 ( V_96 , V_45 ) * V_45 )
- V_54 -> V_100 ;
exit:
V_19 -> V_54 [ V_20 ] = * V_54 ;
return 0 ;
}
static int F_49 ( struct V_18 * V_19 )
{
struct V_64 * V_2 = & V_19 -> V_1 -> V_2 ;
int V_103 ;
T_2 V_104 ;
T_1 V_105 [ 6 ] ;
if ( ! F_50 ( V_19 -> V_106 ) ) {
if ( 0 > F_7 ( V_19 -> V_1 ,
V_107 , V_105 ) ) {
F_6 ( V_2 , L_19 ) ;
return - 1 ;
}
if ( 0 > F_7 ( V_19 -> V_1 ,
V_108 , V_105 + 2 ) ) {
F_6 ( V_2 , L_20 ) ;
return - 1 ;
}
if ( 0 > F_7 ( V_19 -> V_1 ,
V_109 , V_105 + 4 ) ) {
F_6 ( V_2 , L_21 ) ;
return - 1 ;
}
F_27 ( & V_19 -> V_52 ) ;
for ( V_103 = 0 ; V_103 < 6 ; V_103 ++ )
V_19 -> V_106 [ V_103 ] = V_105 [ V_103 ] ;
F_30 ( & V_19 -> V_52 ) ;
}
if ( 0 > F_7 ( V_19 -> V_1 , V_110 , & V_104 ) ) {
F_6 ( V_2 , L_22 ) ;
return - 1 ;
}
F_51 ( & V_104 ) ;
F_27 ( & V_19 -> V_52 ) ;
V_19 -> V_111 = V_104 ;
F_30 ( & V_19 -> V_52 ) ;
return 0 ;
}
static void F_52 ( struct V_46 * V_47 , int V_20 )
{
struct V_18 * V_19 ;
F_53 ( ! V_47 ) ;
V_19 = F_24 ( V_47 ) ;
V_19 -> V_56 . V_112 = V_113 + V_11 ;
F_54 ( & V_19 -> V_56 , V_19 -> V_56 . V_112 ) ;
}
static void F_55 ( unsigned long V_8 )
{
struct V_18 * V_19 = (struct V_18 * ) V_8 ;
F_36 ( V_75 , & V_19 -> V_57 ) ;
V_19 -> V_56 . V_112 = V_113 + ( 2 * V_11 ) ;
F_56 ( & V_19 -> V_56 ) ;
}
static void F_57 ( struct V_114 * V_115 )
{
struct V_18 * V_19 ;
int V_103 , V_116 ;
T_1 V_117 [ 6 ] ;
V_19 = F_58 ( V_115 ) ;
V_116 = V_19 -> V_111 ;
for ( V_103 = 0 ; V_103 < 6 ; V_103 ++ )
V_117 [ V_103 ] = V_19 -> V_106 [ V_103 ] ;
if ( 0 > F_49 ( V_19 ) )
return;
if ( ( V_116 != V_19 -> V_111 ) ||
( V_117 [ 0 ] != V_19 -> V_106 [ 0 ] ) ||
( V_117 [ 1 ] != V_19 -> V_106 [ 1 ] ) ||
( V_117 [ 2 ] != V_19 -> V_106 [ 2 ] ) ||
( V_117 [ 3 ] != V_19 -> V_106 [ 3 ] ) ||
( V_117 [ 4 ] != V_19 -> V_106 [ 4 ] ) ||
( V_117 [ 5 ] != V_19 -> V_106 [ 5 ] ) )
F_59 ( & V_19 -> V_47 , V_19 -> V_111 ,
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
V_23 = F_60 ( V_115 ) ;
V_27 = V_23 -> V_27 ;
V_21 = V_27 -> V_28 ;
V_19 = F_24 ( V_21 -> V_66 ) ;
V_20 = V_21 -> V_67 ;
if ( F_61 ( V_27 -> V_2 , V_27 -> V_118 ) )
F_26 ( & V_19 -> V_1 -> V_2 , L_23 ) ;
F_19 ( V_27 ) ;
F_11 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
F_20 ( & V_23 -> V_34 ) ;
F_13 ( & V_19 -> V_26 [ V_20 ] , V_25 ) ;
if ( F_14 ( V_21 -> V_30 ) )
V_21 -> V_30 ( V_21 ) ;
if ( V_19 -> V_54 [ V_20 ] . V_87 & V_88 )
F_62 ( & V_19 -> V_47 , V_20 ) ;
F_5 ( V_23 ) ;
}
static T_3 F_63 ( struct V_119 * V_120 , struct V_121 * V_122 ,
char * V_13 )
{
struct V_123 * V_124 = F_64 ( V_122 ) ;
struct V_125 * V_126 = F_65 ( V_120 ) ;
if ( ! V_124 -> V_127 )
return - V_48 ;
return V_124 -> V_127 ( V_126 , V_124 , V_13 ) ;
}
static T_3 F_66 ( struct V_119 * V_120 ,
struct V_121 * V_122 ,
const char * V_13 ,
T_4 V_128 )
{
struct V_123 * V_124 = F_64 ( V_122 ) ;
struct V_125 * V_126 = F_65 ( V_120 ) ;
if ( ! V_124 -> V_129 )
return - V_48 ;
return V_124 -> V_129 ( V_126 , V_124 , V_13 , V_128 ) ;
}
static void F_67 ( struct V_119 * V_120 )
{
struct V_125 * V_126 = F_65 ( V_120 ) ;
F_5 ( V_126 ) ;
}
static T_3 F_68 ( struct V_125 * V_126 ,
struct V_123 * V_122 , char * V_13 )
{
T_2 V_101 ;
T_2 V_130 ;
int V_131 ;
if ( ! strcmp ( V_122 -> V_122 . V_132 , L_24 ) )
V_130 = V_110 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_25 ) )
V_130 = V_133 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_26 ) )
V_130 = V_134 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_27 ) )
V_130 = V_135 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_28 ) )
V_130 = V_136 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_29 ) )
V_130 = V_137 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_30 ) )
V_130 = V_138 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_31 ) )
V_130 = V_139 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_32 ) )
V_130 = V_140 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_33 ) )
V_130 = V_107 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_34 ) )
V_130 = V_108 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_35 ) )
V_130 = V_109 ;
else
return - V_48 ;
V_131 = F_7 ( V_126 -> V_1 , V_130 , & V_101 ) ;
if ( V_131 < 0 )
return V_131 ;
return snprintf ( V_13 , V_141 , L_36 , F_69 ( V_101 ) ) ;
}
static T_3 F_70 ( struct V_125 * V_126 ,
struct V_123 * V_122 ,
const char * V_13 , T_4 V_142 )
{
T_2 V_143 ;
T_2 V_130 ;
int V_131 ;
if ( ! strcmp ( V_122 -> V_122 . V_132 , L_28 ) )
V_130 = V_136 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_29 ) )
V_130 = V_137 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_30 ) )
V_130 = V_138 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_31 ) )
V_130 = V_139 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_32 ) )
V_130 = V_140 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_33 ) )
V_130 = V_107 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_34 ) )
V_130 = V_108 ;
else if ( ! strcmp ( V_122 -> V_122 . V_132 , L_35 ) )
V_130 = V_109 ;
else
return - V_48 ;
V_131 = F_71 ( V_13 , 16 , & V_143 ) ;
if ( V_131 )
return V_131 ;
V_131 = F_9 ( V_126 -> V_1 , V_130 , F_72 ( V_143 ) ) ;
if ( V_131 < 0 )
return V_131 ;
return V_142 ;
}
static struct
V_125 * F_73 ( struct V_119 * V_144 )
{
struct V_125 * V_145 ;
int V_3 ;
V_145 = F_2 ( sizeof( * V_145 ) , V_9 ) ;
if ( ! V_145 )
return NULL ;
V_3 = F_74 ( & V_145 -> V_120 , & V_146 , V_144 ,
L_37 ) ;
if ( V_3 ) {
F_75 ( & V_145 -> V_120 ) ;
return NULL ;
}
return V_145 ;
}
static void F_76 ( struct V_125 * V_147 )
{
F_75 ( & V_147 -> V_120 ) ;
}
static int
F_77 ( struct V_148 * V_149 , const struct V_150 * V_151 )
{
unsigned int V_103 ;
unsigned int V_152 ;
struct V_153 * V_154 ;
struct V_18 * V_19 ;
struct V_1 * V_155 ;
struct V_64 * V_2 ;
struct V_156 * V_157 ;
struct V_158 * V_159 ;
int V_160 = 0 ;
V_157 = V_149 -> V_161 ;
V_155 = F_78 ( V_149 ) ;
V_2 = & V_155 -> V_2 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_9 ) ;
if ( ! V_19 )
goto V_162;
F_79 ( V_149 , V_19 ) ;
V_152 = V_157 -> V_163 . V_164 ;
F_80 ( & V_19 -> V_52 ) ;
F_35 ( & V_19 -> V_57 , F_57 ) ;
F_81 ( & V_19 -> V_56 ) ;
V_19 -> V_1 = V_155 ;
V_19 -> V_56 . V_165 = F_55 ;
V_19 -> V_56 . V_8 = ( unsigned long ) V_19 ;
V_19 -> V_56 . V_112 = V_113 + ( 2 * V_11 ) ;
V_19 -> V_47 . V_166 = V_167 . V_168 ;
V_19 -> V_47 . V_149 = V_169 ;
V_19 -> V_47 . V_170 = F_46 ;
V_19 -> V_47 . V_171 = F_52 ;
V_19 -> V_47 . V_172 = F_38 ;
V_19 -> V_47 . V_173 = F_23 ;
V_19 -> V_47 . V_174 = V_19 -> V_174 ;
V_19 -> V_47 . V_49 = V_152 ;
snprintf ( V_19 -> V_174 , sizeof( V_19 -> V_174 ) ,
L_38 ,
V_155 -> V_175 -> V_176 ,
V_155 -> V_177 ,
V_155 -> V_178 -> V_163 . V_179 ,
V_157 -> V_163 . V_180 ) ;
V_19 -> V_54 = F_82 ( V_152 , sizeof( * V_19 -> V_54 ) , V_9 ) ;
if ( ! V_19 -> V_54 )
goto V_181;
V_19 -> V_182 = F_82 ( V_152 , sizeof( * V_19 -> V_182 ) , V_9 ) ;
if ( ! V_19 -> V_182 )
goto V_183;
V_19 -> V_47 . V_184 = V_19 -> V_182 ;
V_19 -> V_47 . V_65 = NULL ;
V_19 -> V_92 =
F_82 ( V_152 , sizeof( * V_19 -> V_92 ) , V_9 ) ;
if ( ! V_19 -> V_92 )
goto V_185;
V_19 -> V_86 =
F_82 ( V_152 , sizeof( * V_19 -> V_86 ) , V_9 ) ;
if ( ! V_19 -> V_86 )
goto V_186;
V_154 = V_19 -> V_182 ;
for ( V_103 = 0 ; V_103 < V_152 ; V_103 ++ ) {
V_159 = & V_157 -> V_187 [ V_103 ] . V_163 ;
V_19 -> V_92 [ V_103 ] = V_159 -> V_188 ;
V_19 -> V_53 [ V_103 ] = false ;
V_19 -> V_51 [ V_103 ] = true ;
snprintf ( & V_19 -> V_189 [ V_103 ] [ 0 ] , V_190 , L_39 ,
V_19 -> V_92 [ V_103 ] ) ;
V_154 -> V_191 = & V_19 -> V_189 [ V_103 ] [ 0 ] ;
V_154 -> V_192 = V_193 ;
V_154 -> V_194 = V_193 ;
V_154 -> V_195 = V_196 ;
V_154 -> V_197 = V_196 ;
V_154 -> V_40 = V_198 | V_55 |
V_41 | V_43 ;
if ( V_159 -> V_188 & V_15 )
V_154 -> V_87 = V_199 ;
else
V_154 -> V_87 = V_88 ;
V_154 ++ ;
F_83 ( & V_19 -> V_86 [ V_103 ] ) ;
F_84 ( & V_19 -> V_26 [ V_103 ] ) ;
}
F_47 ( V_2 , L_40 ,
F_69 ( V_155 -> V_200 . V_201 ) ,
F_69 ( V_155 -> V_200 . V_202 ) ,
V_155 -> V_175 -> V_176 ,
V_155 -> V_203 ) ;
F_47 ( V_2 , L_41 ,
V_155 -> V_175 -> V_176 ,
V_155 -> V_177 ,
V_155 -> V_178 -> V_163 . V_179 ,
V_157 -> V_163 . V_180 ) ;
V_19 -> V_144 = F_85 ( & V_19 -> V_47 ) ;
if ( F_86 ( V_19 -> V_144 ) ) {
V_160 = F_87 ( V_19 -> V_144 ) ;
goto V_204;
}
F_27 ( & V_19 -> V_52 ) ;
if ( F_69 ( V_155 -> V_200 . V_202 ) == V_205 ) {
V_19 -> V_206 = F_73 ( V_19 -> V_144 ) ;
if ( ! V_19 -> V_206 ) {
F_30 ( & V_19 -> V_52 ) ;
F_88 ( & V_19 -> V_47 ) ;
V_160 = - V_84 ;
goto V_204;
}
F_89 ( & V_19 -> V_206 -> V_120 , V_207 ) ;
V_19 -> V_206 -> V_1 = V_19 -> V_1 ;
F_1 ( V_155 ) ;
}
F_30 ( & V_19 -> V_52 ) ;
return 0 ;
V_204:
F_5 ( V_19 -> V_86 ) ;
V_186:
F_5 ( V_19 -> V_92 ) ;
V_185:
F_5 ( V_19 -> V_182 ) ;
V_183:
F_5 ( V_19 -> V_54 ) ;
V_181:
F_5 ( V_19 ) ;
V_162:
if ( V_160 == 0 || V_160 == - V_84 ) {
V_160 = - V_84 ;
F_6 ( V_2 , L_42 ) ;
}
return V_160 ;
}
static void F_90 ( struct V_148 * V_149 )
{
struct V_18 * V_19 ;
V_19 = F_91 ( V_149 ) ;
F_27 ( & V_19 -> V_52 ) ;
F_79 ( V_149 , NULL ) ;
V_19 -> V_1 = NULL ;
F_30 ( & V_19 -> V_52 ) ;
F_28 ( & V_19 -> V_56 ) ;
F_29 ( & V_19 -> V_57 ) ;
F_76 ( V_19 -> V_206 ) ;
F_88 ( & V_19 -> V_47 ) ;
F_5 ( V_19 -> V_86 ) ;
F_5 ( V_19 -> V_182 ) ;
F_5 ( V_19 -> V_54 ) ;
F_5 ( V_19 -> V_92 ) ;
F_5 ( V_19 ) ;
}
static int T_5 F_92 ( void )
{
F_93 ( L_43 ) ;
if ( F_94 ( & V_208 ) ) {
F_95 ( L_44 ) ;
return - V_48 ;
}
V_75 = F_96 ( L_45 ) ;
if ( V_75 == NULL ) {
F_95 ( L_46 ) ;
F_97 ( & V_208 ) ;
return - V_84 ;
}
return 0 ;
}
static void T_6 F_98 ( void )
{
F_93 ( L_47 ) ;
F_99 ( V_75 ) ;
F_97 ( & V_208 ) ;
}
