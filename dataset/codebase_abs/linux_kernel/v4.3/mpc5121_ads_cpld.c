static void T_1 *
F_1 ( unsigned int V_1 )
{
return V_1 <= 7 ? & V_2 -> V_3 : & V_2 -> V_4 ;
}
static unsigned int
F_2 ( unsigned int V_1 )
{
return 1 << ( V_1 & 0x7 ) ;
}
static void
F_3 ( struct V_5 * V_6 )
{
unsigned int V_7 = ( unsigned int ) F_4 ( V_6 ) ;
void T_1 * V_8 = F_1 ( V_7 ) ;
F_5 ( V_8 ,
F_6 ( V_8 ) | F_2 ( V_7 ) ) ;
}
static void
F_7 ( struct V_5 * V_6 )
{
unsigned int V_7 = ( unsigned int ) F_4 ( V_6 ) ;
void T_1 * V_8 = F_1 ( V_7 ) ;
F_5 ( V_8 ,
F_6 ( V_8 ) & ~ F_2 ( V_7 ) ) ;
}
static int
F_8 ( int V_9 , T_2 V_10 , T_2 T_1 * V_11 ,
T_2 T_1 * V_12 )
{
int V_7 ;
T_2 V_13 = F_6 ( V_11 ) ;
T_2 V_14 = F_6 ( V_12 ) ;
V_13 |= ( V_10 | V_14 ) ;
if ( V_13 == 0xff )
return V_15 ;
V_7 = F_9 ( V_13 ) + V_9 ;
return F_10 ( V_16 , V_7 ) ;
}
static void F_11 ( struct V_17 * V_18 )
{
unsigned int V_1 ;
V_1 = F_8 ( 0 , V_19 , & V_2 -> V_20 ,
& V_2 -> V_3 ) ;
if ( V_1 != V_15 ) {
F_12 ( V_1 ) ;
return;
}
V_1 = F_8 ( 8 , V_21 , & V_2 -> V_22 ,
& V_2 -> V_4 ) ;
if ( V_1 != V_15 ) {
F_12 ( V_1 ) ;
return;
}
}
static int
F_13 ( struct V_23 * V_24 , struct V_25 * V_26 ,
enum V_27 V_28 )
{
return V_29 == V_26 ;
}
static int
F_14 ( struct V_23 * V_24 , unsigned int V_30 ,
T_3 V_31 )
{
F_15 ( V_30 , V_32 ) ;
F_16 ( V_30 , & V_33 , V_34 ) ;
return 0 ;
}
void T_4
F_17 ( void )
{
struct V_25 * V_35 = NULL ;
V_35 = F_18 ( NULL , NULL , L_1 ) ;
if ( ! V_35 ) {
F_19 ( V_36 L_2 ) ;
return;
}
V_2 = F_20 ( V_35 , 0 ) ;
F_21 ( V_35 ) ;
}
void T_4
F_22 ( void )
{
unsigned int V_37 ;
struct V_25 * V_35 = NULL ;
F_23 ( L_3 ) ;
V_35 = F_18 ( NULL , NULL , L_1 ) ;
if ( ! V_35 ) {
F_19 ( V_36 L_2 ) ;
return;
}
if ( ! V_2 )
goto V_38;
V_37 = F_24 ( V_35 , 0 ) ;
if ( V_37 == V_15 )
goto V_38;
F_5 ( & V_2 -> V_39 , 0xfd ) ;
F_5 ( & V_2 -> V_3 , 0xff ) ;
F_5 ( & V_2 -> V_4 , ~ ( V_21 ) ) ;
V_29 = F_25 ( V_35 ) ;
V_16 = F_26 ( V_35 , 16 , & V_40 , NULL ) ;
if ( ! V_16 ) {
F_19 ( V_36 L_4 ) ;
goto V_38;
}
F_27 ( V_37 , F_11 ) ;
V_38:
F_21 ( V_35 ) ;
}
