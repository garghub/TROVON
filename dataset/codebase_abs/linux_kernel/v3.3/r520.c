static int F_1 ( struct V_1 * V_2 )
{
unsigned V_3 ;
T_1 V_4 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_4 = F_2 ( V_6 ) ;
if ( V_4 & V_7 ) {
return 0 ;
}
F_3 ( 1 ) ;
}
return - 1 ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned V_8 , V_9 , V_4 ;
F_5 ( V_2 ) ;
if ( V_2 -> V_10 == V_11 ) {
F_6 ( 0x4128 , 0xFF ) ;
}
F_7 ( V_2 ) ;
V_9 = F_8 ( V_12 ) ;
V_4 = F_8 ( V_13 ) ;
V_8 = ( V_4 >> 2 ) & 3 ;
V_4 = ( 1 << V_8 ) |
( ( ( V_9 >> 8 ) & 0xF ) << 4 ) ;
F_9 ( 0x000D , V_4 ) ;
if ( F_1 ( V_2 ) ) {
F_10 ( V_14 L_1
L_2 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_2 -> V_15 . V_16 = 128 ;
V_2 -> V_15 . V_17 = true ;
V_4 = F_2 ( V_18 ) ;
switch ( ( V_4 & V_19 ) >> V_20 ) {
case 0 :
V_2 -> V_15 . V_16 = 32 ;
break;
case 1 :
V_2 -> V_15 . V_16 = 64 ;
break;
case 2 :
V_2 -> V_15 . V_16 = 128 ;
break;
case 3 :
V_2 -> V_15 . V_16 = 256 ;
break;
default:
V_2 -> V_15 . V_16 = 128 ;
break;
}
if ( V_4 & V_21 )
V_2 -> V_15 . V_16 *= 2 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 , & V_2 -> V_15 , 0 ) ;
V_2 -> V_15 . V_22 = 0 ;
if ( ! ( V_2 -> V_23 & V_24 ) )
F_15 ( V_2 , & V_2 -> V_15 ) ;
F_16 ( V_2 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_25 V_26 ;
F_18 ( V_2 , & V_26 ) ;
if ( F_1 ( V_2 ) )
F_19 ( V_2 -> V_27 , L_3 ) ;
F_6 ( V_28 , V_2 -> V_15 . V_29 ) ;
F_20 ( V_30 ,
F_21 ( V_2 -> V_15 . V_31 >> 16 ) |
F_22 ( V_2 -> V_15 . V_32 >> 16 ) ) ;
F_6 ( V_33 ,
F_23 ( V_2 -> V_15 . V_31 >> 16 ) ) ;
if ( V_2 -> V_23 & V_24 ) {
F_20 ( V_34 ,
F_24 ( V_2 -> V_15 . V_35 >> 16 ) |
F_25 ( V_2 -> V_15 . V_36 >> 16 ) ) ;
F_20 ( V_37 , F_26 ( V_2 -> V_15 . V_38 ) ) ;
F_20 ( V_39 ,
F_27 ( F_28 ( V_2 -> V_15 . V_38 ) ) ) ;
} else {
F_20 ( V_34 , 0xFFFFFFFF ) ;
F_20 ( V_37 , 0 ) ;
F_20 ( V_39 , 0 ) ;
}
F_29 ( V_2 , & V_26 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_40 ;
F_17 ( V_2 ) ;
F_31 ( V_2 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_23 & V_41 ) {
V_40 = F_32 ( V_2 ) ;
if ( V_40 )
return V_40 ;
}
V_40 = F_33 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_34 ( V_2 , V_42 ) ;
if ( V_40 ) {
F_35 ( V_2 -> V_27 , L_4 , V_40 ) ;
return V_40 ;
}
F_36 ( V_2 ) ;
V_2 -> V_43 . V_44 . V_45 = F_8 ( V_46 ) ;
V_40 = F_37 ( V_2 , 1024 * 1024 ) ;
if ( V_40 ) {
F_35 ( V_2 -> V_27 , L_5 , V_40 ) ;
return V_40 ;
}
V_40 = F_38 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_39 ( V_2 ) ;
if ( V_40 ) {
F_35 ( V_2 -> V_27 , L_6 , V_40 ) ;
V_2 -> V_47 = false ;
return V_40 ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_23 & V_41 )
F_41 ( V_2 ) ;
F_31 ( V_2 ) ;
if ( F_42 ( V_2 ) ) {
F_19 ( V_2 -> V_27 , L_7 ,
F_8 ( V_48 ) ,
F_8 ( V_49 ) ) ;
}
F_43 ( V_2 -> V_50 . V_51 ) ;
F_31 ( V_2 ) ;
F_44 ( V_2 ) ;
V_2 -> V_47 = true ;
V_40 = F_30 ( V_2 ) ;
if ( V_40 ) {
V_2 -> V_47 = false ;
}
return V_40 ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_40 ;
F_46 ( V_2 ) ;
F_44 ( V_2 ) ;
F_47 ( V_2 ) ;
if ( ! F_48 ( V_2 ) ) {
if ( F_49 ( V_2 ) )
return - V_52 ;
}
if ( V_2 -> V_53 ) {
V_40 = F_50 ( V_2 ) ;
if ( V_40 )
return V_40 ;
} else {
F_35 ( V_2 -> V_27 , L_8 ) ;
return - V_52 ;
}
if ( F_42 ( V_2 ) ) {
F_19 ( V_2 -> V_27 ,
L_7 ,
F_8 ( V_48 ) ,
F_8 ( V_49 ) ) ;
}
if ( F_51 ( V_2 ) == false )
return - V_52 ;
if ( ! F_52 ( V_2 ) && V_2 -> V_54 ) {
F_53 ( L_9 ) ;
F_43 ( V_2 -> V_50 . V_51 ) ;
}
F_54 ( V_2 -> V_55 ) ;
if ( V_2 -> V_23 & V_24 ) {
V_40 = F_55 ( V_2 ) ;
if ( V_40 ) {
F_56 ( V_2 ) ;
}
}
F_12 ( V_2 ) ;
F_57 ( V_2 ) ;
V_40 = F_58 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_59 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_60 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_61 ( V_2 ) ;
if ( V_40 )
return V_40 ;
F_62 ( V_2 ) ;
V_40 = F_63 ( V_2 ) ;
V_2 -> V_47 = true ;
if ( V_40 ) {
F_35 ( V_2 -> V_27 , L_10 , V_40 ) ;
V_2 -> V_47 = false ;
}
V_40 = F_30 ( V_2 ) ;
if ( V_40 ) {
F_35 ( V_2 -> V_27 , L_11 ) ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
V_2 -> V_47 = false ;
}
return 0 ;
}
