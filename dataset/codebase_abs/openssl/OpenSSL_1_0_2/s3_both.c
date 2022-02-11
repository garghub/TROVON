int F_1 ( T_1 * V_1 , int type )
{
int V_2 ;
V_2 = F_2 ( V_1 , type , & V_1 -> V_3 -> V_4 [ V_1 -> V_5 ] ,
V_1 -> V_6 ) ;
if ( V_2 < 0 )
return ( - 1 ) ;
if ( type == V_7 )
F_3 ( V_1 , ( unsigned char * ) & V_1 -> V_3 -> V_4 [ V_1 -> V_5 ] ,
V_2 ) ;
if ( V_2 == V_1 -> V_6 ) {
if ( V_1 -> V_8 )
V_1 -> V_8 ( 1 , V_1 -> V_9 , type , V_1 -> V_3 -> V_4 ,
( V_10 ) ( V_1 -> V_5 + V_1 -> V_6 ) , V_1 ,
V_1 -> V_11 ) ;
return ( 1 ) ;
}
V_1 -> V_5 += V_2 ;
V_1 -> V_6 -= V_2 ;
return ( 0 ) ;
}
int F_4 ( T_1 * V_1 , int V_12 , int V_13 , const char * V_14 , int V_15 )
{
unsigned char * V_16 ;
int V_17 ;
unsigned long V_18 ;
if ( V_1 -> V_19 == V_12 ) {
V_16 = F_5 ( V_1 ) ;
V_17 = V_1 -> V_20 -> V_21 -> V_22 ( V_1 ,
V_14 , V_15 ,
V_1 -> V_23 -> V_24 . V_25 ) ;
if ( V_17 == 0 )
return 0 ;
V_1 -> V_23 -> V_24 . V_26 = V_17 ;
memcpy ( V_16 , V_1 -> V_23 -> V_24 . V_25 , V_17 ) ;
V_18 = V_17 ;
if ( V_1 -> type == V_27 ) {
F_6 ( V_17 <= V_28 ) ;
memcpy ( V_1 -> V_23 -> V_29 , V_1 -> V_23 -> V_24 . V_25 , V_17 ) ;
V_1 -> V_23 -> V_30 = V_17 ;
} else {
F_6 ( V_17 <= V_28 ) ;
memcpy ( V_1 -> V_23 -> V_31 , V_1 -> V_23 -> V_24 . V_25 , V_17 ) ;
V_1 -> V_23 -> V_32 = V_17 ;
}
#ifdef F_7
V_18 &= 0xffff ;
#endif
F_8 ( V_1 , V_33 , V_18 ) ;
V_1 -> V_19 = V_13 ;
}
return F_9 ( V_1 ) ;
}
static void F_10 ( T_1 * V_1 )
{
const char * V_14 ;
int V_15 ;
if ( V_1 -> V_23 -> V_24 . V_34 == NULL )
return;
if ( V_1 -> V_19 & V_27 ) {
V_14 = V_1 -> V_20 -> V_21 -> V_35 ;
V_15 = V_1 -> V_20 -> V_21 -> V_36 ;
} else {
V_14 = V_1 -> V_20 -> V_21 -> V_37 ;
V_15 = V_1 -> V_20 -> V_21 -> V_38 ;
}
V_1 -> V_23 -> V_24 . V_39 = V_1 -> V_20 -> V_21 -> V_22 ( V_1 ,
V_14 ,
V_15 ,
V_1 -> V_23 -> V_24 . V_40 ) ;
}
int F_11 ( T_1 * V_1 , int V_12 , int V_13 )
{
int V_41 , V_17 , V_42 ;
long V_43 ;
unsigned char * V_16 ;
#ifdef F_12
#endif
V_43 = V_1 -> V_20 -> V_44 ( V_1 , V_12 , V_13 , V_33 , 64 , & V_42 ) ;
if ( ! V_42 )
return ( ( int ) V_43 ) ;
if ( ! V_1 -> V_23 -> V_45 ) {
V_41 = V_46 ;
F_13 ( V_47 , V_48 ) ;
goto V_49;
}
V_1 -> V_23 -> V_45 = 0 ;
V_16 = ( unsigned char * ) V_1 -> V_50 ;
V_17 = V_1 -> V_23 -> V_24 . V_39 ;
if ( V_17 != V_43 ) {
V_41 = V_51 ;
F_13 ( V_47 , V_52 ) ;
goto V_49;
}
if ( F_14 ( V_16 , V_1 -> V_23 -> V_24 . V_40 , V_17 ) != 0 ) {
V_41 = V_53 ;
F_13 ( V_47 , V_54 ) ;
goto V_49;
}
if ( V_1 -> type == V_55 ) {
F_6 ( V_17 <= V_28 ) ;
memcpy ( V_1 -> V_23 -> V_29 , V_1 -> V_23 -> V_24 . V_40 , V_17 ) ;
V_1 -> V_23 -> V_30 = V_17 ;
} else {
F_6 ( V_17 <= V_28 ) ;
memcpy ( V_1 -> V_23 -> V_31 , V_1 -> V_23 -> V_24 . V_40 , V_17 ) ;
V_1 -> V_23 -> V_32 = V_17 ;
}
return ( 1 ) ;
V_49:
F_15 ( V_1 , V_56 , V_41 ) ;
return ( 0 ) ;
}
int F_16 ( T_1 * V_1 , int V_12 , int V_13 )
{
unsigned char * V_16 ;
if ( V_1 -> V_19 == V_12 ) {
V_16 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
* V_16 = V_57 ;
V_1 -> V_6 = 1 ;
V_1 -> V_5 = 0 ;
V_1 -> V_19 = V_13 ;
}
return ( F_1 ( V_1 , V_58 ) ) ;
}
unsigned long F_17 ( T_1 * V_1 , T_2 * V_59 )
{
unsigned char * V_16 ;
unsigned long V_18 = 3 + F_18 ( V_1 ) ;
if ( ! F_19 ( V_1 , V_59 , & V_18 ) )
return 0 ;
V_18 -= 3 + F_18 ( V_1 ) ;
V_16 = F_5 ( V_1 ) ;
F_20 ( V_18 , V_16 ) ;
V_18 += 3 ;
F_8 ( V_1 , V_60 , V_18 ) ;
return V_18 + F_18 ( V_1 ) ;
}
long F_21 ( T_1 * V_1 , int V_61 , int V_62 , int V_63 , long V_64 , int * V_42 )
{
unsigned char * V_16 ;
unsigned long V_18 ;
long V_43 ;
int V_17 , V_41 ;
if ( V_1 -> V_23 -> V_24 . V_65 ) {
V_1 -> V_23 -> V_24 . V_65 = 0 ;
if ( ( V_63 >= 0 ) && ( V_1 -> V_23 -> V_24 . V_66 != V_63 ) ) {
V_41 = V_46 ;
F_13 ( V_67 , V_68 ) ;
goto V_49;
}
* V_42 = 1 ;
V_1 -> V_19 = V_62 ;
V_1 -> V_50 = V_1 -> V_3 -> V_4 + 4 ;
V_1 -> V_6 = ( int ) V_1 -> V_23 -> V_24 . V_69 ;
return V_1 -> V_6 ;
}
V_16 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
if ( V_1 -> V_19 == V_61 ) {
int V_70 ;
do {
while ( V_1 -> V_6 < 4 ) {
V_17 = V_1 -> V_20 -> V_71 ( V_1 , V_7 ,
& V_16 [ V_1 -> V_6 ] ,
4 - V_1 -> V_6 , 0 ) ;
if ( V_17 <= 0 ) {
V_1 -> V_72 = V_73 ;
* V_42 = 0 ;
return V_17 ;
}
V_1 -> V_6 += V_17 ;
}
V_70 = 0 ;
if ( ! V_1 -> V_74 )
if ( V_16 [ 0 ] == V_75 )
if ( V_16 [ 1 ] == 0 && V_16 [ 2 ] == 0 && V_16 [ 3 ] == 0 ) {
V_1 -> V_6 = 0 ;
V_70 = 1 ;
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_1 -> V_9 , V_7 ,
V_16 , 4 , V_1 , V_1 -> V_11 ) ;
}
}
while ( V_70 );
if ( ( V_63 >= 0 ) && ( * V_16 != V_63 ) ) {
V_41 = V_46 ;
F_13 ( V_67 , V_68 ) ;
goto V_49;
}
V_1 -> V_23 -> V_24 . V_66 = * ( V_16 ++ ) ;
F_22 ( V_16 , V_18 ) ;
if ( V_18 > ( unsigned long ) V_64 ) {
V_41 = V_76 ;
F_13 ( V_67 , V_77 ) ;
goto V_49;
}
if ( V_18 > ( V_78 - 4 ) ) {
V_41 = V_76 ;
F_13 ( V_67 , V_77 ) ;
goto V_49;
}
if ( V_18 && ! F_23 ( V_1 -> V_3 , ( int ) V_18 + 4 ) ) {
F_13 ( V_67 , V_79 ) ;
goto V_80;
}
V_1 -> V_23 -> V_24 . V_69 = V_18 ;
V_1 -> V_19 = V_62 ;
V_1 -> V_50 = V_1 -> V_3 -> V_4 + 4 ;
V_1 -> V_6 = 0 ;
}
V_16 = V_1 -> V_50 ;
V_43 = V_1 -> V_23 -> V_24 . V_69 - V_1 -> V_6 ;
while ( V_43 > 0 ) {
V_17 = V_1 -> V_20 -> V_71 ( V_1 , V_7 , & V_16 [ V_1 -> V_6 ] ,
V_43 , 0 ) ;
if ( V_17 <= 0 ) {
V_1 -> V_72 = V_73 ;
* V_42 = 0 ;
return V_17 ;
}
V_1 -> V_6 += V_17 ;
V_43 -= V_17 ;
}
#ifndef F_12
if ( * V_1 -> V_3 -> V_4 == V_33 )
F_10 ( V_1 ) ;
#endif
F_3 ( V_1 , ( unsigned char * ) V_1 -> V_3 -> V_4 , V_1 -> V_6 + 4 ) ;
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_1 -> V_9 , V_7 , V_1 -> V_3 -> V_4 ,
( V_10 ) V_1 -> V_6 + 4 , V_1 , V_1 -> V_11 ) ;
* V_42 = 1 ;
return V_1 -> V_6 ;
V_49:
F_15 ( V_1 , V_56 , V_41 ) ;
V_80:
* V_42 = 0 ;
return ( - 1 ) ;
}
int F_24 ( T_3 * V_81 , T_4 * V_82 )
{
T_4 * V_83 ;
int V_2 = - 1 , V_17 ;
if ( V_82 == NULL )
V_83 = F_25 ( V_81 ) ;
else
V_83 = V_82 ;
if ( V_83 == NULL )
goto V_80;
V_17 = V_83 -> type ;
if ( V_17 == V_84 ) {
V_2 = V_85 ;
} else if ( V_17 == V_86 ) {
V_2 = V_87 ;
}
#ifndef F_26
else if ( V_17 == V_88 ) {
V_2 = V_89 ;
}
#endif
else if ( V_17 == V_90 || V_17 == V_91 ) {
V_2 = V_92 ;
} else if ( V_17 == V_93 || V_17 == V_94 ) {
V_2 = V_95 ;
} else if ( V_81 && ( V_17 == V_96 || V_17 == V_97 ) ) {
V_17 = F_27 ( V_81 , V_83 ) ;
if ( V_17 & V_98 )
V_2 = V_99 ;
else if ( V_17 & V_100 )
V_2 = V_101 ;
}
V_80:
if ( ! V_82 )
F_28 ( V_83 ) ;
return ( V_2 ) ;
}
int F_29 ( long type )
{
int V_41 ;
switch ( type ) {
case V_102 :
case V_103 :
case V_104 :
V_41 = V_105 ;
break;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_41 = V_117 ;
break;
case V_118 :
case V_119 :
V_41 = V_53 ;
break;
case V_120 :
case V_121 :
V_41 = V_122 ;
break;
case V_123 :
V_41 = V_124 ;
break;
case V_125 :
V_41 = V_126 ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
V_41 = V_105 ;
break;
case V_134 :
V_41 = V_135 ;
break;
case V_136 :
V_41 = V_137 ;
break;
default:
V_41 = V_138 ;
break;
}
return ( V_41 ) ;
}
static void * F_30 ( T_5 * V_139 , int V_140 , int V_141 )
{
T_6 * V_142 ;
T_7 * V_143 = NULL ;
void * V_144 = NULL ;
F_31 ( V_145 ) ;
V_142 = V_140 ? V_139 -> V_146 : V_139 -> V_147 ;
if ( V_142 != NULL && V_141 == ( int ) V_142 -> V_148 )
V_143 = V_142 -> V_149 ;
if ( V_143 != NULL ) {
V_142 -> V_149 = V_143 -> V_150 ;
V_144 = V_143 ;
if ( -- V_142 -> V_151 == 0 )
V_142 -> V_148 = 0 ;
}
F_32 ( V_145 ) ;
if ( ! V_144 )
V_144 = F_33 ( V_141 ) ;
return V_144 ;
}
static void F_34 ( T_5 * V_139 , int V_140 , V_10 V_141 , void * V_152 )
{
T_6 * V_142 ;
T_7 * V_143 ;
F_31 ( V_145 ) ;
V_142 = V_140 ? V_139 -> V_146 : V_139 -> V_147 ;
if ( V_142 != NULL &&
( V_141 == V_142 -> V_148 || V_142 -> V_148 == 0 ) &&
V_142 -> V_151 < V_139 -> V_153 && V_141 >= sizeof( * V_143 ) ) {
V_142 -> V_148 = V_141 ;
V_143 = V_152 ;
V_143 -> V_150 = V_142 -> V_149 ;
V_142 -> V_149 = V_143 ;
++ V_142 -> V_151 ;
V_152 = NULL ;
}
F_32 ( V_145 ) ;
if ( V_152 )
F_35 ( V_152 ) ;
}
int F_36 ( T_1 * V_1 )
{
unsigned char * V_16 ;
V_10 V_151 , V_154 = 0 , V_155 ;
if ( F_37 ( V_1 ) == V_156 || F_37 ( V_1 ) == V_157 )
V_155 = V_158 ;
else
V_155 = V_159 ;
#if F_38 ( V_160 ) && V_160 != 0
V_154 = ( - V_159 ) & ( V_160 - 1 ) ;
#endif
if ( V_1 -> V_23 -> V_161 . V_162 == NULL ) {
V_151 = V_163
+ V_164 + V_155 + V_154 ;
if ( V_1 -> V_165 & V_166 ) {
V_1 -> V_23 -> V_167 = 1 ;
V_151 += V_168 ;
}
#ifndef F_39
if ( ! ( V_1 -> V_165 & V_169 ) )
V_151 += V_170 ;
#endif
if ( ( V_16 = F_30 ( V_1 -> V_139 , 1 , V_151 ) ) == NULL )
goto V_80;
V_1 -> V_23 -> V_161 . V_162 = V_16 ;
V_1 -> V_23 -> V_161 . V_151 = V_151 ;
}
V_1 -> V_171 = & ( V_1 -> V_23 -> V_161 . V_162 [ 0 ] ) ;
return 1 ;
V_80:
F_13 ( V_172 , V_173 ) ;
return 0 ;
}
int F_40 ( T_1 * V_1 )
{
unsigned char * V_16 ;
V_10 V_151 , V_154 = 0 , V_155 ;
if ( F_37 ( V_1 ) == V_156 || F_37 ( V_1 ) == V_157 )
V_155 = V_158 + 1 ;
else
V_155 = V_159 ;
#if F_38 ( V_160 ) && V_160 != 0
V_154 = ( - V_159 ) & ( V_160 - 1 ) ;
#endif
if ( V_1 -> V_23 -> V_174 . V_162 == NULL ) {
V_151 = V_1 -> V_175
+ V_176 + V_155 + V_154 ;
#ifndef F_39
if ( ! ( V_1 -> V_165 & V_169 ) )
V_151 += V_170 ;
#endif
if ( ! ( V_1 -> V_165 & V_177 ) )
V_151 += V_155 + V_154 + V_176 ;
if ( ( V_16 = F_30 ( V_1 -> V_139 , 0 , V_151 ) ) == NULL )
goto V_80;
V_1 -> V_23 -> V_174 . V_162 = V_16 ;
V_1 -> V_23 -> V_174 . V_151 = V_151 ;
}
return 1 ;
V_80:
F_13 ( V_178 , V_173 ) ;
return 0 ;
}
int F_41 ( T_1 * V_1 )
{
if ( ! F_36 ( V_1 ) )
return 0 ;
if ( ! F_40 ( V_1 ) )
return 0 ;
return 1 ;
}
int F_42 ( T_1 * V_1 )
{
if ( V_1 -> V_23 -> V_174 . V_162 != NULL ) {
F_34 ( V_1 -> V_139 , 0 , V_1 -> V_23 -> V_174 . V_151 , V_1 -> V_23 -> V_174 . V_162 ) ;
V_1 -> V_23 -> V_174 . V_162 = NULL ;
}
return 1 ;
}
int F_43 ( T_1 * V_1 )
{
if ( V_1 -> V_23 -> V_161 . V_162 != NULL ) {
F_34 ( V_1 -> V_139 , 1 , V_1 -> V_23 -> V_161 . V_151 , V_1 -> V_23 -> V_161 . V_162 ) ;
V_1 -> V_23 -> V_161 . V_162 = NULL ;
}
return 1 ;
}
