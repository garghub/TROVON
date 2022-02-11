static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_4 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
V_4 = F_3 ( V_6 , & V_2 -> V_3 ) ;
if ( ! V_4 )
V_2 -> V_7 ++ ;
F_4 ( & V_2 -> V_5 , V_3 ) ;
return V_4 ;
}
static void F_5 ( struct V_8 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_12 ;
F_7 ( L_1 , V_10 -> V_13 ,
V_8 , V_8 -> V_14 , V_8 -> V_15 ) ;
if ( ! F_3 ( V_16 , & V_10 -> V_3 ) )
return;
if ( V_8 -> V_14 == 0 ) {
V_10 -> V_17 . V_18 += V_8 -> V_15 ;
if ( F_8 ( V_10 , V_19 ,
V_8 -> V_20 ,
V_8 -> V_15 ) < 0 ) {
F_9 ( L_2 , V_10 -> V_13 ) ;
V_10 -> V_17 . V_21 ++ ;
}
}
if ( ! F_3 ( V_22 , & V_2 -> V_3 ) )
return;
F_10 ( V_2 -> V_23 ) ;
F_11 ( V_8 , & V_2 -> V_24 ) ;
V_12 = F_12 ( V_8 , V_25 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_26 && V_12 != - V_27 )
F_9 ( L_3 ,
V_10 -> V_13 , V_8 , - V_12 ) ;
F_13 ( V_8 ) ;
}
}
static int F_14 ( struct V_9 * V_10 , T_1 V_28 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
struct V_8 * V_8 ;
unsigned char * V_29 ;
unsigned int V_30 ;
int V_12 , V_31 ;
F_7 ( L_4 , V_10 -> V_13 ) ;
if ( ! V_2 -> V_32 )
return - V_27 ;
V_8 = F_15 ( 0 , V_28 ) ;
if ( ! V_8 )
return - V_33 ;
V_31 = F_16 ( V_2 -> V_32 -> V_34 ) ;
V_29 = F_17 ( V_31 , V_28 ) ;
if ( ! V_29 ) {
F_18 ( V_8 ) ;
return - V_33 ;
}
V_30 = F_19 ( V_2 -> V_23 , V_2 -> V_32 -> V_35 ) ;
F_20 ( V_8 , V_2 -> V_23 , V_30 , V_29 , V_31 ,
F_5 , V_10 ,
V_2 -> V_32 -> V_36 ) ;
V_8 -> V_37 |= V_38 ;
F_11 ( V_8 , & V_2 -> V_24 ) ;
V_12 = F_12 ( V_8 , V_28 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_26 && V_12 != - V_27 )
F_9 ( L_5 ,
V_10 -> V_13 , V_8 , - V_12 ) ;
F_13 ( V_8 ) ;
}
F_18 ( V_8 ) ;
return V_12 ;
}
static void F_21 ( struct V_8 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_12 ;
F_7 ( L_1 , V_10 -> V_13 ,
V_8 , V_8 -> V_14 , V_8 -> V_15 ) ;
if ( ! F_3 ( V_16 , & V_10 -> V_3 ) )
return;
if ( V_8 -> V_14 == 0 ) {
V_10 -> V_17 . V_18 += V_8 -> V_15 ;
if ( F_8 ( V_10 , V_39 ,
V_8 -> V_20 ,
V_8 -> V_15 ) < 0 ) {
F_9 ( L_6 , V_10 -> V_13 ) ;
V_10 -> V_17 . V_21 ++ ;
}
}
if ( ! F_3 ( V_40 , & V_2 -> V_3 ) )
return;
F_11 ( V_8 , & V_2 -> V_41 ) ;
F_10 ( V_2 -> V_23 ) ;
V_12 = F_12 ( V_8 , V_25 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_26 && V_12 != - V_27 )
F_9 ( L_3 ,
V_10 -> V_13 , V_8 , - V_12 ) ;
F_13 ( V_8 ) ;
}
}
static int F_22 ( struct V_9 * V_10 , T_1 V_28 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
struct V_8 * V_8 ;
unsigned char * V_29 ;
unsigned int V_30 ;
int V_12 , V_31 = V_42 ;
F_7 ( L_4 , V_10 -> V_13 ) ;
if ( ! V_2 -> V_43 )
return - V_27 ;
V_8 = F_15 ( 0 , V_28 ) ;
if ( ! V_8 )
return - V_33 ;
V_29 = F_17 ( V_31 , V_28 ) ;
if ( ! V_29 ) {
F_18 ( V_8 ) ;
return - V_33 ;
}
V_30 = F_23 ( V_2 -> V_23 , V_2 -> V_43 -> V_35 ) ;
F_24 ( V_8 , V_2 -> V_23 , V_30 ,
V_29 , V_31 , F_21 , V_10 ) ;
V_8 -> V_37 |= V_38 ;
F_10 ( V_2 -> V_23 ) ;
F_11 ( V_8 , & V_2 -> V_41 ) ;
V_12 = F_12 ( V_8 , V_28 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_26 && V_12 != - V_27 )
F_9 ( L_5 ,
V_10 -> V_13 , V_8 , - V_12 ) ;
F_13 ( V_8 ) ;
}
F_18 ( V_8 ) ;
return V_12 ;
}
static void F_25 ( struct V_8 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_44 , V_12 ;
F_7 ( L_1 , V_10 -> V_13 ,
V_8 , V_8 -> V_14 , V_8 -> V_15 ) ;
if ( ! F_3 ( V_16 , & V_10 -> V_3 ) )
return;
if ( V_8 -> V_14 == 0 ) {
for ( V_44 = 0 ; V_44 < V_8 -> V_45 ; V_44 ++ ) {
unsigned int V_46 = V_8 -> V_47 [ V_44 ] . V_46 ;
unsigned int V_48 = V_8 -> V_47 [ V_44 ] . V_15 ;
if ( V_8 -> V_47 [ V_44 ] . V_14 )
continue;
V_10 -> V_17 . V_18 += V_48 ;
if ( F_8 ( V_10 , V_49 ,
V_8 -> V_20 + V_46 ,
V_48 ) < 0 ) {
F_9 ( L_7 , V_10 -> V_13 ) ;
V_10 -> V_17 . V_21 ++ ;
}
}
}
if ( ! F_3 ( V_50 , & V_2 -> V_3 ) )
return;
F_11 ( V_8 , & V_2 -> V_51 ) ;
V_12 = F_12 ( V_8 , V_25 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_26 && V_12 != - V_27 )
F_9 ( L_3 ,
V_10 -> V_13 , V_8 , - V_12 ) ;
F_13 ( V_8 ) ;
}
}
static inline void F_26 ( struct V_8 * V_8 , int V_52 , int V_53 )
{
int V_44 , V_46 = 0 ;
F_7 ( L_8 , V_52 , V_53 ) ;
for ( V_44 = 0 ; V_44 < V_54 && V_52 >= V_53 ;
V_44 ++ , V_46 += V_53 , V_52 -= V_53 ) {
V_8 -> V_47 [ V_44 ] . V_46 = V_46 ;
V_8 -> V_47 [ V_44 ] . V_48 = V_53 ;
}
if ( V_52 && V_44 < V_54 ) {
V_8 -> V_47 [ V_44 ] . V_46 = V_46 ;
V_8 -> V_47 [ V_44 ] . V_48 = V_52 ;
V_44 ++ ;
}
V_8 -> V_45 = V_44 ;
}
static int F_27 ( struct V_9 * V_10 , T_1 V_28 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
struct V_8 * V_8 ;
unsigned char * V_29 ;
unsigned int V_30 ;
int V_12 , V_31 ;
F_7 ( L_4 , V_10 -> V_13 ) ;
if ( ! V_2 -> V_55 )
return - V_27 ;
V_8 = F_15 ( V_54 , V_28 ) ;
if ( ! V_8 )
return - V_33 ;
V_31 = F_16 ( V_2 -> V_55 -> V_34 ) *
V_54 ;
V_29 = F_17 ( V_31 , V_28 ) ;
if ( ! V_29 ) {
F_18 ( V_8 ) ;
return - V_33 ;
}
V_30 = F_28 ( V_2 -> V_23 , V_2 -> V_55 -> V_35 ) ;
F_20 ( V_8 , V_2 -> V_23 , V_30 , V_29 , V_31 , F_25 ,
V_10 , V_2 -> V_55 -> V_36 ) ;
V_8 -> V_37 = V_38 | V_56 ;
F_26 ( V_8 , V_31 ,
F_16 ( V_2 -> V_55 -> V_34 ) ) ;
F_11 ( V_8 , & V_2 -> V_51 ) ;
V_12 = F_12 ( V_8 , V_28 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_26 && V_12 != - V_27 )
F_9 ( L_5 ,
V_10 -> V_13 , V_8 , - V_12 ) ;
F_13 ( V_8 ) ;
}
F_18 ( V_8 ) ;
return V_12 ;
}
static void F_29 ( struct V_8 * V_8 )
{
struct V_57 * V_58 = V_8 -> V_11 ;
struct V_9 * V_10 = (struct V_9 * ) V_58 -> V_59 ;
struct V_1 * V_2 = F_6 ( V_10 ) ;
F_7 ( L_1 , V_10 -> V_13 ,
V_8 , V_8 -> V_14 , V_8 -> V_15 ) ;
if ( ! F_3 ( V_16 , & V_10 -> V_3 ) )
goto V_60;
if ( ! V_8 -> V_14 )
V_10 -> V_17 . V_61 += V_8 -> V_62 ;
else
V_10 -> V_17 . V_63 ++ ;
V_60:
F_30 ( & V_2 -> V_5 ) ;
V_2 -> V_7 -- ;
F_31 ( & V_2 -> V_5 ) ;
F_32 ( V_8 -> V_64 ) ;
F_33 ( V_58 ) ;
}
static void F_34 ( struct V_8 * V_8 )
{
struct V_57 * V_58 = V_8 -> V_11 ;
struct V_9 * V_10 = (struct V_9 * ) V_58 -> V_59 ;
F_7 ( L_1 , V_10 -> V_13 ,
V_8 , V_8 -> V_14 , V_8 -> V_15 ) ;
if ( ! F_3 ( V_16 , & V_10 -> V_3 ) )
goto V_60;
if ( ! V_8 -> V_14 )
V_10 -> V_17 . V_61 += V_8 -> V_62 ;
else
V_10 -> V_17 . V_63 ++ ;
V_60:
F_32 ( V_8 -> V_64 ) ;
F_33 ( V_58 ) ;
}
static int F_35 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_12 ;
F_7 ( L_4 , V_10 -> V_13 ) ;
V_12 = F_36 ( V_2 -> V_65 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_65 -> V_66 = 1 ;
if ( F_37 ( V_16 , & V_10 -> V_3 ) )
goto V_60;
if ( F_37 ( V_22 , & V_2 -> V_3 ) )
goto V_60;
V_12 = F_14 ( V_10 , V_67 ) ;
if ( V_12 < 0 )
goto V_68;
V_12 = F_22 ( V_10 , V_67 ) ;
if ( V_12 < 0 ) {
F_38 ( & V_2 -> V_24 ) ;
goto V_68;
}
F_39 ( V_40 , & V_2 -> V_3 ) ;
F_22 ( V_10 , V_67 ) ;
V_60:
F_40 ( V_2 -> V_65 ) ;
return 0 ;
V_68:
F_41 ( V_22 , & V_2 -> V_3 ) ;
F_41 ( V_16 , & V_10 -> V_3 ) ;
F_40 ( V_2 -> V_65 ) ;
return V_12 ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_24 ) ;
F_38 ( & V_2 -> V_41 ) ;
F_38 ( & V_2 -> V_51 ) ;
}
static int F_43 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_12 ;
F_7 ( L_4 , V_10 -> V_13 ) ;
if ( ! F_44 ( V_16 , & V_10 -> V_3 ) )
return 0 ;
F_45 ( & V_2 -> V_69 ) ;
F_45 ( & V_2 -> V_70 ) ;
F_41 ( V_50 , & V_2 -> V_3 ) ;
F_41 ( V_40 , & V_2 -> V_3 ) ;
F_41 ( V_22 , & V_2 -> V_3 ) ;
F_42 ( V_2 ) ;
V_12 = F_36 ( V_2 -> V_65 ) ;
if ( V_12 < 0 )
goto V_68;
V_2 -> V_65 -> V_66 = 0 ;
F_40 ( V_2 -> V_65 ) ;
V_68:
F_46 ( & V_2 -> V_71 ) ;
return 0 ;
}
static int F_47 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
F_7 ( L_4 , V_10 -> V_13 ) ;
F_38 ( & V_2 -> V_72 ) ;
return 0 ;
}
static int F_48 ( struct V_9 * V_10 , struct V_57 * V_58 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
struct V_73 * V_74 ;
struct V_8 * V_8 ;
unsigned int V_30 ;
int V_12 ;
F_7 ( L_4 , V_10 -> V_13 ) ;
if ( ! F_3 ( V_16 , & V_10 -> V_3 ) )
return - V_75 ;
V_58 -> V_59 = ( void * ) V_10 ;
switch ( F_49 ( V_58 ) -> V_76 ) {
case V_77 :
V_8 = F_15 ( 0 , V_25 ) ;
if ( ! V_8 )
return - V_33 ;
V_74 = F_17 ( sizeof( * V_74 ) , V_25 ) ;
if ( ! V_74 ) {
F_18 ( V_8 ) ;
return - V_33 ;
}
V_74 -> V_78 = V_2 -> V_79 ;
V_74 -> V_80 = 0 ;
V_74 -> V_81 = 0 ;
V_74 -> V_82 = 0 ;
V_74 -> V_83 = F_50 ( V_58 -> V_52 ) ;
V_30 = F_51 ( V_2 -> V_23 , 0x00 ) ;
F_52 ( V_8 , V_2 -> V_23 , V_30 , ( void * ) V_74 ,
V_58 -> V_2 , V_58 -> V_52 , F_29 , V_58 ) ;
V_10 -> V_17 . V_84 ++ ;
break;
case V_39 :
if ( ! V_2 -> V_85 )
return - V_27 ;
V_8 = F_15 ( 0 , V_25 ) ;
if ( ! V_8 )
return - V_33 ;
V_30 = F_53 ( V_2 -> V_23 ,
V_2 -> V_85 -> V_35 ) ;
F_24 ( V_8 , V_2 -> V_23 , V_30 ,
V_58 -> V_2 , V_58 -> V_52 , F_29 , V_58 ) ;
V_10 -> V_17 . V_86 ++ ;
break;
case V_49 :
if ( ! V_2 -> V_87 || F_54 ( V_10 , V_88 ) < 1 )
return - V_27 ;
V_8 = F_15 ( V_54 , V_25 ) ;
if ( ! V_8 )
return - V_33 ;
V_30 = F_55 ( V_2 -> V_23 ,
V_2 -> V_87 -> V_35 ) ;
F_20 ( V_8 , V_2 -> V_23 , V_30 ,
V_58 -> V_2 , V_58 -> V_52 , F_34 ,
V_58 , V_2 -> V_87 -> V_36 ) ;
V_8 -> V_37 = V_56 ;
F_26 ( V_8 , V_58 -> V_52 ,
F_16 ( V_2 -> V_87 -> V_34 ) ) ;
V_10 -> V_17 . V_89 ++ ;
goto V_90;
default:
return - V_91 ;
}
V_12 = F_1 ( V_2 ) ;
if ( V_12 ) {
F_11 ( V_8 , & V_2 -> V_71 ) ;
F_56 ( & V_2 -> V_70 ) ;
V_12 = 0 ;
goto V_60;
}
V_90:
F_11 ( V_8 , & V_2 -> V_72 ) ;
V_12 = F_12 ( V_8 , V_25 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_26 && V_12 != - V_27 )
F_9 ( L_5 ,
V_10 -> V_13 , V_8 , - V_12 ) ;
F_32 ( V_8 -> V_64 ) ;
F_13 ( V_8 ) ;
} else {
F_10 ( V_2 -> V_23 ) ;
}
V_60:
F_18 ( V_8 ) ;
return V_12 ;
}
static void F_57 ( struct V_9 * V_10 , unsigned int V_92 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
F_7 ( L_9 , V_10 -> V_13 , V_92 ) ;
if ( F_54 ( V_10 , V_88 ) != V_2 -> V_93 ) {
V_2 -> V_93 = F_54 ( V_10 , V_88 ) ;
F_56 ( & V_2 -> V_69 ) ;
}
}
static inline int F_58 ( struct V_9 * V_10 , int V_94 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
struct V_95 * V_65 = V_2 -> V_96 ;
struct V_97 * V_98 ;
int V_44 , V_12 ;
if ( ! V_2 -> V_96 )
return - V_27 ;
V_12 = F_59 ( V_2 -> V_23 , 1 , V_94 ) ;
if ( V_12 < 0 ) {
F_9 ( L_10 , V_10 -> V_13 , - V_12 ) ;
return V_12 ;
}
V_2 -> V_99 = V_94 ;
V_2 -> V_87 = NULL ;
V_2 -> V_55 = NULL ;
for ( V_44 = 0 ; V_44 < V_65 -> V_100 -> V_101 . V_102 ; V_44 ++ ) {
V_98 = & V_65 -> V_100 -> V_103 [ V_44 ] . V_101 ;
if ( ! V_2 -> V_87 && F_60 ( V_98 ) ) {
V_2 -> V_87 = V_98 ;
continue;
}
if ( ! V_2 -> V_55 && F_61 ( V_98 ) ) {
V_2 -> V_55 = V_98 ;
continue;
}
}
if ( ! V_2 -> V_87 || ! V_2 -> V_55 ) {
F_9 ( L_11 , V_10 -> V_13 ) ;
return - V_27 ;
}
return 0 ;
}
static void F_62 ( struct V_104 * V_69 )
{
struct V_1 * V_2 = F_63 ( V_69 , struct V_1 , V_69 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_105 ;
int V_12 ;
if ( V_2 -> V_93 > 0 ) {
if ( ! F_3 ( V_106 , & V_2 -> V_3 ) ) {
V_12 = F_36 ( V_2 -> V_96 ? V_2 -> V_96 : V_2 -> V_65 ) ;
if ( V_12 < 0 ) {
F_41 ( V_50 , & V_2 -> V_3 ) ;
F_38 ( & V_2 -> V_51 ) ;
return;
}
F_39 ( V_106 , & V_2 -> V_3 ) ;
}
if ( V_10 -> V_107 & 0x0020 ) {
static const int V_108 [ 3 ] = { 2 , 4 , 5 } ;
V_105 = V_108 [ V_2 -> V_93 - 1 ] ;
} else {
V_105 = V_2 -> V_93 ;
}
if ( V_2 -> V_99 != V_105 ) {
F_41 ( V_50 , & V_2 -> V_3 ) ;
F_38 ( & V_2 -> V_51 ) ;
if ( F_58 ( V_10 , V_105 ) < 0 )
return;
}
if ( ! F_37 ( V_50 , & V_2 -> V_3 ) ) {
if ( F_27 ( V_10 , V_67 ) < 0 )
F_41 ( V_50 , & V_2 -> V_3 ) ;
else
F_27 ( V_10 , V_67 ) ;
}
} else {
F_41 ( V_50 , & V_2 -> V_3 ) ;
F_38 ( & V_2 -> V_51 ) ;
F_58 ( V_10 , 0 ) ;
if ( F_44 ( V_106 , & V_2 -> V_3 ) )
F_40 ( V_2 -> V_96 ? V_2 -> V_96 : V_2 -> V_65 ) ;
}
}
static void F_64 ( struct V_104 * V_69 )
{
struct V_1 * V_2 = F_63 ( V_69 , struct V_1 , V_70 ) ;
int V_12 ;
V_12 = F_36 ( V_2 -> V_65 ) ;
if ( V_12 < 0 )
return;
F_40 ( V_2 -> V_65 ) ;
}
static int F_65 ( struct V_9 * V_10 )
{
struct V_57 * V_58 ;
T_2 V_109 = 0x00 ;
F_7 ( L_4 , V_10 -> V_13 ) ;
V_58 = F_66 ( V_10 , 0xfc3b , 1 , & V_109 , V_110 ) ;
if ( F_67 ( V_58 ) )
F_9 ( L_12 , - F_68 ( V_58 ) ) ;
else
F_33 ( V_58 ) ;
return 0 ;
}
static int F_69 ( struct V_9 * V_10 )
{
struct V_111 * V_112 ;
struct V_57 * V_58 ;
int V_113 ;
F_7 ( L_4 , V_10 -> V_13 ) ;
V_58 = F_66 ( V_10 , V_114 , 0 , NULL ,
V_110 ) ;
if ( F_67 ( V_58 ) ) {
F_9 ( L_13 , - F_68 ( V_58 ) ) ;
return - F_68 ( V_58 ) ;
}
V_112 = (struct V_111 * ) V_58 -> V_2 ;
if ( ! V_112 -> V_14 ) {
if ( F_16 ( V_112 -> V_115 ) != 10 ) {
F_41 ( V_116 , & V_10 -> V_117 ) ;
F_39 ( V_118 ,
& V_10 -> V_117 ) ;
}
}
V_113 = - F_70 ( V_112 -> V_14 ) ;
F_33 ( V_58 ) ;
return V_113 ;
}
static const struct V_119 * F_71 ( struct V_9 * V_10 ,
struct V_120 * V_121 )
{
const struct V_119 * V_122 ;
char V_123 [ 64 ] ;
int V_113 ;
snprintf ( V_123 , sizeof( V_123 ) ,
L_14 ,
V_121 -> V_124 , V_121 -> V_125 , V_121 -> V_126 ,
V_121 -> V_127 , V_121 -> V_128 , V_121 -> V_129 ,
V_121 -> V_130 , V_121 -> V_131 ) ;
V_113 = F_72 ( & V_122 , V_123 , & V_10 -> V_59 ) ;
if ( V_113 < 0 ) {
if ( V_113 == - V_132 ) {
F_9 ( L_15 ,
V_10 -> V_13 , V_113 ) ;
return NULL ;
}
F_9 ( L_16 ,
V_10 -> V_13 , V_123 , V_113 ) ;
snprintf ( V_123 , sizeof( V_123 ) , L_17 ,
V_121 -> V_124 , V_121 -> V_125 ) ;
if ( F_72 ( & V_122 , V_123 , & V_10 -> V_59 ) < 0 ) {
F_9 ( L_18 ,
V_10 -> V_13 , V_123 ) ;
return NULL ;
}
}
F_73 ( L_19 , V_10 -> V_13 , V_123 ) ;
return V_122 ;
}
static int F_74 ( struct V_9 * V_10 ,
const struct V_119 * V_122 ,
const T_2 * * V_133 , int * V_134 )
{
struct V_57 * V_58 ;
struct V_135 * V_136 ;
const T_2 * V_137 ;
struct V_138 * V_92 = NULL ;
const T_2 * V_139 = NULL ;
int V_140 = V_122 -> V_31 - ( * V_133 - V_122 -> V_2 ) ;
if ( V_140 > V_141 && * V_133 [ 0 ] != 0x01 ) {
F_9 ( L_20 , V_10 -> V_13 ) ;
return - V_132 ;
}
( * V_133 ) ++ ;
V_140 -- ;
V_136 = (struct V_135 * ) ( * V_133 ) ;
* V_133 += sizeof( * V_136 ) ;
V_140 -= sizeof( * V_136 ) ;
if ( V_140 < V_136 -> V_142 ) {
F_9 ( L_21 , V_10 -> V_13 ) ;
return - V_143 ;
}
if ( * V_134 && F_16 ( V_136 -> V_144 ) == 0xfc8e )
* V_134 = 0 ;
V_137 = * V_133 ;
* V_133 += V_136 -> V_142 ;
V_140 -= V_136 -> V_142 ;
while ( V_140 > V_145 && * V_133 [ 0 ] == 0x02 ) {
( * V_133 ) ++ ;
V_140 -- ;
V_92 = (struct V_138 * ) ( * V_133 ) ;
* V_133 += sizeof( * V_92 ) ;
V_140 -= sizeof( * V_92 ) ;
if ( V_140 < V_92 -> V_142 ) {
F_9 ( L_22 ,
V_10 -> V_13 ) ;
return - V_143 ;
}
V_139 = * V_133 ;
* V_133 += V_92 -> V_142 ;
V_140 -= V_92 -> V_142 ;
}
if ( ! V_92 || ! V_139 || V_140 < 0 ) {
F_9 ( L_23 , V_10 -> V_13 ) ;
return - V_143 ;
}
V_58 = F_75 ( V_10 , F_16 ( V_136 -> V_144 ) , V_136 -> V_142 ,
V_137 , V_92 -> V_92 , V_110 ) ;
if ( F_67 ( V_58 ) ) {
F_9 ( L_24 ,
V_10 -> V_13 , V_136 -> V_144 , F_68 ( V_58 ) ) ;
return F_68 ( V_58 ) ;
}
if ( V_58 -> V_52 != V_92 -> V_142 ) {
F_9 ( L_25 , V_10 -> V_13 ,
F_16 ( V_136 -> V_144 ) ) ;
F_33 ( V_58 ) ;
return - V_143 ;
}
if ( memcmp ( V_58 -> V_2 , V_139 , V_92 -> V_142 ) ) {
F_9 ( L_26 ,
V_10 -> V_13 , F_16 ( V_136 -> V_144 ) ) ;
F_33 ( V_58 ) ;
return - V_143 ;
}
F_33 ( V_58 ) ;
return 0 ;
}
static int F_76 ( struct V_9 * V_10 )
{
struct V_57 * V_58 ;
const struct V_119 * V_122 ;
const T_2 * V_133 ;
int V_134 ;
struct V_120 * V_121 ;
const T_2 V_146 [] = { 0x01 , 0x00 } ;
const T_2 V_147 [] = { 0x00 , 0x00 } ;
const T_2 V_148 [] = { 0x00 , 0x01 } ;
const T_2 V_149 [] = { 0x00 , 0x02 } ;
F_7 ( L_4 , V_10 -> V_13 ) ;
V_58 = F_66 ( V_10 , V_150 , 0 , NULL , V_110 ) ;
if ( F_67 ( V_58 ) ) {
F_9 ( L_27 ,
V_10 -> V_13 , F_68 ( V_58 ) ) ;
return F_68 ( V_58 ) ;
}
F_33 ( V_58 ) ;
V_58 = F_66 ( V_10 , 0xfc05 , 0 , NULL , V_110 ) ;
if ( F_67 ( V_58 ) ) {
F_9 ( L_28 ,
V_10 -> V_13 , F_68 ( V_58 ) ) ;
return F_68 ( V_58 ) ;
}
if ( V_58 -> V_52 != sizeof( * V_121 ) ) {
F_9 ( L_29 , V_10 -> V_13 ) ;
F_33 ( V_58 ) ;
return - V_151 ;
}
V_121 = (struct V_120 * ) V_58 -> V_2 ;
if ( V_121 -> V_14 ) {
F_9 ( L_30 , V_10 -> V_13 ,
V_121 -> V_14 ) ;
F_33 ( V_58 ) ;
return - F_70 ( V_121 -> V_14 ) ;
}
F_73 ( L_31 ,
V_10 -> V_13 , V_121 -> V_124 , V_121 -> V_125 ,
V_121 -> V_126 , V_121 -> V_127 , V_121 -> V_128 ,
V_121 -> V_129 , V_121 -> V_130 , V_121 -> V_131 ,
V_121 -> V_152 ) ;
if ( V_121 -> V_152 ) {
F_73 ( L_32 ,
V_10 -> V_13 , V_121 -> V_152 ) ;
F_33 ( V_58 ) ;
return 0 ;
}
V_122 = F_71 ( V_10 , V_121 ) ;
if ( ! V_122 ) {
F_33 ( V_58 ) ;
return 0 ;
}
V_133 = V_122 -> V_2 ;
V_58 = F_66 ( V_10 , 0xfc11 , 2 , V_146 , V_110 ) ;
if ( F_67 ( V_58 ) ) {
F_9 ( L_33 ,
V_10 -> V_13 , F_68 ( V_58 ) ) ;
F_77 ( V_122 ) ;
return F_68 ( V_58 ) ;
}
if ( V_58 -> V_2 [ 0 ] ) {
T_2 V_153 = V_58 -> V_2 [ 0 ] ;
F_9 ( L_34 ,
V_10 -> V_13 , V_153 ) ;
F_33 ( V_58 ) ;
F_77 ( V_122 ) ;
return - F_70 ( V_153 ) ;
}
F_33 ( V_58 ) ;
V_134 = 1 ;
while ( V_122 -> V_31 > V_133 - V_122 -> V_2 ) {
int V_113 ;
V_113 = F_74 ( V_10 , V_122 , & V_133 ,
& V_134 ) ;
if ( V_113 < 0 )
goto V_154;
}
F_77 ( V_122 ) ;
if ( V_134 )
goto V_155;
V_58 = F_66 ( V_10 , 0xfc11 , sizeof( V_149 ) ,
V_149 , V_110 ) ;
if ( F_67 ( V_58 ) ) {
F_9 ( L_35 ,
V_10 -> V_13 , F_68 ( V_58 ) ) ;
return F_68 ( V_58 ) ;
}
F_33 ( V_58 ) ;
F_73 ( L_36 ,
V_10 -> V_13 ) ;
return 0 ;
V_155:
V_58 = F_66 ( V_10 , 0xfc11 , sizeof( V_147 ) , V_147 ,
V_110 ) ;
if ( F_67 ( V_58 ) ) {
F_9 ( L_35 ,
V_10 -> V_13 , F_68 ( V_58 ) ) ;
return F_68 ( V_58 ) ;
}
F_33 ( V_58 ) ;
F_73 ( L_37 , V_10 -> V_13 ) ;
return 0 ;
V_154:
F_77 ( V_122 ) ;
V_58 = F_66 ( V_10 , 0xfc11 , sizeof( V_148 ) ,
V_148 , V_110 ) ;
if ( F_67 ( V_58 ) ) {
F_9 ( L_35 ,
V_10 -> V_13 , F_68 ( V_58 ) ) ;
return F_68 ( V_58 ) ;
}
F_33 ( V_58 ) ;
F_73 ( L_38 ,
V_10 -> V_13 ) ;
return 0 ;
}
static int F_78 ( struct V_95 * V_65 ,
const struct V_156 * V_157 )
{
struct V_97 * V_98 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_44 , V_12 ;
F_7 ( L_39 , V_65 , V_157 ) ;
if ( V_65 -> V_100 -> V_101 . V_158 != 0 )
return - V_27 ;
if ( ! V_157 -> V_159 ) {
const struct V_156 * V_160 ;
V_160 = F_79 ( V_65 , V_161 ) ;
if ( V_160 )
V_157 = V_160 ;
}
if ( V_157 -> V_159 == V_162 )
return - V_27 ;
if ( V_163 && V_157 -> V_159 & V_164 )
return - V_27 ;
if ( V_165 && V_157 -> V_159 & V_166 )
return - V_27 ;
if ( V_167 && V_157 -> V_159 & V_168 )
return - V_27 ;
if ( V_157 -> V_159 & V_169 ) {
struct V_170 * V_23 = F_80 ( V_65 ) ;
if ( F_16 ( V_23 -> V_171 . V_172 ) <= 0x0001 )
return - V_27 ;
}
V_2 = F_81 ( & V_65 -> V_59 , sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_33 ;
for ( V_44 = 0 ; V_44 < V_65 -> V_100 -> V_101 . V_102 ; V_44 ++ ) {
V_98 = & V_65 -> V_100 -> V_103 [ V_44 ] . V_101 ;
if ( ! V_2 -> V_32 && F_82 ( V_98 ) ) {
V_2 -> V_32 = V_98 ;
continue;
}
if ( ! V_2 -> V_85 && F_83 ( V_98 ) ) {
V_2 -> V_85 = V_98 ;
continue;
}
if ( ! V_2 -> V_43 && F_84 ( V_98 ) ) {
V_2 -> V_43 = V_98 ;
continue;
}
}
if ( ! V_2 -> V_32 || ! V_2 -> V_85 || ! V_2 -> V_43 )
return - V_27 ;
V_2 -> V_79 = V_173 ;
V_2 -> V_23 = F_80 ( V_65 ) ;
V_2 -> V_65 = V_65 ;
F_85 ( & V_2 -> V_174 ) ;
F_86 ( & V_2 -> V_69 , F_62 ) ;
F_86 ( & V_2 -> V_70 , F_64 ) ;
F_85 ( & V_2 -> V_5 ) ;
F_87 ( & V_2 -> V_72 ) ;
F_87 ( & V_2 -> V_24 ) ;
F_87 ( & V_2 -> V_41 ) ;
F_87 ( & V_2 -> V_51 ) ;
F_87 ( & V_2 -> V_71 ) ;
V_10 = F_88 () ;
if ( ! V_10 )
return - V_33 ;
V_10 -> V_175 = V_176 ;
F_89 ( V_10 , V_2 ) ;
V_2 -> V_10 = V_10 ;
F_90 ( V_10 , & V_65 -> V_59 ) ;
V_10 -> V_177 = F_35 ;
V_10 -> V_178 = F_43 ;
V_10 -> V_179 = F_47 ;
V_10 -> V_180 = F_48 ;
V_10 -> V_181 = F_57 ;
if ( V_157 -> V_159 & V_182 )
V_10 -> V_183 = F_65 ;
if ( V_157 -> V_159 & V_184 )
V_10 -> V_183 = F_76 ;
V_2 -> V_96 = F_91 ( V_2 -> V_23 , 1 ) ;
if ( ! V_185 )
F_39 ( V_116 , & V_10 -> V_117 ) ;
if ( V_186 || V_157 -> V_159 & V_187 ) {
if ( ! V_188 )
F_39 ( V_189 , & V_10 -> V_117 ) ;
}
if ( V_157 -> V_159 & V_190 )
V_2 -> V_96 = NULL ;
if ( V_157 -> V_159 & V_164 ) {
V_2 -> V_79 = V_191 ;
F_39 ( V_116 , & V_10 -> V_117 ) ;
}
if ( V_157 -> V_159 & V_166 ) {
struct V_170 * V_23 = V_2 -> V_23 ;
T_3 V_172 = F_16 ( V_23 -> V_171 . V_172 ) ;
if ( V_172 < 0x117 )
F_39 ( V_116 , & V_10 -> V_117 ) ;
if ( V_172 <= 0x100 )
V_10 -> V_183 = F_69 ;
}
if ( V_157 -> V_159 & V_168 ) {
struct V_170 * V_23 = V_2 -> V_23 ;
if ( F_16 ( V_23 -> V_171 . V_172 ) > 0x997 )
F_39 ( V_192 , & V_10 -> V_117 ) ;
V_2 -> V_96 = NULL ;
}
if ( V_2 -> V_96 ) {
V_12 = F_92 ( & V_193 ,
V_2 -> V_96 , V_2 ) ;
if ( V_12 < 0 ) {
F_93 ( V_10 ) ;
return V_12 ;
}
}
V_12 = F_94 ( V_10 ) ;
if ( V_12 < 0 ) {
F_93 ( V_10 ) ;
return V_12 ;
}
F_95 ( V_65 , V_2 ) ;
return 0 ;
}
static void F_96 ( struct V_95 * V_65 )
{
struct V_1 * V_2 = F_97 ( V_65 ) ;
struct V_9 * V_10 ;
F_7 ( L_40 , V_65 ) ;
if ( ! V_2 )
return;
V_10 = V_2 -> V_10 ;
F_95 ( V_2 -> V_65 , NULL ) ;
if ( V_2 -> V_96 )
F_95 ( V_2 -> V_96 , NULL ) ;
F_98 ( V_10 ) ;
if ( V_65 == V_2 -> V_96 )
F_99 ( & V_193 , V_2 -> V_65 ) ;
else if ( V_2 -> V_96 )
F_99 ( & V_193 , V_2 -> V_96 ) ;
F_93 ( V_10 ) ;
}
static int F_100 ( struct V_95 * V_65 , T_4 V_194 )
{
struct V_1 * V_2 = F_97 ( V_65 ) ;
F_7 ( L_40 , V_65 ) ;
if ( V_2 -> V_195 ++ )
return 0 ;
F_101 ( & V_2 -> V_5 ) ;
if ( ! ( F_102 ( V_194 ) && V_2 -> V_7 ) ) {
F_39 ( V_6 , & V_2 -> V_3 ) ;
F_103 ( & V_2 -> V_5 ) ;
} else {
F_103 ( & V_2 -> V_5 ) ;
V_2 -> V_195 -- ;
return - V_75 ;
}
F_45 ( & V_2 -> V_69 ) ;
F_42 ( V_2 ) ;
F_38 ( & V_2 -> V_72 ) ;
return 0 ;
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_8 * V_8 ;
int V_12 ;
while ( ( V_8 = F_105 ( & V_2 -> V_71 ) ) ) {
V_12 = F_12 ( V_8 , V_25 ) ;
if ( V_12 < 0 )
break;
V_2 -> V_7 ++ ;
}
F_46 ( & V_2 -> V_71 ) ;
}
static int F_106 ( struct V_95 * V_65 )
{
struct V_1 * V_2 = F_97 ( V_65 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_12 = 0 ;
F_7 ( L_40 , V_65 ) ;
if ( -- V_2 -> V_195 )
return 0 ;
if ( ! F_3 ( V_16 , & V_10 -> V_3 ) )
goto V_60;
if ( F_3 ( V_22 , & V_2 -> V_3 ) ) {
V_12 = F_14 ( V_10 , V_196 ) ;
if ( V_12 < 0 ) {
F_41 ( V_22 , & V_2 -> V_3 ) ;
goto V_68;
}
}
if ( F_3 ( V_40 , & V_2 -> V_3 ) ) {
V_12 = F_22 ( V_10 , V_196 ) ;
if ( V_12 < 0 ) {
F_41 ( V_40 , & V_2 -> V_3 ) ;
goto V_68;
}
F_22 ( V_10 , V_196 ) ;
}
if ( F_3 ( V_50 , & V_2 -> V_3 ) ) {
if ( F_27 ( V_10 , V_196 ) < 0 )
F_41 ( V_50 , & V_2 -> V_3 ) ;
else
F_27 ( V_10 , V_196 ) ;
}
F_101 ( & V_2 -> V_5 ) ;
F_104 ( V_2 ) ;
F_41 ( V_6 , & V_2 -> V_3 ) ;
F_103 ( & V_2 -> V_5 ) ;
F_56 ( & V_2 -> V_69 ) ;
return 0 ;
V_68:
F_46 ( & V_2 -> V_71 ) ;
V_60:
F_101 ( & V_2 -> V_5 ) ;
F_41 ( V_6 , & V_2 -> V_3 ) ;
F_103 ( & V_2 -> V_5 ) ;
return V_12 ;
}
