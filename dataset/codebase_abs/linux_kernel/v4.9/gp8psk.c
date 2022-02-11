static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 , V_12 = 0 ;
if ( V_7 > sizeof( V_9 -> V_13 ) )
return - V_14 ;
if ( ( V_11 = F_2 ( & V_2 -> V_15 ) ) )
return V_11 ;
while ( V_11 >= 0 && V_11 != V_7 && V_12 < 3 ) {
V_11 = F_3 ( V_2 -> V_16 ,
F_4 ( V_2 -> V_16 , 0 ) ,
V_3 ,
V_17 | V_18 ,
V_4 , V_5 , V_9 -> V_13 , V_7 ,
2000 ) ;
F_5 ( L_1 , V_12 , V_11 ) ;
V_12 ++ ;
}
if ( V_11 < 0 || V_11 != V_7 ) {
F_6 ( L_2 , V_3 ) ;
V_11 = - V_14 ;
} else {
V_11 = 0 ;
memcpy ( V_6 , V_9 -> V_13 , V_7 ) ;
}
F_7 ( L_3 , V_3 , V_4 , V_5 ) ;
F_8 ( V_6 , V_7 , F_7 ) ;
F_9 ( & V_2 -> V_15 ) ;
return V_11 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_1 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
F_7 ( L_4 , V_3 , V_4 , V_5 ) ;
F_8 ( V_6 , V_7 , F_7 ) ;
if ( V_7 > sizeof( V_9 -> V_13 ) )
return - V_14 ;
if ( ( V_11 = F_2 ( & V_2 -> V_15 ) ) )
return V_11 ;
memcpy ( V_9 -> V_13 , V_6 , V_7 ) ;
if ( F_3 ( V_2 -> V_16 ,
F_11 ( V_2 -> V_16 , 0 ) ,
V_3 ,
V_17 | V_19 ,
V_4 , V_5 , V_9 -> V_13 , V_7 ,
2000 ) != V_7 ) {
F_6 ( L_5 ) ;
V_11 = - V_14 ;
} else
V_11 = 0 ;
F_9 ( & V_2 -> V_15 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_20 )
{
return F_1 ( V_2 , V_21 , 0 , 0 , V_20 , 6 ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 * V_22 )
{
return F_1 ( V_2 , V_23 , 0 , 0 , V_22 , 1 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_22 , V_20 [ 6 ] ;
if ( ! F_12 ( V_2 , V_20 ) )
F_15 ( L_6 ,
V_20 [ 2 ] , V_20 [ 1 ] , V_20 [ 0 ] , F_16 ( V_20 ) ,
2000 + V_20 [ 5 ] , V_20 [ 4 ] , V_20 [ 3 ] ) ;
else
F_15 ( L_7 ) ;
if ( ! F_13 ( V_2 , & V_22 ) )
F_15 ( L_8 , V_22 ) ;
else
F_15 ( L_9 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_11 ;
const struct V_24 * V_25 = NULL ;
const T_1 * V_26 ;
T_1 * V_27 ;
if ( ( V_11 = F_18 ( & V_25 , V_28 ,
& V_2 -> V_16 -> V_29 ) ) != 0 ) {
F_19 ( L_10
L_11 ,
V_28 , V_11 ) ;
return V_11 ;
}
V_11 = - V_30 ;
if ( F_10 ( V_2 , V_31 , 1 , 0 , NULL , 0 ) )
goto V_32;
F_15 ( L_12 , V_28 ) ;
V_26 = V_25 -> V_13 ;
V_27 = F_20 ( 64 , V_33 | V_34 ) ;
if ( ! V_27 ) {
V_11 = - V_35 ;
goto V_32;
}
while ( V_26 [ 0 ] != 0xff ) {
T_2 V_36 = V_26 [ 0 ] + 4 ;
if ( V_26 + V_36 >= V_25 -> V_13 + V_25 -> V_37 ) {
F_19 ( L_13 ) ;
goto V_38;
}
if ( V_36 > 64 ) {
F_19 ( L_14 ) ;
goto V_38;
}
memcpy ( V_27 , V_26 , V_36 ) ;
if ( F_21 ( V_2 , V_27 , V_36 ) ) {
F_19 ( L_13 ) ;
goto V_38;
}
V_26 += V_36 ;
}
V_11 = 0 ;
V_38:
F_22 ( V_27 ) ;
V_32:
F_23 ( V_25 ) ;
return V_11 ;
}
static int F_24 ( struct V_1 * V_2 , int V_39 )
{
T_1 V_40 , V_27 ;
int V_41 = F_25 ( V_2 -> V_16 -> V_42 . V_43 ) ;
if ( V_39 ) {
F_1 ( V_2 , V_44 , 0 , 0 , & V_40 , 1 ) ;
if ( ! ( V_40 & V_45 ) ) {
if( V_41 == V_46 )
F_10 ( V_2 , V_47 , 1 , 0 , NULL , 0 ) ;
if ( F_1 ( V_2 , V_48 , 1 , 0 , & V_27 , 1 ) )
return - V_30 ;
F_14 ( V_2 ) ;
}
if ( V_41 == V_49 )
if ( ! ( V_40 & V_50 ) )
if( F_17 ( V_2 ) )
return - V_30 ;
if ( ! ( V_40 & V_51 ) )
if ( F_1 ( V_2 , V_52 , 1 , 0 ,
& V_27 , 1 ) )
return - V_30 ;
if ( V_41 == V_49 )
if ( F_10 ( V_2 , V_53 , 1 , 0 , NULL , 0 ) )
return - V_30 ;
if ( F_10 ( V_2 , V_54 , 0 , 0 , NULL , 0 ) )
return - V_30 ;
} else {
if ( F_1 ( V_2 , V_52 , 0 , 0 , & V_27 , 1 ) )
return - V_30 ;
if ( F_1 ( V_2 , V_48 , 0 , 0 , & V_27 , 1 ) )
return - V_30 ;
if( V_41 == V_46 )
F_10 ( V_2 , V_47 , 0 , 0 , NULL , 0 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_1 V_27 ;
int V_41 = F_25 ( V_2 -> V_16 -> V_42 . V_43 ) ;
F_7 ( L_15 ) ;
if ( F_1 ( V_2 , V_48 , 0 , 0 , & V_27 , 1 ) )
return - V_30 ;
if ( F_1 ( V_2 , V_48 , 1 , 0 , & V_27 , 1 ) )
return - V_30 ;
if ( V_41 == V_49 )
if ( F_17 ( V_2 ) )
return - V_30 ;
return 0 ;
}
static int F_27 ( struct V_55 * V_56 , int V_39 )
{
return F_10 ( V_56 -> V_29 , V_54 , V_39 , 0 , NULL , 0 ) ;
}
static int F_28 ( void * V_10 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_1 * V_6 , int V_7 )
{
struct V_1 * V_2 = V_10 ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
static int F_29 ( void * V_10 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_1 * V_6 , int V_7 )
{
struct V_1 * V_2 = V_10 ;
return F_10 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
static int F_30 ( void * V_10 )
{
struct V_1 * V_2 = V_10 ;
return F_26 ( V_2 ) ;
}
static int F_31 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_29 ;
int V_57 = F_25 ( V_2 -> V_16 -> V_42 . V_43 ) ;
int V_58 ;
V_58 = ( V_57 == V_49 ) ? true : false ;
V_56 -> V_59 [ 0 ] . V_60 = F_32 ( V_61 ,
& V_62 , V_2 , V_58 ) ;
return 0 ;
}
static int F_33 ( struct V_63 * V_64 ,
const struct V_65 * V_57 )
{
int V_11 ;
struct V_66 * V_16 = F_34 ( V_64 ) ;
V_11 = F_35 ( V_64 , & V_67 ,
V_68 , NULL , V_69 ) ;
if ( V_11 == 0 ) {
F_15 ( L_16 ,
F_25 ( V_16 -> V_42 . V_43 ) ) ;
}
return V_11 ;
}
