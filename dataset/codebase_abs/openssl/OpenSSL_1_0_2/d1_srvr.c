static const T_1 * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return ( F_2 () ) ;
else if ( V_1 == V_3 )
return ( F_3 () ) ;
else
return ( NULL ) ;
}
int F_4 ( T_2 * V_4 )
{
T_3 * V_5 ;
unsigned long Time = ( unsigned long ) time ( NULL ) ;
void (* F_5) ( const T_2 * V_6 , int type , int V_7 ) = NULL ;
unsigned long V_8 ;
int V_9 = - 1 ;
int V_10 , V_11 , V_12 = 0 ;
int V_13 ;
#ifndef F_6
unsigned char V_14 [ 64 ] ;
char V_15 [ sizeof( V_16 ) ] ;
#endif
F_7 ( & Time , sizeof( Time ) , 0 ) ;
F_8 () ;
F_9 () ;
if ( V_4 -> V_17 != NULL )
F_5 = V_4 -> V_17 ;
else if ( V_4 -> V_18 -> V_17 != NULL )
F_5 = V_4 -> V_18 -> V_17 ;
V_13 = V_4 -> V_19 -> V_13 ;
V_4 -> V_20 ++ ;
if ( ! F_10 ( V_4 ) || F_11 ( V_4 ) )
F_12 ( V_4 ) ;
V_4 -> V_19 -> V_13 = V_13 ;
#ifndef F_6
F_13 ( F_14 ( V_4 ) , V_21 ,
V_4 -> V_20 , NULL ) ;
#endif
if ( V_4 -> V_22 == NULL ) {
F_15 ( V_23 , V_24 ) ;
return ( - 1 ) ;
}
#ifndef F_16
if ( V_4 -> V_25 ) {
F_17 ( V_4 ) ;
V_4 -> V_25 = 0 ;
V_4 -> V_26 ++ ;
}
#endif
for (; ; ) {
V_11 = V_4 -> V_11 ;
switch ( V_4 -> V_11 ) {
case V_27 :
V_4 -> V_28 = 1 ;
case V_29 :
case V_30 :
case V_29 | V_30 :
case V_31 | V_30 :
V_4 -> V_32 = 1 ;
if ( F_5 != NULL )
F_5 ( V_4 , V_33 , 1 ) ;
if ( ( V_4 -> V_34 & 0xff00 ) != ( V_2 & 0xff00 ) ) {
F_15 ( V_23 , V_35 ) ;
return - 1 ;
}
V_4 -> type = V_30 ;
if ( V_4 -> V_36 == NULL ) {
if ( ( V_5 = F_18 () ) == NULL ) {
V_9 = - 1 ;
goto V_37;
}
if ( ! F_19 ( V_5 , V_38 ) ) {
F_20 ( V_5 ) ;
V_9 = - 1 ;
goto V_37;
}
V_4 -> V_36 = V_5 ;
}
if ( ! F_21 ( V_4 ) ) {
V_9 = - 1 ;
goto V_37;
}
V_4 -> V_39 = 0 ;
V_4 -> V_19 -> V_40 = 0 ;
V_4 -> V_41 -> V_42 = 0 ;
if ( V_4 -> V_11 != V_27 ) {
#ifndef F_6
if ( ! F_22 ( F_14 ( V_4 ) ) )
#endif
if ( ! F_23 ( V_4 , 1 ) ) {
V_9 = - 1 ;
goto V_37;
}
F_24 ( V_4 ) ;
V_4 -> V_11 = V_43 ;
V_4 -> V_18 -> V_44 . V_45 ++ ;
} else {
V_4 -> V_18 -> V_44 . V_46 ++ ;
V_4 -> V_11 = V_47 ;
}
break;
case V_47 :
case V_48 :
V_4 -> V_49 = 0 ;
F_25 ( V_4 ) ;
F_26 ( V_4 ) ;
V_9 = F_27 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
V_4 -> V_41 -> V_50 . V_51 = V_43 ;
V_4 -> V_11 = V_52 ;
V_4 -> V_39 = 0 ;
F_24 ( V_4 ) ;
break;
case V_53 :
V_4 -> V_11 = V_31 ;
break;
case V_43 :
case V_54 :
case V_55 :
V_4 -> V_49 = 0 ;
V_9 = F_28 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
F_17 ( V_4 ) ;
if ( V_9 == 1 && ( F_29 ( V_4 ) & V_56 ) )
V_4 -> V_11 = V_57 ;
else
V_4 -> V_11 = V_58 ;
V_4 -> V_39 = 0 ;
if ( V_13 ) {
memcpy ( V_4 -> V_41 -> V_59 , V_4 -> V_41 -> V_60 ,
sizeof( V_4 -> V_41 -> V_59 ) ) ;
}
if ( V_13 && V_4 -> V_11 == V_58 ) {
V_9 = 2 ;
V_4 -> V_19 -> V_13 = 0 ;
V_4 -> V_19 -> V_61 = 2 ;
V_4 -> V_19 -> V_62 = 1 ;
V_4 -> V_19 -> V_63 = 1 ;
goto V_37;
}
break;
case V_57 :
case V_64 :
V_9 = F_30 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
V_4 -> V_11 = V_52 ;
V_4 -> V_41 -> V_50 . V_51 = V_43 ;
if ( V_4 -> V_34 != V_65 )
F_24 ( V_4 ) ;
break;
#ifndef F_6
case V_66 :
if ( F_31 ( F_32 ( V_4 ) ) ) {
V_4 -> V_41 -> V_67 = 2 ;
V_4 -> V_68 = V_69 ;
F_33 ( F_32 ( V_4 ) ) ;
F_34 ( F_32 ( V_4 ) ) ;
V_9 = - 1 ;
goto V_37;
}
V_4 -> V_11 = V_70 ;
break;
case V_71 :
V_9 = F_35 ( F_14 ( V_4 ) ) ;
if ( V_9 < 0 )
goto V_37;
if ( V_9 == 0 ) {
if ( V_4 -> V_19 -> V_51 != V_31 ) {
V_4 -> V_41 -> V_67 = 2 ;
V_4 -> V_68 = V_69 ;
F_33 ( F_32 ( V_4 ) ) ;
F_34 ( F_32 ( V_4 ) ) ;
V_9 = - 1 ;
goto V_37;
}
}
V_4 -> V_11 = V_4 -> V_19 -> V_51 ;
break;
#endif
case V_58 :
case V_72 :
V_4 -> V_28 = 2 ;
F_26 ( V_4 ) ;
V_9 = F_36 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
if ( V_4 -> V_73 ) {
#ifndef F_6
snprintf ( ( char * ) V_15 , sizeof( V_16 ) ,
V_16 ) ;
F_37 ( V_4 , V_14 ,
sizeof( V_14 ) , V_15 ,
sizeof( V_15 ) , NULL , 0 , 0 ) ;
F_13 ( F_14 ( V_4 ) , V_74 ,
sizeof( V_14 ) , V_14 ) ;
#endif
#ifndef F_38
if ( V_4 -> V_75 )
V_4 -> V_11 = V_76 ;
else
V_4 -> V_11 = V_77 ;
#else
V_4 -> V_11 = V_77 ;
#endif
} else
V_4 -> V_11 = V_78 ;
V_4 -> V_39 = 0 ;
break;
case V_78 :
case V_79 :
if ( ! ( V_4 -> V_41 -> V_50 . V_80 -> V_81 & V_82 )
&& ! ( V_4 -> V_41 -> V_50 . V_80 -> V_83 & V_84 ) ) {
F_26 ( V_4 ) ;
V_9 = F_39 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
#ifndef F_38
if ( V_4 -> V_85 )
V_4 -> V_11 = V_86 ;
else
V_4 -> V_11 = V_87 ;
} else {
V_12 = 1 ;
V_4 -> V_11 = V_87 ;
}
#else
} else
V_12 = 1 ;
V_4 -> V_11 = V_87 ;
#endif
V_4 -> V_39 = 0 ;
break;
case V_87 :
case V_88 :
V_8 = V_4 -> V_41 -> V_50 . V_80 -> V_83 ;
V_4 -> V_41 -> V_50 . V_89 = 0 ;
if ( 0
#ifndef F_40
|| ( ( V_8 & V_84 ) && V_4 -> V_18 -> V_90 )
#endif
|| ( V_8 & ( V_91 | V_92 | V_93 ) )
|| ( V_8 & V_94 )
|| ( ( V_8 & V_95 )
&& ( V_4 -> V_22 -> V_96 [ V_97 ] . V_98 == NULL
|| ( F_41 ( V_4 -> V_41 -> V_50 . V_80 )
&& F_42 ( V_4 -> V_22 -> V_96
[ V_97 ] . V_98 ) *
8 > F_43 ( V_4 -> V_41 -> V_50 . V_80 )
)
)
)
) {
F_26 ( V_4 ) ;
V_9 = F_44 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
} else
V_12 = 1 ;
V_4 -> V_11 = V_99 ;
V_4 -> V_39 = 0 ;
break;
case V_99 :
case V_100 :
if (
! ( V_4 -> V_101 & V_102 ) ||
( ( V_4 -> V_103 -> V_104 != NULL ) &&
( V_4 -> V_101 & V_105 ) ) ||
( ( V_4 -> V_41 -> V_50 . V_80 -> V_81 & V_82 ) &&
! ( V_4 -> V_101 & V_106 ) ) ||
( V_4 -> V_41 -> V_50 . V_80 -> V_81 & V_107 )
|| ( V_4 -> V_41 -> V_50 . V_80 -> V_83 & V_84 ) ) {
V_12 = 1 ;
V_4 -> V_41 -> V_50 . V_108 = 0 ;
V_4 -> V_11 = V_109 ;
#ifndef F_6
if ( F_22 ( F_14 ( V_4 ) ) ) {
V_4 -> V_19 -> V_51 = V_109 ;
V_4 -> V_11 = V_71 ;
}
#endif
} else {
V_4 -> V_41 -> V_50 . V_108 = 1 ;
F_26 ( V_4 ) ;
V_9 = F_45 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
#ifndef F_46
V_4 -> V_11 = V_109 ;
# ifndef F_6
if ( F_22 ( F_14 ( V_4 ) ) ) {
V_4 -> V_19 -> V_51 = V_109 ;
V_4 -> V_11 = V_71 ;
}
# endif
#else
V_4 -> V_11 = V_52 ;
V_4 -> V_41 -> V_50 . V_51 = V_110 ;
# ifndef F_6
if ( F_22 ( F_14 ( V_4 ) ) ) {
V_4 -> V_19 -> V_51 = V_4 -> V_41 -> V_50 . V_51 ;
V_4 -> V_41 -> V_50 . V_51 = V_71 ;
}
# endif
#endif
V_4 -> V_39 = 0 ;
}
break;
case V_109 :
case V_111 :
F_26 ( V_4 ) ;
V_9 = F_47 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
V_4 -> V_41 -> V_50 . V_51 = V_110 ;
V_4 -> V_11 = V_52 ;
V_4 -> V_39 = 0 ;
break;
case V_52 :
V_4 -> V_68 = V_112 ;
if ( F_48 ( V_4 -> V_113 ) <= 0 ) {
if ( ! F_49 ( V_4 -> V_113 ) ) {
V_4 -> V_68 = V_114 ;
V_4 -> V_11 = V_4 -> V_41 -> V_50 . V_51 ;
}
V_9 = - 1 ;
goto V_37;
}
V_4 -> V_68 = V_114 ;
V_4 -> V_11 = V_4 -> V_41 -> V_50 . V_51 ;
break;
case V_110 :
case V_115 :
if ( V_4 -> V_41 -> V_50 . V_108 ) {
V_9 = F_50 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
}
V_4 -> V_39 = 0 ;
V_4 -> V_11 = V_116 ;
break;
case V_116 :
case V_117 :
V_9 = F_51 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
#ifndef F_6
snprintf ( ( char * ) V_15 , sizeof( V_16 ) ,
V_16 ) ;
F_37 ( V_4 , V_14 ,
sizeof( V_14 ) , V_15 ,
sizeof( V_15 ) , NULL , 0 , 0 ) ;
F_13 ( F_14 ( V_4 ) , V_74 ,
sizeof( V_14 ) , V_14 ) ;
#endif
V_4 -> V_11 = V_118 ;
V_4 -> V_39 = 0 ;
if ( V_9 == 2 ) {
V_4 -> V_11 = V_70 ;
V_4 -> V_39 = 0 ;
} else if ( F_52 ( V_4 ) ) {
V_4 -> V_11 = V_118 ;
V_4 -> V_39 = 0 ;
if ( ! V_4 -> V_103 -> V_104 )
break;
if ( ! V_4 -> V_41 -> V_119 ) {
F_15 ( V_23 , V_35 ) ;
return - 1 ;
}
V_4 -> V_41 -> V_120 |= V_121 ;
if ( ! F_53 ( V_4 ) )
return - 1 ;
} else {
V_4 -> V_11 = V_118 ;
V_4 -> V_39 = 0 ;
V_4 -> V_122 -> V_123 -> V_124 ( V_4 ,
V_125 ,
& ( V_4 -> V_41 ->
V_50 . V_126
[ 0 ] ) ) ;
V_4 -> V_122 -> V_123 -> V_124 ( V_4 , V_127 ,
& ( V_4 -> V_41 ->
V_50 . V_126
[ V_128 ] ) ) ;
}
break;
case V_118 :
case V_129 :
if ( ! V_4 -> V_41 -> V_42 )
V_4 -> V_19 -> V_40 = 1 ;
V_9 = F_54 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
#ifndef F_6
if ( F_22 ( F_14 ( V_4 ) ) &&
V_11 == V_27 )
V_4 -> V_11 = V_66 ;
else
#endif
V_4 -> V_11 = V_70 ;
V_4 -> V_39 = 0 ;
break;
case V_70 :
case V_130 :
if ( ! V_4 -> V_41 -> V_42 )
V_4 -> V_19 -> V_40 = 1 ;
V_9 = F_55 ( V_4 , V_70 ,
V_130 ) ;
if ( V_9 <= 0 )
goto V_37;
F_17 ( V_4 ) ;
if ( V_4 -> V_73 )
V_4 -> V_11 = V_31 ;
#ifndef F_38
else if ( V_4 -> V_75 )
V_4 -> V_11 = V_76 ;
#endif
else
V_4 -> V_11 = V_77 ;
V_4 -> V_39 = 0 ;
break;
#ifndef F_38
case V_76 :
case V_131 :
V_9 = F_56 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
V_4 -> V_11 = V_77 ;
V_4 -> V_39 = 0 ;
break;
case V_86 :
case V_132 :
V_9 = F_57 ( V_4 ) ;
if ( V_9 <= 0 )
goto V_37;
V_4 -> V_11 = V_87 ;
V_4 -> V_39 = 0 ;
break;
#endif
case V_77 :
case V_133 :
V_4 -> V_103 -> V_134 = V_4 -> V_41 -> V_50 . V_80 ;
if ( ! V_4 -> V_122 -> V_123 -> V_135 ( V_4 ) ) {
V_9 = - 1 ;
goto V_37;
}
V_9 = F_58 ( V_4 ,
V_77 ,
V_133 ) ;
if ( V_9 <= 0 )
goto V_37;
#ifndef F_6
if ( ! V_4 -> V_73 ) {
F_13 ( F_14 ( V_4 ) , V_136 ,
0 , NULL ) ;
}
#endif
V_4 -> V_11 = V_137 ;
V_4 -> V_39 = 0 ;
if ( ! V_4 -> V_122 -> V_123 -> V_138 ( V_4 ,
V_139 ) )
{
V_9 = - 1 ;
goto V_37;
}
F_59 ( V_4 , V_140 ) ;
break;
case V_137 :
case V_141 :
V_9 = F_60 ( V_4 ,
V_137 ,
V_141 ,
V_4 -> V_122 ->
V_123 -> V_142 ,
V_4 -> V_122 ->
V_123 -> V_143 ) ;
if ( V_9 <= 0 )
goto V_37;
V_4 -> V_11 = V_52 ;
if ( V_4 -> V_73 ) {
V_4 -> V_41 -> V_50 . V_51 = V_70 ;
#ifndef F_6
F_13 ( F_14 ( V_4 ) , V_136 ,
0 , NULL ) ;
#endif
} else {
V_4 -> V_41 -> V_50 . V_51 = V_31 ;
#ifndef F_6
if ( F_22 ( F_14 ( V_4 ) ) ) {
V_4 -> V_19 -> V_51 = V_4 -> V_41 -> V_50 . V_51 ;
V_4 -> V_41 -> V_50 . V_51 = V_71 ;
}
#endif
}
V_4 -> V_39 = 0 ;
break;
case V_31 :
F_61 ( V_4 ) ;
#if 0
BUF_MEM_free(s->init_buf);
s->init_buf = NULL;
#endif
F_62 ( V_4 ) ;
V_4 -> V_39 = 0 ;
if ( V_4 -> V_28 == 2 ) {
V_4 -> V_28 = 0 ;
V_4 -> V_144 = 0 ;
F_63 ( V_4 , V_145 ) ;
V_4 -> V_18 -> V_44 . V_146 ++ ;
V_4 -> V_147 = F_4 ;
if ( F_5 != NULL )
F_5 ( V_4 , V_148 , 1 ) ;
}
V_9 = 1 ;
V_4 -> V_19 -> V_61 = 0 ;
V_4 -> V_19 -> V_62 = 0 ;
V_4 -> V_19 -> V_63 = 0 ;
goto V_37;
default:
F_15 ( V_23 , V_149 ) ;
V_9 = - 1 ;
goto V_37;
}
if ( ! V_4 -> V_41 -> V_50 . V_150 && ! V_12 ) {
if ( V_4 -> V_151 ) {
if ( ( V_9 = F_48 ( V_4 -> V_113 ) ) <= 0 )
goto V_37;
}
if ( ( F_5 != NULL ) && ( V_4 -> V_11 != V_11 ) ) {
V_10 = V_4 -> V_11 ;
V_4 -> V_11 = V_11 ;
F_5 ( V_4 , V_152 , 1 ) ;
V_4 -> V_11 = V_10 ;
}
}
V_12 = 0 ;
}
