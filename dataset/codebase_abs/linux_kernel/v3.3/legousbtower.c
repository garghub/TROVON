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
F_15 ( L_7 ,
V_13 , V_21 ) ;
V_22 = - V_29 ;
goto exit;
}
F_16 ( & V_30 ) ;
V_2 = F_17 ( V_24 ) ;
if ( ! V_2 ) {
F_18 ( & V_30 ) ;
V_22 = - V_29 ;
goto exit;
}
if ( F_19 ( & V_2 -> V_31 ) ) {
F_18 ( & V_30 ) ;
V_22 = - V_32 ;
goto exit;
}
if ( V_2 -> V_33 ) {
F_18 ( & V_30 ) ;
V_22 = - V_34 ;
goto V_35;
}
V_2 -> V_33 = 1 ;
F_18 ( & V_30 ) ;
V_27 = F_20 ( V_2 -> V_36 ,
F_21 ( V_2 -> V_36 , 0 ) ,
V_37 ,
V_38 | V_39 | V_40 ,
0 ,
0 ,
& V_26 ,
sizeof( V_26 ) ,
1000 ) ;
if ( V_27 < 0 ) {
F_15 ( L_8 ) ;
V_22 = V_27 ;
goto V_35;
}
V_2 -> V_41 = 0 ;
V_2 -> V_42 = 0 ;
F_22 ( V_2 -> V_14 ,
V_2 -> V_36 ,
F_23 ( V_2 -> V_36 , V_2 -> V_43 -> V_44 ) ,
V_2 -> V_17 ,
F_24 ( V_2 -> V_43 ) ,
V_45 ,
V_2 ,
V_2 -> V_46 ) ;
V_2 -> V_47 = 1 ;
V_2 -> V_48 = 0 ;
F_25 () ;
V_22 = F_26 ( V_2 -> V_14 , V_4 ) ;
if ( V_22 ) {
F_15 ( L_9 , V_22 ) ;
V_2 -> V_47 = 0 ;
V_2 -> V_33 = 0 ;
goto V_35;
}
V_20 -> V_49 = V_2 ;
V_35:
F_18 ( & V_2 -> V_31 ) ;
exit:
F_7 ( 2 , L_10 , V_13 , V_22 ) ;
return V_22 ;
}
static int F_27 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_12 * V_2 ;
int V_22 = 0 ;
F_7 ( 2 , L_5 , V_13 ) ;
V_2 = V_20 -> V_49 ;
if ( V_2 == NULL ) {
F_7 ( 1 , L_11 , V_13 ) ;
V_22 = - V_29 ;
goto V_50;
}
F_16 ( & V_30 ) ;
if ( F_19 ( & V_2 -> V_31 ) ) {
V_22 = - V_32 ;
goto exit;
}
if ( V_2 -> V_33 != 1 ) {
F_7 ( 1 , L_12 , V_13 ) ;
V_22 = - V_29 ;
goto V_35;
}
if ( V_2 -> V_36 == NULL ) {
F_18 ( & V_2 -> V_31 ) ;
F_6 ( V_2 ) ;
goto exit;
}
if ( V_2 -> V_51 ) {
F_28 ( V_2 -> V_52 , ! V_2 -> V_51 , 2 * V_53 ) ;
}
F_8 ( V_2 ) ;
V_2 -> V_33 = 0 ;
V_35:
F_18 ( & V_2 -> V_31 ) ;
exit:
F_18 ( & V_30 ) ;
V_50:
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
if ( V_2 -> V_47 ) {
V_2 -> V_47 = 0 ;
F_25 () ;
if ( V_2 -> V_36 )
F_29 ( V_2 -> V_14 ) ;
}
if ( V_2 -> V_51 && V_2 -> V_36 )
F_29 ( V_2 -> V_15 ) ;
exit:
F_7 ( 2 , L_6 , V_13 ) ;
}
static void F_30 ( struct V_12 * V_2 )
{
F_31 ( & V_2 -> V_54 ) ;
if ( ! V_55
|| F_32 ( V_56 , V_2 -> V_57 + V_2 -> V_58 )
|| V_2 -> V_41 == V_59 ) {
V_2 -> V_42 = V_2 -> V_41 ;
}
V_2 -> V_48 = 0 ;
F_33 ( & V_2 -> V_54 ) ;
}
static unsigned int F_34 ( struct V_20 * V_20 , T_2 * V_60 )
{
struct V_12 * V_2 ;
unsigned int V_61 = 0 ;
F_7 ( 2 , L_5 , V_13 ) ;
V_2 = V_20 -> V_49 ;
if ( ! V_2 -> V_36 )
return V_62 | V_63 ;
F_35 ( V_20 , & V_2 -> V_64 , V_60 ) ;
F_35 ( V_20 , & V_2 -> V_52 , V_60 ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_42 > 0 ) {
V_61 |= V_65 | V_66 ;
}
if ( ! V_2 -> V_51 ) {
V_61 |= V_67 | V_68 ;
}
F_7 ( 2 , L_15 , V_13 , V_61 ) ;
return V_61 ;
}
static T_3 F_36 ( struct V_20 * V_20 , T_3 V_69 , int V_70 )
{
return - V_71 ;
}
static T_4 F_37 ( struct V_20 * V_20 , char T_5 * V_72 , T_6 V_73 , T_3 * V_74 )
{
struct V_12 * V_2 ;
T_6 V_75 ;
int V_9 ;
int V_22 = 0 ;
unsigned long V_76 = 0 ;
F_7 ( 2 , L_16 , V_13 , V_73 ) ;
V_2 = V_20 -> V_49 ;
if ( F_19 ( & V_2 -> V_31 ) ) {
V_22 = - V_32 ;
goto exit;
}
if ( V_2 -> V_36 == NULL ) {
V_22 = - V_29 ;
F_15 ( L_17 , V_22 ) ;
goto V_35;
}
if ( V_73 == 0 ) {
F_7 ( 1 , L_18 , V_13 ) ;
goto V_35;
}
if ( V_77 ) {
V_76 = V_56 + V_77 * V_53 / 1000 ;
}
F_30 ( V_2 ) ;
while ( V_2 -> V_42 == 0 ) {
if ( V_20 -> V_78 & V_79 ) {
V_22 = - V_80 ;
goto V_35;
}
V_22 = F_28 ( V_2 -> V_64 , V_2 -> V_48 , V_2 -> V_58 ) ;
if ( V_22 < 0 ) {
goto V_35;
}
if ( V_77
&& ( V_2 -> V_41 || V_2 -> V_51 ) ) {
V_76 = V_56 + V_77 * V_53 / 1000 ;
}
if ( V_77 && F_32 ( V_56 , V_76 ) ) {
V_22 = - V_81 ;
goto V_35;
}
F_30 ( V_2 ) ;
}
V_75 = F_38 ( V_73 , V_2 -> V_42 ) ;
if ( F_39 ( V_72 , V_2 -> V_16 , V_75 ) ) {
V_22 = - V_82 ;
goto V_35;
}
F_31 ( & V_2 -> V_54 ) ;
V_2 -> V_41 -= V_75 ;
V_2 -> V_42 -= V_75 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_41 ; V_9 ++ ) {
V_2 -> V_16 [ V_9 ] = V_2 -> V_16 [ V_9 + V_75 ] ;
}
F_33 ( & V_2 -> V_54 ) ;
V_22 = V_75 ;
V_35:
F_18 ( & V_2 -> V_31 ) ;
exit:
F_7 ( 2 , L_13 , V_13 , V_22 ) ;
return V_22 ;
}
static T_4 F_40 ( struct V_20 * V_20 , const char T_5 * V_72 , T_6 V_73 , T_3 * V_74 )
{
struct V_12 * V_2 ;
T_6 V_83 ;
int V_22 = 0 ;
F_7 ( 2 , L_16 , V_13 , V_73 ) ;
V_2 = V_20 -> V_49 ;
if ( F_19 ( & V_2 -> V_31 ) ) {
V_22 = - V_32 ;
goto exit;
}
if ( V_2 -> V_36 == NULL ) {
V_22 = - V_29 ;
F_15 ( L_17 , V_22 ) ;
goto V_35;
}
if ( V_73 == 0 ) {
F_7 ( 1 , L_19 , V_13 ) ;
goto V_35;
}
while ( V_2 -> V_51 ) {
if ( V_20 -> V_78 & V_79 ) {
V_22 = - V_80 ;
goto V_35;
}
V_22 = F_41 ( V_2 -> V_52 , ! V_2 -> V_51 ) ;
if ( V_22 ) {
goto V_35;
}
}
V_83 = F_42 ( int , V_73 , V_84 ) ;
F_7 ( 4 , L_20 , V_13 , V_73 , V_83 ) ;
if ( F_43 ( V_2 -> V_18 , V_72 , V_83 ) ) {
V_22 = - V_82 ;
goto V_35;
}
F_22 ( V_2 -> V_15 ,
V_2 -> V_36 ,
F_44 ( V_2 -> V_36 , V_2 -> V_85 -> V_44 ) ,
V_2 -> V_18 ,
V_83 ,
V_86 ,
V_2 ,
V_2 -> V_87 ) ;
V_2 -> V_51 = 1 ;
F_45 () ;
V_22 = F_26 ( V_2 -> V_15 , V_4 ) ;
if ( V_22 ) {
V_2 -> V_51 = 0 ;
F_15 ( L_21 , V_22 ) ;
goto V_35;
}
V_22 = V_83 ;
V_35:
F_18 ( & V_2 -> V_31 ) ;
exit:
F_7 ( 2 , L_13 , V_13 , V_22 ) ;
return V_22 ;
}
static void V_45 ( struct V_88 * V_88 )
{
struct V_12 * V_2 = V_88 -> V_89 ;
int V_90 = V_88 -> V_90 ;
int V_22 ;
F_7 ( 4 , L_22 , V_13 , V_90 ) ;
F_4 ( 5 , V_13 , V_88 -> V_91 , V_88 -> V_92 ) ;
if ( V_90 ) {
if ( V_90 == - V_93 ||
V_90 == - V_94 ||
V_90 == - V_95 ) {
goto exit;
} else {
F_7 ( 1 , L_23 , V_13 , V_90 ) ;
goto V_96;
}
}
if ( V_88 -> V_91 > 0 ) {
F_46 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_41 + V_88 -> V_91 < V_59 ) {
memcpy ( V_2 -> V_16 + V_2 -> V_41 ,
V_2 -> V_17 ,
V_88 -> V_91 ) ;
V_2 -> V_41 += V_88 -> V_91 ;
V_2 -> V_57 = V_56 ;
F_7 ( 3 , L_24 , V_13 , V_88 -> V_91 ) ;
} else {
F_5 ( V_97 L_25 , V_13 , V_88 -> V_91 ) ;
}
F_47 ( & V_2 -> V_54 ) ;
}
V_96:
if ( V_2 -> V_47 && V_2 -> V_36 ) {
V_22 = F_26 ( V_2 -> V_14 , V_98 ) ;
if ( V_22 ) {
F_15 ( L_26 , V_13 , V_22 ) ;
}
}
exit:
V_2 -> V_48 = 1 ;
F_48 ( & V_2 -> V_64 ) ;
F_4 ( 5 , V_13 , V_88 -> V_91 , V_88 -> V_92 ) ;
F_7 ( 4 , L_27 , V_13 , V_90 ) ;
}
static void V_86 ( struct V_88 * V_88 )
{
struct V_12 * V_2 = V_88 -> V_89 ;
int V_90 = V_88 -> V_90 ;
F_7 ( 4 , L_22 , V_13 , V_90 ) ;
F_4 ( 5 , V_13 , V_88 -> V_91 , V_88 -> V_92 ) ;
if ( V_90 && ! ( V_90 == - V_93 ||
V_90 == - V_94 ||
V_90 == - V_95 ) ) {
F_7 ( 1 , L_28 ,
V_13 , V_90 ) ;
}
V_2 -> V_51 = 0 ;
F_48 ( & V_2 -> V_52 ) ;
F_4 ( 5 , V_13 , V_88 -> V_91 , V_88 -> V_92 ) ;
F_7 ( 4 , L_27 , V_13 , V_90 ) ;
}
static int F_49 ( struct V_23 * V_24 , const struct V_99 * V_100 )
{
struct V_101 * V_36 = F_50 ( V_24 ) ;
struct V_12 * V_2 = NULL ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_106 V_107 ;
int V_9 ;
int V_22 = - V_108 ;
int V_27 ;
F_7 ( 2 , L_5 , V_13 ) ;
if ( V_36 == NULL )
F_51 ( & V_24 -> V_2 , L_29 ) ;
V_2 = F_52 ( sizeof( struct V_12 ) , V_4 ) ;
if ( V_2 == NULL ) {
F_15 ( L_30 ) ;
goto exit;
}
F_53 ( & V_2 -> V_31 ) ;
V_2 -> V_36 = V_36 ;
V_2 -> V_33 = 0 ;
V_2 -> V_16 = NULL ;
V_2 -> V_41 = 0 ;
V_2 -> V_42 = 0 ;
F_54 ( & V_2 -> V_54 ) ;
V_2 -> V_58 = V_55 * V_53 / 1000 ;
V_2 -> V_57 = V_56 ;
F_55 ( & V_2 -> V_64 ) ;
F_55 ( & V_2 -> V_52 ) ;
V_2 -> V_17 = NULL ;
V_2 -> V_43 = NULL ;
V_2 -> V_14 = NULL ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_18 = NULL ;
V_2 -> V_85 = NULL ;
V_2 -> V_15 = NULL ;
V_2 -> V_51 = 0 ;
V_103 = V_24 -> V_109 ;
for ( V_9 = 0 ; V_9 < V_103 -> V_110 . V_111 ; ++ V_9 ) {
V_105 = & V_103 -> V_105 [ V_9 ] . V_110 ;
if ( F_56 ( V_105 ) ) {
if ( F_57 ( V_105 ) )
V_2 -> V_43 = V_105 ;
else
V_2 -> V_85 = V_105 ;
}
}
if( V_2 -> V_43 == NULL ) {
F_15 ( L_31 ) ;
goto error;
}
if ( V_2 -> V_85 == NULL ) {
F_15 ( L_32 ) ;
goto error;
}
V_2 -> V_16 = F_52 ( V_59 , V_4 ) ;
if ( ! V_2 -> V_16 ) {
F_15 ( L_33 ) ;
goto error;
}
V_2 -> V_17 = F_52 ( F_24 ( V_2 -> V_43 ) , V_4 ) ;
if ( ! V_2 -> V_17 ) {
F_15 ( L_34 ) ;
goto error;
}
V_2 -> V_14 = F_58 ( 0 , V_4 ) ;
if ( ! V_2 -> V_14 ) {
F_15 ( L_35 ) ;
goto error;
}
V_2 -> V_18 = F_52 ( V_84 , V_4 ) ;
if ( ! V_2 -> V_18 ) {
F_15 ( L_36 ) ;
goto error;
}
V_2 -> V_15 = F_58 ( 0 , V_4 ) ;
if ( ! V_2 -> V_15 ) {
F_15 ( L_37 ) ;
goto error;
}
V_2 -> V_46 = V_46 ? V_46 : V_2 -> V_43 -> V_112 ;
V_2 -> V_87 = V_87 ? V_87 : V_2 -> V_85 -> V_112 ;
F_59 ( V_24 , V_2 ) ;
V_22 = F_60 ( V_24 , & V_113 ) ;
if ( V_22 ) {
F_15 ( L_38 ) ;
F_59 ( V_24 , NULL ) ;
goto error;
}
V_2 -> V_114 = V_24 -> V_114 ;
F_51 ( & V_24 -> V_2 , L_39
L_40 , ( V_2 -> V_114 - V_115 ) ,
V_116 , V_2 -> V_114 ) ;
V_27 = F_20 ( V_36 ,
F_21 ( V_36 , 0 ) ,
V_117 ,
V_38 | V_39 | V_40 ,
0 ,
0 ,
& V_107 ,
sizeof( V_107 ) ,
1000 ) ;
if ( V_27 < 0 ) {
F_15 ( L_41 ) ;
V_22 = V_27 ;
goto error;
}
F_51 ( & V_24 -> V_2 , L_42
L_43 , V_107 . V_118 ,
V_107 . V_114 ,
F_61 ( V_107 . V_119 ) ) ;
exit:
F_7 ( 2 , L_44 , V_13 , ( long ) V_2 ) ;
return V_22 ;
error:
F_6 ( V_2 ) ;
return V_22 ;
}
static void F_62 ( struct V_23 * V_24 )
{
struct V_12 * V_2 ;
int V_114 ;
F_7 ( 2 , L_5 , V_13 ) ;
V_2 = F_17 ( V_24 ) ;
F_16 ( & V_30 ) ;
F_59 ( V_24 , NULL ) ;
V_114 = V_2 -> V_114 ;
F_63 ( V_24 , & V_113 ) ;
F_16 ( & V_2 -> V_31 ) ;
F_18 ( & V_30 ) ;
if ( ! V_2 -> V_33 ) {
F_18 ( & V_2 -> V_31 ) ;
F_6 ( V_2 ) ;
} else {
V_2 -> V_36 = NULL ;
F_64 ( & V_2 -> V_64 ) ;
F_64 ( & V_2 -> V_52 ) ;
F_18 ( & V_2 -> V_31 ) ;
}
F_51 ( & V_24 -> V_2 , L_45 ,
( V_114 - V_115 ) ) ;
F_7 ( 2 , L_6 , V_13 ) ;
}
