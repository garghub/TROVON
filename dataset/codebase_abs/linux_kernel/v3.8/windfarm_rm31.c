static void F_1 ( void )
{
int V_1 ;
if ( V_2 )
F_2 ( V_2 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
if ( V_4 [ V_1 ] [ 0 ] )
F_2 ( V_4 [ V_1 ] [ 0 ] ) ;
if ( V_4 [ V_1 ] [ 1 ] )
F_2 ( V_4 [ V_1 ] [ 1 ] ) ;
if ( V_4 [ V_1 ] [ 2 ] )
F_2 ( V_4 [ V_1 ] [ 2 ] ) ;
}
}
static int F_3 ( T_1 V_5 )
{
int V_6 = 0 ;
T_1 V_7 , V_8 ;
static bool V_9 = true ;
if ( V_5 >= ( V_10 + V_11 ) ) {
V_6 |= V_12 ;
if ( ( V_13 & V_12 ) == 0 )
F_4 ( V_14 L_1
L_2 ) ;
}
if ( V_5 >= ( V_10 + V_15 ) ) {
V_6 |= V_16 ;
if ( ( V_13 & V_16 ) == 0 )
F_4 ( V_14 L_3
L_4 ) ;
}
if ( V_9 ) {
int V_1 ;
V_17 = 0 ;
for ( V_1 = 0 ; V_1 < V_18 ; V_1 ++ ) {
V_19 [ V_1 ] = V_5 ;
V_17 += V_5 ;
}
V_9 = false ;
}
V_8 = V_19 [ V_20 ] ;
V_19 [ V_20 ] = V_5 ;
V_20 = ( V_20 + 1 ) % V_18 ;
V_17 -= V_8 ;
V_17 += V_5 ;
V_7 = V_17 / V_18 ;
F_5 ( L_5 ,
F_6 ( V_7 ) , F_6 ( V_8 ) , F_6 ( V_5 ) ) ;
if ( V_7 >= ( V_10 + V_21 ) ) {
V_6 |= V_12 ;
if ( ( V_13 & V_12 ) == 0 )
F_4 ( V_14 L_6
L_2 ) ;
}
if ( V_7 >= ( V_10 + V_22 ) ) {
V_6 |= V_16 ;
if ( ( V_13 & V_16 ) == 0 )
F_4 ( V_14 L_3
L_7 ) ;
}
if ( V_6 ) {
if ( V_6 & V_16 )
F_7 () ;
if ( ( V_13 & V_6 ) != V_6 )
F_1 () ;
V_13 |= V_6 ;
} else if ( ( V_13 & V_12 ) &&
( V_5 < ( V_10 + V_23 ) ) ) {
F_4 ( V_14 L_8 ) ;
V_13 &= ~ V_12 ;
}
return V_13 & ( V_12 | V_16 ) ;
}
static int F_8 ( int V_24 , T_1 * V_5 , T_1 * V_25 )
{
T_1 V_26 , V_27 , V_28 ;
int V_29 ;
V_29 = F_9 ( V_30 [ V_24 ] , & V_26 ) ;
if ( V_29 ) {
F_10 ( L_9 , V_24 ) ;
return - V_31 ;
}
F_5 ( L_10 , V_24 , F_6 ( ( V_26 ) ) ) ;
* V_5 = V_26 ;
V_29 = F_9 ( V_32 [ V_24 ] , & V_27 ) ;
if ( V_29 ) {
F_10 ( L_11 , V_24 ) ;
return - V_31 ;
}
F_5 ( L_12 , V_24 , F_6 ( ( V_27 ) ) ) ;
V_29 = F_9 ( V_33 [ V_24 ] , & V_28 ) ;
if ( V_29 ) {
F_10 ( L_13 , V_24 ) ;
return - V_31 ;
}
F_5 ( L_14 , V_24 , F_6 ( ( V_28 ) ) ) ;
* V_25 = ( ( ( V_34 ) V_27 ) * ( ( V_34 ) V_28 ) ) >> 16 ;
F_5 ( L_15 , V_24 , F_6 ( ( * V_25 ) ) ) ;
return 0 ;
}
static void F_11 ( void )
{
int V_35 , V_24 , V_1 ;
T_1 V_36 , V_5 , V_25 , V_37 = 0 ;
F_5 ( L_16 ) ;
for ( V_24 = 0 ; V_24 < V_3 ; ++ V_24 ) {
struct V_38 * V_39 = & V_40 [ V_24 ] ;
F_12 ( V_4 [ V_24 ] [ 0 ] , & V_39 -> V_41 ) ;
V_35 = F_8 ( V_24 , & V_5 , & V_25 ) ;
if ( V_35 ) {
V_13 |= V_42 ;
F_1 () ;
return;
}
V_37 = F_13 ( V_37 , V_5 ) ;
if ( F_3 ( V_37 ) )
return;
F_14 ( V_39 , V_25 , V_5 ) ;
F_5 ( L_17 , V_24 , V_39 -> V_41 ) ;
V_36 = F_13 ( V_39 -> V_41 , V_43 ) ;
for ( V_1 = 0 ; V_1 < 3 ; V_1 ++ ) {
V_35 = F_15 ( V_4 [ V_24 ] [ V_1 ] , V_36 ) ;
if ( V_35 ) {
F_16 ( L_18 ,
V_4 [ V_24 ] [ V_1 ] -> V_44 , V_35 ) ;
V_13 |= V_45 ;
}
}
}
}
static int F_17 ( int V_24 )
{
struct V_46 V_47 ;
const struct V_48 * V_49 = V_50 [ V_24 ] ;
T_1 V_51 , V_52 , V_53 ;
int V_54 , V_55 , V_56 ;
V_51 = V_49 -> V_51 << 16 ;
V_52 = V_49 -> V_52 << 16 ;
V_53 = ( ( T_1 ) ( V_49 -> V_57 - V_49 -> V_58 ) ) << 16 ;
F_10 ( L_19 ,
V_24 , F_6 ( V_52 ) , F_6 ( V_51 ) ) ;
if ( V_51 < V_10 )
V_10 = V_51 ;
V_54 = F_18 ( V_4 [ V_24 ] [ 0 ] ) ;
V_55 = F_19 ( V_4 [ V_24 ] [ 0 ] ) ;
F_10 ( L_20 , V_24 , V_54 , V_55 ) ;
V_56 = F_20 ( int , V_49 -> V_59 , V_60 ) ;
F_10 ( L_21 , V_24 , V_56 ) ;
V_47 . V_61 = 1 ;
V_47 . V_62 = V_56 ;
V_47 . V_63 = V_49 -> V_64 ;
V_47 . V_65 = V_49 -> V_66 ;
V_47 . V_67 = V_49 -> V_68 ;
V_47 . V_51 = V_51 ;
V_47 . V_52 = V_52 ;
V_47 . V_69 = V_53 ;
V_47 . V_70 = V_54 ;
V_47 . F_13 = V_55 ;
F_21 ( & V_40 [ V_24 ] , & V_47 ) ;
V_40 [ V_24 ] . V_41 = 4000 ;
return 0 ;
}
static void F_22 ( void )
{
T_1 V_5 , V_26 ;
int V_36 , V_71 , V_72 ;
int V_35 ;
if ( ! V_73 || ! V_74 || ! V_75 || ! V_76 )
return;
if ( -- V_76 > 0 )
return;
V_76 = V_77 . V_78 . V_61 ;
F_5 ( L_22 ) ;
V_35 = F_12 ( V_73 , & V_36 ) ;
if ( ! V_35 )
V_77 . V_41 = V_36 ;
V_35 = F_9 ( V_74 , & V_5 ) ;
if ( V_35 ) {
F_4 ( V_79 L_23 ,
V_35 ) ;
V_13 |= V_42 ;
F_2 ( V_73 ) ;
return;
}
V_36 = F_23 ( & V_77 , V_5 ) ;
F_5 ( L_24 ,
F_6 ( V_5 ) , V_36 ) ;
V_35 = F_9 ( V_75 , & V_26 ) ;
if ( V_35 ) {
F_4 ( V_79 L_25 ,
V_35 ) ;
V_13 |= V_42 ;
F_2 ( V_73 ) ;
return;
}
V_71 = F_23 ( & V_80 , V_26 ) ;
V_43 = V_71 ;
V_72 = ( V_71 * 100 ) / 14000 ;
V_72 = F_13 ( V_72 , V_81 . V_70 ) ;
V_36 = F_13 ( V_36 , V_72 ) ;
V_35 = F_15 ( V_73 , V_36 ) ;
if ( V_35 ) {
F_4 ( V_79 L_26 , V_35 ) ;
V_13 |= V_45 ;
}
}
static void F_24 ( void )
{
T_1 V_54 = F_18 ( V_73 ) ;
T_1 V_55 = F_19 ( V_73 ) ;
struct V_82 V_78 ;
V_78 = V_81 ;
V_78 . V_70 = F_13 ( V_78 . V_70 , V_54 ) ;
V_78 . F_13 = V_70 ( V_78 . F_13 , V_55 ) ;
F_25 ( & V_77 , & V_78 ) ;
V_78 = V_83 ;
F_25 ( & V_80 , & V_78 ) ;
V_76 = 1 ;
F_26 ( L_27 ) ;
}
static void F_27 ( void )
{
T_1 V_5 ;
int V_36 ;
int V_35 ;
if ( ! V_84 || ! V_85 || ! V_86 )
return;
if ( -- V_86 > 0 )
return;
V_86 = V_87 . V_78 . V_61 ;
F_5 ( L_28 ) ;
V_35 = F_9 ( V_85 , & V_5 ) ;
if ( V_35 ) {
F_16 ( L_29 , V_35 ) ;
V_13 |= V_42 ;
F_2 ( V_84 ) ;
return;
}
V_36 = F_23 ( & V_87 , V_5 ) ;
F_5 ( L_30 ,
F_6 ( V_5 ) , V_36 ) ;
V_88 = V_36 ;
V_35 = F_15 ( V_84 , V_36 ) ;
if ( V_35 ) {
F_4 ( V_79 L_31 , V_35 ) ;
V_13 |= V_45 ;
}
}
static void F_28 ( void )
{
T_1 V_54 = F_18 ( V_84 ) ;
T_1 V_55 = F_19 ( V_84 ) ;
struct V_82 V_78 = V_89 ;
V_78 . V_70 = F_13 ( V_78 . V_70 , V_54 ) ;
V_78 . F_13 = V_70 ( V_78 . F_13 , V_55 ) ;
F_25 ( & V_87 , & V_78 ) ;
V_86 = 1 ;
F_26 ( L_32 ) ;
}
static void F_29 ( void )
{
F_1 () ;
if ( V_73 )
F_2 ( V_73 ) ;
if ( V_84 )
F_2 ( V_84 ) ;
}
static void F_30 ( void )
{
int V_1 , V_90 ;
if ( ! V_91 ) {
V_91 = 1 ;
F_4 ( V_92 L_33 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; ++ V_1 ) {
if ( F_17 ( V_1 ) < 0 ) {
V_13 = V_93 ;
F_29 () ;
break;
}
}
F_5 ( L_34 , F_6 ( V_10 ) ) ;
F_24 () ;
F_28 () ;
#ifdef F_31
V_10 = 60 << 16 ;
#endif
}
if ( V_13 & V_93 )
return;
V_90 = V_13 ;
V_13 &= V_12 ;
F_22 () ;
F_27 () ;
F_11 () ;
F_5 ( L_35 ,
V_90 , V_13 ) ;
if ( V_13 && V_90 == 0 && V_2 )
F_2 ( V_2 ) ;
if ( V_13 == 0 && V_90 && V_2 )
F_32 ( V_2 ) ;
}
static void F_33 ( struct V_94 * V_95 )
{
bool V_96 ;
if ( ! strcmp ( V_95 -> V_44 , L_36 ) )
V_4 [ 0 ] [ 0 ] = V_95 ;
else if ( ! strcmp ( V_95 -> V_44 , L_37 ) )
V_4 [ 0 ] [ 1 ] = V_95 ;
else if ( ! strcmp ( V_95 -> V_44 , L_38 ) )
V_4 [ 0 ] [ 2 ] = V_95 ;
else if ( ! strcmp ( V_95 -> V_44 , L_39 ) )
V_4 [ 1 ] [ 0 ] = V_95 ;
else if ( ! strcmp ( V_95 -> V_44 , L_40 ) )
V_4 [ 1 ] [ 1 ] = V_95 ;
else if ( ! strcmp ( V_95 -> V_44 , L_41 ) )
V_4 [ 1 ] [ 2 ] = V_95 ;
else if ( ! strcmp ( V_95 -> V_44 , L_42 ) )
V_73 = V_95 ;
else if ( ! strcmp ( V_95 -> V_44 , L_43 ) )
V_84 = V_95 ;
else if ( ! strcmp ( V_95 -> V_44 , L_44 ) )
V_2 = V_95 ;
V_96 =
V_4 [ 0 ] [ 0 ] &&
V_4 [ 0 ] [ 1 ] &&
V_4 [ 0 ] [ 2 ] &&
V_73 &&
V_84 ;
if ( V_3 > 1 )
V_96 &=
V_4 [ 1 ] [ 0 ] &&
V_4 [ 1 ] [ 1 ] &&
V_4 [ 1 ] [ 2 ] ;
V_97 = V_96 ;
}
static void F_34 ( struct V_98 * V_99 )
{
bool V_100 ;
if ( ! strcmp ( V_99 -> V_44 , L_45 ) )
V_30 [ 0 ] = V_99 ;
else if ( ! strcmp ( V_99 -> V_44 , L_46 ) )
V_30 [ 1 ] = V_99 ;
else if ( ! strcmp ( V_99 -> V_44 , L_47 ) )
V_32 [ 0 ] = V_99 ;
else if ( ! strcmp ( V_99 -> V_44 , L_48 ) )
V_32 [ 1 ] = V_99 ;
else if ( ! strcmp ( V_99 -> V_44 , L_49 ) )
V_33 [ 0 ] = V_99 ;
else if ( ! strcmp ( V_99 -> V_44 , L_50 ) )
V_33 [ 1 ] = V_99 ;
else if ( ! strcmp ( V_99 -> V_44 , L_51 ) )
V_74 = V_99 ;
else if ( ! strcmp ( V_99 -> V_44 , L_52 ) )
V_85 = V_99 ;
else if ( ! strcmp ( V_99 -> V_44 , L_53 ) )
V_75 = V_99 ;
V_100 =
V_30 [ 0 ] &&
V_32 [ 0 ] &&
V_33 [ 0 ] &&
V_74 &&
V_85 &&
V_75 ;
if ( V_3 > 1 )
V_100 &=
V_30 [ 1 ] &&
V_32 [ 1 ] &&
V_33 [ 1 ] ;
V_101 = V_100 ;
}
static int F_35 ( struct V_102 * V_103 ,
unsigned long V_104 , void * V_105 )
{
switch ( V_104 ) {
case V_106 :
F_34 ( V_105 ) ;
break;
case V_107 :
F_33 ( V_105 ) ;
break;
case V_108 :
if ( V_97 && V_101 )
F_30 () ;
}
return 0 ;
}
static int F_36 ( struct V_109 * V_110 )
{
F_37 ( & V_111 ) ;
return 0 ;
}
static int F_38 ( struct V_109 * V_110 )
{
F_39 ( & V_111 ) ;
return 0 ;
}
static int T_2 F_40 ( void )
{
struct V_112 * V_24 ;
int V_1 ;
if ( ! F_41 ( L_54 ) )
return - V_113 ;
V_3 = 0 ;
for ( V_24 = NULL ; ( V_24 = F_42 ( V_24 , L_55 ) ) != NULL ; )
++ V_3 ;
if ( V_3 > V_114 )
V_3 = V_114 ;
F_26 ( L_56 ,
V_3 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
V_50 [ V_1 ] = F_43 ( V_1 ) ;
if ( ! V_50 [ V_1 ] ) {
F_44 ( L_57 , V_1 ) ;
return - V_115 ;
}
}
#ifdef F_45
F_46 ( L_58 ) ;
F_46 ( L_59 ) ;
F_46 ( L_60 ) ;
F_46 ( L_61 ) ;
F_46 ( L_62 ) ;
F_46 ( L_63 ) ;
#endif
F_47 ( & V_116 ) ;
return 0 ;
}
static void T_3 F_48 ( void )
{
F_49 ( & V_116 ) ;
}
