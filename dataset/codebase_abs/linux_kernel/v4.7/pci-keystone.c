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
unsigned int V_21 ;
F_9 ( V_20 ) ;
if ( F_10 ( V_20 ) ) {
F_11 ( V_20 -> V_2 , L_2 ) ;
return 0 ;
}
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ ) {
F_12 ( V_18 ) ;
if ( ! F_13 ( V_20 ) )
return 0 ;
}
F_11 ( V_20 -> V_2 , L_3 ) ;
return - V_22 ;
}
static void F_14 ( struct V_23 * V_24 )
{
unsigned int V_25 = F_15 ( V_24 ) ;
struct V_17 * V_18 = F_16 ( V_24 ) ;
T_1 V_26 = V_25 - V_18 -> V_27 [ 0 ] ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_28 * V_29 = F_17 ( V_24 ) ;
F_18 ( V_20 -> V_2 , L_4 , V_30 , V_25 ) ;
F_19 ( V_29 , V_24 ) ;
F_20 ( V_18 , V_26 ) ;
F_21 ( V_29 , V_24 ) ;
}
static void F_22 ( struct V_23 * V_24 )
{
unsigned int V_25 = F_15 ( V_24 ) ;
struct V_17 * V_18 = F_16 ( V_24 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
T_1 V_31 = V_25 - V_18 -> V_32 [ 0 ] ;
struct V_28 * V_29 = F_17 ( V_24 ) ;
F_18 ( V_20 -> V_2 , L_5 , V_25 ) ;
F_19 ( V_29 , V_24 ) ;
F_23 ( V_18 , V_31 ) ;
F_21 ( V_29 , V_24 ) ;
}
static int F_24 ( struct V_17 * V_18 ,
char * V_33 , int * V_34 )
{
int V_35 , V_36 , V_37 = 1 , * V_38 ;
struct V_39 * V_2 = V_18 -> V_20 . V_2 ;
struct V_40 * V_41 = V_2 -> V_42 , * * V_43 ;
if ( ! strcmp ( V_33 , L_6 ) )
V_37 = 0 ;
if ( V_37 ) {
V_43 = & V_18 -> V_44 ;
V_36 = V_45 ;
V_38 = & V_18 -> V_32 [ 0 ] ;
} else {
V_43 = & V_18 -> V_46 ;
V_36 = V_47 ;
V_38 = & V_18 -> V_27 [ 0 ] ;
}
* V_43 = F_25 ( V_41 , V_33 ) ;
if ( ! ( * V_43 ) ) {
F_11 ( V_2 , L_7 , V_33 ) ;
return - V_48 ;
}
V_35 = F_26 ( * V_43 ) ;
if ( ! V_35 ) {
F_11 ( V_2 , L_8 , V_33 ) ;
return - V_48 ;
}
if ( V_35 > V_36 )
F_27 ( V_2 , L_9 ,
( V_37 ? L_10 : L_11 ) , V_35 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_38 [ V_35 ] = F_28 ( * V_43 , V_35 ) ;
if ( ! V_38 [ V_35 ] )
break;
}
if ( V_35 ) {
* V_34 = V_35 ;
return 0 ;
}
return - V_48 ;
}
static void F_29 ( struct V_17 * V_18 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_18 -> V_50 ; V_49 ++ ) {
F_30 ( V_18 -> V_32 [ V_49 ] ,
F_22 ,
V_18 ) ;
}
F_31 ( V_18 ) ;
if ( F_32 ( V_51 ) ) {
for ( V_49 = 0 ; V_49 < V_18 -> V_52 ; V_49 ++ ) {
F_30 ( V_18 -> V_27 [ V_49 ] ,
F_14 ,
V_18 ) ;
}
}
if ( V_18 -> V_53 > 0 )
F_33 ( V_18 -> V_54 ) ;
}
static int F_34 ( unsigned long V_55 , unsigned int V_56 ,
struct V_57 * V_58 )
{
unsigned long V_59 = * ( unsigned long * ) F_35 ( V_58 ) ;
if ( ( V_59 & 0x0e100090 ) == 0x00100090 ) {
int V_60 = ( V_59 >> 12 ) & 15 ;
V_58 -> V_61 [ V_60 ] = - 1 ;
V_58 -> V_62 += 4 ;
}
return 0 ;
}
static void T_2 F_36 ( struct V_19 * V_20 )
{
struct V_17 * V_18 = F_37 ( V_20 ) ;
T_1 V_63 ;
F_8 ( V_18 ) ;
F_38 ( V_18 ) ;
F_29 ( V_18 ) ;
F_39 ( V_64 | ( V_64 << 8 ) ,
V_20 -> V_65 + V_66 ) ;
F_39 ( V_18 -> V_67 , V_20 -> V_65 + V_68 ) ;
V_63 = F_40 ( V_20 -> V_65 + V_69 + V_70 ) ;
V_63 &= ~ V_71 ;
V_63 |= F_41 ( 12 ) ;
F_42 ( V_63 , V_20 -> V_65 + V_69 + V_70 ) ;
F_43 ( 17 , F_34 , V_72 , 0 ,
L_12 ) ;
}
static T_3 F_44 ( int V_25 , void * V_73 )
{
struct V_17 * V_18 = V_73 ;
return F_45 ( V_18 -> V_20 . V_2 ,
V_18 -> V_54 ) ;
}
static int T_2 F_46 ( struct V_17 * V_18 ,
struct V_74 * V_75 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
int V_76 ;
V_76 = F_24 ( V_18 ,
L_13 ,
& V_18 -> V_50 ) ;
if ( V_76 )
return V_76 ;
if ( F_32 ( V_51 ) ) {
V_76 = F_24 ( V_18 ,
L_6 ,
& V_18 -> V_52 ) ;
if ( V_76 )
return V_76 ;
}
V_18 -> V_53 = F_28 ( V_18 -> V_77 , 0 ) ;
if ( V_18 -> V_53 <= 0 )
F_6 ( & V_75 -> V_2 , L_14 ) ;
else {
if ( F_47 ( V_18 -> V_53 , F_44 ,
V_78 , L_15 , V_18 ) < 0 ) {
F_11 ( & V_75 -> V_2 , L_16 ,
V_18 -> V_53 ) ;
return V_76 ;
}
}
V_20 -> V_79 = - 1 ;
V_20 -> V_80 = & V_81 ;
V_76 = F_48 ( V_18 , V_18 -> V_46 ) ;
if ( V_76 ) {
F_11 ( & V_75 -> V_2 , L_17 ) ;
return V_76 ;
}
return 0 ;
}
static int T_4 F_49 ( struct V_74 * V_75 )
{
struct V_17 * V_18 = F_50 ( V_75 ) ;
F_51 ( V_18 -> V_82 ) ;
return 0 ;
}
static int T_2 F_52 ( struct V_74 * V_75 )
{
struct V_39 * V_2 = & V_75 -> V_2 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_83 * V_84 ;
void T_5 * V_85 ;
struct V_86 * V_86 ;
int V_76 ;
V_18 = F_53 ( & V_75 -> V_2 , sizeof( * V_18 ) ,
V_87 ) ;
if ( ! V_18 )
return - V_88 ;
V_20 = & V_18 -> V_20 ;
V_86 = F_54 ( V_2 , L_18 ) ;
if ( F_55 ( V_86 ) == - V_89 )
return F_56 ( V_86 ) ;
if ( ! F_57 ( V_86 ) ) {
V_76 = F_58 ( V_86 ) ;
if ( V_76 < 0 )
return V_76 ;
}
V_84 = F_59 ( V_75 , V_90 , 2 ) ;
V_85 = F_60 ( V_2 , V_84 ) ;
if ( F_61 ( V_85 ) )
return F_56 ( V_85 ) ;
V_18 -> V_67 = F_40 ( V_85 ) >> 16 ;
F_62 ( V_2 , V_85 ) ;
F_63 ( V_2 , V_84 -> V_91 , F_64 ( V_84 ) ) ;
V_20 -> V_2 = V_2 ;
V_18 -> V_77 = V_2 -> V_42 ;
F_65 ( V_75 , V_18 ) ;
V_18 -> V_82 = F_66 ( V_2 , L_19 ) ;
if ( F_61 ( V_18 -> V_82 ) ) {
F_11 ( V_2 , L_20 ) ;
return F_56 ( V_18 -> V_82 ) ;
}
V_76 = F_67 ( V_18 -> V_82 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_46 ( V_18 , V_75 ) ;
if ( V_76 < 0 )
goto V_92;
return 0 ;
V_92:
F_51 ( V_18 -> V_82 ) ;
return V_76 ;
}
