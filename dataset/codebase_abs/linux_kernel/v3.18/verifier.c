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
for ( V_10 = 0 ; V_10 < V_25 ; V_10 ++ ) {
if ( V_7 -> V_12 . V_26 [ V_10 ] . V_27 == V_28 )
F_1 ( L_4 , - V_25 + V_10 ,
V_15 [ V_7 -> V_12 . V_26 [ V_10 ] . V_29 . type ] ) ;
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
struct V_89 * V_90 ;
int V_10 ;
if ( V_88 >= 0 &&
( V_86 -> V_13 [ V_88 ] . type == V_20 ||
V_86 -> V_13 [ V_88 ] . type == V_17 ||
V_86 -> V_13 [ V_88 ] . type == V_73 ) ) {
if ( V_87 != 8 ) {
F_1 ( L_31 ) ;
return - V_79 ;
}
V_90 = & V_86 -> V_26 [ V_25 + V_43 ] ;
V_90 -> V_27 = V_28 ;
V_90 -> V_29 = V_86 -> V_13 [ V_88 ] ;
for ( V_10 = 1 ; V_10 < 8 ; V_10 ++ ) {
V_90 = & V_86 -> V_26 [ V_25 + V_43 + V_10 ] ;
V_90 -> V_27 = V_91 ;
V_90 -> V_29 . type = V_75 ;
V_90 -> V_29 . V_22 = NULL ;
}
} else {
for ( V_10 = 0 ; V_10 < V_87 ; V_10 ++ ) {
V_90 = & V_86 -> V_26 [ V_25 + V_43 + V_10 ] ;
V_90 -> V_27 = V_92 ;
V_90 -> V_29 . type = V_75 ;
V_90 -> V_29 . V_22 = NULL ;
}
}
return 0 ;
}
static int F_20 ( struct V_66 * V_86 , int V_43 , int V_87 ,
int V_88 )
{
int V_10 ;
struct V_89 * V_90 ;
V_90 = & V_86 -> V_26 [ V_25 + V_43 ] ;
if ( V_90 -> V_27 == V_28 ) {
if ( V_87 != 8 ) {
F_1 ( L_31 ) ;
return - V_79 ;
}
for ( V_10 = 1 ; V_10 < 8 ; V_10 ++ ) {
if ( V_86 -> V_26 [ V_25 + V_43 + V_10 ] . V_27 !=
V_91 ) {
F_1 ( L_32 ) ;
return - V_79 ;
}
}
if ( V_88 >= 0 )
V_86 -> V_13 [ V_88 ] = V_90 -> V_29 ;
return 0 ;
} else {
for ( V_10 = 0 ; V_10 < V_87 ; V_10 ++ ) {
if ( V_86 -> V_26 [ V_25 + V_43 + V_10 ] . V_27 !=
V_92 ) {
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
struct V_93 * V_94 = V_7 -> V_12 . V_13 [ V_74 ] . V_22 ;
if ( V_43 < 0 || V_43 + V_87 > V_94 -> V_24 ) {
F_1 ( L_34 ,
V_94 -> V_24 , V_43 , V_87 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_22 ( struct V_6 * V_7 , int V_43 , int V_87 ,
enum V_95 V_9 )
{
if ( V_7 -> V_96 -> V_97 -> V_98 -> V_99 &&
V_7 -> V_96 -> V_97 -> V_98 -> V_99 ( V_43 , V_87 , V_9 ) )
return 0 ;
F_1 ( L_35 , V_43 , V_87 ) ;
return - V_79 ;
}
static int F_23 ( struct V_6 * V_7 , T_3 V_74 , int V_43 ,
int V_81 , enum V_95 V_9 ,
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
if ( ! V_68 && V_9 == V_100 && V_88 >= 0 )
F_15 ( V_86 -> V_13 , V_88 ) ;
} else if ( V_86 -> V_13 [ V_74 ] . type == V_73 ) {
V_68 = F_22 ( V_7 , V_43 , V_87 , V_9 ) ;
if ( ! V_68 && V_9 == V_100 && V_88 >= 0 )
F_15 ( V_86 -> V_13 , V_88 ) ;
} else if ( V_86 -> V_13 [ V_74 ] . type == V_71 ) {
if ( V_43 >= 0 || V_43 < - V_25 ) {
F_1 ( L_37 , V_43 , V_87 ) ;
return - V_79 ;
}
if ( V_9 == V_101 )
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
F_9 ( V_31 -> V_33 ) , V_100 , - 1 ) ;
if ( V_68 )
return V_68 ;
return F_23 ( V_7 , V_31 -> V_37 , V_31 -> V_43 ,
F_9 ( V_31 -> V_33 ) , V_101 , - 1 ) ;
}
static int F_25 ( struct V_6 * V_7 ,
int V_74 , int V_102 )
{
struct V_66 * V_86 = & V_7 -> V_12 ;
struct V_69 * V_13 = V_86 -> V_13 ;
int V_43 , V_10 ;
if ( V_13 [ V_74 ] . type != V_17 )
return - V_79 ;
V_43 = V_13 [ V_74 ] . V_18 ;
if ( V_43 >= 0 || V_43 < - V_25 || V_43 + V_102 > 0 ||
V_102 <= 0 ) {
F_1 ( L_40 ,
V_74 , V_43 , V_102 ) ;
return - V_79 ;
}
for ( V_10 = 0 ; V_10 < V_102 ; V_10 ++ ) {
if ( V_86 -> V_26 [ V_25 + V_43 + V_10 ] . V_27 != V_92 ) {
F_1 ( L_41 ,
V_43 , V_10 , V_102 ) ;
return - V_79 ;
}
}
return 0 ;
}
static int F_26 ( struct V_6 * V_7 , T_3 V_74 ,
enum V_103 V_104 , struct V_93 * * V_105 )
{
struct V_69 * V_106 = V_7 -> V_12 . V_13 + V_74 ;
enum V_8 V_107 ;
int V_68 = 0 ;
if ( V_104 == V_108 )
return 0 ;
if ( V_106 -> type == V_14 ) {
F_1 ( L_29 , V_74 ) ;
return - V_79 ;
}
if ( V_104 == V_109 || V_104 == V_110 ||
V_104 == V_111 ) {
V_107 = V_17 ;
} else if ( V_104 == V_112 ) {
V_107 = V_16 ;
} else if ( V_104 == V_113 ) {
V_107 = V_19 ;
} else {
F_1 ( L_42 , V_104 ) ;
return - V_114 ;
}
if ( V_106 -> type != V_107 ) {
F_1 ( L_43 , V_74 ,
V_15 [ V_106 -> type ] , V_15 [ V_107 ] ) ;
return - V_79 ;
}
if ( V_104 == V_113 ) {
* V_105 = V_106 -> V_22 ;
} else if ( V_104 == V_110 ) {
if ( ! * V_105 ) {
F_1 ( L_44 ) ;
return - V_79 ;
}
V_68 = F_25 ( V_7 , V_74 , ( * V_105 ) -> V_23 ) ;
} else if ( V_104 == V_111 ) {
if ( ! * V_105 ) {
F_1 ( L_45 ) ;
return - V_79 ;
}
V_68 = F_25 ( V_7 , V_74 , ( * V_105 ) -> V_24 ) ;
} else if ( V_104 == V_112 ) {
if ( V_74 == 0 ) {
F_1 ( L_46 ) ;
return - V_79 ;
}
V_68 = F_25 ( V_7 , V_74 - 1 , V_106 -> V_18 ) ;
}
return V_68 ;
}
static int F_27 ( struct V_6 * V_7 , int V_115 )
{
struct V_66 * V_86 = & V_7 -> V_12 ;
const struct V_116 * V_117 = NULL ;
struct V_69 * V_13 = V_86 -> V_13 ;
struct V_93 * V_94 = NULL ;
struct V_69 * V_106 ;
int V_10 , V_68 ;
if ( V_115 < 0 || V_115 >= V_118 ) {
F_1 ( L_47 , V_115 ) ;
return - V_77 ;
}
if ( V_7 -> V_96 -> V_97 -> V_98 -> V_119 )
V_117 = V_7 -> V_96 -> V_97 -> V_98 -> V_119 ( V_115 ) ;
if ( ! V_117 ) {
F_1 ( L_48 , V_115 ) ;
return - V_77 ;
}
if ( ! V_7 -> V_96 -> V_97 -> V_120 && V_117 -> V_121 ) {
F_1 ( L_49 ) ;
return - V_77 ;
}
V_68 = F_26 ( V_7 , V_72 , V_117 -> V_122 , & V_94 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_123 , V_117 -> V_124 , & V_94 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_125 , V_117 -> V_126 , & V_94 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_127 , V_117 -> V_128 , & V_94 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_129 , V_117 -> V_130 , & V_94 ) ;
if ( V_68 )
return V_68 ;
for ( V_10 = 0 ; V_10 < V_131 ; V_10 ++ ) {
V_106 = V_13 + V_132 [ V_10 ] ;
V_106 -> type = V_14 ;
V_106 -> V_18 = 0 ;
}
if ( V_117 -> V_133 == V_134 ) {
V_13 [ V_135 ] . type = V_75 ;
} else if ( V_117 -> V_133 == V_136 ) {
V_13 [ V_135 ] . type = V_14 ;
} else if ( V_117 -> V_133 == V_137 ) {
V_13 [ V_135 ] . type = V_21 ;
if ( V_94 == NULL ) {
F_1 ( L_50 ) ;
return - V_77 ;
}
V_13 [ V_135 ] . V_22 = V_94 ;
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
static struct V_93 * F_30 ( struct V_30 * V_31 )
{
T_4 V_149 = ( ( T_4 ) ( T_3 ) V_31 [ 0 ] . V_18 ) | ( ( T_4 ) ( T_3 ) V_31 [ 1 ] . V_18 ) << 32 ;
return (struct V_93 * ) ( unsigned long ) V_149 ;
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
static int F_32 ( int V_9 , int V_151 , int V_152 , struct V_6 * V_7 )
{
if ( V_152 == V_153 && V_154 [ V_9 ] >= ( V_155 | V_153 ) )
return 0 ;
if ( V_152 == V_156 && V_154 [ V_9 ] >= ( V_155 | V_156 ) )
return 0 ;
if ( V_151 < 0 || V_151 >= V_7 -> V_96 -> V_157 ) {
F_1 ( L_62 , V_9 , V_151 ) ;
return - V_77 ;
}
if ( V_152 == V_156 )
V_7 -> V_158 [ V_151 ] = V_159 ;
if ( V_154 [ V_151 ] == 0 ) {
V_154 [ V_9 ] = V_155 | V_152 ;
V_154 [ V_151 ] = V_155 ;
if ( V_160 >= V_7 -> V_96 -> V_157 )
return - V_161 ;
V_162 [ V_160 ++ ] = V_151 ;
return 1 ;
} else if ( ( V_154 [ V_151 ] & 0xF0 ) == V_155 ) {
F_1 ( L_63 , V_9 , V_151 ) ;
return - V_77 ;
} else if ( V_154 [ V_151 ] == V_163 ) {
V_154 [ V_9 ] = V_155 | V_152 ;
} else {
F_1 ( L_64 ) ;
return - V_114 ;
}
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_30 * V_164 = V_7 -> V_96 -> V_165 ;
int V_166 = V_7 -> V_96 -> V_157 ;
int V_167 = 0 ;
int V_10 , V_9 ;
V_154 = F_34 ( V_166 , sizeof( int ) , V_67 ) ;
if ( ! V_154 )
return - V_168 ;
V_162 = F_34 ( V_166 , sizeof( int ) , V_67 ) ;
if ( ! V_162 ) {
F_11 ( V_154 ) ;
return - V_168 ;
}
V_154 [ 0 ] = V_155 ;
V_162 [ 0 ] = 0 ;
V_160 = 1 ;
V_169:
if ( V_160 == 0 )
goto V_170;
V_9 = V_162 [ V_160 - 1 ] ;
if ( F_5 ( V_164 [ V_9 ] . V_33 ) == V_51 ) {
T_2 V_52 = F_7 ( V_164 [ V_9 ] . V_33 ) ;
if ( V_52 == V_55 ) {
goto V_171;
} else if ( V_52 == V_53 ) {
V_167 = F_32 ( V_9 , V_9 + 1 , V_153 , V_7 ) ;
if ( V_167 == 1 )
goto V_169;
else if ( V_167 < 0 )
goto V_172;
} else if ( V_52 == V_54 ) {
if ( F_6 ( V_164 [ V_9 ] . V_33 ) != V_144 ) {
V_167 = - V_77 ;
goto V_172;
}
V_167 = F_32 ( V_9 , V_9 + V_164 [ V_9 ] . V_43 + 1 ,
V_153 , V_7 ) ;
if ( V_167 == 1 )
goto V_169;
else if ( V_167 < 0 )
goto V_172;
V_7 -> V_158 [ V_9 + 1 ] = V_159 ;
} else {
V_167 = F_32 ( V_9 , V_9 + 1 , V_153 , V_7 ) ;
if ( V_167 == 1 )
goto V_169;
else if ( V_167 < 0 )
goto V_172;
V_167 = F_32 ( V_9 , V_9 + V_164 [ V_9 ] . V_43 + 1 , V_156 , V_7 ) ;
if ( V_167 == 1 )
goto V_169;
else if ( V_167 < 0 )
goto V_172;
}
} else {
V_167 = F_32 ( V_9 , V_9 + 1 , V_153 , V_7 ) ;
if ( V_167 == 1 )
goto V_169;
else if ( V_167 < 0 )
goto V_172;
}
V_171:
V_154 [ V_9 ] = V_163 ;
if ( V_160 -- <= 0 ) {
F_1 ( L_65 ) ;
V_167 = - V_114 ;
goto V_172;
}
goto V_169;
V_170:
for ( V_10 = 0 ; V_10 < V_166 ; V_10 ++ ) {
if ( V_154 [ V_10 ] != V_163 ) {
F_1 ( L_66 , V_10 ) ;
V_167 = - V_77 ;
goto V_172;
}
}
V_167 = 0 ;
V_172:
F_11 ( V_154 ) ;
F_11 ( V_162 ) ;
return V_167 ;
}
static bool F_35 ( struct V_66 * V_173 , struct V_66 * V_174 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( memcmp ( & V_173 -> V_13 [ V_10 ] , & V_174 -> V_13 [ V_10 ] ,
sizeof( V_173 -> V_13 [ 0 ] ) ) != 0 ) {
if ( V_173 -> V_13 [ V_10 ] . type == V_14 ||
( V_173 -> V_13 [ V_10 ] . type == V_75 &&
V_174 -> V_13 [ V_10 ] . type != V_14 ) )
continue;
return false ;
}
}
for ( V_10 = 0 ; V_10 < V_25 ; V_10 ++ ) {
if ( memcmp ( & V_173 -> V_26 [ V_10 ] , & V_174 -> V_26 [ V_10 ] ,
sizeof( V_173 -> V_26 [ 0 ] ) ) != 0 ) {
if ( V_173 -> V_26 [ V_10 ] . V_27 == V_175 )
continue;
return false ;
}
}
return true ;
}
static int F_36 ( struct V_6 * V_7 , int V_61 )
{
struct V_176 * V_177 ;
struct V_176 * V_178 ;
V_178 = V_7 -> V_158 [ V_61 ] ;
if ( ! V_178 )
return 0 ;
while ( V_178 != V_159 ) {
if ( F_35 ( & V_178 -> V_86 , & V_7 -> V_12 ) )
return 1 ;
V_178 = V_178 -> V_64 ;
}
V_177 = F_13 ( sizeof( struct V_176 ) , V_179 ) ;
if ( ! V_177 )
return - V_168 ;
memcpy ( & V_177 -> V_86 , & V_7 -> V_12 , sizeof( V_7 -> V_12 ) ) ;
V_177 -> V_64 = V_7 -> V_158 [ V_61 ] ;
V_7 -> V_158 [ V_61 ] = V_177 ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 )
{
struct V_66 * V_86 = & V_7 -> V_12 ;
struct V_30 * V_164 = V_7 -> V_96 -> V_165 ;
struct V_69 * V_13 = V_86 -> V_13 ;
int V_166 = V_7 -> V_96 -> V_157 ;
int V_61 , V_58 = 0 ;
int V_180 = 0 ;
bool V_181 = false ;
F_14 ( V_13 ) ;
V_61 = 0 ;
for (; ; ) {
struct V_30 * V_31 ;
T_2 V_32 ;
int V_68 ;
if ( V_61 >= V_166 ) {
F_1 ( L_67 ,
V_61 , V_166 ) ;
return - V_114 ;
}
V_31 = & V_164 [ V_61 ] ;
V_32 = F_5 ( V_31 -> V_33 ) ;
if ( ++ V_180 > 32768 ) {
F_1 ( L_68 ,
V_180 ) ;
return - V_161 ;
}
V_68 = F_36 ( V_7 , V_61 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_68 == 1 ) {
if ( V_2 ) {
if ( V_181 )
F_1 ( L_69 ,
V_58 , V_61 ) ;
else
F_1 ( L_70 , V_61 ) ;
}
goto V_182;
}
if ( V_2 && V_181 ) {
F_1 ( L_71 , V_58 , V_61 ) ;
F_3 ( V_7 ) ;
V_181 = false ;
}
if ( V_2 ) {
F_1 ( L_72 , V_61 ) ;
F_4 ( V_31 ) ;
}
if ( V_32 == V_34 || V_32 == V_35 ) {
V_68 = F_28 ( V_13 , V_31 ) ;
if ( V_68 )
return V_68 ;
} else if ( V_32 == V_46 ) {
if ( F_8 ( V_31 -> V_33 ) != V_41 ||
V_31 -> V_18 != 0 ) {
F_1 ( L_73 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_183 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_23 ( V_7 , V_31 -> V_39 , V_31 -> V_43 ,
F_9 ( V_31 -> V_33 ) , V_100 ,
V_31 -> V_37 ) ;
if ( V_68 )
return V_68 ;
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
F_1 ( L_74 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_23 ( V_7 , V_31 -> V_37 , V_31 -> V_43 ,
F_9 ( V_31 -> V_33 ) , V_101 ,
V_31 -> V_39 ) ;
if ( V_68 )
return V_68 ;
} else if ( V_32 == V_45 ) {
if ( F_8 ( V_31 -> V_33 ) != V_41 ||
V_31 -> V_39 != V_135 ) {
F_1 ( L_75 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_23 ( V_7 , V_31 -> V_37 , V_31 -> V_43 ,
F_9 ( V_31 -> V_33 ) , V_101 ,
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
F_1 ( L_76 ) ;
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
F_1 ( L_77 ) ;
return - V_77 ;
}
V_61 += V_31 -> V_43 + 1 ;
continue;
} else if ( V_52 == V_55 ) {
if ( F_6 ( V_31 -> V_33 ) != V_144 ||
V_31 -> V_18 != 0 ||
V_31 -> V_39 != V_135 ||
V_31 -> V_37 != V_135 ) {
F_1 ( L_78 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_135 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_182:
V_61 = F_10 ( V_7 , & V_58 ) ;
if ( V_61 < 0 ) {
break;
} else {
V_181 = true ;
continue;
}
} else {
V_68 = F_29 ( V_7 , V_31 , & V_61 ) ;
if ( V_68 )
return V_68 ;
}
} else if ( V_32 == V_47 ) {
T_2 V_184 = F_8 ( V_31 -> V_33 ) ;
if ( V_184 == V_48 || V_184 == V_49 ) {
F_1 ( L_79 ) ;
return - V_77 ;
} else if ( V_184 == V_50 ) {
V_68 = F_31 ( V_7 , V_31 ) ;
if ( V_68 )
return V_68 ;
V_61 ++ ;
} else {
F_1 ( L_80 ) ;
return - V_77 ;
}
} else {
F_1 ( L_81 , V_32 ) ;
return - V_77 ;
}
V_61 ++ ;
}
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_96 -> V_165 ;
int V_166 = V_7 -> V_96 -> V_157 ;
int V_10 , V_185 ;
for ( V_10 = 0 ; V_10 < V_166 ; V_10 ++ , V_31 ++ ) {
if ( V_31 [ 0 ] . V_33 == ( V_47 | V_50 | V_85 ) ) {
struct V_93 * V_94 ;
struct V_186 V_187 ;
if ( V_10 == V_166 - 1 || V_31 [ 1 ] . V_33 != 0 ||
V_31 [ 1 ] . V_37 != 0 || V_31 [ 1 ] . V_39 != 0 ||
V_31 [ 1 ] . V_43 != 0 ) {
F_1 ( L_82 ) ;
return - V_77 ;
}
if ( V_31 -> V_39 == 0 )
goto V_188;
if ( V_31 -> V_39 != V_150 ) {
F_1 ( L_83 ) ;
return - V_77 ;
}
V_187 = F_39 ( V_31 -> V_18 ) ;
V_94 = F_40 ( V_187 ) ;
if ( F_41 ( V_94 ) ) {
F_1 ( L_84 ,
V_31 -> V_18 ) ;
F_42 ( V_187 ) ;
return F_43 ( V_94 ) ;
}
V_31 [ 0 ] . V_18 = ( T_3 ) ( unsigned long ) V_94 ;
V_31 [ 1 ] . V_18 = ( ( T_4 ) ( unsigned long ) V_94 ) >> 32 ;
for ( V_185 = 0 ; V_185 < V_7 -> V_189 ; V_185 ++ )
if ( V_7 -> V_190 [ V_185 ] == V_94 ) {
F_42 ( V_187 ) ;
goto V_188;
}
if ( V_7 -> V_189 >= V_191 ) {
F_42 ( V_187 ) ;
return - V_161 ;
}
V_7 -> V_190 [ V_7 -> V_189 ++ ] = V_94 ;
F_44 ( & V_94 -> V_192 ) ;
F_42 ( V_187 ) ;
V_188:
V_31 ++ ;
V_10 ++ ;
}
}
return 0 ;
}
static void F_45 ( struct V_6 * V_7 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_189 ; V_10 ++ )
F_46 ( V_7 -> V_190 [ V_10 ] ) ;
}
static void F_47 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_96 -> V_165 ;
int V_166 = V_7 -> V_96 -> V_157 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_166 ; V_10 ++ , V_31 ++ )
if ( V_31 -> V_33 == ( V_47 | V_50 | V_85 ) )
V_31 -> V_39 = 0 ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_176 * V_178 , * V_193 ;
int V_10 ;
if ( ! V_7 -> V_158 )
return;
for ( V_10 = 0 ; V_10 < V_7 -> V_96 -> V_157 ; V_10 ++ ) {
V_178 = V_7 -> V_158 [ V_10 ] ;
if ( V_178 )
while ( V_178 != V_159 ) {
V_193 = V_178 -> V_64 ;
F_11 ( V_178 ) ;
V_178 = V_193 ;
}
}
F_11 ( V_7 -> V_158 ) ;
}
int F_49 ( struct V_194 * V_96 , union V_195 * V_196 )
{
char T_5 * V_197 = NULL ;
struct V_6 * V_7 ;
int V_167 = - V_77 ;
if ( V_96 -> V_157 <= 0 || V_96 -> V_157 > V_198 )
return - V_161 ;
V_7 = F_50 ( sizeof( struct V_6 ) , V_67 ) ;
if ( ! V_7 )
return - V_168 ;
V_7 -> V_96 = V_96 ;
F_51 ( & V_199 ) ;
if ( V_196 -> V_2 || V_196 -> V_5 || V_196 -> V_4 ) {
V_2 = V_196 -> V_2 ;
V_197 = ( char T_5 * ) ( unsigned long ) V_196 -> V_5 ;
V_4 = V_196 -> V_4 ;
V_3 = 0 ;
V_167 = - V_77 ;
if ( V_4 < 128 || V_4 > V_200 >> 8 ||
V_2 == 0 || V_197 == NULL )
goto V_201;
V_167 = - V_168 ;
V_5 = F_52 ( V_4 ) ;
if ( ! V_5 )
goto V_201;
} else {
V_2 = 0 ;
}
V_167 = F_38 ( V_7 ) ;
if ( V_167 < 0 )
goto V_202;
V_7 -> V_158 = F_34 ( V_96 -> V_157 ,
sizeof( struct V_176 * ) ,
V_179 ) ;
V_167 = - V_168 ;
if ( ! V_7 -> V_158 )
goto V_202;
V_167 = F_33 ( V_7 ) ;
if ( V_167 < 0 )
goto V_202;
V_167 = F_37 ( V_7 ) ;
V_202:
while ( F_10 ( V_7 , NULL ) >= 0 ) ;
F_48 ( V_7 ) ;
if ( V_2 && V_3 >= V_4 - 1 ) {
F_16 ( V_3 >= V_4 ) ;
V_167 = - V_203 ;
}
if ( V_2 && F_53 ( V_197 , V_5 , V_3 + 1 ) != 0 ) {
V_167 = - V_114 ;
goto V_204;
}
if ( V_167 == 0 && V_7 -> V_189 ) {
V_96 -> V_97 -> V_190 = F_54 ( V_7 -> V_189 ,
sizeof( V_7 -> V_190 [ 0 ] ) ,
V_67 ) ;
if ( ! V_96 -> V_97 -> V_190 ) {
V_167 = - V_168 ;
goto V_204;
}
memcpy ( V_96 -> V_97 -> V_190 , V_7 -> V_190 ,
sizeof( V_7 -> V_190 [ 0 ] ) * V_7 -> V_189 ) ;
V_96 -> V_97 -> V_189 = V_7 -> V_189 ;
F_47 ( V_7 ) ;
}
V_204:
if ( V_2 )
F_55 ( V_5 ) ;
V_201:
if ( ! V_96 -> V_97 -> V_190 )
F_45 ( V_7 ) ;
F_11 ( V_7 ) ;
F_56 ( & V_199 ) ;
return V_167 ;
}
