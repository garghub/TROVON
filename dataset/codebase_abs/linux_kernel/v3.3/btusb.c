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
struct V_1 * V_2 = V_10 -> V_12 ;
int V_13 ;
F_6 ( L_1 , V_10 -> V_14 ,
V_8 , V_8 -> V_15 , V_8 -> V_16 ) ;
if ( ! F_3 ( V_17 , & V_10 -> V_3 ) )
return;
if ( V_8 -> V_15 == 0 ) {
V_10 -> V_18 . V_19 += V_8 -> V_16 ;
if ( F_7 ( V_10 , V_20 ,
V_8 -> V_21 ,
V_8 -> V_16 ) < 0 ) {
F_8 ( L_2 , V_10 -> V_14 ) ;
V_10 -> V_18 . V_22 ++ ;
}
}
if ( ! F_3 ( V_23 , & V_2 -> V_3 ) )
return;
F_9 ( V_2 -> V_24 ) ;
F_10 ( V_8 , & V_2 -> V_25 ) ;
V_13 = F_11 ( V_8 , V_26 ) ;
if ( V_13 < 0 ) {
if ( V_13 != - V_27 && V_13 != - V_28 )
F_8 ( L_3 ,
V_10 -> V_14 , V_8 , - V_13 ) ;
F_12 ( V_8 ) ;
}
}
static int F_13 ( struct V_9 * V_10 , T_1 V_29 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 ;
unsigned char * V_30 ;
unsigned int V_31 ;
int V_13 , V_32 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
if ( ! V_2 -> V_33 )
return - V_28 ;
V_8 = F_14 ( 0 , V_29 ) ;
if ( ! V_8 )
return - V_34 ;
V_32 = F_15 ( V_2 -> V_33 -> V_35 ) ;
V_30 = F_16 ( V_32 , V_29 ) ;
if ( ! V_30 ) {
F_17 ( V_8 ) ;
return - V_34 ;
}
V_31 = F_18 ( V_2 -> V_24 , V_2 -> V_33 -> V_36 ) ;
F_19 ( V_8 , V_2 -> V_24 , V_31 , V_30 , V_32 ,
F_5 , V_10 ,
V_2 -> V_33 -> V_37 ) ;
V_8 -> V_38 |= V_39 ;
F_10 ( V_8 , & V_2 -> V_25 ) ;
V_13 = F_11 ( V_8 , V_29 ) ;
if ( V_13 < 0 ) {
if ( V_13 != - V_27 && V_13 != - V_28 )
F_8 ( L_5 ,
V_10 -> V_14 , V_8 , - V_13 ) ;
F_12 ( V_8 ) ;
}
F_17 ( V_8 ) ;
return V_13 ;
}
static void F_20 ( struct V_8 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 = V_10 -> V_12 ;
int V_13 ;
F_6 ( L_1 , V_10 -> V_14 ,
V_8 , V_8 -> V_15 , V_8 -> V_16 ) ;
if ( ! F_3 ( V_17 , & V_10 -> V_3 ) )
return;
if ( V_8 -> V_15 == 0 ) {
V_10 -> V_18 . V_19 += V_8 -> V_16 ;
if ( F_7 ( V_10 , V_40 ,
V_8 -> V_21 ,
V_8 -> V_16 ) < 0 ) {
F_8 ( L_6 , V_10 -> V_14 ) ;
V_10 -> V_18 . V_22 ++ ;
}
}
if ( ! F_3 ( V_41 , & V_2 -> V_3 ) )
return;
F_10 ( V_8 , & V_2 -> V_42 ) ;
F_9 ( V_2 -> V_24 ) ;
V_13 = F_11 ( V_8 , V_26 ) ;
if ( V_13 < 0 ) {
if ( V_13 != - V_27 && V_13 != - V_28 )
F_8 ( L_3 ,
V_10 -> V_14 , V_8 , - V_13 ) ;
F_12 ( V_8 ) ;
}
}
static int F_21 ( struct V_9 * V_10 , T_1 V_29 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 ;
unsigned char * V_30 ;
unsigned int V_31 ;
int V_13 , V_32 = V_43 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
if ( ! V_2 -> V_44 )
return - V_28 ;
V_8 = F_14 ( 0 , V_29 ) ;
if ( ! V_8 )
return - V_34 ;
V_30 = F_16 ( V_32 , V_29 ) ;
if ( ! V_30 ) {
F_17 ( V_8 ) ;
return - V_34 ;
}
V_31 = F_22 ( V_2 -> V_24 , V_2 -> V_44 -> V_36 ) ;
F_23 ( V_8 , V_2 -> V_24 , V_31 ,
V_30 , V_32 , F_20 , V_10 ) ;
V_8 -> V_38 |= V_39 ;
F_9 ( V_2 -> V_24 ) ;
F_10 ( V_8 , & V_2 -> V_42 ) ;
V_13 = F_11 ( V_8 , V_29 ) ;
if ( V_13 < 0 ) {
if ( V_13 != - V_27 && V_13 != - V_28 )
F_8 ( L_5 ,
V_10 -> V_14 , V_8 , - V_13 ) ;
F_12 ( V_8 ) ;
}
F_17 ( V_8 ) ;
return V_13 ;
}
static void F_24 ( struct V_8 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 = V_10 -> V_12 ;
int V_45 , V_13 ;
F_6 ( L_1 , V_10 -> V_14 ,
V_8 , V_8 -> V_15 , V_8 -> V_16 ) ;
if ( ! F_3 ( V_17 , & V_10 -> V_3 ) )
return;
if ( V_8 -> V_15 == 0 ) {
for ( V_45 = 0 ; V_45 < V_8 -> V_46 ; V_45 ++ ) {
unsigned int V_47 = V_8 -> V_48 [ V_45 ] . V_47 ;
unsigned int V_49 = V_8 -> V_48 [ V_45 ] . V_16 ;
if ( V_8 -> V_48 [ V_45 ] . V_15 )
continue;
V_10 -> V_18 . V_19 += V_49 ;
if ( F_7 ( V_10 , V_50 ,
V_8 -> V_21 + V_47 ,
V_49 ) < 0 ) {
F_8 ( L_7 , V_10 -> V_14 ) ;
V_10 -> V_18 . V_22 ++ ;
}
}
}
if ( ! F_3 ( V_51 , & V_2 -> V_3 ) )
return;
F_10 ( V_8 , & V_2 -> V_52 ) ;
V_13 = F_11 ( V_8 , V_26 ) ;
if ( V_13 < 0 ) {
if ( V_13 != - V_27 && V_13 != - V_28 )
F_8 ( L_3 ,
V_10 -> V_14 , V_8 , - V_13 ) ;
F_12 ( V_8 ) ;
}
}
static inline void F_25 ( struct V_8 * V_8 , int V_53 , int V_54 )
{
int V_45 , V_47 = 0 ;
F_6 ( L_8 , V_53 , V_54 ) ;
for ( V_45 = 0 ; V_45 < V_55 && V_53 >= V_54 ;
V_45 ++ , V_47 += V_54 , V_53 -= V_54 ) {
V_8 -> V_48 [ V_45 ] . V_47 = V_47 ;
V_8 -> V_48 [ V_45 ] . V_49 = V_54 ;
}
if ( V_53 && V_45 < V_55 ) {
V_8 -> V_48 [ V_45 ] . V_47 = V_47 ;
V_8 -> V_48 [ V_45 ] . V_49 = V_53 ;
V_45 ++ ;
}
V_8 -> V_46 = V_45 ;
}
static int F_26 ( struct V_9 * V_10 , T_1 V_29 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 ;
unsigned char * V_30 ;
unsigned int V_31 ;
int V_13 , V_32 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
if ( ! V_2 -> V_56 )
return - V_28 ;
V_8 = F_14 ( V_55 , V_29 ) ;
if ( ! V_8 )
return - V_34 ;
V_32 = F_15 ( V_2 -> V_56 -> V_35 ) *
V_55 ;
V_30 = F_16 ( V_32 , V_29 ) ;
if ( ! V_30 ) {
F_17 ( V_8 ) ;
return - V_34 ;
}
V_31 = F_27 ( V_2 -> V_24 , V_2 -> V_56 -> V_36 ) ;
F_19 ( V_8 , V_2 -> V_24 , V_31 , V_30 , V_32 , F_24 ,
V_10 , V_2 -> V_56 -> V_37 ) ;
V_8 -> V_38 = V_39 | V_57 ;
F_25 ( V_8 , V_32 ,
F_15 ( V_2 -> V_56 -> V_35 ) ) ;
F_10 ( V_8 , & V_2 -> V_52 ) ;
V_13 = F_11 ( V_8 , V_29 ) ;
if ( V_13 < 0 ) {
if ( V_13 != - V_27 && V_13 != - V_28 )
F_8 ( L_5 ,
V_10 -> V_14 , V_8 , - V_13 ) ;
F_12 ( V_8 ) ;
}
F_17 ( V_8 ) ;
return V_13 ;
}
static void F_28 ( struct V_8 * V_8 )
{
struct V_58 * V_59 = V_8 -> V_11 ;
struct V_9 * V_10 = (struct V_9 * ) V_59 -> V_60 ;
struct V_1 * V_2 = V_10 -> V_12 ;
F_6 ( L_1 , V_10 -> V_14 ,
V_8 , V_8 -> V_15 , V_8 -> V_16 ) ;
if ( ! F_3 ( V_17 , & V_10 -> V_3 ) )
goto V_61;
if ( ! V_8 -> V_15 )
V_10 -> V_18 . V_62 += V_8 -> V_63 ;
else
V_10 -> V_18 . V_64 ++ ;
V_61:
F_29 ( & V_2 -> V_5 ) ;
V_2 -> V_7 -- ;
F_30 ( & V_2 -> V_5 ) ;
F_31 ( V_8 -> V_65 ) ;
F_32 ( V_59 ) ;
}
static void F_33 ( struct V_8 * V_8 )
{
struct V_58 * V_59 = V_8 -> V_11 ;
struct V_9 * V_10 = (struct V_9 * ) V_59 -> V_60 ;
F_6 ( L_1 , V_10 -> V_14 ,
V_8 , V_8 -> V_15 , V_8 -> V_16 ) ;
if ( ! F_3 ( V_17 , & V_10 -> V_3 ) )
goto V_61;
if ( ! V_8 -> V_15 )
V_10 -> V_18 . V_62 += V_8 -> V_63 ;
else
V_10 -> V_18 . V_64 ++ ;
V_61:
F_31 ( V_8 -> V_65 ) ;
F_32 ( V_59 ) ;
}
static int F_34 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
int V_13 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
V_13 = F_35 ( V_2 -> V_66 ) ;
if ( V_13 < 0 )
return V_13 ;
V_2 -> V_66 -> V_67 = 1 ;
if ( F_36 ( V_17 , & V_10 -> V_3 ) )
goto V_61;
if ( F_36 ( V_23 , & V_2 -> V_3 ) )
goto V_61;
V_13 = F_13 ( V_10 , V_68 ) ;
if ( V_13 < 0 )
goto V_69;
V_13 = F_21 ( V_10 , V_68 ) ;
if ( V_13 < 0 ) {
F_37 ( & V_2 -> V_25 ) ;
goto V_69;
}
F_38 ( V_41 , & V_2 -> V_3 ) ;
F_21 ( V_10 , V_68 ) ;
V_61:
F_39 ( V_2 -> V_66 ) ;
return 0 ;
V_69:
F_40 ( V_23 , & V_2 -> V_3 ) ;
F_40 ( V_17 , & V_10 -> V_3 ) ;
F_39 ( V_2 -> V_66 ) ;
return V_13 ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_25 ) ;
F_37 ( & V_2 -> V_42 ) ;
F_37 ( & V_2 -> V_52 ) ;
}
static int F_42 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
int V_13 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
if ( ! F_43 ( V_17 , & V_10 -> V_3 ) )
return 0 ;
F_44 ( & V_2 -> V_70 ) ;
F_44 ( & V_2 -> V_71 ) ;
F_40 ( V_51 , & V_2 -> V_3 ) ;
F_40 ( V_41 , & V_2 -> V_3 ) ;
F_40 ( V_23 , & V_2 -> V_3 ) ;
F_41 ( V_2 ) ;
V_13 = F_35 ( V_2 -> V_66 ) ;
if ( V_13 < 0 )
goto V_69;
V_2 -> V_66 -> V_67 = 0 ;
F_39 ( V_2 -> V_66 ) ;
V_69:
F_45 ( & V_2 -> V_72 ) ;
return 0 ;
}
static int F_46 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
F_37 ( & V_2 -> V_73 ) ;
return 0 ;
}
static int F_47 ( struct V_58 * V_59 )
{
struct V_9 * V_10 = (struct V_9 * ) V_59 -> V_60 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_74 * V_75 ;
struct V_8 * V_8 ;
unsigned int V_31 ;
int V_13 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
if ( ! F_3 ( V_17 , & V_10 -> V_3 ) )
return - V_76 ;
switch ( F_48 ( V_59 ) -> V_77 ) {
case V_78 :
V_8 = F_14 ( 0 , V_26 ) ;
if ( ! V_8 )
return - V_34 ;
V_75 = F_16 ( sizeof( * V_75 ) , V_26 ) ;
if ( ! V_75 ) {
F_17 ( V_8 ) ;
return - V_34 ;
}
V_75 -> V_79 = V_2 -> V_80 ;
V_75 -> V_81 = 0 ;
V_75 -> V_82 = 0 ;
V_75 -> V_83 = 0 ;
V_75 -> V_84 = F_49 ( V_59 -> V_53 ) ;
V_31 = F_50 ( V_2 -> V_24 , 0x00 ) ;
F_51 ( V_8 , V_2 -> V_24 , V_31 , ( void * ) V_75 ,
V_59 -> V_2 , V_59 -> V_53 , F_28 , V_59 ) ;
V_10 -> V_18 . V_85 ++ ;
break;
case V_40 :
if ( ! V_2 -> V_86 )
return - V_28 ;
V_8 = F_14 ( 0 , V_26 ) ;
if ( ! V_8 )
return - V_34 ;
V_31 = F_52 ( V_2 -> V_24 ,
V_2 -> V_86 -> V_36 ) ;
F_23 ( V_8 , V_2 -> V_24 , V_31 ,
V_59 -> V_2 , V_59 -> V_53 , F_28 , V_59 ) ;
V_10 -> V_18 . V_87 ++ ;
break;
case V_50 :
if ( ! V_2 -> V_88 || V_10 -> V_89 . V_90 < 1 )
return - V_28 ;
V_8 = F_14 ( V_55 , V_26 ) ;
if ( ! V_8 )
return - V_34 ;
V_31 = F_53 ( V_2 -> V_24 ,
V_2 -> V_88 -> V_36 ) ;
F_19 ( V_8 , V_2 -> V_24 , V_31 ,
V_59 -> V_2 , V_59 -> V_53 , F_33 ,
V_59 , V_2 -> V_88 -> V_37 ) ;
V_8 -> V_38 = V_57 ;
F_25 ( V_8 , V_59 -> V_53 ,
F_15 ( V_2 -> V_88 -> V_35 ) ) ;
V_10 -> V_18 . V_91 ++ ;
goto V_92;
default:
return - V_93 ;
}
V_13 = F_1 ( V_2 ) ;
if ( V_13 ) {
F_10 ( V_8 , & V_2 -> V_72 ) ;
F_54 ( & V_2 -> V_71 ) ;
V_13 = 0 ;
goto V_61;
}
V_92:
F_10 ( V_8 , & V_2 -> V_73 ) ;
V_13 = F_11 ( V_8 , V_26 ) ;
if ( V_13 < 0 ) {
if ( V_13 != - V_27 && V_13 != - V_28 )
F_8 ( L_5 ,
V_10 -> V_14 , V_8 , - V_13 ) ;
F_31 ( V_8 -> V_65 ) ;
F_12 ( V_8 ) ;
} else {
F_9 ( V_2 -> V_24 ) ;
}
V_61:
F_17 ( V_8 ) ;
return V_13 ;
}
static void F_55 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
F_31 ( V_2 ) ;
}
static void F_56 ( struct V_9 * V_10 , unsigned int V_94 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
F_6 ( L_9 , V_10 -> V_14 , V_94 ) ;
if ( V_10 -> V_89 . V_90 != V_2 -> V_90 ) {
V_2 -> V_90 = V_10 -> V_89 . V_90 ;
F_54 ( & V_2 -> V_70 ) ;
}
}
static inline int F_57 ( struct V_9 * V_10 , int V_95 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_96 * V_66 = V_2 -> V_97 ;
struct V_98 * V_99 ;
int V_45 , V_13 ;
if ( ! V_2 -> V_97 )
return - V_28 ;
V_13 = F_58 ( V_2 -> V_24 , 1 , V_95 ) ;
if ( V_13 < 0 ) {
F_8 ( L_10 , V_10 -> V_14 , - V_13 ) ;
return V_13 ;
}
V_2 -> V_100 = V_95 ;
V_2 -> V_88 = NULL ;
V_2 -> V_56 = NULL ;
for ( V_45 = 0 ; V_45 < V_66 -> V_101 -> V_102 . V_103 ; V_45 ++ ) {
V_99 = & V_66 -> V_101 -> V_104 [ V_45 ] . V_102 ;
if ( ! V_2 -> V_88 && F_59 ( V_99 ) ) {
V_2 -> V_88 = V_99 ;
continue;
}
if ( ! V_2 -> V_56 && F_60 ( V_99 ) ) {
V_2 -> V_56 = V_99 ;
continue;
}
}
if ( ! V_2 -> V_88 || ! V_2 -> V_56 ) {
F_8 ( L_11 , V_10 -> V_14 ) ;
return - V_28 ;
}
return 0 ;
}
static void F_61 ( struct V_105 * V_70 )
{
struct V_1 * V_2 = F_62 ( V_70 , struct V_1 , V_70 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_13 ;
if ( V_10 -> V_89 . V_90 > 0 ) {
if ( ! F_3 ( V_106 , & V_2 -> V_3 ) ) {
V_13 = F_35 ( V_2 -> V_97 ? V_2 -> V_97 : V_2 -> V_66 ) ;
if ( V_13 < 0 ) {
F_40 ( V_51 , & V_2 -> V_3 ) ;
F_37 ( & V_2 -> V_52 ) ;
return;
}
F_38 ( V_106 , & V_2 -> V_3 ) ;
}
if ( V_2 -> V_100 != 2 ) {
F_40 ( V_51 , & V_2 -> V_3 ) ;
F_37 ( & V_2 -> V_52 ) ;
if ( F_57 ( V_10 , 2 ) < 0 )
return;
}
if ( ! F_36 ( V_51 , & V_2 -> V_3 ) ) {
if ( F_26 ( V_10 , V_68 ) < 0 )
F_40 ( V_51 , & V_2 -> V_3 ) ;
else
F_26 ( V_10 , V_68 ) ;
}
} else {
F_40 ( V_51 , & V_2 -> V_3 ) ;
F_37 ( & V_2 -> V_52 ) ;
F_57 ( V_10 , 0 ) ;
if ( F_43 ( V_106 , & V_2 -> V_3 ) )
F_39 ( V_2 -> V_97 ? V_2 -> V_97 : V_2 -> V_66 ) ;
}
}
static void F_63 ( struct V_105 * V_70 )
{
struct V_1 * V_2 = F_62 ( V_70 , struct V_1 , V_71 ) ;
int V_13 ;
V_13 = F_35 ( V_2 -> V_66 ) ;
if ( V_13 < 0 )
return;
F_39 ( V_2 -> V_66 ) ;
}
static int F_64 ( struct V_96 * V_66 ,
const struct V_107 * V_108 )
{
struct V_98 * V_99 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_45 , V_13 ;
F_6 ( L_12 , V_66 , V_108 ) ;
if ( V_66 -> V_101 -> V_102 . V_109 != 0 )
return - V_28 ;
if ( ! V_108 -> V_110 ) {
const struct V_107 * V_111 ;
V_111 = F_65 ( V_66 , V_112 ) ;
if ( V_111 )
V_108 = V_111 ;
}
if ( V_108 -> V_110 == V_113 )
return - V_28 ;
if ( V_114 && V_108 -> V_110 & V_115 )
return - V_28 ;
if ( V_116 && V_108 -> V_110 & V_117 )
return - V_28 ;
if ( V_118 && V_108 -> V_110 & V_119 )
return - V_28 ;
if ( V_108 -> V_110 & V_120 ) {
struct V_121 * V_24 = F_66 ( V_66 ) ;
if ( F_15 ( V_24 -> V_122 . V_123 ) <= 0x0001 )
return - V_28 ;
}
V_2 = F_67 ( sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 )
return - V_34 ;
for ( V_45 = 0 ; V_45 < V_66 -> V_101 -> V_102 . V_103 ; V_45 ++ ) {
V_99 = & V_66 -> V_101 -> V_104 [ V_45 ] . V_102 ;
if ( ! V_2 -> V_33 && F_68 ( V_99 ) ) {
V_2 -> V_33 = V_99 ;
continue;
}
if ( ! V_2 -> V_86 && F_69 ( V_99 ) ) {
V_2 -> V_86 = V_99 ;
continue;
}
if ( ! V_2 -> V_44 && F_70 ( V_99 ) ) {
V_2 -> V_44 = V_99 ;
continue;
}
}
if ( ! V_2 -> V_33 || ! V_2 -> V_86 || ! V_2 -> V_44 ) {
F_31 ( V_2 ) ;
return - V_28 ;
}
V_2 -> V_80 = V_124 ;
V_2 -> V_24 = F_66 ( V_66 ) ;
V_2 -> V_66 = V_66 ;
F_71 ( & V_2 -> V_125 ) ;
F_72 ( & V_2 -> V_70 , F_61 ) ;
F_72 ( & V_2 -> V_71 , F_63 ) ;
F_71 ( & V_2 -> V_5 ) ;
F_73 ( & V_2 -> V_73 ) ;
F_73 ( & V_2 -> V_25 ) ;
F_73 ( & V_2 -> V_42 ) ;
F_73 ( & V_2 -> V_52 ) ;
F_73 ( & V_2 -> V_72 ) ;
V_10 = F_74 () ;
if ( ! V_10 ) {
F_31 ( V_2 ) ;
return - V_34 ;
}
V_10 -> V_126 = V_127 ;
V_10 -> V_12 = V_2 ;
V_2 -> V_10 = V_10 ;
F_75 ( V_10 , & V_66 -> V_60 ) ;
V_10 -> V_128 = F_34 ;
V_10 -> V_129 = F_42 ;
V_10 -> V_130 = F_46 ;
V_10 -> V_131 = F_47 ;
V_10 -> V_132 = F_55 ;
V_10 -> V_133 = F_56 ;
V_10 -> V_134 = V_135 ;
V_2 -> V_97 = F_76 ( V_2 -> V_24 , 1 ) ;
if ( ! V_136 )
F_38 ( V_137 , & V_10 -> V_138 ) ;
if ( V_139 || V_108 -> V_110 & V_140 ) {
if ( ! V_141 )
F_38 ( V_142 , & V_10 -> V_138 ) ;
}
if ( V_108 -> V_110 & V_143 )
V_2 -> V_97 = NULL ;
if ( V_108 -> V_110 & V_115 ) {
V_2 -> V_80 = V_144 ;
F_38 ( V_137 , & V_10 -> V_138 ) ;
}
if ( V_108 -> V_110 & V_117 ) {
struct V_121 * V_24 = V_2 -> V_24 ;
if ( F_15 ( V_24 -> V_122 . V_123 ) < 0x117 )
F_38 ( V_137 , & V_10 -> V_138 ) ;
}
if ( V_108 -> V_110 & V_119 ) {
struct V_121 * V_24 = V_2 -> V_24 ;
if ( F_15 ( V_24 -> V_122 . V_123 ) > 0x997 )
F_38 ( V_145 , & V_10 -> V_138 ) ;
V_2 -> V_97 = NULL ;
}
if ( V_108 -> V_110 & V_146 ) {
unsigned char V_147 [] = { 0x3b , 0xfc , 0x01 , 0x00 } ;
struct V_58 * V_59 ;
V_59 = F_77 ( sizeof( V_147 ) , V_68 ) ;
if ( V_59 ) {
memcpy ( F_78 ( V_59 , sizeof( V_147 ) ) , V_147 , sizeof( V_147 ) ) ;
F_79 ( & V_10 -> V_148 , V_59 ) ;
}
}
if ( V_2 -> V_97 ) {
V_13 = F_80 ( & V_149 ,
V_2 -> V_97 , V_2 ) ;
if ( V_13 < 0 ) {
F_81 ( V_10 ) ;
F_31 ( V_2 ) ;
return V_13 ;
}
}
V_13 = F_82 ( V_10 ) ;
if ( V_13 < 0 ) {
F_81 ( V_10 ) ;
F_31 ( V_2 ) ;
return V_13 ;
}
F_83 ( V_66 , V_2 ) ;
return 0 ;
}
static void F_84 ( struct V_96 * V_66 )
{
struct V_1 * V_2 = F_85 ( V_66 ) ;
struct V_9 * V_10 ;
F_6 ( L_13 , V_66 ) ;
if ( ! V_2 )
return;
V_10 = V_2 -> V_10 ;
F_86 ( V_10 ) ;
F_83 ( V_2 -> V_66 , NULL ) ;
if ( V_2 -> V_97 )
F_83 ( V_2 -> V_97 , NULL ) ;
F_87 ( V_10 ) ;
if ( V_66 == V_2 -> V_97 )
F_88 ( & V_149 , V_2 -> V_66 ) ;
else if ( V_2 -> V_97 )
F_88 ( & V_149 , V_2 -> V_97 ) ;
F_89 ( V_10 ) ;
F_81 ( V_10 ) ;
}
static int F_90 ( struct V_96 * V_66 , T_2 V_150 )
{
struct V_1 * V_2 = F_85 ( V_66 ) ;
F_6 ( L_13 , V_66 ) ;
if ( V_2 -> V_151 ++ )
return 0 ;
F_91 ( & V_2 -> V_5 ) ;
if ( ! ( F_92 ( V_150 ) && V_2 -> V_7 ) ) {
F_38 ( V_6 , & V_2 -> V_3 ) ;
F_93 ( & V_2 -> V_5 ) ;
} else {
F_93 ( & V_2 -> V_5 ) ;
V_2 -> V_151 -- ;
return - V_76 ;
}
F_44 ( & V_2 -> V_70 ) ;
F_41 ( V_2 ) ;
F_37 ( & V_2 -> V_73 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_8 * V_8 ;
int V_13 ;
while ( ( V_8 = F_95 ( & V_2 -> V_72 ) ) ) {
V_13 = F_11 ( V_8 , V_26 ) ;
if ( V_13 < 0 )
break;
V_2 -> V_7 ++ ;
}
F_45 ( & V_2 -> V_72 ) ;
}
static int F_96 ( struct V_96 * V_66 )
{
struct V_1 * V_2 = F_85 ( V_66 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_13 = 0 ;
F_6 ( L_13 , V_66 ) ;
if ( -- V_2 -> V_151 )
return 0 ;
if ( ! F_3 ( V_17 , & V_10 -> V_3 ) )
goto V_61;
if ( F_3 ( V_23 , & V_2 -> V_3 ) ) {
V_13 = F_13 ( V_10 , V_152 ) ;
if ( V_13 < 0 ) {
F_40 ( V_23 , & V_2 -> V_3 ) ;
goto V_69;
}
}
if ( F_3 ( V_41 , & V_2 -> V_3 ) ) {
V_13 = F_21 ( V_10 , V_152 ) ;
if ( V_13 < 0 ) {
F_40 ( V_41 , & V_2 -> V_3 ) ;
goto V_69;
}
F_21 ( V_10 , V_152 ) ;
}
if ( F_3 ( V_51 , & V_2 -> V_3 ) ) {
if ( F_26 ( V_10 , V_152 ) < 0 )
F_40 ( V_51 , & V_2 -> V_3 ) ;
else
F_26 ( V_10 , V_152 ) ;
}
F_91 ( & V_2 -> V_5 ) ;
F_94 ( V_2 ) ;
F_40 ( V_6 , & V_2 -> V_3 ) ;
F_93 ( & V_2 -> V_5 ) ;
F_54 ( & V_2 -> V_70 ) ;
return 0 ;
V_69:
F_45 ( & V_2 -> V_72 ) ;
V_61:
F_91 ( & V_2 -> V_5 ) ;
F_40 ( V_6 , & V_2 -> V_3 ) ;
F_93 ( & V_2 -> V_5 ) ;
return V_13 ;
}
