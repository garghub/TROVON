static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_9 ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( F_2 ( & V_7 -> V_12 ) )
F_3 ( & V_7 -> V_12 ) ;
if ( V_11 -> V_13 ) {
F_4 ( V_2 -> V_14 , V_11 -> V_15 , V_16 ,
V_17 ) ;
F_5 ( V_11 -> V_13 ) ;
}
F_6 ( V_11 ) ;
V_7 -> V_11 = NULL ;
}
static int
F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_9 ;
struct V_10 * V_11 ;
T_1 V_18 ;
int V_19 ;
V_11 = F_8 ( sizeof( * V_11 ) , V_20 ) ;
if ( ! V_11 )
return - V_21 ;
V_7 -> V_11 = V_11 ;
V_11 -> V_13 = F_9 ( V_20 | V_22 ) ;
if ( ! V_11 -> V_13 ) {
F_1 ( V_2 ) ;
return - V_21 ;
}
V_11 -> V_15 = F_10 ( V_2 -> V_14 , V_11 -> V_13 , 0 ,
V_16 , V_17 ) ;
if ( F_11 ( V_2 -> V_14 , V_11 -> V_15 ) ) {
F_1 ( V_2 ) ;
return - V_23 ;
}
V_18 = F_12 ( V_2 , 0x100320 ) ;
F_13 ( V_2 , L_1 , V_18 ) ;
V_19 = F_14 ( & V_7 -> V_12 , 0 , V_18 ) ;
if ( V_19 ) {
F_1 ( V_2 ) ;
return V_19 ;
}
return 0 ;
}
int
F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 ;
int V_19 ;
if ( ! V_4 -> V_8 . V_9 . V_11 ) {
V_19 = F_7 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
V_11 = V_4 -> V_8 . V_9 . V_11 ;
F_16 ( V_2 , 0x100c08 , V_11 -> V_15 >> 8 ) ;
switch ( V_4 -> V_24 ) {
case 0x50 :
F_16 ( V_2 , 0x100c90 , 0x000707ff ) ;
break;
case 0xa3 :
case 0xa5 :
case 0xa8 :
F_16 ( V_2 , 0x100c90 , 0x000d0fff ) ;
break;
case 0xaf :
F_16 ( V_2 , 0x100c90 , 0x089d1fff ) ;
break;
default:
F_16 ( V_2 , 0x100c90 , 0x001d07ff ) ;
break;
}
return 0 ;
}
void
F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
void
F_18 ( struct V_1 * V_2 , int V_25 )
{
struct V_26 * V_27 = F_19 ( V_2 , V_28 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_29 * V_30 , * V_31 ;
unsigned long V_32 ;
T_1 V_33 [ 6 ] , V_34 , V_35 ;
T_2 V_36 , V_37 , V_38 , V_39 ;
int V_40 , V_41 ;
V_34 = F_12 ( V_2 , 0x100c90 ) ;
if ( ! ( V_34 & 0x80000000 ) )
return;
V_34 &= 0x00ffffff ;
for ( V_40 = 0 ; V_40 < 6 ; V_40 ++ ) {
F_16 ( V_2 , 0x100c90 , V_34 | V_40 << 24 ) ;
V_33 [ V_40 ] = F_12 ( V_2 , 0x100c94 ) ;
}
F_16 ( V_2 , 0x100c90 , V_34 | 0x80000000 ) ;
if ( ! V_25 )
return;
V_35 = ( V_33 [ 2 ] << 16 ) | V_33 [ 1 ] ;
F_20 ( & V_4 -> V_42 . V_43 , V_32 ) ;
for ( V_41 = 0 ; V_41 < V_27 -> V_42 ; V_41 ++ ) {
struct V_44 * V_45 = V_4 -> V_42 . V_46 [ V_41 ] ;
if ( ! V_45 || ! V_45 -> V_47 )
continue;
if ( V_35 == V_45 -> V_47 -> V_48 >> 12 )
break;
}
F_21 ( & V_4 -> V_42 . V_43 , V_32 ) ;
if ( V_4 -> V_24 < 0xa3 ||
V_4 -> V_24 == 0xaa || V_4 -> V_24 == 0xac ) {
V_36 = ( V_33 [ 0 ] & 0x0000000f ) >> 0 ;
V_37 = ( V_33 [ 0 ] & 0x000000f0 ) >> 4 ;
V_38 = ( V_33 [ 0 ] & 0x00000f00 ) >> 8 ;
V_39 = ( V_33 [ 0 ] & 0x0000f000 ) >> 12 ;
} else {
V_36 = ( V_33 [ 0 ] & 0x000000ff ) >> 0 ;
V_37 = ( V_33 [ 0 ] & 0x0000ff00 ) >> 8 ;
V_38 = ( V_33 [ 0 ] & 0x00ff0000 ) >> 16 ;
V_39 = ( V_33 [ 0 ] & 0xff000000 ) >> 24 ;
}
F_22 ( V_2 , L_2 ,
( V_33 [ 5 ] & 0x00000100 ) ? L_3 : L_4 ,
V_33 [ 5 ] & 0xff , V_33 [ 4 ] & 0xffff , V_33 [ 3 ] & 0xffff , V_41 , V_35 ) ;
V_30 = F_23 ( V_49 , V_36 ) ;
if ( V_30 )
F_24 ( L_5 , V_30 -> V_50 ) ;
else
F_24 ( L_6 , V_36 ) ;
V_31 = F_23 ( V_51 , V_38 ) ;
if ( V_31 )
F_24 ( L_5 , V_31 -> V_50 ) ;
else
F_24 ( L_6 , V_38 ) ;
if ( V_31 && V_31 -> V_52 ) V_31 = F_23 ( V_31 -> V_52 , V_39 ) ;
else if ( V_30 && V_30 -> V_52 ) V_31 = F_23 ( V_30 -> V_52 , V_39 ) ;
else V_31 = NULL ;
if ( V_31 )
F_24 ( L_7 , V_31 -> V_50 ) ;
else
F_24 ( L_8 , V_39 ) ;
F_24 ( L_9 ) ;
V_30 = F_23 ( V_53 , V_37 ) ;
if ( V_30 )
F_24 ( L_10 , V_30 -> V_50 ) ;
else
F_24 ( L_11 , V_37 ) ;
}
