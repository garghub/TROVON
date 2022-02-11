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
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_21 * V_22 = & V_20 -> V_22 ;
struct V_23 * V_2 = V_20 -> V_2 ;
unsigned int V_24 ;
F_9 ( V_22 ) ;
if ( F_10 ( V_20 ) ) {
F_11 ( V_2 , L_2 ) ;
return 0 ;
}
for ( V_24 = 0 ; V_24 < 5 ; V_24 ++ ) {
F_12 ( V_18 ) ;
if ( ! F_13 ( V_20 ) )
return 0 ;
}
F_11 ( V_2 , L_3 ) ;
return - V_25 ;
}
static void F_14 ( struct V_26 * V_27 )
{
unsigned int V_28 = F_15 ( V_27 ) ;
struct V_17 * V_18 = F_16 ( V_27 ) ;
T_1 V_29 = V_28 - V_18 -> V_30 [ 0 ] ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_23 * V_2 = V_20 -> V_2 ;
struct V_31 * V_32 = F_17 ( V_27 ) ;
F_18 ( V_2 , L_4 , V_33 , V_28 ) ;
F_19 ( V_32 , V_27 ) ;
F_20 ( V_18 , V_29 ) ;
F_21 ( V_32 , V_27 ) ;
}
static void F_22 ( struct V_26 * V_27 )
{
unsigned int V_28 = F_15 ( V_27 ) ;
struct V_17 * V_18 = F_16 ( V_27 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_23 * V_2 = V_20 -> V_2 ;
T_1 V_34 = V_28 - V_18 -> V_35 [ 0 ] ;
struct V_31 * V_32 = F_17 ( V_27 ) ;
F_18 ( V_2 , L_5 , V_28 ) ;
F_19 ( V_32 , V_27 ) ;
F_23 ( V_18 , V_34 ) ;
F_21 ( V_32 , V_27 ) ;
}
static int F_24 ( struct V_17 * V_18 ,
char * V_36 , int * V_37 )
{
int V_38 , V_39 , V_40 = 1 , * V_41 ;
struct V_23 * V_2 = V_18 -> V_20 -> V_2 ;
struct V_42 * V_43 = V_2 -> V_44 , * * V_45 ;
if ( ! strcmp ( V_36 , L_6 ) )
V_40 = 0 ;
if ( V_40 ) {
V_45 = & V_18 -> V_46 ;
V_39 = V_47 ;
V_41 = & V_18 -> V_35 [ 0 ] ;
} else {
V_45 = & V_18 -> V_48 ;
V_39 = V_49 ;
V_41 = & V_18 -> V_30 [ 0 ] ;
}
* V_45 = F_25 ( V_43 , V_36 ) ;
if ( ! ( * V_45 ) ) {
F_11 ( V_2 , L_7 , V_36 ) ;
return - V_50 ;
}
V_38 = F_26 ( * V_45 ) ;
if ( ! V_38 ) {
F_11 ( V_2 , L_8 , V_36 ) ;
return - V_50 ;
}
if ( V_38 > V_39 )
F_27 ( V_2 , L_9 ,
( V_40 ? L_10 : L_11 ) , V_38 ) ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_41 [ V_38 ] = F_28 ( * V_45 , V_38 ) ;
if ( ! V_41 [ V_38 ] )
break;
}
if ( V_38 ) {
* V_37 = V_38 ;
return 0 ;
}
return - V_50 ;
}
static void F_29 ( struct V_17 * V_18 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_18 -> V_52 ; V_51 ++ ) {
F_30 ( V_18 -> V_35 [ V_51 ] ,
F_22 ,
V_18 ) ;
}
F_31 ( V_18 ) ;
if ( F_32 ( V_53 ) ) {
for ( V_51 = 0 ; V_51 < V_18 -> V_54 ; V_51 ++ ) {
F_30 ( V_18 -> V_30 [ V_51 ] ,
F_14 ,
V_18 ) ;
}
}
if ( V_18 -> V_55 > 0 )
F_33 ( V_18 ) ;
}
static int F_34 ( unsigned long V_56 , unsigned int V_57 ,
struct V_58 * V_59 )
{
unsigned long V_60 = * ( unsigned long * ) F_35 ( V_59 ) ;
if ( ( V_60 & 0x0e100090 ) == 0x00100090 ) {
int V_61 = ( V_60 >> 12 ) & 15 ;
V_59 -> V_62 [ V_61 ] = - 1 ;
V_59 -> V_63 += 4 ;
}
return 0 ;
}
static int T_2 F_36 ( struct V_21 * V_22 )
{
struct V_19 * V_20 = F_37 ( V_22 ) ;
struct V_17 * V_18 = F_38 ( V_20 ) ;
T_1 V_64 ;
F_8 ( V_18 ) ;
F_39 ( V_18 ) ;
F_29 ( V_18 ) ;
F_40 ( V_65 | ( V_65 << 8 ) ,
V_20 -> V_66 + V_67 ) ;
F_40 ( V_18 -> V_68 , V_20 -> V_66 + V_69 ) ;
V_64 = F_41 ( V_20 -> V_66 + V_70 + V_71 ) ;
V_64 &= ~ V_72 ;
V_64 |= F_42 ( 12 ) ;
F_43 ( V_64 , V_20 -> V_66 + V_70 + V_71 ) ;
F_44 ( 17 , F_34 , V_73 , 0 ,
L_12 ) ;
return 0 ;
}
static T_3 F_45 ( int V_28 , void * V_74 )
{
struct V_17 * V_18 = V_74 ;
return F_46 ( V_18 ) ;
}
static int T_2 F_47 ( struct V_17 * V_18 ,
struct V_75 * V_76 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_21 * V_22 = & V_20 -> V_22 ;
struct V_23 * V_2 = & V_76 -> V_2 ;
int V_77 ;
V_77 = F_24 ( V_18 ,
L_13 ,
& V_18 -> V_52 ) ;
if ( V_77 )
return V_77 ;
if ( F_32 ( V_53 ) ) {
V_77 = F_24 ( V_18 ,
L_6 ,
& V_18 -> V_54 ) ;
if ( V_77 )
return V_77 ;
}
V_18 -> V_55 = F_28 ( V_18 -> V_78 , 0 ) ;
if ( V_18 -> V_55 <= 0 )
F_6 ( V_2 , L_14 ) ;
else {
V_77 = F_48 ( V_18 -> V_55 , F_45 ,
V_79 , L_15 , V_18 ) ;
if ( V_77 < 0 ) {
F_11 ( V_2 , L_16 ,
V_18 -> V_55 ) ;
return V_77 ;
}
}
V_22 -> V_80 = - 1 ;
V_22 -> V_81 = & V_82 ;
V_77 = F_49 ( V_18 , V_18 -> V_48 ) ;
if ( V_77 ) {
F_11 ( V_2 , L_17 ) ;
return V_77 ;
}
return 0 ;
}
static int T_4 F_50 ( struct V_75 * V_76 )
{
struct V_17 * V_18 = F_51 ( V_76 ) ;
F_52 ( V_18 -> V_83 ) ;
return 0 ;
}
static int T_2 F_53 ( struct V_75 * V_76 )
{
struct V_23 * V_2 = & V_76 -> V_2 ;
struct V_19 * V_20 ;
struct V_17 * V_18 ;
struct V_84 * V_85 ;
void T_5 * V_86 ;
struct V_87 * V_87 ;
int V_77 ;
V_18 = F_54 ( V_2 , sizeof( * V_18 ) , V_88 ) ;
if ( ! V_18 )
return - V_89 ;
V_20 = F_54 ( V_2 , sizeof( * V_20 ) , V_88 ) ;
if ( ! V_20 )
return - V_89 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_81 = & V_90 ;
V_18 -> V_20 = V_20 ;
V_87 = F_55 ( V_2 , L_18 ) ;
if ( F_56 ( V_87 ) == - V_91 )
return F_57 ( V_87 ) ;
if ( ! F_58 ( V_87 ) ) {
V_77 = F_59 ( V_87 ) ;
if ( V_77 < 0 )
return V_77 ;
}
V_85 = F_60 ( V_76 , V_92 , 2 ) ;
V_86 = F_61 ( V_2 , V_85 ) ;
if ( F_62 ( V_86 ) )
return F_57 ( V_86 ) ;
V_18 -> V_68 = F_41 ( V_86 ) >> 16 ;
F_63 ( V_2 , V_86 ) ;
F_64 ( V_2 , V_85 -> V_93 , F_65 ( V_85 ) ) ;
V_18 -> V_78 = V_2 -> V_44 ;
F_66 ( V_76 , V_18 ) ;
V_18 -> V_83 = F_67 ( V_2 , L_19 ) ;
if ( F_62 ( V_18 -> V_83 ) ) {
F_11 ( V_2 , L_20 ) ;
return F_57 ( V_18 -> V_83 ) ;
}
V_77 = F_68 ( V_18 -> V_83 ) ;
if ( V_77 )
return V_77 ;
F_66 ( V_76 , V_18 ) ;
V_77 = F_47 ( V_18 , V_76 ) ;
if ( V_77 < 0 )
goto V_94;
return 0 ;
V_94:
F_52 ( V_18 -> V_83 ) ;
return V_77 ;
}
