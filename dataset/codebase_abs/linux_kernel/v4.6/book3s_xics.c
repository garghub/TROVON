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
if ( V_4 == 1 || V_4 == V_13 )
V_6 -> V_14 = 1 ;
else if ( V_4 == 0 || V_4 == V_15 ) {
V_6 -> V_14 = 0 ;
return 0 ;
}
F_4 ( V_2 , NULL , V_3 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_16 * V_17 )
{
int V_18 ;
unsigned long V_19 ;
F_6 ( V_19 ) ;
F_7 ( & V_8 -> V_20 ) ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
struct V_5 * V_6 = & V_8 -> V_11 [ V_18 ] ;
if ( ! V_6 -> V_22 )
continue;
F_2 ( L_3 , V_6 -> V_23 ,
V_6 -> V_24 ) ;
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_19 ) ;
F_4 ( V_2 , V_17 , V_6 -> V_23 ) ;
F_6 ( V_19 ) ;
F_7 ( & V_8 -> V_20 ) ;
}
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_19 ) ;
}
static bool F_10 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_5 * V_6 ,
T_1 V_25 , T_1 V_24 , T_1 V_26 )
{
bool V_27 ;
unsigned long V_19 ;
F_6 ( V_19 ) ;
F_7 ( & V_8 -> V_20 ) ;
V_6 -> V_25 = V_25 ;
V_6 -> V_24 = V_24 ;
V_6 -> V_26 = V_26 ;
V_27 = false ;
if ( ( V_6 -> V_28 || V_6 -> V_22 ) && V_24 != V_29 ) {
V_6 -> V_28 = 0 ;
V_27 = true ;
}
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_19 ) ;
return V_27 ;
}
int F_11 ( struct V_30 * V_30 , T_1 V_3 , T_1 V_25 , T_1 V_24 )
{
struct V_1 * V_2 = V_30 -> V_31 . V_2 ;
struct V_16 * V_17 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_32 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
V_17 = F_12 ( V_30 , V_25 ) ;
if ( ! V_17 )
return - V_10 ;
F_2 ( L_4 ,
V_3 , V_25 , V_24 ,
V_6 -> V_28 , V_6 -> V_22 ) ;
if ( F_10 ( V_2 , V_8 , V_6 , V_25 , V_24 , V_24 ) )
F_4 ( V_2 , V_17 , V_3 ) ;
return 0 ;
}
int F_13 ( struct V_30 * V_30 , T_1 V_3 , T_1 * V_25 , T_1 * V_24 )
{
struct V_1 * V_2 = V_30 -> V_31 . V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
unsigned long V_19 ;
if ( ! V_2 )
return - V_32 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_6 ( V_19 ) ;
F_7 ( & V_8 -> V_20 ) ;
* V_25 = V_6 -> V_25 ;
* V_24 = V_6 -> V_24 ;
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_19 ) ;
return 0 ;
}
int F_14 ( struct V_30 * V_30 , T_1 V_3 )
{
struct V_1 * V_2 = V_30 -> V_31 . V_2 ;
struct V_16 * V_17 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_32 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
V_17 = F_12 ( V_30 , V_6 -> V_25 ) ;
if ( ! V_17 )
return - V_10 ;
if ( F_10 ( V_2 , V_8 , V_6 , V_6 -> V_25 , V_6 -> V_26 ,
V_6 -> V_26 ) )
F_4 ( V_2 , V_17 , V_3 ) ;
return 0 ;
}
int F_15 ( struct V_30 * V_30 , T_1 V_3 )
{
struct V_1 * V_2 = V_30 -> V_31 . V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_32 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_10 ( V_2 , V_8 , V_6 , V_6 -> V_25 , V_29 , V_6 -> V_24 ) ;
return 0 ;
}
static inline bool F_16 ( struct V_16 * V_17 ,
union V_33 V_34 ,
union V_33 V_35 ,
bool V_36 )
{
bool V_37 ;
V_35 . V_38 = ( V_35 . V_39 && ( V_35 . V_40 < V_35 . V_41 ) ) ;
V_37 = F_17 ( & V_17 -> V_6 . V_42 , V_34 . V_42 , V_35 . V_42 ) == V_34 . V_42 ;
if ( ! V_37 )
goto V_43;
F_2 ( L_5 ,
V_17 -> V_44 ,
V_34 . V_41 , V_34 . V_45 , V_34 . V_40 , V_34 . V_39 ,
V_34 . V_46 , V_34 . V_38 ) ;
F_2 ( L_6 ,
V_35 . V_41 , V_35 . V_45 , V_35 . V_40 , V_35 . V_39 ,
V_35 . V_46 , V_35 . V_38 ) ;
if ( V_35 . V_38 ) {
F_18 ( V_17 -> V_47 ,
V_48 ) ;
if ( ! V_36 )
F_19 ( V_17 -> V_47 ) ;
}
V_43:
return V_37 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
T_1 V_49 ;
F_21 () ;
F_22 (icsid, icp->resend_map, xics->max_icsid + 1 ) {
struct V_7 * V_8 = V_2 -> V_8 [ V_49 ] ;
if ( ! F_23 ( V_49 , V_17 -> V_50 ) )
continue;
if ( ! V_8 )
continue;
F_5 ( V_2 , V_8 , V_17 ) ;
}
}
static bool F_24 ( struct V_16 * V_17 , T_1 V_3 , T_3 V_24 ,
T_1 * V_51 )
{
union V_33 V_52 , V_53 ;
bool V_37 ;
F_2 ( L_7 , V_3 , V_24 ,
V_17 -> V_44 ) ;
do {
V_52 = V_53 = F_25 ( V_17 -> V_6 ) ;
* V_51 = 0 ;
V_37 = V_53 . V_41 > V_24 &&
V_53 . V_45 > V_24 &&
V_53 . V_40 > V_24 ;
if ( V_37 ) {
* V_51 = V_53 . V_39 ;
V_53 . V_39 = V_3 ;
V_53 . V_40 = V_24 ;
} else {
V_53 . V_46 = true ;
}
} while ( ! F_16 ( V_17 , V_52 , V_53 , false ) );
return V_37 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_1 V_54 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_51 ;
T_2 V_9 ;
unsigned long V_19 ;
V_55:
V_8 = F_3 ( V_2 , V_54 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_8 , V_54 ) ;
return;
}
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_6 ( V_19 ) ;
F_7 ( & V_8 -> V_20 ) ;
if ( ! V_17 || V_6 -> V_25 != V_17 -> V_44 ) {
V_17 = F_12 ( V_2 -> V_30 , V_6 -> V_25 ) ;
if ( ! V_17 ) {
F_26 ( L_9 ,
V_54 , V_6 -> V_25 ) ;
goto V_56;
}
}
V_6 -> V_22 = 0 ;
if ( V_6 -> V_24 == V_29 ) {
F_2 ( L_10 , V_54 ) ;
V_6 -> V_28 = 1 ;
goto V_56;
}
if ( F_24 ( V_17 , V_54 , V_6 -> V_24 , & V_51 ) ) {
if ( V_51 && V_51 != V_57 ) {
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_19 ) ;
V_54 = V_51 ;
goto V_55;
}
} else {
F_27 ( V_8 -> V_49 , V_17 -> V_50 ) ;
V_6 -> V_22 = 1 ;
F_28 () ;
if ( ! V_17 -> V_6 . V_46 ) {
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_19 ) ;
goto V_55;
}
}
V_56:
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_19 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_3 V_58 )
{
union V_33 V_52 , V_53 ;
bool V_22 ;
do {
V_52 = V_53 = F_25 ( V_17 -> V_6 ) ;
V_53 . V_41 = V_58 ;
if ( V_53 . V_45 < V_58 &&
V_53 . V_45 <= V_53 . V_40 ) {
F_30 ( V_53 . V_39 != V_57 &&
V_53 . V_39 != 0 ) ;
V_53 . V_40 = V_53 . V_45 ;
V_53 . V_39 = V_57 ;
}
V_22 = V_53 . V_46 ;
V_53 . V_46 = 0 ;
} while ( ! F_16 ( V_17 , V_52 , V_53 , true ) );
if ( V_22 )
F_20 ( V_2 , V_17 ) ;
}
static T_4 unsigned long F_31 ( struct V_59 * V_47 )
{
union V_33 V_52 , V_53 ;
struct V_16 * V_17 = V_47 -> V_31 . V_17 ;
T_1 V_60 ;
F_32 ( V_17 -> V_47 ,
V_48 ) ;
do {
V_52 = V_53 = F_25 ( V_17 -> V_6 ) ;
V_60 = V_52 . V_39 | ( ( ( T_1 ) V_52 . V_41 ) << 24 ) ;
if ( ! V_52 . V_39 )
break;
V_53 . V_41 = V_53 . V_40 ;
V_53 . V_40 = 0xff ;
V_53 . V_39 = 0 ;
} while ( ! F_16 ( V_17 , V_52 , V_53 , true ) );
F_2 ( L_11 , V_47 -> V_61 , V_60 ) ;
return V_60 ;
}
static T_4 int F_33 ( struct V_59 * V_47 , unsigned long V_25 ,
unsigned long V_45 )
{
union V_33 V_52 , V_53 ;
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
struct V_16 * V_17 ;
T_1 V_51 ;
bool V_22 ;
bool V_62 ;
F_2 ( L_12 ,
V_47 -> V_61 , V_25 , V_45 ) ;
V_17 = V_47 -> V_31 . V_17 ;
V_62 = V_17 -> V_44 == V_25 ;
if ( ! V_62 ) {
V_17 = F_12 ( V_47 -> V_30 , V_25 ) ;
if ( ! V_17 )
return V_63 ;
}
do {
V_52 = V_53 = F_25 ( V_17 -> V_6 ) ;
V_53 . V_45 = V_45 ;
V_51 = 0 ;
V_22 = false ;
if ( V_45 < V_53 . V_41 ) {
if ( V_45 <= V_53 . V_40 ) {
V_51 = V_53 . V_39 ;
V_53 . V_40 = V_45 ;
V_53 . V_39 = V_57 ;
}
}
if ( V_45 > V_52 . V_45 ) {
V_22 = V_53 . V_46 ;
V_53 . V_46 = 0 ;
}
} while ( ! F_16 ( V_17 , V_52 , V_53 , V_62 ) );
if ( V_51 && V_51 != V_57 )
F_4 ( V_2 , V_17 , V_51 ) ;
if ( V_22 )
F_20 ( V_2 , V_17 ) ;
return V_64 ;
}
static int F_34 ( struct V_59 * V_47 , unsigned long V_25 )
{
union V_33 V_6 ;
struct V_16 * V_17 ;
V_17 = V_47 -> V_31 . V_17 ;
if ( V_17 -> V_44 != V_25 ) {
V_17 = F_12 ( V_47 -> V_30 , V_25 ) ;
if ( ! V_17 )
return V_63 ;
}
V_6 = F_25 ( V_17 -> V_6 ) ;
F_35 ( V_47 , 4 , ( ( T_1 ) V_6 . V_41 << 24 ) | V_6 . V_39 ) ;
F_35 ( V_47 , 5 , V_6 . V_45 ) ;
return V_64 ;
}
static T_4 void F_36 ( struct V_59 * V_47 , unsigned long V_41 )
{
union V_33 V_52 , V_53 ;
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
struct V_16 * V_17 = V_47 -> V_31 . V_17 ;
T_1 V_51 ;
F_2 ( L_13 , V_47 -> V_61 , V_41 ) ;
if ( V_41 > V_17 -> V_6 . V_41 )
F_29 ( V_2 , V_17 , V_41 ) ;
else if ( V_41 == V_17 -> V_6 . V_41 )
return;
F_32 ( V_17 -> V_47 ,
V_48 ) ;
do {
V_52 = V_53 = F_25 ( V_17 -> V_6 ) ;
V_51 = 0 ;
V_53 . V_41 = V_41 ;
if ( V_41 <= V_53 . V_40 ) {
V_51 = V_53 . V_39 ;
V_53 . V_39 = 0 ;
V_53 . V_40 = 0xff ;
}
} while ( ! F_16 ( V_17 , V_52 , V_53 , true ) );
if ( V_51 && V_51 != V_57 )
F_4 ( V_2 , V_17 , V_51 ) ;
}
static T_4 int F_37 ( struct V_59 * V_47 , unsigned long V_60 )
{
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
struct V_16 * V_17 = V_47 -> V_31 . V_17 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_1 V_3 = V_60 & 0x00ffffff ;
T_2 V_9 ;
F_2 ( L_14 , V_47 -> V_61 , V_60 ) ;
F_29 ( V_2 , V_17 , V_60 >> 24 ) ;
if ( V_3 == V_57 )
return V_64 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_15 , V_3 ) ;
return V_63 ;
}
V_6 = & V_8 -> V_11 [ V_9 ] ;
if ( V_6 -> V_14 )
F_4 ( V_2 , V_17 , V_3 ) ;
F_38 ( V_47 -> V_30 , 0 , V_3 ) ;
return V_64 ;
}
static T_4 int F_39 ( struct V_59 * V_47 , T_1 V_65 )
{
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
struct V_16 * V_17 = V_47 -> V_31 . V_17 ;
F_2 ( L_16 ,
V_65 , V_17 -> V_66 , V_17 -> V_67 . V_42 , V_17 -> V_68 ) ;
if ( V_17 -> V_66 & V_69 ) {
V_17 -> V_70 ++ ;
F_19 ( V_17 -> V_71 ) ;
}
if ( V_17 -> V_66 & V_72 ) {
V_17 -> V_73 ++ ;
F_20 ( V_2 , V_17 -> V_74 ) ;
}
if ( V_17 -> V_66 & V_75 ) {
V_17 -> V_76 ++ ;
F_4 ( V_2 , V_17 , V_17 -> V_77 ) ;
}
if ( V_17 -> V_66 & V_78 ) {
V_17 -> V_79 ++ ;
F_38 ( V_47 -> V_30 , 0 , V_17 -> V_80 ) ;
}
V_17 -> V_66 = 0 ;
return V_64 ;
}
int F_40 ( struct V_59 * V_47 , T_1 V_81 )
{
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
unsigned long V_82 ;
int V_83 = V_64 ;
if ( ! V_2 || ! V_47 -> V_31 . V_17 )
return V_84 ;
switch ( V_81 ) {
case V_85 :
V_82 = F_31 ( V_47 ) ;
F_35 ( V_47 , 4 , V_82 ) ;
F_35 ( V_47 , 5 , F_41 () ) ;
return V_83 ;
case V_86 :
V_83 = F_34 ( V_47 , F_42 ( V_47 , 4 ) ) ;
return V_83 ;
}
if ( V_2 -> V_87 && F_43 ( V_47 -> V_30 ) )
return F_39 ( V_47 , V_81 ) ;
switch ( V_81 ) {
case V_88 :
V_82 = F_31 ( V_47 ) ;
F_35 ( V_47 , 4 , V_82 ) ;
break;
case V_89 :
F_36 ( V_47 , F_42 ( V_47 , 4 ) ) ;
break;
case V_90 :
V_83 = F_37 ( V_47 , F_42 ( V_47 , 4 ) ) ;
break;
case V_91 :
V_83 = F_33 ( V_47 , F_42 ( V_47 , 4 ) ,
F_42 ( V_47 , 5 ) ) ;
break;
}
return V_83 ;
}
static int F_44 ( struct V_92 * V_93 , void * V_94 )
{
struct V_1 * V_2 = V_93 -> V_94 ;
struct V_30 * V_30 = V_2 -> V_30 ;
struct V_59 * V_47 ;
int V_49 , V_18 ;
unsigned long V_19 ;
unsigned long V_95 , V_96 ;
unsigned long V_97 , V_98 ;
unsigned long V_99 , V_100 ;
if ( ! V_30 )
return 0 ;
V_95 = 0 ;
V_98 = 0 ;
V_96 = 0 ;
V_97 = 0 ;
V_100 = 0 ;
V_99 = 0 ;
F_45 ( V_93 , L_17 ) ;
F_46 (i, vcpu, kvm) {
struct V_16 * V_17 = V_47 -> V_31 . V_17 ;
union V_33 V_6 ;
if ( ! V_17 )
continue;
V_6 . V_42 = F_25 ( V_17 -> V_6 . V_42 ) ;
F_45 ( V_93 , L_18 ,
V_17 -> V_44 , V_6 . V_39 ,
V_6 . V_40 , V_6 . V_41 , V_6 . V_45 ,
V_6 . V_38 , V_6 . V_46 ) ;
V_95 += V_17 -> V_70 ;
V_98 += V_17 -> V_79 ;
V_96 += V_17 -> V_73 ;
V_97 += V_17 -> V_76 ;
V_100 += V_17 -> V_101 ;
V_99 += V_17 -> V_102 ;
}
F_45 ( V_93 , L_19 ,
V_95 , V_96 ,
V_97 , V_98 ) ;
F_45 ( V_93 , L_20 ,
V_100 , V_99 ) ;
for ( V_49 = 0 ; V_49 <= V_103 ; V_49 ++ ) {
struct V_7 * V_8 = V_2 -> V_8 [ V_49 ] ;
if ( ! V_8 )
continue;
F_45 ( V_93 , L_21 ,
V_49 ) ;
F_6 ( V_19 ) ;
F_7 ( & V_8 -> V_20 ) ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
struct V_5 * V_3 = & V_8 -> V_11 [ V_18 ] ;
F_45 ( V_93 , L_22 ,
V_3 -> V_23 , V_3 -> V_25 , V_3 -> V_24 ,
V_3 -> V_26 , V_3 -> V_14 ,
V_3 -> V_22 , V_3 -> V_28 ) ;
}
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_19 ) ;
}
return 0 ;
}
static int F_47 ( struct V_104 * V_104 , struct V_105 * V_105 )
{
return F_48 ( V_105 , F_44 , V_104 -> V_106 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
char * V_107 ;
V_107 = F_50 ( V_108 , L_23 , V_2 ) ;
if ( ! V_107 ) {
F_51 ( L_24 , V_109 ) ;
return;
}
V_2 -> V_110 = F_52 ( V_107 , V_111 , V_112 ,
V_2 , & V_113 ) ;
F_53 ( L_25 , V_109 , V_107 ) ;
F_54 ( V_107 ) ;
}
static struct V_7 * F_55 ( struct V_30 * V_30 ,
struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 ;
int V_18 , V_49 ;
V_49 = V_3 >> V_114 ;
F_56 ( & V_30 -> V_20 ) ;
if ( V_2 -> V_8 [ V_49 ] )
goto V_56;
V_8 = F_57 ( sizeof( struct V_7 ) , V_108 ) ;
if ( ! V_8 )
goto V_56;
V_8 -> V_49 = V_49 ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
V_8 -> V_11 [ V_18 ] . V_23 = ( V_49 << V_114 ) | V_18 ;
V_8 -> V_11 [ V_18 ] . V_24 = V_29 ;
V_8 -> V_11 [ V_18 ] . V_26 = V_29 ;
}
F_58 () ;
V_2 -> V_8 [ V_49 ] = V_8 ;
if ( V_49 > V_2 -> V_115 )
V_2 -> V_115 = V_49 ;
V_56:
F_59 ( & V_30 -> V_20 ) ;
return V_2 -> V_8 [ V_49 ] ;
}
int F_60 ( struct V_59 * V_47 , unsigned long V_44 )
{
struct V_16 * V_17 ;
if ( ! V_47 -> V_30 -> V_31 . V_2 )
return - V_32 ;
if ( F_12 ( V_47 -> V_30 , V_44 ) )
return - V_116 ;
V_17 = F_57 ( sizeof( struct V_16 ) , V_108 ) ;
if ( ! V_17 )
return - V_117 ;
V_17 -> V_47 = V_47 ;
V_17 -> V_44 = V_44 ;
V_17 -> V_6 . V_45 = V_29 ;
V_17 -> V_6 . V_40 = V_29 ;
V_47 -> V_31 . V_17 = V_17 ;
F_2 ( L_26 , V_47 -> V_61 ) ;
return 0 ;
}
T_5 F_61 ( struct V_59 * V_47 )
{
struct V_16 * V_17 = V_47 -> V_31 . V_17 ;
union V_33 V_6 ;
if ( ! V_17 )
return 0 ;
V_6 = V_17 -> V_6 ;
return ( ( T_5 ) V_6 . V_41 << V_118 ) |
( ( T_5 ) V_6 . V_39 << V_119 ) |
( ( T_5 ) V_6 . V_45 << V_120 ) |
( ( T_5 ) V_6 . V_40 << V_121 ) ;
}
int F_62 ( struct V_59 * V_47 , T_5 V_122 )
{
struct V_16 * V_17 = V_47 -> V_31 . V_17 ;
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
union V_33 V_52 , V_53 ;
struct V_7 * V_8 ;
T_3 V_41 , V_45 , V_40 ;
T_1 V_39 ;
T_2 V_9 ;
bool V_22 ;
if ( ! V_17 || ! V_2 )
return - V_123 ;
V_41 = V_122 >> V_118 ;
V_39 = ( V_122 >> V_119 ) &
V_124 ;
V_45 = V_122 >> V_120 ;
V_40 = V_122 >> V_121 ;
if ( V_39 == 0 ) {
if ( V_40 != 0xff )
return - V_10 ;
} else if ( V_39 == V_57 ) {
if ( V_40 != V_45 || V_40 >= V_41 )
return - V_10 ;
} else {
if ( V_40 >= V_45 || V_40 >= V_41 )
return - V_10 ;
V_8 = F_3 ( V_2 , V_39 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
}
V_53 . V_42 = 0 ;
V_53 . V_41 = V_41 ;
V_53 . V_39 = V_39 ;
V_53 . V_45 = V_45 ;
V_53 . V_40 = V_40 ;
F_32 ( V_17 -> V_47 ,
V_48 ) ;
do {
V_52 = F_25 ( V_17 -> V_6 ) ;
if ( V_53 . V_45 <= V_52 . V_45 ) {
V_22 = false ;
V_53 . V_46 = V_52 . V_46 ;
} else {
V_22 = V_52 . V_46 ;
V_53 . V_46 = 0 ;
}
} while ( ! F_16 ( V_17 , V_52 , V_53 , false ) );
if ( V_22 )
F_20 ( V_2 , V_17 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , long V_3 , T_5 V_125 )
{
int V_126 ;
struct V_7 * V_8 ;
struct V_5 * V_127 ;
T_5 T_6 * V_128 = ( T_5 T_6 * ) V_125 ;
T_2 V_129 ;
T_5 V_130 , V_131 ;
unsigned long V_19 ;
V_8 = F_3 ( V_2 , V_3 , & V_129 ) ;
if ( ! V_8 )
return - V_123 ;
V_127 = & V_8 -> V_11 [ V_129 ] ;
F_6 ( V_19 ) ;
F_7 ( & V_8 -> V_20 ) ;
V_126 = - V_123 ;
if ( V_127 -> V_12 ) {
V_130 = V_127 -> V_25 ;
V_131 = V_127 -> V_24 ;
if ( V_131 == V_29 ) {
V_130 |= V_132 ;
V_131 = V_127 -> V_26 ;
}
V_130 |= V_131 << V_133 ;
if ( V_127 -> V_14 )
V_130 |= V_134 | V_135 ;
else if ( V_127 -> V_28 || V_127 -> V_22 )
V_130 |= V_135 ;
V_126 = 0 ;
}
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_19 ) ;
if ( ! V_126 && F_64 ( V_130 , V_128 ) )
V_126 = - V_136 ;
return V_126 ;
}
static int F_65 ( struct V_1 * V_2 , long V_3 , T_5 V_125 )
{
struct V_7 * V_8 ;
struct V_5 * V_127 ;
T_5 T_6 * V_128 = ( T_5 T_6 * ) V_125 ;
T_2 V_129 ;
T_5 V_130 ;
T_3 V_131 ;
T_1 V_25 ;
unsigned long V_19 ;
if ( V_3 < V_137 || V_3 >= V_138 )
return - V_123 ;
V_8 = F_3 ( V_2 , V_3 , & V_129 ) ;
if ( ! V_8 ) {
V_8 = F_55 ( V_2 -> V_30 , V_2 , V_3 ) ;
if ( ! V_8 )
return - V_117 ;
}
V_127 = & V_8 -> V_11 [ V_129 ] ;
if ( F_66 ( V_130 , V_128 ) )
return - V_136 ;
V_25 = V_130 & V_139 ;
V_131 = V_130 >> V_133 ;
if ( V_131 != V_29 &&
F_12 ( V_2 -> V_30 , V_25 ) == NULL )
return - V_10 ;
F_6 ( V_19 ) ;
F_7 ( & V_8 -> V_20 ) ;
V_127 -> V_25 = V_25 ;
V_127 -> V_26 = V_131 ;
if ( V_130 & V_132 )
V_131 = V_29 ;
V_127 -> V_24 = V_131 ;
V_127 -> V_22 = 0 ;
V_127 -> V_28 = 0 ;
V_127 -> V_14 = 0 ;
if ( ( V_130 & V_135 ) && ( V_130 & V_134 ) )
V_127 -> V_14 = 1 ;
V_127 -> V_12 = 1 ;
F_8 ( & V_8 -> V_20 ) ;
F_9 ( V_19 ) ;
if ( V_130 & V_135 )
F_4 ( V_2 , NULL , V_127 -> V_23 ) ;
return 0 ;
}
int F_67 ( struct V_30 * V_30 , int V_140 , T_1 V_3 , int V_4 ,
bool V_141 )
{
struct V_1 * V_2 = V_30 -> V_31 . V_2 ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_68 ( struct V_142 * V_143 , struct V_30 * V_30 ,
int V_140 , int V_4 , bool V_141 )
{
if ( ! V_4 )
return - 1 ;
return F_67 ( V_30 , V_140 , V_143 -> V_144 ,
V_4 , V_141 ) ;
}
static int F_69 ( struct V_145 * V_146 , struct V_147 * V_148 )
{
struct V_1 * V_2 = V_146 -> V_94 ;
switch ( V_148 -> V_149 ) {
case V_150 :
return F_65 ( V_2 , V_148 -> V_148 , V_148 -> V_125 ) ;
}
return - V_151 ;
}
static int F_70 ( struct V_145 * V_146 , struct V_147 * V_148 )
{
struct V_1 * V_2 = V_146 -> V_94 ;
switch ( V_148 -> V_149 ) {
case V_150 :
return F_63 ( V_2 , V_148 -> V_148 , V_148 -> V_125 ) ;
}
return - V_151 ;
}
static int F_71 ( struct V_145 * V_146 , struct V_147 * V_148 )
{
switch ( V_148 -> V_149 ) {
case V_150 :
if ( V_148 -> V_148 >= V_137 &&
V_148 -> V_148 < V_138 )
return 0 ;
break;
}
return - V_151 ;
}
static void F_72 ( struct V_145 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_94 ;
int V_18 ;
struct V_30 * V_30 = V_2 -> V_30 ;
F_73 ( V_2 -> V_110 ) ;
if ( V_30 )
V_30 -> V_31 . V_2 = NULL ;
for ( V_18 = 0 ; V_18 <= V_2 -> V_115 ; V_18 ++ )
F_54 ( V_2 -> V_8 [ V_18 ] ) ;
F_54 ( V_2 ) ;
F_54 ( V_146 ) ;
}
static int F_74 ( struct V_145 * V_146 , T_1 type )
{
struct V_1 * V_2 ;
struct V_30 * V_30 = V_146 -> V_30 ;
int V_126 = 0 ;
V_2 = F_57 ( sizeof( * V_2 ) , V_108 ) ;
if ( ! V_2 )
return - V_117 ;
V_146 -> V_94 = V_2 ;
V_2 -> V_146 = V_146 ;
V_2 -> V_30 = V_30 ;
F_56 ( & V_30 -> V_20 ) ;
if ( V_30 -> V_31 . V_2 )
V_126 = - V_116 ;
else
V_30 -> V_31 . V_2 = V_2 ;
F_59 ( & V_30 -> V_20 ) ;
if ( V_126 ) {
F_54 ( V_2 ) ;
return V_126 ;
}
F_49 ( V_2 ) ;
#ifdef F_75
if ( F_76 ( V_152 ) ) {
V_2 -> V_87 = V_153 ;
V_2 -> V_154 = V_155 ;
}
#endif
return 0 ;
}
int F_77 ( struct V_145 * V_146 , struct V_59 * V_47 ,
T_1 V_156 )
{
struct V_1 * V_2 = V_146 -> V_94 ;
int V_157 = - V_158 ;
if ( V_146 -> V_159 != & V_160 )
return - V_161 ;
if ( V_2 -> V_30 != V_47 -> V_30 )
return - V_161 ;
if ( V_47 -> V_31 . V_162 )
return - V_158 ;
V_157 = F_60 ( V_47 , V_156 ) ;
if ( ! V_157 )
V_47 -> V_31 . V_162 = V_163 ;
return V_157 ;
}
void F_78 ( struct V_59 * V_47 )
{
if ( ! V_47 -> V_31 . V_17 )
return;
F_54 ( V_47 -> V_31 . V_17 ) ;
V_47 -> V_31 . V_17 = NULL ;
V_47 -> V_31 . V_162 = V_164 ;
}
static int F_79 ( struct V_142 * V_165 ,
struct V_30 * V_30 , int V_140 , int V_4 ,
bool V_141 )
{
return F_67 ( V_30 , V_140 , V_165 -> V_144 , V_4 , V_141 ) ;
}
int F_80 ( struct V_30 * V_30 ,
struct V_142 * V_166 , int V_144 )
{
V_166 -> V_144 = V_144 ;
V_166 -> type = V_167 ;
V_166 -> V_168 = F_79 ;
V_166 -> V_169 . V_169 = 0 ;
V_166 -> V_169 . V_170 = V_144 ;
return 1 ;
}
int F_81 ( struct V_30 * V_30 , unsigned V_169 , unsigned V_170 )
{
return V_170 ;
}
