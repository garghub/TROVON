static void F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 )
F_1 ( V_1 -> V_2 ) ;
V_1 -> V_3 ++ ;
}
static void F_2 ( struct V_1 * V_1 )
{
if ( F_3 ( V_1 -> V_3 == 0 ) )
return;
-- V_1 -> V_3 ;
if ( V_1 -> V_2 )
F_2 ( V_1 -> V_2 ) ;
}
int F_4 ( struct V_1 * V_1 )
{
unsigned long V_4 ;
if ( V_1 == NULL || F_5 ( V_1 ) )
return - V_5 ;
F_6 ( & V_6 , V_4 ) ;
F_1 ( V_1 ) ;
F_7 ( & V_6 , V_4 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_1 )
{
unsigned long V_4 ;
if ( V_1 == NULL || F_5 ( V_1 ) )
return;
F_6 ( & V_6 , V_4 ) ;
F_2 ( V_1 ) ;
F_7 ( & V_6 , V_4 ) ;
}
unsigned long F_9 ( struct V_1 * V_1 )
{
if ( V_1 == NULL || F_5 ( V_1 ) )
return - V_5 ;
return V_1 -> V_7 ;
}
long F_10 ( struct V_1 * V_1 , unsigned long V_7 )
{
if ( V_1 == NULL || F_5 ( V_1 ) )
return - V_5 ;
if ( V_1 -> V_8 )
return V_1 -> V_8 ( V_1 , V_7 ) ;
return V_1 -> V_7 ;
}
static void F_11 ( struct V_1 * V_9 )
{
struct V_1 * V_1 ;
F_12 (clk, &root->children, childnode) {
if ( V_1 -> V_10 )
V_1 -> V_7 = V_1 -> V_10 ( V_1 ) ;
F_11 ( V_1 ) ;
}
}
int F_13 ( struct V_1 * V_1 , unsigned long V_7 )
{
unsigned long V_4 ;
int V_11 = - V_5 ;
if ( V_1 == NULL || F_5 ( V_1 ) )
return V_11 ;
if ( V_1 -> V_12 )
V_11 = V_1 -> V_12 ( V_1 , V_7 ) ;
F_6 ( & V_6 , V_4 ) ;
if ( V_11 == 0 ) {
if ( V_1 -> V_10 )
V_1 -> V_7 = V_1 -> V_10 ( V_1 ) ;
F_11 ( V_1 ) ;
}
F_7 ( & V_6 , V_4 ) ;
return V_11 ;
}
int F_14 ( struct V_1 * V_1 , struct V_1 * V_2 )
{
unsigned long V_4 ;
if ( V_1 == NULL || F_5 ( V_1 ) )
return - V_5 ;
if ( F_3 ( V_1 -> V_3 ) )
return - V_5 ;
F_15 ( & V_13 ) ;
V_1 -> V_2 = V_2 ;
F_16 ( & V_1 -> V_14 ) ;
F_17 ( & V_1 -> V_14 , & V_1 -> V_2 -> V_15 ) ;
F_18 ( & V_13 ) ;
F_6 ( & V_6 , V_4 ) ;
if ( V_1 -> V_10 )
V_1 -> V_7 = V_1 -> V_10 ( V_1 ) ;
F_11 ( V_1 ) ;
F_7 ( & V_6 , V_4 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_1 )
{
if ( V_1 == NULL || F_5 ( V_1 ) )
return - V_5 ;
if ( F_20 ( V_1 -> V_2 && ! V_1 -> V_2 -> V_7 ,
L_1 ,
V_1 -> V_16 , V_1 -> V_2 -> V_16 ) )
return - V_5 ;
F_15 ( & V_13 ) ;
F_21 ( & V_1 -> V_17 , & V_18 ) ;
if ( V_1 -> V_2 )
F_21 ( & V_1 -> V_14 , & V_1 -> V_2 -> V_15 ) ;
F_18 ( & V_13 ) ;
if ( V_1 -> V_7 )
return 0 ;
if ( V_1 -> V_10 )
V_1 -> V_7 = V_1 -> V_10 ( V_1 ) ;
else if ( V_1 -> V_2 )
V_1 -> V_7 = V_1 -> V_2 -> V_7 ;
return 0 ;
}
void F_22 ( struct V_1 * V_1 )
{
if ( V_1 == NULL || F_5 ( V_1 ) )
return;
F_15 ( & V_13 ) ;
F_23 ( & V_1 -> V_17 ) ;
F_23 ( & V_1 -> V_14 ) ;
F_18 ( & V_13 ) ;
}
static T_1 F_24 ( struct V_19 * V_20 , int V_21 )
{
return F_25 ( V_20 -> V_22 + V_21 ) ;
}
static unsigned long F_26 ( struct V_1 * V_1 )
{
T_1 V_23 , V_24 = 0 ;
struct V_19 * V_20 ;
unsigned long V_7 = V_1 -> V_7 ;
if ( F_3 ( ! V_1 -> V_2 ) )
return V_7 ;
V_7 = V_1 -> V_2 -> V_7 ;
if ( F_3 ( ! V_1 -> V_2 -> V_19 ) )
return V_7 ;
V_20 = V_1 -> V_2 -> V_19 ;
if ( V_1 -> V_4 & V_25 )
V_7 = V_20 -> V_26 ;
if ( ! V_1 -> div ) {
F_27 ( L_2 ,
V_1 -> V_16 , V_7 / 1000 ) ;
return V_7 ;
}
if ( V_1 -> V_4 & V_27 ) {
V_7 /= V_1 -> div ;
F_27 ( L_3 ,
V_1 -> V_16 , V_1 -> div , V_7 / 1000 ) ;
return V_7 ;
}
V_23 = F_24 ( V_20 , V_1 -> div ) ;
if ( V_23 & V_28 )
V_24 = ( V_23 & V_29 ) + 1 ;
if ( V_24 == 0 )
V_24 = 1 ;
V_7 /= V_24 ;
F_27 ( L_4 ,
V_1 -> V_16 , V_24 , V_7 / 1000 ) ;
return V_7 ;
}
static unsigned long F_28 ( struct V_1 * V_1 )
{
if ( F_3 ( ! V_1 -> V_2 ) )
return V_1 -> V_7 ;
F_27 ( L_5 ,
V_1 -> V_16 , V_1 -> V_2 -> V_16 , V_1 -> V_2 -> V_7 / 1000 ) ;
return V_1 -> V_2 -> V_7 ;
}
static unsigned long F_29 ( struct V_1 * V_1 )
{
T_1 V_30 , V_31 = 0 , V_32 = 0 , V_33 = 0 ;
T_2 V_34 ;
struct V_19 * V_20 = V_1 -> V_19 ;
unsigned long V_7 = V_1 -> V_7 ;
if ( V_1 -> V_4 & V_35 )
return V_7 ;
V_30 = F_24 ( V_20 , V_36 ) ;
V_7 = V_20 -> V_26 = V_1 -> V_2 -> V_7 ;
if ( V_30 & V_37 )
V_34 = 0 ;
else
V_34 = 1 ;
if ( V_20 -> V_4 & V_38 ) {
V_31 = F_24 ( V_20 , V_39 ) ;
V_31 = ( V_31 & V_40 ) + 1 ;
}
if ( V_20 -> V_4 & V_41 ) {
V_32 = F_24 ( V_20 , V_42 ) ;
if ( V_32 & V_28 )
V_32 = ( V_32 & V_29 ) + 1 ;
else
V_32 = 0 ;
}
if ( V_20 -> V_4 & V_43 ) {
V_33 = F_24 ( V_20 , V_44 ) ;
if ( V_33 & V_28 )
V_33 = ( V_33 & V_29 ) + 1 ;
else
V_33 = 1 ;
}
if ( ! V_34 ) {
if ( V_32 )
V_7 /= V_32 ;
if ( V_31 )
V_7 *= V_31 ;
if ( V_33 )
V_7 /= V_33 ;
F_27 ( L_6
L_7 ,
V_20 -> V_45 , V_1 -> V_2 -> V_7 / 1000000 ,
V_32 , V_31 , V_33 , V_7 / 1000000 ) ;
} else
F_27 ( L_8 ,
V_20 -> V_45 , V_1 -> V_2 -> V_7 / 1000000 ) ;
return V_7 ;
}
static void T_3 F_30 ( struct V_1 * V_1 )
{
F_31 ( & V_1 -> V_17 ) ;
F_31 ( & V_1 -> V_15 ) ;
F_31 ( & V_1 -> V_14 ) ;
if ( ! V_1 -> V_10 ) {
if ( V_1 -> V_19 )
V_1 -> V_10 = F_29 ;
else if ( V_1 -> V_4 & V_46 )
V_1 -> V_10 = F_26 ;
else if ( V_1 -> V_2 )
V_1 -> V_10 = F_28 ;
}
}
void T_3 F_32 ( struct V_47 * V_18 )
{
struct V_47 * V_48 ;
struct V_1 * V_1 ;
T_4 V_49 = 0 ;
for ( V_48 = V_18 ; V_48 -> V_1 ; V_48 ++ ) {
V_1 = V_48 -> V_1 ;
F_30 ( V_1 ) ;
F_19 ( V_1 ) ;
V_49 ++ ;
if ( V_1 -> V_4 & V_50 )
F_4 ( V_1 ) ;
}
F_33 ( V_18 , V_49 ) ;
}
static void
F_34 ( struct V_51 * V_52 , unsigned V_53 , struct V_1 * V_2 )
{
char * V_54 ;
char V_55 [ V_56 + V_57 * V_58 ] ;
struct V_1 * V_1 ;
unsigned V_59 ;
if ( V_2 -> V_4 & V_46 )
V_54 = L_9 ;
else
V_54 = L_10 ;
memset ( V_55 , ' ' , sizeof( V_55 ) - 1 ) ;
V_55 [ sizeof( V_55 ) - 1 ] = 0 ;
V_59 = strlen ( V_2 -> V_16 ) ;
memcpy ( V_55 + V_53 , V_2 -> V_16 ,
F_35 ( V_59 , ( unsigned ) ( sizeof( V_55 ) - 1 - V_53 ) ) ) ;
F_36 ( V_52 , L_11 ,
V_55 , V_2 -> V_3 , V_54 , F_9 ( V_2 ) ) ;
F_12 (clk, &parent->children, childnode) {
F_34 ( V_52 , V_53 + V_57 , V_1 ) ;
}
}
static int F_37 ( struct V_51 * V_60 , void * V_23 )
{
struct V_1 * V_1 ;
F_15 ( & V_13 ) ;
F_12 (clk, &clocks, node)
if ( ! V_1 -> V_2 )
F_34 ( V_60 , 0 , V_1 ) ;
F_18 ( & V_13 ) ;
return 0 ;
}
static int F_38 ( struct V_61 * V_61 , struct V_62 * V_62 )
{
return F_39 ( V_62 , F_37 , NULL ) ;
}
static int T_3 F_40 ( void )
{
F_41 ( L_12 , V_63 | V_64 , NULL , NULL ,
& V_65 ) ;
return 0 ;
}
