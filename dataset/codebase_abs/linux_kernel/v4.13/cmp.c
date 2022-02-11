static T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_4 )
return V_5 + F_2 ( V_2 -> V_6 ) ;
else
return V_5 + F_3 ( V_2 -> V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
T_2 (* F_5)( struct V_1 * V_2 , T_2 V_7 ) ,
int (* F_6)( struct V_1 * V_2 , T_2 V_8 ) ,
enum V_9 V_9 )
{
T_2 V_10 , V_11 [ 2 ] ;
int V_12 ;
V_11 [ 0 ] = V_2 -> V_13 ;
for (; ; ) {
V_10 = V_11 [ 0 ] ;
V_11 [ 1 ] = F_5 ( V_2 , V_11 [ 0 ] ) ;
V_12 = F_7 (
V_2 -> V_14 . V_15 , V_16 ,
F_1 ( V_2 ) , V_11 , 8 ,
V_17 | V_2 -> V_14 . V_18 ) ;
if ( V_12 < 0 ) {
if ( V_12 == - V_19 &&
V_9 == V_20 )
V_12 = 0 ;
return V_12 ;
}
if ( V_11 [ 0 ] == V_10 )
break;
if ( F_6 ) {
V_12 = F_6 ( V_2 , V_11 [ 0 ] ) ;
if ( V_12 < 0 )
return V_12 ;
}
}
V_2 -> V_13 = V_11 [ 1 ] ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_21 * V_15 ,
enum V_22 V_3 ,
unsigned int V_6 )
{
T_2 V_23 ;
T_3 V_24 ;
int V_12 ;
V_2 -> V_3 = V_3 ;
V_12 = F_7 ( V_15 , V_25 ,
F_9 ( V_2 ) , & V_23 , 4 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_24 = F_10 ( V_23 ) ;
if ( V_6 >= ( V_24 & V_26 ) )
return - V_27 ;
V_12 = F_11 ( & V_2 -> V_14 , V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_28 = false ;
F_12 ( & V_2 -> V_29 ) ;
V_2 -> V_13 = F_13 ( 0x80000000 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_30 = ( V_24 & V_31 ) >> V_32 ;
if ( V_2 -> V_30 == V_33 )
V_2 -> V_30 += ( V_24 & V_34 ) >> V_35 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , bool * V_36 )
{
T_2 V_8 ;
int V_12 ;
V_12 = F_7 (
V_2 -> V_14 . V_15 , V_25 ,
F_1 ( V_2 ) , & V_8 , 4 , 0 ) ;
if ( V_12 >= 0 )
* V_36 = ! ! ( V_8 & F_13 ( V_37 |
V_38 ) ) ;
return V_12 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_28 ) ;
F_17 ( & V_2 -> V_29 ) ;
F_18 ( & V_2 -> V_14 ) ;
}
static T_2 F_19 ( struct V_1 * V_2 , T_2 V_39 )
{
V_39 &= ~ F_13 ( V_37 |
V_38 |
V_40 ) ;
V_39 |= F_13 ( 1 << V_41 ) ;
V_39 |= F_13 ( V_2 -> V_14 . V_42 << V_43 ) ;
return V_39 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_44 ;
for ( V_44 = 1 ; V_44 < 16 ; V_44 ++ ) {
if ( V_2 -> V_14 . V_45 < ( V_44 << 5 ) )
break;
}
if ( V_44 == 16 )
V_44 = 0 ;
return V_44 ;
}
static T_2 F_21 ( struct V_1 * V_2 , T_2 V_46 )
{
unsigned int V_47 , V_48 ;
if ( V_2 -> V_49 > V_50 ) {
V_47 = V_51 ;
V_48 = V_2 -> V_49 - V_51 ;
} else {
V_47 = V_2 -> V_49 ;
V_48 = 0 ;
}
V_46 &= ~ F_13 ( V_37 |
V_38 |
V_52 |
V_40 |
V_53 |
V_54 ) ;
V_46 |= F_13 ( 1 << V_41 ) ;
V_46 |= F_13 ( V_48 << V_55 ) ;
V_46 |= F_13 ( V_2 -> V_14 . V_42 << V_43 ) ;
V_46 |= F_13 ( V_47 << V_56 ) ;
V_46 |= F_13 ( F_20 ( V_2 ) << V_57 ) ;
return V_46 ;
}
static int F_22 ( struct V_1 * V_2 , T_2 V_8 )
{
if ( V_8 & F_13 ( V_37 |
V_38 ) ) {
F_23 ( V_2 , L_1 ) ;
return - V_58 ;
}
if ( ! ( V_8 & F_13 ( V_59 ) ) ) {
F_23 ( V_2 , L_2 ) ;
return - V_60 ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 ,
unsigned int V_61 )
{
int V_12 ;
if ( F_16 ( V_2 -> V_28 ) )
return - V_62 ;
V_2 -> V_49 = F_25 ( V_2 -> V_30 ,
F_26 ( V_2 -> V_14 . V_15 ) -> V_30 ) ;
F_27 ( & V_2 -> V_29 ) ;
V_63:
V_12 = F_28 ( & V_2 -> V_14 ,
V_61 , V_2 -> V_49 ) ;
if ( V_12 < 0 )
goto V_64;
if ( V_2 -> V_3 == V_65 )
V_12 = F_4 ( V_2 , F_21 , F_22 ,
V_66 ) ;
else
V_12 = F_4 ( V_2 , F_19 , F_22 ,
V_66 ) ;
if ( V_12 == - V_19 ) {
F_29 ( & V_2 -> V_14 ) ;
goto V_63;
}
if ( V_12 < 0 )
goto V_67;
V_2 -> V_28 = true ;
F_30 ( & V_2 -> V_29 ) ;
return 0 ;
V_67:
F_29 ( & V_2 -> V_14 ) ;
V_64:
F_30 ( & V_2 -> V_29 ) ;
return V_12 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_12 ;
F_27 ( & V_2 -> V_29 ) ;
if ( ! V_2 -> V_28 ) {
F_30 ( & V_2 -> V_29 ) ;
return 0 ;
}
V_12 = F_32 ( & V_2 -> V_14 ) ;
if ( V_12 < 0 )
goto V_68;
if ( V_2 -> V_3 == V_65 )
V_12 = F_4 ( V_2 , F_21 , F_22 ,
V_20 ) ;
else
V_12 = F_4 ( V_2 , F_19 , F_22 ,
V_20 ) ;
if ( V_12 < 0 )
goto V_67;
F_30 ( & V_2 -> V_29 ) ;
return 0 ;
V_67:
F_29 ( & V_2 -> V_14 ) ;
V_68:
V_2 -> V_28 = false ;
F_30 ( & V_2 -> V_29 ) ;
return V_12 ;
}
static T_2 F_33 ( struct V_1 * V_2 , T_2 V_8 )
{
return V_8 & ~ F_13 ( V_37 | V_38 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
int V_12 ;
F_27 ( & V_2 -> V_29 ) ;
if ( ! V_2 -> V_28 ) {
F_30 ( & V_2 -> V_29 ) ;
return;
}
V_12 = F_4 ( V_2 , F_33 , NULL , V_20 ) ;
if ( V_12 < 0 )
F_23 ( V_2 , L_3 ) ;
F_29 ( & V_2 -> V_14 ) ;
V_2 -> V_28 = false ;
F_30 ( & V_2 -> V_29 ) ;
}
