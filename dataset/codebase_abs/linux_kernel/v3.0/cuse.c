static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_4 * F_3 ( T_1 V_5 )
{
return & V_6 [ ( F_4 ( V_5 ) + F_5 ( V_5 ) ) % V_7 ] ;
}
static T_2 F_6 ( struct V_8 * V_8 , char T_3 * V_9 , T_4 V_10 ,
T_5 * V_11 )
{
T_5 V_12 = 0 ;
return F_7 ( V_8 , V_9 , V_10 , & V_12 , 0 ) ;
}
static T_2 F_8 ( struct V_8 * V_8 , const char T_3 * V_9 ,
T_4 V_10 , T_5 * V_11 )
{
T_5 V_12 = 0 ;
return F_7 ( V_8 , V_9 , V_10 , & V_12 , 1 ) ;
}
static int F_9 ( struct V_13 * V_13 , struct V_8 * V_8 )
{
T_1 V_5 = V_13 -> V_14 -> V_15 ;
struct V_1 * V_16 = NULL , * V_12 ;
int V_17 ;
F_10 ( & V_18 ) ;
F_11 (pos, cuse_conntbl_head(devt), list)
if ( V_12 -> V_15 -> V_5 == V_5 ) {
F_12 ( & V_12 -> V_3 ) ;
V_16 = V_12 ;
break;
}
F_13 ( & V_18 ) ;
if ( ! V_16 )
return - V_19 ;
V_17 = F_14 ( & V_16 -> V_3 , 0 , V_8 , 0 ) ;
if ( V_17 )
F_15 ( & V_16 -> V_3 ) ;
return V_17 ;
}
static int F_16 ( struct V_13 * V_13 , struct V_8 * V_8 )
{
struct V_20 * V_21 = V_8 -> V_22 ;
struct V_2 * V_3 = V_21 -> V_3 ;
F_17 ( V_21 , V_8 -> V_23 ) ;
F_15 ( V_3 ) ;
return 0 ;
}
static long F_18 ( struct V_8 * V_8 , unsigned int V_24 ,
unsigned long V_25 )
{
struct V_20 * V_21 = V_8 -> V_22 ;
struct V_1 * V_16 = F_1 ( V_21 -> V_3 ) ;
unsigned int V_26 = 0 ;
if ( V_16 -> V_27 )
V_26 |= V_28 ;
return F_19 ( V_8 , V_24 , V_25 , V_26 ) ;
}
static long F_20 ( struct V_8 * V_8 , unsigned int V_24 ,
unsigned long V_25 )
{
struct V_20 * V_21 = V_8 -> V_22 ;
struct V_1 * V_16 = F_1 ( V_21 -> V_3 ) ;
unsigned int V_26 = V_29 ;
if ( V_16 -> V_27 )
V_26 |= V_28 ;
return F_19 ( V_8 , V_24 , V_25 , V_26 ) ;
}
static int F_21 ( char * * V_30 , char * V_31 , char * * V_32 , char * * V_33 )
{
char * V_34 = * V_30 ;
char * V_35 , * V_36 ;
while ( V_34 < V_31 && * V_34 == '\0' )
V_34 ++ ;
if ( V_34 == V_31 )
return 0 ;
if ( V_31 [ - 1 ] != '\0' ) {
F_22 ( V_37 L_1 ) ;
return - V_38 ;
}
V_35 = V_36 = V_34 ;
V_34 += strlen ( V_34 ) ;
if ( V_33 ) {
F_23 ( & V_36 , L_2 ) ;
if ( ! V_36 )
V_36 = V_35 + strlen ( V_35 ) ;
V_35 = F_24 ( V_35 ) ;
V_36 = F_24 ( V_36 ) ;
} else
V_35 = F_24 ( V_35 ) ;
if ( ! strlen ( V_35 ) ) {
F_22 ( V_37 L_3 ) ;
return - V_38 ;
}
* V_30 = V_34 ;
* V_32 = V_35 ;
if ( V_33 )
* V_33 = V_36 ;
return 1 ;
}
static int F_25 ( char * V_34 , T_4 V_39 , struct V_40 * V_41 )
{
char * V_31 = V_34 + V_39 ;
char * V_35 , * V_36 ;
int V_17 ;
while ( true ) {
V_17 = F_21 ( & V_34 , V_31 , & V_35 , & V_36 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( ! V_17 )
break;
if ( strcmp ( V_35 , L_4 ) == 0 )
V_41 -> V_42 = V_36 ;
else
F_22 ( V_43 L_5 ,
V_35 ) ;
}
if ( ! V_41 -> V_42 || ! strlen ( V_41 -> V_42 ) ) {
F_22 ( V_37 L_6 ) ;
return - V_38 ;
}
return 0 ;
}
static void F_26 ( struct V_44 * V_15 )
{
F_27 ( V_15 ) ;
}
static void F_28 ( struct V_2 * V_3 , struct V_45 * V_46 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_47 * V_25 = V_46 -> V_48 . args [ 0 ] . V_49 ;
struct V_50 * V_50 = V_46 -> V_51 [ 0 ] ;
struct V_40 V_41 = { } ;
struct V_44 * V_15 ;
struct V_52 * V_52 ;
T_1 V_5 ;
int V_17 ;
if ( V_46 -> V_48 . V_53 . error ||
V_25 -> V_54 != V_55 || V_25 -> V_56 < 11 ) {
goto V_57;
}
V_3 -> V_56 = V_25 -> V_56 ;
V_3 -> V_58 = F_29 ( unsigned , V_25 -> V_58 , 4096 ) ;
V_3 -> V_59 = F_29 ( unsigned , V_25 -> V_59 , 4096 ) ;
V_16 -> V_27 = V_25 -> V_26 & V_60 ;
V_17 = F_25 ( F_30 ( V_50 ) , V_46 -> V_48 . args [ 1 ] . V_61 ,
& V_41 ) ;
if ( V_17 )
goto V_57;
V_5 = F_31 ( V_25 -> V_62 , V_25 -> V_63 ) ;
if ( ! F_4 ( V_5 ) )
V_17 = F_32 ( & V_5 , F_5 ( V_5 ) , 1 , V_41 . V_42 ) ;
else
V_17 = F_33 ( V_5 , 1 , V_41 . V_42 ) ;
if ( V_17 ) {
F_22 ( V_37 L_7 ) ;
goto V_57;
}
V_17 = - V_64 ;
V_15 = F_34 ( sizeof( * V_15 ) , V_65 ) ;
if ( ! V_15 )
goto V_66;
F_35 ( V_15 ) ;
F_36 ( V_15 , 1 ) ;
V_15 -> V_67 = V_68 ;
V_15 -> V_5 = V_5 ;
V_15 -> V_69 = F_26 ;
F_37 ( V_15 , V_16 ) ;
F_38 ( V_15 , L_8 , V_41 . V_42 ) ;
V_17 = F_39 ( V_15 ) ;
if ( V_17 )
goto V_70;
V_17 = - V_64 ;
V_52 = F_40 () ;
if ( ! V_52 )
goto V_70;
V_52 -> V_71 = V_72 ;
V_52 -> V_73 = & V_74 ;
V_17 = F_41 ( V_52 , V_5 , 1 ) ;
if ( V_17 )
goto V_75;
V_16 -> V_15 = V_15 ;
V_16 -> V_52 = V_52 ;
F_10 ( & V_18 ) ;
F_42 ( & V_16 -> V_76 , F_3 ( V_5 ) ) ;
F_13 ( & V_18 ) ;
F_36 ( V_15 , 0 ) ;
F_43 ( & V_15 -> V_77 , V_78 ) ;
V_48:
F_27 ( V_25 ) ;
F_44 ( V_50 ) ;
return;
V_75:
F_45 ( V_52 ) ;
V_70:
F_46 ( V_15 ) ;
V_66:
F_47 ( V_5 , 1 ) ;
V_57:
V_3 -> V_79 = 1 ;
goto V_48;
}
static int F_48 ( struct V_1 * V_16 )
{
int V_17 ;
struct V_45 * V_46 ;
struct V_50 * V_50 ;
struct V_2 * V_3 = & V_16 -> V_3 ;
struct V_80 * V_25 ;
void * V_81 ;
F_49 ( V_82 > V_83 ) ;
V_46 = F_50 ( V_3 ) ;
if ( F_51 ( V_46 ) ) {
V_17 = F_52 ( V_46 ) ;
goto V_57;
}
V_17 = - V_64 ;
V_50 = F_53 ( V_65 | V_84 ) ;
if ( ! V_50 )
goto V_85;
V_81 = F_34 ( sizeof( struct V_47 ) , V_65 ) ;
if ( ! V_81 )
goto V_86;
V_25 = & V_46 -> V_87 . V_80 ;
V_25 -> V_54 = V_55 ;
V_25 -> V_56 = V_88 ;
V_25 -> V_26 |= V_60 ;
V_46 -> V_89 . V_53 . V_90 = V_91 ;
V_46 -> V_89 . V_92 = 1 ;
V_46 -> V_89 . args [ 0 ] . V_61 = sizeof( struct V_80 ) ;
V_46 -> V_89 . args [ 0 ] . V_49 = V_25 ;
V_46 -> V_48 . V_92 = 2 ;
V_46 -> V_48 . args [ 0 ] . V_61 = sizeof( struct V_47 ) ;
V_46 -> V_48 . args [ 0 ] . V_49 = V_81 ;
V_46 -> V_48 . args [ 1 ] . V_61 = V_82 ;
V_46 -> V_48 . V_93 = 1 ;
V_46 -> V_48 . V_94 = 1 ;
V_46 -> V_51 [ 0 ] = V_50 ;
V_46 -> V_95 = 1 ;
V_46 -> V_31 = F_28 ;
F_54 ( V_3 , V_46 ) ;
return 0 ;
V_86:
F_44 ( V_50 ) ;
V_85:
F_55 ( V_3 , V_46 ) ;
V_57:
return V_17 ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_27 ( V_16 ) ;
}
static int F_57 ( struct V_13 * V_13 , struct V_8 * V_8 )
{
struct V_1 * V_16 ;
int V_17 ;
V_16 = F_34 ( sizeof( * V_16 ) , V_65 ) ;
if ( ! V_16 )
return - V_64 ;
F_58 ( & V_16 -> V_3 ) ;
F_59 ( & V_16 -> V_76 ) ;
V_16 -> V_3 . V_69 = F_56 ;
V_16 -> V_3 . V_96 = 1 ;
V_16 -> V_3 . V_97 = 0 ;
V_17 = F_48 ( V_16 ) ;
if ( V_17 ) {
F_15 ( & V_16 -> V_3 ) ;
return V_17 ;
}
V_8 -> V_22 = & V_16 -> V_3 ;
return 0 ;
}
static int F_60 ( struct V_13 * V_13 , struct V_8 * V_8 )
{
struct V_1 * V_16 = F_1 ( V_8 -> V_22 ) ;
int V_17 ;
F_10 ( & V_18 ) ;
F_61 ( & V_16 -> V_76 ) ;
F_13 ( & V_18 ) ;
if ( V_16 -> V_15 )
F_62 ( V_16 -> V_15 ) ;
if ( V_16 -> V_52 ) {
F_47 ( V_16 -> V_52 -> V_15 , 1 ) ;
F_45 ( V_16 -> V_52 ) ;
}
F_63 ( & V_16 -> V_3 ) ;
V_17 = F_64 ( V_13 , V_8 ) ;
return V_17 ;
}
static T_2 F_65 ( struct V_44 * V_15 ,
struct V_98 * V_99 , char * V_9 )
{
struct V_1 * V_16 = F_66 ( V_15 ) ;
return sprintf ( V_9 , L_9 , F_67 ( & V_16 -> V_3 . V_100 ) ) ;
}
static T_2 F_68 ( struct V_44 * V_15 ,
struct V_98 * V_99 ,
const char * V_9 , T_4 V_10 )
{
struct V_1 * V_16 = F_66 ( V_15 ) ;
F_69 ( & V_16 -> V_3 ) ;
return V_10 ;
}
static int T_6 F_70 ( void )
{
int V_101 , V_17 ;
for ( V_101 = 0 ; V_101 < V_7 ; V_101 ++ )
F_59 ( & V_6 [ V_101 ] ) ;
V_102 = V_103 ;
V_102 . V_71 = V_72 ;
V_102 . V_104 = F_57 ;
V_102 . V_69 = F_60 ;
V_68 = F_71 ( V_72 , L_10 ) ;
if ( F_51 ( V_68 ) )
return F_52 ( V_68 ) ;
V_68 -> V_105 = V_106 ;
V_17 = F_72 ( & V_107 ) ;
if ( V_17 ) {
F_73 ( V_68 ) ;
return V_17 ;
}
return 0 ;
}
static void T_7 F_74 ( void )
{
F_75 ( & V_107 ) ;
F_73 ( V_68 ) ;
}
