static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 0 ) ;
F_2 ( V_4 , 0 ) ;
F_3 ( V_2 -> V_5 . V_6 ) ;
F_3 ( V_2 -> V_5 . V_7 ) ;
}
int F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
T_1 V_12 ,
T_1 V_13 ,
T_1 V_14 )
{
struct V_15 * V_16 = (struct V_15 * ) V_11 -> V_17 -> V_16 ;
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_18 ;
struct V_19 * V_6 = V_2 -> V_5 . V_6 ;
struct V_19 * V_7 = V_2 -> V_5 . V_7 ;
struct V_19 * V_20 = V_2 -> V_5 . V_20 ;
struct V_19 * V_21 = V_2 -> V_5 . V_21 ;
struct V_22 * V_23 ;
struct V_19 * V_24 = NULL ;
int V_25 = 0 ;
unsigned int V_26 , V_27 , V_28 ;
T_1 V_29 [ 16 ] ;
T_1 * V_30 = & V_29 [ 0 ] ;
T_1 * V_31 ;
T_1 V_32 ;
bool V_33 = false ;
int V_34 = 0 ;
T_2 V_35 ;
T_3 V_36 ;
T_3 V_37 [ 48 ] ;
if ( ! V_6 || ! V_7 ) {
F_2 ( V_3 , 0 ) ;
F_2 ( V_4 , 0 ) ;
return - V_38 ;
}
if ( ( V_13 != 64 || V_14 != 64 ) && V_12 ) {
F_2 ( V_3 , 0 ) ;
F_2 ( V_4 , 0 ) ;
return - V_39 ;
}
F_5 ( V_6 != V_20 && V_6 != V_21 ) ;
F_5 ( V_7 != V_20 && V_7 != V_21 ) ;
F_5 ( V_20 == V_21 ) ;
V_25 = F_6 ( V_6 , true ) ;
if ( V_25 ) {
F_2 ( V_3 , 0 ) ;
F_2 ( V_4 , 0 ) ;
return V_25 ;
}
V_25 = F_6 ( V_7 , true ) ;
if ( V_25 ) {
F_2 ( V_3 , 0 ) ;
F_2 ( V_4 , 0 ) ;
F_7 ( V_6 ) ;
return V_25 ;
}
if ( ! V_12 ) {
F_1 ( V_2 ) ;
V_25 = 0 ;
goto V_40;
}
if ( ! V_6 -> V_41 ) {
V_25 = F_8 ( V_6 , V_42 ,
& V_2 -> V_5 . V_43 ) ;
if ( V_25 )
goto V_40;
}
if ( ! V_7 -> V_41 ) {
V_25 = F_8 ( V_7 , V_42 ,
& V_2 -> V_5 . V_44 ) ;
if ( V_25 ) {
F_3 ( V_6 ) ;
goto V_40;
}
}
F_9 ( & V_16 -> V_45 ) ;
V_23 = F_10 ( V_16 , V_11 , V_12 ) ;
if ( ! V_23 ) {
F_11 ( & V_16 -> V_45 ) ;
V_25 = - V_46 ;
goto V_40;
}
F_12 ( V_23 ) ;
F_11 ( & V_16 -> V_45 ) ;
V_24 = F_13 ( V_23 ) ;
V_25 = F_6 ( V_24 , true ) ;
if ( V_25 ) {
F_14 ( & V_16 -> V_47 -> V_16 , L_1 ) ;
goto V_40;
}
if ( ! V_24 -> V_48 . V_49 ) {
V_25 = F_15 ( & V_24 -> V_24 , 0 , V_24 -> V_24 . V_50 , & V_24 -> V_48 ) ;
if ( V_25 ) {
F_14 ( & V_16 -> V_47 -> V_16 , L_2 ) ;
goto V_51;
}
}
memset ( & V_29 [ 0 ] , 0 , sizeof( T_1 ) * 16 ) ;
for ( V_26 = 0 ; V_26 < 16384 ; V_26 += 4 ) {
V_32 = F_16 ( V_24 -> V_48 . V_49 + V_26 ) ;
if ( V_32 >> 24 != 0xff &&
V_32 >> 24 != 0x0 ) {
if ( V_52 ) {
F_17 ( & V_16 -> V_47 -> V_16 , L_3 ) ;
F_17 ( & V_16 -> V_47 -> V_16 , L_4 ) ;
V_52 = false ;
}
V_25 = - V_39 ;
goto V_53;
}
if ( V_32 >> 24 == 0x0 )
continue;
V_33 = false ;
for ( V_31 = & V_29 [ 0 ] ; V_31 != V_30 ; V_31 ++ ) {
if ( * V_31 == V_32 ) {
V_33 = true ;
break;
}
}
if ( V_33 )
continue;
if ( V_34 >= 16 ) {
if ( V_54 ) {
F_17 ( & V_16 -> V_47 -> V_16 , L_5 ) ;
F_17 ( & V_16 -> V_47 -> V_16 , L_4 ) ;
V_54 = false ;
}
V_25 = - V_39 ;
goto V_53;
}
* V_30 = V_32 ;
V_30 ++ ;
V_34 ++ ;
}
for ( V_26 = 0 ; V_26 < V_34 ; V_26 ++ ) {
if ( V_26 <= 2 )
V_36 = 0x8 + V_26 * 0x4 ;
else
V_36 = 0x60 + V_26 * 0x3 ;
F_18 ( V_36 , V_29 [ V_26 ] & 0xff ) ;
F_18 ( V_36 + 1 , V_29 [ V_26 ] >> 8 & 0xff ) ;
F_18 ( V_36 + 2 , V_29 [ V_26 ] >> 16 & 0xff ) ;
F_5 ( ( V_29 [ V_26 ] >> 24 & 0xff ) != 0xff ) ;
}
if ( ! V_21 -> V_48 . V_49 ) {
V_25 = F_15 ( & V_21 -> V_24 , 0 ,
V_21 -> V_24 . V_50 ,
& V_21 -> V_48 ) ;
if ( V_25 ) {
F_14 ( & V_16 -> V_47 -> V_16 , L_6 ) ;
goto V_53;
}
}
for ( V_27 = 0 ; V_27 < 64 ; V_27 ++ ) {
memset ( & V_37 [ 0 ] , 0 , 48 ) ;
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ ) {
V_32 = F_16 ( V_24 -> V_48 . V_49 + 4 * ( V_28 + 64 * V_27 ) ) ;
if ( V_32 >> 24 == 0x0 ) {
V_37 [ 47 - V_28 / 8 ] |= 0x80 >> ( V_28 % 8 ) ;
continue;
}
for ( V_26 = 0 ; V_26 < V_34 ; V_26 ++ ) {
if ( V_29 [ V_26 ] == V_32 ) {
if ( V_28 % 2 )
V_37 [ V_28 / 2 ] |= V_26 << 4 ;
else
V_37 [ V_28 / 2 ] |= V_26 ;
break;
}
}
}
F_19 ( V_21 -> V_48 . V_49 + V_27 * 48 , & V_37 [ 0 ] , 48 ) ;
}
if ( V_21 == V_6 )
V_35 = V_2 -> V_5 . V_43 ;
else
V_35 = V_2 -> V_5 . V_44 ;
F_18 ( V_55 , ( T_3 ) ( ( V_35 >> 10 ) & 0xff ) ) ;
F_18 ( V_56 , ( T_3 ) ( ( V_35 >> 18 ) & 0x3f ) ) ;
F_18 ( V_57 , 4 ) ;
if ( V_2 -> V_5 . V_6 == V_2 -> V_5 . V_21 ) {
V_2 -> V_5 . V_21 = V_2 -> V_5 . V_7 ;
V_2 -> V_5 . V_20 = V_2 -> V_5 . V_6 ;
} else if ( V_2 -> V_5 . V_6 == V_2 -> V_5 . V_20 ) {
V_2 -> V_5 . V_21 = V_2 -> V_5 . V_6 ;
V_2 -> V_5 . V_20 = V_2 -> V_5 . V_7 ;
} else {
F_20 () ;
}
V_25 = 0 ;
F_21 ( & V_21 -> V_48 ) ;
V_53:
F_21 ( & V_24 -> V_48 ) ;
V_51:
F_7 ( V_24 ) ;
V_40:
if ( V_25 )
F_1 ( V_2 ) ;
F_7 ( V_6 ) ;
F_7 ( V_7 ) ;
return V_25 ;
}
int F_22 ( struct V_8 * V_9 , int V_58 , int V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 -> V_16 -> V_18 ;
V_58 += 64 ;
V_59 += 64 ;
F_5 ( V_58 <= 0 ) ;
F_5 ( V_59 <= 0 ) ;
F_5 ( V_58 & ~ 0xffff ) ;
F_5 ( V_59 & ~ 0xffff ) ;
F_2 ( V_3 , V_58 & 0xff ) ;
F_2 ( V_4 , ( V_58 >> 8 ) & 0xff ) ;
F_2 ( V_60 , V_59 & 0xff ) ;
F_2 ( V_61 , ( V_59 >> 8 ) & 0xff ) ;
return 0 ;
}
