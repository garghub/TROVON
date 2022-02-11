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
V_26 -> V_29 = F_10 ( 2 , sizeof( struct V_30 ) ,
V_31 ) ;
F_11 ( V_26 -> V_29 == NULL ) ;
V_26 -> V_29 [ 0 ] . V_32 = V_27 ;
V_26 -> V_29 [ 0 ] . V_33 . V_34 = L_1 ;
V_26 -> V_29 [ 0 ] . V_33 . V_35 = V_36 ;
V_26 -> V_29 [ 0 ] . V_33 . V_37 = V_27 ;
V_26 -> V_29 [ 0 ] . V_33 . V_38 =
V_26 -> V_29 [ 0 ] . V_33 . V_37 + 0xffff ;
V_26 -> V_29 [ 0 ] . V_33 . V_39 = & V_40 ;
V_26 -> V_29 [ 1 ] . V_32 = V_28 ;
V_26 -> V_29 [ 1 ] . V_33 . V_34 = L_2 ;
V_26 -> V_29 [ 1 ] . V_33 . V_35 = V_41 ;
V_26 -> V_29 [ 1 ] . V_33 . V_37 = V_28 ;
V_26 -> V_29 [ 1 ] . V_33 . V_38 =
V_26 -> V_29 [ 1 ] . V_33 . V_37 + ( 1024 * 1024 ) - 1 ;
V_26 -> V_29 [ 1 ] . V_33 . V_39 = & V_42 ;
V_26 -> V_43 = 2 ;
}
static void
F_12 ( struct V_13 * V_44 , unsigned int V_45 ,
T_3 * V_46 )
{
struct V_25 * V_26 = F_13 ( V_44 -> V_47 ) ;
unsigned int V_19 ;
unsigned int V_48 ;
unsigned int V_49 ;
struct V_30 * V_50 ;
if ( V_45 == 0 )
return;
V_48 = V_26 -> V_43 ;
V_49 = V_26 -> V_43 + V_45 ;
V_50 = F_10 ( V_49 , sizeof( struct V_30 ) , V_31 ) ;
F_11 ( V_50 == NULL ) ;
if ( V_26 -> V_29 ) {
memcpy ( V_50 , V_26 -> V_29 ,
sizeof( struct V_30 ) * V_26 -> V_43 ) ;
F_14 ( V_26 -> V_29 ) ;
}
for ( V_19 = 0 ; V_19 <= V_51 ; V_19 ++ ) {
if ( V_46 [ V_19 ] == - 1 )
continue;
V_50 [ V_48 ] . V_32 = V_44 -> V_33 [ V_19 ] . V_37 - V_46 [ V_19 ] ;
V_50 [ V_48 ] . V_33 = V_44 -> V_33 [ V_19 ] ;
V_48 ++ ;
}
V_26 -> V_43 = V_49 ;
V_26 -> V_29 = V_50 ;
}
void
F_15 ( struct V_13 * V_44 )
{
unsigned int V_45 = 0 ;
int V_48 ;
T_3 V_46 [ V_51 + 1 ] ;
unsigned long V_52 , V_38 , V_53 , V_37 ;
struct V_54 * V_54 ;
struct V_14 * V_14 ;
int V_5 ;
V_54 = F_16 ( sizeof( struct V_54 ) , V_31 ) ;
if ( ! V_54 )
F_17 ( L_3 , V_55 ) ;
V_14 = F_16 ( sizeof( struct V_14 ) , V_31 ) ;
if ( ! V_14 )
F_17 ( L_4 , V_55 ) ;
V_5 = F_4 ( ( T_1 ) F_18 ( V_44 ) ,
( T_1 ) V_44 -> V_47 -> V_56 ,
V_44 -> V_12 ,
( T_1 ) F_8 ( V_54 ) ,
( T_1 ) F_8 ( V_14 ) ) ;
F_11 ( V_5 ) ;
for ( V_48 = 0 ; V_48 <= V_51 ; V_48 ++ ) {
if ( ! V_54 -> V_57 [ V_48 ] ) {
V_46 [ V_48 ] = - 1 ;
continue;
}
V_37 = V_44 -> V_33 [ V_48 ] . V_37 ;
V_38 = V_44 -> V_33 [ V_48 ] . V_38 ;
V_53 = V_38 - V_37 ;
if ( V_53 == 0 ) {
V_46 [ V_48 ] = - 1 ;
continue;
}
V_46 [ V_48 ] = V_37 ;
V_45 ++ ;
V_52 = V_54 -> V_57 [ V_48 ] ;
V_52 = ( ( V_52 << 4 ) >> 4 ) | V_58 ;
V_44 -> V_33 [ V_48 ] . V_37 = V_52 ;
V_44 -> V_33 [ V_48 ] . V_38 = V_52 + V_53 ;
if ( V_44 -> V_33 [ V_48 ] . V_39 && V_44 -> V_33 [ V_48 ] . V_39 -> V_59 )
F_19 ( & V_44 -> V_33 [ V_48 ] ) ;
if ( V_44 -> V_33 [ V_48 ] . V_35 & V_36 )
F_20 ( & V_40 , & V_44 -> V_33 [ V_48 ] ) ;
else
F_20 ( & V_42 , & V_44 -> V_33 [ V_48 ] ) ;
if ( V_48 == V_51 ) {
T_4 V_60 ;
void T_5 * V_61 ;
V_61 = F_21 ( F_22 ( V_44 , V_51 ) ,
V_53 + 1 ) ;
V_60 = F_23 ( V_44 , V_61 , V_53 + 1 ) ;
V_44 -> V_33 [ V_51 ] . V_38 =
V_44 -> V_33 [ V_51 ] . V_37 +
V_60 - 1 ;
V_44 -> V_33 [ V_51 ] . V_35 |=
V_62 ;
}
}
if ( V_45 > 0 )
F_12 ( V_44 , V_45 , V_46 ) ;
F_24 ( V_44 , V_54 , V_14 ) ;
}
static void T_2
F_25 ( int V_8 , int V_9 , struct V_63 * V_47 )
{
T_3 V_5 = 0 ;
struct V_25 * V_26 ;
struct V_64 * V_65 ;
V_5 = F_3 ( ( T_1 ) V_8 , ( T_1 ) V_9 ,
( T_1 ) F_26 ( & V_65 ) ) ;
if ( V_5 > 0 )
return;
V_65 = F_27 ( V_65 ) ;
V_26 = F_16 ( sizeof( * V_26 ) , V_31 ) ;
F_11 ( ! V_26 ) ;
V_26 -> V_8 = V_8 ;
V_26 -> V_66 = V_65 ;
V_47 = F_28 ( V_9 , & V_67 , V_26 ) ;
if ( V_47 == NULL )
goto V_68;
V_47 -> V_69 = V_26 ;
return;
V_68:
F_14 ( V_26 ) ;
return;
}
void
F_29 ( struct V_63 * V_47 )
{
struct V_13 * V_13 = NULL ;
struct V_64 * V_65 ;
if ( ! V_47 -> V_39 ) {
V_65 = F_13 ( V_47 ) -> V_66 ;
if ( V_65 == NULL ) {
F_30 ( V_70
L_5
L_6 ,
F_18 ( V_47 ) , V_47 -> V_56 ) ;
return;
}
F_31 ( V_47 , V_65 ) ;
F_9 ( F_13 ( V_47 ) ,
V_65 -> V_71 ,
V_65 -> V_72 ) ;
}
F_32 (pci_dev, &bus->devices, bus_list) {
F_15 ( V_13 ) ;
}
}
void T_2 F_33 ( void )
{
int V_19 , V_73 ;
F_5 () ;
for ( V_19 = 0 ; V_19 <= V_23 ; V_19 ++ )
for ( V_73 = 0 ; V_73 <= V_24 ; V_73 ++ )
F_25 ( V_19 , V_73 , NULL ) ;
}
