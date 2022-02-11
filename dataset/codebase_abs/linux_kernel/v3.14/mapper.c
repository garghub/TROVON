int F_1 ( const struct V_1 * V_2 , int V_3 , int type , int V_4 )
{
T_1 V_5 ;
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
unsigned int V_15 = V_14 % V_12 -> V_4 ;
unsigned int V_5 , V_16 ;
if ( V_12 -> V_17 != ( T_1 ) V_13 || V_12 -> V_18 == 0 ) {
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
unsigned int V_23 = V_12 -> V_18 ;
if ( V_23 < V_12 -> V_4 - 1 ) {
V_5 = F_4 ( V_12 -> V_20 , V_13 , V_12 -> V_19 , V_23 ) %
( V_12 -> V_4 - V_23 ) ;
if ( V_5 ) {
unsigned int V_24 = V_12 -> V_21 [ V_23 + V_5 ] ;
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
T_2 V_29 = F_7 ( V_12 -> V_27 . V_20 , V_13 , V_12 -> V_27 . V_25 [ V_5 ] ,
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
F_3 ( L_8 , V_12 -> V_27 . V_19 ) ;
return V_12 -> V_27 . V_25 [ 0 ] ;
}
static int F_8 ( int V_32 )
{
int V_27 = 0 ;
while ( ( V_32 & 1 ) == 0 ) {
V_27 ++ ;
V_32 = V_32 >> 1 ;
}
return V_27 ;
}
static int F_9 ( int V_13 )
{
int V_27 = F_8 ( V_13 ) ;
return V_13 - ( 1 << ( V_27 - 1 ) ) ;
}
static int F_10 ( int V_13 )
{
int V_27 = F_8 ( V_13 ) ;
return V_13 + ( 1 << ( V_27 - 1 ) ) ;
}
static int F_11 ( int V_13 )
{
return V_13 & 1 ;
}
static int F_12 ( struct V_33 * V_12 ,
int V_13 , int V_14 )
{
int V_32 ;
T_1 V_29 ;
T_2 V_24 ;
V_32 = V_12 -> V_34 >> 1 ;
while ( ! F_11 ( V_32 ) ) {
int V_35 ;
V_29 = V_12 -> V_36 [ V_32 ] ;
V_24 = ( T_2 ) F_7 ( V_12 -> V_27 . V_20 , V_13 , V_32 , V_14 ,
V_12 -> V_27 . V_19 ) * ( T_2 ) V_29 ;
V_24 = V_24 >> 32 ;
V_35 = F_9 ( V_32 ) ;
if ( V_24 < V_12 -> V_36 [ V_35 ] )
V_32 = V_35 ;
else
V_32 = F_10 ( V_32 ) ;
}
return V_12 -> V_27 . V_25 [ V_32 >> 1 ] ;
}
static int F_13 ( struct V_37 * V_12 ,
int V_13 , int V_14 )
{
T_1 V_5 ;
int V_38 = 0 ;
T_2 V_39 = 0 ;
T_2 V_40 ;
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
static int F_14 ( struct V_11 * V_42 , int V_13 , int V_14 )
{
F_3 ( L_9 , V_42 -> V_19 , V_13 , V_14 ) ;
F_15 ( V_42 -> V_4 == 0 ) ;
switch ( V_42 -> V_43 ) {
case V_44 :
return F_5 ( (struct V_26 * ) V_42 ,
V_13 , V_14 ) ;
case V_45 :
return F_6 ( (struct V_28 * ) V_42 ,
V_13 , V_14 ) ;
case V_46 :
return F_12 ( (struct V_33 * ) V_42 ,
V_13 , V_14 ) ;
case V_47 :
return F_13 ( (struct V_37 * ) V_42 ,
V_13 , V_14 ) ;
default:
F_3 ( L_10 , V_42 -> V_19 , V_42 -> V_43 ) ;
return V_42 -> V_25 [ 0 ] ;
}
}
static int F_16 ( const struct V_1 * V_2 ,
const T_1 * V_48 , int V_49 ,
int V_50 , int V_13 )
{
if ( V_50 >= V_49 )
return 1 ;
if ( V_48 [ V_50 ] >= 0x10000 )
return 0 ;
if ( V_48 [ V_50 ] == 0 )
return 1 ;
if ( ( F_17 ( V_51 , V_13 , V_50 ) & 0xffff )
< V_48 [ V_50 ] )
return 0 ;
return 1 ;
}
static int F_18 ( const struct V_1 * V_2 ,
struct V_11 * V_12 ,
const T_1 * V_48 , int V_49 ,
int V_13 , int V_52 , int type ,
int * V_22 , int V_53 ,
unsigned int V_54 ,
unsigned int V_55 ,
unsigned int V_56 ,
unsigned int V_57 ,
int V_58 ,
int * V_59 )
{
int V_60 ;
unsigned int V_61 , V_62 ;
int V_63 , V_64 , V_65 ;
struct V_11 * V_42 = V_12 ;
int V_14 ;
int V_5 ;
int V_50 = 0 ;
int V_66 ;
int V_67 , V_68 ;
F_3 ( L_11 , V_58 ? L_12 : L_13 ,
V_12 -> V_19 , V_13 , V_53 , V_52 ) ;
for ( V_60 = V_53 ; V_60 < V_52 ; V_60 ++ ) {
V_61 = 0 ;
V_65 = 0 ;
do {
V_63 = 0 ;
V_42 = V_12 ;
V_62 = 0 ;
do {
V_67 = 0 ;
V_64 = 0 ;
V_14 = V_60 ;
V_14 += V_61 ;
if ( V_42 -> V_4 == 0 ) {
V_68 = 1 ;
goto V_68;
}
if ( V_57 > 0 &&
V_62 >= ( V_42 -> V_4 >> 1 ) &&
V_62 > V_57 )
V_50 = F_2 ( V_42 , V_13 , V_14 ) ;
else
V_50 = F_14 ( V_42 , V_13 , V_14 ) ;
if ( V_50 >= V_2 -> V_69 ) {
F_3 ( L_14 , V_50 ) ;
V_65 = 1 ;
break;
}
if ( V_50 < 0 )
V_66 = V_2 -> V_70 [ - 1 - V_50 ] -> type ;
else
V_66 = 0 ;
F_3 ( L_15 , V_50 , V_66 ) ;
if ( V_66 != type ) {
if ( V_50 >= 0 ||
( - 1 - V_50 ) >= V_2 -> V_71 ) {
F_3 ( L_16 , type ) ;
V_65 = 1 ;
break;
}
V_42 = V_2 -> V_70 [ - 1 - V_50 ] ;
V_64 = 1 ;
continue;
}
for ( V_5 = 0 ; V_5 < V_53 ; V_5 ++ ) {
if ( V_22 [ V_5 ] == V_50 ) {
V_67 = 1 ;
break;
}
}
V_68 = 0 ;
if ( ! V_67 && V_58 ) {
if ( V_50 < 0 ) {
if ( F_18 ( V_2 ,
V_2 -> V_70 [ - 1 - V_50 ] ,
V_48 , V_49 ,
V_13 , V_53 + 1 , 0 ,
V_59 , V_53 ,
V_55 , 0 ,
V_56 ,
V_57 ,
0 ,
NULL ) <= V_53 )
V_68 = 1 ;
} else {
V_59 [ V_53 ] = V_50 ;
}
}
if ( ! V_68 ) {
if ( V_66 == 0 )
V_68 = F_16 ( V_2 , V_48 ,
V_49 ,
V_50 , V_13 ) ;
else
V_68 = 0 ;
}
V_68:
if ( V_68 || V_67 ) {
V_61 ++ ;
V_62 ++ ;
if ( V_67 && V_62 <= V_56 )
V_64 = 1 ;
else if ( V_57 > 0 &&
V_62 <= V_42 -> V_4 + V_57 )
V_64 = 1 ;
else if ( V_61 <= V_54 )
V_63 = 1 ;
else
V_65 = 1 ;
F_3 ( L_17
L_18 ,
V_68 , V_67 , V_61 ,
V_62 ) ;
}
} while ( V_64 );
} while ( V_63 );
if ( V_65 ) {
F_3 ( L_19 ) ;
continue;
}
F_3 ( L_20 , V_50 ) ;
V_22 [ V_53 ] = V_50 ;
V_53 ++ ;
}
F_3 ( L_21 , V_53 ) ;
return V_53 ;
}
static void F_19 ( const struct V_1 * V_2 ,
struct V_11 * V_12 ,
const T_1 * V_48 , int V_49 ,
int V_13 , int F_9 , int V_52 , int type ,
int * V_22 , int V_53 ,
unsigned int V_54 ,
unsigned int V_55 ,
int V_58 ,
int * V_59 ,
int V_72 )
{
struct V_11 * V_42 = V_12 ;
int V_73 = V_53 + F_9 ;
int V_60 ;
unsigned int V_61 ;
int V_14 ;
int V_5 ;
int V_50 = 0 ;
int V_66 ;
int V_67 ;
F_3 ( L_22 , V_58 ? L_12 : L_13 ,
V_12 -> V_19 , V_13 , V_53 , V_52 ) ;
for ( V_60 = V_53 ; V_60 < V_73 ; V_60 ++ ) {
V_22 [ V_60 ] = V_74 ;
if ( V_59 )
V_59 [ V_60 ] = V_74 ;
}
for ( V_61 = 0 ; F_9 > 0 && V_61 < V_54 ; V_61 ++ ) {
for ( V_60 = V_53 ; V_60 < V_73 ; V_60 ++ ) {
if ( V_22 [ V_60 ] != V_74 )
continue;
V_42 = V_12 ;
for (; ; ) {
V_14 = V_60 + V_72 ;
if ( V_42 -> V_43 == V_44 &&
V_42 -> V_4 % V_52 == 0 )
V_14 += ( V_52 + 1 ) * V_61 ;
else
V_14 += V_52 * V_61 ;
if ( V_42 -> V_4 == 0 ) {
F_3 ( L_23 ) ;
break;
}
V_50 = F_14 ( V_42 , V_13 , V_14 ) ;
if ( V_50 >= V_2 -> V_69 ) {
F_3 ( L_14 , V_50 ) ;
V_22 [ V_60 ] = V_75 ;
if ( V_59 )
V_59 [ V_60 ] = V_75 ;
F_9 -- ;
break;
}
if ( V_50 < 0 )
V_66 = V_2 -> V_70 [ - 1 - V_50 ] -> type ;
else
V_66 = 0 ;
F_3 ( L_15 , V_50 , V_66 ) ;
if ( V_66 != type ) {
if ( V_50 >= 0 ||
( - 1 - V_50 ) >= V_2 -> V_71 ) {
F_3 ( L_16 , type ) ;
V_22 [ V_60 ] = V_75 ;
if ( V_59 )
V_59 [ V_60 ] =
V_75 ;
F_9 -- ;
break;
}
V_42 = V_2 -> V_70 [ - 1 - V_50 ] ;
continue;
}
V_67 = 0 ;
for ( V_5 = V_53 ; V_5 < V_73 ; V_5 ++ ) {
if ( V_22 [ V_5 ] == V_50 ) {
V_67 = 1 ;
break;
}
}
if ( V_67 )
break;
if ( V_58 ) {
if ( V_50 < 0 ) {
F_19 ( V_2 ,
V_2 -> V_70 [ - 1 - V_50 ] ,
V_48 , V_49 ,
V_13 , 1 , V_52 , 0 ,
V_59 , V_60 ,
V_55 , 0 ,
0 , NULL , V_14 ) ;
if ( V_59 [ V_60 ] == V_75 ) {
break;
}
} else {
V_59 [ V_60 ] = V_50 ;
}
}
if ( V_66 == 0 &&
F_16 ( V_2 , V_48 , V_49 , V_50 , V_13 ) )
break;
V_22 [ V_60 ] = V_50 ;
F_9 -- ;
break;
}
}
}
for ( V_60 = V_53 ; V_60 < V_73 ; V_60 ++ ) {
if ( V_22 [ V_60 ] == V_74 ) {
V_22 [ V_60 ] = V_75 ;
}
if ( V_59 && V_59 [ V_60 ] == V_74 ) {
V_59 [ V_60 ] = V_75 ;
}
}
}
int F_20 ( const struct V_1 * V_2 ,
int V_76 , int V_13 , int * V_77 , int V_78 ,
const T_1 * V_48 , int V_49 ,
int * V_79 )
{
int V_80 ;
int * V_81 = V_79 ;
int * V_82 = V_79 + V_78 ;
int * V_83 = V_79 + V_78 * 2 ;
int V_58 ;
int * V_29 ;
int V_84 = 0 ;
int * V_85 ;
int V_86 ;
int * V_87 ;
struct V_88 * V_89 ;
T_1 V_90 ;
int V_5 , V_91 ;
int V_52 ;
int V_92 = V_2 -> V_93 ;
int V_94 = V_2 -> V_94 ;
int V_95 = V_2 -> V_95 ;
int V_96 = 0 ;
if ( ( T_1 ) V_76 >= V_2 -> V_6 ) {
F_3 ( L_24 , V_76 ) ;
return 0 ;
}
V_89 = V_2 -> V_7 [ V_76 ] ;
V_80 = 0 ;
V_29 = V_81 ;
V_85 = V_82 ;
for ( V_90 = 0 ; V_90 < V_89 -> V_97 ; V_90 ++ ) {
int V_98 = 0 ;
struct V_99 * V_100 = & V_89 -> V_101 [ V_90 ] ;
switch ( V_100 -> V_102 ) {
case V_103 :
V_29 [ 0 ] = V_100 -> V_104 ;
V_84 = 1 ;
break;
case V_105 :
if ( V_100 -> V_104 > 0 )
V_92 = V_100 -> V_104 ;
break;
case V_106 :
if ( V_100 -> V_104 > 0 )
V_96 = V_100 -> V_104 ;
break;
case V_107 :
if ( V_100 -> V_104 > 0 )
V_94 = V_100 -> V_104 ;
break;
case V_108 :
if ( V_100 -> V_104 > 0 )
V_95 = V_100 -> V_104 ;
break;
case V_109 :
case V_110 :
V_98 = 1 ;
case V_111 :
case V_112 :
if ( V_84 == 0 )
break;
V_58 =
V_100 -> V_102 ==
V_109 ||
V_100 -> V_102 ==
V_111 ;
V_86 = 0 ;
for ( V_5 = 0 ; V_5 < V_84 ; V_5 ++ ) {
V_52 = V_100 -> V_104 ;
if ( V_52 <= 0 ) {
V_52 += V_78 ;
if ( V_52 <= 0 )
continue;
}
V_91 = 0 ;
if ( V_98 ) {
int V_55 ;
if ( V_96 )
V_55 =
V_96 ;
else if ( V_2 -> V_113 )
V_55 = 1 ;
else
V_55 = V_92 ;
V_86 += F_18 (
V_2 ,
V_2 -> V_70 [ - 1 - V_29 [ V_5 ] ] ,
V_48 , V_49 ,
V_13 , V_52 ,
V_100 -> V_114 ,
V_85 + V_86 , V_91 ,
V_92 ,
V_55 ,
V_94 ,
V_95 ,
V_58 ,
V_83 + V_86 ) ;
} else {
F_19 (
V_2 ,
V_2 -> V_70 [ - 1 - V_29 [ V_5 ] ] ,
V_48 , V_49 ,
V_13 , V_52 , V_52 ,
V_100 -> V_114 ,
V_85 + V_86 , V_91 ,
V_92 ,
V_96 ?
V_96 : 1 ,
V_58 ,
V_83 + V_86 ,
0 ) ;
V_86 += V_52 ;
}
}
if ( V_58 )
memcpy ( V_85 , V_83 , V_86 * sizeof( * V_85 ) ) ;
V_87 = V_85 ;
V_85 = V_29 ;
V_29 = V_87 ;
V_84 = V_86 ;
break;
case V_115 :
for ( V_5 = 0 ; V_5 < V_84 && V_80 < V_78 ; V_5 ++ ) {
V_77 [ V_80 ] = V_29 [ V_5 ] ;
V_80 ++ ;
}
V_84 = 0 ;
break;
default:
F_3 ( L_25 ,
V_100 -> V_102 , V_90 ) ;
break;
}
}
return V_80 ;
}
