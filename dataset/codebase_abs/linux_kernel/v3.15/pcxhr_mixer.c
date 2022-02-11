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
F_4 ( V_2 -> V_21 -> V_22 ,
L_1
L_2 ,
V_2 -> V_18 , V_3 , V_5 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_5 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
V_27 -> type = V_28 ;
V_27 -> V_29 = 2 ;
if ( V_25 -> V_30 == 0 ) {
if ( V_2 -> V_20 -> V_31 ) {
V_27 -> V_32 . integer . V_33 =
V_34 ;
V_27 -> V_32 . integer . V_35 =
V_36 ;
} else {
V_27 -> V_32 . integer . V_33 =
V_16 ;
V_27 -> V_32 . integer . V_35 =
V_17 ;
}
} else {
if ( V_2 -> V_20 -> V_31 ) {
V_27 -> V_32 . integer . V_33 =
V_37 ;
V_27 -> V_32 . integer . V_35 =
V_38 ;
} else {
V_27 -> V_32 . integer . V_33 =
V_39 ;
V_27 -> V_32 . integer . V_35 =
V_40 ;
}
}
return 0 ;
}
static int F_7 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
if ( V_25 -> V_30 == 0 ) {
V_42 -> V_32 . integer . V_32 [ 0 ] = V_2 -> V_15 [ 0 ] ;
V_42 -> V_32 . integer . V_32 [ 1 ] = V_2 -> V_15 [ 1 ] ;
} else {
V_42 -> V_32 . integer . V_32 [ 0 ] = V_2 -> V_12 [ 0 ] ;
V_42 -> V_32 . integer . V_32 [ 1 ] = V_2 -> V_12 [ 1 ] ;
}
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return 0 ;
}
static int F_10 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_44 = 0 ;
int V_3 , V_45 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
V_3 = ( V_25 -> V_30 != 0 ) ;
for ( V_45 = 0 ; V_45 < 2 ; V_45 ++ ) {
int V_46 = V_42 -> V_32 . integer . V_32 [ V_45 ] ;
int * V_47 = V_3 ?
& V_2 -> V_12 [ V_45 ] :
& V_2 -> V_15 [ V_45 ] ;
if ( V_3 ) {
if ( V_2 -> V_20 -> V_31 ) {
if ( V_46 < V_37 ||
V_46 > V_38 )
continue;
} else {
if ( V_46 < V_39 ||
V_46 > V_40 )
continue;
}
} else {
if ( V_2 -> V_20 -> V_31 ) {
if ( V_46 < V_34 ||
V_46 > V_36 )
continue;
} else {
if ( V_46 < V_16 ||
V_46 > V_17 )
continue;
}
}
if ( * V_47 != V_46 ) {
* V_47 = V_46 ;
V_44 = 1 ;
if ( V_2 -> V_20 -> V_31 )
F_11 ( V_2 ,
V_3 , V_45 ) ;
else
F_1 ( V_2 ,
V_3 , V_45 ) ;
}
}
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return V_44 ;
}
static int F_12 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
V_42 -> V_32 . integer . V_32 [ 0 ] = V_2 -> V_14 [ 0 ] ;
V_42 -> V_32 . integer . V_32 [ 1 ] = V_2 -> V_14 [ 1 ] ;
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return 0 ;
}
static int F_13 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_45 , V_44 = 0 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
for( V_45 = 0 ; V_45 < 2 ; V_45 ++ ) {
if ( V_2 -> V_14 [ V_45 ] !=
V_42 -> V_32 . integer . V_32 [ V_45 ] ) {
V_2 -> V_14 [ V_45 ] =
! ! V_42 -> V_32 . integer . V_32 [ V_45 ] ;
V_44 = 1 ;
if ( V_2 -> V_20 -> V_31 )
F_11 ( V_2 , 0 , V_45 ) ;
else
F_1 ( V_2 , 0 , V_45 ) ;
}
}
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return V_44 ;
}
static int F_14 ( struct V_1 * V_2 , int V_48 )
{
int V_5 ;
struct V_7 V_8 ;
struct V_49 * V_50 = & V_2 -> V_51 ;
int V_52 , V_53 ;
if ( V_2 -> V_54 [ V_48 ] [ 0 ] )
V_52 = V_2 -> V_55 [ V_48 ] [ 0 ] ;
else
V_52 = V_56 ;
if ( V_2 -> V_54 [ V_48 ] [ 1 ] )
V_53 = V_2 -> V_55 [ V_48 ] [ 1 ] ;
else
V_53 = V_56 ;
F_2 ( & V_8 , V_57 ) ;
F_15 ( & V_8 , 0 , V_50 -> V_58 , 0 , 1 << V_48 ) ;
V_8 . V_10 [ 0 ] |= V_59 ;
V_8 . V_10 [ 2 ] = V_60 | V_61 ;
V_8 . V_10 [ 2 ] |= ( V_52 << 10 ) ;
V_8 . V_10 [ 3 ] = V_60 | V_62 ;
V_8 . V_10 [ 3 ] |= V_53 ;
V_8 . V_19 = 4 ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_21 -> V_22 , L_3
L_4 , V_2 -> V_18 , V_5 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_63 , int V_4 )
{
int V_5 ;
struct V_7 V_8 ;
struct V_49 * V_50 ;
if ( V_63 )
V_50 = & V_2 -> V_64 [ 0 ] ;
else
V_50 = & V_2 -> V_51 ;
F_2 ( & V_8 , V_65 ) ;
F_15 ( & V_8 , V_63 , 0 , 0 ,
1 << ( V_4 + V_50 -> V_58 ) ) ;
if ( V_63 ) {
V_8 . V_10 [ 0 ] |= V_66 ;
V_8 . V_10 [ 2 ] = V_2 -> V_67 [ V_4 ] ;
} else {
V_8 . V_10 [ 0 ] |= V_68 |
V_69 ;
V_8 . V_10 [ 2 ] = V_2 -> V_70 [ V_4 ] << 10 ;
if ( V_2 -> V_71 [ V_4 ] == 0 )
V_8 . V_10 [ 2 ] |= V_72 ;
}
V_8 . V_19 = 3 ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_21 -> V_22 ,
L_5 ,
V_2 -> V_18 , V_5 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_17 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_27 -> type = V_28 ;
V_27 -> V_29 = 2 ;
V_27 -> V_32 . integer . V_33 = V_56 ;
V_27 -> V_32 . integer . V_35 = V_73 ;
return 0 ;
}
static int F_18 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_48 = F_19 ( V_25 , & V_42 -> V_74 ) ;
int * V_47 ;
int V_3 = V_25 -> V_30 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
if ( V_3 )
V_47 = V_2 -> V_67 ;
else
V_47 = V_2 -> V_55 [ V_48 ] ;
V_42 -> V_32 . integer . V_32 [ 0 ] = V_47 [ 0 ] ;
V_42 -> V_32 . integer . V_32 [ 1 ] = V_47 [ 1 ] ;
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return 0 ;
}
static int F_20 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_48 = F_19 ( V_25 , & V_42 -> V_74 ) ;
int V_44 = 0 ;
int V_3 = V_25 -> V_30 ;
int * V_47 ;
int V_45 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
if ( V_3 )
V_47 = V_2 -> V_67 ;
else
V_47 = V_2 -> V_55 [ V_48 ] ;
for ( V_45 = 0 ; V_45 < 2 ; V_45 ++ ) {
int V_6 = V_42 -> V_32 . integer . V_32 [ V_45 ] ;
if ( V_6 < V_56 ||
V_6 > V_73 )
continue;
if ( V_47 [ V_45 ] != V_6 ) {
V_47 [ V_45 ] = V_6 ;
V_44 = 1 ;
if ( V_3 )
F_16 ( V_2 , 1 , V_45 ) ;
}
}
if ( ! V_3 && V_44 )
F_14 ( V_2 , V_48 ) ;
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return V_44 ;
}
static int F_21 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_48 = F_19 ( V_25 , & V_42 -> V_74 ) ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
V_42 -> V_32 . integer . V_32 [ 0 ] = V_2 -> V_54 [ V_48 ] [ 0 ] ;
V_42 -> V_32 . integer . V_32 [ 1 ] = V_2 -> V_54 [ V_48 ] [ 1 ] ;
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_44 = 0 ;
int V_48 = F_19 ( V_25 , & V_42 -> V_74 ) ;
int V_45 , V_75 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
V_75 = V_48 ;
for ( V_45 = 0 ; V_45 < 2 ; V_45 ++ ) {
if ( V_2 -> V_54 [ V_75 ] [ V_45 ] !=
V_42 -> V_32 . integer . V_32 [ V_45 ] ) {
V_2 -> V_54 [ V_75 ] [ V_45 ] =
! ! V_42 -> V_32 . integer . V_32 [ V_45 ] ;
V_44 = 1 ;
}
}
if ( V_44 )
F_14 ( V_2 , V_48 ) ;
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return V_44 ;
}
static int F_23 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
V_42 -> V_32 . integer . V_32 [ 0 ] = V_2 -> V_70 [ 0 ] ;
V_42 -> V_32 . integer . V_32 [ 1 ] = V_2 -> V_70 [ 1 ] ;
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_44 = 0 ;
int V_45 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
for ( V_45 = 0 ; V_45 < 2 ; V_45 ++ ) {
if ( V_2 -> V_70 [ V_45 ] !=
V_42 -> V_32 . integer . V_32 [ V_45 ] ) {
V_2 -> V_70 [ V_45 ] =
V_42 -> V_32 . integer . V_32 [ V_45 ] ;
if ( V_2 -> V_71 [ V_45 ] )
F_16 ( V_2 , 0 , V_45 ) ;
V_44 = 1 ;
}
}
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return V_44 ;
}
static int F_25 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
V_42 -> V_32 . integer . V_32 [ 0 ] = V_2 -> V_71 [ 0 ] ;
V_42 -> V_32 . integer . V_32 [ 1 ] = V_2 -> V_71 [ 1 ] ;
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return 0 ;
}
static int F_26 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_44 = 0 ;
int V_45 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
for ( V_45 = 0 ; V_45 < 2 ; V_45 ++ ) {
if ( V_2 -> V_71 [ V_45 ] !=
V_42 -> V_32 . integer . V_32 [ V_45 ] ) {
V_2 -> V_71 [ V_45 ] =
! ! V_42 -> V_32 . integer . V_32 [ V_45 ] ;
V_44 |= ( 1 << V_45 ) ;
}
}
if ( V_44 & 0x01 )
F_16 ( V_2 , 0 , 0 ) ;
if ( V_44 & 0x02 )
F_16 ( V_2 , 0 , 1 ) ;
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return ( V_44 != 0 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_7 V_8 ;
unsigned int V_76 , V_77 ;
unsigned int V_78 ;
int V_5 , V_44 ;
switch ( V_2 -> V_18 ) {
case 0 : V_76 = V_79 ; V_78 = V_80 ; break;
case 1 : V_76 = V_81 ; V_78 = V_82 ; break;
case 2 : V_76 = V_83 ; V_78 = V_84 ; break;
case 3 : V_76 = V_85 ; V_78 = V_86 ; break;
default: return - V_23 ;
}
if ( V_2 -> V_87 != 0 ) {
V_77 = V_76 ;
} else {
V_77 = 0 ;
}
F_28 ( V_2 -> V_20 , V_76 , V_77 , & V_44 ) ;
if ( V_44 ) {
F_2 ( & V_8 , V_88 ) ;
V_8 . V_10 [ 0 ] |= ( 1 << V_2 -> V_18 ) ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 )
return V_5 ;
}
if ( V_2 -> V_20 -> V_89 ) {
int V_45 ;
unsigned int V_90 = 0xC0 ;
for ( V_45 = 0 ; ( V_45 < 4 ) && ( V_45 < V_2 -> V_20 -> V_91 ) ; V_45 ++ ) {
if ( V_2 -> V_20 -> V_2 [ V_45 ] -> V_87 == 2 )
V_90 |= ( 1 << ( 3 - V_45 ) ) ;
}
F_2 ( & V_8 , V_9 ) ;
V_8 . V_19 = 2 ;
V_8 . V_10 [ 0 ] |= V_92 ;
V_8 . V_10 [ 1 ] = V_90 ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
} else {
int V_93 = 0 ;
if ( V_2 -> V_87 == 2 )
V_93 = 1 ;
F_2 ( & V_8 , V_9 ) ;
V_8 . V_19 = 3 ;
V_8 . V_10 [ 0 ] |= V_94 ;
V_8 . V_10 [ 1 ] = V_78 ;
V_8 . V_10 [ 2 ] = ( ( V_95 & V_96 ) |
( V_93 ? 0x41 : 0x54 ) ) ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 )
return V_5 ;
V_8 . V_10 [ 2 ] = ( ( V_97 & V_96 ) |
( V_93 ? 0x41 : 0x49 ) ) ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
}
return V_5 ;
}
static int F_29 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
static const char * V_98 [ 5 ] = {
L_6 , L_7 , L_8 , L_9 , L_10
} ;
int V_45 ;
struct V_1 * V_2 = F_6 ( V_25 ) ;
V_45 = 2 ;
if ( V_2 -> V_20 -> V_99 ) {
V_45 = 3 ;
if ( V_2 -> V_20 -> V_100 )
V_45 = 5 ;
}
V_27 -> type = V_101 ;
V_27 -> V_29 = 1 ;
V_27 -> V_32 . V_102 . V_103 = V_45 ;
if ( V_27 -> V_32 . V_102 . V_104 > ( V_45 - 1 ) )
V_27 -> V_32 . V_102 . V_104 = V_45 - 1 ;
strcpy ( V_27 -> V_32 . V_102 . V_105 ,
V_98 [ V_27 -> V_32 . V_102 . V_104 ] ) ;
return 0 ;
}
static int F_30 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
V_42 -> V_32 . V_102 . V_104 [ 0 ] = V_2 -> V_87 ;
return 0 ;
}
static int F_31 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_106 = 0 ;
int V_45 = 2 ;
if ( V_2 -> V_20 -> V_99 ) {
V_45 = 3 ;
if ( V_2 -> V_20 -> V_100 )
V_45 = 5 ;
}
if ( V_42 -> V_32 . V_102 . V_104 [ 0 ] >= V_45 )
return - V_23 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
if ( V_2 -> V_87 != V_42 -> V_32 . V_102 . V_104 [ 0 ] ) {
V_2 -> V_87 = V_42 -> V_32 . V_102 . V_104 [ 0 ] ;
if ( V_2 -> V_20 -> V_31 )
F_32 ( V_2 ) ;
else
F_27 ( V_2 ) ;
V_106 = 1 ;
}
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return V_106 ;
}
static int F_33 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
static const char * V_107 [ 7 ] = {
L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17
} ;
static const char * V_108 [ 3 ] = {
L_11 , L_13 , L_14
} ;
const char * * V_98 ;
struct V_109 * V_20 = F_6 ( V_25 ) ;
int V_110 = 2 ;
if ( V_20 -> V_99 ) {
V_110 += V_20 -> V_91 ;
if ( ! V_20 -> V_31 )
V_110 += 1 ;
}
if ( V_20 -> V_31 ) {
V_98 = V_108 ;
F_34 ( V_110 > ( V_111 + 1 ) ) ;
} else {
V_98 = V_107 ;
F_34 ( V_110 > ( V_112 + 1 ) ) ;
}
V_27 -> type = V_101 ;
V_27 -> V_29 = 1 ;
V_27 -> V_32 . V_102 . V_103 = V_110 ;
if ( V_27 -> V_32 . V_102 . V_104 >= V_110 )
V_27 -> V_32 . V_102 . V_104 = V_110 - 1 ;
strcpy ( V_27 -> V_32 . V_102 . V_105 ,
V_98 [ V_27 -> V_32 . V_102 . V_104 ] ) ;
return 0 ;
}
static int F_35 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_109 * V_20 = F_6 ( V_25 ) ;
V_42 -> V_32 . V_102 . V_104 [ 0 ] = V_20 -> V_113 ;
return 0 ;
}
static int F_36 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_109 * V_20 = F_6 ( V_25 ) ;
int V_114 , V_106 = 0 ;
unsigned int V_110 = 2 ;
if ( V_20 -> V_99 ) {
V_110 += V_20 -> V_91 ;
if ( ! V_20 -> V_31 )
V_110 += 1 ;
}
if ( V_42 -> V_32 . V_102 . V_104 [ 0 ] >= V_110 )
return - V_23 ;
F_8 ( & V_20 -> V_43 ) ;
if ( V_20 -> V_113 != V_42 -> V_32 . V_102 . V_104 [ 0 ] ) {
F_8 ( & V_20 -> V_115 ) ;
V_20 -> V_113 = V_42 -> V_32 . V_102 . V_104 [ 0 ] ;
V_114 = 0 ;
if ( V_20 -> V_113 != V_116 ) {
F_37 ( V_20 , V_20 -> V_113 ,
& V_114 ) ;
} else {
V_114 = V_20 -> V_117 ;
if ( ! V_114 )
V_114 = 48000 ;
}
if ( V_114 ) {
F_38 ( V_20 , V_114 ) ;
if ( V_20 -> V_117 )
V_20 -> V_117 = V_114 ;
}
F_9 ( & V_20 -> V_115 ) ;
V_106 = 1 ;
}
F_9 ( & V_20 -> V_43 ) ;
return V_106 ;
}
static int F_39 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_109 * V_20 = F_6 ( V_25 ) ;
V_27 -> type = V_28 ;
V_27 -> V_29 = 3 + V_20 -> V_91 ;
V_27 -> V_32 . integer . V_33 = 0 ;
V_27 -> V_32 . integer . V_35 = 192000 ;
return 0 ;
}
static int F_40 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_109 * V_20 = F_6 ( V_25 ) ;
int V_45 , V_5 , V_114 ;
F_8 ( & V_20 -> V_43 ) ;
for( V_45 = 0 ; V_45 < 3 + V_20 -> V_91 ; V_45 ++ ) {
if ( V_45 == V_116 )
V_114 = V_20 -> V_118 ;
else {
V_5 = F_37 ( V_20 , V_45 , & V_114 ) ;
if ( V_5 )
break;
}
V_42 -> V_32 . integer . V_32 [ V_45 ] = V_114 ;
}
F_9 ( & V_20 -> V_43 ) ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_27 -> type = V_119 ;
V_27 -> V_29 = 1 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
int V_120 , unsigned char * V_121 )
{
int V_45 , V_5 ;
unsigned char V_122 ;
struct V_7 V_8 ;
F_2 ( & V_8 , V_123 ) ;
V_8 . V_10 [ 0 ] |= V_94 ;
switch ( V_2 -> V_18 ) {
case 0 : V_8 . V_10 [ 1 ] = V_80 ; break;
case 1 : V_8 . V_10 [ 1 ] = V_82 ; break;
case 2 : V_8 . V_10 [ 1 ] = V_84 ; break;
case 3 : V_8 . V_10 [ 1 ] = V_86 ; break;
default: return - V_23 ;
}
if ( V_2 -> V_20 -> V_89 ) {
switch ( V_120 ) {
case 0 : V_8 . V_10 [ 2 ] = V_124 ; break;
case 1 : V_8 . V_10 [ 2 ] = V_125 ; break;
case 2 : V_8 . V_10 [ 2 ] = V_126 ; break;
case 3 : V_8 . V_10 [ 2 ] = V_127 ; break;
case 4 : V_8 . V_10 [ 2 ] = V_128 ; break;
default: return - V_23 ;
}
} else {
switch ( V_120 ) {
case 0 : V_8 . V_10 [ 2 ] = V_129 ; break;
case 1 : V_8 . V_10 [ 2 ] = V_130 ; break;
case 2 : V_8 . V_10 [ 2 ] = V_131 ; break;
case 3 : V_8 . V_10 [ 2 ] = V_132 ; break;
case 4 : V_8 . V_10 [ 2 ] = V_133 ; break;
default: return - V_23 ;
}
}
V_8 . V_10 [ 1 ] &= 0x0fffff ;
V_8 . V_10 [ 2 ] &= V_96 ;
V_8 . V_19 = 3 ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_20 -> V_89 ) {
V_122 = ( unsigned char ) V_8 . V_134 [ 1 ] ;
} else {
V_122 = 0 ;
for ( V_45 = 0 ; V_45 < 8 ; V_45 ++ ) {
V_122 <<= 1 ;
if ( V_8 . V_134 [ 1 ] & ( 1 << V_45 ) )
V_122 |= 1 ;
}
}
F_4 ( V_2 -> V_21 -> V_22 , L_18 ,
V_2 -> V_18 , V_120 , V_122 ) ;
* V_121 = V_122 ;
return 0 ;
}
static int F_43 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned char V_121 ;
int V_45 , V_5 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
for( V_45 = 0 ; V_45 < 5 ; V_45 ++ ) {
if ( V_25 -> V_30 == 0 )
V_121 = V_2 -> V_121 [ V_45 ] ;
else {
if ( V_2 -> V_20 -> V_31 )
V_5 = F_44 ( V_2 , V_45 ,
& V_121 ) ;
else
V_5 = F_42 ( V_2 , V_45 ,
& V_121 ) ;
if ( V_5 )
break;
}
V_42 -> V_32 . V_135 . V_136 [ V_45 ] = V_121 ;
}
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return 0 ;
}
static int F_45 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < 5 ; V_45 ++ )
V_42 -> V_32 . V_135 . V_136 [ V_45 ] = 0xff ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
int V_120 , unsigned char V_121 )
{
int V_45 , V_5 , V_10 ;
unsigned char V_137 = V_121 ;
unsigned char V_138 = V_2 -> V_121 [ V_120 ] ;
struct V_7 V_8 ;
for ( V_45 = 0 ; V_45 < 8 ; V_45 ++ ) {
if ( ( V_138 & 0x01 ) != ( V_137 & 0x01 ) ) {
V_10 = V_2 -> V_18 & 0x03 ;
if ( V_2 -> V_18 > 3 )
V_10 |= 1 << 22 ;
V_10 |= ( ( V_120 << 3 ) + V_45 ) << 2 ;
V_10 |= ( V_137 & 0x01 ) << 23 ;
F_2 ( & V_8 , V_9 ) ;
V_8 . V_10 [ 0 ] |= V_139 ;
V_8 . V_10 [ 1 ] = V_10 ;
V_8 . V_19 = 2 ;
F_4 ( V_2 -> V_21 -> V_22 ,
L_19 ,
V_2 -> V_18 , V_120 , V_45 , V_10 ) ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 )
return V_5 ;
}
V_138 >>= 1 ;
V_137 >>= 1 ;
}
V_2 -> V_121 [ V_120 ] = V_121 ;
return 0 ;
}
static int F_47 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_45 , V_44 = 0 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
for ( V_45 = 0 ; V_45 < 5 ; V_45 ++ ) {
if ( V_42 -> V_32 . V_135 . V_136 [ V_45 ] != V_2 -> V_121 [ V_45 ] ) {
if ( V_2 -> V_20 -> V_31 )
F_48 ( V_2 , V_45 ,
V_42 -> V_32 . V_135 . V_136 [ V_45 ] ) ;
else
F_46 ( V_2 , V_45 ,
V_42 -> V_32 . V_135 . V_136 [ V_45 ] ) ;
V_44 = 1 ;
}
}
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return V_44 ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < 2 ; V_45 ++ ) {
if ( V_2 -> V_140 ) {
int V_75 ;
for ( V_75 = 0 ; V_75 < V_141 ; V_75 ++ ) {
V_2 -> V_54 [ V_75 ] [ V_45 ] = 1 ;
V_2 -> V_55 [ V_75 ] [ V_45 ] =
V_142 ;
}
V_2 -> V_121 [ 0 ] = ( V_143 |
V_144 ) ;
#ifdef F_50
V_2 -> V_14 [ V_45 ] = 1 ;
if ( V_2 -> V_20 -> V_31 )
V_2 -> V_15 [ V_45 ] =
V_145 ;
else {
V_2 -> V_15 [ V_45 ] =
V_146 ;
F_1 ( V_2 , 0 , V_45 ) ;
}
#endif
if ( V_2 -> V_20 -> V_31 )
F_11 ( V_2 , 0 , V_45 ) ;
}
if ( V_2 -> V_147 ) {
V_2 -> V_67 [ V_45 ] =
V_142 ;
V_2 -> V_148 = 1 ;
#ifdef F_50
if ( V_2 -> V_20 -> V_31 )
V_2 -> V_12 [ V_45 ] =
V_149 ;
else {
V_2 -> V_12 [ V_45 ] =
V_150 ;
F_1 ( V_2 , 1 , V_45 ) ;
}
#endif
if ( V_2 -> V_20 -> V_31 )
F_11 ( V_2 , 1 , V_45 ) ;
}
}
return;
}
int F_51 ( struct V_109 * V_20 )
{
struct V_1 * V_2 ;
int V_5 , V_45 ;
F_52 ( & V_20 -> V_43 ) ;
for ( V_45 = 0 ; V_45 < V_20 -> V_151 ; V_45 ++ ) {
struct V_152 V_122 ;
V_2 = V_20 -> V_2 [ V_45 ] ;
if ( V_2 -> V_140 ) {
V_122 = V_153 ;
V_122 . V_105 = L_20 ;
V_122 . V_30 = 0 ;
if ( V_20 -> V_31 )
V_122 . V_154 . V_155 = V_156 ;
else
V_122 . V_154 . V_155 = V_157 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_122 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_158 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_122 = V_159 ;
V_122 . V_105 = L_21 ;
V_122 . V_29 = V_141 ;
V_122 . V_30 = 0 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_122 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_160 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_161 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_162 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_2 -> V_147 ) {
V_122 = V_153 ;
V_122 . V_105 = L_22 ;
V_122 . V_30 = 1 ;
if ( V_20 -> V_31 )
V_122 . V_154 . V_155 = V_163 ;
else
V_122 . V_154 . V_155 = V_164 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_122 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_122 = V_159 ;
V_122 . V_105 = L_23 ;
V_122 . V_29 = 1 ;
V_122 . V_30 = 1 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_122 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_165 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_166 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_167 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_20 -> V_31 ) {
V_5 = F_55 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
}
if ( V_2 -> V_147 > 0 && V_2 -> V_140 > 0 ) {
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_168 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_169 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_45 == 0 ) {
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_170 , V_20 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_53 ( V_2 -> V_21 ,
F_54 ( & V_171 , V_20 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
F_49 ( V_2 ) ;
}
return 0 ;
}
