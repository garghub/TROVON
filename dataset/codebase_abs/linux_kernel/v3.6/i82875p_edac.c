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
int V_29 ;
* V_25 = NULL ;
* V_26 = NULL ;
V_27 = F_13 ( F_14 ( V_30 , 82875_6 ) , NULL ) ;
if ( V_27 == NULL ) {
F_15 ( V_6 , 0xf4 , 0x2 , 0x2 ) ;
V_27 = F_16 ( V_6 -> V_31 , F_17 ( 6 , 0 ) ) ;
if ( V_27 == NULL )
return 1 ;
V_29 = F_18 ( V_27 ) ;
if ( V_29 ) {
F_19 ( V_32 ,
L_6 ,
V_33 ) ;
}
F_20 ( V_27 -> V_31 ) ;
}
* V_25 = V_27 ;
if ( F_21 ( V_27 ) ) {
F_19 ( V_32 , L_7
L_8 , V_33 ) ;
return 1 ;
}
if ( F_22 ( V_27 , F_23 ( V_27 ) ) ) {
#ifdef F_24
goto V_34;
#endif
}
V_28 = F_25 ( V_27 , 0 ) ;
if ( V_28 == NULL ) {
F_19 ( V_32 , L_9 ,
V_33 ) ;
goto V_35;
}
* V_26 = V_28 ;
return 0 ;
V_35:
F_26 ( V_27 ) ;
#ifdef F_24
V_34:
F_27 ( V_27 ) ;
#endif
return 1 ;
}
static inline int F_28 ( T_2 V_36 )
{
return ( V_36 >> 21 ) & 0x1 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
void T_1 * V_26 , T_2 V_36 )
{
struct V_37 * V_38 ;
struct V_39 * V_40 ;
unsigned V_41 = F_28 ( V_36 ) + 1 ;
unsigned long V_42 ;
T_3 V_43 ;
T_2 V_44 ;
T_2 V_45 , V_46 ;
int V_47 , V_48 ;
V_44 = ( V_36 >> 18 ) & 0x1 ;
V_42 = 0 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_49 ; V_47 ++ ) {
V_38 = V_2 -> V_19 [ V_47 ] ;
V_43 = F_30 ( V_26 + V_50 + V_47 ) ;
V_45 = V_43 << ( V_51 - V_22 ) ;
F_11 ( 3 , L_10 , V_47 , V_45 ) ;
if ( V_45 == V_42 )
continue;
V_38 -> V_52 = V_42 ;
V_38 -> V_53 = V_45 - 1 ;
V_46 = V_45 - V_42 ;
V_42 = V_45 ;
for ( V_48 = 0 ; V_48 < V_41 ; V_48 ++ ) {
V_40 = V_38 -> V_54 [ V_48 ] -> V_40 ;
V_40 -> V_46 = V_46 / V_41 ;
V_40 -> V_55 = 1 << 12 ;
V_40 -> V_56 = V_57 ;
V_40 -> V_58 = V_59 ;
V_40 -> V_60 = V_44 ? V_61 : V_62 ;
}
}
}
static int F_31 ( struct V_5 * V_6 , int V_63 )
{
int V_64 = - V_65 ;
struct V_1 * V_2 ;
struct V_66 V_67 [ 2 ] ;
struct V_68 * V_69 ;
struct V_5 * V_25 ;
void T_1 * V_26 ;
T_2 V_36 ;
T_2 V_41 ;
struct V_3 V_70 ;
F_11 ( 0 , L_11 ) ;
V_25 = F_13 ( F_14 ( V_30 , 82875_6 ) , NULL ) ;
if ( F_12 ( V_6 , & V_25 , & V_26 ) )
return - V_65 ;
V_36 = F_32 ( V_26 + V_71 ) ;
V_41 = F_28 ( V_36 ) + 1 ;
V_67 [ 0 ] . type = V_72 ;
V_67 [ 0 ] . V_73 = F_33 ( V_41 ) ;
V_67 [ 0 ] . V_74 = true ;
V_67 [ 1 ] . type = V_75 ;
V_67 [ 1 ] . V_73 = V_41 ;
V_67 [ 1 ] . V_74 = false ;
V_2 = F_34 ( 0 , F_35 ( V_67 ) , V_67 , sizeof( * V_69 ) ) ;
if ( ! V_2 ) {
V_64 = - V_76 ;
goto V_34;
}
F_11 ( 3 , L_12 ) ;
V_2 -> V_6 = & V_6 -> V_27 ;
V_2 -> V_77 = V_78 ;
V_2 -> V_79 = V_80 | V_81 ;
V_2 -> V_82 = V_83 ;
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_88 = V_89 [ V_63 ] . V_88 ;
V_2 -> V_90 = F_23 ( V_6 ) ;
V_2 -> V_91 = F_10 ;
V_2 -> V_92 = NULL ;
F_11 ( 3 , L_13 ) ;
V_69 = (struct V_68 * ) V_2 -> V_93 ;
V_69 -> V_25 = V_25 ;
V_69 -> V_26 = V_26 ;
F_29 ( V_2 , V_6 , V_26 , V_36 ) ;
F_1 ( V_2 , & V_70 ) ;
if ( F_36 ( V_2 ) ) {
F_11 ( 3 , L_14 ) ;
goto V_35;
}
V_94 = F_37 ( & V_6 -> V_27 , V_85 ) ;
if ( ! V_94 ) {
F_38 ( V_95
L_15 ,
V_33 ) ;
F_38 ( V_95
L_16 ,
V_33 ) ;
}
F_11 ( 3 , L_17 ) ;
return 0 ;
V_35:
F_39 ( V_2 ) ;
V_34:
F_40 ( V_26 ) ;
F_26 ( V_25 ) ;
F_27 ( V_25 ) ;
return V_64 ;
}
static int T_4 F_41 ( struct V_5 * V_6 ,
const struct V_96 * V_97 )
{
int V_64 ;
F_11 ( 0 , L_11 ) ;
F_19 ( V_98 , L_18 ) ;
if ( F_21 ( V_6 ) < 0 )
return - V_99 ;
V_64 = F_31 ( V_6 , V_97 -> V_100 ) ;
if ( V_101 == NULL )
V_101 = F_42 ( V_6 ) ;
return V_64 ;
}
static void T_5 F_43 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_68 * V_69 = NULL ;
F_11 ( 0 , L_11 ) ;
if ( V_94 )
F_44 ( V_94 ) ;
if ( ( V_2 = F_45 ( & V_6 -> V_27 ) ) == NULL )
return;
V_69 = (struct V_68 * ) V_2 -> V_93 ;
if ( V_69 -> V_26 )
F_40 ( V_69 -> V_26 ) ;
if ( V_69 -> V_25 ) {
#ifdef F_24
F_26 ( V_69 -> V_25 ) ;
#endif
F_27 ( V_69 -> V_25 ) ;
F_46 ( V_69 -> V_25 ) ;
}
F_39 ( V_2 ) ;
}
static int T_6 F_47 ( void )
{
int V_102 ;
F_11 ( 3 , L_11 ) ;
F_48 () ;
V_102 = F_49 ( & V_103 ) ;
if ( V_102 < 0 )
goto V_34;
if ( V_101 == NULL ) {
V_101 = F_13 ( V_104 ,
V_105 , NULL ) ;
if ( ! V_101 ) {
F_11 ( 0 , L_19 ) ;
V_102 = - V_65 ;
goto V_35;
}
V_102 = F_41 ( V_101 , V_106 ) ;
if ( V_102 < 0 ) {
F_11 ( 0 , L_20 ) ;
V_102 = - V_65 ;
goto V_35;
}
}
return 0 ;
V_35:
F_50 ( & V_103 ) ;
V_34:
if ( V_101 != NULL )
F_46 ( V_101 ) ;
return V_102 ;
}
static void T_7 F_51 ( void )
{
F_11 ( 3 , L_11 ) ;
F_43 ( V_101 ) ;
F_46 ( V_101 ) ;
F_50 ( & V_103 ) ;
}
