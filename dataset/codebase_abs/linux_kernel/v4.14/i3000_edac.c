static inline unsigned long F_1 ( T_1 V_1 , T_2 V_2 )
{
V_2 >>= V_3 ;
V_2 |= ( V_1 & 1 ) << ( 32 - V_3 ) ;
return V_2 ;
}
static inline unsigned long F_2 ( T_2 V_2 )
{
return V_2 & ~ ( V_4 - 1 ) & ~ V_5 ;
}
static inline int F_3 ( T_2 V_2 )
{
return V_2 & 1 ;
}
static inline unsigned char F_4 ( unsigned char V_6 )
{
return ( V_6 & 0x70 ) >> 4 ;
}
static inline unsigned char F_5 ( unsigned char V_6 )
{
return V_6 & 0x07 ;
}
static void F_6 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_7 ( V_8 -> V_12 ) ;
F_8 ( V_12 , V_13 , & V_10 -> V_14 ) ;
if ( ! ( V_10 -> V_14 & V_15 ) )
return;
F_9 ( V_12 , V_16 , & V_10 -> V_1 ) ;
F_10 ( V_12 , V_17 , & V_10 -> V_2 ) ;
F_9 ( V_12 , V_18 , & V_10 -> V_19 ) ;
F_8 ( V_12 , V_13 , & V_10 -> V_20 ) ;
if ( ( V_10 -> V_14 ^ V_10 -> V_20 ) & V_15 ) {
F_9 ( V_12 , V_16 , & V_10 -> V_1 ) ;
F_10 ( V_12 , V_17 , & V_10 -> V_2 ) ;
F_9 ( V_12 , V_18 , & V_10 -> V_19 ) ;
}
F_11 ( V_12 , V_13 , V_15 ,
V_15 ) ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
int V_21 )
{
int V_22 , V_23 , V_24 ;
unsigned long V_25 , V_26 ;
V_23 = V_8 -> V_27 [ 0 ] -> V_28 - 1 ;
if ( ! ( V_10 -> V_14 & V_15 ) )
return 0 ;
if ( ! V_21 )
return 1 ;
if ( ( V_10 -> V_14 ^ V_10 -> V_20 ) & V_15 ) {
F_13 ( V_29 , V_8 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
L_1 , L_2 ) ;
V_10 -> V_14 = V_10 -> V_20 ;
}
V_25 = F_1 ( V_10 -> V_1 , V_10 -> V_2 ) ;
V_26 = F_2 ( V_10 -> V_2 ) ;
V_24 = F_3 ( V_10 -> V_2 ) ;
V_22 = F_14 ( V_8 , V_25 ) ;
if ( V_10 -> V_14 & V_30 )
F_13 ( V_29 , V_8 , 1 ,
V_25 , V_26 , 0 ,
V_22 , - 1 , - 1 ,
L_3 , L_2 ) ;
else
F_13 ( V_31 , V_8 , 1 ,
V_25 , V_26 , V_10 -> V_19 ,
V_22 , V_23 ? V_24 : 0 , - 1 ,
L_4 , L_2 ) ;
return 1 ;
}
static void F_15 ( struct V_7 * V_8 )
{
struct V_9 V_10 ;
F_16 ( 1 , L_5 , V_8 -> V_32 ) ;
F_6 ( V_8 , & V_10 ) ;
F_12 ( V_8 , & V_10 , 1 ) ;
}
static int F_17 ( const unsigned char * V_33 ,
const unsigned char * V_34 ,
const unsigned char * V_35 ,
const unsigned char * V_36 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 / 2 ; V_37 ++ )
if ( F_4 ( V_33 [ V_37 ] ) != F_4 ( V_34 [ V_37 ] ) ||
F_5 ( V_33 [ V_37 ] ) !=
F_5 ( V_34 [ V_37 ] ) )
return 0 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
if ( V_35 [ V_37 ] != V_36 [ V_37 ] )
return 0 ;
return 1 ;
}
static int F_18 ( struct V_11 * V_12 , int V_39 )
{
int V_40 ;
int V_37 , V_41 ;
struct V_7 * V_8 = NULL ;
struct V_42 V_43 [ 2 ] ;
unsigned long V_44 , V_45 ;
int V_46 , V_28 ;
unsigned char V_6 [ V_47 / 2 ] , V_48 [ V_47 ] ;
unsigned char * V_33 = V_6 , * V_34 = & V_6 [ V_38 / 2 ] ;
unsigned char * V_35 = V_48 , * V_36 = & V_48 [ V_38 ] ;
unsigned long V_49 ;
void T_3 * V_50 ;
F_16 ( 0 , L_6 ) ;
F_10 ( V_12 , V_51 , ( T_2 * ) & V_49 ) ;
V_49 &= V_52 ;
V_50 = F_19 ( V_49 , V_53 ) ;
if ( ! V_50 ) {
F_20 ( V_54 L_7 ,
V_49 ) ;
return - V_55 ;
}
V_33 [ 0 ] = F_21 ( V_50 + V_56 + 0 ) ;
V_33 [ 1 ] = F_21 ( V_50 + V_56 + 1 ) ;
V_34 [ 0 ] = F_21 ( V_50 + V_57 + 0 ) ;
V_34 [ 1 ] = F_21 ( V_50 + V_57 + 1 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_35 [ V_37 ] = F_21 ( V_50 + V_58 + V_37 ) ;
V_36 [ V_37 ] = F_21 ( V_50 + V_59 + V_37 ) ;
}
F_22 ( V_50 ) ;
V_46 = F_17 ( V_33 , V_34 , V_35 , V_36 ) ;
V_28 = V_46 ? 2 : 1 ;
V_43 [ 0 ] . type = V_60 ;
V_43 [ 0 ] . V_61 = V_47 / V_28 ;
V_43 [ 0 ] . V_62 = true ;
V_43 [ 1 ] . type = V_63 ;
V_43 [ 1 ] . V_61 = V_28 ;
V_43 [ 1 ] . V_62 = false ;
V_8 = F_23 ( 0 , F_24 ( V_43 ) , V_43 , 0 ) ;
if ( ! V_8 )
return - V_64 ;
F_16 ( 3 , L_8 ) ;
V_8 -> V_12 = & V_12 -> V_65 ;
V_8 -> V_66 = V_67 ;
V_8 -> V_68 = V_69 ;
V_8 -> V_70 = V_69 ;
V_8 -> V_71 = V_72 ;
V_8 -> V_73 = V_74 [ V_39 ] . V_73 ;
V_8 -> V_75 = F_25 ( V_12 ) ;
V_8 -> V_76 = F_15 ;
V_8 -> V_77 = NULL ;
for ( V_44 = V_37 = 0 ; V_37 < V_8 -> V_78 ; V_37 ++ ) {
T_1 V_79 ;
T_2 V_80 ;
struct V_81 * V_82 = V_8 -> V_27 [ V_37 ] ;
V_79 = V_48 [ V_37 ] ;
V_80 = V_79 << ( V_83 - V_3 ) ;
if ( V_46 )
V_80 <<= 1 ;
F_16 ( 3 , L_9 , V_37 , V_80 ) ;
if ( V_80 == V_44 )
continue;
V_82 -> V_84 = V_44 ;
V_82 -> V_85 = V_80 - 1 ;
V_45 = V_80 - V_44 ;
V_44 = V_80 ;
for ( V_41 = 0 ; V_41 < V_28 ; V_41 ++ ) {
struct V_86 * V_87 = V_82 -> V_88 [ V_41 ] -> V_87 ;
V_87 -> V_45 = V_45 / V_28 ;
V_87 -> V_89 = V_4 ;
V_87 -> V_90 = V_91 ;
V_87 -> V_92 = V_93 ;
V_87 -> V_94 = V_95 ;
}
}
F_11 ( V_12 , V_13 , V_15 ,
V_15 ) ;
V_40 = - V_55 ;
if ( F_26 ( V_8 ) ) {
F_16 ( 3 , L_10 ) ;
goto V_96;
}
V_97 = F_27 ( & V_12 -> V_65 , V_72 ) ;
if ( ! V_97 ) {
F_20 ( V_98
L_11 ,
V_99 ) ;
F_20 ( V_98
L_12 ,
V_99 ) ;
}
F_16 ( 3 , L_13 ) ;
return 0 ;
V_96:
if ( V_8 )
F_28 ( V_8 ) ;
return V_40 ;
}
static int F_29 ( struct V_11 * V_12 , const struct V_100 * V_101 )
{
int V_40 ;
F_16 ( 0 , L_6 ) ;
if ( F_30 ( V_12 ) < 0 )
return - V_102 ;
V_40 = F_18 ( V_12 , V_101 -> V_103 ) ;
if ( ! V_104 )
V_104 = F_31 ( V_12 ) ;
return V_40 ;
}
static void F_32 ( struct V_11 * V_12 )
{
struct V_7 * V_8 ;
F_16 ( 0 , L_14 ) ;
if ( V_97 )
F_33 ( V_97 ) ;
V_8 = F_34 ( & V_12 -> V_65 ) ;
if ( ! V_8 )
return;
F_28 ( V_8 ) ;
}
static int T_4 F_35 ( void )
{
int V_105 ;
F_16 ( 3 , L_6 ) ;
F_36 () ;
V_105 = F_37 ( & V_106 ) ;
if ( V_105 < 0 )
goto V_107;
if ( ! V_104 ) {
V_108 = 0 ;
V_104 = F_38 ( V_109 ,
V_110 , NULL ) ;
if ( ! V_104 ) {
F_16 ( 0 , L_15 ) ;
V_105 = - V_55 ;
goto V_111;
}
V_105 = F_29 ( V_104 , V_112 ) ;
if ( V_105 < 0 ) {
F_16 ( 0 , L_16 ) ;
V_105 = - V_55 ;
goto V_111;
}
}
return 0 ;
V_111:
F_39 ( & V_106 ) ;
V_107:
F_40 ( V_104 ) ;
return V_105 ;
}
static void T_5 F_41 ( void )
{
F_16 ( 3 , L_6 ) ;
F_39 ( & V_106 ) ;
if ( ! V_108 ) {
F_32 ( V_104 ) ;
F_40 ( V_104 ) ;
}
}
