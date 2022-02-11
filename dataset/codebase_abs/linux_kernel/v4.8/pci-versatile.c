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
V_16 = F_8 ( V_13 , V_15 ) ;
if ( V_16 )
goto V_25;
F_9 (win, res) {
struct V_26 * V_15 = V_24 -> V_15 ;
switch ( F_10 ( V_15 ) ) {
case V_27 :
V_16 = F_11 ( V_15 , V_22 ) ;
if ( V_16 )
F_12 ( V_13 , L_2 ,
V_16 , V_15 ) ;
break;
case V_28 :
V_18 |= ! ( V_15 -> V_29 & V_30 ) ;
F_13 ( V_15 -> V_31 >> 28 , F_14 ( V_17 ) ) ;
F_13 ( V_32 >> 28 , F_15 ( V_17 ) ) ;
V_17 ++ ;
break;
}
}
if ( V_18 )
return 0 ;
F_16 ( V_13 , L_3 ) ;
V_16 = - V_33 ;
V_25:
F_17 ( V_15 ) ;
return V_16 ;
}
static int F_18 ( struct V_34 * V_35 )
{
struct V_26 * V_15 ;
int V_36 , V_37 , V_38 = - 1 ;
T_4 V_39 ;
void T_2 * V_40 ;
struct V_5 * V_6 ;
F_19 ( V_41 ) ;
V_15 = F_20 ( V_35 , V_28 , 0 ) ;
V_42 = F_21 ( & V_35 -> V_13 , V_15 ) ;
if ( F_22 ( V_42 ) )
return F_23 ( V_42 ) ;
V_15 = F_20 ( V_35 , V_28 , 1 ) ;
V_11 [ 0 ] = F_21 ( & V_35 -> V_13 , V_15 ) ;
if ( F_22 ( V_11 [ 0 ] ) )
return F_23 ( V_11 [ 0 ] ) ;
V_15 = F_20 ( V_35 , V_28 , 2 ) ;
V_11 [ 1 ] = F_21 ( & V_35 -> V_13 , V_15 ) ;
if ( F_22 ( V_11 [ 1 ] ) )
return F_23 ( V_11 [ 1 ] ) ;
V_36 = F_6 ( & V_35 -> V_13 , & V_41 ) ;
if ( V_36 )
return V_36 ;
for ( V_37 = 0 ; V_37 < 32 ; V_37 ++ ) {
if ( ( F_24 ( V_11 [ 0 ] + ( V_37 << 11 ) + V_43 ) == V_44 ) &&
( F_24 ( V_11 [ 0 ] + ( V_37 << 11 ) + V_45 ) == V_46 ) ) {
V_38 = V_37 ;
break;
}
}
if ( V_38 == - 1 ) {
F_16 ( & V_35 -> V_13 , L_4 ) ;
return - V_47 ;
}
V_4 |= ( 1 << V_38 ) ;
F_25 ( & V_35 -> V_13 , L_5 , V_38 ) ;
F_13 ( V_38 , V_48 ) ;
V_40 = V_11 [ 1 ] + ( V_38 << 11 ) ;
V_39 = F_24 ( V_40 + V_49 ) ;
V_39 |= V_50 | V_51 | V_52 ;
F_13 ( V_39 , V_40 + V_49 ) ;
F_13 ( V_32 , V_40 + V_53 ) ;
F_13 ( V_32 , V_40 + V_54 ) ;
F_13 ( V_32 , V_40 + V_55 ) ;
F_13 ( 0 , V_11 [ 0 ] + V_56 ) ;
F_26 ( V_57 ) ;
F_26 ( V_58 | V_59 ) ;
V_6 = F_27 ( & V_35 -> V_13 , 0 , & V_60 , NULL , & V_41 ) ;
if ( ! V_6 )
return - V_61 ;
F_28 ( V_62 , V_63 ) ;
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
return 0 ;
}
