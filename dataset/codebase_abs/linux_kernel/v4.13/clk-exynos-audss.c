static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
V_4 [ V_3 ] [ 1 ] = F_3 ( V_5 + V_4 [ V_3 ] [ 0 ] ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
F_5 ( V_4 [ V_3 ] [ 1 ] , V_5 + V_4 [ V_3 ] [ 0 ] ) ;
return 0 ;
}
static void F_6 ( void )
{
int V_3 ;
for ( V_3 = V_6 ; V_3 < V_7 ; V_3 ++ ) {
if ( ! F_7 ( V_8 -> V_9 [ V_3 ] ) )
F_8 ( V_8 -> V_9 [ V_3 ] ) ;
}
for (; V_3 < V_10 ; V_3 ++ ) {
if ( ! F_7 ( V_8 -> V_9 [ V_3 ] ) )
F_9 ( V_8 -> V_9 [ V_3 ] ) ;
}
for (; V_3 < V_8 -> V_11 ; V_3 ++ ) {
if ( ! F_7 ( V_8 -> V_9 [ V_3 ] ) )
F_10 ( V_8 -> V_9 [ V_3 ] ) ;
}
}
static int F_11 ( struct V_12 * V_13 )
{
const char * V_14 [] = { L_1 , L_2 } ;
const char * V_15 [] = { L_3 , L_4 , L_5 } ;
const char * V_16 = L_6 ;
struct V_17 * V_18 , * V_19 , * V_20 , * V_21 , * V_22 ;
const struct V_23 * V_24 ;
struct V_25 * * V_26 ;
struct V_27 * V_28 ;
int V_3 , V_29 = 0 ;
V_24 = F_12 ( & V_13 -> V_2 ) ;
if ( ! V_24 )
return - V_30 ;
V_28 = F_13 ( V_13 , V_31 , 0 ) ;
V_5 = F_14 ( & V_13 -> V_2 , V_28 ) ;
if ( F_7 ( V_5 ) ) {
F_15 ( & V_13 -> V_2 , L_7 ) ;
return F_16 ( V_5 ) ;
}
V_32 = F_17 ( - V_33 ) ;
V_8 = F_18 ( & V_13 -> V_2 ,
sizeof( * V_8 ) +
sizeof( * V_8 -> V_9 ) * V_34 ,
V_35 ) ;
if ( ! V_8 )
return - V_36 ;
V_8 -> V_11 = V_24 -> V_37 ;
V_26 = V_8 -> V_9 ;
V_18 = F_19 ( & V_13 -> V_2 , L_8 ) ;
V_19 = F_19 ( & V_13 -> V_2 , L_9 ) ;
if ( ! F_7 ( V_18 ) )
V_14 [ 0 ] = F_20 ( V_18 ) ;
if ( ! F_7 ( V_19 ) ) {
V_14 [ 1 ] = F_20 ( V_19 ) ;
if ( V_24 -> V_38 ) {
V_32 = V_19 ;
V_29 = F_21 ( V_32 ) ;
if ( V_29 ) {
F_15 ( & V_13 -> V_2 ,
L_10 ) ;
return V_29 ;
}
}
}
V_26 [ V_6 ] = F_22 ( NULL , L_3 ,
V_14 , F_2 ( V_14 ) ,
V_39 ,
V_5 + V_40 , 0 , 1 , 0 , & V_41 ) ;
V_20 = F_19 ( & V_13 -> V_2 , L_11 ) ;
V_21 = F_19 ( & V_13 -> V_2 , L_12 ) ;
if ( ! F_7 ( V_20 ) )
V_15 [ 1 ] = F_20 ( V_20 ) ;
if ( ! F_7 ( V_21 ) )
V_15 [ 2 ] = F_20 ( V_21 ) ;
V_26 [ V_42 ] = F_22 ( NULL , L_13 ,
V_15 , F_2 ( V_15 ) ,
V_39 ,
V_5 + V_40 , 2 , 2 , 0 , & V_41 ) ;
V_26 [ V_7 ] = F_23 ( NULL , L_14 ,
L_3 , 0 , V_5 + V_43 , 0 , 4 ,
0 , & V_41 ) ;
V_26 [ V_44 ] = F_23 ( NULL ,
L_15 , L_14 , 0 ,
V_5 + V_43 , 4 , 4 , 0 , & V_41 ) ;
V_26 [ V_45 ] = F_23 ( NULL , L_16 ,
L_13 , 0 , V_5 + V_43 , 8 , 4 , 0 ,
& V_41 ) ;
V_26 [ V_10 ] = F_24 ( NULL , L_17 ,
L_14 , V_46 ,
V_5 + V_47 , 0 , 0 , & V_41 ) ;
V_26 [ V_48 ] = F_24 ( NULL , L_18 ,
L_15 , V_46 ,
V_5 + V_47 , 2 , 0 , & V_41 ) ;
V_26 [ V_49 ] = F_24 ( NULL , L_19 ,
L_16 , V_46 ,
V_5 + V_47 , 3 , 0 , & V_41 ) ;
V_26 [ V_50 ] = F_24 ( NULL , L_20 ,
L_21 , V_46 ,
V_5 + V_47 , 4 , 0 , & V_41 ) ;
V_22 = F_19 ( & V_13 -> V_2 , L_22 ) ;
if ( ! F_7 ( V_22 ) )
V_16 = F_20 ( V_22 ) ;
V_26 [ V_51 ] = F_24 ( NULL , L_21 ,
V_16 , V_46 ,
V_5 + V_47 , 5 , 0 , & V_41 ) ;
if ( V_24 -> V_52 ) {
V_26 [ V_53 ] = F_24 ( NULL , L_23 ,
L_14 , V_46 ,
V_5 + V_47 , 9 , 0 , & V_41 ) ;
}
for ( V_3 = 0 ; V_3 < V_8 -> V_11 ; V_3 ++ ) {
if ( F_7 ( V_26 [ V_3 ] ) ) {
F_15 ( & V_13 -> V_2 , L_24 , V_3 ) ;
V_29 = F_16 ( V_26 [ V_3 ] ) ;
goto V_54;
}
}
V_29 = F_25 ( V_13 -> V_2 . V_55 , V_56 ,
V_8 ) ;
if ( V_29 ) {
F_15 ( & V_13 -> V_2 , L_25 ) ;
goto V_54;
}
return 0 ;
V_54:
F_6 () ;
if ( ! F_7 ( V_32 ) )
F_26 ( V_32 ) ;
return V_29 ;
}
static int F_27 ( struct V_12 * V_13 )
{
F_28 ( V_13 -> V_2 . V_55 ) ;
F_6 () ;
if ( ! F_7 ( V_32 ) )
F_26 ( V_32 ) ;
return 0 ;
}
