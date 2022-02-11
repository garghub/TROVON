static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 . V_6 ( V_2 ) ;
}
int F_3 ( struct V_1 * V_2 , unsigned type , unsigned * V_7 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
unsigned V_13 ;
switch ( type ) {
case V_14 :
V_13 = V_15 ;
break;
case V_16 :
V_13 = V_17 ;
break;
case V_18 :
if ( ! ( V_2 -> V_19 & V_11 -> V_20 ) )
return - V_21 ;
V_13 = V_22 ;
break;
case V_23 :
if ( ! ( V_2 -> V_19 & V_11 -> V_20 ) )
return - V_21 ;
V_13 = V_24 ;
break;
default:
return - V_21 ;
}
* V_7 &= ~ V_25 ;
* V_7 |= V_13 ;
return 0 ;
}
int F_5 ( int V_26 , unsigned * V_7 )
{
if ( V_26 < V_27 ||
V_26 > V_28 )
return - V_21 ;
* V_7 &= ~ V_29 ;
* V_7 |= V_26 ;
return 0 ;
}
int F_6 ( struct V_30 * V_2 ,
struct V_31 * V_32 ,
const T_1 * V_33 ,
unsigned int V_34 ,
T_2 * V_35 ,
unsigned int * V_36 )
{
if ( F_7 ( V_34 < 3 ) )
return - V_21 ;
if ( F_7 ( ( V_33 [ 2 ] < V_27 ) ||
( V_33 [ 2 ] > V_28 ) ) )
return - V_21 ;
* V_35 = V_33 [ 0 ] ;
* V_36 = V_33 [ 1 ] & V_37 ;
return 0 ;
}
static void T_3 F_8 ( struct V_30 * V_38 )
{
struct V_31 * V_39 = F_9 ( V_38 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_40 * V_41 ;
const T_4 * V_42 ;
T_1 V_43 ;
V_9 = F_10 ( V_38 , 0 ) ;
V_11 = V_9 -> V_12 ;
V_11 -> V_20 |= 1 ;
F_11 (node, L_1 , prop, p, hwirq) {
V_9 = F_10 ( V_38 , V_43 ) ;
if ( ! V_9 ) {
F_12 ( L_2 ,
V_43 , V_38 -> V_44 ) ;
continue;
}
V_11 = V_9 -> V_12 ;
V_11 -> V_20 |= ( 1 << ( V_43 % 32 ) ) ;
}
}
void T_3 F_13 ( struct V_31 * V_45 )
{
struct V_31 * V_46 ;
void T_5 * V_47 ;
V_46 = F_14 ( V_45 , NULL , L_3 ) ;
if ( ! V_46 )
V_46 = F_14 ( V_45 , NULL ,
L_4 ) ;
if ( ! V_46 )
return;
V_47 = F_15 ( V_46 , 0 ) ;
F_16 ( V_46 ) ;
if ( ! V_47 )
return;
F_17 ( V_48 , V_47 + V_49 ) ;
F_18 ( V_47 ) ;
}
void T_3 F_19 ( struct V_31 * V_45 )
{
struct V_31 * V_46 ;
void T_5 * V_47 ;
F_20 (np, NULL, L_5 ) {
V_47 = F_15 ( V_46 , 0 ) ;
if ( ! V_47 )
continue;
F_17 ( F_21 ( V_47 + V_50 ) &
~ ( V_51 | V_52 ) ,
V_47 + V_50 ) ;
F_18 ( V_47 ) ;
}
}
void T_3 F_22 ( const struct V_53 * V_54 )
{
struct V_31 * V_45 = F_23 ( L_6 ) ;
const struct V_53 * V_55 ;
if ( ! V_45 )
return;
V_55 = F_24 ( V_54 , V_45 ) ;
F_16 ( V_45 ) ;
if ( V_55 ) {
void (* F_25)( struct V_31 * ) = V_55 -> V_56 ;
F_25 ( V_45 ) ;
}
F_16 ( V_45 ) ;
}
struct V_30 * T_3 F_26 ( struct V_31 * V_39 ,
const struct V_57 * V_58 ,
const char * V_59 , int V_60 )
{
struct V_8 * V_9 ;
struct V_30 * V_38 ;
struct V_10 * V_11 ;
void T_5 * V_61 ;
int V_62 ;
int V_63 ;
int V_64 ;
V_62 = F_27 ( V_60 , 32 ) ;
V_61 = F_15 ( V_39 , 0 ) ;
if ( ! V_61 )
return F_28 ( - V_65 ) ;
V_11 = F_29 ( V_62 , sizeof( * V_11 ) , V_66 ) ;
if ( ! V_11 ) {
V_63 = - V_65 ;
goto V_67;
}
V_38 = F_30 ( V_39 , V_62 * 32 , V_58 , V_11 ) ;
if ( ! V_38 ) {
V_63 = - V_65 ;
goto V_68;
}
V_63 = F_31 ( V_38 , 32 , 1 , V_59 ,
V_69 ,
V_70 | V_71 |
V_72 , 0 , 0 ) ;
if ( V_63 )
goto V_73;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
V_9 = F_10 ( V_38 , V_64 * 32 ) ;
V_9 -> V_61 = V_61 ;
V_9 -> V_74 = 0 ;
V_9 -> V_75 = ~ 0 ;
V_9 -> V_76 [ 0 ] . type = V_37 ;
V_9 -> V_76 [ 0 ] . V_5 . V_77 = V_78 ;
V_9 -> V_76 [ 0 ] . V_5 . V_79 = V_80 ;
V_9 -> V_76 [ 0 ] . V_5 . V_81 = F_1 ;
V_9 -> V_12 = & V_11 [ V_64 ] ;
}
F_8 ( V_38 ) ;
return V_38 ;
V_73:
F_32 ( V_38 ) ;
V_68:
F_33 ( V_11 ) ;
V_67:
F_18 ( V_61 ) ;
return F_28 ( V_63 ) ;
}
