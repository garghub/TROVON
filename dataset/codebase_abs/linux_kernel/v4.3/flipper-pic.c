static void F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_3 ( V_2 ) ;
T_2 V_5 = 1 << V_3 ;
F_4 ( V_4 + V_6 , V_5 ) ;
F_5 ( V_4 + V_7 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_3 ( V_2 ) ;
F_5 ( V_4 + V_7 , 1 << V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_3 ( V_2 ) ;
F_4 ( V_4 + V_6 , 1 << V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_3 ( V_2 ) ;
F_9 ( V_4 + V_6 , 1 << V_3 ) ;
}
static int F_10 ( struct V_8 * V_9 , unsigned int V_10 ,
T_3 V_11 )
{
F_11 ( V_10 , V_9 -> V_12 ) ;
F_12 ( V_10 , V_13 ) ;
F_13 ( V_10 , & V_14 , V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 , struct V_16 * V_17 ,
enum V_18 V_19 )
{
return 1 ;
}
static void F_15 ( void T_1 * V_4 )
{
F_5 ( V_4 + V_6 , 0x00000000 ) ;
F_5 ( V_4 + V_7 , 0xffffffff ) ;
}
struct V_8 * T_4 F_16 ( struct V_16 * V_17 )
{
struct V_16 * V_20 ;
struct V_8 * V_8 = NULL ;
struct V_21 V_22 ;
void T_1 * V_4 ;
int V_23 ;
V_20 = F_17 ( V_17 ) ;
if ( ! V_20 ) {
F_18 ( L_1 ) ;
goto V_24;
}
if ( ! F_19 ( V_20 , L_2 ) ) {
F_18 ( L_3 ) ;
goto V_24;
}
V_23 = F_20 ( V_20 , 0 , & V_22 ) ;
if ( V_23 ) {
F_18 ( L_4 ) ;
goto V_24;
}
V_4 = F_21 ( V_22 . V_25 , F_22 ( & V_22 ) ) ;
F_23 ( L_5 , V_22 . V_25 , V_4 ) ;
F_15 ( V_4 ) ;
V_8 = F_24 ( V_17 , V_26 ,
& V_27 , V_4 ) ;
if ( ! V_8 ) {
F_18 ( L_6 ) ;
return NULL ;
}
V_24:
return V_8 ;
}
unsigned int F_25 ( void )
{
void T_1 * V_4 = V_28 -> V_12 ;
int V_3 ;
T_2 V_29 ;
V_29 = F_26 ( V_4 + V_7 ) &
F_26 ( V_4 + V_6 ) ;
if ( V_29 == 0 )
return V_30 ;
V_3 = F_27 ( V_29 ) ;
return F_28 ( V_28 , V_3 ) ;
}
void T_4 F_29 ( void )
{
struct V_16 * V_17 ;
V_17 = F_30 ( NULL , NULL , L_7 ) ;
F_31 ( ! V_17 ) ;
V_28 = F_16 ( V_17 ) ;
F_31 ( ! V_28 ) ;
F_32 ( V_28 ) ;
F_33 ( V_17 ) ;
}
void F_34 ( void )
{
void T_1 * V_4 = V_28 -> V_12 ;
F_15 ( V_4 ) ;
}
void F_35 ( void )
{
void T_1 * V_4 ;
if ( V_28 && V_28 -> V_12 ) {
V_4 = V_28 -> V_12 ;
F_36 ( V_4 + V_31 , 0x00 ) ;
}
}
int F_37 ( void )
{
void T_1 * V_4 ;
T_2 V_32 ;
if ( V_28 && V_28 -> V_12 ) {
V_4 = V_28 -> V_12 ;
V_32 = F_26 ( V_4 + V_7 ) ;
return ! ( V_32 & V_33 ) ;
}
return 0 ;
}
