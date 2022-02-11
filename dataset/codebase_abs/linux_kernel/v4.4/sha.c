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
F_9 ( V_14 -> V_21 , V_5 -> V_22 , V_9 -> V_23 , V_24 ) ;
F_9 ( V_14 -> V_21 , & V_9 -> V_25 , 1 , V_26 ) ;
memcpy ( V_9 -> V_27 , V_16 -> V_28 , V_19 ) ;
if ( V_5 -> V_16 )
memcpy ( V_5 -> V_16 , V_16 -> V_28 , V_19 ) ;
V_9 -> V_29 [ 0 ] = F_10 ( V_16 -> V_30 [ 0 ] ) ;
V_9 -> V_29 [ 1 ] = F_10 ( V_16 -> V_30 [ 1 ] ) ;
error = F_11 ( V_14 , & V_20 ) ;
if ( error < 0 )
F_8 ( V_14 -> V_21 , L_2 , V_20 ) ;
V_5 -> V_22 = V_9 -> V_31 ;
V_5 -> V_32 = V_9 -> V_33 ;
V_9 -> V_34 = false ;
V_9 -> V_35 = false ;
V_14 -> V_36 ( V_11 -> V_14 , error ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_37 * V_38 = F_13 ( V_3 -> V_12 ) ;
struct V_10 * V_11 = F_5 ( V_3 -> V_12 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
unsigned long V_39 = V_9 -> V_39 ;
int V_40 ;
if ( F_14 ( V_39 ) ) {
V_9 -> V_41 = V_38 -> V_41 ;
V_9 -> V_42 = V_43 ;
} else if ( F_15 ( V_39 ) ) {
V_9 -> V_41 = V_38 -> V_41 ;
V_9 -> V_42 = V_44 ;
}
V_9 -> V_23 = F_16 ( V_5 -> V_22 , V_5 -> V_32 ) ;
V_40 = F_17 ( V_14 -> V_21 , V_5 -> V_22 , V_9 -> V_23 , V_24 ) ;
if ( V_40 < 0 )
return V_40 ;
F_18 ( & V_9 -> V_25 , V_14 -> V_17 . V_18 , V_45 ) ;
V_40 = F_17 ( V_14 -> V_21 , & V_9 -> V_25 , 1 , V_26 ) ;
if ( V_40 < 0 )
goto V_46;
V_40 = F_19 ( & V_14 -> V_17 , V_5 -> V_22 , V_9 -> V_23 ,
& V_9 -> V_25 , 1 , F_1 , V_3 ) ;
if ( V_40 )
goto V_47;
F_20 ( & V_14 -> V_17 ) ;
V_40 = F_21 ( V_3 , V_11 -> V_48 , 0 , 0 ) ;
if ( V_40 )
goto V_49;
return 0 ;
V_49:
F_7 ( & V_14 -> V_17 ) ;
V_47:
F_9 ( V_14 -> V_21 , & V_9 -> V_25 , 1 , V_26 ) ;
V_46:
F_9 ( V_14 -> V_21 , V_5 -> V_22 , V_9 -> V_23 , V_24 ) ;
return V_40 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_10 * V_11 = F_5 ( V_5 -> V_50 . V_12 ) ;
const T_1 * V_51 = V_11 -> V_51 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_35 = true ;
V_9 -> V_34 = false ;
V_9 -> V_39 = V_11 -> V_52 ;
memcpy ( V_9 -> V_27 , V_51 , sizeof( V_9 -> V_27 ) ) ;
return 0 ;
}
static int F_23 ( struct V_4 * V_5 , void * V_53 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
unsigned long V_39 = V_9 -> V_39 ;
unsigned int V_19 = F_6 ( V_7 ) ;
unsigned int V_54 =
F_24 ( F_25 ( V_7 ) ) ;
if ( F_26 ( V_39 ) || F_27 ( V_39 ) ) {
struct V_55 * V_56 = V_53 ;
V_56 -> V_57 = V_9 -> V_57 ;
F_28 ( ( V_58 * ) V_56 -> V_59 ,
V_9 -> V_27 , V_19 ) ;
memcpy ( V_56 -> V_60 , V_9 -> V_61 , V_54 ) ;
} else if ( F_29 ( V_39 ) || F_30 ( V_39 ) ) {
struct V_62 * V_56 = V_53 ;
V_56 -> V_57 = V_9 -> V_57 ;
F_28 ( ( V_58 * ) V_56 -> V_59 ,
V_9 -> V_27 , V_19 ) ;
memcpy ( V_56 -> V_61 , V_9 -> V_61 , V_54 ) ;
} else {
return - V_63 ;
}
return 0 ;
}
static int F_31 ( struct V_4 * V_5 , T_2 V_64 ,
const T_1 * V_59 , const T_3 * V_60 , bool V_65 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
unsigned int V_19 = F_6 ( V_7 ) ;
unsigned int V_54 ;
T_2 V_57 = V_64 ;
V_54 = F_24 ( F_25 ( V_7 ) ) ;
V_9 -> V_57 = V_64 ;
memcpy ( V_9 -> V_61 , V_60 , V_54 ) ;
if ( V_64 <= V_54 ) {
V_9 -> V_35 = 1 ;
} else {
V_9 -> V_35 = 0 ;
if ( V_65 )
V_57 += V_66 ;
}
V_9 -> V_29 [ 0 ] = ( V_67 V_58 ) ( V_57 & ~ V_68 ) ;
V_9 -> V_29 [ 1 ] = ( V_67 V_58 ) ( V_57 >> 32 ) ;
F_28 ( ( V_58 * ) V_9 -> V_27 , ( const T_3 * ) V_59 ,
V_19 ) ;
V_9 -> V_69 = ( unsigned int ) ( V_64 & ( V_54 - 1 ) ) ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 , const void * V_70 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
unsigned long V_39 = V_9 -> V_39 ;
bool V_65 = F_14 ( V_39 ) ;
int V_40 = - V_63 ;
if ( F_26 ( V_39 ) || F_27 ( V_39 ) ) {
const struct V_55 * V_59 = V_70 ;
V_40 = F_31 ( V_5 , V_59 -> V_57 , V_59 -> V_59 ,
V_59 -> V_60 , V_65 ) ;
} else if ( F_29 ( V_39 ) || F_30 ( V_39 ) ) {
const struct V_62 * V_59 = V_70 ;
V_40 = F_31 ( V_5 , V_59 -> V_57 , V_59 -> V_59 ,
V_59 -> V_61 , V_65 ) ;
}
return V_40 ;
}
static int F_33 ( struct V_4 * V_5 )
{
struct V_6 * V_12 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_10 * V_11 = F_5 ( V_5 -> V_50 . V_12 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_71 * V_72 , * V_73 ;
unsigned int V_74 , V_75 ;
unsigned int V_76 ;
unsigned int V_32 ;
unsigned int V_54 ;
V_54 = F_24 ( F_25 ( V_12 ) ) ;
V_9 -> V_57 += V_5 -> V_32 ;
V_74 = V_5 -> V_32 + V_9 -> V_69 ;
if ( V_74 <= V_54 ) {
F_34 ( V_9 -> V_61 + V_9 -> V_69 , V_5 -> V_22 ,
0 , V_5 -> V_32 , 0 ) ;
V_9 -> V_69 += V_5 -> V_32 ;
return 0 ;
}
V_9 -> V_31 = V_5 -> V_22 ;
V_9 -> V_33 = V_5 -> V_32 ;
if ( V_9 -> V_69 )
memcpy ( V_9 -> V_77 , V_9 -> V_61 , V_9 -> V_69 ) ;
V_76 = V_74 % V_54 ;
if ( V_76 ) {
unsigned int V_78 = V_5 -> V_32 - V_76 ;
F_34 ( V_9 -> V_61 , V_5 -> V_22 , V_78 ,
V_76 , 0 ) ;
}
V_32 = V_74 - V_76 ;
V_75 = V_9 -> V_69 ;
V_73 = V_72 = V_5 -> V_22 ;
while ( V_75 < V_32 && V_73 ) {
if ( V_75 + F_35 ( V_73 ) > V_32 )
break;
V_75 += F_35 ( V_73 ) ;
V_72 = V_73 ;
V_73 = F_36 ( V_73 ) ;
}
if ( ! V_72 )
return - V_63 ;
F_37 ( V_72 ) ;
if ( V_9 -> V_69 ) {
F_38 ( V_9 -> V_73 , 2 ) ;
F_39 ( V_9 -> V_73 , V_9 -> V_77 , V_9 -> V_69 ) ;
F_40 ( V_9 -> V_73 , 2 , V_5 -> V_22 ) ;
V_5 -> V_22 = V_9 -> V_73 ;
}
V_5 -> V_32 = V_32 ;
V_9 -> V_69 = V_76 ;
return V_14 -> V_79 ( V_11 -> V_14 , & V_5 -> V_50 ) ;
}
static int F_41 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_10 * V_11 = F_5 ( V_5 -> V_50 . V_12 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
if ( ! V_9 -> V_69 )
return 0 ;
V_9 -> V_34 = true ;
V_9 -> V_31 = V_5 -> V_22 ;
V_9 -> V_33 = V_5 -> V_32 ;
memcpy ( V_9 -> V_77 , V_9 -> V_61 , V_9 -> V_69 ) ;
F_18 ( V_9 -> V_73 , V_9 -> V_77 , V_9 -> V_69 ) ;
V_5 -> V_22 = V_9 -> V_73 ;
V_5 -> V_32 = V_9 -> V_69 ;
return V_14 -> V_79 ( V_11 -> V_14 , & V_5 -> V_50 ) ;
}
static int F_42 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_10 * V_11 = F_5 ( V_5 -> V_50 . V_12 ) ;
struct V_13 * V_14 = V_11 -> V_14 ;
int V_40 ;
V_40 = F_22 ( V_5 ) ;
if ( V_40 )
return V_40 ;
V_9 -> V_31 = V_5 -> V_22 ;
V_9 -> V_33 = V_5 -> V_32 ;
V_9 -> V_35 = true ;
V_9 -> V_34 = true ;
return V_14 -> V_79 ( V_11 -> V_14 , & V_5 -> V_50 ) ;
}
static void F_43 ( struct V_2 * V_5 , int error )
{
struct V_80 * V_16 = V_5 -> V_1 ;
if ( error == - V_81 )
return;
V_16 -> error = error ;
F_44 ( & V_16 -> V_82 ) ;
}
static int F_45 ( struct V_6 * V_12 , const T_3 * V_83 ,
unsigned int V_84 )
{
unsigned int V_19 = F_6 ( V_12 ) ;
struct V_37 * V_38 = F_13 ( & V_12 -> V_50 ) ;
struct V_80 V_16 ;
struct V_4 * V_5 ;
struct V_71 V_73 ;
unsigned int V_54 ;
struct V_6 * V_85 ;
T_3 * V_61 ;
int V_40 ;
const char * V_86 ;
V_54 = F_24 ( F_25 ( V_12 ) ) ;
memset ( V_38 -> V_41 , 0 , sizeof( V_38 -> V_41 ) ) ;
if ( V_84 <= V_54 ) {
memcpy ( V_38 -> V_41 , V_83 , V_84 ) ;
return 0 ;
}
if ( V_19 == V_87 )
V_86 = L_3 ;
else if ( V_19 == V_88 )
V_86 = L_4 ;
else
return - V_63 ;
V_85 = F_46 ( V_86 , V_89 ,
V_90 ) ;
if ( F_47 ( V_85 ) )
return F_48 ( V_85 ) ;
V_5 = F_49 ( V_85 , V_91 ) ;
if ( ! V_5 ) {
V_40 = - V_92 ;
goto V_93;
}
F_50 ( & V_16 . V_82 ) ;
F_51 ( V_5 , V_94 ,
F_43 , & V_16 ) ;
F_52 ( V_85 , ~ 0 ) ;
V_61 = F_53 ( V_84 + V_95 , V_91 ) ;
if ( ! V_61 ) {
V_40 = - V_92 ;
goto V_96;
}
memcpy ( V_61 , V_83 , V_84 ) ;
F_18 ( & V_73 , V_61 , V_84 ) ;
F_54 ( V_5 , & V_73 , V_38 -> V_41 , V_84 ) ;
V_40 = F_55 ( V_5 ) ;
if ( V_40 == - V_81 || V_40 == - V_97 ) {
V_40 = F_56 ( & V_16 . V_82 ) ;
if ( ! V_40 )
V_40 = V_16 . error ;
}
if ( V_40 )
F_57 ( V_12 , V_98 ) ;
F_58 ( V_61 ) ;
V_96:
F_59 ( V_5 ) ;
V_93:
F_60 ( V_85 ) ;
return V_40 ;
}
static int F_61 ( struct V_99 * V_12 )
{
struct V_6 * V_7 = F_62 ( V_12 ) ;
struct V_37 * V_38 = F_13 ( V_12 ) ;
F_63 ( V_7 , sizeof( struct V_8 ) ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
return 0 ;
}
static int F_64 ( const struct V_100 * V_101 ,
struct V_13 * V_14 )
{
struct V_10 * V_11 ;
struct V_102 * V_103 ;
struct V_104 * V_50 ;
int V_40 ;
V_11 = F_53 ( sizeof( * V_11 ) , V_91 ) ;
if ( ! V_11 )
return - V_92 ;
V_11 -> V_51 = V_101 -> V_51 ;
V_103 = & V_11 -> V_103 . V_7 ;
V_103 -> V_105 = F_22 ;
V_103 -> V_106 = F_33 ;
V_103 -> V_107 = F_41 ;
V_103 -> V_27 = F_42 ;
V_103 -> V_108 = F_23 ;
V_103 -> V_109 = F_32 ;
if ( F_14 ( V_101 -> V_39 ) )
V_103 -> V_110 = F_45 ;
V_103 -> V_111 . V_19 = V_101 -> V_19 ;
V_103 -> V_111 . V_112 = V_101 -> V_112 ;
V_50 = & V_103 -> V_111 . V_50 ;
V_50 -> V_113 = V_101 -> V_54 ;
V_50 -> V_114 = 300 ;
V_50 -> V_115 = V_116 ;
V_50 -> V_117 = sizeof( struct V_37 ) ;
V_50 -> V_118 = 0 ;
V_50 -> V_119 = V_120 ;
V_50 -> V_121 = F_61 ;
F_65 ( & V_50 -> V_122 ) ;
snprintf ( V_50 -> V_123 , V_124 , L_5 , V_101 -> V_125 ) ;
snprintf ( V_50 -> V_126 , V_124 , L_5 ,
V_101 -> V_127 ) ;
F_65 ( & V_11 -> V_128 ) ;
V_11 -> V_48 = V_89 ;
V_11 -> V_52 = V_101 -> V_39 ;
V_11 -> V_14 = V_14 ;
V_40 = F_66 ( V_103 ) ;
if ( V_40 ) {
F_58 ( V_11 ) ;
F_67 ( V_14 -> V_21 , L_6 , V_50 -> V_123 ) ;
return V_40 ;
}
F_68 ( & V_11 -> V_128 , & V_129 ) ;
F_8 ( V_14 -> V_21 , L_7 , V_50 -> V_123 ) ;
return 0 ;
}
static void F_69 ( struct V_13 * V_14 )
{
struct V_10 * V_11 , * V_130 ;
F_70 (tmpl, n, &ahash_algs, entry) {
F_71 ( & V_11 -> V_103 . V_7 ) ;
F_72 ( & V_11 -> V_128 ) ;
F_58 ( V_11 ) ;
}
}
static int F_73 ( struct V_13 * V_14 )
{
int V_40 , V_131 ;
for ( V_131 = 0 ; V_131 < F_74 ( V_132 ) ; V_131 ++ ) {
V_40 = F_64 ( & V_132 [ V_131 ] , V_14 ) ;
if ( V_40 )
goto V_133;
}
return 0 ;
V_133:
F_69 ( V_14 ) ;
return V_40 ;
}
