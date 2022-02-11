static unsigned int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 )
{
unsigned int V_5 ;
V_5 = F_2 ( V_2 , V_3 , 0 ,
V_6 , V_4 ) ;
#ifdef F_3
F_4 ( V_7 L_1 , V_4 , V_5 ) ;
#endif
return V_5 ;
}
static void F_5 ( struct V_8 * V_9 ,
const unsigned char * V_10 )
{
int V_11 ;
int V_5 ;
V_5 = F_6 ( V_10 , 1 , 0 , 7 ) ;
V_9 -> V_12 = 0 ;
for ( V_11 = 0 ; V_11 < 7 ; V_11 ++ )
if ( V_5 & ( 1 << V_11 ) )
V_9 -> V_12 |= V_13 [ V_11 + 1 ] ;
V_9 -> V_14 = F_6 ( V_10 , 0 , 0 , 3 ) ;
V_9 -> V_14 ++ ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = 0 ;
V_9 -> V_17 = F_6 ( V_10 , 0 , 3 , 4 ) ;
switch ( V_9 -> V_17 ) {
case V_18 :
F_7 ( V_7
L_2 ) ;
break;
case V_19 :
V_5 = F_6 ( V_10 , 2 , 0 , 3 ) ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ )
if ( V_5 & ( 1 << V_11 ) )
V_9 -> V_15 |= V_20 [ V_11 + 1 ] ;
break;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_9 -> V_16 = F_6 ( V_10 , 2 , 0 , 8 ) ;
V_9 -> V_16 *= 8000 ;
break;
case V_28 :
break;
case V_29 :
break;
case V_30 :
break;
case V_31 :
break;
case V_32 :
break;
case V_33 :
V_9 -> V_34 = F_6 ( V_10 , 2 , 0 , 3 ) ;
break;
case V_35 :
V_9 -> V_17 = F_6 ( V_10 , 2 , 3 , 5 ) ;
if ( V_9 -> V_17 == V_36 ||
V_9 -> V_17 >= V_37 ) {
F_7 ( V_7
L_3 ,
V_9 -> V_17 ) ;
V_9 -> V_17 = 0 ;
} else
V_9 -> V_17 += V_38 -
V_39 ;
break;
}
}
static int F_8 ( struct V_40 * V_41 ,
const unsigned char * V_10 , int V_42 )
{
int V_43 ;
int V_11 ;
V_41 -> V_44 = F_6 ( V_10 , 0 , 3 , 5 ) ;
if ( V_41 -> V_44 != V_45 &&
V_41 -> V_44 != V_46 ) {
F_7 ( V_7 L_4 ,
V_41 -> V_44 ) ;
goto V_47;
}
V_41 -> V_48 = V_42 ;
V_41 -> V_49 = F_6 ( V_10 , 2 , 0 , 8 ) ;
V_43 = F_6 ( V_10 , 4 , 0 , 5 ) ;
V_41 -> V_50 = F_6 ( V_10 , 4 , 5 , 3 ) ;
V_41 -> V_51 = F_6 ( V_10 , 5 , 0 , 1 ) ;
V_41 -> V_52 = F_6 ( V_10 , 5 , 1 , 1 ) ;
V_41 -> V_53 = F_6 ( V_10 , 5 , 2 , 2 ) ;
V_41 -> V_54 = F_6 ( V_10 , 5 , 4 , 4 ) ;
V_41 -> V_55 = F_6 ( V_10 , 6 , 0 , 8 ) * 2 ;
V_41 -> V_56 = F_6 ( V_10 , 7 , 0 , 7 ) ;
V_41 -> V_57 = F_9 ( V_10 + 8 ) ;
V_41 -> V_58 = F_10 ( V_10 + 16 ) ;
V_41 -> V_59 = F_10 ( V_10 + 18 ) ;
if ( V_43 > V_60 ) {
F_7 ( V_7 L_5 , V_43 ) ;
goto V_47;
} else if ( V_61 + V_43 > V_42 ) {
F_7 ( V_7 L_6 , V_43 ) ;
goto V_47;
} else
F_11 ( V_41 -> V_62 , V_10 + V_61 , V_43 + 1 ) ;
for ( V_11 = 0 ; V_11 < V_41 -> V_54 ; V_11 ++ ) {
if ( V_61 + V_43 + 3 * ( V_11 + 1 ) > V_42 ) {
F_7 ( V_7 L_7 , V_11 ) ;
goto V_47;
}
F_5 ( V_41 -> V_63 + V_11 ,
V_10 + V_61 + V_43 + 3 * V_11 ) ;
}
return 0 ;
V_47:
V_41 -> V_44 = 0 ;
return - V_64 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 , 0 , V_65 ,
V_66 ) ;
}
int F_13 ( struct V_40 * V_67 ,
struct V_1 * V_2 , T_1 V_3 )
{
int V_11 ;
int V_68 ;
int V_42 ;
unsigned char * V_10 ;
if ( ! V_67 -> V_69 )
return - V_70 ;
V_42 = F_12 ( V_2 , V_3 ) ;
if ( V_42 == 0 ) {
F_7 ( V_7 L_8 ) ;
V_42 = 128 ;
}
if ( V_42 < V_61 || V_42 > V_71 ) {
F_7 ( V_7 L_9 , V_42 ) ;
return - V_72 ;
}
V_10 = F_14 ( V_42 , V_73 ) ;
if ( ! V_10 )
return - V_74 ;
for ( V_11 = 0 ; V_11 < V_42 ; V_11 ++ ) {
unsigned int V_5 = F_1 ( V_2 , V_3 , V_11 ) ;
if ( ! ( V_5 & V_75 ) ) {
if ( ! V_11 ) {
F_7 ( V_7
L_10 ) ;
V_68 = - V_64 ;
goto error;
}
F_7 ( V_7
L_11 , V_11 ) ;
V_5 = 0 ;
} else
V_5 &= V_76 ;
V_10 [ V_11 ] = V_5 ;
}
V_68 = F_8 ( V_67 , V_10 , V_42 ) ;
error:
F_15 ( V_10 ) ;
return V_68 ;
}
static void F_16 ( struct V_8 * V_9 )
{
char V_10 [ V_77 ] ;
char V_78 [ 8 + V_79 ] = L_12 ;
if ( ! V_9 -> V_17 )
return;
F_17 ( V_9 -> V_12 , V_10 , sizeof( V_10 ) ) ;
if ( V_9 -> V_17 == V_19 )
F_18 ( V_9 -> V_15 , V_78 + 8 , sizeof( V_78 ) - 8 ) ;
else if ( V_9 -> V_16 )
snprintf ( V_78 , sizeof( V_78 ) ,
L_13 , V_9 -> V_16 ) ;
else
V_78 [ 0 ] = '\0' ;
F_4 ( V_7 L_14
L_15 ,
V_80 [ V_9 -> V_17 ] ,
V_9 -> V_14 ,
V_10 ,
V_78 ) ;
}
void F_19 ( int V_56 , char * V_10 , int V_81 )
{
int V_11 , V_82 ;
for ( V_11 = 0 , V_82 = 0 ; V_11 < F_20 ( V_83 ) ; V_11 ++ ) {
if ( V_56 & ( 1 << V_11 ) )
V_82 += snprintf ( V_10 + V_82 , V_81 - V_82 , L_16 ,
V_83 [ V_11 ] ) ;
}
V_10 [ V_82 ] = '\0' ;
}
void F_21 ( struct V_40 * V_41 )
{
int V_11 ;
F_4 ( V_7 L_17 ,
V_41 -> V_62 ,
V_84 [ V_41 -> V_53 ] ) ;
if ( V_41 -> V_56 ) {
char V_10 [ V_85 ] ;
F_19 ( V_41 -> V_56 , V_10 , sizeof( V_10 ) ) ;
F_4 ( V_7 L_18 , V_10 ) ;
}
for ( V_11 = 0 ; V_11 < V_41 -> V_54 ; V_11 ++ )
F_16 ( V_41 -> V_63 + V_11 ) ;
}
static void F_22 ( int V_11 , struct V_8 * V_9 ,
struct V_86 * V_87 )
{
char V_10 [ V_77 ] ;
F_23 ( V_87 , L_19 ,
V_11 , V_9 -> V_17 , V_80 [ V_9 -> V_17 ] ) ;
F_23 ( V_87 , L_20 , V_11 , V_9 -> V_14 ) ;
F_17 ( V_9 -> V_12 , V_10 , sizeof( V_10 ) ) ;
F_23 ( V_87 , L_21 , V_11 , V_9 -> V_12 , V_10 ) ;
if ( V_9 -> V_17 == V_19 ) {
F_18 ( V_9 -> V_15 , V_10 , sizeof( V_10 ) ) ;
F_23 ( V_87 , L_22 ,
V_11 , V_9 -> V_15 , V_10 ) ;
}
if ( V_9 -> V_16 )
F_23 ( V_87 , L_23 ,
V_11 , V_9 -> V_16 ) ;
if ( V_9 -> V_34 )
F_23 ( V_87 , L_24 , V_11 , V_9 -> V_34 ) ;
}
static void F_24 ( struct V_88 * V_89 ,
struct V_86 * V_87 )
{
struct V_40 * V_41 = V_89 -> V_90 ;
char V_10 [ V_85 ] ;
int V_11 ;
static char * V_91 [ 32 ] = {
L_25 ,
L_25 ,
L_26 ,
[ 3 ... 30 ] = L_25 ,
[ 31 ] = L_27
} ;
static char * V_92 [ 8 ] = {
L_28 ,
L_29 ,
L_30 ,
L_31 ,
[ 4 ... 7 ] = L_25
} ;
F_23 ( V_87 , L_32 , V_41 -> V_93 ) ;
F_23 ( V_87 , L_33 , V_41 -> V_69 ) ;
if ( ! V_41 -> V_69 )
return;
F_23 ( V_87 , L_34 , V_41 -> V_62 ) ;
F_23 ( V_87 , L_35 ,
V_84 [ V_41 -> V_53 ] ) ;
F_23 ( V_87 , L_36 , V_41 -> V_44 ,
V_91 [ V_41 -> V_44 ] ) ;
F_23 ( V_87 , L_37 , V_41 -> V_50 ,
V_92 [ V_41 -> V_50 ] ) ;
F_23 ( V_87 , L_38 , V_41 -> V_58 ) ;
F_23 ( V_87 , L_39 , V_41 -> V_59 ) ;
F_23 ( V_87 , L_40 , ( long long ) V_41 -> V_57 ) ;
F_23 ( V_87 , L_41 , V_41 -> V_51 ) ;
F_23 ( V_87 , L_42 , V_41 -> V_52 ) ;
F_23 ( V_87 , L_43 , V_41 -> V_55 ) ;
F_19 ( V_41 -> V_56 , V_10 , sizeof( V_10 ) ) ;
F_23 ( V_87 , L_44 , V_41 -> V_56 , V_10 ) ;
F_23 ( V_87 , L_45 , V_41 -> V_54 ) ;
for ( V_11 = 0 ; V_11 < V_41 -> V_54 ; V_11 ++ )
F_22 ( V_11 , V_41 -> V_63 + V_11 , V_87 ) ;
}
static void F_25 ( struct V_88 * V_89 ,
struct V_86 * V_87 )
{
struct V_40 * V_41 = V_89 -> V_90 ;
char line [ 64 ] ;
char V_94 [ 64 ] ;
char * V_95 ;
long long V_5 ;
unsigned int V_96 ;
while ( ! F_26 ( V_87 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_46 , V_94 , & V_5 ) != 2 )
continue;
if ( ! strcmp ( V_94 , L_47 ) )
V_41 -> V_93 = V_5 ;
else if ( ! strcmp ( V_94 , L_48 ) )
V_41 -> V_69 = V_5 ;
else if ( ! strcmp ( V_94 , L_49 ) )
V_41 -> V_53 = V_5 ;
else if ( ! strcmp ( V_94 , L_50 ) )
V_41 -> V_57 = V_5 ;
else if ( ! strcmp ( V_94 , L_51 ) )
V_41 -> V_51 = V_5 ;
else if ( ! strcmp ( V_94 , L_52 ) )
V_41 -> V_52 = V_5 ;
else if ( ! strcmp ( V_94 , L_53 ) )
V_41 -> V_55 = V_5 ;
else if ( ! strcmp ( V_94 , L_54 ) )
V_41 -> V_56 = V_5 ;
else if ( ! strcmp ( V_94 , L_55 ) )
V_41 -> V_54 = V_5 ;
else if ( ! strncmp ( V_94 , L_56 , 3 ) ) {
V_95 = V_94 + 4 ;
V_96 = V_94 [ 3 ] - '0' ;
if ( V_94 [ 4 ] >= '0' && V_94 [ 4 ] <= '9' ) {
V_95 ++ ;
V_96 = 10 * V_96 + V_94 [ 4 ] - '0' ;
}
if ( V_96 >= V_97 )
continue;
if ( ! strcmp ( V_95 , L_57 ) )
V_41 -> V_63 [ V_96 ] . V_17 = V_5 ;
else if ( ! strcmp ( V_95 , L_58 ) )
V_41 -> V_63 [ V_96 ] . V_14 = V_5 ;
else if ( ! strcmp ( V_95 , L_59 ) )
V_41 -> V_63 [ V_96 ] . V_12 = V_5 ;
else if ( ! strcmp ( V_95 , L_60 ) )
V_41 -> V_63 [ V_96 ] . V_15 = V_5 ;
else if ( ! strcmp ( V_95 , L_61 ) )
V_41 -> V_63 [ V_96 ] . V_16 = V_5 ;
else if ( ! strcmp ( V_95 , L_62 ) )
V_41 -> V_63 [ V_96 ] . V_34 = V_5 ;
if ( V_96 >= V_41 -> V_54 )
V_41 -> V_54 = V_96 + 1 ;
}
}
}
int F_27 ( struct V_1 * V_2 , struct V_40 * V_67 ,
int V_98 )
{
char V_94 [ 32 ] ;
struct V_88 * V_89 ;
int V_99 ;
snprintf ( V_94 , sizeof( V_94 ) , L_63 , V_2 -> V_100 , V_98 ) ;
V_99 = F_28 ( V_2 -> V_101 -> V_102 , V_94 , & V_89 ) ;
if ( V_99 < 0 )
return V_99 ;
F_29 ( V_89 , V_67 , F_24 ) ;
V_89 -> V_103 . V_104 . V_105 = F_25 ;
V_89 -> V_106 |= V_107 ;
V_67 -> V_108 = V_89 ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 , struct V_40 * V_67 )
{
if ( ! V_2 -> V_101 -> V_109 && V_67 -> V_108 ) {
F_31 ( V_2 -> V_101 -> V_102 , V_67 -> V_108 ) ;
V_67 -> V_108 = NULL ;
}
}
void F_32 ( struct V_40 * V_67 ,
struct V_110 * V_111 )
{
T_2 V_12 ;
T_3 V_112 ;
unsigned int V_113 ;
unsigned int V_114 ;
int V_11 ;
V_12 = V_115 | V_116 |
V_117 ;
V_112 = V_118 ;
V_113 = 16 ;
V_114 = 2 ;
for ( V_11 = 0 ; V_11 < V_67 -> V_54 ; V_11 ++ ) {
struct V_8 * V_9 = & V_67 -> V_63 [ V_11 ] ;
V_12 |= V_9 -> V_12 ;
if ( V_9 -> V_14 > V_114 )
V_114 = V_9 -> V_14 ;
if ( V_9 -> V_17 == V_19 ) {
if ( V_9 -> V_15 & V_119 ) {
V_112 |= V_120 ;
if ( V_113 < 20 )
V_113 = 20 ;
}
if ( V_9 -> V_15 & V_121 ) {
V_112 |= V_120 ;
if ( V_113 < 24 )
V_113 = 24 ;
}
}
}
V_111 -> V_12 &= V_12 ;
V_111 -> V_112 &= V_112 ;
V_111 -> V_113 = F_33 ( V_111 -> V_113 , V_113 ) ;
V_111 -> V_114 = F_33 ( V_111 -> V_114 , V_114 ) ;
}
