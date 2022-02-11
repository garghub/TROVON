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
F_20 ( V_33 L_11 ,
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
V_5 = F_10 ( V_2 , V_41 , & V_16 ) ;
if ( V_5 )
goto V_40;
V_16 |= 0x1 ;
V_16 &= ~ 0x4 ;
F_1 ( V_2 , V_41 , V_16 ) ;
F_23 ( V_2 -> V_42 ) ;
V_5 = F_24 (
& V_2 -> V_42 ,
5 * V_43 ) ;
if ( V_5 == - V_44 )
goto V_40;
if ( V_5 == 0 ) {
V_5 = - V_45 ;
goto V_40;
}
V_5 = F_10 ( V_2 , V_46 , & V_16 ) ;
if ( V_5 )
goto V_40;
if ( V_16 & 0x1 ) {
F_7 ( F_8 ( V_2 ) , L_13 ) ;
V_5 = - V_47 ;
} else
F_22 ( F_8 ( V_2 ) , L_14 ) ;
V_40:
return V_5 ;
}
static int F_25 ( struct V_35 * V_36 , T_1 * V_48 )
{
F_20 ( V_49 L_15 ) ;
* V_48 = 0 ;
return 0 ;
}
static int F_26 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_16 ;
int V_5 ;
F_22 ( F_8 ( V_2 ) , L_16 ) ;
V_5 = F_10 ( V_2 , V_50 , & V_16 ) ;
if ( V_5 )
return V_5 ;
V_16 &= ~ ( 0x1 | 0x8 ) ;
F_1 ( V_2 , V_50 , V_16 ) ;
return 0 ;
}
static void F_27 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_16 ;
int V_5 ;
F_22 ( F_8 ( V_2 ) , L_17 ) ;
V_5 = F_10 ( V_2 , V_50 , & V_16 ) ;
if ( V_5 )
return;
V_16 |= 0x1 | 0x8 ;
F_1 ( V_2 , V_50 , V_16 ) ;
return;
}
static int F_28 ( struct V_35 * V_36 ,
int V_51 , int V_52 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_16 ;
int V_5 ;
F_22 ( F_8 ( V_2 ) , L_18 , V_52 ) ;
F_29 ( V_51 != 0 ) ;
F_29 ( V_52 < V_53 ) ;
F_29 ( V_52 > V_54 ) ;
V_16 = ( V_52 - 11 ) << 4 | 0x03 ;
F_14 ( V_2 , V_55 , V_16 ) ;
V_5 = F_10 ( V_2 , V_56 , & V_16 ) ;
if ( V_5 )
return V_5 ;
V_16 |= 0x04 ;
F_1 ( V_2 , V_56 , V_16 ) ;
V_16 &= ~ 0x04 ;
F_1 ( V_2 , V_56 , V_16 ) ;
F_30 ( V_57 ) ;
return 0 ;
}
static int F_31 ( struct V_35 * V_36 ,
struct V_58 * V_59 ,
unsigned long V_60 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
F_22 ( F_8 ( V_2 ) , L_19 ) ;
if ( V_60 & V_61 ) {
T_1 V_62 , V_63 ;
V_62 = V_59 -> V_64 >> 8 & 0xff ;
V_63 = V_59 -> V_64 & 0xff ;
F_1 ( V_2 , V_65 , V_62 ) ;
F_1 ( V_2 , V_66 , V_63 ) ;
F_22 ( F_8 ( V_2 ) ,
L_20 , V_59 -> V_64 ) ;
}
if ( V_60 & V_67 ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_1 ( V_2 , V_69 + V_68 ,
V_59 -> V_70 [ V_68 ] ) ;
#ifdef F_18
F_20 ( V_33 L_21 ) ;
for ( V_68 = 0 ; V_68 < 8 ; V_68 ++ )
F_20 ( L_22 , V_59 -> V_70 [ V_68 ] ) ;
F_20 ( V_33 L_23 ) ;
#endif
}
if ( V_60 & V_71 ) {
T_1 V_72 , V_73 ;
V_73 = V_59 -> V_74 >> 8 & 0xff ;
V_72 = V_59 -> V_74 & 0xff ;
F_1 ( V_2 , V_75 , V_73 ) ;
F_1 ( V_2 , V_76 , V_72 ) ;
F_22 ( F_8 ( V_2 ) , L_24 , V_59 -> V_74 ) ;
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
F_22 ( F_8 ( V_2 ) , L_25 ,
V_59 -> V_79 ? L_26 : L_27 ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
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
V_38 = F_33 ( V_10 , V_81 ) ;
if ( ! V_38 ) {
V_5 = - V_82 ;
goto V_31;
}
V_5 = F_17 ( V_2 , F_34 ( V_38 , V_10 ) , & V_10 , & V_25 ) ;
if ( V_5 < 0 ) {
F_7 ( F_8 ( V_2 ) , L_28 ) ;
F_35 ( V_38 ) ;
V_5 = - V_83 ;
goto V_31;
}
F_36 ( V_38 , V_10 - 2 ) ;
F_37 ( V_2 -> V_36 , V_38 , V_25 ) ;
F_22 ( F_8 ( V_2 ) , L_29 ) ;
V_31:
V_5 = F_10 ( V_2 , V_80 , & V_16 ) ;
if ( V_5 )
return V_5 ;
V_16 &= ~ 0x4 ;
F_1 ( V_2 , V_80 , V_16 ) ;
return V_5 ;
}
static T_4 F_38 ( int V_84 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
F_39 ( V_84 ) ;
F_40 ( & V_2 -> V_85 ) ;
return V_86 ;
}
static void F_41 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = F_42 ( V_88 , struct V_1 , V_85 ) ;
T_1 V_89 ;
int V_5 ;
V_5 = F_10 ( V_2 , V_90 , & V_89 ) ;
if ( V_5 )
goto V_31;
if ( V_89 & 0x1 )
F_43 ( & V_2 -> V_42 ) ;
if ( V_89 & 0x8 )
F_32 ( V_2 ) ;
V_31:
F_44 ( V_2 -> V_15 -> V_84 ) ;
}
static int F_45 ( struct V_91 * V_15 )
{
int V_5 = - V_82 ;
T_1 V_16 ;
struct V_1 * V_2 ;
F_20 ( V_92 L_30 , V_15 -> V_84 ) ;
V_2 = F_46 ( sizeof( struct V_1 ) , V_81 ) ;
if ( ! V_2 )
goto V_93;
V_2 -> V_12 = F_46 ( 3 , V_81 ) ;
if ( ! V_2 -> V_12 )
goto V_94;
V_15 -> V_95 = V_96 ;
if ( V_15 -> V_97 > V_98 )
V_15 -> V_97 = V_98 ;
F_47 ( & V_2 -> V_14 ) ;
F_48 ( & V_2 -> V_42 ) ;
F_49 ( & V_2 -> V_85 , F_41 ) ;
V_2 -> V_15 = V_15 ;
F_50 ( & V_15 -> V_36 , V_2 ) ;
V_2 -> V_36 = F_51 ( 0 , & V_99 ) ;
if ( ! V_2 -> V_36 )
goto V_100;
V_2 -> V_36 -> V_39 = V_2 ;
V_2 -> V_36 -> V_101 = & V_2 -> V_15 -> V_36 ;
V_2 -> V_36 -> V_102 -> V_103 [ 0 ] = V_104 ;
V_2 -> V_36 -> V_105 = V_106 | V_107 ;
F_22 ( F_8 ( V_2 ) , L_31 ) ;
V_5 = F_52 ( V_2 -> V_36 ) ;
if ( V_5 )
goto V_108;
F_1 ( V_2 , V_109 , 0x07 ) ;
F_1 ( V_2 , V_110 , 0x98 ) ;
F_1 ( V_2 , V_111 , 0x95 ) ;
F_14 ( V_2 , V_55 , 0x03 ) ;
F_14 ( V_2 , V_112 , 0x01 ) ;
F_14 ( V_2 , V_113 , 0x80 ) ;
F_14 ( V_2 , V_114 , 0x90 ) ;
F_14 ( V_2 , V_115 , 0x80 ) ;
F_14 ( V_2 , V_116 , 0x10 ) ;
F_14 ( V_2 , V_117 , 0x21 ) ;
F_1 ( V_2 , V_118 , 0x80 ) ;
F_1 ( V_2 , V_119 , 0x60 ) ;
F_1 ( V_2 , V_120 , 0x40 ) ;
F_1 ( V_2 , V_56 , 0x04 ) ;
F_1 ( V_2 , V_56 , 0x0 ) ;
F_30 ( 192 ) ;
V_5 = F_10 ( V_2 , V_78 , & V_16 ) ;
if ( V_5 )
goto V_121;
V_16 &= ~ 0x3 ;
F_1 ( V_2 , V_78 , V_16 ) ;
V_5 = F_53 ( V_15 -> V_84 ,
F_38 ,
V_122 ,
F_54 ( & V_15 -> V_36 ) ,
V_2 ) ;
if ( V_5 ) {
F_7 ( F_8 ( V_2 ) , L_32 ) ;
goto V_123;
}
return 0 ;
V_123:
V_121:
F_55 ( V_2 -> V_36 ) ;
V_108:
F_56 ( V_2 -> V_36 ) ;
V_100:
F_57 ( V_2 -> V_12 ) ;
V_94:
F_57 ( V_2 ) ;
V_93:
return V_5 ;
}
static int F_58 ( struct V_91 * V_15 )
{
struct V_1 * V_2 = F_59 ( & V_15 -> V_36 ) ;
F_22 ( F_8 ( V_2 ) , L_33 ) ;
F_60 ( V_15 -> V_84 , V_2 ) ;
F_61 ( & V_2 -> V_85 ) ;
F_55 ( V_2 -> V_36 ) ;
F_56 ( V_2 -> V_36 ) ;
F_50 ( & V_15 -> V_36 , NULL ) ;
F_57 ( V_2 -> V_12 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
static int T_5 F_62 ( void )
{
return F_63 ( & V_124 ) ;
}
static void T_6 F_64 ( void )
{
F_65 ( & V_124 ) ;
}
