static int F_1 ( T_1 * V_1 )
{
T_2 V_2 ;
T_3 V_3 , V_4 ;
T_4 V_5 ;
int V_6 ;
V_1 -> V_2 . V_7 = 0 ;
V_4 = ( 0x100000 < V_1 -> V_8 . V_9 -> V_10 ) ? 0x100000 : V_1 -> V_8 . V_9 -> V_10 ;
for ( V_3 = 0 ;
( V_3 + sizeof( V_2 ) ) < V_4 ;
V_3 += V_1 -> V_8 . V_9 -> V_11 ? : 0x2000 ) {
V_6 = V_1 -> V_8 . V_9 -> V_12 ( V_1 -> V_8 . V_9 , V_3 , sizeof( V_2 ) , & V_5 ,
( unsigned char * ) & V_2 ) ;
if ( V_6 )
return V_6 ;
if ( strcmp ( V_2 . V_13 + 3 , L_1 ) == 0 ) break;
}
if ( V_3 == V_4 ) {
F_2 ( V_14 L_2 ) ;
return - V_15 ;
}
if ( V_2 . V_16 != 9 ||
( V_2 . V_17 < 10 ) || ( V_2 . V_17 > 31 ) ||
( V_2 . V_18 >= F_3 ( V_2 . V_19 ) ) ) {
F_2 ( V_14 L_3 ) ;
return - 1 ;
}
if ( ( 1 << V_2 . V_17 ) != V_1 -> V_8 . V_9 -> V_11 ) {
F_2 ( V_14 L_4 ,
1 << V_2 . V_17 , V_1 -> V_8 . V_9 -> V_11 ) ;
return - 1 ;
}
V_1 -> V_2 = V_2 ;
return 0 ;
}
static int F_4 ( T_1 * V_1 )
{
T_2 V_2 ;
T_5 V_20 , V_21 , V_22 ;
unsigned V_23 , V_24 ;
int V_25 , V_5 = - 1 ;
T_6 V_26 ;
T_3 V_3 ;
V_1 -> V_27 = F_3 ( V_1 -> V_2 . V_19 ) -
V_1 -> V_2 . V_18 ;
V_1 -> V_28 = F_5 ( V_1 -> V_27 * sizeof( struct V_29 ) ,
V_30 ) ;
if ( ! V_1 -> V_28 )
goto V_31;
for ( V_22 = 0 ; V_22 < V_1 -> V_27 ; V_22 ++ )
V_1 -> V_28 [ V_22 ] . V_32 = 0xffffffff ;
V_1 -> V_33 =
F_5 ( V_1 -> V_2 . V_18 * sizeof( struct V_34 ) ,
V_30 ) ;
if ( ! V_1 -> V_33 )
goto V_35;
V_20 = V_21 = 0 ;
for ( V_22 = 0 ; V_22 < F_3 ( V_1 -> V_2 . V_19 ) ; V_22 ++ ) {
V_3 = ( ( V_22 + F_3 ( V_1 -> V_2 . V_36 ) )
<< V_1 -> V_2 . V_17 ) ;
V_5 = V_1 -> V_8 . V_9 -> V_12 ( V_1 -> V_8 . V_9 , V_3 , sizeof( V_2 ) , & V_26 ,
( unsigned char * ) & V_2 ) ;
if ( V_5 )
goto V_37;
V_5 = - 1 ;
V_25 = ( strcmp ( V_2 . V_13 + 3 , L_1 ) == 0 ) ;
if ( V_25 && ( F_3 ( V_2 . V_38 ) < V_1 -> V_27 ) &&
( V_1 -> V_28 [ F_3 ( V_2 . V_38 ) ] . V_32 == 0xffffffff ) ) {
V_1 -> V_28 [ F_3 ( V_2 . V_38 ) ] . V_32 = V_3 ;
V_1 -> V_28 [ F_3 ( V_2 . V_38 ) ] . V_39 =
F_6 ( V_2 . V_39 ) ;
V_20 ++ ;
} else {
if ( V_21 == V_1 -> V_2 . V_18 ) {
F_2 ( V_14 L_5
L_6 ) ;
goto V_37;
}
if ( V_25 && ( F_3 ( V_2 . V_38 ) == 0xffff ) ) {
V_1 -> V_33 [ V_21 ] . V_40 = V_41 ;
V_1 -> V_33 [ V_21 ] . V_39 = F_6 ( V_2 . V_39 ) ;
} else {
V_1 -> V_33 [ V_21 ] . V_40 = V_42 ;
V_1 -> V_33 [ V_21 ] . V_39 =
F_6 ( V_1 -> V_2 . V_39 ) ;
}
V_1 -> V_33 [ V_21 ] . V_32 = V_3 ;
V_21 ++ ;
}
}
V_2 = V_1 -> V_2 ;
if ( ( V_21 != V_2 . V_18 ) ||
( V_20 + V_21 != F_3 ( V_2 . V_19 ) ) ) {
F_2 ( V_14 L_7
L_8 ) ;
goto V_37;
}
V_23 = F_6 ( V_2 . V_7 ) >> V_2 . V_16 ;
V_1 -> V_43 = F_7 ( V_23 * sizeof( V_44 ) ) ;
if ( ! V_1 -> V_43 )
goto V_37;
memset ( V_1 -> V_43 , 0xff , V_23 * sizeof( V_44 ) ) ;
V_1 -> V_45 = ( 1 << V_2 . V_17 ) >> V_2 . V_16 ;
V_1 -> V_46 = F_5 ( V_1 -> V_45 * sizeof( V_44 ) ,
V_30 ) ;
if ( ! V_1 -> V_46 )
goto V_47;
V_1 -> V_48 = 0xffff ;
V_1 -> V_49 = 0 ;
for ( V_22 = 0 ; V_22 < V_1 -> V_27 ; V_22 ++ ) {
V_1 -> V_28 [ V_22 ] . Free = 0 ;
V_1 -> V_28 [ V_22 ] . V_50 = 0 ;
V_3 = V_1 -> V_28 [ V_22 ] . V_32 + F_6 ( V_2 . V_51 ) ;
V_5 = V_1 -> V_8 . V_9 -> V_12 ( V_1 -> V_8 . V_9 , V_3 ,
V_1 -> V_45 * sizeof( V_44 ) , & V_26 ,
( unsigned char * ) V_1 -> V_46 ) ;
if ( V_5 )
goto V_52;
for ( V_24 = 0 ; V_24 < V_1 -> V_45 ; V_24 ++ ) {
if ( F_8 ( F_6 ( V_1 -> V_46 [ V_24 ] ) ) ) {
V_1 -> V_28 [ V_22 ] . Free ++ ;
V_1 -> V_49 ++ ;
} else if ( ( F_9 ( F_6 ( V_1 -> V_46 [ V_24 ] ) ) == V_53 ) &&
( F_10 ( F_6 ( V_1 -> V_46 [ V_24 ] ) ) < V_23 ) )
V_1 -> V_43 [ F_10 ( F_6 ( V_1 -> V_46 [ V_24 ] ) ) ] =
( V_22 << V_2 . V_17 ) + ( V_24 << V_2 . V_16 ) ;
else if ( F_11 ( F_6 ( V_1 -> V_46 [ V_24 ] ) ) )
V_1 -> V_28 [ V_22 ] . V_50 ++ ;
}
}
V_5 = 0 ;
goto V_31;
V_52:
F_12 ( V_1 -> V_46 ) ;
V_47:
F_13 ( V_1 -> V_43 ) ;
V_37:
F_12 ( V_1 -> V_33 ) ;
V_35:
F_12 ( V_1 -> V_28 ) ;
V_31:
return V_5 ;
}
static int F_14 ( T_1 * V_1 ,
T_5 V_54 )
{
int V_5 ;
struct V_34 * V_55 ;
struct V_56 * V_57 ;
V_55 = & V_1 -> V_33 [ V_54 ] ;
F_15 ( L_9 , V_55 -> V_32 ) ;
V_55 -> V_40 = V_58 ;
V_57 = F_5 ( sizeof( struct V_56 ) , V_30 ) ;
if ( ! V_57 )
return - V_59 ;
V_57 -> V_9 = V_1 -> V_8 . V_9 ;
V_57 -> V_60 = V_61 ;
V_57 -> V_62 = V_55 -> V_32 ;
V_57 -> V_63 = 1 << V_1 -> V_2 . V_17 ;
V_57 -> V_64 = ( V_65 ) V_1 ;
V_5 = V_1 -> V_8 . V_9 -> V_57 ( V_1 -> V_8 . V_9 , V_57 ) ;
if ( ! V_5 )
V_55 -> V_39 ++ ;
else
F_12 ( V_57 ) ;
return V_5 ;
}
static void V_61 ( struct V_56 * V_57 )
{
T_1 * V_1 ;
struct V_34 * V_55 ;
int V_22 ;
V_1 = ( T_1 * ) ( V_57 -> V_64 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_2 . V_18 ; V_22 ++ )
if ( V_1 -> V_33 [ V_22 ] . V_32 == V_57 -> V_62 ) break;
if ( V_22 == V_1 -> V_2 . V_18 ) {
F_2 ( V_14 L_10
L_11 ) ;
return;
}
V_55 = & V_1 -> V_33 [ V_22 ] ;
if ( V_57 -> V_40 == V_66 )
V_55 -> V_40 = V_67 ;
else {
V_55 -> V_40 = V_68 ;
F_2 ( V_14 L_12 ,
V_57 -> V_40 ) ;
}
F_12 ( V_57 ) ;
}
static int F_16 ( T_1 * V_1 , int V_22 )
{
T_2 V_2 ;
struct V_34 * V_55 ;
int V_69 , V_5 ;
V_44 V_70 ;
T_6 V_71 ;
T_3 V_3 ;
V_55 = & V_1 -> V_33 [ V_22 ] ;
V_55 -> V_40 = V_68 ;
F_15 ( L_13 , V_55 -> V_32 ) ;
V_2 = V_1 -> V_2 ;
V_2 . V_38 = F_17 ( 0xffff ) ;
V_2 . V_39 = F_18 ( V_55 -> V_39 ) ;
V_5 = V_1 -> V_8 . V_9 -> V_72 ( V_1 -> V_8 . V_9 , V_55 -> V_32 , sizeof( V_2 ) ,
& V_71 , ( V_73 * ) & V_2 ) ;
if ( V_5 ) {
return V_5 ;
}
V_69 = ( V_1 -> V_45 * sizeof( V_44 ) +
F_6 ( V_1 -> V_2 . V_51 ) + V_74 - 1 ) / V_74 ;
V_3 = V_55 -> V_32 + F_6 ( V_1 -> V_2 . V_51 ) ;
V_70 = F_18 ( V_75 ) ;
for ( V_22 = 0 ; V_22 < V_69 ; V_22 ++ , V_3 += sizeof( V_44 ) ) {
V_5 = V_1 -> V_8 . V_9 -> V_72 ( V_1 -> V_8 . V_9 , V_3 , sizeof( V_44 ) ,
& V_71 , ( V_73 * ) & V_70 ) ;
if ( V_5 )
return V_5 ;
}
V_55 -> V_40 = V_41 ;
return 0 ;
}
static int F_19 ( T_1 * V_1 , T_5 V_76 ,
T_5 V_77 )
{
V_73 V_78 [ V_74 ] ;
struct V_29 * V_79 ;
struct V_34 * V_55 ;
V_44 V_80 , V_81 , free , V_22 ;
T_5 V_82 ;
int V_5 ;
T_6 V_71 ;
T_3 V_3 ;
T_5 V_83 = F_17 ( V_76 ) ;
V_79 = & V_1 -> V_28 [ V_76 ] ;
V_55 = & V_1 -> V_33 [ V_77 ] ;
F_15 ( L_14 ,
V_79 -> V_32 , V_55 -> V_32 ) ;
if ( V_1 -> V_48 != V_76 ) {
V_3 = V_79 -> V_32 + F_6 ( V_1 -> V_2 . V_51 ) ;
V_5 = V_1 -> V_8 . V_9 -> V_12 ( V_1 -> V_8 . V_9 , V_3 ,
V_1 -> V_45 * sizeof( V_44 ) ,
& V_71 , ( V_73 * ) ( V_1 -> V_46 ) ) ;
V_1 -> V_48 = 0xffff ;
if ( V_5 ) {
F_2 ( V_84 L_15 ) ;
return V_5 ;
}
}
V_55 -> V_40 = V_42 ;
V_3 = V_55 -> V_32 + 20 ;
V_82 = F_17 ( 0x7fff ) ;
V_5 = V_1 -> V_8 . V_9 -> V_72 ( V_1 -> V_8 . V_9 , V_3 , sizeof( T_5 ) ,
& V_71 , ( V_73 * ) & V_82 ) ;
if ( V_5 ) {
F_2 ( V_84 L_16 ) ;
return V_5 ;
}
V_80 = V_79 -> V_32 ; V_81 = V_55 -> V_32 ;
free = 0 ;
V_5 = 0 ;
for ( V_22 = 0 ; V_22 < V_1 -> V_45 ; V_22 ++ ) {
switch ( F_9 ( F_6 ( V_1 -> V_46 [ V_22 ] ) ) ) {
case V_75 :
break;
case V_53 :
case V_85 :
V_5 = V_1 -> V_8 . V_9 -> V_12 ( V_1 -> V_8 . V_9 , V_80 , V_74 ,
& V_71 , ( V_73 * ) V_78 ) ;
if ( V_5 ) {
F_2 ( V_84 L_17 ) ;
return V_5 ;
}
V_5 = V_1 -> V_8 . V_9 -> V_72 ( V_1 -> V_8 . V_9 , V_81 , V_74 ,
& V_71 , ( V_73 * ) V_78 ) ;
if ( V_5 ) {
F_2 ( V_84 L_18 ) ;
return V_5 ;
}
break;
default:
V_1 -> V_46 [ V_22 ] = F_18 ( 0xffffffff ) ;
free ++ ;
break;
}
V_80 += V_74 ;
V_81 += V_74 ;
}
V_5 = V_1 -> V_8 . V_9 -> V_72 ( V_1 -> V_8 . V_9 , V_55 -> V_32 + F_6 ( V_1 -> V_2 . V_51 ) ,
V_1 -> V_45 * sizeof( V_86 ) , & V_71 ,
( V_73 * ) V_1 -> V_46 ) ;
if ( V_5 ) {
F_2 ( V_84 L_19 ) ;
return V_5 ;
}
V_5 = V_1 -> V_8 . V_9 -> V_72 ( V_1 -> V_8 . V_9 , V_55 -> V_32 + 20 , sizeof( T_5 ) ,
& V_71 , ( V_73 * ) & V_83 ) ;
if ( V_5 ) {
F_2 ( V_84 L_20 ) ;
return V_5 ;
}
V_22 = V_55 -> V_39 ;
V_55 -> V_39 = V_79 -> V_39 ;
V_79 -> V_39 = V_22 ;
V_22 = V_55 -> V_32 ;
V_55 -> V_32 = V_79 -> V_32 ;
V_79 -> V_32 = V_22 ;
V_1 -> V_49 -= V_79 -> Free ;
V_1 -> V_49 += free ;
V_79 -> Free = free ;
V_79 -> V_50 = 0 ;
V_1 -> V_48 = V_76 ;
return 0 ;
}
static int F_20 ( T_1 * V_1 )
{
T_5 V_22 , V_79 , V_55 ;
V_44 V_87 ;
int V_88 , V_5 ;
F_15 ( L_21 ) ;
F_15 ( L_22 , V_1 -> V_2 . V_18 ) ;
V_87 = 0xffffffff ; V_55 = 0xffff ;
do {
V_88 = 0 ;
for ( V_22 = 0 ; V_22 < V_1 -> V_2 . V_18 ; V_22 ++ ) {
int V_89 = 0 ;
if ( V_1 -> V_33 [ V_22 ] . V_40 == V_42 ) {
F_15 ( L_23 , V_22 ) ;
V_89 = 1 ;
F_14 ( V_1 , V_22 ) ;
}
if ( V_1 -> V_33 [ V_22 ] . V_40 == V_58 ) {
F_15 ( L_24 , V_22 ) ;
V_89 = 1 ;
V_88 = 1 ;
}
else if ( V_1 -> V_33 [ V_22 ] . V_40 == V_67 ) {
F_15 ( L_25 , V_22 ) ;
V_89 = 1 ;
F_16 ( V_1 , V_22 ) ;
}
if ( V_1 -> V_33 [ V_22 ] . V_40 == V_41 ) {
F_15 ( L_26 , V_22 ) ;
V_89 = 1 ;
if ( V_1 -> V_33 [ V_22 ] . V_39 <= V_87 ) {
V_87 = V_1 -> V_33 [ V_22 ] . V_39 ;
V_55 = V_22 ;
}
}
if ( ! V_89 )
F_15 ( L_27 , V_22 , V_1 -> V_33 [ V_22 ] . V_40 ) ;
}
if ( V_55 == 0xffff ) {
if ( V_88 ) {
F_15 ( L_28
L_29 ) ;
if ( V_1 -> V_8 . V_9 -> V_90 )
V_1 -> V_8 . V_9 -> V_90 ( V_1 -> V_8 . V_9 ) ;
} else {
static int V_91 = 0 ;
if ( ++ V_91 < 5 )
F_2 ( V_14 L_30
L_31 ) ;
else
F_15 ( L_30
L_31 ) ;
return - V_92 ;
}
}
} while ( V_55 == 0xffff );
V_79 = 0 ;
if ( ( V_93 % V_94 ) == 0 ) {
F_15 ( L_32 ) ;
V_87 = 0xffffffff ;
for ( V_22 = 0 ; V_22 < V_1 -> V_27 ; V_22 ++ )
if ( V_1 -> V_28 [ V_22 ] . V_39 <= V_87 ) {
V_87 = V_1 -> V_28 [ V_22 ] . V_39 ;
V_79 = V_22 ;
}
} else {
V_87 = 0 ;
for ( V_22 = 0 ; V_22 < V_1 -> V_27 ; V_22 ++ )
if ( V_1 -> V_28 [ V_22 ] . V_50 >= V_87 ) {
V_87 = V_1 -> V_28 [ V_22 ] . V_50 ;
V_79 = V_22 ;
}
if ( V_87 == 0 ) {
static int V_91 = 0 ;
if ( ++ V_91 < 5 )
F_2 ( V_14 L_33
L_34 ) ;
else
F_15 ( L_33
L_34 ) ;
return - V_92 ;
}
}
V_5 = F_19 ( V_1 , V_79 , V_55 ) ;
if ( ! V_5 )
F_14 ( V_1 , V_55 ) ;
else
F_2 ( V_14 L_35 ) ;
return V_5 ;
}
static void F_21 ( T_1 * V_1 )
{
int V_22 ;
F_2 ( V_95 L_36 , V_1 -> V_49 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_27 ; V_22 ++ )
F_2 ( V_95 L_37
L_38 , V_22 ,
V_1 -> V_28 [ V_22 ] . V_32 >> V_1 -> V_2 . V_17 ,
V_1 -> V_28 [ V_22 ] . Free , V_1 -> V_28 [ V_22 ] . V_50 ) ;
}
static V_44 F_22 ( T_1 * V_1 )
{
T_5 V_96 , V_79 ;
V_44 V_97 ;
T_4 V_71 ;
int V_5 ;
V_96 = ( V_1 -> V_48 == 0xffff ) ? 0 : V_1 -> V_48 ;
V_79 = V_96 ;
do {
if ( V_1 -> V_28 [ V_79 ] . Free != 0 ) break;
if ( ++ V_79 == V_1 -> V_27 ) V_79 = 0 ;
} while ( V_79 != V_96 );
if ( V_1 -> V_28 [ V_79 ] . Free == 0 )
return 0 ;
if ( V_79 != V_1 -> V_48 ) {
V_1 -> V_48 = 0xffff ;
V_5 = V_1 -> V_8 . V_9 -> V_12 ( V_1 -> V_8 . V_9 ,
V_1 -> V_28 [ V_79 ] . V_32 + F_6 ( V_1 -> V_2 . V_51 ) ,
V_1 -> V_45 * sizeof( V_44 ) ,
& V_71 , ( V_73 * ) ( V_1 -> V_46 ) ) ;
if ( V_5 ) {
F_2 ( V_84 L_39 ) ;
return 0 ;
}
V_1 -> V_48 = V_79 ;
}
for ( V_97 = 0 ; V_97 < V_1 -> V_45 ; V_97 ++ )
if ( F_8 ( F_6 ( V_1 -> V_46 [ V_97 ] ) ) ) break;
if ( V_97 == V_1 -> V_45 ) {
#ifdef F_23
static int V_91 = 0 ;
if ( ++ V_91 == 1 )
F_21 ( V_1 ) ;
#endif
F_2 ( V_14 L_40 ) ;
return 0 ;
}
F_15 ( L_41 , V_97 , V_79 ) ;
return V_97 ;
}
static int F_24 ( T_1 * V_1 , T_7 V_98 ,
V_65 V_99 , V_65 V_100 )
{
V_44 V_101 , V_102 ;
V_65 V_22 ;
int V_5 ;
T_4 V_3 , V_71 ;
F_15 ( L_42 ,
V_1 , V_99 , V_100 ) ;
if ( ! ( V_1 -> V_40 & V_103 ) ) {
F_2 ( V_14 L_43 ) ;
return - V_92 ;
}
V_102 = 1 << V_1 -> V_2 . V_17 ;
for ( V_22 = 0 ; V_22 < V_100 ; V_22 ++ ) {
if ( ( ( V_99 + V_22 ) * V_74 ) >= F_6 ( V_1 -> V_2 . V_7 ) ) {
F_2 ( V_14 L_44 ) ;
return - V_92 ;
}
V_101 = V_1 -> V_43 [ V_99 + V_22 ] ;
if ( V_101 == 0xffffffff )
memset ( V_98 , 0 , V_74 ) ;
else {
V_3 = ( V_1 -> V_28 [ V_101 / V_102 ] . V_32
+ ( V_101 % V_102 ) ) ;
V_5 = V_1 -> V_8 . V_9 -> V_12 ( V_1 -> V_8 . V_9 , V_3 , V_74 ,
& V_71 , ( V_73 * ) V_98 ) ;
if ( V_5 ) {
F_2 ( V_84 L_45 ) ;
return V_5 ;
}
}
V_98 += V_74 ;
}
return 0 ;
}
static int F_25 ( T_1 * V_1 , V_44 V_101 ,
V_44 V_104 )
{
V_44 V_102 , V_97 , V_105 ;
#ifdef F_23
V_44 V_106 ;
#endif
T_5 V_79 ;
int V_5 ;
T_4 V_71 , V_3 ;
F_15 ( L_46 ,
V_1 , V_101 , V_104 ) ;
V_102 = 1 << V_1 -> V_2 . V_17 ;
V_79 = V_101 / V_102 ;
V_97 = ( V_101 % V_102 ) / V_74 ;
V_3 = ( V_1 -> V_28 [ V_79 ] . V_32 + V_97 * sizeof( V_44 ) +
F_6 ( V_1 -> V_2 . V_51 ) ) ;
#ifdef F_23
V_5 = V_1 -> V_8 . V_9 -> V_12 ( V_1 -> V_8 . V_9 , V_3 , sizeof( V_44 ) ,
& V_71 , ( V_73 * ) & V_106 ) ;
if ( V_5 ) {
F_2 ( V_84 L_47 , V_5 ) ;
return V_5 ;
}
V_106 = F_6 ( V_106 ) ;
if ( ( ( V_104 == 0xfffffffe ) && ! F_8 ( V_106 ) ) ||
( ( V_104 == 0 ) && ( F_9 ( V_106 ) != V_53 ) ) ||
( ! F_11 ( V_104 ) && ( V_106 != 0xfffffffe ) ) ) {
static int V_91 = 0 ;
if ( ++ V_91 < 5 ) {
F_2 ( V_14 L_48 ) ;
F_2 ( V_14 L_49
L_50 , V_101 , V_106 , V_104 ) ;
}
return - V_92 ;
}
#endif
V_105 = F_18 ( V_104 ) ;
if ( V_1 -> V_48 == V_79 ) {
#ifdef F_23
if ( F_6 ( V_1 -> V_46 [ V_97 ] ) != V_106 ) {
static int V_91 = 0 ;
if ( ++ V_91 < 5 ) {
F_2 ( V_14 L_51
L_52 ) ;
F_2 ( V_14 L_53
L_54 ,
F_6 ( V_1 -> V_46 [ V_97 ] ) , V_106 ) ;
}
return - V_92 ;
}
#endif
V_1 -> V_46 [ V_97 ] = V_105 ;
}
V_5 = V_1 -> V_8 . V_9 -> V_72 ( V_1 -> V_8 . V_9 , V_3 , sizeof( V_44 ) ,
& V_71 , ( V_73 * ) & V_105 ) ;
if ( V_5 ) {
F_2 ( V_14 L_55 ) ;
F_2 ( V_14 L_56 ,
V_101 , V_104 ) ;
}
return V_5 ;
}
static int F_26 ( T_1 * V_1 , T_7 V_98 ,
V_65 V_99 , V_65 V_100 )
{
V_44 V_102 , V_101 , V_104 , V_106 , V_97 ;
V_65 V_22 ;
int V_5 ;
T_4 V_71 , V_3 ;
F_15 ( L_57 ,
V_1 , V_99 , V_100 ) ;
if ( ! ( V_1 -> V_40 & V_103 ) ) {
F_2 ( V_14 L_43 ) ;
return - V_92 ;
}
while ( V_1 -> V_49 < V_100 ) {
V_5 = F_20 ( V_1 ) ;
if ( V_5 )
return V_5 ;
}
V_102 = 1 << V_1 -> V_2 . V_17 ;
V_104 = V_99 * V_74 | V_53 ;
for ( V_22 = 0 ; V_22 < V_100 ; V_22 ++ ) {
if ( V_104 >= F_6 ( V_1 -> V_2 . V_7 ) ) {
F_2 ( V_14 L_58 ) ;
return - V_92 ;
}
V_97 = F_22 ( V_1 ) ;
if ( V_97 == 0 ) {
static int V_91 = 0 ;
if ( ++ V_91 < 5 )
F_2 ( V_14 L_10
L_34 ) ;
return - V_107 ;
}
V_101 = V_1 -> V_48 * V_102 + V_97 * V_74 ;
V_1 -> V_28 [ V_1 -> V_48 ] . Free -- ;
V_1 -> V_49 -- ;
if ( F_25 ( V_1 , V_101 , 0xfffffffe ) )
return - V_92 ;
V_1 -> V_28 [ V_1 -> V_48 ] . V_50 ++ ;
V_3 = ( V_1 -> V_28 [ V_1 -> V_48 ] . V_32 +
V_97 * V_74 ) ;
V_5 = V_1 -> V_8 . V_9 -> V_72 ( V_1 -> V_8 . V_9 , V_3 , V_74 , & V_71 ,
V_98 ) ;
if ( V_5 ) {
F_2 ( V_14 L_59 ) ;
F_2 ( V_14 L_60
L_61 , V_101 , V_104 ,
V_3 ) ;
return - V_92 ;
}
V_106 = V_1 -> V_43 [ V_99 + V_22 ] ;
if ( V_106 != 0xffffffff ) {
V_1 -> V_43 [ V_99 + V_22 ] = 0xffffffff ;
V_1 -> V_28 [ V_106 / V_102 ] . V_50 ++ ;
if ( F_25 ( V_1 , V_106 , 0 ) )
return - V_92 ;
}
if ( F_25 ( V_1 , V_101 , V_104 ) )
return - V_92 ;
V_1 -> V_43 [ V_99 + V_22 ] = V_101 ;
V_1 -> V_28 [ V_1 -> V_48 ] . V_50 -- ;
V_98 += V_74 ;
V_104 += V_74 ;
}
return 0 ;
}
static int F_27 ( struct V_108 * V_109 , struct V_110 * V_111 )
{
T_1 * V_1 = ( void * ) V_109 ;
V_65 V_112 ;
V_112 = F_6 ( V_1 -> V_2 . V_7 ) / V_74 ;
V_111 -> V_113 = 1 ;
V_111 -> V_114 = 8 ;
V_111 -> V_115 = V_112 >> 3 ;
return 0 ;
}
static int F_28 ( struct V_108 * V_109 ,
unsigned long V_116 , char * V_78 )
{
return F_24 ( ( void * ) V_109 , V_78 , V_116 , 1 ) ;
}
static int F_29 ( struct V_108 * V_109 ,
unsigned long V_116 , char * V_78 )
{
return F_26 ( ( void * ) V_109 , V_78 , V_116 , 1 ) ;
}
static int F_30 ( struct V_108 * V_109 ,
unsigned long V_99 , unsigned V_117 )
{
T_1 * V_1 = ( void * ) V_109 ;
V_44 V_102 = 1 << V_1 -> V_2 . V_17 ;
F_15 ( L_62 ,
V_99 , V_117 ) ;
while ( V_117 ) {
V_44 V_106 = V_1 -> V_43 [ V_99 ] ;
if ( V_106 != 0xffffffff ) {
V_1 -> V_43 [ V_99 ] = 0xffffffff ;
V_1 -> V_28 [ V_106 / V_102 ] . V_50 ++ ;
if ( F_25 ( V_1 , V_106 , 0 ) )
return - V_92 ;
}
V_117 -- ;
V_99 ++ ;
}
return 0 ;
}
static void F_31 ( T_1 * V_1 )
{
F_13 ( V_1 -> V_43 ) ;
V_1 -> V_43 = NULL ;
F_12 ( V_1 -> V_118 ) ;
V_1 -> V_118 = NULL ;
F_12 ( V_1 -> V_28 ) ;
V_1 -> V_28 = NULL ;
F_12 ( V_1 -> V_33 ) ;
V_1 -> V_33 = NULL ;
F_12 ( V_1 -> V_46 ) ;
V_1 -> V_46 = NULL ;
}
static void F_32 ( struct V_119 * V_120 , struct V_121 * V_9 )
{
T_1 * V_122 ;
V_122 = F_33 ( sizeof( T_1 ) , V_30 ) ;
if ( ! V_122 ) {
F_2 ( V_84 L_63 ,
V_9 -> V_123 ) ;
return;
}
V_122 -> V_8 . V_9 = V_9 ;
if ( ( F_1 ( V_122 ) == 0 ) &&
( F_4 ( V_122 ) == 0 ) ) {
V_122 -> V_40 = V_103 ;
#ifdef F_34
F_2 ( V_124 L_64 ,
F_6 ( V_122 -> V_2 . V_7 ) >> 10 ) ;
#endif
V_122 -> V_8 . V_10 = F_6 ( V_122 -> V_2 . V_7 ) >> 9 ;
V_122 -> V_8 . V_120 = V_120 ;
V_122 -> V_8 . V_125 = - 1 ;
if ( ! F_35 ( ( void * ) V_122 ) )
return;
}
F_31 ( V_122 ) ;
F_12 ( V_122 ) ;
}
static void F_36 ( struct V_108 * V_109 )
{
F_37 ( V_109 ) ;
F_31 ( ( T_1 * ) V_109 ) ;
}
static int T_8 F_38 ( void )
{
return F_39 ( & V_126 ) ;
}
static void T_9 F_40 ( void )
{
F_41 ( & V_126 ) ;
}
