static T_1 F_1 ( struct V_1 * V_1 , char * V_2 )
{
int V_3 = - V_4 ;
struct V_5 * V_5 = V_1 -> V_6 -> V_7 ;
if ( ! V_5 )
return V_3 ;
V_3 = sprintf ( V_2 , L_1 , V_5 -> V_8 ) ;
return V_3 ;
}
static int F_2 ( struct V_9 * V_9 , int V_10 )
{
struct V_11 * V_11 ;
T_2 V_12 , V_13 , V_14 ;
V_11 = F_3 ( V_9 ) ;
if ( ! ( V_11 -> V_15 & ( 1 << V_10 ) ) )
return - V_16 ;
V_14 = F_4 ( V_9 ) ;
V_12 = V_11 -> V_17 . V_18 ;
V_13 = F_5 ( V_9 ) & 0xf ;
if ( ( V_14 == V_19 ||
V_14 == V_20 ) &&
( V_13 == 1 && V_12 == 0 && V_10 != 1 ) )
return - V_16 ;
return 1 ;
}
static int F_6 ( struct V_9 * V_9 )
{
struct V_11 * V_11 ;
T_3 V_21 ;
T_2 V_14 ;
V_11 = F_3 ( V_9 ) ;
V_21 = V_11 -> V_17 . V_22 ;
if ( V_21 == V_23 )
return - V_16 ;
V_14 = F_4 ( V_9 ) ;
switch ( V_14 ) {
case V_19 :
case V_24 :
case V_20 :
case V_25 :
case V_26 :
return 1 ;
break;
default:
return - V_16 ;
break;
}
return - V_27 ;
}
static int F_7 ( struct V_28 * V_29 ,
struct V_9 * V_9 , int V_10 ,
char * V_30 )
{
struct V_11 * V_11 ;
struct V_5 * V_5 ;
V_11 = F_3 ( V_9 ) ;
V_5 = F_8 ( sizeof( * V_5 ) , V_31 ) ;
if ( ! V_5 )
return - V_32 ;
V_29 -> V_7 = V_5 ;
V_5 -> V_33 = V_10 ;
V_5 -> V_9 = V_9 ;
sprintf ( V_30 , L_2 ,
F_5 ( V_9 ) ,
( ( T_2 ) V_11 -> V_17 . V_18 ) ,
V_10 + 1 ) ;
F_9 ( V_9 , V_5 -> V_8 ) ;
V_5 -> V_28 = V_29 ;
F_10 ( & V_5 -> V_34 , & V_35 ) ;
return 0 ;
}
static struct V_28 * F_11 ( void )
{
struct V_5 * V_5 ;
struct V_1 * V_1 ;
struct V_28 * V_29 = NULL ;
F_12 (slot, &sn_hp_list, hp_list) {
V_29 = V_5 -> V_28 ;
V_1 = V_29 -> V_1 ;
F_13 ( & ( (struct V_5 * ) V_29 -> V_7 ) ->
V_34 ) ;
F_14 ( & V_1 -> V_36 ,
& V_37 . V_38 ) ;
break;
}
return V_29 ;
}
static void F_15 ( struct V_39 * V_40 )
{
struct V_9 * V_41 ;
struct V_39 * V_42 ;
if ( V_40 -> V_43 ) {
V_41 = V_40 -> V_43 ;
F_12 (child, &subordinate_bus->devices, bus_list)
F_15 ( V_42 ) ;
}
F_16 ( V_40 ) ;
F_17 ( V_40 ) ;
}
static int F_18 ( struct V_28 * V_29 ,
int V_33 , char * * V_44 )
{
struct V_5 * V_5 = V_29 -> V_7 ;
struct V_11 * V_11 ;
struct V_45 V_46 ;
int V_47 ;
V_11 = F_3 ( V_5 -> V_9 ) ;
V_47 = F_19 ( V_11 , V_33 , & V_46 , V_44 ) ;
if ( V_47 == V_48 ) {
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 , L_3 ) ;
return 1 ;
}
if ( V_47 == V_50 ) {
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 ,
L_4 ,
V_46 . V_51 , V_46 . V_52 ) ;
return - V_16 ;
}
if ( V_47 ) {
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 ,
L_5 ,
V_47 , V_46 . V_51 ) ;
return - V_27 ;
}
V_11 = F_3 ( V_5 -> V_9 ) ;
V_11 -> V_53 |= ( 1 << V_33 ) ;
return 0 ;
}
static int F_21 ( struct V_28 * V_29 ,
int V_33 , int V_54 )
{
struct V_5 * V_5 = V_29 -> V_7 ;
struct V_11 * V_11 ;
struct V_55 V_46 ;
int V_47 ;
V_11 = F_3 ( V_5 -> V_9 ) ;
V_47 = F_22 ( V_11 , V_33 , V_54 , & V_46 ) ;
if ( ( V_54 == V_56 ) &&
( V_47 == V_57 ) ) {
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 , L_6 , V_5 -> V_8 ) ;
return 1 ;
}
if ( ( V_54 == V_56 ) && ( V_47 == V_58 ) ) {
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 ,
L_7 ) ;
return - V_16 ;
}
if ( ( V_54 == V_56 ) && ( V_47 == V_50 ) ) {
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 ,
L_8 ,
V_46 . V_51 , V_46 . V_52 ) ;
return - V_16 ;
}
if ( ( V_54 == V_56 ) && V_47 ) {
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 ,
L_9 ,
V_47 , V_46 . V_51 ) ;
return - V_27 ;
}
if ( ( V_54 == V_56 ) && ! V_47 )
return 0 ;
if ( ( V_54 == V_59 ) && ! V_47 ) {
V_11 = F_3 ( V_5 -> V_9 ) ;
V_11 -> V_53 &= ~ ( 1 << V_33 ) ;
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 , L_10 ) ;
return 0 ;
}
if ( ( V_54 == V_59 ) && V_47 ) {
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 , L_11 , V_47 ) ;
}
return V_47 ;
}
static int F_23 ( struct V_28 * V_29 )
{
struct V_5 * V_5 = V_29 -> V_7 ;
struct V_9 * V_60 = NULL ;
struct V_39 * V_40 ;
int V_61 , V_62 ;
int V_63 = 0 ;
int V_47 ;
char * V_44 = NULL ;
void V_64 ( struct V_39 * ) ;
F_24 ( & V_65 ) ;
V_47 = F_18 ( V_29 , V_5 -> V_33 , & V_44 ) ;
if ( V_47 ) {
F_25 ( & V_65 ) ;
return V_47 ;
}
if ( V_44 )
V_44 = F_26 ( V_44 ) ;
if ( F_27 () && V_44 ) {
T_4 V_66 ;
V_66 = F_28 ( (struct V_67 * ) V_44 ) ;
if ( F_29 ( V_66 ) ) {
F_30 ( V_68 L_12 ,
V_69 , V_66 ) ;
}
}
V_62 = F_31 ( V_5 -> V_9 ,
F_32 ( V_5 -> V_33 + 1 , 0 ) ) ;
if ( ! V_62 ) {
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 , L_13 ) ;
F_25 ( & V_65 ) ;
return - V_70 ;
}
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_40 = F_33 ( V_5 -> V_9 ,
F_32 ( V_5 -> V_33 + 1 ,
F_34 ( V_61 ) ) ) ;
if ( V_40 ) {
V_64 ( V_40 ) ;
if ( F_27 () )
F_35 ( V_40 ) ;
else
F_36 ( V_40 ) ;
if ( V_40 -> V_71 == V_72 ) {
unsigned char V_73 ;
F_37 ( V_40 , V_74 ,
& V_73 ) ;
V_60 = F_38 ( V_40 -> V_75 , V_40 ,
V_73 ) ;
F_39 ( V_60 ) ;
V_63 = 1 ;
}
F_40 ( V_40 ) ;
}
}
if ( F_27 () && V_44 ) {
unsigned long long V_76 ;
struct V_77 * V_78 ;
struct V_77 * V_10 ;
T_5 V_79 ;
T_5 V_80 = NULL ;
T_5 V_81 ;
T_4 V_66 ;
V_79 = F_41 ( V_5 -> V_9 ) -> T_5 ;
if ( F_42 ( V_79 , & V_78 ) ) {
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 ,
L_14 ) ;
V_78 = NULL ;
}
for (; ; ) {
V_81 = NULL ;
V_66 = F_43 ( V_82 ,
V_79 , V_80 ,
& V_81 ) ;
if ( V_66 == V_83 || V_81 == NULL )
break;
V_80 = V_81 ;
V_66 = F_44 ( V_80 , V_84 ,
NULL , & V_76 ) ;
if ( F_45 ( V_66 ) &&
( V_76 >> 16 ) == ( V_5 -> V_33 + 1 ) ) {
V_66 = F_46 ( & V_10 , V_78 , V_80 ,
V_85 ) ;
if ( F_29 ( V_66 ) ) {
F_30 ( V_68 L_15
L_16
L_17 , V_69 ,
V_66 , ( int ) ( V_76 >> 16 ) ,
( int ) ( V_76 & 0xffff ) ) ;
} else {
F_47 ( V_10 ) ;
}
}
}
}
F_48 ( V_5 -> V_9 ) ;
if ( V_63 )
F_48 ( V_60 ) ;
F_25 ( & V_65 ) ;
if ( V_47 == 0 )
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 ,
L_18 ) ;
else
F_20 ( & V_5 -> V_9 -> V_49 -> V_40 ,
L_19 , V_47 ) ;
return V_47 ;
}
static int F_49 ( struct V_28 * V_29 )
{
struct V_5 * V_5 = V_29 -> V_7 ;
struct V_39 * V_40 ;
int V_61 ;
int V_47 ;
T_6 V_86 = 0 ;
F_24 ( & V_65 ) ;
V_47 = F_21 ( V_29 , V_5 -> V_33 ,
V_56 ) ;
if ( V_47 )
goto V_87;
if ( F_27 () &&
F_41 ( V_5 -> V_9 ) -> T_5 ) {
unsigned long long V_76 ;
struct V_77 * V_10 ;
T_5 V_79 ;
T_5 V_80 = NULL ;
T_5 V_81 ;
T_4 V_66 ;
V_79 = F_41 ( V_5 -> V_9 ) -> T_5 ;
for (; ; ) {
V_81 = NULL ;
V_66 = F_43 ( V_82 ,
V_79 , V_80 ,
& V_81 ) ;
if ( V_66 == V_83 || V_81 == NULL )
break;
V_80 = V_81 ;
V_66 = F_44 ( V_80 ,
V_84 ,
NULL , & V_76 ) ;
if ( F_45 ( V_66 ) &&
( V_76 >> 16 ) == ( V_5 -> V_33 + 1 ) ) {
F_50 ( V_80 , & V_86 ) ;
V_66 = F_42 ( V_80 ,
& V_10 ) ;
if ( F_45 ( V_66 ) )
F_51 ( V_10 , 1 ) ;
}
}
}
for ( V_61 = 0 ; V_61 < 8 ; V_61 ++ ) {
V_40 = F_33 ( V_5 -> V_9 ,
F_32 ( V_5 -> V_33 + 1 ,
F_34 ( V_61 ) ) ) ;
if ( V_40 ) {
F_15 ( V_40 ) ;
F_52 ( V_40 ) ;
F_40 ( V_40 ) ;
}
}
if ( F_27 () && V_86 ) {
T_4 V_66 ;
V_66 = F_53 ( V_86 ) ;
if ( F_29 ( V_66 ) ) {
F_30 ( V_68 L_20
L_21 ,
V_69 , V_66 , V_86 ) ;
}
}
F_54 () ;
V_47 = F_21 ( V_29 , V_5 -> V_33 ,
V_59 ) ;
V_87:
F_25 ( & V_65 ) ;
return V_47 ;
}
static inline int F_55 ( struct V_28 * V_29 ,
T_7 * V_88 )
{
struct V_5 * V_5 = V_29 -> V_7 ;
struct V_11 * V_11 ;
T_3 V_89 ;
V_11 = F_3 ( V_5 -> V_9 ) ;
F_24 ( & V_65 ) ;
V_89 = V_11 -> V_53 & ( 1 << V_5 -> V_33 ) ;
* V_88 = V_89 ? 1 : 0 ;
F_25 ( & V_65 ) ;
return 0 ;
}
static void F_56 ( struct V_28 * V_29 )
{
F_57 ( V_29 -> V_90 ) ;
F_57 ( V_29 -> V_7 ) ;
F_57 ( V_29 ) ;
}
static int F_58 ( struct V_9 * V_9 )
{
int V_10 ;
struct V_1 * V_1 ;
struct V_28 * V_29 ;
char V_30 [ V_91 ] ;
int V_47 = 0 ;
for ( V_10 = 0 ; V_10 < V_92 ; V_10 ++ ) {
if ( F_2 ( V_9 , V_10 ) != 1 )
continue;
V_29 = F_8 ( sizeof( * V_29 ) ,
V_31 ) ;
if ( ! V_29 ) {
V_47 = - V_32 ;
goto V_93;
}
V_29 -> V_90 =
F_8 ( sizeof( struct V_94 ) ,
V_31 ) ;
if ( ! V_29 -> V_90 ) {
V_47 = - V_32 ;
goto V_93;
}
if ( F_7 ( V_29 ,
V_9 , V_10 , V_30 ) ) {
V_47 = - V_32 ;
goto V_93;
}
V_29 -> V_95 = & V_96 ;
V_29 -> V_97 = & F_56 ;
V_47 = F_59 ( V_29 , V_9 , V_10 , V_30 ) ;
if ( V_47 )
goto V_98;
V_1 = V_29 -> V_1 ;
V_47 = F_60 ( & V_1 -> V_36 ,
& V_37 . V_38 ) ;
if ( V_47 )
goto V_98;
}
F_20 ( & V_9 -> V_49 -> V_40 , L_22 ) ;
return V_47 ;
V_98:
F_20 ( & V_9 -> V_49 -> V_40 , L_23 ,
V_47 ) ;
V_93:
if ( V_47 == - V_32 )
F_20 ( & V_9 -> V_49 -> V_40 , L_24 ) ;
if ( V_29 )
F_56 ( V_29 ) ;
while ( ( V_29 = F_11 () ) )
F_61 ( V_29 ) ;
return V_47 ;
}
static int T_8 F_62 ( void )
{
struct V_9 * V_9 = NULL ;
int V_47 ;
int V_99 = 0 ;
if ( ! F_63 ( V_100 ) ) {
F_30 ( V_68 L_25 ,
V_69 ) ;
return - V_16 ;
}
F_64 ( & V_35 ) ;
while ( ( V_9 = F_65 ( V_9 ) ) ) {
if ( ! V_9 -> V_101 )
continue;
V_47 = F_6 ( V_9 ) ;
if ( V_47 != 1 ) {
F_20 ( & V_9 -> V_49 -> V_40 , L_26 ) ;
continue;
}
F_20 ( & V_9 -> V_49 -> V_40 , L_27 ) ;
V_47 = F_58 ( V_9 ) ;
if ( ! V_47 ) {
V_99 = 1 ;
} else {
V_99 = 0 ;
break;
}
}
return V_99 == 1 ? 0 : - V_70 ;
}
static void T_9 F_66 ( void )
{
struct V_28 * V_29 ;
while ( ( V_29 = F_11 () ) )
F_61 ( V_29 ) ;
if ( ! F_67 ( & V_35 ) )
F_30 ( V_68 L_28 , __FILE__ ) ;
}
