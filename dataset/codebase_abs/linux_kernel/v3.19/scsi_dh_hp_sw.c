static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_5 ) ;
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
if ( F_8 ( V_24 ) )
return V_29 ;
F_9 ( V_24 ) ;
V_24 -> V_30 |= V_31 | V_32 |
V_33 ;
V_24 -> V_34 = F_10 ( V_35 ) ;
V_24 -> V_36 [ 0 ] = V_35 ;
V_24 -> V_37 = V_38 ;
V_24 -> V_6 = V_22 -> V_6 ;
memset ( V_24 -> V_6 , 0 , V_10 ) ;
V_24 -> V_39 = 0 ;
V_9 = F_11 ( V_24 -> V_40 , NULL , V_24 , 1 ) ;
if ( V_9 == - V_41 ) {
if ( V_24 -> V_39 > 0 ) {
V_9 = F_3 ( V_3 , V_22 -> V_6 ) ;
} else {
F_5 ( V_11 , V_3 ,
L_3 ,
V_12 , V_24 -> V_42 ) ;
V_9 = V_13 ;
}
} else {
V_22 -> V_43 = V_44 ;
V_9 = V_45 ;
}
if ( V_9 == V_17 ) {
F_12 ( V_24 ) ;
goto V_25;
}
if ( V_9 == V_21 ) {
V_22 -> V_43 = V_46 ;
V_9 = V_45 ;
}
F_12 ( V_24 ) ;
return V_9 ;
}
static int F_13 ( struct V_2 * V_3 , unsigned char * V_6 )
{
struct V_7 V_8 ;
int V_47 ;
V_47 = F_4 ( V_6 , V_10 , & V_8 ) ;
if ( ! V_47 ) {
F_5 ( V_11 , V_3 ,
L_4
L_5 ,
V_12 ) ;
return V_13 ;
}
switch ( V_8 . V_15 ) {
case V_18 :
if ( ( V_8 . V_19 == 0x04 ) && ( V_8 . V_20 == 3 ) ) {
V_47 = V_48 ;
break;
}
default:
F_5 ( V_11 , V_3 ,
L_6 ,
V_12 , V_8 . V_15 , V_8 . V_19 ,
V_8 . V_20 ) ;
V_47 = V_13 ;
}
return V_47 ;
}
static void F_14 ( struct V_23 * V_24 , int error )
{
struct V_1 * V_22 = V_24 -> V_49 ;
unsigned V_50 = V_45 ;
if ( error || F_15 ( V_24 -> V_42 ) != V_51 ||
F_16 ( V_24 -> V_42 ) != V_52 ) {
F_5 ( V_11 , V_22 -> V_3 ,
L_7 ,
V_12 , V_24 -> V_42 ) ;
V_50 = V_13 ;
goto V_14;
}
if ( V_24 -> V_39 > 0 ) {
V_50 = F_13 ( V_22 -> V_3 , V_22 -> V_6 ) ;
if ( V_50 == V_48 ) {
V_50 = V_13 ;
if ( -- V_22 -> V_53 ) {
F_12 ( V_24 ) ;
V_50 = F_17 ( V_22 ) ;
if ( V_50 == V_45 )
return;
}
}
}
V_14:
V_24 -> V_49 = NULL ;
F_18 ( V_24 -> V_40 , V_24 ) ;
if ( V_22 -> V_54 ) {
V_22 -> V_54 ( V_22 -> V_55 , V_50 ) ;
V_22 -> V_54 = V_22 -> V_55 = NULL ;
}
return;
}
static int F_17 ( struct V_1 * V_22 )
{
struct V_23 * V_24 ;
V_24 = F_7 ( V_22 -> V_3 -> V_26 , V_27 , V_56 ) ;
if ( F_8 ( V_24 ) )
return V_29 ;
F_9 ( V_24 ) ;
V_24 -> V_30 |= V_31 | V_32 |
V_33 ;
V_24 -> V_34 = F_10 ( V_57 ) ;
V_24 -> V_36 [ 0 ] = V_57 ;
V_24 -> V_36 [ 4 ] = 1 ;
V_24 -> V_37 = V_38 ;
V_24 -> V_6 = V_22 -> V_6 ;
memset ( V_24 -> V_6 , 0 , V_10 ) ;
V_24 -> V_39 = 0 ;
V_24 -> V_49 = V_22 ;
F_19 ( V_24 -> V_40 , NULL , V_24 , 1 , F_14 ) ;
return V_45 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
int V_9 = V_58 ;
if ( V_22 -> V_43 != V_44 ) {
V_9 = V_59 ;
V_24 -> V_30 |= V_60 ;
}
return V_9 ;
}
static int F_21 ( struct V_2 * V_3 ,
T_1 V_61 , void * V_62 )
{
int V_9 = V_45 ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
V_9 = F_6 ( V_3 , V_22 ) ;
if ( V_9 == V_45 && V_22 -> V_43 == V_46 ) {
V_22 -> V_53 = V_22 -> V_63 ;
V_22 -> V_54 = V_61 ;
V_22 -> V_55 = V_62 ;
V_9 = F_17 ( V_22 ) ;
if ( V_9 == V_45 )
return 0 ;
V_22 -> V_54 = V_22 -> V_55 = NULL ;
}
if ( V_61 )
V_61 ( V_62 , V_9 ) ;
return 0 ;
}
static bool F_22 ( struct V_2 * V_3 )
{
int V_64 ;
if ( F_23 ( V_3 ) )
return false ;
for ( V_64 = 0 ; V_65 [ V_64 ] . V_66 ; V_64 ++ ) {
if ( ! strncmp ( V_3 -> V_66 , V_65 [ V_64 ] . V_66 ,
strlen ( V_65 [ V_64 ] . V_66 ) ) &&
! strncmp ( V_3 -> V_67 , V_65 [ V_64 ] . V_67 ,
strlen ( V_65 [ V_64 ] . V_67 ) ) ) {
return true ;
}
}
return false ;
}
static struct V_4 * F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_22 ;
int V_9 ;
V_22 = F_25 ( sizeof( * V_22 ) , V_68 ) ;
if ( ! V_22 )
return F_26 ( - V_69 ) ;
V_22 -> V_43 = V_70 ;
V_22 -> V_63 = V_71 ;
V_22 -> V_3 = V_3 ;
V_9 = F_6 ( V_3 , V_22 ) ;
if ( V_9 != V_45 || V_22 -> V_43 == V_70 )
goto V_72;
F_5 ( V_73 , V_3 , L_8 ,
V_12 , V_22 -> V_43 == V_44 ?
L_9 : L_10 ) ;
return & V_22 -> V_5 ;
V_72:
F_27 ( V_22 ) ;
return F_26 ( - V_74 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
F_27 ( V_22 ) ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_75 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_75 ) ;
}
