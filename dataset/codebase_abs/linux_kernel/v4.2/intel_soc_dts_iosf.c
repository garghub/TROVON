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
static int F_3 ( struct V_9 * V_10 , int V_11 ,
unsigned long * V_12 )
{
int V_13 ;
T_1 V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_16 = V_10 -> V_19 ;
V_18 = V_16 -> V_18 ;
F_4 ( & V_18 -> V_20 ) ;
V_13 = F_5 ( V_21 , V_22 ,
V_23 , & V_14 ) ;
F_6 ( & V_18 -> V_20 ) ;
if ( V_13 )
return V_13 ;
V_14 = ( V_14 >> ( V_11 * 8 ) ) & V_24 ;
if ( ! V_14 )
* V_12 = 0 ;
else
* V_12 = V_18 -> V_1 - V_14 * 1000 ;
return 0 ;
}
static int F_7 ( struct V_15 * V_16 ,
int V_25 , unsigned long V_12 ,
enum V_26 V_27 )
{
int V_13 ;
T_1 V_28 ;
T_1 V_14 ;
T_1 V_29 ;
T_1 V_30 ;
T_1 V_31 ;
T_1 V_32 ;
T_1 V_33 = V_34 ;
struct V_17 * V_18 = V_16 -> V_18 ;
if ( V_18 -> V_35 == V_36 )
V_33 |= V_37 ;
V_28 = ( V_18 -> V_1 - V_12 ) / 1000 ;
V_13 = F_5 ( V_21 , V_22 ,
V_23 , & V_29 ) ;
if ( V_13 )
return V_13 ;
V_14 = ( V_29 & ~ ( 0xFF << ( V_25 * 8 ) ) ) ;
V_14 |= ( V_28 & 0xFF ) << ( V_25 * 8 ) ;
V_13 = F_8 ( V_21 , V_38 ,
V_23 , V_14 ) ;
if ( V_13 )
return V_13 ;
F_9 ( L_1 , V_14 ) ;
V_13 = F_5 ( V_21 , V_22 ,
V_39 , & V_14 ) ;
if ( V_13 )
goto V_40;
V_30 = V_14 ;
V_13 = F_5 ( V_21 , V_22 ,
V_41 + V_25 ,
& V_32 ) ;
if ( V_13 )
goto V_42;
V_31 = V_32 ;
V_14 |= ( V_43 |
V_44 ) ;
if ( V_12 ) {
if ( V_25 )
V_14 |= V_45 ;
else
V_14 |= V_46 ;
V_32 |= V_33 ;
} else {
if ( V_25 )
V_14 &= ~ V_45 ;
else
V_14 &= ~ V_46 ;
V_32 &= ~ V_33 ;
}
V_13 = F_8 ( V_21 , V_38 ,
V_39 , V_14 ) ;
if ( V_13 )
goto V_47;
V_13 = F_8 ( V_21 , V_38 ,
V_41 + V_25 ,
V_32 ) ;
if ( V_13 )
goto V_47;
V_16 -> V_48 [ V_25 ] = V_27 ;
return 0 ;
V_47:
F_8 ( V_21 , V_38 ,
V_39 , V_31 ) ;
V_42:
F_8 ( V_21 , V_38 ,
V_39 , V_30 ) ;
V_40:
F_8 ( V_21 , V_38 ,
V_23 , V_29 ) ;
return V_13 ;
}
static int F_10 ( struct V_9 * V_10 , int V_11 ,
unsigned long V_12 )
{
struct V_15 * V_16 = V_10 -> V_19 ;
struct V_17 * V_18 = V_16 -> V_18 ;
int V_13 ;
if ( V_12 > V_18 -> V_1 )
return - V_8 ;
F_4 ( & V_18 -> V_20 ) ;
V_13 = F_7 ( V_10 -> V_19 , V_11 , V_12 ,
V_16 -> V_48 [ V_11 ] ) ;
F_6 ( & V_18 -> V_20 ) ;
return V_13 ;
}
static int F_11 ( struct V_9 * V_10 ,
int V_11 , enum V_26 * type )
{
struct V_15 * V_16 ;
V_16 = V_10 -> V_19 ;
* type = V_16 -> V_48 [ V_11 ] ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
unsigned long * V_12 )
{
int V_13 ;
T_1 V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_16 = V_10 -> V_19 ;
V_18 = V_16 -> V_18 ;
V_13 = F_5 ( V_21 , V_22 ,
V_49 , & V_14 ) ;
if ( V_13 )
return V_13 ;
V_14 = ( V_14 & V_16 -> V_50 ) >> V_16 -> V_51 ;
V_14 -= V_24 ;
* V_12 = V_18 -> V_1 - V_14 * 1000 ;
return 0 ;
}
static int F_13 ( int V_52 )
{
T_1 V_14 ;
int V_53 ;
V_53 = F_5 ( V_21 , V_22 ,
V_54 , & V_14 ) ;
if ( V_53 )
return V_53 ;
if ( ! ( V_14 & F_14 ( V_52 ) ) ) {
V_14 |= F_14 ( V_52 ) ;
V_53 = F_8 ( V_21 , V_38 ,
V_54 , V_14 ) ;
if ( V_53 )
return V_53 ;
}
return V_53 ;
}
static void F_15 ( struct V_15 * V_16 )
{
if ( V_16 ) {
F_8 ( V_21 , V_38 ,
V_54 , V_16 -> V_55 ) ;
F_16 ( V_16 -> V_56 ) ;
}
}
static int F_17 ( int V_52 , struct V_15 * V_16 ,
bool V_57 , int V_58 ,
int V_59 )
{
char V_60 [ 10 ] ;
int V_61 = 0 ;
int V_62 = 0 ;
T_1 V_29 ;
int V_53 ;
int V_63 ;
V_53 = F_5 ( V_21 , V_22 ,
V_54 ,
& V_16 -> V_55 ) ;
if ( V_53 )
goto V_7;
V_16 -> V_52 = V_52 ;
V_16 -> V_50 = 0x00FF << ( V_52 * 8 ) ;
V_16 -> V_51 = V_52 * 8 ;
if ( V_57 ) {
V_61 = F_18 ( V_64 , V_58 ) ;
V_62 = F_14 ( V_61 - V_59 ) - 1 ;
}
V_53 = F_5 ( V_21 , V_22 ,
V_23 , & V_29 ) ;
if ( V_53 )
V_62 = 0 ;
else {
for ( V_63 = 0 ; V_63 < V_61 ; ++ V_63 ) {
if ( V_62 & F_14 ( V_63 ) )
if ( V_29 & ( 0xff << ( V_63 * 8 ) ) )
V_62 &= ~ F_14 ( V_63 ) ;
}
}
V_16 -> V_62 = V_62 ;
V_16 -> V_61 = V_61 ;
snprintf ( V_60 , sizeof( V_60 ) , L_2 , V_52 ) ;
V_16 -> V_56 = F_19 ( V_60 ,
V_61 ,
V_62 ,
V_16 , & V_65 ,
NULL , 0 , 0 ) ;
if ( F_20 ( V_16 -> V_56 ) ) {
V_53 = F_21 ( V_16 -> V_56 ) ;
goto V_7;
}
V_53 = F_13 ( V_52 ) ;
if ( V_53 )
goto V_66;
return 0 ;
V_66:
F_16 ( V_16 -> V_56 ) ;
V_7:
return V_53 ;
}
int F_22 (
struct V_17 * V_18 , int V_67 )
{
int V_63 , V_68 ;
for ( V_63 = 0 ; V_63 < V_69 ; ++ V_63 ) {
for ( V_68 = 0 ; V_68 < V_18 -> V_70 [ V_63 ] . V_61 ; ++ V_68 ) {
if ( ! ( V_18 -> V_70 [ V_63 ] . V_62 & F_14 ( V_68 ) ) ) {
return F_7 ( & V_18 -> V_70 [ V_63 ] , V_68 ,
V_18 -> V_1 - V_67 ,
V_71 ) ;
}
}
}
return - V_8 ;
}
void F_23 ( struct V_17 * V_18 )
{
T_1 V_72 ;
int V_13 ;
T_1 V_73 ;
unsigned long V_74 ;
F_24 ( & V_18 -> V_75 , V_74 ) ;
V_13 = F_5 ( V_21 , V_22 ,
V_39 , & V_73 ) ;
V_73 |= V_76 ;
V_13 = F_8 ( V_21 , V_38 ,
V_39 , V_73 ) ;
V_13 = F_5 ( V_21 , V_22 ,
V_77 , & V_72 ) ;
F_9 ( L_3 , V_13 , V_72 ) ;
if ( V_72 & V_78 ) {
int V_63 ;
V_13 = F_8 ( V_21 , V_38 ,
V_77 , V_72 ) ;
F_25 ( & V_18 -> V_75 , V_74 ) ;
for ( V_63 = 0 ; V_63 < V_69 ; ++ V_63 ) {
F_9 ( L_4 , V_63 ) ;
F_26 ( V_18 -> V_70 [ V_63 ] . V_56 ) ;
}
} else
F_25 ( & V_18 -> V_75 , V_74 ) ;
}
struct V_17 * F_27 (
enum V_79 V_35 , int V_61 ,
int V_80 )
{
struct V_17 * V_18 ;
bool V_81 ;
T_1 V_1 ;
int V_53 ;
int V_63 ;
if ( ! F_28 () )
return F_29 ( - V_82 ) ;
if ( ! V_61 || V_80 > V_61 )
return F_29 ( - V_8 ) ;
if ( F_1 ( & V_1 ) )
return F_29 ( - V_8 ) ;
V_18 = F_30 ( sizeof( * V_18 ) , V_83 ) ;
if ( ! V_18 )
return F_29 ( - V_84 ) ;
F_31 ( & V_18 -> V_75 ) ;
F_32 ( & V_18 -> V_20 ) ;
V_18 -> V_35 = V_35 ;
V_18 -> V_1 = V_1 ;
if ( V_35 == V_85 )
V_81 = false ;
else
V_81 = true ;
for ( V_63 = 0 ; V_63 < V_69 ; ++ V_63 ) {
V_18 -> V_70 [ V_63 ] . V_18 = V_18 ;
V_53 = F_17 ( V_63 , & V_18 -> V_70 [ V_63 ] ,
V_81 , V_61 ,
V_80 ) ;
if ( V_53 )
goto V_86;
}
for ( V_63 = 0 ; V_63 < V_69 ; ++ V_63 ) {
V_53 = F_7 ( & V_18 -> V_70 [ V_63 ] , 0 , 0 ,
V_87 ) ;
if ( V_53 )
goto V_88;
V_53 = F_7 ( & V_18 -> V_70 [ V_63 ] , 1 , 0 ,
V_87 ) ;
if ( V_53 )
goto V_88;
}
return V_18 ;
V_88:
for ( V_63 = 0 ; V_63 < V_69 ; ++ V_63 )
F_15 ( & V_18 -> V_70 [ V_63 ] ) ;
V_86:
F_33 ( V_18 ) ;
return F_29 ( V_53 ) ;
}
void F_34 ( struct V_17 * V_18 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_69 ; ++ V_63 ) {
F_7 ( & V_18 -> V_70 [ V_63 ] , 0 , 0 , 0 ) ;
F_7 ( & V_18 -> V_70 [ V_63 ] , 1 , 0 , 0 ) ;
F_15 ( & V_18 -> V_70 [ V_63 ] ) ;
}
F_33 ( V_18 ) ;
}
