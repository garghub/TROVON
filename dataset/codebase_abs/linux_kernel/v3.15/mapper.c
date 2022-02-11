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
unsigned int V_59 ,
int * V_60 ,
int V_61 )
{
int V_62 ;
unsigned int V_63 , V_64 ;
int V_65 , V_66 , V_67 ;
struct V_11 * V_42 = V_12 ;
int V_14 ;
int V_5 ;
int V_50 = 0 ;
int V_68 ;
int V_69 , V_70 ;
F_3 ( L_11 ,
V_58 ? L_12 : L_13 ,
V_12 -> V_19 , V_13 , V_53 , V_52 ,
V_54 , V_55 , V_56 , V_57 ,
V_61 ) ;
for ( V_62 = V_53 ; V_62 < V_52 ; V_62 ++ ) {
V_63 = 0 ;
V_67 = 0 ;
do {
V_65 = 0 ;
V_42 = V_12 ;
V_64 = 0 ;
do {
V_69 = 0 ;
V_66 = 0 ;
V_14 = V_62 + V_61 ;
V_14 += V_63 ;
if ( V_42 -> V_4 == 0 ) {
V_70 = 1 ;
goto V_70;
}
if ( V_57 > 0 &&
V_64 >= ( V_42 -> V_4 >> 1 ) &&
V_64 > V_57 )
V_50 = F_2 ( V_42 , V_13 , V_14 ) ;
else
V_50 = F_14 ( V_42 , V_13 , V_14 ) ;
if ( V_50 >= V_2 -> V_71 ) {
F_3 ( L_14 , V_50 ) ;
V_67 = 1 ;
break;
}
if ( V_50 < 0 )
V_68 = V_2 -> V_72 [ - 1 - V_50 ] -> type ;
else
V_68 = 0 ;
F_3 ( L_15 , V_50 , V_68 ) ;
if ( V_68 != type ) {
if ( V_50 >= 0 ||
( - 1 - V_50 ) >= V_2 -> V_73 ) {
F_3 ( L_16 , type ) ;
V_67 = 1 ;
break;
}
V_42 = V_2 -> V_72 [ - 1 - V_50 ] ;
V_66 = 1 ;
continue;
}
for ( V_5 = 0 ; V_5 < V_53 ; V_5 ++ ) {
if ( V_22 [ V_5 ] == V_50 ) {
V_69 = 1 ;
break;
}
}
V_70 = 0 ;
if ( ! V_69 && V_58 ) {
if ( V_50 < 0 ) {
int V_74 ;
if ( V_59 )
V_74 = V_14 >> ( V_59 - 1 ) ;
else
V_74 = 0 ;
if ( F_18 ( V_2 ,
V_2 -> V_72 [ - 1 - V_50 ] ,
V_48 , V_49 ,
V_13 , V_53 + 1 , 0 ,
V_60 , V_53 ,
V_55 , 0 ,
V_56 ,
V_57 ,
0 ,
V_59 ,
NULL ,
V_74 ) <= V_53 )
V_70 = 1 ;
} else {
V_60 [ V_53 ] = V_50 ;
}
}
if ( ! V_70 ) {
if ( V_68 == 0 )
V_70 = F_16 ( V_2 , V_48 ,
V_49 ,
V_50 , V_13 ) ;
else
V_70 = 0 ;
}
V_70:
if ( V_70 || V_69 ) {
V_63 ++ ;
V_64 ++ ;
if ( V_69 && V_64 <= V_56 )
V_66 = 1 ;
else if ( V_57 > 0 &&
V_64 <= V_42 -> V_4 + V_57 )
V_66 = 1 ;
else if ( V_63 < V_54 )
V_65 = 1 ;
else
V_67 = 1 ;
F_3 ( L_17
L_18 ,
V_70 , V_69 , V_63 ,
V_64 ) ;
}
} while ( V_66 );
} while ( V_65 );
if ( V_67 ) {
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
int * V_60 ,
int V_61 )
{
struct V_11 * V_42 = V_12 ;
int V_75 = V_53 + F_9 ;
int V_62 ;
unsigned int V_63 ;
int V_14 ;
int V_5 ;
int V_50 = 0 ;
int V_68 ;
int V_69 ;
F_3 ( L_22 , V_58 ? L_12 : L_13 ,
V_12 -> V_19 , V_13 , V_53 , V_52 ) ;
for ( V_62 = V_53 ; V_62 < V_75 ; V_62 ++ ) {
V_22 [ V_62 ] = V_76 ;
if ( V_60 )
V_60 [ V_62 ] = V_76 ;
}
for ( V_63 = 0 ; F_9 > 0 && V_63 < V_54 ; V_63 ++ ) {
for ( V_62 = V_53 ; V_62 < V_75 ; V_62 ++ ) {
if ( V_22 [ V_62 ] != V_76 )
continue;
V_42 = V_12 ;
for (; ; ) {
V_14 = V_62 + V_61 ;
if ( V_42 -> V_43 == V_44 &&
V_42 -> V_4 % V_52 == 0 )
V_14 += ( V_52 + 1 ) * V_63 ;
else
V_14 += V_52 * V_63 ;
if ( V_42 -> V_4 == 0 ) {
F_3 ( L_23 ) ;
break;
}
V_50 = F_14 ( V_42 , V_13 , V_14 ) ;
if ( V_50 >= V_2 -> V_71 ) {
F_3 ( L_14 , V_50 ) ;
V_22 [ V_62 ] = V_77 ;
if ( V_60 )
V_60 [ V_62 ] = V_77 ;
F_9 -- ;
break;
}
if ( V_50 < 0 )
V_68 = V_2 -> V_72 [ - 1 - V_50 ] -> type ;
else
V_68 = 0 ;
F_3 ( L_15 , V_50 , V_68 ) ;
if ( V_68 != type ) {
if ( V_50 >= 0 ||
( - 1 - V_50 ) >= V_2 -> V_73 ) {
F_3 ( L_16 , type ) ;
V_22 [ V_62 ] = V_77 ;
if ( V_60 )
V_60 [ V_62 ] =
V_77 ;
F_9 -- ;
break;
}
V_42 = V_2 -> V_72 [ - 1 - V_50 ] ;
continue;
}
V_69 = 0 ;
for ( V_5 = V_53 ; V_5 < V_75 ; V_5 ++ ) {
if ( V_22 [ V_5 ] == V_50 ) {
V_69 = 1 ;
break;
}
}
if ( V_69 )
break;
if ( V_58 ) {
if ( V_50 < 0 ) {
F_19 ( V_2 ,
V_2 -> V_72 [ - 1 - V_50 ] ,
V_48 , V_49 ,
V_13 , 1 , V_52 , 0 ,
V_60 , V_62 ,
V_55 , 0 ,
0 , NULL , V_14 ) ;
if ( V_60 [ V_62 ] == V_77 ) {
break;
}
} else {
V_60 [ V_62 ] = V_50 ;
}
}
if ( V_68 == 0 &&
F_16 ( V_2 , V_48 , V_49 , V_50 , V_13 ) )
break;
V_22 [ V_62 ] = V_50 ;
F_9 -- ;
break;
}
}
}
for ( V_62 = V_53 ; V_62 < V_75 ; V_62 ++ ) {
if ( V_22 [ V_62 ] == V_76 ) {
V_22 [ V_62 ] = V_77 ;
}
if ( V_60 && V_60 [ V_62 ] == V_76 ) {
V_60 [ V_62 ] = V_77 ;
}
}
}
int F_20 ( const struct V_1 * V_2 ,
int V_78 , int V_13 , int * V_79 , int V_80 ,
const T_1 * V_48 , int V_49 ,
int * V_81 )
{
int V_82 ;
int * V_83 = V_81 ;
int * V_84 = V_81 + V_80 ;
int * V_85 = V_81 + V_80 * 2 ;
int V_58 ;
int * V_29 ;
int V_86 = 0 ;
int * V_87 ;
int V_88 ;
int * V_89 ;
struct V_90 * V_91 ;
T_1 V_92 ;
int V_5 , V_93 ;
int V_52 ;
int V_94 = V_2 -> V_95 + 1 ;
int V_96 = 0 ;
int V_97 = V_2 -> V_98 ;
int V_99 = V_2 -> V_100 ;
int V_59 = V_2 -> V_101 ;
if ( ( T_1 ) V_78 >= V_2 -> V_6 ) {
F_3 ( L_24 , V_78 ) ;
return 0 ;
}
V_91 = V_2 -> V_7 [ V_78 ] ;
V_82 = 0 ;
V_29 = V_83 ;
V_87 = V_84 ;
for ( V_92 = 0 ; V_92 < V_91 -> V_102 ; V_92 ++ ) {
int V_103 = 0 ;
struct V_104 * V_105 = & V_91 -> V_106 [ V_92 ] ;
switch ( V_105 -> V_107 ) {
case V_108 :
V_29 [ 0 ] = V_105 -> V_109 ;
V_86 = 1 ;
break;
case V_110 :
if ( V_105 -> V_109 > 0 )
V_94 = V_105 -> V_109 ;
break;
case V_111 :
if ( V_105 -> V_109 > 0 )
V_96 = V_105 -> V_109 ;
break;
case V_112 :
if ( V_105 -> V_109 >= 0 )
V_97 = V_105 -> V_109 ;
break;
case V_113 :
if ( V_105 -> V_109 >= 0 )
V_99 = V_105 -> V_109 ;
break;
case V_114 :
if ( V_105 -> V_109 >= 0 )
V_59 = V_105 -> V_109 ;
break;
case V_115 :
case V_116 :
V_103 = 1 ;
case V_117 :
case V_118 :
if ( V_86 == 0 )
break;
V_58 =
V_105 -> V_107 ==
V_115 ||
V_105 -> V_107 ==
V_117 ;
V_88 = 0 ;
for ( V_5 = 0 ; V_5 < V_86 ; V_5 ++ ) {
V_52 = V_105 -> V_109 ;
if ( V_52 <= 0 ) {
V_52 += V_80 ;
if ( V_52 <= 0 )
continue;
}
V_93 = 0 ;
if ( V_103 ) {
int V_55 ;
if ( V_96 )
V_55 =
V_96 ;
else if ( V_2 -> V_119 )
V_55 = 1 ;
else
V_55 = V_94 ;
V_88 += F_18 (
V_2 ,
V_2 -> V_72 [ - 1 - V_29 [ V_5 ] ] ,
V_48 , V_49 ,
V_13 , V_52 ,
V_105 -> V_120 ,
V_87 + V_88 , V_93 ,
V_94 ,
V_55 ,
V_97 ,
V_99 ,
V_58 ,
V_59 ,
V_85 + V_88 ,
0 ) ;
} else {
F_19 (
V_2 ,
V_2 -> V_72 [ - 1 - V_29 [ V_5 ] ] ,
V_48 , V_49 ,
V_13 , V_52 , V_52 ,
V_105 -> V_120 ,
V_87 + V_88 , V_93 ,
V_94 ,
V_96 ?
V_96 : 1 ,
V_58 ,
V_85 + V_88 ,
0 ) ;
V_88 += V_52 ;
}
}
if ( V_58 )
memcpy ( V_87 , V_85 , V_88 * sizeof( * V_87 ) ) ;
V_89 = V_87 ;
V_87 = V_29 ;
V_29 = V_89 ;
V_86 = V_88 ;
break;
case V_121 :
for ( V_5 = 0 ; V_5 < V_86 && V_82 < V_80 ; V_5 ++ ) {
V_79 [ V_82 ] = V_29 [ V_5 ] ;
V_82 ++ ;
}
V_86 = 0 ;
break;
default:
F_3 ( L_25 ,
V_105 -> V_107 , V_92 ) ;
break;
}
}
return V_82 ;
}
