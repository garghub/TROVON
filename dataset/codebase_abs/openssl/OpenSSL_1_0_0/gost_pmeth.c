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
return 1 ;
case V_25 :
V_15 -> V_6 = ( int ) V_13 ;
return 1 ;
case V_26 :
V_15 -> V_12 = F_3 ( ( int ) V_13 ) ;
memcpy ( V_15 -> V_12 , V_14 , ( int ) V_13 ) ;
return 1 ;
case V_27 :
if ( V_13 == 0 || V_13 == 1 )
return 1 ;
if ( V_13 == 2 )
return V_15 -> V_28 ;
if ( V_13 == 3 )
return ( V_15 -> V_28 = 1 ) ;
return - 2 ;
}
return - 2 ;
}
static int F_17 ( T_1 * V_1 ,
const char * type , const char * V_29 )
{
int V_30 = 0 ;
if( ! strcmp ( type , V_31 ) )
{
if ( ! V_29 )
{
return 0 ;
}
if ( strlen ( V_29 ) == 1 )
{
switch( toupper ( V_29 [ 0 ] ) )
{
case 'A' :
V_30 = V_32 ;
break;
case 'B' :
V_30 = V_33 ;
break;
case 'C' :
V_30 = V_34 ;
break;
case 'D' :
V_30 = V_35 ;
break;
default:
return 0 ;
break;
}
}
else if ( ( strlen ( V_29 ) == 2 ) && ( toupper ( V_29 [ 0 ] ) == 'X' ) )
{
switch ( toupper ( V_29 [ 1 ] ) )
{
case 'A' :
V_30 = V_36 ;
break;
case 'B' :
V_30 = V_37 ;
break;
case 'C' :
V_30 = V_38 ;
break;
default:
return 0 ;
break;
}
}
else
{
T_3 * V_39 = V_40 ;
V_30 = F_18 ( V_29 ) ;
if ( V_30 == V_41 )
{
return 0 ;
}
for (; V_39 -> V_42 != V_41 ; V_39 ++ )
{
if ( V_39 -> V_42 == V_30 ) break;
}
if ( V_39 -> V_42 == V_41 )
{
F_16 ( V_43 ,
V_44 ) ;
return 0 ;
}
}
return F_14 ( V_1 , V_25 ,
V_30 , NULL ) ;
}
return - 2 ;
}
static int F_19 ( T_1 * V_1 ,
const char * type , const char * V_29 )
{
int V_30 = 0 ;
if( ! strcmp ( type , V_31 ) )
{
if ( ! V_29 )
{
return 0 ;
}
if ( strlen ( V_29 ) == 1 )
{
switch( toupper ( V_29 [ 0 ] ) )
{
case 'A' :
V_30 = V_45 ;
break;
case 'B' :
V_30 = V_46 ;
break;
case 'C' :
V_30 = V_47 ;
break;
case '0' :
V_30 = V_48 ;
break;
default:
return 0 ;
break;
}
}
else if ( ( strlen ( V_29 ) == 2 ) && ( toupper ( V_29 [ 0 ] ) == 'X' ) )
{
switch ( toupper ( V_29 [ 1 ] ) )
{
case 'A' :
V_30 = V_49 ;
break;
case 'B' :
V_30 = V_50 ;
break;
default:
return 0 ;
break;
}
}
else
{
T_4 * V_39 = V_51 ;
V_30 = F_18 ( V_29 ) ;
if ( V_30 == V_41 )
{
return 0 ;
}
for (; V_39 -> V_42 != V_41 ; V_39 ++ )
{
if ( V_39 -> V_42 == V_30 ) break;
}
if ( V_39 -> V_42 == V_41 )
{
F_16 ( V_52 ,
V_44 ) ;
return 0 ;
}
}
return F_14 ( V_1 , V_25 ,
V_30 , NULL ) ;
}
return - 2 ;
}
static int F_20 ( T_1 * V_1 ) {
return 1 ;
}
static int F_21 ( T_1 * V_1 , T_2 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_1 ) ;
T_5 * V_53 = NULL ;
if ( V_3 -> V_6 == V_41 )
{
F_16 ( V_54 ,
V_55 ) ;
return 0 ;
}
V_53 = F_22 () ;
if ( ! F_23 ( V_53 , V_3 -> V_6 ) )
{
F_24 ( V_53 ) ;
return 0 ;
}
F_25 ( V_4 , V_5 , V_53 ) ;
return 1 ;
}
static int F_26 ( T_1 * V_1 , T_2 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_1 ) ;
T_6 * V_56 = NULL ;
if ( V_3 -> V_6 == V_41 )
{
F_16 ( V_57 ,
V_55 ) ;
return 0 ;
}
if ( ! V_56 )
V_56 = F_27 () ;
if ( ! F_28 ( V_56 , V_3 -> V_6 ) )
{
F_29 ( V_56 ) ;
return 0 ;
}
F_25 ( V_4 , V_7 , V_56 ) ;
return 1 ;
}
static int F_30 ( T_1 * V_1 , T_2 * V_4 )
{
T_5 * V_53 ;
if ( ! F_21 ( V_1 , V_4 ) ) return 0 ;
V_53 = F_4 ( V_4 ) ;
F_31 ( V_53 ) ;
return 1 ;
}
static int F_32 ( T_1 * V_1 , T_2 * V_4 )
{
T_6 * V_56 ;
if ( ! F_26 ( V_1 , V_4 ) ) return 0 ;
V_56 = F_4 ( V_4 ) ;
F_33 ( V_56 ) ;
return 1 ;
}
static int F_34 ( T_1 * V_1 , unsigned char * V_58 , T_7 * V_59 ,
const unsigned char * V_60 , T_7 V_61 )
{
T_8 * V_62 = NULL ;
T_2 * V_4 = F_2 ( V_1 ) ;
if ( ! V_59 ) return 0 ;
if ( ! V_58 )
{
* V_59 = 64 ;
return 1 ;
}
V_62 = F_35 ( V_60 , V_61 , F_4 ( V_4 ) ) ;
if ( ! V_62 )
{
return 0 ;
}
return F_36 ( V_62 , 32 , V_58 , V_59 ) ;
}
static int F_37 ( T_1 * V_1 , unsigned char * V_58 , T_7 * V_59 ,
const unsigned char * V_60 , T_7 V_61 )
{
T_8 * V_62 = NULL ;
T_2 * V_4 = F_2 ( V_1 ) ;
if ( ! V_59 ) return 0 ;
if ( ! V_58 )
{
* V_59 = 64 ;
return 1 ;
}
V_62 = F_38 ( V_60 , V_61 , F_4 ( V_4 ) ) ;
if ( ! V_62 )
{
return 0 ;
}
return F_36 ( V_62 , 32 , V_58 , V_59 ) ;
}
static int F_39 ( T_1 * V_1 , const unsigned char * V_58 ,
T_7 V_59 , const unsigned char * V_60 , T_7 V_61 )
{
int V_63 = 0 ;
T_2 * V_64 = F_2 ( V_1 ) ;
T_8 * V_65 = F_40 ( V_58 , V_59 ) ;
if ( ! V_65 ) return 0 ;
if ( V_64 ) V_63 = F_41 ( V_60 , V_61 , V_65 , F_4 ( V_64 ) ) ;
F_42 ( V_65 ) ;
return V_63 ;
}
static int F_43 ( T_1 * V_1 , const unsigned char * V_58 ,
T_7 V_59 , const unsigned char * V_60 , T_7 V_61 )
{
int V_63 = 0 ;
T_2 * V_64 = F_2 ( V_1 ) ;
T_8 * V_65 = F_40 ( V_58 , V_59 ) ;
if ( ! V_65 ) return 0 ;
#ifdef F_44
fprintf ( V_66 , L_1 ) ;
F_45 ( V_66 , V_65 -> V_67 ) ;
fprintf ( V_66 , L_2 ) ;
F_45 ( V_66 , V_65 -> V_65 ) ;
fprintf ( V_66 , L_3 ) ;
#endif
if ( V_64 ) V_63 = F_46 ( V_60 , V_61 , V_65 , F_4 ( V_64 ) ) ;
F_42 ( V_65 ) ;
return V_63 ;
}
static int F_47 ( T_1 * V_1 )
{
return 1 ;
}
static int F_48 ( T_1 * V_1 )
{
return 1 ;
}
static int F_49 ( T_1 * V_1 )
{
struct V_68 * V_3 ;
V_3 = F_3 ( sizeof( struct V_68 ) ) ;
if ( ! V_3 ) return 0 ;
memset ( V_3 , 0 , sizeof( struct V_68 ) ) ;
F_9 ( V_1 , V_3 ) ;
return 1 ;
}
static void F_50 ( T_1 * V_1 )
{
struct V_68 * V_3 = F_11 ( V_1 ) ;
F_13 ( V_3 ) ;
}
static int F_51 ( T_1 * V_8 , T_1 * V_9 )
{
struct V_68 * V_10 , * V_11 ;
if ( ! F_49 ( V_8 ) )
{
return 0 ;
}
V_11 = F_11 ( V_9 ) ;
V_10 = F_11 ( V_8 ) ;
* V_10 = * V_11 ;
return 1 ;
}
static int F_52 ( T_1 * V_1 , int type , int V_13 , void * V_14 )
{
struct V_68 * V_3 =
(struct V_68 * ) F_11 ( V_1 ) ;
switch ( type )
{
case V_16 :
{
if ( F_15 ( ( const V_17 * ) V_14 ) != V_69 )
{
F_16 ( V_70 , V_20 ) ;
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
case V_71 :
if ( V_13 != 32 )
{
F_16 ( V_70 ,
V_72 ) ;
return 0 ;
}
memcpy ( V_3 -> V_73 , V_14 , 32 ) ;
V_3 -> V_74 = 1 ;
return 1 ;
case V_75 :
{
T_9 * V_76 = V_14 ;
void * V_73 ;
if ( ! V_3 -> V_74 )
{
T_2 * V_4 = F_2 ( V_1 ) ;
if ( ! V_4 )
{
F_16 ( V_70 , V_77 ) ;
return 0 ;
}
V_73 = F_4 ( V_4 ) ;
if ( ! V_73 )
{
F_16 ( V_70 , V_77 ) ;
return 0 ;
}
} else {
V_73 = & ( V_3 -> V_73 ) ;
}
return V_76 -> V_78 -> V_79 ( V_76 , V_80 , 32 , V_73 ) ;
}
}
return - 2 ;
}
static int F_53 ( T_1 * V_1 ,
const char * type , const char * V_29 )
{
if ( ! strcmp ( type , V_81 ) )
{
if ( strlen ( V_29 ) != 32 )
{
F_16 ( V_82 ,
V_72 ) ;
return 0 ;
}
return F_52 ( V_1 , V_71 ,
32 , ( char * ) V_29 ) ;
}
if ( ! strcmp ( type , V_83 ) )
{
long V_84 ; int V_85 ;
unsigned char * V_86 = F_54 ( V_29 , & V_84 ) ;
if ( V_84 != 32 )
{
F_16 ( V_82 ,
V_72 ) ;
return 0 ;
}
V_85 = F_52 ( V_1 , V_71 ,
32 , V_86 ) ;
F_13 ( V_86 ) ;
return V_85 ;
}
return - 2 ;
}
static int F_55 ( T_1 * V_1 , T_2 * V_4 )
{
struct V_68 * V_3 = F_11 ( V_1 ) ;
unsigned char * V_87 ;
if ( ! V_3 -> V_74 )
{
F_16 ( V_88 , V_77 ) ;
return 0 ;
}
V_87 = F_3 ( 32 ) ;
memcpy ( V_87 , V_3 -> V_73 , 32 ) ;
F_25 ( V_4 , V_69 , V_87 ) ;
return 1 ;
}
static int F_56 ( T_1 * V_1 , T_9 * V_76 )
{
return 1 ;
}
static int F_57 ( T_1 * V_1 , unsigned char * V_58 , T_7 * V_59 , T_9 * V_76 )
{
unsigned int V_89 = * V_59 ;
int V_85 ;
if ( ! V_58 )
{
* V_59 = 4 ;
return 1 ;
}
V_85 = F_58 ( V_76 , V_58 , & V_89 ) ;
* V_59 = V_89 ;
return V_85 ;
}
int F_59 ( int V_90 , T_10 * * V_91 , int V_92 )
{
* V_91 = F_60 ( V_90 , V_92 ) ;
if ( ! * V_91 ) return 0 ;
switch ( V_90 )
{
case V_5 :
F_61 ( * V_91 , F_14 , F_17 ) ;
F_62 ( * V_91 , NULL , F_30 ) ;
F_63 ( * V_91 , NULL , F_34 ) ;
F_64 ( * V_91 , NULL , F_39 ) ;
F_65 ( * V_91 ,
F_47 , V_93 ) ;
F_66 ( * V_91 , NULL , V_94 ) ;
F_67 ( * V_91 ,
F_48 , V_95 ) ;
F_68 ( * V_91 , F_20 , F_21 ) ;
break;
case V_7 :
F_61 ( * V_91 , F_14 , F_19 ) ;
F_63 ( * V_91 , NULL , F_37 ) ;
F_64 ( * V_91 , NULL , F_43 ) ;
F_62 ( * V_91 , NULL , F_32 ) ;
F_65 ( * V_91 ,
F_47 , V_96 ) ;
F_66 ( * V_91 , NULL , V_97 ) ;
F_67 ( * V_91 ,
F_48 , V_98 ) ;
F_68 ( * V_91 , F_20 , F_26 ) ;
break;
case V_69 :
F_61 ( * V_91 , F_52 , F_53 ) ;
F_69 ( * V_91 , F_56 , F_57 ) ;
F_62 ( * V_91 , NULL , F_55 ) ;
F_70 ( * V_91 , F_49 ) ;
F_71 ( * V_91 , F_50 ) ;
F_72 ( * V_91 , F_51 ) ;
return 1 ;
default:
return 0 ;
}
F_70 ( * V_91 , F_1 ) ;
F_71 ( * V_91 , F_12 ) ;
F_72 ( * V_91 , F_10 ) ;
return 1 ;
}
