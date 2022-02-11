static void
F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 . V_8 ;
struct V_10 * V_11 = & V_8 -> V_12 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
int V_16 , V_17 , V_18 , V_19 ;
if ( ! V_3 ) {
F_2 ( V_2 , L_1 ) ;
return;
}
V_11 -> V_20 = 0 ;
V_11 -> V_21 = 0 ;
V_11 -> V_22 = 1 ;
V_11 -> V_23 = 1 ;
V_11 -> V_24 = 1 ;
V_14 -> V_25 = 110 ;
V_14 -> V_26 = 100 ;
V_14 -> V_27 = 90 ;
if ( V_5 -> V_28 >= V_29 ) {
switch ( V_5 -> V_30 ) {
case 0x43 :
V_11 -> V_21 = 32060 ;
V_11 -> V_22 = 1000 ;
V_11 -> V_23 = 792 ;
V_11 -> V_24 = 1000 ;
break;
case 0x44 :
case 0x47 :
case 0x4a :
V_11 -> V_21 = 27839 ;
V_11 -> V_22 = 1000 ;
V_11 -> V_23 = 780 ;
V_11 -> V_24 = 1000 ;
break;
case 0x46 :
V_11 -> V_21 = - 24775 ;
V_11 -> V_22 = 100 ;
V_11 -> V_23 = 467 ;
V_11 -> V_24 = 10000 ;
break;
case 0x49 :
V_11 -> V_21 = - 25051 ;
V_11 -> V_22 = 100 ;
V_11 -> V_23 = 458 ;
V_11 -> V_24 = 10000 ;
break;
case 0x4b :
V_11 -> V_21 = - 24088 ;
V_11 -> V_22 = 100 ;
V_11 -> V_23 = 442 ;
V_11 -> V_24 = 10000 ;
break;
case 0x50 :
V_11 -> V_21 = - 22749 ;
V_11 -> V_22 = 100 ;
V_11 -> V_23 = 431 ;
V_11 -> V_24 = 10000 ;
break;
case 0x67 :
V_11 -> V_21 = - 26149 ;
V_11 -> V_22 = 100 ;
V_11 -> V_23 = 484 ;
V_11 -> V_24 = 10000 ;
break;
}
}
V_17 = V_3 [ 1 ] ;
V_18 = V_3 [ 2 ] ;
V_19 = V_3 [ 3 ] ;
V_3 = V_3 + V_17 ;
for ( V_16 = 0 ; V_16 < V_19 ; V_16 ++ ) {
T_2 V_31 = F_3 ( V_3 [ 1 ] ) ;
switch ( V_3 [ 0 ] ) {
case 0x01 :
if ( ( V_31 & 0x8f ) == 0 )
V_11 -> V_20 = ( V_31 >> 9 ) & 0x7f ;
break;
case 0x04 :
if ( ( V_31 & 0xf00f ) == 0xa000 )
V_14 -> V_25 = ( V_31 & 0x0ff0 ) >> 4 ;
break;
case 0x07 :
if ( ( V_31 & 0xf00f ) == 0xa000 )
V_14 -> V_26 = ( V_31 & 0x0ff0 ) >> 4 ;
break;
case 0x08 :
if ( ( V_31 & 0xf00f ) == 0xa000 )
V_14 -> V_27 = ( V_31 & 0x0ff0 ) >> 4 ;
break;
case 0x10 :
V_11 -> V_21 = V_31 ;
break;
case 0x11 :
V_11 -> V_22 = V_31 ;
break;
case 0x12 :
V_11 -> V_23 = V_31 ;
break;
case 0x13 :
V_11 -> V_24 = V_31 ;
break;
}
V_3 += V_18 ;
}
F_4 ( V_2 ) ;
}
static int
F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 . V_8 ;
struct V_10 * V_11 = & V_8 -> V_12 ;
T_3 V_32 = V_11 -> V_21 / V_11 -> V_22 ;
T_3 V_33 ;
V_33 = 120 - V_32 - V_11 -> V_20 ;
V_33 = V_33 * V_11 -> V_24 /
V_11 -> V_23 ;
if ( V_5 -> V_30 >= 0x46 )
V_33 |= 0x80000000 ;
else
V_33 |= 0x10000000 ;
F_6 ( V_2 , 0x0015b0 , V_33 ) ;
F_7 ( 5 ) ;
return F_8 ( V_2 , 0x0015b4 ) & 0x1fff ;
}
int
F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 . V_8 ;
struct V_10 * V_11 = & V_8 -> V_12 ;
int V_32 = V_11 -> V_21 / V_11 -> V_22 ;
int V_34 ;
if ( V_5 -> V_28 >= V_35 ) {
V_34 = F_8 ( V_2 , 0x20008 ) ;
} else {
V_34 = F_8 ( V_2 , 0x0015b4 ) & 0x1fff ;
if ( V_34 == 0 )
V_34 = F_5 ( V_2 ) ;
}
V_34 = V_34 * V_11 -> V_23 / V_11 -> V_24 ;
V_34 = V_34 + V_32 + V_11 -> V_20 ;
return V_34 ;
}
int
F_10 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , 0x20400 ) ;
}
void
F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 . V_8 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
if ( V_14 -> V_25 > 120 )
V_14 -> V_25 = 120 ;
else if ( V_14 -> V_25 < 80 )
V_14 -> V_25 = 80 ;
if ( V_14 -> V_26 > 110 )
V_14 -> V_26 = 110 ;
else if ( V_14 -> V_26 < 60 )
V_14 -> V_26 = 60 ;
if ( V_14 -> V_27 > 100 )
V_14 -> V_27 = 100 ;
else if ( V_14 -> V_27 < 40 )
V_14 -> V_27 = 40 ;
}
static bool
F_11 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 ;
F_12 ( L_2 , V_42 , V_39 -> type ) ;
V_41 = F_13 ( & V_37 -> V_43 , V_39 ) ;
if ( ! V_41 )
return false ;
if ( ! V_41 -> V_44 || V_41 -> V_44 -> V_45 ( V_41 , V_39 ) ) {
F_14 ( V_41 ) ;
return false ;
}
return true ;
}
static void
F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_46 * V_47 = & V_5 -> V_48 . V_47 ;
struct V_38 V_39 [] = {
{ F_16 ( L_3 , 0x2d ) } ,
{ F_16 ( L_4 , 0x2d ) } ,
{ F_16 ( L_5 , 0x2e ) } ,
{ F_16 ( L_6 , 0x2e ) } ,
{ F_16 ( L_7 , 0x4c ) } ,
{ }
} ;
int V_49 = ( V_47 -> V_50 >= 0x40 ?
V_47 -> V_51 & 0xf : 2 ) ;
F_17 ( V_2 , L_8 , V_39 ,
F_11 , V_49 ) ;
}
void
F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_52 * V_53 = & V_5 -> V_48 ;
struct V_54 V_55 ;
T_1 * V_3 = NULL ;
if ( V_53 -> type == V_56 ) {
if ( F_19 ( V_2 , 'P' , & V_55 ) )
return;
if ( V_55 . V_50 == 1 )
V_3 = F_20 ( V_53 , V_55 . V_57 [ 12 ] ) ;
else if ( V_55 . V_50 == 2 )
V_3 = F_20 ( V_53 , V_55 . V_57 [ 16 ] ) ;
else
F_21 ( V_2 , L_9 , V_55 . V_50 ) ;
F_1 ( V_2 , V_3 ) ;
}
F_15 ( V_2 ) ;
}
void
F_22 ( struct V_1 * V_2 )
{
}
