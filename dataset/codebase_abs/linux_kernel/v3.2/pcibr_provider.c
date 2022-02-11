int
F_1 ( struct V_1 * V_2 , int V_3 , void * V_4 ,
char * * V_5 )
{
struct V_6 V_7 ;
T_1 V_8 ;
T_1 V_9 ;
V_7 . V_10 = 0 ;
V_7 . V_11 = 0 ;
V_9 = V_2 -> V_12 . V_13 ;
V_8 = V_2 -> V_12 . V_14 ;
F_2 ( V_7 , ( T_1 ) V_15 , V_9 ,
V_8 , ( T_1 ) V_3 , ( T_1 ) V_4 , ( T_1 ) F_3 ( V_5 ) ,
0 , 0 ) ;
return ( int ) V_7 . V_11 ;
}
int
F_4 ( struct V_1 * V_2 , int V_3 , int V_16 ,
void * V_4 )
{
struct V_6 V_7 ;
T_1 V_8 ;
T_1 V_9 ;
V_7 . V_10 = 0 ;
V_7 . V_11 = 0 ;
V_9 = V_2 -> V_12 . V_13 ;
V_8 = V_2 -> V_12 . V_14 ;
F_2 ( V_7 , ( T_1 ) V_17 ,
V_9 , V_8 , ( T_1 ) V_3 , ( T_1 ) V_16 ,
( T_1 ) V_4 , 0 , 0 ) ;
return ( int ) V_7 . V_11 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_6 V_7 ;
T_1 V_8 ;
int V_9 ;
V_7 . V_10 = 0 ;
V_7 . V_11 = 0 ;
V_9 = V_2 -> V_12 . V_13 ;
V_8 = V_2 -> V_12 . V_14 ;
F_2 ( V_7 ,
( T_1 ) V_18 ,
( T_1 ) V_9 , ( T_1 ) V_8 , 0 , 0 , 0 , 0 , 0 ) ;
return ( int ) V_7 . V_11 ;
}
T_2 F_6 ( struct V_19 * V_19 )
{
long V_20 ;
T_2 V_21 ( V_22 ) ;
T_3 V_23 = F_7 ( F_8 ( V_19 ) -> V_24 ) ;
V_20 = F_9 ( V_23 , & V_22 ) ;
if ( V_20 ) {
F_10 ( V_25 L_1 ,
V_20 ) ;
return 0 ;
}
return V_22 ;
}
static T_4
F_11 ( int V_26 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
if ( F_5 ( V_2 ) < 0 )
F_12 ( L_2 ) ;
return V_28 ;
}
void *
F_13 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
int V_23 , V_33 , V_34 ;
struct V_35 * V_35 ;
struct V_1 * V_2 ;
struct V_36 * V_36 ;
struct V_37 * V_38 ;
if ( ! F_14 ( V_30 -> V_39 ) ) {
return NULL ;
}
V_2 = F_15 ( sizeof( struct V_1 ) , V_40 ) ;
if ( ! V_2 ) {
return NULL ;
}
memcpy ( V_2 , V_30 , sizeof( struct V_1 ) ) ;
V_2 -> V_12 . V_24 = ( unsigned long )
F_16 ( F_17 ( V_2 -> V_12 . V_24 ) ,
sizeof( struct V_41 ) ) ;
F_18 ( & V_2 -> V_42 ) ;
if ( F_19 ( V_43 , F_11 ,
V_44 , L_3 , ( void * ) ( V_2 ) ) ) {
F_10 ( V_25
L_4 ) ;
}
F_20 ( V_43 ) ;
if ( V_45 < 16384 ) {
F_21 ( V_2 , V_46 ) ;
} else {
F_22 ( V_2 , V_46 ) ;
}
V_23 = F_7 ( V_2 -> V_12 . V_24 ) ;
V_33 = F_23 ( V_23 ) ;
V_35 = (struct V_35 * ) ( F_24 ( V_33 ) -> V_47 ) ;
if ( V_35 -> V_48 . V_49 ) {
V_36 = V_35 -> V_48 .
V_49 [ ( int ) V_2 -> V_12 . V_50 ] ;
if ( V_36 ) {
for ( V_34 = 0 ; V_34 < V_51 ;
V_34 ++ , V_36 ++ ) {
V_38 = V_36 -> V_38 ;
if ( V_38 -> V_52 == - 1 )
continue;
if ( ( V_38 -> V_53 ==
V_2 -> V_12 . V_13 ) &&
( V_38 -> V_54 ==
V_2 -> V_12 . V_14 ) )
V_38 -> V_55 =
V_2 ;
}
}
}
V_2 -> V_56 . V_57 = 0 ;
V_2 -> V_56 . V_58 =
F_25 ( V_2 -> V_59 * sizeof( T_1 ) , V_40 ) ;
if ( ! V_2 -> V_56 . V_58 ) {
F_26 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_27 ( struct V_60 * V_60 )
{
struct V_61 * V_61 ;
struct V_1 * V_1 ;
int V_62 = V_60 -> V_63 ;
if ( ! V_60 -> V_64 )
return;
V_61 = (struct V_61 * ) V_60 -> V_65 ;
if ( V_61 ) {
V_1 =
(struct V_1 * ) V_61 -> V_66 ->
V_67 ;
F_28 ( V_1 , V_62 ) ;
}
}
void F_29 ( struct V_60 * V_60 )
{
struct V_61 * V_61 ;
struct V_1 * V_1 ;
int V_62 = V_60 -> V_63 ;
T_1 V_68 = V_60 -> V_69 ;
V_61 = (struct V_61 * ) V_60 -> V_65 ;
if ( V_61 ) {
V_1 =
(struct V_1 * ) V_61 -> V_66 ->
V_67 ;
F_30 ( V_1 , ( 1 << V_62 ) ) ;
F_31 ( V_1 , V_62 , V_68 ) ;
F_32 ( V_1 , ( 1 << V_62 ) ) ;
F_27 ( V_60 ) ;
}
}
int
F_33 ( void )
{
V_70 [ V_71 ] = & V_72 ;
V_70 [ V_73 ] = & V_72 ;
return 0 ;
}
