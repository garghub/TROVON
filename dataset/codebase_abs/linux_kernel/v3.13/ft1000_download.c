static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
int V_5 ;
V_3 = 0 ;
while ( V_3 < 10 ) {
V_5 = F_2 ( V_2 , & V_4 ,
V_6 ) ;
F_3 ( L_1 ,
V_4 ) ;
if ( V_4 & 0x0080 ) {
F_3 ( L_2 ) ;
V_5 = F_4 ( V_2 , 0x0080 ,
V_6 ) ;
V_5 = F_4 ( V_2 , 0x0100 ,
V_6 ) ;
V_5 = F_4 ( V_2 , 0x8000 ,
V_6 ) ;
break;
} else {
V_3 ++ ;
F_5 ( 10 ) ;
}
}
V_3 = 0 ;
while ( V_3 < 20 ) {
V_5 = F_2 ( V_2 , & V_4 ,
V_6 ) ;
F_3 ( L_3 , V_4 ) ;
if ( V_4 & 0x8000 ) {
V_3 ++ ;
F_5 ( 10 ) ;
} else {
F_3 ( L_4 ) ;
return 0 ;
}
}
return V_7 ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_8 )
{
T_1 V_9 ;
int V_3 ;
int V_5 = 0 ;
V_3 = 0 ;
while ( V_3 < 100 ) {
V_5 = F_4 ( V_2 , V_10 ,
V_6 ) ;
if ( V_2 -> V_11 ) {
F_3 ( L_5 ,
V_2 -> V_11 ) ;
V_2 -> V_11 = 0 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 != V_12 ) {
F_3 ( L_6 ) ;
V_5 = V_13 ;
break;
}
V_5 = F_4 ( V_2 ,
V_10 ,
V_6 ) ;
}
V_5 = F_7 ( V_2 ,
V_14 , ( V_15 * ) & V_9 , 1 ) ;
V_9 = F_8 ( V_9 ) ;
if ( V_5 )
return V_16 ;
if ( ( V_9 == V_8 ) ||
( V_9 == V_17 ) ) {
return V_9 ;
} else {
V_3 ++ ;
F_5 ( 10 ) ;
}
}
return V_16 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_18 )
{
T_2 V_19 ;
T_1 V_20 ;
int V_5 ;
V_19 = ( T_2 ) V_18 ;
V_19 = F_10 ( V_19 ) ;
V_20 = ( T_1 ) ( V_19 & 0xffff ) ;
V_5 = F_11 ( V_2 , V_14 ,
V_20 , 0 ) ;
V_20 = ( T_1 ) ( V_19 >> 16 ) ;
V_5 = F_11 ( V_2 , V_14 ,
V_20 , 1 ) ;
V_5 = F_4 ( V_2 , V_21 ,
V_6 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_1 V_8 )
{
T_1 V_9 ;
int V_3 ;
T_1 V_4 ;
int V_5 = 0 ;
V_3 = 0 ;
V_9 = 0 ;
while ( V_3 < 100 ) {
if ( V_2 -> V_22 == 2 ) {
V_5 = F_13 ( V_2 , 0 ,
( V_15 * ) & ( V_2 -> V_23 [ 0 ] ) , 64 ) ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
F_3 ( L_7 , V_4 ,
V_2 -> V_23 [ V_4 ] ) ;
}
V_5 = F_7 ( V_2 ,
V_14 ,
( V_15 * ) & V_9 , 1 ) ;
F_3 ( L_8 ,
V_9 ) ;
if ( V_2 -> V_24 == V_2 -> V_23 [ 6 ] ) {
V_9 = 0 ;
} else {
V_9 = V_2 -> V_23 [ 1 ] ;
V_2 -> V_24 =
V_2 -> V_23 [ 6 ] ;
}
} else {
V_5 = F_7 ( V_2 ,
V_14 ,
( V_15 * ) & V_9 , 1 ) ;
}
V_3 ++ ;
F_5 ( 10 ) ;
V_9 = F_8 ( V_9 ) ;
if ( ( V_9 == V_8 ) ||
( V_9 == V_17 ) )
return V_9 ;
}
return V_16 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_18 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < 1000 ; V_25 ++ ) ;
}
static T_1 F_15 ( struct V_1 * V_2 )
{
T_1 V_26 ;
int V_5 ;
T_1 V_20 ;
T_2 V_19 ;
if ( V_2 -> V_27 == 1 ) {
V_5 = F_16 ( V_2 ,
V_28 , ( V_15 * ) & V_19 ) ;
V_19 = F_10 ( V_19 ) ;
} else {
V_19 = 0 ;
V_5 = F_7 ( V_2 ,
V_28 , ( V_15 * ) & V_20 , 1 ) ;
V_19 |= ( V_20 << 16 ) ;
V_19 = F_10 ( V_19 ) ;
}
V_26 = ( T_1 ) V_19 ;
return V_26 ;
}
static T_1 F_17 ( struct V_1 * V_2 )
{
T_1 V_26 ;
int V_5 ;
T_1 V_20 ;
T_2 V_19 ;
if ( V_2 -> V_27 == 1 ) {
V_5 = F_16 ( V_2 ,
V_28 , ( V_15 * ) & V_19 ) ;
V_19 = F_10 ( V_19 ) ;
} else {
if ( V_2 -> V_22 == 2 ) {
V_19 = V_2 -> V_23 [ 2 ] ;
V_20 = V_2 -> V_23 [ 3 ] ;
} else {
V_19 = 0 ;
V_5 = F_7 ( V_2 ,
V_28 ,
( V_15 * ) & V_20 , 1 ) ;
}
V_19 |= ( V_20 << 16 ) ;
V_19 = F_10 ( V_19 ) ;
}
V_26 = ( T_1 ) V_19 ;
return V_26 ;
}
static long F_18 ( struct V_1 * V_2 )
{
T_2 V_29 ;
T_1 V_20 ;
int V_5 ;
if ( V_2 -> V_27 == 1 ) {
V_5 = F_16 ( V_2 ,
V_30 , ( V_15 * ) & V_29 ) ;
V_29 = F_10 ( V_29 ) ;
} else {
V_5 = F_7 ( V_2 ,
V_30 , ( V_15 * ) & V_20 , 0 ) ;
V_29 = V_20 ;
V_5 = F_7 ( V_2 ,
V_30 , ( V_15 * ) & V_20 , 1 ) ;
V_29 |= ( V_20 << 16 ) ;
V_29 = F_10 ( V_29 ) ;
}
return V_29 ;
}
static void F_19 ( struct V_1 * V_2 , long V_31 )
{
T_2 V_19 ;
int V_5 ;
V_19 = F_10 ( V_31 ) ;
V_5 = F_20 ( V_2 , V_30 ,
( V_15 * ) & V_19 ) ;
}
static T_1 F_21 ( struct V_32 * V_33 )
{
T_1 * V_34 = ( T_1 * ) V_33 ;
T_1 V_35 ;
V_35 = ( ( ( ( ( ( V_34 [ 0 ] ^ V_34 [ 1 ] ) ^ V_34 [ 2 ] ) ^ V_34 [ 3 ] ) ^
V_34 [ 4 ] ) ^ V_34 [ 5 ] ) ^ V_34 [ 6 ] ) ;
return V_35 ;
}
static int F_22 ( T_1 * V_36 , T_1 * V_37 , int V_38 , int V_39 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_38 ; V_25 ++ ) {
if ( V_36 [ V_25 ] != V_37 [ V_25 + V_39 ] )
return - V_40 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 V_41 [] , T_1 V_42 )
{
int V_5 ;
T_1 V_43 [ 64 ] ;
int V_25 ;
for ( V_25 = 0 ; V_25 < 10 ; V_25 ++ ) {
V_5 = F_24 ( V_2 , V_42 ,
( V_15 * ) & V_41 [ 0 ] , 64 ) ;
if ( V_5 == 0 ) {
if ( ( V_41 [ 31 ] & 0xfe00 ) == 0xfe00 ) {
V_5 = F_24 ( V_2 ,
V_42 + 12 , ( V_15 * ) & V_41 [ 24 ] ,
64 ) ;
}
V_5 = F_13 ( V_2 , V_42 ,
( V_15 * ) & V_43 [ 0 ] , 64 ) ;
if ( ( V_41 [ 31 ] & 0xfe00 ) == 0xfe00 ) {
if ( F_22 ( V_41 , V_43 , 28 ,
0 ) ) {
F_3 ( L_9 ) ;
F_25 ( 9000 , 11000 ) ;
break;
}
V_5 = F_13 ( V_2 ,
V_42 + 12 ,
( V_15 * ) & V_43 [ 0 ] , 64 ) ;
if ( F_22 ( V_41 , V_43 , 16 ,
24 ) ) {
F_3 ( L_10 ) ;
F_25 ( 9000 , 11000 ) ;
break;
}
} else {
if ( F_22 ( V_41 , V_43 , 32 ,
0 ) ) {
F_3 ( L_11 ) ;
F_25 ( 9000 , 11000 ) ;
break;
}
}
if ( V_5 == 0 )
break;
}
}
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 * * V_44 , V_15 * * V_45 ,
long V_46 )
{
int V_5 = V_12 ;
T_1 V_42 ;
int V_3 , V_25 ;
T_1 V_20 ;
T_1 V_41 [ 64 ] ;
V_42 = ( T_1 ) V_47 ;
V_20 = * ( * V_44 ) ;
( * V_44 ) ++ ;
V_5 = F_11 ( V_2 , V_42 , V_20 , 0 ) ;
V_20 = * ( * V_44 ) ;
( * V_44 ) ++ ;
V_5 = F_11 ( V_2 , V_42 ++ , V_20 , 1 ) ;
* V_45 = * V_45 + 4 ;
V_46 -- ;
V_20 = ( T_1 ) V_46 ;
V_46 = ( V_46 / 16 ) + 1 ;
for (; V_46 > 0 ; V_46 -- ) {
V_3 = 0 ;
for ( V_25 = 0 ; V_25 < 32 ; V_25 ++ ) {
if ( V_20 != 0 ) {
V_41 [ V_25 ++ ] = * ( * V_44 ) ;
( * V_44 ) ++ ;
V_41 [ V_25 ] = * ( * V_44 ) ;
( * V_44 ) ++ ;
* V_45 = * V_45 + 4 ;
V_3 ++ ;
V_20 -- ;
} else {
V_41 [ V_25 ++ ] = 0 ;
V_41 [ V_25 ] = 0 ;
}
}
if ( V_2 -> V_27 == 0 ) {
if ( V_42 >= 0x3F4 )
V_5 = F_24 ( V_2 , V_42 ,
( V_15 * ) & V_41 [ 0 ] , 8 ) ;
else
V_5 = F_24 ( V_2 , V_42 ,
( V_15 * ) & V_41 [ 0 ] , 64 ) ;
} else {
V_5 = F_23 ( V_2 , V_41 ,
V_42 ) ;
if ( V_5 != V_12 ) {
F_3 ( L_12 , V_41 [ 31 ] ) ;
break;
}
}
V_42 = V_42 + V_3 ;
}
return V_5 ;
}
static void F_27 ( struct V_48 * V_48 )
{
}
static int F_28 ( struct V_1 * V_2 , T_1 * * V_44 ,
V_15 * * V_45 , long V_46 )
{
int V_49 = V_12 ;
int V_50 ;
V_50 = V_46 * 4 ;
if ( V_50 && ( ( V_50 % 64 ) == 0 ) )
V_50 += 4 ;
if ( V_50 < 64 )
V_50 = 68 ;
F_29 ( V_2 -> V_51 ) ;
memcpy ( V_2 -> V_52 , * V_45 , V_50 ) ;
F_30 ( V_2 -> V_51 ,
V_2 -> V_53 ,
F_31 ( V_2 -> V_53 ,
V_2 -> V_54 ) ,
V_2 -> V_52 , V_50 , F_27 ,
( void * ) V_2 ) ;
F_32 ( V_2 -> V_51 , V_55 ) ;
* V_44 = * V_44 + ( V_46 << 1 ) ;
* V_45 = * V_45 + ( V_46 << 2 ) ;
return V_49 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 * V_56 ,
T_2 * V_57 )
{
int V_5 = 0 ;
F_3 ( L_13 ) ;
if ( V_2 -> V_22 )
* V_56 = F_12 ( V_2 , V_58 ) ;
else
* V_56 = F_6 ( V_2 , V_58 ) ;
if ( * V_56 == V_58 ) {
F_3 ( L_14 ) ;
F_9 ( V_2 , V_59 ) ;
} else if ( * V_56 == V_16 ) {
V_5 = - V_60 ;
} else {
F_3 ( L_15 ) ;
V_5 = - V_61 ;
}
* V_57 = V_62 ;
return V_5 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 * * V_63 ,
V_15 * * V_64 , const V_15 * V_65 , bool V_66 )
{
long V_46 ;
int V_5 = 0 ;
V_46 = F_18 ( V_2 ) ;
if ( V_46 > V_67 ) {
F_3 ( L_16 ) ;
return V_13 ;
}
if ( ( V_46 * 2 + ( long ) V_64 ) > ( long ) V_65 ) {
F_3 ( L_17 , ( int ) V_46 ) ;
return V_13 ;
}
if ( V_46 & 0x1 )
V_46 ++ ;
V_46 = V_46 / 2 ;
if ( V_66 ) {
V_5 = F_26 ( V_2 , V_63 , V_64 , V_46 ) ;
} else {
F_28 ( V_2 , V_63 , V_64 , V_46 ) ;
if ( V_2 -> V_22 == 0 )
V_2 -> V_22 ++ ;
if ( V_2 -> V_22 == 1 )
F_11 ( V_2 ,
V_47 , 0 , 0 ) ;
}
return V_5 ;
}
int F_35 ( struct V_1 * V_2 , void * V_68 ,
T_2 V_69 )
{
int V_5 = V_12 ;
T_2 V_57 ;
T_1 V_9 ;
struct V_32 * V_70 ;
T_1 V_71 ;
long V_46 ;
T_1 V_72 ;
T_1 V_4 ;
struct V_73 * V_74 ;
struct V_75 * V_76 = NULL ;
long V_77 ;
bool V_78 ;
struct V_79 * V_80 ;
T_1 * V_81 = NULL ;
T_1 * V_63 = NULL ;
V_15 * V_64 = NULL ;
V_15 * V_82 = NULL , * V_83 = NULL ;
int V_84 ;
long V_85 , V_86 = 0 ;
long V_87 = 0 , V_88 = 0 ;
T_2 V_89 ;
T_2 V_90 = 0 ;
T_1 V_42 = 0 ;
V_15 * V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_95 = F_36 ( V_2 -> V_96 ) ;
F_3 ( L_18 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_24 = 0xffff ;
V_57 = V_97 ;
V_74 = (struct V_73 * ) V_68 ;
F_4 ( V_2 , 0x800 , V_98 ) ;
V_63 = ( T_1 * ) ( V_68 + V_74 -> V_99 ) ;
V_64 = ( V_15 * ) ( V_68 + V_74 -> V_99 ) ;
V_82 = ( V_15 * ) ( V_68 + V_74 -> V_100 ) ;
V_85 = V_74 -> V_85 ;
V_86 = V_74 -> V_86 ;
V_78 = false ;
while ( ( V_5 == V_12 ) && ( V_57 != V_101 ) ) {
switch ( V_57 ) {
case V_97 :
V_5 = F_33 ( V_2 , & V_9 ,
& V_57 ) ;
break;
case V_62 :
F_3 ( L_19 ) ;
V_2 -> V_27 = 1 ;
V_9 = F_6 ( V_2 , V_102 ) ;
if ( V_9 == V_102 ) {
V_72 = F_15 ( V_2 ) ;
switch ( V_72 ) {
case V_103 :
F_3 ( L_20 ) ;
F_19 ( V_2 ,
V_85 ) ;
break;
case V_104 :
F_3 ( L_21 ) ;
F_19 ( V_2 ,
V_86 ) ;
break;
case V_105 :
F_3 ( L_22 ) ;
V_63 = ( T_1 * ) ( V_82 ) ;
V_64 = ( V_15 * ) ( V_82 ) ;
V_57 = V_106 ;
V_2 -> V_11 = 1 ;
break;
case V_107 :
V_5 = F_34 ( V_2 ,
& V_63 , & V_64 ,
( const V_15 * ) V_82 ,
true ) ;
break;
default:
F_3
( L_23 ,
V_72 ) ;
V_5 = V_13 ;
break;
}
if ( V_2 -> V_22 )
F_14 ( V_2 ,
V_108 ) ;
else
F_9 ( V_2 ,
V_108 ) ;
} else {
F_3
( L_15 ) ;
V_5 = V_13 ;
}
break;
case V_106 :
V_2 -> V_27 = 0 ;
if ( V_2 -> V_22 )
V_9 =
F_12 ( V_2 ,
V_102 ) ;
else
V_9 =
F_6 ( V_2 , V_102 ) ;
if ( V_9 == V_102 ) {
if ( V_2 -> V_22 )
V_72 =
F_17 ( V_2 ) ;
else
V_72 = F_15 ( V_2 ) ;
switch ( V_72 ) {
case V_109 :
F_3
( L_24 ,
V_90 ) ;
F_19 ( V_2 ,
V_90 ) ;
break;
case V_103 :
F_3
( L_25 ) ;
if ( V_78 ) {
F_3
( L_26 ,
( int ) V_87 ) ;
F_19 ( V_2 ,
V_87 ) ;
} else {
F_3
( L_27 ) ;
V_5 = V_13 ;
break;
}
break;
case V_104 :
F_3
( L_28 ) ;
if ( V_78 ) {
F_3
( L_29 ,
( int ) V_88 ) ;
F_19 ( V_2 ,
V_88 ) ;
} else {
F_3
( L_30 ) ;
V_5 = V_13 ;
break;
}
break;
case V_110 :
V_2 -> V_22 = 3 ;
V_63 =
( T_1 * ) ( V_68 +
V_74 -> V_111 ) ;
V_64 =
( V_15 * ) ( V_68 +
V_74 -> V_111 ) ;
V_57 = V_112 ;
break;
case V_107 :
if ( ! V_78 ) {
F_3
( L_31 ) ;
V_5 = V_13 ;
break;
}
V_5 = F_34 ( V_2 ,
& V_63 , & V_64 ,
( const V_15 * ) V_83 ,
false ) ;
break;
case V_113 :
F_3
( L_32 ) ;
V_46 =
( long ) ( V_95 -> V_114 +
1 ) / 2 ;
F_19 ( V_2 ,
V_46 ) ;
V_80 =
(struct V_79 * ) & ( V_95 ->
V_115 [ 0 ] ) ;
V_81 = ( T_1 * ) & V_80 -> V_81 [ 0 ] ;
V_42 = ( T_1 ) V_47 ;
if ( V_46 & 0x1 )
V_46 ++ ;
V_46 = ( V_46 / 2 ) ;
for (; V_46 > 0 ; V_46 -- ) {
V_89 = * V_81 ++ ;
V_89 |= ( * V_81 ++ << 16 ) ;
V_5 =
F_20
( V_2 , V_42 ++ ,
( V_15 * ) & V_89 ) ;
}
break;
case V_116 :
F_3
( L_33 ) ;
V_46 =
V_74 -> V_117 ;
F_19 ( V_2 ,
V_46 ) ;
V_63 =
( T_1 * ) ( V_68 +
V_74 ->
V_118 ) ;
V_42 = ( T_1 ) V_47 ;
if ( V_46 & 0x1 )
V_46 ++ ;
V_46 = ( V_46 / 2 ) ;
for (; V_46 > 0 ; V_46 -- ) {
V_89 = F_8 ( * V_63 ++ ) ;
V_4 = F_8 ( * V_63 ++ ) ;
V_89 |= ( V_4 << 16 ) ;
V_5 =
F_20
( V_2 , V_42 ++ ,
( V_15 * ) & V_89 ) ;
}
break;
case V_119 :
F_3
( L_34 ) ;
V_78 = false ;
V_77 =
F_18 ( V_2 ) ;
V_76 =
(struct V_75 * ) ( V_68
+
sizeof
( struct
V_73 ) ) ;
for ( V_84 = 0 ;
V_84 < V_74 -> V_120 ;
V_84 ++ ) {
if ( V_76 -> V_121 ==
V_77 ) {
V_78 = true ;
F_3
( L_35 ) ;
V_63 =
( T_1 * ) ( V_68
+
V_76 ->
V_122 ) ;
V_64 =
( V_15 * ) ( V_68 +
V_76 ->
V_122 ) ;
V_83 =
( V_15 * ) ( V_68 +
V_76 ->
V_123 ) ;
V_87 =
V_76 ->
V_87 ;
V_88 =
V_76 ->
V_124 ;
V_90 =
( T_2 ) V_76 ->
V_125 ;
break;
}
V_76 ++ ;
}
if ( ! V_78 ) {
F_3
( L_36 ,
( int ) V_77 ) ;
V_5 = V_13 ;
break;
}
break;
default:
F_3
( L_37 ,
V_72 ) ;
V_5 = V_13 ;
break;
}
if ( V_2 -> V_22 )
F_14 ( V_2 ,
V_108 ) ;
else
F_9 ( V_2 ,
V_108 ) ;
} else {
F_3
( L_15 ) ;
V_5 = V_13 ;
}
break;
case V_112 :
F_3 ( L_38 ) ;
V_57 = V_126 ;
break;
case V_126 :
F_3 ( L_39 ) ;
V_70 = (struct V_32 * ) V_64 ;
if ( V_70 -> V_125 ==
F_21 ( V_70 ) ) {
if ( V_70 -> V_127 !=
0x80 ) {
V_57 = V_128 ;
break;
}
V_71 = F_8 ( V_70 -> V_129 ) ;
V_91 =
F_37 ( ( V_71 +
sizeof( struct V_32 ) ) ,
V_55 ) ;
if ( V_91 ) {
memcpy ( V_91 , ( void * ) V_64 ,
( T_2 ) ( V_71 +
sizeof( struct
V_32 ) ) ) ;
V_93 =
F_37 ( sizeof( struct V_92 ) ,
V_55 ) ;
if ( V_93 ) {
V_93 -> V_130 =
V_91 ;
F_38 ( & V_93 ->
V_131 ,
& V_95 ->
V_132 ) ;
V_64 =
( V_15 * ) ( ( unsigned long )
V_64 +
( T_2 ) ( ( V_71 + 1 ) & 0xFFFFFFFE ) + sizeof( struct V_32 ) ) ;
if ( ( unsigned long ) ( V_64 ) -
( unsigned long ) ( V_68 )
>=
( unsigned long ) V_69 ) {
V_57 = V_101 ;
}
} else {
F_39 ( V_91 ) ;
V_5 = V_13 ;
}
} else {
V_5 = V_13 ;
}
} else {
V_5 = V_13 ;
}
F_3
( L_40 ,
V_57 , V_5 ) ;
break;
case V_128 :
F_3 ( L_41 ) ;
V_57 = V_101 ;
break;
default:
V_5 = V_13 ;
break;
}
if ( V_5 != V_12 )
break;
}
F_3 ( L_42 , V_5 ) ;
F_4 ( V_2 , V_21 ,
V_6 ) ;
return V_5 ;
}
