static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = 1 << V_2 -> V_6 ;
F_3 ( V_5 , V_4 -> V_7 + V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = 1 << V_2 -> V_6 ;
F_3 ( V_5 , V_4 -> V_7 + V_9 ) ;
}
static void F_5 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
T_1 V_12 = F_7 ( V_4 -> V_7 + V_13 ) ;
if ( V_12 == 0 ) {
F_8 ( V_11 ) ;
return;
}
do {
unsigned int V_14 = F_9 ( V_12 ) - 1 ;
V_12 &= ~ ( 1 << V_14 ) ;
F_10 ( F_11 ( V_4 -> V_15 , V_14 ) ) ;
} while ( V_12 );
}
static int F_12 ( struct V_3 * V_4 , struct V_16 * V_17 )
{
int V_18 = 0 ;
int V_14 ;
T_1 V_12 ;
while ( ( V_12 = F_7 ( V_4 -> V_7 + V_13 ) ) ) {
V_14 = F_9 ( V_12 ) - 1 ;
F_13 ( V_4 -> V_15 , V_14 , V_17 ) ;
V_18 = 1 ;
}
return V_18 ;
}
T_2 void T_3 F_14 ( struct V_16 * V_17 )
{
int V_19 , V_18 ;
do {
for ( V_19 = 0 , V_18 = 0 ; V_19 < V_20 ; ++ V_19 )
V_18 |= F_12 ( & V_21 [ V_19 ] , V_17 ) ;
} while ( V_18 );
}
static int F_15 ( struct V_22 * V_2 , unsigned int V_14 ,
T_4 V_6 )
{
struct V_3 * V_4 = V_2 -> V_23 ;
if ( ! ( V_4 -> V_24 & F_16 ( V_6 ) ) )
return - V_25 ;
F_17 ( V_14 , V_4 ) ;
F_18 ( V_14 , & V_4 -> V_26 ,
V_27 ) ;
F_19 ( V_14 ) ;
return 0 ;
}
void T_5 F_20 ( void T_6 * V_7 , const char * V_28 , int V_29 ,
int V_30 , T_1 V_24 , struct V_31 * V_32 )
{
struct V_3 * V_4 ;
int V_19 ;
if ( V_20 >= F_21 ( V_21 ) ) {
F_22 ( L_1 , V_33 ) ;
return;
}
V_4 = & V_21 [ V_20 ] ;
V_4 -> V_7 = V_7 ;
V_4 -> V_26 . V_28 = V_28 ;
V_4 -> V_26 . V_34 = F_1 ;
V_4 -> V_26 . V_35 = F_1 ;
V_4 -> V_26 . V_36 = F_4 ;
V_4 -> V_24 = V_24 ;
if ( V_30 != - 1 ) {
F_23 ( V_30 , F_5 ,
V_4 ) ;
}
V_4 -> V_15 = F_24 ( V_32 , F_25 ( V_24 ) , V_29 ,
& V_37 , V_4 ) ;
for ( V_19 = 0 ; V_19 < F_25 ( V_24 ) ; V_19 ++ )
if ( V_24 & F_16 ( V_19 ) ) {
if ( ! V_29 )
F_26 ( V_4 -> V_15 , V_19 ) ;
V_4 -> V_38 ++ ;
}
F_27 ( L_2 ,
V_20 , V_28 , V_7 , V_4 -> V_38 ) ;
if ( V_30 != - 1 )
F_28 ( L_3 , V_30 ) ;
else
F_28 ( L_4 ) ;
V_20 ++ ;
}
int T_5 F_29 ( struct V_31 * V_32 ,
struct V_31 * V_39 )
{
void T_6 * V_7 ;
T_1 V_40 ;
T_1 V_41 ;
int V_30 ;
if ( F_30 ( ! V_32 ) )
return - V_42 ;
V_7 = F_31 ( V_32 , 0 ) ;
F_32 ( ! V_7 , L_5 ) ;
if ( F_33 ( V_32 , L_6 , & V_40 ) )
V_40 = 0 ;
if ( F_33 ( V_32 , L_7 , & V_41 ) )
V_41 = 0 ;
V_30 = F_34 ( V_32 , 0 ) ;
if ( ! V_30 ) {
F_35 ( F_14 ) ;
V_30 = - 1 ;
}
#ifdef F_36
F_20 ( V_7 , V_32 -> V_28 , V_43 , V_30 , V_41 ,
V_32 ) ;
#else
F_20 ( V_7 , V_32 -> V_28 , 0 , V_30 , V_41 , V_32 ) ;
#endif
F_3 ( V_40 , V_7 + V_8 ) ;
F_3 ( V_40 , V_7 + V_44 ) ;
if ( F_37 ( V_32 , L_8 ) )
F_3 ( 0xffd00000 , V_7 + V_45 ) ;
return 0 ;
}
