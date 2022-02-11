static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_2 V_9 ;
T_1 V_10 , V_11 ;
F_2 ( L_1 , V_3 , V_4 ) ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_2 , V_3 ) ;
return - V_12 ;
}
V_6 = & V_8 -> V_13 [ V_9 ] ;
if ( ! V_6 -> V_14 )
return - V_12 ;
if ( V_4 == V_15 || V_4 == V_16 )
V_4 = 1 ;
else if ( V_4 == V_17 )
V_4 = 0 ;
if ( ! V_6 -> V_18 && V_4 == 0 )
return 0 ;
do {
V_10 = V_6 -> V_19 ;
if ( V_6 -> V_18 ) {
if ( V_4 ) {
if ( V_10 & V_20 )
return 0 ;
V_11 = V_20 ;
} else
V_11 = 0 ;
} else
V_11 = ( ( V_10 << 1 ) & 3 ) | V_20 ;
} while ( F_4 ( & V_6 -> V_19 , V_10 , V_11 ) != V_10 );
if ( V_11 == V_20 )
F_5 ( V_2 , NULL , V_3 , false ) ;
if ( V_6 -> V_21 )
V_6 -> V_22 = F_6 () ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_23 * V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
struct V_5 * V_6 = & V_8 -> V_13 [ V_25 ] ;
if ( V_6 -> V_27 ) {
F_2 ( L_3 , V_6 -> V_28 ,
V_6 -> V_29 ) ;
F_5 ( V_2 , V_24 , V_6 -> V_28 , true ) ;
}
}
}
static bool F_8 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_5 * V_6 ,
T_1 V_30 , T_1 V_29 , T_1 V_31 )
{
bool V_32 ;
unsigned long V_33 ;
F_9 ( V_33 ) ;
F_10 ( & V_8 -> V_34 ) ;
V_6 -> V_30 = V_30 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_31 = V_31 ;
V_32 = false ;
if ( ( V_6 -> V_35 || V_6 -> V_27 ) && V_29 != V_36 ) {
V_6 -> V_35 = 0 ;
V_6 -> V_27 = 0 ;
V_32 = true ;
}
F_11 ( & V_8 -> V_34 ) ;
F_12 ( V_33 ) ;
return V_32 ;
}
int F_13 ( struct V_37 * V_37 , T_1 V_3 , T_1 V_30 , T_1 V_29 )
{
struct V_1 * V_2 = V_37 -> V_38 . V_2 ;
struct V_23 * V_24 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_39 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_12 ;
V_6 = & V_8 -> V_13 [ V_9 ] ;
V_24 = F_14 ( V_37 , V_30 ) ;
if ( ! V_24 )
return - V_12 ;
F_2 ( L_4 ,
V_3 , V_30 , V_29 ,
V_6 -> V_35 , V_6 -> V_27 ) ;
if ( F_8 ( V_2 , V_8 , V_6 , V_30 , V_29 , V_29 ) )
F_5 ( V_2 , V_24 , V_3 , false ) ;
return 0 ;
}
int F_15 ( struct V_37 * V_37 , T_1 V_3 , T_1 * V_30 , T_1 * V_29 )
{
struct V_1 * V_2 = V_37 -> V_38 . V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
unsigned long V_33 ;
if ( ! V_2 )
return - V_39 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_12 ;
V_6 = & V_8 -> V_13 [ V_9 ] ;
F_9 ( V_33 ) ;
F_10 ( & V_8 -> V_34 ) ;
* V_30 = V_6 -> V_30 ;
* V_29 = V_6 -> V_29 ;
F_11 ( & V_8 -> V_34 ) ;
F_12 ( V_33 ) ;
return 0 ;
}
int F_16 ( struct V_37 * V_37 , T_1 V_3 )
{
struct V_1 * V_2 = V_37 -> V_38 . V_2 ;
struct V_23 * V_24 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_39 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_12 ;
V_6 = & V_8 -> V_13 [ V_9 ] ;
V_24 = F_14 ( V_37 , V_6 -> V_30 ) ;
if ( ! V_24 )
return - V_12 ;
if ( F_8 ( V_2 , V_8 , V_6 , V_6 -> V_30 , V_6 -> V_31 ,
V_6 -> V_31 ) )
F_5 ( V_2 , V_24 , V_3 , false ) ;
return 0 ;
}
int F_17 ( struct V_37 * V_37 , T_1 V_3 )
{
struct V_1 * V_2 = V_37 -> V_38 . V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_39 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_12 ;
V_6 = & V_8 -> V_13 [ V_9 ] ;
F_8 ( V_2 , V_8 , V_6 , V_6 -> V_30 , V_36 , V_6 -> V_29 ) ;
return 0 ;
}
static inline bool F_18 ( struct V_23 * V_24 ,
union V_40 V_41 ,
union V_40 V_42 ,
bool V_43 )
{
bool V_44 ;
V_42 . V_45 = ( V_42 . V_46 && ( V_42 . V_47 < V_42 . V_48 ) ) ;
V_44 = F_19 ( & V_24 -> V_6 . V_49 , V_41 . V_49 , V_42 . V_49 ) == V_41 . V_49 ;
if ( ! V_44 )
goto V_50;
F_2 ( L_5 ,
V_24 -> V_51 ,
V_41 . V_48 , V_41 . V_52 , V_41 . V_47 , V_41 . V_46 ,
V_41 . V_53 , V_41 . V_45 ) ;
F_2 ( L_6 ,
V_42 . V_48 , V_42 . V_52 , V_42 . V_47 , V_42 . V_46 ,
V_42 . V_53 , V_42 . V_45 ) ;
if ( V_42 . V_45 ) {
F_20 ( V_24 -> V_54 ,
V_55 ) ;
if ( ! V_43 )
F_21 ( V_24 -> V_54 ) ;
}
V_50:
return V_44 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
T_1 V_56 ;
F_23 () ;
F_24 (icsid, icp->resend_map, xics->max_icsid + 1 ) {
struct V_7 * V_8 = V_2 -> V_8 [ V_56 ] ;
if ( ! F_25 ( V_56 , V_24 -> V_57 ) )
continue;
if ( ! V_8 )
continue;
F_7 ( V_2 , V_8 , V_24 ) ;
}
}
static bool F_26 ( struct V_23 * V_24 , T_1 V_3 , T_3 V_29 ,
T_1 * V_58 )
{
union V_40 V_59 , V_60 ;
bool V_44 ;
F_2 ( L_7 , V_3 , V_29 ,
V_24 -> V_51 ) ;
do {
V_59 = V_60 = F_27 ( V_24 -> V_6 ) ;
* V_58 = 0 ;
V_44 = V_60 . V_48 > V_29 &&
V_60 . V_52 > V_29 &&
V_60 . V_47 > V_29 ;
if ( V_44 ) {
* V_58 = V_60 . V_46 ;
V_60 . V_46 = V_3 ;
V_60 . V_47 = V_29 ;
} else {
V_60 . V_53 = true ;
}
} while ( ! F_18 ( V_24 , V_59 , V_60 , false ) );
return V_44 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_23 * V_24 ,
T_1 V_61 , bool V_62 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_58 ;
T_2 V_9 ;
unsigned long V_33 ;
V_63:
V_8 = F_3 ( V_2 , V_61 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_8 , V_61 ) ;
return;
}
V_6 = & V_8 -> V_13 [ V_9 ] ;
F_9 ( V_33 ) ;
F_10 ( & V_8 -> V_34 ) ;
if ( ! V_24 || V_6 -> V_30 != V_24 -> V_51 ) {
V_24 = F_14 ( V_2 -> V_37 , V_6 -> V_30 ) ;
if ( ! V_24 ) {
F_28 ( L_9 ,
V_61 , V_6 -> V_30 ) ;
goto V_64;
}
}
if ( V_62 )
if ( ! V_6 -> V_27 )
goto V_64;
V_6 -> V_27 = 0 ;
if ( V_6 -> V_29 == V_36 ) {
F_2 ( L_10 , V_61 ) ;
V_6 -> V_35 = 1 ;
goto V_64;
}
if ( F_26 ( V_24 , V_61 , V_6 -> V_29 , & V_58 ) ) {
if ( V_58 && V_58 != V_65 ) {
F_11 ( & V_8 -> V_34 ) ;
F_12 ( V_33 ) ;
V_61 = V_58 ;
V_62 = 0 ;
goto V_63;
}
} else {
V_6 -> V_27 = 1 ;
F_29 () ;
F_30 ( V_8 -> V_56 , V_24 -> V_57 ) ;
F_31 () ;
if ( ! V_24 -> V_6 . V_53 ) {
V_6 -> V_27 = 0 ;
F_11 ( & V_8 -> V_34 ) ;
F_12 ( V_33 ) ;
V_62 = 0 ;
goto V_63;
}
}
V_64:
F_11 ( & V_8 -> V_34 ) ;
F_12 ( V_33 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_23 * V_24 ,
T_3 V_66 )
{
union V_40 V_59 , V_60 ;
bool V_27 ;
do {
V_59 = V_60 = F_27 ( V_24 -> V_6 ) ;
V_60 . V_48 = V_66 ;
if ( V_60 . V_52 < V_66 &&
V_60 . V_52 <= V_60 . V_47 ) {
F_33 ( V_60 . V_46 != V_65 &&
V_60 . V_46 != 0 ) ;
V_60 . V_47 = V_60 . V_52 ;
V_60 . V_46 = V_65 ;
}
V_27 = V_60 . V_53 ;
V_60 . V_53 = 0 ;
} while ( ! F_18 ( V_24 , V_59 , V_60 , true ) );
if ( V_27 )
F_22 ( V_2 , V_24 ) ;
}
static T_4 unsigned long F_34 ( struct V_67 * V_54 )
{
union V_40 V_59 , V_60 ;
struct V_23 * V_24 = V_54 -> V_38 . V_24 ;
T_1 V_68 ;
F_35 ( V_24 -> V_54 ,
V_55 ) ;
do {
V_59 = V_60 = F_27 ( V_24 -> V_6 ) ;
V_68 = V_59 . V_46 | ( ( ( T_1 ) V_59 . V_48 ) << 24 ) ;
if ( ! V_59 . V_46 )
break;
V_60 . V_48 = V_60 . V_47 ;
V_60 . V_47 = 0xff ;
V_60 . V_46 = 0 ;
} while ( ! F_18 ( V_24 , V_59 , V_60 , true ) );
F_2 ( L_11 , V_54 -> V_69 , V_68 ) ;
return V_68 ;
}
static T_4 int F_36 ( struct V_67 * V_54 , unsigned long V_30 ,
unsigned long V_52 )
{
union V_40 V_59 , V_60 ;
struct V_1 * V_2 = V_54 -> V_37 -> V_38 . V_2 ;
struct V_23 * V_24 ;
T_1 V_58 ;
bool V_27 ;
bool V_70 ;
F_2 ( L_12 ,
V_54 -> V_69 , V_30 , V_52 ) ;
V_24 = V_54 -> V_38 . V_24 ;
V_70 = V_24 -> V_51 == V_30 ;
if ( ! V_70 ) {
V_24 = F_14 ( V_54 -> V_37 , V_30 ) ;
if ( ! V_24 )
return V_71 ;
}
do {
V_59 = V_60 = F_27 ( V_24 -> V_6 ) ;
V_60 . V_52 = V_52 ;
V_58 = 0 ;
V_27 = false ;
if ( V_52 < V_60 . V_48 ) {
if ( V_52 <= V_60 . V_47 ) {
V_58 = V_60 . V_46 ;
V_60 . V_47 = V_52 ;
V_60 . V_46 = V_65 ;
}
}
if ( V_52 > V_59 . V_52 ) {
V_27 = V_60 . V_53 ;
V_60 . V_53 = 0 ;
}
} while ( ! F_18 ( V_24 , V_59 , V_60 , V_70 ) );
if ( V_58 && V_58 != V_65 )
F_5 ( V_2 , V_24 , V_58 , false ) ;
if ( V_27 )
F_22 ( V_2 , V_24 ) ;
return V_72 ;
}
static int F_37 ( struct V_67 * V_54 , unsigned long V_30 )
{
union V_40 V_6 ;
struct V_23 * V_24 ;
V_24 = V_54 -> V_38 . V_24 ;
if ( V_24 -> V_51 != V_30 ) {
V_24 = F_14 ( V_54 -> V_37 , V_30 ) ;
if ( ! V_24 )
return V_71 ;
}
V_6 = F_27 ( V_24 -> V_6 ) ;
F_38 ( V_54 , 4 , ( ( T_1 ) V_6 . V_48 << 24 ) | V_6 . V_46 ) ;
F_38 ( V_54 , 5 , V_6 . V_52 ) ;
return V_72 ;
}
static T_4 void F_39 ( struct V_67 * V_54 , unsigned long V_48 )
{
union V_40 V_59 , V_60 ;
struct V_1 * V_2 = V_54 -> V_37 -> V_38 . V_2 ;
struct V_23 * V_24 = V_54 -> V_38 . V_24 ;
T_1 V_58 ;
F_2 ( L_13 , V_54 -> V_69 , V_48 ) ;
if ( V_48 > V_24 -> V_6 . V_48 )
F_32 ( V_2 , V_24 , V_48 ) ;
else if ( V_48 == V_24 -> V_6 . V_48 )
return;
F_35 ( V_24 -> V_54 ,
V_55 ) ;
do {
V_59 = V_60 = F_27 ( V_24 -> V_6 ) ;
V_58 = 0 ;
V_60 . V_48 = V_48 ;
if ( V_48 <= V_60 . V_47 ) {
V_58 = V_60 . V_46 ;
V_60 . V_46 = 0 ;
V_60 . V_47 = 0xff ;
}
} while ( ! F_18 ( V_24 , V_59 , V_60 , true ) );
if ( V_58 && V_58 != V_65 )
F_5 ( V_2 , V_24 , V_58 , false ) ;
}
static int F_40 ( struct V_67 * V_54 , T_1 V_3 )
{
struct V_1 * V_2 = V_54 -> V_37 -> V_38 . V_2 ;
struct V_23 * V_24 = V_54 -> V_38 . V_24 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
T_1 V_10 , V_11 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_14 , V_3 ) ;
return V_71 ;
}
V_6 = & V_8 -> V_13 [ V_9 ] ;
if ( V_6 -> V_18 )
V_11 = V_6 -> V_19 ;
else
do {
V_10 = V_6 -> V_19 ;
V_11 = V_10 >> 1 ;
} while ( F_4 ( & V_6 -> V_19 , V_10 , V_11 ) != V_10 );
if ( V_11 & V_20 )
F_5 ( V_2 , V_24 , V_3 , false ) ;
F_41 ( V_54 -> V_37 , 0 , V_3 ) ;
return V_72 ;
}
static T_4 int F_42 ( struct V_67 * V_54 , unsigned long V_68 )
{
struct V_1 * V_2 = V_54 -> V_37 -> V_38 . V_2 ;
struct V_23 * V_24 = V_54 -> V_38 . V_24 ;
T_1 V_3 = V_68 & 0x00ffffff ;
F_2 ( L_15 , V_54 -> V_69 , V_68 ) ;
F_32 ( V_2 , V_24 , V_68 >> 24 ) ;
if ( V_3 == V_65 )
return V_72 ;
return F_40 ( V_54 , V_3 ) ;
}
int F_43 ( struct V_67 * V_54 , T_1 V_73 )
{
struct V_1 * V_2 = V_54 -> V_37 -> V_38 . V_2 ;
struct V_23 * V_24 = V_54 -> V_38 . V_24 ;
F_2 ( L_16 ,
V_73 , V_24 -> V_74 , V_24 -> V_75 . V_49 , V_24 -> V_76 ) ;
if ( V_24 -> V_74 & V_77 ) {
V_24 -> V_78 ++ ;
F_21 ( V_24 -> V_79 ) ;
}
if ( V_24 -> V_74 & V_80 ) {
V_24 -> V_81 ++ ;
F_22 ( V_2 , V_24 -> V_82 ) ;
}
if ( V_24 -> V_74 & V_83 ) {
V_24 -> V_84 ++ ;
F_41 ( V_54 -> V_37 , 0 , V_24 -> V_85 ) ;
}
V_24 -> V_74 = 0 ;
return V_72 ;
}
int F_44 ( struct V_67 * V_54 , T_1 V_86 )
{
struct V_1 * V_2 = V_54 -> V_37 -> V_38 . V_2 ;
unsigned long V_87 ;
int V_88 = V_72 ;
if ( ! V_2 || ! V_54 -> V_38 . V_24 )
return V_89 ;
switch ( V_86 ) {
case V_90 :
V_87 = F_34 ( V_54 ) ;
F_38 ( V_54 , 4 , V_87 ) ;
F_38 ( V_54 , 5 , F_45 () ) ;
return V_88 ;
case V_91 :
V_88 = F_37 ( V_54 , F_46 ( V_54 , 4 ) ) ;
return V_88 ;
}
if ( V_2 -> V_92 && F_47 ( V_54 -> V_37 ) )
return F_43 ( V_54 , V_86 ) ;
switch ( V_86 ) {
case V_93 :
V_87 = F_34 ( V_54 ) ;
F_38 ( V_54 , 4 , V_87 ) ;
break;
case V_94 :
F_39 ( V_54 , F_46 ( V_54 , 4 ) ) ;
break;
case V_95 :
V_88 = F_42 ( V_54 , F_46 ( V_54 , 4 ) ) ;
break;
case V_96 :
V_88 = F_36 ( V_54 , F_46 ( V_54 , 4 ) ,
F_46 ( V_54 , 5 ) ) ;
break;
}
return V_88 ;
}
static void F_48 ( struct V_97 * V_98 ,
struct V_99 * V_100 )
{
int V_25 ;
if ( ! V_100 )
return;
F_49 ( V_98 , L_17 ,
V_100 -> V_101 ) ;
for ( V_25 = 0 ; V_25 < V_100 -> V_101 ; V_25 ++ ) {
F_49 ( V_98 , L_18 ,
V_100 -> V_102 [ V_25 ] . V_103 , V_100 -> V_102 [ V_25 ] . V_104 ) ;
}
}
static int F_50 ( struct V_97 * V_98 , void * V_105 )
{
struct V_1 * V_2 = V_98 -> V_105 ;
struct V_37 * V_37 = V_2 -> V_37 ;
struct V_67 * V_54 ;
int V_56 , V_25 ;
unsigned long V_33 ;
unsigned long V_106 , V_107 ;
unsigned long V_108 ;
unsigned long V_109 , V_110 ;
if ( ! V_37 )
return 0 ;
V_106 = 0 ;
V_108 = 0 ;
V_107 = 0 ;
V_110 = 0 ;
V_109 = 0 ;
F_48 ( V_98 , V_37 -> V_38 . V_100 ) ;
F_49 ( V_98 , L_19 ) ;
F_51 (i, vcpu, kvm) {
struct V_23 * V_24 = V_54 -> V_38 . V_24 ;
union V_40 V_6 ;
if ( ! V_24 )
continue;
V_6 . V_49 = F_27 ( V_24 -> V_6 . V_49 ) ;
F_49 ( V_98 , L_20 ,
V_24 -> V_51 , V_6 . V_46 ,
V_6 . V_47 , V_6 . V_48 , V_6 . V_52 ,
V_6 . V_45 , V_6 . V_53 ) ;
V_106 += V_24 -> V_78 ;
V_108 += V_24 -> V_84 ;
V_107 += V_24 -> V_81 ;
V_110 += V_24 -> V_111 ;
V_109 += V_24 -> V_112 ;
}
F_49 ( V_98 , L_21 ,
V_106 , V_107 ,
V_108 ) ;
F_49 ( V_98 , L_22 ,
V_110 , V_109 ) ;
for ( V_56 = 0 ; V_56 <= V_113 ; V_56 ++ ) {
struct V_7 * V_8 = V_2 -> V_8 [ V_56 ] ;
if ( ! V_8 )
continue;
F_49 ( V_98 , L_23 ,
V_56 ) ;
F_9 ( V_33 ) ;
F_10 ( & V_8 -> V_34 ) ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
struct V_5 * V_3 = & V_8 -> V_13 [ V_25 ] ;
F_49 ( V_98 , L_24 ,
V_3 -> V_28 , V_3 -> V_30 , V_3 -> V_29 ,
V_3 -> V_31 , V_3 -> V_19 ,
V_3 -> V_27 , V_3 -> V_35 ) ;
}
F_11 ( & V_8 -> V_34 ) ;
F_12 ( V_33 ) ;
}
return 0 ;
}
static int F_52 ( struct V_114 * V_114 , struct V_115 * V_115 )
{
return F_53 ( V_115 , F_50 , V_114 -> V_116 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
char * V_117 ;
V_117 = F_55 ( V_118 , L_25 , V_2 ) ;
if ( ! V_117 ) {
F_56 ( L_26 , V_119 ) ;
return;
}
V_2 -> V_120 = F_57 ( V_117 , V_121 , V_122 ,
V_2 , & V_123 ) ;
F_58 ( L_27 , V_119 , V_117 ) ;
F_59 ( V_117 ) ;
}
static struct V_7 * F_60 ( struct V_37 * V_37 ,
struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 ;
int V_25 , V_56 ;
V_56 = V_3 >> V_124 ;
F_61 ( & V_37 -> V_34 ) ;
if ( V_2 -> V_8 [ V_56 ] )
goto V_64;
V_8 = F_62 ( sizeof( struct V_7 ) , V_118 ) ;
if ( ! V_8 )
goto V_64;
V_8 -> V_56 = V_56 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
V_8 -> V_13 [ V_25 ] . V_28 = ( V_56 << V_124 ) | V_25 ;
V_8 -> V_13 [ V_25 ] . V_29 = V_36 ;
V_8 -> V_13 [ V_25 ] . V_31 = V_36 ;
}
F_29 () ;
V_2 -> V_8 [ V_56 ] = V_8 ;
if ( V_56 > V_2 -> V_125 )
V_2 -> V_125 = V_56 ;
V_64:
F_63 ( & V_37 -> V_34 ) ;
return V_2 -> V_8 [ V_56 ] ;
}
int F_64 ( struct V_67 * V_54 , unsigned long V_51 )
{
struct V_23 * V_24 ;
if ( ! V_54 -> V_37 -> V_38 . V_2 )
return - V_39 ;
if ( F_14 ( V_54 -> V_37 , V_51 ) )
return - V_126 ;
V_24 = F_62 ( sizeof( struct V_23 ) , V_118 ) ;
if ( ! V_24 )
return - V_127 ;
V_24 -> V_54 = V_54 ;
V_24 -> V_51 = V_51 ;
V_24 -> V_6 . V_52 = V_36 ;
V_24 -> V_6 . V_47 = V_36 ;
V_54 -> V_38 . V_24 = V_24 ;
F_2 ( L_28 , V_54 -> V_69 ) ;
return 0 ;
}
T_5 F_65 ( struct V_67 * V_54 )
{
struct V_23 * V_24 = V_54 -> V_38 . V_24 ;
union V_40 V_6 ;
if ( ! V_24 )
return 0 ;
V_6 = V_24 -> V_6 ;
return ( ( T_5 ) V_6 . V_48 << V_128 ) |
( ( T_5 ) V_6 . V_46 << V_129 ) |
( ( T_5 ) V_6 . V_52 << V_130 ) |
( ( T_5 ) V_6 . V_47 << V_131 ) ;
}
int F_66 ( struct V_67 * V_54 , T_5 V_132 )
{
struct V_23 * V_24 = V_54 -> V_38 . V_24 ;
struct V_1 * V_2 = V_54 -> V_37 -> V_38 . V_2 ;
union V_40 V_59 , V_60 ;
struct V_7 * V_8 ;
T_3 V_48 , V_52 , V_47 ;
T_1 V_46 ;
T_2 V_9 ;
bool V_27 ;
if ( ! V_24 || ! V_2 )
return - V_133 ;
V_48 = V_132 >> V_128 ;
V_46 = ( V_132 >> V_129 ) &
V_134 ;
V_52 = V_132 >> V_130 ;
V_47 = V_132 >> V_131 ;
if ( V_46 == 0 ) {
if ( V_47 != 0xff )
return - V_12 ;
} else if ( V_46 == V_65 ) {
if ( V_47 != V_52 || V_47 >= V_48 )
return - V_12 ;
} else {
if ( V_47 >= V_52 || V_47 >= V_48 )
return - V_12 ;
V_8 = F_3 ( V_2 , V_46 , & V_9 ) ;
if ( ! V_8 )
return - V_12 ;
}
V_60 . V_49 = 0 ;
V_60 . V_48 = V_48 ;
V_60 . V_46 = V_46 ;
V_60 . V_52 = V_52 ;
V_60 . V_47 = V_47 ;
F_35 ( V_24 -> V_54 ,
V_55 ) ;
do {
V_59 = F_27 ( V_24 -> V_6 ) ;
if ( V_60 . V_52 <= V_59 . V_52 ) {
V_27 = false ;
V_60 . V_53 = V_59 . V_53 ;
} else {
V_27 = V_59 . V_53 ;
V_60 . V_53 = 0 ;
}
} while ( ! F_18 ( V_24 , V_59 , V_60 , false ) );
if ( V_27 )
F_22 ( V_2 , V_24 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , long V_3 , T_5 V_135 )
{
int V_136 ;
struct V_7 * V_8 ;
struct V_5 * V_137 ;
T_5 T_6 * V_138 = ( T_5 T_6 * ) V_135 ;
T_2 V_139 ;
T_5 V_140 , V_141 ;
unsigned long V_33 ;
V_8 = F_3 ( V_2 , V_3 , & V_139 ) ;
if ( ! V_8 )
return - V_133 ;
V_137 = & V_8 -> V_13 [ V_139 ] ;
F_9 ( V_33 ) ;
F_10 ( & V_8 -> V_34 ) ;
V_136 = - V_133 ;
if ( V_137 -> V_14 ) {
V_140 = V_137 -> V_30 ;
V_141 = V_137 -> V_29 ;
if ( V_141 == V_36 ) {
V_140 |= V_142 ;
V_141 = V_137 -> V_31 ;
}
V_140 |= V_141 << V_143 ;
if ( V_137 -> V_18 ) {
V_140 |= V_144 ;
if ( V_137 -> V_19 & V_20 )
V_140 |= V_145 ;
} else if ( V_137 -> V_35 || V_137 -> V_27 )
V_140 |= V_145 ;
if ( V_137 -> V_19 & V_20 )
V_140 |= V_146 ;
if ( V_137 -> V_19 & V_147 )
V_140 |= V_148 ;
V_136 = 0 ;
}
F_11 ( & V_8 -> V_34 ) ;
F_12 ( V_33 ) ;
if ( ! V_136 && F_68 ( V_140 , V_138 ) )
V_136 = - V_149 ;
return V_136 ;
}
static int F_69 ( struct V_1 * V_2 , long V_3 , T_5 V_135 )
{
struct V_7 * V_8 ;
struct V_5 * V_137 ;
T_5 T_6 * V_138 = ( T_5 T_6 * ) V_135 ;
T_2 V_139 ;
T_5 V_140 ;
T_3 V_141 ;
T_1 V_30 ;
unsigned long V_33 ;
if ( V_3 < V_150 || V_3 >= V_151 )
return - V_133 ;
V_8 = F_3 ( V_2 , V_3 , & V_139 ) ;
if ( ! V_8 ) {
V_8 = F_60 ( V_2 -> V_37 , V_2 , V_3 ) ;
if ( ! V_8 )
return - V_127 ;
}
V_137 = & V_8 -> V_13 [ V_139 ] ;
if ( F_70 ( V_140 , V_138 ) )
return - V_149 ;
V_30 = V_140 & V_152 ;
V_141 = V_140 >> V_143 ;
if ( V_141 != V_36 &&
F_14 ( V_2 -> V_37 , V_30 ) == NULL )
return - V_12 ;
F_9 ( V_33 ) ;
F_10 ( & V_8 -> V_34 ) ;
V_137 -> V_30 = V_30 ;
V_137 -> V_31 = V_141 ;
if ( V_140 & V_142 )
V_141 = V_36 ;
V_137 -> V_29 = V_141 ;
V_137 -> V_27 = 0 ;
V_137 -> V_35 = 0 ;
V_137 -> V_18 = 0 ;
V_137 -> V_19 = 0 ;
if ( V_140 & V_144 )
V_137 -> V_18 = 1 ;
if ( V_140 & V_146 || V_140 & V_145 )
V_137 -> V_19 |= V_20 ;
if ( V_140 & V_148 )
V_137 -> V_19 |= V_147 ;
V_137 -> V_14 = 1 ;
F_11 ( & V_8 -> V_34 ) ;
F_12 ( V_33 ) ;
if ( V_140 & V_145 )
F_5 ( V_2 , NULL , V_137 -> V_28 , false ) ;
return 0 ;
}
int F_71 ( struct V_37 * V_37 , int V_153 , T_1 V_3 , int V_4 ,
bool V_154 )
{
struct V_1 * V_2 = V_37 -> V_38 . V_2 ;
if ( ! V_2 )
return - V_39 ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_72 ( struct V_155 * V_156 ,
struct V_37 * V_37 , int V_153 ,
int V_4 , bool V_154 )
{
return F_71 ( V_37 , V_153 , V_156 -> V_157 ,
V_4 , V_154 ) ;
}
static int F_73 ( struct V_158 * V_159 , struct V_160 * V_161 )
{
struct V_1 * V_2 = V_159 -> V_105 ;
switch ( V_161 -> V_162 ) {
case V_163 :
return F_69 ( V_2 , V_161 -> V_161 , V_161 -> V_135 ) ;
}
return - V_164 ;
}
static int F_74 ( struct V_158 * V_159 , struct V_160 * V_161 )
{
struct V_1 * V_2 = V_159 -> V_105 ;
switch ( V_161 -> V_162 ) {
case V_163 :
return F_67 ( V_2 , V_161 -> V_161 , V_161 -> V_135 ) ;
}
return - V_164 ;
}
static int F_75 ( struct V_158 * V_159 , struct V_160 * V_161 )
{
switch ( V_161 -> V_162 ) {
case V_163 :
if ( V_161 -> V_161 >= V_150 &&
V_161 -> V_161 < V_151 )
return 0 ;
break;
}
return - V_164 ;
}
static void F_76 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = V_159 -> V_105 ;
int V_25 ;
struct V_37 * V_37 = V_2 -> V_37 ;
F_77 ( V_2 -> V_120 ) ;
if ( V_37 )
V_37 -> V_38 . V_2 = NULL ;
for ( V_25 = 0 ; V_25 <= V_2 -> V_125 ; V_25 ++ )
F_59 ( V_2 -> V_8 [ V_25 ] ) ;
F_59 ( V_2 ) ;
F_59 ( V_159 ) ;
}
static int F_78 ( struct V_158 * V_159 , T_1 type )
{
struct V_1 * V_2 ;
struct V_37 * V_37 = V_159 -> V_37 ;
int V_136 = 0 ;
V_2 = F_62 ( sizeof( * V_2 ) , V_118 ) ;
if ( ! V_2 )
return - V_127 ;
V_159 -> V_105 = V_2 ;
V_2 -> V_159 = V_159 ;
V_2 -> V_37 = V_37 ;
if ( V_37 -> V_38 . V_2 )
V_136 = - V_126 ;
else
V_37 -> V_38 . V_2 = V_2 ;
if ( V_136 ) {
F_59 ( V_2 ) ;
return V_136 ;
}
#ifdef F_79
if ( F_80 ( V_165 ) ) {
V_2 -> V_92 = V_166 ;
V_2 -> V_167 = V_168 ;
}
#endif
return 0 ;
}
static void F_81 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = (struct V_1 * ) V_159 -> V_105 ;
F_54 ( V_2 ) ;
}
int F_82 ( struct V_158 * V_159 , struct V_67 * V_54 ,
T_1 V_169 )
{
struct V_1 * V_2 = V_159 -> V_105 ;
int V_170 = - V_171 ;
if ( V_159 -> V_172 != & V_173 )
return - V_174 ;
if ( V_2 -> V_37 != V_54 -> V_37 )
return - V_174 ;
if ( V_54 -> V_38 . V_175 )
return - V_171 ;
V_170 = F_64 ( V_54 , V_169 ) ;
if ( ! V_170 )
V_54 -> V_38 . V_175 = V_176 ;
return V_170 ;
}
void F_83 ( struct V_67 * V_54 )
{
if ( ! V_54 -> V_38 . V_24 )
return;
F_59 ( V_54 -> V_38 . V_24 ) ;
V_54 -> V_38 . V_24 = NULL ;
V_54 -> V_38 . V_175 = V_177 ;
}
static int F_84 ( struct V_155 * V_178 ,
struct V_37 * V_37 , int V_153 , int V_4 ,
bool V_154 )
{
return F_71 ( V_37 , V_153 , V_178 -> V_157 , V_4 , V_154 ) ;
}
int F_85 ( struct V_37 * V_37 ,
struct V_155 * V_179 , int V_157 )
{
V_179 -> V_157 = V_157 ;
V_179 -> type = V_180 ;
V_179 -> V_181 = F_84 ;
V_179 -> V_182 . V_182 = 0 ;
V_179 -> V_182 . V_183 = V_157 ;
return 1 ;
}
int F_86 ( struct V_37 * V_37 , unsigned V_182 , unsigned V_183 )
{
return V_183 ;
}
void F_87 ( struct V_37 * V_37 , unsigned long V_3 ,
unsigned long V_21 )
{
struct V_1 * V_2 = V_37 -> V_38 . V_2 ;
struct V_7 * V_8 ;
T_2 V_139 ;
V_8 = F_3 ( V_2 , V_3 , & V_139 ) ;
if ( ! V_8 )
return;
V_8 -> V_13 [ V_139 ] . V_21 = V_21 ;
V_8 -> V_13 [ V_139 ] . V_22 = - 1 ;
}
void F_88 ( struct V_37 * V_37 , unsigned long V_3 ,
unsigned long V_21 )
{
struct V_1 * V_2 = V_37 -> V_38 . V_2 ;
struct V_7 * V_8 ;
T_2 V_139 ;
V_8 = F_3 ( V_2 , V_3 , & V_139 ) ;
if ( ! V_8 )
return;
V_8 -> V_13 [ V_139 ] . V_21 = 0 ;
}
