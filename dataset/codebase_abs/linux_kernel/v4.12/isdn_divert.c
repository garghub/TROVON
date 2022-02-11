static void F_1 ( T_1 V_1 )
{
unsigned long V_2 ;
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
F_2 ( & V_5 , V_2 ) ;
F_3 ( & V_4 -> V_6 ) ;
F_4 ( & V_5 , V_2 ) ;
switch ( V_4 -> V_7 ) {
case V_8 :
V_4 -> V_9 . V_10 = V_11 ;
V_12 . V_13 ( & V_4 -> V_9 ) ;
F_2 ( & V_5 , V_2 ) ;
V_4 -> V_7 = V_14 ;
V_4 -> V_6 . V_15 = V_16 + ( V_17 * V_18 ) ;
F_5 ( & V_4 -> V_6 ) ;
F_4 ( & V_5 , V_2 ) ;
break;
case V_19 :
V_4 -> V_9 . V_10 = V_20 ;
F_6 ( V_4 -> V_9 . V_21 . V_22 . V_23 , V_4 -> V_24 , sizeof( V_4 -> V_9 . V_21 . V_22 . V_23 ) ) ;
strcpy ( V_4 -> V_9 . V_21 . V_22 . V_25 , L_1 ) ;
V_12 . V_13 ( & V_4 -> V_9 ) ;
F_2 ( & V_5 , V_2 ) ;
V_4 -> V_7 = V_14 ;
V_4 -> V_6 . V_15 = V_16 + ( V_17 * V_18 ) ;
F_5 ( & V_4 -> V_6 ) ;
F_4 ( & V_5 , V_2 ) ;
break;
case V_14 :
default:
F_2 ( & V_5 , V_2 ) ;
if ( V_4 -> V_26 )
V_4 -> V_26 -> V_27 = V_4 -> V_27 ;
else
V_28 = V_4 -> V_27 ;
if ( V_4 -> V_27 )
V_4 -> V_27 -> V_26 = V_4 -> V_26 ;
F_4 ( & V_5 , V_2 ) ;
F_7 ( V_4 ) ;
return;
}
}
int F_8 ( int V_29 , int V_30 ,
T_2 V_31 , char * V_32 ,
T_2 V_33 , char * V_34 , T_1 * V_35 )
{
unsigned long V_2 ;
int V_36 , V_37 ;
int V_38 ;
char * V_39 , * V_40 , V_41 [ 60 ] ;
struct V_3 * V_4 ;
if ( strchr ( V_32 , '.' ) ) return ( - V_42 ) ;
if ( ( V_31 & 0x7F ) > 2 ) return ( - V_42 ) ;
V_31 &= 3 ;
V_39 = V_41 ;
* V_39 ++ = 0x30 ;
V_40 = V_39 ++ ;
* V_39 ++ = 0xa ;
* V_39 ++ = 1 ;
* V_39 ++ = V_31 & 0x7F ;
* V_39 ++ = 0xa ;
* V_39 ++ = 1 ;
* V_39 ++ = V_33 ;
if ( V_30 == 1 ) {
if ( ! * V_34 ) return ( - V_42 ) ;
if ( strchr ( V_34 , '.' ) ) return ( - V_42 ) ;
V_38 = strlen ( V_34 ) ;
* V_39 ++ = 0x30 ;
* V_39 ++ = V_38 + 2 ;
* V_39 ++ = 0x80 ;
* V_39 ++ = V_38 ;
strcpy ( V_39 , V_34 ) ;
V_39 += V_38 ;
}
V_37 = strlen ( V_32 ) ;
* V_39 ++ = 0x80 ;
if ( V_37 > 1 ) {
* V_39 ++ = V_37 ;
strcpy ( V_39 , V_32 ) ;
V_39 += V_37 ;
} else
* V_39 ++ = 0 ;
* V_40 = V_39 - V_40 - 1 ;
if ( ! ( V_4 = F_9 ( sizeof( struct V_3 ) , V_43 ) ) )
return ( - V_44 ) ;
F_10 ( & V_4 -> V_6 , F_1 , ( T_1 ) V_4 ) ;
V_4 -> V_45 [ 0 ] = '\0' ;
V_4 -> V_9 . V_46 = V_29 ;
V_4 -> V_9 . V_10 = V_47 ;
V_4 -> V_9 . V_1 = V_48 ;
V_4 -> V_9 . V_21 . V_49 . V_31 = ( V_30 == 1 ) ? 7 : ( V_30 == 2 ) ? 11 : 8 ;
V_4 -> V_9 . V_21 . V_49 . V_50 = 4000 ;
V_4 -> V_9 . V_21 . V_49 . V_51 = V_39 - V_41 ;
V_4 -> V_9 . V_21 . V_49 . V_52 = V_41 ;
F_2 ( & V_5 , V_2 ) ;
V_4 -> V_9 . V_21 . V_49 . V_53 = V_54 ++ ;
F_4 ( & V_5 , V_2 ) ;
* V_35 = V_4 -> V_9 . V_21 . V_49 . V_53 ;
sprintf ( V_4 -> V_45 , L_2 ,
( ! V_30 ) ? V_55 : ( V_30 == 1 ) ? V_56 : V_57 ,
V_4 -> V_9 . V_21 . V_49 . V_53 ,
( V_30 != 2 ) ? L_3 : L_4 ,
V_12 . V_58 ( V_4 -> V_9 . V_46 ) ,
V_32 ,
V_33 & 0xFF ,
V_31 ,
( V_30 != 1 ) ? L_3 : L_5 ,
( V_30 != 1 ) ? L_3 : V_34 ) ;
V_36 = V_12 . V_13 ( & V_4 -> V_9 ) ;
if ( ! V_36 ) {
V_4 -> V_26 = NULL ;
F_2 ( & V_5 , V_2 ) ;
V_4 -> V_27 = V_28 ;
V_28 = V_4 ;
F_4 ( & V_5 , V_2 ) ;
} else
F_7 ( V_4 ) ;
return ( V_36 ) ;
}
int F_11 ( T_2 V_59 , T_1 V_60 , char * V_61 )
{
struct V_3 * V_4 ;
T_3 V_62 ;
unsigned long V_2 ;
int V_63 ;
if ( ( V_59 & 0x7F ) > 2 ) return ( - V_42 ) ;
V_4 = V_28 ;
while ( V_4 ) {
if ( V_4 -> V_64 == V_60 ) break;
V_4 = V_4 -> V_27 ;
}
if ( ! V_4 ) return ( - V_42 ) ;
V_62 . V_46 = V_4 -> V_9 . V_46 ;
V_62 . V_1 = V_4 -> V_9 . V_1 ;
V_63 = - V_42 ;
if ( V_4 -> V_7 == V_14 ) return ( V_63 ) ;
switch ( V_59 & 0x7F ) {
case 0 :
F_3 ( & V_4 -> V_6 ) ;
V_62 . V_10 = V_11 ;
V_63 = V_12 . V_13 ( & V_62 ) ;
F_2 ( & V_5 , V_2 ) ;
V_4 -> V_7 = V_14 ;
V_4 -> V_6 . V_15 = V_16 + ( V_17 * V_18 ) ;
F_5 ( & V_4 -> V_6 ) ;
F_4 ( & V_5 , V_2 ) ;
break;
case 1 :
if ( V_4 -> V_7 == V_19 ) return ( 0 ) ;
V_59 &= 0x7F ;
F_3 ( & V_4 -> V_6 ) ;
V_62 . V_10 = V_65 ;
if ( ( V_63 = V_12 . V_13 ( & V_62 ) ) ) {
F_2 ( & V_5 , V_2 ) ;
V_4 -> V_7 = V_14 ;
V_4 -> V_6 . V_15 = V_16 + ( V_17 * V_18 ) ;
F_5 ( & V_4 -> V_6 ) ;
F_4 ( & V_5 , V_2 ) ;
} else
V_4 -> V_7 = V_19 ;
break;
case 2 :
F_3 ( & V_4 -> V_6 ) ;
F_6 ( V_4 -> V_9 . V_21 . V_22 . V_23 , V_61 , sizeof( V_4 -> V_9 . V_21 . V_22 . V_23 ) ) ;
strcpy ( V_4 -> V_9 . V_21 . V_22 . V_25 , L_6 ) ;
V_62 . V_10 = V_20 ;
if ( ( V_63 = V_12 . V_13 ( & V_62 ) ) ) {
F_2 ( & V_5 , V_2 ) ;
V_4 -> V_7 = V_14 ;
V_4 -> V_6 . V_15 = V_16 + ( V_17 * V_18 ) ;
F_5 ( & V_4 -> V_6 ) ;
F_4 ( & V_5 , V_2 ) ;
} else
V_4 -> V_7 = V_19 ;
break;
}
return ( V_63 ) ;
}
int F_12 ( int V_66 , T_4 * V_67 )
{
struct V_68 * V_69 , * V_70 = NULL ;
unsigned long V_2 ;
if ( ! ( V_69 = F_9 ( sizeof( struct V_68 ) , V_71 ) ) )
return ( - V_44 ) ;
V_69 -> V_72 = * V_67 ;
F_2 ( & V_5 , V_2 ) ;
if ( V_66 >= 0 ) {
V_70 = V_73 ;
while ( ( V_70 ) && ( V_66 > 0 ) )
{ V_66 -- ;
V_70 = V_70 -> V_27 ;
}
if ( ! V_70 ) V_66 = - 1 ;
}
if ( V_66 < 0 ) {
V_69 -> V_26 = V_74 ;
V_69 -> V_27 = NULL ;
if ( V_69 -> V_26 )
V_69 -> V_26 -> V_27 = V_69 ;
else
V_73 = V_69 ;
V_74 = V_69 ;
} else {
V_69 -> V_27 = V_70 ;
V_69 -> V_26 = V_70 -> V_26 ;
V_70 -> V_26 = V_69 ;
if ( ! V_69 -> V_26 )
V_73 = V_69 ;
}
F_4 ( & V_5 , V_2 ) ;
return ( 0 ) ;
}
int F_13 ( int V_66 )
{
struct V_68 * V_69 , * V_70 ;
unsigned long V_2 ;
if ( V_66 < 0 ) {
F_2 ( & V_5 , V_2 ) ;
V_69 = V_73 ;
V_73 = NULL ;
V_74 = NULL ;
F_4 ( & V_5 , V_2 ) ;
while ( V_69 ) {
V_70 = V_69 ;
V_69 = V_69 -> V_27 ;
F_7 ( V_70 ) ;
}
return ( 0 ) ;
}
F_2 ( & V_5 , V_2 ) ;
V_69 = V_73 ;
while ( ( V_69 ) && ( V_66 > 0 ) ) {
V_66 -- ;
V_69 = V_69 -> V_27 ;
}
if ( ! V_69 ) {
F_4 ( & V_5 , V_2 ) ;
return ( - V_42 ) ;
}
if ( V_69 -> V_27 )
V_69 -> V_27 -> V_26 = V_69 -> V_26 ;
else
V_74 = V_69 -> V_26 ;
if ( V_69 -> V_26 )
V_69 -> V_26 -> V_27 = V_69 -> V_27 ;
else
V_73 = V_69 -> V_27 ;
F_4 ( & V_5 , V_2 ) ;
F_7 ( V_69 ) ;
return ( 0 ) ;
}
T_4 * F_14 ( int V_66 )
{
struct V_68 * V_69 = V_73 ;
if ( V_66 < 0 ) return ( NULL ) ;
while ( ( V_69 ) && ( V_66 >= 0 ) ) {
if ( ! ( V_66 -- ) ) {
return ( & V_69 -> V_72 ) ;
break;
}
V_69 = V_69 -> V_27 ;
}
return ( NULL ) ;
}
static int F_15 ( T_3 * V_62 )
{
int V_36 = 0 ;
unsigned long V_2 ;
struct V_3 * V_4 = NULL ;
struct V_68 * V_75 ;
char * V_39 , * V_76 ;
T_2 V_77 ;
for ( V_75 = V_73 ; V_75 ; V_75 = V_75 -> V_27 ) {
if ( ( ( V_75 -> V_72 . V_78 == 1 ) && ( V_62 -> V_10 == V_79 ) ) ||
( ( V_75 -> V_72 . V_78 == 2 ) && ( V_62 -> V_10 == V_80 ) ) )
continue;
if ( ! ( V_75 -> V_72 . V_29 & ( 1L << V_62 -> V_46 ) ) )
continue;
if ( ( V_75 -> V_72 . V_81 ) && ( V_75 -> V_72 . V_81 != V_62 -> V_21 . V_22 . V_81 ) )
continue;
if ( ( V_75 -> V_72 . V_82 ) && ( V_75 -> V_72 . V_82 != V_62 -> V_21 . V_22 . V_82 ) )
continue;
V_39 = V_75 -> V_72 . V_83 ;
V_76 = V_62 -> V_21 . V_22 . V_25 ;
V_77 = 0 ;
while ( * V_39 ) {
if ( * V_39 == '-' ) {
V_77 = 1 ;
break;
}
if ( * V_39 ++ != * V_76 ++ )
break;
if ( ( ! * V_39 ) && ( ! * V_76 ) )
V_77 = 1 ;
}
if ( ! V_77 ) continue;
if ( ( strcmp ( V_75 -> V_72 . V_84 , L_7 ) ) ||
( V_62 -> V_21 . V_22 . V_23 [ 0 ] ) ) {
V_39 = V_75 -> V_72 . V_84 ;
V_76 = V_62 -> V_21 . V_22 . V_23 ;
V_77 = 0 ;
while ( * V_39 ) {
if ( * V_39 == '-' ) {
V_77 = 1 ;
break;
}
if ( * V_39 ++ != * V_76 ++ )
break;
if ( ( ! * V_39 ) && ( ! * V_76 ) )
V_77 = 1 ;
}
if ( ! V_77 ) continue;
}
switch ( V_75 -> V_72 . V_85 ) {
case V_86 :
return 0 ;
case V_19 :
case V_8 :
case V_87 :
case V_88 :
if ( V_75 -> V_72 . V_85 == V_8 )
if ( ( ! V_89 ) || ( ( ! V_90 ) && ( ! V_75 -> V_72 . V_91 ) ) )
return ( 0 ) ;
if ( ! ( V_4 = F_9 ( sizeof( struct V_3 ) , V_43 ) ) )
return ( 0 ) ;
F_10 ( & V_4 -> V_6 , F_1 ,
( T_1 ) V_4 ) ;
V_4 -> V_45 [ 0 ] = '\0' ;
V_4 -> V_9 = * V_62 ;
if ( ! V_4 -> V_9 . V_21 . V_22 . V_23 [ 0 ] ) strcpy ( V_4 -> V_9 . V_21 . V_22 . V_23 , L_7 ) ;
if ( ! V_4 -> V_9 . V_21 . V_22 . V_25 [ 0 ] ) strcpy ( V_4 -> V_9 . V_21 . V_22 . V_25 , L_7 ) ;
V_4 -> V_9 . V_21 . V_22 . V_92 = V_75 -> V_72 . V_92 ;
if ( V_75 -> V_72 . V_91 )
V_4 -> V_6 . V_15 = V_16 + ( V_17 * V_75 -> V_72 . V_91 ) ;
else if ( V_75 -> V_72 . V_85 == V_8 )
V_4 -> V_6 . V_15 = V_16 + ( V_17 * V_90 ) ;
else
V_4 -> V_6 . V_15 = 0 ;
V_4 -> V_7 = V_75 -> V_72 . V_85 ;
F_2 ( & V_5 , V_2 ) ;
V_4 -> V_64 = V_54 ++ ;
F_4 ( & V_5 , V_2 ) ;
V_4 -> V_26 = NULL ;
if ( V_4 -> V_7 == V_19 ) {
strcpy ( V_4 -> V_24 , V_75 -> V_72 . V_61 ) ;
if ( ! V_4 -> V_6 . V_15 ) {
strcpy ( V_62 -> V_21 . V_22 . V_25 ,
L_8 ) ;
V_62 -> V_21 . V_22 . V_92 = V_75 -> V_72 . V_92 ;
F_6 ( V_62 -> V_21 . V_22 . V_23 , V_75 -> V_72 . V_61 , sizeof( V_62 -> V_21 . V_22 . V_23 ) ) ;
V_4 -> V_7 = V_14 ;
V_4 -> V_6 . V_15 = V_16 + ( V_17 * V_18 ) ;
V_36 = 5 ;
} else
V_36 = 1 ;
} else {
V_4 -> V_24 [ 0 ] = '\0' ;
V_36 = 4 ;
}
sprintf ( V_4 -> V_45 , L_9 ,
V_4 -> V_7 ,
V_4 -> V_64 ,
V_12 . V_58 ( V_4 -> V_9 . V_46 ) ,
( V_62 -> V_10 == V_79 ) ? L_10 : L_7 ,
V_4 -> V_9 . V_21 . V_22 . V_23 ,
V_4 -> V_9 . V_21 . V_22 . V_25 ,
V_4 -> V_9 . V_21 . V_22 . V_81 ,
V_4 -> V_9 . V_21 . V_22 . V_82 ,
V_4 -> V_9 . V_21 . V_22 . V_92 ,
V_75 -> V_72 . V_91 ,
V_4 -> V_24 ) ;
if ( ( V_75 -> V_72 . V_85 == V_87 ) ||
( V_75 -> V_72 . V_85 == V_88 ) ) {
F_16 ( V_4 -> V_45 ) ;
F_7 ( V_4 ) ;
return ( ( V_75 -> V_72 . V_85 == V_87 ) ? 0 : 2 ) ;
}
break;
default:
return 0 ;
}
break;
}
if ( V_4 ) {
V_4 -> V_26 = NULL ;
F_2 ( & V_5 , V_2 ) ;
V_4 -> V_27 = V_28 ;
V_28 = V_4 ;
if ( V_4 -> V_6 . V_15 ) F_5 ( & V_4 -> V_6 ) ;
F_4 ( & V_5 , V_2 ) ;
F_16 ( V_4 -> V_45 ) ;
return ( V_36 ) ;
} else
return ( 0 ) ;
}
void F_17 ( void )
{
struct V_3 * V_4 , * V_93 ;
unsigned long V_2 ;
F_2 ( & V_5 , V_2 ) ;
V_4 = V_28 ;
V_28 = NULL ;
while ( V_4 ) {
F_3 ( & V_4 -> V_6 ) ;
V_93 = V_4 ;
V_4 = V_4 -> V_27 ;
F_7 ( V_93 ) ;
}
F_4 ( & V_5 , V_2 ) ;
}
static int F_18 ( char * V_94 , T_2 * V_39 , int V_95 )
{
T_2 V_36 = 0 ;
T_2 V_96 = 0 ;
if ( V_95 < 2 ) return ( V_36 ) ;
if ( * V_39 == 0xA1 ) {
V_36 = * ( ++ V_39 ) + 2 ;
if ( V_36 > V_95 ) return ( 0 ) ;
V_95 = V_36 - 2 ;
if ( V_95 < 3 ) return ( 0 ) ;
if ( ( * ( ++ V_39 ) != 0x0A ) || ( * ( ++ V_39 ) != 1 ) ) return ( 0 ) ;
V_96 = * ( ++ V_39 ) ;
V_95 -= 3 ;
V_39 ++ ;
if ( V_95 < 2 ) return ( 0 ) ;
if ( * V_39 ++ != 0x12 ) return ( 0 ) ;
if ( * V_39 > V_95 ) return ( 0 ) ;
V_95 = * V_39 ++ ;
} else if ( * V_39 == 0x80 ) {
V_36 = * ( ++ V_39 ) + 2 ;
if ( V_36 > V_95 ) return ( 0 ) ;
V_95 = V_36 - 2 ;
V_39 ++ ;
} else
return ( 0 ) ;
sprintf ( V_94 , L_11 , V_96 ) ;
V_94 += strlen ( V_94 ) ;
if ( ! V_95 )
* V_94 ++ = '-' ;
else
while ( V_95 -- )
* V_94 ++ = * V_39 ++ ;
* V_94 = '\0' ;
return ( V_36 ) ;
}
static int F_19 ( T_3 * V_62 , struct V_3 * V_4 )
{
char * V_97 = V_62 -> V_21 . V_49 . V_52 ;
int V_98 = V_62 -> V_21 . V_49 . V_51 ;
int V_99 = 1 ;
T_2 V_100 , V_101 ;
char V_94 [ 90 ] , * V_39 , * V_102 ;
if ( V_98 < 2 ) return ( - 100 ) ;
if ( * V_97 ++ != 0x30 ) return ( - 101 ) ;
if ( ( V_100 = * V_97 ++ ) > 0x81 ) return ( - 102 ) ;
V_98 -= 2 ;
if ( V_100 == 0x80 ) {
if ( V_98 < 2 ) return ( - 103 ) ;
if ( ( * ( V_97 + V_98 - 1 ) ) || ( * ( V_97 + V_98 - 2 ) ) ) return ( - 104 ) ;
V_98 -= 2 ;
} else if ( V_100 == 0x81 ) {
V_100 = * V_97 ++ ;
V_98 -- ;
if ( V_100 > V_98 ) return ( - 105 ) ;
V_98 = V_100 ;
} else if ( V_100 > V_98 )
return ( - 106 ) ;
else
V_98 = V_100 ;
if ( V_98 < 3 ) return ( - 107 ) ;
if ( ( * V_97 ++ != 2 ) || ( * V_97 ++ != 1 ) || ( * V_97 ++ != 0x0B ) ) return ( - 108 ) ;
V_98 -= 3 ;
if ( V_98 < 2 ) return ( - 109 ) ;
if ( * V_97 == 0x31 ) {
V_97 ++ ;
if ( ( V_100 = * V_97 ++ ) > 0x81 ) return ( - 110 ) ;
V_98 -= 2 ;
if ( V_100 == 0x80 ) {
if ( V_98 < 2 ) return ( - 111 ) ;
if ( ( * ( V_97 + V_98 - 1 ) ) || ( * ( V_97 + V_98 - 2 ) ) ) return ( - 112 ) ;
V_98 -= 2 ;
} else if ( V_100 == 0x81 ) {
V_100 = * V_97 ++ ;
V_98 -- ;
if ( V_100 > V_98 ) return ( - 113 ) ;
V_98 = V_100 ;
} else if ( V_100 > V_98 )
return ( - 114 ) ;
else
V_98 = V_100 ;
}
while ( V_98 >= 2 ) {
V_102 = V_94 ;
sprintf ( V_102 , L_12 , V_57 , V_62 -> V_21 . V_49 . V_53 ,
V_99 ++ , V_12 . V_58 ( V_62 -> V_46 ) ) ;
V_102 += strlen ( V_102 ) ;
if ( * V_97 ++ != 0x30 ) return ( - 115 ) ;
V_100 = * V_97 ++ ;
V_98 -= 2 ;
if ( V_100 > V_98 ) return ( - 116 ) ;
V_98 -= V_100 ;
V_39 = V_97 ;
V_97 += V_100 ;
if ( ! ( V_101 = F_18 ( V_102 , V_39 , V_100 & 0xFF ) ) ) continue;
V_102 += strlen ( V_102 ) ;
V_39 += V_101 ;
V_100 -= V_101 ;
if ( V_100 < 6 ) continue;
if ( ( * V_39 ++ != 0x0A ) || ( * V_39 ++ != 1 ) ) continue;
sprintf ( V_102 , L_13 , ( * V_39 ++ ) & 0xFF ) ;
V_102 += strlen ( V_102 ) ;
if ( ( * V_39 ++ != 0x0A ) || ( * V_39 ++ != 1 ) ) continue;
sprintf ( V_102 , L_11 , ( * V_39 ++ ) & 0xFF ) ;
V_102 += strlen ( V_102 ) ;
V_100 -= 6 ;
if ( V_100 > 2 ) {
if ( * V_39 ++ != 0x30 ) continue;
if ( * V_39 > ( V_100 - 2 ) ) continue;
V_100 = * V_39 ++ ;
if ( ! ( V_101 = F_18 ( V_102 , V_39 , V_100 & 0xFF ) ) ) continue;
V_102 += strlen ( V_102 ) ;
}
sprintf ( V_102 , L_14 ) ;
F_16 ( V_94 ) ;
}
if ( V_98 ) return ( - 117 ) ;
return ( 0 ) ;
}
static int F_20 ( T_3 * V_62 )
{
struct V_3 * V_4 , * V_93 ;
int V_63 ;
unsigned long V_2 ;
V_4 = V_28 ;
V_93 = NULL ;
while ( V_4 ) {
if ( V_62 -> V_46 == V_4 -> V_9 . V_46 ) {
switch ( V_4 -> V_9 . V_1 ) {
case V_48 :
if ( ( V_4 -> V_9 . V_21 . V_49 . V_53 == V_62 -> V_21 . V_49 . V_53 ) &&
( V_4 -> V_9 . V_21 . V_49 . V_103 == V_62 -> V_21 . V_49 . V_103 ) ) {
switch ( V_62 -> V_1 ) {
case V_104 :
sprintf ( V_4 -> V_45 , L_15 ,
V_62 -> V_21 . V_49 . V_53 ,
V_62 -> V_21 . V_49 . V_50 ) ;
F_16 ( V_4 -> V_45 ) ;
break;
case V_105 :
switch ( V_4 -> V_9 . V_21 . V_49 . V_31 ) {
case 7 :
case 8 :
F_16 ( V_4 -> V_45 ) ;
break;
case 11 :
V_63 = F_19 ( V_62 , V_4 ) ;
if ( V_63 )
sprintf ( V_4 -> V_45 , L_16 , V_57 ,
V_62 -> V_21 . V_49 . V_53 , V_63 ) ;
F_16 ( V_4 -> V_45 ) ;
break;
default:
F_21 ( V_106 L_17 , V_4 -> V_9 . V_21 . V_49 . V_31 ) ;
break;
}
break;
default:
F_21 ( V_106 L_18 , V_62 -> V_1 ) ;
break;
}
V_93 = V_4 ;
V_4 = NULL ;
continue;
}
break;
case V_107 :
F_21 ( V_106 L_19 ) ;
break;
default:
F_21 ( V_106 L_20 , V_4 -> V_9 . V_1 ) ;
break;
}
V_4 = V_4 -> V_27 ;
}
}
if ( ! V_93 ) {
F_21 ( V_106 L_21 ) ;
return ( 0 ) ;
}
if ( V_93 -> V_9 . V_46 == - 1 ) {
F_2 ( & V_5 , V_2 ) ;
F_3 ( & V_93 -> V_6 ) ;
if ( V_93 -> V_26 )
V_93 -> V_26 -> V_27 = V_93 -> V_27 ;
else
V_28 = V_93 -> V_27 ;
if ( V_93 -> V_27 )
V_93 -> V_27 -> V_26 = V_93 -> V_26 ;
F_4 ( & V_5 , V_2 ) ;
F_7 ( V_93 ) ;
}
return ( 0 ) ;
}
static int F_22 ( T_3 * V_62 )
{
struct V_3 * V_4 , * V_93 ;
unsigned long V_2 ;
int V_36 ;
V_36 = - 1 ;
V_4 = V_28 ;
while ( V_4 ) {
if ( ( V_62 -> V_46 == V_4 -> V_9 . V_46 ) &&
( V_62 -> V_1 == V_4 -> V_9 . V_1 ) ) {
switch ( V_62 -> V_10 ) {
case V_108 :
sprintf ( V_4 -> V_45 , L_22 , V_4 -> V_64 ) ;
F_3 ( & V_4 -> V_6 ) ;
V_4 -> V_9 . V_46 = - 1 ;
break;
case V_109 :
sprintf ( V_4 -> V_45 , L_23 , V_4 -> V_64 , V_62 -> V_21 . V_110 ) ;
break;
case V_111 :
sprintf ( V_4 -> V_45 , L_24 , V_4 -> V_64 ) ;
F_3 ( & V_4 -> V_6 ) ;
V_4 -> V_9 . V_46 = - 1 ;
break;
default:
sprintf ( V_4 -> V_45 , L_25 , V_4 -> V_64 , ( int ) ( V_62 -> V_10 ) ) ;
break;
}
F_16 ( V_4 -> V_45 ) ;
V_36 = 0 ;
}
V_93 = V_4 ;
V_4 = V_4 -> V_27 ;
if ( V_93 -> V_9 . V_46 == - 1 ) {
F_2 ( & V_5 , V_2 ) ;
if ( V_93 -> V_26 )
V_93 -> V_26 -> V_27 = V_93 -> V_27 ;
else
V_28 = V_93 -> V_27 ;
if ( V_93 -> V_27 )
V_93 -> V_27 -> V_26 = V_93 -> V_26 ;
F_4 ( & V_5 , V_2 ) ;
F_7 ( V_93 ) ;
}
}
return ( V_36 ) ;
}
int F_23 ( T_3 * V_62 )
{
switch ( V_62 -> V_10 ) {
case V_80 :
case V_79 :
return ( F_15 ( V_62 ) ) ;
break;
case V_112 :
if ( ( V_62 -> V_1 & 0xFF ) == V_113 ) {
if ( V_62 -> V_1 != V_114 )
return ( F_20 ( V_62 ) ) ;
else
return ( 0 ) ;
} else
return ( - 1 ) ;
default:
return ( F_22 ( V_62 ) ) ;
}
}
