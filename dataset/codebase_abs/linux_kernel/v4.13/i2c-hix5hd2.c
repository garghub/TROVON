static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_6 ) ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_3 ( V_7 , V_2 -> V_4 + V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( 0 , V_2 -> V_4 + V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_3 ( V_9 | V_10 | V_11 ,
V_2 -> V_4 + V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_12 , V_3 ;
T_1 V_13 , V_14 ;
V_3 = F_2 ( V_2 -> V_4 + V_8 ) ;
F_3 ( V_3 & ( ~ V_10 ) , V_2 -> V_4 + V_8 ) ;
V_12 = V_2 -> V_15 ;
V_14 = F_8 ( V_2 -> V_16 ) ;
V_13 = ( V_14 / ( V_12 * 2 ) ) / 2 - 1 ;
F_3 ( V_13 , V_2 -> V_4 + V_17 ) ;
F_3 ( V_13 , V_2 -> V_4 + V_18 ) ;
F_3 ( V_3 , V_2 -> V_4 + V_8 ) ;
F_9 ( V_2 -> V_19 , L_1 ,
V_20 , V_14 , V_12 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_7 ( V_2 ) ;
F_4 ( V_2 ) ;
F_6 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_16 ) ;
F_13 ( 20 ) ;
F_14 ( V_2 -> V_16 ) ;
F_10 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_21 ;
T_1 V_22 ;
V_21 = V_23 + F_16 ( 100 ) ;
do {
V_22 = F_1 ( V_2 ) ;
if ( ! ( V_22 & V_24 ) )
return 0 ;
F_17 ( 50 , 200 ) ;
} while ( F_18 ( V_23 , V_21 ) );
return - V_25 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 == V_27 )
F_9 ( V_2 -> V_19 , L_2 , V_20 ) ;
else
F_9 ( V_2 -> V_19 , L_3 , V_20 ) ;
V_2 -> V_26 = V_28 ;
V_2 -> V_29 = 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 ) {
V_2 -> V_26 = V_27 ;
F_3 ( V_31 , V_2 -> V_4 + V_32 ) ;
} else {
F_19 ( V_2 ) ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 == 1 ) {
F_3 ( V_34 | V_35 , V_2 -> V_4 + V_32 ) ;
} else if ( V_2 -> V_33 > 1 ) {
F_3 ( V_34 , V_2 -> V_4 + V_32 ) ;
} else {
F_20 ( V_2 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
T_2 V_36 ;
if ( V_2 -> V_33 > 0 ) {
V_36 = V_2 -> V_37 -> V_38 [ V_2 -> V_39 ++ ] ;
F_3 ( V_36 , V_2 -> V_4 + V_40 ) ;
F_3 ( V_41 , V_2 -> V_4 + V_32 ) ;
} else {
F_20 ( V_2 ) ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
T_2 V_36 ;
if ( V_2 -> V_26 == V_42 ) {
V_2 -> V_26 = V_43 ;
} else if ( V_2 -> V_26 == V_43 ) {
if ( V_2 -> V_37 -> V_44 & V_45 ) {
V_36 = F_2 ( V_2 -> V_4 + V_46 ) ;
V_2 -> V_37 -> V_38 [ V_2 -> V_39 ++ ] = V_36 ;
}
V_2 -> V_33 -- ;
} else {
F_9 ( V_2 -> V_19 , L_4 ,
V_20 , V_2 -> V_26 , V_2 -> V_33 ) ;
return - V_47 ;
}
return 0 ;
}
static T_3 F_24 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
T_1 V_22 ;
int V_50 ;
F_25 ( & V_2 -> V_51 ) ;
V_22 = F_1 ( V_2 ) ;
if ( V_22 & V_52 ) {
F_9 ( V_2 -> V_19 , L_5 ) ;
V_2 -> V_29 = - V_47 ;
V_2 -> V_26 = V_53 ;
goto V_30;
} else if ( V_22 & V_54 ) {
F_9 ( V_2 -> V_19 , L_6 ) ;
V_2 -> V_29 = - V_55 ;
V_2 -> V_26 = V_53 ;
goto V_30;
}
if ( V_22 & V_56 ) {
if ( V_2 -> V_33 > 0 ) {
V_50 = F_23 ( V_2 ) ;
if ( V_50 ) {
V_2 -> V_29 = V_50 ;
V_2 -> V_26 = V_53 ;
goto V_30;
}
if ( V_2 -> V_37 -> V_44 & V_45 )
F_21 ( V_2 ) ;
else
F_22 ( V_2 ) ;
} else {
F_19 ( V_2 ) ;
}
}
V_30:
if ( ( V_2 -> V_26 == V_28 &&
V_2 -> V_37 -> V_57 == V_2 -> V_39 ) ||
( V_2 -> V_26 == V_53 ) ) {
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
F_26 ( & V_2 -> V_58 ) ;
}
F_27 ( & V_2 -> V_51 ) ;
return V_59 ;
}
static void F_28 ( struct V_1 * V_2 , int V_30 )
{
unsigned long V_44 ;
F_29 ( & V_2 -> V_51 , V_44 ) ;
F_4 ( V_2 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_37 -> V_44 & V_45 )
F_3 ( ( V_2 -> V_37 -> V_60 << 1 ) | V_61 ,
V_2 -> V_4 + V_40 ) ;
else
F_3 ( V_2 -> V_37 -> V_60 << 1 ,
V_2 -> V_4 + V_40 ) ;
F_3 ( V_41 | V_62 , V_2 -> V_4 + V_32 ) ;
F_30 ( & V_2 -> V_51 , V_44 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_63 * V_64 , int V_30 )
{
unsigned long V_65 ;
int V_50 ;
V_2 -> V_37 = V_64 ;
V_2 -> V_39 = 0 ;
V_2 -> V_33 = V_2 -> V_37 -> V_57 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_29 = 0 ;
V_2 -> V_26 = V_42 ;
F_32 ( & V_2 -> V_58 ) ;
F_28 ( V_2 , V_30 ) ;
V_65 = F_33 ( & V_2 -> V_58 ,
V_2 -> V_66 . V_65 ) ;
if ( V_65 == 0 ) {
V_2 -> V_26 = V_53 ;
V_2 -> V_29 = - V_67 ;
F_34 ( V_2 -> V_19 , L_7 ,
V_64 -> V_44 & V_45 ? L_8 : L_9 ,
V_2 -> V_66 . V_65 ) ;
}
V_50 = V_2 -> V_26 ;
if ( V_2 -> V_26 == V_28 && V_30 )
V_50 = F_15 ( V_2 ) ;
if ( V_50 < 0 )
F_11 ( V_2 ) ;
return V_2 -> V_29 ;
}
static int F_35 ( struct V_68 * V_66 ,
struct V_63 * V_64 , int V_69 )
{
struct V_1 * V_2 = F_36 ( V_66 ) ;
int V_70 , V_50 , V_30 ;
F_37 ( V_2 -> V_19 ) ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ , V_64 ++ ) {
V_30 = ( V_70 == V_69 - 1 ) ;
V_50 = F_31 ( V_2 , V_64 , V_30 ) ;
if ( V_50 < 0 )
goto V_71;
}
if ( V_70 == V_69 ) {
V_50 = V_69 ;
} else {
if ( V_70 == 1 )
V_50 = - V_72 ;
else
V_50 = V_70 ;
F_34 ( V_2 -> V_19 , L_10 ) ;
}
V_71:
F_38 ( V_2 -> V_19 ) ;
F_39 ( V_2 -> V_19 ) ;
return V_50 ;
}
static T_1 F_40 ( struct V_68 * V_66 )
{
return V_73 | ( V_74 & ~ V_75 ) ;
}
static int F_41 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = V_77 -> V_19 . V_80 ;
struct V_1 * V_2 ;
struct V_81 * V_82 ;
unsigned int V_15 ;
int V_83 , V_50 ;
V_2 = F_42 ( & V_77 -> V_19 , sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
if ( F_43 ( V_79 , L_11 , & V_15 ) ) {
V_2 -> V_15 = 100000 ;
} else {
if ( V_15 > V_86 ) {
V_2 -> V_15 = V_86 ;
F_34 ( V_2 -> V_19 , L_12 ,
V_86 ) ;
} else {
V_2 -> V_15 = V_15 ;
}
}
V_82 = F_44 ( V_77 , V_87 , 0 ) ;
V_2 -> V_4 = F_45 ( & V_77 -> V_19 , V_82 ) ;
if ( F_46 ( V_2 -> V_4 ) )
return F_47 ( V_2 -> V_4 ) ;
V_83 = F_48 ( V_77 , 0 ) ;
if ( V_83 <= 0 ) {
F_49 ( & V_77 -> V_19 , L_13 ) ;
return V_83 ;
}
V_2 -> V_16 = F_50 ( & V_77 -> V_19 , NULL ) ;
if ( F_46 ( V_2 -> V_16 ) ) {
F_49 ( & V_77 -> V_19 , L_14 ) ;
return F_47 ( V_2 -> V_16 ) ;
}
F_14 ( V_2 -> V_16 ) ;
F_51 ( V_2 -> V_66 . V_88 , L_15 , sizeof( V_2 -> V_66 . V_88 ) ) ;
V_2 -> V_19 = & V_77 -> V_19 ;
V_2 -> V_66 . V_89 = V_90 ;
V_2 -> V_66 . V_91 = & V_92 ;
V_2 -> V_66 . V_93 = 3 ;
V_2 -> V_66 . V_19 . V_80 = V_79 ;
V_2 -> V_66 . V_94 = V_2 ;
V_2 -> V_66 . V_19 . V_95 = & V_77 -> V_19 ;
F_52 ( & V_2 -> V_66 , V_2 ) ;
F_53 ( V_77 , V_2 ) ;
F_54 ( & V_2 -> V_51 ) ;
F_55 ( & V_2 -> V_58 ) ;
F_10 ( V_2 ) ;
V_50 = F_56 ( & V_77 -> V_19 , V_83 , F_24 ,
V_96 | V_97 ,
F_57 ( & V_77 -> V_19 ) , V_2 ) ;
if ( V_50 != 0 ) {
F_49 ( & V_77 -> V_19 , L_16 , V_83 ) ;
goto V_98;
}
F_58 ( & V_77 -> V_19 , true ) ;
F_59 ( V_2 -> V_19 , V_99 ) ;
F_60 ( V_2 -> V_19 ) ;
F_61 ( V_2 -> V_19 ) ;
F_62 ( V_2 -> V_19 ) ;
V_50 = F_63 ( & V_2 -> V_66 ) ;
if ( V_50 < 0 )
goto V_100;
return V_50 ;
V_100:
F_64 ( V_2 -> V_19 ) ;
F_65 ( V_2 -> V_19 ) ;
V_98:
F_12 ( V_2 -> V_16 ) ;
return V_50 ;
}
static int F_66 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_67 ( V_77 ) ;
F_68 ( & V_2 -> V_66 ) ;
F_64 ( V_2 -> V_19 ) ;
F_65 ( V_2 -> V_19 ) ;
return 0 ;
}
static int F_69 ( struct V_101 * V_19 )
{
struct V_76 * V_77 = F_70 ( V_19 ) ;
struct V_1 * V_2 = F_67 ( V_77 ) ;
F_12 ( V_2 -> V_16 ) ;
return 0 ;
}
static int F_71 ( struct V_101 * V_19 )
{
struct V_76 * V_77 = F_70 ( V_19 ) ;
struct V_1 * V_2 = F_67 ( V_77 ) ;
F_14 ( V_2 -> V_16 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
