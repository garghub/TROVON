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
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_26 , unsigned int V_27 )
{
int V_17 ;
V_17 = F_13 ( V_2 , V_27 ) ;
if ( V_17 )
return V_17 ;
F_14 ( V_2 -> V_21 -> V_28 ) ;
V_2 -> V_14 = true ;
F_15 ( & V_2 -> V_29 ) ;
V_17 = F_16 ( V_2 , V_26 ) ;
if ( V_17 < 0 )
goto V_25;
V_2 -> V_30 = false ;
F_17 ( V_2 -> V_21 -> V_31 ) ;
V_17 = F_18 ( & V_2 -> V_29 , 2 * V_32 ) ;
if ( V_17 == 0 ) {
V_2 -> V_30 = true ;
F_19 ( V_2 -> V_21 -> V_31 ) ;
V_17 = - V_33 ;
} else {
V_17 = 0 ;
}
V_25:
V_2 -> V_14 = false ;
F_20 ( V_2 -> V_21 -> V_28 ) ;
F_16 ( V_2 , V_34 ) ;
return V_17 ;
}
int F_21 ( struct V_1 * V_2 ,
const struct V_35 * V_36 , unsigned int V_37 )
{
unsigned int V_38 ;
int V_17 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
V_17 = F_12 ( V_2 , V_36 [ V_38 ] . V_26 , V_36 [ V_38 ] . V_27 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
int F_22 ( struct V_39 * V_40 ,
const struct V_41 * V_42 , int * V_7 )
{
struct V_1 * V_2 = F_23 ( V_40 ) ;
unsigned int V_43 , V_44 ;
int V_17 = 0 ;
if ( F_24 ( V_40 ) )
return - V_45 ;
F_25 ( & V_40 -> V_46 ) ;
F_13 ( V_2 , V_42 -> V_47 ) ;
F_14 ( V_2 -> V_21 -> V_28 ) ;
V_2 -> V_14 = true ;
F_15 ( & V_2 -> V_29 ) ;
F_16 ( V_2 , V_48 ) ;
V_2 -> V_30 = false ;
F_17 ( V_2 -> V_21 -> V_31 ) ;
V_17 = F_26 (
& V_2 -> V_29 , V_32 ) ;
V_2 -> V_14 = false ;
F_20 ( V_2 -> V_21 -> V_28 ) ;
if ( V_17 == 0 )
V_17 = - V_33 ;
if ( V_17 < 0 )
goto V_25;
V_17 = F_9 ( V_2 , V_49 ,
F_27 ( V_42 -> V_50 . V_51 + V_42 -> V_50 . V_52 , 8 ) ,
& V_44 ) ;
V_25:
if ( ! V_2 -> V_30 ) {
F_19 ( V_2 -> V_21 -> V_31 ) ;
V_2 -> V_30 = true ;
}
F_16 ( V_2 , V_34 ) ;
F_28 ( & V_40 -> V_46 ) ;
if ( V_17 )
return V_17 ;
V_43 = V_44 >> V_42 -> V_50 . V_52 ;
V_43 &= ( 1 << V_42 -> V_50 . V_51 ) - 1 ;
* V_7 = V_43 ;
V_17 = F_29 ( V_2 , V_44 ) ;
if ( V_17 )
return V_17 ;
return V_53 ;
}
static int F_30 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_23 ( V_40 ) ;
unsigned int V_27 ;
int V_17 ;
V_17 = F_31 ( V_40 ) ;
if ( V_17 < 0 )
return V_17 ;
V_27 = F_32 ( V_40 -> V_54 ,
V_40 -> V_55 ) ;
V_17 = F_13 ( V_2 ,
V_40 -> V_56 [ V_27 ] . V_47 ) ;
if ( V_17 )
goto V_57;
F_14 ( V_2 -> V_21 -> V_28 ) ;
V_2 -> V_14 = true ;
V_17 = F_16 ( V_2 , V_58 ) ;
if ( V_17 )
goto V_59;
V_2 -> V_30 = false ;
F_17 ( V_2 -> V_21 -> V_31 ) ;
return 0 ;
V_59:
F_20 ( V_2 -> V_21 -> V_28 ) ;
V_57:
return V_17 ;
}
static int F_33 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_23 ( V_40 ) ;
F_15 ( & V_2 -> V_29 ) ;
F_18 ( & V_2 -> V_29 , V_32 ) ;
if ( ! V_2 -> V_30 ) {
F_19 ( V_2 -> V_21 -> V_31 ) ;
V_2 -> V_30 = true ;
}
F_16 ( V_2 , V_34 ) ;
V_2 -> V_14 = false ;
return F_20 ( V_2 -> V_21 -> V_28 ) ;
}
static T_2 F_34 ( int V_31 , void * V_60 )
{
struct V_61 * V_62 = V_60 ;
struct V_39 * V_40 = V_62 -> V_40 ;
struct V_1 * V_2 = F_23 ( V_40 ) ;
unsigned int V_63 ;
T_1 V_8 [ 16 ] ;
int V_17 ;
memset ( V_8 , 0x00 , 16 ) ;
V_63 = V_40 -> V_56 [ 0 ] . V_50 . V_51 +
V_40 -> V_56 [ 0 ] . V_50 . V_52 ;
V_63 = F_27 ( V_63 , 8 ) ;
switch ( V_63 ) {
case 4 :
case 2 :
case 1 :
V_17 = F_8 ( V_2 , V_49 ,
V_63 , & V_8 [ 0 ] ) ;
break;
case 3 :
V_17 = F_8 ( V_2 , V_49 ,
V_63 , & V_8 [ 1 ] ) ;
break;
}
F_35 ( V_40 , V_8 , V_62 -> V_64 ) ;
F_36 ( V_40 -> V_65 ) ;
V_2 -> V_30 = false ;
F_17 ( V_2 -> V_21 -> V_31 ) ;
return V_66 ;
}
static T_2 F_37 ( int V_31 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
F_38 ( & V_2 -> V_29 ) ;
F_19 ( V_31 ) ;
V_2 -> V_30 = true ;
F_39 ( V_2 -> V_65 , F_40 () ) ;
return V_66 ;
}
int F_41 ( struct V_39 * V_40 , struct V_68 * V_65 )
{
struct V_1 * V_2 = F_23 ( V_40 ) ;
if ( V_2 -> V_65 != V_65 )
return - V_20 ;
return 0 ;
}
static int F_42 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_23 ( V_40 ) ;
int V_17 ;
V_2 -> V_65 = F_43 ( L_1 , V_40 -> V_69 ,
V_40 -> V_70 ) ;
if ( V_2 -> V_65 == NULL ) {
V_17 = - V_71 ;
goto V_72;
}
V_2 -> V_65 -> V_73 = & V_74 ;
F_44 ( & V_2 -> V_29 ) ;
V_17 = F_45 ( V_2 -> V_21 -> V_31 ,
F_37 ,
V_75 ,
V_40 -> V_69 ,
V_2 ) ;
if ( V_17 )
goto V_76;
if ( ! V_2 -> V_30 ) {
V_2 -> V_30 = true ;
F_19 ( V_2 -> V_21 -> V_31 ) ;
}
V_2 -> V_65 -> V_77 . V_78 = & V_2 -> V_21 -> V_77 ;
F_46 ( V_2 -> V_65 , V_2 ) ;
V_17 = F_47 ( V_2 -> V_65 ) ;
if ( V_17 )
goto V_79;
V_40 -> V_65 = V_2 -> V_65 ;
return 0 ;
V_79:
F_48 ( V_2 -> V_21 -> V_31 , V_2 ) ;
V_76:
F_49 ( V_2 -> V_65 ) ;
V_72:
return V_17 ;
}
static void F_50 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_23 ( V_40 ) ;
F_51 ( V_2 -> V_65 ) ;
F_48 ( V_2 -> V_21 -> V_31 , V_2 ) ;
F_49 ( V_2 -> V_65 ) ;
}
int F_52 ( struct V_39 * V_40 )
{
int V_17 ;
V_17 = F_53 ( V_40 , & V_80 ,
& F_34 , & V_81 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_42 ( V_40 ) ;
if ( V_17 ) {
F_54 ( V_40 ) ;
return V_17 ;
}
return 0 ;
}
void F_55 ( struct V_39 * V_40 )
{
F_50 ( V_40 ) ;
F_54 ( V_40 ) ;
}
int F_56 ( struct V_1 * V_2 , struct V_39 * V_40 ,
struct V_82 * V_21 , const struct V_83 * V_18 )
{
V_2 -> V_21 = V_21 ;
V_2 -> V_18 = V_18 ;
F_57 ( V_40 , V_2 ) ;
return 0 ;
}
