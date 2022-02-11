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
struct V_32 * V_33 = V_31 -> V_34 ;
void T_1 * V_1 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
unsigned V_2 ;
int V_39 = 0 ;
int V_40 , V_41 ;
bool V_42 ;
F_13 ( V_31 , L_2 ) ;
V_38 = F_14 ( V_31 , sizeof( struct V_37 ) , V_43 ) ;
if ( ! V_38 ) {
F_15 ( V_31 , L_3 ) ;
return - V_44 ;
}
if ( ! V_33 ) {
F_15 ( V_31 , L_4 ) ;
return - V_45 ;
}
V_38 -> V_33 = V_33 ;
V_36 = F_16 ( V_29 , V_46 , 0 ) ;
V_1 = F_17 ( V_31 , V_36 ) ;
if ( ! V_1 ) {
V_39 = - V_47 ;
F_15 ( V_31 , L_5 , V_39 ) ;
return V_39 ;
}
F_18 ( V_29 , V_38 ) ;
F_19 ( V_31 ) ;
F_20 ( V_31 ) ;
V_41 = F_3 ( V_1 , V_48 ) ;
switch ( V_41 ) {
case V_49 :
case V_50 :
V_38 -> V_51 = V_52 ;
break;
case V_53 :
case V_54 :
V_38 -> V_51 = V_55 ;
break;
default:
V_38 -> V_51 = V_52 ;
F_13 ( V_31 ,
L_6 ,
V_41 , V_38 -> V_51 ) ;
break;
}
V_38 -> V_56 = F_14 ( V_31 , sizeof( struct V_57 * [ V_38 -> V_51 ] ) ,
V_43 ) ;
if ( ! V_38 -> V_56 ) {
V_39 = - V_44 ;
F_15 ( V_31 , L_7 ) ;
goto V_58;
}
for ( V_40 = 0 ; V_40 < V_38 -> V_51 ; V_40 ++ ) {
char V_59 [] = L_8 ;
snprintf ( V_59 , sizeof( V_59 ) ,
L_9 , V_40 ) ;
V_38 -> V_56 [ V_40 ] = F_21 ( V_31 , V_59 ) ;
if ( F_22 ( V_38 -> V_56 [ V_40 ] ) )
F_13 ( V_31 , L_10 , V_59 ) ;
}
V_42 = false ;
for ( V_40 = 0 ; V_40 < V_38 -> V_51 ; V_40 ++ )
V_42 |= F_23 ( V_33 -> V_60 [ V_40 ] ) ;
if ( V_42 ) {
V_2 = F_3 ( V_1 , V_61 ) ;
V_2 |= ( V_62
| V_63 ) ;
V_2 &= ~ V_64 ;
V_2 &= ~ V_65 ;
F_1 ( V_1 , V_61 , V_2 ) ;
for ( V_40 = 0 ; V_40 < V_38 -> V_51 ; V_40 ++ ) {
V_2 = F_3 ( V_1 , F_24 ( V_40 ) ) ;
if ( F_9 ( V_33 -> V_60 [ V_40 ] ) ) {
V_2 |= F_10 ( V_33 -> V_60 [ V_40 ] )
<< V_66 ;
V_2 |= V_67 ;
} else if ( V_33 -> V_60 [ V_40 ] ==
V_68 ) {
V_2 &= ~ ( V_69
| V_70
| V_71 ) ;
} else if ( V_33 -> V_60 [ V_40 ] ==
V_72 ) {
V_2 |= V_73
| V_74
| V_75
| V_70 ;
} else {
continue;
}
V_2 |= V_76 ;
F_1 ( V_1 , F_24 ( V_40 ) , V_2 ) ;
F_5 ( V_1 ,
F_25 ( V_40 ) ,
0xbe ) ;
}
}
F_26 ( V_31 ) ;
F_27 ( & V_77 ) ;
V_78 = V_31 ;
F_28 ( & V_77 ) ;
return 0 ;
V_58:
F_26 ( V_31 ) ;
F_29 ( V_31 ) ;
return V_39 ;
}
static int F_30 ( struct V_28 * V_29 )
{
struct V_37 * V_38 = F_31 ( V_29 ) ;
int V_40 ;
F_27 ( & V_77 ) ;
V_78 = NULL ;
F_28 ( & V_77 ) ;
for ( V_40 = 0 ; V_40 < V_38 -> V_51 ; V_40 ++ )
if ( ! F_22 ( V_38 -> V_56 [ V_40 ] ) )
F_32 ( V_38 -> V_56 [ V_40 ] ) ;
F_29 ( & V_29 -> V_31 ) ;
return 0 ;
}
static int F_33 ( struct V_30 * V_31 )
{
struct V_37 * V_38 = F_34 ( V_31 ) ;
struct V_32 * V_33 = V_38 -> V_33 ;
int V_40 ;
F_13 ( V_31 , L_11 ) ;
for ( V_40 = 0 ; V_40 < V_38 -> V_51 ; V_40 ++ ) {
if ( F_23 ( V_33 -> V_60 [ V_40 ] ) ) {
int V_79 ;
if ( F_22 ( V_38 -> V_56 [ V_40 ] ) )
continue;
V_79 = F_35 ( V_38 -> V_56 [ V_40 ] ) ;
if ( V_79 ) {
F_15 ( V_31 ,
L_12 , V_40 , V_79 ) ;
}
}
}
return 0 ;
}
static int F_36 ( struct V_30 * V_31 )
{
struct V_37 * V_38 = F_34 ( V_31 ) ;
struct V_32 * V_33 = V_38 -> V_33 ;
int V_40 ;
F_13 ( V_31 , L_13 ) ;
for ( V_40 = 0 ; V_40 < V_38 -> V_51 ; V_40 ++ ) {
if ( F_23 ( V_33 -> V_60 [ V_40 ] ) ) {
if ( ! F_22 ( V_38 -> V_56 [ V_40 ] ) )
F_37 ( V_38 -> V_56 [ V_40 ] ) ;
}
}
return 0 ;
}
int F_38 ( void )
{
int V_39 ;
F_27 ( & V_77 ) ;
if ( ! V_78 ) {
F_39 ( L_14 , V_80 ) ;
V_39 = - V_45 ;
} else {
V_39 = F_20 ( V_78 ) ;
}
F_28 ( & V_77 ) ;
return V_39 ;
}
int F_40 ( void )
{
int V_39 ;
F_27 ( & V_77 ) ;
if ( ! V_78 ) {
F_39 ( L_14 , V_80 ) ;
V_39 = - V_45 ;
} else {
V_39 = F_26 ( V_78 ) ;
}
F_28 ( & V_77 ) ;
return V_39 ;
}
static int T_4 F_41 ( void )
{
return F_42 ( & V_81 ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( & V_81 ) ;
}
