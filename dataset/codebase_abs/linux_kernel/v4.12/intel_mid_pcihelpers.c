static inline int F_1 ( T_1 V_1 )
{
return ( V_2 . V_3 == V_1 ) ;
}
static int F_2 ( void )
{
V_4 = F_3 ( 0 , F_4 ( 0 , 0 ) ) ;
if ( ! V_4 ) {
F_5 ( L_1 , V_5 ) ;
return - V_6 ;
}
if ( V_7 ) {
F_6 ( & V_8 ,
V_9 ,
V_10 ) ;
}
return 0 ;
}
T_2 F_7 ( T_2 V_11 )
{
unsigned long V_12 ;
T_2 V_13 ;
F_8 ( & V_14 , V_12 ) ;
F_9 ( V_4 , V_15 , V_11 ) ;
F_10 ( V_4 , V_16 , & V_13 ) ;
F_11 ( & V_14 , V_12 ) ;
return V_13 ;
}
T_2 F_12 ( T_2 V_11 , T_2 V_17 )
{
unsigned long V_12 ;
T_2 V_13 ;
F_8 ( & V_14 , V_12 ) ;
F_9 ( V_4 , V_18 , V_17 ) ;
F_9 ( V_4 , V_15 , V_11 ) ;
F_10 ( V_4 , V_16 , & V_13 ) ;
F_11 ( & V_14 , V_12 ) ;
return V_13 ;
}
void F_13 ( T_2 V_11 , T_2 V_13 )
{
unsigned long V_12 ;
F_8 ( & V_14 , V_12 ) ;
F_9 ( V_4 , V_16 , V_13 ) ;
F_9 ( V_4 , V_15 , V_11 ) ;
F_11 ( & V_14 , V_12 ) ;
}
void F_14 ( T_2 V_11 , T_2 V_17 , T_2 V_13 )
{
unsigned long V_12 ;
F_8 ( & V_14 , V_12 ) ;
F_9 ( V_4 , V_16 , V_13 ) ;
F_9 ( V_4 , V_18 , V_17 ) ;
F_9 ( V_4 , V_15 , V_11 ) ;
F_11 ( & V_14 , V_12 ) ;
}
T_2 F_15 ( T_1 V_19 , T_2 V_20 )
{
unsigned long V_12 ;
T_2 V_13 ;
T_2 V_11 ;
T_2 V_21 ;
V_11 = ( V_22 << 24 ) | ( V_19 << 16 ) |
( ( V_20 & 0xff ) << 8 ) | V_23 ;
V_21 = V_20 & 0xffffff00 ;
F_8 ( & V_14 , V_12 ) ;
if ( V_21 ) {
F_9 ( V_4 , V_18 ,
V_21 ) ;
}
F_9 ( V_4 , V_15 , V_11 ) ;
F_10 ( V_4 , V_16 , & V_13 ) ;
F_11 ( & V_14 , V_12 ) ;
return V_13 ;
}
void F_16 ( T_1 V_19 , T_2 V_20 , T_2 V_13 )
{
unsigned long V_12 ;
T_2 V_11 ;
T_2 V_21 ;
V_11 = ( V_24 << 24 ) | ( V_19 << 16 ) |
( ( V_20 & 0xFF ) << 8 ) | V_23 ;
V_21 = V_20 & 0xffffff00 ;
F_8 ( & V_14 , V_12 ) ;
F_9 ( V_4 , V_16 , V_13 ) ;
if ( V_21 ) {
F_9 ( V_4 , V_18 ,
V_21 ) ;
}
F_9 ( V_4 , V_15 , V_11 ) ;
F_11 ( & V_14 , V_12 ) ;
}
T_2 F_17 ( void )
{
return V_4 -> V_25 ;
}
static bool F_18 ( struct V_26 * V_27 )
{
unsigned V_28 = V_27 -> V_29 >> 16 ;
unsigned V_30 = ( V_27 -> V_29 & V_31 ) >> 8 ;
if ( ( ( V_28 == V_32 ) &&
( V_30 == V_33 ) ) ||
( V_28 == V_34 ) ||
( ( V_28 == V_35 ) && ! V_30 ) )
return false ;
else
return true ;
}
static void F_19 ( struct V_26 * V_27 )
{
if ( F_1 ( V_36 ) ||
F_1 ( V_37 ) ) {
if ( V_27 -> V_38 -> V_39 == 0 && F_18 ( V_27 ) ) {
V_27 -> V_40 = V_41 ;
V_27 -> V_42 = V_41 ;
}
}
}
static void F_20 ( void )
{
T_2 V_13 ;
V_13 = F_15 ( V_43 , V_44 ) ;
F_21 () ;
V_13 = V_13 & 0xfffffffc ;
F_16 ( V_43 , V_44 , V_13 ) ;
F_21 () ;
}
int F_22 ( void )
{
T_2 V_45 = 0 ;
T_2 V_13 = 0 ;
T_2 V_11 ;
T_2 V_21 ;
int V_46 = 1000 ;
if ( V_7 )
F_23 ( & V_8 , V_47 - 1 ) ;
F_24 ( F_25 () ) ;
F_26 () ;
F_16 ( V_43 , V_44 , 0x2 ) ;
F_21 () ;
V_11 = ( V_48 << 24 ) | ( V_43 << 16 ) |
( ( V_49 & 0xFF ) << 8 ) | V_23 ;
V_21 = V_49 & 0xffffff00 ;
if ( V_21 )
F_14 ( V_11 , V_21 , V_13 ) ;
else
F_13 ( V_11 , V_13 ) ;
while ( F_27 () != 0x1 ) {
F_28 ( 100 ) ;
V_46 -- ;
if ( V_46 <= 0 ) {
F_5 ( L_2 ) ;
V_45 = - V_50 ;
F_20 () ;
F_28 ( 1000 ) ;
if ( F_27 () != 0 ) {
F_20 () ;
}
F_5 ( L_3 ,
F_15 ( V_43 ,
V_44 ) ) ;
F_29 () ;
if ( V_7 ) {
F_23 ( & V_8 ,
V_10 ) ;
}
return V_45 ;
}
}
F_21 () ;
return V_45 ;
}
int F_30 ( void )
{
F_20 () ;
F_29 () ;
if ( V_7 )
F_23 ( & V_8 , V_10 ) ;
return 0 ;
}
