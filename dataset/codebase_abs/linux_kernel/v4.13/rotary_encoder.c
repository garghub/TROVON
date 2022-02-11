static unsigned int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_6 ; ++ V_3 ) {
int V_7 = F_2 ( V_2 -> V_5 -> V_8 [ V_3 ] ) ;
if ( V_2 -> V_9 == V_10 && V_4 & 1 )
V_7 = ! V_7 ;
V_4 = V_4 << 1 | V_7 ;
}
return V_4 & 3 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 ) {
F_4 ( V_2 -> V_12 ,
V_2 -> V_13 , V_2 -> V_14 ) ;
} else {
unsigned int V_15 = V_2 -> V_15 ;
if ( V_2 -> V_14 < 0 ) {
if ( V_2 -> V_16 )
V_15 += V_2 -> V_17 ;
if ( V_15 )
V_15 -- ;
} else {
if ( V_2 -> V_16 || V_15 < V_2 -> V_17 )
V_15 ++ ;
}
if ( V_2 -> V_16 )
V_15 %= V_2 -> V_17 ;
V_2 -> V_15 = V_15 ;
F_5 ( V_2 -> V_12 , V_2 -> V_13 , V_2 -> V_15 ) ;
}
F_6 ( V_2 -> V_12 ) ;
}
static T_1 F_7 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
unsigned int V_20 ;
F_8 ( & V_2 -> V_21 ) ;
V_20 = F_1 ( V_2 ) ;
switch ( V_20 ) {
case 0x0 :
if ( V_2 -> V_22 ) {
F_3 ( V_2 ) ;
V_2 -> V_22 = false ;
}
break;
case 0x1 :
case 0x3 :
if ( V_2 -> V_22 )
V_2 -> V_14 = 2 - V_20 ;
break;
case 0x2 :
V_2 -> V_22 = true ;
break;
}
F_9 ( & V_2 -> V_21 ) ;
return V_23 ;
}
static T_1 F_10 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
unsigned int V_20 ;
F_8 ( & V_2 -> V_21 ) ;
V_20 = F_1 ( V_2 ) ;
if ( V_20 & 1 ) {
V_2 -> V_14 = ( ( V_2 -> V_24 - V_20 + 1 ) % 4 ) - 1 ;
} else {
if ( V_20 != V_2 -> V_24 ) {
F_3 ( V_2 ) ;
V_2 -> V_24 = V_20 ;
}
}
F_9 ( & V_2 -> V_21 ) ;
return V_23 ;
}
static T_1 F_11 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
unsigned int V_20 ;
F_8 ( & V_2 -> V_21 ) ;
V_20 = F_1 ( V_2 ) ;
if ( ( V_2 -> V_24 + 1 ) % 4 == V_20 )
V_2 -> V_14 = 1 ;
else if ( V_2 -> V_24 == ( V_20 + 1 ) % 4 )
V_2 -> V_14 = - 1 ;
else
goto V_25;
F_3 ( V_2 ) ;
V_25:
V_2 -> V_24 = V_20 ;
F_9 ( & V_2 -> V_21 ) ;
return V_23 ;
}
static int F_12 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = & V_27 -> V_29 ;
struct V_1 * V_2 ;
struct V_30 * V_12 ;
T_2 V_31 ;
T_3 V_32 ;
unsigned int V_3 ;
int V_33 ;
V_2 = F_13 ( V_29 , sizeof( struct V_1 ) , V_34 ) ;
if ( ! V_2 )
return - V_35 ;
F_14 ( & V_2 -> V_21 ) ;
F_15 ( V_29 , L_1 , & V_2 -> V_17 ) ;
V_33 = F_15 ( V_29 , L_2 ,
& V_32 ) ;
if ( V_33 ) {
V_32 = F_16 ( V_29 ,
L_3 ) ? 2 : 1 ;
}
V_2 -> V_16 =
F_16 ( V_29 , L_4 ) ;
if ( ! F_17 ( V_29 , L_5 ) ||
! F_18 ( V_29 , L_5 ,
L_6 ) ) {
F_19 ( V_29 , L_6 ) ;
V_2 -> V_9 = V_10 ;
} else if ( ! F_18 ( V_29 , L_5 ,
L_7 ) ) {
F_19 ( V_29 , L_7 ) ;
V_2 -> V_9 = V_36 ;
} else {
F_20 ( V_29 , L_8 ) ;
return - V_37 ;
}
F_15 ( V_29 , L_9 , & V_2 -> V_13 ) ;
V_2 -> V_11 =
F_16 ( V_29 , L_10 ) ;
V_2 -> V_5 = F_21 ( V_29 , NULL , V_38 ) ;
if ( F_22 ( V_2 -> V_5 ) ) {
F_20 ( V_29 , L_11 ) ;
return F_23 ( V_2 -> V_5 ) ;
}
if ( V_2 -> V_5 -> V_6 < 2 ) {
F_20 ( V_29 , L_12 ) ;
return - V_37 ;
}
V_12 = F_24 ( V_29 ) ;
if ( ! V_12 )
return - V_35 ;
V_2 -> V_12 = V_12 ;
V_12 -> V_39 = V_27 -> V_39 ;
V_12 -> V_40 . V_41 = V_42 ;
V_12 -> V_29 . V_43 = V_29 ;
if ( V_2 -> V_11 )
F_25 ( V_12 , V_44 , V_2 -> V_13 ) ;
else
F_26 ( V_12 ,
V_2 -> V_13 , 0 , V_2 -> V_17 , 0 , 1 ) ;
switch ( V_32 >> ( V_2 -> V_5 -> V_6 - 2 ) ) {
case 4 :
V_31 = & F_11 ;
V_2 -> V_24 = F_1 ( V_2 ) ;
break;
case 2 :
V_31 = & F_10 ;
V_2 -> V_24 = F_1 ( V_2 ) ;
break;
case 1 :
V_31 = & F_7 ;
break;
default:
F_20 ( V_29 , L_13 ,
V_32 ) ;
return - V_37 ;
}
V_2 -> V_18 =
F_13 ( V_29 ,
sizeof( * V_2 -> V_18 ) * V_2 -> V_5 -> V_6 ,
V_34 ) ;
if ( ! V_2 -> V_18 )
return - V_35 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_6 ; ++ V_3 ) {
V_2 -> V_18 [ V_3 ] = F_27 ( V_2 -> V_5 -> V_8 [ V_3 ] ) ;
V_33 = F_28 ( V_29 , V_2 -> V_18 [ V_3 ] ,
NULL , V_31 ,
V_45 | V_46 |
V_47 ,
V_48 , V_2 ) ;
if ( V_33 ) {
F_20 ( V_29 , L_14 ,
V_2 -> V_18 [ V_3 ] , V_3 ) ;
return V_33 ;
}
}
V_33 = F_29 ( V_12 ) ;
if ( V_33 ) {
F_20 ( V_29 , L_15 ) ;
return V_33 ;
}
F_30 ( V_29 ,
F_16 ( V_29 , L_16 ) ) ;
F_31 ( V_27 , V_2 ) ;
return 0 ;
}
static int T_4 F_32 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_33 ( V_29 ) ;
unsigned int V_3 ;
if ( F_34 ( V_29 ) ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_6 ; ++ V_3 )
F_35 ( V_2 -> V_18 [ V_3 ] ) ;
}
return 0 ;
}
static int T_4 F_36 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_33 ( V_29 ) ;
unsigned int V_3 ;
if ( F_34 ( V_29 ) ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_6 ; ++ V_3 )
F_37 ( V_2 -> V_18 [ V_3 ] ) ;
}
return 0 ;
}
