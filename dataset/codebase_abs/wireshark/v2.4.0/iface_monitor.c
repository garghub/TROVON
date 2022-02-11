static inline struct V_1 * F_1 ( void )
{
return F_2 () ;
}
static inline void F_3 ( struct V_2 * V_3 )
{
F_4 ( V_3 ) ;
}
static void
F_5 ( struct V_4 * V_5 , void * V_6 )
{
struct V_7 * V_8 ;
struct V_7 * V_9 ;
int V_10 , V_11 ;
char * V_12 ;
T_1 V_13 = ( T_1 ) V_6 ;
V_8 = F_6 () ;
if ( ! V_8 ) {
fprintf ( V_14 , L_1 ) ;
return;
}
if ( F_7 ( V_5 , F_8 ( V_8 ) ) == 0 ) {
F_9 ( V_8 ) ;
return;
}
V_9 = (struct V_7 * ) V_5 ;
V_10 = F_10 ( V_9 ) ;
V_12 = F_11 ( V_9 ) ;
V_11 = ( V_10 & V_15 ) ? 1 : 0 ;
V_13 ( V_12 , V_11 ) ;
F_9 ( V_8 ) ;
return;
}
static int
F_12 ( struct V_16 * V_17 , void * V_6 )
{
F_13 ( V_17 , & F_5 , V_6 ) ;
return 0 ;
}
void
F_14 ( void )
{
F_15 ( V_18 ) ;
}
int
F_16 ( void )
{
return F_17 ( V_18 ) ;
}
int
F_18 ( T_1 V_13 )
{
int V_19 ;
V_18 = F_1 () ;
if ( ! V_18 ) {
fprintf ( V_14 , L_2 ) ;
return - V_20 ;
}
F_19 ( V_18 ) ;
F_20 ( V_18 , V_21 , V_22 , F_12 , ( void * ) V_13 ) ;
if ( F_21 ( V_18 , V_23 ) ) {
fprintf ( V_14 , L_3 ) ;
V_19 = - V_24 ;
goto V_25;
}
F_22 ( V_18 , V_26 ) ;
return 0 ;
V_25:
F_3 ( V_18 ) ;
return V_19 ;
}
void
F_23 ( void )
{
if( V_18 )
F_3 ( V_18 ) ;
V_18 = NULL ;
}
int
F_18 ( T_1 V_13 )
{
int V_27 ;
struct V_28 V_29 ;
V_30 = F_24 ( V_31 , V_32 , V_33 ) ;
if ( V_30 == - 1 )
return - V_34 ;
V_29 . V_35 = V_36 ;
V_29 . V_37 = V_38 ;
V_29 . V_39 = V_40 ;
if ( F_25 ( V_30 , V_41 , & V_29 ) == - 1 ) {
V_27 = - V_34 ;
F_26 ( V_30 ) ;
return V_27 ;
}
V_42 = V_13 ;
return 0 ;
}
void
F_23 ( void )
{
F_26 ( V_30 ) ;
}
int
F_16 ( void )
{
return V_30 ;
}
void
F_14 ( void )
{
char V_17 [ V_43 ] ;
T_2 V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
T_3 V_49 ;
char V_50 [ V_51 ] ;
V_44 = F_27 ( V_30 , V_17 , sizeof V_17 , 0 ) ;
if ( V_44 < 0 ) {
return;
}
if ( ( T_3 ) V_44 < sizeof V_17 ) {
return;
}
V_46 = (struct V_45 * ) V_17 ;
V_49 = V_46 -> V_52 - V_53 ;
if ( V_49 != sizeof ( struct V_47 ) ) {
return;
}
V_48 = (struct V_47 * ) & V_46 -> V_54 [ 0 ] ;
F_28 ( V_50 , V_51 , L_4 , V_48 -> V_55 , V_48 -> V_56 ) ;
switch ( V_46 -> V_57 ) {
case V_58 :
V_42 ( V_50 , 1 ) ;
break;
case V_59 :
V_42 ( V_50 , 0 ) ;
break;
default:
break;
}
}
int
F_18 ( T_1 V_13 V_60 )
{
return - 1 ;
}
void
F_23 ( void )
{
}
int
F_16 ( void )
{
return - 1 ;
}
void
F_14 ( void )
{
}
