static int F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_3 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] , V_4 ) ;
if ( V_8 )
F_4 ( V_2 -> V_12 , L_1 ,
V_4 , V_8 ) ;
return V_8 ;
}
static int F_5 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_6 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_12 , L_2 , V_8 ) ;
return V_8 ;
}
V_8 = F_6 ( V_7 -> V_15 [ V_2 -> V_10 -> V_11 ] ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_12 , L_3 , V_8 ) ;
F_7 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) ;
return V_8 ;
}
return 0 ;
}
static void F_8 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( V_7 -> V_15 [ V_2 -> V_10 -> V_11 ] ) ;
F_7 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) ;
}
static int F_9 ( struct V_13 * V_14 ,
struct V_16 * V_17 , struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_18 = F_10 ( V_17 ) ;
unsigned int V_19 = F_11 ( V_17 ) ;
unsigned int V_20 = F_12 ( V_17 ) ;
unsigned int V_21 ;
int V_22 , V_8 ;
V_22 = F_13 ( V_18 ) ;
if ( V_22 < 0 ) {
F_4 ( V_2 -> V_12 , L_4 , V_22 ) ;
return V_22 ;
}
V_21 = V_23 |
V_24 ;
switch ( V_22 ) {
case 16 :
V_21 |= V_25 ;
break;
case 24 :
V_21 |= V_26 ;
break;
case 32 :
V_21 |= V_27 ;
break;
default:
F_4 ( V_2 -> V_12 , L_5 , V_22 ) ;
return - V_28 ;
}
if ( V_14 -> V_29 == V_30 ) {
switch ( V_19 ) {
case 1 :
V_21 |= V_31 ;
V_21 |= V_32 ;
break;
case 2 :
V_21 |= V_31 ;
V_21 |= V_33 ;
break;
case 4 :
V_21 |= V_34 ;
V_21 |= V_33 ;
break;
case 6 :
V_21 |= V_35 ;
V_21 |= V_33 ;
break;
case 8 :
V_21 |= V_36 ;
V_21 |= V_33 ;
break;
default:
F_4 ( V_2 -> V_12 , L_6 ,
V_19 ) ;
return - V_28 ;
}
} else {
switch ( V_19 ) {
case 1 :
V_21 |= V_37 ;
V_21 |= V_38 ;
break;
case 2 :
V_21 |= V_37 ;
V_21 |= V_39 ;
break;
case 4 :
V_21 |= V_40 ;
V_21 |= V_39 ;
break;
case 6 :
V_21 |= V_41 ;
V_21 |= V_39 ;
break;
case 8 :
V_21 |= V_42 ;
V_21 |= V_39 ;
break;
default:
F_4 ( V_2 -> V_12 , L_6 ,
V_19 ) ;
return - V_28 ;
}
}
V_8 = F_14 ( V_7 -> V_43 ,
F_15 ( V_7 -> V_44 , V_2 -> V_10 -> V_11 ) ,
V_21 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_12 , L_7 , V_8 ) ;
return V_8 ;
}
V_8 = F_3 ( V_7 -> V_15 [ V_2 -> V_10 -> V_11 ] ,
V_20 * V_22 * 2 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_12 , L_8 ,
V_20 * V_22 * 2 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_16 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_14 ( V_7 -> V_43 ,
F_15 ( V_7 -> V_44 , V_2 -> V_10 -> V_11 ) ,
0 ) ;
if ( V_8 )
F_4 ( V_2 -> V_12 , L_7 , V_8 ) ;
return V_8 ;
}
static int F_17 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
unsigned int V_45 , V_46 ;
if ( V_14 -> V_29 == V_30 ) {
V_45 = V_47 ;
V_46 = V_48 ;
} else {
V_45 = V_49 ;
V_46 = V_50 ;
}
V_8 = F_18 ( V_7 -> V_43 ,
F_15 ( V_7 -> V_44 , V_2 -> V_10 -> V_11 ) ,
V_46 , V_45 ) ;
if ( V_8 )
F_4 ( V_2 -> V_12 , L_7 , V_8 ) ;
return V_8 ;
}
static int F_19 ( struct V_13 * V_14 ,
int V_51 , struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = - V_28 ;
unsigned int V_45 , V_46 ;
switch ( V_51 ) {
case V_52 :
case V_53 :
case V_54 :
if ( V_14 -> V_29 == V_30 ) {
V_45 = V_47 ;
V_46 = V_48 ;
} else {
V_45 = V_49 ;
V_46 = V_50 ;
}
V_8 = F_18 ( V_7 -> V_43 ,
F_15 ( V_7 -> V_44 ,
V_2 -> V_10 -> V_11 ) ,
V_46 , V_45 ) ;
if ( V_8 )
F_4 ( V_2 -> V_12 , L_7 ,
V_8 ) ;
break;
case V_55 :
case V_56 :
case V_57 :
if ( V_14 -> V_29 == V_30 ) {
V_45 = V_58 ;
V_46 = V_48 ;
} else {
V_45 = V_59 ;
V_46 = V_50 ;
}
V_8 = F_18 ( V_7 -> V_43 ,
F_15 ( V_7 -> V_44 ,
V_2 -> V_10 -> V_11 ) ,
V_46 , V_45 ) ;
if ( V_8 )
F_4 ( V_2 -> V_12 , L_7 ,
V_8 ) ;
break;
}
return V_8 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_14 ( V_7 -> V_43 ,
F_15 ( V_7 -> V_44 , V_2 -> V_10 -> V_11 ) , 0 ) ;
if ( V_8 )
F_4 ( V_2 -> V_12 , L_7 , V_8 ) ;
return V_8 ;
}
static bool F_21 ( struct V_60 * V_12 , unsigned int V_61 )
{
struct V_6 * V_7 = F_22 ( V_12 ) ;
struct V_62 * V_63 = V_7 -> V_44 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_63 -> V_65 ; ++ V_64 )
if ( V_61 == F_15 ( V_63 , V_64 ) )
return true ;
for ( V_64 = 0 ; V_64 < V_63 -> V_66 ; ++ V_64 ) {
if ( V_61 == F_23 ( V_63 , V_64 ) )
return true ;
if ( V_61 == F_24 ( V_63 , V_64 ) )
return true ;
}
for ( V_64 = 0 ; V_64 < V_63 -> V_67 ; ++ V_64 ) {
if ( V_61 == F_25 ( V_63 , V_64 ) )
return true ;
if ( V_61 == F_26 ( V_63 , V_64 ) )
return true ;
if ( V_61 == F_27 ( V_63 , V_64 ) )
return true ;
if ( V_61 == F_28 ( V_63 , V_64 ) )
return true ;
}
for ( V_64 = 0 ; V_64 < V_63 -> V_68 ; ++ V_64 ) {
if ( V_61 == F_29 ( V_63 , V_64 + V_63 -> V_69 ) )
return true ;
if ( V_61 == F_30 ( V_63 , V_64 + V_63 -> V_69 ) )
return true ;
if ( V_61 == F_31 ( V_63 , V_64 + V_63 -> V_69 ) )
return true ;
if ( V_61 == F_32 ( V_63 , V_64 + V_63 -> V_69 ) )
return true ;
}
return false ;
}
static bool F_33 ( struct V_60 * V_12 , unsigned int V_61 )
{
struct V_6 * V_7 = F_22 ( V_12 ) ;
struct V_62 * V_63 = V_7 -> V_44 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_63 -> V_65 ; ++ V_64 )
if ( V_61 == F_15 ( V_63 , V_64 ) )
return true ;
for ( V_64 = 0 ; V_64 < V_63 -> V_66 ; ++ V_64 ) {
if ( V_61 == F_23 ( V_63 , V_64 ) )
return true ;
if ( V_61 == F_34 ( V_63 , V_64 ) )
return true ;
}
for ( V_64 = 0 ; V_64 < V_63 -> V_67 ; ++ V_64 ) {
if ( V_61 == F_25 ( V_63 , V_64 ) )
return true ;
if ( V_61 == F_26 ( V_63 , V_64 ) )
return true ;
if ( V_61 == F_27 ( V_63 , V_64 ) )
return true ;
if ( V_61 == F_35 ( V_63 , V_64 ) )
return true ;
if ( V_61 == F_28 ( V_63 , V_64 ) )
return true ;
}
for ( V_64 = 0 ; V_64 < V_63 -> V_68 ; ++ V_64 ) {
if ( V_61 == F_29 ( V_63 , V_64 + V_63 -> V_69 ) )
return true ;
if ( V_61 == F_30 ( V_63 , V_64 + V_63 -> V_69 ) )
return true ;
if ( V_61 == F_31 ( V_63 , V_64 + V_63 -> V_69 ) )
return true ;
if ( V_61 == F_36 ( V_63 , V_64 + V_63 -> V_69 ) )
return true ;
if ( V_61 == F_32 ( V_63 , V_64 + V_63 -> V_69 ) )
return true ;
}
return false ;
}
static bool F_37 ( struct V_60 * V_12 , unsigned int V_61 )
{
struct V_6 * V_7 = F_22 ( V_12 ) ;
struct V_62 * V_63 = V_7 -> V_44 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_63 -> V_66 ; ++ V_64 )
if ( V_61 == F_34 ( V_63 , V_64 ) )
return true ;
for ( V_64 = 0 ; V_64 < V_63 -> V_67 ; ++ V_64 )
if ( V_61 == F_35 ( V_63 , V_64 ) )
return true ;
for ( V_64 = 0 ; V_64 < V_63 -> V_68 ; ++ V_64 )
if ( V_61 == F_36 ( V_63 , V_64 + V_63 -> V_69 ) )
return true ;
return false ;
}
int F_38 ( struct V_70 * V_71 )
{
struct V_6 * V_7 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
struct V_62 * V_44 ;
struct V_60 * V_12 = & V_71 -> V_12 ;
const struct V_76 * V_77 ;
char V_78 [ 16 ] ;
int V_8 , V_64 , V_79 ;
V_73 = F_39 ( V_71 -> V_12 . V_80 , L_9 , 0 ) ;
if ( V_73 ) {
F_4 ( & V_71 -> V_12 , L_10 ) ;
return - V_81 ;
}
V_7 = F_40 ( & V_71 -> V_12 , sizeof( struct V_6 ) ,
V_82 ) ;
if ( ! V_7 )
return - V_83 ;
F_41 ( V_71 , V_7 ) ;
V_77 = F_42 ( V_12 -> V_10 -> V_84 , V_12 ) ;
if ( ! V_77 || ! V_77 -> V_85 )
return - V_28 ;
V_7 -> V_44 = (struct V_62 * ) V_77 -> V_85 ;
V_44 = V_7 -> V_44 ;
V_75 = F_43 ( V_71 , V_86 , L_11 ) ;
V_7 -> V_87 = F_44 ( & V_71 -> V_12 , V_75 ) ;
if ( F_45 ( ( void const V_88 * ) V_7 -> V_87 ) ) {
F_4 ( & V_71 -> V_12 , L_12 ,
F_46 ( ( void const V_88 * ) V_7 -> V_87 ) ) ;
return F_46 ( ( void const V_88 * ) V_7 -> V_87 ) ;
}
V_89 . V_90 = F_32 ( V_44 ,
V_44 -> V_68 +
V_44 -> V_69 ) ;
V_7 -> V_43 = F_47 ( & V_71 -> V_12 , V_7 -> V_87 ,
& V_89 ) ;
if ( F_45 ( V_7 -> V_43 ) ) {
F_4 ( & V_71 -> V_12 , L_13 ,
F_46 ( V_7 -> V_43 ) ) ;
return F_46 ( V_7 -> V_43 ) ;
}
if ( V_44 -> V_91 )
V_44 -> V_91 ( V_71 ) ;
for ( V_64 = 0 ; V_64 < V_44 -> V_92 ; V_64 ++ ) {
V_79 = V_44 -> V_93 [ V_64 ] . V_11 ;
if ( V_44 -> V_92 > 1 )
sprintf ( V_78 , L_14 , V_64 ) ;
else
sprintf ( V_78 , L_15 ) ;
V_7 -> V_9 [ V_79 ] = F_48 ( & V_71 -> V_12 ,
V_78 ) ;
if ( F_45 ( V_7 -> V_9 [ V_79 ] ) ) {
F_49 ( & V_71 -> V_12 ,
L_16 ,
F_46 ( V_7 -> V_9 [ V_79 ] ) ) ;
V_7 -> V_9 [ V_79 ] = NULL ;
}
if ( V_44 -> V_92 > 1 )
sprintf ( V_78 , L_17 , V_64 ) ;
else
sprintf ( V_78 , L_18 ) ;
V_7 -> V_15 [ V_79 ] = F_48 ( & V_71 -> V_12 ,
V_78 ) ;
if ( F_45 ( V_7 -> V_15 [ V_79 ] ) ) {
F_4 ( & V_71 -> V_12 ,
L_19 ,
F_46 ( V_7 -> V_15 [ V_79 ] ) ) ;
return F_46 ( V_7 -> V_15 [ V_79 ] ) ;
}
}
V_7 -> V_94 = F_48 ( & V_71 -> V_12 , L_20 ) ;
if ( F_45 ( V_7 -> V_94 ) ) {
F_4 ( & V_71 -> V_12 , L_21 ,
F_46 ( V_7 -> V_94 ) ) ;
return F_46 ( V_7 -> V_94 ) ;
}
V_8 = F_3 ( V_7 -> V_94 , V_95 ) ;
if ( V_8 ) {
F_4 ( & V_71 -> V_12 , L_22 ,
V_8 ) ;
return V_8 ;
}
F_50 ( & V_71 -> V_12 , L_23 ,
F_51 ( V_7 -> V_94 ) ) ;
V_8 = F_6 ( V_7 -> V_94 ) ;
if ( V_8 ) {
F_4 ( & V_71 -> V_12 , L_24 , V_8 ) ;
return V_8 ;
}
V_8 = F_52 ( & V_71 -> V_12 ,
& V_96 ,
V_44 -> V_93 ,
V_44 -> V_92 ) ;
if ( V_8 ) {
F_4 ( & V_71 -> V_12 , L_25 , V_8 ) ;
goto V_97;
}
V_8 = F_53 ( V_71 ) ;
if ( V_8 ) {
F_4 ( & V_71 -> V_12 , L_26 ,
V_8 ) ;
goto V_97;
}
return 0 ;
V_97:
F_7 ( V_7 -> V_94 ) ;
return V_8 ;
}
int F_54 ( struct V_70 * V_71 )
{
struct V_6 * V_7 = F_55 ( V_71 ) ;
if ( V_7 -> V_44 -> exit )
V_7 -> V_44 -> exit ( V_71 ) ;
F_7 ( V_7 -> V_94 ) ;
return 0 ;
}
