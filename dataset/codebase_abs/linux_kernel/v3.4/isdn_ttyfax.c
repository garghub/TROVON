static char *
F_1 ( const char * V_1 )
{
char * V_2 ;
char * V_3 ;
if ( ( V_3 = strchr ( V_1 , ':' ) ) ) {
V_2 = V_3 + 2 ;
V_3 = strchr ( V_2 , '$' ) ;
* -- V_3 = 0 ;
} else
V_2 = L_1 ;
return V_2 ;
}
static void
F_2 ( int V_4 , T_1 * V_5 )
{
T_2 * V_6 = & V_5 -> V_7 ;
T_3 * V_8 = V_5 -> V_9 ;
char V_10 [ 50 ] ;
char V_11 [ 50 ] ;
char * V_12 ;
int V_13 ;
static char * V_14 [] =
{ L_2 , L_3 , L_4 , L_5 , L_6 ,
L_7 , L_8 , L_9 , L_10 ,
L_11 , L_12 , L_13 } ;
F_3 ( L_14 , V_5 ) ;
F_3 ( V_14 [ V_4 ] , V_5 ) ;
#ifdef F_4
F_5 ( V_15 L_15 ,
V_14 [ V_4 ] , V_5 -> line ) ;
#endif
switch ( V_4 ) {
case 0 :
break;
case 1 :
break;
case 2 :
if ( ( V_6 -> V_16 [ V_17 ] & V_18 ) &&
( ! ( V_19 -> V_20 [ V_5 -> V_21 ] & V_22 ) ) ) {
sprintf ( V_10 , L_16 , V_6 -> V_23 ) ;
F_3 ( V_10 , V_5 ) ;
}
V_5 -> V_24 = 1 ;
V_8 -> V_25 = 0 ;
if ( V_8 -> V_26 == V_27 )
V_8 -> V_26 = V_28 ;
break;
case 3 :
case 8 :
sprintf ( V_10 , L_17 , V_8 -> V_29 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case 4 :
V_10 [ 0 ] = 0 ;
V_12 = & V_8 -> V_30 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
sprintf ( V_11 , L_18 , V_12 [ V_13 ] + 48 ,
( V_13 < 7 ) ? L_19 : L_20 ) ;
strcat ( V_10 , V_11 ) ;
}
F_3 ( V_10 , V_5 ) ;
#ifdef F_4
F_5 ( V_15 L_21 ,
V_10 , V_5 -> line ) ;
#endif
break;
case 5 :
sprintf ( V_10 , L_22 , V_8 -> V_4 ) ;
F_3 ( V_10 , V_5 ) ;
V_5 -> V_31 = 0 ;
break;
case 6 :
V_10 [ 0 ] = 0 ;
V_12 = & V_8 -> V_30 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
sprintf ( V_11 , L_18 , V_12 [ V_13 ] + 48 ,
( V_13 < 7 ) ? L_19 : L_20 ) ;
strcat ( V_10 , V_11 ) ;
}
F_3 ( V_10 , V_5 ) ;
#ifdef F_4
F_5 ( V_15 L_23 ,
V_10 , V_5 -> line ) ;
#endif
break;
case 7 :
V_5 -> V_31 |= 2 ;
break;
case 9 :
break;
case 10 :
F_3 ( L_24 , V_5 ) ;
break;
case 11 :
sprintf ( V_10 , L_22 , V_8 -> V_25 ) ;
F_3 ( V_10 , V_5 ) ;
break;
}
F_3 ( L_14 , V_5 ) ;
switch ( V_4 ) {
case 7 :
V_5 -> V_24 = 2 ;
if ( V_5 -> V_31 & 1 ) {
sprintf ( V_10 , L_25 , V_32 ) ;
F_3 ( V_10 , V_5 ) ;
}
break;
}
}
static int
F_6 ( T_1 * V_5 , T_4 * V_33 )
{
static char * V_14 [] =
{ L_2 , L_9 , L_26 , L_3 , L_27 } ;
#ifdef F_4
F_5 ( V_15 L_28 , V_33 -> V_34 . V_35 . V_36 ) ;
#endif
if ( V_33 -> V_34 . V_35 . V_36 < V_37 ) {
if ( V_5 -> V_24 )
V_5 -> V_24 = 1 ;
F_3 ( L_14 , V_5 ) ;
F_3 ( V_14 [ V_33 -> V_34 . V_35 . V_36 ] , V_5 ) ;
F_3 ( L_14 , V_5 ) ;
}
switch ( V_33 -> V_34 . V_35 . V_36 ) {
case V_38 :
V_5 -> V_24 = 2 ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
break;
case V_37 :
F_3 ( L_14 , V_5 ) ;
if ( ! V_33 -> V_34 . V_35 . V_43 [ 0 ] ) {
F_3 ( V_14 [ V_41 ] , V_5 ) ;
F_3 ( L_14 , V_5 ) ;
} else {
F_3 ( V_33 -> V_34 . V_35 . V_43 , V_5 ) ;
F_3 ( L_29 , V_5 ) ;
}
break;
}
return ( 0 ) ;
}
int
F_7 ( T_1 * V_5 , T_4 * V_33 )
{
T_3 * V_8 = V_5 -> V_9 ;
char V_10 [ 10 ] ;
if ( F_8 ( V_5 ) )
return ( F_6 ( V_5 , V_33 ) ) ;
#ifdef F_4
F_5 ( V_15 L_30 ,
V_8 -> V_44 , V_5 -> line ) ;
#endif
switch ( V_8 -> V_44 ) {
case V_45 :
V_5 -> V_31 = 1 ;
F_2 ( 2 , V_5 ) ;
return ( 0 ) ;
case V_46 :
V_5 -> V_31 = 16 ;
F_2 ( 2 , V_5 ) ;
return ( 0 ) ;
case V_47 :
if ( V_5 -> V_31 & 1 )
F_2 ( 3 , V_5 ) ;
if ( V_5 -> V_31 & 16 )
F_2 ( 8 , V_5 ) ;
return ( 0 ) ;
case V_48 :
F_2 ( 4 , V_5 ) ;
return ( 0 ) ;
case V_49 :
if ( V_8 -> V_26 == V_50 ) {
if ( V_8 -> V_51 == V_52 ) {
sprintf ( V_10 , L_31 , V_53 , V_54 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
sprintf ( V_10 , L_25 , 0x18 ) ;
F_3 ( V_10 , V_5 ) ;
}
V_5 -> V_31 &= ~ 2 ;
V_5 -> V_24 = 1 ;
}
V_8 -> V_26 = V_55 ;
F_2 ( 5 , V_5 ) ;
F_2 ( 0 , V_5 ) ;
return ( 0 ) ;
case V_56 :
F_2 ( 6 , V_5 ) ;
F_2 ( 7 , V_5 ) ;
V_8 -> V_26 = V_50 ;
return ( 0 ) ;
case V_57 :
F_2 ( 6 , V_5 ) ;
F_2 ( 0 , V_5 ) ;
return ( 0 ) ;
case V_58 :
F_2 ( 0 , V_5 ) ;
return ( 0 ) ;
case V_59 :
F_2 ( 9 , V_5 ) ;
return ( 0 ) ;
case V_60 :
sprintf ( V_10 , L_31 , V_53 , V_54 ) ;
F_3 ( V_10 , V_5 ) ;
F_2 ( 10 , V_5 ) ;
F_2 ( 11 , V_5 ) ;
F_2 ( 0 , V_5 ) ;
V_5 -> V_31 &= ~ 2 ;
V_5 -> V_24 = 1 ;
V_8 -> V_26 = V_61 ;
return ( 0 ) ;
case V_62 :
F_2 ( 10 , V_5 ) ;
if ( V_8 -> V_51 == V_63 ) {
if ( V_8 -> V_25 == 1 )
V_8 -> V_26 = V_28 ;
if ( V_8 -> V_25 == 0 )
F_2 ( 0 , V_5 ) ;
}
return ( 0 ) ;
case V_64 :
V_5 -> V_31 &= ~ 2 ;
V_5 -> V_24 = 1 ;
V_8 -> V_26 = V_61 ;
return ( 0 ) ;
}
return ( - 1 ) ;
}
void
F_9 ( T_1 * V_5 , struct V_65 * V_66 )
{
T_5 V_67 ;
T_5 V_68 ;
T_5 V_69 ;
T_5 V_70 ;
int V_13 ;
if ( ! V_5 -> V_9 -> V_71 ) {
for ( V_13 = 0 ; V_13 < V_66 -> V_72 ; V_13 ++ ) {
V_70 = V_66 -> V_73 [ V_13 ] ;
for (
V_67 = 0x80 , V_68 = 0x01 ;
V_67 > V_68 ;
V_67 >>= 1 , V_68 <<= 1
) {
V_69 = ( V_70 & V_67 ) ;
if ( V_70 & V_68 )
V_70 |= V_67 ;
else
V_70 &= ~ V_67 ;
if ( V_69 )
V_70 |= V_68 ;
else
V_70 &= ~ V_68 ;
}
V_66 -> V_73 [ V_13 ] = V_70 ;
}
}
}
static int
F_10 ( char * * V_3 , T_1 * V_5 )
{
static char * V_36 [] =
{ L_32 , L_33 , L_34 , L_35 , L_36 , L_37 , L_38 } ;
T_4 V_33 ;
int V_74 , V_13 ;
T_6 V_75 ;
for ( V_33 . V_34 . V_35 . V_36 = 0 ; V_33 . V_34 . V_35 . V_36 < 7 ; V_33 . V_34 . V_35 . V_36 ++ )
if ( ! strncmp ( V_3 [ 0 ] , V_36 [ V_33 . V_34 . V_35 . V_36 ] , 2 ) )
break;
#ifdef F_4
F_5 ( V_15 L_39 , V_3 [ 0 ] , V_33 . V_34 . V_35 . V_36 ) ;
#endif
if ( V_33 . V_34 . V_35 . V_36 == 7 )
V_76 ;
V_3 [ 0 ] += 2 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
V_33 . V_34 . V_35 . V_77 = V_78 ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
V_33 . V_34 . V_35 . V_77 = V_79 ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 255 ) )
V_76 ;
V_33 . V_34 . V_35 . V_77 = V_80 ;
V_33 . V_34 . V_35 . V_43 [ 0 ] = V_74 ;
}
break;
case 0 :
V_33 . V_34 . V_35 . V_77 = V_81 ;
break;
default:
V_76 ;
}
V_33 . V_82 = V_83 ;
#ifdef F_4
F_5 ( V_15 L_40 ,
V_33 . V_34 . V_35 . V_36 , V_33 . V_34 . V_35 . V_77 , V_33 . V_34 . V_35 . V_43 [ 0 ] ) ;
#endif
if ( V_5 -> V_84 < 0 ) {
if ( ( V_33 . V_34 . V_35 . V_77 == V_80 ) ||
( V_33 . V_34 . V_35 . V_77 == V_81 ) ) {
V_76 ;
}
F_12 ( & V_19 -> V_85 , V_75 ) ;
V_13 = F_13 ( V_86 , V_87 ,
V_88 , - 1 , - 1 , L_41 ) ;
if ( V_13 < 0 ) {
F_14 ( & V_19 -> V_85 , V_75 ) ;
V_76 ;
}
V_5 -> V_84 = V_19 -> V_89 [ V_13 ] ;
V_5 -> V_21 = V_19 -> V_90 [ V_13 ] ;
V_5 -> V_91 = V_13 ;
V_19 -> V_92 [ V_13 ] = V_5 -> line ;
F_14 ( & V_19 -> V_85 , V_75 ) ;
V_33 . V_93 = V_5 -> V_84 ;
V_33 . V_94 = V_5 -> V_21 ;
F_15 ( & V_33 ) ;
F_12 ( & V_19 -> V_85 , V_75 ) ;
F_16 ( V_5 -> V_84 , V_5 -> V_21 ,
V_86 ) ;
V_5 -> V_84 = - 1 ;
V_5 -> V_21 = - 1 ;
if ( V_5 -> V_91 >= 0 ) {
V_19 -> V_92 [ V_5 -> V_91 ] = - 1 ;
V_5 -> V_91 = - 1 ;
}
F_14 ( & V_19 -> V_85 , V_75 ) ;
} else {
V_33 . V_93 = V_5 -> V_84 ;
V_33 . V_94 = V_5 -> V_21 ;
F_15 ( & V_33 ) ;
}
return 1 ;
}
static int
F_17 ( char * * V_3 , T_1 * V_5 )
{
T_2 * V_6 = & V_5 -> V_7 ;
T_3 * V_8 = V_5 -> V_9 ;
T_4 V_36 ;
int V_74 ;
char V_10 [ 50 ] ;
char V_11 [ 50 ] ;
int V_95 [] =
{ 1 , 5 , 2 , 2 , 3 , 2 , 0 , 7 } ;
if ( ! strncmp ( V_3 [ 0 ] , L_42 , 2 ) ) {
V_3 [ 0 ] += 2 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , 0 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 255 ) )
V_76 ;
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_44 , 6 ) ) {
V_3 [ 0 ] += 6 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , V_8 -> V_96 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_45 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 255 ) )
V_76 ;
V_8 -> V_96 = V_74 ;
#ifdef F_18
F_5 ( V_15 L_46 , V_74 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_47 , 6 ) ) {
V_3 [ 0 ] += 6 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , V_8 -> V_97 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_45 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 255 ) )
V_76 ;
V_8 -> V_97 = V_74 ;
#ifdef F_18
F_5 ( V_15 L_48 , V_74 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_49 , 3 ) ) {
V_3 [ 0 ] += 3 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , V_8 -> V_71 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_50 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 1 ) )
V_76 ;
V_8 -> V_71 = V_74 ;
#ifdef F_18
F_5 ( V_15 L_51 , V_74 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_52 , 3 ) ) {
V_3 [ 0 ] += 3 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , V_8 -> V_98 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_50 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 1 ) )
V_76 ;
V_8 -> V_98 = V_74 ;
#ifdef F_18
F_5 ( V_15 L_53 , V_74 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_54 , 4 ) ) {
V_3 [ 0 ] += 4 ;
#ifdef F_18
F_5 ( V_15 L_55 , ( 16 * V_6 -> V_16 [ V_99 ] ) ) ;
#endif
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_56 , ( 16 * V_6 -> V_16 [ V_99 ] ) ) ;
F_3 ( V_10 , V_5 ) ;
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_57 , 3 ) ) {
int V_13 , V_100 ;
V_3 [ 0 ] += 3 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_58 , V_8 -> V_101 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_59 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
if ( * V_3 [ 0 ] == '"' )
V_3 [ 0 ] ++ ;
for ( V_13 = 0 ; ( * V_3 [ 0 ] ) && V_13 < ( V_102 - 1 ) && ( * V_3 [ 0 ] != '"' ) ; V_13 ++ ) {
V_8 -> V_101 [ V_13 ] = * V_3 [ 0 ] ++ ;
}
if ( * V_3 [ 0 ] == '"' )
V_3 [ 0 ] ++ ;
for ( V_100 = V_13 ; V_100 < V_102 ; V_100 ++ ) {
V_8 -> V_101 [ V_100 ] = 32 ;
}
V_8 -> V_101 [ V_102 - 1 ] = 0 ;
#ifdef F_18
F_5 ( V_15 L_60 , V_8 -> V_101 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_61 , 2 ) ) {
V_3 [ 0 ] += 2 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , V_8 -> V_103 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_62 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 2 ) )
V_76 ;
V_8 -> V_103 = V_74 ;
#ifdef F_18
F_5 ( V_15 L_63 , V_74 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_64 , 2 ) ) {
V_3 [ 0 ] += 2 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , V_8 -> V_104 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_50 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 1 ) )
V_76 ;
V_8 -> V_104 = V_74 ;
#ifdef F_18
F_5 ( V_15 L_65 , V_74 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_66 , 6 ) ) {
V_3 [ 0 ] += 6 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , V_8 -> V_105 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_45 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 255 ) )
V_76 ;
V_8 -> V_105 = V_74 ;
#ifdef F_18
F_5 ( V_15 L_67 , V_74 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_68 , 3 ) ) {
char * V_12 = & V_8 -> V_106 ;
int V_13 ;
V_3 [ 0 ] += 3 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
strcpy ( V_10 , L_14 ) ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
sprintf ( V_11 , L_18 , V_12 [ V_13 ] + 48 ,
( V_13 < 7 ) ? L_19 : L_20 ) ;
strcat ( V_10 , V_11 ) ;
}
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
F_3 ( L_69 , V_5 ) ;
V_3 [ 0 ] ++ ;
} else {
for ( V_13 = 0 ; ( ( ( * V_3 [ 0 ] >= '0' ) && ( * V_3 [ 0 ] <= '9' ) ) || ( * V_3 [ 0 ] == ',' ) ) && ( V_13 < 8 ) ; V_13 ++ ) {
if ( * V_3 [ 0 ] != ',' ) {
if ( ( * V_3 [ 0 ] - 48 ) > V_95 [ V_13 ] ) {
V_76 ;
}
V_12 [ V_13 ] = * V_3 [ 0 ] - 48 ;
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == ',' )
V_3 [ 0 ] ++ ;
} else
V_3 [ 0 ] ++ ;
}
#ifdef F_18
F_5 ( V_15 L_70 ,
V_12 [ 0 ] , V_12 [ 1 ] , V_12 [ 2 ] , V_12 [ 3 ] , V_12 [ 4 ] , V_12 [ 5 ] , V_12 [ 6 ] , V_12 [ 7 ] ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_71 , 3 ) ) {
char * V_12 = & V_8 -> V_106 ;
int V_13 ;
V_3 [ 0 ] += 3 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
strcpy ( V_10 , L_14 ) ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
sprintf ( V_11 , L_18 , V_12 [ V_13 ] + 48 ,
( V_13 < 7 ) ? L_19 : L_20 ) ;
strcat ( V_10 , V_11 ) ;
}
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
F_3 ( L_69 , V_5 ) ;
V_3 [ 0 ] ++ ;
} else {
for ( V_13 = 0 ; ( ( ( * V_3 [ 0 ] >= '0' ) && ( * V_3 [ 0 ] <= '9' ) ) || ( * V_3 [ 0 ] == ',' ) ) && ( V_13 < 8 ) ; V_13 ++ ) {
if ( * V_3 [ 0 ] != ',' ) {
if ( ( * V_3 [ 0 ] - 48 ) > V_95 [ V_13 ] ) {
V_76 ;
}
V_12 [ V_13 ] = * V_3 [ 0 ] - 48 ;
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == ',' )
V_3 [ 0 ] ++ ;
} else
V_3 [ 0 ] ++ ;
}
#ifdef F_18
F_5 ( V_15 L_72 ,
V_12 [ 0 ] , V_12 [ 1 ] , V_12 [ 2 ] , V_12 [ 3 ] , V_12 [ 4 ] , V_12 [ 5 ] , V_12 [ 6 ] , V_12 [ 7 ] ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_73 , 2 ) ) {
V_3 [ 0 ] += 2 ;
if ( ( V_5 -> V_31 & 16 ) &&
( ( V_8 -> V_26 == V_28 ) || ( V_8 -> V_26 == V_61 ) ) ) {
#ifdef F_18
F_5 ( V_15 L_74 ) ;
#endif
V_8 -> V_4 = V_107 ;
V_36 . V_93 = V_5 -> V_84 ;
V_36 . V_94 = V_5 -> V_21 ;
V_36 . V_82 = V_83 ;
F_15 ( & V_36 ) ;
if ( V_8 -> V_26 == V_28 ) {
V_8 -> V_26 = V_50 ;
} else if ( V_8 -> V_26 == V_61 ) {
switch ( V_8 -> V_25 ) {
case 0 :
V_8 -> V_26 = V_50 ;
F_2 ( 7 , V_5 ) ;
break;
case 1 :
V_8 -> V_26 = V_28 ;
break;
case 2 :
V_8 -> V_26 = V_55 ;
break;
default:
V_76 ;
}
}
} else {
V_76 ;
}
return 1 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_75 , 2 ) ) {
int V_13 , V_108 [] =
{ 4 , 0 , 2 , 3 } ;
char * V_12 = & V_8 -> V_106 ;
V_3 [ 0 ] += 2 ;
if ( ! ( V_5 -> V_31 & 1 ) )
V_76 ;
for ( V_13 = 0 ; ( ( ( * V_3 [ 0 ] >= '0' ) && ( * V_3 [ 0 ] <= '9' ) ) || ( * V_3 [ 0 ] == ',' ) ) && ( V_13 < 4 ) ; V_13 ++ ) {
if ( * V_3 [ 0 ] != ',' ) {
if ( ( * V_3 [ 0 ] - 48 ) > V_95 [ V_108 [ V_13 ] ] ) {
V_76 ;
}
V_12 [ V_108 [ V_13 ] ] = * V_3 [ 0 ] - 48 ;
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == ',' )
V_3 [ 0 ] ++ ;
} else
V_3 [ 0 ] ++ ;
}
#ifdef F_18
F_5 ( V_15 L_76 ,
V_12 [ 4 ] , V_12 [ 0 ] , V_12 [ 2 ] , V_12 [ 3 ] ) ;
#endif
if ( ( V_8 -> V_26 == V_28 ) || ( V_8 -> V_26 == V_61 ) ) {
V_8 -> V_4 = V_109 ;
V_36 . V_93 = V_5 -> V_84 ;
V_36 . V_94 = V_5 -> V_21 ;
V_36 . V_82 = V_83 ;
F_15 ( & V_36 ) ;
if ( V_8 -> V_26 == V_61 ) {
V_8 -> V_26 = V_50 ;
F_2 ( 7 , V_5 ) ;
}
} else {
V_76 ;
}
return 1 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_77 , 3 ) ) {
V_3 [ 0 ] += 3 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , V_8 -> V_110 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_78 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 != 0 ) && ( V_74 != 2 ) )
V_76 ;
V_8 -> V_110 = V_74 ;
#ifdef F_18
F_5 ( V_15 L_79 , V_74 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_80 , 3 ) ) {
V_3 [ 0 ] += 3 ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_81 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
if ( ( V_8 -> V_26 != V_61 ) ||
( ! ( V_5 -> V_31 & 1 ) ) )
V_76 ;
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 2 ) )
V_76 ;
V_8 -> V_25 = V_74 ;
V_8 -> V_4 = V_60 ;
V_36 . V_93 = V_5 -> V_84 ;
V_36 . V_94 = V_5 -> V_21 ;
V_36 . V_82 = V_83 ;
F_15 ( & V_36 ) ;
#ifdef F_18
F_5 ( V_15 L_82 , V_74 ) ;
#endif
return 1 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_83 , 1 ) ) {
V_3 [ 0 ] += 1 ;
if ( ( V_8 -> V_26 == V_111 ) || ( V_8 -> V_26 == V_55 ) )
V_76 ;
F_19 ( V_5 , 1 ) ;
return 1 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_84 , 3 ) ) {
int V_13 , V_100 ;
V_3 [ 0 ] += 3 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_58 , V_8 -> V_112 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_59 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
if ( * V_3 [ 0 ] == '"' )
V_3 [ 0 ] ++ ;
for ( V_13 = 0 ; ( * V_3 [ 0 ] ) && V_13 < ( V_102 - 1 ) && ( * V_3 [ 0 ] != '"' ) ; V_13 ++ ) {
V_8 -> V_112 [ V_13 ] = * V_3 [ 0 ] ++ ;
}
if ( * V_3 [ 0 ] == '"' )
V_3 [ 0 ] ++ ;
for ( V_100 = V_13 ; V_100 < V_102 ; V_100 ++ ) {
V_8 -> V_112 [ V_100 ] = 32 ;
}
V_8 -> V_112 [ V_102 - 1 ] = 0 ;
#ifdef F_18
F_5 ( V_15 L_85 , V_8 -> V_112 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_86 , 4 ) ) {
V_3 [ 0 ] += 4 ;
#ifdef F_18
F_5 ( V_15 L_87 ) ;
#endif
F_3 ( L_88 , V_5 ) ;
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_89 , 4 ) ) {
V_3 [ 0 ] += 4 ;
#ifdef F_18
F_5 ( V_15 L_90 ) ;
#endif
F_3 ( L_88 , V_5 ) ;
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_91 , 5 ) ) {
V_3 [ 0 ] += 5 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , V_8 -> V_113 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_92 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 5 ) )
V_76 ;
V_8 -> V_113 = V_74 ;
#ifdef F_18
F_5 ( V_15 L_93 , V_74 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_94 , 5 ) ) {
V_3 [ 0 ] += 5 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , V_8 -> V_114 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_45 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 255 ) )
V_76 ;
V_8 -> V_114 = V_74 ;
#ifdef F_18
F_5 ( V_15 L_95 , V_74 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_96 , 3 ) ) {
V_3 [ 0 ] += 3 ;
switch ( * V_3 [ 0 ] ) {
case '?' :
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_43 , V_8 -> V_115 ) ;
F_3 ( V_10 , V_5 ) ;
break;
case '=' :
V_3 [ 0 ] ++ ;
if ( * V_3 [ 0 ] == '?' ) {
V_3 [ 0 ] ++ ;
sprintf ( V_10 , L_50 ) ;
F_3 ( V_10 , V_5 ) ;
} else {
V_74 = F_11 ( V_3 ) ;
if ( ( V_74 < 0 ) || ( V_74 > 1 ) )
V_76 ;
V_8 -> V_115 = V_74 ;
#ifdef F_18
F_5 ( V_15 L_97 , V_74 ) ;
#endif
}
break;
default:
V_76 ;
}
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_98 , 4 ) ) {
V_3 [ 0 ] += 4 ;
#ifdef F_18
F_5 ( V_15 L_99 ) ;
#endif
strcpy ( V_11 , V_116 ) ;
sprintf ( V_10 , L_100 , F_1 ( V_11 ) ) ;
F_3 ( V_10 , V_5 ) ;
return 0 ;
}
if ( ! strncmp ( V_3 [ 0 ] , L_101 , 4 ) ) {
V_3 [ 0 ] += 4 ;
#ifdef F_18
F_5 ( V_15 L_102 , * V_3 [ 0 ] ) ;
#endif
switch ( * V_3 [ 0 ] ) {
case '0' :
V_3 [ 0 ] ++ ;
break;
default:
V_76 ;
}
return 0 ;
}
F_5 ( V_15 L_103 , V_3 [ 0 ] ) ;
V_76 ;
}
int
F_20 ( char * * V_3 , T_1 * V_5 )
{
if ( F_21 ( V_5 ) )
return ( F_17 ( V_3 , V_5 ) ) ;
else if ( F_8 ( V_5 ) )
return ( F_10 ( V_3 , V_5 ) ) ;
V_76 ;
}
