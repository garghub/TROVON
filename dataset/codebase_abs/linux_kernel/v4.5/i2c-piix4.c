static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned char V_5 ;
unsigned short V_6 ;
if ( ( V_2 -> V_7 == V_8 ) &&
( V_2 -> V_9 == V_10 ) )
V_11 = 1 ;
if ( F_2 ( V_12 ) ) {
F_3 ( & V_2 -> V_13 ,
L_1 ) ;
return - V_14 ;
}
if ( F_2 ( V_15 ) &&
V_2 -> V_7 == V_16 ) {
F_3 ( & V_2 -> V_13 , L_2
L_3
L_4 ) ;
return - V_14 ;
}
if ( V_17 ) {
V_6 = V_17 & 0xfff0 ;
V_18 = 0 ;
} else {
F_4 ( V_2 , V_19 , & V_6 ) ;
V_6 &= 0xfff0 ;
if( V_6 == 0 ) {
F_3 ( & V_2 -> V_13 , L_5
L_6
L_7 ) ;
return - V_20 ;
}
}
if ( F_5 ( V_6 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_6 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_13 , L_8 ,
V_6 ) ;
return - V_24 ;
}
F_7 ( V_2 , V_25 , & V_5 ) ;
if ( V_17 ) {
F_8 ( V_2 , V_25 , V_5 & 0xfe ) ;
F_9 ( V_2 , V_19 , V_6 ) ;
F_8 ( V_2 , V_25 , V_5 | 0x01 ) ;
F_10 ( & V_2 -> V_13 , L_9
L_10 , V_6 ) ;
} else if ( ( V_5 & 1 ) == 0 ) {
if ( V_18 ) {
F_8 ( V_2 , V_25 ,
V_5 | 1 ) ;
F_11 ( & V_2 -> V_13 ,
L_11 ) ;
} else {
F_3 ( & V_2 -> V_13 ,
L_12 ) ;
F_12 ( V_6 , V_21 ) ;
return - V_20 ;
}
}
if ( ( ( V_5 & 0x0E ) == 8 ) || ( ( V_5 & 0x0E ) == 2 ) )
F_13 ( & V_2 -> V_13 , L_13 ) ;
else if ( ( V_5 & 0x0E ) == 0 )
F_13 ( & V_2 -> V_13 , L_14 ) ;
else
F_3 ( & V_2 -> V_13 , L_15
L_16 ) ;
F_7 ( V_2 , V_26 , & V_5 ) ;
F_10 ( & V_2 -> V_13 ,
L_17 ,
V_6 , V_5 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , T_1 V_27 )
{
unsigned short V_6 ;
T_1 V_28 , V_29 , V_30 , V_31 ;
T_1 V_32 , V_33 = 0x10 ;
if ( V_18 || V_17 ) {
F_3 ( & V_2 -> V_13 , L_18
L_19 ) ;
return - V_34 ;
}
if ( ( V_2 -> V_7 == V_35 &&
V_2 -> V_9 == V_36 &&
V_2 -> V_37 >= 0x41 ) ||
( V_2 -> V_7 == V_35 &&
V_2 -> V_9 == V_38 &&
V_2 -> V_37 >= 0x49 ) )
V_30 = 0x00 ;
else
V_30 = ( V_27 ) ? 0x28 : 0x2c ;
F_15 ( & V_39 ) ;
F_16 ( V_30 , V_40 ) ;
V_28 = F_17 ( V_40 + 1 ) ;
F_16 ( V_30 + 1 , V_40 ) ;
V_29 = F_17 ( V_40 + 1 ) ;
F_18 ( & V_39 ) ;
if ( ! V_30 ) {
V_31 = V_28 & 0x10 ;
V_6 = V_29 << 8 ;
if ( V_27 )
V_6 |= 0x20 ;
} else {
V_31 = V_28 & 0x01 ;
V_6 = ( ( V_29 << 8 ) | V_28 ) & 0xffe0 ;
}
if ( ! V_31 ) {
F_3 ( & V_2 -> V_13 ,
L_12 ) ;
return - V_20 ;
}
if ( F_5 ( V_6 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_6 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_13 , L_8 ,
V_6 ) ;
return - V_24 ;
}
if ( V_27 ) {
F_10 ( & V_2 -> V_13 ,
L_20 ,
V_6 ) ;
return V_6 ;
}
if ( ! F_6 ( V_6 + V_33 , 1 , L_21 ) ) {
F_3 ( & V_2 -> V_13 , L_22
L_23 , V_6 + V_33 ) ;
F_12 ( V_6 , V_21 ) ;
return - V_24 ;
}
V_32 = F_17 ( V_6 + V_33 ) ;
F_12 ( V_6 + V_33 , 1 ) ;
if ( V_32 & 1 )
F_13 ( & V_2 -> V_13 , L_13 ) ;
else
F_13 ( & V_2 -> V_13 , L_14 ) ;
F_10 ( & V_2 -> V_13 ,
L_17 ,
V_6 , V_32 >> 4 ) ;
return V_6 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned short V_41 )
{
unsigned short V_6 ;
F_4 ( V_2 , V_41 , & V_6 ) ;
if ( ( V_6 & 1 ) == 0 ) {
F_13 ( & V_2 -> V_13 ,
L_24 ) ;
return - V_20 ;
}
V_6 &= 0xfff0 ;
if ( V_6 == 0 ) {
F_13 ( & V_2 -> V_13 ,
L_25 ) ;
return - V_20 ;
}
if ( F_5 ( V_6 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_6 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_13 , L_26
L_27 , V_6 ) ;
return - V_24 ;
}
F_10 ( & V_2 -> V_13 ,
L_20 ,
V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = F_21 ( V_43 ) ;
unsigned short V_6 = V_45 -> V_46 ;
int V_5 ;
int V_47 = 0 ;
int V_48 = 0 ;
F_13 ( & V_43 -> V_13 , L_28
L_29 , F_17 ( V_49 ) ,
F_17 ( V_50 ) , F_17 ( V_51 ) , F_17 ( V_52 ) ,
F_17 ( V_53 ) ) ;
if ( ( V_5 = F_17 ( V_54 ) ) != 0x00 ) {
F_13 ( & V_43 -> V_13 , L_30
L_31 , V_5 ) ;
F_16 ( V_5 , V_54 ) ;
if ( ( V_5 = F_17 ( V_54 ) ) != 0x00 ) {
F_3 ( & V_43 -> V_13 , L_32 , V_5 ) ;
return - V_24 ;
} else {
F_13 ( & V_43 -> V_13 , L_33 ) ;
}
}
F_16 ( F_22 ( V_49 ) | 0x040 , V_49 ) ;
if ( V_11 )
F_23 ( 2 ) ;
else
F_23 ( 1 ) ;
while ( ( ++ V_48 < V_55 ) &&
( ( V_5 = F_17 ( V_54 ) ) & 0x01 ) )
F_23 ( 1 ) ;
if ( V_48 == V_55 ) {
F_3 ( & V_43 -> V_13 , L_34 ) ;
V_47 = - V_56 ;
}
if ( V_5 & 0x10 ) {
V_47 = - V_57 ;
F_3 ( & V_43 -> V_13 , L_35 ) ;
}
if ( V_5 & 0x08 ) {
V_47 = - V_57 ;
F_13 ( & V_43 -> V_13 , L_36
L_37 ) ;
}
if ( V_5 & 0x04 ) {
V_47 = - V_58 ;
F_13 ( & V_43 -> V_13 , L_38 ) ;
}
if ( F_17 ( V_54 ) != 0x00 )
F_16 ( F_22 ( V_54 ) , V_54 ) ;
if ( ( V_5 = F_17 ( V_54 ) ) != 0x00 ) {
F_3 ( & V_43 -> V_13 , L_39
L_40 , V_5 ) ;
}
F_13 ( & V_43 -> V_13 , L_41
L_29 , F_17 ( V_49 ) ,
F_17 ( V_50 ) , F_17 ( V_51 ) , F_17 ( V_52 ) ,
F_17 ( V_53 ) ) ;
return V_47 ;
}
static T_2 F_24 ( struct V_42 * V_59 , T_3 V_60 ,
unsigned short V_61 , char V_62 ,
T_1 V_63 , int V_64 , union V_65 * V_66 )
{
struct V_44 * V_45 = F_21 ( V_59 ) ;
unsigned short V_6 = V_45 -> V_46 ;
int V_67 , V_68 ;
int V_69 ;
switch ( V_64 ) {
case V_70 :
F_16 ( ( V_60 << 1 ) | V_62 ,
V_51 ) ;
V_64 = V_71 ;
break;
case V_72 :
F_16 ( ( V_60 << 1 ) | V_62 ,
V_51 ) ;
if ( V_62 == V_73 )
F_16 ( V_63 , V_50 ) ;
V_64 = V_74 ;
break;
case V_75 :
F_16 ( ( V_60 << 1 ) | V_62 ,
V_51 ) ;
F_16 ( V_63 , V_50 ) ;
if ( V_62 == V_73 )
F_16 ( V_66 -> V_76 , V_52 ) ;
V_64 = V_77 ;
break;
case V_78 :
F_16 ( ( V_60 << 1 ) | V_62 ,
V_51 ) ;
F_16 ( V_63 , V_50 ) ;
if ( V_62 == V_73 ) {
F_16 ( V_66 -> V_79 & 0xff , V_52 ) ;
F_16 ( ( V_66 -> V_79 & 0xff00 ) >> 8 , V_53 ) ;
}
V_64 = V_80 ;
break;
case V_81 :
F_16 ( ( V_60 << 1 ) | V_62 ,
V_51 ) ;
F_16 ( V_63 , V_50 ) ;
if ( V_62 == V_73 ) {
V_68 = V_66 -> V_82 [ 0 ] ;
if ( V_68 == 0 || V_68 > V_83 )
return - V_34 ;
F_16 ( V_68 , V_52 ) ;
F_17 ( V_49 ) ;
for ( V_67 = 1 ; V_67 <= V_68 ; V_67 ++ )
F_16 ( V_66 -> V_82 [ V_67 ] , V_84 ) ;
}
V_64 = V_85 ;
break;
default:
F_25 ( & V_59 -> V_13 , L_42 , V_64 ) ;
return - V_86 ;
}
F_16 ( ( V_64 & 0x1C ) + ( V_87 & 1 ) , V_49 ) ;
V_69 = F_20 ( V_59 ) ;
if ( V_69 )
return V_69 ;
if ( ( V_62 == V_73 ) || ( V_64 == V_71 ) )
return 0 ;
switch ( V_64 ) {
case V_74 :
case V_77 :
V_66 -> V_76 = F_17 ( V_52 ) ;
break;
case V_80 :
V_66 -> V_79 = F_17 ( V_52 ) + ( F_17 ( V_53 ) << 8 ) ;
break;
case V_85 :
V_66 -> V_82 [ 0 ] = F_17 ( V_52 ) ;
if ( V_66 -> V_82 [ 0 ] == 0 || V_66 -> V_82 [ 0 ] > V_83 )
return - V_88 ;
F_17 ( V_49 ) ;
for ( V_67 = 1 ; V_67 <= V_66 -> V_82 [ 0 ] ; V_67 ++ )
V_66 -> V_82 [ V_67 ] = F_17 ( V_84 ) ;
break;
}
return 0 ;
}
static T_2 F_26 ( struct V_42 * V_59 , T_3 V_60 ,
unsigned short V_61 , char V_62 ,
T_1 V_63 , int V_64 , union V_65 * V_66 )
{
struct V_44 * V_45 = F_21 ( V_59 ) ;
T_1 V_28 ;
T_1 V_89 ;
int V_90 ;
F_15 ( & V_39 ) ;
F_16 ( V_91 , V_40 ) ;
V_28 = F_17 ( V_40 + 1 ) ;
V_89 = V_45 -> V_89 ;
if ( ( V_28 & V_92 ) != ( V_89 << 1 ) )
F_16 ( ( V_28 & ~ V_92 ) | ( V_89 << 1 ) ,
V_40 + 1 ) ;
V_90 = F_24 ( V_59 , V_60 , V_61 , V_62 ,
V_63 , V_64 , V_66 ) ;
F_16 ( V_28 , V_40 + 1 ) ;
F_18 ( & V_39 ) ;
return V_90 ;
}
static T_4 F_27 ( struct V_42 * V_93 )
{
return V_94 | V_95 |
V_96 | V_97 |
V_98 ;
}
static int F_28 ( struct V_1 * V_13 , unsigned short V_46 ,
bool V_99 , unsigned short V_89 ,
const char * V_23 , struct V_42 * * V_100 )
{
struct V_42 * V_59 ;
struct V_44 * V_45 ;
int V_90 ;
V_59 = F_29 ( sizeof( * V_59 ) , V_101 ) ;
if ( V_59 == NULL ) {
F_12 ( V_46 , V_21 ) ;
return - V_102 ;
}
V_59 -> V_103 = V_104 ;
V_59 -> V_105 = V_106 | V_107 ;
V_59 -> V_108 = V_99 ? & V_109
: & V_110 ;
V_45 = F_29 ( sizeof( * V_45 ) , V_101 ) ;
if ( V_45 == NULL ) {
F_30 ( V_59 ) ;
F_12 ( V_46 , V_21 ) ;
return - V_102 ;
}
V_45 -> V_46 = V_46 ;
V_45 -> V_99 = V_99 ;
V_45 -> V_89 = V_89 ;
V_59 -> V_13 . V_111 = & V_13 -> V_13 ;
snprintf ( V_59 -> V_23 , sizeof( V_59 -> V_23 ) ,
L_43 , V_23 , V_46 ) ;
F_31 ( V_59 , V_45 ) ;
V_90 = F_32 ( V_59 ) ;
if ( V_90 ) {
F_3 ( & V_13 -> V_13 , L_44 ) ;
F_30 ( V_45 ) ;
F_30 ( V_59 ) ;
F_12 ( V_46 , V_21 ) ;
return V_90 ;
}
* V_100 = V_59 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_13 , unsigned short V_46 )
{
struct V_44 * V_45 ;
int V_89 ;
int V_90 ;
for ( V_89 = 0 ; V_89 < V_112 ; V_89 ++ ) {
V_90 = F_28 ( V_13 , V_46 , true , V_89 ,
V_113 [ V_89 ] ,
& V_114 [ V_89 ] ) ;
if ( V_90 < 0 )
goto error;
}
return V_90 ;
error:
F_3 ( & V_13 -> V_13 ,
L_45 ) ;
while ( -- V_89 >= 0 ) {
V_45 = F_21 ( V_114 [ V_89 ] ) ;
if ( V_45 -> V_46 ) {
F_34 ( V_114 [ V_89 ] ) ;
F_30 ( V_45 ) ;
F_30 ( V_114 [ V_89 ] ) ;
V_114 [ V_89 ] = NULL ;
}
}
return V_90 ;
}
static int F_35 ( struct V_1 * V_13 , const struct V_3 * V_4 )
{
int V_90 ;
bool V_115 = false ;
if ( ( V_13 -> V_7 == V_116 &&
V_13 -> V_9 == V_117 &&
V_13 -> V_37 >= 0x40 ) ||
V_13 -> V_7 == V_35 ) {
V_115 = true ;
if ( ! F_6 ( V_40 , 2 , L_46 ) ) {
F_3 ( & V_13 -> V_13 ,
L_47 ,
V_40 ) ;
return - V_24 ;
}
V_90 = F_14 ( V_13 , V_4 , 0 ) ;
if ( V_90 < 0 ) {
F_12 ( V_40 , 2 ) ;
return V_90 ;
}
V_90 = F_33 ( V_13 , V_90 ) ;
if ( V_90 < 0 ) {
F_12 ( V_40 , 2 ) ;
return V_90 ;
}
} else {
V_90 = F_1 ( V_13 , V_4 ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = F_28 ( V_13 , V_90 , false , 0 , L_48 ,
& V_114 [ 0 ] ) ;
if ( V_90 < 0 )
return V_90 ;
}
V_90 = - V_20 ;
if ( V_13 -> V_7 == V_116 &&
V_13 -> V_9 == V_117 ) {
if ( V_13 -> V_37 < 0x40 ) {
V_90 = F_19 ( V_13 , V_4 , 0x58 ) ;
} else {
V_90 = F_14 ( V_13 , V_4 , 1 ) ;
}
}
if ( V_13 -> V_7 == V_35 &&
V_13 -> V_9 == V_36 ) {
V_90 = F_14 ( V_13 , V_4 , 1 ) ;
}
if ( V_90 > 0 ) {
F_28 ( V_13 , V_90 , false , 0 ,
V_115 ? V_118 : L_48 ,
& V_119 ) ;
}
return 0 ;
}
static void F_36 ( struct V_42 * V_59 )
{
struct V_44 * V_45 = F_21 ( V_59 ) ;
if ( V_45 -> V_46 ) {
F_34 ( V_59 ) ;
if ( V_45 -> V_89 == 0 ) {
F_12 ( V_45 -> V_46 , V_21 ) ;
if ( V_45 -> V_99 )
F_12 ( V_40 , 2 ) ;
}
F_30 ( V_45 ) ;
F_30 ( V_59 ) ;
}
}
static void F_37 ( struct V_1 * V_13 )
{
int V_89 = V_112 ;
while ( -- V_89 >= 0 ) {
if ( V_114 [ V_89 ] ) {
F_36 ( V_114 [ V_89 ] ) ;
V_114 [ V_89 ] = NULL ;
}
}
if ( V_119 ) {
F_36 ( V_119 ) ;
V_119 = NULL ;
}
}
