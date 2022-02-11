int F_1 ( T_1 * V_1 , int type )
{
int V_2 ;
V_2 = F_2 ( V_1 , type , & V_1 -> V_3 -> V_4 [ V_1 -> V_5 ] ,
V_1 -> V_6 ) ;
if ( V_2 < 0 ) return ( - 1 ) ;
if ( type == V_7 )
F_3 ( V_1 , ( unsigned char * ) & V_1 -> V_3 -> V_4 [ V_1 -> V_5 ] , V_2 ) ;
if ( V_2 == V_1 -> V_6 )
{
if ( V_1 -> V_8 )
V_1 -> V_8 ( 1 , V_1 -> V_9 , type , V_1 -> V_3 -> V_4 , ( V_10 ) ( V_1 -> V_5 + V_1 -> V_6 ) , V_1 , V_1 -> V_11 ) ;
return ( 1 ) ;
}
V_1 -> V_5 += V_2 ;
V_1 -> V_6 -= V_2 ;
return ( 0 ) ;
}
int F_4 ( T_1 * V_1 , int V_12 , int V_13 , const char * V_14 , int V_15 )
{
unsigned char * V_16 , * V_17 ;
int V_18 ;
unsigned long V_19 ;
if ( V_1 -> V_20 == V_12 )
{
V_17 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
V_16 = & ( V_17 [ 4 ] ) ;
V_18 = V_1 -> V_21 -> V_22 -> V_23 ( V_1 ,
& ( V_1 -> V_24 -> V_25 ) ,
& ( V_1 -> V_24 -> V_26 ) ,
V_14 , V_15 , V_1 -> V_24 -> V_27 . V_28 ) ;
V_1 -> V_24 -> V_27 . V_29 = V_18 ;
memcpy ( V_16 , V_1 -> V_24 -> V_27 . V_28 , V_18 ) ;
V_16 += V_18 ;
V_19 = V_18 ;
#ifdef F_5
V_19 &= 0xffff ;
#endif
* ( V_17 ++ ) = V_30 ;
F_6 ( V_19 , V_17 ) ;
V_1 -> V_6 = ( int ) V_19 + 4 ;
V_1 -> V_5 = 0 ;
V_1 -> V_20 = V_13 ;
}
return ( F_1 ( V_1 , V_7 ) ) ;
}
int F_7 ( T_1 * V_1 , int V_12 , int V_13 )
{
int V_31 , V_18 , V_32 ;
long V_33 ;
unsigned char * V_16 ;
V_33 = V_1 -> V_21 -> V_34 ( V_1 ,
V_12 ,
V_13 ,
V_30 ,
64 ,
& V_32 ) ;
if ( ! V_32 ) return ( ( int ) V_33 ) ;
if ( ! V_1 -> V_24 -> V_35 )
{
V_31 = V_36 ;
F_8 ( V_37 , V_38 ) ;
goto V_39;
}
V_1 -> V_24 -> V_35 = 0 ;
V_16 = ( unsigned char * ) V_1 -> V_40 ;
V_18 = V_1 -> V_24 -> V_27 . V_41 ;
if ( V_18 != V_33 )
{
V_31 = V_42 ;
F_8 ( V_37 , V_43 ) ;
goto V_39;
}
if ( memcmp ( V_16 , V_1 -> V_24 -> V_27 . V_44 , V_18 ) != 0 )
{
V_31 = V_45 ;
F_8 ( V_37 , V_46 ) ;
goto V_39;
}
return ( 1 ) ;
V_39:
F_9 ( V_1 , V_47 , V_31 ) ;
return ( 0 ) ;
}
int F_10 ( T_1 * V_1 , int V_12 , int V_13 )
{
unsigned char * V_16 ;
if ( V_1 -> V_20 == V_12 )
{
V_16 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
* V_16 = V_48 ;
V_1 -> V_6 = 1 ;
V_1 -> V_5 = 0 ;
V_1 -> V_20 = V_13 ;
}
return ( F_1 ( V_1 , V_49 ) ) ;
}
unsigned long F_11 ( T_1 * V_1 , T_2 * V_50 )
{
unsigned char * V_16 ;
int V_33 , V_18 ;
unsigned long V_19 = 7 ;
T_3 * V_51 ;
T_4 V_52 ;
T_5 V_53 ;
int V_54 ;
if ( ( V_1 -> V_55 & V_56 ) || V_1 -> V_57 -> V_58 )
V_54 = 1 ;
else
V_54 = 0 ;
V_51 = V_1 -> V_3 ;
if ( ! F_12 ( V_51 , 10 ) )
{
F_8 ( V_59 , V_60 ) ;
return ( 0 ) ;
}
if ( V_50 != NULL )
{
if( ! V_54 && ! F_13 ( & V_52 , V_1 -> V_57 -> V_61 , NULL , NULL ) )
{
F_8 ( V_59 , V_62 ) ;
return ( 0 ) ;
}
for (; ; )
{
V_33 = F_14 ( V_50 , NULL ) ;
if ( ! F_12 ( V_51 , ( int ) ( V_33 + V_19 + 3 ) ) )
{
F_8 ( V_59 , V_60 ) ;
return ( 0 ) ;
}
V_16 = ( unsigned char * ) & ( V_51 -> V_4 [ V_19 ] ) ;
F_6 ( V_33 , V_16 ) ;
F_14 ( V_50 , & V_16 ) ;
V_19 += V_33 + 3 ;
if ( V_54 )
break;
if ( F_15 ( F_16 ( V_50 ) ,
F_17 ( V_50 ) ) == 0 ) break;
V_18 = F_18 ( & V_52 , V_63 ,
F_17 ( V_50 ) , & V_53 ) ;
if ( V_18 <= 0 ) break;
V_50 = V_53 . V_4 . V_64 ;
F_19 ( V_50 ) ;
}
if ( ! V_54 )
F_20 ( & V_52 ) ;
}
if ( V_1 -> V_57 -> V_58 != NULL )
for ( V_18 = 0 ; V_18 < F_21 ( V_1 -> V_57 -> V_58 ) ; V_18 ++ )
{
V_50 = F_22 ( V_1 -> V_57 -> V_58 , V_18 ) ;
V_33 = F_14 ( V_50 , NULL ) ;
if ( ! F_12 ( V_51 , ( int ) ( V_33 + V_19 + 3 ) ) )
{
F_8 ( V_59 , V_60 ) ;
return ( 0 ) ;
}
V_16 = ( unsigned char * ) & ( V_51 -> V_4 [ V_19 ] ) ;
F_6 ( V_33 , V_16 ) ;
F_14 ( V_50 , & V_16 ) ;
V_19 += V_33 + 3 ;
}
V_19 -= 7 ;
V_16 = ( unsigned char * ) & ( V_51 -> V_4 [ 4 ] ) ;
F_6 ( V_19 , V_16 ) ;
V_19 += 3 ;
V_16 = ( unsigned char * ) & ( V_51 -> V_4 [ 0 ] ) ;
* ( V_16 ++ ) = V_65 ;
F_6 ( V_19 , V_16 ) ;
V_19 += 4 ;
return ( V_19 ) ;
}
long F_23 ( T_1 * V_1 , int V_66 , int V_67 , int V_68 , long V_69 , int * V_32 )
{
unsigned char * V_16 ;
unsigned long V_19 ;
long V_33 ;
int V_18 , V_31 ;
if ( V_1 -> V_24 -> V_27 . V_70 )
{
V_1 -> V_24 -> V_27 . V_70 = 0 ;
if ( ( V_68 >= 0 ) && ( V_1 -> V_24 -> V_27 . V_71 != V_68 ) )
{
V_31 = V_36 ;
F_8 ( V_72 , V_73 ) ;
goto V_39;
}
* V_32 = 1 ;
V_1 -> V_40 = V_1 -> V_3 -> V_4 + 4 ;
V_1 -> V_6 = ( int ) V_1 -> V_24 -> V_27 . V_74 ;
return V_1 -> V_6 ;
}
V_16 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
if ( V_1 -> V_20 == V_66 )
{
int V_75 ;
do
{
while ( V_1 -> V_6 < 4 )
{
V_18 = V_1 -> V_21 -> V_76 ( V_1 , V_7 ,
& V_16 [ V_1 -> V_6 ] , 4 - V_1 -> V_6 , 0 ) ;
if ( V_18 <= 0 )
{
V_1 -> V_77 = V_78 ;
* V_32 = 0 ;
return V_18 ;
}
V_1 -> V_6 += V_18 ;
}
V_75 = 0 ;
if ( ! V_1 -> V_79 )
if ( V_16 [ 0 ] == V_80 )
if ( V_16 [ 1 ] == 0 && V_16 [ 2 ] == 0 && V_16 [ 3 ] == 0 )
{
V_1 -> V_6 = 0 ;
V_75 = 1 ;
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_1 -> V_9 , V_7 , V_16 , 4 , V_1 , V_1 -> V_11 ) ;
}
}
while ( V_75 );
if ( ( V_68 >= 0 ) && ( * V_16 != V_68 ) )
{
V_31 = V_36 ;
F_8 ( V_72 , V_73 ) ;
goto V_39;
}
if ( ( V_68 < 0 ) && ( * V_16 == V_81 ) &&
( V_66 == V_82 ) &&
( V_67 == V_83 ) )
{
F_24 ( V_1 ) ;
}
V_1 -> V_24 -> V_27 . V_71 = * ( V_16 ++ ) ;
F_25 ( V_16 , V_19 ) ;
if ( V_19 > ( unsigned long ) V_69 )
{
V_31 = V_84 ;
F_8 ( V_72 , V_85 ) ;
goto V_39;
}
if ( V_19 > ( V_86 - 4 ) )
{
V_31 = V_84 ;
F_8 ( V_72 , V_85 ) ;
goto V_39;
}
if ( V_19 && ! F_12 ( V_1 -> V_3 , ( int ) V_19 + 4 ) )
{
F_8 ( V_72 , V_60 ) ;
goto V_87;
}
V_1 -> V_24 -> V_27 . V_74 = V_19 ;
V_1 -> V_20 = V_67 ;
V_1 -> V_40 = V_1 -> V_3 -> V_4 + 4 ;
V_1 -> V_6 = 0 ;
}
V_16 = V_1 -> V_40 ;
V_33 = V_1 -> V_24 -> V_27 . V_74 - V_1 -> V_6 ;
while ( V_33 > 0 )
{
V_18 = V_1 -> V_21 -> V_76 ( V_1 , V_7 , & V_16 [ V_1 -> V_6 ] , V_33 , 0 ) ;
if ( V_18 <= 0 )
{
V_1 -> V_77 = V_78 ;
* V_32 = 0 ;
return V_18 ;
}
V_1 -> V_6 += V_18 ;
V_33 -= V_18 ;
}
F_3 ( V_1 , ( unsigned char * ) V_1 -> V_3 -> V_4 , V_1 -> V_6 + 4 ) ;
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_1 -> V_9 , V_7 , V_1 -> V_3 -> V_4 , ( V_10 ) V_1 -> V_6 + 4 , V_1 , V_1 -> V_11 ) ;
* V_32 = 1 ;
return V_1 -> V_6 ;
V_39:
F_9 ( V_1 , V_47 , V_31 ) ;
V_87:
* V_32 = 0 ;
return ( - 1 ) ;
}
int F_26 ( T_2 * V_50 , T_6 * V_88 )
{
T_6 * V_89 ;
int V_2 = - 1 , V_18 ;
if ( V_88 == NULL )
V_89 = F_27 ( V_50 ) ;
else
V_89 = V_88 ;
if ( V_89 == NULL ) goto V_87;
V_18 = V_89 -> type ;
if ( V_18 == V_90 )
{
V_2 = V_91 ;
}
else if ( V_18 == V_92 )
{
V_2 = V_93 ;
}
#ifndef F_28
else if ( V_18 == V_94 )
{
V_2 = V_95 ;
}
#endif
V_87:
if( ! V_88 ) F_29 ( V_89 ) ;
return ( V_2 ) ;
}
int F_30 ( long type )
{
int V_31 ;
switch( type )
{
case V_96 :
case V_97 :
case V_98 :
V_31 = V_99 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
V_31 = V_111 ;
break;
case V_112 :
case V_113 :
V_31 = V_45 ;
break;
case V_114 :
case V_115 :
V_31 = V_116 ;
break;
case V_117 :
V_31 = V_118 ;
break;
case V_119 :
V_31 = V_120 ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
V_31 = V_99 ;
break;
case V_128 :
V_31 = V_129 ;
break;
case V_130 :
V_31 = V_131 ;
break;
default:
V_31 = V_132 ;
break;
}
return ( V_31 ) ;
}
int F_31 ( T_1 * V_1 )
{
unsigned char * V_16 ;
unsigned int V_133 ;
V_10 V_134 ;
if ( V_1 -> V_24 -> V_135 . V_51 == NULL )
{
if ( V_1 -> V_136 & V_137 )
V_133 = V_138 ;
else
V_133 = 0 ;
V_134 = V_139 + V_133 ;
if ( ( V_16 = F_32 ( V_134 ) ) == NULL )
goto V_87;
V_1 -> V_24 -> V_135 . V_51 = V_16 ;
V_1 -> V_24 -> V_135 . V_134 = V_134 ;
}
if ( V_1 -> V_24 -> V_140 . V_51 == NULL )
{
V_134 = V_139 ;
V_134 += V_141 + 256 ;
if ( ( V_16 = F_32 ( V_134 ) ) == NULL )
goto V_87;
V_1 -> V_24 -> V_140 . V_51 = V_16 ;
V_1 -> V_24 -> V_140 . V_134 = V_134 ;
}
V_1 -> V_142 = & ( V_1 -> V_24 -> V_135 . V_51 [ 0 ] ) ;
return ( 1 ) ;
V_87:
F_8 ( V_143 , V_144 ) ;
return ( 0 ) ;
}
