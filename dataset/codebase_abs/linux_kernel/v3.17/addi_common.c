static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned short V_13 = F_3 ( V_6 -> V_14 ) ;
unsigned short V_15 ;
V_15 = F_4 ( V_11 -> V_16 ,
V_9 -> V_17 , 2 * V_13 ) ;
V_7 [ 0 ] = V_15 ;
return V_6 -> V_18 ;
}
static T_1 F_5 ( int V_19 , void * V_20 )
{
struct V_1 * V_2 = V_20 ;
const struct V_8 * V_9 = F_2 ( V_2 ) ;
V_9 -> V_21 ( V_19 , V_20 ) ;
return F_6 ( 1 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
V_9 -> V_22 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_23 )
{
struct V_24 * V_25 = F_9 ( V_2 ) ;
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
struct V_3 * V_4 ;
int V_26 , V_27 ;
unsigned int V_28 ;
V_2 -> V_29 = V_9 -> V_30 ;
V_11 = F_10 ( V_2 , sizeof( * V_11 ) ) ;
if ( ! V_11 )
return - V_31 ;
V_26 = F_11 ( V_2 ) ;
if ( V_26 )
return V_26 ;
if ( V_9 -> V_32 )
V_2 -> V_33 = F_12 ( V_25 , 1 ) ;
else
V_2 -> V_33 = F_12 ( V_25 , 0 ) ;
V_11 -> V_33 = V_2 -> V_33 ;
V_11 -> V_16 = F_12 ( V_25 , 0 ) ;
V_11 -> V_34 = F_12 ( V_25 , 2 ) ;
V_11 -> V_35 = F_12 ( V_25 , 3 ) ;
V_11 -> V_36 . V_37 = V_9 -> V_37 ;
V_11 -> V_36 . V_38 = V_9 -> V_38 ;
V_11 -> V_36 . V_39 = V_9 -> V_39 ;
V_11 -> V_36 . V_40 = V_9 -> V_40 ;
V_11 -> V_36 . V_41 = V_9 -> V_41 ;
V_11 -> V_36 . V_42 = V_9 -> V_42 ;
V_11 -> V_36 . V_43 = V_9 -> V_43 ;
V_11 -> V_36 . V_44 = V_9 -> V_44 ;
V_11 -> V_36 . V_45 =
V_9 -> V_45 ;
V_11 -> V_36 . V_46 =
V_9 -> V_46 ;
if ( V_25 -> V_19 > 0 ) {
V_26 = F_13 ( V_25 -> V_19 , F_5 , V_47 ,
V_2 -> V_29 , V_2 ) ;
if ( V_26 == 0 )
V_2 -> V_19 = V_25 -> V_19 ;
}
if ( V_9 -> V_48 ) {
if ( ! ( strcmp ( V_9 -> V_17 , L_1 ) ) ) {
if ( ! ( strcmp ( V_2 -> V_29 , L_2 ) ) )
F_14 ( 0x80808082 , V_11 -> V_16 + 0x60 ) ;
else
F_14 ( 0x83838383 , V_11 -> V_16 + 0x60 ) ;
V_28 = F_15 ( V_11 -> V_16 + 0x38 ) ;
F_14 ( V_28 | 0x2000 , V_11 -> V_16 + 0x38 ) ;
}
F_16 ( V_2 , F_12 ( V_25 , 0 ) ) ;
}
V_27 = 7 ;
V_26 = F_17 ( V_2 , V_27 ) ;
if ( V_26 )
return V_26 ;
V_4 = & V_2 -> V_49 [ 0 ] ;
if ( ( V_11 -> V_36 . V_37 )
|| ( V_9 -> V_50 ) ) {
V_2 -> V_51 = V_4 ;
V_4 -> type = V_52 ;
V_4 -> V_53 =
V_54 | V_55 | V_56
| V_57 ;
if ( V_11 -> V_36 . V_37 )
V_4 -> V_58 = V_11 -> V_36 . V_37 ;
else
V_4 -> V_58 = V_9 -> V_50 ;
V_4 -> V_59 = V_11 -> V_36 . V_39 ;
V_4 -> V_60 = V_9 -> V_61 ;
V_4 -> V_62 = V_9 -> V_63 ;
V_4 -> V_64 = V_9 -> V_65 ;
V_4 -> V_66 = V_9 -> V_67 ;
V_4 -> V_68 = V_9 -> V_69 ;
V_4 -> V_70 = V_9 -> V_71 ;
V_4 -> V_72 = V_9 -> V_73 ;
V_4 -> V_74 = V_9 -> V_75 ;
V_4 -> V_76 = V_9 -> V_77 ;
} else {
V_4 -> type = V_78 ;
}
V_4 = & V_2 -> V_49 [ 1 ] ;
if ( V_11 -> V_36 . V_38 ) {
V_4 -> type = V_79 ;
V_4 -> V_53 = V_80 | V_56 | V_55 ;
V_4 -> V_58 = V_11 -> V_36 . V_38 ;
V_4 -> V_59 = V_11 -> V_36 . V_40 ;
V_4 -> V_60 =
V_11 -> V_36 . V_38 ;
V_4 -> V_68 = V_9 -> V_81 ;
} else {
V_4 -> type = V_78 ;
}
V_4 = & V_2 -> V_49 [ 2 ] ;
if ( V_11 -> V_36 . V_41 ) {
V_4 -> type = V_82 ;
V_4 -> V_53 = V_54 | V_56 | V_55 ;
V_4 -> V_58 = V_11 -> V_36 . V_41 ;
V_4 -> V_59 = 1 ;
V_4 -> V_60 =
V_11 -> V_36 . V_41 ;
V_4 -> V_62 = & V_83 ;
V_4 -> V_64 = V_9 -> V_84 ;
V_4 -> V_66 = V_9 -> V_85 ;
V_4 -> V_68 = V_9 -> V_86 ;
V_4 -> V_70 = V_9 -> V_87 ;
} else {
V_4 -> type = V_78 ;
}
V_4 = & V_2 -> V_49 [ 3 ] ;
if ( V_11 -> V_36 . V_42 ) {
V_4 -> type = V_88 ;
V_4 -> V_53 =
V_54 | V_80 | V_56 | V_55 ;
V_4 -> V_58 = V_11 -> V_36 . V_42 ;
V_4 -> V_59 = V_11 -> V_36 . V_43 ;
V_4 -> V_60 =
V_11 -> V_36 . V_42 ;
V_4 -> V_62 = & V_83 ;
V_4 -> V_64 = V_9 -> V_89 ;
V_4 -> V_68 = V_9 -> V_90 ;
V_4 -> V_70 = V_9 -> V_91 ;
V_4 -> V_66 = V_9 -> V_92 ;
} else {
V_4 -> type = V_78 ;
}
V_4 = & V_2 -> V_49 [ 4 ] ;
if ( V_11 -> V_36 . V_44 ) {
V_4 -> type = V_93 ;
V_4 -> V_53 = V_80 | V_56 | V_55 ;
V_4 -> V_58 = 1 ;
V_4 -> V_59 = 0 ;
V_4 -> V_60 = 1 ;
V_4 -> V_62 = & V_83 ;
V_4 -> V_68 = V_9 -> V_94 ;
V_4 -> V_66 = V_9 -> V_95 ;
V_4 -> V_64 = V_9 -> V_96 ;
V_4 -> V_70 = V_9 -> V_97 ;
} else {
V_4 -> type = V_78 ;
}
V_4 = & V_2 -> V_49 [ 5 ] ;
V_4 -> type = V_78 ;
V_4 = & V_2 -> V_49 [ 6 ] ;
if ( V_9 -> V_48 ) {
V_4 -> type = V_98 ;
V_4 -> V_53 = V_54 | V_99 ;
V_4 -> V_58 = 256 ;
V_4 -> V_59 = 0xffff ;
V_4 -> V_66 = F_1 ;
} else {
V_4 -> type = V_78 ;
}
F_7 ( V_2 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
if ( V_11 ) {
if ( V_2 -> V_33 )
F_7 ( V_2 ) ;
if ( V_2 -> V_19 )
F_19 ( V_2 -> V_19 , V_2 ) ;
}
F_20 ( V_2 ) ;
}
