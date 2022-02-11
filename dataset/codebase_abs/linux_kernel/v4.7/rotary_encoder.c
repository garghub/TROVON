static unsigned int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_6 ; ++ V_3 ) {
int V_7 = F_2 ( V_2 -> V_5 -> V_8 [ V_3 ] ) ;
if ( V_4 & 1 )
V_7 = ! V_7 ;
V_4 = V_4 << 1 | V_7 ;
}
return V_4 & 3 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 ) {
F_4 ( V_2 -> V_10 ,
V_2 -> V_11 , V_2 -> V_12 ) ;
} else {
unsigned int V_13 = V_2 -> V_13 ;
if ( V_2 -> V_12 < 0 ) {
if ( V_2 -> V_14 )
V_13 += V_2 -> V_15 ;
if ( V_13 )
V_13 -- ;
} else {
if ( V_2 -> V_14 || V_13 < V_2 -> V_15 )
V_13 ++ ;
}
if ( V_2 -> V_14 )
V_13 %= V_2 -> V_15 ;
V_2 -> V_13 = V_13 ;
F_5 ( V_2 -> V_10 , V_2 -> V_11 , V_2 -> V_13 ) ;
}
F_6 ( V_2 -> V_10 ) ;
}
static T_1 F_7 ( int V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
unsigned int V_18 ;
F_8 ( & V_2 -> V_19 ) ;
V_18 = F_1 ( V_2 ) ;
switch ( V_18 ) {
case 0x0 :
if ( V_2 -> V_20 ) {
F_3 ( V_2 ) ;
V_2 -> V_20 = false ;
}
break;
case 0x1 :
case 0x3 :
if ( V_2 -> V_20 )
V_2 -> V_12 = 2 - V_18 ;
break;
case 0x2 :
V_2 -> V_20 = true ;
break;
}
F_9 ( & V_2 -> V_19 ) ;
return V_21 ;
}
static T_1 F_10 ( int V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
unsigned int V_18 ;
F_8 ( & V_2 -> V_19 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 & 1 ) {
V_2 -> V_12 = ( ( V_2 -> V_22 - V_18 + 1 ) % 4 ) - 1 ;
} else {
if ( V_18 != V_2 -> V_22 ) {
F_3 ( V_2 ) ;
V_2 -> V_22 = V_18 ;
}
}
F_9 ( & V_2 -> V_19 ) ;
return V_21 ;
}
static T_1 F_11 ( int V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
unsigned int V_18 ;
F_8 ( & V_2 -> V_19 ) ;
V_18 = F_1 ( V_2 ) ;
if ( ( V_2 -> V_22 + 1 ) % 4 == V_18 )
V_2 -> V_12 = 1 ;
else if ( V_2 -> V_22 == ( V_18 + 1 ) % 4 )
V_2 -> V_12 = - 1 ;
else
goto V_23;
F_3 ( V_2 ) ;
V_23:
V_2 -> V_22 = V_18 ;
F_9 ( & V_2 -> V_19 ) ;
return V_21 ;
}
static int F_12 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = & V_25 -> V_27 ;
struct V_1 * V_2 ;
struct V_28 * V_10 ;
T_2 V_29 ;
T_3 V_30 ;
unsigned int V_3 ;
int V_31 ;
V_2 = F_13 ( V_27 , sizeof( struct V_1 ) , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
F_14 ( & V_2 -> V_19 ) ;
F_15 ( V_27 , L_1 , & V_2 -> V_15 ) ;
V_31 = F_15 ( V_27 , L_2 ,
& V_30 ) ;
if ( V_31 ) {
V_30 = F_16 ( V_27 ,
L_3 ) ? 2 : 1 ;
}
V_2 -> V_14 =
F_16 ( V_27 , L_4 ) ;
F_15 ( V_27 , L_5 , & V_2 -> V_11 ) ;
V_2 -> V_9 =
F_16 ( V_27 , L_6 ) ;
V_2 -> V_5 = F_17 ( V_27 , NULL , V_34 ) ;
if ( F_18 ( V_2 -> V_5 ) ) {
F_19 ( V_27 , L_7 ) ;
return F_20 ( V_2 -> V_5 ) ;
}
if ( V_2 -> V_5 -> V_6 < 2 ) {
F_19 ( V_27 , L_8 ) ;
return - V_35 ;
}
V_10 = F_21 ( V_27 ) ;
if ( ! V_10 )
return - V_33 ;
V_2 -> V_10 = V_10 ;
V_10 -> V_36 = V_25 -> V_36 ;
V_10 -> V_37 . V_38 = V_39 ;
V_10 -> V_27 . V_40 = V_27 ;
if ( V_2 -> V_9 )
F_22 ( V_10 , V_41 , V_2 -> V_11 ) ;
else
F_23 ( V_10 ,
V_2 -> V_11 , 0 , V_2 -> V_15 , 0 , 1 ) ;
switch ( V_30 >> ( V_2 -> V_5 -> V_6 - 2 ) ) {
case 4 :
V_29 = & F_11 ;
V_2 -> V_22 = F_1 ( V_2 ) ;
break;
case 2 :
V_29 = & F_10 ;
V_2 -> V_22 = F_1 ( V_2 ) ;
break;
case 1 :
V_29 = & F_7 ;
break;
default:
F_19 ( V_27 , L_9 ,
V_30 ) ;
return - V_35 ;
}
V_2 -> V_16 =
F_13 ( V_27 ,
sizeof( * V_2 -> V_16 ) * V_2 -> V_5 -> V_6 ,
V_32 ) ;
if ( ! V_2 -> V_16 )
return - V_33 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_6 ; ++ V_3 ) {
V_2 -> V_16 [ V_3 ] = F_24 ( V_2 -> V_5 -> V_8 [ V_3 ] ) ;
V_31 = F_25 ( V_27 , V_2 -> V_16 [ V_3 ] ,
NULL , V_29 ,
V_42 | V_43 |
V_44 ,
V_45 , V_2 ) ;
if ( V_31 ) {
F_19 ( V_27 , L_10 ,
V_2 -> V_16 [ V_3 ] , V_3 ) ;
return V_31 ;
}
}
V_31 = F_26 ( V_10 ) ;
if ( V_31 ) {
F_19 ( V_27 , L_11 ) ;
return V_31 ;
}
F_27 ( V_27 ,
F_16 ( V_27 , L_12 ) ) ;
F_28 ( V_25 , V_2 ) ;
return 0 ;
}
static int T_4 F_29 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_30 ( V_27 ) ;
unsigned int V_3 ;
if ( F_31 ( V_27 ) ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_6 ; ++ V_3 )
F_32 ( V_2 -> V_16 [ V_3 ] ) ;
}
return 0 ;
}
static int T_4 F_33 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_30 ( V_27 ) ;
unsigned int V_3 ;
if ( F_31 ( V_27 ) ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_6 ; ++ V_3 )
F_34 ( V_2 -> V_16 [ V_3 ] ) ;
}
return 0 ;
}
