static int F_1 ( int V_1 )
{
return ( F_2 ( & V_2 -> V_3 , V_1 ) ||
V_2 -> V_4 -> V_5 [ V_1 - 1 ] . V_6 . V_7 == V_8 ) ;
}
int F_3 ( struct V_9 * V_10 , int V_1 )
{
unsigned long V_11 ;
struct V_12 * V_13 , * V_14 ;
int V_15 = 0 ;
if ( V_2 -> signal -> V_10 != V_10 )
return 0 ;
F_4 () ;
V_13 = F_5 ( V_2 ) ;
F_6 ( & V_10 -> V_16 , V_11 ) ;
V_14 = V_10 -> V_13 ;
F_7 ( & V_10 -> V_16 , V_11 ) ;
if ( V_14 && V_13 != V_10 -> V_13 ) {
if ( F_1 ( V_1 ) ) {
if ( V_1 == V_17 )
V_15 = - V_18 ;
} else if ( F_8 () )
V_15 = - V_18 ;
else {
F_9 ( V_13 , V_1 , 1 ) ;
F_10 ( V_19 ) ;
V_15 = - V_20 ;
}
}
F_11 () ;
if ( ! V_14 )
F_12 ( V_10 , L_1 , V_1 ) ;
return V_15 ;
}
int F_13 ( struct V_9 * V_10 )
{
return F_3 ( V_10 , V_21 ) ;
}
void F_14 ( struct V_22 * V_23 )
{
unsigned long V_11 ;
struct V_9 * V_10 ;
F_6 ( & V_23 -> V_4 -> V_24 , V_11 ) ;
V_10 = V_23 -> signal -> V_10 ;
V_23 -> signal -> V_10 = NULL ;
F_7 ( & V_23 -> V_4 -> V_24 , V_11 ) ;
F_15 ( V_10 ) ;
}
static void F_16 ( struct V_9 * V_10 )
{
unsigned long V_11 ;
F_6 ( & V_10 -> V_16 , V_11 ) ;
F_17 ( V_10 -> V_25 ) ;
F_17 ( V_10 -> V_13 ) ;
V_10 -> V_13 = F_18 ( F_5 ( V_2 ) ) ;
F_7 ( & V_10 -> V_16 , V_11 ) ;
V_10 -> V_25 = F_18 ( F_19 ( V_2 ) ) ;
if ( V_2 -> signal -> V_10 ) {
F_20 ( V_10 , L_2 ,
V_2 -> signal -> V_10 -> V_26 ) ;
F_15 ( V_2 -> signal -> V_10 ) ;
}
F_17 ( V_2 -> signal -> V_27 ) ;
V_2 -> signal -> V_10 = F_21 ( V_10 ) ;
V_2 -> signal -> V_27 = NULL ;
}
static void F_22 ( struct V_9 * V_10 )
{
F_23 ( & V_2 -> V_4 -> V_24 ) ;
F_16 ( V_10 ) ;
F_24 ( & V_2 -> V_4 -> V_24 ) ;
}
void F_25 ( struct V_28 * V_29 , struct V_9 * V_10 )
{
F_26 ( & V_30 ) ;
F_23 ( & V_2 -> V_4 -> V_24 ) ;
if ( V_2 -> signal -> V_31 &&
! V_2 -> signal -> V_10 &&
V_10 -> V_25 == NULL ) {
if ( V_29 -> V_32 & V_33 )
F_16 ( V_10 ) ;
}
F_24 ( & V_2 -> V_4 -> V_24 ) ;
F_27 ( & V_30 ) ;
}
struct V_9 * F_28 ( void )
{
struct V_9 * V_10 ;
unsigned long V_11 ;
F_6 ( & V_2 -> V_4 -> V_24 , V_11 ) ;
V_10 = F_21 ( V_2 -> signal -> V_10 ) ;
F_7 ( & V_2 -> V_4 -> V_24 , V_11 ) ;
return V_10 ;
}
void F_29 ( struct V_12 * V_25 )
{
struct V_22 * V_23 ;
F_30 (session, PIDTYPE_SID, p) {
F_14 ( V_23 ) ;
} F_31 ( V_25 , V_34 , V_23 ) ;
}
int F_32 ( struct V_9 * V_10 , int V_35 )
{
struct V_22 * V_23 ;
int V_36 = 0 ;
struct V_12 * V_14 = NULL ;
F_26 ( & V_30 ) ;
if ( V_10 -> V_25 ) {
F_30 (tty->session, PIDTYPE_SID, p) {
F_23 ( & V_23 -> V_4 -> V_24 ) ;
if ( V_23 -> signal -> V_10 == V_10 ) {
V_23 -> signal -> V_10 = NULL ;
V_36 ++ ;
}
if ( ! V_23 -> signal -> V_31 ) {
F_24 ( & V_23 -> V_4 -> V_24 ) ;
continue;
}
F_33 ( V_37 , V_38 , V_23 ) ;
F_33 ( V_39 , V_38 , V_23 ) ;
F_17 ( V_23 -> signal -> V_27 ) ;
F_34 ( & V_10 -> V_16 ) ;
V_14 = F_18 ( V_10 -> V_13 ) ;
if ( V_10 -> V_13 )
V_23 -> signal -> V_27 = F_18 ( V_10 -> V_13 ) ;
F_35 ( & V_10 -> V_16 ) ;
F_24 ( & V_23 -> V_4 -> V_24 ) ;
} F_31 ( V_10 -> V_25 , V_34 , V_23 ) ;
}
F_27 ( & V_30 ) ;
if ( V_14 ) {
if ( V_35 )
F_9 ( V_14 , V_37 , V_35 ) ;
F_17 ( V_14 ) ;
}
return V_36 ;
}
void F_36 ( int V_40 )
{
struct V_9 * V_10 ;
if ( ! V_2 -> signal -> V_31 )
return;
V_10 = F_28 () ;
if ( V_10 ) {
if ( V_40 && V_10 -> V_41 -> type != V_42 ) {
F_37 ( V_10 ) ;
} else {
struct V_12 * V_14 = F_38 ( V_10 ) ;
if ( V_14 ) {
F_9 ( V_14 , V_37 , V_40 ) ;
if ( ! V_40 )
F_9 ( V_14 , V_39 , V_40 ) ;
F_17 ( V_14 ) ;
}
}
F_15 ( V_10 ) ;
} else if ( V_40 ) {
struct V_12 * V_43 ;
F_23 ( & V_2 -> V_4 -> V_24 ) ;
V_43 = V_2 -> signal -> V_27 ;
V_2 -> signal -> V_27 = NULL ;
F_24 ( & V_2 -> V_4 -> V_24 ) ;
if ( V_43 ) {
F_9 ( V_43 , V_37 , V_40 ) ;
F_9 ( V_43 , V_39 , V_40 ) ;
F_17 ( V_43 ) ;
}
return;
}
F_23 ( & V_2 -> V_4 -> V_24 ) ;
F_17 ( V_2 -> signal -> V_27 ) ;
V_2 -> signal -> V_27 = NULL ;
V_10 = F_21 ( V_2 -> signal -> V_10 ) ;
if ( V_10 ) {
unsigned long V_11 ;
F_6 ( & V_10 -> V_16 , V_11 ) ;
F_17 ( V_10 -> V_25 ) ;
F_17 ( V_10 -> V_13 ) ;
V_10 -> V_25 = NULL ;
V_10 -> V_13 = NULL ;
F_7 ( & V_10 -> V_16 , V_11 ) ;
F_15 ( V_10 ) ;
}
F_24 ( & V_2 -> V_4 -> V_24 ) ;
F_26 ( & V_30 ) ;
F_29 ( F_19 ( V_2 ) ) ;
F_27 ( & V_30 ) ;
}
void F_39 ( void )
{
struct V_22 * V_44 = V_2 ;
F_36 ( 0 ) ;
F_14 ( V_44 ) ;
}
static int F_40 ( struct V_9 * V_10 , struct V_28 * V_28 , int V_45 )
{
int V_15 = 0 ;
F_41 ( V_10 ) ;
F_26 ( & V_30 ) ;
if ( V_2 -> signal -> V_31 && ( F_19 ( V_2 ) == V_10 -> V_25 ) )
goto V_46;
if ( ! V_2 -> signal -> V_31 || V_2 -> signal -> V_10 ) {
V_15 = - V_47 ;
goto V_46;
}
if ( V_10 -> V_25 ) {
if ( V_45 == 1 && F_42 ( V_48 ) ) {
F_29 ( V_10 -> V_25 ) ;
} else {
V_15 = - V_47 ;
goto V_46;
}
}
if ( ( V_28 -> V_32 & V_33 ) == 0 && ! F_42 ( V_48 ) ) {
V_15 = - V_47 ;
goto V_46;
}
F_22 ( V_10 ) ;
V_46:
F_27 ( & V_30 ) ;
F_43 ( V_10 ) ;
return V_15 ;
}
struct V_12 * F_38 ( struct V_9 * V_10 )
{
unsigned long V_11 ;
struct V_12 * V_13 ;
F_6 ( & V_10 -> V_16 , V_11 ) ;
V_13 = F_18 ( V_10 -> V_13 ) ;
F_7 ( & V_10 -> V_16 , V_11 ) ;
return V_13 ;
}
static struct V_12 * F_44 ( struct V_12 * V_13 )
{
struct V_22 * V_23 ;
struct V_12 * V_49 = NULL ;
V_23 = F_45 ( V_13 , V_50 ) ;
if ( V_23 == NULL )
V_23 = F_45 ( V_13 , V_51 ) ;
if ( V_23 != NULL )
V_49 = F_19 ( V_23 ) ;
return V_49 ;
}
static int F_46 ( struct V_9 * V_10 , struct V_9 * V_52 , T_1 T_2 * V_23 )
{
struct V_12 * V_12 ;
int V_15 ;
if ( V_10 == V_52 && V_2 -> signal -> V_10 != V_52 )
return - V_53 ;
V_12 = F_38 ( V_52 ) ;
V_15 = F_47 ( F_48 ( V_12 ) , V_23 ) ;
F_17 ( V_12 ) ;
return V_15 ;
}
static int F_49 ( struct V_9 * V_10 , struct V_9 * V_52 , T_1 T_2 * V_23 )
{
struct V_12 * V_13 ;
T_1 V_54 ;
int V_55 = F_13 ( V_52 ) ;
if ( V_55 == - V_18 )
return - V_53 ;
if ( V_55 )
return V_55 ;
if ( ! V_2 -> signal -> V_10 ||
( V_2 -> signal -> V_10 != V_52 ) ||
( V_52 -> V_25 != F_19 ( V_2 ) ) )
return - V_53 ;
if ( F_50 ( V_54 , V_23 ) )
return - V_56 ;
if ( V_54 < 0 )
return - V_57 ;
F_4 () ;
V_13 = F_51 ( V_54 ) ;
V_55 = - V_58 ;
if ( ! V_13 )
goto V_59;
V_55 = - V_47 ;
if ( F_44 ( V_13 ) != F_19 ( V_2 ) )
goto V_59;
V_55 = 0 ;
F_23 ( & V_10 -> V_16 ) ;
F_17 ( V_52 -> V_13 ) ;
V_52 -> V_13 = F_18 ( V_13 ) ;
F_24 ( & V_10 -> V_16 ) ;
V_59:
F_11 () ;
return V_55 ;
}
static int F_52 ( struct V_9 * V_10 , struct V_9 * V_52 , T_1 T_2 * V_23 )
{
if ( V_10 == V_52 && V_2 -> signal -> V_10 != V_52 )
return - V_53 ;
if ( ! V_52 -> V_25 )
return - V_53 ;
return F_47 ( F_48 ( V_52 -> V_25 ) , V_23 ) ;
}
long F_53 ( struct V_9 * V_10 , struct V_9 * V_52 ,
struct V_28 * V_28 , unsigned int V_60 , unsigned long V_45 )
{
void T_2 * V_23 = ( void T_2 * ) V_45 ;
switch ( V_60 ) {
case V_61 :
if ( V_2 -> signal -> V_10 != V_10 )
return - V_53 ;
F_39 () ;
return 0 ;
case V_62 :
return F_40 ( V_52 , V_28 , V_45 ) ;
case V_63 :
return F_46 ( V_10 , V_52 , V_23 ) ;
case V_64 :
return F_49 ( V_10 , V_52 , V_23 ) ;
case V_65 :
return F_52 ( V_10 , V_52 , V_23 ) ;
}
return - V_66 ;
}
