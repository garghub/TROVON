int T_1 F_1 ( int V_1 , T_2 * V_2 )
{
T_3 * V_3 ;
int V_4 , V_5 ;
V_3 = F_2 ( V_2 ) ;
V_4 = F_3 ( V_2 ) ;
V_5 = F_4 ( V_2 ) ;
F_5 ( V_6 , L_1 , V_5 ) ;
if ( V_3 )
{
F_6 ( V_6 , F_7 ( V_3 ) ,
0 , V_7 ) ;
F_8 ( V_6 , L_2 ) ;
}
else
F_8 ( V_6 , L_3 ) ;
if ( ! V_1 )
{
F_5 ( V_6 , L_4 , V_4 ,
F_9 ( V_4 ) ) ;
if ( V_8 >= V_5 )
{
if ( ! V_9 )
V_1 = 1 ;
V_10 = V_11 ;
}
else
{
V_1 = 0 ;
V_10 = V_12 ;
}
}
switch ( V_4 )
{
case V_13 :
F_8 ( V_6 , L_5 ) ;
F_6 ( V_6 , F_10 ( V_3 ) ,
0 , V_7 ) ;
F_8 ( V_6 , L_2 ) ;
break;
case V_14 :
case V_15 :
F_5 ( V_6 , L_6 ) ;
F_11 ( V_6 , F_12 ( V_3 ) ) ;
F_5 ( V_6 , L_2 ) ;
break;
case V_16 :
case V_17 :
F_5 ( V_6 , L_7 ) ;
F_11 ( V_6 , F_13 ( V_3 ) ) ;
F_5 ( V_6 , L_2 ) ;
break;
case V_18 :
F_14 ( V_6 , V_2 ) ;
break;
}
if ( V_4 == V_11 && V_1 == 2 )
F_14 ( V_6 , V_2 ) ;
F_5 ( V_6 , L_8 , V_1 ) ;
return ( V_1 ) ;
}
int F_15 ( T_4 * V_2 , char * V_19 , char * V_20 )
{
if ( V_19 != NULL )
{
if ( F_16 ( V_2 , V_19 ,
V_21 ) <= 0 )
{
F_5 ( V_6 , L_9 , V_19 ) ;
F_17 ( V_6 ) ;
return ( 0 ) ;
}
if ( V_20 == NULL ) V_20 = V_19 ;
if ( F_18 ( V_2 , V_20 ,
V_21 ) <= 0 )
{
F_5 ( V_6 , L_10 , V_20 ) ;
F_17 ( V_6 ) ;
return ( 0 ) ;
}
if ( ! F_19 ( V_2 ) )
{
F_5 ( V_6 , L_11 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
int F_20 ( T_4 * V_2 , T_3 * V_22 , T_5 * V_23 )
{
if ( V_22 == NULL )
return 1 ;
if ( F_21 ( V_2 , V_22 ) <= 0 )
{
F_5 ( V_6 , L_12 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
if ( F_22 ( V_2 , V_23 ) <= 0 )
{
F_5 ( V_6 , L_13 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
if ( ! F_19 ( V_2 ) )
{
F_5 ( V_6 , L_11 ) ;
return 0 ;
}
return 1 ;
}
long T_1 F_23 ( T_6 * V_24 , int V_25 , const char * V_26 ,
int V_27 , long V_28 , long V_29 )
{
T_6 * V_30 ;
V_30 = ( T_6 * ) F_24 ( V_24 ) ;
if ( V_30 == NULL ) return ( V_29 ) ;
if ( V_25 == ( V_31 | V_32 ) )
{
F_5 ( V_30 , L_14 ,
( void * ) V_24 , V_26 , ( unsigned long ) V_27 , V_29 , V_29 ) ;
F_25 ( V_30 , V_26 , ( int ) V_29 ) ;
return ( V_29 ) ;
}
else if ( V_25 == ( V_33 | V_32 ) )
{
F_5 ( V_30 , L_15 ,
( void * ) V_24 , V_26 , ( unsigned long ) V_27 , V_29 , V_29 ) ;
F_25 ( V_30 , V_26 , ( int ) V_29 ) ;
}
return ( V_29 ) ;
}
void T_1 F_26 ( const T_7 * V_34 , int V_35 , int V_29 )
{
const char * V_36 ;
int V_37 ;
V_37 = V_35 & ~ V_38 ;
if ( V_37 & V_39 ) V_36 = L_16 ;
else if ( V_37 & V_40 ) V_36 = L_17 ;
else V_36 = L_18 ;
if ( V_35 & V_41 )
{
F_5 ( V_6 , L_19 , V_36 , F_27 ( V_34 ) ) ;
}
else if ( V_35 & V_42 )
{
V_36 = ( V_35 & V_43 ) ? L_20 : L_21 ;
F_5 ( V_6 , L_22 ,
V_36 ,
F_28 ( V_29 ) ,
F_29 ( V_29 ) ) ;
}
else if ( V_35 & V_44 )
{
if ( V_29 == 0 )
F_5 ( V_6 , L_23 ,
V_36 , F_27 ( V_34 ) ) ;
else if ( V_29 < 0 )
{
F_5 ( V_6 , L_24 ,
V_36 , F_27 ( V_34 ) ) ;
}
}
}
void T_1 F_30 ( int V_45 , int V_46 , int V_47 , const void * V_48 , T_8 V_49 , T_7 * V_50 , void * V_51 )
{
T_6 * V_24 = V_51 ;
const char * V_52 , * V_53 , * V_54 = L_25 , * V_55 = L_25 , * V_56 = L_25 ;
V_52 = V_45 ? L_26 : L_27 ;
switch ( V_46 )
{
case V_57 :
V_53 = L_28 ;
break;
case V_58 :
V_53 = L_29 ;
break;
case V_59 :
V_53 = L_30 ;
break;
case V_60 :
V_53 = L_31 ;
break;
case V_61 :
V_53 = L_32 ;
break;
default:
V_53 = L_33 ;
}
if ( V_46 == V_57 )
{
V_55 = L_33 ;
if ( V_49 > 0 )
{
switch ( ( ( const unsigned char * ) V_48 ) [ 0 ] )
{
case 0 :
V_55 = L_34 ;
V_56 = L_35 ;
if ( V_49 >= 3 )
{
unsigned V_4 = ( ( ( const unsigned char * ) V_48 ) [ 1 ] << 8 ) + ( ( const unsigned char * ) V_48 ) [ 2 ] ;
switch ( V_4 )
{
case 0x0001 :
V_56 = L_36 ;
break;
case 0x0002 :
V_56 = L_37 ;
break;
case 0x0004 :
V_56 = L_38 ;
break;
case 0x0006 :
V_56 = L_39 ;
break;
}
}
break;
case 1 :
V_55 = L_40 ;
break;
case 2 :
V_55 = L_41 ;
break;
case 3 :
V_55 = L_42 ;
break;
case 4 :
V_55 = L_43 ;
break;
case 5 :
V_55 = L_44 ;
break;
case 6 :
V_55 = L_45 ;
break;
case 7 :
V_55 = L_46 ;
break;
case 8 :
V_55 = L_47 ;
break;
}
}
}
if ( V_46 == V_58 ||
V_46 == V_59 ||
V_46 == V_60 ||
V_46 == V_61 )
{
switch ( V_47 )
{
case 20 :
V_54 = L_48 ;
break;
case 21 :
V_54 = L_49 ;
break;
case 22 :
V_54 = L_50 ;
break;
}
if ( V_47 == 21 )
{
V_55 = L_51 ;
if ( V_49 == 2 )
{
switch ( ( ( const unsigned char * ) V_48 ) [ 0 ] )
{
case 1 :
V_55 = L_52 ;
break;
case 2 :
V_55 = L_53 ;
break;
}
V_56 = L_35 ;
switch ( ( ( const unsigned char * ) V_48 ) [ 1 ] )
{
case 0 :
V_56 = L_54 ;
break;
case 10 :
V_56 = L_55 ;
break;
case 20 :
V_56 = L_56 ;
break;
case 21 :
V_56 = L_57 ;
break;
case 22 :
V_56 = L_58 ;
break;
case 30 :
V_56 = L_59 ;
break;
case 40 :
V_56 = L_60 ;
break;
case 42 :
V_56 = L_61 ;
break;
case 43 :
V_56 = L_62 ;
break;
case 44 :
V_56 = L_63 ;
break;
case 45 :
V_56 = L_64 ;
break;
case 46 :
V_56 = L_65 ;
break;
case 47 :
V_56 = L_66 ;
break;
case 48 :
V_56 = L_67 ;
break;
case 49 :
V_56 = L_68 ;
break;
case 50 :
V_56 = L_69 ;
break;
case 51 :
V_56 = L_70 ;
break;
case 60 :
V_56 = L_71 ;
break;
case 70 :
V_56 = L_72 ;
break;
case 71 :
V_56 = L_73 ;
break;
case 80 :
V_56 = L_74 ;
break;
case 90 :
V_56 = L_75 ;
break;
case 100 :
V_56 = L_76 ;
break;
case 110 :
V_56 = L_77 ;
break;
case 111 :
V_56 = L_78 ;
break;
case 112 :
V_56 = L_79 ;
break;
case 113 :
V_56 = L_80 ;
break;
case 114 :
V_56 = L_81 ;
break;
}
}
}
if ( V_47 == 22 )
{
V_55 = L_33 ;
if ( V_49 > 0 )
{
switch ( ( ( const unsigned char * ) V_48 ) [ 0 ] )
{
case 0 :
V_55 = L_82 ;
break;
case 1 :
V_55 = L_83 ;
break;
case 2 :
V_55 = L_84 ;
break;
case 3 :
V_55 = L_85 ;
break;
case 11 :
V_55 = L_86 ;
break;
case 12 :
V_55 = L_87 ;
break;
case 13 :
V_55 = L_88 ;
break;
case 14 :
V_55 = L_89 ;
break;
case 15 :
V_55 = L_90 ;
break;
case 16 :
V_55 = L_91 ;
break;
case 20 :
V_55 = L_92 ;
break;
}
}
}
}
F_5 ( V_24 , L_93 , V_52 , V_53 , V_54 , ( unsigned long ) V_49 , V_55 , V_56 ) ;
if ( V_49 > 0 )
{
T_8 V_62 , V_63 ;
F_5 ( V_24 , L_94 ) ;
V_62 = V_49 ;
#if 0
if (num > 16)
num = 16;
#endif
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ )
{
if ( V_63 % 16 == 0 && V_63 > 0 )
F_5 ( V_24 , L_95 ) ;
F_5 ( V_24 , L_96 , ( ( const unsigned char * ) V_48 ) [ V_63 ] ) ;
}
if ( V_63 < V_49 )
F_5 ( V_24 , L_97 ) ;
F_5 ( V_24 , L_2 ) ;
}
( void ) F_31 ( V_24 ) ;
}
void T_1 F_32 ( T_7 * V_34 , int V_64 , int type ,
unsigned char * V_65 , int V_49 ,
void * V_51 )
{
T_6 * V_24 = V_51 ;
char * V_66 ;
switch( type )
{
case V_67 :
V_66 = L_98 ;
break;
case V_68 :
V_66 = L_99 ;
break;
case V_69 :
V_66 = L_100 ;
break;
case V_70 :
V_66 = L_101 ;
break;
case V_71 :
V_66 = L_102 ;
break;
case V_72 :
V_66 = L_103 ;
break;
case V_73 :
V_66 = L_104 ;
break;
case V_74 :
V_66 = L_105 ;
break;
case V_75 :
V_66 = L_106 ;
break;
case V_76 :
V_66 = L_107 ;
break;
#ifdef F_33
case F_33 :
V_66 = L_108 ;
break;
#endif
default:
V_66 = L_109 ;
break;
}
F_5 ( V_24 , L_110 ,
V_64 ? L_111 : L_112 ,
V_66 , type , V_49 ) ;
F_25 ( V_24 , ( char * ) V_65 , V_49 ) ;
( void ) F_31 ( V_24 ) ;
}
int T_1 F_34 ( T_7 * V_50 , unsigned char * V_77 , unsigned int * V_78 )
{
unsigned char * V_79 , V_80 [ V_81 ] ;
unsigned int V_82 , V_83 ;
union {
struct V_84 V_85 ;
struct V_86 V_87 ;
#if V_88
struct V_89 V_90 ;
#endif
} V_91 ;
if ( ! V_92 )
{
if ( ! F_35 ( V_93 , V_94 ) )
{
F_5 ( V_6 , L_113 ) ;
return 0 ;
}
V_92 = 1 ;
}
( void ) F_36 ( F_37 ( V_50 ) , & V_91 ) ;
V_82 = 0 ;
switch ( V_91 . V_85 . V_95 )
{
case V_96 :
V_82 += sizeof( struct V_97 ) ;
V_82 += sizeof( V_91 . V_87 . V_98 ) ;
break;
#if V_88
case V_99 :
V_82 += sizeof( struct V_100 ) ;
V_82 += sizeof( V_91 . V_90 . V_101 ) ;
break;
#endif
default:
F_38 ( 0 ) ;
break;
}
V_79 = F_39 ( V_82 ) ;
if ( V_79 == NULL )
{
F_5 ( V_6 , L_114 ) ;
return 0 ;
}
switch ( V_91 . V_85 . V_95 )
{
case V_96 :
memcpy ( V_79 ,
& V_91 . V_87 . V_98 ,
sizeof( V_91 . V_87 . V_98 ) ) ;
memcpy ( V_79 + sizeof( V_91 . V_87 . V_98 ) ,
& V_91 . V_87 . V_102 ,
sizeof( struct V_97 ) ) ;
break;
#if V_88
case V_99 :
memcpy ( V_79 ,
& V_91 . V_90 . V_101 ,
sizeof( V_91 . V_90 . V_101 ) ) ;
memcpy ( V_79 + sizeof( V_91 . V_90 . V_101 ) ,
& V_91 . V_90 . V_103 ,
sizeof( struct V_100 ) ) ;
break;
#endif
default:
F_38 ( 0 ) ;
break;
}
F_40 ( F_41 () , V_93 , V_94 ,
V_79 , V_82 , V_80 , & V_83 ) ;
F_42 ( V_79 ) ;
memcpy ( V_77 , V_80 , V_83 ) ;
* V_78 = V_83 ;
return 1 ;
}
int T_1 F_43 ( T_7 * V_50 , unsigned char * V_77 , unsigned int V_78 )
{
unsigned char * V_79 , V_80 [ V_81 ] ;
unsigned int V_82 , V_83 ;
union {
struct V_84 V_85 ;
struct V_86 V_87 ;
#if V_88
struct V_89 V_90 ;
#endif
} V_91 ;
if ( ! V_92 )
return 0 ;
( void ) F_36 ( F_37 ( V_50 ) , & V_91 ) ;
V_82 = 0 ;
switch ( V_91 . V_85 . V_95 )
{
case V_96 :
V_82 += sizeof( struct V_97 ) ;
V_82 += sizeof( V_91 . V_87 . V_98 ) ;
break;
#if V_88
case V_99 :
V_82 += sizeof( struct V_100 ) ;
V_82 += sizeof( V_91 . V_90 . V_101 ) ;
break;
#endif
default:
F_38 ( 0 ) ;
break;
}
V_79 = F_39 ( V_82 ) ;
if ( V_79 == NULL )
{
F_5 ( V_6 , L_114 ) ;
return 0 ;
}
switch ( V_91 . V_85 . V_95 )
{
case V_96 :
memcpy ( V_79 ,
& V_91 . V_87 . V_98 ,
sizeof( V_91 . V_87 . V_98 ) ) ;
memcpy ( V_79 + sizeof( V_91 . V_87 . V_98 ) ,
& V_91 . V_87 . V_102 ,
sizeof( struct V_97 ) ) ;
break;
#if V_88
case V_99 :
memcpy ( V_79 ,
& V_91 . V_90 . V_101 ,
sizeof( V_91 . V_90 . V_101 ) ) ;
memcpy ( V_79 + sizeof( V_91 . V_90 . V_101 ) ,
& V_91 . V_90 . V_103 ,
sizeof( struct V_100 ) ) ;
break;
#endif
default:
F_38 ( 0 ) ;
break;
}
F_40 ( F_41 () , V_93 , V_94 ,
V_79 , V_82 , V_80 , & V_83 ) ;
F_42 ( V_79 ) ;
if ( V_78 == V_83 && memcmp ( V_80 , V_77 , V_83 ) == 0 )
return 1 ;
return 0 ;
}
