static T_1 F_1 ( void )
{
return V_1 ;
}
static struct V_2 * F_2 ( T_1 V_3 )
{
struct V_2 * V_4 ;
F_3 (vsock, &vhost_vsock_list, list) {
T_1 V_5 = V_4 -> V_3 ;
if ( V_5 == 0 )
continue;
if ( V_5 == V_3 ) {
return V_4 ;
}
}
return NULL ;
}
static struct V_2 * F_4 ( T_1 V_3 )
{
struct V_2 * V_4 ;
F_5 ( & V_6 ) ;
V_4 = F_2 ( V_3 ) ;
F_6 ( & V_6 ) ;
return V_4 ;
}
static void
F_7 ( struct V_2 * V_4 ,
struct V_7 * V_8 )
{
struct V_7 * V_9 = & V_4 -> V_10 [ V_11 ] ;
bool V_12 = false ;
bool V_13 = false ;
F_8 ( & V_8 -> V_14 ) ;
if ( ! V_8 -> V_15 )
goto V_16;
F_9 ( & V_4 -> V_17 , V_8 ) ;
for (; ; ) {
struct V_18 * V_19 ;
struct V_20 V_20 ;
unsigned V_16 , V_21 ;
T_2 V_22 ;
T_2 V_23 ;
int V_24 ;
F_5 ( & V_4 -> V_25 ) ;
if ( F_10 ( & V_4 -> V_26 ) ) {
F_6 ( & V_4 -> V_25 ) ;
F_11 ( & V_4 -> V_17 , V_8 ) ;
break;
}
V_19 = F_12 ( & V_4 -> V_26 ,
struct V_18 , V_27 ) ;
F_13 ( & V_19 -> V_27 ) ;
F_6 ( & V_4 -> V_25 ) ;
V_24 = F_14 ( V_8 , V_8 -> V_28 , F_15 ( V_8 -> V_28 ) ,
& V_16 , & V_21 , NULL , NULL ) ;
if ( V_24 < 0 ) {
F_5 ( & V_4 -> V_25 ) ;
F_16 ( & V_19 -> V_27 , & V_4 -> V_26 ) ;
F_6 ( & V_4 -> V_25 ) ;
break;
}
if ( V_24 == V_8 -> V_29 ) {
F_5 ( & V_4 -> V_25 ) ;
F_16 ( & V_19 -> V_27 , & V_4 -> V_26 ) ;
F_6 ( & V_4 -> V_25 ) ;
if ( F_17 ( F_11 ( & V_4 -> V_17 , V_8 ) ) ) {
F_9 ( & V_4 -> V_17 , V_8 ) ;
continue;
}
break;
}
if ( V_16 ) {
F_18 ( V_19 ) ;
F_19 ( V_8 , L_1 , V_16 ) ;
break;
}
V_23 = F_20 ( & V_8 -> V_28 [ V_16 ] , V_21 ) ;
F_21 ( & V_20 , V_30 , & V_8 -> V_28 [ V_16 ] , V_21 , V_23 ) ;
V_22 = F_22 ( & V_19 -> V_31 , sizeof( V_19 -> V_31 ) , & V_20 ) ;
if ( V_22 != sizeof( V_19 -> V_31 ) ) {
F_18 ( V_19 ) ;
F_19 ( V_8 , L_2 ) ;
break;
}
V_22 = F_22 ( V_19 -> V_32 , V_19 -> V_23 , & V_20 ) ;
if ( V_22 != V_19 -> V_23 ) {
F_18 ( V_19 ) ;
F_19 ( V_8 , L_3 ) ;
break;
}
F_23 ( V_8 , V_24 , sizeof( V_19 -> V_31 ) + V_19 -> V_23 ) ;
V_12 = true ;
if ( V_19 -> V_33 ) {
int V_34 ;
V_34 = F_24 ( & V_4 -> V_35 ) ;
if ( V_34 + 1 == V_9 -> V_29 )
V_13 = true ;
}
F_18 ( V_19 ) ;
}
if ( V_12 )
F_25 ( & V_4 -> V_17 , V_8 ) ;
V_16:
F_26 ( & V_8 -> V_14 ) ;
if ( V_13 )
F_27 ( & V_9 -> V_36 ) ;
}
static void F_28 ( struct V_37 * V_38 )
{
struct V_7 * V_8 ;
struct V_2 * V_4 ;
V_4 = F_29 ( V_38 , struct V_2 , V_39 ) ;
V_8 = & V_4 -> V_10 [ V_40 ] ;
F_7 ( V_4 , V_8 ) ;
}
static int
F_30 ( struct V_18 * V_19 )
{
struct V_2 * V_4 ;
int V_23 = V_19 -> V_23 ;
V_4 = F_4 ( F_31 ( V_19 -> V_31 . V_41 ) ) ;
if ( ! V_4 ) {
F_18 ( V_19 ) ;
return - V_42 ;
}
if ( V_19 -> V_33 )
F_32 ( & V_4 -> V_35 ) ;
F_5 ( & V_4 -> V_25 ) ;
F_33 ( & V_19 -> V_27 , & V_4 -> V_26 ) ;
F_6 ( & V_4 -> V_25 ) ;
F_34 ( & V_4 -> V_17 , & V_4 -> V_39 ) ;
return V_23 ;
}
static struct V_18 *
F_35 ( struct V_7 * V_8 ,
unsigned int V_16 , unsigned int V_21 )
{
struct V_18 * V_19 ;
struct V_20 V_20 ;
T_2 V_22 ;
T_2 V_23 ;
if ( V_21 != 0 ) {
F_19 ( V_8 , L_4 , V_21 ) ;
return NULL ;
}
V_19 = F_36 ( sizeof( * V_19 ) , V_43 ) ;
if ( ! V_19 )
return NULL ;
V_23 = F_20 ( V_8 -> V_28 , V_16 ) ;
F_21 ( & V_20 , V_44 , V_8 -> V_28 , V_16 , V_23 ) ;
V_22 = F_37 ( & V_19 -> V_31 , sizeof( V_19 -> V_31 ) , & V_20 ) ;
if ( V_22 != sizeof( V_19 -> V_31 ) ) {
F_19 ( V_8 , L_5 ,
sizeof( V_19 -> V_31 ) , V_22 ) ;
F_38 ( V_19 ) ;
return NULL ;
}
if ( F_39 ( V_19 -> V_31 . type ) == V_45 )
V_19 -> V_23 = F_40 ( V_19 -> V_31 . V_23 ) ;
if ( ! V_19 -> V_23 )
return V_19 ;
if ( V_19 -> V_23 > V_46 ) {
F_38 ( V_19 ) ;
return NULL ;
}
V_19 -> V_32 = F_41 ( V_19 -> V_23 , V_43 ) ;
if ( ! V_19 -> V_32 ) {
F_38 ( V_19 ) ;
return NULL ;
}
V_22 = F_37 ( V_19 -> V_32 , V_19 -> V_23 , & V_20 ) ;
if ( V_22 != V_19 -> V_23 ) {
F_19 ( V_8 , L_6 ,
V_19 -> V_23 , V_22 ) ;
F_18 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
static bool F_42 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_10 [ V_11 ] ;
int V_34 ;
F_43 () ;
V_34 = F_44 ( & V_4 -> V_35 ) ;
return V_34 < V_8 -> V_29 ;
}
static void F_45 ( struct V_37 * V_38 )
{
struct V_7 * V_8 = F_29 ( V_38 , struct V_7 ,
V_36 . V_38 ) ;
struct V_2 * V_4 = F_29 ( V_8 -> V_17 , struct V_2 ,
V_17 ) ;
struct V_18 * V_19 ;
int V_24 ;
unsigned int V_16 , V_21 ;
bool V_12 = false ;
F_8 ( & V_8 -> V_14 ) ;
if ( ! V_8 -> V_15 )
goto V_16;
F_9 ( & V_4 -> V_17 , V_8 ) ;
for (; ; ) {
T_1 V_23 ;
if ( ! F_42 ( V_4 ) ) {
goto V_47;
}
V_24 = F_14 ( V_8 , V_8 -> V_28 , F_15 ( V_8 -> V_28 ) ,
& V_16 , & V_21 , NULL , NULL ) ;
if ( V_24 < 0 )
break;
if ( V_24 == V_8 -> V_29 ) {
if ( F_17 ( F_11 ( & V_4 -> V_17 , V_8 ) ) ) {
F_9 ( & V_4 -> V_17 , V_8 ) ;
continue;
}
break;
}
V_19 = F_35 ( V_8 , V_16 , V_21 ) ;
if ( ! V_19 ) {
F_19 ( V_8 , L_7 ) ;
continue;
}
V_23 = V_19 -> V_23 ;
if ( F_31 ( V_19 -> V_31 . V_48 ) == V_4 -> V_3 )
F_46 ( V_19 ) ;
else
F_18 ( V_19 ) ;
F_23 ( V_8 , V_24 , sizeof( V_19 -> V_31 ) + V_23 ) ;
V_12 = true ;
}
V_47:
if ( V_12 )
F_25 ( & V_4 -> V_17 , V_8 ) ;
V_16:
F_26 ( & V_8 -> V_14 ) ;
}
static void F_47 ( struct V_37 * V_38 )
{
struct V_7 * V_8 = F_29 ( V_38 , struct V_7 ,
V_36 . V_38 ) ;
struct V_2 * V_4 = F_29 ( V_8 -> V_17 , struct V_2 ,
V_17 ) ;
F_7 ( V_4 , V_8 ) ;
}
static int F_48 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
T_2 V_49 ;
int V_50 ;
F_8 ( & V_4 -> V_17 . V_14 ) ;
V_50 = F_49 ( & V_4 -> V_17 ) ;
if ( V_50 )
goto V_51;
for ( V_49 = 0 ; V_49 < F_15 ( V_4 -> V_10 ) ; V_49 ++ ) {
V_8 = & V_4 -> V_10 [ V_49 ] ;
F_8 ( & V_8 -> V_14 ) ;
if ( ! F_50 ( V_8 ) ) {
V_50 = - V_52 ;
goto V_53;
}
if ( ! V_8 -> V_15 ) {
V_8 -> V_15 = V_4 ;
V_50 = F_51 ( V_8 ) ;
if ( V_50 )
goto V_53;
}
F_26 ( & V_8 -> V_14 ) ;
}
F_26 ( & V_4 -> V_17 . V_14 ) ;
return 0 ;
V_53:
V_8 -> V_15 = NULL ;
F_26 ( & V_8 -> V_14 ) ;
for ( V_49 = 0 ; V_49 < F_15 ( V_4 -> V_10 ) ; V_49 ++ ) {
V_8 = & V_4 -> V_10 [ V_49 ] ;
F_8 ( & V_8 -> V_14 ) ;
V_8 -> V_15 = NULL ;
F_26 ( & V_8 -> V_14 ) ;
}
V_51:
F_26 ( & V_4 -> V_17 . V_14 ) ;
return V_50 ;
}
static int F_52 ( struct V_2 * V_4 )
{
T_2 V_49 ;
int V_50 ;
F_8 ( & V_4 -> V_17 . V_14 ) ;
V_50 = F_49 ( & V_4 -> V_17 ) ;
if ( V_50 )
goto V_51;
for ( V_49 = 0 ; V_49 < F_15 ( V_4 -> V_10 ) ; V_49 ++ ) {
struct V_7 * V_8 = & V_4 -> V_10 [ V_49 ] ;
F_8 ( & V_8 -> V_14 ) ;
V_8 -> V_15 = NULL ;
F_26 ( & V_8 -> V_14 ) ;
}
V_51:
F_26 ( & V_4 -> V_17 . V_14 ) ;
return V_50 ;
}
static void F_53 ( struct V_2 * V_4 )
{
F_54 ( V_4 ) ;
}
static int F_55 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
struct V_7 * * V_10 ;
struct V_2 * V_4 ;
int V_50 ;
V_4 = F_36 ( sizeof( * V_4 ) , V_43 | V_56 | V_57 ) ;
if ( ! V_4 ) {
V_4 = F_56 ( sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_58 ;
}
V_10 = F_57 ( F_15 ( V_4 -> V_10 ) , sizeof( * V_10 ) , V_43 ) ;
if ( ! V_10 ) {
V_50 = - V_58 ;
goto V_16;
}
F_58 ( & V_4 -> V_35 , 0 ) ;
V_10 [ V_11 ] = & V_4 -> V_10 [ V_11 ] ;
V_10 [ V_40 ] = & V_4 -> V_10 [ V_40 ] ;
V_4 -> V_10 [ V_11 ] . V_59 = F_45 ;
V_4 -> V_10 [ V_40 ] . V_59 = F_47 ;
F_59 ( & V_4 -> V_17 , V_10 , F_15 ( V_4 -> V_10 ) ) ;
V_55 -> V_15 = V_4 ;
F_60 ( & V_4 -> V_25 ) ;
F_61 ( & V_4 -> V_26 ) ;
F_62 ( & V_4 -> V_39 , F_28 ) ;
F_5 ( & V_6 ) ;
F_33 ( & V_4 -> V_27 , & V_60 ) ;
F_6 ( & V_6 ) ;
return 0 ;
V_16:
F_53 ( V_4 ) ;
return V_50 ;
}
static void F_63 ( struct V_2 * V_4 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < F_15 ( V_4 -> V_10 ) ; V_49 ++ )
if ( V_4 -> V_10 [ V_49 ] . V_59 )
F_64 ( & V_4 -> V_10 [ V_49 ] . V_36 ) ;
F_65 ( & V_4 -> V_17 , & V_4 -> V_39 ) ;
}
static void F_66 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_67 ( V_62 ) ;
if ( ! F_4 ( V_64 -> V_65 . V_66 ) ) {
F_68 ( V_62 , V_67 ) ;
V_64 -> V_68 = V_69 ;
V_62 -> V_70 = V_71 ;
V_62 -> V_72 = V_73 ;
V_62 -> V_74 ( V_62 ) ;
}
}
static int F_69 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
struct V_2 * V_4 = V_55 -> V_15 ;
F_5 ( & V_6 ) ;
F_70 ( & V_4 -> V_27 ) ;
F_6 ( & V_6 ) ;
F_71 ( F_66 ) ;
F_52 ( V_4 ) ;
F_63 ( V_4 ) ;
F_72 ( & V_4 -> V_17 ) ;
F_5 ( & V_4 -> V_25 ) ;
while ( ! F_10 ( & V_4 -> V_26 ) ) {
struct V_18 * V_19 ;
V_19 = F_12 ( & V_4 -> V_26 ,
struct V_18 , V_27 ) ;
F_13 ( & V_19 -> V_27 ) ;
F_18 ( V_19 ) ;
}
F_6 ( & V_4 -> V_25 ) ;
F_73 ( & V_4 -> V_17 , false ) ;
F_38 ( V_4 -> V_17 . V_10 ) ;
F_53 ( V_4 ) ;
return 0 ;
}
static int F_74 ( struct V_2 * V_4 , T_3 V_3 )
{
struct V_2 * V_75 ;
if ( V_3 <= V_76 ||
V_3 == V_77 )
return - V_78 ;
if ( V_3 > V_77 )
return - V_78 ;
F_5 ( & V_6 ) ;
V_75 = F_2 ( V_3 ) ;
if ( V_75 && V_75 != V_4 ) {
F_6 ( & V_6 ) ;
return - V_79 ;
}
V_4 -> V_3 = V_3 ;
F_6 ( & V_6 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_4 , T_3 V_80 )
{
struct V_7 * V_8 ;
int V_49 ;
if ( V_80 & ~ V_81 )
return - V_82 ;
F_8 ( & V_4 -> V_17 . V_14 ) ;
if ( ( V_80 & ( 1 << V_83 ) ) &&
! F_76 ( & V_4 -> V_17 ) ) {
F_26 ( & V_4 -> V_17 . V_14 ) ;
return - V_52 ;
}
for ( V_49 = 0 ; V_49 < F_15 ( V_4 -> V_10 ) ; V_49 ++ ) {
V_8 = & V_4 -> V_10 [ V_49 ] ;
F_8 ( & V_8 -> V_14 ) ;
V_8 -> V_84 = V_80 ;
F_26 ( & V_8 -> V_14 ) ;
}
F_26 ( & V_4 -> V_17 . V_14 ) ;
return 0 ;
}
static long F_77 ( struct V_55 * V_85 , unsigned int V_86 ,
unsigned long V_87 )
{
struct V_2 * V_4 = V_85 -> V_15 ;
void T_4 * V_88 = ( void T_4 * ) V_87 ;
T_3 V_3 ;
T_3 V_80 ;
int V_89 ;
int V_90 ;
switch ( V_86 ) {
case V_91 :
if ( F_78 ( & V_3 , V_88 , sizeof( V_3 ) ) )
return - V_52 ;
return F_74 ( V_4 , V_3 ) ;
case V_92 :
if ( F_78 ( & V_89 , V_88 , sizeof( V_89 ) ) )
return - V_52 ;
if ( V_89 )
return F_48 ( V_4 ) ;
else
return F_52 ( V_4 ) ;
case V_93 :
V_80 = V_81 ;
if ( F_79 ( V_88 , & V_80 , sizeof( V_80 ) ) )
return - V_52 ;
return 0 ;
case V_94 :
if ( F_78 ( & V_80 , V_88 , sizeof( V_80 ) ) )
return - V_52 ;
return F_75 ( V_4 , V_80 ) ;
default:
F_8 ( & V_4 -> V_17 . V_14 ) ;
V_90 = F_80 ( & V_4 -> V_17 , V_86 , V_88 ) ;
if ( V_90 == - V_95 )
V_90 = F_81 ( & V_4 -> V_17 , V_86 , V_88 ) ;
else
F_63 ( V_4 ) ;
F_26 ( & V_4 -> V_17 . V_14 ) ;
return V_90 ;
}
}
static int T_5 F_82 ( void )
{
int V_50 ;
V_50 = F_83 ( & V_96 . V_97 ) ;
if ( V_50 < 0 )
return V_50 ;
return F_84 ( & V_98 ) ;
}
static void T_6 F_85 ( void )
{
F_86 ( & V_98 ) ;
F_87 () ;
}
