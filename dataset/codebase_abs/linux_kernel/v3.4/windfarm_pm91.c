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
V_2 . V_34 = V_35 -> V_36 -> V_37 ( V_35 ) ;
V_2 . V_38 = V_35 -> V_36 -> V_39 ( V_35 ) ;
F_5 ( & V_18 -> V_40 , & V_2 ) ;
F_6 ( L_5 ) ;
F_6 ( L_6 ,
F_7 ( V_2 . V_32 ) , F_7 ( V_2 . V_9 ) ,
V_2 . V_34 , V_2 . V_38 ) ;
return;
V_15:
F_3 ( V_14 L_7
L_8 ) ;
if ( V_41 )
F_8 ( V_41 ) ;
if ( V_35 )
F_8 ( V_35 ) ;
}
static void F_9 ( struct V_19 * V_42 )
{
T_1 V_43 , V_44 , V_45 ;
int V_46 ;
if ( -- V_42 -> V_21 != 0 ) {
if ( V_47 )
goto V_48;
return;
}
V_42 -> V_21 = V_23 ;
V_46 = V_49 -> V_36 -> V_50 ( V_49 , & V_44 ) ;
if ( V_46 ) {
F_3 ( V_14 L_9 ,
V_46 ) ;
V_51 |= V_52 ;
return;
}
V_46 = V_53 -> V_36 -> V_50 ( V_53 , & V_45 ) ;
if ( V_46 ) {
F_3 ( V_14 L_10 ,
V_46 ) ;
V_51 |= V_52 ;
return;
}
F_6 ( L_11 ,
F_7 ( V_44 ) , F_7 ( V_45 ) ) ;
#ifdef F_10
if ( V_44 > 0x4a0000 )
V_51 |= V_54 ;
#else
if ( V_44 > V_42 -> V_40 . V_55 . V_9 )
V_51 |= V_54 ;
#endif
V_43 = F_11 ( & V_42 -> V_40 , V_45 , V_44 ) ;
F_6 ( L_12 , ( int ) V_43 ) ;
if ( V_42 -> V_56 == V_43 )
return;
V_42 -> V_56 = V_43 ;
V_48:
if ( V_35 && V_51 == 0 ) {
V_46 = V_35 -> V_36 -> V_57 ( V_35 ,
V_42 -> V_56 ) ;
if ( V_46 ) {
F_3 ( V_14 L_13
L_14 , V_46 ) ;
V_51 |= V_58 ;
}
}
if ( V_59 && V_51 == 0 ) {
V_46 = V_59 -> V_36 -> V_57 ( V_59 ,
V_42 -> V_56 ) ;
if ( V_46 ) {
F_3 ( V_14 L_15
L_14 , V_46 ) ;
V_51 |= V_58 ;
}
}
if ( V_60 && V_51 == 0 ) {
V_46 = V_35 -> V_36 -> V_57 ( V_60 ,
V_42 -> V_56 ) ;
if ( V_46 ) {
F_3 ( V_14 L_16
L_14 , V_46 ) ;
V_51 |= V_58 ;
}
}
}
static void F_12 ( void )
{
struct V_61 V_55 = {
. V_22 = 5 ,
. V_24 = 2 ,
. V_26 = 0x01e00000 ,
. V_27 = 0x00500000 ,
. V_28 = 0x00000000 ,
. V_62 = 0x00200000 ,
} ;
V_63 = F_4 ( sizeof( struct V_64 ) ,
V_20 ) ;
if ( V_63 == NULL ) {
F_3 ( V_14 L_17
L_18 ) ;
goto V_15;
}
V_63 -> V_21 = 1 ;
V_55 . V_65 = ( V_66 -> type == V_67 ) ;
V_55 . V_34 = V_66 -> V_36 -> V_37 ( V_66 ) ;
V_55 . V_38 = V_66 -> V_36 -> V_39 ( V_66 ) ;
F_13 ( & V_63 -> V_40 , & V_55 ) ;
F_6 ( L_19 ) ;
F_6 ( L_20 ,
F_7 ( V_55 . V_62 ) , V_55 . V_34 , V_55 . V_38 ) ;
return;
V_15:
if ( V_66 )
F_8 ( V_66 ) ;
}
static void F_14 ( struct V_64 * V_42 )
{
T_1 V_43 , V_44 ;
int V_46 ;
if ( -- V_42 -> V_21 != 0 ) {
if ( V_47 )
goto V_48;
return;
}
V_42 -> V_21 = V_42 -> V_40 . V_55 . V_22 ;
V_46 = V_68 -> V_36 -> V_50 ( V_68 , & V_44 ) ;
if ( V_46 ) {
F_3 ( V_14 L_21 ,
V_46 ) ;
V_51 |= V_52 ;
return;
}
F_6 ( L_22 ,
F_7 ( V_44 ) ) ;
if ( V_44 > ( V_42 -> V_40 . V_55 . V_62 + 0x50000 ) )
V_51 |= V_54 ;
V_43 = F_15 ( & V_42 -> V_40 , V_44 ) ;
F_6 ( L_23 , ( int ) V_43 ) ;
if ( V_42 -> V_69 == V_43 )
return;
V_42 -> V_69 = V_43 ;
V_48:
if ( V_66 && V_51 == 0 ) {
V_46 = V_66 -> V_36 -> V_57 ( V_66 , V_42 -> V_69 ) ;
if ( V_46 ) {
F_3 ( V_14 L_24 ,
V_46 ) ;
V_51 |= V_58 ;
}
}
}
static void F_16 ( void )
{
struct V_61 V_55 = {
. V_22 = 1 ,
. V_24 = 8 ,
. V_26 = 0x00000000 ,
. V_27 = 0x00000000 ,
. V_28 = 0x00020000 ,
. V_62 = 0x00000000
} ;
V_70 = F_4 ( sizeof( struct V_71 ) ,
V_20 ) ;
if ( V_70 == NULL ) {
F_3 ( V_14 L_17
L_18 ) ;
goto V_15;
}
V_70 -> V_21 = 1 ;
V_55 . V_65 = ( V_72 -> type == V_67 ) ;
V_55 . V_34 = V_72 -> V_36 -> V_37 ( V_72 ) ;
V_55 . V_38 = V_72 -> V_36 -> V_39 ( V_72 ) ;
F_13 ( & V_70 -> V_40 , & V_55 ) ;
F_6 ( L_25 ) ;
F_6 ( L_20 ,
F_7 ( V_55 . V_62 ) , V_55 . V_34 , V_55 . V_38 ) ;
return;
V_15:
if ( V_72 )
F_8 ( V_72 ) ;
}
static void F_17 ( struct V_71 * V_42 )
{
T_1 V_43 , V_45 ;
int V_46 ;
if ( -- V_42 -> V_21 != 0 ) {
if ( V_47 )
goto V_48;
return;
}
V_42 -> V_21 = V_42 -> V_40 . V_55 . V_22 ;
V_46 = V_73 -> V_36 -> V_50 ( V_73 , & V_45 ) ;
if ( V_46 ) {
F_3 ( V_14 L_26 ,
V_46 ) ;
V_51 |= V_52 ;
return;
}
F_6 ( L_27 ,
F_7 ( V_45 ) ) ;
#if 0
if (power > (st->pid.param.itarget + 0x50000))
wf_smu_failure_state |= FAILURE_OVERTEMP;
#endif
V_43 = F_15 ( & V_42 -> V_40 , V_45 ) ;
F_6 ( L_23 , ( int ) V_43 ) ;
if ( V_42 -> V_69 == V_43 )
return;
V_42 -> V_69 = V_43 ;
V_48:
if ( V_72 && V_51 == 0 ) {
V_46 = V_72 -> V_36 -> V_57 ( V_72 , V_42 -> V_69 ) ;
if ( V_46 ) {
F_3 ( V_14 L_28 ,
V_46 ) ;
V_51 |= V_58 ;
}
}
}
static void F_18 ( void )
{
unsigned int V_74 = V_51 ;
unsigned int V_75 ;
if ( ! V_76 ) {
F_6 ( L_29 ) ;
F_12 () ;
F_16 () ;
F_1 () ;
V_76 = 1 ;
}
if ( V_77 && -- V_77 )
return;
V_51 = 0 ;
if ( V_63 )
F_14 ( V_63 ) ;
if ( V_70 )
F_17 ( V_70 ) ;
if ( V_18 )
F_9 ( V_18 ) ;
V_47 = 0 ;
V_75 = V_51 & ~ V_74 ;
if ( V_51 && ! V_74 ) {
if ( V_41 )
F_8 ( V_41 ) ;
if ( V_35 )
F_8 ( V_35 ) ;
if ( V_59 )
F_8 ( V_59 ) ;
if ( V_60 )
F_8 ( V_60 ) ;
if ( V_66 )
F_8 ( V_66 ) ;
if ( V_72 )
F_8 ( V_72 ) ;
}
if ( ! V_51 && V_74 ) {
if ( V_41 )
F_19 ( V_41 ) ;
V_47 = 1 ;
}
if ( V_75 & V_54 ) {
F_20 () ;
V_77 = 2 ;
}
if ( V_75 == 0 && V_74 & V_54 )
F_21 () ;
}
static void F_22 ( struct V_78 * V_79 )
{
if ( V_80 )
return;
if ( V_35 == NULL && ! strcmp ( V_79 -> V_81 , L_30 ) ) {
if ( F_23 ( V_79 ) == 0 )
V_35 = V_79 ;
}
if ( V_59 == NULL && ! strcmp ( V_79 -> V_81 , L_31 ) ) {
if ( F_23 ( V_79 ) == 0 )
V_59 = V_79 ;
}
if ( V_60 == NULL && ! strcmp ( V_79 -> V_81 , L_32 ) ) {
if ( F_23 ( V_79 ) == 0 )
V_60 = V_79 ;
}
if ( V_41 == NULL && ! strcmp ( V_79 -> V_81 , L_33 ) ) {
if ( F_23 ( V_79 ) == 0 )
V_41 = V_79 ;
}
if ( V_66 == NULL && ! strcmp ( V_79 -> V_81 , L_34 ) ) {
if ( F_23 ( V_79 ) == 0 )
V_66 = V_79 ;
}
if ( V_72 == NULL && ! strcmp ( V_79 -> V_81 , L_35 ) ) {
if ( F_23 ( V_79 ) == 0 )
V_72 = V_79 ;
}
if ( V_35 && ( V_59 || V_60 ) && V_66 &&
V_72 && V_41 )
V_80 = 1 ;
}
static void F_24 ( struct V_82 * V_83 )
{
if ( V_84 )
return;
if ( V_53 == NULL && ! strcmp ( V_83 -> V_81 , L_36 ) ) {
if ( F_25 ( V_83 ) == 0 )
V_53 = V_83 ;
}
if ( V_49 == NULL && ! strcmp ( V_83 -> V_81 , L_37 ) ) {
if ( F_25 ( V_83 ) == 0 )
V_49 = V_83 ;
}
if ( V_68 == NULL && ! strcmp ( V_83 -> V_81 , L_38 ) ) {
if ( F_25 ( V_83 ) == 0 )
V_68 = V_83 ;
}
if ( V_73 == NULL && ! strcmp ( V_83 -> V_81 , L_39 ) ) {
if ( F_25 ( V_83 ) == 0 )
V_73 = V_83 ;
}
if ( V_53 && V_49 &&
V_68 && V_73 )
V_84 = 1 ;
}
static int F_26 ( struct V_85 * V_86 ,
unsigned long V_87 , void * V_88 )
{
switch( V_87 ) {
case V_89 :
F_6 ( L_40 ,
( (struct V_78 * ) V_88 ) -> V_81 ) ;
F_22 ( V_88 ) ;
V_47 = 1 ;
break;
case V_90 :
F_6 ( L_41 ,
( (struct V_82 * ) V_88 ) -> V_81 ) ;
F_24 ( V_88 ) ;
break;
case V_91 :
if ( V_80 && V_84 )
F_18 () ;
}
return 0 ;
}
static int F_27 ( void )
{
F_3 ( V_92 L_42 ) ;
return 0 ;
}
static int F_28 ( struct V_93 * V_94 )
{
F_29 ( & V_95 ) ;
return 0 ;
}
static int T_2 F_30 ( struct V_93 * V_94 )
{
F_31 ( & V_95 ) ;
F_32 ( 1000 ) ;
if ( V_53 )
F_33 ( V_53 ) ;
if ( V_49 )
F_33 ( V_49 ) ;
if ( V_68 )
F_33 ( V_68 ) ;
if ( V_73 )
F_33 ( V_73 ) ;
if ( V_35 )
F_34 ( V_35 ) ;
if ( V_59 )
F_34 ( V_59 ) ;
if ( V_60 )
F_34 ( V_60 ) ;
if ( V_66 )
F_34 ( V_66 ) ;
if ( V_72 )
F_34 ( V_72 ) ;
if ( V_41 )
F_34 ( V_41 ) ;
F_35 ( V_70 ) ;
F_35 ( V_63 ) ;
F_35 ( V_18 ) ;
return 0 ;
}
static int T_3 F_36 ( void )
{
int V_46 = - V_96 ;
if ( F_37 ( L_43 ) )
V_46 = F_27 () ;
if ( V_46 == 0 ) {
#ifdef F_38
F_39 ( L_44 ) ;
F_39 ( L_45 ) ;
F_39 ( L_46 ) ;
F_39 ( L_47 ) ;
#endif
F_40 ( & V_97 ) ;
}
return V_46 ;
}
static void T_4 F_41 ( void )
{
F_42 ( & V_97 ) ;
}
