static void
F_1 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = * V_2 ;
if ( ! V_3 )
return;
* V_2 = NULL ;
F_2 ( NULL , & V_3 -> V_4 , V_3 ) ;
F_3 ( V_3 ) ;
F_4 ( V_3 -> V_5 ) ;
F_5 ( NULL , & V_3 -> V_5 ) ;
if ( V_3 -> V_6 )
F_6 ( V_3 -> V_6 ) ;
F_7 ( V_3 ) ;
}
void
F_8 ( struct V_7 * V_8 , T_1 V_9 , T_2 V_10 , T_2 V_11 )
{
struct V_12 * V_13 = V_8 -> V_14 -> V_15 ;
T_1 V_16 ;
if ( V_13 -> V_17 < 0xc0 ) {
if ( V_13 -> V_17 == 0x50 )
V_9 = 0 ;
V_16 = 0x00010000 ;
} else {
if ( V_9 & 0x80000000 )
V_16 = 0x00000000 ;
else
V_16 = 0x00020000 ;
}
F_9 ( V_8 , 0 , 0x3d , V_10 , V_11 , V_18 ,
V_19 , ( V_9 >> 8 ) & 0xff , 0 ) ;
F_10 ( V_8 , 0x14 , V_16 ) ;
V_13 -> V_20 . V_21 . V_22 ( V_8 -> V_14 ) ;
}
int
F_11 ( struct V_1 * V_3 , T_1 V_23 , T_1 V_9 ,
T_2 V_10 , T_2 V_11 , struct V_7 * * V_24 )
{
struct V_25 * V_26 = V_25 ( V_3 -> V_14 ) ;
struct V_7 * V_8 = NULL ;
int V_27 ;
V_27 = F_12 ( V_3 -> V_14 , V_26 -> V_28 , 6 * 4 , 32 , 0 , & V_8 ) ;
if ( V_27 )
return V_27 ;
V_8 -> V_20 = V_29 ;
F_8 ( V_8 , V_9 , V_10 , V_11 ) ;
V_27 = F_13 ( V_3 , V_23 , V_8 ) ;
if ( V_27 )
goto V_30;
if ( V_24 )
F_14 ( V_8 , V_24 ) ;
V_30:
F_14 ( NULL , & V_8 ) ;
return V_27 ;
}
static int
F_15 ( struct V_31 * V_14 , int V_32 ,
struct V_1 * * V_2 )
{
struct V_25 * V_26 = V_25 ( V_14 ) ;
struct V_1 * V_3 ;
int V_27 ;
V_3 = F_16 ( sizeof( struct V_1 ) , V_33 ) ;
if ( ! V_3 )
return - V_34 ;
* V_2 = V_3 ;
V_3 -> V_35 = V_32 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_36 = 4 ;
V_3 -> V_37 = 0 ;
V_27 = F_17 ( V_14 , 4096 , 0 , V_38 , 0 , 0 ,
& V_3 -> V_5 ) ;
if ( V_27 == 0 )
V_27 = F_18 ( V_3 -> V_5 , V_38 ) ;
if ( V_27 ) {
F_19 ( V_14 , L_1 , V_27 ) ;
F_1 ( V_2 ) ;
return V_27 ;
}
V_27 = F_20 ( V_3 -> V_5 ) ;
if ( V_27 ) {
F_19 ( V_14 , L_2 , V_27 ) ;
F_1 ( V_2 ) ;
return V_27 ;
}
V_3 -> V_6 = F_21 ( F_22 ( V_14 -> V_39 , 0 ) +
F_23 ( V_3 -> V_35 ) , V_40 ) ;
if ( ! V_3 -> V_6 ) {
F_19 ( V_14 , L_3 ) ;
F_1 ( V_2 ) ;
return - V_34 ;
}
if ( V_26 -> V_28 && V_3 != V_26 -> V_28 )
F_2 ( V_26 -> V_28 -> V_4 , & V_3 -> V_4 , NULL ) ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_3 )
{
struct V_31 * V_14 = V_3 -> V_14 ;
int V_35 = V_3 -> V_35 , V_27 , V_41 ;
T_2 V_42 = V_3 -> V_5 -> V_43 . V_44 ;
T_1 V_45 ;
V_45 = F_25 ( V_14 , F_26 ( V_35 ) ) ;
if ( ( V_45 & 0x009f0000 ) == 0x00020000 )
F_27 ( V_14 , F_26 ( V_35 ) , V_45 | 0x00800000 ) ;
V_45 = F_25 ( V_14 , F_26 ( V_35 ) ) ;
if ( ( V_45 & 0x003f0000 ) == 0x00030000 )
F_27 ( V_14 , F_26 ( V_35 ) , V_45 | 0x00600000 ) ;
F_27 ( V_14 , F_28 ( V_35 ) , V_42 >> 8 |
V_46 |
V_47 ) ;
F_27 ( V_14 , F_29 ( V_35 ) , 0x00010000 ) ;
F_27 ( V_14 , F_30 ( V_35 ) , V_35 ) ;
F_31 ( V_14 , F_26 ( V_35 ) , V_48 ,
V_49 ) ;
F_27 ( V_14 , F_32 ( V_35 ) , 0x00000000 ) ;
F_27 ( V_14 , F_26 ( V_35 ) , 0x01000003 |
V_49 ) ;
if ( ! F_33 ( V_14 , F_26 ( V_35 ) , 0x80000000 , 0x00000000 ) ) {
F_19 ( V_14 , L_4 , V_35 ,
F_25 ( V_14 , F_26 ( V_35 ) ) ) ;
return - V_50 ;
}
F_31 ( V_14 , 0x610028 , 0x00000000 , 0x00010001 << V_35 ) ;
V_3 -> V_51 . V_52 = ( 4096 / 4 ) - 2 ;
V_3 -> V_51 . V_52 &= ~ 7 ;
V_3 -> V_51 . V_53 = 0 ;
V_3 -> V_51 . V_54 = V_3 -> V_51 . V_53 ;
V_3 -> V_51 . free = V_3 -> V_51 . V_52 - V_3 -> V_51 . V_54 ;
V_27 = F_34 ( V_3 , V_55 ) ;
if ( V_27 )
return V_27 ;
for ( V_41 = 0 ; V_41 < V_55 ; V_41 ++ )
F_35 ( V_3 , 0 ) ;
return 0 ;
}
static void
F_36 ( struct V_1 * V_3 )
{
struct V_31 * V_14 = V_3 -> V_14 ;
int V_35 = V_3 -> V_35 ;
F_31 ( V_14 , 0x610028 , 0x00010001 << V_35 , 0x00000000 ) ;
F_31 ( V_14 , F_26 ( V_35 ) , 0x00001010 , 0x00001000 ) ;
F_27 ( V_14 , V_56 , ( 1 << V_35 ) ) ;
F_31 ( V_14 , F_26 ( V_35 ) , 0x00000003 , 0x00000000 ) ;
if ( ! F_33 ( V_14 , F_26 ( V_35 ) , 0x001e0000 , 0x00000000 ) ) {
F_19 ( V_14 , L_5 , V_35 ,
F_25 ( V_14 , F_26 ( V_35 ) ) ) ;
}
}
static void
F_37 ( struct V_31 * V_14 )
{
struct V_25 * V_26 = V_25 ( V_14 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
if ( V_26 -> V_57 [ V_41 ] . V_58 . V_43 ) {
F_4 ( V_26 -> V_57 [ V_41 ] . V_58 . V_43 ) ;
F_5 ( NULL , & V_26 -> V_57 [ V_41 ] . V_58 . V_43 ) ;
}
F_1 ( & V_26 -> V_57 [ V_41 ] . V_59 ) ;
}
F_14 ( NULL , & V_26 -> V_60 ) ;
F_1 ( & V_26 -> V_28 ) ;
}
static int
F_38 ( struct V_31 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_25 * V_26 = V_25 ( V_14 ) ;
struct V_7 * V_4 = NULL ;
struct V_1 * V_3 ;
int V_27 , V_41 , V_61 ;
V_27 = F_15 ( V_14 , 0 , & V_26 -> V_28 ) ;
if ( V_27 )
return V_27 ;
V_3 = V_26 -> V_28 ;
V_27 = F_12 ( V_14 , NULL , 32768 , 65536 ,
V_62 , & V_3 -> V_63 ) ;
if ( V_27 ) {
F_19 ( V_14 , L_6 , V_27 ) ;
goto V_64;
}
V_27 = F_39 ( & V_3 -> V_65 , 0 , 32768 ) ;
if ( V_27 ) {
F_19 ( V_14 , L_7 , V_27 ) ;
goto V_64;
}
V_27 = F_12 ( V_14 , V_3 , 4096 , 16 , 0 , & V_4 ) ;
if ( V_27 ) {
F_19 ( V_14 , L_8 , V_27 ) ;
goto V_64;
}
V_27 = F_40 ( V_14 , V_4 , & V_3 -> V_4 ) ;
F_14 ( NULL , & V_4 ) ;
if ( V_27 )
goto V_64;
V_27 = F_12 ( V_14 , V_26 -> V_28 , 0x1000 , 0 ,
V_62 , & V_26 -> V_60 ) ;
if ( V_27 )
goto V_64;
V_27 = F_11 ( V_26 -> V_28 , V_66 , 0x0000 ,
V_26 -> V_60 -> V_67 , V_26 -> V_60 -> V_11 , NULL ) ;
if ( V_27 )
goto V_64;
V_27 = F_11 ( V_26 -> V_28 , V_68 , 0x0000 ,
0 , V_13 -> V_69 , NULL ) ;
if ( V_27 )
goto V_64;
V_27 = F_11 ( V_26 -> V_28 , V_70 , 0x80000000 ,
0 , V_13 -> V_69 , NULL ) ;
if ( V_27 )
goto V_64;
V_27 = F_11 ( V_26 -> V_28 , V_71 , 0x80000000 |
( V_13 -> V_17 < 0xc0 ? 0x7a00 : 0xfe00 ) ,
0 , V_13 -> V_69 , NULL ) ;
if ( V_27 )
goto V_64;
V_27 = F_11 ( V_26 -> V_28 , V_72 , 0x80000000 |
( V_13 -> V_17 < 0xc0 ? 0x7000 : 0xfe00 ) ,
0 , V_13 -> V_69 , NULL ) ;
if ( V_27 )
goto V_64;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
struct V_73 * V_74 = & V_26 -> V_57 [ V_41 ] ;
T_2 V_44 ;
V_27 = F_15 ( V_14 , 1 + V_41 , & V_74 -> V_59 ) ;
if ( V_27 )
goto V_64;
V_27 = F_17 ( V_14 , 4096 , 0x1000 , V_38 ,
0 , 0x0000 , & V_74 -> V_58 . V_43 ) ;
if ( ! V_27 ) {
V_27 = F_18 ( V_74 -> V_58 . V_43 , V_38 ) ;
if ( ! V_27 )
V_27 = F_20 ( V_74 -> V_58 . V_43 ) ;
if ( V_27 )
F_5 ( NULL , & V_74 -> V_58 . V_43 ) ;
V_44 = V_74 -> V_58 . V_43 -> V_43 . V_44 ;
}
if ( V_27 )
goto V_64;
V_27 = F_11 ( V_74 -> V_59 , V_66 , 0x0000 ,
V_44 , 4096 , NULL ) ;
if ( V_27 )
goto V_64;
V_27 = F_11 ( V_74 -> V_59 , V_70 , 0x80000000 ,
0 , V_13 -> V_69 , NULL ) ;
if ( V_27 )
goto V_64;
V_27 = F_11 ( V_74 -> V_59 , V_71 , 0x80000000 |
( V_13 -> V_17 < 0xc0 ?
0x7a00 : 0xfe00 ) ,
0 , V_13 -> V_69 , NULL ) ;
if ( V_27 )
goto V_64;
V_27 = F_11 ( V_74 -> V_59 , V_72 , 0x80000000 |
( V_13 -> V_17 < 0xc0 ?
0x7000 : 0xfe00 ) ,
0 , V_13 -> V_69 , NULL ) ;
if ( V_27 )
goto V_64;
for ( V_61 = 0 ; V_61 < 4096 ; V_61 += 4 )
F_41 ( V_74 -> V_58 . V_43 , V_61 / 4 , 0x74b1e000 ) ;
V_74 -> V_58 . V_44 = 0 ;
}
return 0 ;
V_64:
F_37 ( V_14 ) ;
return V_27 ;
}
int
F_42 ( struct V_31 * V_14 )
{
struct V_25 * V_26 = V_25 ( V_14 ) ;
int V_27 , V_41 ;
if ( ! V_26 -> V_28 ) {
V_27 = F_38 ( V_14 ) ;
if ( V_27 )
return V_27 ;
}
V_27 = F_24 ( V_26 -> V_28 ) ;
if ( V_27 )
return V_27 ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
V_27 = F_24 ( V_26 -> V_57 [ V_41 ] . V_59 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
void
F_43 ( struct V_31 * V_14 )
{
struct V_25 * V_26 = V_25 ( V_14 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
if ( V_26 -> V_57 [ V_41 ] . V_59 )
F_36 ( V_26 -> V_57 [ V_41 ] . V_59 ) ;
}
if ( V_26 -> V_28 )
F_36 ( V_26 -> V_28 ) ;
F_37 ( V_14 ) ;
}
