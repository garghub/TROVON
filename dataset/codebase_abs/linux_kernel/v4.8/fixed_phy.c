static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) )
V_2 -> V_4 . V_5 = ! ! F_3 ( V_2 -> V_3 ) ;
}
static int F_4 ( struct V_6 * V_7 , int V_8 , int V_9 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_1 * V_2 ;
F_5 (fp, &fmb->phys, node) {
if ( V_2 -> V_13 == V_8 ) {
struct V_14 V_15 ;
int V_16 ;
do {
V_16 = F_6 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_18 ) {
V_2 -> V_18 ( V_2 -> V_19 -> V_20 ,
& V_2 -> V_4 ) ;
F_1 ( V_2 ) ;
}
V_15 = V_2 -> V_4 ;
} while ( F_7 ( & V_2 -> V_17 , V_16 ) );
return F_8 ( V_9 , & V_15 ) ;
}
}
return 0xFFFF ;
}
static int F_9 ( struct V_6 * V_7 , int V_8 , int V_9 ,
T_1 V_21 )
{
return 0 ;
}
int F_10 ( struct V_22 * V_19 ,
int (* V_18)( struct V_23 * ,
struct V_14 * ) )
{
struct V_10 * V_11 = & V_24 ;
struct V_1 * V_2 ;
if ( ! V_19 || ! V_19 -> V_25 . V_7 )
return - V_26 ;
F_5 (fp, &fmb->phys, node) {
if ( V_2 -> V_13 == V_19 -> V_25 . V_13 ) {
V_2 -> V_18 = V_18 ;
V_2 -> V_19 = V_19 ;
return 0 ;
}
}
return - V_27 ;
}
int F_11 ( struct V_22 * V_19 ,
const struct V_14 * V_4 ,
const struct V_14 * V_28 )
{
struct V_10 * V_11 = & V_24 ;
struct V_1 * V_2 ;
if ( ! V_19 || V_19 -> V_25 . V_7 != V_11 -> V_6 )
return - V_26 ;
F_5 (fp, &fmb->phys, node) {
if ( V_2 -> V_13 == V_19 -> V_25 . V_13 ) {
F_12 ( & V_2 -> V_17 ) ;
#define F_13 ( T_2 ) if (changed->x) \
fp->status.x = status->x
F_13 ( V_5 ) ;
F_13 ( V_29 ) ;
F_13 ( V_30 ) ;
F_13 ( V_31 ) ;
F_13 ( V_32 ) ;
#undef F_13
F_1 ( V_2 ) ;
F_14 ( & V_2 -> V_17 ) ;
return 0 ;
}
}
return - V_27 ;
}
int F_15 ( unsigned int V_33 , int V_8 ,
struct V_14 * V_4 ,
int V_3 )
{
int V_34 ;
struct V_10 * V_11 = & V_24 ;
struct V_1 * V_2 ;
V_34 = F_16 ( V_4 ) ;
if ( V_34 < 0 )
return V_34 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
F_18 ( & V_2 -> V_17 ) ;
if ( V_33 != V_37 )
V_11 -> V_6 -> V_33 [ V_8 ] = V_33 ;
V_2 -> V_13 = V_8 ;
V_2 -> V_4 = * V_4 ;
V_2 -> V_3 = V_3 ;
if ( F_2 ( V_2 -> V_3 ) ) {
V_34 = F_19 ( V_2 -> V_3 , V_38 ,
L_1 ) ;
if ( V_34 )
goto V_39;
}
F_1 ( V_2 ) ;
F_20 ( & V_2 -> V_40 , & V_11 -> V_41 ) ;
return 0 ;
V_39:
F_21 ( V_2 ) ;
return V_34 ;
}
static void F_22 ( int V_8 )
{
struct V_10 * V_11 = & V_24 ;
struct V_1 * V_2 , * V_42 ;
F_23 (fp, tmp, &fmb->phys, node) {
if ( V_2 -> V_13 == V_8 ) {
F_24 ( & V_2 -> V_40 ) ;
if ( F_2 ( V_2 -> V_3 ) )
F_25 ( V_2 -> V_3 ) ;
F_21 ( V_2 ) ;
F_26 ( & V_43 , V_8 ) ;
return;
}
}
}
struct V_22 * F_27 ( unsigned int V_33 ,
struct V_14 * V_4 ,
int V_3 ,
struct V_44 * V_45 )
{
struct V_10 * V_11 = & V_24 ;
struct V_22 * V_46 ;
int V_8 ;
int V_34 ;
if ( ! V_11 -> V_6 || V_11 -> V_6 -> V_15 != V_47 )
return F_28 ( - V_48 ) ;
V_8 = F_29 ( & V_43 , 0 , V_49 , V_35 ) ;
if ( V_8 < 0 )
return F_28 ( V_8 ) ;
V_34 = F_15 ( V_33 , V_8 , V_4 , V_3 ) ;
if ( V_34 < 0 ) {
F_26 ( & V_43 , V_8 ) ;
return F_28 ( V_34 ) ;
}
V_46 = F_30 ( V_11 -> V_6 , V_8 , false ) ;
if ( F_31 ( V_46 ) ) {
F_22 ( V_8 ) ;
return F_28 ( - V_26 ) ;
}
V_46 -> V_5 = V_4 -> V_5 ;
if ( V_4 -> V_5 ) {
V_46 -> V_29 = V_4 -> V_29 ;
V_46 -> V_30 = V_4 -> V_30 ;
V_46 -> V_31 = V_4 -> V_31 ;
V_46 -> V_32 = V_4 -> V_32 ;
}
F_32 ( V_45 ) ;
V_46 -> V_25 . V_50 . V_51 = V_45 ;
V_46 -> V_52 = true ;
switch ( V_4 -> V_29 ) {
case V_53 :
V_46 -> V_54 = V_55 ;
break;
case V_56 :
V_46 -> V_54 = V_57 ;
break;
case V_58 :
default:
V_46 -> V_54 = V_59 ;
}
V_34 = F_33 ( V_46 ) ;
if ( V_34 ) {
F_34 ( V_46 ) ;
F_35 ( V_45 ) ;
F_22 ( V_8 ) ;
return F_28 ( V_34 ) ;
}
return V_46 ;
}
void F_36 ( struct V_22 * V_46 )
{
F_37 ( V_46 ) ;
F_22 ( V_46 -> V_25 . V_13 ) ;
}
static int T_3 F_38 ( void )
{
struct V_10 * V_11 = & V_24 ;
int V_34 ;
V_60 = F_39 ( L_2 , 0 , NULL , 0 ) ;
if ( F_31 ( V_60 ) ) {
V_34 = F_40 ( V_60 ) ;
goto V_61;
}
V_11 -> V_6 = F_41 () ;
if ( V_11 -> V_6 == NULL ) {
V_34 = - V_36 ;
goto V_62;
}
snprintf ( V_11 -> V_6 -> V_63 , V_64 , L_3 ) ;
V_11 -> V_6 -> V_65 = L_4 ;
V_11 -> V_6 -> V_12 = V_11 ;
V_11 -> V_6 -> V_66 = & V_60 -> V_50 ;
V_11 -> V_6 -> V_67 = & F_4 ;
V_11 -> V_6 -> V_68 = & F_9 ;
V_34 = F_42 ( V_11 -> V_6 ) ;
if ( V_34 )
goto V_69;
return 0 ;
V_69:
F_43 ( V_11 -> V_6 ) ;
V_62:
F_44 ( V_60 ) ;
V_61:
return V_34 ;
}
static void T_4 F_45 ( void )
{
struct V_10 * V_11 = & V_24 ;
struct V_1 * V_2 , * V_42 ;
F_46 ( V_11 -> V_6 ) ;
F_43 ( V_11 -> V_6 ) ;
F_44 ( V_60 ) ;
F_23 (fp, tmp, &fmb->phys, node) {
F_24 ( & V_2 -> V_40 ) ;
F_21 ( V_2 ) ;
}
F_47 ( & V_43 ) ;
}
