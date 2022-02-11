static T_1 F_1 ( struct V_1 * V_2 , T_2 * * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_5 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_2 ( & V_12 -> V_13 , L_1 ,
* * V_3 & V_14 , V_7 -> V_15 ) ;
return F_3 ( V_2 , V_3 , V_5 ) ;
}
T_1 F_4 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_9 -> V_2 ;
struct V_16 * V_17 ;
T_3 V_18 ;
int V_19 ;
if ( ! F_5 ( V_9 -> V_17 ) )
return 0 ;
F_6 () ;
V_17 = V_9 -> V_17 ;
if ( ! V_17 )
goto V_20;
if ( ! ( F_7 ( V_2 , V_21 ) & V_22 ) )
goto V_20;
do {
V_18 = F_7 ( V_2 , F_8 ( 0 ) ) ;
V_18 <<= 32 ;
V_18 |= F_7 ( V_2 , F_8 ( 1 ) ) ;
V_18 = ( V_18 << 32 ) | ( V_18 >> 32 ) ;
V_18 |= F_7 ( V_2 , F_8 ( 0 ) ) ;
V_19 = V_17 -> V_23 ;
for ( V_18 <<= 64 - V_19 ; V_18 && V_19 -- ; V_18 += V_18 ) {
struct V_6 * V_7 = & V_17 -> V_7 [ V_19 ] ;
if ( V_18 >= 0 )
continue;
V_2 -> V_24 . V_25 . V_26 ( V_2 , V_7 ) ;
V_7 -> V_5 . V_25 . V_27 ( V_2 , & V_7 -> V_5 ) ;
}
} while ( V_19 != V_17 -> V_23 );
V_20:
F_9 () ;
return 0 ;
}
T_1 F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_9 -> V_2 ;
struct V_16 * V_17 ;
int V_19 ;
if ( ! F_5 ( V_9 -> V_17 ) )
return 0 ;
F_6 () ;
V_17 = V_9 -> V_17 ;
if ( ! V_17 )
goto V_20;
F_11 ( V_9 ) ;
V_28:
for ( V_19 = V_17 -> V_29 ? : V_17 -> V_23 ; V_19 -- ; ) {
struct V_6 * V_7 = & V_17 -> V_7 [ V_19 ] ;
struct V_4 * V_5 = & V_7 -> V_5 ;
T_4 V_30 = V_7 -> V_30 ;
if ( V_7 -> V_31 && ! F_12 ( V_2 , V_30 ) )
V_2 -> V_24 . V_25 . V_32 ( V_2 , V_7 ) ;
if ( ! V_5 -> V_33 ) {
V_2 -> V_24 . V_25 . V_26 ( V_2 , V_7 ) ;
V_5 -> V_25 . V_27 ( V_2 , V_5 ) ;
}
if ( ! V_2 -> V_5 . V_25 . V_34 ( & V_2 -> V_5 , V_35 ) ) {
V_9 -> V_36 ++ ;
break;
}
V_5 -> V_25 . V_37 ( V_2 , V_5 ) ;
}
if ( V_19 >= 0 ) {
V_17 -> V_29 = V_19 + 1 ;
} else if ( V_17 -> V_29 ) {
V_17 -> V_29 = 0 ;
goto V_28;
}
F_13 ( V_9 ) ;
V_20:
F_9 () ;
return 0 ;
}
void F_14 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = F_15 ( V_12 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_23 , V_19 ;
V_23 = V_17 ? V_17 -> V_23 : 0 ;
F_16 ( V_2 , F_17 ( V_38 ) ,
V_39 ) ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
struct V_6 * V_7 = & V_17 -> V_7 [ V_19 ] ;
V_2 -> V_24 . V_25 . V_26 ( V_2 , V_7 ) ;
V_2 -> V_24 . V_25 . V_32 ( V_2 , V_7 ) ;
}
}
int F_18 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = F_15 ( V_12 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_40 V_41 = { 0 } ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_23 , V_19 ;
V_23 = V_17 ? V_17 -> V_23 : 0 ;
if ( ! V_17 )
return - V_42 ;
V_2 -> V_24 . V_25 . V_43 ( V_2 , V_23 , V_23 ) ;
V_41 . V_30 = V_2 -> V_44 . V_45 & V_39 ;
V_41 . V_46 = V_38 ;
V_41 . V_47 = 1 ;
V_41 . V_48 = F_19 ( F_20 ( V_2 ) - 1 ) ;
V_41 . V_49 = F_21 ( V_2 , 0 ) ;
V_41 . V_50 = F_19 ( V_2 -> V_24 . V_51 - 1 ) ;
V_41 . V_52 = 1 ;
V_2 -> V_44 . V_25 . V_53 ( V_2 , & V_41 ) ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
struct V_6 * V_7 = & V_17 -> V_7 [ V_19 ] ;
if ( V_19 == ( ( ~ V_2 -> V_44 . V_45 ) >> V_54 ) )
break;
V_2 -> V_24 . V_25 . V_55 ( V_2 , V_7 , V_19 ,
V_56 ) ;
V_2 -> V_24 . V_25 . V_57 ( V_2 , V_7 ) ;
V_7 -> V_5 . V_25 . V_27 ( V_2 , & V_7 -> V_5 ) ;
}
return 0 ;
}
T_1 F_22 ( struct V_8 * V_9 , T_4 V_30 , T_4 V_58 )
{
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
struct V_6 * V_7 ;
T_4 V_15 = ( V_30 - V_2 -> V_44 . V_45 ) & V_39 ;
if ( ! V_17 )
return V_59 ;
if ( V_15 >= V_17 -> V_23 )
return V_59 ;
V_7 = & V_17 -> V_7 [ V_15 ] ;
if ( V_7 -> V_60 != V_58 ) {
V_7 -> V_60 = V_58 ;
V_2 -> V_24 . V_25 . V_57 ( V_2 , V_7 ) ;
}
return 0 ;
}
static void F_23 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = F_15 ( V_12 ) ;
if ( ! V_9 -> V_17 )
return;
F_14 ( V_12 ) ;
F_24 ( V_9 -> V_17 , V_61 ) ;
V_9 -> V_17 = NULL ;
}
static T_1 F_25 ( struct V_11 * V_12 , int V_23 )
{
struct V_8 * V_9 = F_15 ( V_12 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
T_5 V_62 ;
int V_19 , V_63 ;
if ( V_17 )
return - V_64 ;
if ( ! V_2 -> V_24 . V_25 . V_43 )
return - V_65 ;
if ( ! V_23 )
return 0 ;
V_62 = F_26 ( struct V_16 , V_7 [ V_23 ] ) ;
V_17 = F_27 ( V_62 , V_66 ) ;
if ( ! V_17 )
return - V_42 ;
V_17 -> V_23 = V_23 ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
struct V_6 * V_7 = & V_17 -> V_7 [ V_19 ] ;
V_7 -> V_67 = V_19 + 1 ;
V_7 -> V_15 = V_19 ;
V_63 = F_28 ( V_2 , & V_7 -> V_5 , V_68 , V_19 ) ;
if ( V_63 ) {
F_2 ( & V_12 -> V_13 ,
L_2 ) ;
F_29 ( V_17 ) ;
return V_63 ;
}
}
V_9 -> V_17 = V_17 ;
F_18 ( V_12 ) ;
return 0 ;
}
void F_30 ( struct V_11 * V_12 )
{
if ( F_31 ( V_12 ) && F_32 ( V_12 ) )
F_2 ( & V_12 -> V_13 ,
L_3 ) ;
else
F_33 ( V_12 ) ;
F_23 ( V_12 ) ;
}
static void F_34 ( struct V_11 * V_12 )
{
T_2 V_69 ;
int V_70 ;
V_70 = F_35 ( V_12 , V_71 ) ;
if ( ! V_70 )
return;
F_36 ( V_12 , V_70 + V_72 , & V_69 ) ;
V_69 &= ~ V_73 ;
F_37 ( V_12 , V_70 + V_72 , V_69 ) ;
}
int F_38 ( struct V_11 * V_12 , int V_23 )
{
int V_74 = F_31 ( V_12 ) ;
int V_63 = 0 ;
if ( V_74 && F_32 ( V_12 ) ) {
F_2 ( & V_12 -> V_13 ,
L_4 ) ;
V_23 = V_74 ;
} else {
F_33 ( V_12 ) ;
F_23 ( V_12 ) ;
}
V_63 = F_25 ( V_12 , V_23 ) ;
if ( V_63 )
return V_63 ;
if ( V_23 && ( V_23 != V_74 ) ) {
F_34 ( V_12 ) ;
V_63 = F_39 ( V_12 , V_23 ) ;
if ( V_63 ) {
F_2 ( & V_12 -> V_13 ,
L_5 , V_63 ) ;
return V_63 ;
}
}
return V_23 ;
}
static inline void F_40 ( struct V_8 * V_9 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_9 -> V_2 ;
F_11 ( V_9 ) ;
V_2 -> V_24 . V_25 . V_32 ( V_2 , V_7 ) ;
V_2 -> V_24 . V_25 . V_57 ( V_2 , V_7 ) ;
V_2 -> V_24 . V_25 . V_55 ( V_2 , V_7 , V_7 -> V_15 ,
V_56 ) ;
F_13 ( V_9 ) ;
}
int F_41 ( struct V_75 * V_76 , int V_15 , T_6 * V_44 )
{
struct V_8 * V_9 = F_42 ( V_76 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_6 * V_7 ;
if ( ! V_17 || V_15 >= V_17 -> V_23 )
return - V_77 ;
if ( ! F_43 ( V_44 ) && ! F_44 ( V_44 ) )
return - V_77 ;
V_7 = & V_17 -> V_7 [ V_15 ] ;
F_45 ( V_7 -> V_44 , V_44 ) ;
F_40 ( V_9 , V_7 ) ;
return 0 ;
}
int F_46 ( struct V_75 * V_76 , int V_15 , T_4 V_78 ,
T_6 V_79 , T_7 V_80 )
{
struct V_8 * V_9 = F_42 ( V_76 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
struct V_6 * V_7 ;
if ( ! V_17 || V_15 >= V_17 -> V_23 )
return - V_77 ;
if ( V_79 || ( V_78 > ( V_81 - 1 ) ) )
return - V_77 ;
if ( V_80 != F_47 ( V_82 ) )
return - V_83 ;
V_7 = & V_17 -> V_7 [ V_15 ] ;
if ( V_7 -> V_84 == V_78 )
return 0 ;
V_7 -> V_84 = V_78 ;
V_2 -> V_44 . V_25 . V_85 ( V_2 , V_86 , V_7 -> V_67 , false ) ;
F_40 ( V_9 , V_7 ) ;
return 0 ;
}
int F_48 ( struct V_75 * V_76 , int V_15 ,
int T_8 V_87 , int V_88 )
{
struct V_8 * V_9 = F_42 ( V_76 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
if ( ! V_17 || V_15 >= V_17 -> V_23 )
return - V_77 ;
if ( V_88 && ( ( V_88 < V_89 ) || V_88 > V_90 ) )
return - V_77 ;
V_17 -> V_7 [ V_15 ] . V_88 = V_88 ;
V_2 -> V_24 . V_25 . V_91 ( V_2 , V_15 , V_88 ) ;
return 0 ;
}
int F_49 ( struct V_75 * V_76 ,
int V_15 , struct V_92 * V_93 )
{
struct V_8 * V_9 = F_42 ( V_76 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_6 * V_7 ;
if ( ! V_17 || V_15 >= V_17 -> V_23 )
return - V_77 ;
V_7 = & V_17 -> V_7 [ V_15 ] ;
V_93 -> V_94 = V_15 ;
V_93 -> V_95 = V_7 -> V_88 ;
V_93 -> V_96 = 0 ;
F_45 ( V_93 -> V_44 , V_7 -> V_44 ) ;
V_93 -> V_97 = V_7 -> V_84 ;
V_93 -> V_79 = 0 ;
return 0 ;
}
