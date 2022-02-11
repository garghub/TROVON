static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_4 ) {
F_2 ( V_2 -> V_4 ) ;
V_4 = F_3 ( V_2 -> V_4 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
} else {
V_4 = F_4 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return;
V_2 -> V_4 = & V_4 -> V_6 ;
}
V_4 -> V_6 . V_2 = V_2 ;
V_4 -> V_7 . V_8 = V_9 ;
}
static struct V_10 * F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = F_3 ( V_2 -> V_4 ) ;
struct V_3 * V_4 ;
V_4 = F_4 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
F_6 ( V_2 , & V_4 -> V_6 ) ;
F_7 ( V_4 -> V_6 . V_2 != V_2 ) ;
V_4 -> V_7 = V_11 -> V_7 ;
return & V_4 -> V_6 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_10 * V_4 )
{
F_2 ( V_4 ) ;
F_9 ( F_3 ( V_4 ) ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_10 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_14 * V_15 ;
struct V_16 V_17 = { 0 , } ;
if ( ! V_13 )
return 0 ;
if ( ! F_11 ( V_13 ) ) {
F_12 ( L_1 ) ;
return - V_18 ;
}
if ( ! V_4 -> V_19 )
return 0 ;
V_15 = F_13 ( V_4 -> V_4 , V_4 -> V_19 ) ;
if ( F_14 ( V_15 ) )
return F_15 ( V_15 ) ;
V_17 . V_20 = V_15 -> V_21 . V_22 ;
V_17 . V_23 = V_15 -> V_21 . V_24 ;
return F_16 ( V_4 , & V_17 ,
V_25 ,
V_25 ,
true , true ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_3 ( V_2 -> V_4 ) ;
struct V_26 * V_19 = V_2 -> V_4 -> V_19 ;
struct V_12 * V_13 = V_2 -> V_4 -> V_13 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
unsigned int V_31 , V_8 ;
T_1 V_32 ;
if ( ! V_19 || F_7 ( ! V_13 ) )
return;
V_28 = F_11 ( V_13 ) ;
V_30 = F_18 ( V_28 ) ;
V_32 = V_30 -> V_33 ;
V_31 = V_13 -> V_34 [ 0 ] ;
V_8 = V_13 -> V_8 -> V_8 ;
V_32 += ( V_2 -> V_4 -> V_35 . V_36 >> 16 ) * V_13 -> V_8 -> V_37 [ 0 ] ;
V_32 += ( V_2 -> V_4 -> V_35 . y1 >> 16 ) * V_31 ;
V_4 -> V_7 . V_38 = true ;
V_4 -> V_7 . V_31 = V_31 ;
V_4 -> V_7 . V_8 = V_8 ;
V_4 -> V_7 . V_32 = V_32 ;
V_4 -> V_7 . V_39 = V_2 -> V_4 -> V_40 . V_36 ;
V_4 -> V_7 . V_41 = V_2 -> V_4 -> V_40 . y1 ;
V_4 -> V_7 . V_42 = F_19 ( & V_2 -> V_4 -> V_40 ) ;
V_4 -> V_7 . V_43 = F_20 ( & V_2 -> V_4 -> V_40 ) ;
F_21 () ;
V_4 -> V_7 . V_44 = true ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_3 ( V_2 -> V_4 ) ;
V_4 -> V_7 . V_38 = false ;
F_21 () ;
V_4 -> V_7 . V_44 = true ;
}
int F_23 ( struct V_45 * V_46 , struct V_1 * V_2 ,
unsigned long V_47 , enum V_48 type )
{
int V_49 ;
V_49 = F_24 ( V_46 , V_2 , V_47 ,
& V_50 , V_51 ,
F_25 ( V_51 ) , NULL , type , NULL ) ;
if ( V_49 ) {
F_26 ( L_2 ) ;
return V_49 ;
}
F_27 ( V_2 , & V_52 ) ;
return 0 ;
}
