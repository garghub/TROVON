static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
return ( F_2 ( V_2 , V_4 , 0 , 0 , V_3 , 6 ) ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_5 )
{
return ( F_2 ( V_2 , V_6 , 0 , 0 , V_5 , 1 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_5 , V_3 [ 6 ] ;
if ( ! F_1 ( V_2 , V_3 ) )
F_5 ( L_1 ,
V_3 [ 2 ] , V_3 [ 1 ] , V_3 [ 0 ] , F_6 ( V_3 ) ,
2000 + V_3 [ 5 ] , V_3 [ 4 ] , V_3 [ 3 ] ) ;
else
F_5 ( L_2 ) ;
if ( ! F_3 ( V_2 , & V_5 ) )
F_5 ( L_3 , V_5 ) ;
else
F_5 ( L_4 ) ;
}
int F_2 ( struct V_1 * V_2 , T_1 V_7 , T_2 V_8 , T_2 V_9 , T_1 * V_10 , int V_11 )
{
int V_12 = 0 , V_13 = 0 ;
if ( ( V_12 = F_7 ( & V_2 -> V_14 ) ) )
return V_12 ;
while ( V_12 >= 0 && V_12 != V_11 && V_13 < 3 ) {
V_12 = F_8 ( V_2 -> V_15 ,
F_9 ( V_2 -> V_15 , 0 ) ,
V_7 ,
V_16 | V_17 ,
V_8 , V_9 , V_10 , V_11 ,
2000 ) ;
F_10 ( L_5 , V_13 , V_12 ) ;
V_13 ++ ;
}
if ( V_12 < 0 || V_12 != V_11 ) {
F_11 ( L_6 , V_7 ) ;
V_12 = - V_18 ;
} else
V_12 = 0 ;
F_12 ( L_7 , V_7 , V_8 , V_9 ) ;
F_13 ( V_10 , V_11 , F_12 ) ;
F_14 ( & V_2 -> V_14 ) ;
return V_12 ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_7 , T_2 V_8 ,
T_2 V_9 , T_1 * V_10 , int V_11 )
{
int V_12 ;
F_12 ( L_8 , V_7 , V_8 , V_9 ) ;
F_13 ( V_10 , V_11 , F_12 ) ;
if ( ( V_12 = F_7 ( & V_2 -> V_14 ) ) )
return V_12 ;
if ( F_8 ( V_2 -> V_15 ,
F_16 ( V_2 -> V_15 , 0 ) ,
V_7 ,
V_16 | V_19 ,
V_8 , V_9 , V_10 , V_11 ,
2000 ) != V_11 ) {
F_11 ( L_9 ) ;
V_12 = - V_18 ;
} else
V_12 = 0 ;
F_14 ( & V_2 -> V_14 ) ;
return V_12 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_12 ;
const struct V_20 * V_21 = NULL ;
const T_1 * V_22 ;
T_1 * V_23 ;
if ( ( V_12 = F_18 ( & V_21 , V_24 ,
& V_2 -> V_15 -> V_25 ) ) != 0 ) {
F_19 ( L_10
L_11 ,
V_24 , V_12 ) ;
return V_12 ;
}
V_12 = - V_26 ;
if ( F_15 ( V_2 , V_27 , 1 , 0 , NULL , 0 ) )
goto V_28;
F_5 ( L_12 , V_24 ) ;
V_22 = V_21 -> V_29 ;
V_23 = F_20 ( 64 , V_30 | V_31 ) ;
if ( ! V_23 ) {
V_12 = - V_32 ;
goto V_28;
}
while ( V_22 [ 0 ] != 0xff ) {
T_2 V_33 = V_22 [ 0 ] + 4 ;
if ( V_22 + V_33 >= V_21 -> V_29 + V_21 -> V_34 ) {
F_19 ( L_13 ) ;
goto V_35;
}
memcpy ( V_23 , V_22 , V_33 ) ;
if ( F_21 ( V_2 , V_23 , V_33 ) ) {
F_19 ( L_13 ) ;
goto V_35;
}
V_22 += V_33 ;
}
V_12 = 0 ;
V_35:
F_22 ( V_23 ) ;
V_28:
F_23 ( V_21 ) ;
return V_12 ;
}
static int F_24 ( struct V_1 * V_2 , int V_36 )
{
T_1 V_37 , V_23 ;
int V_38 = F_25 ( V_2 -> V_15 -> V_39 . V_40 ) ;
if ( V_36 ) {
F_2 ( V_2 , V_41 , 0 , 0 , & V_37 , 1 ) ;
if ( ! ( V_37 & V_42 ) ) {
if( V_38 == V_43 )
F_15 ( V_2 , V_44 , 1 , 0 , NULL , 0 ) ;
if ( F_2 ( V_2 , V_45 , 1 , 0 , & V_23 , 1 ) )
return - V_26 ;
F_4 ( V_2 ) ;
}
if ( V_38 == V_46 )
if ( ! ( V_37 & V_47 ) )
if( F_17 ( V_2 ) )
return - V_26 ;
if ( ! ( V_37 & V_48 ) )
if ( F_2 ( V_2 , V_49 , 1 , 0 ,
& V_23 , 1 ) )
return - V_26 ;
if ( V_38 == V_46 )
if ( F_15 ( V_2 , V_50 , 1 , 0 , NULL , 0 ) )
return - V_26 ;
if ( F_15 ( V_2 , V_51 , 0 , 0 , NULL , 0 ) )
return - V_26 ;
} else {
if ( F_2 ( V_2 , V_49 , 0 , 0 , & V_23 , 1 ) )
return - V_26 ;
if ( F_2 ( V_2 , V_45 , 0 , 0 , & V_23 , 1 ) )
return - V_26 ;
if( V_38 == V_43 )
F_15 ( V_2 , V_44 , 0 , 0 , NULL , 0 ) ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
T_1 V_23 ;
int V_38 = F_25 ( V_2 -> V_15 -> V_39 . V_40 ) ;
if ( F_2 ( V_2 , V_45 , 0 , 0 , & V_23 , 1 ) )
return - V_26 ;
if ( F_2 ( V_2 , V_45 , 1 , 0 , & V_23 , 1 ) )
return - V_26 ;
if ( V_38 == V_46 )
if ( F_17 ( V_2 ) )
return - V_26 ;
return 0 ;
}
static int F_27 ( struct V_52 * V_53 , int V_36 )
{
return F_15 ( V_53 -> V_25 , V_51 , V_36 , 0 , NULL , 0 ) ;
}
static int F_28 ( struct V_52 * V_53 )
{
V_53 -> V_54 [ 0 ] . V_55 = F_29 ( V_53 -> V_25 ) ;
return 0 ;
}
static int F_30 ( struct V_56 * V_57 ,
const struct V_58 * V_59 )
{
int V_12 ;
struct V_60 * V_15 = F_31 ( V_57 ) ;
V_12 = F_32 ( V_57 , & V_61 ,
V_62 , NULL , V_63 ) ;
if ( V_12 == 0 ) {
F_5 ( L_14 ,
F_25 ( V_15 -> V_39 . V_40 ) ) ;
}
return V_12 ;
}
static int T_3 F_33 ( void )
{
int V_64 ;
if ( ( V_64 = F_34 ( & V_65 ) ) ) {
F_19 ( L_15 , V_64 ) ;
return V_64 ;
}
return 0 ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_65 ) ;
}
