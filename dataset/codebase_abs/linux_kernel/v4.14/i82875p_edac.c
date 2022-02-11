static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 -> V_6 ) ;
F_3 ( V_6 , V_7 , & V_4 -> V_8 ) ;
if ( ! ( V_4 -> V_8 & 0x0081 ) )
return;
F_4 ( V_6 , V_9 , & V_4 -> V_10 ) ;
F_5 ( V_6 , V_11 , & V_4 -> V_12 ) ;
F_5 ( V_6 , V_13 , & V_4 -> V_14 ) ;
F_3 ( V_6 , V_7 , & V_4 -> V_15 ) ;
if ( ( V_4 -> V_8 ^ V_4 -> V_15 ) & 0x0081 ) {
F_4 ( V_6 , V_9 , & V_4 -> V_10 ) ;
F_5 ( V_6 , V_11 , & V_4 -> V_12 ) ;
F_5 ( V_6 , V_13 , & V_4 -> V_14 ) ;
}
F_6 ( V_6 , V_7 , 0x0081 , 0x0081 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_16 )
{
int V_17 , V_18 ;
V_18 = V_2 -> V_19 [ 0 ] -> V_20 - 1 ;
if ( ! ( V_4 -> V_8 & 0x0081 ) )
return 0 ;
if ( ! V_16 )
return 1 ;
if ( ( V_4 -> V_8 ^ V_4 -> V_15 ) & 0x0081 ) {
F_8 ( V_21 , V_2 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
L_1 , L_2 ) ;
V_4 -> V_8 = V_4 -> V_15 ;
}
V_4 -> V_10 >>= V_22 ;
V_17 = F_9 ( V_2 , V_4 -> V_10 ) ;
if ( V_4 -> V_8 & 0x0080 )
F_8 ( V_21 , V_2 , 1 ,
V_4 -> V_10 , 0 , 0 ,
V_17 , - 1 , - 1 ,
L_3 , L_2 ) ;
else
F_8 ( V_23 , V_2 , 1 ,
V_4 -> V_10 , 0 , V_4 -> V_14 ,
V_17 , V_18 ? ( V_4 -> V_12 & 0x1 ) : 0 ,
- 1 , L_4 , L_2 ) ;
return 1 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_11 ( 1 , L_5 , V_2 -> V_24 ) ;
F_1 ( V_2 , & V_4 ) ;
F_7 ( V_2 , & V_4 , 1 ) ;
}
static int F_12 ( struct V_5 * V_6 ,
struct V_5 * * V_25 ,
void T_1 * * V_26 )
{
struct V_5 * V_27 ;
void T_1 * V_28 ;
* V_25 = NULL ;
* V_26 = NULL ;
V_27 = F_13 ( F_14 ( V_29 , 82875_6 ) , NULL ) ;
if ( V_27 == NULL ) {
F_15 ( V_6 , 0xf4 , 0x2 , 0x2 ) ;
V_27 = F_16 ( V_6 -> V_30 , F_17 ( 6 , 0 ) ) ;
if ( V_27 == NULL )
return 1 ;
F_18 ( V_27 -> V_30 ) ;
F_19 ( V_27 ) ;
}
* V_25 = V_27 ;
if ( F_20 ( V_27 ) ) {
F_21 ( V_31 , L_6
L_7 , V_32 ) ;
return 1 ;
}
if ( F_22 ( V_27 , F_23 ( V_27 ) ) ) {
#ifdef F_24
goto V_33;
#endif
}
V_28 = F_25 ( V_27 , 0 ) ;
if ( V_28 == NULL ) {
F_21 ( V_31 , L_8 ,
V_32 ) ;
goto V_34;
}
* V_26 = V_28 ;
return 0 ;
V_34:
F_26 ( V_27 ) ;
#ifdef F_24
V_33:
F_27 ( V_27 ) ;
#endif
return 1 ;
}
static inline int F_28 ( T_2 V_35 )
{
return ( V_35 >> 21 ) & 0x1 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
void T_1 * V_26 , T_2 V_35 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
unsigned V_40 = F_28 ( V_35 ) + 1 ;
unsigned long V_41 ;
T_3 V_42 ;
T_2 V_43 ;
T_2 V_44 , V_45 ;
int V_46 , V_47 ;
V_43 = ( V_35 >> 18 ) & 0x1 ;
V_41 = 0 ;
for ( V_46 = 0 ; V_46 < V_2 -> V_48 ; V_46 ++ ) {
V_37 = V_2 -> V_19 [ V_46 ] ;
V_42 = F_30 ( V_26 + V_49 + V_46 ) ;
V_44 = V_42 << ( V_50 - V_22 ) ;
F_11 ( 3 , L_9 , V_46 , V_44 ) ;
if ( V_44 == V_41 )
continue;
V_37 -> V_51 = V_41 ;
V_37 -> V_52 = V_44 - 1 ;
V_45 = V_44 - V_41 ;
V_41 = V_44 ;
for ( V_47 = 0 ; V_47 < V_40 ; V_47 ++ ) {
V_39 = V_37 -> V_53 [ V_47 ] -> V_39 ;
V_39 -> V_45 = V_45 / V_40 ;
V_39 -> V_54 = 1 << 12 ;
V_39 -> V_55 = V_56 ;
V_39 -> V_57 = V_58 ;
V_39 -> V_59 = V_43 ? V_60 : V_61 ;
}
}
}
static int F_31 ( struct V_5 * V_6 , int V_62 )
{
int V_63 = - V_64 ;
struct V_1 * V_2 ;
struct V_65 V_66 [ 2 ] ;
struct V_67 * V_68 ;
struct V_5 * V_25 ;
void T_1 * V_26 ;
T_2 V_35 ;
T_2 V_40 ;
struct V_3 V_69 ;
F_11 ( 0 , L_10 ) ;
if ( F_12 ( V_6 , & V_25 , & V_26 ) )
return - V_64 ;
V_35 = F_32 ( V_26 + V_70 ) ;
V_40 = F_28 ( V_35 ) + 1 ;
V_66 [ 0 ] . type = V_71 ;
V_66 [ 0 ] . V_72 = F_33 ( V_40 ) ;
V_66 [ 0 ] . V_73 = true ;
V_66 [ 1 ] . type = V_74 ;
V_66 [ 1 ] . V_72 = V_40 ;
V_66 [ 1 ] . V_73 = false ;
V_2 = F_34 ( 0 , F_35 ( V_66 ) , V_66 , sizeof( * V_68 ) ) ;
if ( ! V_2 ) {
V_63 = - V_75 ;
goto V_33;
}
F_11 ( 3 , L_11 ) ;
V_2 -> V_6 = & V_6 -> V_27 ;
V_2 -> V_76 = V_77 ;
V_2 -> V_78 = V_79 | V_80 ;
V_2 -> V_81 = V_82 ;
V_2 -> V_83 = V_84 ;
V_2 -> V_85 = V_86 [ V_62 ] . V_85 ;
V_2 -> V_87 = F_23 ( V_6 ) ;
V_2 -> V_88 = F_10 ;
V_2 -> V_89 = NULL ;
F_11 ( 3 , L_12 ) ;
V_68 = (struct V_67 * ) V_2 -> V_90 ;
V_68 -> V_25 = V_25 ;
V_68 -> V_26 = V_26 ;
F_29 ( V_2 , V_6 , V_26 , V_35 ) ;
F_1 ( V_2 , & V_69 ) ;
if ( F_36 ( V_2 ) ) {
F_11 ( 3 , L_13 ) ;
goto V_34;
}
V_91 = F_37 ( & V_6 -> V_27 , V_84 ) ;
if ( ! V_91 ) {
F_38 ( V_92
L_14 ,
V_32 ) ;
F_38 ( V_92
L_15 ,
V_32 ) ;
}
F_11 ( 3 , L_16 ) ;
return 0 ;
V_34:
F_39 ( V_2 ) ;
V_33:
F_40 ( V_26 ) ;
F_26 ( V_25 ) ;
F_27 ( V_25 ) ;
return V_63 ;
}
static int F_41 ( struct V_5 * V_6 ,
const struct V_93 * V_94 )
{
int V_63 ;
F_11 ( 0 , L_10 ) ;
F_21 ( V_95 , L_17 ) ;
if ( F_20 ( V_6 ) < 0 )
return - V_96 ;
V_63 = F_31 ( V_6 , V_94 -> V_97 ) ;
if ( V_98 == NULL )
V_98 = F_42 ( V_6 ) ;
return V_63 ;
}
static void F_43 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_67 * V_68 = NULL ;
F_11 ( 0 , L_10 ) ;
if ( V_91 )
F_44 ( V_91 ) ;
if ( ( V_2 = F_45 ( & V_6 -> V_27 ) ) == NULL )
return;
V_68 = (struct V_67 * ) V_2 -> V_90 ;
if ( V_68 -> V_26 )
F_40 ( V_68 -> V_26 ) ;
if ( V_68 -> V_25 ) {
#ifdef F_24
F_26 ( V_68 -> V_25 ) ;
#endif
F_27 ( V_68 -> V_25 ) ;
F_46 ( V_68 -> V_25 ) ;
}
F_39 ( V_2 ) ;
}
static int T_4 F_47 ( void )
{
int V_99 ;
F_11 ( 3 , L_10 ) ;
F_48 () ;
V_99 = F_49 ( & V_100 ) ;
if ( V_99 < 0 )
goto V_33;
if ( V_98 == NULL ) {
V_98 = F_13 ( V_101 ,
V_102 , NULL ) ;
if ( ! V_98 ) {
F_11 ( 0 , L_18 ) ;
V_99 = - V_64 ;
goto V_34;
}
V_99 = F_41 ( V_98 , V_103 ) ;
if ( V_99 < 0 ) {
F_11 ( 0 , L_19 ) ;
V_99 = - V_64 ;
goto V_34;
}
}
return 0 ;
V_34:
F_50 ( & V_100 ) ;
V_33:
F_46 ( V_98 ) ;
return V_99 ;
}
static void T_5 F_51 ( void )
{
F_11 ( 3 , L_10 ) ;
F_43 ( V_98 ) ;
F_46 ( V_98 ) ;
F_50 ( & V_100 ) ;
}
