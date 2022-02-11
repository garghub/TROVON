bool F_1 ( int V_1 )
{
return V_1 == V_2 ;
}
static int F_2 ( int V_3 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
case V_5 :
return - V_6 ;
case V_7 :
return - V_8 ;
case V_9 :
return - V_10 ;
} ;
return - V_8 ;
}
static T_1 F_3 ( void )
{
return F_4 ( V_11 , 0 , 0 , 0 ) ;
}
static int F_5 ( T_1 V_12 , unsigned long V_13 )
{
int V_14 ;
T_1 V_15 ;
V_15 = V_16 [ V_17 ] ;
V_14 = F_4 ( V_15 , V_12 , V_13 , 0 ) ;
return F_2 ( V_14 ) ;
}
static int F_6 ( T_1 V_12 )
{
int V_14 ;
T_1 V_15 ;
V_15 = V_16 [ V_18 ] ;
V_14 = F_4 ( V_15 , V_12 , 0 , 0 ) ;
return F_2 ( V_14 ) ;
}
static int F_7 ( unsigned long V_19 , unsigned long V_13 )
{
int V_14 ;
T_1 V_15 ;
V_15 = V_16 [ V_20 ] ;
V_14 = F_4 ( V_15 , V_19 , V_13 , 0 ) ;
return F_2 ( V_14 ) ;
}
static int F_8 ( unsigned long V_19 )
{
int V_14 ;
T_1 V_15 ;
V_15 = V_16 [ V_21 ] ;
V_14 = F_4 ( V_15 , V_19 , 0 , 0 ) ;
return F_2 ( V_14 ) ;
}
static int F_9 ( unsigned long V_22 ,
unsigned long V_23 )
{
return F_4 ( F_10 ( V_24 ) ,
V_22 , V_23 , 0 ) ;
}
static int F_11 ( void )
{
return F_4 ( V_25 , 0 , 0 , 0 ) ;
}
static unsigned long F_12 ( void )
{
return F_4 ( F_10 ( V_26 ) ,
0 , 0 , 0 ) ;
}
static int F_13 ( struct V_27 * V_28 )
{
const char * V_29 ;
F_14 ( L_1 ) ;
if ( F_15 ( V_28 , L_2 , & V_29 ) ) {
F_16 ( L_3 ) ;
return - V_30 ;
}
if ( ! strcmp ( L_4 , V_29 ) ) {
F_4 = V_31 ;
} else if ( ! strcmp ( L_5 , V_29 ) ) {
F_4 = V_32 ;
} else {
F_16 ( L_6 , V_29 ) ;
return - V_8 ;
}
return 0 ;
}
static void F_17 ( enum V_33 V_33 , const char * V_34 )
{
F_4 ( V_35 , 0 , 0 , 0 ) ;
}
static void F_18 ( void )
{
F_4 ( V_36 , 0 , 0 , 0 ) ;
}
static void T_2 F_19 ( void )
{
unsigned long V_19 ;
int type , V_1 = - 1 ;
type = V_37 . V_38 () ;
if ( type == V_39 ) {
F_14 ( L_7 ) ;
return;
}
if ( type == V_5 ) {
F_14 ( L_8 ) ;
return;
}
if ( type != V_40 &&
type != V_41 ) {
F_20 ( L_9 , type ) ;
return;
}
V_19 = F_12 () ;
if ( V_19 & ~ V_42 ) {
F_16 ( L_10 ,
V_19 ) ;
return;
}
V_1 = F_21 ( V_19 ) ;
V_2 = V_1 >= 0 ? V_1 : - 1 ;
F_14 ( L_11 , V_19 ) ;
}
static void T_2 F_22 ( void )
{
F_14 ( L_12 ) ;
V_16 [ V_17 ] = F_10 ( V_43 ) ;
V_37 . V_44 = F_5 ;
V_16 [ V_18 ] = V_45 ;
V_37 . V_46 = F_6 ;
V_16 [ V_20 ] = F_10 ( V_47 ) ;
V_37 . V_48 = F_7 ;
V_16 [ V_21 ] = F_10 ( V_49 ) ;
V_37 . V_50 = F_8 ;
V_37 . V_51 = F_9 ;
V_37 . V_38 = F_11 ;
V_52 = F_17 ;
V_53 = F_18 ;
}
static int T_2 F_23 ( void )
{
T_1 V_54 = F_3 () ;
F_14 ( L_13 ,
F_24 ( V_54 ) ,
F_25 ( V_54 ) ) ;
if ( F_24 ( V_54 ) == 0 && F_25 ( V_54 ) < 2 ) {
F_20 ( L_14 ) ;
return - V_8 ;
}
F_22 () ;
F_19 () ;
return 0 ;
}
static int T_2 F_26 ( struct V_27 * V_28 )
{
int V_14 ;
V_14 = F_13 ( V_28 ) ;
if ( V_14 )
goto V_55;
V_14 = F_23 () ;
V_55:
F_27 ( V_28 ) ;
return V_14 ;
}
static int T_2 F_28 ( struct V_27 * V_28 )
{
T_1 V_56 ;
int V_14 ;
V_14 = F_13 ( V_28 ) ;
if ( V_14 )
goto V_55;
F_14 ( L_15 ) ;
if ( ! F_29 ( V_28 , L_16 , & V_56 ) ) {
V_16 [ V_17 ] = V_56 ;
V_37 . V_44 = F_5 ;
}
if ( ! F_29 ( V_28 , L_17 , & V_56 ) ) {
V_16 [ V_18 ] = V_56 ;
V_37 . V_46 = F_6 ;
}
if ( ! F_29 ( V_28 , L_18 , & V_56 ) ) {
V_16 [ V_20 ] = V_56 ;
V_37 . V_48 = F_7 ;
}
if ( ! F_29 ( V_28 , L_19 , & V_56 ) ) {
V_16 [ V_21 ] = V_56 ;
V_37 . V_50 = F_8 ;
}
V_55:
F_27 ( V_28 ) ;
return V_14 ;
}
int T_2 F_30 ( void )
{
struct V_27 * V_28 ;
const struct V_57 * V_58 ;
T_3 V_59 ;
V_28 = F_31 ( NULL , V_60 , & V_58 ) ;
if ( ! V_28 )
return - V_61 ;
V_59 = ( T_3 ) V_58 -> V_62 ;
return V_59 ( V_28 ) ;
}
int T_2 F_32 ( void )
{
if ( ! F_33 () ) {
F_14 ( L_20 ) ;
return - V_6 ;
}
F_14 ( L_21 ) ;
if ( F_34 () )
F_4 = V_31 ;
else
F_4 = V_32 ;
return F_23 () ;
}
