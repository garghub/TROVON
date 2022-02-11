static int F_1 ( const char * string , T_1 V_1 )
{
F_2 ( F_3 ( * V_2 ) ) ;
}
static int F_4 ( const char * string , unsigned int V_1 )
{
F_2 ( F_5 ( * V_2 ) ) ;
}
static int F_6 ( const char * string , unsigned int V_1 )
{
F_2 ( F_7 ( * V_2 ) || F_8 ( * V_2 ) || F_9 ( * V_2 ) ) ;
}
static int F_10 ( const char * string , unsigned int V_1 )
{
F_2 ( F_7 ( * V_2 ) ) ;
}
static int F_11 ( const char * string , unsigned int V_1 )
{
F_2 ( F_12 ( * V_2 ) ) ;
}
static int F_13 ( const char * string , unsigned int V_1 )
{
F_2 ( F_12 ( * V_2 ) || F_8 ( * V_2 ) || F_9 ( * V_2 ) ) ;
}
static int F_14 ( const char * string , unsigned int V_1 )
{
F_2 ( F_5 ( * V_2 ) || F_8 ( * V_2 ) || F_9 ( * V_2 ) ) ;
}
static int F_15 ( const char * string , unsigned int V_1 )
{
F_2 ( F_8 ( * V_2 ) || F_9 ( * V_2 ) ) ;
}
static T_2 F_16 ( int type , const char * string , unsigned int V_1 )
{
switch( type )
{
case V_3 :
return F_10 ( string , V_1 ) ;
case V_4 :
return F_4 ( string , V_1 ) ;
case V_5 :
return F_1 ( string , V_1 ) ;
case V_6 :
return F_15 ( string , V_1 ) ;
case V_7 :
return F_6 ( string , V_1 ) ;
case V_8 :
return F_11 ( string , V_1 ) ;
case V_9 :
return F_13 ( string , V_1 ) ;
case V_10 :
return F_14 ( string , V_1 ) ;
case V_11 :
return F_1 ( string , V_1 ) ;
case V_12 :
if( V_13 == V_14 )
return F_13 ( string , V_1 ) ;
else
return F_1 ( string , V_1 ) ;
}
return 0 ;
}
static T_1 F_17 ( T_3 * T_4 V_15 , T_5 * V_16 , int V_17 , void * T_6 V_15 )
{
const T_1 V_18 = ( V_19 == V_20 ) ? V_21 : V_22 ;
return F_18 ( V_16 , V_17 , V_18 ) + 2 ;
}
static T_7 * F_19 ( const T_8 * V_23 , enum V_24 type , T_9 V_25 )
{
T_7 * V_26 ;
T_8 V_27 ;
const T_8 * V_28 = V_23 ;
T_9 V_1 = V_25 ;
T_7 * V_29 ;
V_26 = ( T_7 * ) F_20 ( F_21 () , V_1 + 1 ) ;
V_29 = V_26 ;
if( type == V_30 )
{
if( V_1 % 2 )
{
V_27 = * V_28 & 0x0f ;
* V_29 ++ = F_22 ( V_27 ) ;
V_28 ++ ;
V_1 -- ;
}
V_1 = V_25 /= 2 ;
}
while( V_1 -- > 0 )
{
V_27 = ( * V_28 >> 4 ) & 0x0f ;
* V_29 ++ = F_22 ( V_27 ) ;
V_27 = * V_28 & 0x0f ;
* V_29 ++ = F_22 ( V_27 ) ;
V_28 ++ ;
}
* V_29 = '\0' ;
return V_26 ;
}
static T_10 F_23 ( const char * V_31 , int V_25 )
{
char V_32 ;
int V_33 ;
T_10 V_23 = 0 ;
for( V_33 = 0 ; V_33 < V_25 && V_33 < 16 ; V_33 ++ )
{
V_32 = V_31 [ V_33 ] ;
V_23 <<= 4 ;
if ( F_5 ( V_32 ) )
V_23 |= V_32 - 48 ;
else
V_23 |= F_24 ( V_32 ) - 55 ;
}
return V_23 ;
}
static T_7 * F_25 ( T_1 V_34 , T_5 * V_16 , T_1 * V_35 , T_11 * V_36 , T_12 * * exp , T_13 * V_37 , T_9 V_38 )
{
T_7 V_39 [ 1024 ] ;
T_7 * V_26 = NULL ;
T_9 V_25 ;
T_1 V_17 = * V_35 ;
T_2 V_40 = FALSE ;
if( V_41 [ V_34 ] . V_42 == 0 )
V_25 = V_41 [ V_34 ] . V_43 ;
else
{
V_25 = V_41 [ V_34 ] . V_42 ;
switch( V_13 )
{
case V_14 :
{
T_8 * V_44 ;
F_26 ( V_25 ) ;
V_44 = F_27 ( F_21 () , V_16 , V_17 , V_25 , V_45 ) ;
V_17 += V_25 ;
if ( ! F_28 ( V_44 , NULL , & V_25 ) )
return NULL ;
break;
}
case V_46 :
{
T_13 V_44 = 0 ;
T_7 * V_47 ;
if( V_25 % 2 )
V_25 ++ ;
F_29 ( V_16 , V_39 , V_17 , V_25 ) ;
V_47 = V_39 ;
F_26 ( ( V_25 / 2 ) ) ;
V_17 += V_25 / 2 ;
while( V_25 > 0 )
{
V_44 = V_44 * 100 + ( ( ( T_8 ) ( * V_47 ) >> 4 ) & 0x0f ) * 10 +
( ( ( T_8 ) ( * V_47 ) ) & 0x0f ) ;
V_25 -= 2 ;
V_47 ++ ;
}
V_25 = V_44 ;
break;
}
}
}
* V_35 = V_17 ;
if( V_25 > 0 )
{
if( ( T_1 ) V_25 > V_41 [ V_34 ] . V_43 )
return NULL ;
if( V_41 [ V_34 ] . type == V_4 || V_41 [ V_34 ] . type == V_5 )
{
if( V_13 == V_14 )
{
F_26 ( V_25 ) ;
V_26 = ( T_7 * ) F_27 ( F_21 () , V_16 , V_17 ,
V_25 , V_45 ) ;
* V_37 = V_25 ;
}
else if( V_13 == V_46 )
{
T_13 V_48 = ( V_25 % 2 ) ? V_25 / 2 + 1 : V_25 / 2 ;
F_26 ( V_48 ) ;
F_29 ( V_16 , V_39 , V_17 , V_48 ) ;
if( ( V_26 = F_19 ( ( T_8 * ) V_39 , V_30 , V_25 ) ) == NULL )
return NULL ;
* V_37 = ( T_13 ) strlen ( V_26 ) ;
V_25 = V_48 ;
V_40 = TRUE ;
}
}
else if( V_41 [ V_34 ] . type == V_11 || V_41 [ V_34 ] . type == V_12 )
{
if( V_49 == V_50 )
{
if( V_41 [ V_34 ] . type == V_11 )
V_25 *= 2 ;
* V_37 = V_25 ;
F_26 ( V_25 ) ;
V_26 = ( T_7 * ) F_27 ( F_21 () , V_16 , V_17 ,
V_25 , V_45 ) ;
}
else
{
F_26 ( V_25 ) ;
F_29 ( V_16 , V_39 , V_17 , V_25 ) ;
if( ( V_26 = F_19 ( ( T_8 * ) V_39 , V_51 , V_25 ) ) == NULL )
return NULL ;
* V_37 = ( T_13 ) strlen ( V_26 ) ;
V_40 = TRUE ;
}
}
else
{
F_26 ( V_25 ) ;
V_26 = ( T_7 * ) F_27 ( F_21 () , V_16 , V_17 ,
V_25 , V_45 ) ;
* V_37 = V_25 ;
}
if( V_40 && V_36 != NULL )
* exp = F_30 ( V_36 , V_52 [ V_34 ] , V_16 , V_17 , V_25 , V_26 ) ;
else if ( V_36 != NULL )
* exp = F_31 ( V_36 , V_52 [ V_34 ] , V_16 ,
V_17 , V_25 , V_45 ) ;
* V_35 = V_17 + V_25 ;
}
else
{
* V_37 = 0 ;
V_26 = L_1 ;
}
return V_26 ;
}
static int F_32 ( T_5 * V_16 , T_10 * V_53 , T_1 V_17 , T_13 * V_54 , T_9 V_38 )
{
T_7 * V_55 ;
T_13 V_33 ;
T_2 V_56 = FALSE ;
* V_54 = 0 ;
for( V_33 = 0 ; V_33 < 2 ; V_33 ++ )
{
if( V_49 == V_57 )
{
if( ( V_17 - 2 + 8 ) > V_38 )
return - 1 ;
( * V_54 ) ++ ;
V_53 [ V_33 ] = F_33 ( V_16 , V_17 * 8 , 64 , V_21 ) ;
V_17 += V_58 ;
}
else
{
T_13 V_25 = V_58 * 2 ;
if( ( V_17 - 2 + V_25 ) > V_38 )
return - 1 ;
( * V_54 ) ++ ;
V_55 = ( T_7 * ) F_27 ( F_21 () , V_16 , V_17 , V_25 , V_45 ) ;
V_17 += V_25 ;
if( ! F_1 ( V_55 , V_25 ) )
return 0 ;
V_53 [ V_33 ] = F_23 ( V_55 , V_25 ) ;
}
if( ! ( V_53 [ V_33 ] & ( ( ( T_10 ) 1 ) << 63 ) ) )
{
V_56 = TRUE ;
break;
}
}
if( ! V_56 )
( * V_54 ) ++ ;
return 0 ;
}
static int F_34 ( T_5 * V_16 , T_3 * T_4 , T_11 * V_36 ,
int V_17 , int V_59 , T_10 * V_53 , T_9 V_38 )
{
T_12 * exp ;
T_13 V_60 = V_59 * 64 , V_33 ;
T_10 V_61 ;
T_7 * V_62 ;
T_13 V_25 ;
if( ! T_4 )
return 0 ;
for( V_33 = 0 ; V_33 < V_60 ; V_33 ++ )
{
exp = NULL ;
V_61 = V_33 % 64 ;
if( ! V_61 )
continue;
if( V_53 [ V_33 / 64 ] & ( ( ( T_10 ) 1 ) << ( 63 - V_61 ) ) )
{
V_62 = F_25 ( V_33 , V_16 , & V_17 , V_36 , & exp , & V_25 , V_38 ) ;
if( V_62 == NULL || ! F_16 ( V_41 [ V_33 ] . type , V_62 , V_25 ) )
{
if( ! exp )
exp = F_30 ( V_36 , V_52 [ V_33 ] , V_16 , V_17 , 0 , L_1 ) ;
F_35 ( T_4 , exp , & V_63 ) ;
return V_17 ;
}
if( V_33 == 2 || V_33 == 69 )
{
F_36 ( T_4 -> V_64 , V_65 , L_2 , ( ( V_33 == 2 ) ? L_3 : L_4 ) , V_62 ) ;
continue;
}
if( exp )
{
}
}
}
return F_37 ( V_16 ) ;
}
static int F_38 ( T_5 * V_16 , T_3 * T_4 , T_11 * V_36 ,
void * T_6 V_15 )
{
T_12 * V_66 , * exp ;
T_11 * V_67 ;
T_1 V_17 = 0 ;
int V_25 = 0 ;
T_7 * V_68 , * V_69 ;
T_7 V_39 [ 24 ] ;
T_10 V_53 [ 3 ] = { 0 , 0 , 0 } ;
int V_59 = 0 ;
T_1 V_26 ;
T_9 V_38 ;
if ( F_39 ( V_16 ) < V_70 )
{
return 0 ;
}
if( V_13 == V_14 )
{
V_25 = 4 ;
V_68 = ( T_7 * ) F_27 ( F_21 () , V_16 , 2 , V_25 , V_45 ) ;
}
else
{
V_25 = 2 ;
F_29 ( V_16 , V_39 , 2 , V_25 ) ;
if( ( V_68 = F_19 ( ( T_8 * ) V_39 , V_30 , V_25 * 2 ) ) == NULL )
return 0 ;
}
if( strlen ( V_68 ) == 4 && ! F_4 ( V_68 , 4 ) )
{
return 0 ;
}
if( V_49 == V_57 )
V_69 = ( T_7 * ) F_27 ( F_21 () , V_16 , 6 , V_58 * 2 , V_45 ) ;
else
{
F_29 ( V_16 , V_39 , 6 , V_58 ) ;
if( ( V_69 = F_19 ( ( T_8 * ) V_39 , V_30 , V_58 ) ) == NULL )
return 0 ;
}
if( strlen ( V_69 ) == 16 && ! F_1 ( V_69 , V_58 * 2 ) )
{
return 0 ;
}
if( V_68 [ 0 ] == '0' )
V_41 = V_71 ;
else if ( V_68 [ 0 ] == '1' )
V_41 = V_72 ;
else
{
return 0 ;
}
F_40 ( T_4 -> V_64 , V_73 ) ;
F_41 ( T_4 -> V_64 , V_73 , L_5 ,
F_42 ( ( T_1 ) V_68 [ 0 ] , V_74 , L_6 ) ) ;
F_40 ( T_4 -> V_64 , V_65 ) ;
F_41 ( T_4 -> V_64 , V_65 , L_7 , V_68 ,
F_42 ( ( T_1 ) V_68 [ 1 ] , V_75 , L_8 ) ) ;
V_66 = F_31 ( V_36 , V_76 , V_16 , 0 , - 1 , V_77 ) ;
F_43 ( V_66 , L_9 , V_68 ,
F_42 ( ( T_1 ) V_68 [ 1 ] , V_75 , L_8 ) ) ;
V_67 = F_44 ( V_66 , V_78 ) ;
V_25 = 2 ;
F_45 ( V_67 , V_79 , V_16 ,
V_17 , V_25 , ( V_19 == V_20 ) ? V_21 : V_22 ,
& V_38 ) ;
V_17 += V_25 ;
V_38 += 2 ;
if( V_13 == V_14 )
{
V_25 = 4 ;
F_31 ( V_67 , V_80 , V_16 ,
V_17 , V_25 , V_45 | V_77 ) ;
}
else
{
V_25 = 2 ;
F_30 ( V_67 , V_80 , V_16 , V_17 , V_25 , V_68 ) ;
}
V_17 += V_25 ;
F_32 ( V_16 , V_53 , V_17 , & V_59 , V_38 ) ;
if( V_59 == 0 )
{
F_35 ( T_4 , V_66 , & V_63 ) ;
return V_17 ;
}
if( V_49 == V_50 )
{
V_25 = V_58 * 2 ;
exp = F_31 ( V_67 , V_81 , V_16 ,
V_17 , V_25 , V_45 | V_77 ) ;
if( ! F_1 ( ( T_7 * ) F_27 ( F_21 () , V_16 , V_17 , V_25 , V_45 ) , V_25 ) )
{
F_35 ( T_4 , exp , & V_63 ) ;
return V_17 + V_25 ;
}
}
else
{
T_7 * V_31 ;
V_25 = V_58 ;
V_31 = F_46 ( F_21 () , V_16 , V_17 , V_25 ) ;
exp = F_30 ( V_67 , V_81 , V_16 , V_17 , V_25 , V_31 ) ;
}
V_17 += V_25 ;
if( V_59 > 1 )
{
if( V_49 == V_50 )
{
exp = F_31 ( V_67 , V_82 , V_16 ,
V_17 , V_25 , V_45 | V_77 ) ;
if( ! F_1 ( ( T_7 * ) F_27 ( F_21 () , V_16 , V_17 , V_25 , V_45 ) , V_25 ) )
{
F_35 ( T_4 , exp , & V_63 ) ;
return V_17 + V_25 ;
}
}
else
{
T_7 * V_31 = F_46 ( F_21 () , V_16 , V_17 , V_25 ) ;
exp = F_30 ( V_67 , V_82 , V_16 , V_17 , V_25 , V_31 ) ;
}
V_17 += V_25 ;
}
if( V_59 > 2 )
{
F_35 ( T_4 , exp , & V_63 ) ;
return V_17 ;
}
V_26 = F_34 ( V_16 , T_4 , V_67 , V_17 , V_59 , V_53 ,
V_38 ) ;
return V_26 ;
}
static int F_47 ( T_5 * V_16 , T_3 * T_4 , T_11 * V_36 ,
void * T_6 V_15 )
{
F_48 ( V_16 , T_4 , V_36 , TRUE , V_83 , F_17 , F_38 , T_6 ) ;
return F_37 ( V_16 ) ;
}
void
F_49 ( void )
{
T_14 * V_84 ;
T_15 * V_85 ;
int V_33 ;
static T_16 V_86 [] = {
{ & V_79 ,
{ L_10 , L_11 ,
V_87 , V_88 , NULL , 0x0 ,
L_12 , V_89 }
} ,
{ & V_80 ,
{ L_13 , L_14 ,
V_90 , V_91 , NULL , 0 ,
L_15 , V_89 }
} ,
{ & V_81 ,
{ L_16 , L_17 ,
V_90 , V_91 , NULL , 0 ,
L_18 , V_89 }
} ,
{ & V_82 ,
{ L_19 , L_20 ,
V_90 , V_91 , NULL , 0 ,
L_21 , V_89 }
}
} ;
static T_16 V_92 [ 128 ] ;
static const char * V_93 [ 128 ] = {
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36 ,
L_37 ,
L_38 ,
L_39 ,
L_40 ,
L_41 ,
L_42 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
L_50 ,
L_51 ,
L_52 ,
L_53 ,
L_54 ,
L_55 ,
L_56 ,
L_57 ,
L_58 ,
L_59 ,
L_60 ,
L_61 ,
L_62 ,
L_63 ,
L_64 ,
L_65 ,
L_66 ,
L_67 ,
L_68 ,
L_69 ,
L_70 ,
L_71 ,
L_72 ,
L_73 ,
L_74 ,
L_75 ,
L_76 ,
L_76 ,
L_77 ,
L_77 ,
L_77 ,
L_77 ,
L_78 ,
L_78 ,
L_78 ,
L_79 ,
L_80 ,
L_81 ,
L_82 ,
L_83 ,
L_84 ,
L_85 ,
L_86 ,
L_87 ,
L_88 ,
L_89 ,
L_90 ,
L_91 ,
L_92 ,
L_93 ,
L_94 ,
L_95 ,
L_96 ,
L_97 ,
L_98 ,
L_99 ,
L_100 ,
L_101 ,
L_102 ,
L_103 ,
L_104 ,
L_105 ,
L_106 ,
L_107 ,
L_108 ,
L_109 ,
L_110 ,
L_111 ,
L_112 ,
L_113 ,
L_114 ,
L_115 ,
L_116 ,
L_117 ,
L_118 ,
L_119 ,
L_120 ,
L_120 ,
L_120 ,
L_120 ,
L_120 ,
L_120 ,
L_120 ,
L_121 ,
L_121 ,
L_121 ,
L_121 ,
L_121 ,
L_121 ,
L_121 ,
L_121 ,
L_122 ,
L_122 ,
L_122 ,
L_122 ,
L_122 ,
L_122 ,
L_122 ,
L_122 ,
L_123
} ;
static T_13 * V_94 [] = {
& V_78
} ;
static T_17 V_95 [] = {
{ & V_63 ,
{ L_124 , V_96 , V_97 ,
L_125 , V_98 }
}
} ;
V_76 = F_50 ( L_126 , L_127 , L_128 ) ;
F_51 ( V_76 , V_86 , F_52 ( V_86 ) ) ;
for ( V_33 = 0 ; V_33 < 128 ; V_33 ++ ) {
F_53 ( V_92 [ V_33 ] ) ;
V_92 [ V_33 ] . V_99 = & V_52 [ V_33 ] ;
V_92 [ V_33 ] . V_100 . V_101 = F_54 ( F_55 () , L_129 , V_33 + 1 ) ;
V_92 [ V_33 ] . V_100 . V_102 = F_54 ( F_55 () , L_130 , V_33 + 1 ) ;
if( ! V_33 % 64 )
{
V_92 [ V_33 ] . V_100 . type = V_103 ;
V_92 [ V_33 ] . V_100 . V_104 = 8 ;
}
else
{
V_92 [ V_33 ] . V_100 . type = V_90 ;
V_92 [ V_33 ] . V_100 . V_104 = V_91 ;
}
V_92 [ V_33 ] . V_100 . V_105 = NULL ;
V_92 [ V_33 ] . V_100 . V_106 = 0 ;
V_92 [ V_33 ] . V_100 . V_107 = V_93 [ V_33 ] ;
}
F_51 ( V_76 , V_92 , F_52 ( V_92 ) ) ;
F_56 ( V_94 , F_52 ( V_94 ) ) ;
V_85 = F_57 ( V_76 ) ;
F_58 ( V_85 , V_95 , F_52 ( V_95 ) ) ;
V_84 = F_59 ( V_76 , NULL ) ;
F_60 ( V_84 , L_131 ,
L_132 ,
L_133 ,
& V_19 ,
V_108 , TRUE ) ;
F_60 ( V_84 , L_134 ,
L_135 ,
L_136 ,
& V_13 , V_109 , TRUE ) ;
F_60 ( V_84 , L_137 ,
L_138 ,
L_139 ,
& V_49 , V_110 , TRUE ) ;
}
void F_61 ( void )
{
T_18 V_111 ;
V_111 = F_62 ( F_47 , V_76 ) ;
F_63 ( L_140 , V_111 ) ;
}
