static int F_1 ( struct V_1 * V_2 ,
struct V_3 V_4 [] , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_1 * V_9 = V_7 -> V_9 ;
int V_10 ;
V_10 = V_7 -> V_11 ( V_9 , V_7 -> V_12 , V_7 -> V_13 ) ;
if ( V_10 >= 0 )
V_10 = V_9 -> V_14 -> V_15 ( V_9 , V_4 , V_5 ) ;
if ( V_7 -> V_16 )
V_7 -> V_16 ( V_9 , V_7 -> V_12 , V_7 -> V_13 ) ;
return V_10 ;
}
static int F_2 ( struct V_1 * V_2 ,
T_1 V_17 , unsigned short V_18 ,
char V_19 , T_2 V_20 ,
int V_21 , union V_22 * V_23 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_1 * V_9 = V_7 -> V_9 ;
int V_10 ;
V_10 = V_7 -> V_11 ( V_9 , V_7 -> V_12 , V_7 -> V_13 ) ;
if ( V_10 >= 0 )
V_10 = V_9 -> V_14 -> V_24 ( V_9 , V_17 , V_18 ,
V_19 , V_20 , V_21 , V_23 ) ;
if ( V_7 -> V_16 )
V_7 -> V_16 ( V_9 , V_7 -> V_12 , V_7 -> V_13 ) ;
return V_10 ;
}
static T_3 F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_1 * V_9 = V_7 -> V_9 ;
return V_9 -> V_14 -> V_25 ( V_9 ) ;
}
static unsigned int F_4 ( struct V_1 * V_9 )
{
unsigned int V_26 = 0 ;
do {
V_26 |= V_9 -> V_26 ;
V_9 = F_5 ( V_9 ) ;
} while ( V_9 );
return V_26 ;
}
struct V_1 * F_6 ( struct V_1 * V_9 ,
struct V_27 * V_28 ,
void * V_12 , T_3 V_29 , T_3 V_13 ,
unsigned int V_26 ,
int (* V_11) ( struct V_1 * ,
void * , T_3 ) ,
int (* V_16) ( struct V_1 * ,
void * , T_3 ) )
{
struct V_6 * V_7 ;
int V_10 ;
V_7 = F_7 ( sizeof( struct V_6 ) , V_30 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_9 = V_9 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_16 = V_16 ;
if ( V_9 -> V_14 -> V_15 )
V_7 -> V_14 . V_15 = F_1 ;
if ( V_9 -> V_14 -> V_24 )
V_7 -> V_14 . V_24 = F_2 ;
V_7 -> V_14 . V_25 = F_3 ;
snprintf ( V_7 -> V_2 . V_31 , sizeof( V_7 -> V_2 . V_31 ) ,
L_1 , F_8 ( V_9 ) , V_13 ) ;
V_7 -> V_2 . V_32 = V_33 ;
V_7 -> V_2 . V_14 = & V_7 -> V_14 ;
V_7 -> V_2 . V_8 = V_7 ;
V_7 -> V_2 . V_34 . V_9 = & V_9 -> V_34 ;
V_7 -> V_2 . V_35 = V_9 -> V_35 ;
V_7 -> V_2 . V_36 = V_9 -> V_36 ;
if ( F_4 ( V_9 ) & V_26 )
F_9 ( & V_9 -> V_34 ,
L_2 ,
V_13 ) ;
else
V_7 -> V_2 . V_26 = V_26 ;
if ( V_28 -> V_37 ) {
struct V_38 * V_39 ;
T_3 V_40 ;
F_10 (mux_dev->of_node, child) {
V_10 = F_11 ( V_39 , L_3 , & V_40 ) ;
if ( V_10 )
continue;
if ( V_13 == V_40 ) {
V_7 -> V_2 . V_34 . V_37 = V_39 ;
break;
}
}
}
if ( V_29 ) {
V_7 -> V_2 . V_41 = V_29 ;
V_10 = F_12 ( & V_7 -> V_2 ) ;
} else {
V_10 = F_13 ( & V_7 -> V_2 ) ;
}
if ( V_10 < 0 ) {
F_9 ( & V_9 -> V_34 ,
L_4 ,
V_10 ) ;
F_14 ( V_7 ) ;
return NULL ;
}
F_15 ( & V_9 -> V_34 , L_5 ,
F_8 ( & V_7 -> V_2 ) ) ;
return & V_7 -> V_2 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_17 ( V_2 ) ;
F_14 ( V_7 ) ;
}
