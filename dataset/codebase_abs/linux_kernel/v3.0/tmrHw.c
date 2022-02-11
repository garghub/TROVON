T_1 F_1 ( T_2 V_1 ,
T_3 V_2
) {
switch ( V_2 ) {
case V_3 :
return ( V_1 <=
1 ) ? V_4 :
V_5 ;
case V_6 :
return 32 ;
default:
return 0 ;
}
return 0 ;
}
static void F_2 ( T_2 V_1
) {
V_7 [ V_1 ] . V_8 = 0 ;
V_7 [ V_1 ] . V_9 = 0xFFFFFFFF ;
V_7 [ V_1 ] . V_10 = 0 ;
V_7 [ V_1 ] . V_11 = 0 ;
V_7 [ V_1 ] . V_10 |= V_12 ;
if ( V_7 [ V_1 ] . V_13 ) {
V_7 [ V_1 ] . V_14 = 0xFFFFFFFF ;
}
}
static T_4 F_3 ( T_2 V_1 ,
T_4 V_15
) {
T_1 V_16 = 0 ;
T_1 V_17 = 0 ;
if ( V_1 == 0 || V_1 == 1 ) {
if ( V_15 <= V_18 ) {
V_7 [ V_1 ] . V_10 |= V_19 ;
V_16 = V_20 ;
} else if ( V_15 <= V_21 ) {
V_7 [ V_1 ] . V_10 |= V_22 ;
V_16 = V_23 ;
} else if ( V_15 <= V_24 ) {
V_7 [ V_1 ] . V_10 |= V_25 ;
V_16 = V_26 ;
} else {
return 0 ;
}
V_17 = V_15 * V_16 ;
V_7 [ V_1 ] . V_8 = V_17 ;
V_7 [ V_1 ] . V_11 = V_17 ;
} else if ( V_1 == 2 || V_1 == 3 ) {
if ( V_15 <= V_27 ) {
V_7 [ V_1 ] . V_10 |= V_19 ;
V_16 = V_28 ;
} else if ( V_15 <= V_29 ) {
V_7 [ V_1 ] . V_10 |= V_22 ;
V_16 = V_30 ;
} else if ( V_15 <= V_31 ) {
V_7 [ V_1 ] . V_10 |= V_25 ;
V_16 = V_32 ;
} else {
return 0 ;
}
V_17 = V_15 * V_16 ;
V_7 [ V_1 ] . V_8 = V_17 ;
V_7 [ V_1 ] . V_11 = V_17 ;
}
return V_17 / V_16 ;
}
T_5 F_4 ( T_2 V_1 ,
T_5 V_33
) {
T_1 V_34 = 0 ;
T_1 V_17 = 0 ;
F_2 ( V_1 ) ;
V_7 [ V_1 ] . V_10 |= V_35 ;
V_7 [ V_1 ] . V_10 &= ~ V_36 ;
V_7 [ V_1 ] . V_10 |= V_19 ;
if ( V_33 && ( V_1 == 0 || V_1 == 1 ) ) {
if ( V_33 > V_4 ) {
return 0 ;
}
V_34 = V_4 ;
} else if ( V_33 && ( V_1 == 2 || V_1 == 3 ) ) {
if ( V_33 > V_5 ) {
return 0 ;
} else {
V_34 = V_5 ;
}
} else {
return 0 ;
}
V_17 = V_34 / V_33 ;
V_7 [ V_1 ] . V_8 = V_17 ;
V_7 [ V_1 ] . V_11 = V_17 ;
return V_34 / V_17 ;
}
T_4 F_5 ( T_2 V_1 ,
T_4 V_15
) {
F_2 ( V_1 ) ;
V_7 [ V_1 ] . V_10 |= V_35 ;
V_7 [ V_1 ] . V_10 &= ~ V_36 ;
return F_3 ( V_1 , V_15 ) ;
}
T_4 F_6 ( T_2 V_1 ,
T_4 V_15
) {
F_2 ( V_1 ) ;
V_7 [ V_1 ] . V_10 |= V_35 ;
V_7 [ V_1 ] . V_10 |= V_36 ;
return F_3 ( V_1 , V_15 ) ;
}
T_5 F_7 ( T_2 V_1 ,
T_1 V_37
) {
T_1 V_16 = 0 ;
F_2 ( V_1 ) ;
V_7 [ V_1 ] . V_10 &= ~ V_35 ;
V_7 [ V_1 ] . V_10 &= ~ V_36 ;
if ( V_37 >= 64 ) {
V_7 [ V_1 ] . V_10 |= V_25 ;
V_16 = 256 ;
} else if ( V_37 >= 8 ) {
V_7 [ V_1 ] . V_10 |= V_22 ;
V_16 = 16 ;
} else {
V_7 [ V_1 ] . V_10 |= V_19 ;
V_16 = 1 ;
}
if ( V_1 == 0 || V_1 == 1 ) {
return F_8 ( V_4 , V_16 ) ;
} else if ( V_1 == 2 || V_1 == 3 ) {
return F_8 ( V_5 , V_16 ) ;
}
return 0 ;
}
int F_9 ( T_2 V_1
) {
V_7 [ V_1 ] . V_10 |= V_38 ;
return 0 ;
}
int F_10 ( T_2 V_1
) {
V_7 [ V_1 ] . V_10 &= ~ V_38 ;
return 0 ;
}
T_1 F_11 ( T_2 V_1
) {
switch ( V_7 [ V_1 ] . V_10 & V_39 ) {
case V_40 :
if ( V_7 [ V_1 ] . V_9 ) {
return V_41 - V_7 [ V_1 ] . V_9 ;
}
break;
case V_35 :
case V_36 :
return V_7 [ V_1 ] . V_11 -
V_7 [ V_1 ] . V_9 ;
}
return 0 ;
}
T_5 F_12 ( T_2 V_1
) {
T_1 V_37 = 0 ;
switch ( V_7 [ V_1 ] . V_10 & V_42 ) {
case V_19 :
V_37 = 1 ;
break;
case V_22 :
V_37 = 16 ;
break;
case V_25 :
V_37 = 256 ;
break;
default:
F_13 ( 0 ) ;
}
if ( V_1 == 0 || V_1 == 1 ) {
return F_8 ( V_4 , V_37 ) ;
} else {
return F_8 ( V_5 , V_37 ) ;
}
return 0 ;
}
void F_14 ( T_2 V_1
) {
V_7 [ V_1 ] . V_10 |= V_43 ;
}
void F_15 ( T_2 V_1
) {
V_7 [ V_1 ] . V_10 &= ~ V_43 ;
}
void F_16 ( T_2 V_1
) {
V_7 [ V_1 ] . V_14 = 0x1 ;
}
T_6 F_17 ( T_2 V_1
) {
if ( V_7 [ V_1 ] . V_44 ) {
return V_45 ;
} else {
return V_46 ;
}
}
T_2 F_18 ( void
) {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
if ( V_7 [ V_47 ] . V_44 ) {
return V_47 ;
}
}
return 0xFFFFFFFF ;
}
void F_19 ( T_2 V_1 ,
int (* F_20) ( const char * , ... )
) {
(* F_20) ( L_1 ) ;
(* F_20) ( L_2 , V_1 ,
V_7 [ V_1 ] . V_8 ) ;
(* F_20) ( L_3 , V_1 ,
V_7 [ V_1 ] . V_11 ) ;
(* F_20) ( L_4 , V_1 ,
V_7 [ V_1 ] . V_10 ) ;
(* F_20) ( L_5 , V_1 ,
V_7 [ V_1 ] . V_14 ) ;
(* F_20) ( L_6 , V_1 ,
V_7 [ V_1 ] . V_13 ) ;
(* F_20) ( L_7 , V_1 ,
V_7 [ V_1 ] . V_44 ) ;
}
void F_21 ( T_2 V_1 ,
unsigned long V_49
) {
T_5 V_50 ;
T_7 V_51 ;
T_7 V_52 ;
V_51 = F_11 ( V_1 ) ;
V_50 = F_8 ( F_12 ( V_1 ) , 1000000 ) ;
V_52 = V_49 * V_50 ;
while ( V_52 > ( F_11 ( V_1 ) - V_51 ) )
;
}
static int F_8 ( int V_53 , int V_54 )
{
int V_55 ;
int V_56 = 1 ;
while ( ( V_54 & 0x40000000 ) == 0 ) {
V_54 = V_54 << 1 ;
V_56 = V_56 << 1 ;
}
V_55 = 0 ;
do {
if ( ( V_53 - V_54 ) >= 0 ) {
V_53 = V_53 - V_54 ;
V_55 = V_55 + V_56 ;
}
V_54 = V_54 >> 1 ;
V_56 = V_56 >> 1 ;
} while ( V_56 != 0 );
return V_55 ;
}
