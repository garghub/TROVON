static T_1
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
void T_2 * V_4 = V_2 -> V_5 -> V_6 -> V_7 ;
return F_2 ( V_4 + V_3 ) ;
}
static void
F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
void T_2 * V_4 = V_2 -> V_5 -> V_6 -> V_7 ;
F_4 ( V_8 , V_4 + V_3 ) ;
}
static void
F_5 ( struct V_9 * * V_10 )
{
struct V_9 * V_11 = * V_10 ;
if ( ! V_11 )
return;
* V_10 = NULL ;
F_6 ( V_11 -> V_12 . V_13 ) ;
F_7 ( NULL , & V_11 -> V_12 . V_13 ) ;
if ( V_11 -> V_2 )
F_8 ( V_11 -> V_2 -> V_5 -> V_6 ) ;
F_9 ( V_11 ) ;
}
int
F_10 ( struct V_9 * V_11 , T_1 V_14 , T_1 V_15 ,
T_3 V_16 , T_3 V_17 , struct V_18 * * V_19 )
{
struct V_20 * V_21 = V_11 -> V_22 ;
struct V_23 * V_24 = V_23 ( V_21 ) ;
struct V_25 * V_26 = V_25 ( V_21 ) ;
T_1 V_27 = V_26 -> V_27 ;
T_1 V_28 = V_26 -> V_28 ;
T_1 V_29 ;
if ( F_11 ( V_24 -> V_30 ) -> V_31 < 0xc0 ) {
if ( F_11 ( V_24 -> V_30 ) -> V_31 == 0x50 )
V_15 = 0 ;
V_29 = 0x00010000 ;
} else {
if ( V_15 & 0x80000000 )
V_29 = 0x00000000 ;
else
V_29 = 0x00020000 ;
}
F_12 ( V_26 -> V_32 , V_27 + 0x00 , 0x0019003d | ( V_15 << 22 ) ) ;
F_12 ( V_26 -> V_32 , V_27 + 0x04 , F_13 ( V_16 + V_17 - 1 ) ) ;
F_12 ( V_26 -> V_32 , V_27 + 0x08 , F_13 ( V_16 ) ) ;
F_12 ( V_26 -> V_32 , V_27 + 0x0c , F_14 ( V_16 + V_17 - 1 ) << 24 |
F_14 ( V_16 ) ) ;
F_12 ( V_26 -> V_32 , V_27 + 0x10 , 0x00000000 ) ;
F_12 ( V_26 -> V_32 , V_27 + 0x14 , V_29 ) ;
F_12 ( V_26 -> V_32 , V_28 + 0x00 , V_14 ) ;
F_12 ( V_26 -> V_32 , V_28 + 0x04 , ( V_11 -> V_14 << 28 ) | ( V_27 << 10 ) |
V_11 -> V_14 ) ;
V_26 -> V_27 += 0x20 ;
V_26 -> V_28 += 0x08 ;
return 0 ;
}
static int
F_15 ( struct V_20 * V_21 , int V_33 ,
struct V_9 * * V_10 )
{
struct V_23 * V_24 = V_23 ( V_21 ) ;
struct V_25 * V_26 = V_25 ( V_21 ) ;
struct V_9 * V_11 ;
int V_34 ;
V_11 = F_16 ( sizeof( struct V_9 ) , V_35 ) ;
if ( ! V_11 )
return - V_36 ;
* V_10 = V_11 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_14 = V_33 ;
V_11 -> V_22 = V_21 ;
V_11 -> V_37 = 4 ;
V_11 -> V_38 = 0 ;
V_34 = F_17 ( V_21 , 4096 , 0 , V_39 , 0 , 0 , NULL ,
& V_11 -> V_12 . V_13 ) ;
if ( V_34 == 0 )
V_34 = F_18 ( V_11 -> V_12 . V_13 , V_39 ) ;
if ( V_34 ) {
F_19 ( V_24 , L_1 , V_34 ) ;
F_5 ( V_10 ) ;
return V_34 ;
}
V_34 = F_20 ( V_11 -> V_12 . V_13 ) ;
if ( V_34 ) {
F_19 ( V_24 , L_2 , V_34 ) ;
F_5 ( V_10 ) ;
return V_34 ;
}
V_11 -> V_2 = F_16 ( sizeof( * V_11 -> V_2 ) , V_35 ) ;
#ifdef F_21
V_11 -> V_2 -> V_40 = F_21 ;
#endif
V_11 -> V_2 -> V_41 = F_22 ( V_26 -> V_32 ) -> V_41 ;
V_11 -> V_2 -> V_42 = F_22 ( V_26 -> V_32 ) -> V_42 ;
V_11 -> V_2 -> V_5 =
F_16 ( sizeof( * V_11 -> V_2 -> V_5 ) , V_35 ) ;
V_11 -> V_2 -> V_5 -> V_6 =
F_16 ( sizeof( * V_11 -> V_2 -> V_5 -> V_6 ) , V_35 ) ;
V_11 -> V_2 -> V_5 -> V_6 -> V_43 = F_1 ;
V_11 -> V_2 -> V_5 -> V_6 -> V_44 = F_3 ;
V_11 -> V_2 -> V_5 -> V_6 -> V_7 =
F_23 ( F_24 ( V_21 -> V_45 , 0 ) +
F_25 ( V_11 -> V_14 ) , V_46 ) ;
return 0 ;
}
static int
F_26 ( struct V_9 * V_11 )
{
struct V_23 * V_24 = V_11 -> V_24 ;
struct V_47 * V_30 = F_11 ( V_24 -> V_30 ) ;
int V_48 = V_11 -> V_14 , V_34 , V_49 ;
T_3 V_50 = V_11 -> V_12 . V_13 -> V_51 . V_52 ;
T_1 V_53 ;
V_53 = F_27 ( V_30 , F_28 ( V_48 ) ) ;
if ( ( V_53 & 0x009f0000 ) == 0x00020000 )
F_29 ( V_30 , F_28 ( V_48 ) , V_53 | 0x00800000 ) ;
V_53 = F_27 ( V_30 , F_28 ( V_48 ) ) ;
if ( ( V_53 & 0x003f0000 ) == 0x00030000 )
F_29 ( V_30 , F_28 ( V_48 ) , V_53 | 0x00600000 ) ;
F_29 ( V_30 , F_30 ( V_48 ) , V_50 >> 8 |
V_54 |
V_55 ) ;
F_29 ( V_30 , F_31 ( V_48 ) , 0x00010000 ) ;
F_29 ( V_30 , F_32 ( V_48 ) , V_48 ) ;
F_33 ( V_30 , F_28 ( V_48 ) , V_56 ,
V_57 ) ;
F_29 ( V_30 , F_34 ( V_48 ) , 0x00000000 ) ;
F_29 ( V_30 , F_28 ( V_48 ) , 0x01000003 |
V_57 ) ;
if ( ! F_35 ( V_30 , F_28 ( V_48 ) , 0x80000000 , 0x00000000 ) ) {
F_19 ( V_24 , L_3 , V_48 ,
F_27 ( V_30 , F_28 ( V_48 ) ) ) ;
return - V_58 ;
}
F_33 ( V_30 , 0x610028 , 0x00000000 , 0x00010001 << V_48 ) ;
V_11 -> V_59 . V_60 = ( 4096 / 4 ) - 2 ;
V_11 -> V_59 . V_60 &= ~ 7 ;
V_11 -> V_59 . V_61 = 0 ;
V_11 -> V_59 . V_62 = V_11 -> V_59 . V_61 ;
V_11 -> V_59 . free = V_11 -> V_59 . V_60 - V_11 -> V_59 . V_62 ;
V_34 = F_36 ( V_11 , V_63 ) ;
if ( V_34 )
return V_34 ;
for ( V_49 = 0 ; V_49 < V_63 ; V_49 ++ )
F_37 ( V_11 , 0 ) ;
return 0 ;
}
static void
F_38 ( struct V_9 * V_11 )
{
struct V_23 * V_24 = V_11 -> V_24 ;
struct V_47 * V_30 = F_11 ( V_24 -> V_30 ) ;
int V_48 = V_11 -> V_14 ;
F_33 ( V_30 , 0x610028 , 0x00010001 << V_48 , 0x00000000 ) ;
F_33 ( V_30 , F_28 ( V_48 ) , 0x00001010 , 0x00001000 ) ;
F_29 ( V_30 , V_64 , ( 1 << V_48 ) ) ;
F_33 ( V_30 , F_28 ( V_48 ) , 0x00000003 , 0x00000000 ) ;
if ( ! F_35 ( V_30 , F_28 ( V_48 ) , 0x001e0000 , 0x00000000 ) ) {
F_19 ( V_24 , L_4 , V_48 ,
F_27 ( V_30 , F_28 ( V_48 ) ) ) ;
}
}
void
F_39 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = V_25 ( V_21 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
if ( V_26 -> V_65 [ V_49 ] . V_66 . V_51 ) {
F_6 ( V_26 -> V_65 [ V_49 ] . V_66 . V_51 ) ;
F_7 ( NULL , & V_26 -> V_65 [ V_49 ] . V_66 . V_51 ) ;
}
F_5 ( & V_26 -> V_65 [ V_49 ] . V_67 ) ;
}
F_5 ( & V_26 -> V_68 ) ;
F_40 ( NULL , & V_26 -> V_32 ) ;
}
int
F_41 ( struct V_20 * V_21 )
{
struct V_23 * V_24 = V_23 ( V_21 ) ;
struct V_69 * V_70 = V_69 ( V_24 -> V_30 ) ;
struct V_25 * V_26 = V_25 ( V_21 ) ;
struct V_9 * V_11 ;
int V_34 , V_49 , V_71 ;
V_34 = F_42 ( V_24 -> V_30 , NULL , 32768 , 65536 ,
V_72 , & V_26 -> V_32 ) ;
if ( V_34 ) {
F_19 ( V_24 , L_5 , V_34 ) ;
goto V_73;
}
V_26 -> V_28 = 0x0000 ;
V_26 -> V_27 = 0x1000 ;
V_34 = F_15 ( V_21 , 0 , & V_26 -> V_68 ) ;
if ( V_34 )
return V_34 ;
V_11 = V_26 -> V_68 ;
V_34 = F_10 ( V_26 -> V_68 , V_74 , 0x0000 ,
V_26 -> V_32 -> V_3 + 0x2000 , 0x1000 , NULL ) ;
if ( V_34 )
goto V_73;
V_34 = F_10 ( V_26 -> V_68 , V_75 , 0x0000 ,
0 , V_70 -> V_76 . V_17 , NULL ) ;
if ( V_34 )
goto V_73;
V_34 = F_10 ( V_26 -> V_68 , V_77 , 0x80000000 ,
0 , V_70 -> V_76 . V_17 , NULL ) ;
if ( V_34 )
goto V_73;
V_34 = F_10 ( V_26 -> V_68 , V_78 , 0x80000000 |
( F_11 ( V_24 -> V_30 ) -> V_31 < 0xc0 ? 0x7a : 0xfe ) ,
0 , V_70 -> V_76 . V_17 , NULL ) ;
if ( V_34 )
goto V_73;
V_34 = F_10 ( V_26 -> V_68 , V_79 , 0x80000000 |
( F_11 ( V_24 -> V_30 ) -> V_31 < 0xc0 ? 0x70 : 0xfe ) ,
0 , V_70 -> V_76 . V_17 , NULL ) ;
if ( V_34 )
goto V_73;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
struct V_80 * V_81 = & V_26 -> V_65 [ V_49 ] ;
T_3 V_52 ;
V_34 = F_15 ( V_21 , 1 + V_49 , & V_81 -> V_67 ) ;
if ( V_34 )
goto V_73;
V_34 = F_17 ( V_21 , 4096 , 0x1000 , V_39 ,
0 , 0x0000 , NULL , & V_81 -> V_66 . V_51 ) ;
if ( ! V_34 ) {
V_34 = F_18 ( V_81 -> V_66 . V_51 , V_39 ) ;
if ( ! V_34 )
V_34 = F_20 ( V_81 -> V_66 . V_51 ) ;
if ( V_34 )
F_7 ( NULL , & V_81 -> V_66 . V_51 ) ;
V_52 = V_81 -> V_66 . V_51 -> V_51 . V_52 ;
}
if ( V_34 )
goto V_73;
V_34 = F_10 ( V_81 -> V_67 , V_74 , 0x0000 ,
V_52 , 4096 , NULL ) ;
if ( V_34 )
goto V_73;
V_34 = F_10 ( V_81 -> V_67 , V_77 , 0x80000000 ,
0 , V_70 -> V_76 . V_17 , NULL ) ;
if ( V_34 )
goto V_73;
V_34 = F_10 ( V_81 -> V_67 , V_78 , 0x80000000 |
( F_11 ( V_24 -> V_30 ) -> V_31 < 0xc0 ?
0x7a : 0xfe ) ,
0 , V_70 -> V_76 . V_17 , NULL ) ;
if ( V_34 )
goto V_73;
V_34 = F_10 ( V_81 -> V_67 , V_79 , 0x80000000 |
( F_11 ( V_24 -> V_30 ) -> V_31 < 0xc0 ?
0x70 : 0xfe ) ,
0 , V_70 -> V_76 . V_17 , NULL ) ;
if ( V_34 )
goto V_73;
for ( V_71 = 0 ; V_71 < 4096 ; V_71 += 4 )
F_43 ( V_81 -> V_66 . V_51 , V_71 / 4 , 0x74b1e000 ) ;
V_81 -> V_66 . V_52 = 0 ;
}
return 0 ;
V_73:
F_39 ( V_21 ) ;
return V_34 ;
}
int
F_44 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = V_25 ( V_21 ) ;
int V_34 , V_49 ;
V_34 = F_26 ( V_26 -> V_68 ) ;
if ( V_34 )
return V_34 ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
V_34 = F_26 ( V_26 -> V_65 [ V_49 ] . V_67 ) ;
if ( V_34 )
return V_34 ;
}
return 0 ;
}
void
F_45 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = V_25 ( V_21 ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
if ( V_26 -> V_65 [ V_49 ] . V_67 )
F_38 ( V_26 -> V_65 [ V_49 ] . V_67 ) ;
}
if ( V_26 -> V_68 )
F_38 ( V_26 -> V_68 ) ;
}
