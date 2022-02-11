static void F_1 ( int V_1 )
{
F_2 ( V_1 , V_2 ) ;
F_2 ( V_1 , V_3 ) ;
}
static void F_3 ( int V_1 )
{
unsigned long V_4 ;
int V_5 ;
if ( F_4 ( V_1 == F_5 () ) ) {
F_6 ( V_3 ) ;
return;
}
F_7 ( & V_6 , V_4 ) ;
F_8 ( V_7 , V_1 ) ;
V_5 = F_9 ( V_8 ) ;
if ( ! V_5 )
F_8 ( V_9 , V_1 ) ;
F_10 ( & V_6 , V_4 ) ;
}
static void F_11 ( int V_10 )
{
unsigned int V_1 , V_11 ;
unsigned long V_4 ;
if ( F_4 ( V_10 == V_3 ) ) {
F_12 ( V_10 ) ;
return;
}
F_7 ( & V_6 , V_4 ) ;
F_8 ( V_12 , 0 ) ;
V_1 = F_9 ( V_8 ) ;
do {
V_11 = F_13 ( V_1 ) ;
F_8 ( V_13 , V_11 ) ;
V_1 &= ~ ( 1U << V_11 ) ;
} while ( V_1 );
F_10 ( & V_6 , V_4 ) ;
}
static void F_14 ( void )
{
struct V_14 {
#ifdef F_15
unsigned int V_15 : 8 ,
V_16 : 1 , V_17 : 1 , V_18 : 6 ,
V_19 : 1 , V_20 : 1 , V_21 : 1 , V_22 : 1 ,
V_23 : 1 , V_24 : 1 , V_25 : 1 , V_26 : 1 ,
V_27 : 8 ;
#else
unsigned int V_27 : 8 ,
V_26 : 1 , V_25 : 1 , V_24 : 1 , V_23 : 1 ,
V_22 : 1 , V_21 : 1 , V_20 : 1 , V_19 : 1 ,
V_18 : 6 , V_17 : 1 , V_16 : 1 ,
V_15 : 8 ;
#endif
} V_28 ;
F_16 ( V_29 , V_28 ) ;
sprintf ( V_30 ,
L_1 ,
V_28 . V_27 , V_28 . V_18 ,
F_17 ( V_28 . V_25 , L_2 ) ,
F_17 ( V_28 . V_16 , L_3 ) ,
F_17 ( V_28 . V_17 , L_4 ) ,
F_17 ( V_28 . V_21 , L_5 ) ,
F_17 ( V_28 . V_20 , L_6 ) ) ;
V_31 [ 0 ] . V_32 . V_20 = V_28 . V_20 ;
V_33 = V_28 . V_16 ;
if ( V_28 . V_21 ) {
F_18 ( V_34 , 0 , 0xf ) ;
F_18 ( V_35 , 0xf , 0xf ) ;
}
}
static void F_19 ( unsigned int V_36 , unsigned int V_37 )
{
F_18 ( V_38 , V_36 , V_37 ) ;
}
static void F_20 ( unsigned int V_36 , unsigned int V_39 ,
unsigned int V_40 )
{
union {
unsigned int V_41 ;
struct {
unsigned int V_40 : 2 , V_26 : 2 , V_39 : 1 , V_22 : 27 ;
};
} V_42 ;
V_42 . V_40 = V_40 ;
V_42 . V_39 = V_39 ;
F_18 ( V_43 , V_36 , V_42 . V_41 ) ;
}
static void F_21 ( struct V_44 * V_42 )
{
unsigned long V_4 ;
F_7 ( & V_6 , V_4 ) ;
F_18 ( V_45 , V_42 -> V_46 , 1 ) ;
F_10 ( & V_6 , V_4 ) ;
}
static void F_22 ( struct V_44 * V_42 )
{
unsigned long V_4 ;
F_7 ( & V_6 , V_4 ) ;
F_18 ( V_45 , V_42 -> V_46 , 0 ) ;
F_10 ( & V_6 , V_4 ) ;
}
static int
F_23 ( struct V_44 * V_42 , const struct V_47 * V_47 ,
bool V_48 )
{
unsigned long V_4 ;
T_1 V_49 ;
if ( ! F_24 ( & V_49 , V_47 , V_50 ) )
return - V_51 ;
F_7 ( & V_6 , V_4 ) ;
F_19 ( V_42 -> V_46 , F_25 ( & V_49 ) [ 0 ] ) ;
F_20 ( V_42 -> V_46 , V_52 , V_53 ) ;
F_10 ( & V_6 , V_4 ) ;
return V_54 ;
}
static void F_26 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_27 ( V_56 ) ;
unsigned int V_59 = F_28 ( V_56 ) ;
unsigned int V_60 ;
V_60 = V_59 - V_61 ;
F_29 ( F_30 ( V_58 , V_60 ) ) ;
}
static int F_31 ( struct V_57 * V_62 , unsigned int V_63 , T_2 V_46 )
{
F_32 ( V_63 , & V_64 , V_65 ) ;
F_33 ( V_63 , V_66 ) ;
return 0 ;
}
static int F_34 ( struct V_57 * V_62 , struct V_67 * V_68 ,
const T_3 * V_69 , unsigned int V_70 ,
T_2 * V_71 , unsigned int * V_72 )
{
T_2 V_46 = * V_71 = V_69 [ 0 ] ;
int V_73 = V_69 [ 1 ] ;
unsigned long V_4 ;
* V_72 = V_74 ;
if ( V_73 == 0 ) {
F_7 ( & V_6 , V_4 ) ;
F_19 ( V_46 , F_35 ( F_36 () ) - 1 ) ;
F_20 ( V_46 , V_52 , V_53 ) ;
F_10 ( & V_6 , V_4 ) ;
} else {
int V_1 = F_37 ( V_73 ) ;
if ( V_1 != F_38 ( V_73 ) )
F_39 ( L_7 ,
V_46 , V_1 ) ;
F_7 ( & V_6 , V_4 ) ;
F_19 ( V_46 , V_1 ) ;
F_20 ( V_46 , V_52 , V_75 ) ;
F_10 ( & V_6 , V_4 ) ;
}
return 0 ;
}
static int T_4
F_40 ( struct V_67 * V_76 , struct V_67 * V_77 )
{
struct V_57 * V_58 ;
int V_78 = F_41 ( V_76 ) ;
int V_79 , V_10 ;
if ( ! V_33 )
F_42 ( L_8 ) ;
F_43 ( L_9 , V_78 ) ;
V_58 = F_44 ( V_76 , V_78 , & V_80 , NULL ) ;
for ( V_79 = 0 ; V_79 < V_78 ; V_79 ++ ) {
V_10 = F_45 ( V_76 , V_79 ) ;
if ( ! V_79 )
V_61 = V_10 ;
F_46 ( V_10 , F_26 , V_58 ) ;
}
F_8 ( V_81 , 0 ) ;
return 0 ;
}
