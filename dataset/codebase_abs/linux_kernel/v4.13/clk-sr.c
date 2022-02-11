static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 ,
& V_5 , NULL , 0 , V_6 ,
F_3 ( V_6 ) ) ;
return 0 ;
}
static void F_4 ( struct V_7 * V_8 )
{
F_2 ( V_8 , & V_9 , NULL , 0 , V_10 ,
F_3 ( V_10 ) ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 ,
& V_11 , NULL , 0 , V_12 ,
F_3 ( V_12 ) ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 ,
& V_13 , NULL , 0 , V_14 ,
F_3 ( V_14 ) ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 ,
& V_15 , NULL , 0 , V_16 ,
F_3 ( V_16 ) ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 ,
& V_17 , NULL , 0 , V_18 ,
F_3 ( V_18 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 ,
& V_19 , NULL , 0 , V_20 ,
F_3 ( V_20 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int (* F_11)( struct V_1 * );
F_11 = F_12 ( & V_2 -> V_3 ) ;
if ( ! F_11 )
return - V_21 ;
return F_11 ( V_2 ) ;
}
