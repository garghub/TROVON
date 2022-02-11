static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
V_5 = & V_2 -> V_6 [ V_2 -> V_7 ] ;
V_5 -> V_8 = V_2 -> V_9 . V_10 ;
V_5 -> V_11 = V_2 -> V_9 . V_12 ;
V_5 -> V_13 = 0 ;
V_5 -> type =
( 4 << 8 ) | V_14 | V_15 | V_16 ;
V_5 -> V_17 = 0 ;
V_5 -> V_18 = 0 ;
V_5 -> V_19 = 0 ;
V_3 = V_2 -> V_20 -> V_21 ( V_2 -> V_20 ,
V_5 ,
F_2
( V_5 -> type ) ) ;
if ( V_3 == 0 )
F_3 ( V_2 , L_1
L_2 ) ;
return V_3 ;
}
static T_1 F_4 ( T_1 V_22 )
{
if ( V_22 > 0xF )
return 0xFF ;
if ( V_22 <= 9 )
V_22 += 0x30 ;
else
V_22 += 0x37 ;
return V_22 ;
}
static void F_5 ( T_2 V_22 , char * V_23 )
{
T_2 V_24 ;
char * V_25 = V_26 ;
char * V_27 = V_23 ;
T_1 V_28 ;
for ( V_24 = 0 ; V_24 < ( V_29 + V_30 ) ; V_24 ++ )
* ( V_27 + V_24 ) = 0 ;
for ( V_24 = 0 ; V_24 < strlen ( V_26 ) ; V_24 ++ ) {
* V_27 = * ( V_25 + V_24 ) ;
V_27 ++ ;
}
for ( V_24 = 0 ; V_24 < sizeof( V_22 ) ; V_24 ++ ) {
#ifndef F_6
V_28 = * ( ( ( T_1 * ) & V_22 ) + ( sizeof( V_22 ) - 1 ) - V_24 ) ;
* V_27 = F_4 ( ( V_28 & 0xF0 ) >> 4 ) ;
V_27 ++ ;
* V_27 = F_4 ( V_28 & 0x0F ) ;
V_27 ++ ;
#else
V_28 = * ( ( ( T_1 * ) & V_22 ) + V_24 ) ;
* V_27 = F_4 ( ( V_28 & 0xF0 ) >> 4 ) ;
V_27 ++ ;
* V_27 = F_4 ( V_28 & 0x0F ) ;
V_27 ++ ;
#endif
}
* V_27 = 0 ;
}
static struct V_31 * F_7 ( struct V_1 * V_2 ,
T_2 V_32 , char * V_33 )
{
struct V_31 * V_34 = NULL ;
T_2 V_24 ;
V_34 =
(struct V_31 * ) V_2 -> V_35 -> V_21 ( V_2 -> V_35 ,
( sizeof
( struct
V_31 )
+ V_32 +
1 ) ) ;
if ( V_34 != NULL ) {
for ( V_24 = 0 ; V_24 < ( sizeof( struct V_31 ) + V_32 + 1 ) ;
V_24 ++ )
* ( ( T_1 * ) V_34 + V_24 ) = 0 ;
V_34 -> V_36 = V_2 -> V_9 . V_37 ;
V_2 -> V_9 . V_37 ++ ;
V_2 -> V_9 . V_38 += V_32 + 1 ;
V_34 -> V_39 = NULL ;
if ( V_2 -> V_9 . V_40 == NULL )
V_2 -> V_9 . V_40 = V_34 ;
else
V_2 -> V_9 . V_41 -> V_39 = V_34 ;
V_2 -> V_9 . V_41 = V_34 ;
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ )
V_34 -> V_33 [ V_24 ] = V_33 [ V_24 ] ;
}
return V_34 ;
}
static struct V_31 * F_8 ( struct V_1 * V_2 ,
char * V_33 )
{
struct V_31 * V_42 = NULL ;
struct V_31 * V_3 = NULL ;
T_2 V_24 ;
T_2 V_32 = strlen ( V_33 ) ;
for ( V_42 = V_2 -> V_9 . V_40 ;
( V_3 == NULL ) && ( V_42 != NULL ) ; V_42 = V_42 -> V_39 ) {
if ( V_32 != strlen ( V_42 -> V_33 ) )
continue;
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ ) {
if ( V_33 [ V_24 ] != V_42 -> V_33 [ V_24 ] )
break;
}
if ( V_24 == V_32 )
V_3 = V_42 ;
}
return V_3 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_31 * V_43 ;
char * V_44 ;
char * V_28 ;
V_2 -> V_9 . V_10 =
( char * ) V_2 -> V_35 -> V_21 ( V_2 -> V_35 ,
V_2 -> V_9 .
V_38 ) ;
if ( V_2 -> V_9 . V_10 != NULL ) {
V_44 = V_2 -> V_9 . V_10 ;
V_43 = V_2 -> V_9 . V_40 ;
while ( V_43 != NULL ) {
V_2 -> V_9 . V_40 = V_43 -> V_39 ;
if ( V_2 -> V_9 . V_41 == V_43 )
V_2 -> V_9 . V_41 = NULL ;
for ( V_28 = V_43 -> V_33 ;
* V_28 != '\0' ; V_28 ++ , V_44 ++ )
* V_44 = * V_28 ;
* V_44 = '\0' ;
V_44 ++ ;
V_2 -> V_35 -> V_45 ( V_2 -> V_35 ,
V_43 ) ;
V_43 = V_2 -> V_9 . V_40 ;
}
V_3 = 1 ;
} else
F_3 ( V_2 , L_3
L_4 ) ;
return V_3 ;
}
static T_2 F_10 ( struct V_1 * V_2 , T_2 V_46 )
{
T_2 V_3 ;
if ( V_2 -> V_9 . V_12 == 0 ) {
F_11 ( V_2 -> V_35 , L_5
L_6 ,
V_2 -> V_47 ) ;
}
V_3 = V_2 -> V_9 . V_12 ;
V_2 -> V_9 . V_12 += V_46 ;
return V_3 ;
}
static struct V_48 * F_12 ( struct V_1 * V_2 ,
T_2 V_49 ,
struct V_50 * V_51 )
{
struct V_48 * V_52 = NULL ;
T_2 V_24 ;
V_52 =
(struct V_48 * ) V_2 -> V_35 -> V_21 ( V_2 -> V_35 ,
sizeof( struct V_48 ) ) ;
if ( V_52 != NULL ) {
for ( V_24 = 0 ; V_24 != sizeof( struct V_48 ) ; V_24 ++ )
* ( ( char * ) V_52 + V_24 ) = 0 ;
V_52 -> V_36 = V_2 -> V_9 . V_53 ;
V_2 -> V_9 . V_53 ++ ;
V_52 -> V_54 = * V_51 ;
V_52 -> V_49 = V_49 ;
V_52 -> V_39 = NULL ;
if ( V_2 -> V_9 . V_55 == NULL )
V_2 -> V_9 . V_55 = V_52 ;
else
V_2 -> V_9 . V_56 -> V_39 = V_52 ;
V_2 -> V_9 . V_56 = V_52 ;
}
return V_52 ;
}
static struct V_48 * F_13 ( struct V_1 * V_2 ,
T_2 V_57 )
{
struct V_48 * V_58 = NULL ;
for ( V_58 = V_2 -> V_9 . V_55 ;
V_58 != NULL ; V_58 = V_58 -> V_39 ) {
if ( V_58 -> V_49 == V_57 )
break;
}
return V_58 ;
}
static struct V_48 * F_14 ( struct V_1 * V_2 ,
char * string )
{
struct V_48 * V_58 = NULL ;
struct V_31 * V_59 = NULL ;
V_59 = F_8 ( V_2 , string ) ;
if ( V_59 != NULL )
V_58 = F_13 ( V_2 , V_59 -> V_36 ) ;
return V_58 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_48 * V_60 ;
struct V_4 * V_61 =
& V_2 -> V_6 [ V_2 -> V_7 ] ;
struct V_50 * V_52 ;
V_2 -> V_9 . V_62 =
(struct V_50 * ) V_2 -> V_35 -> V_21 ( V_2 -> V_35 ,
( sizeof( struct V_50 ) * V_2 -> V_9 .
V_53 ) ) ;
if ( V_2 -> V_9 . V_62 != NULL ) {
V_52 = V_2 -> V_9 . V_62 ;
V_60 = V_2 -> V_9 . V_55 ;
while ( V_60 != NULL ) {
V_2 -> V_9 . V_55 = V_60 -> V_39 ;
if ( V_60 == V_2 -> V_9 . V_56 )
V_2 -> V_9 . V_56 = NULL ;
* V_52 = V_60 -> V_54 ;
if ( V_52 -> V_63 < 0 ) {
V_52 -> V_22 += V_61 -> V_19 ;
V_52 -> V_64 = V_52 -> V_22 ;
}
V_2 -> V_35 -> V_45 ( V_2 -> V_35 , V_60 ) ;
V_60 = V_2 -> V_9 . V_55 ;
V_52 ++ ;
}
V_3 = 1 ;
} else
F_3 ( V_2 , L_7 ) ;
return V_3 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_65 ,
T_2 V_66 , struct V_48 * V_67 )
{
struct V_68 * V_69 = NULL ;
T_2 V_24 ;
T_2 V_70 = F_17 () ;
T_1 * V_71 ;
T_1 * V_72 ;
struct V_73 * V_74 ;
int V_3 = 0 ;
V_69 =
(struct V_68 * ) V_2 -> V_35 -> V_21 ( V_2 -> V_35 ,
V_70 ) ;
if ( V_69 != NULL ) {
V_69 -> V_65 = V_65 ;
V_72 = ( T_1 * ) & V_69 -> V_75 ;
V_71 = ( T_1 * ) & V_76 [ V_66 ] ;
for ( V_24 = 0 ; V_24 < V_70 ; V_24 ++ ) {
* V_72 = * V_71 ;
V_72 ++ ;
V_71 ++ ;
}
V_74 =
(struct V_73 * ) ( ( T_1 * ) & V_69 -> V_75 +
V_69 -> V_75 . V_77 ) ;
for ( V_24 = 0 ; V_24 < V_69 -> V_75 . V_78 ; V_24 ++ )
V_74 [ V_24 ] . V_79 = V_67 -> V_36 ;
V_69 -> V_39 = V_2 -> V_9 . V_80 ;
V_2 -> V_9 . V_80 = V_69 ;
V_3 = 1 ;
}
return V_3 ;
}
static int F_18 ( struct V_1 * V_2 , T_3 * V_81 ,
struct V_73 * V_82 [] , T_2 V_83 )
{
int V_3 = 1 ;
T_2 V_24 ;
bool V_28 ;
for ( V_24 = 0 ; V_24 < V_83 ; V_24 ++ )
F_19 ( V_2 , V_81 , V_82 [ V_24 ] , & V_28 , true ) ;
return V_3 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_3 = 1 ;
struct V_68 * V_84 = NULL ;
struct V_73 * V_85 [ V_86 ] ;
T_2 V_87 ;
T_2 V_24 ;
struct V_73 * V_74 ;
struct V_4 * V_5 =
& V_2 -> V_6 [ V_2 -> V_7 ] ;
V_84 = V_2 -> V_9 . V_80 ;
while ( ( V_3 != 0 ) && ( V_84 != NULL ) ) {
V_2 -> V_9 . V_80 = V_84 -> V_39 ;
V_2 -> V_88 = V_5 ;
V_2 -> V_89 = V_84 -> V_65 ;
V_2 -> V_90 = V_5 -> V_18 ;
V_87 = 0 ;
V_74 = (struct V_73 * ) ( ( T_1 * ) & V_84 -> V_75 +
V_84 -> V_75 . V_77 ) ;
while ( V_87 < V_84 -> V_75 . V_78 ) {
#ifdef F_21
F_11 ( V_2 -> V_35 ,
L_8 ,
V_5 -> V_18 +
V_2 -> V_89 ,
V_2 ->
V_9 . V_62 [ V_74 ->
V_79 ] . V_22 ) ;
#endif
for ( V_24 = 0 ;
( ( V_24 < V_86 ) &&
( ( V_24 + V_87 ) < V_84 -> V_75 . V_78 ) ) ; V_24 ++ )
V_85 [ V_24 ] = V_74 + V_24 ;
V_3 = F_18 ( V_2 ,
( T_3 * ) & V_84 -> V_91 ,
V_85 , V_24 ) ;
if ( V_3 == 0 ) {
F_3 ( V_2 ,
L_9
L_10 , V_84 -> V_65 +
V_5 -> V_18 ) ;
break;
}
V_87 += V_24 ;
V_74 += V_24 ;
}
if ( V_3 != 0 ) {
V_3 = V_2 -> V_92 -> V_93 ( V_2 -> V_92 ,
& V_84 -> V_91 ,
V_5 -> V_19 +
V_84 -> V_65 ,
V_5 ,
F_22
( V_84 -> V_75 .
V_94 ) ) ;
if ( V_3 == 0 ) {
F_3 ( V_2 ,
L_11 V_95 L_10 ,
V_5 -> V_19 +
V_84 -> V_65 ) ;
}
V_2 -> V_35 -> V_45 ( V_2 -> V_35 , V_84 ) ;
V_84 = V_2 -> V_9 . V_80 ;
}
}
return V_3 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_3 = 1 ;
struct V_96 * V_84 ;
struct V_97 * V_74 ;
struct V_73 * V_85 [ V_86 ] ;
struct V_98 * V_99 = NULL ;
T_4 V_24 ;
V_84 = V_2 -> V_9 . V_100 ;
while ( ( V_3 != 0 ) && ( V_84 != NULL ) ) {
V_2 -> V_9 . V_100 = V_84 -> V_39 ;
V_2 -> V_88 = & V_2 -> V_6 [ V_84 -> V_63 ] ;
V_2 -> V_89 = V_84 -> V_101 ;
V_24 = ( T_4 ) ( V_2 -> V_88 - V_2 -> V_6 ) ;
V_99 = V_2 -> V_102 + V_24 ;
V_2 -> V_90 = V_99 -> V_103 ;
V_74 = V_84 -> V_104 ;
while ( V_74 != NULL ) {
for ( V_24 = 0 ; ( V_24 < V_86 )
&& ( V_74 != NULL ) ;
V_24 ++ , V_74 = V_74 -> V_39 ) {
V_85 [ V_24 ] = & V_74 -> V_105 ;
V_84 -> V_104 = V_74 -> V_39 ;
}
V_3 = F_18 ( V_2 ,
V_84 -> V_106 . V_107 ,
V_85 , V_24 ) ;
if ( V_3 == 0 ) {
F_3 ( V_2 ,
L_12
L_10 , V_84 -> V_101 +
V_2 -> V_88 -> V_18 ) ;
break;
}
while ( V_24 > 0 ) {
V_2 -> V_35 -> V_45 ( V_2 -> V_35 ,
F_24
( V_85 [ V_24 - 1 ] ,
struct V_97 ,
V_105 ) ) ;
V_24 -- ;
}
}
if ( V_3 != 0 ) {
V_3 = V_2 -> V_92 -> V_93 ( V_2 -> V_92 ,
V_84 -> V_106 .
V_107 ,
V_2 -> V_88 ->
V_19 +
V_84 -> V_101 ,
V_2 -> V_88 ,
F_22
( V_84 -> V_106 .
V_108 ) ) ;
if ( V_3 == 0 ) {
F_3 ( V_2 ,
L_11 V_95 L_10 ,
V_2 -> V_88 -> V_19 +
V_84 -> V_101 ) ;
}
V_2 -> V_35 -> V_45 ( V_2 -> V_35 , V_84 ) ;
V_84 = V_2 -> V_9 . V_100 ;
}
}
return V_3 ;
}
static struct V_96 * F_25 ( struct V_1 * V_2 ,
T_5 V_63 , T_2 V_89 )
{
struct V_96 * V_84 = NULL ;
for ( V_84 = V_2 -> V_9 . V_100 ;
V_84 != NULL ; V_84 = V_84 -> V_39 ) {
if ( ( V_84 -> V_63 == V_63 ) &&
( V_84 -> V_101 == V_89 ) ) {
break;
}
}
return V_84 ;
}
static int F_26 ( struct V_1 * V_2 ,
T_5 V_63 , T_2 V_89 ,
struct V_109 * V_110 ,
struct V_73 * V_82 ,
struct V_48 * V_111 )
{
struct V_96 * V_112 = NULL ;
T_2 V_113 ;
T_4 V_24 ;
int V_3 = 0 ;
struct V_97 * V_114 = NULL ;
V_112 = F_25 ( V_2 , V_63 , V_89 ) ;
if ( V_112 == NULL ) {
V_113 = sizeof( struct V_96 ) +
V_110 -> V_108 ;
V_112 = (struct V_96 * )
V_2 -> V_35 -> V_21 ( V_2 -> V_35 , V_113 ) ;
if ( V_112 != NULL ) {
V_112 -> V_63 = V_63 ;
V_112 -> V_101 = V_89 ;
V_112 -> V_104 = NULL ;
V_112 -> V_106 = * V_110 ;
V_112 -> V_106 . V_107 = ( T_1 * ) ( V_112 + 1 ) ;
for ( V_24 = 0 ; V_24 < V_110 -> V_108 ; V_24 ++ )
* ( V_112 -> V_106 . V_107 + V_24 ) =
* ( V_110 -> V_107 + V_24 ) ;
V_112 -> V_39 = V_2 -> V_9 . V_100 ;
V_2 -> V_9 . V_100 = V_112 ;
} else
F_3 ( V_2 , L_13 ) ;
} else {
for ( V_24 = 0 ; V_24 < V_112 -> V_106 . V_108 ; V_24 ++ )
* ( V_112 -> V_106 . V_107 + V_24 ) =
* ( V_110 -> V_107 + V_24 ) ;
}
if ( V_112 != NULL ) {
V_114 = V_2 -> V_35 -> V_21 ( V_2 -> V_35 ,
sizeof( struct V_97 ) ) ;
if ( V_114 != NULL ) {
V_114 -> V_105 = * V_82 ;
V_114 -> V_105 . V_79 = V_111 -> V_36 ;
V_114 -> V_39 = V_112 -> V_104 ;
V_112 -> V_104 = V_114 ;
V_3 = 1 ;
} else
F_3 ( V_2 , L_14 ) ;
}
return V_3 ;
}
bool F_27 ( struct V_1 * V_2 , struct V_73 * V_82 )
{
bool V_3 = false ;
T_6 V_115 ;
T_6 V_66 ;
V_115 = F_28 ( V_82 -> TYPE ) ;
V_66 = V_116 [ V_115 ] ;
if ( V_66 != V_117 )
V_3 = true ;
return V_3 ;
}
int F_29 ( struct V_1 * V_2 , T_5 V_63 ,
T_2 V_89 , struct V_109 * V_110 ,
struct V_73 * V_82 )
{
T_6 V_115 ;
T_6 V_66 ;
int V_3 = 1 ;
char V_118 [ V_29 + V_30 ] ;
struct V_50 * V_119 ;
struct V_48 * V_111 ;
struct V_48 * V_67 ;
struct V_31 * V_120 ;
T_2 V_121 ;
struct V_50 V_51 ;
struct V_50 V_122 ;
V_115 = F_28 ( V_82 -> TYPE ) ;
V_66 = V_116 [ V_115 ] ;
if ( V_66 != V_117 ) {
if ( V_2 -> V_9 . V_40 == NULL ) {
F_7 ( V_2 ,
strlen ( V_123 ) ,
V_123 ) ;
}
#ifdef F_21
F_11 ( V_2 -> V_35 ,
L_15 ,
V_2 -> V_6 [ V_63 ] . V_18 +
V_89 + V_82 -> V_124 ,
V_2 -> V_125 [ V_82 -> V_79 ] . V_22 ) ;
#endif
if ( V_82 -> V_79 == - 1 ) {
V_122 . V_22 =
V_2 -> V_6 [ V_63 ] . V_18 ;
V_122 . V_64 = V_2 -> V_102 [ V_63 ] . V_103 ;
V_119 = & V_122 ;
} else
V_119 = & ( V_2 -> V_125 [ V_82 -> V_79 ] ) ;
F_5 ( V_119 -> V_22 , V_118 ) ;
V_111 = F_14 ( V_2 , V_118 ) ;
if ( V_111 == NULL ) {
V_120 = F_7 ( V_2 ,
strlen
( V_118 ) ,
V_118 ) ;
if ( V_120 == NULL ) {
F_3 ( V_2 , L_16
L_17 ) ;
V_3 = 0 ;
} else {
V_121 = F_10 ( V_2 ,
F_30 () ) ;
V_51 . V_22 = V_121 ;
V_51 . V_64 = 0 ;
V_51 . V_63 = - 1 ;
V_51 . V_126 = 0 ;
V_111 = F_12 ( V_2 ,
V_120 ->
V_36 ,
& V_51 ) ;
V_67 = F_12 ( V_2 , - 1 ,
V_119 ) ;
if ( ( V_111 != NULL ) &&
( V_67 != NULL ) ) {
V_3 = F_16 ( V_2 ,
V_121 ,
V_66 ,
V_67 ) ;
if ( V_3 != 1 ) {
F_3 ( V_2 , L_18
L_19
L_20 ) ;
}
} else {
F_3 ( V_2 , L_21
L_22
L_23 ,
V_111 , V_67 ) ;
V_3 = 0 ;
}
}
}
if ( V_3 == 1 ) {
V_3 = F_26 ( V_2 , V_63 , V_89 ,
V_110 , V_82 , V_111 ) ;
if ( V_3 != 1 ) {
F_3 ( V_2 , L_24
L_25 ) ;
}
}
}
return V_3 ;
}
int F_31 ( struct V_1 * V_2 , T_5 V_63 ,
T_2 V_89 , struct V_109 * V_110 )
{
struct V_96 * V_112 = NULL ;
T_4 V_24 ;
int V_3 = 0 ;
V_112 = F_25 ( V_2 , V_63 , V_89 ) ;
if ( V_112 != NULL ) {
for ( V_24 = 0 ; V_24 < V_112 -> V_106 . V_108 ; V_24 ++ )
* ( V_112 -> V_106 . V_107 + V_24 ) =
* ( V_110 -> V_107 + V_24 ) ;
V_3 = 1 ;
} else {
F_3 ( V_2 ,
L_26 ,
V_63 , V_89 ) ;
}
return V_3 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_3 = 1 ;
if ( V_2 -> V_9 . V_12 != 0 ) {
V_3 = F_9 ( V_2 ) ;
if ( V_3 != 0 )
V_3 = F_1 ( V_2 ) ;
if ( V_3 != 0 )
V_3 = F_15 ( V_2 ) ;
if ( V_3 != 0 )
V_3 = F_20 ( V_2 ) ;
if ( V_3 != 0 )
V_3 = F_23 ( V_2 ) ;
}
return V_3 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_127 * V_9 = & V_2 -> V_9 ;
struct V_48 * V_60 ;
struct V_31 * V_43 ;
struct V_68 * V_128 ;
struct V_96 * V_129 ;
struct V_97 * V_130 ;
if ( V_9 -> V_12 == 0 )
return;
for ( V_60 = V_9 -> V_55 ;
V_60 != NULL ; V_60 = V_9 -> V_55 ) {
V_9 -> V_55 = V_60 -> V_39 ;
if ( V_9 -> V_56 == V_60 )
V_9 -> V_56 = NULL ;
V_2 -> V_35 -> V_45 ( V_2 -> V_35 , V_60 ) ;
}
if ( V_9 -> V_62 != NULL )
V_2 -> V_35 -> V_45 ( V_2 -> V_35 ,
V_9 -> V_62 ) ;
for ( V_43 = V_9 -> V_40 ;
V_43 != NULL ; V_43 = V_9 -> V_40 ) {
V_9 -> V_40 = V_43 -> V_39 ;
if ( V_9 -> V_41 == V_43 )
V_9 -> V_41 = NULL ;
V_2 -> V_35 -> V_45 ( V_2 -> V_35 , V_43 ) ;
}
if ( V_9 -> V_10 != NULL )
V_2 -> V_35 -> V_45 ( V_2 -> V_35 ,
V_9 -> V_10 ) ;
for ( V_128 = V_9 -> V_80 ;
V_128 != NULL ; V_128 = V_9 -> V_80 ) {
V_9 -> V_80 = V_128 -> V_39 ;
V_2 -> V_35 -> V_45 ( V_2 -> V_35 , V_128 ) ;
}
for ( V_129 = V_9 -> V_100 ;
V_129 != NULL ; V_129 = V_9 -> V_100 ) {
V_9 -> V_100 = V_129 -> V_39 ;
for ( V_130 = V_129 -> V_104 ;
V_130 != NULL ;
V_130 = V_129 -> V_104 ) {
V_129 -> V_104 = V_130 -> V_39 ;
V_2 -> V_35 -> V_45 ( V_2 -> V_35 ,
V_130 ) ;
}
V_2 -> V_35 -> V_45 ( V_2 -> V_35 , V_129 ) ;
}
}
