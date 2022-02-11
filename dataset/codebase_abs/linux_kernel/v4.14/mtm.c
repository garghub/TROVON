int F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
F_2 ( L_1 , V_3 , V_1 ) ;
return 1 ;
}
static void F_3 ( int V_4 )
{
struct V_5 V_6 ;
struct V_7 V_8 ;
int V_9 , V_10 = 0 , V_11 , V_12 ;
for ( V_11 = 0 , V_12 = V_4 ; V_11 < V_13 ; V_11 ++ , V_12 ++ )
V_10 += F_4 ( V_12 , F_5 ( V_14 ) ) ;
V_9 = F_6 ( V_10 ) ;
V_8 . V_15 = F_7 ( V_16 ) ;
V_8 . V_10 = V_9 ;
F_8 ( V_16 , V_8 . V_15 ) ;
V_6 . V_15 = F_9 ( F_10 ( V_4 ) ) ;
V_6 . V_10 = V_9 ;
F_11 ( V_6 . V_15 , F_10 ( V_4 ) ) ;
}
static void F_12 ( int V_4 )
{
int V_11 , V_17 = 5 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
V_19 . V_15 = 0 ;
F_11 ( V_19 . V_15 , F_13 ( V_4 ) ) ;
V_19 . V_22 = F_14 ( V_4 ) ;
V_19 . V_23 = 1 ;
F_11 ( V_19 . V_15 , F_13 ( V_4 ) ) ;
for ( V_11 = 0 ; V_11 < V_17 ; V_11 ++ ) {
V_21 . V_15 = F_9 ( F_15 ( V_4 ) ) ;
if ( V_21 . V_22 == V_19 . V_22 ) {
if ( V_21 . V_24 )
continue;
else if ( V_21 . V_25 )
F_16 ( L_2 , V_4 ) ;
break;
}
F_16 ( L_3 , V_4 ) ;
break;
}
if ( V_11 == V_17 )
F_16 ( L_4 , V_4 ) ;
}
int F_17 ( int V_4 )
{
struct V_5 V_6 ;
if ( F_14 ( V_4 ) == 0 )
return 1 ;
V_6 . V_15 = F_9 ( F_10 ( V_4 ) ) ;
V_6 . V_26 |= ( 1 << ( F_14 ( V_4 ) ) ) ;
F_11 ( V_6 . V_15 , F_10 ( V_4 ) ) ;
return 0 ;
}
void F_18 ( unsigned int V_4 )
{
int V_11 ;
struct V_27 V_28 ;
struct V_5 V_6 ;
struct V_29 V_30 ;
V_30 . V_31 = 1 ;
V_30 . V_32 = 1 ;
F_8 ( V_33 , V_30 . V_15 ) ;
if ( F_14 ( V_4 ) != 0 )
return;
F_3 ( V_4 ) ;
V_6 . V_15 = F_9 ( F_10 ( V_4 ) ) ;
V_6 . V_26 = 1 ;
F_11 ( V_6 . V_15 , F_10 ( V_4 ) ) ;
for ( V_11 = 1 ; V_11 < V_13 ; V_11 ++ )
F_12 ( V_4 + V_11 ) ;
V_28 . V_15 = 0 ;
V_28 . V_34 = 1 ;
V_28 . V_35 = V_36 ;
V_28 . V_37 = 1 ;
F_8 ( V_38 , V_28 . V_15 ) ;
F_19 () ;
}
static int T_1 F_20 ( char * V_39 )
{
long V_40 ;
int V_41 ;
V_41 = F_21 ( V_39 , 0 , & V_40 ) ;
if ( V_41 || V_40 > V_42 || V_40 < V_43 ) {
F_22 ( L_5 ,
V_40 , V_43 , V_42 ) ;
return - V_44 ;
}
V_36 = V_40 ;
return 0 ;
}
