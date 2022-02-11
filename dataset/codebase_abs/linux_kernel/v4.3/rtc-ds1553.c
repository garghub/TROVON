static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_9 ;
T_2 V_10 ;
V_10 = F_4 ( ( V_4 -> V_11 + 1900 ) / 100 ) ;
F_5 ( V_12 , V_8 -> V_9 + V_13 ) ;
F_5 ( F_4 ( V_4 -> V_11 % 100 ) , V_9 + V_14 ) ;
F_5 ( F_4 ( V_4 -> V_15 + 1 ) , V_9 + V_16 ) ;
F_5 ( F_4 ( V_4 -> V_17 ) & V_18 , V_9 + V_19 ) ;
F_5 ( F_4 ( V_4 -> V_20 ) , V_9 + V_21 ) ;
F_5 ( F_4 ( V_4 -> V_22 ) , V_9 + V_23 ) ;
F_5 ( F_4 ( V_4 -> V_24 ) , V_9 + V_25 ) ;
F_5 ( F_4 ( V_4 -> V_26 ) & V_27 , V_9 + V_28 ) ;
F_5 ( V_12 | ( V_10 & V_29 ) , V_9 + V_30 ) ;
F_5 ( V_10 & V_29 , V_9 + V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_9 ;
unsigned int V_31 , V_32 , V_33 , V_34 , V_35 , V_36 , V_37 ;
unsigned int V_10 ;
if ( V_8 -> V_38 == V_39 )
F_7 ( 1 ) ;
V_8 -> V_38 = V_39 ;
F_5 ( V_40 , V_9 + V_13 ) ;
V_36 = F_8 ( V_9 + V_28 ) & V_27 ;
V_35 = F_8 ( V_9 + V_25 ) ;
V_34 = F_8 ( V_9 + V_23 ) ;
V_33 = F_8 ( V_9 + V_21 ) ;
V_37 = F_8 ( V_9 + V_19 ) & V_18 ;
V_32 = F_8 ( V_9 + V_16 ) ;
V_31 = F_8 ( V_9 + V_14 ) ;
V_10 = F_8 ( V_9 + V_30 ) & V_29 ;
F_5 ( 0 , V_9 + V_13 ) ;
V_4 -> V_26 = F_9 ( V_36 ) ;
V_4 -> V_24 = F_9 ( V_35 ) ;
V_4 -> V_22 = F_9 ( V_34 ) ;
V_4 -> V_20 = F_9 ( V_33 ) ;
V_4 -> V_17 = F_9 ( V_37 ) ;
V_4 -> V_15 = F_9 ( V_32 ) - 1 ;
V_4 -> V_11 = F_9 ( V_31 ) + F_9 ( V_10 ) * 100 - 1900 ;
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
F_14 ( & V_8 -> V_42 , V_41 ) ;
F_5 ( V_8 -> V_43 < 0 || ( V_8 -> V_44 & V_45 ) ?
0x80 : F_4 ( V_8 -> V_43 ) ,
V_9 + V_46 ) ;
F_5 ( V_8 -> V_47 < 0 || ( V_8 -> V_44 & V_45 ) ?
0x80 : F_4 ( V_8 -> V_47 ) ,
V_9 + V_48 ) ;
F_5 ( V_8 -> V_49 < 0 || ( V_8 -> V_44 & V_45 ) ?
0x80 : F_4 ( V_8 -> V_49 ) ,
V_9 + V_50 ) ;
F_5 ( V_8 -> V_51 < 0 || ( V_8 -> V_44 & V_45 ) ?
0x80 : F_4 ( V_8 -> V_51 ) ,
V_9 + V_52 ) ;
F_5 ( V_8 -> V_44 ? V_53 : 0 , V_9 + V_54 ) ;
F_8 ( V_9 + V_55 ) ;
F_15 ( & V_8 -> V_42 , V_41 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_58 <= 0 )
return - V_59 ;
V_8 -> V_43 = V_57 -> time . V_20 ;
V_8 -> V_47 = V_57 -> time . V_22 ;
V_8 -> V_49 = V_57 -> time . V_24 ;
V_8 -> V_51 = V_57 -> time . V_26 ;
if ( V_57 -> V_60 )
V_8 -> V_44 |= V_61 ;
F_13 ( V_8 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_58 <= 0 )
return - V_59 ;
V_57 -> time . V_20 = V_8 -> V_43 < 0 ? 0 : V_8 -> V_43 ;
V_57 -> time . V_22 = V_8 -> V_47 < 0 ? 0 : V_8 -> V_47 ;
V_57 -> time . V_24 = V_8 -> V_49 < 0 ? 0 : V_8 -> V_49 ;
V_57 -> time . V_26 = V_8 -> V_51 < 0 ? 0 : V_8 -> V_51 ;
V_57 -> V_60 = ( V_8 -> V_44 & V_61 ) ? 1 : 0 ;
return 0 ;
}
static T_3 F_18 ( int V_58 , void * V_62 )
{
struct V_5 * V_6 = V_62 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_9 ;
unsigned long V_63 = 0 ;
F_19 ( & V_8 -> V_42 ) ;
if ( F_8 ( V_9 + V_55 ) & V_64 ) {
V_63 = V_65 ;
if ( F_8 ( V_9 + V_52 ) & 0x80 )
V_63 |= V_45 ;
else
V_63 |= V_61 ;
F_20 ( V_8 -> V_66 , 1 , V_63 ) ;
}
F_21 ( & V_8 -> V_42 ) ;
return V_63 ? V_67 : V_68 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_60 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_58 <= 0 )
return - V_59 ;
if ( V_60 )
V_8 -> V_44 |= V_61 ;
else
V_8 -> V_44 &= ~ V_61 ;
F_13 ( V_8 ) ;
return 0 ;
}
static T_4 F_23 ( struct V_69 * V_70 , struct V_71 * V_72 ,
struct V_73 * V_74 ,
char * V_75 , T_5 V_76 , T_6 V_77 )
{
struct V_1 * V_2 = F_24 ( V_72 , struct V_1 , V_72 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_9 ;
T_4 V_78 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ )
* V_75 ++ = F_8 ( V_9 + V_76 ++ ) ;
return V_78 ;
}
static T_4 F_25 ( struct V_69 * V_70 , struct V_71 * V_72 ,
struct V_73 * V_74 ,
char * V_75 , T_5 V_76 , T_6 V_77 )
{
struct V_1 * V_2 = F_24 ( V_72 , struct V_1 , V_72 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_8 -> V_9 ;
T_4 V_78 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ )
F_5 ( * V_75 ++ , V_9 + V_76 ++ ) ;
return V_78 ;
}
static int F_26 ( struct V_5 * V_6 )
{
struct V_79 * V_80 ;
unsigned int V_81 , V_82 ;
struct V_7 * V_8 ;
void T_1 * V_9 ;
int V_83 = 0 ;
V_8 = F_27 ( & V_6 -> V_2 , sizeof( * V_8 ) , V_84 ) ;
if ( ! V_8 )
return - V_85 ;
V_80 = F_28 ( V_6 , V_86 , 0 ) ;
V_9 = F_29 ( & V_6 -> V_2 , V_80 ) ;
if ( F_30 ( V_9 ) )
return F_31 ( V_9 ) ;
V_8 -> V_9 = V_9 ;
V_8 -> V_58 = F_32 ( V_6 , 0 ) ;
V_82 = F_8 ( V_9 + V_28 ) ;
if ( V_82 & V_87 ) {
V_82 &= V_27 ;
V_81 = F_8 ( V_9 + V_30 ) & V_29 ;
F_5 ( V_12 , V_9 + V_13 ) ;
F_5 ( V_82 , V_9 + V_28 ) ;
F_5 ( V_81 & V_29 , V_9 + V_13 ) ;
}
if ( F_8 ( V_9 + V_55 ) & V_88 )
F_33 ( & V_6 -> V_2 , L_2 ) ;
F_34 ( & V_8 -> V_42 ) ;
V_8 -> V_38 = V_39 ;
F_35 ( V_6 , V_8 ) ;
V_8 -> V_66 = F_36 ( & V_6 -> V_2 , V_6 -> V_89 ,
& V_90 , V_91 ) ;
if ( F_30 ( V_8 -> V_66 ) )
return F_31 ( V_8 -> V_66 ) ;
if ( V_8 -> V_58 > 0 ) {
F_5 ( 0 , V_9 + V_54 ) ;
if ( F_37 ( & V_6 -> V_2 , V_8 -> V_58 ,
F_18 ,
0 , V_6 -> V_89 , V_6 ) < 0 ) {
F_33 ( & V_6 -> V_2 , L_3 ) ;
V_8 -> V_58 = 0 ;
}
}
V_83 = F_38 ( & V_6 -> V_2 . V_72 , & V_92 ) ;
if ( V_83 )
F_11 ( & V_6 -> V_2 , L_4 ,
V_92 . V_93 . V_89 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_40 ( & V_6 -> V_2 . V_72 , & V_92 ) ;
if ( V_8 -> V_58 > 0 )
F_5 ( 0 , V_8 -> V_9 + V_54 ) ;
return 0 ;
}
