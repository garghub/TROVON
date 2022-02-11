static unsigned int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 = 0 ;
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( V_3 )
return V_3 ;
V_4 = F_3 ( V_2 -> V_6 + V_7 ) ;
F_4 ( V_2 -> V_5 ) ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_8 ;
T_1 V_4 ;
F_6 ( V_2 -> V_6 ) ;
V_4 = V_2 -> V_9 ;
F_7 ( 0x0 , V_2 -> V_6 + V_10 ) ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ )
F_7 ( 0x0 , V_2 -> V_6 + V_11 ) ;
F_7 ( 0x0 , V_2 -> V_6 + V_10 ) ;
F_7 ( 0x0 , V_2 -> V_6 + V_12 ) ;
F_7 ( V_2 -> V_13 , V_2 -> V_6 + V_14 ) ;
F_7 ( V_15 | V_16 ,
V_2 -> V_6 + V_17 ) ;
F_7 ( V_18 , V_2 -> V_6 + V_19 ) ;
F_8 ( V_2 -> V_6 ) ;
}
static int F_9 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_10 ( V_21 -> V_22 . V_23 ) ;
int V_3 ;
unsigned long V_24 ;
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( V_3 )
return V_3 ;
F_11 ( & V_2 -> V_25 , V_24 ) ;
F_5 ( V_2 ) ;
V_2 -> V_26 = true ;
F_12 ( & V_2 -> V_25 , V_24 ) ;
F_13 ( V_2 -> V_22 , L_1 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_27 ;
F_6 ( V_2 -> V_6 ) ;
V_27 = F_3 ( V_2 -> V_6 + V_17 ) ;
V_27 |= V_28 ;
F_7 ( V_27 , V_2 -> V_6 + V_17 ) ;
V_27 |= V_29 ;
F_7 ( V_27 , V_2 -> V_6 + V_17 ) ;
if ( F_15 ( V_2 -> V_6 , V_17 , V_30 , 0 ) ) {
F_16 ( V_2 -> V_22 ,
L_2 ,
V_17 ) ;
}
F_7 ( 0x0 , V_2 -> V_6 + V_19 ) ;
if ( F_15 ( V_2 -> V_6 , V_31 , V_32 , 1 ) ) {
F_16 ( V_2 -> V_22 ,
L_2 ,
V_17 ) ;
}
F_8 ( V_2 -> V_6 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_8 ;
T_2 * V_33 ;
T_1 V_34 , V_4 ;
T_1 V_35 , V_36 ;
T_1 V_37 , V_38 ;
F_6 ( V_2 -> V_6 ) ;
V_35 = F_3 ( V_2 -> V_6 + V_12 ) ;
V_36 = F_3 ( V_2 -> V_6 + V_10 ) ;
V_37 = V_36 % V_39 ;
V_38 = V_39 - V_37 ;
if ( V_37 ) {
F_16 ( V_2 -> V_22 ,
L_3 ,
( unsigned long ) V_36 ) ;
F_16 ( V_2 -> V_22 , L_4 ,
( unsigned long ) V_37 , ( unsigned long ) V_38 ) ;
V_36 += V_38 ;
}
if ( ( F_3 ( V_2 -> V_6 + V_40 )
& V_41 ) == 0 )
F_7 ( 0x0 , V_2 -> V_6 + V_12 ) ;
else
F_7 ( V_36 , V_2 -> V_6 + V_12 ) ;
V_4 = V_2 -> V_9 ;
V_33 = V_2 -> V_42 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ ) {
V_34 = F_3 ( V_2 -> V_6 +
V_43 ) ;
* V_33 ++ = V_34 >> 0 ;
* V_33 ++ = V_34 >> 8 ;
* V_33 ++ = V_34 >> 16 ;
* V_33 ++ = V_34 >> 24 ;
}
if ( V_37 ) {
V_33 -= ( V_38 * 4 ) ;
for ( V_8 = 0 ; V_8 < V_38 ; V_8 ++ ) {
* V_33 ++ = 0x0 ;
* V_33 ++ = 0x0 ;
* V_33 ++ = 0x0 ;
* V_33 ++ = 0x0 ;
}
}
F_7 ( V_35 , V_2 -> V_6 + V_12 ) ;
F_8 ( V_2 -> V_6 ) ;
}
static void F_18 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_10 ( V_21 -> V_22 . V_23 ) ;
unsigned long V_24 ;
F_11 ( & V_2 -> V_25 , V_24 ) ;
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
V_2 -> V_26 = false ;
F_12 ( & V_2 -> V_25 , V_24 ) ;
F_4 ( V_2 -> V_5 ) ;
F_13 ( V_2 -> V_22 , L_5 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned long V_24 ;
F_11 ( & V_2 -> V_25 , V_24 ) ;
if ( V_2 -> V_26 ) {
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
F_5 ( V_2 ) ;
}
F_12 ( & V_2 -> V_25 , V_24 ) ;
F_13 ( V_2 -> V_22 , L_6 ) ;
}
static int F_20 ( struct V_44 * V_44 , struct V_45 * V_45 )
{
struct V_1 * V_2 = F_21 ( V_45 -> V_46 ,
struct V_1 , V_47 ) ;
if ( F_22 ( & V_2 -> V_48 , 0 , 1 ) )
return - V_49 ;
F_23 ( V_2 -> V_22 , L_7 , V_50 ) ;
return 0 ;
}
static T_3 F_24 ( struct V_45 * V_45 , char T_4 * V_51 ,
T_5 V_52 , T_6 * V_53 )
{
T_1 V_4 ;
struct V_1 * V_2 = F_21 ( V_45 -> V_46 ,
struct V_1 , V_47 ) ;
F_19 ( V_2 ) ;
V_4 = V_2 -> V_9 ;
if ( * V_53 + V_52 > V_4 * 4 )
V_52 = V_4 * 4 - * V_53 ;
if ( F_25 ( V_51 , V_2 -> V_42 + * V_53 , V_52 ) ) {
F_23 ( V_2 -> V_22 , L_8 , V_50 ) ;
return - V_54 ;
}
* V_53 += V_52 ;
F_23 ( V_2 -> V_22 , L_9 ,
V_50 , V_52 , ( int ) ( V_4 * 4 - * V_53 ) ) ;
return V_52 ;
}
static int F_26 ( struct V_44 * V_44 , struct V_45 * V_45 )
{
struct V_1 * V_2 = F_21 ( V_45 -> V_46 ,
struct V_1 , V_47 ) ;
F_27 ( & V_2 -> V_48 , 0 ) ;
F_23 ( V_2 -> V_22 , L_10 , V_50 ) ;
return 0 ;
}
static T_3 F_28 ( struct V_55 * V_22 ,
struct V_56 * V_57 , char * V_42 )
{
int V_3 ;
unsigned long V_24 ;
T_1 V_58 , V_59 , V_60 , V_61 ;
T_1 V_62 , V_63 , V_64 , V_65 ;
struct V_1 * V_2 = F_10 ( V_22 -> V_23 ) ;
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( V_3 )
goto V_66;
F_11 ( & V_2 -> V_25 , V_24 ) ;
F_6 ( V_2 -> V_6 ) ;
V_58 = F_3 ( V_2 -> V_6 + V_7 ) ;
V_59 = F_3 ( V_2 -> V_6 + V_40 ) ;
V_60 = F_3 ( V_2 -> V_6 + V_12 ) ;
V_61 = F_3 ( V_2 -> V_6 + V_10 ) ;
V_62 = F_3 ( V_2 -> V_6 + V_14 ) ;
V_63 = F_3 ( V_2 -> V_6 + V_19 ) ;
V_64 = F_3 ( V_2 -> V_6 + V_31 ) ;
V_65 = F_3 ( V_2 -> V_6 + V_17 ) ;
F_8 ( V_2 -> V_6 ) ;
F_12 ( & V_2 -> V_25 , V_24 ) ;
F_4 ( V_2 -> V_5 ) ;
return sprintf ( V_42 ,
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_18 ,
V_58 , V_59 , V_60 , V_61 ,
V_62 , V_63 , V_64 , V_65 ) ;
V_66:
return - V_67 ;
}
static T_3 F_29 ( struct V_55 * V_22 ,
struct V_56 * V_57 , char * V_42 )
{
struct V_1 * V_2 = F_10 ( V_22 -> V_23 ) ;
unsigned long V_68 = V_2 -> V_13 ;
return sprintf ( V_42 , L_19 , V_68 ) ;
}
static T_3 F_30 ( struct V_55 * V_22 ,
struct V_56 * V_57 ,
const char * V_42 , T_5 V_69 )
{
int V_3 ;
unsigned long V_68 ;
struct V_1 * V_2 = F_10 ( V_22 -> V_23 ) ;
V_3 = F_31 ( V_42 , 16 , & V_68 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_13 = V_68 ;
return V_69 ;
}
static int F_32 ( struct V_70 * V_71 , const struct V_72 * V_73 )
{
int V_3 ;
void T_7 * V_6 ;
struct V_55 * V_22 = & V_71 -> V_22 ;
struct V_74 * V_75 = NULL ;
struct V_1 * V_2 ;
struct V_76 * V_77 = & V_71 -> V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 = V_71 -> V_22 . V_82 ;
if ( V_81 ) {
V_75 = F_33 ( V_22 , V_81 ) ;
if ( F_34 ( V_75 ) )
return F_35 ( V_75 ) ;
V_71 -> V_22 . V_83 = V_75 ;
}
V_2 = F_36 ( V_22 , sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_22 = & V_71 -> V_22 ;
F_37 ( V_22 , V_2 ) ;
V_6 = F_38 ( V_22 , V_77 ) ;
if ( F_34 ( V_6 ) )
return F_35 ( V_6 ) ;
V_2 -> V_6 = V_6 ;
F_39 ( & V_2 -> V_25 ) ;
V_2 -> V_5 = V_71 -> V_86 ;
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_9 = F_1 ( V_2 ) ;
F_4 ( V_2 -> V_5 ) ;
if ( V_2 -> V_9 < 0 )
return - V_67 ;
V_2 -> V_42 = F_36 ( V_22 ,
V_2 -> V_9 * 4 , V_84 ) ;
if ( ! V_2 -> V_42 )
return - V_85 ;
V_79 = F_36 ( V_22 , sizeof( * V_79 ) , V_84 ) ;
if ( ! V_79 )
return - V_85 ;
V_79 -> type = V_87 ;
V_79 -> V_88 . V_89 = V_90 ;
V_79 -> V_91 = & V_92 ;
V_79 -> V_75 = V_75 ;
V_79 -> V_22 = V_22 ;
V_79 -> V_93 = V_94 ;
V_2 -> V_21 = F_40 ( V_79 ) ;
if ( F_34 ( V_2 -> V_21 ) )
return F_35 ( V_2 -> V_21 ) ;
V_2 -> V_47 . V_95 = V_75 -> V_95 ;
V_2 -> V_47 . V_96 = V_97 ;
V_2 -> V_47 . V_98 = & V_99 ;
V_3 = F_41 ( & V_2 -> V_47 ) ;
if ( V_3 )
goto V_100;
F_13 ( V_22 , L_20 ) ;
return 0 ;
V_100:
F_42 ( V_2 -> V_21 ) ;
return V_3 ;
}
static int F_43 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_44 ( V_71 ) ;
F_45 ( & V_2 -> V_47 ) ;
F_42 ( V_2 -> V_21 ) ;
return 0 ;
}
