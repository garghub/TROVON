static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( V_4 , L_1 , V_2 ,
F_4 ( V_6 -> V_7 ) ) ;
if ( V_2 ) {
if ( F_4 ( V_6 -> V_7 ) )
F_5 ( V_4 ) ;
} else {
F_6 ( V_4 ) ;
}
}
static void F_7 ( struct V_8 * V_7 , void * V_9 ,
void * V_1 , int V_10 )
{
struct V_3 * V_4 = V_9 ;
struct V_11 * V_12 ;
int V_13 ;
V_12 = V_1 ;
if ( ! V_12 )
return;
F_3 ( V_4 , L_2 , V_14 , V_10 ) ;
if ( V_10 < 0 ) {
V_4 -> V_15 . V_16 ++ ;
V_4 -> V_15 . V_17 ++ ;
goto V_18;
}
F_8 ( V_12 , V_10 ) ;
V_12 -> V_19 = F_9 ( V_12 , V_4 ) ;
V_12 -> V_20 = V_21 ;
if ( F_10 ( V_12 ) == V_22 ) {
V_4 -> V_15 . V_16 ++ ;
V_4 -> V_15 . V_23 ++ ;
} else {
V_4 -> V_15 . V_24 ++ ;
V_4 -> V_15 . V_25 += V_10 ;
}
V_12 = F_11 ( V_4 , V_4 -> V_26 + V_27 ) ;
if ( ! V_12 ) {
V_4 -> V_15 . V_16 ++ ;
V_4 -> V_15 . V_28 ++ ;
return;
}
V_18:
V_13 = F_12 ( V_7 , V_12 , V_12 -> V_1 , V_4 -> V_26 + V_27 ) ;
if ( V_13 ) {
F_13 ( V_12 ) ;
V_4 -> V_15 . V_16 ++ ;
V_4 -> V_15 . V_29 ++ ;
}
}
static void F_14 ( struct V_8 * V_7 , void * V_9 ,
void * V_1 , int V_10 )
{
struct V_3 * V_4 = V_9 ;
struct V_11 * V_12 ;
V_12 = V_1 ;
if ( ! V_12 || ! V_4 )
return;
if ( V_10 > 0 ) {
V_4 -> V_15 . V_30 ++ ;
V_4 -> V_15 . V_31 += V_12 -> V_10 ;
} else {
V_4 -> V_15 . V_32 ++ ;
V_4 -> V_15 . V_33 ++ ;
}
F_13 ( V_12 ) ;
}
static T_1 F_15 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_13 ;
V_13 = F_16 ( V_6 -> V_7 , V_12 , V_12 -> V_1 , V_12 -> V_10 ) ;
if ( V_13 )
goto V_34;
return V_35 ;
V_34:
V_4 -> V_15 . V_36 ++ ;
V_4 -> V_15 . V_32 ++ ;
return V_37 ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_11 * V_12 ;
int V_13 , V_38 , V_10 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_12 = F_11 ( V_4 , V_4 -> V_26 + V_27 ) ;
if ( ! V_12 ) {
V_13 = - V_40 ;
goto V_34;
}
V_13 = F_12 ( V_6 -> V_7 , V_12 , V_12 -> V_1 ,
V_4 -> V_26 + V_27 ) ;
if ( V_13 ) {
F_13 ( V_12 ) ;
goto V_34;
}
}
F_6 ( V_4 ) ;
F_18 ( V_6 -> V_7 ) ;
return 0 ;
V_34:
while ( ( V_12 = F_19 ( V_6 -> V_7 , & V_10 ) ) )
F_13 ( V_12 ) ;
return V_13 ;
}
static int F_20 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_11 * V_12 ;
int V_10 ;
F_21 ( V_6 -> V_7 ) ;
while ( ( V_12 = F_19 ( V_6 -> V_7 , & V_10 ) ) )
F_13 ( V_12 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 , int V_41 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_11 * V_12 ;
int V_10 , V_13 ;
if ( V_41 > F_23 ( V_6 -> V_7 ) - V_27 )
return - V_42 ;
if ( ! F_24 ( V_4 ) ) {
V_4 -> V_26 = V_41 ;
return 0 ;
}
F_21 ( V_6 -> V_7 ) ;
if ( V_4 -> V_26 < V_41 ) {
int V_38 ;
for ( V_38 = 0 ; ( V_12 = F_19 ( V_6 -> V_7 , & V_10 ) ) ; V_38 ++ )
F_13 ( V_12 ) ;
for (; V_38 ; V_38 -- ) {
V_12 = F_11 ( V_4 , V_41 + V_27 ) ;
if ( ! V_12 ) {
V_13 = - V_40 ;
goto V_34;
}
V_13 = F_12 ( V_6 -> V_7 , V_12 , V_12 -> V_1 ,
V_41 + V_27 ) ;
if ( V_13 ) {
F_13 ( V_12 ) ;
goto V_34;
}
}
}
V_4 -> V_26 = V_41 ;
F_18 ( V_6 -> V_7 ) ;
return 0 ;
V_34:
F_21 ( V_6 -> V_7 ) ;
while ( ( V_12 = F_19 ( V_6 -> V_7 , & V_10 ) ) )
F_13 ( V_12 ) ;
F_25 ( V_4 , L_3 ) ;
return V_13 ;
}
static void F_26 ( struct V_3 * V_4 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_27 ( V_44 -> V_45 , V_46 , sizeof( V_44 -> V_45 ) ) ;
F_27 ( V_44 -> V_47 , V_48 , sizeof( V_44 -> V_47 ) ) ;
F_27 ( V_44 -> V_49 , F_28 ( V_6 -> V_50 ) , sizeof( V_44 -> V_49 ) ) ;
}
static int F_29 ( struct V_3 * V_6 , struct V_51 * V_52 )
{
V_52 -> V_53 = V_54 ;
V_52 -> V_55 = V_56 ;
F_30 ( V_52 , V_57 ) ;
V_52 -> V_58 = V_59 ;
V_52 -> V_60 = V_61 ;
V_52 -> V_62 = 0 ;
V_52 -> V_63 = V_64 ;
V_52 -> V_65 = V_66 ;
V_52 -> V_67 = 0 ;
V_52 -> V_68 = 0 ;
return 0 ;
}
static int F_31 ( struct V_69 * V_70 )
{
struct V_71 * V_72 ;
struct V_3 * V_4 ;
struct V_73 * V_50 ;
struct V_5 * V_6 ;
int V_13 ;
V_72 = F_32 ( V_70 -> V_74 ) ;
V_50 = V_72 -> V_50 ;
if ( ! V_50 )
return - V_75 ;
V_4 = F_33 ( sizeof( * V_6 ) ) ;
if ( ! V_4 )
return - V_40 ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_4 = V_4 ;
V_6 -> V_50 = V_50 ;
V_4 -> V_76 = V_77 ;
V_4 -> V_78 |= V_79 ;
V_4 -> V_80 = V_4 -> V_76 ;
V_4 -> V_81 = F_34 ( V_82 ) ;
F_35 ( V_4 -> V_83 ) ;
memcpy ( V_4 -> V_84 , V_4 -> V_83 , V_4 -> V_85 ) ;
V_4 -> V_86 = & V_87 ;
V_4 -> V_88 = & V_89 ;
V_6 -> V_7 = F_36 ( V_4 , V_70 ,
& V_90 ) ;
if ( ! V_6 -> V_7 ) {
V_13 = - V_91 ;
goto V_34;
}
V_4 -> V_26 = F_23 ( V_6 -> V_7 ) - V_27 ;
V_13 = F_37 ( V_4 ) ;
if ( V_13 )
goto V_92;
F_38 ( & V_6 -> V_93 , & V_94 ) ;
F_39 ( & V_50 -> V_6 , L_4 , V_4 -> V_95 ) ;
return 0 ;
V_92:
F_40 ( V_6 -> V_7 ) ;
V_34:
F_41 ( V_4 ) ;
return V_13 ;
}
static void F_42 ( struct V_69 * V_70 )
{
struct V_71 * V_72 ;
struct V_3 * V_4 ;
struct V_73 * V_50 ;
struct V_5 * V_6 ;
bool V_96 = false ;
V_72 = F_32 ( V_70 -> V_74 ) ;
V_50 = V_72 -> V_50 ;
F_43 (dev, &dev_list, list) {
if ( V_6 -> V_50 == V_50 ) {
V_96 = true ;
break;
}
}
if ( ! V_96 )
return;
F_44 ( & V_6 -> V_93 ) ;
V_4 = V_6 -> V_4 ;
F_45 ( V_4 ) ;
F_40 ( V_6 -> V_7 ) ;
F_41 ( V_4 ) ;
}
static int T_2 F_46 ( void )
{
int V_13 ;
V_13 = F_47 ( V_46 ) ;
if ( V_13 )
return V_13 ;
return F_48 ( & V_97 ) ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_97 ) ;
F_51 ( V_46 ) ;
}
