static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_4 -> V_5 )
return 0 ;
return F_2 ( V_4 -> V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_6 )
{
if ( V_6 -> V_5 )
F_4 ( V_6 -> V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
struct V_11 * V_11 = F_6 ( V_2 ) ;
struct V_3 * V_12 = V_2 -> V_12 ;
struct V_13 V_14 ;
int V_15 ;
F_7 ( L_1 , V_11 -> V_16 , V_12 -> V_17 , V_12 -> V_5 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_18 = V_19 ;
V_14 . V_20 = V_21 ;
V_14 . V_22 = 0xff ;
V_14 . V_23 = V_12 -> V_24 ;
F_8 ( V_12 -> V_5 , V_12 , & V_14 ) ;
F_7 ( L_2 , V_14 . V_25 , V_14 . V_26 ,
V_14 . V_27 , V_14 . V_28 ,
V_14 . V_29 ) ;
F_7 ( L_3 , V_14 . V_30 , V_14 . V_31 ,
& V_14 . V_32 , & V_14 . V_33 ) ;
V_15 = V_8 -> V_34 -> V_35 ( V_11 -> V_36 , & V_14 ,
F_9 ( V_12 -> V_17 ) , false ,
F_10 ( V_12 -> V_17 ) ) ;
if ( V_15 ) {
F_11 ( V_2 -> V_9 -> V_9 , L_4 ,
V_11 -> V_16 ) ;
V_8 -> V_34 -> V_37 ( V_11 -> V_36 , false ) ;
return;
}
V_8 -> V_34 -> V_37 ( V_11 -> V_36 , true ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
struct V_11 * V_11 = F_6 ( V_2 ) ;
V_2 -> V_12 -> V_20 = V_21 ;
V_2 -> V_12 -> V_24 = V_2 -> type == V_38
? 0 : V_11 -> V_36 ;
V_8 -> V_34 -> V_37 ( V_11 -> V_36 , false ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_12 )
{
struct V_39 * V_40 ;
if ( ! V_12 -> V_5 )
return 0 ;
if ( F_14 ( ! V_12 -> V_17 ) )
return 0 ;
V_40 = F_15 ( V_12 -> V_12 , V_12 -> V_17 ) ;
if ( F_14 ( ! V_40 ) )
return 0 ;
if ( ! V_40 -> V_41 )
return 0 ;
if ( V_12 -> V_42 < 0 || V_12 -> V_43 < 0 )
return - V_44 ;
if ( V_12 -> V_42 + V_12 -> V_45 > V_40 -> V_46 . V_47 )
return - V_44 ;
if ( V_12 -> V_43 + V_12 -> V_48 > V_40 -> V_46 . V_49 )
return - V_44 ;
if ( V_12 -> V_20 != V_21 &&
! F_16 ( V_12 -> V_5 ) )
return - V_44 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_6 ( V_2 ) ;
F_7 ( L_5 , V_11 -> V_16 ) ;
F_18 ( V_2 ) ;
F_19 ( V_11 ) ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_52 * V_9 = V_2 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_10 ;
if ( V_8 -> V_53 ) {
if ( ! V_2 -> V_54 )
F_21 ( V_2 ,
V_21 ,
V_21 | V_55 |
V_56 | V_57 |
V_58 | V_59 ) ;
if ( V_2 -> V_54 && V_51 != & V_2 -> V_60 )
F_22 ( V_51 , V_2 -> V_54 ,
V_21 ) ;
}
F_22 ( V_51 , V_8 -> V_61 , 0 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_6 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( ! V_2 -> V_12 )
return;
V_2 -> V_12 -> V_24 = V_2 -> type == V_38
? 0 : V_11 -> V_36 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_12 ,
struct V_62 * V_63 ,
T_1 V_64 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
if ( V_63 == V_8 -> V_61 )
V_12 -> V_24 = V_64 ;
else
return - V_44 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_3 * V_12 ,
struct V_62 * V_63 ,
T_1 * V_64 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
if ( V_63 == V_8 -> V_61 )
* V_64 = V_12 -> V_24 ;
else
return - V_44 ;
return 0 ;
}
struct V_1 * F_27 ( struct V_52 * V_9 ,
int V_65 , enum V_66 type ,
T_2 V_67 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
unsigned int V_68 = V_8 -> V_34 -> V_69 () ;
struct V_1 * V_2 ;
struct V_11 * V_11 ;
enum V_70 V_36 ;
int V_15 ;
T_2 V_71 ;
const T_2 * V_72 ;
if ( F_14 ( V_65 >= F_28 ( V_73 ) ) )
return F_29 ( - V_44 ) ;
V_36 = V_73 [ V_65 ] ;
F_7 ( L_6 , V_74 [ V_36 ] , type ) ;
V_11 = F_30 ( sizeof( * V_11 ) , V_75 ) ;
if ( ! V_11 )
return F_29 ( - V_76 ) ;
V_72 = V_8 -> V_34 -> V_77 ( V_36 ) ;
for ( V_71 = 0 ; V_72 [ V_71 ] ; ++ V_71 )
;
V_11 -> V_36 = V_36 ;
V_11 -> V_16 = V_74 [ V_36 ] ;
V_2 = & V_11 -> V_60 ;
V_15 = F_31 ( V_9 , V_2 , V_67 ,
& V_78 , V_72 ,
V_71 , NULL , type , NULL ) ;
if ( V_15 < 0 )
goto error;
F_32 ( V_2 , & V_79 ) ;
F_20 ( V_2 , & V_2 -> V_60 ) ;
F_33 ( V_2 , 0 , 0 , V_68 - 1 ) ;
return V_2 ;
error:
F_11 ( V_9 -> V_9 , L_7 ,
V_80 , V_74 [ V_36 ] ) ;
F_19 ( V_11 ) ;
return NULL ;
}
