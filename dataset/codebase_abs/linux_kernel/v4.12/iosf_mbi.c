static inline T_1 F_1 ( T_2 V_1 , T_2 V_2 , T_2 V_3 )
{
return ( V_1 << 24 ) | ( V_2 << 16 ) | ( V_3 << 8 ) | V_4 ;
}
static int F_2 ( T_1 V_5 , T_1 V_6 , T_1 * V_7 )
{
int V_8 ;
if ( ! V_9 )
return - V_10 ;
if ( V_5 ) {
V_8 = F_3 ( V_9 , V_11 ,
V_5 ) ;
if ( V_8 < 0 )
goto V_12;
}
V_8 = F_3 ( V_9 , V_13 , V_6 ) ;
if ( V_8 < 0 )
goto V_12;
V_8 = F_4 ( V_9 , V_14 , V_7 ) ;
if ( V_8 < 0 )
goto V_12;
return 0 ;
V_12:
F_5 ( & V_9 -> V_15 , L_1 , V_8 ) ;
return V_8 ;
}
static int F_6 ( T_1 V_5 , T_1 V_6 , T_1 V_7 )
{
int V_8 ;
if ( ! V_9 )
return - V_10 ;
V_8 = F_3 ( V_9 , V_14 , V_7 ) ;
if ( V_8 < 0 )
goto V_16;
if ( V_5 ) {
V_8 = F_3 ( V_9 , V_11 ,
V_5 ) ;
if ( V_8 < 0 )
goto V_16;
}
V_8 = F_3 ( V_9 , V_13 , V_6 ) ;
if ( V_8 < 0 )
goto V_16;
return 0 ;
V_16:
F_5 ( & V_9 -> V_15 , L_1 , V_8 ) ;
return V_8 ;
}
int F_7 ( T_2 V_2 , T_2 V_17 , T_1 V_3 , T_1 * V_7 )
{
T_1 V_6 , V_5 ;
unsigned long V_18 ;
int V_19 ;
if ( V_2 == V_20 ) {
F_8 ( 1 ) ;
return - V_21 ;
}
V_6 = F_1 ( V_17 , V_2 , V_3 & V_22 ) ;
V_5 = V_3 & V_23 ;
F_9 ( & V_24 , V_18 ) ;
V_19 = F_2 ( V_5 , V_6 , V_7 ) ;
F_10 ( & V_24 , V_18 ) ;
return V_19 ;
}
int F_11 ( T_2 V_2 , T_2 V_17 , T_1 V_3 , T_1 V_7 )
{
T_1 V_6 , V_5 ;
unsigned long V_18 ;
int V_19 ;
if ( V_2 == V_20 ) {
F_8 ( 1 ) ;
return - V_21 ;
}
V_6 = F_1 ( V_17 , V_2 , V_3 & V_22 ) ;
V_5 = V_3 & V_23 ;
F_9 ( & V_24 , V_18 ) ;
V_19 = F_6 ( V_5 , V_6 , V_7 ) ;
F_10 ( & V_24 , V_18 ) ;
return V_19 ;
}
int F_12 ( T_2 V_2 , T_2 V_17 , T_1 V_3 , T_1 V_7 , T_1 V_25 )
{
T_1 V_6 , V_5 ;
T_1 V_26 ;
unsigned long V_18 ;
int V_19 ;
if ( V_2 == V_20 ) {
F_8 ( 1 ) ;
return - V_21 ;
}
V_6 = F_1 ( V_17 , V_2 , V_3 & V_22 ) ;
V_5 = V_3 & V_23 ;
F_9 ( & V_24 , V_18 ) ;
V_19 = F_2 ( V_5 , V_6 & V_27 , & V_26 ) ;
if ( V_19 < 0 ) {
F_10 ( & V_24 , V_18 ) ;
return V_19 ;
}
V_26 &= ~ V_25 ;
V_7 &= V_25 ;
V_26 |= V_7 ;
V_19 = F_6 ( V_5 , V_6 | V_28 , V_26 ) ;
F_10 ( & V_24 , V_18 ) ;
return V_19 ;
}
bool F_13 ( void )
{
return V_9 ;
}
void F_14 ( void )
{
F_15 ( & V_29 ) ;
}
void F_16 ( void )
{
F_17 ( & V_29 ) ;
}
int F_18 ( struct V_30 * V_31 )
{
int V_19 ;
F_15 ( & V_29 ) ;
V_19 = F_19 (
& V_32 , V_31 ) ;
F_17 ( & V_29 ) ;
return V_19 ;
}
int F_20 ( struct V_30 * V_31 )
{
int V_19 ;
F_15 ( & V_29 ) ;
V_19 = F_21 (
& V_32 , V_31 ) ;
F_17 ( & V_29 ) ;
return V_19 ;
}
int F_22 ( unsigned long V_33 , void * V_34 )
{
return F_23 (
& V_32 , V_33 , V_34 ) ;
}
static int F_24 ( void * V_35 , T_3 * V_33 )
{
* V_33 = * ( T_1 * ) V_35 ;
return 0 ;
}
static int F_25 ( void * V_35 , T_3 V_33 )
{
T_2 V_36 = ( ( T_1 ) V_33 & 0xFF000000 ) >> 24 ,
V_2 = ( ( T_1 ) V_33 & 0x00FF0000 ) >> 16 ,
V_3 = ( ( T_1 ) V_33 & 0x0000FF00 ) >> 8 ;
int V_37 ;
* ( T_1 * ) V_35 = V_33 ;
if ( ! F_26 ( V_38 ) )
return - V_39 ;
if ( V_36 & 1u )
V_37 = F_11 ( V_2 ,
V_36 ,
V_40 | V_3 ,
V_41 ) ;
else
V_37 = F_7 ( V_2 ,
V_36 ,
V_40 | V_3 ,
& V_41 ) ;
return V_37 ;
}
static void F_27 ( void )
{
struct V_42 * V_43 ;
V_44 = F_28 ( L_2 , NULL ) ;
if ( F_29 ( V_44 ) )
return;
V_43 = F_30 ( L_3 , 0660 , V_44 , & V_41 ) ;
if ( ! V_43 )
goto V_45;
V_43 = F_30 ( L_4 , 0660 , V_44 , & V_40 ) ;
if ( ! V_43 )
goto V_45;
V_43 = F_31 ( L_5 , 0660 , V_44 , & V_46 , & V_47 ) ;
if ( ! V_43 )
goto V_45;
return;
V_45:
F_32 ( V_43 ) ;
}
static void F_33 ( void )
{
F_27 () ;
}
static void F_34 ( void )
{
F_32 ( V_44 ) ;
}
static inline void F_33 ( void ) { }
static inline void F_34 ( void ) { }
static int F_35 ( struct V_48 * V_49 ,
const struct V_50 * V_51 )
{
int V_19 ;
V_19 = F_36 ( V_49 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_49 -> V_15 , L_6 ) ;
return V_19 ;
}
V_9 = F_37 ( V_49 ) ;
return 0 ;
}
static int T_4 F_38 ( void )
{
F_33 () ;
return F_39 ( & V_52 ) ;
}
static void T_5 F_40 ( void )
{
F_34 () ;
F_41 ( & V_52 ) ;
F_42 ( V_9 ) ;
V_9 = NULL ;
}
