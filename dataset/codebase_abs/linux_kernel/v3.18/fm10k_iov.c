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
T_3 V_18 , V_19 ;
int V_20 ;
if ( ! F_5 ( V_9 -> V_17 ) )
return 0 ;
F_6 () ;
V_17 = V_9 -> V_17 ;
if ( ! V_17 )
goto V_21;
if ( ! ( F_7 ( V_2 , V_22 ) & V_23 ) )
goto V_24;
do {
V_19 = F_7 ( V_2 , F_8 ( 0 ) ) ;
V_19 <<= 32 ;
V_19 |= F_7 ( V_2 , F_8 ( 1 ) ) ;
V_19 = ( V_19 << 32 ) | ( V_19 >> 32 ) ;
V_19 |= F_7 ( V_2 , F_8 ( 0 ) ) ;
V_20 = V_17 -> V_25 ;
for ( V_19 <<= 64 - V_20 ; V_19 && V_20 -- ; V_19 += V_19 ) {
struct V_6 * V_7 = & V_17 -> V_7 [ V_20 ] ;
if ( V_19 >= 0 )
continue;
V_2 -> V_26 . V_27 . V_28 ( V_2 , V_7 ) ;
V_7 -> V_5 . V_27 . V_29 ( V_2 , & V_7 -> V_5 ) ;
}
} while ( V_20 != V_17 -> V_25 );
V_24:
V_18 = F_7 ( V_2 , F_9 ( 1 ) ) ;
V_18 <<= 32 ;
V_18 |= F_7 ( V_2 , F_9 ( 0 ) ) ;
V_20 = V_17 -> V_30 ? : V_17 -> V_25 ;
for ( V_18 <<= 64 - V_20 ; V_20 -- ; V_18 += V_18 ) {
struct V_4 * V_5 = & V_17 -> V_7 [ V_20 ] . V_5 ;
if ( V_18 >= 0 )
continue;
if ( ! V_2 -> V_5 . V_27 . V_31 ( & V_2 -> V_5 , V_32 ) )
break;
V_5 -> V_27 . V_33 ( V_2 , V_5 ) ;
}
if ( V_20 >= 0 ) {
V_17 -> V_30 = V_20 + 1 ;
} else if ( V_17 -> V_30 ) {
V_17 -> V_30 = 0 ;
goto V_24;
}
V_21:
F_10 () ;
return 0 ;
}
T_1 F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_9 -> V_2 ;
struct V_16 * V_17 ;
int V_20 ;
if ( ! F_5 ( V_9 -> V_17 ) )
return 0 ;
F_6 () ;
V_17 = V_9 -> V_17 ;
if ( ! V_17 )
goto V_21;
F_12 ( V_9 ) ;
V_24:
for ( V_20 = V_17 -> V_30 ? : V_17 -> V_25 ; V_20 -- ; ) {
struct V_6 * V_7 = & V_17 -> V_7 [ V_20 ] ;
struct V_4 * V_5 = & V_7 -> V_5 ;
T_4 V_34 = V_7 -> V_34 ;
if ( V_7 -> V_35 && ! F_13 ( V_2 , V_34 ) )
V_2 -> V_26 . V_27 . V_36 ( V_2 , V_7 ) ;
if ( ! V_5 -> V_37 ) {
V_2 -> V_26 . V_27 . V_28 ( V_2 , V_7 ) ;
V_5 -> V_27 . V_29 ( V_2 , V_5 ) ;
}
if ( V_5 -> V_27 . V_38 ( V_5 ) && ! V_5 -> V_27 . V_39 ( V_5 ) )
continue;
if ( ! V_2 -> V_5 . V_27 . V_31 ( & V_2 -> V_5 , V_32 ) )
break;
V_5 -> V_27 . V_33 ( V_2 , V_5 ) ;
}
if ( V_20 >= 0 ) {
V_17 -> V_30 = V_20 + 1 ;
} else if ( V_17 -> V_30 ) {
V_17 -> V_30 = 0 ;
goto V_24;
}
F_14 ( V_9 ) ;
V_21:
F_10 () ;
return 0 ;
}
void F_15 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = F_16 ( V_12 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_25 , V_20 ;
V_25 = V_17 ? V_17 -> V_25 : 0 ;
F_17 ( V_2 , F_18 ( V_40 ) ,
V_41 ) ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
struct V_6 * V_7 = & V_17 -> V_7 [ V_20 ] ;
V_2 -> V_26 . V_27 . V_28 ( V_2 , V_7 ) ;
V_2 -> V_26 . V_27 . V_36 ( V_2 , V_7 ) ;
}
}
int F_19 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = F_16 ( V_12 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_42 V_43 = { 0 } ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_25 , V_20 ;
V_25 = V_17 ? V_17 -> V_25 : 0 ;
if ( ! V_17 )
return - V_44 ;
V_2 -> V_26 . V_27 . V_45 ( V_2 , V_25 , V_25 ) ;
V_43 . V_34 = V_2 -> V_46 . V_47 & V_41 ;
V_43 . V_48 = V_40 ;
V_43 . V_49 = 1 ;
V_43 . V_50 = F_20 ( F_21 ( V_2 ) - 1 ) ;
V_43 . V_51 = F_22 ( V_2 , 0 ) ;
V_43 . V_52 = F_20 ( V_2 -> V_26 . V_53 - 1 ) ;
V_43 . V_54 = 1 ;
V_2 -> V_46 . V_27 . V_55 ( V_2 , & V_43 ) ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
struct V_6 * V_7 = & V_17 -> V_7 [ V_20 ] ;
if ( V_20 == ( ( ~ V_2 -> V_46 . V_47 ) >> V_56 ) )
break;
V_2 -> V_26 . V_27 . V_57 ( V_2 , V_7 , V_20 ,
V_58 ) ;
V_7 -> V_59 = V_2 -> V_46 . V_60 ;
V_2 -> V_26 . V_27 . V_61 ( V_2 , V_7 ) ;
V_7 -> V_5 . V_27 . V_29 ( V_2 , & V_7 -> V_5 ) ;
}
return 0 ;
}
T_1 F_23 ( struct V_8 * V_9 , T_4 V_34 , T_4 V_62 )
{
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
struct V_6 * V_7 ;
T_4 V_15 = ( V_34 - V_2 -> V_46 . V_47 ) & V_41 ;
if ( ! V_17 )
return V_63 ;
if ( V_15 >= V_17 -> V_25 )
return V_63 ;
V_7 = & V_17 -> V_7 [ V_15 ] ;
if ( V_7 -> V_59 != V_62 ) {
V_7 -> V_59 = V_62 ;
V_2 -> V_26 . V_27 . V_61 ( V_2 , V_7 ) ;
}
return 0 ;
}
static void F_24 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = F_16 ( V_12 ) ;
if ( ! V_9 -> V_17 )
return;
F_15 ( V_12 ) ;
F_25 ( V_9 -> V_17 , V_64 ) ;
V_9 -> V_17 = NULL ;
}
static T_1 F_26 ( struct V_11 * V_12 , int V_25 )
{
struct V_8 * V_9 = F_16 ( V_12 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
T_5 V_65 ;
int V_20 , V_66 ;
if ( V_17 )
return - V_67 ;
if ( ! V_2 -> V_26 . V_27 . V_45 )
return - V_68 ;
if ( ! V_25 )
return 0 ;
V_65 = F_27 ( struct V_16 , V_7 [ V_25 ] ) ;
V_17 = F_28 ( V_65 , V_69 ) ;
if ( ! V_17 )
return - V_44 ;
V_17 -> V_25 = V_25 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
struct V_6 * V_7 = & V_17 -> V_7 [ V_20 ] ;
V_7 -> V_70 = V_20 + 1 ;
V_7 -> V_15 = V_20 ;
V_66 = F_29 ( V_2 , & V_7 -> V_5 , V_71 , V_20 ) ;
if ( V_66 ) {
F_2 ( & V_12 -> V_13 ,
L_2 ) ;
F_30 ( V_17 ) ;
return V_66 ;
}
}
V_9 -> V_17 = V_17 ;
F_19 ( V_12 ) ;
return 0 ;
}
void F_31 ( struct V_11 * V_12 )
{
if ( F_32 ( V_12 ) && F_33 ( V_12 ) )
F_2 ( & V_12 -> V_13 ,
L_3 ) ;
else
F_34 ( V_12 ) ;
F_24 ( V_12 ) ;
}
static void F_35 ( struct V_11 * V_12 )
{
T_2 V_72 ;
int V_73 ;
V_73 = F_36 ( V_12 , V_74 ) ;
if ( ! V_73 )
return;
F_37 ( V_12 , V_73 + V_75 , & V_72 ) ;
V_72 &= ~ V_76 ;
F_38 ( V_12 , V_73 + V_75 , V_72 ) ;
}
int F_39 ( struct V_11 * V_12 , int V_25 )
{
int V_77 = F_32 ( V_12 ) ;
int V_66 = 0 ;
if ( V_77 && F_33 ( V_12 ) ) {
F_2 ( & V_12 -> V_13 ,
L_4 ) ;
V_25 = V_77 ;
} else {
F_34 ( V_12 ) ;
F_24 ( V_12 ) ;
}
V_66 = F_26 ( V_12 , V_25 ) ;
if ( V_66 )
return V_66 ;
if ( V_25 && ( V_25 != V_77 ) ) {
F_35 ( V_12 ) ;
V_66 = F_40 ( V_12 , V_25 ) ;
if ( V_66 ) {
F_2 ( & V_12 -> V_13 ,
L_5 , V_66 ) ;
return V_66 ;
}
}
return V_25 ;
}
int F_41 ( struct V_78 * V_79 , int V_15 , T_6 * V_46 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
struct V_6 * V_7 ;
if ( ! V_17 || V_15 >= V_17 -> V_25 )
return - V_80 ;
if ( ! F_43 ( V_46 ) && ! F_44 ( V_46 ) )
return - V_80 ;
V_7 = & V_17 -> V_7 [ V_15 ] ;
F_45 ( V_7 -> V_46 , V_46 ) ;
F_12 ( V_9 ) ;
V_2 -> V_26 . V_27 . V_61 ( V_2 , V_7 ) ;
F_14 ( V_9 ) ;
return 0 ;
}
int F_46 ( struct V_78 * V_79 , int V_15 , T_4 V_81 ,
T_6 V_82 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
struct V_6 * V_7 ;
if ( ! V_17 || V_15 >= V_17 -> V_25 )
return - V_80 ;
if ( V_82 || ( V_81 > ( V_83 - 1 ) ) )
return - V_80 ;
V_7 = & V_17 -> V_7 [ V_15 ] ;
if ( V_7 -> V_84 == V_81 )
return 0 ;
V_7 -> V_84 = V_81 ;
F_12 ( V_9 ) ;
V_2 -> V_46 . V_27 . V_85 ( V_2 , V_86 , V_7 -> V_70 , false ) ;
V_2 -> V_26 . V_27 . V_61 ( V_2 , V_7 ) ;
F_14 ( V_9 ) ;
return 0 ;
}
int F_47 ( struct V_78 * V_79 , int V_15 , int V_87 ,
int V_88 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
if ( ! V_17 || V_15 >= V_17 -> V_25 )
return - V_80 ;
if ( V_88 && ( ( V_88 < V_89 ) || V_88 > V_90 ) )
return - V_80 ;
V_17 -> V_7 [ V_15 ] . V_88 = V_88 ;
V_2 -> V_26 . V_27 . V_91 ( V_2 , V_15 , V_88 ) ;
return 0 ;
}
int F_48 ( struct V_78 * V_79 ,
int V_15 , struct V_92 * V_93 )
{
struct V_8 * V_9 = F_42 ( V_79 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_6 * V_7 ;
if ( ! V_17 || V_15 >= V_17 -> V_25 )
return - V_80 ;
V_7 = & V_17 -> V_7 [ V_15 ] ;
V_93 -> V_94 = V_15 ;
V_93 -> V_95 = V_7 -> V_88 ;
V_93 -> V_96 = 0 ;
F_45 ( V_93 -> V_46 , V_7 -> V_46 ) ;
V_93 -> V_97 = V_7 -> V_84 ;
V_93 -> V_82 = 0 ;
return 0 ;
}
