static void F_1 ( struct V_1 * V_2 , long V_3 )
{
if ( F_2 ( V_3 >= 1000000 ) ) {
F_3 ( V_2 , L_1 , V_3 / 1000000 ) ;
V_3 %= 1000000 ;
F_3 ( V_2 , L_2 , V_3 / 1000 , V_3 % 1000 ) ;
} else if ( F_4 ( V_3 >= 1000 ) )
F_3 ( V_2 , L_3 , V_3 / 1000 , V_3 % 1000 ) ;
else
F_3 ( V_2 , L_4 , V_3 ) ;
}
static void F_5 ( struct V_4 * V_5 ,
union V_6 V_7 , unsigned long * V_8 ,
unsigned long * V_9 , unsigned int * V_10 )
{
F_6 (unsigned long, device->rs_total) ;
* V_8 = V_5 -> V_8 ;
if ( V_7 . V_11 == V_12 || V_7 . V_11 == V_13 )
* V_9 = V_5 -> V_14 ;
else
* V_9 = F_7 ( V_5 ) - V_5 -> V_15 ;
if ( * V_9 > * V_8 ) {
* V_9 = * V_8 ;
* V_10 = * V_8 ? 0 : 1000 ;
} else {
unsigned int V_16 = * V_8 > V_17 ? 16 : 10 ;
unsigned long V_18 = * V_9 >> V_16 ;
unsigned long V_19 = 1UL + ( * V_8 >> V_16 ) ;
unsigned long V_20 = 1000UL - V_18 * 1000UL / V_19 ;
* V_10 = V_20 ;
}
}
static void F_8 ( struct V_4 * V_5 , struct V_1 * V_2 ,
union V_6 V_7 )
{
unsigned long V_21 , V_22 , V_23 , V_24 , V_8 , V_25 ;
unsigned int V_26 ;
int V_27 , V_28 , V_29 ;
int V_30 = 0 ;
F_5 ( V_5 , V_7 , & V_8 , & V_25 , & V_26 ) ;
V_28 = V_26 / 50 ;
V_29 = 20 - V_28 ;
F_9 ( V_2 , L_5 ) ;
for ( V_27 = 1 ; V_27 < V_28 ; V_27 ++ )
F_10 ( V_2 , '=' ) ;
F_10 ( V_2 , '>' ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ )
F_3 ( V_2 , L_6 ) ;
F_9 ( V_2 , L_7 ) ;
if ( V_7 . V_11 == V_12 || V_7 . V_11 == V_13 )
F_9 ( V_2 , L_8 ) ;
else
F_9 ( V_2 , L_9 ) ;
F_3 ( V_2 , L_10 , V_26 / 10 , V_26 % 10 ) ;
if ( V_8 > ( 4UL << ( 30 - V_31 ) ) )
F_3 ( V_2 , L_11 ,
( unsigned long ) F_11 ( V_25 >> 10 ) ,
( unsigned long ) F_11 ( V_8 >> 10 ) ) ;
else
F_3 ( V_2 , L_12 ,
( unsigned long ) F_11 ( V_25 ) ,
( unsigned long ) F_11 ( V_8 ) ) ;
F_9 ( V_2 , L_13 ) ;
V_27 = ( V_5 -> V_32 + 2 ) % V_33 ;
V_22 = ( V_34 - V_5 -> V_35 [ V_27 ] ) / V_36 ;
if ( V_22 > 180 )
V_30 = 1 ;
if ( ! V_22 )
V_22 ++ ;
V_21 = V_5 -> V_37 [ V_27 ] - V_25 ;
V_24 = ( V_22 * ( V_25 / ( V_21 / 100 + 1 ) ) ) / 100 ;
F_3 ( V_2 , L_14 ,
V_24 / 3600 , ( V_24 % 3600 ) / 60 , V_24 % 60 ) ;
V_23 = F_11 ( V_21 / V_22 ) ;
F_9 ( V_2 , L_15 ) ;
F_1 ( V_2 , V_23 ) ;
F_9 ( V_2 , L_16 ) ;
if ( V_38 >= 1 ) {
V_27 = ( V_5 -> V_32 + V_33 - 1 ) % V_33 ;
V_22 = ( V_34 - V_5 -> V_35 [ V_27 ] ) / V_36 ;
if ( ! V_22 )
V_22 ++ ;
V_21 = V_5 -> V_37 [ V_27 ] - V_25 ;
V_23 = F_11 ( V_21 / V_22 ) ;
F_1 ( V_2 , V_23 ) ;
F_9 ( V_2 , L_17 ) ;
}
V_22 = ( V_34 - V_5 -> V_39 - V_5 -> V_40 ) / V_36 ;
if ( V_22 == 0 )
V_22 = 1 ;
V_21 = V_8 - V_25 ;
V_23 = F_11 ( V_21 / V_22 ) ;
F_1 ( V_2 , V_23 ) ;
F_10 ( V_2 , ')' ) ;
if ( V_7 . V_11 == V_41 ||
V_7 . V_11 == V_12 ) {
F_9 ( V_2 , L_18 ) ;
F_1 ( V_2 , V_5 -> V_42 ) ;
}
F_3 ( V_2 , L_19 , V_30 ? L_20 : L_21 ) ;
if ( V_38 >= 1 ) {
unsigned long V_43 = F_12 ( V_5 ) ;
unsigned long V_44 ;
unsigned long long V_45 = 0 ;
if ( V_7 . V_11 == V_12 ||
V_7 . V_11 == V_13 ) {
V_44 = V_43 - V_5 -> V_14 ;
if ( F_13 ( V_5 ) )
V_45 = V_5 -> V_46 ;
} else
V_44 = V_5 -> V_47 ;
F_3 ( V_2 ,
L_22 ,
( int ) ( V_44 / ( V_43 / 100 + 1 ) ) ,
( unsigned long long ) V_44 * V_48 ,
( unsigned long long ) V_43 * V_48 ) ;
if ( V_45 != 0 && V_45 != V_49 )
F_3 ( V_2 , L_23 , V_45 ) ;
F_10 ( V_2 , '\n' ) ;
}
}
static int F_14 ( struct V_1 * V_2 , void * V_3 )
{
int V_27 , V_50 = - 1 ;
const char * V_51 ;
struct V_4 * V_5 ;
struct V_52 * V_53 ;
union V_6 V_7 ;
char V_54 ;
static char V_55 [] = {
[ V_56 ] = 'n' ,
[ V_57 ] = 'd' ,
[ V_58 ] = 'f' ,
} ;
F_3 ( V_2 , L_24 V_59 L_25 ,
V_60 , V_61 , V_62 , F_15 () ) ;
F_16 () ;
F_17 (&drbd_devices, device, i) {
if ( V_50 != V_27 - 1 )
F_10 ( V_2 , '\n' ) ;
V_50 = V_27 ;
V_7 = V_5 -> V_7 ;
V_51 = F_18 ( V_7 . V_11 ) ;
if ( V_7 . V_11 == V_63 &&
V_7 . V_64 == V_65 &&
V_7 . V_66 == V_67 ) {
F_3 ( V_2 , L_26 , V_27 ) ;
} else {
F_19 ( & V_5 -> V_68 -> V_69 ) ;
V_53 = F_20 ( F_21 ( V_5 ) -> V_70 -> V_52 ) ;
V_54 = V_53 ? V_53 -> V_71 - V_72 + 'A' : ' ' ;
F_3 ( V_2 ,
L_27
L_28
L_29 ,
V_27 , V_51 ,
F_22 ( V_7 . V_66 ) ,
F_22 ( V_7 . V_73 ) ,
F_23 ( V_7 . V_64 ) ,
F_23 ( V_7 . V_74 ) ,
V_54 ,
F_24 ( V_5 ) ? 's' : 'r' ,
V_7 . V_75 ? 'a' : '-' ,
V_7 . V_76 ? 'p' : '-' ,
V_7 . V_77 ? 'u' : '-' ,
V_5 -> V_78 ? : '-' ,
F_25 ( V_79 , & V_5 -> V_80 ) ? 's' : '-' ,
V_5 -> V_81 / 2 ,
V_5 -> V_82 / 2 ,
V_5 -> V_83 / 2 ,
V_5 -> V_84 / 2 ,
V_5 -> V_85 ,
V_5 -> V_86 ,
F_26 ( & V_5 -> V_87 ) ,
F_26 ( & V_5 -> V_88 ) +
F_26 ( & V_5 -> V_89 ) ,
F_26 ( & V_5 -> V_90 ) ,
F_26 ( & V_5 -> V_91 ) ,
F_21 ( V_5 ) -> V_70 -> V_92 ,
V_55 [ V_5 -> V_93 -> V_94 ]
) ;
F_3 ( V_2 , L_30 ,
F_11 ( ( unsigned long long )
F_7 ( V_5 ) ) ) ;
}
if ( V_7 . V_11 == V_95 ||
V_7 . V_11 == V_41 ||
V_7 . V_11 == V_12 ||
V_7 . V_11 == V_13 )
F_8 ( V_5 , V_2 , V_7 ) ;
if ( V_38 >= 1 && F_27 ( V_5 , V_96 ) ) {
F_28 ( V_2 , V_5 -> V_97 ) ;
F_28 ( V_2 , V_5 -> V_98 ) ;
F_29 ( V_5 ) ;
}
if ( V_38 >= 2 )
F_3 ( V_2 , L_31 , F_26 ( & V_5 -> V_99 ) ) ;
}
F_30 () ;
return 0 ;
}
static int F_31 ( struct V_100 * V_100 , struct V_101 * V_101 )
{
int V_102 ;
if ( F_32 ( V_103 ) ) {
V_102 = F_33 ( V_101 , F_14 , NULL ) ;
if ( V_102 )
F_34 ( V_103 ) ;
return V_102 ;
}
return - V_104 ;
}
static int F_35 ( struct V_100 * V_100 , struct V_101 * V_101 )
{
F_34 ( V_103 ) ;
return F_36 ( V_100 , V_101 ) ;
}
