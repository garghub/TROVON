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
return F_30 ( V_27 , 1 , V_45 , V_98 ) ;
}
static int F_31 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
V_42 -> V_32 . V_101 . V_102 [ 0 ] = V_2 -> V_87 ;
return 0 ;
}
static int F_32 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_103 = 0 ;
int V_45 = 2 ;
if ( V_2 -> V_20 -> V_99 ) {
V_45 = 3 ;
if ( V_2 -> V_20 -> V_100 )
V_45 = 5 ;
}
if ( V_42 -> V_32 . V_101 . V_102 [ 0 ] >= V_45 )
return - V_23 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
if ( V_2 -> V_87 != V_42 -> V_32 . V_101 . V_102 [ 0 ] ) {
V_2 -> V_87 = V_42 -> V_32 . V_101 . V_102 [ 0 ] ;
if ( V_2 -> V_20 -> V_31 )
F_33 ( V_2 ) ;
else
F_27 ( V_2 ) ;
V_103 = 1 ;
}
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return V_103 ;
}
static int F_34 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
static const char * V_104 [ 7 ] = {
L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17
} ;
static const char * V_105 [ 3 ] = {
L_11 , L_13 , L_14
} ;
const char * * V_98 ;
struct V_106 * V_20 = F_6 ( V_25 ) ;
int V_107 = 2 ;
if ( V_20 -> V_99 ) {
V_107 += V_20 -> V_91 ;
if ( ! V_20 -> V_31 )
V_107 += 1 ;
}
if ( V_20 -> V_31 ) {
V_98 = V_105 ;
F_35 ( V_107 > ( V_108 + 1 ) ) ;
} else {
V_98 = V_104 ;
F_35 ( V_107 > ( V_109 + 1 ) ) ;
}
return F_30 ( V_27 , 1 , V_107 , V_98 ) ;
}
static int F_36 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_106 * V_20 = F_6 ( V_25 ) ;
V_42 -> V_32 . V_101 . V_102 [ 0 ] = V_20 -> V_110 ;
return 0 ;
}
static int F_37 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_106 * V_20 = F_6 ( V_25 ) ;
int V_111 , V_103 = 0 ;
unsigned int V_107 = 2 ;
if ( V_20 -> V_99 ) {
V_107 += V_20 -> V_91 ;
if ( ! V_20 -> V_31 )
V_107 += 1 ;
}
if ( V_42 -> V_32 . V_101 . V_102 [ 0 ] >= V_107 )
return - V_23 ;
F_8 ( & V_20 -> V_43 ) ;
if ( V_20 -> V_110 != V_42 -> V_32 . V_101 . V_102 [ 0 ] ) {
F_8 ( & V_20 -> V_112 ) ;
V_20 -> V_110 = V_42 -> V_32 . V_101 . V_102 [ 0 ] ;
V_111 = 0 ;
if ( V_20 -> V_110 != V_113 ) {
F_38 ( V_20 , V_20 -> V_110 ,
& V_111 ) ;
} else {
V_111 = V_20 -> V_114 ;
if ( ! V_111 )
V_111 = 48000 ;
}
if ( V_111 ) {
F_39 ( V_20 , V_111 ) ;
if ( V_20 -> V_114 )
V_20 -> V_114 = V_111 ;
}
F_9 ( & V_20 -> V_112 ) ;
V_103 = 1 ;
}
F_9 ( & V_20 -> V_43 ) ;
return V_103 ;
}
static int F_40 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_106 * V_20 = F_6 ( V_25 ) ;
V_27 -> type = V_28 ;
V_27 -> V_29 = 3 + V_20 -> V_91 ;
V_27 -> V_32 . integer . V_33 = 0 ;
V_27 -> V_32 . integer . V_35 = 192000 ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_106 * V_20 = F_6 ( V_25 ) ;
int V_45 , V_5 , V_111 ;
F_8 ( & V_20 -> V_43 ) ;
for( V_45 = 0 ; V_45 < 3 + V_20 -> V_91 ; V_45 ++ ) {
if ( V_45 == V_113 )
V_111 = V_20 -> V_115 ;
else {
V_5 = F_38 ( V_20 , V_45 , & V_111 ) ;
if ( V_5 )
break;
}
V_42 -> V_32 . integer . V_32 [ V_45 ] = V_111 ;
}
F_9 ( & V_20 -> V_43 ) ;
return 0 ;
}
static int F_42 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_27 -> type = V_116 ;
V_27 -> V_29 = 1 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
int V_117 , unsigned char * V_118 )
{
int V_45 , V_5 ;
unsigned char V_119 ;
struct V_7 V_8 ;
F_2 ( & V_8 , V_120 ) ;
V_8 . V_10 [ 0 ] |= V_94 ;
switch ( V_2 -> V_18 ) {
case 0 : V_8 . V_10 [ 1 ] = V_80 ; break;
case 1 : V_8 . V_10 [ 1 ] = V_82 ; break;
case 2 : V_8 . V_10 [ 1 ] = V_84 ; break;
case 3 : V_8 . V_10 [ 1 ] = V_86 ; break;
default: return - V_23 ;
}
if ( V_2 -> V_20 -> V_89 ) {
switch ( V_117 ) {
case 0 : V_8 . V_10 [ 2 ] = V_121 ; break;
case 1 : V_8 . V_10 [ 2 ] = V_122 ; break;
case 2 : V_8 . V_10 [ 2 ] = V_123 ; break;
case 3 : V_8 . V_10 [ 2 ] = V_124 ; break;
case 4 : V_8 . V_10 [ 2 ] = V_125 ; break;
default: return - V_23 ;
}
} else {
switch ( V_117 ) {
case 0 : V_8 . V_10 [ 2 ] = V_126 ; break;
case 1 : V_8 . V_10 [ 2 ] = V_127 ; break;
case 2 : V_8 . V_10 [ 2 ] = V_128 ; break;
case 3 : V_8 . V_10 [ 2 ] = V_129 ; break;
case 4 : V_8 . V_10 [ 2 ] = V_130 ; break;
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
V_119 = ( unsigned char ) V_8 . V_131 [ 1 ] ;
} else {
V_119 = 0 ;
for ( V_45 = 0 ; V_45 < 8 ; V_45 ++ ) {
V_119 <<= 1 ;
if ( V_8 . V_131 [ 1 ] & ( 1 << V_45 ) )
V_119 |= 1 ;
}
}
F_4 ( V_2 -> V_21 -> V_22 , L_18 ,
V_2 -> V_18 , V_117 , V_119 ) ;
* V_118 = V_119 ;
return 0 ;
}
static int F_44 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
unsigned char V_118 ;
int V_45 , V_5 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
for( V_45 = 0 ; V_45 < 5 ; V_45 ++ ) {
if ( V_25 -> V_30 == 0 )
V_118 = V_2 -> V_118 [ V_45 ] ;
else {
if ( V_2 -> V_20 -> V_31 )
V_5 = F_45 ( V_2 , V_45 ,
& V_118 ) ;
else
V_5 = F_43 ( V_2 , V_45 ,
& V_118 ) ;
if ( V_5 )
break;
}
V_42 -> V_32 . V_132 . V_133 [ V_45 ] = V_118 ;
}
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return 0 ;
}
static int F_46 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < 5 ; V_45 ++ )
V_42 -> V_32 . V_132 . V_133 [ V_45 ] = 0xff ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
int V_117 , unsigned char V_118 )
{
int V_45 , V_5 , V_10 ;
unsigned char V_134 = V_118 ;
unsigned char V_135 = V_2 -> V_118 [ V_117 ] ;
struct V_7 V_8 ;
for ( V_45 = 0 ; V_45 < 8 ; V_45 ++ ) {
if ( ( V_135 & 0x01 ) != ( V_134 & 0x01 ) ) {
V_10 = V_2 -> V_18 & 0x03 ;
if ( V_2 -> V_18 > 3 )
V_10 |= 1 << 22 ;
V_10 |= ( ( V_117 << 3 ) + V_45 ) << 2 ;
V_10 |= ( V_134 & 0x01 ) << 23 ;
F_2 ( & V_8 , V_9 ) ;
V_8 . V_10 [ 0 ] |= V_136 ;
V_8 . V_10 [ 1 ] = V_10 ;
V_8 . V_19 = 2 ;
F_4 ( V_2 -> V_21 -> V_22 ,
L_19 ,
V_2 -> V_18 , V_117 , V_45 , V_10 ) ;
V_5 = F_3 ( V_2 -> V_20 , & V_8 ) ;
if ( V_5 )
return V_5 ;
}
V_135 >>= 1 ;
V_134 >>= 1 ;
}
V_2 -> V_118 [ V_117 ] = V_118 ;
return 0 ;
}
static int F_48 ( struct V_24 * V_25 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_6 ( V_25 ) ;
int V_45 , V_44 = 0 ;
F_8 ( & V_2 -> V_20 -> V_43 ) ;
for ( V_45 = 0 ; V_45 < 5 ; V_45 ++ ) {
if ( V_42 -> V_32 . V_132 . V_133 [ V_45 ] != V_2 -> V_118 [ V_45 ] ) {
if ( V_2 -> V_20 -> V_31 )
F_49 ( V_2 , V_45 ,
V_42 -> V_32 . V_132 . V_133 [ V_45 ] ) ;
else
F_47 ( V_2 , V_45 ,
V_42 -> V_32 . V_132 . V_133 [ V_45 ] ) ;
V_44 = 1 ;
}
}
F_9 ( & V_2 -> V_20 -> V_43 ) ;
return V_44 ;
}
static void F_50 ( struct V_1 * V_2 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < 2 ; V_45 ++ ) {
if ( V_2 -> V_137 ) {
int V_75 ;
for ( V_75 = 0 ; V_75 < V_138 ; V_75 ++ ) {
V_2 -> V_54 [ V_75 ] [ V_45 ] = 1 ;
V_2 -> V_55 [ V_75 ] [ V_45 ] =
V_139 ;
}
V_2 -> V_118 [ 0 ] = ( V_140 |
V_141 ) ;
#ifdef F_51
V_2 -> V_14 [ V_45 ] = 1 ;
if ( V_2 -> V_20 -> V_31 )
V_2 -> V_15 [ V_45 ] =
V_142 ;
else {
V_2 -> V_15 [ V_45 ] =
V_143 ;
F_1 ( V_2 , 0 , V_45 ) ;
}
#endif
if ( V_2 -> V_20 -> V_31 )
F_11 ( V_2 , 0 , V_45 ) ;
}
if ( V_2 -> V_144 ) {
V_2 -> V_67 [ V_45 ] =
V_139 ;
V_2 -> V_145 = 1 ;
#ifdef F_51
if ( V_2 -> V_20 -> V_31 )
V_2 -> V_12 [ V_45 ] =
V_146 ;
else {
V_2 -> V_12 [ V_45 ] =
V_147 ;
F_1 ( V_2 , 1 , V_45 ) ;
}
#endif
if ( V_2 -> V_20 -> V_31 )
F_11 ( V_2 , 1 , V_45 ) ;
}
}
return;
}
int F_52 ( struct V_106 * V_20 )
{
struct V_1 * V_2 ;
int V_5 , V_45 ;
F_53 ( & V_20 -> V_43 ) ;
for ( V_45 = 0 ; V_45 < V_20 -> V_148 ; V_45 ++ ) {
struct V_149 V_119 ;
V_2 = V_20 -> V_2 [ V_45 ] ;
if ( V_2 -> V_137 ) {
V_119 = V_150 ;
V_119 . V_151 = L_20 ;
V_119 . V_30 = 0 ;
if ( V_20 -> V_31 )
V_119 . V_152 . V_153 = V_154 ;
else
V_119 . V_152 . V_153 = V_155 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_119 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_156 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_119 = V_157 ;
V_119 . V_151 = L_21 ;
V_119 . V_29 = V_138 ;
V_119 . V_30 = 0 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_119 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_158 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_159 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_160 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_2 -> V_144 ) {
V_119 = V_150 ;
V_119 . V_151 = L_22 ;
V_119 . V_30 = 1 ;
if ( V_20 -> V_31 )
V_119 . V_152 . V_153 = V_161 ;
else
V_119 . V_152 . V_153 = V_162 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_119 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_119 = V_157 ;
V_119 . V_151 = L_23 ;
V_119 . V_29 = 1 ;
V_119 . V_30 = 1 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_119 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_163 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_164 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_165 ,
V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_20 -> V_31 ) {
V_5 = F_56 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
}
if ( V_2 -> V_144 > 0 && V_2 -> V_137 > 0 ) {
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_166 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_167 , V_2 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_45 == 0 ) {
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_168 , V_20 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_54 ( V_2 -> V_21 ,
F_55 ( & V_169 , V_20 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
F_50 ( V_2 ) ;
}
return 0 ;
}
