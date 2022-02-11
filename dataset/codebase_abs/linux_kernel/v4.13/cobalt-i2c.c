static struct V_1 T_1 *
V_1 ( struct V_2 * V_2 , unsigned V_3 )
{
switch ( V_3 ) {
case 0 :
default:
return (struct V_1 T_1 * )
( V_2 -> V_4 + V_5 ) ;
case 1 :
return (struct V_1 T_1 * )
( V_2 -> V_4 + V_6 ) ;
case 2 :
return (struct V_1 T_1 * )
( V_2 -> V_4 + V_7 ) ;
case 3 :
return (struct V_1 T_1 * )
( V_2 -> V_4 + V_8 ) ;
case 4 :
return (struct V_1 T_1 * )
( V_2 -> V_4 + V_9 ) ;
}
}
static int F_1 ( struct V_1 T_1 * V_10 ,
struct V_11 * V_12 , bool V_13 , bool V_14 ,
T_2 * V_15 , T_3 V_16 )
{
unsigned long V_17 ;
int V_18 ;
int V_19 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_16 ; V_20 ++ ) {
F_2 ( V_15 [ V_20 ] , & V_10 -> V_21 ) ;
if ( V_20 == 0 && V_13 != 0 ) {
V_19 = V_22 |
V_23 ;
} else if ( V_20 == V_16 - 1 && V_14 != 0 ) {
V_19 = V_22 |
V_24 ;
} else {
V_19 = V_22 ;
}
F_2 ( V_19 , & V_10 -> V_25 ) ;
V_17 = V_26 ;
V_18 = F_3 ( & V_10 -> V_25 ) ;
while ( V_18 & V_27 ) {
if ( F_4 ( V_26 , V_17 + V_12 -> V_28 ) )
return - V_29 ;
F_5 () ;
V_18 = F_3 ( & V_10 -> V_25 ) ;
}
if ( V_18 & V_30 ) {
return - V_31 ;
}
if ( V_18 & V_32 ) {
return - V_31 ;
}
}
return 0 ;
}
static int F_6 ( struct V_1 T_1 * V_10 ,
struct V_11 * V_12 , bool V_13 , bool V_14 ,
T_2 * V_15 , T_3 V_16 )
{
unsigned long V_17 ;
int V_18 ;
int V_19 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_16 ; V_20 ++ ) {
if ( V_20 == 0 && V_13 != 0 ) {
V_19 = V_33 |
V_23 ;
} else if ( V_20 == V_16 - 1 && V_14 != 0 ) {
V_19 = V_33 |
V_24 ;
} else {
V_19 = V_33 ;
}
if ( V_20 == V_16 - 1 )
V_19 |= V_34 ;
F_2 ( V_19 , & V_10 -> V_25 ) ;
V_17 = V_26 ;
V_18 = F_3 ( & V_10 -> V_25 ) ;
while ( V_18 & V_27 ) {
if ( F_4 ( V_26 , V_17 + V_12 -> V_28 ) )
return - V_29 ;
F_5 () ;
V_18 = F_3 ( & V_10 -> V_25 ) ;
}
if ( V_18 & V_32 ) {
return - V_31 ;
}
V_15 [ V_20 ] = F_3 ( & V_10 -> V_21 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 T_1 * V_10 ,
struct V_11 * V_12 )
{
T_2 V_15 = 0 ;
return F_1 ( V_10 , V_12 , true , true , & V_15 , 1 ) ;
}
static int F_8 ( struct V_11 * V_12 ,
struct V_35 V_36 [] , int V_37 )
{
struct V_38 * V_15 = V_12 -> V_39 ;
struct V_1 T_1 * V_10 = V_15 -> V_10 ;
struct V_35 * V_40 ;
unsigned short V_41 ;
int V_42 = 0 ;
int V_20 , V_43 ;
for ( V_20 = 0 ; V_20 < V_37 ; V_20 ++ ) {
int V_14 = ( V_20 == V_37 - 1 ) ;
V_40 = & V_36 [ V_20 ] ;
V_41 = V_40 -> V_41 ;
if ( ! ( V_40 -> V_41 & V_44 ) ) {
T_2 V_45 = V_40 -> V_45 << 1 ;
if ( V_41 & V_46 )
V_45 |= 1 ;
if ( V_41 & V_47 )
V_45 ^= 1 ;
for ( V_43 = 0 ; V_43 < V_12 -> V_48 ; V_43 ++ ) {
V_42 = F_1 ( V_10 , V_12 , true , false ,
& V_45 , 1 ) ;
if ( ! V_42 )
break;
F_7 ( V_10 , V_12 ) ;
}
if ( V_42 < 0 )
return V_42 ;
V_42 = 0 ;
}
if ( V_40 -> V_41 & V_46 ) {
V_42 = F_6 ( V_10 , V_12 , false , V_14 ,
V_40 -> V_49 , V_40 -> V_16 ) ;
if ( V_42 < 0 )
goto V_50;
} else {
V_42 = F_1 ( V_10 , V_12 , false , V_14 ,
V_40 -> V_49 , V_40 -> V_16 ) ;
if ( V_42 < 0 )
goto V_50;
}
}
V_42 = V_20 ;
V_50:
if ( V_42 < 0 )
F_7 ( V_10 , V_12 ) ;
return V_42 ;
}
static T_4 F_9 ( struct V_11 * V_12 )
{
return V_51 | V_52 ;
}
int F_10 ( struct V_2 * V_2 )
{
int V_20 , V_53 ;
int V_18 ;
int V_54 ;
unsigned long V_17 ;
F_11 ( 1 , L_1 ) ;
V_54 = ( ( V_55 ) / ( 5 * V_56 ) ) - 1 ;
for ( V_20 = 0 ; V_20 < V_57 ; V_20 ++ ) {
struct V_1 T_1 * V_10 =
V_1 ( V_2 , V_20 ) ;
struct V_11 * V_12 = & V_2 -> V_58 [ V_20 ] ;
F_2 ( V_59 , & V_10 -> V_25 ) ;
F_2 ( 0 , & V_10 -> V_60 ) ;
F_2 ( 0 , & V_10 -> V_25 ) ;
V_17 = V_26 ;
do {
if ( F_4 ( V_26 , V_17 + V_61 ) ) {
if ( V_62 ) {
V_12 -> V_63 . V_64 = NULL ;
return 0 ;
}
return - V_29 ;
}
V_18 = F_3 ( & V_10 -> V_25 ) ;
} while ( V_18 & V_27 );
F_2 ( 0 , & V_10 -> V_60 ) ;
F_2 ( 0 , & V_10 -> V_25 ) ;
F_2 ( V_54 & 0xff , & V_10 -> V_65 ) ;
F_2 ( ( V_54 >> 8 ) & 0xff , & V_10 -> V_66 ) ;
F_2 ( V_59 , & V_10 -> V_60 ) ;
V_2 -> V_67 [ V_20 ] . V_2 = V_2 ;
V_2 -> V_67 [ V_20 ] . V_10 = V_10 ;
* V_12 = V_68 ;
V_12 -> V_69 = & V_70 ;
V_12 -> V_39 = & V_2 -> V_67 [ V_20 ] ;
V_12 -> V_48 = 3 ;
sprintf ( V_12 -> V_71 + strlen ( V_12 -> V_71 ) ,
L_2 , V_2 -> V_72 , V_20 ) ;
F_12 ( V_12 , & V_2 -> V_73 ) ;
V_12 -> V_63 . V_64 = & V_2 -> V_74 -> V_63 ;
V_53 = F_13 ( V_12 ) ;
if ( V_53 ) {
if ( V_62 ) {
V_12 -> V_63 . V_64 = NULL ;
return 0 ;
}
while ( V_20 -- )
F_14 ( & V_2 -> V_58 [ V_20 ] ) ;
return V_53 ;
}
F_15 ( L_3 , V_12 -> V_71 ) ;
}
return 0 ;
}
void F_16 ( struct V_2 * V_2 )
{
int V_20 ;
F_11 ( 1 , L_4 ) ;
for ( V_20 = 0 ; V_20 < V_57 ; V_20 ++ ) {
F_17 ( L_5 , V_2 -> V_58 [ V_20 ] . V_71 ) ;
F_14 ( & V_2 -> V_58 [ V_20 ] ) ;
}
}
