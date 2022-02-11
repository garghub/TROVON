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
F_6 ( & V_8 -> V_19 ) ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_5 * V_6 = & V_8 -> V_11 [ V_18 ] ;
if ( ! V_6 -> V_21 )
continue;
F_2 ( L_3 , V_6 -> V_22 ,
V_6 -> V_23 ) ;
F_7 ( & V_8 -> V_19 ) ;
F_4 ( V_2 , V_17 , V_6 -> V_22 ) ;
F_6 ( & V_8 -> V_19 ) ;
}
F_7 ( & V_8 -> V_19 ) ;
}
static bool F_8 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_5 * V_6 ,
T_1 V_24 , T_1 V_23 , T_1 V_25 )
{
bool V_26 ;
F_6 ( & V_8 -> V_19 ) ;
V_6 -> V_24 = V_24 ;
V_6 -> V_23 = V_23 ;
V_6 -> V_25 = V_25 ;
V_26 = false ;
if ( ( V_6 -> V_27 || V_6 -> V_21 ) && V_23 != V_28 ) {
V_6 -> V_27 = 0 ;
V_26 = true ;
}
F_7 ( & V_8 -> V_19 ) ;
return V_26 ;
}
int F_9 ( struct V_29 * V_29 , T_1 V_3 , T_1 V_24 , T_1 V_23 )
{
struct V_1 * V_2 = V_29 -> V_30 . V_2 ;
struct V_16 * V_17 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_31 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
V_17 = F_10 ( V_29 , V_24 ) ;
if ( ! V_17 )
return - V_10 ;
F_2 ( L_4 ,
V_3 , V_24 , V_23 ,
V_6 -> V_27 , V_6 -> V_21 ) ;
if ( F_8 ( V_2 , V_8 , V_6 , V_24 , V_23 , V_23 ) )
F_4 ( V_2 , V_17 , V_3 ) ;
return 0 ;
}
int F_11 ( struct V_29 * V_29 , T_1 V_3 , T_1 * V_24 , T_1 * V_23 )
{
struct V_1 * V_2 = V_29 -> V_30 . V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_31 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_6 ( & V_8 -> V_19 ) ;
* V_24 = V_6 -> V_24 ;
* V_23 = V_6 -> V_23 ;
F_7 ( & V_8 -> V_19 ) ;
return 0 ;
}
int F_12 ( struct V_29 * V_29 , T_1 V_3 )
{
struct V_1 * V_2 = V_29 -> V_30 . V_2 ;
struct V_16 * V_17 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_31 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
V_17 = F_10 ( V_29 , V_6 -> V_24 ) ;
if ( ! V_17 )
return - V_10 ;
if ( F_8 ( V_2 , V_8 , V_6 , V_6 -> V_24 , V_6 -> V_25 ,
V_6 -> V_25 ) )
F_4 ( V_2 , V_17 , V_3 ) ;
return 0 ;
}
int F_13 ( struct V_29 * V_29 , T_1 V_3 )
{
struct V_1 * V_2 = V_29 -> V_30 . V_2 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 )
return - V_31 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_8 ( V_2 , V_8 , V_6 , V_6 -> V_24 , V_28 , V_6 -> V_23 ) ;
return 0 ;
}
static inline bool F_14 ( struct V_16 * V_17 ,
union V_32 V_33 ,
union V_32 V_34 ,
bool V_35 )
{
bool V_36 ;
V_34 . V_37 = ( V_34 . V_38 && ( V_34 . V_39 < V_34 . V_40 ) ) ;
V_36 = F_15 ( & V_17 -> V_6 . V_41 , V_33 . V_41 , V_34 . V_41 ) == V_33 . V_41 ;
if ( ! V_36 )
goto V_42;
F_2 ( L_5 ,
V_17 -> V_43 ,
V_33 . V_40 , V_33 . V_44 , V_33 . V_39 , V_33 . V_38 ,
V_33 . V_45 , V_33 . V_37 ) ;
F_2 ( L_6 ,
V_34 . V_40 , V_34 . V_44 , V_34 . V_39 , V_34 . V_38 ,
V_34 . V_45 , V_34 . V_37 ) ;
if ( V_34 . V_37 ) {
F_16 ( V_17 -> V_46 ,
V_47 ) ;
if ( ! V_35 )
F_17 ( V_17 -> V_46 ) ;
}
V_42:
return V_36 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
T_1 V_48 ;
F_19 () ;
F_20 (icsid, icp->resend_map, xics->max_icsid + 1 ) {
struct V_7 * V_8 = V_2 -> V_8 [ V_48 ] ;
if ( ! F_21 ( V_48 , V_17 -> V_49 ) )
continue;
if ( ! V_8 )
continue;
F_5 ( V_2 , V_8 , V_17 ) ;
}
}
static bool F_22 ( struct V_16 * V_17 , T_1 V_3 , T_3 V_23 ,
T_1 * V_50 )
{
union V_32 V_51 , V_52 ;
bool V_36 ;
F_2 ( L_7 , V_3 , V_23 ,
V_17 -> V_43 ) ;
do {
V_51 = V_52 = F_23 ( V_17 -> V_6 ) ;
* V_50 = 0 ;
V_36 = V_52 . V_40 > V_23 &&
V_52 . V_44 > V_23 &&
V_52 . V_39 > V_23 ;
if ( V_36 ) {
* V_50 = V_52 . V_38 ;
V_52 . V_38 = V_3 ;
V_52 . V_39 = V_23 ;
} else {
V_52 . V_45 = true ;
}
} while ( ! F_14 ( V_17 , V_51 , V_52 , false ) );
return V_36 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_1 V_53 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_50 ;
T_2 V_9 ;
V_54:
V_8 = F_3 ( V_2 , V_53 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_8 , V_53 ) ;
return;
}
V_6 = & V_8 -> V_11 [ V_9 ] ;
F_6 ( & V_8 -> V_19 ) ;
if ( ! V_17 || V_6 -> V_24 != V_17 -> V_43 ) {
V_17 = F_10 ( V_2 -> V_29 , V_6 -> V_24 ) ;
if ( ! V_17 ) {
F_24 ( L_9 ,
V_53 , V_6 -> V_24 ) ;
goto V_55;
}
}
V_6 -> V_21 = 0 ;
if ( V_6 -> V_23 == V_28 ) {
F_2 ( L_10 , V_53 ) ;
V_6 -> V_27 = 1 ;
goto V_55;
}
if ( F_22 ( V_17 , V_53 , V_6 -> V_23 , & V_50 ) ) {
if ( V_50 && V_50 != V_56 ) {
F_7 ( & V_8 -> V_19 ) ;
V_53 = V_50 ;
goto V_54;
}
} else {
F_25 ( V_8 -> V_48 , V_17 -> V_49 ) ;
V_6 -> V_21 = 1 ;
F_26 () ;
if ( ! V_17 -> V_6 . V_45 ) {
F_7 ( & V_8 -> V_19 ) ;
goto V_54;
}
}
V_55:
F_7 ( & V_8 -> V_19 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_3 V_57 )
{
union V_32 V_51 , V_52 ;
bool V_21 ;
do {
V_51 = V_52 = F_23 ( V_17 -> V_6 ) ;
V_52 . V_40 = V_57 ;
if ( V_52 . V_44 < V_57 &&
V_52 . V_44 <= V_52 . V_39 ) {
F_28 ( V_52 . V_38 != V_56 &&
V_52 . V_38 != 0 ) ;
V_52 . V_39 = V_52 . V_44 ;
V_52 . V_38 = V_56 ;
}
V_21 = V_52 . V_45 ;
V_52 . V_45 = 0 ;
} while ( ! F_14 ( V_17 , V_51 , V_52 , true ) );
if ( V_21 )
F_18 ( V_2 , V_17 ) ;
}
static T_4 unsigned long F_29 ( struct V_58 * V_46 )
{
union V_32 V_51 , V_52 ;
struct V_16 * V_17 = V_46 -> V_30 . V_17 ;
T_1 V_59 ;
F_30 ( V_17 -> V_46 ,
V_47 ) ;
do {
V_51 = V_52 = F_23 ( V_17 -> V_6 ) ;
V_59 = V_51 . V_38 | ( ( ( T_1 ) V_51 . V_40 ) << 24 ) ;
if ( ! V_51 . V_38 )
break;
V_52 . V_40 = V_52 . V_39 ;
V_52 . V_39 = 0xff ;
V_52 . V_38 = 0 ;
} while ( ! F_14 ( V_17 , V_51 , V_52 , true ) );
F_2 ( L_11 , V_46 -> V_60 , V_59 ) ;
return V_59 ;
}
static T_4 int F_31 ( struct V_58 * V_46 , unsigned long V_24 ,
unsigned long V_44 )
{
union V_32 V_51 , V_52 ;
struct V_1 * V_2 = V_46 -> V_29 -> V_30 . V_2 ;
struct V_16 * V_17 ;
T_1 V_50 ;
bool V_21 ;
bool V_61 ;
F_2 ( L_12 ,
V_46 -> V_60 , V_24 , V_44 ) ;
V_17 = V_46 -> V_30 . V_17 ;
V_61 = V_17 -> V_43 == V_24 ;
if ( ! V_61 ) {
V_17 = F_10 ( V_46 -> V_29 , V_24 ) ;
if ( ! V_17 )
return V_62 ;
}
do {
V_51 = V_52 = F_23 ( V_17 -> V_6 ) ;
V_52 . V_44 = V_44 ;
V_50 = 0 ;
V_21 = false ;
if ( V_44 < V_52 . V_40 ) {
if ( V_44 <= V_52 . V_39 )
V_50 = V_52 . V_38 ;
V_52 . V_39 = V_44 ;
V_52 . V_38 = V_56 ;
}
if ( V_44 > V_51 . V_44 && V_44 > V_52 . V_40 ) {
V_21 = V_52 . V_45 ;
V_52 . V_45 = 0 ;
}
} while ( ! F_14 ( V_17 , V_51 , V_52 , V_61 ) );
if ( V_50 && V_50 != V_56 )
F_4 ( V_2 , V_17 , V_50 ) ;
if ( V_21 )
F_18 ( V_2 , V_17 ) ;
return V_63 ;
}
static int F_32 ( struct V_58 * V_46 , unsigned long V_24 )
{
union V_32 V_6 ;
struct V_16 * V_17 ;
V_17 = V_46 -> V_30 . V_17 ;
if ( V_17 -> V_43 != V_24 ) {
V_17 = F_10 ( V_46 -> V_29 , V_24 ) ;
if ( ! V_17 )
return V_62 ;
}
V_6 = F_23 ( V_17 -> V_6 ) ;
F_33 ( V_46 , 4 , ( ( T_1 ) V_6 . V_40 << 24 ) | V_6 . V_38 ) ;
F_33 ( V_46 , 5 , V_6 . V_44 ) ;
return V_63 ;
}
static T_4 void F_34 ( struct V_58 * V_46 , unsigned long V_40 )
{
union V_32 V_51 , V_52 ;
struct V_1 * V_2 = V_46 -> V_29 -> V_30 . V_2 ;
struct V_16 * V_17 = V_46 -> V_30 . V_17 ;
T_1 V_50 ;
F_2 ( L_13 , V_46 -> V_60 , V_40 ) ;
if ( V_40 > V_17 -> V_6 . V_40 )
F_27 ( V_2 , V_17 , V_40 ) ;
else if ( V_40 == V_17 -> V_6 . V_40 )
return;
F_30 ( V_17 -> V_46 ,
V_47 ) ;
do {
V_51 = V_52 = F_23 ( V_17 -> V_6 ) ;
V_50 = 0 ;
V_52 . V_40 = V_40 ;
if ( V_40 <= V_52 . V_39 ) {
V_50 = V_52 . V_38 ;
V_52 . V_38 = 0 ;
V_52 . V_39 = 0xff ;
}
} while ( ! F_14 ( V_17 , V_51 , V_52 , true ) );
if ( V_50 && V_50 != V_56 )
F_4 ( V_2 , V_17 , V_50 ) ;
}
static T_4 int F_35 ( struct V_58 * V_46 , unsigned long V_59 )
{
struct V_1 * V_2 = V_46 -> V_29 -> V_30 . V_2 ;
struct V_16 * V_17 = V_46 -> V_30 . V_17 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
T_1 V_3 = V_59 & 0x00ffffff ;
T_2 V_9 ;
F_2 ( L_14 , V_46 -> V_60 , V_59 ) ;
F_27 ( V_2 , V_17 , V_59 >> 24 ) ;
if ( V_3 == V_56 )
return V_63 ;
V_8 = F_3 ( V_2 , V_3 , & V_9 ) ;
if ( ! V_8 ) {
F_2 ( L_15 , V_3 ) ;
return V_62 ;
}
V_6 = & V_8 -> V_11 [ V_9 ] ;
if ( V_6 -> V_14 )
F_4 ( V_2 , V_17 , V_3 ) ;
F_36 ( V_46 -> V_29 , 0 , V_3 ) ;
return V_63 ;
}
static T_4 int F_37 ( struct V_58 * V_46 , T_1 V_64 )
{
struct V_1 * V_2 = V_46 -> V_29 -> V_30 . V_2 ;
struct V_16 * V_17 = V_46 -> V_30 . V_17 ;
F_2 ( L_16 ,
V_64 , V_17 -> V_65 , V_17 -> V_66 . V_41 , V_17 -> V_67 ) ;
if ( V_17 -> V_65 & V_68 )
F_17 ( V_17 -> V_69 ) ;
if ( V_17 -> V_65 & V_70 )
F_18 ( V_2 , V_17 ) ;
if ( V_17 -> V_65 & V_71 )
F_4 ( V_2 , V_17 , V_17 -> V_72 ) ;
if ( V_17 -> V_65 & V_73 )
F_36 ( V_46 -> V_29 , 0 , V_17 -> V_74 ) ;
V_17 -> V_65 = 0 ;
return V_63 ;
}
int F_38 ( struct V_58 * V_46 , T_1 V_75 )
{
struct V_1 * V_2 = V_46 -> V_29 -> V_30 . V_2 ;
unsigned long V_76 ;
int V_77 = V_63 ;
if ( ! V_2 || ! V_46 -> V_30 . V_17 )
return V_78 ;
switch ( V_75 ) {
case V_79 :
V_76 = F_29 ( V_46 ) ;
F_33 ( V_46 , 4 , V_76 ) ;
F_33 ( V_46 , 5 , F_39 () ) ;
return V_77 ;
case V_80 :
V_77 = F_32 ( V_46 , F_40 ( V_46 , 4 ) ) ;
return V_77 ;
}
if ( V_2 -> V_81 && F_41 ( V_46 -> V_29 ) )
return F_37 ( V_46 , V_75 ) ;
switch ( V_75 ) {
case V_82 :
V_76 = F_29 ( V_46 ) ;
F_33 ( V_46 , 4 , V_76 ) ;
break;
case V_83 :
F_34 ( V_46 , F_40 ( V_46 , 4 ) ) ;
break;
case V_84 :
V_77 = F_35 ( V_46 , F_40 ( V_46 , 4 ) ) ;
break;
case V_85 :
V_77 = F_31 ( V_46 , F_40 ( V_46 , 4 ) ,
F_40 ( V_46 , 5 ) ) ;
break;
}
return V_77 ;
}
static int F_42 ( struct V_86 * V_87 , void * V_88 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
struct V_29 * V_29 = V_2 -> V_29 ;
struct V_58 * V_46 ;
int V_48 , V_18 ;
if ( ! V_29 )
return 0 ;
F_43 ( V_87 , L_17 ) ;
F_44 (i, vcpu, kvm) {
struct V_16 * V_17 = V_46 -> V_30 . V_17 ;
union V_32 V_6 ;
if ( ! V_17 )
continue;
V_6 . V_41 = F_23 ( V_17 -> V_6 . V_41 ) ;
F_43 ( V_87 , L_18 ,
V_17 -> V_43 , V_6 . V_38 ,
V_6 . V_39 , V_6 . V_40 , V_6 . V_44 ,
V_6 . V_37 , V_6 . V_45 ) ;
}
for ( V_48 = 0 ; V_48 <= V_89 ; V_48 ++ ) {
struct V_7 * V_8 = V_2 -> V_8 [ V_48 ] ;
if ( ! V_8 )
continue;
F_43 ( V_87 , L_19 ,
V_48 ) ;
F_6 ( & V_8 -> V_19 ) ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_5 * V_3 = & V_8 -> V_11 [ V_18 ] ;
F_43 ( V_87 , L_20 ,
V_3 -> V_22 , V_3 -> V_24 , V_3 -> V_23 ,
V_3 -> V_25 , V_3 -> V_14 ,
V_3 -> V_21 , V_3 -> V_27 ) ;
}
F_7 ( & V_8 -> V_19 ) ;
}
return 0 ;
}
static int F_45 ( struct V_90 * V_90 , struct V_91 * V_91 )
{
return F_46 ( V_91 , F_42 , V_90 -> V_92 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
char * V_93 ;
V_93 = F_48 ( V_94 , L_21 , V_2 ) ;
if ( ! V_93 ) {
F_49 ( L_22 , V_95 ) ;
return;
}
V_2 -> V_96 = F_50 ( V_93 , V_97 , V_98 ,
V_2 , & V_99 ) ;
F_51 ( L_23 , V_95 , V_93 ) ;
F_52 ( V_93 ) ;
}
static struct V_7 * F_53 ( struct V_29 * V_29 ,
struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 ;
int V_18 , V_48 ;
V_48 = V_3 >> V_100 ;
F_6 ( & V_29 -> V_19 ) ;
if ( V_2 -> V_8 [ V_48 ] )
goto V_55;
V_8 = F_54 ( sizeof( struct V_7 ) , V_94 ) ;
if ( ! V_8 )
goto V_55;
F_55 ( & V_8 -> V_19 ) ;
V_8 -> V_48 = V_48 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
V_8 -> V_11 [ V_18 ] . V_22 = ( V_48 << V_100 ) | V_18 ;
V_8 -> V_11 [ V_18 ] . V_23 = V_28 ;
V_8 -> V_11 [ V_18 ] . V_25 = V_28 ;
}
F_56 () ;
V_2 -> V_8 [ V_48 ] = V_8 ;
if ( V_48 > V_2 -> V_101 )
V_2 -> V_101 = V_48 ;
V_55:
F_7 ( & V_29 -> V_19 ) ;
return V_2 -> V_8 [ V_48 ] ;
}
int F_57 ( struct V_58 * V_46 , unsigned long V_43 )
{
struct V_16 * V_17 ;
if ( ! V_46 -> V_29 -> V_30 . V_2 )
return - V_31 ;
if ( F_10 ( V_46 -> V_29 , V_43 ) )
return - V_102 ;
V_17 = F_54 ( sizeof( struct V_16 ) , V_94 ) ;
if ( ! V_17 )
return - V_103 ;
V_17 -> V_46 = V_46 ;
V_17 -> V_43 = V_43 ;
V_17 -> V_6 . V_44 = V_28 ;
V_17 -> V_6 . V_39 = V_28 ;
V_46 -> V_30 . V_17 = V_17 ;
F_2 ( L_24 , V_46 -> V_60 ) ;
return 0 ;
}
T_5 F_58 ( struct V_58 * V_46 )
{
struct V_16 * V_17 = V_46 -> V_30 . V_17 ;
union V_32 V_6 ;
if ( ! V_17 )
return 0 ;
V_6 = V_17 -> V_6 ;
return ( ( T_5 ) V_6 . V_40 << V_104 ) |
( ( T_5 ) V_6 . V_38 << V_105 ) |
( ( T_5 ) V_6 . V_44 << V_106 ) |
( ( T_5 ) V_6 . V_39 << V_107 ) ;
}
int F_59 ( struct V_58 * V_46 , T_5 V_108 )
{
struct V_16 * V_17 = V_46 -> V_30 . V_17 ;
struct V_1 * V_2 = V_46 -> V_29 -> V_30 . V_2 ;
union V_32 V_51 , V_52 ;
struct V_7 * V_8 ;
T_3 V_40 , V_44 , V_39 ;
T_1 V_38 ;
T_2 V_9 ;
bool V_21 ;
if ( ! V_17 || ! V_2 )
return - V_109 ;
V_40 = V_108 >> V_104 ;
V_38 = ( V_108 >> V_105 ) &
V_110 ;
V_44 = V_108 >> V_106 ;
V_39 = V_108 >> V_107 ;
if ( V_38 == 0 ) {
if ( V_39 != 0xff )
return - V_10 ;
} else if ( V_38 == V_56 ) {
if ( V_39 != V_44 || V_39 >= V_40 )
return - V_10 ;
} else {
if ( V_39 >= V_44 || V_39 >= V_40 )
return - V_10 ;
V_8 = F_3 ( V_2 , V_38 , & V_9 ) ;
if ( ! V_8 )
return - V_10 ;
}
V_52 . V_41 = 0 ;
V_52 . V_40 = V_40 ;
V_52 . V_38 = V_38 ;
V_52 . V_44 = V_44 ;
V_52 . V_39 = V_39 ;
F_30 ( V_17 -> V_46 ,
V_47 ) ;
do {
V_51 = F_23 ( V_17 -> V_6 ) ;
if ( V_52 . V_44 <= V_51 . V_44 ) {
V_21 = false ;
V_52 . V_45 = V_51 . V_45 ;
} else {
V_21 = V_51 . V_45 ;
V_52 . V_45 = 0 ;
}
} while ( ! F_14 ( V_17 , V_51 , V_52 , false ) );
if ( V_21 )
F_18 ( V_2 , V_17 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , long V_3 , T_5 V_111 )
{
int V_112 ;
struct V_7 * V_8 ;
struct V_5 * V_113 ;
T_5 T_6 * V_114 = ( T_5 T_6 * ) V_111 ;
T_2 V_115 ;
T_5 V_116 , V_117 ;
V_8 = F_3 ( V_2 , V_3 , & V_115 ) ;
if ( ! V_8 )
return - V_109 ;
V_113 = & V_8 -> V_11 [ V_115 ] ;
F_6 ( & V_8 -> V_19 ) ;
V_112 = - V_109 ;
if ( V_113 -> V_12 ) {
V_116 = V_113 -> V_24 ;
V_117 = V_113 -> V_23 ;
if ( V_117 == V_28 ) {
V_116 |= V_118 ;
V_117 = V_113 -> V_25 ;
}
V_116 |= V_117 << V_119 ;
if ( V_113 -> V_14 )
V_116 |= V_120 | V_121 ;
else if ( V_113 -> V_27 || V_113 -> V_21 )
V_116 |= V_121 ;
V_112 = 0 ;
}
F_7 ( & V_8 -> V_19 ) ;
if ( ! V_112 && F_61 ( V_116 , V_114 ) )
V_112 = - V_122 ;
return V_112 ;
}
static int F_62 ( struct V_1 * V_2 , long V_3 , T_5 V_111 )
{
struct V_7 * V_8 ;
struct V_5 * V_113 ;
T_5 T_6 * V_114 = ( T_5 T_6 * ) V_111 ;
T_2 V_115 ;
T_5 V_116 ;
T_3 V_117 ;
T_1 V_24 ;
if ( V_3 < V_123 || V_3 >= V_124 )
return - V_109 ;
V_8 = F_3 ( V_2 , V_3 , & V_115 ) ;
if ( ! V_8 ) {
V_8 = F_53 ( V_2 -> V_29 , V_2 , V_3 ) ;
if ( ! V_8 )
return - V_103 ;
}
V_113 = & V_8 -> V_11 [ V_115 ] ;
if ( F_63 ( V_116 , V_114 ) )
return - V_122 ;
V_24 = V_116 & V_125 ;
V_117 = V_116 >> V_119 ;
if ( V_117 != V_28 &&
F_10 ( V_2 -> V_29 , V_24 ) == NULL )
return - V_10 ;
F_6 ( & V_8 -> V_19 ) ;
V_113 -> V_24 = V_24 ;
V_113 -> V_25 = V_117 ;
if ( V_116 & V_118 )
V_117 = V_28 ;
V_113 -> V_23 = V_117 ;
V_113 -> V_21 = 0 ;
V_113 -> V_27 = 0 ;
V_113 -> V_14 = 0 ;
if ( ( V_116 & V_121 ) && ( V_116 & V_120 ) )
V_113 -> V_14 = 1 ;
V_113 -> V_12 = 1 ;
F_7 ( & V_8 -> V_19 ) ;
if ( V_116 & V_121 )
F_4 ( V_2 , NULL , V_113 -> V_22 ) ;
return 0 ;
}
int F_64 ( struct V_29 * V_29 , int V_126 , T_1 V_3 , int V_4 ,
bool V_127 )
{
struct V_1 * V_2 = V_29 -> V_30 . V_2 ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_65 ( struct V_128 * V_129 , struct V_29 * V_29 ,
int V_126 , int V_4 , bool V_127 )
{
if ( ! V_4 )
return - 1 ;
return F_64 ( V_29 , V_126 , V_129 -> V_130 ,
V_4 , V_127 ) ;
}
static int F_66 ( struct V_131 * V_132 , struct V_133 * V_134 )
{
struct V_1 * V_2 = V_132 -> V_88 ;
switch ( V_134 -> V_135 ) {
case V_136 :
return F_62 ( V_2 , V_134 -> V_134 , V_134 -> V_111 ) ;
}
return - V_137 ;
}
static int F_67 ( struct V_131 * V_132 , struct V_133 * V_134 )
{
struct V_1 * V_2 = V_132 -> V_88 ;
switch ( V_134 -> V_135 ) {
case V_136 :
return F_60 ( V_2 , V_134 -> V_134 , V_134 -> V_111 ) ;
}
return - V_137 ;
}
static int F_68 ( struct V_131 * V_132 , struct V_133 * V_134 )
{
switch ( V_134 -> V_135 ) {
case V_136 :
if ( V_134 -> V_134 >= V_123 &&
V_134 -> V_134 < V_124 )
return 0 ;
break;
}
return - V_137 ;
}
static void F_69 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_88 ;
int V_18 ;
struct V_29 * V_29 = V_2 -> V_29 ;
F_70 ( V_2 -> V_96 ) ;
if ( V_29 )
V_29 -> V_30 . V_2 = NULL ;
for ( V_18 = 0 ; V_18 <= V_2 -> V_101 ; V_18 ++ )
F_52 ( V_2 -> V_8 [ V_18 ] ) ;
F_52 ( V_2 ) ;
F_52 ( V_132 ) ;
}
static int F_71 ( struct V_131 * V_132 , T_1 type )
{
struct V_1 * V_2 ;
struct V_29 * V_29 = V_132 -> V_29 ;
int V_112 = 0 ;
V_2 = F_54 ( sizeof( * V_2 ) , V_94 ) ;
if ( ! V_2 )
return - V_103 ;
V_132 -> V_88 = V_2 ;
V_2 -> V_132 = V_132 ;
V_2 -> V_29 = V_29 ;
F_6 ( & V_29 -> V_19 ) ;
if ( V_29 -> V_30 . V_2 )
V_112 = - V_102 ;
else
V_29 -> V_30 . V_2 = V_2 ;
F_7 ( & V_29 -> V_19 ) ;
if ( V_112 ) {
F_52 ( V_2 ) ;
return V_112 ;
}
F_47 ( V_2 ) ;
#ifdef F_72
if ( F_73 ( V_138 ) ) {
V_2 -> V_81 = V_139 ;
V_2 -> V_140 = V_141 ;
}
#endif
return 0 ;
}
int F_74 ( struct V_131 * V_132 , struct V_58 * V_46 ,
T_1 V_142 )
{
struct V_1 * V_2 = V_132 -> V_88 ;
int V_143 = - V_144 ;
if ( V_132 -> V_145 != & V_146 )
return - V_147 ;
if ( V_2 -> V_29 != V_46 -> V_29 )
return - V_147 ;
if ( V_46 -> V_30 . V_148 )
return - V_144 ;
V_143 = F_57 ( V_46 , V_142 ) ;
if ( ! V_143 )
V_46 -> V_30 . V_148 = V_149 ;
return V_143 ;
}
void F_75 ( struct V_58 * V_46 )
{
if ( ! V_46 -> V_30 . V_17 )
return;
F_52 ( V_46 -> V_30 . V_17 ) ;
V_46 -> V_30 . V_17 = NULL ;
V_46 -> V_30 . V_148 = V_150 ;
}
static int F_76 ( struct V_128 * V_151 ,
struct V_29 * V_29 , int V_126 , int V_4 ,
bool V_127 )
{
return F_64 ( V_29 , V_126 , V_151 -> V_130 , V_4 , V_127 ) ;
}
int F_77 ( struct V_29 * V_29 ,
struct V_128 * V_152 , int V_130 )
{
V_152 -> V_130 = V_130 ;
V_152 -> type = V_153 ;
V_152 -> V_154 = F_76 ;
V_152 -> V_155 . V_155 = 0 ;
V_152 -> V_155 . V_156 = V_130 ;
return 1 ;
}
int F_78 ( struct V_29 * V_29 , unsigned V_155 , unsigned V_156 )
{
return V_156 ;
}
