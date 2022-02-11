static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 [ 0 ] ;
struct V_9 * V_10 = & V_8 -> V_11 ;
unsigned short * V_12 = F_3 ( V_10 -> V_13 . V_14 [ 0 ] ) ;
struct V_15 V_16 ;
if ( V_8 -> V_17 != V_18 )
return;
F_4 ( V_6 -> V_19 , L_1 , V_20 ) ;
V_16 = * F_5 ( & V_8 -> V_21 , NULL ,
V_22 ,
V_23 ) ;
while ( ! F_6 () )
F_7 ( 1000 , 1500 ) ;
F_8 ( V_8 , V_12 , V_16 . V_24 ,
V_16 . V_25 ) ;
F_4 ( V_6 -> V_19 , L_2 , V_20 ) ;
}
static int F_9 ( struct V_26 * V_27 , int V_28 )
{
struct V_3 * V_4 = F_10 ( V_27 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 [ 0 ] ;
F_4 ( V_6 -> V_19 , L_3 , V_20 , V_28 ) ;
if ( V_28 ) {
if ( V_8 -> V_17 != V_18 )
return 0 ;
F_11 ( V_4 -> V_29 , & V_4 -> V_2 ) ;
return 0 ;
}
F_12 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_26 * V_27 ,
struct V_30 * V_31 )
{
return 0 ;
}
static int F_14 ( struct V_26 * V_27 ,
struct V_30 * V_31 )
{
return 0 ;
}
static int F_15 ( struct V_26 * V_27 ,
struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_15 * V_36 = & V_35 -> V_35 ;
struct V_3 * V_4 = F_10 ( V_27 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 [ 0 ] ;
struct V_15 * V_16 ;
if ( V_35 -> V_37 )
return - V_38 ;
V_16 = F_5 ( & V_8 -> V_21 , NULL ,
V_22 ,
V_23 ) ;
V_36 -> V_24 = V_16 -> V_24 ;
V_36 -> V_25 = V_16 -> V_25 ;
V_36 -> V_39 = V_16 -> V_39 ;
return 0 ;
}
static int F_16 ( struct V_26 * V_27 ,
struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_15 * V_36 = & V_35 -> V_35 ;
if ( V_35 -> V_37 )
return - V_38 ;
F_15 ( V_27 , V_33 , V_35 ) ;
if ( V_35 -> V_40 == V_41 )
V_33 -> V_42 = * V_36 ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 )
{
return 0 ;
}
static int F_18 ( struct V_26 * V_27 , int V_43 )
{
return 0 ;
}
static int F_19 ( struct V_26 * V_27 ,
struct V_32 * V_33 ,
struct V_44 * V_39 )
{
return 0 ;
}
static int F_20 ( struct V_26 * V_27 ,
struct V_32 * V_33 ,
struct V_45 * V_46 )
{
return 0 ;
}
static int F_21 ( struct V_26 * V_27 ,
struct V_32 * V_33 ,
struct V_47
* V_48 )
{
return 0 ;
}
void
F_22 ( struct V_3 * V_4 )
{
F_23 ( & V_4 -> V_27 . V_49 ) ;
F_24 ( & V_4 -> V_27 ) ;
}
int F_25 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
return F_26 ( V_51 , & V_4 -> V_27 ) ;
}
void F_27 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
if ( V_4 -> V_29 ) {
F_28 ( V_4 -> V_29 ) ;
V_4 -> V_29 = NULL ;
}
}
int F_29 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_26 * V_27 = & V_4 -> V_27 ;
struct V_52 * V_53 = V_4 -> V_53 ;
struct V_54 * V_55 = & V_27 -> V_49 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_29 = F_30 ( V_6 -> V_56 . V_57 , 0 , 1 ) ;
if ( V_4 -> V_29 == NULL ) {
F_31 ( V_6 -> V_19 , L_4 ) ;
return - V_58 ;
}
F_32 ( & V_4 -> V_2 , F_1 ) ;
F_33 ( V_27 , & V_59 ) ;
V_27 -> V_60 |= V_61 ;
strcpy ( V_27 -> V_57 , L_5 ) ;
F_34 ( V_27 , V_4 ) ;
V_53 [ 0 ] . V_60 = V_62 ;
V_55 -> V_63 = V_64 ;
return F_35 ( V_55 , 1 , V_53 ) ;
}
