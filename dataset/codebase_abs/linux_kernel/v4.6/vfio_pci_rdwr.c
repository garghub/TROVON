static T_1 F_1 ( void T_2 * V_1 , char T_3 * V_2 ,
T_4 V_3 , T_5 V_4 , T_5 V_5 ,
T_5 V_6 , bool V_7 )
{
T_1 V_8 = 0 ;
while ( V_4 ) {
T_5 V_9 , V_10 ;
if ( V_3 < V_5 )
V_9 = F_2 ( V_4 , ( T_5 ) ( V_5 - V_3 ) ) ;
else if ( V_3 >= V_6 )
V_9 = V_4 ;
else
V_9 = 0 ;
if ( V_9 >= 4 && ! ( V_3 % 4 ) ) {
T_6 V_11 ;
if ( V_7 ) {
if ( F_3 ( & V_11 , V_2 , 4 ) )
return - V_12 ;
F_4 ( F_5 ( V_11 ) , V_1 + V_3 ) ;
} else {
V_11 = F_6 ( F_7 ( V_1 + V_3 ) ) ;
if ( F_8 ( V_2 , & V_11 , 4 ) )
return - V_12 ;
}
V_10 = 4 ;
} else if ( V_9 >= 2 && ! ( V_3 % 2 ) ) {
T_7 V_11 ;
if ( V_7 ) {
if ( F_3 ( & V_11 , V_2 , 2 ) )
return - V_12 ;
F_9 ( F_10 ( V_11 ) , V_1 + V_3 ) ;
} else {
V_11 = F_11 ( F_12 ( V_1 + V_3 ) ) ;
if ( F_8 ( V_2 , & V_11 , 2 ) )
return - V_12 ;
}
V_10 = 2 ;
} else if ( V_9 ) {
T_8 V_11 ;
if ( V_7 ) {
if ( F_3 ( & V_11 , V_2 , 1 ) )
return - V_12 ;
F_13 ( V_11 , V_1 + V_3 ) ;
} else {
V_11 = F_14 ( V_1 + V_3 ) ;
if ( F_8 ( V_2 , & V_11 , 1 ) )
return - V_12 ;
}
V_10 = 1 ;
} else {
V_10 = F_2 ( V_4 , ( T_5 ) ( V_6 - V_3 ) ) ;
if ( ! V_7 ) {
T_8 V_11 = 0xFF ;
T_5 V_13 ;
for ( V_13 = 0 ; V_13 < V_10 ; V_13 ++ )
if ( F_8 ( V_2 + V_13 , & V_11 , 1 ) )
return - V_12 ;
}
}
V_4 -= V_10 ;
V_8 += V_10 ;
V_3 += V_10 ;
V_2 += V_10 ;
}
return V_8 ;
}
T_1 F_15 ( struct V_14 * V_15 , char T_3 * V_2 ,
T_5 V_4 , T_4 * V_16 , bool V_7 )
{
struct V_17 * V_18 = V_15 -> V_18 ;
T_4 V_19 = * V_16 & V_20 ;
int V_21 = F_16 ( * V_16 ) ;
T_5 V_5 = 0 , V_6 = 0 ;
T_9 V_22 ;
void T_2 * V_1 ;
T_1 V_8 ;
if ( F_17 ( V_18 , V_21 ) )
V_22 = F_18 ( V_18 , V_21 ) ;
else if ( V_21 == V_23 &&
V_18 -> V_24 [ V_21 ] . V_25 & V_26 )
V_22 = 0x20000 ;
else
return - V_27 ;
if ( V_19 >= V_22 )
return - V_27 ;
V_4 = F_2 ( V_4 , ( T_5 ) ( V_22 - V_19 ) ) ;
if ( V_21 == V_23 ) {
V_1 = F_19 ( V_18 , & V_5 ) ;
if ( ! V_1 )
return - V_28 ;
V_6 = V_22 ;
} else if ( ! V_15 -> V_29 [ V_21 ] ) {
int V_30 ;
V_30 = F_20 ( V_18 , 1 << V_21 , L_1 ) ;
if ( V_30 )
return V_30 ;
V_1 = F_21 ( V_18 , V_21 , 0 ) ;
if ( ! V_1 ) {
F_22 ( V_18 , 1 << V_21 ) ;
return - V_28 ;
}
V_15 -> V_29 [ V_21 ] = V_1 ;
} else
V_1 = V_15 -> V_29 [ V_21 ] ;
if ( V_21 == V_15 -> V_31 ) {
V_5 = V_15 -> V_32 ;
V_6 = V_15 -> V_32 + V_15 -> V_33 ;
}
V_8 = F_1 ( V_1 , V_2 , V_19 , V_4 , V_5 , V_6 , V_7 ) ;
if ( V_8 >= 0 )
* V_16 += V_8 ;
if ( V_21 == V_23 )
F_23 ( V_18 , V_1 ) ;
return V_8 ;
}
T_1 F_24 ( struct V_14 * V_15 , char T_3 * V_2 ,
T_5 V_4 , T_4 * V_16 , bool V_7 )
{
int V_30 ;
T_4 V_3 , V_19 = * V_16 & V_20 ;
void T_2 * V_34 = NULL ;
unsigned int V_35 ;
bool V_36 ;
T_1 V_8 ;
if ( ! V_15 -> V_37 )
return - V_27 ;
switch ( V_19 ) {
case 0xa0000 ... 0xbffff :
V_4 = F_2 ( V_4 , ( T_5 ) ( 0xc0000 - V_19 ) ) ;
V_34 = F_25 ( 0xa0000 , 0xbffff - 0xa0000 + 1 ) ;
V_3 = V_19 - 0xa0000 ;
V_35 = V_38 ;
V_36 = false ;
break;
case 0x3b0 ... 0x3bb :
V_4 = F_2 ( V_4 , ( T_5 ) ( 0x3bc - V_19 ) ) ;
V_34 = F_26 ( 0x3b0 , 0x3bb - 0x3b0 + 1 ) ;
V_3 = V_19 - 0x3b0 ;
V_35 = V_39 ;
V_36 = true ;
break;
case 0x3c0 ... 0x3df :
V_4 = F_2 ( V_4 , ( T_5 ) ( 0x3e0 - V_19 ) ) ;
V_34 = F_26 ( 0x3c0 , 0x3df - 0x3c0 + 1 ) ;
V_3 = V_19 - 0x3c0 ;
V_35 = V_39 ;
V_36 = true ;
break;
default:
return - V_27 ;
}
if ( ! V_34 )
return - V_28 ;
V_30 = F_27 ( V_15 -> V_18 , V_35 ) ;
if ( V_30 ) {
V_36 ? F_28 ( V_34 ) : F_29 ( V_34 ) ;
return V_30 ;
}
V_8 = F_1 ( V_34 , V_2 , V_3 , V_4 , 0 , 0 , V_7 ) ;
F_30 ( V_15 -> V_18 , V_35 ) ;
V_36 ? F_28 ( V_34 ) : F_29 ( V_34 ) ;
if ( V_8 >= 0 )
* V_16 += V_8 ;
return V_8 ;
}
