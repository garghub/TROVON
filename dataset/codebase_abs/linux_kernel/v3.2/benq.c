static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
int V_6 ;
if ( V_1 -> V_7 < 0 )
return;
V_6 = F_2 ( V_5 , F_3 ( V_5 , 0 ) ,
0x02 ,
V_8 | V_9 | V_10 ,
V_2 ,
V_3 ,
NULL ,
0 ,
500 ) ;
if ( V_6 < 0 ) {
F_4 ( L_1 , V_6 ) ;
V_1 -> V_7 = V_6 ;
}
}
static int F_5 ( struct V_1 * V_1 ,
const struct V_11 * V_12 )
{
V_1 -> V_13 . V_14 = V_15 ;
V_1 -> V_13 . V_16 = F_6 ( V_15 ) ;
V_1 -> V_13 . V_17 = 1 ;
V_1 -> V_13 . V_18 = 1 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_19 * V_19 ;
int V_20 , V_21 ;
#if V_22 < 4
#error "Not enough URBs in the gspca table"
#endif
#define F_9 64
#define F_10 32
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ ) {
V_19 = F_11 ( F_10 , V_23 ) ;
if ( ! V_19 ) {
F_4 ( L_2 ) ;
return - V_24 ;
}
V_1 -> V_19 [ V_21 ] = V_19 ;
V_19 -> V_25 = F_12 ( V_1 -> V_5 ,
F_9 * F_10 ,
V_23 ,
& V_19 -> V_26 ) ;
if ( V_19 -> V_25 == NULL ) {
F_4 ( L_3 ) ;
return - V_24 ;
}
V_19 -> V_5 = V_1 -> V_5 ;
V_19 -> V_27 = V_1 ;
V_19 -> V_28 = F_9 * F_10 ;
V_19 -> V_29 = F_13 ( V_1 -> V_5 ,
V_21 & 1 ? 0x82 : 0x83 ) ;
V_19 -> V_30 = V_31
| V_32 ;
V_19 -> V_33 = 1 ;
V_19 -> V_34 = V_35 ;
V_19 -> V_36 = F_10 ;
for ( V_20 = 0 ; V_20 < F_10 ; V_20 ++ ) {
V_19 -> V_37 [ V_20 ] . V_38 = F_9 ;
V_19 -> V_37 [ V_20 ] . V_39 = F_9 * V_20 ;
}
}
return V_1 -> V_7 ;
}
static void F_14 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0x003c , 0x0003 ) ;
F_1 ( V_1 , 0x003c , 0x0004 ) ;
F_1 ( V_1 , 0x003c , 0x0005 ) ;
F_1 ( V_1 , 0x003c , 0x0006 ) ;
F_1 ( V_1 , 0x003c , 0x0007 ) ;
F_15 ( V_1 -> V_5 , V_1 -> V_40 ,
V_1 -> V_41 - 1 ) ;
}
static void F_16 ( struct V_1 * V_1 ,
T_2 * V_42 ,
int V_43 )
{
}
static void V_35 ( struct V_19 * V_19 )
{
struct V_1 * V_1 = (struct V_1 * ) V_19 -> V_27 ;
struct V_19 * V_44 ;
T_2 * V_42 ;
int V_20 , V_45 ;
F_17 ( V_46 , L_4 ) ;
if ( ! V_1 -> V_47 )
return;
if ( V_19 -> V_48 != 0 ) {
if ( V_19 -> V_48 == - V_49 )
return;
#ifdef F_18
if ( V_1 -> V_50 )
return;
#endif
F_4 ( L_5 , V_19 -> V_48 ) ;
return;
}
if ( V_19 == V_1 -> V_19 [ 0 ] || V_19 == V_1 -> V_19 [ 2 ] )
return;
if ( V_19 == V_1 -> V_19 [ 1 ] )
V_44 = V_1 -> V_19 [ 0 ] ;
else
V_44 = V_1 -> V_19 [ 2 ] ;
for ( V_20 = 0 ; V_20 < V_19 -> V_36 ; V_20 ++ ) {
if ( V_44 -> V_37 [ V_20 ] . V_51 != F_9
|| V_19 -> V_37 [ V_20 ] . V_51 != F_9 ) {
F_17 ( V_52 , L_6 ,
V_44 -> V_37 [ V_20 ] . V_51 ,
V_19 -> V_37 [ V_20 ] . V_51 ) ;
V_1 -> V_53 = V_54 ;
continue;
}
V_45 = V_44 -> V_37 [ V_20 ] . V_48 ;
if ( V_45 == 0 )
V_45 = V_19 -> V_37 [ V_20 ] . V_48 ;
if ( V_45 ) {
F_4 ( L_7 ,
V_20 , V_45 ) ;
V_1 -> V_53 = V_54 ;
continue;
}
V_42 = ( T_2 * ) V_44 -> V_25
+ V_44 -> V_37 [ V_20 ] . V_39 ;
if ( V_42 [ 0 ] == 0x80 && ( V_42 [ 1 ] & 0xfe ) == 0xba ) {
F_19 ( V_1 , V_55 ,
NULL , 0 ) ;
F_19 ( V_1 , V_56 ,
V_42 + 4 , F_9 - 4 ) ;
} else if ( V_42 [ 0 ] == 0x04 && ( V_42 [ 1 ] & 0xfe ) == 0xba ) {
F_19 ( V_1 , V_57 ,
V_42 + 4 , F_9 - 4 ) ;
} else {
V_1 -> V_53 = V_54 ;
continue;
}
V_42 = ( T_2 * ) V_19 -> V_25
+ V_19 -> V_37 [ V_20 ] . V_39 ;
F_19 ( V_1 , V_57 ,
V_42 , F_9 ) ;
}
V_45 = F_20 ( V_44 , V_58 ) ;
if ( V_45 < 0 )
F_4 ( L_8 , V_45 ) ;
V_45 = F_20 ( V_19 , V_58 ) ;
if ( V_45 < 0 )
F_4 ( L_9 , V_45 ) ;
}
static int F_21 ( struct V_59 * V_60 ,
const struct V_11 * V_12 )
{
return F_22 ( V_60 , V_12 , & V_61 , sizeof( struct V_62 ) ,
V_63 ) ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_64 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_64 ) ;
}
