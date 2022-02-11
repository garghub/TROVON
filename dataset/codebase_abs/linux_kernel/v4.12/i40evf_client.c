void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 ;
if ( ! V_2 )
return;
V_6 = V_2 -> V_7 -> V_6 ;
if ( ! V_6 || ! V_6 -> V_8 || ! V_6 -> V_8 -> V_9 ||
! V_6 -> V_8 -> V_9 -> V_10 ) {
F_2 ( & V_2 -> V_7 -> V_11 -> V_12 ,
L_1 ) ;
return;
}
V_6 -> V_8 -> V_9 -> V_10 ( & V_6 -> V_13 , V_6 -> V_8 ,
V_3 , V_4 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_14 V_15 ;
if ( ! V_2 )
return;
V_6 = V_2 -> V_7 -> V_6 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_16 = V_2 -> V_17 -> V_16 ;
V_15 . V_18 = V_2 -> V_7 -> V_18 ;
V_15 . V_19 . V_20 [ 0 ] . V_21 = V_2 -> V_21 ;
if ( ! V_6 || ! V_6 -> V_8 || ! V_6 -> V_8 -> V_9 ||
! V_6 -> V_8 -> V_9 -> V_22 ) {
F_2 ( & V_2 -> V_7 -> V_11 -> V_12 ,
L_2 ) ;
return;
}
V_6 -> V_8 -> V_9 -> V_22 ( & V_6 -> V_13 , V_6 -> V_8 ,
& V_15 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_7 ;
struct V_5 * V_6 = V_24 -> V_6 ;
int V_25 ;
if ( ! V_6 || ! V_6 -> V_8 || ! V_6 -> V_8 -> V_9 ||
! V_6 -> V_8 -> V_9 -> V_26 ) {
F_2 ( & V_2 -> V_7 -> V_11 -> V_12 ,
L_3 ) ;
return;
}
if ( ! ( F_5 ( V_27 , & V_6 -> V_28 ) ) ) {
V_25 = V_6 -> V_8 -> V_9 -> V_26 ( & V_6 -> V_13 , V_6 -> V_8 ) ;
if ( ! V_25 )
F_6 ( V_27 , & V_6 -> V_28 ) ;
}
}
static int F_7 ( struct V_29 * V_30 )
{
struct V_23 * V_24 = V_30 -> V_31 ;
T_3 V_32 ;
if ( V_24 -> V_33 )
return - V_34 ;
V_32 = F_8 ( & V_24 -> V_35 ,
V_36 ,
V_37 , NULL , 0 , NULL ) ;
if ( V_32 )
F_9 ( & V_24 -> V_11 -> V_12 ,
L_4 ,
V_32 , V_24 -> V_35 . V_38 . V_39 ) ;
return V_32 ;
}
void F_10 ( struct V_1 * V_2 , bool V_40 )
{
struct V_23 * V_24 = V_2 -> V_7 ;
struct V_5 * V_6 = V_24 -> V_6 ;
if ( ! V_6 || ! V_6 -> V_8 || ! V_6 -> V_8 -> V_9 ||
! V_6 -> V_8 -> V_9 -> V_41 ) {
F_2 ( & V_2 -> V_7 -> V_11 -> V_12 ,
L_5 ) ;
return;
}
V_6 -> V_8 -> V_9 -> V_41 ( & V_6 -> V_13 , V_6 -> V_8 , V_40 ) ;
F_7 ( & V_6 -> V_13 ) ;
F_11 ( V_27 , & V_6 -> V_28 ) ;
}
static struct V_5 *
F_12 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = NULL ;
struct V_42 * V_43 = NULL ;
struct V_1 * V_2 = & V_24 -> V_2 ;
int V_44 ;
if ( ! V_45 )
goto V_46;
if ( V_24 -> V_6 ) {
V_6 = V_24 -> V_6 ;
goto V_46;
}
V_6 = F_13 ( sizeof( * V_6 ) , V_47 ) ;
if ( ! V_6 )
goto V_46;
V_6 -> V_13 . V_31 = ( void * ) V_24 ;
V_6 -> V_13 . V_17 = V_2 -> V_17 ;
V_6 -> V_13 . V_48 = V_24 -> V_11 ;
V_6 -> V_13 . V_49 = 0 ;
V_6 -> V_13 . V_50 = V_51 ;
V_6 -> V_13 . V_52 = V_24 -> V_35 . V_52 ;
V_6 -> V_13 . V_9 = & V_53 ;
V_6 -> V_13 . V_54 . V_55 = V_56 ;
V_6 -> V_13 . V_54 . V_57 = V_58 ;
V_6 -> V_13 . V_54 . V_59 = V_60 ;
F_6 ( V_61 , & V_6 -> V_28 ) ;
V_6 -> V_13 . V_62 = V_24 -> V_63 ;
V_6 -> V_13 . V_64 =
& V_24 -> V_64 [ V_24 -> V_65 ] ;
for ( V_44 = 0 ; V_44 < V_66 ; V_44 ++ ) {
V_6 -> V_13 . V_15 . V_19 . V_20 [ V_44 ] . V_67 = 0 ;
V_6 -> V_13 . V_15 . V_19 . V_20 [ V_44 ] . V_21 =
V_2 -> V_21 ;
}
V_43 = F_14 ( & V_6 -> V_13 . V_17 -> V_68 . V_69 ,
struct V_42 , V_69 ) ;
if ( V_43 )
F_15 ( V_6 -> V_13 . V_70 , V_43 -> V_71 ) ;
else
F_9 ( & V_24 -> V_11 -> V_12 , L_6 ) ;
V_6 -> V_8 = V_45 ;
V_24 -> V_6 = V_6 ;
V_46:
return V_6 ;
}
static
void F_16 ( struct V_23 * V_24 )
{
F_17 ( V_24 -> V_6 ) ;
V_24 -> V_6 = NULL ;
}
void F_18 ( struct V_23 * V_24 )
{
struct V_72 * V_8 = V_45 ;
struct V_5 * V_6 ;
int V_25 = 0 ;
if ( V_24 -> V_28 < V_73 )
return;
if ( ! V_8 )
return;
V_6 = F_12 ( V_24 ) ;
if ( ! V_6 )
return;
F_19 ( & V_24 -> V_11 -> V_12 , L_7 ,
V_8 -> V_74 ) ;
if ( ! F_5 ( V_27 , & V_6 -> V_28 ) ) {
if ( V_8 -> V_9 && V_8 -> V_9 -> V_26 )
V_25 = V_8 -> V_9 -> V_26 ( & V_6 -> V_13 , V_8 ) ;
if ( ! V_25 )
F_6 ( V_27 ,
& V_6 -> V_28 ) ;
else
F_16 ( V_24 ) ;
}
}
int F_20 ( struct V_23 * V_24 )
{
struct V_75 * V_30 ;
int V_25 = 0 ;
F_21 ( & V_76 ) ;
F_22 (ldev, &i40evf_devices, list) {
if ( V_30 -> V_31 == V_24 ) {
V_25 = - V_77 ;
goto V_46;
}
}
V_30 = F_13 ( sizeof( * V_30 ) , V_47 ) ;
if ( ! V_30 ) {
V_25 = - V_78 ;
goto V_46;
}
V_30 -> V_31 = V_24 ;
F_23 ( & V_30 -> V_69 ) ;
F_24 ( & V_30 -> V_69 , & V_79 ) ;
F_19 ( & V_24 -> V_11 -> V_12 , L_8 ,
V_24 -> V_35 . V_80 . V_81 , V_24 -> V_35 . V_80 . V_82 ,
V_24 -> V_35 . V_80 . V_83 ) ;
V_24 -> V_84 |= V_85 ;
V_46:
F_25 ( & V_76 ) ;
return V_25 ;
}
int F_26 ( struct V_23 * V_24 )
{
struct V_75 * V_30 , * V_86 ;
int V_25 = - V_87 ;
F_21 ( & V_76 ) ;
F_27 (ldev, tmp, &i40evf_devices, list) {
if ( V_30 -> V_31 == V_24 ) {
F_19 ( & V_24 -> V_11 -> V_12 ,
L_9 ,
V_24 -> V_35 . V_80 . V_81 , V_24 -> V_35 . V_80 . V_82 ,
V_24 -> V_35 . V_80 . V_83 ) ;
F_28 ( & V_30 -> V_69 ) ;
F_17 ( V_30 ) ;
V_25 = 0 ;
break;
}
}
F_25 ( & V_76 ) ;
return V_25 ;
}
static void F_29 ( struct V_72 * V_8 )
{
struct V_5 * V_6 ;
struct V_75 * V_30 ;
struct V_23 * V_24 ;
F_21 ( & V_76 ) ;
F_22 (ldev, &i40evf_devices, list) {
V_24 = V_30 -> V_31 ;
V_6 = V_24 -> V_6 ;
if ( ! V_6 )
continue;
if ( F_5 ( V_27 , & V_6 -> V_28 ) ) {
if ( V_8 -> V_9 && V_8 -> V_9 -> V_41 )
V_8 -> V_9 -> V_41 ( & V_6 -> V_13 , V_8 ,
false ) ;
F_7 ( & V_6 -> V_13 ) ;
F_11 ( V_27 , & V_6 -> V_28 ) ;
F_30 ( & V_24 -> V_11 -> V_12 ,
L_10 , V_8 -> V_74 ) ;
}
F_16 ( V_24 ) ;
F_19 ( & V_24 -> V_11 -> V_12 , L_11 ,
V_8 -> V_74 ) ;
}
F_25 ( & V_76 ) ;
}
static void F_31 ( struct V_72 * V_8 )
{
struct V_75 * V_30 ;
struct V_23 * V_24 ;
F_21 ( & V_76 ) ;
F_22 (ldev, &i40evf_devices, list) {
V_24 = V_30 -> V_31 ;
V_24 -> V_84 |= V_85 ;
}
F_25 ( & V_76 ) ;
}
static T_4 F_32 ( struct V_29 * V_30 ,
struct V_72 * V_8 ,
T_1 * V_3 , T_2 V_4 )
{
struct V_23 * V_24 = V_30 -> V_31 ;
T_3 V_32 ;
if ( V_24 -> V_33 )
return - V_34 ;
V_32 = F_8 ( & V_24 -> V_35 , V_88 ,
V_37 , V_3 , V_4 , NULL ) ;
if ( V_32 )
F_9 ( & V_24 -> V_11 -> V_12 , L_12 ,
V_32 , V_24 -> V_35 . V_38 . V_39 ) ;
return V_32 ;
}
static int F_33 ( struct V_29 * V_30 ,
struct V_72 * V_8 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 ;
struct V_23 * V_24 = V_30 -> V_31 ;
struct V_93 * V_94 ;
T_3 V_32 ;
T_4 V_95 , V_44 ;
T_4 V_96 ;
if ( V_24 -> V_33 )
return - V_34 ;
for ( V_44 = 0 ; V_44 < V_90 -> V_97 ; V_44 ++ ) {
V_94 = & V_90 -> V_94 [ V_44 ] ;
if ( ! V_94 )
continue;
V_95 = V_94 -> V_95 ;
if ( ( V_95 >=
( V_24 -> V_65 + V_24 -> V_63 ) ) ||
( V_95 < V_24 -> V_65 ) )
return - V_98 ;
}
V_92 = (struct V_91 * ) V_90 ;
V_96 = sizeof( struct V_91 ) +
( sizeof( struct V_99 ) *
( V_92 -> V_97 - 1 ) ) ;
V_24 -> V_100 |= F_34 ( V_101 ) ;
V_32 = F_8 ( & V_24 -> V_35 ,
V_101 ,
V_37 , ( T_1 * ) V_92 , V_96 , NULL ) ;
if ( V_32 ) {
F_9 ( & V_24 -> V_11 -> V_12 ,
L_13 ,
V_32 , V_24 -> V_35 . V_38 . V_39 ) ;
goto V_46;
}
V_32 = - V_102 ;
for ( V_44 = 0 ; V_44 < 5 ; V_44 ++ ) {
F_35 ( 100 ) ;
if ( ! ( V_24 -> V_100 &
F_34 ( V_101 ) ) ) {
V_32 = 0 ;
break;
}
}
V_46:
return V_32 ;
}
int F_36 ( struct V_72 * V_8 )
{
int V_25 = 0 ;
if ( ! V_8 ) {
V_25 = - V_103 ;
goto V_46;
}
if ( strlen ( V_8 -> V_74 ) == 0 ) {
F_37 ( L_14 ) ;
V_25 = - V_103 ;
goto V_46;
}
if ( V_45 ) {
F_37 ( L_15 ,
V_8 -> V_74 ) ;
V_25 = - V_77 ;
goto V_46;
}
if ( ( V_8 -> V_54 . V_55 != V_56 ) ||
( V_8 -> V_54 . V_57 != V_58 ) ) {
F_37 ( L_16 ,
V_8 -> V_74 ) ;
F_37 ( L_17 ,
V_8 -> V_54 . V_55 , V_8 -> V_54 . V_57 ,
V_8 -> V_54 . V_59 ,
V_104 ) ;
V_25 = - V_103 ;
goto V_46;
}
V_45 = V_8 ;
F_31 ( V_8 ) ;
F_37 ( L_18 ,
V_8 -> V_74 , V_25 ) ;
V_46:
return V_25 ;
}
int F_38 ( struct V_72 * V_8 )
{
int V_25 = 0 ;
F_29 ( V_8 ) ;
if ( V_45 != V_8 ) {
F_37 ( L_19 ,
V_8 -> V_74 ) ;
V_25 = - V_87 ;
goto V_46;
}
V_45 = NULL ;
F_37 ( L_20 , V_8 -> V_74 ) ;
V_46:
return V_25 ;
}
