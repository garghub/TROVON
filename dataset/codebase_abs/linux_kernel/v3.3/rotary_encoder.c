static int F_1 ( struct V_1 * V_2 )
{
int V_3 = ! ! F_2 ( V_2 -> V_4 ) ;
int V_5 = ! ! F_2 ( V_2 -> V_6 ) ;
V_3 ^= V_2 -> V_7 ;
V_5 ^= V_2 -> V_8 ;
return ( ( V_3 << 1 ) | V_5 ) ;
}
static void F_3 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_2 -> V_11 ) {
F_4 ( V_10 -> V_12 ,
V_2 -> V_13 , V_10 -> V_14 ? - 1 : 1 ) ;
} else {
unsigned int V_15 = V_10 -> V_15 ;
if ( V_10 -> V_14 ) {
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
V_10 -> V_15 = V_15 ;
F_5 ( V_10 -> V_12 , V_2 -> V_13 , V_10 -> V_15 ) ;
}
F_6 ( V_10 -> V_12 ) ;
}
static T_1 F_7 ( int V_18 , void * V_19 )
{
struct V_9 * V_10 = V_19 ;
int V_20 ;
V_20 = F_1 ( V_10 -> V_2 ) ;
switch ( V_20 ) {
case 0x0 :
if ( V_10 -> V_21 ) {
F_3 ( V_10 ) ;
V_10 -> V_21 = false ;
}
break;
case 0x1 :
case 0x2 :
if ( V_10 -> V_21 )
V_10 -> V_14 = V_20 - 1 ;
break;
case 0x3 :
V_10 -> V_21 = true ;
break;
}
return V_22 ;
}
static T_1 F_8 ( int V_18 , void * V_19 )
{
struct V_9 * V_10 = V_19 ;
int V_20 ;
V_20 = F_1 ( V_10 -> V_2 ) ;
switch ( V_20 ) {
case 0x00 :
case 0x03 :
if ( V_20 != V_10 -> V_23 ) {
F_3 ( V_10 ) ;
V_10 -> V_23 = V_20 ;
}
break;
case 0x01 :
case 0x02 :
V_10 -> V_14 = ( V_10 -> V_23 + V_20 ) & 0x01 ;
break;
}
return V_22 ;
}
static int T_2 F_9 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 . V_27 ;
struct V_9 * V_10 ;
struct V_28 * V_12 ;
T_3 V_29 ;
int V_30 ;
if ( ! V_2 ) {
F_10 ( & V_25 -> V_26 , L_1 ) ;
return - V_31 ;
}
V_10 = F_11 ( sizeof( struct V_9 ) , V_32 ) ;
V_12 = F_12 () ;
if ( ! V_10 || ! V_12 ) {
F_10 ( & V_25 -> V_26 , L_2 ) ;
V_30 = - V_33 ;
goto V_34;
}
V_10 -> V_12 = V_12 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_35 = F_13 ( V_2 -> V_4 ) ;
V_10 -> V_36 = F_13 ( V_2 -> V_6 ) ;
V_12 -> V_37 = V_25 -> V_37 ;
V_12 -> V_38 . V_39 = V_40 ;
V_12 -> V_26 . V_41 = & V_25 -> V_26 ;
if ( V_2 -> V_11 ) {
V_12 -> V_42 [ 0 ] = F_14 ( V_43 ) ;
V_12 -> V_44 [ 0 ] = F_14 ( V_2 -> V_13 ) ;
} else {
V_12 -> V_42 [ 0 ] = F_14 ( V_45 ) ;
F_15 ( V_10 -> V_12 ,
V_2 -> V_13 , 0 , V_2 -> V_17 , 0 , 1 ) ;
}
V_30 = F_16 ( V_12 ) ;
if ( V_30 ) {
F_10 ( & V_25 -> V_26 , L_3 ) ;
goto V_34;
}
V_30 = F_17 ( V_2 -> V_4 , V_46 ) ;
if ( V_30 ) {
F_10 ( & V_25 -> V_26 , L_4 ,
V_2 -> V_4 ) ;
goto V_47;
}
V_30 = F_18 ( V_2 -> V_4 ) ;
if ( V_30 ) {
F_10 ( & V_25 -> V_26 , L_5 ,
V_2 -> V_4 ) ;
goto V_47;
}
V_30 = F_17 ( V_2 -> V_6 , V_46 ) ;
if ( V_30 ) {
F_10 ( & V_25 -> V_26 , L_4 ,
V_2 -> V_6 ) ;
goto V_48;
}
V_30 = F_18 ( V_2 -> V_6 ) ;
if ( V_30 ) {
F_10 ( & V_25 -> V_26 , L_5 ,
V_2 -> V_6 ) ;
goto V_48;
}
if ( V_2 -> V_49 ) {
V_29 = & F_8 ;
V_10 -> V_23 = F_1 ( V_2 ) ;
} else {
V_29 = & F_7 ;
}
V_30 = F_19 ( V_10 -> V_35 , V_29 ,
V_50 | V_51 ,
V_46 , V_10 ) ;
if ( V_30 ) {
F_10 ( & V_25 -> V_26 , L_6 ,
V_10 -> V_35 ) ;
goto V_52;
}
V_30 = F_19 ( V_10 -> V_36 , V_29 ,
V_50 | V_51 ,
V_46 , V_10 ) ;
if ( V_30 ) {
F_10 ( & V_25 -> V_26 , L_6 ,
V_10 -> V_36 ) ;
goto V_53;
}
F_20 ( V_25 , V_10 ) ;
return 0 ;
V_53:
F_21 ( V_10 -> V_35 , V_10 ) ;
V_52:
F_22 ( V_2 -> V_6 ) ;
V_48:
F_22 ( V_2 -> V_4 ) ;
V_47:
F_23 ( V_12 ) ;
V_12 = NULL ;
V_34:
F_24 ( V_12 ) ;
F_25 ( V_10 ) ;
return V_30 ;
}
static int T_4 F_26 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = F_27 ( V_25 ) ;
struct V_1 * V_2 = V_25 -> V_26 . V_27 ;
F_21 ( V_10 -> V_35 , V_10 ) ;
F_21 ( V_10 -> V_36 , V_10 ) ;
F_22 ( V_2 -> V_4 ) ;
F_22 ( V_2 -> V_6 ) ;
F_23 ( V_10 -> V_12 ) ;
F_20 ( V_25 , NULL ) ;
F_25 ( V_10 ) ;
return 0 ;
}
