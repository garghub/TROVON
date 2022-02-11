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
if ( ! V_51 || ! V_52 || ! V_52 -> V_41 )
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
int F_7 ( unsigned int V_60 , int V_42 ,
struct V_57 * V_8 )
{
int V_61 ;
struct V_44 * V_45 = & V_58 ;
struct V_1 * V_2 ;
V_2 = F_8 ( sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_63 ;
memset ( V_2 -> V_33 , 0xFF , sizeof( V_2 -> V_33 [ 0 ] ) * V_47 ) ;
V_45 -> V_64 [ V_42 ] = V_60 ;
V_2 -> V_50 = V_42 ;
V_2 -> V_8 = * V_8 ;
V_61 = F_1 ( V_2 ) ;
if ( V_61 )
goto V_65;
F_9 ( & V_2 -> V_66 , & V_45 -> V_67 ) ;
return 0 ;
V_65:
F_10 ( V_2 ) ;
return V_61 ;
}
void F_11 ( int V_42 )
{
struct V_44 * V_45 = & V_58 ;
struct V_1 * V_2 , * V_68 ;
F_12 (fp, tmp, &fmb->phys, node) {
if ( V_2 -> V_50 == V_42 ) {
F_13 ( & V_2 -> V_66 ) ;
F_10 ( V_2 ) ;
return;
}
}
}
struct V_55 * F_14 ( unsigned int V_60 ,
struct V_57 * V_8 ,
struct V_69 * V_70 )
{
struct V_44 * V_45 = & V_58 ;
struct V_55 * V_71 ;
int V_42 ;
int V_61 ;
F_15 ( & V_72 ) ;
if ( V_73 == V_74 ) {
F_16 ( & V_72 ) ;
return F_17 ( - V_75 ) ;
}
V_42 = V_73 ++ ;
F_16 ( & V_72 ) ;
V_61 = F_7 ( V_76 , V_42 , V_8 ) ;
if ( V_61 < 0 )
return F_17 ( V_61 ) ;
V_71 = F_18 ( V_45 -> V_40 , V_42 , false ) ;
if ( ! V_71 || F_19 ( V_71 ) ) {
F_11 ( V_42 ) ;
return F_17 ( - V_20 ) ;
}
F_20 ( V_70 ) ;
V_71 -> V_77 . V_78 = V_70 ;
V_61 = F_21 ( V_71 ) ;
if ( V_61 ) {
F_22 ( V_71 ) ;
F_23 ( V_70 ) ;
F_11 ( V_42 ) ;
return F_17 ( V_61 ) ;
}
return V_71 ;
}
static int T_2 F_24 ( void )
{
struct V_44 * V_45 = & V_58 ;
int V_61 ;
V_79 = F_25 ( L_2 , 0 , NULL , 0 ) ;
if ( F_19 ( V_79 ) ) {
V_61 = F_26 ( V_79 ) ;
goto V_80;
}
V_45 -> V_40 = F_27 () ;
if ( V_45 -> V_40 == NULL ) {
V_61 = - V_63 ;
goto V_81;
}
snprintf ( V_45 -> V_40 -> V_82 , V_83 , L_3 ) ;
V_45 -> V_40 -> V_84 = L_4 ;
V_45 -> V_40 -> V_46 = V_45 ;
V_45 -> V_40 -> V_85 = & V_79 -> V_77 ;
V_45 -> V_40 -> V_86 = & F_3 ;
V_45 -> V_40 -> V_87 = & F_5 ;
V_45 -> V_40 -> V_60 = V_45 -> V_64 ;
V_61 = F_28 ( V_45 -> V_40 ) ;
if ( V_61 )
goto V_88;
return 0 ;
V_88:
F_29 ( V_45 -> V_40 ) ;
V_81:
F_30 ( V_79 ) ;
V_80:
return V_61 ;
}
static void T_3 F_31 ( void )
{
struct V_44 * V_45 = & V_58 ;
struct V_1 * V_2 , * V_68 ;
F_32 ( V_45 -> V_40 ) ;
F_29 ( V_45 -> V_40 ) ;
F_30 ( V_79 ) ;
F_12 (fp, tmp, &fmb->phys, node) {
F_13 ( & V_2 -> V_66 ) ;
F_10 ( V_2 ) ;
}
}
