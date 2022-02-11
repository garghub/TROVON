static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
T_1 V_5 = 0 ;
T_1 V_6 = 0 ;
T_1 V_7 = 0 ;
if ( F_2 ( V_2 -> V_8 ) )
V_2 -> V_9 . V_10 = ! ! F_3 ( V_2 -> V_8 ) ;
if ( V_2 -> V_9 . V_11 ) {
switch ( V_2 -> V_9 . V_12 ) {
case 1000 :
V_3 |= V_13 ;
break;
case 100 :
V_3 |= V_14 ;
break;
case 10 :
V_3 |= V_15 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_9 . V_12 ) {
case 1000 :
V_3 |= V_13 ;
break;
case 100 :
V_3 |= V_16 ;
break;
case 10 :
V_3 |= V_17 ;
break;
default:
break;
}
}
if ( V_2 -> V_9 . V_10 ) {
V_3 |= V_18 | V_19 ;
if ( V_2 -> V_9 . V_11 ) {
V_5 |= V_20 ;
switch ( V_2 -> V_9 . V_12 ) {
case 1000 :
V_5 |= V_21 ;
V_6 |= V_22 ;
break;
case 100 :
V_5 |= V_23 ;
V_7 |= V_24 ;
break;
case 10 :
V_7 |= V_25 ;
break;
default:
F_4 ( L_1 ) ;
return - V_26 ;
}
} else {
switch ( V_2 -> V_9 . V_12 ) {
case 1000 :
V_5 |= V_21 ;
V_6 |= V_27 ;
break;
case 100 :
V_5 |= V_23 ;
V_7 |= V_28 ;
break;
case 10 :
V_7 |= V_29 ;
break;
default:
F_4 ( L_1 ) ;
return - V_26 ;
}
}
if ( V_2 -> V_9 . V_30 )
V_7 |= V_31 ;
if ( V_2 -> V_9 . V_32 )
V_7 |= V_33 ;
}
V_2 -> V_34 [ V_35 ] = 0 ;
V_2 -> V_34 [ V_36 ] = 0 ;
V_2 -> V_34 [ V_37 ] = V_3 ;
V_2 -> V_34 [ V_38 ] = V_5 ;
V_2 -> V_34 [ V_39 ] = V_7 ;
V_2 -> V_34 [ V_40 ] = V_6 ;
return 0 ;
}
static int F_5 ( struct V_41 * V_42 , int V_43 , int V_44 )
{
struct V_45 * V_46 = V_42 -> V_47 ;
struct V_1 * V_2 ;
if ( V_44 >= V_48 )
return - 1 ;
switch ( V_44 ) {
case V_49 :
case V_50 :
return - 1 ;
default:
break;
}
F_6 (fp, &fmb->phys, node) {
if ( V_2 -> V_51 == V_43 ) {
if ( V_2 -> V_52 ) {
V_2 -> V_52 ( V_2 -> V_53 -> V_54 ,
& V_2 -> V_9 ) ;
F_1 ( V_2 ) ;
}
return V_2 -> V_34 [ V_44 ] ;
}
}
return 0xFFFF ;
}
static int F_7 ( struct V_41 * V_42 , int V_43 , int V_44 ,
T_1 V_55 )
{
return 0 ;
}
int F_8 ( struct V_56 * V_53 ,
int (* V_52)( struct V_57 * ,
struct V_58 * ) )
{
struct V_45 * V_46 = & V_59 ;
struct V_1 * V_2 ;
if ( ! V_53 || ! V_53 -> V_60 . V_42 )
return - V_26 ;
F_6 (fp, &fmb->phys, node) {
if ( V_2 -> V_51 == V_53 -> V_60 . V_51 ) {
V_2 -> V_52 = V_52 ;
V_2 -> V_53 = V_53 ;
return 0 ;
}
}
return - V_61 ;
}
int F_9 ( struct V_56 * V_53 ,
const struct V_58 * V_9 ,
const struct V_58 * V_62 )
{
struct V_45 * V_46 = & V_59 ;
struct V_1 * V_2 ;
if ( ! V_53 || V_53 -> V_60 . V_42 != V_46 -> V_41 )
return - V_26 ;
F_6 (fp, &fmb->phys, node) {
if ( V_2 -> V_51 == V_53 -> V_60 . V_51 ) {
#define F_10 ( T_2 ) if (changed->x) \
fp->status.x = status->x
F_10 ( V_10 ) ;
F_10 ( V_12 ) ;
F_10 ( V_11 ) ;
F_10 ( V_30 ) ;
F_10 ( V_32 ) ;
#undef F_10
F_1 ( V_2 ) ;
return 0 ;
}
}
return - V_61 ;
}
int F_11 ( unsigned int V_63 , int V_43 ,
struct V_58 * V_9 ,
int V_8 )
{
int V_64 ;
struct V_45 * V_46 = & V_59 ;
struct V_1 * V_2 ;
V_2 = F_12 ( sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 )
return - V_66 ;
memset ( V_2 -> V_34 , 0xFF , sizeof( V_2 -> V_34 [ 0 ] ) * V_48 ) ;
if ( V_63 != V_67 )
V_46 -> V_41 -> V_63 [ V_43 ] = V_63 ;
V_2 -> V_51 = V_43 ;
V_2 -> V_9 = * V_9 ;
V_2 -> V_8 = V_8 ;
if ( F_2 ( V_2 -> V_8 ) ) {
V_64 = F_13 ( V_2 -> V_8 , V_68 ,
L_2 ) ;
if ( V_64 )
goto V_69;
}
V_64 = F_1 ( V_2 ) ;
if ( V_64 )
goto V_70;
F_14 ( & V_2 -> V_71 , & V_46 -> V_72 ) ;
return 0 ;
V_70:
if ( F_2 ( V_2 -> V_8 ) )
F_15 ( V_2 -> V_8 ) ;
V_69:
F_16 ( V_2 ) ;
return V_64 ;
}
static void F_17 ( int V_43 )
{
struct V_45 * V_46 = & V_59 ;
struct V_1 * V_2 , * V_73 ;
F_18 (fp, tmp, &fmb->phys, node) {
if ( V_2 -> V_51 == V_43 ) {
F_19 ( & V_2 -> V_71 ) ;
if ( F_2 ( V_2 -> V_8 ) )
F_15 ( V_2 -> V_8 ) ;
F_16 ( V_2 ) ;
F_20 ( & V_74 , V_43 ) ;
return;
}
}
}
struct V_56 * F_21 ( unsigned int V_63 ,
struct V_58 * V_9 ,
int V_8 ,
struct V_75 * V_76 )
{
struct V_45 * V_46 = & V_59 ;
struct V_56 * V_77 ;
int V_43 ;
int V_64 ;
if ( ! V_46 -> V_41 || V_46 -> V_41 -> V_78 != V_79 )
return F_22 ( - V_80 ) ;
V_43 = F_23 ( & V_74 , 0 , V_81 , V_65 ) ;
if ( V_43 < 0 )
return F_22 ( V_43 ) ;
V_64 = F_11 ( V_63 , V_43 , V_9 , V_8 ) ;
if ( V_64 < 0 ) {
F_20 ( & V_74 , V_43 ) ;
return F_22 ( V_64 ) ;
}
V_77 = F_24 ( V_46 -> V_41 , V_43 , false ) ;
if ( F_25 ( V_77 ) ) {
F_17 ( V_43 ) ;
return F_22 ( - V_26 ) ;
}
V_77 -> V_10 = V_9 -> V_10 ;
if ( V_9 -> V_10 ) {
V_77 -> V_12 = V_9 -> V_12 ;
V_77 -> V_11 = V_9 -> V_11 ;
V_77 -> V_30 = V_9 -> V_30 ;
V_77 -> V_32 = V_9 -> V_32 ;
}
F_26 ( V_76 ) ;
V_77 -> V_60 . V_82 . V_83 = V_76 ;
V_77 -> V_84 = true ;
switch ( V_9 -> V_12 ) {
case V_85 :
V_77 -> V_86 = V_87 ;
break;
case V_88 :
V_77 -> V_86 = V_89 ;
break;
case V_90 :
default:
V_77 -> V_86 = V_91 ;
}
V_64 = F_27 ( V_77 ) ;
if ( V_64 ) {
F_28 ( V_77 ) ;
F_29 ( V_76 ) ;
F_17 ( V_43 ) ;
return F_22 ( V_64 ) ;
}
return V_77 ;
}
void F_30 ( struct V_56 * V_77 )
{
F_31 ( V_77 ) ;
F_17 ( V_77 -> V_60 . V_51 ) ;
}
static int T_3 F_32 ( void )
{
struct V_45 * V_46 = & V_59 ;
int V_64 ;
V_92 = F_33 ( L_3 , 0 , NULL , 0 ) ;
if ( F_25 ( V_92 ) ) {
V_64 = F_34 ( V_92 ) ;
goto V_93;
}
V_46 -> V_41 = F_35 () ;
if ( V_46 -> V_41 == NULL ) {
V_64 = - V_66 ;
goto V_94;
}
snprintf ( V_46 -> V_41 -> V_95 , V_96 , L_4 ) ;
V_46 -> V_41 -> V_97 = L_5 ;
V_46 -> V_41 -> V_47 = V_46 ;
V_46 -> V_41 -> V_98 = & V_92 -> V_82 ;
V_46 -> V_41 -> V_99 = & F_5 ;
V_46 -> V_41 -> V_100 = & F_7 ;
V_64 = F_36 ( V_46 -> V_41 ) ;
if ( V_64 )
goto V_101;
return 0 ;
V_101:
F_37 ( V_46 -> V_41 ) ;
V_94:
F_38 ( V_92 ) ;
V_93:
return V_64 ;
}
static void T_4 F_39 ( void )
{
struct V_45 * V_46 = & V_59 ;
struct V_1 * V_2 , * V_73 ;
F_40 ( V_46 -> V_41 ) ;
F_37 ( V_46 -> V_41 ) ;
F_38 ( V_92 ) ;
F_18 (fp, tmp, &fmb->phys, node) {
F_19 ( & V_2 -> V_71 ) ;
F_16 ( V_2 ) ;
}
F_41 ( & V_74 ) ;
}
