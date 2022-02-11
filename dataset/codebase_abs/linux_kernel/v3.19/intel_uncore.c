static void
F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_3 ) && V_2 -> V_4 . V_5 ,
L_1 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( F_5 ( ( F_6 ( V_2 , V_6 ) &
V_7 ) == 0 , 500 ) )
F_7 ( L_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_8 , 0 ) ;
F_10 ( V_2 , V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
int V_10 )
{
if ( F_12 ( ( F_6 ( V_2 , V_11 ) & 1 ) == 0 ,
V_12 ) )
F_7 ( L_3 ) ;
F_9 ( V_2 , V_8 , 1 ) ;
F_10 ( V_2 , V_9 ) ;
if ( F_12 ( ( F_6 ( V_2 , V_11 ) & 1 ) ,
V_12 ) )
F_7 ( L_4 ) ;
F_4 ( V_2 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_13 , F_14 ( 0xffff ) ) ;
F_10 ( V_2 , V_9 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
int V_10 )
{
T_1 V_14 ;
if ( F_16 ( V_2 -> V_3 ) || F_17 ( V_2 -> V_3 ) )
V_14 = V_15 ;
else
V_14 = V_16 ;
if ( F_12 ( ( F_6 ( V_2 , V_14 ) & V_17 ) == 0 ,
V_12 ) )
F_7 ( L_3 ) ;
F_9 ( V_2 , V_13 ,
F_18 ( V_17 ) ) ;
F_10 ( V_2 , V_9 ) ;
if ( F_12 ( ( F_6 ( V_2 , V_14 ) & V_17 ) ,
V_12 ) )
F_7 ( L_4 ) ;
F_4 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_18 ;
V_18 = F_6 ( V_2 , V_19 ) ;
if ( F_20 ( V_18 , L_5 , V_18 ) )
F_9 ( V_2 , V_19 , V_18 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
int V_10 )
{
F_9 ( V_2 , V_8 , 0 ) ;
F_10 ( V_2 , V_9 ) ;
F_19 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
int V_10 )
{
F_9 ( V_2 , V_13 ,
F_14 ( V_17 ) ) ;
F_10 ( V_2 , V_9 ) ;
if ( F_23 ( V_2 -> V_3 ) )
F_19 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
if ( F_25 ( V_2 -> V_3 ) )
V_2 -> V_21 . V_22 =
F_6 ( V_2 , V_23 ) &
V_24 ;
if ( V_2 -> V_21 . V_22 < V_25 ) {
int V_26 = 500 ;
T_1 V_27 = F_6 ( V_2 , V_23 ) & V_24 ;
while ( V_27 <= V_25 && V_26 -- ) {
F_26 ( 10 ) ;
V_27 = F_6 ( V_2 , V_23 ) & V_24 ;
}
if ( F_27 ( V_26 < 0 && V_27 <= V_25 ) )
++ V_20 ;
V_2 -> V_21 . V_22 = V_27 ;
}
V_2 -> V_21 . V_22 -- ;
return V_20 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_28 ,
F_14 ( 0xffff ) ) ;
F_9 ( V_2 , V_29 ,
F_14 ( 0xffff ) ) ;
F_10 ( V_2 , V_30 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
int V_10 )
{
if ( V_31 & V_10 ) {
if ( F_12 ( ( F_6 ( V_2 ,
V_30 ) &
V_17 ) == 0 ,
V_12 ) )
F_7 ( L_6 ) ;
F_9 ( V_2 , V_28 ,
F_18 ( V_17 ) ) ;
if ( F_12 ( ( F_6 ( V_2 ,
V_30 ) &
V_17 ) ,
V_12 ) )
F_7 ( L_7 ) ;
}
if ( V_32 & V_10 ) {
if ( F_12 ( ( F_6 ( V_2 ,
V_33 ) &
V_17 ) == 0 ,
V_12 ) )
F_7 ( L_8 ) ;
F_9 ( V_2 , V_29 ,
F_18 ( V_17 ) ) ;
if ( F_12 ( ( F_6 ( V_2 ,
V_33 ) &
V_17 ) ,
V_12 ) )
F_7 ( L_9 ) ;
}
}
static void F_30 ( struct V_1 * V_2 ,
int V_10 )
{
if ( V_31 & V_10 )
F_9 ( V_2 , V_28 ,
F_14 ( V_17 ) ) ;
if ( V_32 & V_10 )
F_9 ( V_2 , V_29 ,
F_14 ( V_17 ) ) ;
F_10 ( V_2 , V_30 ) ;
if ( ! F_31 ( V_2 -> V_3 ) )
F_19 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_10 )
{
unsigned long V_34 ;
F_33 ( & V_2 -> V_21 . V_35 , V_34 ) ;
if ( V_10 & V_31 &&
V_2 -> V_21 . V_36 ++ != 0 )
V_10 &= ~ V_31 ;
if ( V_10 & V_32 &&
V_2 -> V_21 . V_37 ++ != 0 )
V_10 &= ~ V_32 ;
if ( V_10 )
V_2 -> V_21 . V_38 . V_39 ( V_2 , V_10 ) ;
F_34 ( & V_2 -> V_21 . V_35 , V_34 ) ;
}
static void F_35 ( struct V_1 * V_2 , int V_10 )
{
unsigned long V_34 ;
F_33 ( & V_2 -> V_21 . V_35 , V_34 ) ;
if ( V_10 & V_31 ) {
F_27 ( ! V_2 -> V_21 . V_36 ) ;
if ( -- V_2 -> V_21 . V_36 != 0 )
V_10 &= ~ V_31 ;
}
if ( V_10 & V_32 ) {
F_27 ( ! V_2 -> V_21 . V_37 ) ;
if ( -- V_2 -> V_21 . V_37 != 0 )
V_10 &= ~ V_32 ;
}
if ( V_10 )
V_2 -> V_21 . V_38 . V_40 ( V_2 , V_10 ) ;
F_34 ( & V_2 -> V_21 . V_35 , V_34 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_41 ,
F_14 ( 0xffff ) ) ;
F_9 ( V_2 , V_42 ,
F_14 ( 0xffff ) ) ;
F_9 ( V_2 , V_43 ,
F_14 ( 0xffff ) ) ;
}
static void
F_37 ( struct V_1 * V_2 , int V_10 )
{
if ( V_31 & V_10 ) {
if ( F_12 ( ( F_6 ( V_2 ,
V_44 ) &
V_17 ) == 0 ,
V_12 ) )
F_7 ( L_6 ) ;
F_9 ( V_2 , V_41 ,
F_18 ( V_17 ) ) ;
if ( F_12 ( ( F_6 ( V_2 ,
V_44 ) &
V_17 ) ,
V_12 ) )
F_7 ( L_7 ) ;
}
if ( V_32 & V_10 ) {
if ( F_12 ( ( F_6 ( V_2 ,
V_45 ) &
V_17 ) == 0 ,
V_12 ) )
F_7 ( L_8 ) ;
F_9 ( V_2 , V_42 ,
F_18 ( V_17 ) ) ;
if ( F_12 ( ( F_6 ( V_2 ,
V_45 ) &
V_17 ) ,
V_12 ) )
F_7 ( L_10 ) ;
}
if ( V_46 & V_10 ) {
if ( F_12 ( ( F_6 ( V_2 ,
V_47 ) &
V_17 ) == 0 ,
V_12 ) )
F_7 ( L_11 ) ;
F_9 ( V_2 , V_43 ,
F_18 ( V_17 ) ) ;
if ( F_12 ( ( F_6 ( V_2 ,
V_47 ) &
V_17 ) ,
V_12 ) )
F_7 ( L_12 ) ;
}
}
static void
F_38 ( struct V_1 * V_2 , int V_10 )
{
if ( V_31 & V_10 )
F_9 ( V_2 , V_41 ,
F_14 ( V_17 ) ) ;
if ( V_32 & V_10 )
F_9 ( V_2 , V_42 ,
F_14 ( V_17 ) ) ;
if ( V_46 & V_10 )
F_9 ( V_2 , V_43 ,
F_14 ( V_17 ) ) ;
}
static void
F_39 ( struct V_1 * V_2 , int V_10 )
{
unsigned long V_34 ;
F_33 ( & V_2 -> V_21 . V_35 , V_34 ) ;
if ( V_31 & V_10 ) {
if ( V_2 -> V_21 . V_36 ++ == 0 )
V_2 -> V_21 . V_38 . V_39 ( V_2 ,
V_31 ) ;
}
if ( V_32 & V_10 ) {
if ( V_2 -> V_21 . V_37 ++ == 0 )
V_2 -> V_21 . V_38 . V_39 ( V_2 ,
V_32 ) ;
}
if ( V_46 & V_10 ) {
if ( V_2 -> V_21 . V_48 ++ == 0 )
V_2 -> V_21 . V_38 . V_39 ( V_2 ,
V_46 ) ;
}
F_34 ( & V_2 -> V_21 . V_35 , V_34 ) ;
}
static void
F_40 ( struct V_1 * V_2 , int V_10 )
{
unsigned long V_34 ;
F_33 ( & V_2 -> V_21 . V_35 , V_34 ) ;
if ( V_31 & V_10 ) {
F_27 ( V_2 -> V_21 . V_36 == 0 ) ;
if ( -- V_2 -> V_21 . V_36 == 0 )
V_2 -> V_21 . V_38 . V_40 ( V_2 ,
V_31 ) ;
}
if ( V_32 & V_10 ) {
F_27 ( V_2 -> V_21 . V_37 == 0 ) ;
if ( -- V_2 -> V_21 . V_37 == 0 )
V_2 -> V_21 . V_38 . V_40 ( V_2 ,
V_32 ) ;
}
if ( V_46 & V_10 ) {
F_27 ( V_2 -> V_21 . V_48 == 0 ) ;
if ( -- V_2 -> V_21 . V_48 == 0 )
V_2 -> V_21 . V_38 . V_40 ( V_2 ,
V_46 ) ;
}
F_34 ( & V_2 -> V_21 . V_35 , V_34 ) ;
}
static void F_41 ( unsigned long V_49 )
{
struct V_1 * V_2 = ( void * ) V_49 ;
unsigned long V_34 ;
F_1 ( V_2 ) ;
F_33 ( & V_2 -> V_21 . V_35 , V_34 ) ;
F_27 ( ! V_2 -> V_21 . V_50 ) ;
if ( -- V_2 -> V_21 . V_50 == 0 )
V_2 -> V_21 . V_38 . V_40 ( V_2 , V_51 ) ;
F_34 ( & V_2 -> V_21 . V_35 , V_34 ) ;
F_42 ( V_2 ) ;
}
void F_43 ( struct V_52 * V_3 , bool V_53 )
{
struct V_1 * V_2 = V_3 -> V_54 ;
unsigned long V_34 ;
if ( F_44 ( & V_2 -> V_21 . V_55 ) )
F_41 ( ( unsigned long ) V_2 ) ;
F_33 ( & V_2 -> V_21 . V_35 , V_34 ) ;
if ( F_25 ( V_3 ) )
F_28 ( V_2 ) ;
else if ( F_45 ( V_3 ) || F_23 ( V_3 ) )
F_8 ( V_2 ) ;
if ( F_46 ( V_3 ) || F_16 ( V_3 ) || F_17 ( V_3 ) )
F_13 ( V_2 ) ;
if ( F_47 ( V_3 ) )
F_36 ( V_2 ) ;
if ( V_53 ) {
unsigned V_56 = 0 ;
if ( F_25 ( V_3 ) ) {
if ( V_2 -> V_21 . V_36 )
V_56 |= V_31 ;
if ( V_2 -> V_21 . V_37 )
V_56 |= V_32 ;
} else if ( F_47 ( V_3 ) ) {
if ( V_2 -> V_21 . V_36 )
V_56 |= V_31 ;
if ( V_2 -> V_21 . V_37 )
V_56 |= V_32 ;
if ( V_2 -> V_21 . V_48 )
V_56 |= V_46 ;
} else {
if ( V_2 -> V_21 . V_50 )
V_56 = V_51 ;
}
if ( V_56 )
V_2 -> V_21 . V_38 . V_39 ( V_2 , V_56 ) ;
if ( F_45 ( V_3 ) || F_23 ( V_3 ) )
V_2 -> V_21 . V_22 =
F_6 ( V_2 , V_23 ) &
V_24 ;
}
F_34 ( & V_2 -> V_21 . V_35 , V_34 ) ;
}
static void F_48 ( struct V_52 * V_3 ,
bool V_57 )
{
struct V_1 * V_2 = V_3 -> V_54 ;
if ( F_49 ( V_3 ) )
F_9 ( V_2 , V_58 , V_59 ) ;
if ( ( F_16 ( V_3 ) || F_17 ( V_3 ) ) &&
( F_6 ( V_2 , V_60 ) == 1 ) ) {
V_2 -> V_61 = 128 ;
F_50 ( L_13 , V_2 -> V_61 ) ;
}
if ( F_45 ( V_3 ) || F_23 ( V_3 ) )
F_9 ( V_2 , V_19 ,
F_6 ( V_2 , V_19 ) ) ;
F_43 ( V_3 , V_57 ) ;
}
void F_51 ( struct V_52 * V_3 , bool V_57 )
{
F_48 ( V_3 , V_57 ) ;
F_52 ( V_3 ) ;
}
void F_53 ( struct V_52 * V_3 )
{
F_54 ( V_3 ) ;
}
void F_55 ( struct V_1 * V_2 , int V_10 )
{
unsigned long V_34 ;
if ( ! V_2 -> V_21 . V_38 . V_39 )
return;
F_56 ( V_2 ) ;
if ( F_47 ( V_2 -> V_3 ) )
return F_39 ( V_2 , V_10 ) ;
if ( F_25 ( V_2 -> V_3 ) )
return F_32 ( V_2 , V_10 ) ;
F_33 ( & V_2 -> V_21 . V_35 , V_34 ) ;
if ( V_2 -> V_21 . V_50 ++ == 0 )
V_2 -> V_21 . V_38 . V_39 ( V_2 , V_51 ) ;
F_34 ( & V_2 -> V_21 . V_35 , V_34 ) ;
}
void F_57 ( struct V_1 * V_2 , int V_10 )
{
unsigned long V_34 ;
bool V_62 = false ;
if ( ! V_2 -> V_21 . V_38 . V_40 )
return;
if ( F_47 ( V_2 -> V_3 ) ) {
F_40 ( V_2 , V_10 ) ;
goto V_63;
}
if ( F_25 ( V_2 -> V_3 ) ) {
F_35 ( V_2 , V_10 ) ;
goto V_63;
}
F_33 ( & V_2 -> V_21 . V_35 , V_34 ) ;
F_27 ( ! V_2 -> V_21 . V_50 ) ;
if ( -- V_2 -> V_21 . V_50 == 0 ) {
V_2 -> V_21 . V_50 ++ ;
V_62 = true ;
F_58 ( & V_2 -> V_21 . V_55 ,
V_64 + 1 ) ;
}
F_34 ( & V_2 -> V_21 . V_35 , V_34 ) ;
V_63:
if ( ! V_62 )
F_42 ( V_2 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_21 . V_38 . V_39 )
return;
F_27 ( V_2 -> V_21 . V_50 > 0 ) ;
}
static void
F_60 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_65 , 0 ) ;
}
static void
F_61 ( struct V_1 * V_2 , T_1 V_66 , bool V_67 ,
bool V_68 )
{
const char * V_69 = V_67 ? L_14 : L_15 ;
const char * V_70 = V_68 ? L_16 : L_17 ;
if ( ! V_71 . V_72 )
return;
if ( F_6 ( V_2 , V_58 ) & V_59 ) {
F_20 ( 1 , L_18 ,
V_70 , V_69 , V_66 ) ;
F_9 ( V_2 , V_58 , V_59 ) ;
}
}
static void
F_62 ( struct V_1 * V_2 )
{
if ( V_71 . V_72 )
return;
if ( F_6 ( V_2 , V_58 ) & V_59 ) {
F_7 ( L_19 ) ;
F_9 ( V_2 , V_58 , V_59 ) ;
}
}
static bool F_63 ( struct V_1 * V_2 , T_1 V_66 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < F_64 ( V_74 ) ; V_73 ++ )
if ( V_66 == V_74 [ V_73 ] )
return true ;
return false ;
}
static bool F_65 ( struct V_1 * V_2 , T_1 V_66 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < F_64 ( V_75 ) ; V_73 ++ )
if ( V_66 == V_75 [ V_73 ] )
return true ;
return false ;
}
void F_66 ( struct V_52 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_54 ;
F_67 ( & V_2 -> V_21 . V_55 ,
F_41 , ( unsigned long ) V_2 ) ;
F_48 ( V_3 , false ) ;
if ( F_47 ( V_3 ) ) {
V_2 -> V_21 . V_38 . V_39 = F_37 ;
V_2 -> V_21 . V_38 . V_40 = F_38 ;
} else if ( F_25 ( V_3 ) ) {
V_2 -> V_21 . V_38 . V_39 = F_29 ;
V_2 -> V_21 . V_38 . V_40 = F_30 ;
} else if ( F_16 ( V_3 ) || F_17 ( V_3 ) ) {
V_2 -> V_21 . V_38 . V_39 = F_15 ;
V_2 -> V_21 . V_38 . V_40 = F_22 ;
} else if ( F_46 ( V_3 ) ) {
T_1 V_76 ;
F_68 ( & V_3 -> V_77 ) ;
F_15 ( V_2 , V_51 ) ;
V_76 = F_6 ( V_2 , V_9 ) ;
F_22 ( V_2 , V_51 ) ;
F_69 ( & V_3 -> V_77 ) ;
if ( V_76 & V_78 ) {
V_2 -> V_21 . V_38 . V_39 =
F_15 ;
V_2 -> V_21 . V_38 . V_40 =
F_22 ;
} else {
F_50 ( L_20 ) ;
F_50 ( L_21 ) ;
V_2 -> V_21 . V_38 . V_39 =
F_11 ;
V_2 -> V_21 . V_38 . V_40 =
F_21 ;
}
} else if ( F_45 ( V_3 ) ) {
V_2 -> V_21 . V_38 . V_39 =
F_11 ;
V_2 -> V_21 . V_38 . V_40 =
F_21 ;
}
switch ( F_70 ( V_3 ) -> V_79 ) {
default:
F_27 ( 1 ) ;
return;
case 9 :
F_71 ( V_80 ) ;
F_72 ( V_80 ) ;
break;
case 8 :
if ( F_31 ( V_3 ) ) {
F_71 ( V_81 ) ;
F_72 ( V_81 ) ;
} else {
F_71 ( V_82 ) ;
F_72 ( V_83 ) ;
}
break;
case 7 :
case 6 :
if ( F_16 ( V_3 ) ) {
F_71 ( V_84 ) ;
} else {
F_71 ( V_83 ) ;
}
if ( F_25 ( V_3 ) ) {
F_72 ( V_85 ) ;
} else {
F_72 ( V_83 ) ;
}
break;
case 5 :
F_71 ( V_86 ) ;
F_72 ( V_86 ) ;
break;
case 4 :
case 3 :
case 2 :
F_71 ( V_87 ) ;
F_72 ( V_87 ) ;
break;
}
F_52 ( V_3 ) ;
}
void F_73 ( struct V_52 * V_3 )
{
F_53 ( V_3 ) ;
F_43 ( V_3 , false ) ;
}
int F_74 ( struct V_52 * V_3 ,
void * V_88 , struct V_89 * V_90 )
{
struct V_1 * V_2 = V_3 -> V_54 ;
struct V_91 * V_66 = V_88 ;
struct V_92 const * V_93 = V_94 ;
int V_73 , V_20 = 0 ;
for ( V_73 = 0 ; V_73 < F_64 ( V_94 ) ; V_73 ++ , V_93 ++ ) {
if ( V_93 -> V_95 == V_66 -> V_95 &&
( 1 << F_70 ( V_3 ) -> V_79 & V_93 -> V_96 ) )
break;
}
if ( V_73 == F_64 ( V_94 ) )
return - V_97 ;
F_56 ( V_2 ) ;
switch ( V_93 -> V_98 ) {
case 8 :
V_66 -> V_99 = F_75 ( V_66 -> V_95 ) ;
break;
case 4 :
V_66 -> V_99 = F_76 ( V_66 -> V_95 ) ;
break;
case 2 :
V_66 -> V_99 = F_77 ( V_66 -> V_95 ) ;
break;
case 1 :
V_66 -> V_99 = F_78 ( V_66 -> V_95 ) ;
break;
default:
F_27 ( 1 ) ;
V_20 = - V_97 ;
goto V_63;
}
V_63:
F_42 ( V_2 ) ;
return V_20 ;
}
int F_79 ( struct V_52 * V_3 ,
void * V_88 , struct V_89 * V_90 )
{
struct V_1 * V_2 = V_3 -> V_54 ;
struct V_100 * args = V_88 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
int V_20 ;
if ( args -> V_105 || args -> V_106 )
return - V_97 ;
if ( args -> V_107 == V_108 && ! F_80 ( V_109 ) )
return - V_110 ;
V_20 = F_81 ( & V_3 -> V_77 ) ;
if ( V_20 )
return V_20 ;
V_104 = F_82 ( V_90 -> V_111 , args -> V_107 ) ;
if ( F_83 ( V_104 ) ) {
F_69 ( & V_3 -> V_77 ) ;
return F_84 ( V_104 ) ;
}
V_102 = & V_104 -> V_112 ;
if ( F_80 ( V_109 ) )
args -> V_113 = F_85 ( & V_2 -> V_114 ) ;
else
args -> V_113 = 0 ;
args -> V_115 = V_102 -> V_115 ;
args -> V_116 = V_102 -> V_116 ;
F_69 ( & V_3 -> V_77 ) ;
return 0 ;
}
static int F_86 ( struct V_52 * V_3 )
{
T_2 V_117 ;
F_87 ( V_3 -> V_118 , V_119 , & V_117 ) ;
return ( V_117 & V_120 ) == 0 ;
}
static int F_88 ( struct V_52 * V_3 )
{
F_89 ( V_3 -> V_118 , V_119 , V_121 ) ;
F_26 ( 20 ) ;
F_89 ( V_3 -> V_118 , V_119 , 0 ) ;
return F_90 ( F_86 ( V_3 ) , 500 ) ;
}
static int F_91 ( struct V_52 * V_3 )
{
T_2 V_117 ;
F_87 ( V_3 -> V_118 , V_119 , & V_117 ) ;
return ( V_117 & V_121 ) == 0 ;
}
static int F_92 ( struct V_52 * V_3 )
{
F_89 ( V_3 -> V_118 , V_119 , V_121 ) ;
return F_90 ( F_91 ( V_3 ) , 500 ) ;
}
static int F_93 ( struct V_52 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_54 ;
int V_20 ;
F_89 ( V_3 -> V_118 , V_119 ,
V_122 | V_121 ) ;
V_20 = F_90 ( F_91 ( V_3 ) , 500 ) ;
if ( V_20 )
return V_20 ;
F_94 ( V_123 , F_76 ( V_123 ) | V_124 ) ;
F_95 ( V_123 ) ;
F_89 ( V_3 -> V_118 , V_119 ,
V_125 | V_121 ) ;
V_20 = F_90 ( F_91 ( V_3 ) , 500 ) ;
if ( V_20 )
return V_20 ;
F_94 ( V_123 , F_76 ( V_123 ) & ~ V_124 ) ;
F_95 ( V_123 ) ;
F_89 ( V_3 -> V_118 , V_119 , 0 ) ;
return 0 ;
}
static int F_96 ( struct V_52 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_54 ;
int V_20 ;
F_94 ( V_126 + V_127 ,
V_128 | V_129 ) ;
V_20 = F_90 ( ( F_76 ( V_126 + V_127 ) &
V_129 ) == 0 , 500 ) ;
if ( V_20 )
return V_20 ;
F_94 ( V_126 + V_127 ,
V_130 | V_129 ) ;
V_20 = F_90 ( ( F_76 ( V_126 + V_127 ) &
V_129 ) == 0 , 500 ) ;
if ( V_20 )
return V_20 ;
F_94 ( V_126 + V_127 , 0 ) ;
return 0 ;
}
static int F_97 ( struct V_52 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_54 ;
int V_20 ;
F_9 ( V_2 , V_131 , V_132 ) ;
V_20 = F_90 ( ( F_6 ( V_2 , V_131 ) & V_132 ) == 0 , 500 ) ;
F_43 ( V_3 , true ) ;
return V_20 ;
}
int F_98 ( struct V_52 * V_3 )
{
if ( F_70 ( V_3 ) -> V_79 >= 6 )
return F_97 ( V_3 ) ;
else if ( F_99 ( V_3 ) )
return F_96 ( V_3 ) ;
else if ( F_100 ( V_3 ) )
return F_93 ( V_3 ) ;
else if ( F_101 ( V_3 ) )
return F_92 ( V_3 ) ;
else if ( F_70 ( V_3 ) -> V_79 >= 3 )
return F_88 ( V_3 ) ;
else
return - V_133 ;
}
void F_102 ( struct V_52 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_54 ;
if ( F_49 ( V_3 ) &&
( F_6 ( V_2 , V_58 ) & V_59 ) ) {
F_7 ( L_22 ) ;
F_9 ( V_2 , V_58 , V_59 ) ;
}
}
