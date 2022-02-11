static int F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 ;
T_2 * V_4 = F_2 ( V_1 ) ;
V_3 = F_3 ( sizeof( struct V_2 ) ) ;
if ( ! V_3 )
return 0 ;
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
if ( V_4 && F_4 ( V_4 ) ) {
switch ( F_5 ( V_4 ) ) {
case V_5 :
V_3 -> V_6 = F_6 ( F_4 ( V_4 ) ) ;
break;
case V_7 :
V_3 -> V_6 =
F_7 ( F_8
( F_4 ( ( T_2 * ) V_4 ) ) ) ;
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
if ( ! F_1 ( V_8 ) ) {
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
if ( V_3 -> V_12 )
F_13 ( V_3 -> V_12 ) ;
F_13 ( V_3 ) ;
}
static int F_14 ( T_1 * V_1 , int type , int V_13 , void * V_14 )
{
struct V_2 * V_15 =
(struct V_2 * ) F_11 ( V_1 ) ;
switch ( type ) {
case V_16 :
{
if ( F_15 ( ( const V_17 * ) V_14 ) != V_18 ) {
F_16 ( V_19 , V_20 ) ;
return 0 ;
}
V_15 -> V_21 = ( V_17 * ) V_14 ;
return 1 ;
}
break;
case V_22 :
* ( const V_17 * * ) V_14 = V_15 -> V_21 ;
return 1 ;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
#ifndef F_17
case V_27 :
case V_28 :
case V_29 :
#endif
return 1 ;
case V_30 :
V_15 -> V_6 = ( int ) V_13 ;
return 1 ;
case V_31 :
V_15 -> V_12 = F_3 ( ( int ) V_13 ) ;
memcpy ( V_15 -> V_12 , V_14 , ( int ) V_13 ) ;
return 1 ;
case V_32 :
if ( V_13 == 0 || V_13 == 1 )
return 1 ;
if ( V_13 == 2 )
return V_15 -> V_33 ;
if ( V_13 == 3 )
return ( V_15 -> V_33 = 1 ) ;
return - 2 ;
}
return - 2 ;
}
static int F_18 ( T_1 * V_1 ,
const char * type , const char * V_34 )
{
int V_35 = 0 ;
if ( ! strcmp ( type , V_36 ) ) {
if ( ! V_34 ) {
return 0 ;
}
if ( strlen ( V_34 ) == 1 ) {
switch ( toupper ( ( unsigned char ) V_34 [ 0 ] ) ) {
case 'A' :
V_35 = V_37 ;
break;
case 'B' :
V_35 = V_38 ;
break;
case 'C' :
V_35 = V_39 ;
break;
case 'D' :
V_35 = V_40 ;
break;
default:
return 0 ;
break;
}
} else if ( ( strlen ( V_34 ) == 2 )
&& ( toupper ( ( unsigned char ) V_34 [ 0 ] ) == 'X' ) ) {
switch ( toupper ( ( unsigned char ) V_34 [ 1 ] ) ) {
case 'A' :
V_35 = V_41 ;
break;
case 'B' :
V_35 = V_42 ;
break;
case 'C' :
V_35 = V_43 ;
break;
default:
return 0 ;
break;
}
} else {
T_3 * V_44 = V_45 ;
V_35 = F_19 ( V_34 ) ;
if ( V_35 == V_46 ) {
return 0 ;
}
for (; V_44 -> V_47 != V_46 ; V_44 ++ ) {
if ( V_44 -> V_47 == V_35 )
break;
}
if ( V_44 -> V_47 == V_46 ) {
F_16 ( V_48 , V_49 ) ;
return 0 ;
}
}
return F_14 ( V_1 , V_30 ,
V_35 , NULL ) ;
}
return - 2 ;
}
static int F_20 ( T_1 * V_1 ,
const char * type , const char * V_34 )
{
int V_35 = 0 ;
if ( ! strcmp ( type , V_36 ) ) {
if ( ! V_34 ) {
return 0 ;
}
if ( strlen ( V_34 ) == 1 ) {
switch ( toupper ( ( unsigned char ) V_34 [ 0 ] ) ) {
case 'A' :
V_35 = V_50 ;
break;
case 'B' :
V_35 = V_51 ;
break;
case 'C' :
V_35 = V_52 ;
break;
case '0' :
V_35 = V_53 ;
break;
default:
return 0 ;
break;
}
} else if ( ( strlen ( V_34 ) == 2 )
&& ( toupper ( ( unsigned char ) V_34 [ 0 ] ) == 'X' ) ) {
switch ( toupper ( ( unsigned char ) V_34 [ 1 ] ) ) {
case 'A' :
V_35 = V_54 ;
break;
case 'B' :
V_35 = V_55 ;
break;
default:
return 0 ;
break;
}
} else {
T_4 * V_44 = V_56 ;
V_35 = F_19 ( V_34 ) ;
if ( V_35 == V_46 ) {
return 0 ;
}
for (; V_44 -> V_47 != V_46 ; V_44 ++ ) {
if ( V_44 -> V_47 == V_35 )
break;
}
if ( V_44 -> V_47 == V_46 ) {
F_16 ( V_57 , V_49 ) ;
return 0 ;
}
}
return F_14 ( V_1 , V_30 ,
V_35 , NULL ) ;
}
return - 2 ;
}
static int F_21 ( T_1 * V_1 )
{
return 1 ;
}
static int F_22 ( T_1 * V_1 , T_2 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_1 ) ;
T_5 * V_58 = NULL ;
if ( V_3 -> V_6 == V_46 ) {
F_16 ( V_59 , V_60 ) ;
return 0 ;
}
V_58 = F_23 () ;
if ( ! F_24 ( V_58 , V_3 -> V_6 ) ) {
F_25 ( V_58 ) ;
return 0 ;
}
F_26 ( V_4 , V_5 , V_58 ) ;
return 1 ;
}
static int F_27 ( T_1 * V_1 , T_2 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_1 ) ;
T_6 * V_61 = NULL ;
if ( V_3 -> V_6 == V_46 ) {
F_16 ( V_62 , V_60 ) ;
return 0 ;
}
if ( ! V_61 )
V_61 = F_28 () ;
if ( ! F_29 ( V_61 , V_3 -> V_6 ) ) {
F_30 ( V_61 ) ;
return 0 ;
}
F_26 ( V_4 , V_7 , V_61 ) ;
return 1 ;
}
static int F_31 ( T_1 * V_1 , T_2 * V_4 )
{
T_5 * V_58 ;
if ( ! F_22 ( V_1 , V_4 ) )
return 0 ;
V_58 = F_4 ( V_4 ) ;
F_32 ( V_58 ) ;
return 1 ;
}
static int F_33 ( T_1 * V_1 , T_2 * V_4 )
{
T_6 * V_61 ;
if ( ! F_27 ( V_1 , V_4 ) )
return 0 ;
V_61 = F_4 ( V_4 ) ;
F_34 ( V_61 ) ;
return 1 ;
}
static int F_35 ( T_1 * V_1 , unsigned char * V_63 ,
T_7 * V_64 , const unsigned char * V_65 ,
T_7 V_66 )
{
T_8 * V_67 = NULL ;
T_2 * V_4 = F_2 ( V_1 ) ;
if ( ! V_64 )
return 0 ;
if ( ! V_63 ) {
* V_64 = 64 ;
return 1 ;
}
V_67 = F_36 ( V_65 , V_66 , F_4 ( V_4 ) ) ;
if ( ! V_67 ) {
return 0 ;
}
return F_37 ( V_67 , 32 , V_63 , V_64 ) ;
}
static int F_38 ( T_1 * V_1 , unsigned char * V_63 ,
T_7 * V_64 , const unsigned char * V_65 ,
T_7 V_66 )
{
T_8 * V_67 = NULL ;
T_2 * V_4 = F_2 ( V_1 ) ;
if ( ! V_64 )
return 0 ;
if ( ! V_63 ) {
* V_64 = 64 ;
return 1 ;
}
V_67 = F_39 ( V_65 , V_66 , F_4 ( V_4 ) ) ;
if ( ! V_67 ) {
return 0 ;
}
return F_37 ( V_67 , 32 , V_63 , V_64 ) ;
}
static int F_40 ( T_1 * V_1 , const unsigned char * V_63 ,
T_7 V_64 , const unsigned char * V_65 ,
T_7 V_66 )
{
int V_68 = 0 ;
T_2 * V_69 = F_2 ( V_1 ) ;
T_8 * V_70 = F_41 ( V_63 , V_64 ) ;
if ( ! V_70 )
return 0 ;
if ( V_69 )
V_68 = F_42 ( V_65 , V_66 , V_70 , F_4 ( V_69 ) ) ;
F_43 ( V_70 ) ;
return V_68 ;
}
static int F_44 ( T_1 * V_1 , const unsigned char * V_63 ,
T_7 V_64 , const unsigned char * V_65 ,
T_7 V_66 )
{
int V_68 = 0 ;
T_2 * V_69 = F_2 ( V_1 ) ;
T_8 * V_70 = F_41 ( V_63 , V_64 ) ;
if ( ! V_70 )
return 0 ;
#ifdef F_45
fprintf ( V_71 , L_1 ) ;
F_46 ( V_71 , V_70 -> V_72 ) ;
fprintf ( V_71 , L_2 ) ;
F_46 ( V_71 , V_70 -> V_70 ) ;
fprintf ( V_71 , L_3 ) ;
#endif
if ( V_69 )
V_68 = F_47 ( V_65 , V_66 , V_70 , F_4 ( V_69 ) ) ;
F_43 ( V_70 ) ;
return V_68 ;
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
struct V_73 * V_3 ;
V_3 = F_3 ( sizeof( struct V_73 ) ) ;
if ( ! V_3 )
return 0 ;
memset ( V_3 , 0 , sizeof( struct V_73 ) ) ;
F_9 ( V_1 , V_3 ) ;
return 1 ;
}
static void F_51 ( T_1 * V_1 )
{
struct V_73 * V_3 = F_11 ( V_1 ) ;
F_13 ( V_3 ) ;
}
static int F_52 ( T_1 * V_8 , T_1 * V_9 )
{
struct V_73 * V_10 , * V_11 ;
if ( ! F_50 ( V_8 ) ) {
return 0 ;
}
V_11 = F_11 ( V_9 ) ;
V_10 = F_11 ( V_8 ) ;
* V_10 = * V_11 ;
return 1 ;
}
static int F_53 ( T_1 * V_1 , int type , int V_13 , void * V_14 )
{
struct V_73 * V_3 =
(struct V_73 * ) F_11 ( V_1 ) ;
switch ( type ) {
case V_16 :
{
if ( F_15 ( ( const V_17 * ) V_14 ) != V_74 ) {
F_16 ( V_75 ,
V_20 ) ;
return 0 ;
}
V_3 -> V_21 = ( V_17 * ) V_14 ;
return 1 ;
}
break;
case V_22 :
* ( const V_17 * * ) V_14 = V_3 -> V_21 ;
return 1 ;
case V_23 :
case V_24 :
case V_25 :
return 1 ;
case V_76 :
if ( V_13 != 32 ) {
F_16 ( V_75 , V_77 ) ;
return 0 ;
}
memcpy ( V_3 -> V_78 , V_14 , 32 ) ;
V_3 -> V_79 = 1 ;
return 1 ;
case V_26 :
{
T_9 * V_80 = V_14 ;
void * V_78 ;
if ( ! V_3 -> V_79 ) {
T_2 * V_4 = F_2 ( V_1 ) ;
if ( ! V_4 ) {
F_16 ( V_75 ,
V_81 ) ;
return 0 ;
}
V_78 = F_4 ( V_4 ) ;
if ( ! V_78 ) {
F_16 ( V_75 ,
V_81 ) ;
return 0 ;
}
} else {
V_78 = & ( V_3 -> V_78 ) ;
}
return V_80 -> V_82 -> V_83 ( V_80 , V_84 , 32 , V_78 ) ;
}
}
return - 2 ;
}
static int F_54 ( T_1 * V_1 ,
const char * type , const char * V_34 )
{
if ( ! strcmp ( type , V_85 ) ) {
if ( strlen ( V_34 ) != 32 ) {
F_16 ( V_86 ,
V_77 ) ;
return 0 ;
}
return F_53 ( V_1 , V_76 ,
32 , ( char * ) V_34 ) ;
}
if ( ! strcmp ( type , V_87 ) ) {
long V_88 ;
int V_89 ;
unsigned char * V_90 = F_55 ( V_34 , & V_88 ) ;
if ( V_88 != 32 ) {
F_16 ( V_86 ,
V_77 ) ;
F_13 ( V_90 ) ;
return 0 ;
}
V_89 = F_53 ( V_1 , V_76 , 32 , V_90 ) ;
F_13 ( V_90 ) ;
return V_89 ;
}
return - 2 ;
}
static int F_56 ( T_1 * V_1 , T_2 * V_4 )
{
struct V_73 * V_3 = F_11 ( V_1 ) ;
unsigned char * V_91 ;
if ( ! V_3 -> V_79 ) {
F_16 ( V_92 , V_81 ) ;
return 0 ;
}
V_91 = F_3 ( 32 ) ;
memcpy ( V_91 , V_3 -> V_78 , 32 ) ;
F_26 ( V_4 , V_74 , V_91 ) ;
return 1 ;
}
static int F_57 ( T_1 * V_1 , T_9 * V_80 )
{
return 1 ;
}
static int F_58 ( T_1 * V_1 , unsigned char * V_63 ,
T_7 * V_64 , T_9 * V_80 )
{
unsigned int V_93 = * V_64 ;
int V_89 ;
if ( ! V_63 ) {
* V_64 = 4 ;
return 1 ;
}
V_89 = F_59 ( V_80 , V_63 , & V_93 ) ;
* V_64 = V_93 ;
return V_89 ;
}
int F_60 ( int V_94 , T_10 * * V_95 , int V_96 )
{
* V_95 = F_61 ( V_94 , V_96 ) ;
if ( ! * V_95 )
return 0 ;
switch ( V_94 ) {
case V_5 :
F_62 ( * V_95 , F_14 , F_18 ) ;
F_63 ( * V_95 , NULL , F_31 ) ;
F_64 ( * V_95 , NULL , F_35 ) ;
F_65 ( * V_95 , NULL , F_40 ) ;
F_66 ( * V_95 ,
F_48 ,
V_97 ) ;
F_67 ( * V_95 , NULL , V_98 ) ;
F_68 ( * V_95 ,
F_49 , V_99 ) ;
F_69 ( * V_95 , F_21 ,
F_22 ) ;
break;
case V_7 :
F_62 ( * V_95 , F_14 , F_20 ) ;
F_64 ( * V_95 , NULL , F_38 ) ;
F_65 ( * V_95 , NULL , F_44 ) ;
F_63 ( * V_95 , NULL , F_33 ) ;
F_66 ( * V_95 ,
F_48 ,
V_100 ) ;
F_67 ( * V_95 , NULL , V_101 ) ;
F_68 ( * V_95 ,
F_49 , V_102 ) ;
F_69 ( * V_95 , F_21 ,
F_27 ) ;
break;
case V_74 :
F_62 ( * V_95 , F_53 ,
F_54 ) ;
F_70 ( * V_95 , F_57 ,
F_58 ) ;
F_63 ( * V_95 , NULL , F_56 ) ;
F_71 ( * V_95 , F_50 ) ;
F_72 ( * V_95 , F_51 ) ;
F_73 ( * V_95 , F_52 ) ;
return 1 ;
default:
return 0 ;
}
F_71 ( * V_95 , F_1 ) ;
F_72 ( * V_95 , F_12 ) ;
F_73 ( * V_95 , F_10 ) ;
return 1 ;
}
