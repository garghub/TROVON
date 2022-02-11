static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_1 * V_5 , T_2 V_6 , int V_7 )
{
int V_8 ;
T_1 V_9 ;
T_1 * V_10 ;
unsigned int V_11 = ( V_7 == V_12 ) ?
F_2 ( V_2 , 0 ) : F_3 ( V_2 , 0 ) ;
T_1 V_13 = ( V_7 == V_12 ) ? V_14 : V_15 ;
V_10 = F_4 ( V_6 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
if ( V_7 == V_18 )
memcpy ( V_10 , V_5 , V_6 ) ;
V_8 = F_5 ( V_2 , V_11 , V_3 ,
V_13 | V_19 , V_4 , 0x0 ,
V_10 , V_6 , 2000 ) ;
if ( V_3 == V_20 ) {
V_9 = V_10 [ 0 ] ;
if ( F_5 ( V_2 , F_2 ( V_2 , 0 ) ,
V_20 , V_14 | V_19 ,
0x01 , 0x0 , V_10 , 1 , 2000 ) < 1 || V_10 [ 0 ] != 0x08 ) {
V_8 = 0 ;
goto V_21;
}
V_10 [ 0 ] = V_9 ;
}
if ( V_7 == V_12 )
memcpy ( V_5 , V_10 , V_6 ) ;
V_21:
F_6 ( V_10 ) ;
return V_8 ;
}
static int F_7 ( struct V_22 * V_2 , T_2 V_23 ,
T_1 * V_10 , T_2 V_6 )
{
int V_8 = 0 ;
T_1 V_3 ;
T_2 V_4 ;
if ( ! V_2 ) {
F_8 ( L_1 ) ;
return - V_24 ;
}
if ( F_9 ( & V_2 -> V_25 ) < 0 )
return - V_26 ;
switch ( V_23 >> 1 ) {
case V_27 :
V_3 = 0xb6 ;
V_4 = 0x00 ;
break;
case V_28 :
V_3 = 0xb6 ;
V_4 = 0x01 ;
break;
case V_29 :
V_3 = 0xb1 ;
V_4 = 0xa6 ;
break;
case V_30 :
V_3 = 0xb8 ;
V_4 = 0x80 ;
break;
default:
V_3 = 0xb1 ;
V_4 = V_23 ;
}
V_8 = F_1 ( V_2 -> V_31 , V_3 ,
V_4 , V_10 , V_6 ,
V_23 & 0x01 ? V_12 : V_18 ) ;
F_10 ( & V_2 -> V_25 ) ;
return V_8 ;
}
static int F_11 ( struct V_32 * V_33 , struct V_34 V_35 [] ,
int V_36 )
{
struct V_22 * V_37 = F_12 ( V_33 ) ;
int V_38 = 0 , V_9 = 0 ;
if ( ! V_37 )
return - V_39 ;
if ( F_9 ( & V_37 -> V_40 ) < 0 )
return - V_26 ;
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ ) {
if ( ( V_9 = F_7 ( V_37 ,
( V_35 [ V_38 ] . V_23 << 1 ) | ( V_35 [ V_38 ] . V_7 & V_41 ? 0x01 : 0 ) ,
V_35 [ V_38 ] . V_10 ,
V_35 [ V_38 ] . V_6
) ) != V_35 [ V_38 ] . V_6 ) {
break;
}
if ( V_42 & 0x10 )
F_8 ( L_2 , V_9 , V_35 [ V_38 ] . V_6 ) ;
}
F_10 ( & V_37 -> V_40 ) ;
return V_36 ;
}
static T_3 F_13 ( struct V_32 * V_43 )
{
return V_44 ;
}
static int F_14 ( struct V_45 * V_46 ,
enum V_47 V_48 )
{
static T_1 V_49 [ 1 ] = { 0x00 } ;
static T_1 V_50 [ 1 ] = { 0x01 } ;
struct V_34 V_35 [] = {
{ . V_23 = V_27 , . V_7 = 0 , . V_10 = V_49 , . V_6 = 1 } ,
} ;
struct V_51 * V_52 =
(struct V_51 * ) ( V_46 -> V_53 -> V_54 ) ;
if ( V_48 == V_55 ) {
V_35 [ 0 ] . V_23 = V_28 ;
V_35 [ 0 ] . V_10 = V_50 ;
}
F_15 ( & V_52 -> V_2 -> V_56 , V_35 , 1 ) ;
return 0 ;
}
static int F_16 ( struct V_45 * V_46 , T_3 V_57 ,
T_3 V_58 )
{
F_17 ( V_46 , 0x13 , 0x98 ) ;
F_17 ( V_46 , 0x14 , 0x95 ) ;
F_17 ( V_46 , V_59 , ( V_58 >> 16 ) & 0xff ) ;
F_17 ( V_46 , V_60 , ( V_58 >> 8 ) & 0xff ) ;
F_17 ( V_46 , V_61 , ( V_58 ) & 0xf0 ) ;
return 0 ;
}
static int F_18 ( struct V_51 * V_37 )
{
V_37 -> V_62 [ 0 ] . V_46 = F_19 ( V_63 , & V_64 ,
& V_37 -> V_2 -> V_56 ) ;
if ( ( V_37 -> V_62 [ 0 ] . V_46 ) != NULL ) {
V_37 -> V_62 [ 0 ] . V_46 -> V_65 . V_66 = F_14 ;
return 0 ;
}
F_8 ( L_3 ) ;
return - V_67 ;
}
static int F_20 ( struct V_51 * V_33 )
{
F_19 (
V_68 , V_33 -> V_62 [ 0 ] . V_46 , 0xc0 >> 1 ,
& V_33 -> V_2 -> V_56 , V_69
) ;
return 0 ;
}
static int F_21 ( struct V_22 * V_37 , int V_70 )
{
T_1 V_71 = V_70 ? 0x01 : 0x00 ;
if ( V_42 )
F_8 ( L_4 , V_70 ? L_5 : L_6 ) ;
return F_1 ( V_37 -> V_31 , 0xb7 , V_71 ,
& V_71 , 1 , V_18 ) ;
}
static int F_22 ( struct V_51 * V_33 , int V_70 )
{
static T_1 V_72 [ 2 ] = { 0xff , 0x03 } ;
static T_1 V_73 [ 2 ] = { 0xff , 0x00 } ;
struct V_34 V_74 [] = {
{ . V_23 = V_29 , . V_10 = V_70 ? V_72 : V_73 , . V_6 = 2 } ,
} ;
if ( V_42 )
F_8 ( L_7 , V_70 ? L_5 : L_6 ) ;
F_15 ( & V_33 -> V_2 -> V_56 , V_74 , 1 ) ;
return 0 ;
}
static int F_23 ( struct V_51 * V_33 , int V_75 , T_2 V_76 ,
int V_70 )
{
T_1 V_77 [ 3 ] ;
struct V_34 V_35 [] = {
{ . V_23 = V_29 , . V_10 = V_77 , . V_6 = 3 } ,
} ;
if ( V_42 )
F_8 ( L_8 , V_75 , V_76 ,
V_70 ? L_5 : L_6 ) ;
V_77 [ 0 ] = ( 2 * V_75 ) + 4 ;
V_77 [ 1 ] = V_70 ? ( V_76 & 0xff ) : ( 0x00 ) ;
V_77 [ 2 ] = V_70 ? ( ( V_76 >> 8 ) & 0xff ) : ( 0x00 ) ;
F_15 ( & V_33 -> V_2 -> V_56 , V_35 , 1 ) ;
return 0 ;
}
static int F_24 ( struct V_51 * V_33 , int V_70 )
{
int V_78 = 0x04 ;
T_1 V_77 [ 3 ] ;
struct V_34 V_35 [] = {
{ . V_23 = V_29 , . V_10 = V_77 , . V_6 = 3 } ,
} ;
if ( V_42 )
F_8 ( L_9 , V_70 ? L_10 : L_11 ) ;
for (; V_78 < 0x7e ; V_78 += 2 ) {
V_77 [ 0 ] = V_78 ;
V_77 [ 1 ] = 0 ;
V_77 [ 2 ] = 0x80 ;
F_15 ( & V_33 -> V_2 -> V_56 , V_35 , 1 ) ;
}
return 0 ;
}
static int F_25 ( struct V_22 * V_2 , T_3 * V_79 , int * V_80 )
{
struct V_81 * V_82 = V_2 -> V_54 ;
T_1 V_83 [ 32 ] ;
const T_2 V_84 = 0x10ed ;
const T_2 V_85 = 0x11ec ;
struct V_34 V_86 [] = {
{ . V_23 = V_30 , . V_10 = V_83 , . V_7 = V_41 , . V_6 = 32 } ,
} ;
int V_38 = 0 ;
T_3 V_87 = 0 ;
if ( F_15 ( & V_2 -> V_56 , V_86 , 1 ) == 1 ) {
for ( V_38 = 0 ; V_38 < 32 ; V_38 ++ ) {
if ( V_83 [ V_38 ] )
V_87 |= 1 ;
if ( V_38 < 31 )
V_87 = V_87 << 1 ;
}
if ( V_87 & 0x8000 )
V_87 = ( V_87 << 1 ) | ( V_87 >> 15 & 0x01 ) ;
if ( V_87 == 0xffff && V_82 -> V_88 != 0 ) {
* V_80 = V_89 ;
* V_79 = V_82 -> V_88 ;
return 0 ;
}
for (; V_87 != 0 ; ) {
if ( V_87 >> 16 == V_85 ) {
break;
} else if ( V_87 >> 16 == V_84 ) {
V_87 =
( V_87 & 0xfffeffff ) | ( V_84 << 16 ) ;
break;
} else
V_87 >>= 1 ;
}
if ( V_87 == 0 )
return 0 ;
V_87 = ( V_87 & 0xffff ) | 0x0100 ;
for ( V_38 = 0 ; V_38 < F_26 ( V_90 ) ; V_38 ++ ) {
if ( F_27 ( & V_90 [ V_38 ] ) == ( V_87 & 0xffff ) ) {
* V_80 = V_91 ;
* V_79 = V_90 [ V_38 ] . V_92 ;
V_82 -> V_88 =
V_90 [ V_38 ] . V_92 ;
break;
}
V_82 -> V_88 = 0 ;
}
} else
* V_80 = V_93 ;
return 0 ;
}
static int F_28 ( struct V_22 * V_37 , T_1 V_94 [ 6 ] )
{
T_1 V_95 [] = { V_96 } ;
F_1 ( V_37 -> V_31 , 0xb1 , 0xa0 , V_95 , 1 , V_18 ) ;
F_1 ( V_37 -> V_31 , 0xb1 , 0xa1 , V_94 , 6 , V_12 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
const char * V_97 )
{
const struct V_98 * V_99 = NULL ;
T_1 * V_100 , * V_101 ;
int V_8 = 0 , V_38 , V_102 = 40 ;
T_1 V_103 ;
F_8 ( L_12 , V_97 ) ;
if ( ( V_8 = F_30 ( & V_99 , V_97 , & V_2 -> V_2 ) ) != 0 ) {
F_31 ( L_13 ,
V_97 ) ;
return V_8 ;
} else {
V_101 = F_4 ( V_99 -> V_104 , V_16 ) ;
F_1 ( V_2 , 0xbc , 0x00 , & V_103 , 1 , V_12 ) ;
if ( V_101 != NULL && V_103 != 0x67 ) {
T_1 V_105 = 0 , V_106 = 0 ;
memcpy ( V_101 , V_99 -> V_5 , V_99 -> V_104 ) ;
F_1 ( V_2 , 0xbc , 0xaa , & V_106 , 1 ,
V_18 ) ;
for ( V_38 = 0 ; V_38 < V_99 -> V_104 ; ) {
if ( ( V_99 -> V_104 - V_38 ) < V_102 ) {
V_102 = V_99 -> V_104 - V_38 ;
}
V_100 = ( T_1 * ) V_101 + V_38 ;
if ( F_1
( V_2 , V_107 , 0x0 , V_100 , V_102 ,
V_18 ) != V_102
) {
F_31 ( L_14 ) ;
V_8 = - V_24 ;
break;
}
V_38 = V_38 + V_102 ;
}
if ( V_8 || F_1
( V_2 , 0xa0 , 0xe600 , & V_105 , 1 ,
V_18 ) != 1 ) {
F_31 ( L_15 ) ;
V_8 = - V_24 ;
}
}
}
F_6 ( V_101 ) ;
F_32 ( V_99 ) ;
return V_8 ;
}
static int F_33 ( struct V_108 * V_109 ,
const struct V_110 * V_111 )
{
struct V_1 * V_31 = F_34 ( V_109 ) ;
if ( F_35 ( V_31 -> V_112 . V_113 ) == V_114 &&
F_35 ( V_31 -> V_112 . V_115 ) == V_116 &&
F_29 ( V_31 , L_16 ) != 0
) {
return - V_24 ;
}
if ( 0 != F_36 ( V_109 , & V_117 ,
V_118 , NULL , V_119 ) )
return - V_24 ;
return 0 ;
}
