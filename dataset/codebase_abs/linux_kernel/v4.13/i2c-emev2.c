static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
F_2 ( ( F_3 ( V_2 -> V_6 + V_5 ) & ~ V_3 ) | V_4 , V_2 -> V_6 + V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
int V_8 ;
F_5 ( & V_2 -> V_9 ) ;
V_7 = F_6 ( & V_2 -> V_9 , V_2 -> V_10 . V_11 ) ;
if ( ! V_7 )
return - V_12 ;
V_8 = F_3 ( V_2 -> V_6 + V_13 ) ;
return V_8 & V_14 ? - V_15 : V_8 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 , V_16 | V_17 , V_18 ) ;
F_4 ( V_2 ) ;
}
static void F_8 ( struct V_19 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
int V_20 ;
if ( F_3 ( V_2 -> V_6 + V_21 ) & V_22 ) {
F_2 ( 0 , V_2 -> V_6 + V_21 ) ;
V_20 = 1000 ;
while ( F_3 ( V_2 -> V_6 + V_21 ) == 1 && V_20 )
V_20 -- ;
F_10 ( V_20 == 0 ) ;
}
F_2 ( V_23 , V_2 -> V_6 + V_24 ) ;
F_2 ( V_25 | V_26 , V_2 -> V_6 + V_27 ) ;
F_2 ( V_28 , V_2 -> V_6 + V_18 ) ;
F_2 ( V_22 , V_2 -> V_6 + V_21 ) ;
V_20 = 1000 ;
while ( F_3 ( V_2 -> V_6 + V_21 ) == 0 && V_20 )
V_20 -- ;
F_10 ( V_20 == 0 ) ;
}
static int F_11 ( struct V_19 * V_10 , struct V_29 * V_30 ,
int V_31 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
int V_32 , V_8 , V_33 = ! ! ( V_30 -> V_34 & V_35 ) ;
F_1 ( V_2 , 0 , V_36 | V_28 , V_18 ) ;
F_1 ( V_2 , 0 , V_37 , V_18 ) ;
F_2 ( ( V_30 -> V_38 << 1 ) | V_33 , V_2 -> V_6 + V_39 ) ;
V_8 = F_4 ( V_2 ) ;
if ( V_8 < 0 )
goto V_40;
if ( ! ( V_8 & V_41 ) ) {
F_7 ( V_2 ) ;
goto V_42;
}
if ( V_33 ) {
F_1 ( V_2 , V_28 , V_36 , V_18 ) ;
F_1 ( V_2 , V_28 , V_43 , V_18 ) ;
V_8 = F_4 ( V_2 ) ;
if ( V_8 < 0 )
goto V_40;
}
for ( V_32 = 0 ; V_32 < V_30 -> V_44 ; V_32 ++ ) {
if ( V_33 ) {
V_30 -> V_45 [ V_32 ] = F_3 ( V_2 -> V_6 + V_39 ) ;
F_1 ( V_2 , 0 , V_43 , V_18 ) ;
} else {
if ( ! ( V_8 & V_41 ) ) {
F_7 ( V_2 ) ;
goto V_42;
}
F_2 ( V_30 -> V_45 [ V_32 ] , V_2 -> V_6 + V_39 ) ;
}
V_8 = F_4 ( V_2 ) ;
if ( V_8 < 0 )
goto V_40;
}
if ( V_31 )
F_7 ( V_2 ) ;
return V_32 ;
V_40:
F_8 ( V_10 ) ;
V_42:
return V_8 < 0 ? V_8 : - V_46 ;
}
static int F_12 ( struct V_19 * V_10 , struct V_29 * V_47 ,
int V_48 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
int V_49 , V_50 ;
if ( F_3 ( V_2 -> V_6 + V_27 ) & V_51 )
return - V_15 ;
for ( V_50 = 0 ; V_50 < V_48 ; V_50 ++ ) {
V_49 = F_11 ( V_10 , & V_47 [ V_50 ] , ( V_50 == ( V_48 - 1 ) ) ) ;
if ( V_49 < 0 )
return V_49 ;
}
return V_48 ;
}
static bool F_13 ( struct V_1 * V_2 )
{
T_1 V_8 , V_52 ;
enum V_53 V_54 ;
int V_49 ;
if ( ! V_2 -> V_55 )
return false ;
V_8 = F_3 ( V_2 -> V_6 + V_13 ) ;
if ( V_8 & V_56 ) {
F_1 ( V_2 , 0 , V_57 , V_18 ) ;
return true ;
}
if ( V_8 & V_58 ) {
V_53 ( V_2 -> V_55 , V_59 , & V_52 ) ;
return false ;
}
if ( ! ( V_8 & V_60 ) )
return false ;
F_1 ( V_2 , 0 , V_17 , V_18 ) ;
if ( V_8 & V_61 ) {
if ( V_8 & V_41 ) {
F_1 ( V_2 , 0 , V_28 , V_18 ) ;
V_54 = V_8 & V_62 ?
V_63 :
V_64 ;
V_53 ( V_2 -> V_55 , V_54 , & V_52 ) ;
F_2 ( V_52 , V_2 -> V_6 + V_39 ) ;
} else {
F_1 ( V_2 , 0 , V_57 , V_18 ) ;
}
} else {
F_1 ( V_2 , V_28 , V_36 ,
V_18 ) ;
F_1 ( V_2 , V_28 , V_43 ,
V_18 ) ;
if ( V_8 & V_62 ) {
V_53 ( V_2 -> V_55 , V_65 ,
& V_52 ) ;
} else {
V_52 = F_3 ( V_2 -> V_6 + V_39 ) ;
V_49 = V_53 ( V_2 -> V_55 ,
V_66 , & V_52 ) ;
if ( V_49 < 0 )
F_1 ( V_2 , V_36 , 0 ,
V_18 ) ;
}
}
return true ;
}
static T_2 F_14 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
if ( F_13 ( V_2 ) )
return V_69 ;
F_15 ( & V_2 -> V_9 ) ;
return V_69 ;
}
static T_3 F_16 ( struct V_19 * V_10 )
{
return V_70 | V_71 | V_72 ;
}
static int F_17 ( struct V_73 * V_55 )
{
struct V_1 * V_2 = F_9 ( V_55 -> V_74 ) ;
if ( V_2 -> V_55 )
return - V_75 ;
if ( V_55 -> V_34 & V_76 )
return - V_77 ;
V_2 -> V_55 = V_55 ;
F_2 ( V_55 -> V_38 << 1 , V_2 -> V_6 + V_78 ) ;
return 0 ;
}
static int F_18 ( struct V_73 * V_55 )
{
struct V_1 * V_2 = F_9 ( V_55 -> V_74 ) ;
F_10 ( ! V_2 -> V_55 ) ;
F_2 ( 0 , V_2 -> V_6 + V_78 ) ;
V_2 -> V_55 = NULL ;
return 0 ;
}
static int F_19 ( struct V_79 * V_80 )
{
struct V_1 * V_2 ;
struct V_81 * V_82 ;
int V_83 , V_49 ;
V_2 = F_20 ( & V_80 -> V_84 , sizeof( * V_2 ) , V_85 ) ;
if ( ! V_2 )
return - V_86 ;
V_82 = F_21 ( V_80 , V_87 , 0 ) ;
V_2 -> V_6 = F_22 ( & V_80 -> V_84 , V_82 ) ;
if ( F_23 ( V_2 -> V_6 ) )
return F_24 ( V_2 -> V_6 ) ;
F_25 ( V_2 -> V_10 . V_88 , L_1 , sizeof( V_2 -> V_10 . V_88 ) ) ;
V_2 -> V_89 = F_26 ( & V_80 -> V_84 , L_2 ) ;
if ( F_23 ( V_2 -> V_89 ) )
return F_24 ( V_2 -> V_89 ) ;
V_49 = F_27 ( V_2 -> V_89 ) ;
if ( V_49 )
return V_49 ;
V_2 -> V_10 . V_11 = F_28 ( 100 ) ;
V_2 -> V_10 . V_90 = 5 ;
V_2 -> V_10 . V_84 . V_91 = & V_80 -> V_84 ;
V_2 -> V_10 . V_92 = & V_93 ;
V_2 -> V_10 . V_94 = V_95 ;
V_2 -> V_10 . V_84 . V_96 = V_80 -> V_84 . V_96 ;
F_29 ( & V_2 -> V_9 ) ;
F_30 ( V_80 , V_2 ) ;
F_31 ( & V_2 -> V_10 , V_2 ) ;
F_8 ( & V_2 -> V_10 ) ;
V_83 = F_32 ( V_80 , 0 ) ;
V_49 = F_33 ( & V_80 -> V_84 , V_83 , F_14 , 0 ,
L_3 , V_2 ) ;
if ( V_49 )
goto V_97;
V_49 = F_34 ( & V_2 -> V_10 ) ;
if ( V_49 )
goto V_97;
F_35 ( & V_80 -> V_84 , L_4 , V_2 -> V_10 . V_98 , V_83 ) ;
return 0 ;
V_97:
F_36 ( V_2 -> V_89 ) ;
return V_49 ;
}
static int F_37 ( struct V_79 * V_84 )
{
struct V_1 * V_2 = F_38 ( V_84 ) ;
F_39 ( & V_2 -> V_10 ) ;
F_36 ( V_2 -> V_89 ) ;
return 0 ;
}
