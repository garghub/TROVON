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
F_18 ( L_1 ) ;
return V_17 ;
}
F_19 ( & V_46 -> V_47 ) ;
if ( F_8 ( V_13 -> V_21 ) != V_22 ) {
int V_48 , type = F_8 ( V_13 -> V_21 ) ;
if ( V_36 != NULL )
F_20 ( V_46 , V_36 -> V_48 ,
V_36 -> V_43 , V_36 -> V_49 ,
V_36 -> type ,
V_13 -> V_50 ) ;
V_48 =
F_20 ( V_46 , - 1 ,
F_21 ( V_45 ) ,
V_13 -> V_36 , type ,
V_13 -> V_50 ) ;
if ( V_48 < 0 ) {
F_22 ( & V_46 -> V_47 ) ;
return V_48 ;
}
V_36 = V_13 -> V_16 -> V_41 = & V_46 -> V_51 [ V_48 ] ;
V_36 -> V_13 = V_13 ;
F_23 ( V_46 , V_48 ,
F_24 ( V_45 ) ,
F_25 ( V_45 ) ) ;
if ( F_8 ( V_13 -> V_21 ) == V_33 ) {
V_46 -> V_52 [ V_13 -> V_50 ] . V_53 = 1 ;
F_1 ( V_46 -> V_2 ,
V_46 -> V_52 [ V_13 -> V_50 ] . V_4 , 1 ) ;
}
}
#ifndef F_13
else {
F_26 ( V_46 , V_13 -> V_50 ,
F_21 ( V_45 ) ) ;
V_36 = V_13 -> V_16 -> V_41 =
& V_46 -> V_54 [ V_13 -> V_50 ] ;
V_36 -> V_48 = V_13 -> V_50 ;
V_36 -> V_13 = V_13 ;
F_27 ( V_46 , V_13 -> V_50 ,
F_24 ( V_45 ) ,
F_25 ( V_45 ) ) ;
}
#endif
F_22 ( & V_46 -> V_47 ) ;
return 0 ;
}
static int F_28 ( struct V_12 * V_13 )
{
T_1 * V_46 = F_4 ( V_13 ) ;
T_2 * V_36 = ( T_2 * ) ( V_13 -> V_16 -> V_41 ) ;
F_19 ( & V_46 -> V_47 ) ;
if ( F_8 ( V_13 -> V_21 ) != V_22 ) {
if ( V_36 != NULL ) {
if ( F_8 ( V_13 -> V_21 ) == V_33 ) {
V_46 -> V_52 [ V_13 -> V_50 ] . V_53 = 0 ;
F_1 ( V_46 -> V_2 ,
V_46 -> V_52 [ V_13 -> V_50 ] . V_4 ,
0 ) ;
}
F_20 ( V_46 , V_36 -> V_48 ,
V_36 -> V_43 , V_36 -> V_49 ,
V_36 -> type ,
V_13 -> V_50 ) ;
}
}
#ifndef F_13
else {
if ( V_36 != NULL )
F_26 ( V_46 , V_36 -> V_48 , 0 ) ;
}
#endif
V_13 -> V_16 -> V_41 = NULL ;
F_22 ( & V_46 -> V_47 ) ;
return F_29 ( V_13 ) ;
}
static int F_30 ( struct V_12 * V_13 )
{
T_1 * V_46 = F_4 ( V_13 ) ;
struct V_15 * V_16 = V_13 -> V_16 ;
T_2 * V_36 = ( T_2 * ) V_13 -> V_16 -> V_41 ;
int V_48 = V_36 -> V_48 , V_55 , V_49 ;
if ( V_13 -> V_36 == V_37 )
V_49 = 1 ;
else
V_49 = 0 ;
V_55 = F_31 ( V_16 -> V_56 ) ;
F_19 ( & V_46 -> V_47 ) ;
if ( F_8 ( V_13 -> V_21 ) != V_22 ) {
F_32 ( V_46 , V_48 , 1 , V_49 , V_55 ,
V_16 -> V_57 == 1 ? 0 : 1 , 0 ) ;
F_33 ( V_46 , V_48 , 0 ) ;
if ( F_8 ( V_13 -> V_21 ) != V_26 )
F_34 ( V_46 , V_48 , V_16 -> V_58 , V_49 ) ;
}
#ifndef F_13
else {
F_35 ( V_46 , V_48 , 1 , V_55 , 0 , 0 ) ;
F_36 ( V_46 , V_48 , 0 ) ;
}
#endif
F_22 ( & V_46 -> V_47 ) ;
return 0 ;
}
static int F_37 ( struct V_12 * V_13 , int V_59 )
{
T_1 * V_46 = F_4 ( V_13 ) ;
T_2 * V_36 = ( T_2 * ) V_13 -> V_16 -> V_41 ;
int V_48 = V_36 -> V_48 ;
F_38 ( & V_46 -> V_47 ) ;
switch ( V_59 ) {
case V_60 :
V_36 -> V_61 = 1 ;
if ( F_8 ( V_13 -> V_21 ) != V_22 ) {
F_39 ( V_46 , V_48 ) ;
F_40 ( V_46 , V_48 ) ;
}
#ifndef F_13
else {
F_41 ( L_2 , V_48 ) ;
F_42 ( V_46 , V_48 ) ;
}
#endif
break;
case V_62 :
V_36 -> V_61 = 0 ;
if ( F_8 ( V_13 -> V_21 ) != V_22 )
F_43 ( V_46 , V_48 ) ;
#ifndef F_13
else {
F_41 ( L_3 , V_48 ) ;
F_44 ( V_46 , V_48 ) ;
}
#endif
break;
case V_63 :
if ( F_8 ( V_13 -> V_21 ) != V_22 )
F_45 ( V_46 , V_48 ) ;
#ifndef F_13
else
F_46 ( V_46 , V_48 ) ;
#endif
break;
case V_64 :
if ( F_8 ( V_13 -> V_21 ) != V_22 )
F_47 ( V_46 , V_48 ) ;
#ifndef F_13
else
F_48 ( V_46 , V_48 ) ;
#endif
break;
default:
F_49 ( & V_46 -> V_47 ) ;
return - V_65 ;
}
F_49 ( & V_46 -> V_47 ) ;
return 0 ;
}
static T_3 F_50 ( struct V_12 * V_13 )
{
T_1 * V_46 = F_4 ( V_13 ) ;
T_2 * V_36 = ( T_2 * ) V_13 -> V_16 -> V_41 ;
int V_48 = V_36 -> V_48 ;
T_3 V_66 = 0 ;
F_38 ( & V_46 -> V_47 ) ;
if ( F_8 ( V_13 -> V_21 ) != V_22 )
V_66 = F_51 ( V_46 , V_48 ) ;
#ifndef F_13
else
V_66 = F_52 ( V_46 , V_48 ) ;
#endif
F_49 ( & V_46 -> V_47 ) ;
return ( F_53 ( V_13 -> V_16 , V_66 ) ) ;
}
static int F_54 ( struct V_3 * V_67 , struct V_68 * V_69 )
{
V_69 -> type = V_70 ;
V_69 -> V_71 = 1 ;
return 0 ;
}
static int F_55 ( struct V_3 * V_67 , struct V_72 * V_73 )
{
V_73 -> V_74 . V_75 . V_76 [ 0 ] = 0xff ;
V_73 -> V_74 . V_75 . V_76 [ 1 ] = 0xff ;
V_73 -> V_74 . V_75 . V_76 [ 2 ] = 0xff ;
V_73 -> V_74 . V_75 . V_76 [ 3 ] = V_77 ;
return 0 ;
}
static int F_56 ( struct V_3 * V_67 , struct V_72 * V_73 )
{
T_1 * V_14 = F_57 ( V_67 ) ;
V_73 -> V_74 . V_75 . V_76 [ 0 ] = 0x00 ;
V_73 -> V_74 . V_75 . V_76 [ 1 ] = V_78 | V_79 ;
V_73 -> V_74 . V_75 . V_76 [ 2 ] = 0x00 ;
switch ( V_14 -> V_28 ) {
case 32000 : V_73 -> V_74 . V_75 . V_76 [ 3 ] = V_80 ; break;
case 44100 : V_73 -> V_74 . V_75 . V_76 [ 3 ] = V_81 ; break;
case 48000 : V_73 -> V_74 . V_75 . V_76 [ 3 ] = V_82 ; break;
}
return 0 ;
}
static int F_58 ( struct V_3 * V_67 , struct V_72 * V_73 )
{
T_1 * V_14 = F_57 ( V_67 ) ;
int V_28 = 48000 ;
switch ( V_73 -> V_74 . V_75 . V_76 [ 3 ] & V_77 ) {
case V_80 : V_28 = 32000 ; break;
case V_81 : V_28 = 44100 ; break;
case V_82 : V_28 = 48000 ; break;
}
if ( V_28 == V_14 -> V_28 )
return 0 ;
V_14 -> V_28 = V_28 ;
F_59 ( V_14 , V_14 -> V_28 , 1 ) ;
return 1 ;
}
static int F_60 ( struct V_3 * V_67 ,
struct V_68 * V_69 )
{
T_1 * V_14 = F_57 ( V_67 ) ;
V_69 -> type = V_83 ;
V_69 -> V_71 = ( F_11 ( V_14 ) ? 4 : 2 ) ;
V_69 -> V_74 . integer . V_84 = - 128 ;
V_69 -> V_74 . integer . V_85 = 32 ;
return 0 ;
}
static int F_61 ( struct V_3 * V_67 ,
struct V_72 * V_73 )
{
int V_86 ;
T_1 * V_14 = F_57 ( V_67 ) ;
int V_87 = V_67 -> V_11 . V_88 ;
struct V_52 * V_89 = & V_14 -> V_52 [ V_87 ] ;
int V_90 = ( F_11 ( V_14 ) ? 4 : 2 ) ;
for ( V_86 = 0 ; V_86 < V_90 ; V_86 ++ )
V_73 -> V_74 . integer . V_74 [ V_86 ] = V_89 -> V_91 [ V_86 ] ;
return 0 ;
}
static int F_62 ( struct V_3 * V_67 ,
struct V_72 * V_73 )
{
int V_86 ;
int V_92 = 0 ;
int V_93 ;
unsigned char V_91 ;
T_1 * V_14 = F_57 ( V_67 ) ;
int V_87 = V_67 -> V_11 . V_88 ;
struct V_52 * V_89 = & V_14 -> V_52 [ V_87 ] ;
int V_90 = ( F_11 ( V_14 ) ? 4 : 2 ) ;
for ( V_86 = 0 ; V_86 < V_90 ; V_86 ++ ) {
if ( V_89 -> V_91 [ V_86 ] != V_73 -> V_74 . integer . V_74 [ V_86 ] ) {
V_89 -> V_91 [ V_86 ] = V_73 -> V_74 . integer . V_74 [ V_86 ] ;
if ( V_89 -> V_53 ) {
switch ( V_14 -> V_51 [ V_89 -> V_48 ] . V_43 ) {
case 1 :
V_93 = V_89 -> V_93 [ 0 ] ;
break;
case 2 :
default:
V_93 = V_89 -> V_93 [ ( V_86 < 2 ) ? V_86 : ( V_86 - 2 ) ] ;
break;
case 4 :
V_93 = V_89 -> V_93 [ V_86 ] ;
break;
}
V_91 = V_89 -> V_91 [ V_86 ] ;
F_63 ( V_14 ,
V_14 -> V_94 [ V_86 ] , V_93 , V_91 ) ;
}
V_92 = 1 ;
}
}
return V_92 ;
}
static int F_64 ( T_1 * V_46 , int V_95 , int V_96 )
{
struct V_97 * V_21 ;
struct V_3 * V_4 ;
int V_86 ;
int V_17 , V_98 ;
if ( ! V_46 || V_95 < 0 || V_95 >= V_99 )
return - V_100 ;
if ( V_95 == V_33 )
V_98 = V_96 ;
else
V_98 = 0 ;
V_17 = F_65 ( V_46 -> V_2 , V_101 [ V_95 ] , V_95 , V_96 ,
V_98 , & V_21 ) ;
if ( V_17 < 0 )
return V_17 ;
snprintf ( V_21 -> V_102 , sizeof( V_21 -> V_102 ) ,
L_4 , V_103 , V_104 [ V_95 ] ) ;
V_46 -> V_21 [ V_95 ] = V_21 ;
F_8 ( V_21 ) = V_95 ;
V_21 -> V_41 = V_46 ;
F_66 ( V_21 , V_37 ,
& V_105 ) ;
if ( V_95 == V_33 )
F_66 ( V_21 , V_106 ,
& V_105 ) ;
F_67 ( V_21 , V_107 ,
F_68 ( V_46 -> V_108 ) ,
0x10000 , 0x10000 ) ;
switch ( F_8 ( V_21 ) ) {
case V_33 :
V_17 = F_69 ( V_21 , V_37 ,
V_109 ,
F_11 ( V_46 ) ? 4 : 2 ,
0 , NULL ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_69 ( V_21 , V_106 ,
V_109 , 2 , 0 , NULL ) ;
if ( V_17 < 0 )
return V_17 ;
break;
#ifdef F_10
case V_23 :
V_17 = F_69 ( V_21 , V_37 ,
V_109 , 1 , 0 , NULL ) ;
if ( V_17 < 0 )
return V_17 ;
break;
#endif
}
if ( F_8 ( V_21 ) == V_26 ) {
for ( V_86 = 0 ; V_86 < F_70 ( V_110 ) ; V_86 ++ ) {
V_4 = F_71 ( & V_110 [ V_86 ] , V_46 ) ;
if ( ! V_4 )
return - V_111 ;
if ( ( V_17 = F_72 ( V_46 -> V_2 , V_4 ) ) < 0 )
return V_17 ;
}
}
if ( F_8 ( V_21 ) == V_33 ) {
for ( V_86 = 0 ; V_86 < V_112 ; V_86 ++ ) {
V_46 -> V_52 [ V_86 ] . V_53 = 0 ;
V_46 -> V_52 [ V_86 ] . V_48 = - 1 ;
V_4 = F_71 ( & V_113 , V_46 ) ;
if ( ! V_4 )
return - V_111 ;
V_46 -> V_52 [ V_86 ] . V_4 = V_4 ;
V_4 -> V_11 . V_114 = 0 ;
V_4 -> V_11 . V_88 = V_86 ;
V_17 = F_72 ( V_46 -> V_2 , V_4 ) ;
if ( V_17 < 0 )
return V_17 ;
}
}
return 0 ;
}
