static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
struct V_3 * V_5 = NULL ;
T_1 * V_6 = NULL ;
T_1 * V_7 = NULL ;
V_4 = F_2 ( 0 , V_8 ) ;
if ( V_4 == NULL )
goto V_9;
V_5 = F_2 ( 0 , V_8 ) ;
if ( V_5 == NULL )
goto V_10;
V_6 = F_3 ( V_2 -> V_11 , V_12 ,
V_8 , & V_4 -> V_13 ) ;
if ( V_6 == NULL )
goto V_14;
V_7 = F_3 ( V_2 -> V_11 , V_12 ,
V_8 , & V_5 -> V_13 ) ;
if ( V_7 == NULL )
goto V_15;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = V_7 ;
return 0 ;
V_15:
F_4 ( V_2 -> V_11 , V_12 , V_6 ,
V_4 -> V_13 ) ;
V_14:
F_5 ( V_5 ) ;
V_10:
F_5 ( V_4 ) ;
V_9:
return - V_16 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_11 , V_12 , V_2 -> V_7 ,
V_2 -> V_5 -> V_13 ) ;
F_4 ( V_2 -> V_11 , V_12 , V_2 -> V_6 ,
V_2 -> V_4 -> V_13 ) ;
F_5 ( V_2 -> V_5 ) ;
F_5 ( V_2 -> V_4 ) ;
}
static void F_7 ( struct V_1 * V_17 )
{
F_8 ( V_17 -> V_4 ) ;
F_8 ( V_17 -> V_5 ) ;
}
static void F_9 ( struct V_3 * V_3 )
{
struct V_1 * V_17 ;
struct V_18 * V_19 ;
int V_20 ;
char * V_21 ;
int V_22 ;
V_17 = V_3 -> V_23 ;
if ( V_17 == NULL )
return;
V_20 = V_3 -> V_20 ;
switch ( V_20 ) {
case - V_24 :
case - V_25 :
case - V_26 :
return;
case 0 :
break;
default:
F_10 ( L_1 , V_27 , V_20 ) ;
return;
}
if ( V_3 -> V_28 <= V_29 ) {
V_17 -> V_30 -> V_31 . V_32 ++ ;
return;
}
V_22 = V_3 -> V_28 - V_29 ;
V_21 = V_3 -> V_33 + V_29 ;
V_19 = F_11 ( V_22 ) ;
if ( ! V_19 ) {
F_10 ( L_2 , V_27 ) ;
V_17 -> V_30 -> V_31 . V_34 ++ ;
return;
}
memcpy ( F_12 ( V_19 , V_22 ) , V_21 , V_22 ) ;
V_19 -> V_17 = V_17 -> V_30 ;
V_19 -> V_35 = F_13 ( V_19 , V_17 -> V_30 ) ;
V_17 -> V_30 -> V_31 . V_36 ++ ;
V_17 -> V_30 -> V_31 . V_37 += V_22 ;
F_14 ( V_19 ) ;
F_15 ( V_17 , V_38 ) ;
}
static void F_16 ( struct V_3 * V_3 )
{
struct V_1 * V_17 ;
int V_20 = V_3 -> V_20 ;
V_17 = V_3 -> V_23 ;
if ( V_17 == NULL )
return;
if ( V_20 != 0 &&
V_20 != - V_24 &&
V_20 != - V_25 &&
V_20 != - V_26 )
F_10 ( L_1 , V_27 , V_20 ) ;
F_17 ( V_17 -> V_39 ) ;
F_18 ( V_17 -> V_30 ) ;
}
static int F_19 ( struct V_1 * V_17 )
{
struct V_40 * V_11 = V_17 -> V_11 ;
int V_41 ;
V_41 = F_20 ( V_11 ,
F_21 ( V_11 , V_42 ) ,
V_43 ,
0xc0 ,
0x00 ,
0x02 ,
V_17 -> V_44 , V_45 ,
V_46 ) ;
if ( V_41 < 0 ) {
F_10 ( L_3 , V_27 , V_41 ) ;
return V_41 ;
}
if ( V_17 -> V_44 [ 0 ] == V_47 )
F_22 ( V_17 -> V_30 ) ;
else
F_23 ( V_17 -> V_30 ) ;
return 0 ;
}
static void F_24 ( struct V_48 * V_49 )
{
struct V_1 * V_17 = F_25 ( V_49 , struct V_1 ,
V_50 . V_49 ) ;
F_19 ( V_17 ) ;
F_26 ( & V_17 -> V_50 , V_51 ) ;
}
static int F_27 ( struct V_1 * V_17 )
{
struct V_40 * V_11 = V_17 -> V_11 ;
struct V_52 * V_30 = V_17 -> V_30 ;
int V_41 ;
V_41 = F_20 ( V_11 ,
F_21 ( V_11 , V_42 ) ,
V_53 ,
0xc0 ,
0x00 ,
0x02 ,
V_17 -> V_44 ,
V_45 ,
V_46 ) ;
if ( V_41 < 0 ) {
F_10 ( L_3 , V_27 , V_41 ) ;
} else if ( V_41 < V_54 ) {
F_10 ( L_4 ,
V_27 , V_41 ) ;
V_41 = - V_55 ;
} else {
memcpy ( V_30 -> V_56 , V_17 -> V_44 , V_54 ) ;
V_41 = 0 ;
}
return V_41 ;
}
static int F_15 ( struct V_1 * V_17 , T_2 V_57 )
{
struct V_40 * V_11 = V_17 -> V_11 ;
int V_41 ;
F_28 ( V_17 -> V_5 , V_11 ,
F_29 ( V_11 , V_17 -> V_58 ) ,
V_17 -> V_7 , V_12 ,
F_9 ,
V_17 ) ;
V_17 -> V_5 -> V_59 |= V_60 ;
V_41 = F_30 ( V_17 -> V_5 , V_57 ) ;
if ( V_41 )
F_10 ( L_5 , V_27 , V_41 ) ;
return V_41 ;
}
static int F_31 ( struct V_52 * V_30 )
{
struct V_1 * V_17 = F_32 ( V_30 ) ;
struct V_40 * V_11 = V_17 -> V_11 ;
int V_41 = 0 ;
F_33 ( V_11 , V_61 , V_62 ) ;
V_41 = F_19 ( V_17 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_15 ( V_17 , V_8 ) ;
if ( V_41 )
return V_41 ;
F_26 ( & V_17 -> V_50 , V_51 ) ;
F_34 ( V_30 ) ;
return V_41 ;
}
static int F_35 ( struct V_52 * V_30 )
{
struct V_1 * V_17 = F_32 ( V_30 ) ;
F_36 ( & V_17 -> V_50 ) ;
F_37 ( V_30 ) ;
return 0 ;
}
static int F_38 ( struct V_18 * V_19 , struct V_52 * V_30 )
{
struct V_1 * V_17 = F_32 ( V_30 ) ;
struct V_40 * V_11 = V_17 -> V_11 ;
int V_41 ;
if ( V_19 -> V_22 > V_12 ) {
F_39 ( 1 , L_6 , V_27 , V_19 -> V_22 ) ;
V_17 -> V_30 -> V_31 . V_63 ++ ;
F_17 ( V_19 ) ;
return V_64 ;
}
memcpy ( V_17 -> V_6 , V_19 -> V_65 , V_19 -> V_22 ) ;
if ( V_19 -> V_22 < V_12 )
memset ( V_17 -> V_6 + V_19 -> V_22 , 0 , V_12 - V_19 -> V_22 ) ;
F_28 ( V_17 -> V_4 , V_11 ,
F_40 ( V_11 , V_17 -> V_66 ) ,
V_17 -> V_6 , V_12 ,
F_16 ,
V_17 ) ;
V_17 -> V_4 -> V_59 |= V_60 ;
V_41 = F_30 ( V_17 -> V_4 , V_38 ) ;
if ( V_41 ) {
F_10 ( L_5 , V_27 , V_41 ) ;
V_17 -> V_30 -> V_31 . V_67 ++ ;
F_17 ( V_19 ) ;
} else {
V_17 -> V_39 = V_19 ;
V_17 -> V_30 -> V_31 . V_68 ++ ;
V_17 -> V_30 -> V_31 . V_69 += V_19 -> V_22 ;
F_37 ( V_30 ) ;
}
return V_64 ;
}
static void F_41 ( struct V_52 * V_30 )
{
struct V_1 * V_17 = F_32 ( V_30 ) ;
F_10 ( L_7 , V_27 ) ;
V_17 -> V_30 -> V_31 . V_67 ++ ;
F_42 ( V_17 -> V_4 ) ;
}
static T_3 F_43 ( struct V_52 * V_30 )
{
struct V_1 * V_17 = F_32 ( V_30 ) ;
return F_44 ( V_17 -> V_30 ) ;
}
static int F_45 ( struct V_70 * V_71 ,
const struct V_72 * V_73 )
{
struct V_40 * V_11 = F_46 ( V_71 ) ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
struct V_1 * V_17 ;
struct V_52 * V_78 ;
int V_79 ;
int V_41 ;
V_78 = F_47 ( sizeof( struct V_1 ) ) ;
if ( ! V_78 )
return - V_16 ;
V_78 -> V_80 = & V_81 ;
V_78 -> V_82 = V_83 ;
strcpy ( V_78 -> V_84 , L_8 ) ;
V_17 = F_32 ( V_78 ) ;
V_17 -> V_11 = V_11 ;
V_17 -> V_30 = V_78 ;
V_17 -> V_71 = V_71 ;
V_75 = F_48 ( V_71 , V_62 ) ;
if ( V_75 == NULL ) {
V_41 = - V_85 ;
F_10 ( L_9 ) ;
goto V_86;
}
for ( V_79 = 0 ; V_79 < V_75 -> V_87 . V_88 ; V_79 ++ ) {
V_77 = & V_75 -> V_89 [ V_79 ] . V_87 ;
if ( F_49 ( V_77 ) )
V_17 -> V_58 = V_77 -> V_90 ;
else if ( F_50 ( V_77 ) )
V_17 -> V_66 = V_77 -> V_90 ;
}
if ( ! ( V_17 -> V_58 && V_17 -> V_66 ) ) {
V_41 = - V_85 ;
F_10 ( L_10 ) ;
goto V_86;
}
V_17 -> V_44 = F_51 ( V_45 , V_8 ) ;
if ( V_17 -> V_44 == NULL ) {
V_41 = - V_16 ;
goto V_91;
}
V_41 = F_27 ( V_17 ) ;
if ( V_41 )
goto V_92;
F_52 ( & V_17 -> V_50 , F_24 ) ;
V_41 = F_1 ( V_17 ) ;
if ( V_41 ) {
F_10 ( L_11 , V_41 ) ;
goto V_93;
}
F_53 ( V_71 , V_17 ) ;
F_54 ( V_78 , & V_71 -> V_17 ) ;
F_55 ( V_78 , & V_94 ) ;
V_41 = F_56 ( V_78 ) ;
if ( V_41 ) {
F_10 ( L_12 , V_41 ) ;
V_41 = - V_95 ;
goto V_96;
}
F_57 ( & V_71 -> V_17 , L_13 ) ;
return 0 ;
V_96:
F_6 ( V_17 ) ;
V_93:
V_92:
V_91:
F_58 ( V_17 -> V_44 ) ;
V_86:
F_59 ( V_78 ) ;
return V_41 ;
}
static void F_60 ( struct V_70 * V_71 )
{
struct V_1 * V_17 ;
V_17 = F_61 ( V_71 ) ;
if ( V_17 != NULL ) {
F_62 ( V_17 -> V_30 ) ;
F_7 ( V_17 ) ;
F_6 ( V_17 ) ;
F_58 ( V_17 -> V_44 ) ;
F_59 ( V_17 -> V_30 ) ;
}
F_53 ( V_71 , NULL ) ;
F_57 ( & V_71 -> V_17 , L_14 ) ;
}
static int T_4 F_63 ( void )
{
int V_41 ;
V_41 = F_64 ( & V_97 ) ;
if ( V_41 ) {
F_10 ( L_15 , V_41 ) ;
return V_41 ;
}
return 0 ;
}
static void T_5 F_65 ( void )
{
F_66 ( & V_97 ) ;
}
