static unsigned int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 [ 0 ] - 'A' ;
}
static int F_2 ( struct V_1 * V_2 ,
const struct V_4 * V_5 ,
T_1 * V_6 )
{
if ( F_1 ( V_2 ) + 0xA != V_5 -> args [ 2 ] )
return - V_7 ;
return F_3 ( V_2 , V_5 , V_6 ) ;
}
static unsigned int F_4 ( unsigned int V_8 )
{
return V_8 % 8 ;
}
static unsigned int F_5 ( struct V_9 * V_10 ,
unsigned int V_8 )
{
return 4 * F_1 ( & V_10 -> V_2 ) + V_8 / 8 ;
}
static void F_6 ( struct V_11 * V_12 )
{
struct V_9 * V_10 =
F_7 ( F_8 ( V_12 ) ) ;
struct V_13 * V_14 = V_10 -> V_14 ;
unsigned int V_15 = F_4 ( V_12 -> V_16 ) ;
F_9 ( F_10 ( V_15 ) , V_14 -> V_17 + V_14 -> V_18 -> V_19 ) ;
}
static void F_11 ( struct V_11 * V_12 )
{
struct V_9 * V_10 =
F_7 ( F_8 ( V_12 ) ) ;
struct V_13 * V_14 = V_10 -> V_14 ;
unsigned int V_15 = F_4 ( V_12 -> V_16 ) ;
F_12 ( & V_14 -> V_20 ) ;
V_14 -> V_21 &= ~ F_10 ( V_15 ) ;
F_9 ( V_14 -> V_21 , V_14 -> V_17 + V_14 -> V_18 -> V_22 ) ;
F_13 ( & V_14 -> V_20 ) ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_9 * V_10 =
F_7 ( F_8 ( V_12 ) ) ;
struct V_13 * V_14 = V_10 -> V_14 ;
unsigned int V_15 = F_4 ( V_12 -> V_16 ) ;
F_12 ( & V_14 -> V_20 ) ;
V_14 -> V_21 |= F_10 ( V_15 ) ;
F_9 ( V_14 -> V_21 , V_14 -> V_17 + V_14 -> V_18 -> V_22 ) ;
F_13 ( & V_14 -> V_20 ) ;
}
static int F_15 ( struct V_11 * V_12 , T_1 type )
{
struct V_9 * V_10 =
F_7 ( F_8 ( V_12 ) ) ;
struct V_13 * V_14 = V_10 -> V_14 ;
unsigned int V_15 = F_4 ( V_12 -> V_16 ) ;
T_1 V_23 ;
switch ( type ) {
case V_24 :
V_23 = V_25 ;
break;
case V_26 :
V_23 = V_27 ;
break;
case V_28 :
V_23 = V_29 ;
break;
case V_30 :
V_23 = V_31 ;
break;
case V_32 :
V_23 = V_33 ;
break;
default:
return - V_7 ;
}
F_12 ( & V_14 -> V_20 ) ;
V_14 -> V_23 &= ~ ( 0x7 << ( V_15 * 3 ) ) ;
V_14 -> V_23 |= ( V_23 << ( V_15 * 3 ) ) ;
F_9 ( V_14 -> V_23 , V_14 -> V_17 + V_14 -> V_18 -> V_34 ) ;
F_13 ( & V_14 -> V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_9 * V_10 =
F_7 ( F_8 ( V_12 ) ) ;
struct V_13 * V_14 = V_10 -> V_14 ;
unsigned int V_15 = F_4 ( V_12 -> V_16 ) ;
int V_35 = - V_36 ;
F_12 ( & V_14 -> V_20 ) ;
if ( V_14 -> V_37 [ V_15 ] )
goto V_38;
V_35 = F_17 ( & V_10 -> V_2 , V_12 -> V_16 ) ;
if ( V_35 )
goto V_38;
V_14 -> V_37 [ V_15 ] = V_12 -> V_39 ;
if ( V_14 -> V_18 -> V_40 ) {
unsigned int V_41 = F_5 ( V_10 , V_12 -> V_16 ) ;
V_14 -> V_42 &= ~ ( 0xf << ( V_15 * 4 ) ) ;
V_14 -> V_42 |= ( V_41 << ( V_15 * 4 ) ) ;
F_9 ( V_14 -> V_42 , V_14 -> V_17 + V_14 -> V_18 -> V_40 ) ;
}
V_38:
F_13 ( & V_14 -> V_20 ) ;
return V_35 ;
}
static void F_18 ( struct V_11 * V_12 )
{
struct V_9 * V_10 =
F_7 ( F_8 ( V_12 ) ) ;
struct V_13 * V_14 = V_10 -> V_14 ;
unsigned int V_15 = F_4 ( V_12 -> V_16 ) ;
F_12 ( & V_14 -> V_20 ) ;
V_14 -> V_37 [ V_15 ] = 0 ;
F_19 ( & V_10 -> V_2 , V_12 -> V_16 ) ;
F_13 ( & V_14 -> V_20 ) ;
}
static T_2 F_20 ( int V_39 , void * V_43 )
{
struct V_13 * V_14 = V_43 ;
unsigned long V_44 = F_21 ( V_14 -> V_17 + V_14 -> V_18 -> V_45 ) ;
int V_46 ;
F_22 (bit, &intr, 8 )
F_23 ( V_14 -> V_37 [ V_46 ] ) ;
return F_24 ( V_44 & 0xff ) ;
}
static int F_25 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = & V_48 -> V_50 ;
const struct V_51 * V_18 ;
const struct V_52 * V_53 ;
struct V_13 * V_14 ;
struct V_9 * V_54 ;
struct V_55 * V_56 , * V_39 ;
bool V_57 = false ;
void T_3 * V_17 ;
int V_35 ;
int V_58 ;
V_56 = F_26 ( V_48 , V_59 , 0 ) ;
V_17 = F_27 ( V_50 , V_56 ) ;
if ( F_28 ( V_17 ) )
return F_29 ( V_17 ) ;
V_53 = F_30 ( V_60 , V_50 -> V_61 ) ;
if ( ! V_53 )
return - V_7 ;
V_18 = V_53 -> V_62 ;
V_54 = F_31 ( V_50 , sizeof( * V_54 ) * V_18 -> V_63 , V_64 ) ;
if ( ! V_54 )
return - V_65 ;
V_39 = F_26 ( V_48 , V_66 , 0 ) ;
if ( ! V_39 )
return - V_7 ;
V_14 = F_31 ( V_50 , sizeof( * V_14 ) , V_64 ) ;
if ( ! V_14 )
return - V_65 ;
F_32 ( & V_14 -> V_20 ) ;
V_14 -> V_17 = V_17 ;
V_14 -> V_18 = V_18 ;
F_9 ( 0 , V_14 -> V_17 + V_18 -> V_22 ) ;
F_9 ( 0 , V_14 -> V_17 + V_18 -> V_34 ) ;
if ( V_18 -> V_40 ) {
V_57 = true ;
F_9 ( 0 , V_14 -> V_17 + V_18 -> V_40 ) ;
}
V_35 = F_33 ( V_50 , V_39 -> V_67 , F_20 ,
V_68 , F_34 ( V_50 ) , V_14 ) ;
if ( V_35 ) {
F_35 ( V_50 , L_1 , V_35 ) ;
return V_35 ;
}
for ( V_58 = 0 ; V_58 < V_18 -> V_63 ; V_58 ++ ) {
struct V_9 * V_10 = & V_54 [ V_58 ] ;
struct V_1 * V_2 = & V_10 -> V_2 ;
const struct V_69 * V_70 = & V_18 -> V_71 [ V_58 ] ;
unsigned long V_6 = V_72 ;
void T_3 * V_73 = V_17 + V_70 -> V_74 ;
void T_3 * V_75 = V_17 + V_70 -> V_76 ;
void T_3 * V_77 = V_17 + V_70 -> V_78 ;
V_10 -> V_14 = V_14 ;
if ( V_77 == V_75 ) {
V_77 = V_75 = NULL ;
V_6 = V_79 ;
}
V_35 = F_36 ( V_2 , V_50 , 4 ,
V_73 , V_75 , NULL , V_77 , NULL ,
V_6 ) ;
if ( V_35 ) {
F_35 ( V_50 , L_2 ,
V_70 -> V_3 ) ;
continue;
}
V_2 -> V_80 = V_70 -> V_80 ;
V_2 -> V_3 = V_70 -> V_3 ;
V_2 -> V_61 = V_50 -> V_61 ;
V_2 -> V_81 = 3 ;
V_2 -> V_82 = F_2 ;
V_35 = F_37 ( V_2 , V_10 ) ;
if ( V_35 ) {
F_35 ( V_50 , L_3 ,
V_2 -> V_3 ) ;
continue;
}
if ( V_58 > 0 && ! V_57 )
continue;
V_35 = F_38 ( V_2 , & V_83 , 0 ,
V_84 , V_85 ) ;
if ( V_35 ) {
F_35 ( V_50 , L_4 ,
V_2 -> V_3 ) ;
}
}
return 0 ;
}
static int T_4 F_39 ( void )
{
return F_40 ( & V_86 ) ;
}
