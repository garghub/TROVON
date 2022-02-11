static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_3 ( V_6 -> V_7 , V_6 -> V_8 , V_6 -> V_9 ,
V_6 -> V_9 ) ;
F_4 ( V_10 , V_2 -> V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_6 ( V_10 , V_2 -> V_11 ) ;
F_3 ( V_6 -> V_7 , V_6 -> V_8 , V_6 -> V_9 , 0 ) ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_13 ) ;
struct V_14 * V_14 ;
int V_15 ;
F_8 ( V_4 -> V_16 + V_17 , 0 ) ;
V_14 = F_9 ( V_13 , & V_4 -> V_18 -> V_19 ) ;
if ( ! V_14 ) {
F_8 ( V_4 -> V_16 + V_17 ,
V_20 ) ;
V_4 -> V_21 = false ;
return 0 ;
}
F_8 ( V_4 -> V_16 + V_17 , V_22 ) ;
F_10 ( V_13 , V_14 ) ;
V_15 = F_11 ( V_13 , V_14 ) ;
F_12 ( V_14 ) ;
return V_15 ;
}
static enum V_23
F_13 ( struct V_12 * V_13 ,
struct V_24 * V_25 )
{
return V_26 ;
}
static enum V_27
F_14 ( struct V_12 * V_13 , bool V_28 )
{
struct V_3 * V_4 = F_2 ( V_13 ) ;
return V_4 -> V_21 ? V_29 :
V_30 ;
}
static int F_15 ( struct V_31 * V_32 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_12 * V_13 = & V_4 -> V_13 ;
struct V_33 * V_34 = V_4 -> V_34 ;
int V_15 ;
V_2 -> V_35 = V_36 ;
V_15 = F_16 ( V_32 , V_2 , & V_37 ,
V_38 , NULL ) ;
if ( V_15 ) {
F_17 ( V_34 , L_1 , V_15 ) ;
return V_15 ;
} ;
F_18 ( V_2 , & V_39 ) ;
V_4 -> V_13 . V_40 = V_41 ;
V_15 = F_19 ( V_32 , V_13 , & V_42 ,
V_43 ) ;
if ( V_15 ) {
F_17 ( V_34 , L_2 , V_15 ) ;
goto V_44;
} ;
F_20 ( V_13 , & V_45 ) ;
V_15 = F_21 ( V_13 , V_2 ) ;
if ( V_15 ) {
F_17 ( V_34 , L_3 , V_15 ) ;
goto V_46;
} ;
return 0 ;
V_46:
F_22 ( V_13 ) ;
V_44:
F_23 ( V_2 ) ;
return V_15 ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_33 * V_34 = V_4 -> V_34 ;
struct V_47 V_48 ;
struct V_7 * V_7 ;
int V_15 ;
V_15 = F_25 ( V_34 -> V_49 ,
L_4 , 2 , 0 , & V_48 ) ;
if ( V_15 )
return V_15 ;
V_7 = F_26 ( V_48 . V_50 ) ;
if ( F_27 ( V_7 ) ) {
V_15 = F_28 ( V_7 ) ;
goto V_51;
}
V_6 -> V_7 = V_7 ;
V_6 -> V_8 = V_48 . args [ 0 ] ;
V_6 -> V_9 = V_48 . args [ 1 ] ;
V_51:
F_29 ( V_48 . V_50 ) ;
return V_15 ;
}
static int F_30 ( struct V_3 * V_4 , struct V_52 * V_53 )
{
int V_54 = V_53 -> V_54 ;
T_1 * V_55 = V_53 -> V_55 ;
T_2 V_56 = 0 ;
int V_57 ;
F_31 ( & V_4 -> V_58 ) ;
F_32 ( V_4 -> V_16 + V_59 , V_60 , V_60 ) ;
F_32 ( V_4 -> V_16 + V_59 , V_61 , 0 ) ;
while ( V_54 > 0 ) {
T_2 V_62 ;
F_32 ( V_4 -> V_16 + V_63 , V_64 ,
V_64 ) ;
F_8 ( V_4 -> V_16 + V_65 , V_56 ) ;
F_32 ( V_4 -> V_16 + V_59 , V_66 ,
V_66 ) ;
if ( ! F_33 ( & V_4 -> V_58 ,
F_34 ( 1000 ) ) ) {
F_17 ( V_4 -> V_34 , L_5 ) ;
return - V_67 ;
}
V_62 = F_35 ( V_4 -> V_16 + V_68 ) ;
V_62 = ( V_62 & V_69 ) >> V_70 ;
V_62 = F_36 ( T_2 , V_54 , V_62 ) ;
for ( V_57 = 0 ; V_57 < V_62 ; V_57 ++ )
* V_55 ++ = F_35 ( V_4 -> V_16 + V_71 ) ;
V_54 -= V_62 ;
V_56 += V_62 ;
}
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , struct V_52 * V_53 )
{
if ( ( V_53 -> V_54 != 1 ) || ( ( V_53 -> V_72 != V_73 ) ) )
return - V_74 ;
F_8 ( V_4 -> V_16 + V_75 , V_53 -> V_72 ) ;
return 0 ;
}
static int F_38 ( struct V_76 * V_19 , struct V_52 * V_77 ,
int V_78 )
{
struct V_3 * V_4 = F_39 ( V_19 ) ;
struct V_79 * V_18 = V_4 -> V_18 ;
int V_15 = 0 ;
int V_57 ;
F_40 ( & V_18 -> V_80 ) ;
for ( V_57 = 0 ; V_57 < V_78 ; V_57 ++ ) {
if ( V_77 [ V_57 ] . V_81 & V_82 )
V_15 = F_30 ( V_4 , & V_77 [ V_57 ] ) ;
else
V_15 = F_37 ( V_4 , & V_77 [ V_57 ] ) ;
if ( V_15 < 0 )
break;
}
if ( ! V_15 )
V_15 = V_78 ;
F_41 ( & V_18 -> V_80 ) ;
return V_15 ;
}
static T_2 F_42 ( struct V_76 * V_83 )
{
return V_84 | V_85 ;
}
static int F_43 ( struct V_3 * V_4 )
{
struct V_33 * V_34 = V_4 -> V_34 ;
struct V_76 * V_19 ;
struct V_79 * V_18 ;
int V_15 ;
V_18 = F_44 ( V_34 , sizeof( * V_18 ) , V_86 ) ;
if ( ! V_18 )
return - V_87 ;
V_4 -> V_18 = V_18 ;
F_45 ( & V_18 -> V_80 ) ;
V_19 = & V_18 -> V_19 ;
V_19 -> V_88 = V_89 ;
V_19 -> V_90 = V_91 ;
V_19 -> V_34 . V_92 = V_34 ;
V_19 -> V_93 = & V_94 ;
snprintf ( V_19 -> V_95 , sizeof( V_19 -> V_95 ) , L_6 ) ;
V_15 = F_46 ( V_19 ) ;
if ( V_15 ) {
F_17 ( V_34 , L_7 , V_15 ) ;
return V_15 ;
}
F_47 ( V_19 , V_4 ) ;
return 0 ;
}
static T_3 F_48 ( int V_96 , void * V_97 )
{
struct V_3 * V_4 = V_97 ;
F_49 ( V_4 -> V_13 . V_34 ) ;
return V_98 ;
}
static T_3 F_50 ( int V_96 , void * V_97 )
{
struct V_3 * V_4 = V_97 ;
T_2 V_99 ;
V_99 = F_35 ( V_4 -> V_16 + V_100 ) ;
F_32 ( V_4 -> V_16 + V_100 , V_101 ,
V_101 ) ;
if ( V_99 & V_102 ) {
V_4 -> V_21 = true ;
return V_103 ;
}
if ( V_99 & V_104 ) {
F_8 ( V_4 -> V_16 + V_17 ,
V_20 ) ;
V_4 -> V_21 = false ;
return V_103 ;
}
if ( V_99 & V_105 ) {
V_58 ( & V_4 -> V_58 ) ;
return V_98 ;
}
return V_106 ;
}
static void F_51 ( struct V_3 * V_4 )
{
unsigned long V_107 = F_52 ( V_4 -> V_108 ) ;
int div ;
div = F_53 ( V_107 / 1000 , 400 * 4 ) - 1 ;
F_8 ( V_4 -> V_16 + V_109 , div ) ;
F_8 ( V_4 -> V_16 + V_110 , 0x80 ) ;
F_8 ( V_4 -> V_16 + V_17 , V_20 ) ;
F_8 ( V_4 -> V_16 + V_75 , V_73 ) ;
F_32 ( V_4 -> V_16 + V_59 , V_66 , V_66 ) ;
}
static int F_54 ( struct V_33 * V_34 , struct V_33 * V_111 , void * V_112 )
{
struct V_113 * V_114 = F_55 ( V_34 ) ;
struct V_31 * V_32 = V_112 ;
struct V_115 * V_116 ;
struct V_3 * V_4 ;
int V_96 ;
int V_15 ;
V_4 = F_44 ( V_34 , sizeof( * V_4 ) , V_86 ) ;
if ( ! V_4 )
return - V_87 ;
V_4 -> V_34 = V_34 ;
F_56 ( V_34 , V_4 ) ;
V_116 = F_57 ( V_114 , V_117 , 0 ) ;
V_4 -> V_16 = F_58 ( V_34 , V_116 ) ;
if ( F_27 ( V_4 -> V_16 ) )
return F_28 ( V_4 -> V_16 ) ;
V_96 = F_59 ( V_114 , 0 ) ;
if ( V_96 < 0 )
return V_96 ;
V_4 -> V_108 = F_60 ( V_34 , L_8 ) ;
if ( F_27 ( V_4 -> V_108 ) ) {
V_15 = F_28 ( V_4 -> V_108 ) ;
F_17 ( V_34 , L_9 , V_15 ) ;
return V_15 ;
}
V_15 = F_24 ( V_4 ) ;
if ( V_15 ) {
F_17 ( V_34 , L_10 , V_15 ) ;
return V_15 ;
}
V_15 = F_43 ( V_4 ) ;
if ( V_15 ) {
F_17 ( V_34 , L_11 , V_15 ) ;
return V_15 ;
}
V_15 = F_15 ( V_32 , V_4 ) ;
if ( V_15 ) {
F_17 ( V_34 , L_12 , V_15 ) ;
return V_15 ;
}
F_61 ( & V_4 -> V_58 ) ;
V_15 = F_62 ( V_34 , V_96 , F_50 ,
F_48 , V_118 ,
F_63 ( V_34 ) , V_4 ) ;
if ( V_15 ) {
F_17 ( V_34 , L_13 , V_15 ) ;
return V_15 ;
}
V_15 = F_64 ( V_4 -> V_108 ) ;
if ( V_15 )
return V_15 ;
F_51 ( V_4 ) ;
return 0 ;
}
static void F_65 ( struct V_33 * V_34 , struct V_33 * V_111 ,
void * V_112 )
{
struct V_3 * V_4 = F_66 ( V_34 ) ;
F_67 ( V_4 -> V_108 ) ;
}
static int F_68 ( struct V_113 * V_114 )
{
return F_69 ( & V_114 -> V_34 , & V_119 ) ;
}
static int F_70 ( struct V_113 * V_114 )
{
F_71 ( & V_114 -> V_34 , & V_119 ) ;
return 0 ;
}
