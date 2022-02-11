unsigned long F_1 ( int V_1 )
{
if ( ( V_1 < 0 ) || ( V_1 > 30 ) ) return 0 ;
return V_2 [ V_1 ] ;
}
T_1 * F_2 ( T_1 * * V_3 ,
const unsigned char * * V_4 , long V_5 , const T_2 * V_6 )
{
T_3 V_7 ;
T_1 * V_8 = NULL ;
if ( ! V_3 )
V_3 = & V_8 ;
F_3 ( & V_7 ) ;
if ( F_4 ( V_3 , V_4 , V_5 , V_6 , - 1 , 0 , 0 , & V_7 ) > 0 )
return * V_3 ;
return NULL ;
}
int F_5 ( T_1 * * V_3 ,
const unsigned char * * V_4 , long V_5 , const T_4 * V_9 )
{
T_3 V_7 ;
F_3 ( & V_7 ) ;
return F_6 ( V_3 , V_4 , V_5 , V_9 , 0 , & V_7 ) ;
}
int F_4 ( T_1 * * V_3 , const unsigned char * * V_4 , long V_5 ,
const T_2 * V_6 ,
int V_1 , int V_10 , char V_11 , T_3 * V_12 )
{
const T_4 * V_9 , * V_13 = NULL ;
const T_5 * V_14 ;
const T_6 * V_15 ;
const T_7 * V_16 = V_6 -> V_17 ;
T_8 * V_18 ;
const unsigned char * V_19 = NULL , * V_20 ;
unsigned char * V_21 = NULL ;
unsigned char V_22 = 0 , V_23 ;
char V_24 , V_25 , V_26 , V_27 ;
long V_28 ;
int V_29 ;
int V_30 ;
int V_31 = 0 ;
T_1 * * V_32 , * V_8 ;
if ( ! V_3 )
return 0 ;
if ( V_16 && V_16 -> V_18 )
V_18 = V_16 -> V_18 ;
else V_18 = 0 ;
switch( V_6 -> V_33 )
{
case V_34 :
if ( V_6 -> V_35 )
{
if ( ( V_1 != - 1 ) || V_11 )
{
F_7 ( V_36 ,
V_37 ) ;
goto V_38;
}
return F_6 ( V_3 , V_4 , V_5 ,
V_6 -> V_35 , V_11 , V_12 ) ;
}
return F_8 ( V_3 , V_4 , V_5 , V_6 ,
V_1 , V_10 , V_11 , V_12 ) ;
break;
case V_39 :
V_19 = * V_4 ;
V_31 = F_9 ( NULL , & V_30 , & V_23 , NULL , NULL ,
& V_19 , V_5 , - 1 , 0 , 1 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_36 ,
V_40 ) ;
goto V_38;
}
if ( V_23 != V_41 )
{
if ( V_11 ) return - 1 ;
F_7 ( V_36 ,
V_42 ) ;
goto V_38;
}
if ( ! ( F_1 ( V_30 ) & V_6 -> V_43 ) )
{
if ( V_11 )
return - 1 ;
F_7 ( V_36 ,
V_44 ) ;
goto V_38;
}
return F_8 ( V_3 , V_4 , V_5 ,
V_6 , V_30 , 0 , 0 , V_12 ) ;
case V_45 :
V_15 = V_6 -> V_17 ;
return V_15 -> V_46 ( V_3 , V_4 , V_5 ,
V_6 , V_1 , V_10 , V_11 , V_12 ) ;
case V_47 :
V_14 = V_6 -> V_17 ;
if ( V_11 )
{
int V_48 ;
V_19 = * V_4 ;
if ( V_1 == - 1 )
V_48 = V_6 -> V_43 ;
else V_48 = V_1 ;
V_31 = F_9 ( NULL , NULL , NULL , NULL , NULL ,
& V_19 , V_5 , V_48 , V_10 , 1 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_36 ,
V_40 ) ;
goto V_38;
}
if ( V_31 == - 1 )
return - 1 ;
}
if ( V_1 != - 1 )
{
V_21 = * ( unsigned char * * ) V_4 ;
V_22 = * V_21 ;
if ( V_19 == NULL )
{
F_7 ( V_36 ,
V_40 ) ;
goto V_38;
}
* V_21 = ( unsigned char ) ( ( * V_19 & V_49 )
| V_6 -> V_43 ) ;
}
V_8 = V_14 -> V_50 ( V_3 , V_4 , V_5 ) ;
if ( V_1 != - 1 )
* V_21 = V_22 ;
if ( V_8 )
return 1 ;
F_7 ( V_36 , V_40 ) ;
goto V_38;
case V_51 :
if ( V_18 && ! V_18 ( V_52 , V_3 , V_6 , NULL ) )
goto V_53;
if ( ! * V_3 && ! F_10 ( V_3 , V_6 ) )
{
F_7 ( V_36 ,
V_40 ) ;
goto V_38;
}
V_19 = * V_4 ;
for ( V_29 = 0 , V_9 = V_6 -> V_35 ; V_29 < V_6 -> V_54 ; V_29 ++ , V_9 ++ )
{
V_32 = F_11 ( V_3 , V_9 ) ;
V_31 = F_6 ( V_32 , & V_19 , V_5 , V_9 , 1 , V_12 ) ;
if ( V_31 == - 1 )
continue;
if ( V_31 > 0 )
break;
V_13 = V_9 ;
F_7 ( V_36 ,
V_40 ) ;
goto V_38;
}
if ( V_29 == V_6 -> V_54 )
{
if ( V_11 )
{
F_12 ( V_3 , V_6 ) ;
return - 1 ;
}
F_7 ( V_36 ,
V_55 ) ;
goto V_38;
}
F_13 ( V_3 , V_29 , V_6 ) ;
* V_4 = V_19 ;
if ( V_18 && ! V_18 ( V_56 , V_3 , V_6 , NULL ) )
goto V_53;
return 1 ;
case V_57 :
case V_58 :
V_19 = * V_4 ;
V_28 = V_5 ;
if ( V_1 == - 1 )
{
V_1 = V_59 ;
V_10 = V_41 ;
}
V_31 = F_9 ( & V_5 , NULL , NULL , & V_24 , & V_26 ,
& V_19 , V_5 , V_1 , V_10 , V_11 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_36 ,
V_40 ) ;
goto V_38;
}
else if ( V_31 == - 1 )
return - 1 ;
if ( V_16 && ( V_16 -> V_60 & V_61 ) )
{
V_5 = V_28 - ( V_19 - * V_4 ) ;
V_25 = 1 ;
}
else V_25 = V_24 ;
if ( ! V_26 )
{
F_7 ( V_36 ,
V_62 ) ;
goto V_38;
}
if ( ! * V_3 && ! F_10 ( V_3 , V_6 ) )
{
F_7 ( V_36 ,
V_40 ) ;
goto V_38;
}
if ( V_18 && ! V_18 ( V_52 , V_3 , V_6 , NULL ) )
goto V_53;
for ( V_29 = 0 , V_9 = V_6 -> V_35 ; V_29 < V_6 -> V_54 ; V_29 ++ , V_9 ++ )
{
const T_4 * V_63 ;
T_1 * * V_64 ;
V_63 = F_14 ( V_3 , V_9 , 1 ) ;
if ( ! V_63 )
goto V_38;
V_64 = F_11 ( V_3 , V_63 ) ;
if ( ! V_5 )
break;
V_20 = V_19 ;
if ( F_15 ( & V_19 , V_5 ) )
{
if ( ! V_24 )
{
F_7 ( V_36 ,
V_65 ) ;
goto V_38;
}
V_5 -= V_19 - V_20 ;
V_24 = 0 ;
V_20 = V_19 ;
break;
}
if ( V_29 == ( V_6 -> V_54 - 1 ) )
V_27 = 0 ;
else V_27 = ( char ) ( V_63 -> V_60 & V_66 ) ;
V_31 = F_6 ( V_64 , & V_19 , V_5 ,
V_63 , V_27 , V_12 ) ;
if ( ! V_31 )
{
V_13 = V_63 ;
goto V_38;
}
else if ( V_31 == - 1 )
{
F_16 ( V_64 , V_63 ) ;
continue;
}
V_5 -= V_19 - V_20 ;
}
if ( V_24 && ! F_15 ( & V_19 , V_5 ) )
{
F_7 ( V_36 , V_67 ) ;
goto V_38;
}
if ( ! V_25 && V_5 )
{
F_7 ( V_36 ,
V_68 ) ;
goto V_38;
}
for (; V_29 < V_6 -> V_54 ; V_9 ++ , V_29 ++ )
{
const T_4 * V_63 ;
V_63 = F_14 ( V_3 , V_9 , 1 ) ;
if ( ! V_63 )
goto V_38;
if ( V_63 -> V_60 & V_66 )
{
T_1 * * V_64 ;
V_64 = F_11 ( V_3 , V_63 ) ;
F_16 ( V_64 , V_63 ) ;
}
else
{
V_13 = V_63 ;
F_7 ( V_36 ,
V_69 ) ;
goto V_38;
}
}
if ( ! F_17 ( V_3 , * V_4 , V_19 - * V_4 , V_6 ) )
goto V_53;
* V_4 = V_19 ;
if ( V_18 && ! V_18 ( V_56 , V_3 , V_6 , NULL ) )
goto V_53;
return 1 ;
default:
return 0 ;
}
V_53:
F_7 ( V_36 , V_70 ) ;
V_38:
F_12 ( V_3 , V_6 ) ;
if ( V_13 )
F_18 ( 4 , L_1 , V_13 -> V_71 ,
L_2 , V_6 -> V_72 ) ;
else
F_18 ( 2 , L_3 , V_6 -> V_72 ) ;
return 0 ;
}
static int F_6 ( T_1 * * V_73 ,
const unsigned char * * V_4 , long V_74 ,
const T_4 * V_9 , char V_11 ,
T_3 * V_12 )
{
int V_60 , V_10 ;
int V_31 ;
long V_5 ;
const unsigned char * V_19 , * V_20 ;
char V_75 ;
if ( ! V_73 )
return 0 ;
V_60 = V_9 -> V_60 ;
V_10 = V_60 & V_76 ;
V_19 = * V_4 ;
if ( V_60 & V_77 )
{
char V_26 ;
V_31 = F_9 ( & V_5 , NULL , NULL , & V_75 , & V_26 ,
& V_19 , V_74 , V_9 -> V_1 , V_10 , V_11 , V_12 ) ;
V_20 = V_19 ;
if ( ! V_31 )
{
F_7 ( V_78 ,
V_40 ) ;
return 0 ;
}
else if ( V_31 == - 1 )
return - 1 ;
if ( ! V_26 )
{
F_7 ( V_78 ,
V_79 ) ;
return 0 ;
}
V_31 = F_19 ( V_73 , & V_19 , V_5 , V_9 , 0 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_78 ,
V_40 ) ;
return 0 ;
}
V_5 -= V_19 - V_20 ;
if ( V_75 )
{
if ( ! F_15 ( & V_19 , V_5 ) )
{
F_7 ( V_78 ,
V_67 ) ;
goto V_38;
}
}
else
{
if ( V_5 )
{
F_7 ( V_78 ,
V_80 ) ;
goto V_38;
}
}
}
else
return F_19 ( V_73 , V_4 , V_74 ,
V_9 , V_11 , V_12 ) ;
* V_4 = V_19 ;
return 1 ;
V_38:
F_16 ( V_73 , V_9 ) ;
return 0 ;
}
static int F_19 ( T_1 * * V_73 ,
const unsigned char * * V_4 , long V_5 ,
const T_4 * V_9 , char V_11 ,
T_3 * V_12 )
{
int V_60 , V_10 ;
int V_31 ;
const unsigned char * V_19 , * V_20 ;
if ( ! V_73 )
return 0 ;
V_60 = V_9 -> V_60 ;
V_10 = V_60 & V_76 ;
V_19 = * V_4 ;
V_20 = V_19 ;
if ( V_60 & V_81 )
{
int V_82 , V_83 ;
char V_84 ;
if ( V_60 & V_85 )
{
V_82 = V_9 -> V_1 ;
V_83 = V_10 ;
}
else
{
V_83 = V_41 ;
if ( V_60 & V_86 )
V_82 = V_87 ;
else
V_82 = V_59 ;
}
V_31 = F_9 ( & V_5 , NULL , NULL , & V_84 , NULL ,
& V_19 , V_5 , V_82 , V_83 , V_11 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_88 ,
V_40 ) ;
return 0 ;
}
else if ( V_31 == - 1 )
return - 1 ;
if ( ! * V_73 )
* V_73 = ( T_1 * ) F_20 () ;
else
{
F_21 ( T_1 ) * V_89
= ( F_21 ( T_1 ) * ) * V_73 ;
T_1 * V_90 ;
while( F_22 ( V_89 ) > 0 )
{
V_90 = F_23 ( V_89 ) ;
F_12 ( & V_90 ,
F_24 ( V_9 -> V_91 ) ) ;
}
}
if ( ! * V_73 )
{
F_7 ( V_88 ,
V_92 ) ;
goto V_38;
}
while( V_5 > 0 )
{
T_1 * V_93 ;
V_20 = V_19 ;
if ( F_15 ( & V_19 , V_5 ) )
{
if ( ! V_84 )
{
F_7 ( V_88 ,
V_65 ) ;
goto V_38;
}
V_5 -= V_19 - V_20 ;
V_84 = 0 ;
break;
}
V_93 = NULL ;
if ( ! F_4 ( & V_93 , & V_19 , V_5 ,
F_24 ( V_9 -> V_91 ) ,
- 1 , 0 , 0 , V_12 ) )
{
F_7 ( V_88 ,
V_40 ) ;
goto V_38;
}
V_5 -= V_19 - V_20 ;
if ( ! F_25 ( ( F_21 ( T_1 ) * ) * V_73 ,
V_93 ) )
{
F_7 ( V_88 ,
V_92 ) ;
goto V_38;
}
}
if ( V_84 )
{
F_7 ( V_88 , V_67 ) ;
goto V_38;
}
}
else if ( V_60 & V_85 )
{
V_31 = F_4 ( V_73 , & V_19 , V_5 ,
F_24 ( V_9 -> V_91 ) , V_9 -> V_1 , V_10 , V_11 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_88 ,
V_40 ) ;
goto V_38;
}
else if ( V_31 == - 1 )
return - 1 ;
}
else
{
V_31 = F_4 ( V_73 , & V_19 , V_5 , F_24 ( V_9 -> V_91 ) ,
- 1 , 0 , V_11 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_88 ,
V_40 ) ;
goto V_38;
}
else if ( V_31 == - 1 )
return - 1 ;
}
* V_4 = V_19 ;
return 1 ;
V_38:
F_16 ( V_73 , V_9 ) ;
return 0 ;
}
static int F_8 ( T_1 * * V_3 ,
const unsigned char * * V_4 , long V_74 ,
const T_2 * V_6 ,
int V_1 , int V_10 , char V_11 , T_3 * V_12 )
{
int V_31 = 0 , V_43 ;
long V_94 ;
char V_26 , V_95 , V_96 = 0 ;
const unsigned char * V_19 ;
T_9 V_97 ;
const unsigned char * V_98 = NULL ;
long V_5 ;
if ( ! V_3 )
{
F_7 ( V_99 , V_100 ) ;
return 0 ;
}
if ( V_6 -> V_33 == V_39 )
{
V_43 = V_1 ;
V_1 = - 1 ;
}
else
V_43 = V_6 -> V_43 ;
if ( V_43 == V_101 )
{
unsigned char V_23 ;
if ( V_1 >= 0 )
{
F_7 ( V_99 ,
V_102 ) ;
return 0 ;
}
if ( V_11 )
{
F_7 ( V_99 ,
V_103 ) ;
return 0 ;
}
V_19 = * V_4 ;
V_31 = F_9 ( NULL , & V_43 , & V_23 , NULL , NULL ,
& V_19 , V_74 , - 1 , 0 , 0 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_99 ,
V_40 ) ;
return 0 ;
}
if ( V_23 != V_41 )
V_43 = V_104 ;
}
if ( V_1 == - 1 )
{
V_1 = V_43 ;
V_10 = V_41 ;
}
V_19 = * V_4 ;
V_31 = F_9 ( & V_94 , NULL , NULL , & V_95 , & V_26 ,
& V_19 , V_74 , V_1 , V_10 , V_11 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_99 , V_40 ) ;
return 0 ;
}
else if ( V_31 == - 1 )
return - 1 ;
V_31 = 0 ;
if ( ( V_43 == V_59 )
|| ( V_43 == V_87 ) || ( V_43 == V_104 ) )
{
if ( V_43 == V_104 )
{
F_26 ( V_12 ) ;
}
else if ( ! V_26 )
{
F_7 ( V_99 ,
V_105 ) ;
return 0 ;
}
V_98 = * V_4 ;
if ( V_95 )
{
if ( ! F_27 ( & V_19 , V_94 , V_95 ) )
goto V_38;
V_5 = V_19 - V_98 ;
}
else
{
V_5 = V_19 - V_98 + V_94 ;
V_19 += V_94 ;
V_97 . V_106 = NULL ;
}
}
else if ( V_26 )
{
V_97 . V_107 = 0 ;
V_97 . V_108 = 0 ;
V_97 . V_106 = NULL ;
if ( ! F_28 ( & V_97 , & V_19 , V_94 , V_95 , - 1 , V_41 , 0 ) )
{
V_96 = 1 ;
goto V_38;
}
V_5 = V_97 . V_107 ;
if ( ! F_29 ( & V_97 , V_5 + 1 ) )
{
F_7 ( V_99 ,
V_92 ) ;
return 0 ;
}
V_97 . V_106 [ V_5 ] = 0 ;
V_98 = ( const unsigned char * ) V_97 . V_106 ;
V_96 = 1 ;
}
else
{
V_98 = V_19 ;
V_5 = V_94 ;
V_19 += V_94 ;
}
if ( ! F_30 ( V_3 , V_98 , V_5 , V_43 , & V_96 , V_6 ) )
goto V_38;
* V_4 = V_19 ;
V_31 = 1 ;
V_38:
if ( V_96 && V_97 . V_106 ) F_31 ( V_97 . V_106 ) ;
return V_31 ;
}
int F_30 ( T_1 * * V_3 , const unsigned char * V_98 , int V_5 ,
int V_43 , char * V_96 , const T_2 * V_6 )
{
T_1 * * V_109 = NULL ;
T_10 * V_110 ;
T_11 * V_111 = NULL ;
int V_31 = 0 ;
const T_12 * V_112 ;
T_13 * * V_113 ;
V_112 = V_6 -> V_17 ;
if ( V_112 && V_112 -> V_114 )
return V_112 -> V_114 ( V_3 , V_98 , V_5 , V_43 , V_96 , V_6 ) ;
if ( V_6 -> V_43 == V_101 )
{
if ( ! * V_3 )
{
V_111 = F_32 () ;
if ( V_111 == NULL )
goto V_38;
* V_3 = ( T_1 * ) V_111 ;
}
else
V_111 = ( T_11 * ) * V_3 ;
if ( V_43 != V_111 -> type )
F_33 ( V_111 , V_43 , NULL ) ;
V_109 = V_3 ;
V_3 = & V_111 -> V_115 . V_116 ;
}
switch( V_43 )
{
case V_117 :
if ( ! F_34 ( ( V_118 * * ) V_3 , & V_98 , V_5 ) )
goto V_38;
break;
case V_119 :
if ( V_5 )
{
F_7 ( V_120 ,
V_121 ) ;
goto V_38;
}
* V_3 = ( T_1 * ) 1 ;
break;
case V_122 :
if ( V_5 != 1 )
{
F_7 ( V_120 ,
V_123 ) ;
goto V_38;
}
else
{
T_14 * V_124 ;
V_124 = ( T_14 * ) V_3 ;
* V_124 = * V_98 ;
}
break;
case V_125 :
if ( ! F_35 ( ( V_126 * * ) V_3 , & V_98 , V_5 ) )
goto V_38;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
V_113 = ( T_13 * * ) V_3 ;
if ( ! F_36 ( V_113 , & V_98 , V_5 ) )
goto V_38;
( * V_113 ) -> type = V_43 | ( ( * V_113 ) -> type & V_131 ) ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_104 :
case V_87 :
case V_59 :
default:
if ( V_43 == V_144 && ( V_5 & 1 ) )
{
F_7 ( V_120 ,
V_146 ) ;
goto V_38;
}
if ( V_43 == V_143 && ( V_5 & 3 ) )
{
F_7 ( V_120 ,
V_147 ) ;
goto V_38;
}
if ( ! * V_3 )
{
V_110 = F_37 ( V_43 ) ;
if ( ! V_110 )
{
F_7 ( V_120 ,
V_92 ) ;
goto V_38;
}
* V_3 = ( T_1 * ) V_110 ;
}
else
{
V_110 = ( T_10 * ) * V_3 ;
V_110 -> type = V_43 ;
}
if ( * V_96 )
{
if ( V_110 -> V_106 )
F_31 ( V_110 -> V_106 ) ;
V_110 -> V_106 = ( unsigned char * ) V_98 ;
V_110 -> V_107 = V_5 ;
* V_96 = 0 ;
}
else
{
if ( ! F_38 ( V_110 , V_98 , V_5 ) )
{
F_7 ( V_120 ,
V_92 ) ;
F_39 ( V_110 ) ;
* V_3 = NULL ;
goto V_38;
}
}
break;
}
if ( V_111 && ( V_43 == V_119 ) )
V_111 -> V_115 . V_148 = NULL ;
V_31 = 1 ;
V_38:
if ( ! V_31 )
{
F_40 ( V_111 ) ;
if ( V_109 )
* V_109 = NULL ;
}
return V_31 ;
}
static int F_27 ( const unsigned char * * V_4 , long V_5 , char V_95 )
{
int V_149 ;
long V_94 ;
const unsigned char * V_19 = * V_4 , * V_20 ;
if ( V_95 == 0 )
{
* V_4 += V_5 ;
return 1 ;
}
V_149 = 1 ;
while ( V_5 > 0 )
{
if( F_15 ( & V_19 , V_5 ) )
{
V_149 -- ;
if ( V_149 == 0 )
break;
V_5 -= 2 ;
continue;
}
V_20 = V_19 ;
if( ! F_9 ( & V_94 , NULL , NULL , & V_95 , NULL , & V_19 , V_5 ,
- 1 , 0 , 0 , NULL ) )
{
F_7 ( V_150 , V_40 ) ;
return 0 ;
}
if ( V_95 )
V_149 ++ ;
else
V_19 += V_94 ;
V_5 -= V_19 - V_20 ;
}
if ( V_149 )
{
F_7 ( V_150 , V_67 ) ;
return 0 ;
}
* V_4 = V_19 ;
return 1 ;
}
static int F_28 ( T_9 * V_97 , const unsigned char * * V_4 , long V_5 ,
char V_95 , int V_1 , int V_10 , int V_151 )
{
const unsigned char * V_19 , * V_20 ;
long V_94 ;
char V_26 , V_152 ;
V_19 = * V_4 ;
V_95 &= 1 ;
if ( ! V_97 && ! V_95 )
{
* V_4 += V_5 ;
return 1 ;
}
while( V_5 > 0 )
{
V_20 = V_19 ;
if ( F_15 ( & V_19 , V_5 ) )
{
if ( ! V_95 )
{
F_7 ( V_153 ,
V_65 ) ;
return 0 ;
}
V_95 = 0 ;
break;
}
if ( ! F_9 ( & V_94 , NULL , NULL , & V_152 , & V_26 , & V_19 ,
V_5 , V_1 , V_10 , 0 , NULL ) )
{
F_7 ( V_153 , V_40 ) ;
return 0 ;
}
if ( V_26 )
{
if ( V_151 >= V_154 )
{
F_7 ( V_153 ,
V_155 ) ;
return 0 ;
}
if ( ! F_28 ( V_97 , & V_19 , V_94 , V_152 , V_1 , V_10 ,
V_151 + 1 ) )
return 0 ;
}
else if ( V_94 && ! F_41 ( V_97 , & V_19 , V_94 ) )
return 0 ;
V_5 -= V_19 - V_20 ;
}
if ( V_95 )
{
F_7 ( V_153 , V_67 ) ;
return 0 ;
}
* V_4 = V_19 ;
return 1 ;
}
static int F_41 ( T_9 * V_97 , const unsigned char * * V_19 , long V_94 )
{
int V_5 ;
if ( V_97 )
{
V_5 = V_97 -> V_107 ;
if ( ! F_29 ( V_97 , V_5 + V_94 ) )
{
F_7 ( V_156 , V_92 ) ;
return 0 ;
}
memcpy ( V_97 -> V_106 + V_5 , * V_19 , V_94 ) ;
}
* V_19 += V_94 ;
return 1 ;
}
static int F_15 ( const unsigned char * * V_4 , long V_5 )
{
const unsigned char * V_19 ;
if ( V_5 < 2 ) return 0 ;
V_19 = * V_4 ;
if ( ! V_19 [ 0 ] && ! V_19 [ 1 ] )
{
* V_4 += 2 ;
return 1 ;
}
return 0 ;
}
static int F_9 ( long * V_157 , int * V_30 , unsigned char * V_23 ,
char * V_95 , char * V_26 ,
const unsigned char * * V_4 , long V_5 ,
int V_48 , int V_158 , char V_11 ,
T_3 * V_12 )
{
int V_29 ;
int V_159 , V_160 ;
long V_94 ;
const unsigned char * V_19 , * V_20 ;
V_19 = * V_4 ;
V_20 = V_19 ;
if ( V_12 && V_12 -> V_161 )
{
V_29 = V_12 -> V_31 ;
V_94 = V_12 -> V_94 ;
V_160 = V_12 -> V_160 ;
V_159 = V_12 -> V_159 ;
V_19 += V_12 -> V_162 ;
}
else
{
V_29 = F_42 ( & V_19 , & V_94 , & V_159 , & V_160 , V_5 ) ;
if ( V_12 )
{
V_12 -> V_31 = V_29 ;
V_12 -> V_94 = V_94 ;
V_12 -> V_160 = V_160 ;
V_12 -> V_159 = V_159 ;
V_12 -> V_162 = V_19 - V_20 ;
V_12 -> V_161 = 1 ;
if ( ! ( V_29 & 0x81 ) && ( ( V_94 + V_12 -> V_162 ) > V_5 ) )
{
F_7 ( V_163 ,
V_164 ) ;
F_26 ( V_12 ) ;
return 0 ;
}
}
}
if ( V_29 & 0x80 )
{
F_7 ( V_163 , V_165 ) ;
F_26 ( V_12 ) ;
return 0 ;
}
if ( V_48 >= 0 )
{
if ( ( V_48 != V_159 ) || ( V_158 != V_160 ) )
{
if ( V_11 ) return - 1 ;
F_26 ( V_12 ) ;
F_7 ( V_163 , V_166 ) ;
return 0 ;
}
F_26 ( V_12 ) ;
}
if ( V_29 & 1 )
V_94 = V_5 - ( V_19 - V_20 ) ;
if ( V_95 )
* V_95 = V_29 & 1 ;
if ( V_26 )
* V_26 = V_29 & V_49 ;
if ( V_157 )
* V_157 = V_94 ;
if ( V_23 )
* V_23 = V_160 ;
if ( V_30 )
* V_30 = V_159 ;
* V_4 = V_19 ;
return 1 ;
}
