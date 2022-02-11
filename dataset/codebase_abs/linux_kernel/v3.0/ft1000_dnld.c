void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( V_4 ) F_2 ( V_2 ) ;
unsigned long V_5 ;
T_2 V_6 ;
T_3 V_7 ;
T_3 V_8 ;
T_4 V_9 ;
F_3 ( 0 , L_1 ) ;
V_6 = ( T_2 ) V_10 ;
V_7 = sizeof( V_10 ) ;
if ( V_7 & 0x0003 ) {
V_7 += 4 ;
}
F_4 ( & V_3 -> V_11 , V_5 ) ;
F_5 ( V_2 , V_12 , V_13 ) ;
for ( V_8 = 0 ; V_8 < ( V_7 >> 2 ) ; V_8 ++ ) {
V_9 = * V_6 ++ ;
F_6 ( V_9 , V_2 -> V_14 + V_15 ) ;
}
F_7 ( & V_3 -> V_11 , V_5 ) ;
}
T_5 F_8 ( struct V_1 * V_2 , T_5 V_16 )
{
T_1 * V_3 = ( V_4 ) F_2 ( V_2 ) ;
T_5 V_17 ;
T_4 V_18 ;
int V_19 ;
V_19 = 0 ;
while ( V_19 < V_20 ) {
if ( V_3 -> V_21 == V_22 ) {
F_5 ( V_2 , V_12 ,
V_23 ) ;
V_17 = F_9 ( V_2 , V_24 ) ;
} else {
V_18 =
F_10 ( F_11
( V_2 , V_25 ) ) ;
V_17 = ( T_5 ) V_18 ;
}
if ( ( V_17 == V_16 )
|| ( V_17 == V_26 ) ) {
return V_17 ;
} else {
V_19 ++ ;
F_12 ( V_27 ) ;
}
}
return V_28 ;
}
void F_13 ( struct V_1 * V_2 , T_5 V_29 )
{
T_1 * V_3 = ( V_4 ) F_2 ( V_2 ) ;
T_4 V_18 ;
if ( V_3 -> V_21 == V_22 ) {
F_5 ( V_2 , V_12 ,
V_23 ) ;
F_5 ( V_2 , V_24 , V_29 ) ;
} else {
V_18 = ( T_4 ) V_29 ;
V_18 = F_10 ( V_18 ) ;
F_14 ( V_2 , V_25 , V_18 ) ;
}
}
T_5 F_15 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( V_4 ) F_2 ( V_2 ) ;
T_5 V_30 ;
T_4 V_18 ;
if ( V_3 -> V_21 == V_22 ) {
F_5 ( V_2 , V_12 , V_31 ) ;
V_30 = F_9 ( V_2 , V_24 ) ;
} else {
V_18 = F_11 ( V_2 , V_32 ) ;
V_18 = F_10 ( V_18 ) ;
V_30 = ( T_5 ) V_18 ;
}
return V_30 ;
}
long F_16 ( struct V_1 * V_2 )
{
T_1 * V_3 = ( V_4 ) F_2 ( V_2 ) ;
long V_33 ;
T_5 V_34 ;
if ( V_3 -> V_21 == V_22 ) {
F_5 ( V_2 , V_12 ,
V_35 ) ;
V_34 = F_9 ( V_2 , V_24 ) ;
V_33 = ( long ) ( V_34 << 16 ) ;
F_5 ( V_2 , V_12 ,
V_36 ) ;
V_34 = F_9 ( V_2 , V_24 ) ;
V_33 = ( long ) ( V_33 | V_34 ) ;
} else {
V_33 = F_11 ( V_2 , V_37 ) ;
V_33 = F_10 ( V_33 ) ;
}
return V_33 ;
}
void F_17 ( struct V_1 * V_2 , long V_38 )
{
T_1 * V_3 = ( V_4 ) F_2 ( V_2 ) ;
T_5 V_7 ;
T_4 V_18 ;
if ( V_3 -> V_21 == V_22 ) {
V_7 = ( T_5 ) ( V_38 >> 16 ) ;
F_5 ( V_2 , V_12 ,
V_35 ) ;
F_5 ( V_2 , V_24 , V_7 ) ;
V_7 = ( T_5 ) ( V_38 ) ;
F_5 ( V_2 , V_12 ,
V_36 ) ;
F_5 ( V_2 , V_24 , V_7 ) ;
} else {
V_18 = F_10 ( V_38 ) ;
F_14 ( V_2 , V_37 , V_18 ) ;
}
}
T_5 F_18 ( T_6 V_39 )
{
T_5 * V_40 = ( T_5 * ) V_39 ;
T_5 V_41 ;
V_41 = ( ( ( ( ( ( V_40 [ 0 ] ^ V_40 [ 1 ] ) ^ V_40 [ 2 ] ) ^ V_40 [ 3 ] ) ^
V_40 [ 4 ] ) ^ V_40 [ 5 ] ) ^ V_40 [ 6 ] ) ;
return V_41 ;
}
int F_19 ( struct V_1 * V_2 , const T_7 * V_42 , T_3 V_43 )
{
T_1 * V_3 = ( V_4 ) F_2 ( V_2 ) ;
int V_44 = V_45 ;
T_5 V_46 = 0 ;
T_3 V_47 ;
T_5 V_17 ;
T_6 V_39 ;
T_5 V_48 ;
T_8 V_49 ;
long V_50 ;
T_5 V_51 ;
T_5 V_52 ;
T_9 V_53 ;
T_10 V_54 ;
T_11 V_55 ;
T_12 V_56 = NULL ;
T_13 V_57 = NULL ;
long V_58 ;
BOOLEAN V_59 = 0 ;
T_14 V_60 ;
T_5 * V_61 = NULL ;
T_5 * V_62 = NULL ;
T_15 * V_63 = NULL ;
T_15 * V_64 = NULL ;
T_15 * V_65 = NULL ;
int V_66 ;
long V_67 ;
long V_68 = 0 ;
long V_69 = 0 ;
long V_70 = 0 ;
long V_71 = 0 ;
unsigned long V_5 ;
unsigned long V_9 ;
unsigned long V_72 = 0 ;
V_67 = * ( long * ) V_42 ;
V_47 = V_73 ;
V_49 = ( T_8 ) V_42 ;
V_55 = ( T_11 ) V_42 ;
switch ( V_67 ) {
case 5 :
case 6 :
V_62 =
( T_5 * ) ( ( long ) V_42 + V_55 -> V_74 ) ;
V_63 =
( T_15 * ) ( ( long ) V_42 + V_55 -> V_74 ) ;
V_64 =
( T_15 * ) ( ( long ) V_42 + V_55 -> V_75 ) ;
V_68 = V_55 -> V_68 ;
V_69 = V_55 -> V_69 ;
V_59 = FALSE ;
break;
default:
V_44 = V_76 ;
break;
}
while ( ( V_44 == V_45 ) && ( V_47 != V_77 ) ) {
switch ( V_47 ) {
case V_73 :
V_17 = F_8 ( V_2 , V_78 ) ;
if ( V_17 == V_78 ) {
F_13 ( V_2 , V_79 ) ;
} else {
V_44 = V_76 ;
}
V_47 = V_80 ;
break;
case V_80 :
V_17 = F_8 ( V_2 , V_81 ) ;
if ( V_17 == V_81 ) {
V_51 = F_15 ( V_2 ) ;
switch ( V_51 ) {
case V_82 :
F_17 ( V_2 ,
V_68 ) ;
break;
case V_83 :
F_17 ( V_2 ,
V_69 ) ;
break;
case V_84 :
V_62 = ( T_5 * ) ( ( long ) V_64 ) ;
V_63 = ( T_15 * ) ( ( long ) V_64 ) ;
V_47 = V_85 ;
break;
case V_86 :
V_50 = F_16 ( V_2 ) ;
if ( V_50 > V_87 ) {
V_44 = V_76 ;
break;
}
if ( ( V_50 * 2 + ( long ) V_63 ) >
( long ) V_64 ) {
V_44 = V_76 ;
break;
}
F_4 ( & V_3 -> V_11 ,
V_5 ) ;
if ( V_67 == 5 ) {
F_5 ( V_2 ,
V_12 ,
V_88 ) ;
for (; V_50 > 0 ; V_50 -- ) {
F_5 ( V_2 ,
V_24 ,
* V_62 ) ;
V_62 ++ ;
V_63 += 2 ;
V_46 ++ ;
}
} else {
F_20 ( V_89 ,
V_2 -> V_14 +
V_12 ) ;
if ( V_50 & 0x01 ) {
V_50 ++ ;
}
V_50 = V_50 / 2 ;
for (; V_50 > 0 ; V_50 -- ) {
V_9 = * V_62 ++ ;
V_9 |=
( * V_62 ++ << 16 ) ;
V_63 += 4 ;
F_6 ( V_9 ,
V_2 -> V_14 +
V_90 ) ;
}
}
F_7 ( & V_3 ->
V_11 ,
V_5 ) ;
break;
default:
V_44 = V_76 ;
break;
}
F_13 ( V_2 , V_91 ) ;
} else {
V_44 = V_76 ;
}
break;
case V_85 :
V_17 = F_8 ( V_2 , V_81 ) ;
if ( V_17 == V_81 ) {
V_51 = F_15 ( V_2 ) ;
switch ( V_51 ) {
case V_92 :
F_3 ( 0 ,
L_2 ) ;
F_17 ( V_2 , V_72 ) ;
break;
case V_82 :
if ( V_59 ) {
F_17 ( V_2 ,
V_70 ) ;
} else {
V_44 = V_76 ;
break;
}
break;
case V_83 :
if ( V_59 ) {
F_17 ( V_2 ,
V_71 ) ;
} else {
V_44 = V_76 ;
break;
}
break;
case V_93 :
switch ( V_67 ) {
case 5 :
case 6 :
V_62 =
( T_5 * ) ( ( long ) V_42
+
V_55 ->
V_94 ) ;
V_63 =
( T_15 * ) ( ( long ) V_42
+
V_55 ->
V_94 ) ;
break;
default:
V_44 = V_76 ;
break;
}
V_47 = V_95 ;
break;
case V_86 :
if ( ! V_59 ) {
V_44 = V_76 ;
break;
}
V_50 = F_16 ( V_2 ) ;
if ( V_50 > V_87 ) {
V_44 = V_76 ;
break;
}
if ( ( V_50 * 2 + ( long ) V_63 ) >
( long ) V_65 ) {
V_44 = V_76 ;
break;
}
if ( V_67 == 5 ) {
F_5 ( V_2 ,
V_12 ,
V_88 ) ;
for (; V_50 > 0 ; V_50 -- ) {
F_5 ( V_2 ,
V_24 ,
* V_62 ) ;
V_62 ++ ;
V_63 += 2 ;
V_46 ++ ;
}
} else {
F_20 ( V_89 ,
V_2 -> V_14 +
V_12 ) ;
if ( V_50 & 0x01 ) {
V_50 ++ ;
}
V_50 = V_50 / 2 ;
for (; V_50 > 0 ; V_50 -- ) {
V_9 = * V_62 ++ ;
V_9 |=
( * V_62 ++ << 16 ) ;
V_63 += 4 ;
F_6 ( V_9 ,
V_2 -> V_14 +
V_90 ) ;
}
}
break;
case V_96 :
V_50 =
( long ) ( V_3 -> V_97 + 1 ) / 2 ;
F_17 ( V_2 , V_50 ) ;
V_60 =
( T_14 ) & V_3 -> V_98 [ 0 ] ;
V_61 =
( T_5 * ) & V_60 -> V_99 [ 0 ] ;
F_4 ( & V_3 -> V_11 ,
V_5 ) ;
if ( V_67 == 5 ) {
F_5 ( V_2 ,
V_12 ,
V_88 ) ;
for (; V_50 > 0 ; V_50 -- ) {
V_52 = F_21 ( * V_61 ) ;
F_5 ( V_2 ,
V_24 ,
V_52 ) ;
V_61 ++ ;
}
} else {
F_20 ( V_89 ,
V_2 -> V_14 +
V_12 ) ;
if ( V_50 & 0x01 ) {
V_50 ++ ;
}
V_50 = V_50 / 2 ;
for (; V_50 > 0 ; V_50 -- ) {
V_9 = * V_61 ++ ;
V_9 |=
( * V_61 ++ << 16 ) ;
F_6 ( V_9 ,
V_2 -> V_14 +
V_90 ) ;
}
}
F_7 ( & V_3 ->
V_11 ,
V_5 ) ;
break;
case V_100 :
V_50 =
V_55 -> V_101 ;
F_17 ( V_2 , V_50 ) ;
V_62 =
( T_5 * ) ( ( long ) V_42 +
V_55 ->
V_102 ) ;
F_4 ( & V_3 -> V_11 ,
V_5 ) ;
if ( V_67 == 5 ) {
F_5 ( V_2 ,
V_12 ,
V_88 ) ;
for (; V_50 > 0 ; V_50 -- ) {
F_5 ( V_2 ,
V_24 ,
* V_62
) ;
V_62 ++ ;
}
} else {
F_20 ( V_89 ,
V_2 -> V_14 +
V_12 ) ;
if ( V_50 & 0x01 ) {
V_50 ++ ;
}
V_50 = V_50 / 2 ;
for (; V_50 > 0 ; V_50 -- ) {
V_9 =
F_21 ( * V_62 ++ ) ;
V_52 =
F_21 ( * V_62 ++ ) ;
V_9 |=
( V_52 << 16 ) ;
F_6 ( V_9 ,
V_2 -> V_14 +
V_90 ) ;
}
}
F_7 ( & V_3 ->
V_11 ,
V_5 ) ;
break;
case V_103 :
V_59 = FALSE ;
V_58 =
F_16 ( V_2 ) ;
if ( V_67 == 5 ) {
V_56 =
( T_12 ) ( ( long )
V_42
+
sizeof
( V_104 ) ) ;
for ( V_66 = 0 ;
V_66 <
V_55 -> V_105 ;
V_66 ++ ) {
if ( V_56 ->
V_106 ==
V_58 ) {
V_59 =
TRUE ;
V_62 =
( T_5
* ) ( ( long )
V_42
+
V_56 ->
V_107 ) ;
V_63 =
( T_15
* ) ( ( long )
V_42
+
V_56 ->
V_107 ) ;
V_65 =
( T_15
* ) ( ( long )
V_42
+
V_56 ->
V_108 ) ;
V_70 =
V_56 ->
V_70 ;
V_71 =
V_56 ->
V_109 ;
break;
}
V_56 ++ ;
}
} else {
V_57 =
( T_13 ) ( ( long )
V_42
+
sizeof
( V_104 ) ) ;
for ( V_66 = 0 ;
V_66 <
V_55 -> V_105 ;
V_66 ++ ) {
V_52 = ( T_5 )
( V_57 ->
V_106 ) ;
V_9 = V_52 ;
V_52 = ( T_5 )
( V_57 ->
V_106 >> 16 ) ;
V_9 |=
( V_52 << 16 ) ;
if ( V_9 ==
V_58 ) {
V_59 =
TRUE ;
V_62 =
( T_5
* ) ( ( long )
V_42
+
V_57 ->
V_107 ) ;
V_63 =
( T_15
* ) ( ( long )
V_42
+
V_57 ->
V_107 ) ;
V_65 =
( T_15
* ) ( ( long )
V_42
+
V_57 ->
V_108 ) ;
V_70 =
V_57 ->
V_70 ;
V_71 =
V_57 ->
V_109 ;
V_72 =
( T_4 )
V_57 ->
V_110 ;
F_3 ( 0 ,
L_3 ,
( unsigned
int )
V_72 ) ;
break;
}
V_57 ++ ;
}
}
if ( ! V_59 ) {
V_44 = V_76 ;
break;
}
break;
default:
V_44 = V_76 ;
break;
}
F_13 ( V_2 , V_91 ) ;
} else {
V_44 = V_76 ;
}
break;
case V_95 :
if ( ( ( unsigned long ) ( V_63 ) - ( unsigned long ) V_42 ) >=
( unsigned long ) V_43 ) {
V_47 = V_77 ;
break;
}
V_39 = ( T_6 ) V_62 ;
if ( V_39 -> V_111 == 0x80
&& ( V_39 -> V_112 == 0x00
|| V_39 -> V_112 == 0x10 ) ) {
V_47 = V_113 ;
} else {
F_3 ( 1 ,
L_4 ) ;
F_3 ( 1 , L_5 ,
V_39 -> V_112 ) ;
F_3 ( 1 , L_6 ,
V_39 -> V_111 ) ;
V_44 = V_76 ;
}
break;
case V_113 :
V_39 = ( T_6 ) V_63 ;
if ( V_39 -> V_110 == F_18 ( V_39 ) ) {
if ( V_39 -> V_111 != 0x80 ) {
V_47 = V_114 ;
break;
}
V_48 = F_21 ( V_39 -> V_115 ) ;
V_54 =
F_22 ( ( V_48 + sizeof( V_116 ) ) ,
V_117 ) ;
if ( V_54 ) {
memcpy ( V_54 , ( void * ) V_63 ,
( T_3 ) ( V_48 +
sizeof( V_116 ) ) ) ;
V_53 =
F_22 ( sizeof( V_118 ) ,
V_117 ) ;
if ( V_53 ) {
V_53 -> V_119 =
V_54 ;
F_23 ( & V_53 ->
V_120 ,
& V_3 -> V_121 ) ;
V_63 =
( T_15 * ) ( ( unsigned long ) V_63 +
( unsigned long ) ( ( V_48 + 1 ) & 0xFFFFFFFE ) + sizeof( V_116 ) ) ;
if ( ( unsigned long ) ( V_63 ) -
( unsigned long ) ( V_42 ) >=
( unsigned long ) V_43 ) {
V_47 =
V_77 ;
}
} else {
F_24 ( V_54 ) ;
V_44 = V_76 ;
}
} else {
V_44 = V_76 ;
}
} else {
V_44 = V_76 ;
}
break;
case V_114 :
V_47 = V_77 ;
break;
default:
V_44 = V_76 ;
break;
}
}
return V_44 ;
}
