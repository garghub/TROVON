int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
unsigned int V_5 = V_2 / V_6 ;
int V_7 , V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 [] = {
{
. V_13 = V_1 -> V_14 ,
. V_15 = 8 ,
. V_16 = 2 ,
. V_17 = 1 ,
. V_18 = V_1 -> V_19 -> V_20 ,
} , {
. V_13 = V_1 -> V_14 + 2 ,
. V_15 = 8 ,
. V_16 = 2 ,
. V_17 = 1 ,
. V_18 = V_1 -> V_19 -> V_20 ,
} , {
. V_13 = V_1 -> V_14 + 4 ,
. V_15 = 8 ,
. V_16 = 2 ,
. V_17 = 1 ,
. V_18 = V_1 -> V_19 -> V_20 ,
} , {
. V_13 = V_1 -> V_14 + 6 ,
. V_15 = 8 ,
. V_16 = 2 ,
. V_18 = V_1 -> V_19 -> V_20 ,
} , {
. V_13 = V_1 -> V_14 + 8 ,
. V_15 = 8 ,
. V_16 = 2 ,
. V_18 = V_1 -> V_19 -> V_20 ,
} ,
} ;
F_2 ( & V_1 -> V_21 ) ;
F_3 ( & V_10 ) ;
if ( V_1 -> V_22 != V_5 ) {
V_1 -> V_14 [ 0 ] = F_4 ( V_23 ) ;
V_1 -> V_14 [ 1 ] = V_5 ;
F_5 ( & V_12 [ 0 ] , & V_10 ) ;
}
switch ( V_4 ) {
case 4 :
V_1 -> V_14 [ 8 ] = F_4 ( V_2 + 3 ) ;
V_1 -> V_14 [ 9 ] = ( V_3 >> 24 ) & 0xff ;
V_1 -> V_14 [ 6 ] = F_4 ( V_2 + 2 ) ;
V_1 -> V_14 [ 7 ] = ( V_3 >> 16 ) & 0xff ;
case 2 :
V_1 -> V_14 [ 4 ] = F_4 ( V_2 + 1 ) ;
V_1 -> V_14 [ 5 ] = ( V_3 >> 8 ) & 0xff ;
case 1 :
V_1 -> V_14 [ 2 ] = F_4 ( V_2 ) ;
V_1 -> V_14 [ 3 ] = V_3 & 0xff ;
break;
default:
V_7 = - V_24 ;
goto V_25;
}
V_12 [ V_4 ] . V_17 = 0 ;
for ( V_8 = 1 ; V_8 <= V_4 ; V_8 ++ )
F_5 ( & V_12 [ V_8 ] , & V_10 ) ;
V_7 = F_6 ( V_1 -> V_26 , & V_10 ) ;
if ( V_7 ) {
F_7 ( & V_1 -> V_26 -> V_27 , L_1 ,
V_2 , V_7 ) ;
} else {
V_1 -> V_22 = V_5 ;
}
V_25:
F_8 ( & V_1 -> V_21 ) ;
return V_7 ;
}
int F_9 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int * V_28 , unsigned int V_4 )
{
unsigned int V_5 = V_2 / V_6 ;
struct V_9 V_10 ;
int V_7 ;
struct V_11 V_12 [] = {
{
. V_13 = V_1 -> V_14 ,
. V_15 = 8 ,
. V_16 = 2 ,
. V_17 = 1 ,
. V_18 = V_1 -> V_19 -> V_20 ,
} , {
. V_13 = V_1 -> V_14 + 2 ,
. V_15 = 8 ,
. V_16 = 2 ,
. V_17 = 1 ,
. V_18 = V_1 -> V_19 -> V_29 ,
} , {
. V_13 = V_1 -> V_14 + 4 ,
. V_30 = V_1 -> V_31 ,
. V_15 = 8 ,
. V_16 = 2 ,
. V_17 = 1 ,
. V_18 = V_1 -> V_19 -> V_29 ,
} , {
. V_30 = V_1 -> V_31 + 2 ,
. V_15 = 8 ,
. V_16 = 2 ,
. V_18 = V_1 -> V_19 -> V_29 ,
} ,
} ;
F_2 ( & V_1 -> V_21 ) ;
F_3 ( & V_10 ) ;
if ( V_1 -> V_22 != V_5 ) {
V_1 -> V_14 [ 0 ] = F_4 ( V_23 ) ;
V_1 -> V_14 [ 1 ] = V_5 ;
F_5 ( & V_12 [ 0 ] , & V_10 ) ;
}
switch ( V_4 ) {
case 4 :
V_1 -> V_14 [ 2 ] = F_10 ( V_2 + 2 ) ;
V_1 -> V_14 [ 3 ] = 0 ;
F_5 ( & V_12 [ 1 ] , & V_10 ) ;
case 2 :
V_1 -> V_14 [ 4 ] = F_10 ( V_2 ) ;
V_1 -> V_14 [ 5 ] = 0 ;
F_5 ( & V_12 [ 2 ] , & V_10 ) ;
F_5 ( & V_12 [ 3 ] , & V_10 ) ;
break;
default:
V_7 = - V_24 ;
goto V_25;
}
V_7 = F_6 ( V_1 -> V_26 , & V_10 ) ;
if ( V_7 ) {
F_7 ( & V_1 -> V_26 -> V_27 , L_2 ,
V_2 , V_7 ) ;
goto V_25;
} else {
V_1 -> V_22 = V_5 ;
}
switch ( V_4 ) {
case 4 :
* V_28 = F_11 ( V_1 -> V_31 ) ;
break;
case 2 :
* V_28 = F_12 ( V_1 -> V_31 + 2 ) ;
break;
}
V_25:
F_8 ( & V_1 -> V_21 ) ;
return V_7 ;
}
int F_13 ( struct V_32 * V_33 ,
unsigned int V_2 , unsigned int V_34 , unsigned int * V_35 )
{
struct V_1 * V_1 = F_14 ( V_33 ) ;
if ( V_35 ) {
T_1 V_36 ;
int V_7 ;
V_7 = F_15 ( V_1 , V_2 , & V_36 ) ;
* V_35 = V_36 ;
return V_7 ;
} else {
return F_16 ( V_1 , V_2 , V_34 ) ;
}
}
int F_17 ( struct V_1 * V_1 , bool V_37 )
{
int V_7 = 0 ;
T_1 V_38 ;
if ( V_1 -> V_19 -> V_39 )
return V_1 -> V_19 -> V_39 ( V_1 , V_37 ) ;
V_7 = F_15 ( V_1 , V_1 -> V_19 -> V_40 , & V_38 ) ;
if ( V_7 )
goto V_41;
V_38 |= V_42 ;
V_38 &= ~ V_43 ;
if ( V_37 )
V_38 |= V_44 ;
else
V_38 &= ~ V_44 ;
V_7 = F_16 ( V_1 , V_1 -> V_19 -> V_40 , V_38 ) ;
V_41:
return V_7 ;
}
int F_18 ( struct V_1 * V_1 )
{
T_1 V_45 ;
int V_7 ;
int V_8 ;
V_7 = F_15 ( V_1 , V_1 -> V_19 -> V_46 , & V_45 ) ;
if ( V_7 < 0 )
return V_7 ;
V_45 &= V_1 -> V_19 -> V_47 ;
if ( V_45 == 0 )
return 0 ;
for ( V_8 = 0 ; V_8 < 16 ; ++ V_8 ) {
if ( V_45 & F_19 ( V_8 ) ) {
F_7 ( & V_1 -> V_26 -> V_27 , L_3 ,
V_1 -> V_19 -> V_48 [ V_8 ] ) ;
}
}
return - V_49 ;
}
int F_20 ( struct V_1 * V_1 )
{
int V_7 ;
V_7 = F_21 ( V_1 , V_1 -> V_19 -> V_50 ,
V_51 ) ;
if ( V_7 )
F_7 ( & V_1 -> V_26 -> V_27 , L_4 , V_7 ) ;
return V_7 ;
}
static int F_22 ( struct V_1 * V_1 )
{
int V_7 ;
V_7 = F_16 ( V_1 , V_1 -> V_19 -> V_40 ,
V_1 -> V_19 -> V_52 ) ;
if ( V_7 ) {
F_7 ( & V_1 -> V_26 -> V_27 , L_5 ,
V_7 ) ;
return V_7 ;
}
F_23 ( V_1 -> V_19 -> V_53 ) ;
return F_18 ( V_1 ) ;
}
int F_24 ( struct V_1 * V_1 )
{
int V_7 ;
V_7 = F_22 ( V_1 ) ;
if ( V_7 ) {
F_7 ( & V_1 -> V_26 -> V_27 , L_6 ) ;
F_20 ( V_1 ) ;
F_23 ( V_1 -> V_19 -> V_53 ) ;
V_7 = F_22 ( V_1 ) ;
if ( V_7 ) {
F_7 ( & V_1 -> V_26 -> V_27 , L_7 ) ;
return V_7 ;
}
}
return 0 ;
}
int F_25 ( struct V_32 * V_33 ,
const struct V_54 * V_55 , unsigned int V_56 , int * V_28 )
{
struct V_1 * V_1 = F_14 ( V_33 ) ;
unsigned int V_57 ;
int V_7 ;
F_2 ( & V_33 -> V_58 ) ;
V_7 = F_9 ( V_1 , V_55 -> V_59 , & V_57 ,
V_55 -> V_60 . V_61 / 8 ) ;
if ( V_7 )
goto V_62;
if ( V_57 & V_56 ) {
V_7 = F_18 ( V_1 ) ;
if ( V_7 )
goto V_62;
}
if ( V_55 -> V_60 . V_63 == 's' )
* V_28 = F_26 ( V_57 , V_55 -> V_60 . V_64 - 1 ) ;
else
* V_28 = V_57 & ( ( 1 << V_55 -> V_60 . V_64 ) - 1 ) ;
V_7 = V_65 ;
V_62:
F_8 ( & V_33 -> V_58 ) ;
return V_7 ;
}
int F_27 ( struct V_1 * V_1 , struct V_32 * V_33 ,
struct V_66 * V_26 , const struct V_67 * V_19 )
{
F_28 ( & V_1 -> V_21 ) ;
V_1 -> V_26 = V_26 ;
V_1 -> V_19 = V_19 ;
F_29 ( V_33 , V_1 ) ;
if ( V_19 -> V_68 ) {
V_1 -> V_22 = - 1 ;
} else {
V_1 -> V_22 = 0 ;
}
return F_17 ( V_1 , false ) ;
}
