static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
if ( V_5 )
V_4 -> V_6 [ 0 ] . V_7 &= ~ V_8 ;
else
V_4 -> V_6 [ 0 ] . V_7 |= V_8 ;
F_2 ( V_2 , V_9 |
V_10 , & ( V_4 -> V_11 ) ) ;
}
static int F_3 ( struct V_12 * V_13 )
{
T_1 * V_14 = F_4 ( V_13 ) ;
struct V_15 * V_16 = V_13 -> V_16 ;
int V_17 ;
if ( ( V_17 =
F_5 ( V_16 ,
V_18 ) ) < 0 )
return V_17 ;
if ( ( V_17 =
F_6 ( V_16 , 0 ,
V_19 ) ) < 0 )
return V_17 ;
F_7 ( V_16 , 0 ,
V_20 , 64 ) ;
if ( F_8 ( V_13 -> V_21 ) != V_22 ) {
#ifndef F_9
if ( F_8 ( V_13 -> V_21 ) == V_23 ) {
V_16 -> V_24 = V_25 ;
}
#endif
if ( F_8 ( V_13 -> V_21 ) == V_26 ) {
V_16 -> V_24 = V_27 ;
switch ( V_14 -> V_28 ) {
case 32000 :
V_16 -> V_24 . V_29 = V_30 ;
break;
case 44100 :
V_16 -> V_24 . V_29 = V_31 ;
break;
case 48000 :
V_16 -> V_24 . V_29 = V_32 ;
break;
}
}
if ( F_8 ( V_13 -> V_21 ) == V_33
|| F_8 ( V_13 -> V_21 ) == V_34 )
V_16 -> V_24 = V_35 ;
#ifdef F_10
if ( V_13 -> V_36 == V_37 &&
F_11 ( V_14 ) &&
F_8 ( V_13 -> V_21 ) == V_33 ) {
V_16 -> V_24 . V_38 = 4 ;
F_12 ( V_16 , 0 ,
V_39 ,
& V_40 ) ;
}
#endif
V_13 -> V_16 -> V_41 = NULL ;
}
#ifndef F_13
else {
V_16 -> V_24 = V_42 ;
V_13 -> V_16 -> V_41 = NULL ;
}
#endif
return 0 ;
}
static int F_14 ( struct V_12 * V_13 )
{
T_2 * V_36 = ( T_2 * ) V_13 -> V_16 -> V_41 ;
if ( V_36 != NULL ) {
V_36 -> V_13 = NULL ;
V_36 -> V_43 = 0 ;
}
V_13 -> V_16 -> V_41 = NULL ;
return 0 ;
}
static int
F_15 ( struct V_12 * V_13 ,
struct V_44 * V_45 )
{
T_1 * V_46 = F_4 ( V_13 ) ;
T_2 * V_36 = ( T_2 * ) ( V_13 -> V_16 -> V_41 ) ;
int V_17 ;
V_17 =
F_16 ( V_13 , F_17 ( V_45 ) ) ;
if ( V_17 < 0 ) {
F_18 ( V_46 -> V_2 -> V_47 , L_1 ) ;
return V_17 ;
}
F_19 ( & V_46 -> V_48 ) ;
if ( F_8 ( V_13 -> V_21 ) != V_22 ) {
int V_49 , type = F_8 ( V_13 -> V_21 ) ;
if ( V_36 != NULL )
F_20 ( V_46 , V_36 -> V_49 ,
V_36 -> V_43 , V_36 -> V_50 ,
V_36 -> type ,
V_13 -> V_51 ) ;
V_49 =
F_20 ( V_46 , - 1 ,
F_21 ( V_45 ) ,
V_13 -> V_36 , type ,
V_13 -> V_51 ) ;
if ( V_49 < 0 ) {
F_22 ( & V_46 -> V_48 ) ;
return V_49 ;
}
V_36 = V_13 -> V_16 -> V_41 = & V_46 -> V_52 [ V_49 ] ;
V_36 -> V_13 = V_13 ;
F_23 ( V_46 , V_49 ,
F_24 ( V_45 ) ,
F_25 ( V_45 ) ) ;
if ( F_8 ( V_13 -> V_21 ) == V_33 ) {
V_46 -> V_53 [ V_13 -> V_51 ] . V_54 = 1 ;
F_1 ( V_46 -> V_2 ,
V_46 -> V_53 [ V_13 -> V_51 ] . V_4 , 1 ) ;
}
}
#ifndef F_13
else {
F_26 ( V_46 , V_13 -> V_51 ,
F_21 ( V_45 ) ) ;
V_36 = V_13 -> V_16 -> V_41 =
& V_46 -> V_55 [ V_13 -> V_51 ] ;
V_36 -> V_49 = V_13 -> V_51 ;
V_36 -> V_13 = V_13 ;
F_27 ( V_46 , V_13 -> V_51 ,
F_24 ( V_45 ) ,
F_25 ( V_45 ) ) ;
}
#endif
F_22 ( & V_46 -> V_48 ) ;
return 0 ;
}
static int F_28 ( struct V_12 * V_13 )
{
T_1 * V_46 = F_4 ( V_13 ) ;
T_2 * V_36 = ( T_2 * ) ( V_13 -> V_16 -> V_41 ) ;
F_19 ( & V_46 -> V_48 ) ;
if ( F_8 ( V_13 -> V_21 ) != V_22 ) {
if ( V_36 != NULL ) {
if ( F_8 ( V_13 -> V_21 ) == V_33 ) {
V_46 -> V_53 [ V_13 -> V_51 ] . V_54 = 0 ;
F_1 ( V_46 -> V_2 ,
V_46 -> V_53 [ V_13 -> V_51 ] . V_4 ,
0 ) ;
}
F_20 ( V_46 , V_36 -> V_49 ,
V_36 -> V_43 , V_36 -> V_50 ,
V_36 -> type ,
V_13 -> V_51 ) ;
}
}
#ifndef F_13
else {
if ( V_36 != NULL )
F_26 ( V_46 , V_36 -> V_49 , 0 ) ;
}
#endif
V_13 -> V_16 -> V_41 = NULL ;
F_22 ( & V_46 -> V_48 ) ;
return F_29 ( V_13 ) ;
}
static int F_30 ( struct V_12 * V_13 )
{
T_1 * V_46 = F_4 ( V_13 ) ;
struct V_15 * V_16 = V_13 -> V_16 ;
T_2 * V_36 = ( T_2 * ) V_13 -> V_16 -> V_41 ;
int V_49 = V_36 -> V_49 , V_56 , V_50 ;
if ( V_13 -> V_36 == V_37 )
V_50 = 1 ;
else
V_50 = 0 ;
V_56 = F_31 ( V_16 -> V_57 , V_46 ) ;
F_19 ( & V_46 -> V_48 ) ;
if ( F_8 ( V_13 -> V_21 ) != V_22 ) {
F_32 ( V_46 , V_49 , 1 , V_50 , V_56 ,
V_16 -> V_58 == 1 ? 0 : 1 , 0 ) ;
F_33 ( V_46 , V_49 , 0 ) ;
if ( F_8 ( V_13 -> V_21 ) != V_26 )
F_34 ( V_46 , V_49 , V_16 -> V_59 , V_50 ) ;
}
#ifndef F_13
else {
F_35 ( V_46 , V_49 , 1 , V_56 , 0 , 0 ) ;
F_36 ( V_46 , V_49 , 0 ) ;
}
#endif
F_22 ( & V_46 -> V_48 ) ;
return 0 ;
}
static int F_37 ( struct V_12 * V_13 , int V_60 )
{
T_1 * V_46 = F_4 ( V_13 ) ;
T_2 * V_36 = ( T_2 * ) V_13 -> V_16 -> V_41 ;
int V_49 = V_36 -> V_49 ;
F_38 ( & V_46 -> V_48 ) ;
switch ( V_60 ) {
case V_61 :
V_36 -> V_62 = 1 ;
if ( F_8 ( V_13 -> V_21 ) != V_22 ) {
F_39 ( V_46 , V_49 ) ;
F_40 ( V_46 , V_49 ) ;
}
#ifndef F_13
else {
F_41 ( V_46 -> V_2 -> V_47 , L_2 , V_49 ) ;
F_42 ( V_46 , V_49 ) ;
}
#endif
break;
case V_63 :
V_36 -> V_62 = 0 ;
if ( F_8 ( V_13 -> V_21 ) != V_22 )
F_43 ( V_46 , V_49 ) ;
#ifndef F_13
else {
F_41 ( V_46 -> V_2 -> V_47 , L_3 , V_49 ) ;
F_44 ( V_46 , V_49 ) ;
}
#endif
break;
case V_64 :
if ( F_8 ( V_13 -> V_21 ) != V_22 )
F_45 ( V_46 , V_49 ) ;
#ifndef F_13
else
F_46 ( V_46 , V_49 ) ;
#endif
break;
case V_65 :
if ( F_8 ( V_13 -> V_21 ) != V_22 )
F_47 ( V_46 , V_49 ) ;
#ifndef F_13
else
F_48 ( V_46 , V_49 ) ;
#endif
break;
default:
F_49 ( & V_46 -> V_48 ) ;
return - V_66 ;
}
F_49 ( & V_46 -> V_48 ) ;
return 0 ;
}
static T_3 F_50 ( struct V_12 * V_13 )
{
T_1 * V_46 = F_4 ( V_13 ) ;
T_2 * V_36 = ( T_2 * ) V_13 -> V_16 -> V_41 ;
int V_49 = V_36 -> V_49 ;
T_3 V_67 = 0 ;
F_38 ( & V_46 -> V_48 ) ;
if ( F_8 ( V_13 -> V_21 ) != V_22 )
V_67 = F_51 ( V_46 , V_49 ) ;
#ifndef F_13
else
V_67 = F_52 ( V_46 , V_49 ) ;
#endif
F_49 ( & V_46 -> V_48 ) ;
return ( F_53 ( V_13 -> V_16 , V_67 ) ) ;
}
static int F_54 ( struct V_3 * V_68 , struct V_69 * V_70 )
{
V_70 -> type = V_71 ;
V_70 -> V_72 = 1 ;
return 0 ;
}
static int F_55 ( struct V_3 * V_68 , struct V_73 * V_74 )
{
V_74 -> V_75 . V_76 . V_77 [ 0 ] = 0xff ;
V_74 -> V_75 . V_76 . V_77 [ 1 ] = 0xff ;
V_74 -> V_75 . V_76 . V_77 [ 2 ] = 0xff ;
V_74 -> V_75 . V_76 . V_77 [ 3 ] = V_78 ;
return 0 ;
}
static int F_56 ( struct V_3 * V_68 , struct V_73 * V_74 )
{
T_1 * V_14 = F_57 ( V_68 ) ;
V_74 -> V_75 . V_76 . V_77 [ 0 ] = 0x00 ;
V_74 -> V_75 . V_76 . V_77 [ 1 ] = V_79 | V_80 ;
V_74 -> V_75 . V_76 . V_77 [ 2 ] = 0x00 ;
switch ( V_14 -> V_28 ) {
case 32000 : V_74 -> V_75 . V_76 . V_77 [ 3 ] = V_81 ; break;
case 44100 : V_74 -> V_75 . V_76 . V_77 [ 3 ] = V_82 ; break;
case 48000 : V_74 -> V_75 . V_76 . V_77 [ 3 ] = V_83 ; break;
}
return 0 ;
}
static int F_58 ( struct V_3 * V_68 , struct V_73 * V_74 )
{
T_1 * V_14 = F_57 ( V_68 ) ;
int V_28 = 48000 ;
switch ( V_74 -> V_75 . V_76 . V_77 [ 3 ] & V_78 ) {
case V_81 : V_28 = 32000 ; break;
case V_82 : V_28 = 44100 ; break;
case V_83 : V_28 = 48000 ; break;
}
if ( V_28 == V_14 -> V_28 )
return 0 ;
V_14 -> V_28 = V_28 ;
F_59 ( V_14 , V_14 -> V_28 , 1 ) ;
return 1 ;
}
static int F_60 ( struct V_3 * V_68 ,
struct V_69 * V_70 )
{
T_1 * V_14 = F_57 ( V_68 ) ;
V_70 -> type = V_84 ;
V_70 -> V_72 = ( F_11 ( V_14 ) ? 4 : 2 ) ;
V_70 -> V_75 . integer . V_85 = - 128 ;
V_70 -> V_75 . integer . V_86 = 32 ;
return 0 ;
}
static int F_61 ( struct V_3 * V_68 ,
struct V_73 * V_74 )
{
int V_87 ;
T_1 * V_14 = F_57 ( V_68 ) ;
int V_88 = V_68 -> V_11 . V_89 ;
struct V_53 * V_90 = & V_14 -> V_53 [ V_88 ] ;
int V_91 = ( F_11 ( V_14 ) ? 4 : 2 ) ;
for ( V_87 = 0 ; V_87 < V_91 ; V_87 ++ )
V_74 -> V_75 . integer . V_75 [ V_87 ] = V_90 -> V_92 [ V_87 ] ;
return 0 ;
}
static int F_62 ( struct V_3 * V_68 ,
struct V_73 * V_74 )
{
int V_87 ;
int V_93 = 0 ;
int V_94 ;
unsigned char V_92 ;
T_1 * V_14 = F_57 ( V_68 ) ;
int V_88 = V_68 -> V_11 . V_89 ;
struct V_53 * V_90 = & V_14 -> V_53 [ V_88 ] ;
int V_91 = ( F_11 ( V_14 ) ? 4 : 2 ) ;
for ( V_87 = 0 ; V_87 < V_91 ; V_87 ++ ) {
if ( V_90 -> V_92 [ V_87 ] != V_74 -> V_75 . integer . V_75 [ V_87 ] ) {
V_90 -> V_92 [ V_87 ] = V_74 -> V_75 . integer . V_75 [ V_87 ] ;
if ( V_90 -> V_54 ) {
switch ( V_14 -> V_52 [ V_90 -> V_49 ] . V_43 ) {
case 1 :
V_94 = V_90 -> V_94 [ 0 ] ;
break;
case 2 :
default:
V_94 = V_90 -> V_94 [ ( V_87 < 2 ) ? V_87 : ( V_87 - 2 ) ] ;
break;
case 4 :
V_94 = V_90 -> V_94 [ V_87 ] ;
break;
}
V_92 = V_90 -> V_92 [ V_87 ] ;
F_63 ( V_14 ,
V_14 -> V_95 [ V_87 ] , V_94 , V_92 ) ;
}
V_93 = 1 ;
}
}
return V_93 ;
}
static int F_64 ( T_1 * V_46 , int V_96 , int V_97 )
{
struct V_98 * V_21 ;
struct V_3 * V_4 ;
int V_87 ;
int V_17 , V_99 ;
if ( ! V_46 || V_96 < 0 || V_96 >= V_100 )
return - V_101 ;
if ( V_96 == V_33 )
V_99 = V_97 ;
else
V_99 = 0 ;
V_17 = F_65 ( V_46 -> V_2 , V_102 [ V_96 ] , V_96 , V_97 ,
V_99 , & V_21 ) ;
if ( V_17 < 0 )
return V_17 ;
snprintf ( V_21 -> V_103 , sizeof( V_21 -> V_103 ) ,
L_4 , V_104 , V_105 [ V_96 ] ) ;
V_46 -> V_21 [ V_96 ] = V_21 ;
F_8 ( V_21 ) = V_96 ;
V_21 -> V_41 = V_46 ;
F_66 ( V_21 , V_37 ,
& V_106 ) ;
if ( V_96 == V_33 )
F_66 ( V_21 , V_107 ,
& V_106 ) ;
F_67 ( V_21 , V_108 ,
F_68 ( V_46 -> V_109 ) ,
0x10000 , 0x10000 ) ;
switch ( F_8 ( V_21 ) ) {
case V_33 :
V_17 = F_69 ( V_21 , V_37 ,
V_110 ,
F_11 ( V_46 ) ? 4 : 2 ,
0 , NULL ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_69 ( V_21 , V_107 ,
V_110 , 2 , 0 , NULL ) ;
if ( V_17 < 0 )
return V_17 ;
break;
#ifdef F_10
case V_23 :
V_17 = F_69 ( V_21 , V_37 ,
V_110 , 1 , 0 , NULL ) ;
if ( V_17 < 0 )
return V_17 ;
break;
#endif
}
if ( F_8 ( V_21 ) == V_26 ) {
for ( V_87 = 0 ; V_87 < F_70 ( V_111 ) ; V_87 ++ ) {
V_4 = F_71 ( & V_111 [ V_87 ] , V_46 ) ;
if ( ! V_4 )
return - V_112 ;
if ( ( V_17 = F_72 ( V_46 -> V_2 , V_4 ) ) < 0 )
return V_17 ;
}
}
if ( F_8 ( V_21 ) == V_33 ) {
for ( V_87 = 0 ; V_87 < V_113 ; V_87 ++ ) {
V_46 -> V_53 [ V_87 ] . V_54 = 0 ;
V_46 -> V_53 [ V_87 ] . V_49 = - 1 ;
V_4 = F_71 ( & V_114 , V_46 ) ;
if ( ! V_4 )
return - V_112 ;
V_46 -> V_53 [ V_87 ] . V_4 = V_4 ;
V_4 -> V_11 . V_115 = 0 ;
V_4 -> V_11 . V_89 = V_87 ;
V_17 = F_72 ( V_46 -> V_2 , V_4 ) ;
if ( V_17 < 0 )
return V_17 ;
}
}
return 0 ;
}
