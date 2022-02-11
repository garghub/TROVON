static void F_1 ( struct V_1 * V_2 , int * V_3 ,
int * V_4 , int * V_5 )
{
* V_3 = ( ( V_6 ) * V_3 ) * V_2 -> V_7 ;
* V_4 = ( ( V_6 ) * V_4 ) * V_2 -> V_7 ;
* V_5 = ( ( V_6 ) * V_5 ) * V_2 -> V_7 ;
}
static T_1 F_2 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
int V_3 , V_4 , V_5 , V_10 ;
T_2 V_11 , V_12 , V_13 ;
V_10 = F_3 ( V_2 , V_14 , L_1 ) ;
if ( V_10 < 0 )
return V_15 ;
if ( V_10 & V_16 ) {
F_4 ( V_2 -> V_17 , V_18 , 1 ) ;
F_5 ( V_2 -> V_17 ) ;
} else {
F_4 ( V_2 -> V_17 , V_18 , 0 ) ;
}
V_3 = F_3 ( V_2 , V_19 , L_2 ) ;
V_4 = F_3 ( V_2 , V_20 , L_3 ) ;
V_5 = F_3 ( V_2 , V_21 , L_4 ) ;
V_11 = F_3 ( V_2 , V_22 , L_5 ) ;
V_12 = ( V_11 & V_23 ) >> 1 ;
V_13 = ( V_11 & V_24 ) >> 7 ;
V_2 -> V_7 = V_25 [ V_12 ] [ V_13 ] ;
if ( V_2 -> V_7 == 0 )
return V_15 ;
F_1 ( V_2 , & V_3 , & V_4 , & V_5 ) ;
F_4 ( V_2 -> V_17 , V_26 , V_3 ) ;
F_4 ( V_2 -> V_17 , V_27 , V_4 ) ;
F_4 ( V_2 -> V_17 , V_28 , V_5 ) ;
F_5 ( V_2 -> V_17 ) ;
return V_29 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_30 ;
F_7 ( V_2 , V_31 , 0x02 , L_6 ) ;
F_7 ( V_2 , V_31 , 0x0A , L_6 ) ;
F_7 ( V_2 , V_31 , 0x04 , L_6 ) ;
F_8 ( 10 ) ;
V_30 = F_3 ( V_2 , V_32 , L_7 ) ;
if ( V_30 < 0 ) {
F_9 ( V_2 -> V_33 , L_8 ) ;
return V_30 ;
}
if ( V_30 & V_34 ) {
F_9 ( V_2 -> V_33 , L_9 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
const struct V_36 * V_37 = V_2 -> V_37 ;
T_2 V_11 = 0 ;
int V_38 ;
if ( V_2 -> V_39 == V_40 ) {
V_11 = ( V_2 -> V_12 << 1 ) | V_41 ;
} else if ( V_2 -> V_39 == V_42 ) {
V_11 = ( V_2 -> V_12 << 1 ) | V_43 ;
} else {
F_11 ( V_2 -> V_33 ,
L_10 ) ;
V_11 = ( V_2 -> V_12 << 1 ) | V_43 ;
}
V_11 |= V_2 -> V_44 -> V_45 ;
F_7 ( V_2 , V_46 , V_37 -> V_47 ,
L_11 ) ;
F_7 ( V_2 , V_48 , V_37 -> V_49 ,
L_12 ) ;
F_7 ( V_2 , V_50 , V_37 -> V_51 ,
L_13 ) ;
V_38 = F_7 ( V_2 , V_22 , V_11 , L_14 ) ;
if ( V_38 < 0 )
return - V_35 ;
F_12 ( V_52 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = F_7 ( V_2 , V_22 , V_53 , L_14 ) ;
F_12 ( V_52 ) ;
return V_38 ;
}
static int F_14 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = F_15 ( V_17 ) ;
F_16 ( & V_2 -> V_54 ) ;
if ( ! V_2 -> V_55 )
F_10 ( V_2 ) ;
V_2 -> V_56 = true ;
F_17 ( & V_2 -> V_54 ) ;
return 0 ;
}
static void F_18 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = F_15 ( V_17 ) ;
F_16 ( & V_2 -> V_54 ) ;
if ( ! V_2 -> V_55 )
F_13 ( V_2 ) ;
V_2 -> V_56 = false ;
F_17 ( & V_2 -> V_54 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_54 ) ;
if ( ! V_2 -> V_55 && V_2 -> V_56 )
F_13 ( V_2 ) ;
V_2 -> V_55 = true ;
F_17 ( & V_2 -> V_54 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_55 && V_2 -> V_56 )
F_10 ( V_2 ) ;
V_2 -> V_55 = false ;
F_17 ( & V_2 -> V_54 ) ;
}
struct V_1 * F_21 ( struct V_57 * V_33 , int V_8 ,
const struct V_58 * V_59 )
{
const struct V_36 * V_37 = F_22 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_17 * V_17 ;
int V_60 ;
int error ;
if ( ! V_37 ) {
F_9 ( V_33 , L_15 ) ;
error = - V_61 ;
goto V_62;
}
if ( V_8 == 0 ) {
error = - V_61 ;
goto V_62;
}
V_2 = F_23 ( sizeof( struct V_1 ) , V_63 ) ;
V_17 = F_24 () ;
if ( ! V_2 || ! V_17 ) {
error = - V_64 ;
goto V_65;
}
V_2 -> V_33 = V_33 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_44 = V_59 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_8 = V_8 ;
F_25 ( & V_2 -> V_54 ) ;
V_2 -> V_12 = V_37 -> V_12 ;
if ( V_2 -> V_12 > V_53 ) {
V_2 -> V_12 = V_66 ;
F_26 ( V_33 ,
L_16 ) ;
}
V_2 -> V_39 = V_37 -> V_39 ;
if ( V_2 -> V_39 != V_40 && V_2 -> V_39 != V_42 ) {
F_11 ( V_33 ,
L_10 ) ;
V_2 -> V_39 = V_42 ;
}
V_17 -> V_67 = L_17 ;
V_17 -> V_68 . V_69 = V_59 -> V_69 ;
V_17 -> V_70 = F_14 ;
V_17 -> V_71 = F_18 ;
F_27 ( V_72 , V_17 -> V_73 ) ;
F_28 ( V_17 , V_26 ,
- V_2 -> V_39 , V_2 -> V_39 , V_37 -> V_74 , 0 ) ;
F_28 ( V_17 , V_27 ,
- V_2 -> V_39 , V_2 -> V_39 , V_37 -> V_75 , 0 ) ;
F_28 ( V_17 , V_28 ,
- V_2 -> V_39 , V_2 -> V_39 , V_37 -> V_76 , 0 ) ;
F_28 ( V_17 , V_18 , 0 , 1 , 0 , 0 ) ;
F_29 ( V_17 , V_2 ) ;
error = F_6 ( V_2 ) ;
if ( error )
goto V_65;
V_60 = F_3 ( V_2 , V_77 , L_18 ) ;
if ( V_60 < 0 ) {
error = V_60 ;
goto V_65;
}
F_30 ( L_19 , V_60 ) ;
error = F_31 ( V_8 , NULL , F_2 ,
V_37 -> V_78 | V_79 ,
L_20 , V_2 ) ;
if ( error ) {
F_9 ( V_33 , L_21 ) ;
goto V_65;
}
error = F_32 ( V_2 -> V_17 ) ;
if ( error ) {
F_9 ( V_33 , L_22 ) ;
goto V_80;
}
return V_2 ;
V_80:
F_33 ( V_8 , V_2 ) ;
V_65:
F_34 ( V_17 ) ;
F_35 ( V_2 ) ;
V_62:
return F_36 ( error ) ;
}
void F_37 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_8 , V_2 ) ;
F_38 ( V_2 -> V_17 ) ;
F_35 ( V_2 ) ;
}
