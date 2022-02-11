static void F_1 ( struct V_1 * V_2 )
{
V_3 = false ;
V_4 = 0 ;
F_2 ( V_2 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_5 ) ;
V_6 = V_2 ;
F_1 ( V_2 ) ;
F_5 () ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_5 ) ;
F_7 () ;
F_1 ( V_2 ) ;
V_6 = NULL ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_4 ( L_1 , V_5 ) ;
F_1 ( V_2 ) ;
}
static int F_9 ( struct V_7 * V_8 , const struct V_9 * V_10 )
{
int V_11 = 0 ;
int V_12 ;
T_1 V_13 , V_14 ;
const struct V_15 * V_16 = F_10 ( V_10 ) ;
V_11 += F_11 ( V_8 , L_2 ,
V_10 -> V_17 -> V_18 , V_10 -> V_19 ,
V_10 -> V_20 , V_10 -> V_21 , V_10 -> V_22 ) ;
for ( V_12 = 0 ; V_12 < 7 ; V_12 ++ ) {
F_12 ( V_10 , V_12 , & V_10 -> V_23 [ V_12 ] , & V_13 , & V_14 ) ;
V_11 += F_11 ( V_8 , L_3 ,
( unsigned long long ) ( V_13 |
( V_10 -> V_23 [ V_12 ] . V_24 & V_25 ) ) ) ;
}
for ( V_12 = 0 ; V_12 < 7 ; V_12 ++ ) {
F_12 ( V_10 , V_12 , & V_10 -> V_23 [ V_12 ] , & V_13 , & V_14 ) ;
V_11 += F_11 ( V_8 , L_3 ,
V_10 -> V_23 [ V_12 ] . V_13 < V_10 -> V_23 [ V_12 ] . V_14 ?
( unsigned long long ) ( V_14 - V_13 ) + 1 : 0 ) ;
}
if ( V_16 )
V_11 += F_11 ( V_8 , L_4 , V_16 -> V_26 ) ;
else
V_11 += F_11 ( V_8 , L_5 ) ;
return V_11 ;
}
static void F_13 ( struct V_27 * V_28 )
{
if ( ! V_28 )
return;
F_14 ( V_28 -> V_10 ) ;
F_15 ( V_28 ) ;
}
static void F_16 ( struct V_29 * V_30 )
{
struct V_27 * V_28 ;
struct V_7 * V_8 = & V_30 -> V_31 ;
F_11 ( V_8 , L_6 ) ;
V_28 = F_17 ( sizeof( * V_28 ) , V_32 ) ;
if ( ! V_28 )
return;
V_28 -> V_10 = F_18 ( V_33 , V_33 , NULL ) ;
V_30 -> V_34 = V_28 ;
}
static void F_19 ( struct V_29 * V_30 )
{
struct V_27 * V_28 = V_30 -> V_34 ;
F_13 ( V_28 ) ;
V_30 -> V_34 = NULL ;
}
static unsigned long F_20 ( struct V_29 * V_30 )
{
unsigned long V_35 = F_21 ( & V_36 , 0 ) ;
unsigned long V_37 = F_22 ( V_30 -> V_2 -> V_38 ) ;
if ( V_37 > V_4 )
V_35 += V_37 - V_4 ;
V_4 = V_37 ;
return V_35 ;
}
static T_2 F_23 ( struct V_29 * V_30 , struct V_39 * V_40 ,
char T_3 * V_41 , T_4 V_35 , T_5 * V_42 )
{
T_2 V_11 ;
struct V_27 * V_28 = V_30 -> V_34 ;
struct V_7 * V_8 = & V_30 -> V_31 ;
unsigned long V_43 ;
V_43 = F_20 ( V_30 ) ;
if ( V_43 ) {
F_11 ( V_8 , L_7 , V_43 ) ;
if ( ! V_3 )
F_24 ( L_8 ) ;
V_3 = true ;
goto V_44;
}
if ( ! V_28 )
return 0 ;
F_9 ( V_8 , V_28 -> V_10 ) ;
V_28 -> V_10 = F_18 ( V_33 , V_33 , V_28 -> V_10 ) ;
if ( ! V_28 -> V_10 ) {
F_13 ( V_28 ) ;
V_30 -> V_34 = NULL ;
}
V_44:
V_11 = F_25 ( V_8 , V_41 , V_35 ) ;
return ( V_11 == - V_45 ) ? 0 : V_11 ;
}
static enum V_46 F_26 ( struct V_29 * V_30 )
{
struct V_47 * V_48 = V_30 -> V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_7 * V_8 = & V_30 -> V_31 ;
unsigned long long V_54 = F_27 ( V_30 -> V_55 ) ;
unsigned long V_56 = F_28 ( V_54 , V_57 ) ;
unsigned V_58 = ( unsigned long ) V_54 ;
int V_11 = 1 ;
F_29 ( V_51 , V_48 ) ;
V_53 = & V_51 -> V_53 ;
switch ( V_53 -> V_59 ) {
case V_60 :
V_11 = F_11 ( V_8 ,
L_9 ,
V_53 -> V_61 , V_58 , V_56 , V_53 -> V_62 ,
( unsigned long long ) V_53 -> V_63 ,
V_53 -> V_64 , V_53 -> V_65 , 0 ) ;
break;
case V_66 :
V_11 = F_11 ( V_8 ,
L_10 ,
V_53 -> V_61 , V_58 , V_56 , V_53 -> V_62 ,
( unsigned long long ) V_53 -> V_63 ,
V_53 -> V_64 , V_53 -> V_65 , 0 ) ;
break;
case V_67 :
V_11 = F_11 ( V_8 ,
L_11
L_12 ,
V_58 , V_56 , V_53 -> V_62 ,
( unsigned long long ) V_53 -> V_63 ,
( V_53 -> V_64 >> 16 ) & 0xff , ( V_53 -> V_64 >> 8 ) & 0xff ,
( V_53 -> V_64 >> 0 ) & 0xff , V_53 -> V_65 , 0 ) ;
break;
default:
V_11 = F_11 ( V_8 , L_13 ) ;
break;
}
if ( V_11 )
return V_68 ;
return V_69 ;
}
static enum V_46 F_30 ( struct V_29 * V_30 )
{
struct V_47 * V_48 = V_30 -> V_49 ;
struct V_70 * V_51 ;
struct V_71 * V_72 ;
struct V_7 * V_8 = & V_30 -> V_31 ;
unsigned long long V_54 = F_27 ( V_30 -> V_55 ) ;
unsigned long V_56 = F_28 ( V_54 , V_57 ) ;
unsigned V_58 = ( unsigned long ) V_54 ;
int V_11 ;
F_29 ( V_51 , V_48 ) ;
V_72 = & V_51 -> V_73 ;
switch ( V_72 -> V_59 ) {
case V_74 :
V_11 = F_11 ( V_8 ,
L_14 ,
V_58 , V_56 , V_72 -> V_62 ,
( unsigned long long ) V_72 -> V_63 , V_72 -> V_75 , V_72 -> V_76 ,
0UL , 0 ) ;
break;
case V_77 :
V_11 = F_11 ( V_8 ,
L_15 ,
V_58 , V_56 , V_72 -> V_62 , 0UL , 0 ) ;
break;
default:
V_11 = F_11 ( V_8 , L_16 ) ;
break;
}
if ( V_11 )
return V_68 ;
return V_69 ;
}
static enum V_46 F_31 ( struct V_29 * V_30 )
{
struct V_47 * V_48 = V_30 -> V_49 ;
struct V_78 * V_79 = (struct V_78 * ) V_48 ;
const char * V_80 = V_79 -> V_81 ;
struct V_7 * V_8 = & V_30 -> V_31 ;
unsigned long long V_54 = F_27 ( V_30 -> V_55 ) ;
unsigned long V_56 = F_28 ( V_54 , V_57 ) ;
unsigned V_58 = ( unsigned long ) V_54 ;
int V_11 ;
V_11 = F_11 ( V_8 , L_17 , V_58 , V_56 , V_80 ) ;
if ( ! V_11 )
return V_69 ;
return V_68 ;
}
static enum V_46 F_32 ( struct V_29 * V_30 )
{
switch ( V_30 -> V_49 -> type ) {
case V_82 :
return F_26 ( V_30 ) ;
case V_83 :
return F_30 ( V_30 ) ;
case V_84 :
return F_31 ( V_30 ) ;
default:
return V_68 ;
}
}
T_6 static int F_33 ( void )
{
return F_34 ( & V_85 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
struct V_52 * V_53 )
{
struct V_88 * V_89 = & V_90 ;
struct V_91 * V_38 = V_2 -> V_38 ;
struct V_92 * V_93 ;
struct V_50 * V_48 ;
int V_65 = F_36 () ;
V_93 = F_37 ( V_38 , V_82 ,
sizeof( * V_48 ) , 0 , V_65 ) ;
if ( ! V_93 ) {
F_38 ( & V_36 ) ;
return;
}
V_48 = F_39 ( V_93 ) ;
V_48 -> V_53 = * V_53 ;
if ( ! F_40 ( V_89 , V_48 , V_38 , V_93 ) )
F_41 ( V_38 , V_93 , 0 , V_65 ) ;
}
void F_42 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_6 ;
struct V_86 * V_87 = V_2 -> V_87 [ F_43 () ] ;
F_35 ( V_2 , V_87 , V_53 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
struct V_71 * V_73 )
{
struct V_88 * V_89 = & V_94 ;
struct V_91 * V_38 = V_2 -> V_38 ;
struct V_92 * V_93 ;
struct V_70 * V_48 ;
int V_65 = F_36 () ;
V_93 = F_37 ( V_38 , V_83 ,
sizeof( * V_48 ) , 0 , V_65 ) ;
if ( ! V_93 ) {
F_38 ( & V_36 ) ;
return;
}
V_48 = F_39 ( V_93 ) ;
V_48 -> V_73 = * V_73 ;
if ( ! F_40 ( V_89 , V_48 , V_38 , V_93 ) )
F_41 ( V_38 , V_93 , 0 , V_65 ) ;
}
void F_45 ( struct V_71 * V_73 )
{
struct V_1 * V_2 = V_6 ;
struct V_86 * V_87 ;
F_46 () ;
V_87 = V_2 -> V_87 [ F_43 () ] ;
F_44 ( V_2 , V_87 , V_73 ) ;
F_47 () ;
}
int F_48 ( const char * V_95 , T_7 args )
{
return F_49 ( 0 , V_95 , args ) ;
}
