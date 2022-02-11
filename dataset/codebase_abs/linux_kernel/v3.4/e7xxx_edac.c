static inline int F_1 ( T_1 V_1 )
{
F_2 ( L_1 , V_2 ) ;
if ( ( V_1 & 0xff00 ) == 0 )
return 0 ;
if ( ( V_1 & 0x00ff ) == 0 )
return 1 ;
if ( ( V_1 & 0xf000 ) == 0 || ( V_1 & 0x0f00 ) == 0 )
return 0 ;
return 1 ;
}
static unsigned long F_3 ( struct V_3 * V_4 ,
unsigned long V_5 )
{
T_2 V_6 ;
struct V_7 * V_8 = (struct V_7 * ) V_4 -> V_9 ;
F_2 ( L_1 , V_2 ) ;
if ( ( V_5 < V_8 -> V_10 ) ||
( ( V_5 >= 0x100000 ) && ( V_5 < V_8 -> V_11 ) ) )
return V_5 ;
V_6 = ( V_5 - V_8 -> V_10 ) + V_8 -> V_11 ;
if ( V_6 < V_8 -> V_12 )
return V_6 ;
F_4 ( V_13 , L_2 , V_5 ) ;
return V_8 -> V_10 - 1 ;
}
static void F_5 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
T_2 V_16 , V_5 ;
T_1 V_1 ;
int V_17 ;
int V_18 ;
F_2 ( L_1 , V_2 ) ;
V_16 = V_15 -> V_19 ;
V_5 = V_16 >> 6 ;
V_1 = V_15 -> V_20 ;
V_17 = F_6 ( V_4 , V_5 ) ;
V_18 = F_1 ( V_1 ) ;
F_7 ( V_4 , V_5 , 0 , V_1 , V_17 , V_18 , L_3 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
F_2 ( L_1 , V_2 ) ;
F_9 ( V_4 , L_4 ) ;
}
static void F_10 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
T_2 V_21 , V_22 ;
int V_17 ;
F_2 ( L_1 , V_2 ) ;
V_21 = V_15 -> V_23 ;
V_22 = V_21 >> 6 ;
V_17 = F_6 ( V_4 , V_22 ) ;
F_11 ( V_4 , V_22 , 0 , V_17 , L_5 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_2 ( L_1 , V_2 ) ;
F_13 ( V_4 , L_6 ) ;
}
static void F_14 ( struct V_3 * V_4 ,
struct V_14 * V_15 )
{
struct V_7 * V_8 ;
V_8 = (struct V_7 * ) V_4 -> V_9 ;
F_15 ( V_8 -> V_24 , V_25 , & V_15 -> V_26 ) ;
F_15 ( V_8 -> V_24 , V_27 , & V_15 -> V_28 ) ;
if ( ( V_15 -> V_26 & 1 ) || ( V_15 -> V_28 & 1 ) ) {
F_16 ( V_8 -> V_24 , V_29 ,
& V_15 -> V_19 ) ;
F_17 ( V_8 -> V_24 ,
V_30 ,
& V_15 -> V_20 ) ;
}
if ( ( V_15 -> V_26 & 2 ) || ( V_15 -> V_28 & 2 ) )
F_16 ( V_8 -> V_24 , V_31 ,
& V_15 -> V_23 ) ;
if ( V_15 -> V_26 & 3 )
F_18 ( V_8 -> V_24 , V_25 , 0x03 , 0x03 ) ;
if ( V_15 -> V_28 & 3 )
F_18 ( V_8 -> V_24 , V_27 , 0x03 , 0x03 ) ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_14 * V_15 ,
int V_32 )
{
int V_33 ;
V_33 = 0 ;
if ( V_15 -> V_26 & 1 ) {
V_33 = 1 ;
if ( V_32 )
F_5 ( V_4 , V_15 ) ;
}
if ( V_15 -> V_26 & 2 ) {
V_33 = 1 ;
if ( V_32 )
F_10 ( V_4 , V_15 ) ;
}
if ( V_15 -> V_28 & 1 ) {
V_33 = 1 ;
if ( V_32 ) {
if ( V_15 -> V_26 & 1 )
F_8 ( V_4 ) ;
else
F_5 ( V_4 , V_15 ) ;
}
}
if ( V_15 -> V_28 & 2 ) {
V_33 = 1 ;
if ( V_32 ) {
if ( V_15 -> V_26 & 2 )
F_12 ( V_4 ) ;
else
F_10 ( V_4 , V_15 ) ;
}
}
return V_33 ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_14 V_15 ;
F_2 ( L_1 , V_2 ) ;
F_14 ( V_4 , & V_15 ) ;
F_19 ( V_4 , & V_15 , 1 ) ;
}
static inline int F_21 ( T_2 V_34 , int V_35 )
{
return ( V_35 == V_36 ) ? ( ( V_34 >> 22 ) & 0x1 ) : 1 ;
}
static inline int F_22 ( T_2 V_34 , int V_35 )
{
return ( V_35 == V_36 ) ? ( ( V_34 >> 18 ) & 0x3 ) : 1 ;
}
static void F_23 ( struct V_3 * V_4 , struct V_37 * V_38 ,
int V_35 , T_2 V_34 )
{
unsigned long V_39 ;
int V_40 ;
T_3 V_41 ;
T_2 V_42 , V_43 ;
int V_44 , V_45 , V_46 , V_47 ;
struct V_48 * V_49 ;
F_16 ( V_38 , V_50 , & V_42 ) ;
V_44 = F_21 ( V_34 , V_35 ) ;
V_45 = F_22 ( V_34 , V_35 ) ;
V_46 = ( V_34 >> 20 ) & 0x3 ;
V_39 = 0 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_51 ; V_40 ++ ) {
V_47 = ( V_42 >> ( V_40 * 4 + 3 ) ) & 0x1 ;
V_49 = & V_4 -> V_52 [ V_40 ] ;
F_15 ( V_38 , V_53 + V_40 , & V_41 ) ;
V_43 = V_41 << ( 25 + V_45 - V_54 ) ;
F_2 ( L_7 , V_2 , V_40 ,
V_43 ) ;
if ( V_43 == V_39 )
continue;
V_49 -> V_55 = V_39 ;
V_49 -> V_56 = V_43 - 1 ;
V_49 -> V_57 = V_43 - V_39 ;
V_39 = V_43 ;
V_49 -> V_58 = 1 << 12 ;
V_49 -> V_59 = V_60 ;
V_49 -> V_61 = V_47 ? V_62 : V_63 ;
if ( V_46 ) {
if ( V_44 && V_47 ) {
V_49 -> V_64 = V_65 ;
V_4 -> V_66 |= V_67 ;
} else {
V_49 -> V_64 = V_68 ;
V_4 -> V_66 |= V_69 ;
}
} else
V_49 -> V_64 = V_70 ;
}
}
static int F_24 ( struct V_37 * V_38 , int V_35 )
{
T_1 V_71 ;
struct V_3 * V_4 = NULL ;
struct V_7 * V_8 = NULL ;
T_2 V_34 ;
int V_44 ;
struct V_14 V_72 ;
F_25 ( L_8 , V_2 ) ;
F_16 ( V_38 , V_73 , & V_34 ) ;
V_44 = F_21 ( V_34 , V_35 ) ;
V_4 = F_26 ( sizeof( * V_8 ) , V_74 , V_44 + 1 , 0 ) ;
if ( V_4 == NULL )
return - V_75 ;
F_2 ( L_9 , V_2 ) ;
V_4 -> V_76 = V_77 ;
V_4 -> V_78 = V_79 | V_69 |
V_67 ;
V_4 -> V_80 = V_81 ;
V_4 -> V_82 = V_83 ;
V_4 -> V_84 = & V_38 -> V_84 ;
F_2 ( L_10 , V_2 ) ;
V_8 = (struct V_7 * ) V_4 -> V_9 ;
V_8 -> V_85 = & V_86 [ V_35 ] ;
V_8 -> V_24 = F_27 ( V_87 ,
V_8 -> V_85 -> V_88 , V_8 -> V_24 ) ;
if ( ! V_8 -> V_24 ) {
F_4 ( V_13 , L_11
L_12 ,
V_87 , V_86 [ V_35 ] . V_88 ) ;
goto V_89;
}
F_2 ( L_13 , V_2 ) ;
V_4 -> V_90 = V_8 -> V_85 -> V_90 ;
V_4 -> V_91 = F_28 ( V_38 ) ;
V_4 -> V_92 = F_20 ;
V_4 -> F_3 = F_3 ;
F_23 ( V_4 , V_38 , V_35 , V_34 ) ;
V_4 -> V_66 |= V_79 ;
F_2 ( L_14 , V_2 ) ;
F_17 ( V_38 , V_93 , & V_71 ) ;
V_8 -> V_10 = ( ( T_2 ) V_71 ) << 4 ;
F_17 ( V_38 , V_94 , & V_71 ) ;
V_8 -> V_11 = ( ( T_2 ) V_71 ) << 14 ;
F_17 ( V_38 , V_95 , & V_71 ) ;
V_8 -> V_12 = ( ( T_2 ) V_71 ) << 14 ;
F_4 ( V_96 ,
L_15 , V_8 -> V_10 ,
V_8 -> V_11 , V_8 -> V_12 ) ;
F_14 ( V_4 , & V_72 ) ;
if ( F_29 ( V_4 ) ) {
F_2 ( L_16 , V_2 ) ;
goto V_97;
}
V_98 = F_30 ( & V_38 -> V_84 , V_81 ) ;
if ( ! V_98 ) {
F_31 ( V_99
L_17 ,
V_2 ) ;
F_31 ( V_99
L_18 ,
V_2 ) ;
}
F_2 ( L_19 , V_2 ) ;
return 0 ;
V_97:
F_32 ( V_8 -> V_24 ) ;
V_89:
F_33 ( V_4 ) ;
return - V_100 ;
}
static int T_4 F_34 ( struct V_37 * V_38 ,
const struct V_101 * V_102 )
{
F_25 ( L_1 , V_2 ) ;
return F_35 ( V_38 ) ?
- V_103 : F_24 ( V_38 , V_102 -> V_104 ) ;
}
static void T_5 F_36 ( struct V_37 * V_38 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
F_25 ( L_1 , V_2 ) ;
if ( V_98 )
F_37 ( V_98 ) ;
if ( ( V_4 = F_38 ( & V_38 -> V_84 ) ) == NULL )
return;
V_8 = (struct V_7 * ) V_4 -> V_9 ;
F_32 ( V_8 -> V_24 ) ;
F_33 ( V_4 ) ;
}
static int T_6 F_39 ( void )
{
F_40 () ;
return F_41 ( & V_105 ) ;
}
static void T_7 F_42 ( void )
{
F_43 ( & V_105 ) ;
}
