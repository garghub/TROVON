static int F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
if ( F_3 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) )
return 0 ;
V_8 = F_4 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] , V_4 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_1 ,
V_13 , V_4 , V_8 ) ;
return V_8 ;
}
static int F_6 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
if ( ! F_3 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) ) {
V_8 = F_7 (
V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_2 ,
V_13 , V_8 ) ;
return V_8 ;
}
}
V_8 = F_7 ( V_7 -> V_16 [ V_2 -> V_10 -> V_11 ] ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_3 ,
V_13 , V_8 ) ;
if ( ! F_3 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) )
F_8 (
V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) ;
return V_8 ;
}
return 0 ;
}
static void F_9 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_8 ( V_7 -> V_16 [ V_2 -> V_10 -> V_11 ] ) ;
if ( ! F_3 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) )
F_8 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) ;
}
static int F_10 ( struct V_14 * V_15 ,
struct V_17 * V_18 , struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_19 = F_11 ( V_18 ) ;
unsigned int V_20 = F_12 ( V_18 ) ;
unsigned int V_21 = F_13 ( V_18 ) ;
unsigned int V_22 ;
int V_23 , V_8 ;
V_23 = F_14 ( V_19 ) ;
if ( V_23 < 0 ) {
F_5 ( V_2 -> V_12 , L_4 ,
V_13 , V_23 ) ;
return V_23 ;
}
V_22 = V_24 |
V_25 ;
switch ( V_23 ) {
case 16 :
V_22 |= V_26 ;
break;
case 24 :
V_22 |= V_27 ;
break;
case 32 :
V_22 |= V_28 ;
break;
default:
F_5 ( V_2 -> V_12 , L_5 ,
V_13 , V_23 ) ;
return - V_29 ;
}
if ( V_15 -> V_30 == V_31 ) {
switch ( V_20 ) {
case 1 :
V_22 |= V_32 ;
V_22 |= V_33 ;
break;
case 2 :
V_22 |= V_32 ;
V_22 |= V_34 ;
break;
case 4 :
V_22 |= V_35 ;
V_22 |= V_34 ;
break;
case 6 :
V_22 |= V_36 ;
V_22 |= V_34 ;
break;
case 8 :
V_22 |= V_37 ;
V_22 |= V_34 ;
break;
default:
F_5 ( V_2 -> V_12 , L_6 ,
V_13 , V_20 ) ;
return - V_29 ;
}
} else {
switch ( V_20 ) {
case 1 :
V_22 |= V_38 ;
V_22 |= V_39 ;
break;
case 2 :
V_22 |= V_38 ;
V_22 |= V_40 ;
break;
case 4 :
V_22 |= V_41 ;
V_22 |= V_40 ;
break;
case 6 :
V_22 |= V_42 ;
V_22 |= V_40 ;
break;
case 8 :
V_22 |= V_43 ;
V_22 |= V_40 ;
break;
default:
F_5 ( V_2 -> V_12 , L_6 ,
V_13 , V_20 ) ;
return - V_29 ;
}
}
V_8 = F_15 ( V_7 -> V_44 ,
F_16 ( V_7 -> V_45 , V_2 -> V_10 -> V_11 ) ,
V_22 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
return V_8 ;
}
V_8 = F_4 ( V_7 -> V_16 [ V_2 -> V_10 -> V_11 ] ,
V_21 * V_23 * 2 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_8 ,
V_13 , V_21 * V_23 * 2 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_17 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_15 ( V_7 -> V_44 ,
F_16 ( V_7 -> V_45 , V_2 -> V_10 -> V_11 ) ,
0 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
return V_8 ;
}
static int F_18 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
unsigned int V_46 , V_47 ;
if ( V_15 -> V_30 == V_31 ) {
V_46 = V_48 ;
V_47 = V_49 ;
} else {
V_46 = V_50 ;
V_47 = V_51 ;
}
V_8 = F_19 ( V_7 -> V_44 ,
F_16 ( V_7 -> V_45 , V_2 -> V_10 -> V_11 ) ,
V_47 , V_46 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
return V_8 ;
}
static int F_20 ( struct V_14 * V_15 ,
int V_52 , struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = - V_29 ;
unsigned int V_46 , V_47 ;
switch ( V_52 ) {
case V_53 :
case V_54 :
case V_55 :
if ( V_15 -> V_30 == V_31 ) {
V_46 = V_48 ;
V_47 = V_49 ;
} else {
V_46 = V_50 ;
V_47 = V_51 ;
}
V_8 = F_19 ( V_7 -> V_44 ,
F_16 ( V_7 -> V_45 ,
V_2 -> V_10 -> V_11 ) ,
V_47 , V_46 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
break;
case V_56 :
case V_57 :
case V_58 :
if ( V_15 -> V_30 == V_31 ) {
V_46 = V_59 ;
V_47 = V_49 ;
} else {
V_46 = V_60 ;
V_47 = V_51 ;
}
V_8 = F_19 ( V_7 -> V_44 ,
F_16 ( V_7 -> V_45 ,
V_2 -> V_10 -> V_11 ) ,
V_47 , V_46 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
break;
}
return V_8 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_15 ( V_7 -> V_44 ,
F_16 ( V_7 -> V_45 , V_2 -> V_10 -> V_11 ) , 0 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
return V_8 ;
}
static bool F_22 ( struct V_61 * V_12 , unsigned int V_62 )
{
struct V_6 * V_7 = F_23 ( V_12 ) ;
struct V_63 * V_64 = V_7 -> V_45 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_64 -> V_66 ; ++ V_65 )
if ( V_62 == F_16 ( V_64 , V_65 ) )
return true ;
for ( V_65 = 0 ; V_65 < V_64 -> V_67 ; ++ V_65 ) {
if ( V_62 == F_24 ( V_64 , V_65 ) )
return true ;
if ( V_62 == F_25 ( V_64 , V_65 ) )
return true ;
}
for ( V_65 = 0 ; V_65 < V_64 -> V_68 ; ++ V_65 ) {
if ( V_62 == F_26 ( V_64 , V_65 ) )
return true ;
if ( V_62 == F_27 ( V_64 , V_65 ) )
return true ;
if ( V_62 == F_28 ( V_64 , V_65 ) )
return true ;
if ( V_62 == F_29 ( V_64 , V_65 ) )
return true ;
}
for ( V_65 = 0 ; V_65 < V_64 -> V_69 ; ++ V_65 ) {
if ( V_62 == F_30 ( V_64 , V_65 + V_64 -> V_70 ) )
return true ;
if ( V_62 == F_31 ( V_64 , V_65 + V_64 -> V_70 ) )
return true ;
if ( V_62 == F_32 ( V_64 , V_65 + V_64 -> V_70 ) )
return true ;
if ( V_62 == F_33 ( V_64 , V_65 + V_64 -> V_70 ) )
return true ;
}
return false ;
}
static bool F_34 ( struct V_61 * V_12 , unsigned int V_62 )
{
struct V_6 * V_7 = F_23 ( V_12 ) ;
struct V_63 * V_64 = V_7 -> V_45 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_64 -> V_66 ; ++ V_65 )
if ( V_62 == F_16 ( V_64 , V_65 ) )
return true ;
for ( V_65 = 0 ; V_65 < V_64 -> V_67 ; ++ V_65 ) {
if ( V_62 == F_24 ( V_64 , V_65 ) )
return true ;
if ( V_62 == F_35 ( V_64 , V_65 ) )
return true ;
}
for ( V_65 = 0 ; V_65 < V_64 -> V_68 ; ++ V_65 ) {
if ( V_62 == F_26 ( V_64 , V_65 ) )
return true ;
if ( V_62 == F_27 ( V_64 , V_65 ) )
return true ;
if ( V_62 == F_28 ( V_64 , V_65 ) )
return true ;
if ( V_62 == F_36 ( V_64 , V_65 ) )
return true ;
if ( V_62 == F_29 ( V_64 , V_65 ) )
return true ;
}
for ( V_65 = 0 ; V_65 < V_64 -> V_69 ; ++ V_65 ) {
if ( V_62 == F_30 ( V_64 , V_65 + V_64 -> V_70 ) )
return true ;
if ( V_62 == F_31 ( V_64 , V_65 + V_64 -> V_70 ) )
return true ;
if ( V_62 == F_32 ( V_64 , V_65 + V_64 -> V_70 ) )
return true ;
if ( V_62 == F_37 ( V_64 , V_65 + V_64 -> V_70 ) )
return true ;
if ( V_62 == F_33 ( V_64 , V_65 + V_64 -> V_70 ) )
return true ;
}
return false ;
}
static bool F_38 ( struct V_61 * V_12 , unsigned int V_62 )
{
struct V_6 * V_7 = F_23 ( V_12 ) ;
struct V_63 * V_64 = V_7 -> V_45 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_64 -> V_67 ; ++ V_65 )
if ( V_62 == F_35 ( V_64 , V_65 ) )
return true ;
for ( V_65 = 0 ; V_65 < V_64 -> V_68 ; ++ V_65 )
if ( V_62 == F_36 ( V_64 , V_65 ) )
return true ;
for ( V_65 = 0 ; V_65 < V_64 -> V_69 ; ++ V_65 )
if ( V_62 == F_37 ( V_64 , V_65 + V_64 -> V_70 ) )
return true ;
return false ;
}
int F_39 ( struct V_71 * V_72 )
{
struct V_6 * V_7 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
struct V_63 * V_45 ;
struct V_61 * V_12 = & V_72 -> V_12 ;
const struct V_77 * V_78 ;
char V_79 [ 16 ] ;
int V_8 , V_65 , V_80 ;
V_74 = F_40 ( V_72 -> V_12 . V_81 , L_9 , 0 ) ;
if ( V_74 ) {
F_5 ( & V_72 -> V_12 , L_10 ,
V_13 ) ;
return - V_82 ;
}
V_7 = F_41 ( & V_72 -> V_12 , sizeof( struct V_6 ) ,
V_83 ) ;
if ( ! V_7 )
return - V_84 ;
F_42 ( V_72 , V_7 ) ;
V_78 = F_43 ( V_12 -> V_10 -> V_85 , V_12 ) ;
if ( ! V_78 || ! V_78 -> V_86 )
return - V_29 ;
V_7 -> V_45 = (struct V_63 * ) V_78 -> V_86 ;
V_45 = V_7 -> V_45 ;
V_76 = F_44 ( V_72 , V_87 , L_11 ) ;
V_7 -> V_88 = F_45 ( & V_72 -> V_12 , V_76 ) ;
if ( F_3 ( ( void const V_89 * ) V_7 -> V_88 ) ) {
F_5 ( & V_72 -> V_12 , L_12 ,
V_13 ,
F_46 ( ( void const V_89 * ) V_7 -> V_88 ) ) ;
return F_46 ( ( void const V_89 * ) V_7 -> V_88 ) ;
}
V_90 . V_91 = F_33 ( V_45 ,
V_45 -> V_69 +
V_45 -> V_70 ) ;
V_7 -> V_44 = F_47 ( & V_72 -> V_12 , V_7 -> V_88 ,
& V_90 ) ;
if ( F_3 ( V_7 -> V_44 ) ) {
F_5 ( & V_72 -> V_12 , L_13 ,
V_13 , F_46 ( V_7 -> V_44 ) ) ;
return F_46 ( V_7 -> V_44 ) ;
}
if ( V_45 -> V_92 )
V_45 -> V_92 ( V_72 ) ;
for ( V_65 = 0 ; V_65 < V_45 -> V_93 ; V_65 ++ ) {
V_80 = V_45 -> V_94 [ V_65 ] . V_11 ;
if ( V_45 -> V_93 > 1 )
sprintf ( V_79 , L_14 , V_65 ) ;
else
sprintf ( V_79 , L_15 ) ;
V_7 -> V_9 [ V_80 ] = F_48 ( & V_72 -> V_12 ,
V_79 ) ;
if ( F_3 ( V_7 -> V_9 [ V_80 ] ) ) {
F_49 ( & V_72 -> V_12 ,
L_16 ,
V_13 ,
F_46 ( V_7 -> V_9 [ V_80 ] ) ) ;
}
if ( V_45 -> V_93 > 1 )
sprintf ( V_79 , L_17 , V_65 ) ;
else
sprintf ( V_79 , L_18 ) ;
V_7 -> V_16 [ V_80 ] = F_48 ( & V_72 -> V_12 ,
V_79 ) ;
if ( F_3 ( V_7 -> V_16 [ V_80 ] ) ) {
F_5 ( & V_72 -> V_12 ,
L_19 ,
V_13 ,
F_46 ( V_7 -> V_16 [ V_80 ] ) ) ;
return F_46 ( V_7 -> V_16 [ V_80 ] ) ;
}
}
V_7 -> V_95 = F_48 ( & V_72 -> V_12 , L_20 ) ;
if ( F_3 ( V_7 -> V_95 ) ) {
F_5 ( & V_72 -> V_12 , L_21 ,
V_13 , F_46 ( V_7 -> V_95 ) ) ;
return F_46 ( V_7 -> V_95 ) ;
}
V_8 = F_4 ( V_7 -> V_95 , V_96 ) ;
if ( V_8 ) {
F_5 ( & V_72 -> V_12 , L_22 ,
V_13 , V_8 ) ;
return V_8 ;
}
F_50 ( & V_72 -> V_12 , L_23 , V_13 ,
F_51 ( V_7 -> V_95 ) ) ;
V_8 = F_7 ( V_7 -> V_95 ) ;
if ( V_8 ) {
F_5 ( & V_72 -> V_12 , L_24 ,
V_13 , V_8 ) ;
return V_8 ;
}
V_8 = F_52 ( & V_72 -> V_12 ,
& V_97 ,
V_45 -> V_94 ,
V_45 -> V_93 ) ;
if ( V_8 ) {
F_5 ( & V_72 -> V_12 , L_25 ,
V_13 , V_8 ) ;
goto V_98;
}
V_8 = F_53 ( V_72 ) ;
if ( V_8 ) {
F_5 ( & V_72 -> V_12 , L_26 ,
V_13 , V_8 ) ;
goto V_98;
}
return 0 ;
V_98:
F_8 ( V_7 -> V_95 ) ;
return V_8 ;
}
int F_54 ( struct V_71 * V_72 )
{
struct V_6 * V_7 = F_55 ( V_72 ) ;
if ( V_7 -> V_45 -> exit )
V_7 -> V_45 -> exit ( V_72 ) ;
F_8 ( V_7 -> V_95 ) ;
return 0 ;
}
