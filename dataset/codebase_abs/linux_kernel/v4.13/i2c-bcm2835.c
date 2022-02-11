static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_6 ( F_7 ( V_2 -> V_7 ) ,
V_2 -> V_8 ) ;
if ( V_6 & 1 )
V_6 ++ ;
if ( ( V_6 < V_9 ) ||
( V_6 > V_10 ) ) {
F_8 ( V_2 -> V_11 , L_1 ) ;
return - V_12 ;
}
F_1 ( V_2 , V_13 , V_6 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_4 ;
while ( V_2 -> V_14 ) {
V_4 = F_3 ( V_2 , V_15 ) ;
if ( ! ( V_4 & V_16 ) )
break;
F_1 ( V_2 , V_17 ,
* V_2 -> V_18 ) ;
V_2 -> V_18 ++ ;
V_2 -> V_14 -- ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_4 ;
while ( V_2 -> V_14 ) {
V_4 = F_3 ( V_2 , V_15 ) ;
if ( ! ( V_4 & V_19 ) )
break;
* V_2 -> V_18 = F_3 ( V_2 ,
V_17 ) ;
V_2 -> V_18 ++ ;
V_2 -> V_14 -- ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_20 = V_21 | V_22 ;
struct V_23 * V_24 = V_2 -> V_25 ;
bool V_26 = ( V_2 -> V_27 == 1 ) ;
if ( ! V_2 -> V_27 )
return;
V_2 -> V_27 -- ;
V_2 -> V_18 = V_24 -> V_28 ;
V_2 -> V_14 = V_24 -> V_29 ;
if ( V_24 -> V_30 & V_31 )
V_20 |= V_32 | V_33 ;
else
V_20 |= V_34 ;
if ( V_26 )
V_20 |= V_35 ;
F_1 ( V_2 , V_36 , V_24 -> V_37 ) ;
F_1 ( V_2 , V_38 , V_24 -> V_29 ) ;
F_1 ( V_2 , V_39 , V_20 ) ;
}
static T_2 F_12 ( int V_40 , void * V_41 )
{
struct V_1 * V_2 = V_41 ;
T_1 V_4 , V_42 ;
V_4 = F_3 ( V_2 , V_15 ) ;
V_42 = V_4 & ( V_43 | V_44 ) ;
if ( V_42 ) {
V_2 -> V_45 = V_42 ;
goto V_46;
}
if ( V_4 & V_47 ) {
if ( ! V_2 -> V_25 ) {
F_13 ( V_2 -> V_11 , L_2 ) ;
} else if ( V_2 -> V_25 -> V_30 & V_31 ) {
F_10 ( V_2 ) ;
V_4 = F_3 ( V_2 , V_15 ) ;
}
if ( ( V_4 & V_19 ) || V_2 -> V_14 )
V_2 -> V_45 = V_48 ;
else
V_2 -> V_45 = 0 ;
goto V_46;
}
if ( V_4 & V_49 ) {
if ( ! V_2 -> V_14 ) {
V_2 -> V_45 = V_4 | V_48 ;
goto V_46;
}
F_9 ( V_2 ) ;
if ( V_2 -> V_27 && ! V_2 -> V_14 ) {
V_2 -> V_25 ++ ;
F_11 ( V_2 ) ;
}
return V_50 ;
}
if ( V_4 & V_51 ) {
if ( ! V_2 -> V_14 ) {
V_2 -> V_45 = V_4 | V_48 ;
goto V_46;
}
F_10 ( V_2 ) ;
return V_50 ;
}
return V_52 ;
V_46:
F_1 ( V_2 , V_39 , V_53 ) ;
F_1 ( V_2 , V_15 , V_43 |
V_44 | V_47 ) ;
V_46 ( & V_2 -> V_54 ) ;
return V_50 ;
}
static int F_14 ( struct V_55 * V_56 , struct V_23 V_57 [] ,
int V_58 )
{
struct V_1 * V_2 = F_15 ( V_56 ) ;
unsigned long V_59 ;
int V_60 , V_61 ;
for ( V_60 = 0 ; V_60 < ( V_58 - 1 ) ; V_60 ++ )
if ( V_57 [ V_60 ] . V_30 & V_31 ) {
F_16 ( V_2 -> V_11 ,
L_3 ) ;
return - V_62 ;
}
V_61 = F_5 ( V_2 ) ;
if ( V_61 )
return V_61 ;
V_2 -> V_25 = V_57 ;
V_2 -> V_27 = V_58 ;
F_17 ( & V_2 -> V_54 ) ;
F_11 ( V_2 ) ;
V_59 = F_18 ( & V_2 -> V_54 ,
V_56 -> V_63 ) ;
if ( ! V_59 ) {
F_1 ( V_2 , V_39 ,
V_53 ) ;
F_13 ( V_2 -> V_11 , L_4 ) ;
return - V_64 ;
}
if ( ! V_2 -> V_45 )
return V_58 ;
F_19 ( V_2 -> V_11 , L_5 , V_2 -> V_45 ) ;
if ( V_2 -> V_45 & V_44 )
return - V_65 ;
return - V_66 ;
}
static T_1 F_20 ( struct V_55 * V_56 )
{
return V_67 | V_68 ;
}
static int F_21 ( struct V_69 * V_70 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 , * V_73 ;
int V_61 ;
struct V_55 * V_56 ;
V_2 = F_22 ( & V_70 -> V_11 , sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
F_23 ( V_70 , V_2 ) ;
V_2 -> V_11 = & V_70 -> V_11 ;
F_24 ( & V_2 -> V_54 ) ;
V_72 = F_25 ( V_70 , V_76 , 0 ) ;
V_2 -> V_5 = F_26 ( & V_70 -> V_11 , V_72 ) ;
if ( F_27 ( V_2 -> V_5 ) )
return F_28 ( V_2 -> V_5 ) ;
V_2 -> V_7 = F_29 ( & V_70 -> V_11 , NULL ) ;
if ( F_27 ( V_2 -> V_7 ) ) {
if ( F_28 ( V_2 -> V_7 ) != - V_77 )
F_13 ( & V_70 -> V_11 , L_6 ) ;
return F_28 ( V_2 -> V_7 ) ;
}
V_61 = F_30 ( V_70 -> V_11 . V_78 , L_7 ,
& V_2 -> V_8 ) ;
if ( V_61 < 0 ) {
F_31 ( & V_70 -> V_11 ,
L_8 ) ;
V_2 -> V_8 = 100000 ;
}
V_73 = F_25 ( V_70 , V_79 , 0 ) ;
if ( ! V_73 ) {
F_13 ( & V_70 -> V_11 , L_9 ) ;
return - V_80 ;
}
V_2 -> V_73 = V_73 -> V_81 ;
V_61 = F_32 ( V_2 -> V_73 , F_12 , V_82 ,
F_33 ( & V_70 -> V_11 ) , V_2 ) ;
if ( V_61 ) {
F_13 ( & V_70 -> V_11 , L_10 ) ;
return - V_80 ;
}
V_56 = & V_2 -> V_83 ;
F_34 ( V_56 , V_2 ) ;
V_56 -> V_84 = V_85 ;
V_56 -> V_86 = V_87 ;
F_35 ( V_56 -> V_88 , L_11 , sizeof( V_56 -> V_88 ) ) ;
V_56 -> V_89 = & V_90 ;
V_56 -> V_11 . V_91 = & V_70 -> V_11 ;
V_56 -> V_11 . V_78 = V_70 -> V_11 . V_78 ;
V_56 -> V_92 = & V_93 ;
F_1 ( V_2 , V_39 , 0 ) ;
V_61 = F_36 ( V_56 ) ;
if ( V_61 )
F_37 ( V_2 -> V_73 , V_2 ) ;
return V_61 ;
}
static int F_38 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_39 ( V_70 ) ;
F_37 ( V_2 -> V_73 , V_2 ) ;
F_40 ( & V_2 -> V_83 ) ;
return 0 ;
}
