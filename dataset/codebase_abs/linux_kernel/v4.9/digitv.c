static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 * V_5 , int V_6 , T_1 * V_7 , int V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 , V_13 ;
V_13 = ( V_7 == NULL || V_8 == 0 ) ;
memset ( V_10 -> V_14 , 0 , 7 ) ;
memset ( V_10 -> V_15 , 0 , 7 ) ;
V_10 -> V_14 [ 0 ] = V_3 ;
V_10 -> V_14 [ 1 ] = V_4 ;
V_10 -> V_14 [ 2 ] = V_13 ? V_6 : V_8 ;
if ( V_13 ) {
memcpy ( & V_10 -> V_14 [ 3 ] , V_5 , V_6 ) ;
V_12 = F_2 ( V_2 , V_10 -> V_14 , 7 ) ;
} else {
V_12 = F_3 ( V_2 , V_10 -> V_14 , 7 , V_10 -> V_15 , 7 , 10 ) ;
memcpy ( V_7 , & V_10 -> V_15 [ 3 ] , V_8 ) ;
}
return V_12 ;
}
static int F_4 ( struct V_16 * V_17 , struct V_18 V_19 [] , int V_20 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
int V_21 ;
if ( F_6 ( & V_2 -> V_22 ) < 0 )
return - V_23 ;
if ( V_20 > 2 )
F_7 ( L_1 ) ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
if ( V_21 + 1 < V_20 && ( V_19 [ V_21 + 1 ] . V_24 & V_25 ) ) {
if ( F_1 ( V_2 , V_26 , V_19 [ V_21 ] . V_27 [ 0 ] , NULL , 0 ,
V_19 [ V_21 + 1 ] . V_27 , V_19 [ V_21 + 1 ] . V_28 ) < 0 )
break;
V_21 ++ ;
} else
if ( F_1 ( V_2 , V_29 , V_19 [ V_21 ] . V_27 [ 0 ] ,
& V_19 [ V_21 ] . V_27 [ 1 ] , V_19 [ V_21 ] . V_28 - 1 , NULL , 0 ) < 0 )
break;
}
F_8 ( & V_2 -> V_22 ) ;
return V_21 ;
}
static T_2 F_9 ( struct V_16 * V_30 )
{
return V_31 ;
}
static int F_10 ( struct V_32 * V_33 , struct
V_34 * V_35 , struct V_36 * * V_37 ,
int * V_38 )
{
* V_38 = V_33 -> V_39 . V_40 == 0 && V_33 -> V_39 . V_41 == 0 ;
return 0 ;
}
static int F_11 ( struct V_42 * V_43 )
{
static T_1 V_44 [] = { 0x89 , 0x38 , 0x8a , 0x2d , 0x50 , 0x80 } ;
static T_1 V_45 [] = { 0x68 , 0xa0 , 0x8e , 0x40 , 0x53 , 0x50 ,
0x67 , 0x20 , 0x7d , 0x01 , 0x7c , 0x00 , 0x7a , 0x00 ,
0x79 , 0x20 , 0x57 , 0x05 , 0x56 , 0x31 , 0x88 , 0x0f ,
0x75 , 0x32 } ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_12 ( V_44 ) ; V_21 += 2 )
F_13 ( V_43 , & V_44 [ V_21 ] , 2 ) ;
F_14 ( 1 ) ;
for ( V_21 = 0 ; V_21 < F_12 ( V_45 ) ; V_21 += 2 )
F_13 ( V_43 , & V_45 [ V_21 ] , 2 ) ;
return 0 ;
}
static int F_15 ( struct V_42 * V_43 )
{
struct V_46 * V_17 = V_43 -> V_47 -> V_11 ;
T_1 V_48 [ 5 ] ;
V_43 -> V_49 . V_50 . V_51 ( V_43 , V_48 , sizeof( V_48 ) ) ;
if ( V_43 -> V_49 . V_52 )
V_43 -> V_49 . V_52 ( V_43 , 1 ) ;
return F_1 ( V_17 -> V_53 , V_54 , 0 , & V_48 [ 1 ] , 4 , NULL , 0 ) ;
}
static int F_16 ( struct V_46 * V_17 )
{
struct V_9 * V_10 = V_17 -> V_53 -> V_11 ;
V_17 -> V_55 [ 0 ] . V_43 = F_17 ( V_56 , & V_57 ,
& V_17 -> V_53 -> V_58 ) ;
if ( ( V_17 -> V_55 [ 0 ] . V_43 ) != NULL ) {
V_10 -> V_59 = 0 ;
return 0 ;
}
V_17 -> V_55 [ 0 ] . V_43 = F_17 ( V_60 ,
& V_61 ,
& V_17 -> V_53 -> V_58 ) ;
if ( ( V_17 -> V_55 [ 0 ] . V_43 ) != NULL ) {
V_10 -> V_59 = 1 ;
return 0 ;
}
return - V_62 ;
}
static int F_18 ( struct V_46 * V_17 )
{
struct V_9 * V_10 = V_17 -> V_53 -> V_11 ;
if ( ! F_17 ( V_63 , V_17 -> V_55 [ 0 ] . V_43 , 0x60 , NULL , V_64 ) )
return - V_65 ;
if ( V_10 -> V_59 )
V_17 -> V_55 [ 0 ] . V_43 -> V_49 . V_50 . V_66 = F_15 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 * V_67 , int * V_68 )
{
int V_21 ;
T_1 V_69 [ 5 ] ;
T_1 V_48 [ 4 ] = { 0 } ;
* V_67 = 0 ;
* V_68 = V_70 ;
F_1 ( V_2 , V_71 , 0 , NULL , 0 , & V_69 [ 1 ] , 4 ) ;
F_1 ( V_2 , V_72 , 0 , V_48 , 4 , NULL , 0 ) ;
if ( V_69 [ 1 ] != 0 )
{
for ( V_21 = 0 ; V_21 < V_2 -> V_35 . V_73 . V_74 . V_75 ; V_21 ++ ) {
if ( F_20 ( & V_2 -> V_35 . V_73 . V_74 . V_76 [ V_21 ] ) == V_69 [ 1 ] &&
F_21 ( & V_2 -> V_35 . V_73 . V_74 . V_76 [ V_21 ] ) == V_69 [ 2 ] ) {
* V_67 = V_2 -> V_35 . V_73 . V_74 . V_76 [ V_21 ] . V_77 ;
* V_68 = V_78 ;
return 0 ;
}
}
}
if ( V_69 [ 0 ] != 0 )
F_22 ( L_2 , 5 , V_69 ) ;
return 0 ;
}
static int F_23 ( struct V_79 * V_80 ,
const struct V_81 * V_82 )
{
struct V_1 * V_2 ;
int V_12 = F_24 ( V_80 , & V_83 , V_84 , & V_2 ,
V_85 ) ;
if ( V_12 == 0 ) {
T_1 V_48 [ 4 ] = { 0 } ;
if ( V_2 != NULL ) {
V_48 [ 0 ] = 1 ;
F_1 ( V_2 , V_86 , 0 , V_48 , 4 , NULL , 0 ) ;
V_48 [ 0 ] = 0 ;
F_1 ( V_2 , V_72 , 0 , V_48 , 4 , NULL , 0 ) ;
}
}
return V_12 ;
}
