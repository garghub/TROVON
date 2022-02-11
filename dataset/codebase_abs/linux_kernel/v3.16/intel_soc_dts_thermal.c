static int F_1 ( T_1 * V_1 )
{
T_1 V_2 , V_3 ;
T_1 V_4 ;
int V_5 ;
V_5 = F_2 ( V_6 , & V_2 , & V_3 ) ;
if ( V_5 )
goto V_7;
else {
V_4 = ( V_2 >> 16 ) & 0xff ;
if ( V_4 )
* V_1 = V_4 * 1000 ;
else {
V_5 = - V_8 ;
goto V_7;
}
}
return 0 ;
V_7:
* V_1 = 0 ;
return V_5 ;
}
static int F_3 ( struct V_9 * V_10 ,
int V_11 , unsigned long * V_12 )
{
int V_13 ;
T_1 V_14 ;
struct V_15 * V_16 ;
V_16 = V_10 -> V_17 ;
if ( ! V_11 ) {
* V_12 = V_16 -> V_1 - V_18 ;
return 0 ;
}
F_4 ( & V_19 ) ;
V_13 = F_5 ( V_20 , V_21 ,
V_22 , & V_14 ) ;
F_6 ( & V_19 ) ;
if ( V_13 )
return V_13 ;
V_14 = ( V_14 >> ( V_11 * 8 ) ) & V_23 ;
if ( ! V_14 )
* V_12 = 0 ;
else
* V_12 = V_16 -> V_1 - V_14 * 1000 ;
return 0 ;
}
static int F_7 ( struct V_15 * V_16 ,
int V_24 , unsigned long V_12 )
{
int V_13 ;
T_1 V_25 ;
T_1 V_14 ;
T_1 V_26 ;
T_1 V_27 ;
T_1 V_28 ;
T_1 V_29 ;
T_1 V_30 = V_31 |
V_32 ;
V_25 = ( V_16 -> V_1 - V_12 ) / 1000 ;
V_13 = F_5 ( V_20 , V_21 ,
V_22 , & V_26 ) ;
if ( V_13 )
return V_13 ;
V_14 = ( V_26 & ~ ( 0xFF << ( V_24 * 8 ) ) ) ;
V_14 |= ( V_25 & 0xFF ) << ( V_24 * 8 ) ;
V_13 = F_8 ( V_20 , V_33 ,
V_22 , V_14 ) ;
if ( V_13 )
return V_13 ;
F_9 ( L_1 , V_14 ) ;
V_13 = F_5 ( V_20 , V_21 ,
V_34 , & V_14 ) ;
if ( V_13 )
goto V_35;
V_27 = V_14 ;
V_13 = F_5 ( V_20 , V_21 ,
V_36 + V_24 ,
& V_29 ) ;
if ( V_13 )
goto V_37;
V_28 = V_29 ;
V_14 |= ( V_38 |
V_39 ) ;
if ( V_12 ) {
if ( V_24 )
V_14 |= V_40 ;
else
V_14 |= V_41 ;
V_29 |= V_30 ;
} else {
if ( V_24 )
V_14 &= ~ V_40 ;
else
V_14 &= ~ V_41 ;
V_29 &= ~ V_30 ;
}
V_13 = F_8 ( V_20 , V_33 ,
V_34 , V_14 ) ;
if ( V_13 )
goto V_42;
V_13 = F_8 ( V_20 , V_33 ,
V_36 + V_24 ,
V_29 ) ;
if ( V_13 )
goto V_42;
return 0 ;
V_42:
F_8 ( V_20 , V_33 ,
V_34 , V_28 ) ;
V_37:
F_8 ( V_20 , V_33 ,
V_34 , V_27 ) ;
V_35:
F_8 ( V_20 , V_33 ,
V_22 , V_26 ) ;
return V_13 ;
}
static int F_10 ( struct V_9 * V_10 , int V_11 ,
unsigned long V_12 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
int V_13 ;
if ( V_12 > ( V_16 -> V_1 - V_18 ) )
return - V_8 ;
F_4 ( & V_19 ) ;
V_13 = F_7 ( V_10 -> V_17 , V_11 , V_12 ) ;
F_6 ( & V_19 ) ;
return V_13 ;
}
static int F_11 ( struct V_9 * V_43 ,
int V_11 , enum V_44 * type )
{
if ( V_11 )
* type = V_45 ;
else
* type = V_46 ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
unsigned long * V_12 )
{
int V_13 ;
T_1 V_14 ;
struct V_15 * V_16 ;
V_16 = V_10 -> V_17 ;
V_13 = F_5 ( V_20 , V_21 ,
V_47 , & V_14 ) ;
if ( V_13 )
return V_13 ;
V_14 = ( V_14 & V_16 -> V_48 ) >> V_16 -> V_49 ;
V_14 -= V_23 ;
* V_12 = V_16 -> V_1 - V_14 * 1000 ;
return 0 ;
}
static void F_13 ( struct V_15 * V_16 )
{
if ( V_16 ) {
F_8 ( V_20 , V_33 ,
V_50 , V_16 -> V_51 ) ;
F_14 ( V_16 -> V_52 ) ;
F_15 ( V_16 ) ;
}
}
static int F_16 ( int V_53 )
{
T_1 V_14 ;
int V_54 ;
V_54 = F_5 ( V_20 , V_21 ,
V_50 , & V_14 ) ;
if ( V_54 )
return V_54 ;
if ( ! ( V_14 & F_17 ( V_53 ) ) ) {
V_14 |= F_17 ( V_53 ) ;
V_54 = F_8 ( V_20 , V_33 ,
V_50 , V_14 ) ;
if ( V_54 )
return V_54 ;
}
return V_54 ;
}
static struct V_15 * F_18 ( int V_53 , T_1 V_1 )
{
struct V_15 * V_16 ;
char V_55 [ 10 ] ;
int V_5 ;
V_16 = F_19 ( sizeof( * V_16 ) , V_56 ) ;
if ( ! V_16 ) {
V_5 = - V_57 ;
return F_20 ( - V_57 ) ;
}
V_5 = F_5 ( V_20 , V_21 ,
V_50 ,
& V_16 -> V_51 ) ;
if ( V_5 )
goto V_7;
V_16 -> V_53 = V_53 ;
V_16 -> V_1 = V_1 ;
V_16 -> V_48 = 0x00FF << ( V_53 * 8 ) ;
V_16 -> V_49 = V_53 * 8 ;
snprintf ( V_55 , sizeof( V_55 ) , L_2 , V_53 ) ;
V_16 -> V_52 = F_21 ( V_55 ,
V_58 ,
0x02 ,
V_16 , & V_59 , NULL , 0 , 0 ) ;
if ( F_22 ( V_16 -> V_52 ) ) {
V_5 = F_23 ( V_16 -> V_52 ) ;
goto V_7;
}
V_5 = F_16 ( V_53 ) ;
if ( V_5 )
goto V_60;
return V_16 ;
V_60:
F_14 ( V_16 -> V_52 ) ;
V_7:
F_15 ( V_16 ) ;
return F_20 ( V_5 ) ;
}
static void F_24 ( void )
{
T_1 V_61 ;
int V_13 ;
T_1 V_62 ;
V_13 = F_5 ( V_20 , V_21 ,
V_34 , & V_62 ) ;
V_62 |= V_63 ;
V_13 = F_8 ( V_20 , V_33 ,
V_34 , V_62 ) ;
V_13 = F_5 ( V_20 , V_21 ,
V_64 , & V_61 ) ;
F_9 ( L_3 , V_13 , V_61 ) ;
if ( V_61 & V_65 ) {
int V_66 ;
V_13 = F_8 ( V_20 , V_33 ,
V_64 , V_61 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; ++ V_66 ) {
F_9 ( L_4 , V_66 ) ;
F_25 ( V_68 [ V_66 ] -> V_52 ) ;
}
}
}
static T_2 F_26 ( int V_69 , void * V_70 )
{
unsigned long V_71 ;
F_27 ( & V_72 , V_71 ) ;
F_24 () ;
F_28 ( & V_72 , V_71 ) ;
F_9 ( L_5 ) ;
return V_73 ;
}
static int T_3 F_29 ( void )
{
T_1 V_1 ;
int V_5 = 0 ;
int V_66 ;
const struct V_74 * V_75 ;
V_75 = F_30 ( V_76 ) ;
if ( ! V_75 )
return - V_77 ;
if ( F_1 ( & V_1 ) )
return - V_8 ;
for ( V_66 = 0 ; V_66 < V_67 ; ++ V_66 ) {
V_68 [ V_66 ] = F_18 ( V_66 , V_1 ) ;
if ( F_22 ( V_68 [ V_66 ] ) ) {
V_5 = F_23 ( V_68 [ V_66 ] ) ;
goto V_78;
}
}
F_31 ( & V_72 ) ;
V_79 = ( int ) V_75 -> V_80 ;
V_5 = F_32 ( V_79 , NULL ,
F_26 ,
V_81 | V_82 ,
L_6 , V_68 ) ;
if ( V_5 ) {
F_33 ( L_7 , V_5 ) ;
goto V_78;
}
for ( V_66 = 0 ; V_66 < V_67 ; ++ V_66 ) {
V_5 = F_7 ( V_68 [ V_66 ] , 0 , V_1 - V_18 ) ;
if ( V_5 )
goto V_83;
}
return 0 ;
V_83:
V_66 = V_67 ;
F_34 ( V_79 , V_68 ) ;
V_78:
while ( -- V_66 >= 0 )
F_13 ( V_68 [ V_66 ] ) ;
return V_5 ;
}
static void T_4 F_35 ( void )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; ++ V_66 )
F_7 ( V_68 [ V_66 ] , 0 , 0 ) ;
F_34 ( V_79 , V_68 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; ++ V_66 )
F_13 ( V_68 [ V_66 ] ) ;
}
