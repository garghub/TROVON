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
V_4 . V_28 = V_29 -> V_30 -> V_31 ( V_29 ) ;
V_4 . V_32 = V_29 -> V_30 -> V_33 ( V_29 ) ;
if ( V_34 ) {
V_4 . V_28 =
V_32 ( V_4 . V_28 , V_34 -> V_30 -> V_31 ( V_34 ) ) ;
V_4 . V_32 =
V_28 ( V_4 . V_32 , V_34 -> V_30 -> V_33 ( V_34 ) ) ;
}
F_4 ( & V_12 -> V_35 , & V_4 ) ;
F_5 ( L_5 ) ;
F_5 ( L_6 ,
F_6 ( V_4 . V_27 ) , V_4 . V_28 , V_4 . V_32 ) ;
return;
V_11:
if ( V_29 )
F_7 ( V_29 ) ;
if ( V_34 )
F_7 ( V_34 ) ;
}
static void F_8 ( struct V_13 * V_36 )
{
T_1 V_37 , V_38 , V_39 , V_40 ;
int V_41 ;
if ( -- V_36 -> V_15 != 0 ) {
if ( V_42 )
goto V_43;
return;
}
V_36 -> V_15 = V_24 ;
V_41 = V_44 -> V_30 -> V_45 ( V_44 , & V_38 ) ;
if ( V_41 ) {
F_2 ( V_10 L_7 ,
V_41 ) ;
V_46 |= V_47 ;
return;
}
F_5 ( L_8 ,
F_6 ( V_38 ) ) ;
if ( V_38 > ( V_36 -> V_35 . V_2 . V_27 + 0x50000 ) )
V_46 |= V_48 ;
V_37 = F_9 ( & V_36 -> V_35 , V_38 ) ;
F_5 ( L_9 , ( int ) V_37 ) ;
V_39 = ( ( ( ( V_49 ) V_37 ) * ( V_49 ) V_36 -> V_16 ) >> 12 ) + V_36 -> V_17 ;
F_5 ( L_10 , ( int ) V_39 ) ;
V_40 = V_50 ? V_50 -> V_35 . V_51 : 0 ;
V_40 = ( ( ( ( V_49 ) V_40 ) * ( V_49 ) V_36 -> V_18 ) >> 12 ) + V_36 -> V_19 ;
V_39 = V_32 ( V_39 , V_40 ) ;
V_39 = V_32 ( V_39 , V_36 -> V_35 . V_2 . V_28 ) ;
V_39 = V_28 ( V_39 , V_36 -> V_35 . V_2 . V_32 ) ;
F_5 ( L_11 , ( int ) V_39 ) ;
if ( V_36 -> V_52 == V_39 && V_37 == V_36 -> V_53 )
return;
V_36 -> V_52 = V_39 ;
V_36 -> V_53 = V_37 ;
V_43:
if ( V_29 && V_46 == 0 ) {
V_41 = V_29 -> V_30 -> V_54 ( V_29 , V_36 -> V_52 ) ;
if ( V_41 ) {
F_2 ( V_10 L_12 ,
V_41 ) ;
V_46 |= V_55 ;
}
}
if ( V_34 && V_46 == 0 ) {
V_41 = V_34 -> V_30 -> V_54 ( V_34 , V_36 -> V_53 ) ;
if ( V_41 ) {
F_2 ( V_10 L_13 ,
V_41 ) ;
V_46 |= V_55 ;
}
}
}
static void F_10 ( void )
{
struct V_56 V_4 ;
const struct V_57 * V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
T_1 V_63 , V_64 , V_65 , V_66 ;
V_58 = F_11 ( V_67 , NULL ) ;
if ( V_58 == 0 ) {
F_2 ( V_10 L_14
L_15 ) ;
goto V_11;
}
V_60 = (struct V_59 * ) & V_58 [ 1 ] ;
V_58 = F_11 ( V_68 , NULL ) ;
if ( V_58 ) {
V_62 = (struct V_61 * ) & V_58 [ 1 ] ;
V_63 = ( ( T_1 ) V_62 -> V_69 ) << 16 ;
} else
V_63 = 0x5e0000 ;
V_50 = F_3 ( sizeof( struct V_70 ) ,
V_14 ) ;
if ( V_50 == NULL )
goto V_11;
V_50 -> V_15 = 1 ;
V_50 -> V_71 = V_72 ;
V_50 -> V_73 = V_74 ;
V_4 . V_23 = V_75 ;
V_4 . V_25 = V_60 -> V_25 ;
if ( V_4 . V_25 > V_76 ) {
F_2 ( V_10 L_16
L_17 , V_60 -> V_25 ) ;
V_4 . V_25 = V_76 ;
}
V_4 . V_20 = V_60 -> V_20 ;
V_4 . V_21 = V_60 -> V_21 ;
V_4 . V_22 = V_60 -> V_22 / V_4 . V_25 ;
V_64 = ( ( T_1 ) V_60 -> V_77 ) << 16 ;
V_65 = ( ( T_1 ) V_60 -> V_78 ) << 16 ;
V_66 = ( ( T_1 ) V_60 -> V_79 ) << 16 ;
V_4 . V_63 = V_63 ;
V_4 . V_80 = V_63 - V_64 ;
V_4 . V_81 = V_65 - V_66 ;
V_4 . V_28 = V_82 -> V_30 -> V_31 ( V_82 ) ;
V_4 . V_32 = V_82 -> V_30 -> V_33 ( V_82 ) ;
F_12 ( & V_50 -> V_35 , & V_4 ) ;
F_5 ( L_18 ) ;
F_5 ( L_19 ,
F_6 ( V_4 . V_80 ) , F_6 ( V_4 . V_63 ) ,
V_4 . V_28 , V_4 . V_32 ) ;
return;
V_11:
F_2 ( V_10 L_20
L_2 ) ;
if ( V_83 )
F_7 ( V_83 ) ;
if ( V_82 )
F_7 ( V_82 ) ;
}
static void F_13 ( struct V_70 * V_36 )
{
T_1 V_37 , V_38 , V_84 , V_85 ;
int V_41 ;
if ( -- V_36 -> V_15 != 0 ) {
if ( V_42 )
goto V_43;
return;
}
V_36 -> V_15 = V_75 ;
V_41 = V_86 -> V_30 -> V_45 ( V_86 , & V_38 ) ;
if ( V_41 ) {
F_2 ( V_10 L_21 ,
V_41 ) ;
V_46 |= V_47 ;
return;
}
V_41 = V_87 -> V_30 -> V_45 ( V_87 , & V_84 ) ;
if ( V_41 ) {
F_2 ( V_10 L_22 ,
V_41 ) ;
V_46 |= V_47 ;
return;
}
F_5 ( L_23 ,
F_6 ( V_38 ) , F_6 ( V_84 ) ) ;
#ifdef F_14
if ( V_38 > 0x4a0000 )
V_46 |= V_48 ;
#else
if ( V_38 > V_36 -> V_35 . V_2 . V_63 )
V_46 |= V_48 ;
#endif
V_37 = F_15 ( & V_36 -> V_35 , V_84 , V_38 ) ;
F_5 ( L_9 , ( int ) V_37 ) ;
V_85 = V_12 ? V_12 -> V_35 . V_51 : 0 ;
V_85 = ( ( ( ( V_49 ) V_85 ) * ( V_49 ) V_36 -> V_71 ) >> 12 )
+ V_36 -> V_73 ;
V_37 = V_32 ( V_37 , V_85 ) ;
V_37 = V_32 ( V_37 , V_36 -> V_35 . V_2 . V_28 ) ;
V_37 = V_28 ( V_37 , V_36 -> V_35 . V_2 . V_32 ) ;
F_5 ( L_11 , ( int ) V_37 ) ;
if ( V_36 -> V_88 == V_37 )
return;
V_36 -> V_88 = V_37 ;
V_43:
if ( V_82 && V_46 == 0 ) {
V_41 = V_82 -> V_30 -> V_54 ( V_82 ,
V_36 -> V_88 ) ;
if ( V_41 ) {
F_2 ( V_10 L_24
L_25 , V_41 ) ;
V_46 |= V_55 ;
}
}
}
static void F_16 ( void )
{
unsigned int V_89 = V_46 ;
unsigned int V_90 ;
if ( ! V_91 ) {
F_5 ( L_26 ) ;
F_1 () ;
F_10 () ;
V_91 = 1 ;
}
if ( V_92 && -- V_92 )
return;
V_46 = 0 ;
if ( V_12 )
F_8 ( V_12 ) ;
if ( V_50 )
F_13 ( V_50 ) ;
V_42 = 0 ;
V_90 = V_46 & ~ V_89 ;
if ( V_46 && ! V_89 ) {
if ( V_83 )
F_7 ( V_83 ) ;
if ( V_29 )
F_7 ( V_29 ) ;
if ( V_82 )
F_7 ( V_82 ) ;
if ( V_34 )
F_7 ( V_34 ) ;
}
if ( ! V_46 && V_89 ) {
if ( V_83 )
F_17 ( V_83 ) ;
V_42 = 1 ;
}
if ( V_90 & V_48 ) {
F_18 () ;
V_92 = 2 ;
}
if ( V_90 == 0 && V_89 & V_48 )
F_19 () ;
}
static void F_20 ( struct V_93 * V_94 )
{
if ( V_95 )
return;
if ( V_82 == NULL && ! strcmp ( V_94 -> V_96 , L_27 ) ) {
if ( F_21 ( V_94 ) == 0 )
V_82 = V_94 ;
}
if ( V_29 == NULL && ! strcmp ( V_94 -> V_96 , L_28 ) ) {
if ( F_21 ( V_94 ) == 0 )
V_29 = V_94 ;
}
if ( V_83 == NULL && ! strcmp ( V_94 -> V_96 , L_29 ) ) {
if ( F_21 ( V_94 ) == 0 )
V_83 = V_94 ;
}
if ( V_9 > 3 ) {
if ( V_29 && V_82 && V_83 )
V_95 = 1 ;
return;
}
if ( V_34 == NULL && ! strcmp ( V_94 -> V_96 , L_30 ) ) {
if ( F_21 ( V_94 ) == 0 )
V_34 = V_94 ;
}
if ( V_29 && V_34 && V_82 && V_83 )
V_95 = 1 ;
}
static void F_22 ( struct V_97 * V_98 )
{
if ( V_99 )
return;
if ( V_87 == NULL && ! strcmp ( V_98 -> V_96 , L_31 ) ) {
if ( F_23 ( V_98 ) == 0 )
V_87 = V_98 ;
}
if ( V_86 == NULL && ! strcmp ( V_98 -> V_96 , L_32 ) ) {
if ( F_23 ( V_98 ) == 0 )
V_86 = V_98 ;
}
if ( V_44 == NULL && ! strcmp ( V_98 -> V_96 , L_33 ) ) {
if ( F_23 ( V_98 ) == 0 )
V_44 = V_98 ;
}
if ( V_87 && V_86 && V_44 )
V_99 = 1 ;
}
static int F_24 ( struct V_100 * V_101 ,
unsigned long V_102 , void * V_103 )
{
switch( V_102 ) {
case V_104 :
F_5 ( L_34 ,
( (struct V_93 * ) V_103 ) -> V_96 ) ;
F_20 ( V_103 ) ;
V_42 = 1 ;
break;
case V_105 :
F_5 ( L_35 ,
( (struct V_97 * ) V_103 ) -> V_96 ) ;
F_22 ( V_103 ) ;
break;
case V_106 :
if ( V_95 && V_99 )
F_16 () ;
}
return 0 ;
}
static int F_25 ( void )
{
const struct V_57 * V_58 ;
V_58 = F_11 ( V_107 , NULL ) ;
if ( V_58 != 0 ) {
struct V_108 * V_36 =
(struct V_108 * ) & V_58 [ 1 ] ;
V_9 = V_36 -> V_8 ;
}
F_2 ( V_109 L_36 ,
V_9 ) ;
return 0 ;
}
static int F_26 ( struct V_110 * V_111 )
{
F_27 ( & V_112 ) ;
return 0 ;
}
static int T_2 F_28 ( struct V_110 * V_111 )
{
F_29 ( & V_112 ) ;
F_30 ( 1000 ) ;
if ( V_87 )
F_31 ( V_87 ) ;
if ( V_86 )
F_31 ( V_86 ) ;
if ( V_44 )
F_31 ( V_44 ) ;
if ( V_82 )
F_32 ( V_82 ) ;
if ( V_34 )
F_32 ( V_34 ) ;
if ( V_29 )
F_32 ( V_29 ) ;
if ( V_83 )
F_32 ( V_83 ) ;
F_33 ( V_12 ) ;
F_33 ( V_50 ) ;
return 0 ;
}
static int T_3 F_34 ( void )
{
int V_41 = - V_113 ;
if ( F_35 ( L_37 ) ||
F_35 ( L_38 ) )
V_41 = F_25 () ;
if ( V_41 == 0 ) {
#ifdef F_36
F_37 ( L_39 ) ;
F_37 ( L_40 ) ;
F_37 ( L_41 ) ;
F_37 ( L_42 ) ;
#endif
F_38 ( & V_114 ) ;
}
return V_41 ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_114 ) ;
}
