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
static int F_14 ( void * V_29 , T_3 * V_30 )
{
* V_30 = * ( T_1 * ) V_29 ;
return 0 ;
}
static int F_15 ( void * V_29 , T_3 V_30 )
{
T_2 V_31 = ( ( T_1 ) V_30 & 0xFF000000 ) >> 24 ,
V_2 = ( ( T_1 ) V_30 & 0x00FF0000 ) >> 16 ,
V_3 = ( ( T_1 ) V_30 & 0x0000FF00 ) >> 8 ;
int V_32 ;
* ( T_1 * ) V_29 = V_30 ;
if ( ! F_16 ( V_33 ) )
return - V_34 ;
if ( V_31 & 1u )
V_32 = F_11 ( V_2 ,
V_31 ,
V_35 | V_3 ,
V_36 ) ;
else
V_32 = F_7 ( V_2 ,
V_31 ,
V_35 | V_3 ,
& V_36 ) ;
return V_32 ;
}
static void F_17 ( void )
{
struct V_37 * V_38 ;
V_39 = F_18 ( L_2 , NULL ) ;
if ( F_19 ( V_39 ) )
return;
V_38 = F_20 ( L_3 , 0660 , V_39 , & V_36 ) ;
if ( ! V_38 )
goto V_40;
V_38 = F_20 ( L_4 , 0660 , V_39 , & V_35 ) ;
if ( ! V_38 )
goto V_40;
V_38 = F_21 ( L_5 , 0660 , V_39 , & V_41 , & V_42 ) ;
if ( ! V_38 )
goto V_40;
return;
V_40:
F_22 ( V_38 ) ;
}
static void F_23 ( void )
{
F_17 () ;
}
static void F_24 ( void )
{
F_22 ( V_39 ) ;
}
static inline void F_23 ( void ) { }
static inline void F_24 ( void ) { }
static int F_25 ( struct V_43 * V_44 ,
const struct V_45 * V_46 )
{
int V_19 ;
V_19 = F_26 ( V_44 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_44 -> V_15 , L_6 ) ;
return V_19 ;
}
V_9 = F_27 ( V_44 ) ;
return 0 ;
}
static int T_4 F_28 ( void )
{
F_23 () ;
return F_29 ( & V_47 ) ;
}
static void T_5 F_30 ( void )
{
F_24 () ;
F_31 ( & V_47 ) ;
F_32 ( V_9 ) ;
V_9 = NULL ;
}
