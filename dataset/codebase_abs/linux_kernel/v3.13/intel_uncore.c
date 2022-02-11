static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( F_2 ( V_2 -> V_4 ) )
V_3 = V_5 ;
else
V_3 = V_6 ;
if ( F_3 ( ( F_4 ( V_2 , V_7 ) & V_3 ) == 0 , 500 ) )
F_5 ( L_1 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_8 , 0 ) ;
F_8 ( V_2 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( ( F_4 ( V_2 , V_10 ) & 1 ) == 0 ,
V_11 ) )
F_5 ( L_2 ) ;
F_7 ( V_2 , V_8 , 1 ) ;
F_8 ( V_2 , V_9 ) ;
if ( F_10 ( ( F_4 ( V_2 , V_10 ) & 1 ) ,
V_11 ) )
F_5 ( L_3 ) ;
F_1 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_12 , F_12 ( 0xffff ) ) ;
F_8 ( V_2 , V_9 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_13 ;
if ( F_2 ( V_2 -> V_4 ) || F_14 ( V_2 -> V_4 ) )
V_13 = V_14 ;
else
V_13 = V_15 ;
if ( F_10 ( ( F_4 ( V_2 , V_13 ) & V_16 ) == 0 ,
V_11 ) )
F_5 ( L_2 ) ;
F_7 ( V_2 , V_12 ,
F_15 ( V_16 ) ) ;
F_8 ( V_2 , V_9 ) ;
if ( F_10 ( ( F_4 ( V_2 , V_13 ) & V_16 ) ,
V_11 ) )
F_5 ( L_3 ) ;
if ( F_16 ( V_2 -> V_4 ) -> V_17 < 8 )
F_1 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_18 ;
V_18 = F_4 ( V_2 , V_19 ) ;
if ( F_18 ( V_18 & V_20 ,
L_4 , V_18 ) )
F_7 ( V_2 , V_19 , V_20 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_8 , 0 ) ;
F_8 ( V_2 , V_9 ) ;
F_17 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_12 ,
F_12 ( V_16 ) ) ;
F_8 ( V_2 , V_9 ) ;
F_17 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
if ( V_2 -> V_22 . V_23 < V_24 ) {
int V_25 = 500 ;
T_1 V_26 = F_4 ( V_2 , V_27 ) ;
while ( V_26 <= V_24 && V_25 -- ) {
F_22 ( 10 ) ;
V_26 = F_4 ( V_2 , V_27 ) ;
}
if ( F_23 ( V_25 < 0 && V_26 <= V_24 ) )
++ V_21 ;
V_2 -> V_22 . V_23 = V_26 ;
}
V_2 -> V_22 . V_23 -- ;
return V_21 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_28 ,
F_12 ( 0xffff ) ) ;
F_8 ( V_2 , V_29 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( F_10 ( ( F_4 ( V_2 , V_29 ) & V_16 ) == 0 ,
V_11 ) )
F_5 ( L_2 ) ;
F_7 ( V_2 , V_28 ,
F_15 ( V_16 ) ) ;
F_7 ( V_2 , V_30 ,
F_15 ( V_16 ) ) ;
if ( F_10 ( ( F_4 ( V_2 , V_29 ) & V_16 ) ,
V_11 ) )
F_5 ( L_5 ) ;
if ( F_10 ( ( F_4 ( V_2 , V_31 ) &
V_16 ) ,
V_11 ) )
F_5 ( L_6 ) ;
F_1 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_28 ,
F_12 ( V_16 ) ) ;
F_7 ( V_2 , V_30 ,
F_12 ( V_16 ) ) ;
F_17 ( V_2 ) ;
}
static void F_27 ( struct V_32 * V_33 )
{
struct V_1 * V_2 =
F_28 ( V_33 , F_29 ( * V_2 ) , V_22 . V_34 . V_33 ) ;
unsigned long V_35 ;
F_30 ( & V_2 -> V_22 . V_36 , V_35 ) ;
if ( -- V_2 -> V_22 . V_37 == 0 )
V_2 -> V_22 . V_38 . V_39 ( V_2 ) ;
F_31 ( & V_2 -> V_22 . V_36 , V_35 ) ;
}
static void F_32 ( struct V_40 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_41 ;
if ( F_33 ( V_4 ) ) {
F_24 ( V_2 ) ;
} else if ( F_16 ( V_4 ) -> V_17 >= 6 ) {
F_6 ( V_2 ) ;
if ( F_34 ( V_4 ) || F_2 ( V_4 ) )
F_11 ( V_2 ) ;
}
}
void F_35 ( struct V_40 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_41 ;
if ( F_36 ( V_4 ) )
F_7 ( V_2 , V_42 , V_43 ) ;
if ( F_2 ( V_4 ) &&
( F_4 ( V_2 , V_44 ) == 1 ) ) {
V_2 -> V_45 = 128 ;
F_37 ( L_7 , V_2 -> V_45 ) ;
}
F_32 ( V_4 ) ;
}
void F_38 ( struct V_40 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_41 ;
T_1 V_46 ;
F_32 ( V_4 ) ;
F_39 ( V_4 ) ;
if ( F_33 ( V_4 ) ) {
F_40 ( & V_2 -> V_47 . V_48 ) ;
V_46 = F_41 ( V_2 , V_49 ) ;
if ( V_46 & ( V_50 | V_51 | V_52 ) )
F_42 ( V_2 , V_53 , 0x0 ) ;
F_43 ( & V_2 -> V_47 . V_48 ) ;
}
}
void F_44 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
if ( ! V_2 -> V_22 . V_38 . V_54 )
return;
F_30 ( & V_2 -> V_22 . V_36 , V_35 ) ;
if ( V_2 -> V_22 . V_37 ++ == 0 )
V_2 -> V_22 . V_38 . V_54 ( V_2 ) ;
F_31 ( & V_2 -> V_22 . V_36 , V_35 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
if ( ! V_2 -> V_22 . V_38 . V_39 )
return;
F_30 ( & V_2 -> V_22 . V_36 , V_35 ) ;
if ( -- V_2 -> V_22 . V_37 == 0 ) {
V_2 -> V_22 . V_37 ++ ;
F_46 ( V_2 -> V_55 ,
& V_2 -> V_22 . V_34 ,
1 ) ;
}
F_31 ( & V_2 -> V_22 . V_36 , V_35 ) ;
}
static void
F_47 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_56 , 0 ) ;
}
static void
F_48 ( struct V_1 * V_2 , T_1 V_57 )
{
if ( F_4 ( V_2 , V_42 ) & V_43 ) {
F_5 ( L_8 ,
V_57 ) ;
F_7 ( V_2 , V_42 , V_43 ) ;
}
}
static void
F_49 ( struct V_1 * V_2 , T_1 V_57 )
{
if ( F_4 ( V_2 , V_42 ) & V_43 ) {
F_5 ( L_9 , V_57 ) ;
F_7 ( V_2 , V_42 , V_43 ) ;
}
}
static bool F_50 ( struct V_1 * V_2 , T_1 V_57 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < F_51 ( V_59 ) ; V_58 ++ )
if ( V_57 == V_59 [ V_58 ] )
return true ;
return false ;
}
void F_52 ( struct V_40 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_41 ;
F_53 ( & V_2 -> V_22 . V_34 ,
F_27 ) ;
if ( F_33 ( V_4 ) ) {
V_2 -> V_22 . V_38 . V_54 = F_25 ;
V_2 -> V_22 . V_38 . V_39 = F_26 ;
} else if ( F_2 ( V_4 ) || F_14 ( V_4 ) ) {
V_2 -> V_22 . V_38 . V_54 = F_13 ;
V_2 -> V_22 . V_38 . V_39 = F_20 ;
} else if ( F_34 ( V_4 ) ) {
T_1 V_60 ;
F_40 ( & V_4 -> V_61 ) ;
F_13 ( V_2 ) ;
V_60 = F_4 ( V_2 , V_9 ) ;
F_20 ( V_2 ) ;
F_43 ( & V_4 -> V_61 ) ;
if ( V_60 & V_62 ) {
V_2 -> V_22 . V_38 . V_54 =
F_13 ;
V_2 -> V_22 . V_38 . V_39 =
F_20 ;
} else {
F_37 ( L_10 ) ;
F_37 ( L_11 ) ;
V_2 -> V_22 . V_38 . V_54 =
F_9 ;
V_2 -> V_22 . V_38 . V_39 =
F_19 ;
}
} else if ( F_54 ( V_4 ) ) {
V_2 -> V_22 . V_38 . V_54 =
F_9 ;
V_2 -> V_22 . V_38 . V_39 =
F_19 ;
}
switch ( F_16 ( V_4 ) -> V_17 ) {
default:
V_2 -> V_22 . V_38 . V_63 = V_64 ;
V_2 -> V_22 . V_38 . V_65 = V_66 ;
V_2 -> V_22 . V_38 . V_67 = V_68 ;
V_2 -> V_22 . V_38 . V_69 = V_70 ;
V_2 -> V_22 . V_38 . V_71 = V_72 ;
V_2 -> V_22 . V_38 . V_73 = V_74 ;
V_2 -> V_22 . V_38 . V_75 = V_76 ;
V_2 -> V_22 . V_38 . V_77 = V_78 ;
break;
case 7 :
case 6 :
if ( F_2 ( V_4 ) ) {
V_2 -> V_22 . V_38 . V_63 = V_79 ;
V_2 -> V_22 . V_38 . V_65 = V_80 ;
V_2 -> V_22 . V_38 . V_67 = V_81 ;
V_2 -> V_22 . V_38 . V_69 = V_82 ;
} else {
V_2 -> V_22 . V_38 . V_63 = V_83 ;
V_2 -> V_22 . V_38 . V_65 = V_84 ;
V_2 -> V_22 . V_38 . V_67 = V_85 ;
V_2 -> V_22 . V_38 . V_69 = V_86 ;
}
V_2 -> V_22 . V_38 . V_71 = V_72 ;
V_2 -> V_22 . V_38 . V_73 = V_74 ;
V_2 -> V_22 . V_38 . V_75 = V_76 ;
V_2 -> V_22 . V_38 . V_77 = V_78 ;
break;
case 5 :
V_2 -> V_22 . V_38 . V_63 = V_87 ;
V_2 -> V_22 . V_38 . V_65 = V_88 ;
V_2 -> V_22 . V_38 . V_67 = V_89 ;
V_2 -> V_22 . V_38 . V_69 = V_90 ;
V_2 -> V_22 . V_38 . V_71 = V_91 ;
V_2 -> V_22 . V_38 . V_73 = V_92 ;
V_2 -> V_22 . V_38 . V_75 = V_93 ;
V_2 -> V_22 . V_38 . V_77 = V_94 ;
break;
case 4 :
case 3 :
case 2 :
V_2 -> V_22 . V_38 . V_63 = V_95 ;
V_2 -> V_22 . V_38 . V_65 = V_96 ;
V_2 -> V_22 . V_38 . V_67 = V_97 ;
V_2 -> V_22 . V_38 . V_69 = V_98 ;
V_2 -> V_22 . V_38 . V_71 = V_99 ;
V_2 -> V_22 . V_38 . V_73 = V_100 ;
V_2 -> V_22 . V_38 . V_75 = V_101 ;
V_2 -> V_22 . V_38 . V_77 = V_102 ;
break;
}
}
void F_55 ( struct V_40 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_41 ;
F_56 ( & V_2 -> V_22 . V_34 ) ;
F_38 ( V_4 ) ;
}
int F_57 ( struct V_40 * V_4 ,
void * V_103 , struct V_104 * V_105 )
{
struct V_1 * V_2 = V_4 -> V_41 ;
struct V_106 * V_57 = V_103 ;
struct V_107 const * V_108 = V_109 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < F_51 ( V_109 ) ; V_58 ++ , V_108 ++ ) {
if ( V_108 -> V_110 == V_57 -> V_110 &&
( 1 << F_16 ( V_4 ) -> V_17 & V_108 -> V_111 ) )
break;
}
if ( V_58 == F_51 ( V_109 ) )
return - V_112 ;
switch ( V_108 -> V_113 ) {
case 8 :
V_57 -> V_114 = F_58 ( V_57 -> V_110 ) ;
break;
case 4 :
V_57 -> V_114 = F_59 ( V_57 -> V_110 ) ;
break;
case 2 :
V_57 -> V_114 = F_60 ( V_57 -> V_110 ) ;
break;
case 1 :
V_57 -> V_114 = F_61 ( V_57 -> V_110 ) ;
break;
default:
F_23 ( 1 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_62 ( struct V_40 * V_4 )
{
T_2 V_115 ;
F_63 ( V_4 -> V_116 , V_117 , & V_115 ) ;
return ( V_115 & V_118 ) == 0 ;
}
static int F_64 ( struct V_40 * V_4 )
{
int V_21 ;
F_65 ( V_4 -> V_116 , V_117 ,
V_119 | V_118 ) ;
V_21 = F_66 ( F_62 ( V_4 ) , 500 ) ;
if ( V_21 )
return V_21 ;
F_65 ( V_4 -> V_116 , V_117 ,
V_120 | V_118 ) ;
V_21 = F_66 ( F_62 ( V_4 ) , 500 ) ;
if ( V_21 )
return V_21 ;
F_65 ( V_4 -> V_116 , V_117 , 0 ) ;
return 0 ;
}
static int F_67 ( struct V_40 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_41 ;
T_1 V_115 ;
int V_21 ;
V_115 = F_59 ( V_121 + V_122 ) ;
V_115 &= ~ V_123 ;
F_68 ( V_121 + V_122 ,
V_115 | V_119 | V_118 ) ;
V_21 = F_66 ( F_59 ( V_121 + V_122 ) & 0x1 , 500 ) ;
if ( V_21 )
return V_21 ;
V_115 = F_59 ( V_121 + V_122 ) ;
V_115 &= ~ V_123 ;
F_68 ( V_121 + V_122 ,
V_115 | V_120 | V_118 ) ;
return F_66 ( F_59 ( V_121 + V_122 ) & 0x1 , 500 ) ;
}
static int F_69 ( struct V_40 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_41 ;
int V_21 ;
unsigned long V_35 ;
F_30 ( & V_2 -> V_22 . V_36 , V_35 ) ;
F_7 ( V_2 , V_124 , V_125 ) ;
V_21 = F_66 ( ( F_4 ( V_2 , V_124 ) & V_125 ) == 0 , 500 ) ;
F_32 ( V_4 ) ;
if ( V_2 -> V_22 . V_37 )
V_2 -> V_22 . V_38 . V_54 ( V_2 ) ;
else
V_2 -> V_22 . V_38 . V_39 ( V_2 ) ;
V_2 -> V_22 . V_23 = F_4 ( V_2 , V_27 ) ;
F_31 ( & V_2 -> V_22 . V_36 , V_35 ) ;
return V_21 ;
}
int F_70 ( struct V_40 * V_4 )
{
switch ( F_16 ( V_4 ) -> V_17 ) {
case 8 :
case 7 :
case 6 : return F_69 ( V_4 ) ;
case 5 : return F_67 ( V_4 ) ;
case 4 : return F_64 ( V_4 ) ;
default: return - V_126 ;
}
}
void F_71 ( struct V_40 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_41 ;
if ( F_36 ( V_4 ) )
F_7 ( V_2 , V_42 , V_43 ) ;
}
void F_72 ( struct V_40 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_41 ;
if ( F_36 ( V_4 ) &&
( F_4 ( V_2 , V_42 ) & V_43 ) ) {
F_5 ( L_12 ) ;
F_7 ( V_2 , V_42 , V_43 ) ;
}
}
