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
V_6 = F_2 ( V_1 -> V_8 . V_9 , V_3 , sizeof( V_2 ) , & V_5 ,
( unsigned char * ) & V_2 ) ;
if ( V_6 )
return V_6 ;
if ( strcmp ( V_2 . V_12 + 3 , L_1 ) == 0 ) break;
}
if ( V_3 == V_4 ) {
F_3 ( V_13 L_2 ) ;
return - V_14 ;
}
if ( V_2 . V_15 != 9 ||
( V_2 . V_16 < 10 ) || ( V_2 . V_16 > 31 ) ||
( V_2 . V_17 >= F_4 ( V_2 . V_18 ) ) ) {
F_3 ( V_13 L_3 ) ;
return - 1 ;
}
if ( ( 1 << V_2 . V_16 ) != V_1 -> V_8 . V_9 -> V_11 ) {
F_3 ( V_13 L_4 ,
1 << V_2 . V_16 , V_1 -> V_8 . V_9 -> V_11 ) ;
return - 1 ;
}
V_1 -> V_2 = V_2 ;
return 0 ;
}
static int F_5 ( T_1 * V_1 )
{
T_2 V_2 ;
T_5 V_19 , V_20 , V_21 ;
unsigned V_22 , V_23 ;
int V_24 , V_5 = - 1 ;
T_6 V_25 ;
T_3 V_3 ;
V_1 -> V_26 = F_4 ( V_1 -> V_2 . V_18 ) -
V_1 -> V_2 . V_17 ;
V_1 -> V_27 = F_6 ( V_1 -> V_26 * sizeof( struct V_28 ) ,
V_29 ) ;
if ( ! V_1 -> V_27 )
goto V_30;
for ( V_21 = 0 ; V_21 < V_1 -> V_26 ; V_21 ++ )
V_1 -> V_27 [ V_21 ] . V_31 = 0xffffffff ;
V_1 -> V_32 =
F_6 ( V_1 -> V_2 . V_17 * sizeof( struct V_33 ) ,
V_29 ) ;
if ( ! V_1 -> V_32 )
goto V_34;
V_19 = V_20 = 0 ;
for ( V_21 = 0 ; V_21 < F_4 ( V_1 -> V_2 . V_18 ) ; V_21 ++ ) {
V_3 = ( ( V_21 + F_4 ( V_1 -> V_2 . V_35 ) )
<< V_1 -> V_2 . V_16 ) ;
V_5 = F_2 ( V_1 -> V_8 . V_9 , V_3 , sizeof( V_2 ) , & V_25 ,
( unsigned char * ) & V_2 ) ;
if ( V_5 )
goto V_36;
V_5 = - 1 ;
V_24 = ( strcmp ( V_2 . V_12 + 3 , L_1 ) == 0 ) ;
if ( V_24 && ( F_4 ( V_2 . V_37 ) < V_1 -> V_26 ) &&
( V_1 -> V_27 [ F_4 ( V_2 . V_37 ) ] . V_31 == 0xffffffff ) ) {
V_1 -> V_27 [ F_4 ( V_2 . V_37 ) ] . V_31 = V_3 ;
V_1 -> V_27 [ F_4 ( V_2 . V_37 ) ] . V_38 =
F_7 ( V_2 . V_38 ) ;
V_19 ++ ;
} else {
if ( V_20 == V_1 -> V_2 . V_17 ) {
F_3 ( V_13 L_5
L_6 ) ;
goto V_36;
}
if ( V_24 && ( F_4 ( V_2 . V_37 ) == 0xffff ) ) {
V_1 -> V_32 [ V_20 ] . V_39 = V_40 ;
V_1 -> V_32 [ V_20 ] . V_38 = F_7 ( V_2 . V_38 ) ;
} else {
V_1 -> V_32 [ V_20 ] . V_39 = V_41 ;
V_1 -> V_32 [ V_20 ] . V_38 =
F_7 ( V_1 -> V_2 . V_38 ) ;
}
V_1 -> V_32 [ V_20 ] . V_31 = V_3 ;
V_20 ++ ;
}
}
V_2 = V_1 -> V_2 ;
if ( ( V_20 != V_2 . V_17 ) ||
( V_19 + V_20 != F_4 ( V_2 . V_18 ) ) ) {
F_3 ( V_13 L_7
L_8 ) ;
goto V_36;
}
V_22 = F_7 ( V_2 . V_7 ) >> V_2 . V_15 ;
V_1 -> V_42 = F_8 ( V_22 * sizeof( V_43 ) ) ;
if ( ! V_1 -> V_42 )
goto V_36;
memset ( V_1 -> V_42 , 0xff , V_22 * sizeof( V_43 ) ) ;
V_1 -> V_44 = ( 1 << V_2 . V_16 ) >> V_2 . V_15 ;
V_1 -> V_45 = F_6 ( V_1 -> V_44 * sizeof( V_43 ) ,
V_29 ) ;
if ( ! V_1 -> V_45 )
goto V_46;
V_1 -> V_47 = 0xffff ;
V_1 -> V_48 = 0 ;
for ( V_21 = 0 ; V_21 < V_1 -> V_26 ; V_21 ++ ) {
V_1 -> V_27 [ V_21 ] . Free = 0 ;
V_1 -> V_27 [ V_21 ] . V_49 = 0 ;
V_3 = V_1 -> V_27 [ V_21 ] . V_31 + F_7 ( V_2 . V_50 ) ;
V_5 = F_2 ( V_1 -> V_8 . V_9 , V_3 ,
V_1 -> V_44 * sizeof( V_43 ) , & V_25 ,
( unsigned char * ) V_1 -> V_45 ) ;
if ( V_5 )
goto V_51;
for ( V_23 = 0 ; V_23 < V_1 -> V_44 ; V_23 ++ ) {
if ( F_9 ( F_7 ( V_1 -> V_45 [ V_23 ] ) ) ) {
V_1 -> V_27 [ V_21 ] . Free ++ ;
V_1 -> V_48 ++ ;
} else if ( ( F_10 ( F_7 ( V_1 -> V_45 [ V_23 ] ) ) == V_52 ) &&
( F_11 ( F_7 ( V_1 -> V_45 [ V_23 ] ) ) < V_22 ) )
V_1 -> V_42 [ F_11 ( F_7 ( V_1 -> V_45 [ V_23 ] ) ) ] =
( V_21 << V_2 . V_16 ) + ( V_23 << V_2 . V_15 ) ;
else if ( F_12 ( F_7 ( V_1 -> V_45 [ V_23 ] ) ) )
V_1 -> V_27 [ V_21 ] . V_49 ++ ;
}
}
V_5 = 0 ;
goto V_30;
V_51:
F_13 ( V_1 -> V_45 ) ;
V_46:
F_14 ( V_1 -> V_42 ) ;
V_36:
F_13 ( V_1 -> V_32 ) ;
V_34:
F_13 ( V_1 -> V_27 ) ;
V_30:
return V_5 ;
}
static int F_15 ( T_1 * V_1 ,
T_5 V_53 )
{
int V_5 ;
struct V_33 * V_54 ;
struct V_55 * V_56 ;
V_54 = & V_1 -> V_32 [ V_53 ] ;
F_16 ( L_9 , V_54 -> V_31 ) ;
V_54 -> V_39 = V_57 ;
V_56 = F_6 ( sizeof( struct V_55 ) , V_29 ) ;
if ( ! V_56 )
return - V_58 ;
V_56 -> V_9 = V_1 -> V_8 . V_9 ;
V_56 -> V_59 = V_60 ;
V_56 -> V_61 = V_54 -> V_31 ;
V_56 -> V_62 = 1 << V_1 -> V_2 . V_16 ;
V_56 -> V_63 = ( V_64 ) V_1 ;
V_5 = F_17 ( V_1 -> V_8 . V_9 , V_56 ) ;
if ( ! V_5 )
V_54 -> V_38 ++ ;
else
F_13 ( V_56 ) ;
return V_5 ;
}
static void V_60 ( struct V_55 * V_56 )
{
T_1 * V_1 ;
struct V_33 * V_54 ;
int V_21 ;
V_1 = ( T_1 * ) ( V_56 -> V_63 ) ;
for ( V_21 = 0 ; V_21 < V_1 -> V_2 . V_17 ; V_21 ++ )
if ( V_1 -> V_32 [ V_21 ] . V_31 == V_56 -> V_61 ) break;
if ( V_21 == V_1 -> V_2 . V_17 ) {
F_3 ( V_13 L_10
L_11 ) ;
return;
}
V_54 = & V_1 -> V_32 [ V_21 ] ;
if ( V_56 -> V_39 == V_65 )
V_54 -> V_39 = V_66 ;
else {
V_54 -> V_39 = V_67 ;
F_3 ( V_13 L_12 ,
V_56 -> V_39 ) ;
}
F_13 ( V_56 ) ;
}
static int F_18 ( T_1 * V_1 , int V_21 )
{
T_2 V_2 ;
struct V_33 * V_54 ;
int V_68 , V_5 ;
V_43 V_69 ;
T_6 V_70 ;
T_3 V_3 ;
V_54 = & V_1 -> V_32 [ V_21 ] ;
V_54 -> V_39 = V_67 ;
F_16 ( L_13 , V_54 -> V_31 ) ;
V_2 = V_1 -> V_2 ;
V_2 . V_37 = F_19 ( 0xffff ) ;
V_2 . V_38 = F_20 ( V_54 -> V_38 ) ;
V_5 = F_21 ( V_1 -> V_8 . V_9 , V_54 -> V_31 , sizeof( V_2 ) , & V_70 ,
( V_71 * ) & V_2 ) ;
if ( V_5 ) {
return V_5 ;
}
V_68 = ( V_1 -> V_44 * sizeof( V_43 ) +
F_7 ( V_1 -> V_2 . V_50 ) + V_72 - 1 ) / V_72 ;
V_3 = V_54 -> V_31 + F_7 ( V_1 -> V_2 . V_50 ) ;
V_69 = F_20 ( V_73 ) ;
for ( V_21 = 0 ; V_21 < V_68 ; V_21 ++ , V_3 += sizeof( V_43 ) ) {
V_5 = F_21 ( V_1 -> V_8 . V_9 , V_3 , sizeof( V_43 ) , & V_70 ,
( V_71 * ) & V_69 ) ;
if ( V_5 )
return V_5 ;
}
V_54 -> V_39 = V_40 ;
return 0 ;
}
static int F_22 ( T_1 * V_1 , T_5 V_74 ,
T_5 V_75 )
{
V_71 V_76 [ V_72 ] ;
struct V_28 * V_77 ;
struct V_33 * V_54 ;
V_43 V_78 , V_79 , free , V_21 ;
T_5 V_80 ;
int V_5 ;
T_6 V_70 ;
T_3 V_3 ;
T_5 V_81 = F_19 ( V_74 ) ;
V_77 = & V_1 -> V_27 [ V_74 ] ;
V_54 = & V_1 -> V_32 [ V_75 ] ;
F_16 ( L_14 ,
V_77 -> V_31 , V_54 -> V_31 ) ;
if ( V_1 -> V_47 != V_74 ) {
V_3 = V_77 -> V_31 + F_7 ( V_1 -> V_2 . V_50 ) ;
V_5 = F_2 ( V_1 -> V_8 . V_9 , V_3 ,
V_1 -> V_44 * sizeof( V_43 ) , & V_70 ,
( V_71 * ) ( V_1 -> V_45 ) ) ;
V_1 -> V_47 = 0xffff ;
if ( V_5 ) {
F_3 ( V_82 L_15 ) ;
return V_5 ;
}
}
V_54 -> V_39 = V_41 ;
V_3 = V_54 -> V_31 + 20 ;
V_80 = F_19 ( 0x7fff ) ;
V_5 = F_21 ( V_1 -> V_8 . V_9 , V_3 , sizeof( T_5 ) , & V_70 ,
( V_71 * ) & V_80 ) ;
if ( V_5 ) {
F_3 ( V_82 L_16 ) ;
return V_5 ;
}
V_78 = V_77 -> V_31 ; V_79 = V_54 -> V_31 ;
free = 0 ;
V_5 = 0 ;
for ( V_21 = 0 ; V_21 < V_1 -> V_44 ; V_21 ++ ) {
switch ( F_10 ( F_7 ( V_1 -> V_45 [ V_21 ] ) ) ) {
case V_73 :
break;
case V_52 :
case V_83 :
V_5 = F_2 ( V_1 -> V_8 . V_9 , V_78 , V_72 , & V_70 ,
( V_71 * ) V_76 ) ;
if ( V_5 ) {
F_3 ( V_82 L_17 ) ;
return V_5 ;
}
V_5 = F_21 ( V_1 -> V_8 . V_9 , V_79 , V_72 , & V_70 ,
( V_71 * ) V_76 ) ;
if ( V_5 ) {
F_3 ( V_82 L_18 ) ;
return V_5 ;
}
break;
default:
V_1 -> V_45 [ V_21 ] = F_20 ( 0xffffffff ) ;
free ++ ;
break;
}
V_78 += V_72 ;
V_79 += V_72 ;
}
V_5 = F_21 ( V_1 -> V_8 . V_9 ,
V_54 -> V_31 + F_7 ( V_1 -> V_2 . V_50 ) ,
V_1 -> V_44 * sizeof( V_84 ) ,
& V_70 ,
( V_71 * ) V_1 -> V_45 ) ;
if ( V_5 ) {
F_3 ( V_82 L_19 ) ;
return V_5 ;
}
V_5 = F_21 ( V_1 -> V_8 . V_9 , V_54 -> V_31 + 20 , sizeof( T_5 ) ,
& V_70 , ( V_71 * ) & V_81 ) ;
if ( V_5 ) {
F_3 ( V_82 L_20 ) ;
return V_5 ;
}
F_23 ( V_54 -> V_38 , V_77 -> V_38 ) ;
F_23 ( V_54 -> V_31 , V_77 -> V_31 ) ;
V_1 -> V_48 -= V_77 -> Free ;
V_1 -> V_48 += free ;
V_77 -> Free = free ;
V_77 -> V_49 = 0 ;
V_1 -> V_47 = V_74 ;
return 0 ;
}
static int F_24 ( T_1 * V_1 )
{
T_5 V_21 , V_77 , V_54 ;
V_43 V_85 ;
int V_86 , V_5 ;
F_16 ( L_21 ) ;
F_16 ( L_22 , V_1 -> V_2 . V_17 ) ;
V_85 = 0xffffffff ; V_54 = 0xffff ;
do {
V_86 = 0 ;
for ( V_21 = 0 ; V_21 < V_1 -> V_2 . V_17 ; V_21 ++ ) {
int V_87 = 0 ;
if ( V_1 -> V_32 [ V_21 ] . V_39 == V_41 ) {
F_16 ( L_23 , V_21 ) ;
V_87 = 1 ;
F_15 ( V_1 , V_21 ) ;
}
if ( V_1 -> V_32 [ V_21 ] . V_39 == V_57 ) {
F_16 ( L_24 , V_21 ) ;
V_87 = 1 ;
V_86 = 1 ;
}
else if ( V_1 -> V_32 [ V_21 ] . V_39 == V_66 ) {
F_16 ( L_25 , V_21 ) ;
V_87 = 1 ;
F_18 ( V_1 , V_21 ) ;
}
if ( V_1 -> V_32 [ V_21 ] . V_39 == V_40 ) {
F_16 ( L_26 , V_21 ) ;
V_87 = 1 ;
if ( V_1 -> V_32 [ V_21 ] . V_38 <= V_85 ) {
V_85 = V_1 -> V_32 [ V_21 ] . V_38 ;
V_54 = V_21 ;
}
}
if ( ! V_87 )
F_16 ( L_27 , V_21 , V_1 -> V_32 [ V_21 ] . V_39 ) ;
}
if ( V_54 == 0xffff ) {
if ( V_86 ) {
F_16 ( L_28
L_29 ) ;
F_25 ( V_1 -> V_8 . V_9 ) ;
} else {
static int V_88 = 0 ;
if ( ++ V_88 < 5 )
F_3 ( V_13 L_30
L_31 ) ;
else
F_16 ( L_30
L_31 ) ;
return - V_89 ;
}
}
} while ( V_54 == 0xffff );
V_77 = 0 ;
if ( ( V_90 % V_91 ) == 0 ) {
F_16 ( L_32 ) ;
V_85 = 0xffffffff ;
for ( V_21 = 0 ; V_21 < V_1 -> V_26 ; V_21 ++ )
if ( V_1 -> V_27 [ V_21 ] . V_38 <= V_85 ) {
V_85 = V_1 -> V_27 [ V_21 ] . V_38 ;
V_77 = V_21 ;
}
} else {
V_85 = 0 ;
for ( V_21 = 0 ; V_21 < V_1 -> V_26 ; V_21 ++ )
if ( V_1 -> V_27 [ V_21 ] . V_49 >= V_85 ) {
V_85 = V_1 -> V_27 [ V_21 ] . V_49 ;
V_77 = V_21 ;
}
if ( V_85 == 0 ) {
static int V_88 = 0 ;
if ( ++ V_88 < 5 )
F_3 ( V_13 L_33
L_34 ) ;
else
F_16 ( L_33
L_34 ) ;
return - V_89 ;
}
}
V_5 = F_22 ( V_1 , V_77 , V_54 ) ;
if ( ! V_5 )
F_15 ( V_1 , V_54 ) ;
else
F_3 ( V_13 L_35 ) ;
return V_5 ;
}
static void F_26 ( T_1 * V_1 )
{
int V_21 ;
F_3 ( V_92 L_36 , V_1 -> V_48 ) ;
for ( V_21 = 0 ; V_21 < V_1 -> V_26 ; V_21 ++ )
F_3 ( V_92 L_37
L_38 , V_21 ,
V_1 -> V_27 [ V_21 ] . V_31 >> V_1 -> V_2 . V_16 ,
V_1 -> V_27 [ V_21 ] . Free , V_1 -> V_27 [ V_21 ] . V_49 ) ;
}
static V_43 F_27 ( T_1 * V_1 )
{
T_5 V_93 , V_77 ;
V_43 V_94 ;
T_4 V_70 ;
int V_5 ;
V_93 = ( V_1 -> V_47 == 0xffff ) ? 0 : V_1 -> V_47 ;
V_77 = V_93 ;
do {
if ( V_1 -> V_27 [ V_77 ] . Free != 0 ) break;
if ( ++ V_77 == V_1 -> V_26 ) V_77 = 0 ;
} while ( V_77 != V_93 );
if ( V_1 -> V_27 [ V_77 ] . Free == 0 )
return 0 ;
if ( V_77 != V_1 -> V_47 ) {
V_1 -> V_47 = 0xffff ;
V_5 = F_2 ( V_1 -> V_8 . V_9 ,
V_1 -> V_27 [ V_77 ] . V_31 + F_7 ( V_1 -> V_2 . V_50 ) ,
V_1 -> V_44 * sizeof( V_43 ) ,
& V_70 ,
( V_71 * ) ( V_1 -> V_45 ) ) ;
if ( V_5 ) {
F_3 ( V_82 L_39 ) ;
return 0 ;
}
V_1 -> V_47 = V_77 ;
}
for ( V_94 = 0 ; V_94 < V_1 -> V_44 ; V_94 ++ )
if ( F_9 ( F_7 ( V_1 -> V_45 [ V_94 ] ) ) ) break;
if ( V_94 == V_1 -> V_44 ) {
#ifdef F_28
static int V_88 = 0 ;
if ( ++ V_88 == 1 )
F_26 ( V_1 ) ;
#endif
F_3 ( V_13 L_40 ) ;
return 0 ;
}
F_16 ( L_41 , V_94 , V_77 ) ;
return V_94 ;
}
static int F_29 ( T_1 * V_1 , T_7 V_95 ,
V_64 V_96 , V_64 V_97 )
{
V_43 V_98 , V_99 ;
V_64 V_21 ;
int V_5 ;
T_4 V_3 , V_70 ;
F_16 ( L_42 ,
V_1 , V_96 , V_97 ) ;
if ( ! ( V_1 -> V_39 & V_100 ) ) {
F_3 ( V_13 L_43 ) ;
return - V_89 ;
}
V_99 = 1 << V_1 -> V_2 . V_16 ;
for ( V_21 = 0 ; V_21 < V_97 ; V_21 ++ ) {
if ( ( ( V_96 + V_21 ) * V_72 ) >= F_7 ( V_1 -> V_2 . V_7 ) ) {
F_3 ( V_13 L_44 ) ;
return - V_89 ;
}
V_98 = V_1 -> V_42 [ V_96 + V_21 ] ;
if ( V_98 == 0xffffffff )
memset ( V_95 , 0 , V_72 ) ;
else {
V_3 = ( V_1 -> V_27 [ V_98 / V_99 ] . V_31
+ ( V_98 % V_99 ) ) ;
V_5 = F_2 ( V_1 -> V_8 . V_9 , V_3 , V_72 , & V_70 ,
( V_71 * ) V_95 ) ;
if ( V_5 ) {
F_3 ( V_82 L_45 ) ;
return V_5 ;
}
}
V_95 += V_72 ;
}
return 0 ;
}
static int F_30 ( T_1 * V_1 , V_43 V_98 ,
V_43 V_101 )
{
V_43 V_99 , V_94 , V_102 ;
#ifdef F_28
V_43 V_103 ;
#endif
T_5 V_77 ;
int V_5 ;
T_4 V_70 , V_3 ;
F_16 ( L_46 ,
V_1 , V_98 , V_101 ) ;
V_99 = 1 << V_1 -> V_2 . V_16 ;
V_77 = V_98 / V_99 ;
V_94 = ( V_98 % V_99 ) / V_72 ;
V_3 = ( V_1 -> V_27 [ V_77 ] . V_31 + V_94 * sizeof( V_43 ) +
F_7 ( V_1 -> V_2 . V_50 ) ) ;
#ifdef F_28
V_5 = F_2 ( V_1 -> V_8 . V_9 , V_3 , sizeof( V_43 ) , & V_70 ,
( V_71 * ) & V_103 ) ;
if ( V_5 ) {
F_3 ( V_82 L_47 , V_5 ) ;
return V_5 ;
}
V_103 = F_7 ( V_103 ) ;
if ( ( ( V_101 == 0xfffffffe ) && ! F_9 ( V_103 ) ) ||
( ( V_101 == 0 ) && ( F_10 ( V_103 ) != V_52 ) ) ||
( ! F_12 ( V_101 ) && ( V_103 != 0xfffffffe ) ) ) {
static int V_88 = 0 ;
if ( ++ V_88 < 5 ) {
F_3 ( V_13 L_48 ) ;
F_3 ( V_13 L_49
L_50 , V_98 , V_103 , V_101 ) ;
}
return - V_89 ;
}
#endif
V_102 = F_20 ( V_101 ) ;
if ( V_1 -> V_47 == V_77 ) {
#ifdef F_28
if ( F_7 ( V_1 -> V_45 [ V_94 ] ) != V_103 ) {
static int V_88 = 0 ;
if ( ++ V_88 < 5 ) {
F_3 ( V_13 L_51
L_52 ) ;
F_3 ( V_13 L_53
L_54 ,
F_7 ( V_1 -> V_45 [ V_94 ] ) , V_103 ) ;
}
return - V_89 ;
}
#endif
V_1 -> V_45 [ V_94 ] = V_102 ;
}
V_5 = F_21 ( V_1 -> V_8 . V_9 , V_3 , sizeof( V_43 ) , & V_70 ,
( V_71 * ) & V_102 ) ;
if ( V_5 ) {
F_3 ( V_13 L_55 ) ;
F_3 ( V_13 L_56 ,
V_98 , V_101 ) ;
}
return V_5 ;
}
static int F_31 ( T_1 * V_1 , T_7 V_95 ,
V_64 V_96 , V_64 V_97 )
{
V_43 V_99 , V_98 , V_101 , V_103 , V_94 ;
V_64 V_21 ;
int V_5 ;
T_4 V_70 , V_3 ;
F_16 ( L_57 ,
V_1 , V_96 , V_97 ) ;
if ( ! ( V_1 -> V_39 & V_100 ) ) {
F_3 ( V_13 L_43 ) ;
return - V_89 ;
}
while ( V_1 -> V_48 < V_97 ) {
V_5 = F_24 ( V_1 ) ;
if ( V_5 )
return V_5 ;
}
V_99 = 1 << V_1 -> V_2 . V_16 ;
V_101 = V_96 * V_72 | V_52 ;
for ( V_21 = 0 ; V_21 < V_97 ; V_21 ++ ) {
if ( V_101 >= F_7 ( V_1 -> V_2 . V_7 ) ) {
F_3 ( V_13 L_58 ) ;
return - V_89 ;
}
V_94 = F_27 ( V_1 ) ;
if ( V_94 == 0 ) {
static int V_88 = 0 ;
if ( ++ V_88 < 5 )
F_3 ( V_13 L_10
L_34 ) ;
return - V_104 ;
}
V_98 = V_1 -> V_47 * V_99 + V_94 * V_72 ;
V_1 -> V_27 [ V_1 -> V_47 ] . Free -- ;
V_1 -> V_48 -- ;
if ( F_30 ( V_1 , V_98 , 0xfffffffe ) )
return - V_89 ;
V_1 -> V_27 [ V_1 -> V_47 ] . V_49 ++ ;
V_3 = ( V_1 -> V_27 [ V_1 -> V_47 ] . V_31 +
V_94 * V_72 ) ;
V_5 = F_21 ( V_1 -> V_8 . V_9 , V_3 , V_72 , & V_70 , V_95 ) ;
if ( V_5 ) {
F_3 ( V_13 L_59 ) ;
F_3 ( V_13 L_60
L_61 , V_98 , V_101 ,
V_3 ) ;
return - V_89 ;
}
V_103 = V_1 -> V_42 [ V_96 + V_21 ] ;
if ( V_103 != 0xffffffff ) {
V_1 -> V_42 [ V_96 + V_21 ] = 0xffffffff ;
V_1 -> V_27 [ V_103 / V_99 ] . V_49 ++ ;
if ( F_30 ( V_1 , V_103 , 0 ) )
return - V_89 ;
}
if ( F_30 ( V_1 , V_98 , V_101 ) )
return - V_89 ;
V_1 -> V_42 [ V_96 + V_21 ] = V_98 ;
V_1 -> V_27 [ V_1 -> V_47 ] . V_49 -- ;
V_95 += V_72 ;
V_101 += V_72 ;
}
return 0 ;
}
static int F_32 ( struct V_105 * V_106 , struct V_107 * V_108 )
{
T_1 * V_1 = ( void * ) V_106 ;
V_64 V_109 ;
V_109 = F_7 ( V_1 -> V_2 . V_7 ) / V_72 ;
V_108 -> V_110 = 1 ;
V_108 -> V_111 = 8 ;
V_108 -> V_112 = V_109 >> 3 ;
return 0 ;
}
static int F_33 ( struct V_105 * V_106 ,
unsigned long V_113 , char * V_76 )
{
return F_29 ( ( void * ) V_106 , V_76 , V_113 , 1 ) ;
}
static int F_34 ( struct V_105 * V_106 ,
unsigned long V_113 , char * V_76 )
{
return F_31 ( ( void * ) V_106 , V_76 , V_113 , 1 ) ;
}
static int F_35 ( struct V_105 * V_106 ,
unsigned long V_96 , unsigned V_114 )
{
T_1 * V_1 = ( void * ) V_106 ;
V_43 V_99 = 1 << V_1 -> V_2 . V_16 ;
F_16 ( L_62 ,
V_96 , V_114 ) ;
while ( V_114 ) {
V_43 V_103 = V_1 -> V_42 [ V_96 ] ;
if ( V_103 != 0xffffffff ) {
V_1 -> V_42 [ V_96 ] = 0xffffffff ;
V_1 -> V_27 [ V_103 / V_99 ] . V_49 ++ ;
if ( F_30 ( V_1 , V_103 , 0 ) )
return - V_89 ;
}
V_114 -- ;
V_96 ++ ;
}
return 0 ;
}
static void F_36 ( T_1 * V_1 )
{
F_14 ( V_1 -> V_42 ) ;
V_1 -> V_42 = NULL ;
F_13 ( V_1 -> V_27 ) ;
V_1 -> V_27 = NULL ;
F_13 ( V_1 -> V_32 ) ;
V_1 -> V_32 = NULL ;
F_13 ( V_1 -> V_45 ) ;
V_1 -> V_45 = NULL ;
}
static void F_37 ( struct V_115 * V_116 , struct V_117 * V_9 )
{
T_1 * V_118 ;
V_118 = F_38 ( sizeof( T_1 ) , V_29 ) ;
if ( ! V_118 ) {
F_3 ( V_82 L_63 ,
V_9 -> V_119 ) ;
return;
}
V_118 -> V_8 . V_9 = V_9 ;
if ( ( F_1 ( V_118 ) == 0 ) &&
( F_5 ( V_118 ) == 0 ) ) {
V_118 -> V_39 = V_100 ;
#ifdef F_39
F_3 ( V_120 L_64 ,
F_7 ( V_118 -> V_2 . V_7 ) >> 10 ) ;
#endif
V_118 -> V_8 . V_10 = F_7 ( V_118 -> V_2 . V_7 ) >> 9 ;
V_118 -> V_8 . V_116 = V_116 ;
V_118 -> V_8 . V_121 = - 1 ;
if ( ! F_40 ( ( void * ) V_118 ) )
return;
}
F_13 ( V_118 ) ;
}
static void F_41 ( struct V_105 * V_106 )
{
F_42 ( V_106 ) ;
F_36 ( ( T_1 * ) V_106 ) ;
}
static int T_8 F_43 ( void )
{
return F_44 ( & V_122 ) ;
}
static void T_9 F_45 ( void )
{
F_46 ( & V_122 ) ;
}
