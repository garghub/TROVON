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
V_31 = V_28 . V_16 ;
if ( V_28 . V_21 ) {
F_18 ( V_32 , 0 , 0xf ) ;
F_18 ( V_33 , 0xf , 0xf ) ;
}
if ( F_19 ( V_34 ) && ! V_28 . V_20 )
F_20 ( L_7 ) ;
}
static void F_21 ( unsigned int V_35 , unsigned int V_36 )
{
F_18 ( V_37 , V_35 , V_36 ) ;
}
static void F_22 ( unsigned int V_35 , unsigned int V_38 ,
unsigned int V_39 )
{
union {
unsigned int V_40 ;
struct {
unsigned int V_39 : 2 , V_26 : 2 , V_38 : 1 , V_22 : 27 ;
};
} V_41 ;
V_41 . V_39 = V_39 ;
V_41 . V_38 = V_38 ;
F_18 ( V_42 , V_35 , V_41 . V_40 ) ;
}
static void F_23 ( struct V_43 * V_41 )
{
unsigned long V_4 ;
F_7 ( & V_6 , V_4 ) ;
F_18 ( V_44 , V_41 -> V_45 , 1 ) ;
F_10 ( & V_6 , V_4 ) ;
}
static void F_24 ( struct V_43 * V_41 )
{
unsigned long V_4 ;
F_7 ( & V_6 , V_4 ) ;
F_18 ( V_44 , V_41 -> V_45 , 0 ) ;
F_10 ( & V_6 , V_4 ) ;
}
static int
F_25 ( struct V_43 * V_41 , const struct V_46 * V_46 ,
bool V_47 )
{
unsigned long V_4 ;
T_1 V_48 ;
if ( ! F_26 ( & V_48 , V_46 , V_49 ) )
return - V_50 ;
F_7 ( & V_6 , V_4 ) ;
F_21 ( V_41 -> V_45 , F_27 ( & V_48 ) [ 0 ] ) ;
F_22 ( V_41 -> V_45 , V_51 , V_52 ) ;
F_10 ( & V_6 , V_4 ) ;
return V_53 ;
}
static void F_28 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_29 ( V_55 ) ;
unsigned int V_58 = F_30 ( V_55 ) ;
unsigned int V_59 ;
V_59 = V_58 - V_60 ;
F_31 ( F_32 ( V_57 , V_59 ) ) ;
}
static int F_33 ( struct V_56 * V_61 , unsigned int V_62 , T_2 V_45 )
{
F_34 ( V_62 , & V_63 , V_64 ) ;
F_35 ( V_62 , V_65 ) ;
return 0 ;
}
static int F_36 ( struct V_56 * V_61 , struct V_66 * V_67 ,
const T_3 * V_68 , unsigned int V_69 ,
T_2 * V_70 , unsigned int * V_71 )
{
T_2 V_45 = * V_70 = V_68 [ 0 ] ;
int V_72 = V_68 [ 1 ] ;
unsigned long V_4 ;
* V_71 = V_73 ;
if ( V_72 == 0 ) {
F_7 ( & V_6 , V_4 ) ;
F_21 ( V_45 , F_37 ( F_38 () ) - 1 ) ;
F_22 ( V_45 , V_51 , V_52 ) ;
F_10 ( & V_6 , V_4 ) ;
} else {
int V_1 = F_39 ( V_72 ) ;
if ( V_1 != F_40 ( V_72 ) )
F_41 ( L_8 ,
V_45 , V_1 ) ;
F_7 ( & V_6 , V_4 ) ;
F_21 ( V_45 , V_1 ) ;
F_22 ( V_45 , V_51 , V_74 ) ;
F_10 ( & V_6 , V_4 ) ;
}
return 0 ;
}
static int T_4
F_42 ( struct V_66 * V_75 , struct V_66 * V_76 )
{
struct V_56 * V_57 ;
int V_77 = F_43 ( V_75 ) ;
int V_78 , V_10 ;
if ( ! V_31 )
F_20 ( L_9 ) ;
F_44 ( L_10 , V_77 ) ;
V_57 = F_45 ( V_75 , V_77 , & V_79 , NULL ) ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
V_10 = F_46 ( V_75 , V_78 ) ;
if ( ! V_78 )
V_60 = V_10 ;
F_47 ( V_10 , F_28 , V_57 ) ;
}
F_8 ( V_80 , 0 ) ;
return 0 ;
}
