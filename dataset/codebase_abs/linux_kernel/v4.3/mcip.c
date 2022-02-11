void F_1 ( unsigned int V_1 )
{
F_2 ( V_1 , V_2 ) ;
}
static void F_3 ( int V_1 )
{
unsigned long V_3 ;
int V_4 ;
do {
F_4 ( & V_5 , V_3 ) ;
F_5 ( V_6 , V_1 ) ;
V_4 = F_6 ( V_7 ) ;
if ( V_4 == 0 )
break;
F_7 ( & V_5 , V_3 ) ;
} while ( 1 );
F_5 ( V_8 , V_1 ) ;
F_7 ( & V_5 , V_3 ) ;
#ifdef F_8
if ( V_4 )
F_9 ( L_1 , V_1 ) ;
#endif
}
static void F_10 ( int V_9 )
{
unsigned int V_1 , V_10 ;
unsigned long V_3 ;
unsigned int T_1 V_11 ;
F_4 ( & V_5 , V_3 ) ;
F_5 ( V_12 , 0 ) ;
V_11 = V_1 = F_6 ( V_7 ) ;
do {
V_10 = F_11 ( V_1 ) ;
F_5 ( V_13 , V_10 ) ;
V_1 &= ~ ( 1U << V_10 ) ;
} while ( V_1 );
F_7 ( & V_5 , V_3 ) ;
#ifdef F_8
if ( V_10 != F_11 ( V_11 ) )
F_9 ( L_2 ,
V_11 , F_12 () ) ;
#endif
}
static void F_13 ( int V_1 , unsigned long V_14 )
{
F_14 ( V_1 == 0 ) ;
V_15 = V_1 ;
}
void F_15 ( int V_1 )
{
while ( V_15 != V_1 )
;
V_15 = 0 ;
__asm__ __volatile__("j @first_lines_of_secondary \n");
}
void F_16 ( void )
{
#define F_17 ( T_2 , T_3 ) ((var) ? str : "")
struct V_16 {
#ifdef F_18
unsigned int V_17 : 8 ,
V_18 : 1 , V_19 : 1 , V_20 : 6 ,
V_21 : 1 , V_22 : 1 , V_23 : 1 , V_24 : 1 ,
V_25 : 1 , V_26 : 1 , V_27 : 1 , V_28 : 1 ,
V_29 : 8 ;
#else
unsigned int V_29 : 8 ,
V_28 : 1 , V_27 : 1 , V_26 : 1 , V_25 : 1 ,
V_24 : 1 , V_23 : 1 , V_22 : 1 , V_21 : 1 ,
V_20 : 6 , V_19 : 1 , V_18 : 1 ,
V_17 : 8 ;
#endif
} V_30 ;
F_19 ( V_31 , V_30 ) ;
sprintf ( V_32 ,
L_3 ,
V_30 . V_29 , V_30 . V_20 ,
F_17 ( V_30 . V_27 , L_4 ) ,
F_17 ( V_30 . V_18 , L_5 ) ,
F_17 ( V_30 . V_23 , L_6 ) ,
F_17 ( V_30 . V_22 , L_7 ) ) ;
V_33 = V_30 . V_18 ;
if ( V_30 . V_23 ) {
F_20 ( V_34 , 0 , 0xf ) ;
F_20 ( V_35 , 0xf , 0xf ) ;
}
if ( F_21 ( V_36 ) && ! V_30 . V_22 )
F_22 ( L_8 ) ;
}
static void F_23 ( unsigned int V_37 , unsigned int V_38 )
{
F_20 ( V_39 , V_37 , V_38 ) ;
}
static void F_24 ( unsigned int V_37 , unsigned int V_40 ,
unsigned int V_41 )
{
union {
unsigned int V_42 ;
struct {
unsigned int V_41 : 2 , V_28 : 2 , V_40 : 1 , V_24 : 27 ;
};
} V_43 ;
V_43 . V_41 = V_41 ;
V_43 . V_40 = V_40 ;
F_20 ( V_44 , V_37 , V_43 . V_42 ) ;
}
static void F_25 ( struct V_45 * V_43 )
{
unsigned long V_3 ;
F_4 ( & V_5 , V_3 ) ;
F_20 ( V_46 , V_43 -> V_47 , 1 ) ;
F_7 ( & V_5 , V_3 ) ;
}
static void F_26 ( struct V_45 * V_43 )
{
unsigned long V_3 ;
F_4 ( & V_5 , V_3 ) ;
F_20 ( V_46 , V_43 -> V_47 , 0 ) ;
F_7 ( & V_5 , V_3 ) ;
}
static int
F_27 ( struct V_45 * V_43 , const struct V_48 * V_48 ,
bool V_49 )
{
unsigned long V_3 ;
T_4 V_50 ;
if ( ! F_28 ( & V_50 , V_48 , V_51 ) )
return - V_52 ;
F_4 ( & V_5 , V_3 ) ;
F_23 ( V_43 -> V_47 , F_29 ( & V_50 ) [ 0 ] ) ;
F_24 ( V_43 -> V_47 , V_53 , V_54 ) ;
F_7 ( & V_5 , V_3 ) ;
return V_55 ;
}
static void F_30 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_31 ( V_57 ) ;
unsigned int V_60 = F_32 ( V_57 ) ;
unsigned int V_61 ;
V_61 = V_60 - V_62 ;
F_33 ( F_34 ( V_59 , V_61 ) ) ;
}
static int F_35 ( struct V_58 * V_63 , unsigned int V_64 , T_5 V_47 )
{
F_36 ( V_64 , & V_65 , V_66 ) ;
F_37 ( V_64 , V_67 ) ;
return 0 ;
}
static int F_38 ( struct V_58 * V_63 , struct V_68 * V_69 ,
const T_6 * V_70 , unsigned int V_71 ,
T_5 * V_72 , unsigned int * V_73 )
{
T_5 V_47 = * V_72 = V_70 [ 0 ] ;
int V_74 = V_70 [ 1 ] ;
unsigned long V_3 ;
* V_73 = V_75 ;
if ( V_74 == 0 ) {
F_4 ( & V_5 , V_3 ) ;
F_23 ( V_47 , F_39 ( F_40 () ) - 1 ) ;
F_24 ( V_47 , V_53 , V_54 ) ;
F_7 ( & V_5 , V_3 ) ;
} else {
int V_1 = F_41 ( V_74 ) ;
if ( V_1 != F_42 ( V_74 ) )
F_43 ( L_9 ,
V_47 , V_1 ) ;
F_4 ( & V_5 , V_3 ) ;
F_23 ( V_47 , V_1 ) ;
F_24 ( V_47 , V_53 , V_76 ) ;
F_7 ( & V_5 , V_3 ) ;
}
return 0 ;
}
static int T_7
F_44 ( struct V_68 * V_77 , struct V_68 * V_78 )
{
struct V_58 * V_59 ;
int V_79 = F_45 ( V_77 ) ;
int V_80 , V_9 ;
if ( ! V_33 )
F_22 ( L_10 ) ;
F_9 ( L_11 , V_79 ) ;
V_59 = F_46 ( V_77 , V_79 , & V_81 , NULL ) ;
for ( V_80 = 0 ; V_80 < V_79 ; V_80 ++ ) {
V_9 = F_47 ( V_77 , V_80 ) ;
if ( ! V_80 )
V_62 = V_9 ;
F_48 ( V_9 , F_30 , V_59 ) ;
}
F_5 ( V_82 , 0 ) ;
return 0 ;
}
