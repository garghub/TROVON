static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_9 ;
T_2 V_10 ;
V_10 = F_4 ( V_8 -> V_9 + V_11 ) ;
F_5 ( V_10 | V_12 , V_8 -> V_9 + V_11 ) ;
F_5 ( F_6 ( V_4 -> V_13 % 100 ) , V_9 + V_14 ) ;
F_5 ( F_6 ( V_4 -> V_15 + 1 ) , V_9 + V_16 ) ;
F_5 ( F_6 ( V_4 -> V_17 ) & V_18 , V_9 + V_19 ) ;
F_5 ( F_6 ( V_4 -> V_20 ) , V_9 + V_21 ) ;
F_5 ( F_6 ( V_4 -> V_22 ) , V_9 + V_23 ) ;
F_5 ( F_6 ( V_4 -> V_24 ) , V_9 + V_25 ) ;
F_5 ( F_6 ( V_4 -> V_26 ) & V_27 , V_9 + V_28 ) ;
F_5 ( F_6 ( ( V_4 -> V_13 + 1900 ) / 100 ) , V_9 + V_29 ) ;
F_5 ( V_10 & ~ V_12 , V_8 -> V_9 + V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_9 ;
unsigned int V_30 , V_31 , V_32 , V_33 , V_34 , V_35 , V_36 ;
unsigned int V_37 ;
T_2 V_10 ;
if ( V_8 -> V_38 == V_39 )
F_8 ( 1 ) ;
V_8 -> V_38 = V_39 ;
V_10 = F_4 ( V_8 -> V_9 + V_11 ) ;
F_5 ( V_10 | V_40 , V_9 + V_11 ) ;
V_35 = F_4 ( V_9 + V_28 ) & V_27 ;
V_34 = F_4 ( V_9 + V_25 ) ;
V_33 = F_4 ( V_9 + V_23 ) ;
V_32 = F_4 ( V_9 + V_21 ) ;
V_36 = F_4 ( V_9 + V_19 ) & V_18 ;
V_31 = F_4 ( V_9 + V_16 ) ;
V_30 = F_4 ( V_9 + V_14 ) ;
V_37 = F_4 ( V_9 + V_29 ) ;
F_5 ( V_10 & ~ V_40 , V_9 + V_11 ) ;
V_4 -> V_26 = F_9 ( V_35 ) ;
V_4 -> V_24 = F_9 ( V_34 ) ;
V_4 -> V_22 = F_9 ( V_33 ) ;
V_4 -> V_20 = F_9 ( V_32 ) ;
V_4 -> V_17 = F_9 ( V_36 ) ;
V_4 -> V_15 = F_9 ( V_31 ) - 1 ;
V_4 -> V_13 = F_9 ( V_30 ) + F_9 ( V_37 ) * 100 - 1900 ;
if ( F_10 ( V_4 ) < 0 ) {
F_11 ( V_2 , L_1 ) ;
F_12 ( 0 , V_4 ) ;
}
return 0 ;
}
static void F_13 ( struct V_7 * V_8 )
{
void T_1 * V_9 = V_8 -> V_9 ;
unsigned long V_41 ;
T_2 V_10 ;
F_14 ( & V_8 -> V_42 , V_41 ) ;
V_10 = F_4 ( V_9 + V_11 ) ;
F_5 ( V_10 | V_12 , V_9 + V_11 ) ;
F_5 ( V_8 -> V_43 < 0 || ( V_8 -> V_44 & V_45 ) ?
0x80 : F_6 ( V_8 -> V_43 ) ,
V_9 + V_46 ) ;
F_5 ( V_8 -> V_47 < 0 || ( V_8 -> V_44 & V_45 ) ?
0x80 : F_6 ( V_8 -> V_47 ) ,
V_9 + V_48 ) ;
F_5 ( V_8 -> V_49 < 0 || ( V_8 -> V_44 & V_45 ) ?
0x80 : F_6 ( V_8 -> V_49 ) ,
V_9 + V_50 ) ;
F_5 ( V_8 -> V_51 < 0 || ( V_8 -> V_44 & V_45 ) ?
0x80 : F_6 ( V_8 -> V_51 ) ,
V_9 + V_52 ) ;
F_5 ( V_8 -> V_44 ? V_53 : 0 , V_9 + V_54 ) ;
F_4 ( V_9 + V_11 ) ;
F_5 ( V_10 & ~ V_12 , V_9 + V_11 ) ;
F_15 ( & V_8 -> V_42 , V_41 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_57 <= 0 )
return - V_58 ;
V_8 -> V_43 = V_56 -> time . V_20 ;
V_8 -> V_47 = V_56 -> time . V_22 ;
V_8 -> V_49 = V_56 -> time . V_24 ;
V_8 -> V_51 = V_56 -> time . V_26 ;
if ( V_56 -> V_59 )
V_8 -> V_44 |= V_60 ;
F_13 ( V_8 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_57 <= 0 )
return - V_58 ;
V_56 -> time . V_20 = V_8 -> V_43 < 0 ? 0 : V_8 -> V_43 ;
V_56 -> time . V_22 = V_8 -> V_47 < 0 ? 0 : V_8 -> V_47 ;
V_56 -> time . V_24 = V_8 -> V_49 < 0 ? 0 : V_8 -> V_49 ;
V_56 -> time . V_26 = V_8 -> V_51 < 0 ? 0 : V_8 -> V_51 ;
V_56 -> V_59 = ( V_8 -> V_44 & V_60 ) ? 1 : 0 ;
return 0 ;
}
static T_3 F_18 ( int V_57 , void * V_61 )
{
struct V_5 * V_6 = V_61 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_9 ;
unsigned long V_62 = 0 ;
F_19 ( & V_8 -> V_42 ) ;
if ( F_4 ( V_9 + V_11 ) & V_63 ) {
V_62 = V_64 ;
if ( F_4 ( V_9 + V_52 ) & 0x80 )
V_62 |= V_45 ;
else
V_62 |= V_60 ;
if ( F_20 ( V_8 -> V_65 ) )
F_21 ( V_8 -> V_65 , 1 , V_62 ) ;
}
F_22 ( & V_8 -> V_42 ) ;
return V_62 ? V_66 : V_67 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned int V_59 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_57 <= 0 )
return - V_58 ;
if ( V_59 )
V_8 -> V_44 |= V_60 ;
else
V_8 -> V_44 &= ~ V_60 ;
F_13 ( V_8 ) ;
return 0 ;
}
static T_4 F_24 ( struct V_68 * V_69 , struct V_70 * V_71 ,
struct V_72 * V_73 , char * V_74 ,
T_5 V_75 , T_6 V_76 )
{
struct V_1 * V_2 = F_25 ( V_71 , struct V_1 , V_71 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_9 ;
T_4 V_77 ;
for ( V_77 = 0 ; V_76 > 0 && V_75 < V_78 ; V_77 ++ , V_76 -- )
* V_74 ++ = F_4 ( V_9 + V_75 ++ ) ;
return V_77 ;
}
static T_4 F_26 ( struct V_68 * V_69 , struct V_70 * V_71 ,
struct V_72 * V_73 , char * V_74 ,
T_5 V_75 , T_6 V_76 )
{
struct V_1 * V_2 = F_25 ( V_71 , struct V_1 , V_71 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_9 ;
T_4 V_77 ;
for ( V_77 = 0 ; V_76 > 0 && V_75 < V_78 ; V_77 ++ , V_76 -- )
F_5 ( * V_74 ++ , V_9 + V_75 ++ ) ;
return V_77 ;
}
static int T_7 F_27 ( struct V_5 * V_6 )
{
struct V_79 * V_80 ;
unsigned int V_81 ;
unsigned int V_10 ;
struct V_7 * V_8 ;
void T_1 * V_9 ;
int V_82 = 0 ;
V_80 = F_28 ( V_6 , V_83 , 0 ) ;
if ( ! V_80 )
return - V_84 ;
V_8 = F_29 ( & V_6 -> V_2 , sizeof( * V_8 ) , V_85 ) ;
if ( ! V_8 )
return - V_86 ;
if ( ! F_30 ( & V_6 -> V_2 , V_80 -> V_87 , V_88 ,
V_6 -> V_89 ) )
return - V_90 ;
V_9 = F_31 ( & V_6 -> V_2 , V_80 -> V_87 , V_88 ) ;
if ( ! V_9 )
return - V_86 ;
V_8 -> V_9 = V_9 ;
V_8 -> V_57 = F_32 ( V_6 , 0 ) ;
V_81 = F_4 ( V_9 + V_91 ) ;
if ( V_81 & V_92 ) {
V_81 &= V_93 ;
V_10 = F_4 ( V_9 + V_11 ) ;
F_5 ( V_10 | V_12 , V_9 + V_11 ) ;
F_5 ( V_81 , V_9 + V_91 ) ;
F_5 ( V_10 & ~ V_12 , V_9 + V_11 ) ;
}
if ( F_4 ( V_9 + V_11 ) & V_94 )
F_33 ( & V_6 -> V_2 , L_2 ) ;
F_34 ( & V_8 -> V_42 ) ;
V_8 -> V_38 = V_39 ;
F_35 ( V_6 , V_8 ) ;
if ( V_8 -> V_57 > 0 ) {
F_5 ( 0 , V_9 + V_54 ) ;
if ( F_36 ( & V_6 -> V_2 , V_8 -> V_57 ,
F_18 ,
V_95 ,
V_6 -> V_89 , V_6 ) < 0 ) {
F_33 ( & V_6 -> V_2 , L_3 ) ;
V_8 -> V_57 = 0 ;
}
}
V_8 -> V_65 = F_37 ( V_6 -> V_89 , & V_6 -> V_2 ,
& V_96 , V_97 ) ;
if ( F_38 ( V_8 -> V_65 ) )
return F_39 ( V_8 -> V_65 ) ;
V_82 = F_40 ( & V_6 -> V_2 . V_71 , & V_98 ) ;
if ( V_82 )
F_41 ( V_8 -> V_65 ) ;
return V_82 ;
}
static int T_8 F_42 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_43 ( & V_6 -> V_2 . V_71 , & V_98 ) ;
F_41 ( V_8 -> V_65 ) ;
if ( V_8 -> V_57 > 0 )
F_5 ( 0 , V_8 -> V_9 + V_54 ) ;
return 0 ;
}
