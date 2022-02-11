static struct V_1 * F_1 ( struct V_2 * V_3 , unsigned int V_4 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_7 [ V_5 ] . V_8 == V_3 -> V_9 . V_10 . V_11 &&
V_7 [ V_5 ] . type == V_4 )
return & V_7 [ V_5 ] ;
}
return NULL ;
}
static const char * const * F_2 ( T_1 V_12 )
{
static const char * const V_13 [] = {
L_1 ,
L_2 ,
L_3 ,
NULL ,
} ;
static const char * const V_14 [] = {
L_1 ,
L_4 ,
L_5 ,
NULL ,
} ;
switch ( V_12 ) {
case V_15 :
return V_13 ;
case V_16 :
return V_14 ;
}
return NULL ;
}
static int F_3 ( struct V_17 * V_18 )
{
F_4 ( 2 , L_6 ,
V_18 -> V_19 , V_18 -> V_20 , V_18 -> V_21 ) ;
if ( V_18 -> V_21 == V_22 && V_18 -> V_20 >= 1 )
return 1 ;
if ( V_18 -> V_21 == V_23 &&
V_18 -> V_19 >= 1 && V_18 -> V_20 >= 1 )
return 1 ;
if ( V_18 -> V_21 == V_24 &&
V_18 -> V_19 >= 1 && V_18 -> V_20 >= 1 )
return 1 ;
F_4 ( 2 , L_7 ) ;
return 0 ;
}
static void F_5 ( struct V_17 * V_18 )
{
struct V_25 * V_26 ;
unsigned long V_27 , V_28 ;
while ( ! F_6 ( & V_18 -> V_29 ) ) {
V_26 = F_7 ( ( & V_18 -> V_29 ) -> V_30 ,
struct V_25 , V_31 ) ;
V_27 = F_8 ( V_26 -> V_32 , 0 ) ;
V_28 = F_8 ( V_26 -> V_32 , 1 ) ;
F_9 ( & V_26 -> V_31 ) ;
V_18 -> V_33 -- ;
F_10 ( & V_26 -> V_31 , & V_18 -> V_34 ) ;
V_18 -> V_19 ++ ;
}
F_4 ( 2 , L_8 ,
V_18 -> V_19 , V_18 -> V_33 ) ;
F_11 ( & V_18 -> V_29 ) ;
V_18 -> V_33 = 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_35 * V_36 = V_18 -> V_36 ;
struct V_25 * V_37 ;
unsigned long V_38 ;
unsigned int V_39 ;
unsigned long V_40 ;
F_13 ( & V_36 -> V_41 , V_40 ) ;
V_37 = F_7 ( V_18 -> V_42 . V_30 , struct V_25 , V_31 ) ;
V_38 = F_8 ( V_37 -> V_32 , 0 ) ;
V_39 = F_14 ( V_37 -> V_32 , 0 ) ;
F_15 ( V_18 , V_38 , V_39 ) ;
F_16 ( & V_36 -> V_41 , V_40 ) ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_35 * V_36 = V_18 -> V_36 ;
struct V_43 * V_44 = & V_18 -> V_45 ;
struct V_25 * V_37 ;
unsigned long V_40 ;
if ( V_44 -> V_46 == V_47 ) {
F_13 ( & V_36 -> V_41 , V_40 ) ;
V_37 = F_7 ( V_18 -> V_42 . V_30 ,
struct V_25 , V_31 ) ;
F_9 ( & V_37 -> V_31 ) ;
V_18 -> V_20 -- ;
F_18 ( V_37 -> V_32 , 0 ,
F_19 () ) ;
F_20 ( V_37 -> V_32 , V_48 ) ;
F_16 ( & V_36 -> V_41 , V_40 ) ;
}
V_18 -> V_21 = V_23 ;
if ( F_3 ( V_18 ) ) {
F_13 ( & V_36 -> V_49 , V_40 ) ;
F_21 ( V_18 -> V_50 , & V_36 -> V_51 ) ;
F_16 ( & V_36 -> V_49 , V_40 ) ;
}
F_22 ( V_36 ) ;
return 0 ;
}
static int F_23 ( struct V_17 * V_18 )
{
struct V_35 * V_36 = V_18 -> V_36 ;
struct V_25 * V_37 ;
struct V_25 * V_52 ;
unsigned long V_40 ;
unsigned long V_53 , V_54 , V_38 ;
unsigned int V_39 ;
F_13 ( & V_36 -> V_41 , V_40 ) ;
V_52 = F_7 ( V_18 -> V_34 . V_30 , struct V_25 , V_31 ) ;
V_53 = F_8 ( V_52 -> V_32 , 0 ) ;
V_54 = F_8 ( V_52 -> V_32 , 1 ) ;
F_24 ( V_18 , V_53 , V_54 ) ;
F_16 ( & V_36 -> V_41 , V_40 ) ;
F_13 ( & V_36 -> V_41 , V_40 ) ;
V_37 = F_7 ( V_18 -> V_42 . V_30 , struct V_25 , V_31 ) ;
V_38 = F_8 ( V_37 -> V_32 , 0 ) ;
V_39 = F_14 ( V_37 -> V_32 , 0 ) ;
F_15 ( V_18 , V_38 , V_39 ) ;
F_16 ( & V_36 -> V_41 , V_40 ) ;
return 0 ;
}
static int F_25 ( struct V_17 * V_18 )
{
struct V_35 * V_36 = V_18 -> V_36 ;
struct V_25 * V_26 ;
unsigned long V_55 , V_56 ;
unsigned long V_27 , V_28 ;
int V_57 ;
unsigned int V_58 ;
unsigned long V_40 ;
V_57 = F_26 () ;
V_58 = F_19 () ;
F_4 ( 2 , L_9 , V_57 ) ;
F_4 ( 2 , L_10 , V_58 ) ;
F_4 ( 2 , L_11 ,
F_27 ( V_36 , V_59 ) ) ;
F_13 ( & V_36 -> V_41 , V_40 ) ;
if ( V_57 >= 0 ) {
F_28 ( V_18 , & V_55 , & V_56 ) ;
F_29 (mb_entry, &ctx->src_queue, list) {
V_27 = F_8 ( V_26 -> V_32 , 0 ) ;
V_28 = F_8 ( V_26 -> V_32 , 1 ) ;
if ( ( V_55 == V_27 ) &&
( V_56 == V_28 ) ) {
F_9 ( & V_26 -> V_31 ) ;
V_18 -> V_19 -- ;
F_20 ( V_26 -> V_32 ,
V_48 ) ;
break;
}
}
F_29 (mb_entry, &ctx->ref_queue, list) {
V_27 = F_8 ( V_26 -> V_32 , 0 ) ;
V_28 = F_8 ( V_26 -> V_32 , 1 ) ;
if ( ( V_55 == V_27 ) &&
( V_56 == V_28 ) ) {
F_9 ( & V_26 -> V_31 ) ;
V_18 -> V_33 -- ;
F_20 ( V_26 -> V_32 ,
V_48 ) ;
break;
}
}
}
if ( ( V_18 -> V_19 > 0 ) && ( V_18 -> V_21 == V_23 ) ) {
V_26 = F_7 ( V_18 -> V_34 . V_30 , struct V_25 ,
V_31 ) ;
if ( V_26 -> V_60 ) {
F_9 ( & V_26 -> V_31 ) ;
V_18 -> V_19 -- ;
F_10 ( & V_26 -> V_31 , & V_18 -> V_29 ) ;
V_18 -> V_33 ++ ;
}
F_4 ( 2 , L_8 ,
V_18 -> V_19 , V_18 -> V_33 ) ;
}
if ( V_58 > 0 ) {
V_26 = F_7 ( V_18 -> V_42 . V_30 , struct V_25 ,
V_31 ) ;
F_9 ( & V_26 -> V_31 ) ;
V_18 -> V_20 -- ;
switch ( V_57 ) {
case V_61 :
V_26 -> V_32 -> V_62 . V_40 |= V_63 ;
break;
case V_64 :
V_26 -> V_32 -> V_62 . V_40 |= V_65 ;
break;
case V_66 :
V_26 -> V_32 -> V_62 . V_40 |= V_67 ;
break;
}
F_18 ( V_26 -> V_32 , 0 , V_58 ) ;
F_20 ( V_26 -> V_32 , V_48 ) ;
}
F_16 ( & V_36 -> V_41 , V_40 ) ;
if ( ( V_18 -> V_19 == 0 ) || ( V_18 -> V_20 == 0 ) ) {
F_30 ( & V_36 -> V_49 ) ;
F_31 ( V_18 -> V_50 , & V_36 -> V_51 ) ;
F_32 ( & V_36 -> V_49 ) ;
}
return 0 ;
}
static int F_33 ( struct V_68 * V_68 , void * V_69 ,
struct V_70 * V_71 )
{
struct V_35 * V_36 = F_34 ( V_68 ) ;
strncpy ( V_71 -> V_72 , V_36 -> V_73 -> V_74 , sizeof( V_71 -> V_72 ) - 1 ) ;
strncpy ( V_71 -> V_75 , V_36 -> V_73 -> V_74 , sizeof( V_71 -> V_75 ) - 1 ) ;
V_71 -> V_76 [ 0 ] = 0 ;
V_71 -> V_77 = F_35 ( 1 , 0 , 0 ) ;
V_71 -> V_78 = V_79 | V_80 |
V_81 |
V_82 ;
return 0 ;
}
static int F_36 ( struct V_83 * V_3 , bool V_84 , bool V_85 )
{
struct V_1 * V_9 ;
int V_5 , V_86 = 0 ;
for ( V_5 = 0 ; V_5 < F_37 ( V_7 ) ; ++ V_5 ) {
if ( V_84 && V_7 [ V_5 ] . V_87 == 1 )
continue;
else if ( ! V_84 && V_7 [ V_5 ] . V_87 > 1 )
continue;
if ( V_85 && V_7 [ V_5 ] . type != V_88 )
continue;
else if ( ! V_85 && V_7 [ V_5 ] . type != V_89 )
continue;
if ( V_86 == V_3 -> V_90 ) {
V_9 = & V_7 [ V_5 ] ;
F_38 ( V_3 -> V_91 , V_9 -> V_74 ,
sizeof( V_3 -> V_91 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
++ V_86 ;
}
return - V_92 ;
}
static int F_39 ( struct V_68 * V_68 , void * V_93 ,
struct V_83 * V_3 )
{
return F_36 ( V_3 , false , false ) ;
}
static int F_40 ( struct V_68 * V_68 , void * V_93 ,
struct V_83 * V_3 )
{
return F_36 ( V_3 , true , false ) ;
}
static int F_41 ( struct V_68 * V_68 , void * V_94 ,
struct V_83 * V_3 )
{
return F_36 ( V_3 , false , true ) ;
}
static int F_42 ( struct V_68 * V_68 , void * V_94 ,
struct V_83 * V_3 )
{
return F_36 ( V_3 , true , true ) ;
}
static int F_43 ( struct V_68 * V_68 , void * V_69 , struct V_2 * V_3 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
struct V_95 * V_96 = & V_3 -> V_9 . V_10 ;
F_4 ( 2 , L_12 , V_3 -> type , V_18 -> V_21 ) ;
if ( V_3 -> type == V_97 ) {
V_96 -> V_98 = 0 ;
V_96 -> V_99 = 0 ;
V_96 -> V_100 = V_101 ;
V_96 -> V_11 = V_18 -> V_102 -> V_8 ;
V_96 -> V_87 = V_18 -> V_102 -> V_87 ;
V_96 -> V_103 [ 0 ] . V_104 = V_18 -> V_105 ;
V_96 -> V_103 [ 0 ] . V_106 = V_18 -> V_105 ;
} else if ( V_3 -> type == V_107 ) {
V_96 -> V_98 = V_18 -> V_108 ;
V_96 -> V_99 = V_18 -> V_109 ;
V_96 -> V_100 = V_101 ;
V_96 -> V_11 = V_18 -> V_110 -> V_8 ;
V_96 -> V_87 = V_18 -> V_110 -> V_87 ;
V_96 -> V_103 [ 0 ] . V_104 = V_18 -> V_111 ;
V_96 -> V_103 [ 0 ] . V_106 = V_18 -> V_112 ;
V_96 -> V_103 [ 1 ] . V_104 = V_18 -> V_111 ;
V_96 -> V_103 [ 1 ] . V_106 = V_18 -> V_113 ;
} else {
F_45 ( L_13 ) ;
return - V_92 ;
}
return 0 ;
}
static int F_46 ( struct V_68 * V_68 , void * V_69 , struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_95 * V_96 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_97 ) {
V_9 = F_1 ( V_3 , V_89 ) ;
if ( ! V_9 ) {
F_45 ( L_14 ) ;
return - V_92 ;
}
if ( V_96 -> V_103 [ 0 ] . V_106 == 0 ) {
F_45 ( L_15 ) ;
return - V_92 ;
}
V_96 -> V_103 [ 0 ] . V_104 =
V_96 -> V_103 [ 0 ] . V_106 ;
} else if ( V_3 -> type == V_107 ) {
V_9 = F_1 ( V_3 , V_88 ) ;
if ( ! V_9 ) {
F_45 ( L_14 ) ;
return - V_92 ;
}
if ( V_9 -> V_87 != V_96 -> V_87 ) {
F_45 ( L_14 ) ;
return - V_92 ;
}
F_47 ( & V_96 -> V_98 , 8 , 1920 , 1 ,
& V_96 -> V_99 , 4 , 1080 , 1 , 0 ) ;
} else {
F_45 ( L_13 ) ;
return - V_92 ;
}
return 0 ;
}
static int F_48 ( struct V_68 * V_68 , void * V_69 , struct V_2 * V_3 )
{
struct V_35 * V_36 = F_34 ( V_68 ) ;
struct V_17 * V_18 = F_44 ( V_69 ) ;
struct V_1 * V_9 ;
struct V_95 * V_96 = & V_3 -> V_9 . V_10 ;
unsigned long V_40 ;
int V_114 = 0 ;
V_114 = F_46 ( V_68 , V_69 , V_3 ) ;
if ( V_114 )
return V_114 ;
if ( V_18 -> V_115 . V_116 || V_18 -> V_117 . V_116 ) {
F_49 ( & V_36 -> V_118 , L_16 , V_119 ) ;
V_114 = - V_120 ;
goto V_85;
}
if ( V_3 -> type == V_97 ) {
V_9 = F_1 ( V_3 , V_89 ) ;
if ( ! V_9 ) {
F_45 ( L_17 ) ;
return - V_92 ;
}
V_18 -> V_21 = V_121 ;
V_18 -> V_102 = V_9 ;
V_18 -> V_122 = V_18 -> V_102 -> V_122 ;
V_18 -> V_105 = V_96 -> V_103 [ 0 ] . V_106 ;
V_96 -> V_103 [ 0 ] . V_104 = 0 ;
V_18 -> V_123 = 0 ;
V_18 -> V_124 = V_125 ;
F_50 ( V_18 ) ;
F_13 ( & V_36 -> V_49 , V_40 ) ;
F_21 ( V_18 -> V_50 , & V_36 -> V_51 ) ;
F_16 ( & V_36 -> V_49 , V_40 ) ;
F_51 ( V_18 ) ;
F_22 ( V_36 ) ;
if ( F_52 ( V_18 , \
V_126 , 1 ) ) {
F_45 ( L_18 ) ;
F_53 ( V_18 ) ;
V_114 = - V_127 ;
goto V_85;
}
F_4 ( 2 , L_19 , V_18 -> V_128 ) ;
} else if ( V_3 -> type == V_107 ) {
V_9 = F_1 ( V_3 , V_88 ) ;
if ( ! V_9 ) {
F_45 ( L_20 ) ;
return - V_92 ;
}
if ( V_9 -> V_87 != V_96 -> V_87 ) {
F_45 ( L_20 ) ;
V_114 = - V_92 ;
goto V_85;
}
V_18 -> V_110 = V_9 ;
V_18 -> V_108 = V_96 -> V_98 ;
V_18 -> V_109 = V_96 -> V_99 ;
F_4 ( 2 , L_21 , V_18 -> V_110 -> V_122 ) ;
F_4 ( 2 , L_22 ,
V_96 -> V_98 , V_96 -> V_99 ,
V_18 -> V_108 , V_18 -> V_109 ) ;
if ( V_18 -> V_110 -> V_8 == V_129 ) {
V_18 -> V_111 = F_54 ( V_18 -> V_108 ,
V_130 ) ;
V_18 -> V_112 = F_54 ( V_18 -> V_108 ,
V_130 ) * F_54 ( V_18 -> V_109 ,
V_131 ) ;
V_18 -> V_113 = F_54 ( V_18 -> V_108 ,
V_130 ) * F_54 ( ( V_18 -> V_109
>> 1 ) , V_132 ) ;
V_18 -> V_112 = F_54 ( V_18 -> V_112 ,
V_133 ) ;
V_18 -> V_113 = F_54 ( V_18 -> V_113 ,
V_133 ) ;
V_96 -> V_103 [ 0 ] . V_106 = V_18 -> V_112 ;
V_96 -> V_103 [ 0 ] . V_104 = V_18 -> V_111 ;
V_96 -> V_103 [ 1 ] . V_106 = V_18 -> V_113 ;
V_96 -> V_103 [ 1 ] . V_104 = V_18 -> V_111 ;
} else if ( V_18 -> V_110 -> V_8 == V_134 ) {
V_18 -> V_111 = F_54 ( V_18 -> V_108 ,
V_135 ) ;
V_18 -> V_112 = F_54 ( V_18 -> V_108 ,
V_135 ) * F_54 ( V_18 -> V_109 ,
V_136 ) ;
V_18 -> V_113 = F_54 ( V_18 -> V_108 ,
V_135 ) * F_54 ( ( V_18 -> V_109
>> 1 ) , V_136 ) ;
V_18 -> V_112 = F_54 ( V_18 -> V_112 ,
V_137 ) ;
V_18 -> V_113 = F_54 ( V_18 -> V_113 ,
V_137 ) ;
V_96 -> V_103 [ 0 ] . V_106 = V_18 -> V_112 ;
V_96 -> V_103 [ 0 ] . V_104 = V_18 -> V_111 ;
V_96 -> V_103 [ 1 ] . V_106 = V_18 -> V_113 ;
V_96 -> V_103 [ 1 ] . V_104 = V_18 -> V_111 ;
}
V_18 -> V_138 = 0 ;
V_18 -> V_139 = V_125 ;
} else {
F_45 ( L_13 ) ;
return - V_92 ;
}
V_85:
F_55 () ;
return V_114 ;
}
static int F_56 ( struct V_68 * V_68 , void * V_69 ,
struct V_140 * V_141 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
int V_114 = 0 ;
if ( ( V_141 -> V_142 != V_143 ) &&
( V_141 -> V_142 != V_144 ) )
return - V_92 ;
if ( V_141 -> type == V_97 ) {
if ( V_18 -> V_124 != V_125 ) {
F_45 ( L_23 ,
V_18 -> V_124 ) ;
return - V_92 ;
}
V_114 = F_57 ( & V_18 -> V_117 , V_141 ) ;
if ( V_114 != 0 ) {
F_45 ( L_24 ) ;
return V_114 ;
}
V_18 -> V_124 = V_145 ;
V_114 = F_58 ( V_18 ) ;
if ( V_114 ) {
F_45 ( L_25 ) ;
V_141 -> V_146 = 0 ;
V_114 = F_57 ( & V_18 -> V_117 , V_141 ) ;
return - V_147 ;
}
} else if ( V_141 -> type == V_107 ) {
if ( V_18 -> V_139 != V_125 ) {
F_45 ( L_26 ,
V_18 -> V_139 ) ;
return - V_92 ;
}
V_114 = F_57 ( & V_18 -> V_115 , V_141 ) ;
if ( V_114 != 0 ) {
F_45 ( L_27 ) ;
return V_114 ;
}
V_18 -> V_139 = V_145 ;
} else {
F_45 ( L_13 ) ;
return - V_92 ;
}
return V_114 ;
}
static int F_59 ( struct V_68 * V_68 , void * V_69 ,
struct V_148 * V_149 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
int V_114 = 0 ;
if ( ( V_149 -> V_142 != V_143 ) &&
( V_149 -> V_142 != V_144 ) )
return - V_92 ;
if ( V_149 -> type == V_97 ) {
if ( V_18 -> V_21 != V_22 ) {
F_45 ( L_28 , V_18 -> V_21 ) ;
return - V_92 ;
}
V_114 = F_60 ( & V_18 -> V_117 , V_149 ) ;
if ( V_114 != 0 ) {
F_45 ( L_29 ) ;
return V_114 ;
}
V_149 -> V_150 . V_151 [ 0 ] . V_150 . V_152 += V_153 ;
} else if ( V_149 -> type == V_107 ) {
V_114 = F_60 ( & V_18 -> V_115 , V_149 ) ;
if ( V_114 != 0 ) {
F_45 ( L_30 ) ;
return V_114 ;
}
} else {
F_45 ( L_13 ) ;
return - V_92 ;
}
return V_114 ;
}
static int F_61 ( struct V_68 * V_68 , void * V_69 , struct V_148 * V_149 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( V_18 -> V_21 == V_154 ) {
F_45 ( L_31 ) ;
return - V_127 ;
}
if ( V_149 -> type == V_107 )
return F_62 ( & V_18 -> V_115 , V_149 ) ;
else if ( V_149 -> type == V_97 )
return F_62 ( & V_18 -> V_117 , V_149 ) ;
return - V_92 ;
}
static int F_63 ( struct V_68 * V_68 , void * V_69 , struct V_148 * V_149 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( V_18 -> V_21 == V_154 ) {
F_45 ( L_32 ) ;
return - V_127 ;
}
if ( V_149 -> type == V_107 )
return F_64 ( & V_18 -> V_115 , V_149 , V_68 -> V_155 & V_156 ) ;
else if ( V_149 -> type == V_97 )
return F_64 ( & V_18 -> V_117 , V_149 , V_68 -> V_155 & V_156 ) ;
return - V_92 ;
}
static int F_65 ( struct V_68 * V_68 , void * V_69 ,
enum V_157 type )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( type == V_107 )
return F_66 ( & V_18 -> V_115 , type ) ;
else if ( type == V_97 )
return F_66 ( & V_18 -> V_117 , type ) ;
return - V_92 ;
}
static int F_67 ( struct V_68 * V_68 , void * V_69 ,
enum V_157 type )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( type == V_107 )
return F_68 ( & V_18 -> V_115 , type ) ;
else if ( type == V_97 )
return F_68 ( & V_18 -> V_117 , type ) ;
return - V_92 ;
}
static inline int F_69 ( enum V_158 V_159 )
{
static unsigned int V_4 [ V_160 + 1 ] = {
10 ,
9 ,
11 ,
12 ,
13 ,
20 ,
21 ,
22 ,
30 ,
31 ,
32 ,
40 ,
} ;
return V_4 [ V_159 ] ;
}
static inline int F_70 ( enum V_161 V_159 )
{
static unsigned int V_4 [ V_162 + 1 ] = {
0 ,
9 ,
1 ,
2 ,
3 ,
7 ,
4 ,
5 ,
} ;
return V_4 [ V_159 ] ;
}
static inline int F_71 ( enum V_163 V_164 )
{
static unsigned int V_4 [ V_165 + 1 ] = {
0 ,
1 ,
2 ,
3 ,
4 ,
5 ,
6 ,
7 ,
8 ,
9 ,
10 ,
11 ,
12 ,
13 ,
14 ,
15 ,
16 ,
255 ,
} ;
return V_4 [ V_164 ] ;
}
static int F_72 ( struct V_166 * V_167 )
{
struct V_17 * V_18 = F_73 ( V_167 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
struct V_43 * V_44 = & V_18 -> V_45 ;
int V_114 = 0 ;
switch ( V_167 -> V_12 ) {
case V_168 :
V_44 -> V_169 = V_167 -> V_170 ;
break;
case V_171 :
V_44 -> V_172 = V_167 -> V_170 ;
break;
case V_173 :
V_44 -> V_174 = V_167 -> V_170 ;
break;
case V_175 :
V_44 -> V_176 = V_167 -> V_170 * 8 ;
break;
case V_177 :
V_44 -> V_178 = V_167 -> V_170 ;
break;
case V_179 :
V_44 -> V_180 = V_167 -> V_170 ;
break;
case V_181 :
V_44 -> V_182 = ( V_167 -> V_170 >> 16 ) & 0xff ;
V_44 -> V_183 = ( V_167 -> V_170 >> 8 ) & 0xff ;
V_44 -> V_184 = ( V_167 -> V_170 >> 0 ) & 0xff ;
break;
case V_185 :
V_44 -> V_186 = V_167 -> V_170 ;
break;
case V_187 :
V_44 -> V_188 = V_167 -> V_170 ;
break;
case V_189 :
V_44 -> V_190 = V_167 -> V_170 ;
break;
case V_16 :
V_18 -> V_191 = V_167 -> V_170 ;
break;
case V_192 :
V_44 -> V_193 = V_167 -> V_170 ;
break;
case V_194 :
V_44 -> V_195 . V_196 . V_197 = V_167 -> V_170 ;
break;
case V_198 :
V_44 -> V_46 = V_167 -> V_170 ;
break;
case V_15 :
V_44 -> V_199 = V_167 -> V_170 ;
break;
case V_200 :
V_44 -> V_201 = V_167 -> V_170 ;
break;
case V_202 :
V_44 -> V_203 = V_167 -> V_170 ;
break;
case V_204 :
switch ( V_167 -> V_170 ) {
case V_205 :
V_44 -> V_195 . V_196 . V_206 =
V_207 ;
break;
case V_208 :
V_44 -> V_195 . V_196 . V_206 =
V_209 ;
break;
case V_210 :
V_44 -> V_195 . V_196 . V_206 =
V_211 ;
break;
default:
V_114 = - V_92 ;
}
break;
case V_212 :
V_44 -> V_195 . V_196 . V_213 = V_167 -> V_170 ;
V_44 -> V_195 . V_196 . V_214 = F_69 ( V_167 -> V_170 ) ;
if ( V_44 -> V_195 . V_196 . V_214 < 0 ) {
F_45 ( L_33 ) ;
V_114 = V_44 -> V_195 . V_196 . V_214 ;
}
break;
case V_215 :
V_44 -> V_195 . V_216 . V_213 = V_167 -> V_170 ;
V_44 -> V_195 . V_216 . V_214 = F_70 ( V_167 -> V_170 ) ;
if ( V_44 -> V_195 . V_216 . V_214 < 0 ) {
F_45 ( L_33 ) ;
V_114 = V_44 -> V_195 . V_216 . V_214 ;
}
break;
case V_217 :
V_44 -> V_195 . V_196 . V_218 = V_167 -> V_170 ;
break;
case V_219 :
V_44 -> V_195 . V_196 . V_220 = V_167 -> V_170 ;
break;
case V_221 :
V_44 -> V_195 . V_196 . V_222 = V_167 -> V_170 ;
break;
case V_223 :
V_44 -> V_195 . V_196 . V_224 = V_167 -> V_170 ;
break;
case V_225 :
V_44 -> V_195 . V_196 . V_226 = V_167 -> V_170 ;
break;
case V_227 :
V_44 -> V_195 . V_196 . V_228 = V_167 -> V_170 ;
break;
case V_229 :
V_44 -> V_195 . V_196 . V_230 = V_167 -> V_170 ;
break;
case V_231 :
V_44 -> V_195 . V_196 . V_232 = V_167 -> V_170 ;
break;
case V_233 :
V_44 -> V_195 . V_196 . V_234 = V_167 -> V_170 ;
break;
case V_235 :
V_44 -> V_195 . V_196 . V_236 = V_167 -> V_170 ;
break;
case V_237 :
V_44 -> V_195 . V_196 . V_238 = V_167 -> V_170 ;
break;
case V_239 :
V_44 -> V_195 . V_196 . V_240 = V_167 -> V_170 ;
break;
case V_241 :
case V_242 :
V_44 -> V_195 . V_216 . V_232 = V_167 -> V_170 ;
break;
case V_243 :
case V_244 :
V_44 -> V_195 . V_216 . V_234 = V_167 -> V_170 ;
break;
case V_245 :
case V_246 :
V_44 -> V_195 . V_216 . V_236 = V_167 -> V_170 ;
break;
case V_247 :
case V_248 :
V_44 -> V_195 . V_216 . V_238 = V_167 -> V_170 ;
break;
case V_249 :
case V_250 :
V_44 -> V_195 . V_216 . V_240 = V_167 -> V_170 ;
break;
case V_251 :
V_44 -> V_195 . V_196 . V_252 = V_167 -> V_170 ;
break;
case V_253 :
V_44 -> V_195 . V_196 . V_254 = V_167 -> V_170 ;
break;
case V_255 :
V_44 -> V_195 . V_196 . V_256 = V_167 -> V_170 ;
break;
case V_257 :
V_44 -> V_195 . V_196 . V_258 = V_167 -> V_170 ;
break;
case V_259 :
V_44 -> V_195 . V_196 . V_260 = V_167 -> V_170 ;
break;
case V_261 :
V_44 -> V_195 . V_196 . F_71 = F_71 ( V_167 -> V_170 ) ;
break;
case V_262 :
V_44 -> V_195 . V_196 . V_263 = V_167 -> V_170 ;
break;
case V_264 :
V_44 -> V_195 . V_196 . V_265 = V_167 -> V_170 ;
break;
case V_266 :
V_44 -> V_195 . V_196 . V_267 = ! V_167 -> V_170 ;
break;
case V_268 :
V_44 -> V_195 . V_196 . V_269 = V_167 -> V_170 ;
break;
case V_270 :
switch ( V_167 -> V_170 ) {
case V_271 :
V_44 -> V_195 . V_216 . V_206 =
V_272 ;
break;
case V_273 :
V_44 -> V_195 . V_216 . V_206 =
V_274 ;
break;
default:
V_114 = - V_92 ;
}
break;
case V_275 :
V_44 -> V_195 . V_216 . V_276 = V_167 -> V_170 ;
break;
default:
F_49 ( & V_36 -> V_118 , L_34 ,
V_167 -> V_12 , V_167 -> V_170 ) ;
V_114 = - V_92 ;
}
return V_114 ;
}
static int F_74 ( struct V_68 * V_68 , void * V_69 ,
struct V_277 * V_278 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( V_278 -> type == V_107 ) {
V_18 -> V_45 . V_279 =
V_278 -> V_280 . V_281 . V_282 . V_283 ;
V_18 -> V_45 . V_284 =
V_278 -> V_280 . V_281 . V_282 . V_285 ;
} else {
F_45 ( L_35 ) ;
return - V_92 ;
}
return 0 ;
}
static int F_75 ( struct V_68 * V_68 , void * V_69 ,
struct V_277 * V_278 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( V_278 -> type == V_286 ) {
V_278 -> V_280 . V_281 . V_282 . V_283 =
V_18 -> V_45 . V_279 ;
V_278 -> V_280 . V_281 . V_282 . V_285 =
V_18 -> V_45 . V_284 ;
} else {
F_45 ( L_35 ) ;
return - V_92 ;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_9 , struct V_287 * V_288 )
{
int V_5 ;
if ( ! V_9 )
return - V_92 ;
if ( V_9 -> V_87 != V_288 -> V_87 ) {
F_45 ( L_36 ) ;
return - V_92 ;
}
for ( V_5 = 0 ; V_5 < V_9 -> V_87 ; V_5 ++ ) {
if ( ! F_8 ( V_288 , V_5 ) ) {
F_45 ( L_37 ) ;
return - V_92 ;
}
F_4 ( 2 , L_38 ,
V_288 -> V_62 . V_90 , V_5 ,
F_8 ( V_288 , V_5 ) ) ;
}
return 0 ;
}
static int F_77 ( struct V_289 * V_290 ,
const struct V_2 * V_9 ,
unsigned int * V_291 , unsigned int * V_292 ,
unsigned int V_293 [] , void * V_294 [] )
{
struct V_17 * V_18 = F_44 ( V_290 -> V_295 ) ;
if ( V_18 -> V_21 != V_22 ) {
F_45 ( L_39 , V_18 -> V_21 ) ;
return - V_92 ;
}
if ( V_290 -> type == V_97 ) {
if ( V_18 -> V_102 )
* V_292 = V_18 -> V_102 -> V_87 ;
else
* V_292 = V_296 ;
if ( * V_291 < 1 )
* V_291 = 1 ;
if ( * V_291 > V_297 )
* V_291 = V_297 ;
V_293 [ 0 ] = V_18 -> V_105 ;
V_294 [ 0 ] = V_18 -> V_36 -> V_298 [ V_299 ] ;
} else if ( V_290 -> type == V_107 ) {
if ( V_18 -> V_110 )
* V_292 = V_18 -> V_110 -> V_87 ;
else
* V_292 = V_300 ;
if ( * V_291 < 1 )
* V_291 = 1 ;
if ( * V_291 > V_297 )
* V_291 = V_297 ;
V_293 [ 0 ] = V_18 -> V_112 ;
V_293 [ 1 ] = V_18 -> V_113 ;
V_294 [ 0 ] = V_18 -> V_36 -> V_298 [ V_301 ] ;
V_294 [ 1 ] = V_18 -> V_36 -> V_298 [ V_301 ] ;
} else {
F_45 ( L_40 , V_290 -> type ) ;
return - V_92 ;
}
return 0 ;
}
static void F_78 ( struct V_289 * V_302 )
{
struct V_17 * V_18 = F_44 ( V_302 -> V_295 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
F_79 ( & V_36 -> V_303 ) ;
}
static void F_80 ( struct V_289 * V_302 )
{
struct V_17 * V_18 = F_44 ( V_302 -> V_295 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
F_81 ( & V_36 -> V_303 ) ;
}
static int F_82 ( struct V_287 * V_288 )
{
struct V_289 * V_290 = V_288 -> V_289 ;
struct V_17 * V_18 = F_44 ( V_290 -> V_295 ) ;
unsigned int V_5 ;
int V_114 ;
if ( V_290 -> type == V_97 ) {
V_114 = F_76 ( V_18 -> V_102 , V_288 ) ;
if ( V_114 < 0 )
return V_114 ;
V_5 = V_288 -> V_62 . V_90 ;
V_18 -> V_304 [ V_5 ] . V_32 = V_288 ;
V_18 -> V_304 [ V_5 ] . V_305 . V_306 =
F_8 ( V_288 , 0 ) ;
V_18 -> V_123 ++ ;
} else if ( V_290 -> type == V_107 ) {
V_114 = F_76 ( V_18 -> V_110 , V_288 ) ;
if ( V_114 < 0 )
return V_114 ;
V_5 = V_288 -> V_62 . V_90 ;
V_18 -> V_307 [ V_5 ] . V_32 = V_288 ;
V_18 -> V_307 [ V_5 ] . V_305 . V_308 . V_309 =
F_8 ( V_288 , 0 ) ;
V_18 -> V_307 [ V_5 ] . V_305 . V_308 . V_310 =
F_8 ( V_288 , 1 ) ;
V_18 -> V_138 ++ ;
} else {
F_45 ( L_40 , V_290 -> type ) ;
return - V_92 ;
}
return 0 ;
}
static int F_83 ( struct V_287 * V_288 )
{
struct V_289 * V_290 = V_288 -> V_289 ;
struct V_17 * V_18 = F_44 ( V_290 -> V_295 ) ;
int V_114 ;
if ( V_290 -> type == V_97 ) {
V_114 = F_76 ( V_18 -> V_102 , V_288 ) ;
if ( V_114 < 0 )
return V_114 ;
F_4 ( 2 , L_41 ,
F_14 ( V_288 , 0 ) , V_18 -> V_105 ) ;
if ( F_14 ( V_288 , 0 ) < V_18 -> V_105 ) {
F_45 ( L_42 ) ;
return - V_92 ;
}
} else if ( V_290 -> type == V_107 ) {
V_114 = F_76 ( V_18 -> V_110 , V_288 ) ;
if ( V_114 < 0 )
return V_114 ;
F_4 ( 2 , L_43 ,
F_14 ( V_288 , 0 ) , V_18 -> V_112 ) ;
F_4 ( 2 , L_44 ,
F_14 ( V_288 , 1 ) , V_18 -> V_113 ) ;
if ( F_14 ( V_288 , 0 ) < V_18 -> V_112 ||
F_14 ( V_288 , 1 ) < V_18 -> V_113 ) {
F_45 ( L_45 ) ;
return - V_92 ;
}
} else {
F_45 ( L_40 , V_290 -> type ) ;
return - V_92 ;
}
return 0 ;
}
static int F_84 ( struct V_289 * V_302 , unsigned int V_146 )
{
struct V_17 * V_18 = F_44 ( V_302 -> V_295 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
unsigned long V_40 ;
F_85 ( & V_18 -> V_311 ) ;
if ( F_3 ( V_18 ) ) {
F_13 ( & V_36 -> V_49 , V_40 ) ;
F_21 ( V_18 -> V_50 , & V_36 -> V_51 ) ;
F_16 ( & V_36 -> V_49 , V_40 ) ;
}
F_22 ( V_36 ) ;
return 0 ;
}
static int F_86 ( struct V_289 * V_302 )
{
unsigned long V_40 ;
struct V_17 * V_18 = F_44 ( V_302 -> V_295 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
if ( ( V_18 -> V_21 == V_24 ||
V_18 -> V_21 == V_23 ) &&
V_36 -> V_312 == V_18 -> V_50 && V_36 -> V_313 ) {
V_18 -> V_21 = V_314 ;
F_52 ( V_18 , V_315 ,
0 ) ;
}
V_18 -> V_21 = V_316 ;
F_13 ( & V_36 -> V_41 , V_40 ) ;
if ( V_302 -> type == V_97 ) {
F_87 ( & V_18 -> V_42 , & V_18 -> V_117 ) ;
F_11 ( & V_18 -> V_42 ) ;
V_18 -> V_20 = 0 ;
}
if ( V_302 -> type == V_107 ) {
F_5 ( V_18 ) ;
F_87 ( & V_18 -> V_34 , & V_18 -> V_115 ) ;
F_11 ( & V_18 -> V_34 ) ;
V_18 -> V_19 = 0 ;
}
F_16 ( & V_36 -> V_41 , V_40 ) ;
return 0 ;
}
static void F_88 ( struct V_287 * V_288 )
{
struct V_289 * V_290 = V_288 -> V_289 ;
struct V_17 * V_18 = F_44 ( V_290 -> V_295 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
unsigned long V_40 ;
struct V_25 * V_317 ;
if ( V_18 -> V_21 == V_154 ) {
F_20 ( V_288 , V_318 ) ;
F_5 ( V_18 ) ;
return;
}
if ( V_290 -> type == V_97 ) {
V_317 = & V_18 -> V_304 [ V_288 -> V_62 . V_90 ] ;
V_317 -> V_60 = 0 ;
F_13 ( & V_36 -> V_41 , V_40 ) ;
F_10 ( & V_317 -> V_31 , & V_18 -> V_42 ) ;
V_18 -> V_20 ++ ;
F_16 ( & V_36 -> V_41 , V_40 ) ;
} else if ( V_290 -> type == V_107 ) {
V_317 = & V_18 -> V_307 [ V_288 -> V_62 . V_90 ] ;
V_317 -> V_60 = 0 ;
F_13 ( & V_36 -> V_41 , V_40 ) ;
if ( V_288 -> V_319 [ 0 ] . V_320 == 0 ) {
F_4 ( 1 , L_46 ) ;
V_18 -> V_21 = V_24 ;
F_20 ( V_288 , V_48 ) ;
F_5 ( V_18 ) ;
} else {
F_10 ( & V_317 -> V_31 , & V_18 -> V_34 ) ;
V_18 -> V_19 ++ ;
}
F_16 ( & V_36 -> V_41 , V_40 ) ;
} else {
F_45 ( L_47 , V_290 -> type ) ;
}
if ( F_3 ( V_18 ) ) {
F_13 ( & V_36 -> V_49 , V_40 ) ;
F_21 ( V_18 -> V_50 , & V_36 -> V_51 ) ;
F_16 ( & V_36 -> V_49 , V_40 ) ;
}
F_22 ( V_36 ) ;
}
struct V_321 * F_89 ( void )
{
return & V_322 ;
}
struct V_323 * F_90 ( void )
{
return & V_324 ;
}
const struct V_325 * F_91 ( void )
{
return & V_326 ;
}
int F_92 ( struct V_17 * V_18 )
{
struct V_327 V_328 ;
int V_5 ;
F_93 ( & V_18 -> V_311 , V_329 ) ;
if ( V_18 -> V_311 . error ) {
F_45 ( L_48 ) ;
return V_18 -> V_311 . error ;
}
for ( V_5 = 0 ; V_5 < V_329 ; V_5 ++ ) {
if ( F_94 ( V_330 [ V_5 ] . V_12 ) ) {
memset ( & V_328 , 0 , sizeof( struct V_327 ) ) ;
V_328 . V_331 = & V_332 ;
V_328 . V_12 = V_330 [ V_5 ] . V_12 ;
V_328 . V_333 = V_330 [ V_5 ] . V_334 ;
V_328 . V_335 = V_330 [ V_5 ] . V_336 ;
V_328 . V_337 = V_330 [ V_5 ] . V_338 ;
V_328 . V_74 = V_330 [ V_5 ] . V_74 ;
V_328 . type = V_330 [ V_5 ] . type ;
V_328 . V_40 = 0 ;
if ( V_328 . type == V_339 ) {
V_328 . V_340 = 0 ;
V_328 . V_341 = V_328 . V_341 ;
V_328 . V_342 = F_2 ( V_328 . V_12 ) ;
} else {
V_328 . V_340 = V_330 [ V_5 ] . V_340 ;
V_328 . V_341 = 0 ;
}
V_18 -> V_343 [ V_5 ] = F_95 ( & V_18 -> V_311 ,
& V_328 , NULL ) ;
} else {
if ( V_330 [ V_5 ] . type == V_339 ) {
V_18 -> V_343 [ V_5 ] = F_96 (
& V_18 -> V_311 ,
& V_332 , V_330 [ V_5 ] . V_12 ,
V_330 [ V_5 ] . V_336 , 0 ,
V_330 [ V_5 ] . V_338 ) ;
} else {
V_18 -> V_343 [ V_5 ] = F_97 (
& V_18 -> V_311 ,
& V_332 , V_330 [ V_5 ] . V_12 ,
V_330 [ V_5 ] . V_334 ,
V_330 [ V_5 ] . V_336 , V_330 [ V_5 ] . V_340 ,
V_330 [ V_5 ] . V_338 ) ;
}
}
if ( V_18 -> V_311 . error ) {
F_45 ( L_49 , V_5 ) ;
return V_18 -> V_311 . error ;
}
if ( V_330 [ V_5 ] . V_344 && V_18 -> V_343 [ V_5 ] )
V_18 -> V_343 [ V_5 ] -> V_40 |= V_345 ;
}
return 0 ;
}
void F_98 ( struct V_17 * V_18 )
{
int V_5 ;
F_99 ( & V_18 -> V_311 ) ;
for ( V_5 = 0 ; V_5 < V_329 ; V_5 ++ )
V_18 -> V_343 [ V_5 ] = NULL ;
}
