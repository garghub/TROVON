static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_6 * V_7 = & V_6 [ V_5 -> V_8 ] ;
F_4 ( V_7 ) ;
F_5 ( V_5 ) ;
}
static int F_6 ( struct V_6 * V_7 )
{
struct V_1 * V_9 ;
int V_10 ;
V_9 = F_7 ( sizeof( * V_9 ) , V_11 ) ;
if ( ! V_9 ) {
V_10 = - V_12 ;
goto V_13;
}
V_9 -> V_3 . V_14 = V_7 -> V_5 -> V_3 . V_14 ;
V_9 -> V_3 . V_15 = F_3 ;
V_9 -> V_8 = V_7 -> V_16 ;
V_9 -> V_3 . V_17 = & V_18 ;
F_8 ( & V_9 -> V_3 , L_1 , V_9 -> V_8 ) ;
F_9 ( & V_9 -> V_3 ) ;
F_10 ( & V_9 -> V_3 ) ;
F_11 ( V_7 -> V_9 , V_9 ) ;
F_12 ( & V_19 . V_20 ) ;
V_19 . V_21 ++ ;
V_19 . V_22 = F_13 ( V_23 , V_9 -> V_8 , V_19 . V_22 ) ;
F_14 ( & V_19 . V_20 ) ;
return 0 ;
V_13:
F_15 ( & V_7 -> V_5 -> V_3 ,
L_2 , V_7 -> V_16 , V_10 ) ;
return V_10 ;
}
static int F_16 ( struct V_6 * V_7 )
{
struct V_1 * V_9 = F_17 ( V_7 -> V_9 ) ;
char V_24 [ 16 ] ;
int V_10 ;
V_10 = F_18 ( & V_9 -> V_3 ) ;
F_19 ( & V_9 -> V_3 ) ;
if ( V_10 ) {
F_15 ( & V_7 -> V_5 -> V_3 ,
L_3 , V_7 -> V_16 ) ;
goto V_25;
}
F_20 ( V_24 , sizeof( V_24 ) , L_4 , V_9 -> V_8 ) ;
V_7 -> V_26 = F_21 ( V_24 , & V_7 -> V_5 -> V_3 ,
sizeof( struct V_27 ) , 1 ,
0 ) ;
if ( ! V_7 -> V_26 ) {
F_15 ( & V_7 -> V_5 -> V_3 ,
L_5 , V_7 -> V_16 ) ;
V_10 = - V_12 ;
goto V_28;
}
F_22 ( & V_9 -> V_3 , L_6 , V_9 -> V_8 ) ;
return 0 ;
V_28:
F_23 ( & V_9 -> V_3 ) ;
V_25:
F_24 ( V_7 -> V_9 , NULL ) ;
F_25 () ;
F_19 ( & V_9 -> V_3 ) ;
F_12 ( & V_19 . V_20 ) ;
V_19 . V_21 -- ;
F_14 ( & V_19 . V_20 ) ;
return V_10 ;
}
void F_26 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = F_2 ( V_30 , struct V_6 ,
V_31 ) ;
F_16 ( V_7 ) ;
}
void F_27 ( struct V_6 * V_7 )
{
int V_10 ;
F_12 ( & V_7 -> V_32 ) ;
V_10 = F_6 ( V_7 ) ;
if ( V_10 )
goto exit;
F_28 ( & V_7 -> V_31 ) ;
exit:
F_14 ( & V_7 -> V_32 ) ;
}
int F_29 ( struct V_6 * V_7 )
{
struct V_1 * V_9 ;
F_12 ( & V_7 -> V_32 ) ;
F_30 ( & V_7 -> V_31 ) ;
V_9 = F_17 ( V_7 -> V_9 ) ;
if ( ! V_9 ) {
F_14 ( & V_7 -> V_32 ) ;
return - V_33 ;
}
F_24 ( V_7 -> V_9 , NULL ) ;
F_25 () ;
F_14 ( & V_7 -> V_32 ) ;
F_22 ( & V_9 -> V_3 , L_7 , V_9 -> V_8 ) ;
F_31 ( & V_9 -> V_3 ) ;
F_12 ( & V_19 . V_20 ) ;
V_19 . V_21 -- ;
F_14 ( & V_19 . V_20 ) ;
return 0 ;
}
int F_32 ( void )
{
return F_33 ( & V_18 ) ;
}
void F_34 ( void )
{
F_35 ( & V_18 ) ;
}
