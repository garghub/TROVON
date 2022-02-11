int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 -> V_6 & V_7 )
return - V_8 ;
V_2 -> V_5 -> V_6 = V_4 -> V_6 | V_9 ;
V_2 -> V_5 -> div = V_4 -> div ;
F_2 () ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_10 -> V_6 & V_7 )
return - V_8 ;
V_2 -> V_10 -> V_6 = V_4 -> V_6 & ~ V_9 ;
V_2 -> V_10 -> div = V_4 -> div ;
F_2 () ;
return 0 ;
}
static int F_4 ( T_1 V_11 )
{
switch ( V_11 ) {
case 1 :
return V_12 | V_13 ;
case 2 :
return V_14 | V_15 ;
default:
return V_16 | V_17 ;
}
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_18 , V_2 -> V_19 ) ;
F_7 ( V_2 -> V_18 , V_20 | V_21
| F_4 ( V_2 -> V_11 ) | V_22 ) ;
F_8 ( V_2 -> V_18 ) ;
V_2 -> V_5 -> V_6 |= V_7 ;
F_2 () ;
}
void F_9 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_23 , V_2 -> V_24 ) ;
F_7 ( V_2 -> V_23 , V_20 | V_21 | V_25
| F_4 ( V_2 -> V_11 ) | V_22 ) ;
F_8 ( V_2 -> V_23 ) ;
V_2 -> V_10 -> V_6 |= V_7 ;
F_2 () ;
}
void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_5 -> V_6 &= ~ V_7 ;
F_2 () ;
F_11 ( V_2 -> V_18 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
V_2 -> V_10 -> V_6 &= ~ V_7 ;
F_2 () ;
F_11 ( V_2 -> V_23 ) ;
}
void F_13 ( struct V_1 * V_2 ,
void (* F_14)( void * ) , void * V_26 )
{
V_2 -> F_14 = F_14 ;
V_2 -> V_26 = V_26 ;
}
void F_15 ( struct V_1 * V_2 ,
void (* F_16)( void * ) , void * V_27 )
{
V_2 -> F_16 = F_16 ;
V_2 -> V_27 = V_27 ;
}
static void F_17 ( struct V_28 * V_29 , void * V_30 , int V_31 ,
T_1 V_32 , unsigned int V_33 ,
unsigned int V_34 , T_1 V_11 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_31 ; ++ V_35 ) {
V_29 [ V_35 ] . V_36 = & ( V_29 [ V_35 + 1 ] ) ;
V_29 [ V_35 ] . V_37 = ( unsigned long ) V_30 + V_35 * V_32 ;
V_29 [ V_35 ] . V_33 = V_33 ;
V_29 [ V_35 ] . V_38 = V_34 ;
V_29 [ V_35 ] . V_39 = V_11 ;
V_29 [ V_35 ] . V_40 = 0 ;
V_29 [ V_35 ] . V_41 = 0 ;
}
V_29 [ V_31 - 1 ] . V_36 = V_29 ;
}
int F_18 ( struct V_1 * V_2 , void * V_30 ,
int V_31 , T_1 V_32 )
{
unsigned int V_34 ;
unsigned int V_33 ;
T_2 V_42 ;
V_34 = V_32 / V_2 -> V_11 ;
if ( V_2 -> V_19 )
F_19 ( NULL , V_2 -> V_43 ,
V_2 -> V_19 , 0 ) ;
V_2 -> V_19 = F_20 ( NULL ,
V_31 * sizeof( struct V_28 ) , & V_42 , 0 ) ;
V_2 -> V_43 = V_31 * sizeof( struct V_28 ) ;
if ( ! V_2 -> V_19 )
return - V_44 ;
V_2 -> V_45 = V_30 ;
V_2 -> V_46 = V_32 ;
V_2 -> V_47 = V_31 ;
V_33 = V_20 | V_21 | F_4 ( V_2 -> V_11 ) | V_22 ;
F_17 ( V_2 -> V_19 , V_30 , V_31 , V_32 ,
V_33 | V_48 , V_34 , V_2 -> V_11 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , void * V_30 ,
int V_31 , T_1 V_32 )
{
unsigned int V_34 ;
unsigned int V_33 ;
T_2 V_42 ;
V_34 = V_32 / V_2 -> V_11 ;
if ( V_2 -> V_24 )
F_19 ( NULL , V_2 -> V_49 ,
V_2 -> V_24 , 0 ) ;
V_2 -> V_24 = F_20 ( NULL ,
V_31 * sizeof( struct V_28 ) , & V_42 , 0 ) ;
V_2 -> V_49 = V_31 * sizeof( struct V_28 ) ;
if ( ! V_2 -> V_24 )
return - V_44 ;
V_2 -> V_50 = V_30 ;
V_2 -> V_51 = V_32 ;
V_2 -> V_52 = V_31 ;
V_33 = V_20 | V_21 | F_4 ( V_2 -> V_11 )
| V_25 | V_22 ;
F_17 ( V_2 -> V_24 , V_30 , V_31 , V_32 ,
V_33 | V_48 , V_34 , V_2 -> V_11 ) ;
return 0 ;
}
unsigned long F_22 ( struct V_1 * V_2 )
{
unsigned long V_53 = F_23 ( V_2 -> V_18 ) ;
return ( unsigned char * ) V_53 - V_2 -> V_45 ;
}
unsigned long F_24 ( struct V_1 * V_2 )
{
unsigned long V_53 = F_23 ( V_2 -> V_23 ) ;
return ( unsigned char * ) V_53 - V_2 -> V_50 ;
}
static T_3 F_25 ( int V_54 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
static unsigned long V_56 ;
V_56 = F_26 ( V_2 -> V_18 ) ;
if ( V_56 & ( V_57 | V_58 ) ) {
F_27 ( V_2 -> V_18 ) ;
F_2 () ;
}
if ( V_2 -> F_14 )
V_2 -> F_14 ( V_2 -> V_26 ) ;
return V_59 ;
}
static T_3 F_28 ( int V_54 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
unsigned long V_56 ;
V_56 = F_26 ( V_2 -> V_23 ) ;
if ( V_56 & ( V_57 | V_58 ) ) {
F_27 ( V_2 -> V_23 ) ;
F_2 () ;
}
if ( V_2 -> F_16 )
V_2 -> F_16 ( V_2 -> V_27 ) ;
return V_59 ;
}
static T_3 F_29 ( int V_54 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
struct V_60 * V_61 = & V_2 -> V_62 -> V_61 ;
if ( V_2 -> V_5 -> V_6 & V_63 )
F_30 ( V_61 , L_1 ) ;
if ( V_2 -> V_10 -> V_6 & V_63 )
F_30 ( V_61 , L_2 ) ;
return V_59 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_64 * V_62 = V_2 -> V_62 ;
struct V_60 * V_61 = & V_62 -> V_61 ;
struct V_65 * V_66 = V_61 -> V_67 ;
struct V_68 * V_69 ;
if ( ! V_66 ) {
F_30 ( V_61 , L_3 ) ;
return - V_70 ;
}
V_2 -> V_71 = V_66 -> V_71 ;
V_69 = F_32 ( V_62 , V_72 , 0 ) ;
if ( ! V_69 ) {
F_30 ( V_61 , L_4 ) ;
return - V_70 ;
}
V_2 -> V_5 = (struct V_73 * ) V_69 -> V_74 ;
V_69 = F_32 ( V_62 , V_72 , 1 ) ;
if ( ! V_69 ) {
F_30 ( V_61 , L_5 ) ;
return - V_70 ;
}
V_2 -> V_10 = (struct V_73 * ) V_69 -> V_74 ;
V_69 = F_32 ( V_62 , V_75 , 0 ) ;
if ( ! V_69 ) {
F_30 ( V_61 , L_6 ) ;
return - V_70 ;
}
V_2 -> V_18 = V_69 -> V_74 ;
V_69 = F_32 ( V_62 , V_75 , 1 ) ;
if ( ! V_69 ) {
F_30 ( V_61 , L_7 ) ;
return - V_70 ;
}
V_2 -> V_23 = V_69 -> V_74 ;
V_69 = F_32 ( V_62 , V_76 , 0 ) ;
if ( ! V_69 ) {
F_30 ( V_61 , L_8 ) ;
return - V_70 ;
}
V_2 -> V_77 = V_69 -> V_74 ;
V_69 = F_32 ( V_62 , V_76 , 1 ) ;
if ( ! V_69 ) {
F_30 ( V_61 , L_9 ) ;
return - V_70 ;
}
V_2 -> V_78 = V_69 -> V_74 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = & V_2 -> V_62 -> V_61 ;
int V_79 ;
V_79 = F_34 ( V_2 -> V_71 , L_10 ) ;
if ( V_79 ) {
F_30 ( V_61 , L_11 ) ;
return V_79 ;
}
V_79 = F_35 ( V_2 -> V_18 , L_12 ) ;
if ( V_79 ) {
F_30 ( V_61 , L_13 ) ;
goto V_80;
}
F_36 ( V_2 -> V_18 , F_25 , V_2 ) ;
V_79 = F_35 ( V_2 -> V_23 , L_14 ) ;
if ( V_79 ) {
F_30 ( V_61 , L_15 ) ;
goto V_81;
}
F_36 ( V_2 -> V_23 , F_28 , V_2 ) ;
V_79 = F_37 ( V_2 -> V_77 , F_29 ,
0 , L_16 , V_2 ) ;
if ( V_79 ) {
F_30 ( V_61 , L_17 ) ;
goto V_82;
}
V_79 = F_37 ( V_2 -> V_78 , F_29 ,
0 , L_18 , V_2 ) ;
if ( V_79 ) {
F_30 ( V_61 , L_19 ) ;
goto V_83;
}
return 0 ;
V_83:
F_38 ( V_2 -> V_77 , V_2 ) ;
V_82:
F_39 ( V_2 -> V_23 ) ;
V_81:
F_39 ( V_2 -> V_18 ) ;
V_80:
F_40 ( V_2 -> V_71 ) ;
return V_79 ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_38 ( V_2 -> V_78 , V_2 ) ;
F_38 ( V_2 -> V_77 , V_2 ) ;
F_39 ( V_2 -> V_23 ) ;
F_39 ( V_2 -> V_18 ) ;
F_40 ( V_2 -> V_71 ) ;
}
struct V_1 * F_42 ( struct V_64 * V_62 )
{
struct V_60 * V_61 = & V_62 -> V_61 ;
struct V_1 * V_2 ;
int V_79 ;
V_2 = F_43 ( sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 ) {
F_30 ( V_61 , L_20 ) ;
return NULL ;
}
V_2 -> V_62 = V_62 ;
V_79 = F_31 ( V_2 ) ;
if ( V_79 ) {
F_44 ( V_2 ) ;
return NULL ;
}
V_79 = F_33 ( V_2 ) ;
if ( V_79 ) {
F_44 ( V_2 ) ;
return NULL ;
}
F_45 ( V_61 , L_21 ) ;
return V_2 ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 )
F_19 ( NULL , V_2 -> V_43 ,
V_2 -> V_19 , 0 ) ;
if ( V_2 -> V_24 )
F_19 ( NULL , V_2 -> V_49 ,
V_2 -> V_24 , 0 ) ;
F_41 ( V_2 ) ;
F_44 ( V_2 ) ;
}
