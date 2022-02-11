static char * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
return F_2 ( V_4 , L_1 , F_3 ( V_2 ) ) ;
}
static inline void F_4 ( struct V_1 * V_2 ,
const char * V_5 , int V_6 ,
const unsigned char * V_7 )
{
F_5 ( V_2 , L_2 ,
V_5 , V_6 , V_6 , V_7 ) ;
}
static inline void F_6 ( struct V_8 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 -> V_9 ) ;
F_8 ( V_2 -> V_10 ) ;
F_9 ( V_2 -> V_11 ) ;
F_9 ( V_2 -> V_12 ) ;
F_9 ( V_2 -> V_13 ) ;
F_9 ( V_2 ) ;
}
static int F_10 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
struct V_8 * V_2 = NULL ;
int V_16 ;
int V_17 = 0 ;
struct V_18 * V_19 ;
struct V_20 V_21 ;
int V_22 ;
F_11 ( V_14 , V_15 ) ;
V_16 = F_12 ( V_14 ) ;
V_19 = F_13 ( & V_23 , V_16 ) ;
if ( ! V_19 ) {
F_14 ( L_3 , V_16 ) ;
V_17 = - V_24 ;
goto exit;
}
F_15 ( & V_25 ) ;
V_2 = F_16 ( V_19 ) ;
if ( ! V_2 ) {
F_17 ( & V_25 ) ;
V_17 = - V_24 ;
goto exit;
}
if ( F_18 ( & V_2 -> V_26 ) ) {
F_17 ( & V_25 ) ;
V_17 = - V_27 ;
goto exit;
}
if ( V_2 -> V_28 ) {
F_17 ( & V_25 ) ;
V_17 = - V_29 ;
goto V_30;
}
V_2 -> V_28 = 1 ;
F_17 ( & V_25 ) ;
V_22 = F_19 ( V_2 -> V_31 ,
F_20 ( V_2 -> V_31 , 0 ) ,
V_32 ,
V_33 | V_34 | V_35 ,
0 ,
0 ,
& V_21 ,
sizeof( V_21 ) ,
1000 ) ;
if ( V_22 < 0 ) {
F_21 ( & V_2 -> V_31 -> V_2 ,
L_4 ) ;
V_17 = V_22 ;
goto V_30;
}
V_2 -> V_36 = 0 ;
V_2 -> V_37 = 0 ;
F_22 ( V_2 -> V_9 ,
V_2 -> V_31 ,
F_23 ( V_2 -> V_31 , V_2 -> V_38 -> V_39 ) ,
V_2 -> V_12 ,
F_24 ( V_2 -> V_38 ) ,
V_40 ,
V_2 ,
V_2 -> V_41 ) ;
V_2 -> V_42 = 1 ;
V_2 -> V_43 = 0 ;
F_25 () ;
V_17 = F_26 ( V_2 -> V_9 , V_4 ) ;
if ( V_17 ) {
F_21 ( & V_2 -> V_31 -> V_2 ,
L_5 , V_17 ) ;
V_2 -> V_42 = 0 ;
V_2 -> V_28 = 0 ;
goto V_30;
}
V_15 -> V_44 = V_2 ;
V_30:
F_17 ( & V_2 -> V_26 ) ;
exit:
return V_17 ;
}
static int F_27 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
struct V_8 * V_2 ;
int V_17 = 0 ;
V_2 = V_15 -> V_44 ;
if ( V_2 == NULL ) {
V_17 = - V_24 ;
goto V_45;
}
F_15 ( & V_25 ) ;
if ( F_18 ( & V_2 -> V_26 ) ) {
V_17 = - V_27 ;
goto exit;
}
if ( V_2 -> V_28 != 1 ) {
F_5 ( & V_2 -> V_31 -> V_2 , L_6 ,
V_46 ) ;
V_17 = - V_24 ;
goto V_30;
}
if ( V_2 -> V_31 == NULL ) {
F_17 ( & V_2 -> V_26 ) ;
F_6 ( V_2 ) ;
goto exit;
}
if ( V_2 -> V_47 ) {
F_28 ( V_2 -> V_48 , ! V_2 -> V_47 , 2 * V_49 ) ;
}
F_7 ( V_2 ) ;
V_2 -> V_28 = 0 ;
V_30:
F_17 ( & V_2 -> V_26 ) ;
exit:
F_17 ( & V_25 ) ;
V_45:
return V_17 ;
}
static void F_7 ( struct V_8 * V_2 )
{
if ( V_2 == NULL )
return;
if ( V_2 -> V_42 ) {
V_2 -> V_42 = 0 ;
F_25 () ;
if ( V_2 -> V_31 )
F_29 ( V_2 -> V_9 ) ;
}
if ( V_2 -> V_47 && V_2 -> V_31 )
F_29 ( V_2 -> V_10 ) ;
}
static void F_30 ( struct V_8 * V_2 )
{
F_31 ( & V_2 -> V_50 ) ;
if ( ! V_51
|| F_32 ( V_52 , V_2 -> V_53 + V_2 -> V_54 )
|| V_2 -> V_36 == V_55 ) {
V_2 -> V_37 = V_2 -> V_36 ;
}
V_2 -> V_43 = 0 ;
F_33 ( & V_2 -> V_50 ) ;
}
static unsigned int F_34 ( struct V_15 * V_15 , T_2 * V_56 )
{
struct V_8 * V_2 ;
unsigned int V_57 = 0 ;
V_2 = V_15 -> V_44 ;
if ( ! V_2 -> V_31 )
return V_58 | V_59 ;
F_35 ( V_15 , & V_2 -> V_60 , V_56 ) ;
F_35 ( V_15 , & V_2 -> V_48 , V_56 ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_37 > 0 ) {
V_57 |= V_61 | V_62 ;
}
if ( ! V_2 -> V_47 ) {
V_57 |= V_63 | V_64 ;
}
return V_57 ;
}
static T_3 F_36 ( struct V_15 * V_15 , T_3 V_65 , int V_66 )
{
return - V_67 ;
}
static T_4 F_37 ( struct V_15 * V_15 , char T_5 * V_68 , T_6 V_69 , T_3 * V_70 )
{
struct V_8 * V_2 ;
T_6 V_71 ;
int V_72 ;
int V_17 = 0 ;
unsigned long V_73 = 0 ;
V_2 = V_15 -> V_44 ;
if ( F_18 ( & V_2 -> V_26 ) ) {
V_17 = - V_27 ;
goto exit;
}
if ( V_2 -> V_31 == NULL ) {
V_17 = - V_24 ;
F_14 ( L_7 , V_17 ) ;
goto V_30;
}
if ( V_69 == 0 ) {
F_5 ( & V_2 -> V_31 -> V_2 , L_8 ) ;
goto V_30;
}
if ( V_74 ) {
V_73 = V_52 + V_74 * V_49 / 1000 ;
}
F_30 ( V_2 ) ;
while ( V_2 -> V_37 == 0 ) {
if ( V_15 -> V_75 & V_76 ) {
V_17 = - V_77 ;
goto V_30;
}
V_17 = F_28 ( V_2 -> V_60 , V_2 -> V_43 , V_2 -> V_54 ) ;
if ( V_17 < 0 ) {
goto V_30;
}
if ( V_74
&& ( V_2 -> V_36 || V_2 -> V_47 ) ) {
V_73 = V_52 + V_74 * V_49 / 1000 ;
}
if ( V_74 && F_32 ( V_52 , V_73 ) ) {
V_17 = - V_78 ;
goto V_30;
}
F_30 ( V_2 ) ;
}
V_71 = F_38 ( V_69 , V_2 -> V_37 ) ;
if ( F_39 ( V_68 , V_2 -> V_11 , V_71 ) ) {
V_17 = - V_79 ;
goto V_30;
}
F_31 ( & V_2 -> V_50 ) ;
V_2 -> V_36 -= V_71 ;
V_2 -> V_37 -= V_71 ;
for ( V_72 = 0 ; V_72 < V_2 -> V_36 ; V_72 ++ ) {
V_2 -> V_11 [ V_72 ] = V_2 -> V_11 [ V_72 + V_71 ] ;
}
F_33 ( & V_2 -> V_50 ) ;
V_17 = V_71 ;
V_30:
F_17 ( & V_2 -> V_26 ) ;
exit:
return V_17 ;
}
static T_4 F_40 ( struct V_15 * V_15 , const char T_5 * V_68 , T_6 V_69 , T_3 * V_70 )
{
struct V_8 * V_2 ;
T_6 V_80 ;
int V_17 = 0 ;
V_2 = V_15 -> V_44 ;
if ( F_18 ( & V_2 -> V_26 ) ) {
V_17 = - V_27 ;
goto exit;
}
if ( V_2 -> V_31 == NULL ) {
V_17 = - V_24 ;
F_14 ( L_7 , V_17 ) ;
goto V_30;
}
if ( V_69 == 0 ) {
F_5 ( & V_2 -> V_31 -> V_2 , L_9 ) ;
goto V_30;
}
while ( V_2 -> V_47 ) {
if ( V_15 -> V_75 & V_76 ) {
V_17 = - V_77 ;
goto V_30;
}
V_17 = F_41 ( V_2 -> V_48 , ! V_2 -> V_47 ) ;
if ( V_17 ) {
goto V_30;
}
}
V_80 = F_42 ( int , V_69 , V_81 ) ;
F_5 ( & V_2 -> V_31 -> V_2 , L_10 ,
V_46 , V_69 , V_80 ) ;
if ( F_43 ( V_2 -> V_13 , V_68 , V_80 ) ) {
V_17 = - V_79 ;
goto V_30;
}
F_22 ( V_2 -> V_10 ,
V_2 -> V_31 ,
F_44 ( V_2 -> V_31 , V_2 -> V_82 -> V_39 ) ,
V_2 -> V_13 ,
V_80 ,
V_83 ,
V_2 ,
V_2 -> V_84 ) ;
V_2 -> V_47 = 1 ;
F_45 () ;
V_17 = F_26 ( V_2 -> V_10 , V_4 ) ;
if ( V_17 ) {
V_2 -> V_47 = 0 ;
F_21 ( & V_2 -> V_31 -> V_2 ,
L_11 , V_17 ) ;
goto V_30;
}
V_17 = V_80 ;
V_30:
F_17 ( & V_2 -> V_26 ) ;
exit:
return V_17 ;
}
static void V_40 ( struct V_85 * V_85 )
{
struct V_8 * V_2 = V_85 -> V_86 ;
int V_87 = V_85 -> V_87 ;
int V_17 ;
F_4 ( & V_2 -> V_31 -> V_2 , V_46 ,
V_85 -> V_88 , V_85 -> V_89 ) ;
if ( V_87 ) {
if ( V_87 == - V_90 ||
V_87 == - V_91 ||
V_87 == - V_92 ) {
goto exit;
} else {
F_5 ( & V_2 -> V_31 -> V_2 ,
L_12 , V_46 ,
V_87 ) ;
goto V_93;
}
}
if ( V_85 -> V_88 > 0 ) {
F_46 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_36 + V_85 -> V_88 < V_55 ) {
memcpy ( V_2 -> V_11 + V_2 -> V_36 ,
V_2 -> V_12 ,
V_85 -> V_88 ) ;
V_2 -> V_36 += V_85 -> V_88 ;
V_2 -> V_53 = V_52 ;
F_5 ( & V_2 -> V_31 -> V_2 , L_13 ,
V_46 , V_85 -> V_88 ) ;
} else {
F_47 ( L_14 ,
V_85 -> V_88 ) ;
}
F_48 ( & V_2 -> V_50 ) ;
}
V_93:
if ( V_2 -> V_42 && V_2 -> V_31 ) {
V_17 = F_26 ( V_2 -> V_9 , V_94 ) ;
if ( V_17 )
F_21 ( & V_2 -> V_31 -> V_2 ,
L_15 ,
V_46 , V_17 ) ;
}
exit:
V_2 -> V_43 = 1 ;
F_49 ( & V_2 -> V_60 ) ;
}
static void V_83 ( struct V_85 * V_85 )
{
struct V_8 * V_2 = V_85 -> V_86 ;
int V_87 = V_85 -> V_87 ;
F_4 ( & V_2 -> V_31 -> V_2 , V_46 ,
V_85 -> V_88 , V_85 -> V_89 ) ;
if ( V_87 && ! ( V_87 == - V_90 ||
V_87 == - V_91 ||
V_87 == - V_92 ) ) {
F_5 ( & V_2 -> V_31 -> V_2 ,
L_16 , V_46 ,
V_87 ) ;
}
V_2 -> V_47 = 0 ;
F_49 ( & V_2 -> V_48 ) ;
}
static int F_50 ( struct V_18 * V_19 , const struct V_95 * V_96 )
{
struct V_1 * V_97 = & V_19 -> V_2 ;
struct V_98 * V_31 = F_51 ( V_19 ) ;
struct V_8 * V_2 = NULL ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_103 V_104 ;
int V_72 ;
int V_17 = - V_105 ;
int V_22 ;
V_2 = F_52 ( sizeof( struct V_8 ) , V_4 ) ;
if ( V_2 == NULL ) {
F_21 ( V_97 , L_17 ) ;
goto exit;
}
F_53 ( & V_2 -> V_26 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_28 = 0 ;
V_2 -> V_11 = NULL ;
V_2 -> V_36 = 0 ;
V_2 -> V_37 = 0 ;
F_54 ( & V_2 -> V_50 ) ;
V_2 -> V_54 = V_51 * V_49 / 1000 ;
V_2 -> V_53 = V_52 ;
F_55 ( & V_2 -> V_60 ) ;
F_55 ( & V_2 -> V_48 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_38 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_13 = NULL ;
V_2 -> V_82 = NULL ;
V_2 -> V_10 = NULL ;
V_2 -> V_47 = 0 ;
V_100 = V_19 -> V_106 ;
for ( V_72 = 0 ; V_72 < V_100 -> V_107 . V_108 ; ++ V_72 ) {
V_102 = & V_100 -> V_102 [ V_72 ] . V_107 ;
if ( F_56 ( V_102 ) ) {
if ( F_57 ( V_102 ) )
V_2 -> V_38 = V_102 ;
else
V_2 -> V_82 = V_102 ;
}
}
if( V_2 -> V_38 == NULL ) {
F_21 ( V_97 , L_18 ) ;
goto error;
}
if ( V_2 -> V_82 == NULL ) {
F_21 ( V_97 , L_19 ) ;
goto error;
}
V_2 -> V_11 = F_52 ( V_55 , V_4 ) ;
if ( ! V_2 -> V_11 ) {
F_21 ( V_97 , L_20 ) ;
goto error;
}
V_2 -> V_12 = F_52 ( F_24 ( V_2 -> V_38 ) , V_4 ) ;
if ( ! V_2 -> V_12 ) {
F_21 ( V_97 , L_21 ) ;
goto error;
}
V_2 -> V_9 = F_58 ( 0 , V_4 ) ;
if ( ! V_2 -> V_9 ) {
F_21 ( V_97 , L_22 ) ;
goto error;
}
V_2 -> V_13 = F_52 ( V_81 , V_4 ) ;
if ( ! V_2 -> V_13 ) {
F_21 ( V_97 , L_23 ) ;
goto error;
}
V_2 -> V_10 = F_58 ( 0 , V_4 ) ;
if ( ! V_2 -> V_10 ) {
F_21 ( V_97 , L_24 ) ;
goto error;
}
V_2 -> V_41 = V_41 ? V_41 : V_2 -> V_38 -> V_109 ;
V_2 -> V_84 = V_84 ? V_84 : V_2 -> V_82 -> V_109 ;
F_59 ( V_19 , V_2 ) ;
V_17 = F_60 ( V_19 , & V_110 ) ;
if ( V_17 ) {
F_21 ( V_97 , L_25 ) ;
F_59 ( V_19 , NULL ) ;
goto error;
}
V_2 -> V_111 = V_19 -> V_111 ;
F_61 ( & V_19 -> V_2 , L_26
L_27 , ( V_2 -> V_111 - V_112 ) ,
V_113 , V_2 -> V_111 ) ;
V_22 = F_19 ( V_31 ,
F_20 ( V_31 , 0 ) ,
V_114 ,
V_33 | V_34 | V_35 ,
0 ,
0 ,
& V_104 ,
sizeof( V_104 ) ,
1000 ) ;
if ( V_22 < 0 ) {
F_21 ( V_97 , L_28 ) ;
V_17 = V_22 ;
goto error;
}
F_61 ( & V_19 -> V_2 , L_29
L_30 , V_104 . V_115 ,
V_104 . V_111 ,
F_62 ( V_104 . V_116 ) ) ;
exit:
return V_17 ;
error:
F_6 ( V_2 ) ;
return V_17 ;
}
static void F_63 ( struct V_18 * V_19 )
{
struct V_8 * V_2 ;
int V_111 ;
V_2 = F_16 ( V_19 ) ;
F_15 ( & V_25 ) ;
F_59 ( V_19 , NULL ) ;
V_111 = V_2 -> V_111 ;
F_64 ( V_19 , & V_110 ) ;
F_15 ( & V_2 -> V_26 ) ;
F_17 ( & V_25 ) ;
if ( ! V_2 -> V_28 ) {
F_17 ( & V_2 -> V_26 ) ;
F_6 ( V_2 ) ;
} else {
V_2 -> V_31 = NULL ;
F_65 ( & V_2 -> V_60 ) ;
F_65 ( & V_2 -> V_48 ) ;
F_17 ( & V_2 -> V_26 ) ;
}
F_61 ( & V_19 -> V_2 , L_31 ,
( V_111 - V_112 ) ) ;
}
