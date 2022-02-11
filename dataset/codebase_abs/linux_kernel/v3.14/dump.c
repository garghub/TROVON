void F_1 ( struct V_1 * V_2 , T_1 * V_3 , unsigned long V_4 )
{
T_2 * V_5 = F_2 ( V_3 , 0 ) ;
unsigned long V_6 ;
unsigned V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ , V_5 ++ ) {
V_6 = V_4 + V_7 * V_9 ;
F_3 ( V_2 , V_6 , 4 , F_4 ( * V_5 ) ) ;
}
}
static void F_5 ( struct V_1 * V_2 , T_3 * V_10 , unsigned long V_4 )
{
T_1 * V_3 = F_6 ( V_10 , 0 ) ;
unsigned long V_6 ;
unsigned V_7 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ , V_3 ++ ) {
V_6 = V_4 + V_7 * V_12 ;
if ( F_7 ( * V_3 ) || F_8 ( * V_3 ) || ! F_9 ( * V_3 ) )
F_3 ( V_2 , V_6 , 3 , F_10 ( * V_3 ) ) ;
else
F_1 ( V_2 , V_3 , V_6 ) ;
if ( V_13 < V_12 && F_8 ( V_3 [ 1 ] ) )
F_3 ( V_2 , V_6 + V_13 , 3 , F_10 ( V_3 [ 1 ] ) ) ;
}
}
static void F_11 ( struct V_1 * V_2 , T_4 * V_14 , unsigned long V_4 )
{
T_3 * V_10 = F_12 ( V_14 , 0 ) ;
unsigned long V_6 ;
unsigned V_7 ;
for ( V_7 = 0 ; V_7 < V_15 ; V_7 ++ , V_10 ++ ) {
V_6 = V_4 + V_7 * V_16 ;
if ( ! F_13 ( * V_10 ) ) {
F_5 ( V_2 , V_10 , V_6 ) ;
} else {
F_3 ( V_2 , V_6 , 2 , F_14 ( * V_10 ) ) ;
}
}
}
static void F_15 ( struct V_17 * V_18 )
{
T_4 * V_14 = V_19 ;
struct V_1 V_2 ;
unsigned long V_6 ;
unsigned V_7 , V_20 = V_21 / V_22 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_23 = V_18 ;
V_2 . V_24 = V_25 ;
V_14 += V_20 ;
for ( V_7 = V_20 ; V_7 < V_26 ; V_7 ++ , V_14 ++ ) {
V_6 = V_7 * V_22 ;
if ( ! F_16 ( * V_14 ) ) {
F_11 ( & V_2 , V_14 , V_6 ) ;
} else {
F_3 ( & V_2 , V_6 , 1 , F_17 ( * V_14 ) ) ;
}
}
F_3 ( & V_2 , 0 , 0 , 0 ) ;
}
static int F_18 ( struct V_17 * V_18 , void * V_27 )
{
F_15 ( V_18 ) ;
return 0 ;
}
static int F_19 ( struct V_28 * V_28 , struct V_29 * V_29 )
{
return F_20 ( V_29 , F_18 , NULL ) ;
}
static int F_21 ( void )
{
struct V_30 * V_31 ;
unsigned V_7 , V_32 ;
for ( V_7 = 0 ; V_7 < F_22 ( V_33 ) ; V_7 ++ )
if ( V_33 [ V_7 ] . V_34 )
for ( V_32 = 0 ; V_32 < V_33 [ V_7 ] . V_35 ; V_32 ++ )
V_33 [ V_7 ] . V_36 |= V_33 [ V_7 ] . V_34 [ V_32 ] . V_36 ;
V_25 [ 2 ] . V_37 = V_38 ;
V_31 = F_23 ( L_1 , 0400 , NULL , NULL ,
& V_39 ) ;
return V_31 ? 0 : - V_40 ;
}
