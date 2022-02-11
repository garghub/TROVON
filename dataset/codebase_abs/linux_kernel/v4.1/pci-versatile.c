static int T_1 F_1 ( char * V_1 )
{
int V_2 ;
int V_3 ;
while ( ( V_2 = F_2 ( & V_1 , & V_3 ) ) ) {
if ( ( V_3 < 0 ) || ( V_3 > 31 ) )
F_3 ( L_1 , V_3 ) ;
else
V_4 |= ( 1 << V_3 ) ;
}
return 1 ;
}
static void T_2 * F_4 ( struct V_5 * V_6 ,
unsigned int V_7 , int V_8 )
{
unsigned int V_9 = V_6 -> V_10 ;
if ( V_4 & ( 1 << F_5 ( V_7 ) ) )
return NULL ;
return V_11 [ 1 ] + ( ( V_9 << 16 ) | ( V_7 << 8 ) | V_8 ) ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
int V_16 , V_17 = 1 , V_18 = 0 ;
struct V_19 * V_20 = V_13 -> V_21 ;
T_3 V_22 ;
struct V_23 * V_24 ;
V_16 = F_7 ( V_20 , 0 , 0xff , V_15 , & V_22 ) ;
if ( V_16 )
return V_16 ;
F_8 (win, res) {
struct V_25 * V_26 , * V_15 = V_24 -> V_15 ;
switch ( F_9 ( V_15 ) ) {
case V_27 :
V_26 = & V_28 ;
V_16 = F_10 ( V_15 , V_22 ) ;
if ( V_16 ) {
F_11 ( V_13 , L_2 ,
V_16 , V_15 ) ;
continue;
}
break;
case V_29 :
V_26 = & V_30 ;
V_18 |= ! ( V_15 -> V_31 & V_32 ) ;
F_12 ( V_15 -> V_33 >> 28 , F_13 ( V_17 ) ) ;
F_12 ( V_34 >> 28 , F_14 ( V_17 ) ) ;
V_17 ++ ;
break;
case V_35 :
default:
continue;
}
V_16 = F_15 ( V_13 , V_26 , V_15 ) ;
if ( V_16 )
goto V_36;
}
if ( ! V_18 ) {
F_16 ( V_13 , L_3 ) ;
V_16 = - V_37 ;
goto V_36;
}
return 0 ;
V_36:
F_17 ( V_15 ) ;
return V_16 ;
}
static int F_18 ( struct V_38 * V_39 )
{
struct V_25 * V_15 ;
int V_40 , V_41 , V_42 = - 1 ;
T_4 V_43 ;
void T_2 * V_44 ;
struct V_5 * V_6 ;
F_19 ( V_45 ) ;
V_15 = F_20 ( V_39 , V_29 , 0 ) ;
V_46 = F_21 ( & V_39 -> V_13 , V_15 ) ;
if ( F_22 ( V_46 ) )
return F_23 ( V_46 ) ;
V_15 = F_20 ( V_39 , V_29 , 1 ) ;
V_11 [ 0 ] = F_21 ( & V_39 -> V_13 , V_15 ) ;
if ( F_22 ( V_11 [ 0 ] ) )
return F_23 ( V_11 [ 0 ] ) ;
V_15 = F_20 ( V_39 , V_29 , 2 ) ;
V_11 [ 1 ] = F_21 ( & V_39 -> V_13 , V_15 ) ;
if ( F_22 ( V_11 [ 1 ] ) )
return F_23 ( V_11 [ 1 ] ) ;
V_40 = F_6 ( & V_39 -> V_13 , & V_45 ) ;
if ( V_40 )
return V_40 ;
for ( V_41 = 0 ; V_41 < 32 ; V_41 ++ ) {
if ( ( F_24 ( V_11 [ 0 ] + ( V_41 << 11 ) + V_47 ) == V_48 ) &&
( F_24 ( V_11 [ 0 ] + ( V_41 << 11 ) + V_49 ) == V_50 ) ) {
V_42 = V_41 ;
break;
}
}
if ( V_42 == - 1 ) {
F_16 ( & V_39 -> V_13 , L_4 ) ;
return - V_51 ;
}
V_4 |= ( 1 << V_42 ) ;
F_25 ( & V_39 -> V_13 , L_5 , V_42 ) ;
F_12 ( V_42 , V_52 ) ;
V_44 = V_11 [ 1 ] + ( V_42 << 11 ) ;
V_43 = F_24 ( V_44 + V_53 ) ;
V_43 |= V_54 | V_55 | V_56 ;
F_12 ( V_43 , V_44 + V_53 ) ;
F_12 ( V_34 , V_44 + V_57 ) ;
F_12 ( V_34 , V_44 + V_58 ) ;
F_12 ( V_34 , V_44 + V_59 ) ;
F_12 ( 0 , V_11 [ 0 ] + V_60 ) ;
F_26 ( V_61 ) ;
F_26 ( V_62 | V_63 ) ;
V_6 = F_27 ( & V_39 -> V_13 , 0 , & V_64 , & V_65 , & V_45 ) ;
if ( ! V_6 )
return - V_66 ;
F_28 ( V_67 , V_68 ) ;
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
return 0 ;
}
