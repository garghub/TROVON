static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
F_3 ( V_5 -> V_7 , V_8 , & V_6 ) ;
if ( V_6 & V_9 )
return 66000000 ;
return 33000000 ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long * V_11 )
{
if ( V_10 < 48000000 )
return 33000000 ;
return 66000000 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_10 == 33000000 )
return F_6 ( V_5 -> V_7 ,
V_8 ,
V_9 , 0 ) ;
if ( V_10 == 66000000 )
return F_6 ( V_5 -> V_7 ,
V_8 ,
0 , V_9 ) ;
return - V_12 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_6 ( V_5 -> V_7 , V_13 ,
0 , V_14 ) ;
F_6 ( V_5 -> V_7 ,
V_8 ,
0 , V_15 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_6 ( V_5 -> V_7 ,
V_8 ,
V_15 , 0 ) ;
F_6 ( V_5 -> V_7 , V_13 ,
V_14 , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( V_5 -> V_7 , V_13 , & V_6 ) ;
return ! ! ( V_6 & V_14 ) ;
}
static struct V_1 * F_10 ( const char * V_16 ,
const char * V_17 ,
struct V_18 * V_7 )
{
struct V_4 * V_5 ;
struct V_19 V_20 ;
int V_21 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return F_12 ( - V_23 ) ;
V_20 . V_16 = V_16 ;
V_20 . V_24 = & V_25 ;
V_20 . V_26 = 0 ;
V_20 . V_27 = & V_17 ;
V_20 . V_28 = 1 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_2 . V_20 = & V_20 ;
V_21 = F_13 ( NULL , & V_5 -> V_2 ) ;
if ( V_21 ) {
F_14 ( V_5 ) ;
return F_12 ( V_21 ) ;
}
return & V_5 -> V_2 ;
}
static int F_15 ( struct V_29 * V_30 ,
unsigned long V_31 )
{
struct F_15 * V_32 = F_16 ( V_30 ) ;
return F_17 ( V_32 -> V_7 ,
V_33 ,
F_18 ( V_34 ) | F_18 ( V_31 ) ) ;
}
static int F_19 ( struct V_29 * V_30 ,
unsigned long V_31 )
{
return 0 ;
}
static int F_20 ( struct V_29 * V_30 ,
unsigned long V_31 )
{
return 0 ;
}
static int F_21 ( struct V_29 * V_30 ,
unsigned long V_31 )
{
struct F_15 * V_32 = F_16 ( V_30 ) ;
T_1 V_6 ;
int V_21 ;
V_21 = F_3 ( V_32 -> V_7 , V_33 , & V_6 ) ;
if ( V_21 )
return V_21 ;
return ! ! ( V_6 & F_18 ( V_31 ) ) ;
}
static int F_22 ( struct V_35 * V_36 )
{
unsigned int V_37 [ 4 ] = { 1 , 3 , 24 , 2 } ;
unsigned int V_38 [ 4 ] = { 1 , 2 , 13 , 1 } ;
void T_2 * V_39 ;
struct F_15 * V_32 ;
struct V_18 * V_7 ;
struct V_1 * V_2 ;
struct V_40 * V_41 = & V_36 -> V_41 ;
struct V_42 * V_43 = V_41 -> V_44 ;
unsigned int V_45 , div ;
struct V_46 * V_47 ;
T_1 V_6 ;
int V_21 ;
int V_48 ;
V_32 = F_23 ( V_41 , sizeof( * V_32 ) , V_22 ) ;
if ( ! V_32 )
return - V_23 ;
V_47 = F_24 ( V_36 , V_49 , 0 ) ;
V_39 = F_25 ( V_41 , V_47 ) ;
if ( F_26 ( V_39 ) )
return F_27 ( V_39 ) ;
V_7 = F_28 ( V_43 ) ;
if ( F_26 ( V_7 ) ) {
F_29 ( V_41 , L_1 ) ;
return F_27 ( V_7 ) ;
}
V_32 -> V_7 = V_7 ;
V_32 -> V_30 . V_50 = V_51 ;
V_32 -> V_30 . V_52 = 32 ;
V_32 -> V_30 . V_24 = & V_53 ;
V_32 -> V_30 . V_44 = V_43 ;
V_21 = F_30 ( V_41 , & V_32 -> V_30 ) ;
if ( V_21 ) {
F_29 ( V_41 , L_2 ) ;
return V_21 ;
}
V_2 = F_31 ( NULL , L_3 , NULL , 0 , 32768 ) ;
V_54 -> V_55 [ V_56 ] = V_2 ;
F_3 ( V_7 , V_57 , & V_6 ) ;
V_6 >>= V_58 ;
V_6 &= V_59 ;
V_2 = F_32 ( NULL , L_4 , L_5 , 0 ,
V_37 [ V_6 ] ,
V_38 [ V_6 ] ) ;
V_54 -> V_55 [ V_60 ] = V_2 ;
F_3 ( V_7 , V_13 , & V_6 ) ;
if ( V_6 & V_61 ) {
V_45 = 1 ;
div = 1 ;
} else {
V_45 = 3 ;
div = 4 ;
}
V_2 = F_32 ( NULL , L_6 , L_5 , 0 , V_45 , div ) ;
for ( V_48 = 0 ; V_48 < F_33 ( V_62 ) ; V_48 ++ ) {
const struct V_63 * V_64 ;
V_64 = & V_62 [ V_48 ] ;
V_54 -> V_55 [ V_65 + V_48 ] =
F_34 ( NULL , V_64 -> V_16 ,
V_64 -> V_17 ,
V_64 -> V_26 ,
V_39 + V_13 ,
V_64 -> V_66 ,
V_67 ,
& V_68 ) ;
}
V_45 = 1 ;
div = ( ( V_6 >> V_69 ) & V_70 ) ;
F_35 ( V_41 , L_7 , div ) ;
div += 1 ;
V_2 = F_31 ( NULL , L_8 , L_9 , 0 , 27000000 ) ;
V_54 -> V_55 [ V_71 ] = V_2 ;
V_2 = F_10 ( L_10 , L_9 , V_7 ) ;
V_54 -> V_55 [ V_72 ] = V_2 ;
V_2 = F_31 ( NULL , L_11 , L_9 , 0 , 48000000 ) ;
V_54 -> V_55 [ V_73 ] = V_2 ;
return 0 ;
}
static void T_3 F_36 ( struct V_42 * V_43 )
{
struct V_18 * V_7 ;
struct V_1 * V_2 ;
unsigned long V_74 ;
unsigned int V_45 , div ;
T_1 V_6 ;
int V_21 ;
int V_48 ;
V_54 = F_11 ( sizeof( * V_54 ) +
sizeof( * V_54 -> V_55 ) * V_75 ,
V_22 ) ;
if ( ! V_54 )
return;
for ( V_48 = 0 ; V_48 < V_75 ; V_48 ++ )
V_54 -> V_55 [ V_48 ] = F_12 ( - V_76 ) ;
V_7 = F_28 ( V_43 ) ;
if ( F_26 ( V_7 ) ) {
F_37 ( L_1 ) ;
return;
}
V_21 = F_3 ( V_7 , V_57 , & V_6 ) ;
if ( V_21 ) {
F_37 ( L_12 ) ;
return;
}
if ( V_6 & V_77 )
V_74 = 30000000 ;
else
V_74 = 60000000 ;
V_2 = F_31 ( NULL , L_9 , NULL , 0 , V_74 ) ;
F_38 ( L_13 , V_74 / 1000000 ) ;
V_45 = 13 + ( ( V_6 >> V_78 ) & V_79 ) ;
div = 2 ;
if ( V_6 & V_77 )
V_45 *= 2 ;
V_2 = F_32 ( NULL , L_14 , L_9 , 0 , V_45 , div ) ;
V_2 = F_32 ( NULL , L_5 , L_14 , 0 , 1 , 3 ) ;
V_54 -> V_55 [ V_80 ] = V_2 ;
V_2 = F_32 ( NULL , L_15 , L_5 , 0 , 1 , 6 ) ;
V_54 -> V_55 [ V_81 ] = V_2 ;
V_54 -> V_82 = V_75 ;
F_39 ( V_43 , V_83 , V_54 ) ;
}
