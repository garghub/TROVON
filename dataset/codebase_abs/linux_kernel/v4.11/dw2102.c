static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_1 * V_6 , T_2 V_7 , int V_8 )
{
int V_9 ;
T_1 * V_10 ;
unsigned int V_11 = ( V_8 == V_12 ) ?
F_2 ( V_2 , 0 ) : F_3 ( V_2 , 0 ) ;
T_1 V_13 = ( V_8 == V_12 ) ? V_14 : V_15 ;
V_10 = F_4 ( V_7 , V_16 ) ;
if ( ! V_10 )
return - V_17 ;
if ( V_8 == V_18 )
memcpy ( V_10 , V_6 , V_7 ) ;
V_9 = F_5 ( V_2 , V_11 , V_3 , V_13 | V_19 ,
V_4 , V_5 , V_10 , V_7 , 2000 ) ;
if ( V_8 == V_12 )
memcpy ( V_6 , V_10 , V_7 ) ;
F_6 ( V_10 ) ;
return V_9 ;
}
static int F_7 ( struct V_20 * V_21 , struct V_22 V_23 [] ,
int V_24 )
{
struct V_25 * V_26 = F_8 ( V_21 ) ;
int V_27 = 0 ;
T_1 V_28 [] = { 0x2c , 0x05 , 0xc0 , 0 , 0 , 0 , 0 } ;
T_2 V_4 ;
if ( ! V_26 )
return - V_29 ;
if ( F_9 ( & V_26 -> V_30 ) < 0 )
return - V_31 ;
switch ( V_24 ) {
case 2 :
V_4 = V_23 [ 0 ] . V_32 [ 0 ] ;
for ( V_27 = 0 ; V_27 < V_23 [ 1 ] . V_7 ; V_27 ++ ) {
F_1 ( V_26 -> V_33 , 0xb5 , V_4 + V_27 , 0 ,
V_28 , 2 , V_12 ) ;
V_23 [ 1 ] . V_32 [ V_27 ] = V_28 [ 0 ] ;
}
break;
case 1 :
switch ( V_23 [ 0 ] . V_34 ) {
case 0x68 :
V_28 [ 0 ] = 0x2a ;
V_28 [ 1 ] = V_23 [ 0 ] . V_32 [ 0 ] ;
V_28 [ 2 ] = V_23 [ 0 ] . V_32 [ 1 ] ;
F_1 ( V_26 -> V_33 , 0xb2 , 0 , 0 ,
V_28 , 3 , V_18 ) ;
break;
case 0x60 :
if ( V_23 [ 0 ] . V_8 == 0 ) {
V_28 [ 0 ] = 0x2c ;
V_28 [ 1 ] = 5 ;
V_28 [ 2 ] = 0xc0 ;
V_28 [ 3 ] = V_23 [ 0 ] . V_32 [ 0 ] ;
V_28 [ 4 ] = V_23 [ 0 ] . V_32 [ 1 ] ;
V_28 [ 5 ] = V_23 [ 0 ] . V_32 [ 2 ] ;
V_28 [ 6 ] = V_23 [ 0 ] . V_32 [ 3 ] ;
F_1 ( V_26 -> V_33 , 0xb2 , 0 , 0 ,
V_28 , 7 , V_18 ) ;
} else {
F_1 ( V_26 -> V_33 , 0xb5 , 0 , 0 ,
V_28 , 1 , V_12 ) ;
V_23 [ 0 ] . V_32 [ 0 ] = V_28 [ 0 ] ;
}
break;
case ( V_35 ) :
F_1 ( V_26 -> V_33 , 0xb8 , 0 , 0 ,
V_28 , 2 , V_12 ) ;
V_23 [ 0 ] . V_32 [ 0 ] = V_28 [ 0 ] ;
V_23 [ 0 ] . V_32 [ 1 ] = V_28 [ 1 ] ;
break;
case ( V_36 ) :
V_28 [ 0 ] = 0x30 ;
V_28 [ 1 ] = V_23 [ 0 ] . V_32 [ 0 ] ;
F_1 ( V_26 -> V_33 , 0xb2 , 0 , 0 ,
V_28 , 2 , V_18 ) ;
break;
}
break;
}
F_10 ( & V_26 -> V_30 ) ;
return V_24 ;
}
static int F_11 ( struct V_20 * V_21 ,
struct V_22 V_23 [] , int V_24 )
{
struct V_25 * V_26 = F_8 ( V_21 ) ;
T_1 V_28 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( ! V_26 )
return - V_29 ;
if ( F_9 ( & V_26 -> V_30 ) < 0 )
return - V_31 ;
switch ( V_24 ) {
case 2 :
V_28 [ 0 ] = V_23 [ 0 ] . V_34 << 1 ;
V_28 [ 1 ] = V_23 [ 0 ] . V_7 ;
V_28 [ 2 ] = V_23 [ 0 ] . V_32 [ 0 ] ;
F_1 ( V_26 -> V_33 , 0xc2 , 0 , 0 ,
V_28 , V_23 [ 0 ] . V_7 + 2 , V_18 ) ;
F_1 ( V_26 -> V_33 , 0xc3 , 0xd0 , 0 ,
V_28 , V_23 [ 1 ] . V_7 + 2 , V_12 ) ;
memcpy ( V_23 [ 1 ] . V_32 , V_28 + 2 , V_23 [ 1 ] . V_7 ) ;
break;
case 1 :
switch ( V_23 [ 0 ] . V_34 ) {
case 0x68 :
V_28 [ 0 ] = V_23 [ 0 ] . V_34 << 1 ;
V_28 [ 1 ] = V_23 [ 0 ] . V_7 ;
memcpy ( V_28 + 2 , V_23 [ 0 ] . V_32 , V_23 [ 0 ] . V_7 ) ;
F_1 ( V_26 -> V_33 , 0xc2 , 0 , 0 , V_28 ,
V_23 [ 0 ] . V_7 + 2 , V_18 ) ;
break;
case ( V_35 ) :
F_1 ( V_26 -> V_33 , 0xb8 , 0 , 0 ,
V_28 , 2 , V_12 ) ;
V_23 [ 0 ] . V_32 [ 0 ] = V_28 [ 0 ] ;
V_23 [ 0 ] . V_32 [ 1 ] = V_28 [ 1 ] ;
break;
case ( V_36 ) :
V_28 [ 0 ] = 0x30 ;
V_28 [ 1 ] = V_23 [ 0 ] . V_32 [ 0 ] ;
F_1 ( V_26 -> V_33 , 0xb2 , 0 , 0 ,
V_28 , 2 , V_18 ) ;
break;
}
break;
}
F_10 ( & V_26 -> V_30 ) ;
return V_24 ;
}
static int F_12 ( struct V_20 * V_21 , struct V_22 V_23 [] , int V_24 )
{
struct V_25 * V_26 = F_8 ( V_21 ) ;
int V_9 ;
if ( ! V_26 )
return - V_29 ;
if ( F_9 ( & V_26 -> V_30 ) < 0 )
return - V_31 ;
switch ( V_24 ) {
case 2 : {
T_1 V_37 [ V_38 ] , V_39 [ 3 ] ;
if ( 2 + V_23 [ 1 ] . V_7 > sizeof( V_37 ) ) {
F_13 ( L_1 ,
V_23 [ 1 ] . V_7 ) ;
V_9 = - V_40 ;
goto V_41;
}
V_39 [ 0 ] = V_23 [ 0 ] . V_34 << 1 ;
V_39 [ 1 ] = V_23 [ 0 ] . V_7 ;
V_39 [ 2 ] = V_23 [ 0 ] . V_32 [ 0 ] ;
F_1 ( V_26 -> V_33 , 0xc2 , 0 , 0 ,
V_39 , V_23 [ 0 ] . V_7 + 2 , V_18 ) ;
F_1 ( V_26 -> V_33 , 0xc3 , 0xd1 , 0 ,
V_37 , V_23 [ 1 ] . V_7 + 2 , V_12 ) ;
memcpy ( V_23 [ 1 ] . V_32 , V_37 + 2 , V_23 [ 1 ] . V_7 ) ;
break;
}
case 1 :
switch ( V_23 [ 0 ] . V_34 ) {
case 0x68 : {
T_1 V_39 [ V_38 ] ;
if ( 2 + V_23 [ 0 ] . V_7 > sizeof( V_39 ) ) {
F_13 ( L_2 ,
V_23 [ 1 ] . V_7 ) ;
V_9 = - V_40 ;
goto V_41;
}
V_39 [ 0 ] = V_23 [ 0 ] . V_34 << 1 ;
V_39 [ 1 ] = V_23 [ 0 ] . V_7 ;
memcpy ( V_39 + 2 , V_23 [ 0 ] . V_32 , V_23 [ 0 ] . V_7 ) ;
F_1 ( V_26 -> V_33 , 0xc2 , 0 , 0 ,
V_39 , V_23 [ 0 ] . V_7 + 2 , V_18 ) ;
break;
}
case 0x61 : {
T_1 V_39 [ V_38 ] ;
if ( 2 + V_23 [ 0 ] . V_7 > sizeof( V_39 ) ) {
F_13 ( L_2 ,
V_23 [ 1 ] . V_7 ) ;
V_9 = - V_40 ;
goto V_41;
}
V_39 [ 0 ] = V_23 [ 0 ] . V_34 << 1 ;
V_39 [ 1 ] = V_23 [ 0 ] . V_7 ;
memcpy ( V_39 + 2 , V_23 [ 0 ] . V_32 , V_23 [ 0 ] . V_7 ) ;
F_1 ( V_26 -> V_33 , 0xc2 , 0 , 0 ,
V_39 , V_23 [ 0 ] . V_7 + 2 , V_18 ) ;
break;
}
case ( V_35 ) : {
T_1 V_37 [ 2 ] ;
F_1 ( V_26 -> V_33 , 0xb8 , 0 , 0 ,
V_37 , 2 , V_12 ) ;
memcpy ( V_23 [ 0 ] . V_32 , V_37 , 2 ) ;
break;
}
case ( V_36 ) : {
T_1 V_39 [ 2 ] ;
V_39 [ 0 ] = 0x30 ;
V_39 [ 1 ] = V_23 [ 0 ] . V_32 [ 0 ] ;
F_1 ( V_26 -> V_33 , 0xb2 , 0 , 0 ,
V_39 , 2 , V_18 ) ;
break;
}
}
break;
}
V_9 = V_24 ;
V_41:
F_10 ( & V_26 -> V_30 ) ;
return V_9 ;
}
static int F_14 ( struct V_20 * V_21 , struct V_22 V_23 [] , int V_24 )
{
struct V_25 * V_26 = F_8 ( V_21 ) ;
int V_7 , V_27 , V_42 , V_9 ;
if ( ! V_26 )
return - V_29 ;
if ( F_9 ( & V_26 -> V_30 ) < 0 )
return - V_31 ;
for ( V_42 = 0 ; V_42 < V_24 ; V_42 ++ ) {
switch ( V_23 [ V_42 ] . V_34 ) {
case ( V_35 ) : {
T_1 V_37 [ 2 ] ;
F_1 ( V_26 -> V_33 , 0xb8 , 0 , 0 ,
V_37 , 2 , V_12 ) ;
memcpy ( V_23 [ V_42 ] . V_32 , V_37 , 2 ) ;
break;
}
case ( V_36 ) : {
T_1 V_39 [ 2 ] ;
V_39 [ 0 ] = 0x30 ;
V_39 [ 1 ] = V_23 [ V_42 ] . V_32 [ 0 ] ;
F_1 ( V_26 -> V_33 , 0xb2 , 0 , 0 ,
V_39 , 2 , V_18 ) ;
break;
}
default: {
if ( V_23 [ V_42 ] . V_8 == V_43 ) {
T_1 V_37 [ V_38 ] ;
if ( 2 + V_23 [ V_42 ] . V_7 > sizeof( V_37 ) ) {
F_13 ( L_1 ,
V_23 [ V_42 ] . V_7 ) ;
V_9 = - V_40 ;
goto V_41;
}
F_1 ( V_26 -> V_33 , 0xc3 ,
( V_23 [ V_42 ] . V_34 << 1 ) + 1 , 0 ,
V_37 , V_23 [ V_42 ] . V_7 + 2 ,
V_12 ) ;
memcpy ( V_23 [ V_42 ] . V_32 , V_37 + 2 , V_23 [ V_42 ] . V_7 ) ;
F_15 ( 10 ) ;
} else if ( ( ( V_23 [ V_42 ] . V_32 [ 0 ] == 0xb0 ) &&
( V_23 [ V_42 ] . V_34 == 0x68 ) ) ||
( ( V_23 [ V_42 ] . V_32 [ 0 ] == 0xf7 ) &&
( V_23 [ V_42 ] . V_34 == 0x55 ) ) ) {
T_1 V_39 [ 19 ] ;
V_39 [ 0 ] = V_23 [ V_42 ] . V_34 << 1 ;
V_39 [ 1 ] = ( V_23 [ V_42 ] . V_7 > 15 ? 17 : V_23 [ V_42 ] . V_7 ) ;
V_39 [ 2 ] = V_23 [ V_42 ] . V_32 [ 0 ] ;
V_7 = V_23 [ V_42 ] . V_7 - 1 ;
V_27 = 1 ;
do {
memcpy ( V_39 + 3 , V_23 [ V_42 ] . V_32 + V_27 ,
( V_7 > 16 ? 16 : V_7 ) ) ;
F_1 ( V_26 -> V_33 , 0xc2 , 0 , 0 ,
V_39 , ( V_7 > 16 ? 16 : V_7 ) + 3 ,
V_18 ) ;
V_27 += 16 ;
V_7 -= 16 ;
} while ( V_7 > 0 );
} else {
T_1 V_39 [ V_38 ] ;
if ( 2 + V_23 [ V_42 ] . V_7 > sizeof( V_39 ) ) {
F_13 ( L_2 ,
V_23 [ V_42 ] . V_7 ) ;
V_9 = - V_40 ;
goto V_41;
}
V_39 [ 0 ] = V_23 [ V_42 ] . V_34 << 1 ;
V_39 [ 1 ] = V_23 [ V_42 ] . V_7 ;
memcpy ( V_39 + 2 , V_23 [ V_42 ] . V_32 , V_23 [ V_42 ] . V_7 ) ;
F_1 ( V_26 -> V_33 , 0xc2 , 0 , 0 ,
V_39 , V_23 [ V_42 ] . V_7 + 2 ,
V_18 ) ;
}
break;
}
}
}
V_9 = V_24 ;
V_41:
F_10 ( & V_26 -> V_30 ) ;
return V_9 ;
}
static int F_16 ( struct V_20 * V_21 , struct V_22 V_23 [] ,
int V_24 )
{
struct V_25 * V_26 = F_8 ( V_21 ) ;
int V_9 ;
int V_27 ;
if ( ! V_26 )
return - V_29 ;
if ( F_9 ( & V_26 -> V_30 ) < 0 )
return - V_31 ;
switch ( V_24 ) {
case 2 : {
T_1 V_37 [ V_38 ] , V_39 [ 3 ] ;
if ( 2 + V_23 [ 1 ] . V_7 > sizeof( V_37 ) ) {
F_13 ( L_1 ,
V_23 [ 1 ] . V_7 ) ;
V_9 = - V_40 ;
goto V_41;
}
V_39 [ 0 ] = V_23 [ 0 ] . V_34 << 1 ;
V_39 [ 1 ] = V_23 [ 0 ] . V_7 ;
V_39 [ 2 ] = V_23 [ 0 ] . V_32 [ 0 ] ;
F_1 ( V_26 -> V_33 , 0xc2 , 0 , 0 ,
V_39 , V_23 [ 0 ] . V_7 + 2 , V_18 ) ;
F_1 ( V_26 -> V_33 , 0xc3 , 0x19 , 0 ,
V_37 , V_23 [ 1 ] . V_7 + 2 , V_12 ) ;
memcpy ( V_23 [ 1 ] . V_32 , V_37 + 2 , V_23 [ 1 ] . V_7 ) ;
break;
}
case 1 :
switch ( V_23 [ 0 ] . V_34 ) {
case 0x60 :
case 0x0c : {
T_1 V_39 [ V_38 ] ;
if ( 2 + V_23 [ 0 ] . V_7 > sizeof( V_39 ) ) {
F_13 ( L_2 ,
V_23 [ 0 ] . V_7 ) ;
V_9 = - V_40 ;
goto V_41;
}
V_39 [ 0 ] = V_23 [ 0 ] . V_34 << 1 ;
V_39 [ 1 ] = V_23 [ 0 ] . V_7 ;
memcpy ( V_39 + 2 , V_23 [ 0 ] . V_32 , V_23 [ 0 ] . V_7 ) ;
F_1 ( V_26 -> V_33 , 0xc2 , 0 , 0 ,
V_39 , V_23 [ 0 ] . V_7 + 2 , V_18 ) ;
break;
}
case ( V_35 ) : {
T_1 V_37 [ 2 ] ;
F_1 ( V_26 -> V_33 , 0xb8 , 0 , 0 ,
V_37 , 2 , V_12 ) ;
memcpy ( V_23 [ 0 ] . V_32 , V_37 , 2 ) ;
break;
}
}
break;
}
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ ) {
F_17 ( L_3 , V_27 , V_23 [ V_27 ] . V_34 ,
V_23 [ V_27 ] . V_8 == 0 ? L_4 : L_5 ) ;
F_18 ( V_23 [ V_27 ] . V_32 , V_23 [ V_27 ] . V_7 , F_17 ) ;
}
V_9 = V_24 ;
V_41:
F_10 ( & V_26 -> V_30 ) ;
return V_9 ;
}
static int F_19 ( struct V_20 * V_21 , struct V_22 V_23 [] ,
int V_24 )
{
struct V_25 * V_26 = F_8 ( V_21 ) ;
struct V_1 * V_33 ;
int V_7 , V_27 , V_42 , V_9 ;
if ( ! V_26 )
return - V_29 ;
V_33 = V_26 -> V_33 ;
if ( F_9 ( & V_26 -> V_30 ) < 0 )
return - V_31 ;
for ( V_42 = 0 ; V_42 < V_24 ; V_42 ++ ) {
switch ( V_23 [ V_42 ] . V_34 ) {
case ( V_35 ) : {
T_1 V_37 [ 5 ] ;
F_1 ( V_26 -> V_33 , 0xb8 , 0 , 0 ,
V_37 , 5 , V_12 ) ;
memcpy ( V_23 [ V_42 ] . V_32 , V_37 + 3 , 2 ) ;
break;
}
case ( V_36 ) : {
T_1 V_39 [ 2 ] ;
V_39 [ 0 ] = 1 ;
V_39 [ 1 ] = V_23 [ V_42 ] . V_32 [ 1 ] ;
F_1 ( V_26 -> V_33 , 0x8a , 0 , 0 ,
V_39 , 2 , V_18 ) ;
V_39 [ 0 ] = 3 ;
V_39 [ 1 ] = V_23 [ V_42 ] . V_32 [ 0 ] ;
F_1 ( V_26 -> V_33 , 0x8a , 0 , 0 ,
V_39 , 2 , V_18 ) ;
break;
}
case ( V_44 ) : {
T_1 V_39 [ 2 ] ;
V_39 [ 0 ] = 5 ;
V_39 [ 1 ] = V_23 [ V_42 ] . V_32 [ 0 ] ;
F_1 ( V_26 -> V_33 , 0x8a , 0 , 0 ,
V_39 , 2 , V_18 ) ;
break;
}
default: {
if ( V_23 [ V_42 ] . V_8 == V_43 ) {
T_1 V_37 [ V_38 ] ;
if ( V_23 [ V_42 ] . V_7 > sizeof( V_37 ) ) {
F_13 ( L_1 ,
V_23 [ V_42 ] . V_7 ) ;
V_9 = - V_40 ;
goto V_41;
}
F_1 ( V_26 -> V_33 , 0x91 , 0 , 0 ,
V_37 , V_23 [ V_42 ] . V_7 ,
V_12 ) ;
memcpy ( V_23 [ V_42 ] . V_32 , V_37 , V_23 [ V_42 ] . V_7 ) ;
break;
} else if ( ( V_23 [ V_42 ] . V_32 [ 0 ] == 0xb0 ) &&
( V_23 [ V_42 ] . V_34 == 0x68 ) ) {
T_1 V_39 [ 19 ] ;
V_39 [ 0 ] = ( V_23 [ V_42 ] . V_7 > 16 ?
18 : V_23 [ V_42 ] . V_7 + 1 ) ;
V_39 [ 1 ] = V_23 [ V_42 ] . V_34 << 1 ;
V_39 [ 2 ] = V_23 [ V_42 ] . V_32 [ 0 ] ;
V_7 = V_23 [ V_42 ] . V_7 - 1 ;
V_27 = 1 ;
do {
memcpy ( V_39 + 3 , V_23 [ V_42 ] . V_32 + V_27 ,
( V_7 > 16 ? 16 : V_7 ) ) ;
F_1 ( V_26 -> V_33 , 0x80 , 0 , 0 ,
V_39 , ( V_7 > 16 ? 16 : V_7 ) + 3 ,
V_18 ) ;
V_27 += 16 ;
V_7 -= 16 ;
} while ( V_7 > 0 );
} else if ( V_42 < ( V_24 - 1 ) ) {
T_1 V_39 [ V_38 ] ;
if ( 2 + V_23 [ V_42 ] . V_7 > sizeof( V_39 ) ) {
F_13 ( L_2 ,
V_23 [ V_42 ] . V_7 ) ;
V_9 = - V_40 ;
goto V_41;
}
V_39 [ 0 ] = V_23 [ V_42 + 1 ] . V_7 ;
V_39 [ 1 ] = ( V_23 [ V_42 ] . V_34 << 1 ) ;
memcpy ( V_39 + 2 , V_23 [ V_42 ] . V_32 , V_23 [ V_42 ] . V_7 ) ;
F_1 ( V_26 -> V_33 ,
F_20 ( V_33 -> V_45 . V_46 ) ==
0x7500 ? 0x92 : 0x90 , 0 , 0 ,
V_39 , V_23 [ V_42 ] . V_7 + 2 ,
V_18 ) ;
break;
} else {
T_1 V_39 [ V_38 ] ;
if ( 2 + V_23 [ V_42 ] . V_7 > sizeof( V_39 ) ) {
F_13 ( L_2 ,
V_23 [ V_42 ] . V_7 ) ;
V_9 = - V_40 ;
goto V_41;
}
V_39 [ 0 ] = V_23 [ V_42 ] . V_7 + 1 ;
V_39 [ 1 ] = ( V_23 [ V_42 ] . V_34 << 1 ) ;
memcpy ( V_39 + 2 , V_23 [ V_42 ] . V_32 , V_23 [ V_42 ] . V_7 ) ;
F_1 ( V_26 -> V_33 , 0x80 , 0 , 0 ,
V_39 , V_23 [ V_42 ] . V_7 + 2 ,
V_18 ) ;
break;
}
break;
}
}
}
V_9 = V_24 ;
V_41:
F_10 ( & V_26 -> V_30 ) ;
return V_9 ;
}
static int F_21 ( struct V_20 * V_21 , struct V_22 V_23 [] ,
int V_24 )
{
struct V_25 * V_26 = F_8 ( V_21 ) ;
struct V_47 * V_48 ;
if ( ! V_26 )
return - V_29 ;
V_48 = V_26 -> V_49 ;
if ( F_9 ( & V_26 -> V_30 ) < 0 )
return - V_31 ;
if ( F_9 ( & V_26 -> V_50 ) < 0 ) {
F_10 ( & V_26 -> V_30 ) ;
return - V_31 ;
}
switch ( V_24 ) {
case 1 :
switch ( V_23 [ 0 ] . V_34 ) {
case V_51 :
V_48 -> V_6 [ 0 ] = V_23 [ 0 ] . V_32 [ 0 ] + 0x36 ;
V_48 -> V_6 [ 1 ] = 3 ;
V_48 -> V_6 [ 2 ] = 0 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 ,
V_48 -> V_6 , 0 , 0 ) < 0 )
F_23 ( L_6 ) ;
break;
case V_35 :
V_48 -> V_6 [ 0 ] = 0x10 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 1 ,
V_48 -> V_6 , 2 , 0 ) < 0 )
F_23 ( L_6 ) ;
V_23 [ 0 ] . V_32 [ 1 ] = V_48 -> V_6 [ 0 ] ;
V_23 [ 0 ] . V_32 [ 0 ] = V_48 -> V_6 [ 1 ] ;
break;
default:
V_48 -> V_6 [ 0 ] = 0x08 ;
V_48 -> V_6 [ 1 ] = V_23 [ 0 ] . V_34 ;
V_48 -> V_6 [ 2 ] = V_23 [ 0 ] . V_7 ;
memcpy ( & V_48 -> V_6 [ 3 ] , V_23 [ 0 ] . V_32 , V_23 [ 0 ] . V_7 ) ;
if ( F_22 ( V_26 , V_48 -> V_6 , V_23 [ 0 ] . V_7 + 3 ,
V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_6 ) ;
}
break;
case 2 :
V_48 -> V_6 [ 0 ] = 0x09 ;
V_48 -> V_6 [ 1 ] = V_23 [ 0 ] . V_7 ;
V_48 -> V_6 [ 2 ] = V_23 [ 1 ] . V_7 ;
V_48 -> V_6 [ 3 ] = V_23 [ 0 ] . V_34 ;
memcpy ( & V_48 -> V_6 [ 4 ] , V_23 [ 0 ] . V_32 , V_23 [ 0 ] . V_7 ) ;
if ( F_22 ( V_26 , V_48 -> V_6 , V_23 [ 0 ] . V_7 + 4 ,
V_48 -> V_6 , V_23 [ 1 ] . V_7 + 1 , 0 ) < 0 )
F_23 ( L_6 ) ;
memcpy ( V_23 [ 1 ] . V_32 , & V_48 -> V_6 [ 1 ] , V_23 [ 1 ] . V_7 ) ;
break;
default:
F_13 ( L_7 ) ;
break;
}
F_10 ( & V_26 -> V_50 ) ;
F_10 ( & V_26 -> V_30 ) ;
return V_24 ;
}
static T_3 F_24 ( struct V_20 * V_52 )
{
return V_53 ;
}
static int F_25 ( struct V_25 * V_26 , T_1 V_54 [ 6 ] )
{
int V_27 ;
T_1 V_37 [] = { 0 , 0 } ;
T_1 V_55 [ 256 ] , V_56 [ 16 ] ;
for ( V_27 = 0 ; V_27 < 256 ; V_27 ++ ) {
if ( F_1 ( V_26 -> V_33 , 0xb6 , 0xa0 , V_27 , V_37 , 2 , V_12 ) < 0 ) {
F_23 ( L_8 ) ;
return - 1 ;
} else {
V_56 [ V_27 % 16 ] = V_37 [ 0 ] ;
V_55 [ V_27 ] = V_37 [ 0 ] ;
}
if ( ( V_27 % 16 ) == 15 ) {
F_17 ( L_9 , V_27 - 15 ) ;
F_18 ( V_56 , 16 , F_17 ) ;
}
}
memcpy ( V_54 , V_55 + 8 , 6 ) ;
return 0 ;
}
static int F_26 ( struct V_25 * V_26 , T_1 V_54 [ 6 ] )
{
int V_27 , V_9 ;
T_1 V_37 [] = { 0 } , V_39 [] = { 0 } ;
T_1 V_55 [ 256 ] , V_56 [ 16 ] ;
struct V_22 V_23 [] = {
{
. V_34 = 0xa0 >> 1 ,
. V_8 = 0 ,
. V_32 = V_39 ,
. V_7 = 1 ,
} , {
. V_34 = 0xa0 >> 1 ,
. V_8 = V_43 ,
. V_32 = V_37 ,
. V_7 = 1 ,
}
} ;
for ( V_27 = 0 ; V_27 < 256 ; V_27 ++ ) {
V_39 [ 0 ] = V_27 ;
V_9 = F_19 ( & V_26 -> V_57 , V_23 , 2 ) ;
if ( V_9 != 2 ) {
F_23 ( L_8 ) ;
return - 1 ;
} else {
V_56 [ V_27 % 16 ] = V_37 [ 0 ] ;
V_55 [ V_27 ] = V_37 [ 0 ] ;
}
if ( ( V_27 % 16 ) == 15 ) {
F_17 ( L_9 , V_27 - 15 ) ;
F_18 ( V_56 , 16 , F_17 ) ;
}
}
memcpy ( V_54 , V_55 + 16 , 6 ) ;
return 0 ;
}
static int F_27 ( struct V_58 * V_21 , int V_59 )
{
static T_1 V_60 [] = { 0x00 } ;
static T_1 V_61 [] = { 0x01 } ;
struct V_22 V_23 = {
. V_34 = V_51 ,
. V_8 = 0 ,
. V_32 = V_59 ? V_60 : V_61 ,
. V_7 = 1
} ;
F_28 ( & V_21 -> V_2 -> V_57 , & V_23 , 1 ) ;
return 0 ;
}
static int F_29 ( struct V_25 * V_26 , int V_27 )
{
struct V_47 * V_48 = (struct V_47 * ) V_26 -> V_49 ;
int V_9 = 0 ;
F_30 ( L_10 , V_62 , V_27 , V_48 -> V_63 ) ;
if ( V_27 && ! V_48 -> V_63 ) {
F_31 ( & V_26 -> V_50 ) ;
V_48 -> V_6 [ 0 ] = 0xde ;
V_48 -> V_6 [ 1 ] = 0 ;
V_48 -> V_63 = 1 ;
V_9 = F_22 ( V_26 , V_48 -> V_6 , 2 , NULL , 0 , 0 ) ;
F_10 ( & V_26 -> V_50 ) ;
}
return V_9 ;
}
static int F_32 ( struct V_25 * V_26 , T_1 V_54 [ 6 ] )
{
int V_27 ;
T_1 V_39 [] = { 0x1f , 0xf0 } ;
T_1 V_37 [] = { 0 } ;
struct V_22 V_23 [] = {
{
. V_34 = 0x51 ,
. V_8 = 0 ,
. V_32 = V_39 ,
. V_7 = 2 ,
} , {
. V_34 = 0x51 ,
. V_8 = V_43 ,
. V_32 = V_37 ,
. V_7 = 1 ,
}
} ;
for ( V_27 = 0 ; V_27 < 6 ; V_27 ++ ) {
V_39 [ 1 ] = 0xf0 + V_27 ;
if ( F_28 ( & V_26 -> V_57 , V_23 , 2 ) != 2 )
break;
else
V_54 [ V_27 ] = V_37 [ 0 ] ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_33 ,
struct V_64 * V_65 ,
struct V_66 * * V_67 ,
int * V_68 )
{
F_30 ( L_11 , V_62 ) ;
* V_68 = 0 ;
return 0 ;
}
static int F_34 ( struct V_69 * V_70 ,
enum V_71 V_72 )
{
static T_1 V_73 [] = { 0x00 , 0x01 } ;
static T_1 V_74 [] = { 0x01 , 0x01 } ;
static T_1 V_75 [] = { 0x00 , 0x00 } ;
struct V_22 V_23 = {
. V_34 = V_36 ,
. V_8 = 0 ,
. V_32 = V_75 ,
. V_7 = 2 ,
} ;
struct V_58 * V_76 =
(struct V_58 * ) ( V_70 -> V_77 -> V_49 ) ;
if ( V_72 == V_78 )
V_23 . V_32 = V_74 ;
else if ( V_72 == V_79 )
V_23 . V_32 = V_73 ;
F_28 ( & V_76 -> V_2 -> V_57 , & V_23 , 1 ) ;
return 0 ;
}
static int F_35 ( struct V_69 * V_70 ,
enum V_71 V_72 )
{
struct V_58 * V_26 =
(struct V_58 * ) ( V_70 -> V_77 -> V_49 ) ;
struct V_47 * V_80 = (struct V_47 * ) V_26 -> V_2 -> V_49 ;
F_34 ( V_70 , V_72 ) ;
if ( V_80 -> V_81 )
V_80 -> V_81 ( V_70 , V_72 ) ;
return 0 ;
}
static void F_36 ( struct V_69 * V_70 , int V_82 )
{
static T_1 V_83 [] = { 0 } ;
static T_1 V_84 [] = { 1 } ;
struct V_22 V_23 = {
. V_34 = V_44 ,
. V_8 = 0 ,
. V_32 = V_83 ,
. V_7 = 1
} ;
struct V_58 * V_76 =
(struct V_58 * ) ( V_70 -> V_77 -> V_49 ) ;
if ( V_82 )
V_23 . V_32 = V_84 ;
F_28 ( & V_76 -> V_2 -> V_57 , & V_23 , 1 ) ;
}
static int F_37 ( struct V_69 * V_70 ,
enum V_85 * V_86 )
{
struct V_58 * V_26 =
(struct V_58 * ) ( V_70 -> V_77 -> V_49 ) ;
struct V_47 * V_80 = (struct V_47 * ) V_26 -> V_2 -> V_49 ;
int V_9 ;
V_9 = V_80 -> V_87 ( V_70 , V_86 ) ;
if ( ( * V_86 & V_88 ) && ( ! V_80 -> V_89 ) )
F_27 ( V_26 , 1 ) ;
V_80 -> V_89 = ( * V_86 & V_88 ) ? 1 : 0 ;
return V_9 ;
}
static int F_38 ( struct V_58 * V_26 )
{
struct V_90 * V_91 = NULL ;
if ( V_92 & 4 ) {
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_94 , & V_95 ,
& V_26 -> V_2 -> V_57 , 0 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 != NULL ) {
if ( F_39 ( V_96 , V_26 -> V_93 [ 0 ] . V_70 ,
& V_97 ,
& V_26 -> V_2 -> V_57 ) ) {
V_91 = & V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_91 ;
V_91 -> V_99 = V_100 ;
V_91 -> V_101 = V_102 ;
V_91 -> V_103 = V_104 ;
V_91 -> V_105 = V_106 ;
V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 = F_34 ;
F_30 ( L_12 ) ;
return 0 ;
}
}
}
if ( V_92 & 2 ) {
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_94 , & V_108 ,
& V_26 -> V_2 -> V_57 , 0 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 != NULL ) {
if ( F_39 ( V_109 , V_26 -> V_93 [ 0 ] . V_70 ,
& V_110 ,
& V_26 -> V_2 -> V_57 ) ) {
V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 = F_34 ;
F_30 ( L_13 ) ;
return 0 ;
}
}
}
if ( V_92 & 1 ) {
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_111 , & V_112 ,
& V_26 -> V_2 -> V_57 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 != NULL ) {
V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 = F_34 ;
F_30 ( L_14 ) ;
return 0 ;
}
}
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_113 , & V_114 ,
& V_26 -> V_2 -> V_57 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 != NULL ) {
F_39 ( V_115 , V_26 -> V_93 [ 0 ] . V_70 ,
& V_116 , & V_26 -> V_2 -> V_57 ) ;
V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 = F_34 ;
F_30 ( L_15 ) ;
return 0 ;
}
return - V_117 ;
}
static int F_40 ( struct V_58 * V_26 )
{
if ( V_118 . V_119 == & V_120 ) {
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_121 , & V_122 ,
& V_26 -> V_2 -> V_57 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 != NULL ) {
V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 = F_34 ;
F_30 ( L_16 ) ;
return 0 ;
}
}
if ( V_118 . V_119 == & V_123 ) {
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_124 , & V_125 ,
& V_26 -> V_2 -> V_57 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 != NULL ) {
if ( F_39 ( V_126 , V_26 -> V_93 [ 0 ] . V_70 , 0x61 ,
& V_26 -> V_2 -> V_57 ) ) {
V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 = F_34 ;
F_30 ( L_17 ) ;
return 0 ;
}
}
}
if ( V_118 . V_119 == & V_127 ) {
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_128 , & V_129 ,
& V_26 -> V_2 -> V_57 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 != NULL ) {
V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 = F_34 ;
F_30 ( L_18 ) ;
return 0 ;
}
}
return - V_117 ;
}
static int F_41 ( struct V_58 * V_26 )
{
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_130 , & V_131 ,
& V_26 -> V_2 -> V_57 , 0x48 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 != NULL ) {
F_30 ( L_19 ) ;
return 0 ;
}
return - V_117 ;
}
static int F_42 ( struct V_58 * V_26 )
{
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_132 , & V_133 ,
& V_26 -> V_2 -> V_57 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 != NULL ) {
if ( F_39 ( V_134 , V_26 -> V_93 [ 0 ] . V_70 , 0x60 ,
& V_26 -> V_2 -> V_57 ) ) {
V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 = F_34 ;
F_30 ( L_20 ) ;
return 0 ;
}
}
return - V_117 ;
}
static int F_43 ( struct V_58 * V_26 )
{
T_1 V_39 [] = { 7 , 1 } ;
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_124 , & V_125 ,
& V_26 -> V_2 -> V_57 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 == NULL )
return - V_117 ;
if ( NULL == F_39 ( V_126 , V_26 -> V_93 [ 0 ] . V_70 , 0x61 , & V_26 -> V_2 -> V_57 ) )
return - V_117 ;
V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 = F_34 ;
F_1 ( V_26 -> V_2 -> V_33 , 0x8a , 0 , 0 , V_39 , 2 , V_18 ) ;
F_30 ( L_21 ) ;
return 0 ;
}
static int F_44 ( struct V_58 * V_26 )
{
struct V_47 * V_80 = V_26 -> V_2 -> V_49 ;
T_1 V_39 [] = { 7 , 1 } ;
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_113 , & V_135 ,
& V_26 -> V_2 -> V_57 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 == NULL )
return - V_117 ;
F_39 ( V_115 , V_26 -> V_93 [ 0 ] . V_70 , & V_136 ,
& V_26 -> V_2 -> V_57 ) ;
V_80 -> V_81 = V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 ;
V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 = F_35 ;
F_1 ( V_26 -> V_2 -> V_33 , 0x8a , 0 , 0 , V_39 , 2 , V_18 ) ;
F_30 ( L_22 ) ;
return 0 ;
}
static int F_45 ( struct V_58 * V_26 )
{
T_1 V_39 [] = { 7 , 1 } ;
V_26 -> V_93 [ 0 ] . V_70 = F_39 ( V_94 , & V_137 ,
& V_26 -> V_2 -> V_57 , 0 ) ;
if ( V_26 -> V_93 [ 0 ] . V_70 == NULL )
return - V_117 ;
V_26 -> V_93 [ 0 ] . V_70 -> V_98 . V_107 = F_34 ;
F_1 ( V_26 -> V_2 -> V_33 , 0x8a , 0 , 0 , V_39 , 2 , V_18 ) ;
F_30 ( L_23 ) ;
return 0 ;
}
static int F_46 ( struct V_58 * V_21 )
{
struct V_25 * V_26 = V_21 -> V_2 ;
struct V_47 * V_48 = V_26 -> V_49 ;
F_31 ( & V_26 -> V_50 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x80 ;
V_48 -> V_6 [ 2 ] = 0 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x02 ;
V_48 -> V_6 [ 2 ] = 1 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
F_47 ( 300 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x83 ;
V_48 -> V_6 [ 2 ] = 0 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x83 ;
V_48 -> V_6 [ 2 ] = 1 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
V_48 -> V_6 [ 0 ] = 0x51 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 1 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_25 ) ;
F_10 ( & V_26 -> V_50 ) ;
V_21 -> V_93 [ 0 ] . V_70 = F_39 ( V_113 , & V_138 ,
& V_26 -> V_57 ) ;
if ( V_21 -> V_93 [ 0 ] . V_70 == NULL )
return - V_117 ;
if ( F_39 ( V_115 , V_21 -> V_93 [ 0 ] . V_70 ,
& V_116 ,
& V_26 -> V_57 ) ) {
F_30 ( L_26 ) ;
return 0 ;
}
F_30 ( L_27 ) ;
return - V_117 ;
}
static int F_48 ( struct V_58 * V_21 )
{
struct V_25 * V_26 = V_21 -> V_2 ;
struct V_47 * V_48 = V_26 -> V_49 ;
F_31 ( & V_26 -> V_50 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x87 ;
V_48 -> V_6 [ 2 ] = 0x0 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x86 ;
V_48 -> V_6 [ 2 ] = 1 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x80 ;
V_48 -> V_6 [ 2 ] = 0 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
F_47 ( 50 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x80 ;
V_48 -> V_6 [ 2 ] = 1 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
V_48 -> V_6 [ 0 ] = 0x51 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 1 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_25 ) ;
F_10 ( & V_26 -> V_50 ) ;
V_21 -> V_93 [ 0 ] . V_70 = F_39 ( V_139 , & V_140 ,
& V_26 -> V_57 , NULL ) ;
if ( V_21 -> V_93 [ 0 ] . V_70 != NULL ) {
if ( F_39 ( V_141 , V_21 -> V_93 [ 0 ] . V_70 , 0x60 ,
& V_26 -> V_57 , & V_142 ) ) {
F_30 ( L_28 ) ;
return 0 ;
}
}
F_30 ( L_29 ) ;
return - V_117 ;
}
static int F_49 ( struct V_58 * V_21 )
{
struct V_25 * V_26 = V_21 -> V_2 ;
struct V_47 * V_48 = V_26 -> V_49 ;
F_31 ( & V_26 -> V_50 ) ;
V_48 -> V_6 [ 0 ] = 0x51 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 1 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_25 ) ;
F_10 ( & V_26 -> V_50 ) ;
V_21 -> V_93 [ 0 ] . V_70 = F_39 ( V_143 ,
& V_144 ,
& V_26 -> V_57 ) ;
if ( V_21 -> V_93 [ 0 ] . V_70 == NULL )
return - V_117 ;
if ( F_39 ( V_115 , V_21 -> V_93 [ 0 ] . V_70 ,
& V_116 ,
& V_26 -> V_57 ) ) {
F_30 ( L_30 ) ;
return 0 ;
}
F_30 ( L_31 ) ;
return - V_117 ;
}
static int F_50 ( struct V_58 * V_21 )
{
struct V_25 * V_26 = V_21 -> V_2 ;
struct V_47 * V_48 = V_26 -> V_49 ;
struct V_20 * V_20 ;
struct V_145 * V_146 ;
struct V_147 V_148 ;
struct V_149 V_150 = {} ;
struct V_151 V_151 = {} ;
F_31 ( & V_26 -> V_50 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x80 ;
V_48 -> V_6 [ 2 ] = 0x0 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x02 ;
V_48 -> V_6 [ 2 ] = 1 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
F_47 ( 300 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x83 ;
V_48 -> V_6 [ 2 ] = 0 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
V_48 -> V_6 [ 0 ] = 0xe ;
V_48 -> V_6 [ 1 ] = 0x83 ;
V_48 -> V_6 [ 2 ] = 1 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 3 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_24 ) ;
V_48 -> V_6 [ 0 ] = 0x51 ;
if ( F_22 ( V_26 , V_48 -> V_6 , 1 , V_48 -> V_6 , 1 , 0 ) < 0 )
F_23 ( L_25 ) ;
F_10 ( & V_26 -> V_50 ) ;
V_150 . V_152 = 27000000 ;
V_150 . V_153 = 33 ;
V_150 . V_154 = V_155 ;
V_150 . V_156 = 16000 ;
V_150 . V_157 = 0 ;
V_150 . V_158 = 0 ;
V_150 . V_159 = 0x99 ;
V_150 . V_160 = 0 ;
V_150 . V_161 = V_162 ;
V_150 . V_163 = 0 ;
V_150 . V_164 = 1 ;
V_150 . V_165 = 0 ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
F_51 ( V_148 . type , L_32 , V_166 ) ;
V_148 . V_34 = 0x68 ;
V_148 . V_167 = & V_150 ;
F_52 ( L_32 ) ;
V_146 = F_53 ( & V_26 -> V_57 , & V_148 ) ;
if ( V_146 == NULL || V_146 -> V_2 . V_168 == NULL )
return - V_29 ;
if ( ! F_54 ( V_146 -> V_2 . V_168 -> V_169 ) ) {
F_55 ( V_146 ) ;
return - V_29 ;
}
V_21 -> V_93 [ 0 ] . V_70 = V_150 . V_170 ( V_146 ) ;
V_20 = V_150 . V_171 ( V_146 ) ;
V_48 -> V_172 = V_146 ;
V_151 . V_70 = V_21 -> V_93 [ 0 ] . V_70 ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
F_51 ( V_148 . type , L_33 , V_166 ) ;
V_148 . V_34 = 0x60 ;
V_148 . V_167 = & V_151 ;
F_52 ( L_34 ) ;
V_146 = F_53 ( V_20 , & V_148 ) ;
if ( V_146 == NULL || V_146 -> V_2 . V_168 == NULL ) {
F_56 ( V_21 -> V_93 [ 0 ] . V_70 ) ;
return - V_29 ;
}
if ( ! F_54 ( V_146 -> V_2 . V_168 -> V_169 ) ) {
F_55 ( V_146 ) ;
F_56 ( V_21 -> V_93 [ 0 ] . V_70 ) ;
return - V_29 ;
}
V_21 -> V_93 [ 0 ] . V_70 -> V_98 . V_173 =
V_21 -> V_93 [ 0 ] . V_70 -> V_98 . V_91 . V_174 ;
V_48 -> V_175 = V_146 ;
V_48 -> V_87 = V_21 -> V_93 [ 0 ] . V_70 -> V_98 . V_176 ;
V_21 -> V_93 [ 0 ] . V_70 -> V_98 . V_176 = F_37 ;
V_48 -> V_89 = 0 ;
return 0 ;
}
static int F_57 ( struct V_58 * V_21 )
{
F_39 ( V_177 , V_21 -> V_93 [ 0 ] . V_70 , 0x60 ,
& V_21 -> V_2 -> V_57 , V_178 ) ;
return 0 ;
}
static int F_58 ( struct V_58 * V_21 )
{
F_39 ( V_177 , V_21 -> V_93 [ 0 ] . V_70 , 0x60 ,
& V_21 -> V_2 -> V_57 , V_179 ) ;
return 0 ;
}
static int F_59 ( struct V_25 * V_26 )
{
T_1 V_180 [ 2 ] ;
struct V_22 V_23 = {
. V_34 = V_35 ,
. V_8 = V_43 ,
. V_32 = V_180 ,
. V_7 = 2
} ;
if ( V_26 -> V_65 . V_119 -> V_181 ( & V_26 -> V_57 , & V_23 , 1 ) == 1 ) {
if ( V_23 . V_32 [ 0 ] != 0xff ) {
F_60 ( L_35 ,
V_62 , V_180 [ 0 ] , V_180 [ 1 ] ) ;
F_61 ( V_26 -> V_182 , V_183 , V_180 [ 0 ] , 0 ) ;
}
}
return 0 ;
}
static int F_62 ( struct V_25 * V_26 )
{
T_1 V_180 [ 2 ] ;
struct V_22 V_23 = {
. V_34 = V_35 ,
. V_8 = V_43 ,
. V_32 = V_180 ,
. V_7 = 2
} ;
if ( V_26 -> V_65 . V_119 -> V_181 ( & V_26 -> V_57 , & V_23 , 1 ) == 1 ) {
if ( V_23 . V_32 [ 0 ] != 0xff ) {
F_60 ( L_35 ,
V_62 , V_180 [ 0 ] , V_180 [ 1 ] ) ;
F_61 ( V_26 -> V_182 , V_183 , V_180 [ 0 ] ^ 0xff , 0 ) ;
}
}
return 0 ;
}
static int F_63 ( struct V_25 * V_26 )
{
T_1 V_180 [ 2 ] ;
struct V_22 V_23 = {
. V_34 = V_35 ,
. V_8 = V_43 ,
. V_32 = V_180 ,
. V_7 = 2
} ;
if ( V_26 -> V_65 . V_119 -> V_181 ( & V_26 -> V_57 , & V_23 , 1 ) == 1 ) {
if ( V_23 . V_32 [ 0 ] != 0xff ) {
F_60 ( L_35 ,
V_62 , V_180 [ 0 ] , V_180 [ 1 ] ) ;
F_61 ( V_26 -> V_182 , V_184 ,
F_64 ( V_180 [ 1 ] , V_180 [ 0 ] ) , 0 ) ;
}
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
const struct V_185 * V_186 )
{
T_1 * V_187 , * V_188 ;
int V_9 = 0 , V_27 ;
T_1 V_189 ;
T_1 V_190 [] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
const struct V_185 * V_191 ;
switch ( F_20 ( V_2 -> V_45 . V_46 ) ) {
case 0x2101 :
V_9 = F_66 ( & V_191 , V_192 , & V_2 -> V_2 ) ;
if ( V_9 != 0 ) {
F_23 ( V_193 , V_192 ) ;
return V_9 ;
}
break;
default:
V_191 = V_186 ;
break;
}
F_30 ( L_36 ) ;
V_188 = F_4 ( V_191 -> V_194 , V_16 ) ;
V_189 = 1 ;
F_1 ( V_2 , 0xa0 , 0x7f92 , 0 , & V_189 , 1 , V_18 ) ;
F_1 ( V_2 , 0xa0 , 0xe600 , 0 , & V_189 , 1 , V_18 ) ;
if ( V_188 != NULL ) {
memcpy ( V_188 , V_191 -> V_6 , V_191 -> V_194 ) ;
for ( V_27 = 0 ; V_27 < V_191 -> V_194 ; V_27 += 0x40 ) {
V_187 = ( T_1 * ) V_188 + V_27 ;
if ( F_1 ( V_2 , 0xa0 , V_27 , 0 , V_187 , 0x40 ,
V_18 ) != 0x40 ) {
F_23 ( L_37 ) ;
V_9 = - V_195 ;
break;
}
}
V_189 = 0 ;
if ( V_9 || F_1 ( V_2 , 0xa0 , 0x7f92 , 0 , & V_189 , 1 ,
V_18 ) != 1 ) {
F_23 ( L_38 ) ;
V_9 = - V_195 ;
}
if ( V_9 || F_1 ( V_2 , 0xa0 , 0xe600 , 0 , & V_189 , 1 ,
V_18 ) != 1 ) {
F_23 ( L_38 ) ;
V_9 = - V_195 ;
}
switch ( F_20 ( V_2 -> V_45 . V_46 ) ) {
case V_196 :
V_197 . V_198 . V_199 . V_200 = V_201 ;
case V_202 :
V_189 = 1 ;
F_1 ( V_2 , 0xc4 , 0x0000 , 0 , & V_189 , 1 ,
V_18 ) ;
case V_203 :
V_189 = 0 ;
F_1 ( V_2 , 0xbf , 0x0040 , 0 , & V_189 , 0 ,
V_18 ) ;
break;
case V_204 :
case V_205 :
F_1 ( V_2 , 0xbf , 0x0040 , 0 , & V_189 , 0 ,
V_18 ) ;
F_1 ( V_2 , 0xb9 , 0x0000 , 0 , & V_190 [ 0 ] , 2 ,
V_12 ) ;
F_1 ( V_2 , 0xb5 , 0 , 0 , & V_190 [ 0 ] , 2 ,
V_12 ) ;
if ( ( V_190 [ 0 ] == 0xa1 ) || ( V_190 [ 0 ] == 0x80 ) ) {
V_118 . V_119 = & V_127 ;
V_118 . V_52 -> V_70 [ 0 ] . V_206 = & F_57 ;
break;
} else {
V_190 [ 0 ] = 0xd0 ;
V_190 [ 1 ] = 1 ;
V_190 [ 2 ] = 0 ;
F_1 ( V_2 , 0xc2 , 0 , 0 , & V_190 [ 0 ] , 3 ,
V_18 ) ;
F_1 ( V_2 , 0xc3 , 0xd1 , 0 , & V_190 [ 0 ] , 3 ,
V_12 ) ;
if ( V_190 [ 2 ] == 0x11 ) {
V_118 . V_119 = & V_123 ;
break;
}
}
case 0x2101 :
F_1 ( V_2 , 0xbc , 0x0030 , 0 , & V_190 [ 0 ] , 2 ,
V_12 ) ;
F_1 ( V_2 , 0xba , 0x0000 , 0 , & V_190 [ 0 ] , 7 ,
V_12 ) ;
F_1 ( V_2 , 0xba , 0x0000 , 0 , & V_190 [ 0 ] , 7 ,
V_12 ) ;
F_1 ( V_2 , 0xb9 , 0x0000 , 0 , & V_190 [ 0 ] , 2 ,
V_12 ) ;
break;
}
F_47 ( 100 ) ;
F_6 ( V_188 ) ;
}
if ( F_20 ( V_2 -> V_45 . V_46 ) == 0x2101 )
F_67 ( V_191 ) ;
return V_9 ;
}
static int F_68 ( struct V_207 * V_208 ,
const struct V_209 * V_210 )
{
V_211 = F_69 ( & V_212 ,
sizeof( struct V_64 ) , V_16 ) ;
if ( ! V_211 )
return - V_17 ;
V_211 -> V_185 = V_213 ;
V_211 -> V_214 [ 0 ] = V_215 ;
V_211 -> V_198 . V_199 . V_216 = F_62 ;
V_211 -> V_198 . V_199 . V_200 = V_217 ;
V_211 -> V_52 -> V_70 [ 0 ] . V_218 = F_43 ;
V_219 = F_69 ( & V_212 ,
sizeof( struct V_64 ) , V_16 ) ;
if ( ! V_219 ) {
F_6 ( V_211 ) ;
return - V_17 ;
}
V_219 -> V_185 = V_220 ;
V_219 -> V_221 = 3 ;
V_219 -> V_214 [ 0 ] = V_222 ;
V_219 -> V_214 [ 1 ] = V_223 ;
V_219 -> V_214 [ 2 ] = V_224 ;
V_219 -> V_52 -> V_70 [ 0 ] . V_218 = F_44 ;
V_225 = F_69 ( & V_212 ,
sizeof( struct V_64 ) , V_16 ) ;
if ( ! V_225 ) {
F_6 ( V_211 ) ;
F_6 ( V_219 ) ;
return - V_17 ;
}
V_225 -> V_185 = V_226 ;
V_225 -> V_214 [ 0 ] = V_227 ;
V_225 -> V_198 . V_199 . V_216 = F_62 ;
V_225 -> V_198 . V_199 . V_200 = V_217 ;
V_225 -> V_52 -> V_70 [ 0 ] . V_218 = F_45 ;
V_228 = F_69 ( & V_229 ,
sizeof( struct V_64 ) , V_16 ) ;
if ( ! V_228 ) {
F_6 ( V_211 ) ;
F_6 ( V_219 ) ;
F_6 ( V_225 ) ;
return - V_17 ;
}
V_228 -> V_221 = 2 ;
V_228 -> V_214 [ 0 ] = V_230 ;
V_228 -> V_214 [ 1 ] = V_231 ;
V_228 -> V_52 -> V_70 [ 0 ] . V_218 = F_49 ;
if ( 0 == F_70 ( V_208 , & V_118 ,
V_232 , NULL , V_233 ) ||
0 == F_70 ( V_208 , & V_197 ,
V_232 , NULL , V_233 ) ||
0 == F_70 ( V_208 , & V_234 ,
V_232 , NULL , V_233 ) ||
0 == F_70 ( V_208 , & V_212 ,
V_232 , NULL , V_233 ) ||
0 == F_70 ( V_208 , V_211 ,
V_232 , NULL , V_233 ) ||
0 == F_70 ( V_208 , V_219 ,
V_232 , NULL , V_233 ) ||
0 == F_70 ( V_208 , V_225 ,
V_232 , NULL , V_233 ) ||
0 == F_70 ( V_208 , V_228 ,
V_232 , NULL , V_233 ) ||
0 == F_70 ( V_208 , & V_229 ,
V_232 , NULL , V_233 ) ||
0 == F_70 ( V_208 , & V_235 ,
V_232 , NULL , V_233 ) ||
0 == F_70 ( V_208 , & V_236 ,
V_232 , NULL , V_233 ) )
return 0 ;
return - V_29 ;
}
static void F_71 ( struct V_207 * V_208 )
{
struct V_25 * V_26 = F_72 ( V_208 ) ;
struct V_47 * V_80 = (struct V_47 * ) V_26 -> V_49 ;
struct V_145 * V_146 ;
V_146 = V_80 -> V_175 ;
if ( V_146 ) {
F_73 ( V_146 -> V_2 . V_168 -> V_169 ) ;
F_55 ( V_146 ) ;
}
V_146 = V_80 -> V_172 ;
if ( V_146 ) {
F_73 ( V_146 -> V_2 . V_168 -> V_169 ) ;
F_55 ( V_146 ) ;
}
F_74 ( V_208 ) ;
}
