static void F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ ) {
F_2 ( V_2 [ V_1 ] . V_3 ) ;
F_2 ( V_2 [ V_1 ] . V_4 ) ;
}
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_7 * V_9 , * V_10 [ 2 ] ;
int V_1 ;
V_10 [ 0 ] = F_4 ( V_8 , L_1 , 0 ) ;
V_10 [ 1 ] = F_4 ( V_8 , L_1 , 1 ) ;
V_9 = F_4 ( V_8 , L_2 , 0 ) ;
if ( ! ( V_10 [ 0 ] && V_10 [ 1 ] && V_9 ) ) {
F_5 ( & V_6 -> V_11 , L_3 ) ;
F_1 () ;
return - V_12 ;
}
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ ) {
V_2 [ V_1 ] . V_3 = V_10 [ V_1 ] ;
V_2 [ V_1 ] . V_13 = NULL ;
V_2 [ V_1 ] . V_4 = V_9 ;
V_2 [ V_1 ] . V_14 = NULL ;
}
F_6 ( & V_15 , L_4 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_11 . V_16 ;
int V_17 ;
F_8 ( & V_6 -> V_11 , L_5 , V_18 ) ;
V_15 . V_11 = & V_6 -> V_11 ;
if ( V_8 ) {
V_17 = F_3 ( V_6 , V_8 ) ;
if ( V_17 )
return V_17 ;
}
F_8 ( & V_6 -> V_11 , L_6 ,
V_18 , V_15 . V_19 ) ;
F_9 ( V_6 , & V_15 ) ;
F_10 ( & V_15 , NULL ) ;
F_8 ( & V_6 -> V_11 , L_7 ,
V_18 , V_15 . V_19 , V_15 . V_20 ) ;
F_8 ( & V_6 -> V_11 , L_8 ,
V_18 , V_15 . V_19 , V_15 . V_21 [ 0 ] . V_19 ) ;
F_8 ( & V_6 -> V_11 , L_9 ,
V_18 , V_15 . V_19 ,
V_15 . V_21 [ 0 ] . V_22 ) ;
V_17 = F_11 ( & V_15 ) ;
if ( V_17 )
F_5 ( & V_6 -> V_11 ,
L_10 , V_17 ) ;
return V_17 ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_23 * V_15 = F_13 ( V_6 ) ;
F_14 ( L_5 , V_18 ) ;
F_15 ( V_15 ) ;
F_16 ( V_15 ) ;
F_1 () ;
return 0 ;
}
