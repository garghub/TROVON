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
if ( V_11 )
return 2 ;
V_11 |= F_4 ( & V_10 -> V_22 , 0 ) ;
V_11 |= F_4 ( & V_10 -> V_23 , 0 ) ;
V_11 |= F_4 ( & V_10 -> V_24 , 0 ) ;
V_11 |= F_4 ( & V_10 -> V_25 , 1 ) ;
V_11 |= F_4 ( & V_10 -> V_26 , 0 ) ;
if ( V_11 )
return 3 ;
if ( V_11 )
return 4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_27 * V_28 = V_2 -> V_29 ;
V_28 -> V_30 = 1 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_27 * V_28 = V_2 -> V_29 ;
V_28 -> V_30 = 0 ;
return 0 ;
}
static T_1 F_7 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_3 * V_4 = V_2 -> V_33 ;
struct V_27 * V_28 = V_2 -> V_29 ;
if ( V_28 -> V_30 ) {
F_6 ( V_2 , V_4 ) ;
F_8 ( V_4 -> V_34 , 0 ) ;
V_4 -> V_34 -> V_35 |= ( V_36 | V_37 ) ;
F_9 ( V_2 , V_4 ) ;
}
return V_38 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_27 * V_28 = V_2 -> V_29 ;
unsigned int V_39 = F_11 ( V_6 -> V_40 ) ;
unsigned int V_41 = F_12 ( V_6 -> V_40 ) ;
unsigned int V_42 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_6 -> V_8 ; V_43 ++ ) {
V_42 = V_7 [ V_43 ] ;
V_28 -> V_44 [ V_39 ] = V_42 ;
if ( F_13 ( V_4 , V_39 , V_41 ) )
V_42 = F_14 ( V_4 , V_42 ) ;
F_15 ( ( V_42 >> 8 ) & 0xff , V_2 -> V_45 + F_16 ( V_39 ) ) ;
F_15 ( V_42 & 0xff , V_2 -> V_45 + F_17 ( V_39 ) ) ;
}
return V_6 -> V_8 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_27 * V_28 = V_2 -> V_29 ;
unsigned int V_39 = F_11 ( V_6 -> V_40 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_6 -> V_8 ; V_43 ++ )
V_7 [ V_43 ] = V_28 -> V_44 [ V_39 ] ;
return V_6 -> V_8 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_46 * V_47 = F_20 ( V_2 ) ;
unsigned int V_42 ;
if ( V_47 -> V_48 ) {
V_42 = F_21 ( V_2 -> V_45 + V_49 ) ;
V_42 |= ( F_21 ( V_2 -> V_45 + V_50 ) << 8 ) ;
} else {
V_42 = F_21 ( V_2 -> V_45 + V_51 ) ;
V_42 |= ( F_21 ( V_2 -> V_45 + V_52 ) << 8 ) ;
}
V_7 [ 1 ] = V_42 ;
return V_6 -> V_8 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_46 * V_47 = F_20 ( V_2 ) ;
unsigned long V_53 = V_2 -> V_45 ;
unsigned int V_54 ;
V_54 = F_23 ( V_4 , V_7 ) ;
if ( V_54 ) {
if ( V_47 -> V_48 ) {
if ( V_54 & 0x00ff )
F_15 ( V_4 -> V_55 & 0xff , V_53 + V_56 ) ;
if ( V_54 & 0xff00 )
F_15 ( ( V_4 -> V_55 >> 8 ) , V_53 + V_57 ) ;
} else {
if ( V_54 & 0x00ff )
F_15 ( V_4 -> V_55 & 0xff , V_53 + V_58 ) ;
if ( V_54 & 0xff00 )
F_15 ( ( V_4 -> V_55 >> 8 ) , V_53 + V_59 ) ;
}
}
V_7 [ 1 ] = V_4 -> V_55 ;
return V_6 -> V_8 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
const struct V_46 * V_47 = F_20 ( V_2 ) ;
struct V_27 * V_28 ;
struct V_3 * V_4 ;
int V_62 ;
int V_63 ;
int V_43 ;
V_63 = F_25 ( V_2 , V_61 -> V_64 [ 0 ] , V_47 -> V_65 ) ;
if ( V_63 )
return V_63 ;
V_28 = F_26 ( V_2 , sizeof( * V_28 ) ) ;
if ( ! V_28 )
return - V_66 ;
if ( V_61 -> V_64 [ 1 ] && ( V_47 -> V_67 & ( 1 << V_61 -> V_64 [ 1 ] ) ) ) {
V_63 = F_27 ( V_61 -> V_64 [ 1 ] , F_7 , 0 ,
V_2 -> V_68 , V_2 ) ;
if ( V_63 == 0 ) {
V_2 -> V_31 = V_61 -> V_64 [ 1 ] ;
}
}
for ( V_43 = 0 ; V_43 < 12 ; V_43 ++ ) {
unsigned int V_69 = V_61 -> V_64 [ 2 + V_43 ] ;
if ( V_69 < V_47 -> V_70 && V_43 < V_47 -> V_71 )
V_28 -> V_72 [ V_43 ] = V_47 -> V_73 [ V_69 ] ;
else
V_28 -> V_72 [ V_43 ] = & V_74 ;
}
V_62 = V_47 -> V_75 ? 3 : 1 ;
if ( V_2 -> V_31 )
V_62 ++ ;
V_63 = F_28 ( V_2 , V_62 ) ;
if ( V_63 )
return V_63 ;
V_62 = 0 ;
V_4 = & V_2 -> V_76 [ V_62 ++ ] ;
V_4 -> type = V_77 ;
V_4 -> V_78 = V_79 | V_80 ;
V_4 -> V_81 = V_47 -> V_71 ;
V_4 -> V_82 = 0x0fff ;
V_4 -> V_83 = V_28 -> V_72 ;
V_4 -> V_84 = F_10 ;
V_4 -> V_85 = F_18 ;
if ( V_47 -> V_75 ) {
V_4 = & V_2 -> V_76 [ V_62 ++ ] ;
V_4 -> type = V_86 ;
V_4 -> V_78 = V_87 ;
V_4 -> V_81 = 16 ;
V_4 -> V_82 = 1 ;
V_4 -> V_88 = F_19 ;
V_4 -> V_89 = & V_90 ;
V_4 = & V_2 -> V_76 [ V_62 ++ ] ;
V_4 -> type = V_91 ;
V_4 -> V_78 = V_79 ;
V_4 -> V_81 = 16 ;
V_4 -> V_82 = 1 ;
V_4 -> V_88 = F_22 ;
V_4 -> V_89 = & V_90 ;
}
if ( V_2 -> V_31 ) {
V_4 = & V_2 -> V_76 [ V_62 ++ ] ;
V_2 -> V_33 = V_4 ;
V_4 -> type = V_86 ;
V_4 -> V_78 = V_87 | V_92 ;
V_4 -> V_81 = 1 ;
V_4 -> V_82 = 1 ;
V_4 -> V_89 = & V_90 ;
V_4 -> V_88 = F_1 ;
V_4 -> V_93 = F_2 ;
V_4 -> V_94 = F_5 ;
V_4 -> V_95 = F_6 ;
}
return 0 ;
}
