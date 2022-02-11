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
return 0 ;
}
static int F_7 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_18 * V_18 ;
int V_19 , V_20 ;
#if V_21 < 4
#error "Not enough URBs in the gspca table"
#endif
#define F_9 64
#define F_10 32
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
V_18 = F_11 ( F_10 , V_22 ) ;
if ( ! V_18 ) {
F_4 ( L_2 ) ;
return - V_23 ;
}
V_1 -> V_18 [ V_20 ] = V_18 ;
V_18 -> V_24 = F_12 ( V_1 -> V_5 ,
F_9 * F_10 ,
V_22 ,
& V_18 -> V_25 ) ;
if ( V_18 -> V_24 == NULL ) {
F_4 ( L_3 ) ;
return - V_23 ;
}
V_18 -> V_5 = V_1 -> V_5 ;
V_18 -> V_26 = V_1 ;
V_18 -> V_27 = F_9 * F_10 ;
V_18 -> V_28 = F_13 ( V_1 -> V_5 ,
V_20 & 1 ? 0x82 : 0x83 ) ;
V_18 -> V_29 = V_30
| V_31 ;
V_18 -> V_32 = 1 ;
V_18 -> V_33 = V_34 ;
V_18 -> V_35 = F_10 ;
for ( V_19 = 0 ; V_19 < F_10 ; V_19 ++ ) {
V_18 -> V_36 [ V_19 ] . V_37 = F_9 ;
V_18 -> V_36 [ V_19 ] . V_38 = F_9 * V_19 ;
}
}
return V_1 -> V_7 ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_39 * V_40 ;
F_1 ( V_1 , 0x003c , 0x0003 ) ;
F_1 ( V_1 , 0x003c , 0x0004 ) ;
F_1 ( V_1 , 0x003c , 0x0005 ) ;
F_1 ( V_1 , 0x003c , 0x0006 ) ;
F_1 ( V_1 , 0x003c , 0x0007 ) ;
V_40 = F_15 ( V_1 -> V_5 , V_1 -> V_41 ) ;
F_16 ( V_1 -> V_5 , V_1 -> V_41 ,
V_40 -> V_42 - 1 ) ;
}
static void F_17 ( struct V_1 * V_1 ,
T_2 * V_43 ,
int V_44 )
{
}
static void V_34 ( struct V_18 * V_18 )
{
struct V_1 * V_1 = (struct V_1 * ) V_18 -> V_26 ;
struct V_18 * V_45 ;
T_2 * V_43 ;
int V_19 , V_46 ;
F_18 ( V_47 , L_4 ) ;
if ( ! V_1 -> V_48 )
return;
if ( V_18 -> V_49 != 0 ) {
if ( V_18 -> V_49 == - V_50 )
return;
#ifdef F_19
if ( V_1 -> V_51 )
return;
#endif
F_4 ( L_5 , V_18 -> V_49 ) ;
return;
}
if ( V_18 == V_1 -> V_18 [ 0 ] || V_18 == V_1 -> V_18 [ 2 ] )
return;
if ( V_18 == V_1 -> V_18 [ 1 ] )
V_45 = V_1 -> V_18 [ 0 ] ;
else
V_45 = V_1 -> V_18 [ 2 ] ;
for ( V_19 = 0 ; V_19 < V_18 -> V_35 ; V_19 ++ ) {
if ( V_45 -> V_36 [ V_19 ] . V_52 != F_9
|| V_18 -> V_36 [ V_19 ] . V_52 != F_9 ) {
F_20 ( L_6 ,
V_45 -> V_36 [ V_19 ] . V_52 ,
V_18 -> V_36 [ V_19 ] . V_52 ) ;
V_1 -> V_53 = V_54 ;
continue;
}
V_46 = V_45 -> V_36 [ V_19 ] . V_49 ;
if ( V_46 == 0 )
V_46 = V_18 -> V_36 [ V_19 ] . V_49 ;
if ( V_46 ) {
F_4 ( L_7 ,
V_19 , V_46 ) ;
V_1 -> V_53 = V_54 ;
continue;
}
V_43 = ( T_2 * ) V_45 -> V_24
+ V_45 -> V_36 [ V_19 ] . V_38 ;
if ( V_43 [ 0 ] == 0x80 && ( V_43 [ 1 ] & 0xfe ) == 0xba ) {
F_21 ( V_1 , V_55 ,
NULL , 0 ) ;
F_21 ( V_1 , V_56 ,
V_43 + 4 , F_9 - 4 ) ;
} else if ( V_43 [ 0 ] == 0x04 && ( V_43 [ 1 ] & 0xfe ) == 0xba ) {
F_21 ( V_1 , V_57 ,
V_43 + 4 , F_9 - 4 ) ;
} else {
V_1 -> V_53 = V_54 ;
continue;
}
V_43 = ( T_2 * ) V_18 -> V_24
+ V_18 -> V_36 [ V_19 ] . V_38 ;
F_21 ( V_1 , V_57 ,
V_43 , F_9 ) ;
}
V_46 = F_22 ( V_45 , V_58 ) ;
if ( V_46 < 0 )
F_4 ( L_8 , V_46 ) ;
V_46 = F_22 ( V_18 , V_58 ) ;
if ( V_46 < 0 )
F_4 ( L_9 , V_46 ) ;
}
static int F_23 ( struct V_39 * V_40 ,
const struct V_11 * V_12 )
{
return F_24 ( V_40 , V_12 , & V_59 , sizeof( struct V_60 ) ,
V_61 ) ;
}
