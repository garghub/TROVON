static unsigned long F_1 ( unsigned long V_1 )
{
return F_2 ( V_1 * sizeof( V_2 ) , V_3 ) / V_3 ;
}
static unsigned long F_3 ( unsigned long V_4 )
{
unsigned long V_5 = sizeof( struct V_6 ) +
( V_4 * sizeof( struct V_7 * ) ) ;
return V_4 + F_2 ( V_5 , V_3 ) / V_3 ;
}
static long F_4 ( unsigned long V_8 , bool V_9 )
{
long V_10 = 0 ;
if ( ! V_11 || ! V_11 -> V_12 )
return V_10 ;
F_5 ( & V_11 -> V_12 -> V_13 ) ;
if ( V_9 ) {
unsigned long V_14 , V_15 ;
V_14 = V_11 -> V_12 -> V_16 + V_8 ;
V_15 = F_6 ( V_17 ) >> V_18 ;
if ( V_14 > V_15 && ! F_7 ( V_19 ) )
V_10 = - V_20 ;
else
V_11 -> V_12 -> V_16 += V_8 ;
} else {
if ( F_8 ( V_8 > V_11 -> V_12 -> V_16 ) )
V_8 = V_11 -> V_12 -> V_16 ;
V_11 -> V_12 -> V_16 -= V_8 ;
}
F_9 ( L_1 , V_11 -> V_21 ,
V_9 ? '+' : '-' ,
V_8 << V_18 ,
V_11 -> V_12 -> V_16 << V_18 ,
F_6 ( V_17 ) ,
V_10 ? L_2 : L_3 ) ;
F_10 ( & V_11 -> V_12 -> V_13 ) ;
return V_10 ;
}
static void F_11 ( struct V_22 * V_23 )
{
struct V_6 * V_24 = F_12 ( V_23 ,
struct V_6 , V_25 ) ;
unsigned long V_26 , V_27 = F_1 ( V_24 -> V_28 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
F_13 ( V_24 -> V_29 [ V_26 ] ) ;
F_14 ( V_24 ) ;
}
static int F_15 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_6 * V_24 = V_31 -> V_34 -> V_35 ;
struct V_7 * V_7 ;
if ( V_33 -> V_36 >= F_1 ( V_24 -> V_28 ) )
return V_37 ;
V_7 = V_24 -> V_29 [ V_33 -> V_36 ] ;
F_16 ( V_7 ) ;
V_33 -> V_7 = V_7 ;
return 0 ;
}
static int F_17 ( struct V_38 * V_38 , struct V_30 * V_31 )
{
V_31 -> V_39 = & V_40 ;
return 0 ;
}
static int F_18 ( struct V_41 * V_41 , struct V_38 * V_42 )
{
struct V_6 * V_24 = V_42 -> V_35 ;
F_19 ( & V_24 -> V_43 ) ;
F_20 ( V_24 -> V_44 ) ;
F_4 (
F_3 ( F_1 ( V_24 -> V_28 ) ) , false ) ;
F_21 ( & V_24 -> V_25 , F_11 ) ;
return 0 ;
}
long F_22 ( struct V_44 * V_44 ,
struct V_45 * args )
{
struct V_6 * V_24 = NULL ;
unsigned long V_27 , V_28 ;
int V_10 = - V_20 ;
int V_26 ;
if ( ! args -> V_28 )
return - V_46 ;
F_23 (stt, &kvm->arch.spapr_tce_tables, list) {
if ( V_24 -> V_47 == args -> V_47 )
return - V_48 ;
}
V_28 = args -> V_28 ;
V_27 = F_1 ( V_28 ) ;
V_10 = F_4 ( F_3 ( V_27 ) , true ) ;
if ( V_10 ) {
V_24 = NULL ;
goto V_49;
}
V_24 = F_24 ( sizeof( * V_24 ) + V_27 * sizeof( struct V_7 * ) ,
V_50 ) ;
if ( ! V_24 )
goto V_49;
V_24 -> V_47 = args -> V_47 ;
V_24 -> V_51 = args -> V_51 ;
V_24 -> V_52 = args -> V_52 ;
V_24 -> V_28 = V_28 ;
V_24 -> V_44 = V_44 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_24 -> V_29 [ V_26 ] = F_25 ( V_50 | V_53 ) ;
if ( ! V_24 -> V_29 [ V_26 ] )
goto V_49;
}
F_26 ( V_44 ) ;
F_27 ( & V_44 -> V_54 ) ;
F_28 ( & V_24 -> V_43 , & V_44 -> V_55 . V_56 ) ;
F_29 ( & V_44 -> V_54 ) ;
return F_30 ( L_4 , & V_57 ,
V_24 , V_58 | V_59 ) ;
V_49:
if ( V_24 ) {
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
if ( V_24 -> V_29 [ V_26 ] )
F_13 ( V_24 -> V_29 [ V_26 ] ) ;
F_14 ( V_24 ) ;
}
return V_10 ;
}
long F_31 ( struct V_60 * V_61 , unsigned long V_47 ,
unsigned long V_62 , unsigned long V_63 )
{
struct V_6 * V_24 = F_32 ( V_61 , V_47 ) ;
long V_10 ;
if ( ! V_24 )
return V_64 ;
V_10 = F_33 ( V_24 , V_62 , 1 ) ;
if ( V_10 != V_65 )
return V_10 ;
V_10 = F_34 ( V_24 , V_63 ) ;
if ( V_10 != V_65 )
return V_10 ;
F_35 ( V_24 , V_62 >> V_24 -> V_51 , V_63 ) ;
return V_65 ;
}
long F_36 ( struct V_60 * V_61 ,
unsigned long V_47 , unsigned long V_62 ,
unsigned long V_66 , unsigned long V_27 )
{
struct V_6 * V_24 ;
long V_26 , V_10 = V_65 , V_67 ;
unsigned long V_68 , V_69 = 0 ;
V_2 T_1 * V_70 ;
V_2 V_63 ;
V_24 = F_32 ( V_61 , V_47 ) ;
if ( ! V_24 )
return V_64 ;
V_68 = V_62 >> V_24 -> V_51 ;
if ( V_27 > 512 )
return V_71 ;
if ( V_66 & ( V_72 - 1 ) )
return V_71 ;
V_10 = F_33 ( V_24 , V_62 , V_27 ) ;
if ( V_10 != V_65 )
return V_10 ;
V_67 = F_37 ( & V_61 -> V_44 -> V_73 ) ;
if ( F_38 ( V_61 -> V_44 , V_66 , & V_69 , NULL ) ) {
V_10 = V_64 ;
goto V_74;
}
V_70 = ( V_2 T_1 * ) V_69 ;
for ( V_26 = 0 ; V_26 < V_27 ; ++ V_26 ) {
if ( F_39 ( V_63 , V_70 + V_26 ) ) {
V_10 = V_64 ;
goto V_74;
}
V_63 = F_40 ( V_63 ) ;
V_10 = F_34 ( V_24 , V_63 ) ;
if ( V_10 != V_65 )
goto V_74;
F_35 ( V_24 , V_68 + V_26 , V_63 ) ;
}
V_74:
F_41 ( & V_61 -> V_44 -> V_73 , V_67 ) ;
return V_10 ;
}
long F_42 ( struct V_60 * V_61 ,
unsigned long V_47 , unsigned long V_62 ,
unsigned long V_75 , unsigned long V_27 )
{
struct V_6 * V_24 ;
long V_26 , V_10 ;
V_24 = F_32 ( V_61 , V_47 ) ;
if ( ! V_24 )
return V_64 ;
V_10 = F_33 ( V_24 , V_62 , V_27 ) ;
if ( V_10 != V_65 )
return V_10 ;
if ( V_75 & ( V_76 | V_77 ) )
return V_71 ;
for ( V_26 = 0 ; V_26 < V_27 ; ++ V_26 , V_62 += ( 1ULL << V_24 -> V_51 ) )
F_35 ( V_24 , V_62 >> V_24 -> V_51 , V_75 ) ;
return V_65 ;
}
