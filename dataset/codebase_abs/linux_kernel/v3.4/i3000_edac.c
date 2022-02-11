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
F_13 ( V_8 , L_1 ) ;
V_10 -> V_15 = V_10 -> V_21 ;
}
V_26 = F_1 ( V_10 -> V_1 , V_10 -> V_2 ) ;
V_27 = F_2 ( V_10 -> V_2 ) ;
V_25 = F_3 ( V_10 -> V_2 ) ;
V_23 = F_14 ( V_8 , V_26 ) ;
if ( V_10 -> V_15 & V_30 )
F_15 ( V_8 , V_26 , V_27 , V_23 , L_2 ) ;
else
F_16 ( V_8 , V_26 , V_27 , V_10 -> V_20 , V_23 ,
V_24 ? V_25 : 0 , L_3 ) ;
return 1 ;
}
static void F_17 ( struct V_7 * V_8 )
{
struct V_9 V_10 ;
F_18 ( L_4 , V_8 -> V_31 , V_32 ) ;
F_6 ( V_8 , & V_10 ) ;
F_12 ( V_8 , & V_10 , 1 ) ;
}
static int F_19 ( const unsigned char * V_33 ,
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
static int F_20 ( struct V_11 * V_12 , int V_39 )
{
int V_40 ;
int V_37 ;
struct V_7 * V_8 = NULL ;
unsigned long V_41 ;
int V_42 , V_29 ;
unsigned char V_6 [ V_43 / 2 ] , V_44 [ V_43 ] ;
unsigned char * V_33 = V_6 , * V_34 = & V_6 [ V_38 / 2 ] ;
unsigned char * V_35 = V_44 , * V_36 = & V_44 [ V_38 ] ;
unsigned long V_45 ;
void T_3 * V_46 ;
F_21 ( L_5 , V_32 ) ;
F_10 ( V_12 , V_47 , ( T_2 * ) & V_45 ) ;
V_45 &= V_48 ;
V_46 = F_22 ( V_45 , V_49 ) ;
if ( ! V_46 ) {
F_23 ( V_50 L_6 ,
V_45 ) ;
return - V_51 ;
}
V_33 [ 0 ] = F_24 ( V_46 + V_52 + 0 ) ;
V_33 [ 1 ] = F_24 ( V_46 + V_52 + 1 ) ;
V_34 [ 0 ] = F_24 ( V_46 + V_53 + 0 ) ;
V_34 [ 1 ] = F_24 ( V_46 + V_53 + 1 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_35 [ V_37 ] = F_24 ( V_46 + V_54 + V_37 ) ;
V_36 [ V_37 ] = F_24 ( V_46 + V_55 + V_37 ) ;
}
F_25 ( V_46 ) ;
V_42 = F_19 ( V_33 , V_34 , V_35 , V_36 ) ;
V_29 = V_42 ? 2 : 1 ;
V_8 = F_26 ( 0 , V_43 / V_29 , V_29 , 0 ) ;
if ( ! V_8 )
return - V_56 ;
F_27 ( L_7 , V_32 ) ;
V_8 -> V_13 = & V_12 -> V_13 ;
V_8 -> V_57 = V_58 ;
V_8 -> V_59 = V_60 ;
V_8 -> V_61 = V_60 ;
V_8 -> V_62 = V_63 ;
V_8 -> V_64 = V_65 ;
V_8 -> V_66 = V_67 [ V_39 ] . V_66 ;
V_8 -> V_68 = F_28 ( V_12 ) ;
V_8 -> V_69 = F_17 ;
V_8 -> V_70 = NULL ;
for ( V_41 = V_37 = 0 ; V_37 < V_8 -> V_71 ; V_37 ++ ) {
T_1 V_72 ;
T_2 V_73 ;
struct V_74 * V_75 = & V_8 -> V_28 [ V_37 ] ;
V_72 = V_44 [ V_37 ] ;
V_73 = V_72 << ( V_76 - V_3 ) ;
if ( V_42 )
V_73 <<= 1 ;
F_27 ( L_8 ,
V_32 , V_37 , V_73 ) ;
if ( V_73 == V_41 ) {
V_75 -> V_77 = V_78 ;
continue;
}
V_75 -> V_79 = V_41 ;
V_75 -> V_80 = V_73 - 1 ;
V_75 -> V_81 = V_73 - V_41 ;
V_41 = V_73 ;
V_75 -> V_82 = V_4 ;
V_75 -> V_77 = V_83 ;
V_75 -> V_84 = V_85 ;
V_75 -> V_86 = V_87 ;
}
F_11 ( V_12 , V_14 , V_16 ,
V_16 ) ;
V_40 = - V_51 ;
if ( F_29 ( V_8 ) ) {
F_27 ( L_9 , V_32 ) ;
goto V_88;
}
V_89 = F_30 ( & V_12 -> V_13 , V_63 ) ;
if ( ! V_89 ) {
F_23 ( V_90
L_10 ,
V_32 ) ;
F_23 ( V_90
L_11 ,
V_32 ) ;
}
F_27 ( L_12 , V_32 ) ;
return 0 ;
V_88:
if ( V_8 )
F_31 ( V_8 ) ;
return V_40 ;
}
static int T_4 F_32 ( struct V_11 * V_12 ,
const struct V_91 * V_92 )
{
int V_40 ;
F_21 ( L_5 , V_32 ) ;
if ( F_33 ( V_12 ) < 0 )
return - V_93 ;
V_40 = F_20 ( V_12 , V_92 -> V_94 ) ;
if ( ! V_95 )
V_95 = F_34 ( V_12 ) ;
return V_40 ;
}
static void T_5 F_35 ( struct V_11 * V_12 )
{
struct V_7 * V_8 ;
F_21 ( L_13 , V_32 ) ;
if ( V_89 )
F_36 ( V_89 ) ;
V_8 = F_37 ( & V_12 -> V_13 ) ;
if ( ! V_8 )
return;
F_31 ( V_8 ) ;
}
static int T_6 F_38 ( void )
{
int V_96 ;
F_27 ( L_5 , V_32 ) ;
F_39 () ;
V_96 = F_40 ( & V_97 ) ;
if ( V_96 < 0 )
goto V_98;
if ( ! V_95 ) {
V_99 = 0 ;
V_95 = F_41 ( V_100 ,
V_101 , NULL ) ;
if ( ! V_95 ) {
F_21 ( L_14 ) ;
V_96 = - V_51 ;
goto V_102;
}
V_96 = F_32 ( V_95 , V_103 ) ;
if ( V_96 < 0 ) {
F_21 ( L_15 ) ;
V_96 = - V_51 ;
goto V_102;
}
}
return 0 ;
V_102:
F_42 ( & V_97 ) ;
V_98:
if ( V_95 )
F_43 ( V_95 ) ;
return V_96 ;
}
static void T_7 F_44 ( void )
{
F_27 ( L_5 , V_32 ) ;
F_42 ( & V_97 ) ;
if ( ! V_99 ) {
F_35 ( V_95 ) ;
F_43 ( V_95 ) ;
}
}
