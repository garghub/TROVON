static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
T_1 V_5 = 0 ;
T_1 V_6 = 0 ;
T_1 V_7 = 0 ;
if ( V_2 -> V_8 . V_9 ) {
V_5 |= V_10 ;
switch ( V_2 -> V_8 . V_11 ) {
case 1000 :
V_3 |= V_12 ;
V_5 |= V_13 ;
V_6 |= V_14 ;
break;
case 100 :
V_3 |= V_15 ;
V_5 |= V_16 ;
V_7 |= V_17 ;
break;
case 10 :
V_3 |= V_18 ;
V_7 |= V_19 ;
break;
default:
F_2 ( L_1 ) ;
return - V_20 ;
}
} else {
switch ( V_2 -> V_8 . V_11 ) {
case 1000 :
V_3 |= V_12 ;
V_5 |= V_13 ;
V_6 |= V_21 ;
break;
case 100 :
V_3 |= V_22 ;
V_5 |= V_16 ;
V_7 |= V_23 ;
break;
case 10 :
V_3 |= V_24 ;
V_7 |= V_25 ;
break;
default:
F_2 ( L_1 ) ;
return - V_20 ;
}
}
if ( V_2 -> V_8 . V_26 )
V_3 |= V_27 | V_28 ;
if ( V_2 -> V_8 . V_29 )
V_7 |= V_30 ;
if ( V_2 -> V_8 . V_31 )
V_7 |= V_32 ;
V_2 -> V_33 [ V_34 ] = 0 ;
V_2 -> V_33 [ V_35 ] = 0 ;
V_2 -> V_33 [ V_36 ] = V_3 ;
V_2 -> V_33 [ V_37 ] = V_5 ;
V_2 -> V_33 [ V_38 ] = V_7 ;
V_2 -> V_33 [ V_39 ] = V_6 ;
return 0 ;
}
static int F_3 ( struct V_40 * V_41 , int V_42 , int V_43 )
{
struct V_44 * V_45 = V_41 -> V_46 ;
struct V_1 * V_2 ;
if ( V_43 >= V_47 )
return - 1 ;
switch ( V_43 ) {
case V_48 :
case V_49 :
return - 1 ;
default:
break;
}
F_4 (fp, &fmb->phys, node) {
if ( V_2 -> V_50 == V_42 ) {
if ( V_2 -> V_51 ) {
V_2 -> V_51 ( V_2 -> V_52 -> V_53 ,
& V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
}
return V_2 -> V_33 [ V_43 ] ;
}
}
return 0xFFFF ;
}
static int F_5 ( struct V_40 * V_41 , int V_42 , int V_43 ,
T_1 V_54 )
{
return 0 ;
}
int F_6 ( struct V_55 * V_52 ,
int (* V_51)( struct V_56 * ,
struct V_57 * ) )
{
struct V_44 * V_45 = & V_58 ;
struct V_1 * V_2 ;
if ( ! V_52 || ! V_52 -> V_41 )
return - V_20 ;
F_4 (fp, &fmb->phys, node) {
if ( V_2 -> V_50 == V_52 -> V_50 ) {
V_2 -> V_51 = V_51 ;
V_2 -> V_52 = V_52 ;
return 0 ;
}
}
return - V_59 ;
}
int F_7 ( struct V_55 * V_52 ,
const struct V_57 * V_8 ,
const struct V_57 * V_60 )
{
struct V_44 * V_45 = & V_58 ;
struct V_1 * V_2 ;
if ( ! V_52 || ! V_52 -> V_41 )
return - V_20 ;
F_4 (fp, &fmb->phys, node) {
if ( V_2 -> V_50 == V_52 -> V_50 ) {
#define F_8 ( T_2 ) if (changed->x) \
fp->status.x = status->x
F_8 ( V_26 ) ;
F_8 ( V_11 ) ;
F_8 ( V_9 ) ;
F_8 ( V_29 ) ;
F_8 ( V_31 ) ;
#undef F_8
F_1 ( V_2 ) ;
return 0 ;
}
}
return - V_59 ;
}
int F_9 ( unsigned int V_61 , int V_42 ,
struct V_57 * V_8 )
{
int V_62 ;
struct V_44 * V_45 = & V_58 ;
struct V_1 * V_2 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 )
return - V_64 ;
memset ( V_2 -> V_33 , 0xFF , sizeof( V_2 -> V_33 [ 0 ] ) * V_47 ) ;
V_45 -> V_65 [ V_42 ] = V_61 ;
V_2 -> V_50 = V_42 ;
V_2 -> V_8 = * V_8 ;
V_62 = F_1 ( V_2 ) ;
if ( V_62 )
goto V_66;
F_11 ( & V_2 -> V_67 , & V_45 -> V_68 ) ;
return 0 ;
V_66:
F_12 ( V_2 ) ;
return V_62 ;
}
void F_13 ( int V_42 )
{
struct V_44 * V_45 = & V_58 ;
struct V_1 * V_2 , * V_69 ;
F_14 (fp, tmp, &fmb->phys, node) {
if ( V_2 -> V_50 == V_42 ) {
F_15 ( & V_2 -> V_67 ) ;
F_12 ( V_2 ) ;
return;
}
}
}
struct V_55 * F_16 ( unsigned int V_61 ,
struct V_57 * V_8 ,
struct V_70 * V_71 )
{
struct V_44 * V_45 = & V_58 ;
struct V_55 * V_72 ;
int V_42 ;
int V_62 ;
F_17 ( & V_73 ) ;
if ( V_74 == V_75 ) {
F_18 ( & V_73 ) ;
return F_19 ( - V_76 ) ;
}
V_42 = V_74 ++ ;
F_18 ( & V_73 ) ;
V_62 = F_9 ( V_77 , V_42 , V_8 ) ;
if ( V_62 < 0 )
return F_19 ( V_62 ) ;
V_72 = F_20 ( V_45 -> V_40 , V_42 , false ) ;
if ( ! V_72 || F_21 ( V_72 ) ) {
F_13 ( V_42 ) ;
return F_19 ( - V_20 ) ;
}
V_72 -> V_26 = V_8 -> V_26 ;
if ( V_8 -> V_26 ) {
V_72 -> V_11 = V_8 -> V_11 ;
V_72 -> V_9 = V_8 -> V_9 ;
V_72 -> V_29 = V_8 -> V_29 ;
V_72 -> V_31 = V_8 -> V_31 ;
}
F_22 ( V_71 ) ;
V_72 -> V_78 . V_79 = V_71 ;
V_62 = F_23 ( V_72 ) ;
if ( V_62 ) {
F_24 ( V_72 ) ;
F_25 ( V_71 ) ;
F_13 ( V_42 ) ;
return F_19 ( V_62 ) ;
}
return V_72 ;
}
static int T_3 F_26 ( void )
{
struct V_44 * V_45 = & V_58 ;
int V_62 ;
V_80 = F_27 ( L_2 , 0 , NULL , 0 ) ;
if ( F_21 ( V_80 ) ) {
V_62 = F_28 ( V_80 ) ;
goto V_81;
}
V_45 -> V_40 = F_29 () ;
if ( V_45 -> V_40 == NULL ) {
V_62 = - V_64 ;
goto V_82;
}
snprintf ( V_45 -> V_40 -> V_83 , V_84 , L_3 ) ;
V_45 -> V_40 -> V_85 = L_4 ;
V_45 -> V_40 -> V_46 = V_45 ;
V_45 -> V_40 -> V_86 = & V_80 -> V_78 ;
V_45 -> V_40 -> V_87 = & F_3 ;
V_45 -> V_40 -> V_88 = & F_5 ;
V_45 -> V_40 -> V_61 = V_45 -> V_65 ;
V_62 = F_30 ( V_45 -> V_40 ) ;
if ( V_62 )
goto V_89;
return 0 ;
V_89:
F_31 ( V_45 -> V_40 ) ;
V_82:
F_32 ( V_80 ) ;
V_81:
return V_62 ;
}
static void T_4 F_33 ( void )
{
struct V_44 * V_45 = & V_58 ;
struct V_1 * V_2 , * V_69 ;
F_34 ( V_45 -> V_40 ) ;
F_31 ( V_45 -> V_40 ) ;
F_32 ( V_80 ) ;
F_14 (fp, tmp, &fmb->phys, node) {
F_15 ( & V_2 -> V_67 ) ;
F_12 ( V_2 ) ;
}
}
