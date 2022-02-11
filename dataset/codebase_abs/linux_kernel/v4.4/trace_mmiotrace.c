static void F_1 ( struct V_1 * V_2 )
{
V_3 = false ;
V_4 = 0 ;
F_2 ( & V_2 -> V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_6 ) ;
V_7 = V_2 ;
F_1 ( V_2 ) ;
F_5 () ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_6 ) ;
F_7 () ;
F_1 ( V_2 ) ;
V_7 = NULL ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_6 ) ;
F_1 ( V_2 ) ;
}
static void F_9 ( struct V_8 * V_9 , const struct V_10 * V_11 )
{
int V_12 ;
T_1 V_13 , V_14 ;
const struct V_15 * V_16 = F_10 ( V_11 ) ;
F_11 ( V_9 , L_2 ,
V_11 -> V_17 -> V_18 , V_11 -> V_19 ,
V_11 -> V_20 , V_11 -> V_21 , V_11 -> V_22 ) ;
for ( V_12 = 0 ; V_12 < 7 ; V_12 ++ ) {
F_12 ( V_11 , V_12 , & V_11 -> V_23 [ V_12 ] , & V_13 , & V_14 ) ;
F_11 ( V_9 , L_3 ,
( unsigned long long ) ( V_13 |
( V_11 -> V_23 [ V_12 ] . V_24 & V_25 ) ) ) ;
}
for ( V_12 = 0 ; V_12 < 7 ; V_12 ++ ) {
F_12 ( V_11 , V_12 , & V_11 -> V_23 [ V_12 ] , & V_13 , & V_14 ) ;
F_11 ( V_9 , L_3 ,
V_11 -> V_23 [ V_12 ] . V_13 < V_11 -> V_23 [ V_12 ] . V_14 ?
( unsigned long long ) ( V_14 - V_13 ) + 1 : 0 ) ;
}
if ( V_16 )
F_11 ( V_9 , L_4 , V_16 -> V_26 ) ;
else
F_13 ( V_9 , L_5 ) ;
}
static void F_14 ( struct V_27 * V_28 )
{
if ( ! V_28 )
return;
F_15 ( V_28 -> V_11 ) ;
F_16 ( V_28 ) ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_27 * V_28 ;
struct V_8 * V_9 = & V_30 -> V_31 ;
F_13 ( V_9 , L_6 ) ;
V_28 = F_18 ( sizeof( * V_28 ) , V_32 ) ;
if ( ! V_28 )
return;
V_28 -> V_11 = F_19 ( V_33 , V_33 , NULL ) ;
V_30 -> V_34 = V_28 ;
}
static void F_20 ( struct V_29 * V_30 )
{
struct V_27 * V_28 = V_30 -> V_34 ;
F_14 ( V_28 ) ;
V_30 -> V_34 = NULL ;
}
static unsigned long F_21 ( struct V_29 * V_30 )
{
unsigned long V_35 = F_22 ( & V_36 , 0 ) ;
unsigned long V_37 = F_23 ( V_30 -> V_5 -> V_38 ) ;
if ( V_37 > V_4 )
V_35 += V_37 - V_4 ;
V_4 = V_37 ;
return V_35 ;
}
static T_2 F_24 ( struct V_29 * V_30 , struct V_39 * V_40 ,
char T_3 * V_41 , T_4 V_35 , T_5 * V_42 )
{
T_2 V_43 ;
struct V_27 * V_28 = V_30 -> V_34 ;
struct V_8 * V_9 = & V_30 -> V_31 ;
unsigned long V_44 ;
V_44 = F_21 ( V_30 ) ;
if ( V_44 ) {
F_11 ( V_9 , L_7 , V_44 ) ;
if ( ! V_3 )
F_25 ( L_8 ) ;
V_3 = true ;
goto V_45;
}
if ( ! V_28 )
return 0 ;
F_9 ( V_9 , V_28 -> V_11 ) ;
V_28 -> V_11 = F_19 ( V_33 , V_33 , V_28 -> V_11 ) ;
if ( ! V_28 -> V_11 ) {
F_14 ( V_28 ) ;
V_30 -> V_34 = NULL ;
}
V_45:
V_43 = F_26 ( V_9 , V_41 , V_35 ) ;
return ( V_43 == - V_46 ) ? 0 : V_43 ;
}
static enum V_47 F_27 ( struct V_29 * V_30 )
{
struct V_48 * V_49 = V_30 -> V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_8 * V_9 = & V_30 -> V_31 ;
unsigned long long V_55 = F_28 ( V_30 -> V_56 ) ;
unsigned long V_57 = F_29 ( V_55 , V_58 ) ;
unsigned V_59 = ( unsigned long ) V_55 ;
F_30 ( V_52 , V_49 ) ;
V_54 = & V_52 -> V_54 ;
switch ( V_54 -> V_60 ) {
case V_61 :
F_11 ( V_9 ,
L_9 ,
V_54 -> V_62 , V_59 , V_57 , V_54 -> V_63 ,
( unsigned long long ) V_54 -> V_64 ,
V_54 -> V_65 , V_54 -> V_66 , 0 ) ;
break;
case V_67 :
F_11 ( V_9 ,
L_10 ,
V_54 -> V_62 , V_59 , V_57 , V_54 -> V_63 ,
( unsigned long long ) V_54 -> V_64 ,
V_54 -> V_65 , V_54 -> V_66 , 0 ) ;
break;
case V_68 :
F_11 ( V_9 ,
L_11
L_12 ,
V_59 , V_57 , V_54 -> V_63 ,
( unsigned long long ) V_54 -> V_64 ,
( V_54 -> V_65 >> 16 ) & 0xff , ( V_54 -> V_65 >> 8 ) & 0xff ,
( V_54 -> V_65 >> 0 ) & 0xff , V_54 -> V_66 , 0 ) ;
break;
default:
F_13 ( V_9 , L_13 ) ;
break;
}
return F_31 ( V_9 ) ;
}
static enum V_47 F_32 ( struct V_29 * V_30 )
{
struct V_48 * V_49 = V_30 -> V_50 ;
struct V_69 * V_52 ;
struct V_70 * V_71 ;
struct V_8 * V_9 = & V_30 -> V_31 ;
unsigned long long V_55 = F_28 ( V_30 -> V_56 ) ;
unsigned long V_57 = F_29 ( V_55 , V_58 ) ;
unsigned V_59 = ( unsigned long ) V_55 ;
F_30 ( V_52 , V_49 ) ;
V_71 = & V_52 -> V_72 ;
switch ( V_71 -> V_60 ) {
case V_73 :
F_11 ( V_9 ,
L_14 ,
V_59 , V_57 , V_71 -> V_63 ,
( unsigned long long ) V_71 -> V_64 , V_71 -> V_74 , V_71 -> V_75 ,
0UL , 0 ) ;
break;
case V_76 :
F_11 ( V_9 ,
L_15 ,
V_59 , V_57 , V_71 -> V_63 , 0UL , 0 ) ;
break;
default:
F_13 ( V_9 , L_16 ) ;
break;
}
return F_31 ( V_9 ) ;
}
static enum V_47 F_33 ( struct V_29 * V_30 )
{
struct V_48 * V_49 = V_30 -> V_50 ;
struct V_77 * V_78 = (struct V_77 * ) V_49 ;
const char * V_79 = V_78 -> V_80 ;
struct V_8 * V_9 = & V_30 -> V_31 ;
unsigned long long V_55 = F_28 ( V_30 -> V_56 ) ;
unsigned long V_57 = F_29 ( V_55 , V_58 ) ;
unsigned V_59 = ( unsigned long ) V_55 ;
F_11 ( V_9 , L_17 , V_59 , V_57 , V_79 ) ;
return F_31 ( V_9 ) ;
}
static enum V_47 F_34 ( struct V_29 * V_30 )
{
switch ( V_30 -> V_50 -> type ) {
case V_81 :
return F_27 ( V_30 ) ;
case V_82 :
return F_32 ( V_30 ) ;
case V_83 :
return F_33 ( V_30 ) ;
default:
return V_84 ;
}
}
T_6 static int F_35 ( void )
{
return F_36 ( & V_85 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
struct V_53 * V_54 )
{
struct V_88 * V_89 = & V_90 ;
struct V_91 * V_38 = V_2 -> V_5 . V_38 ;
struct V_92 * V_93 ;
struct V_51 * V_49 ;
int V_66 = F_38 () ;
V_93 = F_39 ( V_38 , V_81 ,
sizeof( * V_49 ) , 0 , V_66 ) ;
if ( ! V_93 ) {
F_40 ( & V_36 ) ;
return;
}
V_49 = F_41 ( V_93 ) ;
V_49 -> V_54 = * V_54 ;
if ( ! F_42 ( V_89 , V_49 , V_38 , V_93 ) )
F_43 ( V_2 , V_38 , V_93 , 0 , V_66 ) ;
}
void F_44 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_7 ;
struct V_86 * V_87 = F_45 ( V_2 -> V_5 . V_87 , F_46 () ) ;
F_37 ( V_2 , V_87 , V_54 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
struct V_70 * V_72 )
{
struct V_88 * V_89 = & V_94 ;
struct V_91 * V_38 = V_2 -> V_5 . V_38 ;
struct V_92 * V_93 ;
struct V_69 * V_49 ;
int V_66 = F_38 () ;
V_93 = F_39 ( V_38 , V_82 ,
sizeof( * V_49 ) , 0 , V_66 ) ;
if ( ! V_93 ) {
F_40 ( & V_36 ) ;
return;
}
V_49 = F_41 ( V_93 ) ;
V_49 -> V_72 = * V_72 ;
if ( ! F_42 ( V_89 , V_49 , V_38 , V_93 ) )
F_43 ( V_2 , V_38 , V_93 , 0 , V_66 ) ;
}
void F_48 ( struct V_70 * V_72 )
{
struct V_1 * V_2 = V_7 ;
struct V_86 * V_87 ;
F_49 () ;
V_87 = F_45 ( V_2 -> V_5 . V_87 , F_46 () ) ;
F_47 ( V_2 , V_87 , V_72 ) ;
F_50 () ;
}
int F_51 ( const char * V_95 , T_7 args )
{
return F_52 ( 0 , V_95 , args ) ;
}
