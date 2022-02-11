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
V_11 |= F_4 ( & V_10 -> V_25 , V_10 -> V_26 ) ;
V_11 |= F_4 ( & V_10 -> V_27 , 0 ) ;
if ( V_11 )
return 3 ;
if ( V_11 )
return 4 ;
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
F_8 ( V_4 , 0 ) ;
V_4 -> V_35 -> V_36 |= ( V_37 | V_38 ) ;
F_9 ( V_2 , V_4 ) ;
}
return V_39 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
unsigned int V_40 = F_11 ( V_6 -> V_41 ) ;
unsigned int V_42 = F_12 ( V_6 -> V_41 ) ;
unsigned int V_43 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_6 -> V_8 ; V_44 ++ ) {
V_43 = V_7 [ V_44 ] ;
V_29 -> V_45 [ V_40 ] = V_43 ;
if ( F_13 ( V_4 , V_40 , V_42 ) )
V_43 = F_14 ( V_4 , V_43 ) ;
F_15 ( ( V_43 >> 8 ) & 0xff , V_2 -> V_46 + F_16 ( V_40 ) ) ;
F_15 ( V_43 & 0xff , V_2 -> V_46 + F_17 ( V_40 ) ) ;
}
return V_6 -> V_8 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_28 * V_29 = V_2 -> V_30 ;
unsigned int V_40 = F_11 ( V_6 -> V_41 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_6 -> V_8 ; V_44 ++ )
V_7 [ V_44 ] = V_29 -> V_45 [ V_40 ] ;
return V_6 -> V_8 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_47 * V_48 = F_20 ( V_2 ) ;
unsigned int V_43 ;
if ( V_48 -> V_49 ) {
V_43 = F_21 ( V_2 -> V_46 + V_50 ) ;
V_43 |= ( F_21 ( V_2 -> V_46 + V_51 ) << 8 ) ;
} else {
V_43 = F_21 ( V_2 -> V_46 + V_52 ) ;
V_43 |= ( F_21 ( V_2 -> V_46 + V_53 ) << 8 ) ;
}
V_7 [ 1 ] = V_43 ;
return V_6 -> V_8 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_47 * V_48 = F_20 ( V_2 ) ;
unsigned long V_54 = V_2 -> V_46 ;
unsigned int V_55 ;
V_55 = F_23 ( V_4 , V_7 ) ;
if ( V_55 ) {
if ( V_48 -> V_49 ) {
if ( V_55 & 0x00ff )
F_15 ( V_4 -> V_56 & 0xff , V_54 + V_57 ) ;
if ( V_55 & 0xff00 )
F_15 ( ( V_4 -> V_56 >> 8 ) , V_54 + V_58 ) ;
} else {
if ( V_55 & 0x00ff )
F_15 ( V_4 -> V_56 & 0xff , V_54 + V_59 ) ;
if ( V_55 & 0xff00 )
F_15 ( ( V_4 -> V_56 >> 8 ) , V_54 + V_60 ) ;
}
}
V_7 [ 1 ] = V_4 -> V_56 ;
return V_6 -> V_8 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
const struct V_47 * V_48 = F_20 ( V_2 ) ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
int V_63 ;
int V_64 ;
int V_44 ;
V_64 = F_25 ( V_2 , V_62 -> V_65 [ 0 ] , V_48 -> V_66 ) ;
if ( V_64 )
return V_64 ;
V_29 = F_26 ( V_2 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_67 ;
if ( V_62 -> V_65 [ 1 ] && ( V_48 -> V_68 & ( 1 << V_62 -> V_65 [ 1 ] ) ) ) {
V_64 = F_27 ( V_62 -> V_65 [ 1 ] , F_7 , 0 ,
V_2 -> V_69 , V_2 ) ;
if ( V_64 == 0 ) {
V_2 -> V_32 = V_62 -> V_65 [ 1 ] ;
}
}
for ( V_44 = 0 ; V_44 < 12 ; V_44 ++ ) {
unsigned int V_70 = V_62 -> V_65 [ 2 + V_44 ] ;
if ( V_70 < V_48 -> V_71 && V_44 < V_48 -> V_72 )
V_29 -> V_73 [ V_44 ] = V_48 -> V_74 [ V_70 ] ;
else
V_29 -> V_73 [ V_44 ] = & V_75 ;
}
V_63 = V_48 -> V_76 ? 3 : 1 ;
if ( V_2 -> V_32 )
V_63 ++ ;
V_64 = F_28 ( V_2 , V_63 ) ;
if ( V_64 )
return V_64 ;
V_63 = 0 ;
V_4 = & V_2 -> V_77 [ V_63 ++ ] ;
V_4 -> type = V_78 ;
V_4 -> V_79 = V_80 | V_81 ;
V_4 -> V_82 = V_48 -> V_72 ;
V_4 -> V_83 = 0x0fff ;
V_4 -> V_84 = V_29 -> V_73 ;
V_4 -> V_85 = F_10 ;
V_4 -> V_86 = F_18 ;
if ( V_48 -> V_76 ) {
V_4 = & V_2 -> V_77 [ V_63 ++ ] ;
V_4 -> type = V_87 ;
V_4 -> V_79 = V_88 ;
V_4 -> V_82 = 16 ;
V_4 -> V_83 = 1 ;
V_4 -> V_89 = F_19 ;
V_4 -> V_90 = & V_91 ;
V_4 = & V_2 -> V_77 [ V_63 ++ ] ;
V_4 -> type = V_92 ;
V_4 -> V_79 = V_80 ;
V_4 -> V_82 = 16 ;
V_4 -> V_83 = 1 ;
V_4 -> V_89 = F_22 ;
V_4 -> V_90 = & V_91 ;
}
if ( V_2 -> V_32 ) {
V_4 = & V_2 -> V_77 [ V_63 ++ ] ;
V_2 -> V_34 = V_4 ;
V_4 -> type = V_87 ;
V_4 -> V_79 = V_88 | V_93 ;
V_4 -> V_82 = 1 ;
V_4 -> V_83 = 1 ;
V_4 -> V_90 = & V_91 ;
V_4 -> V_89 = F_1 ;
V_4 -> V_94 = 1 ;
V_4 -> V_95 = F_2 ;
V_4 -> V_96 = F_5 ;
V_4 -> V_97 = F_6 ;
}
return 0 ;
}
