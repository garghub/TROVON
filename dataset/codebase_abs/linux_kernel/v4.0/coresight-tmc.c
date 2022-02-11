static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ,
V_4 , V_5 , 1 ) ) {
F_3 ( V_2 -> V_6 ,
L_1 ,
V_4 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_7 ;
V_7 = F_5 ( V_2 -> V_3 + V_8 ) ;
V_7 |= V_9 ;
F_6 ( V_7 , V_2 -> V_3 + V_8 ) ;
V_7 |= V_10 ;
F_6 ( V_7 , V_2 -> V_3 + V_8 ) ;
if ( F_2 ( V_2 -> V_3 ,
V_8 , V_11 , 0 ) ) {
F_3 ( V_2 -> V_6 ,
L_1 ,
V_8 ) ;
}
F_1 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_6 ( V_12 , V_2 -> V_3 + V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_6 ( 0x0 , V_2 -> V_3 + V_13 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_14 , 0 , V_2 -> V_15 ) ;
F_10 ( V_2 -> V_3 ) ;
F_6 ( V_16 , V_2 -> V_3 + V_17 ) ;
F_6 ( V_18 | V_19 |
V_20 | V_21 |
V_22 ,
V_2 -> V_3 + V_8 ) ;
F_6 ( V_2 -> V_23 , V_2 -> V_3 + V_24 ) ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_25 ;
memset ( V_2 -> V_26 , 0 , V_2 -> V_15 ) ;
F_10 ( V_2 -> V_3 ) ;
F_6 ( V_2 -> V_15 / 4 , V_2 -> V_3 + V_27 ) ;
F_6 ( V_16 , V_2 -> V_3 + V_17 ) ;
V_25 = F_5 ( V_2 -> V_3 + V_28 ) ;
V_25 |= V_29 ;
F_6 ( V_25 , V_2 -> V_3 + V_28 ) ;
V_25 &= ~ V_30 ;
F_6 ( V_25 , V_2 -> V_3 + V_28 ) ;
V_25 = ( V_25 &
~ ( V_31 | V_32 ) ) |
V_32 ;
F_6 ( V_25 , V_2 -> V_3 + V_28 ) ;
F_6 ( V_2 -> V_33 , V_2 -> V_3 + V_34 ) ;
F_6 ( 0x0 , V_2 -> V_3 + V_35 ) ;
F_6 ( V_18 | V_19 |
V_20 | V_21 |
V_22 ,
V_2 -> V_3 + V_8 ) ;
F_6 ( V_2 -> V_23 , V_2 -> V_3 + V_24 ) ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_3 ) ;
F_6 ( V_36 , V_2 -> V_3 + V_17 ) ;
F_6 ( V_18 | V_19 ,
V_2 -> V_3 + V_8 ) ;
F_6 ( 0x0 , V_2 -> V_3 + V_37 ) ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static int F_14 ( struct V_1 * V_2 , enum V_38 V_39 )
{
int V_40 ;
unsigned long V_41 ;
V_40 = F_15 ( V_2 -> V_42 ) ;
if ( V_40 )
return V_40 ;
F_16 ( & V_2 -> V_43 , V_41 ) ;
if ( V_2 -> V_44 ) {
F_17 ( & V_2 -> V_43 , V_41 ) ;
F_18 ( V_2 -> V_42 ) ;
return - V_45 ;
}
if ( V_2 -> V_46 == V_47 ) {
F_9 ( V_2 ) ;
} else if ( V_2 -> V_46 == V_48 ) {
F_12 ( V_2 ) ;
} else {
if ( V_39 == V_16 )
F_9 ( V_2 ) ;
else
F_13 ( V_2 ) ;
}
V_2 -> V_49 = true ;
F_17 ( & V_2 -> V_43 , V_41 ) ;
F_19 ( V_2 -> V_6 , L_2 ) ;
return 0 ;
}
static int F_20 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_21 ( V_51 -> V_6 . V_52 ) ;
return F_14 ( V_2 , V_16 ) ;
}
static int F_22 ( struct V_50 * V_51 , int V_53 ,
int V_54 )
{
struct V_1 * V_2 = F_21 ( V_51 -> V_6 . V_52 ) ;
return F_14 ( V_2 , V_36 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
enum V_55 V_56 ;
T_2 V_57 ;
char * V_58 ;
T_1 V_59 ;
int V_60 ;
V_56 = F_24 ( F_5 ( V_2 -> V_3 + V_61 ) , 8 , 10 ) ;
if ( V_56 == V_62 )
V_57 = 1 ;
else if ( V_56 == V_63 )
V_57 = 2 ;
else if ( V_56 == V_64 )
V_57 = 4 ;
else
V_57 = 8 ;
V_58 = V_2 -> V_14 ;
while ( 1 ) {
for ( V_60 = 0 ; V_60 < V_57 ; V_60 ++ ) {
V_59 = F_5 ( V_2 -> V_3 + V_65 ) ;
if ( V_59 == 0xFFFFFFFF )
return;
memcpy ( V_58 , & V_59 , 4 ) ;
V_58 += 4 ;
}
}
}
static void F_25 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
F_23 ( V_2 ) ;
F_8 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_66 , V_67 ;
V_66 = F_5 ( V_2 -> V_3 + V_68 ) ;
V_67 = F_5 ( V_2 -> V_3 + V_4 ) ;
if ( V_67 & F_27 ( 0 ) )
V_2 -> V_14 = V_2 -> V_26 + V_66 - V_2 -> V_33 ;
else
V_2 -> V_14 = V_2 -> V_26 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
F_26 ( V_2 ) ;
F_8 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
F_8 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static void F_30 ( struct V_1 * V_2 , enum V_38 V_39 )
{
unsigned long V_41 ;
F_16 ( & V_2 -> V_43 , V_41 ) ;
if ( V_2 -> V_44 )
goto V_69;
if ( V_2 -> V_46 == V_47 ) {
F_25 ( V_2 ) ;
} else if ( V_2 -> V_46 == V_48 ) {
F_28 ( V_2 ) ;
} else {
if ( V_39 == V_16 )
F_25 ( V_2 ) ;
else
F_29 ( V_2 ) ;
}
V_69:
V_2 -> V_49 = false ;
F_17 ( & V_2 -> V_43 , V_41 ) ;
F_18 ( V_2 -> V_42 ) ;
F_19 ( V_2 -> V_6 , L_3 ) ;
}
static void F_31 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_21 ( V_51 -> V_6 . V_52 ) ;
F_30 ( V_2 , V_16 ) ;
}
static void F_32 ( struct V_50 * V_51 , int V_53 ,
int V_54 )
{
struct V_1 * V_2 = F_21 ( V_51 -> V_6 . V_52 ) ;
F_30 ( V_2 , V_36 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_40 ;
unsigned long V_41 ;
enum V_38 V_39 ;
F_16 ( & V_2 -> V_43 , V_41 ) ;
if ( ! V_2 -> V_49 )
goto V_69;
if ( V_2 -> V_46 == V_47 ) {
F_25 ( V_2 ) ;
} else if ( V_2 -> V_46 == V_48 ) {
F_28 ( V_2 ) ;
} else {
V_39 = F_5 ( V_2 -> V_3 + V_17 ) ;
if ( V_39 == V_16 ) {
F_25 ( V_2 ) ;
} else {
V_40 = - V_70 ;
goto V_71;
}
}
V_69:
V_2 -> V_44 = true ;
F_17 ( & V_2 -> V_43 , V_41 ) ;
F_19 ( V_2 -> V_6 , L_4 ) ;
return 0 ;
V_71:
F_17 ( & V_2 -> V_43 , V_41 ) ;
return V_40 ;
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned long V_41 ;
enum V_38 V_39 ;
F_16 ( & V_2 -> V_43 , V_41 ) ;
if ( ! V_2 -> V_49 )
goto V_69;
if ( V_2 -> V_46 == V_47 ) {
F_9 ( V_2 ) ;
} else if ( V_2 -> V_46 == V_48 ) {
F_12 ( V_2 ) ;
} else {
V_39 = F_5 ( V_2 -> V_3 + V_17 ) ;
if ( V_39 == V_16 )
F_9 ( V_2 ) ;
}
V_69:
V_2 -> V_44 = false ;
F_17 ( & V_2 -> V_43 , V_41 ) ;
F_19 ( V_2 -> V_6 , L_5 ) ;
}
static int F_35 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
struct V_1 * V_2 = F_36 ( V_73 -> V_74 ,
struct V_1 , V_75 ) ;
int V_40 = 0 ;
if ( V_2 -> V_76 ++ )
goto V_69;
V_40 = F_33 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_69:
F_37 ( V_72 , V_73 ) ;
F_38 ( V_2 -> V_6 , L_6 , V_77 ) ;
return 0 ;
}
static T_3 F_39 ( struct V_73 * V_73 , char T_4 * V_78 , T_5 V_79 ,
T_6 * V_80 )
{
struct V_1 * V_2 = F_36 ( V_73 -> V_74 ,
struct V_1 , V_75 ) ;
char * V_58 = V_2 -> V_14 + * V_80 ;
if ( * V_80 + V_79 > V_2 -> V_15 )
V_79 = V_2 -> V_15 - * V_80 ;
if ( V_2 -> V_46 == V_48 ) {
if ( V_58 == ( char * ) ( V_2 -> V_26 + V_2 -> V_15 ) )
V_58 = V_2 -> V_26 ;
else if ( V_58 > ( char * ) ( V_2 -> V_26 + V_2 -> V_15 ) )
V_58 -= V_2 -> V_15 ;
if ( ( V_58 + V_79 ) > ( char * ) ( V_2 -> V_26 + V_2 -> V_15 ) )
V_79 = ( char * ) ( V_2 -> V_26 + V_2 -> V_15 ) - V_58 ;
}
if ( F_40 ( V_78 , V_58 , V_79 ) ) {
F_38 ( V_2 -> V_6 , L_7 , V_77 ) ;
return - V_81 ;
}
* V_80 += V_79 ;
F_38 ( V_2 -> V_6 , L_8 ,
V_77 , V_79 , ( int ) ( V_2 -> V_15 - * V_80 ) ) ;
return V_79 ;
}
static int F_41 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
struct V_1 * V_2 = F_36 ( V_73 -> V_74 ,
struct V_1 , V_75 ) ;
if ( -- V_2 -> V_76 ) {
if ( V_2 -> V_76 < 0 ) {
F_3 ( V_2 -> V_6 , L_9 ) ;
V_2 -> V_76 = 0 ;
}
goto V_69;
}
F_34 ( V_2 ) ;
V_69:
F_38 ( V_2 -> V_6 , L_10 , V_77 ) ;
return 0 ;
}
static T_3 F_42 ( struct V_82 * V_6 ,
struct V_83 * V_84 , char * V_14 )
{
struct V_1 * V_2 = F_21 ( V_6 -> V_52 ) ;
unsigned long V_67 = V_2 -> V_23 ;
return sprintf ( V_14 , L_11 , V_67 ) ;
}
static T_3 F_43 ( struct V_82 * V_6 ,
struct V_83 * V_84 ,
const char * V_14 , T_5 V_15 )
{
int V_40 ;
unsigned long V_67 ;
struct V_1 * V_2 = F_21 ( V_6 -> V_52 ) ;
V_40 = F_44 ( V_14 , 16 , & V_67 ) ;
if ( V_40 )
return V_40 ;
V_2 -> V_23 = V_67 ;
return V_15 ;
}
static int F_45 ( struct V_85 * V_86 , const struct V_87 * V_88 )
{
int V_40 = 0 ;
T_1 V_89 ;
void T_7 * V_3 ;
struct V_82 * V_6 = & V_86 -> V_6 ;
struct V_90 * V_91 = NULL ;
struct V_1 * V_2 ;
struct V_92 * V_93 = & V_86 -> V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 = V_86 -> V_6 . V_98 ;
if ( V_97 ) {
V_91 = F_46 ( V_6 , V_97 ) ;
if ( F_47 ( V_91 ) )
return F_48 ( V_91 ) ;
V_86 -> V_6 . V_99 = V_91 ;
}
V_2 = F_49 ( V_6 , sizeof( * V_2 ) , V_100 ) ;
if ( ! V_2 )
return - V_101 ;
V_2 -> V_6 = & V_86 -> V_6 ;
F_50 ( V_6 , V_2 ) ;
V_3 = F_51 ( V_6 , V_93 ) ;
if ( F_47 ( V_3 ) )
return F_48 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
F_52 ( & V_2 -> V_43 ) ;
V_2 -> V_42 = V_86 -> V_102 ;
V_40 = F_15 ( V_2 -> V_42 ) ;
if ( V_40 )
return V_40 ;
V_89 = F_5 ( V_2 -> V_3 + V_61 ) ;
V_2 -> V_46 = F_24 ( V_89 , 6 , 7 ) ;
if ( V_2 -> V_46 == V_48 ) {
if ( V_97 )
V_40 = F_53 ( V_97 ,
L_12 ,
& V_2 -> V_15 ) ;
if ( V_40 )
V_2 -> V_15 = V_103 ;
} else {
V_2 -> V_15 = F_5 ( V_2 -> V_3 + V_27 ) * 4 ;
}
F_18 ( V_2 -> V_42 ) ;
if ( V_2 -> V_46 == V_48 ) {
V_2 -> V_26 = F_54 ( V_6 , V_2 -> V_15 ,
& V_2 -> V_33 , V_100 ) ;
if ( ! V_2 -> V_26 )
return - V_101 ;
memset ( V_2 -> V_26 , 0 , V_2 -> V_15 ) ;
V_2 -> V_14 = V_2 -> V_26 ;
} else {
V_2 -> V_14 = F_49 ( V_6 , V_2 -> V_15 , V_100 ) ;
if ( ! V_2 -> V_14 )
return - V_101 ;
}
V_95 = F_49 ( V_6 , sizeof( * V_95 ) , V_100 ) ;
if ( ! V_95 ) {
V_40 = - V_101 ;
goto V_104;
}
V_95 -> V_91 = V_91 ;
V_95 -> V_6 = V_6 ;
V_95 -> V_105 . V_106 = V_107 ;
if ( V_2 -> V_46 == V_47 ) {
V_95 -> type = V_108 ;
V_95 -> V_109 = & V_110 ;
V_95 -> V_111 = V_112 ;
} else if ( V_2 -> V_46 == V_48 ) {
V_95 -> type = V_108 ;
V_95 -> V_109 = & V_113 ;
V_95 -> V_111 = V_114 ;
} else {
V_95 -> type = V_115 ;
V_95 -> V_105 . V_116 = V_117 ;
V_95 -> V_109 = & V_118 ;
V_95 -> V_111 = V_119 ;
}
V_2 -> V_51 = F_55 ( V_95 ) ;
if ( F_47 ( V_2 -> V_51 ) ) {
V_40 = F_48 ( V_2 -> V_51 ) ;
goto V_104;
}
V_2 -> V_75 . V_120 = V_91 -> V_120 ;
V_2 -> V_75 . V_121 = V_122 ;
V_2 -> V_75 . V_123 = & V_124 ;
V_40 = F_56 ( & V_2 -> V_75 ) ;
if ( V_40 )
goto V_125;
F_19 ( V_6 , L_13 ) ;
return 0 ;
V_125:
F_57 ( V_2 -> V_51 ) ;
V_104:
if ( V_2 -> V_46 == V_48 )
F_58 ( V_6 , V_2 -> V_15 ,
& V_2 -> V_33 , V_100 ) ;
return V_40 ;
}
static int F_59 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = F_60 ( V_86 ) ;
F_61 ( & V_2 -> V_75 ) ;
F_57 ( V_2 -> V_51 ) ;
if ( V_2 -> V_46 == V_48 )
F_58 ( V_2 -> V_6 , V_2 -> V_15 ,
& V_2 -> V_33 , V_100 ) ;
return 0 ;
}
