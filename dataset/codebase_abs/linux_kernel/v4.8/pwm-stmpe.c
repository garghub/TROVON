static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_6 ;
int V_7 ;
V_7 = F_4 ( V_1 -> V_8 , V_9 ) ;
if ( V_7 < 0 ) {
F_5 ( V_3 -> V_10 , L_1 ,
V_5 -> V_11 ) ;
return V_7 ;
}
V_6 = V_7 | F_6 ( V_5 -> V_11 ) ;
V_7 = F_7 ( V_1 -> V_8 , V_9 , V_6 ) ;
if ( V_7 ) {
F_5 ( V_3 -> V_10 , L_2 ,
V_5 -> V_11 ) ;
return V_7 ;
}
return 0 ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_6 ;
int V_7 ;
V_7 = F_4 ( V_1 -> V_8 , V_9 ) ;
if ( V_7 < 0 ) {
F_5 ( V_3 -> V_10 , L_1 ,
V_5 -> V_11 ) ;
return;
}
V_6 = V_7 & ~ F_6 ( V_5 -> V_11 ) ;
V_7 = F_7 ( V_1 -> V_8 , V_9 , V_6 ) ;
if ( V_7 ) {
F_5 ( V_3 -> V_10 , L_2 ,
V_5 -> V_11 ) ;
return;
}
}
static int F_9 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_12 , int V_13 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_14 , V_15 ;
T_2 V_16 [ 3 ] = {
V_17 ,
V_18 ,
V_18 ,
} ;
T_1 V_19 ;
int V_7 ;
if ( F_10 ( V_5 ) ) {
F_8 ( V_3 , V_5 ) ;
} else {
V_15 = V_5 -> V_11 ;
if ( V_1 -> V_8 -> V_20 == V_21 ||
V_1 -> V_8 -> V_20 == V_22 )
V_15 += V_23 ;
V_7 = F_11 ( V_1 -> V_8 , F_6 ( V_15 ) ,
V_24 ) ;
if ( V_7 ) {
F_5 ( V_3 -> V_10 , L_3 ,
V_5 -> V_11 ) ;
return V_7 ;
}
}
switch ( V_5 -> V_11 ) {
case 0 :
V_19 = V_25 ;
break;
case 1 :
V_19 = V_26 ;
break;
case 2 :
V_19 = V_26 ;
break;
default:
return - V_27 ;
}
F_12 ( V_3 -> V_10 , L_4 ,
V_5 -> V_11 , V_12 , V_13 ) ;
if ( V_12 == 0 ) {
if ( V_1 -> V_8 -> V_20 == V_21 )
V_16 [ 0 ] = V_17 ;
if ( V_1 -> V_8 -> V_20 == V_22 )
V_16 [ 0 ] = V_28 | 0xff ;
V_1 -> V_29 = 0x00 ;
} else if ( V_12 == V_13 ) {
if ( V_1 -> V_8 -> V_20 == V_21 )
V_16 [ 0 ] = V_30 ;
if ( V_1 -> V_8 -> V_20 == V_22 )
V_16 [ 0 ] = V_28 | 0x00 ;
V_1 -> V_29 = 0xff ;
} else {
T_1 V_6 , V_31 = V_1 -> V_29 ;
unsigned long V_32 ;
V_32 = V_12 * 256 ;
V_32 = F_13 ( V_32 , V_13 ) ;
V_6 = V_32 ;
if ( V_6 == V_31 ) {
if ( F_10 ( V_5 ) )
F_3 ( V_3 , V_5 ) ;
return 0 ;
} else if ( V_1 -> V_8 -> V_20 == V_22 ) {
V_16 [ 0 ] = V_28 | V_6 ;
V_16 [ 1 ] = 0x0000 ;
} else if ( V_1 -> V_8 -> V_20 == V_21 ) {
T_2 V_33 = 0x0000 ;
if ( V_31 < V_6 )
V_33 = V_34 | ( V_6 - V_31 ) ;
else
V_33 = V_35 | ( V_31 - V_6 ) ;
V_16 [ 0 ] = V_36 | V_37 | V_33 ;
V_16 [ 1 ] = V_38 ;
}
F_12 ( V_3 -> V_10 ,
L_5 ,
V_5 -> V_11 , V_6 , V_31 , V_16 [ 0 ] , V_16 [ 1 ] ,
V_16 [ 2 ] ) ;
V_1 -> V_29 = V_6 ;
}
for ( V_14 = 0 ; V_14 < F_14 ( V_16 ) ; V_14 ++ ) {
T_1 V_6 ;
V_6 = ( V_16 [ V_14 ] >> 8 ) & 0xff ;
V_7 = F_7 ( V_1 -> V_8 , V_19 , V_6 ) ;
if ( V_7 ) {
F_5 ( V_3 -> V_10 , L_6 ,
V_19 , V_7 ) ;
return V_7 ;
}
V_6 = V_16 [ V_14 ] & 0xff ;
V_7 = F_7 ( V_1 -> V_8 , V_19 , V_6 ) ;
if ( V_7 ) {
F_5 ( V_3 -> V_10 , L_6 ,
V_19 , V_7 ) ;
return V_7 ;
}
}
if ( F_10 ( V_5 ) )
F_3 ( V_3 , V_5 ) ;
F_15 ( 200 ) ;
F_12 ( V_3 -> V_10 , L_7 , V_5 -> V_11 , V_14 ) ;
return 0 ;
}
static int T_3 F_16 ( struct V_39 * V_40 )
{
struct V_8 * V_8 = F_17 ( V_40 -> V_10 . V_41 ) ;
struct V_1 * V_5 ;
int V_7 ;
V_5 = F_18 ( & V_40 -> V_10 , sizeof( * V_5 ) , V_42 ) ;
if ( ! V_5 )
return - V_43 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_3 . V_10 = & V_40 -> V_10 ;
V_5 -> V_3 . V_44 = - 1 ;
if ( V_8 -> V_20 == V_21 || V_8 -> V_20 == V_22 ) {
V_5 -> V_3 . V_45 = & V_46 ;
V_5 -> V_3 . V_47 = 3 ;
} else {
if ( V_8 -> V_20 == V_48 )
F_5 ( & V_40 -> V_10 , L_8 ) ;
else
F_5 ( & V_40 -> V_10 , L_9 ) ;
return - V_27 ;
}
V_7 = F_19 ( V_8 , V_24 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_20 ( & V_5 -> V_3 ) ;
if ( V_7 ) {
F_21 ( V_8 , V_24 ) ;
return V_7 ;
}
F_22 ( V_40 , V_5 ) ;
return 0 ;
}
