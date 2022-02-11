static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = 0 ;
return V_6 -> V_8 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_9 * V_10 )
{
int V_11 = 0 ;
V_11 |= F_3 ( & V_10 -> V_12 , V_13 ) ;
V_11 |= F_3 ( & V_10 -> V_14 , V_15 ) ;
V_11 |= F_3 ( & V_10 -> V_16 , V_17 ) ;
V_11 |= F_3 ( & V_10 -> V_18 , V_19 ) ;
V_11 |= F_3 ( & V_10 -> V_20 , V_21 ) ;
if ( V_11 )
return 1 ;
V_11 |= F_4 ( & V_10 -> V_22 , 0 ) ;
V_11 |= F_4 ( & V_10 -> V_23 , 0 ) ;
V_11 |= F_4 ( & V_10 -> V_24 , 0 ) ;
V_11 |= F_4 ( & V_10 -> V_25 ,
V_10 -> V_26 ) ;
V_11 |= F_4 ( & V_10 -> V_27 , 0 ) ;
if ( V_11 )
return 3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
V_29 -> V_31 = 1 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
V_29 -> V_31 = 0 ;
return 0 ;
}
static T_1 F_7 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_3 * V_4 = V_2 -> V_34 ;
struct V_28 * V_29 = V_2 -> V_30 ;
if ( V_29 -> V_31 ) {
F_6 ( V_2 , V_4 ) ;
F_8 ( V_4 , & V_4 -> V_35 , 1 ) ;
F_9 ( V_2 , V_4 ) ;
}
return V_36 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_37 = F_11 ( V_6 -> V_38 ) ;
unsigned int V_39 = F_12 ( V_6 -> V_38 ) ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_6 -> V_8 ; V_40 ++ ) {
unsigned int V_41 = V_7 [ V_40 ] ;
V_4 -> V_42 [ V_37 ] = V_41 ;
if ( F_13 ( V_4 , V_37 , V_39 ) )
V_41 = F_14 ( V_4 , V_41 ) ;
F_15 ( ( V_41 >> 8 ) & 0xff , V_2 -> V_43 + F_16 ( V_37 ) ) ;
F_15 ( V_41 & 0xff , V_2 -> V_43 + F_17 ( V_37 ) ) ;
}
return V_6 -> V_8 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_44 * V_45 = V_2 -> V_46 ;
unsigned int V_41 ;
if ( V_45 -> V_47 ) {
V_41 = F_19 ( V_2 -> V_43 + V_48 ) ;
V_41 |= ( F_19 ( V_2 -> V_43 + V_49 ) << 8 ) ;
} else {
V_41 = F_19 ( V_2 -> V_43 + V_50 ) ;
V_41 |= ( F_19 ( V_2 -> V_43 + V_51 ) << 8 ) ;
}
V_7 [ 1 ] = V_41 ;
return V_6 -> V_8 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_44 * V_45 = V_2 -> V_46 ;
unsigned long V_52 = V_2 -> V_43 ;
unsigned int V_53 ;
V_53 = F_21 ( V_4 , V_7 ) ;
if ( V_53 ) {
if ( V_45 -> V_47 ) {
if ( V_53 & 0x00ff )
F_15 ( V_4 -> V_35 & 0xff , V_52 + V_54 ) ;
if ( V_53 & 0xff00 )
F_15 ( ( V_4 -> V_35 >> 8 ) , V_52 + V_55 ) ;
} else {
if ( V_53 & 0x00ff )
F_15 ( V_4 -> V_35 & 0xff , V_52 + V_56 ) ;
if ( V_53 & 0xff00 )
F_15 ( ( V_4 -> V_35 >> 8 ) , V_52 + V_57 ) ;
}
}
V_7 [ 1 ] = V_4 -> V_35 ;
return V_6 -> V_8 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
const struct V_44 * V_45 = V_2 -> V_46 ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
int V_60 ;
int V_61 ;
int V_40 ;
V_61 = F_23 ( V_2 , V_59 -> V_62 [ 0 ] , V_45 -> V_63 ) ;
if ( V_61 )
return V_61 ;
V_29 = F_24 ( V_2 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_64 ;
if ( V_59 -> V_62 [ 1 ] && ( V_45 -> V_65 & ( 1 << V_59 -> V_62 [ 1 ] ) ) ) {
V_61 = F_25 ( V_59 -> V_62 [ 1 ] , F_7 , 0 ,
V_2 -> V_66 , V_2 ) ;
if ( V_61 == 0 ) {
V_2 -> V_32 = V_59 -> V_62 [ 1 ] ;
}
}
for ( V_40 = 0 ; V_40 < 12 ; V_40 ++ ) {
unsigned int V_67 = V_59 -> V_62 [ 2 + V_40 ] ;
if ( V_67 < V_45 -> V_68 && V_40 < V_45 -> V_69 )
V_29 -> V_70 [ V_40 ] = V_45 -> V_71 [ V_67 ] ;
else
V_29 -> V_70 [ V_40 ] = & V_72 ;
}
V_60 = V_45 -> V_73 ? 3 : 1 ;
if ( V_2 -> V_32 )
V_60 ++ ;
V_61 = F_26 ( V_2 , V_60 ) ;
if ( V_61 )
return V_61 ;
V_60 = 0 ;
V_4 = & V_2 -> V_74 [ V_60 ++ ] ;
V_4 -> type = V_75 ;
V_4 -> V_76 = V_77 | V_78 ;
V_4 -> V_79 = V_45 -> V_69 ;
V_4 -> V_80 = 0x0fff ;
V_4 -> V_81 = V_29 -> V_70 ;
V_4 -> V_82 = F_10 ;
V_61 = F_27 ( V_4 ) ;
if ( V_61 )
return V_61 ;
if ( V_45 -> V_73 ) {
V_4 = & V_2 -> V_74 [ V_60 ++ ] ;
V_4 -> type = V_83 ;
V_4 -> V_76 = V_84 ;
V_4 -> V_79 = 16 ;
V_4 -> V_80 = 1 ;
V_4 -> V_85 = F_18 ;
V_4 -> V_86 = & V_87 ;
V_4 = & V_2 -> V_74 [ V_60 ++ ] ;
V_4 -> type = V_88 ;
V_4 -> V_76 = V_77 ;
V_4 -> V_79 = 16 ;
V_4 -> V_80 = 1 ;
V_4 -> V_85 = F_20 ;
V_4 -> V_86 = & V_87 ;
}
if ( V_2 -> V_32 ) {
V_4 = & V_2 -> V_74 [ V_60 ++ ] ;
V_2 -> V_34 = V_4 ;
V_4 -> type = V_83 ;
V_4 -> V_76 = V_84 | V_89 ;
V_4 -> V_79 = 1 ;
V_4 -> V_80 = 1 ;
V_4 -> V_86 = & V_87 ;
V_4 -> V_85 = F_1 ;
V_4 -> V_90 = 1 ;
V_4 -> V_91 = F_2 ;
V_4 -> V_92 = F_5 ;
V_4 -> V_93 = F_6 ;
}
return 0 ;
}
