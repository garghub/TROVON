static void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
bool V_5 = false ;
char V_6 [ 64 ] ;
V_4 . V_7 = F_2 ( F_3 ( V_2 -> V_8 ) ) ;
if ( V_4 . V_9 . V_10 || V_4 . V_9 . V_11 ) {
union V_12 V_13 ;
V_13 . V_7 = F_2 ( F_4 ( V_2 -> V_8 ) ) ;
snprintf ( V_6 , sizeof( V_6 ) ,
L_1 ,
V_13 . V_14 . V_15 , V_13 . V_14 . V_16 ,
V_13 . V_14 . V_17 , V_13 . V_14 . V_18 , V_13 . V_14 . V_19 ) ;
}
if ( V_4 . V_9 . V_10 ) {
F_5 ( V_20 , V_2 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , V_6 , L_2 ) ;
V_4 . V_9 . V_10 = - 1 ;
V_5 = true ;
}
if ( V_4 . V_9 . V_11 ) {
F_5 ( V_21 , V_2 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , V_6 , L_2 ) ;
V_4 . V_9 . V_11 = - 1 ;
V_5 = true ;
}
if ( V_5 )
F_6 ( F_3 ( V_2 -> V_8 ) , V_4 . V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
union V_22 V_23 ;
bool V_5 = false ;
char V_6 [ 64 ] ;
V_23 . V_7 = F_2 ( F_8 ( V_2 -> V_8 ) ) ;
if ( V_23 . V_9 . V_10 || V_23 . V_9 . V_11 ) {
union V_12 V_13 ;
V_13 . V_7 = F_2 ( F_4 ( V_2 -> V_8 ) ) ;
snprintf ( V_6 , sizeof( V_6 ) ,
L_1 ,
V_13 . V_24 . V_15 , V_13 . V_24 . V_16 ,
V_13 . V_24 . V_17 , V_13 . V_24 . V_18 , V_13 . V_24 . V_19 ) ;
}
if ( V_23 . V_9 . V_10 ) {
F_5 ( V_20 , V_2 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , V_6 , L_2 ) ;
V_23 . V_9 . V_10 = - 1 ;
V_5 = true ;
}
if ( V_23 . V_9 . V_11 ) {
F_5 ( V_21 , V_2 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , V_6 , L_2 ) ;
V_23 . V_9 . V_11 = - 1 ;
V_5 = true ;
}
if ( V_5 )
F_6 ( F_8 ( V_2 -> V_8 ) , V_23 . V_7 ) ;
}
static int F_9 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_27 V_28 [ 1 ] ;
int V_29 = V_26 -> V_30 ;
V_28 [ 0 ] . type = V_31 ;
V_28 [ 0 ] . V_32 = 1 ;
V_28 [ 0 ] . V_33 = false ;
if ( F_10 ( V_34 ) ) {
union V_3 V_4 ;
V_4 . V_7 = F_2 ( F_3 ( 0 ) ) ;
if ( ! V_4 . V_9 . V_35 ) {
F_11 ( & V_26 -> V_36 , L_3 ) ;
return 0 ;
}
V_2 = F_12 ( V_29 , F_13 ( V_28 ) , V_28 , 0 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_26 = & V_26 -> V_36 ;
V_2 -> V_38 = V_38 ( & V_26 -> V_36 ) ;
V_2 -> V_39 = L_4 ;
V_2 -> V_40 = L_5 ;
V_2 -> V_41 = F_1 ;
if ( F_14 ( V_2 ) ) {
F_15 ( & V_26 -> V_36 , L_6 ) ;
F_16 ( V_2 ) ;
return - V_37 ;
}
V_4 . V_7 = F_2 ( F_3 ( V_29 ) ) ;
V_4 . V_9 . V_42 = 0 ;
V_4 . V_9 . V_43 = 0 ;
F_6 ( F_3 ( V_29 ) , V_4 . V_7 ) ;
} else {
union V_44 V_45 ;
union V_46 V_47 ;
V_47 . V_7 = F_2 ( F_17 ( 0 ) ) ;
if ( ! V_47 . V_9 . V_35 ) {
F_11 ( & V_26 -> V_36 , L_3 ) ;
return 0 ;
}
V_2 = F_12 ( V_29 , F_13 ( V_28 ) , V_28 , 0 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_26 = & V_26 -> V_36 ;
V_2 -> V_38 = V_38 ( & V_26 -> V_36 ) ;
V_2 -> V_39 = L_4 ;
V_2 -> V_40 = L_7 ;
V_2 -> V_41 = F_7 ;
if ( F_14 ( V_2 ) ) {
F_15 ( & V_26 -> V_36 , L_6 ) ;
F_16 ( V_2 ) ;
return - V_37 ;
}
V_45 . V_7 = F_2 ( F_3 ( V_29 ) ) ;
V_45 . V_9 . V_42 = 0 ;
V_45 . V_9 . V_43 = 0 ;
F_6 ( F_3 ( V_29 ) , V_45 . V_7 ) ;
}
F_18 ( V_26 , V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_20 ( V_26 ) ;
F_21 ( & V_26 -> V_36 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
