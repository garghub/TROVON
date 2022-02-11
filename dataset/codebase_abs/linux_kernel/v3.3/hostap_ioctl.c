static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
struct V_1 * V_7 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_5 -> type != V_8 )
return NULL ;
V_7 = & V_6 -> V_7 ;
V_7 -> V_9 = 0 ;
V_7 -> V_10 . V_11 =
V_6 -> V_12 . V_13 ;
V_7 -> V_10 . V_14 =
V_6 -> V_12 . V_15 +
V_6 -> V_12 . V_16 +
V_6 -> V_12 . V_17 ;
V_7 -> V_10 . V_18 =
V_6 -> V_12 . V_19 ;
V_7 -> V_10 . V_20 =
V_6 -> V_12 . V_21 ;
if ( V_6 -> V_22 != V_23 &&
V_6 -> V_22 != V_24 ) {
int V_25 = 1 ;
#ifdef F_3
if ( F_3 () )
V_25 = 0 ;
#endif
if ( V_25 && F_4 ( V_3 ) == 0 )
V_7 -> V_26 . V_27 = V_28 |
V_29 ;
V_7 -> V_26 . V_26 = V_6 -> V_30 ;
V_7 -> V_26 . V_31 = V_6 -> V_32 ;
V_7 -> V_26 . V_33 = V_6 -> V_34 ;
} else {
V_7 -> V_26 . V_26 = 0 ;
V_7 -> V_26 . V_31 = 0 ;
V_7 -> V_26 . V_33 = 0 ;
V_7 -> V_26 . V_27 = V_35 ;
}
return V_7 ;
}
static int F_5 ( struct V_2 * V_3 , T_2 * V_36 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
T_2 V_37 [ 12 ] ;
int V_38 ;
T_3 V_39 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
V_38 = V_6 -> V_40 -> V_41 ( V_3 , V_42 , V_37 ,
sizeof( V_37 ) , 0 ) ;
if ( V_38 < 2 )
return 0 ;
V_39 = F_6 ( * ( V_43 * ) V_37 ) ;
if ( V_38 - 2 < V_39 || V_39 > 10 )
return 0 ;
memcpy ( V_36 , V_37 + 2 , V_39 ) ;
return V_39 ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
char * V_46 , char * V_47 )
{
T_2 V_36 [ 10 ] ;
int V_38 , V_48 , V_49 = 0 ;
V_38 = F_5 ( V_3 , V_36 ) ;
for ( V_48 = 0 ; V_48 < V_38 ; V_48 ++ ) {
if ( V_36 [ V_48 ] == 0x0b || V_36 [ V_48 ] == 0x16 ) {
V_49 = 1 ;
break;
}
}
strcpy ( V_46 , V_49 ? L_1 : L_2 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_51 , char * V_52 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
int V_48 ;
struct V_53 * * V_54 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
V_48 = V_51 -> V_55 & V_56 ;
if ( V_48 < 1 || V_48 > 4 )
V_48 = V_6 -> V_57 . V_58 ;
else
V_48 -- ;
if ( V_48 < 0 || V_48 >= V_59 )
return - V_60 ;
V_54 = & V_6 -> V_57 . V_54 [ V_48 ] ;
if ( V_51 -> V_55 & V_61 ) {
if ( * V_54 )
F_9 ( & V_6 -> V_57 , V_54 ) ;
goto V_62;
}
if ( * V_54 != NULL && ( * V_54 ) -> V_63 != NULL &&
strcmp ( ( * V_54 ) -> V_63 -> V_46 , L_3 ) != 0 ) {
F_9 ( & V_6 -> V_57 , V_54 ) ;
}
if ( * V_54 == NULL ) {
struct V_53 * V_64 ;
V_64 = F_10 ( sizeof( struct V_53 ) ,
V_65 ) ;
if ( V_64 == NULL )
return - V_66 ;
V_64 -> V_63 = F_11 ( L_3 ) ;
if ( ! V_64 -> V_63 ) {
F_12 ( L_4 ) ;
V_64 -> V_63 = F_11 ( L_3 ) ;
}
if ( V_64 -> V_63 && F_13 ( V_64 -> V_63 -> V_67 ) )
V_64 -> V_68 = V_64 -> V_63 -> V_69 ( V_48 ) ;
if ( ! V_64 -> V_63 || ! V_64 -> V_68 ) {
F_14 ( V_64 ) ;
V_64 = NULL ;
F_15 ( V_70 L_5
L_6 ,
V_3 -> V_46 ) ;
return - V_71 ;
}
* V_54 = V_64 ;
}
if ( V_51 -> V_72 > 0 ) {
int V_38 = V_51 -> V_72 <= 5 ? 5 : 13 ;
int V_73 = 1 , V_74 ;
if ( V_38 > V_51 -> V_72 )
memset ( V_52 + V_51 -> V_72 , 0 , V_38 - V_51 -> V_72 ) ;
( * V_54 ) -> V_63 -> V_75 ( V_52 , V_38 , NULL , ( * V_54 ) -> V_68 ) ;
for ( V_74 = 0 ; V_74 < V_59 ; V_74 ++ ) {
if ( V_74 != V_48 && V_6 -> V_57 . V_54 [ V_74 ] ) {
V_73 = 0 ;
break;
}
}
if ( V_73 )
V_6 -> V_57 . V_58 = V_48 ;
} else {
V_6 -> V_57 . V_58 = V_48 ;
}
V_62:
V_6 -> V_76 = V_51 -> V_55 & V_77 ;
if ( F_16 ( V_6 ) ) {
F_15 ( V_78 L_7 , V_3 -> V_46 ) ;
return - V_60 ;
}
if ( V_6 -> V_22 != V_79 && V_6 -> V_40 -> V_80 ( V_3 ) ) {
F_15 ( V_78 L_8 , V_3 -> V_46 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_51 , char * V_81 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
int V_48 , V_38 ;
T_3 V_39 ;
struct V_53 * V_54 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
V_48 = V_51 -> V_55 & V_56 ;
if ( V_48 < 1 || V_48 > 4 )
V_48 = V_6 -> V_57 . V_58 ;
else
V_48 -- ;
if ( V_48 < 0 || V_48 >= V_59 )
return - V_60 ;
V_54 = V_6 -> V_57 . V_54 [ V_48 ] ;
V_51 -> V_55 = V_48 + 1 ;
if ( V_54 == NULL || V_54 -> V_63 == NULL ) {
V_51 -> V_72 = 0 ;
V_51 -> V_55 |= V_61 ;
return 0 ;
}
if ( strcmp ( V_54 -> V_63 -> V_46 , L_3 ) != 0 ) {
V_51 -> V_72 = 0 ;
V_51 -> V_55 |= V_82 ;
return 0 ;
}
V_38 = V_54 -> V_63 -> V_83 ( V_81 , V_84 , NULL , V_54 -> V_68 ) ;
V_51 -> V_72 = ( V_38 >= 0 ? V_38 : 0 ) ;
if ( V_6 -> V_40 -> V_41 ( V_3 , V_85 , & V_39 , 2 , 1 ) < 0 )
{
F_15 ( L_9 ) ;
return - V_71 ;
}
F_18 ( & V_39 ) ;
if ( V_39 & V_86 )
V_51 -> V_55 |= V_82 ;
else
V_51 -> V_55 |= V_61 ;
if ( V_39 & V_87 )
V_51 -> V_55 |= V_88 ;
else
V_51 -> V_55 |= V_77 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
int V_89 , V_90 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
V_90 = V_6 -> V_90 & V_6 -> V_91 ;
if ( ! V_90 || V_90 != V_6 -> V_90 ) {
F_15 ( V_92 L_10
L_11 ,
V_3 -> V_46 ) ;
if ( ! V_90 )
V_90 = V_6 -> V_91 ;
V_6 -> V_90 = V_90 ;
if ( F_20 ( V_3 , V_93 ,
V_90 ) )
F_15 ( V_70 L_12
L_13 , V_3 -> V_46 ) ;
}
V_89 = ( F_20 ( V_3 , V_94 ,
V_6 -> V_91 ) ||
F_20 ( V_3 , V_95 ,
V_6 -> V_91 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) ) ;
if ( V_89 ) {
F_15 ( V_70 L_14
L_15 ,
V_3 -> V_46 , V_6 -> V_91 ) ;
}
F_21 ( V_6 ) ;
return V_89 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_97 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_97 -> V_98 ) {
switch ( V_97 -> V_99 ) {
case 11000000 :
V_6 -> V_91 = V_100 ;
break;
case 5500000 :
V_6 -> V_91 = V_101 ;
break;
case 2000000 :
V_6 -> V_91 = V_102 ;
break;
case 1000000 :
V_6 -> V_91 = V_103 ;
break;
default:
V_6 -> V_91 = V_103 |
V_102 | V_101 |
V_100 ;
break;
}
} else {
switch ( V_97 -> V_99 ) {
case 11000000 :
V_6 -> V_91 = V_103 |
V_102 | V_101 |
V_100 ;
break;
case 5500000 :
V_6 -> V_91 = V_103 |
V_102 | V_101 ;
break;
case 2000000 :
V_6 -> V_91 = V_103 |
V_102 ;
break;
case 1000000 :
V_6 -> V_91 = V_103 ;
break;
default:
V_6 -> V_91 = V_103 |
V_102 | V_101 |
V_100 ;
break;
}
}
return F_19 ( V_3 ) ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_97 , char * V_47 )
{
T_3 V_39 ;
struct V_4 * V_5 ;
T_1 * V_6 ;
int V_89 = 0 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_40 -> V_41 ( V_3 , V_94 , & V_39 , 2 , 1 ) <
0 )
return - V_60 ;
if ( ( V_39 & 0x1 ) && ( V_39 > 1 ) )
V_97 -> V_98 = 0 ;
else
V_97 -> V_98 = 1 ;
if ( V_6 -> V_22 == V_23 && V_6 -> V_104 != NULL &&
! V_6 -> V_105 ) {
V_97 -> V_99 = V_6 -> V_104 -> V_106 > 0 ?
V_6 -> V_104 -> V_106 * 100000 : 11000000 ;
return 0 ;
}
if ( V_6 -> V_40 -> V_41 ( V_3 , V_107 , & V_39 , 2 , 1 ) <
0 )
return - V_60 ;
switch ( V_39 ) {
case V_103 :
V_97 -> V_99 = 1000000 ;
break;
case V_102 :
V_97 -> V_99 = 2000000 ;
break;
case V_101 :
V_97 -> V_99 = 5500000 ;
break;
case V_100 :
V_97 -> V_99 = 11000000 ;
break;
default:
V_97 -> V_99 = 11000000 ;
V_89 = - V_60 ;
break;
}
return V_89 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_108 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_108 -> V_99 < 1 || V_108 -> V_99 > 3 )
return - V_60 ;
if ( F_20 ( V_3 , V_109 , V_108 -> V_99 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
return - V_60 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_108 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_43 V_39 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_40 -> V_41 ( V_3 , V_109 , & V_39 , 2 , 1 ) <
0 )
return - V_60 ;
V_108 -> V_99 = F_6 ( V_39 ) ;
V_108 -> V_98 = 1 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
struct V_111 * V_112 ;
struct V_113 * V_26 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_22 != V_23 ) {
F_15 ( V_78 L_16
L_17 ) ;
V_110 -> V_72 = 0 ;
return - V_71 ;
}
V_112 = F_27 ( sizeof( struct V_111 ) * V_114 , V_65 ) ;
V_26 = F_27 ( sizeof( struct V_113 ) * V_114 , V_65 ) ;
if ( V_112 == NULL || V_26 == NULL ) {
F_14 ( V_112 ) ;
F_14 ( V_26 ) ;
V_110 -> V_72 = 0 ;
return - V_66 ;
}
V_110 -> V_72 = F_28 ( V_6 , V_112 , V_26 , V_114 , 1 ) ;
memcpy ( V_47 , & V_112 , sizeof( struct V_111 ) * V_110 -> V_72 ) ;
V_110 -> V_55 = 1 ;
memcpy ( V_47 + sizeof( struct V_111 ) * V_110 -> V_72 , & V_26 ,
sizeof( struct V_113 ) * V_110 -> V_72 ) ;
F_14 ( V_112 ) ;
F_14 ( V_26 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_115 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_43 V_39 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_115 -> V_116 )
V_39 = F_30 ( 2347 ) ;
else if ( V_115 -> V_99 < 0 || V_115 -> V_99 > 2347 )
return - V_60 ;
else
V_39 = F_30 ( V_115 -> V_99 ) ;
if ( V_6 -> V_40 -> V_117 ( V_3 , V_118 , & V_39 , 2 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
return - V_60 ;
V_6 -> V_119 = V_115 -> V_99 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_115 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_43 V_39 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_40 -> V_41 ( V_3 , V_118 , & V_39 , 2 , 1 ) <
0 )
return - V_60 ;
V_115 -> V_99 = F_6 ( V_39 ) ;
V_115 -> V_116 = ( V_115 -> V_99 == 2347 ) ;
V_115 -> V_98 = 1 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_115 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_43 V_39 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_115 -> V_116 )
V_39 = F_30 ( 2346 ) ;
else if ( V_115 -> V_99 < 256 || V_115 -> V_99 > 2346 )
return - V_60 ;
else
V_39 = F_30 ( V_115 -> V_99 & ~ 0x1 ) ;
V_6 -> V_120 = V_115 -> V_99 & ~ 0x1 ;
if ( V_6 -> V_40 -> V_117 ( V_3 , V_121 , & V_39 ,
2 )
|| V_6 -> V_40 -> V_80 ( V_3 ) )
return - V_60 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_115 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_43 V_39 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_40 -> V_41 ( V_3 , V_121 ,
& V_39 , 2 , 1 ) < 0 )
return - V_60 ;
V_115 -> V_99 = F_6 ( V_39 ) ;
V_115 -> V_116 = ( V_115 -> V_99 == 2346 ) ;
V_115 -> V_98 = 1 ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
struct V_122 V_123 ;
unsigned long V_55 ;
int V_48 ;
struct V_124 * V_125 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
memcpy ( V_123 . V_126 , V_6 -> V_127 , V_128 ) ;
V_123 . V_129 = 0 ;
F_35 ( & V_6 -> V_130 , V_55 ) ;
for ( V_48 = 0 ; V_48 < V_6 -> V_131 ; V_48 ++ ) {
if ( ! V_6 -> V_132 )
break;
V_125 = & V_6 -> V_132 [ V_48 ] ;
if ( memcmp ( V_6 -> V_127 , V_125 -> V_126 , V_128 ) == 0 ) {
V_123 . V_129 = V_125 -> V_133 ;
break;
}
}
F_36 ( & V_6 -> V_130 , V_55 ) ;
if ( V_6 -> V_40 -> V_117 ( V_3 , V_134 , & V_123 ,
sizeof( V_123 ) ) ) {
F_15 ( V_78 L_18 ,
V_3 -> V_46 , V_6 -> V_127 ) ;
return - 1 ;
}
F_15 ( V_78 L_19 ,
V_3 -> V_46 , V_6 -> V_127 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_111 * V_135 , char * V_47 )
{
#ifdef F_38
return - V_71 ;
#else
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
memcpy ( V_6 -> V_127 , & V_135 -> V_136 , V_128 ) ;
if ( V_6 -> V_137 == 1 && V_6 -> V_22 == V_79 ) {
struct V_138 V_139 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_140 = F_30 ( 0x3fff ) ;
V_139 . V_141 = F_30 ( V_103 ) ;
if ( V_6 -> V_40 -> V_117 ( V_3 , V_142 ,
& V_139 , sizeof( V_139 ) ) ) {
F_15 ( V_78 L_20
L_21
L_22 , V_3 -> V_46 ) ;
}
} else if ( V_6 -> V_137 == 2 &&
V_6 -> V_22 == V_79 ) {
if ( F_34 ( V_3 ) )
return - V_60 ;
} else {
F_15 ( V_78 L_23
L_24 ,
V_3 -> V_46 ) ;
}
return 0 ;
#endif
}
static int F_39 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_111 * V_135 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
V_135 -> V_143 = V_144 ;
switch ( V_5 -> type ) {
case V_145 :
memcpy ( & V_135 -> V_136 , V_3 -> V_146 , V_128 ) ;
break;
case V_147 :
memcpy ( & V_135 -> V_136 , V_6 -> V_148 , V_128 ) ;
break;
case V_149 :
memcpy ( & V_135 -> V_136 , V_5 -> V_150 . V_151 . V_152 , V_128 ) ;
break;
default:
if ( V_6 -> V_40 -> V_41 ( V_3 , V_153 ,
& V_135 -> V_136 , V_128 , 1 ) < 0 )
return - V_71 ;
memcpy ( V_6 -> V_126 , & V_135 -> V_136 , V_128 ) ;
break;
}
return 0 ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_154 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
memset ( V_6 -> V_46 , 0 , sizeof( V_6 -> V_46 ) ) ;
memcpy ( V_6 -> V_46 , V_154 , V_110 -> V_72 ) ;
V_6 -> V_155 = 1 ;
if ( F_41 ( V_3 , V_156 , V_6 -> V_46 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
return - V_60 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_154 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
int V_38 ;
char V_46 [ V_157 + 3 ] ;
T_3 V_39 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
V_38 = V_6 -> V_40 -> V_41 ( V_3 , V_156 ,
& V_46 , V_157 + 2 , 0 ) ;
V_39 = F_6 ( * ( V_43 * ) V_46 ) ;
if ( V_38 > V_157 + 2 || V_38 < 0 || V_39 > V_157 )
return - V_71 ;
V_46 [ V_39 + 2 ] = '\0' ;
V_110 -> V_72 = V_39 + 1 ;
memcpy ( V_154 , V_46 + 2 , V_39 + 1 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_158 * V_159 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_159 -> V_160 == 1 &&
V_159 -> V_161 / 100000 >= V_162 [ 0 ] &&
V_159 -> V_161 / 100000 <= V_162 [ V_163 - 1 ] ) {
int V_164 ;
int V_165 = V_159 -> V_161 / 100000 ;
for ( V_164 = 0 ; V_164 < V_163 ; V_164 ++ ) {
if ( V_165 == V_162 [ V_164 ] ) {
V_159 -> V_160 = 0 ;
V_159 -> V_161 = V_164 + 1 ;
break;
}
}
}
if ( V_159 -> V_160 != 0 || V_159 -> V_161 < 1 || V_159 -> V_161 > V_163 ||
! ( V_6 -> V_166 & ( 1 << ( V_159 -> V_161 - 1 ) ) ) )
return - V_60 ;
V_6 -> V_129 = V_159 -> V_161 ;
if ( F_20 ( V_3 , V_167 , V_6 -> V_129 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
return - V_60 ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_158 * V_159 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
T_3 V_39 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_40 -> V_41 ( V_3 , V_168 , & V_39 , 2 , 1 ) <
0 )
return - V_60 ;
F_18 ( & V_39 ) ;
if ( V_39 < 1 || V_39 > V_163 )
return - V_60 ;
V_159 -> V_161 = V_162 [ V_39 - 1 ] * 100000 ;
V_159 -> V_160 = 1 ;
return 0 ;
}
static void F_45 ( T_1 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_169 ;
if ( V_3 == NULL )
return;
if ( V_6 -> V_170 == V_171 ||
V_6 -> V_170 == V_172 ) {
V_3 -> type = V_173 ;
} else if ( V_6 -> V_170 == V_174 ) {
V_3 -> type = V_175 ;
} else {
V_3 -> type = V_176 ;
}
}
static int F_46 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_177 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_5 -> type == V_149 )
return - V_71 ;
if ( V_110 -> V_55 == 0 )
V_177 [ 0 ] = '\0' ;
if ( V_6 -> V_22 == V_23 && V_177 [ 0 ] == '\0' ) {
F_15 ( V_78 L_25
L_26 , V_3 -> V_46 ) ;
return - V_60 ;
}
memcpy ( V_6 -> V_178 , V_177 , V_110 -> V_72 ) ;
V_6 -> V_178 [ V_110 -> V_72 ] = '\0' ;
if ( ( ! V_6 -> V_179 &&
F_41 ( V_3 , V_180 , V_6 -> V_178 ) )
|| F_41 ( V_3 , V_181 , V_6 -> V_178 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
return - V_60 ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_178 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
T_3 V_39 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_5 -> type == V_149 )
return - V_71 ;
V_110 -> V_55 = 1 ;
if ( V_6 -> V_22 == V_23 ) {
V_110 -> V_72 = strlen ( V_6 -> V_178 ) ;
memcpy ( V_178 , V_6 -> V_178 , V_182 ) ;
} else {
int V_38 ;
char V_177 [ V_183 + 2 ] ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
V_38 = V_6 -> V_40 -> V_41 ( V_3 , V_184 ,
& V_177 , V_183 + 2 , 0 ) ;
V_39 = F_6 ( * ( V_43 * ) V_177 ) ;
if ( V_38 > V_183 + 2 || V_38 < 0 || V_39 > V_183 ) {
return - V_71 ;
}
V_110 -> V_72 = V_39 ;
memcpy ( V_178 , V_177 + 2 , V_182 ) ;
}
return 0 ;
}
static int F_48 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
struct V_185 * V_186 = (struct V_185 * ) V_47 ;
T_2 V_36 [ 10 ] ;
T_3 V_39 ;
int V_48 , V_38 , V_49 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
V_110 -> V_72 = sizeof( struct V_185 ) ;
memset ( V_186 , 0 , sizeof( struct V_185 ) ) ;
V_186 -> V_187 = V_188 ;
if ( V_6 -> V_22 == V_79 || V_6 -> V_22 == V_189 )
{
V_186 -> V_190 = 1 * 1024 ;
V_186 -> V_191 = 65535 * 1024 ;
V_186 -> V_192 = 1 * 1024 ;
V_186 -> V_193 = 1000 * 1024 ;
V_186 -> V_194 = V_195 ;
V_186 -> V_196 = V_197 ;
V_186 -> V_198 = V_195 | V_197 |
V_199 | V_200 ;
}
V_186 -> V_201 = V_202 ;
V_186 -> V_203 = 18 ;
V_186 -> V_204 = V_205 ;
V_186 -> V_206 = V_205 ;
V_186 -> V_207 = 0 ;
V_186 -> V_208 = 255 ;
V_186 -> V_209 = V_163 ;
V_39 = 0 ;
for ( V_48 = 0 ; V_48 < V_163 ; V_48 ++ ) {
if ( V_6 -> V_166 & ( 1 << V_48 ) ) {
V_186 -> V_159 [ V_39 ] . V_48 = V_48 + 1 ;
V_186 -> V_159 [ V_39 ] . V_161 = V_162 [ V_48 ] * 100000 ;
V_186 -> V_159 [ V_39 ] . V_160 = 1 ;
V_39 ++ ;
}
if ( V_39 == V_210 )
break;
}
V_186 -> V_211 = V_39 ;
if ( V_6 -> V_212 >= F_49 ( 1 , 3 , 1 ) ) {
V_186 -> V_213 . V_26 = 70 ;
V_186 -> V_213 . V_31 = 0 ;
V_186 -> V_213 . V_33 = 0 ;
V_186 -> V_214 . V_26 = 20 ;
V_186 -> V_214 . V_31 = - 60 ;
V_186 -> V_214 . V_33 = - 95 ;
} else {
V_186 -> V_213 . V_26 = 92 ;
V_186 -> V_213 . V_31 = 154 ;
V_186 -> V_213 . V_33 = 154 ;
}
V_186 -> V_215 = 3 ;
V_186 -> V_216 = V_59 ;
V_186 -> V_217 = 2 ;
V_186 -> V_218 [ 0 ] = 5 ;
V_186 -> V_218 [ 1 ] = 13 ;
V_49 = 0 ;
V_38 = F_5 ( V_3 , V_36 ) ;
V_186 -> V_219 = 0 ;
for ( V_48 = 0 ; V_48 < V_38 ; V_48 ++ ) {
if ( V_186 -> V_219 < V_220 ) {
V_186 -> V_221 [ V_186 -> V_219 ] =
V_36 [ V_48 ] * 500000 ;
V_186 -> V_219 ++ ;
}
if ( V_36 [ V_48 ] == 0x0b || V_36 [ V_48 ] == 0x16 )
V_49 = 1 ;
}
V_186 -> V_222 = V_49 ? 5500000 : 1500000 ;
V_186 -> V_223 = 0 ;
V_186 -> V_224 = 2347 ;
V_186 -> V_225 = 256 ;
V_186 -> V_226 = 2346 ;
V_186 -> V_227 [ 0 ] = ( V_228 |
F_50 ( V_229 ) |
F_50 ( V_230 ) |
F_50 ( V_231 ) ) ;
V_186 -> V_227 [ 1 ] = V_232 ;
V_186 -> V_227 [ 4 ] = ( F_50 ( V_233 ) |
F_50 ( V_234 ) |
F_50 ( V_235 ) |
F_50 ( V_236 ) ) ;
V_186 -> V_237 = V_238 | V_239 |
V_240 | V_241 ;
if ( V_6 -> V_212 >= F_49 ( 1 , 3 , 1 ) )
V_186 -> V_242 = V_243 ;
return 0 ;
}
static int F_51 ( T_1 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
F_15 ( V_78 L_27 ) ;
F_45 ( V_6 ) ;
if ( F_20 ( V_3 , V_244 ,
V_245 ) ) {
F_15 ( V_78 L_28
L_29 ) ;
return - V_71 ;
}
if ( F_20 ( V_3 , V_85 ,
V_246 |
V_247 ) ) {
F_15 ( V_78 L_30 ) ;
return - V_71 ;
}
if ( V_6 -> V_40 -> V_80 ( V_3 ) ||
V_6 -> V_40 -> V_248 ( V_3 , V_249 |
( V_250 << 8 ) ,
0 , NULL , NULL ) ) {
F_15 ( V_78 L_31 ) ;
return - V_71 ;
}
return 0 ;
}
static int F_52 ( T_1 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_169 ;
if ( V_3 == NULL )
return - 1 ;
F_15 ( V_78 L_32 , V_3 -> V_46 ) ;
V_3 -> type = V_144 ;
if ( V_6 -> V_40 -> V_248 ( V_3 , V_249 |
( V_251 << 8 ) ,
0 , NULL , NULL ) )
return - 1 ;
return F_16 ( V_6 ) ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
T_4 * V_252 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
int V_253 = 0 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( * V_252 != V_189 && * V_252 != V_79 &&
* V_252 != V_23 && * V_252 != V_24 &&
* V_252 != V_254 )
return - V_71 ;
#ifdef F_38
if ( * V_252 == V_189 || * V_252 == V_79 )
return - V_71 ;
#endif
if ( * V_252 == V_6 -> V_22 )
return 0 ;
if ( * V_252 == V_23 && V_6 -> V_178 [ 0 ] == '\0' ) {
F_15 ( V_70 L_33
L_34 , V_3 -> V_46 ) ;
return - V_60 ;
}
if ( V_6 -> V_22 == V_254 )
F_52 ( V_6 ) ;
if ( ( V_6 -> V_22 == V_189 ||
V_6 -> V_22 == V_254 ) && * V_252 == V_23 ) {
V_253 = 1 ;
}
F_15 ( V_78 L_35
L_36 , V_3 -> V_46 , V_6 -> V_22 , * V_252 ) ;
V_6 -> V_22 = * V_252 ;
if ( V_6 -> V_22 == V_254 )
F_51 ( V_6 ) ;
else if ( V_6 -> V_22 == V_23 && ! V_6 -> V_255 &&
! V_6 -> V_256 ) {
F_15 ( V_78 L_37
L_38 ,
V_3 -> V_46 ) ;
V_6 -> V_255 = 1 ;
}
if ( F_20 ( V_3 , V_244 ,
F_54 ( V_6 ) ) )
return - V_71 ;
if ( V_6 -> V_40 -> V_80 ( V_3 ) )
return - V_60 ;
if ( V_253 && V_6 -> V_40 -> V_80 ( V_3 ) )
return - V_60 ;
if ( V_6 -> V_22 != V_79 && V_6 -> V_22 != V_189 )
{
F_55 ( V_6 -> V_3 ) ;
F_55 ( V_6 -> V_169 ) ;
}
return 0 ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
T_4 * V_252 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
switch ( V_5 -> type ) {
case V_147 :
* V_252 = V_79 ;
break;
case V_149 :
* V_252 = V_24 ;
break;
default:
* V_252 = V_6 -> V_22 ;
break;
}
return 0 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_257 , char * V_47 )
{
#ifdef F_38
return - V_71 ;
#else
int V_89 = 0 ;
if ( V_257 -> V_116 )
return F_20 ( V_3 , V_258 , 0 ) ;
switch ( V_257 -> V_55 & V_259 ) {
case V_199 :
V_89 = F_20 ( V_3 , V_260 , 0 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_20 ( V_3 , V_258 , 1 ) ;
if ( V_89 )
return V_89 ;
break;
case V_200 :
V_89 = F_20 ( V_3 , V_260 , 1 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_20 ( V_3 , V_258 , 1 ) ;
if ( V_89 )
return V_89 ;
break;
case V_261 :
break;
default:
return - V_60 ;
}
if ( V_257 -> V_55 & V_197 ) {
V_89 = F_20 ( V_3 , V_258 , 1 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_20 ( V_3 , V_262 ,
V_257 -> V_99 / 1024 ) ;
if ( V_89 )
return V_89 ;
}
if ( V_257 -> V_55 & V_195 ) {
V_89 = F_20 ( V_3 , V_258 , 1 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_20 ( V_3 , V_263 ,
V_257 -> V_99 / 1024 ) ;
if ( V_89 )
return V_89 ;
}
return V_89 ;
#endif
}
static int F_58 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_97 , char * V_47 )
{
#ifdef F_38
return - V_71 ;
#else
struct V_4 * V_5 ;
T_1 * V_6 ;
V_43 V_264 , V_265 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_40 -> V_41 ( V_3 , V_258 , & V_264 , 2 , 1 )
< 0 )
return - V_60 ;
if ( ! F_6 ( V_264 ) ) {
V_97 -> V_116 = 1 ;
return 0 ;
}
V_97 -> V_116 = 0 ;
if ( ( V_97 -> V_55 & V_266 ) == V_197 ) {
V_43 V_267 ;
if ( V_6 -> V_40 -> V_41 ( V_3 ,
V_262 ,
& V_267 , 2 , 1 ) < 0 )
return - V_60 ;
V_97 -> V_55 = V_197 ;
V_97 -> V_99 = F_6 ( V_267 ) * 1024 ;
} else {
V_43 V_268 ;
if ( V_6 -> V_40 -> V_41 ( V_3 , V_263 ,
& V_268 , 2 , 1 ) < 0 )
return - V_60 ;
V_97 -> V_55 = V_195 ;
V_97 -> V_99 = F_6 ( V_268 ) * 1024 ;
}
if ( V_6 -> V_40 -> V_41 ( V_3 , V_260 , & V_265 ,
2 , 1 ) < 0 )
return - V_60 ;
if ( F_6 ( V_265 ) )
V_97 -> V_55 |= V_200 ;
else
V_97 -> V_55 |= V_199 ;
return 0 ;
#endif
}
static int F_59 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_97 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_97 -> V_116 )
return - V_60 ;
if ( V_97 -> V_55 == V_205 ) {
if ( V_97 -> V_99 < 0 ) {
V_6 -> V_269 = - 1 ;
V_6 -> V_270 &= ~ V_271 ;
} else {
if ( F_20 ( V_3 , V_272 ,
V_97 -> V_99 ) ) {
F_15 ( V_78 L_39
L_40 ,
V_3 -> V_46 , V_97 -> V_99 ) ;
return - V_71 ;
}
V_6 -> V_269 = V_97 -> V_99 ;
V_6 -> V_270 |= V_271 ;
}
return 0 ;
}
return - V_71 ;
#if 0
if (rrq->flags & IW_RETRY_LIMIT) {
if (rrq->flags & IW_RETRY_LONG)
HFA384X_RID_LONGRETRYLIMIT = rrq->value;
else if (rrq->flags & IW_RETRY_SHORT)
HFA384X_RID_SHORTRETRYLIMIT = rrq->value;
else {
HFA384X_RID_LONGRETRYLIMIT = rrq->value;
HFA384X_RID_SHORTRETRYLIMIT = rrq->value;
}
}
if (rrq->flags & IW_RETRY_LIFETIME) {
HFA384X_RID_MAXTRANSMITLIFETIME = rrq->value / 1024;
}
return 0;
#endif
}
static int F_60 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_97 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_43 V_273 , V_274 , V_275 , V_276 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_40 -> V_41 ( V_3 , V_277 , & V_273 ,
2 , 1 ) < 0 ||
V_6 -> V_40 -> V_41 ( V_3 , V_278 , & V_274 ,
2 , 1 ) < 0 ||
V_6 -> V_40 -> V_41 ( V_3 , V_279 ,
& V_275 , 2 , 1 ) < 0 )
return - V_60 ;
V_97 -> V_116 = 0 ;
if ( ( V_97 -> V_55 & V_280 ) == V_281 ) {
V_97 -> V_55 = V_281 ;
V_97 -> V_99 = F_6 ( V_275 ) * 1024 ;
} else {
if ( V_6 -> V_269 >= 0 ) {
V_97 -> V_55 = V_205 ;
if ( V_6 -> V_40 -> V_41 ( V_3 ,
V_272 ,
& V_276 , 2 , 1 ) >= 0 )
V_97 -> V_99 = F_6 ( V_276 ) ;
else
V_97 -> V_99 = V_6 -> V_269 ;
} else if ( ( V_97 -> V_55 & V_282 ) ) {
V_97 -> V_55 = V_205 | V_282 ;
V_97 -> V_99 = F_6 ( V_274 ) ;
} else {
V_97 -> V_55 = V_205 ;
V_97 -> V_99 = F_6 ( V_273 ) ;
if ( V_273 != V_274 )
V_97 -> V_55 |= V_283 ;
}
}
return 0 ;
}
static int F_61 ( T_3 V_39 )
{
signed char V_284 ;
if ( V_39 > 255 )
V_39 = 255 ;
V_284 = V_39 ;
V_284 >>= 2 ;
return - 12 - V_284 ;
}
static T_3 F_62 ( int V_39 )
{
signed char V_284 ;
if ( V_39 > 20 )
return 128 ;
else if ( V_39 < - 43 )
return 127 ;
V_284 = V_39 ;
V_284 = - 12 - V_284 ;
V_284 <<= 2 ;
return ( unsigned char ) V_284 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_97 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
#ifdef F_64
char * V_284 ;
#endif
T_3 V_39 ;
int V_89 = 0 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_97 -> V_116 ) {
if ( V_6 -> V_285 != V_286 ) {
V_39 = 0xff ;
V_89 = V_6 -> V_40 -> V_248 ( V_3 , V_287 ,
V_288 ,
& V_39 , NULL ) ;
F_15 ( V_78 L_41 ,
V_3 -> V_46 , V_89 ? L_42 : L_43 ) ;
V_6 -> V_285 = V_286 ;
}
return ( V_89 ? - V_71 : 0 ) ;
}
if ( V_6 -> V_285 == V_286 ) {
V_39 = 0 ;
V_89 = V_6 -> V_40 -> V_248 ( V_3 , V_287 ,
V_288 , & V_39 , NULL ) ;
F_15 ( V_78 L_44 ,
V_3 -> V_46 , V_89 ? L_42 : L_43 ) ;
V_6 -> V_285 = V_289 ;
}
#ifdef F_64
if ( ! V_97 -> V_98 && V_6 -> V_285 != V_290 ) {
F_15 ( V_78 L_45 ) ;
V_39 = V_291 ;
V_6 -> V_40 -> V_248 ( V_3 , V_249 |
( V_292 << 8 ) , 1 , & V_39 , NULL ) ;
V_6 -> V_285 = V_290 ;
return 0 ;
}
if ( V_6 -> V_285 != V_293 ) {
F_15 ( V_78 L_46 ) ;
V_39 = V_291 ;
V_6 -> V_40 -> V_248 ( V_3 , V_249 |
( V_292 << 8 ) , 0 , & V_39 , NULL ) ;
V_6 -> V_285 = V_293 ;
}
if ( V_97 -> V_55 == V_188 )
V_284 = L_47 ;
else if ( V_97 -> V_55 == V_294 )
V_284 = L_48 ;
else
V_284 = L_49 ;
F_15 ( V_78 L_50 , V_97 -> V_99 , V_284 ) ;
if ( V_97 -> V_55 != V_188 ) {
F_15 ( L_51 ) ;
return - V_71 ;
}
V_6 -> V_295 = V_97 -> V_99 ;
V_39 = F_62 ( V_6 -> V_295 ) ;
if ( V_6 -> V_40 -> V_248 ( V_3 , V_287 ,
V_296 , & V_39 , NULL ) )
V_89 = - V_71 ;
#else
if ( V_97 -> V_98 )
V_89 = - V_71 ;
#endif
return V_89 ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_97 , char * V_47 )
{
#ifdef F_64
struct V_4 * V_5 ;
T_1 * V_6 ;
T_3 V_297 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
V_97 -> V_55 = V_188 ;
V_97 -> V_116 = 0 ;
V_97 -> V_98 = 0 ;
if ( V_6 -> V_285 == V_290 ) {
if ( V_6 -> V_40 -> V_248 ( V_3 , V_298 ,
V_296 ,
NULL , & V_297 ) == 0 ) {
V_97 -> V_99 = F_61 ( V_297 ) ;
} else {
V_97 -> V_99 = 15 ;
}
} else if ( V_6 -> V_285 == V_286 ) {
V_97 -> V_99 = 0 ;
V_97 -> V_116 = 1 ;
} else if ( V_6 -> V_285 == V_293 ) {
V_97 -> V_99 = V_6 -> V_295 ;
V_97 -> V_98 = 1 ;
} else {
F_15 ( L_52 ,
V_6 -> V_285 ) ;
}
return 0 ;
#else
return - V_71 ;
#endif
}
static int F_66 ( struct V_2 * V_3 ,
T_2 * V_177 , T_2 V_299 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
struct V_300 V_139 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_140 = F_30 ( V_6 -> V_166 &
V_6 -> V_301 ) ;
V_139 . V_141 = F_30 ( V_103 ) ;
if ( V_177 ) {
if ( V_299 > 32 )
return - V_60 ;
V_139 . V_302 = F_30 ( V_299 ) ;
memcpy ( V_139 . V_303 , V_177 , V_299 ) ;
}
if ( V_6 -> V_40 -> V_117 ( V_3 , V_304 , & V_139 ,
sizeof( V_139 ) ) ) {
F_15 ( V_78 L_53 , V_3 -> V_46 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
struct V_138 V_139 ;
int V_89 = 0 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_140 = F_30 ( V_6 -> V_166 &
V_6 -> V_301 ) ;
V_139 . V_141 = F_30 ( V_103 ) ;
if ( ! V_6 -> V_137 )
F_20 ( V_3 , V_305 ,
V_306 ) ;
if ( V_6 -> V_40 -> V_117 ( V_3 , V_142 , & V_139 ,
sizeof( V_139 ) ) ) {
F_15 ( V_78 L_54 ) ;
V_89 = - V_60 ;
}
if ( ! V_6 -> V_137 )
F_20 ( V_3 , V_305 ,
V_307 ) ;
return V_89 ;
}
static inline int F_66 ( struct V_2 * V_3 ,
T_2 * V_177 , T_2 V_299 )
{
return - V_71 ;
}
static inline int F_67 ( struct V_2 * V_3 )
{
return - V_71 ;
}
static int F_68 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
int V_89 ;
T_2 * V_177 = NULL , V_299 = 0 ;
struct V_308 * V_123 = (struct V_308 * ) V_47 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_110 -> V_72 < sizeof( struct V_308 ) )
V_123 = NULL ;
if ( V_6 -> V_22 == V_23 ) {
V_110 -> V_72 = 0 ;
return 0 ;
}
if ( ! V_6 -> V_309 )
return - V_310 ;
if ( V_123 && V_110 -> V_55 & V_311 ) {
V_177 = V_123 -> V_178 ;
V_299 = V_123 -> V_312 ;
if ( V_299 &&
( ( V_6 -> V_22 != V_79 &&
V_6 -> V_22 != V_189 ) ||
( V_6 -> V_212 < F_49 ( 1 , 3 , 1 ) ) ) )
return - V_71 ;
}
if ( V_6 -> V_212 >= F_49 ( 1 , 3 , 1 ) )
V_89 = F_66 ( V_3 , V_177 , V_299 ) ;
else
V_89 = F_67 ( V_3 ) ;
if ( V_89 == 0 )
V_6 -> V_313 = V_314 ;
return V_89 ;
}
static char * F_69 ( T_1 * V_6 ,
struct V_44 * V_45 ,
struct V_124 * V_315 ,
struct V_316 * V_317 ,
char * V_318 , char * V_319 )
{
int V_48 , V_320 ;
struct V_321 V_322 ;
char * V_323 ;
T_3 V_324 ;
T_2 * V_325 ;
T_2 * V_177 , * V_126 ;
T_5 V_299 ;
char * V_37 ;
if ( V_317 ) {
V_177 = V_317 -> V_177 ;
V_299 = V_317 -> V_299 ;
V_126 = V_317 -> V_126 ;
} else {
V_177 = V_315 -> V_177 ;
V_299 = F_6 ( V_315 -> V_299 ) ;
V_126 = V_315 -> V_126 ;
}
if ( V_299 > 32 )
V_299 = 32 ;
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_230 ;
V_322 . V_150 . V_135 . V_143 = V_144 ;
memcpy ( V_322 . V_150 . V_135 . V_136 , V_126 , V_128 ) ;
V_318 = F_70 ( V_45 , V_318 , V_319 , & V_322 ,
V_326 ) ;
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_327 ;
V_322 . V_150 . V_110 . V_72 = V_299 ;
V_322 . V_150 . V_110 . V_55 = 1 ;
V_318 = F_71 ( V_45 , V_318 , V_319 ,
& V_322 , V_177 ) ;
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_328 ;
if ( V_317 ) {
V_324 = V_317 -> V_329 ;
} else {
V_324 = F_6 ( V_315 -> V_330 ) ;
}
if ( V_324 & ( V_331 |
V_332 ) ) {
if ( V_324 & V_331 )
V_322 . V_150 . V_252 = V_23 ;
else
V_322 . V_150 . V_252 = V_189 ;
V_318 = F_70 ( V_45 , V_318 , V_319 ,
& V_322 , V_333 ) ;
}
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_334 ;
if ( V_315 ) {
V_320 = F_6 ( V_315 -> V_133 ) ;
} else if ( V_317 ) {
V_320 = V_317 -> V_320 ;
} else {
V_320 = 0 ;
}
if ( V_320 > 0 ) {
V_322 . V_150 . V_159 . V_161 = V_162 [ V_320 - 1 ] * 100000 ;
V_322 . V_150 . V_159 . V_160 = 1 ;
V_318 = F_70 ( V_45 , V_318 , V_319 ,
& V_322 , V_335 ) ;
}
if ( V_315 ) {
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_336 ;
if ( V_6 -> V_337 == V_338 ) {
V_322 . V_150 . V_26 . V_31 = F_6 ( V_315 -> V_339 ) ;
V_322 . V_150 . V_26 . V_33 = F_6 ( V_315 -> V_340 ) ;
} else {
V_322 . V_150 . V_26 . V_31 =
F_72 ( F_6 ( V_315 -> V_339 ) ) ;
V_322 . V_150 . V_26 . V_33 =
F_72 ( F_6 ( V_315 -> V_340 ) ) ;
}
V_322 . V_150 . V_26 . V_27 = V_341
| V_342
| V_343
| V_29 ;
V_318 = F_70 ( V_45 , V_318 , V_319 ,
& V_322 , V_344 ) ;
}
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_345 ;
if ( V_324 & V_346 )
V_322 . V_150 . V_110 . V_55 = V_82 | V_347 ;
else
V_322 . V_150 . V_110 . V_55 = V_61 ;
V_322 . V_150 . V_110 . V_72 = 0 ;
V_318 = F_71 ( V_45 , V_318 , V_319 , & V_322 , L_55 ) ;
if ( V_315 ) {
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_348 ;
V_323 = V_318 + F_73 ( V_45 ) ;
V_325 = V_315 -> V_349 ;
for ( V_48 = 0 ; V_48 < sizeof( V_315 -> V_349 ) ; V_48 ++ ) {
if ( V_325 [ V_48 ] == 0 )
break;
V_322 . V_150 . V_221 . V_99 = ( ( V_325 [ V_48 ] & 0x7f ) * 500000 ) ;
V_323 = F_74 (
V_45 , V_318 , V_323 , V_319 , & V_322 ,
V_350 ) ;
}
if ( ( V_323 - V_318 ) > F_73 ( V_45 ) )
V_318 = V_323 ;
}
V_37 = F_27 ( V_351 * 2 + 30 , V_352 ) ;
if ( V_37 && V_315 ) {
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_234 ;
sprintf ( V_37 , L_56 , F_6 ( V_315 -> V_353 ) ) ;
V_322 . V_150 . V_110 . V_72 = strlen ( V_37 ) ;
V_318 = F_71 ( V_45 , V_318 , V_319 ,
& V_322 , V_37 ) ;
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_234 ;
sprintf ( V_37 , L_57 , F_6 ( V_315 -> V_354 ) ) ;
V_322 . V_150 . V_110 . V_72 = strlen ( V_37 ) ;
V_318 = F_71 ( V_45 , V_318 , V_319 ,
& V_322 , V_37 ) ;
if ( V_6 -> V_337 == V_338 &&
( V_324 & V_332 ) ) {
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_234 ;
sprintf ( V_37 , L_58 , F_6 ( V_315 -> V_355 ) ) ;
V_322 . V_150 . V_110 . V_72 = strlen ( V_37 ) ;
V_318 = F_71 ( V_45 , V_318 ,
V_319 , & V_322 , V_37 ) ;
}
}
F_14 ( V_37 ) ;
if ( V_317 && V_317 -> V_356 > 0 && V_317 -> V_356 <= V_351 ) {
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_357 ;
V_322 . V_150 . V_110 . V_72 = V_317 -> V_356 ;
V_318 = F_71 ( V_45 , V_318 , V_319 ,
& V_322 , V_317 -> V_358 ) ;
}
if ( V_317 && V_317 -> V_359 > 0 && V_317 -> V_359 <= V_351 ) {
memset ( & V_322 , 0 , sizeof( V_322 ) ) ;
V_322 . V_248 = V_357 ;
V_322 . V_150 . V_110 . V_72 = V_317 -> V_359 ;
V_318 = F_71 ( V_45 , V_318 , V_319 ,
& V_322 , V_317 -> V_360 ) ;
}
return V_318 ;
}
static inline int F_75 ( T_1 * V_6 ,
struct V_44 * V_45 ,
char * V_361 , int V_362 )
{
struct V_124 * V_315 ;
int V_125 , V_363 ;
char * V_318 = V_361 ;
char * V_319 = V_361 + V_362 ;
struct V_364 * V_365 ;
F_76 ( & V_6 -> V_130 ) ;
F_77 (ptr, &local->bss_list) {
struct V_316 * V_317 ;
V_317 = F_78 ( V_365 , struct V_316 , V_366 ) ;
V_317 -> V_367 = 0 ;
}
V_363 = V_6 -> V_337 == V_338 ;
for ( V_125 = 0 ; V_125 < V_6 -> V_131 ; V_125 ++ ) {
int V_368 = 0 ;
V_315 = & V_6 -> V_132 [ V_125 ] ;
F_77 (ptr, &local->bss_list) {
struct V_316 * V_317 ;
V_317 = F_78 ( V_365 , struct V_316 , V_366 ) ;
if ( memcmp ( V_317 -> V_126 , V_315 -> V_126 , V_128 ) == 0 ) {
V_317 -> V_367 = 1 ;
V_318 = F_69 (
V_6 , V_45 , V_315 , V_317 , V_318 ,
V_319 ) ;
V_368 ++ ;
}
}
if ( ! V_368 ) {
V_318 = F_69 (
V_6 , V_45 , V_315 , NULL , V_318 , V_319 ) ;
}
if ( ( V_319 - V_318 ) <= V_326 ) {
F_79 ( & V_6 -> V_130 ) ;
return - V_369 ;
}
}
F_77 (ptr, &local->bss_list) {
struct V_316 * V_317 ;
V_317 = F_78 ( V_365 , struct V_316 , V_366 ) ;
if ( V_317 -> V_367 )
continue;
V_318 = F_69 ( V_6 , V_45 , NULL , V_317 ,
V_318 , V_319 ) ;
if ( ( V_319 - V_318 ) <= V_326 ) {
F_79 ( & V_6 -> V_130 ) ;
return - V_369 ;
}
}
F_79 ( & V_6 -> V_130 ) ;
return V_318 - V_361 ;
}
static inline int F_80 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_47 )
{
#ifdef F_38
return - V_71 ;
#else
struct V_4 * V_5 ;
T_1 * V_6 ;
int V_370 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_313 &&
F_81 ( V_314 , V_6 -> V_313 + 3 * V_371 ) ) {
return - V_372 ;
}
V_6 -> V_313 = 0 ;
V_370 = F_75 ( V_6 , V_45 , V_47 , V_110 -> V_72 ) ;
if ( V_370 >= 0 ) {
V_110 -> V_72 = V_370 ;
return 0 ;
} else {
V_110 -> V_72 = 0 ;
return V_370 ;
}
#endif
}
static int F_82 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
int V_370 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_22 == V_23 ) {
V_370 = F_83 ( V_3 , V_45 , V_47 ) ;
if ( V_370 >= 0 ) {
F_15 ( V_78 L_59
L_60 , V_370 ) ;
V_110 -> V_72 = V_370 ;
return 0 ;
} else {
F_15 ( V_78
L_61 ,
V_370 ) ;
V_110 -> V_72 = 0 ;
return V_370 ;
}
} else {
return F_80 ( V_3 , V_45 , V_110 , V_47 ) ;
}
}
static int F_84 ( struct V_2 * V_3 , int * V_48 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_40 -> V_248 ( V_3 , V_373 , * V_48 , NULL , NULL ) )
return - V_71 ;
return 0 ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
void * V_374 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
int * V_48 = ( int * ) V_47 ;
int V_375 = * V_48 ;
int V_99 = * ( V_48 + 1 ) ;
int V_89 = 0 ;
T_3 V_39 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
switch ( V_375 ) {
case V_376 :
V_6 -> V_105 = V_99 ;
break;
case V_377 :
if ( F_20 ( V_3 , V_378 , V_99 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
V_89 = - V_60 ;
else
V_6 -> V_379 = V_99 ;
break;
#ifndef F_38
case V_380 :
if ( V_99 == V_6 -> V_381 )
break;
if ( V_99 != 0 && V_99 != 1 ) {
V_89 = - V_60 ;
break;
}
F_15 ( V_78 L_62 ,
V_3 -> V_46 , V_6 -> V_381 , V_99 ) ;
V_6 -> V_381 = V_99 ;
if ( V_6 -> V_22 != V_189 )
break;
if ( F_20 ( V_3 , V_244 ,
F_54 ( V_6 ) ) ) {
V_89 = - V_71 ;
break;
}
if ( V_6 -> V_40 -> V_80 ( V_3 ) )
V_89 = - V_60 ;
break;
#endif
case V_382 :
F_15 ( V_78 L_63 , V_3 -> V_46 ,
V_99 == 0 ? L_64 : L_65 ) ;
V_39 = V_291 ;
V_6 -> V_40 -> V_248 ( V_3 , V_249 |
( V_292 << 8 ) ,
V_99 == 0 ? 0 : 1 , & V_39 , NULL ) ;
break;
case V_383 :
V_6 -> V_384 = V_99 ;
break;
case V_385 :
if ( V_99 < 0 || V_99 > 3 ) {
V_89 = - V_60 ;
break;
}
if ( V_6 -> V_104 != NULL )
V_6 -> V_104 -> V_386 = V_99 ;
break;
case V_387 :
if ( V_99 < 0 || V_99 > 7 * 24 * 60 * 60 ) {
V_89 = - V_60 ;
break;
}
if ( V_6 -> V_104 != NULL )
V_6 -> V_104 -> V_388 = V_99 * V_371 ;
break;
case V_389 :
if ( V_6 -> V_104 != NULL )
V_6 -> V_104 -> V_390 = V_99 ;
break;
case V_391 :
if ( V_99 < 0 || V_99 > 65535 ) {
V_89 = - V_60 ;
break;
}
if ( F_20 ( V_3 , V_392 , V_99 )
|| V_6 -> V_40 -> V_80 ( V_3 ) )
V_89 = - V_60 ;
else
V_6 -> V_393 = V_99 ;
break;
case V_394 :
if ( V_6 -> V_104 != NULL )
V_6 -> V_104 -> V_395 = V_99 ;
break;
case V_396 :
V_6 -> V_397 = V_99 ;
break;
case V_398 :
if ( V_6 -> V_104 != NULL ) {
if ( ! V_6 -> V_104 -> V_399 && V_99 ) {
F_86 ( V_6 ) ;
}
V_6 -> V_104 -> V_399 = V_99 ;
}
break;
case V_400 :
V_6 -> V_401 = V_99 ;
if ( F_87 ( V_6 ) )
V_89 = - V_60 ;
break;
case V_402 :
V_6 -> V_403 = V_99 ;
break;
case V_404 :
V_6 -> V_255 = V_99 ;
if ( F_16 ( V_6 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
V_89 = - V_60 ;
break;
case V_405 :
V_6 -> V_406 = V_99 ;
if ( F_16 ( V_6 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
V_89 = - V_60 ;
break;
#ifndef F_38
case V_407 :
if ( V_99 < 0 || V_99 > 2 ) {
V_89 = - V_60 ;
break;
}
V_6 -> V_137 = V_99 ;
if ( F_88 ( V_6 ) || V_6 -> V_40 -> V_80 ( V_3 ) )
V_89 = - V_60 ;
break;
#endif
case V_408 :
V_6 -> V_409 = V_99 ;
break;
case V_410 :
V_6 -> V_411 = V_99 ;
break;
case V_412 :
if ( V_99 < 0 || V_99 > V_413 ) {
V_89 = - V_60 ;
break;
}
V_6 -> V_414 = V_99 ;
F_89 ( V_6 ) ;
break;
case V_415 :
if ( V_99 < 0 || V_99 > V_413 ) {
V_89 = - V_60 ;
break;
}
V_6 -> V_416 = V_99 ;
F_89 ( V_6 ) ;
break;
case V_417 :
if ( V_99 != V_418 &&
V_99 != V_172 &&
V_99 != V_171 &&
V_99 != V_174 ) {
V_89 = - V_60 ;
break;
}
V_6 -> V_170 = V_99 ;
if ( V_6 -> V_22 == V_254 )
F_45 ( V_6 ) ;
break;
case V_419 :
V_6 -> V_420 = V_99 ;
break;
case V_421 :
{
struct V_300 V_139 ;
T_3 V_354 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
V_139 . V_140 = F_30 ( 0x3fff ) ;
switch ( V_99 ) {
case 1 : V_354 = V_103 ; break;
case 2 : V_354 = V_102 ; break;
case 3 : V_354 = V_101 ; break;
case 4 : V_354 = V_100 ; break;
default: V_354 = V_103 ; break;
}
V_139 . V_141 = F_30 ( V_354 ) ;
if ( V_6 -> V_22 == V_23 ) {
if ( F_20 ( V_3 , V_244 ,
V_422 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
F_15 ( V_78 L_66
L_67 ) ;
}
if ( V_6 -> V_40 -> V_117 ( V_3 , V_304 , & V_139 ,
sizeof( V_139 ) ) ) {
F_15 ( V_78 L_68 ) ;
V_89 = - V_60 ;
}
if ( V_6 -> V_22 == V_23 ) {
T_6 V_423 ;
F_90 ( & V_423 , V_424 ) ;
F_91 ( & V_6 -> V_425 , & V_423 ) ;
F_92 ( V_426 ) ;
F_93 ( V_371 ) ;
if ( F_94 ( V_424 ) )
V_89 = - V_427 ;
F_92 ( V_428 ) ;
F_95 ( & V_6 -> V_425 , & V_423 ) ;
if ( F_20 ( V_3 , V_244 ,
V_429 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
F_15 ( V_78 L_69
L_70 ) ;
}
break;
}
case V_430 :
V_6 -> V_431 = V_99 ;
if ( F_96 ( & V_6 -> V_432 ) )
F_97 ( & V_6 -> V_432 ) ;
if ( V_99 > 0 ) {
V_6 -> V_432 . V_433 = V_314 +
V_6 -> V_431 * V_371 ;
F_98 ( & V_6 -> V_432 ) ;
}
break;
case V_434 :
if ( V_99 < 0 || V_99 > 3 ) {
V_89 = - V_60 ;
break;
}
V_6 -> V_435 = V_99 ;
if ( F_20 ( V_3 , V_436 ,
V_6 -> V_435 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) ) {
F_15 ( V_92 L_71
L_72 , V_3 -> V_46 ) ;
V_89 = - V_71 ;
}
break;
#ifdef F_99
case V_437 :
V_6 -> V_438 = V_99 ;
break;
#endif
case V_439 :
if ( ( V_99 & V_6 -> V_91 ) != V_99 || V_99 == 0 ) {
F_15 ( V_92 L_73
L_74 ,
V_3 -> V_46 ) ;
V_89 = - V_60 ;
break;
}
V_6 -> V_90 = V_99 ;
if ( F_20 ( V_3 , V_93 ,
V_6 -> V_90 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
V_89 = - V_60 ;
break;
case V_440 :
V_6 -> V_91 = V_99 ;
if ( F_19 ( V_3 ) )
V_89 = - V_60 ;
break;
case V_441 :
V_89 = F_100 ( V_6 , V_99 , 1 ) ;
break;
case V_442 :
V_89 = F_101 ( V_6 , V_99 , 1 ) ;
break;
case V_443 :
V_6 -> V_444 = V_99 ;
if ( V_6 -> V_212 < F_49 ( 1 , 7 , 0 ) )
V_89 = - V_71 ;
else if ( F_20 ( V_3 , V_445 ,
V_99 ? 1 : 0 ) )
V_89 = - V_60 ;
break;
case V_446 :
V_6 -> V_447 = V_99 ;
if ( F_16 ( V_6 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
V_89 = - V_60 ;
break;
case V_448 :
V_6 -> V_449 = V_99 ;
break;
case V_450 :
V_6 -> V_451 = V_99 ;
break;
case V_452 :
V_6 -> V_301 = V_99 ;
break;
default:
F_15 ( V_78 L_75 ,
V_3 -> V_46 , V_375 ) ;
V_89 = - V_71 ;
break;
}
return V_89 ;
}
static int F_102 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
void * V_374 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
int * V_375 = ( int * ) V_47 ;
int V_89 = 0 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
switch ( * V_375 ) {
case V_376 :
* V_375 = V_6 -> V_105 ;
break;
case V_377 :
* V_375 = V_6 -> V_379 ;
break;
case V_380 :
* V_375 = V_6 -> V_381 ;
break;
case V_382 :
V_89 = - V_71 ;
break;
case V_383 :
* V_375 = V_6 -> V_384 ;
break;
case V_385 :
if ( V_6 -> V_104 != NULL )
* V_375 = V_6 -> V_104 -> V_386 ;
else
V_89 = - V_71 ;
break;
case V_387 :
if ( V_6 -> V_104 != NULL )
* V_375 = V_6 -> V_104 -> V_388 / V_371 ;
else
V_89 = - V_71 ;
break;
case V_389 :
if ( V_6 -> V_104 != NULL )
* V_375 = V_6 -> V_104 -> V_390 ;
else
V_89 = - V_71 ;
break;
case V_391 :
* V_375 = V_6 -> V_393 ;
break;
case V_394 :
if ( V_6 -> V_104 != NULL )
* V_375 = V_6 -> V_104 -> V_395 ;
else
V_89 = - V_71 ;
break;
case V_396 :
* V_375 = V_6 -> V_397 ;
break;
case V_398 :
if ( V_6 -> V_104 != NULL )
* V_375 = V_6 -> V_104 -> V_399 ;
else
V_89 = - V_71 ;
break;
case V_400 :
* V_375 = V_6 -> V_401 ;
break;
case V_402 :
* V_375 = V_6 -> V_403 ;
break;
case V_404 :
* V_375 = V_6 -> V_255 ;
break;
case V_405 :
* V_375 = V_6 -> V_406 ;
break;
case V_407 :
* V_375 = V_6 -> V_137 ;
break;
case V_408 :
* V_375 = V_6 -> V_409 ;
break;
case V_410 :
* V_375 = V_6 -> V_411 ;
break;
case V_412 :
* V_375 = V_6 -> V_414 ;
break;
case V_415 :
* V_375 = V_6 -> V_416 ;
break;
case V_417 :
* V_375 = V_6 -> V_170 ;
break;
case V_419 :
* V_375 = V_6 -> V_420 ;
break;
case V_421 :
V_89 = - V_71 ;
break;
case V_430 :
* V_375 = V_6 -> V_431 ;
break;
case V_434 :
* V_375 = V_6 -> V_435 ;
break;
#ifdef F_99
case V_437 :
* V_375 = V_6 -> V_438 ;
break;
#endif
case V_439 :
* V_375 = V_6 -> V_90 ;
break;
case V_440 :
* V_375 = V_6 -> V_91 ;
break;
case V_441 :
* V_375 = V_6 -> V_453 ;
break;
case V_442 :
* V_375 = V_6 -> V_454 ;
break;
case V_443 :
if ( V_6 -> V_212 < F_49 ( 1 , 7 , 0 ) )
V_89 = - V_71 ;
* V_375 = V_6 -> V_444 ;
break;
case V_446 :
* V_375 = V_6 -> V_447 ;
break;
case V_448 :
* V_375 = V_6 -> V_449 ;
break;
case V_450 :
* V_375 = V_6 -> V_451 ;
break;
case V_452 :
* V_375 = V_6 -> V_301 ;
break;
default:
F_15 ( V_78 L_76 ,
V_3 -> V_46 , * V_375 ) ;
V_89 = - V_71 ;
break;
}
return V_89 ;
}
static int F_103 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
void * V_374 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
T_3 V_297 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
if ( V_6 -> V_40 -> V_248 ( V_3 , V_298 , * V_47 , NULL ,
& V_297 ) )
return - V_71 ;
else
* V_47 = V_297 ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
void * V_374 , char * V_47 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
T_3 V_455 , V_39 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
V_455 = * V_47 ;
V_39 = * ( V_47 + 1 ) ;
if ( V_6 -> V_40 -> V_248 ( V_3 , V_287 , V_455 , & V_39 , NULL ) )
return - V_71 ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 , int * V_48 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
int V_89 = 0 ;
T_7 V_252 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
F_15 ( V_78 L_77
L_78 ,
V_3 -> V_46 , F_106 ( V_424 ) , V_424 -> V_456 ) ;
if ( * V_48 == 0 ) {
V_252 = V_23 ;
V_89 = F_53 ( V_3 , NULL , & V_252 , NULL ) ;
} else if ( * V_48 == 1 ) {
V_89 = - V_71 ;
} else if ( * V_48 == 2 || * V_48 == 3 ) {
switch ( * V_48 ) {
case 2 :
V_6 -> V_170 = V_418 ;
break;
case 3 :
V_6 -> V_170 = V_171 ;
break;
}
V_252 = V_254 ;
V_89 = F_53 ( V_3 , NULL , & V_252 , NULL ) ;
F_51 ( V_6 ) ;
} else
V_89 = - V_60 ;
return V_89 ;
}
static int F_107 ( struct V_2 * V_3 , int * V_48 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
F_15 ( V_78 L_79 , V_3 -> V_46 , * V_48 ) ;
switch ( * V_48 ) {
case 0 :
V_6 -> V_40 -> V_457 ( V_3 , 1 ) ;
V_6 -> V_40 -> V_458 ( V_3 , 0 ) ;
break;
case 1 :
V_6 -> V_40 -> V_459 ( V_3 ) ;
break;
case 2 :
V_6 -> V_40 -> V_80 ( V_3 ) ;
break;
case 3 :
F_108 ( V_6 , V_460 ) ;
if ( V_6 -> V_40 -> V_248 ( V_3 , V_461 , 0 , NULL ,
NULL ) )
return - V_60 ;
break;
case 4 :
if ( V_6 -> V_40 -> V_248 ( V_3 , V_462 , 0 , NULL ,
NULL ) )
return - V_60 ;
break;
default:
F_15 ( V_78 L_80 , * V_48 ) ;
return - V_71 ;
}
return 0 ;
}
static int F_109 ( struct V_2 * V_3 , int * V_48 )
{
int V_463 = * V_48 ;
int V_99 = * ( V_48 + 1 ) ;
F_15 ( V_78 L_81 , V_3 -> V_46 , V_463 , V_99 ) ;
if ( F_20 ( V_3 , V_463 , V_99 ) )
return - V_60 ;
return 0 ;
}
static int F_110 ( T_1 * V_6 , int * V_248 )
{
int V_89 = 0 ;
switch ( * V_248 ) {
case V_464 :
V_6 -> V_104 -> V_465 . V_466 = V_467 ;
break;
case V_468 :
V_6 -> V_104 -> V_465 . V_466 = V_469 ;
break;
case V_470 :
V_6 -> V_104 -> V_465 . V_466 = V_471 ;
break;
case V_472 :
F_111 ( & V_6 -> V_104 -> V_465 ) ;
break;
case V_473 :
F_112 ( V_6 -> V_104 ) ;
F_113 ( V_6 -> V_3 , V_6 -> V_104 , 0 ) ;
break;
default:
V_89 = - V_71 ;
break;
}
return V_89 ;
}
static int F_114 ( T_1 * V_6 , struct V_50 * V_474 )
{
struct V_475 * V_375 ;
int V_89 = 0 ;
if ( V_474 -> V_72 < sizeof( struct V_475 ) ||
V_474 -> V_72 > 1024 || ! V_474 -> V_476 )
return - V_60 ;
V_375 = F_27 ( V_474 -> V_72 , V_65 ) ;
if ( V_375 == NULL )
return - V_66 ;
if ( F_115 ( V_375 , V_474 -> V_476 , V_474 -> V_72 ) ) {
V_89 = - V_477 ;
goto V_478;
}
if ( V_474 -> V_72 < sizeof( struct V_475 ) +
V_375 -> V_479 * sizeof( struct V_480 ) ) {
V_89 = - V_60 ;
goto V_478;
}
V_89 = V_6 -> V_40 -> V_481 ( V_6 , V_375 ) ;
V_478:
F_14 ( V_375 ) ;
return V_89 ;
}
static int F_116 ( struct V_2 * V_3 , T_2 * V_482 ,
T_5 V_38 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 * V_6 = V_5 -> V_6 ;
T_2 * V_37 ;
V_37 = F_27 ( V_38 + 2 , V_65 ) ;
if ( V_37 == NULL )
return - V_66 ;
* ( ( V_43 * ) V_37 ) = F_30 ( V_38 ) ;
memcpy ( V_37 + 2 , V_482 , V_38 ) ;
F_14 ( V_6 -> V_483 ) ;
V_6 -> V_483 = V_37 ;
V_6 -> V_484 = V_38 + 2 ;
return V_6 -> V_40 -> V_117 ( V_6 -> V_3 , V_485 ,
V_37 , V_38 + 2 ) ;
}
static int F_117 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_110 , char * V_47 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 * V_6 = V_5 -> V_6 ;
switch ( V_110 -> V_55 & V_486 ) {
case V_487 :
case V_488 :
case V_489 :
case V_490 :
break;
case V_491 :
V_6 -> V_449 = V_110 -> V_99 ;
break;
case V_492 :
V_6 -> V_451 = V_110 -> V_99 ;
break;
case V_493 :
V_6 -> V_401 = V_110 -> V_99 ;
break;
case V_494 :
if ( V_110 -> V_99 == 0 ) {
V_6 -> V_444 = 0 ;
if ( V_6 -> V_212 < F_49 ( 1 , 7 , 0 ) )
break;
F_116 ( V_3 , L_55 , 0 ) ;
V_6 -> V_137 = 0 ;
V_6 -> V_447 = 0 ;
if ( F_20 ( V_3 , V_445 ,
0 ) ||
F_88 ( V_6 ) ||
F_16 ( V_6 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
return - V_60 ;
break;
}
if ( V_6 -> V_212 < F_49 ( 1 , 7 , 0 ) )
return - V_71 ;
V_6 -> V_137 = 2 ;
V_6 -> V_447 = 1 ;
V_6 -> V_444 = 1 ;
if ( F_20 ( V_3 , V_445 , 1 ) ||
F_88 ( V_6 ) ||
F_16 ( V_6 ) ||
V_6 -> V_40 -> V_80 ( V_3 ) )
return - V_60 ;
break;
case V_495 :
V_6 -> V_411 = V_110 -> V_99 ;
break;
case V_496 :
V_6 -> V_447 = V_110 -> V_99 ;
break;
default:
return - V_71 ;
}
return 0 ;
}
static int F_118 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_96 * V_110 , char * V_47 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 * V_6 = V_5 -> V_6 ;
switch ( V_110 -> V_55 & V_486 ) {
case V_487 :
case V_488 :
case V_489 :
case V_490 :
return - V_71 ;
case V_491 :
V_110 -> V_99 = V_6 -> V_449 ;
break;
case V_492 :
V_110 -> V_99 = V_6 -> V_451 ;
break;
case V_493 :
V_110 -> V_99 = V_6 -> V_401 ;
break;
case V_494 :
V_110 -> V_99 = V_6 -> V_444 ;
break;
case V_495 :
V_110 -> V_99 = V_6 -> V_411 ;
break;
default:
return - V_71 ;
}
return 0 ;
}
static int F_119 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_51 , char * V_47 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 * V_6 = V_5 -> V_6 ;
struct V_497 * V_498 = (struct V_497 * ) V_47 ;
int V_48 , V_89 = 0 ;
struct V_499 * V_63 ;
struct V_53 * * V_54 ;
void * V_500 ;
T_2 * V_112 ;
const char * V_501 , * V_502 ;
V_48 = V_51 -> V_55 & V_56 ;
if ( V_48 > V_59 )
return - V_60 ;
if ( V_48 < 1 || V_48 > V_59 )
V_48 = V_6 -> V_57 . V_58 ;
else
V_48 -- ;
if ( V_48 < 0 || V_48 >= V_59 )
return - V_60 ;
V_112 = V_498 -> V_112 . V_136 ;
if ( V_112 [ 0 ] == 0xff && V_112 [ 1 ] == 0xff && V_112 [ 2 ] == 0xff &&
V_112 [ 3 ] == 0xff && V_112 [ 4 ] == 0xff && V_112 [ 5 ] == 0xff ) {
V_500 = NULL ;
V_54 = & V_6 -> V_57 . V_54 [ V_48 ] ;
} else {
if ( V_48 != 0 )
return - V_60 ;
V_500 = F_120 ( V_6 -> V_104 , V_112 , 0 , & V_54 ) ;
if ( V_500 == NULL ) {
if ( V_6 -> V_22 == V_79 ) {
V_48 = 0 ;
V_54 = & V_6 -> V_57 . V_54 [ V_48 ] ;
} else
return - V_60 ;
}
}
if ( ( V_51 -> V_55 & V_61 ) ||
V_498 -> V_501 == V_503 ) {
if ( * V_54 )
F_9 ( & V_6 -> V_57 , V_54 ) ;
goto V_62;
}
switch ( V_498 -> V_501 ) {
case V_504 :
V_501 = L_3 ;
V_502 = L_4 ;
break;
case V_505 :
V_501 = L_82 ;
V_502 = L_83 ;
break;
case V_506 :
V_501 = L_84 ;
V_502 = L_85 ;
break;
default:
F_15 ( V_78 L_86 ,
V_6 -> V_3 -> V_46 , V_498 -> V_501 ) ;
V_89 = - V_71 ;
goto V_62;
}
V_63 = F_11 ( V_501 ) ;
if ( V_63 == NULL ) {
F_12 ( V_502 ) ;
V_63 = F_11 ( V_501 ) ;
}
if ( V_63 == NULL ) {
F_15 ( V_78 L_87 ,
V_6 -> V_3 -> V_46 , V_501 ) ;
V_89 = - V_71 ;
goto V_62;
}
if ( V_500 || V_498 -> V_501 != V_504 ) {
V_6 -> V_406 = V_6 -> V_255 = 1 ;
}
if ( * V_54 == NULL || ( * V_54 ) -> V_63 != V_63 ) {
struct V_53 * V_64 ;
F_9 ( & V_6 -> V_57 , V_54 ) ;
V_64 = F_10 ( sizeof( struct V_53 ) ,
V_65 ) ;
if ( V_64 == NULL ) {
V_89 = - V_66 ;
goto V_62;
}
V_64 -> V_63 = V_63 ;
if ( V_64 -> V_63 && F_13 ( V_64 -> V_63 -> V_67 ) )
V_64 -> V_68 = V_64 -> V_63 -> V_69 ( V_48 ) ;
if ( V_64 -> V_68 == NULL ) {
F_14 ( V_64 ) ;
V_89 = - V_60 ;
goto V_62;
}
* V_54 = V_64 ;
}
if ( ( ! ( V_498 -> V_507 & V_508 ) || V_498 -> V_509 > 0 )
&& ( * V_54 ) -> V_63 -> V_75 &&
( * V_54 ) -> V_63 -> V_75 ( V_498 -> V_81 , V_498 -> V_509 , V_498 -> V_510 ,
( * V_54 ) -> V_68 ) < 0 ) {
F_15 ( V_78 L_88 ,
V_6 -> V_3 -> V_46 ) ;
V_89 = - V_60 ;
goto V_62;
}
if ( V_498 -> V_507 & V_508 ) {
if ( ! V_500 )
V_6 -> V_57 . V_58 = V_48 ;
}
if ( V_500 == NULL && V_498 -> V_509 > 0 ) {
int V_73 = 1 , V_74 ;
for ( V_74 = 0 ; V_74 < V_59 ; V_74 ++ ) {
if ( V_74 != V_48 && V_6 -> V_57 . V_54 [ V_74 ] ) {
V_73 = 0 ;
break;
}
}
if ( V_73 )
V_6 -> V_57 . V_58 = V_48 ;
}
V_62:
if ( V_500 )
F_121 ( V_500 ) ;
V_6 -> V_76 = V_51 -> V_55 & V_77 ;
if ( V_89 == 0 &&
( F_16 ( V_6 ) ||
( V_6 -> V_22 != V_79 &&
V_6 -> V_40 -> V_80 ( V_6 -> V_3 ) ) ) )
V_89 = - V_60 ;
return V_89 ;
}
static int F_122 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_51 , char * V_47 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 * V_6 = V_5 -> V_6 ;
struct V_53 * * V_54 ;
void * V_500 ;
int V_511 , V_48 ;
struct V_497 * V_498 = (struct V_497 * ) V_47 ;
T_2 * V_112 ;
V_511 = V_51 -> V_72 - sizeof( * V_498 ) ;
if ( V_511 < 0 )
return - V_60 ;
V_48 = V_51 -> V_55 & V_56 ;
if ( V_48 < 1 || V_48 > V_59 )
V_48 = V_6 -> V_57 . V_58 ;
else
V_48 -- ;
V_112 = V_498 -> V_112 . V_136 ;
if ( V_112 [ 0 ] == 0xff && V_112 [ 1 ] == 0xff && V_112 [ 2 ] == 0xff &&
V_112 [ 3 ] == 0xff && V_112 [ 4 ] == 0xff && V_112 [ 5 ] == 0xff ) {
V_500 = NULL ;
V_54 = & V_6 -> V_57 . V_54 [ V_48 ] ;
} else {
V_48 = 0 ;
V_500 = F_120 ( V_6 -> V_104 , V_112 , 0 , & V_54 ) ;
if ( V_500 == NULL )
return - V_60 ;
}
V_51 -> V_55 = V_48 + 1 ;
memset ( V_498 , 0 , sizeof( * V_498 ) ) ;
if ( * V_54 == NULL || ( * V_54 ) -> V_63 == NULL ) {
V_498 -> V_501 = V_503 ;
V_498 -> V_509 = 0 ;
V_51 -> V_55 |= V_61 ;
} else {
if ( strcmp ( ( * V_54 ) -> V_63 -> V_46 , L_3 ) == 0 )
V_498 -> V_501 = V_504 ;
else if ( strcmp ( ( * V_54 ) -> V_63 -> V_46 , L_82 ) == 0 )
V_498 -> V_501 = V_505 ;
else if ( strcmp ( ( * V_54 ) -> V_63 -> V_46 , L_84 ) == 0 )
V_498 -> V_501 = V_506 ;
else
return - V_60 ;
if ( ( * V_54 ) -> V_63 -> V_83 ) {
V_498 -> V_509 =
( * V_54 ) -> V_63 -> V_83 ( V_498 -> V_81 ,
V_511 ,
V_498 -> V_512 ,
( * V_54 ) -> V_68 ) ;
if ( V_498 -> V_509 &&
( V_498 -> V_501 == V_505 ||
V_498 -> V_501 == V_506 ) )
V_498 -> V_507 |= V_513 ;
}
}
if ( V_500 )
F_121 ( V_500 ) ;
return 0 ;
}
static int F_123 ( T_1 * V_6 ,
struct V_514 * V_375 ,
int V_515 )
{
int V_89 = 0 ;
struct V_499 * V_63 ;
struct V_53 * * V_54 ;
void * V_500 ;
V_375 -> V_150 . V_54 . V_516 = 0 ;
V_375 -> V_150 . V_54 . V_501 [ V_517 - 1 ] = '\0' ;
if ( V_515 !=
( int ) ( ( char * ) V_375 -> V_150 . V_54 . V_81 - ( char * ) V_375 ) +
V_375 -> V_150 . V_54 . V_509 )
return - V_60 ;
if ( V_375 -> V_518 [ 0 ] == 0xff && V_375 -> V_518 [ 1 ] == 0xff &&
V_375 -> V_518 [ 2 ] == 0xff && V_375 -> V_518 [ 3 ] == 0xff &&
V_375 -> V_518 [ 4 ] == 0xff && V_375 -> V_518 [ 5 ] == 0xff ) {
if ( V_375 -> V_150 . V_54 . V_519 >= V_59 )
return - V_60 ;
V_500 = NULL ;
V_54 = & V_6 -> V_57 . V_54 [ V_375 -> V_150 . V_54 . V_519 ] ;
} else {
if ( V_375 -> V_150 . V_54 . V_519 )
return - V_60 ;
V_500 = F_120 (
V_6 -> V_104 , V_375 -> V_518 ,
( V_375 -> V_150 . V_54 . V_55 & V_520 ) ,
& V_54 ) ;
if ( V_500 == NULL ) {
V_375 -> V_150 . V_54 . V_516 = V_521 ;
return - V_60 ;
}
}
if ( strcmp ( V_375 -> V_150 . V_54 . V_501 , L_89 ) == 0 ) {
if ( V_54 )
F_9 ( & V_6 -> V_57 , V_54 ) ;
goto V_62;
}
V_63 = F_11 ( V_375 -> V_150 . V_54 . V_501 ) ;
if ( V_63 == NULL && strcmp ( V_375 -> V_150 . V_54 . V_501 , L_3 ) == 0 ) {
F_12 ( L_4 ) ;
V_63 = F_11 ( V_375 -> V_150 . V_54 . V_501 ) ;
} else if ( V_63 == NULL && strcmp ( V_375 -> V_150 . V_54 . V_501 , L_82 ) == 0 ) {
F_12 ( L_83 ) ;
V_63 = F_11 ( V_375 -> V_150 . V_54 . V_501 ) ;
} else if ( V_63 == NULL && strcmp ( V_375 -> V_150 . V_54 . V_501 , L_84 ) == 0 ) {
F_12 ( L_85 ) ;
V_63 = F_11 ( V_375 -> V_150 . V_54 . V_501 ) ;
}
if ( V_63 == NULL ) {
F_15 ( V_78 L_87 ,
V_6 -> V_3 -> V_46 , V_375 -> V_150 . V_54 . V_501 ) ;
V_375 -> V_150 . V_54 . V_516 = V_522 ;
V_89 = - V_60 ;
goto V_62;
}
V_6 -> V_406 = V_6 -> V_255 = 1 ;
if ( * V_54 == NULL || ( * V_54 ) -> V_63 != V_63 ) {
struct V_53 * V_64 ;
F_9 ( & V_6 -> V_57 , V_54 ) ;
V_64 = F_10 ( sizeof( struct V_53 ) ,
V_65 ) ;
if ( V_64 == NULL ) {
V_89 = - V_66 ;
goto V_62;
}
V_64 -> V_63 = V_63 ;
V_64 -> V_68 = V_64 -> V_63 -> V_69 ( V_375 -> V_150 . V_54 . V_519 ) ;
if ( V_64 -> V_68 == NULL ) {
F_14 ( V_64 ) ;
V_375 -> V_150 . V_54 . V_516 =
V_523 ;
V_89 = - V_60 ;
goto V_62;
}
* V_54 = V_64 ;
}
if ( ( ! ( V_375 -> V_150 . V_54 . V_55 & V_524 ) ||
V_375 -> V_150 . V_54 . V_509 > 0 ) && ( * V_54 ) -> V_63 -> V_75 &&
( * V_54 ) -> V_63 -> V_75 ( V_375 -> V_150 . V_54 . V_81 ,
V_375 -> V_150 . V_54 . V_509 , V_375 -> V_150 . V_54 . V_525 ,
( * V_54 ) -> V_68 ) < 0 ) {
F_15 ( V_78 L_88 ,
V_6 -> V_3 -> V_46 ) ;
V_375 -> V_150 . V_54 . V_516 = V_526 ;
V_89 = - V_60 ;
goto V_62;
}
if ( V_375 -> V_150 . V_54 . V_55 & V_524 ) {
if ( ! V_500 )
V_6 -> V_57 . V_58 = V_375 -> V_150 . V_54 . V_519 ;
else if ( V_375 -> V_150 . V_54 . V_519 ) {
F_15 ( V_78 L_90 ,
V_6 -> V_3 -> V_46 ) ;
V_375 -> V_150 . V_54 . V_516 =
V_527 ;
V_89 = - V_60 ;
goto V_62;
}
}
V_62:
if ( V_500 )
F_121 ( V_500 ) ;
if ( V_89 == 0 &&
( F_16 ( V_6 ) ||
( V_6 -> V_22 != V_79 &&
V_6 -> V_40 -> V_80 ( V_6 -> V_3 ) ) ) ) {
V_375 -> V_150 . V_54 . V_516 = V_528 ;
return - V_60 ;
}
return V_89 ;
}
static int F_124 ( T_1 * V_6 ,
struct V_514 * V_375 ,
int V_515 )
{
struct V_53 * * V_54 ;
void * V_500 ;
int V_511 ;
V_375 -> V_150 . V_54 . V_516 = 0 ;
V_511 = V_515 -
( int ) ( ( char * ) V_375 -> V_150 . V_54 . V_81 - ( char * ) V_375 ) ;
if ( V_511 < 0 )
return - V_60 ;
if ( V_375 -> V_518 [ 0 ] == 0xff && V_375 -> V_518 [ 1 ] == 0xff &&
V_375 -> V_518 [ 2 ] == 0xff && V_375 -> V_518 [ 3 ] == 0xff &&
V_375 -> V_518 [ 4 ] == 0xff && V_375 -> V_518 [ 5 ] == 0xff ) {
V_500 = NULL ;
if ( V_375 -> V_150 . V_54 . V_519 >= V_59 )
V_375 -> V_150 . V_54 . V_519 = V_6 -> V_57 . V_58 ;
V_54 = & V_6 -> V_57 . V_54 [ V_375 -> V_150 . V_54 . V_519 ] ;
} else {
V_375 -> V_150 . V_54 . V_519 = 0 ;
V_500 = F_120 ( V_6 -> V_104 , V_375 -> V_518 , 0 ,
& V_54 ) ;
if ( V_500 == NULL ) {
V_375 -> V_150 . V_54 . V_516 = V_521 ;
return - V_60 ;
}
}
if ( * V_54 == NULL || ( * V_54 ) -> V_63 == NULL ) {
memcpy ( V_375 -> V_150 . V_54 . V_501 , L_89 , 5 ) ;
V_375 -> V_150 . V_54 . V_509 = 0 ;
V_375 -> V_150 . V_54 . V_519 = 0xff ;
} else {
strncpy ( V_375 -> V_150 . V_54 . V_501 , ( * V_54 ) -> V_63 -> V_46 ,
V_517 ) ;
V_375 -> V_150 . V_54 . V_509 = 0 ;
memset ( V_375 -> V_150 . V_54 . V_525 , 0 , 8 ) ;
if ( ( * V_54 ) -> V_63 -> V_83 ) {
V_375 -> V_150 . V_54 . V_509 =
( * V_54 ) -> V_63 -> V_83 ( V_375 -> V_150 . V_54 . V_81 ,
V_511 ,
V_375 -> V_150 . V_54 . V_525 ,
( * V_54 ) -> V_68 ) ;
}
}
if ( V_500 )
F_121 ( V_500 ) ;
return 0 ;
}
static int F_125 ( T_1 * V_6 ,
struct V_514 * V_375 ,
int V_515 )
{
int V_529 , V_370 ;
V_529 = V_515 - V_530 ;
if ( V_529 < 0 )
return - V_60 ;
V_370 = V_6 -> V_40 -> V_41 ( V_6 -> V_3 , V_375 -> V_150 . V_463 . V_463 ,
V_375 -> V_150 . V_463 . V_110 , V_375 -> V_150 . V_463 . V_38 , 0 ) ;
if ( V_370 >= 0 ) {
V_375 -> V_150 . V_463 . V_38 = V_370 ;
return 0 ;
}
return V_370 ;
}
static int F_126 ( T_1 * V_6 ,
struct V_514 * V_375 ,
int V_515 )
{
int V_529 ;
V_529 = V_515 - V_530 ;
if ( V_529 < 0 || V_529 < V_375 -> V_150 . V_463 . V_38 )
return - V_60 ;
return V_6 -> V_40 -> V_117 ( V_6 -> V_3 , V_375 -> V_150 . V_463 . V_463 ,
V_375 -> V_150 . V_463 . V_110 , V_375 -> V_150 . V_463 . V_38 ) ;
}
static int F_127 ( T_1 * V_6 ,
struct V_514 * V_375 ,
int V_515 )
{
F_15 ( V_78 L_91 ,
V_6 -> V_3 -> V_46 , V_375 -> V_518 ) ;
memcpy ( V_6 -> V_148 , V_375 -> V_518 , V_128 ) ;
return 0 ;
}
static int F_128 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_47 )
{
return F_116 ( V_3 , V_47 , V_110 -> V_72 ) ;
}
static int F_129 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_47 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 * V_6 = V_5 -> V_6 ;
int V_38 = V_6 -> V_484 - 2 ;
if ( V_38 <= 0 || V_6 -> V_483 == NULL ) {
V_110 -> V_72 = 0 ;
return 0 ;
}
if ( V_110 -> V_72 < V_38 )
return - V_369 ;
V_110 -> V_72 = V_38 ;
memcpy ( V_47 , V_6 -> V_483 + 2 , V_38 ) ;
return 0 ;
}
static int F_130 ( T_1 * V_6 ,
struct V_514 * V_375 ,
int V_515 )
{
int V_529 , V_38 ;
V_38 = V_375 -> V_150 . V_483 . V_38 ;
V_529 = V_515 - V_531 ;
if ( V_529 < 0 || V_529 < V_38 )
return - V_60 ;
return F_116 ( V_6 -> V_3 ,
V_375 -> V_150 . V_483 . V_110 , V_38 ) ;
}
static int F_131 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
struct V_50 * V_110 , char * V_47 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
T_1 * V_6 = V_5 -> V_6 ;
struct V_532 * V_533 = (struct V_532 * ) V_47 ;
V_43 V_534 ;
V_534 = F_30 ( V_533 -> V_535 ) ;
switch ( V_533 -> V_248 ) {
case V_536 :
return F_132 ( V_6 , V_533 -> V_112 . V_136 ,
V_537 ,
( T_2 * ) & V_534 , 2 ) ;
case V_538 :
return F_132 ( V_6 , V_533 -> V_112 . V_136 ,
V_539 ,
( T_2 * ) & V_534 , 2 ) ;
default:
return - V_71 ;
}
}
static int F_133 ( T_1 * V_6 ,
struct V_514 * V_375 )
{
V_43 V_534 ;
V_534 = F_30 ( V_375 -> V_150 . V_533 . V_535 ) ;
switch ( V_375 -> V_150 . V_533 . V_248 ) {
case V_540 :
return F_132 ( V_6 , V_375 -> V_518 ,
V_537 ,
( T_2 * ) & V_534 , 2 ) ;
case V_541 :
return F_132 ( V_6 , V_375 -> V_518 ,
V_539 ,
( T_2 * ) & V_534 , 2 ) ;
default:
return - V_71 ;
}
}
static int F_134 ( T_1 * V_6 ,
struct V_514 * V_375 )
{
#ifndef F_38
if ( ( V_6 -> V_22 != V_79 &&
V_6 -> V_22 != V_189 ) ||
( V_6 -> V_212 < F_49 ( 1 , 3 , 1 ) ) )
return - V_71 ;
if ( ! V_6 -> V_309 )
return - V_310 ;
return F_66 ( V_6 -> V_3 , V_375 -> V_150 . V_139 . V_177 ,
V_375 -> V_150 . V_139 . V_299 ) ;
#else
return - V_71 ;
#endif
}
static int F_135 ( T_1 * V_6 , struct V_50 * V_474 )
{
struct V_514 * V_375 ;
int V_89 = 0 ;
int V_542 = 0 ;
if ( V_474 -> V_72 < sizeof( struct V_514 ) ||
V_474 -> V_72 > V_543 || ! V_474 -> V_476 )
return - V_60 ;
V_375 = F_27 ( V_474 -> V_72 , V_65 ) ;
if ( V_375 == NULL )
return - V_66 ;
if ( F_115 ( V_375 , V_474 -> V_476 , V_474 -> V_72 ) ) {
V_89 = - V_477 ;
goto V_478;
}
switch ( V_375 -> V_248 ) {
case V_544 :
V_89 = F_123 ( V_6 , V_375 , V_474 -> V_72 ) ;
break;
case V_545 :
V_89 = F_124 ( V_6 , V_375 , V_474 -> V_72 ) ;
break;
case V_546 :
V_89 = F_125 ( V_6 , V_375 , V_474 -> V_72 ) ;
break;
case V_547 :
V_89 = F_126 ( V_6 , V_375 , V_474 -> V_72 ) ;
break;
case V_548 :
V_89 = F_127 ( V_6 , V_375 , V_474 -> V_72 ) ;
break;
case V_549 :
V_89 = F_130 ( V_6 , V_375 ,
V_474 -> V_72 ) ;
break;
case V_550 :
V_89 = F_133 ( V_6 , V_375 ) ;
break;
case V_551 :
V_89 = F_134 ( V_6 , V_375 ) ;
break;
default:
V_89 = F_136 ( V_6 -> V_104 , V_375 ) ;
V_542 = 1 ;
break;
}
if ( V_89 == 1 || ! V_542 ) {
if ( F_137 ( V_474 -> V_476 , V_375 , V_474 -> V_72 ) ) {
V_89 = - V_477 ;
goto V_478;
} else if ( V_542 )
V_89 = 0 ;
}
V_478:
F_14 ( V_375 ) ;
return V_89 ;
}
static void F_138 ( struct V_2 * V_3 ,
struct V_552 * V_45 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
F_139 ( V_45 -> V_553 , L_92 , sizeof( V_45 -> V_553 ) ) ;
snprintf ( V_45 -> V_554 , sizeof( V_45 -> V_554 ) ,
L_93 , ( V_6 -> V_212 >> 16 ) & 0xff ,
( V_6 -> V_212 >> 8 ) & 0xff ,
V_6 -> V_212 & 0xff ) ;
}
int F_140 ( struct V_2 * V_3 , struct V_555 * V_556 , int V_248 )
{
struct V_557 * V_257 = (struct V_557 * ) V_556 ;
struct V_4 * V_5 ;
T_1 * V_6 ;
int V_89 = 0 ;
V_5 = F_2 ( V_3 ) ;
V_6 = V_5 -> V_6 ;
switch ( V_248 ) {
case V_558 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_84 ( V_3 , ( int * ) V_257 -> V_150 . V_46 ) ;
break;
case V_561 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_105 ( V_3 , ( int * ) V_257 -> V_150 . V_46 ) ;
break;
case V_562 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_107 ( V_3 , ( int * ) V_257 -> V_150 . V_46 ) ;
break;
case V_563 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_142 ( V_6 , V_257 -> V_150 . V_135 . V_136 , 1 ) ;
break;
case V_564 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_143 ( V_6 , V_257 -> V_150 . V_135 . V_136 , 1 , 0 ) ;
break;
case V_565 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_109 ( V_3 ,
( int * ) V_257 -> V_150 . V_46 ) ;
break;
#ifndef F_144
case V_566 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_110 ( V_6 , ( int * ) V_257 -> V_150 . V_46 ) ;
break;
case V_567 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_145 ( & V_6 -> V_104 -> V_465 ,
V_257 -> V_150 . V_135 . V_136 ) ;
break;
case V_568 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_146 ( & V_6 -> V_104 -> V_465 ,
V_257 -> V_150 . V_135 . V_136 ) ;
break;
case V_569 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_147 ( V_6 -> V_104 , V_6 -> V_3 ,
V_257 -> V_150 . V_135 . V_136 ) ;
break;
#endif
#ifdef F_148
case V_570 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_114 ( V_6 , & V_257 -> V_150 . V_110 ) ;
break;
#endif
case V_571 :
if ( ! F_141 ( V_559 ) ) V_89 = - V_560 ;
else V_89 = F_135 ( V_6 , & V_257 -> V_150 . V_110 ) ;
break;
default:
V_89 = - V_71 ;
break;
}
return V_89 ;
}
