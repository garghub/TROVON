static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( V_4 , L_1 , V_2 ,
F_4 ( V_6 -> V_7 ) ) ;
switch ( V_2 ) {
case V_8 :
F_5 ( V_4 ) ;
break;
case V_9 :
if ( ! F_4 ( V_6 -> V_7 ) )
return;
F_6 ( V_4 ) ;
break;
default:
F_7 ( V_4 , L_2 , V_2 ) ;
}
}
static void F_8 ( struct V_10 * V_7 , void * V_11 ,
void * V_1 , int V_12 )
{
struct V_3 * V_4 = V_11 ;
struct V_13 * V_14 ;
int V_15 ;
V_14 = V_1 ;
if ( ! V_14 )
return;
F_3 ( V_4 , L_3 , V_16 , V_12 ) ;
F_9 ( V_14 , V_12 ) ;
V_14 -> V_17 = F_10 ( V_14 , V_4 ) ;
V_14 -> V_18 = V_19 ;
if ( F_11 ( V_14 ) == V_20 ) {
V_4 -> V_21 . V_22 ++ ;
V_4 -> V_21 . V_23 ++ ;
} else {
V_4 -> V_21 . V_24 ++ ;
V_4 -> V_21 . V_25 += V_12 ;
}
V_14 = F_12 ( V_4 , V_4 -> V_26 + V_27 ) ;
if ( ! V_14 ) {
V_4 -> V_21 . V_22 ++ ;
V_4 -> V_21 . V_28 ++ ;
return;
}
V_15 = F_13 ( V_7 , V_14 , V_14 -> V_1 , V_4 -> V_26 + V_27 ) ;
if ( V_15 ) {
F_14 ( V_14 ) ;
V_4 -> V_21 . V_22 ++ ;
V_4 -> V_21 . V_29 ++ ;
}
}
static void F_15 ( struct V_10 * V_7 , void * V_11 ,
void * V_1 , int V_12 )
{
struct V_3 * V_4 = V_11 ;
struct V_13 * V_14 ;
V_14 = V_1 ;
if ( ! V_14 || ! V_4 )
return;
if ( V_12 > 0 ) {
V_4 -> V_21 . V_30 ++ ;
V_4 -> V_21 . V_31 += V_14 -> V_12 ;
} else {
V_4 -> V_21 . V_32 ++ ;
V_4 -> V_21 . V_33 ++ ;
}
F_14 ( V_14 ) ;
}
static T_1 F_16 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_15 ;
F_3 ( V_4 , L_4 , V_16 , V_14 -> V_12 ) ;
V_15 = F_17 ( V_6 -> V_7 , V_14 , V_14 -> V_1 , V_14 -> V_12 ) ;
if ( V_15 )
goto V_34;
return V_35 ;
V_34:
V_4 -> V_21 . V_36 ++ ;
V_4 -> V_21 . V_32 ++ ;
return V_37 ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_13 * V_14 ;
int V_15 , V_38 , V_12 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_14 = F_12 ( V_4 , V_4 -> V_26 + V_27 ) ;
if ( ! V_14 ) {
V_15 = - V_40 ;
goto V_34;
}
V_15 = F_13 ( V_6 -> V_7 , V_14 , V_14 -> V_1 ,
V_4 -> V_26 + V_27 ) ;
if ( V_15 == - V_41 ) {
F_14 ( V_14 ) ;
goto V_34;
}
}
F_5 ( V_4 ) ;
F_19 ( V_6 -> V_7 ) ;
return 0 ;
V_34:
while ( ( V_14 = F_20 ( V_6 -> V_7 , & V_12 ) ) )
F_14 ( V_14 ) ;
return V_15 ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_13 * V_14 ;
int V_12 ;
F_22 ( V_6 -> V_7 ) ;
while ( ( V_14 = F_20 ( V_6 -> V_7 , & V_12 ) ) )
F_14 ( V_14 ) ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 , int V_42 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_13 * V_14 ;
int V_12 , V_15 ;
if ( V_42 > F_24 ( V_6 -> V_7 ) - V_27 )
return - V_41 ;
if ( ! F_25 ( V_4 ) ) {
V_4 -> V_26 = V_42 ;
return 0 ;
}
F_22 ( V_6 -> V_7 ) ;
if ( V_4 -> V_26 < V_42 ) {
int V_38 ;
for ( V_38 = 0 ; ( V_14 = F_20 ( V_6 -> V_7 , & V_12 ) ) ; V_38 ++ )
F_14 ( V_14 ) ;
for (; V_38 ; V_38 -- ) {
V_14 = F_12 ( V_4 , V_42 + V_27 ) ;
if ( ! V_14 ) {
V_15 = - V_40 ;
goto V_34;
}
V_15 = F_13 ( V_6 -> V_7 , V_14 , V_14 -> V_1 ,
V_42 + V_27 ) ;
if ( V_15 ) {
F_14 ( V_14 ) ;
goto V_34;
}
}
}
V_4 -> V_26 = V_42 ;
F_19 ( V_6 -> V_7 ) ;
return 0 ;
V_34:
F_22 ( V_6 -> V_7 ) ;
while ( ( V_14 = F_20 ( V_6 -> V_7 , & V_12 ) ) )
F_14 ( V_14 ) ;
F_26 ( V_4 , L_5 ) ;
return V_15 ;
}
static void F_27 ( struct V_3 * V_4 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_28 ( V_44 -> V_45 , V_46 , sizeof( V_44 -> V_45 ) ) ;
F_28 ( V_44 -> V_47 , V_48 , sizeof( V_44 -> V_47 ) ) ;
F_28 ( V_44 -> V_49 , F_29 ( V_6 -> V_50 ) , sizeof( V_44 -> V_49 ) ) ;
}
static int F_30 ( struct V_3 * V_6 , struct V_51 * V_52 )
{
V_52 -> V_53 = V_54 ;
V_52 -> V_55 = V_56 ;
F_31 ( V_52 , V_57 ) ;
V_52 -> V_58 = V_59 ;
V_52 -> V_60 = V_61 ;
V_52 -> V_62 = 0 ;
V_52 -> V_63 = V_64 ;
V_52 -> V_65 = V_66 ;
V_52 -> V_67 = 0 ;
V_52 -> V_68 = 0 ;
return 0 ;
}
static int F_32 ( struct V_69 * V_50 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_15 ;
V_4 = F_33 ( sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return - V_40 ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_4 = V_4 ;
V_6 -> V_50 = V_50 ;
F_34 ( ! V_6 -> V_50 ) ;
V_4 -> V_70 = V_71 ;
V_4 -> V_72 |= V_73 ;
V_4 -> V_74 = V_4 -> V_70 ;
V_4 -> V_75 = F_35 ( V_76 ) ;
F_36 ( V_4 -> V_77 ) ;
memcpy ( V_4 -> V_78 , V_4 -> V_77 , V_4 -> V_79 ) ;
V_4 -> V_80 = & V_81 ;
V_4 -> V_82 = & V_83 ;
V_6 -> V_7 = F_37 ( V_4 , V_50 , & V_84 ) ;
if ( ! V_6 -> V_7 ) {
V_15 = - V_85 ;
goto V_34;
}
V_4 -> V_26 = F_24 ( V_6 -> V_7 ) - V_27 ;
V_15 = F_38 ( V_4 ) ;
if ( V_15 )
goto V_86;
F_39 ( & V_6 -> V_87 , & V_88 ) ;
F_40 ( & V_50 -> V_6 , L_6 , V_4 -> V_89 ) ;
return 0 ;
V_86:
F_41 ( V_6 -> V_7 ) ;
V_34:
F_42 ( V_4 ) ;
return V_15 ;
}
static void F_43 ( struct V_69 * V_50 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
bool V_90 = false ;
F_44 (dev, &dev_list, list) {
if ( V_6 -> V_50 == V_50 ) {
V_90 = true ;
break;
}
}
if ( ! V_90 )
return;
F_45 ( & V_6 -> V_87 ) ;
V_4 = V_6 -> V_4 ;
F_46 ( V_4 ) ;
F_41 ( V_6 -> V_7 ) ;
F_42 ( V_4 ) ;
}
static int T_2 F_47 ( void )
{
int V_15 ;
V_15 = F_48 ( V_46 ) ;
if ( V_15 )
return V_15 ;
return F_49 ( & V_91 ) ;
}
static void T_3 F_50 ( void )
{
F_51 ( & V_91 ) ;
F_52 ( V_46 ) ;
}
