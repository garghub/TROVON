static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
bool V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_2 V_10 ;
F_2 ( L_1 , V_3 , V_4 ) ;
V_9 = F_3 ( V_2 , V_3 , & V_10 ) ;
if ( ! V_9 ) {
F_2 ( L_2 , V_3 ) ;
return - V_11 ;
}
V_7 = & V_9 -> V_12 [ V_10 ] ;
if ( ! V_7 -> V_13 )
return - V_11 ;
if ( V_5 )
return V_7 -> V_14 ;
if ( V_4 == V_15 )
V_7 -> V_14 = 1 ;
else if ( V_4 == V_16 ) {
V_7 -> V_14 = 0 ;
return 0 ;
}
F_4 ( V_2 , NULL , V_3 ) ;
return V_7 -> V_14 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_17 * V_18 )
{
int V_19 ;
F_6 ( & V_9 -> V_20 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
struct V_6 * V_7 = & V_9 -> V_12 [ V_19 ] ;
if ( ! V_7 -> V_22 )
continue;
F_2 ( L_3 , V_7 -> V_23 ,
V_7 -> V_24 ) ;
F_7 ( & V_9 -> V_20 ) ;
F_4 ( V_2 , V_18 , V_7 -> V_23 ) ;
F_6 ( & V_9 -> V_20 ) ;
}
F_7 ( & V_9 -> V_20 ) ;
}
static bool F_8 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_6 * V_7 ,
T_1 V_25 , T_1 V_24 , T_1 V_26 )
{
bool V_27 ;
F_6 ( & V_9 -> V_20 ) ;
V_7 -> V_25 = V_25 ;
V_7 -> V_24 = V_24 ;
V_7 -> V_26 = V_26 ;
V_27 = false ;
if ( ( V_7 -> V_28 || V_7 -> V_22 ) && V_24 != V_29 ) {
V_7 -> V_28 = 0 ;
V_27 = true ;
}
F_7 ( & V_9 -> V_20 ) ;
return V_27 ;
}
int F_9 ( struct V_30 * V_30 , T_1 V_3 , T_1 V_25 , T_1 V_24 )
{
struct V_1 * V_2 = V_30 -> V_31 . V_2 ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
T_2 V_10 ;
if ( ! V_2 )
return - V_32 ;
V_9 = F_3 ( V_2 , V_3 , & V_10 ) ;
if ( ! V_9 )
return - V_11 ;
V_7 = & V_9 -> V_12 [ V_10 ] ;
V_18 = F_10 ( V_30 , V_25 ) ;
if ( ! V_18 )
return - V_11 ;
F_2 ( L_4 ,
V_3 , V_25 , V_24 ,
V_7 -> V_28 , V_7 -> V_22 ) ;
if ( F_8 ( V_2 , V_9 , V_7 , V_25 , V_24 , V_24 ) )
F_4 ( V_2 , V_18 , V_3 ) ;
return 0 ;
}
int F_11 ( struct V_30 * V_30 , T_1 V_3 , T_1 * V_25 , T_1 * V_24 )
{
struct V_1 * V_2 = V_30 -> V_31 . V_2 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
T_2 V_10 ;
if ( ! V_2 )
return - V_32 ;
V_9 = F_3 ( V_2 , V_3 , & V_10 ) ;
if ( ! V_9 )
return - V_11 ;
V_7 = & V_9 -> V_12 [ V_10 ] ;
F_6 ( & V_9 -> V_20 ) ;
* V_25 = V_7 -> V_25 ;
* V_24 = V_7 -> V_24 ;
F_7 ( & V_9 -> V_20 ) ;
return 0 ;
}
int F_12 ( struct V_30 * V_30 , T_1 V_3 )
{
struct V_1 * V_2 = V_30 -> V_31 . V_2 ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
T_2 V_10 ;
if ( ! V_2 )
return - V_32 ;
V_9 = F_3 ( V_2 , V_3 , & V_10 ) ;
if ( ! V_9 )
return - V_11 ;
V_7 = & V_9 -> V_12 [ V_10 ] ;
V_18 = F_10 ( V_30 , V_7 -> V_25 ) ;
if ( ! V_18 )
return - V_11 ;
if ( F_8 ( V_2 , V_9 , V_7 , V_7 -> V_25 , V_7 -> V_26 ,
V_7 -> V_26 ) )
F_4 ( V_2 , V_18 , V_3 ) ;
return 0 ;
}
int F_13 ( struct V_30 * V_30 , T_1 V_3 )
{
struct V_1 * V_2 = V_30 -> V_31 . V_2 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
T_2 V_10 ;
if ( ! V_2 )
return - V_32 ;
V_9 = F_3 ( V_2 , V_3 , & V_10 ) ;
if ( ! V_9 )
return - V_11 ;
V_7 = & V_9 -> V_12 [ V_10 ] ;
F_8 ( V_2 , V_9 , V_7 , V_7 -> V_25 , V_29 , V_7 -> V_24 ) ;
return 0 ;
}
static inline bool F_14 ( struct V_17 * V_18 ,
union V_33 V_34 ,
union V_33 V_35 ,
bool V_36 )
{
bool V_37 ;
V_35 . V_38 = ( V_35 . V_39 && ( V_35 . V_40 < V_35 . V_41 ) ) ;
V_37 = F_15 ( & V_18 -> V_7 . V_42 , V_34 . V_42 , V_35 . V_42 ) == V_34 . V_42 ;
if ( ! V_37 )
goto V_43;
F_2 ( L_5 ,
V_18 -> V_44 ,
V_34 . V_41 , V_34 . V_45 , V_34 . V_40 , V_34 . V_39 ,
V_34 . V_46 , V_34 . V_38 ) ;
F_2 ( L_6 ,
V_35 . V_41 , V_35 . V_45 , V_35 . V_40 , V_35 . V_39 ,
V_35 . V_46 , V_35 . V_38 ) ;
if ( V_35 . V_38 ) {
F_16 ( V_18 -> V_47 ,
V_48 ) ;
if ( ! V_36 )
F_17 ( V_18 -> V_47 ) ;
}
V_43:
return V_37 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
T_1 V_49 ;
F_19 () ;
F_20 (icsid, icp->resend_map, xics->max_icsid + 1 ) {
struct V_8 * V_9 = V_2 -> V_9 [ V_49 ] ;
if ( ! F_21 ( V_49 , V_18 -> V_50 ) )
continue;
if ( ! V_9 )
continue;
F_5 ( V_2 , V_9 , V_18 ) ;
}
}
static bool F_22 ( struct V_17 * V_18 , T_1 V_3 , T_3 V_24 ,
T_1 * V_51 )
{
union V_33 V_52 , V_53 ;
bool V_37 ;
F_2 ( L_7 , V_3 , V_24 ,
V_18 -> V_44 ) ;
do {
V_52 = V_53 = F_23 ( V_18 -> V_7 ) ;
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
} while ( ! F_14 ( V_18 , V_52 , V_53 , false ) );
return V_37 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_17 * V_18 ,
T_1 V_54 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_1 V_51 ;
T_2 V_10 ;
V_55:
V_9 = F_3 ( V_2 , V_54 , & V_10 ) ;
if ( ! V_9 ) {
F_2 ( L_8 , V_54 ) ;
return;
}
V_7 = & V_9 -> V_12 [ V_10 ] ;
F_6 ( & V_9 -> V_20 ) ;
if ( ! V_18 || V_7 -> V_25 != V_18 -> V_44 ) {
V_18 = F_10 ( V_2 -> V_30 , V_7 -> V_25 ) ;
if ( ! V_18 ) {
F_24 ( L_9 ,
V_54 , V_7 -> V_25 ) ;
goto V_56;
}
}
V_7 -> V_22 = 0 ;
if ( V_7 -> V_24 == V_29 ) {
F_2 ( L_10 , V_54 ) ;
V_7 -> V_28 = 1 ;
goto V_56;
}
if ( F_22 ( V_18 , V_54 , V_7 -> V_24 , & V_51 ) ) {
if ( V_51 && V_51 != V_57 ) {
F_7 ( & V_9 -> V_20 ) ;
V_54 = V_51 ;
goto V_55;
}
} else {
F_25 ( V_9 -> V_49 , V_18 -> V_50 ) ;
V_7 -> V_22 = 1 ;
F_26 () ;
if ( ! V_18 -> V_7 . V_46 ) {
F_7 ( & V_9 -> V_20 ) ;
goto V_55;
}
}
V_56:
F_7 ( & V_9 -> V_20 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_17 * V_18 ,
T_3 V_58 )
{
union V_33 V_52 , V_53 ;
bool V_22 ;
do {
V_52 = V_53 = F_23 ( V_18 -> V_7 ) ;
V_53 . V_41 = V_58 ;
if ( V_53 . V_45 < V_58 &&
V_53 . V_45 <= V_53 . V_40 ) {
F_28 ( V_53 . V_39 != V_57 &&
V_53 . V_39 != 0 ) ;
V_53 . V_40 = V_53 . V_45 ;
V_53 . V_39 = V_57 ;
}
V_22 = V_53 . V_46 ;
V_53 . V_46 = 0 ;
} while ( ! F_14 ( V_18 , V_52 , V_53 , true ) );
if ( V_22 )
F_18 ( V_2 , V_18 ) ;
}
static T_4 unsigned long F_29 ( struct V_59 * V_47 )
{
union V_33 V_52 , V_53 ;
struct V_17 * V_18 = V_47 -> V_31 . V_18 ;
T_1 V_60 ;
F_30 ( V_18 -> V_47 ,
V_48 ) ;
do {
V_52 = V_53 = F_23 ( V_18 -> V_7 ) ;
V_60 = V_52 . V_39 | ( ( ( T_1 ) V_52 . V_41 ) << 24 ) ;
if ( ! V_52 . V_39 )
break;
V_53 . V_41 = V_53 . V_40 ;
V_53 . V_40 = 0xff ;
V_53 . V_39 = 0 ;
} while ( ! F_14 ( V_18 , V_52 , V_53 , true ) );
F_2 ( L_11 , V_47 -> V_61 , V_60 ) ;
return V_60 ;
}
static T_4 int F_31 ( struct V_59 * V_47 , unsigned long V_25 ,
unsigned long V_45 )
{
union V_33 V_52 , V_53 ;
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
struct V_17 * V_18 ;
T_1 V_51 ;
bool V_22 ;
bool V_62 ;
F_2 ( L_12 ,
V_47 -> V_61 , V_25 , V_45 ) ;
V_18 = V_47 -> V_31 . V_18 ;
V_62 = V_18 -> V_44 == V_25 ;
if ( ! V_62 ) {
V_18 = F_10 ( V_47 -> V_30 , V_25 ) ;
if ( ! V_18 )
return V_63 ;
}
do {
V_52 = V_53 = F_23 ( V_18 -> V_7 ) ;
V_53 . V_45 = V_45 ;
V_51 = 0 ;
V_22 = false ;
if ( V_45 < V_53 . V_41 ) {
if ( V_45 <= V_53 . V_40 )
V_51 = V_53 . V_39 ;
V_53 . V_40 = V_45 ;
V_53 . V_39 = V_57 ;
}
if ( V_45 > V_52 . V_45 && V_45 > V_53 . V_41 ) {
V_22 = V_53 . V_46 ;
V_53 . V_46 = 0 ;
}
} while ( ! F_14 ( V_18 , V_52 , V_53 , V_62 ) );
if ( V_51 && V_51 != V_57 )
F_4 ( V_2 , V_18 , V_51 ) ;
if ( V_22 )
F_18 ( V_2 , V_18 ) ;
return V_64 ;
}
static int F_32 ( struct V_59 * V_47 , unsigned long V_25 )
{
union V_33 V_7 ;
struct V_17 * V_18 ;
V_18 = V_47 -> V_31 . V_18 ;
if ( V_18 -> V_44 != V_25 ) {
V_18 = F_10 ( V_47 -> V_30 , V_25 ) ;
if ( ! V_18 )
return V_63 ;
}
V_7 = F_23 ( V_18 -> V_7 ) ;
F_33 ( V_47 , 4 , ( ( T_1 ) V_7 . V_41 << 24 ) | V_7 . V_39 ) ;
F_33 ( V_47 , 5 , V_7 . V_45 ) ;
return V_64 ;
}
static T_4 void F_34 ( struct V_59 * V_47 , unsigned long V_41 )
{
union V_33 V_52 , V_53 ;
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
struct V_17 * V_18 = V_47 -> V_31 . V_18 ;
T_1 V_51 ;
F_2 ( L_13 , V_47 -> V_61 , V_41 ) ;
if ( V_41 > V_18 -> V_7 . V_41 )
F_27 ( V_2 , V_18 , V_41 ) ;
else if ( V_41 == V_18 -> V_7 . V_41 )
return;
F_30 ( V_18 -> V_47 ,
V_48 ) ;
do {
V_52 = V_53 = F_23 ( V_18 -> V_7 ) ;
V_51 = 0 ;
V_53 . V_41 = V_41 ;
if ( V_41 <= V_53 . V_40 ) {
V_51 = V_53 . V_39 ;
V_53 . V_39 = 0 ;
V_53 . V_40 = 0xff ;
}
} while ( ! F_14 ( V_18 , V_52 , V_53 , true ) );
if ( V_51 && V_51 != V_57 )
F_4 ( V_2 , V_18 , V_51 ) ;
}
static T_4 int F_35 ( struct V_59 * V_47 , unsigned long V_60 )
{
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
struct V_17 * V_18 = V_47 -> V_31 . V_18 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
T_1 V_3 = V_60 & 0x00ffffff ;
T_2 V_10 ;
F_2 ( L_14 , V_47 -> V_61 , V_60 ) ;
F_27 ( V_2 , V_18 , V_60 >> 24 ) ;
if ( V_3 == V_57 )
return V_64 ;
V_9 = F_3 ( V_2 , V_3 , & V_10 ) ;
if ( ! V_9 ) {
F_2 ( L_15 , V_3 ) ;
return V_63 ;
}
V_7 = & V_9 -> V_12 [ V_10 ] ;
if ( V_7 -> V_14 )
F_4 ( V_2 , V_18 , V_3 ) ;
return V_64 ;
}
static T_4 int F_36 ( struct V_59 * V_47 , T_1 V_65 )
{
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
struct V_17 * V_18 = V_47 -> V_31 . V_18 ;
F_2 ( L_16 ,
V_65 , V_18 -> V_66 , V_18 -> V_67 . V_42 , V_18 -> V_68 ) ;
if ( V_18 -> V_66 & V_69 )
F_17 ( V_18 -> V_70 ) ;
if ( V_18 -> V_66 & V_71 )
F_18 ( V_2 , V_18 ) ;
if ( V_18 -> V_66 & V_72 )
F_4 ( V_2 , V_18 , V_18 -> V_73 ) ;
V_18 -> V_66 = 0 ;
return V_64 ;
}
int F_37 ( struct V_59 * V_47 , T_1 V_74 )
{
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
unsigned long V_75 ;
int V_76 = V_64 ;
if ( ! V_2 || ! V_47 -> V_31 . V_18 )
return V_77 ;
switch ( V_74 ) {
case V_78 :
V_75 = F_29 ( V_47 ) ;
F_33 ( V_47 , 4 , V_75 ) ;
F_33 ( V_47 , 5 , F_38 () ) ;
return V_76 ;
case V_79 :
V_76 = F_32 ( V_47 , F_39 ( V_47 , 4 ) ) ;
return V_76 ;
}
if ( V_2 -> V_80 )
return F_36 ( V_47 , V_74 ) ;
switch ( V_74 ) {
case V_81 :
V_75 = F_29 ( V_47 ) ;
F_33 ( V_47 , 4 , V_75 ) ;
break;
case V_82 :
F_34 ( V_47 , F_39 ( V_47 , 4 ) ) ;
break;
case V_83 :
V_76 = F_35 ( V_47 , F_39 ( V_47 , 4 ) ) ;
break;
case V_84 :
V_76 = F_31 ( V_47 , F_39 ( V_47 , 4 ) ,
F_39 ( V_47 , 5 ) ) ;
break;
}
return V_76 ;
}
static int F_40 ( struct V_85 * V_86 , void * V_87 )
{
struct V_1 * V_2 = V_86 -> V_87 ;
struct V_30 * V_30 = V_2 -> V_30 ;
struct V_59 * V_47 ;
int V_49 , V_19 ;
if ( ! V_30 )
return 0 ;
F_41 ( V_86 , L_17 ) ;
F_42 (i, vcpu, kvm) {
struct V_17 * V_18 = V_47 -> V_31 . V_18 ;
union V_33 V_7 ;
if ( ! V_18 )
continue;
V_7 . V_42 = F_23 ( V_18 -> V_7 . V_42 ) ;
F_41 ( V_86 , L_18 ,
V_18 -> V_44 , V_7 . V_39 ,
V_7 . V_40 , V_7 . V_41 , V_7 . V_45 ,
V_7 . V_38 , V_7 . V_46 ) ;
}
for ( V_49 = 0 ; V_49 <= V_88 ; V_49 ++ ) {
struct V_8 * V_9 = V_2 -> V_9 [ V_49 ] ;
if ( ! V_9 )
continue;
F_41 ( V_86 , L_19 ,
V_49 ) ;
F_6 ( & V_9 -> V_20 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
struct V_6 * V_3 = & V_9 -> V_12 [ V_19 ] ;
F_41 ( V_86 , L_20 ,
V_3 -> V_23 , V_3 -> V_25 , V_3 -> V_24 ,
V_3 -> V_26 , V_3 -> V_14 ,
V_3 -> V_22 , V_3 -> V_28 ) ;
}
F_7 ( & V_9 -> V_20 ) ;
}
return 0 ;
}
static int F_43 ( struct V_89 * V_89 , struct V_90 * V_90 )
{
return F_44 ( V_90 , F_40 , V_89 -> V_91 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
char * V_92 ;
V_92 = F_46 ( V_93 , L_21 , V_2 ) ;
if ( ! V_92 ) {
F_47 ( L_22 , V_94 ) ;
return;
}
V_2 -> V_95 = F_48 ( V_92 , V_96 , V_97 ,
V_2 , & V_98 ) ;
F_49 ( L_23 , V_94 , V_92 ) ;
F_50 ( V_92 ) ;
}
static struct V_8 * F_51 ( struct V_30 * V_30 ,
struct V_1 * V_2 , int V_3 )
{
struct V_8 * V_9 ;
int V_19 , V_49 ;
V_49 = V_3 >> V_99 ;
F_6 ( & V_30 -> V_20 ) ;
if ( V_2 -> V_9 [ V_49 ] )
goto V_56;
V_9 = F_52 ( sizeof( struct V_8 ) , V_93 ) ;
if ( ! V_9 )
goto V_56;
F_53 ( & V_9 -> V_20 ) ;
V_9 -> V_49 = V_49 ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
V_9 -> V_12 [ V_19 ] . V_23 = ( V_49 << V_99 ) | V_19 ;
V_9 -> V_12 [ V_19 ] . V_24 = V_29 ;
V_9 -> V_12 [ V_19 ] . V_26 = V_29 ;
}
F_54 () ;
V_2 -> V_9 [ V_49 ] = V_9 ;
if ( V_49 > V_2 -> V_100 )
V_2 -> V_100 = V_49 ;
V_56:
F_7 ( & V_30 -> V_20 ) ;
return V_2 -> V_9 [ V_49 ] ;
}
int F_55 ( struct V_59 * V_47 , unsigned long V_44 )
{
struct V_17 * V_18 ;
if ( ! V_47 -> V_30 -> V_31 . V_2 )
return - V_32 ;
if ( F_10 ( V_47 -> V_30 , V_44 ) )
return - V_101 ;
V_18 = F_52 ( sizeof( struct V_17 ) , V_93 ) ;
if ( ! V_18 )
return - V_102 ;
V_18 -> V_47 = V_47 ;
V_18 -> V_44 = V_44 ;
V_18 -> V_7 . V_45 = V_29 ;
V_18 -> V_7 . V_40 = V_29 ;
V_47 -> V_31 . V_18 = V_18 ;
F_2 ( L_24 , V_47 -> V_61 ) ;
return 0 ;
}
T_5 F_56 ( struct V_59 * V_47 )
{
struct V_17 * V_18 = V_47 -> V_31 . V_18 ;
union V_33 V_7 ;
if ( ! V_18 )
return 0 ;
V_7 = V_18 -> V_7 ;
return ( ( T_5 ) V_7 . V_41 << V_103 ) |
( ( T_5 ) V_7 . V_39 << V_104 ) |
( ( T_5 ) V_7 . V_45 << V_105 ) |
( ( T_5 ) V_7 . V_40 << V_106 ) ;
}
int F_57 ( struct V_59 * V_47 , T_5 V_107 )
{
struct V_17 * V_18 = V_47 -> V_31 . V_18 ;
struct V_1 * V_2 = V_47 -> V_30 -> V_31 . V_2 ;
union V_33 V_52 , V_53 ;
struct V_8 * V_9 ;
T_3 V_41 , V_45 , V_40 ;
T_1 V_39 ;
T_2 V_10 ;
bool V_22 ;
if ( ! V_18 || ! V_2 )
return - V_108 ;
V_41 = V_107 >> V_103 ;
V_39 = ( V_107 >> V_104 ) &
V_109 ;
V_45 = V_107 >> V_105 ;
V_40 = V_107 >> V_106 ;
if ( V_39 == 0 ) {
if ( V_40 != 0xff )
return - V_11 ;
} else if ( V_39 == V_57 ) {
if ( V_40 != V_45 || V_40 >= V_41 )
return - V_11 ;
} else {
if ( V_40 >= V_45 || V_40 >= V_41 )
return - V_11 ;
V_9 = F_3 ( V_2 , V_39 , & V_10 ) ;
if ( ! V_9 )
return - V_11 ;
}
V_53 . V_42 = 0 ;
V_53 . V_41 = V_41 ;
V_53 . V_39 = V_39 ;
V_53 . V_45 = V_45 ;
V_53 . V_40 = V_40 ;
F_30 ( V_18 -> V_47 ,
V_48 ) ;
do {
V_52 = F_23 ( V_18 -> V_7 ) ;
if ( V_53 . V_45 <= V_52 . V_45 ) {
V_22 = false ;
V_53 . V_46 = V_52 . V_46 ;
} else {
V_22 = V_52 . V_46 ;
V_53 . V_46 = 0 ;
}
} while ( ! F_14 ( V_18 , V_52 , V_53 , false ) );
if ( V_22 )
F_18 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , long V_3 , T_5 V_110 )
{
int V_111 ;
struct V_8 * V_9 ;
struct V_6 * V_112 ;
T_5 T_6 * V_113 = ( T_5 T_6 * ) V_110 ;
T_2 V_114 ;
T_5 V_115 , V_116 ;
V_9 = F_3 ( V_2 , V_3 , & V_114 ) ;
if ( ! V_9 )
return - V_108 ;
V_112 = & V_9 -> V_12 [ V_114 ] ;
F_6 ( & V_9 -> V_20 ) ;
V_111 = - V_108 ;
if ( V_112 -> V_13 ) {
V_115 = V_112 -> V_25 ;
V_116 = V_112 -> V_24 ;
if ( V_116 == V_29 ) {
V_115 |= V_117 ;
V_116 = V_112 -> V_26 ;
}
V_115 |= V_116 << V_118 ;
if ( V_112 -> V_14 )
V_115 |= V_119 | V_120 ;
else if ( V_112 -> V_28 || V_112 -> V_22 )
V_115 |= V_120 ;
V_111 = 0 ;
}
F_7 ( & V_9 -> V_20 ) ;
if ( ! V_111 && F_59 ( V_115 , V_113 ) )
V_111 = - V_121 ;
return V_111 ;
}
static int F_60 ( struct V_1 * V_2 , long V_3 , T_5 V_110 )
{
struct V_8 * V_9 ;
struct V_6 * V_112 ;
T_5 T_6 * V_113 = ( T_5 T_6 * ) V_110 ;
T_2 V_114 ;
T_5 V_115 ;
T_3 V_116 ;
T_1 V_25 ;
if ( V_3 < V_122 || V_3 >= V_123 )
return - V_108 ;
V_9 = F_3 ( V_2 , V_3 , & V_114 ) ;
if ( ! V_9 ) {
V_9 = F_51 ( V_2 -> V_30 , V_2 , V_3 ) ;
if ( ! V_9 )
return - V_102 ;
}
V_112 = & V_9 -> V_12 [ V_114 ] ;
if ( F_61 ( V_115 , V_113 ) )
return - V_121 ;
V_25 = V_115 & V_124 ;
V_116 = V_115 >> V_118 ;
if ( V_116 != V_29 &&
F_10 ( V_2 -> V_30 , V_25 ) == NULL )
return - V_11 ;
F_6 ( & V_9 -> V_20 ) ;
V_112 -> V_25 = V_25 ;
V_112 -> V_26 = V_116 ;
if ( V_115 & V_117 )
V_116 = V_29 ;
V_112 -> V_24 = V_116 ;
V_112 -> V_22 = 0 ;
V_112 -> V_28 = 0 ;
V_112 -> V_14 = 0 ;
if ( ( V_115 & V_120 ) && ( V_115 & V_119 ) )
V_112 -> V_14 = 1 ;
V_112 -> V_13 = 1 ;
F_7 ( & V_9 -> V_20 ) ;
if ( V_115 & V_120 )
F_4 ( V_2 , NULL , V_112 -> V_23 ) ;
return 0 ;
}
int F_62 ( struct V_30 * V_30 , int V_125 , T_1 V_3 , int V_4 ,
bool V_126 )
{
struct V_1 * V_2 = V_30 -> V_31 . V_2 ;
return F_1 ( V_2 , V_3 , V_4 , V_126 ) ;
}
static int F_63 ( struct V_127 * V_128 , struct V_129 * V_130 )
{
struct V_1 * V_2 = V_128 -> V_87 ;
switch ( V_130 -> V_131 ) {
case V_132 :
return F_60 ( V_2 , V_130 -> V_130 , V_130 -> V_110 ) ;
}
return - V_133 ;
}
static int F_64 ( struct V_127 * V_128 , struct V_129 * V_130 )
{
struct V_1 * V_2 = V_128 -> V_87 ;
switch ( V_130 -> V_131 ) {
case V_132 :
return F_58 ( V_2 , V_130 -> V_130 , V_130 -> V_110 ) ;
}
return - V_133 ;
}
static int F_65 ( struct V_127 * V_128 , struct V_129 * V_130 )
{
switch ( V_130 -> V_131 ) {
case V_132 :
if ( V_130 -> V_130 >= V_122 &&
V_130 -> V_130 < V_123 )
return 0 ;
break;
}
return - V_133 ;
}
static void F_66 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = V_128 -> V_87 ;
int V_19 ;
struct V_30 * V_30 = V_2 -> V_30 ;
F_67 ( V_2 -> V_95 ) ;
if ( V_30 )
V_30 -> V_31 . V_2 = NULL ;
for ( V_19 = 0 ; V_19 <= V_2 -> V_100 ; V_19 ++ )
F_50 ( V_2 -> V_9 [ V_19 ] ) ;
F_50 ( V_2 ) ;
F_50 ( V_128 ) ;
}
static int F_68 ( struct V_127 * V_128 , T_1 type )
{
struct V_1 * V_2 ;
struct V_30 * V_30 = V_128 -> V_30 ;
int V_111 = 0 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_93 ) ;
if ( ! V_2 )
return - V_102 ;
V_128 -> V_87 = V_2 ;
V_2 -> V_128 = V_128 ;
V_2 -> V_30 = V_30 ;
F_6 ( & V_30 -> V_20 ) ;
if ( V_30 -> V_31 . V_2 )
V_111 = - V_101 ;
else
V_30 -> V_31 . V_2 = V_2 ;
F_7 ( & V_30 -> V_20 ) ;
if ( V_111 )
return V_111 ;
F_45 ( V_2 ) ;
#ifdef F_69
if ( F_70 ( V_134 ) ) {
V_2 -> V_80 = V_135 ;
V_2 -> V_136 = V_137 ;
}
#endif
return 0 ;
}
int F_71 ( struct V_127 * V_128 , struct V_59 * V_47 ,
T_1 V_138 )
{
struct V_1 * V_2 = V_128 -> V_87 ;
int V_139 = - V_140 ;
if ( V_128 -> V_141 != & V_142 )
return - V_143 ;
if ( V_2 -> V_30 != V_47 -> V_30 )
return - V_143 ;
if ( V_47 -> V_31 . V_144 )
return - V_140 ;
V_139 = F_55 ( V_47 , V_138 ) ;
if ( ! V_139 )
V_47 -> V_31 . V_144 = V_145 ;
return V_139 ;
}
void F_72 ( struct V_59 * V_47 )
{
if ( ! V_47 -> V_31 . V_18 )
return;
F_50 ( V_47 -> V_31 . V_18 ) ;
V_47 -> V_31 . V_18 = NULL ;
V_47 -> V_31 . V_144 = V_146 ;
}
