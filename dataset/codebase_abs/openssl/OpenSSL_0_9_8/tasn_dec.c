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
const unsigned char * V_19 , * V_20 ;
unsigned char * V_21 = NULL ;
unsigned char V_22 = 0 , V_23 ;
char V_24 , V_25 , V_26 , V_27 ;
long V_28 ;
int V_29 ;
int V_30 ;
int V_31 = 0 ;
T_1 * V_32 , * * V_33 , * V_8 ;
if ( ! V_3 )
return 0 ;
if ( V_16 && V_16 -> V_18 )
V_18 = V_16 -> V_18 ;
else V_18 = 0 ;
switch( V_6 -> V_34 )
{
case V_35 :
if ( V_6 -> V_36 )
{
if ( ( V_1 != - 1 ) || V_11 )
{
F_7 ( V_37 ,
V_38 ) ;
goto V_39;
}
return F_6 ( V_3 , V_4 , V_5 ,
V_6 -> V_36 , V_11 , V_12 ) ;
}
return F_8 ( V_3 , V_4 , V_5 , V_6 ,
V_1 , V_10 , V_11 , V_12 ) ;
break;
case V_40 :
V_19 = * V_4 ;
V_31 = F_9 ( NULL , & V_30 , & V_23 , NULL , NULL ,
& V_19 , V_5 , - 1 , 0 , 1 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_37 ,
V_41 ) ;
goto V_39;
}
if ( V_23 != V_42 )
{
if ( V_11 ) return - 1 ;
F_7 ( V_37 ,
V_43 ) ;
goto V_39;
}
if ( ! ( F_1 ( V_30 ) & V_6 -> V_44 ) )
{
if ( V_11 )
return - 1 ;
F_7 ( V_37 ,
V_45 ) ;
goto V_39;
}
return F_8 ( V_3 , V_4 , V_5 ,
V_6 , V_30 , 0 , 0 , V_12 ) ;
case V_46 :
V_15 = V_6 -> V_17 ;
return V_15 -> V_47 ( V_3 , V_4 , V_5 ,
V_6 , V_1 , V_10 , V_11 , V_12 ) ;
case V_48 :
V_14 = V_6 -> V_17 ;
if ( V_11 )
{
int V_49 ;
V_19 = * V_4 ;
if ( V_1 == - 1 )
V_49 = V_6 -> V_44 ;
else V_49 = V_1 ;
V_31 = F_9 ( NULL , NULL , NULL , NULL , NULL ,
& V_19 , V_5 , V_49 , V_10 , 1 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_37 ,
V_41 ) ;
goto V_39;
}
if ( V_31 == - 1 )
return - 1 ;
}
if ( V_1 != - 1 )
{
V_21 = * ( unsigned char * * ) V_4 ;
V_22 = * V_21 ;
* V_21 = ( unsigned char ) ( ( * V_19 & V_50 )
| V_6 -> V_44 ) ;
}
V_8 = V_14 -> V_51 ( V_3 , V_4 , V_5 ) ;
if ( V_1 != - 1 )
* V_21 = V_22 ;
if ( V_8 )
return 1 ;
F_7 ( V_37 , V_41 ) ;
goto V_39;
case V_52 :
if ( V_18 && ! V_18 ( V_53 , V_3 , V_6 ) )
goto V_54;
if ( ! * V_3 && ! F_10 ( V_3 , V_6 ) )
{
F_7 ( V_37 ,
V_41 ) ;
goto V_39;
}
V_32 = NULL ;
V_19 = * V_4 ;
for ( V_29 = 0 , V_9 = V_6 -> V_36 ; V_29 < V_6 -> V_55 ; V_29 ++ , V_9 ++ )
{
V_33 = F_11 ( V_3 , V_9 ) ;
V_31 = F_6 ( V_33 , & V_19 , V_5 , V_9 , 1 , V_12 ) ;
if ( V_31 == - 1 )
continue;
if ( V_31 > 0 )
break;
V_13 = V_9 ;
F_7 ( V_37 ,
V_41 ) ;
goto V_39;
}
if ( V_29 == V_6 -> V_55 )
{
if ( V_11 )
{
F_12 ( V_3 , V_6 ) ;
return - 1 ;
}
F_7 ( V_37 ,
V_56 ) ;
goto V_39;
}
F_13 ( V_3 , V_29 , V_6 ) ;
* V_4 = V_19 ;
if ( V_18 && ! V_18 ( V_57 , V_3 , V_6 ) )
goto V_54;
return 1 ;
case V_58 :
case V_59 :
V_19 = * V_4 ;
V_28 = V_5 ;
if ( V_1 == - 1 )
{
V_1 = V_60 ;
V_10 = V_42 ;
}
V_31 = F_9 ( & V_5 , NULL , NULL , & V_24 , & V_26 ,
& V_19 , V_5 , V_1 , V_10 , V_11 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_37 ,
V_41 ) ;
goto V_39;
}
else if ( V_31 == - 1 )
return - 1 ;
if ( V_16 && ( V_16 -> V_61 & V_62 ) )
{
V_5 = V_28 - ( V_19 - * V_4 ) ;
V_25 = 1 ;
}
else V_25 = V_24 ;
if ( ! V_26 )
{
F_7 ( V_37 ,
V_63 ) ;
goto V_39;
}
if ( ! * V_3 && ! F_10 ( V_3 , V_6 ) )
{
F_7 ( V_37 ,
V_41 ) ;
goto V_39;
}
if ( V_18 && ! V_18 ( V_53 , V_3 , V_6 ) )
goto V_54;
for ( V_29 = 0 , V_9 = V_6 -> V_36 ; V_29 < V_6 -> V_55 ; V_29 ++ , V_9 ++ )
{
const T_4 * V_64 ;
T_1 * * V_65 ;
V_64 = F_14 ( V_3 , V_9 , 1 ) ;
if ( ! V_64 )
goto V_39;
V_65 = F_11 ( V_3 , V_64 ) ;
if ( ! V_5 )
break;
V_20 = V_19 ;
if ( F_15 ( & V_19 , V_5 ) )
{
if ( ! V_24 )
{
F_7 ( V_37 ,
V_66 ) ;
goto V_39;
}
V_5 -= V_19 - V_20 ;
V_24 = 0 ;
V_20 = V_19 ;
break;
}
if ( V_29 == ( V_6 -> V_55 - 1 ) )
V_27 = 0 ;
else V_27 = ( char ) ( V_64 -> V_61 & V_67 ) ;
V_31 = F_6 ( V_65 , & V_19 , V_5 ,
V_64 , V_27 , V_12 ) ;
if ( ! V_31 )
{
V_13 = V_64 ;
goto V_39;
}
else if ( V_31 == - 1 )
{
F_16 ( V_65 , V_64 ) ;
continue;
}
V_5 -= V_19 - V_20 ;
}
if ( V_24 && ! F_15 ( & V_19 , V_5 ) )
{
F_7 ( V_37 , V_68 ) ;
goto V_39;
}
if ( ! V_25 && V_5 )
{
F_7 ( V_37 ,
V_69 ) ;
goto V_39;
}
for (; V_29 < V_6 -> V_55 ; V_9 ++ , V_29 ++ )
{
const T_4 * V_64 ;
V_64 = F_14 ( V_3 , V_9 , 1 ) ;
if ( ! V_64 )
goto V_39;
if ( V_64 -> V_61 & V_67 )
{
T_1 * * V_65 ;
V_65 = F_11 ( V_3 , V_64 ) ;
F_16 ( V_65 , V_64 ) ;
}
else
{
V_13 = V_64 ;
F_7 ( V_37 ,
V_70 ) ;
goto V_39;
}
}
if ( ! F_17 ( V_3 , * V_4 , V_19 - * V_4 , V_6 ) )
goto V_54;
* V_4 = V_19 ;
if ( V_18 && ! V_18 ( V_57 , V_3 , V_6 ) )
goto V_54;
return 1 ;
default:
return 0 ;
}
V_54:
F_7 ( V_37 , V_71 ) ;
V_39:
F_12 ( V_3 , V_6 ) ;
if ( V_13 )
F_18 ( 4 , L_1 , V_13 -> V_72 ,
L_2 , V_6 -> V_73 ) ;
else
F_18 ( 2 , L_3 , V_6 -> V_73 ) ;
return 0 ;
}
static int F_6 ( T_1 * * V_74 ,
const unsigned char * * V_4 , long V_75 ,
const T_4 * V_9 , char V_11 ,
T_3 * V_12 )
{
int V_61 , V_10 ;
int V_31 ;
long V_5 ;
const unsigned char * V_19 , * V_20 ;
char V_76 ;
if ( ! V_74 )
return 0 ;
V_61 = V_9 -> V_61 ;
V_10 = V_61 & V_77 ;
V_19 = * V_4 ;
if ( V_61 & V_78 )
{
char V_26 ;
V_31 = F_9 ( & V_5 , NULL , NULL , & V_76 , & V_26 ,
& V_19 , V_75 , V_9 -> V_1 , V_10 , V_11 , V_12 ) ;
V_20 = V_19 ;
if ( ! V_31 )
{
F_7 ( V_79 ,
V_41 ) ;
return 0 ;
}
else if ( V_31 == - 1 )
return - 1 ;
if ( ! V_26 )
{
F_7 ( V_79 ,
V_80 ) ;
return 0 ;
}
V_31 = F_19 ( V_74 , & V_19 , V_5 , V_9 , 0 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_79 ,
V_41 ) ;
return 0 ;
}
V_5 -= V_19 - V_20 ;
if ( V_76 )
{
if ( ! F_15 ( & V_19 , V_5 ) )
{
F_7 ( V_79 ,
V_68 ) ;
goto V_39;
}
}
else
{
if ( V_5 )
{
F_7 ( V_79 ,
V_81 ) ;
goto V_39;
}
}
}
else
return F_19 ( V_74 , V_4 , V_75 ,
V_9 , V_11 , V_12 ) ;
* V_4 = V_19 ;
return 1 ;
V_39:
F_16 ( V_74 , V_9 ) ;
* V_74 = NULL ;
return 0 ;
}
static int F_19 ( T_1 * * V_74 ,
const unsigned char * * V_4 , long V_5 ,
const T_4 * V_9 , char V_11 ,
T_3 * V_12 )
{
int V_61 , V_10 ;
int V_31 ;
const unsigned char * V_19 , * V_20 ;
if ( ! V_74 )
return 0 ;
V_61 = V_9 -> V_61 ;
V_10 = V_61 & V_77 ;
V_19 = * V_4 ;
V_20 = V_19 ;
if ( V_61 & V_82 )
{
int V_83 , V_84 ;
char V_85 ;
if ( V_61 & V_86 )
{
V_83 = V_9 -> V_1 ;
V_84 = V_10 ;
}
else
{
V_84 = V_42 ;
if ( V_61 & V_87 )
V_83 = V_88 ;
else
V_83 = V_60 ;
}
V_31 = F_9 ( & V_5 , NULL , NULL , & V_85 , NULL ,
& V_19 , V_5 , V_83 , V_84 , V_11 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_89 ,
V_41 ) ;
return 0 ;
}
else if ( V_31 == - 1 )
return - 1 ;
if ( ! * V_74 )
* V_74 = ( T_1 * ) F_20 () ;
else
{
T_9 * V_90 = ( T_9 * ) * V_74 ;
T_1 * V_91 ;
while( F_21 ( V_90 ) > 0 )
{
V_91 = ( T_1 * ) F_22 ( V_90 ) ;
F_12 ( & V_91 ,
F_23 ( V_9 -> V_92 ) ) ;
}
}
if ( ! * V_74 )
{
F_7 ( V_89 ,
V_93 ) ;
goto V_39;
}
while( V_5 > 0 )
{
T_1 * V_94 ;
V_20 = V_19 ;
if ( F_15 ( & V_19 , V_5 ) )
{
if ( ! V_85 )
{
F_7 ( V_89 ,
V_66 ) ;
goto V_39;
}
V_5 -= V_19 - V_20 ;
V_85 = 0 ;
break;
}
V_94 = NULL ;
if ( ! F_4 ( & V_94 , & V_19 , V_5 ,
F_23 ( V_9 -> V_92 ) ,
- 1 , 0 , 0 , V_12 ) )
{
F_7 ( V_89 ,
V_41 ) ;
goto V_39;
}
V_5 -= V_19 - V_20 ;
if ( ! F_24 ( ( T_9 * ) * V_74 , ( char * ) V_94 ) )
{
F_7 ( V_89 ,
V_93 ) ;
goto V_39;
}
}
if ( V_85 )
{
F_7 ( V_89 , V_68 ) ;
goto V_39;
}
}
else if ( V_61 & V_86 )
{
V_31 = F_4 ( V_74 , & V_19 , V_5 ,
F_23 ( V_9 -> V_92 ) , V_9 -> V_1 , V_10 , V_11 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_89 ,
V_41 ) ;
goto V_39;
}
else if ( V_31 == - 1 )
return - 1 ;
}
else
{
V_31 = F_4 ( V_74 , & V_19 , V_5 , F_23 ( V_9 -> V_92 ) ,
- 1 , 0 , V_11 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_89 ,
V_41 ) ;
goto V_39;
}
else if ( V_31 == - 1 )
return - 1 ;
}
* V_4 = V_19 ;
return 1 ;
V_39:
F_16 ( V_74 , V_9 ) ;
* V_74 = NULL ;
return 0 ;
}
static int F_8 ( T_1 * * V_3 ,
const unsigned char * * V_4 , long V_75 ,
const T_2 * V_6 ,
int V_1 , int V_10 , char V_11 , T_3 * V_12 )
{
int V_31 = 0 , V_44 ;
long V_95 ;
char V_26 , V_96 , V_97 = 0 ;
const unsigned char * V_19 ;
T_10 V_98 ;
const unsigned char * V_99 = NULL ;
long V_5 ;
if ( ! V_3 )
{
F_7 ( V_100 , V_101 ) ;
return 0 ;
}
if ( V_6 -> V_34 == V_40 )
{
V_44 = V_1 ;
V_1 = - 1 ;
}
else
V_44 = V_6 -> V_44 ;
if ( V_44 == V_102 )
{
unsigned char V_23 ;
if ( V_1 >= 0 )
{
F_7 ( V_100 ,
V_103 ) ;
return 0 ;
}
if ( V_11 )
{
F_7 ( V_100 ,
V_104 ) ;
return 0 ;
}
V_19 = * V_4 ;
V_31 = F_9 ( NULL , & V_44 , & V_23 , NULL , NULL ,
& V_19 , V_75 , - 1 , 0 , 0 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_100 ,
V_41 ) ;
return 0 ;
}
if ( V_23 != V_42 )
V_44 = V_105 ;
}
if ( V_1 == - 1 )
{
V_1 = V_44 ;
V_10 = V_42 ;
}
V_19 = * V_4 ;
V_31 = F_9 ( & V_95 , NULL , NULL , & V_96 , & V_26 ,
& V_19 , V_75 , V_1 , V_10 , V_11 , V_12 ) ;
if ( ! V_31 )
{
F_7 ( V_100 , V_41 ) ;
return 0 ;
}
else if ( V_31 == - 1 )
return - 1 ;
if ( ( V_44 == V_60 )
|| ( V_44 == V_88 ) || ( V_44 == V_105 ) )
{
if ( V_44 == V_105 )
{
F_3 ( V_12 ) ;
}
else if ( ! V_26 )
{
F_7 ( V_100 ,
V_106 ) ;
return 0 ;
}
V_99 = * V_4 ;
if ( V_96 )
{
if ( ! F_25 ( & V_19 , V_95 , V_96 ) )
goto V_39;
V_5 = V_19 - V_99 ;
}
else
{
V_5 = V_19 - V_99 + V_95 ;
V_19 += V_95 ;
V_98 . V_107 = NULL ;
}
}
else if ( V_26 )
{
V_98 . V_108 = 0 ;
V_98 . V_109 = 0 ;
V_98 . V_107 = NULL ;
if ( ! F_26 ( & V_98 , & V_19 , V_95 , V_96 , - 1 , V_42 ) )
goto V_39;
V_5 = V_98 . V_108 ;
if ( ! F_27 ( & V_98 , V_5 + 1 ) )
{
F_7 ( V_100 ,
V_93 ) ;
return 0 ;
}
V_98 . V_107 [ V_5 ] = 0 ;
V_99 = ( const unsigned char * ) V_98 . V_107 ;
V_97 = 1 ;
}
else
{
V_99 = V_19 ;
V_5 = V_95 ;
V_19 += V_95 ;
}
if ( ! F_28 ( V_3 , V_99 , V_5 , V_44 , & V_97 , V_6 ) )
goto V_39;
* V_4 = V_19 ;
V_31 = 1 ;
V_39:
if ( V_97 && V_98 . V_107 ) F_29 ( V_98 . V_107 ) ;
return V_31 ;
}
int F_28 ( T_1 * * V_3 , const unsigned char * V_99 , int V_5 ,
int V_44 , char * V_97 , const T_2 * V_6 )
{
T_1 * * V_110 = NULL ;
T_11 * V_111 ;
T_12 * V_112 = NULL ;
int V_31 = 0 ;
const T_13 * V_113 ;
T_14 * * V_114 ;
V_113 = V_6 -> V_17 ;
if ( V_113 && V_113 -> V_115 )
return V_113 -> V_115 ( V_3 , V_99 , V_5 , V_44 , V_97 , V_6 ) ;
if ( V_6 -> V_44 == V_102 )
{
if ( ! * V_3 )
{
V_112 = F_30 () ;
* V_3 = ( T_1 * ) V_112 ;
}
else
V_112 = ( T_12 * ) * V_3 ;
if ( V_44 != V_112 -> type )
F_31 ( V_112 , V_44 , NULL ) ;
V_110 = V_3 ;
V_3 = ( T_1 * * ) & V_112 -> V_116 . V_117 ;
}
switch( V_44 )
{
case V_118 :
if ( ! F_32 ( ( V_119 * * ) V_3 , & V_99 , V_5 ) )
goto V_39;
break;
case V_120 :
if ( V_5 )
{
F_7 ( V_121 ,
V_122 ) ;
goto V_39;
}
* V_3 = ( T_1 * ) 1 ;
break;
case V_123 :
if ( V_5 != 1 )
{
F_7 ( V_121 ,
V_124 ) ;
goto V_39;
}
else
{
T_15 * V_125 ;
V_125 = ( T_15 * ) V_3 ;
* V_125 = * V_99 ;
}
break;
case V_126 :
if ( ! F_33 ( ( V_127 * * ) V_3 , & V_99 , V_5 ) )
goto V_39;
break;
case V_128 :
case V_129 :
case V_130 :
case V_131 :
V_114 = ( T_14 * * ) V_3 ;
if ( ! F_34 ( V_114 , & V_99 , V_5 ) )
goto V_39;
( * V_114 ) -> type = V_44 | ( ( * V_114 ) -> type & V_132 ) ;
break;
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
case V_146 :
case V_105 :
case V_88 :
case V_60 :
default:
if ( ! * V_3 )
{
V_111 = F_35 ( V_44 ) ;
if ( ! V_111 )
{
F_7 ( V_121 ,
V_93 ) ;
goto V_39;
}
* V_3 = ( T_1 * ) V_111 ;
}
else
{
V_111 = ( T_11 * ) * V_3 ;
V_111 -> type = V_44 ;
}
if ( * V_97 )
{
if ( V_111 -> V_107 )
F_29 ( V_111 -> V_107 ) ;
V_111 -> V_107 = ( unsigned char * ) V_99 ;
V_111 -> V_108 = V_5 ;
* V_97 = 0 ;
}
else
{
if ( ! F_36 ( V_111 , V_99 , V_5 ) )
{
F_7 ( V_121 ,
V_93 ) ;
F_37 ( V_111 ) ;
* V_3 = NULL ;
goto V_39;
}
}
break;
}
if ( V_112 && ( V_44 == V_120 ) )
V_112 -> V_116 . V_117 = NULL ;
V_31 = 1 ;
V_39:
if ( ! V_31 )
{
F_38 ( V_112 ) ;
if ( V_110 )
* V_110 = NULL ;
}
return V_31 ;
}
static int F_25 ( const unsigned char * * V_4 , long V_5 , char V_96 )
{
int V_147 ;
long V_95 ;
const unsigned char * V_19 = * V_4 , * V_20 ;
if ( V_96 == 0 )
{
* V_4 += V_5 ;
return 1 ;
}
V_147 = 1 ;
while ( V_5 > 0 )
{
if( F_15 ( & V_19 , V_5 ) )
{
V_147 -- ;
if ( V_147 == 0 )
break;
V_5 -= 2 ;
continue;
}
V_20 = V_19 ;
if( ! F_9 ( & V_95 , NULL , NULL , & V_96 , NULL , & V_19 , V_5 ,
- 1 , 0 , 0 , NULL ) )
{
F_7 ( V_148 , V_41 ) ;
return 0 ;
}
if ( V_96 )
V_147 ++ ;
else
V_19 += V_95 ;
V_5 -= V_19 - V_20 ;
}
if ( V_147 )
{
F_7 ( V_148 , V_68 ) ;
return 0 ;
}
* V_4 = V_19 ;
return 1 ;
}
static int F_26 ( T_10 * V_98 , const unsigned char * * V_4 , long V_5 ,
char V_96 , int V_1 , int V_10 )
{
const unsigned char * V_19 , * V_20 ;
long V_95 ;
char V_26 , V_149 ;
V_19 = * V_4 ;
V_96 &= 1 ;
if ( ! V_98 && ! V_96 )
{
* V_4 += V_5 ;
return 1 ;
}
while( V_5 > 0 )
{
V_20 = V_19 ;
if ( F_15 ( & V_19 , V_5 ) )
{
if ( ! V_96 )
{
F_7 ( V_150 ,
V_66 ) ;
return 0 ;
}
V_96 = 0 ;
break;
}
if ( ! F_9 ( & V_95 , NULL , NULL , & V_149 , & V_26 , & V_19 ,
V_5 , V_1 , V_10 , 0 , NULL ) )
{
F_7 ( V_150 , V_41 ) ;
return 0 ;
}
if ( V_26 )
{
#ifdef F_39
if ( ! F_26 ( V_98 , & V_19 , V_95 , V_149 , V_1 , V_10 ) )
return 0 ;
#else
F_7 ( V_150 , V_151 ) ;
return 0 ;
#endif
}
else if ( ! F_40 ( V_98 , & V_19 , V_95 ) )
return 0 ;
V_5 -= V_19 - V_20 ;
}
if ( V_96 )
{
F_7 ( V_150 , V_68 ) ;
return 0 ;
}
* V_4 = V_19 ;
return 1 ;
}
static int F_40 ( T_10 * V_98 , const unsigned char * * V_19 , long V_95 )
{
int V_5 ;
if ( V_98 )
{
V_5 = V_98 -> V_108 ;
if ( ! F_27 ( V_98 , V_5 + V_95 ) )
{
F_7 ( V_152 , V_93 ) ;
return 0 ;
}
memcpy ( V_98 -> V_107 + V_5 , * V_19 , V_95 ) ;
}
* V_19 += V_95 ;
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
static int F_9 ( long * V_153 , int * V_30 , unsigned char * V_23 ,
char * V_96 , char * V_26 ,
const unsigned char * * V_4 , long V_5 ,
int V_49 , int V_154 , char V_11 ,
T_3 * V_12 )
{
int V_29 ;
int V_155 , V_156 ;
long V_95 ;
const unsigned char * V_19 , * V_20 ;
V_19 = * V_4 ;
V_20 = V_19 ;
if ( V_12 && V_12 -> V_157 )
{
V_29 = V_12 -> V_31 ;
V_95 = V_12 -> V_95 ;
V_156 = V_12 -> V_156 ;
V_155 = V_12 -> V_155 ;
V_19 += V_12 -> V_158 ;
}
else
{
V_29 = F_41 ( & V_19 , & V_95 , & V_155 , & V_156 , V_5 ) ;
if ( V_12 )
{
V_12 -> V_31 = V_29 ;
V_12 -> V_95 = V_95 ;
V_12 -> V_156 = V_156 ;
V_12 -> V_155 = V_155 ;
V_12 -> V_158 = V_19 - V_20 ;
V_12 -> V_157 = 1 ;
if ( ! ( V_29 & 0x81 ) && ( ( V_95 + V_12 -> V_158 ) > V_5 ) )
{
F_7 ( V_159 ,
V_160 ) ;
F_3 ( V_12 ) ;
return 0 ;
}
}
}
if ( V_29 & 0x80 )
{
F_7 ( V_159 , V_161 ) ;
F_3 ( V_12 ) ;
return 0 ;
}
if ( V_49 >= 0 )
{
if ( ( V_49 != V_155 ) || ( V_154 != V_156 ) )
{
if ( V_11 ) return - 1 ;
F_3 ( V_12 ) ;
F_7 ( V_159 , V_162 ) ;
return 0 ;
}
F_3 ( V_12 ) ;
}
if ( V_29 & 1 )
V_95 = V_5 - ( V_19 - V_20 ) ;
if ( V_96 )
* V_96 = V_29 & 1 ;
if ( V_26 )
* V_26 = V_29 & V_50 ;
if ( V_153 )
* V_153 = V_95 ;
if ( V_23 )
* V_23 = V_156 ;
if ( V_30 )
* V_30 = V_155 ;
* V_4 = V_19 ;
return 1 ;
}
