T_1 * F_1 ( char * V_1 , T_2 * V_2 )
{
T_3 V_3 ;
if ( ! V_2 )
return F_2 ( V_1 , NULL ) ;
F_3 ( & V_3 , V_2 ) ;
return F_2 ( V_1 , & V_3 ) ;
}
T_1 * F_2 ( char * V_1 , T_3 * V_3 )
{
T_1 * V_4 ;
T_4 V_5 ;
T_5 * V_6 ;
int V_7 , V_8 ;
unsigned char * V_9 = NULL , * V_10 = NULL ;
const unsigned char * V_11 ;
unsigned char * V_12 ;
const unsigned char * V_13 ;
int V_14 ;
long V_15 ;
int V_16 = 0 , V_17 , V_18 ;
int V_19 ;
V_5 . V_20 = - 1 ;
V_5 . V_21 = - 1 ;
V_5 . V_22 = V_23 ;
V_5 . V_24 = 0 ;
if ( F_4 ( V_1 , ',' , 1 , V_25 , & V_5 ) != 0 )
return NULL ;
if ( ( V_5 . V_26 == V_27 )
|| ( V_5 . V_26 == V_28 ) ) {
if ( ! V_3 ) {
F_5 ( V_29 ,
V_30 ) ;
return NULL ;
}
V_4 = F_6 ( V_5 . V_26 , V_5 . V_1 , V_3 ) ;
} else
V_4 = F_7 ( V_5 . V_1 , V_5 . V_22 , V_5 . V_26 ) ;
if ( ! V_4 )
return NULL ;
if ( ( V_5 . V_20 == - 1 ) && ( V_5 . V_24 == 0 ) )
return V_4 ;
V_14 = F_8 ( V_4 , & V_9 ) ;
F_9 ( V_4 ) ;
V_4 = NULL ;
V_11 = V_9 ;
if ( V_5 . V_20 != - 1 ) {
V_19 = F_10 ( & V_11 , & V_15 , & V_17 , & V_18 ,
V_14 ) ;
if ( V_19 & 0x80 )
goto V_31;
V_14 -= V_11 - V_9 ;
if ( V_19 & 0x1 ) {
V_16 = 2 ;
V_15 = 0 ;
} else
V_16 = V_19 & V_32 ;
V_8 = F_11 ( 0 , V_15 , V_5 . V_20 ) ;
} else
V_8 = V_14 ;
for ( V_7 = 0 , V_6 = V_5 . V_33 + V_5 . V_24 - 1 ;
V_7 < V_5 . V_24 ; V_7 ++ , V_6 -- ) {
V_8 += V_6 -> V_34 ;
V_6 -> V_35 = V_8 ;
V_8 = F_11 ( 0 , V_8 , V_6 -> V_36 ) ;
}
V_10 = F_12 ( V_8 ) ;
if ( ! V_10 )
goto V_31;
V_12 = V_10 ;
for ( V_7 = 0 , V_6 = V_5 . V_33 ; V_7 < V_5 . V_24 ;
V_7 ++ , V_6 ++ ) {
F_13 ( & V_12 , V_6 -> V_37 , V_6 -> V_35 ,
V_6 -> V_36 , V_6 -> V_38 ) ;
if ( V_6 -> V_34 )
* V_12 ++ = 0 ;
}
if ( V_5 . V_20 != - 1 ) {
if ( V_5 . V_21 == V_39
&& ( V_5 . V_20 == V_27
|| V_5 . V_20 == V_28 ) )
V_16 = V_32 ;
F_13 ( & V_12 , V_16 , V_15 ,
V_5 . V_20 , V_5 . V_21 ) ;
}
memcpy ( V_12 , V_11 , V_14 ) ;
V_13 = V_10 ;
V_4 = F_14 ( NULL , & V_13 , V_8 ) ;
V_31:
if ( V_9 )
F_15 ( V_9 ) ;
if ( V_10 )
F_15 ( V_10 ) ;
return V_4 ;
}
static int V_25 ( const char * V_40 , int V_8 , void * V_41 )
{
T_4 * V_42 = V_41 ;
int V_7 ;
int V_26 ;
int V_43 = 0 ;
const char * V_12 , * V_44 = NULL ;
int V_45 , V_46 ;
for ( V_7 = 0 , V_12 = V_40 ; V_7 < V_8 ; V_12 ++ , V_7 ++ ) {
if ( * V_12 == ':' ) {
V_44 = V_12 + 1 ;
V_43 = V_8 - ( V_44 - V_40 ) ;
V_8 = V_12 - V_40 ;
break;
}
}
V_26 = F_16 ( V_40 , V_8 ) ;
if ( V_26 == - 1 ) {
F_5 ( V_47 , V_48 ) ;
F_17 ( 2 , L_1 , V_40 ) ;
return - 1 ;
}
if ( ! ( V_26 & V_49 ) ) {
V_42 -> V_26 = V_26 ;
V_42 -> V_1 = V_44 ;
if ( ! V_44 && V_40 [ V_8 ] ) {
F_5 ( V_47 , V_50 ) ;
return - 1 ;
}
return 0 ;
}
switch ( V_26 ) {
case V_51 :
if ( V_42 -> V_20 != - 1 ) {
F_5 ( V_47 , V_52 ) ;
return - 1 ;
}
if ( ! F_18 ( V_44 , V_43 , & V_42 -> V_20 , & V_42 -> V_21 ) )
return - 1 ;
break;
case V_53 :
if ( ! F_18 ( V_44 , V_43 , & V_45 , & V_46 ) )
return - 1 ;
if ( ! F_19 ( V_42 , V_45 , V_46 , 1 , 0 , 0 ) )
return - 1 ;
break;
case V_54 :
if ( ! F_19 ( V_42 , V_27 , V_39 , 1 , 0 , 1 ) )
return - 1 ;
break;
case V_55 :
if ( ! F_19 ( V_42 , V_28 , V_39 , 1 , 0 , 1 ) )
return - 1 ;
break;
case V_56 :
if ( ! F_19 ( V_42 , V_57 , V_39 , 0 , 1 , 1 ) )
return - 1 ;
break;
case V_58 :
if ( ! F_19 ( V_42 , V_59 , V_39 , 0 , 0 , 1 ) )
return - 1 ;
break;
case V_60 :
if ( ! strncmp ( V_44 , L_2 , 5 ) )
V_42 -> V_22 = V_23 ;
else if ( ! strncmp ( V_44 , L_3 , 4 ) )
V_42 -> V_22 = V_61 ;
else if ( ! strncmp ( V_44 , L_4 , 3 ) )
V_42 -> V_22 = V_62 ;
else if ( ! strncmp ( V_44 , L_5 , 3 ) )
V_42 -> V_22 = V_63 ;
else {
F_5 ( V_47 , V_64 ) ;
return - 1 ;
}
break;
}
return 1 ;
}
static int F_18 ( const char * V_44 , int V_43 , int * V_65 , int * V_66 )
{
char V_67 [ 2 ] ;
long V_68 ;
char * V_69 ;
if ( ! V_44 )
return 0 ;
V_68 = strtoul ( V_44 , & V_69 , 10 ) ;
if ( V_69 && * V_69 && ( V_69 > V_44 + V_43 ) )
return 0 ;
if ( V_68 < 0 ) {
F_5 ( V_70 , V_71 ) ;
return 0 ;
}
* V_65 = V_68 ;
if ( V_69 )
V_43 -= V_69 - V_44 ;
else
V_43 = 0 ;
if ( V_43 ) {
switch ( * V_69 ) {
case 'U' :
* V_66 = V_39 ;
break;
case 'A' :
* V_66 = V_72 ;
break;
case 'P' :
* V_66 = V_73 ;
break;
case 'C' :
* V_66 = V_74 ;
break;
default:
V_67 [ 0 ] = * V_69 ;
V_67 [ 1 ] = 0 ;
F_5 ( V_70 , V_75 ) ;
F_17 ( 2 , L_6 , V_67 ) ;
return 0 ;
break;
}
} else
* V_66 = V_74 ;
return 1 ;
}
static T_1 * F_6 ( int V_26 , const char * V_76 , T_3 * V_3 )
{
T_1 * V_4 = NULL ;
F_20 ( T_1 ) * V_77 = NULL ;
F_20 ( V_78 ) * V_79 = NULL ;
unsigned char * V_80 = NULL ;
int V_81 ;
int V_7 ;
V_77 = F_21 () ;
if ( ! V_77 )
goto V_82;
if ( V_76 ) {
if ( ! V_3 )
goto V_82;
V_79 = F_22 ( V_3 , ( char * ) V_76 ) ;
if ( ! V_79 )
goto V_82;
for ( V_7 = 0 ; V_7 < F_23 ( V_79 ) ; V_7 ++ ) {
T_1 * V_83 =
F_2 ( F_24 ( V_79 , V_7 ) -> V_84 , V_3 ) ;
if ( ! V_83 )
goto V_82;
if ( ! F_25 ( V_77 , V_83 ) )
goto V_82;
}
}
if ( V_26 == V_28 )
V_81 = F_26 ( V_77 , & V_80 ) ;
else
V_81 = F_27 ( V_77 , & V_80 ) ;
if ( V_81 < 0 )
goto V_82;
if ( ! ( V_4 = F_28 () ) )
goto V_82;
if ( ! ( V_4 -> V_84 . V_85 = F_29 ( V_26 ) ) )
goto V_82;
V_4 -> type = V_26 ;
V_4 -> V_84 . V_85 -> V_86 = V_80 ;
V_4 -> V_84 . V_85 -> V_87 = V_81 ;
V_80 = NULL ;
V_82:
if ( V_80 )
F_15 ( V_80 ) ;
if ( V_77 )
F_30 ( V_77 , F_9 ) ;
if ( V_79 )
F_31 ( V_3 , V_79 ) ;
return V_4 ;
}
static int F_19 ( T_4 * V_42 , int V_36 , int V_38 ,
int V_37 , int V_34 , int V_88 )
{
T_5 * V_89 ;
if ( ( V_42 -> V_20 != - 1 ) && ! V_88 ) {
F_5 ( V_90 , V_91 ) ;
return 0 ;
}
if ( V_42 -> V_24 == V_92 ) {
F_5 ( V_90 , V_93 ) ;
return 0 ;
}
V_89 = & V_42 -> V_33 [ V_42 -> V_24 ++ ] ;
if ( V_42 -> V_20 != - 1 ) {
V_89 -> V_36 = V_42 -> V_20 ;
V_89 -> V_38 = V_42 -> V_21 ;
V_42 -> V_20 = - 1 ;
V_42 -> V_21 = - 1 ;
} else {
V_89 -> V_36 = V_36 ;
V_89 -> V_38 = V_38 ;
}
V_89 -> V_37 = V_37 ;
V_89 -> V_34 = V_34 ;
return 1 ;
}
static int F_16 ( const char * V_94 , int V_8 )
{
unsigned int V_7 ;
static const struct V_95 * V_96 , V_97 [] = {
F_32 ( L_7 , V_98 ) ,
F_32 ( L_8 , V_98 ) ,
F_32 ( L_9 , V_99 ) ,
F_32 ( L_10 , V_100 ) ,
F_32 ( L_11 , V_100 ) ,
F_32 ( L_12 , V_101 ) ,
F_32 ( L_13 , V_101 ) ,
F_32 ( L_14 , V_102 ) ,
F_32 ( L_15 , V_102 ) ,
F_32 ( L_16 , V_103 ) ,
F_32 ( L_17 , V_103 ) ,
F_32 ( L_18 , V_104 ) ,
F_32 ( L_19 , V_104 ) ,
F_32 ( L_20 , V_59 ) ,
F_32 ( L_21 , V_59 ) ,
F_32 ( L_22 , V_57 ) ,
F_32 ( L_23 , V_57 ) ,
F_32 ( L_24 , V_105 ) ,
F_32 ( L_25 , V_105 ) ,
F_32 ( L_26 , V_106 ) ,
F_32 ( L_27 , V_106 ) ,
F_32 ( L_3 , V_107 ) ,
F_32 ( L_28 , V_107 ) ,
F_32 ( L_29 , V_108 ) ,
F_32 ( L_30 , V_108 ) ,
F_32 ( L_31 , V_109 ) ,
F_32 ( L_32 , V_109 ) ,
F_32 ( L_33 , V_110 ) ,
F_32 ( L_34 , V_110 ) ,
F_32 ( L_35 , V_111 ) ,
F_32 ( L_36 , V_111 ) ,
F_32 ( L_37 , V_111 ) ,
F_32 ( L_38 , V_112 ) ,
F_32 ( L_39 , V_112 ) ,
F_32 ( L_40 , V_113 ) ,
F_32 ( L_41 , V_113 ) ,
F_32 ( L_42 , V_27 ) ,
F_32 ( L_43 , V_27 ) ,
F_32 ( L_44 , V_28 ) ,
F_32 ( L_45 , V_53 ) ,
F_32 ( L_46 , V_53 ) ,
F_32 ( L_47 , V_51 ) ,
F_32 ( L_48 , V_51 ) ,
F_32 ( L_49 , V_58 ) ,
F_32 ( L_50 , V_54 ) ,
F_32 ( L_51 , V_55 ) ,
F_32 ( L_52 , V_56 ) ,
F_32 ( L_53 , V_60 ) ,
F_32 ( L_54 , V_60 ) ,
} ;
if ( V_8 == - 1 )
V_8 = strlen ( V_94 ) ;
V_96 = V_97 ;
for ( V_7 = 0 ; V_7 < sizeof( V_97 ) / sizeof( struct V_95 ) ; V_7 ++ , V_96 ++ ) {
if ( ( V_8 == V_96 -> V_8 ) && ! strncmp ( V_96 -> V_114 , V_94 , V_8 ) )
return V_96 -> V_115 ;
}
return - 1 ;
}
static T_1 * F_7 ( const char * V_1 , int V_22 , int V_26 )
{
T_1 * V_116 = NULL ;
V_78 V_117 ;
unsigned char * V_118 ;
long V_119 ;
int V_120 = 1 ;
if ( ! ( V_116 = F_28 () ) ) {
F_5 ( V_121 , V_122 ) ;
return NULL ;
}
if ( ! V_1 )
V_1 = L_55 ;
switch ( V_26 ) {
case V_99 :
if ( V_1 && * V_1 ) {
F_5 ( V_121 , V_123 ) ;
goto V_124;
}
break;
case V_98 :
if ( V_22 != V_23 ) {
F_5 ( V_121 , V_125 ) ;
goto V_124;
}
V_117 . V_126 = NULL ;
V_117 . V_76 = NULL ;
V_117 . V_84 = ( char * ) V_1 ;
if ( ! F_33 ( & V_117 , & V_116 -> V_84 . boolean ) ) {
F_5 ( V_121 , V_127 ) ;
goto V_128;
}
break;
case V_100 :
case V_101 :
if ( V_22 != V_23 ) {
F_5 ( V_121 , V_129 ) ;
goto V_124;
}
if ( ! ( V_116 -> V_84 . integer = F_34 ( NULL , ( char * ) V_1 ) ) ) {
F_5 ( V_121 , V_130 ) ;
goto V_128;
}
break;
case V_102 :
if ( V_22 != V_23 ) {
F_5 ( V_121 , V_131 ) ;
goto V_124;
}
if ( ! ( V_116 -> V_84 . V_132 = F_35 ( V_1 , 0 ) ) ) {
F_5 ( V_121 , V_133 ) ;
goto V_128;
}
break;
case V_103 :
case V_104 :
if ( V_22 != V_23 ) {
F_5 ( V_121 , V_134 ) ;
goto V_124;
}
if ( ! ( V_116 -> V_84 . V_85 = F_36 () ) ) {
F_5 ( V_121 , V_122 ) ;
goto V_128;
}
if ( ! F_37 ( V_116 -> V_84 . V_85 , V_1 , - 1 ) ) {
F_5 ( V_121 , V_122 ) ;
goto V_128;
}
V_116 -> V_84 . V_85 -> type = V_26 ;
if ( ! F_38 ( V_116 -> V_84 . V_85 ) ) {
F_5 ( V_121 , V_135 ) ;
goto V_128;
}
break;
case V_108 :
case V_110 :
case V_106 :
case V_111 :
case V_107 :
case V_109 :
case V_105 :
case V_112 :
case V_113 :
if ( V_22 == V_23 )
V_22 = V_136 ;
else if ( V_22 == V_61 )
V_22 = V_137 ;
else {
F_5 ( V_121 , V_138 ) ;
goto V_124;
}
if ( F_39 ( & V_116 -> V_84 . V_85 , ( unsigned char * ) V_1 ,
- 1 , V_22 , F_40 ( V_26 ) ) <= 0 ) {
F_5 ( V_121 , V_122 ) ;
goto V_128;
}
break;
case V_57 :
case V_59 :
if ( ! ( V_116 -> V_84 . V_85 = F_36 () ) ) {
F_5 ( V_121 , V_122 ) ;
goto V_124;
}
if ( V_22 == V_62 ) {
if ( ! ( V_118 = F_41 ( ( char * ) V_1 , & V_119 ) ) ) {
F_5 ( V_121 , V_139 ) ;
goto V_128;
}
V_116 -> V_84 . V_85 -> V_86 = V_118 ;
V_116 -> V_84 . V_85 -> V_87 = V_119 ;
V_116 -> V_84 . V_85 -> type = V_26 ;
} else if ( V_22 == V_23 )
F_37 ( V_116 -> V_84 . V_85 , V_1 , - 1 ) ;
else if ( ( V_22 == V_63 )
&& ( V_26 == V_57 ) ) {
if ( ! F_4
( V_1 , ',' , 1 , V_140 , V_116 -> V_84 . V_141 ) ) {
F_5 ( V_121 , V_142 ) ;
goto V_128;
}
V_120 = 0 ;
} else {
F_5 ( V_121 , V_143 ) ;
goto V_124;
}
if ( ( V_26 == V_57 ) && V_120 ) {
V_116 -> V_84 . V_85 -> V_144
&= ~ ( V_145 | 0x07 ) ;
V_116 -> V_84 . V_85 -> V_144 |= V_145 ;
}
break;
default:
F_5 ( V_121 , V_146 ) ;
goto V_128;
break;
}
V_116 -> type = V_26 ;
return V_116 ;
V_128:
F_17 ( 2 , L_56 , V_1 ) ;
V_124:
F_9 ( V_116 ) ;
return NULL ;
}
static int V_140 ( const char * V_40 , int V_8 , void * V_41 )
{
long V_147 ;
char * V_69 ;
if ( ! V_40 )
return 0 ;
V_147 = strtoul ( V_40 , & V_69 , 10 ) ;
if ( V_69 && * V_69 && ( V_69 != V_40 + V_8 ) )
return 0 ;
if ( V_147 < 0 ) {
F_5 ( V_148 , V_71 ) ;
return 0 ;
}
if ( ! F_42 ( V_41 , V_147 , 1 ) ) {
F_5 ( V_148 , V_122 ) ;
return 0 ;
}
return 1 ;
}
