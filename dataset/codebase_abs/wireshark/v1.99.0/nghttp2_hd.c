static int F_1 ( const void * V_1 , const void * V_2 , T_1 V_3 )
{
const T_2 * V_4 = ( const T_2 * ) V_1 , * V_5 = ( const T_2 * ) V_2 ;
T_2 V_6 = 0 ;
while( V_3 > 0 ) {
V_6 |= ( * V_4 ++ ) ^ ( * V_5 ++ ) ;
-- V_3 ;
}
return V_6 == 0 ;
}
static T_3 F_2 ( const T_2 * V_7 , T_1 V_3 )
{
T_3 V_8 = 0 ;
while( V_3 > 0 ) {
V_8 = V_8 * 31 + * V_7 ++ ;
-- V_3 ;
}
return V_8 ;
}
int F_3 ( T_4 * V_9 , T_2 V_10 ,
T_2 * V_11 , T_1 V_12 ,
T_2 * V_13 , T_1 V_14 )
{
int V_15 = 0 ;
V_9 -> V_16 . V_10 = V_17 ;
if( ( V_10 & V_18 ) &&
( V_10 & V_19 ) == 0 ) {
if( V_12 == 0 ) {
V_9 -> V_16 . V_11 = NULL ;
} else {
V_9 -> V_16 . V_11 = ( T_2 * ) F_4 ( V_11 , V_12 ) ;
if( V_9 -> V_16 . V_11 == NULL ) {
V_15 = V_20 ;
goto V_21;
}
}
} else {
V_9 -> V_16 . V_11 = V_11 ;
}
if( ( V_10 & V_22 ) &&
( V_10 & V_23 ) == 0 ) {
if( V_14 == 0 ) {
V_9 -> V_16 . V_13 = NULL ;
} else {
V_9 -> V_16 . V_13 = ( T_2 * ) F_4 ( V_13 , V_14 ) ;
if( V_9 -> V_16 . V_13 == NULL ) {
V_15 = V_20 ;
goto V_24;
}
}
} else {
V_9 -> V_16 . V_13 = V_13 ;
}
V_9 -> V_16 . V_12 = V_12 ;
V_9 -> V_16 . V_14 = V_14 ;
V_9 -> V_25 = 1 ;
V_9 -> V_10 = V_10 ;
if( V_9 -> V_16 . V_11 ) {
V_9 -> V_26 = F_2 ( V_9 -> V_16 . V_11 , V_9 -> V_16 . V_12 ) ;
} else {
V_9 -> V_26 = 0 ;
}
if( V_9 -> V_16 . V_13 ) {
V_9 -> V_27 = F_2 ( V_9 -> V_16 . V_13 , V_9 -> V_16 . V_14 ) ;
} else {
V_9 -> V_27 = 0 ;
}
return 0 ;
V_24:
if( V_10 & V_18 ) {
free ( V_9 -> V_16 . V_11 ) ;
}
V_21:
return V_15 ;
}
void F_5 ( T_4 * V_9 )
{
assert ( V_9 -> V_25 == 0 ) ;
if( V_9 -> V_10 & V_18 ) {
free ( V_9 -> V_16 . V_11 ) ;
}
if( V_9 -> V_10 & V_22 ) {
free ( V_9 -> V_16 . V_13 ) ;
}
}
static int F_6 ( T_5 * V_28 , T_1 V_29 )
{
T_1 V_30 ;
for( V_30 = 1 ; V_30 < V_29 ; V_30 <<= 1 ) ;
V_28 -> V_31 = ( T_4 * * ) malloc ( sizeof( T_4 * ) * V_30 ) ;
if( V_28 -> V_31 == NULL ) {
return V_20 ;
}
V_28 -> V_32 = V_30 - 1 ;
V_28 -> V_33 = 0 ;
V_28 -> V_34 = 0 ;
return 0 ;
}
static T_4 * F_7 ( T_5 * V_28 ,
T_1 V_35 )
{
assert ( V_35 < V_28 -> V_34 ) ;
return V_28 -> V_31 [ ( V_28 -> V_33 + V_35 ) & V_28 -> V_32 ] ;
}
static int F_8 ( T_5 * V_28 , T_1 V_29 )
{
T_1 V_36 ;
T_1 V_30 ;
T_4 * * V_31 ;
if( V_28 -> V_32 + 1 >= V_29 ) {
return 0 ;
}
for( V_30 = 1 ; V_30 < V_29 ; V_30 <<= 1 ) ;
V_31 = ( T_4 * * ) malloc ( sizeof( T_4 * ) * V_30 ) ;
if( V_31 == NULL ) {
return V_20 ;
}
for( V_36 = 0 ; V_36 < V_28 -> V_34 ; ++ V_36 ) {
V_31 [ V_36 ] = F_7 ( V_28 , V_36 ) ;
}
free ( V_28 -> V_31 ) ;
V_28 -> V_31 = V_31 ;
V_28 -> V_32 = V_30 - 1 ;
V_28 -> V_33 = 0 ;
return 0 ;
}
static void F_9 ( T_5 * V_28 )
{
T_1 V_36 ;
if( V_28 == NULL ) {
return;
}
for( V_36 = 0 ; V_36 < V_28 -> V_34 ; ++ V_36 ) {
T_4 * V_9 = F_7 ( V_28 , V_36 ) ;
-- V_9 -> V_25 ;
F_5 ( V_9 ) ;
free ( V_9 ) ;
}
free ( V_28 -> V_31 ) ;
}
static int F_10 ( T_5 * V_28 ,
T_4 * V_9 )
{
int V_15 ;
V_15 = F_8 ( V_28 , V_28 -> V_34 + 1 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
V_28 -> V_31 [ -- V_28 -> V_33 & V_28 -> V_32 ] = V_9 ;
++ V_28 -> V_34 ;
return 0 ;
}
static void F_11 ( T_5 * V_28 )
{
assert ( V_28 -> V_34 > 0 ) ;
-- V_28 -> V_34 ;
}
static int F_12 ( T_6 * V_37 )
{
int V_15 ;
V_37 -> V_38 = 0 ;
V_37 -> V_39 = V_40 ;
V_15 = F_6
( & V_37 -> V_41 ,
V_37 -> V_39 / V_42 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
V_37 -> V_43 = 0 ;
return 0 ;
}
static void F_13 ( T_6 * V_37 )
{
F_9 ( & V_37 -> V_41 ) ;
}
int F_14 ( T_7 * V_44 )
{
return F_15 ( V_44 ,
V_45 ) ;
}
int F_15 ( T_7 * V_44 ,
T_1 V_46 )
{
int V_15 ;
V_15 = F_12 ( & V_44 -> V_47 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
if( V_46 < V_40 ) {
V_44 -> V_48 = 1 ;
V_44 -> V_47 . V_39 = V_46 ;
} else {
V_44 -> V_48 = 0 ;
}
V_44 -> V_46 = V_46 ;
V_44 -> V_49 = V_50 ;
return 0 ;
}
int F_16 ( T_8 * V_51 )
{
int V_15 ;
V_15 = F_12 ( & V_51 -> V_47 ) ;
if( V_15 != 0 ) {
goto V_21;
}
V_51 -> V_52 =
V_40 ;
V_51 -> V_53 = NULL ;
V_51 -> V_54 = NULL ;
V_51 -> V_55 = V_56 ;
V_51 -> V_57 = V_58 ;
V_15 = F_17 ( & V_51 -> V_59 , V_60 / 8 , 8 , 1 , 0 ) ;
if( V_15 != 0 ) {
goto V_61;
}
V_51 -> V_62 = 0 ;
V_51 -> V_63 = 0 ;
V_51 -> V_64 = 0 ;
V_51 -> V_65 = 0 ;
V_51 -> V_66 = 0 ;
V_51 -> V_67 = 0 ;
V_51 -> V_68 = 0 ;
return 0 ;
V_61:
F_13 ( & V_51 -> V_47 ) ;
V_21:
return V_15 ;
}
static void F_18 ( T_8 * V_51 )
{
if( V_51 -> V_53 ) {
if( V_51 -> V_53 -> V_25 == 0 ) {
F_5 ( V_51 -> V_53 ) ;
free ( V_51 -> V_53 ) ;
}
V_51 -> V_53 = NULL ;
}
free ( V_51 -> V_54 ) ;
V_51 -> V_54 = NULL ;
}
void F_19 ( T_7 * V_44 )
{
F_13 ( & V_44 -> V_47 ) ;
}
void F_20 ( T_8 * V_51 )
{
F_18 ( V_51 ) ;
F_21 ( & V_51 -> V_59 ) ;
F_13 ( & V_51 -> V_47 ) ;
}
static T_1 F_22 ( T_1 V_12 , T_1 V_14 )
{
return V_42 + V_12 + V_14 ;
}
static int F_23 ( T_9 * V_69 , T_4 * V_9 )
{
F_24 ( fprintf ( V_70 , L_1 ) ) ;
F_24 ( fwrite ( V_9 -> V_16 . V_11 , V_9 -> V_16 . V_12 , 1 , V_70 ) ) ;
F_24 ( fprintf ( V_70 , L_2 ) ) ;
F_24 ( fwrite ( V_9 -> V_16 . V_13 , V_9 -> V_16 . V_14 , 1 , V_70 ) ) ;
F_24 ( fprintf ( V_70 , L_3 ) ) ;
* V_69 = V_9 -> V_16 ;
return 0 ;
}
static int F_25 ( T_9 * V_69 , T_9 * V_16 )
{
F_24 ( fprintf ( V_70 , L_1 ) ) ;
F_24 ( fwrite ( V_16 -> V_11 , V_16 -> V_12 , 1 , V_70 ) ) ;
F_24 ( fprintf ( V_70 , L_2 ) ) ;
F_24 ( fwrite ( V_16 -> V_13 , V_16 -> V_14 , 1 , V_70 ) ) ;
F_24 ( fprintf ( V_70 , L_3 ) ) ;
* V_69 = * V_16 ;
return 0 ;
}
static T_1 F_26 ( T_1 V_3 , T_1 V_71 )
{
T_1 V_72 = ( 1 << V_71 ) - 1 ;
T_1 V_34 = 0 ;
if( V_3 >= V_72 ) {
V_3 -= V_72 ;
++ V_34 ;
} else {
return 1 ;
}
do {
++ V_34 ;
if( V_3 >= 128 ) {
V_3 >>= 7 ;
} else {
break;
}
} while( V_3 );
return V_34 ;
}
static T_1 F_27 ( T_2 * V_73 , T_1 V_3 , T_1 V_71 )
{
T_1 V_72 = ( 1 << V_71 ) - 1 ;
T_1 V_34 = 0 ;
* V_73 &= ~ V_72 ;
if( V_3 < V_72 ) {
* V_73 ++ |= V_3 ;
return 1 ;
}
* V_73 ++ |= V_72 ;
V_3 -= V_72 ;
++ V_34 ;
do {
++ V_34 ;
if( V_3 >= 128 ) {
* V_73 ++ = ( 1 << 7 ) | ( V_3 & 0x7f ) ;
V_3 >>= 7 ;
} else {
* V_73 ++ = ( T_2 ) V_3 ;
break;
}
} while( V_3 );
return V_34 ;
}
static T_10 F_28 ( T_3 * V_74 , T_1 * V_75 , int * V_76 ,
T_3 V_77 , T_1 V_65 ,
T_2 * V_78 , T_2 * V_79 , T_1 V_71 )
{
T_3 V_72 = ( 1 << V_71 ) - 1 ;
T_3 V_3 = V_77 ;
T_2 * V_80 = V_78 ;
* V_75 = 0 ;
* V_76 = 0 ;
if( V_3 == 0 ) {
if( ( * V_78 & V_72 ) != V_72 ) {
* V_74 = ( * V_78 ) & V_72 ;
* V_76 = 1 ;
return 1 ;
}
V_3 = V_72 ;
if( ++ V_78 == V_79 ) {
* V_74 = V_3 ;
return ( T_10 ) ( V_78 - V_80 ) ;
}
}
for(; V_78 != V_79 ; ++ V_78 , V_65 += 7 ) {
T_3 V_81 = * V_78 & 0x7f ;
if( ( V_50 >> V_65 ) < V_81 ) {
F_24 ( fprintf ( V_70 , L_4 ) ) ;
return - 1 ;
}
V_81 <<= V_65 ;
if( V_50 - V_81 < V_3 ) {
F_24 ( fprintf ( V_70 , L_5 ) ) ;
return - 1 ;
}
V_3 += V_81 ;
if( ( * V_78 & ( 1 << 7 ) ) == 0 ) {
break;
}
}
* V_75 = V_65 ;
if( V_78 == V_79 ) {
* V_74 = V_3 ;
return ( T_10 ) ( V_78 - V_80 ) ;
}
* V_74 = V_3 ;
* V_76 = 1 ;
return ( T_10 ) ( V_78 + 1 - V_80 ) ;
}
static int F_29 ( T_11 * V_82 , T_1 V_83 )
{
int V_15 ;
T_2 * V_84 ;
T_1 V_85 ;
T_2 V_86 [ 16 ] ;
F_24 ( fprintf ( V_70 , L_6 , V_83 ) ) ;
V_85 = F_26 ( V_83 , 5 ) ;
if( sizeof( V_86 ) < V_85 ) {
return V_87 ;
}
V_84 = V_86 ;
* V_84 = 0x20u ;
F_27 ( V_84 , V_83 , 5 ) ;
V_15 = F_30 ( V_82 , V_86 , V_85 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
return 0 ;
}
static int F_31 ( T_11 * V_82 , T_1 V_35 )
{
int V_15 ;
T_1 V_85 ;
T_2 V_86 [ 16 ] ;
T_2 * V_84 ;
V_85 = F_26 ( V_35 + 1 , 7 ) ;
F_24 ( fprintf ( V_70 , L_7 ,
V_35 , V_85 ) ) ;
if( sizeof( V_86 ) < V_85 ) {
return V_87 ;
}
V_84 = V_86 ;
* V_84 = 0x80u ;
F_27 ( V_84 , V_35 + 1 , 7 ) ;
V_15 = F_30 ( V_82 , V_86 , V_85 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
return 0 ;
}
static int F_32 ( T_11 * V_82 , const T_2 * V_88 , T_1 V_34 )
{
int V_15 ;
T_2 V_86 [ 16 ] ;
T_2 * V_84 ;
T_1 V_85 ;
T_1 V_89 ;
int V_90 = 0 ;
V_89 = F_33 ( V_88 , V_34 ) ;
if( V_89 < V_34 ) {
V_90 = 1 ;
} else {
V_89 = V_34 ;
}
V_85 = F_26 ( V_89 , 7 ) ;
F_24 ( fprintf ( V_70 ,
L_8 ) ) ;
F_24 ( fwrite ( V_88 , V_34 , 1 , V_70 ) ) ;
F_24 ( fprintf ( V_70 , L_9 ,
V_34 , V_90 , V_89 ) ) ;
if( sizeof( V_86 ) < V_85 ) {
return V_87 ;
}
V_84 = V_86 ;
* V_84 = V_90 ? 1 << 7 : 0 ;
F_27 ( V_84 , V_89 , 7 ) ;
V_15 = F_30 ( V_82 , V_86 , V_85 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
if( V_90 ) {
V_15 = F_34 ( V_82 , V_88 , V_34 ) ;
} else {
assert ( V_89 == V_34 ) ;
V_15 = F_30 ( V_82 , V_88 , V_34 ) ;
}
return V_15 ;
}
static T_2 F_35 ( int V_91 , int V_68 )
{
if( V_91 ) {
return 0x40u ;
}
if( V_68 ) {
return 0x10u ;
}
return 0 ;
}
static int F_36 ( T_11 * V_82 , T_1 V_35 ,
const T_9 * V_16 ,
int V_91 )
{
int V_15 ;
T_2 * V_84 ;
T_1 V_85 ;
T_2 V_86 [ 16 ] ;
T_1 V_92 ;
int V_68 ;
V_68 = ( V_16 -> V_10 & V_93 ) != 0 ;
if( V_91 ) {
V_92 = 6 ;
} else {
V_92 = 4 ;
}
F_24 ( fprintf ( V_70 ,
L_10
L_11 ,
V_35 , V_16 -> V_14 , V_91 , V_68 ) ) ;
V_85 = F_26 ( V_35 + 1 , V_92 ) ;
if( sizeof( V_86 ) < V_85 ) {
return V_87 ;
}
V_84 = V_86 ;
* V_84 = F_35 ( V_91 , V_68 ) ;
F_27 ( V_84 , V_35 + 1 , V_92 ) ;
V_15 = F_30 ( V_82 , V_86 , V_85 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
V_15 = F_32 ( V_82 , V_16 -> V_13 , V_16 -> V_14 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
return 0 ;
}
static int F_37 ( T_11 * V_82 , const T_9 * V_16 ,
int V_91 )
{
int V_15 ;
int V_68 ;
V_68 = ( V_16 -> V_10 & V_93 ) != 0 ;
F_24 ( fprintf ( V_70 ,
L_12
L_11 ,
V_16 -> V_12 , V_16 -> V_14 , V_91 , V_68 ) ) ;
V_15 = F_38 ( V_82 , F_35 ( V_91 , V_68 ) ) ;
if( V_15 != 0 ) {
return V_15 ;
}
V_15 = F_32 ( V_82 , V_16 -> V_11 , V_16 -> V_12 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
V_15 = F_32 ( V_82 , V_16 -> V_13 , V_16 -> V_14 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
return 0 ;
}
static T_4 * F_39 ( T_6 * V_37 ,
const T_9 * V_16 ,
T_2 V_94 )
{
int V_15 ;
T_4 * V_95 ;
T_1 V_96 ;
V_96 = F_22 ( V_16 -> V_12 , V_16 -> V_14 ) ;
while( V_37 -> V_43 + V_96 > V_37 -> V_39 &&
V_37 -> V_41 . V_34 > 0 ) {
T_1 V_35 = V_37 -> V_41 . V_34 - 1 ;
T_4 * V_9 = F_7 ( & V_37 -> V_41 , V_35 ) ;
V_37 -> V_43 -= F_22 ( V_9 -> V_16 . V_12 , V_9 -> V_16 . V_14 ) ;
F_24 ( fprintf ( V_70 , L_13 ) ) ;
F_24 ( fwrite ( V_9 -> V_16 . V_11 , V_9 -> V_16 . V_12 , 1 , V_70 ) ) ;
F_24 ( fprintf ( V_70 , L_2 ) ) ;
F_24 ( fwrite ( V_9 -> V_16 . V_13 , V_9 -> V_16 . V_14 , 1 , V_70 ) ) ;
F_24 ( fprintf ( V_70 , L_3 ) ) ;
F_11 ( & V_37 -> V_41 ) ;
if( -- V_9 -> V_25 == 0 ) {
F_5 ( V_9 ) ;
free ( V_9 ) ;
}
}
V_95 = ( T_4 * ) malloc ( sizeof( T_4 ) ) ;
if( V_95 == NULL ) {
return NULL ;
}
V_15 = F_3 ( V_95 , V_94 ,
V_16 -> V_11 , V_16 -> V_12 , V_16 -> V_13 , V_16 -> V_14 ) ;
if( V_15 != 0 ) {
free ( V_95 ) ;
return NULL ;
}
if( V_96 > V_37 -> V_39 ) {
-- V_95 -> V_25 ;
} else {
V_15 = F_10 ( & V_37 -> V_41 , V_95 ) ;
if( V_15 != 0 ) {
-- V_95 -> V_25 ;
V_95 -> V_16 . V_11 = NULL ;
V_95 -> V_16 . V_12 = 0 ;
V_95 -> V_16 . V_13 = NULL ;
V_95 -> V_16 . V_14 = 0 ;
F_5 ( V_95 ) ;
free ( V_95 ) ;
return NULL ;
}
V_37 -> V_43 += V_96 ;
}
return V_95 ;
}
static int F_40 ( const T_9 * V_4 , const T_9 * V_5 )
{
return V_4 -> V_12 == V_5 -> V_12 && F_1 ( V_4 -> V_11 , V_5 -> V_11 , V_4 -> V_12 ) ;
}
static int F_41 ( const T_9 * V_4 , const T_9 * V_5 )
{
return V_4 -> V_14 == V_5 -> V_14 && F_1 ( V_4 -> V_13 , V_5 -> V_13 , V_4 -> V_14 ) ;
}
static T_12 F_42 ( T_6 * V_37 ,
const T_9 * V_16 )
{
T_12 V_74 = { - 1 , 0 } ;
T_1 V_36 ;
T_3 V_26 = F_2 ( V_16 -> V_11 , V_16 -> V_12 ) ;
T_3 V_27 = F_2 ( V_16 -> V_13 , V_16 -> V_14 ) ;
int V_97 = ( V_16 -> V_10 & V_93 ) == 0 ;
for( V_36 = 0 ; V_36 < V_98 ; ++ V_36 ) {
T_4 * V_9 = & V_99 [ V_36 ] ;
if( V_9 -> V_26 != V_26 || ! F_40 ( & V_9 -> V_16 , V_16 ) ) {
continue;
}
if( V_74 . V_63 == - 1 ) {
V_74 . V_63 = ( T_10 ) V_36 ;
}
if( V_97 &&
V_9 -> V_27 == V_27 && F_41 ( & V_9 -> V_16 , V_16 ) ) {
V_74 . V_63 = ( T_10 ) V_36 ;
V_74 . V_100 = 1 ;
return V_74 ;
}
}
if( ! V_97 ) {
return V_74 ;
}
for( V_36 = 0 ; V_36 < V_37 -> V_41 . V_34 ; ++ V_36 ) {
T_4 * V_9 = F_7 ( & V_37 -> V_41 , V_36 ) ;
if( V_9 -> V_26 == V_26 && F_40 ( & V_9 -> V_16 , V_16 ) ) {
if( V_74 . V_63 == - 1 ) {
V_74 . V_63 = ( T_10 ) ( V_36 + V_98 ) ;
}
if( V_9 -> V_27 == V_27 && F_41 ( & V_9 -> V_16 , V_16 ) ) {
V_74 . V_63 = ( T_10 ) ( V_36 + V_98 ) ;
V_74 . V_100 = 1 ;
return V_74 ;
}
}
}
return V_74 ;
}
static void F_43 ( T_6 * V_37 )
{
while( V_37 -> V_43 > V_37 -> V_39 &&
V_37 -> V_41 . V_34 > 0 ) {
T_1 V_35 = V_37 -> V_41 . V_34 - 1 ;
T_4 * V_9 = F_7 ( & V_37 -> V_41 , V_35 ) ;
V_37 -> V_43 -= F_22 ( V_9 -> V_16 . V_12 , V_9 -> V_16 . V_14 ) ;
F_11 ( & V_37 -> V_41 ) ;
if( -- V_9 -> V_25 == 0 ) {
F_5 ( V_9 ) ;
free ( V_9 ) ;
}
}
}
int F_44 ( T_7 * V_44 ,
T_1 V_52 )
{
T_1 V_101 = F_45 ( V_52 ,
V_44 -> V_46 ) ;
V_44 -> V_47 . V_39 = V_101 ;
V_44 -> V_49 =
F_45 ( V_44 -> V_49 , V_101 ) ;
V_44 -> V_48 = 1 ;
F_43 ( & V_44 -> V_47 ) ;
return 0 ;
}
int F_46 ( T_8 * V_51 ,
T_1 V_52 )
{
V_51 -> V_52 = V_52 ;
V_51 -> V_47 . V_39 = V_52 ;
F_43 ( & V_51 -> V_47 ) ;
return 0 ;
}
static T_1 F_47 ( T_6 * V_37 )
{
return V_37 -> V_41 . V_34 + V_98 - 1 ;
}
T_4 * F_48 ( T_6 * V_37 ,
T_1 V_35 )
{
assert ( F_49 ( V_37 , V_35 ) ) ;
if( V_35 >= V_98 ) {
return F_7 ( & V_37 -> V_41 , V_35 - V_98 ) ;
} else {
return & V_99 [ V_35 ] ;
}
}
static int F_50 ( T_7 * V_44 ,
const T_9 * V_16 )
{
if( ( V_16 -> V_10 & V_93 ) ||
F_22 ( V_16 -> V_12 , V_16 -> V_14 ) >
V_44 -> V_47 . V_39 * 3 / 4 ) {
return 0 ;
}
#ifdef F_51
return ! F_52 ( V_16 , F_51 ) ;
#else
return
! F_52 ( V_16 , L_14 ) &&
! F_52 ( V_16 , L_15 ) &&
! F_52 ( V_16 , L_16 ) &&
! F_52 ( V_16 , L_17 ) &&
! F_52 ( V_16 , L_18 ) ;
#endif
}
static int F_53 ( T_7 * V_44 ,
T_11 * V_82 , const T_9 * V_16 )
{
int V_15 ;
T_12 V_74 ;
T_10 V_35 = - 1 ;
int V_102 = 0 ;
F_24 ( fprintf ( V_70 , L_19 ) ) ;
F_24 ( fwrite ( V_16 -> V_11 , V_16 -> V_12 , 1 , V_70 ) ) ;
F_24 ( fprintf ( V_70 , L_2 ) ) ;
F_24 ( fwrite ( V_16 -> V_13 , V_16 -> V_14 , 1 , V_70 ) ) ;
F_24 ( fprintf ( V_70 , L_3 ) ) ;
V_74 = F_42 ( & V_44 -> V_47 , V_16 ) ;
V_35 = V_74 . V_63 ;
if( V_74 . V_100 ) {
F_24 ( fprintf ( V_70 , L_20 , V_35 ) ) ;
V_15 = F_31 ( V_82 , V_35 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
return 0 ;
}
if( V_74 . V_63 != - 1 ) {
F_24 ( fprintf ( V_70 , L_21 ,
V_74 . V_63 ) ) ;
}
if( F_50 ( V_44 , V_16 ) ) {
T_4 * V_95 ;
if( V_35 != - 1 && V_35 < ( T_10 ) V_98 ) {
T_9 V_103 ;
V_103 = * V_16 ;
V_103 . V_11 = F_48 ( & V_44 -> V_47 , V_35 ) -> V_16 . V_11 ;
V_95 = F_39 ( & V_44 -> V_47 , & V_103 ,
V_22 ) ;
} else {
V_95 = F_39 ( & V_44 -> V_47 , V_16 ,
V_18 |
V_22 ) ;
}
if( ! V_95 ) {
return V_87 ;
}
if( V_95 -> V_25 == 0 ) {
F_5 ( V_95 ) ;
free ( V_95 ) ;
}
V_102 = 1 ;
}
if( V_35 == - 1 ) {
V_15 = F_37 ( V_82 , V_16 , V_102 ) ;
} else {
V_15 = F_36 ( V_82 , V_35 , V_16 , V_102 ) ;
}
if( V_15 != 0 ) {
return V_15 ;
}
return 0 ;
}
int F_54 ( T_7 * V_44 ,
T_11 * V_82 ,
const T_9 * V_16 , T_1 V_104 )
{
T_1 V_36 ;
int V_15 = 0 ;
if( V_44 -> V_47 . V_38 ) {
return V_87 ;
}
if( V_44 -> V_48 ) {
T_1 V_49 ;
V_49 = V_44 -> V_49 ;
V_44 -> V_48 = 0 ;
V_44 -> V_49 = V_50 ;
if( V_44 -> V_47 . V_39 > V_49 ) {
V_15 = F_29 ( V_82 , V_49 ) ;
if( V_15 != 0 ) {
goto V_21;
}
}
V_15 = F_29 ( V_82 , V_44 -> V_47 . V_39 ) ;
if( V_15 != 0 ) {
goto V_21;
}
}
for( V_36 = 0 ; V_36 < V_104 ; ++ V_36 ) {
V_15 = F_53 ( V_44 , V_82 , & V_16 [ V_36 ] ) ;
if( V_15 != 0 ) {
goto V_21;
}
}
F_24 ( fprintf ( V_70 ,
L_22 ) ) ;
return 0 ;
V_21:
F_24 ( fprintf ( V_70 , L_23 , V_15 ) ) ;
V_44 -> V_47 . V_38 = 1 ;
return V_15 ;
}
T_10 F_55 ( T_7 * V_44 ,
T_2 * V_73 , T_1 V_105 ,
const T_9 * V_16 , T_1 V_104 )
{
T_11 V_82 ;
int V_15 ;
V_15 = F_56 ( & V_82 , V_73 , V_105 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
V_15 = F_54 ( V_44 , & V_82 , V_16 , V_104 ) ;
V_105 = F_57 ( & V_82 ) ;
F_58 ( & V_82 ) ;
if( V_15 == V_106 ) {
return V_107 ;
}
if( V_15 != 0 ) {
return V_15 ;
}
return ( T_10 ) V_105 ;
}
T_1 F_59 ( T_7 * V_44 ,
const T_9 * V_108 , T_1 V_104 )
{
T_1 V_3 = 0 ;
T_1 V_36 ;
( void ) V_44 ;
V_3 += 12 ;
V_3 += 6 * 2 * V_104 ;
for( V_36 = 0 ; V_36 < V_104 ; ++ V_36 ) {
V_3 += V_108 [ V_36 ] . V_12 + V_108 [ V_36 ] . V_14 ;
}
return V_3 ;
}
int F_60 ( T_7 * * V_109 ,
T_1 V_46 )
{
int V_15 ;
T_7 * V_44 ;
V_44 = ( T_7 * ) malloc ( sizeof( T_7 ) ) ;
if( V_44 == NULL ) {
return V_20 ;
}
V_15 = F_15 ( V_44 , V_46 ) ;
if( V_15 != 0 ) {
free ( V_44 ) ;
return V_15 ;
}
* V_109 = V_44 ;
return 0 ;
}
void F_61 ( T_7 * V_44 )
{
F_19 ( V_44 ) ;
free ( V_44 ) ;
}
static void F_62 ( T_8 * V_51 ,
const T_2 * V_78 )
{
V_51 -> V_62 = ( * V_78 & ( 1 << 7 ) ) != 0 ;
}
static T_10 F_63 ( T_8 * V_51 ,
int * V_110 ,
T_2 * V_78 , T_2 * V_79 ,
T_1 V_71 , T_1 V_111 )
{
T_10 V_15 ;
T_3 V_112 ;
* V_110 = 0 ;
V_15 = F_28 ( & V_112 , & V_51 -> V_65 , V_110 , ( T_3 ) V_51 -> V_64 ,
V_51 -> V_65 , V_78 , V_79 , V_71 ) ;
if( V_15 == - 1 ) {
F_24 ( fprintf ( V_70 , L_24 ) ) ;
return V_87 ;
}
if( V_112 > V_111 ) {
F_24 ( fprintf ( V_70 ,
L_25 ,
V_111 ) ) ;
return V_87 ;
}
V_51 -> V_64 = V_112 ;
F_24 ( fprintf ( V_70 , L_26 , V_112 ) ) ;
return V_15 ;
}
static T_10 F_64 ( T_8 * V_51 ,
T_11 * V_82 ,
T_2 * V_78 , T_2 * V_79 )
{
T_10 V_113 ;
int V_76 = 0 ;
if( ( T_1 ) ( V_79 - V_78 ) >= V_51 -> V_64 ) {
V_79 = V_78 + V_51 -> V_64 ;
V_76 = 1 ;
}
V_113 = F_65 ( & V_51 -> V_114 , V_82 ,
V_78 , V_79 - V_78 , V_76 ) ;
if( V_113 < 0 ) {
F_24 ( fprintf ( V_70 , L_27 ) ) ;
return V_113 ;
}
V_51 -> V_64 -= ( T_1 ) V_113 ;
return V_113 ;
}
static T_10 F_66 ( T_8 * V_51 ,
T_11 * V_82 ,
T_2 * V_78 , T_2 * V_79 )
{
int V_15 ;
T_1 V_34 = F_45 ( ( T_1 ) ( V_79 - V_78 ) , V_51 -> V_64 ) ;
V_15 = F_30 ( V_82 , V_78 , V_34 ) ;
if( V_15 != 0 ) {
return V_15 ;
}
V_51 -> V_64 -= V_34 ;
return ( T_10 ) V_34 ;
}
static int F_67 ( T_8 * V_51 ,
T_9 * V_69 )
{
T_4 * V_9 = F_48 ( & V_51 -> V_47 , V_51 -> V_63 ) ;
F_23 ( V_69 , V_9 ) ;
return 0 ;
}
static int F_68 ( T_8 * V_51 ,
T_9 * V_16 , int V_115 )
{
T_10 V_15 ;
T_1 V_105 ;
T_2 * V_73 ;
V_15 = F_69 ( & V_51 -> V_59 , & V_73 ) ;
if( V_15 < 0 ) {
return V_20 ;
}
V_105 = V_15 ;
if( V_115 ) {
V_16 -> V_11 = NULL ;
V_16 -> V_12 = 0 ;
} else {
V_16 -> V_11 = V_73 ;
V_16 -> V_12 = V_51 -> V_66 ;
}
V_16 -> V_13 = V_73 + V_16 -> V_12 ;
V_16 -> V_14 = V_105 - V_16 -> V_12 ;
return 0 ;
}
static int F_70 ( T_8 * V_51 ,
T_9 * V_69 )
{
int V_15 ;
T_9 V_16 ;
V_15 = F_68 ( V_51 , & V_16 , 0 ) ;
if( V_15 != 0 ) {
return V_20 ;
}
if( V_51 -> V_68 ) {
V_16 . V_10 = V_93 ;
} else {
V_16 . V_10 = V_17 ;
}
if( V_51 -> V_67 ) {
T_4 * V_95 ;
T_2 V_116 ;
V_116 = V_18 | V_19 ;
V_95 = F_39 ( & V_51 -> V_47 , & V_16 , V_116 ) ;
if( V_95 ) {
F_23 ( V_69 , V_95 ) ;
V_51 -> V_53 = V_95 ;
return 0 ;
}
free ( V_16 . V_11 ) ;
return V_20 ;
}
F_25 ( V_69 , & V_16 ) ;
V_51 -> V_54 = V_16 . V_11 ;
return 0 ;
}
static int F_71 ( T_8 * V_51 ,
T_9 * V_69 )
{
int V_15 ;
T_9 V_16 ;
T_4 * V_117 ;
V_15 = F_68 ( V_51 , & V_16 , 1 ) ;
if( V_15 != 0 ) {
return V_20 ;
}
if( V_51 -> V_68 ) {
V_16 . V_10 = V_93 ;
} else {
V_16 . V_10 = V_17 ;
}
V_117 = F_48 ( & V_51 -> V_47 , V_51 -> V_63 ) ;
V_16 . V_11 = V_117 -> V_16 . V_11 ;
V_16 . V_12 = V_117 -> V_16 . V_12 ;
if( V_51 -> V_67 ) {
T_4 * V_95 ;
T_2 V_116 ;
int V_118 ;
V_116 = V_22 | V_23 ;
V_118 = V_51 -> V_63 < V_98 ;
if( ! V_118 ) {
V_116 |= V_18 ;
++ V_117 -> V_25 ;
}
V_95 = F_39 ( & V_51 -> V_47 , & V_16 , V_116 ) ;
if( ! V_118 && -- V_117 -> V_25 == 0 ) {
F_5 ( V_117 ) ;
free ( V_117 ) ;
}
if( V_95 ) {
F_23 ( V_69 , V_95 ) ;
V_51 -> V_53 = V_95 ;
return 0 ;
}
free ( V_16 . V_13 ) ;
return V_20 ;
}
F_25 ( V_69 , & V_16 ) ;
V_51 -> V_54 = V_16 . V_13 ;
return 0 ;
}
T_10 F_72 ( T_8 * V_51 ,
T_9 * V_69 , int * V_119 ,
T_2 * V_78 , T_1 V_120 , int V_121 )
{
T_10 V_15 = 0 ;
T_2 * V_33 = V_78 ;
T_2 * V_79 = V_78 + V_120 ;
int V_110 = 0 ;
if( V_51 -> V_47 . V_38 ) {
return V_87 ;
}
F_24 ( fprintf ( V_70 , L_28 ,
V_51 -> V_57 ) ) ;
F_18 ( V_51 ) ;
* V_119 = V_122 ;
for(; V_78 != V_79 ; ) {
switch( V_51 -> V_57 ) {
case V_58 :
if( ( * V_78 & 0xe0u ) == 0x20u ) {
F_24 ( fprintf ( V_70 , L_29 ) ) ;
V_51 -> V_55 = V_123 ;
V_51 -> V_57 = V_124 ;
} else if( * V_78 & 0x80u ) {
F_24 ( fprintf ( V_70 , L_30 ) ) ;
V_51 -> V_55 = V_123 ;
V_51 -> V_57 = V_125 ;
} else {
if( * V_78 == 0x40u || * V_78 == 0 || * V_78 == 0x10u ) {
F_24 ( fprintf ( V_70 ,
L_31 ) ) ;
V_51 -> V_55 = V_126 ;
V_51 -> V_57 = V_127 ;
} else {
F_24 ( fprintf ( V_70 ,
L_32 ) ) ;
V_51 -> V_55 = V_128 ;
V_51 -> V_57 = V_125 ;
}
V_51 -> V_67 = ( * V_78 & 0x40 ) != 0 ;
V_51 -> V_68 = ( * V_78 & 0xf0u ) == 0x10u ;
F_24 ( fprintf ( V_70 ,
L_33 ,
V_51 -> V_67 ,
V_51 -> V_68 ) ) ;
if( V_51 -> V_55 == V_126 ) {
++ V_78 ;
}
}
V_51 -> V_64 = 0 ;
V_51 -> V_65 = 0 ;
break;
case V_124 :
V_110 = 0 ;
V_15 = F_63 ( V_51 , & V_110 , V_78 , V_79 , 5 ,
V_51 -> V_52 ) ;
if( V_15 < 0 ) {
goto V_21;
}
V_78 += V_15 ;
if( ! V_110 ) {
goto V_129;
}
F_24 ( fprintf ( V_70 , L_34 , V_51 -> V_64 ) ) ;
V_51 -> V_47 . V_39 = V_51 -> V_64 ;
F_43 ( & V_51 -> V_47 ) ;
V_51 -> V_57 = V_58 ;
break;
case V_125 : {
T_1 V_92 ;
if( V_51 -> V_55 == V_123 ) {
V_92 = 7 ;
} else if( V_51 -> V_67 ) {
V_92 = 6 ;
} else {
V_92 = 4 ;
}
V_110 = 0 ;
V_15 = F_63 ( V_51 , & V_110 , V_78 , V_79 , V_92 ,
F_47 ( & V_51 -> V_47 ) + 1 ) ;
if( V_15 < 0 ) {
goto V_21;
}
V_78 += V_15 ;
if( ! V_110 ) {
goto V_129;
}
if( V_51 -> V_64 == 0 ) {
V_15 = V_87 ;
goto V_21;
}
F_24 ( fprintf ( V_70 , L_35 , V_51 -> V_64 ) ) ;
if( V_51 -> V_55 == V_123 ) {
V_51 -> V_63 = V_51 -> V_64 ;
-- V_51 -> V_63 ;
V_15 = F_67 ( V_51 , V_69 ) ;
if( V_15 < 0 ) {
goto V_21;
}
V_51 -> V_57 = V_58 ;
if( V_15 == 0 ) {
* V_119 |= V_130 ;
return ( T_10 ) ( V_78 - V_33 ) ;
}
} else {
V_51 -> V_63 = V_51 -> V_64 ;
-- V_51 -> V_63 ;
V_51 -> V_57 = V_131 ;
}
break;
}
case V_127 :
F_62 ( V_51 , V_78 ) ;
V_51 -> V_57 = V_132 ;
V_51 -> V_64 = 0 ;
V_51 -> V_65 = 0 ;
F_24 ( fprintf ( V_70 , L_36 ,
V_51 -> V_62 != 0 ) ) ;
case V_132 :
V_110 = 0 ;
V_15 = F_63 ( V_51 , & V_110 , V_78 , V_79 , 7 ,
V_60 ) ;
if( V_15 < 0 ) {
goto V_21;
}
V_78 += V_15 ;
if( ! V_110 ) {
F_24 ( fprintf ( V_70 ,
L_37 ,
V_51 -> V_64 ) ) ;
goto V_129;
}
if( V_51 -> V_62 ) {
F_73 ( & V_51 -> V_114 ) ;
V_51 -> V_57 = V_133 ;
} else {
V_51 -> V_57 = V_134 ;
}
break;
case V_133 :
V_15 = F_64 ( V_51 , & V_51 -> V_59 , V_78 , V_79 ) ;
if( V_15 < 0 ) {
goto V_21;
}
V_78 += V_15 ;
F_24 ( fprintf ( V_70 , L_38 , V_15 ) ) ;
if( V_51 -> V_64 ) {
F_24 ( fprintf ( V_70 ,
L_39 , V_51 -> V_64 ) ) ;
goto V_129;
}
V_51 -> V_66 = F_57 ( & V_51 -> V_59 ) ;
V_51 -> V_57 = V_131 ;
break;
case V_134 :
V_15 = F_66 ( V_51 , & V_51 -> V_59 , V_78 , V_79 ) ;
if( V_15 < 0 ) {
goto V_21;
}
V_78 += V_15 ;
F_24 ( fprintf ( V_70 , L_38 , V_15 ) ) ;
if( V_51 -> V_64 ) {
F_24 ( fprintf ( V_70 ,
L_39 , V_51 -> V_64 ) ) ;
goto V_129;
}
V_51 -> V_66 = F_57 ( & V_51 -> V_59 ) ;
V_51 -> V_57 = V_131 ;
break;
case V_131 :
F_62 ( V_51 , V_78 ) ;
V_51 -> V_57 = V_135 ;
V_51 -> V_64 = 0 ;
V_51 -> V_65 = 0 ;
F_24 ( fprintf ( V_70 , L_36 ,
V_51 -> V_62 != 0 ) ) ;
case V_135 :
V_110 = 0 ;
V_15 = F_63 ( V_51 , & V_110 , V_78 , V_79 , 7 ,
V_60 ) ;
if( V_15 < 0 ) {
goto V_21;
}
V_78 += V_15 ;
if( ! V_110 ) {
goto V_129;
}
F_24 ( fprintf ( V_70 , L_40 , V_51 -> V_64 ) ) ;
if( V_51 -> V_64 == 0 ) {
if( V_51 -> V_55 == V_126 ) {
V_15 = F_70 ( V_51 , V_69 ) ;
} else {
V_15 = F_71 ( V_51 , V_69 ) ;
}
if( V_15 != 0 ) {
goto V_21;
}
V_51 -> V_57 = V_58 ;
* V_119 |= V_130 ;
return ( T_10 ) ( V_78 - V_33 ) ;
}
if( V_51 -> V_62 ) {
F_73 ( & V_51 -> V_114 ) ;
V_51 -> V_57 = V_136 ;
} else {
V_51 -> V_57 = V_137 ;
}
break;
case V_136 :
V_15 = F_64 ( V_51 , & V_51 -> V_59 , V_78 , V_79 ) ;
if( V_15 < 0 ) {
goto V_21;
}
V_78 += V_15 ;
F_24 ( fprintf ( V_70 , L_38 , V_15 ) ) ;
if( V_51 -> V_64 ) {
F_24 ( fprintf ( V_70 ,
L_39 , V_51 -> V_64 ) ) ;
goto V_129;
}
if( V_51 -> V_55 == V_126 ) {
V_15 = F_70 ( V_51 , V_69 ) ;
} else {
V_15 = F_71 ( V_51 , V_69 ) ;
}
if( V_15 != 0 ) {
goto V_21;
}
V_51 -> V_57 = V_58 ;
* V_119 |= V_130 ;
return ( T_10 ) ( V_78 - V_33 ) ;
case V_137 :
V_15 = F_66 ( V_51 , & V_51 -> V_59 , V_78 , V_79 ) ;
if( V_15 < 0 ) {
F_24 ( fprintf ( V_70 , L_41 ,
V_15 , F_74 ( ( int ) V_15 ) ) ) ;
goto V_21;
}
V_78 += V_15 ;
F_24 ( fprintf ( V_70 , L_38 , V_15 ) ) ;
if( V_51 -> V_64 ) {
F_24 ( fprintf ( V_70 ,
L_39 , V_51 -> V_64 ) ) ;
goto V_129;
}
if( V_51 -> V_55 == V_126 ) {
V_15 = F_70 ( V_51 , V_69 ) ;
} else {
V_15 = F_71 ( V_51 , V_69 ) ;
}
if( V_15 != 0 ) {
goto V_21;
}
V_51 -> V_57 = V_58 ;
* V_119 |= V_130 ;
return ( T_10 ) ( V_78 - V_33 ) ;
}
}
assert ( V_78 == V_79 ) ;
F_24 ( fprintf ( V_70 , L_42 ) ) ;
if( V_121 ) {
F_24 ( fprintf ( V_70 , L_43 ) ) ;
if( V_51 -> V_57 != V_58 ) {
F_24 ( fprintf ( V_70 , L_44 ,
V_51 -> V_57 ) ) ;
V_15 = V_87 ;
goto V_21;
}
* V_119 |= V_138 ;
}
return ( T_10 ) ( V_78 - V_33 ) ;
V_129:
if( V_121 && V_51 -> V_57 != V_58 ) {
F_24 ( fprintf ( V_70 , L_45 ) ) ;
V_15 = V_87 ;
goto V_21;
}
return ( T_10 ) ( V_78 - V_33 ) ;
V_21:
F_24 ( fprintf ( V_70 , L_46 , V_15 ) ) ;
V_51 -> V_47 . V_38 = 1 ;
return V_15 ;
}
int F_75 ( T_8 * V_51 )
{
F_18 ( V_51 ) ;
return 0 ;
}
int F_76 ( T_8 * * V_139 )
{
int V_15 ;
T_8 * V_51 ;
V_51 = ( T_8 * ) malloc ( sizeof( T_8 ) ) ;
if( V_51 == NULL ) {
return V_20 ;
}
V_15 = F_16 ( V_51 ) ;
if( V_15 != 0 ) {
free ( V_51 ) ;
return V_15 ;
}
* V_139 = V_51 ;
return 0 ;
}
void F_77 ( T_8 * V_51 )
{
F_20 ( V_51 ) ;
free ( V_51 ) ;
}
int F_78 ( T_11 * V_82 , T_1 V_35 ,
T_9 * V_16 , int V_91 )
{
return F_36 ( V_82 , V_35 , V_16 , V_91 ) ;
}
int F_79 ( T_11 * V_82 , T_9 * V_16 ,
int V_91 )
{
return F_37 ( V_82 , V_16 , V_91 ) ;
}
int F_80 ( T_11 * V_82 , T_1 V_83 )
{
return F_29 ( V_82 , V_83 ) ;
}
T_10 F_81 ( T_3 * V_74 , T_1 * V_75 , int * V_76 ,
T_3 V_77 , T_1 V_65 ,
T_2 * V_78 , T_2 * V_79 , T_1 V_71 )
{
return F_28 ( V_74 , V_75 , V_76 , V_77 , V_65 , V_78 , V_79 ,
V_71 ) ;
}
