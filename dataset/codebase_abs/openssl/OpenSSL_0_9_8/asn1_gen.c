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
if ( ( V_5 . V_26 == V_27 ) || ( V_5 . V_26 == V_28 ) )
{
if ( ! V_3 )
{
F_5 ( V_29 , V_30 ) ;
return NULL ;
}
V_4 = F_6 ( V_5 . V_26 , V_5 . V_1 , V_3 ) ;
}
else
V_4 = F_7 ( V_5 . V_1 , V_5 . V_22 , V_5 . V_26 ) ;
if ( ! V_4 )
return NULL ;
if ( ( V_5 . V_20 == - 1 ) && ( V_5 . V_24 == 0 ) )
return V_4 ;
V_14 = F_8 ( V_4 , & V_9 ) ;
F_9 ( V_4 ) ;
V_4 = NULL ;
V_11 = V_9 ;
if ( V_5 . V_20 != - 1 )
{
V_19 = F_10 ( & V_11 , & V_15 , & V_17 , & V_18 , V_14 ) ;
if ( V_19 & 0x80 )
goto V_31;
V_14 -= V_11 - V_9 ;
if ( V_19 & 0x1 )
{
V_16 = 2 ;
V_15 = 0 ;
}
else
V_16 = V_19 & V_32 ;
V_8 = F_11 ( 0 , V_15 , V_5 . V_20 ) ;
}
else
V_8 = V_14 ;
for( V_7 = 0 , V_6 = V_5 . V_33 + V_5 . V_24 - 1 ; V_7 < V_5 . V_24 ; V_7 ++ , V_6 -- )
{
V_8 += V_6 -> V_34 ;
V_6 -> V_35 = V_8 ;
V_8 = F_11 ( 0 , V_8 , V_6 -> V_36 ) ;
}
V_10 = F_12 ( V_8 ) ;
V_12 = V_10 ;
for ( V_7 = 0 , V_6 = V_5 . V_33 ; V_7 < V_5 . V_24 ; V_7 ++ , V_6 ++ )
{
F_13 ( & V_12 , V_6 -> V_37 , V_6 -> V_35 ,
V_6 -> V_36 , V_6 -> V_38 ) ;
if ( V_6 -> V_34 )
* V_12 ++ = 0 ;
}
if ( V_5 . V_20 != - 1 )
F_13 ( & V_12 , V_16 , V_15 ,
V_5 . V_20 , V_5 . V_21 ) ;
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
static int V_25 ( const char * V_39 , int V_8 , void * V_40 )
{
T_4 * V_41 = V_40 ;
int V_7 ;
int V_26 ;
int V_42 = 0 ;
const char * V_12 , * V_43 = NULL ;
int V_44 , V_45 ;
for( V_7 = 0 , V_12 = V_39 ; V_7 < V_8 ; V_12 ++ , V_7 ++ )
{
if ( * V_12 == ':' )
{
V_43 = V_12 + 1 ;
V_42 = V_8 - ( V_43 - V_39 ) ;
V_8 = V_12 - V_39 ;
break;
}
}
V_26 = F_16 ( V_39 , V_8 ) ;
if ( V_26 == - 1 )
{
F_5 ( V_46 , V_47 ) ;
F_17 ( 2 , L_1 , V_39 ) ;
return - 1 ;
}
if ( ! ( V_26 & V_48 ) )
{
V_41 -> V_26 = V_26 ;
V_41 -> V_1 = V_43 ;
if ( ! V_43 && V_39 [ V_8 ] )
{
F_5 ( V_46 , V_49 ) ;
return - 1 ;
}
return 0 ;
}
switch( V_26 )
{
case V_50 :
if ( V_41 -> V_20 != - 1 )
{
F_5 ( V_46 , V_51 ) ;
return - 1 ;
}
if ( ! F_18 ( V_43 , V_42 , & V_41 -> V_20 , & V_41 -> V_21 ) )
return - 1 ;
break;
case V_52 :
if ( ! F_18 ( V_43 , V_42 , & V_44 , & V_45 ) )
return - 1 ;
if ( ! F_19 ( V_41 , V_44 , V_45 , 1 , 0 , 0 ) )
return - 1 ;
break;
case V_53 :
if ( ! F_19 ( V_41 , V_27 , V_54 , 1 , 0 , 1 ) )
return - 1 ;
break;
case V_55 :
if ( ! F_19 ( V_41 , V_28 , V_54 , 1 , 0 , 1 ) )
return - 1 ;
break;
case V_56 :
if ( ! F_19 ( V_41 , V_57 , V_54 , 0 , 1 , 1 ) )
return - 1 ;
break;
case V_58 :
if ( ! F_19 ( V_41 , V_59 , V_54 , 0 , 0 , 1 ) )
return - 1 ;
break;
case V_60 :
if ( ! strncmp ( V_43 , L_2 , 5 ) )
V_41 -> V_22 = V_23 ;
else if ( ! strncmp ( V_43 , L_3 , 4 ) )
V_41 -> V_22 = V_61 ;
else if ( ! strncmp ( V_43 , L_4 , 3 ) )
V_41 -> V_22 = V_62 ;
else if ( ! strncmp ( V_43 , L_5 , 3 ) )
V_41 -> V_22 = V_63 ;
else
{
F_5 ( V_46 , V_64 ) ;
return - 1 ;
}
break;
}
return 1 ;
}
static int F_18 ( const char * V_43 , int V_42 , int * V_65 , int * V_66 )
{
char V_67 [ 2 ] ;
long V_68 ;
char * V_69 ;
if ( ! V_43 )
return 0 ;
V_68 = strtoul ( V_43 , & V_69 , 10 ) ;
if ( V_69 && * V_69 && ( V_69 > V_43 + V_42 ) )
return 0 ;
if ( V_68 < 0 )
{
F_5 ( V_70 , V_71 ) ;
return 0 ;
}
* V_65 = V_68 ;
if ( V_69 )
V_42 -= V_69 - V_43 ;
else
V_42 = 0 ;
if ( V_42 )
{
switch ( * V_69 )
{
case 'U' :
* V_66 = V_54 ;
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
}
else
* V_66 = V_74 ;
return 1 ;
}
static T_1 * F_6 ( int V_26 , const char * V_76 , T_3 * V_3 )
{
T_1 * V_4 = NULL , * V_77 = NULL ;
F_20 ( T_1 ) * V_78 = NULL ;
F_20 ( V_79 ) * V_80 = NULL ;
unsigned char * V_81 = NULL , * V_12 ;
int V_82 ;
int V_7 , V_83 ;
V_78 = F_21 () ;
if ( V_76 )
{
if ( ! V_3 )
goto V_84;
V_80 = F_22 ( V_3 , ( char * ) V_76 ) ;
if ( ! V_80 )
goto V_84;
for ( V_7 = 0 ; V_7 < F_23 ( V_80 ) ; V_7 ++ )
{
V_77 = F_2 ( F_24 ( V_80 , V_7 ) -> V_85 , V_3 ) ;
if ( ! V_77 )
goto V_84;
F_25 ( V_78 , V_77 ) ;
V_77 = NULL ;
}
}
if ( V_26 == V_28 )
V_83 = 1 ;
else
V_83 = 0 ;
V_82 = F_26 ( V_78 , NULL , F_8 , V_26 ,
V_54 , V_83 ) ;
V_81 = F_12 ( V_82 ) ;
V_12 = V_81 ;
F_26 ( V_78 , & V_12 , F_8 , V_26 ,
V_54 , V_83 ) ;
if ( ! ( V_4 = F_27 () ) )
goto V_84;
if ( ! ( V_4 -> V_85 . V_86 = F_28 ( V_26 ) ) )
goto V_84;
V_4 -> type = V_26 ;
V_4 -> V_85 . V_86 -> V_87 = V_81 ;
V_4 -> V_85 . V_86 -> V_88 = V_82 ;
V_81 = NULL ;
V_84:
if ( V_81 )
F_15 ( V_81 ) ;
if ( V_78 )
F_29 ( V_78 , F_9 ) ;
if ( V_77 )
F_9 ( V_77 ) ;
if ( V_80 )
F_30 ( V_3 , V_80 ) ;
return V_4 ;
}
static int F_19 ( T_4 * V_41 , int V_36 , int V_38 , int V_37 , int V_34 , int V_89 )
{
T_5 * V_90 ;
if ( ( V_41 -> V_20 != - 1 ) && ! V_89 )
{
F_5 ( V_91 , V_92 ) ;
return 0 ;
}
if ( V_41 -> V_24 == V_93 )
{
F_5 ( V_91 , V_94 ) ;
return 0 ;
}
V_90 = & V_41 -> V_33 [ V_41 -> V_24 ++ ] ;
if ( V_41 -> V_20 != - 1 )
{
V_90 -> V_36 = V_41 -> V_20 ;
V_90 -> V_38 = V_41 -> V_21 ;
V_41 -> V_20 = - 1 ;
V_41 -> V_21 = - 1 ;
}
else
{
V_90 -> V_36 = V_36 ;
V_90 -> V_38 = V_38 ;
}
V_90 -> V_37 = V_37 ;
V_90 -> V_34 = V_34 ;
return 1 ;
}
static int F_16 ( const char * V_95 , int V_8 )
{
unsigned int V_7 ;
static struct V_96 * V_97 , V_98 [] = {
F_31 ( L_7 , V_99 ) ,
F_31 ( L_8 , V_99 ) ,
F_31 ( L_9 , V_100 ) ,
F_31 ( L_10 , V_101 ) ,
F_31 ( L_11 , V_101 ) ,
F_31 ( L_12 , V_102 ) ,
F_31 ( L_13 , V_102 ) ,
F_31 ( L_14 , V_103 ) ,
F_31 ( L_15 , V_103 ) ,
F_31 ( L_16 , V_104 ) ,
F_31 ( L_17 , V_104 ) ,
F_31 ( L_18 , V_105 ) ,
F_31 ( L_19 , V_105 ) ,
F_31 ( L_20 , V_59 ) ,
F_31 ( L_21 , V_59 ) ,
F_31 ( L_22 , V_57 ) ,
F_31 ( L_23 , V_57 ) ,
F_31 ( L_24 , V_106 ) ,
F_31 ( L_25 , V_106 ) ,
F_31 ( L_26 , V_107 ) ,
F_31 ( L_27 , V_107 ) ,
F_31 ( L_3 , V_108 ) ,
F_31 ( L_28 , V_108 ) ,
F_31 ( L_29 , V_109 ) ,
F_31 ( L_30 , V_109 ) ,
F_31 ( L_31 , V_110 ) ,
F_31 ( L_32 , V_110 ) ,
F_31 ( L_33 , V_111 ) ,
F_31 ( L_34 , V_111 ) ,
F_31 ( L_35 , V_112 ) ,
F_31 ( L_36 , V_112 ) ,
F_31 ( L_37 , V_112 ) ,
F_31 ( L_38 , V_113 ) ,
F_31 ( L_39 , V_113 ) ,
F_31 ( L_40 , V_27 ) ,
F_31 ( L_41 , V_27 ) ,
F_31 ( L_42 , V_28 ) ,
F_31 ( L_43 , V_52 ) ,
F_31 ( L_44 , V_52 ) ,
F_31 ( L_45 , V_50 ) ,
F_31 ( L_46 , V_50 ) ,
F_31 ( L_47 , V_58 ) ,
F_31 ( L_48 , V_53 ) ,
F_31 ( L_49 , V_55 ) ,
F_31 ( L_50 , V_56 ) ,
F_31 ( L_51 , V_60 ) ,
F_31 ( L_52 , V_60 ) ,
} ;
if ( V_8 == - 1 )
V_8 = strlen ( V_95 ) ;
V_97 = V_98 ;
for ( V_7 = 0 ; V_7 < sizeof( V_98 ) / sizeof( struct V_96 ) ; V_7 ++ , V_97 ++ )
{
if ( ( V_8 == V_97 -> V_8 ) && ! strncmp ( V_97 -> V_114 , V_95 , V_8 ) )
return V_97 -> V_115 ;
}
return - 1 ;
}
static T_1 * F_7 ( const char * V_1 , int V_22 , int V_26 )
{
T_1 * V_116 = NULL ;
V_79 V_117 ;
unsigned char * V_118 ;
long V_119 ;
int V_120 = 1 ;
if ( ! ( V_116 = F_27 () ) )
{
F_5 ( V_121 , V_122 ) ;
return NULL ;
}
if ( ! V_1 )
V_1 = L_53 ;
switch( V_26 )
{
case V_100 :
if ( V_1 && * V_1 )
{
F_5 ( V_121 , V_123 ) ;
goto V_124;
}
break;
case V_99 :
if ( V_22 != V_23 )
{
F_5 ( V_121 , V_125 ) ;
goto V_124;
}
V_117 . V_85 = ( char * ) V_1 ;
if ( ! F_32 ( & V_117 , & V_116 -> V_85 . boolean ) )
{
F_5 ( V_121 , V_126 ) ;
goto V_127;
}
break;
case V_101 :
case V_102 :
if ( V_22 != V_23 )
{
F_5 ( V_121 , V_128 ) ;
goto V_124;
}
if ( ! ( V_116 -> V_85 . integer = F_33 ( NULL , ( char * ) V_1 ) ) )
{
F_5 ( V_121 , V_129 ) ;
goto V_127;
}
break;
case V_103 :
if ( V_22 != V_23 )
{
F_5 ( V_121 , V_130 ) ;
goto V_124;
}
if ( ! ( V_116 -> V_85 . V_131 = F_34 ( V_1 , 0 ) ) )
{
F_5 ( V_121 , V_132 ) ;
goto V_127;
}
break;
case V_104 :
case V_105 :
if ( V_22 != V_23 )
{
F_5 ( V_121 , V_133 ) ;
goto V_124;
}
if ( ! ( V_116 -> V_85 . V_86 = F_35 () ) )
{
F_5 ( V_121 , V_122 ) ;
goto V_127;
}
if ( ! F_36 ( V_116 -> V_85 . V_86 , V_1 , - 1 ) )
{
F_5 ( V_121 , V_122 ) ;
goto V_127;
}
V_116 -> V_85 . V_86 -> type = V_26 ;
if ( ! F_37 ( V_116 -> V_85 . V_86 ) )
{
F_5 ( V_121 , V_134 ) ;
goto V_127;
}
break;
case V_109 :
case V_111 :
case V_107 :
case V_112 :
case V_108 :
case V_110 :
case V_106 :
case V_113 :
if ( V_22 == V_23 )
V_22 = V_135 ;
else if ( V_22 == V_61 )
V_22 = V_136 ;
else
{
F_5 ( V_121 , V_137 ) ;
goto V_124;
}
if ( F_38 ( & V_116 -> V_85 . V_86 , ( unsigned char * ) V_1 ,
- 1 , V_22 , F_39 ( V_26 ) ) <= 0 )
{
F_5 ( V_121 , V_122 ) ;
goto V_127;
}
break;
case V_57 :
case V_59 :
if ( ! ( V_116 -> V_85 . V_86 = F_35 () ) )
{
F_5 ( V_121 , V_122 ) ;
goto V_124;
}
if ( V_22 == V_62 )
{
if ( ! ( V_118 = F_40 ( ( char * ) V_1 , & V_119 ) ) )
{
F_5 ( V_121 , V_138 ) ;
goto V_127;
}
V_116 -> V_85 . V_86 -> V_87 = V_118 ;
V_116 -> V_85 . V_86 -> V_88 = V_119 ;
V_116 -> V_85 . V_86 -> type = V_26 ;
}
else if ( V_22 == V_23 )
F_36 ( V_116 -> V_85 . V_86 , V_1 , - 1 ) ;
else if ( ( V_22 == V_63 ) && ( V_26 == V_57 ) )
{
if ( ! F_4 ( V_1 , ',' , 1 , V_139 , V_116 -> V_85 . V_140 ) )
{
F_5 ( V_121 , V_141 ) ;
goto V_127;
}
V_120 = 0 ;
}
else
{
F_5 ( V_121 , V_142 ) ;
goto V_124;
}
if ( ( V_26 == V_57 ) && V_120 )
{
V_116 -> V_85 . V_86 -> V_143
&= ~ ( V_144 | 0x07 ) ;
V_116 -> V_85 . V_86 -> V_143
|= V_144 ;
}
break;
default:
F_5 ( V_121 , V_145 ) ;
goto V_127;
break;
}
V_116 -> type = V_26 ;
return V_116 ;
V_127:
F_17 ( 2 , L_54 , V_1 ) ;
V_124:
F_9 ( V_116 ) ;
return NULL ;
}
static int V_139 ( const char * V_39 , int V_8 , void * V_40 )
{
long V_146 ;
char * V_69 ;
if ( ! V_39 )
return 0 ;
V_146 = strtoul ( V_39 , & V_69 , 10 ) ;
if ( V_69 && * V_69 && ( V_69 != V_39 + V_8 ) )
return 0 ;
if ( V_146 < 0 )
{
F_5 ( V_147 , V_71 ) ;
return 0 ;
}
if ( ! F_41 ( V_40 , V_146 , 1 ) )
{
F_5 ( V_147 , V_122 ) ;
return 0 ;
}
return 1 ;
}
