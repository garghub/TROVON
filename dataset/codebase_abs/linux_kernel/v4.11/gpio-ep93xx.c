static void F_1 ( unsigned V_1 )
{
F_2 ( V_1 > 2 ) ;
F_3 ( 0 , F_4 ( V_2 [ V_1 ] ) ) ;
F_3 ( V_3 [ V_1 ] ,
F_4 ( V_4 [ V_1 ] ) ) ;
F_3 ( V_5 [ V_1 ] ,
F_4 ( V_6 [ V_1 ] ) ) ;
F_5 ( V_7 [ V_1 ] & V_8 [ V_1 ] ,
F_4 ( V_2 [ V_1 ] ) ) ;
}
static void F_6 ( unsigned int V_9 , bool V_10 )
{
int line = F_7 ( V_9 ) ;
int V_1 = line >> 3 ;
int V_11 = 1 << ( line & 7 ) ;
if ( V_10 )
V_12 [ V_1 ] |= V_11 ;
else
V_12 [ V_1 ] &= ~ V_11 ;
F_5 ( V_12 [ V_1 ] ,
F_4 ( V_13 [ V_1 ] ) ) ;
}
static void F_8 ( struct V_14 * V_15 )
{
unsigned char V_16 ;
int V_17 ;
V_16 = F_9 ( V_18 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
if ( V_16 & ( 1 << V_17 ) ) {
int V_19 = F_10 ( F_11 ( 0 ) ) + V_17 ;
F_12 ( V_19 ) ;
}
}
V_16 = F_9 ( V_20 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
if ( V_16 & ( 1 << V_17 ) ) {
int V_19 = F_10 ( F_13 ( 0 ) ) + V_17 ;
F_12 ( V_19 ) ;
}
}
}
static void F_14 ( struct V_14 * V_15 )
{
unsigned int V_9 = F_15 ( V_15 ) ;
int V_21 = ( ( V_9 + 1 ) & 7 ) ^ 4 ;
int V_19 = F_10 ( F_16 ( 0 ) ) + V_21 ;
F_12 ( V_19 ) ;
}
static void F_17 ( struct V_22 * V_23 )
{
int line = F_7 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
int V_11 = 1 << ( line & 7 ) ;
if ( F_18 ( V_23 ) == V_24 ) {
V_3 [ V_1 ] ^= V_11 ;
F_1 ( V_1 ) ;
}
F_5 ( V_11 , F_4 ( V_25 [ V_1 ] ) ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
int line = F_7 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
int V_11 = 1 << ( line & 7 ) ;
if ( F_18 ( V_23 ) == V_24 )
V_3 [ V_1 ] ^= V_11 ;
V_7 [ V_1 ] &= ~ V_11 ;
F_1 ( V_1 ) ;
F_5 ( V_11 , F_4 ( V_25 [ V_1 ] ) ) ;
}
static void F_20 ( struct V_22 * V_23 )
{
int line = F_7 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
V_7 [ V_1 ] &= ~ ( 1 << ( line & 7 ) ) ;
F_1 ( V_1 ) ;
}
static void F_21 ( struct V_22 * V_23 )
{
int line = F_7 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
V_7 [ V_1 ] |= 1 << ( line & 7 ) ;
F_1 ( V_1 ) ;
}
static int F_22 ( struct V_22 * V_23 , unsigned int type )
{
const int V_26 = F_7 ( V_23 -> V_9 ) ;
const int V_1 = V_26 >> 3 ;
const int V_11 = 1 << ( V_26 & 7 ) ;
T_1 V_27 ;
F_23 ( V_26 ) ;
switch ( type ) {
case V_28 :
V_5 [ V_1 ] |= V_11 ;
V_3 [ V_1 ] |= V_11 ;
V_27 = V_29 ;
break;
case V_30 :
V_5 [ V_1 ] |= V_11 ;
V_3 [ V_1 ] &= ~ V_11 ;
V_27 = V_29 ;
break;
case V_31 :
V_5 [ V_1 ] &= ~ V_11 ;
V_3 [ V_1 ] |= V_11 ;
V_27 = V_32 ;
break;
case V_33 :
V_5 [ V_1 ] &= ~ V_11 ;
V_3 [ V_1 ] &= ~ V_11 ;
V_27 = V_32 ;
break;
case V_24 :
V_5 [ V_1 ] |= V_11 ;
if ( F_24 ( V_26 ) )
V_3 [ V_1 ] &= ~ V_11 ;
else
V_3 [ V_1 ] |= V_11 ;
V_27 = V_29 ;
break;
default:
return - V_34 ;
}
F_25 ( V_23 , V_27 ) ;
V_8 [ V_1 ] |= V_11 ;
F_1 ( V_1 ) ;
return 0 ;
}
static void F_26 ( void )
{
int V_19 ;
for ( V_19 = F_10 ( 0 ) ;
V_19 <= F_10 ( V_35 ) ; ++ V_19 ) {
F_27 ( V_19 , & V_36 ,
V_32 ) ;
F_28 ( V_19 , V_37 ) ;
}
F_29 ( V_38 ,
F_8 ) ;
F_29 ( V_39 ,
F_14 ) ;
F_29 ( V_40 ,
F_14 ) ;
F_29 ( V_41 ,
F_14 ) ;
F_29 ( V_42 ,
F_14 ) ;
F_29 ( V_43 ,
F_14 ) ;
F_29 ( V_44 ,
F_14 ) ;
F_29 ( V_45 ,
F_14 ) ;
F_29 ( V_46 ,
F_14 ) ;
}
static int F_30 ( struct V_47 * V_48 , unsigned V_49 ,
unsigned long V_50 )
{
int V_26 = V_48 -> V_51 + V_49 ;
int V_9 = F_10 ( V_26 ) ;
T_2 V_52 ;
if ( F_31 ( V_50 ) != V_53 )
return - V_54 ;
if ( V_9 < 0 )
return - V_34 ;
V_52 = F_32 ( V_50 ) ;
F_6 ( V_9 , V_52 ? true : false ) ;
return 0 ;
}
static int F_33 ( struct V_47 * V_48 , unsigned V_49 )
{
int V_26 = V_48 -> V_51 + V_49 ;
if ( V_26 > V_35 )
return - V_34 ;
return 64 + V_26 ;
}
static int F_34 ( struct V_47 * V_55 , struct V_56 * V_57 ,
void T_3 * V_58 , struct V_59 * V_60 )
{
void T_3 * V_61 = V_58 + V_60 -> V_61 ;
void T_3 * V_62 = V_58 + V_60 -> V_62 ;
int V_63 ;
V_63 = F_35 ( V_55 , V_57 , 1 , V_61 , NULL , NULL , V_62 , NULL , 0 ) ;
if ( V_63 )
return V_63 ;
V_55 -> V_64 = V_60 -> V_64 ;
V_55 -> V_51 = V_60 -> V_51 ;
if ( V_60 -> V_65 ) {
V_55 -> V_66 = F_30 ;
V_55 -> V_67 = F_33 ;
}
return F_36 ( V_57 , V_55 , NULL ) ;
}
static int F_37 ( struct V_68 * V_69 )
{
struct V_70 * V_70 ;
struct V_71 * V_72 ;
int V_17 ;
struct V_56 * V_57 = & V_69 -> V_57 ;
V_70 = F_38 ( V_57 , sizeof( struct V_70 ) , V_73 ) ;
if ( ! V_70 )
return - V_74 ;
V_72 = F_39 ( V_69 , V_75 , 0 ) ;
V_70 -> V_58 = F_40 ( V_57 , V_72 ) ;
if ( F_41 ( V_70 -> V_58 ) )
return F_42 ( V_70 -> V_58 ) ;
for ( V_17 = 0 ; V_17 < F_43 ( V_76 ) ; V_17 ++ ) {
struct V_47 * V_55 = & V_70 -> V_55 [ V_17 ] ;
struct V_59 * V_60 = & V_76 [ V_17 ] ;
if ( F_34 ( V_55 , & V_69 -> V_57 ,
V_70 -> V_58 , V_60 ) )
F_44 ( & V_69 -> V_57 , L_1 ,
V_60 -> V_64 ) ;
}
F_26 () ;
return 0 ;
}
static int T_4 F_45 ( void )
{
return F_46 ( & V_77 ) ;
}
