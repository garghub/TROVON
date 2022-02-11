static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
T_1 V_6 , V_7 , V_8 ;
int V_9 = 0 ;
F_4 ( V_5 -> V_5 ) ;
F_5 ( V_3 ) ;
V_6 = F_6 ( V_3 , V_10 ) ;
F_7 ( V_3 ) ;
V_7 = F_8 ( V_6 , V_11 ) ;
V_8 = F_8 ( V_6 , V_12 ) ;
F_9 ( L_1 , V_7 , V_8 ) ;
if ( ( V_7 != 1 ) || ( ( V_8 != 0 ) && ( V_8 != 2 ) ) ) {
F_10 ( V_5 -> V_5 , L_2 ,
V_7 , V_8 ) ;
V_9 = - V_13 ;
goto V_14;
}
V_3 -> V_15 = V_8 ;
F_11 ( V_3 , V_16 , 0 ) ;
F_11 ( V_3 , F_12 ( 0 ) , 0 ) ;
F_11 ( V_3 , F_12 ( 1 ) , 0 ) ;
F_11 ( V_3 , F_12 ( 2 ) , 0 ) ;
F_11 ( V_3 , F_12 ( 3 ) , 0 ) ;
V_14:
F_13 ( V_5 -> V_5 ) ;
return V_9 ;
}
static long F_14 ( struct V_1 * V_2 , unsigned long V_17 ,
struct V_18 * V_19 )
{
return V_17 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_22 * V_23 = V_3 -> V_5 -> V_24 ;
unsigned V_25 ;
for ( V_25 = 0 ; V_25 < V_23 -> V_26 ; V_25 ++ )
F_16 ( V_23 -> V_27 [ V_25 ] , V_21 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_18 ( V_3 ) ;
}
int F_7 ( struct V_3 * V_3 )
{
F_9 ( L_3 ) ;
F_19 ( V_3 -> V_28 ) ;
F_19 ( V_3 -> V_29 ) ;
F_19 ( V_3 -> V_30 ) ;
F_19 ( V_3 -> V_31 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_3 )
{
F_9 ( L_3 ) ;
F_20 ( V_3 -> V_28 ) ;
F_20 ( V_3 -> V_29 ) ;
F_20 ( V_3 -> V_30 ) ;
F_20 ( V_3 -> V_31 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_3 )
{
static const enum V_32 V_27 [] = {
V_33 , V_34 , V_35 ,
} ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_5 -> V_24 ;
struct V_18 * V_19 ;
int V_25 , V_9 ;
for ( V_25 = 0 ; V_25 < F_22 ( V_27 ) ; V_25 ++ ) {
struct V_36 * V_37 ;
struct V_38 * V_39 ;
V_37 = F_23 ( V_5 , V_27 [ V_25 ] , true ) ;
if ( F_24 ( V_37 ) ) {
V_9 = F_25 ( V_37 ) ;
F_10 ( V_5 -> V_5 , L_4 ,
F_26 ( V_27 [ V_25 ] ) , V_9 ) ;
goto V_40;
}
V_39 = F_27 ( V_5 , V_37 , V_25 ) ;
if ( F_24 ( V_39 ) ) {
V_9 = F_25 ( V_39 ) ;
F_10 ( V_5 -> V_5 , L_5 ,
F_26 ( V_27 [ V_25 ] ) , V_9 ) ;
goto V_40;
}
V_23 -> V_27 [ V_23 -> V_26 ++ ] = V_39 ;
}
V_19 = F_28 ( V_5 , 3 , V_41 ) ;
if ( F_24 ( V_19 ) ) {
F_10 ( V_5 -> V_5 , L_6 ) ;
V_9 = F_25 ( V_19 ) ;
goto V_40;
}
V_19 -> V_42 = F_29 ( 0 ) ;
F_30 ( V_23 -> V_27 [ 0 ] , 3 , V_41 ) ;
V_23 -> V_43 [ V_23 -> V_44 ++ ] = V_19 ;
V_3 -> V_45 = F_31 ( V_5 , V_19 ) ;
if ( F_24 ( V_3 -> V_45 ) ) {
V_9 = F_25 ( V_3 -> V_45 ) ;
F_10 ( V_5 -> V_5 , L_7 , V_9 ) ;
goto V_40;
}
return 0 ;
V_40:
return V_9 ;
}
static int F_32 ( struct V_46 * V_47 , struct V_48 * * V_49 ,
const char * V_50 )
{
struct V_51 * V_5 = & V_47 -> V_5 ;
struct V_48 * V_48 = F_33 ( V_5 , V_50 ) ;
if ( F_24 ( V_48 ) ) {
F_10 ( V_5 , L_8 , V_50 , F_25 ( V_48 ) ) ;
return F_25 ( V_48 ) ;
}
* V_49 = V_48 ;
return 0 ;
}
struct V_1 * F_34 ( struct V_4 * V_5 )
{
struct V_46 * V_47 = V_5 -> V_52 ;
struct V_53 * V_54 = F_35 ( V_47 ) ;
struct V_3 * V_3 ;
struct V_1 * V_2 = NULL ;
struct V_55 * V_56 ;
int V_9 ;
V_3 = F_36 ( sizeof( * V_3 ) , V_57 ) ;
if ( ! V_3 ) {
F_10 ( V_5 -> V_5 , L_9 ) ;
V_9 = - V_58 ;
goto V_40;
}
F_37 ( & V_3 -> V_59 , & V_60 ) ;
V_2 = & V_3 -> V_59 . V_59 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_61 = V_54 -> V_61 ;
V_3 -> V_62 = F_38 ( V_47 , L_10 , L_11 ) ;
if ( F_24 ( V_3 -> V_62 ) ) {
V_9 = F_25 ( V_3 -> V_62 ) ;
goto V_40;
}
V_3 -> V_63 = F_38 ( V_47 , L_12 , L_13 ) ;
if ( F_24 ( V_3 -> V_63 ) ) {
V_9 = F_25 ( V_3 -> V_63 ) ;
goto V_40;
}
V_3 -> V_64 = F_39 ( & V_47 -> V_5 , L_14 ) ;
if ( F_24 ( V_3 -> V_64 ) ) {
V_9 = F_25 ( V_3 -> V_64 ) ;
goto V_40;
}
V_9 = F_40 ( V_3 -> V_64 ) ;
if ( V_9 ) {
F_10 ( V_5 -> V_5 , L_15 , V_9 ) ;
goto V_40;
}
V_9 = F_32 ( V_47 , & V_3 -> V_29 , L_16 ) ||
F_32 ( V_47 , & V_3 -> V_28 , L_17 ) ||
F_32 ( V_47 , & V_3 -> V_65 , L_18 ) ||
F_32 ( V_47 , & V_3 -> V_30 , L_19 ) ||
F_32 ( V_47 , & V_3 -> V_31 , L_20 ) ||
F_32 ( V_47 , & V_3 -> V_66 , L_21 ) ;
if ( V_9 )
goto V_40;
V_9 = F_41 ( V_3 -> V_65 , V_54 -> V_67 ) ;
F_5 ( V_3 ) ;
F_11 ( V_3 , F_42 ( 0 ) , 0 ) ;
F_11 ( V_3 , F_42 ( 1 ) , 0 ) ;
F_11 ( V_3 , F_42 ( 2 ) , 0 ) ;
F_11 ( V_3 , F_42 ( 3 ) , 0 ) ;
F_7 ( V_3 ) ;
F_43 ( 16 ) ;
if ( V_54 -> V_68 ) {
V_56 = F_44 ( V_5 , V_54 -> V_68 ) ;
if ( F_24 ( V_56 ) ) {
V_9 = F_25 ( V_56 ) ;
goto V_40;
}
V_9 = V_56 -> V_69 -> V_70 ( V_56 , V_71 ,
F_22 ( V_71 ) ) ;
if ( V_9 )
goto V_40;
} else {
F_45 ( V_5 -> V_5 , L_22
L_23 ) ;
V_56 = NULL ;
}
V_3 -> V_72 = F_46 ( V_5 , V_56 ) ;
if ( V_3 -> V_72 < 0 ) {
V_9 = V_3 -> V_72 ;
F_10 ( V_5 -> V_5 , L_24 , V_9 ) ;
goto V_40;
}
V_9 = F_21 ( V_3 ) ;
if ( V_9 ) {
F_10 ( V_5 -> V_5 , L_25 , V_9 ) ;
goto V_40;
}
return V_2 ;
V_40:
if ( V_2 )
F_17 ( V_2 ) ;
return F_47 ( V_9 ) ;
}
static struct V_53 * F_35 ( struct V_46 * V_5 )
{
static struct V_53 V_54 = {} ;
#ifdef F_48
#endif
return & V_54 ;
}
