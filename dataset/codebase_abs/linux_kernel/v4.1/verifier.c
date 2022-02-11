static void F_1 ( const char * V_1 , ... )
{
T_1 args ;
if ( V_2 == 0 || V_3 >= V_4 - 1 )
return;
va_start ( args , V_1 ) ;
V_3 += F_2 ( V_5 + V_3 , V_4 - V_3 , V_1 , args ) ;
va_end ( args ) ;
}
static void F_3 ( struct V_6 * V_7 )
{
enum V_8 V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_9 = V_7 -> V_12 . V_13 [ V_10 ] . type ;
if ( V_9 == V_14 )
continue;
F_1 ( L_1 , V_10 , V_15 [ V_9 ] ) ;
if ( V_9 == V_16 || V_9 == V_17 )
F_1 ( L_2 , V_7 -> V_12 . V_13 [ V_10 ] . V_18 ) ;
else if ( V_9 == V_19 || V_9 == V_20 ||
V_9 == V_21 )
F_1 ( L_3 ,
V_7 -> V_12 . V_13 [ V_10 ] . V_22 -> V_23 ,
V_7 -> V_12 . V_13 [ V_10 ] . V_22 -> V_24 ) ;
}
for ( V_10 = 0 ; V_10 < V_25 ; V_10 += V_26 ) {
if ( V_7 -> V_12 . V_27 [ V_10 ] == V_28 )
F_1 ( L_4 , - V_25 + V_10 ,
V_15 [ V_7 -> V_12 . V_29 [ V_10 / V_26 ] . type ] ) ;
}
F_1 ( L_5 ) ;
}
static void F_4 ( struct V_30 * V_31 )
{
T_2 V_32 = F_5 ( V_31 -> V_33 ) ;
if ( V_32 == V_34 || V_32 == V_35 ) {
if ( F_6 ( V_31 -> V_33 ) == V_36 )
F_1 ( L_6 ,
V_31 -> V_33 , V_32 == V_34 ? L_7 : L_8 ,
V_31 -> V_37 ,
V_38 [ F_7 ( V_31 -> V_33 ) >> 4 ] ,
V_32 == V_34 ? L_7 : L_8 ,
V_31 -> V_39 ) ;
else
F_1 ( L_9 ,
V_31 -> V_33 , V_32 == V_34 ? L_7 : L_8 ,
V_31 -> V_37 ,
V_38 [ F_7 ( V_31 -> V_33 ) >> 4 ] ,
V_32 == V_34 ? L_7 : L_8 ,
V_31 -> V_18 ) ;
} else if ( V_32 == V_40 ) {
if ( F_8 ( V_31 -> V_33 ) == V_41 )
F_1 ( L_10 ,
V_31 -> V_33 ,
V_42 [ F_9 ( V_31 -> V_33 ) >> 3 ] ,
V_31 -> V_37 ,
V_31 -> V_43 , V_31 -> V_39 ) ;
else if ( F_8 ( V_31 -> V_33 ) == V_44 )
F_1 ( L_11 ,
V_31 -> V_33 ,
V_42 [ F_9 ( V_31 -> V_33 ) >> 3 ] ,
V_31 -> V_37 , V_31 -> V_43 ,
V_31 -> V_39 ) ;
else
F_1 ( L_12 , V_31 -> V_33 ) ;
} else if ( V_32 == V_45 ) {
if ( F_8 ( V_31 -> V_33 ) != V_41 ) {
F_1 ( L_13 , V_31 -> V_33 ) ;
return;
}
F_1 ( L_14 ,
V_31 -> V_33 ,
V_42 [ F_9 ( V_31 -> V_33 ) >> 3 ] ,
V_31 -> V_37 ,
V_31 -> V_43 , V_31 -> V_18 ) ;
} else if ( V_32 == V_46 ) {
if ( F_8 ( V_31 -> V_33 ) != V_41 ) {
F_1 ( L_15 , V_31 -> V_33 ) ;
return;
}
F_1 ( L_16 ,
V_31 -> V_33 , V_31 -> V_37 ,
V_42 [ F_9 ( V_31 -> V_33 ) >> 3 ] ,
V_31 -> V_39 , V_31 -> V_43 ) ;
} else if ( V_32 == V_47 ) {
if ( F_8 ( V_31 -> V_33 ) == V_48 ) {
F_1 ( L_17 ,
V_31 -> V_33 ,
V_42 [ F_9 ( V_31 -> V_33 ) >> 3 ] ,
V_31 -> V_18 ) ;
} else if ( F_8 ( V_31 -> V_33 ) == V_49 ) {
F_1 ( L_18 ,
V_31 -> V_33 ,
V_42 [ F_9 ( V_31 -> V_33 ) >> 3 ] ,
V_31 -> V_39 , V_31 -> V_18 ) ;
} else if ( F_8 ( V_31 -> V_33 ) == V_50 ) {
F_1 ( L_19 ,
V_31 -> V_33 , V_31 -> V_37 , V_31 -> V_18 ) ;
} else {
F_1 ( L_20 , V_31 -> V_33 ) ;
return;
}
} else if ( V_32 == V_51 ) {
T_2 V_52 = F_7 ( V_31 -> V_33 ) ;
if ( V_52 == V_53 ) {
F_1 ( L_21 , V_31 -> V_33 , V_31 -> V_18 ) ;
} else if ( V_31 -> V_33 == ( V_51 | V_54 ) ) {
F_1 ( L_22 ,
V_31 -> V_33 , V_31 -> V_43 ) ;
} else if ( V_31 -> V_33 == ( V_51 | V_55 ) ) {
F_1 ( L_23 , V_31 -> V_33 ) ;
} else if ( F_6 ( V_31 -> V_33 ) == V_36 ) {
F_1 ( L_24 ,
V_31 -> V_33 , V_31 -> V_37 ,
V_56 [ F_7 ( V_31 -> V_33 ) >> 4 ] ,
V_31 -> V_39 , V_31 -> V_43 ) ;
} else {
F_1 ( L_25 ,
V_31 -> V_33 , V_31 -> V_37 ,
V_56 [ F_7 ( V_31 -> V_33 ) >> 4 ] ,
V_31 -> V_18 , V_31 -> V_43 ) ;
}
} else {
F_1 ( L_26 , V_31 -> V_33 , V_57 [ V_32 ] ) ;
}
}
static int F_10 ( struct V_6 * V_7 , int * V_58 )
{
struct V_59 * V_60 ;
int V_61 ;
if ( V_7 -> V_62 == NULL )
return - 1 ;
memcpy ( & V_7 -> V_12 , & V_7 -> V_62 -> V_63 , sizeof( V_7 -> V_12 ) ) ;
V_61 = V_7 -> V_62 -> V_61 ;
if ( V_58 )
* V_58 = V_7 -> V_62 -> V_58 ;
V_60 = V_7 -> V_62 -> V_64 ;
F_11 ( V_7 -> V_62 ) ;
V_7 -> V_62 = V_60 ;
V_7 -> V_65 -- ;
return V_61 ;
}
static struct V_66 * F_12 ( struct V_6 * V_7 , int V_61 ,
int V_58 )
{
struct V_59 * V_60 ;
V_60 = F_13 ( sizeof( struct V_59 ) , V_67 ) ;
if ( ! V_60 )
goto V_68;
memcpy ( & V_60 -> V_63 , & V_7 -> V_12 , sizeof( V_7 -> V_12 ) ) ;
V_60 -> V_61 = V_61 ;
V_60 -> V_58 = V_58 ;
V_60 -> V_64 = V_7 -> V_62 ;
V_7 -> V_62 = V_60 ;
V_7 -> V_65 ++ ;
if ( V_7 -> V_65 > 1024 ) {
F_1 ( L_27 ) ;
goto V_68;
}
return & V_60 -> V_63 ;
V_68:
while ( F_10 ( V_7 , NULL ) >= 0 ) ;
return NULL ;
}
static void F_14 ( struct V_69 * V_13 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_13 [ V_10 ] . type = V_14 ;
V_13 [ V_10 ] . V_18 = 0 ;
V_13 [ V_10 ] . V_22 = NULL ;
}
V_13 [ V_70 ] . type = V_71 ;
V_13 [ V_72 ] . type = V_73 ;
}
static void F_15 ( struct V_69 * V_13 , T_3 V_74 )
{
F_16 ( V_74 >= V_11 ) ;
V_13 [ V_74 ] . type = V_75 ;
V_13 [ V_74 ] . V_18 = 0 ;
V_13 [ V_74 ] . V_22 = NULL ;
}
static int F_17 ( struct V_69 * V_13 , T_3 V_74 ,
enum V_76 V_9 )
{
if ( V_74 >= V_11 ) {
F_1 ( L_28 , V_74 ) ;
return - V_77 ;
}
if ( V_9 == V_78 ) {
if ( V_13 [ V_74 ] . type == V_14 ) {
F_1 ( L_29 , V_74 ) ;
return - V_79 ;
}
} else {
if ( V_74 == V_70 ) {
F_1 ( L_30 ) ;
return - V_79 ;
}
if ( V_9 == V_80 )
F_15 ( V_13 , V_74 ) ;
}
return 0 ;
}
static int F_18 ( int V_81 )
{
if ( V_81 == V_82 )
return 4 ;
else if ( V_81 == V_83 )
return 2 ;
else if ( V_81 == V_84 )
return 1 ;
else if ( V_81 == V_85 )
return 8 ;
else
return - V_77 ;
}
static int F_19 ( struct V_66 * V_86 , int V_43 , int V_87 ,
int V_88 )
{
int V_10 ;
if ( V_88 >= 0 &&
( V_86 -> V_13 [ V_88 ] . type == V_20 ||
V_86 -> V_13 [ V_88 ] . type == V_17 ||
V_86 -> V_13 [ V_88 ] . type == V_73 ) ) {
if ( V_87 != V_26 ) {
F_1 ( L_31 ) ;
return - V_79 ;
}
V_86 -> V_29 [ ( V_25 + V_43 ) / V_26 ] =
V_86 -> V_13 [ V_88 ] ;
for ( V_10 = 0 ; V_10 < V_26 ; V_10 ++ )
V_86 -> V_27 [ V_25 + V_43 + V_10 ] = V_28 ;
} else {
V_86 -> V_29 [ ( V_25 + V_43 ) / V_26 ] =
(struct V_69 ) {} ;
for ( V_10 = 0 ; V_10 < V_87 ; V_10 ++ )
V_86 -> V_27 [ V_25 + V_43 + V_10 ] = V_89 ;
}
return 0 ;
}
static int F_20 ( struct V_66 * V_86 , int V_43 , int V_87 ,
int V_88 )
{
T_2 * V_90 ;
int V_10 ;
V_90 = & V_86 -> V_27 [ V_25 + V_43 ] ;
if ( V_90 [ 0 ] == V_28 ) {
if ( V_87 != V_26 ) {
F_1 ( L_31 ) ;
return - V_79 ;
}
for ( V_10 = 1 ; V_10 < V_26 ; V_10 ++ ) {
if ( V_90 [ V_10 ] != V_28 ) {
F_1 ( L_32 ) ;
return - V_79 ;
}
}
if ( V_88 >= 0 )
V_86 -> V_13 [ V_88 ] =
V_86 -> V_29 [ ( V_25 + V_43 ) / V_26 ] ;
return 0 ;
} else {
for ( V_10 = 0 ; V_10 < V_87 ; V_10 ++ ) {
if ( V_90 [ V_10 ] != V_89 ) {
F_1 ( L_33 ,
V_43 , V_10 , V_87 ) ;
return - V_79 ;
}
}
if ( V_88 >= 0 )
F_15 ( V_86 -> V_13 , V_88 ) ;
return 0 ;
}
}
static int F_21 ( struct V_6 * V_7 , T_3 V_74 , int V_43 ,
int V_87 )
{
struct V_91 * V_92 = V_7 -> V_12 . V_13 [ V_74 ] . V_22 ;
if ( V_43 < 0 || V_43 + V_87 > V_92 -> V_24 ) {
F_1 ( L_34 ,
V_92 -> V_24 , V_43 , V_87 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_22 ( struct V_6 * V_7 , int V_43 , int V_87 ,
enum V_93 V_9 )
{
if ( V_7 -> V_94 -> V_95 -> V_96 -> V_97 &&
V_7 -> V_94 -> V_95 -> V_96 -> V_97 ( V_43 , V_87 , V_9 ) )
return 0 ;
F_1 ( L_35 , V_43 , V_87 ) ;
return - V_79 ;
}
static int F_23 ( struct V_6 * V_7 , T_3 V_74 , int V_43 ,
int V_81 , enum V_93 V_9 ,
int V_88 )
{
struct V_66 * V_86 = & V_7 -> V_12 ;
int V_87 , V_68 = 0 ;
V_87 = F_18 ( V_81 ) ;
if ( V_87 < 0 )
return V_87 ;
if ( V_43 % V_87 != 0 ) {
F_1 ( L_36 , V_43 , V_87 ) ;
return - V_79 ;
}
if ( V_86 -> V_13 [ V_74 ] . type == V_20 ) {
V_68 = F_21 ( V_7 , V_74 , V_43 , V_87 ) ;
if ( ! V_68 && V_9 == V_98 && V_88 >= 0 )
F_15 ( V_86 -> V_13 , V_88 ) ;
} else if ( V_86 -> V_13 [ V_74 ] . type == V_73 ) {
V_68 = F_22 ( V_7 , V_43 , V_87 , V_9 ) ;
if ( ! V_68 && V_9 == V_98 && V_88 >= 0 )
F_15 ( V_86 -> V_13 , V_88 ) ;
} else if ( V_86 -> V_13 [ V_74 ] . type == V_71 ) {
if ( V_43 >= 0 || V_43 < - V_25 ) {
F_1 ( L_37 , V_43 , V_87 ) ;
return - V_79 ;
}
if ( V_9 == V_99 )
V_68 = F_19 ( V_86 , V_43 , V_87 , V_88 ) ;
else
V_68 = F_20 ( V_86 , V_43 , V_87 , V_88 ) ;
} else {
F_1 ( L_38 ,
V_74 , V_15 [ V_86 -> V_13 [ V_74 ] . type ] ) ;
return - V_79 ;
}
return V_68 ;
}
static int F_24 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
struct V_69 * V_13 = V_7 -> V_12 . V_13 ;
int V_68 ;
if ( ( F_9 ( V_31 -> V_33 ) != V_82 && F_9 ( V_31 -> V_33 ) != V_85 ) ||
V_31 -> V_18 != 0 ) {
F_1 ( L_39 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_23 ( V_7 , V_31 -> V_37 , V_31 -> V_43 ,
F_9 ( V_31 -> V_33 ) , V_98 , - 1 ) ;
if ( V_68 )
return V_68 ;
return F_23 ( V_7 , V_31 -> V_37 , V_31 -> V_43 ,
F_9 ( V_31 -> V_33 ) , V_99 , - 1 ) ;
}
static int F_25 ( struct V_6 * V_7 ,
int V_74 , int V_100 )
{
struct V_66 * V_86 = & V_7 -> V_12 ;
struct V_69 * V_13 = V_86 -> V_13 ;
int V_43 , V_10 ;
if ( V_13 [ V_74 ] . type != V_17 )
return - V_79 ;
V_43 = V_13 [ V_74 ] . V_18 ;
if ( V_43 >= 0 || V_43 < - V_25 || V_43 + V_100 > 0 ||
V_100 <= 0 ) {
F_1 ( L_40 ,
V_74 , V_43 , V_100 ) ;
return - V_79 ;
}
for ( V_10 = 0 ; V_10 < V_100 ; V_10 ++ ) {
if ( V_86 -> V_27 [ V_25 + V_43 + V_10 ] != V_89 ) {
F_1 ( L_41 ,
V_43 , V_10 , V_100 ) ;
return - V_79 ;
}
}
return 0 ;
}
static int F_26 ( struct V_6 * V_7 , T_3 V_74 ,
enum V_101 V_102 , struct V_91 * * V_103 )
{
struct V_69 * V_104 = V_7 -> V_12 . V_13 + V_74 ;
enum V_8 V_105 ;
int V_68 = 0 ;
if ( V_102 == V_106 )
return 0 ;
if ( V_104 -> type == V_14 ) {
F_1 ( L_29 , V_74 ) ;
return - V_79 ;
}
if ( V_102 == V_107 )
return 0 ;
if ( V_102 == V_108 || V_102 == V_109 ||
V_102 == V_110 ) {
V_105 = V_17 ;
} else if ( V_102 == V_111 ) {
V_105 = V_16 ;
} else if ( V_102 == V_112 ) {
V_105 = V_19 ;
} else if ( V_102 == V_113 ) {
V_105 = V_73 ;
} else {
F_1 ( L_42 , V_102 ) ;
return - V_114 ;
}
if ( V_104 -> type != V_105 ) {
F_1 ( L_43 , V_74 ,
V_15 [ V_104 -> type ] , V_15 [ V_105 ] ) ;
return - V_79 ;
}
if ( V_102 == V_112 ) {
* V_103 = V_104 -> V_22 ;
} else if ( V_102 == V_109 ) {
if ( ! * V_103 ) {
F_1 ( L_44 ) ;
return - V_79 ;
}
V_68 = F_25 ( V_7 , V_74 , ( * V_103 ) -> V_23 ) ;
} else if ( V_102 == V_110 ) {
if ( ! * V_103 ) {
F_1 ( L_45 ) ;
return - V_79 ;
}
V_68 = F_25 ( V_7 , V_74 , ( * V_103 ) -> V_24 ) ;
} else if ( V_102 == V_111 ) {
if ( V_74 == 0 ) {
F_1 ( L_46 ) ;
return - V_79 ;
}
V_68 = F_25 ( V_7 , V_74 - 1 , V_104 -> V_18 ) ;
}
return V_68 ;
}
static int F_27 ( struct V_6 * V_7 , int V_115 )
{
struct V_66 * V_86 = & V_7 -> V_12 ;
const struct V_116 * V_117 = NULL ;
struct V_69 * V_13 = V_86 -> V_13 ;
struct V_91 * V_92 = NULL ;
struct V_69 * V_104 ;
int V_10 , V_68 ;
if ( V_115 < 0 || V_115 >= V_118 ) {
F_1 ( L_47 , V_115 ) ;
return - V_77 ;
}
if ( V_7 -> V_94 -> V_95 -> V_96 -> V_119 )
V_117 = V_7 -> V_94 -> V_95 -> V_96 -> V_119 ( V_115 ) ;
if ( ! V_117 ) {
F_1 ( L_48 , V_115 ) ;
return - V_77 ;
}
if ( ! V_7 -> V_94 -> V_120 && V_117 -> V_121 ) {
F_1 ( L_49 ) ;
return - V_77 ;
}
V_68 = F_26 ( V_7 , V_72 , V_117 -> V_122 , & V_92 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_123 , V_117 -> V_124 , & V_92 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_125 , V_117 -> V_126 , & V_92 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_127 , V_117 -> V_128 , & V_92 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_129 , V_117 -> V_130 , & V_92 ) ;
if ( V_68 )
return V_68 ;
for ( V_10 = 0 ; V_10 < V_131 ; V_10 ++ ) {
V_104 = V_13 + V_132 [ V_10 ] ;
V_104 -> type = V_14 ;
V_104 -> V_18 = 0 ;
}
if ( V_117 -> V_133 == V_134 ) {
V_13 [ V_135 ] . type = V_75 ;
} else if ( V_117 -> V_133 == V_136 ) {
V_13 [ V_135 ] . type = V_14 ;
} else if ( V_117 -> V_133 == V_137 ) {
V_13 [ V_135 ] . type = V_21 ;
if ( V_92 == NULL ) {
F_1 ( L_50 ) ;
return - V_77 ;
}
V_13 [ V_135 ] . V_22 = V_92 ;
} else {
F_1 ( L_51 ,
V_117 -> V_133 , V_115 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_28 ( struct V_69 * V_13 , struct V_30 * V_31 )
{
T_2 V_52 = F_7 ( V_31 -> V_33 ) ;
int V_68 ;
if ( V_52 == V_138 || V_52 == V_139 ) {
if ( V_52 == V_139 ) {
if ( F_6 ( V_31 -> V_33 ) != 0 ||
V_31 -> V_39 != V_135 ||
V_31 -> V_43 != 0 || V_31 -> V_18 != 0 ) {
F_1 ( L_52 ) ;
return - V_77 ;
}
} else {
if ( V_31 -> V_39 != V_135 || V_31 -> V_43 != 0 ||
( V_31 -> V_18 != 16 && V_31 -> V_18 != 32 && V_31 -> V_18 != 64 ) ) {
F_1 ( L_53 ) ;
return - V_77 ;
}
}
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_80 ) ;
if ( V_68 )
return V_68 ;
} else if ( V_52 == V_140 ) {
if ( F_6 ( V_31 -> V_33 ) == V_36 ) {
if ( V_31 -> V_18 != 0 || V_31 -> V_43 != 0 ) {
F_1 ( L_54 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
} else {
if ( V_31 -> V_39 != V_135 || V_31 -> V_43 != 0 ) {
F_1 ( L_54 ) ;
return - V_77 ;
}
}
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_80 ) ;
if ( V_68 )
return V_68 ;
if ( F_6 ( V_31 -> V_33 ) == V_36 ) {
if ( F_5 ( V_31 -> V_33 ) == V_35 ) {
V_13 [ V_31 -> V_37 ] = V_13 [ V_31 -> V_39 ] ;
} else {
V_13 [ V_31 -> V_37 ] . type = V_75 ;
V_13 [ V_31 -> V_37 ] . V_22 = NULL ;
}
} else {
V_13 [ V_31 -> V_37 ] . type = V_16 ;
V_13 [ V_31 -> V_37 ] . V_18 = V_31 -> V_18 ;
}
} else if ( V_52 > V_138 ) {
F_1 ( L_55 , V_52 ) ;
return - V_77 ;
} else {
bool V_141 = false ;
if ( F_6 ( V_31 -> V_33 ) == V_36 ) {
if ( V_31 -> V_18 != 0 || V_31 -> V_43 != 0 ) {
F_1 ( L_56 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
} else {
if ( V_31 -> V_39 != V_135 || V_31 -> V_43 != 0 ) {
F_1 ( L_56 ) ;
return - V_77 ;
}
}
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_78 ) ;
if ( V_68 )
return V_68 ;
if ( ( V_52 == V_142 || V_52 == V_143 ) &&
F_6 ( V_31 -> V_33 ) == V_144 && V_31 -> V_18 == 0 ) {
F_1 ( L_57 ) ;
return - V_77 ;
}
if ( V_52 == V_145 && F_5 ( V_31 -> V_33 ) == V_35 &&
V_13 [ V_31 -> V_37 ] . type == V_71 &&
F_6 ( V_31 -> V_33 ) == V_144 )
V_141 = true ;
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_80 ) ;
if ( V_68 )
return V_68 ;
if ( V_141 ) {
V_13 [ V_31 -> V_37 ] . type = V_17 ;
V_13 [ V_31 -> V_37 ] . V_18 = V_31 -> V_18 ;
}
}
return 0 ;
}
static int F_29 ( struct V_6 * V_7 ,
struct V_30 * V_31 , int * V_61 )
{
struct V_69 * V_13 = V_7 -> V_12 . V_13 ;
struct V_66 * V_146 ;
T_2 V_52 = F_7 ( V_31 -> V_33 ) ;
int V_68 ;
if ( V_52 > V_55 ) {
F_1 ( L_58 , V_52 ) ;
return - V_77 ;
}
if ( F_6 ( V_31 -> V_33 ) == V_36 ) {
if ( V_31 -> V_18 != 0 ) {
F_1 ( L_59 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
} else {
if ( V_31 -> V_39 != V_135 ) {
F_1 ( L_59 ) ;
return - V_77 ;
}
}
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_78 ) ;
if ( V_68 )
return V_68 ;
if ( F_6 ( V_31 -> V_33 ) == V_144 &&
( V_52 == V_147 || V_52 == V_148 ) &&
V_13 [ V_31 -> V_37 ] . type == V_16 &&
V_13 [ V_31 -> V_37 ] . V_18 == V_31 -> V_18 ) {
if ( V_52 == V_147 ) {
* V_61 += V_31 -> V_43 ;
return 0 ;
} else {
return 0 ;
}
}
V_146 = F_12 ( V_7 , * V_61 + V_31 -> V_43 + 1 , * V_61 ) ;
if ( ! V_146 )
return - V_114 ;
if ( F_6 ( V_31 -> V_33 ) == V_144 &&
V_31 -> V_18 == 0 && ( V_52 == V_147 ||
V_52 == V_148 ) &&
V_13 [ V_31 -> V_37 ] . type == V_21 ) {
if ( V_52 == V_147 ) {
V_13 [ V_31 -> V_37 ] . type = V_20 ;
V_146 -> V_13 [ V_31 -> V_37 ] . type = V_16 ;
V_146 -> V_13 [ V_31 -> V_37 ] . V_18 = 0 ;
} else {
V_146 -> V_13 [ V_31 -> V_37 ] . type = V_20 ;
V_13 [ V_31 -> V_37 ] . type = V_16 ;
V_13 [ V_31 -> V_37 ] . V_18 = 0 ;
}
} else if ( F_6 ( V_31 -> V_33 ) == V_144 &&
( V_52 == V_147 || V_52 == V_148 ) ) {
if ( V_52 == V_147 ) {
V_146 -> V_13 [ V_31 -> V_37 ] . type = V_16 ;
V_146 -> V_13 [ V_31 -> V_37 ] . V_18 = V_31 -> V_18 ;
} else {
V_13 [ V_31 -> V_37 ] . type = V_16 ;
V_13 [ V_31 -> V_37 ] . V_18 = V_31 -> V_18 ;
}
}
if ( V_2 )
F_3 ( V_7 ) ;
return 0 ;
}
static struct V_91 * F_30 ( struct V_30 * V_31 )
{
T_4 V_149 = ( ( T_4 ) ( T_3 ) V_31 [ 0 ] . V_18 ) | ( ( T_4 ) ( T_3 ) V_31 [ 1 ] . V_18 ) << 32 ;
return (struct V_91 * ) ( unsigned long ) V_149 ;
}
static int F_31 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
struct V_69 * V_13 = V_7 -> V_12 . V_13 ;
int V_68 ;
if ( F_9 ( V_31 -> V_33 ) != V_85 ) {
F_1 ( L_60 ) ;
return - V_77 ;
}
if ( V_31 -> V_43 != 0 ) {
F_1 ( L_61 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_80 ) ;
if ( V_68 )
return V_68 ;
if ( V_31 -> V_39 == 0 )
return 0 ;
F_16 ( V_31 -> V_39 != V_150 ) ;
V_13 [ V_31 -> V_37 ] . type = V_19 ;
V_13 [ V_31 -> V_37 ] . V_22 = F_30 ( V_31 ) ;
return 0 ;
}
static bool F_32 ( enum V_151 type )
{
switch ( type ) {
case V_152 :
case V_153 :
case V_154 :
return true ;
default:
return false ;
}
}
static int F_33 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
struct V_69 * V_13 = V_7 -> V_12 . V_13 ;
T_2 V_155 = F_8 ( V_31 -> V_33 ) ;
struct V_69 * V_104 ;
int V_10 , V_68 ;
if ( ! F_32 ( V_7 -> V_94 -> type ) ) {
F_1 ( L_62 ) ;
return - V_77 ;
}
if ( V_31 -> V_37 != V_135 || V_31 -> V_43 != 0 ||
( V_155 == V_48 && V_31 -> V_39 != V_135 ) ) {
F_1 ( L_63 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_156 , V_78 ) ;
if ( V_68 )
return V_68 ;
if ( V_13 [ V_156 ] . type != V_73 ) {
F_1 ( L_64 ) ;
return - V_77 ;
}
if ( V_155 == V_49 ) {
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
}
for ( V_10 = 0 ; V_10 < V_131 ; V_10 ++ ) {
V_104 = V_13 + V_132 [ V_10 ] ;
V_104 -> type = V_14 ;
V_104 -> V_18 = 0 ;
}
V_13 [ V_135 ] . type = V_75 ;
return 0 ;
}
static int F_34 ( int V_9 , int V_157 , int V_158 , struct V_6 * V_7 )
{
if ( V_158 == V_159 && V_160 [ V_9 ] >= ( V_161 | V_159 ) )
return 0 ;
if ( V_158 == V_162 && V_160 [ V_9 ] >= ( V_161 | V_162 ) )
return 0 ;
if ( V_157 < 0 || V_157 >= V_7 -> V_94 -> V_163 ) {
F_1 ( L_65 , V_9 , V_157 ) ;
return - V_77 ;
}
if ( V_158 == V_162 )
V_7 -> V_164 [ V_157 ] = V_165 ;
if ( V_160 [ V_157 ] == 0 ) {
V_160 [ V_9 ] = V_161 | V_158 ;
V_160 [ V_157 ] = V_161 ;
if ( V_166 >= V_7 -> V_94 -> V_163 )
return - V_167 ;
V_168 [ V_166 ++ ] = V_157 ;
return 1 ;
} else if ( ( V_160 [ V_157 ] & 0xF0 ) == V_161 ) {
F_1 ( L_66 , V_9 , V_157 ) ;
return - V_77 ;
} else if ( V_160 [ V_157 ] == V_169 ) {
V_160 [ V_9 ] = V_161 | V_158 ;
} else {
F_1 ( L_67 ) ;
return - V_114 ;
}
return 0 ;
}
static int F_35 ( struct V_6 * V_7 )
{
struct V_30 * V_170 = V_7 -> V_94 -> V_171 ;
int V_172 = V_7 -> V_94 -> V_163 ;
int V_173 = 0 ;
int V_10 , V_9 ;
V_160 = F_36 ( V_172 , sizeof( int ) , V_67 ) ;
if ( ! V_160 )
return - V_174 ;
V_168 = F_36 ( V_172 , sizeof( int ) , V_67 ) ;
if ( ! V_168 ) {
F_11 ( V_160 ) ;
return - V_174 ;
}
V_160 [ 0 ] = V_161 ;
V_168 [ 0 ] = 0 ;
V_166 = 1 ;
V_175:
if ( V_166 == 0 )
goto V_176;
V_9 = V_168 [ V_166 - 1 ] ;
if ( F_5 ( V_170 [ V_9 ] . V_33 ) == V_51 ) {
T_2 V_52 = F_7 ( V_170 [ V_9 ] . V_33 ) ;
if ( V_52 == V_55 ) {
goto V_177;
} else if ( V_52 == V_53 ) {
V_173 = F_34 ( V_9 , V_9 + 1 , V_159 , V_7 ) ;
if ( V_173 == 1 )
goto V_175;
else if ( V_173 < 0 )
goto V_178;
} else if ( V_52 == V_54 ) {
if ( F_6 ( V_170 [ V_9 ] . V_33 ) != V_144 ) {
V_173 = - V_77 ;
goto V_178;
}
V_173 = F_34 ( V_9 , V_9 + V_170 [ V_9 ] . V_43 + 1 ,
V_159 , V_7 ) ;
if ( V_173 == 1 )
goto V_175;
else if ( V_173 < 0 )
goto V_178;
if ( V_9 + 1 < V_172 )
V_7 -> V_164 [ V_9 + 1 ] = V_165 ;
} else {
V_173 = F_34 ( V_9 , V_9 + 1 , V_159 , V_7 ) ;
if ( V_173 == 1 )
goto V_175;
else if ( V_173 < 0 )
goto V_178;
V_173 = F_34 ( V_9 , V_9 + V_170 [ V_9 ] . V_43 + 1 , V_162 , V_7 ) ;
if ( V_173 == 1 )
goto V_175;
else if ( V_173 < 0 )
goto V_178;
}
} else {
V_173 = F_34 ( V_9 , V_9 + 1 , V_159 , V_7 ) ;
if ( V_173 == 1 )
goto V_175;
else if ( V_173 < 0 )
goto V_178;
}
V_177:
V_160 [ V_9 ] = V_169 ;
if ( V_166 -- <= 0 ) {
F_1 ( L_68 ) ;
V_173 = - V_114 ;
goto V_178;
}
goto V_175;
V_176:
for ( V_10 = 0 ; V_10 < V_172 ; V_10 ++ ) {
if ( V_160 [ V_10 ] != V_169 ) {
F_1 ( L_69 , V_10 ) ;
V_173 = - V_77 ;
goto V_178;
}
}
V_173 = 0 ;
V_178:
F_11 ( V_160 ) ;
F_11 ( V_168 ) ;
return V_173 ;
}
static bool F_37 ( struct V_66 * V_179 , struct V_66 * V_180 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( memcmp ( & V_179 -> V_13 [ V_10 ] , & V_180 -> V_13 [ V_10 ] ,
sizeof( V_179 -> V_13 [ 0 ] ) ) != 0 ) {
if ( V_179 -> V_13 [ V_10 ] . type == V_14 ||
( V_179 -> V_13 [ V_10 ] . type == V_75 &&
V_180 -> V_13 [ V_10 ] . type != V_14 ) )
continue;
return false ;
}
}
for ( V_10 = 0 ; V_10 < V_25 ; V_10 ++ ) {
if ( V_179 -> V_27 [ V_10 ] == V_181 )
continue;
if ( V_179 -> V_27 [ V_10 ] != V_180 -> V_27 [ V_10 ] )
return false ;
if ( V_10 % V_26 )
continue;
if ( memcmp ( & V_179 -> V_29 [ V_10 / V_26 ] ,
& V_180 -> V_29 [ V_10 / V_26 ] ,
sizeof( V_179 -> V_29 [ 0 ] ) ) )
return false ;
else
continue;
}
return true ;
}
static int F_38 ( struct V_6 * V_7 , int V_61 )
{
struct V_182 * V_183 ;
struct V_182 * V_184 ;
V_184 = V_7 -> V_164 [ V_61 ] ;
if ( ! V_184 )
return 0 ;
while ( V_184 != V_165 ) {
if ( F_37 ( & V_184 -> V_86 , & V_7 -> V_12 ) )
return 1 ;
V_184 = V_184 -> V_64 ;
}
V_183 = F_13 ( sizeof( struct V_182 ) , V_185 ) ;
if ( ! V_183 )
return - V_174 ;
memcpy ( & V_183 -> V_86 , & V_7 -> V_12 , sizeof( V_7 -> V_12 ) ) ;
V_183 -> V_64 = V_7 -> V_164 [ V_61 ] ;
V_7 -> V_164 [ V_61 ] = V_183 ;
return 0 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_66 * V_86 = & V_7 -> V_12 ;
struct V_30 * V_170 = V_7 -> V_94 -> V_171 ;
struct V_69 * V_13 = V_86 -> V_13 ;
int V_172 = V_7 -> V_94 -> V_163 ;
int V_61 , V_58 = 0 ;
int V_186 = 0 ;
bool V_187 = false ;
F_14 ( V_13 ) ;
V_61 = 0 ;
for (; ; ) {
struct V_30 * V_31 ;
T_2 V_32 ;
int V_68 ;
if ( V_61 >= V_172 ) {
F_1 ( L_70 ,
V_61 , V_172 ) ;
return - V_114 ;
}
V_31 = & V_170 [ V_61 ] ;
V_32 = F_5 ( V_31 -> V_33 ) ;
if ( ++ V_186 > 32768 ) {
F_1 ( L_71 ,
V_186 ) ;
return - V_167 ;
}
V_68 = F_38 ( V_7 , V_61 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_68 == 1 ) {
if ( V_2 ) {
if ( V_187 )
F_1 ( L_72 ,
V_58 , V_61 ) ;
else
F_1 ( L_73 , V_61 ) ;
}
goto V_188;
}
if ( V_2 && V_187 ) {
F_1 ( L_74 , V_58 , V_61 ) ;
F_3 ( V_7 ) ;
V_187 = false ;
}
if ( V_2 ) {
F_1 ( L_75 , V_61 ) ;
F_4 ( V_31 ) ;
}
if ( V_32 == V_34 || V_32 == V_35 ) {
V_68 = F_28 ( V_13 , V_31 ) ;
if ( V_68 )
return V_68 ;
} else if ( V_32 == V_46 ) {
enum V_8 V_189 ;
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_190 ) ;
if ( V_68 )
return V_68 ;
V_189 = V_13 [ V_31 -> V_39 ] . type ;
V_68 = F_23 ( V_7 , V_31 -> V_39 , V_31 -> V_43 ,
F_9 ( V_31 -> V_33 ) , V_98 ,
V_31 -> V_37 ) ;
if ( V_68 )
return V_68 ;
if ( F_9 ( V_31 -> V_33 ) != V_82 ) {
V_61 ++ ;
continue;
}
if ( V_31 -> V_18 == 0 ) {
V_31 -> V_18 = V_189 ;
} else if ( V_189 != V_31 -> V_18 &&
( V_189 == V_73 ||
V_31 -> V_18 == V_73 ) ) {
F_1 ( L_76 ) ;
return - V_77 ;
}
} else if ( V_32 == V_40 ) {
if ( F_8 ( V_31 -> V_33 ) == V_44 ) {
V_68 = F_24 ( V_7 , V_31 ) ;
if ( V_68 )
return V_68 ;
V_61 ++ ;
continue;
}
if ( F_8 ( V_31 -> V_33 ) != V_41 ||
V_31 -> V_18 != 0 ) {
F_1 ( L_77 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_23 ( V_7 , V_31 -> V_37 , V_31 -> V_43 ,
F_9 ( V_31 -> V_33 ) , V_99 ,
V_31 -> V_39 ) ;
if ( V_68 )
return V_68 ;
} else if ( V_32 == V_45 ) {
if ( F_8 ( V_31 -> V_33 ) != V_41 ||
V_31 -> V_39 != V_135 ) {
F_1 ( L_78 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_23 ( V_7 , V_31 -> V_37 , V_31 -> V_43 ,
F_9 ( V_31 -> V_33 ) , V_99 ,
- 1 ) ;
if ( V_68 )
return V_68 ;
} else if ( V_32 == V_51 ) {
T_2 V_52 = F_7 ( V_31 -> V_33 ) ;
if ( V_52 == V_53 ) {
if ( F_6 ( V_31 -> V_33 ) != V_144 ||
V_31 -> V_43 != 0 ||
V_31 -> V_39 != V_135 ||
V_31 -> V_37 != V_135 ) {
F_1 ( L_79 ) ;
return - V_77 ;
}
V_68 = F_27 ( V_7 , V_31 -> V_18 ) ;
if ( V_68 )
return V_68 ;
} else if ( V_52 == V_54 ) {
if ( F_6 ( V_31 -> V_33 ) != V_144 ||
V_31 -> V_18 != 0 ||
V_31 -> V_39 != V_135 ||
V_31 -> V_37 != V_135 ) {
F_1 ( L_80 ) ;
return - V_77 ;
}
V_61 += V_31 -> V_43 + 1 ;
continue;
} else if ( V_52 == V_55 ) {
if ( F_6 ( V_31 -> V_33 ) != V_144 ||
V_31 -> V_18 != 0 ||
V_31 -> V_39 != V_135 ||
V_31 -> V_37 != V_135 ) {
F_1 ( L_81 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_135 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_188:
V_61 = F_10 ( V_7 , & V_58 ) ;
if ( V_61 < 0 ) {
break;
} else {
V_187 = true ;
continue;
}
} else {
V_68 = F_29 ( V_7 , V_31 , & V_61 ) ;
if ( V_68 )
return V_68 ;
}
} else if ( V_32 == V_47 ) {
T_2 V_155 = F_8 ( V_31 -> V_33 ) ;
if ( V_155 == V_48 || V_155 == V_49 ) {
V_68 = F_33 ( V_7 , V_31 ) ;
if ( V_68 )
return V_68 ;
} else if ( V_155 == V_50 ) {
V_68 = F_31 ( V_7 , V_31 ) ;
if ( V_68 )
return V_68 ;
V_61 ++ ;
} else {
F_1 ( L_82 ) ;
return - V_77 ;
}
} else {
F_1 ( L_83 , V_32 ) ;
return - V_77 ;
}
V_61 ++ ;
}
return 0 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_94 -> V_171 ;
int V_172 = V_7 -> V_94 -> V_163 ;
int V_10 , V_191 ;
for ( V_10 = 0 ; V_10 < V_172 ; V_10 ++ , V_31 ++ ) {
if ( F_5 ( V_31 -> V_33 ) == V_46 &&
( F_8 ( V_31 -> V_33 ) != V_41 ||
V_31 -> V_18 != 0 ) ) {
F_1 ( L_84 ) ;
return - V_77 ;
}
if ( V_31 [ 0 ] . V_33 == ( V_47 | V_50 | V_85 ) ) {
struct V_91 * V_92 ;
struct V_192 V_193 ;
if ( V_10 == V_172 - 1 || V_31 [ 1 ] . V_33 != 0 ||
V_31 [ 1 ] . V_37 != 0 || V_31 [ 1 ] . V_39 != 0 ||
V_31 [ 1 ] . V_43 != 0 ) {
F_1 ( L_85 ) ;
return - V_77 ;
}
if ( V_31 -> V_39 == 0 )
goto V_194;
if ( V_31 -> V_39 != V_150 ) {
F_1 ( L_86 ) ;
return - V_77 ;
}
V_193 = F_41 ( V_31 -> V_18 ) ;
V_92 = F_42 ( V_193 ) ;
if ( F_43 ( V_92 ) ) {
F_1 ( L_87 ,
V_31 -> V_18 ) ;
F_44 ( V_193 ) ;
return F_45 ( V_92 ) ;
}
V_31 [ 0 ] . V_18 = ( T_3 ) ( unsigned long ) V_92 ;
V_31 [ 1 ] . V_18 = ( ( T_4 ) ( unsigned long ) V_92 ) >> 32 ;
for ( V_191 = 0 ; V_191 < V_7 -> V_195 ; V_191 ++ )
if ( V_7 -> V_196 [ V_191 ] == V_92 ) {
F_44 ( V_193 ) ;
goto V_194;
}
if ( V_7 -> V_195 >= V_197 ) {
F_44 ( V_193 ) ;
return - V_167 ;
}
V_7 -> V_196 [ V_7 -> V_195 ++ ] = V_92 ;
F_46 ( & V_92 -> V_198 ) ;
F_44 ( V_193 ) ;
V_194:
V_31 ++ ;
V_10 ++ ;
}
}
return 0 ;
}
static void F_47 ( struct V_6 * V_7 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_195 ; V_10 ++ )
F_48 ( V_7 -> V_196 [ V_10 ] ) ;
}
static void F_49 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_94 -> V_171 ;
int V_172 = V_7 -> V_94 -> V_163 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_172 ; V_10 ++ , V_31 ++ )
if ( V_31 -> V_33 == ( V_47 | V_50 | V_85 ) )
V_31 -> V_39 = 0 ;
}
static void F_50 ( struct V_199 * V_94 , int V_200 , int V_201 )
{
struct V_30 * V_31 = V_94 -> V_171 ;
int V_172 = V_94 -> V_163 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_172 ; V_10 ++ , V_31 ++ ) {
if ( F_5 ( V_31 -> V_33 ) != V_51 ||
F_7 ( V_31 -> V_33 ) == V_53 ||
F_7 ( V_31 -> V_33 ) == V_55 )
continue;
if ( V_10 < V_200 && V_10 + V_31 -> V_43 + 1 > V_200 )
V_31 -> V_43 += V_201 ;
else if ( V_10 > V_200 && V_10 + V_31 -> V_43 + 1 < V_200 )
V_31 -> V_43 -= V_201 ;
}
}
static int F_51 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_94 -> V_171 ;
int V_172 = V_7 -> V_94 -> V_163 ;
struct V_30 V_202 [ 16 ] ;
struct V_199 * V_203 ;
T_3 V_204 ;
int V_10 ;
if ( ! V_7 -> V_94 -> V_95 -> V_96 -> V_205 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_172 ; V_10 ++ , V_31 ++ ) {
if ( V_31 -> V_33 != ( V_46 | V_41 | V_82 ) )
continue;
if ( V_31 -> V_18 != V_73 ) {
V_31 -> V_18 = 0 ;
continue;
}
V_204 = V_7 -> V_94 -> V_95 -> V_96 ->
V_205 ( V_31 -> V_37 , V_31 -> V_39 ,
V_31 -> V_43 , V_202 ) ;
if ( V_204 == 0 || V_204 >= F_52 ( V_202 ) ) {
F_1 ( L_88 ) ;
return - V_77 ;
}
if ( V_204 == 1 ) {
memcpy ( V_31 , V_202 , sizeof( * V_31 ) ) ;
continue;
}
V_172 += V_204 - 1 ;
V_203 = F_53 ( V_7 -> V_94 ,
F_54 ( V_172 ) ,
V_185 ) ;
if ( ! V_203 )
return - V_174 ;
V_203 -> V_163 = V_172 ;
memmove ( V_203 -> V_171 + V_10 + V_204 , V_203 -> V_170 + V_10 + 1 ,
sizeof( * V_31 ) * ( V_172 - V_10 - V_204 ) ) ;
memcpy ( V_203 -> V_171 + V_10 , V_202 , sizeof( * V_31 ) * V_204 ) ;
F_50 ( V_203 , V_10 , V_204 - 1 ) ;
V_7 -> V_94 = V_203 ;
V_31 = V_203 -> V_171 + V_10 + V_204 - 1 ;
V_10 += V_204 - 1 ;
}
return 0 ;
}
static void F_55 ( struct V_6 * V_7 )
{
struct V_182 * V_184 , * V_206 ;
int V_10 ;
if ( ! V_7 -> V_164 )
return;
for ( V_10 = 0 ; V_10 < V_7 -> V_94 -> V_163 ; V_10 ++ ) {
V_184 = V_7 -> V_164 [ V_10 ] ;
if ( V_184 )
while ( V_184 != V_165 ) {
V_206 = V_184 -> V_64 ;
F_11 ( V_184 ) ;
V_184 = V_206 ;
}
}
F_11 ( V_7 -> V_164 ) ;
}
int F_56 ( struct V_199 * * V_94 , union V_207 * V_208 )
{
char T_5 * V_209 = NULL ;
struct V_6 * V_7 ;
int V_173 = - V_77 ;
if ( ( * V_94 ) -> V_163 <= 0 || ( * V_94 ) -> V_163 > V_210 )
return - V_167 ;
V_7 = F_57 ( sizeof( struct V_6 ) , V_67 ) ;
if ( ! V_7 )
return - V_174 ;
V_7 -> V_94 = * V_94 ;
F_58 ( & V_211 ) ;
if ( V_208 -> V_2 || V_208 -> V_5 || V_208 -> V_4 ) {
V_2 = V_208 -> V_2 ;
V_209 = ( char T_5 * ) ( unsigned long ) V_208 -> V_5 ;
V_4 = V_208 -> V_4 ;
V_3 = 0 ;
V_173 = - V_77 ;
if ( V_4 < 128 || V_4 > V_212 >> 8 ||
V_2 == 0 || V_209 == NULL )
goto V_213;
V_173 = - V_174 ;
V_5 = F_59 ( V_4 ) ;
if ( ! V_5 )
goto V_213;
} else {
V_2 = 0 ;
}
V_173 = F_40 ( V_7 ) ;
if ( V_173 < 0 )
goto V_214;
V_7 -> V_164 = F_36 ( V_7 -> V_94 -> V_163 ,
sizeof( struct V_182 * ) ,
V_185 ) ;
V_173 = - V_174 ;
if ( ! V_7 -> V_164 )
goto V_214;
V_173 = F_35 ( V_7 ) ;
if ( V_173 < 0 )
goto V_214;
V_173 = F_39 ( V_7 ) ;
V_214:
while ( F_10 ( V_7 , NULL ) >= 0 ) ;
F_55 ( V_7 ) ;
if ( V_173 == 0 )
V_173 = F_51 ( V_7 ) ;
if ( V_2 && V_3 >= V_4 - 1 ) {
F_16 ( V_3 >= V_4 ) ;
V_173 = - V_215 ;
}
if ( V_2 && F_60 ( V_209 , V_5 , V_3 + 1 ) != 0 ) {
V_173 = - V_114 ;
goto V_216;
}
if ( V_173 == 0 && V_7 -> V_195 ) {
V_7 -> V_94 -> V_95 -> V_196 = F_61 ( V_7 -> V_195 ,
sizeof( V_7 -> V_196 [ 0 ] ) ,
V_67 ) ;
if ( ! V_7 -> V_94 -> V_95 -> V_196 ) {
V_173 = - V_174 ;
goto V_216;
}
memcpy ( V_7 -> V_94 -> V_95 -> V_196 , V_7 -> V_196 ,
sizeof( V_7 -> V_196 [ 0 ] ) * V_7 -> V_195 ) ;
V_7 -> V_94 -> V_95 -> V_195 = V_7 -> V_195 ;
F_49 ( V_7 ) ;
}
V_216:
if ( V_2 )
F_62 ( V_5 ) ;
V_213:
if ( ! V_7 -> V_94 -> V_95 -> V_196 )
F_47 ( V_7 ) ;
* V_94 = V_7 -> V_94 ;
F_11 ( V_7 ) ;
F_63 ( & V_211 ) ;
return V_173 ;
}
