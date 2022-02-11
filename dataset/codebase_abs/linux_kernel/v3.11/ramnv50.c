void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
while ( ! F_2 ( & V_4 -> V_7 ) ) {
V_6 = F_3 ( & V_4 -> V_7 , F_4 ( * V_6 ) , V_8 ) ;
F_5 ( & V_6 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , & V_6 ) ;
}
F_6 ( & V_2 -> V_10 , & V_4 -> V_11 ) ;
}
void
F_7 ( struct V_1 * V_2 , struct V_3 * * V_12 )
{
struct V_3 * V_4 = * V_12 ;
* V_12 = NULL ;
if ( F_8 ( V_4 == NULL ) )
return;
F_9 ( & V_2 -> V_13 . V_14 ) ;
F_1 ( V_2 , V_4 ) ;
F_10 ( & V_2 -> V_13 . V_14 ) ;
F_11 ( V_4 ) ;
}
static int
F_12 ( struct V_1 * V_2 , T_1 V_15 , T_2 V_16 , T_2 V_17 ,
T_2 V_18 , struct V_3 * * V_12 )
{
struct V_19 * V_20 = & V_2 -> V_9 ;
struct V_19 * V_10 = & V_2 -> V_10 ;
struct V_5 * V_21 ;
struct V_3 * V_4 ;
int V_22 = ( V_18 & 0x300 ) >> 8 ;
int type = ( V_18 & 0x07f ) ;
int V_23 = ( V_18 & 0x800 ) ;
int V_24 , V_25 , V_26 ;
V_25 = ( V_15 >> 12 ) ;
V_24 = V_17 ? ( V_17 >> 12 ) : V_25 ;
V_16 >>= 12 ;
V_4 = F_13 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return - V_28 ;
F_9 ( & V_2 -> V_13 . V_14 ) ;
if ( V_22 ) {
if ( V_16 == 16 ) {
int V_29 = ( V_25 >> 4 ) * V_22 ;
V_26 = F_14 ( V_10 , 1 , V_29 , V_29 , 1 , & V_4 -> V_11 ) ;
if ( V_26 )
V_4 -> V_11 = NULL ;
}
if ( F_8 ( ! V_4 -> V_11 ) )
V_22 = 0 ;
}
F_15 ( & V_4 -> V_7 ) ;
V_4 -> V_18 = ( V_22 << 7 ) | type ;
V_4 -> V_15 = V_25 ;
type = V_30 [ type ] ;
do {
if ( V_23 )
V_26 = F_16 ( V_20 , type , V_25 , V_24 , V_16 , & V_21 ) ;
else
V_26 = F_14 ( V_20 , type , V_25 , V_24 , V_16 , & V_21 ) ;
if ( V_26 ) {
F_10 ( & V_2 -> V_13 . V_14 ) ;
V_2 -> V_31 -> V_32 ( V_2 , & V_4 ) ;
return V_26 ;
}
F_17 ( & V_21 -> V_8 , & V_4 -> V_7 ) ;
V_25 -= V_21 -> V_33 ;
} while ( V_25 );
F_10 ( & V_2 -> V_13 . V_14 ) ;
V_21 = F_3 ( & V_4 -> V_7 , struct V_5 , V_8 ) ;
V_4 -> V_34 = ( T_1 ) V_21 -> V_34 << 12 ;
* V_12 = V_4 ;
return 0 ;
}
static T_2
F_18 ( struct V_1 * V_2 , struct V_35 * V_31 )
{
int V_36 , V_37 , V_38 , V_39 , V_40 , V_41 ;
T_1 V_42 , V_43 ;
T_2 V_44 , V_45 , V_46 , V_47 , V_48 ;
V_44 = F_19 ( V_2 , 0x100200 ) ;
V_45 = F_19 ( V_2 , 0x100204 ) ;
V_46 = F_19 ( V_2 , 0x100250 ) ;
V_47 = F_19 ( V_2 , 0x001540 ) ;
F_20 ( V_2 , L_1 , V_44 , V_45 , V_46 , V_47 ) ;
for ( V_36 = 0 , V_37 = 0 ; V_36 < 8 ; V_36 ++ ) {
if ( V_47 & ( 0x00010000 << V_36 ) )
V_37 ++ ;
}
V_38 = ( V_45 & 0x0000f000 ) >> 12 ;
V_39 = ( ( V_45 & 0x000f0000 ) >> 16 ) + 8 ;
V_40 = ( ( V_45 & 0x00f00000 ) >> 20 ) + 8 ;
V_41 = 1 << ( ( ( V_45 & 0x03000000 ) >> 24 ) + 2 ) ;
V_42 = V_37 * V_41 * ( 1 << V_38 ) * 8 ;
V_43 = V_42 << V_39 ;
if ( V_44 & 0x00000004 )
V_43 += V_42 << V_40 ;
if ( V_43 != V_31 -> V_15 ) {
F_21 ( V_2 , L_2 ,
( T_2 ) ( V_31 -> V_15 >> 20 ) ) ;
}
V_48 = V_42 ;
if ( V_46 & 1 )
V_48 *= 3 ;
F_20 ( V_2 , L_3 , V_48 ) ;
return V_48 ;
}
static int
F_22 ( struct V_49 * V_50 , struct V_49 * V_51 ,
struct V_52 * V_53 , void * V_54 , T_2 V_55 ,
struct V_49 * * V_56 )
{
struct V_1 * V_2 = V_1 ( V_50 ) ;
struct V_57 * V_58 = F_23 ( V_2 ) ;
struct V_59 * V_60 = V_59 ( V_58 ) ;
struct V_35 * V_31 ;
const T_2 V_61 = ( 256 * 1024 ) >> 12 ;
const T_2 V_62 = ( 1024 * 1024 ) >> 12 ;
T_2 V_15 ;
int V_26 ;
V_26 = F_24 ( V_50 , V_51 , V_53 , & V_31 ) ;
* V_56 = F_25 ( V_31 ) ;
if ( V_26 )
return V_26 ;
V_31 -> V_15 = F_19 ( V_2 , 0x10020c ) ;
V_31 -> V_15 = ( V_31 -> V_15 & 0xffffff00 ) |
( ( V_31 -> V_15 & 0x000000ff ) << 32 ) ;
V_15 = ( V_31 -> V_15 >> 12 ) - V_61 - V_62 ;
switch ( V_58 -> V_63 ) {
case 0xaa :
case 0xac :
case 0xaf :
V_26 = F_26 ( & V_2 -> V_9 , V_61 , V_15 , 1 ) ;
if ( V_26 )
return V_26 ;
V_31 -> type = V_64 ;
V_31 -> V_65 = ( T_1 ) F_19 ( V_2 , 0x100e10 ) << 12 ;
break;
default:
switch ( F_19 ( V_2 , 0x100714 ) & 0x00000007 ) {
case 0 : V_31 -> type = V_66 ; break;
case 1 :
if ( F_27 ( V_60 ) == V_67 )
V_31 -> type = V_67 ;
else
V_31 -> type = V_68 ;
break;
case 2 : V_31 -> type = V_69 ; break;
case 3 : V_31 -> type = V_70 ; break;
case 4 : V_31 -> type = V_71 ; break;
default:
break;
}
V_26 = F_26 ( & V_2 -> V_9 , V_61 , V_15 ,
F_18 ( V_2 , V_31 ) >> 12 ) ;
if ( V_26 )
return V_26 ;
V_31 -> V_72 = ( F_19 ( V_2 , 0x100200 ) & 0x4 ) ? 2 : 1 ;
V_31 -> V_10 = F_19 ( V_2 , 0x100320 ) ;
break;
}
V_31 -> V_73 = F_12 ;
V_31 -> V_32 = F_7 ;
return 0 ;
}
