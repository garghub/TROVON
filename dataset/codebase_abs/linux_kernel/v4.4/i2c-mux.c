static int F_1 ( struct V_1 * V_2 ,
struct V_3 V_4 [] , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_1 * V_9 = V_7 -> V_9 ;
int V_10 ;
V_10 = V_7 -> V_11 ( V_9 , V_7 -> V_12 , V_7 -> V_13 ) ;
if ( V_10 >= 0 )
V_10 = F_2 ( V_9 , V_4 , V_5 ) ;
if ( V_7 -> V_14 )
V_7 -> V_14 ( V_9 , V_7 -> V_12 , V_7 -> V_13 ) ;
return V_10 ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_15 , unsigned short V_16 ,
char V_17 , T_2 V_18 ,
int V_19 , union V_20 * V_21 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_1 * V_9 = V_7 -> V_9 ;
int V_10 ;
V_10 = V_7 -> V_11 ( V_9 , V_7 -> V_12 , V_7 -> V_13 ) ;
if ( V_10 >= 0 )
V_10 = V_9 -> V_22 -> V_23 ( V_9 , V_15 , V_16 ,
V_17 , V_18 , V_19 , V_21 ) ;
if ( V_7 -> V_14 )
V_7 -> V_14 ( V_9 , V_7 -> V_12 , V_7 -> V_13 ) ;
return V_10 ;
}
static T_3 F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_1 * V_9 = V_7 -> V_9 ;
return V_9 -> V_22 -> V_24 ( V_9 ) ;
}
static unsigned int F_5 ( struct V_1 * V_9 )
{
unsigned int V_25 = 0 ;
do {
V_25 |= V_9 -> V_25 ;
V_9 = F_6 ( V_9 ) ;
} while ( V_9 );
return V_25 ;
}
struct V_1 * F_7 ( struct V_1 * V_9 ,
struct V_26 * V_27 ,
void * V_12 , T_3 V_28 , T_3 V_13 ,
unsigned int V_25 ,
int (* V_11) ( struct V_1 * ,
void * , T_3 ) ,
int (* V_14) ( struct V_1 * ,
void * , T_3 ) )
{
struct V_6 * V_7 ;
char V_29 [ 20 ] ;
int V_10 ;
V_7 = F_8 ( sizeof( struct V_6 ) , V_30 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_9 = V_9 ;
V_7 -> V_27 = V_27 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_14 = V_14 ;
if ( V_9 -> V_22 -> V_31 )
V_7 -> V_22 . V_31 = F_1 ;
if ( V_9 -> V_22 -> V_23 )
V_7 -> V_22 . V_23 = F_3 ;
V_7 -> V_22 . V_24 = F_4 ;
snprintf ( V_7 -> V_2 . V_32 , sizeof( V_7 -> V_2 . V_32 ) ,
L_1 , F_9 ( V_9 ) , V_13 ) ;
V_7 -> V_2 . V_33 = V_34 ;
V_7 -> V_2 . V_22 = & V_7 -> V_22 ;
V_7 -> V_2 . V_8 = V_7 ;
V_7 -> V_2 . V_35 . V_9 = & V_9 -> V_35 ;
V_7 -> V_2 . V_36 = V_9 -> V_36 ;
V_7 -> V_2 . V_37 = V_9 -> V_37 ;
V_7 -> V_2 . V_38 = V_9 -> V_38 ;
if ( F_5 ( V_9 ) & V_25 )
F_10 ( & V_9 -> V_35 ,
L_2 ,
V_13 ) ;
else
V_7 -> V_2 . V_25 = V_25 ;
if ( V_27 -> V_39 ) {
struct V_40 * V_41 ;
T_3 V_42 ;
F_11 (mux_dev->of_node, child) {
V_10 = F_12 ( V_41 , L_3 , & V_42 ) ;
if ( V_10 )
continue;
if ( V_13 == V_42 ) {
V_7 -> V_2 . V_35 . V_39 = V_41 ;
break;
}
}
}
if ( F_13 ( V_27 ) )
F_14 ( & V_7 -> V_2 . V_35 , F_15 ( V_27 ) ,
V_13 ) ;
if ( V_28 ) {
V_7 -> V_2 . V_43 = V_28 ;
V_10 = F_16 ( & V_7 -> V_2 ) ;
} else {
V_10 = F_17 ( & V_7 -> V_2 ) ;
}
if ( V_10 < 0 ) {
F_10 ( & V_9 -> V_35 ,
L_4 ,
V_10 ) ;
F_18 ( V_7 ) ;
return NULL ;
}
F_19 ( F_20 ( & V_7 -> V_2 . V_35 . V_44 , & V_27 -> V_44 , L_5 ) ,
L_6 ) ;
snprintf ( V_29 , sizeof( V_29 ) , L_7 , V_13 ) ;
F_19 ( F_20 ( & V_27 -> V_44 , & V_7 -> V_2 . V_35 . V_44 , V_29 ) ,
L_8 , V_13 ) ;
F_21 ( & V_9 -> V_35 , L_9 ,
F_9 ( & V_7 -> V_2 ) ) ;
return & V_7 -> V_2 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
char V_29 [ 20 ] ;
snprintf ( V_29 , sizeof( V_29 ) , L_7 , V_7 -> V_13 ) ;
F_23 ( & V_7 -> V_27 -> V_44 , V_29 ) ;
F_23 ( & V_7 -> V_2 . V_35 . V_44 , L_5 ) ;
F_24 ( V_2 ) ;
F_18 ( V_7 ) ;
}
