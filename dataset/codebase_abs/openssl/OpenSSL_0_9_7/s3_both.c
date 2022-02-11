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
V_33 = F_8 ( V_1 ,
V_12 ,
V_13 ,
V_30 ,
64 ,
& V_32 ) ;
if ( ! V_32 ) return ( ( int ) V_33 ) ;
if ( ! V_1 -> V_24 -> V_34 )
{
V_31 = V_35 ;
F_9 ( V_36 , V_37 ) ;
goto V_38;
}
V_1 -> V_24 -> V_34 = 0 ;
V_16 = ( unsigned char * ) V_1 -> V_39 ;
V_18 = V_1 -> V_24 -> V_27 . V_40 ;
if ( V_18 != V_33 )
{
V_31 = V_41 ;
F_9 ( V_36 , V_42 ) ;
goto V_38;
}
if ( memcmp ( V_16 , V_1 -> V_24 -> V_27 . V_43 , V_18 ) != 0 )
{
V_31 = V_44 ;
F_9 ( V_36 , V_45 ) ;
goto V_38;
}
return ( 1 ) ;
V_38:
F_10 ( V_1 , V_46 , V_31 ) ;
return ( 0 ) ;
}
int F_11 ( T_1 * V_1 , int V_12 , int V_13 )
{
unsigned char * V_16 ;
if ( V_1 -> V_20 == V_12 )
{
V_16 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
* V_16 = V_47 ;
V_1 -> V_6 = 1 ;
V_1 -> V_5 = 0 ;
V_1 -> V_20 = V_13 ;
}
return ( F_1 ( V_1 , V_48 ) ) ;
}
unsigned long F_12 ( T_1 * V_1 , T_2 * V_49 )
{
unsigned char * V_16 ;
int V_33 , V_18 ;
unsigned long V_19 = 7 ;
T_3 * V_50 ;
T_4 V_51 ;
T_5 V_52 ;
V_50 = V_1 -> V_3 ;
if ( ! F_13 ( V_50 , 10 ) )
{
F_9 ( V_53 , V_54 ) ;
return ( 0 ) ;
}
if ( V_49 != NULL )
{
if( ! F_14 ( & V_51 , V_1 -> V_55 -> V_56 , NULL , NULL ) )
{
F_9 ( V_53 , V_57 ) ;
return ( 0 ) ;
}
for (; ; )
{
V_33 = F_15 ( V_49 , NULL ) ;
if ( ! F_13 ( V_50 , ( int ) ( V_33 + V_19 + 3 ) ) )
{
F_9 ( V_53 , V_54 ) ;
return ( 0 ) ;
}
V_16 = ( unsigned char * ) & ( V_50 -> V_4 [ V_19 ] ) ;
F_6 ( V_33 , V_16 ) ;
F_15 ( V_49 , & V_16 ) ;
V_19 += V_33 + 3 ;
if ( F_16 ( F_17 ( V_49 ) ,
F_18 ( V_49 ) ) == 0 ) break;
V_18 = F_19 ( & V_51 , V_58 ,
F_18 ( V_49 ) , & V_52 ) ;
if ( V_18 <= 0 ) break;
V_49 = V_52 . V_4 . V_59 ;
F_20 ( V_49 ) ;
}
F_21 ( & V_51 ) ;
}
if ( V_1 -> V_55 -> V_60 != NULL )
for ( V_18 = 0 ; V_18 < F_22 ( V_1 -> V_55 -> V_60 ) ; V_18 ++ )
{
V_49 = F_23 ( V_1 -> V_55 -> V_60 , V_18 ) ;
V_33 = F_15 ( V_49 , NULL ) ;
if ( ! F_13 ( V_50 , ( int ) ( V_33 + V_19 + 3 ) ) )
{
F_9 ( V_53 , V_54 ) ;
return ( 0 ) ;
}
V_16 = ( unsigned char * ) & ( V_50 -> V_4 [ V_19 ] ) ;
F_6 ( V_33 , V_16 ) ;
F_15 ( V_49 , & V_16 ) ;
V_19 += V_33 + 3 ;
}
V_19 -= 7 ;
V_16 = ( unsigned char * ) & ( V_50 -> V_4 [ 4 ] ) ;
F_6 ( V_19 , V_16 ) ;
V_19 += 3 ;
V_16 = ( unsigned char * ) & ( V_50 -> V_4 [ 0 ] ) ;
* ( V_16 ++ ) = V_61 ;
F_6 ( V_19 , V_16 ) ;
V_19 += 4 ;
return ( V_19 ) ;
}
long F_8 ( T_1 * V_1 , int V_62 , int V_63 , int V_64 , long V_65 , int * V_32 )
{
unsigned char * V_16 ;
unsigned long V_19 ;
long V_33 ;
int V_18 , V_31 ;
if ( V_1 -> V_24 -> V_27 . V_66 )
{
V_1 -> V_24 -> V_27 . V_66 = 0 ;
if ( ( V_64 >= 0 ) && ( V_1 -> V_24 -> V_27 . V_67 != V_64 ) )
{
V_31 = V_35 ;
F_9 ( V_68 , V_69 ) ;
goto V_38;
}
* V_32 = 1 ;
V_1 -> V_39 = V_1 -> V_3 -> V_4 + 4 ;
V_1 -> V_6 = ( int ) V_1 -> V_24 -> V_27 . V_70 ;
return V_1 -> V_6 ;
}
V_16 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
if ( V_1 -> V_20 == V_62 )
{
int V_71 ;
do
{
while ( V_1 -> V_6 < 4 )
{
V_18 = F_24 ( V_1 , V_7 , & V_16 [ V_1 -> V_6 ] ,
4 - V_1 -> V_6 , 0 ) ;
if ( V_18 <= 0 )
{
V_1 -> V_72 = V_73 ;
* V_32 = 0 ;
return V_18 ;
}
V_1 -> V_6 += V_18 ;
}
V_71 = 0 ;
if ( ! V_1 -> V_74 )
if ( V_16 [ 0 ] == V_75 )
if ( V_16 [ 1 ] == 0 && V_16 [ 2 ] == 0 && V_16 [ 3 ] == 0 )
{
V_1 -> V_6 = 0 ;
V_71 = 1 ;
if ( V_1 -> V_8 )
V_1 -> V_8 ( 0 , V_1 -> V_9 , V_7 , V_16 , 4 , V_1 , V_1 -> V_11 ) ;
}
}
while ( V_71 );
if ( ( V_64 >= 0 ) && ( * V_16 != V_64 ) )
{
V_31 = V_35 ;
F_9 ( V_68 , V_69 ) ;
goto V_38;
}
if ( ( V_64 < 0 ) && ( * V_16 == V_76 ) &&
( V_62 == V_77 ) &&
( V_63 == V_78 ) )
{
F_25 ( V_1 ) ;
}
V_1 -> V_24 -> V_27 . V_67 = * ( V_16 ++ ) ;
F_26 ( V_16 , V_19 ) ;
if ( V_19 > ( unsigned long ) V_65 )
{
V_31 = V_79 ;
F_9 ( V_68 , V_80 ) ;
goto V_38;
}
if ( V_19 > ( V_81 - 4 ) )
{
V_31 = V_79 ;
F_9 ( V_68 , V_80 ) ;
goto V_38;
}
if ( V_19 && ! F_13 ( V_1 -> V_3 , ( int ) V_19 + 4 ) )
{
F_9 ( V_68 , V_54 ) ;
goto V_82;
}
V_1 -> V_24 -> V_27 . V_70 = V_19 ;
V_1 -> V_20 = V_63 ;
V_1 -> V_39 = V_1 -> V_3 -> V_4 + 4 ;
V_1 -> V_6 = 0 ;
}
V_16 = V_1 -> V_39 ;
V_33 = V_1 -> V_24 -> V_27 . V_70 - V_1 -> V_6 ;
while ( V_33 > 0 )
{
V_18 = F_24 ( V_1 , V_7 , & V_16 [ V_1 -> V_6 ] , V_33 , 0 ) ;
if ( V_18 <= 0 )
{
V_1 -> V_72 = V_73 ;
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
V_38:
F_10 ( V_1 , V_46 , V_31 ) ;
V_82:
* V_32 = 0 ;
return ( - 1 ) ;
}
int F_27 ( T_2 * V_49 , T_6 * V_83 )
{
T_6 * V_84 ;
int V_2 = - 1 , V_18 , V_85 ;
if ( V_83 == NULL )
V_84 = F_28 ( V_49 ) ;
else
V_84 = V_83 ;
if ( V_84 == NULL ) goto V_82;
V_18 = V_84 -> type ;
if ( V_18 == V_86 )
{
V_2 = V_87 ;
if ( V_49 != NULL )
{
V_85 = F_29 ( V_49 ) ;
}
}
else if ( V_18 == V_88 )
{
V_2 = V_89 ;
}
else if ( V_18 == V_90 )
{
if ( V_49 == NULL )
V_2 = V_91 ;
else
{
V_85 = F_30 ( V_49 ) ;
if ( V_85 == V_86 )
V_2 = V_92 ;
else if ( V_85 == V_88 )
V_2 = V_91 ;
else V_2 = - 1 ;
}
}
else
V_2 = - 1 ;
V_82:
if( ! V_83 ) F_31 ( V_84 ) ;
return ( V_2 ) ;
}
int F_32 ( long type )
{
int V_31 ;
switch( type )
{
case V_93 :
case V_94 :
case V_95 :
V_31 = V_96 ;
break;
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
V_31 = V_108 ;
break;
case V_109 :
case V_110 :
V_31 = V_44 ;
break;
case V_111 :
case V_112 :
V_31 = V_113 ;
break;
case V_114 :
V_31 = V_115 ;
break;
case V_116 :
V_31 = V_117 ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_31 = V_96 ;
break;
case V_125 :
V_31 = V_126 ;
break;
case V_127 :
V_31 = V_128 ;
break;
default:
V_31 = V_129 ;
break;
}
return ( V_31 ) ;
}
int F_33 ( T_1 * V_1 )
{
unsigned char * V_16 ;
unsigned int V_130 ;
V_10 V_131 ;
if ( V_1 -> V_24 -> V_132 . V_50 == NULL )
{
if ( V_1 -> V_133 & V_134 )
V_130 = V_135 ;
else
V_130 = 0 ;
V_131 = V_136 + V_130 ;
if ( ( V_16 = F_34 ( V_131 ) ) == NULL )
goto V_82;
V_1 -> V_24 -> V_132 . V_50 = V_16 ;
V_1 -> V_24 -> V_132 . V_131 = V_131 ;
}
if ( V_1 -> V_24 -> V_137 . V_50 == NULL )
{
V_131 = V_136 ;
V_131 += V_138 + 256 ;
if ( ( V_16 = F_34 ( V_131 ) ) == NULL )
goto V_82;
V_1 -> V_24 -> V_137 . V_50 = V_16 ;
V_1 -> V_24 -> V_137 . V_131 = V_131 ;
}
V_1 -> V_139 = & ( V_1 -> V_24 -> V_132 . V_50 [ 0 ] ) ;
return ( 1 ) ;
V_82:
F_9 ( V_140 , V_141 ) ;
return ( 0 ) ;
}
