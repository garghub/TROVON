static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
F_2 ( V_4 L_1 , V_3 ) ;
F_3 ( V_2 , V_3 , 1 ) ;
F_4 ( V_2 ) ;
F_3 ( V_2 , V_3 , 0 ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_1 * V_10 = V_6 -> V_2 ;
T_1 V_11 = V_12 [ V_13 ] == V_14 ? 0 : 8 ;
T_2 V_15 ;
int V_16 ;
V_15 = F_6 ( V_8 -> V_17 , V_11 ) ;
if ( V_15 < 0 )
return;
F_7 ( V_8 -> V_17 , V_11 , 0 ) ;
if ( ! V_15 )
return;
F_8 ( & V_10 -> V_18 , V_4 L_2 , V_15 ) ;
for ( V_16 = 0 ; V_16 < V_10 -> V_19 ; V_16 ++ )
if ( ( 1u << V_16 ) & V_15 )
F_1 ( V_10 , V_8 -> V_20 [ V_16 ] ) ;
}
static void F_9 ( struct V_21 * V_22 )
{
struct V_7 * V_8 = F_10 ( V_22 , struct V_7 , V_23 ) ;
F_7 ( V_8 -> V_17 , 0x10 , V_8 -> V_24 ) ;
}
static void F_11 ( struct V_25 * V_26 ,
enum V_27 V_28 )
{
struct V_7 * V_8 = F_10 ( V_26 , struct V_7 , V_29 ) ;
if ( V_28 != V_30 )
V_8 -> V_24 |= 0x8000 ;
else
V_8 -> V_24 &= ~ 0x8000 ;
F_12 ( & V_8 -> V_23 ) ;
}
static int F_13 ( struct V_31 * V_17 )
{
struct V_7 * V_8 = F_14 ( V_17 ) ;
if ( V_12 [ V_32 ] != V_33 )
F_15 ( & V_8 -> V_29 ) ;
F_16 ( V_8 -> V_6 ) ;
F_17 ( V_8 -> V_6 ) ;
return 0 ;
}
static void F_18 ( struct V_31 * V_17 )
{
F_13 ( V_17 ) ;
}
static int F_19 ( struct V_31 * V_17 ,
const struct V_34 * V_35 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_1 * V_10 ;
T_1 V_11 = V_12 [ V_13 ] == V_14 ? 0 : 8 ;
int V_16 , V_36 = - V_37 ;
V_8 = & V_7 ;
V_6 = F_20 () ;
if ( ! V_6 )
goto V_38;
V_8 -> V_6 = V_6 ;
V_8 -> V_17 = V_17 ;
F_21 ( V_17 , V_8 ) ;
V_36 = F_7 ( V_17 , V_11 , 0 ) ;
if ( V_36 ) {
F_22 ( & V_17 -> V_18 , V_4 L_3 ,
V_36 ) ;
goto V_39;
}
V_6 -> V_40 = F_5 ;
V_6 -> V_41 = V_42 ;
V_6 -> V_9 = V_8 ;
V_10 = V_6 -> V_2 ;
V_10 -> V_43 = V_44 L_4 ;
V_10 -> V_45 = L_5 ;
V_10 -> V_35 . V_46 = V_47 ;
V_10 -> V_18 . V_48 = & V_17 -> V_18 ;
F_23 ( V_49 , V_10 -> V_50 ) ;
V_10 -> V_3 = V_8 -> V_20 ;
V_10 -> V_51 = sizeof( V_8 -> V_20 [ 0 ] ) ;
V_10 -> V_19 = ( V_12 [ V_52 ] != V_33 ) ? 12 : 4 ;
for ( V_16 = 0 ; V_16 < V_10 -> V_19 ; V_16 ++ )
if ( V_8 -> V_20 [ V_16 ] )
F_23 ( V_8 -> V_20 [ V_16 ] , V_10 -> V_53 ) ;
V_36 = F_24 ( V_6 ) ;
if ( V_36 )
goto V_39;
F_25 ( & V_8 -> V_23 , F_9 ) ;
if ( V_12 [ V_32 ] != V_33 ) {
V_36 = F_26 ( & V_17 -> V_18 , & V_8 -> V_29 ) ;
if ( V_36 )
goto V_54;
}
return 0 ;
V_54:
F_16 ( V_6 ) ;
V_39:
F_17 ( V_6 ) ;
V_38:
return V_36 ;
}
static T_3 const void T_4 * F_27 ( const void T_4 * V_55 )
{
T_5 V_56 ;
const unsigned char V_57 [] = L_6 ;
for ( V_56 = 0 ; V_56 < 0x10000 ; V_56 += 0x10 ) {
if ( F_28 ( V_55 + V_56 , V_57 ,
sizeof( V_57 ) - 1 ) )
return V_55 + V_56 ;
}
F_29 ( V_4 L_7 ,
V_57 ) ;
return NULL ;
}
static int T_3 F_30 ( void )
{
void T_4 * V_55 ;
const void T_4 * V_58 ;
T_1 V_59 ;
unsigned char V_60 ;
int V_61 = 0 ;
V_55 = F_31 ( 0xF0000 , 0x10000 ) ;
V_58 = F_27 ( V_55 ) ;
if ( ! V_58 ) {
F_32 ( V_55 ) ;
return - V_62 ;
}
V_58 += 8 ;
V_60 = F_33 ( V_58 + 3 ) >> 1 ;
for ( ; ( V_59 = F_33 ( V_58 ) ) & 0x7f ; V_58 += 4 ) {
unsigned char V_63 , V_64 , V_65 ;
V_63 = F_33 ( V_58 + 1 ) ;
V_65 = F_33 ( V_58 + 2 ) ;
V_64 = F_33 ( V_58 + 3 ) >> 1 ;
if ( V_64 != V_60 ) {
F_29 ( V_4 L_8
L_9 ) ;
continue;
}
switch ( V_59 ) {
case 6 :
V_59 = V_13 ;
break;
case 7 :
V_59 = V_32 ;
break;
}
if ( V_59 >= V_66 )
F_29 ( V_4 L_10 , V_59 ) ;
else if ( V_12 [ V_59 ] != V_33 )
F_34 ( V_4 L_11 , V_59 ) ;
else if ( V_63 != 1 && V_63 != 2 && V_63 != 4 ) {
F_29 ( V_4 L_12 ,
V_63 , V_59 ) ;
} else {
V_12 [ V_59 ] = (enum V_67 ) V_65 ;
++ V_61 ;
}
}
F_32 ( V_55 ) ;
if ( V_61 == 0 ) {
F_35 ( V_4 L_13 ) ;
return - V_68 ;
}
return F_36 ( & V_69 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_69 ) ;
}
