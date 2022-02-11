static T_1 F_1 ( T_1 V_1 ,
unsigned int V_2 ,
T_1 V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 ;
V_6 = & V_7 [ V_2 ] [ V_8 - 2 ] ;
V_4 = ( V_9 * V_6 -> V_10 ) >> 16 ;
V_4 += V_6 -> V_11 ;
V_4 = ( V_4 >> 16 ) + V_3 ;
return F_2 ( V_1 , V_4 , 0 ) ;
}
static T_1 F_3 ( unsigned int V_2 , T_1 V_12 )
{
T_1 V_4 , V_13 , V_1 ;
if ( V_14 -> V_2 == V_2 ) {
V_15 [ V_2 ] -> V_16 -> V_17 ( V_15 [ V_2 ] ,
& V_13 ) ;
V_4 = V_13 * V_14 -> V_6 . V_10 ;
V_4 += V_14 -> V_6 . V_11 ;
if ( V_4 > 0 ) {
V_1 = F_4 ( V_12 , ( V_4 >> 16 ) ) ;
if ( V_1 != V_12 ) {
F_5 ( L_1
L_2 ,
V_15 [ V_2 ] -> V_18 ,
V_15 [ V_14 -> V_19 ] -> V_18 ,
( int ) V_12 , ( int ) V_1 ) ;
}
} else
V_1 = V_12 ;
}
else
V_1 = V_12 ;
return V_1 ;
}
static void F_6 ( int V_20 )
{
struct V_21 * V_22 = NULL ;
struct V_23 V_24 ;
struct V_25 * V_26 = NULL ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
if ( V_29 [ V_20 ] [ V_27 ] . V_30 == V_8 ) {
V_22 = & ( V_29 [ V_20 ] [ V_27 ] ) ;
break;
}
}
if ( V_22 == NULL ) {
F_7 ( V_31 L_3
L_4 ,
V_32 [ V_20 ] ) ;
goto V_33;
}
V_26 = V_15 [ V_22 -> V_2 ] ;
V_34 [ V_20 ] = F_8 ( sizeof( struct V_34 ) ,
V_35 ) ;
if ( V_34 [ V_20 ] == NULL ) {
F_7 ( V_31 L_5 ) ;
goto V_33;
}
V_34 [ V_20 ] -> V_36 = 1 ;
V_24 . V_37 = V_38 ;
V_24 . V_39 = V_22 -> V_39 ;
V_24 . V_40 = V_41 ;
V_24 . V_42 = V_43 ;
V_24 . V_44 = V_45 ;
V_24 . V_46 = V_22 -> V_46 ;
V_24 . V_3 = V_26 -> V_16 -> V_47 ( V_26 ) ;
V_24 . F_4 = V_26 -> V_16 -> V_48 ( V_26 ) ;
F_9 ( & V_34 [ V_20 ] -> V_49 , & V_24 ) ;
F_5 ( L_6
L_7 ,
V_32 [ V_20 ] , F_10 ( V_24 . V_46 ) ,
V_24 . V_3 , V_24 . F_4 ) ;
return;
V_33:
F_7 ( V_31 L_8
L_9 ,
V_32 [ V_20 ] , V_26 -> V_18 ) ;
if ( V_26 )
F_11 ( V_26 ) ;
}
static void F_12 ( int V_20 )
{
struct V_21 * V_22 ;
struct V_34 * V_50 ;
struct V_51 * V_52 ;
struct V_25 * V_26 ;
T_1 V_53 , V_1 ;
int V_54 ;
V_22 = & ( V_29 [ V_20 ] [ V_8 - 2 ] ) ;
V_50 = V_34 [ V_20 ] ;
V_52 = * ( V_22 -> V_52 ) ;
V_26 = V_15 [ V_22 -> V_2 ] ;
if ( -- V_50 -> V_36 != 0 ) {
if ( V_55 )
goto V_56;
return;
}
V_50 -> V_36 = V_43 ;
V_54 = V_52 -> V_16 -> V_17 ( V_52 , & V_53 ) ;
if ( V_54 ) {
F_7 ( V_31 L_10 ,
V_52 -> V_18 , V_54 ) ;
V_57 |= V_58 ;
return;
}
F_5 ( L_11 ,
V_32 [ V_20 ] , V_52 -> V_18 ,
F_10 ( V_53 ) ) ;
V_1 = F_13 ( & V_50 -> V_49 , V_53 ) ;
V_1 = F_1 ( V_1 ,
V_22 -> V_2 ,
V_50 -> V_49 . V_22 . V_3 ) ;
V_1 = F_3 ( V_22 -> V_2 , V_1 ) ;
if ( V_1 == V_50 -> V_12 )
return;
V_50 -> V_12 = V_1 ;
F_5 ( L_12 ,
V_26 -> V_18 , ( int ) V_1 ) ;
V_56:
if ( V_26 && V_57 == 0 ) {
V_54 = V_26 -> V_16 -> V_59 ( V_26 , V_50 -> V_12 ) ;
if ( V_54 ) {
F_7 ( V_31 L_13 ,
V_26 -> V_18 , V_54 ) ;
V_57 |= V_60 ;
}
}
}
static void F_14 ( void )
{
struct V_61 V_24 ;
const struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_25 * V_68 ;
T_1 V_69 , V_70 , V_71 , V_72 ;
V_68 = V_15 [ V_73 ] ;
V_63 = F_15 ( V_74 , NULL ) ;
if ( V_63 == 0 ) {
F_7 ( V_31 L_14 ) ;
goto V_33;
}
V_65 = (struct V_64 * ) & V_63 [ 1 ] ;
V_63 = F_15 ( V_75 , NULL ) ;
if ( V_63 ) {
V_67 = (struct V_66 * ) & V_63 [ 1 ] ;
V_69 = ( ( T_1 ) V_67 -> V_76 ) << 16 ;
} else
V_69 = 0x5e0000 ;
V_77 = F_8 ( sizeof( struct V_77 ) ,
V_35 ) ;
if ( V_77 == NULL )
goto V_33;
V_77 -> V_36 = 1 ;
V_24 . V_42 = V_78 ;
V_24 . V_44 = V_65 -> V_44 ;
if ( V_24 . V_44 > V_79 ) {
F_7 ( V_31 L_15
L_16 , V_65 -> V_44 ) ;
V_24 . V_44 = V_79 ;
}
V_24 . V_37 = V_65 -> V_37 ;
V_24 . V_39 = V_65 -> V_39 ;
V_24 . V_40 = V_65 -> V_40 / V_24 . V_44 ;
V_70 = ( ( T_1 ) V_65 -> V_80 ) << 16 ;
V_71 = ( ( T_1 ) V_65 -> V_81 ) << 16 ;
V_72 = ( ( T_1 ) V_65 -> V_82 ) << 16 ;
V_24 . V_69 = V_69 ;
V_24 . V_83 = V_69 - V_70 ;
V_24 . V_84 = V_71 - V_72 ;
V_24 . V_3 = V_68 -> V_16 -> V_47 ( V_68 ) ;
V_24 . F_4 = V_68 -> V_16 -> V_48 ( V_68 ) ;
F_16 ( & V_77 -> V_49 , & V_24 ) ;
F_5 ( L_17 ) ;
F_5 ( L_18 ,
F_10 ( V_24 . V_83 ) , F_10 ( V_24 . V_69 ) ,
V_24 . V_3 , V_24 . F_4 ) ;
return;
V_33:
F_7 ( V_31 L_19 ) ;
if ( V_15 [ V_85 ] )
F_11 ( V_15 [ V_85 ] ) ;
if ( V_68 )
F_11 ( V_68 ) ;
}
static void F_17 ( struct V_77 * V_50 )
{
T_1 V_1 , V_53 , V_86 ;
struct V_25 * V_68 = NULL ;
int V_54 ;
if ( -- V_50 -> V_36 != 0 ) {
if ( V_55 )
goto V_56;
return;
}
V_50 -> V_36 = V_78 ;
V_68 = V_15 [ V_73 ] ;
V_54 = V_87 -> V_16 -> V_17 ( V_87 , & V_53 ) ;
if ( V_54 ) {
F_7 ( V_31 L_20 ,
V_54 ) ;
V_57 |= V_58 ;
return;
}
V_54 = V_88 -> V_16 -> V_17 ( V_88 , & V_86 ) ;
if ( V_54 ) {
F_7 ( V_31 L_21 ,
V_54 ) ;
V_57 |= V_58 ;
return;
}
F_5 ( L_22 ,
F_10 ( V_53 ) , F_10 ( V_86 ) ) ;
if ( V_53 > V_50 -> V_49 . V_22 . V_69 )
V_57 |= V_89 ;
V_1 = F_18 ( & V_50 -> V_49 , V_86 , V_53 ) ;
V_1 = F_1 ( V_1 ,
V_73 ,
V_50 -> V_49 . V_22 . V_3 ) ;
V_1 = F_3 ( V_73 , V_1 ) ;
if ( V_50 -> V_12 == V_1 )
return;
V_50 -> V_12 = V_1 ;
F_5 ( L_23 , ( int ) V_1 ) ;
V_56:
if ( V_68 && V_57 == 0 ) {
V_54 = V_68 -> V_16 -> V_59 ( V_68 , V_50 -> V_12 ) ;
if ( V_54 ) {
F_7 ( V_31 L_24 ,
V_68 -> V_18 , V_54 ) ;
V_57 |= V_60 ;
}
}
}
static void F_19 ( void )
{
unsigned int V_90 = V_57 ;
unsigned int V_91 ;
T_1 V_92 ;
int V_27 ;
if ( ! V_93 ) {
F_5 ( L_25 ) ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ )
F_6 ( V_27 ) ;
F_14 () ;
V_93 = 1 ;
}
if ( V_95 && -- V_95 )
return;
V_92 = 0 ;
for ( V_27 = 0 ; V_27 < V_77 -> V_49 . V_22 . V_44 ; V_27 ++ )
V_92 += V_77 -> V_49 . V_96 [ V_27 ] ;
V_9 = V_92 / V_77 -> V_49 . V_22 . V_44 ;
V_57 = 0 ;
for ( V_27 = 0 ; V_27 < V_94 ; V_27 ++ ) {
if ( V_34 [ V_27 ] )
F_12 ( V_27 ) ;
}
if ( V_77 )
F_17 ( V_77 ) ;
V_55 = 0 ;
V_91 = V_57 & ~ V_90 ;
if ( V_57 && ! V_90 ) {
for ( V_27 = 0 ; V_27 < V_97 ; V_27 ++ ) {
if ( V_15 [ V_27 ] )
F_11 ( V_15 [ V_27 ] ) ;
}
}
if ( ! V_57 && V_90 ) {
if ( V_15 [ V_85 ] )
F_20 ( V_15 [ V_85 ] ) ;
V_55 = 1 ;
}
if ( V_91 & V_89 ) {
F_21 () ;
V_95 = 2 ;
V_98 = true ;
}
if ( ! V_57 && V_98 ) {
F_22 () ;
V_98 = false ;
}
}
static struct V_25 * F_23 ( struct V_25 * V_99 ,
const char * V_100 ,
unsigned int V_101 )
{
if ( V_15 [ V_101 ] == NULL && ! strcmp ( V_99 -> V_18 , V_100 ) ) {
if ( F_24 ( V_99 ) == 0 )
V_15 [ V_101 ] = V_99 ;
}
return V_15 [ V_101 ] ;
}
static void F_25 ( struct V_25 * V_99 )
{
int V_102 = 1 ;
if ( V_103 )
return;
V_102 = F_23 ( V_99 , L_26 , V_104 ) && V_102 ;
V_102 = F_23 ( V_99 , L_27 , V_105 ) && V_102 ;
V_102 = F_23 ( V_99 , L_28 , V_73 ) && V_102 ;
V_102 = F_23 ( V_99 , L_29 , V_85 ) && V_102 ;
if ( V_102 )
V_103 = 1 ;
}
static struct V_51 * F_26 ( struct V_51 * V_52 ,
const char * V_100 ,
struct V_51 * * V_106 )
{
if ( * V_106 == NULL && ! strcmp ( V_52 -> V_18 , V_100 ) ) {
if ( F_27 ( V_52 ) == 0 )
* V_106 = V_52 ;
}
return * V_106 ;
}
static void F_28 ( struct V_51 * V_107 )
{
int V_102 = 1 ;
if ( V_108 )
return;
V_102 = F_26 ( V_107 , L_30 ,
& V_87 ) && V_102 ;
V_102 = F_26 ( V_107 , L_31 ,
& V_109 ) && V_102 ;
V_102 = F_26 ( V_107 , L_32 ,
& V_110 ) && V_102 ;
V_102 = F_26 ( V_107 , L_33 ,
& V_88 ) && V_102 ;
V_102 = F_26 ( V_107 , L_34 ,
& V_111 ) && V_102 ;
V_102 = F_26 ( V_107 , L_35 ,
& V_112 ) && V_102 ;
V_102 = F_26 ( V_107 , L_36 ,
& V_113 ) && V_102 ;
V_102 = F_26 ( V_107 , L_37 ,
& V_114 ) && V_102 ;
V_102 = F_26 ( V_107 , L_38 ,
& V_115 ) && V_102 ;
if ( V_102 )
V_108 = 1 ;
}
static int F_29 ( struct V_116 * V_117 ,
unsigned long V_118 , void * V_119 )
{
switch ( V_118 ) {
case V_120 :
F_5 ( L_39 ,
( (struct V_25 * ) V_119 ) -> V_18 ) ;
F_25 ( V_119 ) ;
break;
case V_121 :
F_5 ( L_40 ,
( (struct V_51 * ) V_119 ) -> V_18 ) ;
F_28 ( V_119 ) ;
break;
case V_122 :
if ( V_103 && V_108 )
F_19 () ;
break;
}
return 0 ;
}
static int F_30 ( void )
{
const struct V_62 * V_63 ;
V_63 = F_15 ( V_123 , NULL ) ;
if ( V_63 != 0 ) {
struct V_124 * V_50 =
(struct V_124 * ) & V_63 [ 1 ] ;
V_8 = V_50 -> V_30 ;
}
V_14 = & V_125 [ V_8 - 2 ] ;
F_7 ( V_126 L_41 ,
V_8 ) ;
return 0 ;
}
static int F_31 ( struct V_127 * V_128 )
{
F_32 ( & V_129 ) ;
return 0 ;
}
static int F_33 ( struct V_127 * V_128 )
{
F_34 ( & V_129 ) ;
return 0 ;
}
static int T_2 F_35 ( void )
{
int V_54 = - V_130 ;
if ( F_36 ( L_42 ) )
V_54 = F_30 () ;
if ( V_54 == 0 ) {
F_37 ( L_43 ) ;
F_37 ( L_44 ) ;
F_37 ( L_45 ) ;
F_37 ( L_46 ) ;
F_37 ( L_47 ) ;
F_37 ( L_48 ) ;
F_38 ( & V_131 ) ;
}
return V_54 ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_131 ) ;
}
