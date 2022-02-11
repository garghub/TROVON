static void F_1 (
char * V_1 ,
int * V_2 ,
const char * V_3 ,
int V_4 ,
int V_5
) {
if( V_4 < 0 ) for( V_4 = 0 ; V_3 [ V_4 ] ; V_4 ++ ) {}
while( V_5 > V_4 ) { V_1 [ ( * V_2 ) ++ ] = ' ' ; V_5 -- ; }
if( V_4 == 0 ) return;
memcpy ( & V_1 [ * V_2 ] , V_3 , V_4 ) ;
* V_2 += V_4 ;
while( ( - V_5 ) > V_4 ) { V_1 [ ( * V_2 ) ++ ] = ' ' ; V_5 ++ ; }
V_1 [ * V_2 ] = 0 ;
}
static int F_2 ( char * V_6 , const char * V_7 , T_1 V_8 ) {
int V_9 , V_10 , V_11 , V_12 ;
int V_13 = 0 ;
const char * V_14 ;
char V_15 [ 50 ] ;
V_6 [ 0 ] = 0 ;
for( V_9 = V_10 = 0 ; ( V_12 = V_7 [ V_9 ] ) != 0 ; V_9 ++ ) {
if( V_12 == '%' ) {
int V_5 = 0 ;
F_1 ( V_6 , & V_13 , & V_7 [ V_10 ] , V_9 - V_10 , 0 ) ;
V_12 = V_7 [ ++ V_9 ] ;
if( ISDIGIT ( V_12 ) || ( V_12 == '-' && ISDIGIT ( V_7 [ V_9 + 1 ] ) ) ) {
if( V_12 == '-' ) V_9 ++ ;
while( ISDIGIT ( V_7 [ V_9 ] ) ) V_5 = V_5 * 10 + V_7 [ V_9 ++ ] - '0' ;
if( V_12 == '-' ) V_5 = - V_5 ;
V_12 = V_7 [ V_9 ] ;
}
if( V_12 == 'd' ) {
int V_16 = va_arg ( V_8 , int ) ;
if( V_16 < 0 ) {
F_1 ( V_6 , & V_13 , L_1 , 1 , V_5 ) ;
V_16 = - V_16 ;
} else if( V_16 == 0 ) {
F_1 ( V_6 , & V_13 , L_2 , 1 , V_5 ) ;
}
V_11 = 0 ;
while( V_16 > 0 ) {
V_11 ++ ;
V_15 [ sizeof( V_15 ) - V_11 ] = ( V_16 % 10 ) + '0' ;
V_16 /= 10 ;
}
F_1 ( V_6 , & V_13 , & V_15 [ sizeof( V_15 ) - V_11 ] , V_11 , V_5 ) ;
} else if( V_12 == 's' ) {
V_14 = va_arg ( V_8 , const char * ) ;
F_1 ( V_6 , & V_13 , V_14 , - 1 , V_5 ) ;
} else if( V_12 == '.' && memcmp ( & V_7 [ V_9 ] , L_3 , 3 ) == 0 ) {
V_9 += 2 ;
V_11 = va_arg ( V_8 , int ) ;
V_14 = va_arg ( V_8 , const char * ) ;
F_1 ( V_6 , & V_13 , V_14 , V_11 , V_5 ) ;
} else if( V_12 == '%' ) {
F_1 ( V_6 , & V_13 , L_4 , 1 , 0 ) ;
} else{
fprintf ( V_17 , L_5 ) ;
exit ( 1 ) ;
}
V_10 = V_9 + 1 ;
}
}
F_1 ( V_6 , & V_13 , & V_7 [ V_10 ] , V_9 - V_10 , 0 ) ;
return V_13 ;
}
static int F_3 ( char * V_6 , const char * V_18 , ... ) {
T_1 V_8 ;
int V_19 ;
va_start ( V_8 , V_18 ) ;
V_19 = F_2 ( V_6 , V_18 , V_8 ) ;
va_end ( V_8 ) ;
return V_19 ;
}
static void F_4 ( char * V_20 , const char * V_21 ) {
while( ( * ( V_20 ++ ) = * ( V_21 ++ ) ) != 0 ) {}
}
static void F_5 ( char * V_20 , const char * V_21 ) {
while( * V_20 ) V_20 ++ ;
F_4 ( V_20 , V_21 ) ;
}
static struct V_22 * F_6 ( void ) {
static struct V_22 * V_23 = 0 ;
struct V_22 * V_24 ;
if( V_23 == 0 ) {
int V_9 ;
int V_25 = 100 ;
V_23 = (struct V_22 * ) calloc ( V_25 , sizeof( struct V_22 ) ) ;
if( V_23 == 0 ) {
fprintf ( V_17 , L_6 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_25 - 1 ; V_9 ++ ) V_23 [ V_9 ] . V_26 = & V_23 [ V_9 + 1 ] ;
V_23 [ V_25 - 1 ] . V_26 = 0 ;
}
V_24 = V_23 ;
V_23 = V_23 -> V_26 ;
return V_24 ;
}
static int F_7 (
struct V_22 * V_27 ,
struct V_22 * V_28
) {
int V_19 ;
V_19 = V_27 -> V_29 -> V_30 - V_28 -> V_29 -> V_30 ;
if( V_19 == 0 ) {
V_19 = ( int ) V_27 -> type - ( int ) V_28 -> type ;
}
if( V_19 == 0 && ( V_27 -> type == V_31 || V_27 -> type == V_32 ) ) {
V_19 = V_27 -> V_33 . V_34 -> V_30 - V_28 -> V_33 . V_34 -> V_30 ;
}
if( V_19 == 0 ) {
V_19 = ( int ) ( V_28 - V_27 ) ;
}
return V_19 ;
}
static struct V_22 * F_8 (
struct V_22 * V_8
) {
V_8 = (struct V_22 * ) F_9 ( ( char * ) V_8 , ( char * * ) & V_8 -> V_26 ,
( int ( * ) ( const char * , const char * ) ) F_7 ) ;
return V_8 ;
}
T_2 void F_10 (
struct V_22 * * V_35 ,
enum V_36 type ,
struct V_37 * V_29 ,
char * V_38
) {
struct V_22 * V_24 ;
V_24 = F_6 () ;
V_24 -> V_26 = * V_35 ;
* V_35 = V_24 ;
V_24 -> type = type ;
V_24 -> V_29 = V_29 ;
V_24 -> V_39 = 0 ;
if( type == V_40 ) {
V_24 -> V_33 . V_41 = (struct V_42 * ) V_38 ;
} else{
V_24 -> V_33 . V_34 = (struct V_43 * ) V_38 ;
}
}
T_2 T_3 * F_11 ( void ) {
T_3 * V_44 = ( T_3 * ) calloc ( 1 , sizeof( * V_44 ) ) ;
if( V_44 == 0 ) {
fprintf ( V_17 , L_7 ) ;
exit ( 1 ) ;
}
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
return V_44 ;
}
T_2 void F_12 ( T_3 * V_44 , int V_45 , int V_22 ) {
if( V_44 -> V_46 >= V_44 -> V_47 ) {
V_44 -> V_47 += 25 ;
V_44 -> V_48 = (struct V_49 * ) realloc ( V_44 -> V_48 ,
sizeof( V_44 -> V_48 [ 0 ] ) * V_44 -> V_47 ) ;
F_13 ( V_44 -> V_48 ) ;
}
if( V_44 -> V_46 == 0 ) {
V_44 -> V_50 = V_45 ;
V_44 -> V_51 = V_45 ;
V_44 -> V_52 = V_22 ;
} else{
if( V_44 -> V_50 < V_45 ) V_44 -> V_50 = V_45 ;
if( V_44 -> V_51 > V_45 ) {
V_44 -> V_51 = V_45 ;
V_44 -> V_52 = V_22 ;
}
}
V_44 -> V_48 [ V_44 -> V_46 ] . V_45 = V_45 ;
V_44 -> V_48 [ V_44 -> V_46 ] . V_22 = V_22 ;
V_44 -> V_46 ++ ;
}
T_2 int F_14 ( T_3 * V_44 ) {
int V_9 , V_10 , V_11 , V_53 ;
assert ( V_44 -> V_46 > 0 ) ;
V_53 = V_44 -> V_50 + 1 ;
if( V_44 -> V_54 + V_53 >= V_44 -> V_55 ) {
int V_56 = V_44 -> V_55 ;
V_44 -> V_55 = V_44 -> V_54 + V_53 + V_44 -> V_55 + 20 ;
V_44 -> V_57 = (struct V_49 * ) realloc ( V_44 -> V_57 ,
sizeof( V_44 -> V_57 [ 0 ] ) * V_44 -> V_55 ) ;
F_13 ( V_44 -> V_57 ) ;
for( V_9 = V_56 ; V_9 < V_44 -> V_55 ; V_9 ++ ) {
V_44 -> V_57 [ V_9 ] . V_45 = - 1 ;
V_44 -> V_57 [ V_9 ] . V_22 = - 1 ;
}
}
for( V_9 = V_44 -> V_54 - 1 ; V_9 >= 0 ; V_9 -- ) {
if( V_44 -> V_57 [ V_9 ] . V_45 == V_44 -> V_51 ) {
if( V_44 -> V_57 [ V_9 ] . V_22 != V_44 -> V_52 ) continue;
for( V_10 = 0 ; V_10 < V_44 -> V_46 ; V_10 ++ ) {
V_11 = V_44 -> V_48 [ V_10 ] . V_45 - V_44 -> V_51 + V_9 ;
if( V_11 < 0 || V_11 >= V_44 -> V_54 ) break;
if( V_44 -> V_48 [ V_10 ] . V_45 != V_44 -> V_57 [ V_11 ] . V_45 ) break;
if( V_44 -> V_48 [ V_10 ] . V_22 != V_44 -> V_57 [ V_11 ] . V_22 ) break;
}
if( V_10 < V_44 -> V_46 ) continue;
V_53 = 0 ;
for( V_10 = 0 ; V_10 < V_44 -> V_54 ; V_10 ++ ) {
if( V_44 -> V_57 [ V_10 ] . V_45 < 0 ) continue;
if( V_44 -> V_57 [ V_10 ] . V_45 == V_10 + V_44 -> V_51 - V_9 ) V_53 ++ ;
}
if( V_53 == V_44 -> V_46 ) {
break;
}
}
}
if( V_9 < 0 ) {
for( V_9 = 0 ; V_9 < V_44 -> V_55 - V_44 -> V_50 ; V_9 ++ ) {
if( V_44 -> V_57 [ V_9 ] . V_45 < 0 ) {
for( V_10 = 0 ; V_10 < V_44 -> V_46 ; V_10 ++ ) {
V_11 = V_44 -> V_48 [ V_10 ] . V_45 - V_44 -> V_51 + V_9 ;
if( V_11 < 0 ) break;
if( V_44 -> V_57 [ V_11 ] . V_45 >= 0 ) break;
}
if( V_10 < V_44 -> V_46 ) continue;
for( V_10 = 0 ; V_10 < V_44 -> V_54 ; V_10 ++ ) {
if( V_44 -> V_57 [ V_10 ] . V_45 == V_10 + V_44 -> V_51 - V_9 ) break;
}
if( V_10 == V_44 -> V_54 ) {
break;
}
}
}
}
for( V_10 = 0 ; V_10 < V_44 -> V_46 ; V_10 ++ ) {
V_11 = V_44 -> V_48 [ V_10 ] . V_45 - V_44 -> V_51 + V_9 ;
V_44 -> V_57 [ V_11 ] = V_44 -> V_48 [ V_10 ] ;
if( V_11 >= V_44 -> V_54 ) V_44 -> V_54 = V_11 + 1 ;
}
V_44 -> V_46 = 0 ;
return V_9 - V_44 -> V_51 ;
}
void F_15 ( struct V_58 * V_59 )
{
struct V_43 * V_34 ;
for( V_34 = V_59 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
if( V_34 -> V_60 == 0 ) {
int V_9 , V_10 ;
for( V_9 = 0 ; V_9 < V_34 -> V_61 && V_34 -> V_60 == 0 ; V_9 ++ ) {
struct V_37 * V_29 = V_34 -> V_62 [ V_9 ] ;
if( V_29 -> type == V_63 ) {
for( V_10 = 0 ; V_10 < V_29 -> V_64 ; V_10 ++ ) {
if( V_29 -> V_65 [ V_10 ] -> V_66 >= 0 ) {
V_34 -> V_60 = V_29 -> V_65 [ V_10 ] ;
break;
}
}
} else if( V_29 -> V_66 >= 0 ) {
V_34 -> V_60 = V_34 -> V_62 [ V_9 ] ;
}
}
}
}
return;
}
void F_16 ( struct V_58 * V_67 )
{
int V_9 , V_10 ;
struct V_43 * V_34 ;
int V_68 ;
for( V_9 = 0 ; V_9 < V_67 -> V_69 ; V_9 ++ ) {
V_67 -> V_70 [ V_9 ] -> V_71 = V_72 ;
}
for( V_9 = V_67 -> V_73 ; V_9 < V_67 -> V_69 ; V_9 ++ ) {
V_67 -> V_70 [ V_9 ] -> V_74 = F_17 () ;
}
do{
V_68 = 0 ;
for( V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
if( V_34 -> V_75 -> V_71 ) continue;
for( V_9 = 0 ; V_9 < V_34 -> V_61 ; V_9 ++ ) {
struct V_37 * V_29 = V_34 -> V_62 [ V_9 ] ;
assert ( V_29 -> type == V_76 || V_29 -> V_71 == V_72 ) ;
if( V_29 -> V_71 == V_72 ) break;
}
if( V_9 == V_34 -> V_61 ) {
V_34 -> V_75 -> V_71 = V_77 ;
V_68 = 1 ;
}
}
}while( V_68 );
do{
struct V_37 * V_78 , * V_79 ;
V_68 = 0 ;
for( V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
V_78 = V_34 -> V_75 ;
for( V_9 = 0 ; V_9 < V_34 -> V_61 ; V_9 ++ ) {
V_79 = V_34 -> V_62 [ V_9 ] ;
if( V_79 -> type == V_80 ) {
V_68 += F_18 ( V_78 -> V_74 , V_79 -> V_30 ) ;
break;
} else if( V_79 -> type == V_63 ) {
for( V_10 = 0 ; V_10 < V_79 -> V_64 ; V_10 ++ ) {
V_68 += F_18 ( V_78 -> V_74 , V_79 -> V_65 [ V_10 ] -> V_30 ) ;
}
break;
} else if( V_78 == V_79 ) {
if( V_78 -> V_71 == V_72 ) break;
} else{
V_68 += F_19 ( V_78 -> V_74 , V_79 -> V_74 ) ;
if( V_79 -> V_71 == V_72 ) break;
}
}
}
}while( V_68 );
return;
}
void F_20 ( struct V_58 * V_67 )
{
struct V_37 * V_29 ;
struct V_43 * V_34 ;
F_21 () ;
if( V_67 -> V_81 ) {
V_29 = F_22 ( V_67 -> V_81 ) ;
if( V_29 == 0 ) {
F_23 ( V_67 -> V_82 , 0 ,
L_8 , V_67 -> V_81 , V_67 -> V_83 -> V_75 -> V_84 ) ;
V_67 -> V_85 ++ ;
V_29 = V_67 -> V_83 -> V_75 ;
}
} else{
V_29 = V_67 -> V_83 -> V_75 ;
}
for( V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
int V_9 ;
for( V_9 = 0 ; V_9 < V_34 -> V_61 ; V_9 ++ ) {
if( V_34 -> V_62 [ V_9 ] == V_29 ) {
F_23 ( V_67 -> V_82 , 0 ,
L_9 , V_29 -> V_84 ) ;
V_67 -> V_85 ++ ;
}
}
}
for( V_34 = V_29 -> V_43 ; V_34 ; V_34 = V_34 -> V_86 ) {
struct V_87 * V_88 ;
V_34 -> V_89 = 1 ;
V_88 = F_24 ( V_34 , 0 ) ;
F_18 ( V_88 -> V_90 , 0 ) ;
}
( void ) F_25 ( V_67 ) ;
return;
}
T_2 struct V_42 * F_25 ( struct V_58 * V_67 )
{
struct V_87 * V_91 , * V_92 ;
struct V_42 * V_41 ;
F_26 () ;
V_92 = F_27 () ;
V_41 = F_28 ( V_92 ) ;
if( V_41 ) {
struct V_87 * V_33 , * V_93 ;
for( V_33 = V_92 , V_93 = V_41 -> V_92 ; V_33 && V_93 ; V_33 = V_33 -> V_92 , V_93 = V_93 -> V_92 ) {
F_29 ( & V_93 -> V_94 , V_33 -> V_94 ) ;
F_30 ( V_33 -> V_95 ) ;
V_33 -> V_95 = V_33 -> V_94 = 0 ;
}
V_91 = F_31 () ;
F_32 ( V_91 ) ;
} else{
F_33 ( V_67 ) ;
F_34 () ;
V_91 = F_31 () ;
V_41 = F_35 () ;
F_13 ( V_41 ) ;
V_41 -> V_92 = V_92 ;
V_41 -> V_91 = V_91 ;
V_41 -> V_96 = V_67 -> V_97 ++ ;
V_41 -> V_8 = 0 ;
F_36 ( V_41 , V_41 -> V_92 ) ;
F_37 ( V_67 , V_41 ) ;
}
return V_41 ;
}
T_2 int F_38 ( struct V_37 * V_98 , struct V_37 * V_99 )
{
int V_9 ;
if( V_98 == V_99 ) return 1 ;
if( V_98 -> type != V_63 ) return 0 ;
if( V_99 -> type != V_63 ) return 0 ;
if( V_98 -> V_64 != V_99 -> V_64 ) return 0 ;
for( V_9 = 0 ; V_9 < V_98 -> V_64 ; V_9 ++ ) {
if( V_98 -> V_65 [ V_9 ] != V_99 -> V_65 [ V_9 ] ) return 0 ;
}
return 1 ;
}
T_2 void F_37 ( struct V_58 * V_67 , struct V_42 * V_41 )
{
struct V_87 * V_91 ;
struct V_87 * V_100 ;
struct V_87 * V_101 ;
struct V_37 * V_29 ;
struct V_37 * V_102 ;
struct V_42 * V_103 ;
for( V_91 = V_41 -> V_91 ; V_91 ; V_91 = V_91 -> V_26 ) V_91 -> V_104 = V_105 ;
for( V_91 = V_41 -> V_91 ; V_91 ; V_91 = V_91 -> V_26 ) {
if( V_91 -> V_104 == V_106 ) continue;
if( V_91 -> V_107 >= V_91 -> V_34 -> V_61 ) continue;
F_39 () ;
V_29 = V_91 -> V_34 -> V_62 [ V_91 -> V_107 ] ;
for( V_100 = V_91 ; V_100 ; V_100 = V_100 -> V_26 ) {
if( V_100 -> V_104 == V_106 ) continue;
if( V_100 -> V_107 >= V_100 -> V_34 -> V_61 ) continue;
V_102 = V_100 -> V_34 -> V_62 [ V_100 -> V_107 ] ;
if( ! F_38 ( V_102 , V_29 ) ) continue;
V_100 -> V_104 = V_106 ;
V_101 = F_24 ( V_100 -> V_34 , V_100 -> V_107 + 1 ) ;
F_40 ( & V_101 -> V_94 , V_100 ) ;
}
V_103 = F_25 ( V_67 ) ;
if( V_29 -> type == V_63 ) {
int V_9 ;
for( V_9 = 0 ; V_9 < V_29 -> V_64 ; V_9 ++ ) {
F_10 ( & V_41 -> V_8 , V_40 , V_29 -> V_65 [ V_9 ] , ( char * ) V_103 ) ;
}
} else{
F_10 ( & V_41 -> V_8 , V_40 , V_29 , ( char * ) V_103 ) ;
}
}
}
void F_41 ( struct V_58 * V_67 )
{
int V_9 ;
struct V_87 * V_91 , * V_108 ;
struct V_42 * V_41 ;
struct V_109 * V_110 ;
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
V_41 = V_67 -> V_111 [ V_9 ] ;
if( V_41 ) {
for( V_91 = V_41 -> V_91 ; V_91 ; V_91 = V_91 -> V_26 ) {
V_91 -> V_41 = V_41 ;
}
}
}
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
V_41 = V_67 -> V_111 [ V_9 ] ;
if( V_41 ) {
for( V_91 = V_41 -> V_91 ; V_91 ; V_91 = V_91 -> V_26 ) {
for( V_110 = V_91 -> V_94 ; V_110 ; V_110 = V_110 -> V_26 ) {
V_108 = V_110 -> V_91 ;
F_40 ( & V_108 -> V_95 , V_91 ) ;
}
}
}
}
}
void F_42 ( struct V_58 * V_67 )
{
int V_9 ;
struct V_87 * V_91 ;
struct V_109 * V_110 ;
int V_68 ;
int V_112 ;
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
if( V_67 -> V_111 [ V_9 ] ) {
for( V_91 = V_67 -> V_111 [ V_9 ] -> V_91 ; V_91 ; V_91 = V_91 -> V_26 ) {
V_91 -> V_104 = V_105 ;
}
}
}
do{
V_68 = 0 ;
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
if( V_67 -> V_111 [ V_9 ] ) {
for( V_91 = V_67 -> V_111 [ V_9 ] -> V_91 ; V_91 ; V_91 = V_91 -> V_26 ) {
if( V_91 -> V_104 == V_106 ) continue;
for( V_110 = V_91 -> V_95 ; V_110 ; V_110 = V_110 -> V_26 ) {
V_112 = F_19 ( V_110 -> V_91 -> V_90 , V_91 -> V_90 ) ;
if( V_112 ) {
V_110 -> V_91 -> V_104 = V_105 ;
V_68 = 1 ;
}
}
V_91 -> V_104 = V_106 ;
}
}
}
}while( V_68 );
}
void F_43 ( struct V_58 * V_67 )
{
int V_9 , V_10 ;
struct V_87 * V_91 ;
struct V_42 * V_41 ;
struct V_37 * V_29 ;
struct V_43 * V_34 ;
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
V_41 = V_67 -> V_111 [ V_9 ] ;
if( V_41 ) {
for( V_91 = V_41 -> V_91 ; V_91 ; V_91 = V_91 -> V_26 ) {
if( V_91 -> V_34 -> V_61 == V_91 -> V_107 ) {
for( V_10 = 0 ; V_10 < V_67 -> V_73 ; V_10 ++ ) {
if( F_44 ( V_91 -> V_90 , V_10 ) ) {
F_10 ( & V_41 -> V_8 , V_31 , V_67 -> V_70 [ V_10 ] , ( char * ) V_91 -> V_34 ) ;
}
}
}
}
}
}
if( V_67 -> V_81 ) {
V_29 = F_22 ( V_67 -> V_81 ) ;
if( V_29 == 0 ) V_29 = V_67 -> V_83 -> V_75 ;
} else{
V_29 = V_67 -> V_83 -> V_75 ;
}
F_10 ( & V_67 -> V_111 [ 0 ] -> V_8 , V_113 , V_29 , 0 ) ;
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
struct V_22 * V_8 , * V_114 ;
V_41 = V_67 -> V_111 [ V_9 ] ;
V_41 -> V_8 = F_8 ( V_41 -> V_8 ) ;
for( V_8 = V_41 -> V_8 ; V_8 && V_8 -> V_26 ; V_8 = V_8 -> V_26 ) {
for( V_114 = V_8 -> V_26 ; V_114 && V_114 -> V_29 == V_8 -> V_29 ; V_114 = V_114 -> V_26 ) {
V_67 -> V_115 += F_45 ( V_8 , V_114 ) ;
}
}
}
for( V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) V_34 -> V_116 = V_72 ;
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
struct V_22 * V_8 ;
for( V_8 = V_67 -> V_111 [ V_9 ] -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_31 ) V_8 -> V_33 . V_34 -> V_116 = V_77 ;
}
}
for( V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
if( V_34 -> V_116 ) continue;
F_23 ( V_67 -> V_82 , V_34 -> V_117 , L_10 ) ;
V_67 -> V_85 ++ ;
}
}
static int F_45 (
struct V_22 * V_118 ,
struct V_22 * V_119
) {
struct V_37 * V_120 , * V_121 ;
int V_122 = 0 ;
assert ( V_118 -> V_29 == V_119 -> V_29 ) ;
if( V_118 -> type == V_40 && V_119 -> type == V_40 ) {
V_119 -> type = V_123 ;
V_122 ++ ;
}
if( V_118 -> type == V_40 && V_119 -> type == V_31 ) {
V_120 = V_118 -> V_29 ;
V_121 = V_119 -> V_33 . V_34 -> V_60 ;
if( V_121 == 0 || V_120 -> V_66 < 0 || V_121 -> V_66 < 0 ) {
V_119 -> type = V_124 ;
V_122 ++ ;
} else if( V_120 -> V_66 > V_121 -> V_66 ) {
V_119 -> type = V_125 ;
} else if( V_120 -> V_66 < V_121 -> V_66 ) {
V_118 -> type = V_126 ;
} else if( V_120 -> V_66 == V_121 -> V_66 && V_120 -> V_127 == V_128 ) {
V_119 -> type = V_125 ;
} else if( V_120 -> V_66 == V_121 -> V_66 && V_120 -> V_127 == V_129 ) {
V_118 -> type = V_126 ;
} else{
assert ( V_120 -> V_66 == V_121 -> V_66 && V_120 -> V_127 == V_130 ) ;
V_118 -> type = ERROR ;
}
} else if( V_118 -> type == V_31 && V_119 -> type == V_31 ) {
V_120 = V_118 -> V_33 . V_34 -> V_60 ;
V_121 = V_119 -> V_33 . V_34 -> V_60 ;
if( V_120 == 0 || V_121 == 0 || V_120 -> V_66 < 0 ||
V_121 -> V_66 < 0 || V_120 -> V_66 == V_121 -> V_66 ) {
V_119 -> type = V_131 ;
V_122 ++ ;
} else if( V_120 -> V_66 > V_121 -> V_66 ) {
V_119 -> type = V_125 ;
} else if( V_120 -> V_66 < V_121 -> V_66 ) {
V_118 -> type = V_125 ;
}
} else{
assert (
V_118 -> type == V_126 ||
V_118 -> type == V_125 ||
V_118 -> type == V_123 ||
V_118 -> type == V_124 ||
V_118 -> type == V_131 ||
V_119 -> type == V_126 ||
V_119 -> type == V_125 ||
V_119 -> type == V_123 ||
V_119 -> type == V_124 ||
V_119 -> type == V_131
) ;
}
return V_122 ;
}
T_2 struct V_87 * F_46 ( void ) {
struct V_87 * V_101 ;
if( V_23 == 0 ) {
int V_9 ;
int V_25 = 3 ;
V_23 = (struct V_87 * ) calloc ( V_25 , sizeof( struct V_87 ) ) ;
if( V_23 == 0 ) {
fprintf ( V_17 , L_11 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_25 - 1 ; V_9 ++ ) V_23 [ V_9 ] . V_26 = & V_23 [ V_9 + 1 ] ;
V_23 [ V_25 - 1 ] . V_26 = 0 ;
}
V_101 = V_23 ;
V_23 = V_23 -> V_26 ;
return V_101 ;
}
T_2 void F_47 ( struct V_87 * V_132 )
{
V_132 -> V_26 = V_23 ;
V_23 = V_132 ;
}
void F_21 ( void ) {
V_133 = 0 ;
V_134 = & V_133 ;
V_135 = 0 ;
V_136 = & V_135 ;
F_48 () ;
return;
}
void F_39 ( void ) {
V_133 = 0 ;
V_134 = & V_133 ;
V_135 = 0 ;
V_136 = & V_135 ;
F_49 ( 0 ) ;
return;
}
struct V_87 * F_50 (
struct V_43 * V_34 ,
int V_107
) {
struct V_87 * V_91 , V_137 ;
assert ( V_134 != 0 ) ;
V_137 . V_34 = V_34 ;
V_137 . V_107 = V_107 ;
V_91 = F_51 ( & V_137 ) ;
if( V_91 == 0 ) {
V_91 = F_46 () ;
V_91 -> V_34 = V_34 ;
V_91 -> V_107 = V_107 ;
V_91 -> V_90 = F_17 () ;
V_91 -> V_41 = 0 ;
V_91 -> V_95 = V_91 -> V_94 = 0 ;
V_91 -> V_26 = 0 ;
V_91 -> V_92 = 0 ;
* V_134 = V_91 ;
V_134 = & V_91 -> V_26 ;
F_52 ( V_91 ) ;
}
return V_91 ;
}
struct V_87 * F_24 ( struct V_43 * V_34 , int V_107 )
{
struct V_87 * V_91 , V_137 ;
assert ( V_136 != 0 ) ;
assert ( V_134 != 0 ) ;
V_137 . V_34 = V_34 ;
V_137 . V_107 = V_107 ;
V_91 = F_51 ( & V_137 ) ;
if( V_91 == 0 ) {
V_91 = F_46 () ;
V_91 -> V_34 = V_34 ;
V_91 -> V_107 = V_107 ;
V_91 -> V_90 = F_17 () ;
V_91 -> V_41 = 0 ;
V_91 -> V_95 = V_91 -> V_94 = 0 ;
V_91 -> V_26 = 0 ;
V_91 -> V_92 = 0 ;
* V_134 = V_91 ;
V_134 = & V_91 -> V_26 ;
* V_136 = V_91 ;
V_136 = & V_91 -> V_92 ;
F_52 ( V_91 ) ;
}
return V_91 ;
}
void F_33 ( struct V_58 * V_67 )
{
struct V_87 * V_91 , * V_88 ;
struct V_43 * V_34 , * V_138 ;
struct V_37 * V_29 , * V_139 ;
int V_9 , V_107 ;
assert ( V_134 != 0 ) ;
for( V_91 = V_133 ; V_91 ; V_91 = V_91 -> V_26 ) {
V_34 = V_91 -> V_34 ;
V_107 = V_91 -> V_107 ;
if( V_107 >= V_34 -> V_61 ) continue;
V_29 = V_34 -> V_62 [ V_107 ] ;
if( V_29 -> type == V_76 ) {
if( V_29 -> V_43 == 0 && V_29 != V_67 -> V_140 ) {
F_23 ( V_67 -> V_82 , V_34 -> line , L_12 ,
V_29 -> V_84 ) ;
V_67 -> V_85 ++ ;
}
for( V_138 = V_29 -> V_43 ; V_138 ; V_138 = V_138 -> V_86 ) {
V_88 = F_50 ( V_138 , 0 ) ;
for( V_9 = V_107 + 1 ; V_9 < V_34 -> V_61 ; V_9 ++ ) {
V_139 = V_34 -> V_62 [ V_9 ] ;
if( V_139 -> type == V_80 ) {
F_18 ( V_88 -> V_90 , V_139 -> V_30 ) ;
break;
} else if( V_139 -> type == V_63 ) {
int V_11 ;
for( V_11 = 0 ; V_11 < V_139 -> V_64 ; V_11 ++ ) {
F_18 ( V_88 -> V_90 , V_139 -> V_65 [ V_11 ] -> V_30 ) ;
}
break;
} else{
F_19 ( V_88 -> V_90 , V_139 -> V_74 ) ;
if( V_139 -> V_71 == V_72 ) break;
}
}
if( V_9 == V_34 -> V_61 ) F_40 ( & V_91 -> V_95 , V_88 ) ;
}
}
}
return;
}
void F_34 ( void ) {
V_133 = (struct V_87 * ) F_9 ( ( char * ) V_133 , ( char * * ) & ( V_133 -> V_26 ) ,
V_141 ) ;
V_134 = 0 ;
return;
}
void F_26 ( void ) {
V_135 = (struct V_87 * ) F_9 ( ( char * ) V_133 , ( char * * ) & ( V_133 -> V_92 ) ,
V_141 ) ;
V_136 = 0 ;
return;
}
struct V_87 * F_31 ( void ) {
struct V_87 * V_132 ;
V_132 = V_133 ;
V_133 = 0 ;
V_134 = 0 ;
return V_132 ;
}
struct V_87 * F_27 ( void ) {
struct V_87 * V_132 ;
V_132 = V_135 ;
V_135 = 0 ;
V_136 = 0 ;
return V_132 ;
}
void F_32 ( struct V_87 * V_91 )
{
struct V_87 * V_142 ;
for(; V_91 ; V_91 = V_142 ) {
V_142 = V_91 -> V_26 ;
assert ( V_91 -> V_95 == 0 ) ;
assert ( V_91 -> V_94 == 0 ) ;
if( V_91 -> V_90 ) F_53 ( V_91 -> V_90 ) ;
F_47 ( V_91 ) ;
}
return;
}
void F_23 ( const char * V_82 , int V_143 , const char * V_18 , ... ) {
T_1 V_8 ;
fprintf ( V_17 , L_13 , V_82 , V_143 ) ;
va_start ( V_8 , V_18 ) ;
vfprintf ( V_17 , V_18 , V_8 ) ;
va_end ( V_8 ) ;
fprintf ( V_17 , L_14 ) ;
}
T_2 char *
F_54 ( char * V_144 )
{
char * V_145 ;
char * V_146 ;
V_145 = strrchr ( V_144 , '/' ) ;
#ifdef F_55
if ( ! V_145 )
V_145 = strrchr ( V_144 , '\\' ) ;
#endif
if ( ! V_145 ) {
V_146 = ( char * ) malloc ( strlen ( V_144 ) + 1 ) ;
F_13 ( V_146 ) ;
strcpy ( V_146 , V_144 ) ;
}
else {
V_145 ++ ;
V_146 = ( char * ) malloc ( strlen ( V_145 ) + 1 ) ;
F_13 ( V_146 ) ;
strcpy ( V_146 , V_145 ) ;
}
return V_146 ;
}
static void F_56 ( void * V_38 ) {
char * V_14 = ( char * ) V_38 ;
char * * V_147 ;
V_148 ++ ;
V_149 = ( char * * ) realloc ( V_149 , sizeof( V_149 [ 0 ] ) * V_148 ) ;
F_13 ( V_149 ) ;
V_147 = & V_149 [ V_148 - 1 ] ;
* V_147 = ( char * ) malloc ( F_57 ( V_14 ) + 1 ) ;
F_13 ( * V_147 ) ;
F_4 ( * V_147 , V_14 ) ;
for( V_14 = * V_147 ; * V_14 && * V_14 != '=' ; V_14 ++ ) {}
* V_14 = 0 ;
}
static void F_58 ( void * V_38 ) {
char * V_14 = ( char * ) V_38 ;
V_150 = ( char * ) malloc ( F_57 ( V_14 ) + 1 ) ;
F_13 ( V_150 ) ;
F_4 ( V_150 , V_14 ) ;
}
static struct V_43 * F_59 ( struct V_43 * V_151 , struct V_43 * V_152 ) {
struct V_43 * V_153 = 0 ;
struct V_43 * * V_154 = & V_153 ;
while( V_151 && V_152 ) {
if( V_151 -> V_155 < V_152 -> V_155 ) {
* V_154 = V_151 ;
V_154 = & V_151 -> V_26 ;
V_151 = V_151 -> V_26 ;
} else{
* V_154 = V_152 ;
V_154 = & V_152 -> V_26 ;
V_152 = V_152 -> V_26 ;
}
}
if( V_151 ) {
* V_154 = V_151 ;
} else{
* V_154 = V_152 ;
}
return V_153 ;
}
static struct V_43 * F_60 ( struct V_43 * V_34 ) {
unsigned int V_9 ;
struct V_43 * V_156 ;
struct V_43 * V_33 [ 32 ] ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
while( V_34 ) {
V_156 = V_34 -> V_26 ;
V_34 -> V_26 = 0 ;
for( V_9 = 0 ; V_9 < sizeof( V_33 ) / sizeof( V_33 [ 0 ] ) && V_33 [ V_9 ] ; V_9 ++ ) {
V_34 = F_59 ( V_33 [ V_9 ] , V_34 ) ;
V_33 [ V_9 ] = 0 ;
}
V_33 [ V_9 ] = V_34 ;
V_34 = V_156 ;
}
V_34 = 0 ;
for( V_9 = 0 ; V_9 < sizeof( V_33 ) / sizeof( V_33 [ 0 ] ) ; V_9 ++ ) {
V_34 = F_59 ( V_33 [ V_9 ] , V_34 ) ;
}
return V_34 ;
}
static void F_61 ( const char * V_157 , int V_158 ) {
int V_159 = F_57 ( V_157 ) ;
printf ( L_15 , V_157 ,
35 - V_159 , L_16 ,
V_158 ) ;
}
int main ( int T_4 V_160 , char * * V_161 )
{
static int V_162 = 0 ;
static int V_163 = 0 ;
static int V_164 = 0 ;
static int V_165 = 0 ;
static int V_166 = 0 ;
static int V_167 = 0 ;
static int V_168 = 0 ;
static int V_169 = 0 ;
static int V_170 = 0 ;
static struct V_171 V_172 [] = {
{ V_173 , L_17 , & V_164 , NULL , L_18 } ,
{ V_173 , L_19 , & V_165 , NULL , L_20 } ,
{ V_174 , L_21 , NULL , F_56 , L_22 } ,
{ V_174 , L_23 , & V_175 , NULL , L_24 } ,
{ V_173 , L_25 , & V_163 , NULL , L_26 } ,
{ V_174 , L_27 , & V_175 , NULL , L_28 } ,
{ V_173 , L_29 , & V_168 , NULL , L_30 } ,
{ V_173 , L_31 , & V_169 , NULL , L_32 } ,
{ V_174 , L_33 , & V_175 , NULL , L_34 } ,
{ V_173 , L_35 , & V_176 , NULL ,
L_36 } ,
{ V_173 , L_37 , & V_166 , NULL , L_38 } ,
{ V_173 , L_39 , & V_170 , NULL , L_40 } ,
{ V_173 , L_41 , & V_167 , NULL ,
L_42 } ,
{ V_173 , L_43 , & V_162 , NULL , L_44 } ,
{ V_174 , L_45 , NULL , F_58 , L_46 } ,
{ V_174 , L_47 , & V_175 , NULL , L_48 } ,
{ V_173 , NULL , NULL , NULL , NULL }
} ;
int V_9 ;
int V_177 ;
struct V_58 V_178 ;
struct V_43 * V_34 ;
F_62 ( V_161 , V_172 , V_17 ) ;
if( V_162 ) {
printf ( L_49 ) ;
exit ( 0 ) ;
}
if( F_63 () != 1 ) {
fprintf ( V_17 , L_50 ) ;
exit ( 1 ) ;
}
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_85 = 0 ;
F_64 () ;
F_65 () ;
F_66 () ;
V_178 . V_179 = V_161 [ 0 ] ;
V_178 . V_82 = F_67 ( 0 ) ;
V_178 . V_164 = V_164 ;
V_178 . V_169 = V_169 ;
F_68 ( L_51 ) ;
V_178 . V_140 = F_68 ( L_52 ) ;
V_178 . V_140 -> V_180 = 0 ;
V_178 . V_181 = F_54 ( V_178 . V_82 ) ;
F_69 ( & V_178 ) ;
if( V_178 . V_85 ) exit ( V_178 . V_85 ) ;
if( V_178 . V_182 == 0 || V_178 . V_43 == NULL ) {
fprintf ( V_17 , L_53 ) ;
exit ( 1 ) ;
}
F_68 ( L_54 ) ;
V_178 . V_69 = F_70 () ;
V_178 . V_70 = F_71 () ;
for( V_9 = 0 ; V_9 < V_178 . V_69 ; V_9 ++ ) V_178 . V_70 [ V_9 ] -> V_30 = V_9 ;
qsort ( V_178 . V_70 , V_178 . V_69 , sizeof( struct V_37 * ) , V_183 ) ;
for( V_9 = 0 ; V_9 < V_178 . V_69 ; V_9 ++ ) V_178 . V_70 [ V_9 ] -> V_30 = V_9 ;
while( V_178 . V_70 [ V_9 - 1 ] -> type == V_63 ) { V_9 -- ; }
assert ( strcmp ( V_178 . V_70 [ V_9 - 1 ] -> V_84 , L_54 ) == 0 ) ;
V_178 . V_69 = V_9 - 1 ;
for( V_9 = 1 ; ISUPPER ( V_178 . V_70 [ V_9 ] -> V_84 [ 0 ] ) ; V_9 ++ ) ;
V_178 . V_73 = V_9 ;
for( V_9 = 0 , V_34 = V_178 . V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
V_34 -> V_155 = V_34 -> V_184 ? V_9 ++ : - 1 ;
}
for( V_34 = V_178 . V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
if( V_34 -> V_155 < 0 ) V_34 -> V_155 = V_9 ++ ;
}
V_178 . V_83 = V_178 . V_43 ;
V_178 . V_43 = F_60 ( V_178 . V_43 ) ;
if( V_163 ) {
F_72 ( & V_178 ) ;
} else{
F_73 ( V_178 . V_73 + 1 ) ;
F_15 ( & V_178 ) ;
F_16 ( & V_178 ) ;
V_178 . V_97 = 0 ;
F_20 ( & V_178 ) ;
V_178 . V_111 = F_74 () ;
F_41 ( & V_178 ) ;
F_42 ( & V_178 ) ;
F_43 ( & V_178 ) ;
if( V_165 == 0 ) F_75 ( & V_178 ) ;
if( V_170 == 0 ) F_76 ( & V_178 ) ;
if( ! V_166 ) F_77 ( & V_178 ) ;
F_78 ( & V_178 , V_168 ) ;
if( ! V_168 ) F_79 ( & V_178 ) ;
}
if( V_167 ) {
printf ( L_55 ) ;
F_61 ( L_56 , V_178 . V_73 ) ;
F_61 ( L_57 , V_178 . V_69 - V_178 . V_73 ) ;
F_61 ( L_58 , V_178 . V_69 ) ;
F_61 ( L_59 , V_178 . V_182 ) ;
F_61 ( L_60 , V_178 . V_185 ) ;
F_61 ( L_61 , V_178 . V_115 ) ;
F_61 ( L_62 , V_178 . V_186 ) ;
F_61 ( L_63 , V_178 . V_187 ) ;
}
if( V_178 . V_115 > 0 ) {
fprintf ( V_17 , L_64 , V_178 . V_115 ) ;
}
V_177 = ( ( V_178 . V_85 > 0 ) || ( V_178 . V_115 > 0 ) ) ? 1 : 0 ;
exit ( V_177 ) ;
return ( V_177 ) ;
}
static char * F_80 (
char * V_98 ,
char * V_99 ,
int (* F_81)( const char * , const char * ) ,
int V_188
) {
char * V_189 , * V_190 ;
if( V_98 == 0 ) {
V_190 = V_99 ;
} else if( V_99 == 0 ) {
V_190 = V_98 ;
} else{
if( (* F_81)( V_98 , V_99 ) <= 0 ) {
V_189 = V_98 ;
V_98 = F_82 ( V_98 ) ;
} else{
V_189 = V_99 ;
V_99 = F_82 ( V_99 ) ;
}
V_190 = V_189 ;
while( V_98 && V_99 ) {
if( (* F_81)( V_98 , V_99 ) <= 0 ) {
F_82 ( V_189 ) = V_98 ;
V_189 = V_98 ;
V_98 = F_82 ( V_98 ) ;
} else{
F_82 ( V_189 ) = V_99 ;
V_189 = V_99 ;
V_99 = F_82 ( V_99 ) ;
}
}
if( V_98 ) F_82 ( V_189 ) = V_98 ;
else F_82 ( V_189 ) = V_99 ;
}
return V_190 ;
}
T_2 char * F_9 (
char * V_191 ,
char * * V_26 ,
int (* F_81)( const char * , const char * )
) {
unsigned long V_188 ;
char * V_192 ;
char * V_193 [ V_194 ] ;
int V_9 ;
V_188 = ( unsigned long ) ( ( char * ) V_26 - ( char * ) V_191 ) ;
for( V_9 = 0 ; V_9 < V_194 ; V_9 ++ ) V_193 [ V_9 ] = 0 ;
while( V_191 ) {
V_192 = V_191 ;
V_191 = F_82 ( V_191 ) ;
F_82 ( V_192 ) = 0 ;
for( V_9 = 0 ; V_9 < V_194 - 1 && V_193 [ V_9 ] != 0 ; V_9 ++ ) {
V_192 = F_80 ( V_192 , V_193 [ V_9 ] , F_81 , ( int ) V_188 ) ;
V_193 [ V_9 ] = 0 ;
}
V_193 [ V_9 ] = V_192 ;
}
V_192 = 0 ;
for( V_9 = 0 ; V_9 < V_194 ; V_9 ++ ) if( V_193 [ V_9 ] ) V_192 = F_80 ( V_193 [ V_9 ] , V_192 , F_81 , ( int ) V_188 ) ;
return V_192 ;
}
static void F_83 ( int V_53 , int V_11 , T_5 * V_195 )
{
int V_196 , V_9 ;
if( V_161 [ 0 ] ) fprintf ( V_195 , L_65 , V_161 [ 0 ] ) ;
V_196 = F_57 ( V_161 [ 0 ] ) + 1 ;
for( V_9 = 1 ; V_9 < V_53 && V_161 [ V_9 ] ; V_9 ++ ) {
fprintf ( V_195 , L_66 , V_161 [ V_9 ] ) ;
V_196 += F_57 ( V_161 [ V_9 ] ) + 1 ;
}
V_196 += V_11 ;
for(; V_161 [ V_9 ] ; V_9 ++ ) fprintf ( V_195 , L_66 , V_161 [ V_9 ] ) ;
if( V_196 < 20 ) {
fprintf ( V_195 , L_67 , V_196 , L_68 ) ;
} else{
fprintf ( V_195 , L_69 , V_196 - 7 , L_68 ) ;
}
}
static int F_84 ( int V_53 )
{
int V_9 ;
int V_197 = 0 ;
if( V_161 != 0 && * V_161 != 0 ) {
for( V_9 = 1 ; V_161 [ V_9 ] ; V_9 ++ ) {
if( V_197 || ! F_85 ( V_161 [ V_9 ] ) ) {
if( V_53 == 0 ) return V_9 ;
V_53 -- ;
}
if( strcmp ( V_161 [ V_9 ] , L_70 ) == 0 ) V_197 = 1 ;
}
}
return - 1 ;
}
static int F_86 ( int V_9 , T_5 * V_195 )
{
int V_16 ;
int V_122 = 0 ;
int V_10 ;
for( V_10 = 0 ; V_198 [ V_10 ] . V_199 ; V_10 ++ ) {
if( strncmp ( & V_161 [ V_9 ] [ 1 ] , V_198 [ V_10 ] . V_199 , F_57 ( V_198 [ V_10 ] . V_199 ) ) == 0 ) break;
}
V_16 = V_161 [ V_9 ] [ 0 ] == '-' ? 1 : 0 ;
if( V_198 [ V_10 ] . V_199 == 0 ) {
if( V_195 ) {
fprintf ( V_195 , L_71 , V_200 ) ;
F_83 ( V_9 , 1 , V_195 ) ;
}
V_122 ++ ;
} else if( V_198 [ V_10 ] . V_38 == & V_175 ) {
} else if( V_198 [ V_10 ] . type == V_173 ) {
* ( ( int * ) V_198 [ V_10 ] . V_38 ) = V_16 ;
} else if( V_198 [ V_10 ] . type == V_201 ) {
V_198 [ V_10 ] . F_87 ( & V_16 ) ;
} else if( V_198 [ V_10 ] . type == V_174 ) {
V_198 [ V_10 ] . F_87 ( & V_161 [ V_9 ] [ 2 ] ) ;
} else{
if( V_195 ) {
fprintf ( V_195 , L_72 , V_200 ) ;
F_83 ( V_9 , 1 , V_195 ) ;
}
V_122 ++ ;
}
return V_122 ;
}
static int F_88 ( int V_9 , T_5 * V_195 )
{
int V_202 = 0 ;
double V_203 = 0.0 ;
char * V_204 = 0 , * V_205 ;
char * V_145 ;
int V_10 ;
int V_122 = 0 ;
V_145 = strchr ( V_161 [ V_9 ] , '=' ) ;
assert ( V_145 != 0 ) ;
* V_145 = 0 ;
for( V_10 = 0 ; V_198 [ V_10 ] . V_199 ; V_10 ++ ) {
if( strcmp ( V_161 [ V_9 ] , V_198 [ V_10 ] . V_199 ) == 0 ) break;
}
* V_145 = '=' ;
if( V_198 [ V_10 ] . V_199 == 0 ) {
if( V_195 ) {
fprintf ( V_195 , L_71 , V_200 ) ;
F_83 ( V_9 , 0 , V_195 ) ;
}
V_122 ++ ;
} else{
V_145 ++ ;
switch( V_198 [ V_10 ] . type ) {
case V_173 :
case V_201 :
if( V_195 ) {
fprintf ( V_195 , L_73 , V_200 ) ;
F_83 ( V_9 , 0 , V_195 ) ;
}
V_122 ++ ;
break;
case V_206 :
case V_207 :
V_203 = strtod ( V_145 , & V_205 ) ;
if( * V_205 ) {
if( V_195 ) {
fprintf ( V_195 ,
L_74 , V_200 ) ;
F_83 ( V_9 , ( int ) ( ( char * ) V_205 - ( char * ) V_161 [ V_9 ] ) , V_195 ) ;
}
V_122 ++ ;
}
break;
case V_208 :
case V_209 :
V_202 = ( int ) strtol ( V_145 , & V_205 , 0 ) ;
if( * V_205 ) {
if( V_195 ) {
fprintf ( V_195 , L_75 , V_200 ) ;
F_83 ( V_9 , ( int ) ( ( char * ) V_205 - ( char * ) V_161 [ V_9 ] ) , V_195 ) ;
}
V_122 ++ ;
}
break;
case V_210 :
case V_174 :
V_204 = V_145 ;
break;
}
switch( V_198 [ V_10 ] . type ) {
case V_173 :
case V_201 :
break;
case V_206 :
* ( double * ) ( V_198 [ V_10 ] . V_38 ) = V_203 ;
break;
case V_207 :
V_198 [ V_10 ] . F_87 ( & V_203 ) ;
break;
case V_208 :
* ( int * ) ( V_198 [ V_10 ] . V_38 ) = V_202 ;
break;
case V_209 :
V_198 [ V_10 ] . F_87 ( & V_202 ) ;
break;
case V_210 :
* ( char * * ) ( V_198 [ V_10 ] . V_38 ) = V_204 ;
break;
case V_174 :
V_198 [ V_10 ] . F_87 ( V_204 ) ;
break;
}
}
return V_122 ;
}
int F_62 ( char * * V_98 , struct V_171 * V_211 , T_5 * V_195 )
{
int V_122 = 0 ;
V_161 = V_98 ;
V_198 = V_211 ;
V_212 = V_195 ;
if( V_161 && * V_161 && V_198 ) {
int V_9 ;
for( V_9 = 1 ; V_161 [ V_9 ] ; V_9 ++ ) {
if( V_161 [ V_9 ] [ 0 ] == '+' || V_161 [ V_9 ] [ 0 ] == '-' ) {
V_122 += F_86 ( V_9 , V_195 ) ;
} else if( strchr ( V_161 [ V_9 ] , '=' ) ) {
V_122 += F_88 ( V_9 , V_195 ) ;
}
}
}
if( V_122 > 0 ) {
fprintf ( V_195 , L_76 , * V_98 ) ;
F_89 () ;
exit ( 1 ) ;
}
return 0 ;
}
int F_63 ( void ) {
int V_213 = 0 ;
int V_197 = 0 ;
int V_9 ;
if( V_161 != 0 && V_161 [ 0 ] != 0 ) {
for( V_9 = 1 ; V_161 [ V_9 ] ; V_9 ++ ) {
if( V_197 || ! F_85 ( V_161 [ V_9 ] ) ) V_213 ++ ;
if( strcmp ( V_161 [ V_9 ] , L_70 ) == 0 ) V_197 = 1 ;
}
}
return V_213 ;
}
char * F_67 ( int V_53 )
{
int V_9 ;
V_9 = F_84 ( V_53 ) ;
return V_9 >= 0 ? V_161 [ V_9 ] : 0 ;
}
void F_90 ( int V_53 )
{
int V_9 ;
V_9 = F_84 ( V_53 ) ;
if( V_9 >= 0 ) F_83 ( V_9 , 0 , V_212 ) ;
}
void F_89 ( void ) {
int V_9 ;
int V_214 , V_215 ;
V_214 = 0 ;
for( V_9 = 0 ; V_198 [ V_9 ] . V_199 ; V_9 ++ ) {
V_215 = F_57 ( V_198 [ V_9 ] . V_199 ) + 1 ;
switch( V_198 [ V_9 ] . type ) {
case V_173 :
case V_201 :
break;
case V_208 :
case V_209 :
V_215 += 9 ;
break;
case V_206 :
case V_207 :
V_215 += 6 ;
break;
case V_210 :
case V_174 :
V_215 += 8 ;
break;
}
if( V_215 > V_214 ) V_214 = V_215 ;
}
for( V_9 = 0 ; V_198 [ V_9 ] . V_199 ; V_9 ++ ) {
switch( V_198 [ V_9 ] . type ) {
case V_173 :
case V_201 :
fprintf ( V_212 , L_77 , V_214 , V_198 [ V_9 ] . V_199 , V_198 [ V_9 ] . V_216 ) ;
break;
case V_208 :
case V_209 :
fprintf ( V_212 , L_78 , V_198 [ V_9 ] . V_199 ,
( int ) ( V_214 - F_57 ( V_198 [ V_9 ] . V_199 ) - 9 ) , L_68 , V_198 [ V_9 ] . V_216 ) ;
break;
case V_206 :
case V_207 :
fprintf ( V_212 , L_79 , V_198 [ V_9 ] . V_199 ,
( int ) ( V_214 - F_57 ( V_198 [ V_9 ] . V_199 ) - 6 ) , L_68 , V_198 [ V_9 ] . V_216 ) ;
break;
case V_210 :
case V_174 :
fprintf ( V_212 , L_80 , V_198 [ V_9 ] . V_199 ,
( int ) ( V_214 - F_57 ( V_198 [ V_9 ] . V_199 ) - 8 ) , L_68 , V_198 [ V_9 ] . V_216 ) ;
break;
}
}
}
static void F_91 ( struct V_217 * V_218 )
{
const char * V_33 ;
V_33 = F_92 ( V_218 -> V_219 ) ;
#if 0
printf("%s:%d: Token=[%s] state=%d\n",psp->filename,psp->tokenlineno,
x,psp->state);
#endif
switch( V_218 -> V_42 ) {
case V_220 :
V_218 -> V_221 = 0 ;
V_218 -> V_222 = 0 ;
V_218 -> V_223 = V_218 -> V_224 = 0 ;
V_218 -> V_225 -> V_182 = 0 ;
case V_226 :
if( V_33 [ 0 ] == '%' ) {
V_218 -> V_42 = V_227 ;
} else if( ISLOWER ( V_33 [ 0 ] ) ) {
V_218 -> V_75 = F_68 ( V_33 ) ;
V_218 -> V_61 = 0 ;
V_218 -> V_228 = 0 ;
V_218 -> V_42 = V_229 ;
} else if( V_33 [ 0 ] == '{' ) {
if( V_218 -> V_221 == 0 ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_81 ) ;
V_218 -> V_85 ++ ;
} else if( V_218 -> V_221 -> V_184 != 0 ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_82 ) ;
V_218 -> V_85 ++ ;
} else{
V_218 -> V_221 -> line = V_218 -> V_230 ;
V_218 -> V_221 -> V_184 = & V_33 [ 1 ] ;
V_218 -> V_221 -> V_231 = 0 ;
}
} else if( V_33 [ 0 ] == '[' ) {
V_218 -> V_42 = V_232 ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_83 ,
V_33 ) ;
V_218 -> V_85 ++ ;
}
break;
case V_232 :
if( ! ISUPPER ( V_33 [ 0 ] ) ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_84 ) ;
V_218 -> V_85 ++ ;
} else if( V_218 -> V_221 == 0 ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_85 , V_33 ) ;
V_218 -> V_85 ++ ;
} else if( V_218 -> V_221 -> V_60 != 0 ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_86 ) ;
V_218 -> V_85 ++ ;
} else{
V_218 -> V_221 -> V_60 = F_68 ( V_33 ) ;
}
V_218 -> V_42 = V_233 ;
break;
case V_233 :
if( V_33 [ 0 ] != ']' ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_87 ) ;
V_218 -> V_85 ++ ;
}
V_218 -> V_42 = V_226 ;
break;
case V_229 :
if( V_33 [ 0 ] == ':' && V_33 [ 1 ] == ':' && V_33 [ 2 ] == '=' ) {
V_218 -> V_42 = V_234 ;
} else if( V_33 [ 0 ] == '(' ) {
V_218 -> V_42 = V_235 ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_88 ,
V_218 -> V_75 -> V_84 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_236 ;
}
break;
case V_235 :
if( ISALPHA ( V_33 [ 0 ] ) ) {
V_218 -> V_228 = V_33 ;
V_218 -> V_42 = V_237 ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_89 ,
V_33 , V_218 -> V_75 -> V_84 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_236 ;
}
break;
case V_237 :
if( V_33 [ 0 ] == ')' ) {
V_218 -> V_42 = V_238 ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_90 , V_218 -> V_228 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_236 ;
}
break;
case V_238 :
if( V_33 [ 0 ] == ':' && V_33 [ 1 ] == ':' && V_33 [ 2 ] == '=' ) {
V_218 -> V_42 = V_234 ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_91 ,
V_218 -> V_75 -> V_84 , V_218 -> V_228 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_236 ;
}
break;
case V_234 :
if( V_33 [ 0 ] == '.' ) {
struct V_43 * V_34 ;
V_34 = (struct V_43 * ) calloc ( sizeof( struct V_43 ) +
sizeof( struct V_37 * ) * V_218 -> V_61 + sizeof( char * ) * V_218 -> V_61 , 1 ) ;
if( V_34 == 0 ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_92 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_221 = 0 ;
} else{
int V_9 ;
V_34 -> V_117 = V_218 -> V_230 ;
V_34 -> V_62 = (struct V_37 * * ) & V_34 [ 1 ] ;
V_34 -> V_239 = ( const char * * ) & ( V_34 -> V_62 [ V_218 -> V_61 ] ) ;
for( V_9 = 0 ; V_9 < V_218 -> V_61 ; V_9 ++ ) {
V_34 -> V_62 [ V_9 ] = V_218 -> V_62 [ V_9 ] ;
V_34 -> V_239 [ V_9 ] = V_218 -> V_240 [ V_9 ] ;
}
V_34 -> V_75 = V_218 -> V_75 ;
V_34 -> V_228 = V_218 -> V_228 ;
V_34 -> V_61 = V_218 -> V_61 ;
V_34 -> V_184 = 0 ;
V_34 -> V_231 = 1 ;
V_34 -> V_60 = 0 ;
V_34 -> V_30 = V_218 -> V_225 -> V_182 ++ ;
V_34 -> V_86 = V_34 -> V_75 -> V_43 ;
V_34 -> V_75 -> V_43 = V_34 ;
V_34 -> V_26 = 0 ;
if( V_218 -> V_223 == 0 ) {
V_218 -> V_223 = V_218 -> V_224 = V_34 ;
} else{
V_218 -> V_224 -> V_26 = V_34 ;
V_218 -> V_224 = V_34 ;
}
V_218 -> V_221 = V_34 ;
}
V_218 -> V_42 = V_226 ;
} else if( ISALPHA ( V_33 [ 0 ] ) ) {
if( V_218 -> V_61 >= V_241 ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_93 ,
V_33 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_236 ;
} else{
V_218 -> V_62 [ V_218 -> V_61 ] = F_68 ( V_33 ) ;
V_218 -> V_240 [ V_218 -> V_61 ] = 0 ;
V_218 -> V_61 ++ ;
}
} else if( ( V_33 [ 0 ] == '|' || V_33 [ 0 ] == '/' ) && V_218 -> V_61 > 0 ) {
struct V_37 * V_242 = V_218 -> V_62 [ V_218 -> V_61 - 1 ] ;
if( V_242 -> type != V_63 ) {
struct V_37 * V_243 = V_242 ;
V_242 = (struct V_37 * ) calloc ( 1 , sizeof( * V_242 ) ) ;
memset ( V_242 , 0 , sizeof( * V_242 ) ) ;
V_242 -> type = V_63 ;
V_242 -> V_64 = 1 ;
V_242 -> V_65 = (struct V_37 * * ) calloc ( 1 , sizeof( struct V_37 * ) ) ;
V_242 -> V_65 [ 0 ] = V_243 ;
V_242 -> V_84 = V_243 -> V_84 ;
V_218 -> V_62 [ V_218 -> V_61 - 1 ] = V_242 ;
}
V_242 -> V_64 ++ ;
V_242 -> V_65 = (struct V_37 * * ) realloc ( V_242 -> V_65 ,
sizeof( struct V_37 * ) * V_242 -> V_64 ) ;
F_13 ( V_242 -> V_65 ) ;
V_242 -> V_65 [ V_242 -> V_64 - 1 ] = F_68 ( & V_33 [ 1 ] ) ;
if( ISLOWER ( V_33 [ 1 ] ) || ISLOWER ( V_242 -> V_65 [ 0 ] -> V_84 [ 0 ] ) ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_94 ) ;
V_218 -> V_85 ++ ;
}
} else if( V_33 [ 0 ] == '(' && V_218 -> V_61 > 0 ) {
V_218 -> V_42 = V_244 ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_95 , V_33 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_236 ;
}
break;
case V_244 :
if( ISALPHA ( V_33 [ 0 ] ) ) {
V_218 -> V_240 [ V_218 -> V_61 - 1 ] = V_33 ;
V_218 -> V_42 = V_245 ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_96 ,
V_33 , V_218 -> V_62 [ V_218 -> V_61 - 1 ] -> V_84 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_236 ;
}
break;
case V_245 :
if( V_33 [ 0 ] == ')' ) {
V_218 -> V_42 = V_234 ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_90 , V_218 -> V_228 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_236 ;
}
break;
case V_227 :
if( ISALPHA ( V_33 [ 0 ] ) ) {
V_218 -> V_246 = V_33 ;
V_218 -> V_247 = 0 ;
V_218 -> V_248 = 0 ;
V_218 -> V_249 = 1 ;
V_218 -> V_42 = V_250 ;
if( strcmp ( V_33 , L_97 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> V_84 ) ;
V_218 -> V_249 = 0 ;
} else if( strcmp ( V_33 , L_98 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> include ) ;
} else if( strcmp ( V_33 , L_99 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> V_251 ) ;
} else if( strcmp ( V_33 , L_100 ) == 0 ) {
V_218 -> V_247 = & V_218 -> V_225 -> V_252 ;
} else if( strcmp ( V_33 , L_101 ) == 0 ) {
V_218 -> V_247 = & V_218 -> V_225 -> V_253 ;
} else if( strcmp ( V_33 , L_102 ) == 0 ) {
V_218 -> V_247 = & V_218 -> V_225 -> V_254 ;
V_218 -> V_249 = 0 ;
} else if( strcmp ( V_33 , L_103 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> error ) ;
} else if( strcmp ( V_33 , L_104 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> V_255 ) ;
} else if( strcmp ( V_33 , L_105 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> V_256 ) ;
} else if( strcmp ( V_33 , L_106 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> V_257 ) ;
} else if( strcmp ( V_33 , L_107 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> V_38 ) ;
V_218 -> V_249 = 0 ;
} else if( strcmp ( V_33 , L_108 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> V_258 ) ;
V_218 -> V_249 = 0 ;
} else if( strcmp ( V_33 , L_109 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> V_259 ) ;
V_218 -> V_249 = 0 ;
} else if( strcmp ( V_33 , L_110 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> V_260 ) ;
V_218 -> V_249 = 0 ;
} else if( strcmp ( V_33 , L_111 ) == 0 ) {
V_218 -> V_247 = & ( V_218 -> V_225 -> V_81 ) ;
V_218 -> V_249 = 0 ;
} else if( strcmp ( V_33 , L_112 ) == 0 ) {
V_218 -> V_222 ++ ;
V_218 -> V_261 = V_129 ;
V_218 -> V_42 = V_262 ;
} else if( strcmp ( V_33 , L_113 ) == 0 ) {
V_218 -> V_222 ++ ;
V_218 -> V_261 = V_128 ;
V_218 -> V_42 = V_262 ;
} else if( strcmp ( V_33 , L_114 ) == 0 ) {
V_218 -> V_222 ++ ;
V_218 -> V_261 = V_130 ;
V_218 -> V_42 = V_262 ;
} else if( strcmp ( V_33 , L_115 ) == 0 ) {
V_218 -> V_42 = V_263 ;
} else if( strcmp ( V_33 , L_116 ) == 0 ) {
V_218 -> V_42 = V_264 ;
} else if( strcmp ( V_33 , L_117 ) == 0 ) {
V_218 -> V_265 = 0 ;
V_218 -> V_42 = V_266 ;
} else if( strcmp ( V_33 , L_118 ) == 0 ) {
V_218 -> V_42 = V_267 ;
} else if( strcmp ( V_33 , L_119 ) == 0 ) {
V_218 -> V_42 = V_268 ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_120 , V_33 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_269 ;
}
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_121 , V_33 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_269 ;
}
break;
case V_263 :
if( ! ISALPHA ( V_33 [ 0 ] ) ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_122 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_269 ;
} else{
struct V_37 * V_29 = F_68 ( V_33 ) ;
V_218 -> V_247 = & V_29 -> V_270 ;
V_218 -> V_248 = & V_29 -> V_271 ;
V_218 -> V_249 = 1 ;
V_218 -> V_42 = V_250 ;
}
break;
case V_264 :
if( ! ISALPHA ( V_33 [ 0 ] ) ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_123 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_269 ;
} else{
struct V_37 * V_29 = F_22 ( V_33 ) ;
if( ( V_29 ) && ( V_29 -> V_272 ) ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_124 , V_33 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_269 ;
} else{
if ( ! V_29 ) {
V_29 = F_68 ( V_33 ) ;
}
V_218 -> V_247 = & V_29 -> V_272 ;
V_218 -> V_249 = 0 ;
V_218 -> V_42 = V_250 ;
}
}
break;
case V_262 :
if( V_33 [ 0 ] == '.' ) {
V_218 -> V_42 = V_226 ;
} else if( ISUPPER ( V_33 [ 0 ] ) ) {
struct V_37 * V_29 ;
V_29 = F_68 ( V_33 ) ;
if( V_29 -> V_66 >= 0 ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_125 , V_33 ) ;
V_218 -> V_85 ++ ;
} else{
V_29 -> V_66 = V_218 -> V_222 ;
V_29 -> V_127 = V_218 -> V_261 ;
}
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_126 , V_33 ) ;
V_218 -> V_85 ++ ;
}
break;
case V_250 :
if( V_33 [ 0 ] == '{' || V_33 [ 0 ] == '\"' || ISALNUM ( V_33 [ 0 ] ) ) {
const char * V_273 , * V_274 ;
char * V_1 , * V_14 ;
int V_275 , V_53 , V_276 = 0 , V_277 , V_278 ;
int V_279 ;
char V_280 [ 50 ] ;
V_274 = V_33 ;
if( V_274 [ 0 ] == '"' || V_274 [ 0 ] == '{' ) V_274 ++ ;
V_277 = F_57 ( V_274 ) ;
if( * V_218 -> V_247 ) {
V_273 = * V_218 -> V_247 ;
} else{
V_273 = L_68 ;
}
V_275 = F_57 ( V_273 ) ;
V_53 = V_275 + V_277 + 20 ;
V_279 = ! V_218 -> V_225 -> V_169 && V_218 -> V_249 &&
( V_218 -> V_248 == 0 || V_218 -> V_248 [ 0 ] != 0 ) ;
if( V_279 ) {
for( V_14 = V_218 -> V_82 , V_278 = 0 ; * V_14 ; V_14 ++ ) {
if( * V_14 == '\\' ) V_278 ++ ;
}
F_3 ( V_280 , L_127 , V_218 -> V_230 ) ;
V_276 = F_57 ( V_280 ) ;
V_53 += V_276 + F_57 ( V_218 -> V_82 ) + V_278 ;
}
* V_218 -> V_247 = ( char * ) realloc ( * V_218 -> V_247 , V_53 ) ;
F_13 ( * V_218 -> V_247 ) ;
V_1 = * V_218 -> V_247 + V_275 ;
if( V_279 ) {
if( V_275 && V_1 [ - 1 ] != '\n' ) {
* ( V_1 ++ ) = '\n' ;
}
memcpy ( V_1 , V_280 , V_276 ) ;
V_1 += V_276 ;
* ( V_1 ++ ) = '"' ;
for( V_14 = V_218 -> V_82 ; * V_14 ; V_14 ++ ) {
if( * V_14 == '\\' ) {
* ( V_1 ++ ) = '\\' ;
}
* ( V_1 ++ ) = * V_14 ;
}
* ( V_1 ++ ) = '"' ;
* ( V_1 ++ ) = '\n' ;
}
if( V_218 -> V_248 && V_218 -> V_248 [ 0 ] == 0 ) {
V_218 -> V_248 [ 0 ] = V_218 -> V_230 ;
}
memcpy ( V_1 , V_274 , V_277 ) ;
V_1 += V_277 ;
* V_1 = 0 ;
V_218 -> V_42 = V_226 ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_128 , V_218 -> V_246 , V_33 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_269 ;
}
break;
case V_266 :
if( V_33 [ 0 ] == '.' ) {
V_218 -> V_42 = V_226 ;
} else if( ! ISUPPER ( V_33 [ 0 ] ) ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_129 , V_33 ) ;
V_218 -> V_85 ++ ;
} else{
struct V_37 * V_29 = F_68 ( V_33 ) ;
if( V_218 -> V_265 == 0 ) {
V_218 -> V_265 = V_29 ;
} else if( V_29 -> V_265 ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_130 , V_33 ) ;
V_218 -> V_85 ++ ;
} else{
V_29 -> V_265 = V_218 -> V_265 ;
V_218 -> V_225 -> V_281 = 1 ;
}
}
break;
case V_267 :
if( V_33 [ 0 ] == '.' ) {
V_218 -> V_42 = V_226 ;
} else if( ! ISUPPER ( V_33 [ 0 ] ) ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_131 , V_33 ) ;
V_218 -> V_85 ++ ;
} else{
struct V_37 * V_29 = F_68 ( V_33 ) ;
if( V_218 -> V_225 -> V_282 == 0 ) {
V_218 -> V_225 -> V_282 = V_29 ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_132 , V_33 ) ;
V_218 -> V_85 ++ ;
}
}
break;
case V_268 :
if( ! ISLOWER ( V_33 [ 0 ] ) ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_133 , V_33 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_269 ;
} else if( F_22 ( V_33 ) ) {
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_134 , V_33 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_269 ;
} else{
V_218 -> V_283 = F_68 ( V_33 ) ;
V_218 -> V_283 -> type = V_63 ;
V_218 -> V_42 = V_284 ;
}
break;
case V_284 :
if( V_33 [ 0 ] == '.' ) {
V_218 -> V_42 = V_226 ;
} else if( ISUPPER ( V_33 [ 0 ] ) || ( ( V_33 [ 0 ] == '|' || V_33 [ 0 ] == '/' ) && ISUPPER ( V_33 [ 1 ] ) ) ) {
struct V_37 * V_242 = V_218 -> V_283 ;
V_242 -> V_64 ++ ;
V_242 -> V_65 = (struct V_37 * * ) realloc ( V_242 -> V_65 ,
sizeof( struct V_37 * ) * V_242 -> V_64 ) ;
F_13 ( V_242 -> V_65 ) ;
if( ! ISUPPER ( V_33 [ 0 ] ) ) V_33 ++ ;
V_242 -> V_65 [ V_242 -> V_64 - 1 ] = F_68 ( V_33 ) ;
} else{
F_23 ( V_218 -> V_82 , V_218 -> V_230 ,
L_135 , V_33 ) ;
V_218 -> V_85 ++ ;
V_218 -> V_42 = V_269 ;
}
break;
case V_236 :
case V_269 :
if( V_33 [ 0 ] == '.' ) V_218 -> V_42 = V_226 ;
if( V_33 [ 0 ] == '%' ) V_218 -> V_42 = V_227 ;
break;
}
}
static void F_93 ( char * V_14 ) {
int V_9 , V_10 , V_11 , V_53 ;
int V_285 = 0 ;
int V_81 = 0 ;
int V_143 = 1 ;
int V_286 = 1 ;
for( V_9 = 0 ; V_14 [ V_9 ] ; V_9 ++ ) {
if( V_14 [ V_9 ] == '\n' ) V_143 ++ ;
if( V_14 [ V_9 ] != '%' || ( V_9 > 0 && V_14 [ V_9 - 1 ] != '\n' ) ) continue;
if( strncmp ( & V_14 [ V_9 ] , L_136 , 6 ) == 0 && ISSPACE ( V_14 [ V_9 + 6 ] ) ) {
if( V_285 ) {
V_285 -- ;
if( V_285 == 0 ) {
for( V_10 = V_81 ; V_10 < V_9 ; V_10 ++ ) if( V_14 [ V_10 ] != '\n' ) V_14 [ V_10 ] = ' ' ;
}
}
for( V_10 = V_9 ; V_14 [ V_10 ] && V_14 [ V_10 ] != '\n' ; V_10 ++ ) V_14 [ V_10 ] = ' ' ;
} else if( ( strncmp ( & V_14 [ V_9 ] , L_137 , 6 ) == 0 && ISSPACE ( V_14 [ V_9 + 6 ] ) )
|| ( strncmp ( & V_14 [ V_9 ] , L_138 , 7 ) == 0 && ISSPACE ( V_14 [ V_9 + 7 ] ) ) ) {
if( V_285 ) {
V_285 ++ ;
} else{
for( V_10 = V_9 + 7 ; ISSPACE ( V_14 [ V_10 ] ) ; V_10 ++ ) {}
for( V_53 = 0 ; V_14 [ V_10 + V_53 ] && ! ISSPACE ( V_14 [ V_10 + V_53 ] ) ; V_53 ++ ) {}
V_285 = 1 ;
for( V_11 = 0 ; V_11 < V_148 ; V_11 ++ ) {
if( strncmp ( V_149 [ V_11 ] , & V_14 [ V_10 ] , V_53 ) == 0 && F_57 ( V_149 [ V_11 ] ) == V_53 ) {
V_285 = 0 ;
break;
}
}
if( V_14 [ V_9 + 3 ] == 'n' ) V_285 = ! V_285 ;
if( V_285 ) {
V_81 = V_9 ;
V_286 = V_143 ;
}
}
for( V_10 = V_9 ; V_14 [ V_10 ] && V_14 [ V_10 ] != '\n' ; V_10 ++ ) V_14 [ V_10 ] = ' ' ;
}
}
if( V_285 ) {
fprintf ( V_17 , L_139 , V_286 ) ;
exit ( 1 ) ;
}
}
void F_69 ( struct V_58 * V_225 )
{
struct V_217 V_287 ;
T_5 * V_288 ;
char * V_289 ;
unsigned long int V_290 ;
int V_143 ;
int V_12 ;
char * V_145 , * V_291 ;
int V_292 = 0 ;
memset ( & V_287 , '\0' , sizeof( V_287 ) ) ;
V_287 . V_225 = V_225 ;
V_287 . V_82 = V_225 -> V_82 ;
V_287 . V_85 = 0 ;
V_287 . V_42 = V_220 ;
V_288 = fopen ( V_287 . V_82 , L_140 ) ;
if( V_288 == 0 ) {
F_23 ( V_287 . V_82 , 0 , L_141 ) ;
V_225 -> V_85 ++ ;
return;
}
fseek ( V_288 , 0 , V_293 ) ;
V_290 = ftell ( V_288 ) ;
rewind ( V_288 ) ;
V_289 = ( char * ) malloc ( V_290 + 1 ) ;
if( V_290 > 100000000 || V_289 == 0 ) {
F_23 ( V_287 . V_82 , 0 , L_142 ) ;
V_225 -> V_85 ++ ;
free ( V_289 ) ;
fclose ( V_288 ) ;
return;
}
if( fread ( V_289 , 1 , V_290 , V_288 ) != V_290 ) {
F_23 ( V_287 . V_82 , 0 , L_143 ,
V_290 ) ;
free ( V_289 ) ;
V_225 -> V_85 ++ ;
fclose ( V_288 ) ;
return;
}
fclose ( V_288 ) ;
V_289 [ V_290 ] = 0 ;
F_93 ( V_289 ) ;
V_143 = 1 ;
for( V_145 = V_289 ; ( V_12 = * V_145 ) != 0 ; ) {
if( V_12 == '\n' ) V_143 ++ ;
if( ISSPACE ( V_12 ) ) { V_145 ++ ; continue; }
if( V_12 == '/' && V_145 [ 1 ] == '/' ) {
V_145 += 2 ;
while( ( V_12 = * V_145 ) != 0 && V_12 != '\n' ) V_145 ++ ;
continue;
}
if( V_12 == '/' && V_145 [ 1 ] == '*' ) {
V_145 += 2 ;
while( ( V_12 = * V_145 ) != 0 && ( V_12 != '/' || V_145 [ - 1 ] != '*' ) ) {
if( V_12 == '\n' ) V_143 ++ ;
V_145 ++ ;
}
if( V_12 ) V_145 ++ ;
continue;
}
V_287 . V_219 = V_145 ;
V_287 . V_230 = V_143 ;
if( V_12 == '\"' ) {
V_145 ++ ;
while( ( V_12 = * V_145 ) != 0 && V_12 != '\"' ) {
if( V_12 == '\n' ) V_143 ++ ;
V_145 ++ ;
}
if( V_12 == 0 ) {
F_23 ( V_287 . V_82 , V_292 ,
L_144 ) ;
V_287 . V_85 ++ ;
V_291 = V_145 ;
} else{
V_291 = V_145 + 1 ;
}
} else if( V_12 == '{' ) {
int V_294 ;
V_145 ++ ;
for( V_294 = 1 ; ( V_12 = * V_145 ) != 0 && ( V_294 > 1 || V_12 != '}' ) ; V_145 ++ ) {
if( V_12 == '\n' ) V_143 ++ ;
else if( V_12 == '{' ) V_294 ++ ;
else if( V_12 == '}' ) V_294 -- ;
else if( V_12 == '/' && V_145 [ 1 ] == '*' ) {
int V_295 ;
V_145 = & V_145 [ 2 ] ;
V_295 = 0 ;
while( ( V_12 = * V_145 ) != 0 && ( V_12 != '/' || V_295 != '*' ) ) {
if( V_12 == '\n' ) V_143 ++ ;
V_295 = V_12 ;
V_145 ++ ;
}
} else if( V_12 == '/' && V_145 [ 1 ] == '/' ) {
V_145 = & V_145 [ 2 ] ;
while( ( V_12 = * V_145 ) != 0 && V_12 != '\n' ) V_145 ++ ;
if( V_12 ) V_143 ++ ;
} else if( V_12 == '\'' || V_12 == '\"' ) {
int V_296 , V_295 ;
V_296 = V_12 ;
V_295 = 0 ;
for( V_145 ++ ; ( V_12 = * V_145 ) != 0 && ( V_12 != V_296 || V_295 == '\\' ) ; V_145 ++ ) {
if( V_12 == '\n' ) V_143 ++ ;
if( V_295 == '\\' ) V_295 = 0 ;
else V_295 = V_12 ;
}
}
}
if( V_12 == 0 ) {
F_23 ( V_287 . V_82 , V_287 . V_230 ,
L_145 ) ;
V_287 . V_85 ++ ;
V_291 = V_145 ;
} else{
V_291 = V_145 + 1 ;
}
} else if( ISALNUM ( V_12 ) ) {
while( ( V_12 = * V_145 ) != 0 && ( ISALNUM ( V_12 ) || V_12 == '_' ) ) V_145 ++ ;
V_291 = V_145 ;
} else if( V_12 == ':' && V_145 [ 1 ] == ':' && V_145 [ 2 ] == '=' ) {
V_145 += 3 ;
V_291 = V_145 ;
} else if( ( V_12 == '/' || V_12 == '|' ) && ISALPHA ( V_145 [ 1 ] ) ) {
V_145 += 2 ;
while( ( V_12 = * V_145 ) != 0 && ( ISALNUM ( V_12 ) || V_12 == '_' ) ) V_145 ++ ;
V_291 = V_145 ;
} else{
V_145 ++ ;
V_291 = V_145 ;
}
V_12 = * V_145 ;
* V_145 = 0 ;
F_91 ( & V_287 ) ;
* V_145 = ( char ) V_12 ;
V_145 = V_291 ;
}
free ( V_289 ) ;
V_225 -> V_43 = V_287 . V_223 ;
V_225 -> V_85 = V_287 . V_85 ;
}
struct V_109 * F_94 ( void ) {
struct V_109 * V_297 ;
if( V_298 == 0 ) {
int V_9 ;
int V_25 = 100 ;
V_298 = (struct V_109 * ) calloc ( V_25 , sizeof( struct V_109 ) ) ;
if( V_298 == 0 ) {
fprintf ( V_17 ,
L_146 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_25 - 1 ; V_9 ++ ) V_298 [ V_9 ] . V_26 = & V_298 [ V_9 + 1 ] ;
V_298 [ V_25 - 1 ] . V_26 = 0 ;
}
V_297 = V_298 ;
V_298 = V_298 -> V_26 ;
return V_297 ;
}
void F_40 ( struct V_109 * * V_299 , struct V_87 * V_91 )
{
struct V_109 * V_297 ;
V_297 = F_94 () ;
V_297 -> V_26 = * V_299 ;
* V_299 = V_297 ;
V_297 -> V_91 = V_91 ;
}
void F_29 ( struct V_109 * * V_300 , struct V_109 * V_301 )
{
struct V_109 * V_302 ;
while( V_301 ) {
V_302 = V_301 -> V_26 ;
V_301 -> V_26 = * V_300 ;
* V_300 = V_301 ;
V_301 = V_302 ;
}
}
void F_30 ( struct V_109 * V_110 )
{
struct V_109 * V_302 ;
while( V_110 ) {
V_302 = V_110 -> V_26 ;
V_110 -> V_26 = V_298 ;
V_298 = V_110 ;
V_110 = V_302 ;
}
}
T_2 char * F_95 ( struct V_58 * V_67 , const char * V_303 )
{
char * V_84 ;
char * V_145 ;
V_84 = ( char * ) malloc ( F_57 ( V_67 -> V_82 ) + F_57 ( V_303 ) + 5 ) ;
if( V_84 == 0 ) {
fprintf ( V_17 , L_147 ) ;
exit ( 1 ) ;
}
F_4 ( V_84 , V_67 -> V_82 ) ;
V_145 = strrchr ( V_84 , '.' ) ;
if( V_145 ) * V_145 = 0 ;
F_5 ( V_84 , V_303 ) ;
return V_84 ;
}
T_2 char * F_96 ( struct V_58 * V_67 , const char * V_303 )
{
V_67 -> V_82 = V_67 -> V_181 ;
return F_95 ( V_67 , V_303 ) ;
}
T_2 T_5 * F_97 (
struct V_58 * V_67 ,
const char * V_303 ,
const char * V_304
) {
T_5 * V_288 ;
if( V_67 -> V_305 ) free ( V_67 -> V_305 ) ;
V_67 -> V_305 = F_96 ( V_67 , V_303 ) ;
V_288 = fopen ( V_67 -> V_305 , V_304 ) ;
if( V_288 == 0 && * V_304 == 'w' ) {
fprintf ( V_17 , L_148 , V_67 -> V_305 ) ;
V_67 -> V_85 ++ ;
return 0 ;
}
return V_288 ;
}
void F_72 ( struct V_58 * V_67 )
{
struct V_43 * V_34 ;
struct V_37 * V_29 ;
int V_9 , V_10 , V_306 , V_215 , V_307 , V_308 ;
printf ( L_149 , V_67 -> V_82 ) ;
V_306 = 10 ;
for( V_9 = 0 ; V_9 < V_67 -> V_69 ; V_9 ++ ) {
V_29 = V_67 -> V_70 [ V_9 ] ;
V_215 = F_57 ( V_29 -> V_84 ) ;
if( V_215 > V_306 ) V_306 = V_215 ;
}
V_307 = 76 / ( V_306 + 5 ) ;
if( V_307 < 1 ) V_307 = 1 ;
V_308 = ( V_67 -> V_69 + V_307 - 1 ) / V_307 ;
for( V_9 = 0 ; V_9 < V_308 ; V_9 ++ ) {
printf ( L_150 ) ;
for( V_10 = V_9 ; V_10 < V_67 -> V_69 ; V_10 += V_308 ) {
V_29 = V_67 -> V_70 [ V_10 ] ;
assert ( V_29 -> V_30 == V_10 ) ;
printf ( L_151 , V_10 , V_306 , V_306 , V_29 -> V_84 ) ;
}
printf ( L_14 ) ;
}
for( V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
printf ( L_65 , V_34 -> V_75 -> V_84 ) ;
printf ( L_152 ) ;
for( V_9 = 0 ; V_9 < V_34 -> V_61 ; V_9 ++ ) {
V_29 = V_34 -> V_62 [ V_9 ] ;
if( V_29 -> type == V_63 ) {
printf ( L_66 , V_29 -> V_65 [ 0 ] -> V_84 ) ;
for( V_10 = 1 ; V_10 < V_29 -> V_64 ; V_10 ++ ) {
printf ( L_153 , V_29 -> V_65 [ V_10 ] -> V_84 ) ;
}
} else{
printf ( L_66 , V_29 -> V_84 ) ;
}
}
printf ( L_154 ) ;
if( V_34 -> V_60 ) printf ( L_155 , V_34 -> V_60 -> V_84 ) ;
printf ( L_14 ) ;
}
}
T_2 void F_98 ( T_5 * V_288 , struct V_43 * V_34 , int V_309 ) {
struct V_37 * V_29 ;
int V_9 , V_10 ;
fprintf ( V_288 , L_156 , V_34 -> V_75 -> V_84 ) ;
for( V_9 = 0 ; V_9 <= V_34 -> V_61 ; V_9 ++ ) {
if( V_9 == V_309 ) fprintf ( V_288 , L_157 ) ;
if( V_9 == V_34 -> V_61 ) break;
V_29 = V_34 -> V_62 [ V_9 ] ;
if( V_29 -> type == V_63 ) {
fprintf ( V_288 , L_66 , V_29 -> V_65 [ 0 ] -> V_84 ) ;
for( V_10 = 1 ; V_10 < V_29 -> V_64 ; V_10 ++ ) {
fprintf ( V_288 , L_153 , V_29 -> V_65 [ V_10 ] -> V_84 ) ;
}
} else{
fprintf ( V_288 , L_66 , V_29 -> V_84 ) ;
}
}
}
T_2 void F_99 ( T_5 * V_288 , struct V_87 * V_91 ) {
F_98 ( V_288 , V_91 -> V_34 , V_91 -> V_107 ) ;
}
T_2 int F_100 (
struct V_22 * V_8 ,
T_5 * V_288 ,
int V_310
) {
int V_311 = 1 ;
switch( V_8 -> type ) {
case V_40 : {
struct V_42 * V_41 = V_8 -> V_33 . V_41 ;
fprintf ( V_288 , L_158 , V_310 , V_8 -> V_29 -> V_84 , V_41 -> V_96 ) ;
break;
}
case V_31 : {
struct V_43 * V_34 = V_8 -> V_33 . V_34 ;
fprintf ( V_288 , L_159 , V_310 , V_8 -> V_29 -> V_84 , V_34 -> V_155 ) ;
F_98 ( V_288 , V_34 , - 1 ) ;
break;
}
case V_32 : {
struct V_43 * V_34 = V_8 -> V_33 . V_34 ;
fprintf ( V_288 , L_160 , V_310 , V_8 -> V_29 -> V_84 , V_34 -> V_155 ) ;
F_98 ( V_288 , V_34 , - 1 ) ;
break;
}
case V_113 :
fprintf ( V_288 , L_161 , V_310 , V_8 -> V_29 -> V_84 ) ;
break;
case ERROR :
fprintf ( V_288 , L_162 , V_310 , V_8 -> V_29 -> V_84 ) ;
break;
case V_124 :
case V_131 :
fprintf ( V_288 , L_163 ,
V_310 , V_8 -> V_29 -> V_84 , V_8 -> V_33 . V_34 -> V_155 ) ;
break;
case V_123 :
fprintf ( V_288 , L_164 ,
V_310 , V_8 -> V_29 -> V_84 , V_8 -> V_33 . V_41 -> V_96 ) ;
break;
case V_126 :
if( V_176 ) {
fprintf ( V_288 , L_165 ,
V_310 , V_8 -> V_29 -> V_84 , V_8 -> V_33 . V_41 -> V_96 ) ;
} else{
V_311 = 0 ;
}
break;
case V_125 :
if( V_176 ) {
fprintf ( V_288 , L_166 ,
V_310 , V_8 -> V_29 -> V_84 , V_8 -> V_33 . V_34 -> V_155 ) ;
} else{
V_311 = 0 ;
}
break;
case V_312 :
V_311 = 0 ;
break;
}
if( V_311 && V_8 -> V_39 ) {
fprintf ( V_288 , L_167 , V_8 -> V_29 -> V_84 , V_8 -> V_39 -> V_84 ) ;
}
return V_311 ;
}
void F_77 ( struct V_58 * V_67 )
{
int V_9 ;
struct V_42 * V_41 ;
struct V_87 * V_91 ;
struct V_22 * V_8 ;
T_5 * V_288 ;
V_288 = F_97 ( V_67 , L_168 , L_169 ) ;
if( V_288 == 0 ) return;
for( V_9 = 0 ; V_9 < V_67 -> V_185 ; V_9 ++ ) {
V_41 = V_67 -> V_111 [ V_9 ] ;
if( V_41 ) {
fprintf ( V_288 , L_170 , V_41 -> V_96 ) ;
if( V_67 -> V_164 ) V_91 = V_41 -> V_92 ;
else V_91 = V_41 -> V_91 ;
while( V_91 ) {
char V_313 [ 20 ] ;
if( V_91 -> V_107 == V_91 -> V_34 -> V_61 ) {
F_3 ( V_313 , L_171 , V_91 -> V_34 -> V_155 ) ;
fprintf ( V_288 , L_172 , V_313 ) ;
} else{
fprintf ( V_288 , L_173 ) ;
}
F_99 ( V_288 , V_91 ) ;
fprintf ( V_288 , L_14 ) ;
#if 0
SetPrint(fp,cfp->fws,lemp);
PlinkPrint(fp,cfp->fplp,"To ");
PlinkPrint(fp,cfp->bplp,"From");
#endif
if( V_67 -> V_164 ) V_91 = V_91 -> V_92 ;
else V_91 = V_91 -> V_26 ;
}
fprintf ( V_288 , L_14 ) ;
for( V_8 = V_41 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( F_100 ( V_8 , V_288 , 30 ) ) fprintf ( V_288 , L_14 ) ;
}
}
fprintf ( V_288 , L_14 ) ;
}
fprintf ( V_288 , L_174 ) ;
fprintf ( V_288 , L_175 ) ;
for( V_9 = 0 ; V_9 < V_67 -> V_69 ; V_9 ++ ) {
int V_10 ;
struct V_37 * V_29 ;
V_29 = V_67 -> V_70 [ V_9 ] ;
fprintf ( V_288 , L_176 , V_9 , V_29 -> V_84 ) ;
if( V_29 -> type == V_76 ) {
fprintf ( V_288 , L_177 ) ;
if( V_29 -> V_71 ) {
fprintf ( V_288 , L_178 ) ;
}
for( V_10 = 0 ; V_10 < V_67 -> V_73 ; V_10 ++ ) {
if( V_29 -> V_74 && F_44 ( V_29 -> V_74 , V_10 ) ) {
fprintf ( V_288 , L_66 , V_67 -> V_70 [ V_10 ] -> V_84 ) ;
}
}
}
fprintf ( V_288 , L_14 ) ;
}
fclose ( V_288 ) ;
return;
}
T_2 char * F_101 ( char * V_179 , char * V_84 , int V_314 )
{
const char * V_315 ;
char * V_316 ;
char * V_317 ;
char * V_318 , * V_145 ;
char V_12 ;
#ifdef F_102
V_145 = strrchr ( V_179 , '\\' ) ;
#else
V_145 = strrchr ( V_179 , '/' ) ;
#endif
if( V_145 ) {
V_12 = * V_145 ;
* V_145 = 0 ;
V_318 = ( char * ) malloc ( F_57 ( V_179 ) + F_57 ( V_84 ) + 2 ) ;
if( V_318 ) F_3 ( V_318 , L_179 , V_179 , V_84 ) ;
* V_145 = V_12 ;
} else{
V_315 = getenv ( L_180 ) ;
if( V_315 == 0 ) V_315 = L_181 ;
V_317 = ( char * ) malloc ( F_57 ( V_315 ) + 1 ) ;
if( V_317 == 0 )
return NULL ;
V_316 = V_317 ;
V_318 = ( char * ) malloc ( F_57 ( V_315 ) + F_57 ( V_84 ) + 2 ) ;
if( ( V_318 != 0 ) ) {
F_4 ( V_317 , V_315 ) ;
while( * V_317 ) {
V_145 = strchr ( V_317 , ':' ) ;
if( V_145 == 0 ) V_145 = & V_317 [ F_57 ( V_317 ) ] ;
V_12 = * V_145 ;
* V_145 = 0 ;
F_3 ( V_318 , L_179 , V_317 , V_84 ) ;
* V_145 = V_12 ;
if( V_12 == 0 ) V_317 [ 0 ] = 0 ;
else V_317 = & V_145 [ 1 ] ;
if( F_103 ( V_318 , V_314 ) == 0 ) break;
}
}
free ( V_316 ) ;
}
return V_318 ;
}
T_2 int F_104 ( struct V_58 * V_67 , struct V_22 * V_8 )
{
int V_319 ;
switch( V_8 -> type ) {
case V_40 : V_319 = V_8 -> V_33 . V_41 -> V_96 ; break;
case V_32 : V_319 = V_8 -> V_33 . V_34 -> V_155 + V_67 -> V_97 ; break;
case V_31 : V_319 = V_8 -> V_33 . V_34 -> V_155 + V_67 -> V_97 + V_67 -> V_182 ; break;
case ERROR : V_319 = V_67 -> V_97 + V_67 -> V_182 * 2 ; break;
case V_113 : V_319 = V_67 -> V_97 + V_67 -> V_182 * 2 + 1 ; break;
default: V_319 = - 1 ; break;
}
return V_319 ;
}
T_2 void F_105 ( char * V_84 , T_5 * V_320 , T_5 * V_321 , int * V_143 )
{
int V_9 , V_322 ;
char line [ V_323 ] ;
while( fgets ( line , V_323 , V_320 ) && ( line [ 0 ] != '%' || line [ 1 ] != '%' ) ) {
( * V_143 ) ++ ;
V_322 = 0 ;
if( V_84 ) {
for( V_9 = 0 ; line [ V_9 ] ; V_9 ++ ) {
if( line [ V_9 ] == 'P' && strncmp ( & line [ V_9 ] , L_182 , 5 ) == 0
&& ( V_9 == 0 || ! ISALPHA ( line [ V_9 - 1 ] ) )
) {
if( V_9 > V_322 ) fprintf ( V_321 , L_183 , V_9 - V_322 , & line [ V_322 ] ) ;
fprintf ( V_321 , L_65 , V_84 ) ;
V_9 += 4 ;
V_322 = V_9 + 1 ;
}
}
}
fprintf ( V_321 , L_65 , & line [ V_322 ] ) ;
}
}
T_2 T_5 * F_106 ( struct V_58 * V_67 )
{
static char V_324 [] = L_184 ;
char V_313 [ 1000 ] ;
T_5 * V_320 ;
char * V_325 ;
char * V_326 = NULL ;
char * V_145 ;
if ( V_150 != 0 ) {
if( F_103 ( V_150 , 004 ) == - 1 ) {
fprintf ( V_17 , L_185 ,
V_150 ) ;
V_67 -> V_85 ++ ;
return 0 ;
}
V_320 = fopen ( V_150 , L_140 ) ;
if( V_320 == 0 ) {
fprintf ( V_17 , L_186 ,
V_150 ) ;
V_67 -> V_85 ++ ;
return 0 ;
}
return V_320 ;
}
V_145 = strrchr ( V_67 -> V_82 , '.' ) ;
if( V_145 ) {
F_3 ( V_313 , L_187 , ( int ) ( V_145 - V_67 -> V_82 ) , V_67 -> V_82 ) ;
} else{
F_3 ( V_313 , L_188 , V_67 -> V_82 ) ;
}
if( F_103 ( V_313 , 004 ) == 0 ) {
V_325 = V_313 ;
} else if( F_103 ( V_324 , 004 ) == 0 ) {
V_325 = V_324 ;
} else{
V_326 = F_101 ( V_67 -> V_179 , V_324 , 0 ) ;
V_325 = V_326 ;
}
if( V_325 == 0 ) {
fprintf ( V_17 , L_185 ,
V_324 ) ;
V_67 -> V_85 ++ ;
return 0 ;
}
V_320 = fopen ( V_325 , L_140 ) ;
if( V_320 == 0 ) {
fprintf ( V_17 , L_186 , V_324 ) ;
V_67 -> V_85 ++ ;
}
if ( V_326 ) {
free ( V_326 ) ;
}
return V_320 ;
}
T_2 void F_107 ( T_5 * V_321 , int V_143 , char * V_82 )
{
fprintf ( V_321 , L_189 , V_143 ) ;
while( * V_82 ) {
if( * V_82 == '\\' ) putc ( '\\' , V_321 ) ;
putc ( * V_82 , V_321 ) ;
V_82 ++ ;
}
fprintf ( V_321 , L_190 ) ;
}
T_2 void F_108 ( T_5 * V_321 , struct V_58 * V_67 , char * V_6 , int * V_143 )
{
if( V_6 == 0 ) return;
while( * V_6 ) {
putc ( * V_6 , V_321 ) ;
if( * V_6 == '\n' ) ( * V_143 ) ++ ;
V_6 ++ ;
}
if( V_6 [ - 1 ] != '\n' ) {
putc ( '\n' , V_321 ) ;
( * V_143 ) ++ ;
}
if ( ! V_67 -> V_169 ) {
( * V_143 ) ++ ; F_107 ( V_321 , * V_143 , V_67 -> V_305 ) ;
}
return;
}
T_2 void F_109 (
T_5 * V_321 ,
struct V_37 * V_29 ,
struct V_58 * V_67 ,
int * V_143
) {
char * V_145 = 0 ;
if( V_29 -> type == V_80 ) {
V_145 = V_67 -> V_252 ;
if( V_145 == 0 ) return;
fprintf ( V_321 , L_191 ) ; ( * V_143 ) ++ ;
} else if( V_29 -> V_270 ) {
V_145 = V_29 -> V_270 ;
fprintf ( V_321 , L_191 ) ; ( * V_143 ) ++ ;
if( ! V_67 -> V_169 ) {
( * V_143 ) ++ ;
F_107 ( V_321 , V_29 -> V_271 , V_67 -> V_82 ) ;
}
} else if( V_67 -> V_253 ) {
V_145 = V_67 -> V_253 ;
if( V_145 == 0 ) return;
fprintf ( V_321 , L_191 ) ; ( * V_143 ) ++ ;
} else{
assert ( 0 ) ;
}
for(; * V_145 ; V_145 ++ ) {
if( * V_145 == '$' && V_145 [ 1 ] == '$' ) {
fprintf ( V_321 , L_192 , V_29 -> V_327 ) ;
V_145 ++ ;
continue;
}
if( * V_145 == '\n' ) ( * V_143 ) ++ ;
fputc ( * V_145 , V_321 ) ;
}
fprintf ( V_321 , L_14 ) ; ( * V_143 ) ++ ;
if ( ! V_67 -> V_169 ) {
( * V_143 ) ++ ; F_107 ( V_321 , * V_143 , V_67 -> V_305 ) ;
}
fprintf ( V_321 , L_193 ) ; ( * V_143 ) ++ ;
return;
}
T_2 int F_110 ( struct V_37 * V_29 , struct V_58 * V_67 )
{
int V_328 ;
if( V_29 -> type == V_80 ) {
V_328 = V_67 -> V_252 != 0 ;
} else{
V_328 = V_67 -> V_253 != 0 || V_29 -> V_270 != 0 ;
}
return V_328 ;
}
T_2 char * F_111 ( const char * V_329 , int V_53 , int V_330 , int V_331 ) {
static char V_332 [ 1 ] = { 0 } ;
static char * V_14 = 0 ;
static int V_333 = 0 ;
static int V_334 = 0 ;
int V_12 ;
char V_335 [ 40 ] ;
if( V_329 == 0 ) {
if( V_334 == 0 && V_14 != 0 ) V_14 [ 0 ] = 0 ;
V_334 = 0 ;
return V_14 ;
}
if( V_53 <= 0 ) {
if( V_53 < 0 ) {
V_334 += V_53 ;
assert ( V_334 >= 0 ) ;
}
V_53 = F_57 ( V_329 ) ;
}
if( ( int ) ( V_53 + sizeof( V_335 ) * 2 + V_334 ) >= V_333 ) {
V_333 = ( int ) ( V_53 + sizeof( V_335 ) * 2 + V_334 + 200 ) ;
V_14 = ( char * ) realloc ( V_14 , V_333 ) ;
F_13 ( V_14 ) ;
}
if( V_14 == 0 ) return V_332 ;
while( V_53 -- > 0 ) {
V_12 = * ( V_329 ++ ) ;
if( V_12 == '%' && V_53 > 0 && V_329 [ 0 ] == 'd' ) {
F_3 ( V_335 , L_194 , V_330 ) ;
V_330 = V_331 ;
F_4 ( & V_14 [ V_334 ] , V_335 ) ;
V_334 += F_57 ( & V_14 [ V_334 ] ) ;
V_329 ++ ;
V_53 -- ;
} else{
V_14 [ V_334 ++ ] = ( char ) V_12 ;
}
}
V_14 [ V_334 ] = 0 ;
return V_14 ;
}
T_2 int F_112 ( struct V_58 * V_67 , struct V_43 * V_34 ) {
char * V_145 , * V_59 ;
int V_9 ;
int V_19 = 0 ;
int V_336 = 0 ;
const char * V_337 = 0 ;
char V_338 = 0 ;
char V_339 ;
char V_334 [ V_241 ] ;
char V_340 [ 50 ] ;
char V_341 [ 900 ] ;
for( V_9 = 0 ; V_9 < V_34 -> V_61 ; V_9 ++ ) V_334 [ V_9 ] = 0 ;
V_338 = 0 ;
if( V_34 -> V_184 == 0 ) {
static char V_342 [ 2 ] = { '\n' , '\0' } ;
V_34 -> V_184 = V_342 ;
V_34 -> line = V_34 -> V_117 ;
V_34 -> V_231 = 1 ;
} else{
V_34 -> V_231 = 0 ;
}
if( V_34 -> V_61 == 0 ) {
V_339 = 1 ;
} else if( V_34 -> V_239 [ 0 ] == 0 ) {
V_339 = 1 ;
if( F_110 ( V_34 -> V_62 [ 0 ] , V_67 ) ) {
F_111 ( 0 , 0 , 0 , 0 ) ;
F_111 ( L_195 , 0 ,
V_34 -> V_62 [ 0 ] -> V_30 , 1 - V_34 -> V_61 ) ;
V_34 -> V_343 = F_92 ( F_111 ( 0 , 0 , 0 , 0 ) ) ;
V_34 -> V_231 = 0 ;
}
} else if( V_34 -> V_228 == 0 ) {
V_339 = 1 ;
} else if( strcmp ( V_34 -> V_228 , V_34 -> V_239 [ 0 ] ) == 0 ) {
V_339 = 1 ;
V_338 = 1 ;
V_334 [ 0 ] = 1 ;
if( V_34 -> V_75 -> V_327 != V_34 -> V_62 [ 0 ] -> V_327 ) {
F_23 ( V_67 -> V_82 , V_34 -> V_117 ,
L_196
L_197 ,
V_34 -> V_75 -> V_84 , V_34 -> V_228 , V_34 -> V_62 [ 0 ] -> V_84 , V_34 -> V_239 [ 0 ] ) ;
V_67 -> V_85 ++ ;
}
} else{
F_3 ( V_341 , L_198 ,
V_34 -> V_228 , V_34 -> V_239 [ 0 ] ) ;
V_337 = strstr ( V_34 -> V_184 , V_341 ) ;
if( V_337 != 0 ) {
V_339 = 1 ;
} else{
V_339 = 0 ;
}
}
if( V_339 ) {
sprintf ( V_340 , L_199 , 1 - V_34 -> V_61 , V_34 -> V_75 -> V_327 ) ;
} else{
V_19 = 1 ;
sprintf ( V_340 , L_200 , V_34 -> V_75 -> V_327 ) ;
}
F_111 ( 0 , 0 , 0 , 0 ) ;
for( V_145 = ( char * ) V_34 -> V_184 ; * V_145 ; V_145 ++ ) {
if( V_145 == V_337 ) {
F_111 ( V_341 , 0 , 0 , 0 ) ;
V_145 += F_57 ( V_341 ) - 1 ;
V_336 = 1 ;
continue;
}
if( ISALPHA ( * V_145 ) && ( V_145 == V_34 -> V_184 || ( ! ISALNUM ( V_145 [ - 1 ] ) && V_145 [ - 1 ] != '_' ) ) ) {
char V_344 ;
for( V_59 = & V_145 [ 1 ] ; ISALNUM ( * V_59 ) || * V_59 == '_' ; V_59 ++ ) ;
V_344 = * V_59 ;
* V_59 = 0 ;
if( V_34 -> V_228 && strcmp ( V_145 , V_34 -> V_228 ) == 0 ) {
F_111 ( V_340 , 0 , 0 , 0 ) ;
V_145 = V_59 ;
V_338 = 1 ;
} else{
for( V_9 = 0 ; V_9 < V_34 -> V_61 ; V_9 ++ ) {
if( V_34 -> V_239 [ V_9 ] && strcmp ( V_145 , V_34 -> V_239 [ V_9 ] ) == 0 ) {
if( V_9 == 0 && V_336 ) {
F_23 ( V_67 -> V_82 , V_34 -> V_117 ,
L_201 ,
V_34 -> V_239 [ 0 ] , V_341 ) ;
V_67 -> V_85 ++ ;
} else if( V_145 != V_34 -> V_184 && V_145 [ - 1 ] == '@' ) {
F_111 ( L_202 , - 1 , V_9 - V_34 -> V_61 + 1 , 0 ) ;
} else{
struct V_37 * V_29 = V_34 -> V_62 [ V_9 ] ;
int V_327 ;
if( V_29 -> type == V_63 ) {
V_327 = V_29 -> V_65 [ 0 ] -> V_327 ;
} else{
V_327 = V_29 -> V_327 ;
}
F_111 ( L_199 , 0 , V_9 - V_34 -> V_61 + 1 , V_327 ) ;
}
V_145 = V_59 ;
V_334 [ V_9 ] = 1 ;
break;
}
}
}
* V_59 = V_344 ;
}
F_111 ( V_145 , 1 , 0 , 0 ) ;
}
V_145 = F_111 ( 0 , 0 , 0 , 0 ) ;
if( V_145 && V_145 [ 0 ] ) V_34 -> V_184 = F_92 ( V_145 ) ;
F_111 ( 0 , 0 , 0 , 0 ) ;
if( V_34 -> V_228 && ! V_338 ) {
F_23 ( V_67 -> V_82 , V_34 -> V_117 ,
L_203 ,
V_34 -> V_228 , V_34 -> V_75 -> V_84 , V_34 -> V_228 ) ;
V_67 -> V_85 ++ ;
}
for( V_9 = 0 ; V_9 < V_34 -> V_61 ; V_9 ++ ) {
if( V_34 -> V_239 [ V_9 ] ) {
if( V_9 > 0 ) {
int V_10 ;
if( V_34 -> V_228 && strcmp ( V_34 -> V_228 , V_34 -> V_239 [ V_9 ] ) == 0 ) {
F_23 ( V_67 -> V_82 , V_34 -> V_117 ,
L_204
L_205 ,
V_34 -> V_62 [ V_9 ] -> V_84 , V_34 -> V_239 ) ;
V_67 -> V_85 ++ ;
}
for( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
if( V_34 -> V_239 [ V_10 ] && strcmp ( V_34 -> V_239 [ V_10 ] , V_34 -> V_239 [ V_9 ] ) == 0 ) {
F_23 ( V_67 -> V_82 , V_34 -> V_117 ,
L_206 ,
V_34 -> V_239 [ V_9 ] ) ;
V_67 -> V_85 ++ ;
break;
}
}
}
if( ! V_334 [ V_9 ] ) {
F_23 ( V_67 -> V_82 , V_34 -> V_117 ,
L_207 ,
V_34 -> V_239 [ V_9 ] , V_34 -> V_62 [ V_9 ] -> V_84 , V_34 -> V_239 [ V_9 ] ) ;
V_67 -> V_85 ++ ;
}
} else if( V_9 > 0 && F_110 ( V_34 -> V_62 [ V_9 ] , V_67 ) ) {
F_111 ( L_195 , 0 ,
V_34 -> V_62 [ V_9 ] -> V_30 , V_9 - V_34 -> V_61 + 1 ) ;
}
}
if( V_339 == 0 ) {
F_111 ( L_208 , 0 , 1 - V_34 -> V_61 , V_34 -> V_75 -> V_327 ) ;
F_111 ( V_340 , 0 , 0 , 0 ) ;
F_111 ( L_209 , 0 , 0 , 0 ) ;
}
V_145 = F_111 ( 0 , 0 , 0 , 0 ) ;
if( V_145 && V_145 [ 0 ] ) {
V_34 -> V_345 = F_92 ( V_145 ) ;
V_34 -> V_231 = 0 ;
}
return V_19 ;
}
T_2 void F_113 (
T_5 * V_321 ,
struct V_43 * V_34 ,
struct V_58 * V_67 ,
int * V_143
) {
const char * V_145 ;
if( V_34 -> V_343 && V_34 -> V_343 [ 0 ] ) {
fprintf ( V_321 , L_210 , V_34 -> V_343 ) ;
for( V_145 = V_34 -> V_343 ; * V_145 ; V_145 ++ ) { if( * V_145 == '\n' ) ( * V_143 ) ++ ; }
}
if( V_34 -> V_184 ) {
if( ! V_67 -> V_169 ) {
( * V_143 ) ++ ;
F_107 ( V_321 , V_34 -> line , V_67 -> V_82 ) ;
}
fprintf ( V_321 , L_210 , V_34 -> V_184 ) ;
for( V_145 = V_34 -> V_184 ; * V_145 ; V_145 ++ ) { if( * V_145 == '\n' ) ( * V_143 ) ++ ; }
fprintf ( V_321 , L_193 ) ; ( * V_143 ) ++ ;
if( ! V_67 -> V_169 ) {
( * V_143 ) ++ ;
F_107 ( V_321 , * V_143 , V_67 -> V_305 ) ;
}
}
if( V_34 -> V_345 && V_34 -> V_345 [ 0 ] ) {
fprintf ( V_321 , L_65 , V_34 -> V_345 ) ;
for( V_145 = V_34 -> V_345 ; * V_145 ; V_145 ++ ) { if( * V_145 == '\n' ) ( * V_143 ) ++ ; }
}
if( V_34 -> V_343 ) {
fprintf ( V_321 , L_193 ) ; ( * V_143 ) ++ ;
}
return;
}
T_2 void F_114 (
T_5 * V_321 ,
struct V_58 * V_67 ,
int * V_346 ,
int V_168
) {
int V_143 = * V_346 ;
char * * V_347 ;
int V_348 ;
int V_349 ;
char * V_350 ;
int V_9 , V_10 ;
unsigned V_351 ;
const char * V_84 ;
V_348 = V_67 -> V_69 * 2 ;
V_347 = ( char * * ) calloc ( V_348 , sizeof( char * ) ) ;
if( V_347 == 0 ) {
fprintf ( V_17 , L_211 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_348 ; V_9 ++ ) V_347 [ V_9 ] = 0 ;
V_349 = 0 ;
if( V_67 -> V_259 ) {
V_349 = F_57 ( V_67 -> V_259 ) ;
}
for( V_9 = 0 ; V_9 < V_67 -> V_69 ; V_9 ++ ) {
int V_215 ;
struct V_37 * V_29 = V_67 -> V_70 [ V_9 ] ;
if( V_29 -> V_272 == 0 ) continue;
V_215 = F_57 ( V_29 -> V_272 ) ;
if( V_215 > V_349 ) V_349 = V_215 ;
}
V_350 = ( char * ) malloc ( V_349 * 2 + 1 ) ;
F_13 ( V_350 ) ;
for( V_9 = 0 ; V_9 < V_67 -> V_69 ; V_9 ++ ) {
struct V_37 * V_29 = V_67 -> V_70 [ V_9 ] ;
char * V_145 ;
if( V_29 == V_67 -> V_140 ) {
V_29 -> V_327 = V_348 + 1 ;
continue;
}
if( V_29 -> type != V_76 || ( V_29 -> V_272 == 0 && V_67 -> V_259 == 0 ) ) {
V_29 -> V_327 = 0 ;
continue;
}
V_145 = V_29 -> V_272 ;
if( V_145 == 0 ) V_145 = V_67 -> V_259 ;
V_10 = 0 ;
while( ISSPACE ( * V_145 ) ) V_145 ++ ;
while( * V_145 ) V_350 [ V_10 ++ ] = * V_145 ++ ;
while( V_10 > 0 && ISSPACE ( V_350 [ V_10 - 1 ] ) ) V_10 -- ;
V_350 [ V_10 ] = 0 ;
if( V_67 -> V_258 && strcmp ( V_350 , V_67 -> V_258 ) == 0 ) {
V_29 -> V_327 = 0 ;
continue;
}
V_351 = 0 ;
for( V_10 = 0 ; V_350 [ V_10 ] ; V_10 ++ ) {
V_351 = V_351 * 53 + V_350 [ V_10 ] ;
}
V_351 = ( V_351 & 0x7fffffff ) % V_348 ;
while( V_347 [ V_351 ] ) {
if( strcmp ( V_347 [ V_351 ] , V_350 ) == 0 ) {
V_29 -> V_327 = V_351 + 1 ;
break;
}
V_351 ++ ;
if( V_351 >= ( unsigned ) V_348 ) V_351 = 0 ;
}
if( V_347 [ V_351 ] == 0 ) {
V_29 -> V_327 = V_351 + 1 ;
V_347 [ V_351 ] = ( char * ) malloc ( F_57 ( V_350 ) + 1 ) ;
F_13 ( V_347 [ V_351 ] ) ;
F_4 ( V_347 [ V_351 ] , V_350 ) ;
}
}
V_84 = V_67 -> V_84 ? V_67 -> V_84 : L_182 ;
if( V_168 ) { fprintf ( V_321 , L_212 ) ; V_143 ++ ; }
fprintf ( V_321 , L_213 , V_84 ,
V_67 -> V_258 ? V_67 -> V_258 : L_214 ) ; V_143 ++ ;
if( V_168 ) { fprintf ( V_321 , L_215 ) ; V_143 ++ ; }
fprintf ( V_321 , L_216 ) ; V_143 ++ ;
fprintf ( V_321 , L_217 ) ; V_143 ++ ;
fprintf ( V_321 , L_218 , V_84 ) ; V_143 ++ ;
for( V_9 = 0 ; V_9 < V_348 ; V_9 ++ ) {
if( V_347 [ V_9 ] == 0 ) continue;
fprintf ( V_321 , L_219 , V_347 [ V_9 ] , V_9 + 1 ) ; V_143 ++ ;
free ( V_347 [ V_9 ] ) ;
}
if( V_67 -> V_140 -> V_180 ) {
fprintf ( V_321 , L_220 , V_67 -> V_140 -> V_327 ) ; V_143 ++ ;
}
free ( V_350 ) ;
free ( V_347 ) ;
fprintf ( V_321 , L_221 ) ; V_143 ++ ;
* V_346 = V_143 ;
}
static const char * F_115 ( int V_352 , int V_353 , int * V_354 ) {
const char * V_355 = L_222 ;
int V_356 = 4 ;
if( V_352 >= 0 ) {
if( V_353 <= 255 ) {
V_355 = L_223 ;
V_356 = 1 ;
} else if( V_353 < 65535 ) {
V_355 = L_224 ;
V_356 = 2 ;
} else{
V_355 = L_225 ;
V_356 = 4 ;
}
} else if( V_352 >= - 127 && V_353 <= 127 ) {
V_355 = L_226 ;
V_356 = 1 ;
} else if( V_352 >= - 32767 && V_353 < 32767 ) {
V_355 = L_227 ;
V_356 = 2 ;
}
if( V_354 ) * V_354 = V_356 ;
return V_355 ;
}
static int F_116 ( const void * V_98 , const void * V_99 ) {
const struct V_357 * V_330 = ( const struct V_357 * ) V_98 ;
const struct V_357 * V_331 = ( const struct V_357 * ) V_99 ;
int V_12 ;
V_12 = V_331 -> V_54 - V_330 -> V_54 ;
if( V_12 == 0 ) {
V_12 = V_330 -> V_358 - V_331 -> V_358 ;
}
assert ( V_12 != 0 || V_330 == V_331 ) ;
return V_12 ;
}
static void F_117 ( T_5 * V_321 , struct V_43 * V_34 ) {
int V_10 ;
fprintf ( V_321 , L_156 , V_34 -> V_75 -> V_84 ) ;
for( V_10 = 0 ; V_10 < V_34 -> V_61 ; V_10 ++ ) {
struct V_37 * V_29 = V_34 -> V_62 [ V_10 ] ;
if( V_29 -> type != V_63 ) {
fprintf ( V_321 , L_66 , V_29 -> V_84 ) ;
} else{
int V_11 ;
fprintf ( V_321 , L_66 , V_29 -> V_65 [ 0 ] -> V_84 ) ;
for( V_11 = 1 ; V_11 < V_29 -> V_64 ; V_11 ++ ) {
fprintf ( V_321 , L_153 , V_29 -> V_65 [ V_11 ] -> V_84 ) ;
}
}
}
}
void F_78 (
struct V_58 * V_67 ,
int V_168
) {
T_5 * V_321 , * V_320 ;
char line [ V_323 ] ;
int V_143 ;
struct V_42 * V_41 ;
struct V_22 * V_8 ;
struct V_43 * V_34 ;
struct T_3 * V_359 ;
int V_9 , V_10 , V_53 , V_360 ;
int V_361 ;
int V_362 ;
const char * V_84 ;
int V_363 , V_364 ;
int V_365 , V_366 ;
struct V_357 * V_367 ;
V_320 = F_106 ( V_67 ) ;
if( V_320 == 0 ) return;
V_321 = F_97 ( V_67 , L_228 , L_169 ) ;
if( V_321 == 0 ) {
fclose ( V_320 ) ;
return;
}
V_143 = 1 ;
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
F_108 ( V_321 , V_67 , V_67 -> include , & V_143 ) ;
if( V_168 ) {
char * V_368 = F_95 ( V_67 , L_229 ) ;
fprintf ( V_321 , L_230 , V_368 ) ; V_143 ++ ;
free ( V_368 ) ;
}
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
if( V_168 ) {
const char * V_369 ;
fprintf ( V_321 , L_212 ) ; V_143 ++ ;
if( V_67 -> V_254 ) V_369 = V_67 -> V_254 ;
else V_369 = L_68 ;
for( V_9 = 1 ; V_9 < V_67 -> V_73 ; V_9 ++ ) {
fprintf ( V_321 , L_231 , V_369 , V_67 -> V_70 [ V_9 ] -> V_84 , V_9 ) ;
V_143 ++ ;
}
fprintf ( V_321 , L_215 ) ; V_143 ++ ;
}
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
fprintf ( V_321 , L_232 ,
F_115 ( 0 , V_67 -> V_69 + 1 , & V_362 ) ) ; V_143 ++ ;
fprintf ( V_321 , L_233 , V_67 -> V_69 + 1 ) ; V_143 ++ ;
fprintf ( V_321 , L_234 ,
F_115 ( 0 , V_67 -> V_97 + V_67 -> V_182 * 2 + 5 , & V_361 ) ) ; V_143 ++ ;
if( V_67 -> V_282 ) {
fprintf ( V_321 , L_235 ,
V_67 -> V_282 -> V_30 ) ; V_143 ++ ;
}
F_114 ( V_321 , V_67 , & V_143 , V_168 ) ;
fprintf ( V_321 , L_236 ) ; V_143 ++ ;
if( V_67 -> V_260 ) {
fprintf ( V_321 , L_237 , V_67 -> V_260 ) ; V_143 ++ ;
} else{
fprintf ( V_321 , L_238 ) ; V_143 ++ ;
}
fprintf ( V_321 , L_215 ) ; V_143 ++ ;
if( V_168 ) {
fprintf ( V_321 , L_212 ) ; V_143 ++ ;
}
V_84 = V_67 -> V_84 ? V_67 -> V_84 : L_182 ;
if( V_67 -> V_38 && V_67 -> V_38 [ 0 ] ) {
V_9 = F_57 ( V_67 -> V_38 ) ;
while( V_9 >= 1 && ISSPACE ( V_67 -> V_38 [ V_9 - 1 ] ) ) V_9 -- ;
while( V_9 >= 1 && ( ISALNUM ( V_67 -> V_38 [ V_9 - 1 ] ) || V_67 -> V_38 [ V_9 - 1 ] == '_' ) ) V_9 -- ;
fprintf ( V_321 , L_239 , V_84 , V_67 -> V_38 ) ; V_143 ++ ;
fprintf ( V_321 , L_240 , V_84 , V_67 -> V_38 ) ; V_143 ++ ;
fprintf ( V_321 , L_241 ,
V_84 , V_67 -> V_38 , & V_67 -> V_38 [ V_9 ] ) ; V_143 ++ ;
fprintf ( V_321 , L_242 ,
V_84 , & V_67 -> V_38 [ V_9 ] , & V_67 -> V_38 [ V_9 ] ) ; V_143 ++ ;
} else{
fprintf ( V_321 , L_243 , V_84 ) ; V_143 ++ ;
fprintf ( V_321 , L_244 , V_84 ) ; V_143 ++ ;
fprintf ( V_321 , L_245 , V_84 ) ; V_143 ++ ;
fprintf ( V_321 , L_246 , V_84 ) ; V_143 ++ ;
}
if( V_168 ) {
fprintf ( V_321 , L_215 ) ; V_143 ++ ;
}
if( V_67 -> V_140 -> V_180 ) {
fprintf ( V_321 , L_247 , V_67 -> V_140 -> V_30 ) ; V_143 ++ ;
fprintf ( V_321 , L_248 , V_67 -> V_140 -> V_327 ) ; V_143 ++ ;
}
if( V_67 -> V_281 ) {
fprintf ( V_321 , L_249 ) ; V_143 ++ ;
}
V_367 = (struct V_357 * ) calloc ( V_67 -> V_185 * 2 , sizeof( V_367 [ 0 ] ) ) ;
F_13 ( V_367 ) ;
for( V_9 = 0 ; V_9 < V_67 -> V_185 ; V_9 ++ ) {
V_41 = V_67 -> V_111 [ V_9 ] ;
V_367 [ V_9 * 2 ] . V_41 = V_41 ;
V_367 [ V_9 * 2 ] . V_370 = 1 ;
V_367 [ V_9 * 2 ] . V_54 = V_41 -> V_371 ;
V_367 [ V_9 * 2 + 1 ] . V_41 = V_41 ;
V_367 [ V_9 * 2 + 1 ] . V_370 = 0 ;
V_367 [ V_9 * 2 + 1 ] . V_54 = V_41 -> V_372 ;
}
V_364 = V_363 = 0 ;
V_366 = V_365 = 0 ;
for( V_9 = 0 ; V_9 < V_67 -> V_185 * 2 ; V_9 ++ ) V_367 [ V_9 ] . V_358 = V_9 ;
qsort ( V_367 , V_67 -> V_185 * 2 , sizeof( V_367 [ 0 ] ) , F_116 ) ;
V_359 = F_11 () ;
for( V_9 = 0 ; V_9 < V_67 -> V_185 * 2 && V_367 [ V_9 ] . V_54 > 0 ; V_9 ++ ) {
V_41 = V_367 [ V_9 ] . V_41 ;
if( V_367 [ V_9 ] . V_370 ) {
for( V_8 = V_41 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
int V_22 ;
if( V_8 -> V_29 -> V_30 >= V_67 -> V_73 ) continue;
V_22 = F_104 ( V_67 , V_8 ) ;
if( V_22 < 0 ) continue;
F_12 ( V_359 , V_8 -> V_29 -> V_30 , V_22 ) ;
}
V_41 -> V_373 = F_14 ( V_359 ) ;
if( V_41 -> V_373 < V_363 ) V_363 = V_41 -> V_373 ;
if( V_41 -> V_373 > V_364 ) V_364 = V_41 -> V_373 ;
} else{
for( V_8 = V_41 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
int V_22 ;
if( V_8 -> V_29 -> V_30 < V_67 -> V_73 ) continue;
if( V_8 -> V_29 -> V_30 == V_67 -> V_69 ) continue;
V_22 = F_104 ( V_67 , V_8 ) ;
if( V_22 < 0 ) continue;
F_12 ( V_359 , V_8 -> V_29 -> V_30 , V_22 ) ;
}
V_41 -> V_374 = F_14 ( V_359 ) ;
if( V_41 -> V_374 < V_365 ) V_365 = V_41 -> V_374 ;
if( V_41 -> V_374 > V_366 ) V_366 = V_41 -> V_374 ;
}
#if 0
{ int jj, nn;
for(jj=nn=0; jj<pActtab->nAction; jj++){
if( pActtab->aAction[jj].action<0 ) nn++;
}
printf("%4d: State %3d %s n: %2d size: %5d freespace: %d\n",
i, stp->statenum, ax[i].isTkn ? "Token" : "Var ",
ax[i].nAction, pActtab->nAction, nn);
}
#endif
}
free ( V_367 ) ;
for( V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) V_34 -> V_375 = V_72 ;
for( V_9 = 0 ; V_9 < V_67 -> V_185 ; V_9 ++ ) {
for( V_8 = V_67 -> V_111 [ V_9 ] -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_31 || V_8 -> type == V_32 ) {
V_8 -> V_33 . V_34 -> V_375 = V_9 ? V_77 : V_72 ;
}
}
}
fprintf ( V_321 , L_250 , V_67 -> V_185 ) ; V_143 ++ ;
fprintf ( V_321 , L_251 , V_67 -> V_182 ) ; V_143 ++ ;
fprintf ( V_321 , L_252 , V_67 -> V_185 - 1 ) ; V_143 ++ ;
fprintf ( V_321 , L_253 , V_67 -> V_97 ) ; V_143 ++ ;
V_9 = V_67 -> V_97 + V_67 -> V_182 ;
fprintf ( V_321 , L_254 , V_9 - 1 ) ; V_143 ++ ;
fprintf ( V_321 , L_255 , V_9 ) ; V_143 ++ ;
V_9 = V_67 -> V_97 + V_67 -> V_182 * 2 ;
fprintf ( V_321 , L_256 , V_9 - 1 ) ; V_143 ++ ;
fprintf ( V_321 , L_257 , V_9 ) ; V_143 ++ ;
fprintf ( V_321 , L_258 , V_9 + 1 ) ; V_143 ++ ;
fprintf ( V_321 , L_259 , V_9 + 2 ) ; V_143 ++ ;
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
V_67 -> V_186 = V_53 = F_118 ( V_359 ) ;
V_67 -> V_187 += V_53 * V_361 ;
fprintf ( V_321 , L_260 , V_53 ) ; V_143 ++ ;
fprintf ( V_321 , L_261 ) ; V_143 ++ ;
for( V_9 = V_10 = 0 ; V_9 < V_53 ; V_9 ++ ) {
int V_22 = F_119 ( V_359 , V_9 ) ;
if( V_22 < 0 ) V_22 = V_67 -> V_97 + V_67 -> V_182 + 2 ;
if( V_10 == 0 ) fprintf ( V_321 , L_262 , V_9 ) ;
fprintf ( V_321 , L_263 , V_22 ) ;
if( V_10 == 9 || V_9 == V_53 - 1 ) {
fprintf ( V_321 , L_14 ) ; V_143 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_321 , L_264 ) ; V_143 ++ ;
V_67 -> V_187 += V_53 * V_362 ;
fprintf ( V_321 , L_265 ) ; V_143 ++ ;
for( V_9 = V_10 = 0 ; V_9 < V_53 ; V_9 ++ ) {
int V_376 = F_120 ( V_359 , V_9 ) ;
if( V_376 < 0 ) V_376 = V_67 -> V_69 ;
if( V_10 == 0 ) fprintf ( V_321 , L_262 , V_9 ) ;
fprintf ( V_321 , L_263 , V_376 ) ;
if( V_10 == 9 || V_9 == V_53 - 1 ) {
fprintf ( V_321 , L_14 ) ; V_143 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_321 , L_264 ) ; V_143 ++ ;
V_53 = V_67 -> V_185 ;
while( V_53 > 0 && V_67 -> V_111 [ V_53 - 1 ] -> V_373 == V_377 ) V_53 -- ;
fprintf ( V_321 , L_266 , V_67 -> V_186 ) ; V_143 ++ ;
fprintf ( V_321 , L_267 , V_53 - 1 ) ; V_143 ++ ;
fprintf ( V_321 , L_268 , V_363 ) ; V_143 ++ ;
fprintf ( V_321 , L_269 , V_364 ) ; V_143 ++ ;
fprintf ( V_321 , L_270 ,
F_115 ( V_363 , V_67 -> V_73 + V_67 -> V_186 , & V_360 ) ) ;
V_143 ++ ;
V_67 -> V_187 += V_53 * V_360 ;
for( V_9 = V_10 = 0 ; V_9 < V_53 ; V_9 ++ ) {
int V_378 ;
V_41 = V_67 -> V_111 [ V_9 ] ;
V_378 = V_41 -> V_373 ;
if( V_378 == V_377 ) V_378 = V_67 -> V_186 ;
if( V_10 == 0 ) fprintf ( V_321 , L_262 , V_9 ) ;
fprintf ( V_321 , L_263 , V_378 ) ;
if( V_10 == 9 || V_9 == V_53 - 1 ) {
fprintf ( V_321 , L_14 ) ; V_143 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_321 , L_264 ) ; V_143 ++ ;
fprintf ( V_321 , L_271 , V_365 - 1 ) ; V_143 ++ ;
V_53 = V_67 -> V_185 ;
while( V_53 > 0 && V_67 -> V_111 [ V_53 - 1 ] -> V_374 == V_377 ) V_53 -- ;
fprintf ( V_321 , L_272 , V_53 - 1 ) ; V_143 ++ ;
fprintf ( V_321 , L_273 , V_365 ) ; V_143 ++ ;
fprintf ( V_321 , L_274 , V_366 ) ; V_143 ++ ;
fprintf ( V_321 , L_275 ,
F_115 ( V_365 - 1 , V_366 , & V_360 ) ) ; V_143 ++ ;
V_67 -> V_187 += V_53 * V_360 ;
for( V_9 = V_10 = 0 ; V_9 < V_53 ; V_9 ++ ) {
int V_378 ;
V_41 = V_67 -> V_111 [ V_9 ] ;
V_378 = V_41 -> V_374 ;
if( V_378 == V_377 ) V_378 = V_365 - 1 ;
if( V_10 == 0 ) fprintf ( V_321 , L_262 , V_9 ) ;
fprintf ( V_321 , L_263 , V_378 ) ;
if( V_10 == 9 || V_9 == V_53 - 1 ) {
fprintf ( V_321 , L_14 ) ; V_143 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_321 , L_264 ) ; V_143 ++ ;
fprintf ( V_321 , L_276 ) ; V_143 ++ ;
V_53 = V_67 -> V_185 ;
V_67 -> V_187 += V_53 * V_361 ;
for( V_9 = V_10 = 0 ; V_9 < V_53 ; V_9 ++ ) {
V_41 = V_67 -> V_111 [ V_9 ] ;
if( V_10 == 0 ) fprintf ( V_321 , L_262 , V_9 ) ;
fprintf ( V_321 , L_263 , V_41 -> V_379 + V_67 -> V_97 + V_67 -> V_182 ) ;
if( V_10 == 9 || V_9 == V_53 - 1 ) {
fprintf ( V_321 , L_14 ) ; V_143 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_321 , L_264 ) ; V_143 ++ ;
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
if( V_67 -> V_281 ) {
int V_380 = V_67 -> V_73 - 1 ;
while( V_380 > 0 && V_67 -> V_70 [ V_380 ] -> V_265 == 0 ) { V_380 -- ; }
V_67 -> V_187 += ( V_380 + 1 ) * V_362 ;
for( V_9 = 0 ; V_9 <= V_380 ; V_9 ++ ) {
struct V_37 * V_44 = V_67 -> V_70 [ V_9 ] ;
if( V_44 -> V_265 == 0 ) {
fprintf ( V_321 , L_277 , V_44 -> V_84 ) ;
} else{
fprintf ( V_321 , L_278 , V_44 -> V_265 -> V_30 ,
V_44 -> V_84 , V_44 -> V_265 -> V_84 ) ;
}
V_143 ++ ;
}
}
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
for( V_9 = 0 ; V_9 < V_67 -> V_69 ; V_9 ++ ) {
F_3 ( line , L_279 , V_67 -> V_70 [ V_9 ] -> V_84 ) ;
fprintf ( V_321 , L_280 , line ) ;
if( ( V_9 & 3 ) == 3 ) { fprintf ( V_321 , L_14 ) ; V_143 ++ ; }
}
if( ( V_9 & 3 ) != 0 ) { fprintf ( V_321 , L_14 ) ; V_143 ++ ; }
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
for( V_9 = 0 , V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 , V_9 ++ ) {
assert ( V_34 -> V_155 == V_9 ) ;
fprintf ( V_321 , L_281 , V_9 ) ;
F_117 ( V_321 , V_34 ) ;
fprintf ( V_321 , L_282 ) ; V_143 ++ ;
}
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
if( V_67 -> V_252 ) {
int V_381 = 1 ;
for( V_9 = 0 ; V_9 < V_67 -> V_69 ; V_9 ++ ) {
struct V_37 * V_29 = V_67 -> V_70 [ V_9 ] ;
if( V_29 == 0 || V_29 -> type != V_80 ) continue;
if( V_381 ) {
fprintf ( V_321 , L_283 ) ; V_143 ++ ;
V_381 = 0 ;
}
fprintf ( V_321 , L_284 , V_29 -> V_30 , V_29 -> V_84 ) ; V_143 ++ ;
}
for( V_9 = 0 ; V_9 < V_67 -> V_69 && V_67 -> V_70 [ V_9 ] -> type != V_80 ; V_9 ++ ) ;
if( V_9 < V_67 -> V_69 ) {
F_109 ( V_321 , V_67 -> V_70 [ V_9 ] , V_67 , & V_143 ) ;
fprintf ( V_321 , L_285 ) ; V_143 ++ ;
}
}
if( V_67 -> V_253 ) {
struct V_37 * V_382 = 0 ;
int V_381 = 1 ;
for( V_9 = 0 ; V_9 < V_67 -> V_69 ; V_9 ++ ) {
struct V_37 * V_29 = V_67 -> V_70 [ V_9 ] ;
if( V_29 == 0 || V_29 -> type == V_80 ||
V_29 -> V_30 <= 0 || V_29 -> V_270 != 0 ) continue;
if( V_381 ) {
fprintf ( V_321 , L_286 ) ; V_143 ++ ;
V_381 = 0 ;
}
fprintf ( V_321 , L_284 , V_29 -> V_30 , V_29 -> V_84 ) ; V_143 ++ ;
V_382 = V_29 ;
}
if( V_382 != 0 ) {
F_109 ( V_321 , V_382 , V_67 , & V_143 ) ;
}
fprintf ( V_321 , L_285 ) ; V_143 ++ ;
}
for( V_9 = 0 ; V_9 < V_67 -> V_69 ; V_9 ++ ) {
struct V_37 * V_29 = V_67 -> V_70 [ V_9 ] ;
if( V_29 == 0 || V_29 -> type == V_80 || V_29 -> V_270 == 0 ) continue;
if( V_29 -> V_271 < 0 ) continue;
fprintf ( V_321 , L_284 , V_29 -> V_30 , V_29 -> V_84 ) ; V_143 ++ ;
for( V_10 = V_9 + 1 ; V_10 < V_67 -> V_69 ; V_10 ++ ) {
struct V_37 * V_383 = V_67 -> V_70 [ V_10 ] ;
if( V_383 && V_383 -> type != V_80 && V_383 -> V_270
&& V_383 -> V_327 == V_29 -> V_327
&& strcmp ( V_29 -> V_270 , V_383 -> V_270 ) == 0 ) {
fprintf ( V_321 , L_284 ,
V_383 -> V_30 , V_383 -> V_84 ) ; V_143 ++ ;
V_383 -> V_271 = - 1 ;
}
}
F_109 ( V_321 , V_67 -> V_70 [ V_9 ] , V_67 , & V_143 ) ;
fprintf ( V_321 , L_285 ) ; V_143 ++ ;
}
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
F_108 ( V_321 , V_67 , V_67 -> V_257 , & V_143 ) ;
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
for( V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
fprintf ( V_321 , L_287 , V_34 -> V_75 -> V_30 , V_34 -> V_61 ) ; V_143 ++ ;
}
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
V_9 = 0 ;
for( V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
V_9 += F_112 ( V_67 , V_34 ) ;
}
if( V_9 ) {
fprintf ( V_321 , L_288 ) ; V_143 ++ ;
}
for( V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
struct V_43 * V_384 ;
if( V_34 -> V_385 ) continue;
if( V_34 -> V_231 ) {
continue;
}
fprintf ( V_321 , L_289 , V_34 -> V_155 ) ;
F_117 ( V_321 , V_34 ) ;
fprintf ( V_321 , L_290 ) ; V_143 ++ ;
for( V_384 = V_34 -> V_26 ; V_384 ; V_384 = V_384 -> V_26 ) {
if( V_384 -> V_184 == V_34 -> V_184 && V_384 -> V_343 == V_34 -> V_343
&& V_384 -> V_345 == V_34 -> V_345 ) {
fprintf ( V_321 , L_289 , V_384 -> V_155 ) ;
F_117 ( V_321 , V_384 ) ;
fprintf ( V_321 , L_291 , V_384 -> V_155 ) ; V_143 ++ ;
V_384 -> V_385 = 1 ;
}
}
F_113 ( V_321 , V_34 , V_67 , & V_143 ) ;
fprintf ( V_321 , L_292 ) ; V_143 ++ ;
V_34 -> V_385 = 1 ;
}
fprintf ( V_321 , L_293 ) ; V_143 ++ ;
for( V_34 = V_67 -> V_43 ; V_34 ; V_34 = V_34 -> V_26 ) {
if( V_34 -> V_385 ) continue;
assert ( V_34 -> V_231 ) ;
fprintf ( V_321 , L_294 , V_34 -> V_155 ) ;
F_117 ( V_321 , V_34 ) ;
if( V_34 -> V_375 ) {
fprintf ( V_321 , L_291 , V_34 -> V_155 ) ; V_143 ++ ;
} else{
fprintf ( V_321 , L_295 ,
V_34 -> V_155 ) ; V_143 ++ ;
}
}
fprintf ( V_321 , L_292 ) ; V_143 ++ ;
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
F_108 ( V_321 , V_67 , V_67 -> V_256 , & V_143 ) ;
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
F_108 ( V_321 , V_67 , V_67 -> error , & V_143 ) ;
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
F_108 ( V_321 , V_67 , V_67 -> V_255 , & V_143 ) ;
F_105 ( V_67 -> V_84 , V_320 , V_321 , & V_143 ) ;
F_108 ( V_321 , V_67 , V_67 -> V_251 , & V_143 ) ;
fclose ( V_320 ) ;
fclose ( V_321 ) ;
return;
}
void F_79 ( struct V_58 * V_67 )
{
T_5 * V_321 , * V_320 ;
const char * V_369 ;
char line [ V_323 ] ;
char V_386 [ V_323 ] ;
int V_9 ;
if( V_67 -> V_254 ) V_369 = V_67 -> V_254 ;
else V_369 = L_68 ;
V_320 = F_97 ( V_67 , L_229 , L_140 ) ;
if( V_320 ) {
int V_387 ;
for( V_9 = 1 ; V_9 < V_67 -> V_73 && fgets ( line , V_323 , V_320 ) ; V_9 ++ ) {
F_3 ( V_386 , L_296 ,
V_369 , V_67 -> V_70 [ V_9 ] -> V_84 , V_9 ) ;
if( strcmp ( line , V_386 ) ) break;
}
V_387 = fgetc ( V_320 ) ;
fclose ( V_320 ) ;
if( V_9 == V_67 -> V_73 && V_387 == V_388 ) {
return;
}
}
V_321 = F_97 ( V_67 , L_229 , L_169 ) ;
if( V_321 ) {
for( V_9 = 1 ; V_9 < V_67 -> V_73 ; V_9 ++ ) {
fprintf ( V_321 , L_296 , V_369 , V_67 -> V_70 [ V_9 ] -> V_84 , V_9 ) ;
}
fclose ( V_321 ) ;
}
return;
}
void F_75 ( struct V_58 * V_67 )
{
struct V_42 * V_41 ;
struct V_22 * V_8 , * V_28 , * V_389 ;
struct V_43 * V_34 , * V_384 , * V_390 ;
int V_391 , V_53 ;
int V_9 ;
int V_392 ;
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
V_41 = V_67 -> V_111 [ V_9 ] ;
V_391 = 0 ;
V_390 = 0 ;
V_392 = 0 ;
for( V_8 = V_41 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_40 && V_8 -> V_29 == V_67 -> V_282 ) {
V_392 = 1 ;
}
if( V_8 -> type != V_31 ) continue;
V_34 = V_8 -> V_33 . V_34 ;
if( V_34 -> V_89 ) continue;
if( V_34 == V_390 ) continue;
V_53 = 1 ;
for( V_28 = V_8 -> V_26 ; V_28 ; V_28 = V_28 -> V_26 ) {
if( V_28 -> type != V_31 ) continue;
V_384 = V_28 -> V_33 . V_34 ;
if( V_384 == V_390 ) continue;
if( V_384 == V_34 ) V_53 ++ ;
}
if( V_53 > V_391 ) {
V_391 = V_53 ;
V_390 = V_34 ;
}
}
if( V_391 < 1 || V_392 ) continue;
for( V_8 = V_41 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_31 && V_8 -> V_33 . V_34 == V_390 ) break;
}
assert ( V_8 ) ;
V_8 -> V_29 = F_68 ( L_54 ) ;
for( V_8 = V_8 -> V_26 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_31 && V_8 -> V_33 . V_34 == V_390 ) V_8 -> type = V_312 ;
}
V_41 -> V_8 = F_8 ( V_41 -> V_8 ) ;
for( V_8 = V_41 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_40 ) break;
if( V_8 -> type == V_31 && V_8 -> V_33 . V_34 != V_390 ) break;
}
if( V_8 == 0 ) {
V_41 -> V_393 = 1 ;
V_41 -> V_394 = V_390 ;
}
}
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
V_41 = V_67 -> V_111 [ V_9 ] ;
for( V_8 = V_41 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
struct V_42 * V_395 ;
if( V_8 -> type != V_40 ) continue;
V_395 = V_8 -> V_33 . V_41 ;
if( V_395 -> V_393 && V_395 -> V_394 != 0 ) {
V_8 -> type = V_32 ;
V_8 -> V_33 . V_34 = V_395 -> V_394 ;
}
}
}
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
V_41 = V_67 -> V_111 [ V_9 ] ;
for( V_8 = V_41 -> V_8 ; V_8 ; V_8 = V_389 ) {
V_389 = V_8 -> V_26 ;
if( V_8 -> type != V_32 ) continue;
V_34 = V_8 -> V_33 . V_34 ;
if( V_34 -> V_231 == 0 ) continue;
if( V_34 -> V_61 != 1 ) continue;
#if 1
if( V_8 -> V_29 -> V_30 < V_67 -> V_73 ) continue;
#endif
V_389 = V_8 ;
for( V_28 = V_41 -> V_8 ; V_28 && ( V_28 == V_8 || V_28 -> V_29 != V_34 -> V_75 ) ; V_28 = V_28 -> V_26 ) {}
assert ( V_28 != 0 ) ;
V_8 -> V_39 = V_28 -> V_29 ;
V_8 -> type = V_28 -> type ;
V_8 -> V_33 = V_28 -> V_33 ;
}
}
}
static int F_121 ( const void * V_98 , const void * V_99 ) {
const struct V_42 * V_151 = * ( const struct V_42 * const * ) V_98 ;
const struct V_42 * V_152 = * ( const struct V_42 * const * ) V_99 ;
int V_53 ;
V_53 = V_152 -> V_372 - V_151 -> V_372 ;
if( V_53 == 0 ) {
V_53 = V_152 -> V_371 - V_151 -> V_371 ;
if( V_53 == 0 ) {
V_53 = V_152 -> V_96 - V_151 -> V_96 ;
}
}
assert ( V_53 != 0 ) ;
return V_53 ;
}
void F_76 ( struct V_58 * V_67 )
{
int V_9 ;
struct V_42 * V_41 ;
struct V_22 * V_8 ;
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
V_41 = V_67 -> V_111 [ V_9 ] ;
V_41 -> V_371 = V_41 -> V_372 = 0 ;
V_41 -> V_379 = V_67 -> V_182 ;
V_41 -> V_373 = V_377 ;
V_41 -> V_374 = V_377 ;
for( V_8 = V_41 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
int V_396 = F_104 ( V_67 , V_8 ) ;
if( V_396 >= 0 ) {
if( V_8 -> V_29 -> V_30 < V_67 -> V_73 ) {
V_41 -> V_371 ++ ;
} else if( V_8 -> V_29 -> V_30 < V_67 -> V_69 ) {
V_41 -> V_372 ++ ;
} else{
assert ( V_41 -> V_393 == 0 || V_41 -> V_394 == V_8 -> V_33 . V_34 ) ;
V_41 -> V_379 = V_396 - V_67 -> V_97 - V_67 -> V_182 ;
}
}
}
}
qsort ( & V_67 -> V_111 [ 1 ] , V_67 -> V_97 - 1 , sizeof( V_67 -> V_111 [ 0 ] ) ,
F_121 ) ;
for( V_9 = 0 ; V_9 < V_67 -> V_97 ; V_9 ++ ) {
V_67 -> V_111 [ V_9 ] -> V_96 = V_9 ;
}
V_67 -> V_185 = V_67 -> V_97 ;
while( V_67 -> V_185 > 1 && V_67 -> V_111 [ V_67 -> V_185 - 1 ] -> V_393 ) {
V_67 -> V_185 -- ;
}
}
void F_73 ( int V_53 )
{
V_397 = V_53 + 1 ;
}
char * F_17 ( void ) {
char * V_398 ;
V_398 = ( char * ) calloc ( V_397 , 1 ) ;
F_13 ( V_398 ) ;
return V_398 ;
}
void F_53 ( char * V_398 )
{
free ( V_398 ) ;
}
int F_18 ( char * V_398 , int V_399 )
{
int V_400 ;
assert ( V_399 >= 0 && V_399 < V_397 ) ;
V_400 = V_398 [ V_399 ] ;
V_398 [ V_399 ] = 1 ;
return ! V_400 ;
}
int F_19 ( char * V_78 , char * V_79 )
{
int V_9 , V_68 ;
V_68 = 0 ;
for( V_9 = 0 ; V_9 < V_397 ; V_9 ++ ) {
if( V_79 [ V_9 ] == 0 ) continue;
if( V_78 [ V_9 ] == 0 ) {
V_68 = 1 ;
V_78 [ V_9 ] = 1 ;
}
}
return V_68 ;
}
T_2 unsigned F_122 ( const char * V_33 )
{
unsigned V_401 = 0 ;
while( * V_33 ) V_401 = V_401 * 13 + * ( V_33 ++ ) ;
return V_401 ;
}
const char * F_92 ( const char * V_93 )
{
const char * V_14 ;
char * V_402 ;
if( V_93 == 0 ) return 0 ;
V_14 = F_123 ( V_93 ) ;
if( V_14 == 0 && ( V_402 = ( char * ) malloc ( F_57 ( V_93 ) + 1 ) ) != 0 ) {
F_4 ( V_402 , V_93 ) ;
V_14 = V_402 ;
F_124 ( V_14 ) ;
}
F_13 ( V_14 ) ;
return V_14 ;
}
void F_64 ( void ) {
if( V_403 ) return;
V_403 = (struct V_404 * ) malloc ( sizeof( struct V_404 ) ) ;
if( V_403 ) {
V_403 -> V_397 = 1024 ;
V_403 -> V_405 = 0 ;
V_403 -> V_406 = ( V_407 * ) calloc ( 1024 , sizeof( V_407 ) + sizeof( V_407 * ) ) ;
if( V_403 -> V_406 == 0 ) {
free ( V_403 ) ;
V_403 = 0 ;
} else{
int V_9 ;
V_403 -> V_408 = ( V_407 * * ) & ( V_403 -> V_406 [ 1024 ] ) ;
for( V_9 = 0 ; V_9 < 1024 ; V_9 ++ ) V_403 -> V_408 [ V_9 ] = 0 ;
}
}
}
int F_124 ( const char * V_409 )
{
V_407 * V_410 ;
unsigned V_401 ;
unsigned V_411 ;
if( V_403 == 0 ) return 0 ;
V_411 = F_122 ( V_409 ) ;
V_401 = V_411 & ( V_403 -> V_397 - 1 ) ;
V_410 = V_403 -> V_408 [ V_401 ] ;
while( V_410 ) {
if( strcmp ( V_410 -> V_409 , V_409 ) == 0 ) {
return 0 ;
}
V_410 = V_410 -> V_26 ;
}
if( V_403 -> V_405 >= V_403 -> V_397 ) {
int V_9 , V_412 ;
struct V_404 V_413 ;
V_413 . V_397 = V_412 = V_403 -> V_397 * 2 ;
V_413 . V_405 = V_403 -> V_405 ;
V_413 . V_406 = ( V_407 * ) calloc ( V_412 , sizeof( V_407 ) + sizeof( V_407 * ) ) ;
if( V_413 . V_406 == 0 ) return 0 ;
V_413 . V_408 = ( V_407 * * ) & ( V_413 . V_406 [ V_412 ] ) ;
for( V_9 = 0 ; V_9 < V_412 ; V_9 ++ ) V_413 . V_408 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_403 -> V_405 ; V_9 ++ ) {
V_407 * V_414 , * V_415 ;
V_414 = & ( V_403 -> V_406 [ V_9 ] ) ;
V_401 = F_122 ( V_414 -> V_409 ) & ( V_412 - 1 ) ;
V_415 = & ( V_413 . V_406 [ V_9 ] ) ;
if( V_413 . V_408 [ V_401 ] ) V_413 . V_408 [ V_401 ] -> V_301 = & ( V_415 -> V_26 ) ;
V_415 -> V_26 = V_413 . V_408 [ V_401 ] ;
V_415 -> V_409 = V_414 -> V_409 ;
V_415 -> V_301 = & ( V_413 . V_408 [ V_401 ] ) ;
V_413 . V_408 [ V_401 ] = V_415 ;
}
free ( V_403 -> V_406 ) ;
* V_403 = V_413 ;
}
V_401 = V_411 & ( V_403 -> V_397 - 1 ) ;
V_410 = & ( V_403 -> V_406 [ V_403 -> V_405 ++ ] ) ;
V_410 -> V_409 = V_409 ;
if( V_403 -> V_408 [ V_401 ] ) V_403 -> V_408 [ V_401 ] -> V_301 = & ( V_410 -> V_26 ) ;
V_410 -> V_26 = V_403 -> V_408 [ V_401 ] ;
V_403 -> V_408 [ V_401 ] = V_410 ;
V_410 -> V_301 = & ( V_403 -> V_408 [ V_401 ] ) ;
return 1 ;
}
const char * F_123 ( const char * V_416 )
{
unsigned V_401 ;
V_407 * V_410 ;
if( V_403 == 0 ) return 0 ;
V_401 = F_122 ( V_416 ) & ( V_403 -> V_397 - 1 ) ;
V_410 = V_403 -> V_408 [ V_401 ] ;
while( V_410 ) {
if( strcmp ( V_410 -> V_409 , V_416 ) == 0 ) break;
V_410 = V_410 -> V_26 ;
}
return V_410 ? V_410 -> V_409 : 0 ;
}
struct V_37 * F_68 ( const char * V_33 )
{
struct V_37 * V_29 ;
V_29 = F_22 ( V_33 ) ;
if( V_29 == 0 ) {
V_29 = (struct V_37 * ) calloc ( 1 , sizeof( struct V_37 ) ) ;
F_13 ( V_29 ) ;
V_29 -> V_84 = F_92 ( V_33 ) ;
V_29 -> type = ISUPPER ( * V_33 ) ? V_80 : V_76 ;
V_29 -> V_43 = 0 ;
V_29 -> V_265 = 0 ;
V_29 -> V_66 = - 1 ;
V_29 -> V_127 = V_417 ;
V_29 -> V_74 = 0 ;
V_29 -> V_71 = V_72 ;
V_29 -> V_270 = 0 ;
V_29 -> V_271 = 0 ;
V_29 -> V_272 = 0 ;
V_29 -> V_180 = 0 ;
F_125 ( V_29 , V_29 -> V_84 ) ;
}
V_29 -> V_180 ++ ;
return V_29 ;
}
int V_183 ( const void * V_418 , const void * V_419 )
{
const struct V_37 * V_98 = * ( const struct V_37 * const * ) V_418 ;
const struct V_37 * V_99 = * ( const struct V_37 * const * ) V_419 ;
int V_420 = V_98 -> type == V_63 ? 3 : V_98 -> V_84 [ 0 ] > 'Z' ? 2 : 1 ;
int V_421 = V_99 -> type == V_63 ? 3 : V_99 -> V_84 [ 0 ] > 'Z' ? 2 : 1 ;
return V_420 == V_421 ? V_98 -> V_30 - V_99 -> V_30 : V_420 - V_421 ;
}
void F_65 ( void ) {
if( V_422 ) return;
V_422 = (struct V_423 * ) malloc ( sizeof( struct V_423 ) ) ;
if( V_422 ) {
V_422 -> V_397 = 128 ;
V_422 -> V_405 = 0 ;
V_422 -> V_406 = ( V_424 * ) calloc ( 128 , sizeof( V_424 ) + sizeof( V_424 * ) ) ;
if( V_422 -> V_406 == 0 ) {
free ( V_422 ) ;
V_422 = 0 ;
} else{
int V_9 ;
V_422 -> V_408 = ( V_424 * * ) & ( V_422 -> V_406 [ 128 ] ) ;
for( V_9 = 0 ; V_9 < 128 ; V_9 ++ ) V_422 -> V_408 [ V_9 ] = 0 ;
}
}
}
int F_125 ( struct V_37 * V_409 , const char * V_416 )
{
V_424 * V_410 ;
unsigned V_401 ;
unsigned V_411 ;
if( V_422 == 0 ) return 0 ;
V_411 = F_122 ( V_416 ) ;
V_401 = V_411 & ( V_422 -> V_397 - 1 ) ;
V_410 = V_422 -> V_408 [ V_401 ] ;
while( V_410 ) {
if( strcmp ( V_410 -> V_416 , V_416 ) == 0 ) {
return 0 ;
}
V_410 = V_410 -> V_26 ;
}
if( V_422 -> V_405 >= V_422 -> V_397 ) {
int V_9 , V_412 ;
struct V_423 V_413 ;
V_413 . V_397 = V_412 = V_422 -> V_397 * 2 ;
V_413 . V_405 = V_422 -> V_405 ;
V_413 . V_406 = ( V_424 * ) calloc ( V_412 , sizeof( V_424 ) + sizeof( V_424 * ) ) ;
if( V_413 . V_406 == 0 ) return 0 ;
V_413 . V_408 = ( V_424 * * ) & ( V_413 . V_406 [ V_412 ] ) ;
for( V_9 = 0 ; V_9 < V_412 ; V_9 ++ ) V_413 . V_408 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_422 -> V_405 ; V_9 ++ ) {
V_424 * V_414 , * V_415 ;
V_414 = & ( V_422 -> V_406 [ V_9 ] ) ;
V_401 = F_122 ( V_414 -> V_416 ) & ( V_412 - 1 ) ;
V_415 = & ( V_413 . V_406 [ V_9 ] ) ;
if( V_413 . V_408 [ V_401 ] ) V_413 . V_408 [ V_401 ] -> V_301 = & ( V_415 -> V_26 ) ;
V_415 -> V_26 = V_413 . V_408 [ V_401 ] ;
V_415 -> V_416 = V_414 -> V_416 ;
V_415 -> V_409 = V_414 -> V_409 ;
V_415 -> V_301 = & ( V_413 . V_408 [ V_401 ] ) ;
V_413 . V_408 [ V_401 ] = V_415 ;
}
free ( V_422 -> V_406 ) ;
* V_422 = V_413 ;
}
V_401 = V_411 & ( V_422 -> V_397 - 1 ) ;
V_410 = & ( V_422 -> V_406 [ V_422 -> V_405 ++ ] ) ;
V_410 -> V_416 = V_416 ;
V_410 -> V_409 = V_409 ;
if( V_422 -> V_408 [ V_401 ] ) V_422 -> V_408 [ V_401 ] -> V_301 = & ( V_410 -> V_26 ) ;
V_410 -> V_26 = V_422 -> V_408 [ V_401 ] ;
V_422 -> V_408 [ V_401 ] = V_410 ;
V_410 -> V_301 = & ( V_422 -> V_408 [ V_401 ] ) ;
return 1 ;
}
struct V_37 * F_22 ( const char * V_416 )
{
unsigned V_401 ;
V_424 * V_410 ;
if( V_422 == 0 ) return 0 ;
V_401 = F_122 ( V_416 ) & ( V_422 -> V_397 - 1 ) ;
V_410 = V_422 -> V_408 [ V_401 ] ;
while( V_410 ) {
if( strcmp ( V_410 -> V_416 , V_416 ) == 0 ) break;
V_410 = V_410 -> V_26 ;
}
return V_410 ? V_410 -> V_409 : 0 ;
}
struct V_37 * F_126 ( int V_53 )
{
struct V_37 * V_409 ;
if( V_422 && V_53 > 0 && V_53 <= V_422 -> V_405 ) {
V_409 = V_422 -> V_406 [ V_53 - 1 ] . V_409 ;
} else{
V_409 = 0 ;
}
return V_409 ;
}
int F_70 ( void )
{
return V_422 ? V_422 -> V_405 : 0 ;
}
struct V_37 * * F_71 ( void )
{
struct V_37 * * V_413 ;
int V_9 , V_412 ;
if( V_422 == 0 ) return 0 ;
V_412 = V_422 -> V_405 ;
V_413 = (struct V_37 * * ) calloc ( V_412 , sizeof( struct V_37 * ) ) ;
if( V_413 ) {
for( V_9 = 0 ; V_9 < V_412 ; V_9 ++ ) V_413 [ V_9 ] = V_422 -> V_406 [ V_9 ] . V_409 ;
}
return V_413 ;
}
int V_141 ( const char * V_418 , const char * V_419 )
{
const struct V_87 * V_98 = ( const struct V_87 * ) V_418 ;
const struct V_87 * V_99 = ( const struct V_87 * ) V_419 ;
int V_33 ;
V_33 = V_98 -> V_34 -> V_30 - V_99 -> V_34 -> V_30 ;
if( V_33 == 0 ) V_33 = V_98 -> V_107 - V_99 -> V_107 ;
return V_33 ;
}
T_2 int F_127 ( struct V_87 * V_98 , struct V_87 * V_99 )
{
int V_19 ;
for( V_19 = 0 ; V_19 == 0 && V_98 && V_99 ; V_98 = V_98 -> V_92 , V_99 = V_99 -> V_92 ) {
V_19 = V_98 -> V_34 -> V_30 - V_99 -> V_34 -> V_30 ;
if( V_19 == 0 ) V_19 = V_98 -> V_107 - V_99 -> V_107 ;
}
if( V_19 == 0 ) {
if( V_98 ) V_19 = 1 ;
if( V_99 ) V_19 = - 1 ;
}
return V_19 ;
}
T_2 unsigned F_128 ( struct V_87 * V_98 )
{
unsigned V_401 = 0 ;
while( V_98 ) {
V_401 = V_401 * 571 + V_98 -> V_34 -> V_30 * 37 + V_98 -> V_107 ;
V_98 = V_98 -> V_92 ;
}
return V_401 ;
}
struct V_42 * F_35 ( void )
{
struct V_42 * V_425 ;
V_425 = (struct V_42 * ) calloc ( 1 , sizeof( struct V_42 ) ) ;
F_13 ( V_425 ) ;
return V_425 ;
}
void F_66 ( void ) {
if( V_426 ) return;
V_426 = (struct V_427 * ) malloc ( sizeof( struct V_427 ) ) ;
if( V_426 ) {
V_426 -> V_397 = 128 ;
V_426 -> V_405 = 0 ;
V_426 -> V_406 = ( V_428 * ) calloc ( 128 , sizeof( V_428 ) + sizeof( V_428 * ) ) ;
if( V_426 -> V_406 == 0 ) {
free ( V_426 ) ;
V_426 = 0 ;
} else{
int V_9 ;
V_426 -> V_408 = ( V_428 * * ) & ( V_426 -> V_406 [ 128 ] ) ;
for( V_9 = 0 ; V_9 < 128 ; V_9 ++ ) V_426 -> V_408 [ V_9 ] = 0 ;
}
}
}
int F_36 ( struct V_42 * V_409 , struct V_87 * V_416 )
{
V_428 * V_410 ;
unsigned V_401 ;
unsigned V_411 ;
if( V_426 == 0 ) return 0 ;
V_411 = F_128 ( V_416 ) ;
V_401 = V_411 & ( V_426 -> V_397 - 1 ) ;
V_410 = V_426 -> V_408 [ V_401 ] ;
while( V_410 ) {
if( F_127 ( V_410 -> V_416 , V_416 ) == 0 ) {
return 0 ;
}
V_410 = V_410 -> V_26 ;
}
if( V_426 -> V_405 >= V_426 -> V_397 ) {
int V_9 , V_412 ;
struct V_427 V_413 ;
V_413 . V_397 = V_412 = V_426 -> V_397 * 2 ;
V_413 . V_405 = V_426 -> V_405 ;
V_413 . V_406 = ( V_428 * ) calloc ( V_412 , sizeof( V_428 ) + sizeof( V_428 * ) ) ;
if( V_413 . V_406 == 0 ) return 0 ;
V_413 . V_408 = ( V_428 * * ) & ( V_413 . V_406 [ V_412 ] ) ;
for( V_9 = 0 ; V_9 < V_412 ; V_9 ++ ) V_413 . V_408 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_426 -> V_405 ; V_9 ++ ) {
V_428 * V_414 , * V_415 ;
V_414 = & ( V_426 -> V_406 [ V_9 ] ) ;
V_401 = F_128 ( V_414 -> V_416 ) & ( V_412 - 1 ) ;
V_415 = & ( V_413 . V_406 [ V_9 ] ) ;
if( V_413 . V_408 [ V_401 ] ) V_413 . V_408 [ V_401 ] -> V_301 = & ( V_415 -> V_26 ) ;
V_415 -> V_26 = V_413 . V_408 [ V_401 ] ;
V_415 -> V_416 = V_414 -> V_416 ;
V_415 -> V_409 = V_414 -> V_409 ;
V_415 -> V_301 = & ( V_413 . V_408 [ V_401 ] ) ;
V_413 . V_408 [ V_401 ] = V_415 ;
}
free ( V_426 -> V_406 ) ;
* V_426 = V_413 ;
}
V_401 = V_411 & ( V_426 -> V_397 - 1 ) ;
V_410 = & ( V_426 -> V_406 [ V_426 -> V_405 ++ ] ) ;
V_410 -> V_416 = V_416 ;
V_410 -> V_409 = V_409 ;
if( V_426 -> V_408 [ V_401 ] ) V_426 -> V_408 [ V_401 ] -> V_301 = & ( V_410 -> V_26 ) ;
V_410 -> V_26 = V_426 -> V_408 [ V_401 ] ;
V_426 -> V_408 [ V_401 ] = V_410 ;
V_410 -> V_301 = & ( V_426 -> V_408 [ V_401 ] ) ;
return 1 ;
}
struct V_42 * F_28 ( struct V_87 * V_416 )
{
unsigned V_401 ;
V_428 * V_410 ;
if( V_426 == 0 ) return 0 ;
V_401 = F_128 ( V_416 ) & ( V_426 -> V_397 - 1 ) ;
V_410 = V_426 -> V_408 [ V_401 ] ;
while( V_410 ) {
if( F_127 ( V_410 -> V_416 , V_416 ) == 0 ) break;
V_410 = V_410 -> V_26 ;
}
return V_410 ? V_410 -> V_409 : 0 ;
}
struct V_42 * * F_74 ( void )
{
struct V_42 * * V_413 ;
int V_9 , V_412 ;
if( V_426 == 0 ) return 0 ;
V_412 = V_426 -> V_405 ;
V_413 = (struct V_42 * * ) calloc ( V_412 , sizeof( struct V_42 * ) ) ;
if( V_413 ) {
for( V_9 = 0 ; V_9 < V_412 ; V_9 ++ ) V_413 [ V_9 ] = V_426 -> V_406 [ V_9 ] . V_409 ;
}
return V_413 ;
}
T_2 unsigned F_129 ( struct V_87 * V_98 )
{
unsigned V_401 = 0 ;
V_401 = V_401 * 571 + V_98 -> V_34 -> V_30 * 37 + V_98 -> V_107 ;
return V_401 ;
}
void F_48 ( void ) {
if( V_429 ) return;
V_429 = (struct V_430 * ) malloc ( sizeof( struct V_430 ) ) ;
if( V_429 ) {
V_429 -> V_397 = 64 ;
V_429 -> V_405 = 0 ;
V_429 -> V_406 = ( V_431 * ) calloc ( 64 , sizeof( V_431 ) + sizeof( V_431 * ) ) ;
if( V_429 -> V_406 == 0 ) {
free ( V_429 ) ;
V_429 = 0 ;
} else{
int V_9 ;
V_429 -> V_408 = ( V_431 * * ) & ( V_429 -> V_406 [ 64 ] ) ;
for( V_9 = 0 ; V_9 < 64 ; V_9 ++ ) V_429 -> V_408 [ V_9 ] = 0 ;
}
}
}
int F_52 ( struct V_87 * V_409 )
{
V_431 * V_410 ;
unsigned V_401 ;
unsigned V_411 ;
if( V_429 == 0 ) return 0 ;
V_411 = F_129 ( V_409 ) ;
V_401 = V_411 & ( V_429 -> V_397 - 1 ) ;
V_410 = V_429 -> V_408 [ V_401 ] ;
while( V_410 ) {
if( V_141 ( ( const char * ) V_410 -> V_409 , ( const char * ) V_409 ) == 0 ) {
return 0 ;
}
V_410 = V_410 -> V_26 ;
}
if( V_429 -> V_405 >= V_429 -> V_397 ) {
int V_9 , V_412 ;
struct V_430 V_413 ;
V_413 . V_397 = V_412 = V_429 -> V_397 * 2 ;
V_413 . V_405 = V_429 -> V_405 ;
V_413 . V_406 = ( V_431 * ) calloc ( V_412 , sizeof( V_431 ) + sizeof( V_431 * ) ) ;
if( V_413 . V_406 == 0 ) return 0 ;
V_413 . V_408 = ( V_431 * * ) & ( V_413 . V_406 [ V_412 ] ) ;
for( V_9 = 0 ; V_9 < V_412 ; V_9 ++ ) V_413 . V_408 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_429 -> V_405 ; V_9 ++ ) {
V_431 * V_414 , * V_415 ;
V_414 = & ( V_429 -> V_406 [ V_9 ] ) ;
V_401 = F_129 ( V_414 -> V_409 ) & ( V_412 - 1 ) ;
V_415 = & ( V_413 . V_406 [ V_9 ] ) ;
if( V_413 . V_408 [ V_401 ] ) V_413 . V_408 [ V_401 ] -> V_301 = & ( V_415 -> V_26 ) ;
V_415 -> V_26 = V_413 . V_408 [ V_401 ] ;
V_415 -> V_409 = V_414 -> V_409 ;
V_415 -> V_301 = & ( V_413 . V_408 [ V_401 ] ) ;
V_413 . V_408 [ V_401 ] = V_415 ;
}
free ( V_429 -> V_406 ) ;
* V_429 = V_413 ;
}
V_401 = V_411 & ( V_429 -> V_397 - 1 ) ;
V_410 = & ( V_429 -> V_406 [ V_429 -> V_405 ++ ] ) ;
V_410 -> V_409 = V_409 ;
if( V_429 -> V_408 [ V_401 ] ) V_429 -> V_408 [ V_401 ] -> V_301 = & ( V_410 -> V_26 ) ;
V_410 -> V_26 = V_429 -> V_408 [ V_401 ] ;
V_429 -> V_408 [ V_401 ] = V_410 ;
V_410 -> V_301 = & ( V_429 -> V_408 [ V_401 ] ) ;
return 1 ;
}
struct V_87 * F_51 ( struct V_87 * V_416 )
{
int V_401 ;
V_431 * V_410 ;
if( V_429 == 0 ) return 0 ;
V_401 = F_129 ( V_416 ) & ( V_429 -> V_397 - 1 ) ;
V_410 = V_429 -> V_408 [ V_401 ] ;
while( V_410 ) {
if( V_141 ( ( const char * ) V_410 -> V_409 , ( const char * ) V_416 ) == 0 ) break;
V_410 = V_410 -> V_26 ;
}
return V_410 ? V_410 -> V_409 : 0 ;
}
void F_49 ( int (* F_130)( struct V_87 * ) )
{
int V_9 ;
if( V_429 == 0 || V_429 -> V_405 == 0 ) return;
if( F_130 ) for( V_9 = 0 ; V_9 < V_429 -> V_405 ; V_9 ++ ) (* F_130)( V_429 -> V_406 [ V_9 ] . V_409 ) ;
for( V_9 = 0 ; V_9 < V_429 -> V_397 ; V_9 ++ ) V_429 -> V_408 [ V_9 ] = 0 ;
V_429 -> V_405 = 0 ;
return;
}
