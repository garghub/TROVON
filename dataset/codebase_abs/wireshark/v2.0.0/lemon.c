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
if( isdigit ( V_12 ) || ( V_12 == '-' && isdigit ( V_7 [ V_9 + 1 ] ) ) ) {
if( V_12 == '-' ) V_9 ++ ;
while( isdigit ( V_7 [ V_9 ] ) ) V_5 = V_5 * 10 + V_7 [ V_9 ++ ] - '0' ;
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
if( V_19 == 0 && V_27 -> type == V_31 ) {
V_19 = V_27 -> V_32 . V_33 -> V_30 - V_28 -> V_32 . V_33 -> V_30 ;
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
struct V_22 * * V_34 ,
enum V_35 type ,
struct V_36 * V_29 ,
char * V_37
) {
struct V_22 * V_24 ;
V_24 = F_6 () ;
V_24 -> V_26 = * V_34 ;
* V_34 = V_24 ;
V_24 -> type = type ;
V_24 -> V_29 = V_29 ;
if( type == V_38 ) {
V_24 -> V_32 . V_39 = (struct V_40 * ) V_37 ;
} else{
V_24 -> V_32 . V_33 = (struct V_41 * ) V_37 ;
}
}
T_2 T_3 * F_11 ( void ) {
T_3 * V_42 = ( T_3 * ) calloc ( 1 , sizeof( * V_42 ) ) ;
if( V_42 == 0 ) {
fprintf ( V_17 , L_7 ) ;
exit ( 1 ) ;
}
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
return V_42 ;
}
T_2 void F_12 ( T_3 * V_42 , int V_43 , int V_22 ) {
if( V_42 -> V_44 >= V_42 -> V_45 ) {
V_42 -> V_45 += 25 ;
V_42 -> V_46 = (struct V_47 * ) realloc ( V_42 -> V_46 ,
sizeof( V_42 -> V_46 [ 0 ] ) * V_42 -> V_45 ) ;
if( V_42 -> V_46 == 0 ) {
fprintf ( V_17 , L_8 ) ;
exit ( 1 ) ;
}
}
if( V_42 -> V_44 == 0 ) {
V_42 -> V_48 = V_43 ;
V_42 -> V_49 = V_43 ;
V_42 -> V_50 = V_22 ;
} else{
if( V_42 -> V_48 < V_43 ) V_42 -> V_48 = V_43 ;
if( V_42 -> V_49 > V_43 ) {
V_42 -> V_49 = V_43 ;
V_42 -> V_50 = V_22 ;
}
}
V_42 -> V_46 [ V_42 -> V_44 ] . V_43 = V_43 ;
V_42 -> V_46 [ V_42 -> V_44 ] . V_22 = V_22 ;
V_42 -> V_44 ++ ;
}
T_2 int F_13 ( T_3 * V_42 ) {
int V_9 , V_10 , V_11 , V_51 ;
assert ( V_42 -> V_44 > 0 ) ;
V_51 = V_42 -> V_48 + 1 ;
if( V_42 -> V_52 + V_51 >= V_42 -> V_53 ) {
int V_54 = V_42 -> V_53 ;
V_42 -> V_53 = V_42 -> V_52 + V_51 + V_42 -> V_53 + 20 ;
V_42 -> V_55 = (struct V_47 * ) realloc ( V_42 -> V_55 ,
sizeof( V_42 -> V_55 [ 0 ] ) * V_42 -> V_53 ) ;
if( V_42 -> V_55 == 0 ) {
fprintf ( V_17 , L_8 ) ;
exit ( 1 ) ;
}
for( V_9 = V_54 ; V_9 < V_42 -> V_53 ; V_9 ++ ) {
V_42 -> V_55 [ V_9 ] . V_43 = - 1 ;
V_42 -> V_55 [ V_9 ] . V_22 = - 1 ;
}
}
for( V_9 = V_42 -> V_52 - 1 ; V_9 >= 0 ; V_9 -- ) {
if( V_42 -> V_55 [ V_9 ] . V_43 == V_42 -> V_49 ) {
if( V_42 -> V_55 [ V_9 ] . V_22 != V_42 -> V_50 ) continue;
for( V_10 = 0 ; V_10 < V_42 -> V_44 ; V_10 ++ ) {
V_11 = V_42 -> V_46 [ V_10 ] . V_43 - V_42 -> V_49 + V_9 ;
if( V_11 < 0 || V_11 >= V_42 -> V_52 ) break;
if( V_42 -> V_46 [ V_10 ] . V_43 != V_42 -> V_55 [ V_11 ] . V_43 ) break;
if( V_42 -> V_46 [ V_10 ] . V_22 != V_42 -> V_55 [ V_11 ] . V_22 ) break;
}
if( V_10 < V_42 -> V_44 ) continue;
V_51 = 0 ;
for( V_10 = 0 ; V_10 < V_42 -> V_52 ; V_10 ++ ) {
if( V_42 -> V_55 [ V_10 ] . V_43 < 0 ) continue;
if( V_42 -> V_55 [ V_10 ] . V_43 == V_10 + V_42 -> V_49 - V_9 ) V_51 ++ ;
}
if( V_51 == V_42 -> V_44 ) {
break;
}
}
}
if( V_9 < 0 ) {
for( V_9 = 0 ; V_9 < V_42 -> V_53 - V_42 -> V_48 ; V_9 ++ ) {
if( V_42 -> V_55 [ V_9 ] . V_43 < 0 ) {
for( V_10 = 0 ; V_10 < V_42 -> V_44 ; V_10 ++ ) {
V_11 = V_42 -> V_46 [ V_10 ] . V_43 - V_42 -> V_49 + V_9 ;
if( V_11 < 0 ) break;
if( V_42 -> V_55 [ V_11 ] . V_43 >= 0 ) break;
}
if( V_10 < V_42 -> V_44 ) continue;
for( V_10 = 0 ; V_10 < V_42 -> V_52 ; V_10 ++ ) {
if( V_42 -> V_55 [ V_10 ] . V_43 == V_10 + V_42 -> V_49 - V_9 ) break;
}
if( V_10 == V_42 -> V_52 ) {
break;
}
}
}
}
for( V_10 = 0 ; V_10 < V_42 -> V_44 ; V_10 ++ ) {
V_11 = V_42 -> V_46 [ V_10 ] . V_43 - V_42 -> V_49 + V_9 ;
V_42 -> V_55 [ V_11 ] = V_42 -> V_46 [ V_10 ] ;
if( V_11 >= V_42 -> V_52 ) V_42 -> V_52 = V_11 + 1 ;
}
V_42 -> V_44 = 0 ;
return V_9 - V_42 -> V_49 ;
}
void F_14 ( struct V_56 * V_57 )
{
struct V_41 * V_33 ;
for( V_33 = V_57 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 ) {
if( V_33 -> V_58 == 0 ) {
int V_9 , V_10 ;
for( V_9 = 0 ; V_9 < V_33 -> V_59 && V_33 -> V_58 == 0 ; V_9 ++ ) {
struct V_36 * V_29 = V_33 -> V_60 [ V_9 ] ;
if( V_29 -> type == V_61 ) {
for( V_10 = 0 ; V_10 < V_29 -> V_62 ; V_10 ++ ) {
if( V_29 -> V_63 [ V_10 ] -> V_64 >= 0 ) {
V_33 -> V_58 = V_29 -> V_63 [ V_10 ] ;
break;
}
}
} else if( V_29 -> V_64 >= 0 ) {
V_33 -> V_58 = V_33 -> V_60 [ V_9 ] ;
}
}
}
}
return;
}
void F_15 ( struct V_56 * V_65 )
{
int V_9 , V_10 ;
struct V_41 * V_33 ;
int V_66 ;
for( V_9 = 0 ; V_9 < V_65 -> V_67 ; V_9 ++ ) {
V_65 -> V_68 [ V_9 ] -> V_69 = V_70 ;
}
for( V_9 = V_65 -> V_71 ; V_9 < V_65 -> V_67 ; V_9 ++ ) {
V_65 -> V_68 [ V_9 ] -> V_72 = F_16 () ;
}
do{
V_66 = 0 ;
for( V_33 = V_65 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 ) {
if( V_33 -> V_73 -> V_69 ) continue;
for( V_9 = 0 ; V_9 < V_33 -> V_59 ; V_9 ++ ) {
struct V_36 * V_29 = V_33 -> V_60 [ V_9 ] ;
assert ( V_29 -> type == V_74 || V_29 -> V_69 == V_70 ) ;
if( V_29 -> V_69 == V_70 ) break;
}
if( V_9 == V_33 -> V_59 ) {
V_33 -> V_73 -> V_69 = V_75 ;
V_66 = 1 ;
}
}
}while( V_66 );
do{
struct V_36 * V_76 , * V_77 ;
V_66 = 0 ;
for( V_33 = V_65 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 ) {
V_76 = V_33 -> V_73 ;
for( V_9 = 0 ; V_9 < V_33 -> V_59 ; V_9 ++ ) {
V_77 = V_33 -> V_60 [ V_9 ] ;
if( V_77 -> type == V_78 ) {
V_66 += F_17 ( V_76 -> V_72 , V_77 -> V_30 ) ;
break;
} else if( V_77 -> type == V_61 ) {
for( V_10 = 0 ; V_10 < V_77 -> V_62 ; V_10 ++ ) {
V_66 += F_17 ( V_76 -> V_72 , V_77 -> V_63 [ V_10 ] -> V_30 ) ;
}
break;
} else if( V_76 == V_77 ) {
if( V_76 -> V_69 == V_70 ) break;
} else{
V_66 += F_18 ( V_76 -> V_72 , V_77 -> V_72 ) ;
if( V_77 -> V_69 == V_70 ) break;
}
}
}
}while( V_66 );
return;
}
void F_19 ( struct V_56 * V_65 )
{
struct V_36 * V_29 ;
struct V_41 * V_33 ;
F_20 () ;
if( V_65 -> V_79 ) {
V_29 = F_21 ( V_65 -> V_79 ) ;
if( V_29 == 0 ) {
F_22 ( V_65 -> V_80 , 0 ,
L_9 , V_65 -> V_79 , V_65 -> V_41 -> V_73 -> V_81 ) ;
V_65 -> V_82 ++ ;
V_29 = V_65 -> V_41 -> V_73 ;
}
} else{
V_29 = V_65 -> V_41 -> V_73 ;
}
for( V_33 = V_65 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 ) {
int V_9 ;
for( V_9 = 0 ; V_9 < V_33 -> V_59 ; V_9 ++ ) {
if( V_33 -> V_60 [ V_9 ] == V_29 ) {
F_22 ( V_65 -> V_80 , 0 ,
L_10 , V_29 -> V_81 ) ;
V_65 -> V_82 ++ ;
}
}
}
for( V_33 = V_29 -> V_41 ; V_33 ; V_33 = V_33 -> V_83 ) {
struct V_84 * V_85 ;
V_33 -> V_86 = 1 ;
V_85 = F_23 ( V_33 , 0 ) ;
F_17 ( V_85 -> V_87 , 0 ) ;
}
( void ) F_24 ( V_65 ) ;
return;
}
T_2 struct V_40 * F_24 ( struct V_56 * V_65 )
{
struct V_84 * V_88 , * V_89 ;
struct V_40 * V_39 ;
F_25 () ;
V_89 = F_26 () ;
V_39 = F_27 ( V_89 ) ;
if( V_39 ) {
struct V_84 * V_32 , * V_90 ;
for( V_32 = V_89 , V_90 = V_39 -> V_89 ; V_32 && V_90 ; V_32 = V_32 -> V_89 , V_90 = V_90 -> V_89 ) {
F_28 ( & V_90 -> V_91 , V_32 -> V_91 ) ;
F_29 ( V_32 -> V_92 ) ;
V_32 -> V_92 = V_32 -> V_91 = 0 ;
}
V_88 = F_30 () ;
F_31 ( V_88 ) ;
} else{
F_32 ( V_65 ) ;
F_33 () ;
V_88 = F_30 () ;
V_39 = F_34 () ;
F_35 ( V_39 ) ;
V_39 -> V_89 = V_89 ;
V_39 -> V_88 = V_88 ;
V_39 -> V_93 = V_65 -> V_94 ++ ;
V_39 -> V_8 = 0 ;
F_36 ( V_39 , V_39 -> V_89 ) ;
F_37 ( V_65 , V_39 ) ;
}
return V_39 ;
}
T_2 int F_38 ( struct V_36 * V_95 , struct V_36 * V_96 )
{
int V_9 ;
if( V_95 == V_96 ) return 1 ;
if( V_95 -> type != V_61 ) return 0 ;
if( V_96 -> type != V_61 ) return 0 ;
if( V_95 -> V_62 != V_96 -> V_62 ) return 0 ;
for( V_9 = 0 ; V_9 < V_95 -> V_62 ; V_9 ++ ) {
if( V_95 -> V_63 [ V_9 ] != V_96 -> V_63 [ V_9 ] ) return 0 ;
}
return 1 ;
}
T_2 void F_37 ( struct V_56 * V_65 , struct V_40 * V_39 )
{
struct V_84 * V_88 ;
struct V_84 * V_97 ;
struct V_84 * V_98 ;
struct V_36 * V_29 ;
struct V_36 * V_99 ;
struct V_40 * V_100 ;
for( V_88 = V_39 -> V_88 ; V_88 ; V_88 = V_88 -> V_26 ) V_88 -> V_101 = V_102 ;
for( V_88 = V_39 -> V_88 ; V_88 ; V_88 = V_88 -> V_26 ) {
if( V_88 -> V_101 == V_103 ) continue;
if( V_88 -> V_104 >= V_88 -> V_33 -> V_59 ) continue;
F_39 () ;
V_29 = V_88 -> V_33 -> V_60 [ V_88 -> V_104 ] ;
for( V_97 = V_88 ; V_97 ; V_97 = V_97 -> V_26 ) {
if( V_97 -> V_101 == V_103 ) continue;
if( V_97 -> V_104 >= V_97 -> V_33 -> V_59 ) continue;
V_99 = V_97 -> V_33 -> V_60 [ V_97 -> V_104 ] ;
if( ! F_38 ( V_99 , V_29 ) ) continue;
V_97 -> V_101 = V_103 ;
V_98 = F_23 ( V_97 -> V_33 , V_97 -> V_104 + 1 ) ;
F_40 ( & V_98 -> V_91 , V_97 ) ;
}
V_100 = F_24 ( V_65 ) ;
if( V_29 -> type == V_61 ) {
int V_9 ;
for( V_9 = 0 ; V_9 < V_29 -> V_62 ; V_9 ++ ) {
F_10 ( & V_39 -> V_8 , V_38 , V_29 -> V_63 [ V_9 ] , ( char * ) V_100 ) ;
}
} else{
F_10 ( & V_39 -> V_8 , V_38 , V_29 , ( char * ) V_100 ) ;
}
}
}
void F_41 ( struct V_56 * V_65 )
{
int V_9 ;
struct V_84 * V_88 , * V_105 ;
struct V_40 * V_39 ;
struct V_106 * V_107 ;
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
V_39 = V_65 -> V_108 [ V_9 ] ;
for( V_88 = V_39 -> V_88 ; V_88 ; V_88 = V_88 -> V_26 ) {
V_88 -> V_39 = V_39 ;
}
}
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
V_39 = V_65 -> V_108 [ V_9 ] ;
for( V_88 = V_39 -> V_88 ; V_88 ; V_88 = V_88 -> V_26 ) {
for( V_107 = V_88 -> V_91 ; V_107 ; V_107 = V_107 -> V_26 ) {
V_105 = V_107 -> V_88 ;
F_40 ( & V_105 -> V_92 , V_88 ) ;
}
}
}
}
void F_42 ( struct V_56 * V_65 )
{
int V_9 ;
struct V_84 * V_88 ;
struct V_106 * V_107 ;
int V_66 ;
int V_109 ;
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
for( V_88 = V_65 -> V_108 [ V_9 ] -> V_88 ; V_88 ; V_88 = V_88 -> V_26 ) {
V_88 -> V_101 = V_102 ;
}
}
do{
V_66 = 0 ;
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
for( V_88 = V_65 -> V_108 [ V_9 ] -> V_88 ; V_88 ; V_88 = V_88 -> V_26 ) {
if( V_88 -> V_101 == V_103 ) continue;
for( V_107 = V_88 -> V_92 ; V_107 ; V_107 = V_107 -> V_26 ) {
V_109 = F_18 ( V_107 -> V_88 -> V_87 , V_88 -> V_87 ) ;
if( V_109 ) {
V_107 -> V_88 -> V_101 = V_102 ;
V_66 = 1 ;
}
}
V_88 -> V_101 = V_103 ;
}
}
}while( V_66 );
}
void F_43 ( struct V_56 * V_65 )
{
int V_9 , V_10 ;
struct V_84 * V_88 ;
struct V_40 * V_39 ;
struct V_36 * V_29 ;
struct V_41 * V_33 ;
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
V_39 = V_65 -> V_108 [ V_9 ] ;
for( V_88 = V_39 -> V_88 ; V_88 ; V_88 = V_88 -> V_26 ) {
if( V_88 -> V_33 -> V_59 == V_88 -> V_104 ) {
for( V_10 = 0 ; V_10 < V_65 -> V_71 ; V_10 ++ ) {
if( F_44 ( V_88 -> V_87 , V_10 ) ) {
F_10 ( & V_39 -> V_8 , V_31 , V_65 -> V_68 [ V_10 ] , ( char * ) V_88 -> V_33 ) ;
}
}
}
}
}
if( V_65 -> V_79 ) {
V_29 = F_21 ( V_65 -> V_79 ) ;
if( V_29 == 0 ) V_29 = V_65 -> V_41 -> V_73 ;
} else{
V_29 = V_65 -> V_41 -> V_73 ;
}
F_10 ( & V_65 -> V_108 [ 0 ] -> V_8 , V_110 , V_29 , 0 ) ;
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
struct V_22 * V_8 , * V_111 ;
V_39 = V_65 -> V_108 [ V_9 ] ;
V_39 -> V_8 = F_8 ( V_39 -> V_8 ) ;
for( V_8 = V_39 -> V_8 ; V_8 && V_8 -> V_26 ; V_8 = V_8 -> V_26 ) {
for( V_111 = V_8 -> V_26 ; V_111 && V_111 -> V_29 == V_8 -> V_29 ; V_111 = V_111 -> V_26 ) {
V_65 -> V_112 += F_45 ( V_8 , V_111 ) ;
}
}
}
for( V_33 = V_65 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 ) V_33 -> V_113 = V_70 ;
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
struct V_22 * V_8 ;
for( V_8 = V_65 -> V_108 [ V_9 ] -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_31 ) V_8 -> V_32 . V_33 -> V_113 = V_75 ;
}
}
for( V_33 = V_65 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 ) {
if( V_33 -> V_113 ) continue;
F_22 ( V_65 -> V_80 , V_33 -> V_114 , L_11 ) ;
V_65 -> V_82 ++ ;
}
}
static int F_45 (
struct V_22 * V_115 ,
struct V_22 * V_116
) {
struct V_36 * V_117 , * V_118 ;
int V_119 = 0 ;
assert ( V_115 -> V_29 == V_116 -> V_29 ) ;
if( V_115 -> type == V_38 && V_116 -> type == V_38 ) {
V_116 -> type = V_120 ;
V_119 ++ ;
}
if( V_115 -> type == V_38 && V_116 -> type == V_31 ) {
V_117 = V_115 -> V_29 ;
V_118 = V_116 -> V_32 . V_33 -> V_58 ;
if( V_118 == 0 || V_117 -> V_64 < 0 || V_118 -> V_64 < 0 ) {
V_116 -> type = V_121 ;
V_119 ++ ;
} else if( V_117 -> V_64 > V_118 -> V_64 ) {
V_116 -> type = V_122 ;
} else if( V_117 -> V_64 < V_118 -> V_64 ) {
V_115 -> type = V_123 ;
} else if( V_117 -> V_64 == V_118 -> V_64 && V_117 -> V_124 == V_125 ) {
V_116 -> type = V_122 ;
} else if( V_117 -> V_64 == V_118 -> V_64 && V_117 -> V_124 == V_126 ) {
V_115 -> type = V_123 ;
} else{
assert ( V_117 -> V_64 == V_118 -> V_64 && V_117 -> V_124 == V_127 ) ;
V_115 -> type = ERROR ;
}
} else if( V_115 -> type == V_31 && V_116 -> type == V_31 ) {
V_117 = V_115 -> V_32 . V_33 -> V_58 ;
V_118 = V_116 -> V_32 . V_33 -> V_58 ;
if( V_117 == 0 || V_118 == 0 || V_117 -> V_64 < 0 ||
V_118 -> V_64 < 0 || V_117 -> V_64 == V_118 -> V_64 ) {
V_116 -> type = V_128 ;
V_119 ++ ;
} else if( V_117 -> V_64 > V_118 -> V_64 ) {
V_116 -> type = V_122 ;
} else if( V_117 -> V_64 < V_118 -> V_64 ) {
V_115 -> type = V_122 ;
}
} else{
assert (
V_115 -> type == V_123 ||
V_115 -> type == V_122 ||
V_115 -> type == V_120 ||
V_115 -> type == V_121 ||
V_115 -> type == V_128 ||
V_116 -> type == V_123 ||
V_116 -> type == V_122 ||
V_116 -> type == V_120 ||
V_116 -> type == V_121 ||
V_116 -> type == V_128
) ;
}
return V_119 ;
}
T_2 struct V_84 * F_46 ( void ) {
struct V_84 * V_98 ;
if( V_23 == 0 ) {
int V_9 ;
int V_25 = 3 ;
V_23 = (struct V_84 * ) calloc ( V_25 , sizeof( struct V_84 ) ) ;
if( V_23 == 0 ) {
fprintf ( V_17 , L_12 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_25 - 1 ; V_9 ++ ) V_23 [ V_9 ] . V_26 = & V_23 [ V_9 + 1 ] ;
V_23 [ V_25 - 1 ] . V_26 = 0 ;
}
V_98 = V_23 ;
V_23 = V_23 -> V_26 ;
return V_98 ;
}
T_2 void F_47 ( struct V_84 * V_129 )
{
V_129 -> V_26 = V_23 ;
V_23 = V_129 ;
}
void F_20 ( void ) {
V_130 = 0 ;
V_131 = & V_130 ;
V_132 = 0 ;
V_133 = & V_132 ;
F_48 () ;
return;
}
void F_39 ( void ) {
V_130 = 0 ;
V_131 = & V_130 ;
V_132 = 0 ;
V_133 = & V_132 ;
F_49 ( 0 ) ;
return;
}
struct V_84 * F_50 (
struct V_41 * V_33 ,
int V_104
) {
struct V_84 * V_88 , V_134 ;
assert ( V_131 != 0 ) ;
V_134 . V_33 = V_33 ;
V_134 . V_104 = V_104 ;
V_88 = F_51 ( & V_134 ) ;
if( V_88 == 0 ) {
V_88 = F_46 () ;
V_88 -> V_33 = V_33 ;
V_88 -> V_104 = V_104 ;
V_88 -> V_87 = F_16 () ;
V_88 -> V_39 = 0 ;
V_88 -> V_92 = V_88 -> V_91 = 0 ;
V_88 -> V_26 = 0 ;
V_88 -> V_89 = 0 ;
* V_131 = V_88 ;
V_131 = & V_88 -> V_26 ;
F_52 ( V_88 ) ;
}
return V_88 ;
}
struct V_84 * F_23 ( struct V_41 * V_33 , int V_104 )
{
struct V_84 * V_88 , V_134 ;
assert ( V_133 != 0 ) ;
assert ( V_131 != 0 ) ;
V_134 . V_33 = V_33 ;
V_134 . V_104 = V_104 ;
V_88 = F_51 ( & V_134 ) ;
if( V_88 == 0 ) {
V_88 = F_46 () ;
V_88 -> V_33 = V_33 ;
V_88 -> V_104 = V_104 ;
V_88 -> V_87 = F_16 () ;
V_88 -> V_39 = 0 ;
V_88 -> V_92 = V_88 -> V_91 = 0 ;
V_88 -> V_26 = 0 ;
V_88 -> V_89 = 0 ;
* V_131 = V_88 ;
V_131 = & V_88 -> V_26 ;
* V_133 = V_88 ;
V_133 = & V_88 -> V_89 ;
F_52 ( V_88 ) ;
}
return V_88 ;
}
void F_32 ( struct V_56 * V_65 )
{
struct V_84 * V_88 , * V_85 ;
struct V_41 * V_33 , * V_135 ;
struct V_36 * V_29 , * V_136 ;
int V_9 , V_104 ;
assert ( V_131 != 0 ) ;
for( V_88 = V_130 ; V_88 ; V_88 = V_88 -> V_26 ) {
V_33 = V_88 -> V_33 ;
V_104 = V_88 -> V_104 ;
if( V_104 >= V_33 -> V_59 ) continue;
V_29 = V_33 -> V_60 [ V_104 ] ;
if( V_29 -> type == V_74 ) {
if( V_29 -> V_41 == 0 && V_29 != V_65 -> V_137 ) {
F_22 ( V_65 -> V_80 , V_33 -> line , L_13 ,
V_29 -> V_81 ) ;
V_65 -> V_82 ++ ;
}
for( V_135 = V_29 -> V_41 ; V_135 ; V_135 = V_135 -> V_83 ) {
V_85 = F_50 ( V_135 , 0 ) ;
for( V_9 = V_104 + 1 ; V_9 < V_33 -> V_59 ; V_9 ++ ) {
V_136 = V_33 -> V_60 [ V_9 ] ;
if( V_136 -> type == V_78 ) {
F_17 ( V_85 -> V_87 , V_136 -> V_30 ) ;
break;
} else if( V_136 -> type == V_61 ) {
int V_11 ;
for( V_11 = 0 ; V_11 < V_136 -> V_62 ; V_11 ++ ) {
F_17 ( V_85 -> V_87 , V_136 -> V_63 [ V_11 ] -> V_30 ) ;
}
break;
} else{
F_18 ( V_85 -> V_87 , V_136 -> V_72 ) ;
if( V_136 -> V_69 == V_70 ) break;
}
}
if( V_9 == V_33 -> V_59 ) F_40 ( & V_88 -> V_92 , V_85 ) ;
}
}
}
return;
}
void F_33 ( void ) {
V_130 = (struct V_84 * ) F_9 ( ( char * ) V_130 , ( char * * ) & ( V_130 -> V_26 ) , V_138 ) ;
V_131 = 0 ;
return;
}
void F_25 ( void ) {
V_132 = (struct V_84 * ) F_9 ( ( char * ) V_130 , ( char * * ) & ( V_130 -> V_89 ) , V_138 ) ;
V_133 = 0 ;
return;
}
struct V_84 * F_30 ( void ) {
struct V_84 * V_129 ;
V_129 = V_130 ;
V_130 = 0 ;
V_131 = 0 ;
return V_129 ;
}
struct V_84 * F_26 ( void ) {
struct V_84 * V_129 ;
V_129 = V_132 ;
V_132 = 0 ;
V_133 = 0 ;
return V_129 ;
}
void F_31 ( struct V_84 * V_88 )
{
struct V_84 * V_139 ;
for(; V_88 ; V_88 = V_139 ) {
V_139 = V_88 -> V_26 ;
assert ( V_88 -> V_92 == 0 ) ;
assert ( V_88 -> V_91 == 0 ) ;
if( V_88 -> V_87 ) F_53 ( V_88 -> V_87 ) ;
F_47 ( V_88 ) ;
}
return;
}
void F_22 ( const char * V_80 , int V_140 , const char * V_18 , ... ) {
T_1 V_8 ;
fprintf ( V_17 , L_14 , V_80 , V_140 ) ;
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
F_55 ( char * V_141 )
{
char * V_142 ;
char * V_143 ;
V_142 = strrchr ( V_141 , '/' ) ;
#ifdef F_56
if ( ! V_142 )
V_142 = strrchr ( V_141 , '\\' ) ;
#endif
if ( ! V_142 ) {
V_143 = ( char * ) malloc ( strlen ( V_141 ) + 1 ) ;
strcpy ( V_143 , V_141 ) ;
}
else {
V_142 ++ ;
V_143 = ( char * ) malloc ( strlen ( V_142 ) + 1 ) ;
strcpy ( V_143 , V_142 ) ;
}
return V_143 ;
}
static void F_57 ( char * V_14 ) {
char * * V_144 ;
V_145 ++ ;
V_146 = ( char * * ) realloc ( V_146 , sizeof( V_146 [ 0 ] ) * V_145 ) ;
if( V_146 == 0 ) {
fprintf ( V_17 , L_17 ) ;
exit ( 1 ) ;
}
V_144 = & V_146 [ V_145 - 1 ] ;
* V_144 = ( char * ) malloc ( F_58 ( V_14 ) + 1 ) ;
if( * V_144 == 0 ) {
fprintf ( V_17 , L_17 ) ;
exit ( 1 ) ;
}
F_4 ( * V_144 , V_14 ) ;
for( V_14 = * V_144 ; * V_14 && * V_14 != '=' ; V_14 ++ ) {}
* V_14 = 0 ;
}
static void F_59 ( char * V_14 ) {
V_147 = ( char * ) malloc ( F_58 ( V_14 ) + 1 ) ;
if( V_147 == 0 ) {
F_54 () ;
}
F_4 ( V_147 , V_14 ) ;
}
int main ( int T_4 V_148 , char * * V_149 )
{
static int V_150 = 0 ;
static int V_151 = 0 ;
static int V_152 = 0 ;
static int V_153 = 0 ;
static int V_154 = 0 ;
static int V_155 = 0 ;
static int V_156 = 0 ;
static int V_157 = 0 ;
static int V_158 = 0 ;
static struct V_159 V_160 [] = {
{ V_161 , L_18 , ( char * ) & V_152 , L_19 } ,
{ V_161 , L_20 , ( char * ) & V_153 , L_21 } ,
{ V_162 , L_22 , ( char * ) F_57 , L_23 } ,
{ V_162 , L_24 , 0 , L_25 } ,
{ V_161 , L_26 , ( char * ) & V_151 , L_27 } ,
{ V_162 , L_28 , 0 , L_29 } ,
{ V_161 , L_30 , ( char * ) & V_156 , L_31 } ,
{ V_161 , L_32 , ( char * ) & V_157 , L_33 } ,
{ V_162 , L_34 , 0 , L_35 } ,
{ V_161 , L_36 , ( char * ) & V_163 ,
L_37 } ,
{ V_161 , L_38 , ( char * ) & V_154 , L_39 } ,
{ V_161 , L_40 , ( char * ) & V_158 , L_41 } ,
{ V_161 , L_42 , ( char * ) & V_155 ,
L_43 } ,
{ V_161 , L_44 , ( char * ) & V_150 , L_45 } ,
{ V_162 , L_46 , ( char * ) F_59 , L_47 } ,
{ V_162 , L_48 , 0 , L_49 } ,
{ V_161 , 0 , 0 , 0 }
} ;
int V_9 ;
int V_164 ;
struct V_56 V_165 ;
F_60 ( V_149 , V_160 , V_17 ) ;
if( V_150 ) {
printf ( L_50 ) ;
exit ( 0 ) ;
}
if( F_61 () != 1 ) {
fprintf ( V_17 , L_51 ) ;
exit ( 1 ) ;
}
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_165 . V_82 = 0 ;
F_62 () ;
F_63 () ;
F_64 () ;
V_165 . V_166 = V_149 [ 0 ] ;
V_165 . V_80 = F_65 ( 0 ) ;
V_165 . V_152 = V_152 ;
V_165 . V_157 = V_157 ;
F_66 ( L_52 ) ;
V_165 . V_137 = F_66 ( L_53 ) ;
V_165 . V_137 -> V_167 = 0 ;
V_165 . V_168 = F_55 ( V_165 . V_80 ) ;
F_67 ( & V_165 ) ;
if( V_165 . V_82 ) exit ( V_165 . V_82 ) ;
if( V_165 . V_169 == 0 ) {
fprintf ( V_17 , L_54 ) ;
exit ( 1 ) ;
}
F_66 ( L_55 ) ;
V_165 . V_67 = F_68 () ;
V_165 . V_68 = F_69 () ;
for( V_9 = 0 ; V_9 < V_165 . V_67 ; V_9 ++ ) V_165 . V_68 [ V_9 ] -> V_30 = V_9 ;
qsort ( V_165 . V_68 , V_165 . V_67 , sizeof( struct V_36 * ) , V_170 ) ;
for( V_9 = 0 ; V_9 < V_165 . V_67 ; V_9 ++ ) V_165 . V_68 [ V_9 ] -> V_30 = V_9 ;
while( V_165 . V_68 [ V_9 - 1 ] -> type == V_61 ) { V_9 -- ; }
assert ( strcmp ( V_165 . V_68 [ V_9 - 1 ] -> V_81 , L_55 ) == 0 ) ;
V_165 . V_67 = V_9 - 1 ;
for( V_9 = 1 ; isupper ( V_165 . V_68 [ V_9 ] -> V_81 [ 0 ] ) ; V_9 ++ ) ;
V_165 . V_71 = V_9 ;
if( V_151 ) {
F_70 ( & V_165 ) ;
} else{
F_71 ( V_165 . V_71 + 1 ) ;
F_14 ( & V_165 ) ;
F_15 ( & V_165 ) ;
V_165 . V_94 = 0 ;
F_19 ( & V_165 ) ;
V_165 . V_108 = F_72 () ;
F_41 ( & V_165 ) ;
F_42 ( & V_165 ) ;
F_43 ( & V_165 ) ;
if( V_153 == 0 ) F_73 ( & V_165 ) ;
if( V_158 == 0 ) F_74 ( & V_165 ) ;
if( ! V_154 ) F_75 ( & V_165 ) ;
F_76 ( & V_165 , V_156 ) ;
if( ! V_156 ) F_77 ( & V_165 ) ;
}
if( V_155 ) {
printf ( L_56 ,
V_165 . V_71 , V_165 . V_67 - V_165 . V_71 , V_165 . V_169 ) ;
printf ( L_57 ,
V_165 . V_94 , V_165 . V_171 , V_165 . V_112 ) ;
}
if( V_165 . V_112 > 0 ) {
fprintf ( V_17 , L_58 , V_165 . V_112 ) ;
}
V_164 = ( ( V_165 . V_82 > 0 ) || ( V_165 . V_112 > 0 ) ) ? 1 : 0 ;
exit ( V_164 ) ;
return ( V_164 ) ;
}
static char * F_78 (
char * V_95 ,
char * V_96 ,
int (* F_79)( const char * , const char * ) ,
int V_172
) {
char * V_173 , * V_174 ;
if( V_95 == 0 ) {
V_174 = V_96 ;
} else if( V_96 == 0 ) {
V_174 = V_95 ;
} else{
if( (* F_79)( V_95 , V_96 ) <= 0 ) {
V_173 = V_95 ;
V_95 = F_80 ( V_95 ) ;
} else{
V_173 = V_96 ;
V_96 = F_80 ( V_96 ) ;
}
V_174 = V_173 ;
while( V_95 && V_96 ) {
if( (* F_79)( V_95 , V_96 ) <= 0 ) {
F_80 ( V_173 ) = V_95 ;
V_173 = V_95 ;
V_95 = F_80 ( V_95 ) ;
} else{
F_80 ( V_173 ) = V_96 ;
V_173 = V_96 ;
V_96 = F_80 ( V_96 ) ;
}
}
if( V_95 ) F_80 ( V_173 ) = V_95 ;
else F_80 ( V_173 ) = V_96 ;
}
return V_174 ;
}
T_2 char * F_9 (
char * V_175 ,
char * * V_26 ,
int (* F_79)( const char * , const char * )
) {
unsigned long V_172 ;
char * V_176 ;
char * V_177 [ V_178 ] ;
int V_9 ;
V_172 = ( unsigned long ) ( ( char * ) V_26 - ( char * ) V_175 ) ;
for( V_9 = 0 ; V_9 < V_178 ; V_9 ++ ) V_177 [ V_9 ] = 0 ;
while( V_175 ) {
V_176 = V_175 ;
V_175 = F_80 ( V_175 ) ;
F_80 ( V_176 ) = 0 ;
for( V_9 = 0 ; V_9 < V_178 - 1 && V_177 [ V_9 ] != 0 ; V_9 ++ ) {
V_176 = F_78 ( V_176 , V_177 [ V_9 ] , F_79 , ( int ) V_172 ) ;
V_177 [ V_9 ] = 0 ;
}
V_177 [ V_9 ] = V_176 ;
}
V_176 = 0 ;
for( V_9 = 0 ; V_9 < V_178 ; V_9 ++ ) if( V_177 [ V_9 ] ) V_176 = F_78 ( V_177 [ V_9 ] , V_176 , F_79 , ( int ) V_172 ) ;
return V_176 ;
}
static void F_81 ( int V_51 , int V_11 , T_5 * V_179 )
{
int V_180 , V_9 ;
if( V_149 [ 0 ] ) fprintf ( V_179 , L_59 , V_149 [ 0 ] ) ;
V_180 = F_58 ( V_149 [ 0 ] ) + 1 ;
for( V_9 = 1 ; V_9 < V_51 && V_149 [ V_9 ] ; V_9 ++ ) {
fprintf ( V_179 , L_60 , V_149 [ V_9 ] ) ;
V_180 += F_58 ( V_149 [ V_9 ] ) + 1 ;
}
V_180 += V_11 ;
for(; V_149 [ V_9 ] ; V_9 ++ ) fprintf ( V_179 , L_60 , V_149 [ V_9 ] ) ;
if( V_180 < 20 ) {
fprintf ( V_179 , L_61 , V_180 , L_62 ) ;
} else{
fprintf ( V_179 , L_63 , V_180 - 7 , L_62 ) ;
}
}
static int F_82 ( int V_51 )
{
int V_9 ;
int V_181 = 0 ;
if( V_149 != 0 && * V_149 != 0 ) {
for( V_9 = 1 ; V_149 [ V_9 ] ; V_9 ++ ) {
if( V_181 || ! F_83 ( V_149 [ V_9 ] ) ) {
if( V_51 == 0 ) return V_9 ;
V_51 -- ;
}
if( strcmp ( V_149 [ V_9 ] , L_64 ) == 0 ) V_181 = 1 ;
}
}
return - 1 ;
}
static int F_84 ( int V_9 , T_5 * V_179 )
{
int V_16 ;
int V_119 = 0 ;
int V_10 ;
for( V_10 = 0 ; V_182 [ V_10 ] . V_183 ; V_10 ++ ) {
if( strncmp ( & V_149 [ V_9 ] [ 1 ] , V_182 [ V_10 ] . V_183 , F_58 ( V_182 [ V_10 ] . V_183 ) ) == 0 ) break;
}
V_16 = V_149 [ V_9 ] [ 0 ] == '-' ? 1 : 0 ;
if( V_182 [ V_10 ] . V_183 == 0 ) {
if( V_179 ) {
fprintf ( V_179 , L_65 , V_184 ) ;
F_81 ( V_9 , 1 , V_179 ) ;
}
V_119 ++ ;
} else if( V_182 [ V_10 ] . V_37 == 0 ) {
} else if( V_182 [ V_10 ] . type == V_161 ) {
* ( ( int * ) V_182 [ V_10 ] . V_37 ) = V_16 ;
} else if( V_182 [ V_10 ] . type == V_185 ) {
( * ( void ( * ) ( int ) ) ( V_182 [ V_10 ] . V_37 ) ) ( V_16 ) ;
} else if( V_182 [ V_10 ] . type == V_162 ) {
( * ( void ( * ) ( char * ) ) ( V_182 [ V_10 ] . V_37 ) ) ( & V_149 [ V_9 ] [ 2 ] ) ;
} else{
if( V_179 ) {
fprintf ( V_179 , L_66 , V_184 ) ;
F_81 ( V_9 , 1 , V_179 ) ;
}
V_119 ++ ;
}
return V_119 ;
}
static int F_85 ( int V_9 , T_5 * V_179 )
{
int V_186 = 0 ;
double V_187 = 0.0 ;
char * V_188 = 0 , * V_189 ;
char * V_142 ;
int V_10 ;
int V_119 = 0 ;
V_142 = strchr ( V_149 [ V_9 ] , '=' ) ;
assert ( V_142 != 0 ) ;
* V_142 = 0 ;
for( V_10 = 0 ; V_182 [ V_10 ] . V_183 ; V_10 ++ ) {
if( strcmp ( V_149 [ V_9 ] , V_182 [ V_10 ] . V_183 ) == 0 ) break;
}
* V_142 = '=' ;
if( V_182 [ V_10 ] . V_183 == 0 ) {
if( V_179 ) {
fprintf ( V_179 , L_65 , V_184 ) ;
F_81 ( V_9 , 0 , V_179 ) ;
}
V_119 ++ ;
} else{
V_142 ++ ;
switch( V_182 [ V_10 ] . type ) {
case V_161 :
case V_185 :
if( V_179 ) {
fprintf ( V_179 , L_67 , V_184 ) ;
F_81 ( V_9 , 0 , V_179 ) ;
}
V_119 ++ ;
break;
case V_190 :
case V_191 :
V_187 = strtod ( V_142 , & V_189 ) ;
if( * V_189 ) {
if( V_179 ) {
fprintf ( V_179 , L_68 , V_184 ) ;
F_81 ( V_9 , ( int ) ( ( char * ) V_189 - ( char * ) V_149 [ V_9 ] ) , V_179 ) ;
}
V_119 ++ ;
}
break;
case V_192 :
case V_193 :
V_186 = ( int ) strtol ( V_142 , & V_189 , 0 ) ;
if( * V_189 ) {
if( V_179 ) {
fprintf ( V_179 , L_69 , V_184 ) ;
F_81 ( V_9 , ( int ) ( ( char * ) V_189 - ( char * ) V_149 [ V_9 ] ) , V_179 ) ;
}
V_119 ++ ;
}
break;
case V_194 :
case V_162 :
V_188 = V_142 ;
break;
}
switch( V_182 [ V_10 ] . type ) {
case V_161 :
case V_185 :
break;
case V_190 :
* ( double * ) ( V_182 [ V_10 ] . V_37 ) = V_187 ;
break;
case V_191 :
( * ( void ( * ) ( double ) ) ( V_182 [ V_10 ] . V_37 ) ) ( V_187 ) ;
break;
case V_192 :
* ( int * ) ( V_182 [ V_10 ] . V_37 ) = V_186 ;
break;
case V_193 :
( * ( void ( * ) ( int ) ) ( V_182 [ V_10 ] . V_37 ) ) ( ( int ) V_186 ) ;
break;
case V_194 :
* ( char * * ) ( V_182 [ V_10 ] . V_37 ) = V_188 ;
break;
case V_162 :
( * ( void ( * ) ( char * ) ) ( V_182 [ V_10 ] . V_37 ) ) ( V_188 ) ;
break;
}
}
return V_119 ;
}
int F_60 ( char * * V_95 , struct V_159 * V_195 , T_5 * V_179 )
{
int V_119 = 0 ;
V_149 = V_95 ;
V_182 = V_195 ;
V_196 = V_179 ;
if( V_149 && * V_149 && V_182 ) {
int V_9 ;
for( V_9 = 1 ; V_149 [ V_9 ] ; V_9 ++ ) {
if( V_149 [ V_9 ] [ 0 ] == '+' || V_149 [ V_9 ] [ 0 ] == '-' ) {
V_119 += F_84 ( V_9 , V_179 ) ;
} else if( strchr ( V_149 [ V_9 ] , '=' ) ) {
V_119 += F_85 ( V_9 , V_179 ) ;
}
}
}
if( V_119 > 0 ) {
fprintf ( V_179 , L_70 , * V_95 ) ;
F_86 () ;
exit ( 1 ) ;
}
return 0 ;
}
int F_61 ( void ) {
int V_197 = 0 ;
int V_181 = 0 ;
int V_9 ;
if( V_149 != 0 && V_149 [ 0 ] != 0 ) {
for( V_9 = 1 ; V_149 [ V_9 ] ; V_9 ++ ) {
if( V_181 || ! F_83 ( V_149 [ V_9 ] ) ) V_197 ++ ;
if( strcmp ( V_149 [ V_9 ] , L_64 ) == 0 ) V_181 = 1 ;
}
}
return V_197 ;
}
char * F_65 ( int V_51 )
{
int V_9 ;
V_9 = F_82 ( V_51 ) ;
return V_9 >= 0 ? V_149 [ V_9 ] : 0 ;
}
void F_87 ( int V_51 )
{
int V_9 ;
V_9 = F_82 ( V_51 ) ;
if( V_9 >= 0 ) F_81 ( V_9 , 0 , V_196 ) ;
}
void F_86 ( void ) {
int V_9 ;
int V_198 , V_199 ;
V_198 = 0 ;
for( V_9 = 0 ; V_182 [ V_9 ] . V_183 ; V_9 ++ ) {
V_199 = F_58 ( V_182 [ V_9 ] . V_183 ) + 1 ;
switch( V_182 [ V_9 ] . type ) {
case V_161 :
case V_185 :
break;
case V_192 :
case V_193 :
V_199 += 9 ;
break;
case V_190 :
case V_191 :
V_199 += 6 ;
break;
case V_194 :
case V_162 :
V_199 += 8 ;
break;
}
if( V_199 > V_198 ) V_198 = V_199 ;
}
for( V_9 = 0 ; V_182 [ V_9 ] . V_183 ; V_9 ++ ) {
switch( V_182 [ V_9 ] . type ) {
case V_161 :
case V_185 :
fprintf ( V_196 , L_71 , V_198 , V_182 [ V_9 ] . V_183 , V_182 [ V_9 ] . V_200 ) ;
break;
case V_192 :
case V_193 :
fprintf ( V_196 , L_72 , V_182 [ V_9 ] . V_183 ,
( int ) ( V_198 - F_58 ( V_182 [ V_9 ] . V_183 ) - 9 ) , L_62 , V_182 [ V_9 ] . V_200 ) ;
break;
case V_190 :
case V_191 :
fprintf ( V_196 , L_73 , V_182 [ V_9 ] . V_183 ,
( int ) ( V_198 - F_58 ( V_182 [ V_9 ] . V_183 ) - 6 ) , L_62 , V_182 [ V_9 ] . V_200 ) ;
break;
case V_194 :
case V_162 :
fprintf ( V_196 , L_74 , V_182 [ V_9 ] . V_183 ,
( int ) ( V_198 - F_58 ( V_182 [ V_9 ] . V_183 ) - 8 ) , L_62 , V_182 [ V_9 ] . V_200 ) ;
break;
}
}
}
static void F_88 ( struct V_201 * V_202 )
{
const char * V_32 ;
V_32 = F_89 ( V_202 -> V_203 ) ;
#if 0
printf("%s:%d: Token=[%s] state=%d\n",psp->filename,psp->tokenlineno,
x,psp->state);
#endif
switch( V_202 -> V_40 ) {
case V_204 :
V_202 -> V_205 = 0 ;
V_202 -> V_206 = 0 ;
V_202 -> V_207 = V_202 -> V_208 = 0 ;
V_202 -> V_209 -> V_169 = 0 ;
case V_210 :
if( V_32 [ 0 ] == '%' ) {
V_202 -> V_40 = V_211 ;
} else if( islower ( V_32 [ 0 ] ) ) {
V_202 -> V_73 = F_66 ( V_32 ) ;
V_202 -> V_59 = 0 ;
V_202 -> V_212 = 0 ;
V_202 -> V_40 = V_213 ;
} else if( V_32 [ 0 ] == '{' ) {
if( V_202 -> V_205 == 0 ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_75 ) ;
V_202 -> V_82 ++ ;
} else if( V_202 -> V_205 -> V_215 != 0 ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_76 ) ;
V_202 -> V_82 ++ ;
} else{
V_202 -> V_205 -> line = V_202 -> V_214 ;
V_202 -> V_205 -> V_215 = & V_32 [ 1 ] ;
}
} else if( V_32 [ 0 ] == '[' ) {
V_202 -> V_40 = V_216 ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_77 ,
V_32 ) ;
V_202 -> V_82 ++ ;
}
break;
case V_216 :
if( ! isupper ( V_32 [ 0 ] ) ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_78 ) ;
V_202 -> V_82 ++ ;
} else if( V_202 -> V_205 == 0 ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_79 , V_32 ) ;
V_202 -> V_82 ++ ;
} else if( V_202 -> V_205 -> V_58 != 0 ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_80 ) ;
V_202 -> V_82 ++ ;
} else{
V_202 -> V_205 -> V_58 = F_66 ( V_32 ) ;
}
V_202 -> V_40 = V_217 ;
break;
case V_217 :
if( V_32 [ 0 ] != ']' ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_81 ) ;
V_202 -> V_82 ++ ;
}
V_202 -> V_40 = V_210 ;
break;
case V_213 :
if( V_32 [ 0 ] == ':' && V_32 [ 1 ] == ':' && V_32 [ 2 ] == '=' ) {
V_202 -> V_40 = V_218 ;
} else if( V_32 [ 0 ] == '(' ) {
V_202 -> V_40 = V_219 ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_82 ,
V_202 -> V_73 -> V_81 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_220 ;
}
break;
case V_219 :
if( isalpha ( V_32 [ 0 ] ) ) {
V_202 -> V_212 = V_32 ;
V_202 -> V_40 = V_221 ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_83 ,
V_32 , V_202 -> V_73 -> V_81 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_220 ;
}
break;
case V_221 :
if( V_32 [ 0 ] == ')' ) {
V_202 -> V_40 = V_222 ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_84 , V_202 -> V_212 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_220 ;
}
break;
case V_222 :
if( V_32 [ 0 ] == ':' && V_32 [ 1 ] == ':' && V_32 [ 2 ] == '=' ) {
V_202 -> V_40 = V_218 ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_85 ,
V_202 -> V_73 -> V_81 , V_202 -> V_212 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_220 ;
}
break;
case V_218 :
if( V_32 [ 0 ] == '.' ) {
struct V_41 * V_33 ;
V_33 = (struct V_41 * ) calloc ( sizeof( struct V_41 ) +
sizeof( struct V_36 * ) * V_202 -> V_59 + sizeof( char * ) * V_202 -> V_59 , 1 ) ;
if( V_33 == 0 ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_86 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_205 = 0 ;
} else{
int V_9 ;
V_33 -> V_114 = V_202 -> V_214 ;
V_33 -> V_60 = (struct V_36 * * ) & V_33 [ 1 ] ;
V_33 -> V_223 = ( const char * * ) & ( V_33 -> V_60 [ V_202 -> V_59 ] ) ;
for( V_9 = 0 ; V_9 < V_202 -> V_59 ; V_9 ++ ) {
V_33 -> V_60 [ V_9 ] = V_202 -> V_60 [ V_9 ] ;
V_33 -> V_223 [ V_9 ] = V_202 -> V_224 [ V_9 ] ;
}
V_33 -> V_73 = V_202 -> V_73 ;
V_33 -> V_212 = V_202 -> V_212 ;
V_33 -> V_59 = V_202 -> V_59 ;
V_33 -> V_215 = 0 ;
V_33 -> V_58 = 0 ;
V_33 -> V_30 = V_202 -> V_209 -> V_169 ++ ;
V_33 -> V_83 = V_33 -> V_73 -> V_41 ;
V_33 -> V_73 -> V_41 = V_33 ;
V_33 -> V_26 = 0 ;
if( V_202 -> V_207 == 0 ) {
V_202 -> V_207 = V_202 -> V_208 = V_33 ;
} else{
V_202 -> V_208 -> V_26 = V_33 ;
V_202 -> V_208 = V_33 ;
}
V_202 -> V_205 = V_33 ;
}
V_202 -> V_40 = V_210 ;
} else if( isalpha ( V_32 [ 0 ] ) ) {
if( V_202 -> V_59 >= V_225 ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_87 ,
V_32 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_220 ;
} else{
V_202 -> V_60 [ V_202 -> V_59 ] = F_66 ( V_32 ) ;
V_202 -> V_224 [ V_202 -> V_59 ] = 0 ;
V_202 -> V_59 ++ ;
}
} else if( ( V_32 [ 0 ] == '|' || V_32 [ 0 ] == '/' ) && V_202 -> V_59 > 0 ) {
struct V_36 * V_226 = V_202 -> V_60 [ V_202 -> V_59 - 1 ] ;
if( V_226 -> type != V_61 ) {
struct V_36 * V_227 = V_226 ;
V_226 = (struct V_36 * ) calloc ( 1 , sizeof( * V_226 ) ) ;
memset ( V_226 , 0 , sizeof( * V_226 ) ) ;
V_226 -> type = V_61 ;
V_226 -> V_62 = 1 ;
V_226 -> V_63 = (struct V_36 * * ) calloc ( 1 , sizeof( struct V_36 * ) ) ;
V_226 -> V_63 [ 0 ] = V_227 ;
V_226 -> V_81 = V_227 -> V_81 ;
V_202 -> V_60 [ V_202 -> V_59 - 1 ] = V_226 ;
}
V_226 -> V_62 ++ ;
V_226 -> V_63 = (struct V_36 * * ) realloc ( V_226 -> V_63 ,
sizeof( struct V_36 * ) * V_226 -> V_62 ) ;
V_226 -> V_63 [ V_226 -> V_62 - 1 ] = F_66 ( & V_32 [ 1 ] ) ;
if( islower ( V_32 [ 1 ] ) || islower ( V_226 -> V_63 [ 0 ] -> V_81 [ 0 ] ) ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_88 ) ;
V_202 -> V_82 ++ ;
}
} else if( V_32 [ 0 ] == '(' && V_202 -> V_59 > 0 ) {
V_202 -> V_40 = V_228 ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_89 , V_32 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_220 ;
}
break;
case V_228 :
if( isalpha ( V_32 [ 0 ] ) ) {
V_202 -> V_224 [ V_202 -> V_59 - 1 ] = V_32 ;
V_202 -> V_40 = V_229 ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_90 ,
V_32 , V_202 -> V_60 [ V_202 -> V_59 - 1 ] -> V_81 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_220 ;
}
break;
case V_229 :
if( V_32 [ 0 ] == ')' ) {
V_202 -> V_40 = V_218 ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_84 , V_202 -> V_212 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_220 ;
}
break;
case V_211 :
if( isalpha ( V_32 [ 0 ] ) ) {
V_202 -> V_230 = V_32 ;
V_202 -> V_231 = 0 ;
V_202 -> V_232 = 0 ;
V_202 -> V_233 = 1 ;
V_202 -> V_40 = V_234 ;
if( strcmp ( V_32 , L_91 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> V_81 ) ;
V_202 -> V_233 = 0 ;
} else if( strcmp ( V_32 , L_92 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> include ) ;
} else if( strcmp ( V_32 , L_93 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> V_235 ) ;
} else if( strcmp ( V_32 , L_94 ) == 0 ) {
V_202 -> V_231 = & V_202 -> V_209 -> V_236 ;
} else if( strcmp ( V_32 , L_95 ) == 0 ) {
V_202 -> V_231 = & V_202 -> V_209 -> V_237 ;
} else if( strcmp ( V_32 , L_96 ) == 0 ) {
V_202 -> V_231 = & V_202 -> V_209 -> V_238 ;
V_202 -> V_233 = 0 ;
} else if( strcmp ( V_32 , L_97 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> error ) ;
} else if( strcmp ( V_32 , L_98 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> V_239 ) ;
} else if( strcmp ( V_32 , L_99 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> V_240 ) ;
} else if( strcmp ( V_32 , L_100 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> V_241 ) ;
} else if( strcmp ( V_32 , L_101 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> V_37 ) ;
V_202 -> V_233 = 0 ;
} else if( strcmp ( V_32 , L_102 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> V_242 ) ;
V_202 -> V_233 = 0 ;
} else if( strcmp ( V_32 , L_103 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> V_243 ) ;
V_202 -> V_233 = 0 ;
} else if( strcmp ( V_32 , L_104 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> V_244 ) ;
V_202 -> V_233 = 0 ;
} else if( strcmp ( V_32 , L_105 ) == 0 ) {
V_202 -> V_231 = & ( V_202 -> V_209 -> V_79 ) ;
V_202 -> V_233 = 0 ;
} else if( strcmp ( V_32 , L_106 ) == 0 ) {
V_202 -> V_206 ++ ;
V_202 -> V_245 = V_126 ;
V_202 -> V_40 = V_246 ;
} else if( strcmp ( V_32 , L_107 ) == 0 ) {
V_202 -> V_206 ++ ;
V_202 -> V_245 = V_125 ;
V_202 -> V_40 = V_246 ;
} else if( strcmp ( V_32 , L_108 ) == 0 ) {
V_202 -> V_206 ++ ;
V_202 -> V_245 = V_127 ;
V_202 -> V_40 = V_246 ;
} else if( strcmp ( V_32 , L_109 ) == 0 ) {
V_202 -> V_40 = V_247 ;
} else if( strcmp ( V_32 , L_110 ) == 0 ) {
V_202 -> V_40 = V_248 ;
} else if( strcmp ( V_32 , L_111 ) == 0 ) {
V_202 -> V_249 = 0 ;
V_202 -> V_40 = V_250 ;
} else if( strcmp ( V_32 , L_112 ) == 0 ) {
V_202 -> V_40 = V_251 ;
} else if( strcmp ( V_32 , L_113 ) == 0 ) {
V_202 -> V_40 = V_252 ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_114 , V_32 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_253 ;
}
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_115 , V_32 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_253 ;
}
break;
case V_247 :
if( ! isalpha ( V_32 [ 0 ] ) ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_116 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_253 ;
} else{
struct V_36 * V_29 = F_66 ( V_32 ) ;
V_202 -> V_231 = & V_29 -> V_254 ;
V_202 -> V_232 = & V_29 -> V_255 ;
V_202 -> V_233 = 1 ;
V_202 -> V_40 = V_234 ;
}
break;
case V_248 :
if( ! isalpha ( V_32 [ 0 ] ) ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_117 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_253 ;
} else{
struct V_36 * V_29 = F_21 ( V_32 ) ;
if( ( V_29 ) && ( V_29 -> V_256 ) ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_118 , V_32 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_253 ;
} else{
if ( ! V_29 ) {
V_29 = F_66 ( V_32 ) ;
}
V_202 -> V_231 = & V_29 -> V_256 ;
V_202 -> V_233 = 0 ;
V_202 -> V_40 = V_234 ;
}
}
break;
case V_246 :
if( V_32 [ 0 ] == '.' ) {
V_202 -> V_40 = V_210 ;
} else if( isupper ( V_32 [ 0 ] ) ) {
struct V_36 * V_29 ;
V_29 = F_66 ( V_32 ) ;
if( V_29 -> V_64 >= 0 ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_119 , V_32 ) ;
V_202 -> V_82 ++ ;
} else{
V_29 -> V_64 = V_202 -> V_206 ;
V_29 -> V_124 = V_202 -> V_245 ;
}
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_120 , V_32 ) ;
V_202 -> V_82 ++ ;
}
break;
case V_234 :
if( V_32 [ 0 ] == '{' || V_32 [ 0 ] == '\"' || isalnum ( V_32 [ 0 ] ) ) {
const char * V_257 , * V_258 ;
char * V_1 , * V_14 ;
int V_259 , V_51 , V_260 = 0 , V_261 , V_262 ;
int V_263 ;
char V_264 [ 50 ] ;
V_258 = V_32 ;
if( V_258 [ 0 ] == '"' || V_258 [ 0 ] == '{' ) V_258 ++ ;
V_261 = F_58 ( V_258 ) ;
if( * V_202 -> V_231 ) {
V_257 = * V_202 -> V_231 ;
} else{
V_257 = L_62 ;
}
V_259 = F_58 ( V_257 ) ;
V_51 = V_259 + V_261 + 20 ;
V_263 = ! V_202 -> V_209 -> V_157 && V_202 -> V_233 &&
( V_202 -> V_232 == 0 || V_202 -> V_232 [ 0 ] != 0 ) ;
if( V_263 ) {
for( V_14 = V_202 -> V_80 , V_262 = 0 ; * V_14 ; V_14 ++ ) {
if( * V_14 == '\\' ) V_262 ++ ;
}
F_3 ( V_264 , L_121 , V_202 -> V_214 ) ;
V_260 = F_58 ( V_264 ) ;
V_51 += V_260 + F_58 ( V_202 -> V_80 ) + V_262 ;
}
* V_202 -> V_231 = ( char * ) realloc ( * V_202 -> V_231 , V_51 ) ;
V_1 = * V_202 -> V_231 + V_259 ;
if( V_263 ) {
if( V_259 && V_1 [ - 1 ] != '\n' ) {
* ( V_1 ++ ) = '\n' ;
}
memcpy ( V_1 , V_264 , V_260 ) ;
V_1 += V_260 ;
* ( V_1 ++ ) = '"' ;
for( V_14 = V_202 -> V_80 ; * V_14 ; V_14 ++ ) {
if( * V_14 == '\\' ) {
* ( V_1 ++ ) = '\\' ;
}
* ( V_1 ++ ) = * V_14 ;
}
* ( V_1 ++ ) = '"' ;
* ( V_1 ++ ) = '\n' ;
}
if( V_202 -> V_232 && V_202 -> V_232 [ 0 ] == 0 ) {
V_202 -> V_232 [ 0 ] = V_202 -> V_214 ;
}
memcpy ( V_1 , V_258 , V_261 ) ;
V_1 += V_261 ;
* V_1 = 0 ;
V_202 -> V_40 = V_210 ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_122 , V_202 -> V_230 , V_32 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_253 ;
}
break;
case V_250 :
if( V_32 [ 0 ] == '.' ) {
V_202 -> V_40 = V_210 ;
} else if( ! isupper ( V_32 [ 0 ] ) ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_123 , V_32 ) ;
V_202 -> V_82 ++ ;
} else{
struct V_36 * V_29 = F_66 ( V_32 ) ;
if( V_202 -> V_249 == 0 ) {
V_202 -> V_249 = V_29 ;
} else if( V_29 -> V_249 ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_124 , V_32 ) ;
V_202 -> V_82 ++ ;
} else{
V_29 -> V_249 = V_202 -> V_249 ;
V_202 -> V_209 -> V_265 = 1 ;
}
}
break;
case V_251 :
if( V_32 [ 0 ] == '.' ) {
V_202 -> V_40 = V_210 ;
} else if( ! isupper ( V_32 [ 0 ] ) ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_125 , V_32 ) ;
V_202 -> V_82 ++ ;
} else{
struct V_36 * V_29 = F_66 ( V_32 ) ;
if( V_202 -> V_209 -> V_266 == 0 ) {
V_202 -> V_209 -> V_266 = V_29 ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_126 , V_32 ) ;
V_202 -> V_82 ++ ;
}
}
break;
case V_252 :
if( ! islower ( V_32 [ 0 ] ) ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_127 , V_32 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_253 ;
} else if( F_21 ( V_32 ) ) {
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_128 , V_32 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_253 ;
} else{
V_202 -> V_267 = F_66 ( V_32 ) ;
V_202 -> V_267 -> type = V_61 ;
V_202 -> V_40 = V_268 ;
}
break;
case V_268 :
if( V_32 [ 0 ] == '.' ) {
V_202 -> V_40 = V_210 ;
} else if( isupper ( V_32 [ 0 ] ) || ( ( V_32 [ 0 ] == '|' || V_32 [ 0 ] == '/' ) && isupper ( V_32 [ 1 ] ) ) ) {
struct V_36 * V_226 = V_202 -> V_267 ;
V_226 -> V_62 ++ ;
V_226 -> V_63 = (struct V_36 * * ) realloc ( V_226 -> V_63 ,
sizeof( struct V_36 * ) * V_226 -> V_62 ) ;
if( ! isupper ( V_32 [ 0 ] ) ) V_32 ++ ;
V_226 -> V_63 [ V_226 -> V_62 - 1 ] = F_66 ( V_32 ) ;
} else{
F_22 ( V_202 -> V_80 , V_202 -> V_214 ,
L_129 , V_32 ) ;
V_202 -> V_82 ++ ;
V_202 -> V_40 = V_253 ;
}
break;
case V_220 :
case V_253 :
if( V_32 [ 0 ] == '.' ) V_202 -> V_40 = V_210 ;
if( V_32 [ 0 ] == '%' ) V_202 -> V_40 = V_211 ;
break;
}
}
static void F_90 ( char * V_14 ) {
int V_9 , V_10 , V_11 , V_51 ;
int V_269 = 0 ;
int V_79 = 0 ;
int V_140 = 1 ;
int V_270 = 1 ;
for( V_9 = 0 ; V_14 [ V_9 ] ; V_9 ++ ) {
if( V_14 [ V_9 ] == '\n' ) V_140 ++ ;
if( V_14 [ V_9 ] != '%' || ( V_9 > 0 && V_14 [ V_9 - 1 ] != '\n' ) ) continue;
if( strncmp ( & V_14 [ V_9 ] , L_130 , 6 ) == 0 && isspace ( V_14 [ V_9 + 6 ] ) ) {
if( V_269 ) {
V_269 -- ;
if( V_269 == 0 ) {
for( V_10 = V_79 ; V_10 < V_9 ; V_10 ++ ) if( V_14 [ V_10 ] != '\n' ) V_14 [ V_10 ] = ' ' ;
}
}
for( V_10 = V_9 ; V_14 [ V_10 ] && V_14 [ V_10 ] != '\n' ; V_10 ++ ) V_14 [ V_10 ] = ' ' ;
} else if( ( strncmp ( & V_14 [ V_9 ] , L_131 , 6 ) == 0 && isspace ( V_14 [ V_9 + 6 ] ) )
|| ( strncmp ( & V_14 [ V_9 ] , L_132 , 7 ) == 0 && isspace ( V_14 [ V_9 + 7 ] ) ) ) {
if( V_269 ) {
V_269 ++ ;
} else{
for( V_10 = V_9 + 7 ; isspace ( V_14 [ V_10 ] ) ; V_10 ++ ) {}
for( V_51 = 0 ; V_14 [ V_10 + V_51 ] && ! isspace ( V_14 [ V_10 + V_51 ] ) ; V_51 ++ ) {}
V_269 = 1 ;
for( V_11 = 0 ; V_11 < V_145 ; V_11 ++ ) {
if( strncmp ( V_146 [ V_11 ] , & V_14 [ V_10 ] , V_51 ) == 0 && F_58 ( V_146 [ V_11 ] ) == V_51 ) {
V_269 = 0 ;
break;
}
}
if( V_14 [ V_9 + 3 ] == 'n' ) V_269 = ! V_269 ;
if( V_269 ) {
V_79 = V_9 ;
V_270 = V_140 ;
}
}
for( V_10 = V_9 ; V_14 [ V_10 ] && V_14 [ V_10 ] != '\n' ; V_10 ++ ) V_14 [ V_10 ] = ' ' ;
}
}
if( V_269 ) {
fprintf ( V_17 , L_133 , V_270 ) ;
exit ( 1 ) ;
}
}
void F_67 ( struct V_56 * V_209 )
{
struct V_201 V_271 ;
T_5 * V_272 ;
char * V_273 ;
unsigned long int V_274 ;
int V_140 ;
int V_12 ;
char * V_142 , * V_275 ;
int V_276 = 0 ;
memset ( & V_271 , '\0' , sizeof( V_271 ) ) ;
V_271 . V_209 = V_209 ;
V_271 . V_80 = V_209 -> V_80 ;
V_271 . V_82 = 0 ;
V_271 . V_40 = V_204 ;
V_272 = fopen ( V_271 . V_80 , L_134 ) ;
if( V_272 == 0 ) {
F_22 ( V_271 . V_80 , 0 , L_135 ) ;
V_209 -> V_82 ++ ;
return;
}
fseek ( V_272 , 0 , 2 ) ;
V_274 = ftell ( V_272 ) ;
rewind ( V_272 ) ;
V_273 = ( char * ) malloc ( V_274 + 1 ) ;
if( V_274 > 100000000 || V_273 == 0 ) {
F_22 ( V_271 . V_80 , 0 , L_136 ) ;
V_209 -> V_82 ++ ;
fclose ( V_272 ) ;
return;
}
if( fread ( V_273 , 1 , V_274 , V_272 ) != V_274 ) {
F_22 ( V_271 . V_80 , 0 , L_137 ,
V_274 ) ;
free ( V_273 ) ;
V_209 -> V_82 ++ ;
fclose ( V_272 ) ;
return;
}
fclose ( V_272 ) ;
V_273 [ V_274 ] = 0 ;
F_90 ( V_273 ) ;
V_140 = 1 ;
for( V_142 = V_273 ; ( V_12 = * V_142 ) != 0 ; ) {
if( V_12 == '\n' ) V_140 ++ ;
if( isspace ( V_12 ) ) { V_142 ++ ; continue; }
if( V_12 == '/' && V_142 [ 1 ] == '/' ) {
V_142 += 2 ;
while( ( V_12 = * V_142 ) != 0 && V_12 != '\n' ) V_142 ++ ;
continue;
}
if( V_12 == '/' && V_142 [ 1 ] == '*' ) {
V_142 += 2 ;
while( ( V_12 = * V_142 ) != 0 && ( V_12 != '/' || V_142 [ - 1 ] != '*' ) ) {
if( V_12 == '\n' ) V_140 ++ ;
V_142 ++ ;
}
if( V_12 ) V_142 ++ ;
continue;
}
V_271 . V_203 = V_142 ;
V_271 . V_214 = V_140 ;
if( V_12 == '\"' ) {
V_142 ++ ;
while( ( V_12 = * V_142 ) != 0 && V_12 != '\"' ) {
if( V_12 == '\n' ) V_140 ++ ;
V_142 ++ ;
}
if( V_12 == 0 ) {
F_22 ( V_271 . V_80 , V_276 ,
L_138 ) ;
V_271 . V_82 ++ ;
V_275 = V_142 ;
} else{
V_275 = V_142 + 1 ;
}
} else if( V_12 == '{' ) {
int V_277 ;
V_142 ++ ;
for( V_277 = 1 ; ( V_12 = * V_142 ) != 0 && ( V_277 > 1 || V_12 != '}' ) ; V_142 ++ ) {
if( V_12 == '\n' ) V_140 ++ ;
else if( V_12 == '{' ) V_277 ++ ;
else if( V_12 == '}' ) V_277 -- ;
else if( V_12 == '/' && V_142 [ 1 ] == '*' ) {
int V_278 ;
V_142 = & V_142 [ 2 ] ;
V_278 = 0 ;
while( ( V_12 = * V_142 ) != 0 && ( V_12 != '/' || V_278 != '*' ) ) {
if( V_12 == '\n' ) V_140 ++ ;
V_278 = V_12 ;
V_142 ++ ;
}
} else if( V_12 == '/' && V_142 [ 1 ] == '/' ) {
V_142 = & V_142 [ 2 ] ;
while( ( V_12 = * V_142 ) != 0 && V_12 != '\n' ) V_142 ++ ;
if( V_12 ) V_140 ++ ;
} else if( V_12 == '\'' || V_12 == '\"' ) {
int V_279 , V_278 ;
V_279 = V_12 ;
V_278 = 0 ;
for( V_142 ++ ; ( V_12 = * V_142 ) != 0 && ( V_12 != V_279 || V_278 == '\\' ) ; V_142 ++ ) {
if( V_12 == '\n' ) V_140 ++ ;
if( V_278 == '\\' ) V_278 = 0 ;
else V_278 = V_12 ;
}
}
}
if( V_12 == 0 ) {
F_22 ( V_271 . V_80 , V_271 . V_214 ,
L_139 ) ;
V_271 . V_82 ++ ;
V_275 = V_142 ;
} else{
V_275 = V_142 + 1 ;
}
} else if( isalnum ( V_12 ) ) {
while( ( V_12 = * V_142 ) != 0 && ( isalnum ( V_12 ) || V_12 == '_' ) ) V_142 ++ ;
V_275 = V_142 ;
} else if( V_12 == ':' && V_142 [ 1 ] == ':' && V_142 [ 2 ] == '=' ) {
V_142 += 3 ;
V_275 = V_142 ;
} else if( ( V_12 == '/' || V_12 == '|' ) && isalpha ( V_142 [ 1 ] ) ) {
V_142 += 2 ;
while( ( V_12 = * V_142 ) != 0 && ( isalnum ( V_12 ) || V_12 == '_' ) ) V_142 ++ ;
V_275 = V_142 ;
} else{
V_142 ++ ;
V_275 = V_142 ;
}
V_12 = * V_142 ;
* V_142 = 0 ;
F_88 ( & V_271 ) ;
* V_142 = ( char ) V_12 ;
V_142 = V_275 ;
}
free ( V_273 ) ;
V_209 -> V_41 = V_271 . V_207 ;
V_209 -> V_82 = V_271 . V_82 ;
}
struct V_106 * F_91 ( void ) {
struct V_106 * V_280 ;
if( V_281 == 0 ) {
int V_9 ;
int V_25 = 100 ;
V_281 = (struct V_106 * ) calloc ( V_25 , sizeof( struct V_106 ) ) ;
if( V_281 == 0 ) {
fprintf ( V_17 ,
L_140 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_25 - 1 ; V_9 ++ ) V_281 [ V_9 ] . V_26 = & V_281 [ V_9 + 1 ] ;
V_281 [ V_25 - 1 ] . V_26 = 0 ;
}
V_280 = V_281 ;
V_281 = V_281 -> V_26 ;
return V_280 ;
}
void F_40 ( struct V_106 * * V_282 , struct V_84 * V_88 )
{
struct V_106 * V_280 ;
V_280 = F_91 () ;
V_280 -> V_26 = * V_282 ;
* V_282 = V_280 ;
V_280 -> V_88 = V_88 ;
}
void F_28 ( struct V_106 * * V_283 , struct V_106 * V_284 )
{
struct V_106 * V_285 ;
while( V_284 ) {
V_285 = V_284 -> V_26 ;
V_284 -> V_26 = * V_283 ;
* V_283 = V_284 ;
V_284 = V_285 ;
}
}
void F_29 ( struct V_106 * V_107 )
{
struct V_106 * V_285 ;
while( V_107 ) {
V_285 = V_107 -> V_26 ;
V_107 -> V_26 = V_281 ;
V_281 = V_107 ;
V_107 = V_285 ;
}
}
T_2 char * F_92 ( struct V_56 * V_65 , const char * V_286 )
{
char * V_81 ;
char * V_142 ;
V_81 = ( char * ) malloc ( F_58 ( V_65 -> V_80 ) + F_58 ( V_286 ) + 5 ) ;
if( V_81 == 0 ) {
fprintf ( V_17 , L_141 ) ;
exit ( 1 ) ;
}
F_4 ( V_81 , V_65 -> V_80 ) ;
V_142 = strrchr ( V_81 , '.' ) ;
if( V_142 ) * V_142 = 0 ;
F_5 ( V_81 , V_286 ) ;
return V_81 ;
}
T_2 char * F_93 ( struct V_56 * V_65 , const char * V_286 )
{
V_65 -> V_80 = V_65 -> V_168 ;
return F_92 ( V_65 , V_286 ) ;
}
T_2 T_5 * F_94 (
struct V_56 * V_65 ,
const char * V_286 ,
const char * V_287
) {
T_5 * V_272 ;
if( V_65 -> V_288 ) free ( V_65 -> V_288 ) ;
V_65 -> V_288 = F_93 ( V_65 , V_286 ) ;
V_272 = fopen ( V_65 -> V_288 , V_287 ) ;
if( V_272 == 0 && * V_287 == 'w' ) {
fprintf ( V_17 , L_142 , V_65 -> V_288 ) ;
V_65 -> V_82 ++ ;
return 0 ;
}
return V_272 ;
}
void F_70 ( struct V_56 * V_65 )
{
struct V_41 * V_33 ;
struct V_36 * V_29 ;
int V_9 , V_10 , V_289 , V_199 , V_290 , V_291 ;
printf ( L_143 , V_65 -> V_80 ) ;
V_289 = 10 ;
for( V_9 = 0 ; V_9 < V_65 -> V_67 ; V_9 ++ ) {
V_29 = V_65 -> V_68 [ V_9 ] ;
V_199 = F_58 ( V_29 -> V_81 ) ;
if( V_199 > V_289 ) V_289 = V_199 ;
}
V_290 = 76 / ( V_289 + 5 ) ;
if( V_290 < 1 ) V_290 = 1 ;
V_291 = ( V_65 -> V_67 + V_290 - 1 ) / V_290 ;
for( V_9 = 0 ; V_9 < V_291 ; V_9 ++ ) {
printf ( L_144 ) ;
for( V_10 = V_9 ; V_10 < V_65 -> V_67 ; V_10 += V_291 ) {
V_29 = V_65 -> V_68 [ V_10 ] ;
assert ( V_29 -> V_30 == V_10 ) ;
printf ( L_145 , V_10 , V_289 , V_289 , V_29 -> V_81 ) ;
}
printf ( L_15 ) ;
}
for( V_33 = V_65 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 ) {
printf ( L_59 , V_33 -> V_73 -> V_81 ) ;
printf ( L_146 ) ;
for( V_9 = 0 ; V_9 < V_33 -> V_59 ; V_9 ++ ) {
V_29 = V_33 -> V_60 [ V_9 ] ;
if( V_29 -> type == V_61 ) {
printf ( L_60 , V_29 -> V_63 [ 0 ] -> V_81 ) ;
for( V_10 = 1 ; V_10 < V_29 -> V_62 ; V_10 ++ ) {
printf ( L_147 , V_29 -> V_63 [ V_10 ] -> V_81 ) ;
}
} else{
printf ( L_60 , V_29 -> V_81 ) ;
}
}
printf ( L_148 ) ;
if( V_33 -> V_58 ) printf ( L_149 , V_33 -> V_58 -> V_81 ) ;
printf ( L_15 ) ;
}
}
T_2 void F_95 ( T_5 * V_272 , struct V_84 * V_88 )
{
struct V_41 * V_33 ;
struct V_36 * V_29 ;
int V_9 , V_10 ;
V_33 = V_88 -> V_33 ;
fprintf ( V_272 , L_150 , V_33 -> V_73 -> V_81 ) ;
for( V_9 = 0 ; V_9 <= V_33 -> V_59 ; V_9 ++ ) {
if( V_9 == V_88 -> V_104 ) fprintf ( V_272 , L_151 ) ;
if( V_9 == V_33 -> V_59 ) break;
V_29 = V_33 -> V_60 [ V_9 ] ;
if( V_29 -> type == V_61 ) {
fprintf ( V_272 , L_60 , V_29 -> V_63 [ 0 ] -> V_81 ) ;
for( V_10 = 1 ; V_10 < V_29 -> V_62 ; V_10 ++ ) {
fprintf ( V_272 , L_147 , V_29 -> V_63 [ V_10 ] -> V_81 ) ;
}
} else{
fprintf ( V_272 , L_60 , V_29 -> V_81 ) ;
}
}
}
T_2 int F_96 ( struct V_22 * V_8 , T_5 * V_272 , int V_292 ) {
int V_293 = 1 ;
switch( V_8 -> type ) {
case V_38 :
fprintf ( V_272 , L_152 , V_292 , V_8 -> V_29 -> V_81 , V_8 -> V_32 . V_39 -> V_93 ) ;
break;
case V_31 :
fprintf ( V_272 , L_153 , V_292 , V_8 -> V_29 -> V_81 , V_8 -> V_32 . V_33 -> V_30 ) ;
break;
case V_110 :
fprintf ( V_272 , L_154 , V_292 , V_8 -> V_29 -> V_81 ) ;
break;
case ERROR :
fprintf ( V_272 , L_155 , V_292 , V_8 -> V_29 -> V_81 ) ;
break;
case V_121 :
case V_128 :
fprintf ( V_272 , L_156 ,
V_292 , V_8 -> V_29 -> V_81 , V_8 -> V_32 . V_33 -> V_30 ) ;
break;
case V_120 :
fprintf ( V_272 , L_157 ,
V_292 , V_8 -> V_29 -> V_81 , V_8 -> V_32 . V_39 -> V_93 ) ;
break;
case V_123 :
if( V_163 ) {
fprintf ( V_272 , L_158 ,
V_292 , V_8 -> V_29 -> V_81 , V_8 -> V_32 . V_39 -> V_93 ) ;
} else{
V_293 = 0 ;
}
break;
case V_122 :
if( V_163 ) {
fprintf ( V_272 , L_159 ,
V_292 , V_8 -> V_29 -> V_81 , V_8 -> V_32 . V_33 -> V_30 ) ;
} else{
V_293 = 0 ;
}
break;
case V_294 :
V_293 = 0 ;
break;
}
return V_293 ;
}
void F_75 ( struct V_56 * V_65 )
{
int V_9 ;
struct V_40 * V_39 ;
struct V_84 * V_88 ;
struct V_22 * V_8 ;
T_5 * V_272 ;
V_272 = F_94 ( V_65 , L_160 , L_161 ) ;
if( V_272 == 0 ) return;
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
V_39 = V_65 -> V_108 [ V_9 ] ;
fprintf ( V_272 , L_162 , V_39 -> V_93 ) ;
if( V_65 -> V_152 ) V_88 = V_39 -> V_89 ;
else V_88 = V_39 -> V_88 ;
while( V_88 ) {
char V_295 [ 20 ] ;
if( V_88 -> V_104 == V_88 -> V_33 -> V_59 ) {
F_3 ( V_295 , L_163 , V_88 -> V_33 -> V_30 ) ;
fprintf ( V_272 , L_164 , V_295 ) ;
} else{
fprintf ( V_272 , L_165 ) ;
}
F_95 ( V_272 , V_88 ) ;
fprintf ( V_272 , L_15 ) ;
#if 0
SetPrint(fp,cfp->fws,lemp);
PlinkPrint(fp,cfp->fplp,"To ");
PlinkPrint(fp,cfp->bplp,"From");
#endif
if( V_65 -> V_152 ) V_88 = V_88 -> V_89 ;
else V_88 = V_88 -> V_26 ;
}
fprintf ( V_272 , L_15 ) ;
for( V_8 = V_39 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( F_96 ( V_8 , V_272 , 30 ) ) fprintf ( V_272 , L_15 ) ;
}
fprintf ( V_272 , L_15 ) ;
}
fprintf ( V_272 , L_166 ) ;
fprintf ( V_272 , L_167 ) ;
for( V_9 = 0 ; V_9 < V_65 -> V_67 ; V_9 ++ ) {
int V_10 ;
struct V_36 * V_29 ;
V_29 = V_65 -> V_68 [ V_9 ] ;
fprintf ( V_272 , L_168 , V_9 , V_29 -> V_81 ) ;
if( V_29 -> type == V_74 ) {
fprintf ( V_272 , L_169 ) ;
if( V_29 -> V_69 ) {
fprintf ( V_272 , L_170 ) ;
}
for( V_10 = 0 ; V_10 < V_65 -> V_71 ; V_10 ++ ) {
if( V_29 -> V_72 && F_44 ( V_29 -> V_72 , V_10 ) ) {
fprintf ( V_272 , L_60 , V_65 -> V_68 [ V_10 ] -> V_81 ) ;
}
}
}
fprintf ( V_272 , L_15 ) ;
}
fclose ( V_272 ) ;
return;
}
T_2 char * F_97 ( char * V_166 , char * V_81 , int V_296 )
{
const char * V_297 ;
char * V_298 ;
char * V_299 ;
char * V_300 , * V_142 ;
char V_12 ;
#ifdef F_98
V_142 = strrchr ( V_166 , '\\' ) ;
#else
V_142 = strrchr ( V_166 , '/' ) ;
#endif
if( V_142 ) {
V_12 = * V_142 ;
* V_142 = 0 ;
V_300 = ( char * ) malloc ( F_58 ( V_166 ) + F_58 ( V_81 ) + 2 ) ;
if( V_300 ) F_3 ( V_300 , L_171 , V_166 , V_81 ) ;
* V_142 = V_12 ;
} else{
V_297 = getenv ( L_172 ) ;
if( V_297 == 0 ) V_297 = L_173 ;
V_299 = ( char * ) malloc ( F_58 ( V_297 ) + 1 ) ;
V_300 = ( char * ) malloc ( F_58 ( V_297 ) + F_58 ( V_81 ) + 2 ) ;
if( ( V_299 != 0 ) && ( V_300 != 0 ) ) {
V_298 = V_299 ;
F_4 ( V_299 , V_297 ) ;
while( * V_299 ) {
V_142 = strchr ( V_299 , ':' ) ;
if( V_142 == 0 ) V_142 = & V_299 [ F_58 ( V_299 ) ] ;
V_12 = * V_142 ;
* V_142 = 0 ;
F_3 ( V_300 , L_171 , V_299 , V_81 ) ;
* V_142 = V_12 ;
if( V_12 == 0 ) V_299 [ 0 ] = 0 ;
else V_299 = & V_142 [ 1 ] ;
if( F_99 ( V_300 , V_296 ) == 0 ) break;
}
free ( V_298 ) ;
}
}
return V_300 ;
}
T_2 int F_100 ( struct V_56 * V_65 , struct V_22 * V_8 )
{
int V_301 ;
switch( V_8 -> type ) {
case V_38 : V_301 = V_8 -> V_32 . V_39 -> V_93 ; break;
case V_31 : V_301 = V_8 -> V_32 . V_33 -> V_30 + V_65 -> V_94 ; break;
case ERROR : V_301 = V_65 -> V_94 + V_65 -> V_169 ; break;
case V_110 : V_301 = V_65 -> V_94 + V_65 -> V_169 + 1 ; break;
default: V_301 = - 1 ; break;
}
return V_301 ;
}
T_2 void F_101 ( char * V_81 , T_5 * V_302 , T_5 * V_303 , int * V_140 )
{
int V_9 , V_304 ;
char line [ V_305 ] ;
while( fgets ( line , V_305 , V_302 ) && ( line [ 0 ] != '%' || line [ 1 ] != '%' ) ) {
( * V_140 ) ++ ;
V_304 = 0 ;
if( V_81 ) {
for( V_9 = 0 ; line [ V_9 ] ; V_9 ++ ) {
if( line [ V_9 ] == 'P' && strncmp ( & line [ V_9 ] , L_174 , 5 ) == 0
&& ( V_9 == 0 || ! isalpha ( line [ V_9 - 1 ] ) )
) {
if( V_9 > V_304 ) fprintf ( V_303 , L_175 , V_9 - V_304 , & line [ V_304 ] ) ;
fprintf ( V_303 , L_59 , V_81 ) ;
V_9 += 4 ;
V_304 = V_9 + 1 ;
}
}
}
fprintf ( V_303 , L_59 , & line [ V_304 ] ) ;
}
}
T_2 T_5 * F_102 ( struct V_56 * V_65 )
{
static char V_306 [] = L_176 ;
char V_295 [ 1000 ] ;
T_5 * V_302 ;
char * V_307 ;
char * V_142 ;
if ( V_147 != 0 ) {
if( F_99 ( V_147 , 004 ) == - 1 ) {
fprintf ( V_17 , L_177 ,
V_147 ) ;
V_65 -> V_82 ++ ;
return 0 ;
}
V_302 = fopen ( V_147 , L_134 ) ;
if( V_302 == 0 ) {
fprintf ( V_17 , L_178 , V_147 ) ;
V_65 -> V_82 ++ ;
return 0 ;
}
return V_302 ;
}
V_142 = strrchr ( V_65 -> V_80 , '.' ) ;
if( V_142 ) {
F_3 ( V_295 , L_179 , ( int ) ( V_142 - V_65 -> V_80 ) , V_65 -> V_80 ) ;
} else{
F_3 ( V_295 , L_180 , V_65 -> V_80 ) ;
}
if( F_99 ( V_295 , 004 ) == 0 ) {
V_307 = V_295 ;
} else if( F_99 ( V_306 , 004 ) == 0 ) {
V_307 = V_306 ;
} else{
V_307 = F_97 ( V_65 -> V_166 , V_306 , 0 ) ;
}
if( V_307 == 0 ) {
fprintf ( V_17 , L_177 ,
V_306 ) ;
V_65 -> V_82 ++ ;
return 0 ;
}
V_302 = fopen ( V_307 , L_134 ) ;
if( V_302 == 0 ) {
fprintf ( V_17 , L_178 , V_306 ) ;
V_65 -> V_82 ++ ;
return 0 ;
}
return V_302 ;
}
T_2 void F_103 ( T_5 * V_303 , int V_140 , char * V_80 )
{
fprintf ( V_303 , L_181 , V_140 ) ;
while( * V_80 ) {
if( * V_80 == '\\' ) putc ( '\\' , V_303 ) ;
putc ( * V_80 , V_303 ) ;
V_80 ++ ;
}
fprintf ( V_303 , L_182 ) ;
}
T_2 void F_104 ( T_5 * V_303 , struct V_56 * V_65 , char * V_6 , int * V_140 )
{
if( V_6 == 0 ) return;
while( * V_6 ) {
putc ( * V_6 , V_303 ) ;
if( * V_6 == '\n' ) ( * V_140 ) ++ ;
V_6 ++ ;
}
if( V_6 [ - 1 ] != '\n' ) {
putc ( '\n' , V_303 ) ;
( * V_140 ) ++ ;
}
if ( ! V_65 -> V_157 ) {
( * V_140 ) ++ ; F_103 ( V_303 , * V_140 , V_65 -> V_288 ) ;
}
return;
}
T_2 void F_105 (
T_5 * V_303 ,
struct V_36 * V_29 ,
struct V_56 * V_65 ,
int * V_140
) {
char * V_142 = 0 ;
if( V_29 -> type == V_78 ) {
V_142 = V_65 -> V_236 ;
if( V_142 == 0 ) return;
fprintf ( V_303 , L_183 ) ; ( * V_140 ) ++ ;
} else if( V_29 -> V_254 ) {
V_142 = V_29 -> V_254 ;
fprintf ( V_303 , L_183 ) ; ( * V_140 ) ++ ;
if ( ! V_65 -> V_157 ) { ( * V_140 ) ++ ; F_103 ( V_303 , V_29 -> V_255 , V_65 -> V_80 ) ; }
} else if( V_65 -> V_237 ) {
V_142 = V_65 -> V_237 ;
if( V_142 == 0 ) return;
fprintf ( V_303 , L_183 ) ; ( * V_140 ) ++ ;
} else{
assert ( 0 ) ;
}
for(; * V_142 ; V_142 ++ ) {
if( * V_142 == '$' && V_142 [ 1 ] == '$' ) {
fprintf ( V_303 , L_184 , V_29 -> V_308 ) ;
V_142 ++ ;
continue;
}
if( * V_142 == '\n' ) ( * V_140 ) ++ ;
fputc ( * V_142 , V_303 ) ;
}
fprintf ( V_303 , L_15 ) ; ( * V_140 ) ++ ;
if ( ! V_65 -> V_157 ) {
( * V_140 ) ++ ; F_103 ( V_303 , * V_140 , V_65 -> V_288 ) ;
}
fprintf ( V_303 , L_185 ) ; ( * V_140 ) ++ ;
return;
}
T_2 int F_106 ( struct V_36 * V_29 , struct V_56 * V_65 )
{
int V_309 ;
if( V_29 -> type == V_78 ) {
V_309 = V_65 -> V_236 != 0 ;
} else{
V_309 = V_65 -> V_237 != 0 || V_29 -> V_254 != 0 ;
}
return V_309 ;
}
T_2 char * F_107 ( const char * V_310 , int V_51 , int V_311 , int V_312 ) {
static char V_313 [ 1 ] = { 0 } ;
static char * V_14 = 0 ;
static int V_314 = 0 ;
static int V_315 = 0 ;
int V_12 ;
char V_316 [ 40 ] ;
if( V_310 == 0 ) {
V_315 = 0 ;
return V_14 ;
}
if( V_51 <= 0 ) {
if( V_51 < 0 ) {
V_315 += V_51 ;
assert ( V_315 >= 0 ) ;
}
V_51 = F_58 ( V_310 ) ;
}
if( ( int ) ( V_51 + sizeof( V_316 ) * 2 + V_315 ) >= V_314 ) {
V_314 = ( int ) ( V_51 + sizeof( V_316 ) * 2 + V_315 + 200 ) ;
V_14 = ( char * ) realloc ( V_14 , V_314 ) ;
}
if( V_14 == 0 ) return V_313 ;
while( V_51 -- > 0 ) {
V_12 = * ( V_310 ++ ) ;
if( V_12 == '%' && V_51 > 0 && V_310 [ 0 ] == 'd' ) {
F_3 ( V_316 , L_186 , V_311 ) ;
V_311 = V_312 ;
F_4 ( & V_14 [ V_315 ] , V_316 ) ;
V_315 += F_58 ( & V_14 [ V_315 ] ) ;
V_310 ++ ;
V_51 -- ;
} else{
V_14 [ V_315 ++ ] = ( char ) V_12 ;
}
}
V_14 [ V_315 ] = 0 ;
return V_14 ;
}
T_2 void F_108 ( struct V_56 * V_65 , struct V_41 * V_33 ) {
char * V_142 , * V_57 ;
int V_9 ;
char V_317 = 0 ;
char V_315 [ V_225 ] ;
for( V_9 = 0 ; V_9 < V_33 -> V_59 ; V_9 ++ ) V_315 [ V_9 ] = 0 ;
V_317 = 0 ;
if( V_33 -> V_215 == 0 ) {
static char V_318 [ 2 ] = { '\n' , '\0' } ;
V_33 -> V_215 = V_318 ;
V_33 -> line = V_33 -> V_114 ;
}
F_107 ( 0 , 0 , 0 , 0 ) ;
for( V_142 = ( char * ) V_33 -> V_215 ; * V_142 ; V_142 ++ ) {
if( isalpha ( * V_142 ) && ( V_142 == V_33 -> V_215 || ( ! isalnum ( V_142 [ - 1 ] ) && V_142 [ - 1 ] != '_' ) ) ) {
char V_319 ;
for( V_57 = & V_142 [ 1 ] ; isalnum ( * V_57 ) || * V_57 == '_' ; V_57 ++ ) ;
V_319 = * V_57 ;
* V_57 = 0 ;
if( V_33 -> V_212 && strcmp ( V_142 , V_33 -> V_212 ) == 0 ) {
F_107 ( L_187 , 0 , V_33 -> V_73 -> V_308 , 0 ) ;
V_142 = V_57 ;
V_317 = 1 ;
} else{
for( V_9 = 0 ; V_9 < V_33 -> V_59 ; V_9 ++ ) {
if( V_33 -> V_223 [ V_9 ] && strcmp ( V_142 , V_33 -> V_223 [ V_9 ] ) == 0 ) {
if( V_142 != V_33 -> V_215 && V_142 [ - 1 ] == '@' ) {
F_107 ( L_188 , - 1 , V_9 - V_33 -> V_59 + 1 , 0 ) ;
} else{
struct V_36 * V_29 = V_33 -> V_60 [ V_9 ] ;
int V_308 ;
if( V_29 -> type == V_61 ) {
V_308 = V_29 -> V_63 [ 0 ] -> V_308 ;
} else{
V_308 = V_29 -> V_308 ;
}
F_107 ( L_189 , 0 , V_9 - V_33 -> V_59 + 1 , V_308 ) ;
}
V_142 = V_57 ;
V_315 [ V_9 ] = 1 ;
break;
}
}
}
* V_57 = V_319 ;
}
F_107 ( V_142 , 1 , 0 , 0 ) ;
}
if( V_33 -> V_212 && ! V_317 ) {
F_22 ( V_65 -> V_80 , V_33 -> V_114 ,
L_190 ,
V_33 -> V_212 , V_33 -> V_73 -> V_81 , V_33 -> V_212 ) ;
V_65 -> V_82 ++ ;
}
for( V_9 = 0 ; V_9 < V_33 -> V_59 ; V_9 ++ ) {
if( V_33 -> V_223 [ V_9 ] && ! V_315 [ V_9 ] ) {
F_22 ( V_65 -> V_80 , V_33 -> V_114 ,
L_191 ,
V_33 -> V_223 [ V_9 ] , V_33 -> V_60 [ V_9 ] -> V_81 , V_33 -> V_223 [ V_9 ] ) ;
V_65 -> V_82 ++ ;
} else if( V_33 -> V_223 [ V_9 ] == 0 ) {
if( F_106 ( V_33 -> V_60 [ V_9 ] , V_65 ) ) {
F_107 ( L_192 , 0 ,
V_33 -> V_60 [ V_9 ] -> V_30 , V_9 - V_33 -> V_59 + 1 ) ;
} else{
}
}
}
if( V_33 -> V_215 ) {
V_142 = F_107 ( 0 , 0 , 0 , 0 ) ;
V_33 -> V_215 = F_89 ( V_142 ? V_142 : L_62 ) ;
}
}
T_2 void F_109 (
T_5 * V_303 ,
struct V_41 * V_33 ,
struct V_56 * V_65 ,
int * V_140
) {
const char * V_142 ;
if( V_33 -> V_215 ) {
if ( ! V_65 -> V_157 ) { ( * V_140 ) ++ ; F_103 ( V_303 , V_33 -> line , V_65 -> V_80 ) ; }
fprintf ( V_303 , L_193 , V_33 -> V_215 ) ;
for( V_142 = V_33 -> V_215 ; * V_142 ; V_142 ++ ) {
if( * V_142 == '\n' ) ( * V_140 ) ++ ;
}
fprintf ( V_303 , L_185 ) ; ( * V_140 ) ++ ;
if ( ! V_65 -> V_157 ) { ( * V_140 ) ++ ; F_103 ( V_303 , * V_140 , V_65 -> V_288 ) ; }
}
return;
}
T_2 void F_110 (
T_5 * V_303 ,
struct V_56 * V_65 ,
int * V_320 ,
int V_156
) {
int V_140 = * V_320 ;
char * * V_321 ;
int V_322 ;
int V_323 ;
char * V_324 ;
int V_9 , V_10 ;
unsigned V_325 ;
const char * V_81 ;
V_322 = V_65 -> V_67 * 2 ;
V_321 = ( char * * ) calloc ( V_322 , sizeof( char * ) ) ;
if( V_321 == 0 ) {
fprintf ( V_17 , L_194 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_322 ; V_9 ++ ) V_321 [ V_9 ] = 0 ;
V_323 = 0 ;
if( V_65 -> V_243 ) {
V_323 = F_58 ( V_65 -> V_243 ) ;
}
for( V_9 = 0 ; V_9 < V_65 -> V_67 ; V_9 ++ ) {
int V_199 ;
struct V_36 * V_29 = V_65 -> V_68 [ V_9 ] ;
if( V_29 -> V_256 == 0 ) continue;
V_199 = F_58 ( V_29 -> V_256 ) ;
if( V_199 > V_323 ) V_323 = V_199 ;
}
V_324 = ( char * ) malloc ( V_323 * 2 + 1 ) ;
if( V_324 == 0 ) {
fprintf ( V_17 , L_194 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_65 -> V_67 ; V_9 ++ ) {
struct V_36 * V_29 = V_65 -> V_68 [ V_9 ] ;
char * V_142 ;
if( V_29 == V_65 -> V_137 ) {
V_29 -> V_308 = V_322 + 1 ;
continue;
}
if( V_29 -> type != V_74 || ( V_29 -> V_256 == 0 && V_65 -> V_243 == 0 ) ) {
V_29 -> V_308 = 0 ;
continue;
}
V_142 = V_29 -> V_256 ;
if( V_142 == 0 ) V_142 = V_65 -> V_243 ;
V_10 = 0 ;
while( isspace ( * V_142 ) ) V_142 ++ ;
while( * V_142 ) V_324 [ V_10 ++ ] = * V_142 ++ ;
while( V_10 > 0 && isspace ( V_324 [ V_10 - 1 ] ) ) V_10 -- ;
V_324 [ V_10 ] = 0 ;
if( V_65 -> V_242 && strcmp ( V_324 , V_65 -> V_242 ) == 0 ) {
V_29 -> V_308 = 0 ;
continue;
}
V_325 = 0 ;
for( V_10 = 0 ; V_324 [ V_10 ] ; V_10 ++ ) {
V_325 = V_325 * 53 + V_324 [ V_10 ] ;
}
V_325 = ( V_325 & 0x7fffffff ) % V_322 ;
while( V_321 [ V_325 ] ) {
if( strcmp ( V_321 [ V_325 ] , V_324 ) == 0 ) {
V_29 -> V_308 = V_325 + 1 ;
break;
}
V_325 ++ ;
if( V_325 >= ( unsigned ) V_322 ) V_325 = 0 ;
}
if( V_321 [ V_325 ] == 0 ) {
V_29 -> V_308 = V_325 + 1 ;
V_321 [ V_325 ] = ( char * ) malloc ( F_58 ( V_324 ) + 1 ) ;
if( V_321 [ V_325 ] == 0 ) {
fprintf ( V_17 , L_194 ) ;
exit ( 1 ) ;
}
F_4 ( V_321 [ V_325 ] , V_324 ) ;
}
}
V_81 = V_65 -> V_81 ? V_65 -> V_81 : L_174 ;
if( V_156 ) { fprintf ( V_303 , L_195 ) ; V_140 ++ ; }
fprintf ( V_303 , L_196 , V_81 ,
V_65 -> V_242 ? V_65 -> V_242 : L_197 ) ; V_140 ++ ;
if( V_156 ) { fprintf ( V_303 , L_198 ) ; V_140 ++ ; }
fprintf ( V_303 , L_199 ) ; V_140 ++ ;
fprintf ( V_303 , L_200 ) ; V_140 ++ ;
fprintf ( V_303 , L_201 , V_81 ) ; V_140 ++ ;
for( V_9 = 0 ; V_9 < V_322 ; V_9 ++ ) {
if( V_321 [ V_9 ] == 0 ) continue;
fprintf ( V_303 , L_202 , V_321 [ V_9 ] , V_9 + 1 ) ; V_140 ++ ;
free ( V_321 [ V_9 ] ) ;
}
if( V_65 -> V_137 -> V_167 ) {
fprintf ( V_303 , L_203 , V_65 -> V_137 -> V_308 ) ; V_140 ++ ;
}
free ( V_324 ) ;
free ( V_321 ) ;
fprintf ( V_303 , L_204 ) ; V_140 ++ ;
* V_320 = V_140 ;
}
static const char * F_111 ( int V_326 , int V_327 ) {
if( V_326 >= 0 ) {
if( V_327 <= 255 ) {
return L_205 ;
} else if( V_327 < 65535 ) {
return L_206 ;
} else{
return L_207 ;
}
} else if( V_326 >= - 127 && V_327 <= 127 ) {
return L_208 ;
} else if( V_326 >= - 32767 && V_327 < 32767 ) {
return L_209 ;
} else{
return L_210 ;
}
}
static int F_112 ( const void * V_95 , const void * V_96 ) {
struct V_328 * V_311 = (struct V_328 * ) V_95 ;
struct V_328 * V_312 = (struct V_328 * ) V_96 ;
int V_12 ;
V_12 = V_312 -> V_52 - V_311 -> V_52 ;
if( V_12 == 0 ) {
V_12 = V_312 -> V_329 - V_311 -> V_329 ;
}
assert ( V_12 != 0 || V_311 == V_312 ) ;
return V_12 ;
}
static void F_113 ( T_5 * V_303 , struct V_41 * V_33 ) {
int V_10 ;
fprintf ( V_303 , L_150 , V_33 -> V_73 -> V_81 ) ;
for( V_10 = 0 ; V_10 < V_33 -> V_59 ; V_10 ++ ) {
struct V_36 * V_29 = V_33 -> V_60 [ V_10 ] ;
if( V_29 -> type != V_61 ) {
fprintf ( V_303 , L_60 , V_29 -> V_81 ) ;
} else{
int V_11 ;
fprintf ( V_303 , L_60 , V_29 -> V_63 [ 0 ] -> V_81 ) ;
for( V_11 = 1 ; V_11 < V_29 -> V_62 ; V_11 ++ ) {
fprintf ( V_303 , L_147 , V_29 -> V_63 [ V_11 ] -> V_81 ) ;
}
}
}
}
void F_76 (
struct V_56 * V_65 ,
int V_156
) {
T_5 * V_303 , * V_302 ;
char line [ V_305 ] ;
int V_140 ;
struct V_40 * V_39 ;
struct V_22 * V_8 ;
struct V_41 * V_33 ;
struct T_3 * V_330 ;
int V_9 , V_10 , V_51 ;
const char * V_81 ;
int V_331 , V_332 ;
int V_333 , V_334 ;
struct V_328 * V_335 ;
V_302 = F_102 ( V_65 ) ;
if( V_302 == 0 ) return;
V_303 = F_94 ( V_65 , L_211 , L_161 ) ;
if( V_303 == 0 ) {
fclose ( V_302 ) ;
return;
}
V_140 = 1 ;
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
F_104 ( V_303 , V_65 , V_65 -> include , & V_140 ) ;
if( V_156 ) {
char * V_336 = F_92 ( V_65 , L_212 ) ;
fprintf ( V_303 , L_213 , V_336 ) ; V_140 ++ ;
free ( V_336 ) ;
}
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
if( V_156 ) {
const char * V_337 ;
fprintf ( V_303 , L_195 ) ; V_140 ++ ;
if( V_65 -> V_238 ) V_337 = V_65 -> V_238 ;
else V_337 = L_62 ;
for( V_9 = 1 ; V_9 < V_65 -> V_71 ; V_9 ++ ) {
fprintf ( V_303 , L_214 , V_337 , V_65 -> V_68 [ V_9 ] -> V_81 , V_9 ) ;
V_140 ++ ;
}
fprintf ( V_303 , L_198 ) ; V_140 ++ ;
}
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
fprintf ( V_303 , L_215 ,
F_111 ( 0 , V_65 -> V_67 + 1 ) ) ; V_140 ++ ;
fprintf ( V_303 , L_216 , V_65 -> V_67 + 1 ) ; V_140 ++ ;
fprintf ( V_303 , L_217 ,
F_111 ( 0 , V_65 -> V_94 + V_65 -> V_169 + 5 ) ) ; V_140 ++ ;
if( V_65 -> V_266 ) {
fprintf ( V_303 , L_218 ,
V_65 -> V_266 -> V_30 ) ; V_140 ++ ;
}
F_110 ( V_303 , V_65 , & V_140 , V_156 ) ;
fprintf ( V_303 , L_219 ) ; V_140 ++ ;
if( V_65 -> V_244 ) {
fprintf ( V_303 , L_220 , V_65 -> V_244 ) ; V_140 ++ ;
} else{
fprintf ( V_303 , L_221 ) ; V_140 ++ ;
}
fprintf ( V_303 , L_198 ) ; V_140 ++ ;
if( V_156 ) {
fprintf ( V_303 , L_195 ) ; V_140 ++ ;
}
V_81 = V_65 -> V_81 ? V_65 -> V_81 : L_174 ;
if( V_65 -> V_37 && V_65 -> V_37 [ 0 ] ) {
V_9 = F_58 ( V_65 -> V_37 ) ;
while( V_9 >= 1 && isspace ( V_65 -> V_37 [ V_9 - 1 ] ) ) V_9 -- ;
while( V_9 >= 1 && ( isalnum ( V_65 -> V_37 [ V_9 - 1 ] ) || V_65 -> V_37 [ V_9 - 1 ] == '_' ) ) V_9 -- ;
fprintf ( V_303 , L_222 , V_81 , V_65 -> V_37 ) ; V_140 ++ ;
fprintf ( V_303 , L_223 , V_81 , V_65 -> V_37 ) ; V_140 ++ ;
fprintf ( V_303 , L_224 ,
V_81 , V_65 -> V_37 , & V_65 -> V_37 [ V_9 ] ) ; V_140 ++ ;
fprintf ( V_303 , L_225 ,
V_81 , & V_65 -> V_37 [ V_9 ] , & V_65 -> V_37 [ V_9 ] ) ; V_140 ++ ;
} else{
fprintf ( V_303 , L_226 , V_81 ) ; V_140 ++ ;
fprintf ( V_303 , L_227 , V_81 ) ; V_140 ++ ;
fprintf ( V_303 , L_228 , V_81 ) ; V_140 ++ ;
fprintf ( V_303 , L_229 , V_81 ) ; V_140 ++ ;
}
if( V_156 ) {
fprintf ( V_303 , L_198 ) ; V_140 ++ ;
}
fprintf ( V_303 , L_230 , V_65 -> V_94 ) ; V_140 ++ ;
fprintf ( V_303 , L_231 , V_65 -> V_169 ) ; V_140 ++ ;
if( V_65 -> V_137 -> V_167 ) {
fprintf ( V_303 , L_232 , V_65 -> V_137 -> V_30 ) ; V_140 ++ ;
fprintf ( V_303 , L_233 , V_65 -> V_137 -> V_308 ) ; V_140 ++ ;
}
if( V_65 -> V_265 ) {
fprintf ( V_303 , L_234 ) ; V_140 ++ ;
}
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
V_335 = (struct V_328 * ) calloc ( V_65 -> V_94 * 2 , sizeof( V_335 [ 0 ] ) ) ;
if( V_335 == 0 ) {
fprintf ( V_17 , L_8 ) ;
exit ( 1 ) ;
}
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
V_39 = V_65 -> V_108 [ V_9 ] ;
V_335 [ V_9 * 2 ] . V_39 = V_39 ;
V_335 [ V_9 * 2 ] . V_338 = 1 ;
V_335 [ V_9 * 2 ] . V_52 = V_39 -> V_339 ;
V_335 [ V_9 * 2 + 1 ] . V_39 = V_39 ;
V_335 [ V_9 * 2 + 1 ] . V_338 = 0 ;
V_335 [ V_9 * 2 + 1 ] . V_52 = V_39 -> V_340 ;
}
V_332 = V_331 = 0 ;
V_334 = V_333 = 0 ;
for( V_9 = 0 ; V_9 < V_65 -> V_94 * 2 ; V_9 ++ ) V_335 [ V_9 ] . V_329 = V_9 ;
qsort ( V_335 , V_65 -> V_94 * 2 , sizeof( V_335 [ 0 ] ) , F_112 ) ;
V_330 = F_11 () ;
for( V_9 = 0 ; V_9 < V_65 -> V_94 * 2 && V_335 [ V_9 ] . V_52 > 0 ; V_9 ++ ) {
V_39 = V_335 [ V_9 ] . V_39 ;
if( V_335 [ V_9 ] . V_338 ) {
for( V_8 = V_39 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
int V_22 ;
if( V_8 -> V_29 -> V_30 >= V_65 -> V_71 ) continue;
V_22 = F_100 ( V_65 , V_8 ) ;
if( V_22 < 0 ) continue;
F_12 ( V_330 , V_8 -> V_29 -> V_30 , V_22 ) ;
}
V_39 -> V_341 = F_13 ( V_330 ) ;
if( V_39 -> V_341 < V_331 ) V_331 = V_39 -> V_341 ;
if( V_39 -> V_341 > V_332 ) V_332 = V_39 -> V_341 ;
} else{
for( V_8 = V_39 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
int V_22 ;
if( V_8 -> V_29 -> V_30 < V_65 -> V_71 ) continue;
if( V_8 -> V_29 -> V_30 == V_65 -> V_67 ) continue;
V_22 = F_100 ( V_65 , V_8 ) ;
if( V_22 < 0 ) continue;
F_12 ( V_330 , V_8 -> V_29 -> V_30 , V_22 ) ;
}
V_39 -> V_342 = F_13 ( V_330 ) ;
if( V_39 -> V_342 < V_333 ) V_333 = V_39 -> V_342 ;
if( V_39 -> V_342 > V_334 ) V_334 = V_39 -> V_342 ;
}
}
free ( V_335 ) ;
V_51 = F_114 ( V_330 ) ;
fprintf ( V_303 , L_235 , V_51 ) ; V_140 ++ ;
fprintf ( V_303 , L_236 ) ; V_140 ++ ;
for( V_9 = V_10 = 0 ; V_9 < V_51 ; V_9 ++ ) {
int V_22 = F_115 ( V_330 , V_9 ) ;
if( V_22 < 0 ) V_22 = V_65 -> V_94 + V_65 -> V_169 + 2 ;
if( V_10 == 0 ) fprintf ( V_303 , L_237 , V_9 ) ;
fprintf ( V_303 , L_238 , V_22 ) ;
if( V_10 == 9 || V_9 == V_51 - 1 ) {
fprintf ( V_303 , L_15 ) ; V_140 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_303 , L_239 ) ; V_140 ++ ;
fprintf ( V_303 , L_240 ) ; V_140 ++ ;
for( V_9 = V_10 = 0 ; V_9 < V_51 ; V_9 ++ ) {
int V_343 = F_116 ( V_330 , V_9 ) ;
if( V_343 < 0 ) V_343 = V_65 -> V_67 ;
if( V_10 == 0 ) fprintf ( V_303 , L_237 , V_9 ) ;
fprintf ( V_303 , L_238 , V_343 ) ;
if( V_10 == 9 || V_9 == V_51 - 1 ) {
fprintf ( V_303 , L_15 ) ; V_140 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_303 , L_239 ) ; V_140 ++ ;
fprintf ( V_303 , L_241 , V_331 - 1 ) ; V_140 ++ ;
V_51 = V_65 -> V_94 ;
while( V_51 > 0 && V_65 -> V_108 [ V_51 - 1 ] -> V_341 == V_344 ) V_51 -- ;
fprintf ( V_303 , L_242 , V_51 - 1 ) ; V_140 ++ ;
fprintf ( V_303 , L_243 , V_331 ) ; V_140 ++ ;
fprintf ( V_303 , L_244 , V_332 ) ; V_140 ++ ;
fprintf ( V_303 , L_245 ,
F_111 ( V_331 - 1 , V_332 ) ) ; V_140 ++ ;
for( V_9 = V_10 = 0 ; V_9 < V_51 ; V_9 ++ ) {
int V_345 ;
V_39 = V_65 -> V_108 [ V_9 ] ;
V_345 = V_39 -> V_341 ;
if( V_345 == V_344 ) V_345 = V_331 - 1 ;
if( V_10 == 0 ) fprintf ( V_303 , L_237 , V_9 ) ;
fprintf ( V_303 , L_238 , V_345 ) ;
if( V_10 == 9 || V_9 == V_51 - 1 ) {
fprintf ( V_303 , L_15 ) ; V_140 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_303 , L_239 ) ; V_140 ++ ;
fprintf ( V_303 , L_246 , V_333 - 1 ) ; V_140 ++ ;
V_51 = V_65 -> V_94 ;
while( V_51 > 0 && V_65 -> V_108 [ V_51 - 1 ] -> V_342 == V_344 ) V_51 -- ;
fprintf ( V_303 , L_247 , V_51 - 1 ) ; V_140 ++ ;
fprintf ( V_303 , L_248 , V_333 ) ; V_140 ++ ;
fprintf ( V_303 , L_249 , V_334 ) ; V_140 ++ ;
fprintf ( V_303 , L_250 ,
F_111 ( V_333 - 1 , V_334 ) ) ; V_140 ++ ;
for( V_9 = V_10 = 0 ; V_9 < V_51 ; V_9 ++ ) {
int V_345 ;
V_39 = V_65 -> V_108 [ V_9 ] ;
V_345 = V_39 -> V_342 ;
if( V_345 == V_344 ) V_345 = V_333 - 1 ;
if( V_10 == 0 ) fprintf ( V_303 , L_237 , V_9 ) ;
fprintf ( V_303 , L_238 , V_345 ) ;
if( V_10 == 9 || V_9 == V_51 - 1 ) {
fprintf ( V_303 , L_15 ) ; V_140 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_303 , L_239 ) ; V_140 ++ ;
fprintf ( V_303 , L_251 ) ; V_140 ++ ;
V_51 = V_65 -> V_94 ;
for( V_9 = V_10 = 0 ; V_9 < V_51 ; V_9 ++ ) {
V_39 = V_65 -> V_108 [ V_9 ] ;
if( V_10 == 0 ) fprintf ( V_303 , L_237 , V_9 ) ;
fprintf ( V_303 , L_238 , V_39 -> V_346 ) ;
if( V_10 == 9 || V_9 == V_51 - 1 ) {
fprintf ( V_303 , L_15 ) ; V_140 ++ ;
V_10 = 0 ;
} else{
V_10 ++ ;
}
}
fprintf ( V_303 , L_239 ) ; V_140 ++ ;
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
if( V_65 -> V_265 ) {
int V_347 = V_65 -> V_71 - 1 ;
while( V_347 > 0 && V_65 -> V_68 [ V_347 ] -> V_249 == 0 ) { V_347 -- ; }
for( V_9 = 0 ; V_9 <= V_347 ; V_9 ++ ) {
struct V_36 * V_42 = V_65 -> V_68 [ V_9 ] ;
if( V_42 -> V_249 == 0 ) {
fprintf ( V_303 , L_252 , V_42 -> V_81 ) ;
} else{
fprintf ( V_303 , L_253 , V_42 -> V_249 -> V_30 ,
V_42 -> V_81 , V_42 -> V_249 -> V_81 ) ;
}
V_140 ++ ;
}
}
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
for( V_9 = 0 ; V_9 < V_65 -> V_67 ; V_9 ++ ) {
F_3 ( line , L_254 , V_65 -> V_68 [ V_9 ] -> V_81 ) ;
fprintf ( V_303 , L_255 , line ) ;
if( ( V_9 & 3 ) == 3 ) { fprintf ( V_303 , L_15 ) ; V_140 ++ ; }
}
if( ( V_9 & 3 ) != 0 ) { fprintf ( V_303 , L_15 ) ; V_140 ++ ; }
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
for( V_9 = 0 , V_33 = V_65 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 , V_9 ++ ) {
assert ( V_33 -> V_30 == V_9 ) ;
fprintf ( V_303 , L_256 , V_9 ) ;
F_113 ( V_303 , V_33 ) ;
fprintf ( V_303 , L_257 ) ; V_140 ++ ;
}
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
if( V_65 -> V_236 ) {
int V_348 = 1 ;
for( V_9 = 0 ; V_9 < V_65 -> V_67 ; V_9 ++ ) {
struct V_36 * V_29 = V_65 -> V_68 [ V_9 ] ;
if( V_29 == 0 || V_29 -> type != V_78 ) continue;
if( V_348 ) {
fprintf ( V_303 , L_258 ) ; V_140 ++ ;
V_348 = 0 ;
}
fprintf ( V_303 , L_259 , V_29 -> V_30 , V_29 -> V_81 ) ; V_140 ++ ;
}
for( V_9 = 0 ; V_9 < V_65 -> V_67 && V_65 -> V_68 [ V_9 ] -> type != V_78 ; V_9 ++ ) ;
if( V_9 < V_65 -> V_67 ) {
F_105 ( V_303 , V_65 -> V_68 [ V_9 ] , V_65 , & V_140 ) ;
fprintf ( V_303 , L_260 ) ; V_140 ++ ;
}
}
if( V_65 -> V_237 ) {
struct V_36 * V_349 = 0 ;
int V_348 = 1 ;
for( V_9 = 0 ; V_9 < V_65 -> V_67 ; V_9 ++ ) {
struct V_36 * V_29 = V_65 -> V_68 [ V_9 ] ;
if( V_29 == 0 || V_29 -> type == V_78 ||
V_29 -> V_30 <= 0 || V_29 -> V_254 != 0 ) continue;
if( V_348 ) {
fprintf ( V_303 , L_261 ) ; V_140 ++ ;
V_348 = 0 ;
}
fprintf ( V_303 , L_259 , V_29 -> V_30 , V_29 -> V_81 ) ; V_140 ++ ;
V_349 = V_29 ;
}
if( V_349 != 0 ) {
F_105 ( V_303 , V_349 , V_65 , & V_140 ) ;
}
fprintf ( V_303 , L_260 ) ; V_140 ++ ;
}
for( V_9 = 0 ; V_9 < V_65 -> V_67 ; V_9 ++ ) {
struct V_36 * V_29 = V_65 -> V_68 [ V_9 ] ;
if( V_29 == 0 || V_29 -> type == V_78 || V_29 -> V_254 == 0 ) continue;
fprintf ( V_303 , L_259 , V_29 -> V_30 , V_29 -> V_81 ) ; V_140 ++ ;
for( V_10 = V_9 + 1 ; V_10 < V_65 -> V_67 ; V_10 ++ ) {
struct V_36 * V_350 = V_65 -> V_68 [ V_10 ] ;
if( V_350 && V_350 -> type != V_78 && V_350 -> V_254
&& V_350 -> V_308 == V_29 -> V_308
&& strcmp ( V_29 -> V_254 , V_350 -> V_254 ) == 0 ) {
fprintf ( V_303 , L_259 ,
V_350 -> V_30 , V_350 -> V_81 ) ; V_140 ++ ;
V_350 -> V_254 = 0 ;
}
}
F_105 ( V_303 , V_65 -> V_68 [ V_9 ] , V_65 , & V_140 ) ;
fprintf ( V_303 , L_260 ) ; V_140 ++ ;
}
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
F_104 ( V_303 , V_65 , V_65 -> V_241 , & V_140 ) ;
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
for( V_33 = V_65 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 ) {
fprintf ( V_303 , L_262 , V_33 -> V_73 -> V_30 , V_33 -> V_59 ) ; V_140 ++ ;
}
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
for( V_33 = V_65 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 ) {
F_108 ( V_65 , V_33 ) ;
}
for( V_33 = V_65 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 ) {
struct V_41 * V_351 ;
if( V_33 -> V_215 == 0 ) continue;
if( V_33 -> V_215 [ 0 ] == '\n' && V_33 -> V_215 [ 1 ] == 0 ) continue;
fprintf ( V_303 , L_263 , V_33 -> V_30 ) ;
F_113 ( V_303 , V_33 ) ;
fprintf ( V_303 , L_264 ) ; V_140 ++ ;
for( V_351 = V_33 -> V_26 ; V_351 ; V_351 = V_351 -> V_26 ) {
if( V_351 -> V_215 == V_33 -> V_215 ) {
fprintf ( V_303 , L_263 , V_351 -> V_30 ) ;
F_113 ( V_303 , V_351 ) ;
fprintf ( V_303 , L_265 , V_351 -> V_30 ) ; V_140 ++ ;
V_351 -> V_215 = 0 ;
}
}
F_109 ( V_303 , V_33 , V_65 , & V_140 ) ;
fprintf ( V_303 , L_266 ) ; V_140 ++ ;
V_33 -> V_215 = 0 ;
}
fprintf ( V_303 , L_267 ) ; V_140 ++ ;
for( V_33 = V_65 -> V_41 ; V_33 ; V_33 = V_33 -> V_26 ) {
if( V_33 -> V_215 == 0 ) continue;
assert ( V_33 -> V_215 [ 0 ] == '\n' && V_33 -> V_215 [ 1 ] == 0 ) ;
fprintf ( V_303 , L_268 , V_33 -> V_30 ) ;
F_113 ( V_303 , V_33 ) ;
fprintf ( V_303 , L_265 , V_33 -> V_30 ) ; V_140 ++ ;
}
fprintf ( V_303 , L_266 ) ; V_140 ++ ;
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
F_104 ( V_303 , V_65 , V_65 -> V_240 , & V_140 ) ;
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
F_104 ( V_303 , V_65 , V_65 -> error , & V_140 ) ;
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
F_104 ( V_303 , V_65 , V_65 -> V_239 , & V_140 ) ;
F_101 ( V_65 -> V_81 , V_302 , V_303 , & V_140 ) ;
F_104 ( V_303 , V_65 , V_65 -> V_235 , & V_140 ) ;
fclose ( V_302 ) ;
fclose ( V_303 ) ;
return;
}
void F_77 ( struct V_56 * V_65 )
{
T_5 * V_303 , * V_302 ;
const char * V_337 ;
char line [ V_305 ] ;
char V_352 [ V_305 ] ;
int V_9 ;
if( V_65 -> V_238 ) V_337 = V_65 -> V_238 ;
else V_337 = L_62 ;
V_302 = F_94 ( V_65 , L_212 , L_134 ) ;
if( V_302 ) {
int V_353 ;
for( V_9 = 1 ; V_9 < V_65 -> V_71 && fgets ( line , V_305 , V_302 ) ; V_9 ++ ) {
F_3 ( V_352 , L_269 ,
V_337 , V_65 -> V_68 [ V_9 ] -> V_81 , V_9 ) ;
if( strcmp ( line , V_352 ) ) break;
}
V_353 = fgetc ( V_302 ) ;
fclose ( V_302 ) ;
if( V_9 == V_65 -> V_71 && V_353 == V_354 ) {
return;
}
}
V_303 = F_94 ( V_65 , L_212 , L_161 ) ;
if( V_303 ) {
for( V_9 = 1 ; V_9 < V_65 -> V_71 ; V_9 ++ ) {
fprintf ( V_303 , L_269 , V_337 , V_65 -> V_68 [ V_9 ] -> V_81 , V_9 ) ;
}
fclose ( V_303 ) ;
}
return;
}
void F_73 ( struct V_56 * V_65 )
{
struct V_40 * V_39 ;
struct V_22 * V_8 , * V_28 ;
struct V_41 * V_33 , * V_351 , * V_355 ;
int V_356 , V_51 ;
int V_9 ;
int V_357 ;
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
V_39 = V_65 -> V_108 [ V_9 ] ;
V_356 = 0 ;
V_355 = 0 ;
V_357 = 0 ;
for( V_8 = V_39 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_38 && V_8 -> V_29 == V_65 -> V_266 ) {
V_357 = 1 ;
}
if( V_8 -> type != V_31 ) continue;
V_33 = V_8 -> V_32 . V_33 ;
if( V_33 -> V_86 ) continue;
if( V_33 == V_355 ) continue;
V_51 = 1 ;
for( V_28 = V_8 -> V_26 ; V_28 ; V_28 = V_28 -> V_26 ) {
if( V_28 -> type != V_31 ) continue;
V_351 = V_28 -> V_32 . V_33 ;
if( V_351 == V_355 ) continue;
if( V_351 == V_33 ) V_51 ++ ;
}
if( V_51 > V_356 ) {
V_356 = V_51 ;
V_355 = V_33 ;
}
}
if( V_356 < 1 || V_357 ) continue;
for( V_8 = V_39 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_31 && V_8 -> V_32 . V_33 == V_355 ) break;
}
assert ( V_8 ) ;
V_8 -> V_29 = F_66 ( L_55 ) ;
for( V_8 = V_8 -> V_26 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( V_8 -> type == V_31 && V_8 -> V_32 . V_33 == V_355 ) V_8 -> type = V_294 ;
}
V_39 -> V_8 = F_8 ( V_39 -> V_8 ) ;
}
}
static int F_117 ( const void * V_95 , const void * V_96 ) {
const struct V_40 * V_358 = * ( const struct V_40 * * ) V_95 ;
const struct V_40 * V_359 = * ( const struct V_40 * * ) V_96 ;
int V_51 ;
V_51 = V_359 -> V_340 - V_358 -> V_340 ;
if( V_51 == 0 ) {
V_51 = V_359 -> V_339 - V_358 -> V_339 ;
if( V_51 == 0 ) {
V_51 = V_359 -> V_93 - V_358 -> V_93 ;
}
}
assert ( V_51 != 0 ) ;
return V_51 ;
}
void F_74 ( struct V_56 * V_65 )
{
int V_9 ;
struct V_40 * V_39 ;
struct V_22 * V_8 ;
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
V_39 = V_65 -> V_108 [ V_9 ] ;
V_39 -> V_339 = V_39 -> V_340 = 0 ;
V_39 -> V_346 = V_65 -> V_94 + V_65 -> V_169 ;
V_39 -> V_341 = V_344 ;
V_39 -> V_342 = V_344 ;
for( V_8 = V_39 -> V_8 ; V_8 ; V_8 = V_8 -> V_26 ) {
if( F_100 ( V_65 , V_8 ) >= 0 ) {
if( V_8 -> V_29 -> V_30 < V_65 -> V_71 ) {
V_39 -> V_339 ++ ;
} else if( V_8 -> V_29 -> V_30 < V_65 -> V_67 ) {
V_39 -> V_340 ++ ;
} else{
V_39 -> V_346 = F_100 ( V_65 , V_8 ) ;
}
}
}
}
qsort ( & V_65 -> V_108 [ 1 ] , V_65 -> V_94 - 1 , sizeof( V_65 -> V_108 [ 0 ] ) ,
F_117 ) ;
for( V_9 = 0 ; V_9 < V_65 -> V_94 ; V_9 ++ ) {
V_65 -> V_108 [ V_9 ] -> V_93 = V_9 ;
}
}
void F_71 ( int V_51 )
{
V_360 = V_51 + 1 ;
}
char * F_16 ( void ) {
char * V_361 ;
V_361 = ( char * ) calloc ( V_360 , 1 ) ;
if( V_361 == 0 ) {
F_54 () ;
}
return V_361 ;
}
void F_53 ( char * V_361 )
{
free ( V_361 ) ;
}
int F_17 ( char * V_361 , int V_362 )
{
int V_363 ;
assert ( V_362 >= 0 && V_362 < V_360 ) ;
V_363 = V_361 [ V_362 ] ;
V_361 [ V_362 ] = 1 ;
return ! V_363 ;
}
int F_18 ( char * V_76 , char * V_77 )
{
int V_9 , V_66 ;
V_66 = 0 ;
for( V_9 = 0 ; V_9 < V_360 ; V_9 ++ ) {
if( V_77 [ V_9 ] == 0 ) continue;
if( V_76 [ V_9 ] == 0 ) {
V_66 = 1 ;
V_76 [ V_9 ] = 1 ;
}
}
return V_66 ;
}
T_2 unsigned F_118 ( const char * V_32 )
{
unsigned V_364 = 0 ;
while( * V_32 ) V_364 = V_364 * 13 + * ( V_32 ++ ) ;
return V_364 ;
}
const char * F_89 ( const char * V_90 )
{
const char * V_14 ;
char * V_365 ;
if( V_90 == 0 ) return 0 ;
V_14 = F_119 ( V_90 ) ;
if( V_14 == 0 && ( V_365 = ( char * ) malloc ( F_58 ( V_90 ) + 1 ) ) != 0 ) {
F_4 ( V_365 , V_90 ) ;
V_14 = V_365 ;
F_120 ( V_14 ) ;
}
F_35 ( V_14 ) ;
return V_14 ;
}
void F_62 ( void ) {
if( V_366 ) return;
V_366 = (struct V_367 * ) malloc ( sizeof( struct V_367 ) ) ;
if( V_366 ) {
V_366 -> V_360 = 1024 ;
V_366 -> V_368 = 0 ;
V_366 -> V_369 = ( V_370 * ) calloc ( 1024 , sizeof( V_370 ) + sizeof( V_370 * ) ) ;
if( V_366 -> V_369 == 0 ) {
free ( V_366 ) ;
V_366 = 0 ;
} else{
int V_9 ;
V_366 -> V_371 = ( V_370 * * ) & ( V_366 -> V_369 [ 1024 ] ) ;
for( V_9 = 0 ; V_9 < 1024 ; V_9 ++ ) V_366 -> V_371 [ V_9 ] = 0 ;
}
}
}
int F_120 ( const char * V_372 )
{
V_370 * V_373 ;
unsigned V_364 ;
unsigned V_374 ;
if( V_366 == 0 ) return 0 ;
V_374 = F_118 ( V_372 ) ;
V_364 = V_374 & ( V_366 -> V_360 - 1 ) ;
V_373 = V_366 -> V_371 [ V_364 ] ;
while( V_373 ) {
if( strcmp ( V_373 -> V_372 , V_372 ) == 0 ) {
return 0 ;
}
V_373 = V_373 -> V_26 ;
}
if( V_366 -> V_368 >= V_366 -> V_360 ) {
int V_9 , V_375 ;
struct V_367 V_376 ;
V_376 . V_360 = V_375 = V_366 -> V_360 * 2 ;
V_376 . V_368 = V_366 -> V_368 ;
V_376 . V_369 = ( V_370 * ) calloc ( V_375 , sizeof( V_370 ) + sizeof( V_370 * ) ) ;
if( V_376 . V_369 == 0 ) return 0 ;
V_376 . V_371 = ( V_370 * * ) & ( V_376 . V_369 [ V_375 ] ) ;
for( V_9 = 0 ; V_9 < V_375 ; V_9 ++ ) V_376 . V_371 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_366 -> V_368 ; V_9 ++ ) {
V_370 * V_377 , * V_378 ;
V_377 = & ( V_366 -> V_369 [ V_9 ] ) ;
V_364 = F_118 ( V_377 -> V_372 ) & ( V_375 - 1 ) ;
V_378 = & ( V_376 . V_369 [ V_9 ] ) ;
if( V_376 . V_371 [ V_364 ] ) V_376 . V_371 [ V_364 ] -> V_284 = & ( V_378 -> V_26 ) ;
V_378 -> V_26 = V_376 . V_371 [ V_364 ] ;
V_378 -> V_372 = V_377 -> V_372 ;
V_378 -> V_284 = & ( V_376 . V_371 [ V_364 ] ) ;
V_376 . V_371 [ V_364 ] = V_378 ;
}
free ( V_366 -> V_369 ) ;
* V_366 = V_376 ;
}
V_364 = V_374 & ( V_366 -> V_360 - 1 ) ;
V_373 = & ( V_366 -> V_369 [ V_366 -> V_368 ++ ] ) ;
V_373 -> V_372 = V_372 ;
if( V_366 -> V_371 [ V_364 ] ) V_366 -> V_371 [ V_364 ] -> V_284 = & ( V_373 -> V_26 ) ;
V_373 -> V_26 = V_366 -> V_371 [ V_364 ] ;
V_366 -> V_371 [ V_364 ] = V_373 ;
V_373 -> V_284 = & ( V_366 -> V_371 [ V_364 ] ) ;
return 1 ;
}
const char * F_119 ( const char * V_379 )
{
unsigned V_364 ;
V_370 * V_373 ;
if( V_366 == 0 ) return 0 ;
V_364 = F_118 ( V_379 ) & ( V_366 -> V_360 - 1 ) ;
V_373 = V_366 -> V_371 [ V_364 ] ;
while( V_373 ) {
if( strcmp ( V_373 -> V_372 , V_379 ) == 0 ) break;
V_373 = V_373 -> V_26 ;
}
return V_373 ? V_373 -> V_372 : 0 ;
}
struct V_36 * F_66 ( const char * V_32 )
{
struct V_36 * V_29 ;
V_29 = F_21 ( V_32 ) ;
if( V_29 == 0 ) {
V_29 = (struct V_36 * ) calloc ( 1 , sizeof( struct V_36 ) ) ;
F_35 ( V_29 ) ;
V_29 -> V_81 = F_89 ( V_32 ) ;
V_29 -> type = isupper ( * V_32 ) ? V_78 : V_74 ;
V_29 -> V_41 = 0 ;
V_29 -> V_249 = 0 ;
V_29 -> V_64 = - 1 ;
V_29 -> V_124 = V_380 ;
V_29 -> V_72 = 0 ;
V_29 -> V_69 = V_70 ;
V_29 -> V_254 = 0 ;
V_29 -> V_255 = 0 ;
V_29 -> V_256 = 0 ;
V_29 -> V_167 = 0 ;
F_121 ( V_29 , V_29 -> V_81 ) ;
}
V_29 -> V_167 ++ ;
return V_29 ;
}
int V_170 ( const void * V_381 , const void * V_382 )
{
const struct V_36 * V_95 = * ( const struct V_36 * * ) V_381 ;
const struct V_36 * V_96 = * ( const struct V_36 * * ) V_382 ;
int V_383 = V_95 -> type == V_61 ? 3 : V_95 -> V_81 [ 0 ] > 'Z' ? 2 : 1 ;
int V_384 = V_96 -> type == V_61 ? 3 : V_96 -> V_81 [ 0 ] > 'Z' ? 2 : 1 ;
return V_383 == V_384 ? V_95 -> V_30 - V_96 -> V_30 : V_383 - V_384 ;
}
void F_63 ( void ) {
if( V_385 ) return;
V_385 = (struct V_386 * ) malloc ( sizeof( struct V_386 ) ) ;
if( V_385 ) {
V_385 -> V_360 = 128 ;
V_385 -> V_368 = 0 ;
V_385 -> V_369 = ( V_387 * ) calloc ( 128 , sizeof( V_387 ) + sizeof( V_387 * ) ) ;
if( V_385 -> V_369 == 0 ) {
free ( V_385 ) ;
V_385 = 0 ;
} else{
int V_9 ;
V_385 -> V_371 = ( V_387 * * ) & ( V_385 -> V_369 [ 128 ] ) ;
for( V_9 = 0 ; V_9 < 128 ; V_9 ++ ) V_385 -> V_371 [ V_9 ] = 0 ;
}
}
}
int F_121 ( struct V_36 * V_372 , const char * V_379 )
{
V_387 * V_373 ;
unsigned V_364 ;
unsigned V_374 ;
if( V_385 == 0 ) return 0 ;
V_374 = F_118 ( V_379 ) ;
V_364 = V_374 & ( V_385 -> V_360 - 1 ) ;
V_373 = V_385 -> V_371 [ V_364 ] ;
while( V_373 ) {
if( strcmp ( V_373 -> V_379 , V_379 ) == 0 ) {
return 0 ;
}
V_373 = V_373 -> V_26 ;
}
if( V_385 -> V_368 >= V_385 -> V_360 ) {
int V_9 , V_375 ;
struct V_386 V_376 ;
V_376 . V_360 = V_375 = V_385 -> V_360 * 2 ;
V_376 . V_368 = V_385 -> V_368 ;
V_376 . V_369 = ( V_387 * ) calloc ( V_375 , sizeof( V_387 ) + sizeof( V_387 * ) ) ;
if( V_376 . V_369 == 0 ) return 0 ;
V_376 . V_371 = ( V_387 * * ) & ( V_376 . V_369 [ V_375 ] ) ;
for( V_9 = 0 ; V_9 < V_375 ; V_9 ++ ) V_376 . V_371 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_385 -> V_368 ; V_9 ++ ) {
V_387 * V_377 , * V_378 ;
V_377 = & ( V_385 -> V_369 [ V_9 ] ) ;
V_364 = F_118 ( V_377 -> V_379 ) & ( V_375 - 1 ) ;
V_378 = & ( V_376 . V_369 [ V_9 ] ) ;
if( V_376 . V_371 [ V_364 ] ) V_376 . V_371 [ V_364 ] -> V_284 = & ( V_378 -> V_26 ) ;
V_378 -> V_26 = V_376 . V_371 [ V_364 ] ;
V_378 -> V_379 = V_377 -> V_379 ;
V_378 -> V_372 = V_377 -> V_372 ;
V_378 -> V_284 = & ( V_376 . V_371 [ V_364 ] ) ;
V_376 . V_371 [ V_364 ] = V_378 ;
}
free ( V_385 -> V_369 ) ;
* V_385 = V_376 ;
}
V_364 = V_374 & ( V_385 -> V_360 - 1 ) ;
V_373 = & ( V_385 -> V_369 [ V_385 -> V_368 ++ ] ) ;
V_373 -> V_379 = V_379 ;
V_373 -> V_372 = V_372 ;
if( V_385 -> V_371 [ V_364 ] ) V_385 -> V_371 [ V_364 ] -> V_284 = & ( V_373 -> V_26 ) ;
V_373 -> V_26 = V_385 -> V_371 [ V_364 ] ;
V_385 -> V_371 [ V_364 ] = V_373 ;
V_373 -> V_284 = & ( V_385 -> V_371 [ V_364 ] ) ;
return 1 ;
}
struct V_36 * F_21 ( const char * V_379 )
{
unsigned V_364 ;
V_387 * V_373 ;
if( V_385 == 0 ) return 0 ;
V_364 = F_118 ( V_379 ) & ( V_385 -> V_360 - 1 ) ;
V_373 = V_385 -> V_371 [ V_364 ] ;
while( V_373 ) {
if( strcmp ( V_373 -> V_379 , V_379 ) == 0 ) break;
V_373 = V_373 -> V_26 ;
}
return V_373 ? V_373 -> V_372 : 0 ;
}
struct V_36 * F_122 ( int V_51 )
{
struct V_36 * V_372 ;
if( V_385 && V_51 > 0 && V_51 <= V_385 -> V_368 ) {
V_372 = V_385 -> V_369 [ V_51 - 1 ] . V_372 ;
} else{
V_372 = 0 ;
}
return V_372 ;
}
int F_68 ( void )
{
return V_385 ? V_385 -> V_368 : 0 ;
}
struct V_36 * * F_69 ( void )
{
struct V_36 * * V_376 ;
int V_9 , V_375 ;
if( V_385 == 0 ) return 0 ;
V_375 = V_385 -> V_368 ;
V_376 = (struct V_36 * * ) calloc ( V_375 , sizeof( struct V_36 * ) ) ;
if( V_376 ) {
for( V_9 = 0 ; V_9 < V_375 ; V_9 ++ ) V_376 [ V_9 ] = V_385 -> V_369 [ V_9 ] . V_372 ;
}
return V_376 ;
}
int V_138 ( const char * V_381 , const char * V_382 )
{
const struct V_84 * V_95 = (struct V_84 * ) V_381 ;
const struct V_84 * V_96 = (struct V_84 * ) V_382 ;
int V_32 ;
V_32 = V_95 -> V_33 -> V_30 - V_96 -> V_33 -> V_30 ;
if( V_32 == 0 ) V_32 = V_95 -> V_104 - V_96 -> V_104 ;
return V_32 ;
}
T_2 int F_123 ( struct V_84 * V_95 , struct V_84 * V_96 )
{
int V_19 ;
for( V_19 = 0 ; V_19 == 0 && V_95 && V_96 ; V_95 = V_95 -> V_89 , V_96 = V_96 -> V_89 ) {
V_19 = V_95 -> V_33 -> V_30 - V_96 -> V_33 -> V_30 ;
if( V_19 == 0 ) V_19 = V_95 -> V_104 - V_96 -> V_104 ;
}
if( V_19 == 0 ) {
if( V_95 ) V_19 = 1 ;
if( V_96 ) V_19 = - 1 ;
}
return V_19 ;
}
T_2 unsigned F_124 ( struct V_84 * V_95 )
{
unsigned V_364 = 0 ;
while( V_95 ) {
V_364 = V_364 * 571 + V_95 -> V_33 -> V_30 * 37 + V_95 -> V_104 ;
V_95 = V_95 -> V_89 ;
}
return V_364 ;
}
struct V_40 * F_34 ( void )
{
struct V_40 * V_388 ;
V_388 = (struct V_40 * ) calloc ( 1 , sizeof( struct V_40 ) ) ;
F_35 ( V_388 ) ;
return V_388 ;
}
void F_64 ( void ) {
if( V_389 ) return;
V_389 = (struct V_390 * ) malloc ( sizeof( struct V_390 ) ) ;
if( V_389 ) {
V_389 -> V_360 = 128 ;
V_389 -> V_368 = 0 ;
V_389 -> V_369 = ( V_391 * ) calloc ( 128 , sizeof( V_391 ) + sizeof( V_391 * ) ) ;
if( V_389 -> V_369 == 0 ) {
free ( V_389 ) ;
V_389 = 0 ;
} else{
int V_9 ;
V_389 -> V_371 = ( V_391 * * ) & ( V_389 -> V_369 [ 128 ] ) ;
for( V_9 = 0 ; V_9 < 128 ; V_9 ++ ) V_389 -> V_371 [ V_9 ] = 0 ;
}
}
}
int F_36 ( struct V_40 * V_372 , struct V_84 * V_379 )
{
V_391 * V_373 ;
unsigned V_364 ;
unsigned V_374 ;
if( V_389 == 0 ) return 0 ;
V_374 = F_124 ( V_379 ) ;
V_364 = V_374 & ( V_389 -> V_360 - 1 ) ;
V_373 = V_389 -> V_371 [ V_364 ] ;
while( V_373 ) {
if( F_123 ( V_373 -> V_379 , V_379 ) == 0 ) {
return 0 ;
}
V_373 = V_373 -> V_26 ;
}
if( V_389 -> V_368 >= V_389 -> V_360 ) {
int V_9 , V_375 ;
struct V_390 V_376 ;
V_376 . V_360 = V_375 = V_389 -> V_360 * 2 ;
V_376 . V_368 = V_389 -> V_368 ;
V_376 . V_369 = ( V_391 * ) calloc ( V_375 , sizeof( V_391 ) + sizeof( V_391 * ) ) ;
if( V_376 . V_369 == 0 ) return 0 ;
V_376 . V_371 = ( V_391 * * ) & ( V_376 . V_369 [ V_375 ] ) ;
for( V_9 = 0 ; V_9 < V_375 ; V_9 ++ ) V_376 . V_371 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_389 -> V_368 ; V_9 ++ ) {
V_391 * V_377 , * V_378 ;
V_377 = & ( V_389 -> V_369 [ V_9 ] ) ;
V_364 = F_124 ( V_377 -> V_379 ) & ( V_375 - 1 ) ;
V_378 = & ( V_376 . V_369 [ V_9 ] ) ;
if( V_376 . V_371 [ V_364 ] ) V_376 . V_371 [ V_364 ] -> V_284 = & ( V_378 -> V_26 ) ;
V_378 -> V_26 = V_376 . V_371 [ V_364 ] ;
V_378 -> V_379 = V_377 -> V_379 ;
V_378 -> V_372 = V_377 -> V_372 ;
V_378 -> V_284 = & ( V_376 . V_371 [ V_364 ] ) ;
V_376 . V_371 [ V_364 ] = V_378 ;
}
free ( V_389 -> V_369 ) ;
* V_389 = V_376 ;
}
V_364 = V_374 & ( V_389 -> V_360 - 1 ) ;
V_373 = & ( V_389 -> V_369 [ V_389 -> V_368 ++ ] ) ;
V_373 -> V_379 = V_379 ;
V_373 -> V_372 = V_372 ;
if( V_389 -> V_371 [ V_364 ] ) V_389 -> V_371 [ V_364 ] -> V_284 = & ( V_373 -> V_26 ) ;
V_373 -> V_26 = V_389 -> V_371 [ V_364 ] ;
V_389 -> V_371 [ V_364 ] = V_373 ;
V_373 -> V_284 = & ( V_389 -> V_371 [ V_364 ] ) ;
return 1 ;
}
struct V_40 * F_27 ( struct V_84 * V_379 )
{
unsigned V_364 ;
V_391 * V_373 ;
if( V_389 == 0 ) return 0 ;
V_364 = F_124 ( V_379 ) & ( V_389 -> V_360 - 1 ) ;
V_373 = V_389 -> V_371 [ V_364 ] ;
while( V_373 ) {
if( F_123 ( V_373 -> V_379 , V_379 ) == 0 ) break;
V_373 = V_373 -> V_26 ;
}
return V_373 ? V_373 -> V_372 : 0 ;
}
struct V_40 * * F_72 ( void )
{
struct V_40 * * V_376 ;
int V_9 , V_375 ;
if( V_389 == 0 ) return 0 ;
V_375 = V_389 -> V_368 ;
V_376 = (struct V_40 * * ) calloc ( V_375 , sizeof( struct V_40 * ) ) ;
if( V_376 ) {
for( V_9 = 0 ; V_9 < V_375 ; V_9 ++ ) V_376 [ V_9 ] = V_389 -> V_369 [ V_9 ] . V_372 ;
}
return V_376 ;
}
T_2 unsigned F_125 ( struct V_84 * V_95 )
{
unsigned V_364 = 0 ;
V_364 = V_364 * 571 + V_95 -> V_33 -> V_30 * 37 + V_95 -> V_104 ;
return V_364 ;
}
void F_48 ( void ) {
if( V_392 ) return;
V_392 = (struct V_393 * ) malloc ( sizeof( struct V_393 ) ) ;
if( V_392 ) {
V_392 -> V_360 = 64 ;
V_392 -> V_368 = 0 ;
V_392 -> V_369 = ( V_394 * ) calloc ( 64 , sizeof( V_394 ) + sizeof( V_394 * ) ) ;
if( V_392 -> V_369 == 0 ) {
free ( V_392 ) ;
V_392 = 0 ;
} else{
int V_9 ;
V_392 -> V_371 = ( V_394 * * ) & ( V_392 -> V_369 [ 64 ] ) ;
for( V_9 = 0 ; V_9 < 64 ; V_9 ++ ) V_392 -> V_371 [ V_9 ] = 0 ;
}
}
}
int F_52 ( struct V_84 * V_372 )
{
V_394 * V_373 ;
unsigned V_364 ;
unsigned V_374 ;
if( V_392 == 0 ) return 0 ;
V_374 = F_125 ( V_372 ) ;
V_364 = V_374 & ( V_392 -> V_360 - 1 ) ;
V_373 = V_392 -> V_371 [ V_364 ] ;
while( V_373 ) {
if( V_138 ( ( const char * ) V_373 -> V_372 , ( const char * ) V_372 ) == 0 ) {
return 0 ;
}
V_373 = V_373 -> V_26 ;
}
if( V_392 -> V_368 >= V_392 -> V_360 ) {
int V_9 , V_375 ;
struct V_393 V_376 ;
V_376 . V_360 = V_375 = V_392 -> V_360 * 2 ;
V_376 . V_368 = V_392 -> V_368 ;
V_376 . V_369 = ( V_394 * ) calloc ( V_375 , sizeof( V_394 ) + sizeof( V_394 * ) ) ;
if( V_376 . V_369 == 0 ) return 0 ;
V_376 . V_371 = ( V_394 * * ) & ( V_376 . V_369 [ V_375 ] ) ;
for( V_9 = 0 ; V_9 < V_375 ; V_9 ++ ) V_376 . V_371 [ V_9 ] = 0 ;
for( V_9 = 0 ; V_9 < V_392 -> V_368 ; V_9 ++ ) {
V_394 * V_377 , * V_378 ;
V_377 = & ( V_392 -> V_369 [ V_9 ] ) ;
V_364 = F_125 ( V_377 -> V_372 ) & ( V_375 - 1 ) ;
V_378 = & ( V_376 . V_369 [ V_9 ] ) ;
if( V_376 . V_371 [ V_364 ] ) V_376 . V_371 [ V_364 ] -> V_284 = & ( V_378 -> V_26 ) ;
V_378 -> V_26 = V_376 . V_371 [ V_364 ] ;
V_378 -> V_372 = V_377 -> V_372 ;
V_378 -> V_284 = & ( V_376 . V_371 [ V_364 ] ) ;
V_376 . V_371 [ V_364 ] = V_378 ;
}
free ( V_392 -> V_369 ) ;
* V_392 = V_376 ;
}
V_364 = V_374 & ( V_392 -> V_360 - 1 ) ;
V_373 = & ( V_392 -> V_369 [ V_392 -> V_368 ++ ] ) ;
V_373 -> V_372 = V_372 ;
if( V_392 -> V_371 [ V_364 ] ) V_392 -> V_371 [ V_364 ] -> V_284 = & ( V_373 -> V_26 ) ;
V_373 -> V_26 = V_392 -> V_371 [ V_364 ] ;
V_392 -> V_371 [ V_364 ] = V_373 ;
V_373 -> V_284 = & ( V_392 -> V_371 [ V_364 ] ) ;
return 1 ;
}
struct V_84 * F_51 ( struct V_84 * V_379 )
{
int V_364 ;
V_394 * V_373 ;
if( V_392 == 0 ) return 0 ;
V_364 = F_125 ( V_379 ) & ( V_392 -> V_360 - 1 ) ;
V_373 = V_392 -> V_371 [ V_364 ] ;
while( V_373 ) {
if( V_138 ( ( const char * ) V_373 -> V_372 , ( const char * ) V_379 ) == 0 ) break;
V_373 = V_373 -> V_26 ;
}
return V_373 ? V_373 -> V_372 : 0 ;
}
void F_49 ( int (* F_126)( struct V_84 * ) )
{
int V_9 ;
if( V_392 == 0 || V_392 -> V_368 == 0 ) return;
if( F_126 ) for( V_9 = 0 ; V_9 < V_392 -> V_368 ; V_9 ++ ) (* F_126)( V_392 -> V_369 [ V_9 ] . V_372 ) ;
for( V_9 = 0 ; V_9 < V_392 -> V_360 ; V_9 ++ ) V_392 -> V_371 [ V_9 ] = 0 ;
V_392 -> V_368 = 0 ;
return;
}
