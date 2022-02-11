static void F_1 ( struct V_1 * V_2 , bool V_3 ,
T_1 V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 -> V_11 ) ;
unsigned int V_12 , V_13 ;
int V_14 , V_15 ;
if ( F_3 ( ! V_8 -> V_11 || ( V_3 && ! V_8 -> V_11 -> V_16 ) ) )
return;
if ( V_8 -> V_11 -> V_16 ) {
V_12 = V_8 -> V_11 -> V_16 -> V_17 [ 0 ] ;
V_13 = V_8 -> V_11 -> V_16 -> V_18 ;
} else {
V_12 = 0 ;
V_13 = V_19 ;
}
V_14 = V_8 -> V_11 -> V_20 ;
V_15 = V_8 -> V_11 -> V_21 ;
if ( V_14 < 0 ) {
V_4 -= V_14 * 4 ;
V_14 = 0 ;
}
if ( V_15 < 0 ) {
V_4 -= V_15 * V_12 ;
V_15 = 0 ;
}
V_11 -> V_22 . V_3 = V_3 ;
V_11 -> V_22 . V_12 = V_12 ;
V_11 -> V_22 . V_13 = V_13 ;
V_11 -> V_22 . V_4 = V_4 ;
V_11 -> V_22 . V_14 = V_14 ;
V_11 -> V_22 . V_15 = V_15 ;
V_11 -> V_22 . V_23 = V_6 -> V_24 - V_6 -> V_25 ;
V_11 -> V_22 . V_26 = V_6 -> V_27 - V_6 -> y1 ;
F_4 () ;
V_11 -> V_22 . V_28 = true ;
}
static void F_5 ( struct V_7 * V_8 )
{
struct V_10 * V_11 ;
if ( V_8 -> V_11 ) {
if ( V_8 -> V_11 -> V_16 )
F_6 ( V_8 -> V_11 -> V_16 ) ;
V_11 = F_2 ( V_8 -> V_11 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
} else {
V_11 = F_7 ( sizeof( * V_11 ) , V_29 ) ;
if ( ! V_11 )
return;
V_8 -> V_11 = & V_11 -> V_9 ;
}
V_11 -> V_9 . V_8 = V_8 ;
V_11 -> V_22 . V_13 = V_30 ;
}
static struct V_31 * F_8 ( struct V_7 * V_8 )
{
struct V_10 * V_32 = F_2 ( V_8 -> V_11 ) ;
struct V_10 * V_11 ;
V_11 = F_7 ( sizeof( * V_11 ) , V_29 ) ;
if ( ! V_11 )
return NULL ;
F_9 ( V_8 , & V_11 -> V_9 ) ;
F_3 ( V_11 -> V_9 . V_8 != V_8 ) ;
V_11 -> V_22 = V_32 -> V_22 ;
return & V_11 -> V_9 ;
}
static void F_10 ( struct V_7 * V_8 ,
struct V_31 * V_11 )
{
F_11 ( V_11 ) ;
F_12 ( F_2 ( V_11 ) ) ;
}
static int F_13 ( struct V_7 * V_8 ,
struct V_31 * V_11 )
{
struct V_33 * V_16 = V_11 -> V_16 ;
struct V_34 * V_35 ;
bool V_36 ;
struct V_5 V_6 = {
. V_25 = V_11 -> V_20 ,
. y1 = V_11 -> V_21 ,
. V_24 = V_11 -> V_20 + V_11 -> V_37 ,
. V_27 = V_11 -> V_21 + V_11 -> V_38 ,
} ;
struct V_5 V_39 = {
. V_25 = V_11 -> V_40 ,
. y1 = V_11 -> V_41 ,
. V_24 = V_11 -> V_40 + V_11 -> V_42 ,
. V_27 = V_11 -> V_41 + V_11 -> V_43 ,
} ;
struct V_5 V_44 = { 0 , } ;
if ( ! V_16 )
return 0 ;
if ( ! F_14 ( V_16 ) ) {
F_15 ( L_1 ) ;
return - V_45 ;
}
if ( ! V_11 -> V_46 )
return 0 ;
V_35 = F_16 ( V_11 -> V_11 , V_11 -> V_46 ) ;
if ( F_17 ( V_35 ) )
return F_18 ( V_35 ) ;
V_44 . V_24 = V_35 -> V_47 . V_48 ;
V_44 . V_27 = V_35 -> V_47 . V_49 ;
return F_19 ( V_8 , V_11 -> V_46 , V_16 ,
& V_39 , & V_6 , & V_44 ,
V_11 -> V_50 ,
V_51 ,
V_51 ,
true , true , & V_36 ) ;
}
static void F_20 ( struct V_7 * V_8 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_2 ( V_8 -> V_11 ) ;
struct V_52 * V_46 = V_11 -> V_9 . V_46 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_1 * V_2 = F_21 ( V_8 ) ;
struct V_5 V_6 = {
. V_25 = V_11 -> V_9 . V_20 ,
. y1 = V_11 -> V_9 . V_21 ,
. V_24 = V_11 -> V_9 . V_20 + V_11 -> V_9 . V_37 ,
. V_27 = V_11 -> V_9 . V_21 + V_11 -> V_9 . V_38 ,
} ;
struct V_5 V_44 = { 0 , } ;
if ( ! V_46 )
return;
V_44 . V_24 = V_11 -> V_9 . V_46 -> V_11 -> V_47 . V_48 ;
V_44 . V_27 = V_11 -> V_9 . V_46 -> V_11 -> V_47 . V_49 ;
F_22 ( & V_6 , & V_44 ) ;
V_54 = F_14 ( V_11 -> V_9 . V_16 ) ;
V_56 = F_23 ( V_54 ) ;
F_1 ( V_2 , true , V_56 -> V_57 , & V_6 ) ;
}
static void F_24 ( struct V_7 * V_8 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_2 ( V_8 -> V_11 ) ;
V_11 -> V_22 . V_3 = false ;
F_4 () ;
V_11 -> V_22 . V_28 = true ;
}
int F_25 ( struct V_58 * V_59 , struct V_1 * V_2 ,
unsigned long V_60 , enum V_61 type ,
unsigned int V_62 )
{
int V_63 ;
V_63 = F_26 ( V_59 , & V_2 -> V_9 , V_60 ,
& V_64 , V_65 ,
F_27 ( V_65 ) , type , NULL ) ;
if ( V_63 ) {
F_28 ( L_2 ) ;
return V_63 ;
}
F_29 ( & V_2 -> V_9 , & V_66 ) ;
V_2 -> V_67 = V_62 ;
return 0 ;
}
