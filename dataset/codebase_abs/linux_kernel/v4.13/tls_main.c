int F_1 ( struct V_1 * V_2 , long * V_3 )
{
int V_4 = 0 ;
F_2 ( V_5 , V_6 ) ;
F_3 ( F_4 ( V_2 ) , & V_5 ) ;
while ( 1 ) {
if ( ! * V_3 ) {
V_4 = - V_7 ;
break;
}
if ( F_5 ( V_8 ) ) {
V_4 = F_6 ( * V_3 ) ;
break;
}
if ( F_7 ( V_2 , V_3 , ! V_2 -> V_9 , & V_5 ) )
break;
}
F_8 ( F_4 ( V_2 ) , & V_5 ) ;
return V_4 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
T_1 V_14 ,
int V_15 )
{
int V_16 = V_15 | V_17 ;
int V_18 = 0 ;
struct V_19 * V_20 ;
T_2 V_21 ;
int V_22 = V_14 ;
V_21 = V_13 -> V_23 - V_22 ;
V_22 += V_13 -> V_22 ;
while ( 1 ) {
if ( F_10 ( V_13 ) )
V_16 = V_15 ;
F_11 ( V_2 ) ;
V_20 = F_12 ( V_13 ) ;
V_24:
V_18 = F_13 ( V_2 , V_20 , V_22 , V_21 , V_16 ) ;
if ( V_18 != V_21 ) {
if ( V_18 > 0 ) {
V_22 += V_18 ;
V_21 -= V_18 ;
goto V_24;
}
V_22 -= V_13 -> V_22 ;
V_11 -> V_25 = V_22 ;
V_11 -> V_26 = ( void * ) V_13 ;
return V_18 ;
}
F_14 ( V_20 ) ;
F_15 ( V_2 , V_13 -> V_23 ) ;
V_13 = F_16 ( V_13 ) ;
if ( ! V_13 )
break;
V_22 = V_13 -> V_22 ;
V_21 = V_13 -> V_23 ;
}
F_17 ( V_27 , & V_11 -> V_15 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_15 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
if ( F_20 ( V_11 ) )
return V_11 -> V_28 ( V_2 , V_15 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , struct V_29 * V_30 ,
unsigned char * V_31 )
{
struct V_32 * V_33 ;
int V_4 = - V_34 ;
F_22 (cmsg, msg) {
if ( ! F_23 ( V_30 , V_33 ) )
return - V_34 ;
if ( V_33 -> V_35 != V_36 )
continue;
switch ( V_33 -> V_37 ) {
case V_38 :
if ( V_33 -> V_39 < F_24 ( sizeof( * V_31 ) ) )
return - V_34 ;
if ( V_30 -> V_40 & V_41 )
return - V_34 ;
V_4 = F_18 ( V_2 , V_30 -> V_40 ) ;
if ( V_4 )
return V_4 ;
* V_31 = * ( unsigned char * ) F_25 ( V_33 ) ;
V_4 = 0 ;
break;
default:
return - V_34 ;
}
}
return V_4 ;
}
int F_26 ( struct V_1 * V_2 , struct V_10 * V_11 ,
int V_15 , long * V_3 )
{
struct V_12 * V_13 ;
T_1 V_22 ;
if ( ! F_27 ( V_11 ) )
return V_11 -> V_28 ( V_2 , V_15 ) ;
V_13 = V_11 -> V_26 ;
V_22 = V_11 -> V_25 ;
V_11 -> V_26 = NULL ;
return F_9 ( V_2 , V_11 , V_13 , V_22 , V_15 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
if ( ! V_2 -> V_9 && F_29 ( V_11 ) ) {
T_3 V_42 = V_2 -> V_42 ;
int V_4 ;
long V_3 = 0 ;
V_2 -> V_42 = V_43 ;
V_4 = F_26 ( V_2 , V_11 ,
V_44 |
V_45 ,
& V_3 ) ;
V_2 -> V_42 = V_42 ;
if ( V_4 < 0 )
return;
}
V_11 -> V_46 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 , long V_47 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
long V_3 = F_31 ( V_2 , 0 ) ;
void (* F_32)( struct V_1 * V_2 , long V_47 );
F_33 ( V_2 ) ;
if ( ! F_34 ( V_2 , V_11 , 0 , & V_3 ) )
F_18 ( V_2 , 0 ) ;
if ( V_11 -> V_26 ) {
struct V_12 * V_13 = V_11 -> V_26 ;
while ( 1 ) {
F_14 ( F_12 ( V_13 ) ) ;
F_15 ( V_2 , V_13 -> V_23 ) ;
if ( F_10 ( V_13 ) )
break;
V_13 ++ ;
}
}
V_11 -> V_48 ( V_2 ) ;
F_35 ( V_11 -> V_49 ) ;
F_35 ( V_11 -> V_50 ) ;
F_32 = V_11 -> F_32 ;
F_35 ( V_11 ) ;
F_36 ( V_2 ) ;
F_32 ( V_2 , V_47 ) ;
}
static int F_37 ( struct V_1 * V_2 , char T_4 * V_51 ,
int T_4 * V_52 )
{
int V_4 = 0 ;
struct V_10 * V_11 = F_19 ( V_2 ) ;
struct V_53 * V_54 ;
int V_55 ;
if ( F_38 ( V_55 , V_52 ) )
return - V_56 ;
if ( ! V_51 || ( V_55 < sizeof( * V_54 ) ) ) {
V_4 = - V_34 ;
goto V_57;
}
if ( ! V_11 ) {
V_4 = - V_58 ;
goto V_57;
}
V_54 = & V_11 -> V_59 ;
if ( ! F_39 ( V_54 ) ) {
V_4 = - V_58 ;
goto V_57;
}
if ( V_55 == sizeof( * V_54 ) ) {
if ( F_40 ( V_51 , V_54 , sizeof( * V_54 ) ) )
V_4 = - V_56 ;
goto V_57;
}
switch ( V_54 -> V_60 ) {
case V_61 : {
struct V_62 *
V_63 =
F_41 ( V_54 ,
struct V_62 ,
V_64 ) ;
if ( V_55 != sizeof( * V_63 ) ) {
V_4 = - V_34 ;
goto V_57;
}
F_33 ( V_2 ) ;
memcpy ( V_63 -> V_50 , V_11 -> V_50 ,
V_65 ) ;
F_36 ( V_2 ) ;
if ( F_40 ( V_51 ,
V_63 ,
sizeof( * V_63 ) ) )
V_4 = - V_56 ;
break;
}
default:
V_4 = - V_34 ;
}
V_57:
return V_4 ;
}
static int F_42 ( struct V_1 * V_2 , int V_66 ,
char T_4 * V_51 , int T_4 * V_52 )
{
int V_4 = 0 ;
switch ( V_66 ) {
case V_67 :
V_4 = F_37 ( V_2 , V_51 , V_52 ) ;
break;
default:
V_4 = - V_68 ;
break;
}
return V_4 ;
}
static int F_43 ( struct V_1 * V_2 , int V_69 , int V_66 ,
char T_4 * V_51 , int T_4 * V_52 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
if ( V_69 != V_36 )
return V_11 -> V_70 ( V_2 , V_69 , V_66 , V_51 , V_52 ) ;
return F_42 ( V_2 , V_66 , V_51 , V_52 ) ;
}
static int F_44 ( struct V_1 * V_2 , char T_4 * V_51 ,
unsigned int V_52 )
{
struct V_53 * V_54 , V_71 ;
struct V_10 * V_11 = F_19 ( V_2 ) ;
struct V_72 * V_73 = NULL ;
int V_4 = 0 ;
if ( ! V_51 || ( V_52 < sizeof( * V_54 ) ) ) {
V_4 = - V_34 ;
goto V_57;
}
V_4 = F_45 ( & V_71 , V_51 , sizeof( * V_54 ) ) ;
if ( V_4 ) {
V_4 = - V_56 ;
goto V_57;
}
if ( V_71 . V_74 != V_75 ) {
V_4 = - V_76 ;
goto V_57;
}
V_54 = & V_11 -> V_59 ;
if ( F_39 ( V_54 ) )
goto V_57;
switch ( V_71 . V_60 ) {
case V_61 : {
if ( V_52 != sizeof( struct V_62 ) ) {
V_4 = - V_34 ;
goto V_57;
}
V_4 = F_45 (
V_54 ,
V_51 ,
sizeof( struct V_62 ) ) ;
if ( V_4 ) {
V_4 = - V_56 ;
goto V_77;
}
break;
}
default:
V_4 = - V_34 ;
goto V_57;
}
V_11 -> V_46 = V_2 -> V_46 ;
V_2 -> V_46 = F_28 ;
V_11 -> F_32 = V_2 -> V_78 -> V_79 ;
V_4 = F_46 ( V_2 , V_11 ) ;
V_73 = & V_80 ;
if ( V_4 )
goto V_77;
V_2 -> V_78 = V_73 ;
goto V_57;
V_77:
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_57:
return V_4 ;
}
static int F_47 ( struct V_1 * V_2 , int V_66 ,
char T_4 * V_51 , unsigned int V_52 )
{
int V_4 = 0 ;
switch ( V_66 ) {
case V_67 :
F_33 ( V_2 ) ;
V_4 = F_44 ( V_2 , V_51 , V_52 ) ;
F_36 ( V_2 ) ;
break;
default:
V_4 = - V_68 ;
break;
}
return V_4 ;
}
static int F_48 ( struct V_1 * V_2 , int V_69 , int V_66 ,
char T_4 * V_51 , unsigned int V_52 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
if ( V_69 != V_36 )
return V_11 -> V_81 ( V_2 , V_69 , V_66 , V_51 , V_52 ) ;
return F_47 ( V_2 , V_66 , V_51 , V_52 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_50 ( V_2 ) ;
struct V_10 * V_11 ;
int V_4 = 0 ;
V_11 = F_51 ( sizeof( * V_11 ) , V_84 ) ;
if ( ! V_11 ) {
V_4 = - V_85 ;
goto V_57;
}
V_83 -> V_86 = V_11 ;
V_11 -> V_81 = V_2 -> V_78 -> V_81 ;
V_11 -> V_70 = V_2 -> V_78 -> V_70 ;
V_2 -> V_78 = & V_87 ;
V_57:
return V_4 ;
}
static int T_5 F_52 ( void )
{
V_87 = V_88 ;
V_87 . V_81 = F_48 ;
V_87 . V_70 = F_43 ;
V_80 = V_87 ;
V_80 . V_89 = V_90 ;
V_80 . V_91 = V_92 ;
V_80 . V_79 = F_30 ;
F_53 ( & V_93 ) ;
return 0 ;
}
static void T_6 F_54 ( void )
{
F_55 ( & V_93 ) ;
}
