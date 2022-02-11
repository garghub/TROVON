static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_5 = V_4 -> V_6 ;
static const struct V_7 V_8 [] = {
{ F_2 ( V_9 , V_10 ) ,
. V_11 = V_12 << 8 , . V_13 = ~ 0 , } ,
{ F_2 ( V_9 , V_14 ) ,
. V_11 = V_12 << 8 , . V_13 = ~ 0 , } ,
{ F_2 ( V_9 , V_15 ) ,
. V_11 = V_12 << 8 , . V_13 = ~ 0 , } ,
{ 0 , } ,
} ;
if ( F_3 ( V_4 ) )
return;
while ( ! F_3 ( V_4 ) ) {
V_5 = V_4 -> V_6 ;
V_4 = V_4 -> V_16 ;
}
if ( V_5 ) {
if ( F_4 ( V_8 , V_5 ) ) {
if ( F_5 ( V_2 ) > 256 ) {
F_6 ( & V_2 -> V_2 , L_1 ) ;
F_7 ( V_2 , 256 ) ;
}
}
}
}
static int F_8 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_2 = V_20 -> V_2 ;
unsigned int V_22 ;
F_9 ( V_20 ) ;
if ( F_10 ( V_20 ) ) {
F_11 ( V_2 , L_2 ) ;
return 0 ;
}
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
F_12 ( V_18 ) ;
if ( ! F_13 ( V_20 ) )
return 0 ;
}
F_11 ( V_2 , L_3 ) ;
return - V_23 ;
}
static void F_14 ( struct V_24 * V_25 )
{
unsigned int V_26 = F_15 ( V_25 ) ;
struct V_17 * V_18 = F_16 ( V_25 ) ;
T_1 V_27 = V_26 - V_18 -> V_28 [ 0 ] ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_2 = V_20 -> V_2 ;
struct V_29 * V_30 = F_17 ( V_25 ) ;
F_18 ( V_2 , L_4 , V_31 , V_26 ) ;
F_19 ( V_30 , V_25 ) ;
F_20 ( V_18 , V_27 ) ;
F_21 ( V_30 , V_25 ) ;
}
static void F_22 ( struct V_24 * V_25 )
{
unsigned int V_26 = F_15 ( V_25 ) ;
struct V_17 * V_18 = F_16 ( V_25 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_2 = V_20 -> V_2 ;
T_1 V_32 = V_26 - V_18 -> V_33 [ 0 ] ;
struct V_29 * V_30 = F_17 ( V_25 ) ;
F_18 ( V_2 , L_5 , V_26 ) ;
F_19 ( V_30 , V_25 ) ;
F_23 ( V_18 , V_32 ) ;
F_21 ( V_30 , V_25 ) ;
}
static int F_24 ( struct V_17 * V_18 ,
char * V_34 , int * V_35 )
{
int V_36 , V_37 , V_38 = 1 , * V_39 ;
struct V_21 * V_2 = V_18 -> V_20 . V_2 ;
struct V_40 * V_41 = V_2 -> V_42 , * * V_43 ;
if ( ! strcmp ( V_34 , L_6 ) )
V_38 = 0 ;
if ( V_38 ) {
V_43 = & V_18 -> V_44 ;
V_37 = V_45 ;
V_39 = & V_18 -> V_33 [ 0 ] ;
} else {
V_43 = & V_18 -> V_46 ;
V_37 = V_47 ;
V_39 = & V_18 -> V_28 [ 0 ] ;
}
* V_43 = F_25 ( V_41 , V_34 ) ;
if ( ! ( * V_43 ) ) {
F_11 ( V_2 , L_7 , V_34 ) ;
return - V_48 ;
}
V_36 = F_26 ( * V_43 ) ;
if ( ! V_36 ) {
F_11 ( V_2 , L_8 , V_34 ) ;
return - V_48 ;
}
if ( V_36 > V_37 )
F_27 ( V_2 , L_9 ,
( V_38 ? L_10 : L_11 ) , V_36 ) ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_39 [ V_36 ] = F_28 ( * V_43 , V_36 ) ;
if ( ! V_39 [ V_36 ] )
break;
}
if ( V_36 ) {
* V_35 = V_36 ;
return 0 ;
}
return - V_48 ;
}
static void F_29 ( struct V_17 * V_18 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_18 -> V_50 ; V_49 ++ ) {
F_30 ( V_18 -> V_33 [ V_49 ] ,
F_22 ,
V_18 ) ;
}
F_31 ( V_18 ) ;
if ( F_32 ( V_51 ) ) {
for ( V_49 = 0 ; V_49 < V_18 -> V_52 ; V_49 ++ ) {
F_30 ( V_18 -> V_28 [ V_49 ] ,
F_14 ,
V_18 ) ;
}
}
if ( V_18 -> V_53 > 0 )
F_33 ( V_18 ) ;
}
static int F_34 ( unsigned long V_54 , unsigned int V_55 ,
struct V_56 * V_57 )
{
unsigned long V_58 = * ( unsigned long * ) F_35 ( V_57 ) ;
if ( ( V_58 & 0x0e100090 ) == 0x00100090 ) {
int V_59 = ( V_58 >> 12 ) & 15 ;
V_57 -> V_60 [ V_59 ] = - 1 ;
V_57 -> V_61 += 4 ;
}
return 0 ;
}
static void T_2 F_36 ( struct V_19 * V_20 )
{
struct V_17 * V_18 = F_37 ( V_20 ) ;
T_1 V_62 ;
F_8 ( V_18 ) ;
F_38 ( V_18 ) ;
F_29 ( V_18 ) ;
F_39 ( V_63 | ( V_63 << 8 ) ,
V_20 -> V_64 + V_65 ) ;
F_39 ( V_18 -> V_66 , V_20 -> V_64 + V_67 ) ;
V_62 = F_40 ( V_20 -> V_64 + V_68 + V_69 ) ;
V_62 &= ~ V_70 ;
V_62 |= F_41 ( 12 ) ;
F_42 ( V_62 , V_20 -> V_64 + V_68 + V_69 ) ;
F_43 ( 17 , F_34 , V_71 , 0 ,
L_12 ) ;
}
static T_3 F_44 ( int V_26 , void * V_72 )
{
struct V_17 * V_18 = V_72 ;
return F_45 ( V_18 ) ;
}
static int T_2 F_46 ( struct V_17 * V_18 ,
struct V_73 * V_74 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_2 = V_20 -> V_2 ;
int V_75 ;
V_75 = F_24 ( V_18 ,
L_13 ,
& V_18 -> V_50 ) ;
if ( V_75 )
return V_75 ;
if ( F_32 ( V_51 ) ) {
V_75 = F_24 ( V_18 ,
L_6 ,
& V_18 -> V_52 ) ;
if ( V_75 )
return V_75 ;
}
V_18 -> V_53 = F_28 ( V_18 -> V_76 , 0 ) ;
if ( V_18 -> V_53 <= 0 )
F_6 ( V_2 , L_14 ) ;
else {
V_75 = F_47 ( V_18 -> V_53 , F_44 ,
V_77 , L_15 , V_18 ) ;
if ( V_75 < 0 ) {
F_11 ( V_2 , L_16 ,
V_18 -> V_53 ) ;
return V_75 ;
}
}
V_20 -> V_78 = - 1 ;
V_20 -> V_79 = & V_80 ;
V_75 = F_48 ( V_18 , V_18 -> V_46 ) ;
if ( V_75 ) {
F_11 ( V_2 , L_17 ) ;
return V_75 ;
}
return 0 ;
}
static int T_4 F_49 ( struct V_73 * V_74 )
{
struct V_17 * V_18 = F_50 ( V_74 ) ;
F_51 ( V_18 -> V_81 ) ;
return 0 ;
}
static int T_2 F_52 ( struct V_73 * V_74 )
{
struct V_21 * V_2 = & V_74 -> V_2 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_82 * V_83 ;
void T_5 * V_84 ;
struct V_85 * V_85 ;
int V_75 ;
V_18 = F_53 ( V_2 , sizeof( * V_18 ) , V_86 ) ;
if ( ! V_18 )
return - V_87 ;
V_20 = & V_18 -> V_20 ;
V_20 -> V_2 = V_2 ;
V_85 = F_54 ( V_2 , L_18 ) ;
if ( F_55 ( V_85 ) == - V_88 )
return F_56 ( V_85 ) ;
if ( ! F_57 ( V_85 ) ) {
V_75 = F_58 ( V_85 ) ;
if ( V_75 < 0 )
return V_75 ;
}
V_83 = F_59 ( V_74 , V_89 , 2 ) ;
V_84 = F_60 ( V_2 , V_83 ) ;
if ( F_61 ( V_84 ) )
return F_56 ( V_84 ) ;
V_18 -> V_66 = F_40 ( V_84 ) >> 16 ;
F_62 ( V_2 , V_84 ) ;
F_63 ( V_2 , V_83 -> V_90 , F_64 ( V_83 ) ) ;
V_18 -> V_76 = V_2 -> V_42 ;
F_65 ( V_74 , V_18 ) ;
V_18 -> V_81 = F_66 ( V_2 , L_19 ) ;
if ( F_61 ( V_18 -> V_81 ) ) {
F_11 ( V_2 , L_20 ) ;
return F_56 ( V_18 -> V_81 ) ;
}
V_75 = F_67 ( V_18 -> V_81 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_46 ( V_18 , V_74 ) ;
if ( V_75 < 0 )
goto V_91;
return 0 ;
V_91:
F_51 ( V_18 -> V_81 ) ;
return V_75 ;
}
