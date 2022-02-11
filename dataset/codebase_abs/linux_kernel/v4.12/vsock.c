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
F_25 ( V_19 ) ;
F_18 ( V_19 ) ;
}
if ( V_12 )
F_26 ( & V_4 -> V_17 , V_8 ) ;
V_16:
F_27 ( & V_8 -> V_14 ) ;
if ( V_13 )
F_28 ( & V_9 -> V_36 ) ;
}
static void F_29 ( struct V_37 * V_38 )
{
struct V_7 * V_8 ;
struct V_2 * V_4 ;
V_4 = F_30 ( V_38 , struct V_2 , V_39 ) ;
V_8 = & V_4 -> V_10 [ V_40 ] ;
F_7 ( V_4 , V_8 ) ;
}
static int
F_31 ( struct V_18 * V_19 )
{
struct V_2 * V_4 ;
int V_23 = V_19 -> V_23 ;
V_4 = F_4 ( F_32 ( V_19 -> V_31 . V_41 ) ) ;
if ( ! V_4 ) {
F_18 ( V_19 ) ;
return - V_42 ;
}
if ( V_19 -> V_33 )
F_33 ( & V_4 -> V_35 ) ;
F_5 ( & V_4 -> V_25 ) ;
F_34 ( & V_19 -> V_27 , & V_4 -> V_26 ) ;
F_6 ( & V_4 -> V_25 ) ;
F_35 ( & V_4 -> V_17 , & V_4 -> V_39 ) ;
return V_23 ;
}
static int
F_36 ( struct V_43 * V_44 )
{
struct V_2 * V_4 ;
struct V_18 * V_19 , * V_45 ;
int V_46 = 0 ;
F_37 ( V_47 ) ;
V_4 = F_4 ( V_44 -> V_48 . V_49 ) ;
if ( ! V_4 )
return - V_42 ;
F_5 ( & V_4 -> V_25 ) ;
F_38 (pkt, n, &vsock->send_pkt_list, list) {
if ( V_19 -> V_44 != V_44 )
continue;
F_39 ( & V_19 -> V_27 , & V_47 ) ;
}
F_6 ( & V_4 -> V_25 ) ;
F_38 (pkt, n, &freeme, list) {
if ( V_19 -> V_33 )
V_46 ++ ;
F_40 ( & V_19 -> V_27 ) ;
F_18 ( V_19 ) ;
}
if ( V_46 ) {
struct V_7 * V_9 = & V_4 -> V_10 [ V_11 ] ;
int V_50 ;
V_50 = F_41 ( V_46 , & V_4 -> V_35 ) ;
if ( V_50 + V_46 >= V_9 -> V_29 && V_50 < V_9 -> V_29 )
F_28 ( & V_9 -> V_36 ) ;
}
return 0 ;
}
static struct V_18 *
F_42 ( struct V_7 * V_8 ,
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
V_19 = F_43 ( sizeof( * V_19 ) , V_51 ) ;
if ( ! V_19 )
return NULL ;
V_23 = F_20 ( V_8 -> V_28 , V_16 ) ;
F_21 ( & V_20 , V_52 , V_8 -> V_28 , V_16 , V_23 ) ;
V_22 = F_44 ( & V_19 -> V_31 , sizeof( V_19 -> V_31 ) , & V_20 ) ;
if ( V_22 != sizeof( V_19 -> V_31 ) ) {
F_19 ( V_8 , L_5 ,
sizeof( V_19 -> V_31 ) , V_22 ) ;
F_45 ( V_19 ) ;
return NULL ;
}
if ( F_46 ( V_19 -> V_31 . type ) == V_53 )
V_19 -> V_23 = F_47 ( V_19 -> V_31 . V_23 ) ;
if ( ! V_19 -> V_23 )
return V_19 ;
if ( V_19 -> V_23 > V_54 ) {
F_45 ( V_19 ) ;
return NULL ;
}
V_19 -> V_32 = F_48 ( V_19 -> V_23 , V_51 ) ;
if ( ! V_19 -> V_32 ) {
F_45 ( V_19 ) ;
return NULL ;
}
V_22 = F_44 ( V_19 -> V_32 , V_19 -> V_23 , & V_20 ) ;
if ( V_22 != V_19 -> V_23 ) {
F_19 ( V_8 , L_6 ,
V_19 -> V_23 , V_22 ) ;
F_18 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
static bool F_49 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = & V_4 -> V_10 [ V_11 ] ;
int V_34 ;
F_50 () ;
V_34 = F_51 ( & V_4 -> V_35 ) ;
return V_34 < V_8 -> V_29 ;
}
static void F_52 ( struct V_37 * V_38 )
{
struct V_7 * V_8 = F_30 ( V_38 , struct V_7 ,
V_36 . V_38 ) ;
struct V_2 * V_4 = F_30 ( V_8 -> V_17 , struct V_2 ,
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
if ( ! F_49 ( V_4 ) ) {
goto V_55;
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
V_19 = F_42 ( V_8 , V_16 , V_21 ) ;
if ( ! V_19 ) {
F_19 ( V_8 , L_7 ) ;
continue;
}
V_23 = V_19 -> V_23 ;
F_25 ( V_19 ) ;
if ( F_32 ( V_19 -> V_31 . V_56 ) == V_4 -> V_3 )
F_53 ( V_19 ) ;
else
F_18 ( V_19 ) ;
F_23 ( V_8 , V_24 , sizeof( V_19 -> V_31 ) + V_23 ) ;
V_12 = true ;
}
V_55:
if ( V_12 )
F_26 ( & V_4 -> V_17 , V_8 ) ;
V_16:
F_27 ( & V_8 -> V_14 ) ;
}
static void F_54 ( struct V_37 * V_38 )
{
struct V_7 * V_8 = F_30 ( V_38 , struct V_7 ,
V_36 . V_38 ) ;
struct V_2 * V_4 = F_30 ( V_8 -> V_17 , struct V_2 ,
V_17 ) ;
F_7 ( V_4 , V_8 ) ;
}
static int F_55 ( struct V_2 * V_4 )
{
struct V_7 * V_8 ;
T_2 V_57 ;
int V_58 ;
F_8 ( & V_4 -> V_17 . V_14 ) ;
V_58 = F_56 ( & V_4 -> V_17 ) ;
if ( V_58 )
goto V_59;
for ( V_57 = 0 ; V_57 < F_15 ( V_4 -> V_10 ) ; V_57 ++ ) {
V_8 = & V_4 -> V_10 [ V_57 ] ;
F_8 ( & V_8 -> V_14 ) ;
if ( ! F_57 ( V_8 ) ) {
V_58 = - V_60 ;
goto V_61;
}
if ( ! V_8 -> V_15 ) {
V_8 -> V_15 = V_4 ;
V_58 = F_58 ( V_8 ) ;
if ( V_58 )
goto V_61;
}
F_27 ( & V_8 -> V_14 ) ;
}
F_27 ( & V_4 -> V_17 . V_14 ) ;
return 0 ;
V_61:
V_8 -> V_15 = NULL ;
F_27 ( & V_8 -> V_14 ) ;
for ( V_57 = 0 ; V_57 < F_15 ( V_4 -> V_10 ) ; V_57 ++ ) {
V_8 = & V_4 -> V_10 [ V_57 ] ;
F_8 ( & V_8 -> V_14 ) ;
V_8 -> V_15 = NULL ;
F_27 ( & V_8 -> V_14 ) ;
}
V_59:
F_27 ( & V_4 -> V_17 . V_14 ) ;
return V_58 ;
}
static int F_59 ( struct V_2 * V_4 )
{
T_2 V_57 ;
int V_58 ;
F_8 ( & V_4 -> V_17 . V_14 ) ;
V_58 = F_56 ( & V_4 -> V_17 ) ;
if ( V_58 )
goto V_59;
for ( V_57 = 0 ; V_57 < F_15 ( V_4 -> V_10 ) ; V_57 ++ ) {
struct V_7 * V_8 = & V_4 -> V_10 [ V_57 ] ;
F_8 ( & V_8 -> V_14 ) ;
V_8 -> V_15 = NULL ;
F_27 ( & V_8 -> V_14 ) ;
}
V_59:
F_27 ( & V_4 -> V_17 . V_14 ) ;
return V_58 ;
}
static void F_60 ( struct V_2 * V_4 )
{
F_61 ( V_4 ) ;
}
static int F_62 ( struct V_62 * V_62 , struct V_63 * V_63 )
{
struct V_7 * * V_10 ;
struct V_2 * V_4 ;
int V_58 ;
V_4 = F_63 ( sizeof( * V_4 ) , V_51 | V_64 ) ;
if ( ! V_4 )
return - V_65 ;
V_10 = F_64 ( F_15 ( V_4 -> V_10 ) , sizeof( * V_10 ) , V_51 ) ;
if ( ! V_10 ) {
V_58 = - V_65 ;
goto V_16;
}
F_65 ( & V_4 -> V_35 , 0 ) ;
V_10 [ V_11 ] = & V_4 -> V_10 [ V_11 ] ;
V_10 [ V_40 ] = & V_4 -> V_10 [ V_40 ] ;
V_4 -> V_10 [ V_11 ] . V_66 = F_52 ;
V_4 -> V_10 [ V_40 ] . V_66 = F_54 ;
F_66 ( & V_4 -> V_17 , V_10 , F_15 ( V_4 -> V_10 ) ) ;
V_63 -> V_15 = V_4 ;
F_67 ( & V_4 -> V_25 ) ;
F_68 ( & V_4 -> V_26 ) ;
F_69 ( & V_4 -> V_39 , F_29 ) ;
F_5 ( & V_6 ) ;
F_34 ( & V_4 -> V_27 , & V_67 ) ;
F_6 ( & V_6 ) ;
return 0 ;
V_16:
F_60 ( V_4 ) ;
return V_58 ;
}
static void F_70 ( struct V_2 * V_4 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < F_15 ( V_4 -> V_10 ) ; V_57 ++ )
if ( V_4 -> V_10 [ V_57 ] . V_66 )
F_71 ( & V_4 -> V_10 [ V_57 ] . V_36 ) ;
F_72 ( & V_4 -> V_17 , & V_4 -> V_39 ) ;
}
static void F_73 ( struct V_68 * V_69 )
{
struct V_43 * V_44 = F_74 ( V_69 ) ;
if ( ! F_4 ( V_44 -> V_48 . V_49 ) ) {
F_75 ( V_69 , V_70 ) ;
V_44 -> V_71 = V_72 ;
V_69 -> V_73 = V_74 ;
V_69 -> V_75 = V_76 ;
V_69 -> V_77 ( V_69 ) ;
}
}
static int F_76 ( struct V_62 * V_62 , struct V_63 * V_63 )
{
struct V_2 * V_4 = V_63 -> V_15 ;
F_5 ( & V_6 ) ;
F_40 ( & V_4 -> V_27 ) ;
F_6 ( & V_6 ) ;
F_77 ( F_73 ) ;
F_59 ( V_4 ) ;
F_70 ( V_4 ) ;
F_78 ( & V_4 -> V_17 ) ;
F_5 ( & V_4 -> V_25 ) ;
while ( ! F_10 ( & V_4 -> V_26 ) ) {
struct V_18 * V_19 ;
V_19 = F_12 ( & V_4 -> V_26 ,
struct V_18 , V_27 ) ;
F_13 ( & V_19 -> V_27 ) ;
F_18 ( V_19 ) ;
}
F_6 ( & V_4 -> V_25 ) ;
F_79 ( & V_4 -> V_17 , false ) ;
F_45 ( V_4 -> V_17 . V_10 ) ;
F_60 ( V_4 ) ;
return 0 ;
}
static int F_80 ( struct V_2 * V_4 , T_3 V_3 )
{
struct V_2 * V_78 ;
if ( V_3 <= V_79 ||
V_3 == V_80 )
return - V_81 ;
if ( V_3 > V_80 )
return - V_81 ;
F_5 ( & V_6 ) ;
V_78 = F_2 ( V_3 ) ;
if ( V_78 && V_78 != V_4 ) {
F_6 ( & V_6 ) ;
return - V_82 ;
}
V_4 -> V_3 = V_3 ;
F_6 ( & V_6 ) ;
return 0 ;
}
static int F_81 ( struct V_2 * V_4 , T_3 V_83 )
{
struct V_7 * V_8 ;
int V_57 ;
if ( V_83 & ~ V_84 )
return - V_85 ;
F_8 ( & V_4 -> V_17 . V_14 ) ;
if ( ( V_83 & ( 1 << V_86 ) ) &&
! F_82 ( & V_4 -> V_17 ) ) {
F_27 ( & V_4 -> V_17 . V_14 ) ;
return - V_60 ;
}
for ( V_57 = 0 ; V_57 < F_15 ( V_4 -> V_10 ) ; V_57 ++ ) {
V_8 = & V_4 -> V_10 [ V_57 ] ;
F_8 ( & V_8 -> V_14 ) ;
V_8 -> V_87 = V_83 ;
F_27 ( & V_8 -> V_14 ) ;
}
F_27 ( & V_4 -> V_17 . V_14 ) ;
return 0 ;
}
static long F_83 ( struct V_63 * V_88 , unsigned int V_89 ,
unsigned long V_90 )
{
struct V_2 * V_4 = V_88 -> V_15 ;
void T_4 * V_91 = ( void T_4 * ) V_90 ;
T_3 V_3 ;
T_3 V_83 ;
int V_92 ;
int V_93 ;
switch ( V_89 ) {
case V_94 :
if ( F_84 ( & V_3 , V_91 , sizeof( V_3 ) ) )
return - V_60 ;
return F_80 ( V_4 , V_3 ) ;
case V_95 :
if ( F_84 ( & V_92 , V_91 , sizeof( V_92 ) ) )
return - V_60 ;
if ( V_92 )
return F_55 ( V_4 ) ;
else
return F_59 ( V_4 ) ;
case V_96 :
V_83 = V_84 ;
if ( F_85 ( V_91 , & V_83 , sizeof( V_83 ) ) )
return - V_60 ;
return 0 ;
case V_97 :
if ( F_84 ( & V_83 , V_91 , sizeof( V_83 ) ) )
return - V_60 ;
return F_81 ( V_4 , V_83 ) ;
default:
F_8 ( & V_4 -> V_17 . V_14 ) ;
V_93 = F_86 ( & V_4 -> V_17 , V_89 , V_91 ) ;
if ( V_93 == - V_98 )
V_93 = F_87 ( & V_4 -> V_17 , V_89 , V_91 ) ;
else
F_70 ( V_4 ) ;
F_27 ( & V_4 -> V_17 . V_14 ) ;
return V_93 ;
}
}
static int T_5 F_88 ( void )
{
int V_58 ;
V_58 = F_89 ( & V_99 . V_100 ) ;
if ( V_58 < 0 )
return V_58 ;
return F_90 ( & V_101 ) ;
}
static void T_6 F_91 ( void )
{
F_92 ( & V_101 ) ;
F_93 () ;
}
