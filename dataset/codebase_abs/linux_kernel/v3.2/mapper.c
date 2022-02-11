int F_1 ( struct V_1 * V_2 , int V_3 , int type , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_7 [ V_5 ] &&
V_2 -> V_7 [ V_5 ] -> V_8 . V_3 == V_3 &&
V_2 -> V_7 [ V_5 ] -> V_8 . type == type &&
V_2 -> V_7 [ V_5 ] -> V_8 . V_9 <= V_4 &&
V_2 -> V_7 [ V_5 ] -> V_8 . V_10 >= V_4 )
return V_5 ;
}
return - 1 ;
}
static int F_2 ( struct V_11 * V_12 ,
int V_13 , int V_14 )
{
unsigned V_15 = V_14 % V_12 -> V_4 ;
unsigned V_5 , V_16 ;
if ( V_12 -> V_17 != V_13 || V_12 -> V_18 == 0 ) {
F_3 ( L_1 , V_12 -> V_19 , V_13 ) ;
V_12 -> V_17 = V_13 ;
if ( V_15 == 0 ) {
V_16 = F_4 ( V_12 -> V_20 , V_13 , V_12 -> V_19 , 0 ) %
V_12 -> V_4 ;
V_12 -> V_21 [ 0 ] = V_16 ;
V_12 -> V_18 = 0xffff ;
goto V_22;
}
for ( V_5 = 0 ; V_5 < V_12 -> V_4 ; V_5 ++ )
V_12 -> V_21 [ V_5 ] = V_5 ;
V_12 -> V_18 = 0 ;
} else if ( V_12 -> V_18 == 0xffff ) {
for ( V_5 = 1 ; V_5 < V_12 -> V_4 ; V_5 ++ )
V_12 -> V_21 [ V_5 ] = V_5 ;
V_12 -> V_21 [ V_12 -> V_21 [ 0 ] ] = 0 ;
V_12 -> V_18 = 1 ;
}
for ( V_5 = 0 ; V_5 < V_12 -> V_18 ; V_5 ++ )
F_3 ( L_2 , V_5 , V_12 -> V_21 [ V_5 ] ) ;
while ( V_12 -> V_18 <= V_15 ) {
unsigned V_23 = V_12 -> V_18 ;
if ( V_23 < V_12 -> V_4 - 1 ) {
V_5 = F_4 ( V_12 -> V_20 , V_13 , V_12 -> V_19 , V_23 ) %
( V_12 -> V_4 - V_23 ) ;
if ( V_5 ) {
unsigned V_24 = V_12 -> V_21 [ V_23 + V_5 ] ;
V_12 -> V_21 [ V_23 + V_5 ] = V_12 -> V_21 [ V_23 ] ;
V_12 -> V_21 [ V_23 ] = V_24 ;
}
F_3 ( L_3 , V_23 , V_23 + V_5 ) ;
}
V_12 -> V_18 ++ ;
}
for ( V_5 = 0 ; V_5 < V_12 -> V_4 ; V_5 ++ )
F_3 ( L_4 , V_5 , V_12 -> V_21 [ V_5 ] ) ;
V_16 = V_12 -> V_21 [ V_15 ] ;
V_22:
F_3 ( L_5 , V_12 -> V_19 ,
V_12 -> V_4 , V_13 , V_14 , V_15 , V_16 ) ;
return V_12 -> V_25 [ V_16 ] ;
}
static int F_5 ( struct V_26 * V_12 ,
int V_13 , int V_14 )
{
return F_2 ( & V_12 -> V_27 , V_13 , V_14 ) ;
}
static int F_6 ( struct V_28 * V_12 ,
int V_13 , int V_14 )
{
int V_5 ;
for ( V_5 = V_12 -> V_27 . V_4 - 1 ; V_5 >= 0 ; V_5 -- ) {
T_1 V_29 = F_7 ( V_12 -> V_27 . V_20 , V_13 , V_12 -> V_27 . V_25 [ V_5 ] ,
V_14 , V_12 -> V_27 . V_19 ) ;
V_29 &= 0xffff ;
F_3 ( L_6
L_7 ,
V_5 , V_13 , V_14 , V_12 -> V_27 . V_25 [ V_5 ] , V_12 -> V_30 [ V_5 ] ,
V_12 -> V_31 [ V_5 ] , V_29 ) ;
V_29 *= V_12 -> V_31 [ V_5 ] ;
V_29 = V_29 >> 16 ;
if ( V_29 < V_12 -> V_30 [ V_5 ] )
return V_12 -> V_27 . V_25 [ V_5 ] ;
}
F_8 ( 1 ) ;
return 0 ;
}
static int F_9 ( int V_32 )
{
int V_27 = 0 ;
while ( ( V_32 & 1 ) == 0 ) {
V_27 ++ ;
V_32 = V_32 >> 1 ;
}
return V_27 ;
}
static int F_10 ( int V_13 )
{
int V_27 = F_9 ( V_13 ) ;
return V_13 - ( 1 << ( V_27 - 1 ) ) ;
}
static int F_11 ( int V_13 )
{
int V_27 = F_9 ( V_13 ) ;
return V_13 + ( 1 << ( V_27 - 1 ) ) ;
}
static int F_12 ( int V_13 )
{
return V_13 & 1 ;
}
static int F_13 ( struct V_33 * V_12 ,
int V_13 , int V_14 )
{
int V_32 , V_34 ;
T_2 V_29 ;
T_1 V_24 ;
V_32 = V_12 -> V_35 >> 1 ;
while ( ! F_12 ( V_32 ) ) {
V_29 = V_12 -> V_36 [ V_32 ] ;
V_24 = ( T_1 ) F_7 ( V_12 -> V_27 . V_20 , V_13 , V_32 , V_14 ,
V_12 -> V_27 . V_19 ) * ( T_1 ) V_29 ;
V_24 = V_24 >> 32 ;
V_34 = F_10 ( V_32 ) ;
if ( V_24 < V_12 -> V_36 [ V_34 ] )
V_32 = V_34 ;
else
V_32 = F_11 ( V_32 ) ;
}
return V_12 -> V_27 . V_25 [ V_32 >> 1 ] ;
}
static int F_14 ( struct V_37 * V_12 ,
int V_13 , int V_14 )
{
int V_5 ;
int V_38 = 0 ;
T_1 V_39 = 0 ;
T_1 V_40 ;
for ( V_5 = 0 ; V_5 < V_12 -> V_27 . V_4 ; V_5 ++ ) {
V_40 = F_4 ( V_12 -> V_27 . V_20 , V_13 , V_12 -> V_27 . V_25 [ V_5 ] , V_14 ) ;
V_40 &= 0xffff ;
V_40 *= V_12 -> V_41 [ V_5 ] ;
if ( V_5 == 0 || V_40 > V_39 ) {
V_38 = V_5 ;
V_39 = V_40 ;
}
}
return V_12 -> V_27 . V_25 [ V_38 ] ;
}
static int F_15 ( struct V_11 * V_42 , int V_13 , int V_14 )
{
F_3 ( L_8 , V_42 -> V_19 , V_13 , V_14 ) ;
switch ( V_42 -> V_43 ) {
case V_44 :
return F_5 ( (struct V_26 * ) V_42 ,
V_13 , V_14 ) ;
case V_45 :
return F_6 ( (struct V_28 * ) V_42 ,
V_13 , V_14 ) ;
case V_46 :
return F_13 ( (struct V_33 * ) V_42 ,
V_13 , V_14 ) ;
case V_47 :
return F_14 ( (struct V_37 * ) V_42 ,
V_13 , V_14 ) ;
default:
F_8 ( 1 ) ;
return V_42 -> V_25 [ 0 ] ;
}
}
static int F_16 ( struct V_1 * V_2 , T_2 * V_48 , int V_49 , int V_13 )
{
if ( V_48 [ V_49 ] >= 0x10000 )
return 0 ;
if ( V_48 [ V_49 ] == 0 )
return 1 ;
if ( ( F_17 ( V_50 , V_13 , V_49 ) & 0xffff )
< V_48 [ V_49 ] )
return 0 ;
return 1 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
T_2 * V_48 ,
int V_13 , int V_51 , int type ,
int * V_22 , int V_52 ,
int V_53 , int V_54 ,
int * V_55 )
{
int V_56 ;
int V_57 , V_58 ;
int V_59 , V_60 , V_61 ;
struct V_11 * V_42 = V_12 ;
int V_14 ;
int V_5 ;
int V_49 = 0 ;
int V_62 ;
int V_63 , V_64 ;
const int V_65 = 5 ;
F_3 ( L_9 , V_54 ? L_10 : L_11 ,
V_12 -> V_19 , V_13 , V_52 , V_51 ) ;
for ( V_56 = V_52 ; V_56 < V_51 ; V_56 ++ ) {
V_57 = 0 ;
V_61 = 0 ;
do {
V_59 = 0 ;
V_42 = V_12 ;
V_58 = 0 ;
do {
V_63 = 0 ;
V_60 = 0 ;
V_14 = V_56 ;
if ( V_42 -> V_43 == V_44 ) {
if ( V_53 || V_51 >= V_42 -> V_4 )
V_14 += V_57 ;
else if ( V_42 -> V_4 % V_51 == 0 )
V_14 += ( V_51 + 1 ) *
( V_58 + V_57 ) ;
else
V_14 += V_51 * ( V_58 + V_57 ) ;
} else {
if ( V_53 )
V_14 += V_57 ;
else
V_14 += V_51 * ( V_58 + V_57 ) ;
}
if ( V_42 -> V_4 == 0 ) {
V_64 = 1 ;
goto V_64;
}
if ( V_58 >= ( V_42 -> V_4 >> 1 ) &&
V_58 > V_65 )
V_49 = F_2 ( V_42 , V_13 , V_14 ) ;
else
V_49 = F_15 ( V_42 , V_13 , V_14 ) ;
F_8 ( V_49 >= V_2 -> V_66 ) ;
if ( V_49 < 0 )
V_62 = V_2 -> V_67 [ - 1 - V_49 ] -> type ;
else
V_62 = 0 ;
F_3 ( L_12 , V_49 , V_62 ) ;
if ( V_62 != type ) {
F_8 ( V_49 >= 0 ||
( - 1 - V_49 ) >= V_2 -> V_68 ) ;
V_42 = V_2 -> V_67 [ - 1 - V_49 ] ;
V_60 = 1 ;
continue;
}
for ( V_5 = 0 ; V_5 < V_52 ; V_5 ++ ) {
if ( V_22 [ V_5 ] == V_49 ) {
V_63 = 1 ;
break;
}
}
V_64 = 0 ;
if ( V_54 ) {
if ( V_49 < 0 ) {
if ( F_18 ( V_2 ,
V_2 -> V_67 [ - 1 - V_49 ] ,
V_48 ,
V_13 , V_52 + 1 , 0 ,
V_55 , V_52 ,
V_53 , 0 ,
NULL ) <= V_52 )
V_64 = 1 ;
} else {
V_55 [ V_52 ] = V_49 ;
}
}
if ( ! V_64 ) {
if ( V_62 == 0 )
V_64 = F_16 ( V_2 , V_48 ,
V_49 , V_13 ) ;
else
V_64 = 0 ;
}
V_64:
if ( V_64 || V_63 ) {
V_57 ++ ;
V_58 ++ ;
if ( V_63 && V_58 < 3 )
V_60 = 1 ;
else if ( V_58 < V_42 -> V_4 + V_65 )
V_60 = 1 ;
else if ( V_57 < 20 )
V_59 = 1 ;
else
V_61 = 1 ;
F_3 ( L_13
L_14 ,
V_64 , V_63 , V_57 ,
V_58 ) ;
}
} while ( V_60 );
} while ( V_59 );
if ( V_61 ) {
F_3 ( L_15 ) ;
continue;
}
F_3 ( L_16 , V_49 ) ;
V_22 [ V_52 ] = V_49 ;
V_52 ++ ;
}
F_3 ( L_17 , V_52 ) ;
return V_52 ;
}
int F_19 ( struct V_1 * V_2 ,
int V_69 , int V_13 , int * V_70 , int V_71 ,
int V_72 , T_2 * V_48 )
{
int V_73 ;
int V_74 [ V_75 ] ;
int V_76 = - 1 ;
int V_77 [ V_78 ] ;
int V_79 [ V_78 ] ;
int V_80 [ V_78 ] ;
int V_54 ;
int * V_29 ;
int V_81 = 0 ;
int * V_82 ;
int V_83 ;
int * V_84 ;
struct V_85 * V_86 ;
int V_87 ;
int V_5 , V_88 ;
int V_51 ;
int V_53 ;
F_8 ( V_69 >= V_2 -> V_6 ) ;
V_86 = V_2 -> V_7 [ V_69 ] ;
V_73 = 0 ;
V_29 = V_77 ;
V_82 = V_79 ;
if ( V_72 >= 0 &&
V_72 < V_2 -> V_66 &&
V_2 -> V_89 [ V_72 ] != 0 &&
! F_16 ( V_2 , V_48 , V_72 , V_13 ) ) {
while ( 1 ) {
V_74 [ ++ V_76 ] = V_72 ;
if ( V_72 >= 0 )
V_72 = V_2 -> V_89 [ V_72 ] ;
else
V_72 = V_2 -> V_90 [ - 1 - V_72 ] ;
if ( V_72 == 0 )
break;
}
}
for ( V_87 = 0 ; V_87 < V_86 -> V_91 ; V_87 ++ ) {
V_53 = 0 ;
switch ( V_86 -> V_92 [ V_87 ] . V_93 ) {
case V_94 :
V_29 [ 0 ] = V_86 -> V_92 [ V_87 ] . V_95 ;
if ( V_76 >= 0 ) {
F_8 ( V_74 [ V_76 ] != V_29 [ 0 ] ) ;
V_76 -- ;
}
V_81 = 1 ;
break;
case V_96 :
case V_97 :
V_53 = 1 ;
case V_98 :
case V_99 :
F_8 ( V_81 == 0 ) ;
V_54 =
V_86 -> V_92 [ V_87 ] . V_93 ==
V_96 ||
V_86 -> V_92 [ V_87 ] . V_93 ==
V_98 ;
V_83 = 0 ;
for ( V_5 = 0 ; V_5 < V_81 ; V_5 ++ ) {
V_51 = V_86 -> V_92 [ V_87 ] . V_95 ;
if ( V_51 <= 0 ) {
V_51 += V_71 ;
if ( V_51 <= 0 )
continue;
}
V_88 = 0 ;
if ( V_83 == 0 && V_76 >= 0 ) {
while ( V_76 &&
V_74 [ V_76 ] < 0 &&
V_86 -> V_92 [ V_87 ] . V_100 !=
V_2 -> V_67 [ - 1 -
V_74 [ V_76 ] ] -> type )
V_76 -- ;
V_82 [ V_83 ] = V_74 [ V_76 ] ;
if ( V_54 )
V_80 [ V_83 ] = V_74 [ 0 ] ;
V_88 ++ ;
V_76 -- ;
}
V_83 += F_18 ( V_2 ,
V_2 -> V_67 [ - 1 - V_29 [ V_5 ] ] ,
V_48 ,
V_13 , V_51 ,
V_86 -> V_92 [ V_87 ] . V_100 ,
V_82 + V_83 , V_88 ,
V_53 ,
V_54 , V_80 + V_83 ) ;
}
if ( V_54 )
memcpy ( V_82 , V_80 , V_83 * sizeof( * V_82 ) ) ;
V_84 = V_82 ;
V_82 = V_29 ;
V_29 = V_84 ;
V_81 = V_83 ;
break;
case V_101 :
for ( V_5 = 0 ; V_5 < V_81 && V_73 < V_71 ; V_5 ++ ) {
V_70 [ V_73 ] = V_29 [ V_5 ] ;
V_73 ++ ;
}
V_81 = 0 ;
break;
default:
F_8 ( 1 ) ;
}
}
return V_73 ;
}
