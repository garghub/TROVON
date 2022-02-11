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
F_16 ( V_15 . V_23 , L_5 ) ) ;
V_24 [ 0 ] . V_25 . V_23 = V_15 . V_23 ;
if ( V_15 . V_22 ) {
F_17 ( V_26 , 0 , 0xf ) ;
F_17 ( V_27 , 0xf , 0xf ) ;
}
}
static void F_18 ( unsigned int V_28 , unsigned int V_29 )
{
F_17 ( V_30 , V_28 , V_29 ) ;
}
static void F_19 ( unsigned int V_28 , unsigned int V_31 ,
unsigned int V_32 )
{
union {
unsigned int V_33 ;
struct {
unsigned int V_32 : 2 , V_34 : 2 , V_31 : 1 , V_35 : 27 ;
};
} V_36 ;
V_36 . V_32 = V_32 ;
V_36 . V_31 = V_31 ;
F_17 ( V_37 , V_28 , V_36 . V_33 ) ;
}
static void F_20 ( struct V_38 * V_36 )
{
unsigned long V_4 ;
F_7 ( & V_6 , V_4 ) ;
F_17 ( V_39 , V_36 -> V_40 , 1 ) ;
F_10 ( & V_6 , V_4 ) ;
}
static void F_21 ( struct V_38 * V_36 )
{
unsigned long V_4 ;
F_7 ( & V_6 , V_4 ) ;
F_17 ( V_39 , V_36 -> V_40 , 0 ) ;
F_10 ( & V_6 , V_4 ) ;
}
static int
F_22 ( struct V_38 * V_36 , const struct V_41 * V_41 ,
bool V_42 )
{
unsigned long V_4 ;
T_1 V_43 ;
unsigned int V_44 ;
unsigned int V_45 ;
if ( ! F_23 ( & V_43 , V_41 , V_46 ) )
return - V_47 ;
F_7 ( & V_6 , V_4 ) ;
V_44 = F_24 ( & V_43 ) [ 0 ] ;
F_18 ( V_36 -> V_40 , V_44 ) ;
if ( F_25 ( V_44 ) == F_26 ( V_44 ) )
V_45 = V_48 ;
else
V_45 = V_49 ;
F_19 ( V_36 -> V_40 , V_50 , V_45 ) ;
F_10 ( & V_6 , V_4 ) ;
return V_51 ;
}
static void F_27 ( struct V_38 * V_36 )
{
F_22 ( V_36 , V_46 , false ) ;
F_21 ( V_36 ) ;
}
static void F_28 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_29 ( V_53 ) ;
struct V_56 * V_57 = F_30 ( V_53 ) ;
T_2 V_58 = F_31 ( F_32 ( V_53 ) ) ;
T_2 V_59 = V_58 - V_60 ;
F_33 ( V_57 , V_53 ) ;
F_34 ( F_35 ( V_55 , V_59 ) ) ;
F_36 ( V_57 , V_53 ) ;
}
static int F_37 ( struct V_54 * V_61 , unsigned int V_62 , T_2 V_40 )
{
F_38 ( V_62 , & V_63 , V_64 ) ;
F_39 ( V_62 , V_65 ) ;
return 0 ;
}
static int F_40 ( struct V_54 * V_61 , struct V_66 * V_67 ,
const T_3 * V_68 , unsigned int V_69 ,
T_2 * V_70 , unsigned int * V_71 )
{
* V_70 = V_68 [ 0 ] ;
* V_71 = V_72 ;
return 0 ;
}
static int T_4
F_41 ( struct V_66 * V_73 , struct V_66 * V_74 )
{
struct V_54 * V_75 ;
int V_76 = F_42 ( V_73 ) ;
int V_77 , V_62 ;
struct V_14 V_15 ;
F_15 ( V_16 , V_15 ) ;
if ( ! V_15 . V_21 )
F_43 ( L_6 ) ;
F_44 ( L_7 , V_76 ) ;
V_75 = F_45 ( V_73 , V_76 , & V_78 , NULL ) ;
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ ) {
V_62 = F_46 ( V_73 , V_77 ) ;
if ( ! V_77 )
V_60 = F_31 ( F_47 ( V_62 ) ) ;
F_48 ( V_62 , F_28 , V_75 ) ;
}
F_8 ( V_79 , 0 ) ;
return 0 ;
}
