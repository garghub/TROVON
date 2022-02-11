static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 , void * V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
return F_2 ( V_9 -> V_11 , F_3 ( V_9 -> V_11 , 0 ) ,
V_3 , V_12 | V_13 |
V_14 , V_4 , V_5 , V_6 , V_7 , 2000 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 , void * V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
return F_2 ( V_9 -> V_11 , F_5 ( V_9 -> V_11 , 0 ) ,
V_3 , V_12 | V_13 ,
V_4 , V_5 , V_6 , V_7 , 2000 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_17 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_15 * V_18 ;
int V_19 = 0 ;
int V_20 , V_3 ;
for ( V_20 = 0 ; V_19 >= 0 && V_20 < V_17 ; V_20 ++ ) {
V_18 = & V_16 [ V_20 ] ;
if ( V_18 -> V_21 & V_22 ) {
V_3 = V_23 ;
V_19 = F_1 ( V_2 , V_3 , V_18 -> V_21 ,
V_18 -> V_24 , V_18 -> V_25 ,
V_18 -> V_7 ) ;
if ( V_19 != V_18 -> V_7 ) {
F_7 ( & V_2 -> V_26 , L_1 ) ;
return - V_27 ;
}
} else {
V_3 = V_28 ;
V_19 = F_4 ( V_2 , V_3 , V_18 -> V_21 ,
V_18 -> V_24 , V_18 -> V_25 , V_18 -> V_7 ) ;
if ( V_19 != V_18 -> V_7 ) {
F_7 ( & V_2 -> V_26 , L_2 ) ;
return - V_27 ;
}
}
V_19 = F_1 ( V_2 , V_29 , 0 , 0 , NULL , 0 ) ;
if ( V_19 ) {
F_7 ( & V_2 -> V_26 , L_3 ) ;
return - V_27 ;
}
V_19 = F_1 ( V_2 , V_30 , 0 , 0 ,
& V_9 -> V_31 , 1 ) ;
if ( V_19 != 1 ) {
F_7 ( & V_2 -> V_26 , L_4 ) ;
return - V_27 ;
}
if ( V_9 -> V_31 != V_32 ) {
F_8 ( & V_2 -> V_26 , L_5 , V_9 -> V_31 ) ;
return - V_27 ;
}
}
return V_20 ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
return V_33 | V_34 ;
}
static int F_10 ( struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
int V_19 ;
struct V_8 * V_9 ;
T_2 V_39 ;
V_9 = F_11 ( & V_36 -> V_26 , sizeof( * V_9 ) , V_40 ) ;
if ( ! V_9 )
return - V_41 ;
V_9 -> V_11 = F_12 ( F_13 ( V_36 ) ) ;
V_9 -> V_36 = V_36 ;
F_14 ( V_36 , V_9 ) ;
V_9 -> V_2 . V_42 = V_43 ;
V_9 -> V_2 . V_44 = V_45 ;
V_9 -> V_2 . V_46 = & V_47 ;
V_9 -> V_2 . V_10 = V_9 ;
snprintf ( V_9 -> V_2 . V_48 , sizeof( V_9 -> V_2 . V_48 ) ,
L_6 ,
V_9 -> V_11 -> V_49 -> V_50 , V_9 -> V_11 -> V_51 ) ;
V_19 = F_1 ( & V_9 -> V_2 , V_52 , 52 , 0 ,
NULL , 0 ) ;
if ( V_19 ) {
F_7 ( & V_36 -> V_26 , L_7 ) ;
F_15 ( V_9 -> V_11 ) ;
return V_19 ;
}
F_16 ( & ( V_9 -> V_2 ) ) ;
V_39 = F_17 ( V_9 -> V_11 -> V_53 . V_54 ) ;
F_18 ( & V_36 -> V_26 ,
L_8 ,
V_39 >> 8 , V_39 & 0xff ,
V_9 -> V_11 -> V_49 -> V_50 , V_9 -> V_11 -> V_51 ) ;
return 0 ;
}
static void F_19 ( struct V_35 * V_36 )
{
struct V_8 * V_9 = F_20 ( V_36 ) ;
F_21 ( & ( V_9 -> V_2 ) ) ;
F_14 ( V_36 , NULL ) ;
F_15 ( V_9 -> V_11 ) ;
}
