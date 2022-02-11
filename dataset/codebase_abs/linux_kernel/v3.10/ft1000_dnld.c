void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
unsigned long V_5 ;
T_1 * V_6 ;
T_1 V_7 ;
T_1 V_8 ;
T_1 V_9 ;
F_3 ( 0 , L_1 ) ;
V_6 = ( T_1 * ) V_10 ;
V_7 = sizeof( V_10 ) ;
if ( V_7 & 0x0003 ) {
V_7 += 4 ;
}
F_4 ( & V_4 -> V_11 , V_5 ) ;
F_5 ( V_2 , V_12 , V_13 ) ;
for ( V_8 = 0 ; V_8 < ( V_7 >> 2 ) ; V_8 ++ ) {
V_9 = * V_6 ++ ;
F_6 ( V_9 , V_2 -> V_14 + V_15 ) ;
}
F_7 ( & V_4 -> V_11 , V_5 ) ;
}
T_2 F_8 ( struct V_1 * V_2 , T_2 V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
T_2 V_17 ;
T_1 V_18 ;
int V_19 ;
V_19 = 0 ;
while ( V_19 < V_20 ) {
if ( V_4 -> V_21 == V_22 ) {
F_5 ( V_2 , V_12 ,
V_23 ) ;
V_17 = F_9 ( V_2 , V_24 ) ;
} else {
V_18 =
F_10 ( F_11
( V_2 , V_25 ) ) ;
V_17 = ( T_2 ) V_18 ;
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
void F_13 ( struct V_1 * V_2 , T_2 V_29 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
T_1 V_18 ;
if ( V_4 -> V_21 == V_22 ) {
F_5 ( V_2 , V_12 ,
V_23 ) ;
F_5 ( V_2 , V_24 , V_29 ) ;
} else {
V_18 = ( T_1 ) V_29 ;
V_18 = F_10 ( V_18 ) ;
F_14 ( V_2 , V_25 , V_18 ) ;
}
}
T_2 F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
T_2 V_30 ;
T_1 V_18 ;
if ( V_4 -> V_21 == V_22 ) {
F_5 ( V_2 , V_12 , V_31 ) ;
V_30 = F_9 ( V_2 , V_24 ) ;
} else {
V_18 = F_11 ( V_2 , V_32 ) ;
V_18 = F_10 ( V_18 ) ;
V_30 = ( T_2 ) V_18 ;
}
return V_30 ;
}
long F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
long V_33 ;
T_2 V_34 ;
if ( V_4 -> V_21 == V_22 ) {
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
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
T_2 V_7 ;
T_1 V_18 ;
if ( V_4 -> V_21 == V_22 ) {
V_7 = ( T_2 ) ( V_38 >> 16 ) ;
F_5 ( V_2 , V_12 ,
V_35 ) ;
F_5 ( V_2 , V_24 , V_7 ) ;
V_7 = ( T_2 ) ( V_38 ) ;
F_5 ( V_2 , V_12 ,
V_36 ) ;
F_5 ( V_2 , V_24 , V_7 ) ;
} else {
V_18 = F_10 ( V_38 ) ;
F_14 ( V_2 , V_37 , V_18 ) ;
}
}
T_2 F_18 ( struct V_39 * V_40 )
{
T_2 * V_41 = ( T_2 * ) V_40 ;
T_2 V_42 ;
V_42 = ( ( ( ( ( ( V_41 [ 0 ] ^ V_41 [ 1 ] ) ^ V_41 [ 2 ] ) ^ V_41 [ 3 ] ) ^
V_41 [ 4 ] ) ^ V_41 [ 5 ] ) ^ V_41 [ 6 ] ) ;
return V_42 ;
}
int F_19 ( struct V_1 * V_2 , const T_3 * V_43 ,
T_4 V_44 )
{
struct V_3 * V_4 = (struct V_3 * ) F_2 ( V_2 ) ;
int V_45 = V_46 ;
T_1 V_47 ;
T_2 V_17 ;
struct V_39 * V_40 ;
T_2 V_48 ;
long V_49 ;
T_2 V_50 ;
T_2 V_51 ;
struct V_52 * V_53 ;
T_3 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 = NULL ;
long V_59 ;
bool V_60 = 0 ;
struct V_61 * V_62 ;
T_2 * V_63 = NULL ;
T_2 * V_64 = NULL ;
T_3 * V_65 = NULL ;
T_3 * V_66 = NULL ;
T_3 * V_67 = NULL ;
int V_68 ;
long V_69 ;
long V_70 = 0 ;
long V_71 = 0 ;
long V_72 = 0 ;
long V_73 = 0 ;
unsigned long V_5 ;
unsigned long V_9 ;
unsigned long V_74 = 0 ;
V_69 = * ( long * ) V_43 ;
if ( V_69 != 6 ) {
F_20 ( V_75 L_2 , V_69 ) ;
V_45 = V_76 ;
}
V_47 = V_77 ;
V_56 = (struct V_55 * ) V_43 ;
V_64 = ( T_2 * ) ( ( long ) V_43 + V_56 -> V_78 ) ;
V_65 = ( T_3 * ) ( ( long ) V_43 + V_56 -> V_78 ) ;
V_66 = ( T_3 * ) ( ( long ) V_43 + V_56 -> V_79 ) ;
V_70 = V_56 -> V_70 ;
V_71 = V_56 -> V_71 ;
V_60 = false ;
while ( ( V_45 == V_46 ) && ( V_47 != V_80 ) ) {
switch ( V_47 ) {
case V_77 :
V_17 = F_8 ( V_2 , V_81 ) ;
if ( V_17 == V_81 ) {
F_13 ( V_2 , V_82 ) ;
} else {
V_45 = V_76 ;
}
V_47 = V_83 ;
break;
case V_83 :
V_17 = F_8 ( V_2 , V_84 ) ;
if ( V_17 == V_84 ) {
V_50 = F_15 ( V_2 ) ;
switch ( V_50 ) {
case V_85 :
F_17 ( V_2 ,
V_70 ) ;
break;
case V_86 :
F_17 ( V_2 ,
V_71 ) ;
break;
case V_87 :
V_64 = ( T_2 * ) ( ( long ) V_66 ) ;
V_65 = ( T_3 * ) ( ( long ) V_66 ) ;
V_47 = V_88 ;
break;
case V_89 :
V_49 = F_16 ( V_2 ) ;
if ( V_49 > V_90 ) {
V_45 = V_76 ;
break;
}
if ( ( V_49 * 2 + ( long ) V_65 ) >
( long ) V_66 ) {
V_45 = V_76 ;
break;
}
F_4 ( & V_4 -> V_11 ,
V_5 ) ;
F_21 ( V_91 ,
V_2 -> V_14 +
V_12 ) ;
if ( V_49 & 0x01 )
V_49 ++ ;
V_49 = V_49 / 2 ;
for (; V_49 > 0 ; V_49 -- ) {
V_9 = * V_64 ++ ;
V_9 |=
( * V_64 ++ << 16 ) ;
V_65 += 4 ;
F_6 ( V_9 ,
V_2 -> V_14 +
V_92 ) ;
}
F_7 ( & V_4 ->
V_11 ,
V_5 ) ;
break;
default:
V_45 = V_76 ;
break;
}
F_13 ( V_2 , V_93 ) ;
} else {
V_45 = V_76 ;
}
break;
case V_88 :
V_17 = F_8 ( V_2 , V_84 ) ;
if ( V_17 == V_84 ) {
V_50 = F_15 ( V_2 ) ;
switch ( V_50 ) {
case V_94 :
F_3 ( 0 ,
L_3 ) ;
F_17 ( V_2 , V_74 ) ;
break;
case V_85 :
if ( V_60 ) {
F_17 ( V_2 ,
V_72 ) ;
} else {
V_45 = V_76 ;
break;
}
break;
case V_86 :
if ( V_60 ) {
F_17 ( V_2 ,
V_73 ) ;
} else {
V_45 = V_76 ;
break;
}
break;
case V_95 :
V_64 = ( T_2 * ) ( ( long ) V_43 + V_56 -> V_96 ) ;
V_65 = ( T_3 * ) ( ( long ) V_43 + V_56 -> V_96 ) ;
V_47 = V_97 ;
break;
case V_89 :
if ( ! V_60 ) {
V_45 = V_76 ;
break;
}
V_49 = F_16 ( V_2 ) ;
if ( V_49 > V_90 ) {
V_45 = V_76 ;
break;
}
if ( ( V_49 * 2 + ( long ) V_65 ) >
( long ) V_67 ) {
V_45 = V_76 ;
break;
}
F_21 ( V_91 ,
V_2 -> V_14 +
V_12 ) ;
if ( V_49 & 0x01 )
V_49 ++ ;
V_49 = V_49 / 2 ;
for (; V_49 > 0 ; V_49 -- ) {
V_9 = * V_64 ++ ;
V_9 |=
( * V_64 ++ << 16 ) ;
V_65 += 4 ;
F_6 ( V_9 ,
V_2 -> V_14 +
V_92 ) ;
}
break;
case V_98 :
V_49 =
( long ) ( V_4 -> V_99 + 1 ) / 2 ;
F_17 ( V_2 , V_49 ) ;
V_62 =
(struct V_61 * ) & V_4 -> V_100 [ 0 ] ;
V_63 =
( T_2 * ) & V_62 -> V_101 [ 0 ] ;
F_4 ( & V_4 -> V_11 ,
V_5 ) ;
if ( V_69 == 5 ) {
F_5 ( V_2 ,
V_12 ,
V_102 ) ;
for (; V_49 > 0 ; V_49 -- ) {
V_51 = F_22 ( * V_63 ) ;
F_5 ( V_2 ,
V_24 ,
V_51 ) ;
V_63 ++ ;
}
} else {
F_21 ( V_91 ,
V_2 -> V_14 +
V_12 ) ;
if ( V_49 & 0x01 ) {
V_49 ++ ;
}
V_49 = V_49 / 2 ;
for (; V_49 > 0 ; V_49 -- ) {
V_9 = * V_63 ++ ;
V_9 |=
( * V_63 ++ << 16 ) ;
F_6 ( V_9 ,
V_2 -> V_14 +
V_92 ) ;
}
}
F_7 ( & V_4 ->
V_11 ,
V_5 ) ;
break;
case V_103 :
V_49 =
V_56 -> V_104 ;
F_17 ( V_2 , V_49 ) ;
V_64 =
( T_2 * ) ( ( long ) V_43 +
V_56 ->
V_105 ) ;
F_4 ( & V_4 -> V_11 ,
V_5 ) ;
F_21 ( V_91 ,
V_2 -> V_14 +
V_12 ) ;
if ( V_49 & 0x01 )
V_49 ++ ;
V_49 = V_49 / 2 ;
for (; V_49 > 0 ; V_49 -- ) {
V_9 =
F_22 ( * V_64 ++ ) ;
V_51 =
F_22 ( * V_64 ++ ) ;
V_9 |=
( V_51 << 16 ) ;
F_6 ( V_9 ,
V_2 -> V_14 +
V_92 ) ;
}
F_7 ( & V_4 ->
V_11 ,
V_5 ) ;
break;
case V_106 :
V_60 = false ;
V_59 =
F_16 ( V_2 ) ;
V_58 =
(struct V_57 * ) ( ( long )
V_43
+
sizeof
( struct V_55 ) ) ;
for ( V_68 = 0 ;
V_68 <
V_56 -> V_107 ;
V_68 ++ ) {
V_51 = ( T_2 )
( V_58 ->
V_108 ) ;
V_9 = V_51 ;
V_51 = ( T_2 )
( V_58 ->
V_108 >> 16 ) ;
V_9 |=
( V_51 << 16 ) ;
if ( V_9 ==
V_59 ) {
V_60 =
true ;
V_64 =
( T_2
* ) ( ( long )
V_43
+
V_58 ->
V_109 ) ;
V_65 =
( T_3
* ) ( ( long )
V_43
+
V_58 ->
V_109 ) ;
V_67 =
( T_3
* ) ( ( long )
V_43
+
V_58 ->
V_110 ) ;
V_72 =
V_58 ->
V_72 ;
V_73 =
V_58 ->
V_111 ;
V_74 =
( T_1 )
V_58 ->
V_112 ;
F_3 ( 0 ,
L_4 ,
( unsigned
int )
V_74 ) ;
break;
}
V_58 ++ ;
}
if ( ! V_60 ) {
V_45 = V_76 ;
break;
}
break;
default:
V_45 = V_76 ;
break;
}
F_13 ( V_2 , V_93 ) ;
} else {
V_45 = V_76 ;
}
break;
case V_97 :
if ( ( ( unsigned long ) ( V_65 ) - ( unsigned long ) V_43 ) >=
( unsigned long ) V_44 ) {
V_47 = V_80 ;
break;
}
V_40 = (struct V_39 * ) V_64 ;
if ( V_40 -> V_113 == 0x80
&& ( V_40 -> V_114 == 0x00
|| V_40 -> V_114 == 0x10 ) ) {
V_47 = V_115 ;
} else {
F_3 ( 1 ,
L_5 ) ;
F_3 ( 1 , L_6 ,
V_40 -> V_114 ) ;
F_3 ( 1 , L_7 ,
V_40 -> V_113 ) ;
V_45 = V_76 ;
}
break;
case V_115 :
V_40 = (struct V_39 * ) V_65 ;
if ( V_40 -> V_112 == F_18 ( V_40 ) ) {
if ( V_40 -> V_113 != 0x80 ) {
V_47 = V_116 ;
break;
}
V_48 = F_22 ( V_40 -> V_117 ) ;
V_54 =
F_23 ( ( V_48 + sizeof( struct V_39 ) ) ,
V_118 ) ;
if ( V_54 ) {
memcpy ( V_54 , ( void * ) V_65 ,
( T_1 ) ( V_48 +
sizeof( struct V_39 ) ) ) ;
V_53 =
F_23 ( sizeof( struct V_52 ) ,
V_118 ) ;
if ( V_53 ) {
V_53 -> V_119 =
V_54 ;
F_24 ( & V_53 ->
V_120 ,
& V_4 -> V_121 ) ;
V_65 =
( T_3 * ) ( ( unsigned long ) V_65 +
( unsigned long ) ( ( V_48 + 1 ) & 0xFFFFFFFE ) + sizeof( struct V_39 ) ) ;
if ( ( unsigned long ) ( V_65 ) -
( unsigned long ) ( V_43 ) >=
( unsigned long ) V_44 ) {
V_47 =
V_80 ;
}
} else {
F_25 ( V_54 ) ;
V_45 = V_76 ;
}
} else {
V_45 = V_76 ;
}
} else {
V_45 = V_76 ;
}
break;
case V_116 :
V_47 = V_80 ;
break;
default:
V_45 = V_76 ;
break;
}
}
return V_45 ;
}
