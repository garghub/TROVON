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
if ( V_102 == V_107 || V_102 == V_108 ||
V_102 == V_109 ) {
V_105 = V_17 ;
} else if ( V_102 == V_110 ) {
V_105 = V_16 ;
} else if ( V_102 == V_111 ) {
V_105 = V_19 ;
} else {
F_1 ( L_42 , V_102 ) ;
return - V_112 ;
}
if ( V_104 -> type != V_105 ) {
F_1 ( L_43 , V_74 ,
V_15 [ V_104 -> type ] , V_15 [ V_105 ] ) ;
return - V_79 ;
}
if ( V_102 == V_111 ) {
* V_103 = V_104 -> V_22 ;
} else if ( V_102 == V_108 ) {
if ( ! * V_103 ) {
F_1 ( L_44 ) ;
return - V_79 ;
}
V_68 = F_25 ( V_7 , V_74 , ( * V_103 ) -> V_23 ) ;
} else if ( V_102 == V_109 ) {
if ( ! * V_103 ) {
F_1 ( L_45 ) ;
return - V_79 ;
}
V_68 = F_25 ( V_7 , V_74 , ( * V_103 ) -> V_24 ) ;
} else if ( V_102 == V_110 ) {
if ( V_74 == 0 ) {
F_1 ( L_46 ) ;
return - V_79 ;
}
V_68 = F_25 ( V_7 , V_74 - 1 , V_104 -> V_18 ) ;
}
return V_68 ;
}
static int F_27 ( struct V_6 * V_7 , int V_113 )
{
struct V_66 * V_86 = & V_7 -> V_12 ;
const struct V_114 * V_115 = NULL ;
struct V_69 * V_13 = V_86 -> V_13 ;
struct V_91 * V_92 = NULL ;
struct V_69 * V_104 ;
int V_10 , V_68 ;
if ( V_113 < 0 || V_113 >= V_116 ) {
F_1 ( L_47 , V_113 ) ;
return - V_77 ;
}
if ( V_7 -> V_94 -> V_95 -> V_96 -> V_117 )
V_115 = V_7 -> V_94 -> V_95 -> V_96 -> V_117 ( V_113 ) ;
if ( ! V_115 ) {
F_1 ( L_48 , V_113 ) ;
return - V_77 ;
}
if ( ! V_7 -> V_94 -> V_95 -> V_118 && V_115 -> V_119 ) {
F_1 ( L_49 ) ;
return - V_77 ;
}
V_68 = F_26 ( V_7 , V_72 , V_115 -> V_120 , & V_92 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_121 , V_115 -> V_122 , & V_92 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_123 , V_115 -> V_124 , & V_92 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_125 , V_115 -> V_126 , & V_92 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_26 ( V_7 , V_127 , V_115 -> V_128 , & V_92 ) ;
if ( V_68 )
return V_68 ;
for ( V_10 = 0 ; V_10 < V_129 ; V_10 ++ ) {
V_104 = V_13 + V_130 [ V_10 ] ;
V_104 -> type = V_14 ;
V_104 -> V_18 = 0 ;
}
if ( V_115 -> V_131 == V_132 ) {
V_13 [ V_133 ] . type = V_75 ;
} else if ( V_115 -> V_131 == V_134 ) {
V_13 [ V_133 ] . type = V_14 ;
} else if ( V_115 -> V_131 == V_135 ) {
V_13 [ V_133 ] . type = V_21 ;
if ( V_92 == NULL ) {
F_1 ( L_50 ) ;
return - V_77 ;
}
V_13 [ V_133 ] . V_22 = V_92 ;
} else {
F_1 ( L_51 ,
V_115 -> V_131 , V_113 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_28 ( struct V_69 * V_13 , struct V_30 * V_31 )
{
T_2 V_52 = F_7 ( V_31 -> V_33 ) ;
int V_68 ;
if ( V_52 == V_136 || V_52 == V_137 ) {
if ( V_52 == V_137 ) {
if ( F_6 ( V_31 -> V_33 ) != 0 ||
V_31 -> V_39 != V_133 ||
V_31 -> V_43 != 0 || V_31 -> V_18 != 0 ) {
F_1 ( L_52 ) ;
return - V_77 ;
}
} else {
if ( V_31 -> V_39 != V_133 || V_31 -> V_43 != 0 ||
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
} else if ( V_52 == V_138 ) {
if ( F_6 ( V_31 -> V_33 ) == V_36 ) {
if ( V_31 -> V_18 != 0 || V_31 -> V_43 != 0 ) {
F_1 ( L_54 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
} else {
if ( V_31 -> V_39 != V_133 || V_31 -> V_43 != 0 ) {
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
} else if ( V_52 > V_136 ) {
F_1 ( L_55 , V_52 ) ;
return - V_77 ;
} else {
bool V_139 = false ;
if ( F_6 ( V_31 -> V_33 ) == V_36 ) {
if ( V_31 -> V_18 != 0 || V_31 -> V_43 != 0 ) {
F_1 ( L_56 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
} else {
if ( V_31 -> V_39 != V_133 || V_31 -> V_43 != 0 ) {
F_1 ( L_56 ) ;
return - V_77 ;
}
}
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_78 ) ;
if ( V_68 )
return V_68 ;
if ( ( V_52 == V_140 || V_52 == V_141 ) &&
F_6 ( V_31 -> V_33 ) == V_142 && V_31 -> V_18 == 0 ) {
F_1 ( L_57 ) ;
return - V_77 ;
}
if ( V_52 == V_143 && F_5 ( V_31 -> V_33 ) == V_35 &&
V_13 [ V_31 -> V_37 ] . type == V_71 &&
F_6 ( V_31 -> V_33 ) == V_142 )
V_139 = true ;
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_80 ) ;
if ( V_68 )
return V_68 ;
if ( V_139 ) {
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
struct V_66 * V_144 ;
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
if ( V_31 -> V_39 != V_133 ) {
F_1 ( L_59 ) ;
return - V_77 ;
}
}
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_78 ) ;
if ( V_68 )
return V_68 ;
if ( F_6 ( V_31 -> V_33 ) == V_142 &&
( V_52 == V_145 || V_52 == V_146 ) &&
V_13 [ V_31 -> V_37 ] . type == V_16 &&
V_13 [ V_31 -> V_37 ] . V_18 == V_31 -> V_18 ) {
if ( V_52 == V_145 ) {
* V_61 += V_31 -> V_43 ;
return 0 ;
} else {
return 0 ;
}
}
V_144 = F_12 ( V_7 , * V_61 + V_31 -> V_43 + 1 , * V_61 ) ;
if ( ! V_144 )
return - V_112 ;
if ( F_6 ( V_31 -> V_33 ) == V_142 &&
V_31 -> V_18 == 0 && ( V_52 == V_145 ||
V_52 == V_146 ) &&
V_13 [ V_31 -> V_37 ] . type == V_21 ) {
if ( V_52 == V_145 ) {
V_13 [ V_31 -> V_37 ] . type = V_20 ;
V_144 -> V_13 [ V_31 -> V_37 ] . type = V_16 ;
V_144 -> V_13 [ V_31 -> V_37 ] . V_18 = 0 ;
} else {
V_144 -> V_13 [ V_31 -> V_37 ] . type = V_20 ;
V_13 [ V_31 -> V_37 ] . type = V_16 ;
V_13 [ V_31 -> V_37 ] . V_18 = 0 ;
}
} else if ( F_6 ( V_31 -> V_33 ) == V_142 &&
( V_52 == V_145 || V_52 == V_146 ) ) {
if ( V_52 == V_145 ) {
V_144 -> V_13 [ V_31 -> V_37 ] . type = V_16 ;
V_144 -> V_13 [ V_31 -> V_37 ] . V_18 = V_31 -> V_18 ;
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
T_4 V_147 = ( ( T_4 ) ( T_3 ) V_31 [ 0 ] . V_18 ) | ( ( T_4 ) ( T_3 ) V_31 [ 1 ] . V_18 ) << 32 ;
return (struct V_91 * ) ( unsigned long ) V_147 ;
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
F_16 ( V_31 -> V_39 != V_148 ) ;
V_13 [ V_31 -> V_37 ] . type = V_19 ;
V_13 [ V_31 -> V_37 ] . V_22 = F_30 ( V_31 ) ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
struct V_69 * V_13 = V_7 -> V_12 . V_13 ;
T_2 V_149 = F_8 ( V_31 -> V_33 ) ;
struct V_69 * V_104 ;
int V_10 , V_68 ;
if ( V_7 -> V_94 -> V_95 -> V_150 != V_151 ) {
F_1 ( L_62 ) ;
return - V_77 ;
}
if ( V_31 -> V_37 != V_133 || V_31 -> V_43 != 0 ||
( V_149 == V_48 && V_31 -> V_39 != V_133 ) ) {
F_1 ( L_63 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_152 , V_78 ) ;
if ( V_68 )
return V_68 ;
if ( V_13 [ V_152 ] . type != V_73 ) {
F_1 ( L_64 ) ;
return - V_77 ;
}
if ( V_149 == V_49 ) {
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
}
for ( V_10 = 0 ; V_10 < V_129 ; V_10 ++ ) {
V_104 = V_13 + V_130 [ V_10 ] ;
V_104 -> type = V_14 ;
V_104 -> V_18 = 0 ;
}
V_13 [ V_133 ] . type = V_75 ;
return 0 ;
}
static int F_33 ( int V_9 , int V_153 , int V_154 , struct V_6 * V_7 )
{
if ( V_154 == V_155 && V_156 [ V_9 ] >= ( V_157 | V_155 ) )
return 0 ;
if ( V_154 == V_158 && V_156 [ V_9 ] >= ( V_157 | V_158 ) )
return 0 ;
if ( V_153 < 0 || V_153 >= V_7 -> V_94 -> V_159 ) {
F_1 ( L_65 , V_9 , V_153 ) ;
return - V_77 ;
}
if ( V_154 == V_158 )
V_7 -> V_160 [ V_153 ] = V_161 ;
if ( V_156 [ V_153 ] == 0 ) {
V_156 [ V_9 ] = V_157 | V_154 ;
V_156 [ V_153 ] = V_157 ;
if ( V_162 >= V_7 -> V_94 -> V_159 )
return - V_163 ;
V_164 [ V_162 ++ ] = V_153 ;
return 1 ;
} else if ( ( V_156 [ V_153 ] & 0xF0 ) == V_157 ) {
F_1 ( L_66 , V_9 , V_153 ) ;
return - V_77 ;
} else if ( V_156 [ V_153 ] == V_165 ) {
V_156 [ V_9 ] = V_157 | V_154 ;
} else {
F_1 ( L_67 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_34 ( struct V_6 * V_7 )
{
struct V_30 * V_166 = V_7 -> V_94 -> V_167 ;
int V_168 = V_7 -> V_94 -> V_159 ;
int V_169 = 0 ;
int V_10 , V_9 ;
V_156 = F_35 ( V_168 , sizeof( int ) , V_67 ) ;
if ( ! V_156 )
return - V_170 ;
V_164 = F_35 ( V_168 , sizeof( int ) , V_67 ) ;
if ( ! V_164 ) {
F_11 ( V_156 ) ;
return - V_170 ;
}
V_156 [ 0 ] = V_157 ;
V_164 [ 0 ] = 0 ;
V_162 = 1 ;
V_171:
if ( V_162 == 0 )
goto V_172;
V_9 = V_164 [ V_162 - 1 ] ;
if ( F_5 ( V_166 [ V_9 ] . V_33 ) == V_51 ) {
T_2 V_52 = F_7 ( V_166 [ V_9 ] . V_33 ) ;
if ( V_52 == V_55 ) {
goto V_173;
} else if ( V_52 == V_53 ) {
V_169 = F_33 ( V_9 , V_9 + 1 , V_155 , V_7 ) ;
if ( V_169 == 1 )
goto V_171;
else if ( V_169 < 0 )
goto V_174;
} else if ( V_52 == V_54 ) {
if ( F_6 ( V_166 [ V_9 ] . V_33 ) != V_142 ) {
V_169 = - V_77 ;
goto V_174;
}
V_169 = F_33 ( V_9 , V_9 + V_166 [ V_9 ] . V_43 + 1 ,
V_155 , V_7 ) ;
if ( V_169 == 1 )
goto V_171;
else if ( V_169 < 0 )
goto V_174;
V_7 -> V_160 [ V_9 + 1 ] = V_161 ;
} else {
V_169 = F_33 ( V_9 , V_9 + 1 , V_155 , V_7 ) ;
if ( V_169 == 1 )
goto V_171;
else if ( V_169 < 0 )
goto V_174;
V_169 = F_33 ( V_9 , V_9 + V_166 [ V_9 ] . V_43 + 1 , V_158 , V_7 ) ;
if ( V_169 == 1 )
goto V_171;
else if ( V_169 < 0 )
goto V_174;
}
} else {
V_169 = F_33 ( V_9 , V_9 + 1 , V_155 , V_7 ) ;
if ( V_169 == 1 )
goto V_171;
else if ( V_169 < 0 )
goto V_174;
}
V_173:
V_156 [ V_9 ] = V_165 ;
if ( V_162 -- <= 0 ) {
F_1 ( L_68 ) ;
V_169 = - V_112 ;
goto V_174;
}
goto V_171;
V_172:
for ( V_10 = 0 ; V_10 < V_168 ; V_10 ++ ) {
if ( V_156 [ V_10 ] != V_165 ) {
F_1 ( L_69 , V_10 ) ;
V_169 = - V_77 ;
goto V_174;
}
}
V_169 = 0 ;
V_174:
F_11 ( V_156 ) ;
F_11 ( V_164 ) ;
return V_169 ;
}
static bool F_36 ( struct V_66 * V_175 , struct V_66 * V_176 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( memcmp ( & V_175 -> V_13 [ V_10 ] , & V_176 -> V_13 [ V_10 ] ,
sizeof( V_175 -> V_13 [ 0 ] ) ) != 0 ) {
if ( V_175 -> V_13 [ V_10 ] . type == V_14 ||
( V_175 -> V_13 [ V_10 ] . type == V_75 &&
V_176 -> V_13 [ V_10 ] . type != V_14 ) )
continue;
return false ;
}
}
for ( V_10 = 0 ; V_10 < V_25 ; V_10 ++ ) {
if ( V_175 -> V_27 [ V_10 ] == V_177 )
continue;
if ( V_175 -> V_27 [ V_10 ] != V_176 -> V_27 [ V_10 ] )
return false ;
if ( V_10 % V_26 )
continue;
if ( memcmp ( & V_175 -> V_29 [ V_10 / V_26 ] ,
& V_176 -> V_29 [ V_10 / V_26 ] ,
sizeof( V_175 -> V_29 [ 0 ] ) ) )
return false ;
else
continue;
}
return true ;
}
static int F_37 ( struct V_6 * V_7 , int V_61 )
{
struct V_178 * V_179 ;
struct V_178 * V_180 ;
V_180 = V_7 -> V_160 [ V_61 ] ;
if ( ! V_180 )
return 0 ;
while ( V_180 != V_161 ) {
if ( F_36 ( & V_180 -> V_86 , & V_7 -> V_12 ) )
return 1 ;
V_180 = V_180 -> V_64 ;
}
V_179 = F_13 ( sizeof( struct V_178 ) , V_181 ) ;
if ( ! V_179 )
return - V_170 ;
memcpy ( & V_179 -> V_86 , & V_7 -> V_12 , sizeof( V_7 -> V_12 ) ) ;
V_179 -> V_64 = V_7 -> V_160 [ V_61 ] ;
V_7 -> V_160 [ V_61 ] = V_179 ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_66 * V_86 = & V_7 -> V_12 ;
struct V_30 * V_166 = V_7 -> V_94 -> V_167 ;
struct V_69 * V_13 = V_86 -> V_13 ;
int V_168 = V_7 -> V_94 -> V_159 ;
int V_61 , V_58 = 0 ;
int V_182 = 0 ;
bool V_183 = false ;
F_14 ( V_13 ) ;
V_61 = 0 ;
for (; ; ) {
struct V_30 * V_31 ;
T_2 V_32 ;
int V_68 ;
if ( V_61 >= V_168 ) {
F_1 ( L_70 ,
V_61 , V_168 ) ;
return - V_112 ;
}
V_31 = & V_166 [ V_61 ] ;
V_32 = F_5 ( V_31 -> V_33 ) ;
if ( ++ V_182 > 32768 ) {
F_1 ( L_71 ,
V_182 ) ;
return - V_163 ;
}
V_68 = F_37 ( V_7 , V_61 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_68 == 1 ) {
if ( V_2 ) {
if ( V_183 )
F_1 ( L_72 ,
V_58 , V_61 ) ;
else
F_1 ( L_73 , V_61 ) ;
}
goto V_184;
}
if ( V_2 && V_183 ) {
F_1 ( L_74 , V_58 , V_61 ) ;
F_3 ( V_7 ) ;
V_183 = false ;
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
if ( F_8 ( V_31 -> V_33 ) != V_41 ||
V_31 -> V_18 != 0 ) {
F_1 ( L_76 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_31 -> V_39 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_17 ( V_13 , V_31 -> V_37 , V_185 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_23 ( V_7 , V_31 -> V_39 , V_31 -> V_43 ,
F_9 ( V_31 -> V_33 ) , V_98 ,
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
V_31 -> V_39 != V_133 ) {
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
if ( F_6 ( V_31 -> V_33 ) != V_142 ||
V_31 -> V_43 != 0 ||
V_31 -> V_39 != V_133 ||
V_31 -> V_37 != V_133 ) {
F_1 ( L_79 ) ;
return - V_77 ;
}
V_68 = F_27 ( V_7 , V_31 -> V_18 ) ;
if ( V_68 )
return V_68 ;
} else if ( V_52 == V_54 ) {
if ( F_6 ( V_31 -> V_33 ) != V_142 ||
V_31 -> V_18 != 0 ||
V_31 -> V_39 != V_133 ||
V_31 -> V_37 != V_133 ) {
F_1 ( L_80 ) ;
return - V_77 ;
}
V_61 += V_31 -> V_43 + 1 ;
continue;
} else if ( V_52 == V_55 ) {
if ( F_6 ( V_31 -> V_33 ) != V_142 ||
V_31 -> V_18 != 0 ||
V_31 -> V_39 != V_133 ||
V_31 -> V_37 != V_133 ) {
F_1 ( L_81 ) ;
return - V_77 ;
}
V_68 = F_17 ( V_13 , V_133 , V_78 ) ;
if ( V_68 )
return V_68 ;
V_184:
V_61 = F_10 ( V_7 , & V_58 ) ;
if ( V_61 < 0 ) {
break;
} else {
V_183 = true ;
continue;
}
} else {
V_68 = F_29 ( V_7 , V_31 , & V_61 ) ;
if ( V_68 )
return V_68 ;
}
} else if ( V_32 == V_47 ) {
T_2 V_149 = F_8 ( V_31 -> V_33 ) ;
if ( V_149 == V_48 || V_149 == V_49 ) {
V_68 = F_32 ( V_7 , V_31 ) ;
if ( V_68 )
return V_68 ;
} else if ( V_149 == V_50 ) {
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
static int F_39 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_94 -> V_167 ;
int V_168 = V_7 -> V_94 -> V_159 ;
int V_10 , V_186 ;
for ( V_10 = 0 ; V_10 < V_168 ; V_10 ++ , V_31 ++ ) {
if ( V_31 [ 0 ] . V_33 == ( V_47 | V_50 | V_85 ) ) {
struct V_91 * V_92 ;
struct V_187 V_188 ;
if ( V_10 == V_168 - 1 || V_31 [ 1 ] . V_33 != 0 ||
V_31 [ 1 ] . V_37 != 0 || V_31 [ 1 ] . V_39 != 0 ||
V_31 [ 1 ] . V_43 != 0 ) {
F_1 ( L_84 ) ;
return - V_77 ;
}
if ( V_31 -> V_39 == 0 )
goto V_189;
if ( V_31 -> V_39 != V_148 ) {
F_1 ( L_85 ) ;
return - V_77 ;
}
V_188 = F_40 ( V_31 -> V_18 ) ;
V_92 = F_41 ( V_188 ) ;
if ( F_42 ( V_92 ) ) {
F_1 ( L_86 ,
V_31 -> V_18 ) ;
F_43 ( V_188 ) ;
return F_44 ( V_92 ) ;
}
V_31 [ 0 ] . V_18 = ( T_3 ) ( unsigned long ) V_92 ;
V_31 [ 1 ] . V_18 = ( ( T_4 ) ( unsigned long ) V_92 ) >> 32 ;
for ( V_186 = 0 ; V_186 < V_7 -> V_190 ; V_186 ++ )
if ( V_7 -> V_191 [ V_186 ] == V_92 ) {
F_43 ( V_188 ) ;
goto V_189;
}
if ( V_7 -> V_190 >= V_192 ) {
F_43 ( V_188 ) ;
return - V_163 ;
}
V_7 -> V_191 [ V_7 -> V_190 ++ ] = V_92 ;
F_45 ( & V_92 -> V_193 ) ;
F_43 ( V_188 ) ;
V_189:
V_31 ++ ;
V_10 ++ ;
}
}
return 0 ;
}
static void F_46 ( struct V_6 * V_7 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_190 ; V_10 ++ )
F_47 ( V_7 -> V_191 [ V_10 ] ) ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_30 * V_31 = V_7 -> V_94 -> V_167 ;
int V_168 = V_7 -> V_94 -> V_159 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_168 ; V_10 ++ , V_31 ++ )
if ( V_31 -> V_33 == ( V_47 | V_50 | V_85 ) )
V_31 -> V_39 = 0 ;
}
static void F_49 ( struct V_6 * V_7 )
{
struct V_178 * V_180 , * V_194 ;
int V_10 ;
if ( ! V_7 -> V_160 )
return;
for ( V_10 = 0 ; V_10 < V_7 -> V_94 -> V_159 ; V_10 ++ ) {
V_180 = V_7 -> V_160 [ V_10 ] ;
if ( V_180 )
while ( V_180 != V_161 ) {
V_194 = V_180 -> V_64 ;
F_11 ( V_180 ) ;
V_180 = V_194 ;
}
}
F_11 ( V_7 -> V_160 ) ;
}
int F_50 ( struct V_195 * V_94 , union V_196 * V_197 )
{
char T_5 * V_198 = NULL ;
struct V_6 * V_7 ;
int V_169 = - V_77 ;
if ( V_94 -> V_159 <= 0 || V_94 -> V_159 > V_199 )
return - V_163 ;
V_7 = F_51 ( sizeof( struct V_6 ) , V_67 ) ;
if ( ! V_7 )
return - V_170 ;
V_7 -> V_94 = V_94 ;
F_52 ( & V_200 ) ;
if ( V_197 -> V_2 || V_197 -> V_5 || V_197 -> V_4 ) {
V_2 = V_197 -> V_2 ;
V_198 = ( char T_5 * ) ( unsigned long ) V_197 -> V_5 ;
V_4 = V_197 -> V_4 ;
V_3 = 0 ;
V_169 = - V_77 ;
if ( V_4 < 128 || V_4 > V_201 >> 8 ||
V_2 == 0 || V_198 == NULL )
goto V_202;
V_169 = - V_170 ;
V_5 = F_53 ( V_4 ) ;
if ( ! V_5 )
goto V_202;
} else {
V_2 = 0 ;
}
V_169 = F_39 ( V_7 ) ;
if ( V_169 < 0 )
goto V_203;
V_7 -> V_160 = F_35 ( V_94 -> V_159 ,
sizeof( struct V_178 * ) ,
V_181 ) ;
V_169 = - V_170 ;
if ( ! V_7 -> V_160 )
goto V_203;
V_169 = F_34 ( V_7 ) ;
if ( V_169 < 0 )
goto V_203;
V_169 = F_38 ( V_7 ) ;
V_203:
while ( F_10 ( V_7 , NULL ) >= 0 ) ;
F_49 ( V_7 ) ;
if ( V_2 && V_3 >= V_4 - 1 ) {
F_16 ( V_3 >= V_4 ) ;
V_169 = - V_204 ;
}
if ( V_2 && F_54 ( V_198 , V_5 , V_3 + 1 ) != 0 ) {
V_169 = - V_112 ;
goto V_205;
}
if ( V_169 == 0 && V_7 -> V_190 ) {
V_94 -> V_95 -> V_191 = F_55 ( V_7 -> V_190 ,
sizeof( V_7 -> V_191 [ 0 ] ) ,
V_67 ) ;
if ( ! V_94 -> V_95 -> V_191 ) {
V_169 = - V_170 ;
goto V_205;
}
memcpy ( V_94 -> V_95 -> V_191 , V_7 -> V_191 ,
sizeof( V_7 -> V_191 [ 0 ] ) * V_7 -> V_190 ) ;
V_94 -> V_95 -> V_190 = V_7 -> V_190 ;
F_48 ( V_7 ) ;
}
V_205:
if ( V_2 )
F_56 ( V_5 ) ;
V_202:
if ( ! V_94 -> V_95 -> V_191 )
F_46 ( V_7 ) ;
F_11 ( V_7 ) ;
F_57 ( & V_200 ) ;
return V_169 ;
}
