static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_4 ;
F_2 ( V_4 == NULL ) ;
return ( (struct V_1 * ) V_4 -> V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned char * V_6 )
{
struct V_7 V_8 ;
int V_9 ;
V_9 = F_4 ( V_6 , V_10 , & V_8 ) ;
if ( ! V_9 ) {
F_5 ( V_11 , V_3 ,
L_1 ,
V_12 ) ;
V_9 = V_13 ;
goto V_14;
}
switch ( V_8 . V_15 ) {
case V_16 :
V_9 = V_17 ;
break;
case V_18 :
if ( ( V_8 . V_19 == 0x04 ) && ( V_8 . V_20 == 2 ) ) {
V_9 = V_21 ;
break;
}
default:
F_5 ( V_11 , V_3 ,
L_2 ,
V_12 , V_8 . V_15 , V_8 . V_19 ,
V_8 . V_20 ) ;
break;
}
V_14:
return V_9 ;
}
static int F_6 ( struct V_2 * V_3 , struct V_1 * V_22 )
{
struct V_23 * V_24 ;
int V_9 ;
V_25:
V_24 = F_7 ( V_3 -> V_26 , V_27 , V_28 ) ;
if ( ! V_24 )
return V_29 ;
V_24 -> V_30 = V_31 ;
V_24 -> V_32 |= V_33 | V_34 |
V_35 ;
V_24 -> V_36 = F_8 ( V_37 ) ;
V_24 -> V_38 [ 0 ] = V_37 ;
V_24 -> V_39 = V_40 ;
V_24 -> V_6 = V_22 -> V_6 ;
memset ( V_24 -> V_6 , 0 , V_10 ) ;
V_24 -> V_41 = 0 ;
V_9 = F_9 ( V_24 -> V_42 , NULL , V_24 , 1 ) ;
if ( V_9 == - V_43 ) {
if ( V_24 -> V_41 > 0 ) {
V_9 = F_3 ( V_3 , V_22 -> V_6 ) ;
} else {
F_5 ( V_11 , V_3 ,
L_3 ,
V_12 , V_24 -> V_44 ) ;
V_9 = V_13 ;
}
} else {
V_22 -> V_45 = V_46 ;
V_9 = V_47 ;
}
if ( V_9 == V_17 ) {
F_10 ( V_24 ) ;
goto V_25;
}
if ( V_9 == V_21 ) {
V_22 -> V_45 = V_48 ;
V_9 = V_47 ;
}
F_10 ( V_24 ) ;
return V_9 ;
}
static int F_11 ( struct V_2 * V_3 , unsigned char * V_6 )
{
struct V_7 V_8 ;
int V_49 ;
V_49 = F_4 ( V_6 , V_10 , & V_8 ) ;
if ( ! V_49 ) {
F_5 ( V_11 , V_3 ,
L_4
L_5 ,
V_12 ) ;
return V_13 ;
}
switch ( V_8 . V_15 ) {
case V_18 :
if ( ( V_8 . V_19 == 0x04 ) && ( V_8 . V_20 == 3 ) ) {
V_49 = V_50 ;
break;
}
default:
F_5 ( V_11 , V_3 ,
L_6 ,
V_12 , V_8 . V_15 , V_8 . V_19 ,
V_8 . V_20 ) ;
V_49 = V_13 ;
}
return V_49 ;
}
static void F_12 ( struct V_23 * V_24 , int error )
{
struct V_1 * V_22 = V_24 -> V_51 ;
unsigned V_52 = V_47 ;
if ( error || F_13 ( V_24 -> V_44 ) != V_53 ||
F_14 ( V_24 -> V_44 ) != V_54 ) {
F_5 ( V_11 , V_22 -> V_3 ,
L_7 ,
V_12 , V_24 -> V_44 ) ;
V_52 = V_13 ;
goto V_14;
}
if ( V_24 -> V_41 > 0 ) {
V_52 = F_11 ( V_22 -> V_3 , V_22 -> V_6 ) ;
if ( V_52 == V_50 ) {
V_52 = V_13 ;
if ( -- V_22 -> V_55 ) {
F_10 ( V_24 ) ;
V_52 = F_15 ( V_22 ) ;
if ( V_52 == V_47 )
return;
}
}
}
V_14:
V_24 -> V_51 = NULL ;
F_16 ( V_24 -> V_42 , V_24 ) ;
if ( V_22 -> V_56 ) {
V_22 -> V_56 ( V_22 -> V_57 , V_52 ) ;
V_22 -> V_56 = V_22 -> V_57 = NULL ;
}
return;
}
static int F_15 ( struct V_1 * V_22 )
{
struct V_23 * V_24 ;
V_24 = F_7 ( V_22 -> V_3 -> V_26 , V_27 , V_58 ) ;
if ( ! V_24 )
return V_29 ;
V_24 -> V_30 = V_31 ;
V_24 -> V_32 |= V_33 | V_34 |
V_35 ;
V_24 -> V_36 = F_8 ( V_59 ) ;
V_24 -> V_38 [ 0 ] = V_59 ;
V_24 -> V_38 [ 4 ] = 1 ;
V_24 -> V_39 = V_40 ;
V_24 -> V_6 = V_22 -> V_6 ;
memset ( V_24 -> V_6 , 0 , V_10 ) ;
V_24 -> V_41 = 0 ;
V_24 -> V_51 = V_22 ;
F_17 ( V_24 -> V_42 , NULL , V_24 , 1 , F_12 ) ;
return V_47 ;
}
static int F_18 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
int V_9 = V_60 ;
if ( V_22 -> V_45 != V_46 ) {
V_9 = V_61 ;
V_24 -> V_32 |= V_62 ;
}
return V_9 ;
}
static int F_19 ( struct V_2 * V_3 ,
T_1 V_63 , void * V_64 )
{
int V_9 = V_47 ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
V_9 = F_6 ( V_3 , V_22 ) ;
if ( V_9 == V_47 && V_22 -> V_45 == V_48 ) {
V_22 -> V_55 = V_22 -> V_65 ;
V_22 -> V_56 = V_63 ;
V_22 -> V_57 = V_64 ;
V_9 = F_15 ( V_22 ) ;
if ( V_9 == V_47 )
return 0 ;
V_22 -> V_56 = V_22 -> V_57 = NULL ;
}
if ( V_63 )
V_63 ( V_64 , V_9 ) ;
return 0 ;
}
static bool F_20 ( struct V_2 * V_3 )
{
int V_66 ;
if ( F_21 ( V_3 ) )
return false ;
for ( V_66 = 0 ; V_67 [ V_66 ] . V_68 ; V_66 ++ ) {
if ( ! strncmp ( V_3 -> V_68 , V_67 [ V_66 ] . V_68 ,
strlen ( V_67 [ V_66 ] . V_68 ) ) &&
! strncmp ( V_3 -> V_69 , V_67 [ V_66 ] . V_69 ,
strlen ( V_67 [ V_66 ] . V_69 ) ) ) {
return true ;
}
}
return false ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_22 ;
unsigned long V_70 ;
int V_9 ;
V_4 = F_23 ( sizeof( * V_4 )
+ sizeof( * V_22 ) , V_71 ) ;
if ( ! V_4 ) {
F_5 ( V_72 , V_3 , L_8 ,
V_12 ) ;
return 0 ;
}
V_4 -> V_73 = & V_74 ;
V_22 = (struct V_1 * ) V_4 -> V_5 ;
V_22 -> V_45 = V_75 ;
V_22 -> V_65 = V_76 ;
V_22 -> V_3 = V_3 ;
V_9 = F_6 ( V_3 , V_22 ) ;
if ( V_9 != V_47 || V_22 -> V_45 == V_75 )
goto V_77;
if ( ! F_24 ( V_78 ) )
goto V_77;
F_25 ( V_3 -> V_26 -> V_79 , V_70 ) ;
V_3 -> V_4 = V_4 ;
F_26 ( V_3 -> V_26 -> V_79 , V_70 ) ;
F_5 ( V_80 , V_3 , L_9 ,
V_12 , V_22 -> V_45 == V_46 ?
L_10 : L_11 ) ;
return 0 ;
V_77:
F_27 ( V_4 ) ;
F_5 ( V_72 , V_3 , L_12 ,
V_12 ) ;
return - V_81 ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
unsigned long V_70 ;
F_25 ( V_3 -> V_26 -> V_79 , V_70 ) ;
V_4 = V_3 -> V_4 ;
V_3 -> V_4 = NULL ;
F_26 ( V_3 -> V_26 -> V_79 , V_70 ) ;
F_29 ( V_78 ) ;
F_5 ( V_82 , V_3 , L_13 , V_12 ) ;
F_27 ( V_4 ) ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_74 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_74 ) ;
}
