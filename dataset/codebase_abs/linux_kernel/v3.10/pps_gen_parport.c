static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 V_5 , V_6 , V_7 , V_8 , V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
long V_14 , V_15 ;
unsigned long V_16 ;
F_2 ( V_16 ) ;
F_3 ( & V_6 ) ;
V_5 = F_4 ( F_5 ( V_3 ) ) ;
V_11 = F_6 ( V_3 , struct V_10 , V_3 ) ;
V_14 = V_17 - V_18 - V_11 -> V_19 ;
if ( V_5 . V_20 != V_6 . V_20 || V_6 . V_21 > V_14 ) {
F_7 ( V_16 ) ;
F_8 ( L_1 ,
V_6 . V_20 , V_6 . V_21 ) ;
goto V_22;
}
do {
F_3 ( & V_7 ) ;
} while ( V_5 . V_20 == V_7 . V_20 && V_7 . V_21 < V_14 );
V_13 = V_11 -> V_23 -> V_13 ;
V_13 -> V_24 -> V_25 ( V_13 , SIGNAL ) ;
V_14 = V_17 - V_11 -> V_19 ;
do {
F_3 ( & V_7 ) ;
} while ( V_5 . V_20 == V_7 . V_20 && V_7 . V_21 < V_14 );
V_13 -> V_24 -> V_25 ( V_13 , V_26 ) ;
F_3 ( & V_8 ) ;
F_7 ( V_16 ) ;
V_9 = F_9 ( V_8 , V_7 ) ;
V_11 -> V_19 =
( V_11 -> V_19 + F_10 ( & V_9 ) ) >> 1 ;
V_22:
V_9 = F_9 ( V_6 , V_5 ) ;
V_15 = F_10 ( & V_9 ) ;
if ( V_15 >= V_27 )
V_27 = V_15 ;
else
V_27 = ( 3 * V_27 + V_15 ) >> 2 ;
F_11 ( V_3 ,
F_12 ( V_5 . V_20 + 1 ,
V_17 - ( V_18 +
V_11 -> V_19 + V_28 +
2 * V_27 ) ) ) ;
return V_29 ;
}
static void F_13 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_23 -> V_13 ;
int V_30 ;
long V_31 = 0 ;
for ( V_30 = 0 ; V_30 < ( 1 << V_32 ) ; V_30 ++ ) {
struct V_4 V_33 , V_34 ;
unsigned long V_35 ;
F_2 ( V_35 ) ;
F_3 ( & V_33 ) ;
V_13 -> V_24 -> V_25 ( V_13 , V_26 ) ;
F_3 ( & V_34 ) ;
F_7 ( V_35 ) ;
V_34 = F_9 ( V_34 , V_33 ) ;
V_31 += F_10 ( & V_34 ) ;
}
V_11 -> V_19 = V_31 >> V_32 ;
F_14 ( L_2 , V_11 -> V_19 ) ;
}
static inline T_1 F_15 ( struct V_10 * V_11 )
{
struct V_4 V_36 ;
F_3 ( & V_36 ) ;
return F_12 ( V_36 . V_20 +
( ( V_36 . V_21 > 990 * V_37 ) ? 1 : 0 ) ,
V_17 - ( V_18 +
V_11 -> V_19 + 3 * V_28 ) ) ;
}
static void F_16 ( struct V_12 * V_13 )
{
if ( V_38 ) {
return;
}
V_39 . V_23 = F_17 ( V_13 , V_40 ,
NULL , NULL , NULL , V_41 , & V_39 ) ;
if ( ! V_39 . V_23 ) {
F_8 ( L_3 , V_13 -> V_42 ) ;
return;
}
if ( F_18 ( V_39 . V_23 ) < 0 ) {
F_8 ( L_4 , V_13 -> V_42 ) ;
goto V_43;
}
F_14 ( L_5 , V_13 -> V_42 ) ;
V_38 = 1 ;
F_13 ( & V_39 ) ;
F_19 ( & V_39 . V_3 , V_44 , V_45 ) ;
V_39 . V_3 . V_46 = F_1 ;
F_20 ( & V_39 . V_3 , F_15 ( & V_39 ) , V_45 ) ;
return;
V_43:
F_21 ( V_39 . V_23 ) ;
}
static void F_22 ( struct V_12 * V_13 )
{
if ( V_13 -> V_47 != V_39 . V_23 )
return;
F_23 ( & V_39 . V_3 ) ;
F_24 ( V_39 . V_23 ) ;
F_21 ( V_39 . V_23 ) ;
}
static int T_2 F_25 ( void )
{
int V_48 ;
F_14 ( V_49 L_6 ) ;
if ( V_18 > V_50 ) {
F_8 ( L_7
L_8 , V_50 ) ;
return - V_51 ;
}
V_48 = F_26 ( & V_52 ) ;
if ( V_48 ) {
F_8 ( L_9 ) ;
return V_48 ;
}
return 0 ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_52 ) ;
F_14 ( L_10 , V_27 ) ;
}
