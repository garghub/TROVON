static int F_1 ( struct V_1 * V_2 )
{
char * V_3 ;
int V_4 ;
if ( ! V_2 -> V_5 )
V_3 = L_1 ;
else if ( V_2 -> V_6 || V_2 -> V_7 == V_8 )
V_3 = L_2 ;
else
V_3 = L_3 ;
V_4 = F_2 ( V_2 , V_3 ) ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_11 . V_12 ;
int V_13 ;
if ( V_10 -> V_14 != F_4 ( 0x8129 ) )
return - V_15 ;
F_5 ( V_2 -> V_16 , V_10 -> V_16 ) ;
memcpy ( V_2 -> V_17 ,
V_10 -> V_17 ,
sizeof( V_10 -> V_17 ) ) ;
memcpy ( V_2 -> V_18 ,
V_10 -> V_18 ,
sizeof( V_10 -> V_18 ) ) ;
memcpy ( V_2 -> V_19 ,
V_10 -> V_19 ,
sizeof( V_10 -> V_19 ) ) ;
memcpy ( V_2 -> V_20 ,
V_10 -> V_20 ,
sizeof( V_10 -> V_20 ) ) ;
memcpy ( V_2 -> V_21 ,
V_10 -> V_21 ,
sizeof( V_10 -> V_21 ) ) ;
memcpy ( V_2 -> V_22 ,
V_10 -> V_22 ,
sizeof( V_10 -> V_22 ) ) ;
memcpy ( V_2 -> V_23 ,
V_10 -> V_23 ,
sizeof( V_10 -> V_23 ) ) ;
memcpy ( V_2 -> V_24 ,
V_10 -> V_24 ,
sizeof( V_10 -> V_24 ) ) ;
memcpy ( V_2 -> V_25 ,
V_10 -> V_25 ,
sizeof( V_10 -> V_25 ) ) ;
F_6 ( & V_2 -> V_26 -> V_27 , L_4 ,
V_10 -> V_28 ) ;
F_6 ( & V_2 -> V_26 -> V_27 , L_5 ,
V_10 -> V_29 ) ;
V_2 -> V_30 = & V_31 ;
if ( V_10 -> V_32 & 0x20 ) {
sprintf ( V_2 -> V_33 , L_6 ) ;
V_2 -> V_7 = V_34 ;
V_2 -> V_35 = 1 ;
V_2 -> V_36 = 1 ;
V_2 -> V_30 = & V_37 ;
}
if ( V_38 & V_39 ) {
unsigned char * V_40 = V_2 -> V_11 . V_40 ;
F_6 ( & V_2 -> V_26 -> V_27 ,
L_7 ,
V_41 , sizeof( struct V_9 ) ) ;
for ( V_13 = 0 ; V_13 < sizeof( struct V_9 ) ; V_13 += 8 ) {
F_6 ( & V_2 -> V_26 -> V_27 , L_8
L_9 , V_13 ,
V_40 [ V_13 ] , V_40 [ V_13 + 1 ] , V_40 [ V_13 + 2 ] ,
V_40 [ V_13 + 3 ] , V_40 [ V_13 + 4 ] , V_40 [ V_13 + 5 ] ,
V_40 [ V_13 + 6 ] , V_40 [ V_13 + 7 ] ) ;
}
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
int V_4 ;
if ( V_2 -> V_7 == V_34 ) {
V_43 = V_44 ;
V_4 = F_8 ( V_2 , V_43 , V_45 ) ;
} else if ( V_2 -> V_46 == 1 ) {
V_43 = V_47 ;
V_4 = F_8 ( V_2 , V_43 , V_45 ) ;
} else {
V_43 = V_48 ;
V_4 = F_8 ( V_2 , V_43 , V_45 ) ;
if ( V_4 )
goto exit;
V_43 = V_49 ;
V_4 = F_8 ( V_2 , V_43 , V_50 ) ;
}
exit:
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_51 ;
T_2 V_52 ;
T_3 V_53 ;
int V_13 ;
for ( V_13 = 100 ; V_13 ; V_13 -- ) {
V_51 = F_10 ( V_2 , V_54 ) ;
if ( V_51 & V_55 )
break;
}
if ( ! V_13 ) {
F_11 ( L_10 , V_41 ) ;
return - V_56 ;
}
F_12 ( V_2 , V_57 , 0x0 ) ;
F_12 ( V_2 , V_58 , 0x2b ) ;
F_13 ( 100 ) ;
V_51 = F_10 ( V_2 , V_59 ) ;
if ( ! ( V_51 & V_60 ) ) {
F_11 ( L_11 , V_41 , V_51 ) ;
V_51 |= V_60 ;
F_12 ( V_2 , V_59 , V_51 ) ;
F_13 ( 100 ) ;
V_51 = F_10 ( V_2 , V_61 ) ;
V_51 &= ~ V_62 ;
F_12 ( V_2 , V_61 , V_51 ) ;
}
V_52 = F_14 ( V_2 , V_54 ) ;
V_52 |= V_63 ;
F_15 ( V_2 , V_54 , V_52 ) ;
for ( V_13 = 1000 ; V_13 ; V_13 -- ) {
V_52 = F_14 ( V_2 , V_54 ) ;
if ( ! ( V_52 & V_63 ) )
break;
}
if ( ! V_13 ) {
F_11 ( L_12 , V_41 ) ;
return - V_64 ;
}
V_52 = V_65 | V_66 |
V_55 ;
F_15 ( V_2 , V_54 , V_52 ) ;
V_52 = F_14 ( V_2 , V_61 ) ;
V_52 &= ~ V_67 ;
F_15 ( V_2 , V_61 , V_52 ) ;
V_51 = F_10 ( V_2 , V_68 ) ;
V_51 &= ~ V_69 ;
F_12 ( V_2 , V_68 , V_51 ) ;
for ( V_13 = 200 ; V_13 ; V_13 -- ) {
V_51 = F_10 ( V_2 , V_68 ) ;
if ( ! ( V_51 & V_70 ) )
break;
}
if ( ! V_13 ) {
F_11 ( L_13 , V_41 ) ;
return - V_64 ;
}
V_52 = F_14 ( V_2 , V_71 ) ;
V_52 |= V_72 | V_73 |
V_74 | V_75 | V_76 |
V_77 | V_78 | V_79 ;
F_15 ( V_2 , V_71 , V_52 ) ;
F_12 ( V_2 , 0xfe10 , 0x19 ) ;
if ( V_2 -> V_7 == V_34 ) {
V_53 = F_16 ( V_2 , V_80 ) ;
V_53 &= ~ F_17 ( 1 ) ;
F_18 ( V_2 , V_80 , V_53 ) ;
}
return 0 ;
}
