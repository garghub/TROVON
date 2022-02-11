static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 , V_5 ;
bool V_6 = F_2 ( V_7 -> F_2 ) == V_8 ;
F_3 (i) {
struct V_9 * V_10 = & F_4 ( V_11 , V_4 ) ;
T_1 V_12 = V_10 -> V_13 ;
F_5 ( V_2 , L_1 , V_4 ) ;
if ( V_6 )
F_5 ( V_2 , L_2 ,
F_6 ( V_12 ) , V_14 ) ;
F_5 ( V_2 , L_3 ,
V_15 / ( 500000UL / V_16 ) ,
V_15 / ( 5000UL / V_16 ) % 100 ) ;
F_7 ( V_2 , L_4 ) ;
if ( V_6 ) {
#ifdef F_8
for ( V_5 = 0 ; V_17 [ V_5 ] ; V_5 ++ )
if ( V_18 & ( 1 << V_5 ) )
F_5 ( V_2 , L_5 , V_17 [ V_5 ] ) ;
for ( V_5 = 0 ; V_19 [ V_5 ] ; V_5 ++ )
if ( V_20 & ( 1 << V_5 ) )
F_5 ( V_2 , L_5 , V_19 [ V_5 ] ) ;
#endif
} else {
for ( V_5 = 0 ; V_21 [ V_5 ] ; V_5 ++ )
if ( V_22 & ( 1 << V_5 ) )
F_5 ( V_2 , L_5 , V_21 [ V_5 ] ) ;
}
F_7 ( V_2 , L_6 ) ;
F_5 ( V_2 , L_7 ,
F_9 ( V_12 ) ) ;
F_5 ( V_2 , L_8 ) ;
F_5 ( V_2 , L_9 , F_10 ( V_12 ) ) ;
F_5 ( V_2 , L_10 , F_11 ( V_12 ) ) ;
F_5 ( V_2 , L_11 , F_6 ( V_12 ) ) ;
}
return 0 ;
}
static void * F_12 ( struct V_1 * V_2 , T_2 * V_23 )
{
return * V_23 < 1 ? ( void * ) 1 : NULL ;
}
static void * F_13 ( struct V_1 * V_2 , void * V_3 , T_2 * V_23 )
{
++ * V_23 ;
return NULL ;
}
static void F_14 ( struct V_1 * V_2 , void * V_3 )
{
}
static int F_15 ( unsigned int V_24 )
{
int V_25 ;
struct V_26 * V_27 ;
struct V_9 * V_28 = & F_4 ( V_11 , V_24 ) ;
V_27 = F_16 ( V_24 ) ;
if ( ! V_27 ) {
V_25 = - V_29 ;
goto V_30;
}
V_25 = F_17 ( & V_28 -> V_31 , & V_27 -> V_31 , L_12 ) ;
if ( V_25 )
goto V_30;
V_25 = F_18 ( & V_28 -> V_31 , & V_32 ) ;
if ( V_25 )
F_19 ( & V_28 -> V_31 ) ;
V_30:
return V_25 ;
}
static int F_20 ( unsigned int V_24 )
{
struct V_26 * V_27 ;
struct V_9 * V_28 = & F_4 ( V_11 , V_24 ) ;
V_27 = F_16 ( V_24 ) ;
if ( ! V_27 )
return - V_29 ;
if ( V_28 -> V_31 . V_33 ) {
F_21 ( & V_28 -> V_31 , & V_32 ) ;
F_19 ( & V_28 -> V_31 ) ;
}
return 0 ;
}
static int T_3 F_22 ( void )
{
int V_24 , V_34 ;
F_23 (cpu) {
struct V_9 * V_28 = & F_4 ( V_11 , V_24 ) ;
F_24 ( & V_28 -> V_31 , & V_35 ) ;
}
V_34 = F_25 ( V_36 , L_13 ,
F_15 , F_20 ) ;
if ( V_34 < 0 ) {
F_26 ( L_14 ) ;
return V_34 ;
}
return 0 ;
}
static void F_27 ( struct V_9 * V_28 )
{
unsigned int V_24 = F_28 () ;
T_1 V_37 = F_29 ( V_28 -> V_38 ) ;
switch ( V_37 ) {
case V_39 :
break;
case V_40 :
F_30 ( V_41 , & V_42 ) ;
break;
default:
case V_43 :
F_30 ( V_44 , & V_42 ) ;
}
F_31 ( L_15 , V_45 [ V_37 ] , V_24 ) ;
}
static void F_32 ( struct V_9 * V_28 )
{
V_28 -> V_46 = F_33 () ;
V_28 -> V_38 = F_34 () ;
V_28 -> V_47 = F_35 ( V_48 ) ;
V_28 -> V_13 = F_36 () ;
V_28 -> V_49 = F_35 ( V_50 ) ;
V_28 -> V_51 = F_35 ( V_52 ) ;
V_28 -> V_53 = F_35 ( V_54 ) ;
V_28 -> V_55 = F_35 ( V_56 ) ;
V_28 -> V_57 = F_35 ( V_58 ) ;
V_28 -> V_59 = F_35 ( V_60 ) ;
V_28 -> V_61 = F_35 ( V_62 ) ;
V_28 -> V_63 = F_35 ( V_64 ) ;
V_28 -> V_65 = F_35 ( V_66 ) ;
V_28 -> V_67 = F_35 ( V_68 ) ;
if ( F_37 ( V_28 -> V_65 ) ) {
V_28 -> V_69 = F_35 ( V_70 ) ;
V_28 -> V_71 = F_35 ( V_72 ) ;
V_28 -> V_73 = F_35 ( V_74 ) ;
V_28 -> V_75 = F_35 ( V_76 ) ;
V_28 -> V_77 = F_35 ( V_78 ) ;
V_28 -> V_79 = F_35 ( V_80 ) ;
V_28 -> V_81 = F_35 ( V_82 ) ;
V_28 -> V_83 = F_35 ( V_84 ) ;
V_28 -> V_85 = F_35 ( V_86 ) ;
V_28 -> V_87 = F_35 ( V_88 ) ;
V_28 -> V_89 = F_35 ( V_90 ) ;
V_28 -> V_91 = F_35 ( V_92 ) ;
V_28 -> V_93 = F_35 ( V_94 ) ;
V_28 -> V_95 = F_35 ( V_96 ) ;
V_28 -> V_97 = F_35 ( V_98 ) ;
V_28 -> V_99 = F_35 ( V_100 ) ;
}
F_27 ( V_28 ) ;
}
void F_38 ( void )
{
struct V_9 * V_28 = F_39 ( & V_11 ) ;
F_32 ( V_28 ) ;
F_40 ( F_28 () , V_28 , & V_101 ) ;
}
void T_3 F_41 ( void )
{
struct V_9 * V_28 = & F_4 ( V_11 , 0 ) ;
F_32 ( V_28 ) ;
V_101 = * V_28 ;
F_42 ( & V_101 ) ;
}
