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
V_71 -> V_78 = V_79
| V_80
| V_81 ;
return 0 ;
}
static int F_36 ( struct V_82 * V_3 , bool V_83 , bool V_84 )
{
struct V_1 * V_9 ;
int V_5 , V_85 = 0 ;
for ( V_5 = 0 ; V_5 < F_37 ( V_7 ) ; ++ V_5 ) {
if ( V_83 && V_7 [ V_5 ] . V_86 == 1 )
continue;
else if ( ! V_83 && V_7 [ V_5 ] . V_86 > 1 )
continue;
if ( V_84 && V_7 [ V_5 ] . type != V_87 )
continue;
else if ( ! V_84 && V_7 [ V_5 ] . type != V_88 )
continue;
if ( V_85 == V_3 -> V_89 ) {
V_9 = & V_7 [ V_5 ] ;
F_38 ( V_3 -> V_90 , V_9 -> V_74 ,
sizeof( V_3 -> V_90 ) ) ;
V_3 -> V_11 = V_9 -> V_8 ;
return 0 ;
}
++ V_85 ;
}
return - V_91 ;
}
static int F_39 ( struct V_68 * V_68 , void * V_92 ,
struct V_82 * V_3 )
{
return F_36 ( V_3 , false , false ) ;
}
static int F_40 ( struct V_68 * V_68 , void * V_92 ,
struct V_82 * V_3 )
{
return F_36 ( V_3 , true , false ) ;
}
static int F_41 ( struct V_68 * V_68 , void * V_93 ,
struct V_82 * V_3 )
{
return F_36 ( V_3 , false , true ) ;
}
static int F_42 ( struct V_68 * V_68 , void * V_93 ,
struct V_82 * V_3 )
{
return F_36 ( V_3 , true , true ) ;
}
static int F_43 ( struct V_68 * V_68 , void * V_69 , struct V_2 * V_3 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
struct V_94 * V_95 = & V_3 -> V_9 . V_10 ;
F_4 ( 2 , L_12 , V_3 -> type , V_18 -> V_21 ) ;
if ( V_3 -> type == V_96 ) {
V_95 -> V_97 = 0 ;
V_95 -> V_98 = 0 ;
V_95 -> V_99 = V_100 ;
V_95 -> V_11 = V_18 -> V_101 -> V_8 ;
V_95 -> V_86 = V_18 -> V_101 -> V_86 ;
V_95 -> V_102 [ 0 ] . V_103 = V_18 -> V_104 ;
V_95 -> V_102 [ 0 ] . V_105 = V_18 -> V_104 ;
} else if ( V_3 -> type == V_106 ) {
V_95 -> V_97 = V_18 -> V_107 ;
V_95 -> V_98 = V_18 -> V_108 ;
V_95 -> V_99 = V_100 ;
V_95 -> V_11 = V_18 -> V_109 -> V_8 ;
V_95 -> V_86 = V_18 -> V_109 -> V_86 ;
V_95 -> V_102 [ 0 ] . V_103 = V_18 -> V_110 ;
V_95 -> V_102 [ 0 ] . V_105 = V_18 -> V_111 ;
V_95 -> V_102 [ 1 ] . V_103 = V_18 -> V_110 ;
V_95 -> V_102 [ 1 ] . V_105 = V_18 -> V_112 ;
} else {
F_45 ( L_13 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_46 ( struct V_68 * V_68 , void * V_69 , struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_94 * V_95 = & V_3 -> V_9 . V_10 ;
if ( V_3 -> type == V_96 ) {
V_9 = F_1 ( V_3 , V_88 ) ;
if ( ! V_9 ) {
F_45 ( L_14 ) ;
return - V_91 ;
}
if ( V_95 -> V_102 [ 0 ] . V_105 == 0 ) {
F_45 ( L_15 ) ;
return - V_91 ;
}
V_95 -> V_102 [ 0 ] . V_103 =
V_95 -> V_102 [ 0 ] . V_105 ;
} else if ( V_3 -> type == V_106 ) {
V_9 = F_1 ( V_3 , V_87 ) ;
if ( ! V_9 ) {
F_45 ( L_14 ) ;
return - V_91 ;
}
if ( V_9 -> V_86 != V_95 -> V_86 ) {
F_45 ( L_14 ) ;
return - V_91 ;
}
} else {
F_45 ( L_13 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_47 ( struct V_68 * V_68 , void * V_69 , struct V_2 * V_3 )
{
struct V_35 * V_36 = F_34 ( V_68 ) ;
struct V_17 * V_18 = F_44 ( V_69 ) ;
struct V_1 * V_9 ;
struct V_94 * V_95 = & V_3 -> V_9 . V_10 ;
unsigned long V_40 ;
int V_113 = 0 ;
V_113 = F_46 ( V_68 , V_69 , V_3 ) ;
if ( V_113 )
return V_113 ;
if ( V_18 -> V_114 . V_115 || V_18 -> V_116 . V_115 ) {
F_48 ( & V_36 -> V_117 , L_16 , V_118 ) ;
V_113 = - V_119 ;
goto V_84;
}
if ( V_3 -> type == V_96 ) {
V_9 = F_1 ( V_3 , V_88 ) ;
if ( ! V_9 ) {
F_45 ( L_17 ) ;
return - V_91 ;
}
V_18 -> V_21 = V_120 ;
V_18 -> V_101 = V_9 ;
V_18 -> V_121 = V_18 -> V_101 -> V_121 ;
V_18 -> V_104 = V_95 -> V_102 [ 0 ] . V_105 ;
V_95 -> V_102 [ 0 ] . V_103 = 0 ;
V_18 -> V_122 = 0 ;
V_18 -> V_123 = V_124 ;
F_49 ( V_18 ) ;
F_13 ( & V_36 -> V_49 , V_40 ) ;
F_21 ( V_18 -> V_50 , & V_36 -> V_51 ) ;
F_16 ( & V_36 -> V_49 , V_40 ) ;
F_50 ( V_18 ) ;
F_22 ( V_36 ) ;
if ( F_51 ( V_18 , \
V_125 , 1 ) ) {
F_45 ( L_18 ) ;
F_52 ( V_18 ) ;
V_113 = - V_126 ;
goto V_84;
}
F_4 ( 2 , L_19 , V_18 -> V_127 ) ;
} else if ( V_3 -> type == V_106 ) {
V_9 = F_1 ( V_3 , V_87 ) ;
if ( ! V_9 ) {
F_45 ( L_20 ) ;
return - V_91 ;
}
if ( V_9 -> V_86 != V_95 -> V_86 ) {
F_45 ( L_20 ) ;
V_113 = - V_91 ;
goto V_84;
}
V_18 -> V_109 = V_9 ;
V_18 -> V_107 = V_95 -> V_97 ;
V_18 -> V_108 = V_95 -> V_98 ;
F_4 ( 2 , L_21 , V_18 -> V_109 -> V_121 ) ;
F_4 ( 2 , L_22 ,
V_95 -> V_97 , V_95 -> V_98 ,
V_18 -> V_107 , V_18 -> V_108 ) ;
if ( V_18 -> V_109 -> V_8 == V_128 ) {
V_18 -> V_110 = F_53 ( V_18 -> V_107 ,
V_129 ) ;
V_18 -> V_111 = F_53 ( V_18 -> V_107 ,
V_129 ) * F_53 ( V_18 -> V_108 ,
V_130 ) ;
V_18 -> V_112 = F_53 ( V_18 -> V_107 ,
V_129 ) * F_53 ( ( V_18 -> V_108
>> 1 ) , V_131 ) ;
V_18 -> V_111 = F_53 ( V_18 -> V_111 ,
V_132 ) ;
V_18 -> V_112 = F_53 ( V_18 -> V_112 ,
V_132 ) ;
V_95 -> V_102 [ 0 ] . V_105 = V_18 -> V_111 ;
V_95 -> V_102 [ 0 ] . V_103 = V_18 -> V_110 ;
V_95 -> V_102 [ 1 ] . V_105 = V_18 -> V_112 ;
V_95 -> V_102 [ 1 ] . V_103 = V_18 -> V_110 ;
} else if ( V_18 -> V_109 -> V_8 == V_133 ) {
V_18 -> V_110 = F_53 ( V_18 -> V_107 ,
V_134 ) ;
V_18 -> V_111 = F_53 ( V_18 -> V_107 ,
V_134 ) * F_53 ( V_18 -> V_108 ,
V_135 ) ;
V_18 -> V_112 = F_53 ( V_18 -> V_107 ,
V_134 ) * F_53 ( ( V_18 -> V_108
>> 1 ) , V_135 ) ;
V_18 -> V_111 = F_53 ( V_18 -> V_111 ,
V_136 ) ;
V_18 -> V_112 = F_53 ( V_18 -> V_112 ,
V_136 ) ;
V_95 -> V_102 [ 0 ] . V_105 = V_18 -> V_111 ;
V_95 -> V_102 [ 0 ] . V_103 = V_18 -> V_110 ;
V_95 -> V_102 [ 1 ] . V_105 = V_18 -> V_112 ;
V_95 -> V_102 [ 1 ] . V_103 = V_18 -> V_110 ;
}
V_18 -> V_137 = 0 ;
V_18 -> V_138 = V_124 ;
} else {
F_45 ( L_13 ) ;
return - V_91 ;
}
V_84:
F_54 () ;
return V_113 ;
}
static int F_55 ( struct V_68 * V_68 , void * V_69 ,
struct V_139 * V_140 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
int V_113 = 0 ;
if ( ( V_140 -> V_141 != V_142 ) &&
( V_140 -> V_141 != V_143 ) )
return - V_91 ;
if ( V_140 -> type == V_96 ) {
if ( V_18 -> V_123 != V_124 ) {
F_45 ( L_23 ,
V_18 -> V_123 ) ;
return - V_91 ;
}
V_113 = F_56 ( & V_18 -> V_116 , V_140 ) ;
if ( V_113 != 0 ) {
F_45 ( L_24 ) ;
return V_113 ;
}
V_18 -> V_123 = V_144 ;
V_113 = F_57 ( V_18 ) ;
if ( V_113 ) {
F_45 ( L_25 ) ;
V_140 -> V_145 = 0 ;
V_113 = F_56 ( & V_18 -> V_116 , V_140 ) ;
return - V_146 ;
}
} else if ( V_140 -> type == V_106 ) {
if ( V_18 -> V_138 != V_124 ) {
F_45 ( L_26 ,
V_18 -> V_138 ) ;
return - V_91 ;
}
V_113 = F_56 ( & V_18 -> V_114 , V_140 ) ;
if ( V_113 != 0 ) {
F_45 ( L_27 ) ;
return V_113 ;
}
V_18 -> V_138 = V_144 ;
} else {
F_45 ( L_13 ) ;
return - V_91 ;
}
return V_113 ;
}
static int F_58 ( struct V_68 * V_68 , void * V_69 ,
struct V_147 * V_148 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
int V_113 = 0 ;
if ( ( V_148 -> V_141 != V_142 ) &&
( V_148 -> V_141 != V_143 ) )
return - V_91 ;
if ( V_148 -> type == V_96 ) {
if ( V_18 -> V_21 != V_22 ) {
F_45 ( L_28 , V_18 -> V_21 ) ;
return - V_91 ;
}
V_113 = F_59 ( & V_18 -> V_116 , V_148 ) ;
if ( V_113 != 0 ) {
F_45 ( L_29 ) ;
return V_113 ;
}
V_148 -> V_149 . V_150 [ 0 ] . V_149 . V_151 += V_152 ;
} else if ( V_148 -> type == V_106 ) {
V_113 = F_59 ( & V_18 -> V_114 , V_148 ) ;
if ( V_113 != 0 ) {
F_45 ( L_30 ) ;
return V_113 ;
}
} else {
F_45 ( L_13 ) ;
return - V_91 ;
}
return V_113 ;
}
static int F_60 ( struct V_68 * V_68 , void * V_69 , struct V_147 * V_148 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( V_18 -> V_21 == V_153 ) {
F_45 ( L_31 ) ;
return - V_126 ;
}
if ( V_148 -> type == V_106 )
return F_61 ( & V_18 -> V_114 , V_148 ) ;
else if ( V_148 -> type == V_96 )
return F_61 ( & V_18 -> V_116 , V_148 ) ;
return - V_91 ;
}
static int F_62 ( struct V_68 * V_68 , void * V_69 , struct V_147 * V_148 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( V_18 -> V_21 == V_153 ) {
F_45 ( L_32 ) ;
return - V_126 ;
}
if ( V_148 -> type == V_106 )
return F_63 ( & V_18 -> V_114 , V_148 , V_68 -> V_154 & V_155 ) ;
else if ( V_148 -> type == V_96 )
return F_63 ( & V_18 -> V_116 , V_148 , V_68 -> V_154 & V_155 ) ;
return - V_91 ;
}
static int F_64 ( struct V_68 * V_68 , void * V_69 ,
enum V_156 type )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( type == V_106 )
return F_65 ( & V_18 -> V_114 , type ) ;
else if ( type == V_96 )
return F_65 ( & V_18 -> V_116 , type ) ;
return - V_91 ;
}
static int F_66 ( struct V_68 * V_68 , void * V_69 ,
enum V_156 type )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( type == V_106 )
return F_67 ( & V_18 -> V_114 , type ) ;
else if ( type == V_96 )
return F_67 ( & V_18 -> V_116 , type ) ;
return - V_91 ;
}
static inline int F_68 ( enum V_157 V_158 )
{
static unsigned int V_4 [ V_159 + 1 ] = {
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
return V_4 [ V_158 ] ;
}
static inline int F_69 ( enum V_160 V_158 )
{
static unsigned int V_4 [ V_161 + 1 ] = {
0 ,
9 ,
1 ,
2 ,
3 ,
7 ,
4 ,
5 ,
} ;
return V_4 [ V_158 ] ;
}
static inline int F_70 ( enum V_162 V_163 )
{
static unsigned int V_4 [ V_164 + 1 ] = {
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
return V_4 [ V_163 ] ;
}
static int F_71 ( struct V_165 * V_166 )
{
struct V_17 * V_18 = F_72 ( V_166 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
struct V_43 * V_44 = & V_18 -> V_45 ;
int V_113 = 0 ;
switch ( V_166 -> V_12 ) {
case V_167 :
V_44 -> V_168 = V_166 -> V_169 ;
break;
case V_170 :
V_44 -> V_171 = V_166 -> V_169 ;
break;
case V_172 :
V_44 -> V_173 = V_166 -> V_169 ;
break;
case V_174 :
V_44 -> V_175 = V_166 -> V_169 * 8 ;
break;
case V_176 :
V_44 -> V_177 = V_166 -> V_169 ;
break;
case V_178 :
V_44 -> V_179 = V_166 -> V_169 ;
break;
case V_180 :
V_44 -> V_181 = ( V_166 -> V_169 >> 16 ) & 0xff ;
V_44 -> V_182 = ( V_166 -> V_169 >> 8 ) & 0xff ;
V_44 -> V_183 = ( V_166 -> V_169 >> 0 ) & 0xff ;
break;
case V_184 :
V_44 -> V_185 = V_166 -> V_169 ;
break;
case V_186 :
V_44 -> V_187 = V_166 -> V_169 ;
break;
case V_188 :
V_44 -> V_189 = V_166 -> V_169 ;
break;
case V_16 :
V_18 -> V_190 = V_166 -> V_169 ;
break;
case V_191 :
V_44 -> V_192 = V_166 -> V_169 ;
break;
case V_193 :
V_44 -> V_194 . V_195 . V_196 = V_166 -> V_169 ;
break;
case V_197 :
V_44 -> V_46 = V_166 -> V_169 ;
break;
case V_15 :
V_44 -> V_198 = V_166 -> V_169 ;
break;
case V_199 :
V_44 -> V_200 = V_166 -> V_169 ;
break;
case V_201 :
V_44 -> V_202 = V_166 -> V_169 ;
break;
case V_203 :
switch ( V_166 -> V_169 ) {
case V_204 :
V_44 -> V_194 . V_195 . V_205 =
V_206 ;
break;
case V_207 :
V_44 -> V_194 . V_195 . V_205 =
V_208 ;
break;
case V_209 :
V_44 -> V_194 . V_195 . V_205 =
V_210 ;
break;
default:
V_113 = - V_91 ;
}
break;
case V_211 :
V_44 -> V_194 . V_195 . V_212 = V_166 -> V_169 ;
V_44 -> V_194 . V_195 . V_213 = F_68 ( V_166 -> V_169 ) ;
if ( V_44 -> V_194 . V_195 . V_213 < 0 ) {
F_45 ( L_33 ) ;
V_113 = V_44 -> V_194 . V_195 . V_213 ;
}
break;
case V_214 :
V_44 -> V_194 . V_215 . V_212 = V_166 -> V_169 ;
V_44 -> V_194 . V_215 . V_213 = F_69 ( V_166 -> V_169 ) ;
if ( V_44 -> V_194 . V_215 . V_213 < 0 ) {
F_45 ( L_33 ) ;
V_113 = V_44 -> V_194 . V_215 . V_213 ;
}
break;
case V_216 :
V_44 -> V_194 . V_195 . V_217 = V_166 -> V_169 ;
break;
case V_218 :
V_44 -> V_194 . V_195 . V_219 = V_166 -> V_169 ;
break;
case V_220 :
V_44 -> V_194 . V_195 . V_221 = V_166 -> V_169 ;
break;
case V_222 :
V_44 -> V_194 . V_195 . V_223 = V_166 -> V_169 ;
break;
case V_224 :
V_44 -> V_194 . V_195 . V_225 = V_166 -> V_169 ;
break;
case V_226 :
V_44 -> V_194 . V_195 . V_227 = V_166 -> V_169 ;
break;
case V_228 :
V_44 -> V_194 . V_195 . V_229 = V_166 -> V_169 ;
break;
case V_230 :
V_44 -> V_194 . V_195 . V_231 = V_166 -> V_169 ;
break;
case V_232 :
V_44 -> V_194 . V_195 . V_233 = V_166 -> V_169 ;
break;
case V_234 :
V_44 -> V_194 . V_195 . V_235 = V_166 -> V_169 ;
break;
case V_236 :
V_44 -> V_194 . V_195 . V_237 = V_166 -> V_169 ;
break;
case V_238 :
V_44 -> V_194 . V_195 . V_239 = V_166 -> V_169 ;
break;
case V_240 :
case V_241 :
V_44 -> V_194 . V_215 . V_231 = V_166 -> V_169 ;
break;
case V_242 :
case V_243 :
V_44 -> V_194 . V_215 . V_233 = V_166 -> V_169 ;
break;
case V_244 :
case V_245 :
V_44 -> V_194 . V_215 . V_235 = V_166 -> V_169 ;
break;
case V_246 :
case V_247 :
V_44 -> V_194 . V_215 . V_237 = V_166 -> V_169 ;
break;
case V_248 :
case V_249 :
V_44 -> V_194 . V_215 . V_239 = V_166 -> V_169 ;
break;
case V_250 :
V_44 -> V_194 . V_195 . V_251 = V_166 -> V_169 ;
break;
case V_252 :
V_44 -> V_194 . V_195 . V_253 = V_166 -> V_169 ;
break;
case V_254 :
V_44 -> V_194 . V_195 . V_255 = V_166 -> V_169 ;
break;
case V_256 :
V_44 -> V_194 . V_195 . V_257 = V_166 -> V_169 ;
break;
case V_258 :
V_44 -> V_194 . V_195 . V_259 = V_166 -> V_169 ;
break;
case V_260 :
V_44 -> V_194 . V_195 . F_70 = F_70 ( V_166 -> V_169 ) ;
break;
case V_261 :
V_44 -> V_194 . V_195 . V_262 = V_166 -> V_169 ;
break;
case V_263 :
V_44 -> V_194 . V_195 . V_264 = V_166 -> V_169 ;
break;
case V_265 :
V_44 -> V_194 . V_195 . V_266 = ! V_166 -> V_169 ;
break;
case V_267 :
V_44 -> V_194 . V_195 . V_268 = V_166 -> V_169 ;
break;
case V_269 :
switch ( V_166 -> V_169 ) {
case V_270 :
V_44 -> V_194 . V_215 . V_205 =
V_271 ;
break;
case V_272 :
V_44 -> V_194 . V_215 . V_205 =
V_273 ;
break;
default:
V_113 = - V_91 ;
}
break;
case V_274 :
V_44 -> V_194 . V_215 . V_275 = V_166 -> V_169 ;
break;
default:
F_48 ( & V_36 -> V_117 , L_34 ,
V_166 -> V_12 , V_166 -> V_169 ) ;
V_113 = - V_91 ;
}
return V_113 ;
}
int F_73 ( struct V_68 * V_68 , void * V_69 , struct V_276 * V_277 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( V_277 -> type == V_106 ) {
V_18 -> V_45 . V_278 =
V_277 -> V_279 . V_280 . V_281 . V_282 ;
V_18 -> V_45 . V_283 =
V_277 -> V_279 . V_280 . V_281 . V_284 ;
} else {
F_45 ( L_35 ) ;
return - V_91 ;
}
return 0 ;
}
int F_74 ( struct V_68 * V_68 , void * V_69 , struct V_276 * V_277 )
{
struct V_17 * V_18 = F_44 ( V_69 ) ;
if ( V_277 -> type == V_285 ) {
V_277 -> V_279 . V_280 . V_281 . V_282 =
V_18 -> V_45 . V_278 ;
V_277 -> V_279 . V_280 . V_281 . V_284 =
V_18 -> V_45 . V_283 ;
} else {
F_45 ( L_35 ) ;
return - V_91 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_9 , struct V_286 * V_287 )
{
int V_5 ;
if ( ! V_9 )
return - V_91 ;
if ( V_9 -> V_86 != V_287 -> V_86 ) {
F_45 ( L_36 ) ;
return - V_91 ;
}
for ( V_5 = 0 ; V_5 < V_9 -> V_86 ; V_5 ++ ) {
if ( ! F_8 ( V_287 , V_5 ) ) {
F_45 ( L_37 ) ;
return - V_91 ;
}
F_4 ( 2 , L_38 ,
V_287 -> V_62 . V_89 , V_5 ,
F_8 ( V_287 , V_5 ) ) ;
}
return 0 ;
}
static int F_76 ( struct V_288 * V_289 ,
unsigned int * V_290 , unsigned int * V_291 ,
unsigned long V_292 [] , void * V_293 [] )
{
struct V_17 * V_18 = F_44 ( V_289 -> V_294 ) ;
if ( V_18 -> V_21 != V_22 ) {
F_45 ( L_39 , V_18 -> V_21 ) ;
return - V_91 ;
}
if ( V_289 -> type == V_96 ) {
if ( V_18 -> V_101 )
* V_291 = V_18 -> V_101 -> V_86 ;
else
* V_291 = V_295 ;
if ( * V_290 < 1 )
* V_290 = 1 ;
if ( * V_290 > V_296 )
* V_290 = V_296 ;
V_292 [ 0 ] = V_18 -> V_104 ;
V_293 [ 0 ] = V_18 -> V_36 -> V_297 [ V_298 ] ;
} else if ( V_289 -> type == V_106 ) {
if ( V_18 -> V_109 )
* V_291 = V_18 -> V_109 -> V_86 ;
else
* V_291 = V_299 ;
if ( * V_290 < 1 )
* V_290 = 1 ;
if ( * V_290 > V_296 )
* V_290 = V_296 ;
V_292 [ 0 ] = V_18 -> V_111 ;
V_292 [ 1 ] = V_18 -> V_112 ;
V_293 [ 0 ] = V_18 -> V_36 -> V_297 [ V_300 ] ;
V_293 [ 1 ] = V_18 -> V_36 -> V_297 [ V_300 ] ;
} else {
F_45 ( L_40 , V_289 -> type ) ;
return - V_91 ;
}
return 0 ;
}
static void F_77 ( struct V_288 * V_301 )
{
struct V_17 * V_18 = F_44 ( V_301 -> V_294 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
F_78 ( & V_36 -> V_302 ) ;
}
static void F_79 ( struct V_288 * V_301 )
{
struct V_17 * V_18 = F_44 ( V_301 -> V_294 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
F_80 ( & V_36 -> V_302 ) ;
}
static int F_81 ( struct V_286 * V_287 )
{
struct V_288 * V_289 = V_287 -> V_288 ;
struct V_17 * V_18 = F_44 ( V_289 -> V_294 ) ;
unsigned int V_5 ;
int V_113 ;
if ( V_289 -> type == V_96 ) {
V_113 = F_75 ( V_18 -> V_101 , V_287 ) ;
if ( V_113 < 0 )
return V_113 ;
V_5 = V_287 -> V_62 . V_89 ;
V_18 -> V_303 [ V_5 ] . V_32 = V_287 ;
V_18 -> V_303 [ V_5 ] . V_304 . V_305 =
F_8 ( V_287 , 0 ) ;
V_18 -> V_122 ++ ;
} else if ( V_289 -> type == V_106 ) {
V_113 = F_75 ( V_18 -> V_109 , V_287 ) ;
if ( V_113 < 0 )
return V_113 ;
V_5 = V_287 -> V_62 . V_89 ;
V_18 -> V_306 [ V_5 ] . V_32 = V_287 ;
V_18 -> V_306 [ V_5 ] . V_304 . V_307 . V_308 =
F_8 ( V_287 , 0 ) ;
V_18 -> V_306 [ V_5 ] . V_304 . V_307 . V_309 =
F_8 ( V_287 , 1 ) ;
V_18 -> V_137 ++ ;
} else {
F_45 ( L_40 , V_289 -> type ) ;
return - V_91 ;
}
return 0 ;
}
static int F_82 ( struct V_286 * V_287 )
{
struct V_288 * V_289 = V_287 -> V_288 ;
struct V_17 * V_18 = F_44 ( V_289 -> V_294 ) ;
int V_113 ;
if ( V_289 -> type == V_96 ) {
V_113 = F_75 ( V_18 -> V_101 , V_287 ) ;
if ( V_113 < 0 )
return V_113 ;
F_4 ( 2 , L_41 ,
F_14 ( V_287 , 0 ) , V_18 -> V_104 ) ;
if ( F_14 ( V_287 , 0 ) < V_18 -> V_104 ) {
F_45 ( L_42 ) ;
return - V_91 ;
}
} else if ( V_289 -> type == V_106 ) {
V_113 = F_75 ( V_18 -> V_109 , V_287 ) ;
if ( V_113 < 0 )
return V_113 ;
F_4 ( 2 , L_43 ,
F_14 ( V_287 , 0 ) , V_18 -> V_111 ) ;
F_4 ( 2 , L_44 ,
F_14 ( V_287 , 1 ) , V_18 -> V_112 ) ;
if ( F_14 ( V_287 , 0 ) < V_18 -> V_111 ||
F_14 ( V_287 , 1 ) < V_18 -> V_112 ) {
F_45 ( L_45 ) ;
return - V_91 ;
}
} else {
F_45 ( L_40 , V_289 -> type ) ;
return - V_91 ;
}
return 0 ;
}
static int F_83 ( struct V_288 * V_301 )
{
struct V_17 * V_18 = F_44 ( V_301 -> V_294 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
unsigned long V_40 ;
F_84 ( & V_18 -> V_310 ) ;
if ( F_3 ( V_18 ) ) {
F_13 ( & V_36 -> V_49 , V_40 ) ;
F_21 ( V_18 -> V_50 , & V_36 -> V_51 ) ;
F_16 ( & V_36 -> V_49 , V_40 ) ;
}
F_22 ( V_36 ) ;
return 0 ;
}
static int F_85 ( struct V_288 * V_301 )
{
unsigned long V_40 ;
struct V_17 * V_18 = F_44 ( V_301 -> V_294 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
if ( ( V_18 -> V_21 == V_24 ||
V_18 -> V_21 == V_23 ) &&
V_36 -> V_311 == V_18 -> V_50 && V_36 -> V_312 ) {
V_18 -> V_21 = V_313 ;
F_51 ( V_18 , V_314 ,
0 ) ;
}
V_18 -> V_21 = V_315 ;
F_13 ( & V_36 -> V_41 , V_40 ) ;
if ( V_301 -> type == V_96 ) {
F_86 ( & V_18 -> V_42 , & V_18 -> V_116 ) ;
F_11 ( & V_18 -> V_42 ) ;
V_18 -> V_20 = 0 ;
}
if ( V_301 -> type == V_106 ) {
F_5 ( V_18 ) ;
F_86 ( & V_18 -> V_34 , & V_18 -> V_114 ) ;
F_11 ( & V_18 -> V_34 ) ;
V_18 -> V_19 = 0 ;
}
F_16 ( & V_36 -> V_41 , V_40 ) ;
return 0 ;
}
static void F_87 ( struct V_286 * V_287 )
{
struct V_288 * V_289 = V_287 -> V_288 ;
struct V_17 * V_18 = F_44 ( V_289 -> V_294 ) ;
struct V_35 * V_36 = V_18 -> V_36 ;
unsigned long V_40 ;
struct V_25 * V_316 ;
if ( V_18 -> V_21 == V_153 ) {
F_20 ( V_287 , V_317 ) ;
F_5 ( V_18 ) ;
return;
}
if ( V_289 -> type == V_96 ) {
V_316 = & V_18 -> V_303 [ V_287 -> V_62 . V_89 ] ;
V_316 -> V_60 = 0 ;
F_13 ( & V_36 -> V_41 , V_40 ) ;
F_10 ( & V_316 -> V_31 , & V_18 -> V_42 ) ;
V_18 -> V_20 ++ ;
F_16 ( & V_36 -> V_41 , V_40 ) ;
} else if ( V_289 -> type == V_106 ) {
V_316 = & V_18 -> V_306 [ V_287 -> V_62 . V_89 ] ;
V_316 -> V_60 = 0 ;
F_13 ( & V_36 -> V_41 , V_40 ) ;
if ( V_287 -> V_318 [ 0 ] . V_319 == 0 ) {
F_4 ( 1 , L_46 ) ;
V_18 -> V_21 = V_24 ;
F_20 ( V_287 , V_48 ) ;
F_5 ( V_18 ) ;
} else {
F_10 ( & V_316 -> V_31 , & V_18 -> V_34 ) ;
V_18 -> V_19 ++ ;
}
F_16 ( & V_36 -> V_41 , V_40 ) ;
} else {
F_45 ( L_47 , V_289 -> type ) ;
}
if ( F_3 ( V_18 ) ) {
F_13 ( & V_36 -> V_49 , V_40 ) ;
F_21 ( V_18 -> V_50 , & V_36 -> V_51 ) ;
F_16 ( & V_36 -> V_49 , V_40 ) ;
}
F_22 ( V_36 ) ;
}
struct V_320 * F_88 ( void )
{
return & V_321 ;
}
struct V_322 * F_89 ( void )
{
return & V_323 ;
}
const struct V_324 * F_90 ( void )
{
return & V_325 ;
}
int F_91 ( struct V_17 * V_18 )
{
struct V_326 V_327 ;
int V_5 ;
F_92 ( & V_18 -> V_310 , V_328 ) ;
if ( V_18 -> V_310 . error ) {
F_45 ( L_48 ) ;
return V_18 -> V_310 . error ;
}
for ( V_5 = 0 ; V_5 < V_328 ; V_5 ++ ) {
if ( F_93 ( V_329 [ V_5 ] . V_12 ) ) {
V_327 . V_330 = & V_331 ;
V_327 . V_12 = V_329 [ V_5 ] . V_12 ;
V_327 . V_332 = V_329 [ V_5 ] . V_333 ;
V_327 . V_334 = V_329 [ V_5 ] . V_335 ;
V_327 . V_336 = V_329 [ V_5 ] . V_337 ;
V_327 . V_74 = V_329 [ V_5 ] . V_74 ;
V_327 . type = V_329 [ V_5 ] . type ;
V_327 . V_40 = 0 ;
if ( V_327 . type == V_338 ) {
V_327 . V_339 = 0 ;
V_327 . V_340 = V_327 . V_340 ;
V_327 . V_341 = F_2 ( V_327 . V_12 ) ;
} else {
V_327 . V_339 = V_329 [ V_5 ] . V_339 ;
V_327 . V_340 = 0 ;
}
V_18 -> V_342 [ V_5 ] = F_94 ( & V_18 -> V_310 ,
& V_327 , NULL ) ;
} else {
if ( V_329 [ V_5 ] . type == V_338 ) {
V_18 -> V_342 [ V_5 ] = F_95 (
& V_18 -> V_310 ,
& V_331 , V_329 [ V_5 ] . V_12 ,
V_329 [ V_5 ] . V_335 , 0 ,
V_329 [ V_5 ] . V_337 ) ;
} else {
V_18 -> V_342 [ V_5 ] = F_96 (
& V_18 -> V_310 ,
& V_331 , V_329 [ V_5 ] . V_12 ,
V_329 [ V_5 ] . V_333 ,
V_329 [ V_5 ] . V_335 , V_329 [ V_5 ] . V_339 ,
V_329 [ V_5 ] . V_337 ) ;
}
}
if ( V_18 -> V_310 . error ) {
F_45 ( L_49 , V_5 ) ;
return V_18 -> V_310 . error ;
}
if ( V_329 [ V_5 ] . V_343 && V_18 -> V_342 [ V_5 ] )
V_18 -> V_342 [ V_5 ] -> V_343 = 1 ;
}
return 0 ;
}
void F_97 ( struct V_17 * V_18 )
{
int V_5 ;
F_98 ( & V_18 -> V_310 ) ;
for ( V_5 = 0 ; V_5 < V_328 ; V_5 ++ )
V_18 -> V_342 [ V_5 ] = NULL ;
}
