static void F_1 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_3 V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( V_7 [ V_5 ] . V_8 == V_9 ) {
V_2 = & V_7 [ V_5 ] ;
break;
}
if ( V_2 == NULL ) {
F_2 ( V_10 L_1
L_2 ) ;
goto V_11;
}
V_12 = F_3 ( sizeof( struct V_13 ) ,
V_14 ) ;
if ( V_12 == NULL ) {
F_2 ( V_10 L_3
L_4 ) ;
goto V_11;
}
V_12 -> V_15 = 1 ;
V_12 -> V_16 = V_2 -> V_16 ;
V_12 -> V_17 = V_2 -> V_17 ;
V_12 -> V_18 = V_2 -> V_18 ;
V_12 -> V_19 = V_2 -> V_19 ;
V_4 . V_20 = V_2 -> V_20 ;
V_4 . V_21 = V_2 -> V_21 ;
V_4 . V_22 = V_2 -> V_22 ;
V_4 . V_23 = V_24 ;
V_4 . V_25 = V_26 ;
V_4 . V_27 = V_2 -> V_27 ;
V_4 . V_28 = F_4 ( V_29 ) ;
V_4 . V_30 = F_5 ( V_29 ) ;
if ( V_31 ) {
V_4 . V_28 =
V_30 ( V_4 . V_28 , F_4 ( V_31 ) ) ;
V_4 . V_30 =
V_28 ( V_4 . V_30 , F_5 ( V_31 ) ) ;
}
F_6 ( & V_12 -> V_32 , & V_4 ) ;
F_7 ( L_5 ) ;
F_7 ( L_6 ,
F_8 ( V_4 . V_27 ) , V_4 . V_28 , V_4 . V_30 ) ;
return;
V_11:
if ( V_29 )
F_9 ( V_29 ) ;
if ( V_31 )
F_9 ( V_31 ) ;
}
static void F_10 ( struct V_13 * V_33 )
{
T_1 V_34 , V_35 , V_36 , V_37 ;
int V_38 ;
if ( -- V_33 -> V_15 != 0 ) {
if ( V_39 )
goto V_40;
return;
}
V_33 -> V_15 = V_24 ;
V_38 = F_11 ( V_41 , & V_35 ) ;
if ( V_38 ) {
F_2 ( V_10 L_7 ,
V_38 ) ;
V_42 |= V_43 ;
return;
}
F_7 ( L_8 ,
F_8 ( V_35 ) ) ;
if ( V_35 > ( V_33 -> V_32 . V_2 . V_27 + 0x50000 ) )
V_42 |= V_44 ;
V_34 = F_12 ( & V_33 -> V_32 , V_35 ) ;
F_7 ( L_9 , ( int ) V_34 ) ;
V_36 = ( ( ( ( V_45 ) V_34 ) * ( V_45 ) V_33 -> V_16 ) >> 12 ) + V_33 -> V_17 ;
F_7 ( L_10 , ( int ) V_36 ) ;
V_37 = V_46 ? V_46 -> V_32 . V_47 : 0 ;
V_37 = ( ( ( ( V_45 ) V_37 ) * ( V_45 ) V_33 -> V_18 ) >> 12 ) + V_33 -> V_19 ;
V_36 = V_30 ( V_36 , V_37 ) ;
V_36 = V_30 ( V_36 , V_33 -> V_32 . V_2 . V_28 ) ;
V_36 = V_28 ( V_36 , V_33 -> V_32 . V_2 . V_30 ) ;
F_7 ( L_11 , ( int ) V_36 ) ;
if ( V_33 -> V_48 == V_36 && V_34 == V_33 -> V_49 )
return;
V_33 -> V_48 = V_36 ;
V_33 -> V_49 = V_34 ;
V_40:
if ( V_29 && V_42 == 0 ) {
V_38 = F_13 ( V_29 , V_33 -> V_48 ) ;
if ( V_38 ) {
F_2 ( V_10 L_12 ,
V_38 ) ;
V_42 |= V_50 ;
}
}
if ( V_31 && V_42 == 0 ) {
V_38 = F_13 ( V_31 , V_33 -> V_49 ) ;
if ( V_38 ) {
F_2 ( V_10 L_13 ,
V_38 ) ;
V_42 |= V_50 ;
}
}
}
static void F_14 ( void )
{
struct V_51 V_4 ;
const struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_1 V_58 , V_59 , V_60 , V_61 ;
V_53 = F_15 ( V_62 , NULL ) ;
if ( V_53 == 0 ) {
F_2 ( V_10 L_14
L_15 ) ;
goto V_11;
}
V_55 = (struct V_54 * ) & V_53 [ 1 ] ;
V_53 = F_15 ( V_63 , NULL ) ;
if ( V_53 ) {
V_57 = (struct V_56 * ) & V_53 [ 1 ] ;
V_58 = ( ( T_1 ) V_57 -> V_64 ) << 16 ;
} else
V_58 = 0x5e0000 ;
V_46 = F_3 ( sizeof( struct V_65 ) ,
V_14 ) ;
if ( V_46 == NULL )
goto V_11;
V_46 -> V_15 = 1 ;
V_46 -> V_66 = V_67 ;
V_46 -> V_68 = V_69 ;
V_4 . V_23 = V_70 ;
V_4 . V_25 = V_55 -> V_25 ;
if ( V_4 . V_25 > V_71 ) {
F_2 ( V_10 L_16
L_17 , V_55 -> V_25 ) ;
V_4 . V_25 = V_71 ;
}
V_4 . V_20 = V_55 -> V_20 ;
V_4 . V_21 = V_55 -> V_21 ;
V_4 . V_22 = V_55 -> V_22 / V_4 . V_25 ;
V_59 = ( ( T_1 ) V_55 -> V_72 ) << 16 ;
V_60 = ( ( T_1 ) V_55 -> V_73 ) << 16 ;
V_61 = ( ( T_1 ) V_55 -> V_74 ) << 16 ;
V_4 . V_58 = V_58 ;
V_4 . V_75 = V_58 - V_59 ;
V_4 . V_76 = V_60 - V_61 ;
V_4 . V_28 = F_4 ( V_77 ) ;
V_4 . V_30 = F_5 ( V_77 ) ;
F_16 ( & V_46 -> V_32 , & V_4 ) ;
F_7 ( L_18 ) ;
F_7 ( L_19 ,
F_8 ( V_4 . V_75 ) , F_8 ( V_4 . V_58 ) ,
V_4 . V_28 , V_4 . V_30 ) ;
return;
V_11:
F_2 ( V_10 L_20
L_2 ) ;
if ( V_78 )
F_9 ( V_78 ) ;
if ( V_77 )
F_9 ( V_77 ) ;
}
static void F_17 ( struct V_65 * V_33 )
{
T_1 V_34 , V_35 , V_79 , V_80 ;
int V_38 ;
if ( -- V_33 -> V_15 != 0 ) {
if ( V_39 )
goto V_40;
return;
}
V_33 -> V_15 = V_70 ;
V_38 = F_11 ( V_81 , & V_35 ) ;
if ( V_38 ) {
F_2 ( V_10 L_21 ,
V_38 ) ;
V_42 |= V_43 ;
return;
}
V_38 = F_11 ( V_82 , & V_79 ) ;
if ( V_38 ) {
F_2 ( V_10 L_22 ,
V_38 ) ;
V_42 |= V_43 ;
return;
}
F_7 ( L_23 ,
F_8 ( V_35 ) , F_8 ( V_79 ) ) ;
#ifdef F_18
if ( V_35 > 0x4a0000 )
V_42 |= V_44 ;
#else
if ( V_35 > V_33 -> V_32 . V_2 . V_58 )
V_42 |= V_44 ;
#endif
V_34 = F_19 ( & V_33 -> V_32 , V_79 , V_35 ) ;
F_7 ( L_9 , ( int ) V_34 ) ;
V_80 = V_12 ? V_12 -> V_32 . V_47 : 0 ;
V_80 = ( ( ( ( V_45 ) V_80 ) * ( V_45 ) V_33 -> V_66 ) >> 12 )
+ V_33 -> V_68 ;
V_34 = V_30 ( V_34 , V_80 ) ;
V_34 = V_30 ( V_34 , V_33 -> V_32 . V_2 . V_28 ) ;
V_34 = V_28 ( V_34 , V_33 -> V_32 . V_2 . V_30 ) ;
F_7 ( L_11 , ( int ) V_34 ) ;
if ( V_33 -> V_83 == V_34 )
return;
V_33 -> V_83 = V_34 ;
V_40:
if ( V_77 && V_42 == 0 ) {
V_38 = F_13 ( V_77 , V_33 -> V_83 ) ;
if ( V_38 ) {
F_2 ( V_10 L_24
L_25 , V_38 ) ;
V_42 |= V_50 ;
}
}
}
static void F_20 ( void )
{
unsigned int V_84 = V_42 ;
unsigned int V_85 ;
if ( ! V_86 ) {
F_7 ( L_26 ) ;
F_1 () ;
F_14 () ;
V_86 = 1 ;
}
if ( V_87 && -- V_87 )
return;
V_42 = 0 ;
if ( V_12 )
F_10 ( V_12 ) ;
if ( V_46 )
F_17 ( V_46 ) ;
V_39 = 0 ;
V_85 = V_42 & ~ V_84 ;
if ( V_42 && ! V_84 ) {
if ( V_78 )
F_9 ( V_78 ) ;
if ( V_29 )
F_9 ( V_29 ) ;
if ( V_77 )
F_9 ( V_77 ) ;
if ( V_31 )
F_9 ( V_31 ) ;
}
if ( ! V_42 && V_84 ) {
if ( V_78 )
F_21 ( V_78 ) ;
V_39 = 1 ;
}
if ( V_85 & V_44 ) {
F_22 () ;
V_87 = 2 ;
V_88 = true ;
}
if ( ! V_42 && V_88 ) {
F_23 () ;
V_88 = false ;
}
}
static void F_24 ( struct V_89 * V_90 )
{
if ( V_91 )
return;
if ( V_77 == NULL && ! strcmp ( V_90 -> V_92 , L_27 ) ) {
if ( F_25 ( V_90 ) == 0 )
V_77 = V_90 ;
}
if ( V_29 == NULL && ! strcmp ( V_90 -> V_92 , L_28 ) ) {
if ( F_25 ( V_90 ) == 0 )
V_29 = V_90 ;
}
if ( V_78 == NULL && ! strcmp ( V_90 -> V_92 , L_29 ) ) {
if ( F_25 ( V_90 ) == 0 )
V_78 = V_90 ;
}
if ( V_9 > 3 ) {
if ( V_29 && V_77 && V_78 )
V_91 = 1 ;
return;
}
if ( V_31 == NULL && ! strcmp ( V_90 -> V_92 , L_30 ) ) {
if ( F_25 ( V_90 ) == 0 )
V_31 = V_90 ;
}
if ( V_29 && V_31 && V_77 && V_78 )
V_91 = 1 ;
}
static void F_26 ( struct V_93 * V_94 )
{
if ( V_95 )
return;
if ( V_82 == NULL && ! strcmp ( V_94 -> V_92 , L_31 ) ) {
if ( F_27 ( V_94 ) == 0 )
V_82 = V_94 ;
}
if ( V_81 == NULL && ! strcmp ( V_94 -> V_92 , L_32 ) ) {
if ( F_27 ( V_94 ) == 0 )
V_81 = V_94 ;
}
if ( V_41 == NULL && ! strcmp ( V_94 -> V_92 , L_33 ) ) {
if ( F_27 ( V_94 ) == 0 )
V_41 = V_94 ;
}
if ( V_82 && V_81 && V_41 )
V_95 = 1 ;
}
static int F_28 ( struct V_96 * V_97 ,
unsigned long V_98 , void * V_99 )
{
switch( V_98 ) {
case V_100 :
F_7 ( L_34 ,
( (struct V_89 * ) V_99 ) -> V_92 ) ;
F_24 ( V_99 ) ;
V_39 = 1 ;
break;
case V_101 :
F_7 ( L_35 ,
( (struct V_93 * ) V_99 ) -> V_92 ) ;
F_26 ( V_99 ) ;
break;
case V_102 :
if ( V_91 && V_95 )
F_20 () ;
}
return 0 ;
}
static int F_29 ( void )
{
const struct V_52 * V_53 ;
V_53 = F_15 ( V_103 , NULL ) ;
if ( V_53 != 0 ) {
struct V_104 * V_33 =
(struct V_104 * ) & V_53 [ 1 ] ;
V_9 = V_33 -> V_8 ;
}
F_2 ( V_105 L_36 ,
V_9 ) ;
return 0 ;
}
static int F_30 ( struct V_106 * V_107 )
{
F_31 ( & V_108 ) ;
return 0 ;
}
static int F_32 ( struct V_106 * V_107 )
{
F_33 ( & V_108 ) ;
F_34 ( 1000 ) ;
if ( V_82 )
F_35 ( V_82 ) ;
if ( V_81 )
F_35 ( V_81 ) ;
if ( V_41 )
F_35 ( V_41 ) ;
if ( V_77 )
F_36 ( V_77 ) ;
if ( V_31 )
F_36 ( V_31 ) ;
if ( V_29 )
F_36 ( V_29 ) ;
if ( V_78 )
F_36 ( V_78 ) ;
F_37 ( V_12 ) ;
F_37 ( V_46 ) ;
return 0 ;
}
static int T_2 F_38 ( void )
{
int V_38 = - V_109 ;
if ( F_39 ( L_37 ) ||
F_39 ( L_38 ) )
V_38 = F_29 () ;
if ( V_38 == 0 ) {
#ifdef F_40
F_41 ( L_39 ) ;
F_41 ( L_40 ) ;
F_41 ( L_41 ) ;
F_41 ( L_42 ) ;
#endif
F_42 ( & V_110 ) ;
}
return V_38 ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_110 ) ;
}
