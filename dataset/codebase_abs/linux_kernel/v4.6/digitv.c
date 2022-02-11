static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 * V_5 , int V_6 , T_1 * V_7 , int V_8 )
{
int V_9 = ( V_7 == NULL || V_8 == 0 ) ;
T_1 V_10 [ 7 ] , V_11 [ 7 ] ;
memset ( V_10 , 0 , 7 ) ; memset ( V_11 , 0 , 7 ) ;
V_10 [ 0 ] = V_3 ;
V_10 [ 1 ] = V_4 ;
V_10 [ 2 ] = V_9 ? V_6 : V_8 ;
if ( V_9 ) {
memcpy ( & V_10 [ 3 ] , V_5 , V_6 ) ;
F_2 ( V_2 , V_10 , 7 ) ;
} else {
F_3 ( V_2 , V_10 , 7 , V_11 , 7 , 10 ) ;
memcpy ( V_7 , & V_11 [ 3 ] , V_8 ) ;
}
return 0 ;
}
static int F_4 ( struct V_12 * V_13 , struct V_14 V_15 [] , int V_16 )
{
struct V_1 * V_2 = F_5 ( V_13 ) ;
int V_17 ;
if ( F_6 ( & V_2 -> V_18 ) < 0 )
return - V_19 ;
if ( V_16 > 2 )
F_7 ( L_1 ) ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
if ( V_17 + 1 < V_16 && ( V_15 [ V_17 + 1 ] . V_20 & V_21 ) ) {
if ( F_1 ( V_2 , V_22 , V_15 [ V_17 ] . V_23 [ 0 ] , NULL , 0 ,
V_15 [ V_17 + 1 ] . V_23 , V_15 [ V_17 + 1 ] . V_24 ) < 0 )
break;
V_17 ++ ;
} else
if ( F_1 ( V_2 , V_25 , V_15 [ V_17 ] . V_23 [ 0 ] ,
& V_15 [ V_17 ] . V_23 [ 1 ] , V_15 [ V_17 ] . V_24 - 1 , NULL , 0 ) < 0 )
break;
}
F_8 ( & V_2 -> V_18 ) ;
return V_17 ;
}
static T_2 F_9 ( struct V_12 * V_26 )
{
return V_27 ;
}
static int F_10 ( struct V_28 * V_29 , struct
V_30 * V_31 , struct V_32 * * V_33 ,
int * V_34 )
{
* V_34 = V_29 -> V_35 . V_36 == 0 && V_29 -> V_35 . V_37 == 0 ;
return 0 ;
}
static int F_11 ( struct V_38 * V_39 )
{
static T_1 V_40 [] = { 0x89 , 0x38 , 0x8a , 0x2d , 0x50 , 0x80 } ;
static T_1 V_41 [] = { 0x68 , 0xa0 , 0x8e , 0x40 , 0x53 , 0x50 ,
0x67 , 0x20 , 0x7d , 0x01 , 0x7c , 0x00 , 0x7a , 0x00 ,
0x79 , 0x20 , 0x57 , 0x05 , 0x56 , 0x31 , 0x88 , 0x0f ,
0x75 , 0x32 } ;
int V_17 ;
for ( V_17 = 0 ; V_17 < F_12 ( V_40 ) ; V_17 += 2 )
F_13 ( V_39 , & V_40 [ V_17 ] , 2 ) ;
F_14 ( 1 ) ;
for ( V_17 = 0 ; V_17 < F_12 ( V_41 ) ; V_17 += 2 )
F_13 ( V_39 , & V_41 [ V_17 ] , 2 ) ;
return 0 ;
}
static int F_15 ( struct V_38 * V_39 )
{
struct V_42 * V_13 = V_39 -> V_43 -> V_44 ;
T_1 V_45 [ 5 ] ;
V_39 -> V_46 . V_47 . V_48 ( V_39 , V_45 , sizeof( V_45 ) ) ;
if ( V_39 -> V_46 . V_49 )
V_39 -> V_46 . V_49 ( V_39 , 1 ) ;
return F_1 ( V_13 -> V_50 , V_51 , 0 , & V_45 [ 1 ] , 4 , NULL , 0 ) ;
}
static int F_16 ( struct V_42 * V_13 )
{
struct V_52 * V_53 = V_13 -> V_50 -> V_44 ;
V_13 -> V_54 [ 0 ] . V_39 = F_17 ( V_55 , & V_56 ,
& V_13 -> V_50 -> V_57 ) ;
if ( ( V_13 -> V_54 [ 0 ] . V_39 ) != NULL ) {
V_53 -> V_58 = 0 ;
return 0 ;
}
V_13 -> V_54 [ 0 ] . V_39 = F_17 ( V_59 ,
& V_60 ,
& V_13 -> V_50 -> V_57 ) ;
if ( ( V_13 -> V_54 [ 0 ] . V_39 ) != NULL ) {
V_53 -> V_58 = 1 ;
return 0 ;
}
return - V_61 ;
}
static int F_18 ( struct V_42 * V_13 )
{
struct V_52 * V_53 = V_13 -> V_50 -> V_44 ;
if ( ! F_17 ( V_62 , V_13 -> V_54 [ 0 ] . V_39 , 0x60 , NULL , V_63 ) )
return - V_64 ;
if ( V_53 -> V_58 )
V_13 -> V_54 [ 0 ] . V_39 -> V_46 . V_47 . V_65 = F_15 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 * V_66 , int * V_67 )
{
int V_17 ;
T_1 V_68 [ 5 ] ;
T_1 V_45 [ 4 ] = { 0 } ;
* V_66 = 0 ;
* V_67 = V_69 ;
F_1 ( V_2 , V_70 , 0 , NULL , 0 , & V_68 [ 1 ] , 4 ) ;
F_1 ( V_2 , V_71 , 0 , V_45 , 4 , NULL , 0 ) ;
if ( V_68 [ 1 ] != 0 )
{
for ( V_17 = 0 ; V_17 < V_2 -> V_31 . V_72 . V_73 . V_74 ; V_17 ++ ) {
if ( F_20 ( & V_2 -> V_31 . V_72 . V_73 . V_75 [ V_17 ] ) == V_68 [ 1 ] &&
F_21 ( & V_2 -> V_31 . V_72 . V_73 . V_75 [ V_17 ] ) == V_68 [ 2 ] ) {
* V_66 = V_2 -> V_31 . V_72 . V_73 . V_75 [ V_17 ] . V_76 ;
* V_67 = V_77 ;
return 0 ;
}
}
}
if ( V_68 [ 0 ] != 0 )
F_22 ( L_2 , 5 , V_68 ) ;
return 0 ;
}
static int F_23 ( struct V_78 * V_79 ,
const struct V_80 * V_81 )
{
struct V_1 * V_2 ;
int V_82 = F_24 ( V_79 , & V_83 , V_84 , & V_2 ,
V_85 ) ;
if ( V_82 == 0 ) {
T_1 V_45 [ 4 ] = { 0 } ;
if ( V_2 != NULL ) {
V_45 [ 0 ] = 1 ;
F_1 ( V_2 , V_86 , 0 , V_45 , 4 , NULL , 0 ) ;
V_45 [ 0 ] = 0 ;
F_1 ( V_2 , V_71 , 0 , V_45 , 4 , NULL , 0 ) ;
}
}
return V_82 ;
}
