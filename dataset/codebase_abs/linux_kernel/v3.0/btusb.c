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
if ( V_13 != - V_27 )
F_8 ( L_3 ,
V_10 -> V_14 , V_8 , - V_13 ) ;
F_12 ( V_8 ) ;
}
}
static int F_13 ( struct V_9 * V_10 , T_1 V_28 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 ;
unsigned char * V_29 ;
unsigned int V_30 ;
int V_13 , V_31 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
if ( ! V_2 -> V_32 )
return - V_33 ;
V_8 = F_14 ( 0 , V_28 ) ;
if ( ! V_8 )
return - V_34 ;
V_31 = F_15 ( V_2 -> V_32 -> V_35 ) ;
V_29 = F_16 ( V_31 , V_28 ) ;
if ( ! V_29 ) {
F_17 ( V_8 ) ;
return - V_34 ;
}
V_30 = F_18 ( V_2 -> V_24 , V_2 -> V_32 -> V_36 ) ;
F_19 ( V_8 , V_2 -> V_24 , V_30 , V_29 , V_31 ,
F_5 , V_10 ,
V_2 -> V_32 -> V_37 ) ;
V_8 -> V_38 |= V_39 ;
F_10 ( V_8 , & V_2 -> V_25 ) ;
V_13 = F_11 ( V_8 , V_28 ) ;
if ( V_13 < 0 ) {
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
if ( V_13 != - V_27 )
F_8 ( L_3 ,
V_10 -> V_14 , V_8 , - V_13 ) ;
F_12 ( V_8 ) ;
}
}
static int F_21 ( struct V_9 * V_10 , T_1 V_28 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 ;
unsigned char * V_29 ;
unsigned int V_30 ;
int V_13 , V_31 = V_43 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
if ( ! V_2 -> V_44 )
return - V_33 ;
V_8 = F_14 ( 0 , V_28 ) ;
if ( ! V_8 )
return - V_34 ;
V_29 = F_16 ( V_31 , V_28 ) ;
if ( ! V_29 ) {
F_17 ( V_8 ) ;
return - V_34 ;
}
V_30 = F_22 ( V_2 -> V_24 , V_2 -> V_44 -> V_36 ) ;
F_23 ( V_8 , V_2 -> V_24 , V_30 ,
V_29 , V_31 , F_20 , V_10 ) ;
V_8 -> V_38 |= V_39 ;
F_9 ( V_2 -> V_24 ) ;
F_10 ( V_8 , & V_2 -> V_42 ) ;
V_13 = F_11 ( V_8 , V_28 ) ;
if ( V_13 < 0 ) {
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
if ( V_13 != - V_27 )
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
static int F_26 ( struct V_9 * V_10 , T_1 V_28 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_8 * V_8 ;
unsigned char * V_29 ;
unsigned int V_30 ;
int V_13 , V_31 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
if ( ! V_2 -> V_56 )
return - V_33 ;
V_8 = F_14 ( V_55 , V_28 ) ;
if ( ! V_8 )
return - V_34 ;
V_31 = F_15 ( V_2 -> V_56 -> V_35 ) *
V_55 ;
V_29 = F_16 ( V_31 , V_28 ) ;
if ( ! V_29 ) {
F_17 ( V_8 ) ;
return - V_34 ;
}
V_30 = F_27 ( V_2 -> V_24 , V_2 -> V_56 -> V_36 ) ;
V_8 -> V_57 = V_2 -> V_24 ;
V_8 -> V_30 = V_30 ;
V_8 -> V_11 = V_10 ;
V_8 -> V_58 = F_24 ;
V_8 -> V_59 = V_2 -> V_56 -> V_37 ;
V_8 -> V_38 = V_39 | V_60 ;
V_8 -> V_21 = V_29 ;
V_8 -> V_61 = V_31 ;
F_25 ( V_8 , V_31 ,
F_15 ( V_2 -> V_56 -> V_35 ) ) ;
F_10 ( V_8 , & V_2 -> V_52 ) ;
V_13 = F_11 ( V_8 , V_28 ) ;
if ( V_13 < 0 ) {
F_8 ( L_5 ,
V_10 -> V_14 , V_8 , - V_13 ) ;
F_12 ( V_8 ) ;
}
F_17 ( V_8 ) ;
return V_13 ;
}
static void F_28 ( struct V_8 * V_8 )
{
struct V_62 * V_63 = V_8 -> V_11 ;
struct V_9 * V_10 = (struct V_9 * ) V_63 -> V_57 ;
struct V_1 * V_2 = V_10 -> V_12 ;
F_6 ( L_1 , V_10 -> V_14 ,
V_8 , V_8 -> V_15 , V_8 -> V_16 ) ;
if ( ! F_3 ( V_17 , & V_10 -> V_3 ) )
goto V_64;
if ( ! V_8 -> V_15 )
V_10 -> V_18 . V_65 += V_8 -> V_61 ;
else
V_10 -> V_18 . V_66 ++ ;
V_64:
F_29 ( & V_2 -> V_5 ) ;
V_2 -> V_7 -- ;
F_30 ( & V_2 -> V_5 ) ;
F_31 ( V_8 -> V_67 ) ;
F_32 ( V_63 ) ;
}
static void F_33 ( struct V_8 * V_8 )
{
struct V_62 * V_63 = V_8 -> V_11 ;
struct V_9 * V_10 = (struct V_9 * ) V_63 -> V_57 ;
F_6 ( L_1 , V_10 -> V_14 ,
V_8 , V_8 -> V_15 , V_8 -> V_16 ) ;
if ( ! F_3 ( V_17 , & V_10 -> V_3 ) )
goto V_64;
if ( ! V_8 -> V_15 )
V_10 -> V_18 . V_65 += V_8 -> V_61 ;
else
V_10 -> V_18 . V_66 ++ ;
V_64:
F_31 ( V_8 -> V_67 ) ;
F_32 ( V_63 ) ;
}
static int F_34 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
int V_13 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
V_13 = F_35 ( V_2 -> V_68 ) ;
if ( V_13 < 0 )
return V_13 ;
V_2 -> V_68 -> V_69 = 1 ;
if ( F_36 ( V_17 , & V_10 -> V_3 ) )
goto V_64;
if ( F_36 ( V_23 , & V_2 -> V_3 ) )
goto V_64;
V_13 = F_13 ( V_10 , V_70 ) ;
if ( V_13 < 0 )
goto V_71;
V_13 = F_21 ( V_10 , V_70 ) ;
if ( V_13 < 0 ) {
F_37 ( & V_2 -> V_25 ) ;
goto V_71;
}
F_38 ( V_41 , & V_2 -> V_3 ) ;
F_21 ( V_10 , V_70 ) ;
V_64:
F_39 ( V_2 -> V_68 ) ;
return 0 ;
V_71:
F_40 ( V_23 , & V_2 -> V_3 ) ;
F_40 ( V_17 , & V_10 -> V_3 ) ;
F_39 ( V_2 -> V_68 ) ;
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
F_44 ( & V_2 -> V_72 ) ;
F_44 ( & V_2 -> V_73 ) ;
F_40 ( V_51 , & V_2 -> V_3 ) ;
F_40 ( V_41 , & V_2 -> V_3 ) ;
F_40 ( V_23 , & V_2 -> V_3 ) ;
F_41 ( V_2 ) ;
V_13 = F_35 ( V_2 -> V_68 ) ;
if ( V_13 < 0 )
goto V_71;
V_2 -> V_68 -> V_69 = 0 ;
F_39 ( V_2 -> V_68 ) ;
V_71:
F_45 ( & V_2 -> V_74 ) ;
return 0 ;
}
static int F_46 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
F_37 ( & V_2 -> V_75 ) ;
return 0 ;
}
static int F_47 ( struct V_62 * V_63 )
{
struct V_9 * V_10 = (struct V_9 * ) V_63 -> V_57 ;
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_76 * V_77 ;
struct V_8 * V_8 ;
unsigned int V_30 ;
int V_13 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
if ( ! F_3 ( V_17 , & V_10 -> V_3 ) )
return - V_78 ;
switch ( F_48 ( V_63 ) -> V_79 ) {
case V_80 :
V_8 = F_14 ( 0 , V_26 ) ;
if ( ! V_8 )
return - V_34 ;
V_77 = F_16 ( sizeof( * V_77 ) , V_26 ) ;
if ( ! V_77 ) {
F_17 ( V_8 ) ;
return - V_34 ;
}
V_77 -> V_81 = V_2 -> V_82 ;
V_77 -> V_83 = 0 ;
V_77 -> V_84 = 0 ;
V_77 -> V_85 = 0 ;
V_77 -> V_86 = F_49 ( V_63 -> V_53 ) ;
V_30 = F_50 ( V_2 -> V_24 , 0x00 ) ;
F_51 ( V_8 , V_2 -> V_24 , V_30 , ( void * ) V_77 ,
V_63 -> V_2 , V_63 -> V_53 , F_28 , V_63 ) ;
V_10 -> V_18 . V_87 ++ ;
break;
case V_40 :
if ( ! V_2 -> V_88 || ( V_10 -> V_89 . V_90 < 1 &&
V_10 -> V_89 . V_91 < 1 ) )
return - V_33 ;
V_8 = F_14 ( 0 , V_26 ) ;
if ( ! V_8 )
return - V_34 ;
V_30 = F_52 ( V_2 -> V_24 ,
V_2 -> V_88 -> V_36 ) ;
F_23 ( V_8 , V_2 -> V_24 , V_30 ,
V_63 -> V_2 , V_63 -> V_53 , F_28 , V_63 ) ;
V_10 -> V_18 . V_92 ++ ;
break;
case V_50 :
if ( ! V_2 -> V_93 || V_10 -> V_89 . V_94 < 1 )
return - V_33 ;
V_8 = F_14 ( V_55 , V_26 ) ;
if ( ! V_8 )
return - V_34 ;
V_30 = F_53 ( V_2 -> V_24 ,
V_2 -> V_93 -> V_36 ) ;
F_19 ( V_8 , V_2 -> V_24 , V_30 ,
V_63 -> V_2 , V_63 -> V_53 , F_33 ,
V_63 , V_2 -> V_93 -> V_37 ) ;
V_8 -> V_38 = V_60 ;
F_25 ( V_8 , V_63 -> V_53 ,
F_15 ( V_2 -> V_93 -> V_35 ) ) ;
V_10 -> V_18 . V_95 ++ ;
goto V_96;
default:
return - V_97 ;
}
V_13 = F_1 ( V_2 ) ;
if ( V_13 ) {
F_10 ( V_8 , & V_2 -> V_74 ) ;
F_54 ( & V_2 -> V_73 ) ;
V_13 = 0 ;
goto V_64;
}
V_96:
F_10 ( V_8 , & V_2 -> V_75 ) ;
V_13 = F_11 ( V_8 , V_26 ) ;
if ( V_13 < 0 ) {
F_8 ( L_9 , V_10 -> V_14 , V_8 ) ;
F_31 ( V_8 -> V_67 ) ;
F_12 ( V_8 ) ;
} else {
F_9 ( V_2 -> V_24 ) ;
}
F_17 ( V_8 ) ;
V_64:
return V_13 ;
}
static void F_55 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
F_6 ( L_4 , V_10 -> V_14 ) ;
F_31 ( V_2 ) ;
}
static void F_56 ( struct V_9 * V_10 , unsigned int V_98 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
F_6 ( L_10 , V_10 -> V_14 , V_98 ) ;
if ( V_10 -> V_89 . V_94 != V_2 -> V_94 ) {
V_2 -> V_94 = V_10 -> V_89 . V_94 ;
F_54 ( & V_2 -> V_72 ) ;
}
}
static inline int F_57 ( struct V_9 * V_10 , int V_99 )
{
struct V_1 * V_2 = V_10 -> V_12 ;
struct V_100 * V_68 = V_2 -> V_101 ;
struct V_102 * V_103 ;
int V_45 , V_13 ;
if ( ! V_2 -> V_101 )
return - V_33 ;
V_13 = F_58 ( V_2 -> V_24 , 1 , V_99 ) ;
if ( V_13 < 0 ) {
F_8 ( L_11 , V_10 -> V_14 , - V_13 ) ;
return V_13 ;
}
V_2 -> V_104 = V_99 ;
V_2 -> V_93 = NULL ;
V_2 -> V_56 = NULL ;
for ( V_45 = 0 ; V_45 < V_68 -> V_105 -> V_106 . V_107 ; V_45 ++ ) {
V_103 = & V_68 -> V_105 -> V_108 [ V_45 ] . V_106 ;
if ( ! V_2 -> V_93 && F_59 ( V_103 ) ) {
V_2 -> V_93 = V_103 ;
continue;
}
if ( ! V_2 -> V_56 && F_60 ( V_103 ) ) {
V_2 -> V_56 = V_103 ;
continue;
}
}
if ( ! V_2 -> V_93 || ! V_2 -> V_56 ) {
F_8 ( L_12 , V_10 -> V_14 ) ;
return - V_33 ;
}
return 0 ;
}
static void F_61 ( struct V_109 * V_72 )
{
struct V_1 * V_2 = F_62 ( V_72 , struct V_1 , V_72 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_13 ;
if ( V_10 -> V_89 . V_94 > 0 ) {
if ( ! F_3 ( V_110 , & V_2 -> V_3 ) ) {
V_13 = F_35 ( V_2 -> V_101 ? V_2 -> V_101 : V_2 -> V_68 ) ;
if ( V_13 < 0 ) {
F_40 ( V_51 , & V_2 -> V_3 ) ;
F_37 ( & V_2 -> V_52 ) ;
return;
}
F_38 ( V_110 , & V_2 -> V_3 ) ;
}
if ( V_2 -> V_104 != 2 ) {
F_40 ( V_51 , & V_2 -> V_3 ) ;
F_37 ( & V_2 -> V_52 ) ;
if ( F_57 ( V_10 , 2 ) < 0 )
return;
}
if ( ! F_36 ( V_51 , & V_2 -> V_3 ) ) {
if ( F_26 ( V_10 , V_70 ) < 0 )
F_40 ( V_51 , & V_2 -> V_3 ) ;
else
F_26 ( V_10 , V_70 ) ;
}
} else {
F_40 ( V_51 , & V_2 -> V_3 ) ;
F_37 ( & V_2 -> V_52 ) ;
F_57 ( V_10 , 0 ) ;
if ( F_43 ( V_110 , & V_2 -> V_3 ) )
F_39 ( V_2 -> V_101 ? V_2 -> V_101 : V_2 -> V_68 ) ;
}
}
static void F_63 ( struct V_109 * V_72 )
{
struct V_1 * V_2 = F_62 ( V_72 , struct V_1 , V_73 ) ;
int V_13 ;
V_13 = F_35 ( V_2 -> V_68 ) ;
if ( V_13 < 0 )
return;
F_39 ( V_2 -> V_68 ) ;
}
static int F_64 ( struct V_100 * V_68 ,
const struct V_111 * V_112 )
{
struct V_102 * V_103 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_45 , V_13 ;
F_6 ( L_13 , V_68 , V_112 ) ;
if ( V_68 -> V_105 -> V_106 . V_113 != 0 )
return - V_33 ;
if ( ! V_112 -> V_114 ) {
const struct V_111 * V_115 ;
V_115 = F_65 ( V_68 , V_116 ) ;
if ( V_115 )
V_112 = V_115 ;
}
if ( V_112 -> V_114 == V_117 )
return - V_33 ;
if ( V_118 && V_112 -> V_114 & V_119 )
return - V_33 ;
if ( V_120 && V_112 -> V_114 & V_121 )
return - V_33 ;
if ( V_122 && V_112 -> V_114 & V_123 )
return - V_33 ;
V_2 = F_66 ( sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_34 ;
for ( V_45 = 0 ; V_45 < V_68 -> V_105 -> V_106 . V_107 ; V_45 ++ ) {
V_103 = & V_68 -> V_105 -> V_108 [ V_45 ] . V_106 ;
if ( ! V_2 -> V_32 && F_67 ( V_103 ) ) {
V_2 -> V_32 = V_103 ;
continue;
}
if ( ! V_2 -> V_88 && F_68 ( V_103 ) ) {
V_2 -> V_88 = V_103 ;
continue;
}
if ( ! V_2 -> V_44 && F_69 ( V_103 ) ) {
V_2 -> V_44 = V_103 ;
continue;
}
}
if ( ! V_2 -> V_32 || ! V_2 -> V_88 || ! V_2 -> V_44 ) {
F_31 ( V_2 ) ;
return - V_33 ;
}
V_2 -> V_82 = V_124 ;
V_2 -> V_24 = F_70 ( V_68 ) ;
V_2 -> V_68 = V_68 ;
F_71 ( & V_2 -> V_125 ) ;
F_72 ( & V_2 -> V_72 , F_61 ) ;
F_72 ( & V_2 -> V_73 , F_63 ) ;
F_71 ( & V_2 -> V_5 ) ;
F_73 ( & V_2 -> V_75 ) ;
F_73 ( & V_2 -> V_25 ) ;
F_73 ( & V_2 -> V_42 ) ;
F_73 ( & V_2 -> V_52 ) ;
F_73 ( & V_2 -> V_74 ) ;
V_10 = F_74 () ;
if ( ! V_10 ) {
F_31 ( V_2 ) ;
return - V_34 ;
}
V_10 -> V_126 = V_127 ;
V_10 -> V_12 = V_2 ;
V_2 -> V_10 = V_10 ;
F_75 ( V_10 , & V_68 -> V_57 ) ;
V_10 -> V_128 = F_34 ;
V_10 -> V_129 = F_42 ;
V_10 -> V_130 = F_46 ;
V_10 -> V_131 = F_47 ;
V_10 -> V_132 = F_55 ;
V_10 -> V_133 = F_56 ;
V_10 -> V_134 = V_135 ;
V_2 -> V_101 = F_76 ( V_2 -> V_24 , 1 ) ;
if ( ! V_136 )
F_38 ( V_137 , & V_10 -> V_138 ) ;
if ( V_139 || V_112 -> V_114 & V_140 ) {
if ( ! V_141 )
F_38 ( V_142 , & V_10 -> V_138 ) ;
}
if ( V_112 -> V_114 & V_143 )
V_2 -> V_101 = NULL ;
if ( V_112 -> V_114 & V_119 ) {
V_2 -> V_82 = V_144 ;
F_38 ( V_137 , & V_10 -> V_138 ) ;
}
if ( V_112 -> V_114 & V_121 ) {
struct V_145 * V_24 = V_2 -> V_24 ;
if ( F_15 ( V_24 -> V_146 . V_147 ) < 0x117 )
F_38 ( V_137 , & V_10 -> V_138 ) ;
}
if ( V_112 -> V_114 & V_123 ) {
struct V_145 * V_24 = V_2 -> V_24 ;
if ( F_15 ( V_24 -> V_146 . V_147 ) > 0x997 )
F_38 ( V_148 , & V_10 -> V_138 ) ;
V_2 -> V_101 = NULL ;
}
if ( V_112 -> V_114 & V_149 ) {
unsigned char V_150 [] = { 0x3b , 0xfc , 0x01 , 0x00 } ;
struct V_62 * V_63 ;
V_63 = F_77 ( sizeof( V_150 ) , V_70 ) ;
if ( V_63 ) {
memcpy ( F_78 ( V_63 , sizeof( V_150 ) ) , V_150 , sizeof( V_150 ) ) ;
F_79 ( & V_10 -> V_151 , V_63 ) ;
}
}
if ( V_2 -> V_101 ) {
V_13 = F_80 ( & V_152 ,
V_2 -> V_101 , V_2 ) ;
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
F_83 ( V_68 , V_2 ) ;
return 0 ;
}
static void F_84 ( struct V_100 * V_68 )
{
struct V_1 * V_2 = F_85 ( V_68 ) ;
struct V_9 * V_10 ;
F_6 ( L_14 , V_68 ) ;
if ( ! V_2 )
return;
V_10 = V_2 -> V_10 ;
F_86 ( V_10 ) ;
F_83 ( V_2 -> V_68 , NULL ) ;
if ( V_2 -> V_101 )
F_83 ( V_2 -> V_101 , NULL ) ;
F_87 ( V_10 ) ;
if ( V_68 == V_2 -> V_101 )
F_88 ( & V_152 , V_2 -> V_68 ) ;
else if ( V_2 -> V_101 )
F_88 ( & V_152 , V_2 -> V_101 ) ;
F_89 ( V_10 ) ;
F_81 ( V_10 ) ;
}
static int F_90 ( struct V_100 * V_68 , T_2 V_153 )
{
struct V_1 * V_2 = F_85 ( V_68 ) ;
F_6 ( L_14 , V_68 ) ;
if ( V_2 -> V_154 ++ )
return 0 ;
F_91 ( & V_2 -> V_5 ) ;
if ( ! ( ( V_153 . V_155 & V_156 ) && V_2 -> V_7 ) ) {
F_38 ( V_6 , & V_2 -> V_3 ) ;
F_92 ( & V_2 -> V_5 ) ;
} else {
F_92 ( & V_2 -> V_5 ) ;
V_2 -> V_154 -- ;
return - V_78 ;
}
F_44 ( & V_2 -> V_72 ) ;
F_41 ( V_2 ) ;
F_37 ( & V_2 -> V_75 ) ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_8 * V_8 ;
int V_13 ;
while ( ( V_8 = F_94 ( & V_2 -> V_74 ) ) ) {
V_13 = F_11 ( V_8 , V_26 ) ;
if ( V_13 < 0 )
break;
V_2 -> V_7 ++ ;
}
F_45 ( & V_2 -> V_74 ) ;
}
static int F_95 ( struct V_100 * V_68 )
{
struct V_1 * V_2 = F_85 ( V_68 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_13 = 0 ;
F_6 ( L_14 , V_68 ) ;
if ( -- V_2 -> V_154 )
return 0 ;
if ( ! F_3 ( V_17 , & V_10 -> V_3 ) )
goto V_64;
if ( F_3 ( V_23 , & V_2 -> V_3 ) ) {
V_13 = F_13 ( V_10 , V_157 ) ;
if ( V_13 < 0 ) {
F_40 ( V_23 , & V_2 -> V_3 ) ;
goto V_71;
}
}
if ( F_3 ( V_41 , & V_2 -> V_3 ) ) {
V_13 = F_21 ( V_10 , V_157 ) ;
if ( V_13 < 0 ) {
F_40 ( V_41 , & V_2 -> V_3 ) ;
goto V_71;
}
F_21 ( V_10 , V_157 ) ;
}
if ( F_3 ( V_51 , & V_2 -> V_3 ) ) {
if ( F_26 ( V_10 , V_157 ) < 0 )
F_40 ( V_51 , & V_2 -> V_3 ) ;
else
F_26 ( V_10 , V_157 ) ;
}
F_91 ( & V_2 -> V_5 ) ;
F_93 ( V_2 ) ;
F_40 ( V_6 , & V_2 -> V_3 ) ;
F_92 ( & V_2 -> V_5 ) ;
F_54 ( & V_2 -> V_72 ) ;
return 0 ;
V_71:
F_45 ( & V_2 -> V_74 ) ;
V_64:
F_91 ( & V_2 -> V_5 ) ;
F_40 ( V_6 , & V_2 -> V_3 ) ;
F_92 ( & V_2 -> V_5 ) ;
return V_13 ;
}
static int T_3 F_96 ( void )
{
F_97 ( L_15 , V_158 ) ;
return F_98 ( & V_152 ) ;
}
static void T_4 F_99 ( void )
{
F_100 ( & V_152 ) ;
}
