int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
int V_15 ;
V_15 = F_2 ( V_13 , 4 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_13 , V_16 , 0x0300 , 3 ) ;
F_4 ( V_13 , ( V_4 -> V_17 << 16 ) | V_4 -> V_18 ) ;
F_4 ( V_13 , ( V_4 -> V_19 << 16 ) | V_4 -> V_20 ) ;
F_4 ( V_13 , ( V_4 -> V_21 << 16 ) | V_4 -> V_22 ) ;
F_5 ( V_13 ) ;
return 0 ;
}
int
F_6 ( struct V_1 * V_2 , const struct V_23 * V_24 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
int V_15 ;
V_15 = F_2 ( V_13 , 7 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_13 , V_25 , 0x02fc , 1 ) ;
F_4 ( V_13 , ( V_24 -> V_26 != V_27 ) ? 1 : 3 ) ;
F_3 ( V_13 , V_25 , 0x03fc , 1 ) ;
if ( V_2 -> V_28 . V_29 == V_30 ||
V_2 -> V_28 . V_29 == V_31 )
F_4 ( V_13 , ( ( V_32 * ) V_2 -> V_33 ) [ V_24 -> V_34 ] ) ;
else
F_4 ( V_13 , V_24 -> V_34 ) ;
F_3 ( V_13 , V_25 , 0x0400 , 2 ) ;
F_4 ( V_13 , ( V_24 -> V_20 << 16 ) | V_24 -> V_19 ) ;
F_4 ( V_13 , ( V_24 -> V_22 << 16 ) | V_24 -> V_21 ) ;
F_5 ( V_13 ) ;
return 0 ;
}
int
F_7 ( struct V_1 * V_2 , const struct V_35 * V_36 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
V_32 V_37 ;
V_32 V_38 ;
V_32 V_39 ;
V_32 * V_40 = ( V_32 * ) V_36 -> V_40 ;
int V_15 ;
if ( V_36 -> V_41 != 1 )
return - V_42 ;
V_15 = F_2 ( V_13 , 8 ) ;
if ( V_15 )
return V_15 ;
if ( V_2 -> V_28 . V_29 == V_30 ||
V_2 -> V_28 . V_29 == V_31 ) {
V_37 = ( ( V_32 * ) V_2 -> V_33 ) [ V_36 -> V_43 ] ;
V_38 = ( ( V_32 * ) V_2 -> V_33 ) [ V_36 -> V_44 ] ;
} else {
V_37 = V_36 -> V_43 ;
V_38 = V_36 -> V_44 ;
}
F_3 ( V_13 , V_25 , 0x0be4 , 7 ) ;
F_4 ( V_13 , ( V_36 -> V_19 << 16 ) | ( V_36 -> V_20 & 0xffff ) ) ;
F_4 ( V_13 , ( ( V_36 -> V_19 + V_36 -> V_21 ) << 16 ) |
( ( V_36 -> V_20 + V_36 -> V_22 ) & 0xffff ) ) ;
F_4 ( V_13 , V_38 ) ;
F_4 ( V_13 , V_37 ) ;
F_4 ( V_13 , ( V_36 -> V_21 << 16 ) | F_8 ( V_36 -> V_22 , 8 ) ) ;
F_4 ( V_13 , ( V_36 -> V_21 << 16 ) | V_36 -> V_22 ) ;
F_4 ( V_13 , ( V_36 -> V_19 << 16 ) | ( V_36 -> V_20 & 0xffff ) ) ;
V_39 = F_8 ( F_8 ( V_36 -> V_22 , 8 ) * V_36 -> V_21 , 32 ) >> 5 ;
while ( V_39 ) {
int V_45 = V_39 > 128 ? 128 : V_39 ;
V_15 = F_2 ( V_13 , V_45 + 1 ) ;
if ( V_15 )
return V_15 ;
F_3 ( V_13 , V_25 , 0x0c00 , V_45 ) ;
F_9 ( V_13 , V_40 , V_45 ) ;
V_40 += V_45 ;
V_39 -= V_45 ;
}
F_5 ( V_13 ) ;
return 0 ;
}
int
F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_46 * V_11 = V_6 -> V_10 . V_11 ;
struct V_8 * V_9 = V_8 ( V_11 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_47 * V_48 = & V_9 -> V_49 . V_48 ;
int V_50 , V_51 , V_52 ;
int V_15 ;
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
V_15 = F_11 ( & V_13 -> V_58 , 0x0062 ,
V_48 -> V_2 . V_59 >= V_60 ?
0x0062 : 0x0042 , NULL , 0 , & V_6 -> V_61 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_11 ( & V_13 -> V_58 , 0x0019 , 0x0019 , NULL , 0 ,
& V_6 -> V_62 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_11 ( & V_13 -> V_58 , 0x0043 , 0x0043 , NULL , 0 ,
& V_6 -> V_26 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_11 ( & V_13 -> V_58 , 0x0044 , 0x0044 , NULL , 0 ,
& V_6 -> V_63 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_11 ( & V_13 -> V_58 , 0x004a , 0x004a , NULL , 0 ,
& V_6 -> V_64 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_11 ( & V_13 -> V_58 , 0x005f ,
V_48 -> V_2 . V_65 >= 0x11 ? 0x009f : 0x005f ,
NULL , 0 , & V_6 -> V_66 ) ;
if ( V_15 )
return V_15 ;
if ( F_2 ( V_13 , 49 + ( V_48 -> V_2 . V_65 >= 0x11 ? 4 : 0 ) ) ) {
F_12 ( V_2 ) ;
return 0 ;
}
F_3 ( V_13 , V_67 , 0x0000 , 1 ) ;
F_4 ( V_13 , V_6 -> V_61 . V_68 ) ;
F_3 ( V_13 , V_67 , 0x0184 , 2 ) ;
F_4 ( V_13 , V_13 -> V_69 . V_68 ) ;
F_4 ( V_13 , V_13 -> V_69 . V_68 ) ;
F_3 ( V_13 , V_67 , 0x0300 , 4 ) ;
F_4 ( V_13 , V_50 ) ;
F_4 ( V_13 , V_2 -> V_28 . V_70 | ( V_2 -> V_28 . V_70 << 16 ) ) ;
F_4 ( V_13 , V_2 -> V_28 . V_71 - V_11 -> V_72 . V_73 ) ;
F_4 ( V_13 , V_2 -> V_28 . V_71 - V_11 -> V_72 . V_73 ) ;
F_3 ( V_13 , V_67 , 0x0000 , 1 ) ;
F_4 ( V_13 , V_6 -> V_26 . V_68 ) ;
F_3 ( V_13 , V_67 , 0x0300 , 1 ) ;
F_4 ( V_13 , 0x55 ) ;
F_3 ( V_13 , V_67 , 0x0000 , 1 ) ;
F_4 ( V_13 , V_6 -> V_63 . V_68 ) ;
F_3 ( V_13 , V_67 , 0x0300 , 8 ) ;
F_4 ( V_13 , V_51 ) ;
#ifdef F_13
F_4 ( V_13 , 2 ) ;
#else
F_4 ( V_13 , 1 ) ;
#endif
F_4 ( V_13 , 0 ) ;
F_4 ( V_13 , 1 ) ;
F_4 ( V_13 , ~ 0 ) ;
F_4 ( V_13 , ~ 0 ) ;
F_4 ( V_13 , ~ 0 ) ;
F_4 ( V_13 , ~ 0 ) ;
F_3 ( V_13 , V_67 , 0x0000 , 1 ) ;
F_4 ( V_13 , V_6 -> V_62 . V_68 ) ;
F_3 ( V_13 , V_67 , 0x0300 , 2 ) ;
F_4 ( V_13 , 0 ) ;
F_4 ( V_13 , ( V_2 -> V_53 . V_74 << 16 ) | V_2 -> V_53 . V_75 ) ;
F_3 ( V_13 , V_16 , 0x0000 , 1 ) ;
F_4 ( V_13 , V_6 -> V_66 . V_68 ) ;
F_3 ( V_13 , V_16 , 0x019c , 1 ) ;
F_4 ( V_13 , V_6 -> V_61 . V_68 ) ;
F_3 ( V_13 , V_16 , 0x02fc , 1 ) ;
F_4 ( V_13 , 3 ) ;
if ( V_48 -> V_2 . V_65 >= 0x11 ) {
F_3 ( V_13 , V_16 , 0x0120 , 3 ) ;
F_4 ( V_13 , 0 ) ;
F_4 ( V_13 , 1 ) ;
F_4 ( V_13 , 2 ) ;
}
F_3 ( V_13 , V_25 , 0x0000 , 1 ) ;
F_4 ( V_13 , V_6 -> V_64 . V_68 ) ;
F_3 ( V_13 , V_25 , 0x0198 , 1 ) ;
F_4 ( V_13 , V_6 -> V_61 . V_68 ) ;
F_3 ( V_13 , V_25 , 0x0188 , 2 ) ;
F_4 ( V_13 , V_6 -> V_63 . V_68 ) ;
F_4 ( V_13 , V_6 -> V_26 . V_68 ) ;
F_3 ( V_13 , V_25 , 0x0304 , 1 ) ;
F_4 ( V_13 , 1 ) ;
F_3 ( V_13 , V_25 , 0x0300 , 1 ) ;
F_4 ( V_13 , V_52 ) ;
F_3 ( V_13 , V_25 , 0x02fc , 1 ) ;
F_4 ( V_13 , 3 ) ;
F_5 ( V_13 ) ;
return 0 ;
}
