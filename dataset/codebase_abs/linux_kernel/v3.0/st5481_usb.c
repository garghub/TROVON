static void F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_5 ;
int V_6 ;
if ( F_2 ( 0 , & V_5 -> V_7 ) ) {
return;
}
if ( ( V_6 = F_3 ( & V_5 -> V_8 . V_9 ) ) < 0 ) {
F_4 ( 0 , & V_5 -> V_7 ) ;
return;
}
V_1 -> V_10 =
( unsigned char * ) & V_5 -> V_8 . V_11 [ V_6 ] ;
F_5 ( 1 , L_1 ,
( (struct V_12 * ) V_1 -> V_10 ) -> V_13 . V_14 ,
( (struct V_12 * ) V_1 -> V_10 ) -> V_13 . V_15 ,
( (struct V_12 * ) V_1 -> V_10 ) -> V_13 . V_16 ) ;
V_1 -> V_17 = V_3 -> V_18 ;
F_6 ( V_1 , V_19 ) ;
}
static void F_7 ( struct V_2 * V_3 ,
T_1 V_20 , T_1 V_21 , T_2 V_22 , T_2 V_23 ,
T_3 V_24 , void * V_25 )
{
struct V_4 * V_5 = & V_3 -> V_5 ;
int V_26 ;
struct V_12 * V_12 ;
if ( ( V_26 = F_8 ( & V_5 -> V_8 . V_9 ) ) < 0 ) {
F_9 ( L_2 ) ;
return;
}
V_12 = & V_5 -> V_8 . V_11 [ V_26 ] ;
V_12 -> V_13 . V_27 = V_21 ;
V_12 -> V_13 . V_14 = V_20 ;
V_12 -> V_13 . V_15 = F_10 ( & V_22 ) ;
V_12 -> V_13 . V_16 = F_10 ( & V_23 ) ;
V_12 -> V_13 . V_28 = 0 ;
V_12 -> V_24 = V_24 ;
V_12 -> V_25 = V_25 ;
F_1 ( V_5 -> V_1 , V_3 ) ;
}
void F_11 ( struct V_2 * V_3 ,
T_1 V_20 , T_2 V_22 ,
T_3 V_24 , void * V_25 )
{
F_7 ( V_3 , V_20 ,
V_29 | V_30 | V_31 ,
V_22 , 0 , V_24 , V_25 ) ;
}
void F_12 ( struct V_2 * V_3 ,
T_4 V_32 ,
T_3 V_24 , void * V_25 )
{
F_5 ( 1 , L_3 , V_32 ) ;
F_7 ( V_3 ,
V_33 , V_29 | V_34 ,
0 , V_32 , V_24 , V_25 ) ;
}
void F_13 ( struct V_2 * V_3 , unsigned int V_35 )
{
F_5 ( 8 , L_4 , F_14 ( V_35 ) ) ;
F_11 ( V_3 , V_36 , V_35 , NULL , NULL ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_25 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
struct V_12 * V_12 ;
if ( F_16 ( V_1 -> V_37 < 0 ) ) {
switch ( V_1 -> V_37 ) {
case - V_38 :
case - V_39 :
case - V_40 :
F_5 ( 1 , L_5 , V_1 -> V_37 ) ;
return;
default:
F_9 ( L_6 , V_1 -> V_37 ) ;
break;
}
}
V_12 = (struct V_12 * ) V_1 -> V_10 ;
if ( V_12 -> V_13 . V_14 == V_33 ) {
F_17 ( & V_12 -> V_13 . V_16 ) ;
F_18 ( V_3 -> V_18 , V_12 -> V_13 . V_16 ) ;
}
if ( V_12 -> V_24 )
V_12 -> V_24 ( V_12 -> V_25 ) ;
F_19 ( 0 , & V_5 -> V_7 ) ;
F_1 ( V_1 , V_3 ) ;
return;
}
static void F_20 ( struct V_1 * V_1 )
{
T_1 * V_11 = V_1 -> V_41 ;
T_1 V_42 ;
struct V_2 * V_3 = V_1 -> V_25 ;
int V_43 ;
int V_37 ;
switch ( V_1 -> V_37 ) {
case 0 :
break;
case - V_40 :
case - V_38 :
case - V_39 :
F_5 ( 2 , L_7 , V_1 -> V_37 ) ;
return;
default:
F_9 ( L_8 , V_1 -> V_37 ) ;
goto exit;
}
F_21 ( 2 , V_11 , V_44 ) ;
if ( V_1 -> V_45 == 0 ) {
goto exit;
}
V_42 = V_11 [ V_46 ] ;
if ( V_42 & V_47 )
F_22 ( & V_3 -> V_48 . V_49 , V_50 , NULL ) ;
if ( V_42 & V_51 )
F_22 ( & V_3 -> V_48 . V_49 , V_52 , NULL ) ;
V_42 = V_11 [ V_53 ] ;
if ( V_42 & V_54 )
F_22 ( & V_3 -> V_48 . V_49 , V_55 , NULL ) ;
if ( V_42 & V_56 )
;
V_42 = V_11 [ V_46 ] ;
if ( V_42 & V_57 )
F_22 ( & V_3 -> V_58 , V_11 [ V_59 ] & 0x0f , NULL ) ;
for ( V_43 = 0 ; V_43 < 2 ; V_43 ++ )
V_3 -> V_60 [ V_43 ] . V_61 . V_62 |= V_11 [ V_63 + V_43 ] ;
V_1 -> V_45 = 0 ;
exit:
V_37 = F_23 ( V_1 , V_19 ) ;
if ( V_37 )
F_9 ( L_9 , V_37 ) ;
}
int F_24 ( struct V_2 * V_3 )
{
struct V_64 * V_17 = V_3 -> V_18 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
struct V_65 * V_66 = & V_3 -> V_66 ;
struct V_67 * V_68 ;
struct V_69 * V_70 = NULL ;
struct V_71 * V_72 ;
int V_37 ;
struct V_1 * V_1 ;
T_1 * V_73 ;
F_5 ( 2 , L_10 ) ;
if ( ( V_37 = F_25 ( V_17 ) ) < 0 ) {
F_9 ( L_11 , V_37 ) ;
return V_37 ;
}
V_68 = F_26 ( V_17 , 0 ) ;
if ( V_68 )
V_70 = F_27 ( V_68 , 3 ) ;
if ( ! V_70 )
return - V_74 ;
if ( V_70 -> V_75 . V_76 != 7 ) {
F_9 ( L_12 , V_70 -> V_75 . V_76 ) ;
return - V_77 ;
}
V_70 -> V_72 [ 3 ] . V_75 . V_78 = F_28 ( 32 ) ;
V_70 -> V_72 [ 4 ] . V_75 . V_78 = F_28 ( 32 ) ;
if ( ( V_37 = F_29 ( V_17 , 0 , 3 ) ) < 0 ) {
F_9 ( L_13 , V_37 ) ;
return V_37 ;
}
V_1 = F_30 ( 0 , V_79 ) ;
if ( ! V_1 ) {
return - V_80 ;
}
V_5 -> V_1 = V_1 ;
F_31 ( V_1 , V_17 ,
F_32 ( V_17 , 0 ) ,
NULL , NULL , 0 , F_15 , V_3 ) ;
F_33 ( & V_5 -> V_8 . V_9 , F_34 ( V_5 -> V_8 . V_11 ) ) ;
V_1 = F_30 ( 0 , V_79 ) ;
if ( ! V_1 ) {
return - V_80 ;
}
V_66 -> V_1 = V_1 ;
V_73 = F_35 ( V_44 , V_79 ) ;
if ( ! V_73 ) {
return - V_80 ;
}
V_72 = & V_70 -> V_72 [ V_81 - 1 ] ;
F_36 ( V_1 , V_17 ,
F_37 ( V_17 , V_72 -> V_75 . V_82 ) ,
V_73 , V_44 ,
F_20 , V_3 ,
V_72 -> V_75 . V_83 ) ;
return 0 ;
}
void F_38 ( struct V_2 * V_3 )
{
struct V_65 * V_66 = & V_3 -> V_66 ;
struct V_4 * V_5 = & V_3 -> V_5 ;
F_5 ( 1 , L_10 ) ;
F_39 ( V_5 -> V_1 ) ;
F_40 ( V_5 -> V_1 -> V_41 ) ;
F_41 ( V_5 -> V_1 ) ;
V_5 -> V_1 = NULL ;
F_39 ( V_66 -> V_1 ) ;
F_40 ( V_66 -> V_1 -> V_41 ) ;
F_41 ( V_66 -> V_1 ) ;
V_66 -> V_1 = NULL ;
}
void F_42 ( struct V_2 * V_3 )
{
static const T_1 V_84 [] = {
V_85 , 0 ,
V_86 , 0 ,
V_87 , 0x0d ,
V_88 , 0x29 ,
V_89 , 0x14 ,
V_90 , 0x01 ,
V_91 , V_92 ,
V_93 , 6 ,
V_94 , 20 ,
V_95 , 6 ,
V_96 , 20 ,
V_97 , V_57 + V_47 + V_51 ,
0
} ;
struct V_65 * V_66 = & V_3 -> V_66 ;
int V_98 = 0 ;
T_1 V_20 , V_22 ;
F_5 ( 8 , L_10 ) ;
V_3 -> V_99 = V_92 ;
F_6 ( V_66 -> V_1 , V_79 ) ;
while ( ( V_20 = V_84 [ V_98 ++ ] ) ) {
V_22 = V_84 [ V_98 ++ ] ;
F_11 ( V_3 , V_20 , V_22 , NULL , NULL ) ;
}
F_13 ( V_3 , V_100 ) ;
}
void F_43 ( struct V_2 * V_3 )
{
F_5 ( 8 , L_10 ) ;
F_11 ( V_3 , V_85 , 0 , NULL , NULL ) ;
}
static void
F_44 ( struct V_1 * V_1 , struct V_64 * V_17 ,
unsigned int V_32 , void * V_73 , int V_101 ,
int V_102 , T_5 V_24 ,
void * V_25 )
{
int V_103 ;
V_1 -> V_17 = V_17 ;
V_1 -> V_32 = V_32 ;
V_1 -> V_104 = 1 ;
V_1 -> V_41 = V_73 ;
V_1 -> V_105 = V_101 ;
V_1 -> V_106 = V_101 * V_102 ;
V_1 -> V_45 = 0 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_25 = V_25 ;
V_1 -> V_107 = V_108 ;
for ( V_103 = 0 ; V_103 < V_101 ; V_103 ++ ) {
V_1 -> V_109 [ V_103 ] . V_110 = V_102 * V_103 ;
V_1 -> V_109 [ V_103 ] . V_111 = V_102 ;
V_1 -> V_109 [ V_103 ] . V_45 = 0 ;
}
}
int
F_45 ( struct V_1 * V_1 [ 2 ] , struct V_64 * V_17 ,
unsigned int V_32 , int V_101 ,
int V_102 , int V_112 ,
T_5 V_24 , void * V_25 )
{
int V_43 , V_113 ;
unsigned char * V_73 ;
for ( V_43 = 0 ; V_43 < 2 ; V_43 ++ ) {
V_113 = - V_80 ;
V_1 [ V_43 ] = F_30 ( V_101 , V_79 ) ;
if ( ! V_1 [ V_43 ] )
goto V_114;
V_73 = F_35 ( V_112 , V_79 ) ;
if ( ! V_73 )
goto V_114;
F_44 ( V_1 [ V_43 ] , V_17 , V_32 , V_73 ,
V_101 , V_102 , V_24 ,
V_25 ) ;
}
return 0 ;
V_114:
for ( V_43 = 0 ; V_43 < 2 ; V_43 ++ ) {
if ( V_1 [ V_43 ] ) {
F_40 ( V_1 [ V_43 ] -> V_41 ) ;
V_1 [ V_43 ] -> V_41 = NULL ;
F_41 ( V_1 [ V_43 ] ) ;
V_1 [ V_43 ] = NULL ;
}
}
return V_113 ;
}
void F_46 ( struct V_1 * V_1 [ 2 ] )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < 2 ; V_43 ++ ) {
F_39 ( V_1 [ V_43 ] ) ;
F_40 ( V_1 [ V_43 ] -> V_41 ) ;
F_41 ( V_1 [ V_43 ] ) ;
V_1 [ V_43 ] = NULL ;
}
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_115 * V_116 = V_1 -> V_25 ;
unsigned char * V_117 ;
struct V_118 * V_119 ;
int V_120 , V_121 , V_37 ;
if ( F_16 ( V_1 -> V_37 < 0 ) ) {
switch ( V_1 -> V_37 ) {
case - V_38 :
case - V_39 :
case - V_40 :
F_5 ( 1 , L_5 , V_1 -> V_37 ) ;
return;
default:
F_9 ( L_6 , V_1 -> V_37 ) ;
break;
}
}
F_48 ( 0x80 , V_1 ) ;
V_120 = F_49 ( V_1 ) ;
V_117 = V_1 -> V_41 ;
while ( V_120 > 0 ) {
if ( V_116 -> V_122 == V_123 ) {
memcpy ( V_116 -> V_124 , V_117 , V_120 ) ;
V_37 = V_120 ;
V_120 = 0 ;
} else {
V_37 = F_50 ( & V_116 -> V_125 , V_117 , V_120 , & V_121 ,
V_116 -> V_124 , V_116 -> V_126 ) ;
V_117 += V_121 ;
V_120 -= V_121 ;
}
if ( V_37 > 0 ) {
F_5 ( 4 , L_14 , V_37 ) ;
F_21 ( 0x400 , V_116 -> V_124 , V_37 ) ;
if ( ! ( V_119 = F_51 ( V_37 ) ) ) {
F_9 ( L_15 ) ;
break;
}
memcpy ( F_52 ( V_119 , V_37 ) , V_116 -> V_124 , V_37 ) ;
V_116 -> V_127 -> V_128 ( V_116 -> V_127 , V_129 | V_130 , V_119 ) ;
} else if ( V_37 == - V_131 ) {
F_53 ( L_16 ) ;
} else if ( V_37 == - V_132 ) {
F_53 ( L_17 ) ;
} else if ( V_37 == - V_133 ) {
F_53 ( L_18 ) ;
}
}
V_1 -> V_17 = V_116 -> V_3 -> V_18 ;
V_1 -> V_45 = 0 ;
F_6 ( V_1 , V_19 ) ;
}
int F_54 ( struct V_115 * V_116 )
{
struct V_64 * V_17 = V_116 -> V_3 -> V_18 ;
int V_113 ;
F_5 ( 4 , L_10 ) ;
V_116 -> V_124 = F_35 ( V_116 -> V_126 , V_79 ) ;
V_113 = - V_80 ;
if ( ! V_116 -> V_124 )
goto V_114;
V_113 = F_45 ( V_116 -> V_1 , V_17 ,
F_55 ( V_17 , V_116 -> V_134 ) ,
V_116 -> V_101 , V_116 -> V_102 ,
V_116 -> V_101 * V_116 -> V_102 ,
F_47 , V_116 ) ;
if ( V_113 )
goto V_135;
return 0 ;
V_135:
F_40 ( V_116 -> V_124 ) ;
V_114:
return V_113 ;
}
void F_56 ( struct V_115 * V_116 )
{
F_5 ( 2 , L_10 ) ;
F_46 ( V_116 -> V_1 ) ;
}
static int F_49 ( struct V_1 * V_1 )
{
struct V_136 * V_137 , * V_138 ;
unsigned char * V_139 , * V_140 ;
unsigned int V_120 ;
if ( V_1 -> V_37 < 0 ) {
return V_1 -> V_37 ;
}
for ( V_137 = & V_1 -> V_109 [ 0 ] ,
V_138 = & V_1 -> V_109 [ V_1 -> V_105 ] ,
V_140 = V_1 -> V_41 ;
V_137 < V_138 ;
V_137 ++ ) {
if ( V_137 -> V_37 < 0 ) {
return ( V_137 -> V_37 ) ;
}
V_120 = V_137 -> V_45 ;
V_137 -> V_45 = 0 ;
V_139 = V_1 -> V_41 + V_137 -> V_110 ;
if ( V_139 != V_140 ) {
while ( V_120 -- ) {
* V_140 ++ = * V_139 ++ ;
}
} else {
V_140 += V_120 ;
}
}
return ( V_140 - ( unsigned char * ) V_1 -> V_41 ) ;
}
static void F_57 ( void * V_25 )
{
struct V_115 * V_116 = V_25 ;
struct V_2 * V_3 = V_116 -> V_3 ;
F_5 ( 4 , L_10 ) ;
V_116 -> V_1 [ 0 ] -> V_17 = V_3 -> V_18 ;
F_6 ( V_116 -> V_1 [ 0 ] , V_79 ) ;
V_116 -> V_1 [ 1 ] -> V_17 = V_3 -> V_18 ;
F_6 ( V_116 -> V_1 [ 1 ] , V_79 ) ;
}
void F_58 ( struct V_115 * V_116 , int V_122 )
{
if ( V_116 -> V_122 == V_122 )
return;
V_116 -> V_122 = V_122 ;
F_59 ( V_116 -> V_1 [ 0 ] ) ;
F_59 ( V_116 -> V_1 [ 1 ] ) ;
if ( V_116 -> V_122 != V_141 ) {
if ( V_116 -> V_122 != V_123 ) {
T_6 V_142 = V_143 ;
if ( V_116 -> V_122 == V_144 )
V_142 |= V_145 ;
F_60 ( & V_116 -> V_125 , V_142 ) ;
}
F_12 ( V_116 -> V_3 , V_116 -> V_134 , NULL , NULL ) ;
F_11 ( V_116 -> V_3 , V_116 -> V_146 ,
V_116 -> V_102 ,
NULL , NULL ) ;
F_57 ( V_116 ) ;
} else {
F_11 ( V_116 -> V_3 , V_116 -> V_146 ,
0 , NULL , NULL ) ;
}
}
