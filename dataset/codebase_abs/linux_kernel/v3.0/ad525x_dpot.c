static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 -> V_5 ( V_2 -> V_3 . V_6 ) ;
}
static inline int F_2 ( struct V_1 * V_2 , T_1 V_7 )
{
return V_2 -> V_3 . V_4 -> V_8 ( V_2 -> V_3 . V_6 , V_7 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
return V_2 -> V_3 . V_4 -> V_9 ( V_2 -> V_3 . V_6 , V_7 ) ;
}
static inline int F_4 ( struct V_1 * V_2 , T_1 V_10 )
{
return V_2 -> V_3 . V_4 -> V_11 ( V_2 -> V_3 . V_6 , V_10 ) ;
}
static inline int F_5 ( struct V_1 * V_2 , T_1 V_7 , T_2 V_10 )
{
return V_2 -> V_3 . V_4 -> V_12 ( V_2 -> V_3 . V_6 , V_7 , V_10 ) ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_7 , T_2 V_10 )
{
return V_2 -> V_3 . V_4 -> V_13 ( V_2 -> V_3 . V_6 , V_7 , V_10 ) ;
}
static T_3 F_7 ( struct V_1 * V_2 , T_1 V_7 )
{
unsigned V_14 = 0 ;
int V_15 ;
if ( ! ( V_7 & ( V_16 | V_17 ) ) ) {
if ( V_2 -> V_18 & V_19 )
return V_2 -> V_20 [ V_7 & V_21 ] ;
if ( V_2 -> V_22 == F_8 ( V_23 ) ||
V_2 -> V_22 == F_8 ( V_24 ) ||
V_2 -> V_22 == F_8 ( V_25 ) ) {
V_15 = F_2 ( V_2 ,
V_26 << 2 ) ;
if ( V_2 -> V_22 == F_8 ( V_23 ) )
V_15 = V_15 >> 2 ;
return V_15 ;
} else if ( V_2 -> V_22 == F_8 ( V_27 ) ||
V_2 -> V_22 == F_8 ( V_28 ) ) {
V_15 = F_2 ( V_2 ,
V_29 << 2 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_2 -> V_22 == F_8 ( V_28 ) )
V_15 = V_15 >> 2 ;
return V_15 ;
}
V_14 = V_30 ;
} else if ( V_7 & V_16 ) {
V_14 = V_31 ;
}
if ( V_2 -> V_18 & V_32 )
return F_2 ( V_2 , V_14 ) ;
else if ( V_2 -> V_18 & V_33 )
return F_3 ( V_2 , V_14 ) ;
return - V_34 ;
}
static T_3 F_9 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_15 ;
unsigned V_14 = 0 ;
switch ( V_2 -> V_22 ) {
case F_8 ( V_35 ) :
case F_8 ( V_36 ) :
return F_1 ( V_2 ) ;
case F_8 ( V_37 ) :
case F_8 ( V_38 ) :
case F_8 ( V_39 ) :
case F_8 ( V_40 ) :
case F_8 ( V_41 ) :
case F_8 ( V_42 ) :
case F_8 ( V_43 ) :
V_14 = ( ( V_7 & V_21 ) == V_44 ) ?
0 : V_45 ;
return F_2 ( V_2 , V_14 ) ;
case F_8 ( V_46 ) :
case F_8 ( V_47 ) :
case F_8 ( V_48 ) :
return F_1 ( V_2 ) ;
case F_8 ( V_49 ) :
case F_8 ( V_50 ) :
V_14 = ( ( V_7 & V_21 ) == V_44 ) ?
0 : V_51 ;
return F_2 ( V_2 , V_14 ) ;
case F_8 ( V_52 ) :
case F_8 ( V_53 ) :
F_5 ( V_2 ,
( V_29 << 2 ) , 0 ) ;
V_15 = F_3 ( V_2 ,
V_54 << 2 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_10 ( V_15 ) ;
if ( V_2 -> V_22 == F_8 ( V_28 ) )
V_15 = V_15 >> 2 ;
return V_15 ;
default:
if ( ( V_7 & V_55 ) || ( V_2 -> V_56 > 256 ) )
return F_3 ( V_2 , ( V_7 & 0xF8 ) |
( ( V_7 & 0x7 ) << 1 ) ) ;
else
return F_2 ( V_2 , V_7 ) ;
}
}
static T_3 F_11 ( struct V_1 * V_2 , T_1 V_7 )
{
if ( V_2 -> V_18 & V_57 )
return F_7 ( V_2 , V_7 ) ;
else
return F_9 ( V_2 , V_7 ) ;
}
static T_3 F_12 ( struct V_1 * V_2 , T_1 V_7 , T_2 V_15 )
{
unsigned V_10 = 0 ;
if ( ! ( V_7 & ( V_16 | V_17 | V_58 ) ) ) {
if ( V_2 -> V_18 & V_19 )
V_2 -> V_20 [ V_7 & V_21 ] = V_15 ;
if ( V_2 -> V_18 & V_59 ) {
if ( V_2 -> V_18 & V_60 ) {
V_10 = ( ( V_7 & V_21 ) <<
F_13 ( V_2 -> V_61 ) ) |
V_15 ;
return F_4 ( V_2 , V_10 ) ;
} else if ( V_2 -> V_18 & V_32 ) {
V_10 = ( ( V_7 & V_21 ) <<
F_13 ( V_2 -> V_61 ) ) |
V_15 ;
return F_5 ( V_2 , V_10 >> 8 ,
V_10 & 0xFF ) ;
} else
F_14 () ;
} else {
if ( V_2 -> V_22 == F_8 ( V_23 ) ||
V_2 -> V_22 == F_8 ( V_24 ) ||
V_2 -> V_22 == F_8 ( V_25 ) ) {
F_5 ( V_2 , V_62 << 2 ,
V_63 ) ;
if ( V_2 -> V_22 == F_8 ( V_23 ) )
V_15 = V_15 << 2 ;
return F_5 ( V_2 ,
( V_64 << 2 ) |
( V_15 >> 8 ) , V_15 & 0xFF ) ;
} else if ( V_2 -> V_22 == F_8 ( V_27 ) ||
V_2 -> V_22 == F_8 ( V_28 ) ) {
F_5 ( V_2 ,
V_65 << 2 ,
V_66 ) ;
if ( V_2 -> V_22 == F_8 ( V_28 ) )
V_15 = V_15 << 2 ;
return F_5 ( V_2 ,
( V_54 << 2 ) |
( V_15 >> 8 ) , V_15 & 0xFF ) ;
}
V_10 = V_67 | ( V_7 & V_21 ) ;
}
} else if ( V_7 & V_16 ) {
V_10 = V_68 | ( V_7 & V_21 ) ;
} else if ( V_7 & V_17 ) {
switch ( V_7 ) {
case V_69 :
V_10 = V_70 ;
break;
case V_71 :
V_10 = V_72 ;
break;
case V_73 :
V_10 = V_74 ;
break;
case V_75 :
V_10 = V_76 ;
break;
}
} else if ( V_7 & V_58 ) {
if ( V_2 -> V_22 == F_8 ( V_23 ) ||
V_2 -> V_22 == F_8 ( V_24 ) ) {
return F_5 ( V_2 ,
V_77 << 2 , 0 ) ;
} else if ( V_2 -> V_22 == F_8 ( V_27 ) ||
V_2 -> V_22 == F_8 ( V_28 ) ) {
return F_5 ( V_2 ,
V_78 << 2 , 0 ) ;
}
} else
F_14 () ;
if ( V_2 -> V_18 & V_32 )
return F_5 ( V_2 , V_10 , V_15 ) ;
else if ( V_2 -> V_18 & V_33 )
return F_6 ( V_2 , V_10 , V_15 ) ;
return - V_34 ;
}
static T_3 F_15 ( struct V_1 * V_2 , T_1 V_7 , T_2 V_15 )
{
unsigned V_79 = 0 , V_14 = 0 ;
switch ( V_2 -> V_22 ) {
case F_8 ( V_35 ) :
case F_8 ( V_36 ) :
return F_4 ( V_2 , V_15 ) ;
break;
case F_8 ( V_37 ) :
case F_8 ( V_38 ) :
case F_8 ( V_39 ) :
case F_8 ( V_40 ) :
case F_8 ( V_41 ) :
case F_8 ( V_42 ) :
case F_8 ( V_43 ) :
V_14 = ( ( V_7 & V_21 ) == V_44 ) ?
0 : V_45 ;
return F_5 ( V_2 , V_14 , V_15 ) ;
break;
case F_8 ( V_47 ) :
case F_8 ( V_48 ) :
if ( V_7 & V_58 ) {
V_79 = F_1 ( V_2 ) ;
if ( V_79 >> 6 )
return - V_34 ;
V_14 = V_80 ;
}
return F_5 ( V_2 , V_14 , V_15 ) ;
break;
case F_8 ( V_49 ) :
case F_8 ( V_50 ) :
V_14 = ( ( V_7 & V_21 ) == V_44 ) ?
0 : V_51 ;
if ( V_7 & V_58 ) {
V_79 = F_3 ( V_2 , V_14 ) ;
if ( V_79 >> 14 )
return - V_34 ;
V_14 |= V_81 ;
}
return F_5 ( V_2 , V_14 , V_15 ) ;
break;
case F_8 ( V_46 ) :
if ( V_7 & V_58 ) {
V_79 = F_3 ( V_2 , V_79 ) ;
if ( V_79 >> 14 )
return - V_34 ;
V_14 = V_81 ;
}
return F_5 ( V_2 , V_14 , V_15 ) ;
break;
case F_8 ( V_52 ) :
case F_8 ( V_53 ) :
F_5 ( V_2 , V_65 << 2 ,
V_66 ) ;
if ( V_7 & V_58 )
return F_5 ( V_2 ,
V_78 << 2 , 0 ) ;
if ( V_2 -> V_22 == F_8 ( V_53 ) )
V_15 = V_15 << 2 ;
return F_5 ( V_2 , ( V_54 << 2 ) |
( V_15 >> 8 ) , V_15 & 0xFF ) ;
break;
default:
if ( V_7 & V_17 )
return F_4 ( V_2 , V_7 ) ;
if ( V_2 -> V_56 > 256 )
return F_6 ( V_2 , ( V_7 & 0xF8 ) |
( ( V_7 & 0x7 ) << 1 ) , V_15 ) ;
else
return F_5 ( V_2 , V_7 , V_15 ) ;
}
}
static T_3 F_16 ( struct V_1 * V_2 , T_1 V_7 , T_2 V_15 )
{
if ( V_2 -> V_18 & V_57 )
return F_12 ( V_2 , V_7 , V_15 ) ;
else
return F_15 ( V_2 , V_7 , V_15 ) ;
}
static T_4 F_17 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
char * V_86 , T_5 V_7 )
{
struct V_1 * V_87 = F_18 ( V_83 ) ;
T_3 V_15 ;
if ( V_7 & V_88 )
return sprintf ( V_86 , L_1 ,
F_19 ( V_21 & V_7 , V_87 -> V_89 ) ?
L_2 : L_3 ) ;
F_20 ( & V_87 -> V_90 ) ;
V_15 = F_11 ( V_87 , V_7 ) ;
F_21 ( & V_87 -> V_90 ) ;
if ( V_15 < 0 )
return - V_91 ;
if ( V_7 & V_55 )
return sprintf ( V_86 , L_4 , V_15 & 0xFFFF ) ;
else
return sprintf ( V_86 , L_5 , V_15 & V_87 -> V_92 ) ;
}
static T_4 F_22 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
const char * V_86 , T_6 V_93 , T_5 V_7 )
{
struct V_1 * V_87 = F_18 ( V_83 ) ;
unsigned long V_15 ;
int V_94 ;
if ( V_7 & V_88 ) {
if ( ! strncmp ( V_86 , L_2 , sizeof( L_2 ) ) )
F_23 ( V_21 & V_7 , V_87 -> V_89 ) ;
else
F_24 ( V_21 & V_7 , V_87 -> V_89 ) ;
return V_93 ;
}
if ( ( V_7 & V_58 ) &&
! F_19 ( V_21 & V_7 , V_87 -> V_89 ) )
return - V_95 ;
V_94 = F_25 ( V_86 , 10 , & V_15 ) ;
if ( V_94 )
return V_94 ;
if ( V_15 > V_87 -> V_92 )
V_15 = V_87 -> V_92 ;
F_20 ( & V_87 -> V_90 ) ;
F_16 ( V_87 , V_7 , V_15 ) ;
if ( V_7 & V_16 )
F_26 ( 26 ) ;
else if ( V_7 & V_58 )
F_26 ( 400 ) ;
F_21 ( & V_87 -> V_90 ) ;
return V_93 ;
}
static T_4 F_27 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
const char * V_86 , T_6 V_93 , T_5 V_7 )
{
struct V_1 * V_87 = F_18 ( V_83 ) ;
F_20 ( & V_87 -> V_90 ) ;
F_16 ( V_87 , V_7 , 0 ) ;
F_21 ( & V_87 -> V_90 ) ;
return V_93 ;
}
T_7 int F_28 ( struct V_82 * V_83 ,
unsigned V_96 , unsigned V_97 )
{
int V_94 = F_29 ( & V_83 -> V_98 ,
V_99 [ V_97 ] ) ;
if ( V_96 & V_100 )
V_94 |= F_29 ( & V_83 -> V_98 ,
V_101 [ V_97 ] ) ;
if ( V_96 & V_102 )
V_94 |= F_29 ( & V_83 -> V_98 ,
V_103 [ V_97 ] ) ;
if ( V_96 & V_104 ) {
V_94 |= F_29 ( & V_83 -> V_98 ,
V_105 [ V_97 ] ) ;
V_94 |= F_29 ( & V_83 -> V_98 ,
V_106 [ V_97 ] ) ;
}
if ( V_94 )
F_30 ( V_83 , L_6 ,
V_97 ) ;
return V_94 ;
}
inline void F_31 ( struct V_82 * V_83 ,
unsigned V_96 , unsigned V_97 )
{
F_32 ( & V_83 -> V_98 ,
V_99 [ V_97 ] ) ;
if ( V_96 & V_100 )
F_32 ( & V_83 -> V_98 ,
V_101 [ V_97 ] ) ;
if ( V_96 & V_102 )
F_32 ( & V_83 -> V_98 ,
V_103 [ V_97 ] ) ;
if ( V_96 & V_104 ) {
F_32 ( & V_83 -> V_98 ,
V_105 [ V_97 ] ) ;
F_32 ( & V_83 -> V_98 ,
V_106 [ V_97 ] ) ;
}
}
T_7 int F_33 ( struct V_82 * V_83 ,
struct V_107 * V_3 , const struct V_108 * V_109 )
{
struct V_1 * V_87 ;
int V_110 , V_94 = 0 ;
V_87 = F_34 ( sizeof( struct V_1 ) , V_111 ) ;
if ( ! V_87 ) {
V_94 = - V_112 ;
goto exit;
}
F_35 ( V_83 , V_87 ) ;
F_36 ( & V_87 -> V_90 ) ;
V_87 -> V_3 = * V_3 ;
V_87 -> V_61 = V_109 -> V_61 ;
V_87 -> V_56 = 1 << F_13 ( V_87 -> V_61 ) ;
V_87 -> V_92 = V_87 -> V_56 - 1 ;
V_87 -> V_18 = F_37 ( V_87 -> V_61 ) ;
V_87 -> V_22 = F_8 ( V_87 -> V_61 ) ;
V_87 -> V_113 = F_38 ( V_87 -> V_61 ) ;
for ( V_110 = V_44 ; V_110 < V_114 ; V_110 ++ )
if ( V_87 -> V_113 & ( 1 << V_110 ) ) {
V_94 = F_28 ( V_83 , V_87 -> V_18 , V_110 ) ;
if ( V_94 )
goto V_115;
if ( V_87 -> V_18 & V_19 )
V_87 -> V_20 [ V_110 ] = V_87 -> V_56 / 2 ;
}
if ( V_87 -> V_18 & V_116 )
V_94 = F_39 ( & V_83 -> V_98 , & V_117 ) ;
if ( V_94 ) {
F_30 ( V_83 , L_7 ) ;
goto V_118;
}
F_40 ( V_83 , L_8 ,
V_109 -> V_119 , V_87 -> V_56 ) ;
return 0 ;
V_115:
for ( V_110 = V_44 ; V_110 < V_114 ; V_110 ++ )
if ( V_87 -> V_113 & ( 1 << V_110 ) )
F_31 ( V_83 , V_87 -> V_18 , V_110 ) ;
V_118:
F_41 ( V_87 ) ;
F_35 ( V_83 , NULL ) ;
exit:
F_30 ( V_83 , L_9 ,
V_109 -> V_119 , V_109 -> V_61 ) ;
return V_94 ;
}
T_8 int F_42 ( struct V_82 * V_83 )
{
struct V_1 * V_87 = F_18 ( V_83 ) ;
int V_110 ;
for ( V_110 = V_44 ; V_110 < V_114 ; V_110 ++ )
if ( V_87 -> V_113 & ( 1 << V_110 ) )
F_31 ( V_83 , V_87 -> V_18 , V_110 ) ;
F_41 ( V_87 ) ;
return 0 ;
}
