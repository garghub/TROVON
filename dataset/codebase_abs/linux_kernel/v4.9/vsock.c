static T_1 F_1 ( void )
{
return V_1 ;
}
static struct V_2 * F_2 ( T_1 V_3 )
{
struct V_2 * V_4 ;
F_3 ( & V_5 ) ;
F_4 (vsock, &vhost_vsock_list, list) {
T_1 V_6 = V_4 -> V_3 ;
if ( V_6 == 0 )
continue;
if ( V_6 == V_3 ) {
F_5 ( & V_5 ) ;
return V_4 ;
}
}
F_5 ( & V_5 ) ;
return NULL ;
}
static void
F_6 ( struct V_2 * V_4 ,
struct V_7 * V_8 )
{
struct V_7 * V_9 = & V_4 -> V_10 [ V_11 ] ;
bool V_12 = false ;
bool V_13 = false ;
F_7 ( & V_8 -> V_14 ) ;
if ( ! V_8 -> V_15 )
goto V_16;
F_8 ( & V_4 -> V_17 , V_8 ) ;
for (; ; ) {
struct V_18 * V_19 ;
struct V_20 V_20 ;
unsigned V_16 , V_21 ;
T_2 V_22 ;
T_2 V_23 ;
int V_24 ;
F_3 ( & V_4 -> V_25 ) ;
if ( F_9 ( & V_4 -> V_26 ) ) {
F_5 ( & V_4 -> V_25 ) ;
F_10 ( & V_4 -> V_17 , V_8 ) ;
break;
}
V_19 = F_11 ( & V_4 -> V_26 ,
struct V_18 , V_27 ) ;
F_12 ( & V_19 -> V_27 ) ;
F_5 ( & V_4 -> V_25 ) ;
V_24 = F_13 ( V_8 , V_8 -> V_28 , F_14 ( V_8 -> V_28 ) ,
& V_16 , & V_21 , NULL , NULL ) ;
if ( V_24 < 0 ) {
F_3 ( & V_4 -> V_25 ) ;
F_15 ( & V_19 -> V_27 , & V_4 -> V_26 ) ;
F_5 ( & V_4 -> V_25 ) ;
break;
}
if ( V_24 == V_8 -> V_29 ) {
F_3 ( & V_4 -> V_25 ) ;
F_15 ( & V_19 -> V_27 , & V_4 -> V_26 ) ;
F_5 ( & V_4 -> V_25 ) ;
if ( F_16 ( F_10 ( & V_4 -> V_17 , V_8 ) ) ) {
F_8 ( & V_4 -> V_17 , V_8 ) ;
continue;
}
break;
}
if ( V_16 ) {
F_17 ( V_19 ) ;
F_18 ( V_8 , L_1 , V_16 ) ;
break;
}
V_23 = F_19 ( & V_8 -> V_28 [ V_16 ] , V_21 ) ;
F_20 ( & V_20 , V_30 , & V_8 -> V_28 [ V_16 ] , V_21 , V_23 ) ;
V_22 = F_21 ( & V_19 -> V_31 , sizeof( V_19 -> V_31 ) , & V_20 ) ;
if ( V_22 != sizeof( V_19 -> V_31 ) ) {
F_17 ( V_19 ) ;
F_18 ( V_8 , L_2 ) ;
break;
}
V_22 = F_21 ( V_19 -> V_32 , V_19 -> V_23 , & V_20 ) ;
if ( V_22 != V_19 -> V_23 ) {
F_17 ( V_19 ) ;
F_18 ( V_8 , L_3 ) ;
break;
}
F_22 ( V_8 , V_24 , sizeof( V_19 -> V_31 ) + V_19 -> V_23 ) ;
V_12 = true ;
if ( V_19 -> V_33 ) {
int V_34 ;
V_34 = F_23 ( & V_4 -> V_35 ) ;
if ( V_34 + 1 == V_9 -> V_29 )
V_13 = true ;
}
F_17 ( V_19 ) ;
}
if ( V_12 )
F_24 ( & V_4 -> V_17 , V_8 ) ;
V_16:
F_25 ( & V_8 -> V_14 ) ;
if ( V_13 )
F_26 ( & V_9 -> V_36 ) ;
}
static void F_27 ( struct V_37 * V_38 )
{
struct V_7 * V_8 ;
struct V_2 * V_4 ;
V_4 = F_28 ( V_38 , struct V_2 , V_39 ) ;
V_8 = & V_4 -> V_10 [ V_40 ] ;
F_6 ( V_4 , V_8 ) ;
}
static int
F_29 ( struct V_18 * V_19 )
{
struct V_2 * V_4 ;
struct V_7 * V_8 ;
int V_23 = V_19 -> V_23 ;
V_4 = F_2 ( F_30 ( V_19 -> V_31 . V_41 ) ) ;
if ( ! V_4 ) {
F_17 ( V_19 ) ;
return - V_42 ;
}
V_8 = & V_4 -> V_10 [ V_40 ] ;
if ( V_19 -> V_33 )
F_31 ( & V_4 -> V_35 ) ;
F_3 ( & V_4 -> V_25 ) ;
F_32 ( & V_19 -> V_27 , & V_4 -> V_26 ) ;
F_5 ( & V_4 -> V_25 ) ;
F_33 ( & V_4 -> V_17 , & V_4 -> V_39 ) ;
return V_23 ;
}
static struct V_18 *
F_34 ( struct V_7 * V_8 ,
unsigned int V_16 , unsigned int V_21 )
{
struct V_18 * V_19 ;
struct V_20 V_20 ;
T_2 V_22 ;
T_2 V_23 ;
if ( V_21 != 0 ) {
F_18 ( V_8 , L_4 , V_21 ) ;
return NULL ;
}
V_19 = F_35 ( sizeof( * V_19 ) , V_43 ) ;
if ( ! V_19 )
return NULL ;
V_23 = F_19 ( V_8 -> V_28 , V_16 ) ;
F_20 ( & V_20 , V_44 , V_8 -> V_28 , V_16 , V_23 ) ;
V_22 = F_36 ( & V_19 -> V_31 , sizeof( V_19 -> V_31 ) , & V_20 ) ;
if ( V_22 != sizeof( V_19 -> V_31 ) ) {
F_18 ( V_8 , L_5 ,
sizeof( V_19 -> V_31 ) , V_22 ) ;
F_37 ( V_19 ) ;
return NULL ;
}
if ( F_38 ( V_19 -> V_31 . type ) == V_45 )
V_19 -> V_23 = F_39 ( V_19 -> V_31 . V_23 ) ;
if ( ! V_19 -> V_23 )
return V_19 ;
if ( V_19 -> V_23 > V_46 ) {
F_37 ( V_19 ) ;
return NULL ;
}
V_19 -> V_32 = F_40 ( V_19 -> V_23 , V_43 ) ;
if ( ! V_19 -> V_32 ) {
F_37 ( V_19 ) ;
return NULL ;
}
V_22 = F_36 ( V_19 -> V_32 , V_19 -> V_23 , & V_20 ) ;
if ( V_22 != V_19 -> V_23 ) {
F_18 ( V_8 , L_6 ,
V_19 -> V_23 , V_22 ) ;
F_17 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
static bool F_41 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_10 [ V_11 ] ;
int V_34 ;
F_42 () ;
V_34 = F_43 ( & V_4 -> V_35 ) ;
return V_34 < V_8 -> V_29 ;
}
static void F_44 ( struct V_37 * V_38 )
{
struct V_7 * V_8 = F_28 ( V_38 , struct V_7 ,
V_36 . V_38 ) ;
struct V_2 * V_4 = F_28 ( V_8 -> V_17 , struct V_2 ,
V_17 ) ;
struct V_18 * V_19 ;
int V_24 ;
unsigned int V_16 , V_21 ;
bool V_12 = false ;
F_7 ( & V_8 -> V_14 ) ;
if ( ! V_8 -> V_15 )
goto V_16;
F_8 ( & V_4 -> V_17 , V_8 ) ;
for (; ; ) {
T_1 V_23 ;
if ( ! F_41 ( V_4 ) ) {
goto V_47;
}
V_24 = F_13 ( V_8 , V_8 -> V_28 , F_14 ( V_8 -> V_28 ) ,
& V_16 , & V_21 , NULL , NULL ) ;
if ( V_24 < 0 )
break;
if ( V_24 == V_8 -> V_29 ) {
if ( F_16 ( F_10 ( & V_4 -> V_17 , V_8 ) ) ) {
F_8 ( & V_4 -> V_17 , V_8 ) ;
continue;
}
break;
}
V_19 = F_34 ( V_8 , V_16 , V_21 ) ;
if ( ! V_19 ) {
F_18 ( V_8 , L_7 ) ;
continue;
}
V_23 = V_19 -> V_23 ;
if ( F_30 ( V_19 -> V_31 . V_48 ) == V_4 -> V_3 )
F_45 ( V_19 ) ;
else
F_17 ( V_19 ) ;
F_22 ( V_8 , V_24 , sizeof( V_19 -> V_31 ) + V_23 ) ;
V_12 = true ;
}
V_47:
if ( V_12 )
F_24 ( & V_4 -> V_17 , V_8 ) ;
V_16:
F_25 ( & V_8 -> V_14 ) ;
}
static void F_46 ( struct V_37 * V_38 )
{
struct V_7 * V_8 = F_28 ( V_38 , struct V_7 ,
V_36 . V_38 ) ;
struct V_2 * V_4 = F_28 ( V_8 -> V_17 , struct V_2 ,
V_17 ) ;
F_6 ( V_4 , V_8 ) ;
}
static int F_47 ( struct V_2 * V_4 )
{
T_2 V_49 ;
int V_50 ;
F_7 ( & V_4 -> V_17 . V_14 ) ;
V_50 = F_48 ( & V_4 -> V_17 ) ;
if ( V_50 )
goto V_51;
for ( V_49 = 0 ; V_49 < F_14 ( V_4 -> V_10 ) ; V_49 ++ ) {
struct V_7 * V_8 = & V_4 -> V_10 [ V_49 ] ;
F_7 ( & V_8 -> V_14 ) ;
if ( ! F_49 ( V_8 ) ) {
V_50 = - V_52 ;
F_25 ( & V_8 -> V_14 ) ;
goto V_53;
}
if ( ! V_8 -> V_15 ) {
V_8 -> V_15 = V_4 ;
F_50 ( V_8 ) ;
}
F_25 ( & V_8 -> V_14 ) ;
}
F_25 ( & V_4 -> V_17 . V_14 ) ;
return 0 ;
V_53:
for ( V_49 = 0 ; V_49 < F_14 ( V_4 -> V_10 ) ; V_49 ++ ) {
struct V_7 * V_8 = & V_4 -> V_10 [ V_49 ] ;
F_7 ( & V_8 -> V_14 ) ;
V_8 -> V_15 = NULL ;
F_25 ( & V_8 -> V_14 ) ;
}
V_51:
F_25 ( & V_4 -> V_17 . V_14 ) ;
return V_50 ;
}
static int F_51 ( struct V_2 * V_4 )
{
T_2 V_49 ;
int V_50 ;
F_7 ( & V_4 -> V_17 . V_14 ) ;
V_50 = F_48 ( & V_4 -> V_17 ) ;
if ( V_50 )
goto V_51;
for ( V_49 = 0 ; V_49 < F_14 ( V_4 -> V_10 ) ; V_49 ++ ) {
struct V_7 * V_8 = & V_4 -> V_10 [ V_49 ] ;
F_7 ( & V_8 -> V_14 ) ;
V_8 -> V_15 = NULL ;
F_25 ( & V_8 -> V_14 ) ;
}
V_51:
F_25 ( & V_4 -> V_17 . V_14 ) ;
return V_50 ;
}
static void F_52 ( struct V_2 * V_4 )
{
F_53 ( V_4 ) ;
}
static int F_54 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
struct V_7 * * V_10 ;
struct V_2 * V_4 ;
int V_50 ;
V_4 = F_35 ( sizeof( * V_4 ) , V_43 | V_56 | V_57 ) ;
if ( ! V_4 ) {
V_4 = F_55 ( sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_58 ;
}
V_10 = F_56 ( F_14 ( V_4 -> V_10 ) , sizeof( * V_10 ) , V_43 ) ;
if ( ! V_10 ) {
V_50 = - V_58 ;
goto V_16;
}
F_57 ( & V_4 -> V_35 , 0 ) ;
V_10 [ V_11 ] = & V_4 -> V_10 [ V_11 ] ;
V_10 [ V_40 ] = & V_4 -> V_10 [ V_40 ] ;
V_4 -> V_10 [ V_11 ] . V_59 = F_44 ;
V_4 -> V_10 [ V_40 ] . V_59 = F_46 ;
F_58 ( & V_4 -> V_17 , V_10 , F_14 ( V_4 -> V_10 ) ) ;
V_55 -> V_15 = V_4 ;
F_59 ( & V_4 -> V_25 ) ;
F_60 ( & V_4 -> V_26 ) ;
F_61 ( & V_4 -> V_39 , F_27 ) ;
F_3 ( & V_5 ) ;
F_32 ( & V_4 -> V_27 , & V_60 ) ;
F_5 ( & V_5 ) ;
return 0 ;
V_16:
F_52 ( V_4 ) ;
return V_50 ;
}
static void F_62 ( struct V_2 * V_4 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < F_14 ( V_4 -> V_10 ) ; V_49 ++ )
if ( V_4 -> V_10 [ V_49 ] . V_59 )
F_63 ( & V_4 -> V_10 [ V_49 ] . V_36 ) ;
F_64 ( & V_4 -> V_17 , & V_4 -> V_39 ) ;
}
static void F_65 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_66 ( V_62 ) ;
if ( ! F_2 ( V_64 -> V_65 . V_66 ) ) {
F_67 ( V_62 , V_67 ) ;
V_64 -> V_68 = V_69 ;
V_62 -> V_70 = V_71 ;
V_62 -> V_72 = V_73 ;
V_62 -> V_74 ( V_62 ) ;
}
}
static int F_68 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
struct V_2 * V_4 = V_55 -> V_15 ;
F_3 ( & V_5 ) ;
F_69 ( & V_4 -> V_27 ) ;
F_5 ( & V_5 ) ;
F_70 ( F_65 ) ;
F_51 ( V_4 ) ;
F_62 ( V_4 ) ;
F_71 ( & V_4 -> V_17 ) ;
F_3 ( & V_4 -> V_25 ) ;
while ( ! F_9 ( & V_4 -> V_26 ) ) {
struct V_18 * V_19 ;
V_19 = F_11 ( & V_4 -> V_26 ,
struct V_18 , V_27 ) ;
F_12 ( & V_19 -> V_27 ) ;
F_17 ( V_19 ) ;
}
F_5 ( & V_4 -> V_25 ) ;
F_72 ( & V_4 -> V_17 , false ) ;
F_37 ( V_4 -> V_17 . V_10 ) ;
F_52 ( V_4 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_4 , T_3 V_3 )
{
struct V_2 * V_75 ;
if ( V_3 <= V_76 ||
V_3 == V_77 )
return - V_78 ;
if ( V_3 > V_77 )
return - V_78 ;
V_75 = F_2 ( V_3 ) ;
if ( V_75 && V_75 != V_4 )
return - V_79 ;
F_3 ( & V_5 ) ;
V_4 -> V_3 = V_3 ;
F_5 ( & V_5 ) ;
return 0 ;
}
static int F_74 ( struct V_2 * V_4 , T_3 V_80 )
{
struct V_7 * V_8 ;
int V_49 ;
if ( V_80 & ~ V_81 )
return - V_82 ;
F_7 ( & V_4 -> V_17 . V_14 ) ;
if ( ( V_80 & ( 1 << V_83 ) ) &&
! F_75 ( & V_4 -> V_17 ) ) {
F_25 ( & V_4 -> V_17 . V_14 ) ;
return - V_52 ;
}
for ( V_49 = 0 ; V_49 < F_14 ( V_4 -> V_10 ) ; V_49 ++ ) {
V_8 = & V_4 -> V_10 [ V_49 ] ;
F_7 ( & V_8 -> V_14 ) ;
V_8 -> V_84 = V_80 ;
F_25 ( & V_8 -> V_14 ) ;
}
F_25 ( & V_4 -> V_17 . V_14 ) ;
return 0 ;
}
static long F_76 ( struct V_55 * V_85 , unsigned int V_86 ,
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
if ( F_77 ( & V_3 , V_88 , sizeof( V_3 ) ) )
return - V_52 ;
return F_73 ( V_4 , V_3 ) ;
case V_92 :
if ( F_77 ( & V_89 , V_88 , sizeof( V_89 ) ) )
return - V_52 ;
if ( V_89 )
return F_47 ( V_4 ) ;
else
return F_51 ( V_4 ) ;
case V_93 :
V_80 = V_81 ;
if ( F_78 ( V_88 , & V_80 , sizeof( V_80 ) ) )
return - V_52 ;
return 0 ;
case V_94 :
if ( F_77 ( & V_80 , V_88 , sizeof( V_80 ) ) )
return - V_52 ;
return F_74 ( V_4 , V_80 ) ;
default:
F_7 ( & V_4 -> V_17 . V_14 ) ;
V_90 = F_79 ( & V_4 -> V_17 , V_86 , V_88 ) ;
if ( V_90 == - V_95 )
V_90 = F_80 ( & V_4 -> V_17 , V_86 , V_88 ) ;
else
F_62 ( V_4 ) ;
F_25 ( & V_4 -> V_17 . V_14 ) ;
return V_90 ;
}
}
static int T_5 F_81 ( void )
{
int V_50 ;
V_50 = F_82 ( & V_96 . V_97 ) ;
if ( V_50 < 0 )
return V_50 ;
return F_83 ( & V_98 ) ;
}
static void T_6 F_84 ( void )
{
F_85 ( & V_98 ) ;
F_86 () ;
}
