static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = F_2 ( V_2 ) ;
struct V_17 * V_18 = F_3 ( V_4 ) ;
int V_19 ;
F_4 ( L_1 ,
V_4 -> V_20 . V_21 , F_5 ( V_18 ) ,
V_2 -> V_20 . V_21 , F_6 ( V_16 ) , V_6 -> V_20 . V_21 ) ;
F_4 ( L_2 , V_9 , V_10 , V_7 , V_8 ) ;
V_19 = F_7 ( V_18 , V_16 ) ;
if ( V_19 ) {
F_8 ( L_3 ) ;
return V_19 ;
}
V_19 = F_9 ( V_16 , V_6 , & V_4 -> V_22 , V_18 -> V_21 ,
V_7 , V_8 , V_9 , V_10 ,
V_11 >> 16 , V_12 >> 16 ,
V_13 >> 16 , V_14 >> 16 ) ;
if ( V_19 ) {
F_8 ( L_4 ) ;
return V_19 ;
}
V_19 = F_10 ( V_16 ) ;
if ( V_19 ) {
F_8 ( L_5 ) ;
return V_19 ;
}
V_19 = F_11 ( V_18 , V_16 , true ) ;
if ( V_19 ) {
F_8 ( L_6 ) ;
return V_19 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_23 , V_24 ;
if ( ! V_2 -> V_4 ) {
F_13 ( L_7 , V_2 -> V_20 . V_21 ) ;
return 0 ;
}
V_16 = F_2 ( V_2 ) ;
V_18 = F_3 ( V_2 -> V_4 ) ;
F_13 ( L_8 ,
V_2 -> V_4 -> V_20 . V_21 , F_5 ( V_18 ) ,
V_2 -> V_20 . V_21 , F_6 ( V_16 ) ) ;
V_24 = F_11 ( V_18 , V_16 , false ) ;
if ( V_24 )
F_8 ( L_9 ) ;
F_14 ( V_25 ) ;
V_23 = F_15 ( V_16 ) ;
if ( V_23 )
F_8 ( L_10 ) ;
if ( V_23 || V_24 )
return - V_26 ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_13 ( L_11 ) ;
F_12 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
T_2 V_29 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_32 * V_33 = V_31 -> V_34 ;
struct V_15 * V_16 = F_2 ( V_2 ) ;
F_13 ( L_11 ) ;
if ( V_28 == V_33 -> V_35 ) {
V_16 -> V_36 = V_29 ;
return 0 ;
}
return - V_26 ;
}
static void F_19 ( struct V_1 * V_2 ,
T_2 V_37 )
{
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_32 * V_33 = V_31 -> V_34 ;
struct V_27 * V_38 ;
struct V_15 * V_16 = F_2 ( V_2 ) ;
V_38 = V_33 -> V_35 ;
if ( ! V_38 ) {
V_38 = F_20 ( V_31 , 0 , L_12 , 0 ,
V_39 - 1 ) ;
if ( ! V_38 )
return;
V_33 -> V_35 = V_38 ;
}
F_21 ( & V_2 -> V_20 , V_38 , V_37 ) ;
V_16 -> V_36 = V_37 ;
}
struct V_1 * F_22 ( struct V_30 * V_31 ,
struct V_15 * V_16 ,
unsigned int V_40 ,
enum V_41 type )
{
int V_42 , V_43 ;
T_2 V_44 = 0 ;
V_42 = F_23 ( V_31 , & V_16 -> V_2 , V_40 ,
& V_45 ,
F_24 ( V_16 ) ,
F_25 ( V_16 ) , type ) ;
if ( V_42 ) {
F_8 ( L_13 ) ;
return NULL ;
}
for ( V_43 = 0 ; V_43 < F_26 ( V_46 ) ; V_43 ++ )
if ( V_46 [ V_43 ] == V_16 -> V_47 )
break;
V_44 = V_43 ;
if ( type == V_48 )
F_19 ( & V_16 -> V_2 ,
V_44 ) ;
F_13 ( L_14 ,
V_16 -> V_2 . V_20 . V_21 ,
F_6 ( V_16 ) , V_44 ) ;
return & V_16 -> V_2 ;
}
