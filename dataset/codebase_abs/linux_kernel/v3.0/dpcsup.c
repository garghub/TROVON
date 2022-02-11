unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_9 ;
int V_10 = 0 ;
unsigned long V_11 , V_12 ;
F_2 ( V_2 -> V_13 , V_11 ) ;
while( F_3 ( V_4 , V_2 , & V_6 ) )
{
int V_14 ;
T_1 V_15 = F_4 ( V_6 -> V_16 ) ;
V_14 = V_15 & 0x01 ;
V_9 = & V_4 -> V_17 [ V_15 >> 2 ] ;
V_8 = V_9 -> V_18 ;
F_5 ( V_4 , V_2 , V_19 ) ;
V_4 -> V_20 -> V_21 [ V_22 ] . V_23 -- ;
if ( F_6 ( V_9 -> V_11 & V_24 ) ) {
F_7 ( V_2 -> V_13 , V_11 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 ) ;
F_2 ( V_2 -> V_13 , V_11 ) ;
continue;
}
F_7 ( V_2 -> V_13 , V_11 ) ;
if ( V_14 ) {
* ( V_25 * ) V_8 -> V_26 = F_10 ( V_27 ) ;
V_8 -> V_28 . V_29 |= F_10 ( V_30 ) ;
}
F_11 ( V_31 . V_32 ) ;
if ( V_8 -> V_28 . V_33 == F_12 ( V_34 ) )
{
V_25 * V_35 = ( V_25 * ) V_8 -> V_26 ;
if ( * V_35 & F_10 ( 0xffff0000 ) )
* V_35 = F_10 ( V_27 ) ;
}
if ( V_8 -> V_28 . V_29 & F_10 ( V_36 | V_37 ) )
{
if ( V_8 -> V_28 . V_29 & F_10 ( V_36 ) )
F_11 ( V_31 . V_38 ) ;
else
F_11 ( V_31 . V_39 ) ;
V_9 -> V_11 = 0 ;
V_9 -> V_40 ( V_9 -> V_41 , V_9 ) ;
} else {
unsigned long V_42 ;
F_2 ( & V_9 -> V_43 , V_42 ) ;
if ( ! V_9 -> V_44 ) {
V_9 -> V_44 = 1 ;
F_13 ( & V_9 -> V_45 ) ;
}
F_7 ( & V_9 -> V_43 , V_42 ) ;
F_2 ( & V_4 -> V_46 , V_12 ) ;
V_4 -> V_47 -- ;
F_7 ( & V_4 -> V_46 , V_12 ) ;
F_11 ( V_31 . V_48 ) ;
if ( V_9 -> V_44 == 2 ) {
F_2 ( & V_9 -> V_43 , V_42 ) ;
V_9 -> V_44 = 0 ;
F_7 ( & V_9 -> V_43 , V_42 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 ) ;
}
}
V_10 ++ ;
F_2 ( V_2 -> V_13 , V_11 ) ;
}
if ( V_10 > V_31 . V_49 )
V_31 . V_49 = V_10 ;
if ( V_10 == 0 )
V_31 . V_50 ++ ;
F_7 ( V_2 -> V_13 , V_11 ) ;
return 0 ;
}
unsigned int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
unsigned long V_11 ;
F_2 ( V_2 -> V_13 , V_11 ) ;
while( F_3 ( V_4 , V_2 , & V_6 ) )
{
struct V_9 V_51 ;
struct V_7 * V_7 ;
T_1 V_15 ;
struct V_9 * V_9 = & V_51 ;
V_15 = F_4 ( V_6 -> V_16 ) / sizeof( struct V_7 ) ;
V_7 = & V_4 -> V_52 [ V_15 ] ;
if ( V_4 -> V_53 )
if( ( V_9 = F_15 ( sizeof( struct V_9 ) , V_54 ) ) == NULL )
V_9 = & V_51 ;
memset ( V_9 , 0 , sizeof( struct V_9 ) ) ;
F_16 ( & V_9 -> V_55 ) ;
V_9 -> type = V_56 ;
V_9 -> V_57 = sizeof( struct V_9 ) ;
V_9 -> V_18 = V_7 ;
V_9 -> V_26 = V_7 -> V_26 ;
V_9 -> V_4 = V_4 ;
if ( V_4 -> V_53 && V_9 != & V_51 ) {
F_17 ( & V_9 -> V_55 , & V_2 -> V_58 ) ;
F_5 ( V_4 , V_2 , V_59 ) ;
F_18 ( & V_2 -> V_60 ) ;
} else {
F_5 ( V_4 , V_2 , V_59 ) ;
F_7 ( V_2 -> V_13 , V_11 ) ;
* ( V_25 * ) V_7 -> V_26 = F_10 ( V_27 ) ;
F_19 ( V_9 , sizeof( T_1 ) ) ;
F_2 ( V_2 -> V_13 , V_11 ) ;
}
}
F_7 ( V_2 -> V_13 , V_11 ) ;
return 0 ;
}
static void F_20 ( void * V_61 , struct V_9 * V_62 )
{
struct V_9 * V_51 ;
struct V_3 * V_4 ;
struct V_63 * V_64 ;
int V_65 ;
V_51 = (struct V_9 * ) V_61 ;
F_21 ( V_62 == NULL ) ;
V_4 = V_62 -> V_4 ;
if ( V_62 -> V_18 -> V_28 . V_29 &
F_10 ( V_66 ) ) {
F_8 ( V_62 ) ;
F_9 ( V_62 ) ;
return;
}
F_22 ( V_4 , 0 , 1 , 0 , V_62 -> V_18 ) ;
F_23 ( V_51 ) ;
V_64 = (struct V_63 * ) F_24 ( V_51 ) ;
V_64 -> V_67 = F_10 ( V_68 ) ;
V_65 = F_25 ( V_69 ,
V_51 ,
sizeof( struct V_7 ) - sizeof( struct V_70 ) ,
V_71 ,
0 , 1 ,
( V_72 ) F_20 , V_51 ) ;
}
unsigned int F_22 ( struct V_3 * V_4 , T_1 V_15 ,
int V_73 , int V_74 , struct V_7 * V_75 )
{
unsigned long V_12 ;
F_26 ( ( V_76 L_1 , V_4 , V_15 ) ) ;
if ( V_73 == 1 ) {
struct V_7 * V_7 ;
struct V_9 * V_9 ;
struct V_1 * V_2 = & V_4 -> V_20 -> V_21 [ V_59 ] ;
unsigned long V_11 ;
if ( ( ! V_4 -> V_53 )
|| ( ! ( V_9 = F_27 ( sizeof( struct V_9 ) , V_54 ) ) ) )
return 1 ;
if ( ! ( V_7 = F_27 ( sizeof( struct V_7 ) , V_54 ) ) ) {
F_28 ( V_9 ) ;
return 1 ;
}
if ( V_75 != NULL ) {
memcpy ( V_7 , V_75 , sizeof( struct V_7 ) ) ;
} else {
memcpy ( V_7 ,
(struct V_7 * ) ( ( ( V_77 ) ( V_4 -> V_78 . V_79 ) ) +
V_15 ) , sizeof( struct V_7 ) ) ;
}
F_16 ( & V_9 -> V_55 ) ;
V_9 -> type = V_56 ;
V_9 -> V_57 = sizeof( struct V_9 ) ;
V_9 -> V_18 = V_7 ;
V_9 -> V_26 = V_7 -> V_26 ;
V_9 -> V_4 = V_4 ;
F_2 ( V_2 -> V_13 , V_11 ) ;
F_17 ( & V_9 -> V_55 , & V_2 -> V_58 ) ;
F_18 ( & V_2 -> V_60 ) ;
F_7 ( V_2 -> V_13 , V_11 ) ;
return 1 ;
} else if ( V_73 == 2 ) {
struct V_9 * V_51 ;
struct V_63 * V_64 ;
V_51 = F_29 ( V_4 ) ;
if ( ! V_51 )
return 1 ;
F_23 ( V_51 ) ;
V_64 = (struct V_63 * ) F_24 ( V_51 ) ;
V_64 -> V_67 = F_10 ( V_68 ) ;
return F_25 ( V_69 ,
V_51 ,
sizeof( struct V_7 ) - sizeof( struct V_70 ) ,
V_71 ,
0 , 1 ,
( V_72 ) F_20 , V_51 ) ;
} else {
struct V_9 * V_9 = & V_4 -> V_17 [ V_15 ] ;
struct V_7 * V_8 = V_9 -> V_18 ;
V_4 -> V_20 -> V_21 [ V_22 ] . V_23 -- ;
if ( F_6 ( V_9 -> V_11 & V_24 ) ) {
F_8 ( V_9 ) ;
F_9 ( V_9 ) ;
return 0 ;
}
if ( V_74 ) {
* ( V_25 * ) V_8 -> V_26 = F_10 ( V_27 ) ;
V_8 -> V_28 . V_29 |= F_10 ( V_30 ) ;
}
F_11 ( V_31 . V_32 ) ;
if ( V_8 -> V_28 . V_33 == F_12 ( V_34 ) )
{
V_25 * V_35 = ( V_25 * ) V_8 -> V_26 ;
if ( * V_35 & F_10 ( 0xffff0000 ) )
* V_35 = F_10 ( V_27 ) ;
}
if ( V_8 -> V_28 . V_29 & F_10 ( V_36 | V_37 ) )
{
if ( V_8 -> V_28 . V_29 & F_10 ( V_36 ) )
F_11 ( V_31 . V_38 ) ;
else
F_11 ( V_31 . V_39 ) ;
V_9 -> V_11 = 0 ;
V_9 -> V_40 ( V_9 -> V_41 , V_9 ) ;
} else {
unsigned long V_42 ;
F_26 ( ( V_76 L_2 ) ) ;
F_2 ( & V_9 -> V_43 , V_42 ) ;
if ( ! V_9 -> V_44 ) {
V_9 -> V_44 = 1 ;
F_13 ( & V_9 -> V_45 ) ;
}
F_7 ( & V_9 -> V_43 , V_42 ) ;
F_2 ( & V_4 -> V_46 , V_12 ) ;
V_4 -> V_47 -- ;
F_7 ( & V_4 -> V_46 , V_12 ) ;
F_11 ( V_31 . V_48 ) ;
if ( V_9 -> V_44 == 2 ) {
F_2 ( & V_9 -> V_43 , V_42 ) ;
V_9 -> V_44 = 0 ;
F_7 ( & V_9 -> V_43 , V_42 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 ) ;
}
}
return 0 ;
}
}
