static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( ! V_2 -> V_4 )
return false ;
return F_2 ( V_2 -> V_4 ) == V_3 ;
}
static struct V_5 * F_3 ( char * V_6 , int V_7 )
{
struct V_1 * V_8 ;
T_1 V_9 ;
T_2 V_10 ;
V_10 = F_4 ( NULL , V_6 , & V_9 ) ;
if ( F_5 ( V_10 ) )
return F_6 ( - V_11 ) ;
V_8 = F_7 ( V_9 , F_1 ) ;
if ( ! V_8 )
return F_6 ( - V_11 ) ;
if ( V_7 < 0 || V_7 > V_8 -> V_12 )
return F_6 ( - V_13 ) ;
return F_8 ( V_8 , V_7 ) ;
}
static T_3 F_9 ( int V_14 , void * V_3 )
{
struct V_15 * V_16 = V_3 ;
F_10 ( V_16 -> V_9 , NULL , NULL , NULL ) ;
return V_17 ;
}
static T_3 F_11 ( int V_14 , void * V_3 )
{
struct V_15 * V_16 = V_3 ;
F_12 ( V_16 -> V_9 , NULL , V_16 -> V_7 ) ;
return V_17 ;
}
static void F_13 ( T_1 V_9 , void * V_3 )
{
}
static T_2 F_14 ( struct V_18 * V_19 ,
void * V_20 )
{
struct V_21 * V_22 = V_20 ;
struct V_1 * V_8 = V_22 -> V_8 ;
struct V_23 * V_24 ;
T_1 V_9 , V_25 ;
struct V_15 * V_16 ;
T_4 V_26 = NULL ;
struct V_5 * V_27 ;
unsigned long V_28 ;
int V_29 , V_7 , V_14 ;
if ( V_19 -> type != V_30 )
return V_31 ;
V_24 = & V_19 -> V_3 . V_32 ;
if ( V_24 -> V_33 != V_34 )
return V_31 ;
V_9 = F_2 ( V_8 -> V_4 ) ;
V_7 = V_24 -> V_35 [ 0 ] ;
if ( V_7 <= 255 ) {
char V_36 [ 5 ] ;
sprintf ( V_36 , L_1 ,
V_24 -> V_37 == V_38 ? 'E' : 'L' ,
V_7 ) ;
if ( F_15 ( F_4 ( V_9 , V_36 , & V_25 ) ) )
V_26 = F_9 ;
}
if ( ! V_26 ) {
if ( F_15 ( F_4 ( V_9 , L_2 , & V_25 ) ) )
V_26 = F_11 ;
}
if ( ! V_26 )
return V_39 ;
V_27 = F_8 ( V_8 , V_7 ) ;
if ( F_16 ( V_27 ) ) {
F_17 ( V_8 -> V_4 , L_3 ) ;
return V_40 ;
}
V_29 = F_18 ( V_27 , L_4 ) ;
if ( V_29 ) {
F_17 ( V_8 -> V_4 , L_5 ) ;
return V_40 ;
}
F_19 ( V_27 ) ;
V_29 = F_20 ( V_8 , V_7 ) ;
if ( V_29 ) {
F_17 ( V_8 -> V_4 , L_6 ) ;
goto V_41;
}
V_14 = F_21 ( V_27 ) ;
if ( V_14 < 0 ) {
F_17 ( V_8 -> V_4 , L_7 ) ;
goto V_42;
}
V_28 = V_43 ;
if ( V_24 -> V_37 == V_44 ) {
if ( V_24 -> V_45 == V_46 )
V_28 |= V_47 ;
else
V_28 |= V_48 ;
} else {
switch ( V_24 -> V_45 ) {
case V_46 :
V_28 |= V_49 ;
break;
case V_50 :
V_28 |= V_51 ;
break;
default:
V_28 |= V_49 |
V_51 ;
break;
}
}
V_16 = F_22 ( sizeof( * V_16 ) , V_52 ) ;
if ( ! V_16 )
goto V_42;
V_16 -> V_9 = V_25 ;
V_16 -> V_14 = V_14 ;
V_16 -> V_7 = V_7 ;
V_29 = F_23 ( V_16 -> V_14 , NULL , V_26 , V_28 ,
L_4 , V_16 ) ;
if ( V_29 ) {
F_17 ( V_8 -> V_4 , L_8 ,
V_16 -> V_14 ) ;
goto V_53;
}
F_24 ( & V_16 -> V_54 , & V_22 -> V_55 ) ;
return V_31 ;
V_53:
F_25 ( V_16 ) ;
V_42:
F_26 ( V_8 , V_7 ) ;
V_41:
F_27 ( V_27 ) ;
return V_40 ;
}
void F_28 ( struct V_1 * V_8 )
{
struct V_21 * V_22 ;
T_1 V_9 ;
T_2 V_10 ;
if ( ! V_8 -> V_4 || ! V_8 -> V_56 )
return;
V_9 = F_2 ( V_8 -> V_4 ) ;
if ( ! V_9 )
return;
V_10 = F_29 ( V_9 , F_13 , ( void * * ) & V_22 ) ;
if ( F_5 ( V_10 ) )
return;
F_30 ( & V_22 -> V_55 ) ;
F_31 ( F_2 ( V_8 -> V_4 ) , L_9 ,
F_14 , V_22 ) ;
}
void F_32 ( struct V_1 * V_8 )
{
struct V_21 * V_22 ;
struct V_15 * V_16 , * V_57 ;
T_1 V_9 ;
T_2 V_10 ;
if ( ! V_8 -> V_4 || ! V_8 -> V_56 )
return;
V_9 = F_2 ( V_8 -> V_4 ) ;
if ( ! V_9 )
return;
V_10 = F_29 ( V_9 , F_13 , ( void * * ) & V_22 ) ;
if ( F_5 ( V_10 ) )
return;
F_33 (event, ep, &acpi_gpio->events, node) {
struct V_5 * V_27 ;
F_34 ( V_16 -> V_14 , V_16 ) ;
V_27 = F_8 ( V_8 , V_16 -> V_7 ) ;
if ( F_35 ( F_16 ( V_27 ) ) )
continue;
F_26 ( V_8 , V_16 -> V_7 ) ;
F_27 ( V_27 ) ;
F_36 ( & V_16 -> V_54 ) ;
F_25 ( V_16 ) ;
}
}
static int F_37 ( struct V_18 * V_19 , void * V_3 )
{
struct V_58 * V_59 = V_3 ;
if ( V_19 -> type != V_30 )
return 1 ;
if ( V_59 -> V_60 ++ == V_59 -> V_61 && ! V_59 -> V_27 ) {
const struct V_23 * V_24 = & V_19 -> V_3 . V_32 ;
V_59 -> V_27 = F_3 ( V_24 -> V_62 . V_63 ,
V_24 -> V_35 [ 0 ] ) ;
V_59 -> V_64 . V_65 =
V_24 -> V_33 == V_34 ;
V_59 -> V_64 . V_66 =
V_24 -> V_45 == V_50 ;
}
return 1 ;
}
struct V_5 * F_38 ( struct V_67 * V_4 , int V_61 ,
struct V_68 * V_64 )
{
struct V_58 V_59 ;
struct V_69 V_70 ;
struct V_71 * V_72 ;
T_1 V_9 ;
int V_29 ;
if ( ! V_4 )
return F_6 ( - V_13 ) ;
V_9 = F_2 ( V_4 ) ;
if ( ! V_9 || F_39 ( V_9 , & V_72 ) )
return F_6 ( - V_11 ) ;
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_61 = V_61 ;
F_30 ( & V_70 ) ;
V_29 = F_40 ( V_72 , & V_70 , F_37 ,
& V_59 ) ;
if ( V_29 < 0 )
return F_6 ( V_29 ) ;
F_41 ( & V_70 ) ;
if ( V_59 . V_27 && V_64 )
* V_64 = V_59 . V_64 ;
return V_59 . V_27 ? V_59 . V_27 : F_6 ( - V_73 ) ;
}
static T_2
F_42 ( T_5 V_74 , T_6 V_75 ,
T_5 V_76 , T_7 * V_77 , void * V_78 ,
void * V_79 )
{
struct V_21 * V_80 = V_79 ;
struct V_1 * V_8 = V_80 -> V_8 ;
struct V_23 * V_24 ;
struct V_18 * V_19 ;
int V_81 = ( int ) V_75 ;
T_2 V_10 ;
bool V_82 ;
int V_83 ;
int V_84 ;
V_10 = F_43 ( V_80 -> V_85 . V_86 ,
V_80 -> V_85 . V_83 , & V_19 ) ;
if ( F_5 ( V_10 ) )
return V_10 ;
if ( F_35 ( V_19 -> type != V_30 ) ) {
F_44 ( V_19 ) ;
return V_39 ;
}
V_24 = & V_19 -> V_3 . V_32 ;
V_82 = V_24 -> V_87 == V_88 ;
if ( F_35 ( V_24 -> V_89 == V_90 &&
V_74 == V_91 ) ) {
F_44 ( V_19 ) ;
return V_39 ;
}
V_83 = F_45 ( V_24 -> V_92 , ( V_93 ) ( V_81 + V_76 ) ) ;
for ( V_84 = V_81 ; V_84 < V_83 ; ++ V_84 ) {
unsigned V_7 = V_24 -> V_35 [ V_84 ] ;
struct V_94 * V_95 ;
struct V_5 * V_27 ;
bool V_96 ;
V_27 = F_8 ( V_8 , V_7 ) ;
if ( F_16 ( V_27 ) ) {
V_10 = V_40 ;
goto V_97;
}
F_46 ( & V_80 -> V_98 ) ;
V_96 = false ;
F_47 (conn, &achip->conns, node) {
if ( V_95 -> V_27 == V_27 ) {
V_96 = true ;
break;
}
}
if ( ! V_96 ) {
int V_29 ;
V_29 = F_18 ( V_27 , L_10 ) ;
if ( V_29 ) {
V_10 = V_40 ;
F_48 ( & V_80 -> V_98 ) ;
goto V_97;
}
switch ( V_24 -> V_89 ) {
case V_90 :
F_19 ( V_27 ) ;
break;
case V_99 :
F_49 ( V_27 , V_82 ) ;
break;
default:
break;
}
V_95 = F_22 ( sizeof( * V_95 ) , V_52 ) ;
if ( ! V_95 ) {
V_10 = V_100 ;
F_27 ( V_27 ) ;
F_48 ( & V_80 -> V_98 ) ;
goto V_97;
}
V_95 -> V_27 = V_27 ;
F_24 ( & V_95 -> V_54 , & V_80 -> V_101 ) ;
}
F_48 ( & V_80 -> V_98 ) ;
if ( V_74 == V_91 )
F_50 ( V_27 ,
! ! ( ( 1 << V_84 ) & * V_77 ) ) ;
else
* V_77 |= ( T_7 ) F_51 ( V_27 ) << V_84 ;
}
V_97:
F_44 ( V_19 ) ;
return V_10 ;
}
static void F_52 ( struct V_21 * V_80 )
{
struct V_1 * V_8 = V_80 -> V_8 ;
T_1 V_9 = F_2 ( V_8 -> V_4 ) ;
T_2 V_10 ;
F_30 ( & V_80 -> V_101 ) ;
F_53 ( & V_80 -> V_98 ) ;
V_10 = F_54 ( V_9 , V_102 ,
F_42 ,
NULL , V_80 ) ;
if ( F_5 ( V_10 ) )
F_17 ( V_8 -> V_4 , L_11 ) ;
}
static void F_55 ( struct V_21 * V_80 )
{
struct V_1 * V_8 = V_80 -> V_8 ;
T_1 V_9 = F_2 ( V_8 -> V_4 ) ;
struct V_94 * V_95 , * V_103 ;
T_2 V_10 ;
V_10 = F_56 ( V_9 , V_102 ,
F_42 ) ;
if ( F_5 ( V_10 ) ) {
F_17 ( V_8 -> V_4 , L_12 ) ;
return;
}
F_33 (conn, tmp, &achip->conns, node) {
F_27 ( V_95 -> V_27 ) ;
F_36 ( & V_95 -> V_54 ) ;
F_25 ( V_95 ) ;
}
}
void F_57 ( struct V_1 * V_8 )
{
struct V_21 * V_22 ;
T_1 V_9 ;
T_2 V_10 ;
if ( ! V_8 || ! V_8 -> V_4 )
return;
V_9 = F_2 ( V_8 -> V_4 ) ;
if ( ! V_9 )
return;
V_22 = F_22 ( sizeof( * V_22 ) , V_52 ) ;
if ( ! V_22 ) {
F_17 ( V_8 -> V_4 ,
L_13 ) ;
return;
}
V_22 -> V_8 = V_8 ;
V_10 = F_58 ( V_9 , F_13 , V_22 ) ;
if ( F_5 ( V_10 ) ) {
F_17 ( V_8 -> V_4 , L_14 ) ;
F_25 ( V_22 ) ;
return;
}
F_52 ( V_22 ) ;
}
void F_59 ( struct V_1 * V_8 )
{
struct V_21 * V_22 ;
T_1 V_9 ;
T_2 V_10 ;
if ( ! V_8 || ! V_8 -> V_4 )
return;
V_9 = F_2 ( V_8 -> V_4 ) ;
if ( ! V_9 )
return;
V_10 = F_29 ( V_9 , F_13 , ( void * * ) & V_22 ) ;
if ( F_5 ( V_10 ) ) {
F_60 ( V_8 -> V_4 , L_15 ) ;
return;
}
F_55 ( V_22 ) ;
F_61 ( V_9 , F_13 ) ;
F_25 ( V_22 ) ;
}
