static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_4 ;
union V_5 V_6 ;
int V_7 = 0 ;
F_2 ( L_1 ) ;
for ( V_7 = 0 ; V_7 < sizeof( V_8 ) ; V_7 ++ ) {
V_6 . V_9 = V_8 [ V_7 ] ;
if ( 0 != F_3 ( & V_3 -> V_10 , 0x6c , 0 , V_11 , V_7 , V_12 , & V_6 ) ) {
F_4 ( L_2 ,
V_7 ) ;
}
}
return 0 ;
}
static int F_5 ( struct V_3 * V_3 , int V_13 )
{
union V_5 V_6 ;
F_2 ( L_3 ) ;
V_6 . V_9 = V_14 [ V_13 ] . V_9 ;
if ( 0 != F_3 ( & V_3 -> V_10 , 0x6c , 0 , V_11 , V_14 [ V_13 ] . V_15 , V_12 , & V_6 ) ) {
return - 1 ;
}
return 0 ;
}
static int F_6 ( struct V_3 * V_3 , struct V_16 * V_17 )
{
union V_5 V_6 ;
int V_7 = 0 ;
F_2 ( L_3 ) ;
while ( V_17 [ V_7 ] . V_15 != - 1 ) {
V_6 . V_9 = V_17 [ V_7 ] . V_9 ;
if ( 0 != F_3 ( & V_3 -> V_10 , 0x6c , 0 , V_11 , V_17 [ V_7 ] . V_15 , V_12 , & V_6 ) ) {
F_4 ( L_4 ,
V_7 ) ;
return - 1 ;
}
V_7 ++ ;
}
return 0 ;
}
static int F_7 ( struct V_18 * V_18 , void * V_19 , struct V_20 * V_7 )
{
F_8 ( L_5 , V_7 -> V_21 ) ;
if ( V_7 -> V_21 >= V_22 )
return - V_23 ;
memcpy ( V_7 , & V_24 [ V_7 -> V_21 ] , sizeof( struct V_20 ) ) ;
F_2 ( L_6 , V_7 -> V_21 ) ;
return 0 ;
}
static int F_9 ( struct V_18 * V_18 , void * V_19 , unsigned int * V_13 )
{
struct V_1 * V_2 = ( (struct V_25 * ) V_19 ) -> V_2 ;
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_4 ;
* V_13 = V_3 -> V_26 ;
F_2 ( L_7 , * V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_18 * V_18 , void * V_19 , unsigned int V_13 )
{
struct V_1 * V_2 = ( (struct V_25 * ) V_19 ) -> V_2 ;
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_4 ;
F_8 ( L_8 , V_13 ) ;
if ( V_13 >= V_22 )
return - V_23 ;
V_3 -> V_26 = V_13 ;
F_5 ( V_3 , V_13 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_3 * V_3 ;
int V_29 ;
F_8 ( L_3 ) ;
V_3 = F_12 ( sizeof( struct V_3 ) , V_30 ) ;
if ( NULL == V_3 ) {
F_4 ( L_9 ) ;
return - V_31 ;
}
V_2 -> V_4 = V_3 ;
F_13 ( V_2 , V_32 , ( V_33 | V_34 | V_35 | V_36 ) ) ;
V_3 -> V_10 = (struct V_10 ) {
. V_37 = L_10 ,
} ;
F_14 ( V_2 , & V_3 -> V_10 , V_38 ) ;
if ( F_15 ( & V_3 -> V_10 ) < 0 ) {
F_16 ( L_11 ) ;
F_17 ( V_3 ) ;
return - V_39 ;
}
F_18 ( V_2 , 2 , V_40 ) ;
F_13 ( V_2 , V_41 , 0x07000700 ) ;
F_13 ( V_2 , V_42 , 0x00000000 ) ;
F_13 ( V_2 , V_43 , ( V_44 | V_45 | V_35 | V_36 ) ) ;
V_3 -> V_26 = 0 ;
F_1 ( V_2 ) ;
F_6 ( V_3 , V_46 ) ;
V_3 -> V_47 = V_48 ;
F_5 ( V_3 , 0 ) ;
V_3 -> V_26 = 0 ;
F_19 ( V_2 , & V_49 ) ;
V_49 . V_50 . F_7 = F_7 ;
V_49 . V_50 . F_9 = F_9 ;
V_49 . V_50 . F_10 = F_10 ;
V_29 = F_20 ( & V_3 -> V_51 , V_2 , L_10 , V_52 ) ;
if ( V_29 < 0 ) {
F_4 ( L_12 ) ;
return V_29 ;
}
F_21 ( L_13 , V_53 ) ;
V_53 ++ ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_4 ;
F_8 ( L_14 , V_2 ) ;
F_23 ( & V_3 -> V_51 , V_2 ) ;
F_24 ( V_2 ) ;
V_53 -- ;
F_25 ( & V_3 -> V_10 ) ;
F_17 ( V_3 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_4 ;
if ( V_48 == V_55 -> V_56 ) {
F_6 ( V_3 , V_46 ) ;
V_3 -> V_47 = V_48 ;
return 0 ;
} else if ( V_57 == V_55 -> V_56 ) {
F_6 ( V_3 , V_58 ) ;
V_3 -> V_47 = V_57 ;
return 0 ;
} else if ( V_59 == V_55 -> V_56 ) {
F_6 ( V_3 , V_60 ) ;
V_3 -> V_47 = V_59 ;
return 0 ;
}
return - 1 ;
}
static int T_1 F_27 ( void )
{
if ( 0 != F_28 ( & V_61 ) ) {
F_16 ( L_15 ) ;
return - V_62 ;
}
return 0 ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_61 ) ;
}
