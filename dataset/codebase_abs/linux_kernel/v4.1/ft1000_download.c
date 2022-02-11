static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
int V_5 ;
V_3 = 0 ;
while ( V_3 < 10 ) {
V_5 = F_2 ( V_2 , & V_4 ,
V_6 ) ;
F_3 ( L_1 , V_4 ) ;
if ( V_4 & 0x0080 ) {
F_3 ( L_2 ) ;
V_5 = F_4 ( V_2 , 0x0080 ,
V_6 ) ;
V_5 = F_4 ( V_2 , 0x0100 ,
V_6 ) ;
V_5 = F_4 ( V_2 , 0x8000 ,
V_6 ) ;
break;
}
V_3 ++ ;
F_5 ( 10 ) ;
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
F_3 ( L_5 , V_2 -> V_10 ) ;
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
}
V_3 ++ ;
F_5 ( 10 ) ;
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
( V_12 * ) & V_2 -> V_20 [ 0 ] , 64 ) ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
F_3 ( L_7 ,
V_4 , V_2 -> V_20 [ V_4 ] ) ;
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
V_32 = ( ( ( ( ( V_31 [ 0 ] ^ V_31 [ 1 ] ) ^ V_31 [ 2 ] ) ^ V_31 [ 3 ] ) ^
V_31 [ 4 ] ) ^ V_31 [ 5 ] ) ^ V_31 [ 6 ] ;
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
F_3 ( L_12 ,
V_38 [ 31 ] ) ;
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
int V_46 ;
V_46 = V_43 * 4 ;
if ( V_46 && ( ( V_46 % 64 ) == 0 ) )
V_46 += 4 ;
if ( V_46 < 64 )
V_46 = 68 ;
F_29 ( V_2 -> V_47 ) ;
memcpy ( V_2 -> V_48 , * V_42 , V_46 ) ;
F_30 ( V_2 -> V_47 ,
V_2 -> V_49 ,
F_31 ( V_2 -> V_49 ,
V_2 -> V_50 ) ,
V_2 -> V_48 , V_46 , F_27 ,
V_2 ) ;
F_32 ( V_2 -> V_47 , V_51 ) ;
* V_41 = * V_41 + ( V_43 << 1 ) ;
* V_42 = * V_42 + ( V_43 << 2 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 * V_52 ,
T_2 * V_53 )
{
int V_5 = 0 ;
if ( V_2 -> V_19 )
* V_52 = F_12 ( V_2 , V_54 ) ;
else
* V_52 = F_6 ( V_2 , V_54 ) ;
if ( * V_52 == V_54 ) {
F_3 ( L_13 ) ;
F_9 ( V_2 , V_55 ) ;
} else if ( * V_52 == V_13 ) {
V_5 = - V_56 ;
} else {
F_3 ( L_14 ) ;
V_5 = - V_57 ;
}
* V_53 = V_58 ;
return V_5 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 * * V_59 ,
V_12 * * V_60 , const V_12 * V_61 , bool V_62 )
{
long V_43 ;
int V_5 = 0 ;
V_43 = F_18 ( V_2 ) ;
if ( V_43 > V_63 ) {
F_3 ( L_15 ) ;
return - 1 ;
}
if ( ( V_43 * 2 + ( long ) V_60 ) > ( long ) V_61 ) {
F_3 ( L_16 ,
( int ) V_43 ) ;
return - 1 ;
}
if ( V_43 & 0x1 )
V_43 ++ ;
V_43 = V_43 / 2 ;
if ( V_62 ) {
V_5 = F_26 ( V_2 , V_59 , V_60 , V_43 ) ;
} else {
V_5 = F_28 ( V_2 , V_59 , V_60 , V_43 ) ;
if ( V_2 -> V_19 == 0 )
V_2 -> V_19 ++ ;
if ( V_2 -> V_19 == 1 )
V_5 |= F_11 ( V_2 ,
V_44 , 0 , 0 ) ;
}
return V_5 ;
}
int F_35 ( struct V_1 * V_2 , void * V_64 ,
T_2 V_65 )
{
int V_5 = 0 ;
T_2 V_53 ;
T_1 V_8 ;
struct V_29 * V_66 ;
T_1 V_67 ;
long V_43 ;
T_1 V_68 ;
T_1 V_4 ;
struct V_69 * V_70 ;
struct V_71 * V_72 = NULL ;
long V_73 ;
bool V_74 ;
struct V_75 * V_76 ;
T_1 * V_77 = NULL ;
T_1 * V_59 = NULL ;
V_12 * V_60 = NULL ;
V_12 * V_78 = NULL , * V_79 = NULL ;
int V_80 ;
long V_81 , V_82 = 0 ;
long V_83 = 0 , V_84 = 0 ;
T_2 V_85 ;
T_2 V_86 = 0 ;
T_1 V_39 = 0 ;
V_12 * V_87 ;
struct V_88 * V_89 ;
struct V_90 * V_91 = F_36 ( V_2 -> V_92 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_21 = 0xffff ;
V_53 = V_93 ;
V_70 = V_64 ;
F_4 ( V_2 , 0x800 , V_94 ) ;
V_59 = ( T_1 * ) ( V_64 + V_70 -> V_95 ) ;
V_60 = ( V_12 * ) ( V_64 + V_70 -> V_95 ) ;
V_78 = ( V_12 * ) ( V_64 + V_70 -> V_96 ) ;
V_81 = V_70 -> V_81 ;
V_82 = V_70 -> V_82 ;
V_74 = false ;
while ( ( V_5 == 0 ) && ( V_53 != V_97 ) ) {
switch ( V_53 ) {
case V_93 :
V_5 = F_33 ( V_2 , & V_8 ,
& V_53 ) ;
break;
case V_58 :
F_3 ( L_17 ) ;
V_2 -> V_24 = 1 ;
V_8 = F_6 ( V_2 , V_98 ) ;
if ( V_8 == V_98 ) {
V_68 = F_15 ( V_2 ) ;
switch ( V_68 ) {
case V_99 :
F_3 ( L_18 ) ;
F_19 ( V_2 ,
V_81 ) ;
break;
case V_100 :
F_3 ( L_19 ) ;
F_19 ( V_2 ,
V_82 ) ;
break;
case V_101 :
F_3 ( L_20 ) ;
V_59 = ( T_1 * ) ( V_78 ) ;
V_60 = ( V_12 * ) ( V_78 ) ;
V_53 = V_102 ;
V_2 -> V_10 = 1 ;
break;
case V_103 :
V_5 = F_34 ( V_2 ,
& V_59 , & V_60 ,
V_78 ,
true ) ;
break;
default:
F_3 ( L_21 ,
V_68 ) ;
V_5 = - 1 ;
break;
}
if ( V_2 -> V_19 )
F_14 ( V_2 ,
V_104 ) ;
else
F_9 ( V_2 ,
V_104 ) ;
} else {
F_3 ( L_14 ) ;
V_5 = - 1 ;
}
break;
case V_102 :
V_2 -> V_24 = 0 ;
if ( V_2 -> V_19 )
V_8 =
F_12 ( V_2 ,
V_98 ) ;
else
V_8 =
F_6 ( V_2 , V_98 ) ;
if ( V_8 == V_98 ) {
if ( V_2 -> V_19 )
V_68 =
F_17 ( V_2 ) ;
else
V_68 = F_15 ( V_2 ) ;
switch ( V_68 ) {
case V_105 :
F_3 ( L_22 ,
V_86 ) ;
F_19 ( V_2 ,
V_86 ) ;
break;
case V_99 :
F_3 ( L_18 ) ;
if ( V_74 ) {
F_3 ( L_23 ,
( int ) V_83 ) ;
F_19 ( V_2 ,
V_83 ) ;
} else {
F_3 ( L_24 ) ;
V_5 = - 1 ;
break;
}
break;
case V_100 :
F_3 ( L_19 ) ;
if ( V_74 ) {
F_3 ( L_25 ,
( int ) V_84 ) ;
F_19 ( V_2 ,
V_84 ) ;
} else {
F_3 ( L_26 ) ;
V_5 = - 1 ;
break;
}
break;
case V_106 :
V_2 -> V_19 = 3 ;
V_59 =
( T_1 * ) ( V_64 +
V_70 -> V_107 ) ;
V_60 =
( V_12 * ) ( V_64 +
V_70 -> V_107 ) ;
V_53 = V_108 ;
break;
case V_103 :
if ( ! V_74 ) {
F_3 ( L_27 ) ;
V_5 = - 1 ;
break;
}
V_5 = F_34 ( V_2 ,
& V_59 , & V_60 ,
V_79 ,
false ) ;
break;
case V_109 :
F_3 ( L_28 ) ;
V_43 =
( long ) ( V_91 -> V_110 +
1 ) / 2 ;
F_19 ( V_2 ,
V_43 ) ;
V_76 =
(struct V_75 * ) & ( V_91 ->
V_111 [ 0 ] ) ;
V_77 = ( T_1 * ) & V_76 -> V_77 [ 0 ] ;
V_39 = ( T_1 ) V_44 ;
if ( V_43 & 0x1 )
V_43 ++ ;
V_43 = V_43 / 2 ;
for (; V_43 > 0 ; V_43 -- ) {
V_85 = * V_77 ++ ;
V_85 |= ( * V_77 ++ << 16 ) ;
V_5 =
F_20
( V_2 , V_39 ++ ,
( V_12 * ) & V_85 ) ;
}
break;
case V_112 :
F_3 ( L_29 ) ;
V_43 =
V_70 -> V_113 ;
F_19 ( V_2 ,
V_43 ) ;
V_59 =
( T_1 * ) ( V_64 +
V_70 ->
V_114 ) ;
V_39 = ( T_1 ) V_44 ;
if ( V_43 & 0x1 )
V_43 ++ ;
V_43 = V_43 / 2 ;
for (; V_43 > 0 ; V_43 -- ) {
V_85 = F_8 ( * V_59 ++ ) ;
V_4 = F_8 ( * V_59 ++ ) ;
V_85 |= ( V_4 << 16 ) ;
V_5 =
F_20
( V_2 , V_39 ++ ,
( V_12 * ) & V_85 ) ;
}
break;
case V_115 :
F_3 ( L_30 ) ;
V_74 = false ;
V_73 =
F_18 ( V_2 ) ;
V_72 =
(struct V_71 * ) ( V_64
+
sizeof
( struct
V_69 ) ) ;
for ( V_80 = 0 ;
V_80 < V_70 -> V_116 ;
V_80 ++ ) {
if ( V_72 -> V_117 ==
V_73 ) {
V_74 = true ;
F_3 ( L_31 ) ;
V_59 =
( T_1 * ) ( V_64
+
V_72 ->
V_118 ) ;
V_60 =
( V_12 * ) ( V_64 +
V_72 ->
V_118 ) ;
V_79 =
( V_12 * ) ( V_64 +
V_72 ->
V_119 ) ;
V_83 =
V_72 ->
V_83 ;
V_84 =
V_72 ->
V_120 ;
V_86 =
( T_2 ) V_72 ->
V_121 ;
break;
}
V_72 ++ ;
}
if ( ! V_74 ) {
F_3 ( L_32 ,
( int ) V_73 ) ;
V_5 = - 1 ;
break;
}
break;
default:
F_3 ( L_33 ,
V_68 ) ;
V_5 = - 1 ;
break;
}
if ( V_2 -> V_19 )
F_14 ( V_2 ,
V_104 ) ;
else
F_9 ( V_2 ,
V_104 ) ;
} else {
F_3 ( L_14 ) ;
V_5 = - 1 ;
}
break;
case V_108 :
F_3 ( L_34 ) ;
V_53 = V_122 ;
break;
case V_122 :
F_3 ( L_35 ) ;
V_66 = (struct V_29 * ) V_60 ;
if ( V_66 -> V_121 ==
F_21 ( V_66 ) ) {
if ( V_66 -> V_123 !=
0x80 ) {
V_53 = V_124 ;
break;
}
V_67 = F_8 ( V_66 -> V_125 ) ;
V_87 =
F_37 ( V_67 +
sizeof( struct V_29 ) ,
V_51 ) ;
if ( V_87 ) {
memcpy ( V_87 , V_60 ,
( T_2 ) ( V_67 +
sizeof( struct
V_29 ) ) ) ;
V_89 =
F_37 ( sizeof( struct V_88 ) ,
V_51 ) ;
if ( V_89 ) {
V_89 -> V_126 =
V_87 ;
F_38 ( & V_89 ->
V_127 ,
& V_91 ->
V_128 ) ;
V_60 =
( V_12 * ) ( ( unsigned long )
V_60 +
( T_2 ) ( ( V_67 + 1 ) & 0xFFFFFFFE ) + sizeof( struct V_29 ) ) ;
if ( ( unsigned long ) ( V_60 ) -
( unsigned long ) ( V_64 )
>=
( unsigned long ) V_65 ) {
V_53 = V_97 ;
}
} else {
F_39 ( V_87 ) ;
V_5 = - 1 ;
}
} else {
V_5 = - 1 ;
}
} else {
V_5 = - 1 ;
}
F_3 ( L_36 ,
V_53 , V_5 ) ;
break;
case V_124 :
F_3 ( L_37 ) ;
V_53 = V_97 ;
break;
default:
V_5 = - 1 ;
break;
}
if ( V_5 != 0 )
break;
}
F_3 ( L_38 , V_5 ) ;
F_4 ( V_2 , V_18 ,
V_6 ) ;
return V_5 ;
}
