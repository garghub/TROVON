static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_2 V_5 , T_1 * V_6 , T_2 V_7 )
{
T_2 V_8 = V_4 [ 0 ] ;
T_2 V_9 = V_3 << ( 8 + 1 ) ;
int V_10 = ( V_6 == NULL || V_7 == 0 ) ;
T_1 V_11 , type ;
F_2 ( L_1 ,
V_4 [ 1 ] , V_4 [ 0 ] , V_5 - 1 ) ;
if ( V_10 && V_5 >= 2 ) {
V_11 = V_12 ;
type = V_13 ;
F_3 ( 20 ) ;
return F_4 ( V_2 -> V_14 , F_5 ( V_2 -> V_14 , 0 ) ,
V_11 , type , V_9 , V_8 ,
& V_4 [ 1 ] , V_5 - 1 , 2000 ) ;
}
F_2 ( L_2 ) ;
return - V_15 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_2 V_5 , T_1 * V_6 , T_2 V_7 )
{
T_2 V_8 ;
T_2 V_9 = V_3 << ( 8 + 1 ) ;
int V_10 = ( V_6 == NULL || V_7 == 0 ) ;
T_1 V_11 , type ;
unsigned int V_16 ;
if ( V_3 == V_17 . V_18 &&
V_4 [ 0 ] == V_19 )
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
if ( V_10 ) {
V_11 = V_20 ;
type = V_13 ;
V_16 = F_5 ( V_2 -> V_14 , 0 ) ;
} else {
V_11 = V_21 ;
type = V_22 ;
V_16 = F_7 ( V_2 -> V_14 , 0 ) ;
}
switch ( V_5 ) {
case 1 :
V_8 = V_4 [ 0 ] ;
break;
case 2 :
V_8 = V_4 [ 0 ] ;
V_9 = V_9 + V_4 [ 1 ] ;
break;
case 3 :
V_8 = ( V_4 [ 2 ] << 8 ) | V_4 [ 0 ] ;
V_9 = V_9 + V_4 [ 1 ] ;
break;
default:
F_2 ( L_3 , V_5 ) ;
return - V_15 ;
}
F_8 ( 1 ) ;
return F_4 ( V_2 -> V_14 , V_16 , V_11 , type ,
V_9 , V_8 , V_6 , V_7 , 2000 ) ;
}
static int F_9 ( struct V_23 * V_24 , struct V_25 V_26 [] ,
int V_27 )
{
struct V_1 * V_2 = F_10 ( V_24 ) ;
int V_28 ;
if ( V_27 > 2 )
return - V_15 ;
if ( F_11 ( & V_2 -> V_29 ) < 0 )
return - V_30 ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
if ( V_28 + 1 < V_27 && ( V_26 [ V_28 + 1 ] . V_31 & V_32 ) ) {
if ( F_6 ( V_2 , V_26 [ V_28 ] . V_3 ,
V_26 [ V_28 ] . V_33 , V_26 [ V_28 ] . V_34 ,
V_26 [ V_28 + 1 ] . V_33 , V_26 [ V_28 + 1 ] . V_34 ) < 0 )
break;
V_28 ++ ;
} else
if ( F_6 ( V_2 , V_26 [ V_28 ] . V_3 , V_26 [ V_28 ] . V_33 ,
V_26 [ V_28 ] . V_34 , NULL , 0 ) < 0 )
break;
}
F_12 ( & V_2 -> V_29 ) ;
return V_28 ;
}
static T_3 F_13 ( struct V_23 * V_35 )
{
return V_36 ;
}
static int F_14 ( struct V_37 * V_24 ,
T_3 V_38 , int V_39 )
{
int V_28 ;
int V_40 ;
struct V_25 V_26 ;
T_1 * V_33 ;
T_3 V_41 ;
T_1 V_42 = ( V_39 ) ? V_43 : 0 ;
V_33 = F_15 ( 2 , V_44 ) ;
if ( ! V_33 )
return - V_45 ;
V_26 . V_3 = 0x00 ;
V_26 . V_31 = 0 ;
V_26 . V_34 = 2 ;
V_26 . V_33 = V_33 ;
V_33 [ 0 ] = 0x00 ;
V_33 [ 1 ] = V_42 | V_46 | V_47 ;
V_40 = F_9 ( & V_24 -> V_48 -> V_49 , & V_26 , 1 ) ;
V_33 [ 1 ] |= V_50 ;
V_40 += F_9 ( & V_24 -> V_48 -> V_49 , & V_26 , 1 ) ;
V_33 [ 1 ] = V_42 | V_47 ;
V_40 += F_9 ( & V_24 -> V_48 -> V_49 , & V_26 , 1 ) ;
V_33 [ 1 ] |= V_50 ;
V_40 += F_9 ( & V_24 -> V_48 -> V_49 , & V_26 , 1 ) ;
V_41 = 1 << 31 ;
for ( V_28 = 0 ; V_28 < 32 ; V_28 ++ ) {
V_33 [ 1 ] = V_42 | V_47 ;
if ( V_38 & V_41 )
V_33 [ 1 ] |= V_46 ;
V_40 += F_9 ( & V_24 -> V_48 -> V_49 , & V_26 , 1 ) ;
V_33 [ 1 ] |= V_50 ;
V_40 += F_9 ( & V_24 -> V_48 -> V_49 , & V_26 , 1 ) ;
V_41 >>= 1 ;
}
V_33 [ 1 ] = V_42 ;
V_40 += F_9 ( & V_24 -> V_48 -> V_49 , & V_26 , 1 ) ;
V_33 [ 1 ] |= V_50 ;
V_40 += F_9 ( & V_24 -> V_48 -> V_49 , & V_26 , 1 ) ;
F_16 ( V_33 ) ;
return ( V_40 == 70 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_40 ;
int V_28 ;
int V_51 = 0 ;
T_1 * V_6 , * V_4 ;
F_18 ( L_4 , V_52 ) ;
V_4 = F_15 ( 3 , V_44 ) ;
if ( ! V_4 )
return - V_45 ;
V_6 = F_15 ( 2 , V_44 ) ;
if ( ! V_6 ) {
F_16 ( V_4 ) ;
return - V_45 ;
}
V_4 [ 0 ] = 0x11 ;
V_4 [ 1 ] = 0x02 ;
V_40 = F_6 ( V_2 , 0x00 , V_4 , 2 , NULL , 0 ) ;
if ( V_40 < 0 )
goto error;
F_8 ( 2 ) ;
V_4 [ 0 ] = 0x11 ;
V_4 [ 1 ] = 0x00 ;
V_40 = F_6 ( V_2 , 0x00 , V_4 , 2 , NULL , 0 ) ;
if ( V_40 < 0 )
goto error;
F_8 ( 1 ) ;
V_4 [ 0 ] = 0x03 ;
V_4 [ 1 ] = 0x80 ;
V_40 = F_4 ( V_2 -> V_14 , F_5 ( V_2 -> V_14 , 0 ) ,
V_12 , V_13 ,
0x1200 , 0x0100 , V_4 , 2 , 2000 ) ;
if ( V_40 < 0 )
goto error;
F_8 ( 2 ) ;
V_4 [ 0 ] = 0x00 ;
V_4 [ 2 ] = 0x01 ;
V_4 [ 1 ] = 0x00 ;
V_40 = F_6 ( V_2 , 0x12 >> 1 , V_4 , 3 , V_6 , 2 ) ;
if ( V_40 < 0 || V_6 [ 0 ] != 0xff || V_6 [ 1 ] != 0xff )
goto error;
F_8 ( 2 ) ;
V_4 [ 0 ] = 0x03 ;
V_4 [ 1 ] = 0x80 ;
V_40 = F_4 ( V_2 -> V_14 , F_5 ( V_2 -> V_14 , 0 ) ,
V_12 , V_13 ,
0x9000 , 0x0100 , V_4 , 2 , 2000 ) ;
if ( V_40 < 0 )
goto error;
F_8 ( 2 ) ;
V_4 [ 0 ] = 0x00 ;
V_4 [ 2 ] = 0x01 ;
V_4 [ 1 ] = 0x00 ;
V_40 = F_6 ( V_2 , 0x90 >> 1 , V_4 , 3 , V_6 , 2 ) ;
if ( V_40 < 0 || V_6 [ 0 ] != 0xff || V_6 [ 1 ] != 0xff )
goto error;
F_8 ( 1 ) ;
V_53:
V_4 [ 0 ] = V_19 ;
V_4 [ 1 ] = ( V_54 << 1 ) + 1 ;
V_40 = F_6 ( V_2 , V_55 , V_4 , 2 , NULL , 0 ) ;
if ( V_40 < 0 )
goto error;
F_8 ( 5 ) ;
V_4 [ 0 ] = 0x00 ;
V_4 [ 2 ] = 0x01 ;
V_4 [ 1 ] = 0x00 ;
V_40 = F_6 ( V_2 , V_55 , V_4 , 3 , V_6 , 1 ) ;
if ( V_40 < 0 )
goto error;
if ( V_6 [ 0 ] & 0x80 ) {
if ( ++ V_51 > 3 ) {
F_18 ( L_5
L_6 , V_6 [ 0 ] ) ;
goto error;
}
F_8 ( 100 ) ;
goto V_53;
}
F_8 ( 1 ) ;
V_4 [ 0 ] = 0x30 ;
V_4 [ 1 ] = 0x04 ;
V_40 = F_6 ( V_2 , 0x00 , V_4 , 2 , NULL , 0 ) ;
if ( V_40 < 0 )
goto error;
F_8 ( 2 ) ;
V_4 [ 0 ] = 0x00 ;
V_4 [ 1 ] = 0x01 ;
V_40 = F_6 ( V_2 , 0x00 , V_4 , 2 , NULL , 0 ) ;
if ( V_40 < 0 )
goto error;
V_4 [ 0 ] = 0x06 ;
V_4 [ 1 ] = 0x0F ;
V_40 = F_6 ( V_2 , 0x00 , V_4 , 2 , NULL , 0 ) ;
if ( V_40 < 0 )
goto error;
F_8 ( 10 ) ;
for ( V_28 = 0 ; V_28 < V_56 ; V_28 ++ ) {
V_40 = F_6 ( V_2 , 0x00 , V_57 [ V_28 ] , 2 ,
NULL , 0 ) ;
if ( V_40 < 0 )
goto error;
F_8 ( 1 ) ;
}
F_8 ( 20 ) ;
V_40 = F_19 ( & V_2 -> V_35 [ 0 ] , 0 ) ;
if ( V_40 < 0 )
goto error;
return 0 ;
error:
F_16 ( V_4 ) ;
F_16 ( V_6 ) ;
F_18 ( L_7 , V_52 , V_40 ) ;
return - V_58 ;
}
static int F_19 ( struct V_37 * V_24 , int V_59 )
{
int V_40 ;
F_18 ( L_8 , V_52 , V_59 ) ;
if ( V_59 )
V_40 = F_14 ( V_24 , 0x6400ff64 , 1 ) ;
else
V_40 = F_14 ( V_24 , 0x96ff00ff , 1 ) ;
if ( V_40 != 1 ) {
F_18 ( L_9 , V_52 , V_40 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_20 ( struct V_37 * V_24 )
{
if ( F_17 ( V_24 -> V_48 ) < 0 )
return - V_58 ;
V_24 -> V_61 [ 0 ] . V_62 = F_21 ( V_24 -> V_48 ) ;
if ( V_24 -> V_61 [ 0 ] . V_62 == NULL )
return - V_58 ;
return 0 ;
}
static int F_22 ( struct V_63 * V_64 ,
const struct V_65 * V_66 )
{
struct V_1 * V_2 ;
struct V_67 * V_68 ;
int V_40 ;
if ( V_64 -> V_69 < V_70 )
return - V_71 ;
V_68 = F_23 ( V_64 , V_72 ) ;
if ( V_68 == NULL ) {
F_24 ( L_10 ) ;
return - V_71 ;
}
V_40 = F_25 ( F_26 ( V_64 ) ,
V_68 -> V_73 . V_74 ,
V_68 -> V_73 . V_75 ) ;
if ( V_40 != 0 ) {
F_24 ( L_11 ) ;
return V_40 ;
}
V_40 = F_27 ( V_64 , & V_76 ,
V_77 , & V_2 , V_78 ) ;
if ( V_40 == 0 )
F_19 ( & V_2 -> V_35 [ 0 ] , 1 ) ;
return V_40 ;
}
