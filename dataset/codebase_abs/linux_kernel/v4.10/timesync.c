static T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
if ( V_2 -> V_4 )
return V_3 - V_2 -> V_5 ;
else
return V_3 + V_2 -> V_5 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
T_1 V_6 = F_3 () ;
return F_1 ( V_2 , V_6 ) ;
}
static void F_4 ( struct V_1
* V_2 )
{
F_5 ( V_2 -> V_7 ,
& V_2 -> V_8 ,
V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
int V_10 )
{
switch ( V_10 ) {
case V_11 :
V_2 -> V_10 = V_10 ;
F_7 ( & V_2 -> V_12 ) ;
break;
case V_13 :
V_2 -> V_10 = V_10 ;
F_7 ( & V_2 -> V_12 ) ;
break;
case V_14 :
if ( V_2 -> V_10 != V_11 ) {
V_2 -> V_15 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_10 = V_10 ;
F_8 ( & V_2 -> V_8 ) ;
F_5 ( V_2 -> V_7 ,
& V_2 -> V_8 ,
V_16 ) ;
}
break;
case V_17 :
if ( V_2 -> V_10 == V_14 )
V_2 -> V_10 = V_10 ;
break;
case V_18 :
if ( V_2 -> V_10 == V_17 ) {
V_2 -> V_10 = V_10 ;
F_8 ( & V_2 -> V_8 ) ;
F_5 ( V_2 -> V_7 ,
& V_2 -> V_8 , 0 ) ;
}
break;
case V_19 :
if ( V_2 -> V_10 == V_20 ) {
V_2 -> V_10 = V_10 ;
F_5 ( V_2 -> V_7 ,
& V_2 -> V_8 ,
V_21 ) ;
}
break;
case V_20 :
if ( V_2 -> V_10 == V_18 ||
V_2 -> V_10 == V_19 ) {
V_2 -> V_10 = V_10 ;
F_7 ( & V_2 -> V_12 ) ;
}
break;
}
if ( F_9 ( V_2 -> V_10 != V_10 ) ) {
F_10 ( L_1 ,
V_2 -> V_10 , V_10 ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
int V_10 )
{
unsigned long V_22 ;
F_12 ( & V_2 -> V_23 , V_22 ) ;
F_6 ( V_2 , V_10 ) ;
F_13 ( & V_2 -> V_23 , V_22 ) ;
}
static T_1 F_14 ( T_1 V_24 , T_1 V_25 )
{
if ( V_24 > V_25 )
return V_24 - V_25 ;
else
return V_25 - V_24 ;
}
static void F_15 ( struct V_1 * V_26 ,
T_1 V_27 , T_1 V_28 )
{
if ( V_27 > V_28 ) {
V_26 -> V_5 = V_27 - V_28 ;
V_26 -> V_4 = false ;
} else {
V_26 -> V_5 = V_28 - V_27 ;
V_26 -> V_4 = true ;
}
}
static void F_16 ( struct V_1 * V_2 ,
struct V_29 V_30 , T_1 V_31 )
{
V_2 -> V_32 . V_30 = V_30 ;
V_2 -> V_32 . V_31 = V_31 ;
}
static void F_17 ( struct V_1 * V_2 ,
T_1 * V_31 )
{
int V_33 = 0 ;
T_1 V_34 , V_28 ;
T_1 V_35 = V_36 * V_37 ;
T_1 V_38 = 0 ;
for ( V_33 = 1 ; V_33 < V_39 ; V_33 ++ ) {
V_34 = V_2 -> V_40 [ V_33 ] . V_31 -
V_2 -> V_40 [ V_33 - 1 ] . V_31 ;
V_34 *= V_41 ;
V_34 = F_14 ( V_34 , V_35 ) ;
if ( ! V_38 || V_34 < V_38 ) {
V_38 = V_34 ;
F_15 ( V_2 , V_31 [ V_33 ] ,
V_2 -> V_40 [ V_33 ] . V_31 ) ;
V_28 = V_2 -> V_40 [ V_33 ] . V_31 ;
V_28 = F_1 ( V_2 ,
V_28 ) ;
F_16 ( V_2 ,
V_2 -> V_40 [ V_33 ] . V_30 ,
V_28 ) ;
F_18 ( L_2 ,
V_2 -> V_4 ? L_3 : L_4 ,
V_2 -> V_40 [ V_33 ] . V_31 ,
V_31 [ V_33 ] , V_34 ) ;
}
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
struct V_44 * V_26 = V_2 -> V_26 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
int V_49 ;
F_20 (timesync_interface,
&timesync_svc->interface_list, list) {
V_46 = V_43 -> V_46 ;
V_49 = F_21 ( V_46 ) ;
if ( V_49 ) {
F_22 ( & V_46 -> V_50 ,
L_5 , V_49 ) ;
}
}
V_48 = V_2 -> V_51 -> V_48 ;
V_49 = V_48 -> V_52 -> V_53 ( V_48 ) ;
if ( V_49 < 0 ) {
F_22 ( & V_48 -> V_50 , L_6 ,
V_49 ) ;
}
F_23 ( V_26 ) ;
F_24 ( V_26 ) ;
F_25 () ;
F_11 ( V_2 , V_13 ) ;
}
static void F_26 ( struct V_1
* V_2 , int V_49 )
{
if ( V_49 == - V_54 ) {
F_6 ( V_2 , V_2 -> V_10 ) ;
} else {
F_10 ( L_7 , V_49 ) ;
F_6 ( V_2 , V_13 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_44 * V_26 = V_2 -> V_26 ;
struct V_47 * V_48 ;
struct V_42 * V_43 ;
struct V_45 * V_46 ;
T_1 V_55 ;
unsigned long V_56 = V_57 ;
int V_49 ;
V_49 = F_28 ( V_2 ) ;
if ( V_49 < 0 ) {
F_26 ( V_2 , V_49 ) ;
return;
}
V_49 = F_29 ( V_26 , V_2 -> V_58 ) ;
if ( V_49 ) {
F_22 ( & V_26 -> V_50 ,
L_8 , V_49 ) ;
F_19 ( V_2 ) ;
return;
}
V_55 = F_2 ( V_2 ) + 100000UL ;
F_20 (timesync_interface, &timesync_svc->interface_list,
list) {
V_46 = V_43 -> V_46 ;
V_49 = F_30 ( V_46 ,
V_39 ,
V_55 ,
V_36 ,
V_56 ) ;
if ( V_49 ) {
F_22 ( & V_46 -> V_50 ,
L_9 , V_49 ) ;
}
}
V_48 = V_2 -> V_51 -> V_48 ;
V_49 = V_48 -> V_52 -> V_59 ( V_48 , V_39 ,
V_55 ,
V_36 ,
V_56 ) ;
if ( V_49 < 0 ) {
F_22 ( & V_48 -> V_50 , L_10 ,
V_49 ) ;
}
F_11 ( V_2 , V_17 ) ;
V_49 = F_31 ( V_26 , V_39 ,
V_55 ,
V_36 ,
V_56 ) ;
if ( V_49 ) {
F_22 ( & V_26 -> V_50 ,
L_11 , V_49 ) ;
F_19 ( V_2 ) ;
return;
}
F_4 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_44 * V_26 = V_2 -> V_26 ;
struct V_47 * V_48 ;
struct V_42 * V_43 ;
struct V_45 * V_46 ;
T_1 V_27 [ V_39 ] ;
int V_49 ;
V_49 = F_33 ( V_26 , V_27 ) ;
if ( V_49 ) {
F_22 ( & V_26 -> V_50 ,
L_12 , V_49 ) ;
F_19 ( V_2 ) ;
return;
}
F_17 ( V_2 , V_27 ) ;
V_48 = V_2 -> V_51 -> V_48 ;
V_49 = V_48 -> V_52 -> V_60 ( V_48 , V_27 ) ;
if ( V_49 < 0 )
F_22 ( & V_48 -> V_50 , L_13 , V_49 ) ;
F_20 (timesync_interface,
&timesync_svc->interface_list, list) {
V_46 = V_43 -> V_46 ;
V_49 = F_34 (
V_46 ,
V_27 ) ;
if ( V_49 ) {
F_22 ( & V_46 -> V_50 ,
L_14 , V_49 ) ;
}
}
F_23 ( V_26 ) ;
F_25 () ;
F_11 ( V_2 , V_20 ) ;
V_2 -> V_61 = true ;
F_11 ( V_2 , V_19 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_49 = - V_62 ;
switch ( V_2 -> V_10 ) {
case V_11 :
case V_13 :
V_49 = - V_63 ;
break;
case V_14 :
case V_17 :
case V_18 :
V_49 = - V_54 ;
break;
case V_19 :
case V_20 :
V_49 = 0 ;
break;
}
return V_49 ;
}
static int F_36 ( struct V_1 * V_2 ,
T_1 V_31 , struct V_29 * V_30 )
{
unsigned long V_22 ;
T_1 V_64 , V_3 , V_65 , V_66 ;
bool V_67 ;
int V_49 = 0 ;
memset ( V_30 , 0x00 , sizeof( * V_30 ) ) ;
F_37 ( & V_2 -> V_68 ) ;
F_12 ( & V_2 -> V_23 , V_22 ) ;
V_49 = F_35 ( V_2 ) ;
if ( V_49 )
goto V_69;
if ( V_31 < V_2 -> V_32 . V_31 ) {
V_67 = false ;
V_3 = V_2 -> V_32 . V_31 - V_31 ;
} else {
V_67 = true ;
V_3 = V_31 - V_2 -> V_32 . V_31 ;
}
if ( V_3 > V_70 ) {
V_49 = - V_62 ;
goto V_69;
}
V_64 = V_3 * V_71 ;
V_65 = V_64 ;
F_38 ( V_65 , V_72 ) ;
F_38 ( V_65 , 1000000UL ) ;
V_66 = F_38 ( V_64 , V_65 ) ;
F_38 ( V_66 , 1000000UL ) ;
if ( V_67 ) {
V_30 -> V_73 = V_2 -> V_32 . V_30 . V_73 + V_65 ;
V_30 -> V_74 = V_2 -> V_32 . V_30 . V_74 + V_66 ;
if ( V_30 -> V_74 >= V_72 ) {
V_30 -> V_73 ++ ;
V_30 -> V_74 -= V_72 ;
}
} else {
if ( V_66 > V_2 -> V_32 . V_30 . V_74 ) {
V_65 ++ ;
V_66 = V_66 + V_2 -> V_32 . V_30 . V_74 ;
V_66 = F_38 ( V_66 , V_72 ) ;
} else {
V_66 = V_2 -> V_32 . V_30 . V_74 - V_66 ;
}
if ( V_65 > V_2 -> V_32 . V_30 . V_73 ) {
V_49 = - V_62 ;
goto V_69;
}
V_30 -> V_73 = V_2 -> V_32 . V_30 . V_73 - V_65 ;
V_30 -> V_74 = V_66 ;
}
V_69:
F_13 ( & V_2 -> V_23 , V_22 ) ;
F_39 ( & V_2 -> V_68 ) ;
return V_49 ;
}
static T_2 F_40 ( struct V_1 * V_2 ,
char * V_75 , T_2 V_76 )
{
struct V_44 * V_26 = V_2 -> V_26 ;
struct V_47 * V_48 ;
struct V_42 * V_43 ;
struct V_45 * V_46 ;
unsigned int V_77 ;
T_2 V_78 ;
V_78 = snprintf ( V_75 , V_76 , L_15 ,
V_79 . V_80 ,
V_2 -> V_81 , F_41 ( & V_26 -> V_50 ) ,
V_2 -> V_82 ) ;
V_77 = V_76 - V_78 ;
if ( V_77 < V_76 ) {
V_48 = V_2 -> V_51 -> V_48 ;
V_78 += snprintf ( & V_75 [ V_78 ] , V_77 , L_16 , F_41 ( & V_48 -> V_50 ) ,
V_2 -> V_51 -> V_83 ) ;
V_77 = V_76 - V_78 ;
}
F_20 (timesync_interface,
&timesync_svc->interface_list, list) {
if ( V_77 < V_76 ) {
V_46 = V_43 -> V_46 ;
V_78 += snprintf ( & V_75 [ V_78 ] , V_77 , L_16 ,
F_41 ( & V_46 -> V_50 ) ,
V_43 -> V_83 ) ;
V_77 = V_76 - V_78 ;
}
}
if ( V_77 < V_76 )
V_78 += snprintf ( & V_75 [ V_78 ] , V_77 , L_17 ) ;
return V_78 ;
}
static T_2 F_42 ( struct V_1 * V_2 ,
char * V_75 , T_2 V_76 )
{
struct V_44 * V_26 = V_2 -> V_26 ;
struct V_47 * V_48 ;
struct V_42 * V_43 ;
struct V_45 * V_46 ;
struct V_29 V_30 ;
unsigned int V_77 ;
T_2 V_78 ;
F_36 ( V_2 , V_2 -> V_81 ,
& V_30 ) ;
V_78 = snprintf ( V_75 , V_76 , L_18 ,
V_79 . V_80 , V_30 . V_73 , V_30 . V_74 ) ;
V_77 = V_76 - V_78 ;
if ( V_77 >= V_76 )
goto V_69;
F_36 ( V_2 , V_2 -> V_82 ,
& V_30 ) ;
V_78 += snprintf ( & V_75 [ V_78 ] , V_77 , L_19 , F_41 ( & V_26 -> V_50 ) ,
V_30 . V_73 , V_30 . V_74 ) ;
V_77 = V_76 - V_78 ;
if ( V_77 >= V_76 )
goto V_69;
V_48 = V_2 -> V_51 -> V_48 ;
F_36 ( V_2 ,
V_2 -> V_51 -> V_83 ,
& V_30 ) ;
V_78 += snprintf ( & V_75 [ V_78 ] , V_77 , L_19 ,
F_41 ( & V_48 -> V_50 ) ,
V_30 . V_73 , V_30 . V_74 ) ;
V_77 = V_76 - V_78 ;
if ( V_77 >= V_76 )
goto V_69;
F_20 (timesync_interface,
&timesync_svc->interface_list, list) {
V_46 = V_43 -> V_46 ;
F_36 ( V_2 ,
V_43 -> V_83 ,
& V_30 ) ;
V_78 += snprintf ( & V_75 [ V_78 ] , V_77 , L_19 ,
F_41 ( & V_46 -> V_50 ) ,
V_30 . V_73 , V_30 . V_74 ) ;
V_77 = V_76 - V_78 ;
if ( V_77 >= V_76 )
goto V_69;
}
V_78 += snprintf ( & V_75 [ V_78 ] , V_77 , L_17 ) ;
V_69:
return V_78 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_44 * V_26 = V_2 -> V_26 ;
struct V_47 * V_48 ;
struct V_42 * V_43 ;
struct V_84 * V_85 ;
T_1 * V_83 ;
int V_49 ;
V_49 = F_28 ( V_2 ) ;
if ( V_49 < 0 ) {
F_26 ( V_2 , V_49 ) ;
return;
}
V_49 = F_29 ( V_26 , V_2 -> V_58 ) ;
if ( V_49 ) {
F_22 ( & V_26 -> V_50 ,
L_8 , V_49 ) ;
F_19 ( V_2 ) ;
return;
}
V_2 -> V_86 = true ;
V_2 -> V_82 = 0 ;
V_49 = F_44 ( V_26 , & V_2 -> V_82 ) ;
V_2 -> V_86 = false ;
if ( V_49 ) {
F_22 ( & V_26 -> V_50 ,
L_20 , V_49 ) ;
F_19 ( V_2 ) ;
return;
}
V_48 = V_2 -> V_51 -> V_48 ;
V_2 -> V_51 -> V_83 = 0 ;
V_49 = V_48 -> V_52 -> V_87 ( V_48 ,
& V_2 -> V_51 -> V_83 ) ;
if ( V_49 )
F_22 ( & V_48 -> V_50 , L_21 , V_49 ) ;
F_20 (timesync_interface,
&timesync_svc->interface_list, list) {
V_85 = V_43 -> V_46 -> V_85 ;
V_43 -> V_83 = 0 ;
V_83 = & V_43 -> V_83 ;
V_49 = F_45 ( V_85 ,
V_83 ) ;
if ( V_49 ) {
F_22 ( & V_43 -> V_46 -> V_50 ,
L_22 , V_49 ) ;
}
}
F_23 ( V_26 ) ;
F_25 () ;
F_11 ( V_2 , V_20 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
char * V_75 ;
if ( ! V_2 -> V_61 )
return;
V_75 = F_47 ( V_88 , V_89 ) ;
if ( V_75 ) {
F_40 ( V_2 , V_75 , V_88 ) ;
F_48 ( & V_2 -> V_26 -> V_50 , L_23 , V_75 ) ;
F_49 ( V_75 ) ;
}
}
static void F_50 ( struct V_90 * V_91 )
{
struct V_8 * V_8 = F_51 ( V_91 ) ;
struct V_1 * V_2 =
F_52 ( V_8 , struct V_1 , V_8 ) ;
F_37 ( & V_2 -> V_68 ) ;
switch ( V_2 -> V_10 ) {
case V_14 :
F_27 ( V_2 ) ;
break;
case V_17 :
F_22 ( & V_2 -> V_26 -> V_50 ,
L_24 ,
V_2 -> V_15 , V_39 ) ;
F_19 ( V_2 ) ;
break;
case V_18 :
F_32 ( V_2 ) ;
break;
case V_19 :
F_43 ( V_2 ) ;
F_46 ( V_2 ) ;
break;
default:
F_10 ( L_25 ,
V_2 -> V_10 ) ;
break;
}
F_39 ( & V_2 -> V_68 ) ;
}
static int F_53 ( struct V_1 * V_2 , int V_10 )
{
int V_49 = 0 ;
if ( V_10 != V_14 && V_10 != V_19 )
return - V_62 ;
F_37 ( & V_2 -> V_68 ) ;
if ( V_2 -> V_10 != V_11 )
F_11 ( V_2 , V_10 ) ;
else
V_49 = - V_63 ;
F_39 ( & V_2 -> V_68 ) ;
return V_49 ;
}
static int F_54 (
struct V_1 * V_2 , int V_10 )
{
unsigned long V_22 ;
int V_49 ;
V_49 = F_53 ( V_2 , V_10 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_55 ( V_2 -> V_12 ,
( V_2 -> V_10 == V_20 ||
V_2 -> V_10 == V_13 ||
V_2 -> V_10 == V_11 ) ) ;
if ( V_49 )
return V_49 ;
F_37 ( & V_2 -> V_68 ) ;
F_12 ( & V_2 -> V_23 , V_22 ) ;
V_49 = F_35 ( V_2 ) ;
F_13 ( & V_2 -> V_23 , V_22 ) ;
F_39 ( & V_2 -> V_68 ) ;
return V_49 ;
}
static struct V_1 * F_56 (
struct V_47 * V_48 )
{
struct V_1 * V_2 ;
F_20 (timesync_svc, &gb_timesync_svc_list, list) {
if ( V_2 -> V_26 == V_48 -> V_26 )
return V_2 ;
}
return NULL ;
}
static struct V_42 * F_57 (
struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_42 * V_43 ;
F_20 (timesync_interface, &timesync_svc->interface_list, list) {
if ( V_43 -> V_46 == V_46 )
return V_43 ;
}
return NULL ;
}
int F_58 ( struct V_45 * V_46 )
{
int V_49 ;
struct V_1 * V_2 ;
int V_92 ;
if ( ! ( V_46 -> V_93 & V_94 ) )
return 0 ;
F_37 ( & V_95 ) ;
for ( V_92 = 0 ; V_92 < V_96 ; V_92 ++ ) {
V_2 = F_56 ( V_46 -> V_48 ) ;
if ( ! V_2 ) {
V_49 = - V_63 ;
goto V_69;
}
V_49 = F_54 ( V_2 ,
V_14 ) ;
if ( ! V_49 )
break;
}
if ( V_49 && V_92 == V_96 )
V_49 = - V_97 ;
V_69:
F_39 ( & V_95 ) ;
return V_49 ;
}
void F_59 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
if ( ! ( V_46 -> V_93 & V_94 ) )
return;
F_37 ( & V_95 ) ;
V_2 = F_56 ( V_46 -> V_48 ) ;
if ( ! V_2 )
goto V_69;
F_53 ( V_2 , V_14 ) ;
V_69:
F_39 ( & V_95 ) ;
return;
}
static T_3 F_60 ( struct V_98 * V_98 , char T_4 * V_99 ,
T_2 V_77 , T_5 * V_100 , bool V_101 )
{
struct V_1 * V_2 = F_61 ( V_98 ) -> V_102 ;
char * V_75 ;
T_3 V_49 = 0 ;
F_37 ( & V_95 ) ;
F_37 ( & V_2 -> V_68 ) ;
if ( F_62 ( & V_2 -> V_103 ) )
V_49 = - V_63 ;
V_2 -> V_61 = false ;
F_39 ( & V_2 -> V_68 ) ;
if ( V_49 )
goto V_69;
V_49 = F_54 ( V_2 ,
V_19 ) ;
if ( V_49 )
goto V_69;
V_75 = F_47 ( V_88 , V_89 ) ;
if ( ! V_75 ) {
V_49 = - V_104 ;
goto V_69;
}
if ( V_101 )
V_49 = F_42 ( V_2 , V_75 , V_88 ) ;
else
V_49 = F_40 ( V_2 , V_75 , V_88 ) ;
if ( V_49 > 0 )
V_49 = F_63 ( V_99 , V_77 , V_100 , V_75 , V_49 ) ;
F_49 ( V_75 ) ;
V_69:
F_39 ( & V_95 ) ;
return V_49 ;
}
static T_3 F_64 ( struct V_98 * V_98 ,
char T_4 * V_75 ,
T_2 V_77 , T_5 * V_100 )
{
return F_60 ( V_98 , V_75 , V_77 , V_100 , false ) ;
}
static T_3 F_65 ( struct V_98 * V_98 ,
char T_4 * V_75 ,
T_2 V_77 , T_5 * V_100 )
{
return F_60 ( V_98 , V_75 , V_77 , V_100 , true ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_105 * V_51 ;
V_51 = F_47 ( sizeof( * V_51 ) , V_89 ) ;
if ( ! V_51 )
return - V_104 ;
F_9 ( V_2 -> V_51 ) ;
V_51 -> V_48 = V_48 ;
V_2 -> V_51 = V_51 ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
if ( V_2 -> V_51 -> V_48 == V_48 ) {
F_49 ( V_2 -> V_51 ) ;
V_2 -> V_51 = NULL ;
return;
}
F_9 ( 1 ) ;
}
int F_68 ( struct V_44 * V_26 )
{
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_47 ( sizeof( * V_2 ) , V_89 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_7 =
F_69 ( L_26 ) ;
if ( ! V_2 -> V_7 ) {
F_49 ( V_2 ) ;
return - V_104 ;
}
F_37 ( & V_95 ) ;
F_70 ( & V_2 -> V_103 ) ;
F_71 ( & V_2 -> V_8 , F_50 ) ;
F_72 ( & V_2 -> V_68 ) ;
F_73 ( & V_2 -> V_23 ) ;
F_74 ( & V_2 -> V_12 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_5 = 0 ;
V_2 -> V_86 = false ;
F_11 ( V_2 , V_13 ) ;
V_2 -> V_106 =
F_75 ( L_27 , V_107 , V_26 -> V_108 ,
V_2 ,
& V_109 ) ;
V_2 -> V_110 =
F_75 ( L_28 , V_107 , V_26 -> V_108 ,
V_2 ,
& V_111 ) ;
F_76 ( & V_2 -> V_112 , & V_113 ) ;
V_49 = F_66 ( V_2 , V_26 -> V_48 ) ;
if ( V_49 ) {
F_77 ( & V_2 -> V_112 ) ;
F_78 ( V_2 -> V_110 ) ;
F_78 ( V_2 -> V_106 ) ;
F_79 ( V_2 -> V_7 ) ;
F_49 ( V_2 ) ;
goto V_69;
}
F_80 ( & V_2 -> V_114 ) ;
V_2 -> V_114 . V_115 = V_116 ;
V_2 -> V_114 . V_117 = V_118 + V_119 ;
V_2 -> V_114 . V_120 = ( unsigned long ) V_2 ;
F_81 ( & V_2 -> V_114 ) ;
V_69:
F_39 ( & V_95 ) ;
return V_49 ;
}
void F_82 ( struct V_44 * V_26 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_42 * V_121 ;
F_37 ( & V_95 ) ;
V_2 = F_56 ( V_26 -> V_48 ) ;
if ( ! V_2 )
goto V_69;
F_83 ( & V_2 -> V_8 ) ;
F_37 ( & V_2 -> V_68 ) ;
F_11 ( V_2 , V_11 ) ;
F_84 ( & V_2 -> V_114 ) ;
F_19 ( V_2 ) ;
F_67 ( V_2 , V_26 -> V_48 ) ;
F_85 (timesync_interface, next,
&timesync_svc->interface_list, list) {
F_77 ( & V_43 -> V_112 ) ;
F_49 ( V_43 ) ;
}
F_78 ( V_2 -> V_110 ) ;
F_78 ( V_2 -> V_106 ) ;
F_79 ( V_2 -> V_7 ) ;
F_77 ( & V_2 -> V_112 ) ;
F_39 ( & V_2 -> V_68 ) ;
F_49 ( V_2 ) ;
V_69:
F_39 ( & V_95 ) ;
}
int F_86 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
int V_49 = 0 ;
if ( ! ( V_46 -> V_93 & V_94 ) )
return 0 ;
F_37 ( & V_95 ) ;
V_2 = F_56 ( V_46 -> V_48 ) ;
if ( ! V_2 ) {
V_49 = - V_63 ;
goto V_69;
}
V_43 = F_47 ( sizeof( * V_43 ) , V_89 ) ;
if ( ! V_43 ) {
V_49 = - V_104 ;
goto V_69;
}
F_37 ( & V_2 -> V_68 ) ;
V_43 -> V_46 = V_46 ;
F_76 ( & V_43 -> V_112 , & V_2 -> V_103 ) ;
V_2 -> V_58 |= 1 << V_46 -> V_122 ;
F_39 ( & V_2 -> V_68 ) ;
V_69:
F_39 ( & V_95 ) ;
return V_49 ;
}
void F_87 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
if ( ! ( V_46 -> V_93 & V_94 ) )
return;
F_37 ( & V_95 ) ;
V_2 = F_56 ( V_46 -> V_48 ) ;
if ( ! V_2 )
goto V_69;
V_43 = F_57 ( V_2 ,
V_46 ) ;
if ( ! V_43 )
goto V_69;
F_37 ( & V_2 -> V_68 ) ;
V_2 -> V_58 &= ~ ( 1 << V_46 -> V_122 ) ;
F_77 ( & V_43 -> V_112 ) ;
F_49 ( V_43 ) ;
F_39 ( & V_2 -> V_68 ) ;
V_69:
F_39 ( & V_95 ) ;
}
static T_1 F_88 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
T_1 V_49 ;
F_12 ( & V_2 -> V_23 , V_22 ) ;
if ( V_2 -> V_10 == V_20 )
V_49 = F_2 ( V_2 ) ;
else
V_49 = 0 ;
F_13 ( & V_2 -> V_23 , V_22 ) ;
return V_49 ;
}
T_1 F_89 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
T_1 V_49 = 0 ;
F_37 ( & V_95 ) ;
V_2 = F_56 ( V_46 -> V_48 ) ;
if ( ! V_2 )
goto V_69;
V_49 = F_88 ( V_2 ) ;
V_69:
F_39 ( & V_95 ) ;
return V_49 ;
}
T_1 F_90 ( struct V_44 * V_26 )
{
struct V_1 * V_2 ;
T_1 V_49 = 0 ;
F_37 ( & V_95 ) ;
V_2 = F_56 ( V_26 -> V_48 ) ;
if ( ! V_2 )
goto V_69;
V_49 = F_88 ( V_2 ) ;
V_69:
F_39 ( & V_95 ) ;
return V_49 ;
}
static void V_116 ( unsigned long V_120 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_120 ;
unsigned long V_22 ;
T_1 V_31 ;
struct V_29 V_30 ;
F_12 ( & V_2 -> V_23 , V_22 ) ;
if ( V_2 -> V_10 != V_20 )
goto V_69;
F_91 ( & V_30 ) ;
V_31 = F_2 ( V_2 ) ;
F_16 ( V_2 , V_30 , V_31 ) ;
V_69:
F_13 ( & V_2 -> V_23 , V_22 ) ;
F_92 ( & V_2 -> V_114 ,
V_118 + V_119 ) ;
}
int F_93 ( struct V_44 * V_26 , T_1 V_31 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 ;
int V_49 = 0 ;
F_37 ( & V_95 ) ;
V_2 = F_56 ( V_26 -> V_48 ) ;
if ( ! V_2 ) {
V_49 = - V_63 ;
goto V_69;
}
V_49 = F_36 ( V_2 , V_31 , V_30 ) ;
V_69:
F_39 ( & V_95 ) ;
return V_49 ;
}
int F_94 ( struct V_45 * V_46 ,
T_1 V_31 , struct V_29 * V_30 )
{
struct V_1 * V_2 ;
int V_49 = 0 ;
F_37 ( & V_95 ) ;
V_2 = F_56 ( V_46 -> V_48 ) ;
if ( ! V_2 ) {
V_49 = - V_63 ;
goto V_69;
}
V_49 = F_36 ( V_2 , V_31 , V_30 ) ;
V_69:
F_39 ( & V_95 ) ;
return V_49 ;
}
void F_95 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
T_1 V_123 ;
bool V_124 = true ;
struct V_29 V_30 ;
F_91 ( & V_30 ) ;
V_123 = F_2 ( V_2 ) ;
F_12 ( & V_2 -> V_23 , V_22 ) ;
if ( V_2 -> V_10 == V_19 ) {
if ( ! V_2 -> V_86 )
goto V_125;
V_2 -> V_81 = V_123 ;
goto V_126;
} else if ( V_2 -> V_10 != V_17 ) {
goto V_125;
}
V_2 -> V_40 [ V_2 -> V_15 ] . V_31 = V_123 ;
V_2 -> V_40 [ V_2 -> V_15 ] . V_30 = V_30 ;
if ( ++ V_2 -> V_15 == V_39 ) {
F_6 ( V_2 ,
V_18 ) ;
}
V_124 = false ;
V_126:
F_96 ( V_124 , V_2 -> V_15 ,
V_39 , V_123 ) ;
V_125:
F_13 ( & V_2 -> V_23 , V_22 ) ;
}
int T_6 F_97 ( void )
{
int V_49 = 0 ;
V_49 = F_98 () ;
if ( V_49 ) {
F_10 ( L_29 ) ;
return V_49 ;
}
V_57 = F_99 () ;
V_71 = V_127 ;
F_38 ( V_71 , V_57 ) ;
V_41 = V_72 ;
F_38 ( V_41 , V_57 ) ;
V_70 =
V_128 * V_57 ;
F_100 ( L_30 ,
V_57 , V_128 ) ;
return 0 ;
}
void F_101 ( void )
{
F_102 () ;
}
