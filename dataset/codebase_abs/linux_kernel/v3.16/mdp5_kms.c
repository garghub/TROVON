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
struct V_28 * V_29 = V_3 -> V_29 ;
if ( V_29 ) {
V_29 -> V_30 -> V_31 ( V_29 , V_32 , F_18 ( V_32 ) ) ;
V_29 -> V_30 -> V_33 ( V_29 ) ;
}
F_19 ( V_3 ) ;
}
int F_7 ( struct V_3 * V_3 )
{
F_9 ( L_3 ) ;
F_20 ( V_3 -> V_34 ) ;
F_20 ( V_3 -> V_35 ) ;
F_20 ( V_3 -> V_36 ) ;
F_20 ( V_3 -> V_37 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_3 )
{
F_9 ( L_3 ) ;
F_21 ( V_3 -> V_34 ) ;
F_21 ( V_3 -> V_35 ) ;
F_21 ( V_3 -> V_36 ) ;
F_21 ( V_3 -> V_37 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_3 )
{
static const enum V_38 V_27 [] = {
V_39 , V_40 , V_41 ,
} ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_22 * V_23 = V_5 -> V_24 ;
struct V_18 * V_19 ;
int V_25 , V_9 ;
for ( V_25 = 0 ; V_25 < F_18 ( V_27 ) ; V_25 ++ ) {
struct V_42 * V_43 ;
struct V_44 * V_45 ;
V_43 = F_23 ( V_5 , V_27 [ V_25 ] , true ) ;
if ( F_24 ( V_43 ) ) {
V_9 = F_25 ( V_43 ) ;
F_10 ( V_5 -> V_5 , L_4 ,
F_26 ( V_27 [ V_25 ] ) , V_9 ) ;
goto V_46;
}
V_45 = F_27 ( V_5 , V_43 , V_25 ) ;
if ( F_24 ( V_45 ) ) {
V_9 = F_25 ( V_45 ) ;
F_10 ( V_5 -> V_5 , L_5 ,
F_26 ( V_27 [ V_25 ] ) , V_9 ) ;
goto V_46;
}
V_23 -> V_27 [ V_23 -> V_26 ++ ] = V_45 ;
}
V_19 = F_28 ( V_5 , 3 , V_47 ) ;
if ( F_24 ( V_19 ) ) {
F_10 ( V_5 -> V_5 , L_6 ) ;
V_9 = F_25 ( V_19 ) ;
goto V_46;
}
V_19 -> V_48 = F_29 ( 0 ) ;
F_30 ( V_23 -> V_27 [ 0 ] , 3 , V_47 ) ;
V_23 -> V_49 [ V_23 -> V_50 ++ ] = V_19 ;
V_3 -> V_51 = F_31 ( V_5 , V_19 ) ;
if ( F_24 ( V_3 -> V_51 ) ) {
V_9 = F_25 ( V_3 -> V_51 ) ;
F_10 ( V_5 -> V_5 , L_7 , V_9 ) ;
goto V_46;
}
return 0 ;
V_46:
return V_9 ;
}
static int F_32 ( struct V_52 * V_53 , struct V_54 * * V_55 ,
const char * V_56 )
{
struct V_57 * V_5 = & V_53 -> V_5 ;
struct V_54 * V_54 = F_33 ( V_5 , V_56 ) ;
if ( F_24 ( V_54 ) ) {
F_10 ( V_5 , L_8 , V_56 , F_25 ( V_54 ) ) ;
return F_25 ( V_54 ) ;
}
* V_55 = V_54 ;
return 0 ;
}
struct V_1 * F_34 ( struct V_4 * V_5 )
{
struct V_52 * V_53 = V_5 -> V_58 ;
struct V_59 * V_60 = F_35 ( V_53 ) ;
struct V_3 * V_3 ;
struct V_1 * V_2 = NULL ;
struct V_28 * V_29 ;
int V_9 ;
V_3 = F_36 ( sizeof( * V_3 ) , V_61 ) ;
if ( ! V_3 ) {
F_10 ( V_5 -> V_5 , L_9 ) ;
V_9 = - V_62 ;
goto V_46;
}
F_37 ( & V_3 -> V_63 , & V_64 ) ;
V_2 = & V_3 -> V_63 . V_63 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_65 = V_60 -> V_65 ;
V_3 -> V_66 = F_38 ( V_53 , L_10 , L_11 ) ;
if ( F_24 ( V_3 -> V_66 ) ) {
V_9 = F_25 ( V_3 -> V_66 ) ;
goto V_46;
}
V_3 -> V_67 = F_38 ( V_53 , L_12 , L_13 ) ;
if ( F_24 ( V_3 -> V_67 ) ) {
V_9 = F_25 ( V_3 -> V_67 ) ;
goto V_46;
}
V_3 -> V_68 = F_39 ( & V_53 -> V_5 , L_14 ) ;
if ( F_24 ( V_3 -> V_68 ) ) {
V_9 = F_25 ( V_3 -> V_68 ) ;
goto V_46;
}
V_9 = F_40 ( V_3 -> V_68 ) ;
if ( V_9 ) {
F_10 ( V_5 -> V_5 , L_15 , V_9 ) ;
goto V_46;
}
V_9 = F_32 ( V_53 , & V_3 -> V_35 , L_16 ) ;
if ( V_9 )
goto V_46;
V_9 = F_32 ( V_53 , & V_3 -> V_34 , L_17 ) ;
if ( V_9 )
goto V_46;
V_9 = F_32 ( V_53 , & V_3 -> V_69 , L_18 ) ;
if ( V_9 )
goto V_46;
V_9 = F_32 ( V_53 , & V_3 -> V_36 , L_19 ) ;
if ( V_9 )
goto V_46;
V_9 = F_32 ( V_53 , & V_3 -> V_37 , L_20 ) ;
if ( V_9 )
goto V_46;
V_9 = F_32 ( V_53 , & V_3 -> V_70 , L_21 ) ;
if ( V_9 )
goto V_46;
V_9 = F_41 ( V_3 -> V_69 , V_60 -> V_71 ) ;
F_5 ( V_3 ) ;
F_11 ( V_3 , F_42 ( 0 ) , 0 ) ;
F_11 ( V_3 , F_42 ( 1 ) , 0 ) ;
F_11 ( V_3 , F_42 ( 2 ) , 0 ) ;
F_11 ( V_3 , F_42 ( 3 ) , 0 ) ;
F_7 ( V_3 ) ;
F_43 ( 16 ) ;
if ( V_60 -> V_72 ) {
V_29 = F_44 ( V_5 , V_60 -> V_72 ) ;
if ( F_24 ( V_29 ) ) {
V_9 = F_25 ( V_29 ) ;
F_10 ( V_5 -> V_5 , L_22 , V_9 ) ;
goto V_46;
}
V_9 = V_29 -> V_30 -> V_73 ( V_29 , V_32 ,
F_18 ( V_32 ) ) ;
if ( V_9 ) {
F_10 ( V_5 -> V_5 , L_23 , V_9 ) ;
V_29 -> V_30 -> V_33 ( V_29 ) ;
goto V_46;
}
} else {
F_45 ( V_5 -> V_5 , L_24
L_25 ) ;
V_29 = NULL ;
}
V_3 -> V_29 = V_29 ;
V_3 -> V_74 = F_46 ( V_5 , V_29 ) ;
if ( V_3 -> V_74 < 0 ) {
V_9 = V_3 -> V_74 ;
F_10 ( V_5 -> V_5 , L_26 , V_9 ) ;
goto V_46;
}
V_9 = F_22 ( V_3 ) ;
if ( V_9 ) {
F_10 ( V_5 -> V_5 , L_27 , V_9 ) ;
goto V_46;
}
return V_2 ;
V_46:
if ( V_2 )
F_17 ( V_2 ) ;
return F_47 ( V_9 ) ;
}
static struct V_59 * F_35 ( struct V_52 * V_5 )
{
static struct V_59 V_60 = {} ;
#ifdef F_48
#endif
return & V_60 ;
}
