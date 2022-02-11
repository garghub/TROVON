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
static int F_9 ( struct V_8 * V_9 , const struct V_10 * V_11 )
{
int V_12 = 0 ;
int V_13 ;
T_1 V_14 , V_15 ;
const struct V_16 * V_17 = F_10 ( V_11 ) ;
V_12 += F_11 ( V_9 , L_2 ,
V_11 -> V_18 -> V_19 , V_11 -> V_20 ,
V_11 -> V_21 , V_11 -> V_22 , V_11 -> V_23 ) ;
for ( V_13 = 0 ; V_13 < 7 ; V_13 ++ ) {
F_12 ( V_11 , V_13 , & V_11 -> V_24 [ V_13 ] , & V_14 , & V_15 ) ;
V_12 += F_11 ( V_9 , L_3 ,
( unsigned long long ) ( V_14 |
( V_11 -> V_24 [ V_13 ] . V_25 & V_26 ) ) ) ;
}
for ( V_13 = 0 ; V_13 < 7 ; V_13 ++ ) {
F_12 ( V_11 , V_13 , & V_11 -> V_24 [ V_13 ] , & V_14 , & V_15 ) ;
V_12 += F_11 ( V_9 , L_3 ,
V_11 -> V_24 [ V_13 ] . V_14 < V_11 -> V_24 [ V_13 ] . V_15 ?
( unsigned long long ) ( V_15 - V_14 ) + 1 : 0 ) ;
}
if ( V_17 )
V_12 += F_11 ( V_9 , L_4 , V_17 -> V_27 ) ;
else
V_12 += F_11 ( V_9 , L_5 ) ;
return V_12 ;
}
static void F_13 ( struct V_28 * V_29 )
{
if ( ! V_29 )
return;
F_14 ( V_29 -> V_11 ) ;
F_15 ( V_29 ) ;
}
static void F_16 ( struct V_30 * V_31 )
{
struct V_28 * V_29 ;
struct V_8 * V_9 = & V_31 -> V_32 ;
F_11 ( V_9 , L_6 ) ;
V_29 = F_17 ( sizeof( * V_29 ) , V_33 ) ;
if ( ! V_29 )
return;
V_29 -> V_11 = F_18 ( V_34 , V_34 , NULL ) ;
V_31 -> V_35 = V_29 ;
}
static void F_19 ( struct V_30 * V_31 )
{
struct V_28 * V_29 = V_31 -> V_35 ;
F_13 ( V_29 ) ;
V_31 -> V_35 = NULL ;
}
static unsigned long F_20 ( struct V_30 * V_31 )
{
unsigned long V_36 = F_21 ( & V_37 , 0 ) ;
unsigned long V_38 = F_22 ( V_31 -> V_5 -> V_39 ) ;
if ( V_38 > V_4 )
V_36 += V_38 - V_4 ;
V_4 = V_38 ;
return V_36 ;
}
static T_2 F_23 ( struct V_30 * V_31 , struct V_40 * V_41 ,
char T_3 * V_42 , T_4 V_36 , T_5 * V_43 )
{
T_2 V_12 ;
struct V_28 * V_29 = V_31 -> V_35 ;
struct V_8 * V_9 = & V_31 -> V_32 ;
unsigned long V_44 ;
V_44 = F_20 ( V_31 ) ;
if ( V_44 ) {
F_11 ( V_9 , L_7 , V_44 ) ;
if ( ! V_3 )
F_24 ( L_8 ) ;
V_3 = true ;
goto V_45;
}
if ( ! V_29 )
return 0 ;
F_9 ( V_9 , V_29 -> V_11 ) ;
V_29 -> V_11 = F_18 ( V_34 , V_34 , V_29 -> V_11 ) ;
if ( ! V_29 -> V_11 ) {
F_13 ( V_29 ) ;
V_31 -> V_35 = NULL ;
}
V_45:
V_12 = F_25 ( V_9 , V_42 , V_36 ) ;
return ( V_12 == - V_46 ) ? 0 : V_12 ;
}
static enum V_47 F_26 ( struct V_30 * V_31 )
{
struct V_48 * V_49 = V_31 -> V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_8 * V_9 = & V_31 -> V_32 ;
unsigned long long V_55 = F_27 ( V_31 -> V_56 ) ;
unsigned long V_57 = F_28 ( V_55 , V_58 ) ;
unsigned V_59 = ( unsigned long ) V_55 ;
int V_12 = 1 ;
F_29 ( V_52 , V_49 ) ;
V_54 = & V_52 -> V_54 ;
switch ( V_54 -> V_60 ) {
case V_61 :
V_12 = F_11 ( V_9 ,
L_9 ,
V_54 -> V_62 , V_59 , V_57 , V_54 -> V_63 ,
( unsigned long long ) V_54 -> V_64 ,
V_54 -> V_65 , V_54 -> V_66 , 0 ) ;
break;
case V_67 :
V_12 = F_11 ( V_9 ,
L_10 ,
V_54 -> V_62 , V_59 , V_57 , V_54 -> V_63 ,
( unsigned long long ) V_54 -> V_64 ,
V_54 -> V_65 , V_54 -> V_66 , 0 ) ;
break;
case V_68 :
V_12 = F_11 ( V_9 ,
L_11
L_12 ,
V_59 , V_57 , V_54 -> V_63 ,
( unsigned long long ) V_54 -> V_64 ,
( V_54 -> V_65 >> 16 ) & 0xff , ( V_54 -> V_65 >> 8 ) & 0xff ,
( V_54 -> V_65 >> 0 ) & 0xff , V_54 -> V_66 , 0 ) ;
break;
default:
V_12 = F_11 ( V_9 , L_13 ) ;
break;
}
if ( V_12 )
return V_69 ;
return V_70 ;
}
static enum V_47 F_30 ( struct V_30 * V_31 )
{
struct V_48 * V_49 = V_31 -> V_50 ;
struct V_71 * V_52 ;
struct V_72 * V_73 ;
struct V_8 * V_9 = & V_31 -> V_32 ;
unsigned long long V_55 = F_27 ( V_31 -> V_56 ) ;
unsigned long V_57 = F_28 ( V_55 , V_58 ) ;
unsigned V_59 = ( unsigned long ) V_55 ;
int V_12 ;
F_29 ( V_52 , V_49 ) ;
V_73 = & V_52 -> V_74 ;
switch ( V_73 -> V_60 ) {
case V_75 :
V_12 = F_11 ( V_9 ,
L_14 ,
V_59 , V_57 , V_73 -> V_63 ,
( unsigned long long ) V_73 -> V_64 , V_73 -> V_76 , V_73 -> V_77 ,
0UL , 0 ) ;
break;
case V_78 :
V_12 = F_11 ( V_9 ,
L_15 ,
V_59 , V_57 , V_73 -> V_63 , 0UL , 0 ) ;
break;
default:
V_12 = F_11 ( V_9 , L_16 ) ;
break;
}
if ( V_12 )
return V_69 ;
return V_70 ;
}
static enum V_47 F_31 ( struct V_30 * V_31 )
{
struct V_48 * V_49 = V_31 -> V_50 ;
struct V_79 * V_80 = (struct V_79 * ) V_49 ;
const char * V_81 = V_80 -> V_82 ;
struct V_8 * V_9 = & V_31 -> V_32 ;
unsigned long long V_55 = F_27 ( V_31 -> V_56 ) ;
unsigned long V_57 = F_28 ( V_55 , V_58 ) ;
unsigned V_59 = ( unsigned long ) V_55 ;
int V_12 ;
V_12 = F_11 ( V_9 , L_17 , V_59 , V_57 , V_81 ) ;
if ( ! V_12 )
return V_70 ;
return V_69 ;
}
static enum V_47 F_32 ( struct V_30 * V_31 )
{
switch ( V_31 -> V_50 -> type ) {
case V_83 :
return F_26 ( V_31 ) ;
case V_84 :
return F_30 ( V_31 ) ;
case V_85 :
return F_31 ( V_31 ) ;
default:
return V_69 ;
}
}
T_6 static int F_33 ( void )
{
return F_34 ( & V_86 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_53 * V_54 )
{
struct V_89 * V_90 = & V_91 ;
struct V_92 * V_39 = V_2 -> V_5 . V_39 ;
struct V_93 * V_94 ;
struct V_51 * V_49 ;
int V_66 = F_36 () ;
V_94 = F_37 ( V_39 , V_83 ,
sizeof( * V_49 ) , 0 , V_66 ) ;
if ( ! V_94 ) {
F_38 ( & V_37 ) ;
return;
}
V_49 = F_39 ( V_94 ) ;
V_49 -> V_54 = * V_54 ;
if ( ! F_40 ( V_90 , V_49 , V_39 , V_94 ) )
F_41 ( V_39 , V_94 , 0 , V_66 ) ;
}
void F_42 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_7 ;
struct V_87 * V_88 = F_43 ( V_2 -> V_5 . V_88 , F_44 () ) ;
F_35 ( V_2 , V_88 , V_54 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_72 * V_74 )
{
struct V_89 * V_90 = & V_95 ;
struct V_92 * V_39 = V_2 -> V_5 . V_39 ;
struct V_93 * V_94 ;
struct V_71 * V_49 ;
int V_66 = F_36 () ;
V_94 = F_37 ( V_39 , V_84 ,
sizeof( * V_49 ) , 0 , V_66 ) ;
if ( ! V_94 ) {
F_38 ( & V_37 ) ;
return;
}
V_49 = F_39 ( V_94 ) ;
V_49 -> V_74 = * V_74 ;
if ( ! F_40 ( V_90 , V_49 , V_39 , V_94 ) )
F_41 ( V_39 , V_94 , 0 , V_66 ) ;
}
void F_46 ( struct V_72 * V_74 )
{
struct V_1 * V_2 = V_7 ;
struct V_87 * V_88 ;
F_47 () ;
V_88 = F_43 ( V_2 -> V_5 . V_88 , F_44 () ) ;
F_45 ( V_2 , V_88 , V_74 ) ;
F_48 () ;
}
int F_49 ( const char * V_96 , T_7 args )
{
return F_50 ( 0 , V_96 , args ) ;
}
