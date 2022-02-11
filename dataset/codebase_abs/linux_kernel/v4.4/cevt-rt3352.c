static int F_1 ( unsigned long V_1 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
V_5 = F_2 ( V_3 , struct V_4 , V_7 ) ;
V_6 = F_3 ( V_5 -> V_8 + V_9 ) ;
V_6 = ( V_6 + V_1 ) % V_10 ;
F_4 ( V_6 , V_5 -> V_8 + V_11 ) ;
return 0 ;
}
static void F_5 ( struct V_2 * V_7 )
{
}
static T_2 F_6 ( int V_12 , void * V_13 )
{
struct V_2 * V_7 = (struct V_2 * ) V_13 ;
V_7 -> V_14 ( V_7 ) ;
return V_15 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 , struct V_4 , V_7 ) ;
if ( V_5 -> V_16 )
F_8 ( V_17 . V_7 . V_12 , & V_18 ) ;
V_5 -> V_16 = 0 ;
F_4 ( 0 , V_17 . V_8 + V_19 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 , struct V_4 , V_7 ) ;
if ( ! V_5 -> V_16 )
F_10 ( V_17 . V_7 . V_12 , & V_18 ) ;
V_5 -> V_16 = 1 ;
F_4 ( V_20 | V_21 ,
V_17 . V_8 + V_19 ) ;
return 0 ;
}
static void T_3 F_11 ( struct V_22 * V_23 )
{
V_17 . V_8 = F_12 ( V_23 , 0 ) ;
if ( ! V_17 . V_8 )
return;
V_18 . V_24 = V_23 -> V_24 ;
V_17 . V_7 . V_24 = V_23 -> V_24 ;
F_13 ( & V_17 . V_7 , V_10 , 60 ) ;
V_17 . V_7 . V_25 = F_14 ( 0x7fff , & V_17 . V_7 ) ;
V_17 . V_7 . V_26 = F_14 ( 0x3 , & V_17 . V_7 ) ;
V_17 . V_7 . V_12 = F_15 ( V_23 , 0 ) ;
if ( ! V_17 . V_7 . V_12 ) {
F_16 ( L_1 , V_23 -> V_24 ) ;
return;
}
F_17 ( V_17 . V_8 + V_9 , V_23 -> V_24 ,
V_10 , 301 , 16 , V_27 ) ;
F_18 ( & V_17 . V_7 ) ;
F_19 ( L_2 ,
V_23 -> V_24 , V_17 . V_7 . V_28 , V_17 . V_7 . V_29 ) ;
}
