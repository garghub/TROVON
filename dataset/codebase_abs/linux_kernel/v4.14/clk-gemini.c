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
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
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
static struct V_1 * F_10 ( const char * V_15 ,
const char * V_16 ,
struct V_17 * V_7 )
{
struct V_4 * V_5 ;
struct V_18 V_19 ;
int V_20 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_21 ) ;
if ( ! V_5 )
return F_12 ( - V_22 ) ;
V_19 . V_15 = V_15 ;
V_19 . V_23 = & V_24 ;
V_19 . V_25 = 0 ;
V_19 . V_26 = & V_16 ;
V_19 . V_27 = 1 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_2 . V_19 = & V_19 ;
V_20 = F_13 ( NULL , & V_5 -> V_2 ) ;
if ( V_20 ) {
F_14 ( V_5 ) ;
return F_12 ( V_20 ) ;
}
return & V_5 -> V_2 ;
}
static int F_15 ( struct V_28 * V_29 ,
unsigned long V_30 )
{
struct F_15 * V_31 = F_16 ( V_29 ) ;
return F_17 ( V_31 -> V_7 ,
V_32 ,
F_18 ( V_33 ) | F_18 ( V_30 ) ) ;
}
static int F_19 ( struct V_28 * V_29 ,
unsigned long V_30 )
{
return 0 ;
}
static int F_20 ( struct V_28 * V_29 ,
unsigned long V_30 )
{
return 0 ;
}
static int F_21 ( struct V_28 * V_29 ,
unsigned long V_30 )
{
struct F_15 * V_31 = F_16 ( V_29 ) ;
T_1 V_6 ;
int V_20 ;
V_20 = F_3 ( V_31 -> V_7 , V_32 , & V_6 ) ;
if ( V_20 )
return V_20 ;
return ! ! ( V_6 & F_18 ( V_30 ) ) ;
}
static int F_22 ( struct V_34 * V_35 )
{
unsigned int V_36 [ 4 ] = { 1 , 3 , 24 , 2 } ;
unsigned int V_37 [ 4 ] = { 1 , 2 , 13 , 1 } ;
void T_2 * V_38 ;
struct F_15 * V_31 ;
struct V_17 * V_7 ;
struct V_1 * V_2 ;
struct V_39 * V_40 = & V_35 -> V_40 ;
struct V_41 * V_42 = V_40 -> V_43 ;
unsigned int V_44 , div ;
struct V_45 * V_46 ;
T_1 V_6 ;
int V_20 ;
int V_47 ;
V_31 = F_23 ( V_40 , sizeof( * V_31 ) , V_21 ) ;
if ( ! V_31 )
return - V_22 ;
V_46 = F_24 ( V_35 , V_48 , 0 ) ;
V_38 = F_25 ( V_40 , V_46 ) ;
if ( F_26 ( V_38 ) )
return F_27 ( V_38 ) ;
V_7 = F_28 ( V_42 ) ;
if ( F_26 ( V_7 ) ) {
F_29 ( V_40 , L_1 ) ;
return F_27 ( V_7 ) ;
}
V_31 -> V_7 = V_7 ;
V_31 -> V_29 . V_49 = V_50 ;
V_31 -> V_29 . V_51 = 32 ;
V_31 -> V_29 . V_23 = & V_52 ;
V_31 -> V_29 . V_43 = V_42 ;
V_20 = F_30 ( V_40 , & V_31 -> V_29 ) ;
if ( V_20 ) {
F_29 ( V_40 , L_2 ) ;
return V_20 ;
}
V_2 = F_31 ( NULL , L_3 , NULL , 0 , 32768 ) ;
V_53 -> V_54 [ V_55 ] = V_2 ;
F_3 ( V_7 , V_56 , & V_6 ) ;
V_6 >>= V_57 ;
V_6 &= V_58 ;
V_2 = F_32 ( NULL , L_4 , L_5 , 0 ,
V_36 [ V_6 ] ,
V_37 [ V_6 ] ) ;
V_53 -> V_54 [ V_59 ] = V_2 ;
F_3 ( V_7 , V_13 , & V_6 ) ;
if ( V_6 & V_60 ) {
V_44 = 1 ;
div = 1 ;
} else {
V_44 = 3 ;
div = 4 ;
}
V_2 = F_32 ( NULL , L_6 , L_5 , 0 , V_44 , div ) ;
for ( V_47 = 0 ; V_47 < F_33 ( V_61 ) ; V_47 ++ ) {
const struct V_62 * V_63 ;
V_63 = & V_61 [ V_47 ] ;
V_53 -> V_54 [ V_64 + V_47 ] =
F_34 ( NULL , V_63 -> V_15 ,
V_63 -> V_16 ,
V_63 -> V_25 ,
V_38 + V_13 ,
V_63 -> V_65 ,
V_66 ,
& V_67 ) ;
}
V_44 = 1 ;
div = ( ( V_6 >> V_68 ) & V_69 ) ;
F_35 ( V_40 , L_7 , div ) ;
div += 1 ;
V_2 = F_31 ( NULL , L_8 , L_9 , 0 , 27000000 ) ;
V_53 -> V_54 [ V_70 ] = V_2 ;
V_2 = F_10 ( L_10 , L_9 , V_7 ) ;
V_53 -> V_54 [ V_71 ] = V_2 ;
V_2 = F_31 ( NULL , L_11 , L_9 , 0 , 48000000 ) ;
V_53 -> V_54 [ V_72 ] = V_2 ;
return 0 ;
}
static void T_3 F_36 ( struct V_41 * V_42 )
{
struct V_17 * V_7 ;
struct V_1 * V_2 ;
unsigned long V_73 ;
unsigned int V_44 , div ;
T_1 V_6 ;
int V_20 ;
int V_47 ;
V_53 = F_11 ( sizeof( * V_53 ) +
sizeof( * V_53 -> V_54 ) * V_74 ,
V_21 ) ;
if ( ! V_53 )
return;
for ( V_47 = 0 ; V_47 < V_74 ; V_47 ++ )
V_53 -> V_54 [ V_47 ] = F_12 ( - V_75 ) ;
V_7 = F_28 ( V_42 ) ;
if ( F_26 ( V_7 ) ) {
F_37 ( L_1 ) ;
return;
}
V_20 = F_3 ( V_7 , V_56 , & V_6 ) ;
if ( V_20 ) {
F_37 ( L_12 ) ;
return;
}
if ( V_6 & V_76 )
V_73 = 30000000 ;
else
V_73 = 60000000 ;
V_2 = F_31 ( NULL , L_9 , NULL , 0 , V_73 ) ;
F_38 ( L_13 , V_73 / 1000000 ) ;
V_44 = 13 + ( ( V_6 >> V_77 ) & V_78 ) ;
div = 2 ;
if ( V_6 & V_76 )
V_44 *= 2 ;
V_2 = F_32 ( NULL , L_14 , L_9 , 0 , V_44 , div ) ;
V_2 = F_32 ( NULL , L_5 , L_14 , 0 , 1 , 3 ) ;
V_53 -> V_54 [ V_79 ] = V_2 ;
V_2 = F_32 ( NULL , L_15 , L_5 , 0 , 1 , 6 ) ;
V_53 -> V_54 [ V_80 ] = V_2 ;
V_53 -> V_81 = V_74 ;
F_39 ( V_42 , V_82 , V_53 ) ;
}
