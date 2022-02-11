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
static int T_4 F_12 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = & V_29 -> V_31 ;
struct V_32 * V_33 = V_31 -> V_34 ;
void T_1 * V_1 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
unsigned V_2 ;
unsigned long V_39 ;
int V_40 = 0 ;
int V_41 , V_42 , V_43 ;
F_13 ( V_31 , L_2 ) ;
V_38 = F_14 ( sizeof( struct V_37 ) , V_44 ) ;
if ( ! V_38 ) {
F_15 ( V_31 , L_3 ) ;
V_40 = - V_45 ;
goto V_46;
}
F_16 ( & V_38 -> V_47 ) ;
for ( V_41 = 0 ; V_41 < V_48 ; V_41 ++ )
V_38 -> V_49 . V_50 [ V_41 ] = V_33 -> V_50 [ V_41 ] ;
V_38 -> V_51 = F_17 ( V_31 , L_4 ) ;
if ( F_18 ( V_38 -> V_51 ) ) {
V_40 = F_19 ( V_38 -> V_51 ) ;
F_15 ( V_31 , L_5 , V_40 ) ;
goto V_52;
}
V_38 -> V_53 = F_17 ( V_31 , L_6 ) ;
if ( F_18 ( V_38 -> V_53 ) ) {
V_40 = F_19 ( V_38 -> V_53 ) ;
F_15 ( V_31 , L_7 , V_40 ) ;
goto V_54;
}
V_36 = F_20 ( V_29 , V_55 , 0 ) ;
if ( ! V_36 ) {
F_15 ( V_31 , L_8 ) ;
V_40 = - V_56 ;
goto V_57;
}
V_1 = F_21 ( V_36 -> V_58 , F_22 ( V_36 ) ) ;
if ( ! V_1 ) {
F_15 ( V_31 , L_9 ) ;
V_40 = - V_45 ;
goto V_57;
}
F_23 ( V_29 , V_38 ) ;
F_24 ( V_31 ) ;
F_25 ( V_31 ) ;
F_26 ( & V_38 -> V_47 , V_39 ) ;
V_42 = F_3 ( V_1 , V_59 ) ;
switch ( V_42 ) {
case V_60 :
case V_61 :
V_43 = V_62 ;
break;
case V_63 :
V_43 = V_64 ;
break;
default:
F_15 ( V_31 , L_10 ) ;
V_40 = - V_56 ;
goto V_65;
}
if ( F_27 ( V_33 -> V_50 [ 0 ] ) ||
F_27 ( V_33 -> V_50 [ 1 ] ) ||
F_27 ( V_33 -> V_50 [ 2 ] ) ||
F_9 ( V_33 -> V_50 [ 0 ] ) ||
F_9 ( V_33 -> V_50 [ 1 ] ) ||
F_9 ( V_33 -> V_50 [ 2 ] ) ) {
V_2 = F_3 ( V_1 , V_66 ) ;
V_2 |= ( V_67
| V_68 ) ;
V_2 &= ~ V_69 ;
V_2 &= ~ V_70 ;
F_1 ( V_1 , V_66 , V_2 ) ;
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ ) {
V_2 = F_3 ( V_1 , F_28 ( V_41 ) ) ;
if ( F_9 ( V_33 -> V_50 [ V_41 ] ) ) {
V_2 |= F_10 ( V_33 -> V_50 [ V_41 ] )
<< V_71 ;
V_2 |= V_72 ;
} else if ( V_33 -> V_50 [ V_41 ] ==
V_73 ) {
V_2 &= ~ ( V_74
| V_75
| V_76 ) ;
} else {
continue;
}
V_2 |= V_77 ;
F_1 ( V_1 , F_28 ( V_41 ) , V_2 ) ;
F_5 ( V_1 ,
F_29 ( V_41 ) ,
0xbe ) ;
}
}
V_65:
F_30 ( & V_38 -> V_47 , V_39 ) ;
F_31 ( V_1 ) ;
F_32 ( V_31 ) ;
V_78 = V_29 ;
if ( ! V_40 )
goto V_46;
F_33 ( V_31 ) ;
V_57:
F_34 ( V_38 -> V_53 ) ;
V_54:
F_34 ( V_38 -> V_51 ) ;
V_52:
F_35 ( V_38 ) ;
V_46:
return V_40 ;
}
static int T_5 F_36 ( struct V_28 * V_29 )
{
struct V_37 * V_38 = F_37 ( V_29 ) ;
F_34 ( V_38 -> V_53 ) ;
F_34 ( V_38 -> V_51 ) ;
F_33 ( & V_29 -> V_31 ) ;
F_35 ( V_38 ) ;
return 0 ;
}
static int F_38 ( struct V_30 * V_31 )
{
struct V_37 * V_38 = F_39 ( V_31 ) ;
struct V_32 * V_33 = & V_38 -> V_49 ;
unsigned long V_39 ;
F_13 ( V_31 , L_11 ) ;
if ( ! V_33 ) {
F_13 ( V_31 , L_12 ) ;
return - V_56 ;
}
F_26 ( & V_38 -> V_47 , V_39 ) ;
if ( F_27 ( V_33 -> V_50 [ 0 ] ) )
F_40 ( V_38 -> V_51 ) ;
if ( F_27 ( V_33 -> V_50 [ 1 ] ) )
F_40 ( V_38 -> V_53 ) ;
F_30 ( & V_38 -> V_47 , V_39 ) ;
return 0 ;
}
static int F_41 ( struct V_30 * V_31 )
{
struct V_37 * V_38 = F_39 ( V_31 ) ;
struct V_32 * V_33 = & V_38 -> V_49 ;
unsigned long V_39 ;
F_13 ( V_31 , L_13 ) ;
if ( ! V_33 ) {
F_13 ( V_31 , L_12 ) ;
return - V_56 ;
}
F_26 ( & V_38 -> V_47 , V_39 ) ;
if ( F_27 ( V_33 -> V_50 [ 0 ] ) )
F_42 ( V_38 -> V_51 ) ;
if ( F_27 ( V_33 -> V_50 [ 1 ] ) )
F_42 ( V_38 -> V_53 ) ;
F_30 ( & V_38 -> V_47 , V_39 ) ;
return 0 ;
}
int F_43 ( void )
{
if ( ! V_78 ) {
F_44 ( L_14 ) ;
return - V_56 ;
}
return F_25 ( & V_78 -> V_31 ) ;
}
int F_45 ( void )
{
if ( ! V_78 ) {
F_44 ( L_14 ) ;
return - V_56 ;
}
return F_32 ( & V_78 -> V_31 ) ;
}
static int T_6 F_46 ( void )
{
return F_47 ( & V_79 ) ;
}
static void T_7 F_48 ( void )
{
F_49 ( & V_79 ) ;
}
