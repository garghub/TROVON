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
int V_35 , V_36 , V_37 = 1 , * V_38 , V_39 = - V_40 ;
struct V_41 * V_2 = V_18 -> V_20 . V_2 ;
struct V_42 * V_43 = V_2 -> V_44 , * * V_45 ;
if ( ! strcmp ( V_33 , L_6 ) )
V_37 = 0 ;
if ( V_37 ) {
V_45 = & V_18 -> V_46 ;
V_36 = V_47 ;
V_38 = & V_18 -> V_32 [ 0 ] ;
} else {
V_45 = & V_18 -> V_48 ;
V_36 = V_49 ;
V_38 = & V_18 -> V_27 [ 0 ] ;
}
* V_45 = F_25 ( V_43 , V_33 ) ;
if ( ! ( * V_45 ) ) {
F_11 ( V_2 , L_7 , V_33 ) ;
goto V_50;
}
V_35 = F_26 ( * V_45 ) ;
if ( ! V_35 )
goto V_50;
if ( V_35 > V_36 )
F_27 ( V_2 , L_8 ,
( V_37 ? L_9 : L_10 ) , V_35 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_38 [ V_35 ] = F_28 ( * V_45 , V_35 ) ;
if ( ! V_38 [ V_35 ] )
break;
}
if ( V_35 ) {
* V_34 = V_35 ;
V_39 = 0 ;
}
V_50:
return V_39 ;
}
static void F_29 ( struct V_17 * V_18 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_18 -> V_52 ; V_51 ++ ) {
F_30 ( V_18 -> V_32 [ V_51 ] ,
F_22 ,
V_18 ) ;
}
F_31 ( V_18 ) ;
if ( F_32 ( V_53 ) ) {
for ( V_51 = 0 ; V_51 < V_18 -> V_54 ; V_51 ++ ) {
F_30 ( V_18 -> V_27 [ V_51 ] ,
F_14 ,
V_18 ) ;
}
}
}
static int F_33 ( unsigned long V_55 , unsigned int V_56 ,
struct V_57 * V_58 )
{
unsigned long V_59 = * ( unsigned long * ) F_34 ( V_58 ) ;
if ( ( V_59 & 0x0e100090 ) == 0x00100090 ) {
int V_60 = ( V_59 >> 12 ) & 15 ;
V_58 -> V_61 [ V_60 ] = - 1 ;
V_58 -> V_62 += 4 ;
}
return 0 ;
}
static void T_2 F_35 ( struct V_19 * V_20 )
{
struct V_17 * V_18 = F_36 ( V_20 ) ;
T_1 V_63 ;
F_8 ( V_18 ) ;
F_37 ( V_18 ) ;
F_29 ( V_18 ) ;
F_38 ( V_64 | ( V_64 << 8 ) ,
V_20 -> V_65 + V_66 ) ;
F_38 ( V_18 -> V_67 , V_20 -> V_65 + V_68 ) ;
V_63 = F_39 ( V_20 -> V_65 + V_69 + V_70 ) ;
V_63 &= ~ V_71 ;
V_63 |= F_40 ( 12 ) ;
F_41 ( V_63 , V_20 -> V_65 + V_69 + V_70 ) ;
F_42 ( 17 , F_33 , V_72 , 0 ,
L_11 ) ;
}
static int T_2 F_43 ( struct V_17 * V_18 ,
struct V_73 * V_74 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
int V_39 ;
V_39 = F_24 ( V_18 ,
L_12 ,
& V_18 -> V_52 ) ;
if ( V_39 )
return V_39 ;
if ( F_32 ( V_53 ) ) {
V_39 = F_24 ( V_18 ,
L_6 ,
& V_18 -> V_54 ) ;
if ( V_39 )
return V_39 ;
}
V_20 -> V_75 = - 1 ;
V_20 -> V_76 = & V_77 ;
V_39 = F_44 ( V_18 , V_18 -> V_48 ) ;
if ( V_39 ) {
F_11 ( & V_74 -> V_2 , L_13 ) ;
return V_39 ;
}
return V_39 ;
}
static int T_3 F_45 ( struct V_73 * V_74 )
{
struct V_17 * V_18 = F_46 ( V_74 ) ;
F_47 ( V_18 -> V_78 ) ;
return 0 ;
}
static int T_2 F_48 ( struct V_73 * V_74 )
{
struct V_41 * V_2 = & V_74 -> V_2 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_79 * V_80 ;
void T_4 * V_81 ;
struct V_82 * V_82 ;
int V_39 = 0 ;
V_18 = F_49 ( & V_74 -> V_2 , sizeof( * V_18 ) ,
V_83 ) ;
if ( ! V_18 )
return - V_84 ;
V_20 = & V_18 -> V_20 ;
V_82 = F_50 ( V_2 , L_14 ) ;
if ( F_51 ( V_82 ) == - V_85 )
return F_52 ( V_82 ) ;
if ( ! F_53 ( V_82 ) ) {
V_39 = F_54 ( V_82 ) ;
if ( V_39 < 0 )
return V_39 ;
}
V_80 = F_55 ( V_74 , V_86 , 2 ) ;
V_81 = F_56 ( V_2 , V_80 ) ;
if ( F_57 ( V_81 ) )
return F_52 ( V_81 ) ;
V_18 -> V_67 = F_39 ( V_81 ) >> 16 ;
F_58 ( V_2 , V_81 ) ;
F_59 ( V_2 , V_80 -> V_87 , F_60 ( V_80 ) ) ;
V_20 -> V_2 = V_2 ;
F_61 ( V_74 , V_18 ) ;
V_18 -> V_78 = F_62 ( V_2 , L_15 ) ;
if ( F_57 ( V_18 -> V_78 ) ) {
F_11 ( V_2 , L_16 ) ;
return F_52 ( V_18 -> V_78 ) ;
}
V_39 = F_63 ( V_18 -> V_78 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_43 ( V_18 , V_74 ) ;
if ( V_39 < 0 )
goto V_88;
return 0 ;
V_88:
F_47 ( V_18 -> V_78 ) ;
return V_39 ;
}
