static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
struct V_6 V_7 ;
struct V_8 V_9 = {
. V_10 = 2 ,
. V_11 = V_2 -> V_12 ,
. V_13 = V_2 -> V_12 ,
} ;
F_2 ( & V_7 ) ;
F_3 ( & V_9 , & V_7 ) ;
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_12 [ 0 ] = F_5 ( V_3 ) ;
V_2 -> V_12 [ 1 ] = V_4 ;
V_5 = F_6 ( V_2 -> V_15 , & V_7 ) ;
if ( V_5 )
F_7 ( F_8 ( V_2 ) ,
L_1 , V_3 ) ;
F_9 ( & V_2 -> V_14 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_16 )
{
int V_5 = - 1 ;
struct V_6 V_7 ;
struct V_8 V_9 = {
. V_10 = 2 ,
. V_11 = V_2 -> V_12 ,
. V_13 = V_2 -> V_12 ,
} ;
F_2 ( & V_7 ) ;
F_3 ( & V_9 , & V_7 ) ;
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_12 [ 0 ] = F_11 ( V_3 ) ;
V_2 -> V_12 [ 1 ] = 0 ;
V_5 = F_6 ( V_2 -> V_15 , & V_7 ) ;
if ( V_5 )
F_7 ( F_8 ( V_2 ) ,
L_2 , V_3 ) ;
else
* V_16 = V_2 -> V_12 [ 1 ] ;
F_9 ( & V_2 -> V_14 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_3 , T_1 * V_4 )
{
int V_5 ;
T_2 V_17 ;
struct V_6 V_7 ;
struct V_8 V_9 = {
. V_10 = 3 ,
. V_11 = V_2 -> V_12 ,
. V_13 = V_2 -> V_12 ,
} ;
F_2 ( & V_7 ) ;
F_3 ( & V_9 , & V_7 ) ;
V_17 = F_13 ( V_3 ) ;
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_12 [ 0 ] = V_17 >> 8 & 0xff ;
V_2 -> V_12 [ 1 ] = V_17 & 0xff ;
V_2 -> V_12 [ 2 ] = 0 ;
V_5 = F_6 ( V_2 -> V_15 , & V_7 ) ;
if ( V_5 )
F_7 ( F_8 ( V_2 ) ,
L_3 , V_3 ) ;
else
* V_4 = V_2 -> V_12 [ 2 ] ;
F_9 ( & V_2 -> V_14 ) ;
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_16 )
{
int V_5 ;
T_2 V_17 ;
struct V_6 V_7 ;
struct V_8 V_9 = {
. V_10 = 3 ,
. V_11 = V_2 -> V_12 ,
. V_13 = V_2 -> V_12 ,
} ;
F_2 ( & V_7 ) ;
F_3 ( & V_9 , & V_7 ) ;
V_17 = F_15 ( V_3 ) ;
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_12 [ 0 ] = V_17 >> 8 & 0xff ;
V_2 -> V_12 [ 1 ] = V_17 & 0xff ;
V_2 -> V_12 [ 2 ] = V_16 ;
V_5 = F_6 ( V_2 -> V_15 , & V_7 ) ;
if ( V_5 )
F_7 ( F_8 ( V_2 ) ,
L_4 , V_3 ) ;
F_9 ( & V_2 -> V_14 ) ;
return V_5 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_3 ,
const T_1 * V_18 , T_3 V_19 )
{
int V_5 ;
T_2 V_17 ;
T_1 V_20 [ 2 ] ;
struct V_6 V_7 ;
struct V_8 V_21 = {
. V_10 = 2 ,
. V_11 = V_2 -> V_12 ,
} ;
struct V_8 V_22 = {
. V_10 = 2 ,
. V_11 = & V_20 ,
} ;
struct V_8 V_23 = {
. V_10 = V_19 ,
. V_11 = V_18 ,
} ;
if ( V_19 > V_24 - 2 ) {
F_7 ( F_8 ( V_2 ) , L_5 ) ;
V_19 = V_24 - 2 ;
}
F_2 ( & V_7 ) ;
F_3 ( & V_21 , & V_7 ) ;
F_3 ( & V_22 , & V_7 ) ;
F_3 ( & V_23 , & V_7 ) ;
V_17 = F_15 ( V_3 ) ;
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_12 [ 0 ] = V_17 >> 8 & 0xff ;
V_2 -> V_12 [ 1 ] = V_17 & 0xff ;
V_20 [ 0 ] = 0x0 ;
V_20 [ 1 ] = V_19 ;
V_5 = F_6 ( V_2 -> V_15 , & V_7 ) ;
if ( V_5 )
F_7 ( F_8 ( V_2 ) , L_6 ) ;
F_9 ( & V_2 -> V_14 ) ;
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_1 * V_18 , T_1 * V_10 , T_1 * V_25 )
{
T_1 V_26 ;
T_1 V_27 [ 2 ] ;
T_1 V_28 [ 2 ] ;
T_2 V_17 ;
int V_5 ;
struct V_6 V_7 ;
struct V_8 V_21 = {
. V_10 = 2 ,
. V_11 = & V_27 ,
} ;
struct V_8 V_23 = {
. V_10 = 0x0 ,
. V_13 = V_18 ,
} ;
struct V_8 V_29 = {
. V_10 = 2 ,
. V_13 = & V_28 ,
} ;
V_5 = F_12 ( V_2 , V_30 , & V_26 ) ;
if ( V_5 )
goto V_31;
if ( V_26 > V_32 - 1 ) {
F_7 ( F_8 ( V_2 ) , L_7 ) ;
V_26 = V_32 - 1 ;
}
if ( V_26 > * V_10 ) {
F_7 ( F_8 ( V_2 ) , L_8 ) ;
V_26 = * V_10 ;
}
V_17 = F_13 ( V_30 + 1 ) ;
V_27 [ 0 ] = V_17 >> 8 & 0xff ;
V_27 [ 1 ] = V_17 & 0xff ;
V_23 . V_10 = V_26 ;
F_2 ( & V_7 ) ;
F_3 ( & V_21 , & V_7 ) ;
F_3 ( & V_23 , & V_7 ) ;
F_3 ( & V_29 , & V_7 ) ;
V_5 = F_6 ( V_2 -> V_15 , & V_7 ) ;
if ( V_5 ) {
F_7 ( F_8 ( V_2 ) , L_9 ) ;
goto V_31;
}
* V_25 = V_28 [ 0 ] ;
* V_10 = V_26 ;
#ifdef F_18
F_19 ( V_33 , L_10 ,
V_34 , 16 , 1 , V_18 , * V_10 , 0 ) ;
F_20 ( L_11 ,
V_28 [ 0 ] , V_28 [ 1 ] ) ;
#endif
V_31:
return V_5 ;
}
static int F_21 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_16 ;
int V_5 = 0 ;
F_22 ( F_8 ( V_2 ) , L_12 , V_38 -> V_10 ) ;
V_5 = F_16 ( V_2 , 0x000 , V_38 -> V_18 , V_38 -> V_10 ) ;
if ( V_5 )
goto V_40;
F_23 ( & V_2 -> V_41 ) ;
V_5 = F_10 ( V_2 , V_42 , & V_16 ) ;
if ( V_5 )
goto V_40;
V_16 |= 0x1 ;
if ( V_38 -> V_18 [ 0 ] & V_43 )
V_16 |= 0x4 ;
F_1 ( V_2 , V_42 , V_16 ) ;
V_5 = F_24 (
& V_2 -> V_41 ,
5 * V_44 ) ;
if ( V_5 == - V_45 )
goto V_40;
if ( V_5 == 0 ) {
F_25 ( F_8 ( V_2 ) , L_13 ) ;
V_5 = - V_46 ;
goto V_40;
}
V_5 = F_10 ( V_2 , V_47 , & V_16 ) ;
if ( V_5 )
goto V_40;
if ( V_16 & 0x1 ) {
F_22 ( F_8 ( V_2 ) , L_14 ) ;
V_5 = - V_48 ;
} else
F_22 ( F_8 ( V_2 ) , L_15 ) ;
V_40:
return V_5 ;
}
static int F_26 ( struct V_35 * V_36 , T_1 * V_49 )
{
F_27 ( L_16 ) ;
* V_49 = 0 ;
return 0 ;
}
static int F_28 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_16 ;
int V_5 ;
F_22 ( F_8 ( V_2 ) , L_17 ) ;
V_5 = F_10 ( V_2 , V_50 , & V_16 ) ;
if ( V_5 )
return V_5 ;
V_16 &= ~ ( 0x1 | 0x8 ) ;
F_1 ( V_2 , V_50 , V_16 ) ;
return 0 ;
}
static void F_29 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_16 ;
int V_5 ;
F_22 ( F_8 ( V_2 ) , L_18 ) ;
V_5 = F_10 ( V_2 , V_50 , & V_16 ) ;
if ( V_5 )
return;
V_16 |= 0x1 | 0x8 ;
F_1 ( V_2 , V_50 , V_16 ) ;
}
static int F_30 ( struct V_35 * V_36 , T_1 V_51 , T_1 V_52 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_16 ;
int V_5 ;
F_22 ( F_8 ( V_2 ) , L_19 , V_52 ) ;
F_31 ( V_51 != 0 ) ;
F_31 ( V_52 < V_53 ) ;
F_31 ( V_52 > V_54 ) ;
V_16 = ( V_52 - 11 ) << 4 | 0x03 ;
F_14 ( V_2 , V_55 , V_16 ) ;
V_5 = F_10 ( V_2 , V_56 , & V_16 ) ;
if ( V_5 )
return V_5 ;
V_16 |= 0x04 ;
F_1 ( V_2 , V_56 , V_16 ) ;
V_16 &= ~ 0x04 ;
F_1 ( V_2 , V_56 , V_16 ) ;
F_32 ( V_57 ) ;
return 0 ;
}
static int F_33 ( struct V_35 * V_36 ,
struct V_58 * V_59 ,
unsigned long V_60 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
F_22 ( F_8 ( V_2 ) , L_20 ) ;
if ( V_60 & V_61 ) {
T_1 V_62 , V_63 ;
V_62 = F_34 ( V_59 -> V_64 ) >> 8 & 0xff ;
V_63 = F_34 ( V_59 -> V_64 ) & 0xff ;
F_1 ( V_2 , V_65 , V_62 ) ;
F_1 ( V_2 , V_66 , V_63 ) ;
F_22 ( F_8 ( V_2 ) ,
L_21 , V_59 -> V_64 ) ;
}
if ( V_60 & V_67 ) {
T_1 V_68 , V_27 [ 8 ] ;
memcpy ( V_27 , & V_59 -> V_69 , 8 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_1 ( V_2 , V_70 + V_68 , V_27 [ V_68 ] ) ;
#ifdef F_18
F_20 ( L_22 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_20 ( L_23 , V_27 [ 7 - V_68 ] ) ;
F_20 ( L_24 ) ;
#endif
}
if ( V_60 & V_71 ) {
T_1 V_72 , V_73 ;
V_73 = F_34 ( V_59 -> V_74 ) >> 8 & 0xff ;
V_72 = F_34 ( V_59 -> V_74 ) & 0xff ;
F_1 ( V_2 , V_75 , V_73 ) ;
F_1 ( V_2 , V_76 , V_72 ) ;
F_22 ( F_8 ( V_2 ) , L_25 , V_59 -> V_74 ) ;
}
if ( V_60 & V_77 ) {
T_1 V_16 ;
int V_5 ;
V_5 = F_10 ( V_2 , V_78 , & V_16 ) ;
if ( V_5 )
return V_5 ;
if ( V_59 -> V_79 )
V_16 |= 0x8 ;
else
V_16 &= ~ 0x8 ;
F_1 ( V_2 , V_78 , V_16 ) ;
F_22 ( F_8 ( V_2 ) , L_26 ,
V_59 -> V_79 ? L_27 : L_28 ) ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_1 V_10 = V_32 ;
T_1 V_25 = 0 ;
T_1 V_16 ;
int V_5 = 0 ;
struct V_37 * V_38 ;
V_5 = F_10 ( V_2 , V_80 , & V_16 ) ;
if ( V_5 )
goto V_31;
V_16 |= 4 ;
F_1 ( V_2 , V_80 , V_16 ) ;
V_38 = F_36 ( V_10 ) ;
if ( ! V_38 ) {
V_5 = - V_81 ;
goto V_31;
}
V_5 = F_17 ( V_2 , F_37 ( V_38 , V_10 ) , & V_10 , & V_25 ) ;
if ( V_5 < 0 ) {
F_7 ( F_8 ( V_2 ) , L_29 ) ;
F_38 ( V_38 ) ;
V_5 = - V_82 ;
goto V_31;
}
F_39 ( V_38 , V_10 - 2 ) ;
F_40 ( V_2 -> V_36 , V_38 , V_25 ) ;
F_22 ( F_8 ( V_2 ) , L_30 ) ;
V_31:
V_5 = F_10 ( V_2 , V_80 , & V_16 ) ;
if ( V_5 )
return V_5 ;
V_16 &= ~ 0x4 ;
F_1 ( V_2 , V_80 , V_16 ) ;
return V_5 ;
}
static T_4 F_41 ( int V_83 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
T_1 V_84 ;
int V_5 ;
V_5 = F_10 ( V_2 , V_85 , & V_84 ) ;
if ( V_5 )
goto V_31;
if ( V_84 & 0x1 )
F_42 ( & V_2 -> V_41 ) ;
if ( V_84 & 0x8 )
F_35 ( V_2 ) ;
V_31:
return V_86 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_16 ;
V_5 = F_1 ( V_2 , V_87 , 0x07 ) ;
if ( V_5 )
goto V_88;
V_5 = F_1 ( V_2 , V_89 , 0x98 ) ;
if ( V_5 )
goto V_88;
V_5 = F_1 ( V_2 , V_90 , 0x95 ) ;
if ( V_5 )
goto V_88;
V_5 = F_14 ( V_2 , V_55 , 0x03 ) ;
if ( V_5 )
goto V_88;
V_5 = F_14 ( V_2 , V_91 , 0x01 ) ;
if ( V_5 )
goto V_88;
V_5 = F_14 ( V_2 , V_92 , 0x80 ) ;
if ( V_5 )
goto V_88;
V_5 = F_14 ( V_2 , V_93 , 0x90 ) ;
if ( V_5 )
goto V_88;
V_5 = F_14 ( V_2 , V_94 , 0x80 ) ;
if ( V_5 )
goto V_88;
V_5 = F_14 ( V_2 , V_95 , 0x10 ) ;
if ( V_5 )
goto V_88;
V_5 = F_14 ( V_2 , V_96 , 0x21 ) ;
if ( V_5 )
goto V_88;
V_5 = F_1 ( V_2 , V_97 , 0x80 ) ;
if ( V_5 )
goto V_88;
V_5 = F_1 ( V_2 , V_98 , 0x60 ) ;
if ( V_5 )
goto V_88;
V_5 = F_1 ( V_2 , V_99 , 0x40 ) ;
if ( V_5 )
goto V_88;
V_5 = F_1 ( V_2 , V_56 , 0x04 ) ;
if ( V_5 )
goto V_88;
V_5 = F_1 ( V_2 , V_56 , 0x0 ) ;
if ( V_5 )
goto V_88;
F_32 ( 192 ) ;
V_5 = F_10 ( V_2 , V_78 , & V_16 ) ;
if ( V_5 )
goto V_88;
V_16 &= ~ 0x3 ;
V_5 = F_1 ( V_2 , V_78 , V_16 ) ;
if ( V_5 )
goto V_88;
if ( F_44 ( V_2 -> V_15 ) -> V_100 == V_101 ) {
F_12 ( V_2 , V_102 , & V_16 ) ;
V_16 |= 0x7 ;
F_14 ( V_2 , V_102 , V_16 ) ;
F_10 ( V_2 , V_103 , & V_16 ) ;
V_16 |= 0x8 ;
F_1 ( V_2 , V_103 , V_16 ) ;
F_10 ( V_2 , V_104 , & V_16 ) ;
V_16 |= 0x8 ;
F_1 ( V_2 , V_104 , V_16 ) ;
F_14 ( V_2 , V_105 , 0x28 ) ;
}
return 0 ;
V_88:
return V_5 ;
}
static int F_45 ( struct V_106 * V_15 )
{
int V_5 = - V_81 ;
struct V_1 * V_2 ;
F_46 ( & V_15 -> V_107 , L_31 , V_15 -> V_83 ) ;
V_2 = F_47 ( & V_15 -> V_107 , sizeof( struct V_1 ) , V_108 ) ;
if ( ! V_2 )
goto V_88;
V_2 -> V_12 = F_47 ( & V_15 -> V_107 , 3 , V_108 ) ;
if ( ! V_2 -> V_12 )
goto V_88;
V_15 -> V_109 = V_110 ;
if ( V_15 -> V_111 > V_112 )
V_15 -> V_111 = V_112 ;
F_48 ( & V_2 -> V_14 ) ;
F_49 ( & V_2 -> V_41 ) ;
V_2 -> V_15 = V_15 ;
F_50 ( V_15 , V_2 ) ;
V_2 -> V_36 = F_51 ( 0 , & V_113 ) ;
if ( ! V_2 -> V_36 )
goto V_88;
V_2 -> V_36 -> V_39 = V_2 ;
V_2 -> V_36 -> V_114 = & V_2 -> V_15 -> V_107 ;
V_2 -> V_36 -> V_115 -> V_116 [ 0 ] = V_117 ;
V_2 -> V_36 -> V_118 = V_119 | V_120 |
V_121 ;
F_22 ( F_8 ( V_2 ) , L_32 ) ;
V_5 = F_52 ( V_2 -> V_36 ) ;
if ( V_5 )
goto V_122;
V_5 = F_43 ( V_2 ) ;
if ( V_5 )
goto V_123;
V_5 = F_53 ( & V_15 -> V_107 ,
V_15 -> V_83 ,
NULL ,
F_41 ,
V_124 | V_125 ,
F_54 ( & V_15 -> V_107 ) ,
V_2 ) ;
if ( V_5 ) {
F_7 ( F_8 ( V_2 ) , L_33 ) ;
goto V_126;
}
return 0 ;
V_126:
V_123:
F_55 ( V_2 -> V_36 ) ;
V_122:
F_56 ( V_2 -> V_36 ) ;
V_88:
return V_5 ;
}
static int F_57 ( struct V_106 * V_15 )
{
struct V_1 * V_2 = F_58 ( V_15 ) ;
F_22 ( F_8 ( V_2 ) , L_34 ) ;
F_55 ( V_2 -> V_36 ) ;
F_56 ( V_2 -> V_36 ) ;
return 0 ;
}
