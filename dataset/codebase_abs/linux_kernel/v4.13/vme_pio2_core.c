static int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static int F_2 ( struct V_1 * V_2 , int V_4 )
{
T_1 V_5 ;
int V_6 ;
V_5 = V_2 -> V_7 ;
if ( ! V_4 )
V_5 |= V_8 ;
if ( V_9 )
V_5 |= V_10 ;
V_6 = F_3 ( V_2 -> V_11 , & V_5 , 1 , V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_3 = V_4 ? 1 : 0 ;
return 0 ;
}
static void F_4 ( int V_13 , int V_14 , void * V_15 )
{
int V_16 , V_17 , V_18 , V_6 ;
T_1 V_5 ;
struct V_1 * V_2 = V_15 ;
V_16 = V_14 & ~ V_19 ;
switch ( V_16 ) {
case 0 :
F_5 ( & V_2 -> V_20 -> V_21 , L_1 ) ;
break;
case 1 :
case 2 :
case 3 :
case 4 :
V_6 = F_6 ( V_2 -> V_11 , & V_5 , 1 ,
V_22 [ V_16 - 1 ] ) ;
if ( V_6 < 0 ) {
F_7 ( & V_2 -> V_20 -> V_21 ,
L_2 ) ;
return;
}
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
V_18 = ( ( V_16 - 1 ) * 8 ) + V_17 ;
if ( V_5 & V_23 [ V_18 ] )
F_8 ( & V_2 -> V_20 -> V_21 ,
L_3 ,
V_18 ) ;
}
break;
case 5 :
case 6 :
case 7 :
case 8 :
case 9 :
case 10 :
F_7 ( & V_2 -> V_20 -> V_21 ,
L_4 ) ;
break;
}
}
static int F_9 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
T_1 V_24 = 0 ;
V_6 = F_3 ( V_2 -> V_11 , & V_24 , 1 , V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 -> V_11 , & V_24 , 1 , V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_10 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int T_2 F_12 ( void )
{
if ( V_26 == 0 ) {
F_13 ( L_5 ) ;
return - V_27 ;
}
if ( V_26 > V_28 ) {
F_13 ( L_6 ,
V_28 ) ;
V_26 = V_28 ;
}
return F_14 ( & V_29 , V_26 ) ;
}
static int F_15 ( struct V_30 * V_20 )
{
if ( V_20 -> V_31 >= V_26 ) {
F_7 ( & V_20 -> V_21 ,
L_7 ) ;
return 0 ;
}
if ( V_20 -> V_31 >= V_32 ) {
F_7 ( & V_20 -> V_21 ,
L_8 ) ;
return 0 ;
}
if ( V_20 -> V_31 >= V_33 ) {
F_7 ( & V_20 -> V_21 ,
L_9 ) ;
return 0 ;
}
if ( V_20 -> V_31 >= V_34 ) {
F_7 ( & V_20 -> V_21 ,
L_10 ) ;
return 0 ;
}
if ( V_20 -> V_31 >= V_35 ) {
F_7 ( & V_20 -> V_21 , L_11 ) ;
return 0 ;
}
return 1 ;
}
static int F_16 ( struct V_30 * V_20 )
{
struct V_1 * V_2 ;
int V_6 ;
int V_17 ;
T_1 V_5 ;
int V_16 ;
V_2 = F_17 ( & V_20 -> V_21 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_38 = V_20 -> V_31 ;
V_2 -> V_39 = V_39 [ V_2 -> V_38 ] ;
V_2 -> V_40 = V_40 [ V_2 -> V_38 ] ;
V_2 -> V_41 = V_14 [ V_2 -> V_38 ] ;
V_2 -> V_7 = V_13 [ V_2 -> V_38 ] & V_42 ;
strncpy ( V_2 -> V_43 , V_43 [ V_2 -> V_38 ] , V_44 ) ;
V_2 -> V_20 = V_20 ;
for ( V_17 = 0 ; V_17 < V_44 ; V_17 ++ ) {
if ( ! isdigit ( V_2 -> V_43 [ V_17 ] ) ) {
F_7 ( & V_2 -> V_20 -> V_21 , L_12 ) ;
return - V_45 ;
}
}
if ( V_2 -> V_41 & ~ V_19 ) {
F_7 ( & V_2 -> V_20 -> V_21 ,
L_13 ) ;
return - V_45 ;
}
for ( V_17 = 1 ; V_17 < V_44 ; V_17 ++ ) {
switch ( V_2 -> V_43 [ V_17 ] ) {
case '0' :
V_2 -> V_46 [ V_17 - 1 ] . V_47 = V_48 ;
break;
case '1' :
case '2' :
case '3' :
case '4' :
V_2 -> V_46 [ V_17 - 1 ] . V_47 = V_49 ;
break;
case '5' :
V_2 -> V_46 [ V_17 - 1 ] . V_47 = V_50 ;
break;
case '6' :
case '7' :
case '8' :
case '9' :
V_2 -> V_46 [ V_17 - 1 ] . V_47 = V_51 ;
break;
}
}
V_2 -> V_11 = F_18 ( V_20 , V_52 , V_53 , V_54 ) ;
if ( ! V_2 -> V_11 ) {
F_7 ( & V_2 -> V_20 -> V_21 ,
L_14 ) ;
return - V_55 ;
}
V_6 = F_19 ( V_2 -> V_11 , 1 , V_2 -> V_40 , 0x10000 , V_52 ,
V_53 | V_56 | V_57 , V_54 ) ;
if ( V_6 ) {
F_7 ( & V_2 -> V_20 -> V_21 ,
L_15 ) ;
goto V_58;
}
V_6 = F_6 ( V_2 -> V_11 , & V_5 , 1 , V_59 ) ;
if ( V_6 < 0 ) {
F_7 ( & V_2 -> V_20 -> V_21 , L_16 ) ;
goto V_60;
}
F_20 ( & V_2 -> V_20 -> V_21 , L_17 , V_5 ) ;
V_6 = F_9 ( V_2 ) ;
if ( V_6 ) {
F_7 ( & V_2 -> V_20 -> V_21 ,
L_18 ) ;
V_6 = - V_27 ;
goto V_61;
}
V_5 = V_2 -> V_7 ;
if ( F_1 ( V_2 ) )
V_5 |= V_8 ;
if ( V_9 )
V_5 |= V_10 ;
V_6 = F_3 ( V_2 -> V_11 , & V_5 , 1 , V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 -> V_11 , & V_2 -> V_41 , 1 ,
V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
V_16 = V_2 -> V_41 | V_62 ;
V_6 = F_21 ( V_20 , V_2 -> V_7 , V_16 ,
& F_4 , V_2 ) ;
if ( V_6 < 0 ) {
F_7 ( & V_2 -> V_20 -> V_21 ,
L_19 ,
V_16 , V_2 -> V_7 ) ;
goto V_63;
}
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ ) {
V_16 = V_2 -> V_41 | V_64 [ V_17 ] ;
V_6 = F_21 ( V_20 , V_2 -> V_7 , V_16 ,
& F_4 , V_2 ) ;
if ( V_6 < 0 ) {
F_7 ( & V_2 -> V_20 -> V_21 ,
L_19 ,
V_16 , V_2 -> V_7 ) ;
goto V_65;
}
}
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ ) {
V_16 = V_2 -> V_41 | V_66 [ V_17 ] ;
V_6 = F_21 ( V_20 , V_2 -> V_7 , V_16 ,
& F_4 , V_2 ) ;
if ( V_6 < 0 ) {
F_7 ( & V_2 -> V_20 -> V_21 ,
L_19 ,
V_16 , V_2 -> V_7 ) ;
goto V_67;
}
}
V_6 = F_22 ( V_2 ) ;
if ( V_6 < 0 ) {
F_7 ( & V_2 -> V_20 -> V_21 ,
L_20 ) ;
goto V_68;
}
V_6 = F_2 ( V_2 , 0 ) ;
if ( V_6 < 0 ) {
F_7 ( & V_2 -> V_20 -> V_21 , L_21 ) ;
goto V_69;
}
F_23 ( & V_2 -> V_20 -> V_21 , V_2 ) ;
F_8 ( & V_2 -> V_20 -> V_21 ,
L_22 , V_2 -> V_43 ,
V_2 -> V_40 ) ;
return 0 ;
V_69:
F_24 ( V_2 ) ;
V_68:
V_17 = 6 ;
V_67:
while ( V_17 > 0 ) {
V_17 -- ;
V_16 = V_2 -> V_41 | V_66 [ V_17 ] ;
F_25 ( V_20 , V_2 -> V_7 , V_16 ) ;
}
V_17 = 4 ;
V_65:
while ( V_17 > 0 ) {
V_17 -- ;
V_16 = V_2 -> V_41 | V_64 [ V_17 ] ;
F_25 ( V_20 , V_2 -> V_7 , V_16 ) ;
}
V_16 = ( V_2 -> V_41 & V_19 ) | V_62 ;
F_25 ( V_20 , V_2 -> V_7 , V_16 ) ;
V_63:
F_9 ( V_2 ) ;
V_61:
V_60:
F_19 ( V_2 -> V_11 , 0 , 0 , 0 , V_70 , 0 , V_54 ) ;
V_58:
F_26 ( V_2 -> V_11 ) ;
return V_6 ;
}
static int F_27 ( struct V_30 * V_20 )
{
int V_16 ;
int V_17 ;
struct V_1 * V_2 = F_28 ( & V_20 -> V_21 ) ;
F_24 ( V_2 ) ;
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ ) {
V_16 = V_2 -> V_41 | V_66 [ V_17 ] ;
F_25 ( V_20 , V_2 -> V_7 , V_16 ) ;
}
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ ) {
V_16 = V_2 -> V_41 | V_64 [ V_17 ] ;
F_25 ( V_20 , V_2 -> V_7 , V_16 ) ;
}
V_16 = ( V_2 -> V_41 & V_19 ) | V_62 ;
F_25 ( V_20 , V_2 -> V_7 , V_16 ) ;
F_9 ( V_2 ) ;
F_19 ( V_2 -> V_11 , 0 , 0 , 0 , V_70 , 0 , V_54 ) ;
F_26 ( V_2 -> V_11 ) ;
return 0 ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_29 ) ;
}
