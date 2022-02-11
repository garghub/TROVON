static int F_1 ( const char * V_1 )
{
if ( strcmp ( V_1 , L_1 ) == 0 )
return V_2 ;
else if ( strcmp ( V_1 , L_2 ) == 0 )
return V_3 ;
else
return - V_4 ;
}
static void F_2 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_8 -> V_10 ;
if ( V_6 -> V_11 == V_12 ) {
V_10 -> V_13 = 1 ;
V_10 -> V_14 = 0 ;
}
}
int F_3 ( struct V_15 * V_16 , struct V_5 * V_6 ,
struct V_7 * V_8 )
{
const char * V_17 ;
int V_18 = 0 ;
T_1 V_19 ;
struct V_20 * V_21 ;
struct V_15 * V_22 ;
static int V_23 ;
struct V_24 * V_25 ;
V_17 = F_4 ( V_16 , L_3 , NULL ) ;
if ( V_17 ) {
V_8 -> V_26 . V_27 = F_5 ( V_17 ) ;
if ( ( V_8 -> V_26 . V_27 < V_28 ) ||
( V_8 -> V_26 . V_27 > V_29 ) ) {
F_6 ( L_4 ) ;
return - V_4 ;
}
} else {
F_6 ( L_4 ) ;
return - V_4 ;
}
V_17 = F_4 ( V_16 , L_5 , NULL ) ;
if ( V_17 ) {
V_8 -> V_26 . V_30 = F_5 ( V_17 ) ;
if ( ( V_8 -> V_26 . V_30 < V_28 ) ||
( V_8 -> V_26 . V_30 > V_31 ) ) {
F_6 ( L_6 ) ;
return - V_4 ;
}
} else {
F_6 ( L_6 ) ;
return - V_4 ;
}
V_18 = F_7 ( V_16 , L_7 , 0 , & V_19 ) ;
if ( V_18 ) {
F_6 ( L_8 ) ;
return - V_4 ;
}
V_6 -> V_32 = V_19 ;
V_18 = F_7 ( V_16 , L_9 , 0 , & V_19 ) ;
if ( V_18 ) {
V_18 = - V_4 ;
F_6 ( L_10 ) ;
return V_18 ;
}
V_6 -> V_33 = V_19 ;
V_18 = F_7 ( V_16 , L_11 , 0 , & V_19 ) ;
if ( V_18 ) {
V_18 = - V_4 ;
F_6 ( L_12 ) ;
return V_18 ;
}
V_6 -> V_34 = V_19 ;
V_8 -> V_26 . V_35 = V_6 -> V_34 ;
if ( F_8 ( V_16 , L_13 ) )
V_6 -> V_11 = V_12 ;
else
V_6 -> V_11 = V_36 ;
V_17 = F_4 ( V_16 , L_14 , NULL ) ;
if ( ! V_17 ) {
V_18 = - V_4 ;
F_6 ( L_15 ) ;
return V_18 ;
}
V_18 = F_1 ( V_17 ) ;
if ( V_18 < 0 )
return - V_4 ;
V_6 -> V_1 = V_18 ;
V_18 = F_7 ( V_16 , L_16 , 0 , & V_19 ) ;
if ( V_18 ) {
V_18 = - V_4 ;
F_6 ( L_17 ) ;
return V_18 ;
}
V_6 -> V_37 = V_19 ;
F_2 ( V_6 , V_8 ) ;
V_22 = F_9 ( NULL , NULL , L_18 ) ;
if ( ! V_22 )
return - V_4 ;
V_25 = F_10 ( V_22 ) ;
if ( ! V_25 ) {
F_6 ( L_19 , V_22 -> V_38 ) ;
F_11 ( V_22 ) ;
return - V_4 ;
}
F_11 ( V_22 ) ;
V_21 = F_12 ( V_25 , V_39 , 0 ) ;
V_6 -> V_40 = F_13 ( & V_25 -> V_41 , V_21 ) ;
if ( F_14 ( V_6 -> V_40 ) ) {
V_18 = F_15 ( V_6 -> V_40 ) ;
goto V_42;
}
V_22 = F_9 ( NULL , NULL , L_20 ) ;
if ( ! V_22 ) {
V_18 = - V_4 ;
goto V_42;
}
V_25 = F_10 ( V_22 ) ;
if ( ! V_25 ) {
V_18 = - V_4 ;
F_6 ( L_19 , V_22 -> V_38 ) ;
F_11 ( V_22 ) ;
goto V_42;
}
F_11 ( V_22 ) ;
V_21 = F_12 ( V_25 , V_39 , 0 ) ;
V_6 -> V_43 = F_13 ( & V_25 -> V_41 , V_21 ) ;
if ( F_14 ( V_6 -> V_43 ) ) {
V_18 = F_15 ( V_6 -> V_43 ) ;
goto V_42;
}
if ( V_23 == 0 ) {
F_16 ( V_6 -> V_43 , 0 , F_17 ( V_21 ) ) ;
V_23 = 1 ;
}
return V_18 ;
V_42:
F_18 ( & V_25 -> V_41 , V_6 -> V_40 ) ;
return V_18 ;
}
void F_19 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_44 T_2 * V_40 ;
T_3 T_2 * V_43 ;
T_3 V_45 ;
T_3 V_46 ;
T_3 V_47 ;
T_4 V_48 ;
T_3 V_49 ;
T_3 V_34 ;
T_1 V_37 ;
T_1 V_50 ;
int V_51 ;
V_40 = V_6 -> V_40 ;
V_43 = V_6 -> V_43 ;
V_47 = V_8 -> V_26 . V_47 ;
V_34 = V_6 -> V_34 ;
V_37 = V_6 -> V_37 ;
if ( V_6 -> V_1 == V_3 )
V_6 -> V_52 = 24 ;
if ( V_6 -> V_1 == V_2 )
V_6 -> V_52 = 32 ;
V_48 = ( V_47 < 4 ) ? V_47 + 9 : V_47 - 3 ;
V_45 = F_20 ( V_48 ) | V_53 | F_21 ( 0 ) ;
V_46 = V_54 | V_53 | F_21 ( 0 ) ;
for ( V_51 = 0 ; V_51 < V_6 -> V_52 ; V_51 ++ ) {
V_50 = 0x01 << V_51 ;
if ( V_6 -> V_32 & V_50 )
F_22 ( V_45 ,
& V_43 [ V_37 * 32 + V_51 ] ) ;
else
F_22 ( V_46 ,
& V_43 [ V_37 * 32 + V_51 ] ) ;
if ( V_6 -> V_33 & V_50 )
F_22 ( V_45 ,
& V_43 [ V_37 * 32 + 0x200 + V_51 ] ) ;
else
F_22 ( V_46 ,
& V_43 [ V_37 * 32 + 0x200 + V_51 ] ) ;
}
F_23 ( & V_43 [ ( V_37 * 32 ) + ( V_6 -> V_52 - 1 ) ] ,
V_55 ) ;
F_23 ( & V_43 [ ( V_37 * 32 ) + 0x200 + ( V_6 -> V_52 - 1 ) ] ,
V_55 ) ;
V_49 = F_24 ( V_37 ) ;
V_49 &= ~ V_56 ;
if ( V_6 -> V_11 == V_12 )
V_49 |= V_57 ;
else
V_49 |= V_58 ;
V_49 |= F_25 ( V_8 -> V_10 . V_14 ) |
F_26 ( V_8 -> V_10 . V_59 ) ;
if ( V_8 -> V_10 . V_13 )
V_49 |= V_60 ;
if ( V_8 -> V_10 . V_61 )
V_49 |= V_62 ;
if ( V_8 -> V_10 . V_63 )
V_49 |= V_64 ;
if ( V_8 -> V_10 . V_65 )
V_49 |= V_66 ;
if ( V_8 -> V_10 . V_67 )
V_49 |= V_68 ;
switch ( V_34 ) {
case 0 :
F_22 ( V_49 , & V_40 -> V_69 [ 0 ] ) ;
break;
case 1 :
F_22 ( V_49 , & V_40 -> V_69 [ 1 ] ) ;
break;
case 2 :
F_22 ( V_49 , & V_40 -> V_69 [ 2 ] ) ;
break;
case 3 :
F_22 ( V_49 , & V_40 -> V_69 [ 3 ] ) ;
break;
default:
F_6 ( L_21 ) ;
break;
}
}
