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
F_4 ( V_2 , NULL , V_3 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_17 * V_18 )
{
int V_19 ;
unsigned long V_20 ;
F_6 ( V_20 ) ;
F_7 ( & V_8 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_5 * V_6 = & V_8 -> V_11 [ V_19 ] ;
if ( ! V_6 -> V_23 )
continue;
F_2 ( L_3 , V_6 -> V_24 ,
V_6 -> V_25 ) ;
F_8 ( & V_8 -> V_21 ) ;
F_9 ( V_20 ) ;
F_4 ( V_2 , V_18 , V_6 -> V_24 ) ;
F_6 ( V_20 ) ;
F_7 ( & V_8 -> V_21 ) ;
}
F_8 ( & V_8 -> V_21 ) ;
F_9 ( V_20 ) ;
}
static bool F_10 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_5 * V_6 ,
T_1 V_26 , T_1 V_25 , T_1 V_27 )
{
bool V_28 ;
unsigned long V_20 ;
F_6 ( V_20 ) ;
F_7 ( & V_8 -> V_21 ) ;
V_6 -> V_26 = V_26 ;
V_6 -> V_25 = V_25 ;
V_6 -> V_27 = V_27 ;
V_28 = false ;
if ( ( V_6 -> V_29 || V_6 -> V_23 ) && V_25 != V_30 ) {
V_6 -> V_29 = 0 ;
V_28 = true ;
}
F_8 ( & V_8 -> V_21 ) ;
F_9 ( V_20 ) ;
return V_28 ;
}
int F_11 ( struct V_31 * V_31 , T_1 V_3 , T_1 V_26 , T_1 V_25 )
{
struct V_1 * V_2 = V_31 -> V_32 . V_2 ;
struct V_17 * V_18 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_33 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
V_18 = F_12 ( V_31 , V_26 ) ;
if ( ! V_18 )
return - V_10 ;
F_2 ( L_4 ,
V_3 , V_26 , V_25 ,
V_6 -> V_29 , V_6 -> V_23 ) ;
if ( F_10 ( V_2 , V_8 , V_6 , V_26 , V_25 , V_25 ) )
F_4 ( V_2 , V_18 , V_3 ) ;
return 0 ;
}
int F_13 ( struct V_31 * V_31 , T_1 V_3 , T_1 * V_26 , T_1 * V_25 )
{
struct V_1 * V_2 = V_31 -> V_32 . V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
unsigned long V_20 ;
if ( ! V_2 )
return - V_33 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_6 ( V_20 ) ;
F_7 ( & V_8 -> V_21 ) ;
* V_26 = V_6 -> V_26 ;
* V_25 = V_6 -> V_25 ;
F_8 ( & V_8 -> V_21 ) ;
F_9 ( V_20 ) ;
return 0 ;
}
int F_14 ( struct V_31 * V_31 , T_1 V_3 )
{
struct V_1 * V_2 = V_31 -> V_32 . V_2 ;
struct V_17 * V_18 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_33 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
V_18 = F_12 ( V_31 , V_6 -> V_26 ) ;
if ( ! V_18 )
return - V_10 ;
if ( F_10 ( V_2 , V_8 , V_6 , V_6 -> V_26 , V_6 -> V_27 ,
V_6 -> V_27 ) )
F_4 ( V_2 , V_18 , V_3 ) ;
return 0 ;
}
int F_15 ( struct V_31 * V_31 , T_1 V_3 )
{
struct V_1 * V_2 = V_31 -> V_32 . V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_33 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_10 ( V_2 , V_8 , V_6 , V_6 -> V_26 , V_30 , V_6 -> V_25 ) ;
return 0 ;
}
static inline bool F_16 ( struct V_17 * V_18 ,
union V_34 V_35 ,
union V_34 V_36 ,
bool V_37 )
{
bool V_38 ;
V_36 . V_39 = ( V_36 . V_40 && ( V_36 . V_41 < V_36 . V_42 ) ) ;
V_38 = F_17 ( & V_18 -> V_6 . V_43 , V_35 . V_43 , V_36 . V_43 ) == V_35 . V_43 ;
if ( ! V_38 )
goto V_44;
F_2 ( L_5 ,
V_18 -> V_45 ,
V_35 . V_42 , V_35 . V_46 , V_35 . V_41 , V_35 . V_40 ,
V_35 . V_47 , V_35 . V_39 ) ;
F_2 ( L_6 ,
V_36 . V_42 , V_36 . V_46 , V_36 . V_41 , V_36 . V_40 ,
V_36 . V_47 , V_36 . V_39 ) ;
if ( V_36 . V_39 ) {
F_18 ( V_18 -> V_48 ,
V_49 ) ;
if ( ! V_37 )
F_19 ( V_18 -> V_48 ) ;
}
V_44:
return V_38 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
T_1 V_50 ;
F_21 () ;
F_22 (icsid, icp->resend_map, xics->max_icsid + 1 ) {
struct V_7 * V_8 = V_2 -> V_8 [ V_50 ] ;
if ( ! F_23 ( V_50 , V_18 -> V_51 ) )
continue;
if ( ! V_8 )
continue;
F_5 ( V_2 , V_8 , V_18 ) ;
}
}
static bool F_24 ( struct V_17 * V_18 , T_1 V_3 , T_3 V_25 ,
T_1 * V_52 )
{
union V_34 V_53 , V_54 ;
bool V_38 ;
F_2 ( L_7 , V_3 , V_25 ,
V_18 -> V_45 ) ;
do {
V_53 = V_54 = F_25 ( V_18 -> V_6 ) ;
* V_52 = 0 ;
V_38 = V_54 . V_42 > V_25 &&
V_54 . V_46 > V_25 &&
V_54 . V_41 > V_25 ;
if ( V_38 ) {
* V_52 = V_54 . V_40 ;
V_54 . V_40 = V_3 ;
V_54 . V_41 = V_25 ;
} else {
V_54 . V_47 = true ;
}
} while ( ! F_16 ( V_18 , V_53 , V_54 , false ) );
return V_38 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_17 * V_18 ,
T_1 V_55 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_52 ;
T_2 V_9 ;
unsigned long V_20 ;
V_56:
V_8 = F_3 ( V_2 , V_55 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_8 , V_55 ) ;
return;
}
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_6 ( V_20 ) ;
F_7 ( & V_8 -> V_21 ) ;
if ( ! V_18 || V_6 -> V_26 != V_18 -> V_45 ) {
V_18 = F_12 ( V_2 -> V_31 , V_6 -> V_26 ) ;
if ( ! V_18 ) {
F_26 ( L_9 ,
V_55 , V_6 -> V_26 ) ;
goto V_57;
}
}
V_6 -> V_23 = 0 ;
if ( V_6 -> V_25 == V_30 ) {
F_2 ( L_10 , V_55 ) ;
V_6 -> V_29 = 1 ;
goto V_57;
}
if ( F_24 ( V_18 , V_55 , V_6 -> V_25 , & V_52 ) ) {
if ( V_52 && V_52 != V_58 ) {
F_8 ( & V_8 -> V_21 ) ;
F_9 ( V_20 ) ;
V_55 = V_52 ;
goto V_56;
}
} else {
F_27 ( V_8 -> V_50 , V_18 -> V_51 ) ;
V_6 -> V_23 = 1 ;
F_28 () ;
if ( ! V_18 -> V_6 . V_47 ) {
F_8 ( & V_8 -> V_21 ) ;
F_9 ( V_20 ) ;
goto V_56;
}
}
V_57:
F_8 ( & V_8 -> V_21 ) ;
F_9 ( V_20 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_17 * V_18 ,
T_3 V_59 )
{
union V_34 V_53 , V_54 ;
bool V_23 ;
do {
V_53 = V_54 = F_25 ( V_18 -> V_6 ) ;
V_54 . V_42 = V_59 ;
if ( V_54 . V_46 < V_59 &&
V_54 . V_46 <= V_54 . V_41 ) {
F_30 ( V_54 . V_40 != V_58 &&
V_54 . V_40 != 0 ) ;
V_54 . V_41 = V_54 . V_46 ;
V_54 . V_40 = V_58 ;
}
V_23 = V_54 . V_47 ;
V_54 . V_47 = 0 ;
} while ( ! F_16 ( V_18 , V_53 , V_54 , true ) );
if ( V_23 )
F_20 ( V_2 , V_18 ) ;
}
static T_4 unsigned long F_31 ( struct V_60 * V_48 )
{
union V_34 V_53 , V_54 ;
struct V_17 * V_18 = V_48 -> V_32 . V_18 ;
T_1 V_61 ;
F_32 ( V_18 -> V_48 ,
V_49 ) ;
do {
V_53 = V_54 = F_25 ( V_18 -> V_6 ) ;
V_61 = V_53 . V_40 | ( ( ( T_1 ) V_53 . V_42 ) << 24 ) ;
if ( ! V_53 . V_40 )
break;
V_54 . V_42 = V_54 . V_41 ;
V_54 . V_41 = 0xff ;
V_54 . V_40 = 0 ;
} while ( ! F_16 ( V_18 , V_53 , V_54 , true ) );
F_2 ( L_11 , V_48 -> V_62 , V_61 ) ;
return V_61 ;
}
static T_4 int F_33 ( struct V_60 * V_48 , unsigned long V_26 ,
unsigned long V_46 )
{
union V_34 V_53 , V_54 ;
struct V_1 * V_2 = V_48 -> V_31 -> V_32 . V_2 ;
struct V_17 * V_18 ;
T_1 V_52 ;
bool V_23 ;
bool V_63 ;
F_2 ( L_12 ,
V_48 -> V_62 , V_26 , V_46 ) ;
V_18 = V_48 -> V_32 . V_18 ;
V_63 = V_18 -> V_45 == V_26 ;
if ( ! V_63 ) {
V_18 = F_12 ( V_48 -> V_31 , V_26 ) ;
if ( ! V_18 )
return V_64 ;
}
do {
V_53 = V_54 = F_25 ( V_18 -> V_6 ) ;
V_54 . V_46 = V_46 ;
V_52 = 0 ;
V_23 = false ;
if ( V_46 < V_54 . V_42 ) {
if ( V_46 <= V_54 . V_41 ) {
V_52 = V_54 . V_40 ;
V_54 . V_41 = V_46 ;
V_54 . V_40 = V_58 ;
}
}
if ( V_46 > V_53 . V_46 ) {
V_23 = V_54 . V_47 ;
V_54 . V_47 = 0 ;
}
} while ( ! F_16 ( V_18 , V_53 , V_54 , V_63 ) );
if ( V_52 && V_52 != V_58 )
F_4 ( V_2 , V_18 , V_52 ) ;
if ( V_23 )
F_20 ( V_2 , V_18 ) ;
return V_65 ;
}
static int F_34 ( struct V_60 * V_48 , unsigned long V_26 )
{
union V_34 V_6 ;
struct V_17 * V_18 ;
V_18 = V_48 -> V_32 . V_18 ;
if ( V_18 -> V_45 != V_26 ) {
V_18 = F_12 ( V_48 -> V_31 , V_26 ) ;
if ( ! V_18 )
return V_64 ;
}
V_6 = F_25 ( V_18 -> V_6 ) ;
F_35 ( V_48 , 4 , ( ( T_1 ) V_6 . V_42 << 24 ) | V_6 . V_40 ) ;
F_35 ( V_48 , 5 , V_6 . V_46 ) ;
return V_65 ;
}
static T_4 void F_36 ( struct V_60 * V_48 , unsigned long V_42 )
{
union V_34 V_53 , V_54 ;
struct V_1 * V_2 = V_48 -> V_31 -> V_32 . V_2 ;
struct V_17 * V_18 = V_48 -> V_32 . V_18 ;
T_1 V_52 ;
F_2 ( L_13 , V_48 -> V_62 , V_42 ) ;
if ( V_42 > V_18 -> V_6 . V_42 )
F_29 ( V_2 , V_18 , V_42 ) ;
else if ( V_42 == V_18 -> V_6 . V_42 )
return;
F_32 ( V_18 -> V_48 ,
V_49 ) ;
do {
V_53 = V_54 = F_25 ( V_18 -> V_6 ) ;
V_52 = 0 ;
V_54 . V_42 = V_42 ;
if ( V_42 <= V_54 . V_41 ) {
V_52 = V_54 . V_40 ;
V_54 . V_40 = 0 ;
V_54 . V_41 = 0xff ;
}
} while ( ! F_16 ( V_18 , V_53 , V_54 , true ) );
if ( V_52 && V_52 != V_58 )
F_4 ( V_2 , V_18 , V_52 ) ;
}
static T_4 int F_37 ( struct V_60 * V_48 , unsigned long V_61 )
{
struct V_1 * V_2 = V_48 -> V_31 -> V_32 . V_2 ;
struct V_17 * V_18 = V_48 -> V_32 . V_18 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_1 V_3 = V_61 & 0x00ffffff ;
T_2 V_9 ;
F_2 ( L_14 , V_48 -> V_62 , V_61 ) ;
F_29 ( V_2 , V_18 , V_61 >> 24 ) ;
if ( V_3 == V_58 )
return V_65 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_15 , V_3 ) ;
return V_64 ;
}
V_6 = & V_8 -> V_11 [ V_9 ] ;
if ( V_6 -> V_15 )
F_4 ( V_2 , V_18 , V_3 ) ;
F_38 ( V_48 -> V_31 , 0 , V_3 ) ;
return V_65 ;
}
static T_4 int F_39 ( struct V_60 * V_48 , T_1 V_66 )
{
struct V_1 * V_2 = V_48 -> V_31 -> V_32 . V_2 ;
struct V_17 * V_18 = V_48 -> V_32 . V_18 ;
F_2 ( L_16 ,
V_66 , V_18 -> V_67 , V_18 -> V_68 . V_43 , V_18 -> V_69 ) ;
if ( V_18 -> V_67 & V_70 ) {
V_18 -> V_71 ++ ;
F_19 ( V_18 -> V_72 ) ;
}
if ( V_18 -> V_67 & V_73 ) {
V_18 -> V_74 ++ ;
F_20 ( V_2 , V_18 -> V_75 ) ;
}
if ( V_18 -> V_67 & V_76 ) {
V_18 -> V_77 ++ ;
F_4 ( V_2 , V_18 , V_18 -> V_78 ) ;
}
if ( V_18 -> V_67 & V_79 ) {
V_18 -> V_80 ++ ;
F_38 ( V_48 -> V_31 , 0 , V_18 -> V_81 ) ;
}
V_18 -> V_67 = 0 ;
return V_65 ;
}
int F_40 ( struct V_60 * V_48 , T_1 V_82 )
{
struct V_1 * V_2 = V_48 -> V_31 -> V_32 . V_2 ;
unsigned long V_83 ;
int V_84 = V_65 ;
if ( ! V_2 || ! V_48 -> V_32 . V_18 )
return V_85 ;
switch ( V_82 ) {
case V_86 :
V_83 = F_31 ( V_48 ) ;
F_35 ( V_48 , 4 , V_83 ) ;
F_35 ( V_48 , 5 , F_41 () ) ;
return V_84 ;
case V_87 :
V_84 = F_34 ( V_48 , F_42 ( V_48 , 4 ) ) ;
return V_84 ;
}
if ( V_2 -> V_88 && F_43 ( V_48 -> V_31 ) )
return F_39 ( V_48 , V_82 ) ;
switch ( V_82 ) {
case V_89 :
V_83 = F_31 ( V_48 ) ;
F_35 ( V_48 , 4 , V_83 ) ;
break;
case V_90 :
F_36 ( V_48 , F_42 ( V_48 , 4 ) ) ;
break;
case V_91 :
V_84 = F_37 ( V_48 , F_42 ( V_48 , 4 ) ) ;
break;
case V_92 :
V_84 = F_33 ( V_48 , F_42 ( V_48 , 4 ) ,
F_42 ( V_48 , 5 ) ) ;
break;
}
return V_84 ;
}
static int F_44 ( struct V_93 * V_94 , void * V_95 )
{
struct V_1 * V_2 = V_94 -> V_95 ;
struct V_31 * V_31 = V_2 -> V_31 ;
struct V_60 * V_48 ;
int V_50 , V_19 ;
unsigned long V_20 ;
unsigned long V_96 , V_97 ;
unsigned long V_98 , V_99 ;
unsigned long V_100 , V_101 ;
if ( ! V_31 )
return 0 ;
V_96 = 0 ;
V_99 = 0 ;
V_97 = 0 ;
V_98 = 0 ;
V_101 = 0 ;
V_100 = 0 ;
F_45 ( V_94 , L_17 ) ;
F_46 (i, vcpu, kvm) {
struct V_17 * V_18 = V_48 -> V_32 . V_18 ;
union V_34 V_6 ;
if ( ! V_18 )
continue;
V_6 . V_43 = F_25 ( V_18 -> V_6 . V_43 ) ;
F_45 ( V_94 , L_18 ,
V_18 -> V_45 , V_6 . V_40 ,
V_6 . V_41 , V_6 . V_42 , V_6 . V_46 ,
V_6 . V_39 , V_6 . V_47 ) ;
V_96 += V_18 -> V_71 ;
V_99 += V_18 -> V_80 ;
V_97 += V_18 -> V_74 ;
V_98 += V_18 -> V_77 ;
V_101 += V_18 -> V_102 ;
V_100 += V_18 -> V_103 ;
}
F_45 ( V_94 , L_19 ,
V_96 , V_97 ,
V_98 , V_99 ) ;
F_45 ( V_94 , L_20 ,
V_101 , V_100 ) ;
for ( V_50 = 0 ; V_50 <= V_104 ; V_50 ++ ) {
struct V_7 * V_8 = V_2 -> V_8 [ V_50 ] ;
if ( ! V_8 )
continue;
F_45 ( V_94 , L_21 ,
V_50 ) ;
F_6 ( V_20 ) ;
F_7 ( & V_8 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
struct V_5 * V_3 = & V_8 -> V_11 [ V_19 ] ;
F_45 ( V_94 , L_22 ,
V_3 -> V_24 , V_3 -> V_26 , V_3 -> V_25 ,
V_3 -> V_27 , V_3 -> V_15 ,
V_3 -> V_23 , V_3 -> V_29 ) ;
}
F_8 ( & V_8 -> V_21 ) ;
F_9 ( V_20 ) ;
}
return 0 ;
}
static int F_47 ( struct V_105 * V_105 , struct V_106 * V_106 )
{
return F_48 ( V_106 , F_44 , V_105 -> V_107 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
char * V_108 ;
V_108 = F_50 ( V_109 , L_23 , V_2 ) ;
if ( ! V_108 ) {
F_51 ( L_24 , V_110 ) ;
return;
}
V_2 -> V_111 = F_52 ( V_108 , V_112 , V_113 ,
V_2 , & V_114 ) ;
F_53 ( L_25 , V_110 , V_108 ) ;
F_54 ( V_108 ) ;
}
static struct V_7 * F_55 ( struct V_31 * V_31 ,
struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 ;
int V_19 , V_50 ;
V_50 = V_3 >> V_115 ;
F_56 ( & V_31 -> V_21 ) ;
if ( V_2 -> V_8 [ V_50 ] )
goto V_57;
V_8 = F_57 ( sizeof( struct V_7 ) , V_109 ) ;
if ( ! V_8 )
goto V_57;
V_8 -> V_50 = V_50 ;
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_8 -> V_11 [ V_19 ] . V_24 = ( V_50 << V_115 ) | V_19 ;
V_8 -> V_11 [ V_19 ] . V_25 = V_30 ;
V_8 -> V_11 [ V_19 ] . V_27 = V_30 ;
}
F_58 () ;
V_2 -> V_8 [ V_50 ] = V_8 ;
if ( V_50 > V_2 -> V_116 )
V_2 -> V_116 = V_50 ;
V_57:
F_59 ( & V_31 -> V_21 ) ;
return V_2 -> V_8 [ V_50 ] ;
}
int F_60 ( struct V_60 * V_48 , unsigned long V_45 )
{
struct V_17 * V_18 ;
if ( ! V_48 -> V_31 -> V_32 . V_2 )
return - V_33 ;
if ( F_12 ( V_48 -> V_31 , V_45 ) )
return - V_117 ;
V_18 = F_57 ( sizeof( struct V_17 ) , V_109 ) ;
if ( ! V_18 )
return - V_118 ;
V_18 -> V_48 = V_48 ;
V_18 -> V_45 = V_45 ;
V_18 -> V_6 . V_46 = V_30 ;
V_18 -> V_6 . V_41 = V_30 ;
V_48 -> V_32 . V_18 = V_18 ;
F_2 ( L_26 , V_48 -> V_62 ) ;
return 0 ;
}
T_5 F_61 ( struct V_60 * V_48 )
{
struct V_17 * V_18 = V_48 -> V_32 . V_18 ;
union V_34 V_6 ;
if ( ! V_18 )
return 0 ;
V_6 = V_18 -> V_6 ;
return ( ( T_5 ) V_6 . V_42 << V_119 ) |
( ( T_5 ) V_6 . V_40 << V_120 ) |
( ( T_5 ) V_6 . V_46 << V_121 ) |
( ( T_5 ) V_6 . V_41 << V_122 ) ;
}
int F_62 ( struct V_60 * V_48 , T_5 V_123 )
{
struct V_17 * V_18 = V_48 -> V_32 . V_18 ;
struct V_1 * V_2 = V_48 -> V_31 -> V_32 . V_2 ;
union V_34 V_53 , V_54 ;
struct V_7 * V_8 ;
T_3 V_42 , V_46 , V_41 ;
T_1 V_40 ;
T_2 V_9 ;
bool V_23 ;
if ( ! V_18 || ! V_2 )
return - V_124 ;
V_42 = V_123 >> V_119 ;
V_40 = ( V_123 >> V_120 ) &
V_125 ;
V_46 = V_123 >> V_121 ;
V_41 = V_123 >> V_122 ;
if ( V_40 == 0 ) {
if ( V_41 != 0xff )
return - V_10 ;
} else if ( V_40 == V_58 ) {
if ( V_41 != V_46 || V_41 >= V_42 )
return - V_10 ;
} else {
if ( V_41 >= V_46 || V_41 >= V_42 )
return - V_10 ;
V_8 = F_3 ( V_2 , V_40 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
}
V_54 . V_43 = 0 ;
V_54 . V_42 = V_42 ;
V_54 . V_40 = V_40 ;
V_54 . V_46 = V_46 ;
V_54 . V_41 = V_41 ;
F_32 ( V_18 -> V_48 ,
V_49 ) ;
do {
V_53 = F_25 ( V_18 -> V_6 ) ;
if ( V_54 . V_46 <= V_53 . V_46 ) {
V_23 = false ;
V_54 . V_47 = V_53 . V_47 ;
} else {
V_23 = V_53 . V_47 ;
V_54 . V_47 = 0 ;
}
} while ( ! F_16 ( V_18 , V_53 , V_54 , false ) );
if ( V_23 )
F_20 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , long V_3 , T_5 V_126 )
{
int V_127 ;
struct V_7 * V_8 ;
struct V_5 * V_128 ;
T_5 T_6 * V_129 = ( T_5 T_6 * ) V_126 ;
T_2 V_130 ;
T_5 V_131 , V_132 ;
unsigned long V_20 ;
V_8 = F_3 ( V_2 , V_3 , & V_130 ) ;
if ( ! V_8 )
return - V_124 ;
V_128 = & V_8 -> V_11 [ V_130 ] ;
F_6 ( V_20 ) ;
F_7 ( & V_8 -> V_21 ) ;
V_127 = - V_124 ;
if ( V_128 -> V_12 ) {
V_131 = V_128 -> V_26 ;
V_132 = V_128 -> V_25 ;
if ( V_132 == V_30 ) {
V_131 |= V_133 ;
V_132 = V_128 -> V_27 ;
}
V_131 |= V_132 << V_134 ;
if ( V_128 -> V_13 ) {
V_131 |= V_135 ;
if ( V_128 -> V_15 )
V_131 |= V_136 ;
} else if ( V_128 -> V_29 || V_128 -> V_23 )
V_131 |= V_136 ;
V_127 = 0 ;
}
F_8 ( & V_8 -> V_21 ) ;
F_9 ( V_20 ) ;
if ( ! V_127 && F_64 ( V_131 , V_129 ) )
V_127 = - V_137 ;
return V_127 ;
}
static int F_65 ( struct V_1 * V_2 , long V_3 , T_5 V_126 )
{
struct V_7 * V_8 ;
struct V_5 * V_128 ;
T_5 T_6 * V_129 = ( T_5 T_6 * ) V_126 ;
T_2 V_130 ;
T_5 V_131 ;
T_3 V_132 ;
T_1 V_26 ;
unsigned long V_20 ;
if ( V_3 < V_138 || V_3 >= V_139 )
return - V_124 ;
V_8 = F_3 ( V_2 , V_3 , & V_130 ) ;
if ( ! V_8 ) {
V_8 = F_55 ( V_2 -> V_31 , V_2 , V_3 ) ;
if ( ! V_8 )
return - V_118 ;
}
V_128 = & V_8 -> V_11 [ V_130 ] ;
if ( F_66 ( V_131 , V_129 ) )
return - V_137 ;
V_26 = V_131 & V_140 ;
V_132 = V_131 >> V_134 ;
if ( V_132 != V_30 &&
F_12 ( V_2 -> V_31 , V_26 ) == NULL )
return - V_10 ;
F_6 ( V_20 ) ;
F_7 ( & V_8 -> V_21 ) ;
V_128 -> V_26 = V_26 ;
V_128 -> V_27 = V_132 ;
if ( V_131 & V_133 )
V_132 = V_30 ;
V_128 -> V_25 = V_132 ;
V_128 -> V_23 = 0 ;
V_128 -> V_29 = 0 ;
V_128 -> V_13 = 0 ;
V_128 -> V_15 = 0 ;
if ( V_131 & V_135 ) {
V_128 -> V_13 = 1 ;
if ( V_131 & V_136 )
V_128 -> V_15 = 1 ;
}
V_128 -> V_12 = 1 ;
F_8 ( & V_8 -> V_21 ) ;
F_9 ( V_20 ) ;
if ( V_131 & V_136 )
F_4 ( V_2 , NULL , V_128 -> V_24 ) ;
return 0 ;
}
int F_67 ( struct V_31 * V_31 , int V_141 , T_1 V_3 , int V_4 ,
bool V_142 )
{
struct V_1 * V_2 = V_31 -> V_32 . V_2 ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_68 ( struct V_143 * V_144 ,
struct V_31 * V_31 , int V_141 ,
int V_4 , bool V_142 )
{
return F_67 ( V_31 , V_141 , V_144 -> V_145 ,
V_4 , V_142 ) ;
}
static int F_69 ( struct V_146 * V_147 , struct V_148 * V_149 )
{
struct V_1 * V_2 = V_147 -> V_95 ;
switch ( V_149 -> V_150 ) {
case V_151 :
return F_65 ( V_2 , V_149 -> V_149 , V_149 -> V_126 ) ;
}
return - V_152 ;
}
static int F_70 ( struct V_146 * V_147 , struct V_148 * V_149 )
{
struct V_1 * V_2 = V_147 -> V_95 ;
switch ( V_149 -> V_150 ) {
case V_151 :
return F_63 ( V_2 , V_149 -> V_149 , V_149 -> V_126 ) ;
}
return - V_152 ;
}
static int F_71 ( struct V_146 * V_147 , struct V_148 * V_149 )
{
switch ( V_149 -> V_150 ) {
case V_151 :
if ( V_149 -> V_149 >= V_138 &&
V_149 -> V_149 < V_139 )
return 0 ;
break;
}
return - V_152 ;
}
static void F_72 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = V_147 -> V_95 ;
int V_19 ;
struct V_31 * V_31 = V_2 -> V_31 ;
F_73 ( V_2 -> V_111 ) ;
if ( V_31 )
V_31 -> V_32 . V_2 = NULL ;
for ( V_19 = 0 ; V_19 <= V_2 -> V_116 ; V_19 ++ )
F_54 ( V_2 -> V_8 [ V_19 ] ) ;
F_54 ( V_2 ) ;
F_54 ( V_147 ) ;
}
static int F_74 ( struct V_146 * V_147 , T_1 type )
{
struct V_1 * V_2 ;
struct V_31 * V_31 = V_147 -> V_31 ;
int V_127 = 0 ;
V_2 = F_57 ( sizeof( * V_2 ) , V_109 ) ;
if ( ! V_2 )
return - V_118 ;
V_147 -> V_95 = V_2 ;
V_2 -> V_147 = V_147 ;
V_2 -> V_31 = V_31 ;
if ( V_31 -> V_32 . V_2 )
V_127 = - V_117 ;
else
V_31 -> V_32 . V_2 = V_2 ;
if ( V_127 ) {
F_54 ( V_2 ) ;
return V_127 ;
}
#ifdef F_75
if ( F_76 ( V_153 ) ) {
V_2 -> V_88 = V_154 ;
V_2 -> V_155 = V_156 ;
}
#endif
return 0 ;
}
static void F_77 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = (struct V_1 * ) V_147 -> V_95 ;
F_49 ( V_2 ) ;
}
int F_78 ( struct V_146 * V_147 , struct V_60 * V_48 ,
T_1 V_157 )
{
struct V_1 * V_2 = V_147 -> V_95 ;
int V_158 = - V_159 ;
if ( V_147 -> V_160 != & V_161 )
return - V_162 ;
if ( V_2 -> V_31 != V_48 -> V_31 )
return - V_162 ;
if ( V_48 -> V_32 . V_163 )
return - V_159 ;
V_158 = F_60 ( V_48 , V_157 ) ;
if ( ! V_158 )
V_48 -> V_32 . V_163 = V_164 ;
return V_158 ;
}
void F_79 ( struct V_60 * V_48 )
{
if ( ! V_48 -> V_32 . V_18 )
return;
F_54 ( V_48 -> V_32 . V_18 ) ;
V_48 -> V_32 . V_18 = NULL ;
V_48 -> V_32 . V_163 = V_165 ;
}
static int F_80 ( struct V_143 * V_166 ,
struct V_31 * V_31 , int V_141 , int V_4 ,
bool V_142 )
{
return F_67 ( V_31 , V_141 , V_166 -> V_145 , V_4 , V_142 ) ;
}
int F_81 ( struct V_31 * V_31 ,
struct V_143 * V_167 , int V_145 )
{
V_167 -> V_145 = V_145 ;
V_167 -> type = V_168 ;
V_167 -> V_169 = F_80 ;
V_167 -> V_170 . V_170 = 0 ;
V_167 -> V_170 . V_171 = V_145 ;
return 1 ;
}
int F_82 ( struct V_31 * V_31 , unsigned V_170 , unsigned V_171 )
{
return V_171 ;
}
