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
struct V_3 * V_4 = V_2 -> V_5 ;
const struct V_26 * V_27 , * V_28 ;
unsigned long V_29 ;
T_1 V_30 [ 6 ] , V_31 , V_32 ;
T_2 V_33 , V_34 , V_35 , V_36 ;
int V_37 , V_38 ;
V_31 = F_12 ( V_2 , 0x100c90 ) ;
if ( ! ( V_31 & 0x80000000 ) )
return;
V_31 &= 0x00ffffff ;
for ( V_37 = 0 ; V_37 < 6 ; V_37 ++ ) {
F_16 ( V_2 , 0x100c90 , V_31 | V_37 << 24 ) ;
V_30 [ V_37 ] = F_12 ( V_2 , 0x100c94 ) ;
}
F_16 ( V_2 , 0x100c90 , V_31 | 0x80000000 ) ;
if ( ! V_25 )
return;
V_32 = ( V_30 [ 2 ] << 16 ) | V_30 [ 1 ] ;
F_19 ( & V_4 -> V_39 . V_40 , V_29 ) ;
for ( V_38 = 0 ; V_38 < V_4 -> V_8 . V_41 . V_39 ; V_38 ++ ) {
struct V_42 * V_43 = V_4 -> V_39 . V_44 [ V_38 ] ;
if ( ! V_43 || ! V_43 -> V_45 )
continue;
if ( V_32 == V_43 -> V_45 -> V_46 >> 12 )
break;
}
F_20 ( & V_4 -> V_39 . V_40 , V_29 ) ;
if ( V_4 -> V_24 < 0xa3 ||
V_4 -> V_24 == 0xaa || V_4 -> V_24 == 0xac ) {
V_33 = ( V_30 [ 0 ] & 0x0000000f ) >> 0 ;
V_34 = ( V_30 [ 0 ] & 0x000000f0 ) >> 4 ;
V_35 = ( V_30 [ 0 ] & 0x00000f00 ) >> 8 ;
V_36 = ( V_30 [ 0 ] & 0x0000f000 ) >> 12 ;
} else {
V_33 = ( V_30 [ 0 ] & 0x000000ff ) >> 0 ;
V_34 = ( V_30 [ 0 ] & 0x0000ff00 ) >> 8 ;
V_35 = ( V_30 [ 0 ] & 0x00ff0000 ) >> 16 ;
V_36 = ( V_30 [ 0 ] & 0xff000000 ) >> 24 ;
}
F_21 ( V_2 , L_2 ,
( V_30 [ 5 ] & 0x00000100 ) ? L_3 : L_4 ,
V_30 [ 5 ] & 0xff , V_30 [ 4 ] & 0xffff , V_30 [ 3 ] & 0xffff , V_38 , V_32 ) ;
V_27 = F_22 ( V_47 , V_33 ) ;
if ( V_27 )
F_23 ( L_5 , V_27 -> V_48 ) ;
else
F_23 ( L_6 , V_33 ) ;
V_28 = F_22 ( V_49 , V_35 ) ;
if ( V_28 )
F_23 ( L_5 , V_28 -> V_48 ) ;
else
F_23 ( L_6 , V_35 ) ;
if ( V_28 && V_28 -> V_50 ) V_28 = F_22 ( V_28 -> V_50 , V_36 ) ;
else if ( V_27 && V_27 -> V_50 ) V_28 = F_22 ( V_27 -> V_50 , V_36 ) ;
else V_28 = NULL ;
if ( V_28 )
F_23 ( L_7 , V_28 -> V_48 ) ;
else
F_23 ( L_8 , V_36 ) ;
F_23 ( L_9 ) ;
V_27 = F_22 ( V_51 , V_34 ) ;
if ( V_27 )
F_23 ( L_10 , V_27 -> V_48 ) ;
else
F_23 ( L_11 , V_34 ) ;
}
