static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 = F_2 ( V_2 , ( V_3 << 4 ) | 0x08 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_1 , V_3 ) ;
return V_5 ;
}
* V_4 = V_5 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_3 , T_1 V_7 , T_1 * V_8 )
{
int V_5 = F_5 ( V_2 , ( V_3 << 4 ) | 0x08 ,
V_7 , V_8 ) ;
if ( V_5 != V_7 ) {
F_3 ( & V_2 -> V_6 , L_2 ,
V_3 , V_3 + V_7 - 1 ) ;
return V_5 < 0 ? V_5 : - V_9 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int V_5 = F_7 ( V_2 , V_3 << 4 , V_4 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_6 , L_3 ,
V_3 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_3 , T_1 V_7 , T_1 * V_8 )
{
int V_5 = F_9 ( V_2 , ( V_3 << 4 ) | 0x08 ,
V_7 , V_8 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_6 , L_4 ,
V_3 , V_3 + V_7 - 1 ) ;
return V_5 ;
}
static T_2 F_10 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
struct V_12 * V_13 = F_11 ( V_2 ) ;
F_12 ( V_10 ) ;
F_13 ( & V_13 -> V_14 ) ;
return V_15 ;
}
static void F_14 ( struct V_16 * V_14 )
{
struct V_12 * V_13 = F_15 ( V_14 , struct V_12 ,
V_14 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_17 * V_18 = & V_13 -> V_19 -> V_20 ;
T_1 V_21 ;
F_16 ( V_18 ) ;
if ( F_1 ( V_2 , V_22 , & V_21 ) )
goto V_23;
if ( ! ( V_21 & V_24 ) )
F_17 ( & V_2 -> V_6 , L_5
L_6 ) ;
if ( V_21 & V_25 ) {
V_21 &= ~ V_25 ;
F_18 () ;
F_19 ( V_13 -> V_19 , 1 , V_26 | V_27 ) ;
F_20 () ;
}
if ( V_21 & V_28 ) {
V_21 &= V_28 ;
if ( F_6 ( V_2 , V_29 ,
V_13 -> V_30 & ~ V_31 ) )
goto V_23;
F_18 () ;
F_19 ( V_13 -> V_19 , 1 , V_32 | V_27 ) ;
F_20 () ;
}
F_6 ( V_2 , V_22 ,
V_21 | V_24 ) ;
V_23:
if ( ! V_13 -> V_33 )
F_21 ( V_2 -> V_10 ) ;
F_22 ( V_18 ) ;
}
static int F_23 ( struct V_34 * V_6 , struct V_35 * V_36 )
{
struct V_12 * V_13 = F_24 ( V_6 ) ;
T_1 V_37 [ 7 ] ;
int V_38 ;
V_38 = F_4 ( V_13 -> V_2 , V_39 , 7 , V_37 ) ;
if ( V_38 )
return V_38 ;
F_25 ( V_6 , L_7
L_8 , V_40 ,
V_37 [ 0 ] , V_37 [ 1 ] , V_37 [ 2 ] , V_37 [ 3 ] , V_37 [ 4 ] ,
V_37 [ 5 ] , V_37 [ 6 ] ) ;
V_36 -> V_41 = F_26 ( V_37 [ V_39 ] & 0x7f ) ;
V_36 -> V_42 = F_26 ( V_37 [ V_43 ] & 0x7f ) ;
if ( V_13 -> V_30 & V_44 )
V_36 -> V_45 = F_26 ( V_37 [ V_46 ] & 0x3f ) ;
else
V_36 -> V_45 = F_26 ( V_37 [ V_46 ] & 0x1f ) % 12
+ ( V_37 [ V_46 ] & 0x20 ? 12 : 0 ) ;
V_36 -> V_47 = F_26 ( V_37 [ V_48 ] & 0x3f ) ;
V_36 -> V_49 = F_26 ( V_37 [ V_50 ] & 0x1f ) - 1 ;
V_36 -> V_51 = F_26 ( V_37 [ V_52 ] ) ;
if ( V_36 -> V_51 < 70 )
V_36 -> V_51 += 100 ;
F_25 ( V_6 , L_9 , V_40 ,
V_36 -> V_41 , V_36 -> V_42 , V_36 -> V_45 ,
V_36 -> V_47 , V_36 -> V_49 , V_36 -> V_51 ) ;
return F_27 ( V_36 ) ;
}
static int F_28 ( struct V_34 * V_6 , struct V_35 * V_36 )
{
struct V_12 * V_13 = F_24 ( V_6 ) ;
T_1 V_37 [ 7 ] ;
V_37 [ V_39 ] = F_29 ( V_36 -> V_41 ) ;
V_37 [ V_43 ] = F_29 ( V_36 -> V_42 ) ;
if ( V_13 -> V_30 & V_44 )
V_37 [ V_46 ] = F_29 ( V_36 -> V_45 ) ;
else
V_37 [ V_46 ] = ( V_36 -> V_45 >= 12 ? 0x20 : 0 )
| F_29 ( ( V_36 -> V_45 + 11 ) % 12 + 1 ) ;
V_37 [ V_53 ] = F_29 ( V_36 -> V_54 ) ;
V_37 [ V_48 ] = F_29 ( V_36 -> V_47 ) ;
V_37 [ V_50 ] = F_29 ( V_36 -> V_49 + 1 ) ;
V_37 [ V_52 ] = F_29 ( V_36 -> V_51 % 100 ) ;
F_25 ( V_6 ,
L_10 ,
V_40 ,
V_37 [ 0 ] , V_37 [ 1 ] , V_37 [ 2 ] , V_37 [ 3 ] , V_37 [ 4 ] , V_37 [ 5 ] , V_37 [ 6 ] ) ;
return F_8 ( V_13 -> V_2 , V_39 , 7 , V_37 ) ;
}
static int F_30 ( struct V_1 * V_2 , int * V_55 )
{
struct V_12 * V_13 = F_11 ( V_2 ) ;
T_1 V_56 [ 2 ] , V_57 ;
int V_58 = 0 ;
int V_38 ;
V_38 = F_4 ( V_13 -> V_2 , V_29 , 2 , V_56 ) ;
if ( V_38 )
goto V_23;
V_13 -> V_30 = V_56 [ 0 ] & ~ V_59 ;
if ( V_56 [ 1 ] & V_60 ) {
F_17 ( & V_2 -> V_6 , L_11
L_6 ) ;
* V_55 = 1 ;
}
if ( V_56 [ 1 ] & V_61 ) {
F_17 ( & V_2 -> V_6 , L_12
L_6 ) ;
* V_55 = 1 ;
}
if ( ! ( V_56 [ 1 ] & V_24 ) ) {
F_17 ( & V_2 -> V_6 , L_5
L_6 ) ;
* V_55 = 1 ;
}
if ( V_56 [ 1 ] & ( V_28 | V_62 ) ) {
F_17 ( & V_2 -> V_6 , L_13 ) ;
V_58 = 1 ;
}
if ( ! ( V_56 [ 1 ] & V_25 ) )
V_58 = 1 ;
if ( * V_55 || V_58 ) {
V_57 = V_56 [ 0 ] ;
V_57 &= ~ ( V_60 | V_61 |
V_25 | V_62 |
V_28 ) ;
V_57 |= V_24 ;
V_38 = F_6 ( V_2 , V_22 , V_57 ) ;
}
V_23:
return V_38 ;
}
static int F_31 ( struct V_34 * V_6 , struct V_63 * V_64 )
{
struct V_12 * V_13 = F_24 ( V_6 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
T_1 V_57 , V_65 [ 2 ] ;
int V_38 ;
if ( V_2 -> V_10 <= 0 )
return - V_66 ;
V_38 = F_4 ( V_2 , V_67 , 2 , V_65 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_1 ( V_2 , V_22 , & V_57 ) ;
if ( V_38 )
return V_38 ;
F_25 ( V_6 , L_14 ,
V_40 , V_65 [ 0 ] , V_65 [ 1 ] , V_57 ) ;
V_64 -> time . V_41 = 0 ;
V_64 -> time . V_42 = F_26 ( V_65 [ 0 ] & 0x7f ) ;
if ( V_13 -> V_30 & V_44 )
V_64 -> time . V_45 = F_26 ( V_65 [ 1 ] & 0x3f ) ;
else
V_64 -> time . V_45 = F_26 ( V_65 [ 1 ] & 0x1f ) % 12
+ ( V_65 [ 1 ] & 0x20 ? 12 : 0 ) ;
V_64 -> time . V_54 = - 1 ;
V_64 -> time . V_47 = - 1 ;
V_64 -> time . V_49 = - 1 ;
V_64 -> time . V_51 = - 1 ;
F_25 ( V_6 , L_15 ,
V_40 ,
V_64 -> time . V_41 , V_64 -> time . V_42 , V_64 -> time . V_45 ,
V_64 -> time . V_47 , V_64 -> time . V_49 , V_64 -> time . V_51 ) ;
V_64 -> V_68 = ! ! ( V_13 -> V_30 & V_31 ) ;
V_64 -> V_69 = ( V_57 & V_28 ) && V_64 -> V_68 ;
return V_38 ;
}
static int F_32 ( struct V_34 * V_6 , struct V_63 * V_64 )
{
struct V_1 * V_2 = F_33 ( V_6 ) ;
struct V_12 * V_13 = F_24 ( V_6 ) ;
T_1 V_65 [ 2 ] ;
int V_38 ;
if ( V_2 -> V_10 <= 0 )
return - V_66 ;
V_65 [ 0 ] = F_29 ( V_64 -> time . V_42 ) ;
if ( V_13 -> V_30 & V_44 )
V_65 [ 1 ] = F_29 ( V_64 -> time . V_45 ) ;
else
V_65 [ 1 ] = ( V_64 -> time . V_45 >= 12 ? 0x20 : 0 )
| F_29 ( ( V_64 -> time . V_45 + 11 ) % 12 + 1 ) ;
F_25 ( V_6 , L_16 , V_40 , V_65 [ 0 ] , V_65 [ 1 ] ) ;
if ( V_13 -> V_30 & V_31 ) {
V_13 -> V_30 &= ~ V_31 ;
V_38 = F_6 ( V_13 -> V_2 , V_29 ,
V_13 -> V_30 ) ;
if ( V_38 )
return V_38 ;
}
V_38 = F_8 ( V_13 -> V_2 , V_67 , 2 , V_65 ) ;
if ( V_38 )
return V_38 ;
if ( V_64 -> V_68 ) {
V_13 -> V_30 |= V_31 ;
V_38 = F_6 ( V_13 -> V_2 , V_29 ,
V_13 -> V_30 ) ;
if ( V_38 )
return V_38 ;
}
return 0 ;
}
static int F_34 ( struct V_34 * V_6 , unsigned int V_68 )
{
struct V_12 * V_13 = F_24 ( V_6 ) ;
T_1 V_30 ;
int V_38 ;
V_30 = V_13 -> V_30 ;
if ( V_68 )
V_30 |= V_31 ;
else
V_30 &= ~ V_31 ;
if ( V_30 != V_13 -> V_30 ) {
V_13 -> V_30 = V_30 ;
V_38 = F_6 ( V_13 -> V_2 , V_29 ,
V_13 -> V_30 ) ;
if ( V_38 )
return V_38 ;
}
return 0 ;
}
static int F_35 ( struct V_34 * V_6 , int * V_70 )
{
struct V_1 * V_2 = F_33 ( V_6 ) ;
T_1 V_71 ;
int V_38 ;
V_38 = F_1 ( V_2 , V_72 , & V_71 ) ;
if ( V_38 )
return V_38 ;
* V_70 = V_71 >= 64 ? V_71 - 128 : V_71 ;
if ( * V_70 > 0 )
( * V_70 ) -- ;
* V_70 *= - V_73 ;
return 0 ;
}
static int F_36 ( struct V_34 * V_6 , int V_70 )
{
struct V_1 * V_2 = F_33 ( V_6 ) ;
T_1 V_71 ;
int V_38 ;
V_70 /= - V_73 ;
if ( V_70 > V_74 )
V_70 = V_74 ;
else if ( V_70 < V_75 )
V_70 = V_75 ;
else if ( V_70 > 0 )
V_70 ++ ;
else if ( V_70 < 0 )
V_70 += 128 ;
V_71 = V_70 ;
V_38 = F_6 ( V_2 , V_72 , V_71 ) ;
if ( V_38 )
return V_38 ;
F_25 ( V_6 , L_17 , V_40 , V_71 ) ;
return 0 ;
}
static T_3 F_37 ( struct V_34 * V_6 ,
struct V_76 * V_77 ,
char * V_78 )
{
int V_38 , V_70 ;
V_38 = F_35 ( V_6 , & V_70 ) ;
if ( V_38 )
return V_38 ;
return sprintf ( V_78 , L_18 , V_70 ) ;
}
static T_3 F_38 ( struct V_34 * V_6 ,
struct V_76 * V_77 ,
const char * V_78 , T_4 V_79 )
{
int V_70 , V_38 ;
if ( sscanf ( V_78 , L_19 , & V_70 ) != 1 )
return - V_66 ;
V_38 = F_36 ( V_6 , V_70 ) ;
return V_38 ? V_38 : V_79 ;
}
static int F_39 ( struct V_34 * V_6 )
{
return F_40 ( V_6 , & V_80 ) ;
}
static void F_41 ( struct V_34 * V_6 )
{
F_42 ( V_6 , & V_80 ) ;
}
static int T_5 F_43 ( struct V_1 * V_2 ,
const struct V_81 * V_82 )
{
struct V_83 * V_84 = F_44 ( V_2 -> V_6 . V_85 ) ;
struct V_12 * V_13 ;
int V_38 , V_55 = 0 ;
if ( ! F_45 ( V_84 , V_86
| V_87 ) ) {
F_3 ( & V_84 -> V_6 ,
L_20 ) ;
V_38 = - V_9 ;
goto V_88;
}
V_13 = F_46 ( sizeof( * V_13 ) , V_89 ) ;
if ( ! V_13 ) {
F_3 ( & V_84 -> V_6 , L_21 ) ;
V_38 = - V_90 ;
goto V_88;
}
V_13 -> V_2 = V_2 ;
F_47 ( V_2 , V_13 ) ;
F_48 ( & V_13 -> V_14 , F_14 ) ;
V_38 = F_30 ( V_2 , & V_55 ) ;
if ( V_38 )
goto V_91;
if ( V_55 ) {
struct V_35 V_92 ;
F_49 ( & V_2 -> V_6 ,
L_22 ) ;
F_50 ( 0 , & V_92 ) ;
F_28 ( & V_2 -> V_6 , & V_92 ) ;
}
V_13 -> V_19 = F_51 ( V_2 -> V_93 , & V_2 -> V_6 ,
& V_94 , V_95 ) ;
if ( F_52 ( V_13 -> V_19 ) ) {
V_38 = F_53 ( V_13 -> V_19 ) ;
F_3 ( & V_2 -> V_6 , L_23 ) ;
goto V_91;
}
if ( V_2 -> V_10 > 0 ) {
F_49 ( & V_2 -> V_6 , L_24 , V_2 -> V_10 ) ;
V_38 = F_54 ( V_2 -> V_10 , F_10 ,
0 , L_25 , V_2 ) ;
if ( V_38 ) {
F_3 ( & V_2 -> V_6 , L_26 ) ;
goto V_96;
}
}
V_13 -> V_19 -> V_97 = 1 ;
V_13 -> V_19 -> V_98 = 1 ;
V_38 = F_39 ( & V_2 -> V_6 ) ;
if ( V_38 )
goto V_99;
return 0 ;
V_99:
if ( V_2 -> V_10 > 0 )
F_55 ( V_2 -> V_10 , V_2 ) ;
V_96:
F_56 ( V_13 -> V_19 ) ;
V_91:
F_57 ( V_13 ) ;
V_88:
F_3 ( & V_84 -> V_6 , L_27 ) ;
return V_38 ;
}
static int T_6 F_58 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_11 ( V_2 ) ;
struct V_17 * V_18 = & V_13 -> V_19 -> V_20 ;
if ( V_2 -> V_10 > 0 ) {
F_16 ( V_18 ) ;
V_13 -> V_33 = 1 ;
F_22 ( V_18 ) ;
F_55 ( V_2 -> V_10 , V_2 ) ;
F_59 ( & V_13 -> V_14 ) ;
}
F_41 ( & V_2 -> V_6 ) ;
F_56 ( V_13 -> V_19 ) ;
F_57 ( V_13 ) ;
return 0 ;
}
static int T_7 F_60 ( void )
{
return F_61 ( & V_100 ) ;
}
static void T_8 F_62 ( void )
{
F_63 ( & V_100 ) ;
}
