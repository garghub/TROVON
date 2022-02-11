void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_3 = V_3 & V_4 ;
}
int F_2 ( struct V_1 * V_2 , unsigned int V_5 ,
unsigned int V_6 , unsigned int V_7 )
{
T_1 * V_8 = V_2 -> V_8 ;
struct V_9 V_10 = {
. V_11 = V_8 ,
. V_12 = V_6 + 1 ,
. V_13 = V_2 -> V_14 ,
} ;
struct V_15 V_16 ;
int V_17 ;
V_8 [ 0 ] = ( V_5 << V_2 -> V_18 -> V_19 ) | V_2 -> V_3 ;
switch ( V_6 ) {
case 3 :
V_8 [ 1 ] = V_7 >> 16 ;
V_8 [ 2 ] = V_7 >> 8 ;
V_8 [ 3 ] = V_7 ;
break;
case 2 :
F_3 ( V_7 , & V_8 [ 1 ] ) ;
break;
case 1 :
V_8 [ 1 ] = V_7 ;
break;
case 0 :
break;
default:
return - V_20 ;
}
F_4 ( & V_16 ) ;
F_5 ( & V_10 , & V_16 ) ;
if ( V_2 -> V_14 )
V_17 = F_6 ( V_2 -> V_21 , & V_16 ) ;
else
V_17 = F_7 ( V_2 -> V_21 , & V_16 ) ;
return V_17 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_6 , T_1 * V_7 )
{
T_1 * V_8 = V_2 -> V_8 ;
int V_17 ;
struct V_9 V_10 [] = {
{
. V_11 = V_8 ,
. V_12 = 1 ,
} , {
. V_22 = V_7 ,
. V_12 = V_6 ,
. V_13 = V_2 -> V_14 ,
} ,
} ;
struct V_15 V_16 ;
F_4 ( & V_16 ) ;
if ( V_2 -> V_18 -> V_23 ) {
V_8 [ 0 ] = V_5 << V_2 -> V_18 -> V_19 ;
V_8 [ 0 ] |= V_2 -> V_18 -> V_24 ;
F_5 ( & V_10 [ 0 ] , & V_16 ) ;
}
F_5 ( & V_10 [ 1 ] , & V_16 ) ;
if ( V_2 -> V_14 )
V_17 = F_6 ( V_2 -> V_21 , & V_16 ) ;
else
V_17 = F_7 ( V_2 -> V_21 , & V_16 ) ;
return V_17 ;
}
int F_9 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_6 , unsigned int * V_7 )
{
int V_17 ;
V_17 = F_8 ( V_2 , V_5 , V_6 , V_2 -> V_8 ) ;
if ( V_17 < 0 )
goto V_25;
switch ( V_6 ) {
case 4 :
* V_7 = F_10 ( V_2 -> V_8 ) ;
break;
case 3 :
* V_7 = ( V_2 -> V_8 [ 0 ] << 16 ) |
( V_2 -> V_8 [ 1 ] << 8 ) |
V_2 -> V_8 [ 2 ] ;
break;
case 2 :
* V_7 = F_11 ( V_2 -> V_8 ) ;
break;
case 1 :
* V_7 = V_2 -> V_8 [ 0 ] ;
break;
default:
V_17 = - V_20 ;
break;
}
V_25:
return V_17 ;
}
int F_12 ( struct V_1 * V_2 ,
unsigned int V_26 )
{
T_1 * V_27 ;
unsigned int V_6 ;
int V_17 ;
V_6 = F_13 ( V_26 , 8 ) ;
V_27 = F_14 ( V_6 , sizeof( * V_27 ) , V_28 ) ;
if ( ! V_27 )
return - V_29 ;
memset ( V_27 , 0xff , V_6 ) ;
V_17 = F_15 ( V_2 -> V_21 , V_27 , V_6 ) ;
F_16 ( V_27 ) ;
return V_17 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_30 , unsigned int V_31 )
{
int V_17 ;
V_17 = F_18 ( V_2 , V_31 ) ;
if ( V_17 )
return V_17 ;
F_19 ( V_2 -> V_21 -> V_32 ) ;
V_2 -> V_14 = true ;
F_20 ( & V_2 -> V_33 ) ;
V_17 = F_21 ( V_2 , V_30 ) ;
if ( V_17 < 0 )
goto V_25;
V_2 -> V_34 = false ;
F_22 ( V_2 -> V_21 -> V_35 ) ;
V_17 = F_23 ( & V_2 -> V_33 , 2 * V_36 ) ;
if ( V_17 == 0 ) {
V_2 -> V_34 = true ;
F_24 ( V_2 -> V_21 -> V_35 ) ;
V_17 = - V_37 ;
} else {
V_17 = 0 ;
}
V_25:
V_2 -> V_14 = false ;
F_25 ( V_2 -> V_21 -> V_32 ) ;
F_21 ( V_2 , V_38 ) ;
return V_17 ;
}
int F_26 ( struct V_1 * V_2 ,
const struct V_39 * V_40 , unsigned int V_41 )
{
unsigned int V_42 ;
int V_17 ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ ) {
V_17 = F_17 ( V_2 , V_40 [ V_42 ] . V_30 , V_40 [ V_42 ] . V_31 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
int F_27 ( struct V_43 * V_44 ,
const struct V_45 * V_46 , int * V_7 )
{
struct V_1 * V_2 = F_28 ( V_44 ) ;
unsigned int V_47 , V_48 ;
int V_17 = 0 ;
if ( F_29 ( V_44 ) )
return - V_49 ;
F_30 ( & V_44 -> V_50 ) ;
F_18 ( V_2 , V_46 -> V_51 ) ;
F_19 ( V_2 -> V_21 -> V_32 ) ;
V_2 -> V_14 = true ;
F_20 ( & V_2 -> V_33 ) ;
F_21 ( V_2 , V_52 ) ;
V_2 -> V_34 = false ;
F_22 ( V_2 -> V_21 -> V_35 ) ;
V_17 = F_31 (
& V_2 -> V_33 , V_36 ) ;
V_2 -> V_14 = false ;
F_25 ( V_2 -> V_21 -> V_32 ) ;
if ( V_17 == 0 )
V_17 = - V_37 ;
if ( V_17 < 0 )
goto V_25;
V_17 = F_9 ( V_2 , V_53 ,
F_13 ( V_46 -> V_54 . V_55 + V_46 -> V_54 . V_56 , 8 ) ,
& V_48 ) ;
V_25:
if ( ! V_2 -> V_34 ) {
F_24 ( V_2 -> V_21 -> V_35 ) ;
V_2 -> V_34 = true ;
}
F_21 ( V_2 , V_38 ) ;
F_32 ( & V_44 -> V_50 ) ;
if ( V_17 )
return V_17 ;
V_47 = V_48 >> V_46 -> V_54 . V_56 ;
V_47 &= ( 1 << V_46 -> V_54 . V_55 ) - 1 ;
* V_7 = V_47 ;
V_17 = F_33 ( V_2 , V_48 ) ;
if ( V_17 )
return V_17 ;
return V_57 ;
}
static int F_34 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_28 ( V_44 ) ;
unsigned int V_31 ;
int V_17 ;
V_17 = F_35 ( V_44 ) ;
if ( V_17 < 0 )
return V_17 ;
V_31 = F_36 ( V_44 -> V_58 ,
V_44 -> V_59 ) ;
V_17 = F_18 ( V_2 ,
V_44 -> V_60 [ V_31 ] . V_51 ) ;
if ( V_17 )
goto V_61;
F_19 ( V_2 -> V_21 -> V_32 ) ;
V_2 -> V_14 = true ;
V_17 = F_21 ( V_2 , V_62 ) ;
if ( V_17 )
goto V_63;
V_2 -> V_34 = false ;
F_22 ( V_2 -> V_21 -> V_35 ) ;
return 0 ;
V_63:
F_25 ( V_2 -> V_21 -> V_32 ) ;
V_61:
return V_17 ;
}
static int F_37 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_28 ( V_44 ) ;
F_20 ( & V_2 -> V_33 ) ;
F_23 ( & V_2 -> V_33 , V_36 ) ;
if ( ! V_2 -> V_34 ) {
F_24 ( V_2 -> V_21 -> V_35 ) ;
V_2 -> V_34 = true ;
}
F_21 ( V_2 , V_38 ) ;
V_2 -> V_14 = false ;
return F_25 ( V_2 -> V_21 -> V_32 ) ;
}
static T_2 F_38 ( int V_35 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
struct V_43 * V_44 = V_66 -> V_44 ;
struct V_1 * V_2 = F_28 ( V_44 ) ;
unsigned int V_67 ;
T_1 V_8 [ 16 ] ;
int V_17 ;
memset ( V_8 , 0x00 , 16 ) ;
V_67 = V_44 -> V_60 [ 0 ] . V_54 . V_55 +
V_44 -> V_60 [ 0 ] . V_54 . V_56 ;
V_67 = F_13 ( V_67 , 8 ) ;
switch ( V_67 ) {
case 4 :
case 2 :
case 1 :
V_17 = F_8 ( V_2 , V_53 ,
V_67 , & V_8 [ 0 ] ) ;
break;
case 3 :
V_17 = F_8 ( V_2 , V_53 ,
V_67 , & V_8 [ 1 ] ) ;
break;
}
F_39 ( V_44 , V_8 , V_66 -> V_68 ) ;
F_40 ( V_44 -> V_69 ) ;
V_2 -> V_34 = false ;
F_22 ( V_2 -> V_21 -> V_35 ) ;
return V_70 ;
}
static T_2 F_41 ( int V_35 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
F_42 ( & V_2 -> V_33 ) ;
F_24 ( V_35 ) ;
V_2 -> V_34 = true ;
F_43 ( V_2 -> V_69 ) ;
return V_70 ;
}
int F_44 ( struct V_43 * V_44 , struct V_72 * V_69 )
{
struct V_1 * V_2 = F_28 ( V_44 ) ;
if ( V_2 -> V_69 != V_69 )
return - V_20 ;
return 0 ;
}
static int F_45 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_28 ( V_44 ) ;
int V_17 ;
V_2 -> V_69 = F_46 ( L_1 , V_44 -> V_73 ,
V_44 -> V_74 ) ;
if ( V_2 -> V_69 == NULL ) {
V_17 = - V_29 ;
goto V_75;
}
V_2 -> V_69 -> V_76 = & V_77 ;
F_47 ( & V_2 -> V_33 ) ;
V_17 = F_48 ( V_2 -> V_21 -> V_35 ,
F_41 ,
V_78 ,
V_44 -> V_73 ,
V_2 ) ;
if ( V_17 )
goto V_79;
if ( ! V_2 -> V_34 ) {
V_2 -> V_34 = true ;
F_24 ( V_2 -> V_21 -> V_35 ) ;
}
V_2 -> V_69 -> V_80 . V_81 = & V_2 -> V_21 -> V_80 ;
F_49 ( V_2 -> V_69 , V_2 ) ;
V_17 = F_50 ( V_2 -> V_69 ) ;
if ( V_17 )
goto V_82;
V_44 -> V_69 = F_51 ( V_2 -> V_69 ) ;
return 0 ;
V_82:
F_52 ( V_2 -> V_21 -> V_35 , V_2 ) ;
V_79:
F_53 ( V_2 -> V_69 ) ;
V_75:
return V_17 ;
}
static void F_54 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_28 ( V_44 ) ;
F_55 ( V_2 -> V_69 ) ;
F_52 ( V_2 -> V_21 -> V_35 , V_2 ) ;
F_53 ( V_2 -> V_69 ) ;
}
int F_56 ( struct V_43 * V_44 )
{
int V_17 ;
V_17 = F_57 ( V_44 , & V_83 ,
& F_38 , & V_84 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_45 ( V_44 ) ;
if ( V_17 ) {
F_58 ( V_44 ) ;
return V_17 ;
}
return 0 ;
}
void F_59 ( struct V_43 * V_44 )
{
F_54 ( V_44 ) ;
F_58 ( V_44 ) ;
}
int F_60 ( struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_85 * V_21 , const struct V_86 * V_18 )
{
V_2 -> V_21 = V_21 ;
V_2 -> V_18 = V_18 ;
F_61 ( V_44 , V_2 ) ;
return 0 ;
}
