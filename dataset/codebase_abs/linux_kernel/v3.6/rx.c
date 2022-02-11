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
if ( F_7 ( V_34 == V_39 ) ) {
V_15 -> V_26 |= V_40 ;
F_8 ( L_1 ) ;
}
}
}
static int F_9 ( struct V_1 * V_2 , T_2 * V_41 , T_1 V_42 ,
enum V_43 V_44 , T_2 * V_45 )
{
struct V_12 * V_13 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
T_2 * V_50 ;
T_2 V_16 = 0 ;
T_2 V_51 = 0 ;
T_2 V_52 = 0 ;
T_3 V_53 ;
T_1 V_54 ;
if ( F_7 ( V_2 -> V_55 ) )
return - V_56 ;
V_54 = F_10 ( V_2 , V_41 , V_42 ) ;
if ( ! V_54 ) {
F_11 ( L_2 ,
V_42 ) ;
return - V_56 ;
}
if ( V_44 == V_57 )
V_52 = V_58 ;
V_13 = (struct V_12 * ) V_41 ;
if ( V_13 -> V_59 == V_60 ) {
T_4 V_61 = V_42 - sizeof( * V_13 ) ;
F_12 ( V_2 , V_41 + sizeof( * V_13 ) , V_61 ) ;
F_13 ( & V_2 -> V_62 ) ;
return 0 ;
}
switch ( V_13 -> V_15 & V_35 ) {
case V_63 :
case V_64 :
F_8 ( L_3 ,
V_13 -> V_15 & V_35 ) ;
return - V_56 ;
case V_65 :
case V_39 :
break;
default:
F_11 ( L_4 ,
V_13 -> V_15 & V_35 ) ;
return - V_56 ;
}
V_47 = F_14 ( V_54 + V_52 , V_66 ) ;
if ( ! V_47 ) {
F_11 ( L_5 ) ;
return - V_67 ;
}
F_15 ( V_47 , V_52 ) ;
V_50 = F_16 ( V_47 , V_54 ) ;
memcpy ( V_50 , V_41 + sizeof( * V_13 ) , V_54 ) ;
if ( V_44 == V_68 )
F_17 ( V_47 , V_58 ) ;
* V_45 = V_13 -> V_45 ;
V_49 = (struct V_48 * ) V_47 -> V_41 ;
if ( F_18 ( V_49 -> V_69 ) )
V_16 = 1 ;
if ( F_19 ( V_49 -> V_69 ) )
V_51 = 1 ;
F_4 ( V_2 , V_13 , F_20 ( V_47 ) , V_16 ) ;
F_21 ( V_2 , V_13 , V_47 ) ;
V_53 = ( F_22 ( V_49 -> V_70 ) & V_71 ) >> 4 ;
F_23 ( V_72 , L_6 , V_47 ,
V_47 -> V_61 - V_13 -> V_73 ,
V_16 ? L_7 : L_8 ,
V_53 , * V_45 ) ;
F_24 ( & V_2 -> V_74 , V_47 ) ;
F_25 ( V_2 -> V_75 , & V_2 -> V_76 ) ;
return V_51 ;
}
int F_26 ( struct V_1 * V_2 , struct V_77 * V_15 )
{
unsigned long V_78 [ F_27 ( V_79 ) ] = { 0 } ;
T_1 V_80 ;
T_1 V_81 = V_15 -> V_81 % V_2 -> V_82 ;
T_1 V_83 = V_2 -> V_84 % V_2 -> V_82 ;
T_1 V_84 ;
T_1 V_10 , V_85 ;
T_1 V_86 , V_87 ;
T_2 V_45 ;
enum V_43 V_44 ;
int V_88 = 0 ;
while ( V_83 != V_81 ) {
V_80 = 0 ;
V_84 = V_83 ;
while ( V_84 != V_81 ) {
V_87 = F_28 ( V_15 -> V_89 [ V_84 ] ) ;
V_10 = F_1 ( V_2 , V_87 ) ;
V_85 = F_2 ( V_2 ,
V_10 ) ;
if ( V_80 + V_85 > V_90 )
break;
V_80 += V_85 ;
V_84 ++ ;
V_84 %= V_2 -> V_82 ;
}
if ( V_80 == 0 ) {
F_8 ( L_9 ) ;
break;
}
V_87 = F_28 ( V_15 -> V_89 [ V_83 ] ) ;
V_88 = F_29 ( V_2 , V_87 , V_80 ) ;
if ( V_88 < 0 )
goto V_91;
V_88 = F_30 ( V_2 , V_92 , V_2 -> V_93 ,
V_80 , true ) ;
if ( V_88 < 0 )
goto V_91;
V_86 = 0 ;
while ( V_86 < V_80 ) {
V_87 = F_28 ( V_15 -> V_89 [ V_83 ] ) ;
V_10 = F_1 ( V_2 , V_87 ) ;
V_44 = F_31 ( V_2 , V_87 ) ;
if ( F_9 ( V_2 ,
V_2 -> V_93 + V_86 ,
V_10 , V_44 ,
& V_45 ) == 1 ) {
if ( V_45 < V_79 )
F_32 ( V_45 , V_78 ) ;
else
F_33 ( 1 ,
L_10
L_11 , V_45 ) ;
}
V_2 -> V_84 ++ ;
V_83 ++ ;
V_83 %= V_2 -> V_82 ;
V_86 += F_2 ( V_2 , V_10 ) ;
}
}
if ( V_2 -> V_4 & V_94 ) {
V_88 = F_34 ( V_2 , V_95 ,
V_2 -> V_84 ) ;
if ( V_88 < 0 )
goto V_91;
}
F_35 ( V_2 , V_78 ) ;
V_91:
return V_88 ;
}
int F_36 ( struct V_1 * V_2 ,
int V_96 , bool V_97 ,
struct V_98 * V_99 )
{
int V_88 ;
if ( V_2 -> V_100 [ V_96 ] == V_97 ) {
F_8 ( L_12
L_13 , V_96 ) ;
return 0 ;
}
V_88 = F_37 ( V_2 , V_96 , V_97 , V_99 ) ;
if ( V_88 ) {
F_11 ( L_14 ,
V_97 ? L_15 : L_16 , V_96 , V_88 ) ;
return V_88 ;
}
V_2 -> V_100 [ V_96 ] = V_97 ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_101 , V_88 = 0 ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ ) {
if ( ! V_2 -> V_100 [ V_101 ] )
continue;
V_88 = F_36 ( V_2 , V_101 , 0 , NULL ) ;
if ( V_88 )
goto V_91;
}
V_91:
return V_88 ;
}
