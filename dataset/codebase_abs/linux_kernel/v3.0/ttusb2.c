static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , int V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 V_11 [ V_5 + 4 ] , V_12 [ 64 ] = { 0 } ;
int V_13 = 0 ;
memset ( V_11 , 0 , V_5 + 4 ) ;
V_11 [ 0 ] = 0xaa ;
V_11 [ 1 ] = ++ V_9 -> V_14 ;
V_11 [ 2 ] = V_3 ;
V_11 [ 3 ] = V_5 ;
memcpy ( & V_11 [ 4 ] , V_4 , V_5 ) ;
V_13 = F_2 ( V_2 , V_11 , V_5 + 4 , V_12 , 64 , 0 ) ;
if ( V_13 != 0 ||
V_12 [ 0 ] != 0x55 ||
V_12 [ 1 ] != V_11 [ 1 ] ||
V_12 [ 2 ] != V_3 ||
( V_7 > 0 && V_12 [ 3 ] != V_7 ) ) {
F_3 ( L_1 , V_7 , V_12 [ 3 ] ) ;
return - V_15 ;
}
if ( V_7 > 0 )
memcpy ( V_6 , & V_12 [ 4 ] , V_7 ) ;
return 0 ;
}
static int F_4 ( struct V_16 * V_17 , struct V_18 V_19 [] , int V_20 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
static T_1 V_21 [ 60 ] , V_22 [ 60 ] ;
int V_23 , V_24 ;
if ( F_6 ( & V_2 -> V_25 ) < 0 )
return - V_26 ;
if ( V_20 > 2 )
F_3 ( L_2 ) ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
V_24 = V_23 + 1 < V_20 && ( V_19 [ V_23 + 1 ] . V_27 & V_28 ) ;
V_21 [ 0 ] = ( V_19 [ V_23 ] . V_29 << 1 ) | V_24 ;
V_21 [ 1 ] = V_19 [ V_23 ] . V_30 ;
if ( V_24 )
V_21 [ 2 ] = V_19 [ V_23 + 1 ] . V_30 ;
else
V_21 [ 2 ] = 0 ;
memcpy ( & V_21 [ 3 ] , V_19 [ V_23 ] . V_31 , V_19 [ V_23 ] . V_30 ) ;
if ( F_1 ( V_2 , V_32 , V_21 , V_19 [ V_23 ] . V_30 + 3 , V_22 , V_21 [ 2 ] + 3 ) < 0 ) {
F_7 ( L_3 ) ;
break;
}
if ( V_24 ) {
memcpy ( V_19 [ V_23 + 1 ] . V_31 , & V_22 [ 3 ] , V_19 [ V_23 + 1 ] . V_30 ) ;
V_23 ++ ;
}
}
F_8 ( & V_2 -> V_25 ) ;
return V_23 ;
}
static T_2 F_9 ( struct V_16 * V_33 )
{
return V_34 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_13 ;
T_1 V_35 [ 9 ] ;
struct V_8 * V_9 = V_2 -> V_10 ;
V_13 = F_1 ( V_2 , V_36 , NULL , 0 , V_35 , sizeof( V_35 ) ) ;
if ( V_13 != 0 )
return V_13 ;
if ( V_35 [ 8 ] & 0x01 ) {
V_9 -> V_37 = ( V_35 [ 3 ] << 8 ) | V_35 [ 2 ] ;
F_11 ( L_4 , V_38 , V_35 [ 2 ] , V_35 [ 3 ] ) ;
F_12 ( V_2 -> V_39 , V_9 -> V_37 , 0 ) ;
} else if ( V_9 -> V_37 ) {
F_13 ( V_2 -> V_39 ) ;
V_9 -> V_37 = 0 ;
}
return 0 ;
}
static int F_14 ( struct V_40 * V_41 , struct
V_42 * V_43 , struct V_44 * * V_45 ,
int * V_46 )
{
* V_46 = V_41 -> V_47 . V_48 == 0 && V_41 -> V_47 . V_49 == 0 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_50 )
{
T_1 V_51 = V_50 ;
F_1 ( V_2 , V_52 , & V_51 , 0 , NULL , 0 ) ;
return F_1 ( V_2 , V_52 , & V_51 , 1 , NULL , 0 ) ;
}
static int F_16 ( struct V_53 * V_17 )
{
if ( F_17 ( V_17 -> V_54 -> V_41 , 0 , 3 ) < 0 )
F_7 ( L_5 ) ;
if ( ( V_17 -> V_55 = F_18 ( V_56 , & V_57 , & V_17 -> V_54 -> V_58 ) ) == NULL ) {
F_11 ( L_6 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_19 ( struct V_53 * V_17 )
{
if ( F_17 ( V_17 -> V_54 -> V_41 , 0 , 3 ) < 0 )
F_7 ( L_5 ) ;
if ( ( V_17 -> V_55 = F_18 ( V_60 , & V_61 , & V_17 -> V_54 -> V_58 , 0x48 ) ) == NULL ) {
F_11 ( L_7 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_20 ( struct V_53 * V_17 )
{
if ( F_18 ( V_62 , V_17 -> V_55 , 0x61 , & V_17 -> V_54 -> V_58 , NULL ) == NULL ) {
F_21 ( V_63 L_8 , V_38 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_22 ( struct V_53 * V_17 )
{
if ( F_18 ( V_64 , V_17 -> V_55 , 0x60 , & V_17 -> V_54 -> V_58 , 0 ) == NULL ) {
F_11 ( L_9 ) ;
return - V_59 ;
}
if ( F_18 ( V_65 , V_17 -> V_55 , & V_17 -> V_54 -> V_58 , 0 , 0 ) == NULL ) {
F_11 ( L_10 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_23 ( struct V_66 * V_67 ,
const struct V_68 * V_14 )
{
if ( 0 == F_24 ( V_67 , & V_69 ,
V_70 , NULL , V_71 ) ||
0 == F_24 ( V_67 , & V_72 ,
V_70 , NULL , V_71 ) ||
0 == F_24 ( V_67 , & V_73 ,
V_70 , NULL , V_71 ) )
return 0 ;
return - V_59 ;
}
static int T_3 F_25 ( void )
{
int V_74 ;
if ( ( V_74 = F_26 ( & V_75 ) ) ) {
F_7 ( L_11 , V_74 ) ;
return V_74 ;
}
return 0 ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_75 ) ;
}
