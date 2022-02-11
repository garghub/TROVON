int F_1 ( T_1 * V_1 , int type )
{
int V_2 ;
V_2 = F_2 ( V_1 , type , & V_1 -> V_3 -> V_4 [ V_1 -> V_5 ] ,
V_1 -> V_6 ) ;
if ( V_2 < 0 ) return ( - 1 ) ;
if ( type == V_7 )
F_3 ( V_1 , ( unsigned char * ) & V_1 -> V_3 -> V_4 [ V_1 -> V_5 ] , V_2 ) ;
if ( V_2 == V_1 -> V_6 )
return ( 1 ) ;
V_1 -> V_5 += V_2 ;
V_1 -> V_6 -= V_2 ;
return ( 0 ) ;
}
int F_4 ( T_1 * V_1 , int V_8 , int V_9 , const char * V_10 , int V_11 )
{
unsigned char * V_12 , * V_13 ;
int V_14 ;
unsigned long V_15 ;
if ( V_1 -> V_16 == V_8 )
{
V_13 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
V_12 = & ( V_13 [ 4 ] ) ;
V_14 = V_1 -> V_17 -> V_18 -> V_19 ( V_1 ,
& ( V_1 -> V_20 -> V_21 ) ,
& ( V_1 -> V_20 -> V_22 ) ,
V_10 , V_11 , V_1 -> V_20 -> V_23 . V_24 ) ;
V_1 -> V_20 -> V_23 . V_25 = V_14 ;
memcpy ( V_12 , V_1 -> V_20 -> V_23 . V_24 , V_14 ) ;
V_12 += V_14 ;
V_15 = V_14 ;
#ifdef F_5
V_15 &= 0xffff ;
#endif
* ( V_13 ++ ) = V_26 ;
F_6 ( V_15 , V_13 ) ;
V_1 -> V_6 = ( int ) V_15 + 4 ;
V_1 -> V_5 = 0 ;
V_1 -> V_16 = V_9 ;
}
return ( F_1 ( V_1 , V_7 ) ) ;
}
int F_7 ( T_1 * V_1 , int V_8 , int V_9 )
{
int V_27 , V_14 , V_28 ;
long V_29 ;
unsigned char * V_12 ;
V_29 = F_8 ( V_1 ,
V_8 ,
V_9 ,
V_26 ,
64 ,
& V_28 ) ;
if ( ! V_28 ) return ( ( int ) V_29 ) ;
if ( ! V_1 -> V_20 -> V_30 )
{
V_27 = V_31 ;
F_9 ( V_32 , V_33 ) ;
goto V_34;
}
V_1 -> V_20 -> V_30 = 0 ;
V_12 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
V_14 = V_1 -> V_20 -> V_23 . V_35 ;
if ( V_14 != V_29 )
{
V_27 = V_36 ;
F_9 ( V_32 , V_37 ) ;
goto V_34;
}
if ( memcmp ( V_12 , V_1 -> V_20 -> V_23 . V_38 , V_14 ) != 0 )
{
V_27 = V_39 ;
F_9 ( V_32 , V_40 ) ;
goto V_34;
}
return ( 1 ) ;
V_34:
F_10 ( V_1 , V_41 , V_27 ) ;
return ( 0 ) ;
}
int F_11 ( T_1 * V_1 , int V_8 , int V_9 )
{
unsigned char * V_12 ;
if ( V_1 -> V_16 == V_8 )
{
V_12 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
* V_12 = V_42 ;
V_1 -> V_6 = 1 ;
V_1 -> V_5 = 0 ;
V_1 -> V_16 = V_9 ;
}
return ( F_1 ( V_1 , V_43 ) ) ;
}
unsigned long F_12 ( T_1 * V_1 , T_2 * V_44 )
{
unsigned char * V_12 ;
int V_29 , V_14 ;
unsigned long V_15 = 7 ;
T_3 * V_45 ;
T_4 V_46 ;
T_5 V_47 ;
V_45 = V_1 -> V_3 ;
if ( ! F_13 ( V_45 , ( int ) ( 10 ) ) )
{
F_9 ( V_48 , V_49 ) ;
return ( 0 ) ;
}
if ( V_44 != NULL )
{
F_14 ( & V_46 , V_1 -> V_50 -> V_51 , NULL , NULL ) ;
for (; ; )
{
V_29 = F_15 ( V_44 , NULL ) ;
if ( ! F_13 ( V_45 , ( int ) ( V_29 + V_15 + 3 ) ) )
{
F_9 ( V_48 , V_49 ) ;
return ( 0 ) ;
}
V_12 = ( unsigned char * ) & ( V_45 -> V_4 [ V_15 ] ) ;
F_6 ( V_29 , V_12 ) ;
F_15 ( V_44 , & V_12 ) ;
V_15 += V_29 + 3 ;
if ( F_16 ( F_17 ( V_44 ) ,
F_18 ( V_44 ) ) == 0 ) break;
V_14 = F_19 ( & V_46 , V_52 ,
F_18 ( V_44 ) , & V_47 ) ;
if ( V_14 <= 0 ) break;
V_44 = V_47 . V_4 . V_53 ;
F_20 ( V_44 ) ;
}
F_21 ( & V_46 ) ;
}
if ( V_1 -> V_50 -> V_54 != NULL )
for ( V_14 = 0 ; V_14 < F_22 ( V_1 -> V_50 -> V_54 ) ; V_14 ++ )
{
V_44 = F_23 ( V_1 -> V_50 -> V_54 , V_14 ) ;
V_29 = F_15 ( V_44 , NULL ) ;
if ( ! F_13 ( V_45 , ( int ) ( V_29 + V_15 + 3 ) ) )
{
F_9 ( V_48 , V_49 ) ;
return ( 0 ) ;
}
V_12 = ( unsigned char * ) & ( V_45 -> V_4 [ V_15 ] ) ;
F_6 ( V_29 , V_12 ) ;
F_15 ( V_44 , & V_12 ) ;
V_15 += V_29 + 3 ;
}
V_15 -= 7 ;
V_12 = ( unsigned char * ) & ( V_45 -> V_4 [ 4 ] ) ;
F_6 ( V_15 , V_12 ) ;
V_15 += 3 ;
V_12 = ( unsigned char * ) & ( V_45 -> V_4 [ 0 ] ) ;
* ( V_12 ++ ) = V_55 ;
F_6 ( V_15 , V_12 ) ;
V_15 += 4 ;
return ( V_15 ) ;
}
long F_8 ( T_1 * V_1 , int V_56 , int V_57 , int V_58 , long V_59 , int * V_28 )
{
unsigned char * V_12 ;
unsigned long V_15 ;
long V_29 ;
int V_14 , V_27 ;
if ( V_1 -> V_20 -> V_23 . V_60 )
{
V_1 -> V_20 -> V_23 . V_60 = 0 ;
if ( ( V_58 >= 0 ) && ( V_1 -> V_20 -> V_23 . V_61 != V_58 ) )
{
V_27 = V_31 ;
F_9 ( V_62 , V_63 ) ;
goto V_34;
}
* V_28 = 1 ;
return ( ( int ) V_1 -> V_20 -> V_23 . V_64 ) ;
}
V_12 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
if ( V_1 -> V_16 == V_56 )
{
int V_65 ;
do
{
while ( V_1 -> V_6 < 4 )
{
V_14 = F_24 ( V_1 , V_7 , & V_12 [ V_1 -> V_6 ] ,
4 - V_1 -> V_6 ) ;
if ( V_14 <= 0 )
{
V_1 -> V_66 = V_67 ;
* V_28 = 0 ;
return V_14 ;
}
V_1 -> V_6 += V_14 ;
}
V_65 = 0 ;
if ( ! V_1 -> V_68 )
if ( V_12 [ 0 ] == V_69 )
if ( V_12 [ 1 ] == 0 && V_12 [ 2 ] == 0 && V_12 [ 3 ] == 0 )
V_65 = 1 ;
}
while ( V_65 );
if ( ( V_58 >= 0 ) && ( * V_12 != V_58 ) )
{
V_27 = V_31 ;
F_9 ( V_62 , V_63 ) ;
goto V_34;
}
if ( ( V_58 < 0 ) && ( * V_12 == V_70 ) &&
( V_56 == V_71 ) &&
( V_57 == V_72 ) )
{
F_25 ( V_1 ) ;
}
F_3 ( V_1 , ( unsigned char * ) V_1 -> V_3 -> V_4 , 4 ) ;
V_1 -> V_20 -> V_23 . V_61 = * ( V_12 ++ ) ;
F_26 ( V_12 , V_15 ) ;
if ( V_15 > ( unsigned long ) V_59 )
{
V_27 = V_73 ;
F_9 ( V_62 , V_74 ) ;
goto V_34;
}
if ( V_15 && ! F_13 ( V_1 -> V_3 , ( int ) V_15 ) )
{
F_9 ( V_62 , V_49 ) ;
goto V_75;
}
V_1 -> V_20 -> V_23 . V_64 = V_15 ;
V_1 -> V_16 = V_57 ;
V_1 -> V_6 = 0 ;
}
V_12 = ( unsigned char * ) V_1 -> V_3 -> V_4 ;
V_29 = V_1 -> V_20 -> V_23 . V_64 ;
while ( V_29 > 0 )
{
V_14 = F_24 ( V_1 , V_7 , & V_12 [ V_1 -> V_6 ] , V_29 ) ;
if ( V_14 <= 0 )
{
V_1 -> V_66 = V_67 ;
* V_28 = 0 ;
return V_14 ;
}
V_1 -> V_6 += V_14 ;
V_29 -= V_14 ;
}
F_3 ( V_1 , ( unsigned char * ) V_1 -> V_3 -> V_4 , V_1 -> V_6 ) ;
* V_28 = 1 ;
return V_1 -> V_6 ;
V_34:
F_10 ( V_1 , V_41 , V_27 ) ;
V_75:
* V_28 = 0 ;
return ( - 1 ) ;
}
int F_27 ( T_2 * V_44 , T_6 * V_76 )
{
T_6 * V_77 ;
int V_2 = - 1 , V_14 , V_78 ;
if ( V_76 == NULL )
V_77 = F_28 ( V_44 ) ;
else
V_77 = V_76 ;
if ( V_77 == NULL ) goto V_75;
V_14 = V_77 -> type ;
if ( V_14 == V_79 )
{
V_2 = V_80 ;
if ( V_44 != NULL )
{
V_78 = F_29 ( V_44 ) ;
}
}
else if ( V_14 == V_81 )
{
V_2 = V_82 ;
}
else if ( V_14 == V_83 )
{
if ( V_44 == NULL )
V_2 = V_84 ;
else
{
V_78 = F_30 ( V_44 ) ;
if ( V_78 == V_79 )
V_2 = V_85 ;
else if ( V_78 == V_81 )
V_2 = V_84 ;
else V_2 = - 1 ;
}
}
else
V_2 = - 1 ;
V_75:
if( ! V_76 ) F_31 ( V_77 ) ;
return ( V_2 ) ;
}
int F_32 ( long type )
{
int V_27 ;
switch( type )
{
case V_86 :
case V_87 :
V_27 = V_88 ;
break;
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
V_27 = V_98 ;
break;
case V_99 :
case V_100 :
V_27 = V_39 ;
break;
case V_101 :
case V_102 :
V_27 = V_103 ;
break;
case V_104 :
V_27 = V_105 ;
break;
case V_106 :
V_27 = V_107 ;
break;
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
V_27 = V_88 ;
break;
case V_113 :
V_27 = V_114 ;
break;
default:
V_27 = V_115 ;
break;
}
return ( V_27 ) ;
}
int F_33 ( T_1 * V_1 )
{
unsigned char * V_12 ;
unsigned int V_116 ;
if ( V_1 -> V_20 -> V_117 . V_45 == NULL )
{
if ( V_1 -> V_118 & V_119 )
V_116 = V_120 ;
else
V_116 = 0 ;
if ( ( V_12 = Malloc ( V_121 + V_116 ) )
== NULL )
goto V_75;
V_1 -> V_20 -> V_117 . V_45 = V_12 ;
}
if ( V_1 -> V_20 -> V_122 . V_45 == NULL )
{
if ( ( V_12 = Malloc ( V_121 ) )
== NULL )
goto V_75;
V_1 -> V_20 -> V_122 . V_45 = V_12 ;
}
V_1 -> V_123 = & ( V_1 -> V_20 -> V_117 . V_45 [ 0 ] ) ;
return ( 1 ) ;
V_75:
F_9 ( V_124 , V_125 ) ;
return ( 0 ) ;
}
