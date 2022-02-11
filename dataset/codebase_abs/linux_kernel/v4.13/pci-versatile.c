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
struct V_23 * V_24 , * V_25 ;
V_16 = F_7 ( V_20 , 0 , 0xff , V_15 , & V_22 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_8 ( V_13 , V_15 ) ;
if ( V_16 )
goto V_26;
F_9 (win, tmp, res) {
struct V_27 * V_15 = V_24 -> V_15 ;
switch ( F_10 ( V_15 ) ) {
case V_28 :
V_16 = F_11 ( V_15 , V_22 ) ;
if ( V_16 ) {
F_12 ( V_13 , L_2 ,
V_16 , V_15 ) ;
F_13 ( V_24 ) ;
}
break;
case V_29 :
V_18 |= ! ( V_15 -> V_30 & V_31 ) ;
F_14 ( V_15 -> V_32 >> 28 , F_15 ( V_17 ) ) ;
F_14 ( V_33 >> 28 , F_16 ( V_17 ) ) ;
V_17 ++ ;
break;
}
}
if ( V_18 )
return 0 ;
F_17 ( V_13 , L_3 ) ;
V_16 = - V_34 ;
V_26:
F_18 ( V_15 ) ;
return V_16 ;
}
static int F_19 ( struct V_35 * V_36 )
{
struct V_12 * V_13 = & V_36 -> V_13 ;
struct V_27 * V_15 ;
int V_37 , V_38 , V_39 = - 1 ;
T_4 V_40 ;
void T_2 * V_41 ;
struct V_5 * V_6 , * V_42 ;
struct V_43 * V_44 ;
F_20 ( V_45 ) ;
V_44 = F_21 ( V_13 , 0 ) ;
if ( ! V_44 )
return - V_46 ;
V_15 = F_22 ( V_36 , V_29 , 0 ) ;
V_47 = F_23 ( V_13 , V_15 ) ;
if ( F_24 ( V_47 ) )
return F_25 ( V_47 ) ;
V_15 = F_22 ( V_36 , V_29 , 1 ) ;
V_11 [ 0 ] = F_23 ( V_13 , V_15 ) ;
if ( F_24 ( V_11 [ 0 ] ) )
return F_25 ( V_11 [ 0 ] ) ;
V_15 = F_22 ( V_36 , V_29 , 2 ) ;
V_11 [ 1 ] = F_26 ( V_13 , V_15 ) ;
if ( F_24 ( V_11 [ 1 ] ) )
return F_25 ( V_11 [ 1 ] ) ;
V_37 = F_6 ( V_13 , & V_45 ) ;
if ( V_37 )
return V_37 ;
for ( V_38 = 0 ; V_38 < 32 ; V_38 ++ ) {
if ( ( F_27 ( V_11 [ 0 ] + ( V_38 << 11 ) + V_48 ) == V_49 ) &&
( F_27 ( V_11 [ 0 ] + ( V_38 << 11 ) + V_50 ) == V_51 ) ) {
V_39 = V_38 ;
break;
}
}
if ( V_39 == - 1 ) {
F_17 ( V_13 , L_4 ) ;
return - V_52 ;
}
V_4 |= ( 1 << V_39 ) ;
F_28 ( V_13 , L_5 , V_39 ) ;
F_14 ( V_39 , V_53 ) ;
V_41 = V_11 [ 1 ] + ( V_39 << 11 ) ;
V_40 = F_27 ( V_41 + V_54 ) ;
V_40 |= V_55 | V_56 | V_57 ;
F_14 ( V_40 , V_41 + V_54 ) ;
F_14 ( V_33 , V_41 + V_58 ) ;
F_14 ( V_33 , V_41 + V_59 ) ;
F_14 ( V_33 , V_41 + V_60 ) ;
F_14 ( 0 , V_11 [ 0 ] + V_61 ) ;
F_29 ( V_62 ) ;
F_29 ( V_63 | V_64 ) ;
F_30 ( & V_45 , & V_44 -> V_65 ) ;
V_44 -> V_13 . V_66 = V_13 ;
V_44 -> V_67 = NULL ;
V_44 -> V_9 = 0 ;
V_44 -> V_68 = & V_69 ;
V_44 -> V_70 = V_71 ;
V_44 -> V_72 = V_73 ;
V_37 = F_31 ( V_44 ) ;
if ( V_37 < 0 )
return V_37 ;
V_6 = V_44 -> V_6 ;
F_32 ( V_6 ) ;
F_33 (child, &bus->children, node)
F_34 ( V_42 ) ;
F_35 ( V_6 ) ;
return 0 ;
}
