static void F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ ) {
if ( V_2 [ V_1 ] . V_3 )
F_2 ( (struct V_4 * )
V_2 [ V_1 ] . V_3 ) ;
if ( V_2 [ V_1 ] . V_5 )
F_2 ( (struct V_4 * )
V_2 [ V_1 ] . V_5 ) ;
}
}
static int F_3 ( struct V_6 * V_7 ,
struct V_4 * V_8 )
{
struct V_4 * V_9 , * V_10 [ 2 ] ;
int V_1 ;
V_10 [ 0 ] = F_4 ( V_8 , L_1 , 0 ) ;
V_10 [ 1 ] = F_4 ( V_8 , L_1 , 1 ) ;
V_9 = F_4 ( V_8 , L_2 , 0 ) ;
if ( ! ( V_10 [ 0 ] && V_10 [ 1 ] && V_9 ) ) {
F_5 ( & V_7 -> V_11 , L_3 ) ;
F_1 () ;
return - V_12 ;
}
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ ) {
V_2 [ V_1 ] . V_3 = V_10 [ V_1 ] ;
V_2 [ V_1 ] . V_13 = NULL ;
V_2 [ V_1 ] . V_14 = V_10 [ V_1 ] ;
V_2 [ V_1 ] . V_15 = NULL ;
V_2 [ V_1 ] . V_5 = V_9 ;
V_2 [ V_1 ] . V_16 = NULL ;
}
F_6 ( & V_17 , L_4 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_4 * V_8 = V_7 -> V_11 . V_18 ;
int V_19 ;
F_8 ( & V_7 -> V_11 , L_5 , V_20 ) ;
V_17 . V_11 = & V_7 -> V_11 ;
if ( V_8 ) {
V_19 = F_3 ( V_7 , V_8 ) ;
if ( V_19 )
return V_19 ;
}
F_8 ( & V_7 -> V_11 , L_6 ,
V_20 , V_17 . V_21 ) ;
F_9 ( V_7 , & V_17 ) ;
F_10 ( & V_17 , NULL ) ;
F_8 ( & V_7 -> V_11 , L_7 ,
V_20 , V_17 . V_21 , V_17 . V_22 ) ;
F_8 ( & V_7 -> V_11 , L_8 ,
V_20 , V_17 . V_21 , V_17 . V_23 [ 0 ] . V_21 ) ;
F_8 ( & V_7 -> V_11 , L_9 ,
V_20 , V_17 . V_21 ,
V_17 . V_23 [ 0 ] . V_24 ) ;
V_19 = F_11 ( & V_17 ) ;
if ( V_19 )
F_5 ( & V_7 -> V_11 ,
L_10 , V_19 ) ;
return V_19 ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_25 * V_17 = F_13 ( V_7 ) ;
F_14 ( L_5 , V_20 ) ;
F_15 ( V_17 ) ;
F_16 ( V_17 ) ;
F_1 () ;
return 0 ;
}
