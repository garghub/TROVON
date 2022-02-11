T_1 * F_1 ( const char * V_1 , T_2 * V_2 )
{
T_3 V_3 ;
if ( ! V_2 )
return F_2 ( V_1 , NULL ) ;
F_3 ( & V_3 , V_2 ) ;
return F_2 ( V_1 , & V_3 ) ;
}
T_1 * F_2 ( const char * V_1 , T_3 * V_3 )
{
int V_4 = 0 ;
T_1 * V_5 = F_4 ( V_1 , V_3 , 0 , & V_4 ) ;
if ( V_4 )
F_5 ( V_6 , V_4 ) ;
return V_5 ;
}
static T_1 * F_4 ( const char * V_1 , T_3 * V_3 , int V_7 ,
int * V_8 )
{
T_1 * V_5 ;
T_4 V_9 ;
T_5 * V_10 ;
int V_11 , V_12 ;
unsigned char * V_13 = NULL , * V_14 = NULL ;
const unsigned char * V_15 ;
unsigned char * V_16 ;
const unsigned char * V_17 ;
int V_18 ;
long V_19 = 0 ;
int V_20 = 0 , V_21 , V_22 ;
int V_23 ;
V_9 . V_24 = - 1 ;
V_9 . V_25 = - 1 ;
V_9 . V_26 = V_27 ;
V_9 . V_28 = 0 ;
if ( F_6 ( V_1 , ',' , 1 , V_29 , & V_9 ) != 0 ) {
* V_8 = V_30 ;
return NULL ;
}
if ( ( V_9 . V_31 == V_32 )
|| ( V_9 . V_31 == V_33 ) ) {
if ( ! V_3 ) {
* V_8 = V_34 ;
return NULL ;
}
if ( V_7 >= V_35 ) {
* V_8 = V_36 ;
return NULL ;
}
V_5 = F_7 ( V_9 . V_31 , V_9 . V_1 , V_3 , V_7 , V_8 ) ;
} else
V_5 = F_8 ( V_9 . V_1 , V_9 . V_26 , V_9 . V_31 ) ;
if ( ! V_5 )
return NULL ;
if ( ( V_9 . V_24 == - 1 ) && ( V_9 . V_28 == 0 ) )
return V_5 ;
V_18 = F_9 ( V_5 , & V_13 ) ;
F_10 ( V_5 ) ;
V_5 = NULL ;
V_15 = V_13 ;
if ( V_9 . V_24 != - 1 ) {
V_23 = F_11 ( & V_15 , & V_19 , & V_21 , & V_22 ,
V_18 ) ;
if ( V_23 & 0x80 )
goto V_4;
V_18 -= V_15 - V_13 ;
if ( V_23 & 0x1 ) {
V_20 = 2 ;
V_19 = 0 ;
} else
V_20 = V_23 & V_37 ;
V_12 = F_12 ( 0 , V_19 , V_9 . V_24 ) ;
} else
V_12 = V_18 ;
for ( V_11 = 0 , V_10 = V_9 . V_38 + V_9 . V_28 - 1 ;
V_11 < V_9 . V_28 ; V_11 ++ , V_10 -- ) {
V_12 += V_10 -> V_39 ;
V_10 -> V_40 = V_12 ;
V_12 = F_12 ( 0 , V_12 , V_10 -> V_41 ) ;
}
V_14 = F_13 ( V_12 ) ;
if ( V_14 == NULL )
goto V_4;
V_16 = V_14 ;
for ( V_11 = 0 , V_10 = V_9 . V_38 ; V_11 < V_9 . V_28 ;
V_11 ++ , V_10 ++ ) {
F_14 ( & V_16 , V_10 -> V_42 , V_10 -> V_40 ,
V_10 -> V_41 , V_10 -> V_43 ) ;
if ( V_10 -> V_39 )
* V_16 ++ = 0 ;
}
if ( V_9 . V_24 != - 1 ) {
if ( V_9 . V_25 == V_44
&& ( V_9 . V_24 == V_32
|| V_9 . V_24 == V_33 ) )
V_20 = V_37 ;
F_14 ( & V_16 , V_20 , V_19 ,
V_9 . V_24 , V_9 . V_25 ) ;
}
memcpy ( V_16 , V_15 , V_18 ) ;
V_17 = V_14 ;
V_5 = F_15 ( NULL , & V_17 , V_12 ) ;
V_4:
F_16 ( V_13 ) ;
F_16 ( V_14 ) ;
return V_5 ;
}
static int V_29 ( const char * V_45 , int V_12 , void * V_46 )
{
T_4 * V_47 = V_46 ;
int V_11 ;
int V_31 ;
int V_48 = 0 ;
const char * V_16 , * V_49 = NULL ;
int V_50 , V_51 ;
if ( V_45 == NULL )
return - 1 ;
for ( V_11 = 0 , V_16 = V_45 ; V_11 < V_12 ; V_16 ++ , V_11 ++ ) {
if ( * V_16 == ':' ) {
V_49 = V_16 + 1 ;
V_48 = V_12 - ( V_49 - V_45 ) ;
V_12 = V_16 - V_45 ;
break;
}
}
V_31 = F_17 ( V_45 , V_12 ) ;
if ( V_31 == - 1 ) {
F_5 ( V_52 , V_30 ) ;
F_18 ( 2 , L_1 , V_45 ) ;
return - 1 ;
}
if ( ! ( V_31 & V_53 ) ) {
V_47 -> V_31 = V_31 ;
V_47 -> V_1 = V_49 ;
if ( ! V_49 && V_45 [ V_12 ] ) {
F_5 ( V_52 , V_54 ) ;
return - 1 ;
}
return 0 ;
}
switch ( V_31 ) {
case V_55 :
if ( V_47 -> V_24 != - 1 ) {
F_5 ( V_52 , V_36 ) ;
return - 1 ;
}
if ( ! F_19 ( V_49 , V_48 , & V_47 -> V_24 , & V_47 -> V_25 ) )
return - 1 ;
break;
case V_56 :
if ( ! F_19 ( V_49 , V_48 , & V_50 , & V_51 ) )
return - 1 ;
if ( ! F_20 ( V_47 , V_50 , V_51 , 1 , 0 , 0 ) )
return - 1 ;
break;
case V_57 :
if ( ! F_20 ( V_47 , V_32 , V_44 , 1 , 0 , 1 ) )
return - 1 ;
break;
case V_58 :
if ( ! F_20 ( V_47 , V_33 , V_44 , 1 , 0 , 1 ) )
return - 1 ;
break;
case V_59 :
if ( ! F_20 ( V_47 , V_60 , V_44 , 0 , 1 , 1 ) )
return - 1 ;
break;
case V_61 :
if ( ! F_20 ( V_47 , V_62 , V_44 , 0 , 0 , 1 ) )
return - 1 ;
break;
case V_63 :
if ( ! V_49 ) {
F_5 ( V_52 , V_64 ) ;
return - 1 ;
}
if ( strncmp ( V_49 , L_2 , 5 ) == 0 )
V_47 -> V_26 = V_27 ;
else if ( strncmp ( V_49 , L_3 , 4 ) == 0 )
V_47 -> V_26 = V_65 ;
else if ( strncmp ( V_49 , L_4 , 3 ) == 0 )
V_47 -> V_26 = V_66 ;
else if ( strncmp ( V_49 , L_5 , 7 ) == 0 )
V_47 -> V_26 = V_67 ;
else {
F_5 ( V_52 , V_64 ) ;
return - 1 ;
}
break;
}
return 1 ;
}
static int F_19 ( const char * V_49 , int V_48 , int * V_68 , int * V_69 )
{
char V_70 [ 2 ] ;
long V_71 ;
char * V_72 ;
if ( ! V_49 )
return 0 ;
V_71 = strtoul ( V_49 , & V_72 , 10 ) ;
if ( V_72 && * V_72 && ( V_72 > V_49 + V_48 ) )
return 0 ;
if ( V_71 < 0 ) {
F_5 ( V_73 , V_74 ) ;
return 0 ;
}
* V_68 = V_71 ;
if ( V_72 )
V_48 -= V_72 - V_49 ;
else
V_48 = 0 ;
if ( V_48 ) {
switch ( * V_72 ) {
case 'U' :
* V_69 = V_44 ;
break;
case 'A' :
* V_69 = V_75 ;
break;
case 'P' :
* V_69 = V_76 ;
break;
case 'C' :
* V_69 = V_77 ;
break;
default:
V_70 [ 0 ] = * V_72 ;
V_70 [ 1 ] = 0 ;
F_5 ( V_73 , V_78 ) ;
F_18 ( 2 , L_6 , V_70 ) ;
return 0 ;
}
} else
* V_69 = V_77 ;
return 1 ;
}
static T_1 * F_7 ( int V_31 , const char * V_79 , T_3 * V_3 ,
int V_7 , int * V_8 )
{
T_1 * V_5 = NULL ;
F_21 ( T_1 ) * V_80 = NULL ;
F_21 ( V_81 ) * V_82 = NULL ;
unsigned char * V_83 = NULL ;
int V_84 ;
int V_11 ;
V_80 = F_22 () ;
if ( ! V_80 )
goto V_85;
if ( V_79 ) {
if ( ! V_3 )
goto V_85;
V_82 = F_23 ( V_3 , ( char * ) V_79 ) ;
if ( ! V_82 )
goto V_85;
for ( V_11 = 0 ; V_11 < F_24 ( V_82 ) ; V_11 ++ ) {
T_1 * V_86 =
F_4 ( F_25 ( V_82 , V_11 ) -> V_87 , V_3 ,
V_7 + 1 , V_8 ) ;
if ( ! V_86 )
goto V_85;
if ( ! F_26 ( V_80 , V_86 ) )
goto V_85;
}
}
if ( V_31 == V_33 )
V_84 = F_27 ( V_80 , & V_83 ) ;
else
V_84 = F_28 ( V_80 , & V_83 ) ;
if ( V_84 < 0 )
goto V_85;
if ( ( V_5 = F_29 () ) == NULL )
goto V_85;
if ( ( V_5 -> V_87 . V_88 = F_30 ( V_31 ) ) == NULL )
goto V_85;
V_5 -> type = V_31 ;
V_5 -> V_87 . V_88 -> V_89 = V_83 ;
V_5 -> V_87 . V_88 -> V_90 = V_84 ;
V_83 = NULL ;
V_85:
F_16 ( V_83 ) ;
F_31 ( V_80 , F_10 ) ;
F_32 ( V_3 , V_82 ) ;
return V_5 ;
}
static int F_20 ( T_4 * V_47 , int V_41 , int V_43 ,
int V_42 , int V_39 , int V_91 )
{
T_5 * V_92 ;
if ( ( V_47 -> V_24 != - 1 ) && ! V_91 ) {
F_5 ( V_93 , V_94 ) ;
return 0 ;
}
if ( V_47 -> V_28 == V_95 ) {
F_5 ( V_93 , V_96 ) ;
return 0 ;
}
V_92 = & V_47 -> V_38 [ V_47 -> V_28 ++ ] ;
if ( V_47 -> V_24 != - 1 ) {
V_92 -> V_41 = V_47 -> V_24 ;
V_92 -> V_43 = V_47 -> V_25 ;
V_47 -> V_24 = - 1 ;
V_47 -> V_25 = - 1 ;
} else {
V_92 -> V_41 = V_41 ;
V_92 -> V_43 = V_43 ;
}
V_92 -> V_42 = V_42 ;
V_92 -> V_39 = V_39 ;
return 1 ;
}
static int F_17 ( const char * V_97 , int V_12 )
{
unsigned int V_11 ;
static const struct V_98 * V_99 , V_100 [] = {
F_33 ( L_7 , V_101 ) ,
F_33 ( L_8 , V_101 ) ,
F_33 ( L_9 , V_102 ) ,
F_33 ( L_10 , V_103 ) ,
F_33 ( L_11 , V_103 ) ,
F_33 ( L_12 , V_104 ) ,
F_33 ( L_13 , V_104 ) ,
F_33 ( L_14 , V_105 ) ,
F_33 ( L_15 , V_105 ) ,
F_33 ( L_16 , V_106 ) ,
F_33 ( L_17 , V_106 ) ,
F_33 ( L_18 , V_107 ) ,
F_33 ( L_19 , V_107 ) ,
F_33 ( L_20 , V_62 ) ,
F_33 ( L_21 , V_62 ) ,
F_33 ( L_22 , V_60 ) ,
F_33 ( L_23 , V_60 ) ,
F_33 ( L_24 , V_108 ) ,
F_33 ( L_25 , V_108 ) ,
F_33 ( L_26 , V_109 ) ,
F_33 ( L_27 , V_109 ) ,
F_33 ( L_3 , V_110 ) ,
F_33 ( L_28 , V_110 ) ,
F_33 ( L_29 , V_111 ) ,
F_33 ( L_30 , V_111 ) ,
F_33 ( L_31 , V_112 ) ,
F_33 ( L_32 , V_112 ) ,
F_33 ( L_33 , V_113 ) ,
F_33 ( L_34 , V_113 ) ,
F_33 ( L_35 , V_114 ) ,
F_33 ( L_36 , V_114 ) ,
F_33 ( L_37 , V_114 ) ,
F_33 ( L_38 , V_115 ) ,
F_33 ( L_39 , V_115 ) ,
F_33 ( L_40 , V_116 ) ,
F_33 ( L_41 , V_116 ) ,
F_33 ( L_42 , V_32 ) ,
F_33 ( L_43 , V_32 ) ,
F_33 ( L_44 , V_33 ) ,
F_33 ( L_45 , V_56 ) ,
F_33 ( L_46 , V_56 ) ,
F_33 ( L_47 , V_55 ) ,
F_33 ( L_48 , V_55 ) ,
F_33 ( L_49 , V_61 ) ,
F_33 ( L_50 , V_57 ) ,
F_33 ( L_51 , V_58 ) ,
F_33 ( L_52 , V_59 ) ,
F_33 ( L_53 , V_63 ) ,
F_33 ( L_54 , V_63 ) ,
} ;
if ( V_12 == - 1 )
V_12 = strlen ( V_97 ) ;
V_99 = V_100 ;
for ( V_11 = 0 ; V_11 < F_34 ( V_100 ) ; V_11 ++ , V_99 ++ ) {
if ( ( V_12 == V_99 -> V_12 ) && ( strncmp ( V_99 -> V_117 , V_97 , V_12 ) == 0 ) )
return V_99 -> V_118 ;
}
return - 1 ;
}
static T_1 * F_8 ( const char * V_1 , int V_26 , int V_31 )
{
T_1 * V_119 = NULL ;
V_81 V_120 ;
unsigned char * V_121 ;
long V_122 ;
int V_123 = 1 ;
if ( ( V_119 = F_29 () ) == NULL ) {
F_5 ( V_124 , V_125 ) ;
return NULL ;
}
if ( ! V_1 )
V_1 = L_55 ;
switch ( V_31 ) {
case V_102 :
if ( V_1 && * V_1 ) {
F_5 ( V_124 , V_126 ) ;
goto V_127;
}
break;
case V_101 :
if ( V_26 != V_27 ) {
F_5 ( V_124 , V_128 ) ;
goto V_127;
}
V_120 . V_129 = NULL ;
V_120 . V_79 = NULL ;
V_120 . V_87 = ( char * ) V_1 ;
if ( ! F_35 ( & V_120 , & V_119 -> V_87 . boolean ) ) {
F_5 ( V_124 , V_130 ) ;
goto V_131;
}
break;
case V_103 :
case V_104 :
if ( V_26 != V_27 ) {
F_5 ( V_124 , V_132 ) ;
goto V_127;
}
if ( ( V_119 -> V_87 . integer
= F_36 ( NULL , V_1 ) ) == NULL ) {
F_5 ( V_124 , V_133 ) ;
goto V_131;
}
break;
case V_105 :
if ( V_26 != V_27 ) {
F_5 ( V_124 , V_134 ) ;
goto V_127;
}
if ( ( V_119 -> V_87 . V_135 = F_37 ( V_1 , 0 ) ) == NULL ) {
F_5 ( V_124 , V_136 ) ;
goto V_131;
}
break;
case V_106 :
case V_107 :
if ( V_26 != V_27 ) {
F_5 ( V_124 , V_137 ) ;
goto V_127;
}
if ( ( V_119 -> V_87 . V_88 = F_38 () ) == NULL ) {
F_5 ( V_124 , V_125 ) ;
goto V_131;
}
if ( ! F_39 ( V_119 -> V_87 . V_88 , V_1 , - 1 ) ) {
F_5 ( V_124 , V_125 ) ;
goto V_131;
}
V_119 -> V_87 . V_88 -> type = V_31 ;
if ( ! F_40 ( V_119 -> V_87 . V_88 ) ) {
F_5 ( V_124 , V_138 ) ;
goto V_131;
}
break;
case V_111 :
case V_113 :
case V_109 :
case V_114 :
case V_110 :
case V_112 :
case V_108 :
case V_115 :
case V_116 :
if ( V_26 == V_27 )
V_26 = V_139 ;
else if ( V_26 == V_65 )
V_26 = V_140 ;
else {
F_5 ( V_124 , V_141 ) ;
goto V_127;
}
if ( F_41 ( & V_119 -> V_87 . V_88 , ( unsigned char * ) V_1 ,
- 1 , V_26 , F_42 ( V_31 ) ) <= 0 ) {
F_5 ( V_124 , V_125 ) ;
goto V_131;
}
break;
case V_60 :
case V_62 :
if ( ( V_119 -> V_87 . V_88 = F_38 () ) == NULL ) {
F_5 ( V_124 , V_125 ) ;
goto V_127;
}
if ( V_26 == V_66 ) {
if ( ( V_121 = F_43 ( V_1 , & V_122 ) ) == NULL ) {
F_5 ( V_124 , V_142 ) ;
goto V_131;
}
V_119 -> V_87 . V_88 -> V_89 = V_121 ;
V_119 -> V_87 . V_88 -> V_90 = V_122 ;
V_119 -> V_87 . V_88 -> type = V_31 ;
} else if ( V_26 == V_27 )
F_39 ( V_119 -> V_87 . V_88 , V_1 , - 1 ) ;
else if ( ( V_26 == V_67 )
&& ( V_31 == V_60 ) ) {
if ( ! F_6
( V_1 , ',' , 1 , V_143 , V_119 -> V_87 . V_144 ) ) {
F_5 ( V_124 , V_145 ) ;
goto V_131;
}
V_123 = 0 ;
} else {
F_5 ( V_124 , V_146 ) ;
goto V_127;
}
if ( ( V_31 == V_60 ) && V_123 ) {
V_119 -> V_87 . V_88 -> V_147
&= ~ ( V_148 | 0x07 ) ;
V_119 -> V_87 . V_88 -> V_147 |= V_148 ;
}
break;
default:
F_5 ( V_124 , V_149 ) ;
goto V_131;
}
V_119 -> type = V_31 ;
return V_119 ;
V_131:
F_18 ( 2 , L_56 , V_1 ) ;
V_127:
F_10 ( V_119 ) ;
return NULL ;
}
static int V_143 ( const char * V_45 , int V_12 , void * V_46 )
{
long V_150 ;
char * V_72 ;
if ( ! V_45 )
return 0 ;
V_150 = strtoul ( V_45 , & V_72 , 10 ) ;
if ( V_72 && * V_72 && ( V_72 != V_45 + V_12 ) )
return 0 ;
if ( V_150 < 0 ) {
F_5 ( V_151 , V_74 ) ;
return 0 ;
}
if ( ! F_44 ( V_46 , V_150 , 1 ) ) {
F_5 ( V_151 , V_125 ) ;
return 0 ;
}
return 1 ;
}
static int F_45 ( const char * V_45 , int V_12 , void * V_47 )
{
unsigned long * V_152 = V_47 , V_153 ;
int V_118 ;
if ( V_45 == NULL )
return 0 ;
if ( ( V_12 == 3 ) && ( strncmp ( V_45 , L_57 , 3 ) == 0 ) ) {
* V_152 |= V_154 ;
return 1 ;
}
V_118 = F_17 ( V_45 , V_12 ) ;
if ( ! V_118 || ( V_118 & V_53 ) )
return 0 ;
V_153 = F_42 ( V_118 ) ;
if ( ! V_153 )
return 0 ;
* V_152 |= V_153 ;
return 1 ;
}
int F_46 ( const char * V_1 , unsigned long * V_152 )
{
* V_152 = 0 ;
return F_6 ( V_1 , '|' , 1 , F_45 , V_152 ) ;
}
