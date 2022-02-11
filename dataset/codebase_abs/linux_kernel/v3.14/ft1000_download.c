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
return - 1 ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_7 )
{
T_1 V_8 ;
int V_3 ;
int V_5 = 0 ;
V_3 = 0 ;
while ( V_3 < 100 ) {
V_5 = F_4 ( V_2 , V_9 ,
V_6 ) ;
if ( V_2 -> V_10 ) {
F_3 ( L_5 ,
V_2 -> V_10 ) ;
V_2 -> V_10 = 0 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 != 0 ) {
F_3 ( L_6 ) ;
break;
}
V_5 = F_4 ( V_2 ,
V_9 ,
V_6 ) ;
}
V_5 = F_7 ( V_2 ,
V_11 , ( V_12 * ) & V_8 , 1 ) ;
V_8 = F_8 ( V_8 ) ;
if ( V_5 )
return V_13 ;
if ( ( V_8 == V_7 ) ||
( V_8 == V_14 ) ) {
return V_8 ;
} else {
V_3 ++ ;
F_5 ( 10 ) ;
}
}
return V_13 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_15 )
{
T_2 V_16 ;
T_1 V_17 ;
int V_5 ;
V_16 = ( T_2 ) V_15 ;
V_16 = F_10 ( V_16 ) ;
V_17 = ( T_1 ) ( V_16 & 0xffff ) ;
V_5 = F_11 ( V_2 , V_11 ,
V_17 , 0 ) ;
V_17 = ( T_1 ) ( V_16 >> 16 ) ;
V_5 = F_11 ( V_2 , V_11 ,
V_17 , 1 ) ;
V_5 = F_4 ( V_2 , V_18 ,
V_6 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_1 V_7 )
{
T_1 V_8 ;
int V_3 ;
T_1 V_4 ;
int V_5 = 0 ;
V_3 = 0 ;
V_8 = 0 ;
while ( V_3 < 100 ) {
if ( V_2 -> V_19 == 2 ) {
V_5 = F_13 ( V_2 , 0 ,
( V_12 * ) & ( V_2 -> V_20 [ 0 ] ) , 64 ) ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
F_3 ( L_7 , V_4 ,
V_2 -> V_20 [ V_4 ] ) ;
}
V_5 = F_7 ( V_2 ,
V_11 ,
( V_12 * ) & V_8 , 1 ) ;
F_3 ( L_8 ,
V_8 ) ;
if ( V_2 -> V_21 == V_2 -> V_20 [ 6 ] ) {
V_8 = 0 ;
} else {
V_8 = V_2 -> V_20 [ 1 ] ;
V_2 -> V_21 =
V_2 -> V_20 [ 6 ] ;
}
} else {
V_5 = F_7 ( V_2 ,
V_11 ,
( V_12 * ) & V_8 , 1 ) ;
}
V_3 ++ ;
F_5 ( 10 ) ;
V_8 = F_8 ( V_8 ) ;
if ( ( V_8 == V_7 ) ||
( V_8 == V_14 ) )
return V_8 ;
}
return V_13 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_15 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < 1000 ; V_22 ++ )
;
}
static T_1 F_15 ( struct V_1 * V_2 )
{
T_1 V_23 ;
int V_5 ;
T_1 V_17 ;
T_2 V_16 ;
if ( V_2 -> V_24 == 1 ) {
V_5 = F_16 ( V_2 ,
V_25 , ( V_12 * ) & V_16 ) ;
V_16 = F_10 ( V_16 ) ;
} else {
V_16 = 0 ;
V_5 = F_7 ( V_2 ,
V_25 , ( V_12 * ) & V_17 , 1 ) ;
V_16 |= ( V_17 << 16 ) ;
V_16 = F_10 ( V_16 ) ;
}
V_23 = ( T_1 ) V_16 ;
return V_23 ;
}
static T_1 F_17 ( struct V_1 * V_2 )
{
T_1 V_23 ;
int V_5 ;
T_1 V_17 ;
T_2 V_16 ;
if ( V_2 -> V_24 == 1 ) {
V_5 = F_16 ( V_2 ,
V_25 , ( V_12 * ) & V_16 ) ;
V_16 = F_10 ( V_16 ) ;
} else {
if ( V_2 -> V_19 == 2 ) {
V_16 = V_2 -> V_20 [ 2 ] ;
V_17 = V_2 -> V_20 [ 3 ] ;
} else {
V_16 = 0 ;
V_5 = F_7 ( V_2 ,
V_25 ,
( V_12 * ) & V_17 , 1 ) ;
}
V_16 |= ( V_17 << 16 ) ;
V_16 = F_10 ( V_16 ) ;
}
V_23 = ( T_1 ) V_16 ;
return V_23 ;
}
static long F_18 ( struct V_1 * V_2 )
{
T_2 V_26 ;
T_1 V_17 ;
int V_5 ;
if ( V_2 -> V_24 == 1 ) {
V_5 = F_16 ( V_2 ,
V_27 , ( V_12 * ) & V_26 ) ;
V_26 = F_10 ( V_26 ) ;
} else {
V_5 = F_7 ( V_2 ,
V_27 , ( V_12 * ) & V_17 , 0 ) ;
V_26 = V_17 ;
V_5 = F_7 ( V_2 ,
V_27 , ( V_12 * ) & V_17 , 1 ) ;
V_26 |= ( V_17 << 16 ) ;
V_26 = F_10 ( V_26 ) ;
}
return V_26 ;
}
static void F_19 ( struct V_1 * V_2 , long V_28 )
{
T_2 V_16 ;
int V_5 ;
V_16 = F_10 ( V_28 ) ;
V_5 = F_20 ( V_2 , V_27 ,
( V_12 * ) & V_16 ) ;
}
static T_1 F_21 ( struct V_29 * V_30 )
{
T_1 * V_31 = ( T_1 * ) V_30 ;
T_1 V_32 ;
V_32 = ( ( ( ( ( ( V_31 [ 0 ] ^ V_31 [ 1 ] ) ^ V_31 [ 2 ] ) ^ V_31 [ 3 ] ) ^
V_31 [ 4 ] ) ^ V_31 [ 5 ] ) ^ V_31 [ 6 ] ) ;
return V_32 ;
}
static int F_22 ( T_1 * V_33 , T_1 * V_34 , int V_35 , int V_36 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_35 ; V_22 ++ ) {
if ( V_33 [ V_22 ] != V_34 [ V_22 + V_36 ] )
return - V_37 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 V_38 [] , T_1 V_39 )
{
int V_5 ;
T_1 V_40 [ 64 ] ;
int V_22 ;
for ( V_22 = 0 ; V_22 < 10 ; V_22 ++ ) {
V_5 = F_24 ( V_2 , V_39 ,
( V_12 * ) & V_38 [ 0 ] , 64 ) ;
if ( V_5 == 0 ) {
if ( ( V_38 [ 31 ] & 0xfe00 ) == 0xfe00 ) {
V_5 = F_24 ( V_2 ,
V_39 + 12 , ( V_12 * ) & V_38 [ 24 ] ,
64 ) ;
}
V_5 = F_13 ( V_2 , V_39 ,
( V_12 * ) & V_40 [ 0 ] , 64 ) ;
if ( ( V_38 [ 31 ] & 0xfe00 ) == 0xfe00 ) {
if ( F_22 ( V_38 , V_40 , 28 ,
0 ) ) {
F_3 ( L_9 ) ;
F_25 ( 9000 , 11000 ) ;
break;
}
V_5 = F_13 ( V_2 ,
V_39 + 12 ,
( V_12 * ) & V_40 [ 0 ] , 64 ) ;
if ( F_22 ( V_38 , V_40 , 16 ,
24 ) ) {
F_3 ( L_10 ) ;
F_25 ( 9000 , 11000 ) ;
break;
}
} else {
if ( F_22 ( V_38 , V_40 , 32 ,
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
static int F_26 ( struct V_1 * V_2 , T_1 * * V_41 , V_12 * * V_42 ,
long V_43 )
{
int V_5 = 0 ;
T_1 V_39 ;
int V_3 , V_22 ;
T_1 V_17 ;
T_1 V_38 [ 64 ] ;
V_39 = ( T_1 ) V_44 ;
V_17 = * ( * V_41 ) ;
( * V_41 ) ++ ;
V_5 = F_11 ( V_2 , V_39 , V_17 , 0 ) ;
V_17 = * ( * V_41 ) ;
( * V_41 ) ++ ;
V_5 = F_11 ( V_2 , V_39 ++ , V_17 , 1 ) ;
* V_42 = * V_42 + 4 ;
V_43 -- ;
V_17 = ( T_1 ) V_43 ;
V_43 = ( V_43 / 16 ) + 1 ;
for (; V_43 > 0 ; V_43 -- ) {
V_3 = 0 ;
for ( V_22 = 0 ; V_22 < 32 ; V_22 ++ ) {
if ( V_17 != 0 ) {
V_38 [ V_22 ++ ] = * ( * V_41 ) ;
( * V_41 ) ++ ;
V_38 [ V_22 ] = * ( * V_41 ) ;
( * V_41 ) ++ ;
* V_42 = * V_42 + 4 ;
V_3 ++ ;
V_17 -- ;
} else {
V_38 [ V_22 ++ ] = 0 ;
V_38 [ V_22 ] = 0 ;
}
}
if ( V_2 -> V_24 == 0 ) {
if ( V_39 >= 0x3F4 )
V_5 = F_24 ( V_2 , V_39 ,
( V_12 * ) & V_38 [ 0 ] , 8 ) ;
else
V_5 = F_24 ( V_2 , V_39 ,
( V_12 * ) & V_38 [ 0 ] , 64 ) ;
} else {
V_5 = F_23 ( V_2 , V_38 ,
V_39 ) ;
if ( V_5 != 0 ) {
F_3 ( L_12 , V_38 [ 31 ] ) ;
break;
}
}
V_39 = V_39 + V_3 ;
}
return V_5 ;
}
static void F_27 ( struct V_45 * V_45 )
{
}
static int F_28 ( struct V_1 * V_2 , T_1 * * V_41 ,
V_12 * * V_42 , long V_43 )
{
int V_46 = 0 ;
int V_47 ;
V_47 = V_43 * 4 ;
if ( V_47 && ( ( V_47 % 64 ) == 0 ) )
V_47 += 4 ;
if ( V_47 < 64 )
V_47 = 68 ;
F_29 ( V_2 -> V_48 ) ;
memcpy ( V_2 -> V_49 , * V_42 , V_47 ) ;
F_30 ( V_2 -> V_48 ,
V_2 -> V_50 ,
F_31 ( V_2 -> V_50 ,
V_2 -> V_51 ) ,
V_2 -> V_49 , V_47 , F_27 ,
( void * ) V_2 ) ;
F_32 ( V_2 -> V_48 , V_52 ) ;
* V_41 = * V_41 + ( V_43 << 1 ) ;
* V_42 = * V_42 + ( V_43 << 2 ) ;
return V_46 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 * V_53 ,
T_2 * V_54 )
{
int V_5 = 0 ;
F_3 ( L_13 ) ;
if ( V_2 -> V_19 )
* V_53 = F_12 ( V_2 , V_55 ) ;
else
* V_53 = F_6 ( V_2 , V_55 ) ;
if ( * V_53 == V_55 ) {
F_3 ( L_14 ) ;
F_9 ( V_2 , V_56 ) ;
} else if ( * V_53 == V_13 ) {
V_5 = - V_57 ;
} else {
F_3 ( L_15 ) ;
V_5 = - V_58 ;
}
* V_54 = V_59 ;
return V_5 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 * * V_60 ,
V_12 * * V_61 , const V_12 * V_62 , bool V_63 )
{
long V_43 ;
int V_5 = 0 ;
V_43 = F_18 ( V_2 ) ;
if ( V_43 > V_64 ) {
F_3 ( L_16 ) ;
return - 1 ;
}
if ( ( V_43 * 2 + ( long ) V_61 ) > ( long ) V_62 ) {
F_3 ( L_17 , ( int ) V_43 ) ;
return - 1 ;
}
if ( V_43 & 0x1 )
V_43 ++ ;
V_43 = V_43 / 2 ;
if ( V_63 ) {
V_5 = F_26 ( V_2 , V_60 , V_61 , V_43 ) ;
} else {
V_5 = F_28 ( V_2 , V_60 , V_61 , V_43 ) ;
if ( V_2 -> V_19 == 0 )
V_2 -> V_19 ++ ;
if ( V_2 -> V_19 == 1 )
V_5 |= F_11 ( V_2 ,
V_44 , 0 , 0 ) ;
}
return V_5 ;
}
int F_35 ( struct V_1 * V_2 , void * V_65 ,
T_2 V_66 )
{
int V_5 = 0 ;
T_2 V_54 ;
T_1 V_8 ;
struct V_29 * V_67 ;
T_1 V_68 ;
long V_43 ;
T_1 V_69 ;
T_1 V_4 ;
struct V_70 * V_71 ;
struct V_72 * V_73 = NULL ;
long V_74 ;
bool V_75 ;
struct V_76 * V_77 ;
T_1 * V_78 = NULL ;
T_1 * V_60 = NULL ;
V_12 * V_61 = NULL ;
V_12 * V_79 = NULL , * V_80 = NULL ;
int V_81 ;
long V_82 , V_83 = 0 ;
long V_84 = 0 , V_85 = 0 ;
T_2 V_86 ;
T_2 V_87 = 0 ;
T_1 V_39 = 0 ;
V_12 * V_88 ;
struct V_89 * V_90 ;
struct V_91 * V_92 = F_36 ( V_2 -> V_93 ) ;
F_3 ( L_18 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_21 = 0xffff ;
V_54 = V_94 ;
V_71 = (struct V_70 * ) V_65 ;
F_4 ( V_2 , 0x800 , V_95 ) ;
V_60 = ( T_1 * ) ( V_65 + V_71 -> V_96 ) ;
V_61 = ( V_12 * ) ( V_65 + V_71 -> V_96 ) ;
V_79 = ( V_12 * ) ( V_65 + V_71 -> V_97 ) ;
V_82 = V_71 -> V_82 ;
V_83 = V_71 -> V_83 ;
V_75 = false ;
while ( ( V_5 == 0 ) && ( V_54 != V_98 ) ) {
switch ( V_54 ) {
case V_94 :
V_5 = F_33 ( V_2 , & V_8 ,
& V_54 ) ;
break;
case V_59 :
F_3 ( L_19 ) ;
V_2 -> V_24 = 1 ;
V_8 = F_6 ( V_2 , V_99 ) ;
if ( V_8 == V_99 ) {
V_69 = F_15 ( V_2 ) ;
switch ( V_69 ) {
case V_100 :
F_3 ( L_20 ) ;
F_19 ( V_2 ,
V_82 ) ;
break;
case V_101 :
F_3 ( L_21 ) ;
F_19 ( V_2 ,
V_83 ) ;
break;
case V_102 :
F_3 ( L_22 ) ;
V_60 = ( T_1 * ) ( V_79 ) ;
V_61 = ( V_12 * ) ( V_79 ) ;
V_54 = V_103 ;
V_2 -> V_10 = 1 ;
break;
case V_104 :
V_5 = F_34 ( V_2 ,
& V_60 , & V_61 ,
( const V_12 * ) V_79 ,
true ) ;
break;
default:
F_3
( L_23 ,
V_69 ) ;
V_5 = - 1 ;
break;
}
if ( V_2 -> V_19 )
F_14 ( V_2 ,
V_105 ) ;
else
F_9 ( V_2 ,
V_105 ) ;
} else {
F_3
( L_15 ) ;
V_5 = - 1 ;
}
break;
case V_103 :
V_2 -> V_24 = 0 ;
if ( V_2 -> V_19 )
V_8 =
F_12 ( V_2 ,
V_99 ) ;
else
V_8 =
F_6 ( V_2 , V_99 ) ;
if ( V_8 == V_99 ) {
if ( V_2 -> V_19 )
V_69 =
F_17 ( V_2 ) ;
else
V_69 = F_15 ( V_2 ) ;
switch ( V_69 ) {
case V_106 :
F_3
( L_24 ,
V_87 ) ;
F_19 ( V_2 ,
V_87 ) ;
break;
case V_100 :
F_3
( L_25 ) ;
if ( V_75 ) {
F_3
( L_26 ,
( int ) V_84 ) ;
F_19 ( V_2 ,
V_84 ) ;
} else {
F_3
( L_27 ) ;
V_5 = - 1 ;
break;
}
break;
case V_101 :
F_3
( L_28 ) ;
if ( V_75 ) {
F_3
( L_29 ,
( int ) V_85 ) ;
F_19 ( V_2 ,
V_85 ) ;
} else {
F_3
( L_30 ) ;
V_5 = - 1 ;
break;
}
break;
case V_107 :
V_2 -> V_19 = 3 ;
V_60 =
( T_1 * ) ( V_65 +
V_71 -> V_108 ) ;
V_61 =
( V_12 * ) ( V_65 +
V_71 -> V_108 ) ;
V_54 = V_109 ;
break;
case V_104 :
if ( ! V_75 ) {
F_3
( L_31 ) ;
V_5 = - 1 ;
break;
}
V_5 = F_34 ( V_2 ,
& V_60 , & V_61 ,
( const V_12 * ) V_80 ,
false ) ;
break;
case V_110 :
F_3
( L_32 ) ;
V_43 =
( long ) ( V_92 -> V_111 +
1 ) / 2 ;
F_19 ( V_2 ,
V_43 ) ;
V_77 =
(struct V_76 * ) & ( V_92 ->
V_112 [ 0 ] ) ;
V_78 = ( T_1 * ) & V_77 -> V_78 [ 0 ] ;
V_39 = ( T_1 ) V_44 ;
if ( V_43 & 0x1 )
V_43 ++ ;
V_43 = ( V_43 / 2 ) ;
for (; V_43 > 0 ; V_43 -- ) {
V_86 = * V_78 ++ ;
V_86 |= ( * V_78 ++ << 16 ) ;
V_5 =
F_20
( V_2 , V_39 ++ ,
( V_12 * ) & V_86 ) ;
}
break;
case V_113 :
F_3
( L_33 ) ;
V_43 =
V_71 -> V_114 ;
F_19 ( V_2 ,
V_43 ) ;
V_60 =
( T_1 * ) ( V_65 +
V_71 ->
V_115 ) ;
V_39 = ( T_1 ) V_44 ;
if ( V_43 & 0x1 )
V_43 ++ ;
V_43 = ( V_43 / 2 ) ;
for (; V_43 > 0 ; V_43 -- ) {
V_86 = F_8 ( * V_60 ++ ) ;
V_4 = F_8 ( * V_60 ++ ) ;
V_86 |= ( V_4 << 16 ) ;
V_5 =
F_20
( V_2 , V_39 ++ ,
( V_12 * ) & V_86 ) ;
}
break;
case V_116 :
F_3
( L_34 ) ;
V_75 = false ;
V_74 =
F_18 ( V_2 ) ;
V_73 =
(struct V_72 * ) ( V_65
+
sizeof
( struct
V_70 ) ) ;
for ( V_81 = 0 ;
V_81 < V_71 -> V_117 ;
V_81 ++ ) {
if ( V_73 -> V_118 ==
V_74 ) {
V_75 = true ;
F_3
( L_35 ) ;
V_60 =
( T_1 * ) ( V_65
+
V_73 ->
V_119 ) ;
V_61 =
( V_12 * ) ( V_65 +
V_73 ->
V_119 ) ;
V_80 =
( V_12 * ) ( V_65 +
V_73 ->
V_120 ) ;
V_84 =
V_73 ->
V_84 ;
V_85 =
V_73 ->
V_121 ;
V_87 =
( T_2 ) V_73 ->
V_122 ;
break;
}
V_73 ++ ;
}
if ( ! V_75 ) {
F_3
( L_36 ,
( int ) V_74 ) ;
V_5 = - 1 ;
break;
}
break;
default:
F_3
( L_37 ,
V_69 ) ;
V_5 = - 1 ;
break;
}
if ( V_2 -> V_19 )
F_14 ( V_2 ,
V_105 ) ;
else
F_9 ( V_2 ,
V_105 ) ;
} else {
F_3
( L_15 ) ;
V_5 = - 1 ;
}
break;
case V_109 :
F_3 ( L_38 ) ;
V_54 = V_123 ;
break;
case V_123 :
F_3 ( L_39 ) ;
V_67 = (struct V_29 * ) V_61 ;
if ( V_67 -> V_122 ==
F_21 ( V_67 ) ) {
if ( V_67 -> V_124 !=
0x80 ) {
V_54 = V_125 ;
break;
}
V_68 = F_8 ( V_67 -> V_126 ) ;
V_88 =
F_37 ( ( V_68 +
sizeof( struct V_29 ) ) ,
V_52 ) ;
if ( V_88 ) {
memcpy ( V_88 , ( void * ) V_61 ,
( T_2 ) ( V_68 +
sizeof( struct
V_29 ) ) ) ;
V_90 =
F_37 ( sizeof( struct V_89 ) ,
V_52 ) ;
if ( V_90 ) {
V_90 -> V_127 =
V_88 ;
F_38 ( & V_90 ->
V_128 ,
& V_92 ->
V_129 ) ;
V_61 =
( V_12 * ) ( ( unsigned long )
V_61 +
( T_2 ) ( ( V_68 + 1 ) & 0xFFFFFFFE ) + sizeof( struct V_29 ) ) ;
if ( ( unsigned long ) ( V_61 ) -
( unsigned long ) ( V_65 )
>=
( unsigned long ) V_66 ) {
V_54 = V_98 ;
}
} else {
F_39 ( V_88 ) ;
V_5 = - 1 ;
}
} else {
V_5 = - 1 ;
}
} else {
V_5 = - 1 ;
}
F_3
( L_40 ,
V_54 , V_5 ) ;
break;
case V_125 :
F_3 ( L_41 ) ;
V_54 = V_98 ;
break;
default:
V_5 = - 1 ;
break;
}
if ( V_5 != 0 )
break;
}
F_3 ( L_42 , V_5 ) ;
F_4 ( V_2 , V_18 ,
V_6 ) ;
return V_5 ;
}
