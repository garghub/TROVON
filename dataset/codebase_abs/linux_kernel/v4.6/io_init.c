static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
struct V_3 V_4 ;
V_4 . V_5 = 0 ;
V_4 . V_6 = 0 ;
F_2 ( V_4 ,
( T_1 ) V_7 ,
( T_1 ) V_1 , ( T_1 ) V_2 , 0 , 0 , 0 , 0 , 0 ) ;
return V_4 . V_6 ;
}
static inline T_1 F_3 ( T_1 V_8 , T_1 V_9 , T_1 V_2 )
{
struct V_3 V_4 ;
V_4 . V_5 = 0 ;
V_4 . V_6 = 0 ;
F_2 ( V_4 ,
( T_1 ) V_10 ,
( T_1 ) V_8 , ( T_1 ) V_9 , ( T_1 ) V_2 , 0 , 0 , 0 , 0 ) ;
return V_4 . V_6 ;
}
static inline T_1
F_4 ( T_1 V_8 , T_1 V_11 , T_1 V_12 , T_1 V_13 ,
T_1 V_14 )
{
struct V_3 V_4 ;
V_4 . V_5 = 0 ;
V_4 . V_6 = 0 ;
F_2 ( V_4 ,
( T_1 ) V_15 ,
( T_1 ) V_8 , ( T_1 ) V_11 , ( T_1 ) V_12 ,
( T_1 ) V_13 ,
V_14 , 0 , 0 ) ;
return V_4 . V_6 ;
}
static void T_2 F_5 ( void )
{
struct V_16 * V_17 ;
T_1 V_5 ;
T_1 V_18 ;
int V_19 ;
extern void V_20 ( struct V_16 * ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
V_17 = (struct V_16 * ) ( F_6 ( V_19 ) -> V_22 ) ;
V_18 = F_7 ( V_19 ) ;
V_17 -> V_23 = 0xffffffff ;
V_17 -> V_24 = 0xff ;
V_5 = F_1 ( V_18 , ( T_1 ) F_8 ( V_17 ) ) ;
if ( V_5 )
continue;
if ( V_17 -> V_23 ) {
V_23 = V_17 -> V_23 ;
V_24 = V_17 -> V_24 ;
}
V_20 ( V_17 ) ;
}
}
static void
F_9 ( struct V_25 * V_26 ,
T_1 V_27 , T_1 V_28 )
{
V_26 [ 0 ] . V_29 = L_1 ;
V_26 [ 0 ] . V_30 = V_31 ;
V_26 [ 0 ] . V_32 = V_27 ;
V_26 [ 0 ] . V_33 = V_26 [ 0 ] . V_32 + 0xffff ;
V_26 [ 0 ] . V_34 = & V_35 ;
V_26 [ 1 ] . V_29 = L_2 ;
V_26 [ 1 ] . V_30 = V_36 ;
V_26 [ 1 ] . V_32 = V_28 ;
V_26 [ 1 ] . V_33 = V_26 [ 1 ] . V_32 + ( 1024 * 1024 ) - 1 ;
V_26 [ 1 ] . V_34 = & V_37 ;
}
void
F_10 ( struct V_13 * V_38 )
{
int V_39 ;
struct V_25 * V_26 ;
unsigned long V_40 , V_41 ;
struct V_42 * V_42 ;
struct V_14 * V_14 ;
int V_5 ;
V_42 = F_11 ( sizeof( struct V_42 ) , V_43 ) ;
if ( ! V_42 )
F_12 ( L_3 , V_44 ) ;
V_14 = F_11 ( sizeof( struct V_14 ) , V_43 ) ;
if ( ! V_14 )
F_12 ( L_4 , V_44 ) ;
V_5 = F_4 ( ( T_1 ) F_13 ( V_38 ) ,
( T_1 ) V_38 -> V_45 -> V_46 ,
V_38 -> V_12 ,
( T_1 ) F_8 ( V_42 ) ,
( T_1 ) F_8 ( V_14 ) ) ;
F_14 ( V_5 ) ;
for ( V_39 = 0 ; V_39 <= V_47 ; V_39 ++ ) {
if ( ! V_42 -> V_48 [ V_39 ] )
continue;
V_26 = & V_38 -> V_25 [ V_39 ] ;
V_41 = V_26 -> V_33 - V_26 -> V_32 ;
if ( V_41 == 0 )
continue;
V_26 -> V_32 = V_42 -> V_48 [ V_39 ] ;
V_26 -> V_33 = V_40 + V_41 ;
if ( V_26 -> V_34 && V_26 -> V_34 -> V_49 )
F_15 ( V_26 ) ;
if ( V_26 -> V_30 & V_31 )
F_16 ( & V_35 , V_26 ) ;
else
F_16 ( & V_37 , V_26 ) ;
if ( V_39 == V_47 ) {
F_17 ( V_38 ) ;
V_26 -> V_30 = V_36 | V_50 |
V_51 ;
}
}
F_18 ( V_38 , V_42 , V_14 ) ;
}
static void T_2
F_19 ( int V_8 , int V_9 , struct V_52 * V_45 )
{
T_3 V_5 = 0 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_25 * V_26 ;
F_20 ( V_57 ) ;
V_5 = F_3 ( ( T_1 ) V_8 , ( T_1 ) V_9 ,
( T_1 ) F_21 ( & V_56 ) ) ;
if ( V_5 > 0 )
return;
V_56 = F_22 ( V_56 ) ;
V_54 = F_11 ( sizeof( * V_54 ) , V_43 ) ;
F_14 ( ! V_54 ) ;
V_54 -> V_8 = V_8 ;
V_26 = F_23 ( 2 , sizeof( struct V_25 ) , V_43 ) ;
F_14 ( ! V_26 ) ;
V_54 -> V_58 = V_56 ;
F_9 ( V_26 ,
V_56 -> V_59 ,
V_56 -> V_60 ) ;
F_24 ( & V_57 , & V_26 [ 0 ] ,
V_56 -> V_59 ) ;
F_24 ( & V_57 , & V_26 [ 1 ] ,
V_56 -> V_60 ) ;
V_45 = F_25 ( NULL , V_9 , & V_61 , V_54 ,
& V_57 ) ;
if ( V_45 == NULL ) {
F_26 ( V_26 ) ;
F_26 ( V_54 ) ;
return;
}
F_27 ( V_45 ) ;
}
void
F_28 ( struct V_52 * V_45 )
{
struct V_13 * V_13 = NULL ;
struct V_55 * V_56 ;
if ( ! V_45 -> V_34 ) {
V_56 = F_29 ( V_45 ) -> V_58 ;
if ( V_56 == NULL ) {
F_30 ( V_62
L_5
L_6 ,
F_13 ( V_45 ) , V_45 -> V_46 ) ;
return;
}
F_31 ( V_45 , V_56 ) ;
}
F_32 (pci_dev, &bus->devices, bus_list) {
F_10 ( V_13 ) ;
}
}
void T_2 F_33 ( void )
{
int V_19 , V_63 ;
F_5 () ;
for ( V_19 = 0 ; V_19 <= V_23 ; V_19 ++ )
for ( V_63 = 0 ; V_63 <= V_24 ; V_63 ++ )
F_19 ( V_19 , V_63 , NULL ) ;
}
