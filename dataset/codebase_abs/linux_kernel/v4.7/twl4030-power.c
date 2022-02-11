static int F_1 ( T_1 V_1 , T_1 V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 , V_1 , V_5 ) ;
if ( V_3 )
goto V_6;
V_3 = F_2 ( V_4 , V_2 , V_7 ) ;
V_6:
return V_3 ;
}
static int F_3 ( T_1 V_1 , T_2 V_8 ,
T_1 V_9 , T_1 V_10 )
{
int V_3 ;
V_1 *= 4 ;
V_3 = F_1 ( V_1 ++ , V_8 >> 8 ) ;
if ( V_3 )
goto V_6;
V_3 = F_1 ( V_1 ++ , V_8 & 0xff ) ;
if ( V_3 )
goto V_6;
V_3 = F_1 ( V_1 ++ , V_9 ) ;
if ( V_3 )
goto V_6;
V_3 = F_1 ( V_1 ++ , V_10 ) ;
V_6:
return V_3 ;
}
static int F_4 ( T_1 V_1 , struct V_11 * V_12 ,
int V_13 )
{
int V_3 = - V_14 ;
for (; V_13 ; V_13 -- , V_1 ++ , V_12 ++ ) {
if ( V_13 == 1 ) {
V_3 = F_3 ( V_1 ,
V_12 -> V_8 ,
V_12 -> V_9 ,
V_15 ) ;
if ( V_3 )
break;
} else {
V_3 = F_3 ( V_1 ,
V_12 -> V_8 ,
V_12 -> V_9 ,
V_1 + 1 ) ;
if ( V_3 )
break;
}
}
return V_3 ;
}
static int F_5 ( T_1 V_1 )
{
int V_3 ;
T_1 V_16 ;
V_3 = F_2 ( V_4 , V_1 , V_17 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_16 , V_18 ) ;
if ( V_3 )
goto V_6;
V_16 |= V_19 ;
V_3 = F_2 ( V_4 , V_16 , V_18 ) ;
V_6:
if ( V_3 )
F_7 ( L_1 ) ;
return V_3 ;
}
static int
F_8 ( const struct V_20 * V_21 ,
T_1 V_1 )
{
int V_3 = 0 ;
T_1 V_16 ;
V_3 = F_2 ( V_4 , V_1 , V_22 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_16 , V_23 ) ;
if ( V_3 )
goto V_6;
V_16 |= V_19 ;
V_3 = F_2 ( V_4 , V_16 , V_23 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_16 , V_24 ) ;
if ( V_3 )
goto V_6;
V_16 |= V_19 ;
V_3 = F_2 ( V_4 , V_16 , V_24 ) ;
if ( V_3 )
goto V_6;
if ( V_21 -> V_25 || F_9 () ||
F_10 () ) {
V_3 = F_6 ( V_4 , & V_16 ,
V_26 ) ;
if ( V_3 )
goto V_6;
V_16 &= ~ V_27 ;
V_3 = F_2 ( V_4 , V_16 ,
V_26 ) ;
if ( V_3 )
goto V_6;
}
V_6:
if ( V_3 )
F_7 ( L_2 \
L_3 ) ;
return V_3 ;
}
static int F_11 ( T_1 V_1 )
{
int V_3 ;
V_3 = F_2 ( V_4 , V_1 , V_28 ) ;
if ( V_3 )
F_7 ( L_4 ) ;
return V_3 ;
}
static int F_12 ( T_1 V_1 )
{
int V_3 ;
T_1 V_29 ;
V_3 = F_2 ( V_4 , V_1 , V_30 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_29 , V_23 ) ;
if ( V_3 )
goto V_6;
V_29 |= V_31 ;
V_3 = F_2 ( V_4 , V_29 , V_23 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_29 , V_24 ) ;
if ( V_3 )
goto V_6;
V_29 |= V_31 ;
V_3 = F_2 ( V_4 , V_29 , V_24 ) ;
if ( V_3 )
goto V_6;
V_3 = F_6 ( V_4 , & V_29 , V_18 ) ;
if ( V_3 )
goto V_6;
V_29 |= V_31 ;
V_3 = F_2 ( V_4 , V_29 , V_18 ) ;
V_6:
if ( V_3 )
F_7 ( L_5 ) ;
return V_3 ;
}
static int F_13 ( struct V_32 * V_33 )
{
int V_34 ;
int V_3 ;
T_1 type ;
T_1 V_35 ;
T_1 V_36 ;
if ( V_33 -> V_37 > V_38 ) {
F_7 ( L_6 ,
V_33 -> V_37 ) ;
return - V_14 ;
}
V_34 = V_39 [ V_33 -> V_37 ] ;
V_3 = F_6 ( V_40 , & V_35 ,
V_34 + V_41 ) ;
if ( V_3 ) {
F_7 ( L_7 ,
V_33 -> V_37 ) ;
return V_3 ;
}
if ( V_33 -> V_42 != V_43 ) {
V_35 &= ~ V_44 ;
V_35 |= V_33 -> V_42 << V_45 ;
V_3 = F_2 ( V_40 ,
V_35 , V_34 + V_41 ) ;
if ( V_3 < 0 ) {
F_7 ( L_8 ) ;
return V_3 ;
}
}
V_3 = F_6 ( V_40 , & type ,
V_34 + V_46 ) ;
if ( V_3 < 0 ) {
F_7 ( L_9 ,
V_33 -> V_37 ) ;
return V_3 ;
}
if ( V_33 -> type != V_43 ) {
type &= ~ V_47 ;
type |= V_33 -> type << V_48 ;
}
if ( V_33 -> V_49 != V_43 ) {
type &= ~ V_50 ;
type |= V_33 -> V_49 << V_51 ;
}
V_3 = F_2 ( V_40 ,
type , V_34 + V_46 ) ;
if ( V_3 < 0 ) {
F_7 ( L_10 ) ;
return V_3 ;
}
V_3 = F_6 ( V_40 , & V_36 ,
V_34 + V_52 ) ;
if ( V_3 < 0 ) {
F_7 ( L_11 ,
V_33 -> V_37 ) ;
return V_3 ;
}
if ( V_33 -> V_53 != V_43 ) {
V_36 &= ~ V_54 ;
V_36 |= V_33 -> V_53 << V_55 ;
}
if ( V_33 -> V_56 != V_43 ) {
V_36 &= ~ V_57 ;
V_36 |= V_33 -> V_56 << V_58 ;
}
V_3 = F_2 ( V_40 ,
V_36 ,
V_34 + V_52 ) ;
if ( V_3 < 0 ) {
F_7 ( L_12 ) ;
return V_3 ;
}
return 0 ;
}
static int F_14 ( const struct V_20 * V_21 ,
struct V_59 * V_60 ,
T_1 V_1 )
{
int V_3 ;
static int V_61 ;
if ( ( V_1 + V_60 -> V_62 ) > V_15 ) {
F_7 ( L_13 ) ;
return - V_14 ;
}
V_3 = F_4 ( V_1 , V_60 -> V_12 , V_60 -> V_62 ) ;
if ( V_3 )
goto V_6;
if ( V_60 -> V_63 & V_64 ) {
V_3 = F_12 ( V_1 ) ;
if ( V_3 )
goto V_6;
}
if ( V_60 -> V_63 & V_65 ) {
V_3 = F_2 ( V_4 , V_15 ,
V_28 ) ;
if ( V_3 )
goto V_6;
V_3 = F_8 ( V_21 , V_1 ) ;
if ( V_3 )
goto V_6;
V_61 = 1 ;
}
if ( V_60 -> V_63 & V_66 ) {
V_3 = F_5 ( V_1 ) ;
if ( V_3 )
goto V_6;
}
if ( V_60 -> V_63 & V_67 ) {
if ( ! V_61 )
F_15 ( L_14\
L_15\
L_16 ) ;
V_3 = F_11 ( V_1 ) ;
}
V_6:
return V_3 ;
}
int F_16 ( T_1 V_63 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_4 , V_68 ,
V_69 ) ;
if ( V_3 ) {
F_7 ( L_17 ) ;
return V_3 ;
}
V_3 = F_2 ( V_4 , V_70 ,
V_69 ) ;
if ( V_3 ) {
F_7 ( L_17 ) ;
return V_3 ;
}
if ( V_63 & V_64 ) {
V_3 = F_2 ( V_4 , V_15 ,
V_30 ) ;
if ( V_3 )
return V_3 ;
}
if ( V_63 & V_65 ) {
V_3 = F_2 ( V_4 , V_15 ,
V_22 ) ;
if ( V_3 )
return V_3 ;
}
if ( V_63 & V_66 ) {
V_3 = F_2 ( V_4 , V_15 ,
V_17 ) ;
if ( V_3 )
return V_3 ;
}
if ( V_63 & V_67 ) {
V_3 = F_2 ( V_4 , V_15 ,
V_28 ) ;
if ( V_3 )
return V_3 ;
}
V_3 = F_2 ( V_4 , 0 ,
V_69 ) ;
if ( V_3 )
F_7 ( L_18 ) ;
return V_3 ;
}
static int
F_17 ( const struct V_20 * V_21 )
{
int V_3 ;
int V_71 ;
T_1 V_1 = V_72 ;
for ( V_71 = 0 ; V_71 < V_21 -> V_73 ; V_71 ++ ) {
V_3 = F_14 ( V_21 , V_21 -> V_74 [ V_71 ] , V_1 ) ;
if ( V_3 )
return V_3 ;
V_1 += V_21 -> V_74 [ V_71 ] -> V_62 ;
}
return 0 ;
}
static void F_18 ( struct V_32 * V_75 ,
struct V_32 * V_76 )
{
while ( V_75 -> V_37 ) {
struct V_32 * V_77 = V_76 ;
while ( V_77 -> V_37 ) {
if ( V_77 -> V_37 == V_75 -> V_37 ) {
* V_75 = * V_77 ;
break;
}
V_77 ++ ;
}
V_75 ++ ;
}
}
static int
F_19 ( const struct V_20 * V_21 )
{
struct V_32 * V_78 = V_21 -> V_79 ;
struct V_32 * V_80 = V_21 -> V_81 ;
int V_3 ;
if ( V_78 ) {
if ( V_80 )
F_18 ( V_78 , V_80 ) ;
while ( V_78 -> V_37 ) {
V_3 = F_13 ( V_78 ) ;
if ( V_3 )
return V_3 ;
V_78 ++ ;
}
}
return 0 ;
}
static int F_20 ( T_1 V_82 , T_1 V_83 )
{
T_1 V_84 [ 3 ] = { V_85 ,
V_86 ,
V_87 , } ;
T_1 V_88 ;
int V_71 , V_3 ;
V_3 = F_2 ( V_4 , V_68 ,
V_69 ) ;
if ( V_3 )
goto V_89;
V_3 = F_2 ( V_4 ,
V_70 ,
V_69 ) ;
if ( V_3 )
goto V_89;
for ( V_71 = 0 ; V_71 < sizeof( V_84 ) ; V_71 ++ ) {
V_3 = F_6 ( V_4 ,
& V_88 , V_84 [ V_71 ] ) ;
if ( V_3 )
break;
V_88 = ( ~ V_82 & V_88 ) | ( V_82 & V_83 ) ;
V_3 = F_2 ( V_4 ,
V_88 , V_84 [ V_71 ] ) ;
if ( V_3 )
break;
}
if ( V_3 )
F_7 ( L_19 , V_3 ) ;
V_89:
return F_2 ( V_4 , 0 ,
V_69 ) ;
}
void F_21 ( void )
{
int V_3 ;
V_3 = F_20 ( V_90 | V_27 , 0 ) ;
if ( V_3 )
F_7 ( L_20 ) ;
V_3 = F_2 ( V_4 , V_91 ,
V_92 ) ;
if ( V_3 )
F_7 ( L_21 ) ;
}
static bool F_22 ( const struct V_20 * V_21 ,
struct V_93 * V_94 )
{
if ( V_21 && V_21 -> V_95 )
return true ;
if ( F_23 ( V_94 , L_22 ) )
return true ;
if ( F_23 ( V_94 , L_23 ) )
return true ;
return false ;
}
static int F_24 ( struct V_96 * V_97 )
{
const struct V_20 * V_21 = F_25 ( & V_97 -> V_98 ) ;
struct V_93 * V_94 = V_97 -> V_98 . V_99 ;
const struct V_100 * V_101 ;
int V_3 = 0 ;
int V_102 = 0 ;
T_1 V_88 ;
if ( ! V_21 && ! V_94 ) {
F_26 ( & V_97 -> V_98 , L_24 ) ;
return - V_14 ;
}
V_3 = F_2 ( V_4 , V_68 ,
V_69 ) ;
V_3 |= F_2 ( V_4 ,
V_70 ,
V_69 ) ;
if ( V_3 ) {
F_7 ( L_25 ) ;
return V_3 ;
}
V_101 = F_27 ( F_28 ( V_103 ) ,
& V_97 -> V_98 ) ;
if ( V_101 && V_101 -> V_16 )
V_21 = V_101 -> V_16 ;
if ( V_21 ) {
V_3 = F_17 ( V_21 ) ;
if ( V_3 ) {
F_7 ( L_26 ) ;
goto V_89;
}
V_3 = F_19 ( V_21 ) ;
if ( V_3 ) {
F_7 ( L_27 ) ;
goto V_89;
}
}
if ( F_22 ( V_21 , V_94 ) && ! V_104 ) {
V_3 = F_6 ( V_4 , & V_88 ,
V_105 ) ;
if ( V_3 ) {
F_15 ( L_28 ) ;
} else if ( ! ( V_88 & V_106 ) ) {
V_88 |= V_106 ;
V_3 = F_2 ( V_4 , V_88 ,
V_105 ) ;
if ( V_3 ) {
F_7 ( L_29 ) ;
goto V_89;
}
}
V_104 = F_21 ;
}
V_89:
V_102 = F_2 ( V_4 , 0 ,
V_69 ) ;
if ( V_102 ) {
F_7 ( L_18 ) ;
return V_102 ;
}
return V_3 ;
}
static int F_29 ( struct V_96 * V_97 )
{
return 0 ;
}
