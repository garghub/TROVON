static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
const int V_3 = ( ( V_4 * ) V_2 -> V_5 . V_6 -> V_7 -> V_8 )
- ( ( V_4 * ) NULL ) ;
return F_2 ( V_3 , V_2 ) ;
}
static int F_3 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_4 ( V_2 -> V_9 ) ;
}
static unsigned int F_5 ( struct V_2 * V_2 , T_1 * V_10 )
{
return F_6 ( V_2 , V_10 ) ;
}
static T_2 F_7 ( struct V_2 * V_2 , char T_3 * V_11 , T_4 V_12 ,
T_5 * V_13 )
{
return F_8 ( V_2 -> V_9 , V_11 , V_12 ) ;
}
static T_2 F_9 ( struct V_2 * V_2 , const char T_3 * V_11 ,
T_4 V_12 , T_5 * V_13 )
{
return F_10 ( V_2 -> V_9 , V_11 , V_12 ) ;
}
static void T_6 F_11 ( const char * V_14 , const T_7 V_15 ,
struct V_6 * V_16 , const V_4 V_3 )
{
F_12 ( V_14 , V_15 , V_16 , ( ( V_4 * ) NULL ) + V_3 ,
& V_17 ) ;
}
static int T_6 F_13 ( void )
{
struct V_6 * V_18 ;
if ( F_14 () -> V_19 != & V_20 )
return 0 ;
V_18 = F_15 ( L_1 , NULL ) ;
F_11 ( L_2 , 0600 , V_18 ,
V_21 ) ;
F_11 ( L_3 , 0600 , V_18 ,
V_22 ) ;
F_11 ( L_4 , 0600 , V_18 ,
V_23 ) ;
F_11 ( L_5 , 0400 , V_18 ,
V_24 ) ;
F_11 ( L_6 , 0400 , V_18 ,
V_25 ) ;
F_11 ( L_7 , 0600 , V_18 ,
V_26 ) ;
F_11 ( L_8 , 0644 , V_18 ,
V_27 ) ;
F_11 ( L_9 , 0600 , V_18 ,
V_28 ) ;
F_11 ( L_10 , 0600 , V_18 ,
V_29 ) ;
F_11 ( L_11 , 0400 , V_18 ,
V_30 ) ;
return 0 ;
}
