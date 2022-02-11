static T_1 F_1 ( struct V_1 * V_2 , union V_3 * V_4 )
{
union V_3 * V_5 , * V_6 ;
int V_7 ;
if ( V_4 -> type != V_8 ||
V_4 -> V_9 . V_10 < 2 ||
V_4 -> V_9 . V_11 [ 0 ] . type != V_12 ||
V_4 -> V_9 . V_11 [ 0 ] . integer . V_13 != 0 ) {
F_2 ( V_2 ,
L_1 ) ;
return 0 ;
}
for ( V_7 = 1 ; V_7 < V_4 -> V_9 . V_10 ; V_7 ++ ) {
union V_3 * V_14 ;
V_5 = & V_4 -> V_9 . V_11 [ V_7 ] ;
if ( V_5 -> type != V_8 ||
V_5 -> V_9 . V_10 < 2 ||
V_5 -> V_9 . V_11 [ 0 ] . type != V_12 ||
V_5 -> V_9 . V_11 [ 1 ] . type != V_12 )
continue;
V_14 = & V_5 -> V_9 . V_11 [ 0 ] ;
if ( V_14 -> integer . V_13 == V_15 )
break;
V_5 = NULL ;
}
if ( ! V_5 ) {
F_2 ( V_2 ,
L_2 ) ;
return 0 ;
}
V_6 = & V_5 -> V_9 . V_11 [ 1 ] ;
return V_6 -> integer . V_13 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
T_2 V_18 ;
T_2 V_19 ;
struct V_20 V_4 = { V_21 , NULL } ;
T_3 V_22 ;
V_18 = F_4 ( & V_17 -> V_23 ) ;
if ( ! V_18 ) {
F_2 ( V_2 ,
L_3 ) ;
return;
}
V_22 = F_5 ( V_18 , ( V_24 ) V_25 ,
& V_19 ) ;
if ( F_6 ( V_22 ) ) {
F_2 ( V_2 , L_4 ) ;
return;
}
V_22 = F_7 ( V_19 , NULL , NULL , & V_4 ) ;
if ( F_6 ( V_22 ) ) {
F_8 ( V_2 , L_5 , V_22 ) ;
return;
}
V_2 -> V_6 = F_1 ( V_2 , V_4 . V_26 ) ;
F_2 ( V_2 , L_6 ,
V_2 -> V_6 ) ;
F_9 ( V_4 . V_26 ) ;
}
static void F_3 ( struct V_1 * V_2 , struct V_16 * V_17 ) {}
static int F_10 ( struct V_16 * V_17 , const struct V_27 * V_28 )
{
const struct V_29 * V_30 = (struct V_29 * ) ( V_28 -> V_31 ) ;
const struct V_29 * T_4 V_32 = NULL ;
struct V_1 * V_1 ;
int V_33 ;
V_1 = F_11 ( V_17 , V_28 , V_30 ) ;
if ( F_12 ( V_1 ) )
return F_13 ( V_1 ) ;
#if F_14 ( V_34 )
if ( V_30 == & V_35 )
T_4 = & V_36 ;
else if ( V_30 == & V_37 )
T_4 = & V_38 ;
else if ( V_30 == & V_39 )
T_4 = & V_40 ;
if ( T_4 &&
( V_1 -> V_41 & V_42 ) == V_43 ) {
V_30 = T_4 ;
V_1 -> V_30 = T_4 ;
}
if ( V_1 -> V_30 -> V_44 ) {
if ( V_30 == & V_45 &&
V_1 -> V_46 == V_47 ) {
V_30 = & V_48 ;
V_1 -> V_30 = V_30 ;
}
if ( V_30 == & V_49 &&
V_1 -> V_46 == V_50 ) {
V_30 = & V_51 ;
V_1 -> V_30 = V_30 ;
}
}
#endif
F_15 ( V_17 , V_1 ) ;
V_1 -> V_52 = F_16 ( V_1 ) ;
if ( F_12 ( V_1 -> V_52 ) ) {
V_33 = F_13 ( V_1 -> V_52 ) ;
goto V_53;
}
F_3 ( V_1 , V_17 ) ;
V_33 = F_17 ( V_1 ) ;
if ( V_33 )
goto V_54;
if ( V_1 -> V_55 != V_56 ) {
F_18 ( & V_17 -> V_23 ) ;
F_19 ( & V_17 -> V_23 ,
V_57 . V_58 ) ;
F_20 ( & V_17 -> V_23 ) ;
F_21 ( & V_17 -> V_23 ) ;
}
return 0 ;
V_54:
F_22 ( V_1 -> V_52 ) ;
V_53:
F_23 ( V_1 ) ;
return V_33 ;
}
static void F_24 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_25 ( V_17 ) ;
if ( V_2 -> V_55 != V_56 ) {
F_26 ( V_2 -> V_23 ) ;
}
F_22 ( V_2 -> V_52 ) ;
F_23 ( V_2 ) ;
}
static int F_27 ( struct V_59 * V_59 )
{
return 0 ;
}
static int F_28 ( struct V_59 * V_59 )
{
struct V_16 * V_17 = F_29 ( V_59 ) ;
struct V_1 * V_2 = F_25 ( V_17 ) ;
struct V_60 * V_61 = F_30 ( V_2 ) ;
bool V_62 ;
F_31 ( V_17 , V_63 , 0x00 ) ;
if ( ! V_2 -> V_64 )
return 0 ;
F_32 ( & V_61 -> V_65 ) ;
F_33 ( V_2 ) ;
V_62 = F_34 ( V_2 ) ;
F_35 ( V_2 , V_62 ) ;
F_36 ( & V_61 -> V_65 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_30 ( V_2 ) ;
int V_33 ;
if ( F_38 ( V_66 , & V_2 -> V_22 ) )
return 0 ;
F_39 ( V_67 , & V_2 -> V_22 ) ;
V_33 = F_40 ( V_2 -> V_64 ) ;
if ( V_33 == 1 ) {
F_41 ( V_2 , L_7 ) ;
F_42 ( V_67 , & V_2 -> V_22 ) ;
return - V_68 ;
}
if ( V_33 )
goto V_69;
V_33 = F_43 ( V_61 -> V_70 ,
F_38 ( V_71 , & V_2 -> V_22 ) ,
F_44 ( V_72 ) ) ;
if ( ! V_33 ) {
F_8 ( V_2 , L_8 ) ;
V_33 = - V_73 ;
goto V_69;
}
F_42 ( V_67 , & V_2 -> V_22 ) ;
return 0 ;
V_69:
F_42 ( V_67 , & V_2 -> V_22 ) ;
F_45 ( V_2 ) ;
return V_33 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = F_30 ( V_2 ) ;
int V_33 ;
if ( ! F_38 ( V_71 , & V_2 -> V_22 ) )
return 0 ;
V_33 = F_47 ( V_2 -> V_64 ) ;
if ( V_33 )
goto V_69;
V_33 = F_43 ( V_61 -> V_70 ,
! F_38 ( V_71 , & V_2 -> V_22 ) ,
F_44 ( V_72 ) ) ;
if ( ! V_33 ) {
F_8 ( V_2 , L_9 ) ;
V_33 = - V_73 ;
goto V_69;
}
return 0 ;
V_69:
F_42 ( V_71 , & V_2 -> V_22 ) ;
F_45 ( V_2 ) ;
return V_33 ;
}
static int F_48 ( struct V_59 * V_59 )
{
struct V_16 * V_17 = F_29 ( V_59 ) ;
struct V_1 * V_2 = F_25 ( V_17 ) ;
int V_33 ;
F_41 ( V_2 , L_10 ) ;
if ( F_38 ( V_74 , & V_2 -> V_22 ) ) {
V_33 = F_37 ( V_2 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_2 -> V_75 = V_76 ;
F_49 ( V_2 , false , false ) ;
return 0 ;
}
static int F_50 ( struct V_59 * V_59 )
{
struct V_16 * V_17 = F_29 ( V_59 ) ;
struct V_1 * V_2 = F_25 ( V_17 ) ;
enum V_77 V_78 ;
F_41 ( V_2 , L_11 ) ;
F_51 ( V_2 , & V_78 , false , false ) ;
if ( F_38 ( V_74 , & V_2 -> V_22 ) )
return F_46 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_59 * V_59 )
{
struct V_16 * V_17 = F_29 ( V_59 ) ;
struct V_1 * V_2 = F_25 ( V_17 ) ;
F_41 ( V_2 , L_12 ) ;
V_2 -> V_79 = true ;
F_53 ( V_59 ) ;
return 0 ;
}
static void F_54 ( struct V_59 * V_59 )
{
struct V_16 * V_17 = F_29 ( V_59 ) ;
struct V_1 * V_2 = F_25 ( V_17 ) ;
F_41 ( V_2 , L_13 ) ;
V_2 -> V_79 = false ;
}
int T_5 F_55 ( void )
{
int V_33 ;
V_33 = F_56 ( & V_80 ) ;
if ( V_33 )
F_57 ( L_14 ) ;
return V_33 ;
}
void F_58 ( void )
{
F_59 ( & V_80 ) ;
}
