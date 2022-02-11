static int F_1 ( T_1 * V_1 ,
struct V_2 * V_3 ,
int T_2 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_8 , V_9 , V_10 , V_11 , V_12 ;
int T_2 * V_13 ;
T_3 V_14 [ 256 ] , V_15 , V_16 ;
if ( F_2 ( V_11 , V_4 ) )
return - V_17 ;
if ( V_11 <= 0 )
return - V_18 ;
F_3 ( V_3 ) ;
if ( F_4 ( V_1 , V_6 -> V_19 , V_3 , V_14 , V_3 -> V_20 ) ) {
F_5 ( V_21 L_1 ) ;
return - V_22 ;
}
V_15 = V_14 [ 3 ] ;
V_16 = V_15 / 8 ;
V_12 = 0 ;
V_13 = V_4 + 1 ;
for ( V_8 = 1 ; V_8 < V_16 ; V_8 ++ ) {
unsigned int V_23 = 4 + V_8 * 8 ;
if ( V_12 >= V_11 )
break;
V_9 = F_6 ( ( V_24 * ) & V_14 [ V_23 ] ) ;
V_10 = F_7 ( ( V_25 * ) & V_14 [ V_23 + 6 ] ) ;
if ( F_8 ( V_9 , V_13 ) )
return - V_17 ;
++ V_13 ;
if ( F_8 ( V_10 , V_13 ) )
return - V_17 ;
++ V_13 ;
++ V_12 ;
}
if ( F_8 ( V_12 , V_4 ) )
return - V_17 ;
return 0 ;
}
static void F_9 ( struct V_2 * V_3 ,
T_3 * V_26 , int V_27 , int V_28 ,
int V_29 )
{
F_10 ( V_3 ) ;
V_3 -> V_30 [ 0 ] = V_31 ;
V_3 -> V_30 [ 1 ] = 0x17 ;
memset ( V_26 , 0 , 12 ) ;
V_26 [ 1 ] = 0xA2 ;
if ( V_29 & 1 )
V_26 [ 1 ] ^= 0x20 ;
V_26 [ 3 ] = 8 ;
F_11 ( F_12 ( V_27 ) , ( unsigned int * ) ( & V_26 [ 4 ] ) ) ;
F_11 ( F_12 ( V_28 ) , ( unsigned int * ) ( & V_26 [ 8 ] ) ) ;
V_3 -> V_20 = 12 ;
V_3 -> V_29 |= V_32 ;
}
static int F_13 ( T_1 * V_1 , struct V_2 * V_3 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
T_3 V_26 [ 20 ] ;
V_1 -> V_33 &= ~ V_34 ;
F_14 ( V_3 , V_35 ) ;
V_3 -> V_29 |= V_36 ;
if ( F_4 ( V_1 , V_6 -> V_19 , V_3 , V_26 , V_3 -> V_20 ) )
return 1 ;
if ( V_26 [ 8 + 2 ] & 0x40 )
V_1 -> V_33 |= V_34 ;
return 0 ;
}
static int F_15 ( T_1 * V_1 , struct V_2 * V_3 ,
int T_2 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
T_3 V_26 [ 12 ] ;
int V_9 , V_10 , V_29 , V_37 = 0 ;
if ( V_6 -> V_38 > 1 ) {
V_1 -> V_39 &= ~ V_40 ;
return - V_41 ;
}
V_1 -> V_39 |= V_40 ;
if ( F_2 ( V_9 , V_4 ) ||
F_2 ( V_10 , V_4 + 1 ) ||
F_2 ( V_29 , V_4 + 2 ) ) {
V_37 = - V_17 ;
goto V_42;
}
F_13 ( V_1 , V_3 ) ;
F_9 ( V_3 , V_26 , V_9 , V_10 , V_29 ) ;
if ( F_4 ( V_1 , V_6 -> V_19 , V_3 , V_26 , V_3 -> V_20 ) )
V_37 = - V_22 ;
V_42:
if ( V_37 )
V_1 -> V_39 &= ~ V_40 ;
return V_37 ;
}
static int F_16 ( T_1 * V_1 ,
struct V_2 * V_3 ,
int T_2 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
T_3 V_43 [ 18 ] ;
int V_44 = 0x10000 ;
if ( V_1 -> V_33 & V_34 ) {
F_17 ( V_1 , V_3 ) ;
if ( F_4 ( V_1 , V_6 -> V_19 , V_3 , V_43 ,
V_3 -> V_20 ) )
return - V_22 ;
if ( V_6 -> V_45 == 2 &&
V_6 -> V_46 == 4 &&
V_6 -> V_47 == 4 )
V_44 = V_6 -> V_44 ;
} else {
T_4 * V_48 = V_1 -> V_48 ;
unsigned long V_29 ;
T_3 V_49 ;
F_18 ( V_29 ) ;
V_49 = V_48 -> V_50 -> V_51 ( V_48 ) ;
F_19 ( V_29 ) ;
V_44 = ( ( V_49 & V_52 ) == 0 ) ? 0 : 0x10000 ;
}
if ( F_8 ( V_44 , V_4 ) )
return - V_17 ;
return 0 ;
}
static int F_20 ( T_1 * V_1 , struct V_2 * V_3 ,
unsigned long V_4 , unsigned int V_53 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_54 * V_19 = V_6 -> V_19 ;
int V_55 = ( V_4 && V_53 != V_56 ) ? 1 : 0 ;
if ( V_6 -> V_38 > 1 )
return - V_41 ;
F_21 ( V_1 , V_19 , V_55 ) ;
if ( V_53 == V_56 )
F_22 ( V_1 , V_19 , 2 ) ;
return 0 ;
}
static int F_23 ( T_1 * V_1 , struct V_2 * V_3 ,
T_5 V_57 , unsigned int V_53 ,
void T_2 * V_13 )
{
switch ( V_53 ) {
case V_58 :
return 0 ;
case V_59 :
return F_1 ( V_1 , V_3 , V_13 ) ;
case V_60 :
if ( ! ( V_57 & V_61 ) )
return - V_62 ;
return F_15 ( V_1 , V_3 , ( int T_2 * ) V_13 ) ;
case V_63 :
return F_16 ( V_1 , V_3 , V_13 ) ;
default:
return - V_64 ;
}
}
int F_24 ( T_1 * V_1 , struct V_65 * V_66 ,
T_5 V_57 , unsigned int V_53 , unsigned long V_4 )
{
struct V_2 V_3 ;
void T_2 * V_13 = ( void T_2 * ) V_4 ;
int V_37 ;
F_25 ( & V_67 ) ;
if ( V_53 == V_56 || V_53 == V_68 ) {
V_37 = F_20 ( V_1 , & V_3 , V_4 , V_53 ) ;
goto V_42;
}
V_37 = F_23 ( V_1 , & V_3 , V_57 , V_53 , V_13 ) ;
if ( V_37 != - V_64 )
goto V_42;
if ( V_53 != V_69 && V_53 != V_70 )
V_37 = F_26 ( V_66 , V_57 , V_53 , V_13 ) ;
if ( V_37 == - V_64 )
V_37 = F_27 ( V_1 , V_66 , V_53 , V_4 ) ;
V_42:
F_28 ( & V_67 ) ;
return V_37 ;
}
