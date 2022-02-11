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
struct V_20 * V_21 ;
int V_22 ;
V_21 = F_11 ( sizeof( * V_21 ) , V_4 ) ;
if ( ! V_21 ) {
V_17 = - V_23 ;
goto exit;
}
F_12 ( V_14 , V_15 ) ;
V_16 = F_13 ( V_14 ) ;
V_19 = F_14 ( & V_24 , V_16 ) ;
if ( ! V_19 ) {
F_15 ( L_3 , V_16 ) ;
V_17 = - V_25 ;
goto exit;
}
F_16 ( & V_26 ) ;
V_2 = F_17 ( V_19 ) ;
if ( ! V_2 ) {
F_18 ( & V_26 ) ;
V_17 = - V_25 ;
goto exit;
}
if ( F_19 ( & V_2 -> V_27 ) ) {
F_18 ( & V_26 ) ;
V_17 = - V_28 ;
goto exit;
}
if ( V_2 -> V_29 ) {
F_18 ( & V_26 ) ;
V_17 = - V_30 ;
goto V_31;
}
V_2 -> V_29 = 1 ;
F_18 ( & V_26 ) ;
V_22 = F_20 ( V_2 -> V_32 ,
F_21 ( V_2 -> V_32 , 0 ) ,
V_33 ,
V_34 | V_35 | V_36 ,
0 ,
0 ,
V_21 ,
sizeof( * V_21 ) ,
1000 ) ;
if ( V_22 < 0 ) {
F_22 ( & V_2 -> V_32 -> V_2 ,
L_4 ) ;
V_17 = V_22 ;
goto V_31;
}
V_2 -> V_37 = 0 ;
V_2 -> V_38 = 0 ;
F_23 ( V_2 -> V_9 ,
V_2 -> V_32 ,
F_24 ( V_2 -> V_32 , V_2 -> V_39 -> V_40 ) ,
V_2 -> V_12 ,
F_25 ( V_2 -> V_39 ) ,
V_41 ,
V_2 ,
V_2 -> V_42 ) ;
V_2 -> V_43 = 1 ;
V_2 -> V_44 = 0 ;
F_26 () ;
V_17 = F_27 ( V_2 -> V_9 , V_4 ) ;
if ( V_17 ) {
F_22 ( & V_2 -> V_32 -> V_2 ,
L_5 , V_17 ) ;
V_2 -> V_43 = 0 ;
V_2 -> V_29 = 0 ;
goto V_31;
}
V_15 -> V_45 = V_2 ;
V_31:
F_18 ( & V_2 -> V_27 ) ;
exit:
F_9 ( V_21 ) ;
return V_17 ;
}
static int F_28 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
struct V_8 * V_2 ;
int V_17 = 0 ;
V_2 = V_15 -> V_45 ;
if ( V_2 == NULL ) {
V_17 = - V_25 ;
goto V_46;
}
F_16 ( & V_26 ) ;
if ( F_19 ( & V_2 -> V_27 ) ) {
V_17 = - V_28 ;
goto exit;
}
if ( V_2 -> V_29 != 1 ) {
F_5 ( & V_2 -> V_32 -> V_2 , L_6 ,
V_47 ) ;
V_17 = - V_25 ;
goto V_31;
}
if ( V_2 -> V_32 == NULL ) {
F_18 ( & V_2 -> V_27 ) ;
F_6 ( V_2 ) ;
goto exit;
}
if ( V_2 -> V_48 ) {
F_29 ( V_2 -> V_49 , ! V_2 -> V_48 , 2 * V_50 ) ;
}
F_7 ( V_2 ) ;
V_2 -> V_29 = 0 ;
V_31:
F_18 ( & V_2 -> V_27 ) ;
exit:
F_18 ( & V_26 ) ;
V_46:
return V_17 ;
}
static void F_7 ( struct V_8 * V_2 )
{
if ( V_2 == NULL )
return;
if ( V_2 -> V_43 ) {
V_2 -> V_43 = 0 ;
F_26 () ;
if ( V_2 -> V_32 )
F_30 ( V_2 -> V_9 ) ;
}
if ( V_2 -> V_48 && V_2 -> V_32 )
F_30 ( V_2 -> V_10 ) ;
}
static void F_31 ( struct V_8 * V_2 )
{
F_32 ( & V_2 -> V_51 ) ;
if ( ! V_52
|| F_33 ( V_53 , V_2 -> V_54 + V_2 -> V_55 )
|| V_2 -> V_37 == V_56 ) {
V_2 -> V_38 = V_2 -> V_37 ;
}
V_2 -> V_44 = 0 ;
F_34 ( & V_2 -> V_51 ) ;
}
static unsigned int F_35 ( struct V_15 * V_15 , T_2 * V_57 )
{
struct V_8 * V_2 ;
unsigned int V_58 = 0 ;
V_2 = V_15 -> V_45 ;
if ( ! V_2 -> V_32 )
return V_59 | V_60 ;
F_36 ( V_15 , & V_2 -> V_61 , V_57 ) ;
F_36 ( V_15 , & V_2 -> V_49 , V_57 ) ;
F_31 ( V_2 ) ;
if ( V_2 -> V_38 > 0 ) {
V_58 |= V_62 | V_63 ;
}
if ( ! V_2 -> V_48 ) {
V_58 |= V_64 | V_65 ;
}
return V_58 ;
}
static T_3 F_37 ( struct V_15 * V_15 , T_3 V_66 , int V_67 )
{
return - V_68 ;
}
static T_4 F_38 ( struct V_15 * V_15 , char T_5 * V_69 , T_6 V_70 , T_3 * V_71 )
{
struct V_8 * V_2 ;
T_6 V_72 ;
int V_73 ;
int V_17 = 0 ;
unsigned long V_74 = 0 ;
V_2 = V_15 -> V_45 ;
if ( F_19 ( & V_2 -> V_27 ) ) {
V_17 = - V_28 ;
goto exit;
}
if ( V_2 -> V_32 == NULL ) {
V_17 = - V_25 ;
F_15 ( L_7 , V_17 ) ;
goto V_31;
}
if ( V_70 == 0 ) {
F_5 ( & V_2 -> V_32 -> V_2 , L_8 ) ;
goto V_31;
}
if ( V_75 ) {
V_74 = V_53 + F_39 ( V_75 ) ;
}
F_31 ( V_2 ) ;
while ( V_2 -> V_38 == 0 ) {
if ( V_15 -> V_76 & V_77 ) {
V_17 = - V_78 ;
goto V_31;
}
V_17 = F_29 ( V_2 -> V_61 , V_2 -> V_44 , V_2 -> V_55 ) ;
if ( V_17 < 0 ) {
goto V_31;
}
if ( V_75
&& ( V_2 -> V_37 || V_2 -> V_48 ) ) {
V_74 = V_53 + F_39 ( V_75 ) ;
}
if ( V_75 && F_33 ( V_53 , V_74 ) ) {
V_17 = - V_79 ;
goto V_31;
}
F_31 ( V_2 ) ;
}
V_72 = F_40 ( V_70 , V_2 -> V_38 ) ;
if ( F_41 ( V_69 , V_2 -> V_11 , V_72 ) ) {
V_17 = - V_80 ;
goto V_31;
}
F_32 ( & V_2 -> V_51 ) ;
V_2 -> V_37 -= V_72 ;
V_2 -> V_38 -= V_72 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_37 ; V_73 ++ ) {
V_2 -> V_11 [ V_73 ] = V_2 -> V_11 [ V_73 + V_72 ] ;
}
F_34 ( & V_2 -> V_51 ) ;
V_17 = V_72 ;
V_31:
F_18 ( & V_2 -> V_27 ) ;
exit:
return V_17 ;
}
static T_4 F_42 ( struct V_15 * V_15 , const char T_5 * V_69 , T_6 V_70 , T_3 * V_71 )
{
struct V_8 * V_2 ;
T_6 V_81 ;
int V_17 = 0 ;
V_2 = V_15 -> V_45 ;
if ( F_19 ( & V_2 -> V_27 ) ) {
V_17 = - V_28 ;
goto exit;
}
if ( V_2 -> V_32 == NULL ) {
V_17 = - V_25 ;
F_15 ( L_7 , V_17 ) ;
goto V_31;
}
if ( V_70 == 0 ) {
F_5 ( & V_2 -> V_32 -> V_2 , L_9 ) ;
goto V_31;
}
while ( V_2 -> V_48 ) {
if ( V_15 -> V_76 & V_77 ) {
V_17 = - V_78 ;
goto V_31;
}
V_17 = F_43 ( V_2 -> V_49 , ! V_2 -> V_48 ) ;
if ( V_17 ) {
goto V_31;
}
}
V_81 = F_44 ( int , V_70 , V_82 ) ;
F_5 ( & V_2 -> V_32 -> V_2 , L_10 ,
V_47 , V_70 , V_81 ) ;
if ( F_45 ( V_2 -> V_13 , V_69 , V_81 ) ) {
V_17 = - V_80 ;
goto V_31;
}
F_23 ( V_2 -> V_10 ,
V_2 -> V_32 ,
F_46 ( V_2 -> V_32 , V_2 -> V_83 -> V_40 ) ,
V_2 -> V_13 ,
V_81 ,
V_84 ,
V_2 ,
V_2 -> V_85 ) ;
V_2 -> V_48 = 1 ;
F_47 () ;
V_17 = F_27 ( V_2 -> V_10 , V_4 ) ;
if ( V_17 ) {
V_2 -> V_48 = 0 ;
F_22 ( & V_2 -> V_32 -> V_2 ,
L_11 , V_17 ) ;
goto V_31;
}
V_17 = V_81 ;
V_31:
F_18 ( & V_2 -> V_27 ) ;
exit:
return V_17 ;
}
static void V_41 ( struct V_86 * V_86 )
{
struct V_8 * V_2 = V_86 -> V_87 ;
int V_88 = V_86 -> V_88 ;
int V_17 ;
F_4 ( & V_2 -> V_32 -> V_2 , V_47 ,
V_86 -> V_89 , V_86 -> V_90 ) ;
if ( V_88 ) {
if ( V_88 == - V_91 ||
V_88 == - V_92 ||
V_88 == - V_93 ) {
goto exit;
} else {
F_5 ( & V_2 -> V_32 -> V_2 ,
L_12 , V_47 ,
V_88 ) ;
goto V_94;
}
}
if ( V_86 -> V_89 > 0 ) {
F_48 ( & V_2 -> V_51 ) ;
if ( V_2 -> V_37 + V_86 -> V_89 < V_56 ) {
memcpy ( V_2 -> V_11 + V_2 -> V_37 ,
V_2 -> V_12 ,
V_86 -> V_89 ) ;
V_2 -> V_37 += V_86 -> V_89 ;
V_2 -> V_54 = V_53 ;
F_5 ( & V_2 -> V_32 -> V_2 , L_13 ,
V_47 , V_86 -> V_89 ) ;
} else {
F_49 ( L_14 ,
V_86 -> V_89 ) ;
}
F_50 ( & V_2 -> V_51 ) ;
}
V_94:
if ( V_2 -> V_43 && V_2 -> V_32 ) {
V_17 = F_27 ( V_2 -> V_9 , V_95 ) ;
if ( V_17 )
F_22 ( & V_2 -> V_32 -> V_2 ,
L_15 ,
V_47 , V_17 ) ;
}
exit:
V_2 -> V_44 = 1 ;
F_51 ( & V_2 -> V_61 ) ;
}
static void V_84 ( struct V_86 * V_86 )
{
struct V_8 * V_2 = V_86 -> V_87 ;
int V_88 = V_86 -> V_88 ;
F_4 ( & V_2 -> V_32 -> V_2 , V_47 ,
V_86 -> V_89 , V_86 -> V_90 ) ;
if ( V_88 && ! ( V_88 == - V_91 ||
V_88 == - V_92 ||
V_88 == - V_93 ) ) {
F_5 ( & V_2 -> V_32 -> V_2 ,
L_16 , V_47 ,
V_88 ) ;
}
V_2 -> V_48 = 0 ;
F_51 ( & V_2 -> V_49 ) ;
}
static int F_52 ( struct V_18 * V_19 , const struct V_96 * V_97 )
{
struct V_1 * V_98 = & V_19 -> V_2 ;
struct V_99 * V_32 = F_53 ( V_19 ) ;
struct V_8 * V_2 = NULL ;
struct V_100 * V_101 = NULL ;
int V_17 = - V_23 ;
int V_22 ;
V_2 = F_11 ( sizeof( struct V_8 ) , V_4 ) ;
if ( ! V_2 )
goto exit;
F_54 ( & V_2 -> V_27 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_29 = 0 ;
V_2 -> V_11 = NULL ;
V_2 -> V_37 = 0 ;
V_2 -> V_38 = 0 ;
F_55 ( & V_2 -> V_51 ) ;
V_2 -> V_55 = F_39 ( V_52 ) ;
V_2 -> V_54 = V_53 ;
F_56 ( & V_2 -> V_61 ) ;
F_56 ( & V_2 -> V_49 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_39 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = 0 ;
V_2 -> V_13 = NULL ;
V_2 -> V_83 = NULL ;
V_2 -> V_10 = NULL ;
V_2 -> V_48 = 0 ;
V_22 = F_57 ( V_19 -> V_102 ,
NULL , NULL ,
& V_2 -> V_39 ,
& V_2 -> V_83 ) ;
if ( V_22 ) {
F_22 ( V_98 , L_17 ) ;
V_17 = V_22 ;
goto error;
}
V_2 -> V_11 = F_11 ( V_56 , V_4 ) ;
if ( ! V_2 -> V_11 )
goto error;
V_2 -> V_12 = F_11 ( F_25 ( V_2 -> V_39 ) , V_4 ) ;
if ( ! V_2 -> V_12 )
goto error;
V_2 -> V_9 = F_58 ( 0 , V_4 ) ;
if ( ! V_2 -> V_9 )
goto error;
V_2 -> V_13 = F_11 ( V_82 , V_4 ) ;
if ( ! V_2 -> V_13 )
goto error;
V_2 -> V_10 = F_58 ( 0 , V_4 ) ;
if ( ! V_2 -> V_10 )
goto error;
V_2 -> V_42 = V_42 ? V_42 : V_2 -> V_39 -> V_103 ;
V_2 -> V_85 = V_85 ? V_85 : V_2 -> V_83 -> V_103 ;
V_101 = F_11 ( sizeof( * V_101 ) , V_4 ) ;
if ( ! V_101 ) {
V_17 = - V_23 ;
goto error;
}
V_22 = F_20 ( V_32 ,
F_21 ( V_32 , 0 ) ,
V_104 ,
V_34 | V_35 | V_36 ,
0 ,
0 ,
V_101 ,
sizeof( * V_101 ) ,
1000 ) ;
if ( V_22 < 0 ) {
F_22 ( V_98 , L_18 ) ;
V_17 = V_22 ;
goto error;
}
F_59 ( & V_19 -> V_2 ,
L_19 ,
V_101 -> V_105 ,
V_101 -> V_106 ,
F_60 ( V_101 -> V_107 ) ) ;
F_61 ( V_19 , V_2 ) ;
V_17 = F_62 ( V_19 , & V_108 ) ;
if ( V_17 ) {
F_22 ( V_98 , L_20 ) ;
F_61 ( V_19 , NULL ) ;
goto error;
}
V_2 -> V_106 = V_19 -> V_106 ;
F_59 ( & V_19 -> V_2 , L_21
L_22 , ( V_2 -> V_106 - V_109 ) ,
V_110 , V_2 -> V_106 ) ;
exit:
F_9 ( V_101 ) ;
return V_17 ;
error:
F_9 ( V_101 ) ;
F_6 ( V_2 ) ;
return V_17 ;
}
static void F_63 ( struct V_18 * V_19 )
{
struct V_8 * V_2 ;
int V_106 ;
V_2 = F_17 ( V_19 ) ;
F_16 ( & V_26 ) ;
F_61 ( V_19 , NULL ) ;
V_106 = V_2 -> V_106 ;
F_64 ( V_19 , & V_108 ) ;
F_16 ( & V_2 -> V_27 ) ;
F_18 ( & V_26 ) ;
if ( ! V_2 -> V_29 ) {
F_18 ( & V_2 -> V_27 ) ;
F_6 ( V_2 ) ;
} else {
V_2 -> V_32 = NULL ;
F_65 ( & V_2 -> V_61 ) ;
F_65 ( & V_2 -> V_49 ) ;
F_18 ( & V_2 -> V_27 ) ;
}
F_59 ( & V_19 -> V_2 , L_23 ,
( V_106 - V_109 ) ) ;
}
