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
static int F_11 ( struct V_18 * V_18 , void * V_19 , struct V_27 * V_28 )
{
struct V_1 * V_2 = ( (struct V_25 * ) V_19 ) -> V_2 ;
int V_7 ;
for ( V_7 = V_29 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_30 [ V_7 ] . V_31 == V_28 -> V_31 ) {
* V_28 = V_30 [ V_7 ] ;
F_2 ( L_9 , V_28 -> V_31 ) ;
return 0 ;
}
}
return V_2 -> V_32 -> V_33 -> F_11 ( V_18 , V_19 , V_28 ) ;
}
static int F_12 ( struct V_18 * V_18 , void * V_19 , struct V_34 * V_35 )
{
struct V_1 * V_2 = ( (struct V_25 * ) V_19 ) -> V_2 ;
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_4 ;
int V_7 ;
for ( V_7 = V_29 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_30 [ V_7 ] . V_31 == V_35 -> V_31 )
break;
}
if ( V_7 < 0 )
return V_2 -> V_32 -> V_33 -> F_12 ( V_18 , V_19 , V_35 ) ;
if ( V_35 -> V_31 == V_36 ) {
V_35 -> V_37 = V_3 -> V_38 ;
F_2 ( L_10 , V_35 -> V_37 ) ;
return 0 ;
}
return - V_23 ;
}
static int F_13 ( struct V_18 * V_18 , void * V_19 , struct V_34 * V_35 )
{
struct V_1 * V_2 = ( (struct V_25 * ) V_19 ) -> V_2 ;
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_4 ;
int V_7 = 0 ;
for ( V_7 = V_29 - 1 ; V_7 >= 0 ; V_7 -- ) {
if ( V_30 [ V_7 ] . V_31 == V_35 -> V_31 )
break;
}
if ( V_7 < 0 )
return V_2 -> V_32 -> V_33 -> F_13 ( V_18 , V_19 , V_35 ) ;
if ( V_35 -> V_31 == V_36 )
V_3 -> V_38 = V_35 -> V_37 ;
F_2 ( L_11 , V_3 -> V_38 ) ;
if ( 0 == V_3 -> V_38 && V_39 == V_3 -> V_40 ) {
F_6 ( V_3 , V_41 ) ;
return 0 ;
}
if ( 0 == V_3 -> V_38 && V_42 == V_3 -> V_40 ) {
F_6 ( V_3 , V_43 ) ;
return 0 ;
}
if ( 0 == V_3 -> V_38 && V_44 == V_3 -> V_40 ) {
F_6 ( V_3 , V_45 ) ;
return 0 ;
}
if ( 1 == V_3 -> V_38 && V_39 == V_3 -> V_40 ) {
F_6 ( V_3 , V_46 ) ;
return 0 ;
}
if ( 1 == V_3 -> V_38 && V_42 == V_3 -> V_40 ) {
F_6 ( V_3 , V_47 ) ;
return 0 ;
}
if ( 1 == V_3 -> V_38 && V_44 == V_3 -> V_40 )
return - V_23 ;
return - V_23 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_3 * V_3 ;
int V_50 ;
F_8 ( L_3 ) ;
V_3 = F_15 ( sizeof( struct V_3 ) , V_51 ) ;
if ( NULL == V_3 ) {
F_4 ( L_12 ) ;
return - V_52 ;
}
V_2 -> V_4 = V_3 ;
F_16 ( V_2 , V_53 , ( V_54 | V_55 | V_56 | V_57 ) ) ;
V_3 -> V_10 = (struct V_10 ) {
. V_58 = L_13 ,
} ;
F_17 ( V_2 , & V_3 -> V_10 , V_59 ) ;
if ( F_18 ( & V_3 -> V_10 ) < 0 ) {
F_19 ( L_14 ) ;
F_20 ( V_3 ) ;
return - V_60 ;
}
F_21 ( V_2 , 2 , V_61 ) ;
F_16 ( V_2 , V_62 , 0x07000700 ) ;
F_16 ( V_2 , V_63 , 0x00000000 ) ;
F_16 ( V_2 , V_64 , ( V_65 | V_66 | V_56 | V_57 ) ) ;
V_3 -> V_26 = 0 ;
F_1 ( V_2 ) ;
F_6 ( V_3 , V_41 ) ;
V_3 -> V_40 = V_39 ;
F_5 ( V_3 , 0 ) ;
V_3 -> V_26 = 0 ;
F_22 ( V_2 , & V_67 ) ;
V_67 . V_68 . F_11 = F_11 ;
V_67 . V_68 . F_12 = F_12 ;
V_67 . V_68 . F_13 = F_13 ;
V_67 . V_68 . F_7 = F_7 ;
V_67 . V_68 . F_9 = F_9 ;
V_67 . V_68 . F_10 = F_10 ;
V_50 = F_23 ( & V_3 -> V_69 , V_2 , L_13 , V_70 ) ;
if ( V_50 < 0 ) {
F_4 ( L_15 ) ;
return V_50 ;
}
F_24 ( L_16 , V_71 ) ;
V_71 ++ ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_4 ;
F_8 ( L_17 , V_2 ) ;
F_26 ( & V_3 -> V_69 , V_2 ) ;
F_27 ( V_2 ) ;
V_71 -- ;
F_28 ( & V_3 -> V_10 ) ;
F_20 ( V_3 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 -> V_4 ;
if ( V_39 == V_73 -> V_31 ) {
F_6 ( V_3 , V_41 ) ;
V_3 -> V_40 = V_39 ;
return 0 ;
} else if ( V_42 == V_73 -> V_31 ) {
F_6 ( V_3 , V_43 ) ;
V_3 -> V_40 = V_42 ;
return 0 ;
} else if ( V_44 == V_73 -> V_31 ) {
F_6 ( V_3 , V_45 ) ;
V_3 -> V_40 = V_44 ;
return 0 ;
}
return - 1 ;
}
static int T_1 F_30 ( void )
{
if ( 0 != F_31 ( & V_74 ) ) {
F_19 ( L_18 ) ;
return - V_75 ;
}
return 0 ;
}
static void T_2 F_32 ( void )
{
F_33 ( & V_74 ) ;
}
