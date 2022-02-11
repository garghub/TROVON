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
return 0 ;
V_7 = F_9 ( V_13 ) + V_9 ;
return F_10 ( V_15 , V_7 ) ;
}
static void F_11 ( struct V_16 * V_17 )
{
unsigned int V_1 ;
V_1 = F_8 ( 0 , V_18 , & V_2 -> V_19 ,
& V_2 -> V_3 ) ;
if ( V_1 ) {
F_12 ( V_1 ) ;
return;
}
V_1 = F_8 ( 8 , V_20 , & V_2 -> V_21 ,
& V_2 -> V_4 ) ;
if ( V_1 ) {
F_12 ( V_1 ) ;
return;
}
}
static int
F_13 ( struct V_22 * V_23 , struct V_24 * V_25 ,
enum V_26 V_27 )
{
return V_28 == V_25 ;
}
static int
F_14 ( struct V_22 * V_23 , unsigned int V_29 ,
T_3 V_30 )
{
F_15 ( V_29 , V_31 ) ;
F_16 ( V_29 , & V_32 , V_33 ) ;
return 0 ;
}
void T_4
F_17 ( void )
{
struct V_24 * V_34 = NULL ;
V_34 = F_18 ( NULL , NULL , L_1 ) ;
if ( ! V_34 ) {
F_19 ( V_35 L_2 ) ;
return;
}
V_2 = F_20 ( V_34 , 0 ) ;
F_21 ( V_34 ) ;
}
void T_4
F_22 ( void )
{
unsigned int V_36 ;
struct V_24 * V_34 = NULL ;
F_23 ( L_3 ) ;
V_34 = F_18 ( NULL , NULL , L_1 ) ;
if ( ! V_34 ) {
F_19 ( V_35 L_2 ) ;
return;
}
if ( ! V_2 )
goto V_37;
V_36 = F_24 ( V_34 , 0 ) ;
if ( ! V_36 )
goto V_37;
F_5 ( & V_2 -> V_38 , 0xfd ) ;
F_5 ( & V_2 -> V_3 , 0xff ) ;
F_5 ( & V_2 -> V_4 , ~ ( V_20 ) ) ;
V_28 = F_25 ( V_34 ) ;
V_15 = F_26 ( V_34 , 16 , & V_39 , NULL ) ;
if ( ! V_15 ) {
F_19 ( V_35 L_4 ) ;
goto V_37;
}
F_27 ( V_36 , F_11 ) ;
V_37:
F_21 ( V_34 ) ;
}
