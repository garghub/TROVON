static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
const char * V_4 ;
T_1 V_5 , V_6 , V_7 ;
struct V_8 * * V_9 ;
V_3 = F_2 ( V_2 , L_1 , L_2 ) ;
if ( V_3 < 0 )
return;
V_4 = F_3 ( V_2 , V_3 ) ;
V_10 = F_4 ( sizeof( * V_10 ) , V_11 ) ;
if ( ! V_10 )
return;
V_9 = V_10 -> V_12 ;
for ( V_3 = 0 ; V_3 < V_13 ; ++ V_3 )
V_9 [ V_3 ] = F_5 ( - V_14 ) ;
V_10 -> V_15 = F_6 ( V_2 , 0 ) ;
F_7 ( V_10 -> V_15 == NULL ) ;
V_5 = ( F_8 ( V_10 -> V_15 ) >> 6 ) & 3 ;
switch ( V_5 ) {
case 0 :
V_6 = 4 ;
V_7 = 85 ;
break;
case 1 :
V_6 = 6 ;
V_7 = 112 ;
break;
case 2 :
V_6 = 4 ;
V_7 = 64 ;
break;
case 3 :
V_6 = 8 ;
V_7 = 106 ;
break;
}
V_9 [ V_16 ] =
F_9 ( NULL , L_3 , V_4 , 0 , V_7 ,
V_6 ) ;
V_9 [ V_17 ] =
F_9 ( NULL , L_4 , L_3 , 0 , 1 , 2 ) ;
V_9 [ V_18 ] =
F_9 ( NULL , L_5 , L_3 , 0 , 1 , 8 ) ;
V_9 [ V_19 ] =
F_10 ( NULL , L_6 , V_4 , 0 ,
50000000 ) ;
V_9 [ V_20 ] =
F_9 ( NULL , L_7 , L_3 , 0 , 1 , 8 ) ;
V_9 [ V_21 ] =
F_10 ( NULL , L_8 , V_4 , 0 ,
50000000 ) ;
V_9 [ V_22 ] =
F_9 ( NULL , L_9 , L_3 , 0 , 1 , 8 ) ;
V_10 -> V_23 . V_9 = V_10 -> V_12 ;
V_10 -> V_23 . V_24 = V_13 ;
F_11 ( V_2 , V_25 , & V_10 -> V_23 ) ;
}
static int F_12 ( struct V_26 * V_27 )
{
int V_28 ;
struct V_1 * V_2 = V_27 -> V_29 . V_30 ;
struct V_31 * V_29 = & V_27 -> V_29 ;
struct V_8 * * V_9 = V_10 -> V_12 ;
const char * V_4 ;
const char * V_32 = NULL ;
const char * V_33 [ 2 ] = { NULL , NULL } ;
const char * V_34 [ 2 ] ;
T_1 V_35 ;
int V_3 ;
int V_36 = 0 ;
V_28 = F_2 ( V_2 , L_1 , L_2 ) ;
if ( V_28 < 0 )
return - V_37 ;
V_4 = F_3 ( V_2 , V_28 ) ;
V_28 = F_2 ( V_2 , L_1 , L_10 ) ;
if ( V_28 >= 0 )
V_32 = F_3 ( V_2 , V_28 ) ;
V_28 = F_2 ( V_2 , L_1 , L_11 ) ;
if ( V_28 >= 0 )
V_33 [ 0 ] = F_3 ( V_2 , V_28 ) ;
V_28 = F_2 ( V_2 , L_1 , L_12 ) ;
if ( V_28 >= 0 )
V_33 [ 1 ] = F_3 ( V_2 , V_28 ) ;
F_13 ( & V_10 -> V_38 ) ;
V_9 [ V_39 ] =
F_9 ( V_29 , L_13 , L_3 , 0 , 1 , 8 ) ;
V_9 [ V_40 ] =
F_10 ( V_29 , L_14 , V_4 , 0 ,
100000000 ) ;
V_9 [ V_41 ] =
F_9 ( V_29 , L_15 , L_3 , 0 , 1 , 4 ) ;
V_9 [ V_42 ] =
F_9 ( V_29 , L_16 , L_3 , 0 , 1 , 4 ) ;
V_9 [ V_43 ] =
F_10 ( V_29 , L_17 , V_4 , 0 ,
100000000 ) ;
V_9 [ V_44 ] =
F_10 ( V_29 , L_18 , V_4 , 0 ,
100000000 ) ;
V_9 [ V_45 ] =
F_10 ( V_29 , L_19 , V_4 , 0 ,
100000000 ) ;
V_9 [ V_46 ] =
F_9 ( V_29 , L_20 , L_3 , 0 , 1 , 8 ) ;
for ( V_3 = 0 ; V_3 < V_47 ; ++ V_3 ) {
if ( V_32 && V_33 [ V_3 ] ) {
V_34 [ 0 ] = V_33 [ V_3 ] ;
V_34 [ 1 ] = V_32 ;
V_9 [ V_48 [ V_3 ] ] =
F_14 ( V_29 , V_49 [ V_3 ] ,
V_34 , 2 ,
V_50 |
V_51 ,
V_10 -> V_15 + 0x14 , V_3 , 1 ,
0 , & V_10 -> V_38 ) ;
} else if ( V_33 [ V_3 ] ) {
V_35 = F_8 ( V_10 -> V_15 + 0x14 ) ;
V_35 &= ~ F_15 ( V_3 ) ;
F_16 ( V_35 , V_10 -> V_15 + 0x14 ) ;
V_9 [ V_48 [ V_3 ] ] =
F_9 ( V_29 , V_49 [ V_3 ] ,
V_33 [ V_3 ] , 0 , 1 ,
1 ) ;
} else if ( V_32 ) {
V_35 = F_8 ( V_10 -> V_15 + 0x14 ) ;
V_35 |= F_15 ( V_3 ) ;
F_16 ( V_35 , V_10 -> V_15 + 0x14 ) ;
V_9 [ V_48 [ V_3 ] ] =
F_9 ( V_29 , V_49 [ V_3 ] ,
V_32 , 0 , 1 , 1 ) ;
}
}
V_9 [ V_52 ] =
F_10 ( V_29 , L_21 , V_4 , 0 , 100000000 ) ;
V_9 [ V_53 ] =
F_10 ( V_29 , L_22 , V_4 , 0 ,
100000000 ) ;
V_9 [ V_54 ] =
F_10 ( V_29 , L_23 , V_4 , 0 ,
600000000 ) ;
for ( V_3 = 0 ; V_3 < V_13 ; ++ V_3 ) {
if ( F_17 ( V_9 [ V_3 ] ) && F_18 ( V_9 [ V_3 ] ) != - V_14 ) {
F_19 ( V_29 ,
L_24 ,
V_3 , F_18 ( V_9 [ V_3 ] ) ) ;
V_36 = F_18 ( V_9 [ V_3 ] ) ;
}
}
return V_36 ;
}
