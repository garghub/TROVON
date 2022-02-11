void F_1 ( unsigned int V_1 )
{
F_2 ( L_1 , F_3 () , V_2 ,
F_4 () ) ;
F_5 ( F_6 ( V_3 , V_4 ) , 0x80000000 | V_1 ) ;
}
static void T_1 F_7 ( unsigned int V_5 )
{
int V_6 ;
unsigned long V_7 = 5 , V_8 = 5 ;
unsigned int V_9 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
F_5 ( F_6 ( V_10 , V_11 ) , V_6 ) ;
F_8 ( F_6 ( V_12 , V_13 ) , V_9 ) ;
if ( V_9 & V_14 )
F_5 ( F_6 ( V_12 , V_15 ) ,
V_16 | V_7 ) ;
if ( V_9 & V_17 )
F_5 ( F_6 ( V_12 , V_18 ) ,
V_16 | V_8 ) ;
}
}
unsigned int F_9 ( void )
{
unsigned int V_6 ;
unsigned long * V_19 , * V_20 , * V_21 ;
unsigned long * V_22 , * V_23 ;
V_19 = V_24 [ F_3 () ] . V_19 ;
V_20 = V_25 [ F_3 () ] . V_20 ;
V_21 = V_26 [ F_3 () ] . V_21 ;
V_22 = ( unsigned long * ) F_10 ( V_3 ,
V_27 ) ;
V_23 = ( unsigned long * ) F_10 ( V_3 ,
V_28 ) ;
for ( V_6 = 0 ; V_6 < F_11 ( V_29 ) ; V_6 ++ ) {
F_8 ( * V_22 , V_19 [ V_6 ] ) ;
F_8 ( * V_23 , V_20 [ V_6 ] ) ;
V_22 ++ ;
V_23 ++ ;
}
F_12 ( V_19 , V_19 , V_20 , V_29 ) ;
F_12 ( V_19 , V_19 , V_21 , V_29 ) ;
V_6 = F_13 ( V_19 , V_29 ) ;
F_2 ( L_2 , F_3 () , V_2 , V_6 ) ;
return V_6 ;
}
static void F_14 ( struct V_30 * V_31 )
{
unsigned int V_32 = V_31 -> V_32 - V_33 ;
F_2 ( L_3 , F_3 () , V_2 , V_32 ) ;
F_15 ( V_32 ) ;
if ( V_34 [ V_32 ] & V_35 )
F_5 ( F_6 ( V_3 , V_4 ) , V_32 ) ;
}
static void F_16 ( struct V_30 * V_31 )
{
unsigned int V_32 = V_31 -> V_32 - V_33 ;
F_2 ( L_3 , F_3 () , V_2 , V_32 ) ;
F_15 ( V_32 ) ;
}
static void F_17 ( struct V_30 * V_31 )
{
unsigned int V_32 = V_31 -> V_32 - V_33 ;
F_2 ( L_3 , F_3 () , V_2 , V_32 ) ;
F_18 ( V_32 ) ;
}
static int F_19 ( struct V_30 * V_31 , const struct V_36 * V_36 ,
bool V_37 )
{
unsigned int V_32 = V_31 -> V_32 - V_33 ;
T_2 V_38 = V_39 ;
unsigned long V_40 ;
int V_6 ;
F_2 ( L_4 , V_2 , V_32 ) ;
F_20 ( & V_38 , V_36 , V_41 ) ;
if ( F_21 ( V_38 ) )
return - 1 ;
F_22 ( & V_42 , V_40 ) ;
for (; ; ) {
F_23 ( V_32 , F_24 ( V_38 ) ) ;
for ( V_6 = 0 ; V_6 < V_43 ; V_6 ++ )
F_25 ( V_32 , V_26 [ V_6 ] . V_21 ) ;
F_26 ( V_32 , V_26 [ F_24 ( V_38 ) ] . V_21 ) ;
}
F_27 ( V_31 -> V_44 , V_36 ) ;
F_28 ( & V_42 , V_40 ) ;
return V_45 ;
}
static void T_1 F_29 ( unsigned int V_1 , unsigned int V_46 ,
unsigned int V_47 , unsigned int V_48 , unsigned int V_49 ,
unsigned int V_40 )
{
if ( V_47 & V_50 ) {
F_5 ( F_30 ( V_3 , F_31 ( V_1 ) ) , V_47 ) ;
for ( V_46 = 0 ; V_46 < V_43 ; V_46 += 32 ) {
F_5 ( F_30 ( V_3 ,
F_32 ( V_1 , V_46 ) ) ,
0xffffffff ) ;
}
} else {
F_5 ( F_30 ( V_3 , F_31 ( V_1 ) ) ,
V_16 | V_47 ) ;
F_23 ( V_1 , V_46 ) ;
}
F_33 ( V_1 , V_48 ) ;
F_34 ( V_1 , V_49 ) ;
F_15 ( V_1 ) ;
if ( V_40 & V_51 )
F_26 ( V_1 , V_26 [ V_46 ] . V_21 ) ;
if ( V_40 & V_52 )
F_18 ( V_1 ) ;
if ( V_49 == V_53 )
V_34 [ V_1 ] |= V_35 ;
}
static void T_1 F_35 ( int V_54 , int V_5 ,
struct V_55 * V_56 , int V_57 )
{
unsigned int V_6 , V_46 ;
for ( V_6 = 0 ; V_6 < V_54 ; V_6 ++ ) {
F_33 ( V_6 , V_58 ) ;
F_34 ( V_6 , V_59 ) ;
F_15 ( V_6 ) ;
if ( V_6 < V_29 )
V_34 [ V_6 ] = 0 ;
}
for ( V_6 = 0 ; V_6 < V_57 ; V_6 ++ ) {
V_46 = V_56 [ V_6 ] . V_60 ;
if ( V_46 == V_61 )
continue;
if ( V_46 == 0 && V_6 != 0 && V_56 [ V_6 ] . V_40 == 0 )
continue;
F_29 ( V_6 ,
V_56 [ V_6 ] . V_60 ,
V_56 [ V_6 ] . V_47 ,
V_56 [ V_6 ] . V_48 ,
V_56 [ V_6 ] . V_49 ,
V_56 [ V_6 ] . V_40 ) ;
}
F_7 ( V_5 ) ;
for ( V_6 = V_33 ; V_6 < ( V_33 + V_54 ) ; V_6 ++ )
F_36 ( V_6 , & V_62 ) ;
}
void T_1 F_37 ( unsigned long V_63 ,
unsigned long V_64 ,
struct V_55 * V_65 , unsigned int V_66 ,
unsigned int V_67 )
{
unsigned int V_68 ;
int V_5 , V_54 ;
V_69 = ( unsigned long ) F_38 ( V_63 ,
V_64 ) ;
V_33 = V_67 ;
F_8 ( F_6 ( V_3 , V_70 ) , V_68 ) ;
V_54 = ( V_68 & V_71 ) >>
V_72 ;
V_54 = ( ( V_54 + 1 ) * 8 ) ;
V_5 = ( V_68 & V_73 ) >>
V_74 ;
F_2 ( L_5 , V_2 ) ;
F_35 ( V_54 , V_5 , V_65 , V_66 ) ;
}
