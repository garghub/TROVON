static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = NULL ;
union V_4 V_5 ;
int V_6 = 0 ;
F_2 ( ( L_1 ) ) ;
if ( 0 == V_2 -> V_7 ) {
return - V_8 ;
}
V_3 = F_3 ( sizeof( struct V_3 ) , V_9 ) ;
if ( NULL == V_3 ) {
F_4 ( L_2 ) ;
return - V_10 ;
}
F_5 ( V_2 , V_11 , ( V_12 | V_13 | V_14 | V_15 ) ) ;
F_5 ( V_2 , V_16 , 0x01000100 ) ;
F_5 ( V_2 , V_17 , 0x00000000 ) ;
F_5 ( V_2 , V_18 , ( V_19 | V_20 | V_14 | V_15 ) ) ;
V_3 -> V_21 = (struct V_21 ) {
. V_22 = L_3 ,
} ;
F_6 ( V_2 , & V_3 -> V_21 , V_23 ) ;
if ( F_7 ( & V_3 -> V_21 ) < 0 ) {
F_8 ( ( L_4 ) ) ;
F_9 ( V_3 ) ;
return - V_8 ;
}
F_10 ( V_2 , 0 , V_24 ) ;
F_10 ( V_2 , 2 , V_24 ) ;
F_11 ( 10 ) ;
if ( 0x17c8 == V_2 -> V_25 -> V_26 && 0x0101 == V_2 -> V_25 -> V_27 ) {
F_4 ( L_5 ) ;
V_2 -> V_28 = V_3 ;
V_3 -> type = V_29 ;
return 0 ;
}
if ( 0x17c8 == V_2 -> V_25 -> V_26 && 0x2101 == V_2 -> V_25 -> V_27 ) {
F_4 ( L_6 ) ;
V_2 -> V_28 = V_3 ;
V_3 -> type = V_30 ;
return 0 ;
}
if ( 0 == ( V_6 = F_12 ( & V_3 -> V_21 , 0x4e , 0 , V_31 , 0x00 , V_32 , & V_5 ) ) ) {
F_4 ( L_7 ) ;
V_2 -> V_28 = V_3 ;
V_3 -> type = V_33 ;
return 0 ;
}
F_13 ( & V_3 -> V_21 ) ;
F_9 ( V_3 ) ;
return - V_8 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_28 ;
union V_4 V_5 ;
int V_34 = 0 ;
F_15 ( ( L_8 ) ) ;
for ( V_34 = 0 ; V_34 < sizeof( V_35 ) ; V_34 ++ ) {
V_5 . V_36 = V_35 [ V_34 ] ;
if ( 0 != F_12 ( & V_3 -> V_21 , 0x4e , 0 , V_37 , V_34 , V_32 , & V_5 ) ) {
F_4 ( L_9 , V_34 ) ;
}
}
return 0 ;
}
static int F_16 ( struct V_3 * V_3 , int V_38 )
{
union V_4 V_5 ;
int V_34 = 0 ;
F_15 ( ( L_1 ) ) ;
for ( V_34 = 0 ; V_34 < 8 ; V_34 ++ ) {
int V_39 = V_40 [ V_38 ] . V_5 [ V_34 ] . V_39 ;
V_5 . V_36 = V_40 [ V_38 ] . V_5 [ V_34 ] . V_36 ;
if ( 0 != F_12 ( & V_3 -> V_21 , 0x4e , 0 , V_37 , V_39 , V_32 , & V_5 ) ) {
return - 1 ;
}
F_4 ( L_10 , V_38 , V_39 , V_5 . V_36 ) ;
}
return 0 ;
}
static int F_17 ( struct V_41 * V_41 , void * V_42 , struct V_43 * V_34 )
{
F_2 ( ( L_11 , V_34 -> V_44 ) ) ;
if ( V_34 -> V_44 >= V_45 )
return - V_46 ;
memcpy ( V_34 , & V_47 [ V_34 -> V_44 ] , sizeof( struct V_43 ) ) ;
F_15 ( ( L_12 , V_34 -> V_44 ) ) ;
return 0 ;
}
static int F_18 ( struct V_41 * V_41 , void * V_42 , unsigned int * V_38 )
{
struct V_1 * V_2 = ( (struct V_48 * ) V_42 ) -> V_2 ;
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_28 ;
* V_38 = V_3 -> V_49 ;
F_15 ( ( L_13 , * V_38 ) ) ;
return 0 ;
}
static int F_19 ( struct V_41 * V_41 , void * V_42 , unsigned int V_38 )
{
struct V_1 * V_2 = ( (struct V_48 * ) V_42 ) -> V_2 ;
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_28 ;
if ( V_38 >= V_45 )
return - V_46 ;
V_3 -> V_49 = V_38 ;
F_16 ( V_3 , V_38 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_28 ;
F_2 ( ( L_1 ) ) ;
F_21 ( V_2 , & V_52 ) ;
V_52 . V_53 . F_17 = F_17 ;
V_52 . V_53 . F_18 = F_18 ;
V_52 . V_53 . F_19 = F_19 ;
if ( 0 != F_22 ( & V_3 -> V_54 , V_2 , L_3 , V_55 ) ) {
F_4 ( L_14 ) ;
return - 1 ;
}
F_4 ( L_15 , V_56 ) ;
V_56 ++ ;
V_3 -> V_49 = 0 ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_28 ;
F_2 ( ( L_16 , V_2 ) ) ;
F_24 ( & V_3 -> V_54 , V_2 ) ;
F_25 ( V_2 ) ;
V_56 -- ;
F_13 ( & V_3 -> V_21 ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
return 0 ;
}
static int T_1 F_27 ( void )
{
if ( 0 != F_28 ( & V_59 ) ) {
F_8 ( ( L_17 ) ) ;
return - V_60 ;
}
return 0 ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_59 ) ;
}
