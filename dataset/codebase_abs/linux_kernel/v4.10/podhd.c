static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return sprintf ( V_5 , L_1 , V_9 -> V_11 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return sprintf ( V_5 , L_2 , V_9 -> V_12 ) ;
}
static void F_4 ( struct V_8 * V_9 )
{
F_5 ( V_9 -> V_13 , V_14 ) ;
F_6 ( & V_9 -> V_15 , V_16 ,
V_17 , ( unsigned long ) V_9 ) ;
}
static void V_17 ( unsigned long V_18 )
{
struct V_8 * V_9 = (struct V_8 * ) V_18 ;
F_5 ( V_9 -> V_13 ,
V_19 ) ;
F_7 ( & V_9 -> V_20 ) ;
}
static int F_8 ( struct V_8 * V_9 )
{
int V_21 ;
T_2 V_22 [ 8 ] ;
int V_23 ;
struct V_24 * V_25 = V_9 -> V_26 . V_25 ;
V_21 = F_9 ( V_25 , F_10 ( V_25 , 0 ) ,
0x67 , V_27 | V_28 | V_29 ,
0x11 , 0 ,
NULL , 0 , V_30 * V_31 ) ;
if ( V_21 < 0 ) {
F_11 ( V_9 -> V_26 . V_32 , L_3 , V_21 ) ;
return V_21 ;
}
V_21 = F_9 ( V_25 , F_12 ( V_25 , 0 ) , 0x67 ,
V_27 | V_28 | V_33 ,
0x11 , 0x0 ,
& V_22 , 3 , V_30 * V_31 ) ;
if ( V_21 < 0 ) {
F_11 ( V_9 -> V_26 . V_32 ,
L_4 , V_21 ) ;
return V_21 ;
}
V_9 -> V_12 =
( V_22 [ 0 ] << 16 ) | ( V_22 [ 1 ] << 8 ) | ( V_22 [ 2 ] << 0 ) ;
for ( V_23 = 0 ; V_23 <= 16 ; V_23 ++ ) {
V_21 = F_13 ( & V_9 -> V_26 , 0xf000 + 0x08 * V_23 , V_22 , 8 ) ;
if ( V_21 < 0 )
return V_21 ;
}
V_21 = F_9 ( V_25 , F_10 ( V_25 , 0 ) ,
V_34 ,
V_35 | V_28 | V_29 ,
1 , 0 ,
NULL , 0 , V_30 * V_31 ) ;
if ( V_21 < 0 )
return V_21 ;
return 0 ;
}
static void F_14 ( struct V_36 * V_37 )
{
struct V_8 * V_9 =
F_15 ( V_37 , struct V_8 , V_20 ) ;
F_5 ( V_9 -> V_13 , V_38 ) ;
F_8 ( V_9 ) ;
F_16 ( & V_9 -> V_26 , & V_9 -> V_11 ) ;
F_17 ( V_9 ) ;
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_39 * V_26 = & V_9 -> V_26 ;
return F_18 ( V_26 -> V_7 ) ;
}
static void F_19 ( struct V_39 * V_26 )
{
struct V_8 * V_9 = (struct V_8 * ) V_26 ;
if ( V_9 -> V_26 . V_40 -> V_41 & V_42 ) {
struct V_43 * V_44 ;
F_20 ( & V_9 -> V_15 ) ;
F_21 ( & V_9 -> V_20 ) ;
V_44 = F_22 ( V_26 -> V_25 ,
V_9 -> V_26 . V_40 -> V_45 ) ;
F_23 ( & V_46 , V_44 ) ;
}
}
static int F_24 ( struct V_39 * V_26 ,
const struct V_47 * V_48 )
{
int V_49 ;
struct V_8 * V_9 = (struct V_8 * ) V_26 ;
struct V_43 * V_44 ;
V_26 -> V_50 = F_19 ;
if ( V_9 -> V_26 . V_40 -> V_41 & V_42 ) {
V_44 = F_22 ( V_26 -> V_25 ,
V_9 -> V_26 . V_40 -> V_45 ) ;
if ( ! V_44 ) {
F_11 ( V_9 -> V_26 . V_32 , L_5 ,
V_9 -> V_26 . V_40 -> V_45 ) ;
return - V_51 ;
}
V_49 = F_25 ( & V_46 , V_44 , NULL ) ;
if ( V_49 != 0 ) {
F_11 ( V_9 -> V_26 . V_32 , L_6 ,
V_9 -> V_26 . V_40 -> V_45 , V_49 ) ;
return V_49 ;
}
V_49 = F_26 ( V_26 -> V_7 , & V_52 ) ;
if ( V_49 < 0 )
return V_49 ;
}
if ( V_9 -> V_26 . V_40 -> V_41 & V_53 ) {
V_49 = F_27 ( V_26 ,
( V_48 -> V_54 == V_55 ||
V_48 -> V_54 == V_56 ) ? & V_57 :
& V_58 ) ;
if ( V_49 < 0 )
return V_49 ;
}
if ( ! ( V_9 -> V_26 . V_40 -> V_41 & V_42 ) ) {
return F_17 ( V_9 ) ;
}
F_28 ( & V_9 -> V_15 ) ;
F_29 ( & V_9 -> V_20 , F_14 ) ;
F_4 ( V_9 ) ;
return 0 ;
}
static int F_30 ( struct V_43 * V_59 ,
const struct V_47 * V_48 )
{
return F_31 ( V_59 , V_48 , L_7 ,
& V_60 [ V_48 -> V_54 ] ,
F_24 , sizeof( struct V_8 ) ) ;
}
