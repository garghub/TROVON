static unsigned char F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_3 = ( unsigned char ) F_3 ( V_5 ) ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned char * V_6 , int V_7 )
{
int V_8 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_6 [ V_8 ] = ( unsigned char ) F_3 ( V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
const unsigned char * V_6 , int V_7 )
{
int V_8 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
F_6 ( V_5 , V_6 [ V_8 ] ) ;
}
static int F_7 ( struct V_1 * V_2 ,
const unsigned char * V_6 , int V_7 )
{
int V_8 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
if ( V_6 [ V_8 ] != ( unsigned char ) F_3 ( V_5 ) )
return - V_9 ;
}
return 0 ;
}
static int F_8 ( struct V_4 * V_5 )
{
unsigned int V_10 ;
F_9 ( & V_5 -> V_11 ) ;
V_10 = F_10 ( V_12 ) ;
V_10 &= V_13 ;
F_11 ( & V_5 -> V_11 ) ;
return V_10 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_14 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_14 = ( F_8 ( V_5 ) ) ? 1 : 0 ;
return V_14 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int V_15 ,
int V_16 , int V_17 )
{
register struct V_18 * V_19 = V_2 -> V_20 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_15 == V_21 ) {
V_16 += V_2 -> V_22 ;
V_15 = V_23 ;
}
F_14 ( V_5 , V_15 & 0xff ) ;
if ( V_16 != - 1 || V_17 != - 1 ) {
if ( V_16 != - 1 ) {
if ( V_19 -> V_24 & V_25 )
V_16 >>= 1 ;
F_15 ( V_5 , V_16 ) ;
F_15 ( V_5 , V_16 >> 8 | V_26 ) ;
}
if ( V_17 != - 1 ) {
F_15 ( V_5 , V_17 ) ;
if ( V_19 -> V_27 > ( 128 << 20 ) ) {
F_15 ( V_5 , V_17 >> 8 ) ;
F_15 ( V_5 , V_17 >> 16 | V_26 ) ;
} else {
F_15 ( V_5 , V_17 >> 8 | V_26 ) ;
}
}
}
switch ( V_15 ) {
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return;
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
F_16 ( V_19 -> V_41 ) ;
return;
case V_42 :
if ( V_19 -> V_43 )
break;
F_16 ( V_19 -> V_41 ) ;
F_14 ( V_5 , V_34 ) ;
F_14 ( V_5 , V_15 ) ;
while ( ! F_8 ( V_5 ) )
;
return;
case V_44 :
F_14 ( V_5 , V_45 ) ;
return;
case V_23 :
F_14 ( V_5 , V_46 ) ;
default:
if ( ! V_19 -> V_43 ) {
F_16 ( V_19 -> V_41 ) ;
return;
}
}
F_17 ( 100 ) ;
while ( ! V_19 -> V_43 ( V_2 ) )
;
}
static void F_18 ( struct V_4 * V_5 )
{
unsigned int V_10 ;
F_9 ( & V_5 -> V_11 ) ;
F_19 ( V_47 , ( V_5 -> V_48 + V_49 ) ) ;
V_10 = F_10 ( V_5 -> V_48 + V_49 ) ;
if ( ! ( V_10 & V_50 ) )
F_19 ( V_10 | V_50 , V_49 ) ;
V_10 = F_10 ( V_5 -> V_48 + V_51 ) ;
V_10 &= ~ ( V_52 | V_53 | V_54 | V_55 | V_56 | V_57 ) ;
V_10 |= V_58 ;
F_19 ( V_10 , V_5 -> V_48 + V_51 ) ;
F_11 ( & V_5 -> V_11 ) ;
}
static int T_1 F_20 ( struct V_59 * V_60 )
{
struct V_4 * V_4 ;
struct V_18 * V_19 ;
int V_61 ;
struct V_62 * V_63 ;
V_61 = 0 ;
V_4 = F_21 ( sizeof( struct V_4 ) , V_64 ) ;
if ( ! V_4 )
return - V_65 ;
V_19 = & ( V_4 -> V_19 ) ;
V_4 -> V_2 . V_20 = V_19 ;
V_4 -> V_2 . V_66 = V_67 ;
F_22 ( & V_4 -> V_11 ) ;
V_4 -> V_68 = F_23 ( & V_60 -> V_69 , NULL ) ;
if ( F_24 ( V_4 -> V_68 ) ) {
V_61 = - V_70 ;
goto V_71;
}
F_25 ( V_4 -> V_68 ) ;
V_19 -> V_72 = F_13 ;
V_19 -> V_43 = F_12 ;
V_19 -> V_73 = F_1 ;
V_19 -> V_74 = F_5 ;
V_19 -> V_75 = F_4 ;
V_19 -> V_76 = F_7 ;
V_19 -> V_41 = 50 ;
V_19 -> V_24 = 0 ;
V_19 -> V_77 . V_78 = V_79 ;
V_63 = F_26 ( V_60 , V_80 , 0 ) ;
if ( ! V_63 ) {
V_61 = - V_81 ;
goto V_71;
}
if ( ! F_27 ( V_63 -> V_82 , F_28 ( V_63 ) , V_60 -> V_83 ) ) {
V_61 = - V_84 ;
goto V_71;
}
V_4 -> V_48 = F_29 ( V_63 -> V_82 , F_28 ( V_63 ) ) ;
if ( ! V_4 -> V_48 ) {
V_61 = - V_65 ;
goto V_85;
}
F_18 ( V_4 ) ;
if ( F_30 ( & ( V_4 -> V_2 ) , 1 ) ) {
V_61 = - V_81 ;
goto V_86;
}
F_31 ( & ( V_4 -> V_2 ) , V_87 ,
F_32 ( V_87 ) ) ;
F_33 ( V_60 , V_4 ) ;
return V_61 ;
V_86: F_34 ( V_4 -> V_48 ) ;
V_85: F_35 ( V_63 -> V_82 , F_28 ( V_63 ) ) ;
V_71: F_36 ( V_4 ) ;
return V_61 ;
}
static int T_2 F_37 ( struct V_59 * V_60 )
{
struct V_4 * V_4 = F_38 ( V_60 ) ;
struct V_62 * V_63 ;
F_34 ( V_4 -> V_48 ) ;
V_63 = F_26 ( V_60 , V_80 , 0 ) ;
F_35 ( V_63 -> V_82 , F_28 ( V_63 ) ) ;
F_39 ( V_4 -> V_68 ) ;
F_40 ( V_4 -> V_68 ) ;
F_36 ( V_4 ) ;
F_33 ( V_60 , NULL ) ;
return 0 ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_88 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_88 ) ;
}
