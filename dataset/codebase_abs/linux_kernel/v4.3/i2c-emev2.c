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
static T_2 F_13 ( int V_52 , void * V_53 )
{
struct V_1 * V_2 = V_53 ;
F_14 ( & V_2 -> V_9 ) ;
return V_54 ;
}
static T_3 F_15 ( struct V_19 * V_10 )
{
return V_55 | V_56 ;
}
static int F_16 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_59 * V_60 ;
int V_61 , V_49 ;
V_2 = F_17 ( & V_58 -> V_62 , sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 )
return - V_64 ;
V_60 = F_18 ( V_58 , V_65 , 0 ) ;
V_2 -> V_6 = F_19 ( & V_58 -> V_62 , V_60 ) ;
if ( F_20 ( V_2 -> V_6 ) )
return F_21 ( V_2 -> V_6 ) ;
F_22 ( V_2 -> V_10 . V_66 , L_1 , sizeof( V_2 -> V_10 . V_66 ) ) ;
V_2 -> V_67 = F_23 ( & V_58 -> V_62 , L_2 ) ;
if ( F_20 ( V_2 -> V_67 ) )
return F_21 ( V_2 -> V_67 ) ;
F_24 ( V_2 -> V_67 ) ;
V_2 -> V_10 . V_11 = F_25 ( 100 ) ;
V_2 -> V_10 . V_68 = 5 ;
V_2 -> V_10 . V_62 . V_69 = & V_58 -> V_62 ;
V_2 -> V_10 . V_70 = & V_71 ;
V_2 -> V_10 . V_72 = V_73 ;
V_2 -> V_10 . V_62 . V_74 = V_58 -> V_62 . V_74 ;
F_26 ( & V_2 -> V_9 ) ;
F_27 ( V_58 , V_2 ) ;
F_28 ( & V_2 -> V_10 , V_2 ) ;
F_8 ( & V_2 -> V_10 ) ;
V_61 = F_29 ( V_58 , 0 ) ;
V_49 = F_30 ( & V_58 -> V_62 , V_61 , F_13 , 0 ,
L_3 , V_2 ) ;
if ( V_49 )
goto V_75;
V_49 = F_31 ( & V_2 -> V_10 ) ;
if ( V_49 )
goto V_75;
F_32 ( & V_58 -> V_62 , L_4 , V_2 -> V_10 . V_76 , V_61 ) ;
return 0 ;
V_75:
F_33 ( V_2 -> V_67 ) ;
return V_49 ;
}
static int F_34 ( struct V_57 * V_62 )
{
struct V_1 * V_2 = F_35 ( V_62 ) ;
F_36 ( & V_2 -> V_10 ) ;
F_33 ( V_2 -> V_67 ) ;
return 0 ;
}
