static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 -> V_7 ) ;
F_3 ( V_6 , V_8 , & V_4 -> V_9 ) ;
if ( ! ( V_4 -> V_9 & 0x0081 ) )
return;
F_4 ( V_6 , V_10 , & V_4 -> V_11 ) ;
F_5 ( V_6 , V_12 , & V_4 -> V_13 ) ;
F_5 ( V_6 , V_14 , & V_4 -> V_15 ) ;
F_3 ( V_6 , V_8 , & V_4 -> V_16 ) ;
if ( ( V_4 -> V_9 ^ V_4 -> V_16 ) & 0x0081 ) {
F_4 ( V_6 , V_10 , & V_4 -> V_11 ) ;
F_5 ( V_6 , V_12 , & V_4 -> V_13 ) ;
F_5 ( V_6 , V_14 , & V_4 -> V_15 ) ;
}
F_6 ( V_6 , V_8 , 0x0081 , 0x0081 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_17 )
{
int V_18 , V_19 ;
V_19 = V_2 -> V_20 [ 0 ] . V_21 - 1 ;
if ( ! ( V_4 -> V_9 & 0x0081 ) )
return 0 ;
if ( ! V_17 )
return 1 ;
if ( ( V_4 -> V_9 ^ V_4 -> V_16 ) & 0x0081 ) {
F_8 ( V_2 , L_1 ) ;
V_4 -> V_9 = V_4 -> V_16 ;
}
V_4 -> V_11 >>= V_22 ;
V_18 = F_9 ( V_2 , V_4 -> V_11 ) ;
if ( V_4 -> V_9 & 0x0080 )
F_10 ( V_2 , V_4 -> V_11 , 0 , V_18 , L_2 ) ;
else
F_11 ( V_2 , V_4 -> V_11 , 0 , V_4 -> V_15 , V_18 ,
V_19 ? ( V_4 -> V_13 & 0x1 ) : 0 ,
L_3 ) ;
return 1 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_13 ( L_4 , V_2 -> V_23 , V_24 ) ;
F_1 ( V_2 , & V_4 ) ;
F_7 ( V_2 , & V_4 , 1 ) ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_5 * * V_25 ,
void T_1 * * V_26 )
{
struct V_5 * V_7 ;
void T_1 * V_27 ;
int V_28 ;
* V_25 = NULL ;
* V_26 = NULL ;
V_7 = F_15 ( F_16 ( V_29 , 82875_6 ) , NULL ) ;
if ( V_7 == NULL ) {
F_17 ( V_6 , 0xf4 , 0x2 , 0x2 ) ;
V_7 = F_18 ( V_6 -> V_30 , F_19 ( 6 , 0 ) ) ;
if ( V_7 == NULL )
return 1 ;
V_28 = F_20 ( V_7 ) ;
if ( V_28 ) {
F_21 ( V_31 ,
L_5 ,
V_24 ) ;
}
F_22 ( V_7 -> V_30 ) ;
}
* V_25 = V_7 ;
if ( F_23 ( V_7 ) ) {
F_21 ( V_31 , L_6
L_7 , V_24 ) ;
return 1 ;
}
if ( F_24 ( V_7 , F_25 ( V_7 ) ) ) {
#ifdef F_26
goto V_32;
#endif
}
V_27 = F_27 ( V_7 , 0 ) ;
if ( V_27 == NULL ) {
F_21 ( V_31 , L_8 ,
V_24 ) ;
goto V_33;
}
* V_26 = V_27 ;
return 0 ;
V_33:
F_28 ( V_7 ) ;
#ifdef F_26
V_32:
F_29 ( V_7 ) ;
#endif
return 1 ;
}
static inline int F_30 ( T_2 V_34 )
{
return ( V_34 >> 21 ) & 0x1 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
void T_1 * V_26 , T_2 V_34 )
{
struct V_35 * V_36 ;
unsigned long V_37 ;
T_3 V_38 ;
T_2 V_39 ;
T_2 V_40 ;
int V_41 ;
V_39 = ( V_34 >> 18 ) & 0x1 ;
V_37 = 0 ;
for ( V_41 = 0 ; V_41 < V_2 -> V_42 ; V_41 ++ ) {
V_36 = & V_2 -> V_20 [ V_41 ] ;
V_38 = F_32 ( V_26 + V_43 + V_41 ) ;
V_40 = V_38 << ( V_44 - V_22 ) ;
F_33 ( L_9 , V_24 , V_41 ,
V_40 ) ;
if ( V_40 == V_37 )
continue;
V_36 -> V_45 = V_37 ;
V_36 -> V_46 = V_40 - 1 ;
V_36 -> V_47 = V_40 - V_37 ;
V_37 = V_40 ;
V_36 -> V_48 = 1 << 12 ;
V_36 -> V_49 = V_50 ;
V_36 -> V_51 = V_52 ;
V_36 -> V_53 = V_39 ? V_54 : V_55 ;
}
}
static int F_34 ( struct V_5 * V_6 , int V_56 )
{
int V_57 = - V_58 ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_5 * V_25 ;
void T_1 * V_26 ;
T_2 V_34 ;
T_2 V_61 ;
struct V_3 V_62 ;
F_35 ( L_10 , V_24 ) ;
V_25 = F_15 ( F_16 ( V_29 , 82875_6 ) , NULL ) ;
if ( F_14 ( V_6 , & V_25 , & V_26 ) )
return - V_58 ;
V_34 = F_36 ( V_26 + V_63 ) ;
V_61 = F_30 ( V_34 ) + 1 ;
V_2 = F_37 ( sizeof( * V_60 ) , F_38 ( V_61 ) ,
V_61 , 0 ) ;
if ( ! V_2 ) {
V_57 = - V_64 ;
goto V_32;
}
F_39 ( & V_2 -> V_65 ) ;
F_33 ( L_11 , V_24 ) ;
V_2 -> V_7 = & V_6 -> V_7 ;
V_2 -> V_66 = V_67 ;
V_2 -> V_68 = V_69 | V_70 ;
V_2 -> V_71 = V_72 ;
V_2 -> V_73 = V_74 ;
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = V_78 [ V_56 ] . V_77 ;
V_2 -> V_79 = F_25 ( V_6 ) ;
V_2 -> V_80 = F_12 ;
V_2 -> V_81 = NULL ;
F_33 ( L_12 , V_24 ) ;
V_60 = (struct V_59 * ) V_2 -> V_82 ;
V_60 -> V_25 = V_25 ;
V_60 -> V_26 = V_26 ;
F_31 ( V_2 , V_6 , V_26 , V_34 ) ;
F_1 ( V_2 , & V_62 ) ;
if ( F_40 ( V_2 ) ) {
F_33 ( L_13 , V_24 ) ;
goto V_33;
}
V_83 = F_41 ( & V_6 -> V_7 , V_74 ) ;
if ( ! V_83 ) {
F_42 ( V_84
L_14 ,
V_24 ) ;
F_42 ( V_84
L_15 ,
V_24 ) ;
}
F_33 ( L_16 , V_24 ) ;
return 0 ;
V_33:
F_43 ( & V_2 -> V_65 ) ;
F_44 ( V_2 ) ;
V_32:
F_45 ( V_26 ) ;
F_28 ( V_25 ) ;
F_29 ( V_25 ) ;
return V_57 ;
}
static int T_4 F_46 ( struct V_5 * V_6 ,
const struct V_85 * V_86 )
{
int V_57 ;
F_35 ( L_10 , V_24 ) ;
F_21 ( V_87 , L_17 ) ;
if ( F_23 ( V_6 ) < 0 )
return - V_88 ;
V_57 = F_34 ( V_6 , V_86 -> V_89 ) ;
if ( V_90 == NULL )
V_90 = F_47 ( V_6 ) ;
return V_57 ;
}
static void T_5 F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_59 * V_60 = NULL ;
F_35 ( L_10 , V_24 ) ;
if ( V_83 )
F_49 ( V_83 ) ;
if ( ( V_2 = F_50 ( & V_6 -> V_7 ) ) == NULL )
return;
V_60 = (struct V_59 * ) V_2 -> V_82 ;
if ( V_60 -> V_26 )
F_45 ( V_60 -> V_26 ) ;
if ( V_60 -> V_25 ) {
#ifdef F_26
F_28 ( V_60 -> V_25 ) ;
#endif
F_29 ( V_60 -> V_25 ) ;
F_51 ( V_60 -> V_25 ) ;
}
F_44 ( V_2 ) ;
}
static int T_6 F_52 ( void )
{
int V_91 ;
F_33 ( L_10 , V_24 ) ;
F_53 () ;
V_91 = F_54 ( & V_92 ) ;
if ( V_91 < 0 )
goto V_32;
if ( V_90 == NULL ) {
V_90 = F_15 ( V_93 ,
V_94 , NULL ) ;
if ( ! V_90 ) {
F_35 ( L_18 ) ;
V_91 = - V_58 ;
goto V_33;
}
V_91 = F_46 ( V_90 , V_95 ) ;
if ( V_91 < 0 ) {
F_35 ( L_19 ) ;
V_91 = - V_58 ;
goto V_33;
}
}
return 0 ;
V_33:
F_55 ( & V_92 ) ;
V_32:
if ( V_90 != NULL )
F_51 ( V_90 ) ;
return V_91 ;
}
static void T_7 F_56 ( void )
{
F_33 ( L_10 , V_24 ) ;
F_48 ( V_90 ) ;
F_51 ( V_90 ) ;
F_55 ( & V_92 ) ;
}
