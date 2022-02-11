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
F_12 ( V_18 ) ;
for ( V_21 = 0 ; V_21 < 200 ; V_21 ++ ) {
if ( F_10 ( V_20 ) )
return 0 ;
F_13 ( 100 , 1000 ) ;
F_12 ( V_18 ) ;
}
F_11 ( V_20 -> V_2 , L_3 ) ;
return - V_22 ;
}
static void F_14 ( unsigned int V_23 , struct V_24 * V_25 )
{
struct V_17 * V_18 = F_15 ( V_25 ) ;
T_1 V_26 = V_23 - V_18 -> V_27 [ 0 ] ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_28 * V_29 = F_16 ( V_25 ) ;
F_17 ( V_20 -> V_2 , L_4 , V_30 , V_23 ) ;
F_18 ( V_29 , V_25 ) ;
F_19 ( V_18 , V_26 ) ;
F_20 ( V_29 , V_25 ) ;
}
static void F_21 ( unsigned int V_23 , struct V_24 * V_25 )
{
struct V_17 * V_18 = F_15 ( V_25 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
T_1 V_31 = V_23 - V_18 -> V_32 [ 0 ] ;
struct V_28 * V_29 = F_16 ( V_25 ) ;
F_17 ( V_20 -> V_2 , L_5 , V_23 ) ;
F_18 ( V_29 , V_25 ) ;
F_22 ( V_18 , V_31 ) ;
F_20 ( V_29 , V_25 ) ;
}
static int F_23 ( struct V_17 * V_18 ,
char * V_33 , int * V_34 )
{
int V_35 , V_36 , V_37 = 1 , * V_38 , V_39 = - V_22 ;
struct V_40 * V_2 = V_18 -> V_20 . V_2 ;
struct V_41 * V_42 = V_2 -> V_43 , * * V_44 ;
if ( ! strcmp ( V_33 , L_6 ) )
V_37 = 0 ;
if ( V_37 ) {
V_44 = & V_18 -> V_45 ;
V_36 = V_46 ;
V_38 = & V_18 -> V_32 [ 0 ] ;
} else {
V_44 = & V_18 -> V_47 ;
V_36 = V_48 ;
V_38 = & V_18 -> V_27 [ 0 ] ;
}
* V_44 = F_24 ( V_42 , V_33 ) ;
if ( ! ( * V_44 ) ) {
F_11 ( V_2 , L_7 , V_33 ) ;
goto V_49;
}
V_35 = F_25 ( * V_44 ) ;
if ( ! V_35 )
goto V_49;
if ( V_35 > V_36 )
F_26 ( V_2 , L_8 ,
( V_37 ? L_9 : L_10 ) , V_35 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_38 [ V_35 ] = F_27 ( * V_44 , V_35 ) ;
if ( ! V_38 [ V_35 ] )
break;
}
if ( V_35 ) {
* V_34 = V_35 ;
V_39 = 0 ;
}
V_49:
return V_39 ;
}
static void F_28 ( struct V_17 * V_18 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_18 -> V_51 ; V_50 ++ ) {
F_29 ( V_18 -> V_32 [ V_50 ] , V_18 ) ;
F_30 ( V_18 -> V_32 [ V_50 ] ,
F_21 ) ;
}
F_31 ( V_18 ) ;
if ( F_32 ( V_52 ) ) {
for ( V_50 = 0 ; V_50 < V_18 -> V_53 ; V_50 ++ ) {
F_33 ( V_18 -> V_27 [ V_50 ] ,
F_14 ,
V_18 ) ;
}
}
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
F_28 ( V_18 ) ;
F_39 ( V_63 | ( V_63 << 8 ) ,
V_20 -> V_64 + V_65 ) ;
F_39 ( V_18 -> V_66 , V_20 -> V_64 + V_67 ) ;
V_62 = F_40 ( V_20 -> V_64 + V_68 + V_69 ) ;
V_62 &= ~ V_70 ;
V_62 |= F_41 ( 12 ) ;
F_42 ( V_62 , V_20 -> V_64 + V_68 + V_69 ) ;
F_43 ( 17 , F_34 , V_71 , 0 ,
L_11 ) ;
}
static int T_2 F_44 ( struct V_17 * V_18 ,
struct V_72 * V_73 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
int V_39 ;
V_39 = F_23 ( V_18 ,
L_12 ,
& V_18 -> V_51 ) ;
if ( V_39 )
return V_39 ;
if ( F_32 ( V_52 ) ) {
V_39 = F_23 ( V_18 ,
L_6 ,
& V_18 -> V_53 ) ;
if ( V_39 )
return V_39 ;
}
V_20 -> V_74 = - 1 ;
V_20 -> V_75 = & V_76 ;
V_39 = F_45 ( V_18 , V_18 -> V_47 ) ;
if ( V_39 ) {
F_11 ( & V_73 -> V_2 , L_13 ) ;
return V_39 ;
}
return V_39 ;
}
static int T_3 F_46 ( struct V_72 * V_73 )
{
struct V_17 * V_18 = F_47 ( V_73 ) ;
F_48 ( V_18 -> V_77 ) ;
return 0 ;
}
static int T_2 F_49 ( struct V_72 * V_73 )
{
struct V_40 * V_2 = & V_73 -> V_2 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_78 * V_79 ;
void T_4 * V_80 ;
struct V_81 * V_81 ;
int V_39 = 0 ;
V_18 = F_50 ( & V_73 -> V_2 , sizeof( * V_18 ) ,
V_82 ) ;
if ( ! V_18 )
return - V_83 ;
V_20 = & V_18 -> V_20 ;
V_81 = F_51 ( V_2 , L_14 ) ;
if ( ! F_52 ( V_81 ) ) {
V_39 = F_53 ( V_81 ) ;
if ( V_39 < 0 )
return V_39 ;
}
V_79 = F_54 ( V_73 , V_84 , 2 ) ;
V_80 = F_55 ( V_2 , V_79 ) ;
if ( F_56 ( V_80 ) )
return F_57 ( V_80 ) ;
V_18 -> V_66 = F_40 ( V_80 ) >> 16 ;
F_58 ( V_2 , V_80 ) ;
F_59 ( V_2 , V_79 -> V_85 , F_60 ( V_79 ) ) ;
V_20 -> V_2 = V_2 ;
F_61 ( V_73 , V_18 ) ;
V_18 -> V_77 = F_62 ( V_2 , L_15 ) ;
if ( F_56 ( V_18 -> V_77 ) ) {
F_11 ( V_2 , L_16 ) ;
return F_57 ( V_18 -> V_77 ) ;
}
V_39 = F_63 ( V_18 -> V_77 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_44 ( V_18 , V_73 ) ;
if ( V_39 < 0 )
goto V_86;
return 0 ;
V_86:
F_48 ( V_18 -> V_77 ) ;
return V_39 ;
}
