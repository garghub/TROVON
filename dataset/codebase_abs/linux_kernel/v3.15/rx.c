static T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
if ( V_2 -> V_4 & V_5 )
return ( V_3 & V_6 ) >>
V_7 ;
return ( V_3 & V_8 ) >> V_9 ;
}
static T_1 F_2 ( struct V_1 * V_2 , T_1 V_10 )
{
if ( V_2 -> V_4 & V_5 )
return F_3 ( V_10 , V_11 ) ;
return V_10 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 ,
T_2 V_16 )
{
memset ( V_15 , 0 , sizeof( struct V_14 ) ) ;
if ( ( V_13 -> V_17 & V_18 ) == V_19 )
V_15 -> V_20 = V_21 ;
else
V_15 -> V_20 = V_22 ;
V_15 -> V_23 = F_5 ( V_2 , V_13 -> V_24 , V_15 -> V_20 ) ;
if ( V_13 -> V_24 <= V_2 -> V_25 )
V_15 -> V_26 |= V_27 ;
V_15 -> signal = V_13 -> V_28 ;
V_2 -> V_29 = V_13 -> V_28 - ( V_13 -> V_30 >> 1 ) ;
V_15 -> V_31 = F_6 ( V_13 -> V_32 ,
V_15 -> V_20 ) ;
if ( V_13 -> V_17 & V_33 ) {
T_2 V_34 = V_13 -> V_15 & V_35 ;
V_15 -> V_26 |= V_36 | V_37 |
V_38 ;
if ( F_7 ( V_34 & V_39 ) ) {
V_15 -> V_26 |= V_40 ;
F_8 ( L_1 ,
V_34 ) ;
}
}
if ( V_16 )
F_9 ( V_2 , ( V_41 ) V_13 -> V_32 ,
V_15 -> V_20 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_2 * V_42 , T_1 V_43 ,
enum V_44 V_45 , T_2 * V_46 )
{
struct V_12 * V_13 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
T_2 * V_51 ;
T_2 V_16 = 0 ;
T_2 V_52 = 0 ;
T_2 V_53 = 0 , V_54 = 0 ;
V_41 V_55 ;
T_1 V_56 ;
if ( F_7 ( V_2 -> V_57 ) )
return - V_58 ;
V_56 = F_11 ( V_2 , V_42 , V_43 ) ;
if ( ! V_56 ) {
F_12 ( L_2 ,
V_43 ) ;
return - V_58 ;
}
if ( V_45 == V_59 )
V_53 = V_60 ;
else if ( V_45 == V_61 )
V_54 = V_60 ;
V_13 = (struct V_12 * ) V_42 ;
if ( V_13 -> V_62 == V_63 ) {
T_3 V_64 = V_43 - sizeof( * V_13 ) ;
F_13 ( V_2 , V_42 + sizeof( * V_13 ) , V_64 ) ;
F_14 ( & V_2 -> V_65 ) ;
return 0 ;
}
if ( V_13 -> V_15 & V_66 ) {
V_50 = ( void * ) ( V_42 + sizeof( * V_13 ) + V_54 ) ;
F_8 ( L_3 ,
V_13 -> V_15 & V_35 ,
V_56 ) ;
F_15 ( ( V_67 | V_68 ) , L_4 , V_42 + sizeof( * V_13 ) ,
F_16 ( V_56 ,
F_17 ( V_50 -> V_69 ) ) ) ;
return - V_58 ;
}
V_48 = F_18 ( V_56 + V_53 , V_70 ) ;
if ( ! V_48 ) {
F_12 ( L_5 ) ;
return - V_71 ;
}
F_19 ( V_48 , V_53 ) ;
V_51 = F_20 ( V_48 , V_56 ) ;
memcpy ( V_51 , V_42 + sizeof( * V_13 ) , V_56 ) ;
if ( V_45 == V_61 )
F_21 ( V_48 , V_60 ) ;
* V_46 = V_13 -> V_46 ;
V_50 = (struct V_49 * ) V_48 -> V_42 ;
if ( F_22 ( V_50 -> V_69 ) )
V_16 = 1 ;
if ( F_23 ( V_50 -> V_69 ) )
V_52 = 1 ;
F_4 ( V_2 , V_13 , F_24 ( V_48 ) , V_16 ) ;
F_25 ( V_2 , V_13 , V_48 ) ;
V_55 = ( F_26 ( V_50 -> V_72 ) & V_73 ) >> 4 ;
F_27 ( V_67 , L_6 , V_48 ,
V_48 -> V_64 - V_13 -> V_74 ,
V_16 ? L_7 : L_8 ,
V_55 , * V_46 ) ;
F_28 ( & V_2 -> V_75 , V_48 ) ;
F_29 ( V_2 -> V_76 , & V_2 -> V_77 ) ;
return V_52 ;
}
int F_30 ( struct V_1 * V_2 , struct V_78 * V_15 )
{
unsigned long V_79 [ F_31 ( V_80 ) ] = { 0 } ;
T_1 V_81 ;
T_1 V_82 = V_15 -> V_82 % V_2 -> V_83 ;
T_1 V_84 = V_2 -> V_85 % V_2 -> V_83 ;
T_1 V_85 ;
T_1 V_10 , V_86 ;
T_1 V_87 , V_88 ;
T_2 V_46 ;
enum V_44 V_45 ;
int V_89 = 0 ;
while ( V_84 != V_82 ) {
V_81 = 0 ;
V_85 = V_84 ;
while ( V_85 != V_82 ) {
V_88 = F_32 ( V_15 -> V_90 [ V_85 ] ) ;
V_10 = F_1 ( V_2 , V_88 ) ;
V_86 = F_2 ( V_2 ,
V_10 ) ;
if ( V_81 + V_86 > V_2 -> V_91 )
break;
V_81 += V_86 ;
V_85 ++ ;
V_85 %= V_2 -> V_83 ;
}
if ( V_81 == 0 ) {
F_8 ( L_9 ) ;
break;
}
V_88 = F_32 ( V_15 -> V_90 [ V_84 ] ) ;
V_89 = F_33 ( V_2 , V_88 , V_81 ) ;
if ( V_89 < 0 )
goto V_92;
V_89 = F_34 ( V_2 , V_93 , V_2 -> V_94 ,
V_81 , true ) ;
if ( V_89 < 0 )
goto V_92;
V_87 = 0 ;
while ( V_87 < V_81 ) {
V_88 = F_32 ( V_15 -> V_90 [ V_84 ] ) ;
V_10 = F_1 ( V_2 , V_88 ) ;
V_45 = F_35 ( V_2 , V_88 ) ;
if ( F_10 ( V_2 ,
V_2 -> V_94 + V_87 ,
V_10 , V_45 ,
& V_46 ) == 1 ) {
if ( V_46 < V_2 -> V_95 )
F_36 ( V_46 , V_79 ) ;
else
F_37 ( 1 ,
L_10 ,
V_46 ) ;
}
V_2 -> V_85 ++ ;
V_84 ++ ;
V_84 %= V_2 -> V_83 ;
V_87 += F_2 ( V_2 , V_10 ) ;
}
}
if ( V_2 -> V_4 & V_96 ) {
V_89 = F_38 ( V_2 , V_97 ,
V_2 -> V_85 ) ;
if ( V_89 < 0 )
goto V_92;
}
F_39 ( V_2 , V_79 ) ;
V_92:
return V_89 ;
}
int F_40 ( struct V_1 * V_2 ,
int V_98 , bool V_99 ,
struct V_100 * V_101 )
{
int V_89 ;
if ( ! ! F_41 ( V_98 , V_2 -> V_102 ) == V_99 ) {
F_8 ( L_11
L_12 , V_98 ) ;
return 0 ;
}
V_89 = F_42 ( V_2 , V_98 , V_99 , V_101 ) ;
if ( V_89 ) {
F_12 ( L_13 ,
V_99 ? L_14 : L_15 , V_98 , V_89 ) ;
return V_89 ;
}
if ( V_99 )
F_36 ( V_98 , V_2 -> V_102 ) ;
else
F_43 ( V_98 , V_2 -> V_102 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_103 , V_89 = 0 ;
for ( V_103 = 0 ; V_103 < V_104 ; V_103 ++ ) {
if ( ! F_41 ( V_103 , V_2 -> V_102 ) )
continue;
V_89 = F_40 ( V_2 , V_103 , 0 , NULL ) ;
if ( V_89 )
goto V_92;
}
V_92:
return V_89 ;
}
