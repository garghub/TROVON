static char * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
return F_2 ( V_4 , L_1 , F_3 ( V_2 ) ) ;
}
static inline void F_4 ( int V_5 , const char * V_6 , int V_7 , const unsigned char * V_8 )
{
int V_9 ;
if ( V_10 < V_5 )
return;
F_5 ( V_11 L_2 , __FILE__ , V_6 , V_7 ) ;
for ( V_9 = 0 ; V_9 < V_7 ; ++ V_9 ) {
F_5 ( L_3 , V_8 [ V_9 ] ) ;
}
F_5 ( L_4 ) ;
}
static inline void F_6 ( struct V_12 * V_2 )
{
F_7 ( 2 , L_5 , V_13 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_14 ) ;
F_9 ( V_2 -> V_15 ) ;
F_10 ( V_2 -> V_16 ) ;
F_10 ( V_2 -> V_17 ) ;
F_10 ( V_2 -> V_18 ) ;
F_10 ( V_2 ) ;
F_7 ( 2 , L_6 , V_13 ) ;
}
static int F_11 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_12 * V_2 = NULL ;
int V_21 ;
int V_22 = 0 ;
struct V_23 * V_24 ;
struct V_25 V_26 ;
int V_27 ;
F_7 ( 2 , L_5 , V_13 ) ;
F_12 ( V_19 , V_20 ) ;
V_21 = F_13 ( V_19 ) ;
V_24 = F_14 ( & V_28 , V_21 ) ;
if ( ! V_24 ) {
F_5 ( V_29 L_7 ,
V_13 , V_21 ) ;
V_22 = - V_30 ;
goto exit;
}
F_15 ( & V_31 ) ;
V_2 = F_16 ( V_24 ) ;
if ( ! V_2 ) {
F_17 ( & V_31 ) ;
V_22 = - V_30 ;
goto exit;
}
if ( F_18 ( & V_2 -> V_32 ) ) {
F_17 ( & V_31 ) ;
V_22 = - V_33 ;
goto exit;
}
if ( V_2 -> V_34 ) {
F_17 ( & V_31 ) ;
V_22 = - V_35 ;
goto V_36;
}
V_2 -> V_34 = 1 ;
F_17 ( & V_31 ) ;
V_27 = F_19 ( V_2 -> V_37 ,
F_20 ( V_2 -> V_37 , 0 ) ,
V_38 ,
V_39 | V_40 | V_41 ,
0 ,
0 ,
& V_26 ,
sizeof( V_26 ) ,
1000 ) ;
if ( V_27 < 0 ) {
F_21 ( & V_2 -> V_37 -> V_2 ,
L_8 ) ;
V_22 = V_27 ;
goto V_36;
}
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 0 ;
F_22 ( V_2 -> V_14 ,
V_2 -> V_37 ,
F_23 ( V_2 -> V_37 , V_2 -> V_44 -> V_45 ) ,
V_2 -> V_17 ,
F_24 ( V_2 -> V_44 ) ,
V_46 ,
V_2 ,
V_2 -> V_47 ) ;
V_2 -> V_48 = 1 ;
V_2 -> V_49 = 0 ;
F_25 () ;
V_22 = F_26 ( V_2 -> V_14 , V_4 ) ;
if ( V_22 ) {
F_21 ( & V_2 -> V_37 -> V_2 ,
L_9 , V_22 ) ;
V_2 -> V_48 = 0 ;
V_2 -> V_34 = 0 ;
goto V_36;
}
V_20 -> V_50 = V_2 ;
V_36:
F_17 ( & V_2 -> V_32 ) ;
exit:
F_7 ( 2 , L_10 , V_13 , V_22 ) ;
return V_22 ;
}
static int F_27 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_12 * V_2 ;
int V_22 = 0 ;
F_7 ( 2 , L_5 , V_13 ) ;
V_2 = V_20 -> V_50 ;
if ( V_2 == NULL ) {
F_7 ( 1 , L_11 , V_13 ) ;
V_22 = - V_30 ;
goto V_51;
}
F_15 ( & V_31 ) ;
if ( F_18 ( & V_2 -> V_32 ) ) {
V_22 = - V_33 ;
goto exit;
}
if ( V_2 -> V_34 != 1 ) {
F_7 ( 1 , L_12 , V_13 ) ;
V_22 = - V_30 ;
goto V_36;
}
if ( V_2 -> V_37 == NULL ) {
F_17 ( & V_2 -> V_32 ) ;
F_6 ( V_2 ) ;
goto exit;
}
if ( V_2 -> V_52 ) {
F_28 ( V_2 -> V_53 , ! V_2 -> V_52 , 2 * V_54 ) ;
}
F_8 ( V_2 ) ;
V_2 -> V_34 = 0 ;
V_36:
F_17 ( & V_2 -> V_32 ) ;
exit:
F_17 ( & V_31 ) ;
V_51:
F_7 ( 2 , L_13 , V_13 , V_22 ) ;
return V_22 ;
}
static void F_8 ( struct V_12 * V_2 )
{
F_7 ( 2 , L_5 , V_13 ) ;
if ( V_2 == NULL ) {
F_7 ( 1 , L_14 , V_13 ) ;
goto exit;
}
if ( V_2 -> V_48 ) {
V_2 -> V_48 = 0 ;
F_25 () ;
if ( V_2 -> V_37 )
F_29 ( V_2 -> V_14 ) ;
}
if ( V_2 -> V_52 && V_2 -> V_37 )
F_29 ( V_2 -> V_15 ) ;
exit:
F_7 ( 2 , L_6 , V_13 ) ;
}
static void F_30 ( struct V_12 * V_2 )
{
F_31 ( & V_2 -> V_55 ) ;
if ( ! V_56
|| F_32 ( V_57 , V_2 -> V_58 + V_2 -> V_59 )
|| V_2 -> V_42 == V_60 ) {
V_2 -> V_43 = V_2 -> V_42 ;
}
V_2 -> V_49 = 0 ;
F_33 ( & V_2 -> V_55 ) ;
}
static unsigned int F_34 ( struct V_20 * V_20 , T_2 * V_61 )
{
struct V_12 * V_2 ;
unsigned int V_62 = 0 ;
F_7 ( 2 , L_5 , V_13 ) ;
V_2 = V_20 -> V_50 ;
if ( ! V_2 -> V_37 )
return V_63 | V_64 ;
F_35 ( V_20 , & V_2 -> V_65 , V_61 ) ;
F_35 ( V_20 , & V_2 -> V_53 , V_61 ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_43 > 0 ) {
V_62 |= V_66 | V_67 ;
}
if ( ! V_2 -> V_52 ) {
V_62 |= V_68 | V_69 ;
}
F_7 ( 2 , L_15 , V_13 , V_62 ) ;
return V_62 ;
}
static T_3 F_36 ( struct V_20 * V_20 , T_3 V_70 , int V_71 )
{
return - V_72 ;
}
static T_4 F_37 ( struct V_20 * V_20 , char T_5 * V_73 , T_6 V_74 , T_3 * V_75 )
{
struct V_12 * V_2 ;
T_6 V_76 ;
int V_9 ;
int V_22 = 0 ;
unsigned long V_77 = 0 ;
F_7 ( 2 , L_16 , V_13 , V_74 ) ;
V_2 = V_20 -> V_50 ;
if ( F_18 ( & V_2 -> V_32 ) ) {
V_22 = - V_33 ;
goto exit;
}
if ( V_2 -> V_37 == NULL ) {
V_22 = - V_30 ;
F_5 ( V_29 L_17 , V_22 ) ;
goto V_36;
}
if ( V_74 == 0 ) {
F_7 ( 1 , L_18 , V_13 ) ;
goto V_36;
}
if ( V_78 ) {
V_77 = V_57 + V_78 * V_54 / 1000 ;
}
F_30 ( V_2 ) ;
while ( V_2 -> V_43 == 0 ) {
if ( V_20 -> V_79 & V_80 ) {
V_22 = - V_81 ;
goto V_36;
}
V_22 = F_28 ( V_2 -> V_65 , V_2 -> V_49 , V_2 -> V_59 ) ;
if ( V_22 < 0 ) {
goto V_36;
}
if ( V_78
&& ( V_2 -> V_42 || V_2 -> V_52 ) ) {
V_77 = V_57 + V_78 * V_54 / 1000 ;
}
if ( V_78 && F_32 ( V_57 , V_77 ) ) {
V_22 = - V_82 ;
goto V_36;
}
F_30 ( V_2 ) ;
}
V_76 = F_38 ( V_74 , V_2 -> V_43 ) ;
if ( F_39 ( V_73 , V_2 -> V_16 , V_76 ) ) {
V_22 = - V_83 ;
goto V_36;
}
F_31 ( & V_2 -> V_55 ) ;
V_2 -> V_42 -= V_76 ;
V_2 -> V_43 -= V_76 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_42 ; V_9 ++ ) {
V_2 -> V_16 [ V_9 ] = V_2 -> V_16 [ V_9 + V_76 ] ;
}
F_33 ( & V_2 -> V_55 ) ;
V_22 = V_76 ;
V_36:
F_17 ( & V_2 -> V_32 ) ;
exit:
F_7 ( 2 , L_13 , V_13 , V_22 ) ;
return V_22 ;
}
static T_4 F_40 ( struct V_20 * V_20 , const char T_5 * V_73 , T_6 V_74 , T_3 * V_75 )
{
struct V_12 * V_2 ;
T_6 V_84 ;
int V_22 = 0 ;
F_7 ( 2 , L_16 , V_13 , V_74 ) ;
V_2 = V_20 -> V_50 ;
if ( F_18 ( & V_2 -> V_32 ) ) {
V_22 = - V_33 ;
goto exit;
}
if ( V_2 -> V_37 == NULL ) {
V_22 = - V_30 ;
F_5 ( V_29 L_17 , V_22 ) ;
goto V_36;
}
if ( V_74 == 0 ) {
F_7 ( 1 , L_19 , V_13 ) ;
goto V_36;
}
while ( V_2 -> V_52 ) {
if ( V_20 -> V_79 & V_80 ) {
V_22 = - V_81 ;
goto V_36;
}
V_22 = F_41 ( V_2 -> V_53 , ! V_2 -> V_52 ) ;
if ( V_22 ) {
goto V_36;
}
}
V_84 = F_42 ( int , V_74 , V_85 ) ;
F_7 ( 4 , L_20 , V_13 , V_74 , V_84 ) ;
if ( F_43 ( V_2 -> V_18 , V_73 , V_84 ) ) {
V_22 = - V_83 ;
goto V_36;
}
F_22 ( V_2 -> V_15 ,
V_2 -> V_37 ,
F_44 ( V_2 -> V_37 , V_2 -> V_86 -> V_45 ) ,
V_2 -> V_18 ,
V_84 ,
V_87 ,
V_2 ,
V_2 -> V_88 ) ;
V_2 -> V_52 = 1 ;
F_45 () ;
V_22 = F_26 ( V_2 -> V_15 , V_4 ) ;
if ( V_22 ) {
V_2 -> V_52 = 0 ;
F_21 ( & V_2 -> V_37 -> V_2 ,
L_21 , V_22 ) ;
goto V_36;
}
V_22 = V_84 ;
V_36:
F_17 ( & V_2 -> V_32 ) ;
exit:
F_7 ( 2 , L_13 , V_13 , V_22 ) ;
return V_22 ;
}
static void V_46 ( struct V_89 * V_89 )
{
struct V_12 * V_2 = V_89 -> V_90 ;
int V_91 = V_89 -> V_91 ;
int V_22 ;
F_7 ( 4 , L_22 , V_13 , V_91 ) ;
F_4 ( 5 , V_13 , V_89 -> V_92 , V_89 -> V_93 ) ;
if ( V_91 ) {
if ( V_91 == - V_94 ||
V_91 == - V_95 ||
V_91 == - V_96 ) {
goto exit;
} else {
F_7 ( 1 , L_23 , V_13 , V_91 ) ;
goto V_97;
}
}
if ( V_89 -> V_92 > 0 ) {
F_46 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_42 + V_89 -> V_92 < V_60 ) {
memcpy ( V_2 -> V_16 + V_2 -> V_42 ,
V_2 -> V_17 ,
V_89 -> V_92 ) ;
V_2 -> V_42 += V_89 -> V_92 ;
V_2 -> V_58 = V_57 ;
F_7 ( 3 , L_24 , V_13 , V_89 -> V_92 ) ;
} else {
F_5 ( V_98 L_25 , V_13 , V_89 -> V_92 ) ;
}
F_47 ( & V_2 -> V_55 ) ;
}
V_97:
if ( V_2 -> V_48 && V_2 -> V_37 ) {
V_22 = F_26 ( V_2 -> V_14 , V_99 ) ;
if ( V_22 )
F_21 ( & V_2 -> V_37 -> V_2 ,
L_26 ,
V_13 , V_22 ) ;
}
exit:
V_2 -> V_49 = 1 ;
F_48 ( & V_2 -> V_65 ) ;
F_4 ( 5 , V_13 , V_89 -> V_92 , V_89 -> V_93 ) ;
F_7 ( 4 , L_27 , V_13 , V_91 ) ;
}
static void V_87 ( struct V_89 * V_89 )
{
struct V_12 * V_2 = V_89 -> V_90 ;
int V_91 = V_89 -> V_91 ;
F_7 ( 4 , L_22 , V_13 , V_91 ) ;
F_4 ( 5 , V_13 , V_89 -> V_92 , V_89 -> V_93 ) ;
if ( V_91 && ! ( V_91 == - V_94 ||
V_91 == - V_95 ||
V_91 == - V_96 ) ) {
F_7 ( 1 , L_28 ,
V_13 , V_91 ) ;
}
V_2 -> V_52 = 0 ;
F_48 ( & V_2 -> V_53 ) ;
F_4 ( 5 , V_13 , V_89 -> V_92 , V_89 -> V_93 ) ;
F_7 ( 4 , L_27 , V_13 , V_91 ) ;
}
static int F_49 ( struct V_23 * V_24 , const struct V_100 * V_101 )
{
struct V_1 * V_102 = & V_24 -> V_2 ;
struct V_103 * V_37 = F_50 ( V_24 ) ;
struct V_12 * V_2 = NULL ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_108 V_109 ;
int V_9 ;
int V_22 = - V_110 ;
int V_27 ;
F_7 ( 2 , L_5 , V_13 ) ;
V_2 = F_51 ( sizeof( struct V_12 ) , V_4 ) ;
if ( V_2 == NULL ) {
F_21 ( V_102 , L_29 ) ;
goto exit;
}
F_52 ( & V_2 -> V_32 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_34 = 0 ;
V_2 -> V_16 = NULL ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 0 ;
F_53 ( & V_2 -> V_55 ) ;
V_2 -> V_59 = V_56 * V_54 / 1000 ;
V_2 -> V_58 = V_57 ;
F_54 ( & V_2 -> V_65 ) ;
F_54 ( & V_2 -> V_53 ) ;
V_2 -> V_17 = NULL ;
V_2 -> V_44 = NULL ;
V_2 -> V_14 = NULL ;
V_2 -> V_48 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_18 = NULL ;
V_2 -> V_86 = NULL ;
V_2 -> V_15 = NULL ;
V_2 -> V_52 = 0 ;
V_105 = V_24 -> V_111 ;
for ( V_9 = 0 ; V_9 < V_105 -> V_112 . V_113 ; ++ V_9 ) {
V_107 = & V_105 -> V_107 [ V_9 ] . V_112 ;
if ( F_55 ( V_107 ) ) {
if ( F_56 ( V_107 ) )
V_2 -> V_44 = V_107 ;
else
V_2 -> V_86 = V_107 ;
}
}
if( V_2 -> V_44 == NULL ) {
F_21 ( V_102 , L_30 ) ;
goto error;
}
if ( V_2 -> V_86 == NULL ) {
F_21 ( V_102 , L_31 ) ;
goto error;
}
V_2 -> V_16 = F_51 ( V_60 , V_4 ) ;
if ( ! V_2 -> V_16 ) {
F_21 ( V_102 , L_32 ) ;
goto error;
}
V_2 -> V_17 = F_51 ( F_24 ( V_2 -> V_44 ) , V_4 ) ;
if ( ! V_2 -> V_17 ) {
F_21 ( V_102 , L_33 ) ;
goto error;
}
V_2 -> V_14 = F_57 ( 0 , V_4 ) ;
if ( ! V_2 -> V_14 ) {
F_21 ( V_102 , L_34 ) ;
goto error;
}
V_2 -> V_18 = F_51 ( V_85 , V_4 ) ;
if ( ! V_2 -> V_18 ) {
F_21 ( V_102 , L_35 ) ;
goto error;
}
V_2 -> V_15 = F_57 ( 0 , V_4 ) ;
if ( ! V_2 -> V_15 ) {
F_21 ( V_102 , L_36 ) ;
goto error;
}
V_2 -> V_47 = V_47 ? V_47 : V_2 -> V_44 -> V_114 ;
V_2 -> V_88 = V_88 ? V_88 : V_2 -> V_86 -> V_114 ;
F_58 ( V_24 , V_2 ) ;
V_22 = F_59 ( V_24 , & V_115 ) ;
if ( V_22 ) {
F_21 ( V_102 , L_37 ) ;
F_58 ( V_24 , NULL ) ;
goto error;
}
V_2 -> V_116 = V_24 -> V_116 ;
F_60 ( & V_24 -> V_2 , L_38
L_39 , ( V_2 -> V_116 - V_117 ) ,
V_118 , V_2 -> V_116 ) ;
V_27 = F_19 ( V_37 ,
F_20 ( V_37 , 0 ) ,
V_119 ,
V_39 | V_40 | V_41 ,
0 ,
0 ,
& V_109 ,
sizeof( V_109 ) ,
1000 ) ;
if ( V_27 < 0 ) {
F_21 ( V_102 , L_40 ) ;
V_22 = V_27 ;
goto error;
}
F_60 ( & V_24 -> V_2 , L_41
L_42 , V_109 . V_120 ,
V_109 . V_116 ,
F_61 ( V_109 . V_121 ) ) ;
exit:
F_7 ( 2 , L_43 , V_13 , ( long ) V_2 ) ;
return V_22 ;
error:
F_6 ( V_2 ) ;
return V_22 ;
}
static void F_62 ( struct V_23 * V_24 )
{
struct V_12 * V_2 ;
int V_116 ;
F_7 ( 2 , L_5 , V_13 ) ;
V_2 = F_16 ( V_24 ) ;
F_15 ( & V_31 ) ;
F_58 ( V_24 , NULL ) ;
V_116 = V_2 -> V_116 ;
F_63 ( V_24 , & V_115 ) ;
F_15 ( & V_2 -> V_32 ) ;
F_17 ( & V_31 ) ;
if ( ! V_2 -> V_34 ) {
F_17 ( & V_2 -> V_32 ) ;
F_6 ( V_2 ) ;
} else {
V_2 -> V_37 = NULL ;
F_64 ( & V_2 -> V_65 ) ;
F_64 ( & V_2 -> V_53 ) ;
F_17 ( & V_2 -> V_32 ) ;
}
F_60 ( & V_24 -> V_2 , L_44 ,
( V_116 - V_117 ) ) ;
F_7 ( 2 , L_6 , V_13 ) ;
}
