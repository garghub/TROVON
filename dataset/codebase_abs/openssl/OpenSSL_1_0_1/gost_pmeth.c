static int F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 ;
T_2 * V_4 = F_2 ( V_1 ) ;
V_3 = F_3 ( sizeof( struct V_2 ) ) ;
if ( ! V_3 ) return 0 ;
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
if ( V_4 && F_4 ( V_4 ) )
{
switch ( F_5 ( V_4 ) ) {
case V_5 :
V_3 -> V_6 = F_6 ( F_4 ( V_4 ) ) ;
break;
case V_7 :
V_3 -> V_6 = F_7 ( F_8 ( F_4 ( ( T_2 * ) V_4 ) ) ) ;
break;
default:
return 0 ;
}
}
F_9 ( V_1 , V_3 ) ;
return 1 ;
}
static int F_10 ( T_1 * V_8 , T_1 * V_9 )
{
struct V_2 * V_10 , * V_11 ;
if ( ! F_1 ( V_8 ) )
{
return 0 ;
}
V_11 = F_11 ( V_9 ) ;
V_10 = F_11 ( V_8 ) ;
* V_10 = * V_11 ;
if ( V_11 -> V_12 ) {
V_10 -> V_12 = NULL ;
}
return 1 ;
}
static void F_12 ( T_1 * V_1 )
{
struct V_2 * V_3 = F_11 ( V_1 ) ;
if ( V_3 -> V_12 ) F_13 ( V_3 -> V_12 ) ;
F_13 ( V_3 ) ;
}
static int F_14 ( T_1 * V_1 , int type , int V_13 , void * V_14 )
{
struct V_2 * V_15 = (struct V_2 * ) F_11 ( V_1 ) ;
switch ( type )
{
case V_16 :
{
if ( F_15 ( ( const V_17 * ) V_14 ) != V_18 )
{
F_16 ( V_19 , V_20 ) ;
return 0 ;
}
V_15 -> V_21 = ( V_17 * ) V_14 ;
return 1 ;
}
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
#ifndef F_17
case V_26 :
case V_27 :
case V_28 :
#endif
return 1 ;
case V_29 :
V_15 -> V_6 = ( int ) V_13 ;
return 1 ;
case V_30 :
V_15 -> V_12 = F_3 ( ( int ) V_13 ) ;
memcpy ( V_15 -> V_12 , V_14 , ( int ) V_13 ) ;
return 1 ;
case V_31 :
if ( V_13 == 0 || V_13 == 1 )
return 1 ;
if ( V_13 == 2 )
return V_15 -> V_32 ;
if ( V_13 == 3 )
return ( V_15 -> V_32 = 1 ) ;
return - 2 ;
}
return - 2 ;
}
static int F_18 ( T_1 * V_1 ,
const char * type , const char * V_33 )
{
int V_34 = 0 ;
if( ! strcmp ( type , V_35 ) )
{
if ( ! V_33 )
{
return 0 ;
}
if ( strlen ( V_33 ) == 1 )
{
switch( toupper ( ( unsigned char ) V_33 [ 0 ] ) )
{
case 'A' :
V_34 = V_36 ;
break;
case 'B' :
V_34 = V_37 ;
break;
case 'C' :
V_34 = V_38 ;
break;
case 'D' :
V_34 = V_39 ;
break;
default:
return 0 ;
break;
}
}
else if ( ( strlen ( V_33 ) == 2 ) && ( toupper ( ( unsigned char ) V_33 [ 0 ] ) == 'X' ) )
{
switch ( toupper ( ( unsigned char ) V_33 [ 1 ] ) )
{
case 'A' :
V_34 = V_40 ;
break;
case 'B' :
V_34 = V_41 ;
break;
case 'C' :
V_34 = V_42 ;
break;
default:
return 0 ;
break;
}
}
else
{
T_3 * V_43 = V_44 ;
V_34 = F_19 ( V_33 ) ;
if ( V_34 == V_45 )
{
return 0 ;
}
for (; V_43 -> V_46 != V_45 ; V_43 ++ )
{
if ( V_43 -> V_46 == V_34 ) break;
}
if ( V_43 -> V_46 == V_45 )
{
F_16 ( V_47 ,
V_48 ) ;
return 0 ;
}
}
return F_14 ( V_1 , V_29 ,
V_34 , NULL ) ;
}
return - 2 ;
}
static int F_20 ( T_1 * V_1 ,
const char * type , const char * V_33 )
{
int V_34 = 0 ;
if( ! strcmp ( type , V_35 ) )
{
if ( ! V_33 )
{
return 0 ;
}
if ( strlen ( V_33 ) == 1 )
{
switch( toupper ( ( unsigned char ) V_33 [ 0 ] ) )
{
case 'A' :
V_34 = V_49 ;
break;
case 'B' :
V_34 = V_50 ;
break;
case 'C' :
V_34 = V_51 ;
break;
case '0' :
V_34 = V_52 ;
break;
default:
return 0 ;
break;
}
}
else if ( ( strlen ( V_33 ) == 2 ) && ( toupper ( ( unsigned char ) V_33 [ 0 ] ) == 'X' ) )
{
switch ( toupper ( ( unsigned char ) V_33 [ 1 ] ) )
{
case 'A' :
V_34 = V_53 ;
break;
case 'B' :
V_34 = V_54 ;
break;
default:
return 0 ;
break;
}
}
else
{
T_4 * V_43 = V_55 ;
V_34 = F_19 ( V_33 ) ;
if ( V_34 == V_45 )
{
return 0 ;
}
for (; V_43 -> V_46 != V_45 ; V_43 ++ )
{
if ( V_43 -> V_46 == V_34 ) break;
}
if ( V_43 -> V_46 == V_45 )
{
F_16 ( V_56 ,
V_48 ) ;
return 0 ;
}
}
return F_14 ( V_1 , V_29 ,
V_34 , NULL ) ;
}
return - 2 ;
}
static int F_21 ( T_1 * V_1 ) {
return 1 ;
}
static int F_22 ( T_1 * V_1 , T_2 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_1 ) ;
T_5 * V_57 = NULL ;
if ( V_3 -> V_6 == V_45 )
{
F_16 ( V_58 ,
V_59 ) ;
return 0 ;
}
V_57 = F_23 () ;
if ( ! F_24 ( V_57 , V_3 -> V_6 ) )
{
F_25 ( V_57 ) ;
return 0 ;
}
F_26 ( V_4 , V_5 , V_57 ) ;
return 1 ;
}
static int F_27 ( T_1 * V_1 , T_2 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_1 ) ;
T_6 * V_60 = NULL ;
if ( V_3 -> V_6 == V_45 )
{
F_16 ( V_61 ,
V_59 ) ;
return 0 ;
}
if ( ! V_60 )
V_60 = F_28 () ;
if ( ! F_29 ( V_60 , V_3 -> V_6 ) )
{
F_30 ( V_60 ) ;
return 0 ;
}
F_26 ( V_4 , V_7 , V_60 ) ;
return 1 ;
}
static int F_31 ( T_1 * V_1 , T_2 * V_4 )
{
T_5 * V_57 ;
if ( ! F_22 ( V_1 , V_4 ) ) return 0 ;
V_57 = F_4 ( V_4 ) ;
F_32 ( V_57 ) ;
return 1 ;
}
static int F_33 ( T_1 * V_1 , T_2 * V_4 )
{
T_6 * V_60 ;
if ( ! F_27 ( V_1 , V_4 ) ) return 0 ;
V_60 = F_4 ( V_4 ) ;
F_34 ( V_60 ) ;
return 1 ;
}
static int F_35 ( T_1 * V_1 , unsigned char * V_62 , T_7 * V_63 ,
const unsigned char * V_64 , T_7 V_65 )
{
T_8 * V_66 = NULL ;
T_2 * V_4 = F_2 ( V_1 ) ;
if ( ! V_63 ) return 0 ;
if ( ! V_62 )
{
* V_63 = 64 ;
return 1 ;
}
V_66 = F_36 ( V_64 , V_65 , F_4 ( V_4 ) ) ;
if ( ! V_66 )
{
return 0 ;
}
return F_37 ( V_66 , 32 , V_62 , V_63 ) ;
}
static int F_38 ( T_1 * V_1 , unsigned char * V_62 , T_7 * V_63 ,
const unsigned char * V_64 , T_7 V_65 )
{
T_8 * V_66 = NULL ;
T_2 * V_4 = F_2 ( V_1 ) ;
if ( ! V_63 ) return 0 ;
if ( ! V_62 )
{
* V_63 = 64 ;
return 1 ;
}
V_66 = F_39 ( V_64 , V_65 , F_4 ( V_4 ) ) ;
if ( ! V_66 )
{
return 0 ;
}
return F_37 ( V_66 , 32 , V_62 , V_63 ) ;
}
static int F_40 ( T_1 * V_1 , const unsigned char * V_62 ,
T_7 V_63 , const unsigned char * V_64 , T_7 V_65 )
{
int V_67 = 0 ;
T_2 * V_68 = F_2 ( V_1 ) ;
T_8 * V_69 = F_41 ( V_62 , V_63 ) ;
if ( ! V_69 ) return 0 ;
if ( V_68 ) V_67 = F_42 ( V_64 , V_65 , V_69 , F_4 ( V_68 ) ) ;
F_43 ( V_69 ) ;
return V_67 ;
}
static int F_44 ( T_1 * V_1 , const unsigned char * V_62 ,
T_7 V_63 , const unsigned char * V_64 , T_7 V_65 )
{
int V_67 = 0 ;
T_2 * V_68 = F_2 ( V_1 ) ;
T_8 * V_69 = F_41 ( V_62 , V_63 ) ;
if ( ! V_69 ) return 0 ;
#ifdef F_45
fprintf ( V_70 , L_1 ) ;
F_46 ( V_70 , V_69 -> V_71 ) ;
fprintf ( V_70 , L_2 ) ;
F_46 ( V_70 , V_69 -> V_69 ) ;
fprintf ( V_70 , L_3 ) ;
#endif
if ( V_68 ) V_67 = F_47 ( V_64 , V_65 , V_69 , F_4 ( V_68 ) ) ;
F_43 ( V_69 ) ;
return V_67 ;
}
static int F_48 ( T_1 * V_1 )
{
return 1 ;
}
static int F_49 ( T_1 * V_1 )
{
return 1 ;
}
static int F_50 ( T_1 * V_1 )
{
struct V_72 * V_3 ;
V_3 = F_3 ( sizeof( struct V_72 ) ) ;
if ( ! V_3 ) return 0 ;
memset ( V_3 , 0 , sizeof( struct V_72 ) ) ;
F_9 ( V_1 , V_3 ) ;
return 1 ;
}
static void F_51 ( T_1 * V_1 )
{
struct V_72 * V_3 = F_11 ( V_1 ) ;
F_13 ( V_3 ) ;
}
static int F_52 ( T_1 * V_8 , T_1 * V_9 )
{
struct V_72 * V_10 , * V_11 ;
if ( ! F_50 ( V_8 ) )
{
return 0 ;
}
V_11 = F_11 ( V_9 ) ;
V_10 = F_11 ( V_8 ) ;
* V_10 = * V_11 ;
return 1 ;
}
static int F_53 ( T_1 * V_1 , int type , int V_13 , void * V_14 )
{
struct V_72 * V_3 =
(struct V_72 * ) F_11 ( V_1 ) ;
switch ( type )
{
case V_16 :
{
if ( F_15 ( ( const V_17 * ) V_14 ) != V_73 )
{
F_16 ( V_74 , V_20 ) ;
return 0 ;
}
V_3 -> V_21 = ( V_17 * ) V_14 ;
return 1 ;
}
break;
case V_22 :
case V_23 :
case V_24 :
return 1 ;
case V_75 :
if ( V_13 != 32 )
{
F_16 ( V_74 ,
V_76 ) ;
return 0 ;
}
memcpy ( V_3 -> V_77 , V_14 , 32 ) ;
V_3 -> V_78 = 1 ;
return 1 ;
case V_25 :
{
T_9 * V_79 = V_14 ;
void * V_77 ;
if ( ! V_3 -> V_78 )
{
T_2 * V_4 = F_2 ( V_1 ) ;
if ( ! V_4 )
{
F_16 ( V_74 , V_80 ) ;
return 0 ;
}
V_77 = F_4 ( V_4 ) ;
if ( ! V_77 )
{
F_16 ( V_74 , V_80 ) ;
return 0 ;
}
} else {
V_77 = & ( V_3 -> V_77 ) ;
}
return V_79 -> V_81 -> V_82 ( V_79 , V_83 , 32 , V_77 ) ;
}
}
return - 2 ;
}
static int F_54 ( T_1 * V_1 ,
const char * type , const char * V_33 )
{
if ( ! strcmp ( type , V_84 ) )
{
if ( strlen ( V_33 ) != 32 )
{
F_16 ( V_85 ,
V_76 ) ;
return 0 ;
}
return F_53 ( V_1 , V_75 ,
32 , ( char * ) V_33 ) ;
}
if ( ! strcmp ( type , V_86 ) )
{
long V_87 ; int V_88 ;
unsigned char * V_89 = F_55 ( V_33 , & V_87 ) ;
if ( V_87 != 32 )
{
F_16 ( V_85 ,
V_76 ) ;
F_13 ( V_89 ) ;
return 0 ;
}
V_88 = F_53 ( V_1 , V_75 ,
32 , V_89 ) ;
F_13 ( V_89 ) ;
return V_88 ;
}
return - 2 ;
}
static int F_56 ( T_1 * V_1 , T_2 * V_4 )
{
struct V_72 * V_3 = F_11 ( V_1 ) ;
unsigned char * V_90 ;
if ( ! V_3 -> V_78 )
{
F_16 ( V_91 , V_80 ) ;
return 0 ;
}
V_90 = F_3 ( 32 ) ;
memcpy ( V_90 , V_3 -> V_77 , 32 ) ;
F_26 ( V_4 , V_73 , V_90 ) ;
return 1 ;
}
static int F_57 ( T_1 * V_1 , T_9 * V_79 )
{
return 1 ;
}
static int F_58 ( T_1 * V_1 , unsigned char * V_62 , T_7 * V_63 , T_9 * V_79 )
{
unsigned int V_92 = * V_63 ;
int V_88 ;
if ( ! V_62 )
{
* V_63 = 4 ;
return 1 ;
}
V_88 = F_59 ( V_79 , V_62 , & V_92 ) ;
* V_63 = V_92 ;
return V_88 ;
}
int F_60 ( int V_93 , T_10 * * V_94 , int V_95 )
{
* V_94 = F_61 ( V_93 , V_95 ) ;
if ( ! * V_94 ) return 0 ;
switch ( V_93 )
{
case V_5 :
F_62 ( * V_94 , F_14 , F_18 ) ;
F_63 ( * V_94 , NULL , F_31 ) ;
F_64 ( * V_94 , NULL , F_35 ) ;
F_65 ( * V_94 , NULL , F_40 ) ;
F_66 ( * V_94 ,
F_48 , V_96 ) ;
F_67 ( * V_94 , NULL , V_97 ) ;
F_68 ( * V_94 ,
F_49 , V_98 ) ;
F_69 ( * V_94 , F_21 , F_22 ) ;
break;
case V_7 :
F_62 ( * V_94 , F_14 , F_20 ) ;
F_64 ( * V_94 , NULL , F_38 ) ;
F_65 ( * V_94 , NULL , F_44 ) ;
F_63 ( * V_94 , NULL , F_33 ) ;
F_66 ( * V_94 ,
F_48 , V_99 ) ;
F_67 ( * V_94 , NULL , V_100 ) ;
F_68 ( * V_94 ,
F_49 , V_101 ) ;
F_69 ( * V_94 , F_21 , F_27 ) ;
break;
case V_73 :
F_62 ( * V_94 , F_53 , F_54 ) ;
F_70 ( * V_94 , F_57 , F_58 ) ;
F_63 ( * V_94 , NULL , F_56 ) ;
F_71 ( * V_94 , F_50 ) ;
F_72 ( * V_94 , F_51 ) ;
F_73 ( * V_94 , F_52 ) ;
return 1 ;
default:
return 0 ;
}
F_71 ( * V_94 , F_1 ) ;
F_72 ( * V_94 , F_12 ) ;
F_73 ( * V_94 , F_10 ) ;
return 1 ;
}
