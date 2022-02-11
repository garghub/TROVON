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
F_6 ( & V_4 -> V_20 -> V_21 [ V_22 ] . V_23 ) ;
if ( F_7 ( V_9 -> V_11 & V_24 ) ) {
F_8 ( V_2 -> V_13 , V_11 ) ;
F_9 ( V_9 ) ;
F_10 ( V_9 ) ;
F_2 ( V_2 -> V_13 , V_11 ) ;
continue;
}
F_8 ( V_2 -> V_13 , V_11 ) ;
if ( V_14 ) {
* ( V_25 * ) V_8 -> V_26 = F_11 ( V_27 ) ;
V_8 -> V_28 . V_29 |= F_11 ( V_30 ) ;
V_9 -> V_11 |= V_31 ;
}
F_12 ( V_32 . V_33 ) ;
if ( V_8 -> V_28 . V_34 == F_13 ( V_35 ) )
{
V_25 * V_36 = ( V_25 * ) V_8 -> V_26 ;
if ( * V_36 & F_11 ( 0xffff0000 ) )
* V_36 = F_11 ( V_27 ) ;
}
if ( V_8 -> V_28 . V_29 & F_11 ( V_37 | V_38 ) )
{
if ( V_8 -> V_28 . V_29 & F_11 ( V_37 ) )
F_12 ( V_32 . V_39 ) ;
else
F_12 ( V_32 . V_40 ) ;
V_9 -> V_11 &= V_31 ;
V_9 -> V_41 ( V_9 -> V_42 , V_9 ) ;
} else {
unsigned long V_43 ;
F_2 ( & V_9 -> V_44 , V_43 ) ;
if ( ! V_9 -> V_45 ) {
V_9 -> V_45 = 1 ;
F_14 ( & V_9 -> V_46 ) ;
}
F_8 ( & V_9 -> V_44 , V_43 ) ;
F_2 ( & V_4 -> V_47 , V_12 ) ;
V_4 -> V_48 -- ;
F_8 ( & V_4 -> V_47 , V_12 ) ;
F_12 ( V_32 . V_49 ) ;
if ( V_9 -> V_45 == 2 ) {
F_2 ( & V_9 -> V_44 , V_43 ) ;
V_9 -> V_45 = 0 ;
F_8 ( & V_9 -> V_44 , V_43 ) ;
F_9 ( V_9 ) ;
F_10 ( V_9 ) ;
}
}
V_10 ++ ;
F_2 ( V_2 -> V_13 , V_11 ) ;
}
if ( V_10 > V_32 . V_50 )
V_32 . V_50 = V_10 ;
if ( V_10 == 0 )
V_32 . V_51 ++ ;
F_8 ( V_2 -> V_13 , V_11 ) ;
return 0 ;
}
unsigned int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
unsigned long V_11 ;
F_2 ( V_2 -> V_13 , V_11 ) ;
while( F_3 ( V_4 , V_2 , & V_6 ) )
{
struct V_9 V_52 ;
struct V_7 * V_7 ;
T_1 V_15 ;
struct V_9 * V_9 = & V_52 ;
V_15 = F_4 ( V_6 -> V_16 ) / sizeof( struct V_7 ) ;
V_7 = & V_4 -> V_53 [ V_15 ] ;
if ( V_4 -> V_54 )
if( ( V_9 = F_16 ( sizeof( struct V_9 ) , V_55 ) ) == NULL )
V_9 = & V_52 ;
memset ( V_9 , 0 , sizeof( struct V_9 ) ) ;
F_17 ( & V_9 -> V_56 ) ;
V_9 -> type = V_57 ;
V_9 -> V_58 = sizeof( struct V_9 ) ;
V_9 -> V_18 = V_7 ;
V_9 -> V_26 = V_7 -> V_26 ;
V_9 -> V_4 = V_4 ;
if ( V_4 -> V_54 && V_9 != & V_52 ) {
F_18 ( & V_9 -> V_56 , & V_2 -> V_59 ) ;
F_5 ( V_4 , V_2 , V_60 ) ;
F_19 ( & V_2 -> V_61 ) ;
} else {
F_5 ( V_4 , V_2 , V_60 ) ;
F_8 ( V_2 -> V_13 , V_11 ) ;
* ( V_25 * ) V_7 -> V_26 = F_11 ( V_27 ) ;
F_20 ( V_9 , sizeof( T_1 ) ) ;
F_2 ( V_2 -> V_13 , V_11 ) ;
}
}
F_8 ( V_2 -> V_13 , V_11 ) ;
return 0 ;
}
static void F_21 ( void * V_62 , struct V_9 * V_63 )
{
struct V_9 * V_52 ;
struct V_3 * V_4 ;
struct V_64 * V_65 ;
int V_66 ;
V_52 = (struct V_9 * ) V_62 ;
F_22 ( V_63 == NULL ) ;
V_4 = V_63 -> V_4 ;
if ( V_63 -> V_18 -> V_28 . V_29 &
F_11 ( V_67 ) ) {
F_9 ( V_63 ) ;
F_10 ( V_63 ) ;
return;
}
F_23 ( V_4 , 0 , 1 , 0 , V_63 -> V_18 ) ;
F_24 ( V_52 ) ;
V_65 = (struct V_64 * ) F_25 ( V_52 ) ;
V_65 -> V_68 = F_11 ( V_69 ) ;
V_66 = F_26 ( V_70 ,
V_52 ,
sizeof( struct V_7 ) - sizeof( struct V_71 ) ,
V_72 ,
0 , 1 ,
( V_73 ) F_21 , V_52 ) ;
}
unsigned int F_23 ( struct V_3 * V_4 , T_1 V_15 ,
int V_74 , int V_75 , struct V_7 * V_76 )
{
unsigned long V_12 ;
F_27 ( ( V_77 L_1 , V_4 , V_15 ) ) ;
if ( V_74 == 1 ) {
struct V_7 * V_7 ;
struct V_9 * V_9 ;
struct V_1 * V_2 = & V_4 -> V_20 -> V_21 [ V_60 ] ;
unsigned long V_11 ;
if ( ( ! V_4 -> V_54 )
|| ( ! ( V_9 = F_28 ( sizeof( struct V_9 ) , V_55 ) ) ) )
return 1 ;
if ( ! ( V_7 = F_28 ( sizeof( struct V_7 ) , V_55 ) ) ) {
F_29 ( V_9 ) ;
return 1 ;
}
if ( V_76 != NULL ) {
memcpy ( V_7 , V_76 , sizeof( struct V_7 ) ) ;
} else {
memcpy ( V_7 ,
(struct V_7 * ) ( ( ( V_78 ) ( V_4 -> V_79 . V_80 ) ) +
V_15 ) , sizeof( struct V_7 ) ) ;
}
F_17 ( & V_9 -> V_56 ) ;
V_9 -> type = V_57 ;
V_9 -> V_58 = sizeof( struct V_9 ) ;
V_9 -> V_18 = V_7 ;
V_9 -> V_26 = V_7 -> V_26 ;
V_9 -> V_4 = V_4 ;
F_2 ( V_2 -> V_13 , V_11 ) ;
F_18 ( & V_9 -> V_56 , & V_2 -> V_59 ) ;
F_19 ( & V_2 -> V_61 ) ;
F_8 ( V_2 -> V_13 , V_11 ) ;
return 1 ;
} else if ( V_74 == 2 ) {
struct V_9 * V_52 ;
struct V_64 * V_65 ;
V_52 = F_30 ( V_4 ) ;
if ( ! V_52 )
return 1 ;
F_24 ( V_52 ) ;
V_65 = (struct V_64 * ) F_25 ( V_52 ) ;
V_65 -> V_68 = F_11 ( V_69 ) ;
return F_26 ( V_70 ,
V_52 ,
sizeof( struct V_7 ) - sizeof( struct V_71 ) ,
V_72 ,
0 , 1 ,
( V_73 ) F_21 , V_52 ) ;
} else {
struct V_9 * V_9 = & V_4 -> V_17 [ V_15 ] ;
struct V_7 * V_8 = V_9 -> V_18 ;
F_6 ( & V_4 -> V_20 -> V_21 [ V_22 ] . V_23 ) ;
if ( F_7 ( V_9 -> V_11 & V_24 ) ) {
F_9 ( V_9 ) ;
F_10 ( V_9 ) ;
return 0 ;
}
if ( V_75 ) {
* ( V_25 * ) V_8 -> V_26 = F_11 ( V_27 ) ;
V_8 -> V_28 . V_29 |= F_11 ( V_30 ) ;
V_9 -> V_11 |= V_31 ;
}
F_12 ( V_32 . V_33 ) ;
if ( V_8 -> V_28 . V_34 == F_13 ( V_35 ) )
{
V_25 * V_36 = ( V_25 * ) V_8 -> V_26 ;
if ( * V_36 & F_11 ( 0xffff0000 ) )
* V_36 = F_11 ( V_27 ) ;
}
if ( V_8 -> V_28 . V_29 & F_11 ( V_37 | V_38 ) )
{
if ( V_8 -> V_28 . V_29 & F_11 ( V_37 ) )
F_12 ( V_32 . V_39 ) ;
else
F_12 ( V_32 . V_40 ) ;
if ( F_31 ( V_9 -> V_41 && V_9 -> V_42 ) ) {
V_9 -> V_11 &= V_31 ;
V_9 -> V_41 ( V_9 -> V_42 , V_9 ) ;
} else
F_32 ( & V_4 -> V_81 -> V_4 ,
L_2 ,
V_15 , V_9 -> V_41 , V_9 -> V_42 ) ;
} else {
unsigned long V_43 ;
F_27 ( ( V_77 L_3 ) ) ;
F_2 ( & V_9 -> V_44 , V_43 ) ;
if ( ! V_9 -> V_45 ) {
V_9 -> V_45 = 1 ;
F_14 ( & V_9 -> V_46 ) ;
}
F_8 ( & V_9 -> V_44 , V_43 ) ;
F_2 ( & V_4 -> V_47 , V_12 ) ;
V_4 -> V_48 -- ;
F_8 ( & V_4 -> V_47 , V_12 ) ;
F_12 ( V_32 . V_49 ) ;
if ( V_9 -> V_45 == 2 ) {
F_2 ( & V_9 -> V_44 , V_43 ) ;
V_9 -> V_45 = 0 ;
F_8 ( & V_9 -> V_44 , V_43 ) ;
F_9 ( V_9 ) ;
}
}
return 0 ;
}
}
