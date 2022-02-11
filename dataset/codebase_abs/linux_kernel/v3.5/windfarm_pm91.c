static void F_1 ( void )
{
struct V_1 V_2 ;
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_9 , V_10 , V_11 , V_12 ;
V_4 = F_2 ( V_13 , NULL ) ;
if ( V_4 == 0 ) {
F_3 ( V_14 L_1
L_2 ) ;
goto V_15;
}
V_6 = (struct V_5 * ) & V_4 [ 1 ] ;
V_4 = F_2 ( V_16 , NULL ) ;
if ( V_4 ) {
V_8 = (struct V_7 * ) & V_4 [ 1 ] ;
V_9 = ( ( T_1 ) V_8 -> V_17 ) << 16 ;
} else
V_9 = 0x5e0000 ;
V_18 = F_4 ( sizeof( struct V_19 ) ,
V_20 ) ;
if ( V_18 == NULL )
goto V_15;
V_18 -> V_21 = 1 ;
V_2 . V_22 = V_23 ;
V_2 . V_24 = V_6 -> V_24 ;
if ( V_2 . V_24 > V_25 ) {
F_3 ( V_14 L_3
L_4 , V_6 -> V_24 ) ;
V_2 . V_24 = V_25 ;
}
V_2 . V_26 = V_6 -> V_26 ;
V_2 . V_27 = V_6 -> V_27 ;
V_2 . V_28 = V_6 -> V_28 / V_2 . V_24 ;
V_10 = ( ( T_1 ) V_6 -> V_29 ) << 16 ;
V_11 = ( ( T_1 ) V_6 -> V_30 ) << 16 ;
V_12 = ( ( T_1 ) V_6 -> V_31 ) << 16 ;
V_2 . V_9 = V_9 ;
V_2 . V_32 = V_9 - V_10 ;
V_2 . V_33 = V_11 - V_12 ;
V_2 . V_34 = F_5 ( V_35 ) ;
V_2 . V_36 = F_6 ( V_35 ) ;
F_7 ( & V_18 -> V_37 , & V_2 ) ;
F_8 ( L_5 ) ;
F_8 ( L_6 ,
F_9 ( V_2 . V_32 ) , F_9 ( V_2 . V_9 ) ,
V_2 . V_34 , V_2 . V_36 ) ;
return;
V_15:
F_3 ( V_14 L_7
L_8 ) ;
if ( V_38 )
F_10 ( V_38 ) ;
if ( V_35 )
F_10 ( V_35 ) ;
}
static void F_11 ( struct V_19 * V_39 )
{
T_1 V_40 , V_41 , V_42 ;
int V_43 ;
if ( -- V_39 -> V_21 != 0 ) {
if ( V_44 )
goto V_45;
return;
}
V_39 -> V_21 = V_23 ;
V_43 = F_12 ( V_46 , & V_41 ) ;
if ( V_43 ) {
F_3 ( V_14 L_9 ,
V_43 ) ;
V_47 |= V_48 ;
return;
}
V_43 = F_12 ( V_49 , & V_42 ) ;
if ( V_43 ) {
F_3 ( V_14 L_10 ,
V_43 ) ;
V_47 |= V_48 ;
return;
}
F_8 ( L_11 ,
F_9 ( V_41 ) , F_9 ( V_42 ) ) ;
#ifdef F_13
if ( V_41 > 0x4a0000 )
V_47 |= V_50 ;
#else
if ( V_41 > V_39 -> V_37 . V_51 . V_9 )
V_47 |= V_50 ;
#endif
V_40 = F_14 ( & V_39 -> V_37 , V_42 , V_41 ) ;
F_8 ( L_12 , ( int ) V_40 ) ;
if ( V_39 -> V_52 == V_40 )
return;
V_39 -> V_52 = V_40 ;
V_45:
if ( V_35 && V_47 == 0 ) {
V_43 = F_15 ( V_35 , V_39 -> V_52 ) ;
if ( V_43 ) {
F_3 ( V_14 L_13
L_14 , V_43 ) ;
V_47 |= V_53 ;
}
}
if ( V_54 && V_47 == 0 ) {
V_43 = F_15 ( V_54 , V_39 -> V_52 ) ;
if ( V_43 ) {
F_3 ( V_14 L_15
L_14 , V_43 ) ;
V_47 |= V_53 ;
}
}
if ( V_55 && V_47 == 0 ) {
V_43 = F_15 ( V_55 , V_39 -> V_52 ) ;
if ( V_43 ) {
F_3 ( V_14 L_16
L_14 , V_43 ) ;
V_47 |= V_53 ;
}
}
}
static void F_16 ( void )
{
struct V_56 V_51 = {
. V_22 = 5 ,
. V_24 = 2 ,
. V_26 = 0x01e00000 ,
. V_27 = 0x00500000 ,
. V_28 = 0x00000000 ,
. V_57 = 0x00200000 ,
} ;
V_58 = F_4 ( sizeof( struct V_59 ) ,
V_20 ) ;
if ( V_58 == NULL ) {
F_3 ( V_14 L_17
L_18 ) ;
goto V_15;
}
V_58 -> V_21 = 1 ;
V_51 . V_60 = ( V_61 -> type == V_62 ) ;
V_51 . V_34 = F_5 ( V_61 ) ;
V_51 . V_36 = F_6 ( V_61 ) ;
F_17 ( & V_58 -> V_37 , & V_51 ) ;
F_8 ( L_19 ) ;
F_8 ( L_20 ,
F_9 ( V_51 . V_57 ) , V_51 . V_34 , V_51 . V_36 ) ;
return;
V_15:
if ( V_61 )
F_10 ( V_61 ) ;
}
static void F_18 ( struct V_59 * V_39 )
{
T_1 V_40 , V_41 ;
int V_43 ;
if ( -- V_39 -> V_21 != 0 ) {
if ( V_44 )
goto V_45;
return;
}
V_39 -> V_21 = V_39 -> V_37 . V_51 . V_22 ;
V_43 = F_12 ( V_63 , & V_41 ) ;
if ( V_43 ) {
F_3 ( V_14 L_21 ,
V_43 ) ;
V_47 |= V_48 ;
return;
}
F_8 ( L_22 ,
F_9 ( V_41 ) ) ;
if ( V_41 > ( V_39 -> V_37 . V_51 . V_57 + 0x50000 ) )
V_47 |= V_50 ;
V_40 = F_19 ( & V_39 -> V_37 , V_41 ) ;
F_8 ( L_23 , ( int ) V_40 ) ;
if ( V_39 -> V_64 == V_40 )
return;
V_39 -> V_64 = V_40 ;
V_45:
if ( V_61 && V_47 == 0 ) {
V_43 = F_15 ( V_61 , V_39 -> V_64 ) ;
if ( V_43 ) {
F_3 ( V_14 L_24 ,
V_43 ) ;
V_47 |= V_53 ;
}
}
}
static void F_20 ( void )
{
struct V_56 V_51 = {
. V_22 = 1 ,
. V_24 = 8 ,
. V_26 = 0x00000000 ,
. V_27 = 0x00000000 ,
. V_28 = 0x00020000 ,
. V_57 = 0x00000000
} ;
V_65 = F_4 ( sizeof( struct V_66 ) ,
V_20 ) ;
if ( V_65 == NULL ) {
F_3 ( V_14 L_17
L_18 ) ;
goto V_15;
}
V_65 -> V_21 = 1 ;
V_51 . V_60 = ( V_67 -> type == V_62 ) ;
V_51 . V_34 = F_5 ( V_67 ) ;
V_51 . V_36 = F_6 ( V_67 ) ;
F_17 ( & V_65 -> V_37 , & V_51 ) ;
F_8 ( L_25 ) ;
F_8 ( L_20 ,
F_9 ( V_51 . V_57 ) , V_51 . V_34 , V_51 . V_36 ) ;
return;
V_15:
if ( V_67 )
F_10 ( V_67 ) ;
}
static void F_21 ( struct V_66 * V_39 )
{
T_1 V_40 , V_42 ;
int V_43 ;
if ( -- V_39 -> V_21 != 0 ) {
if ( V_44 )
goto V_45;
return;
}
V_39 -> V_21 = V_39 -> V_37 . V_51 . V_22 ;
V_43 = F_12 ( V_68 , & V_42 ) ;
if ( V_43 ) {
F_3 ( V_14 L_26 ,
V_43 ) ;
V_47 |= V_48 ;
return;
}
F_8 ( L_27 ,
F_9 ( V_42 ) ) ;
#if 0
if (power > (st->pid.param.itarget + 0x50000))
wf_smu_failure_state |= FAILURE_OVERTEMP;
#endif
V_40 = F_19 ( & V_39 -> V_37 , V_42 ) ;
F_8 ( L_23 , ( int ) V_40 ) ;
if ( V_39 -> V_64 == V_40 )
return;
V_39 -> V_64 = V_40 ;
V_45:
if ( V_67 && V_47 == 0 ) {
V_43 = F_15 ( V_67 , V_39 -> V_64 ) ;
if ( V_43 ) {
F_3 ( V_14 L_28 ,
V_43 ) ;
V_47 |= V_53 ;
}
}
}
static void F_22 ( void )
{
unsigned int V_69 = V_47 ;
unsigned int V_70 ;
if ( ! V_71 ) {
F_8 ( L_29 ) ;
F_16 () ;
F_20 () ;
F_1 () ;
V_71 = 1 ;
}
if ( V_72 && -- V_72 )
return;
V_47 = 0 ;
if ( V_58 )
F_18 ( V_58 ) ;
if ( V_65 )
F_21 ( V_65 ) ;
if ( V_18 )
F_11 ( V_18 ) ;
V_44 = 0 ;
V_70 = V_47 & ~ V_69 ;
if ( V_47 && ! V_69 ) {
if ( V_38 )
F_10 ( V_38 ) ;
if ( V_35 )
F_10 ( V_35 ) ;
if ( V_54 )
F_10 ( V_54 ) ;
if ( V_55 )
F_10 ( V_55 ) ;
if ( V_61 )
F_10 ( V_61 ) ;
if ( V_67 )
F_10 ( V_67 ) ;
}
if ( ! V_47 && V_69 ) {
if ( V_38 )
F_23 ( V_38 ) ;
V_44 = 1 ;
}
if ( V_70 & V_50 ) {
F_24 () ;
V_72 = 2 ;
}
if ( V_70 == 0 && V_69 & V_50 )
F_25 () ;
}
static void F_26 ( struct V_73 * V_74 )
{
if ( V_75 )
return;
if ( V_35 == NULL && ! strcmp ( V_74 -> V_76 , L_30 ) ) {
if ( F_27 ( V_74 ) == 0 )
V_35 = V_74 ;
}
if ( V_54 == NULL && ! strcmp ( V_74 -> V_76 , L_31 ) ) {
if ( F_27 ( V_74 ) == 0 )
V_54 = V_74 ;
}
if ( V_55 == NULL && ! strcmp ( V_74 -> V_76 , L_32 ) ) {
if ( F_27 ( V_74 ) == 0 )
V_55 = V_74 ;
}
if ( V_38 == NULL && ! strcmp ( V_74 -> V_76 , L_33 ) ) {
if ( F_27 ( V_74 ) == 0 )
V_38 = V_74 ;
}
if ( V_61 == NULL && ! strcmp ( V_74 -> V_76 , L_34 ) ) {
if ( F_27 ( V_74 ) == 0 )
V_61 = V_74 ;
}
if ( V_67 == NULL && ! strcmp ( V_74 -> V_76 , L_35 ) ) {
if ( F_27 ( V_74 ) == 0 )
V_67 = V_74 ;
}
if ( V_35 && ( V_54 || V_55 ) && V_61 &&
V_67 && V_38 )
V_75 = 1 ;
}
static void F_28 ( struct V_77 * V_78 )
{
if ( V_79 )
return;
if ( V_49 == NULL && ! strcmp ( V_78 -> V_76 , L_36 ) ) {
if ( F_29 ( V_78 ) == 0 )
V_49 = V_78 ;
}
if ( V_46 == NULL && ! strcmp ( V_78 -> V_76 , L_37 ) ) {
if ( F_29 ( V_78 ) == 0 )
V_46 = V_78 ;
}
if ( V_63 == NULL && ! strcmp ( V_78 -> V_76 , L_38 ) ) {
if ( F_29 ( V_78 ) == 0 )
V_63 = V_78 ;
}
if ( V_68 == NULL && ! strcmp ( V_78 -> V_76 , L_39 ) ) {
if ( F_29 ( V_78 ) == 0 )
V_68 = V_78 ;
}
if ( V_49 && V_46 &&
V_63 && V_68 )
V_79 = 1 ;
}
static int F_30 ( struct V_80 * V_81 ,
unsigned long V_82 , void * V_83 )
{
switch( V_82 ) {
case V_84 :
F_8 ( L_40 ,
( (struct V_73 * ) V_83 ) -> V_76 ) ;
F_26 ( V_83 ) ;
V_44 = 1 ;
break;
case V_85 :
F_8 ( L_41 ,
( (struct V_77 * ) V_83 ) -> V_76 ) ;
F_28 ( V_83 ) ;
break;
case V_86 :
if ( V_75 && V_79 )
F_22 () ;
}
return 0 ;
}
static int F_31 ( void )
{
F_3 ( V_87 L_42 ) ;
return 0 ;
}
static int F_32 ( struct V_88 * V_89 )
{
F_33 ( & V_90 ) ;
return 0 ;
}
static int T_2 F_34 ( struct V_88 * V_89 )
{
F_35 ( & V_90 ) ;
F_36 ( 1000 ) ;
if ( V_49 )
F_37 ( V_49 ) ;
if ( V_46 )
F_37 ( V_46 ) ;
if ( V_63 )
F_37 ( V_63 ) ;
if ( V_68 )
F_37 ( V_68 ) ;
if ( V_35 )
F_38 ( V_35 ) ;
if ( V_54 )
F_38 ( V_54 ) ;
if ( V_55 )
F_38 ( V_55 ) ;
if ( V_61 )
F_38 ( V_61 ) ;
if ( V_67 )
F_38 ( V_67 ) ;
if ( V_38 )
F_38 ( V_38 ) ;
F_39 ( V_65 ) ;
F_39 ( V_58 ) ;
F_39 ( V_18 ) ;
return 0 ;
}
static int T_3 F_40 ( void )
{
int V_43 = - V_91 ;
if ( F_41 ( L_43 ) )
V_43 = F_31 () ;
if ( V_43 == 0 ) {
#ifdef F_42
F_43 ( L_44 ) ;
F_43 ( L_45 ) ;
F_43 ( L_46 ) ;
F_43 ( L_47 ) ;
#endif
F_44 ( & V_92 ) ;
}
return V_43 ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_92 ) ;
}
