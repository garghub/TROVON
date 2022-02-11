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
V_12 = F_7 ( V_8 -> V_13 ) ;
F_8 ( V_12 , V_14 , & V_10 -> V_15 ) ;
if ( ! ( V_10 -> V_15 & V_16 ) )
return;
F_9 ( V_12 , V_17 , & V_10 -> V_1 ) ;
F_10 ( V_12 , V_18 , & V_10 -> V_2 ) ;
F_9 ( V_12 , V_19 , & V_10 -> V_20 ) ;
F_8 ( V_12 , V_14 , & V_10 -> V_21 ) ;
if ( ( V_10 -> V_15 ^ V_10 -> V_21 ) & V_16 ) {
F_9 ( V_12 , V_17 , & V_10 -> V_1 ) ;
F_10 ( V_12 , V_18 , & V_10 -> V_2 ) ;
F_9 ( V_12 , V_19 , & V_10 -> V_20 ) ;
}
F_11 ( V_12 , V_14 , V_16 ,
V_16 ) ;
}
static int F_12 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
int V_22 )
{
int V_23 , V_24 , V_25 ;
unsigned long V_26 , V_27 ;
V_24 = V_8 -> V_28 [ 0 ] . V_29 - 1 ;
if ( ! ( V_10 -> V_15 & V_16 ) )
return 0 ;
if ( ! V_22 )
return 1 ;
if ( ( V_10 -> V_15 ^ V_10 -> V_21 ) & V_16 ) {
F_13 ( V_30 , V_8 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
L_1 , L_2 , NULL ) ;
V_10 -> V_15 = V_10 -> V_21 ;
}
V_26 = F_1 ( V_10 -> V_1 , V_10 -> V_2 ) ;
V_27 = F_2 ( V_10 -> V_2 ) ;
V_25 = F_3 ( V_10 -> V_2 ) ;
V_23 = F_14 ( V_8 , V_26 ) ;
if ( V_10 -> V_15 & V_31 )
F_13 ( V_30 , V_8 ,
V_26 , V_27 , 0 ,
V_23 , - 1 , - 1 ,
L_3 , L_2 , NULL ) ;
else
F_13 ( V_32 , V_8 ,
V_26 , V_27 , V_10 -> V_20 ,
V_23 , V_24 ? V_25 : 0 , - 1 ,
L_4 , L_2 , NULL ) ;
return 1 ;
}
static void F_15 ( struct V_7 * V_8 )
{
struct V_9 V_10 ;
F_16 ( L_5 , V_8 -> V_33 , V_34 ) ;
F_6 ( V_8 , & V_10 ) ;
F_12 ( V_8 , & V_10 , 1 ) ;
}
static int F_17 ( const unsigned char * V_35 ,
const unsigned char * V_36 ,
const unsigned char * V_37 ,
const unsigned char * V_38 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_40 / 2 ; V_39 ++ )
if ( F_4 ( V_35 [ V_39 ] ) != F_4 ( V_36 [ V_39 ] ) ||
F_5 ( V_35 [ V_39 ] ) !=
F_5 ( V_36 [ V_39 ] ) )
return 0 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
if ( V_37 [ V_39 ] != V_38 [ V_39 ] )
return 0 ;
return 1 ;
}
static int F_18 ( struct V_11 * V_12 , int V_41 )
{
int V_42 ;
int V_39 , V_43 ;
struct V_7 * V_8 = NULL ;
struct V_44 V_45 [ 2 ] ;
unsigned long V_46 , V_47 ;
int V_48 , V_29 ;
unsigned char V_6 [ V_49 / 2 ] , V_50 [ V_49 ] ;
unsigned char * V_35 = V_6 , * V_36 = & V_6 [ V_40 / 2 ] ;
unsigned char * V_37 = V_50 , * V_38 = & V_50 [ V_40 ] ;
unsigned long V_51 ;
void T_3 * V_52 ;
F_19 ( L_6 , V_34 ) ;
F_10 ( V_12 , V_53 , ( T_2 * ) & V_51 ) ;
V_51 &= V_54 ;
V_52 = F_20 ( V_51 , V_55 ) ;
if ( ! V_52 ) {
F_21 ( V_56 L_7 ,
V_51 ) ;
return - V_57 ;
}
V_35 [ 0 ] = F_22 ( V_52 + V_58 + 0 ) ;
V_35 [ 1 ] = F_22 ( V_52 + V_58 + 1 ) ;
V_36 [ 0 ] = F_22 ( V_52 + V_59 + 0 ) ;
V_36 [ 1 ] = F_22 ( V_52 + V_59 + 1 ) ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_37 [ V_39 ] = F_22 ( V_52 + V_60 + V_39 ) ;
V_38 [ V_39 ] = F_22 ( V_52 + V_61 + V_39 ) ;
}
F_23 ( V_52 ) ;
V_48 = F_17 ( V_35 , V_36 , V_37 , V_38 ) ;
V_29 = V_48 ? 2 : 1 ;
V_45 [ 0 ] . type = V_62 ;
V_45 [ 0 ] . V_63 = V_49 / V_29 ;
V_45 [ 0 ] . V_64 = true ;
V_45 [ 1 ] . type = V_65 ;
V_45 [ 1 ] . V_63 = V_29 ;
V_45 [ 1 ] . V_64 = false ;
V_8 = F_24 ( 0 , F_25 ( V_45 ) , V_45 , 0 ) ;
if ( ! V_8 )
return - V_66 ;
F_26 ( L_8 , V_34 ) ;
V_8 -> V_13 = & V_12 -> V_13 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 = V_70 ;
V_8 -> V_71 = V_70 ;
V_8 -> V_72 = V_73 ;
V_8 -> V_74 = V_75 ;
V_8 -> V_76 = V_77 [ V_41 ] . V_76 ;
V_8 -> V_78 = F_27 ( V_12 ) ;
V_8 -> V_79 = F_15 ;
V_8 -> V_80 = NULL ;
for ( V_46 = V_39 = 0 ; V_39 < V_8 -> V_81 ; V_39 ++ ) {
T_1 V_82 ;
T_2 V_83 ;
struct V_84 * V_85 = & V_8 -> V_28 [ V_39 ] ;
V_82 = V_50 [ V_39 ] ;
V_83 = V_82 << ( V_86 - V_3 ) ;
if ( V_48 )
V_83 <<= 1 ;
F_26 ( L_9 ,
V_34 , V_39 , V_83 ) ;
if ( V_83 == V_46 )
continue;
V_85 -> V_87 = V_46 ;
V_85 -> V_88 = V_83 - 1 ;
V_47 = V_83 - V_46 ;
V_46 = V_83 ;
for ( V_43 = 0 ; V_43 < V_29 ; V_43 ++ ) {
struct V_89 * V_90 = V_85 -> V_91 [ V_43 ] . V_90 ;
V_90 -> V_47 = V_47 / V_29 ;
V_90 -> V_92 = V_4 ;
V_90 -> V_93 = V_94 ;
V_90 -> V_95 = V_96 ;
V_90 -> V_97 = V_98 ;
}
}
F_11 ( V_12 , V_14 , V_16 ,
V_16 ) ;
V_42 = - V_57 ;
if ( F_28 ( V_8 ) ) {
F_26 ( L_10 , V_34 ) ;
goto V_99;
}
V_100 = F_29 ( & V_12 -> V_13 , V_73 ) ;
if ( ! V_100 ) {
F_21 ( V_101
L_11 ,
V_34 ) ;
F_21 ( V_101
L_12 ,
V_34 ) ;
}
F_26 ( L_13 , V_34 ) ;
return 0 ;
V_99:
if ( V_8 )
F_30 ( V_8 ) ;
return V_42 ;
}
static int T_4 F_31 ( struct V_11 * V_12 ,
const struct V_102 * V_103 )
{
int V_42 ;
F_19 ( L_6 , V_34 ) ;
if ( F_32 ( V_12 ) < 0 )
return - V_104 ;
V_42 = F_18 ( V_12 , V_103 -> V_105 ) ;
if ( ! V_106 )
V_106 = F_33 ( V_12 ) ;
return V_42 ;
}
static void T_5 F_34 ( struct V_11 * V_12 )
{
struct V_7 * V_8 ;
F_19 ( L_14 , V_34 ) ;
if ( V_100 )
F_35 ( V_100 ) ;
V_8 = F_36 ( & V_12 -> V_13 ) ;
if ( ! V_8 )
return;
F_30 ( V_8 ) ;
}
static int T_6 F_37 ( void )
{
int V_107 ;
F_26 ( L_6 , V_34 ) ;
F_38 () ;
V_107 = F_39 ( & V_108 ) ;
if ( V_107 < 0 )
goto V_109;
if ( ! V_106 ) {
V_110 = 0 ;
V_106 = F_40 ( V_111 ,
V_112 , NULL ) ;
if ( ! V_106 ) {
F_19 ( L_15 ) ;
V_107 = - V_57 ;
goto V_113;
}
V_107 = F_31 ( V_106 , V_114 ) ;
if ( V_107 < 0 ) {
F_19 ( L_16 ) ;
V_107 = - V_57 ;
goto V_113;
}
}
return 0 ;
V_113:
F_41 ( & V_108 ) ;
V_109:
if ( V_106 )
F_42 ( V_106 ) ;
return V_107 ;
}
static void T_7 F_43 ( void )
{
F_26 ( L_6 , V_34 ) ;
F_41 ( & V_108 ) ;
if ( ! V_110 ) {
F_34 ( V_106 ) ;
F_42 ( V_106 ) ;
}
}
