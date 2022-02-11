bool
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int type = ( V_3 & V_4 ) >> 8 ;
if ( F_2 ( type < F_3 ( V_5 ) && V_5 [ type ] ) )
return true ;
return false ;
}
void
F_4 ( struct V_1 * V_2 , struct V_6 * * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_9 -> V_13 . V_12 ;
struct V_14 * V_15 = & V_12 -> V_15 [ V_16 ] ;
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_20 * V_21 ;
struct V_6 * V_22 ;
V_22 = * V_7 ;
* V_7 = NULL ;
if ( F_5 ( V_22 == NULL ) )
return;
F_6 ( & V_18 -> V_23 ) ;
while ( ! F_7 ( & V_22 -> V_24 ) ) {
V_21 = F_8 ( & V_22 -> V_24 , struct V_20 , V_25 ) ;
F_9 ( & V_21 -> V_25 ) ;
F_10 ( V_18 , V_21 ) ;
}
if ( V_22 -> V_26 ) {
F_11 ( V_22 -> V_26 ) ;
V_22 -> V_26 = NULL ;
}
F_12 ( & V_18 -> V_23 ) ;
F_13 ( V_22 ) ;
}
int
F_14 ( struct V_1 * V_2 , T_2 V_27 , T_1 V_28 , T_1 V_29 ,
T_1 V_30 , struct V_6 * * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = & V_9 -> V_13 . V_12 ;
struct V_14 * V_15 = & V_12 -> V_15 [ V_16 ] ;
struct V_17 * V_18 = V_15 -> V_19 ;
struct V_20 * V_31 ;
struct V_6 * V_22 ;
int V_32 = ( V_30 & 0x300 ) >> 8 ;
int type = ( V_30 & 0x07f ) ;
int V_33 ;
if ( ! V_5 [ type ] )
return - V_34 ;
V_27 >>= 12 ;
V_28 >>= 12 ;
V_29 >>= 12 ;
V_22 = F_15 ( sizeof( * V_22 ) , V_35 ) ;
if ( ! V_22 )
return - V_36 ;
F_6 ( & V_18 -> V_23 ) ;
if ( V_32 ) {
if ( V_28 == 16 ) {
struct V_37 * V_38 = & V_9 -> V_39 . V_40 ;
int V_41 = ( V_27 >> 4 ) * V_32 ;
V_22 -> V_26 = F_16 ( & V_38 -> V_42 , V_41 , 0 , 0 ) ;
if ( V_22 -> V_26 )
V_22 -> V_26 = F_17 ( V_22 -> V_26 , V_41 , 0 ) ;
}
if ( F_5 ( ! V_22 -> V_26 ) )
V_32 = 0 ;
}
F_18 ( & V_22 -> V_24 ) ;
V_22 -> V_2 = V_9 -> V_2 ;
V_22 -> V_30 = ( V_32 << 7 ) | type ;
V_22 -> V_27 = V_27 ;
do {
V_33 = F_19 ( V_18 , V_5 [ type ] , V_27 , V_29 , V_28 , & V_31 ) ;
if ( V_33 ) {
F_12 ( & V_18 -> V_23 ) ;
F_4 ( V_2 , & V_22 ) ;
return V_33 ;
}
F_20 ( & V_31 -> V_25 , & V_22 -> V_24 ) ;
V_27 -= V_31 -> V_43 ;
} while ( V_27 );
F_12 ( & V_18 -> V_23 ) ;
V_31 = F_8 ( & V_22 -> V_24 , struct V_20 , V_25 ) ;
V_22 -> V_44 = ( T_2 ) V_31 -> V_44 << 12 ;
* V_7 = V_22 ;
return 0 ;
}
static T_1
F_21 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_45 , V_46 , V_47 , V_48 , V_49 , V_50 ;
T_2 V_51 , V_52 ;
T_1 V_53 , V_54 , V_55 , V_56 , V_57 ;
V_53 = F_22 ( V_2 , 0x100200 ) ;
V_54 = F_22 ( V_2 , 0x100204 ) ;
V_55 = F_22 ( V_2 , 0x100250 ) ;
V_56 = F_22 ( V_2 , 0x001540 ) ;
F_23 ( V_2 , L_1 , V_53 , V_54 , V_55 , V_56 ) ;
for ( V_45 = 0 , V_46 = 0 ; V_45 < 8 ; V_45 ++ ) {
if ( V_56 & ( 0x00010000 << V_45 ) )
V_46 ++ ;
}
V_47 = ( V_54 & 0x0000f000 ) >> 12 ;
V_48 = ( ( V_54 & 0x000f0000 ) >> 16 ) + 8 ;
V_49 = ( ( V_54 & 0x00f00000 ) >> 20 ) + 8 ;
V_50 = ( ( V_54 & 0x01000000 ) ? 8 : 4 ) ;
V_51 = V_46 * V_50 * ( 1 << V_47 ) * 8 ;
V_52 = V_51 << V_48 ;
if ( V_53 & 0x00000004 )
V_52 += V_51 << V_49 ;
if ( V_52 != V_9 -> V_58 ) {
F_24 ( V_2 , L_2 ,
( T_1 ) ( V_9 -> V_58 >> 20 ) ) ;
F_24 ( V_2 , L_3 ,
( T_1 ) ( V_52 >> 20 ) ) ;
}
V_57 = V_51 ;
if ( V_55 & 1 )
V_57 *= 3 ;
F_23 ( V_2 , L_4 , V_57 ) ;
return V_57 ;
}
int
F_25 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_9 -> V_58 = F_22 ( V_2 , 0x10020c ) ;
V_9 -> V_58 |= ( V_9 -> V_58 & 0xff ) << 32 ;
V_9 -> V_58 &= 0xffffffff00ULL ;
switch ( V_9 -> V_59 ) {
case 0xaa :
case 0xac :
case 0xaf :
V_9 -> V_60 = ( T_2 ) F_22 ( V_2 , 0x100e10 ) << 12 ;
V_9 -> V_61 = 4096 ;
break;
default:
V_9 -> V_61 = F_21 ( V_2 ) ;
break;
}
return 0 ;
}
