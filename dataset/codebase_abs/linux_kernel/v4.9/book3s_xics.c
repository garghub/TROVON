static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_2 V_9 ;
F_2 ( L_1 , V_3 , V_4 ) ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_2 , V_3 ) ;
return - V_10 ;
}
V_6 = & V_8 -> V_11 [ V_9 ] ;
if ( ! V_6 -> V_12 )
return - V_10 ;
if ( ( V_4 == 1 && V_6 -> V_13 ) || V_4 == V_14 )
V_6 -> V_15 = 1 ;
else if ( V_4 == 0 || V_4 == V_16 ) {
V_6 -> V_15 = 0 ;
return 0 ;
}
if ( V_6 -> V_17 )
V_6 -> V_18 = F_4 () ;
F_5 ( V_2 , NULL , V_3 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_19 * V_20 )
{
int V_21 ;
unsigned long V_22 ;
F_7 ( V_22 ) ;
F_8 ( & V_8 -> V_23 ) ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
struct V_5 * V_6 = & V_8 -> V_11 [ V_21 ] ;
if ( ! V_6 -> V_25 )
continue;
F_2 ( L_3 , V_6 -> V_26 ,
V_6 -> V_27 ) ;
F_9 ( & V_8 -> V_23 ) ;
F_10 ( V_22 ) ;
F_5 ( V_2 , V_20 , V_6 -> V_26 ) ;
F_7 ( V_22 ) ;
F_8 ( & V_8 -> V_23 ) ;
}
F_9 ( & V_8 -> V_23 ) ;
F_10 ( V_22 ) ;
}
static bool F_11 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_5 * V_6 ,
T_1 V_28 , T_1 V_27 , T_1 V_29 )
{
bool V_30 ;
unsigned long V_22 ;
F_7 ( V_22 ) ;
F_8 ( & V_8 -> V_23 ) ;
V_6 -> V_28 = V_28 ;
V_6 -> V_27 = V_27 ;
V_6 -> V_29 = V_29 ;
V_30 = false ;
if ( ( V_6 -> V_31 || V_6 -> V_25 ) && V_27 != V_32 ) {
V_6 -> V_31 = 0 ;
V_30 = true ;
}
F_9 ( & V_8 -> V_23 ) ;
F_10 ( V_22 ) ;
return V_30 ;
}
int F_12 ( struct V_33 * V_33 , T_1 V_3 , T_1 V_28 , T_1 V_27 )
{
struct V_1 * V_2 = V_33 -> V_34 . V_2 ;
struct V_19 * V_20 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_35 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
V_20 = F_13 ( V_33 , V_28 ) ;
if ( ! V_20 )
return - V_10 ;
F_2 ( L_4 ,
V_3 , V_28 , V_27 ,
V_6 -> V_31 , V_6 -> V_25 ) ;
if ( F_11 ( V_2 , V_8 , V_6 , V_28 , V_27 , V_27 ) )
F_5 ( V_2 , V_20 , V_3 ) ;
return 0 ;
}
int F_14 ( struct V_33 * V_33 , T_1 V_3 , T_1 * V_28 , T_1 * V_27 )
{
struct V_1 * V_2 = V_33 -> V_34 . V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
unsigned long V_22 ;
if ( ! V_2 )
return - V_35 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_7 ( V_22 ) ;
F_8 ( & V_8 -> V_23 ) ;
* V_28 = V_6 -> V_28 ;
* V_27 = V_6 -> V_27 ;
F_9 ( & V_8 -> V_23 ) ;
F_10 ( V_22 ) ;
return 0 ;
}
int F_15 ( struct V_33 * V_33 , T_1 V_3 )
{
struct V_1 * V_2 = V_33 -> V_34 . V_2 ;
struct V_19 * V_20 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_35 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
V_20 = F_13 ( V_33 , V_6 -> V_28 ) ;
if ( ! V_20 )
return - V_10 ;
if ( F_11 ( V_2 , V_8 , V_6 , V_6 -> V_28 , V_6 -> V_29 ,
V_6 -> V_29 ) )
F_5 ( V_2 , V_20 , V_3 ) ;
return 0 ;
}
int F_16 ( struct V_33 * V_33 , T_1 V_3 )
{
struct V_1 * V_2 = V_33 -> V_34 . V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_35 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_11 ( V_2 , V_8 , V_6 , V_6 -> V_28 , V_32 , V_6 -> V_27 ) ;
return 0 ;
}
static inline bool F_17 ( struct V_19 * V_20 ,
union V_36 V_37 ,
union V_36 V_38 ,
bool V_39 )
{
bool V_40 ;
V_38 . V_41 = ( V_38 . V_42 && ( V_38 . V_43 < V_38 . V_44 ) ) ;
V_40 = F_18 ( & V_20 -> V_6 . V_45 , V_37 . V_45 , V_38 . V_45 ) == V_37 . V_45 ;
if ( ! V_40 )
goto V_46;
F_2 ( L_5 ,
V_20 -> V_47 ,
V_37 . V_44 , V_37 . V_48 , V_37 . V_43 , V_37 . V_42 ,
V_37 . V_49 , V_37 . V_41 ) ;
F_2 ( L_6 ,
V_38 . V_44 , V_38 . V_48 , V_38 . V_43 , V_38 . V_42 ,
V_38 . V_49 , V_38 . V_41 ) ;
if ( V_38 . V_41 ) {
F_19 ( V_20 -> V_50 ,
V_51 ) ;
if ( ! V_39 )
F_20 ( V_20 -> V_50 ) ;
}
V_46:
return V_40 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
T_1 V_52 ;
F_22 () ;
F_23 (icsid, icp->resend_map, xics->max_icsid + 1 ) {
struct V_7 * V_8 = V_2 -> V_8 [ V_52 ] ;
if ( ! F_24 ( V_52 , V_20 -> V_53 ) )
continue;
if ( ! V_8 )
continue;
F_6 ( V_2 , V_8 , V_20 ) ;
}
}
static bool F_25 ( struct V_19 * V_20 , T_1 V_3 , T_3 V_27 ,
T_1 * V_54 )
{
union V_36 V_55 , V_56 ;
bool V_40 ;
F_2 ( L_7 , V_3 , V_27 ,
V_20 -> V_47 ) ;
do {
V_55 = V_56 = F_26 ( V_20 -> V_6 ) ;
* V_54 = 0 ;
V_40 = V_56 . V_44 > V_27 &&
V_56 . V_48 > V_27 &&
V_56 . V_43 > V_27 ;
if ( V_40 ) {
* V_54 = V_56 . V_42 ;
V_56 . V_42 = V_3 ;
V_56 . V_43 = V_27 ;
} else {
V_56 . V_49 = true ;
}
} while ( ! F_17 ( V_20 , V_55 , V_56 , false ) );
return V_40 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_19 * V_20 ,
T_1 V_57 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_54 ;
T_2 V_9 ;
unsigned long V_22 ;
V_58:
V_8 = F_3 ( V_2 , V_57 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_8 , V_57 ) ;
return;
}
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_7 ( V_22 ) ;
F_8 ( & V_8 -> V_23 ) ;
if ( ! V_20 || V_6 -> V_28 != V_20 -> V_47 ) {
V_20 = F_13 ( V_2 -> V_33 , V_6 -> V_28 ) ;
if ( ! V_20 ) {
F_27 ( L_9 ,
V_57 , V_6 -> V_28 ) ;
goto V_59;
}
}
V_6 -> V_25 = 0 ;
if ( V_6 -> V_27 == V_32 ) {
F_2 ( L_10 , V_57 ) ;
V_6 -> V_31 = 1 ;
goto V_59;
}
if ( F_25 ( V_20 , V_57 , V_6 -> V_27 , & V_54 ) ) {
if ( V_54 && V_54 != V_60 ) {
F_9 ( & V_8 -> V_23 ) ;
F_10 ( V_22 ) ;
V_57 = V_54 ;
goto V_58;
}
} else {
F_28 ( V_8 -> V_52 , V_20 -> V_53 ) ;
V_6 -> V_25 = 1 ;
F_29 () ;
if ( ! V_20 -> V_6 . V_49 ) {
F_9 ( & V_8 -> V_23 ) ;
F_10 ( V_22 ) ;
goto V_58;
}
}
V_59:
F_9 ( & V_8 -> V_23 ) ;
F_10 ( V_22 ) ;
}
static void F_30 ( struct V_1 * V_2 , struct V_19 * V_20 ,
T_3 V_61 )
{
union V_36 V_55 , V_56 ;
bool V_25 ;
do {
V_55 = V_56 = F_26 ( V_20 -> V_6 ) ;
V_56 . V_44 = V_61 ;
if ( V_56 . V_48 < V_61 &&
V_56 . V_48 <= V_56 . V_43 ) {
F_31 ( V_56 . V_42 != V_60 &&
V_56 . V_42 != 0 ) ;
V_56 . V_43 = V_56 . V_48 ;
V_56 . V_42 = V_60 ;
}
V_25 = V_56 . V_49 ;
V_56 . V_49 = 0 ;
} while ( ! F_17 ( V_20 , V_55 , V_56 , true ) );
if ( V_25 )
F_21 ( V_2 , V_20 ) ;
}
static T_4 unsigned long F_32 ( struct V_62 * V_50 )
{
union V_36 V_55 , V_56 ;
struct V_19 * V_20 = V_50 -> V_34 . V_20 ;
T_1 V_63 ;
F_33 ( V_20 -> V_50 ,
V_51 ) ;
do {
V_55 = V_56 = F_26 ( V_20 -> V_6 ) ;
V_63 = V_55 . V_42 | ( ( ( T_1 ) V_55 . V_44 ) << 24 ) ;
if ( ! V_55 . V_42 )
break;
V_56 . V_44 = V_56 . V_43 ;
V_56 . V_43 = 0xff ;
V_56 . V_42 = 0 ;
} while ( ! F_17 ( V_20 , V_55 , V_56 , true ) );
F_2 ( L_11 , V_50 -> V_64 , V_63 ) ;
return V_63 ;
}
static T_4 int F_34 ( struct V_62 * V_50 , unsigned long V_28 ,
unsigned long V_48 )
{
union V_36 V_55 , V_56 ;
struct V_1 * V_2 = V_50 -> V_33 -> V_34 . V_2 ;
struct V_19 * V_20 ;
T_1 V_54 ;
bool V_25 ;
bool V_65 ;
F_2 ( L_12 ,
V_50 -> V_64 , V_28 , V_48 ) ;
V_20 = V_50 -> V_34 . V_20 ;
V_65 = V_20 -> V_47 == V_28 ;
if ( ! V_65 ) {
V_20 = F_13 ( V_50 -> V_33 , V_28 ) ;
if ( ! V_20 )
return V_66 ;
}
do {
V_55 = V_56 = F_26 ( V_20 -> V_6 ) ;
V_56 . V_48 = V_48 ;
V_54 = 0 ;
V_25 = false ;
if ( V_48 < V_56 . V_44 ) {
if ( V_48 <= V_56 . V_43 ) {
V_54 = V_56 . V_42 ;
V_56 . V_43 = V_48 ;
V_56 . V_42 = V_60 ;
}
}
if ( V_48 > V_55 . V_48 ) {
V_25 = V_56 . V_49 ;
V_56 . V_49 = 0 ;
}
} while ( ! F_17 ( V_20 , V_55 , V_56 , V_65 ) );
if ( V_54 && V_54 != V_60 )
F_5 ( V_2 , V_20 , V_54 ) ;
if ( V_25 )
F_21 ( V_2 , V_20 ) ;
return V_67 ;
}
static int F_35 ( struct V_62 * V_50 , unsigned long V_28 )
{
union V_36 V_6 ;
struct V_19 * V_20 ;
V_20 = V_50 -> V_34 . V_20 ;
if ( V_20 -> V_47 != V_28 ) {
V_20 = F_13 ( V_50 -> V_33 , V_28 ) ;
if ( ! V_20 )
return V_66 ;
}
V_6 = F_26 ( V_20 -> V_6 ) ;
F_36 ( V_50 , 4 , ( ( T_1 ) V_6 . V_44 << 24 ) | V_6 . V_42 ) ;
F_36 ( V_50 , 5 , V_6 . V_48 ) ;
return V_67 ;
}
static T_4 void F_37 ( struct V_62 * V_50 , unsigned long V_44 )
{
union V_36 V_55 , V_56 ;
struct V_1 * V_2 = V_50 -> V_33 -> V_34 . V_2 ;
struct V_19 * V_20 = V_50 -> V_34 . V_20 ;
T_1 V_54 ;
F_2 ( L_13 , V_50 -> V_64 , V_44 ) ;
if ( V_44 > V_20 -> V_6 . V_44 )
F_30 ( V_2 , V_20 , V_44 ) ;
else if ( V_44 == V_20 -> V_6 . V_44 )
return;
F_33 ( V_20 -> V_50 ,
V_51 ) ;
do {
V_55 = V_56 = F_26 ( V_20 -> V_6 ) ;
V_54 = 0 ;
V_56 . V_44 = V_44 ;
if ( V_44 <= V_56 . V_43 ) {
V_54 = V_56 . V_42 ;
V_56 . V_42 = 0 ;
V_56 . V_43 = 0xff ;
}
} while ( ! F_17 ( V_20 , V_55 , V_56 , true ) );
if ( V_54 && V_54 != V_60 )
F_5 ( V_2 , V_20 , V_54 ) ;
}
static T_4 int F_38 ( struct V_62 * V_50 , unsigned long V_63 )
{
struct V_1 * V_2 = V_50 -> V_33 -> V_34 . V_2 ;
struct V_19 * V_20 = V_50 -> V_34 . V_20 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_1 V_3 = V_63 & 0x00ffffff ;
T_2 V_9 ;
F_2 ( L_14 , V_50 -> V_64 , V_63 ) ;
F_30 ( V_2 , V_20 , V_63 >> 24 ) ;
if ( V_3 == V_60 )
return V_67 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_15 , V_3 ) ;
return V_66 ;
}
V_6 = & V_8 -> V_11 [ V_9 ] ;
if ( V_6 -> V_15 )
F_5 ( V_2 , V_20 , V_3 ) ;
F_39 ( V_50 -> V_33 , 0 , V_3 ) ;
return V_67 ;
}
int F_40 ( struct V_62 * V_50 , T_1 V_68 )
{
struct V_1 * V_2 = V_50 -> V_33 -> V_34 . V_2 ;
struct V_19 * V_20 = V_50 -> V_34 . V_20 ;
F_2 ( L_16 ,
V_68 , V_20 -> V_69 , V_20 -> V_70 . V_45 , V_20 -> V_71 ) ;
if ( V_20 -> V_69 & V_72 ) {
V_20 -> V_73 ++ ;
F_20 ( V_20 -> V_74 ) ;
}
if ( V_20 -> V_69 & V_75 ) {
V_20 -> V_76 ++ ;
F_21 ( V_2 , V_20 -> V_77 ) ;
}
if ( V_20 -> V_69 & V_78 ) {
V_20 -> V_79 ++ ;
F_5 ( V_2 , V_20 , V_20 -> V_80 ) ;
}
if ( V_20 -> V_69 & V_81 ) {
V_20 -> V_82 ++ ;
F_39 ( V_50 -> V_33 , 0 , V_20 -> V_83 ) ;
}
V_20 -> V_69 = 0 ;
return V_67 ;
}
int F_41 ( struct V_62 * V_50 , T_1 V_84 )
{
struct V_1 * V_2 = V_50 -> V_33 -> V_34 . V_2 ;
unsigned long V_85 ;
int V_86 = V_67 ;
if ( ! V_2 || ! V_50 -> V_34 . V_20 )
return V_87 ;
switch ( V_84 ) {
case V_88 :
V_85 = F_32 ( V_50 ) ;
F_36 ( V_50 , 4 , V_85 ) ;
F_36 ( V_50 , 5 , F_42 () ) ;
return V_86 ;
case V_89 :
V_86 = F_35 ( V_50 , F_43 ( V_50 , 4 ) ) ;
return V_86 ;
}
if ( V_2 -> V_90 && F_44 ( V_50 -> V_33 ) )
return F_40 ( V_50 , V_84 ) ;
switch ( V_84 ) {
case V_91 :
V_85 = F_32 ( V_50 ) ;
F_36 ( V_50 , 4 , V_85 ) ;
break;
case V_92 :
F_37 ( V_50 , F_43 ( V_50 , 4 ) ) ;
break;
case V_93 :
V_86 = F_38 ( V_50 , F_43 ( V_50 , 4 ) ) ;
break;
case V_94 :
V_86 = F_34 ( V_50 , F_43 ( V_50 , 4 ) ,
F_43 ( V_50 , 5 ) ) ;
break;
}
return V_86 ;
}
static void F_45 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
int V_21 ;
if ( ! V_98 )
return;
F_46 ( V_96 , L_17 ,
V_98 -> V_99 ) ;
for ( V_21 = 0 ; V_21 < V_98 -> V_99 ; V_21 ++ ) {
F_46 ( V_96 , L_18 ,
V_98 -> V_100 [ V_21 ] . V_101 , V_98 -> V_100 [ V_21 ] . V_102 ) ;
}
}
static int F_47 ( struct V_95 * V_96 , void * V_103 )
{
struct V_1 * V_2 = V_96 -> V_103 ;
struct V_33 * V_33 = V_2 -> V_33 ;
struct V_62 * V_50 ;
int V_52 , V_21 ;
unsigned long V_22 ;
unsigned long V_104 , V_105 ;
unsigned long V_106 , V_107 ;
unsigned long V_108 , V_109 ;
if ( ! V_33 )
return 0 ;
V_104 = 0 ;
V_107 = 0 ;
V_105 = 0 ;
V_106 = 0 ;
V_109 = 0 ;
V_108 = 0 ;
F_45 ( V_96 , V_33 -> V_34 . V_98 ) ;
F_46 ( V_96 , L_19 ) ;
F_48 (i, vcpu, kvm) {
struct V_19 * V_20 = V_50 -> V_34 . V_20 ;
union V_36 V_6 ;
if ( ! V_20 )
continue;
V_6 . V_45 = F_26 ( V_20 -> V_6 . V_45 ) ;
F_46 ( V_96 , L_20 ,
V_20 -> V_47 , V_6 . V_42 ,
V_6 . V_43 , V_6 . V_44 , V_6 . V_48 ,
V_6 . V_41 , V_6 . V_49 ) ;
V_104 += V_20 -> V_73 ;
V_107 += V_20 -> V_82 ;
V_105 += V_20 -> V_76 ;
V_106 += V_20 -> V_79 ;
V_109 += V_20 -> V_110 ;
V_108 += V_20 -> V_111 ;
}
F_46 ( V_96 , L_21 ,
V_104 , V_105 ,
V_106 , V_107 ) ;
F_46 ( V_96 , L_22 ,
V_109 , V_108 ) ;
for ( V_52 = 0 ; V_52 <= V_112 ; V_52 ++ ) {
struct V_7 * V_8 = V_2 -> V_8 [ V_52 ] ;
if ( ! V_8 )
continue;
F_46 ( V_96 , L_23 ,
V_52 ) ;
F_7 ( V_22 ) ;
F_8 ( & V_8 -> V_23 ) ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
struct V_5 * V_3 = & V_8 -> V_11 [ V_21 ] ;
F_46 ( V_96 , L_24 ,
V_3 -> V_26 , V_3 -> V_28 , V_3 -> V_27 ,
V_3 -> V_29 , V_3 -> V_15 ,
V_3 -> V_25 , V_3 -> V_31 ) ;
}
F_9 ( & V_8 -> V_23 ) ;
F_10 ( V_22 ) ;
}
return 0 ;
}
static int F_49 ( struct V_113 * V_113 , struct V_114 * V_114 )
{
return F_50 ( V_114 , F_47 , V_113 -> V_115 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
char * V_116 ;
V_116 = F_52 ( V_117 , L_25 , V_2 ) ;
if ( ! V_116 ) {
F_53 ( L_26 , V_118 ) ;
return;
}
V_2 -> V_119 = F_54 ( V_116 , V_120 , V_121 ,
V_2 , & V_122 ) ;
F_55 ( L_27 , V_118 , V_116 ) ;
F_56 ( V_116 ) ;
}
static struct V_7 * F_57 ( struct V_33 * V_33 ,
struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 ;
int V_21 , V_52 ;
V_52 = V_3 >> V_123 ;
F_58 ( & V_33 -> V_23 ) ;
if ( V_2 -> V_8 [ V_52 ] )
goto V_59;
V_8 = F_59 ( sizeof( struct V_7 ) , V_117 ) ;
if ( ! V_8 )
goto V_59;
V_8 -> V_52 = V_52 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
V_8 -> V_11 [ V_21 ] . V_26 = ( V_52 << V_123 ) | V_21 ;
V_8 -> V_11 [ V_21 ] . V_27 = V_32 ;
V_8 -> V_11 [ V_21 ] . V_29 = V_32 ;
}
F_60 () ;
V_2 -> V_8 [ V_52 ] = V_8 ;
if ( V_52 > V_2 -> V_124 )
V_2 -> V_124 = V_52 ;
V_59:
F_61 ( & V_33 -> V_23 ) ;
return V_2 -> V_8 [ V_52 ] ;
}
int F_62 ( struct V_62 * V_50 , unsigned long V_47 )
{
struct V_19 * V_20 ;
if ( ! V_50 -> V_33 -> V_34 . V_2 )
return - V_35 ;
if ( F_13 ( V_50 -> V_33 , V_47 ) )
return - V_125 ;
V_20 = F_59 ( sizeof( struct V_19 ) , V_117 ) ;
if ( ! V_20 )
return - V_126 ;
V_20 -> V_50 = V_50 ;
V_20 -> V_47 = V_47 ;
V_20 -> V_6 . V_48 = V_32 ;
V_20 -> V_6 . V_43 = V_32 ;
V_50 -> V_34 . V_20 = V_20 ;
F_2 ( L_28 , V_50 -> V_64 ) ;
return 0 ;
}
T_5 F_63 ( struct V_62 * V_50 )
{
struct V_19 * V_20 = V_50 -> V_34 . V_20 ;
union V_36 V_6 ;
if ( ! V_20 )
return 0 ;
V_6 = V_20 -> V_6 ;
return ( ( T_5 ) V_6 . V_44 << V_127 ) |
( ( T_5 ) V_6 . V_42 << V_128 ) |
( ( T_5 ) V_6 . V_48 << V_129 ) |
( ( T_5 ) V_6 . V_43 << V_130 ) ;
}
int F_64 ( struct V_62 * V_50 , T_5 V_131 )
{
struct V_19 * V_20 = V_50 -> V_34 . V_20 ;
struct V_1 * V_2 = V_50 -> V_33 -> V_34 . V_2 ;
union V_36 V_55 , V_56 ;
struct V_7 * V_8 ;
T_3 V_44 , V_48 , V_43 ;
T_1 V_42 ;
T_2 V_9 ;
bool V_25 ;
if ( ! V_20 || ! V_2 )
return - V_132 ;
V_44 = V_131 >> V_127 ;
V_42 = ( V_131 >> V_128 ) &
V_133 ;
V_48 = V_131 >> V_129 ;
V_43 = V_131 >> V_130 ;
if ( V_42 == 0 ) {
if ( V_43 != 0xff )
return - V_10 ;
} else if ( V_42 == V_60 ) {
if ( V_43 != V_48 || V_43 >= V_44 )
return - V_10 ;
} else {
if ( V_43 >= V_48 || V_43 >= V_44 )
return - V_10 ;
V_8 = F_3 ( V_2 , V_42 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
}
V_56 . V_45 = 0 ;
V_56 . V_44 = V_44 ;
V_56 . V_42 = V_42 ;
V_56 . V_48 = V_48 ;
V_56 . V_43 = V_43 ;
F_33 ( V_20 -> V_50 ,
V_51 ) ;
do {
V_55 = F_26 ( V_20 -> V_6 ) ;
if ( V_56 . V_48 <= V_55 . V_48 ) {
V_25 = false ;
V_56 . V_49 = V_55 . V_49 ;
} else {
V_25 = V_55 . V_49 ;
V_56 . V_49 = 0 ;
}
} while ( ! F_17 ( V_20 , V_55 , V_56 , false ) );
if ( V_25 )
F_21 ( V_2 , V_20 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , long V_3 , T_5 V_134 )
{
int V_135 ;
struct V_7 * V_8 ;
struct V_5 * V_136 ;
T_5 T_6 * V_137 = ( T_5 T_6 * ) V_134 ;
T_2 V_138 ;
T_5 V_139 , V_140 ;
unsigned long V_22 ;
V_8 = F_3 ( V_2 , V_3 , & V_138 ) ;
if ( ! V_8 )
return - V_132 ;
V_136 = & V_8 -> V_11 [ V_138 ] ;
F_7 ( V_22 ) ;
F_8 ( & V_8 -> V_23 ) ;
V_135 = - V_132 ;
if ( V_136 -> V_12 ) {
V_139 = V_136 -> V_28 ;
V_140 = V_136 -> V_27 ;
if ( V_140 == V_32 ) {
V_139 |= V_141 ;
V_140 = V_136 -> V_29 ;
}
V_139 |= V_140 << V_142 ;
if ( V_136 -> V_13 ) {
V_139 |= V_143 ;
if ( V_136 -> V_15 )
V_139 |= V_144 ;
} else if ( V_136 -> V_31 || V_136 -> V_25 )
V_139 |= V_144 ;
V_135 = 0 ;
}
F_9 ( & V_8 -> V_23 ) ;
F_10 ( V_22 ) ;
if ( ! V_135 && F_66 ( V_139 , V_137 ) )
V_135 = - V_145 ;
return V_135 ;
}
static int F_67 ( struct V_1 * V_2 , long V_3 , T_5 V_134 )
{
struct V_7 * V_8 ;
struct V_5 * V_136 ;
T_5 T_6 * V_137 = ( T_5 T_6 * ) V_134 ;
T_2 V_138 ;
T_5 V_139 ;
T_3 V_140 ;
T_1 V_28 ;
unsigned long V_22 ;
if ( V_3 < V_146 || V_3 >= V_147 )
return - V_132 ;
V_8 = F_3 ( V_2 , V_3 , & V_138 ) ;
if ( ! V_8 ) {
V_8 = F_57 ( V_2 -> V_33 , V_2 , V_3 ) ;
if ( ! V_8 )
return - V_126 ;
}
V_136 = & V_8 -> V_11 [ V_138 ] ;
if ( F_68 ( V_139 , V_137 ) )
return - V_145 ;
V_28 = V_139 & V_148 ;
V_140 = V_139 >> V_142 ;
if ( V_140 != V_32 &&
F_13 ( V_2 -> V_33 , V_28 ) == NULL )
return - V_10 ;
F_7 ( V_22 ) ;
F_8 ( & V_8 -> V_23 ) ;
V_136 -> V_28 = V_28 ;
V_136 -> V_29 = V_140 ;
if ( V_139 & V_141 )
V_140 = V_32 ;
V_136 -> V_27 = V_140 ;
V_136 -> V_25 = 0 ;
V_136 -> V_31 = 0 ;
V_136 -> V_13 = 0 ;
V_136 -> V_15 = 0 ;
if ( V_139 & V_143 ) {
V_136 -> V_13 = 1 ;
if ( V_139 & V_144 )
V_136 -> V_15 = 1 ;
}
V_136 -> V_12 = 1 ;
F_9 ( & V_8 -> V_23 ) ;
F_10 ( V_22 ) ;
if ( V_139 & V_144 )
F_5 ( V_2 , NULL , V_136 -> V_26 ) ;
return 0 ;
}
int F_69 ( struct V_33 * V_33 , int V_149 , T_1 V_3 , int V_4 ,
bool V_150 )
{
struct V_1 * V_2 = V_33 -> V_34 . V_2 ;
if ( ! V_2 )
return - V_35 ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_70 ( struct V_151 * V_152 ,
struct V_33 * V_33 , int V_149 ,
int V_4 , bool V_150 )
{
return F_69 ( V_33 , V_149 , V_152 -> V_153 ,
V_4 , V_150 ) ;
}
static int F_71 ( struct V_154 * V_155 , struct V_156 * V_157 )
{
struct V_1 * V_2 = V_155 -> V_103 ;
switch ( V_157 -> V_158 ) {
case V_159 :
return F_67 ( V_2 , V_157 -> V_157 , V_157 -> V_134 ) ;
}
return - V_160 ;
}
static int F_72 ( struct V_154 * V_155 , struct V_156 * V_157 )
{
struct V_1 * V_2 = V_155 -> V_103 ;
switch ( V_157 -> V_158 ) {
case V_159 :
return F_65 ( V_2 , V_157 -> V_157 , V_157 -> V_134 ) ;
}
return - V_160 ;
}
static int F_73 ( struct V_154 * V_155 , struct V_156 * V_157 )
{
switch ( V_157 -> V_158 ) {
case V_159 :
if ( V_157 -> V_157 >= V_146 &&
V_157 -> V_157 < V_147 )
return 0 ;
break;
}
return - V_160 ;
}
static void F_74 ( struct V_154 * V_155 )
{
struct V_1 * V_2 = V_155 -> V_103 ;
int V_21 ;
struct V_33 * V_33 = V_2 -> V_33 ;
F_75 ( V_2 -> V_119 ) ;
if ( V_33 )
V_33 -> V_34 . V_2 = NULL ;
for ( V_21 = 0 ; V_21 <= V_2 -> V_124 ; V_21 ++ )
F_56 ( V_2 -> V_8 [ V_21 ] ) ;
F_56 ( V_2 ) ;
F_56 ( V_155 ) ;
}
static int F_76 ( struct V_154 * V_155 , T_1 type )
{
struct V_1 * V_2 ;
struct V_33 * V_33 = V_155 -> V_33 ;
int V_135 = 0 ;
V_2 = F_59 ( sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 )
return - V_126 ;
V_155 -> V_103 = V_2 ;
V_2 -> V_155 = V_155 ;
V_2 -> V_33 = V_33 ;
if ( V_33 -> V_34 . V_2 )
V_135 = - V_125 ;
else
V_33 -> V_34 . V_2 = V_2 ;
if ( V_135 ) {
F_56 ( V_2 ) ;
return V_135 ;
}
#ifdef F_77
if ( F_78 ( V_161 ) ) {
V_2 -> V_90 = V_162 ;
V_2 -> V_163 = V_164 ;
}
#endif
return 0 ;
}
static void F_79 ( struct V_154 * V_155 )
{
struct V_1 * V_2 = (struct V_1 * ) V_155 -> V_103 ;
F_51 ( V_2 ) ;
}
int F_80 ( struct V_154 * V_155 , struct V_62 * V_50 ,
T_1 V_165 )
{
struct V_1 * V_2 = V_155 -> V_103 ;
int V_166 = - V_167 ;
if ( V_155 -> V_168 != & V_169 )
return - V_170 ;
if ( V_2 -> V_33 != V_50 -> V_33 )
return - V_170 ;
if ( V_50 -> V_34 . V_171 )
return - V_167 ;
V_166 = F_62 ( V_50 , V_165 ) ;
if ( ! V_166 )
V_50 -> V_34 . V_171 = V_172 ;
return V_166 ;
}
void F_81 ( struct V_62 * V_50 )
{
if ( ! V_50 -> V_34 . V_20 )
return;
F_56 ( V_50 -> V_34 . V_20 ) ;
V_50 -> V_34 . V_20 = NULL ;
V_50 -> V_34 . V_171 = V_173 ;
}
static int F_82 ( struct V_151 * V_174 ,
struct V_33 * V_33 , int V_149 , int V_4 ,
bool V_150 )
{
return F_69 ( V_33 , V_149 , V_174 -> V_153 , V_4 , V_150 ) ;
}
int F_83 ( struct V_33 * V_33 ,
struct V_151 * V_175 , int V_153 )
{
V_175 -> V_153 = V_153 ;
V_175 -> type = V_176 ;
V_175 -> V_177 = F_82 ;
V_175 -> V_178 . V_178 = 0 ;
V_175 -> V_178 . V_179 = V_153 ;
return 1 ;
}
int F_84 ( struct V_33 * V_33 , unsigned V_178 , unsigned V_179 )
{
return V_179 ;
}
void F_85 ( struct V_33 * V_33 , unsigned long V_3 ,
unsigned long V_17 )
{
struct V_1 * V_2 = V_33 -> V_34 . V_2 ;
struct V_7 * V_8 ;
T_2 V_138 ;
V_8 = F_3 ( V_2 , V_3 , & V_138 ) ;
if ( ! V_8 )
return;
V_8 -> V_11 [ V_138 ] . V_17 = V_17 ;
V_8 -> V_11 [ V_138 ] . V_18 = - 1 ;
}
void F_86 ( struct V_33 * V_33 , unsigned long V_3 ,
unsigned long V_17 )
{
struct V_1 * V_2 = V_33 -> V_34 . V_2 ;
struct V_7 * V_8 ;
T_2 V_138 ;
V_8 = F_3 ( V_2 , V_3 , & V_138 ) ;
if ( ! V_8 )
return;
V_8 -> V_11 [ V_138 ] . V_17 = 0 ;
}
