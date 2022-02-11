static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 , 0 ) ;
if ( F_3 ( V_3 ) ) {
F_4 ( L_1 ) ;
return F_5 ( V_3 ) ;
}
V_4 = F_6 ( V_3 ) ;
if ( V_4 ) {
F_4 ( L_2 ) ;
return V_4 ;
}
V_5 = F_7 ( V_3 ) ;
return 0 ;
}
static T_2 F_8 ( struct V_6 * V_7 )
{
unsigned long V_8 ;
T_3 V_9 , V_10 ;
F_9 ( V_8 ) ;
F_10 ( V_11 , 0 ) ;
V_9 = F_11 ( V_12 ) ;
F_10 ( V_13 , 0 ) ;
V_10 = F_11 ( V_12 ) ;
F_12 ( V_8 ) ;
return ( ( ( T_2 ) V_10 ) << 32 ) | V_9 ;
}
static int T_4 F_13 ( struct V_1 * V_2 )
{
struct V_14 V_15 ;
int V_4 ;
F_14 ( V_16 , V_15 ) ;
if ( ! V_15 . V_17 ) {
F_15 ( L_3 ) ;
return - V_18 ;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
return F_16 ( & V_19 , V_5 ) ;
}
static T_2 F_17 ( struct V_6 * V_7 )
{
unsigned long V_20 ;
T_3 V_9 , V_10 ;
do {
V_9 = F_11 ( V_21 ) ;
V_10 = F_11 ( V_22 ) ;
V_20 = F_11 ( V_23 ) ;
} while ( ! ( V_20 & F_18 ( 31 ) ) );
return ( ( ( T_2 ) V_10 ) << 32 ) | V_9 ;
}
static int T_4 F_19 ( struct V_1 * V_2 )
{
struct V_24 V_25 ;
int V_4 ;
F_14 ( V_26 , V_25 ) ;
if ( ! V_25 . V_27 ) {
F_15 ( L_4 ) ;
return - V_18 ;
}
if ( F_20 ( V_28 ) ) {
F_15 ( L_5 ) ;
return - V_29 ;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_21 ( V_23 , 1 ) ;
return F_16 ( & V_30 , V_5 ) ;
}
static T_2 F_22 ( struct V_6 * V_7 )
{
return ( T_2 ) F_11 ( V_31 ) ;
}
static int T_4 F_23 ( struct V_1 * V_2 )
{
int V_4 ;
if ( F_20 ( V_28 ) )
return - V_29 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_21 ( V_32 , V_33 ) ;
F_21 ( V_31 , 0 ) ;
F_21 ( V_34 , V_35 ) ;
return F_16 ( & V_36 , V_5 ) ;
}
static void F_24 ( unsigned int V_37 )
{
F_21 ( V_38 , V_37 ) ;
F_21 ( V_39 , 0 ) ;
F_21 ( V_40 , V_41 | V_35 ) ;
}
static int F_25 ( unsigned long V_42 ,
struct V_43 * V_44 )
{
F_24 ( V_42 ) ;
return 0 ;
}
static int F_26 ( struct V_43 * V_44 )
{
F_24 ( V_5 / V_45 ) ;
return 0 ;
}
static T_5 F_27 ( int V_46 , void * V_47 )
{
struct V_43 * V_48 = F_28 ( & V_49 ) ;
int V_50 = F_29 ( V_48 ) ;
F_21 ( V_40 , V_50 | V_35 ) ;
V_48 -> V_51 ( V_48 ) ;
return V_52 ;
}
static int F_30 ( unsigned int V_53 )
{
struct V_43 * V_48 = F_28 ( & V_49 ) ;
V_48 -> V_54 = F_31 ( F_32 () ) ;
F_33 ( V_48 , V_5 , 0 , V_33 ) ;
F_34 ( V_55 , 0 ) ;
return 0 ;
}
static int F_35 ( unsigned int V_53 )
{
F_36 ( V_55 ) ;
return 0 ;
}
static int T_4 F_37 ( struct V_1 * V_2 )
{
struct V_43 * V_48 = F_28 ( & V_49 ) ;
int V_4 ;
V_55 = F_38 ( V_2 , 0 ) ;
if ( V_55 <= 0 ) {
F_4 ( L_6 ) ;
return - V_29 ;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 ) {
F_4 ( L_7 ) ;
return V_4 ;
}
V_4 = F_39 ( V_55 , F_27 ,
L_8 , V_48 ) ;
if ( V_4 ) {
F_4 ( L_9 ) ;
return V_4 ;
}
V_4 = F_40 ( V_56 ,
L_10 ,
F_30 ,
F_35 ) ;
if ( V_4 ) {
F_4 ( L_11 ) ;
return V_4 ;
}
return 0 ;
}
static int T_4 F_41 ( struct V_1 * V_57 )
{
static int V_58 = 0 ;
int V_4 ;
if ( ! V_58 ) {
V_58 = 1 ;
V_4 = F_37 ( V_57 ) ;
} else {
V_4 = F_23 ( V_57 ) ;
}
return V_4 ;
}
