static int F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ )
V_2 [ V_1 ] [ 1 ] = F_3 ( V_3 + V_2 [ V_1 ] [ 0 ] ) ;
return 0 ;
}
static void F_4 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ )
F_5 ( V_2 [ V_1 ] [ 1 ] , V_3 + V_2 [ V_1 ] [ 0 ] ) ;
}
static void F_6 ( void )
{
int V_1 ;
for ( V_1 = V_4 ; V_1 < V_5 ; V_1 ++ ) {
if ( ! F_7 ( V_6 [ V_1 ] ) )
F_8 ( V_6 [ V_1 ] ) ;
}
for (; V_1 < V_7 ; V_1 ++ ) {
if ( ! F_7 ( V_6 [ V_1 ] ) )
F_9 ( V_6 [ V_1 ] ) ;
}
for (; V_1 < V_8 . V_9 ; V_1 ++ ) {
if ( ! F_7 ( V_6 [ V_1 ] ) )
F_10 ( V_6 [ V_1 ] ) ;
}
}
static int F_11 ( struct V_10 * V_11 )
{
int V_1 , V_12 = 0 ;
struct V_13 * V_14 ;
const char * V_15 [] = { L_1 , L_2 } ;
const char * V_16 [] = { L_3 , L_4 , L_5 } ;
const char * V_17 = L_6 ;
struct V_18 * V_19 , * V_20 , * V_21 , * V_22 , * V_23 ;
const struct V_24 * V_25 ;
enum V_26 V_27 ;
V_25 = F_12 ( V_28 , V_11 -> V_29 . V_30 ) ;
if ( ! V_25 )
return - V_31 ;
V_27 = (enum V_26 ) V_25 -> V_32 ;
V_14 = F_13 ( V_11 , V_33 , 0 ) ;
V_3 = F_14 ( & V_11 -> V_29 , V_14 ) ;
if ( F_7 ( V_3 ) ) {
F_15 ( & V_11 -> V_29 , L_7 ) ;
return F_16 ( V_3 ) ;
}
V_34 = F_17 ( - V_35 ) ;
V_6 = F_18 ( & V_11 -> V_29 ,
sizeof( struct V_18 * ) * V_36 ,
V_37 ) ;
if ( ! V_6 )
return - V_38 ;
V_8 . V_39 = V_6 ;
if ( V_27 == V_40 )
V_8 . V_9 = V_36 ;
else
V_8 . V_9 = V_36 - 1 ;
V_19 = F_19 ( & V_11 -> V_29 , L_8 ) ;
V_20 = F_19 ( & V_11 -> V_29 , L_9 ) ;
if ( ! F_7 ( V_19 ) )
V_15 [ 0 ] = F_20 ( V_19 ) ;
if ( ! F_7 ( V_20 ) ) {
V_15 [ 1 ] = F_20 ( V_20 ) ;
if ( V_27 == V_40 ) {
V_34 = V_20 ;
V_12 = F_21 ( V_34 ) ;
if ( V_12 ) {
F_15 ( & V_11 -> V_29 ,
L_10 ) ;
return V_12 ;
}
}
}
V_6 [ V_4 ] = F_22 ( NULL , L_3 ,
V_15 , F_2 ( V_15 ) ,
V_41 ,
V_3 + V_42 , 0 , 1 , 0 , & V_43 ) ;
V_21 = F_19 ( & V_11 -> V_29 , L_11 ) ;
V_22 = F_19 ( & V_11 -> V_29 , L_12 ) ;
if ( ! F_7 ( V_21 ) )
V_16 [ 1 ] = F_20 ( V_21 ) ;
if ( ! F_7 ( V_22 ) )
V_16 [ 2 ] = F_20 ( V_22 ) ;
V_6 [ V_44 ] = F_22 ( NULL , L_13 ,
V_16 , F_2 ( V_16 ) ,
V_41 ,
V_3 + V_42 , 2 , 2 , 0 , & V_43 ) ;
V_6 [ V_5 ] = F_23 ( NULL , L_14 ,
L_3 , 0 , V_3 + V_45 , 0 , 4 ,
0 , & V_43 ) ;
V_6 [ V_46 ] = F_23 ( NULL ,
L_15 , L_14 , 0 ,
V_3 + V_45 , 4 , 4 , 0 , & V_43 ) ;
V_6 [ V_47 ] = F_23 ( NULL , L_16 ,
L_13 , 0 , V_3 + V_45 , 8 , 4 , 0 ,
& V_43 ) ;
V_6 [ V_7 ] = F_24 ( NULL , L_17 ,
L_14 , V_48 ,
V_3 + V_49 , 0 , 0 , & V_43 ) ;
V_6 [ V_50 ] = F_24 ( NULL , L_18 ,
L_15 , V_48 ,
V_3 + V_49 , 2 , 0 , & V_43 ) ;
V_6 [ V_51 ] = F_24 ( NULL , L_19 ,
L_16 , V_48 ,
V_3 + V_49 , 3 , 0 , & V_43 ) ;
V_6 [ V_52 ] = F_24 ( NULL , L_20 ,
L_21 , V_48 ,
V_3 + V_49 , 4 , 0 , & V_43 ) ;
V_23 = F_19 ( & V_11 -> V_29 , L_22 ) ;
if ( ! F_7 ( V_23 ) )
V_17 = F_20 ( V_23 ) ;
V_6 [ V_53 ] = F_24 ( NULL , L_21 ,
V_17 , V_48 ,
V_3 + V_49 , 5 , 0 , & V_43 ) ;
if ( V_27 == V_40 ) {
V_6 [ V_54 ] = F_24 ( NULL , L_23 ,
L_14 , V_48 ,
V_3 + V_49 , 9 , 0 , & V_43 ) ;
}
for ( V_1 = 0 ; V_1 < V_8 . V_9 ; V_1 ++ ) {
if ( F_7 ( V_6 [ V_1 ] ) ) {
F_15 ( & V_11 -> V_29 , L_24 , V_1 ) ;
V_12 = F_16 ( V_6 [ V_1 ] ) ;
goto V_55;
}
}
V_12 = F_25 ( V_11 -> V_29 . V_30 , V_56 ,
& V_8 ) ;
if ( V_12 ) {
F_15 ( & V_11 -> V_29 , L_25 ) ;
goto V_55;
}
#ifdef F_26
F_27 ( & V_57 ) ;
#endif
F_28 ( & V_11 -> V_29 , L_26 ) ;
return 0 ;
V_55:
F_6 () ;
if ( ! F_7 ( V_34 ) )
F_29 ( V_34 ) ;
return V_12 ;
}
static int F_30 ( struct V_10 * V_11 )
{
#ifdef F_26
F_31 ( & V_57 ) ;
#endif
F_32 ( V_11 -> V_29 . V_30 ) ;
F_6 () ;
if ( ! F_7 ( V_34 ) )
F_29 ( V_34 ) ;
return 0 ;
}
