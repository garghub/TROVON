static unsigned int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
F_2 ( V_2 -> V_4 ) ;
V_3 = F_3 ( V_2 -> V_5 + V_6 ) ;
F_4 ( V_2 -> V_4 ) ;
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_3 ;
F_6 ( V_2 -> V_5 ) ;
V_3 = V_2 -> V_8 ;
F_7 ( 0x0 , V_2 -> V_5 + V_9 ) ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ )
F_7 ( 0x0 , V_2 -> V_5 + V_10 ) ;
F_7 ( 0x0 , V_2 -> V_5 + V_9 ) ;
F_7 ( 0x0 , V_2 -> V_5 + V_11 ) ;
F_7 ( V_2 -> V_12 , V_2 -> V_5 + V_13 ) ;
F_7 ( V_14 | V_15 ,
V_2 -> V_5 + V_16 ) ;
F_7 ( V_17 , V_2 -> V_5 + V_18 ) ;
F_8 ( V_2 -> V_5 ) ;
}
static int F_9 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 -> V_4 . V_21 ) ;
unsigned long V_22 ;
F_2 ( V_2 -> V_4 ) ;
F_11 ( & V_2 -> V_23 , V_22 ) ;
F_5 ( V_2 ) ;
V_2 -> V_24 = true ;
F_12 ( & V_2 -> V_23 , V_22 ) ;
F_13 ( V_2 -> V_4 , L_1 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_25 ;
F_6 ( V_2 -> V_5 ) ;
V_25 = F_3 ( V_2 -> V_5 + V_16 ) ;
V_25 |= V_26 ;
F_7 ( V_25 , V_2 -> V_5 + V_16 ) ;
V_25 |= V_27 ;
F_7 ( V_25 , V_2 -> V_5 + V_16 ) ;
if ( F_15 ( V_2 -> V_5 , V_16 , V_28 , 0 ) ) {
F_16 ( V_2 -> V_4 ,
L_2 ,
V_16 ) ;
}
F_7 ( 0x0 , V_2 -> V_5 + V_18 ) ;
if ( F_15 ( V_2 -> V_5 , V_29 , V_30 , 1 ) ) {
F_16 ( V_2 -> V_4 ,
L_2 ,
V_16 ) ;
}
F_8 ( V_2 -> V_5 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_7 ;
T_2 * V_31 ;
T_1 V_32 , V_3 ;
T_1 V_33 , V_34 ;
T_1 V_35 , V_36 ;
F_6 ( V_2 -> V_5 ) ;
V_33 = F_3 ( V_2 -> V_5 + V_11 ) ;
V_34 = F_3 ( V_2 -> V_5 + V_9 ) ;
V_35 = V_34 % V_37 ;
V_36 = V_37 - V_35 ;
if ( V_35 ) {
F_16 ( V_2 -> V_4 ,
L_3 ,
( unsigned long ) V_34 ) ;
F_16 ( V_2 -> V_4 , L_4 ,
( unsigned long ) V_35 , ( unsigned long ) V_36 ) ;
V_34 += V_36 ;
}
if ( ( F_3 ( V_2 -> V_5 + V_38 )
& V_39 ) == 0 )
F_7 ( 0x0 , V_2 -> V_5 + V_11 ) ;
else
F_7 ( V_34 , V_2 -> V_5 + V_11 ) ;
V_3 = V_2 -> V_8 ;
V_31 = V_2 -> V_40 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
V_32 = F_3 ( V_2 -> V_5 +
V_41 ) ;
* V_31 ++ = V_32 >> 0 ;
* V_31 ++ = V_32 >> 8 ;
* V_31 ++ = V_32 >> 16 ;
* V_31 ++ = V_32 >> 24 ;
}
if ( V_35 ) {
V_31 -= ( V_36 * 4 ) ;
for ( V_7 = 0 ; V_7 < V_36 ; V_7 ++ ) {
* V_31 ++ = 0x0 ;
* V_31 ++ = 0x0 ;
* V_31 ++ = 0x0 ;
* V_31 ++ = 0x0 ;
}
}
F_7 ( V_33 , V_2 -> V_5 + V_11 ) ;
F_8 ( V_2 -> V_5 ) ;
}
static void F_18 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 -> V_4 . V_21 ) ;
unsigned long V_22 ;
F_11 ( & V_2 -> V_23 , V_22 ) ;
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
V_2 -> V_24 = false ;
F_12 ( & V_2 -> V_23 , V_22 ) ;
F_4 ( V_2 -> V_4 ) ;
F_13 ( V_2 -> V_4 , L_5 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_11 ( & V_2 -> V_23 , V_22 ) ;
if ( V_2 -> V_24 ) {
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
F_5 ( V_2 ) ;
}
F_12 ( & V_2 -> V_23 , V_22 ) ;
F_13 ( V_2 -> V_4 , L_6 ) ;
}
static int F_20 ( struct V_42 * V_42 , struct V_43 * V_43 )
{
struct V_1 * V_2 = F_21 ( V_43 -> V_44 ,
struct V_1 , V_45 ) ;
if ( F_22 ( & V_2 -> V_46 , 0 , 1 ) )
return - V_47 ;
F_23 ( V_2 -> V_4 , L_7 , V_48 ) ;
return 0 ;
}
static T_3 F_24 ( struct V_43 * V_43 , char T_4 * V_49 ,
T_5 V_50 , T_6 * V_51 )
{
T_1 V_3 ;
struct V_1 * V_2 = F_21 ( V_43 -> V_44 ,
struct V_1 , V_45 ) ;
F_19 ( V_2 ) ;
V_3 = V_2 -> V_8 ;
if ( * V_51 + V_50 > V_3 * 4 )
V_50 = V_3 * 4 - * V_51 ;
if ( F_25 ( V_49 , V_2 -> V_40 + * V_51 , V_50 ) ) {
F_23 ( V_2 -> V_4 , L_8 , V_48 ) ;
return - V_52 ;
}
* V_51 += V_50 ;
F_23 ( V_2 -> V_4 , L_9 ,
V_48 , V_50 , ( int ) ( V_3 * 4 - * V_51 ) ) ;
return V_50 ;
}
static int F_26 ( struct V_42 * V_42 , struct V_43 * V_43 )
{
struct V_1 * V_2 = F_21 ( V_43 -> V_44 ,
struct V_1 , V_45 ) ;
F_27 ( & V_2 -> V_46 , 0 ) ;
F_23 ( V_2 -> V_4 , L_10 , V_48 ) ;
return 0 ;
}
static T_3 F_28 ( struct V_53 * V_4 ,
struct V_54 * V_55 , char * V_40 )
{
unsigned long V_22 ;
T_1 V_56 , V_57 , V_58 , V_59 ;
T_1 V_60 , V_61 , V_62 , V_63 ;
struct V_1 * V_2 = F_10 ( V_4 -> V_21 ) ;
F_2 ( V_2 -> V_4 ) ;
F_11 ( & V_2 -> V_23 , V_22 ) ;
F_6 ( V_2 -> V_5 ) ;
V_56 = F_3 ( V_2 -> V_5 + V_6 ) ;
V_57 = F_3 ( V_2 -> V_5 + V_38 ) ;
V_58 = F_3 ( V_2 -> V_5 + V_11 ) ;
V_59 = F_3 ( V_2 -> V_5 + V_9 ) ;
V_60 = F_3 ( V_2 -> V_5 + V_13 ) ;
V_61 = F_3 ( V_2 -> V_5 + V_18 ) ;
V_62 = F_3 ( V_2 -> V_5 + V_29 ) ;
V_63 = F_3 ( V_2 -> V_5 + V_16 ) ;
F_8 ( V_2 -> V_5 ) ;
F_12 ( & V_2 -> V_23 , V_22 ) ;
F_4 ( V_2 -> V_4 ) ;
return sprintf ( V_40 ,
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_18 ,
V_56 , V_57 , V_58 , V_59 ,
V_60 , V_61 , V_62 , V_63 ) ;
return - V_64 ;
}
static T_3 F_29 ( struct V_53 * V_4 ,
struct V_54 * V_55 , char * V_40 )
{
struct V_1 * V_2 = F_10 ( V_4 -> V_21 ) ;
unsigned long V_65 = V_2 -> V_12 ;
return sprintf ( V_40 , L_19 , V_65 ) ;
}
static T_3 F_30 ( struct V_53 * V_4 ,
struct V_54 * V_55 ,
const char * V_40 , T_5 V_66 )
{
int V_67 ;
unsigned long V_65 ;
struct V_1 * V_2 = F_10 ( V_4 -> V_21 ) ;
V_67 = F_31 ( V_40 , 16 , & V_65 ) ;
if ( V_67 )
return V_67 ;
V_2 -> V_12 = V_65 ;
return V_66 ;
}
static int F_32 ( struct V_68 * V_69 , const struct V_70 * V_71 )
{
int V_67 ;
void T_7 * V_5 ;
struct V_53 * V_4 = & V_69 -> V_4 ;
struct V_72 * V_73 = NULL ;
struct V_1 * V_2 ;
struct V_74 * V_75 = & V_69 -> V_75 ;
struct V_76 * V_77 ;
struct V_78 * V_79 = V_69 -> V_4 . V_80 ;
if ( V_79 ) {
V_73 = F_33 ( V_4 , V_79 ) ;
if ( F_34 ( V_73 ) )
return F_35 ( V_73 ) ;
V_69 -> V_4 . V_81 = V_73 ;
}
V_2 = F_36 ( V_4 , sizeof( * V_2 ) , V_82 ) ;
if ( ! V_2 )
return - V_83 ;
V_2 -> V_4 = & V_69 -> V_4 ;
V_2 -> V_84 = F_37 ( & V_69 -> V_4 , L_20 ) ;
if ( ! F_34 ( V_2 -> V_84 ) ) {
V_67 = F_38 ( V_2 -> V_84 ) ;
if ( V_67 )
return V_67 ;
}
F_39 ( V_4 , V_2 ) ;
V_5 = F_40 ( V_4 , V_75 ) ;
if ( F_34 ( V_5 ) )
return F_35 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
F_41 ( & V_2 -> V_23 ) ;
V_2 -> V_8 = F_1 ( V_2 ) ;
F_4 ( & V_69 -> V_4 ) ;
if ( V_2 -> V_8 & 0x80000000 )
return - V_64 ;
V_2 -> V_40 = F_36 ( V_4 ,
V_2 -> V_8 * 4 , V_82 ) ;
if ( ! V_2 -> V_40 ) {
F_16 ( V_4 , L_21 ,
V_2 -> V_8 * 4 ) ;
return - V_83 ;
}
V_77 = F_36 ( V_4 , sizeof( * V_77 ) , V_82 ) ;
if ( ! V_77 )
return - V_83 ;
V_77 -> type = V_85 ;
V_77 -> V_86 . V_87 = V_88 ;
V_77 -> V_89 = & V_90 ;
V_77 -> V_73 = V_73 ;
V_77 -> V_4 = V_4 ;
V_77 -> V_91 = V_92 ;
V_2 -> V_20 = F_42 ( V_77 ) ;
if ( F_34 ( V_2 -> V_20 ) )
return F_35 ( V_2 -> V_20 ) ;
V_2 -> V_45 . V_93 = V_73 -> V_93 ;
V_2 -> V_45 . V_94 = V_95 ;
V_2 -> V_45 . V_96 = & V_97 ;
V_67 = F_43 ( & V_2 -> V_45 ) ;
if ( V_67 )
goto V_98;
F_13 ( V_4 , L_22 ) ;
return 0 ;
V_98:
F_44 ( V_2 -> V_20 ) ;
return V_67 ;
}
static int F_45 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_46 ( V_69 ) ;
F_47 ( & V_2 -> V_45 ) ;
F_44 ( V_2 -> V_20 ) ;
return 0 ;
}
static int F_48 ( struct V_53 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
if ( V_2 && ! F_34 ( V_2 -> V_84 ) )
F_49 ( V_2 -> V_84 ) ;
return 0 ;
}
static int F_50 ( struct V_53 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
if ( V_2 && ! F_34 ( V_2 -> V_84 ) )
F_38 ( V_2 -> V_84 ) ;
return 0 ;
}
