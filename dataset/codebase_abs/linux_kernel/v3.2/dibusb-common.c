int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
if ( V_6 -> V_7 . V_8 != NULL )
if ( V_6 -> V_7 . V_8 ( V_2 -> V_9 [ 0 ] . V_10 , V_3 ) ) {
F_2 ( L_1 ) ;
return - V_11 ;
}
}
return 0 ;
}
int F_3 ( struct V_1 * V_2 , int V_12 , T_1 V_13 , int V_3 )
{
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
if ( V_6 -> V_7 . V_14 != NULL )
V_6 -> V_7 . V_14 ( V_2 -> V_9 [ 0 ] . V_10 ,
V_12 , V_13 , V_3 ) ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
if ( V_6 -> V_7 . V_15 != NULL )
if ( V_6 -> V_7 . V_15 ( V_2 -> V_9 [ 0 ] . V_10 , V_3 ) < 0 )
F_2 ( L_2 ) ;
}
return 0 ;
}
int F_5 ( struct V_16 * V_17 , int V_3 )
{
T_2 V_18 [ 3 ] ;
int V_19 ;
V_18 [ 0 ] = V_20 ;
V_18 [ 1 ] = V_21 ;
V_18 [ 2 ] = V_3 ? V_22 : V_23 ;
V_19 = F_6 ( V_17 , V_18 , 3 ) ;
F_7 ( 10 ) ;
return V_19 ;
}
int F_8 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_18 [ 3 ] = { 0 } ;
int V_19 ;
if ( ( V_19 = F_1 ( V_2 , V_3 ) ) < 0 )
return V_19 ;
if ( V_3 ) {
V_18 [ 0 ] = V_24 ;
V_18 [ 1 ] = 0x00 ;
if ( ( V_19 = F_6 ( V_2 -> V_25 , V_18 , 2 ) ) < 0 )
return V_19 ;
}
V_18 [ 0 ] = V_20 ;
V_18 [ 1 ] = V_3 ? V_26 : V_27 ;
return F_6 ( V_2 -> V_25 , V_18 , 3 ) ;
}
int F_9 ( struct V_16 * V_17 , int V_3 )
{
if ( V_3 ) {
T_2 V_18 [ 3 ] = { V_20 , V_21 , V_22 } ;
return F_6 ( V_17 , V_18 , 3 ) ;
} else
return 0 ;
}
static int F_10 ( struct V_16 * V_17 , T_2 V_28 ,
T_2 * V_29 , T_1 V_30 , T_2 * V_31 , T_1 V_32 )
{
T_2 V_33 [ V_30 + 4 ] ;
int V_34 = ( V_31 == NULL || V_32 == 0 ) ,
V_35 = 2 + V_30 + ( V_34 ? 0 : 2 ) ;
V_33 [ 0 ] = V_34 ? V_36 : V_37 ;
V_33 [ 1 ] = ( V_28 << 1 ) | ( V_34 ? 0 : 1 ) ;
memcpy ( & V_33 [ 2 ] , V_29 , V_30 ) ;
if ( ! V_34 ) {
V_33 [ V_30 + 2 ] = ( V_32 >> 8 ) & 0xff ;
V_33 [ V_30 + 3 ] = V_32 & 0xff ;
}
return F_11 ( V_17 , V_33 , V_35 , V_31 , V_32 , 0 ) ;
}
static int F_12 ( struct V_38 * V_2 , struct V_39 V_40 [] , int V_41 )
{
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_42 ;
if ( F_14 ( & V_17 -> V_43 ) < 0 )
return - V_44 ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ ) {
if ( V_42 + 1 < V_41 && ( V_40 [ V_42 ] . V_45 & V_46 ) == 0
&& ( V_40 [ V_42 + 1 ] . V_45 & V_46 ) ) {
if ( F_10 ( V_17 , V_40 [ V_42 ] . V_28 , V_40 [ V_42 ] . V_47 , V_40 [ V_42 ] . V_35 ,
V_40 [ V_42 + 1 ] . V_47 , V_40 [ V_42 + 1 ] . V_35 ) < 0 )
break;
V_42 ++ ;
} else if ( ( V_40 [ V_42 ] . V_45 & V_46 ) == 0 ) {
if ( F_10 ( V_17 , V_40 [ V_42 ] . V_28 , V_40 [ V_42 ] . V_47 , V_40 [ V_42 ] . V_35 , NULL , 0 ) < 0 )
break;
} else if ( V_40 [ V_42 ] . V_28 != 0x50 ) {
if ( F_10 ( V_17 , V_40 [ V_42 ] . V_28 , NULL , 0 , V_40 [ V_42 ] . V_47 , V_40 [ V_42 ] . V_35 ) < 0 )
break;
}
}
F_15 ( & V_17 -> V_43 ) ;
return V_42 ;
}
static T_3 F_16 ( struct V_38 * V_48 )
{
return V_49 ;
}
int F_17 ( struct V_16 * V_17 , T_2 V_50 , T_2 * V_51 )
{
T_2 V_29 [ 1 ] = { V_50 } ;
return F_10 ( V_17 , 0x50 , V_29 , 1 , V_51 , 1 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_52 -> V_53 . V_54 == V_55 &&
V_2 -> V_25 -> V_52 -> V_53 . V_56 ==
V_57 ) {
F_7 ( 1000 ) ;
}
V_2 -> V_9 [ 0 ] . V_10 = F_19 ( V_58 ,
& V_2 -> V_25 -> V_59 ,
V_60 ,
& V_61 ) ;
if ( ( V_2 -> V_9 [ 0 ] . V_10 ) == NULL )
V_2 -> V_9 [ 0 ] . V_10 = F_19 ( V_58 ,
& V_2 -> V_25 -> V_59 ,
V_62 ,
& V_61 ) ;
if ( ( V_2 -> V_9 [ 0 ] . V_10 ) != NULL ) {
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
V_6 -> V_7 . V_15 = V_63 ;
V_6 -> V_7 . V_14 = V_64 ;
}
return 0 ;
}
return - V_11 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 ;
T_2 V_65 , V_18 ;
T_1 V_66 = 1220 ;
struct V_38 * V_67 ;
if ( V_2 -> V_25 -> V_52 -> V_53 . V_54 == V_55 &&
V_2 -> V_25 -> V_52 -> V_53 . V_56 == V_57 ) {
F_17 ( V_2 -> V_25 , 0x7E , & V_65 ) ;
F_17 ( V_2 -> V_25 , 0x7F , & V_18 ) ;
if ( V_65 == 0x00 )
V_66 += V_18 ;
else if ( V_65 == 0x80 )
V_66 -= V_18 ;
else
F_21 ( L_3 , V_65 , V_18 ) ;
} else if ( V_2 -> V_25 -> V_52 -> V_53 . V_54 == V_68 &&
V_2 -> V_25 -> V_52 -> V_53 . V_56 == V_69 ) {
T_2 V_70 ;
F_17 ( V_2 -> V_25 , 7 , & V_70 ) ;
if ( V_70 == 2 ) {
V_65 = 127 ;
do {
F_17 ( V_2 -> V_25 , V_65 , & V_70 ) ;
V_65 -- ;
} while ( V_65 > 7 && ( V_70 == 0xff || V_70 == 0x00 ) );
if ( V_70 & 0x80 )
V_66 -= ( 0xff - V_70 ) ;
else
V_66 += V_70 ;
}
}
V_67 = F_22 ( V_2 -> V_9 [ 0 ] . V_10 , 1 ) ;
if ( F_19 ( V_71 , V_2 -> V_9 [ 0 ] . V_10 , V_67 , & V_72 , V_66 ) == NULL ) {
if ( F_19 ( V_73 , V_2 -> V_9 [ 0 ] . V_10 , 0x60 , V_67 , V_74 ) == NULL )
return - V_75 ;
} else {
V_6 -> V_76 = 1 ;
F_23 ( V_2 -> V_9 [ 0 ] . V_10 , & V_77 ) ;
}
return 0 ;
}
int F_24 ( struct V_16 * V_17 , T_3 * V_78 , int * V_79 )
{
T_2 V_80 [ 5 ] , V_81 = V_82 ;
F_11 ( V_17 , & V_81 , 1 , V_80 , 5 , 0 ) ;
F_25 ( V_17 , V_80 , V_78 , V_79 ) ;
if ( V_80 [ 0 ] != 0 )
F_26 ( L_4 , V_80 [ 0 ] , V_80 [ 1 ] , V_80 [ 2 ] , V_80 [ 3 ] , V_80 [ 4 ] ) ;
return 0 ;
}
