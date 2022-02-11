static inline int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( F_3 () , 5000 ) ;
while ( F_4 ( V_2 -> V_4 + V_5 ) & V_6 ) {
if ( F_5 ( F_3 () , V_3 ) > 0 )
return - V_7 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned long V_8 , T_2 * V_9 ,
int * V_10 )
{
unsigned long V_11 ;
T_3 V_12 = F_7 ( V_13 , V_8 ) ;
int V_14 = 0 ;
if ( V_10 && * V_10 )
return;
F_8 ( & V_2 -> V_15 , V_11 ) ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 )
goto V_16;
F_9 ( V_12 , V_2 -> V_4 + V_5 ) ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 )
goto V_16;
* V_9 = F_10 ( V_17 ,
F_4 ( V_2 -> V_4 + V_5 ) ) ;
V_16:
F_11 ( & V_2 -> V_15 , V_11 ) ;
if ( V_10 )
* V_10 = V_14 ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned long V_8 , T_2 V_9 ,
int * V_10 )
{
unsigned long V_11 ;
T_3 V_12 = F_7 ( V_13 , V_8 ) |
F_7 ( V_18 , V_9 ) |
V_19 ;
int V_14 = 0 ;
if ( V_10 && * V_10 )
return;
F_8 ( & V_2 -> V_15 , V_11 ) ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 )
goto V_20;
F_9 ( V_12 , V_2 -> V_4 + V_5 ) ;
V_20:
F_11 ( & V_2 -> V_15 , V_11 ) ;
if ( V_10 )
* V_10 = V_14 ;
}
static inline void F_13 ( struct V_1 * V_2 ,
bool V_21 )
{
T_3 V_22 = V_23 | V_24 ;
F_14 ( V_22 , V_21 ? V_22 : 0 ,
V_2 -> V_4 + V_25 ) ;
}
static inline int F_15 ( struct V_1 * V_2 )
{
int V_14 = 0 ;
F_12 ( V_2 , V_26 , V_27 , & V_14 ) ;
F_12 ( V_2 , V_28 , V_29 , & V_14 ) ;
F_12 ( V_2 , V_30 , 1 , & V_14 ) ;
F_12 ( V_2 , V_31 , 1 , & V_14 ) ;
if ( V_14 )
return V_14 ;
F_16 ( 100 ) ;
F_12 ( V_2 , V_30 , 0 , & V_14 ) ;
F_12 ( V_2 , V_31 , 0 , & V_14 ) ;
if ( V_14 )
return V_14 ;
F_16 ( 100 ) ;
F_12 ( V_2 , V_26 , V_32 , & V_14 ) ;
F_12 ( V_2 , V_28 , V_33 , & V_14 ) ;
return V_14 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_34 ,
unsigned int V_35 )
{
int V_14 = 0 ;
switch ( V_34 ) {
case V_36 :
F_12 ( V_2 , V_37 ,
V_35 & 0xff , & V_14 ) ;
F_12 ( V_2 , V_38 ,
( V_35 >> 8 ) & 0x7 , & V_14 ) ;
break;
case V_39 :
F_12 ( V_2 , V_40 ,
V_35 & 0xff , & V_14 ) ;
F_12 ( V_2 , V_41 ,
( V_35 >> 8 ) & 0x7 , & V_14 ) ;
break;
case V_42 :
F_12 ( V_2 , V_43 ,
V_35 & 0xff , & V_14 ) ;
F_12 ( V_2 , V_44 ,
( V_35 >> 8 ) & 0x7 , & V_14 ) ;
break;
}
return V_14 ;
}
static T_4 F_18 ( int V_45 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
T_3 V_46 = F_4 ( V_2 -> V_4 + V_47 ) ;
if ( V_46 )
return V_48 ;
return V_49 ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned long V_50 = 0 ;
T_2 V_46 ;
int V_14 = 0 ;
F_6 ( V_2 , V_51 , & V_46 , & V_14 ) ;
if ( V_14 )
goto V_52;
switch ( V_46 ) {
case V_53 :
V_50 = V_54 ;
break;
case V_55 :
V_50 = V_56 ;
break;
case V_57 :
V_50 = V_58 ;
break;
case V_59 :
default:
V_50 = V_60 ;
break;
}
F_9 ( V_23 , V_2 -> V_4 + V_61 ) ;
F_12 ( V_2 , V_28 , V_33 , & V_14 ) ;
if ( V_14 )
goto V_52;
F_20 ( V_2 -> V_62 , V_50 ) ;
return;
V_52:
F_20 ( V_2 -> V_62 , V_63 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_64 , V_14 = 0 ;
T_2 V_12 ;
F_6 ( V_2 , V_65 , & V_12 , & V_14 ) ;
if ( V_12 != V_66 )
goto V_67;
F_6 ( V_2 , V_68 , & V_12 , & V_14 ) ;
if ( V_12 != 1 )
goto V_67;
F_6 ( V_2 , V_69 , & V_12 , & V_14 ) ;
V_2 -> V_70 . V_71 = V_12 + 1 ;
if ( V_2 -> V_70 . V_71 > V_72 )
V_2 -> V_70 . V_71 = V_72 ;
for ( V_64 = 0 ; V_64 < V_2 -> V_70 . V_71 ; V_64 ++ ) {
T_2 V_73 ;
F_6 ( V_2 , V_74 + V_64 , & V_73 , & V_14 ) ;
V_2 -> V_70 . V_75 [ V_64 ] = V_73 ;
}
if ( V_14 )
goto V_67;
F_22 ( V_2 -> V_62 , & V_2 -> V_70 ) ;
V_67:
F_9 ( V_24 , V_2 -> V_4 + V_61 ) ;
F_12 ( V_2 , V_26 , V_76 , & V_14 ) ;
F_12 ( V_2 , V_26 , V_32 , & V_14 ) ;
F_12 ( V_2 , V_30 , V_77 , & V_14 ) ;
F_12 ( V_2 , V_30 , V_78 , & V_14 ) ;
}
static T_4 F_23 ( int V_45 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
T_3 V_46 = F_4 ( V_2 -> V_4 + V_47 ) ;
if ( V_46 & V_23 )
F_19 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_79 ;
}
static int F_24 ( struct V_80 * V_62 , T_2 V_81 )
{
struct V_1 * V_2 = V_62 -> V_82 ;
int V_14 = 0 ;
F_12 ( V_2 , V_83 ,
V_84 , & V_14 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_15 ( V_2 ) ;
if ( V_14 )
return V_14 ;
if ( V_81 == V_85 )
return 0 ;
F_12 ( V_2 , V_83 ,
V_81 & V_86 , & V_14 ) ;
if ( V_14 )
return V_14 ;
F_16 ( 100 ) ;
F_12 ( V_2 , V_83 ,
( V_81 & V_86 ) |
V_87 , & V_14 ) ;
return V_14 ;
}
static int F_25 ( struct V_80 * V_62 , T_2 V_88 ,
T_3 V_89 , struct V_90 * V_75 )
{
struct V_1 * V_2 = V_62 -> V_82 ;
int V_64 , V_14 = 0 ;
T_2 V_12 ;
F_6 ( V_2 , V_51 , & V_12 , & V_14 ) ;
if ( V_14 )
return V_14 ;
if ( V_12 == V_55 ) {
F_26 ( & V_2 -> V_91 -> V_92 , L_1 ,
V_93 ) ;
F_12 ( V_2 , V_28 , V_29 , & V_14 ) ;
}
for ( V_64 = 0 ; V_64 < V_75 -> V_71 ; V_64 ++ ) {
F_12 ( V_2 , V_94 + V_64 ,
V_75 -> V_75 [ V_64 ] , & V_14 ) ;
}
F_12 ( V_2 , V_95 , V_75 -> V_71 - 1 , & V_14 ) ;
F_12 ( V_2 , V_28 , V_96 , & V_14 ) ;
return V_14 ;
}
static int F_27 ( struct V_80 * V_62 , bool V_21 )
{
struct V_1 * V_2 = V_62 -> V_82 ;
int V_14 ;
F_13 ( V_2 , false ) ;
F_14 ( V_97 , V_97 ,
V_2 -> V_4 + V_98 ) ;
if ( ! V_21 )
return 0 ;
F_14 ( V_99 ,
F_7 ( V_99 ,
V_100 ) ,
V_2 -> V_4 + V_98 ) ;
F_16 ( 100 ) ;
F_14 ( V_97 , 0 ,
V_2 -> V_4 + V_98 ) ;
V_14 = F_15 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_17 ( V_2 ,
V_36 ,
0x118 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_17 ( V_2 ,
V_39 ,
0x000 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_17 ( V_2 ,
V_42 ,
0x2aa ) ;
if ( V_14 )
return V_14 ;
F_13 ( V_2 , true ) ;
return 0 ;
}
static int F_28 ( struct V_101 * V_91 )
{
struct V_1 * V_2 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_10 ;
int V_14 , V_45 ;
V_104 = F_29 ( V_91 -> V_92 . V_106 , L_2 , 0 ) ;
if ( ! V_104 ) {
F_26 ( & V_91 -> V_92 , L_3 ) ;
return - V_107 ;
}
V_102 = F_30 ( V_104 ) ;
if ( V_102 == NULL )
return - V_108 ;
V_2 = F_31 ( & V_91 -> V_92 , sizeof( * V_2 ) , V_109 ) ;
if ( ! V_2 )
return - V_110 ;
F_32 ( & V_2 -> V_15 ) ;
V_2 -> V_111 = F_33 ( & V_102 -> V_92 ) ;
if ( ! V_2 -> V_111 )
return - V_110 ;
V_2 -> V_62 = F_34 ( & V_112 , V_2 ,
L_4 ,
V_113 |
V_114 |
V_115 |
V_116 ,
1 ) ;
if ( F_35 ( V_2 -> V_62 ) ) {
V_14 = F_36 ( V_2 -> V_62 ) ;
goto V_117;
}
V_2 -> V_62 -> V_118 = V_119 ;
V_10 = F_37 ( V_91 , V_120 , 0 ) ;
V_2 -> V_4 = F_38 ( & V_91 -> V_92 , V_10 ) ;
if ( F_35 ( V_2 -> V_4 ) ) {
V_14 = F_36 ( V_2 -> V_4 ) ;
goto V_121;
}
V_45 = F_39 ( V_91 , 0 ) ;
V_14 = F_40 ( & V_91 -> V_92 , V_45 ,
F_18 ,
F_23 ,
0 , NULL , V_2 ) ;
if ( V_14 ) {
F_26 ( & V_91 -> V_92 , L_5 ) ;
goto V_121;
}
V_2 -> V_122 = F_41 ( & V_91 -> V_92 , L_6 ) ;
if ( F_35 ( V_2 -> V_122 ) ) {
F_26 ( & V_91 -> V_92 , L_7 ) ;
V_14 = F_36 ( V_2 -> V_122 ) ;
goto V_121;
}
V_14 = F_42 ( V_2 -> V_122 ) ;
if ( V_14 ) {
F_26 ( & V_91 -> V_92 , L_8 ) ;
goto V_121;
}
V_14 = F_43 ( V_2 -> V_122 , V_123 ) ;
if ( V_14 ) {
F_26 ( & V_91 -> V_92 , L_9 ) ;
goto V_124;
}
F_44 ( & V_91 -> V_92 ) ;
V_2 -> V_91 = V_91 ;
F_45 ( V_91 , V_2 ) ;
V_14 = F_46 ( V_2 -> V_62 , & V_91 -> V_92 ) ;
if ( V_14 < 0 ) {
F_47 ( V_2 -> V_111 ) ;
goto V_124;
}
F_9 ( V_97 ,
V_2 -> V_4 + V_98 ) ;
F_48 ( V_2 -> V_62 , V_2 -> V_111 ) ;
return 0 ;
V_124:
F_49 ( V_2 -> V_122 ) ;
V_121:
F_50 ( V_2 -> V_62 ) ;
V_117:
F_47 ( V_2 -> V_111 ) ;
F_26 ( & V_91 -> V_92 , L_10 ) ;
return V_14 ;
}
static int F_51 ( struct V_101 * V_91 )
{
struct V_1 * V_2 = F_52 ( V_91 ) ;
F_49 ( V_2 -> V_122 ) ;
F_53 ( V_2 -> V_62 ) ;
F_47 ( V_2 -> V_111 ) ;
return 0 ;
}
