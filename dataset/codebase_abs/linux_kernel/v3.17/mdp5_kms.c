static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
T_1 V_6 , V_7 , V_8 ;
int V_9 , V_10 = 0 ;
F_4 ( V_3 ) ;
V_6 = F_5 ( V_3 , V_11 ) ;
F_6 ( V_3 ) ;
V_7 = F_7 ( V_6 , V_12 ) ;
V_8 = F_7 ( V_6 , V_13 ) ;
F_8 ( L_1 , V_7 , V_8 ) ;
if ( V_7 != 1 ) {
F_9 ( V_5 -> V_5 , L_2 ,
V_7 , V_8 ) ;
V_10 = - V_14 ;
goto V_15;
}
V_3 -> V_16 = V_8 ;
for ( V_9 = 0 ; V_9 < F_10 ( V_17 ) ; V_9 ++ ) {
if ( V_17 [ V_9 ] . V_18 != V_8 )
continue;
V_3 -> V_19 = V_20 = V_17 [ V_9 ] . V_21 ;
break;
}
if ( F_11 ( ! V_3 -> V_19 ) ) {
F_9 ( V_5 -> V_5 , L_3 ,
V_7 , V_8 ) ;
V_10 = - V_14 ;
goto V_15;
}
F_8 ( L_4 , V_3 -> V_19 -> V_22 ) ;
return 0 ;
V_15:
return V_10 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
int V_9 ;
F_13 ( V_5 -> V_5 ) ;
F_14 ( V_3 , V_23 , 0 ) ;
for ( V_9 = 0 ; V_9 < V_3 -> V_19 -> V_24 . V_25 ; V_9 ++ )
F_14 ( V_3 , F_15 ( V_9 ) , 0 ) ;
F_16 ( V_5 -> V_5 ) ;
return 0 ;
}
static long F_17 ( struct V_1 * V_2 , unsigned long V_26 ,
struct V_27 * V_28 )
{
return V_26 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_31 * V_32 = V_3 -> V_5 -> V_33 ;
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < V_32 -> V_34 ; V_9 ++ )
F_19 ( V_32 -> V_35 [ V_9 ] , V_30 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_36 * V_37 = V_3 -> V_37 ;
if ( V_37 ) {
V_37 -> V_38 -> V_39 ( V_37 , V_40 , F_10 ( V_40 ) ) ;
V_37 -> V_38 -> V_41 ( V_37 ) ;
}
F_21 ( V_3 ) ;
}
int F_6 ( struct V_3 * V_3 )
{
F_8 ( L_5 ) ;
F_22 ( V_3 -> V_42 ) ;
F_22 ( V_3 -> V_43 ) ;
F_22 ( V_3 -> V_44 ) ;
F_22 ( V_3 -> V_45 ) ;
return 0 ;
}
int F_4 ( struct V_3 * V_3 )
{
F_8 ( L_5 ) ;
F_23 ( V_3 -> V_42 ) ;
F_23 ( V_3 -> V_43 ) ;
F_23 ( V_3 -> V_44 ) ;
F_23 ( V_3 -> V_45 ) ;
return 0 ;
}
static int F_24 ( struct V_3 * V_3 )
{
static const enum V_46 V_35 [] = {
V_47 , V_48 , V_49 , V_50 ,
} ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_31 * V_32 = V_5 -> V_33 ;
struct V_27 * V_28 ;
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < V_3 -> V_19 -> V_51 . V_25 ; V_9 ++ ) {
struct V_52 * V_53 ;
struct V_54 * V_55 ;
V_53 = F_25 ( V_5 , V_35 [ V_9 ] , true ) ;
if ( F_26 ( V_53 ) ) {
V_10 = F_27 ( V_53 ) ;
F_9 ( V_5 -> V_5 , L_6 ,
F_28 ( V_35 [ V_9 ] ) , V_10 ) ;
goto V_56;
}
V_55 = F_29 ( V_5 , V_53 , V_9 ) ;
if ( F_26 ( V_55 ) ) {
V_10 = F_27 ( V_55 ) ;
F_9 ( V_5 -> V_5 , L_7 ,
F_28 ( V_35 [ V_9 ] ) , V_10 ) ;
goto V_56;
}
V_32 -> V_35 [ V_32 -> V_34 ++ ] = V_55 ;
}
V_28 = F_30 ( V_5 , 3 , V_57 ) ;
if ( F_26 ( V_28 ) ) {
F_9 ( V_5 -> V_5 , L_8 ) ;
V_10 = F_27 ( V_28 ) ;
goto V_56;
}
V_28 -> V_58 = F_31 ( 0 ) ;
F_32 ( V_32 -> V_35 [ 0 ] , 3 , V_57 ) ;
V_32 -> V_59 [ V_32 -> V_60 ++ ] = V_28 ;
V_3 -> V_61 = F_33 ( V_5 , V_28 ) ;
if ( F_26 ( V_3 -> V_61 ) ) {
V_10 = F_27 ( V_3 -> V_61 ) ;
F_9 ( V_5 -> V_5 , L_9 , V_10 ) ;
goto V_56;
}
return 0 ;
V_56:
return V_10 ;
}
static int F_34 ( struct V_62 * V_63 , struct V_64 * * V_65 ,
const char * V_22 )
{
struct V_66 * V_5 = & V_63 -> V_5 ;
struct V_64 * V_64 = F_35 ( V_5 , V_22 ) ;
if ( F_26 ( V_64 ) ) {
F_9 ( V_5 , L_10 , V_22 , F_27 ( V_64 ) ) ;
return F_27 ( V_64 ) ;
}
* V_65 = V_64 ;
return 0 ;
}
struct V_1 * F_36 ( struct V_4 * V_5 )
{
struct V_62 * V_63 = V_5 -> V_67 ;
struct V_68 * V_21 = F_37 ( V_63 ) ;
struct V_3 * V_3 ;
struct V_1 * V_2 = NULL ;
struct V_36 * V_37 ;
int V_9 , V_10 ;
V_3 = F_38 ( sizeof( * V_3 ) , V_69 ) ;
if ( ! V_3 ) {
F_9 ( V_5 -> V_5 , L_11 ) ;
V_10 = - V_70 ;
goto V_56;
}
F_39 ( & V_3 -> V_71 , & V_72 ) ;
V_2 = & V_3 -> V_71 . V_71 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_73 = V_21 -> V_73 ;
V_3 -> V_74 = F_40 ( V_63 , L_12 , L_13 ) ;
if ( F_26 ( V_3 -> V_74 ) ) {
V_10 = F_27 ( V_3 -> V_74 ) ;
goto V_56;
}
V_3 -> V_75 = F_40 ( V_63 , L_14 , L_15 ) ;
if ( F_26 ( V_3 -> V_75 ) ) {
V_10 = F_27 ( V_3 -> V_75 ) ;
goto V_56;
}
V_3 -> V_76 = F_41 ( & V_63 -> V_5 , L_16 ) ;
if ( F_26 ( V_3 -> V_76 ) ) {
V_10 = F_27 ( V_3 -> V_76 ) ;
goto V_56;
}
V_10 = F_42 ( V_3 -> V_76 ) ;
if ( V_10 ) {
F_9 ( V_5 -> V_5 , L_17 , V_10 ) ;
goto V_56;
}
V_10 = F_34 ( V_63 , & V_3 -> V_43 , L_18 ) ;
if ( V_10 )
goto V_56;
V_10 = F_34 ( V_63 , & V_3 -> V_42 , L_19 ) ;
if ( V_10 )
goto V_56;
V_10 = F_34 ( V_63 , & V_3 -> V_77 , L_20 ) ;
if ( V_10 )
goto V_56;
V_10 = F_34 ( V_63 , & V_3 -> V_44 , L_21 ) ;
if ( V_10 )
goto V_56;
V_10 = F_34 ( V_63 , & V_3 -> V_45 , L_22 ) ;
if ( V_10 )
goto V_56;
V_10 = F_34 ( V_63 , & V_3 -> V_78 , L_23 ) ;
if ( V_10 )
goto V_56;
V_10 = F_43 ( V_3 -> V_77 , V_21 -> V_79 ) ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 )
goto V_56;
F_4 ( V_3 ) ;
for ( V_9 = 0 ; V_9 < V_3 -> V_19 -> V_80 . V_25 ; V_9 ++ )
F_14 ( V_3 , F_44 ( V_9 ) , 0 ) ;
F_6 ( V_3 ) ;
F_45 ( 16 ) ;
if ( V_21 -> V_81 ) {
V_37 = F_46 ( & V_63 -> V_5 , V_21 -> V_81 ) ;
if ( F_26 ( V_37 ) ) {
V_10 = F_27 ( V_37 ) ;
F_9 ( V_5 -> V_5 , L_24 , V_10 ) ;
goto V_56;
}
V_10 = V_37 -> V_38 -> V_82 ( V_37 , V_40 ,
F_10 ( V_40 ) ) ;
if ( V_10 ) {
F_9 ( V_5 -> V_5 , L_25 , V_10 ) ;
V_37 -> V_38 -> V_41 ( V_37 ) ;
goto V_56;
}
} else {
F_47 ( V_5 -> V_5 , L_26
L_27 ) ;
V_37 = NULL ;
}
V_3 -> V_37 = V_37 ;
V_3 -> V_83 = F_48 ( V_5 , V_37 ) ;
if ( V_3 -> V_83 < 0 ) {
V_10 = V_3 -> V_83 ;
F_9 ( V_5 -> V_5 , L_28 , V_10 ) ;
goto V_56;
}
V_10 = F_24 ( V_3 ) ;
if ( V_10 ) {
F_9 ( V_5 -> V_5 , L_29 , V_10 ) ;
goto V_56;
}
return V_2 ;
V_56:
if ( V_2 )
F_20 ( V_2 ) ;
return F_49 ( V_10 ) ;
}
static struct V_68 * F_37 ( struct V_62 * V_5 )
{
static struct V_68 V_21 = {} ;
#ifdef F_50
#endif
V_21 . V_81 = F_51 ( & V_84 ) ;
V_21 . V_79 = 200000000 ;
V_21 . V_73 = 22 ;
return & V_21 ;
}
