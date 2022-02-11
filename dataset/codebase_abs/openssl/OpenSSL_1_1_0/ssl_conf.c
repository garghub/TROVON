static void F_1 ( T_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 , int V_4 )
{
T_2 * V_5 ;
if ( V_1 -> V_6 == NULL )
return;
if ( V_2 & V_7 )
V_4 ^= 1 ;
switch ( V_2 & V_8 ) {
case V_9 :
V_5 = V_1 -> V_10 ;
break;
case V_11 :
V_5 = V_1 -> V_12 ;
break;
case V_13 :
V_5 = V_1 -> V_6 ;
break;
default:
return;
}
if ( V_4 )
* V_5 |= V_3 ;
else
* V_5 &= ~ V_3 ;
}
static int F_2 ( T_1 * V_1 , const T_3 * V_14 ,
const char * V_15 , int V_16 , int V_4 )
{
if ( ! ( V_1 -> V_17 & V_14 -> V_2 & V_18 ) )
return 0 ;
if ( V_16 == - 1 ) {
if ( strcmp ( V_14 -> V_15 , V_15 ) )
return 0 ;
} else if ( V_14 -> V_16 != V_16 || strncasecmp ( V_14 -> V_15 , V_15 , V_16 ) )
return 0 ;
F_1 ( V_1 , V_14 -> V_2 , V_14 -> V_3 , V_4 ) ;
return 1 ;
}
static int F_3 ( const char * V_19 , int V_20 , void * V_21 )
{
T_1 * V_1 = V_21 ;
T_4 V_22 ;
const T_3 * V_14 ;
int V_4 = 1 ;
if ( V_19 == NULL )
return 0 ;
if ( V_20 != - 1 ) {
if ( * V_19 == '+' ) {
V_19 ++ ;
V_20 -- ;
V_4 = 1 ;
} else if ( * V_19 == '-' ) {
V_19 ++ ;
V_20 -- ;
V_4 = 0 ;
}
}
for ( V_22 = 0 , V_14 = V_1 -> V_14 ; V_22 < V_1 -> V_23 ; V_22 ++ , V_14 ++ ) {
if ( F_2 ( V_1 , V_14 , V_19 , V_20 , V_4 ) )
return 1 ;
}
return 0 ;
}
static int F_4 ( T_1 * V_1 , const char * V_24 )
{
int V_25 ;
if ( V_1 -> V_26 )
V_25 = F_5 ( V_1 -> V_26 , V_24 ) ;
else
V_25 = F_6 ( V_1 -> V_27 , V_24 ) ;
return V_25 > 0 ;
}
static int F_7 ( T_1 * V_1 , const char * V_24 )
{
int V_25 ;
if ( V_1 -> V_26 )
V_25 = F_8 ( V_1 -> V_26 , V_24 ) ;
else
V_25 = F_9 ( V_1 -> V_27 , V_24 ) ;
return V_25 > 0 ;
}
static int F_10 ( T_1 * V_1 , const char * V_24 )
{
int V_25 ;
if ( V_1 -> V_26 )
V_25 = F_11 ( V_1 -> V_26 , V_24 ) ;
else
V_25 = F_12 ( V_1 -> V_27 , V_24 ) ;
return V_25 > 0 ;
}
static int F_13 ( T_1 * V_1 , const char * V_24 )
{
int V_25 = 1 ;
T_5 * V_28 ;
int V_29 ;
V_29 = F_14 ( V_24 ) ;
if ( V_29 == V_30 )
V_29 = F_15 ( V_24 ) ;
if ( V_29 == 0 )
return 0 ;
V_28 = F_16 ( V_29 ) ;
if ( ! V_28 )
return 0 ;
if ( V_1 -> V_27 )
V_25 = F_17 ( V_1 -> V_27 , V_28 ) ;
else if ( V_1 -> V_26 )
V_25 = F_18 ( V_1 -> V_26 , V_28 ) ;
F_19 ( V_28 ) ;
return V_25 > 0 ;
}
static int F_20 ( T_1 * V_1 , const char * V_24 )
{
int V_25 = 1 ;
if ( V_1 -> V_27 )
V_25 = F_21 ( V_1 -> V_27 , V_24 ) ;
if ( V_1 -> V_26 )
V_25 = F_22 ( V_1 -> V_26 , V_24 ) ;
return V_25 > 0 ;
}
static int F_23 ( T_1 * V_1 , const char * V_24 )
{
static const T_3 V_31 [] = {
F_24 ( L_1 , V_32 ) ,
F_24 ( L_2 , V_33 ) ,
F_24 ( L_3 , V_34 ) ,
F_24 ( L_4 , V_35 ) ,
F_24 ( L_5 , V_36 ) ,
F_24 ( L_6 , V_37 ) ,
F_24 ( L_7 , V_38 ) ,
F_24 ( L_8 , SSL_OP_NO_DTLSv1_2)
} ;
V_1 -> V_14 = V_31 ;
V_1 -> V_23 = F_25 ( V_31 ) ;
return F_26 ( V_24 , ',' , 1 , F_3 , V_1 ) ;
}
static int F_27 ( const char * V_24 )
{
struct V_39 {
const char * V_15 ;
int V_40 ;
};
static const struct V_39 V_41 [] = {
{ L_9 , 0 } ,
{ L_3 , V_42 } ,
{ L_4 , V_43 } ,
{ L_5 , V_44 } ,
{ L_6 , V_45 } ,
{ L_7 , V_46 } ,
{ L_8 , V_47 }
} ;
T_4 V_22 ;
T_4 V_48 = F_25 ( V_41 ) ;
for ( V_22 = 0 ; V_22 < V_48 ; V_22 ++ )
if ( strcmp ( V_41 [ V_22 ] . V_15 , V_24 ) == 0 )
return V_41 [ V_22 ] . V_40 ;
return - 1 ;
}
static int F_28 ( T_1 * V_1 , const char * V_24 , int * V_49 )
{
int V_50 ;
int V_51 ;
if ( V_1 -> V_27 != NULL )
V_50 = V_1 -> V_27 -> V_52 -> V_40 ;
else if ( V_1 -> V_26 != NULL )
V_50 = V_1 -> V_26 -> V_27 -> V_52 -> V_40 ;
else
return 0 ;
if ( ( V_51 = F_27 ( V_24 ) ) < 0 )
return 0 ;
return F_29 ( V_50 , V_51 , V_49 ) ;
}
static int F_30 ( T_1 * V_1 , const char * V_24 )
{
return F_28 ( V_1 , V_24 , V_1 -> V_53 ) ;
}
static int F_31 ( T_1 * V_1 , const char * V_24 )
{
return F_28 ( V_1 , V_24 , V_1 -> V_54 ) ;
}
static int F_32 ( T_1 * V_1 , const char * V_24 )
{
static const T_3 V_55 [] = {
F_24 ( L_10 , V_56 ) ,
F_24 ( L_11 ,
V_57 ) ,
F_33 ( L_12 , V_58 ) ,
F_24 ( L_13 , V_59 ) ,
F_34 ( L_14 , V_60 ) ,
F_34 ( L_15 ,
V_61 ) ,
F_34 ( L_16 , V_62 ) ,
F_34 ( L_17 , V_63 ) ,
F_33 ( L_18 ,
V_64 ) ,
} ;
if ( V_24 == NULL )
return - 3 ;
V_1 -> V_14 = V_55 ;
V_1 -> V_23 = F_25 ( V_55 ) ;
return F_26 ( V_24 , ',' , 1 , F_3 , V_1 ) ;
}
static int F_35 ( T_1 * V_1 , const char * V_24 )
{
static const T_3 V_65 [] = {
F_36 ( L_19 , V_66 ) ,
F_37 ( L_20 , V_66 ) ,
F_37 ( L_21 ,
V_66 | V_67 ) ,
F_37 ( L_22 , SSL_VERIFY_PEER | SSL_VERIFY_CLIENT_ONCE)
} ;
if ( V_24 == NULL )
return - 3 ;
V_1 -> V_14 = V_65 ;
V_1 -> V_23 = F_25 ( V_65 ) ;
return F_26 ( V_24 , ',' , 1 , F_3 , V_1 ) ;
}
static int F_38 ( T_1 * V_1 , const char * V_24 )
{
int V_25 = 1 ;
T_6 * V_68 = NULL ;
if ( V_1 -> V_27 ) {
V_25 = F_39 ( V_1 -> V_27 , V_24 ) ;
V_68 = V_1 -> V_27 -> V_69 ;
}
if ( V_1 -> V_26 ) {
V_25 = F_40 ( V_1 -> V_26 , V_24 ) ;
V_68 = V_1 -> V_26 -> V_69 ;
}
if ( V_25 > 0 && V_68 && V_1 -> V_17 & V_70 ) {
char * * V_71 = & V_1 -> V_72 [ V_68 -> V_73 - V_68 -> V_74 ] ;
F_41 ( * V_71 ) ;
* V_71 = F_42 ( V_24 ) ;
if ( ! * V_71 )
V_25 = 0 ;
}
return V_25 > 0 ;
}
static int F_43 ( T_1 * V_1 , const char * V_24 )
{
int V_25 = 1 ;
if ( ! ( V_1 -> V_17 & V_75 ) )
return - 2 ;
if ( V_1 -> V_27 )
V_25 = F_44 ( V_1 -> V_27 , V_24 , V_76 ) ;
if ( V_1 -> V_26 )
V_25 = F_45 ( V_1 -> V_26 , V_24 , V_76 ) ;
return V_25 > 0 ;
}
static int F_46 ( T_1 * V_1 , const char * V_24 )
{
int V_25 = 1 ;
if ( V_1 -> V_27 )
V_25 = F_47 ( V_1 -> V_27 , V_24 ) ;
return V_25 > 0 ;
}
static int F_48 ( T_1 * V_1 ,
const char * V_77 , const char * V_78 , int V_79 )
{
T_6 * V_69 ;
T_7 * * V_80 ;
if ( V_1 -> V_27 )
V_69 = V_1 -> V_27 -> V_69 ;
else if ( V_1 -> V_26 )
V_69 = V_1 -> V_26 -> V_69 ;
else
return 1 ;
V_80 = V_79 ? & V_69 -> V_79 : & V_69 -> V_81 ;
if ( * V_80 == NULL ) {
* V_80 = F_49 () ;
if ( * V_80 == NULL )
return 0 ;
}
return F_50 ( * V_80 , V_77 , V_78 ) > 0 ;
}
static int F_51 ( T_1 * V_1 , const char * V_24 )
{
return F_48 ( V_1 , NULL , V_24 , 0 ) ;
}
static int F_52 ( T_1 * V_1 , const char * V_24 )
{
return F_48 ( V_1 , V_24 , NULL , 0 ) ;
}
static int F_53 ( T_1 * V_1 , const char * V_24 )
{
return F_48 ( V_1 , NULL , V_24 , 1 ) ;
}
static int F_54 ( T_1 * V_1 , const char * V_24 )
{
return F_48 ( V_1 , V_24 , NULL , 1 ) ;
}
static int F_55 ( T_1 * V_1 , const char * V_24 )
{
if ( V_1 -> V_82 == NULL )
V_1 -> V_82 = F_56 () ;
if ( V_1 -> V_82 == NULL )
return 0 ;
return F_57 ( V_1 -> V_82 , V_24 ) ;
}
static int F_58 ( T_1 * V_1 , const char * V_24 )
{
if ( V_1 -> V_82 == NULL )
V_1 -> V_82 = F_56 () ;
if ( V_1 -> V_82 == NULL )
return 0 ;
return F_59 ( V_1 -> V_82 , V_24 ) ;
}
static int F_60 ( T_1 * V_1 , const char * V_24 )
{
int V_25 = 0 ;
T_8 * V_83 = NULL ;
T_9 * V_84 = NULL ;
if ( V_1 -> V_27 || V_1 -> V_26 ) {
V_84 = F_61 ( F_62 () ) ;
if ( V_84 == NULL )
goto V_85;
if ( F_63 ( V_84 , V_24 ) <= 0 )
goto V_85;
V_83 = F_64 ( V_84 , NULL , NULL , NULL ) ;
if ( V_83 == NULL )
goto V_85;
} else
return 1 ;
if ( V_1 -> V_27 )
V_25 = F_65 ( V_1 -> V_27 , V_83 ) ;
if ( V_1 -> V_26 )
V_25 = F_66 ( V_1 -> V_26 , V_83 ) ;
V_85:
F_67 ( V_83 ) ;
F_68 ( V_84 ) ;
return V_25 > 0 ;
}
static int F_69 ( T_1 * V_1 , const char * * V_86 )
{
if ( ! V_86 || ! * V_86 )
return 0 ;
if ( V_1 -> V_87 ) {
if ( strlen ( * V_86 ) <= V_1 -> V_88 )
return 0 ;
if ( V_1 -> V_17 & V_89 &&
strncmp ( * V_86 , V_1 -> V_87 , V_1 -> V_88 ) )
return 0 ;
if ( V_1 -> V_17 & V_90 &&
strncasecmp ( * V_86 , V_1 -> V_87 , V_1 -> V_88 ) )
return 0 ;
* V_86 += V_1 -> V_88 ;
} else if ( V_1 -> V_17 & V_89 ) {
if ( * * V_86 != '-' || ! ( * V_86 ) [ 1 ] )
return 0 ;
* V_86 += 1 ;
}
return 1 ;
}
static int F_70 ( T_1 * V_1 , const T_10 * V_91 )
{
unsigned int V_92 = V_91 -> V_17 ;
unsigned int V_93 = V_1 -> V_17 ;
if ( ( V_92 & V_94 ) && ! ( V_93 & V_94 ) )
return 0 ;
if ( ( V_92 & V_95 ) && ! ( V_93 & V_95 ) )
return 0 ;
if ( ( V_92 & V_75 )
&& ! ( V_93 & V_75 ) )
return 0 ;
return 1 ;
}
static const T_10 * F_71 ( T_1 * V_1 ,
const char * V_96 )
{
const T_10 * V_91 ;
T_4 V_22 ;
if ( V_96 == NULL )
return NULL ;
for ( V_22 = 0 , V_91 = V_97 ; V_22 < F_25 ( V_97 ) ; V_22 ++ , V_91 ++ ) {
if ( F_70 ( V_1 , V_91 ) ) {
if ( V_1 -> V_17 & V_89 ) {
if ( V_91 -> V_98 && strcmp ( V_91 -> V_98 , V_96 ) == 0 )
return V_91 ;
}
if ( V_1 -> V_17 & V_90 ) {
if ( V_91 -> V_99 && strcasecmp ( V_91 -> V_99 , V_96 ) == 0 )
return V_91 ;
}
}
}
return NULL ;
}
static int F_72 ( T_1 * V_1 , const T_10 * V_96 )
{
T_4 V_100 = V_96 - V_97 ;
const T_11 * V_101 ;
if ( V_100 >= F_25 ( V_102 ) )
return 0 ;
V_101 = V_102 + V_100 ;
F_1 ( V_1 , V_101 -> V_2 , V_101 -> V_3 , 1 ) ;
return 1 ;
}
int F_73 ( T_1 * V_1 , const char * V_96 , const char * V_24 )
{
const T_10 * V_103 ;
if ( V_96 == NULL ) {
F_74 ( V_104 , V_105 ) ;
return 0 ;
}
if ( ! F_69 ( V_1 , & V_96 ) )
return - 2 ;
V_103 = F_71 ( V_1 , V_96 ) ;
if ( V_103 ) {
int V_25 ;
if ( V_103 -> V_106 == V_107 ) {
return F_72 ( V_1 , V_103 ) ;
}
if ( V_24 == NULL )
return - 3 ;
V_25 = V_103 -> V_96 ( V_1 , V_24 ) ;
if ( V_25 > 0 )
return 2 ;
if ( V_25 == - 2 )
return - 2 ;
if ( V_1 -> V_17 & V_108 ) {
F_74 ( V_104 , V_109 ) ;
F_75 ( 4 , L_23 , V_96 , L_24 , V_24 ) ;
}
return 0 ;
}
if ( V_1 -> V_17 & V_108 ) {
F_74 ( V_104 , V_110 ) ;
F_75 ( 2 , L_23 , V_96 ) ;
}
return - 2 ;
}
int F_76 ( T_1 * V_1 , int * V_111 , char * * * V_112 )
{
int V_25 ;
const char * V_113 = NULL , * V_114 ;
if ( V_111 && * V_111 == 0 )
return 0 ;
if ( ! V_111 || * V_111 > 0 )
V_113 = * * V_112 ;
if ( V_113 == NULL )
return 0 ;
if ( ! V_111 || * V_111 > 1 )
V_114 = ( * V_112 ) [ 1 ] ;
else
V_114 = NULL ;
V_1 -> V_17 &= ~ V_90 ;
V_1 -> V_17 |= V_89 ;
V_25 = F_73 ( V_1 , V_113 , V_114 ) ;
if ( V_25 > 0 ) {
( * V_112 ) += V_25 ;
if ( V_111 )
( * V_111 ) -= V_25 ;
return V_25 ;
}
if ( V_25 == - 2 )
return 0 ;
if ( V_25 == 0 )
return - 1 ;
return V_25 ;
}
int F_77 ( T_1 * V_1 , const char * V_96 )
{
if ( F_69 ( V_1 , & V_96 ) ) {
const T_10 * V_103 ;
V_103 = F_71 ( V_1 , V_96 ) ;
if ( V_103 )
return V_103 -> V_106 ;
}
return V_115 ;
}
T_1 * F_78 ( void )
{
T_1 * V_116 = F_79 ( sizeof( * V_116 ) ) ;
return V_116 ;
}
int F_80 ( T_1 * V_1 )
{
T_4 V_22 ;
T_6 * V_68 = NULL ;
if ( V_1 -> V_27 )
V_68 = V_1 -> V_27 -> V_69 ;
else if ( V_1 -> V_26 )
V_68 = V_1 -> V_26 -> V_69 ;
if ( V_68 && V_1 -> V_17 & V_70 ) {
for ( V_22 = 0 ; V_22 < V_117 ; V_22 ++ ) {
const char * V_118 = V_1 -> V_72 [ V_22 ] ;
if ( V_118 && ! V_68 -> V_74 [ V_22 ] . V_119 ) {
if ( ! F_43 ( V_1 , V_118 ) )
return 0 ;
}
}
}
if ( V_1 -> V_82 ) {
if ( V_1 -> V_26 )
F_81 ( V_1 -> V_26 , V_1 -> V_82 ) ;
else if ( V_1 -> V_27 )
F_82 ( V_1 -> V_27 , V_1 -> V_82 ) ;
else
F_83 ( V_1 -> V_82 , V_120 ) ;
V_1 -> V_82 = NULL ;
}
return 1 ;
}
void F_84 ( T_1 * V_1 )
{
if ( V_1 ) {
T_4 V_22 ;
for ( V_22 = 0 ; V_22 < V_117 ; V_22 ++ )
F_41 ( V_1 -> V_72 [ V_22 ] ) ;
F_41 ( V_1 -> V_87 ) ;
F_83 ( V_1 -> V_82 , V_120 ) ;
F_41 ( V_1 ) ;
}
}
unsigned int F_85 ( T_1 * V_1 , unsigned int V_17 )
{
V_1 -> V_17 |= V_17 ;
return V_1 -> V_17 ;
}
unsigned int F_86 ( T_1 * V_1 , unsigned int V_17 )
{
V_1 -> V_17 &= ~ V_17 ;
return V_1 -> V_17 ;
}
int F_87 ( T_1 * V_1 , const char * V_121 )
{
char * V_122 = NULL ;
if ( V_121 ) {
V_122 = F_42 ( V_121 ) ;
if ( V_122 == NULL )
return 0 ;
}
F_41 ( V_1 -> V_87 ) ;
V_1 -> V_87 = V_122 ;
if ( V_122 )
V_1 -> V_88 = strlen ( V_122 ) ;
else
V_1 -> V_88 = 0 ;
return 1 ;
}
void F_88 ( T_1 * V_1 , T_12 * V_26 )
{
V_1 -> V_26 = V_26 ;
V_1 -> V_27 = NULL ;
if ( V_26 ) {
V_1 -> V_6 = & V_26 -> V_123 ;
V_1 -> V_53 = & V_26 -> V_124 ;
V_1 -> V_54 = & V_26 -> V_125 ;
V_1 -> V_10 = & V_26 -> V_69 -> V_126 ;
V_1 -> V_12 = & V_26 -> V_127 ;
} else {
V_1 -> V_6 = NULL ;
V_1 -> V_53 = NULL ;
V_1 -> V_54 = NULL ;
V_1 -> V_10 = NULL ;
V_1 -> V_12 = NULL ;
}
}
void F_89 ( T_1 * V_1 , T_13 * V_27 )
{
V_1 -> V_27 = V_27 ;
V_1 -> V_26 = NULL ;
if ( V_27 ) {
V_1 -> V_6 = & V_27 -> V_123 ;
V_1 -> V_53 = & V_27 -> V_124 ;
V_1 -> V_54 = & V_27 -> V_125 ;
V_1 -> V_10 = & V_27 -> V_69 -> V_126 ;
V_1 -> V_12 = & V_27 -> V_127 ;
} else {
V_1 -> V_6 = NULL ;
V_1 -> V_53 = NULL ;
V_1 -> V_54 = NULL ;
V_1 -> V_10 = NULL ;
V_1 -> V_12 = NULL ;
}
}
