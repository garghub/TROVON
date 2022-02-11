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
if( type == V_39 ) {
V_24 -> V_33 . V_40 = (struct V_41 * ) V_38 ;
} else{
V_24 -> V_33 . V_34 = (struct V_42 * ) V_38 ;
}
}
T_2 T_3 * F_11 ( void ) {
T_3 * V_43 = ( T_3 * ) calloc ( 1 , sizeof( * V_43 ) ) ;
if( V_43 == 0 ) {
fprintf ( V_17 , L_7 ) ;
exit ( 1 ) ;
}
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
return V_43 ;
}
T_2 void F_12 ( T_3 * V_43 , int V_44 , int V_22 ) {
if( V_43 -> V_45 >= V_43 -> V_46 ) {
V_43 -> V_46 += 25 ;
V_43 -> V_47 = (struct V_48 * ) realloc ( V_43 -> V_47 ,
sizeof( V_43 -> V_47 [ 0 ] ) * V_43 -> V_46 ) ;
if( V_43 -> V_47 == 0 ) {
fprintf ( V_17 , L_8 ) ;
exit ( 1 ) ;
}
}
if( V_43 -> V_45 == 0 ) {
V_43 -> V_49 = V_44 ;
V_43 -> V_50 = V_44 ;
V_43 -> V_51 = V_22 ;
} else{
if( V_43 -> V_49 < V_44 ) V_43 -> V_49 = V_44 ;
if( V_43 -> V_50 > V_44 ) {
V_43 -> V_50 = V_44 ;
V_43 -> V_51 = V_22 ;
}
}
V_43 -> V_47 [ V_43 -> V_45 ] . V_44 = V_44 ;
V_43 -> V_47 [ V_43 -> V_45 ] . V_22 = V_22 ;
V_43 -> V_45 ++ ;
}
T_2 int F_13 ( T_3 * V_43 ) {
int V_9 , V_10 , V_11 , V_52 ;
assert ( V_43 -> V_45 > 0 ) ;
V_52 = V_43 -> V_49 + 1 ;
if( V_43 -> V_53 + V_52 >= V_43 -> V_54 ) {
int V_55 = V_43 -> V_54 ;
V_43 -> V_54 = V_43 -> V_53 + V_52 + V_43 -> V_54 + 20 ;
V_43 -> V_56 = (struct V_48 * ) realloc ( V_43 -> V_56 ,
sizeof( V_43 -> V_56 [ 0 ] ) * V_43 -> V_54 ) ;
if( V_43 -> V_56 == 0 ) {
fprintf ( V_17 , L_8 ) ;
exit ( 1 ) ;
}
for( V_9 = V_55 ; V_9 < V_43 -> V_54 ; V_9 ++ ) {
V_43 -> V_56 [ V_9 ] . V_44 = - 1 ;
V_43 -> V_56 [ V_9 ] . V_22 = - 1 ;
}
}
for( V_9 = V_43 -> V_53 - 1 ; V_9 >= 0 ; V_9 -- ) {
if( V_43 -> V_56 [ V_9 ] . V_44 == V_43 -> V_50 ) {
if( V_43 -> V_56 [ V_9 ] . V_22 != V_43 -> V_51 ) continue;
for( V_10 = 0 ; V_10 < V_43 -> V_45 ; V_10 ++ ) {
V_11 = V_43 -> V_47 [ V_10 ] . V_44 - V_43 -> V_50 + V_9 ;
if( V_11 < 0 || V_11 >= V_43 -> V_53 ) break;
if( V_43 -> V_47 [ V_10 ] . V_44 != V_43 -> V_56 [ V_11 ] . V_44 ) break;
if( V_43 -> V_47 [ V_10 ] . V_22 != V_43 -> V_56 [ V_11 ] . V_22 ) break;
}
if( V_10 < V_43 -> V_45 ) continue;
V_52 = 0 ;
for( V_10 = 0 ; V_10 < V_43 -> V_53 ; V_10 ++ ) {
if( V_43 -> V_56 [ V_10 ] . V_44 < 0 ) continue;
if( V_43 -> V_56 [ V_10 ] . V_44 == V_10 + V_43 -> V_50 - V_9 ) V_52 ++ ;
}
if( V_52 == V_43 -> V_45 ) {
break;
}
}
}
if( V_9 < 0 ) {
for( V_9 = 0 ; V_9 < V_43 -> V_54 - V_43 -> V_49 ; V_9 ++ ) {
if( V_43 -> V_56 [ V_9 ] . V_44 < 0 ) {
for( V_10 = 0 ; V_10 < V_43 -> V_45 ; V_10 ++ ) {
V_11 = V_43 -> V_47 [ V_10 ] . V_44 - V_43 -> V_50 + V_9 ;
if( V_11 < 0 ) break;
if( V_43 -> V_56 [ V_11 ] . V_44 >= 0 ) break;
}
if( V_10 < V_43 -> V_45 ) continue;
for( V_10 = 0 ; V_10 < V_43 -> V_53 ; V_10 ++ ) {
if( V_43 -> V_56 [ V_10 ] . V_44 == V_10 + V_43 -> V_50 - V_9 ) break;
}
if( V_10 == V_43 -> V_53 ) {
break;
}
}
}
}
for( V_10 = 0 ; V_10 < V_43 -> V_45 ; V_10 ++ ) {
V_11 = V_43 -> V_47 [ V_10 ] . V_44 - V_43 -> V_50 + V_9 ;
V_43 -> V_56 [ V_11 ] = V_43 -> V_47 [ V_10 ] ;
if( V_11 >= V_43 -> V_53 ) V_43 -> V_53 = V_11 + 1 ;
}
V_43 -> V_45 = 0 ;
return V_9 - V_43 -> V_50 ;
}
void F_14 ( struct V_57 * V_58 )
{
struct V_42 * V_34 ;
for( V_34 = V_58 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 ) {
if( V_34 -> V_59 == 0 ) {
int V_9 , V_10 ;
for( V_9 = 0 ; V_9 < V_34 -> V_60 && V_34 -> V_59 == 0 ; V_9 ++ ) {
struct V_37 * V_29 = V_34 -> V_61 [ V_9 ] ;
if( V_29 -> type == V_62 ) {
for( V_10 = 0 ; V_10 < V_29 -> V_63 ; V_10 ++ ) {
if( V_29 -> V_64 [ V_10 ] -> V_65 >= 0 ) {
V_34 -> V_59 = V_29 -> V_64 [ V_10 ] ;
break;
}
}
} else if( V_29 -> V_65 >= 0 ) {
V_34 -> V_59 = V_34 -> V_61 [ V_9 ] ;
}
}
}
}
return;
}
void F_15 ( struct V_57 * V_66 )
{
int V_9 , V_10 ;
struct V_42 * V_34 ;
int V_67 ;
for( V_9 = 0 ; V_9 < V_66 -> V_68 ; V_9 ++ ) {
V_66 -> V_69 [ V_9 ] -> V_70 = V_71 ;
}
for( V_9 = V_66 -> V_72 ; V_9 < V_66 -> V_68 ; V_9 ++ ) {
V_66 -> V_69 [ V_9 ] -> V_73 = F_16 () ;
}
do{
V_67 = 0 ;
for( V_34 = V_66 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 ) {
if( V_34 -> V_74 -> V_70 ) continue;
for( V_9 = 0 ; V_9 < V_34 -> V_60 ; V_9 ++ ) {
struct V_37 * V_29 = V_34 -> V_61 [ V_9 ] ;
assert ( V_29 -> type == V_75 || V_29 -> V_70 == V_71 ) ;
if( V_29 -> V_70 == V_71 ) break;
}
if( V_9 == V_34 -> V_60 ) {
V_34 -> V_74 -> V_70 = V_76 ;
V_67 = 1 ;
}
}
}while( V_67 );
do{
struct V_37 * V_77 , * V_78 ;
V_67 = 0 ;
for( V_34 = V_66 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 ) {
V_77 = V_34 -> V_74 ;
for( V_9 = 0 ; V_9 < V_34 -> V_60 ; V_9 ++ ) {
V_78 = V_34 -> V_61 [ V_9 ] ;
if( V_78 -> type == V_79 ) {
V_67 += F_17 ( V_77 -> V_73 , V_78 -> V_30 ) ;
break;
} else if( V_78 -> type == V_62 ) {
for( V_10 = 0 ; V_10 < V_78 -> V_63 ; V_10 ++ ) {
V_67 += F_17 ( V_77 -> V_73 , V_78 -> V_64 [ V_10 ] -> V_30 ) ;
}
break;
} else if( V_77 == V_78 ) {
if( V_77 -> V_70 == V_71 ) break;
} else{
V_67 += F_18 ( V_77 -> V_73 , V_78 -> V_73 ) ;
if( V_78 -> V_70 == V_71 ) break;
}
}
}
}while( V_67 );
return;
}
void F_19 ( struct V_57 * V_66 )
{
struct V_37 * V_29 ;
struct V_42 * V_34 ;
F_20 () ;
if( V_66 -> V_80 ) {
V_29 = F_21 ( V_66 -> V_80 ) ;
if( V_29 == 0 ) {
F_22 ( V_66 -> V_81 , 0 ,
L_9 , V_66 -> V_80 , V_66 -> V_42 -> V_74 -> V_82 ) ;
V_66 -> V_83 ++ ;
V_29 = V_66 -> V_42 -> V_74 ;
}
} else{
V_29 = V_66 -> V_42 -> V_74 ;
}
for( V_34 = V_66 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 ) {
int V_9 ;
for( V_9 = 0 ; V_9 < V_34 -> V_60 ; V_9 ++ ) {
if( V_34 -> V_61 [ V_9 ] == V_29 ) {
F_22 ( V_66 -> V_81 , 0 ,
L_10 , V_29 -> V_82 ) ;
V_66 -> V_83 ++ ;
}
}
}
for( V_34 = V_29 -> V_42 ; V_34 ; V_34 = V_34 -> V_84 ) {
struct V_85 * V_86 ;
V_34 -> V_87 = 1 ;
V_86 = F_23 ( V_34 , 0 ) ;
F_17 ( V_86 -> V_88 , 0 ) ;
}
( void ) F_24 ( V_66 ) ;
return;
}
T_2 struct V_41 * F_24 ( struct V_57 * V_66 )
{
struct V_85 * V_89 , * V_90 ;
struct V_41 * V_40 ;
F_25 () ;
V_90 = F_26 () ;
V_40 = F_27 ( V_90 ) ;
if( V_40 ) {
struct V_85 * V_33 , * V_91 ;
for( V_33 = V_90 , V_91 = V_40 -> V_90 ; V_33 && V_91 ; V_33 = V_33 -> V_90 , V_91 = V_91 -> V_90 ) {
F_28 ( & V_91 -> V_92 , V_33 -> V_92 ) ;
F_29 ( V_33 -> V_93 ) ;
V_33 -> V_93 = V_33 -> V_92 = 0 ;
}
V_89 = F_30 () ;
F_31 ( V_89 ) ;
} else{
F_32 ( V_66 ) ;
F_33 () ;
V_89 = F_30 () ;
V_40 = F_34 () ;
F_35 ( V_40 ) ;
V_40 -> V_90 = V_90 ;
V_40 -> V_89 = V_89 ;
V_40 -> V_94 = V_66 -> V_95 ++ ;
V_40 -> V_8 = 0 ;
F_36 ( V_40 , V_40 -> V_90 ) ;
F_37 ( V_66 , V_40 ) ;
}
return V_40 ;
}
T_2 int F_38 ( struct V_37 * V_96 , struct V_37 * V_97 )
{
int V_9 ;
if( V_96 == V_97 ) return 1 ;
if( V_96 -> type != V_62 ) return 0 ;
if( V_97 -> type != V_62 ) return 0 ;
if( V_96 -> V_63 != V_97 -> V_63 ) return 0 ;
for( V_9 = 0 ; V_9 < V_96 -> V_63 ; V_9 ++ ) {
if( V_96 -> V_64 [ V_9 ] != V_97 -> V_64 [ V_9 ] ) return 0 ;
}
return 1 ;
}
T_2 void F_37 ( struct V_57 * V_66 , struct V_41 * V_40 )
{
struct V_85 * V_89 ;
struct V_85 * V_98 ;
struct V_85 * V_99 ;
struct V_37 * V_29 ;
struct V_37 * V_100 ;
struct V_41 * V_101 ;
for( V_89 = V_40 -> V_89 ; V_89 ; V_89 = V_89 -> V_26 ) V_89 -> V_102 = V_103 ;
for( V_89 = V_40 -> V_89 ; V_89 ; V_89 = V_89 -> V_26 ) {
if( V_89 -> V_102 == V_104 ) continue;
if( V_89 -> V_105 >= V_89 -> V_34 -> V_60 ) continue;
F_39 () ;
V_29 = V_89 -> V_34 -> V_61 [ V_89 -> V_105 ] ;
for( V_98 = V_89 ; V_98 ; V_98 = V_98 -> V_26 ) {
if( V_98 -> V_102 == V_104 ) continue;
if( V_98 -> V_105 >= V_98 -> V_34 -> V_60 ) continue;
V_100 = V_98 -> V_34 -> V_61 [ V_98 -> V_105 ] ;
if( ! F_38 ( V_100 , V_29 ) ) continue;
V_98 -> V_102 = V_104 ;
V_99 = F_23 ( V_98 -> V_34 , V_98 -> V_105 + 1 ) ;
F_40 ( & V_99 -> V_92 , V_98 ) ;
}
V_101 = F_24 ( V_66 ) ;
if( V_29 -> type == V_62 ) {
int V_9 ;
for( V_9 = 0 ; V_9 < V_29 -> V_63 ; V_9 ++ ) {
F_10 ( & V_40 -> V_8 , V_39 , V_29 -> V_64 [ V_9 ] , ( char * ) V_101 ) ;
}
} else{
F_10 ( & V_40 -> V_8 , V_39 , V_29 , ( char * ) V_101 ) ;
}
}
}
void F_41 ( struct V_57 * V_66 )
{
int V_9 ;
struct V_85 * V_89 , * V_106 ;
struct V_41 * V_40 ;
struct V_107 * V_108 ;
for( V_9 = 0 ; V_9 < V_66 -> V_95 ; V_9 ++ ) {
V_40 = V_66 -> V_109 [ V_9 ] ;
if( V_40 ) {
for( V_89 = V_40 -> V_89 ; V_89 ; V_89 = V_89 -> V_26 ) {
V_89 -> V_40 = V_40 ;
}
}
}
for( V_9 = 0 ; V_9 < V_66 -> V_95 ; V_9 ++ ) {
V_40 = V_66 -> V_109 [ V_9 ] ;
if( V_40 ) {
for( V_89 = V_40 -> V_89 ; V_89 ; V_89 = V_89 -> V_26 ) {
for( V_108 = V_89 -> V_92 ; V_108 ; V_108 = V_108 -> V_26 ) {
V_106 = V_108 -> V_89 ;
F_40 ( & V_106 -> V_93 , V_89 ) ;
}
}
}
}
}
void F_42 ( struct V_57 * V_66 )
{
int V_9 ;
struct V_85 * V_89 ;
struct V_107 * V_108 ;
int V_67 ;
int V_110 ;
for( V_9 = 0 ; V_9 < V_66 -> V_95 ; V_9 ++ ) {
if( V_66 -> V_109 [ V_9 ] ) {
for( V_89 = V_66 -> V_109 [ V_9 ] -> V_89 ; V_89 ; V_89 = V_89 -> V_26 ) {
V_89 -> V_102 = V_103 ;
}
}
}
do{
V_67 = 0 ;
for( V_9 = 0 ; V_9 < V_66 -> V_95 ; V_9 ++ ) {
if( V_66 -> V_109 [ V_9 ] ) {
for( V_89 = V_66 -> V_109 [ V_9 ] -> V_89 ; V_89 ; V_89 = V_89 -> V_26 ) {
if( V_89 -> V_102 == V_104 ) continue;
for( V_108 = V_89 -> V_93 ; V_108 ; V_108 = V_108 -> V_26 ) {
V_110 = F_18 ( V_108 -> V_89 -> V_88 , V_89 -> V_88 ) ;
if( V_110 ) {
V_108 -> V_89 -> V_102 = V_103 ;
V_67 = 1 ;
}
}
V_89 -> V_102 = V_104 ;
}
}
}
}while( V_67 );
}
void F_43 ( struct V_57 * V_66 )
{
int V_9 , V_10 ;
struct V_85 * V_89 ;
struct V_41 * V_40 ;
struct V_37 * V_29 ;
struct V_42 * V_34 ;
for( V_9 = 0 ; V_9 < V_66 -> V_95 ; V_9 ++ ) {
V_40 = V_66 -> V_109 [ V_9 ] ;
if( V_40 ) {
for( V_89 = V_40 -> V_89 ; V_89 ; V_89 = V_89 -> V_26 ) {
if( V_89 -> V_34 -> V_60 == V_89 -> V_105 ) {
for( V_10 = 0 ; V_10 < V_66 -> V_72 ; V_10 ++ ) {
if( F_44 ( V_89 -> V_88 , V_10 ) ) {
F_10 ( & V_40 -> V_8 , V_31 , V_66 -> V_69 [ V_10 ] , ( char * ) V_89 -> V_34 ) ;
}
}
}
}
}
}
if( V_66 -> V_80 ) {
V_29 = F_21 ( V_66 -> V_80 ) ;
if( V_29 == 0 ) V_29 = V_66 -> V_42 -> V_74 ;
} else{
V_29 = V_66 -> V_42 -> V_74 ;
}
F_10 ( & V_66 -> V_109 [ 0 ] -> V_8 , V_111 , V_29 , 0 ) ;
for( V_9 = 0 ; V_9 < V_66 -> V_95 ; V_9 ++ ) {
struct V_22 * V_8 , * V_112 ;
V_40 = V_66 -> V_109 [ V_9 ] ;
V_40 -> V_8 = F_8 ( V_40 -> V_8 ) ;
for( V_8 = V_40 -> V_8 ; V_8 && V_8 -> V_26 ; V_8 = V_8 -> V_26 ) {
for( V_112 = V_8 -> V_26 ; V_112 && V_112 -> V_29 == V_8 -> V_29 ; V_112 = V_112 -> V_26 ) {
V_66 -> V_113 += F_45 ( V_8 , V_112 ) ;
}
}
}
for( V_34 = V_66 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 ) V_34 -> V_114 = V_71 ;
for( V_9 = 0 ; V_9 < V_66 -> V_95 ; V_9 ++ ) {
struct V_22 * V_8 ;
for( V_8 = V_66 -> V_109 [ V_9 ] -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_31 ) V_8 -> V_33 . V_34 -> V_114 = V_76 ;
}
}
for( V_34 = V_66 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 ) {
if( V_34 -> V_114 ) continue;
F_22 ( V_66 -> V_81 , V_34 -> V_115 , L_11 ) ;
V_66 -> V_83 ++ ;
}
}
static int F_45 (
struct V_22 * V_116 ,
struct V_22 * V_117
) {
struct V_37 * V_118 , * V_119 ;
int V_120 = 0 ;
assert ( V_116 -> V_29 == V_117 -> V_29 ) ;
if( V_116 -> type == V_39 && V_117 -> type == V_39 ) {
V_117 -> type = V_121 ;
V_120 ++ ;
}
if( V_116 -> type == V_39 && V_117 -> type == V_31 ) {
V_118 = V_116 -> V_29 ;
V_119 = V_117 -> V_33 . V_34 -> V_59 ;
if( V_119 == 0 || V_118 -> V_65 < 0 || V_119 -> V_65 < 0 ) {
V_117 -> type = V_122 ;
V_120 ++ ;
} else if( V_118 -> V_65 > V_119 -> V_65 ) {
V_117 -> type = V_123 ;
} else if( V_118 -> V_65 < V_119 -> V_65 ) {
V_116 -> type = V_124 ;
} else if( V_118 -> V_65 == V_119 -> V_65 && V_118 -> V_125 == V_126 ) {
V_117 -> type = V_123 ;
} else if( V_118 -> V_65 == V_119 -> V_65 && V_118 -> V_125 == V_127 ) {
V_116 -> type = V_124 ;
} else{
assert ( V_118 -> V_65 == V_119 -> V_65 && V_118 -> V_125 == V_128 ) ;
V_116 -> type = ERROR ;
}
} else if( V_116 -> type == V_31 && V_117 -> type == V_31 ) {
V_118 = V_116 -> V_33 . V_34 -> V_59 ;
V_119 = V_117 -> V_33 . V_34 -> V_59 ;
if( V_118 == 0 || V_119 == 0 || V_118 -> V_65 < 0 ||
V_119 -> V_65 < 0 || V_118 -> V_65 == V_119 -> V_65 ) {
V_117 -> type = V_129 ;
V_120 ++ ;
} else if( V_118 -> V_65 > V_119 -> V_65 ) {
V_117 -> type = V_123 ;
} else if( V_118 -> V_65 < V_119 -> V_65 ) {
V_116 -> type = V_123 ;
}
} else{
assert (
V_116 -> type == V_124 ||
V_116 -> type == V_123 ||
V_116 -> type == V_121 ||
V_116 -> type == V_122 ||
V_116 -> type == V_129 ||
V_117 -> type == V_124 ||
V_117 -> type == V_123 ||
V_117 -> type == V_121 ||
V_117 -> type == V_122 ||
V_117 -> type == V_129
) ;
}
return V_120 ;
}
T_2 struct V_85 * F_46 ( void ) {
struct V_85 * V_99 ;
if( V_23 == 0 ) {
int V_9 ;
int V_25 = 3 ;
V_23 = (struct V_85 * ) calloc ( V_25 , sizeof( struct V_85 ) ) ;
if( V_23 == 0 ) {
fprintf ( V_17 , L_12 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_25 - 1 ; V_9 ++ ) V_23 [ V_9 ] . V_26 = & V_23 [ V_9 + 1 ] ;
V_23 [ V_25 - 1 ] . V_26 = 0 ;
}
V_99 = V_23 ;
V_23 = V_23 -> V_26 ;
return V_99 ;
}
T_2 void F_47 ( struct V_85 * V_130 )
{
V_130 -> V_26 = V_23 ;
V_23 = V_130 ;
}
void F_20 ( void ) {
V_131 = 0 ;
V_132 = & V_131 ;
V_133 = 0 ;
V_134 = & V_133 ;
F_48 () ;
return;
}
void F_39 ( void ) {
V_131 = 0 ;
V_132 = & V_131 ;
V_133 = 0 ;
V_134 = & V_133 ;
F_49 ( 0 ) ;
return;
}
struct V_85 * F_50 (
struct V_42 * V_34 ,
int V_105
) {
struct V_85 * V_89 , V_135 ;
assert ( V_132 != 0 ) ;
V_135 . V_34 = V_34 ;
V_135 . V_105 = V_105 ;
V_89 = F_51 ( & V_135 ) ;
if( V_89 == 0 ) {
V_89 = F_46 () ;
V_89 -> V_34 = V_34 ;
V_89 -> V_105 = V_105 ;
V_89 -> V_88 = F_16 () ;
V_89 -> V_40 = 0 ;
V_89 -> V_93 = V_89 -> V_92 = 0 ;
V_89 -> V_26 = 0 ;
V_89 -> V_90 = 0 ;
* V_132 = V_89 ;
V_132 = & V_89 -> V_26 ;
F_52 ( V_89 ) ;
}
return V_89 ;
}
struct V_85 * F_23 ( struct V_42 * V_34 , int V_105 )
{
struct V_85 * V_89 , V_135 ;
assert ( V_134 != 0 ) ;
assert ( V_132 != 0 ) ;
V_135 . V_34 = V_34 ;
V_135 . V_105 = V_105 ;
V_89 = F_51 ( & V_135 ) ;
if( V_89 == 0 ) {
V_89 = F_46 () ;
V_89 -> V_34 = V_34 ;
V_89 -> V_105 = V_105 ;
V_89 -> V_88 = F_16 () ;
V_89 -> V_40 = 0 ;
V_89 -> V_93 = V_89 -> V_92 = 0 ;
V_89 -> V_26 = 0 ;
V_89 -> V_90 = 0 ;
* V_132 = V_89 ;
V_132 = & V_89 -> V_26 ;
* V_134 = V_89 ;
V_134 = & V_89 -> V_90 ;
F_52 ( V_89 ) ;
}
return V_89 ;
}
void F_32 ( struct V_57 * V_66 )
{
struct V_85 * V_89 , * V_86 ;
struct V_42 * V_34 , * V_136 ;
struct V_37 * V_29 , * V_137 ;
int V_9 , V_105 ;
assert ( V_132 != 0 ) ;
for( V_89 = V_131 ; V_89 ; V_89 = V_89 -> V_26 ) {
V_34 = V_89 -> V_34 ;
V_105 = V_89 -> V_105 ;
if( V_105 >= V_34 -> V_60 ) continue;
V_29 = V_34 -> V_61 [ V_105 ] ;
if( V_29 -> type == V_75 ) {
if( V_29 -> V_42 == 0 && V_29 != V_66 -> V_138 ) {
F_22 ( V_66 -> V_81 , V_34 -> line , L_13 ,
V_29 -> V_82 ) ;
V_66 -> V_83 ++ ;
}
for( V_136 = V_29 -> V_42 ; V_136 ; V_136 = V_136 -> V_84 ) {
V_86 = F_50 ( V_136 , 0 ) ;
for( V_9 = V_105 + 1 ; V_9 < V_34 -> V_60 ; V_9 ++ ) {
V_137 = V_34 -> V_61 [ V_9 ] ;
if( V_137 -> type == V_79 ) {
F_17 ( V_86 -> V_88 , V_137 -> V_30 ) ;
break;
} else if( V_137 -> type == V_62 ) {
int V_11 ;
for( V_11 = 0 ; V_11 < V_137 -> V_63 ; V_11 ++ ) {
F_17 ( V_86 -> V_88 , V_137 -> V_64 [ V_11 ] -> V_30 ) ;
}
break;
} else{
F_18 ( V_86 -> V_88 , V_137 -> V_73 ) ;
if( V_137 -> V_70 == V_71 ) break;
}
}
if( V_9 == V_34 -> V_60 ) F_40 ( & V_89 -> V_93 , V_86 ) ;
}
}
}
return;
}
void F_33 ( void ) {
V_131 = (struct V_85 * ) F_9 ( ( char * ) V_131 , ( char * * ) & ( V_131 -> V_26 ) ,
V_139 ) ;
V_132 = 0 ;
return;
}
void F_25 ( void ) {
V_133 = (struct V_85 * ) F_9 ( ( char * ) V_131 , ( char * * ) & ( V_131 -> V_90 ) ,
V_139 ) ;
V_134 = 0 ;
return;
}
struct V_85 * F_30 ( void ) {
struct V_85 * V_130 ;
V_130 = V_131 ;
V_131 = 0 ;
V_132 = 0 ;
return V_130 ;
}
struct V_85 * F_26 ( void ) {
struct V_85 * V_130 ;
V_130 = V_133 ;
V_133 = 0 ;
V_134 = 0 ;
return V_130 ;
}
void F_31 ( struct V_85 * V_89 )
{
struct V_85 * V_140 ;
for(; V_89 ; V_89 = V_140 ) {
V_140 = V_89 -> V_26 ;
assert ( V_89 -> V_93 == 0 ) ;
assert ( V_89 -> V_92 == 0 ) ;
if( V_89 -> V_88 ) F_53 ( V_89 -> V_88 ) ;
F_47 ( V_89 ) ;
}
return;
}
void F_22 ( const char * V_81 , int V_141 , const char * V_18 , ... ) {
T_1 V_8 ;
fprintf ( V_17 , L_14 , V_81 , V_141 ) ;
va_start ( V_8 , V_18 ) ;
vfprintf ( V_17 , V_18 , V_8 ) ;
va_end ( V_8 ) ;
fprintf ( V_17 , L_15 ) ;
}
void F_54 ( void ) {
fprintf ( V_17 , L_16 ) ;
exit ( 1 ) ;
}
T_2 char *
F_55 ( char * V_142 )
{
char * V_143 ;
char * V_144 ;
V_143 = strrchr ( V_142 , '/' ) ;
#ifdef F_56
if ( ! V_143 )
V_143 = strrchr ( V_142 , '\\' ) ;
#endif
if ( ! V_143 ) {
V_144 = ( char * ) malloc ( strlen ( V_142 ) + 1 ) ;
strcpy ( V_144 , V_142 ) ;
}
else {
V_143 ++ ;
V_144 = ( char * ) malloc ( strlen ( V_143 ) + 1 ) ;
strcpy ( V_144 , V_143 ) ;
}
return V_144 ;
}
static void F_57 ( void * V_38 ) {
char * V_14 = ( char * ) V_38 ;
char * * V_145 ;
V_146 ++ ;
V_147 = ( char * * ) realloc ( V_147 , sizeof( V_147 [ 0 ] ) * V_146 ) ;
if( V_147 == 0 ) {
fprintf ( V_17 , L_17 ) ;
exit ( 1 ) ;
}
V_145 = & V_147 [ V_146 - 1 ] ;
* V_145 = ( char * ) malloc ( F_58 ( V_14 ) + 1 ) ;
if( * V_145 == 0 ) {
fprintf ( V_17 , L_17 ) ;
exit ( 1 ) ;
}
F_4 ( * V_145 , V_14 ) ;
for( V_14 = * V_145 ; * V_14 && * V_14 != '=' ; V_14 ++ ) {}
* V_14 = 0 ;
}
static void F_59 ( void * V_38 ) {
char * V_14 = ( char * ) V_38 ;
V_148 = ( char * ) malloc ( F_58 ( V_14 ) + 1 ) ;
if( V_148 == 0 ) {
F_54 () ;
}
F_4 ( V_148 , V_14 ) ;
}
static void F_60 ( const char * V_149 , int V_150 ) {
int V_151 = F_58 ( V_149 ) ;
printf ( L_18 , V_149 ,
35 - V_151 , L_19 ,
V_150 ) ;
}
int main ( int T_4 V_152 , char * * V_153 )
{
static int V_154 = 0 ;
static int V_155 = 0 ;
static int V_156 = 0 ;
static int V_157 = 0 ;
static int V_158 = 0 ;
static int V_159 = 0 ;
static int V_160 = 0 ;
static int V_161 = 0 ;
static int V_162 = 0 ;
static struct V_163 V_164 [] = {
{ V_165 , L_20 , & V_156 , NULL , L_21 } ,
{ V_165 , L_22 , & V_157 , NULL , L_23 } ,
{ V_166 , L_24 , NULL , F_57 , L_25 } ,
{ V_166 , L_26 , & V_167 , NULL , L_27 } ,
{ V_165 , L_28 , & V_155 , NULL , L_29 } ,
{ V_166 , L_30 , & V_167 , NULL , L_31 } ,
{ V_165 , L_32 , & V_160 , NULL , L_33 } ,
{ V_165 , L_34 , & V_161 , NULL , L_35 } ,
{ V_166 , L_36 , & V_167 , NULL , L_37 } ,
{ V_165 , L_38 , & V_168 , NULL ,
L_39 } ,
{ V_165 , L_40 , & V_158 , NULL , L_41 } ,
{ V_165 , L_42 , & V_162 , NULL , L_43 } ,
{ V_165 , L_44 , & V_159 , NULL ,
L_45 } ,
{ V_165 , L_46 , & V_154 , NULL , L_47 } ,
{ V_166 , L_48 , NULL , F_59 , L_49 } ,
{ V_166 , L_50 , & V_167 , NULL , L_51 } ,
{ V_165 , NULL , NULL , NULL , NULL }
} ;
int V_9 ;
int V_169 ;
struct V_57 V_170 ;
F_61 ( V_153 , V_164 , V_17 ) ;
if( V_154 ) {
printf ( L_52 ) ;
exit ( 0 ) ;
}
if( F_62 () != 1 ) {
fprintf ( V_17 , L_53 ) ;
exit ( 1 ) ;
}
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
V_170 . V_83 = 0 ;
F_63 () ;
F_64 () ;
F_65 () ;
V_170 . V_171 = V_153 [ 0 ] ;
V_170 . V_81 = F_66 ( 0 ) ;
V_170 . V_156 = V_156 ;
V_170 . V_161 = V_161 ;
F_67 ( L_54 ) ;
V_170 . V_138 = F_67 ( L_55 ) ;
V_170 . V_138 -> V_172 = 0 ;
V_170 . V_173 = F_55 ( V_170 . V_81 ) ;
F_68 ( & V_170 ) ;
if( V_170 . V_83 ) exit ( V_170 . V_83 ) ;
if( V_170 . V_174 == 0 ) {
fprintf ( V_17 , L_56 ) ;
exit ( 1 ) ;
}
F_67 ( L_57 ) ;
V_170 . V_68 = F_69 () ;
V_170 . V_69 = F_70 () ;
for( V_9 = 0 ; V_9 < V_170 . V_68 ; V_9 ++ ) V_170 . V_69 [ V_9 ] -> V_30 = V_9 ;
qsort ( V_170 . V_69 , V_170 . V_68 , sizeof( struct V_37 * ) , V_175 ) ;
for( V_9 = 0 ; V_9 < V_170 . V_68 ; V_9 ++ ) V_170 . V_69 [ V_9 ] -> V_30 = V_9 ;
while( V_170 . V_69 [ V_9 - 1 ] -> type == V_62 ) { V_9 -- ; }
assert ( strcmp ( V_170 . V_69 [ V_9 - 1 ] -> V_82 , L_57 ) == 0 ) ;
V_170 . V_68 = V_9 - 1 ;
for( V_9 = 1 ; ISUPPER ( V_170 . V_69 [ V_9 ] -> V_82 [ 0 ] ) ; V_9 ++ ) ;
V_170 . V_72 = V_9 ;
if( V_155 ) {
F_71 ( & V_170 ) ;
} else{
F_72 ( V_170 . V_72 + 1 ) ;
F_14 ( & V_170 ) ;
F_15 ( & V_170 ) ;
V_170 . V_95 = 0 ;
F_19 ( & V_170 ) ;
V_170 . V_109 = F_73 () ;
F_41 ( & V_170 ) ;
F_42 ( & V_170 ) ;
F_43 ( & V_170 ) ;
if( V_157 == 0 ) F_74 ( & V_170 ) ;
if( V_162 == 0 ) F_75 ( & V_170 ) ;
if( ! V_158 ) F_76 ( & V_170 ) ;
F_77 ( & V_170 , V_160 ) ;
if( ! V_160 ) F_78 ( & V_170 ) ;
}
if( V_159 ) {
printf ( L_58 ) ;
F_60 ( L_59 , V_170 . V_72 ) ;
F_60 ( L_60 , V_170 . V_68 - V_170 . V_72 ) ;
F_60 ( L_61 , V_170 . V_68 ) ;
F_60 ( L_62 , V_170 . V_174 ) ;
F_60 ( L_63 , V_170 . V_176 ) ;
F_60 ( L_64 , V_170 . V_113 ) ;
F_60 ( L_65 , V_170 . V_177 ) ;
F_60 ( L_66 , V_170 . V_178 ) ;
}
if( V_170 . V_113 > 0 ) {
fprintf ( V_17 , L_67 , V_170 . V_113 ) ;
}
V_169 = ( ( V_170 . V_83 > 0 ) || ( V_170 . V_113 > 0 ) ) ? 1 : 0 ;
exit ( V_169 ) ;
return ( V_169 ) ;
}
static char * F_79 (
char * V_96 ,
char * V_97 ,
int (* F_80)( const char * , const char * ) ,
int V_179
) {
char * V_180 , * V_181 ;
if( V_96 == 0 ) {
V_181 = V_97 ;
} else if( V_97 == 0 ) {
V_181 = V_96 ;
} else{
if( (* F_80)( V_96 , V_97 ) <= 0 ) {
V_180 = V_96 ;
V_96 = F_81 ( V_96 ) ;
} else{
V_180 = V_97 ;
V_97 = F_81 ( V_97 ) ;
}
V_181 = V_180 ;
while( V_96 && V_97 ) {
if( (* F_80)( V_96 , V_97 ) <= 0 ) {
F_81 ( V_180 ) = V_96 ;
V_180 = V_96 ;
V_96 = F_81 ( V_96 ) ;
} else{
F_81 ( V_180 ) = V_97 ;
V_180 = V_97 ;
V_97 = F_81 ( V_97 ) ;
}
}
if( V_96 ) F_81 ( V_180 ) = V_96 ;
else F_81 ( V_180 ) = V_97 ;
}
return V_181 ;
}
T_2 char * F_9 (
char * V_182 ,
char * * V_26 ,
int (* F_80)( const char * , const char * )
) {
unsigned long V_179 ;
char * V_183 ;
char * V_184 [ V_185 ] ;
int V_9 ;
V_179 = ( unsigned long ) ( ( char * ) V_26 - ( char * ) V_182 ) ;
for( V_9 = 0 ; V_9 < V_185 ; V_9 ++ ) V_184 [ V_9 ] = 0 ;
while( V_182 ) {
V_183 = V_182 ;
V_182 = F_81 ( V_182 ) ;
F_81 ( V_183 ) = 0 ;
for( V_9 = 0 ; V_9 < V_185 - 1 && V_184 [ V_9 ] != 0 ; V_9 ++ ) {
V_183 = F_79 ( V_183 , V_184 [ V_9 ] , F_80 , ( int ) V_179 ) ;
V_184 [ V_9 ] = 0 ;
}
V_184 [ V_9 ] = V_183 ;
}
V_183 = 0 ;
for( V_9 = 0 ; V_9 < V_185 ; V_9 ++ ) if( V_184 [ V_9 ] ) V_183 = F_79 ( V_184 [ V_9 ] , V_183 , F_80 , ( int ) V_179 ) ;
return V_183 ;
}
static void F_82 ( int V_52 , int V_11 , T_5 * V_186 )
{
int V_187 , V_9 ;
if( V_153 [ 0 ] ) fprintf ( V_186 , L_68 , V_153 [ 0 ] ) ;
V_187 = F_58 ( V_153 [ 0 ] ) + 1 ;
for( V_9 = 1 ; V_9 < V_52 && V_153 [ V_9 ] ; V_9 ++ ) {
fprintf ( V_186 , L_69 , V_153 [ V_9 ] ) ;
V_187 += F_58 ( V_153 [ V_9 ] ) + 1 ;
}
V_187 += V_11 ;
for(; V_153 [ V_9 ] ; V_9 ++ ) fprintf ( V_186 , L_69 , V_153 [ V_9 ] ) ;
if( V_187 < 20 ) {
fprintf ( V_186 , L_70 , V_187 , L_71 ) ;
} else{
fprintf ( V_186 , L_72 , V_187 - 7 , L_71 ) ;
}
}
static int F_83 ( int V_52 )
{
int V_9 ;
int V_188 = 0 ;
if( V_153 != 0 && * V_153 != 0 ) {
for( V_9 = 1 ; V_153 [ V_9 ] ; V_9 ++ ) {
if( V_188 || ! F_84 ( V_153 [ V_9 ] ) ) {
if( V_52 == 0 ) return V_9 ;
V_52 -- ;
}
if( strcmp ( V_153 [ V_9 ] , L_73 ) == 0 ) V_188 = 1 ;
}
}
return - 1 ;
}
static int F_85 ( int V_9 , T_5 * V_186 )
{
int V_16 ;
int V_120 = 0 ;
int V_10 ;
for( V_10 = 0 ; V_189 [ V_10 ] . V_190 ; V_10 ++ ) {
if( strncmp ( & V_153 [ V_9 ] [ 1 ] , V_189 [ V_10 ] . V_190 , F_58 ( V_189 [ V_10 ] . V_190 ) ) == 0 ) break;
}
V_16 = V_153 [ V_9 ] [ 0 ] == '-' ? 1 : 0 ;
if( V_189 [ V_10 ] . V_190 == 0 ) {
if( V_186 ) {
fprintf ( V_186 , L_74 , V_191 ) ;
F_82 ( V_9 , 1 , V_186 ) ;
}
V_120 ++ ;
} else if( V_189 [ V_10 ] . V_38 == & V_167 ) {
} else if( V_189 [ V_10 ] . type == V_165 ) {
* ( ( int * ) V_189 [ V_10 ] . V_38 ) = V_16 ;
} else if( V_189 [ V_10 ] . type == V_192 ) {
V_189 [ V_10 ] . F_86 ( & V_16 ) ;
} else if( V_189 [ V_10 ] . type == V_166 ) {
V_189 [ V_10 ] . F_86 ( & V_153 [ V_9 ] [ 2 ] ) ;
} else{
if( V_186 ) {
fprintf ( V_186 , L_75 , V_191 ) ;
F_82 ( V_9 , 1 , V_186 ) ;
}
V_120 ++ ;
}
return V_120 ;
}
static int F_87 ( int V_9 , T_5 * V_186 )
{
int V_193 = 0 ;
double V_194 = 0.0 ;
char * V_195 = 0 , * V_196 ;
char * V_143 ;
int V_10 ;
int V_120 = 0 ;
V_143 = strchr ( V_153 [ V_9 ] , '=' ) ;
assert ( V_143 != 0 ) ;
* V_143 = 0 ;
for( V_10 = 0 ; V_189 [ V_10 ] . V_190 ; V_10 ++ ) {
if( strcmp ( V_153 [ V_9 ] , V_189 [ V_10 ] . V_190 ) == 0 ) break;
}
* V_143 = '=' ;
if( V_189 [ V_10 ] . V_190 == 0 ) {
if( V_186 ) {
fprintf ( V_186 , L_74 , V_191 ) ;
F_82 ( V_9 , 0 , V_186 ) ;
}
V_120 ++ ;
} else{
V_143 ++ ;
switch( V_189 [ V_10 ] . type ) {
case V_165 :
case V_192 :
if( V_186 ) {
fprintf ( V_186 , L_76 , V_191 ) ;
F_82 ( V_9 , 0 , V_186 ) ;
}
V_120 ++ ;
break;
case V_197 :
case V_198 :
V_194 = strtod ( V_143 , & V_196 ) ;
if( * V_196 ) {
if( V_186 ) {
fprintf ( V_186 ,
L_77 , V_191 ) ;
F_82 ( V_9 , ( int ) ( ( char * ) V_196 - ( char * ) V_153 [ V_9 ] ) , V_186 ) ;
}
V_120 ++ ;
}
break;
case V_199 :
case V_200 :
V_193 = ( int ) strtol ( V_143 , & V_196 , 0 ) ;
if( * V_196 ) {
if( V_186 ) {
fprintf ( V_186 , L_78 , V_191 ) ;
F_82 ( V_9 , ( int ) ( ( char * ) V_196 - ( char * ) V_153 [ V_9 ] ) , V_186 ) ;
}
V_120 ++ ;
}
break;
case V_201 :
case V_166 :
V_195 = V_143 ;
break;
}
switch( V_189 [ V_10 ] . type ) {
case V_165 :
case V_192 :
break;
case V_197 :
* ( double * ) ( V_189 [ V_10 ] . V_38 ) = V_194 ;
break;
case V_198 :
V_189 [ V_10 ] . F_86 ( & V_194 ) ;
break;
case V_199 :
* ( int * ) ( V_189 [ V_10 ] . V_38 ) = V_193 ;
break;
case V_200 :
V_189 [ V_10 ] . F_86 ( & V_193 ) ;
break;
case V_201 :
* ( char * * ) ( V_189 [ V_10 ] . V_38 ) = V_195 ;
break;
case V_166 :
V_189 [ V_10 ] . F_86 ( V_195 ) ;
break;
}
}
return V_120 ;
}
int F_61 ( char * * V_96 , struct V_163 * V_202 , T_5 * V_186 )
{
int V_120 = 0 ;
V_153 = V_96 ;
V_189 = V_202 ;
V_203 = V_186 ;
if( V_153 && * V_153 && V_189 ) {
int V_9 ;
for( V_9 = 1 ; V_153 [ V_9 ] ; V_9 ++ ) {
if( V_153 [ V_9 ] [ 0 ] == '+' || V_153 [ V_9 ] [ 0 ] == '-' ) {
V_120 += F_85 ( V_9 , V_186 ) ;
} else if( strchr ( V_153 [ V_9 ] , '=' ) ) {
V_120 += F_87 ( V_9 , V_186 ) ;
}
}
}
if( V_120 > 0 ) {
fprintf ( V_186 , L_79 , * V_96 ) ;
F_88 () ;
exit ( 1 ) ;
}
return 0 ;
}
int F_62 ( void ) {
int V_204 = 0 ;
int V_188 = 0 ;
int V_9 ;
if( V_153 != 0 && V_153 [ 0 ] != 0 ) {
for( V_9 = 1 ; V_153 [ V_9 ] ; V_9 ++ ) {
if( V_188 || ! F_84 ( V_153 [ V_9 ] ) ) V_204 ++ ;
if( strcmp ( V_153 [ V_9 ] , L_73 ) == 0 ) V_188 = 1 ;
}
}
return V_204 ;
}
char * F_66 ( int V_52 )
{
int V_9 ;
V_9 = F_83 ( V_52 ) ;
return V_9 >= 0 ? V_153 [ V_9 ] : 0 ;
}
void F_89 ( int V_52 )
{
int V_9 ;
V_9 = F_83 ( V_52 ) ;
if( V_9 >= 0 ) F_82 ( V_9 , 0 , V_203 ) ;
}
void F_88 ( void ) {
int V_9 ;
int V_205 , V_206 ;
V_205 = 0 ;
for( V_9 = 0 ; V_189 [ V_9 ] . V_190 ; V_9 ++ ) {
V_206 = F_58 ( V_189 [ V_9 ] . V_190 ) + 1 ;
switch( V_189 [ V_9 ] . type ) {
case V_165 :
case V_192 :
break;
case V_199 :
case V_200 :
V_206 += 9 ;
break;
case V_197 :
case V_198 :
V_206 += 6 ;
break;
case V_201 :
case V_166 :
V_206 += 8 ;
break;
}
if( V_206 > V_205 ) V_205 = V_206 ;
}
for( V_9 = 0 ; V_189 [ V_9 ] . V_190 ; V_9 ++ ) {
switch( V_189 [ V_9 ] . type ) {
case V_165 :
case V_192 :
fprintf ( V_203 , L_80 , V_205 , V_189 [ V_9 ] . V_190 , V_189 [ V_9 ] . V_207 ) ;
break;
case V_199 :
case V_200 :
fprintf ( V_203 , L_81 , V_189 [ V_9 ] . V_190 ,
( int ) ( V_205 - F_58 ( V_189 [ V_9 ] . V_190 ) - 9 ) , L_71 , V_189 [ V_9 ] . V_207 ) ;
break;
case V_197 :
case V_198 :
fprintf ( V_203 , L_82 , V_189 [ V_9 ] . V_190 ,
( int ) ( V_205 - F_58 ( V_189 [ V_9 ] . V_190 ) - 6 ) , L_71 , V_189 [ V_9 ] . V_207 ) ;
break;
case V_201 :
case V_166 :
fprintf ( V_203 , L_83 , V_189 [ V_9 ] . V_190 ,
( int ) ( V_205 - F_58 ( V_189 [ V_9 ] . V_190 ) - 8 ) , L_71 , V_189 [ V_9 ] . V_207 ) ;
break;
}
}
}
static void F_90 ( struct V_208 * V_209 )
{
const char * V_33 ;
V_33 = F_91 ( V_209 -> V_210 ) ;
#if 0
printf("%s:%d: Token=[%s] state=%d\n",psp->filename,psp->tokenlineno,
x,psp->state);
#endif
switch( V_209 -> V_41 ) {
case V_211 :
V_209 -> V_212 = 0 ;
V_209 -> V_213 = 0 ;
V_209 -> V_214 = V_209 -> V_215 = 0 ;
V_209 -> V_216 -> V_174 = 0 ;
case V_217 :
if( V_33 [ 0 ] == '%' ) {
V_209 -> V_41 = V_218 ;
} else if( ISLOWER ( V_33 [ 0 ] ) ) {
V_209 -> V_74 = F_67 ( V_33 ) ;
V_209 -> V_60 = 0 ;
V_209 -> V_219 = 0 ;
V_209 -> V_41 = V_220 ;
} else if( V_33 [ 0 ] == '{' ) {
if( V_209 -> V_212 == 0 ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_84 ) ;
V_209 -> V_83 ++ ;
} else if( V_209 -> V_212 -> V_222 != 0 ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_85 ) ;
V_209 -> V_83 ++ ;
} else{
V_209 -> V_212 -> line = V_209 -> V_221 ;
V_209 -> V_212 -> V_222 = & V_33 [ 1 ] ;
}
} else if( V_33 [ 0 ] == '[' ) {
V_209 -> V_41 = V_223 ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_86 ,
V_33 ) ;
V_209 -> V_83 ++ ;
}
break;
case V_223 :
if( ! ISUPPER ( V_33 [ 0 ] ) ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_87 ) ;
V_209 -> V_83 ++ ;
} else if( V_209 -> V_212 == 0 ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_88 , V_33 ) ;
V_209 -> V_83 ++ ;
} else if( V_209 -> V_212 -> V_59 != 0 ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_89 ) ;
V_209 -> V_83 ++ ;
} else{
V_209 -> V_212 -> V_59 = F_67 ( V_33 ) ;
}
V_209 -> V_41 = V_224 ;
break;
case V_224 :
if( V_33 [ 0 ] != ']' ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_90 ) ;
V_209 -> V_83 ++ ;
}
V_209 -> V_41 = V_217 ;
break;
case V_220 :
if( V_33 [ 0 ] == ':' && V_33 [ 1 ] == ':' && V_33 [ 2 ] == '=' ) {
V_209 -> V_41 = V_225 ;
} else if( V_33 [ 0 ] == '(' ) {
V_209 -> V_41 = V_226 ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_91 ,
V_209 -> V_74 -> V_82 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_227 ;
}
break;
case V_226 :
if( ISALPHA ( V_33 [ 0 ] ) ) {
V_209 -> V_219 = V_33 ;
V_209 -> V_41 = V_228 ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_92 ,
V_33 , V_209 -> V_74 -> V_82 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_227 ;
}
break;
case V_228 :
if( V_33 [ 0 ] == ')' ) {
V_209 -> V_41 = V_229 ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_93 , V_209 -> V_219 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_227 ;
}
break;
case V_229 :
if( V_33 [ 0 ] == ':' && V_33 [ 1 ] == ':' && V_33 [ 2 ] == '=' ) {
V_209 -> V_41 = V_225 ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_94 ,
V_209 -> V_74 -> V_82 , V_209 -> V_219 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_227 ;
}
break;
case V_225 :
if( V_33 [ 0 ] == '.' ) {
struct V_42 * V_34 ;
V_34 = (struct V_42 * ) calloc ( sizeof( struct V_42 ) +
sizeof( struct V_37 * ) * V_209 -> V_60 + sizeof( char * ) * V_209 -> V_60 , 1 ) ;
if( V_34 == 0 ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_95 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_212 = 0 ;
} else{
int V_9 ;
V_34 -> V_115 = V_209 -> V_221 ;
V_34 -> V_61 = (struct V_37 * * ) & V_34 [ 1 ] ;
V_34 -> V_230 = ( const char * * ) & ( V_34 -> V_61 [ V_209 -> V_60 ] ) ;
for( V_9 = 0 ; V_9 < V_209 -> V_60 ; V_9 ++ ) {
V_34 -> V_61 [ V_9 ] = V_209 -> V_61 [ V_9 ] ;
V_34 -> V_230 [ V_9 ] = V_209 -> V_231 [ V_9 ] ;
}
V_34 -> V_74 = V_209 -> V_74 ;
V_34 -> V_219 = V_209 -> V_219 ;
V_34 -> V_60 = V_209 -> V_60 ;
V_34 -> V_222 = 0 ;
V_34 -> V_59 = 0 ;
V_34 -> V_30 = V_209 -> V_216 -> V_174 ++ ;
V_34 -> V_84 = V_34 -> V_74 -> V_42 ;
V_34 -> V_74 -> V_42 = V_34 ;
V_34 -> V_26 = 0 ;
if( V_209 -> V_214 == 0 ) {
V_209 -> V_214 = V_209 -> V_215 = V_34 ;
} else{
V_209 -> V_215 -> V_26 = V_34 ;
V_209 -> V_215 = V_34 ;
}
V_209 -> V_212 = V_34 ;
}
V_209 -> V_41 = V_217 ;
} else if( ISALPHA ( V_33 [ 0 ] ) ) {
if( V_209 -> V_60 >= V_232 ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_96 ,
V_33 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_227 ;
} else{
V_209 -> V_61 [ V_209 -> V_60 ] = F_67 ( V_33 ) ;
V_209 -> V_231 [ V_209 -> V_60 ] = 0 ;
V_209 -> V_60 ++ ;
}
} else if( ( V_33 [ 0 ] == '|' || V_33 [ 0 ] == '/' ) && V_209 -> V_60 > 0 ) {
struct V_37 * V_233 = V_209 -> V_61 [ V_209 -> V_60 - 1 ] ;
if( V_233 -> type != V_62 ) {
struct V_37 * V_234 = V_233 ;
V_233 = (struct V_37 * ) calloc ( 1 , sizeof( * V_233 ) ) ;
memset ( V_233 , 0 , sizeof( * V_233 ) ) ;
V_233 -> type = V_62 ;
V_233 -> V_63 = 1 ;
V_233 -> V_64 = (struct V_37 * * ) calloc ( 1 , sizeof( struct V_37 * ) ) ;
V_233 -> V_64 [ 0 ] = V_234 ;
V_233 -> V_82 = V_234 -> V_82 ;
V_209 -> V_61 [ V_209 -> V_60 - 1 ] = V_233 ;
}
V_233 -> V_63 ++ ;
V_233 -> V_64 = (struct V_37 * * ) realloc ( V_233 -> V_64 ,
sizeof( struct V_37 * ) * V_233 -> V_63 ) ;
V_233 -> V_64 [ V_233 -> V_63 - 1 ] = F_67 ( & V_33 [ 1 ] ) ;
if( ISLOWER ( V_33 [ 1 ] ) || ISLOWER ( V_233 -> V_64 [ 0 ] -> V_82 [ 0 ] ) ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_97 ) ;
V_209 -> V_83 ++ ;
}
} else if( V_33 [ 0 ] == '(' && V_209 -> V_60 > 0 ) {
V_209 -> V_41 = V_235 ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_98 , V_33 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_227 ;
}
break;
case V_235 :
if( ISALPHA ( V_33 [ 0 ] ) ) {
V_209 -> V_231 [ V_209 -> V_60 - 1 ] = V_33 ;
V_209 -> V_41 = V_236 ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_99 ,
V_33 , V_209 -> V_61 [ V_209 -> V_60 - 1 ] -> V_82 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_227 ;
}
break;
case V_236 :
if( V_33 [ 0 ] == ')' ) {
V_209 -> V_41 = V_225 ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_93 , V_209 -> V_219 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_227 ;
}
break;
case V_218 :
if( ISALPHA ( V_33 [ 0 ] ) ) {
V_209 -> V_237 = V_33 ;
V_209 -> V_238 = 0 ;
V_209 -> V_239 = 0 ;
V_209 -> V_240 = 1 ;
V_209 -> V_41 = V_241 ;
if( strcmp ( V_33 , L_100 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> V_82 ) ;
V_209 -> V_240 = 0 ;
} else if( strcmp ( V_33 , L_101 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> include ) ;
} else if( strcmp ( V_33 , L_102 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> V_242 ) ;
} else if( strcmp ( V_33 , L_103 ) == 0 ) {
V_209 -> V_238 = & V_209 -> V_216 -> V_243 ;
} else if( strcmp ( V_33 , L_104 ) == 0 ) {
V_209 -> V_238 = & V_209 -> V_216 -> V_244 ;
} else if( strcmp ( V_33 , L_105 ) == 0 ) {
V_209 -> V_238 = & V_209 -> V_216 -> V_245 ;
V_209 -> V_240 = 0 ;
} else if( strcmp ( V_33 , L_106 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> error ) ;
} else if( strcmp ( V_33 , L_107 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> V_246 ) ;
} else if( strcmp ( V_33 , L_108 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> V_247 ) ;
} else if( strcmp ( V_33 , L_109 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> V_248 ) ;
} else if( strcmp ( V_33 , L_110 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> V_38 ) ;
V_209 -> V_240 = 0 ;
} else if( strcmp ( V_33 , L_111 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> V_249 ) ;
V_209 -> V_240 = 0 ;
} else if( strcmp ( V_33 , L_112 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> V_250 ) ;
V_209 -> V_240 = 0 ;
} else if( strcmp ( V_33 , L_113 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> V_251 ) ;
V_209 -> V_240 = 0 ;
} else if( strcmp ( V_33 , L_114 ) == 0 ) {
V_209 -> V_238 = & ( V_209 -> V_216 -> V_80 ) ;
V_209 -> V_240 = 0 ;
} else if( strcmp ( V_33 , L_115 ) == 0 ) {
V_209 -> V_213 ++ ;
V_209 -> V_252 = V_127 ;
V_209 -> V_41 = V_253 ;
} else if( strcmp ( V_33 , L_116 ) == 0 ) {
V_209 -> V_213 ++ ;
V_209 -> V_252 = V_126 ;
V_209 -> V_41 = V_253 ;
} else if( strcmp ( V_33 , L_117 ) == 0 ) {
V_209 -> V_213 ++ ;
V_209 -> V_252 = V_128 ;
V_209 -> V_41 = V_253 ;
} else if( strcmp ( V_33 , L_118 ) == 0 ) {
V_209 -> V_41 = V_254 ;
} else if( strcmp ( V_33 , L_119 ) == 0 ) {
V_209 -> V_41 = V_255 ;
} else if( strcmp ( V_33 , L_120 ) == 0 ) {
V_209 -> V_256 = 0 ;
V_209 -> V_41 = V_257 ;
} else if( strcmp ( V_33 , L_121 ) == 0 ) {
V_209 -> V_41 = V_258 ;
} else if( strcmp ( V_33 , L_122 ) == 0 ) {
V_209 -> V_41 = V_259 ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_123 , V_33 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_260 ;
}
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_124 , V_33 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_260 ;
}
break;
case V_254 :
if( ! ISALPHA ( V_33 [ 0 ] ) ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_125 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_260 ;
} else{
struct V_37 * V_29 = F_67 ( V_33 ) ;
V_209 -> V_238 = & V_29 -> V_261 ;
V_209 -> V_239 = & V_29 -> V_262 ;
V_209 -> V_240 = 1 ;
V_209 -> V_41 = V_241 ;
}
break;
case V_255 :
if( ! ISALPHA ( V_33 [ 0 ] ) ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_126 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_260 ;
} else{
struct V_37 * V_29 = F_21 ( V_33 ) ;
if( ( V_29 ) && ( V_29 -> V_263 ) ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_127 , V_33 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_260 ;
} else{
if ( ! V_29 ) {
V_29 = F_67 ( V_33 ) ;
}
V_209 -> V_238 = & V_29 -> V_263 ;
V_209 -> V_240 = 0 ;
V_209 -> V_41 = V_241 ;
}
}
break;
case V_253 :
if( V_33 [ 0 ] == '.' ) {
V_209 -> V_41 = V_217 ;
} else if( ISUPPER ( V_33 [ 0 ] ) ) {
struct V_37 * V_29 ;
V_29 = F_67 ( V_33 ) ;
if( V_29 -> V_65 >= 0 ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_128 , V_33 ) ;
V_209 -> V_83 ++ ;
} else{
V_29 -> V_65 = V_209 -> V_213 ;
V_29 -> V_125 = V_209 -> V_252 ;
}
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_129 , V_33 ) ;
V_209 -> V_83 ++ ;
}
break;
case V_241 :
if( V_33 [ 0 ] == '{' || V_33 [ 0 ] == '\"' || ISALNUM ( V_33 [ 0 ] ) ) {
const char * V_264 , * V_265 ;
char * V_1 , * V_14 ;
int V_266 , V_52 , V_267 = 0 , V_268 , V_269 ;
int V_270 ;
char V_271 [ 50 ] ;
V_265 = V_33 ;
if( V_265 [ 0 ] == '"' || V_265 [ 0 ] == '{' ) V_265 ++ ;
V_268 = F_58 ( V_265 ) ;
if( * V_209 -> V_238 ) {
V_264 = * V_209 -> V_238 ;
} else{
V_264 = L_71 ;
}
V_266 = F_58 ( V_264 ) ;
V_52 = V_266 + V_268 + 20 ;
V_270 = ! V_209 -> V_216 -> V_161 && V_209 -> V_240 &&
( V_209 -> V_239 == 0 || V_209 -> V_239 [ 0 ] != 0 ) ;
if( V_270 ) {
for( V_14 = V_209 -> V_81 , V_269 = 0 ; * V_14 ; V_14 ++ ) {
if( * V_14 == '\\' ) V_269 ++ ;
}
F_3 ( V_271 , L_130 , V_209 -> V_221 ) ;
V_267 = F_58 ( V_271 ) ;
V_52 += V_267 + F_58 ( V_209 -> V_81 ) + V_269 ;
}
* V_209 -> V_238 = ( char * ) realloc ( * V_209 -> V_238 , V_52 ) ;
V_1 = * V_209 -> V_238 + V_266 ;
if( V_270 ) {
if( V_266 && V_1 [ - 1 ] != '\n' ) {
* ( V_1 ++ ) = '\n' ;
}
memcpy ( V_1 , V_271 , V_267 ) ;
V_1 += V_267 ;
* ( V_1 ++ ) = '"' ;
for( V_14 = V_209 -> V_81 ; * V_14 ; V_14 ++ ) {
if( * V_14 == '\\' ) {
* ( V_1 ++ ) = '\\' ;
}
* ( V_1 ++ ) = * V_14 ;
}
* ( V_1 ++ ) = '"' ;
* ( V_1 ++ ) = '\n' ;
}
if( V_209 -> V_239 && V_209 -> V_239 [ 0 ] == 0 ) {
V_209 -> V_239 [ 0 ] = V_209 -> V_221 ;
}
memcpy ( V_1 , V_265 , V_268 ) ;
V_1 += V_268 ;
* V_1 = 0 ;
V_209 -> V_41 = V_217 ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_131 , V_209 -> V_237 , V_33 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_260 ;
}
break;
case V_257 :
if( V_33 [ 0 ] == '.' ) {
V_209 -> V_41 = V_217 ;
} else if( ! ISUPPER ( V_33 [ 0 ] ) ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_132 , V_33 ) ;
V_209 -> V_83 ++ ;
} else{
struct V_37 * V_29 = F_67 ( V_33 ) ;
if( V_209 -> V_256 == 0 ) {
V_209 -> V_256 = V_29 ;
} else if( V_29 -> V_256 ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_133 , V_33 ) ;
V_209 -> V_83 ++ ;
} else{
V_29 -> V_256 = V_209 -> V_256 ;
V_209 -> V_216 -> V_272 = 1 ;
}
}
break;
case V_258 :
if( V_33 [ 0 ] == '.' ) {
V_209 -> V_41 = V_217 ;
} else if( ! ISUPPER ( V_33 [ 0 ] ) ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_134 , V_33 ) ;
V_209 -> V_83 ++ ;
} else{
struct V_37 * V_29 = F_67 ( V_33 ) ;
if( V_209 -> V_216 -> V_273 == 0 ) {
V_209 -> V_216 -> V_273 = V_29 ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_135 , V_33 ) ;
V_209 -> V_83 ++ ;
}
}
break;
case V_259 :
if( ! ISLOWER ( V_33 [ 0 ] ) ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_136 , V_33 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_260 ;
} else if( F_21 ( V_33 ) ) {
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_137 , V_33 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_260 ;
} else{
V_209 -> V_274 = F_67 ( V_33 ) ;
V_209 -> V_274 -> type = V_62 ;
V_209 -> V_41 = V_275 ;
}
break;
case V_275 :
if( V_33 [ 0 ] == '.' ) {
V_209 -> V_41 = V_217 ;
} else if( ISUPPER ( V_33 [ 0 ] ) || ( ( V_33 [ 0 ] == '|' || V_33 [ 0 ] == '/' ) && ISUPPER ( V_33 [ 1 ] ) ) ) {
struct V_37 * V_233 = V_209 -> V_274 ;
V_233 -> V_63 ++ ;
V_233 -> V_64 = (struct V_37 * * ) realloc ( V_233 -> V_64 ,
sizeof( struct V_37 * ) * V_233 -> V_63 ) ;
if( ! ISUPPER ( V_33 [ 0 ] ) ) V_33 ++ ;
V_233 -> V_64 [ V_233 -> V_63 - 1 ] = F_67 ( V_33 ) ;
} else{
F_22 ( V_209 -> V_81 , V_209 -> V_221 ,
L_138 , V_33 ) ;
V_209 -> V_83 ++ ;
V_209 -> V_41 = V_260 ;
}
break;
case V_227 :
case V_260 :
if( V_33 [ 0 ] == '.' ) V_209 -> V_41 = V_217 ;
if( V_33 [ 0 ] == '%' ) V_209 -> V_41 = V_218 ;
break;
}
}
static void F_92 ( char * V_14 ) {
int V_9 , V_10 , V_11 , V_52 ;
int V_276 = 0 ;
int V_80 = 0 ;
int V_141 = 1 ;
int V_277 = 1 ;
for( V_9 = 0 ; V_14 [ V_9 ] ; V_9 ++ ) {
if( V_14 [ V_9 ] == '\n' ) V_141 ++ ;
if( V_14 [ V_9 ] != '%' || ( V_9 > 0 && V_14 [ V_9 - 1 ] != '\n' ) ) continue;
if( strncmp ( & V_14 [ V_9 ] , L_139 , 6 ) == 0 && ISSPACE ( V_14 [ V_9 + 6 ] ) ) {
if( V_276 ) {
V_276 -- ;
if( V_276 == 0 ) {
for( V_10 = V_80 ; V_10 < V_9 ; V_10 ++ ) if( V_14 [ V_10 ] != '\n' ) V_14 [ V_10 ] = ' ' ;
}
}
for( V_10 = V_9 ; V_14 [ V_10 ] && V_14 [ V_10 ] != '\n' ; V_10 ++ ) V_14 [ V_10 ] = ' ' ;
} else if( ( strncmp ( & V_14 [ V_9 ] , L_140 , 6 ) == 0 && ISSPACE ( V_14 [ V_9 + 6 ] ) )
|| ( strncmp ( & V_14 [ V_9 ] , L_141 , 7 ) == 0 && ISSPACE ( V_14 [ V_9 + 7 ] ) ) ) {
if( V_276 ) {
V_276 ++ ;
} else{
for( V_10 = V_9 + 7 ; ISSPACE ( V_14 [ V_10 ] ) ; V_10 ++ ) {}
for( V_52 = 0 ; V_14 [ V_10 + V_52 ] && ! ISSPACE ( V_14 [ V_10 + V_52 ] ) ; V_52 ++ ) {}
V_276 = 1 ;
for( V_11 = 0 ; V_11 < V_146 ; V_11 ++ ) {
if( strncmp ( V_147 [ V_11 ] , & V_14 [ V_10 ] , V_52 ) == 0 && F_58 ( V_147 [ V_11 ] ) == V_52 ) {
V_276 = 0 ;
break;
}
}
if( V_14 [ V_9 + 3 ] == 'n' ) V_276 = ! V_276 ;
if( V_276 ) {
V_80 = V_9 ;
V_277 = V_141 ;
}
}
for( V_10 = V_9 ; V_14 [ V_10 ] && V_14 [ V_10 ] != '\n' ; V_10 ++ ) V_14 [ V_10 ] = ' ' ;
}
}
if( V_276 ) {
fprintf ( V_17 , L_142 , V_277 ) ;
exit ( 1 ) ;
}
}
void F_68 ( struct V_57 * V_216 )
{
struct V_208 V_278 ;
T_5 * V_279 ;
char * V_280 ;
unsigned long int V_281 ;
int V_141 ;
int V_12 ;
char * V_143 , * V_282 ;
int V_283 = 0 ;
memset ( & V_278 , '\0' , sizeof( V_278 ) ) ;
V_278 . V_216 = V_216 ;
V_278 . V_81 = V_216 -> V_81 ;
V_278 . V_83 = 0 ;
V_278 . V_41 = V_211 ;
V_279 = fopen ( V_278 . V_81 , L_143 ) ;
if( V_279 == 0 ) {
F_22 ( V_278 . V_81 , 0 , L_144 ) ;
V_216 -> V_83 ++ ;
return;
}
fseek ( V_279 , 0 , 2 ) ;
V_281 = ftell ( V_279 ) ;
rewind ( V_279 ) ;
V_280 = ( char * ) malloc ( V_281 + 1 ) ;
if( V_281 > 100000000 || V_280 == 0 ) {
F_22 ( V_278 . V_81 , 0 , L_145 ) ;
V_216 -> V_83 ++ ;
free ( V_280 ) ;
fclose ( V_279 ) ;
return;
}
if( fread ( V_280 , 1 , V_281 , V_279 ) != V_281 ) {
F_22 ( V_278 . V_81 , 0 , L_146 ,
V_281 ) ;
free ( V_280 ) ;
V_216 -> V_83 ++ ;
fclose ( V_279 ) ;
return;
}
fclose ( V_279 ) ;
V_280 [ V_281 ] = 0 ;
F_92 ( V_280 ) ;
V_141 = 1 ;
for( V_143 = V_280 ; ( V_12 = * V_143 ) != 0 ; ) {
if( V_12 == '\n' ) V_141 ++ ;
if( ISSPACE ( V_12 ) ) { V_143 ++ ; continue; }
if( V_12 == '/' && V_143 [ 1 ] == '/' ) {
V_143 += 2 ;
while( ( V_12 = * V_143 ) != 0 && V_12 != '\n' ) V_143 ++ ;
continue;
}
if( V_12 == '/' && V_143 [ 1 ] == '*' ) {
V_143 += 2 ;
while( ( V_12 = * V_143 ) != 0 && ( V_12 != '/' || V_143 [ - 1 ] != '*' ) ) {
if( V_12 == '\n' ) V_141 ++ ;
V_143 ++ ;
}
if( V_12 ) V_143 ++ ;
continue;
}
V_278 . V_210 = V_143 ;
V_278 . V_221 = V_141 ;
if( V_12 == '\"' ) {
V_143 ++ ;
while( ( V_12 = * V_143 ) != 0 && V_12 != '\"' ) {
if( V_12 == '\n' ) V_141 ++ ;
V_143 ++ ;
}
if( V_12 == 0 ) {
F_22 ( V_278 . V_81 , V_283 ,
L_147 ) ;
V_278 . V_83 ++ ;
V_282 = V_143 ;
} else{
V_282 = V_143 + 1 ;
}
} else if( V_12 == '{' ) {
int V_284 ;
V_143 ++ ;
for( V_284 = 1 ; ( V_12 = * V_143 ) != 0 && ( V_284 > 1 || V_12 != '}' ) ; V_143 ++ ) {
if( V_12 == '\n' ) V_141 ++ ;
else if( V_12 == '{' ) V_284 ++ ;
else if( V_12 == '}' ) V_284 -- ;
else if( V_12 == '/' && V_143 [ 1 ] == '*' ) {
int V_285 ;
V_143 = & V_143 [ 2 ] ;
V_285 = 0 ;
while( ( V_12 = * V_143 ) != 0 && ( V_12 != '/' || V_285 != '*' ) ) {
if( V_12 == '\n' ) V_141 ++ ;
V_285 = V_12 ;
V_143 ++ ;
}
} else if( V_12 == '/' && V_143 [ 1 ] == '/' ) {
V_143 = & V_143 [ 2 ] ;
while( ( V_12 = * V_143 ) != 0 && V_12 != '\n' ) V_143 ++ ;
if( V_12 ) V_141 ++ ;
} else if( V_12 == '\'' || V_12 == '\"' ) {
int V_286 , V_285 ;
V_286 = V_12 ;
V_285 = 0 ;
for( V_143 ++ ; ( V_12 = * V_143 ) != 0 && ( V_12 != V_286 || V_285 == '\\' ) ; V_143 ++ ) {
if( V_12 == '\n' ) V_141 ++ ;
if( V_285 == '\\' ) V_285 = 0 ;
else V_285 = V_12 ;
}
}
}
if( V_12 == 0 ) {
F_22 ( V_278 . V_81 , V_278 . V_221 ,
L_148 ) ;
V_278 . V_83 ++ ;
V_282 = V_143 ;
} else{
V_282 = V_143 + 1 ;
}
} else if( ISALNUM ( V_12 ) ) {
while( ( V_12 = * V_143 ) != 0 && ( ISALNUM ( V_12 ) || V_12 == '_' ) ) V_143 ++ ;
V_282 = V_143 ;
} else if( V_12 == ':' && V_143 [ 1 ] == ':' && V_143 [ 2 ] == '=' ) {
V_143 += 3 ;
V_282 = V_143 ;
} else if( ( V_12 == '/' || V_12 == '|' ) && ISALPHA ( V_143 [ 1 ] ) ) {
V_143 += 2 ;
while( ( V_12 = * V_143 ) != 0 && ( ISALNUM ( V_12 ) || V_12 == '_' ) ) V_143 ++ ;
V_282 = V_143 ;
} else{
V_143 ++ ;
V_282 = V_143 ;
}
V_12 = * V_143 ;
* V_143 = 0 ;
F_90 ( & V_278 ) ;
* V_143 = ( char ) V_12 ;
V_143 = V_282 ;
}
free ( V_280 ) ;
V_216 -> V_42 = V_278 . V_214 ;
V_216 -> V_83 = V_278 . V_83 ;
}
struct V_107 * F_93 ( void ) {
struct V_107 * V_287 ;
if( V_288 == 0 ) {
int V_9 ;
int V_25 = 100 ;
V_288 = (struct V_107 * ) calloc ( V_25 , sizeof( struct V_107 ) ) ;
if( V_288 == 0 ) {
fprintf ( V_17 ,
L_149 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_25 - 1 ; V_9 ++ ) V_288 [ V_9 ] . V_26 = & V_288 [ V_9 + 1 ] ;
V_288 [ V_25 - 1 ] . V_26 = 0 ;
}
V_287 = V_288 ;
V_288 = V_288 -> V_26 ;
return V_287 ;
}
void F_40 ( struct V_107 * * V_289 , struct V_85 * V_89 )
{
struct V_107 * V_287 ;
V_287 = F_93 () ;
V_287 -> V_26 = * V_289 ;
* V_289 = V_287 ;
V_287 -> V_89 = V_89 ;
}
void F_28 ( struct V_107 * * V_290 , struct V_107 * V_291 )
{
struct V_107 * V_292 ;
while( V_291 ) {
V_292 = V_291 -> V_26 ;
V_291 -> V_26 = * V_290 ;
* V_290 = V_291 ;
V_291 = V_292 ;
}
}
void F_29 ( struct V_107 * V_108 )
{
struct V_107 * V_292 ;
while( V_108 ) {
V_292 = V_108 -> V_26 ;
V_108 -> V_26 = V_288 ;
V_288 = V_108 ;
V_108 = V_292 ;
}
}
T_2 char * F_94 ( struct V_57 * V_66 , const char * V_293 )
{
char * V_82 ;
char * V_143 ;
V_82 = ( char * ) malloc ( F_58 ( V_66 -> V_81 ) + F_58 ( V_293 ) + 5 ) ;
if( V_82 == 0 ) {
fprintf ( V_17 , L_150 ) ;
exit ( 1 ) ;
}
F_4 ( V_82 , V_66 -> V_81 ) ;
V_143 = strrchr ( V_82 , '.' ) ;
if( V_143 ) * V_143 = 0 ;
F_5 ( V_82 , V_293 ) ;
return V_82 ;
}
T_2 char * F_95 ( struct V_57 * V_66 , const char * V_293 )
{
V_66 -> V_81 = V_66 -> V_173 ;
return F_94 ( V_66 , V_293 ) ;
}
T_2 T_5 * F_96 (
struct V_57 * V_66 ,
const char * V_293 ,
const char * V_294
) {
T_5 * V_279 ;
if( V_66 -> V_295 ) free ( V_66 -> V_295 ) ;
V_66 -> V_295 = F_95 ( V_66 , V_293 ) ;
V_279 = fopen ( V_66 -> V_295 , V_294 ) ;
if( V_279 == 0 && * V_294 == 'w' ) {
fprintf ( V_17 , L_151 , V_66 -> V_295 ) ;
V_66 -> V_83 ++ ;
return 0 ;
}
return V_279 ;
}
void F_71 ( struct V_57 * V_66 )
{
struct V_42 * V_34 ;
struct V_37 * V_29 ;
int V_9 , V_10 , V_296 , V_206 , V_297 , V_298 ;
printf ( L_152 , V_66 -> V_81 ) ;
V_296 = 10 ;
for( V_9 = 0 ; V_9 < V_66 -> V_68 ; V_9 ++ ) {
V_29 = V_66 -> V_69 [ V_9 ] ;
V_206 = F_58 ( V_29 -> V_82 ) ;
if( V_206 > V_296 ) V_296 = V_206 ;
}
V_297 = 76 / ( V_296 + 5 ) ;
if( V_297 < 1 ) V_297 = 1 ;
V_298 = ( V_66 -> V_68 + V_297 - 1 ) / V_297 ;
for( V_9 = 0 ; V_9 < V_298 ; V_9 ++ ) {
printf ( L_153 ) ;
for( V_10 = V_9 ; V_10 < V_66 -> V_68 ; V_10 += V_298 ) {
V_29 = V_66 -> V_69 [ V_10 ] ;
assert ( V_29 -> V_30 == V_10 ) ;
printf ( L_154 , V_10 , V_296 , V_296 , V_29 -> V_82 ) ;
}
printf ( L_15 ) ;
}
for( V_34 = V_66 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 ) {
printf ( L_68 , V_34 -> V_74 -> V_82 ) ;
printf ( L_155 ) ;
for( V_9 = 0 ; V_9 < V_34 -> V_60 ; V_9 ++ ) {
V_29 = V_34 -> V_61 [ V_9 ] ;
if( V_29 -> type == V_62 ) {
printf ( L_69 , V_29 -> V_64 [ 0 ] -> V_82 ) ;
for( V_10 = 1 ; V_10 < V_29 -> V_63 ; V_10 ++ ) {
printf ( L_156 , V_29 -> V_64 [ V_10 ] -> V_82 ) ;
}
} else{
printf ( L_69 , V_29 -> V_82 ) ;
}
}
printf ( L_157 ) ;
if( V_34 -> V_59 ) printf ( L_158 , V_34 -> V_59 -> V_82 ) ;
printf ( L_15 ) ;
}
}
T_2 void F_97 ( T_5 * V_279 , struct V_42 * V_34 , int V_299 ) {
struct V_37 * V_29 ;
int V_9 , V_10 ;
fprintf ( V_279 , L_159 , V_34 -> V_74 -> V_82 ) ;
for( V_9 = 0 ; V_9 <= V_34 -> V_60 ; V_9 ++ ) {
if( V_9 == V_299 ) fprintf ( V_279 , L_160 ) ;
if( V_9 == V_34 -> V_60 ) break;
V_29 = V_34 -> V_61 [ V_9 ] ;
if( V_29 -> type == V_62 ) {
fprintf ( V_279 , L_69 , V_29 -> V_64 [ 0 ] -> V_82 ) ;
for( V_10 = 1 ; V_10 < V_29 -> V_63 ; V_10 ++ ) {
fprintf ( V_279 , L_156 , V_29 -> V_64 [ V_10 ] -> V_82 ) ;
}
} else{
fprintf ( V_279 , L_69 , V_29 -> V_82 ) ;
}
}
}
T_2 void F_98 ( T_5 * V_279 , struct V_85 * V_89 ) {
F_97 ( V_279 , V_89 -> V_34 , V_89 -> V_105 ) ;
}
T_2 int F_99 (
struct V_22 * V_8 ,
T_5 * V_279 ,
int V_300
) {
int V_301 = 1 ;
switch( V_8 -> type ) {
case V_39 : {
struct V_41 * V_40 = V_8 -> V_33 . V_40 ;
fprintf ( V_279 , L_161 , V_300 , V_8 -> V_29 -> V_82 , V_40 -> V_94 ) ;
break;
}
case V_31 : {
struct V_42 * V_34 = V_8 -> V_33 . V_34 ;
fprintf ( V_279 , L_162 , V_300 , V_8 -> V_29 -> V_82 , V_34 -> V_30 ) ;
F_97 ( V_279 , V_34 , - 1 ) ;
break;
}
case V_32 : {
struct V_42 * V_34 = V_8 -> V_33 . V_34 ;
fprintf ( V_279 , L_163 , V_300 , V_8 -> V_29 -> V_82 , V_34 -> V_30 ) ;
F_97 ( V_279 , V_34 , - 1 ) ;
break;
}
case V_111 :
fprintf ( V_279 , L_164 , V_300 , V_8 -> V_29 -> V_82 ) ;
break;
case ERROR :
fprintf ( V_279 , L_165 , V_300 , V_8 -> V_29 -> V_82 ) ;
break;
case V_122 :
case V_129 :
fprintf ( V_279 , L_166 ,
V_300 , V_8 -> V_29 -> V_82 , V_8 -> V_33 . V_34 -> V_30 ) ;
break;
case V_121 :
fprintf ( V_279 , L_167 ,
V_300 , V_8 -> V_29 -> V_82 , V_8 -> V_33 . V_40 -> V_94 ) ;
break;
case V_124 :
if( V_168 ) {
fprintf ( V_279 , L_168 ,
V_300 , V_8 -> V_29 -> V_82 , V_8 -> V_33 . V_40 -> V_94 ) ;
} else{
V_301 = 0 ;
}
break;
case V_123 :
if( V_168 ) {
fprintf ( V_279 , L_169 ,
V_300 , V_8 -> V_29 -> V_82 , V_8 -> V_33 . V_34 -> V_30 ) ;
} else{
V_301 = 0 ;
}
break;
case V_302 :
V_301 = 0 ;
break;
}
return V_301 ;
}
void F_76 ( struct V_57 * V_66 )
{
int V_9 ;
struct V_41 * V_40 ;
struct V_85 * V_89 ;
struct V_22 * V_8 ;
T_5 * V_279 ;
V_279 = F_96 ( V_66 , L_170 , L_171 ) ;
if( V_279 == 0 ) return;
for( V_9 = 0 ; V_9 < V_66 -> V_176 ; V_9 ++ ) {
V_40 = V_66 -> V_109 [ V_9 ] ;
if( V_40 ) {
fprintf ( V_279 , L_172 , V_40 -> V_94 ) ;
if( V_66 -> V_156 ) V_89 = V_40 -> V_90 ;
else V_89 = V_40 -> V_89 ;
while( V_89 ) {
char V_303 [ 20 ] ;
if( V_89 -> V_105 == V_89 -> V_34 -> V_60 ) {
F_3 ( V_303 , L_173 , V_89 -> V_34 -> V_30 ) ;
fprintf ( V_279 , L_174 , V_303 ) ;
} else{
fprintf ( V_279 , L_175 ) ;
}
F_98 ( V_279 , V_89 ) ;
fprintf ( V_279 , L_15 ) ;
#if 0
SetPrint(fp,cfp->fws,lemp);
PlinkPrint(fp,cfp->fplp,"To ");
PlinkPrint(fp,cfp->bplp,"From");
#endif
if( V_66 -> V_156 ) V_89 = V_89 -> V_90 ;
else V_89 = V_89 -> V_26 ;
}
fprintf ( V_279 , L_15 ) ;
for( V_8 = V_40 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( F_99 ( V_8 , V_279 , 30 ) ) fprintf ( V_279 , L_15 ) ;
}
}
fprintf ( V_279 , L_15 ) ;
}
fprintf ( V_279 , L_176 ) ;
fprintf ( V_279 , L_177 ) ;
for( V_9 = 0 ; V_9 < V_66 -> V_68 ; V_9 ++ ) {
int V_10 ;
struct V_37 * V_29 ;
V_29 = V_66 -> V_69 [ V_9 ] ;
fprintf ( V_279 , L_178 , V_9 , V_29 -> V_82 ) ;
if( V_29 -> type == V_75 ) {
fprintf ( V_279 , L_179 ) ;
if( V_29 -> V_70 ) {
fprintf ( V_279 , L_180 ) ;
}
for( V_10 = 0 ; V_10 < V_66 -> V_72 ; V_10 ++ ) {
if( V_29 -> V_73 && F_44 ( V_29 -> V_73 , V_10 ) ) {
fprintf ( V_279 , L_69 , V_66 -> V_69 [ V_10 ] -> V_82 ) ;
}
}
}
fprintf ( V_279 , L_15 ) ;
}
fclose ( V_279 ) ;
return;
}
T_2 char * F_100 ( char * V_171 , char * V_82 , int V_304 )
{
const char * V_305 ;
char * V_306 ;
char * V_307 ;
char * V_308 , * V_143 ;
char V_12 ;
#ifdef F_101
V_143 = strrchr ( V_171 , '\\' ) ;
#else
V_143 = strrchr ( V_171 , '/' ) ;
#endif
if( V_143 ) {
V_12 = * V_143 ;
* V_143 = 0 ;
V_308 = ( char * ) malloc ( F_58 ( V_171 ) + F_58 ( V_82 ) + 2 ) ;
if( V_308 ) F_3 ( V_308 , L_181 , V_171 , V_82 ) ;
* V_143 = V_12 ;
} else{
V_305 = getenv ( L_182 ) ;
if( V_305 == 0 ) V_305 = L_183 ;
V_307 = ( char * ) malloc ( F_58 ( V_305 ) + 1 ) ;
if( V_307 == 0 )
return NULL ;
V_306 = V_307 ;
V_308 = ( char * ) malloc ( F_58 ( V_305 ) + F_58 ( V_82 ) + 2 ) ;
if( ( V_308 != 0 ) ) {
F_4 ( V_307 , V_305 ) ;
while( * V_307 ) {
V_143 = strchr ( V_307 , ':' ) ;
if( V_143 == 0 ) V_143 = & V_307 [ F_58 ( V_307 ) ] ;
V_12 = * V_143 ;
* V_143 = 0 ;
F_3 ( V_308 , L_181 , V_307 , V_82 ) ;
* V_143 = V_12 ;
if( V_12 == 0 ) V_307 [ 0 ] = 0 ;
else V_307 = & V_143 [ 1 ] ;
if( F_102 ( V_308 , V_304 ) == 0 ) break;
}
}
free ( V_306 ) ;
}
return V_308 ;
}
T_2 int F_103 ( struct V_57 * V_66 , struct V_22 * V_8 )
{
int V_309 ;
switch( V_8 -> type ) {
case V_39 : V_309 = V_8 -> V_33 . V_40 -> V_94 ; break;
case V_32 : V_309 = V_8 -> V_33 . V_34 -> V_30 + V_66 -> V_95 ; break;
case V_31 : V_309 = V_8 -> V_33 . V_34 -> V_30 + V_66 -> V_95 + V_66 -> V_174 ; break;
case ERROR : V_309 = V_66 -> V_95 + V_66 -> V_174 * 2 ; break;
case V_111 : V_309 = V_66 -> V_95 + V_66 -> V_174 * 2 + 1 ; break;
default: V_309 = - 1 ; break;
}
return V_309 ;
}
T_2 void F_104 ( char * V_82 , T_5 * V_310 , T_5 * V_311 , int * V_141 )
{
int V_9 , V_312 ;
char line [ V_313 ] ;
while( fgets ( line , V_313 , V_310 ) && ( line [ 0 ] != '%' || line [ 1 ] != '%' ) ) {
( * V_141 ) ++ ;
V_312 = 0 ;
if( V_82 ) {
for( V_9 = 0 ; line [ V_9 ] ; V_9 ++ ) {
if( line [ V_9 ] == 'P' && strncmp ( & line [ V_9 ] , L_184 , 5 ) == 0
&& ( V_9 == 0 || ! ISALPHA ( line [ V_9 - 1 ] ) )
) {
if( V_9 > V_312 ) fprintf ( V_311 , L_185 , V_9 - V_312 , & line [ V_312 ] ) ;
fprintf ( V_311 , L_68 , V_82 ) ;
V_9 += 4 ;
V_312 = V_9 + 1 ;
}
}
}
fprintf ( V_311 , L_68 , & line [ V_312 ] ) ;
}
}
T_2 T_5 * F_105 ( struct V_57 * V_66 )
{
static char V_314 [] = L_186 ;
char V_303 [ 1000 ] ;
T_5 * V_310 ;
char * V_315 ;
char * V_316 = NULL ;
char * V_143 ;
if ( V_148 != 0 ) {
if( F_102 ( V_148 , 004 ) == - 1 ) {
fprintf ( V_17 , L_187 ,
V_148 ) ;
V_66 -> V_83 ++ ;
return 0 ;
}
V_310 = fopen ( V_148 , L_143 ) ;
if( V_310 == 0 ) {
fprintf ( V_17 , L_188 ,
V_148 ) ;
V_66 -> V_83 ++ ;
return 0 ;
}
return V_310 ;
}
V_143 = strrchr ( V_66 -> V_81 , '.' ) ;
if( V_143 ) {
F_3 ( V_303 , L_189 , ( int ) ( V_143 - V_66 -> V_81 ) , V_66 -> V_81 ) ;
} else{
F_3 ( V_303 , L_190 , V_66 -> V_81 ) ;
}
if( F_102 ( V_303 , 004 ) == 0 ) {
V_315 = V_303 ;
} else if( F_102 ( V_314 , 004 ) == 0 ) {
V_315 = V_314 ;
} else{
V_316 = F_100 ( V_66 -> V_171 , V_314 , 0 ) ;
V_315 = V_316 ;
}
if( V_315 == 0 ) {
fprintf ( V_17 , L_187 ,
V_314 ) ;
V_66 -> V_83 ++ ;
return 0 ;
}
V_310 = fopen ( V_315 , L_143 ) ;
if( V_310 == 0 ) {
fprintf ( V_17 , L_188 , V_314 ) ;
V_66 -> V_83 ++ ;
}
if ( V_316 ) {
free ( V_316 ) ;
}
return V_310 ;
}
T_2 void F_106 ( T_5 * V_311 , int V_141 , char * V_81 )
{
fprintf ( V_311 , L_191 , V_141 ) ;
while( * V_81 ) {
if( * V_81 == '\\' ) putc ( '\\' , V_311 ) ;
putc ( * V_81 , V_311 ) ;
V_81 ++ ;
}
fprintf ( V_311 , L_192 ) ;
}
T_2 void F_107 ( T_5 * V_311 , struct V_57 * V_66 , char * V_6 , int * V_141 )
{
if( V_6 == 0 ) return;
while( * V_6 ) {
putc ( * V_6 , V_311 ) ;
if( * V_6 == '\n' ) ( * V_141 ) ++ ;
V_6 ++ ;
}
if( V_6 [ - 1 ] != '\n' ) {
putc ( '\n' , V_311 ) ;
( * V_141 ) ++ ;
}
if ( ! V_66 -> V_161 ) {
( * V_141 ) ++ ; F_106 ( V_311 , * V_141 , V_66 -> V_295 ) ;
}
return;
}
T_2 void F_108 (
T_5 * V_311 ,
struct V_37 * V_29 ,
struct V_57 * V_66 ,
int * V_141
) {
char * V_143 = 0 ;
if( V_29 -> type == V_79 ) {
V_143 = V_66 -> V_243 ;
if( V_143 == 0 ) return;
fprintf ( V_311 , L_193 ) ; ( * V_141 ) ++ ;
} else if( V_29 -> V_261 ) {
V_143 = V_29 -> V_261 ;
fprintf ( V_311 , L_193 ) ; ( * V_141 ) ++ ;
if( ! V_66 -> V_161 ) {
( * V_141 ) ++ ;
F_106 ( V_311 , V_29 -> V_262 , V_66 -> V_81 ) ;
}
} else if( V_66 -> V_244 ) {
V_143 = V_66 -> V_244 ;
if( V_143 == 0 ) return;
fprintf ( V_311 , L_193 ) ; ( * V_141 ) ++ ;
} else{
assert ( 0 ) ;
}
for(; * V_143 ; V_143 ++ ) {
if( * V_143 == '$' && V_143 [ 1 ] == '$' ) {
fprintf ( V_311 , L_194 , V_29 -> V_317 ) ;
V_143 ++ ;
continue;
}
if( * V_143 == '\n' ) ( * V_141 ) ++ ;
fputc ( * V_143 , V_311 ) ;
}
fprintf ( V_311 , L_15 ) ; ( * V_141 ) ++ ;
if ( ! V_66 -> V_161 ) {
( * V_141 ) ++ ; F_106 ( V_311 , * V_141 , V_66 -> V_295 ) ;
}
fprintf ( V_311 , L_195 ) ; ( * V_141 ) ++ ;
return;
}
T_2 int F_109 ( struct V_37 * V_29 , struct V_57 * V_66 )
{
int V_318 ;
if( V_29 -> type == V_79 ) {
V_318 = V_66 -> V_243 != 0 ;
} else{
V_318 = V_66 -> V_244 != 0 || V_29 -> V_261 != 0 ;
}
return V_318 ;
}
T_2 char * F_110 ( const char * V_319 , int V_52 , int V_320 , int V_321 ) {
static char V_322 [ 1 ] = { 0 } ;
static char * V_14 = 0 ;
static int V_323 = 0 ;
static int V_324 = 0 ;
int V_12 ;
char V_325 [ 40 ] ;
if( V_319 == 0 ) {
V_324 = 0 ;
return V_14 ;
}
if( V_52 <= 0 ) {
if( V_52 < 0 ) {
V_324 += V_52 ;
assert ( V_324 >= 0 ) ;
}
V_52 = F_58 ( V_319 ) ;
}
if( ( int ) ( V_52 + sizeof( V_325 ) * 2 + V_324 ) >= V_323 ) {
V_323 = ( int ) ( V_52 + sizeof( V_325 ) * 2 + V_324 + 200 ) ;
V_14 = ( char * ) realloc ( V_14 , V_323 ) ;
}
if( V_14 == 0 ) return V_322 ;
while( V_52 -- > 0 ) {
V_12 = * ( V_319 ++ ) ;
if( V_12 == '%' && V_52 > 0 && V_319 [ 0 ] == 'd' ) {
F_3 ( V_325 , L_196 , V_320 ) ;
V_320 = V_321 ;
F_4 ( & V_14 [ V_324 ] , V_325 ) ;
V_324 += F_58 ( & V_14 [ V_324 ] ) ;
V_319 ++ ;
V_52 -- ;
} else{
V_14 [ V_324 ++ ] = ( char ) V_12 ;
}
}
V_14 [ V_324 ] = 0 ;
return V_14 ;
}
T_2 void F_111 ( struct V_57 * V_66 , struct V_42 * V_34 ) {
char * V_143 , * V_58 ;
int V_9 ;
char V_326 = 0 ;
char V_324 [ V_232 ] ;
for( V_9 = 0 ; V_9 < V_34 -> V_60 ; V_9 ++ ) V_324 [ V_9 ] = 0 ;
V_326 = 0 ;
if( V_34 -> V_222 == 0 ) {
static char V_327 [ 2 ] = { '\n' , '\0' } ;
V_34 -> V_222 = V_327 ;
V_34 -> line = V_34 -> V_115 ;
}
F_110 ( 0 , 0 , 0 , 0 ) ;
for( V_143 = ( char * ) V_34 -> V_222 ; * V_143 ; V_143 ++ ) {
if( ISALPHA ( * V_143 ) && ( V_143 == V_34 -> V_222 || ( ! ISALNUM ( V_143 [ - 1 ] ) && V_143 [ - 1 ] != '_' ) ) ) {
char V_328 ;
for( V_58 = & V_143 [ 1 ] ; ISALNUM ( * V_58 ) || * V_58 == '_' ; V_58 ++ ) ;
V_328 = * V_58 ;
* V_58 = 0 ;
if( V_34 -> V_219 && strcmp ( V_143 , V_34 -> V_219 ) == 0 ) {
F_110 ( L_197 , 0 , V_34 -> V_74 -> V_317 , 0 ) ;
V_143 = V_58 ;
V_326 = 1 ;
} else{
for( V_9 = 0 ; V_9 < V_34 -> V_60 ; V_9 ++ ) {
if( V_34 -> V_230 [ V_9 ] && strcmp ( V_143 , V_34 -> V_230 [ V_9 ] ) == 0 ) {
if( V_143 != V_34 -> V_222 && V_143 [ - 1 ] == '@' ) {
F_110 ( L_198 , - 1 , V_9 - V_34 -> V_60 + 1 , 0 ) ;
} else{
struct V_37 * V_29 = V_34 -> V_61 [ V_9 ] ;
int V_317 ;
if( V_29 -> type == V_62 ) {
V_317 = V_29 -> V_64 [ 0 ] -> V_317 ;
} else{
V_317 = V_29 -> V_317 ;
}
F_110 ( L_199 , 0 , V_9 - V_34 -> V_60 + 1 , V_317 ) ;
}
V_143 = V_58 ;
V_324 [ V_9 ] = 1 ;
break;
}
}
}
* V_58 = V_328 ;
}
F_110 ( V_143 , 1 , 0 , 0 ) ;
}
if( V_34 -> V_219 && ! V_326 ) {
F_22 ( V_66 -> V_81 , V_34 -> V_115 ,
L_200 ,
V_34 -> V_219 , V_34 -> V_74 -> V_82 , V_34 -> V_219 ) ;
V_66 -> V_83 ++ ;
}
for( V_9 = 0 ; V_9 < V_34 -> V_60 ; V_9 ++ ) {
if( V_34 -> V_230 [ V_9 ] && ! V_324 [ V_9 ] ) {
F_22 ( V_66 -> V_81 , V_34 -> V_115 ,
L_201 ,
V_34 -> V_230 [ V_9 ] , V_34 -> V_61 [ V_9 ] -> V_82 , V_34 -> V_230 [ V_9 ] ) ;
V_66 -> V_83 ++ ;
} else if( V_34 -> V_230 [ V_9 ] == 0 ) {
if( F_109 ( V_34 -> V_61 [ V_9 ] , V_66 ) ) {
F_110 ( L_202 , 0 ,
V_34 -> V_61 [ V_9 ] -> V_30 , V_9 - V_34 -> V_60 + 1 ) ;
} else{
}
}
}
if( V_34 -> V_222 ) {
V_143 = F_110 ( 0 , 0 , 0 , 0 ) ;
V_34 -> V_222 = F_91 ( V_143 ? V_143 : L_71 ) ;
}
}
T_2 void F_112 (
T_5 * V_311 ,
struct V_42 * V_34 ,
struct V_57 * V_66 ,
int * V_141
) {
const char * V_143 ;
if( V_34 -> V_222 ) {
if( ! V_66 -> V_161 ) {
( * V_141 ) ++ ;
F_106 ( V_311 , V_34 -> line , V_66 -> V_81 ) ;
}
fprintf ( V_311 , L_203 , V_34 -> V_222 ) ;
for( V_143 = V_34 -> V_222 ; * V_143 ; V_143 ++ ) {
if( * V_143 == '\n' ) ( * V_141 ) ++ ;
}
fprintf ( V_311 , L_195 ) ; ( * V_141 ) ++ ;
if( ! V_66 -> V_161 ) {
( * V_141 ) ++ ;
F_106 ( V_311 , * V_141 , V_66 -> V_295 ) ;
}
}
return;
}
T_2 void F_113 (
T_5 * V_311 ,
struct V_57 * V_66 ,
int * V_329 ,
int V_160
) {
int V_141 = * V_329 ;
char * * V_330 ;
int V_331 ;
int V_332 ;
char * V_333 ;
int V_9 , V_10 ;
unsigned V_334 ;
const char * V_82 ;
V_331 = V_66 -> V_68 * 2 ;
V_330 = ( char * * ) calloc ( V_331 , sizeof( char * ) ) ;
if( V_330 == 0 ) {
fprintf ( V_17 , L_204 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_331 ; V_9 ++ ) V_330 [ V_9 ] = 0 ;
V_332 = 0 ;
if( V_66 -> V_250 ) {
V_332 = F_58 ( V_66 -> V_250 ) ;
}
for( V_9 = 0 ; V_9 < V_66 -> V_68 ; V_9 ++ ) {
int V_206 ;
struct V_37 * V_29 = V_66 -> V_69 [ V_9 ] ;
if( V_29 -> V_263 == 0 ) continue;
V_206 = F_58 ( V_29 -> V_263 ) ;
if( V_206 > V_332 ) V_332 = V_206 ;
}
V_333 = ( char * ) malloc ( V_332 * 2 + 1 ) ;
if( V_333 == 0 ) {
fprintf ( V_17 , L_204 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_66 -> V_68 ; V_9 ++ ) {
struct V_37 * V_29 = V_66 -> V_69 [ V_9 ] ;
char * V_143 ;
if( V_29 == V_66 -> V_138 ) {
V_29 -> V_317 = V_331 + 1 ;
continue;
}
if( V_29 -> type != V_75 || ( V_29 -> V_263 == 0 && V_66 -> V_250 == 0 ) ) {
V_29 -> V_317 = 0 ;
continue;
}
V_143 = V_29 -> V_263 ;
if( V_143 == 0 ) V_143 = V_66 -> V_250 ;
V_10 = 0 ;
while( ISSPACE ( * V_143 ) ) V_143 ++ ;
while( * V_143 ) V_333 [ V_10 ++ ] = * V_143 ++ ;
while( V_10 > 0 && ISSPACE ( V_333 [ V_10 - 1 ] ) ) V_10 -- ;
V_333 [ V_10 ] = 0 ;
if( V_66 -> V_249 && strcmp ( V_333 , V_66 -> V_249 ) == 0 ) {
V_29 -> V_317 = 0 ;
continue;
}
V_334 = 0 ;
for( V_10 = 0 ; V_333 [ V_10 ] ; V_10 ++ ) {
V_334 = V_334 * 53 + V_333 [ V_10 ] ;
}
V_334 = ( V_334 & 0x7fffffff ) % V_331 ;
while( V_330 [ V_334 ] ) {
if( strcmp ( V_330 [ V_334 ] , V_333 ) == 0 ) {
V_29 -> V_317 = V_334 + 1 ;
break;
}
V_334 ++ ;
if( V_334 >= ( unsigned ) V_331 ) V_334 = 0 ;
}
if( V_330 [ V_334 ] == 0 ) {
V_29 -> V_317 = V_334 + 1 ;
V_330 [ V_334 ] = ( char * ) malloc ( F_58 ( V_333 ) + 1 ) ;
if( V_330 [ V_334 ] == 0 ) {
fprintf ( V_17 , L_204 ) ;
exit ( 1 ) ;
}
F_4 ( V_330 [ V_334 ] , V_333 ) ;
}
}
V_82 = V_66 -> V_82 ? V_66 -> V_82 : L_184 ;
if( V_160 ) { fprintf ( V_311 , L_205 ) ; V_141 ++ ; }
fprintf ( V_311 , L_206 , V_82 ,
V_66 -> V_249 ? V_66 -> V_249 : L_207 ) ; V_141 ++ ;
if( V_160 ) { fprintf ( V_311 , L_208 ) ; V_141 ++ ; }
fprintf ( V_311 , L_209 ) ; V_141 ++ ;
fprintf ( V_311 , L_210 ) ; V_141 ++ ;
fprintf ( V_311 , L_211 , V_82 ) ; V_141 ++ ;
for( V_9 = 0 ; V_9 < V_331 ; V_9 ++ ) {
if( V_330 [ V_9 ] == 0 ) continue;
fprintf ( V_311 , L_212 , V_330 [ V_9 ] , V_9 + 1 ) ; V_141 ++ ;
free ( V_330 [ V_9 ] ) ;
}
if( V_66 -> V_138 -> V_172 ) {
fprintf ( V_311 , L_213 , V_66 -> V_138 -> V_317 ) ; V_141 ++ ;
}
free ( V_333 ) ;
free ( V_330 ) ;
fprintf ( V_311 , L_214 ) ; V_141 ++ ;
* V_329 = V_141 ;
}
static const char * F_114 ( int V_335 , int V_336 , int * V_337 ) {
const char * V_338 = L_215 ;
int V_339 = 4 ;
if( V_335 >= 0 ) {
if( V_336 <= 255 ) {
V_338 = L_216 ;
V_339 = 1 ;
} else if( V_336 < 65535 ) {
V_338 = L_217 ;
V_339 = 2 ;
} else{
V_338 = L_218 ;
V_339 = 4 ;
}
} else if( V_335 >= - 127 && V_336 <= 127 ) {
V_338 = L_219 ;
V_339 = 1 ;
} else if( V_335 >= - 32767 && V_336 < 32767 ) {
V_338 = L_220 ;
V_339 = 2 ;
}
if( V_337 ) * V_337 = V_339 ;
return V_338 ;
}
static int F_115 ( const void * V_96 , const void * V_97 ) {
const struct V_340 * V_320 = ( const struct V_340 * ) V_96 ;
const struct V_340 * V_321 = ( const struct V_340 * ) V_97 ;
int V_12 ;
V_12 = V_321 -> V_53 - V_320 -> V_53 ;
if( V_12 == 0 ) {
V_12 = V_320 -> V_341 - V_321 -> V_341 ;
}
assert ( V_12 != 0 || V_320 == V_321 ) ;
return V_12 ;
}
static void F_116 ( T_5 * V_311 , struct V_42 * V_34 ) {
int V_10 ;
fprintf ( V_311 , L_159 , V_34 -> V_74 -> V_82 ) ;
for( V_10 = 0 ; V_10 < V_34 -> V_60 ; V_10 ++ ) {
struct V_37 * V_29 = V_34 -> V_61 [ V_10 ] ;
if( V_29 -> type != V_62 ) {
fprintf ( V_311 , L_69 , V_29 -> V_82 ) ;
} else{
int V_11 ;
fprintf ( V_311 , L_69 , V_29 -> V_64 [ 0 ] -> V_82 ) ;
for( V_11 = 1 ; V_11 < V_29 -> V_63 ; V_11 ++ ) {
fprintf ( V_311 , L_156 , V_29 -> V_64 [ V_11 ] -> V_82 ) ;
}
}
}
}
void F_77 (
struct V_57 * V_66 ,
int V_160
) {
T_5 * V_311 , * V_310 ;
char line [ V_313 ] ;
int V_141 ;
struct V_41 * V_40 ;
struct V_22 * V_8 ;
struct V_42 * V_34 ;
struct T_3 * V_342 ;
int V_9 , V_10 , V_52 , V_343 ;
int V_344 ;
int V_345 ;
const char * V_82 ;
int V_346 , V_347 ;
int V_348 , V_349 ;
struct V_340 * V_350 ;
V_310 = F_105 ( V_66 ) ;
if( V_310 == 0 ) return;
V_311 = F_96 ( V_66 , L_221 , L_171 ) ;
if( V_311 == 0 ) {
fclose ( V_310 ) ;
return;
}
V_141 = 1 ;
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
F_107 ( V_311 , V_66 , V_66 -> include , & V_141 ) ;
if( V_160 ) {
char * V_351 = F_94 ( V_66 , L_222 ) ;
fprintf ( V_311 , L_223 , V_351 ) ; V_141 ++ ;
free ( V_351 ) ;
}
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
if( V_160 ) {
const char * V_352 ;
fprintf ( V_311 , L_205 ) ; V_141 ++ ;
if( V_66 -> V_245 ) V_352 = V_66 -> V_245 ;
else V_352 = L_71 ;
for( V_9 = 1 ; V_9 < V_66 -> V_72 ; V_9 ++ ) {
fprintf ( V_311 , L_224 , V_352 , V_66 -> V_69 [ V_9 ] -> V_82 , V_9 ) ;
V_141 ++ ;
}
fprintf ( V_311 , L_208 ) ; V_141 ++ ;
}
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
fprintf ( V_311 , L_225 ,
F_114 ( 0 , V_66 -> V_68 + 1 , & V_345 ) ) ; V_141 ++ ;
fprintf ( V_311 , L_226 , V_66 -> V_68 + 1 ) ; V_141 ++ ;
fprintf ( V_311 , L_227 ,
F_114 ( 0 , V_66 -> V_95 + V_66 -> V_174 * 2 + 5 , & V_344 ) ) ; V_141 ++ ;
if( V_66 -> V_273 ) {
fprintf ( V_311 , L_228 ,
V_66 -> V_273 -> V_30 ) ; V_141 ++ ;
}
F_113 ( V_311 , V_66 , & V_141 , V_160 ) ;
fprintf ( V_311 , L_229 ) ; V_141 ++ ;
if( V_66 -> V_251 ) {
fprintf ( V_311 , L_230 , V_66 -> V_251 ) ; V_141 ++ ;
} else{
fprintf ( V_311 , L_231 ) ; V_141 ++ ;
}
fprintf ( V_311 , L_208 ) ; V_141 ++ ;
if( V_160 ) {
fprintf ( V_311 , L_205 ) ; V_141 ++ ;
}
V_82 = V_66 -> V_82 ? V_66 -> V_82 : L_184 ;
if( V_66 -> V_38 && V_66 -> V_38 [ 0 ] ) {
V_9 = F_58 ( V_66 -> V_38 ) ;
while( V_9 >= 1 && ISSPACE ( V_66 -> V_38 [ V_9 - 1 ] ) ) V_9 -- ;
while( V_9 >= 1 && ( ISALNUM ( V_66 -> V_38 [ V_9 - 1 ] ) || V_66 -> V_38 [ V_9 - 1 ] == '_' ) ) V_9 -- ;
fprintf ( V_311 , L_232 , V_82 , V_66 -> V_38 ) ; V_141 ++ ;
fprintf ( V_311 , L_233 , V_82 , V_66 -> V_38 ) ; V_141 ++ ;
fprintf ( V_311 , L_234 ,
V_82 , V_66 -> V_38 , & V_66 -> V_38 [ V_9 ] ) ; V_141 ++ ;
fprintf ( V_311 , L_235 ,
V_82 , & V_66 -> V_38 [ V_9 ] , & V_66 -> V_38 [ V_9 ] ) ; V_141 ++ ;
} else{
fprintf ( V_311 , L_236 , V_82 ) ; V_141 ++ ;
fprintf ( V_311 , L_237 , V_82 ) ; V_141 ++ ;
fprintf ( V_311 , L_238 , V_82 ) ; V_141 ++ ;
fprintf ( V_311 , L_239 , V_82 ) ; V_141 ++ ;
}
if( V_160 ) {
fprintf ( V_311 , L_208 ) ; V_141 ++ ;
}
if( V_66 -> V_138 -> V_172 ) {
fprintf ( V_311 , L_240 , V_66 -> V_138 -> V_30 ) ; V_141 ++ ;
fprintf ( V_311 , L_241 , V_66 -> V_138 -> V_317 ) ; V_141 ++ ;
}
if( V_66 -> V_272 ) {
fprintf ( V_311 , L_242 ) ; V_141 ++ ;
}
V_350 = (struct V_340 * ) calloc ( V_66 -> V_176 * 2 , sizeof( V_350 [ 0 ] ) ) ;
if( V_350 == 0 ) {
fprintf ( V_17 , L_8 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_66 -> V_176 ; V_9 ++ ) {
V_40 = V_66 -> V_109 [ V_9 ] ;
V_350 [ V_9 * 2 ] . V_40 = V_40 ;
V_350 [ V_9 * 2 ] . V_353 = 1 ;
V_350 [ V_9 * 2 ] . V_53 = V_40 -> V_354 ;
V_350 [ V_9 * 2 + 1 ] . V_40 = V_40 ;
V_350 [ V_9 * 2 + 1 ] . V_353 = 0 ;
V_350 [ V_9 * 2 + 1 ] . V_53 = V_40 -> V_355 ;
}
V_347 = V_346 = 0 ;
V_349 = V_348 = 0 ;
for( V_9 = 0 ; V_9 < V_66 -> V_176 * 2 ; V_9 ++ ) V_350 [ V_9 ] . V_341 = V_9 ;
qsort ( V_350 , V_66 -> V_176 * 2 , sizeof( V_350 [ 0 ] ) , F_115 ) ;
V_342 = F_11 () ;
for( V_9 = 0 ; V_9 < V_66 -> V_176 * 2 && V_350 [ V_9 ] . V_53 > 0 ; V_9 ++ ) {
V_40 = V_350 [ V_9 ] . V_40 ;
if( V_350 [ V_9 ] . V_353 ) {
for( V_8 = V_40 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
int V_22 ;
if( V_8 -> V_29 -> V_30 >= V_66 -> V_72 ) continue;
V_22 = F_103 ( V_66 , V_8 ) ;
if( V_22 < 0 ) continue;
F_12 ( V_342 , V_8 -> V_29 -> V_30 , V_22 ) ;
}
V_40 -> V_356 = F_13 ( V_342 ) ;
if( V_40 -> V_356 < V_346 ) V_346 = V_40 -> V_356 ;
if( V_40 -> V_356 > V_347 ) V_347 = V_40 -> V_356 ;
} else{
for( V_8 = V_40 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
int V_22 ;
if( V_8 -> V_29 -> V_30 < V_66 -> V_72 ) continue;
if( V_8 -> V_29 -> V_30 == V_66 -> V_68 ) continue;
V_22 = F_103 ( V_66 , V_8 ) ;
if( V_22 < 0 ) continue;
F_12 ( V_342 , V_8 -> V_29 -> V_30 , V_22 ) ;
}
V_40 -> V_357 = F_13 ( V_342 ) ;
if( V_40 -> V_357 < V_348 ) V_348 = V_40 -> V_357 ;
if( V_40 -> V_357 > V_349 ) V_349 = V_40 -> V_357 ;
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
free ( V_350 ) ;
fprintf ( V_311 , L_243 , V_66 -> V_176 ) ; V_141 ++ ;
fprintf ( V_311 , L_244 , V_66 -> V_174 ) ; V_141 ++ ;
fprintf ( V_311 , L_245 , V_66 -> V_176 - 1 ) ; V_141 ++ ;
fprintf ( V_311 , L_246 , V_66 -> V_95 ) ; V_141 ++ ;
V_9 = V_66 -> V_95 + V_66 -> V_174 ;
fprintf ( V_311 , L_247 , V_9 - 1 ) ; V_141 ++ ;
fprintf ( V_311 , L_248 , V_9 ) ; V_141 ++ ;
V_9 = V_66 -> V_95 + V_66 -> V_174 * 2 ;
fprintf ( V_311 , L_249 , V_9 - 1 ) ; V_141 ++ ;
fprintf ( V_311 , L_250 , V_9 ) ; V_141 ++ ;
fprintf ( V_311 , L_251 , V_9 + 1 ) ; V_141 ++ ;
fprintf ( V_311 , L_252 , V_9 + 2 ) ; V_141 ++ ;
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
V_66 -> V_177 = V_52 = F_117 ( V_342 ) ;
V_66 -> V_178 += V_52 * V_344 ;
fprintf ( V_311 , L_253 , V_52 ) ; V_141 ++ ;
fprintf ( V_311 , L_254 ) ; V_141 ++ ;
for( V_9 = V_10 = 0 ; V_9 < V_52 ; V_9 ++ ) {
int V_22 = F_118 ( V_342 , V_9 ) ;
if( V_22 < 0 ) V_22 = V_66 -> V_95 + V_66 -> V_174 + 2 ;
if( V_10 == 0 ) fprintf ( V_311 , L_255 , V_9 ) ;
fprintf ( V_311 , L_256 , V_22 ) ;
if( V_10 == 9 || V_9 == V_52 - 1 ) {
fprintf ( V_311 , L_15 ) ; V_141 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_311 , L_257 ) ; V_141 ++ ;
V_66 -> V_178 += V_52 * V_345 ;
fprintf ( V_311 , L_258 ) ; V_141 ++ ;
for( V_9 = V_10 = 0 ; V_9 < V_52 ; V_9 ++ ) {
int V_358 = F_119 ( V_342 , V_9 ) ;
if( V_358 < 0 ) V_358 = V_66 -> V_68 ;
if( V_10 == 0 ) fprintf ( V_311 , L_255 , V_9 ) ;
fprintf ( V_311 , L_256 , V_358 ) ;
if( V_10 == 9 || V_9 == V_52 - 1 ) {
fprintf ( V_311 , L_15 ) ; V_141 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_311 , L_257 ) ; V_141 ++ ;
fprintf ( V_311 , L_259 , V_346 - 1 ) ; V_141 ++ ;
V_52 = V_66 -> V_176 ;
while( V_52 > 0 && V_66 -> V_109 [ V_52 - 1 ] -> V_356 == V_359 ) V_52 -- ;
fprintf ( V_311 , L_260 , V_52 - 1 ) ; V_141 ++ ;
fprintf ( V_311 , L_261 , V_346 ) ; V_141 ++ ;
fprintf ( V_311 , L_262 , V_347 ) ; V_141 ++ ;
fprintf ( V_311 , L_263 ,
F_114 ( V_346 - 1 , V_347 , & V_343 ) ) ; V_141 ++ ;
V_66 -> V_178 += V_52 * V_343 ;
for( V_9 = V_10 = 0 ; V_9 < V_52 ; V_9 ++ ) {
int V_360 ;
V_40 = V_66 -> V_109 [ V_9 ] ;
V_360 = V_40 -> V_356 ;
if( V_360 == V_359 ) V_360 = V_346 - 1 ;
if( V_10 == 0 ) fprintf ( V_311 , L_255 , V_9 ) ;
fprintf ( V_311 , L_256 , V_360 ) ;
if( V_10 == 9 || V_9 == V_52 - 1 ) {
fprintf ( V_311 , L_15 ) ; V_141 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_311 , L_257 ) ; V_141 ++ ;
fprintf ( V_311 , L_264 , V_348 - 1 ) ; V_141 ++ ;
V_52 = V_66 -> V_176 ;
while( V_52 > 0 && V_66 -> V_109 [ V_52 - 1 ] -> V_357 == V_359 ) V_52 -- ;
fprintf ( V_311 , L_265 , V_52 - 1 ) ; V_141 ++ ;
fprintf ( V_311 , L_266 , V_348 ) ; V_141 ++ ;
fprintf ( V_311 , L_267 , V_349 ) ; V_141 ++ ;
fprintf ( V_311 , L_268 ,
F_114 ( V_348 - 1 , V_349 , & V_343 ) ) ; V_141 ++ ;
V_66 -> V_178 += V_52 * V_343 ;
for( V_9 = V_10 = 0 ; V_9 < V_52 ; V_9 ++ ) {
int V_360 ;
V_40 = V_66 -> V_109 [ V_9 ] ;
V_360 = V_40 -> V_357 ;
if( V_360 == V_359 ) V_360 = V_348 - 1 ;
if( V_10 == 0 ) fprintf ( V_311 , L_255 , V_9 ) ;
fprintf ( V_311 , L_256 , V_360 ) ;
if( V_10 == 9 || V_9 == V_52 - 1 ) {
fprintf ( V_311 , L_15 ) ; V_141 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_311 , L_257 ) ; V_141 ++ ;
fprintf ( V_311 , L_269 ) ; V_141 ++ ;
V_52 = V_66 -> V_176 ;
V_66 -> V_178 += V_52 * V_344 ;
for( V_9 = V_10 = 0 ; V_9 < V_52 ; V_9 ++ ) {
V_40 = V_66 -> V_109 [ V_9 ] ;
if( V_10 == 0 ) fprintf ( V_311 , L_255 , V_9 ) ;
fprintf ( V_311 , L_256 , V_40 -> V_361 + V_66 -> V_95 + V_66 -> V_174 ) ;
if( V_10 == 9 || V_9 == V_52 - 1 ) {
fprintf ( V_311 , L_15 ) ; V_141 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_311 , L_257 ) ; V_141 ++ ;
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
if( V_66 -> V_272 ) {
int V_362 = V_66 -> V_72 - 1 ;
while( V_362 > 0 && V_66 -> V_69 [ V_362 ] -> V_256 == 0 ) { V_362 -- ; }
V_66 -> V_178 += ( V_362 + 1 ) * V_345 ;
for( V_9 = 0 ; V_9 <= V_362 ; V_9 ++ ) {
struct V_37 * V_43 = V_66 -> V_69 [ V_9 ] ;
if( V_43 -> V_256 == 0 ) {
fprintf ( V_311 , L_270 , V_43 -> V_82 ) ;
} else{
fprintf ( V_311 , L_271 , V_43 -> V_256 -> V_30 ,
V_43 -> V_82 , V_43 -> V_256 -> V_82 ) ;
}
V_141 ++ ;
}
}
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
for( V_9 = 0 ; V_9 < V_66 -> V_68 ; V_9 ++ ) {
F_3 ( line , L_272 , V_66 -> V_69 [ V_9 ] -> V_82 ) ;
fprintf ( V_311 , L_273 , line ) ;
if( ( V_9 & 3 ) == 3 ) { fprintf ( V_311 , L_15 ) ; V_141 ++ ; }
}
if( ( V_9 & 3 ) != 0 ) { fprintf ( V_311 , L_15 ) ; V_141 ++ ; }
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
for( V_9 = 0 , V_34 = V_66 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 , V_9 ++ ) {
assert ( V_34 -> V_30 == V_9 ) ;
fprintf ( V_311 , L_274 , V_9 ) ;
F_116 ( V_311 , V_34 ) ;
fprintf ( V_311 , L_275 ) ; V_141 ++ ;
}
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
if( V_66 -> V_243 ) {
int V_363 = 1 ;
for( V_9 = 0 ; V_9 < V_66 -> V_68 ; V_9 ++ ) {
struct V_37 * V_29 = V_66 -> V_69 [ V_9 ] ;
if( V_29 == 0 || V_29 -> type != V_79 ) continue;
if( V_363 ) {
fprintf ( V_311 , L_276 ) ; V_141 ++ ;
V_363 = 0 ;
}
fprintf ( V_311 , L_277 , V_29 -> V_30 , V_29 -> V_82 ) ; V_141 ++ ;
}
for( V_9 = 0 ; V_9 < V_66 -> V_68 && V_66 -> V_69 [ V_9 ] -> type != V_79 ; V_9 ++ ) ;
if( V_9 < V_66 -> V_68 ) {
F_108 ( V_311 , V_66 -> V_69 [ V_9 ] , V_66 , & V_141 ) ;
fprintf ( V_311 , L_278 ) ; V_141 ++ ;
}
}
if( V_66 -> V_244 ) {
struct V_37 * V_364 = 0 ;
int V_363 = 1 ;
for( V_9 = 0 ; V_9 < V_66 -> V_68 ; V_9 ++ ) {
struct V_37 * V_29 = V_66 -> V_69 [ V_9 ] ;
if( V_29 == 0 || V_29 -> type == V_79 ||
V_29 -> V_30 <= 0 || V_29 -> V_261 != 0 ) continue;
if( V_363 ) {
fprintf ( V_311 , L_279 ) ; V_141 ++ ;
V_363 = 0 ;
}
fprintf ( V_311 , L_277 , V_29 -> V_30 , V_29 -> V_82 ) ; V_141 ++ ;
V_364 = V_29 ;
}
if( V_364 != 0 ) {
F_108 ( V_311 , V_364 , V_66 , & V_141 ) ;
}
fprintf ( V_311 , L_278 ) ; V_141 ++ ;
}
for( V_9 = 0 ; V_9 < V_66 -> V_68 ; V_9 ++ ) {
struct V_37 * V_29 = V_66 -> V_69 [ V_9 ] ;
if( V_29 == 0 || V_29 -> type == V_79 || V_29 -> V_261 == 0 ) continue;
fprintf ( V_311 , L_277 , V_29 -> V_30 , V_29 -> V_82 ) ; V_141 ++ ;
for( V_10 = V_9 + 1 ; V_10 < V_66 -> V_68 ; V_10 ++ ) {
struct V_37 * V_365 = V_66 -> V_69 [ V_10 ] ;
if( V_365 && V_365 -> type != V_79 && V_365 -> V_261
&& V_365 -> V_317 == V_29 -> V_317
&& strcmp ( V_29 -> V_261 , V_365 -> V_261 ) == 0 ) {
fprintf ( V_311 , L_277 ,
V_365 -> V_30 , V_365 -> V_82 ) ; V_141 ++ ;
V_365 -> V_261 = 0 ;
}
}
F_108 ( V_311 , V_66 -> V_69 [ V_9 ] , V_66 , & V_141 ) ;
fprintf ( V_311 , L_278 ) ; V_141 ++ ;
}
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
F_107 ( V_311 , V_66 , V_66 -> V_248 , & V_141 ) ;
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
for( V_34 = V_66 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 ) {
fprintf ( V_311 , L_280 , V_34 -> V_74 -> V_30 , V_34 -> V_60 ) ; V_141 ++ ;
}
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
for( V_34 = V_66 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 ) {
F_111 ( V_66 , V_34 ) ;
}
for( V_34 = V_66 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 ) {
struct V_42 * V_366 ;
if( V_34 -> V_222 == 0 ) continue;
if( V_34 -> V_222 [ 0 ] == '\n' && V_34 -> V_222 [ 1 ] == 0 ) continue;
fprintf ( V_311 , L_281 , V_34 -> V_30 ) ;
F_116 ( V_311 , V_34 ) ;
fprintf ( V_311 , L_282 ) ; V_141 ++ ;
for( V_366 = V_34 -> V_26 ; V_366 ; V_366 = V_366 -> V_26 ) {
if( V_366 -> V_222 == V_34 -> V_222 ) {
fprintf ( V_311 , L_281 , V_366 -> V_30 ) ;
F_116 ( V_311 , V_366 ) ;
fprintf ( V_311 , L_283 , V_366 -> V_30 ) ; V_141 ++ ;
V_366 -> V_222 = 0 ;
}
}
F_112 ( V_311 , V_34 , V_66 , & V_141 ) ;
fprintf ( V_311 , L_284 ) ; V_141 ++ ;
V_34 -> V_222 = 0 ;
}
fprintf ( V_311 , L_285 ) ; V_141 ++ ;
for( V_34 = V_66 -> V_42 ; V_34 ; V_34 = V_34 -> V_26 ) {
if( V_34 -> V_222 == 0 ) continue;
assert ( V_34 -> V_222 [ 0 ] == '\n' && V_34 -> V_222 [ 1 ] == 0 ) ;
fprintf ( V_311 , L_286 , V_34 -> V_30 ) ;
F_116 ( V_311 , V_34 ) ;
fprintf ( V_311 , L_283 , V_34 -> V_30 ) ; V_141 ++ ;
}
fprintf ( V_311 , L_284 ) ; V_141 ++ ;
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
F_107 ( V_311 , V_66 , V_66 -> V_247 , & V_141 ) ;
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
F_107 ( V_311 , V_66 , V_66 -> error , & V_141 ) ;
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
F_107 ( V_311 , V_66 , V_66 -> V_246 , & V_141 ) ;
F_104 ( V_66 -> V_82 , V_310 , V_311 , & V_141 ) ;
F_107 ( V_311 , V_66 , V_66 -> V_242 , & V_141 ) ;
fclose ( V_310 ) ;
fclose ( V_311 ) ;
return;
}
void F_78 ( struct V_57 * V_66 )
{
T_5 * V_311 , * V_310 ;
const char * V_352 ;
char line [ V_313 ] ;
char V_367 [ V_313 ] ;
int V_9 ;
if( V_66 -> V_245 ) V_352 = V_66 -> V_245 ;
else V_352 = L_71 ;
V_310 = F_96 ( V_66 , L_222 , L_143 ) ;
if( V_310 ) {
int V_368 ;
for( V_9 = 1 ; V_9 < V_66 -> V_72 && fgets ( line , V_313 , V_310 ) ; V_9 ++ ) {
F_3 ( V_367 , L_287 ,
V_352 , V_66 -> V_69 [ V_9 ] -> V_82 , V_9 ) ;
if( strcmp ( line , V_367 ) ) break;
}
V_368 = fgetc ( V_310 ) ;
fclose ( V_310 ) ;
if( V_9 == V_66 -> V_72 && V_368 == V_369 ) {
return;
}
}
V_311 = F_96 ( V_66 , L_222 , L_171 ) ;
if( V_311 ) {
for( V_9 = 1 ; V_9 < V_66 -> V_72 ; V_9 ++ ) {
fprintf ( V_311 , L_287 , V_352 , V_66 -> V_69 [ V_9 ] -> V_82 , V_9 ) ;
}
fclose ( V_311 ) ;
}
return;
}
void F_74 ( struct V_57 * V_66 )
{
struct V_41 * V_40 ;
struct V_22 * V_8 , * V_28 ;
struct V_42 * V_34 , * V_366 , * V_370 ;
int V_371 , V_52 ;
int V_9 ;
int V_372 ;
for( V_9 = 0 ; V_9 < V_66 -> V_95 ; V_9 ++ ) {
V_40 = V_66 -> V_109 [ V_9 ] ;
V_371 = 0 ;
V_370 = 0 ;
V_372 = 0 ;
for( V_8 = V_40 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_39 && V_8 -> V_29 == V_66 -> V_273 ) {
V_372 = 1 ;
}
if( V_8 -> type != V_31 ) continue;
V_34 = V_8 -> V_33 . V_34 ;
if( V_34 -> V_87 ) continue;
if( V_34 == V_370 ) continue;
V_52 = 1 ;
for( V_28 = V_8 -> V_26 ; V_28 ; V_28 = V_28 -> V_26 ) {
if( V_28 -> type != V_31 ) continue;
V_366 = V_28 -> V_33 . V_34 ;
if( V_366 == V_370 ) continue;
if( V_366 == V_34 ) V_52 ++ ;
}
if( V_52 > V_371 ) {
V_371 = V_52 ;
V_370 = V_34 ;
}
}
if( V_371 < 1 || V_372 ) continue;
for( V_8 = V_40 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_31 && V_8 -> V_33 . V_34 == V_370 ) break;
}
assert ( V_8 ) ;
V_8 -> V_29 = F_67 ( L_57 ) ;
for( V_8 = V_8 -> V_26 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_31 && V_8 -> V_33 . V_34 == V_370 ) V_8 -> type = V_302 ;
}
V_40 -> V_8 = F_8 ( V_40 -> V_8 ) ;
for( V_8 = V_40 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_39 ) break;
if( V_8 -> type == V_31 && V_8 -> V_33 . V_34 != V_370 ) break;
}
if( V_8 == 0 ) {
V_40 -> V_373 = 1 ;
V_40 -> V_374 = V_370 ;
}
}
for( V_9 = 0 ; V_9 < V_66 -> V_95 ; V_9 ++ ) {
V_40 = V_66 -> V_109 [ V_9 ] ;
for( V_8 = V_40 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
struct V_41 * V_375 ;
if( V_8 -> type != V_39 ) continue;
V_375 = V_8 -> V_33 . V_40 ;
if( V_375 -> V_373 && V_375 -> V_374 != 0 ) {
V_8 -> type = V_32 ;
V_8 -> V_33 . V_34 = V_375 -> V_374 ;
}
}
}
}
static int F_120 ( const void * V_96 , const void * V_97 ) {
const struct V_41 * V_376 = * ( const struct V_41 * const * ) V_96 ;
const struct V_41 * V_377 = * ( const struct V_41 * const * ) V_97 ;
int V_52 ;
V_52 = V_377 -> V_355 - V_376 -> V_355 ;
if( V_52 == 0 ) {
V_52 = V_377 -> V_354 - V_376 -> V_354 ;
if( V_52 == 0 ) {
V_52 = V_377 -> V_94 - V_376 -> V_94 ;
}
}
assert ( V_52 != 0 ) ;
return V_52 ;
}
void F_75 ( struct V_57 * V_66 )
{
int V_9 ;
struct V_41 * V_40 ;
struct V_22 * V_8 ;
for( V_9 = 0 ; V_9 < V_66 -> V_95 ; V_9 ++ ) {
V_40 = V_66 -> V_109 [ V_9 ] ;
V_40 -> V_354 = V_40 -> V_355 = 0 ;
V_40 -> V_361 = V_66 -> V_174 ;
V_40 -> V_356 = V_359 ;
V_40 -> V_357 = V_359 ;
for( V_8 = V_40 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
int V_378 = F_103 ( V_66 , V_8 ) ;
if( V_378 >= 0 ) {
if( V_8 -> V_29 -> V_30 < V_66 -> V_72 ) {
V_40 -> V_354 ++ ;
} else if( V_8 -> V_29 -> V_30 < V_66 -> V_68 ) {
V_40 -> V_355 ++ ;
} else{
assert ( V_40 -> V_373 == 0 || V_40 -> V_374 == V_8 -> V_33 . V_34 ) ;
V_40 -> V_361 = V_378 - V_66 -> V_95 - V_66 -> V_174 ;
}
}
}
}
qsort ( & V_66 -> V_109 [ 1 ] , V_66 -> V_95 - 1 , sizeof( V_66 -> V_109 [ 0 ] ) ,
F_120 ) ;
for( V_9 = 0 ; V_9 < V_66 -> V_95 ; V_9 ++ ) {
V_66 -> V_109 [ V_9 ] -> V_94 = V_9 ;
}
V_66 -> V_176 = V_66 -> V_95 ;
while( V_66 -> V_176 > 1 && V_66 -> V_109 [ V_66 -> V_176 - 1 ] -> V_373 ) {
V_66 -> V_176 -- ;
}
}
void F_72 ( int V_52 )
{
V_379 = V_52 + 1 ;
}
char * F_16 ( void ) {
char * V_380 ;
V_380 = ( char * ) calloc ( V_379 , 1 ) ;
if( V_380 == 0 ) {
F_54 () ;
}
return V_380 ;
}
void F_53 ( char * V_380 )
{
free ( V_380 ) ;
}
int F_17 ( char * V_380 , int V_381 )
{
int V_382 ;
assert ( V_381 >= 0 && V_381 < V_379 ) ;
V_382 = V_380 [ V_381 ] ;
V_380 [ V_381 ] = 1 ;
return ! V_382 ;
}
int F_18 ( char * V_77 , char * V_78 )
{
int V_9 , V_67 ;
V_67 = 0 ;
for( V_9 = 0 ; V_9 < V_379 ; V_9 ++ ) {
if( V_78 [ V_9 ] == 0 ) continue;
if( V_77 [ V_9 ] == 0 ) {
V_67 = 1 ;
V_77 [ V_9 ] = 1 ;
}
}
return V_67 ;
}
T_2 unsigned F_121 ( const char * V_33 )
{
unsigned V_383 = 0 ;
while( * V_33 ) V_383 = V_383 * 13 + * ( V_33 ++ ) ;
return V_383 ;
}
const char * F_91 ( const char * V_91 )
{
const char * V_14 ;
char * V_384 ;
if( V_91 == 0 ) return 0 ;
V_14 = F_122 ( V_91 ) ;
if( V_14 == 0 && ( V_384 = ( char * ) malloc ( F_58 ( V_91 ) + 1 ) ) != 0 ) {
F_4 ( V_384 , V_91 ) ;
V_14 = V_384 ;
F_123 ( V_14 ) ;
}
F_35 ( V_14 ) ;
return V_14 ;
}
void F_63 ( void ) {
if( V_385 ) return;
V_385 = (struct V_386 * ) malloc ( sizeof( struct V_386 ) ) ;
if( V_385 ) {
V_385 -> V_379 = 1024 ;
V_385 -> V_387 = 0 ;
V_385 -> V_388 = ( V_389 * ) calloc ( 1024 , sizeof( V_389 ) + sizeof( V_389 * ) ) ;
if( V_385 -> V_388 == 0 ) {
free ( V_385 ) ;
V_385 = 0 ;
} else{
int V_9 ;
V_385 -> V_390 = ( V_389 * * ) & ( V_385 -> V_388 [ 1024 ] ) ;
for( V_9 = 0 ; V_9 < 1024 ; V_9 ++ ) V_385 -> V_390 [ V_9 ] = 0 ;
}
}
}
int F_123 ( const char * V_391 )
{
V_389 * V_392 ;
unsigned V_383 ;
unsigned V_393 ;
if( V_385 == 0 ) return 0 ;
V_393 = F_121 ( V_391 ) ;
V_383 = V_393 & ( V_385 -> V_379 - 1 ) ;
V_392 = V_385 -> V_390 [ V_383 ] ;
while( V_392 ) {
if( strcmp ( V_392 -> V_391 , V_391 ) == 0 ) {
return 0 ;
}
V_392 = V_392 -> V_26 ;
}
if( V_385 -> V_387 >= V_385 -> V_379 ) {
int V_9 , V_394 ;
struct V_386 V_395 ;
V_395 . V_379 = V_394 = V_385 -> V_379 * 2 ;
V_395 . V_387 = V_385 -> V_387 ;
V_395 . V_388 = ( V_389 * ) calloc ( V_394 , sizeof( V_389 ) + sizeof( V_389 * ) ) ;
if( V_395 . V_388 == 0 ) return 0 ;
V_395 . V_390 = ( V_389 * * ) & ( V_395 . V_388 [ V_394 ] ) ;
for( V_9 = 0 ; V_9 < V_394 ; V_9 ++ ) V_395 . V_390 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_385 -> V_387 ; V_9 ++ ) {
V_389 * V_396 , * V_397 ;
V_396 = & ( V_385 -> V_388 [ V_9 ] ) ;
V_383 = F_121 ( V_396 -> V_391 ) & ( V_394 - 1 ) ;
V_397 = & ( V_395 . V_388 [ V_9 ] ) ;
if( V_395 . V_390 [ V_383 ] ) V_395 . V_390 [ V_383 ] -> V_291 = & ( V_397 -> V_26 ) ;
V_397 -> V_26 = V_395 . V_390 [ V_383 ] ;
V_397 -> V_391 = V_396 -> V_391 ;
V_397 -> V_291 = & ( V_395 . V_390 [ V_383 ] ) ;
V_395 . V_390 [ V_383 ] = V_397 ;
}
free ( V_385 -> V_388 ) ;
* V_385 = V_395 ;
}
V_383 = V_393 & ( V_385 -> V_379 - 1 ) ;
V_392 = & ( V_385 -> V_388 [ V_385 -> V_387 ++ ] ) ;
V_392 -> V_391 = V_391 ;
if( V_385 -> V_390 [ V_383 ] ) V_385 -> V_390 [ V_383 ] -> V_291 = & ( V_392 -> V_26 ) ;
V_392 -> V_26 = V_385 -> V_390 [ V_383 ] ;
V_385 -> V_390 [ V_383 ] = V_392 ;
V_392 -> V_291 = & ( V_385 -> V_390 [ V_383 ] ) ;
return 1 ;
}
const char * F_122 ( const char * V_398 )
{
unsigned V_383 ;
V_389 * V_392 ;
if( V_385 == 0 ) return 0 ;
V_383 = F_121 ( V_398 ) & ( V_385 -> V_379 - 1 ) ;
V_392 = V_385 -> V_390 [ V_383 ] ;
while( V_392 ) {
if( strcmp ( V_392 -> V_391 , V_398 ) == 0 ) break;
V_392 = V_392 -> V_26 ;
}
return V_392 ? V_392 -> V_391 : 0 ;
}
struct V_37 * F_67 ( const char * V_33 )
{
struct V_37 * V_29 ;
V_29 = F_21 ( V_33 ) ;
if( V_29 == 0 ) {
V_29 = (struct V_37 * ) calloc ( 1 , sizeof( struct V_37 ) ) ;
F_35 ( V_29 ) ;
V_29 -> V_82 = F_91 ( V_33 ) ;
V_29 -> type = ISUPPER ( * V_33 ) ? V_79 : V_75 ;
V_29 -> V_42 = 0 ;
V_29 -> V_256 = 0 ;
V_29 -> V_65 = - 1 ;
V_29 -> V_125 = V_399 ;
V_29 -> V_73 = 0 ;
V_29 -> V_70 = V_71 ;
V_29 -> V_261 = 0 ;
V_29 -> V_262 = 0 ;
V_29 -> V_263 = 0 ;
V_29 -> V_172 = 0 ;
F_124 ( V_29 , V_29 -> V_82 ) ;
}
V_29 -> V_172 ++ ;
return V_29 ;
}
int V_175 ( const void * V_400 , const void * V_401 )
{
const struct V_37 * V_96 = * ( const struct V_37 * const * ) V_400 ;
const struct V_37 * V_97 = * ( const struct V_37 * const * ) V_401 ;
int V_402 = V_96 -> type == V_62 ? 3 : V_96 -> V_82 [ 0 ] > 'Z' ? 2 : 1 ;
int V_403 = V_97 -> type == V_62 ? 3 : V_97 -> V_82 [ 0 ] > 'Z' ? 2 : 1 ;
return V_402 == V_403 ? V_96 -> V_30 - V_97 -> V_30 : V_402 - V_403 ;
}
void F_64 ( void ) {
if( V_404 ) return;
V_404 = (struct V_405 * ) malloc ( sizeof( struct V_405 ) ) ;
if( V_404 ) {
V_404 -> V_379 = 128 ;
V_404 -> V_387 = 0 ;
V_404 -> V_388 = ( V_406 * ) calloc ( 128 , sizeof( V_406 ) + sizeof( V_406 * ) ) ;
if( V_404 -> V_388 == 0 ) {
free ( V_404 ) ;
V_404 = 0 ;
} else{
int V_9 ;
V_404 -> V_390 = ( V_406 * * ) & ( V_404 -> V_388 [ 128 ] ) ;
for( V_9 = 0 ; V_9 < 128 ; V_9 ++ ) V_404 -> V_390 [ V_9 ] = 0 ;
}
}
}
int F_124 ( struct V_37 * V_391 , const char * V_398 )
{
V_406 * V_392 ;
unsigned V_383 ;
unsigned V_393 ;
if( V_404 == 0 ) return 0 ;
V_393 = F_121 ( V_398 ) ;
V_383 = V_393 & ( V_404 -> V_379 - 1 ) ;
V_392 = V_404 -> V_390 [ V_383 ] ;
while( V_392 ) {
if( strcmp ( V_392 -> V_398 , V_398 ) == 0 ) {
return 0 ;
}
V_392 = V_392 -> V_26 ;
}
if( V_404 -> V_387 >= V_404 -> V_379 ) {
int V_9 , V_394 ;
struct V_405 V_395 ;
V_395 . V_379 = V_394 = V_404 -> V_379 * 2 ;
V_395 . V_387 = V_404 -> V_387 ;
V_395 . V_388 = ( V_406 * ) calloc ( V_394 , sizeof( V_406 ) + sizeof( V_406 * ) ) ;
if( V_395 . V_388 == 0 ) return 0 ;
V_395 . V_390 = ( V_406 * * ) & ( V_395 . V_388 [ V_394 ] ) ;
for( V_9 = 0 ; V_9 < V_394 ; V_9 ++ ) V_395 . V_390 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_404 -> V_387 ; V_9 ++ ) {
V_406 * V_396 , * V_397 ;
V_396 = & ( V_404 -> V_388 [ V_9 ] ) ;
V_383 = F_121 ( V_396 -> V_398 ) & ( V_394 - 1 ) ;
V_397 = & ( V_395 . V_388 [ V_9 ] ) ;
if( V_395 . V_390 [ V_383 ] ) V_395 . V_390 [ V_383 ] -> V_291 = & ( V_397 -> V_26 ) ;
V_397 -> V_26 = V_395 . V_390 [ V_383 ] ;
V_397 -> V_398 = V_396 -> V_398 ;
V_397 -> V_391 = V_396 -> V_391 ;
V_397 -> V_291 = & ( V_395 . V_390 [ V_383 ] ) ;
V_395 . V_390 [ V_383 ] = V_397 ;
}
free ( V_404 -> V_388 ) ;
* V_404 = V_395 ;
}
V_383 = V_393 & ( V_404 -> V_379 - 1 ) ;
V_392 = & ( V_404 -> V_388 [ V_404 -> V_387 ++ ] ) ;
V_392 -> V_398 = V_398 ;
V_392 -> V_391 = V_391 ;
if( V_404 -> V_390 [ V_383 ] ) V_404 -> V_390 [ V_383 ] -> V_291 = & ( V_392 -> V_26 ) ;
V_392 -> V_26 = V_404 -> V_390 [ V_383 ] ;
V_404 -> V_390 [ V_383 ] = V_392 ;
V_392 -> V_291 = & ( V_404 -> V_390 [ V_383 ] ) ;
return 1 ;
}
struct V_37 * F_21 ( const char * V_398 )
{
unsigned V_383 ;
V_406 * V_392 ;
if( V_404 == 0 ) return 0 ;
V_383 = F_121 ( V_398 ) & ( V_404 -> V_379 - 1 ) ;
V_392 = V_404 -> V_390 [ V_383 ] ;
while( V_392 ) {
if( strcmp ( V_392 -> V_398 , V_398 ) == 0 ) break;
V_392 = V_392 -> V_26 ;
}
return V_392 ? V_392 -> V_391 : 0 ;
}
struct V_37 * F_125 ( int V_52 )
{
struct V_37 * V_391 ;
if( V_404 && V_52 > 0 && V_52 <= V_404 -> V_387 ) {
V_391 = V_404 -> V_388 [ V_52 - 1 ] . V_391 ;
} else{
V_391 = 0 ;
}
return V_391 ;
}
int F_69 ( void )
{
return V_404 ? V_404 -> V_387 : 0 ;
}
struct V_37 * * F_70 ( void )
{
struct V_37 * * V_395 ;
int V_9 , V_394 ;
if( V_404 == 0 ) return 0 ;
V_394 = V_404 -> V_387 ;
V_395 = (struct V_37 * * ) calloc ( V_394 , sizeof( struct V_37 * ) ) ;
if( V_395 ) {
for( V_9 = 0 ; V_9 < V_394 ; V_9 ++ ) V_395 [ V_9 ] = V_404 -> V_388 [ V_9 ] . V_391 ;
}
return V_395 ;
}
int V_139 ( const char * V_400 , const char * V_401 )
{
const struct V_85 * V_96 = ( const struct V_85 * ) V_400 ;
const struct V_85 * V_97 = ( const struct V_85 * ) V_401 ;
int V_33 ;
V_33 = V_96 -> V_34 -> V_30 - V_97 -> V_34 -> V_30 ;
if( V_33 == 0 ) V_33 = V_96 -> V_105 - V_97 -> V_105 ;
return V_33 ;
}
T_2 int F_126 ( struct V_85 * V_96 , struct V_85 * V_97 )
{
int V_19 ;
for( V_19 = 0 ; V_19 == 0 && V_96 && V_97 ; V_96 = V_96 -> V_90 , V_97 = V_97 -> V_90 ) {
V_19 = V_96 -> V_34 -> V_30 - V_97 -> V_34 -> V_30 ;
if( V_19 == 0 ) V_19 = V_96 -> V_105 - V_97 -> V_105 ;
}
if( V_19 == 0 ) {
if( V_96 ) V_19 = 1 ;
if( V_97 ) V_19 = - 1 ;
}
return V_19 ;
}
T_2 unsigned F_127 ( struct V_85 * V_96 )
{
unsigned V_383 = 0 ;
while( V_96 ) {
V_383 = V_383 * 571 + V_96 -> V_34 -> V_30 * 37 + V_96 -> V_105 ;
V_96 = V_96 -> V_90 ;
}
return V_383 ;
}
struct V_41 * F_34 ( void )
{
struct V_41 * V_407 ;
V_407 = (struct V_41 * ) calloc ( 1 , sizeof( struct V_41 ) ) ;
F_35 ( V_407 ) ;
return V_407 ;
}
void F_65 ( void ) {
if( V_408 ) return;
V_408 = (struct V_409 * ) malloc ( sizeof( struct V_409 ) ) ;
if( V_408 ) {
V_408 -> V_379 = 128 ;
V_408 -> V_387 = 0 ;
V_408 -> V_388 = ( V_410 * ) calloc ( 128 , sizeof( V_410 ) + sizeof( V_410 * ) ) ;
if( V_408 -> V_388 == 0 ) {
free ( V_408 ) ;
V_408 = 0 ;
} else{
int V_9 ;
V_408 -> V_390 = ( V_410 * * ) & ( V_408 -> V_388 [ 128 ] ) ;
for( V_9 = 0 ; V_9 < 128 ; V_9 ++ ) V_408 -> V_390 [ V_9 ] = 0 ;
}
}
}
int F_36 ( struct V_41 * V_391 , struct V_85 * V_398 )
{
V_410 * V_392 ;
unsigned V_383 ;
unsigned V_393 ;
if( V_408 == 0 ) return 0 ;
V_393 = F_127 ( V_398 ) ;
V_383 = V_393 & ( V_408 -> V_379 - 1 ) ;
V_392 = V_408 -> V_390 [ V_383 ] ;
while( V_392 ) {
if( F_126 ( V_392 -> V_398 , V_398 ) == 0 ) {
return 0 ;
}
V_392 = V_392 -> V_26 ;
}
if( V_408 -> V_387 >= V_408 -> V_379 ) {
int V_9 , V_394 ;
struct V_409 V_395 ;
V_395 . V_379 = V_394 = V_408 -> V_379 * 2 ;
V_395 . V_387 = V_408 -> V_387 ;
V_395 . V_388 = ( V_410 * ) calloc ( V_394 , sizeof( V_410 ) + sizeof( V_410 * ) ) ;
if( V_395 . V_388 == 0 ) return 0 ;
V_395 . V_390 = ( V_410 * * ) & ( V_395 . V_388 [ V_394 ] ) ;
for( V_9 = 0 ; V_9 < V_394 ; V_9 ++ ) V_395 . V_390 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_408 -> V_387 ; V_9 ++ ) {
V_410 * V_396 , * V_397 ;
V_396 = & ( V_408 -> V_388 [ V_9 ] ) ;
V_383 = F_127 ( V_396 -> V_398 ) & ( V_394 - 1 ) ;
V_397 = & ( V_395 . V_388 [ V_9 ] ) ;
if( V_395 . V_390 [ V_383 ] ) V_395 . V_390 [ V_383 ] -> V_291 = & ( V_397 -> V_26 ) ;
V_397 -> V_26 = V_395 . V_390 [ V_383 ] ;
V_397 -> V_398 = V_396 -> V_398 ;
V_397 -> V_391 = V_396 -> V_391 ;
V_397 -> V_291 = & ( V_395 . V_390 [ V_383 ] ) ;
V_395 . V_390 [ V_383 ] = V_397 ;
}
free ( V_408 -> V_388 ) ;
* V_408 = V_395 ;
}
V_383 = V_393 & ( V_408 -> V_379 - 1 ) ;
V_392 = & ( V_408 -> V_388 [ V_408 -> V_387 ++ ] ) ;
V_392 -> V_398 = V_398 ;
V_392 -> V_391 = V_391 ;
if( V_408 -> V_390 [ V_383 ] ) V_408 -> V_390 [ V_383 ] -> V_291 = & ( V_392 -> V_26 ) ;
V_392 -> V_26 = V_408 -> V_390 [ V_383 ] ;
V_408 -> V_390 [ V_383 ] = V_392 ;
V_392 -> V_291 = & ( V_408 -> V_390 [ V_383 ] ) ;
return 1 ;
}
struct V_41 * F_27 ( struct V_85 * V_398 )
{
unsigned V_383 ;
V_410 * V_392 ;
if( V_408 == 0 ) return 0 ;
V_383 = F_127 ( V_398 ) & ( V_408 -> V_379 - 1 ) ;
V_392 = V_408 -> V_390 [ V_383 ] ;
while( V_392 ) {
if( F_126 ( V_392 -> V_398 , V_398 ) == 0 ) break;
V_392 = V_392 -> V_26 ;
}
return V_392 ? V_392 -> V_391 : 0 ;
}
struct V_41 * * F_73 ( void )
{
struct V_41 * * V_395 ;
int V_9 , V_394 ;
if( V_408 == 0 ) return 0 ;
V_394 = V_408 -> V_387 ;
V_395 = (struct V_41 * * ) calloc ( V_394 , sizeof( struct V_41 * ) ) ;
if( V_395 ) {
for( V_9 = 0 ; V_9 < V_394 ; V_9 ++ ) V_395 [ V_9 ] = V_408 -> V_388 [ V_9 ] . V_391 ;
}
return V_395 ;
}
T_2 unsigned F_128 ( struct V_85 * V_96 )
{
unsigned V_383 = 0 ;
V_383 = V_383 * 571 + V_96 -> V_34 -> V_30 * 37 + V_96 -> V_105 ;
return V_383 ;
}
void F_48 ( void ) {
if( V_411 ) return;
V_411 = (struct V_412 * ) malloc ( sizeof( struct V_412 ) ) ;
if( V_411 ) {
V_411 -> V_379 = 64 ;
V_411 -> V_387 = 0 ;
V_411 -> V_388 = ( V_413 * ) calloc ( 64 , sizeof( V_413 ) + sizeof( V_413 * ) ) ;
if( V_411 -> V_388 == 0 ) {
free ( V_411 ) ;
V_411 = 0 ;
} else{
int V_9 ;
V_411 -> V_390 = ( V_413 * * ) & ( V_411 -> V_388 [ 64 ] ) ;
for( V_9 = 0 ; V_9 < 64 ; V_9 ++ ) V_411 -> V_390 [ V_9 ] = 0 ;
}
}
}
int F_52 ( struct V_85 * V_391 )
{
V_413 * V_392 ;
unsigned V_383 ;
unsigned V_393 ;
if( V_411 == 0 ) return 0 ;
V_393 = F_128 ( V_391 ) ;
V_383 = V_393 & ( V_411 -> V_379 - 1 ) ;
V_392 = V_411 -> V_390 [ V_383 ] ;
while( V_392 ) {
if( V_139 ( ( const char * ) V_392 -> V_391 , ( const char * ) V_391 ) == 0 ) {
return 0 ;
}
V_392 = V_392 -> V_26 ;
}
if( V_411 -> V_387 >= V_411 -> V_379 ) {
int V_9 , V_394 ;
struct V_412 V_395 ;
V_395 . V_379 = V_394 = V_411 -> V_379 * 2 ;
V_395 . V_387 = V_411 -> V_387 ;
V_395 . V_388 = ( V_413 * ) calloc ( V_394 , sizeof( V_413 ) + sizeof( V_413 * ) ) ;
if( V_395 . V_388 == 0 ) return 0 ;
V_395 . V_390 = ( V_413 * * ) & ( V_395 . V_388 [ V_394 ] ) ;
for( V_9 = 0 ; V_9 < V_394 ; V_9 ++ ) V_395 . V_390 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_411 -> V_387 ; V_9 ++ ) {
V_413 * V_396 , * V_397 ;
V_396 = & ( V_411 -> V_388 [ V_9 ] ) ;
V_383 = F_128 ( V_396 -> V_391 ) & ( V_394 - 1 ) ;
V_397 = & ( V_395 . V_388 [ V_9 ] ) ;
if( V_395 . V_390 [ V_383 ] ) V_395 . V_390 [ V_383 ] -> V_291 = & ( V_397 -> V_26 ) ;
V_397 -> V_26 = V_395 . V_390 [ V_383 ] ;
V_397 -> V_391 = V_396 -> V_391 ;
V_397 -> V_291 = & ( V_395 . V_390 [ V_383 ] ) ;
V_395 . V_390 [ V_383 ] = V_397 ;
}
free ( V_411 -> V_388 ) ;
* V_411 = V_395 ;
}
V_383 = V_393 & ( V_411 -> V_379 - 1 ) ;
V_392 = & ( V_411 -> V_388 [ V_411 -> V_387 ++ ] ) ;
V_392 -> V_391 = V_391 ;
if( V_411 -> V_390 [ V_383 ] ) V_411 -> V_390 [ V_383 ] -> V_291 = & ( V_392 -> V_26 ) ;
V_392 -> V_26 = V_411 -> V_390 [ V_383 ] ;
V_411 -> V_390 [ V_383 ] = V_392 ;
V_392 -> V_291 = & ( V_411 -> V_390 [ V_383 ] ) ;
return 1 ;
}
struct V_85 * F_51 ( struct V_85 * V_398 )
{
int V_383 ;
V_413 * V_392 ;
if( V_411 == 0 ) return 0 ;
V_383 = F_128 ( V_398 ) & ( V_411 -> V_379 - 1 ) ;
V_392 = V_411 -> V_390 [ V_383 ] ;
while( V_392 ) {
if( V_139 ( ( const char * ) V_392 -> V_391 , ( const char * ) V_398 ) == 0 ) break;
V_392 = V_392 -> V_26 ;
}
return V_392 ? V_392 -> V_391 : 0 ;
}
void F_49 ( int (* F_129)( struct V_85 * ) )
{
int V_9 ;
if( V_411 == 0 || V_411 -> V_387 == 0 ) return;
if( F_129 ) for( V_9 = 0 ; V_9 < V_411 -> V_387 ; V_9 ++ ) (* F_129)( V_411 -> V_388 [ V_9 ] . V_391 ) ;
for( V_9 = 0 ; V_9 < V_411 -> V_379 ; V_9 ++ ) V_411 -> V_390 [ V_9 ] = 0 ;
V_411 -> V_387 = 0 ;
return;
}
