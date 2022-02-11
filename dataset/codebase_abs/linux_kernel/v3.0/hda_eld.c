static unsigned char F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 )
{
unsigned int V_5 ;
V_5 = F_2 ( V_2 , V_3 , 0 ,
V_6 , V_4 ) ;
#ifdef F_3
F_4 ( V_7 L_1 , V_4 , V_5 ) ;
#endif
if ( ( V_5 & V_8 ) == 0 ) {
F_5 ( V_7 L_2 ,
V_4 ) ;
V_5 = 0 ;
}
return V_5 & V_9 ;
}
static void F_6 ( struct V_10 * V_11 ,
const unsigned char * V_12 )
{
int V_13 ;
int V_5 ;
V_5 = F_7 ( V_12 , 1 , 0 , 7 ) ;
V_11 -> V_14 = 0 ;
for ( V_13 = 0 ; V_13 < 7 ; V_13 ++ )
if ( V_5 & ( 1 << V_13 ) )
V_11 -> V_14 |= V_15 [ V_13 + 1 ] ;
V_11 -> V_16 = F_7 ( V_12 , 0 , 0 , 3 ) ;
V_11 -> V_16 ++ ;
V_11 -> V_17 = 0 ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 = F_7 ( V_12 , 0 , 3 , 4 ) ;
switch ( V_11 -> V_19 ) {
case V_20 :
F_5 ( V_7
L_3 ) ;
break;
case V_21 :
V_5 = F_7 ( V_12 , 2 , 0 , 3 ) ;
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ )
if ( V_5 & ( 1 << V_13 ) )
V_11 -> V_17 |= V_22 [ V_13 + 1 ] ;
break;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
V_11 -> V_18 = F_7 ( V_12 , 2 , 0 , 8 ) ;
V_11 -> V_18 *= 8000 ;
break;
case V_30 :
break;
case V_31 :
break;
case V_32 :
break;
case V_33 :
break;
case V_34 :
break;
case V_35 :
V_11 -> V_36 = F_7 ( V_12 , 2 , 0 , 3 ) ;
break;
case V_37 :
V_11 -> V_19 = F_7 ( V_12 , 2 , 3 , 5 ) ;
if ( V_11 -> V_19 == V_38 ||
V_11 -> V_19 >= V_39 ) {
F_5 ( V_7
L_4 ,
V_11 -> V_19 ) ;
V_11 -> V_19 = 0 ;
} else
V_11 -> V_19 += V_40 -
V_41 ;
break;
}
}
static int F_8 ( struct V_42 * V_43 ,
const unsigned char * V_12 , int V_44 )
{
int V_45 ;
int V_13 ;
V_43 -> V_46 = F_7 ( V_12 , 0 , 3 , 5 ) ;
if ( V_43 -> V_46 != V_47 &&
V_43 -> V_46 != V_48 ) {
F_5 ( V_7 L_5 ,
V_43 -> V_46 ) ;
goto V_49;
}
V_43 -> V_50 = V_44 ;
V_43 -> V_51 = F_7 ( V_12 , 2 , 0 , 8 ) ;
V_45 = F_7 ( V_12 , 4 , 0 , 5 ) ;
V_43 -> V_52 = F_7 ( V_12 , 4 , 5 , 3 ) ;
V_43 -> V_53 = F_7 ( V_12 , 5 , 0 , 1 ) ;
V_43 -> V_54 = F_7 ( V_12 , 5 , 1 , 1 ) ;
V_43 -> V_55 = F_7 ( V_12 , 5 , 2 , 2 ) ;
V_43 -> V_56 = F_7 ( V_12 , 5 , 4 , 4 ) ;
V_43 -> V_57 = F_7 ( V_12 , 6 , 0 , 8 ) * 2 ;
V_43 -> V_58 = F_7 ( V_12 , 7 , 0 , 7 ) ;
V_43 -> V_59 = F_9 ( V_12 + 8 ) ;
V_43 -> V_60 = F_10 ( V_12 + 16 ) ;
V_43 -> V_61 = F_10 ( V_12 + 18 ) ;
if ( V_45 > V_62 ) {
F_5 ( V_7 L_6 , V_45 ) ;
goto V_49;
} else if ( V_63 + V_45 > V_44 ) {
F_5 ( V_7 L_7 , V_45 ) ;
goto V_49;
} else
F_11 ( V_43 -> V_64 , V_12 + V_63 , V_45 + 1 ) ;
for ( V_13 = 0 ; V_13 < V_43 -> V_56 ; V_13 ++ ) {
if ( V_63 + V_45 + 3 * ( V_13 + 1 ) > V_44 ) {
F_5 ( V_7 L_8 , V_13 ) ;
goto V_49;
}
F_6 ( V_43 -> V_65 + V_13 ,
V_12 + V_63 + V_45 + 3 * V_13 ) ;
}
return 0 ;
V_49:
V_43 -> V_46 = 0 ;
return - V_66 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 , 0 , V_67 ,
V_68 ) ;
}
int F_13 ( struct V_42 * V_69 ,
struct V_1 * V_2 , T_1 V_3 )
{
int V_13 ;
int V_70 ;
int V_44 ;
unsigned char * V_12 ;
if ( ! V_69 -> V_71 )
return - V_72 ;
V_44 = F_12 ( V_2 , V_3 ) ;
if ( V_44 == 0 ) {
F_5 ( V_7 L_9 ) ;
V_44 = 128 ;
}
if ( V_44 < V_63 || V_44 > V_73 ) {
F_5 ( V_7 L_10 , V_44 ) ;
return - V_74 ;
}
V_12 = F_14 ( V_44 , V_75 ) ;
if ( ! V_12 )
return - V_76 ;
for ( V_13 = 0 ; V_13 < V_44 ; V_13 ++ )
V_12 [ V_13 ] = F_1 ( V_2 , V_3 , V_13 ) ;
V_70 = F_8 ( V_69 , V_12 , V_44 ) ;
F_15 ( V_12 ) ;
return V_70 ;
}
static void F_16 ( struct V_10 * V_11 )
{
char V_12 [ V_77 ] ;
char V_78 [ 8 + V_79 ] = L_11 ;
if ( ! V_11 -> V_19 )
return;
F_17 ( V_11 -> V_14 , V_12 , sizeof( V_12 ) ) ;
if ( V_11 -> V_19 == V_21 )
F_18 ( V_11 -> V_17 , V_78 + 8 , sizeof( V_78 ) - 8 ) ;
else if ( V_11 -> V_18 )
snprintf ( V_78 , sizeof( V_78 ) ,
L_12 , V_11 -> V_18 ) ;
else
V_78 [ 0 ] = '\0' ;
F_4 ( V_7 L_13
L_14 ,
V_80 [ V_11 -> V_19 ] ,
V_11 -> V_16 ,
V_12 ,
V_78 ) ;
}
void F_19 ( int V_58 , char * V_12 , int V_81 )
{
int V_13 , V_82 ;
for ( V_13 = 0 , V_82 = 0 ; V_13 < F_20 ( V_83 ) ; V_13 ++ ) {
if ( V_58 & ( 1 << V_13 ) )
V_82 += snprintf ( V_12 + V_82 , V_81 - V_82 , L_15 ,
V_83 [ V_13 ] ) ;
}
V_12 [ V_82 ] = '\0' ;
}
void F_21 ( struct V_42 * V_43 )
{
int V_13 ;
F_4 ( V_7 L_16 ,
V_43 -> V_64 ,
V_84 [ V_43 -> V_55 ] ) ;
if ( V_43 -> V_58 ) {
char V_12 [ V_85 ] ;
F_19 ( V_43 -> V_58 , V_12 , sizeof( V_12 ) ) ;
F_4 ( V_7 L_17 , V_12 ) ;
}
for ( V_13 = 0 ; V_13 < V_43 -> V_56 ; V_13 ++ )
F_16 ( V_43 -> V_65 + V_13 ) ;
}
static void F_22 ( int V_13 , struct V_10 * V_11 ,
struct V_86 * V_87 )
{
char V_12 [ V_77 ] ;
F_23 ( V_87 , L_18 ,
V_13 , V_11 -> V_19 , V_80 [ V_11 -> V_19 ] ) ;
F_23 ( V_87 , L_19 , V_13 , V_11 -> V_16 ) ;
F_17 ( V_11 -> V_14 , V_12 , sizeof( V_12 ) ) ;
F_23 ( V_87 , L_20 , V_13 , V_11 -> V_14 , V_12 ) ;
if ( V_11 -> V_19 == V_21 ) {
F_18 ( V_11 -> V_17 , V_12 , sizeof( V_12 ) ) ;
F_23 ( V_87 , L_21 ,
V_13 , V_11 -> V_17 , V_12 ) ;
}
if ( V_11 -> V_18 )
F_23 ( V_87 , L_22 ,
V_13 , V_11 -> V_18 ) ;
if ( V_11 -> V_36 )
F_23 ( V_87 , L_23 , V_13 , V_11 -> V_36 ) ;
}
static void F_24 ( struct V_88 * V_89 ,
struct V_86 * V_87 )
{
struct V_42 * V_43 = V_89 -> V_90 ;
char V_12 [ V_85 ] ;
int V_13 ;
static char * V_91 [ 32 ] = {
L_24 ,
L_24 ,
L_25 ,
[ 3 ... 30 ] = L_24 ,
[ 31 ] = L_26
} ;
static char * V_92 [ 8 ] = {
L_27 ,
L_28 ,
L_29 ,
L_30 ,
[ 4 ... 7 ] = L_24
} ;
F_23 ( V_87 , L_31 , V_43 -> V_93 ) ;
F_23 ( V_87 , L_32 , V_43 -> V_71 ) ;
if ( ! V_43 -> V_71 )
return;
F_23 ( V_87 , L_33 , V_43 -> V_64 ) ;
F_23 ( V_87 , L_34 ,
V_84 [ V_43 -> V_55 ] ) ;
F_23 ( V_87 , L_35 , V_43 -> V_46 ,
V_91 [ V_43 -> V_46 ] ) ;
F_23 ( V_87 , L_36 , V_43 -> V_52 ,
V_92 [ V_43 -> V_52 ] ) ;
F_23 ( V_87 , L_37 , V_43 -> V_60 ) ;
F_23 ( V_87 , L_38 , V_43 -> V_61 ) ;
F_23 ( V_87 , L_39 , ( long long ) V_43 -> V_59 ) ;
F_23 ( V_87 , L_40 , V_43 -> V_53 ) ;
F_23 ( V_87 , L_41 , V_43 -> V_54 ) ;
F_23 ( V_87 , L_42 , V_43 -> V_57 ) ;
F_19 ( V_43 -> V_58 , V_12 , sizeof( V_12 ) ) ;
F_23 ( V_87 , L_43 , V_43 -> V_58 , V_12 ) ;
F_23 ( V_87 , L_44 , V_43 -> V_56 ) ;
for ( V_13 = 0 ; V_13 < V_43 -> V_56 ; V_13 ++ )
F_22 ( V_13 , V_43 -> V_65 + V_13 , V_87 ) ;
}
static void F_25 ( struct V_88 * V_89 ,
struct V_86 * V_87 )
{
struct V_42 * V_43 = V_89 -> V_90 ;
char line [ 64 ] ;
char V_94 [ 64 ] ;
char * V_95 ;
long long V_5 ;
unsigned int V_96 ;
while ( ! F_26 ( V_87 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_45 , V_94 , & V_5 ) != 2 )
continue;
if ( ! strcmp ( V_94 , L_46 ) )
V_43 -> V_93 = V_5 ;
else if ( ! strcmp ( V_94 , L_47 ) )
V_43 -> V_71 = V_5 ;
else if ( ! strcmp ( V_94 , L_48 ) )
V_43 -> V_55 = V_5 ;
else if ( ! strcmp ( V_94 , L_49 ) )
V_43 -> V_59 = V_5 ;
else if ( ! strcmp ( V_94 , L_50 ) )
V_43 -> V_53 = V_5 ;
else if ( ! strcmp ( V_94 , L_51 ) )
V_43 -> V_54 = V_5 ;
else if ( ! strcmp ( V_94 , L_52 ) )
V_43 -> V_57 = V_5 ;
else if ( ! strcmp ( V_94 , L_53 ) )
V_43 -> V_58 = V_5 ;
else if ( ! strcmp ( V_94 , L_54 ) )
V_43 -> V_56 = V_5 ;
else if ( ! strncmp ( V_94 , L_55 , 3 ) ) {
V_95 = V_94 + 4 ;
V_96 = V_94 [ 3 ] - '0' ;
if ( V_94 [ 4 ] >= '0' && V_94 [ 4 ] <= '9' ) {
V_95 ++ ;
V_96 = 10 * V_96 + V_94 [ 4 ] - '0' ;
}
if ( V_96 >= V_97 )
continue;
if ( ! strcmp ( V_95 , L_56 ) )
V_43 -> V_65 [ V_96 ] . V_19 = V_5 ;
else if ( ! strcmp ( V_95 , L_57 ) )
V_43 -> V_65 [ V_96 ] . V_16 = V_5 ;
else if ( ! strcmp ( V_95 , L_58 ) )
V_43 -> V_65 [ V_96 ] . V_14 = V_5 ;
else if ( ! strcmp ( V_95 , L_59 ) )
V_43 -> V_65 [ V_96 ] . V_17 = V_5 ;
else if ( ! strcmp ( V_95 , L_60 ) )
V_43 -> V_65 [ V_96 ] . V_18 = V_5 ;
else if ( ! strcmp ( V_95 , L_61 ) )
V_43 -> V_65 [ V_96 ] . V_36 = V_5 ;
if ( V_96 >= V_43 -> V_56 )
V_43 -> V_56 = V_96 + 1 ;
}
}
}
int F_27 ( struct V_1 * V_2 , struct V_42 * V_69 ,
int V_98 )
{
char V_94 [ 32 ] ;
struct V_88 * V_89 ;
int V_99 ;
snprintf ( V_94 , sizeof( V_94 ) , L_62 , V_2 -> V_100 , V_98 ) ;
V_99 = F_28 ( V_2 -> V_101 -> V_102 , V_94 , & V_89 ) ;
if ( V_99 < 0 )
return V_99 ;
F_29 ( V_89 , V_69 , F_24 ) ;
V_89 -> V_103 . V_104 . V_105 = F_25 ;
V_89 -> V_106 |= V_107 ;
V_69 -> V_108 = V_89 ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 , struct V_42 * V_69 )
{
if ( ! V_2 -> V_101 -> V_109 && V_69 -> V_108 ) {
F_31 ( V_2 -> V_101 -> V_102 , V_69 -> V_108 ) ;
V_69 -> V_108 = NULL ;
}
}
void F_32 ( struct V_42 * V_69 , struct V_110 * V_111 ,
struct V_110 * V_112 )
{
int V_13 ;
V_111 -> V_14 = V_113 | V_114 | V_115 ;
V_111 -> V_116 = V_117 ;
V_111 -> V_118 = 16 ;
V_111 -> V_119 = 2 ;
for ( V_13 = 0 ; V_13 < V_69 -> V_56 ; V_13 ++ ) {
struct V_10 * V_11 = & V_69 -> V_65 [ V_13 ] ;
V_111 -> V_14 |= V_11 -> V_14 ;
if ( V_11 -> V_16 > V_111 -> V_119 )
V_111 -> V_119 = V_11 -> V_16 ;
if ( V_11 -> V_19 == V_21 ) {
if ( V_11 -> V_17 & V_120 ) {
V_111 -> V_116 |= V_121 ;
if ( V_111 -> V_118 < 20 )
V_111 -> V_118 = 20 ;
}
if ( V_11 -> V_17 & V_122 ) {
V_111 -> V_116 |= V_121 ;
if ( V_111 -> V_118 < 24 )
V_111 -> V_118 = 24 ;
}
}
}
if ( ! V_112 )
return;
V_111 -> V_14 &= V_112 -> V_14 ;
V_111 -> V_116 &= V_112 -> V_116 ;
V_111 -> V_119 = F_33 ( V_111 -> V_119 , V_112 -> V_119 ) ;
V_111 -> V_118 = F_33 ( V_111 -> V_118 , V_112 -> V_118 ) ;
}
