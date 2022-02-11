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
if ( V_44 <= V_52 . V_39 ) {
V_50 = V_52 . V_38 ;
V_52 . V_39 = V_44 ;
V_52 . V_38 = V_56 ;
}
}
if ( V_44 > V_51 . V_44 ) {
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
F_18 ( V_2 , V_17 -> V_71 ) ;
if ( V_17 -> V_65 & V_72 )
F_4 ( V_2 , V_17 , V_17 -> V_73 ) ;
if ( V_17 -> V_65 & V_74 )
F_36 ( V_46 -> V_29 , 0 , V_17 -> V_75 ) ;
V_17 -> V_65 = 0 ;
return V_63 ;
}
int F_38 ( struct V_58 * V_46 , T_1 V_76 )
{
struct V_1 * V_2 = V_46 -> V_29 -> V_30 . V_2 ;
unsigned long V_77 ;
int V_78 = V_63 ;
if ( ! V_2 || ! V_46 -> V_30 . V_17 )
return V_79 ;
switch ( V_76 ) {
case V_80 :
V_77 = F_29 ( V_46 ) ;
F_33 ( V_46 , 4 , V_77 ) ;
F_33 ( V_46 , 5 , F_39 () ) ;
return V_78 ;
case V_81 :
V_78 = F_32 ( V_46 , F_40 ( V_46 , 4 ) ) ;
return V_78 ;
}
if ( V_2 -> V_82 && F_41 ( V_46 -> V_29 ) )
return F_37 ( V_46 , V_76 ) ;
switch ( V_76 ) {
case V_83 :
V_77 = F_29 ( V_46 ) ;
F_33 ( V_46 , 4 , V_77 ) ;
break;
case V_84 :
F_34 ( V_46 , F_40 ( V_46 , 4 ) ) ;
break;
case V_85 :
V_78 = F_35 ( V_46 , F_40 ( V_46 , 4 ) ) ;
break;
case V_86 :
V_78 = F_31 ( V_46 , F_40 ( V_46 , 4 ) ,
F_40 ( V_46 , 5 ) ) ;
break;
}
return V_78 ;
}
static int F_42 ( struct V_87 * V_88 , void * V_89 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
struct V_29 * V_29 = V_2 -> V_29 ;
struct V_58 * V_46 ;
int V_48 , V_18 ;
if ( ! V_29 )
return 0 ;
F_43 ( V_88 , L_17 ) ;
F_44 (i, vcpu, kvm) {
struct V_16 * V_17 = V_46 -> V_30 . V_17 ;
union V_32 V_6 ;
if ( ! V_17 )
continue;
V_6 . V_41 = F_23 ( V_17 -> V_6 . V_41 ) ;
F_43 ( V_88 , L_18 ,
V_17 -> V_43 , V_6 . V_38 ,
V_6 . V_39 , V_6 . V_40 , V_6 . V_44 ,
V_6 . V_37 , V_6 . V_45 ) ;
}
for ( V_48 = 0 ; V_48 <= V_90 ; V_48 ++ ) {
struct V_7 * V_8 = V_2 -> V_8 [ V_48 ] ;
if ( ! V_8 )
continue;
F_43 ( V_88 , L_19 ,
V_48 ) ;
F_6 ( & V_8 -> V_19 ) ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
struct V_5 * V_3 = & V_8 -> V_11 [ V_18 ] ;
F_43 ( V_88 , L_20 ,
V_3 -> V_22 , V_3 -> V_24 , V_3 -> V_23 ,
V_3 -> V_25 , V_3 -> V_14 ,
V_3 -> V_21 , V_3 -> V_27 ) ;
}
F_7 ( & V_8 -> V_19 ) ;
}
return 0 ;
}
static int F_45 ( struct V_91 * V_91 , struct V_92 * V_92 )
{
return F_46 ( V_92 , F_42 , V_91 -> V_93 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
char * V_94 ;
V_94 = F_48 ( V_95 , L_21 , V_2 ) ;
if ( ! V_94 ) {
F_49 ( L_22 , V_96 ) ;
return;
}
V_2 -> V_97 = F_50 ( V_94 , V_98 , V_99 ,
V_2 , & V_100 ) ;
F_51 ( L_23 , V_96 , V_94 ) ;
F_52 ( V_94 ) ;
}
static struct V_7 * F_53 ( struct V_29 * V_29 ,
struct V_1 * V_2 , int V_3 )
{
struct V_7 * V_8 ;
int V_18 , V_48 ;
V_48 = V_3 >> V_101 ;
F_6 ( & V_29 -> V_19 ) ;
if ( V_2 -> V_8 [ V_48 ] )
goto V_55;
V_8 = F_54 ( sizeof( struct V_7 ) , V_95 ) ;
if ( ! V_8 )
goto V_55;
F_55 ( & V_8 -> V_19 ) ;
V_8 -> V_48 = V_48 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
V_8 -> V_11 [ V_18 ] . V_22 = ( V_48 << V_101 ) | V_18 ;
V_8 -> V_11 [ V_18 ] . V_23 = V_28 ;
V_8 -> V_11 [ V_18 ] . V_25 = V_28 ;
}
F_56 () ;
V_2 -> V_8 [ V_48 ] = V_8 ;
if ( V_48 > V_2 -> V_102 )
V_2 -> V_102 = V_48 ;
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
return - V_103 ;
V_17 = F_54 ( sizeof( struct V_16 ) , V_95 ) ;
if ( ! V_17 )
return - V_104 ;
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
return ( ( T_5 ) V_6 . V_40 << V_105 ) |
( ( T_5 ) V_6 . V_38 << V_106 ) |
( ( T_5 ) V_6 . V_44 << V_107 ) |
( ( T_5 ) V_6 . V_39 << V_108 ) ;
}
int F_59 ( struct V_58 * V_46 , T_5 V_109 )
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
return - V_110 ;
V_40 = V_109 >> V_105 ;
V_38 = ( V_109 >> V_106 ) &
V_111 ;
V_44 = V_109 >> V_107 ;
V_39 = V_109 >> V_108 ;
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
static int F_60 ( struct V_1 * V_2 , long V_3 , T_5 V_112 )
{
int V_113 ;
struct V_7 * V_8 ;
struct V_5 * V_114 ;
T_5 T_6 * V_115 = ( T_5 T_6 * ) V_112 ;
T_2 V_116 ;
T_5 V_117 , V_118 ;
V_8 = F_3 ( V_2 , V_3 , & V_116 ) ;
if ( ! V_8 )
return - V_110 ;
V_114 = & V_8 -> V_11 [ V_116 ] ;
F_6 ( & V_8 -> V_19 ) ;
V_113 = - V_110 ;
if ( V_114 -> V_12 ) {
V_117 = V_114 -> V_24 ;
V_118 = V_114 -> V_23 ;
if ( V_118 == V_28 ) {
V_117 |= V_119 ;
V_118 = V_114 -> V_25 ;
}
V_117 |= V_118 << V_120 ;
if ( V_114 -> V_14 )
V_117 |= V_121 | V_122 ;
else if ( V_114 -> V_27 || V_114 -> V_21 )
V_117 |= V_122 ;
V_113 = 0 ;
}
F_7 ( & V_8 -> V_19 ) ;
if ( ! V_113 && F_61 ( V_117 , V_115 ) )
V_113 = - V_123 ;
return V_113 ;
}
static int F_62 ( struct V_1 * V_2 , long V_3 , T_5 V_112 )
{
struct V_7 * V_8 ;
struct V_5 * V_114 ;
T_5 T_6 * V_115 = ( T_5 T_6 * ) V_112 ;
T_2 V_116 ;
T_5 V_117 ;
T_3 V_118 ;
T_1 V_24 ;
if ( V_3 < V_124 || V_3 >= V_125 )
return - V_110 ;
V_8 = F_3 ( V_2 , V_3 , & V_116 ) ;
if ( ! V_8 ) {
V_8 = F_53 ( V_2 -> V_29 , V_2 , V_3 ) ;
if ( ! V_8 )
return - V_104 ;
}
V_114 = & V_8 -> V_11 [ V_116 ] ;
if ( F_63 ( V_117 , V_115 ) )
return - V_123 ;
V_24 = V_117 & V_126 ;
V_118 = V_117 >> V_120 ;
if ( V_118 != V_28 &&
F_10 ( V_2 -> V_29 , V_24 ) == NULL )
return - V_10 ;
F_6 ( & V_8 -> V_19 ) ;
V_114 -> V_24 = V_24 ;
V_114 -> V_25 = V_118 ;
if ( V_117 & V_119 )
V_118 = V_28 ;
V_114 -> V_23 = V_118 ;
V_114 -> V_21 = 0 ;
V_114 -> V_27 = 0 ;
V_114 -> V_14 = 0 ;
if ( ( V_117 & V_122 ) && ( V_117 & V_121 ) )
V_114 -> V_14 = 1 ;
V_114 -> V_12 = 1 ;
F_7 ( & V_8 -> V_19 ) ;
if ( V_117 & V_122 )
F_4 ( V_2 , NULL , V_114 -> V_22 ) ;
return 0 ;
}
int F_64 ( struct V_29 * V_29 , int V_127 , T_1 V_3 , int V_4 ,
bool V_128 )
{
struct V_1 * V_2 = V_29 -> V_30 . V_2 ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_65 ( struct V_129 * V_130 , struct V_29 * V_29 ,
int V_127 , int V_4 , bool V_128 )
{
if ( ! V_4 )
return - 1 ;
return F_64 ( V_29 , V_127 , V_130 -> V_131 ,
V_4 , V_128 ) ;
}
static int F_66 ( struct V_132 * V_133 , struct V_134 * V_135 )
{
struct V_1 * V_2 = V_133 -> V_89 ;
switch ( V_135 -> V_136 ) {
case V_137 :
return F_62 ( V_2 , V_135 -> V_135 , V_135 -> V_112 ) ;
}
return - V_138 ;
}
static int F_67 ( struct V_132 * V_133 , struct V_134 * V_135 )
{
struct V_1 * V_2 = V_133 -> V_89 ;
switch ( V_135 -> V_136 ) {
case V_137 :
return F_60 ( V_2 , V_135 -> V_135 , V_135 -> V_112 ) ;
}
return - V_138 ;
}
static int F_68 ( struct V_132 * V_133 , struct V_134 * V_135 )
{
switch ( V_135 -> V_136 ) {
case V_137 :
if ( V_135 -> V_135 >= V_124 &&
V_135 -> V_135 < V_125 )
return 0 ;
break;
}
return - V_138 ;
}
static void F_69 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = V_133 -> V_89 ;
int V_18 ;
struct V_29 * V_29 = V_2 -> V_29 ;
F_70 ( V_2 -> V_97 ) ;
if ( V_29 )
V_29 -> V_30 . V_2 = NULL ;
for ( V_18 = 0 ; V_18 <= V_2 -> V_102 ; V_18 ++ )
F_52 ( V_2 -> V_8 [ V_18 ] ) ;
F_52 ( V_2 ) ;
F_52 ( V_133 ) ;
}
static int F_71 ( struct V_132 * V_133 , T_1 type )
{
struct V_1 * V_2 ;
struct V_29 * V_29 = V_133 -> V_29 ;
int V_113 = 0 ;
V_2 = F_54 ( sizeof( * V_2 ) , V_95 ) ;
if ( ! V_2 )
return - V_104 ;
V_133 -> V_89 = V_2 ;
V_2 -> V_133 = V_133 ;
V_2 -> V_29 = V_29 ;
F_6 ( & V_29 -> V_19 ) ;
if ( V_29 -> V_30 . V_2 )
V_113 = - V_103 ;
else
V_29 -> V_30 . V_2 = V_2 ;
F_7 ( & V_29 -> V_19 ) ;
if ( V_113 ) {
F_52 ( V_2 ) ;
return V_113 ;
}
F_47 ( V_2 ) ;
#ifdef F_72
if ( F_73 ( V_139 ) ) {
V_2 -> V_82 = V_140 ;
V_2 -> V_141 = V_142 ;
}
#endif
return 0 ;
}
int F_74 ( struct V_132 * V_133 , struct V_58 * V_46 ,
T_1 V_143 )
{
struct V_1 * V_2 = V_133 -> V_89 ;
int V_144 = - V_145 ;
if ( V_133 -> V_146 != & V_147 )
return - V_148 ;
if ( V_2 -> V_29 != V_46 -> V_29 )
return - V_148 ;
if ( V_46 -> V_30 . V_149 )
return - V_145 ;
V_144 = F_57 ( V_46 , V_143 ) ;
if ( ! V_144 )
V_46 -> V_30 . V_149 = V_150 ;
return V_144 ;
}
void F_75 ( struct V_58 * V_46 )
{
if ( ! V_46 -> V_30 . V_17 )
return;
F_52 ( V_46 -> V_30 . V_17 ) ;
V_46 -> V_30 . V_17 = NULL ;
V_46 -> V_30 . V_149 = V_151 ;
}
static int F_76 ( struct V_129 * V_152 ,
struct V_29 * V_29 , int V_127 , int V_4 ,
bool V_128 )
{
return F_64 ( V_29 , V_127 , V_152 -> V_131 , V_4 , V_128 ) ;
}
int F_77 ( struct V_29 * V_29 ,
struct V_129 * V_153 , int V_131 )
{
V_153 -> V_131 = V_131 ;
V_153 -> type = V_154 ;
V_153 -> V_155 = F_76 ;
V_153 -> V_156 . V_156 = 0 ;
V_153 -> V_156 . V_157 = V_131 ;
return 1 ;
}
int F_78 ( struct V_29 * V_29 , unsigned V_156 , unsigned V_157 )
{
return V_157 ;
}
