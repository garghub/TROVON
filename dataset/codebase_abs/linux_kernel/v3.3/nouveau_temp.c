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
V_8 -> V_28 . V_29 = 30 ;
V_8 -> V_28 . V_30 = 100 ;
if ( V_5 -> V_31 >= V_32 ) {
switch ( V_5 -> V_33 ) {
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
T_2 V_34 = F_3 ( V_3 [ 1 ] ) ;
switch ( V_3 [ 0 ] ) {
case 0x01 :
if ( ( V_34 & 0x8f ) == 0 )
V_11 -> V_20 = ( V_34 >> 9 ) & 0x7f ;
break;
case 0x04 :
if ( ( V_34 & 0xf00f ) == 0xa000 )
V_14 -> V_25 = ( V_34 & 0x0ff0 ) >> 4 ;
break;
case 0x07 :
if ( ( V_34 & 0xf00f ) == 0xa000 )
V_14 -> V_26 = ( V_34 & 0x0ff0 ) >> 4 ;
break;
case 0x08 :
if ( ( V_34 & 0xf00f ) == 0xa000 )
V_14 -> V_27 = ( V_34 & 0x0ff0 ) >> 4 ;
break;
case 0x10 :
V_11 -> V_21 = V_34 ;
break;
case 0x11 :
V_11 -> V_22 = V_34 ;
break;
case 0x12 :
V_11 -> V_23 = V_34 ;
break;
case 0x13 :
V_11 -> V_24 = V_34 ;
break;
case 0x22 :
V_8 -> V_28 . V_29 = V_34 & 0xff ;
V_8 -> V_28 . V_30 = ( V_34 & 0xff00 ) >> 8 ;
break;
case 0x26 :
V_8 -> V_28 . V_35 = V_34 ;
break;
}
V_3 += V_18 ;
}
F_4 ( V_2 ) ;
if ( V_8 -> V_28 . V_29 < 10 )
V_8 -> V_28 . V_29 = 10 ;
if ( V_8 -> V_28 . V_30 > 100 )
V_8 -> V_28 . V_30 = 100 ;
if ( V_8 -> V_28 . V_30 < V_8 -> V_28 . V_29 )
V_8 -> V_28 . V_30 = V_8 -> V_28 . V_29 ;
}
static int
F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 . V_8 ;
struct V_10 * V_11 = & V_8 -> V_12 ;
T_3 V_36 = V_11 -> V_21 / V_11 -> V_22 ;
T_3 V_37 ;
V_37 = 120 - V_36 - V_11 -> V_20 ;
V_37 = V_37 * V_11 -> V_24 /
V_11 -> V_23 ;
if ( V_5 -> V_33 >= 0x46 )
V_37 |= 0x80000000 ;
else
V_37 |= 0x10000000 ;
F_6 ( V_2 , 0x0015b0 , V_37 ) ;
F_7 ( 5 ) ;
return F_8 ( V_2 , 0x0015b4 ) & 0x1fff ;
}
int
F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 . V_8 ;
struct V_10 * V_11 = & V_8 -> V_12 ;
int V_36 = V_11 -> V_21 / V_11 -> V_22 ;
int V_38 ;
if ( V_5 -> V_31 >= V_39 ) {
V_38 = F_8 ( V_2 , 0x20008 ) ;
} else {
V_38 = F_8 ( V_2 , 0x0015b4 ) & 0x1fff ;
if ( V_38 == 0 )
V_38 = F_5 ( V_2 ) ;
}
V_38 = V_38 * V_11 -> V_23 / V_11 -> V_24 ;
V_38 = V_38 + V_36 + V_11 -> V_20 ;
return V_38 ;
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
F_11 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 ;
F_12 ( L_2 , V_46 , V_43 -> type ) ;
V_45 = F_13 ( & V_41 -> V_47 , V_43 ) ;
if ( ! V_45 )
return false ;
if ( ! V_45 -> V_48 || V_45 -> V_48 -> V_49 ( V_45 , V_43 ) ) {
F_14 ( V_45 ) ;
return false ;
}
return true ;
}
static void
F_15 ( struct V_1 * V_2 )
{
struct V_42 V_43 [] = {
{ F_16 ( L_3 , 0x2d ) } ,
{ F_16 ( L_4 , 0x2d ) } ,
{ F_16 ( L_5 , 0x2e ) } ,
{ F_16 ( L_6 , 0x2e ) } ,
{ F_16 ( L_7 , 0x4c ) } ,
{ }
} ;
F_17 ( V_2 , L_8 , V_43 ,
F_11 , F_18 ( 0 ) ) ;
}
void
F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_50 * V_51 = & V_5 -> V_52 ;
struct V_53 V_54 ;
T_1 * V_3 = NULL ;
if ( V_51 -> type == V_55 ) {
if ( F_20 ( V_2 , 'P' , & V_54 ) )
return;
if ( V_54 . V_56 == 1 )
V_3 = F_21 ( V_2 , V_54 . V_57 [ 12 ] ) ;
else if ( V_54 . V_56 == 2 )
V_3 = F_21 ( V_2 , V_54 . V_57 [ 16 ] ) ;
else
F_22 ( V_2 , L_9 , V_54 . V_56 ) ;
F_1 ( V_2 , V_3 ) ;
}
F_15 ( V_2 ) ;
}
void
F_23 ( struct V_1 * V_2 )
{
}
