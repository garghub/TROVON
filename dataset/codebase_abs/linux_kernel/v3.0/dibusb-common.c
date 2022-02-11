int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
if ( V_6 -> V_7 . V_8 != NULL )
if ( V_6 -> V_7 . V_8 ( V_2 -> V_9 , V_3 ) ) {
F_2 ( L_1 ) ;
return - V_10 ;
}
}
return 0 ;
}
int F_3 ( struct V_1 * V_2 , int V_11 , T_1 V_12 , int V_3 )
{
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
if ( V_6 -> V_7 . V_13 != NULL )
V_6 -> V_7 . V_13 ( V_2 -> V_9 , V_11 , V_12 , V_3 ) ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
if ( V_6 -> V_7 . V_14 != NULL )
if ( V_6 -> V_7 . V_14 ( V_2 -> V_9 , V_3 ) < 0 )
F_2 ( L_2 ) ;
}
return 0 ;
}
int F_5 ( struct V_15 * V_16 , int V_3 )
{
T_2 V_17 [ 3 ] ;
int V_18 ;
V_17 [ 0 ] = V_19 ;
V_17 [ 1 ] = V_20 ;
V_17 [ 2 ] = V_3 ? V_21 : V_22 ;
V_18 = F_6 ( V_16 , V_17 , 3 ) ;
F_7 ( 10 ) ;
return V_18 ;
}
int F_8 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_17 [ 3 ] = { 0 } ;
int V_18 ;
if ( ( V_18 = F_1 ( V_2 , V_3 ) ) < 0 )
return V_18 ;
if ( V_3 ) {
V_17 [ 0 ] = V_23 ;
V_17 [ 1 ] = 0x00 ;
if ( ( V_18 = F_6 ( V_2 -> V_24 , V_17 , 2 ) ) < 0 )
return V_18 ;
}
V_17 [ 0 ] = V_19 ;
V_17 [ 1 ] = V_3 ? V_25 : V_26 ;
return F_6 ( V_2 -> V_24 , V_17 , 3 ) ;
}
int F_9 ( struct V_15 * V_16 , int V_3 )
{
if ( V_3 ) {
T_2 V_17 [ 3 ] = { V_19 , V_20 , V_21 } ;
return F_6 ( V_16 , V_17 , 3 ) ;
} else
return 0 ;
}
static int F_10 ( struct V_15 * V_16 , T_2 V_27 ,
T_2 * V_28 , T_1 V_29 , T_2 * V_30 , T_1 V_31 )
{
T_2 V_32 [ V_29 + 4 ] ;
int V_33 = ( V_30 == NULL || V_31 == 0 ) ,
V_34 = 2 + V_29 + ( V_33 ? 0 : 2 ) ;
V_32 [ 0 ] = V_33 ? V_35 : V_36 ;
V_32 [ 1 ] = ( V_27 << 1 ) | ( V_33 ? 0 : 1 ) ;
memcpy ( & V_32 [ 2 ] , V_28 , V_29 ) ;
if ( ! V_33 ) {
V_32 [ V_29 + 2 ] = ( V_31 >> 8 ) & 0xff ;
V_32 [ V_29 + 3 ] = V_31 & 0xff ;
}
return F_11 ( V_16 , V_32 , V_34 , V_30 , V_31 , 0 ) ;
}
static int F_12 ( struct V_37 * V_2 , struct V_38 V_39 [] , int V_40 )
{
struct V_15 * V_16 = F_13 ( V_2 ) ;
int V_41 ;
if ( F_14 ( & V_16 -> V_42 ) < 0 )
return - V_43 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
if ( V_41 + 1 < V_40 && ( V_39 [ V_41 ] . V_44 & V_45 ) == 0
&& ( V_39 [ V_41 + 1 ] . V_44 & V_45 ) ) {
if ( F_10 ( V_16 , V_39 [ V_41 ] . V_27 , V_39 [ V_41 ] . V_46 , V_39 [ V_41 ] . V_34 ,
V_39 [ V_41 + 1 ] . V_46 , V_39 [ V_41 + 1 ] . V_34 ) < 0 )
break;
V_41 ++ ;
} else if ( ( V_39 [ V_41 ] . V_44 & V_45 ) == 0 ) {
if ( F_10 ( V_16 , V_39 [ V_41 ] . V_27 , V_39 [ V_41 ] . V_46 , V_39 [ V_41 ] . V_34 , NULL , 0 ) < 0 )
break;
} else if ( V_39 [ V_41 ] . V_27 != 0x50 ) {
if ( F_10 ( V_16 , V_39 [ V_41 ] . V_27 , NULL , 0 , V_39 [ V_41 ] . V_46 , V_39 [ V_41 ] . V_34 ) < 0 )
break;
}
}
F_15 ( & V_16 -> V_42 ) ;
return V_41 ;
}
static T_3 F_16 ( struct V_37 * V_47 )
{
return V_48 ;
}
int F_17 ( struct V_15 * V_16 , T_2 V_49 , T_2 * V_50 )
{
T_2 V_28 [ 1 ] = { V_49 } ;
return F_10 ( V_16 , 0x50 , V_28 , 1 , V_50 , 1 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 -> V_51 -> V_52 . V_53 == V_54 &&
V_2 -> V_24 -> V_51 -> V_52 . V_55 ==
V_56 ) {
F_7 ( 1000 ) ;
}
if ( ( V_2 -> V_9 = F_19 ( V_57 , & V_2 -> V_24 -> V_58 , V_59 , & V_60 ) ) != NULL ||
( V_2 -> V_9 = F_19 ( V_57 , & V_2 -> V_24 -> V_58 , V_61 , & V_60 ) ) != NULL ) {
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
V_6 -> V_7 . V_14 = V_62 ;
V_6 -> V_7 . V_13 = V_63 ;
}
return 0 ;
}
return - V_10 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 ;
T_2 V_64 , V_17 ;
T_1 V_65 = 1220 ;
struct V_37 * V_66 ;
if ( V_2 -> V_24 -> V_51 -> V_52 . V_53 == V_54 &&
V_2 -> V_24 -> V_51 -> V_52 . V_55 == V_56 ) {
F_17 ( V_2 -> V_24 , 0x7E , & V_64 ) ;
F_17 ( V_2 -> V_24 , 0x7F , & V_17 ) ;
if ( V_64 == 0x00 )
V_65 += V_17 ;
else if ( V_64 == 0x80 )
V_65 -= V_17 ;
else
F_21 ( L_3 , V_64 , V_17 ) ;
} else if ( V_2 -> V_24 -> V_51 -> V_52 . V_53 == V_67 &&
V_2 -> V_24 -> V_51 -> V_52 . V_55 == V_68 ) {
T_2 V_69 ;
F_17 ( V_2 -> V_24 , 7 , & V_69 ) ;
if ( V_69 == 2 ) {
V_64 = 127 ;
do {
F_17 ( V_2 -> V_24 , V_64 , & V_69 ) ;
V_64 -- ;
} while ( V_64 > 7 && ( V_69 == 0xff || V_69 == 0x00 ) );
if ( V_69 & 0x80 )
V_65 -= ( 0xff - V_69 ) ;
else
V_65 += V_69 ;
}
}
V_66 = F_22 ( V_2 -> V_9 , 1 ) ;
if ( F_19 ( V_70 , V_2 -> V_9 , V_66 , & V_71 , V_65 ) == NULL ) {
if ( F_19 ( V_72 , V_2 -> V_9 , 0x60 , V_66 , V_73 ) == NULL )
return - V_74 ;
} else {
V_6 -> V_75 = 1 ;
F_23 ( V_2 -> V_9 , & V_76 ) ;
}
return 0 ;
}
int F_24 ( struct V_15 * V_16 , T_3 * V_77 , int * V_78 )
{
T_2 V_79 [ 5 ] , V_80 = V_81 ;
F_11 ( V_16 , & V_80 , 1 , V_79 , 5 , 0 ) ;
F_25 ( V_16 , V_79 , V_77 , V_78 ) ;
if ( V_79 [ 0 ] != 0 )
F_26 ( L_4 , V_79 [ 0 ] , V_79 [ 1 ] , V_79 [ 2 ] , V_79 [ 3 ] , V_79 [ 4 ] ) ;
return 0 ;
}
