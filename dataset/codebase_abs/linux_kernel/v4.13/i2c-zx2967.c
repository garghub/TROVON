static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
void * V_6 , unsigned long V_4 , int V_7 )
{
F_6 ( V_2 -> V_5 + V_4 , V_6 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
void * V_6 , unsigned long V_4 , int V_7 )
{
F_8 ( V_2 -> V_5 + V_4 , V_6 , V_7 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_8 ;
T_1 V_9 ;
V_8 = F_3 ( V_2 , V_10 ) ;
V_8 |= V_11 ;
F_1 ( V_2 , V_8 , V_10 ) ;
V_9 = F_3 ( V_2 , V_12 ) ;
if ( V_2 -> V_13 )
V_9 |= V_14 ;
else
V_9 &= ~ V_14 ;
V_9 &= ~ V_15 ;
V_9 |= V_16 ;
F_1 ( V_2 , V_9 , V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_17 ;
T_1 V_3 ;
if ( V_2 -> V_13 ) {
V_17 = V_18 ;
V_3 = V_19 ;
} else {
V_17 = V_20 ;
V_3 = V_21 ;
}
V_3 |= F_3 ( V_2 , V_17 ) ;
F_1 ( V_2 , V_3 , V_17 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_22 )
{
T_2 V_3 [ V_23 ] = { 0 } ;
int V_24 ;
if ( V_22 > V_23 ) {
F_12 ( F_13 ( V_2 ) , L_1 ,
V_22 , V_23 ) ;
return - V_25 ;
}
F_7 ( V_2 , V_3 , V_26 , V_22 ) ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ ) {
* V_2 -> V_27 ++ = V_3 [ V_24 ] ;
V_2 -> V_28 -- ;
}
F_14 () ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_3 V_28 = V_2 -> V_28 ;
T_2 * V_29 = V_2 -> V_27 ;
if ( V_28 == 0 ) {
F_12 ( F_13 ( V_2 ) , L_2 , ( int ) V_28 ) ;
return - V_25 ;
}
if ( V_28 <= V_23 ) {
F_5 ( V_2 , V_29 , V_26 , V_28 ) ;
V_2 -> V_28 = 0 ;
V_2 -> V_27 = NULL ;
} else {
F_5 ( V_2 , V_29 , V_26 , V_23 ) ;
V_2 -> V_28 -= V_23 ;
V_2 -> V_27 += V_23 ;
}
F_14 () ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_30 ;
V_3 = V_31 | V_32 ;
F_1 ( V_2 , V_3 , V_12 ) ;
V_30 = F_17 ( V_2 -> V_33 ) / V_2 -> V_34 - 1 ;
F_1 ( V_2 , V_30 , V_35 ) ;
F_1 ( V_2 , V_30 , V_36 ) ;
F_1 ( V_2 , V_23 - 1 , V_20 ) ;
F_1 ( V_2 , V_23 - 1 , V_18 ) ;
F_1 ( V_2 , 1 , V_18 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_3 ( V_2 , V_10 ) ;
V_8 |= V_11 ;
F_1 ( V_2 , V_8 , V_10 ) ;
}
static T_4 F_19 ( int V_37 , void * V_38 )
{
T_1 V_8 ;
struct V_1 * V_2 = (struct V_1 * ) V_38 ;
V_8 = F_3 ( V_2 , V_10 ) & V_39 ;
F_18 ( V_2 ) ;
if ( V_8 & V_40 )
V_2 -> error = - V_41 ;
else if ( V_8 & V_42 )
V_2 -> error = - V_43 ;
else if ( V_8 & V_44 )
V_2 -> error = 0 ;
else
goto V_45;
F_20 ( & V_2 -> F_20 ) ;
V_45:
return V_46 ;
}
static void F_21 ( struct V_1 * V_2 , T_5 V_47 )
{
T_5 V_3 ;
V_3 = ( V_47 >> V_48 ) & V_49 ;
F_1 ( V_2 , V_3 , V_50 ) ;
V_3 = ( V_47 >> V_51 ) & V_52 ;
F_1 ( V_2 , V_3 , V_53 ) ;
if ( V_3 )
V_3 = F_3 ( V_2 , V_12 ) | V_54 ;
else
V_3 = F_3 ( V_2 , V_12 ) & ~ V_54 ;
F_1 ( V_2 , V_3 , V_12 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_55 )
{
unsigned long V_56 ;
int V_57 = V_2 -> V_13 ;
int V_58 ;
F_23 ( & V_2 -> F_20 ) ;
if ( V_57 ) {
F_1 ( V_2 , V_55 - 1 , V_18 ) ;
} else {
V_58 = F_15 ( V_2 ) ;
if ( V_58 )
return V_58 ;
}
F_9 ( V_2 ) ;
V_56 = F_24 ( & V_2 -> F_20 ,
V_59 ) ;
if ( V_56 == 0 )
return - V_60 ;
if ( V_2 -> error )
return V_2 -> error ;
return V_57 ? F_11 ( V_2 , V_55 ) : 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
int V_58 ;
int V_24 ;
if ( V_62 -> V_7 == 0 )
return - V_25 ;
F_10 ( V_2 ) ;
V_2 -> V_27 = V_62 -> V_29 ;
V_2 -> V_28 = V_62 -> V_7 ;
V_2 -> V_63 = V_62 -> V_7 / V_23 ;
V_2 -> V_13 = V_62 -> V_64 & V_65 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_63 ; V_24 ++ ) {
V_58 = F_22 ( V_2 , V_23 ) ;
if ( V_58 )
return V_58 ;
}
if ( V_2 -> V_28 > 0 ) {
V_58 = F_22 ( V_2 , V_2 -> V_28 ) ;
if ( V_58 )
return V_58 ;
}
V_2 -> V_28 = 0 ;
V_2 -> V_63 = 0 ;
return 0 ;
}
static int F_26 ( struct V_66 * V_67 ,
struct V_61 * V_68 , int V_69 )
{
struct V_1 * V_2 = F_27 ( V_67 ) ;
int V_58 ;
int V_24 ;
if ( V_2 -> V_70 )
return - V_71 ;
F_21 ( V_2 , V_68 -> V_47 ) ;
for ( V_24 = 0 ; V_24 < V_69 ; V_24 ++ ) {
V_58 = F_25 ( V_2 , & V_68 [ V_24 ] ) ;
if ( V_58 )
return V_58 ;
}
return V_69 ;
}
static void
F_28 ( struct V_1 * V_2 , T_5 V_47 ,
char V_72 , T_2 V_73 , int V_22 ,
union V_74 * V_6 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_18 ) ;
V_3 |= V_19 ;
F_1 ( V_2 , V_3 , V_18 ) ;
F_21 ( V_2 , V_47 ) ;
V_3 = F_3 ( V_2 , V_12 ) ;
V_3 &= ~ V_14 ;
F_1 ( V_2 , V_3 , V_12 ) ;
switch ( V_22 ) {
case V_75 :
F_1 ( V_2 , V_73 , V_26 ) ;
break;
case V_76 :
F_1 ( V_2 , V_73 , V_26 ) ;
if ( V_72 == V_77 )
F_1 ( V_2 , V_6 -> V_78 , V_26 ) ;
break;
case V_79 :
F_1 ( V_2 , V_73 , V_26 ) ;
if ( V_72 == V_77 ) {
F_1 ( V_2 , ( V_6 -> V_80 >> 8 ) , V_26 ) ;
F_1 ( V_2 , ( V_6 -> V_80 & 0xff ) ,
V_26 ) ;
}
break;
}
}
static int F_29 ( struct V_1 * V_2 , int V_22 ,
union V_74 * V_6 )
{
unsigned long V_56 ;
T_2 V_29 [ 2 ] ;
T_1 V_3 ;
F_23 ( & V_2 -> F_20 ) ;
V_3 = F_3 ( V_2 , V_12 ) ;
V_3 |= V_15 ;
F_1 ( V_2 , V_3 , V_12 ) ;
V_3 = F_3 ( V_2 , V_12 ) ;
V_3 |= V_16 ;
F_1 ( V_2 , V_3 , V_12 ) ;
V_56 = F_24 ( & V_2 -> F_20 ,
V_59 ) ;
if ( V_56 == 0 )
return - V_60 ;
if ( V_2 -> error )
return V_2 -> error ;
switch ( V_22 ) {
case V_75 :
case V_76 :
V_3 = F_3 ( V_2 , V_26 ) ;
V_6 -> V_78 = V_3 ;
break;
case V_79 :
case V_81 :
V_29 [ 0 ] = F_3 ( V_2 , V_26 ) ;
V_29 [ 1 ] = F_3 ( V_2 , V_26 ) ;
V_6 -> V_80 = ( V_29 [ 0 ] << 8 ) | V_29 [ 1 ] ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
unsigned long V_56 ;
T_1 V_3 ;
F_23 ( & V_2 -> F_20 ) ;
V_3 = F_3 ( V_2 , V_12 ) ;
V_3 |= V_16 ;
F_1 ( V_2 , V_3 , V_12 ) ;
V_56 = F_24 ( & V_2 -> F_20 ,
V_59 ) ;
if ( V_56 == 0 )
return - V_60 ;
if ( V_2 -> error )
return V_2 -> error ;
return 0 ;
}
static int F_31 ( struct V_66 * V_67 , T_5 V_47 ,
unsigned short V_64 , char V_72 ,
T_2 V_73 , int V_22 , union V_74 * V_6 )
{
struct V_1 * V_2 = F_27 ( V_67 ) ;
if ( V_22 == V_83 )
V_72 = V_77 ;
switch ( V_22 ) {
case V_83 :
case V_75 :
case V_76 :
case V_79 :
F_28 ( V_2 , V_47 , V_72 ,
V_73 , V_22 , V_6 ) ;
break;
default:
return - V_82 ;
}
if ( V_72 == V_84 )
return F_29 ( V_2 , V_22 , V_6 ) ;
return F_30 ( V_2 ) ;
}
static T_1 F_32 ( struct V_66 * V_67 )
{
return V_85 |
V_86 |
V_87 |
V_88 |
V_89 |
V_90 |
V_91 |
V_92 ;
}
static int T_6 F_33 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_34 ( V_94 ) ;
V_2 -> V_70 = true ;
F_35 ( V_2 -> V_33 ) ;
return 0 ;
}
static int T_6 F_36 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_34 ( V_94 ) ;
V_2 -> V_70 = false ;
F_37 ( V_2 -> V_33 ) ;
return 0 ;
}
static int F_38 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
void T_7 * V_5 ;
struct V_97 * V_98 ;
struct V_33 * V_33 ;
int V_58 ;
V_2 = F_39 ( & V_96 -> V_94 , sizeof( * V_2 ) , V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_98 = F_40 ( V_96 , V_101 , 0 ) ;
V_5 = F_41 ( & V_96 -> V_94 , V_98 ) ;
if ( F_42 ( V_5 ) )
return F_43 ( V_5 ) ;
V_33 = F_44 ( & V_96 -> V_94 , NULL ) ;
if ( F_42 ( V_33 ) ) {
F_12 ( & V_96 -> V_94 , L_3 ) ;
return F_43 ( V_33 ) ;
}
V_58 = F_37 ( V_33 ) ;
if ( V_58 ) {
F_12 ( & V_96 -> V_94 , L_4 ) ;
return V_58 ;
}
V_58 = F_45 ( & V_96 -> V_94 , L_5 ,
& V_2 -> V_34 ) ;
if ( V_58 ) {
F_12 ( & V_96 -> V_94 , L_6 ) ;
return V_58 ;
}
V_58 = F_46 ( V_96 , 0 ) ;
if ( V_58 < 0 )
return V_58 ;
V_2 -> V_37 = V_58 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_33 = V_33 ;
F_47 ( & V_2 -> F_20 ) ;
F_48 ( V_96 , V_2 ) ;
V_58 = F_16 ( V_2 ) ;
if ( V_58 ) {
F_12 ( & V_96 -> V_94 , L_7 ) ;
goto V_102;
}
V_58 = F_49 ( & V_96 -> V_94 , V_2 -> V_37 ,
F_19 , 0 , F_50 ( & V_96 -> V_94 ) , V_2 ) ;
if ( V_58 ) {
F_12 ( & V_96 -> V_94 , L_8 , V_2 -> V_37 ) ;
goto V_102;
}
F_51 ( & V_2 -> V_67 , V_2 ) ;
F_52 ( V_2 -> V_67 . V_103 , L_9 ,
sizeof( V_2 -> V_67 . V_103 ) ) ;
V_2 -> V_67 . V_104 = & V_105 ;
V_2 -> V_67 . V_106 = V_96 -> V_107 ;
V_2 -> V_67 . V_94 . V_108 = & V_96 -> V_94 ;
V_2 -> V_67 . V_94 . V_109 = V_96 -> V_94 . V_109 ;
V_58 = F_53 ( & V_2 -> V_67 ) ;
if ( V_58 )
goto V_102;
return 0 ;
V_102:
F_35 ( V_2 -> V_33 ) ;
return V_58 ;
}
static int F_54 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_55 ( V_96 ) ;
F_56 ( & V_2 -> V_67 ) ;
F_35 ( V_2 -> V_33 ) ;
return 0 ;
}
