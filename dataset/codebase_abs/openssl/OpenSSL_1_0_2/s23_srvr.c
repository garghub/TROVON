static const T_1 * F_1 ( int V_1 )
{
#ifndef F_2
if ( V_1 == V_2 )
return ( F_3 () ) ;
#endif
#ifndef F_4
if ( V_1 == V_3 )
return ( F_5 () ) ;
#endif
if ( V_1 == V_4 )
return ( F_6 () ) ;
else if ( V_1 == V_5 )
return ( F_7 () ) ;
else if ( V_1 == V_6 )
return ( F_8 () ) ;
else
return ( NULL ) ;
}
int F_9 ( T_2 * V_7 )
{
T_3 * V_8 ;
unsigned long Time = ( unsigned long ) time ( NULL ) ;
void (* F_10) ( const T_2 * V_9 , int type , int V_10 ) = NULL ;
int V_11 = - 1 ;
int V_12 , V_13 ;
F_11 ( & Time , sizeof( Time ) , 0 ) ;
F_12 () ;
F_13 () ;
if ( V_7 -> V_14 != NULL )
F_10 = V_7 -> V_14 ;
else if ( V_7 -> V_15 -> V_14 != NULL )
F_10 = V_7 -> V_15 -> V_14 ;
V_7 -> V_16 ++ ;
if ( ! F_14 ( V_7 ) || F_15 ( V_7 ) )
F_16 ( V_7 ) ;
for (; ; ) {
V_13 = V_7 -> V_13 ;
switch ( V_7 -> V_13 ) {
case V_17 :
case V_18 :
case V_17 | V_18 :
case V_19 | V_18 :
V_7 -> V_20 = 1 ;
if ( F_10 != NULL )
F_10 ( V_7 , V_21 , 1 ) ;
V_7 -> type = V_18 ;
if ( V_7 -> V_22 == NULL ) {
if ( ( V_8 = F_17 () ) == NULL ) {
V_11 = - 1 ;
goto V_23;
}
if ( ! F_18 ( V_8 , V_24 ) ) {
F_19 ( V_8 ) ;
V_11 = - 1 ;
goto V_23;
}
V_7 -> V_22 = V_8 ;
}
F_20 ( V_7 ) ;
V_7 -> V_13 = V_25 ;
V_7 -> V_15 -> V_26 . V_27 ++ ;
V_7 -> V_28 = 0 ;
break;
case V_25 :
case V_29 :
V_7 -> V_30 = 0 ;
V_11 = F_21 ( V_7 ) ;
if ( V_11 >= 0 )
F_10 = NULL ;
goto V_23;
default:
F_22 ( V_31 , V_32 ) ;
V_11 = - 1 ;
goto V_23;
}
if ( ( F_10 != NULL ) && ( V_7 -> V_13 != V_13 ) ) {
V_12 = V_7 -> V_13 ;
V_7 -> V_13 = V_13 ;
F_10 ( V_7 , V_33 , 1 ) ;
V_7 -> V_13 = V_12 ;
}
}
V_23:
V_7 -> V_16 -- ;
if ( F_10 != NULL )
F_10 ( V_7 , V_34 , V_11 ) ;
return ( V_11 ) ;
}
int F_21 ( T_2 * V_7 )
{
char V_35 [ 11 ] ;
char * V_8 = & ( V_35 [ 0 ] ) ;
unsigned char * V_36 , * V_37 , * V_38 , * V_39 ;
unsigned int V_40 ;
unsigned int V_41 , V_42 , V_43 ;
int V_44 = 0 , V_45 ;
int type = 0 ;
int V_46 [ 2 ] ;
if ( V_7 -> V_13 == V_25 ) {
V_46 [ 0 ] = V_46 [ 1 ] = 0 ;
if ( ! F_23 ( V_7 ) )
goto V_47;
V_44 = F_24 ( V_7 , sizeof V_35 ) ;
if ( V_44 != sizeof V_35 )
return ( V_44 ) ;
V_36 = V_7 -> V_48 ;
memcpy ( V_8 , V_36 , V_44 ) ;
if ( ( V_36 [ 0 ] & 0x80 ) && ( V_36 [ 2 ] == V_49 ) ) {
if ( ( V_36 [ 3 ] == 0x00 ) && ( V_36 [ 4 ] == 0x02 ) ) {
V_46 [ 0 ] = V_36 [ 3 ] ;
V_46 [ 1 ] = V_36 [ 4 ] ;
if ( ! ( V_7 -> V_50 & V_51 ) )
type = 1 ;
} else if ( V_36 [ 3 ] == V_52 ) {
V_46 [ 0 ] = V_36 [ 3 ] ;
V_46 [ 1 ] = V_36 [ 4 ] ;
if ( V_36 [ 4 ] >= V_53 ) {
if ( V_36 [ 4 ] >= V_54 &&
! ( V_7 -> V_50 & V_55 ) ) {
V_7 -> V_56 = V_6 ;
V_7 -> V_13 = V_29 ;
} else if ( V_36 [ 4 ] >= V_57 &&
! ( V_7 -> V_50 & V_58 ) ) {
V_7 -> V_56 = V_5 ;
V_7 -> V_13 = V_29 ;
} else if ( ! ( V_7 -> V_50 & V_59 ) ) {
V_7 -> V_56 = V_4 ;
V_7 -> V_13 = V_29 ;
} else if ( ! ( V_7 -> V_50 & V_60 ) ) {
V_7 -> V_56 = V_3 ;
V_7 -> V_13 = V_29 ;
} else if ( ! ( V_7 -> V_50 & V_51 ) ) {
type = 1 ;
}
} else if ( ! ( V_7 -> V_50 & V_60 ) ) {
V_7 -> V_56 = V_3 ;
V_7 -> V_13 = V_29 ;
} else if ( ! ( V_7 -> V_50 & V_51 ) )
type = 1 ;
}
}
else if ( ( V_36 [ 0 ] == V_61 ) &&
( V_36 [ 1 ] == V_52 ) &&
( V_36 [ 5 ] == V_62 ) && ( ( V_36 [ 3 ] == 0 && V_36 [ 4 ] < 5 )
|| ( V_36 [ 9 ] >= V_36 [ 1 ] ) ) ) {
V_46 [ 0 ] = V_36 [ 1 ] ;
if ( V_36 [ 3 ] == 0 && V_36 [ 4 ] < 6 ) {
F_22 ( V_63 , V_64 ) ;
goto V_47;
}
if ( V_36 [ 9 ] > V_52 )
V_46 [ 1 ] = 0xff ;
else
V_46 [ 1 ] = V_36 [ 10 ] ;
if ( V_46 [ 1 ] >= V_53 ) {
if ( V_46 [ 1 ] >= V_54 &&
! ( V_7 -> V_50 & V_55 ) ) {
V_7 -> V_56 = V_6 ;
type = 3 ;
} else if ( V_46 [ 1 ] >= V_57 &&
! ( V_7 -> V_50 & V_58 ) ) {
V_7 -> V_56 = V_5 ;
type = 3 ;
} else if ( ! ( V_7 -> V_50 & V_59 ) ) {
V_7 -> V_56 = V_4 ;
type = 3 ;
} else if ( ! ( V_7 -> V_50 & V_60 ) ) {
V_7 -> V_56 = V_3 ;
type = 3 ;
}
} else {
if ( ! ( V_7 -> V_50 & V_60 ) ) {
V_7 -> V_56 = V_3 ;
type = 3 ;
} else if ( ! ( V_7 -> V_50 & V_59 ) ) {
V_7 -> V_56 = V_4 ;
type = 3 ;
}
}
} else if ( ( strncmp ( L_1 , ( char * ) V_36 , 4 ) == 0 ) ||
( strncmp ( L_2 , ( char * ) V_36 , 5 ) == 0 ) ||
( strncmp ( L_3 , ( char * ) V_36 , 5 ) == 0 ) ||
( strncmp ( L_4 , ( char * ) V_36 , 4 ) == 0 ) ) {
F_22 ( V_63 , V_65 ) ;
goto V_47;
} else if ( strncmp ( L_5 , ( char * ) V_36 , 7 ) == 0 ) {
F_22 ( V_63 , V_66 ) ;
goto V_47;
}
}
F_25 ( V_7 -> V_56 <= V_67 ) ;
if ( V_7 -> V_56 < V_6 && F_26 ( V_7 ) ) {
F_22 ( V_63 ,
V_68 ) ;
goto V_47;
}
#ifdef F_27
if ( F_28 () && ( V_7 -> V_56 < V_4 ) ) {
F_22 ( V_63 ,
V_69 ) ;
goto V_47;
}
#endif
if ( V_7 -> V_13 == V_29 ) {
type = 2 ;
V_36 = V_7 -> V_48 ;
V_46 [ 0 ] = V_36 [ 3 ] ;
V_46 [ 1 ] = V_36 [ 4 ] ;
V_44 = ( ( V_36 [ 0 ] & 0x7f ) << 8 ) | V_36 [ 1 ] ;
if ( V_44 > ( 1024 * 4 ) ) {
F_22 ( V_63 , V_70 ) ;
goto V_47;
}
if ( V_44 < 9 ) {
F_22 ( V_63 ,
V_71 ) ;
goto V_47;
}
V_45 = F_24 ( V_7 , V_44 + 2 ) ;
if ( V_45 <= 0 )
return ( V_45 ) ;
F_29 ( V_7 , V_7 -> V_48 + 2 , V_7 -> V_72 - 2 ) ;
if ( V_7 -> V_73 )
V_7 -> V_73 ( 0 , V_2 , 0 , V_7 -> V_48 + 2 ,
V_7 -> V_72 - 2 , V_7 , V_7 -> V_74 ) ;
V_36 = V_7 -> V_48 ;
V_36 += 5 ;
F_30 ( V_36 , V_41 ) ;
F_30 ( V_36 , V_42 ) ;
F_30 ( V_36 , V_43 ) ;
V_37 = ( unsigned char * ) V_7 -> V_22 -> V_75 ;
if ( ( V_41 + V_42 + V_43 + 11 ) != V_7 -> V_72 ) {
F_22 ( V_63 ,
V_71 ) ;
goto V_47;
}
* ( V_37 ++ ) = V_62 ;
V_38 = V_37 ;
V_37 += 3 ;
* ( V_37 ++ ) = V_52 ;
* ( V_37 ++ ) = V_46 [ 1 ] ;
V_40 = ( V_43 > V_76 ) ? V_76 : V_43 ;
memset ( V_37 , 0 , V_76 ) ;
memcpy ( & ( V_37 [ V_76 - V_40 ] ) , & ( V_36 [ V_41 + V_42 ] ) , V_40 ) ;
V_37 += V_76 ;
* ( V_37 ++ ) = 0 ;
V_45 = 0 ;
V_39 = V_37 ;
V_37 += 2 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 += 3 ) {
if ( V_36 [ V_40 ] != 0 )
continue;
* ( V_37 ++ ) = V_36 [ V_40 + 1 ] ;
* ( V_37 ++ ) = V_36 [ V_40 + 2 ] ;
V_45 += 2 ;
}
F_31 ( V_45 , V_39 ) ;
* ( V_37 ++ ) = 1 ;
* ( V_37 ++ ) = 0 ;
#if 0
p = p + csl + sil + cl;
while (p < s->packet + s->packet_length) {
*(d++) = *(p++);
}
#endif
V_40 = ( V_37 - ( unsigned char * ) V_7 -> V_22 -> V_75 ) - 4 ;
F_32 ( ( long ) V_40 , V_38 ) ;
V_7 -> V_77 -> V_78 . V_79 = 1 ;
V_7 -> V_77 -> V_78 . V_80 = V_62 ;
V_7 -> V_77 -> V_78 . V_81 = V_40 ;
}
if ( type == 1 ) {
#ifdef F_2
F_22 ( V_63 , V_82 ) ;
goto V_47;
#else
if ( V_7 -> V_83 == NULL ) {
if ( ! F_33 ( V_7 ) )
goto V_47;
} else
F_34 ( V_7 ) ;
if ( V_7 -> V_77 != NULL )
F_35 ( V_7 ) ;
if ( ! F_36 ( V_7 -> V_22 ,
V_84 ) ) {
goto V_47;
}
V_7 -> V_13 = V_85 ;
if ( V_7 -> V_50 & V_59 && V_7 -> V_50 & V_60 )
V_7 -> V_83 -> V_86 = 0 ;
else
V_7 -> V_83 -> V_86 = 1 ;
V_7 -> V_87 = V_88 ;
V_7 -> V_72 = V_44 ;
V_7 -> V_48 = & ( V_7 -> V_83 -> V_89 [ 0 ] ) ;
memcpy ( V_7 -> V_48 , V_8 , V_44 ) ;
V_7 -> V_83 -> V_90 = V_44 ;
V_7 -> V_83 -> V_91 = 0 ;
V_7 -> V_92 = F_3 () ;
V_7 -> V_93 = V_7 -> V_92 -> V_94 ;
#endif
}
if ( ( type == 2 ) || ( type == 3 ) ) {
const T_1 * V_95 ;
V_95 = F_1 ( V_7 -> V_56 ) ;
if ( V_95 == NULL ) {
F_22 ( V_63 , V_82 ) ;
goto V_47;
}
V_7 -> V_92 = V_95 ;
if ( ! F_37 ( V_7 , 1 ) )
goto V_47;
V_7 -> V_13 = V_96 ;
if ( type == 3 ) {
V_7 -> V_87 = V_88 ;
V_7 -> V_72 = V_44 ;
if ( V_7 -> V_77 -> V_89 . V_8 == NULL )
if ( ! F_38 ( V_7 ) )
goto V_47;
V_7 -> V_48 = & ( V_7 -> V_77 -> V_89 . V_8 [ 0 ] ) ;
memcpy ( V_7 -> V_48 , V_8 , V_44 ) ;
V_7 -> V_77 -> V_89 . V_97 = V_44 ;
V_7 -> V_77 -> V_89 . V_98 = 0 ;
} else {
V_7 -> V_72 = 0 ;
V_7 -> V_77 -> V_89 . V_97 = 0 ;
V_7 -> V_77 -> V_89 . V_98 = 0 ;
}
#if 0
s->client_version = (v[0] << 8) | v[1];
#endif
V_7 -> V_93 = V_7 -> V_92 -> V_94 ;
}
if ( ( type < 1 ) || ( type > 3 ) ) {
F_22 ( V_63 , V_99 ) ;
goto V_47;
}
V_7 -> V_28 = 0 ;
if ( V_8 != V_35 )
F_39 ( V_8 ) ;
return ( F_40 ( V_7 ) ) ;
V_47:
if ( V_8 != V_35 )
F_39 ( V_8 ) ;
return ( - 1 ) ;
}
