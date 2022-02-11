static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( V_4 , L_1 , V_2 ,
F_4 ( V_6 -> V_7 ) ) ;
if ( V_2 )
F_5 ( V_4 ) ;
else
F_6 ( V_4 ) ;
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
F_8 ( V_12 , V_10 ) ;
V_12 -> V_15 = F_9 ( V_12 , V_4 ) ;
V_12 -> V_16 = V_17 ;
if ( F_10 ( V_12 ) == V_18 ) {
V_4 -> V_19 . V_20 ++ ;
V_4 -> V_19 . V_21 ++ ;
} else {
V_4 -> V_19 . V_22 ++ ;
V_4 -> V_19 . V_23 += V_10 ;
}
V_12 = F_11 ( V_4 , V_4 -> V_24 + V_25 ) ;
if ( ! V_12 ) {
V_4 -> V_19 . V_20 ++ ;
V_4 -> V_19 . V_26 ++ ;
return;
}
V_13 = F_12 ( V_7 , V_12 , V_12 -> V_1 , V_4 -> V_24 + V_25 ) ;
if ( V_13 ) {
F_13 ( V_12 ) ;
V_4 -> V_19 . V_20 ++ ;
V_4 -> V_19 . V_27 ++ ;
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
V_4 -> V_19 . V_28 ++ ;
V_4 -> V_19 . V_29 += V_12 -> V_10 ;
} else {
V_4 -> V_19 . V_30 ++ ;
V_4 -> V_19 . V_31 ++ ;
}
F_13 ( V_12 ) ;
}
static T_1 F_15 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_13 ;
F_3 ( V_4 , L_3 , V_14 , V_12 -> V_10 ) ;
V_13 = F_16 ( V_6 -> V_7 , V_12 , V_12 -> V_1 , V_12 -> V_10 ) ;
if ( V_13 )
goto V_32;
return V_33 ;
V_32:
V_4 -> V_19 . V_34 ++ ;
V_4 -> V_19 . V_30 ++ ;
return V_35 ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_11 * V_12 ;
int V_13 , V_36 , V_10 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_12 = F_11 ( V_4 , V_4 -> V_24 + V_25 ) ;
if ( ! V_12 ) {
V_13 = - V_38 ;
goto V_32;
}
V_13 = F_12 ( V_6 -> V_7 , V_12 , V_12 -> V_1 ,
V_4 -> V_24 + V_25 ) ;
if ( V_13 == - V_39 )
goto V_32;
}
F_6 ( V_4 ) ;
F_18 ( V_6 -> V_7 ) ;
return 0 ;
V_32:
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
static int F_22 ( struct V_3 * V_4 , int V_40 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_11 * V_12 ;
int V_10 , V_13 ;
if ( V_40 > F_23 ( V_6 -> V_7 ) - V_25 )
return - V_39 ;
if ( ! F_24 ( V_4 ) ) {
V_4 -> V_24 = V_40 ;
return 0 ;
}
F_21 ( V_6 -> V_7 ) ;
if ( V_4 -> V_24 < V_40 ) {
int V_36 ;
for ( V_36 = 0 ; ( V_12 = F_19 ( V_6 -> V_7 , & V_10 ) ) ; V_36 ++ )
F_13 ( V_12 ) ;
for (; V_36 ; V_36 -- ) {
V_12 = F_11 ( V_4 , V_40 + V_25 ) ;
if ( ! V_12 ) {
V_13 = - V_38 ;
goto V_32;
}
V_13 = F_12 ( V_6 -> V_7 , V_12 , V_12 -> V_1 ,
V_40 + V_25 ) ;
if ( V_13 ) {
F_13 ( V_12 ) ;
goto V_32;
}
}
}
V_4 -> V_24 = V_40 ;
F_18 ( V_6 -> V_7 ) ;
return 0 ;
V_32:
F_21 ( V_6 -> V_7 ) ;
while ( ( V_12 = F_19 ( V_6 -> V_7 , & V_10 ) ) )
F_13 ( V_12 ) ;
F_25 ( V_4 , L_4 ) ;
return V_13 ;
}
static void F_26 ( struct V_3 * V_4 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_27 ( V_42 -> V_43 , V_44 , sizeof( V_42 -> V_43 ) ) ;
F_27 ( V_42 -> V_45 , V_46 , sizeof( V_42 -> V_45 ) ) ;
F_27 ( V_42 -> V_47 , F_28 ( V_6 -> V_48 ) , sizeof( V_42 -> V_47 ) ) ;
}
static int F_29 ( struct V_3 * V_6 , struct V_49 * V_50 )
{
V_50 -> V_51 = V_52 ;
V_50 -> V_53 = V_54 ;
V_50 -> V_55 = V_56 ;
F_30 ( V_50 , V_56 ) ;
V_50 -> V_57 = V_58 ;
V_50 -> V_59 = V_60 ;
V_50 -> V_61 = 0 ;
V_50 -> V_62 = V_63 ;
V_50 -> V_64 = V_65 ;
V_50 -> V_66 = 0 ;
V_50 -> V_67 = 0 ;
return 0 ;
}
static int F_31 ( struct V_68 * V_48 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_13 ;
V_4 = F_32 ( sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return - V_38 ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_4 = V_4 ;
V_6 -> V_48 = V_48 ;
F_33 ( ! V_6 -> V_48 ) ;
V_4 -> V_69 = V_70 ;
V_4 -> V_71 |= V_72 ;
V_4 -> V_73 = V_4 -> V_69 ;
V_4 -> V_74 = F_34 ( V_75 ) ;
F_35 ( V_4 -> V_76 ) ;
memcpy ( V_4 -> V_77 , V_4 -> V_76 , V_4 -> V_78 ) ;
V_4 -> V_79 = & V_80 ;
F_36 ( V_4 , & V_81 ) ;
V_6 -> V_7 = F_37 ( V_4 , V_48 , & V_82 ) ;
if ( ! V_6 -> V_7 ) {
V_13 = - V_83 ;
goto V_32;
}
V_4 -> V_24 = F_23 ( V_6 -> V_7 ) - V_25 ;
V_13 = F_38 ( V_4 ) ;
if ( V_13 )
goto V_84;
F_39 ( & V_6 -> V_85 , & V_86 ) ;
F_40 ( & V_48 -> V_6 , L_5 , V_4 -> V_87 ) ;
return 0 ;
V_84:
F_41 ( V_6 -> V_7 ) ;
V_32:
F_42 ( V_4 ) ;
return V_13 ;
}
static void F_43 ( struct V_68 * V_48 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_44 (dev, &dev_list, list) {
if ( V_6 -> V_48 == V_48 )
break;
}
if ( V_6 == NULL )
return;
V_4 = V_6 -> V_4 ;
F_45 ( V_4 ) ;
F_41 ( V_6 -> V_7 ) ;
F_42 ( V_4 ) ;
}
static int T_2 F_46 ( void )
{
int V_13 ;
V_13 = F_47 ( V_44 ) ;
if ( V_13 )
return V_13 ;
return F_48 ( & V_88 ) ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_88 ) ;
F_51 ( V_44 ) ;
}
