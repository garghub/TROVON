void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( 1UL << V_3 , V_2 , V_4 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
T_1 V_5 = F_4 ( V_2 , V_6 ) ;
F_2 ( V_5 , V_2 , V_7 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( F_6 ( 0 ) , V_2 , V_8 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
unsigned int V_9 = 2000 ;
T_1 V_5 , V_10 ;
do {
V_5 = F_4 ( V_2 , V_11 ) ;
V_10 = F_8 ( 0 , V_5 ) ;
if ( -- V_9 == 0 ) {
F_9 ( & V_2 -> V_12 -> V_13 , L_1 ,
V_14 ) ;
return - V_15 ;
}
F_10 ( 1 ) ;
} while ( V_10 != 0 );
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_17 [ V_2 -> V_18 ] ;
unsigned int V_19 = F_12 ( V_2 ) ;
F_7 ( V_2 ) ;
F_2 ( V_20 , V_2 , F_13 ( 0 ) ) ;
F_2 ( V_2 -> V_21 , V_2 , F_13 ( 1 ) ) ;
F_2 ( V_2 -> V_18 , V_2 , F_13 ( 2 ) ) ;
F_2 ( V_19 , V_2 , F_13 ( 3 ) ) ;
F_2 ( V_17 -> V_22 [ 0 ] , V_2 , F_13 ( 4 ) ) ;
F_2 ( V_17 -> V_22 [ 1 ] , V_2 , F_13 ( 5 ) ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int T_2 F_14 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_2 ( V_23 , V_2 , F_13 ( 0 ) ) ;
F_2 ( V_2 -> V_21 , V_2 , F_13 ( 1 ) ) ;
F_2 ( V_2 -> V_24 . V_25 , V_2 , F_13 ( 2 ) ) ;
F_5 ( V_2 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_26 )
{
int V_27 ;
if ( V_26 > V_28 )
return - V_29 ;
V_2 -> V_30 . V_26 = V_26 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
if ( V_27 < V_26 )
V_2 -> V_30 . args [ V_27 ] = F_4 ( V_2 ,
F_13 ( 12 + V_27 ) ) ;
else
V_2 -> V_30 . args [ V_27 ] = 0 ;
}
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( L_2 , V_2 -> V_21 ) ;
F_2 ( V_31 , V_2 , F_13 ( 0 ) ) ;
F_2 ( V_2 -> V_21 , V_2 , F_13 ( 1 ) ) ;
F_2 ( V_32 , V_2 , F_13 ( 2 ) ) ;
F_2 ( V_33 , V_2 , F_13 ( 3 ) ) ;
}
void F_18 ( struct V_1 * V_2 , unsigned int V_34 )
{
if ( V_2 -> V_21 != V_34 )
return;
F_7 ( V_2 ) ;
F_2 ( V_35 , V_2 , F_13 ( 0 ) ) ;
F_2 ( V_2 -> V_21 , V_2 , F_13 ( 1 ) ) ;
F_2 ( V_2 -> V_21 , V_2 , F_13 ( 2 ) ) ;
F_5 ( V_2 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_2 ( V_36 , V_2 , F_13 ( 0 ) ) ;
F_2 ( V_2 -> V_21 , V_2 , F_13 ( 1 ) ) ;
F_5 ( V_2 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_2 ( V_37 , V_2 , F_13 ( 0 ) ) ;
F_2 ( V_2 -> V_21 , V_2 , F_13 ( 1 ) ) ;
F_5 ( V_2 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
const T_3 V_38 [] = {
V_39 , V_40 ,
V_41 , V_42 ,
} ;
if ( F_22 ( V_2 -> V_18 >= F_23 ( V_38 ) ) )
return - V_29 ;
F_2 ( V_38 [ V_2 -> V_18 ] , V_2 , F_13 ( 0 ) ) ;
F_2 ( V_2 -> V_21 , V_2 , F_13 ( 1 ) ) ;
F_2 ( V_2 -> V_43 . V_44 , V_2 , F_13 ( 2 ) ) ;
F_5 ( V_2 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_2 ( V_45 , V_2 , F_13 ( 0 ) ) ;
F_2 ( V_2 -> V_21 , V_2 , F_13 ( 1 ) ) ;
F_2 ( 0 , V_2 , F_13 ( 2 ) ) ;
F_5 ( V_2 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_2 ( V_46 , V_2 , F_13 ( 0 ) ) ;
F_2 ( V_2 -> V_21 , V_2 , F_13 ( 1 ) ) ;
F_5 ( V_2 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_2 ( V_47 , V_2 , F_13 ( 0 ) ) ;
F_2 ( V_2 -> V_21 , V_2 , F_13 ( 1 ) ) ;
F_5 ( V_2 ) ;
}
int F_27 ( struct V_1 * V_2 , bool V_48 )
{
int V_49 ;
if ( V_48 )
F_28 ( V_2 ) ;
F_29 () ;
F_30 ( V_50 , & V_2 -> V_51 ) ;
F_11 ( V_2 ) ;
V_49 = F_31 ( V_2 , V_50 , 1 ,
V_52 ) ;
if ( V_49 < 0 )
F_32 ( & V_2 -> V_12 -> V_13 , L_3 , V_14 ) ;
return V_49 ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_49 ;
F_30 ( V_53 , & V_2 -> V_51 ) ;
F_21 ( V_2 ) ;
V_49 = F_31 ( V_2 , V_53 , 1 ,
V_52 ) ;
if ( V_49 < 0 )
F_32 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_14 , V_2 -> V_18 ) ;
return V_49 ;
}
