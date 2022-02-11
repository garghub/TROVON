int F_1 ( T_1 * V_1 , int V_2 , int V_3 , unsigned char * V_4 ,
int V_5 )
{
unsigned char * V_6 , * V_7 ;
int V_8 ;
unsigned long V_9 ;
if ( V_1 -> V_10 == V_2 )
{
V_7 = ( unsigned char * ) V_1 -> V_11 -> V_12 ;
V_6 = & ( V_7 [ 4 ] ) ;
V_8 = V_1 -> V_13 -> V_14 -> V_15 ( V_1 ,
& ( V_1 -> V_16 -> V_17 ) ,
& ( V_1 -> V_16 -> V_18 ) ,
V_4 , V_5 , V_6 ) ;
V_6 += V_8 ;
V_9 = V_8 ;
#ifdef F_2
V_9 &= 0xffff ;
#endif
* ( V_7 ++ ) = V_19 ;
F_3 ( V_9 , V_7 ) ;
V_1 -> V_20 = ( int ) V_9 + 4 ;
V_1 -> V_21 = 0 ;
V_1 -> V_10 = V_3 ;
}
return ( F_4 ( V_1 , V_22 ) ) ;
}
int F_5 ( T_1 * V_1 , int V_2 , int V_3 )
{
int V_23 , V_8 , V_24 ;
long V_25 ;
unsigned char * V_6 ;
V_25 = F_6 ( V_1 ,
V_2 ,
V_3 ,
V_19 ,
64 ,
& V_24 ) ;
if ( ! V_24 ) return ( ( int ) V_25 ) ;
if ( ! V_1 -> V_16 -> V_26 )
{
V_23 = V_27 ;
F_7 ( V_28 , V_29 ) ;
goto V_30;
}
V_1 -> V_16 -> V_26 = 0 ;
V_6 = ( unsigned char * ) V_1 -> V_11 -> V_12 ;
V_8 = V_1 -> V_13 -> V_14 -> V_31 ;
if ( V_8 != V_25 )
{
V_23 = V_32 ;
F_7 ( V_28 , V_33 ) ;
goto V_30;
}
if ( memcmp ( V_6 , ( char * ) & ( V_1 -> V_16 -> V_34 . V_35 [ 0 ] ) , V_8 ) != 0 )
{
V_23 = V_36 ;
F_7 ( V_28 , V_37 ) ;
goto V_30;
}
return ( 1 ) ;
V_30:
F_8 ( V_1 , V_38 , V_23 ) ;
return ( 0 ) ;
}
int F_9 ( T_1 * V_1 , int V_2 , int V_3 )
{
unsigned char * V_6 ;
if ( V_1 -> V_10 == V_2 )
{
V_6 = ( unsigned char * ) V_1 -> V_11 -> V_12 ;
* V_6 = V_39 ;
V_1 -> V_20 = 1 ;
V_1 -> V_21 = 0 ;
V_1 -> V_10 = V_3 ;
}
return ( F_4 ( V_1 , V_40 ) ) ;
}
unsigned long F_10 ( T_1 * V_1 , T_2 * V_41 )
{
unsigned char * V_6 ;
int V_25 , V_8 ;
unsigned long V_9 = 7 ;
T_3 * V_42 ;
T_4 V_43 ;
T_5 V_44 ;
V_42 = V_1 -> V_11 ;
if ( ! F_11 ( V_42 , ( int ) ( 10 ) ) )
{
F_7 ( V_45 , V_46 ) ;
return ( 0 ) ;
}
if ( V_41 != NULL )
{
F_12 ( & V_43 , V_1 -> V_47 -> V_48 , NULL , NULL ) ;
for (; ; )
{
V_25 = F_13 ( V_41 , NULL ) ;
if ( ! F_11 ( V_42 , ( int ) ( V_25 + V_9 + 3 ) ) )
{
F_7 ( V_45 , V_46 ) ;
return ( 0 ) ;
}
V_6 = ( unsigned char * ) & ( V_42 -> V_12 [ V_9 ] ) ;
F_3 ( V_25 , V_6 ) ;
F_13 ( V_41 , & V_6 ) ;
V_9 += V_25 + 3 ;
if ( F_14 ( F_15 ( V_41 ) ,
F_16 ( V_41 ) ) == 0 ) break;
V_8 = F_17 ( & V_43 , V_49 ,
F_16 ( V_41 ) , & V_44 ) ;
if ( V_8 <= 0 ) break;
V_41 = V_44 . V_12 . V_50 ;
F_18 ( V_41 ) ;
}
F_19 ( & V_43 ) ;
}
if ( V_1 -> V_47 -> V_51 != NULL )
for ( V_8 = 0 ; V_8 < F_20 ( V_1 -> V_47 -> V_51 ) ; V_8 ++ )
{
V_41 = F_21 ( V_1 -> V_47 -> V_51 , V_8 ) ;
V_25 = F_13 ( V_41 , NULL ) ;
if ( ! F_11 ( V_42 , ( int ) ( V_25 + V_9 + 3 ) ) )
{
F_7 ( V_45 , V_46 ) ;
return ( 0 ) ;
}
V_6 = ( unsigned char * ) & ( V_42 -> V_12 [ V_9 ] ) ;
F_3 ( V_25 , V_6 ) ;
F_13 ( V_41 , & V_6 ) ;
V_9 += V_25 + 3 ;
}
V_9 -= 7 ;
V_6 = ( unsigned char * ) & ( V_42 -> V_12 [ 4 ] ) ;
F_3 ( V_9 , V_6 ) ;
V_9 += 3 ;
V_6 = ( unsigned char * ) & ( V_42 -> V_12 [ 0 ] ) ;
* ( V_6 ++ ) = V_52 ;
F_3 ( V_9 , V_6 ) ;
V_9 += 4 ;
return ( V_9 ) ;
}
long F_6 ( T_1 * V_1 , int V_53 , int V_54 , int V_55 , long V_56 , int * V_24 )
{
unsigned char * V_6 ;
unsigned long V_9 ;
long V_25 ;
int V_8 , V_23 ;
if ( V_1 -> V_16 -> V_34 . V_57 )
{
V_1 -> V_16 -> V_34 . V_57 = 0 ;
if ( ( V_55 >= 0 ) && ( V_1 -> V_16 -> V_34 . V_58 != V_55 ) )
{
V_23 = V_27 ;
F_7 ( V_59 , V_60 ) ;
goto V_30;
}
* V_24 = 1 ;
return ( ( int ) V_1 -> V_16 -> V_34 . V_61 ) ;
}
V_6 = ( unsigned char * ) V_1 -> V_11 -> V_12 ;
if ( V_1 -> V_10 == V_53 )
{
V_8 = F_22 ( V_1 , V_22 , & V_6 [ V_1 -> V_20 ] ,
4 - V_1 -> V_20 ) ;
if ( V_8 < ( 4 - V_1 -> V_20 ) )
{
* V_24 = 0 ;
return ( F_23 ( V_1 , V_8 ) ) ;
}
if ( ( V_55 >= 0 ) && ( * V_6 != V_55 ) )
{
V_23 = V_27 ;
F_7 ( V_59 , V_60 ) ;
goto V_30;
}
V_1 -> V_16 -> V_34 . V_58 = * ( V_6 ++ ) ;
F_24 ( V_6 , V_9 ) ;
if ( V_9 > ( unsigned long ) V_56 )
{
V_23 = V_62 ;
F_7 ( V_59 , V_63 ) ;
goto V_30;
}
if ( V_9 && ! F_11 ( V_1 -> V_11 , ( int ) V_9 ) )
{
F_7 ( V_59 , V_46 ) ;
goto V_64;
}
V_1 -> V_16 -> V_34 . V_61 = V_9 ;
V_1 -> V_10 = V_54 ;
V_1 -> V_20 = 0 ;
}
V_6 = ( unsigned char * ) V_1 -> V_11 -> V_12 ;
V_25 = V_1 -> V_16 -> V_34 . V_61 ;
if ( V_25 > 0 )
{
V_8 = F_22 ( V_1 , V_22 , & V_6 [ V_1 -> V_20 ] , V_25 ) ;
if ( V_8 != ( int ) V_25 )
{
* V_24 = 0 ;
return ( F_23 ( V_1 , V_8 ) ) ;
}
}
* V_24 = 1 ;
return ( V_25 ) ;
V_30:
F_8 ( V_1 , V_38 , V_23 ) ;
V_64:
* V_24 = 0 ;
return ( - 1 ) ;
}
int F_25 ( T_2 * V_41 , T_6 * V_65 )
{
T_6 * V_66 ;
int V_67 = - 1 , V_8 , V_68 ;
if ( V_65 == NULL )
V_66 = F_26 ( V_41 ) ;
else
V_66 = V_65 ;
if ( V_66 == NULL ) goto V_64;
V_8 = V_66 -> type ;
if ( V_8 == V_69 )
{
V_67 = V_70 ;
if ( V_41 != NULL )
{
V_68 = F_27 ( V_41 ) ;
}
}
else if ( V_8 == V_71 )
{
V_67 = V_72 ;
}
else if ( V_8 == V_73 )
{
if ( V_41 == NULL )
V_67 = V_74 ;
else
{
V_68 = F_28 ( V_41 ) ;
if ( V_68 == V_69 )
V_67 = V_75 ;
else if ( V_68 == V_71 )
V_67 = V_74 ;
else V_67 = - 1 ;
}
}
else
V_67 = - 1 ;
V_64:
if( ! V_65 ) F_29 ( V_66 ) ;
return ( V_67 ) ;
}
int F_30 ( long type )
{
int V_23 ;
switch( type )
{
case V_76 :
case V_77 :
V_23 = V_78 ;
break;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
V_23 = V_88 ;
break;
case V_89 :
case V_90 :
V_23 = V_36 ;
break;
case V_91 :
case V_92 :
V_23 = V_93 ;
break;
case V_94 :
V_23 = V_95 ;
break;
case V_96 :
V_23 = V_97 ;
break;
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
V_23 = V_78 ;
break;
case V_103 :
V_23 = V_104 ;
break;
default:
V_23 = V_105 ;
break;
}
return ( V_23 ) ;
}
int F_31 ( T_1 * V_1 )
{
unsigned char * V_6 ;
unsigned int V_106 ;
if ( V_1 -> V_16 -> V_107 . V_42 == NULL )
{
if ( V_1 -> V_108 & V_109 )
V_106 = V_110 ;
else
V_106 = 0 ;
if ( ( V_6 = ( unsigned char * ) Malloc ( V_111 + V_106 ) )
== NULL )
goto V_64;
V_1 -> V_16 -> V_107 . V_42 = V_6 ;
}
if ( V_1 -> V_16 -> V_112 . V_42 == NULL )
{
if ( ( V_6 = ( unsigned char * ) Malloc ( V_111 ) )
== NULL )
goto V_64;
V_1 -> V_16 -> V_112 . V_42 = V_6 ;
}
V_1 -> V_113 = & ( V_1 -> V_16 -> V_107 . V_42 [ 0 ] ) ;
return ( 1 ) ;
V_64:
F_7 ( V_114 , V_115 ) ;
return ( 0 ) ;
}
