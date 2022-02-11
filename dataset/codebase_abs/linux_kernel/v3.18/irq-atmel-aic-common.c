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
* V_7 &= V_25 ;
* V_7 |= V_13 ;
return 0 ;
}
int F_5 ( int V_26 , unsigned * V_7 )
{
if ( V_26 < V_27 ||
V_26 > V_28 )
return - V_21 ;
* V_7 &= V_29 ;
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
struct V_31 * V_39 = V_38 -> V_40 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_41 * V_42 ;
const T_4 * V_43 ;
T_1 V_44 ;
V_9 = F_9 ( V_38 , 0 ) ;
V_11 = V_9 -> V_12 ;
V_11 -> V_20 |= 1 ;
F_10 (node, L_1 , prop, p, hwirq) {
V_9 = F_9 ( V_38 , V_44 ) ;
if ( ! V_9 ) {
F_11 ( L_2 ,
V_44 , V_38 -> V_45 ) ;
continue;
}
V_11 = V_9 -> V_12 ;
V_11 -> V_20 |= ( 1 << ( V_44 % 32 ) ) ;
}
}
void T_3 F_12 ( struct V_31 * V_46 )
{
struct V_31 * V_47 ;
void T_5 * V_48 ;
V_47 = F_13 ( V_46 , NULL , L_3 ) ;
if ( ! V_47 )
V_47 = F_13 ( V_46 , NULL ,
L_4 ) ;
if ( ! V_47 )
return;
V_48 = F_14 ( V_47 , 0 ) ;
F_15 ( V_47 ) ;
if ( ! V_48 )
return;
F_16 ( V_49 , V_48 + V_50 ) ;
F_17 ( V_48 ) ;
}
void T_3 F_18 ( const struct V_51 * V_52 )
{
struct V_31 * V_46 = F_19 ( L_5 ) ;
const struct V_51 * V_53 ;
if ( ! V_46 )
return;
V_53 = F_20 ( V_52 , V_46 ) ;
F_15 ( V_46 ) ;
if ( V_53 ) {
void (* F_21)( struct V_31 * ) = V_53 -> V_54 ;
F_21 ( V_46 ) ;
}
F_15 ( V_46 ) ;
}
struct V_30 * T_3 F_22 ( struct V_31 * V_39 ,
const struct V_55 * V_56 ,
const char * V_57 , int V_58 )
{
struct V_8 * V_9 ;
struct V_30 * V_38 ;
struct V_10 * V_11 ;
void T_5 * V_59 ;
int V_60 ;
int V_61 ;
int V_62 ;
V_60 = F_23 ( V_58 , 32 ) ;
V_59 = F_14 ( V_39 , 0 ) ;
if ( ! V_59 )
return F_24 ( - V_63 ) ;
V_11 = F_25 ( V_60 , sizeof( * V_11 ) , V_64 ) ;
if ( ! V_11 ) {
V_61 = - V_63 ;
goto V_65;
}
V_38 = F_26 ( V_39 , V_60 * 32 , V_56 , V_11 ) ;
if ( ! V_38 ) {
V_61 = - V_63 ;
goto V_66;
}
V_61 = F_27 ( V_38 , 32 , 1 , V_57 ,
V_67 ,
V_68 | V_69 |
V_70 , 0 , 0 ) ;
if ( V_61 )
goto V_71;
for ( V_62 = 0 ; V_62 < V_60 ; V_62 ++ ) {
V_9 = F_9 ( V_38 , V_62 * 32 ) ;
V_9 -> V_59 = V_59 ;
V_9 -> V_72 = 0 ;
V_9 -> V_73 = ~ 0 ;
V_9 -> V_74 [ 0 ] . type = V_37 ;
V_9 -> V_74 [ 0 ] . V_5 . V_75 = V_76 ;
V_9 -> V_74 [ 0 ] . V_5 . V_77 = V_78 ;
V_9 -> V_74 [ 0 ] . V_5 . V_79 = F_1 ;
V_9 -> V_12 = & V_11 [ V_62 ] ;
}
F_8 ( V_38 ) ;
return V_38 ;
V_71:
F_28 ( V_38 ) ;
V_66:
F_29 ( V_11 ) ;
V_65:
F_17 ( V_59 ) ;
return F_24 ( V_61 ) ;
}
