int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = V_9 -> V_13 ;
int V_14 ;
V_14 = F_2 ( V_12 , 4 ) ;
if ( V_14 )
return V_14 ;
F_3 ( V_12 , V_15 , 0x0300 , 3 ) ;
F_4 ( V_12 , ( V_4 -> V_16 << 16 ) | V_4 -> V_17 ) ;
F_4 ( V_12 , ( V_4 -> V_18 << 16 ) | V_4 -> V_19 ) ;
F_4 ( V_12 , ( V_4 -> V_20 << 16 ) | V_4 -> V_21 ) ;
F_5 ( V_12 ) ;
return 0 ;
}
int
F_6 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = V_9 -> V_13 ;
int V_14 ;
V_14 = F_2 ( V_12 , 7 ) ;
if ( V_14 )
return V_14 ;
F_3 ( V_12 , V_24 , 0x02fc , 1 ) ;
F_4 ( V_12 , ( V_23 -> V_25 != V_26 ) ? 1 : 3 ) ;
F_3 ( V_12 , V_24 , 0x03fc , 1 ) ;
if ( V_2 -> V_27 . V_28 == V_29 ||
V_2 -> V_27 . V_28 == V_30 )
F_4 ( V_12 , ( ( V_31 * ) V_2 -> V_32 ) [ V_23 -> V_33 ] ) ;
else
F_4 ( V_12 , V_23 -> V_33 ) ;
F_3 ( V_12 , V_24 , 0x0400 , 2 ) ;
F_4 ( V_12 , ( V_23 -> V_19 << 16 ) | V_23 -> V_18 ) ;
F_4 ( V_12 , ( V_23 -> V_21 << 16 ) | V_23 -> V_20 ) ;
F_5 ( V_12 ) ;
return 0 ;
}
int
F_7 ( struct V_1 * V_2 , const struct V_34 * V_35 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = V_9 -> V_13 ;
V_31 V_36 ;
V_31 V_37 ;
V_31 V_38 ;
V_31 V_21 ;
V_31 * V_39 = ( V_31 * ) V_35 -> V_39 ;
int V_14 ;
if ( V_35 -> V_40 != 1 )
return - V_41 ;
V_14 = F_2 ( V_12 , 8 ) ;
if ( V_14 )
return V_14 ;
V_21 = F_8 ( V_35 -> V_21 , 8 ) ;
V_38 = F_8 ( V_21 * V_35 -> V_20 , 32 ) >> 5 ;
if ( V_2 -> V_27 . V_28 == V_29 ||
V_2 -> V_27 . V_28 == V_30 ) {
V_36 = ( ( V_31 * ) V_2 -> V_32 ) [ V_35 -> V_42 ] ;
V_37 = ( ( V_31 * ) V_2 -> V_32 ) [ V_35 -> V_43 ] ;
} else {
V_36 = V_35 -> V_42 ;
V_37 = V_35 -> V_43 ;
}
F_3 ( V_12 , V_24 , 0x0be4 , 7 ) ;
F_4 ( V_12 , ( V_35 -> V_18 << 16 ) | ( V_35 -> V_19 & 0xffff ) ) ;
F_4 ( V_12 , ( ( V_35 -> V_18 + V_35 -> V_20 ) << 16 ) |
( ( V_35 -> V_19 + V_35 -> V_21 ) & 0xffff ) ) ;
F_4 ( V_12 , V_37 ) ;
F_4 ( V_12 , V_36 ) ;
F_4 ( V_12 , ( V_35 -> V_20 << 16 ) | V_21 ) ;
F_4 ( V_12 , ( V_35 -> V_20 << 16 ) | V_35 -> V_21 ) ;
F_4 ( V_12 , ( V_35 -> V_18 << 16 ) | ( V_35 -> V_19 & 0xffff ) ) ;
while ( V_38 ) {
int V_44 = V_38 > 128 ? 128 : V_38 ;
V_14 = F_2 ( V_12 , V_44 + 1 ) ;
if ( V_14 )
return V_14 ;
F_3 ( V_12 , V_24 , 0x0c00 , V_44 ) ;
F_9 ( V_12 , V_39 , V_44 ) ;
V_39 += V_44 ;
V_38 -= V_44 ;
}
F_5 ( V_12 ) ;
return 0 ;
}
int
F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_45 * V_10 = V_6 -> V_10 ;
struct V_8 * V_9 = V_8 ( V_10 ) ;
struct V_11 * V_12 = V_9 -> V_13 ;
struct V_46 * V_47 = F_11 ( V_9 -> V_47 ) ;
struct V_48 * V_49 ;
int V_50 , V_51 , V_52 ;
int V_14 ;
switch ( V_2 -> V_53 . V_54 ) {
case 8 :
V_50 = 1 ;
V_51 = 3 ;
V_52 = 3 ;
break;
case 16 :
V_50 = 4 ;
V_51 = 1 ;
V_52 = 1 ;
break;
case 32 :
switch ( V_2 -> V_53 . V_55 . V_56 ) {
case 0 :
case 8 :
break;
default:
return - V_57 ;
}
V_50 = 6 ;
V_51 = 3 ;
V_52 = 3 ;
break;
default:
return - V_57 ;
}
V_14 = F_12 ( F_13 ( V_12 -> V_58 ) , V_59 , V_60 ,
V_47 -> V_61 >= V_62 ? 0x0062 : 0x0042 ,
NULL , 0 , & V_49 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_12 ( F_13 ( V_12 -> V_58 ) , V_59 , V_63 ,
0x0019 , NULL , 0 , & V_49 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_12 ( F_13 ( V_12 -> V_58 ) , V_59 , V_64 ,
0x0043 , NULL , 0 , & V_49 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_12 ( F_13 ( V_12 -> V_58 ) , V_59 , V_65 ,
0x0044 , NULL , 0 , & V_49 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_12 ( F_13 ( V_12 -> V_58 ) , V_59 , V_66 ,
0x004a , NULL , 0 , & V_49 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_12 ( F_13 ( V_12 -> V_58 ) , V_59 , V_67 ,
V_47 -> V_68 >= 0x11 ? 0x009f : 0x005f ,
NULL , 0 , & V_49 ) ;
if ( V_14 )
return V_14 ;
if ( F_2 ( V_12 , 49 ) ) {
F_14 ( V_2 ) ;
return 0 ;
}
F_3 ( V_12 , V_69 , 0x0000 , 1 ) ;
F_4 ( V_12 , V_60 ) ;
F_3 ( V_12 , V_69 , 0x0184 , 2 ) ;
F_4 ( V_12 , V_70 ) ;
F_4 ( V_12 , V_70 ) ;
F_3 ( V_12 , V_69 , 0x0300 , 4 ) ;
F_4 ( V_12 , V_50 ) ;
F_4 ( V_12 , V_2 -> V_27 . V_71 | ( V_2 -> V_27 . V_71 << 16 ) ) ;
F_4 ( V_12 , V_2 -> V_27 . V_72 - V_10 -> V_73 . V_74 ) ;
F_4 ( V_12 , V_2 -> V_27 . V_72 - V_10 -> V_73 . V_74 ) ;
F_3 ( V_12 , V_69 , 0x0000 , 1 ) ;
F_4 ( V_12 , V_64 ) ;
F_3 ( V_12 , V_69 , 0x0300 , 1 ) ;
F_4 ( V_12 , 0x55 ) ;
F_3 ( V_12 , V_69 , 0x0000 , 1 ) ;
F_4 ( V_12 , V_65 ) ;
F_3 ( V_12 , V_69 , 0x0300 , 8 ) ;
F_4 ( V_12 , V_51 ) ;
#ifdef F_15
F_4 ( V_12 , 2 ) ;
#else
F_4 ( V_12 , 1 ) ;
#endif
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , 1 ) ;
F_4 ( V_12 , ~ 0 ) ;
F_4 ( V_12 , ~ 0 ) ;
F_4 ( V_12 , ~ 0 ) ;
F_4 ( V_12 , ~ 0 ) ;
F_3 ( V_12 , V_69 , 0x0000 , 1 ) ;
F_4 ( V_12 , V_63 ) ;
F_3 ( V_12 , V_69 , 0x0300 , 2 ) ;
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , ( V_2 -> V_53 . V_75 << 16 ) | V_2 -> V_53 . V_76 ) ;
F_3 ( V_12 , V_15 , 0x0000 , 1 ) ;
F_4 ( V_12 , V_67 ) ;
F_3 ( V_12 , V_15 , 0x019c , 1 ) ;
F_4 ( V_12 , V_60 ) ;
F_3 ( V_12 , V_15 , 0x02fc , 1 ) ;
F_4 ( V_12 , 3 ) ;
F_3 ( V_12 , V_24 , 0x0000 , 1 ) ;
F_4 ( V_12 , V_66 ) ;
F_3 ( V_12 , V_24 , 0x0198 , 1 ) ;
F_4 ( V_12 , V_60 ) ;
F_3 ( V_12 , V_24 , 0x0188 , 2 ) ;
F_4 ( V_12 , V_65 ) ;
F_4 ( V_12 , V_64 ) ;
F_3 ( V_12 , V_24 , 0x0304 , 1 ) ;
F_4 ( V_12 , 1 ) ;
F_3 ( V_12 , V_24 , 0x0300 , 1 ) ;
F_4 ( V_12 , V_52 ) ;
F_3 ( V_12 , V_24 , 0x02fc , 1 ) ;
F_4 ( V_12 , 3 ) ;
F_5 ( V_12 ) ;
return 0 ;
}
