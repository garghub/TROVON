static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
int V_5 , V_6 ;
struct V_7 V_8 ;
F_2 ( & V_8 , V_9 ) ;
if ( V_3 ) {
V_8 . V_10 [ 0 ] |= V_11 ;
V_8 . V_10 [ 2 ] = V_2 -> V_12 [ V_4 ] ;
} else {
V_8 . V_10 [ 0 ] |= V_13 ;
if ( V_2 -> V_14 [ V_4 ] )
V_6 = V_2 -> V_15 [ V_4 ] ;
else
V_6 = V_16 ;
V_8 . V_10 [ 2 ] = V_17 - V_6 ;
}
V_8 . V_10 [ 1 ] = 1 << ( ( 2 * V_2 -> V_18 ) + V_4 ) ;
V_8 . V_19 = 3 ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 < 0 ) {
F_4 ( V_21 L_1
L_2 ,
V_2 -> V_18 , V_3 , V_5 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_5 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
V_26 -> type = V_27 ;
V_26 -> V_28 = 2 ;
if ( V_24 -> V_29 == 0 ) {
if ( V_2 -> V_20 -> V_30 ) {
V_26 -> V_31 . integer . V_32 =
V_33 ;
V_26 -> V_31 . integer . V_34 =
V_35 ;
} else {
V_26 -> V_31 . integer . V_32 =
V_16 ;
V_26 -> V_31 . integer . V_34 =
V_17 ;
}
} else {
if ( V_2 -> V_20 -> V_30 ) {
V_26 -> V_31 . integer . V_32 =
V_36 ;
V_26 -> V_31 . integer . V_34 =
V_37 ;
} else {
V_26 -> V_31 . integer . V_32 =
V_38 ;
V_26 -> V_31 . integer . V_34 =
V_39 ;
}
}
return 0 ;
}
static int F_7 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
if ( V_24 -> V_29 == 0 ) {
V_41 -> V_31 . integer . V_31 [ 0 ] = V_2 -> V_15 [ 0 ] ;
V_41 -> V_31 . integer . V_31 [ 1 ] = V_2 -> V_15 [ 1 ] ;
} else {
V_41 -> V_31 . integer . V_31 [ 0 ] = V_2 -> V_12 [ 0 ] ;
V_41 -> V_31 . integer . V_31 [ 1 ] = V_2 -> V_12 [ 1 ] ;
}
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return 0 ;
}
static int F_10 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
int V_43 = 0 ;
int V_3 , V_44 ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
V_3 = ( V_24 -> V_29 != 0 ) ;
for ( V_44 = 0 ; V_44 < 2 ; V_44 ++ ) {
int V_45 = V_41 -> V_31 . integer . V_31 [ V_44 ] ;
int * V_46 = V_3 ?
& V_2 -> V_12 [ V_44 ] :
& V_2 -> V_15 [ V_44 ] ;
if ( V_3 ) {
if ( V_2 -> V_20 -> V_30 ) {
if ( V_45 < V_36 ||
V_45 > V_37 )
continue;
} else {
if ( V_45 < V_38 ||
V_45 > V_39 )
continue;
}
} else {
if ( V_2 -> V_20 -> V_30 ) {
if ( V_45 < V_33 ||
V_45 > V_35 )
continue;
} else {
if ( V_45 < V_16 ||
V_45 > V_17 )
continue;
}
}
if ( * V_46 != V_45 ) {
* V_46 = V_45 ;
V_43 = 1 ;
if ( V_2 -> V_20 -> V_30 )
F_11 ( V_2 ,
V_3 , V_44 ) ;
else
F_1 ( V_2 ,
V_3 , V_44 ) ;
}
}
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return V_43 ;
}
static int F_12 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
V_41 -> V_31 . integer . V_31 [ 0 ] = V_2 -> V_14 [ 0 ] ;
V_41 -> V_31 . integer . V_31 [ 1 ] = V_2 -> V_14 [ 1 ] ;
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return 0 ;
}
static int F_13 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
int V_44 , V_43 = 0 ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
for( V_44 = 0 ; V_44 < 2 ; V_44 ++ ) {
if ( V_2 -> V_14 [ V_44 ] !=
V_41 -> V_31 . integer . V_31 [ V_44 ] ) {
V_2 -> V_14 [ V_44 ] =
! ! V_41 -> V_31 . integer . V_31 [ V_44 ] ;
V_43 = 1 ;
if ( V_2 -> V_20 -> V_30 )
F_11 ( V_2 , 0 , V_44 ) ;
else
F_1 ( V_2 , 0 , V_44 ) ;
}
}
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return V_43 ;
}
static int F_14 ( struct V_1 * V_2 , int V_47 )
{
int V_5 ;
struct V_7 V_8 ;
struct V_48 * V_49 = & V_2 -> V_50 ;
int V_51 , V_52 ;
if ( V_2 -> V_53 [ V_47 ] [ 0 ] )
V_51 = V_2 -> V_54 [ V_47 ] [ 0 ] ;
else
V_51 = V_55 ;
if ( V_2 -> V_53 [ V_47 ] [ 1 ] )
V_52 = V_2 -> V_54 [ V_47 ] [ 1 ] ;
else
V_52 = V_55 ;
F_2 ( & V_8 , V_56 ) ;
F_15 ( & V_8 , 0 , V_49 -> V_57 , 0 , 1 << V_47 ) ;
V_8 . V_10 [ 0 ] |= V_58 ;
V_8 . V_10 [ 2 ] = V_59 | V_60 ;
V_8 . V_10 [ 2 ] |= ( V_51 << 10 ) ;
V_8 . V_10 [ 3 ] = V_59 | V_61 ;
V_8 . V_10 [ 3 ] |= V_52 ;
V_8 . V_19 = 4 ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 < 0 ) {
F_4 ( V_21 L_3
L_4 , V_2 -> V_18 , V_5 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_62 , int V_4 )
{
int V_5 ;
struct V_7 V_8 ;
struct V_48 * V_49 ;
if ( V_62 )
V_49 = & V_2 -> V_63 [ 0 ] ;
else
V_49 = & V_2 -> V_50 ;
F_2 ( & V_8 , V_64 ) ;
F_15 ( & V_8 , V_62 , 0 , 0 ,
1 << ( V_4 + V_49 -> V_57 ) ) ;
if ( V_62 ) {
V_8 . V_10 [ 0 ] |= V_65 ;
V_8 . V_10 [ 2 ] = V_2 -> V_66 [ V_4 ] ;
} else {
V_8 . V_10 [ 0 ] |= V_67 |
V_68 ;
V_8 . V_10 [ 2 ] = V_2 -> V_69 [ V_4 ] << 10 ;
if ( V_2 -> V_70 [ V_4 ] == 0 )
V_8 . V_10 [ 2 ] |= V_71 ;
}
V_8 . V_19 = 3 ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 < 0 ) {
F_4 ( V_21 L_5 ,
V_2 -> V_18 , V_5 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_17 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
V_26 -> type = V_27 ;
V_26 -> V_28 = 2 ;
V_26 -> V_31 . integer . V_32 = V_55 ;
V_26 -> V_31 . integer . V_34 = V_72 ;
return 0 ;
}
static int F_18 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
int V_47 = F_19 ( V_24 , & V_41 -> V_73 ) ;
int * V_46 ;
int V_3 = V_24 -> V_29 ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
if ( V_3 )
V_46 = V_2 -> V_66 ;
else
V_46 = V_2 -> V_54 [ V_47 ] ;
V_41 -> V_31 . integer . V_31 [ 0 ] = V_46 [ 0 ] ;
V_41 -> V_31 . integer . V_31 [ 1 ] = V_46 [ 1 ] ;
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return 0 ;
}
static int F_20 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
int V_47 = F_19 ( V_24 , & V_41 -> V_73 ) ;
int V_43 = 0 ;
int V_3 = V_24 -> V_29 ;
int * V_46 ;
int V_44 ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
if ( V_3 )
V_46 = V_2 -> V_66 ;
else
V_46 = V_2 -> V_54 [ V_47 ] ;
for ( V_44 = 0 ; V_44 < 2 ; V_44 ++ ) {
int V_6 = V_41 -> V_31 . integer . V_31 [ V_44 ] ;
if ( V_6 < V_55 ||
V_6 > V_72 )
continue;
if ( V_46 [ V_44 ] != V_6 ) {
V_46 [ V_44 ] = V_6 ;
V_43 = 1 ;
if ( V_3 )
F_16 ( V_2 , 1 , V_44 ) ;
}
}
if ( ! V_3 && V_43 )
F_14 ( V_2 , V_47 ) ;
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return V_43 ;
}
static int F_21 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
int V_47 = F_19 ( V_24 , & V_41 -> V_73 ) ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
V_41 -> V_31 . integer . V_31 [ 0 ] = V_2 -> V_53 [ V_47 ] [ 0 ] ;
V_41 -> V_31 . integer . V_31 [ 1 ] = V_2 -> V_53 [ V_47 ] [ 1 ] ;
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return 0 ;
}
static int F_22 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
int V_43 = 0 ;
int V_47 = F_19 ( V_24 , & V_41 -> V_73 ) ;
int V_44 , V_74 ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
V_74 = V_47 ;
for ( V_44 = 0 ; V_44 < 2 ; V_44 ++ ) {
if ( V_2 -> V_53 [ V_74 ] [ V_44 ] !=
V_41 -> V_31 . integer . V_31 [ V_44 ] ) {
V_2 -> V_53 [ V_74 ] [ V_44 ] =
! ! V_41 -> V_31 . integer . V_31 [ V_44 ] ;
V_43 = 1 ;
}
}
if ( V_43 )
F_14 ( V_2 , V_47 ) ;
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return V_43 ;
}
static int F_23 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
V_41 -> V_31 . integer . V_31 [ 0 ] = V_2 -> V_69 [ 0 ] ;
V_41 -> V_31 . integer . V_31 [ 1 ] = V_2 -> V_69 [ 1 ] ;
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return 0 ;
}
static int F_24 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
int V_43 = 0 ;
int V_44 ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
for ( V_44 = 0 ; V_44 < 2 ; V_44 ++ ) {
if ( V_2 -> V_69 [ V_44 ] !=
V_41 -> V_31 . integer . V_31 [ V_44 ] ) {
V_2 -> V_69 [ V_44 ] =
V_41 -> V_31 . integer . V_31 [ V_44 ] ;
if ( V_2 -> V_70 [ V_44 ] )
F_16 ( V_2 , 0 , V_44 ) ;
V_43 = 1 ;
}
}
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return V_43 ;
}
static int F_25 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
V_41 -> V_31 . integer . V_31 [ 0 ] = V_2 -> V_70 [ 0 ] ;
V_41 -> V_31 . integer . V_31 [ 1 ] = V_2 -> V_70 [ 1 ] ;
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return 0 ;
}
static int F_26 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
int V_43 = 0 ;
int V_44 ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
for ( V_44 = 0 ; V_44 < 2 ; V_44 ++ ) {
if ( V_2 -> V_70 [ V_44 ] !=
V_41 -> V_31 . integer . V_31 [ V_44 ] ) {
V_2 -> V_70 [ V_44 ] =
! ! V_41 -> V_31 . integer . V_31 [ V_44 ] ;
V_43 |= ( 1 << V_44 ) ;
}
}
if ( V_43 & 0x01 )
F_16 ( V_2 , 0 , 0 ) ;
if ( V_43 & 0x02 )
F_16 ( V_2 , 0 , 1 ) ;
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return ( V_43 != 0 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_7 V_8 ;
unsigned int V_75 , V_76 ;
unsigned int V_77 ;
int V_5 , V_43 ;
switch ( V_2 -> V_18 ) {
case 0 : V_75 = V_78 ; V_77 = V_79 ; break;
case 1 : V_75 = V_80 ; V_77 = V_81 ; break;
case 2 : V_75 = V_82 ; V_77 = V_83 ; break;
case 3 : V_75 = V_84 ; V_77 = V_85 ; break;
default: return - V_22 ;
}
if ( V_2 -> V_86 != 0 ) {
V_76 = V_75 ;
} else {
V_76 = 0 ;
}
F_28 ( V_2 -> V_20 , V_75 , V_76 , & V_43 ) ;
if ( V_43 ) {
F_2 ( & V_8 , V_87 ) ;
V_8 . V_10 [ 0 ] |= ( 1 << V_2 -> V_18 ) ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_2 -> V_20 -> V_88 ) {
int V_44 ;
unsigned int V_89 = 0xC0 ;
for ( V_44 = 0 ; ( V_44 < 4 ) && ( V_44 < V_2 -> V_20 -> V_90 ) ; V_44 ++ ) {
if ( V_2 -> V_20 -> V_2 [ V_44 ] -> V_86 == 2 )
V_89 |= ( 1 << ( 3 - V_44 ) ) ;
}
F_2 ( & V_8 , V_9 ) ;
V_8 . V_19 = 2 ;
V_8 . V_10 [ 0 ] |= V_91 ;
V_8 . V_10 [ 1 ] = V_89 ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
} else {
int V_92 = 0 ;
if ( V_2 -> V_86 == 2 )
V_92 = 1 ;
F_2 ( & V_8 , V_9 ) ;
V_8 . V_19 = 3 ;
V_8 . V_10 [ 0 ] |= V_93 ;
V_8 . V_10 [ 1 ] = V_77 ;
V_8 . V_10 [ 2 ] = ( ( V_94 & V_95 ) |
( V_92 ? 0x41 : 0x54 ) ) ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 )
return V_5 ;
V_8 . V_10 [ 2 ] = ( ( V_96 & V_95 ) |
( V_92 ? 0x41 : 0x49 ) ) ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
}
return V_5 ;
}
static int F_29 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
static const char * V_97 [ 5 ] = {
L_6 , L_7 , L_8 , L_9 , L_10
} ;
int V_44 ;
struct V_1 * V_2 = F_6 ( V_24 ) ;
V_44 = 2 ;
if ( V_2 -> V_20 -> V_98 ) {
V_44 = 3 ;
if ( V_2 -> V_20 -> V_99 )
V_44 = 5 ;
}
V_26 -> type = V_100 ;
V_26 -> V_28 = 1 ;
V_26 -> V_31 . V_101 . V_102 = V_44 ;
if ( V_26 -> V_31 . V_101 . V_103 > ( V_44 - 1 ) )
V_26 -> V_31 . V_101 . V_103 = V_44 - 1 ;
strcpy ( V_26 -> V_31 . V_101 . V_104 ,
V_97 [ V_26 -> V_31 . V_101 . V_103 ] ) ;
return 0 ;
}
static int F_30 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
V_41 -> V_31 . V_101 . V_103 [ 0 ] = V_2 -> V_86 ;
return 0 ;
}
static int F_31 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
int V_105 = 0 ;
int V_44 = 2 ;
if ( V_2 -> V_20 -> V_98 ) {
V_44 = 3 ;
if ( V_2 -> V_20 -> V_99 )
V_44 = 5 ;
}
if ( V_41 -> V_31 . V_101 . V_103 [ 0 ] >= V_44 )
return - V_22 ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
if ( V_2 -> V_86 != V_41 -> V_31 . V_101 . V_103 [ 0 ] ) {
V_2 -> V_86 = V_41 -> V_31 . V_101 . V_103 [ 0 ] ;
if ( V_2 -> V_20 -> V_30 )
F_32 ( V_2 ) ;
else
F_27 ( V_2 ) ;
V_105 = 1 ;
}
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return V_105 ;
}
static int F_33 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
static const char * V_106 [ 7 ] = {
L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17
} ;
static const char * V_107 [ 3 ] = {
L_11 , L_13 , L_14
} ;
const char * * V_97 ;
struct V_108 * V_20 = F_6 ( V_24 ) ;
int V_109 = 2 ;
if ( V_20 -> V_98 ) {
V_109 += V_20 -> V_90 ;
if ( ! V_20 -> V_30 )
V_109 += 1 ;
}
if ( V_20 -> V_30 ) {
V_97 = V_107 ;
F_34 ( V_109 > ( V_110 + 1 ) ) ;
} else {
V_97 = V_106 ;
F_34 ( V_109 > ( V_111 + 1 ) ) ;
}
V_26 -> type = V_100 ;
V_26 -> V_28 = 1 ;
V_26 -> V_31 . V_101 . V_102 = V_109 ;
if ( V_26 -> V_31 . V_101 . V_103 >= V_109 )
V_26 -> V_31 . V_101 . V_103 = V_109 - 1 ;
strcpy ( V_26 -> V_31 . V_101 . V_104 ,
V_97 [ V_26 -> V_31 . V_101 . V_103 ] ) ;
return 0 ;
}
static int F_35 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_108 * V_20 = F_6 ( V_24 ) ;
V_41 -> V_31 . V_101 . V_103 [ 0 ] = V_20 -> V_112 ;
return 0 ;
}
static int F_36 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_108 * V_20 = F_6 ( V_24 ) ;
int V_113 , V_105 = 0 ;
unsigned int V_109 = 2 ;
if ( V_20 -> V_98 ) {
V_109 += V_20 -> V_90 ;
if ( ! V_20 -> V_30 )
V_109 += 1 ;
}
if ( V_41 -> V_31 . V_101 . V_103 [ 0 ] >= V_109 )
return - V_22 ;
F_8 ( & V_20 -> V_42 ) ;
if ( V_20 -> V_112 != V_41 -> V_31 . V_101 . V_103 [ 0 ] ) {
F_8 ( & V_20 -> V_114 ) ;
V_20 -> V_112 = V_41 -> V_31 . V_101 . V_103 [ 0 ] ;
V_113 = 0 ;
if ( V_20 -> V_112 != V_115 ) {
F_37 ( V_20 , V_20 -> V_112 ,
& V_113 ) ;
} else {
V_113 = V_20 -> V_116 ;
if ( ! V_113 )
V_113 = 48000 ;
}
if ( V_113 ) {
F_38 ( V_20 , V_113 ) ;
if ( V_20 -> V_116 )
V_20 -> V_116 = V_113 ;
}
F_9 ( & V_20 -> V_114 ) ;
V_105 = 1 ;
}
F_9 ( & V_20 -> V_42 ) ;
return V_105 ;
}
static int F_39 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
struct V_108 * V_20 = F_6 ( V_24 ) ;
V_26 -> type = V_27 ;
V_26 -> V_28 = 3 + V_20 -> V_90 ;
V_26 -> V_31 . integer . V_32 = 0 ;
V_26 -> V_31 . integer . V_34 = 192000 ;
return 0 ;
}
static int F_40 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_108 * V_20 = F_6 ( V_24 ) ;
int V_44 , V_5 , V_113 ;
F_8 ( & V_20 -> V_42 ) ;
for( V_44 = 0 ; V_44 < 3 + V_20 -> V_90 ; V_44 ++ ) {
if ( V_44 == V_115 )
V_113 = V_20 -> V_117 ;
else {
V_5 = F_37 ( V_20 , V_44 , & V_113 ) ;
if ( V_5 )
break;
}
V_41 -> V_31 . integer . V_31 [ V_44 ] = V_113 ;
}
F_9 ( & V_20 -> V_42 ) ;
return 0 ;
}
static int F_41 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
V_26 -> type = V_118 ;
V_26 -> V_28 = 1 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
int V_119 , unsigned char * V_120 )
{
int V_44 , V_5 ;
unsigned char V_121 ;
struct V_7 V_8 ;
F_2 ( & V_8 , V_122 ) ;
V_8 . V_10 [ 0 ] |= V_93 ;
switch ( V_2 -> V_18 ) {
case 0 : V_8 . V_10 [ 1 ] = V_79 ; break;
case 1 : V_8 . V_10 [ 1 ] = V_81 ; break;
case 2 : V_8 . V_10 [ 1 ] = V_83 ; break;
case 3 : V_8 . V_10 [ 1 ] = V_85 ; break;
default: return - V_22 ;
}
if ( V_2 -> V_20 -> V_88 ) {
switch ( V_119 ) {
case 0 : V_8 . V_10 [ 2 ] = V_123 ; break;
case 1 : V_8 . V_10 [ 2 ] = V_124 ; break;
case 2 : V_8 . V_10 [ 2 ] = V_125 ; break;
case 3 : V_8 . V_10 [ 2 ] = V_126 ; break;
case 4 : V_8 . V_10 [ 2 ] = V_127 ; break;
default: return - V_22 ;
}
} else {
switch ( V_119 ) {
case 0 : V_8 . V_10 [ 2 ] = V_128 ; break;
case 1 : V_8 . V_10 [ 2 ] = V_129 ; break;
case 2 : V_8 . V_10 [ 2 ] = V_130 ; break;
case 3 : V_8 . V_10 [ 2 ] = V_131 ; break;
case 4 : V_8 . V_10 [ 2 ] = V_132 ; break;
default: return - V_22 ;
}
}
V_8 . V_10 [ 1 ] &= 0x0fffff ;
V_8 . V_10 [ 2 ] &= V_95 ;
V_8 . V_19 = 3 ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_20 -> V_88 ) {
V_121 = ( unsigned char ) V_8 . V_133 [ 1 ] ;
} else {
V_121 = 0 ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ ) {
V_121 <<= 1 ;
if ( V_8 . V_133 [ 1 ] & ( 1 << V_44 ) )
V_121 |= 1 ;
}
}
F_43 ( L_18 ,
V_2 -> V_18 , V_119 , V_121 ) ;
* V_120 = V_121 ;
return 0 ;
}
static int F_44 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
unsigned char V_120 ;
int V_44 , V_5 ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
for( V_44 = 0 ; V_44 < 5 ; V_44 ++ ) {
if ( V_24 -> V_29 == 0 )
V_120 = V_2 -> V_120 [ V_44 ] ;
else {
if ( V_2 -> V_20 -> V_30 )
V_5 = F_45 ( V_2 , V_44 ,
& V_120 ) ;
else
V_5 = F_42 ( V_2 , V_44 ,
& V_120 ) ;
if ( V_5 )
break;
}
V_41 -> V_31 . V_134 . V_135 [ V_44 ] = V_120 ;
}
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return 0 ;
}
static int F_46 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < 5 ; V_44 ++ )
V_41 -> V_31 . V_134 . V_135 [ V_44 ] = 0xff ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
int V_119 , unsigned char V_120 )
{
int V_44 , V_5 , V_10 ;
unsigned char V_136 = V_120 ;
unsigned char V_137 = V_2 -> V_120 [ V_119 ] ;
struct V_7 V_8 ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ ) {
if ( ( V_137 & 0x01 ) != ( V_136 & 0x01 ) ) {
V_10 = V_2 -> V_18 & 0x03 ;
if ( V_2 -> V_18 > 3 )
V_10 |= 1 << 22 ;
V_10 |= ( ( V_119 << 3 ) + V_44 ) << 2 ;
V_10 |= ( V_136 & 0x01 ) << 23 ;
F_2 ( & V_8 , V_9 ) ;
V_8 . V_10 [ 0 ] |= V_138 ;
V_8 . V_10 [ 1 ] = V_10 ;
V_8 . V_19 = 2 ;
F_43 ( L_19 ,
V_2 -> V_18 , V_119 , V_44 , V_10 ) ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 )
return V_5 ;
}
V_137 >>= 1 ;
V_136 >>= 1 ;
}
V_2 -> V_120 [ V_119 ] = V_120 ;
return 0 ;
}
static int F_48 ( struct V_23 * V_24 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
int V_44 , V_43 = 0 ;
F_8 ( & V_2 -> V_20 -> V_42 ) ;
for ( V_44 = 0 ; V_44 < 5 ; V_44 ++ ) {
if ( V_41 -> V_31 . V_134 . V_135 [ V_44 ] != V_2 -> V_120 [ V_44 ] ) {
if ( V_2 -> V_20 -> V_30 )
F_49 ( V_2 , V_44 ,
V_41 -> V_31 . V_134 . V_135 [ V_44 ] ) ;
else
F_47 ( V_2 , V_44 ,
V_41 -> V_31 . V_134 . V_135 [ V_44 ] ) ;
V_43 = 1 ;
}
}
F_9 ( & V_2 -> V_20 -> V_42 ) ;
return V_43 ;
}
static void F_50 ( struct V_1 * V_2 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < 2 ; V_44 ++ ) {
if ( V_2 -> V_139 ) {
int V_74 ;
for ( V_74 = 0 ; V_74 < V_140 ; V_74 ++ ) {
V_2 -> V_53 [ V_74 ] [ V_44 ] = 1 ;
V_2 -> V_54 [ V_74 ] [ V_44 ] =
V_141 ;
}
V_2 -> V_120 [ 0 ] = ( V_142 |
V_143 ) ;
#ifdef F_51
V_2 -> V_14 [ V_44 ] = 1 ;
if ( V_2 -> V_20 -> V_30 )
V_2 -> V_15 [ V_44 ] =
V_144 ;
else {
V_2 -> V_15 [ V_44 ] =
V_145 ;
F_1 ( V_2 , 0 , V_44 ) ;
}
#endif
if ( V_2 -> V_20 -> V_30 )
F_11 ( V_2 , 0 , V_44 ) ;
}
if ( V_2 -> V_146 ) {
V_2 -> V_66 [ V_44 ] =
V_141 ;
V_2 -> V_147 = 1 ;
#ifdef F_51
if ( V_2 -> V_20 -> V_30 )
V_2 -> V_12 [ V_44 ] =
V_148 ;
else {
V_2 -> V_12 [ V_44 ] =
V_149 ;
F_1 ( V_2 , 1 , V_44 ) ;
}
#endif
if ( V_2 -> V_20 -> V_30 )
F_11 ( V_2 , 1 , V_44 ) ;
}
}
return;
}
int F_52 ( struct V_108 * V_20 )
{
struct V_1 * V_2 ;
int V_5 , V_44 ;
F_53 ( & V_20 -> V_42 ) ;
for ( V_44 = 0 ; V_44 < V_20 -> V_150 ; V_44 ++ ) {
struct V_151 V_121 ;
V_2 = V_20 -> V_2 [ V_44 ] ;
if ( V_2 -> V_139 ) {
V_121 = V_152 ;
V_121 . V_104 = L_20 ;
V_121 . V_29 = 0 ;
if ( V_20 -> V_30 )
V_121 . V_153 . V_154 = V_155 ;
else
V_121 . V_153 . V_154 = V_156 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_121 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_158 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_121 = V_159 ;
V_121 . V_104 = L_21 ;
V_121 . V_28 = V_140 ;
V_121 . V_29 = 0 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_121 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_160 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_161 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_162 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_2 -> V_146 ) {
V_121 = V_152 ;
V_121 . V_104 = L_22 ;
V_121 . V_29 = 1 ;
if ( V_20 -> V_30 )
V_121 . V_153 . V_154 = V_163 ;
else
V_121 . V_153 . V_154 = V_164 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_121 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_121 = V_159 ;
V_121 . V_104 = L_23 ;
V_121 . V_28 = 1 ;
V_121 . V_29 = 1 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_121 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_165 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_166 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_167 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_20 -> V_30 ) {
V_5 = F_56 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
}
if ( V_2 -> V_146 > 0 && V_2 -> V_139 > 0 ) {
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_168 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_169 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_44 == 0 ) {
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_170 , V_20 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_157 ,
F_55 ( & V_171 , V_20 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
F_50 ( V_2 ) ;
}
return 0 ;
}
