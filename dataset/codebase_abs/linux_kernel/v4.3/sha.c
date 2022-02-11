static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_10 * V_11 = F_5 ( V_3 -> V_12 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 . V_18 ;
unsigned int V_19 = F_6 ( V_7 ) ;
int error ;
T_1 V_20 ;
error = F_7 ( & V_14 -> V_17 ) ;
if ( error )
F_8 ( V_14 -> V_21 , L_1 , error ) ;
F_9 ( V_14 -> V_21 , V_5 -> V_22 , V_9 -> V_23 , V_24 ,
V_9 -> V_25 ) ;
F_9 ( V_14 -> V_21 , & V_9 -> V_26 , 1 , V_27 , 0 ) ;
memcpy ( V_9 -> V_28 , V_16 -> V_29 , V_19 ) ;
if ( V_5 -> V_16 )
memcpy ( V_5 -> V_16 , V_16 -> V_29 , V_19 ) ;
V_9 -> V_30 [ 0 ] = F_10 ( V_16 -> V_31 [ 0 ] ) ;
V_9 -> V_30 [ 1 ] = F_10 ( V_16 -> V_31 [ 1 ] ) ;
error = F_11 ( V_14 , & V_20 ) ;
if ( error < 0 )
F_8 ( V_14 -> V_21 , L_2 , V_20 ) ;
V_5 -> V_22 = V_9 -> V_32 ;
V_5 -> V_33 = V_9 -> V_34 ;
V_9 -> V_35 = false ;
V_9 -> V_36 = false ;
V_14 -> V_37 ( V_11 -> V_14 , error ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_38 * V_39 = F_13 ( V_3 -> V_12 ) ;
struct V_10 * V_11 = F_5 ( V_3 -> V_12 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
unsigned long V_40 = V_9 -> V_40 ;
int V_41 ;
if ( F_14 ( V_40 ) ) {
V_9 -> V_42 = V_39 -> V_42 ;
V_9 -> V_43 = V_44 ;
} else if ( F_15 ( V_40 ) ) {
V_9 -> V_42 = V_39 -> V_42 ;
V_9 -> V_43 = V_45 ;
}
V_9 -> V_23 = F_16 ( V_5 -> V_22 , V_5 -> V_33 ,
& V_9 -> V_25 ) ;
V_41 = F_17 ( V_14 -> V_21 , V_5 -> V_22 , V_9 -> V_23 , V_24 ,
V_9 -> V_25 ) ;
if ( V_41 < 0 )
return V_41 ;
F_18 ( & V_9 -> V_26 , V_14 -> V_17 . V_18 , V_46 ) ;
V_41 = F_17 ( V_14 -> V_21 , & V_9 -> V_26 , 1 , V_27 , 0 ) ;
if ( V_41 < 0 )
goto V_47;
V_41 = F_19 ( & V_14 -> V_17 , V_5 -> V_22 , V_9 -> V_23 ,
& V_9 -> V_26 , 1 , F_1 , V_3 ) ;
if ( V_41 )
goto V_48;
F_20 ( & V_14 -> V_17 ) ;
V_41 = F_21 ( V_3 , V_11 -> V_49 , 0 , 0 ) ;
if ( V_41 )
goto V_50;
return 0 ;
V_50:
F_7 ( & V_14 -> V_17 ) ;
V_48:
F_9 ( V_14 -> V_21 , & V_9 -> V_26 , 1 , V_27 , 0 ) ;
V_47:
F_9 ( V_14 -> V_21 , V_5 -> V_22 , V_9 -> V_23 , V_24 ,
V_9 -> V_25 ) ;
return V_41 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_10 * V_11 = F_5 ( V_5 -> V_51 . V_12 ) ;
const T_1 * V_52 = V_11 -> V_52 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_36 = true ;
V_9 -> V_35 = false ;
V_9 -> V_40 = V_11 -> V_53 ;
memcpy ( V_9 -> V_28 , V_52 , sizeof( V_9 -> V_28 ) ) ;
return 0 ;
}
static int F_23 ( struct V_4 * V_5 , void * V_54 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
unsigned long V_40 = V_9 -> V_40 ;
unsigned int V_19 = F_6 ( V_7 ) ;
unsigned int V_55 =
F_24 ( F_25 ( V_7 ) ) ;
if ( F_26 ( V_40 ) || F_27 ( V_40 ) ) {
struct V_56 * V_57 = V_54 ;
V_57 -> V_58 = V_9 -> V_58 ;
F_28 ( ( V_59 * ) V_57 -> V_60 ,
V_9 -> V_28 , V_19 ) ;
memcpy ( V_57 -> V_61 , V_9 -> V_62 , V_55 ) ;
} else if ( F_29 ( V_40 ) || F_30 ( V_40 ) ) {
struct V_63 * V_57 = V_54 ;
V_57 -> V_58 = V_9 -> V_58 ;
F_28 ( ( V_59 * ) V_57 -> V_60 ,
V_9 -> V_28 , V_19 ) ;
memcpy ( V_57 -> V_62 , V_9 -> V_62 , V_55 ) ;
} else {
return - V_64 ;
}
return 0 ;
}
static int F_31 ( struct V_4 * V_5 , T_2 V_65 ,
const T_1 * V_60 , const T_3 * V_61 , bool V_66 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
unsigned int V_19 = F_6 ( V_7 ) ;
unsigned int V_55 ;
T_2 V_58 = V_65 ;
V_55 = F_24 ( F_25 ( V_7 ) ) ;
V_9 -> V_58 = V_65 ;
memcpy ( V_9 -> V_62 , V_61 , V_55 ) ;
if ( V_65 <= V_55 ) {
V_9 -> V_36 = 1 ;
} else {
V_9 -> V_36 = 0 ;
if ( V_66 )
V_58 += V_67 ;
}
V_9 -> V_30 [ 0 ] = ( V_68 V_59 ) ( V_58 & ~ V_69 ) ;
V_9 -> V_30 [ 1 ] = ( V_68 V_59 ) ( V_58 >> 32 ) ;
F_28 ( ( V_59 * ) V_9 -> V_28 , ( const T_3 * ) V_60 ,
V_19 ) ;
V_9 -> V_70 = ( unsigned int ) ( V_65 & ( V_55 - 1 ) ) ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 , const void * V_71 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
unsigned long V_40 = V_9 -> V_40 ;
bool V_66 = F_14 ( V_40 ) ;
int V_41 = - V_64 ;
if ( F_26 ( V_40 ) || F_27 ( V_40 ) ) {
const struct V_56 * V_60 = V_71 ;
V_41 = F_31 ( V_5 , V_60 -> V_58 , V_60 -> V_60 ,
V_60 -> V_61 , V_66 ) ;
} else if ( F_29 ( V_40 ) || F_30 ( V_40 ) ) {
const struct V_63 * V_60 = V_71 ;
V_41 = F_31 ( V_5 , V_60 -> V_58 , V_60 -> V_60 ,
V_60 -> V_62 , V_66 ) ;
}
return V_41 ;
}
static int F_33 ( struct V_4 * V_5 )
{
struct V_6 * V_12 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_10 * V_11 = F_5 ( V_5 -> V_51 . V_12 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_72 * V_73 , * V_74 ;
unsigned int V_75 , V_76 ;
unsigned int V_77 ;
unsigned int V_33 ;
unsigned int V_55 ;
V_55 = F_24 ( F_25 ( V_12 ) ) ;
V_9 -> V_58 += V_5 -> V_33 ;
V_75 = V_5 -> V_33 + V_9 -> V_70 ;
if ( V_75 <= V_55 ) {
F_34 ( V_9 -> V_62 + V_9 -> V_70 , V_5 -> V_22 ,
0 , V_5 -> V_33 , 0 ) ;
V_9 -> V_70 += V_5 -> V_33 ;
return 0 ;
}
V_9 -> V_32 = V_5 -> V_22 ;
V_9 -> V_34 = V_5 -> V_33 ;
if ( V_9 -> V_70 )
memcpy ( V_9 -> V_78 , V_9 -> V_62 , V_9 -> V_70 ) ;
V_77 = V_75 % V_55 ;
if ( V_77 ) {
unsigned int V_79 = V_5 -> V_33 - V_77 ;
F_34 ( V_9 -> V_62 , V_5 -> V_22 , V_79 ,
V_77 , 0 ) ;
}
V_33 = V_75 - V_77 ;
V_76 = V_9 -> V_70 ;
V_74 = V_73 = V_5 -> V_22 ;
while ( V_76 < V_33 && V_74 ) {
if ( V_76 + F_35 ( V_74 ) > V_33 )
break;
V_76 += F_35 ( V_74 ) ;
V_73 = V_74 ;
V_74 = F_36 ( V_74 ) ;
}
if ( ! V_73 )
return - V_64 ;
F_37 ( V_73 ) ;
if ( V_9 -> V_70 ) {
F_38 ( V_9 -> V_74 , 2 ) ;
F_39 ( V_9 -> V_74 , V_9 -> V_78 , V_9 -> V_70 ) ;
F_40 ( V_9 -> V_74 , 2 , V_5 -> V_22 ) ;
V_5 -> V_22 = V_9 -> V_74 ;
}
V_5 -> V_33 = V_33 ;
V_9 -> V_70 = V_77 ;
return V_14 -> V_80 ( V_11 -> V_14 , & V_5 -> V_51 ) ;
}
static int F_41 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_10 * V_11 = F_5 ( V_5 -> V_51 . V_12 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
if ( ! V_9 -> V_70 )
return 0 ;
V_9 -> V_35 = true ;
V_9 -> V_32 = V_5 -> V_22 ;
V_9 -> V_34 = V_5 -> V_33 ;
memcpy ( V_9 -> V_78 , V_9 -> V_62 , V_9 -> V_70 ) ;
F_18 ( V_9 -> V_74 , V_9 -> V_78 , V_9 -> V_70 ) ;
V_5 -> V_22 = V_9 -> V_74 ;
V_5 -> V_33 = V_9 -> V_70 ;
return V_14 -> V_80 ( V_11 -> V_14 , & V_5 -> V_51 ) ;
}
static int F_42 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_10 * V_11 = F_5 ( V_5 -> V_51 . V_12 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
int V_41 ;
V_41 = F_22 ( V_5 ) ;
if ( V_41 )
return V_41 ;
V_9 -> V_32 = V_5 -> V_22 ;
V_9 -> V_34 = V_5 -> V_33 ;
V_9 -> V_36 = true ;
V_9 -> V_35 = true ;
return V_14 -> V_80 ( V_11 -> V_14 , & V_5 -> V_51 ) ;
}
static void F_43 ( struct V_2 * V_5 , int error )
{
struct V_81 * V_16 = V_5 -> V_1 ;
if ( error == - V_82 )
return;
V_16 -> error = error ;
F_44 ( & V_16 -> V_83 ) ;
}
static int F_45 ( struct V_6 * V_12 , const T_3 * V_84 ,
unsigned int V_85 )
{
unsigned int V_19 = F_6 ( V_12 ) ;
struct V_38 * V_39 = F_13 ( & V_12 -> V_51 ) ;
struct V_81 V_16 ;
struct V_4 * V_5 ;
struct V_72 V_74 ;
unsigned int V_55 ;
struct V_6 * V_86 ;
T_3 * V_62 ;
int V_41 ;
const char * V_87 ;
V_55 = F_24 ( F_25 ( V_12 ) ) ;
memset ( V_39 -> V_42 , 0 , sizeof( V_39 -> V_42 ) ) ;
if ( V_85 <= V_55 ) {
memcpy ( V_39 -> V_42 , V_84 , V_85 ) ;
return 0 ;
}
if ( V_19 == V_88 )
V_87 = L_3 ;
else if ( V_19 == V_89 )
V_87 = L_4 ;
else
return - V_64 ;
V_86 = F_46 ( V_87 , V_90 ,
V_91 ) ;
if ( F_47 ( V_86 ) )
return F_48 ( V_86 ) ;
V_5 = F_49 ( V_86 , V_92 ) ;
if ( ! V_5 ) {
V_41 = - V_93 ;
goto V_94;
}
F_50 ( & V_16 . V_83 ) ;
F_51 ( V_5 , V_95 ,
F_43 , & V_16 ) ;
F_52 ( V_86 , ~ 0 ) ;
V_62 = F_53 ( V_85 + V_96 , V_92 ) ;
if ( ! V_62 ) {
V_41 = - V_93 ;
goto V_97;
}
memcpy ( V_62 , V_84 , V_85 ) ;
F_18 ( & V_74 , V_62 , V_85 ) ;
F_54 ( V_5 , & V_74 , V_39 -> V_42 , V_85 ) ;
V_41 = F_55 ( V_5 ) ;
if ( V_41 == - V_82 || V_41 == - V_98 ) {
V_41 = F_56 ( & V_16 . V_83 ) ;
if ( ! V_41 )
V_41 = V_16 . error ;
}
if ( V_41 )
F_57 ( V_12 , V_99 ) ;
F_58 ( V_62 ) ;
V_97:
F_59 ( V_5 ) ;
V_94:
F_60 ( V_86 ) ;
return V_41 ;
}
static int F_61 ( struct V_100 * V_12 )
{
struct V_6 * V_7 = F_62 ( V_12 ) ;
struct V_38 * V_39 = F_13 ( V_12 ) ;
F_63 ( V_7 , sizeof( struct V_8 ) ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
return 0 ;
}
static int F_64 ( const struct V_101 * V_102 ,
struct V_13 * V_14 )
{
struct V_10 * V_11 ;
struct V_103 * V_104 ;
struct V_105 * V_51 ;
int V_41 ;
V_11 = F_53 ( sizeof( * V_11 ) , V_92 ) ;
if ( ! V_11 )
return - V_93 ;
V_11 -> V_52 = V_102 -> V_52 ;
V_104 = & V_11 -> V_104 . V_7 ;
V_104 -> V_106 = F_22 ;
V_104 -> V_107 = F_33 ;
V_104 -> V_108 = F_41 ;
V_104 -> V_28 = F_42 ;
V_104 -> V_109 = F_23 ;
V_104 -> V_110 = F_32 ;
if ( F_14 ( V_102 -> V_40 ) )
V_104 -> V_111 = F_45 ;
V_104 -> V_112 . V_19 = V_102 -> V_19 ;
V_104 -> V_112 . V_113 = V_102 -> V_113 ;
V_51 = & V_104 -> V_112 . V_51 ;
V_51 -> V_114 = V_102 -> V_55 ;
V_51 -> V_115 = 300 ;
V_51 -> V_116 = V_117 ;
V_51 -> V_118 = sizeof( struct V_38 ) ;
V_51 -> V_119 = 0 ;
V_51 -> V_120 = V_121 ;
V_51 -> V_122 = F_61 ;
F_65 ( & V_51 -> V_123 ) ;
snprintf ( V_51 -> V_124 , V_125 , L_5 , V_102 -> V_126 ) ;
snprintf ( V_51 -> V_127 , V_125 , L_5 ,
V_102 -> V_128 ) ;
F_65 ( & V_11 -> V_129 ) ;
V_11 -> V_49 = V_90 ;
V_11 -> V_53 = V_102 -> V_40 ;
V_11 -> V_14 = V_14 ;
V_41 = F_66 ( V_104 ) ;
if ( V_41 ) {
F_58 ( V_11 ) ;
F_67 ( V_14 -> V_21 , L_6 , V_51 -> V_124 ) ;
return V_41 ;
}
F_68 ( & V_11 -> V_129 , & V_130 ) ;
F_8 ( V_14 -> V_21 , L_7 , V_51 -> V_124 ) ;
return 0 ;
}
static void F_69 ( struct V_13 * V_14 )
{
struct V_10 * V_11 , * V_131 ;
F_70 (tmpl, n, &ahash_algs, entry) {
F_71 ( & V_11 -> V_104 . V_7 ) ;
F_72 ( & V_11 -> V_129 ) ;
F_58 ( V_11 ) ;
}
}
static int F_73 ( struct V_13 * V_14 )
{
int V_41 , V_132 ;
for ( V_132 = 0 ; V_132 < F_74 ( V_133 ) ; V_132 ++ ) {
V_41 = F_64 ( & V_133 [ V_132 ] , V_14 ) ;
if ( V_41 )
goto V_134;
}
return 0 ;
V_134:
F_69 ( V_14 ) ;
return V_41 ;
}
