int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = V_9 -> V_13 ;
int V_14 ;
V_14 = F_2 ( V_12 , V_4 -> V_15 == V_16 ? 7 : 11 ) ;
if ( V_14 )
return V_14 ;
if ( V_4 -> V_15 != V_16 ) {
F_3 ( V_12 , V_17 , 0x02ac , 1 ) ;
F_4 ( V_12 , 1 ) ;
}
F_3 ( V_12 , V_17 , 0x0588 , 1 ) ;
if ( V_2 -> V_18 . V_19 == V_20 ||
V_2 -> V_18 . V_19 == V_21 )
F_4 ( V_12 , ( ( V_22 * ) V_2 -> V_23 ) [ V_4 -> V_24 ] ) ;
else
F_4 ( V_12 , V_4 -> V_24 ) ;
F_3 ( V_12 , V_17 , 0x0600 , 4 ) ;
F_4 ( V_12 , V_4 -> V_25 ) ;
F_4 ( V_12 , V_4 -> V_26 ) ;
F_4 ( V_12 , V_4 -> V_25 + V_4 -> V_27 ) ;
F_4 ( V_12 , V_4 -> V_26 + V_4 -> V_28 ) ;
if ( V_4 -> V_15 != V_16 ) {
F_3 ( V_12 , V_17 , 0x02ac , 1 ) ;
F_4 ( V_12 , 3 ) ;
}
F_5 ( V_12 ) ;
return 0 ;
}
int
F_6 ( struct V_1 * V_2 , const struct V_29 * V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = V_9 -> V_13 ;
int V_14 ;
V_14 = F_2 ( V_12 , 12 ) ;
if ( V_14 )
return V_14 ;
F_3 ( V_12 , V_17 , 0x0110 , 1 ) ;
F_4 ( V_12 , 0 ) ;
F_3 ( V_12 , V_17 , 0x08b0 , 4 ) ;
F_4 ( V_12 , V_30 -> V_25 ) ;
F_4 ( V_12 , V_30 -> V_26 ) ;
F_4 ( V_12 , V_30 -> V_27 ) ;
F_4 ( V_12 , V_30 -> V_28 ) ;
F_3 ( V_12 , V_17 , 0x08d0 , 4 ) ;
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , V_30 -> V_31 ) ;
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , V_30 -> V_32 ) ;
F_5 ( V_12 ) ;
return 0 ;
}
int
F_7 ( struct V_1 * V_2 , const struct V_33 * V_34 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = V_9 -> V_13 ;
V_22 V_27 , V_35 , * V_36 = ( V_22 * ) V_34 -> V_36 ;
V_22 V_37 = ~ ( ~ 0 >> ( 32 - V_2 -> V_38 . V_39 ) ) ;
V_22 * V_40 = V_2 -> V_23 ;
int V_14 ;
if ( V_34 -> V_41 != 1 )
return - V_42 ;
V_14 = F_2 ( V_12 , 11 ) ;
if ( V_14 )
return V_14 ;
V_27 = F_8 ( V_34 -> V_27 , 32 ) ;
V_35 = ( V_27 * V_34 -> V_28 ) >> 5 ;
F_3 ( V_12 , V_17 , 0x0814 , 2 ) ;
if ( V_2 -> V_18 . V_19 == V_20 ||
V_2 -> V_18 . V_19 == V_21 ) {
F_4 ( V_12 , V_40 [ V_34 -> V_43 ] | V_37 ) ;
F_4 ( V_12 , V_40 [ V_34 -> V_44 ] | V_37 ) ;
} else {
F_4 ( V_12 , V_34 -> V_43 ) ;
F_4 ( V_12 , V_34 -> V_44 ) ;
}
F_3 ( V_12 , V_17 , 0x0838 , 2 ) ;
F_4 ( V_12 , V_34 -> V_27 ) ;
F_4 ( V_12 , V_34 -> V_28 ) ;
F_3 ( V_12 , V_17 , 0x0850 , 4 ) ;
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , V_34 -> V_25 ) ;
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , V_34 -> V_26 ) ;
while ( V_35 ) {
int V_45 = V_35 > 2047 ? 2047 : V_35 ;
V_14 = F_2 ( V_12 , V_45 + 1 ) ;
if ( V_14 )
return V_14 ;
V_35 -= V_45 ;
F_9 ( V_12 , V_17 , 0x0860 , V_45 ) ;
F_10 ( V_12 , V_36 , V_45 ) ;
V_36 += V_45 ;
}
F_5 ( V_12 ) ;
return 0 ;
}
int
F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_46 * V_47 = & V_6 -> V_48 ;
struct V_49 * V_10 = V_6 -> V_10 ;
struct V_8 * V_9 = V_8 ( V_10 ) ;
struct V_11 * V_12 = V_9 -> V_13 ;
int V_14 , V_50 ;
switch ( V_2 -> V_38 . V_39 ) {
case 8 :
V_50 = 0xf3 ;
break;
case 15 :
V_50 = 0xf8 ;
break;
case 16 :
V_50 = 0xe8 ;
break;
case 32 :
switch ( V_2 -> V_38 . V_51 . V_52 ) {
case 0 :
case 8 :
V_50 = 0xe6 ;
break;
case 2 :
V_50 = 0xd1 ;
break;
default:
return - V_53 ;
}
break;
default:
return - V_53 ;
}
V_14 = F_12 ( & V_12 -> V_54 , 0x502d , 0x502d , NULL , 0 ,
& V_6 -> V_55 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_2 ( V_12 , 58 ) ;
if ( V_14 ) {
F_13 ( V_2 ) ;
return V_14 ;
}
F_3 ( V_12 , V_17 , 0x0000 , 1 ) ;
F_4 ( V_12 , V_6 -> V_55 . V_56 ) ;
F_3 ( V_12 , V_17 , 0x0184 , 3 ) ;
F_4 ( V_12 , V_12 -> V_57 . V_56 ) ;
F_4 ( V_12 , V_12 -> V_57 . V_56 ) ;
F_4 ( V_12 , V_12 -> V_57 . V_56 ) ;
F_3 ( V_12 , V_17 , 0x0290 , 1 ) ;
F_4 ( V_12 , 0 ) ;
F_3 ( V_12 , V_17 , 0x0888 , 1 ) ;
F_4 ( V_12 , 1 ) ;
F_3 ( V_12 , V_17 , 0x02ac , 1 ) ;
F_4 ( V_12 , 3 ) ;
F_3 ( V_12 , V_17 , 0x02a0 , 1 ) ;
F_4 ( V_12 , 0x55 ) ;
F_3 ( V_12 , V_17 , 0x08c0 , 4 ) ;
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , 1 ) ;
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , 1 ) ;
F_3 ( V_12 , V_17 , 0x0580 , 2 ) ;
F_4 ( V_12 , 4 ) ;
F_4 ( V_12 , V_50 ) ;
F_3 ( V_12 , V_17 , 0x02e8 , 2 ) ;
F_4 ( V_12 , 2 ) ;
F_4 ( V_12 , 1 ) ;
F_3 ( V_12 , V_17 , 0x0804 , 1 ) ;
F_4 ( V_12 , V_50 ) ;
F_3 ( V_12 , V_17 , 0x0800 , 1 ) ;
F_4 ( V_12 , 1 ) ;
F_3 ( V_12 , V_17 , 0x0808 , 3 ) ;
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , 1 ) ;
F_3 ( V_12 , V_17 , 0x081c , 1 ) ;
F_4 ( V_12 , 1 ) ;
F_3 ( V_12 , V_17 , 0x0840 , 4 ) ;
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , 1 ) ;
F_4 ( V_12 , 0 ) ;
F_4 ( V_12 , 1 ) ;
F_3 ( V_12 , V_17 , 0x0200 , 2 ) ;
F_4 ( V_12 , V_50 ) ;
F_4 ( V_12 , 1 ) ;
F_3 ( V_12 , V_17 , 0x0214 , 5 ) ;
F_4 ( V_12 , V_2 -> V_18 . V_58 ) ;
F_4 ( V_12 , V_2 -> V_38 . V_59 ) ;
F_4 ( V_12 , V_2 -> V_38 . V_60 ) ;
F_4 ( V_12 , F_14 ( V_47 -> V_61 . V_62 ) ) ;
F_4 ( V_12 , F_15 ( V_47 -> V_61 . V_62 ) ) ;
F_3 ( V_12 , V_17 , 0x0230 , 2 ) ;
F_4 ( V_12 , V_50 ) ;
F_4 ( V_12 , 1 ) ;
F_3 ( V_12 , V_17 , 0x0244 , 5 ) ;
F_4 ( V_12 , V_2 -> V_18 . V_58 ) ;
F_4 ( V_12 , V_2 -> V_38 . V_59 ) ;
F_4 ( V_12 , V_2 -> V_38 . V_60 ) ;
F_4 ( V_12 , F_14 ( V_47 -> V_61 . V_62 ) ) ;
F_4 ( V_12 , F_15 ( V_47 -> V_61 . V_62 ) ) ;
F_5 ( V_12 ) ;
return 0 ;
}
