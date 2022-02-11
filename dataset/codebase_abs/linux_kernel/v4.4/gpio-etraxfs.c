static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
static unsigned int F_3 ( struct V_2 * V_3 )
{
return V_3 -> V_5 [ 0 ] - 'A' ;
}
static int F_4 ( struct V_2 * V_3 ,
const struct V_6 * V_7 ,
T_1 * V_8 )
{
if ( F_3 ( V_3 ) + 0xA != V_7 -> args [ 2 ] )
return - V_9 ;
return F_5 ( V_3 , V_7 , V_8 ) ;
}
static unsigned int F_6 ( unsigned int V_10 )
{
return V_10 % 8 ;
}
static unsigned int F_7 ( struct V_1 * V_11 ,
unsigned int V_10 )
{
return 4 * F_3 ( & V_11 -> V_4 . V_3 ) + V_10 / 8 ;
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_1 * V_11 =
F_1 ( F_9 ( V_13 ) ) ;
struct V_14 * V_15 = V_11 -> V_15 ;
unsigned int V_16 = F_6 ( V_13 -> V_17 ) ;
F_10 ( F_11 ( V_16 ) , V_15 -> V_18 + V_15 -> V_19 -> V_20 ) ;
}
static void F_12 ( struct V_12 * V_13 )
{
struct V_1 * V_11 =
F_1 ( F_9 ( V_13 ) ) ;
struct V_14 * V_15 = V_11 -> V_15 ;
unsigned int V_16 = F_6 ( V_13 -> V_17 ) ;
F_13 ( & V_15 -> V_21 ) ;
V_15 -> V_22 &= ~ F_11 ( V_16 ) ;
F_10 ( V_15 -> V_22 , V_15 -> V_18 + V_15 -> V_19 -> V_23 ) ;
F_14 ( & V_15 -> V_21 ) ;
}
static void F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_11 =
F_1 ( F_9 ( V_13 ) ) ;
struct V_14 * V_15 = V_11 -> V_15 ;
unsigned int V_16 = F_6 ( V_13 -> V_17 ) ;
F_13 ( & V_15 -> V_21 ) ;
V_15 -> V_22 |= F_11 ( V_16 ) ;
F_10 ( V_15 -> V_22 , V_15 -> V_18 + V_15 -> V_19 -> V_23 ) ;
F_14 ( & V_15 -> V_21 ) ;
}
static int F_16 ( struct V_12 * V_13 , T_1 type )
{
struct V_1 * V_11 =
F_1 ( F_9 ( V_13 ) ) ;
struct V_14 * V_15 = V_11 -> V_15 ;
unsigned int V_16 = F_6 ( V_13 -> V_17 ) ;
T_1 V_24 ;
switch ( type ) {
case V_25 :
V_24 = V_26 ;
break;
case V_27 :
V_24 = V_28 ;
break;
case V_29 :
V_24 = V_30 ;
break;
case V_31 :
V_24 = V_32 ;
break;
case V_33 :
V_24 = V_34 ;
break;
default:
return - V_9 ;
}
F_13 ( & V_15 -> V_21 ) ;
V_15 -> V_24 &= ~ ( 0x7 << ( V_16 * 3 ) ) ;
V_15 -> V_24 |= ( V_24 << ( V_16 * 3 ) ) ;
F_10 ( V_15 -> V_24 , V_15 -> V_18 + V_15 -> V_19 -> V_35 ) ;
F_14 ( & V_15 -> V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_1 * V_11 =
F_1 ( F_9 ( V_13 ) ) ;
struct V_14 * V_15 = V_11 -> V_15 ;
unsigned int V_16 = F_6 ( V_13 -> V_17 ) ;
int V_36 = - V_37 ;
F_13 ( & V_15 -> V_21 ) ;
if ( V_15 -> V_38 [ V_16 ] )
goto V_39;
V_36 = F_18 ( & V_11 -> V_4 . V_3 , V_13 -> V_17 ) ;
if ( V_36 )
goto V_39;
V_15 -> V_38 [ V_16 ] = V_13 -> V_40 ;
if ( V_15 -> V_19 -> V_41 ) {
unsigned int V_42 = F_7 ( V_11 , V_13 -> V_17 ) ;
V_15 -> V_43 &= ~ ( 0xf << ( V_16 * 4 ) ) ;
V_15 -> V_43 |= ( V_42 << ( V_16 * 4 ) ) ;
F_10 ( V_15 -> V_43 , V_15 -> V_18 + V_15 -> V_19 -> V_41 ) ;
}
V_39:
F_14 ( & V_15 -> V_21 ) ;
return V_36 ;
}
static void F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_11 =
F_1 ( F_9 ( V_13 ) ) ;
struct V_14 * V_15 = V_11 -> V_15 ;
unsigned int V_16 = F_6 ( V_13 -> V_17 ) ;
F_13 ( & V_15 -> V_21 ) ;
V_15 -> V_38 [ V_16 ] = 0 ;
F_20 ( & V_11 -> V_4 . V_3 , V_13 -> V_17 ) ;
F_14 ( & V_15 -> V_21 ) ;
}
static T_2 F_21 ( int V_40 , void * V_44 )
{
struct V_14 * V_15 = V_44 ;
unsigned long V_45 = F_22 ( V_15 -> V_18 + V_15 -> V_19 -> V_46 ) ;
int V_47 ;
F_23 (bit, &intr, 8 )
F_24 ( V_15 -> V_38 [ V_47 ] ) ;
return F_25 ( V_45 & 0xff ) ;
}
static int F_26 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = & V_49 -> V_51 ;
const struct V_52 * V_19 ;
const struct V_53 * V_54 ;
struct V_14 * V_15 ;
struct V_1 * V_55 ;
struct V_56 * V_57 , * V_40 ;
bool V_58 = false ;
void T_3 * V_18 ;
int V_36 ;
int V_59 ;
V_57 = F_27 ( V_49 , V_60 , 0 ) ;
V_18 = F_28 ( V_51 , V_57 ) ;
if ( F_29 ( V_18 ) )
return F_30 ( V_18 ) ;
V_54 = F_31 ( V_61 , V_51 -> V_62 ) ;
if ( ! V_54 )
return - V_9 ;
V_19 = V_54 -> V_63 ;
V_55 = F_32 ( V_51 , sizeof( * V_55 ) * V_19 -> V_64 , V_65 ) ;
if ( ! V_55 )
return - V_66 ;
V_40 = F_27 ( V_49 , V_67 , 0 ) ;
if ( ! V_40 )
return - V_9 ;
V_15 = F_32 ( V_51 , sizeof( * V_15 ) , V_65 ) ;
if ( ! V_15 )
return - V_66 ;
F_33 ( & V_15 -> V_21 ) ;
V_15 -> V_18 = V_18 ;
V_15 -> V_19 = V_19 ;
F_10 ( 0 , V_15 -> V_18 + V_19 -> V_23 ) ;
F_10 ( 0 , V_15 -> V_18 + V_19 -> V_35 ) ;
if ( V_19 -> V_41 ) {
V_58 = true ;
F_10 ( 0 , V_15 -> V_18 + V_19 -> V_41 ) ;
}
V_36 = F_34 ( V_51 , V_40 -> V_68 , F_21 ,
V_69 , F_35 ( V_51 ) , V_15 ) ;
if ( V_36 ) {
F_36 ( V_51 , L_1 , V_36 ) ;
return V_36 ;
}
for ( V_59 = 0 ; V_59 < V_19 -> V_64 ; V_59 ++ ) {
struct V_1 * V_11 = & V_55 [ V_59 ] ;
struct V_70 * V_4 = & V_11 -> V_4 ;
const struct V_71 * V_72 = & V_19 -> V_73 [ V_59 ] ;
unsigned long V_8 = V_74 ;
void T_3 * V_75 = V_18 + V_72 -> V_76 ;
void T_3 * V_77 = V_18 + V_72 -> V_78 ;
void T_3 * V_79 = V_18 + V_72 -> V_80 ;
V_11 -> V_15 = V_15 ;
if ( V_79 == V_77 ) {
V_79 = V_77 = NULL ;
V_8 = V_81 ;
}
V_36 = F_37 ( V_4 , V_51 , 4 ,
V_75 , V_77 , NULL , V_79 , NULL ,
V_8 ) ;
if ( V_36 ) {
F_36 ( V_51 , L_2 ,
V_72 -> V_5 ) ;
continue;
}
V_4 -> V_3 . V_82 = V_72 -> V_82 ;
V_4 -> V_3 . V_5 = V_72 -> V_5 ;
V_4 -> V_3 . V_62 = V_51 -> V_62 ;
V_4 -> V_3 . V_83 = 3 ;
V_4 -> V_3 . V_84 = F_4 ;
V_36 = F_38 ( & V_4 -> V_3 ) ;
if ( V_36 ) {
F_36 ( V_51 , L_3 ,
V_4 -> V_3 . V_5 ) ;
continue;
}
if ( V_59 > 0 && ! V_58 )
continue;
V_36 = F_39 ( & V_4 -> V_3 , & V_85 , 0 ,
V_86 , V_87 ) ;
if ( V_36 ) {
F_36 ( V_51 , L_4 ,
V_4 -> V_3 . V_5 ) ;
}
}
return 0 ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_88 ) ;
}
