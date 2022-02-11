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
struct V_14 V_15 ;
F_15 ( V_16 , V_15 ) ;
sprintf ( V_17 ,
L_1 ,
V_15 . V_18 , V_15 . V_19 ,
F_16 ( V_15 . V_20 , L_2 ) ,
F_16 ( V_15 . V_21 , L_3 ) ,
F_16 ( V_15 . V_22 , L_4 ) ,
F_16 ( V_15 . V_23 , L_5 ) ,
F_16 ( V_15 . V_24 , L_6 ) ) ;
V_25 [ 0 ] . V_26 . V_24 = V_15 . V_24 ;
if ( V_15 . V_23 ) {
F_17 ( V_27 , 0 , 0xf ) ;
F_17 ( V_28 , 0xf , 0xf ) ;
}
}
static void F_18 ( unsigned int V_29 , unsigned int V_30 )
{
F_17 ( V_31 , V_29 , V_30 ) ;
}
static void F_19 ( unsigned int V_29 , unsigned int V_32 ,
unsigned int V_33 )
{
union {
unsigned int V_34 ;
struct {
unsigned int V_33 : 2 , V_35 : 2 , V_32 : 1 , V_36 : 27 ;
};
} V_37 ;
V_37 . V_33 = V_33 ;
V_37 . V_32 = V_32 ;
F_17 ( V_38 , V_29 , V_37 . V_34 ) ;
}
static void F_20 ( struct V_39 * V_37 )
{
unsigned long V_4 ;
F_7 ( & V_6 , V_4 ) ;
F_17 ( V_40 , V_37 -> V_41 , 1 ) ;
F_10 ( & V_6 , V_4 ) ;
}
static void F_21 ( struct V_39 * V_37 )
{
unsigned long V_4 ;
F_7 ( & V_6 , V_4 ) ;
F_17 ( V_40 , V_37 -> V_41 , 0 ) ;
F_10 ( & V_6 , V_4 ) ;
}
static int
F_22 ( struct V_39 * V_37 , const struct V_42 * V_42 ,
bool V_43 )
{
unsigned long V_4 ;
T_1 V_44 ;
unsigned int V_45 ;
unsigned int V_46 ;
if ( ! F_23 ( & V_44 , V_42 , V_47 ) )
return - V_48 ;
F_7 ( & V_6 , V_4 ) ;
V_45 = F_24 ( & V_44 ) [ 0 ] ;
F_18 ( V_37 -> V_41 , V_45 ) ;
if ( F_25 ( V_45 ) == F_26 ( V_45 ) )
V_46 = V_49 ;
else
V_46 = V_50 ;
F_19 ( V_37 -> V_41 , V_51 , V_46 ) ;
F_10 ( & V_6 , V_4 ) ;
return V_52 ;
}
static void F_27 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_28 ( V_54 ) ;
T_2 V_57 = F_29 ( F_30 ( V_54 ) ) ;
T_2 V_58 = V_57 - V_59 ;
F_31 ( F_32 ( V_56 , V_58 ) ) ;
}
static int F_33 ( struct V_55 * V_60 , unsigned int V_61 , T_2 V_41 )
{
F_34 ( V_61 , & V_62 , V_63 ) ;
F_35 ( V_61 , V_64 ) ;
return 0 ;
}
static int F_36 ( struct V_55 * V_60 , struct V_65 * V_66 ,
const T_3 * V_67 , unsigned int V_68 ,
T_2 * V_69 , unsigned int * V_70 )
{
T_2 V_41 = * V_69 = V_67 [ 0 ] ;
int V_71 = V_67 [ 1 ] ;
unsigned long V_4 ;
* V_70 = V_72 ;
if ( V_71 == 0 ) {
F_7 ( & V_6 , V_4 ) ;
F_18 ( V_41 , F_37 ( F_38 () ) - 1 ) ;
F_19 ( V_41 , V_51 , V_50 ) ;
F_10 ( & V_6 , V_4 ) ;
} else {
int V_1 = F_25 ( V_71 ) ;
if ( V_1 != F_26 ( V_71 ) )
F_39 ( L_7 ,
V_41 , V_1 ) ;
F_7 ( & V_6 , V_4 ) ;
F_18 ( V_41 , V_1 ) ;
F_19 ( V_41 , V_51 , V_49 ) ;
F_10 ( & V_6 , V_4 ) ;
}
return 0 ;
}
static int T_4
F_40 ( struct V_65 * V_73 , struct V_65 * V_74 )
{
struct V_55 * V_75 ;
int V_76 = F_41 ( V_73 ) ;
int V_77 , V_61 ;
struct V_14 V_15 ;
F_15 ( V_16 , V_15 ) ;
if ( ! V_15 . V_21 )
F_42 ( L_8 ) ;
F_43 ( L_9 , V_76 ) ;
V_75 = F_44 ( V_73 , V_76 , & V_78 , NULL ) ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_61 = F_45 ( V_73 , V_77 ) ;
if ( ! V_77 )
V_59 = F_29 ( F_46 ( V_61 ) ) ;
F_47 ( V_61 , F_27 , V_75 ) ;
}
F_8 ( V_79 , 0 ) ;
return 0 ;
}
