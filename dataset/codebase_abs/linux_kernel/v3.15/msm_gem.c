static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return ( ( ( T_1 ) V_4 -> V_9 -> V_10 ) << V_11 ) +
V_6 -> V_12 . V_13 ;
}
static struct V_14 * * F_3 ( struct V_1 * V_2 ,
int V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
T_1 V_13 ;
struct V_14 * * V_16 ;
int V_17 , V_18 ;
V_16 = F_4 ( V_15 , sizeof( struct V_14 * ) ) ;
if ( ! V_16 )
return F_5 ( - V_19 ) ;
V_17 = F_6 ( & V_6 -> V_12 . V_20 , V_4 -> V_9 ,
V_15 , 0 , V_21 ) ;
if ( V_17 ) {
F_7 ( V_16 ) ;
return F_5 ( V_17 ) ;
}
V_13 = F_1 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ ) {
V_16 [ V_18 ] = F_8 ( V_13 ) ;
V_13 += V_22 ;
}
return V_16 ;
}
static struct V_14 * * F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_23 ) {
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_14 * * V_16 ;
int V_15 = V_2 -> V_25 >> V_11 ;
if ( F_10 ( & V_26 ) )
V_16 = F_11 ( V_2 , 0 ) ;
else
V_16 = F_3 ( V_2 , V_15 ) ;
if ( F_12 ( V_16 ) ) {
F_13 ( V_7 -> V_7 , L_1 ,
F_14 ( V_16 ) ) ;
return V_16 ;
}
V_4 -> V_27 = F_15 ( V_16 , V_15 ) ;
if ( F_12 ( V_4 -> V_27 ) ) {
F_13 ( V_7 -> V_7 , L_2 ) ;
return F_16 ( V_4 -> V_27 ) ;
}
V_4 -> V_23 = V_16 ;
if ( V_4 -> V_28 & ( V_29 | V_30 ) )
F_17 ( V_7 -> V_7 , V_4 -> V_27 -> V_31 ,
V_4 -> V_27 -> V_32 , V_33 ) ;
}
return V_4 -> V_23 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_23 ) {
if ( V_4 -> V_28 & ( V_29 | V_30 ) )
F_19 ( V_2 -> V_7 -> V_7 , V_4 -> V_27 -> V_31 ,
V_4 -> V_27 -> V_32 , V_33 ) ;
F_20 ( V_4 -> V_27 ) ;
F_21 ( V_4 -> V_27 ) ;
if ( F_10 ( & V_26 ) )
F_22 ( V_2 , V_4 -> V_23 , true , false ) ;
else {
F_23 ( V_4 -> V_9 ) ;
F_7 ( V_4 -> V_23 ) ;
}
V_4 -> V_23 = NULL ;
}
}
struct V_14 * * F_24 ( struct V_1 * V_2 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_14 * * V_16 ;
F_25 ( & V_7 -> V_34 ) ;
V_16 = F_9 ( V_2 ) ;
F_26 ( & V_7 -> V_34 ) ;
return V_16 ;
}
void F_27 ( struct V_1 * V_2 )
{
}
int F_28 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_36 -> V_37 &= ~ V_38 ;
V_36 -> V_37 |= V_39 ;
if ( V_4 -> V_28 & V_29 ) {
V_36 -> V_40 = F_29 ( F_30 ( V_36 -> V_37 ) ) ;
} else if ( V_4 -> V_28 & V_30 ) {
V_36 -> V_40 = F_31 ( F_30 ( V_36 -> V_37 ) ) ;
} else {
F_32 ( V_36 -> V_41 ) ;
F_33 ( V_2 -> V_42 ) ;
V_36 -> V_43 = 0 ;
V_36 -> V_41 = V_2 -> V_42 ;
V_36 -> V_40 = F_30 ( V_36 -> V_37 ) ;
}
return 0 ;
}
int F_34 ( struct V_44 * V_42 , struct V_35 * V_36 )
{
int V_17 ;
V_17 = F_35 ( V_42 , V_36 ) ;
if ( V_17 ) {
F_36 ( L_3 , V_17 ) ;
return V_17 ;
}
return F_28 ( V_36 -> V_45 , V_36 ) ;
}
int F_37 ( struct V_35 * V_36 , struct V_46 * V_47 )
{
struct V_1 * V_2 = V_36 -> V_45 ;
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_14 * * V_23 ;
unsigned long V_48 ;
T_2 V_49 ;
int V_17 ;
V_17 = F_38 ( & V_7 -> V_34 ) ;
if ( V_17 )
goto V_50;
V_23 = F_9 ( V_2 ) ;
if ( F_12 ( V_23 ) ) {
V_17 = F_14 ( V_23 ) ;
goto V_51;
}
V_49 = ( ( unsigned long ) V_47 -> V_52 -
V_36 -> V_53 ) >> V_11 ;
V_48 = F_39 ( V_23 [ V_49 ] ) ;
F_40 ( L_4 , V_47 -> V_52 ,
V_48 , V_48 << V_11 ) ;
V_17 = F_41 ( V_36 , ( unsigned long ) V_47 -> V_52 , V_48 ) ;
V_51:
F_26 ( & V_7 -> V_34 ) ;
V_50:
switch ( V_17 ) {
case - V_54 :
case 0 :
case - V_55 :
case - V_56 :
case - V_57 :
return V_58 ;
case - V_19 :
return V_59 ;
default:
return V_60 ;
}
}
static T_3 F_42 ( struct V_1 * V_2 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
int V_17 ;
F_43 ( ! F_44 ( & V_7 -> V_34 ) ) ;
V_17 = F_45 ( V_2 ) ;
if ( V_17 ) {
F_13 ( V_7 -> V_7 , L_5 ) ;
return 0 ;
}
return F_46 ( & V_2 -> V_61 ) ;
}
T_3 F_47 ( struct V_1 * V_2 )
{
T_3 V_62 ;
F_25 ( & V_2 -> V_7 -> V_34 ) ;
V_62 = F_42 ( V_2 ) ;
F_26 ( & V_2 -> V_7 -> V_34 ) ;
return V_62 ;
}
int F_48 ( struct V_1 * V_2 , int V_63 ,
T_4 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 = 0 ;
if ( ! V_4 -> V_65 [ V_63 ] . V_64 ) {
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_66 * V_67 = V_6 -> V_68 [ V_63 ] ;
struct V_14 * * V_23 = F_9 ( V_2 ) ;
if ( F_12 ( V_23 ) )
return F_14 ( V_23 ) ;
if ( F_10 ( & V_26 ) ) {
T_4 V_62 = ( T_4 ) F_42 ( V_2 ) ;
V_17 = V_67 -> V_69 -> V_70 ( V_67 , V_62 , V_4 -> V_27 ,
V_2 -> V_25 , V_71 | V_72 ) ;
V_4 -> V_65 [ V_63 ] . V_64 = V_62 ;
} else {
V_4 -> V_65 [ V_63 ] . V_64 = F_1 ( V_2 ) ;
}
}
if ( ! V_17 )
* V_64 = V_4 -> V_65 [ V_63 ] . V_64 ;
return V_17 ;
}
int F_49 ( struct V_1 * V_2 , int V_63 , T_4 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 ;
if ( V_4 -> V_65 [ V_63 ] . V_64 ) {
* V_64 = V_4 -> V_65 [ V_63 ] . V_64 ;
return 0 ;
}
F_25 ( & V_2 -> V_7 -> V_34 ) ;
V_17 = F_48 ( V_2 , V_63 , V_64 ) ;
F_26 ( & V_2 -> V_7 -> V_34 ) ;
return V_17 ;
}
void F_50 ( struct V_1 * V_2 , int V_63 )
{
}
int F_51 ( struct V_73 * V_44 , struct V_24 * V_7 ,
struct V_74 * args )
{
args -> V_75 = F_52 ( args -> V_76 , args -> V_77 ) ;
args -> V_25 = F_53 ( args -> V_75 * args -> V_78 ) ;
return F_54 ( V_7 , V_44 , args -> V_25 ,
V_79 | V_29 , & args -> V_80 ) ;
}
int F_55 ( struct V_73 * V_44 , struct V_24 * V_7 ,
T_4 V_80 , T_3 * V_62 )
{
struct V_1 * V_2 ;
int V_17 = 0 ;
V_2 = F_56 ( V_7 , V_44 , V_80 ) ;
if ( V_2 == NULL ) {
V_17 = - V_81 ;
goto V_82;
}
* V_62 = F_47 ( V_2 ) ;
F_57 ( V_2 ) ;
V_82:
return V_17 ;
}
void * F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_43 ( ! F_44 ( & V_2 -> V_7 -> V_34 ) ) ;
if ( ! V_4 -> V_83 ) {
struct V_14 * * V_23 = F_9 ( V_2 ) ;
if ( F_12 ( V_23 ) )
return F_16 ( V_23 ) ;
V_4 -> V_83 = F_59 ( V_23 , V_2 -> V_25 >> V_11 ,
V_84 , F_29 ( V_85 ) ) ;
}
return V_4 -> V_83 ;
}
void * F_60 ( struct V_1 * V_2 )
{
void * V_17 ;
F_25 ( & V_2 -> V_7 -> V_34 ) ;
V_17 = F_58 ( V_2 ) ;
F_26 ( & V_2 -> V_7 -> V_34 ) ;
return V_17 ;
}
int F_61 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 = 0 ;
F_25 ( & V_7 -> V_34 ) ;
if ( ! F_62 ( & V_87 -> V_88 . V_89 ) ) {
V_17 = - V_90 ;
} else if ( F_63 ( V_4 ) ) {
V_87 -> V_91 = F_64 ( V_4 -> V_92 , V_4 -> V_93 ) ;
F_65 ( & V_87 -> V_88 . V_89 , & V_6 -> V_94 ) ;
} else {
F_66 ( V_6 -> V_95 , & V_87 -> V_88 ) ;
}
F_26 ( & V_7 -> V_34 ) ;
return V_17 ;
}
void F_67 ( struct V_1 * V_2 ,
struct V_96 * V_97 , bool V_98 , T_4 V_91 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_97 = V_97 ;
if ( V_98 )
V_4 -> V_93 = V_91 ;
else
V_4 -> V_92 = V_91 ;
F_68 ( & V_4 -> V_99 ) ;
F_65 ( & V_4 -> V_99 , & V_97 -> V_100 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_43 ( ! F_44 ( & V_7 -> V_34 ) ) ;
V_4 -> V_97 = NULL ;
V_4 -> V_92 = 0 ;
V_4 -> V_93 = 0 ;
F_68 ( & V_4 -> V_99 ) ;
F_65 ( & V_4 -> V_99 , & V_6 -> V_101 ) ;
}
int F_70 ( struct V_1 * V_2 , T_4 V_102 ,
struct V_103 * V_104 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 = 0 ;
if ( F_63 ( V_4 ) ) {
T_4 V_91 = 0 ;
if ( V_102 & V_105 )
V_91 = V_4 -> V_93 ;
if ( V_102 & V_106 )
V_91 = F_64 ( V_91 , V_4 -> V_92 ) ;
if ( V_102 & V_107 )
V_104 = NULL ;
V_17 = F_71 ( V_7 , V_91 , V_104 ) ;
}
return V_17 ;
}
int F_72 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_73 ( struct V_1 * V_2 , struct V_108 * V_109 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_110 = F_74 ( & V_2 -> V_61 ) ;
F_43 ( ! F_44 ( & V_7 -> V_34 ) ) ;
F_75 ( V_109 , L_6 ,
V_4 -> V_28 , F_63 ( V_4 ) ? 'A' : 'I' ,
V_4 -> V_92 , V_4 -> V_93 ,
V_2 -> V_111 , V_2 -> V_112 . V_112 . V_113 ,
V_110 , V_4 -> V_83 , V_2 -> V_25 ) ;
}
void F_76 ( struct V_114 * V_115 , struct V_108 * V_109 )
{
struct V_3 * V_4 ;
int V_116 = 0 ;
T_5 V_25 = 0 ;
F_77 (msm_obj, list, mm_list) {
struct V_1 * V_2 = & V_4 -> V_117 ;
F_75 ( V_109 , L_7 ) ;
F_73 ( V_2 , V_109 ) ;
V_116 ++ ;
V_25 += V_2 -> V_25 ;
}
F_75 ( V_109 , L_8 , V_116 , V_25 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_24 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_63 ;
F_43 ( ! F_44 ( & V_7 -> V_34 ) ) ;
F_43 ( F_63 ( V_4 ) ) ;
F_79 ( & V_4 -> V_99 ) ;
for ( V_63 = 0 ; V_63 < F_80 ( V_4 -> V_65 ) ; V_63 ++ ) {
struct V_66 * V_67 = V_6 -> V_68 [ V_63 ] ;
if ( V_67 && V_4 -> V_65 [ V_63 ] . V_64 ) {
T_4 V_62 = ( T_4 ) F_42 ( V_2 ) ;
V_67 -> V_69 -> V_118 ( V_67 , V_62 , V_4 -> V_27 , V_2 -> V_25 ) ;
}
}
F_81 ( V_2 ) ;
if ( V_2 -> V_119 ) {
if ( V_4 -> V_83 )
F_82 ( V_2 -> V_119 -> V_120 , V_4 -> V_83 ) ;
if ( V_4 -> V_23 )
F_7 ( V_4 -> V_23 ) ;
} else {
if ( V_4 -> V_83 )
F_83 ( V_4 -> V_83 ) ;
F_18 ( V_2 ) ;
}
if ( V_4 -> V_121 == & V_4 -> V_122 )
F_84 ( V_4 -> V_121 ) ;
F_85 ( V_2 ) ;
F_21 ( V_4 ) ;
}
int F_54 ( struct V_24 * V_7 , struct V_73 * V_44 ,
T_4 V_25 , T_4 V_28 , T_4 * V_80 )
{
struct V_1 * V_2 ;
int V_17 ;
V_17 = F_38 ( & V_7 -> V_34 ) ;
if ( V_17 )
return V_17 ;
V_2 = F_86 ( V_7 , V_25 , V_28 ) ;
F_26 ( & V_7 -> V_34 ) ;
if ( F_12 ( V_2 ) )
return F_14 ( V_2 ) ;
V_17 = F_87 ( V_44 , V_2 , V_80 ) ;
F_57 ( V_2 ) ;
return V_17 ;
}
static int F_88 ( struct V_24 * V_7 ,
T_4 V_25 , T_4 V_28 ,
struct V_1 * * V_2 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_3 * V_4 ;
unsigned V_123 ;
switch ( V_28 & V_124 ) {
case V_30 :
case V_125 :
case V_29 :
break;
default:
F_13 ( V_7 -> V_7 , L_9 ,
( V_28 & V_124 ) ) ;
return - V_90 ;
}
V_123 = sizeof( * V_4 ) ;
if ( ! F_10 ( & V_26 ) )
V_123 += sizeof( struct V_126 ) ;
V_4 = F_89 ( V_123 , V_127 ) ;
if ( ! V_4 )
return - V_19 ;
if ( ! F_10 ( & V_26 ) )
V_4 -> V_9 = ( void * ) & V_4 [ 1 ] ;
V_4 -> V_28 = V_28 ;
V_4 -> V_121 = & V_4 -> V_122 ;
F_90 ( V_4 -> V_121 ) ;
F_91 ( & V_4 -> V_128 ) ;
F_65 ( & V_4 -> V_99 , & V_6 -> V_101 ) ;
* V_2 = & V_4 -> V_117 ;
return 0 ;
}
struct V_1 * F_86 ( struct V_24 * V_7 ,
T_4 V_25 , T_4 V_28 )
{
struct V_1 * V_2 = NULL ;
int V_17 ;
F_43 ( ! F_44 ( & V_7 -> V_34 ) ) ;
V_25 = F_53 ( V_25 ) ;
V_17 = F_88 ( V_7 , V_25 , V_28 , & V_2 ) ;
if ( V_17 )
goto V_82;
if ( F_10 ( & V_26 ) ) {
V_17 = F_92 ( V_7 , V_2 , V_25 ) ;
if ( V_17 )
goto V_82;
} else {
F_93 ( V_7 , V_2 , V_25 ) ;
}
return V_2 ;
V_82:
if ( V_2 )
F_94 ( V_2 ) ;
return F_5 ( V_17 ) ;
}
struct V_1 * F_95 ( struct V_24 * V_7 ,
T_4 V_25 , struct V_129 * V_27 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_17 , V_15 ;
if ( ! F_10 ( & V_26 ) ) {
F_13 ( V_7 -> V_7 , L_10 ) ;
return F_5 ( - V_90 ) ;
}
V_25 = F_53 ( V_25 ) ;
V_17 = F_88 ( V_7 , V_25 , V_29 , & V_2 ) ;
if ( V_17 )
goto V_82;
F_93 ( V_7 , V_2 , V_25 ) ;
V_15 = V_25 / V_22 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_27 = V_27 ;
V_4 -> V_23 = F_4 ( V_15 , sizeof( struct V_14 * ) ) ;
if ( ! V_4 -> V_23 ) {
V_17 = - V_19 ;
goto V_82;
}
V_17 = F_96 ( V_27 , V_4 -> V_23 , NULL , V_15 ) ;
if ( V_17 )
goto V_82;
return V_2 ;
V_82:
if ( V_2 )
F_57 ( V_2 ) ;
return F_5 ( V_17 ) ;
}
