int F_1 ( void )
{
const char * V_1 , * V_2 , * V_3 , * V_4 ;
struct V_5 * V_6 ;
int V_7 , V_8 , V_9 , V_10 , V_11 ;
T_1 V_12 , V_13 , V_14 , V_15 , V_16 ;
T_2 V_17 , V_18 , V_19 , V_20 ;
enum V_21 V_22 ;
enum V_23 V_24 ;
for ( V_7 = 0 , V_11 = 0 ; V_7 < V_25 ; V_7 ++ ) {
V_17 = 0x0000 ;
switch ( V_7 ) {
case V_26 : {
V_17 = 0x1F & V_26 ;
V_1 = L_1 ;
V_24 = V_27 ;
break;
}
case V_28 : {
V_17 = 0x1F & V_28 ;
V_1 = L_2 ;
V_24 = V_27 ;
break;
}
case V_29 : {
V_17 = 0x1F & V_29 ;
V_1 = L_3 ;
V_24 = V_27 ;
break;
}
case V_30 : {
V_17 = 0x1F & V_30 ;
V_1 = L_4 ;
V_24 = V_27 ;
break;
}
case V_31 : {
V_17 = 0x1F & V_31 ;
V_1 = L_5 ;
V_24 = V_27 ;
break;
}
case V_32 : {
V_17 = 0x1F & V_32 ;
V_1 = L_6 ;
V_24 = V_33 ;
break;
}
case V_34 : {
V_17 = 0x1F & V_34 ;
V_1 = L_7 ;
V_24 = V_33 ;
break;
}
case V_35 : {
V_17 = 0x1F & V_35 ;
V_1 = L_8 ;
V_24 = V_33 ;
break;
}
case V_36 : {
V_17 = 0x1F & V_32 ;
V_1 = L_9 ;
V_24 = V_33 ;
break;
}
case V_37 : {
V_17 = 0x1F & V_37 ;
V_1 = L_10 ;
V_24 = V_33 ;
break;
}
case V_38 : {
V_17 = 0x001F & V_38 ;
V_17 |= 0x0200 ;
V_1 = L_11 ;
V_24 = V_27 ;
break;
}
case V_39 : {
V_17 = 0x001F & V_39 ;
V_17 |= 0x0200 ;
V_1 = L_12 ;
V_24 = V_27 ;
break;
}
case V_40 : {
V_17 = 0x001F & V_40 ;
V_17 |= 0x0200 ;
V_1 = L_13 ;
V_24 = V_27 ;
break;
}
case V_41 : {
V_17 = 0x001F & V_41 ;
V_17 |= 0x0200 ;
V_1 = L_14 ;
V_24 = V_27 ;
break;
}
case V_42 : {
V_17 = 0x001F & V_42 ;
V_17 |= 0x0200 ;
V_1 = L_15 ;
V_24 = V_27 ;
break;
}
case V_43 : {
V_17 = 0x001F & V_43 ;
V_17 |= 0x0200 ;
V_1 = L_16 ;
V_24 = V_33 ;
break;
}
case V_44 : {
V_17 = 0x001F & V_44 ;
V_17 |= 0x0200 ;
V_1 = L_17 ;
V_24 = V_33 ;
break;
}
case V_45 : {
V_17 = 0x001F & V_45 ;
V_17 |= 0x0200 ;
V_1 = L_18 ;
V_24 = V_33 ;
break;
}
case V_46 : {
V_17 = 0x001F & V_46 ;
V_17 |= 0x0200 ;
V_1 = L_19 ;
V_24 = V_33 ;
break;
}
case V_47 : {
V_17 = 0x001F & V_47 ;
V_17 |= 0x0200 ;
V_1 = L_20 ;
V_24 = V_33 ;
break;
}
default:
return - 1 ;
}
for ( V_8 = 0 ; V_8 < V_48 ; V_8 ++ ) {
V_18 = 0x0000 ;
switch ( V_8 ) {
case V_49 : {
if ( 0x1 & V_17 )
continue;
V_2 = L_21 ;
V_12 = 720 ;
V_13 = 576 ;
break;
}
case V_50 : {
if ( 0x1 & V_17 )
continue;
V_2 = L_22 ;
V_12 = 704 ;
V_13 = 576 ;
break;
}
case V_51 : {
V_2 = L_23 ;
V_12 = 640 ;
V_13 = 480 ;
break;
}
case V_52 : {
if ( ! ( 0x1 & V_17 ) )
continue;
V_2 = L_24 ;
V_12 = 720 ;
V_13 = 480 ;
break;
}
case V_53 : {
if ( 0x1 & V_17 )
continue;
V_2 = L_25 ;
V_12 = 360 ;
V_13 = 288 ;
V_18 = 0x0800 ;
break;
}
case V_54 : {
V_2 = L_26 ;
V_12 = 320 ;
V_13 = 240 ;
V_18 = 0x0800 ;
break;
}
case V_55 : {
if ( ! ( 0x1 & V_17 ) )
continue;
V_2 = L_27 ;
V_12 = 360 ;
V_13 = 240 ;
V_18 = 0x0800 ;
break;
}
default:
return - 2 ;
}
for ( V_9 = 0 ; V_9 < V_56 ; V_9 ++ ) {
V_19 = 0x0000 ;
switch ( V_9 ) {
case V_57 : {
V_3 = F_2 ( V_57 ) ;
V_14 = V_58 ;
V_19 |= ( 0x02 << 5 ) ;
break;
}
case V_59 : {
V_3 = F_2 ( V_59 ) ;
V_14 = V_60 ;
V_19 |= ( 0x02 << 5 ) ;
V_19 |= 0x0100 ;
break;
}
case V_61 : {
V_3 = F_2 ( V_61 ) ;
V_14 = V_62 ;
V_19 |= ( 0x03 << 5 ) ;
break;
}
case V_63 : {
V_3 = F_2 ( V_63 ) ;
V_14 = V_64 ;
V_19 |= ( 0x04 << 5 ) ;
break;
}
case V_65 : {
V_3 = F_2 ( V_65 ) ;
V_14 = V_66 ;
V_19 |= ( 0x03 << 5 ) ;
V_19 |= 0x0100 ;
break;
}
case V_67 : {
V_3 = F_2 ( V_67 ) ;
V_14 = V_68 ;
V_19 |= ( 0x04 << 5 ) ;
V_19 |= 0x0100 ;
break;
}
default:
return - 3 ;
}
V_15 = V_12 * ( ( V_19 & 0x00F0 ) >> 4 ) ;
V_16 = V_15 * V_13 ;
for ( V_10 = 0 ; V_10 < V_69 ; V_10 ++ ) {
V_20 = 0x0000 ;
switch ( V_10 ) {
case V_70 : {
V_4 = L_28 ;
V_22 = V_71 ;
break;
}
case V_72 : {
V_4 = L_29 ;
V_20 |= 0x1000 ;
V_22 = V_73 ;
break;
}
default:
return - 4 ;
}
if ( V_74 <= V_11 )
return - 5 ;
strcpy ( V_75 [ V_11 ] . V_76 , V_1 ) ;
strcat ( V_75 [ V_11 ] . V_76 , V_2 ) ;
strcat ( V_75 [ V_11 ] . V_76 , L_30 ) ;
strcat ( V_75 [ V_11 ] . V_76 , V_3 ) ;
strcat ( V_75 [ V_11 ] . V_76 , V_4 ) ;
V_75 [ V_11 ] . V_77 =
V_17 | V_18 | V_19 | V_20 ;
V_6 = & V_75 [ V_11 ] . V_5 ;
V_6 -> type = V_78 ;
V_6 -> V_6 . V_79 . V_12 = V_12 ;
V_6 -> V_6 . V_79 . V_13 = V_13 ;
V_6 -> V_6 . V_79 . V_14 = V_14 ;
V_6 -> V_6 . V_79 . V_22 = V_22 ;
V_6 -> V_6 . V_79 . V_15 = V_15 ;
V_6 -> V_6 . V_79 . V_16 = V_16 ;
V_6 -> V_6 . V_79 . V_24 = V_24 ;
V_6 -> V_6 . V_79 . V_80 = 0 ;
V_11 ++ ;
}
}
}
}
if ( ( 1 + V_74 ) <= V_11 )
return - 6 ;
V_75 [ V_11 ] . V_77 = 0xFFFF ;
return V_11 ;
}
