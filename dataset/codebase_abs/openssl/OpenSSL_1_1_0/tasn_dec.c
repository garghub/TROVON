unsigned long F_1 ( int V_1 )
{
if ( ( V_1 < 0 ) || ( V_1 > 30 ) )
return 0 ;
return V_2 [ V_1 ] ;
}
T_1 * F_2 ( T_1 * * V_3 ,
const unsigned char * * V_4 , long V_5 ,
const T_2 * V_6 )
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
int F_4 ( T_1 * * V_3 , const unsigned char * * V_4 , long V_5 ,
const T_2 * V_6 ,
int V_1 , int V_9 , char V_10 , T_3 * V_11 )
{
int V_12 ;
V_12 = F_5 ( V_3 , V_4 , V_5 , V_6 , V_1 , V_9 , V_10 , V_11 ) ;
if ( V_12 <= 0 )
F_6 ( V_3 , V_6 ) ;
return V_12 ;
}
static int F_5 ( T_1 * * V_3 , const unsigned char * * V_4 ,
long V_5 , const T_2 * V_6 ,
int V_1 , int V_9 , char V_10 , T_3 * V_11 )
{
const T_4 * V_13 , * V_14 = NULL ;
const T_5 * V_15 ;
const T_6 * V_16 = V_6 -> V_17 ;
T_7 * V_18 ;
const unsigned char * V_19 = NULL , * V_20 ;
unsigned char V_21 ;
char V_22 , V_23 , V_24 , V_25 ;
long V_26 ;
int V_27 ;
int V_28 ;
int V_29 = 0 ;
T_1 * * V_30 ;
if ( ! V_3 )
return 0 ;
if ( V_16 && V_16 -> V_18 )
V_18 = V_16 -> V_18 ;
else
V_18 = 0 ;
switch ( V_6 -> V_31 ) {
case V_32 :
if ( V_6 -> V_33 ) {
if ( ( V_1 != - 1 ) || V_10 ) {
F_7 ( V_34 ,
V_35 ) ;
goto V_36;
}
return F_8 ( V_3 , V_4 , V_5 ,
V_6 -> V_33 , V_10 , V_11 ) ;
}
return F_9 ( V_3 , V_4 , V_5 , V_6 ,
V_1 , V_9 , V_10 , V_11 ) ;
case V_37 :
V_19 = * V_4 ;
V_29 = F_10 ( NULL , & V_28 , & V_21 , NULL , NULL ,
& V_19 , V_5 , - 1 , 0 , 1 , V_11 ) ;
if ( ! V_29 ) {
F_7 ( V_34 , V_38 ) ;
goto V_36;
}
if ( V_21 != V_39 ) {
if ( V_10 )
return - 1 ;
F_7 ( V_34 , V_40 ) ;
goto V_36;
}
if ( ! ( F_1 ( V_28 ) & V_6 -> V_41 ) ) {
if ( V_10 )
return - 1 ;
F_7 ( V_34 , V_42 ) ;
goto V_36;
}
return F_9 ( V_3 , V_4 , V_5 , V_6 , V_28 , 0 , 0 , V_11 ) ;
case V_43 :
V_15 = V_6 -> V_17 ;
return V_15 -> V_44 ( V_3 , V_4 , V_5 , V_6 , V_1 , V_9 , V_10 , V_11 ) ;
case V_45 :
if ( V_18 && ! V_18 ( V_46 , V_3 , V_6 , NULL ) )
goto V_47;
if ( * V_3 ) {
V_27 = F_11 ( V_3 , V_6 ) ;
if ( ( V_27 >= 0 ) && ( V_27 < V_6 -> V_48 ) ) {
V_13 = V_6 -> V_33 + V_27 ;
V_30 = F_12 ( V_3 , V_13 ) ;
F_13 ( V_30 , V_13 ) ;
F_14 ( V_3 , - 1 , V_6 ) ;
}
} else if ( ! F_15 ( V_3 , V_6 ) ) {
F_7 ( V_34 , V_38 ) ;
goto V_36;
}
V_19 = * V_4 ;
for ( V_27 = 0 , V_13 = V_6 -> V_33 ; V_27 < V_6 -> V_48 ; V_27 ++ , V_13 ++ ) {
V_30 = F_12 ( V_3 , V_13 ) ;
V_29 = F_8 ( V_30 , & V_19 , V_5 , V_13 , 1 , V_11 ) ;
if ( V_29 == - 1 )
continue;
F_14 ( V_3 , V_27 , V_6 ) ;
if ( V_29 > 0 )
break;
V_14 = V_13 ;
F_7 ( V_34 , V_38 ) ;
goto V_36;
}
if ( V_27 == V_6 -> V_48 ) {
if ( V_10 ) {
F_6 ( V_3 , V_6 ) ;
return - 1 ;
}
F_7 ( V_34 , V_49 ) ;
goto V_36;
}
if ( V_18 && ! V_18 ( V_50 , V_3 , V_6 , NULL ) )
goto V_47;
* V_4 = V_19 ;
return 1 ;
case V_51 :
case V_52 :
V_19 = * V_4 ;
V_26 = V_5 ;
if ( V_1 == - 1 ) {
V_1 = V_53 ;
V_9 = V_39 ;
}
V_29 = F_10 ( & V_5 , NULL , NULL , & V_22 , & V_24 ,
& V_19 , V_5 , V_1 , V_9 , V_10 , V_11 ) ;
if ( ! V_29 ) {
F_7 ( V_34 , V_38 ) ;
goto V_36;
} else if ( V_29 == - 1 )
return - 1 ;
if ( V_16 && ( V_16 -> V_54 & V_55 ) ) {
V_5 = V_26 - ( V_19 - * V_4 ) ;
V_23 = 1 ;
}
else
V_23 = V_22 ;
if ( ! V_24 ) {
F_7 ( V_34 , V_56 ) ;
goto V_36;
}
if ( ! * V_3 && ! F_15 ( V_3 , V_6 ) ) {
F_7 ( V_34 , V_38 ) ;
goto V_36;
}
if ( V_18 && ! V_18 ( V_46 , V_3 , V_6 , NULL ) )
goto V_47;
for ( V_27 = 0 , V_13 = V_6 -> V_33 ; V_27 < V_6 -> V_48 ; V_27 ++ , V_13 ++ ) {
if ( V_13 -> V_54 & V_57 ) {
const T_4 * V_58 ;
T_1 * * V_59 ;
V_58 = F_16 ( V_3 , V_13 , 0 ) ;
if ( V_58 == NULL )
continue;
V_59 = F_12 ( V_3 , V_58 ) ;
F_13 ( V_59 , V_58 ) ;
}
}
for ( V_27 = 0 , V_13 = V_6 -> V_33 ; V_27 < V_6 -> V_48 ; V_27 ++ , V_13 ++ ) {
const T_4 * V_58 ;
T_1 * * V_59 ;
V_58 = F_16 ( V_3 , V_13 , 1 ) ;
if ( V_58 == NULL )
goto V_36;
V_59 = F_12 ( V_3 , V_58 ) ;
if ( ! V_5 )
break;
V_20 = V_19 ;
if ( F_17 ( & V_19 , V_5 ) ) {
if ( ! V_22 ) {
F_7 ( V_34 , V_60 ) ;
goto V_36;
}
V_5 -= V_19 - V_20 ;
V_22 = 0 ;
V_20 = V_19 ;
break;
}
if ( V_27 == ( V_6 -> V_48 - 1 ) )
V_25 = 0 ;
else
V_25 = ( char ) ( V_58 -> V_54 & V_61 ) ;
V_29 = F_8 ( V_59 , & V_19 , V_5 , V_58 , V_25 , V_11 ) ;
if ( ! V_29 ) {
V_14 = V_58 ;
goto V_36;
} else if ( V_29 == - 1 ) {
F_13 ( V_59 , V_58 ) ;
continue;
}
V_5 -= V_19 - V_20 ;
}
if ( V_22 && ! F_17 ( & V_19 , V_5 ) ) {
F_7 ( V_34 , V_62 ) ;
goto V_36;
}
if ( ! V_23 && V_5 ) {
F_7 ( V_34 , V_63 ) ;
goto V_36;
}
for (; V_27 < V_6 -> V_48 ; V_13 ++ , V_27 ++ ) {
const T_4 * V_58 ;
V_58 = F_16 ( V_3 , V_13 , 1 ) ;
if ( V_58 == NULL )
goto V_36;
if ( V_58 -> V_54 & V_61 ) {
T_1 * * V_59 ;
V_59 = F_12 ( V_3 , V_58 ) ;
F_13 ( V_59 , V_58 ) ;
} else {
V_14 = V_58 ;
F_7 ( V_34 , V_64 ) ;
goto V_36;
}
}
if ( ! F_18 ( V_3 , * V_4 , V_19 - * V_4 , V_6 ) )
goto V_47;
if ( V_18 && ! V_18 ( V_50 , V_3 , V_6 , NULL ) )
goto V_47;
* V_4 = V_19 ;
return 1 ;
default:
return 0 ;
}
V_47:
F_7 ( V_34 , V_65 ) ;
V_36:
if ( V_14 )
F_19 ( 4 , L_1 , V_14 -> V_66 ,
L_2 , V_6 -> V_67 ) ;
else
F_19 ( 2 , L_3 , V_6 -> V_67 ) ;
return 0 ;
}
static int F_8 ( T_1 * * V_68 ,
const unsigned char * * V_4 , long V_69 ,
const T_4 * V_13 , char V_10 ,
T_3 * V_11 )
{
int V_54 , V_9 ;
int V_29 ;
long V_5 ;
const unsigned char * V_19 , * V_20 ;
char V_70 ;
if ( ! V_68 )
return 0 ;
V_54 = V_13 -> V_54 ;
V_9 = V_54 & V_71 ;
V_19 = * V_4 ;
if ( V_54 & V_72 ) {
char V_24 ;
V_29 = F_10 ( & V_5 , NULL , NULL , & V_70 , & V_24 ,
& V_19 , V_69 , V_13 -> V_1 , V_9 , V_10 , V_11 ) ;
V_20 = V_19 ;
if ( ! V_29 ) {
F_7 ( V_73 , V_38 ) ;
return 0 ;
} else if ( V_29 == - 1 )
return - 1 ;
if ( ! V_24 ) {
F_7 ( V_73 ,
V_74 ) ;
return 0 ;
}
V_29 = F_20 ( V_68 , & V_19 , V_5 , V_13 , 0 , V_11 ) ;
if ( ! V_29 ) {
F_7 ( V_73 , V_38 ) ;
return 0 ;
}
V_5 -= V_19 - V_20 ;
if ( V_70 ) {
if ( ! F_17 ( & V_19 , V_5 ) ) {
F_7 ( V_73 , V_62 ) ;
goto V_36;
}
} else {
if ( V_5 ) {
F_7 ( V_73 ,
V_75 ) ;
goto V_36;
}
}
} else
return F_20 ( V_68 , V_4 , V_69 , V_13 , V_10 , V_11 ) ;
* V_4 = V_19 ;
return 1 ;
V_36:
return 0 ;
}
static int F_20 ( T_1 * * V_68 ,
const unsigned char * * V_4 , long V_5 ,
const T_4 * V_13 , char V_10 ,
T_3 * V_11 )
{
int V_54 , V_9 ;
int V_29 ;
T_1 * V_76 ;
const unsigned char * V_19 , * V_20 ;
if ( ! V_68 )
return 0 ;
V_54 = V_13 -> V_54 ;
V_9 = V_54 & V_71 ;
V_19 = * V_4 ;
V_20 = V_19 ;
if ( V_13 -> V_54 & V_77 ) {
V_76 = ( T_1 * ) V_68 ;
V_68 = & V_76 ;
}
if ( V_54 & V_78 ) {
int V_79 , V_80 ;
char V_81 ;
if ( V_54 & V_82 ) {
V_79 = V_13 -> V_1 ;
V_80 = V_9 ;
} else {
V_80 = V_39 ;
if ( V_54 & V_83 )
V_79 = V_84 ;
else
V_79 = V_53 ;
}
V_29 = F_10 ( & V_5 , NULL , NULL , & V_81 , NULL ,
& V_19 , V_5 , V_79 , V_80 , V_10 , V_11 ) ;
if ( ! V_29 ) {
F_7 ( V_85 , V_38 ) ;
return 0 ;
} else if ( V_29 == - 1 )
return - 1 ;
if ( ! * V_68 )
* V_68 = ( T_1 * ) F_21 () ;
else {
F_22 ( T_1 ) * V_86 = ( F_22 ( T_1 ) * ) * V_68 ;
T_1 * V_87 ;
while ( F_23 ( V_86 ) > 0 ) {
V_87 = F_24 ( V_86 ) ;
F_6 ( & V_87 , F_25 ( V_13 -> V_88 ) ) ;
}
}
if ( ! * V_68 ) {
F_7 ( V_85 , V_89 ) ;
goto V_36;
}
while ( V_5 > 0 ) {
T_1 * V_90 ;
V_20 = V_19 ;
if ( F_17 ( & V_19 , V_5 ) ) {
if ( ! V_81 ) {
F_7 ( V_85 ,
V_60 ) ;
goto V_36;
}
V_5 -= V_19 - V_20 ;
V_81 = 0 ;
break;
}
V_90 = NULL ;
if ( ! F_5 ( & V_90 , & V_19 , V_5 ,
F_25 ( V_13 -> V_88 ) , - 1 , 0 , 0 , V_11 ) ) {
F_7 ( V_85 ,
V_38 ) ;
F_26 ( V_90 , F_25 ( V_13 -> V_88 ) ) ;
goto V_36;
}
V_5 -= V_19 - V_20 ;
if ( ! F_27 ( ( F_22 ( T_1 ) * ) * V_68 , V_90 ) ) {
F_7 ( V_85 , V_89 ) ;
F_26 ( V_90 , F_25 ( V_13 -> V_88 ) ) ;
goto V_36;
}
}
if ( V_81 ) {
F_7 ( V_85 , V_62 ) ;
goto V_36;
}
} else if ( V_54 & V_82 ) {
V_29 = F_5 ( V_68 , & V_19 , V_5 ,
F_25 ( V_13 -> V_88 ) , V_13 -> V_1 , V_9 , V_10 ,
V_11 ) ;
if ( ! V_29 ) {
F_7 ( V_85 , V_38 ) ;
goto V_36;
} else if ( V_29 == - 1 )
return - 1 ;
} else {
V_29 = F_5 ( V_68 , & V_19 , V_5 , F_25 ( V_13 -> V_88 ) ,
- 1 , 0 , V_10 , V_11 ) ;
if ( ! V_29 ) {
F_7 ( V_85 , V_38 ) ;
goto V_36;
} else if ( V_29 == - 1 )
return - 1 ;
}
* V_4 = V_19 ;
return 1 ;
V_36:
return 0 ;
}
static int F_9 ( T_1 * * V_3 ,
const unsigned char * * V_4 , long V_69 ,
const T_2 * V_6 ,
int V_1 , int V_9 , char V_10 , T_3 * V_11 )
{
int V_29 = 0 , V_41 ;
long V_91 ;
char V_24 , V_92 , V_93 = 0 ;
const unsigned char * V_19 ;
T_8 V_94 = { 0 , NULL , 0 , 0 } ;
const unsigned char * V_95 = NULL ;
long V_5 ;
if ( ! V_3 ) {
F_7 ( V_96 , V_97 ) ;
return 0 ;
}
if ( V_6 -> V_31 == V_37 ) {
V_41 = V_1 ;
V_1 = - 1 ;
} else
V_41 = V_6 -> V_41 ;
if ( V_41 == V_98 ) {
unsigned char V_21 ;
if ( V_1 >= 0 ) {
F_7 ( V_96 , V_99 ) ;
return 0 ;
}
if ( V_10 ) {
F_7 ( V_96 ,
V_100 ) ;
return 0 ;
}
V_19 = * V_4 ;
V_29 = F_10 ( NULL , & V_41 , & V_21 , NULL , NULL ,
& V_19 , V_69 , - 1 , 0 , 0 , V_11 ) ;
if ( ! V_29 ) {
F_7 ( V_96 , V_38 ) ;
return 0 ;
}
if ( V_21 != V_39 )
V_41 = V_101 ;
}
if ( V_1 == - 1 ) {
V_1 = V_41 ;
V_9 = V_39 ;
}
V_19 = * V_4 ;
V_29 = F_10 ( & V_91 , NULL , NULL , & V_92 , & V_24 ,
& V_19 , V_69 , V_1 , V_9 , V_10 , V_11 ) ;
if ( ! V_29 ) {
F_7 ( V_96 , V_38 ) ;
return 0 ;
} else if ( V_29 == - 1 )
return - 1 ;
V_29 = 0 ;
if ( ( V_41 == V_53 )
|| ( V_41 == V_84 ) || ( V_41 == V_101 ) ) {
if ( V_41 == V_101 ) {
F_28 ( V_11 ) ;
}
else if ( ! V_24 ) {
F_7 ( V_96 ,
V_102 ) ;
return 0 ;
}
V_95 = * V_4 ;
if ( V_92 ) {
if ( ! F_29 ( & V_19 , V_91 , V_92 ) )
goto V_36;
V_5 = V_19 - V_95 ;
} else {
V_5 = V_19 - V_95 + V_91 ;
V_19 += V_91 ;
}
} else if ( V_24 ) {
if ( V_41 == V_103 || V_41 == V_104
|| V_41 == V_105 || V_41 == V_106
|| V_41 == V_107 ) {
F_7 ( V_96 , V_108 ) ;
return 0 ;
}
V_93 = 1 ;
if ( ! F_30 ( & V_94 , & V_19 , V_91 , V_92 , - 1 , V_39 , 0 ) ) {
goto V_36;
}
V_5 = V_94 . V_109 ;
if ( ! F_31 ( & V_94 , V_5 + 1 ) ) {
F_7 ( V_96 , V_89 ) ;
goto V_36;
}
V_94 . V_110 [ V_5 ] = 0 ;
V_95 = ( const unsigned char * ) V_94 . V_110 ;
} else {
V_95 = V_19 ;
V_5 = V_91 ;
V_19 += V_91 ;
}
if ( ! F_32 ( V_3 , V_95 , V_5 , V_41 , & V_93 , V_6 ) )
goto V_36;
* V_4 = V_19 ;
V_29 = 1 ;
V_36:
if ( V_93 )
F_33 ( V_94 . V_110 ) ;
return V_29 ;
}
static int F_32 ( T_1 * * V_3 , const unsigned char * V_95 , int V_5 ,
int V_41 , char * V_93 , const T_2 * V_6 )
{
T_1 * * V_111 = NULL ;
T_9 * V_112 ;
T_10 * V_113 = NULL ;
int V_29 = 0 ;
const T_11 * V_114 ;
T_12 * * V_115 ;
V_114 = V_6 -> V_17 ;
if ( V_114 && V_114 -> V_116 )
return V_114 -> V_116 ( V_3 , V_95 , V_5 , V_41 , V_93 , V_6 ) ;
if ( V_6 -> V_41 == V_98 ) {
if ( ! * V_3 ) {
V_113 = F_34 () ;
if ( V_113 == NULL )
goto V_36;
* V_3 = ( T_1 * ) V_113 ;
} else
V_113 = ( T_10 * ) * V_3 ;
if ( V_41 != V_113 -> type )
F_35 ( V_113 , V_41 , NULL ) ;
V_111 = V_3 ;
V_3 = & V_113 -> V_117 . V_118 ;
}
switch ( V_41 ) {
case V_105 :
if ( ! F_36 ( ( V_119 * * ) V_3 , & V_95 , V_5 ) )
goto V_36;
break;
case V_103 :
if ( V_5 ) {
F_7 ( V_120 , V_121 ) ;
goto V_36;
}
* V_3 = ( T_1 * ) 1 ;
break;
case V_104 :
if ( V_5 != 1 ) {
F_7 ( V_120 , V_122 ) ;
goto V_36;
} else {
T_13 * V_123 ;
V_123 = ( T_13 * ) V_3 ;
* V_123 = * V_95 ;
}
break;
case V_124 :
if ( ! F_37 ( ( V_125 * * ) V_3 , & V_95 , V_5 ) )
goto V_36;
break;
case V_106 :
case V_107 :
V_115 = ( T_12 * * ) V_3 ;
if ( ! F_38 ( V_115 , & V_95 , V_5 ) )
goto V_36;
( * V_115 ) -> type = V_41 | ( ( * V_115 ) -> type & V_126 ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_101 :
case V_84 :
case V_53 :
default:
if ( V_41 == V_139 && ( V_5 & 1 ) ) {
F_7 ( V_120 , V_141 ) ;
goto V_36;
}
if ( V_41 == V_138 && ( V_5 & 3 ) ) {
F_7 ( V_120 ,
V_142 ) ;
goto V_36;
}
if ( ! * V_3 ) {
V_112 = F_39 ( V_41 ) ;
if ( V_112 == NULL ) {
F_7 ( V_120 , V_89 ) ;
goto V_36;
}
* V_3 = ( T_1 * ) V_112 ;
} else {
V_112 = ( T_9 * ) * V_3 ;
V_112 -> type = V_41 ;
}
if ( * V_93 ) {
F_33 ( V_112 -> V_110 ) ;
V_112 -> V_110 = ( unsigned char * ) V_95 ;
V_112 -> V_109 = V_5 ;
* V_93 = 0 ;
} else {
if ( ! F_40 ( V_112 , V_95 , V_5 ) ) {
F_7 ( V_120 , V_89 ) ;
F_41 ( V_112 ) ;
* V_3 = NULL ;
goto V_36;
}
}
break;
}
if ( V_113 && ( V_41 == V_103 ) )
V_113 -> V_117 . V_143 = NULL ;
V_29 = 1 ;
V_36:
if ( ! V_29 ) {
F_42 ( V_113 ) ;
if ( V_111 )
* V_111 = NULL ;
}
return V_29 ;
}
static int F_29 ( const unsigned char * * V_4 , long V_5 , char V_92 )
{
T_14 V_144 ;
long V_91 ;
const unsigned char * V_19 = * V_4 , * V_20 ;
if ( V_92 == 0 ) {
* V_4 += V_5 ;
return 1 ;
}
V_144 = 1 ;
while ( V_5 > 0 ) {
if ( F_17 ( & V_19 , V_5 ) ) {
V_144 -- ;
if ( V_144 == 0 )
break;
V_5 -= 2 ;
continue;
}
V_20 = V_19 ;
if ( ! F_10 ( & V_91 , NULL , NULL , & V_92 , NULL , & V_19 , V_5 ,
- 1 , 0 , 0 , NULL ) ) {
F_7 ( V_145 , V_38 ) ;
return 0 ;
}
if ( V_92 ) {
if ( V_144 == V_146 ) {
F_7 ( V_145 , V_38 ) ;
return 0 ;
}
V_144 ++ ;
} else {
V_19 += V_91 ;
}
V_5 -= V_19 - V_20 ;
}
if ( V_144 ) {
F_7 ( V_145 , V_62 ) ;
return 0 ;
}
* V_4 = V_19 ;
return 1 ;
}
static int F_30 ( T_8 * V_94 , const unsigned char * * V_4 , long V_5 ,
char V_92 , int V_1 , int V_9 , int V_147 )
{
const unsigned char * V_19 , * V_20 ;
long V_91 ;
char V_24 , V_148 ;
V_19 = * V_4 ;
V_92 &= 1 ;
if ( ! V_94 && ! V_92 ) {
* V_4 += V_5 ;
return 1 ;
}
while ( V_5 > 0 ) {
V_20 = V_19 ;
if ( F_17 ( & V_19 , V_5 ) ) {
if ( ! V_92 ) {
F_7 ( V_149 , V_60 ) ;
return 0 ;
}
V_92 = 0 ;
break;
}
if ( ! F_10 ( & V_91 , NULL , NULL , & V_148 , & V_24 , & V_19 ,
V_5 , V_1 , V_9 , 0 , NULL ) ) {
F_7 ( V_149 , V_38 ) ;
return 0 ;
}
if ( V_24 ) {
if ( V_147 >= V_150 ) {
F_7 ( V_149 , V_151 ) ;
return 0 ;
}
if ( ! F_30 ( V_94 , & V_19 , V_91 , V_148 , V_1 , V_9 , V_147 + 1 ) )
return 0 ;
} else if ( V_91 && ! F_43 ( V_94 , & V_19 , V_91 ) )
return 0 ;
V_5 -= V_19 - V_20 ;
}
if ( V_92 ) {
F_7 ( V_149 , V_62 ) ;
return 0 ;
}
* V_4 = V_19 ;
return 1 ;
}
static int F_43 ( T_8 * V_94 , const unsigned char * * V_19 , long V_91 )
{
int V_5 ;
if ( V_94 ) {
V_5 = V_94 -> V_109 ;
if ( ! F_31 ( V_94 , V_5 + V_91 ) ) {
F_7 ( V_152 , V_89 ) ;
return 0 ;
}
memcpy ( V_94 -> V_110 + V_5 , * V_19 , V_91 ) ;
}
* V_19 += V_91 ;
return 1 ;
}
static int F_17 ( const unsigned char * * V_4 , long V_5 )
{
const unsigned char * V_19 ;
if ( V_5 < 2 )
return 0 ;
V_19 = * V_4 ;
if ( ! V_19 [ 0 ] && ! V_19 [ 1 ] ) {
* V_4 += 2 ;
return 1 ;
}
return 0 ;
}
static int F_10 ( long * V_153 , int * V_28 , unsigned char * V_21 ,
char * V_92 , char * V_24 ,
const unsigned char * * V_4 , long V_5 ,
int V_154 , int V_155 , char V_10 , T_3 * V_11 )
{
int V_27 ;
int V_156 , V_157 ;
long V_91 ;
const unsigned char * V_19 , * V_20 ;
V_19 = * V_4 ;
V_20 = V_19 ;
if ( V_11 && V_11 -> V_158 ) {
V_27 = V_11 -> V_29 ;
V_91 = V_11 -> V_91 ;
V_157 = V_11 -> V_157 ;
V_156 = V_11 -> V_156 ;
V_19 += V_11 -> V_159 ;
} else {
V_27 = F_44 ( & V_19 , & V_91 , & V_156 , & V_157 , V_5 ) ;
if ( V_11 ) {
V_11 -> V_29 = V_27 ;
V_11 -> V_91 = V_91 ;
V_11 -> V_157 = V_157 ;
V_11 -> V_156 = V_156 ;
V_11 -> V_159 = V_19 - V_20 ;
V_11 -> V_158 = 1 ;
if ( ! ( V_27 & 0x81 ) && ( ( V_91 + V_11 -> V_159 ) > V_5 ) ) {
F_7 ( V_160 , V_161 ) ;
F_28 ( V_11 ) ;
return 0 ;
}
}
}
if ( V_27 & 0x80 ) {
F_7 ( V_160 , V_162 ) ;
F_28 ( V_11 ) ;
return 0 ;
}
if ( V_154 >= 0 ) {
if ( ( V_154 != V_156 ) || ( V_155 != V_157 ) ) {
if ( V_10 )
return - 1 ;
F_28 ( V_11 ) ;
F_7 ( V_160 , V_163 ) ;
return 0 ;
}
F_28 ( V_11 ) ;
}
if ( V_27 & 1 )
V_91 = V_5 - ( V_19 - V_20 ) ;
if ( V_92 )
* V_92 = V_27 & 1 ;
if ( V_24 )
* V_24 = V_27 & V_164 ;
if ( V_153 )
* V_153 = V_91 ;
if ( V_21 )
* V_21 = V_157 ;
if ( V_28 )
* V_28 = V_156 ;
* V_4 = V_19 ;
return 1 ;
}
