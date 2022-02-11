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
T_2 V_33 [ V_34 ] ;
int V_35 = ( V_31 == NULL || V_32 == 0 ) ,
V_36 = 2 + V_30 + ( V_35 ? 0 : 2 ) ;
if ( 4 + V_30 > sizeof( V_33 ) ) {
F_11 ( L_3 , V_30 ) ;
return - V_37 ;
}
V_33 [ 0 ] = V_35 ? V_38 : V_39 ;
V_33 [ 1 ] = ( V_28 << 1 ) | ( V_35 ? 0 : 1 ) ;
memcpy ( & V_33 [ 2 ] , V_29 , V_30 ) ;
if ( ! V_35 ) {
V_33 [ V_30 + 2 ] = ( V_32 >> 8 ) & 0xff ;
V_33 [ V_30 + 3 ] = V_32 & 0xff ;
}
return F_12 ( V_17 , V_33 , V_36 , V_31 , V_32 , 0 ) ;
}
static int F_13 ( struct V_40 * V_2 , struct V_41 V_42 [] , int V_43 )
{
struct V_16 * V_17 = F_14 ( V_2 ) ;
int V_44 ;
if ( F_15 ( & V_17 -> V_45 ) < 0 )
return - V_46 ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ ) {
if ( V_44 + 1 < V_43 && ( V_42 [ V_44 ] . V_47 & V_48 ) == 0
&& ( V_42 [ V_44 + 1 ] . V_47 & V_48 ) ) {
if ( F_10 ( V_17 , V_42 [ V_44 ] . V_28 , V_42 [ V_44 ] . V_49 , V_42 [ V_44 ] . V_36 ,
V_42 [ V_44 + 1 ] . V_49 , V_42 [ V_44 + 1 ] . V_36 ) < 0 )
break;
V_44 ++ ;
} else if ( ( V_42 [ V_44 ] . V_47 & V_48 ) == 0 ) {
if ( F_10 ( V_17 , V_42 [ V_44 ] . V_28 , V_42 [ V_44 ] . V_49 , V_42 [ V_44 ] . V_36 , NULL , 0 ) < 0 )
break;
} else if ( V_42 [ V_44 ] . V_28 != 0x50 ) {
if ( F_10 ( V_17 , V_42 [ V_44 ] . V_28 , NULL , 0 , V_42 [ V_44 ] . V_49 , V_42 [ V_44 ] . V_36 ) < 0 )
break;
}
}
F_16 ( & V_17 -> V_45 ) ;
return V_44 ;
}
static T_3 F_17 ( struct V_40 * V_50 )
{
return V_51 ;
}
int F_18 ( struct V_16 * V_17 , T_2 V_52 , T_2 * V_53 )
{
T_2 V_29 [ 1 ] = { V_52 } ;
return F_10 ( V_17 , 0x50 , V_29 , 1 , V_53 , 1 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 -> V_54 -> V_55 . V_56 == V_57 &&
V_2 -> V_25 -> V_54 -> V_55 . V_58 ==
V_59 ) {
F_7 ( 1000 ) ;
}
V_2 -> V_9 [ 0 ] . V_10 = F_20 ( V_60 ,
& V_2 -> V_25 -> V_61 ,
V_62 ,
& V_63 ) ;
if ( ( V_2 -> V_9 [ 0 ] . V_10 ) == NULL )
V_2 -> V_9 [ 0 ] . V_10 = F_20 ( V_60 ,
& V_2 -> V_25 -> V_61 ,
V_64 ,
& V_63 ) ;
if ( ( V_2 -> V_9 [ 0 ] . V_10 ) != NULL ) {
if ( V_2 -> V_4 != NULL ) {
struct V_5 * V_6 = V_2 -> V_4 ;
V_6 -> V_7 . V_15 = V_65 ;
V_6 -> V_7 . V_14 = V_66 ;
}
return 0 ;
}
return - V_11 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 ;
T_2 V_67 , V_18 ;
T_1 V_68 = 1220 ;
struct V_40 * V_69 ;
if ( V_2 -> V_25 -> V_54 -> V_55 . V_56 == V_57 &&
V_2 -> V_25 -> V_54 -> V_55 . V_58 == V_59 ) {
F_18 ( V_2 -> V_25 , 0x7E , & V_67 ) ;
F_18 ( V_2 -> V_25 , 0x7F , & V_18 ) ;
if ( V_67 == 0x00 )
V_68 += V_18 ;
else if ( V_67 == 0x80 )
V_68 -= V_18 ;
else
F_11 ( L_4 , V_67 , V_18 ) ;
} else if ( V_2 -> V_25 -> V_54 -> V_55 . V_56 == V_70 &&
V_2 -> V_25 -> V_54 -> V_55 . V_58 == V_71 ) {
T_2 V_72 ;
F_18 ( V_2 -> V_25 , 7 , & V_72 ) ;
if ( V_72 == 2 ) {
V_67 = 127 ;
do {
F_18 ( V_2 -> V_25 , V_67 , & V_72 ) ;
V_67 -- ;
} while ( V_67 > 7 && ( V_72 == 0xff || V_72 == 0x00 ) );
if ( V_72 & 0x80 )
V_68 -= ( 0xff - V_72 ) ;
else
V_68 += V_72 ;
}
}
V_69 = F_22 ( V_2 -> V_9 [ 0 ] . V_10 , 1 ) ;
if ( F_20 ( V_73 , V_2 -> V_9 [ 0 ] . V_10 , V_69 , & V_74 , V_68 ) == NULL ) {
if ( F_20 ( V_75 , V_2 -> V_9 [ 0 ] . V_10 , 0x60 , V_69 , V_76 ) == NULL )
return - V_77 ;
} else {
V_6 -> V_78 = 1 ;
F_23 ( V_2 -> V_9 [ 0 ] . V_10 , & V_79 ) ;
}
return 0 ;
}
int F_24 ( struct V_16 * V_17 , T_3 * V_80 , int * V_81 )
{
T_2 V_82 [ 5 ] , V_83 = V_84 ;
F_12 ( V_17 , & V_83 , 1 , V_82 , 5 , 0 ) ;
F_25 ( V_17 , V_82 , V_80 , V_81 ) ;
if ( V_82 [ 0 ] != 0 )
F_26 ( L_5 , 5 , V_82 ) ;
return 0 ;
}
