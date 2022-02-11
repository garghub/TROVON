int main ( int V_1 , char * V_2 [] )
{
char * * V_3 , * V_4 , * V_5 ;
int V_6 , V_7 , V_8 ;
int V_9 = 0 ;
int V_10 = 0 ;
while ( ( V_6 = F_1 ( V_1 , V_2 , L_1 , V_11 , 0 ) ) != V_12 ) {
switch ( V_6 ) {
case 'a' : V_13 ++ ; V_10 ++ ; break;
case 'c' : V_14 ++ ; V_10 ++ ; break;
case 'd' : V_15 ++ ; V_10 ++ ; break;
case 'f' : V_16 ++ ; V_10 ++ ; break;
case 'h' : V_17 ++ ; V_10 ++ ; break;
case 'u' : V_18 ++ ; V_10 ++ ; break;
case 'v' : V_19 ++ ; break;
case 'V' : V_20 ++ ; V_10 ++ ; break;
case '?' :
fprintf ( V_21 , L_2 , V_22 ) ;
V_9 = 2 ;
goto V_23;
}
}
if ( V_10 > 1 ) {
fprintf ( V_21 , L_2 , V_22 ) ;
V_9 = 2 ;
goto V_23;
}
if ( V_19 || V_20 ) {
printf ( L_2 , V_24 ) ;
if ( V_20 ) {
V_9 = 0 ;
goto V_23;
}
}
if ( V_18 ) {
printf ( L_2 , V_22 ) ;
V_9 = 0 ;
goto V_23;
}
if ( V_17 ) {
printf ( L_2 , V_22 ) ;
printf ( L_2 , V_25 ) ;
V_9 = 0 ;
goto V_23;
}
if ( ( V_26 = F_2 ( V_27 , V_28 , 0 ) ) < 0 ) {
perror ( L_3 ) ;
V_9 = 1 ;
goto V_23;
}
if ( V_13 ) {
if ( V_29 == V_1 ) {
F_3 ( ( char * ) NULL ) ;
goto V_23;
} else {
fprintf ( V_21 , L_2 , V_22 ) ;
V_9 = 2 ;
goto V_23;
}
}
V_3 = V_2 + V_29 ;
V_4 = * V_3 ++ ;
if ( V_4 == NULL ) {
fprintf ( V_21 , L_2 , V_22 ) ;
V_9 = 2 ;
goto V_23;
}
V_9 = F_4 ( V_4 ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_4
L_5 ,
V_4 ) ;
goto V_23;
}
V_5 = * V_3 ++ ;
if ( V_5 == NULL ) {
if ( V_15 || V_14 ) {
fprintf ( V_21 , L_2 , V_22 ) ;
V_9 = 2 ;
goto V_23;
}
F_3 ( V_4 ) ;
goto V_23;
}
V_9 = F_5 ( V_4 , V_30 ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_6
L_5 ,
V_4 , strerror ( V_9 ) ) ;
goto V_23;
}
if ( ! ( V_31 . V_32 & V_33 ) ) {
fprintf ( V_21 ,
L_7
L_8 ,
V_4 ) ;
V_9 = 1 ;
goto V_23;
}
if ( ! ( V_31 . V_32 & V_34 ) ) {
fprintf ( V_21 ,
L_9
L_10 ,
V_4 ) ;
V_9 = 1 ;
goto V_23;
}
if ( ! V_14 && ! V_15 ) {
T_1 V_35 = V_36 . V_37 . V_38 ;
unsigned char * V_39 =
( unsigned char * ) V_36 . V_37 . V_40 ;
if ( V_35 != 1 && ! V_16 ) {
fprintf ( V_21 ,
L_11
L_12
L_13
L_14
L_15
L_16 ,
V_4 ) ;
V_9 = 1 ;
goto V_23;
}
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ ) {
if ( V_39 [ V_7 ] != 0 ) {
V_41 = 1 ;
break;
}
}
if ( V_41 ) {
F_6 ( L_17
L_18
L_19 ,
V_4 ,
V_39 [ 0 ] , V_39 [ 1 ] ,
V_39 [ 2 ] , V_39 [ 3 ] ,
V_39 [ 4 ] , V_39 [ 5 ] ,
V_35 ) ;
}
}
if ( V_14 ) {
V_9 = F_7 ( V_5 ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_20
L_5 ,
V_5 ) ;
goto V_23;
}
V_9 = F_8 ( V_4 , V_5 ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_21
L_22 ,
V_4 , V_5 ) ;
}
} else {
do {
if ( V_15 ) {
V_8 = F_7 ( V_5 ) ;
if ( V_8 ) {
fprintf ( V_21 ,
L_23
L_24 ,
V_5 ) ;
V_9 = V_8 ;
continue;
}
V_8 = F_9 ( V_4 , V_5 ) ;
if ( V_8 ) {
fprintf ( V_21 ,
L_21
L_25 ,
V_4 , V_5 ) ;
V_9 = V_8 ;
}
} else {
V_8 = F_5 ( V_5 , V_42 ) ;
if ( V_8 ) {
fprintf ( V_21 ,
L_26
L_27
L_28 ,
V_5 , strerror ( V_8 ) ) ;
V_9 = V_8 ;
continue;
}
V_8 = F_10 ( V_4 , V_5 ) ;
if ( V_8 ) {
fprintf ( V_21 ,
L_21
L_29 ,
V_4 , V_5 ) ;
V_9 = V_8 ;
}
}
} while ( ( V_5 = * V_3 ++ ) != NULL );
}
V_23:
if ( V_26 >= 0 ) {
F_11 ( V_26 ) ;
}
return V_9 ;
}
static int F_12 ( char * V_43 )
{
struct V_44 V_45 ;
int V_46 , V_47 ;
struct V_48 V_49 , V_50 , V_51 ;
unsigned char * V_39 ;
strcpy ( V_45 . V_52 , V_43 ) ;
if ( F_13 ( V_26 , V_53 , & V_45 ) < 0 )
return - 1 ;
V_54 = V_45 . V_32 ;
printf ( L_30 ,
V_43 , V_45 . V_32 ) ;
strcpy ( V_45 . V_52 , V_43 ) ;
if ( F_13 ( V_26 , V_55 , & V_45 ) < 0 )
return - 1 ;
printf ( L_31 ,
V_45 . V_56 . V_40 [ 0 ] , V_45 . V_56 . V_40 [ 1 ] ,
V_45 . V_56 . V_40 [ 2 ] , V_45 . V_56 . V_40 [ 3 ] ) ;
strcpy ( V_45 . V_52 , V_43 ) ;
if ( F_13 ( V_26 , V_57 , & V_45 ) < 0 )
return - 1 ;
V_39 = ( unsigned char * ) V_45 . V_37 . V_40 ;
printf ( L_32
L_33 ,
V_45 . V_37 . V_38 , V_39 [ 0 ] , V_39 [ 1 ] ,
V_39 [ 2 ] , V_39 [ 3 ] , V_39 [ 4 ] , V_39 [ 5 ] ) ;
strcpy ( V_45 . V_52 , V_43 ) ;
if ( F_13 ( V_26 , V_58 , & V_45 ) < 0 ) {
V_46 = 0 ;
} else
V_46 = V_45 . V_59 ;
strcpy ( V_45 . V_52 , V_43 ) ;
if ( F_13 ( V_26 , V_60 , & V_45 ) < 0 )
V_47 = 0 ;
else
V_47 = V_45 . V_61 ;
strcpy ( V_45 . V_52 , V_43 ) ;
if ( F_13 ( V_26 , V_62 , & V_45 ) < 0 ) {
memset ( & V_49 , 0 , sizeof( struct V_48 ) ) ;
} else
V_49 = V_45 . V_63 ;
strcpy ( V_45 . V_52 , V_43 ) ;
if ( F_13 ( V_26 , V_64 , & V_45 ) < 0 ) {
memset ( & V_50 , 0 , sizeof( struct V_48 ) ) ;
} else
V_50 = V_45 . V_65 ;
strcpy ( V_45 . V_52 , V_43 ) ;
if ( F_13 ( V_26 , V_66 , & V_45 ) < 0 ) {
memset ( & V_51 , 0 , sizeof( struct V_48 ) ) ;
} else
V_51 = V_45 . V_67 ;
return 0 ;
}
static void F_3 ( char * V_43 )
{
char V_68 [ 1024 ] ;
struct V_69 V_70 ;
struct V_44 * V_45 ;
int V_7 ;
if ( V_43 == ( char * ) NULL ) {
V_70 . V_71 = sizeof( V_68 ) ;
V_70 . V_72 = V_68 ;
if ( F_13 ( V_26 , V_73 , & V_70 ) < 0 ) {
perror ( L_34 ) ;
return;
}
V_45 = V_70 . V_74 ;
for ( V_7 = V_70 . V_71 / sizeof( struct V_44 ) ; -- V_7 >= 0 ; V_45 ++ ) {
if ( F_12 ( V_45 -> V_52 ) < 0 ) {
fprintf ( V_21 ,
L_35 ,
V_45 -> V_52 ) ;
continue;
}
if ( ( ( V_54 & V_34 ) == 0 ) && ! V_13 ) continue;
}
} else {
if ( F_12 ( V_43 ) < 0 ) {
fprintf ( V_21 ,
L_35 , V_43 ) ;
}
}
}
static int F_4 ( char * V_4 )
{
struct V_44 V_45 ;
struct V_75 V_76 ;
char * V_77 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
strncpy ( V_45 . V_52 , V_4 , V_78 ) ;
V_45 . V_79 = ( V_80 ) & V_76 ;
V_76 . V_81 = V_82 ;
strncpy ( V_76 . V_83 , L_36 , 32 ) ;
snprintf ( V_76 . V_84 , 32 , L_37 , V_85 ) ;
if ( F_13 ( V_26 , V_86 , & V_45 ) < 0 ) {
if ( V_87 == V_88 ) {
goto V_23;
}
V_89 = V_87 ;
F_6 ( L_38 ,
V_4 , strerror ( V_89 ) ) ;
return 1 ;
}
V_90 = strtoul ( V_76 . V_84 , & V_77 , 0 ) ;
if ( * V_77 ) {
F_6 ( L_39
L_40 ,
V_4 ) ;
return 1 ;
}
V_23:
F_6 ( L_41 , V_90 ) ;
return 0 ;
}
static int F_8 ( char * V_4 , char * V_5 )
{
struct V_44 V_45 ;
int V_9 = 0 ;
if ( ! ( V_91 . V_32 & V_92 ) ) {
fprintf ( V_21 ,
L_42
L_43 ,
V_5 ) ;
return 1 ;
}
strncpy ( V_45 . V_52 , V_4 , V_78 ) ;
strncpy ( V_45 . V_93 , V_5 , V_78 ) ;
if ( ( F_13 ( V_26 , V_94 , & V_45 ) < 0 ) &&
( F_13 ( V_26 , V_95 , & V_45 ) < 0 ) ) {
V_89 = V_87 ;
F_6 ( L_44
L_45 ,
V_4 , strerror ( V_89 ) ) ;
V_9 = 1 ;
}
return V_9 ;
}
static int F_10 ( char * V_4 , char * V_5 )
{
struct V_44 V_45 ;
int V_9 = 0 ;
if ( V_91 . V_32 & V_92 ) {
fprintf ( V_21 ,
L_42
L_46 ,
V_5 ) ;
return 1 ;
}
V_9 = F_14 ( V_5 , V_91 . V_32 ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_47 ,
V_5 ) ;
return V_9 ;
}
if ( V_90 < 2 ) {
F_15 ( V_4 , V_5 ) ;
} else {
V_9 = F_16 ( V_5 ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_48 ,
V_5 ) ;
return V_9 ;
}
}
if ( V_96 . V_61 != V_97 . V_61 ) {
V_9 = F_17 ( V_5 , V_96 . V_61 ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_49 ,
V_5 ) ;
return V_9 ;
}
}
if ( V_41 ) {
if ( V_90 < 1 ) {
V_9 = F_18 ( V_5 ,
& ( V_36 . V_37 ) ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_50
L_51 ,
V_5 ) ;
goto V_98;
}
V_9 = F_19 ( V_5 , V_91 . V_32 ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_52
L_53 ,
V_5 ) ;
goto V_99;
}
}
} else {
if ( V_90 < 1 ) {
V_9 = F_14 ( V_4 , V_31 . V_32 ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_54
L_53 ,
V_4 ) ;
goto V_98;
}
}
V_9 = F_20 ( V_4 ,
& ( V_100 . V_37 ) ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_55
L_51 ,
V_4 ) ;
goto V_98;
}
if ( V_90 < 1 ) {
V_9 = F_19 ( V_4 , V_31 . V_32 ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_54
L_56 ,
V_4 ) ;
goto V_101;
}
}
V_41 = 1 ;
}
strncpy ( V_45 . V_52 , V_4 , V_78 ) ;
strncpy ( V_45 . V_93 , V_5 , V_78 ) ;
if ( ( F_13 ( V_26 , V_102 , & V_45 ) < 0 ) &&
( F_13 ( V_26 , V_103 , & V_45 ) < 0 ) ) {
V_89 = V_87 ;
F_6 ( L_57 ,
V_4 , strerror ( V_89 ) ) ;
V_9 = 1 ;
}
if ( V_9 ) {
goto V_101;
}
return 0 ;
V_101:
F_20 ( V_4 , & ( V_36 . V_37 ) ) ;
V_41 = 0 ;
goto V_98;
V_99:
F_18 ( V_5 , & ( V_100 . V_37 ) ) ;
V_98:
F_17 ( V_5 , V_97 . V_61 ) ;
return V_9 ;
}
static int F_9 ( char * V_4 , char * V_5 )
{
struct V_44 V_45 ;
int V_9 = 0 ;
if ( ! ( V_91 . V_32 & V_92 ) ) {
fprintf ( V_21 ,
L_42
L_43 ,
V_5 ) ;
return 1 ;
}
strncpy ( V_45 . V_52 , V_4 , V_78 ) ;
strncpy ( V_45 . V_93 , V_5 , V_78 ) ;
if ( ( F_13 ( V_26 , V_104 , & V_45 ) < 0 ) &&
( F_13 ( V_26 , V_105 , & V_45 ) < 0 ) ) {
V_89 = V_87 ;
F_6 ( L_58 ,
V_4 , strerror ( V_89 ) ) ;
return 1 ;
} else if ( V_90 < 1 ) {
V_9 = F_14 ( V_5 , V_91 . V_32 ) ;
if ( V_9 ) {
fprintf ( V_21 ,
L_52
L_53 ,
V_5 ) ;
}
}
F_17 ( V_5 , 1500 ) ;
return V_9 ;
}
static int F_5 ( char * V_43 , struct V_106 V_107 [] )
{
int V_7 ;
int V_9 = 0 ;
for ( V_7 = 0 ; V_107 [ V_7 ] . V_108 ; V_7 ++ ) {
strncpy ( V_107 [ V_7 ] . V_108 -> V_52 , V_43 , V_78 ) ;
V_9 = F_13 ( V_26 , V_107 [ V_7 ] . V_109 , V_107 [ V_7 ] . V_108 ) ;
if ( V_9 < 0 ) {
V_89 = V_87 ;
F_6 ( L_59 ,
V_43 , V_107 [ V_7 ] . V_110 ,
strerror ( V_89 ) ) ;
return V_89 ;
}
}
return 0 ;
}
static int F_7 ( char * V_5 )
{
int V_9 = 0 ;
strncpy ( V_91 . V_52 , V_5 , V_78 ) ;
V_9 = F_13 ( V_26 , V_53 , & V_91 ) ;
if ( V_9 < 0 ) {
V_89 = V_87 ;
F_6 ( L_60 ,
V_5 , strerror ( V_89 ) ) ;
} else {
F_6 ( L_61 ,
V_5 , V_91 . V_32 ) ;
}
return V_9 ;
}
static int F_20 ( char * V_4 , struct V_48 * V_39 )
{
unsigned char * V_111 = ( unsigned char * ) V_39 -> V_40 ;
struct V_44 V_45 ;
int V_9 = 0 ;
strncpy ( V_45 . V_52 , V_4 , V_78 ) ;
memcpy ( & ( V_45 . V_37 ) , V_39 , sizeof( struct V_48 ) ) ;
V_9 = F_13 ( V_26 , V_112 , & V_45 ) ;
if ( V_9 < 0 ) {
V_89 = V_87 ;
F_6 ( L_62 ,
V_4 , strerror ( V_89 ) ) ;
return V_9 ;
} else {
F_6 ( L_63
L_33 ,
V_4 , V_111 [ 0 ] , V_111 [ 1 ] , V_111 [ 2 ] ,
V_111 [ 3 ] , V_111 [ 4 ] , V_111 [ 5 ] ) ;
}
return V_9 ;
}
static int F_18 ( char * V_5 , struct V_48 * V_39 )
{
unsigned char * V_111 = ( unsigned char * ) V_39 -> V_40 ;
struct V_44 V_45 ;
int V_9 = 0 ;
strncpy ( V_45 . V_52 , V_5 , V_78 ) ;
memcpy ( & ( V_45 . V_37 ) , V_39 , sizeof( struct V_48 ) ) ;
V_9 = F_13 ( V_26 , V_112 , & V_45 ) ;
if ( V_9 < 0 ) {
V_89 = V_87 ;
F_6 ( L_64 ,
V_5 , strerror ( V_89 ) ) ;
if ( V_89 == V_113 ) {
F_6 ( L_65
L_66 ) ;
} else if ( V_89 == V_88 ) {
F_6 ( L_67
L_68
L_69
L_70 ) ;
} else if ( V_89 == V_114 ) {
F_6 ( L_71
L_72 ) ;
}
return V_9 ;
} else {
F_6 ( L_73
L_33 ,
V_5 , V_111 [ 0 ] , V_111 [ 1 ] , V_111 [ 2 ] ,
V_111 [ 3 ] , V_111 [ 4 ] , V_111 [ 5 ] ) ;
}
return V_9 ;
}
static int F_17 ( char * V_5 , int V_47 )
{
struct V_44 V_45 ;
int V_9 = 0 ;
V_45 . V_61 = V_47 ;
strncpy ( V_45 . V_52 , V_5 , V_78 ) ;
V_9 = F_13 ( V_26 , V_115 , & V_45 ) ;
if ( V_9 < 0 ) {
V_89 = V_87 ;
F_6 ( L_74 ,
V_5 , strerror ( V_89 ) ) ;
} else {
F_6 ( L_75 , V_5 , V_47 ) ;
}
return V_9 ;
}
static int F_21 ( char * V_43 , short V_116 )
{
struct V_44 V_45 ;
int V_9 = 0 ;
V_45 . V_32 = V_116 ;
strncpy ( V_45 . V_52 , V_43 , V_78 ) ;
V_9 = F_13 ( V_26 , V_117 , & V_45 ) ;
if ( V_9 < 0 ) {
V_89 = V_87 ;
F_6 ( L_76 ,
V_43 , strerror ( V_89 ) ) ;
} else {
F_6 ( L_77 , V_43 , V_116 ) ;
}
return V_9 ;
}
static int F_19 ( char * V_43 , short V_116 )
{
return F_21 ( V_43 , V_116 | V_34 ) ;
}
static int F_14 ( char * V_43 , short V_116 )
{
return F_21 ( V_43 , V_116 & ~ V_34 ) ;
}
static int F_16 ( char * V_43 )
{
struct V_44 V_45 ;
int V_9 = 0 ;
strncpy ( V_45 . V_52 , V_43 , V_78 ) ;
V_45 . V_56 . V_38 = V_27 ;
memset ( V_45 . V_56 . V_40 , 0 , sizeof( V_45 . V_56 . V_40 ) ) ;
V_9 = F_13 ( V_26 , V_118 , & V_45 ) ;
if ( V_9 < 0 ) {
V_89 = V_87 ;
F_6 ( L_78 ,
V_43 , strerror ( V_89 ) ) ;
} else {
F_6 ( L_79 , V_43 ) ;
}
return V_9 ;
}
static int F_15 ( char * V_4 , char * V_5 )
{
struct V_44 V_45 ;
int V_9 ;
unsigned char * V_119 ;
int V_7 ;
struct {
char * V_110 ;
char * V_120 ;
int V_121 ;
int V_122 ;
} V_107 [] = {
{ L_80 , L_81 , V_55 , V_118 } ,
{ L_82 , L_83 , V_62 , V_123 } ,
{ L_84 , L_85 , V_64 , V_124 } ,
{ L_86 , L_87 , V_66 , V_125 } ,
{ NULL , NULL , 0 , 0 } ,
} ;
for ( V_7 = 0 ; V_107 [ V_7 ] . V_110 ; V_7 ++ ) {
strncpy ( V_45 . V_52 , V_4 , V_78 ) ;
V_9 = F_13 ( V_26 , V_107 [ V_7 ] . V_121 , & V_45 ) ;
if ( V_9 < 0 ) {
int V_89 = V_87 ;
F_6 ( L_88 ,
V_4 , V_107 [ V_7 ] . V_110 ,
strerror ( V_89 ) ) ;
V_45 . V_56 . V_38 = V_27 ;
memset ( V_45 . V_56 . V_40 , 0 ,
sizeof( V_45 . V_56 . V_40 ) ) ;
}
strncpy ( V_45 . V_52 , V_5 , V_78 ) ;
V_9 = F_13 ( V_26 , V_107 [ V_7 ] . V_122 , & V_45 ) ;
if ( V_9 < 0 ) {
int V_89 = V_87 ;
F_6 ( L_89 ,
V_5 , V_107 [ V_7 ] . V_110 ,
strerror ( V_89 ) ) ;
}
V_119 = ( unsigned char * ) V_45 . V_56 . V_40 ;
F_6 ( L_90 ,
V_5 , V_107 [ V_7 ] . V_120 ,
V_119 [ 0 ] , V_119 [ 1 ] , V_119 [ 2 ] , V_119 [ 3 ] ) ;
}
return 0 ;
}
