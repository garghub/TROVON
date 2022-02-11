static inline void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_2 F_3 ( void T_1 * V_1 , T_2 V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static inline void F_5 ( void T_1 * V_1 , T_3 V_2 , T_3 V_3 )
{
F_6 ( V_3 , V_1 + V_2 ) ;
}
static inline T_3 F_7 ( void T_1 * V_1 , T_3 V_2 )
{
return F_8 ( V_1 + V_2 ) ;
}
static bool F_9 ( enum V_4 V_5 )
{
switch ( V_5 ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
default:
return false ;
}
}
static unsigned F_10 ( enum V_4 V_16 )
{
switch ( V_16 ) {
case V_17 :
case V_6 :
return V_18 ;
case V_7 :
return V_19 ;
case V_8 :
return V_20 ;
case V_9 :
return V_21 ;
case V_10 :
return V_22 ;
case V_11 :
return V_23 ;
case V_12 :
return V_24 ;
case V_13 :
return V_25 ;
case V_14 :
return V_26 ;
case V_15 :
return V_27 ;
default:
F_11 ( L_1 ) ;
return V_18 ;
}
}
static int F_12 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = & V_29 -> V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
int V_36 = 0 ;
int V_37 , V_38 ;
F_13 ( V_31 , L_2 ) ;
V_35 = F_14 ( V_31 , sizeof( struct V_34 ) , V_39 ) ;
if ( ! V_35 ) {
F_15 ( V_31 , L_3 ) ;
return - V_40 ;
}
V_33 = F_16 ( V_29 , V_41 , 0 ) ;
V_35 -> V_1 = F_17 ( V_31 , V_33 ) ;
if ( F_18 ( V_35 -> V_1 ) )
return F_19 ( V_35 -> V_1 ) ;
F_20 ( V_29 , V_35 ) ;
F_21 ( V_31 ) ;
F_22 ( V_31 ) ;
V_38 = F_3 ( V_35 -> V_1 , V_42 ) ;
switch ( V_38 ) {
case V_43 :
case V_44 :
V_35 -> V_45 = V_46 ;
break;
case V_47 :
case V_48 :
V_35 -> V_45 = V_49 ;
break;
default:
V_35 -> V_45 = V_46 ;
F_13 ( V_31 ,
L_4 ,
V_38 , V_35 -> V_45 ) ;
break;
}
V_35 -> V_50 = F_14 ( V_31 , sizeof( struct V_51 * ) * V_35 -> V_45 ,
V_39 ) ;
if ( ! V_35 -> V_50 ) {
V_36 = - V_40 ;
F_15 ( V_31 , L_5 ) ;
goto V_52;
}
for ( V_37 = 0 ; V_37 < V_35 -> V_45 ; V_37 ++ ) {
char V_53 [] = L_6 ;
snprintf ( V_53 , sizeof( V_53 ) ,
L_7 , V_37 ) ;
V_35 -> V_50 [ V_37 ] = F_23 ( V_31 , V_53 ) ;
if ( F_18 ( V_35 -> V_50 [ V_37 ] ) )
F_13 ( V_31 , L_8 , V_53 ) ;
else
F_24 ( V_35 -> V_50 [ V_37 ] ) ;
}
F_25 ( V_31 ) ;
F_26 ( & V_54 ) ;
V_55 = V_31 ;
F_27 ( & V_54 ) ;
return 0 ;
V_52:
F_25 ( V_31 ) ;
F_28 ( V_31 ) ;
return V_36 ;
}
static int F_29 ( struct V_28 * V_29 )
{
struct V_34 * V_35 = F_30 ( V_29 ) ;
int V_37 ;
F_26 ( & V_54 ) ;
V_55 = NULL ;
F_27 ( & V_54 ) ;
for ( V_37 = 0 ; V_37 < V_35 -> V_45 ; V_37 ++ ) {
if ( ! F_18 ( V_35 -> V_50 [ V_37 ] ) ) {
F_31 ( V_35 -> V_50 [ V_37 ] ) ;
F_32 ( V_35 -> V_50 [ V_37 ] ) ;
}
}
F_28 ( & V_29 -> V_31 ) ;
return 0 ;
}
int F_33 ( struct V_56 * V_57 )
{
int V_37 ;
bool V_58 ;
unsigned V_2 ;
struct V_34 * V_35 ;
if ( ! V_55 )
return - V_59 ;
F_22 ( V_55 ) ;
F_26 ( & V_54 ) ;
V_35 = F_34 ( V_55 ) ;
V_58 = false ;
for ( V_37 = 0 ; V_37 < V_35 -> V_45 ; V_37 ++ )
V_58 |= F_35 ( V_57 -> V_60 [ V_37 ] ) ;
if ( V_58 ) {
void T_1 * V_1 = V_35 -> V_1 ;
V_2 = F_3 ( V_1 , V_61 ) ;
V_2 |= ( V_62
| V_63 ) ;
V_2 &= ~ V_64 ;
V_2 &= ~ V_65 ;
F_1 ( V_1 , V_61 , V_2 ) ;
for ( V_37 = 0 ; V_37 < V_35 -> V_45 ; V_37 ++ ) {
V_2 = F_3 ( V_1 , F_36 ( V_37 ) ) ;
if ( F_9 ( V_57 -> V_60 [ V_37 ] ) ) {
V_2 |= F_10 ( V_57 -> V_60 [ V_37 ] )
<< V_66 ;
V_2 |= V_67 ;
} else if ( V_57 -> V_60 [ V_37 ] ==
V_68 ) {
V_2 &= ~ ( V_69
| V_70 ) ;
V_2 |= V_71 ;
V_2 |= V_72 ;
} else if ( V_57 -> V_60 [ V_37 ] ==
V_73 ) {
V_2 |= V_74
| V_75
| V_76
| V_71 ;
} else {
continue;
}
V_2 |= V_77 ;
F_1 ( V_1 , F_36 ( V_37 ) , V_2 ) ;
F_5 ( V_1 ,
F_37 ( V_37 ) ,
0xbe ) ;
}
}
F_27 ( & V_54 ) ;
F_25 ( V_55 ) ;
return 0 ;
}
int F_38 ( struct V_56 * V_57 )
{
int V_37 ;
struct V_34 * V_35 ;
if ( ! V_55 )
return - V_59 ;
F_22 ( V_55 ) ;
F_26 ( & V_54 ) ;
V_35 = F_34 ( V_55 ) ;
for ( V_37 = 0 ; V_37 < V_35 -> V_45 ; V_37 ++ ) {
if ( F_35 ( V_57 -> V_60 [ V_37 ] ) ) {
int V_78 ;
if ( F_18 ( V_35 -> V_50 [ V_37 ] ) )
continue;
V_78 = F_39 ( V_35 -> V_50 [ V_37 ] ) ;
if ( V_78 ) {
F_15 ( V_55 ,
L_9 , V_37 , V_78 ) ;
}
}
}
F_27 ( & V_54 ) ;
return 0 ;
}
int F_40 ( struct V_56 * V_57 )
{
int V_37 ;
struct V_34 * V_35 ;
if ( ! V_55 )
return - V_59 ;
F_26 ( & V_54 ) ;
V_35 = F_34 ( V_55 ) ;
for ( V_37 = 0 ; V_37 < V_35 -> V_45 ; V_37 ++ ) {
if ( F_35 ( V_57 -> V_60 [ V_37 ] ) ) {
if ( ! F_18 ( V_35 -> V_50 [ V_37 ] ) )
F_41 ( V_35 -> V_50 [ V_37 ] ) ;
}
}
F_27 ( & V_54 ) ;
F_25 ( V_55 ) ;
return 0 ;
}
static int T_4 F_42 ( void )
{
return F_43 ( & V_79 ) ;
}
static void T_5 F_44 ( void )
{
F_45 ( & V_79 ) ;
}
