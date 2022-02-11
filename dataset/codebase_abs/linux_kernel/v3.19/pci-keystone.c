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
int V_21 = 200 ;
F_9 ( V_20 ) ;
if ( F_10 ( V_20 ) ) {
F_11 ( V_20 -> V_2 , L_2 ) ;
return 0 ;
}
F_12 ( V_18 ) ;
while ( ! F_10 ( V_20 ) ) {
F_13 ( 100 , 1000 ) ;
if ( -- V_21 ) {
F_12 ( V_18 ) ;
continue;
}
F_11 ( V_20 -> V_2 , L_3 ) ;
return - V_22 ;
}
return 0 ;
}
static void F_14 ( unsigned int V_23 , struct V_24 * V_25 )
{
struct V_17 * V_18 = F_15 ( V_25 ) ;
T_1 V_26 = V_23 - V_18 -> V_27 [ 0 ] ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_28 * V_29 = F_16 ( V_25 ) ;
F_17 ( V_20 -> V_2 , L_4 , V_23 ) ;
F_18 ( V_29 , V_25 ) ;
F_19 ( V_18 , V_26 ) ;
F_20 ( V_29 , V_25 ) ;
}
static void F_21 ( unsigned int V_23 , struct V_24 * V_25 )
{
struct V_17 * V_18 = F_15 ( V_25 ) ;
struct V_19 * V_20 = & V_18 -> V_20 ;
T_1 V_30 = V_23 - V_18 -> V_31 [ 0 ] ;
struct V_28 * V_29 = F_16 ( V_25 ) ;
F_17 ( V_20 -> V_2 , L_5 , V_23 ) ;
F_18 ( V_29 , V_25 ) ;
F_22 ( V_18 , V_30 ) ;
F_20 ( V_29 , V_25 ) ;
}
static int F_23 ( struct V_17 * V_18 ,
char * V_32 , int * V_33 )
{
int V_34 , V_35 , V_36 = 1 , * V_37 , V_38 = - V_22 ;
struct V_39 * V_2 = V_18 -> V_20 . V_2 ;
struct V_40 * V_41 = V_2 -> V_42 , * * V_43 ;
if ( ! strcmp ( V_32 , L_6 ) )
V_36 = 0 ;
if ( V_36 ) {
V_43 = & V_18 -> V_44 ;
V_35 = V_45 ;
V_37 = & V_18 -> V_31 [ 0 ] ;
} else {
V_43 = & V_18 -> V_46 ;
V_35 = V_47 ;
V_37 = & V_18 -> V_27 [ 0 ] ;
}
* V_43 = F_24 ( V_41 , V_32 ) ;
if ( ! ( * V_43 ) ) {
F_11 ( V_2 , L_7 , V_32 ) ;
goto V_48;
}
V_34 = F_25 ( * V_43 ) ;
if ( ! V_34 )
goto V_48;
if ( V_34 > V_35 )
F_26 ( V_2 , L_8 ,
( V_36 ? L_9 : L_10 ) , V_34 ) ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_37 [ V_34 ] = F_27 ( * V_43 , V_34 ) ;
if ( V_37 [ V_34 ] < 0 )
break;
}
if ( V_34 ) {
* V_33 = V_34 ;
V_38 = 0 ;
}
V_48:
return V_38 ;
}
static void F_28 ( struct V_17 * V_18 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_18 -> V_50 ; V_49 ++ ) {
F_29 ( V_18 -> V_31 [ V_49 ] , V_18 ) ;
F_30 ( V_18 -> V_31 [ V_49 ] ,
F_21 ) ;
}
F_31 ( V_18 ) ;
if ( F_32 ( V_51 ) ) {
for ( V_49 = 0 ; V_49 < V_18 -> V_52 ; V_49 ++ ) {
F_30 ( V_18 -> V_27 [ V_49 ] ,
F_14 ) ;
F_29 ( V_18 -> V_27 [ V_49 ] ,
V_18 ) ;
}
}
}
static int F_33 ( unsigned long V_53 , unsigned int V_54 ,
struct V_55 * V_56 )
{
unsigned long V_57 = * ( unsigned long * ) F_34 ( V_56 ) ;
if ( ( V_57 & 0x0e100090 ) == 0x00100090 ) {
int V_58 = ( V_57 >> 12 ) & 15 ;
V_56 -> V_59 [ V_58 ] = - 1 ;
V_56 -> V_60 += 4 ;
}
return 0 ;
}
static void T_2 F_35 ( struct V_19 * V_20 )
{
struct V_17 * V_18 = F_36 ( V_20 ) ;
T_1 V_61 ;
F_8 ( V_18 ) ;
F_37 ( V_18 ) ;
F_28 ( V_18 ) ;
F_38 ( V_62 | ( V_62 << 8 ) ,
V_20 -> V_63 + V_64 ) ;
F_38 ( V_18 -> V_65 , V_20 -> V_63 + V_66 ) ;
V_61 = F_39 ( V_20 -> V_63 + V_67 + V_68 ) ;
V_61 &= ~ V_69 ;
V_61 |= F_40 ( 12 ) ;
F_41 ( V_61 , V_20 -> V_63 + V_67 + V_68 ) ;
F_42 ( 17 , F_33 , V_70 , 0 ,
L_11 ) ;
}
static int T_2 F_43 ( struct V_17 * V_18 ,
struct V_71 * V_72 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
int V_38 ;
V_38 = F_23 ( V_18 ,
L_12 ,
& V_18 -> V_50 ) ;
if ( V_38 )
return V_38 ;
if ( F_32 ( V_51 ) ) {
V_38 = F_23 ( V_18 ,
L_6 ,
& V_18 -> V_52 ) ;
if ( V_38 )
return V_38 ;
}
V_20 -> V_73 = - 1 ;
V_20 -> V_74 = & V_75 ;
V_38 = F_44 ( V_18 , V_18 -> V_46 ) ;
if ( V_38 ) {
F_11 ( & V_72 -> V_2 , L_13 ) ;
return V_38 ;
}
return V_38 ;
}
static int T_3 F_45 ( struct V_71 * V_72 )
{
struct V_17 * V_18 = F_46 ( V_72 ) ;
F_47 ( V_18 -> V_76 ) ;
return 0 ;
}
static int T_2 F_48 ( struct V_71 * V_72 )
{
struct V_39 * V_2 = & V_72 -> V_2 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_77 * V_78 ;
void T_4 * V_79 ;
struct V_80 * V_80 ;
int V_38 = 0 ;
V_18 = F_49 ( & V_72 -> V_2 , sizeof( * V_18 ) ,
V_81 ) ;
if ( ! V_18 )
return - V_82 ;
V_20 = & V_18 -> V_20 ;
V_80 = F_50 ( V_2 , L_14 ) ;
if ( ! F_51 ( V_80 ) ) {
V_38 = F_52 ( V_80 ) ;
if ( V_38 < 0 )
return V_38 ;
}
V_78 = F_53 ( V_72 , V_83 , 2 ) ;
V_79 = F_54 ( V_2 , V_78 ) ;
if ( F_55 ( V_79 ) )
return F_56 ( V_79 ) ;
V_18 -> V_65 = F_39 ( V_79 ) >> 16 ;
F_57 ( V_2 , V_79 ) ;
F_58 ( V_2 , V_78 -> V_84 , F_59 ( V_78 ) ) ;
V_20 -> V_2 = V_2 ;
F_60 ( V_72 , V_18 ) ;
V_18 -> V_76 = F_61 ( V_2 , L_15 ) ;
if ( F_55 ( V_18 -> V_76 ) ) {
F_11 ( V_2 , L_16 ) ;
return F_56 ( V_18 -> V_76 ) ;
}
V_38 = F_62 ( V_18 -> V_76 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_43 ( V_18 , V_72 ) ;
if ( V_38 < 0 )
goto V_85;
return 0 ;
V_85:
F_47 ( V_18 -> V_76 ) ;
return V_38 ;
}
