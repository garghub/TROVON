static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = ( void * ) V_2 ;
int V_10 ;
V_10 = F_2 ( V_9 -> V_11 , V_4 -> V_12 << 12 , 12 , V_5 , V_7 ) ;
if ( V_10 )
return V_10 ;
F_3 ( V_7 , V_4 ) ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = ( void * ) V_2 ;
int V_10 ;
V_10 = F_2 ( V_9 -> V_13 , V_4 -> V_12 << 12 , 12 , V_5 , V_7 ) ;
if ( V_10 )
return V_10 ;
F_3 ( V_7 , V_4 ) ;
return 0 ;
}
static void
F_5 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_6 ( V_7 ) ;
F_7 ( V_7 ) ;
}
static void
F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = ( void * ) V_2 ;
unsigned long V_5 ;
F_9 ( & V_9 -> V_14 , V_5 ) ;
F_10 ( V_9 , 0x00330c , 0x00000001 ) ;
if ( ! F_11 ( V_9 , 0x00330c , 0x00000002 , 0x00000000 ) )
F_12 ( V_9 , L_1 ) ;
F_13 ( & V_9 -> V_14 , V_5 ) ;
}
void
F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = ( void * ) V_2 ;
unsigned long V_5 ;
F_9 ( & V_9 -> V_14 , V_5 ) ;
F_10 ( V_2 , 0x070000 , 0x00000001 ) ;
if ( ! F_11 ( V_9 , 0x070000 , 0x00000002 , 0x00000000 ) )
F_12 ( V_9 , L_1 ) ;
F_13 ( & V_9 -> V_14 , V_5 ) ;
}
static int
F_15 ( struct V_15 * V_16 , struct V_15 * V_17 ,
struct V_18 * V_19 , void * V_20 , T_1 V_12 ,
struct V_15 * * V_21 )
{
struct V_22 * V_23 = F_16 ( V_16 ) ;
struct V_15 * V_24 ;
struct V_25 * V_26 ;
struct V_8 * V_9 ;
T_2 V_27 , V_28 ;
int V_10 ;
V_10 = F_17 ( V_16 , V_17 , V_19 , & V_9 ) ;
* V_21 = F_18 ( V_9 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_19 ( F_18 ( V_9 ) , NULL , 0x20000 , 0 ,
V_29 , & V_9 -> V_4 ) ;
V_24 = F_18 ( V_9 -> V_4 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_19 ( F_18 ( V_9 ) , V_24 ,
( V_23 -> V_30 == 0x50 ) ? 0x1400 : 0x0200 ,
0 , 0 , & V_9 -> V_31 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_19 ( F_18 ( V_9 ) , V_24 , 0x4000 , 0 , 0 , & V_9 -> V_32 ) ;
if ( V_10 )
return V_10 ;
V_27 = 0x0100000000ULL ;
V_28 = V_27 + F_20 ( V_23 , 3 ) ;
V_10 = F_21 ( V_23 , V_27 , V_28 , V_27 , & V_26 ) ;
if ( V_10 )
return V_10 ;
F_22 ( & V_26 -> V_33 [ V_34 ] ) ;
V_10 = F_19 ( F_18 ( V_9 ) , V_24 ,
( ( V_28 -- - V_27 ) >> 12 ) * 8 , 0x1000 ,
V_35 , & V_26 -> V_36 [ 0 ] . V_37 [ 0 ] ) ;
V_26 -> V_36 [ 0 ] . V_38 [ 0 ] = 1 ;
if ( V_10 )
return V_10 ;
V_10 = F_23 ( V_26 , & V_9 -> V_11 , V_9 -> V_32 ) ;
F_23 ( NULL , & V_26 , NULL ) ;
if ( V_10 )
return V_10 ;
V_10 = F_19 ( F_18 ( V_9 ) , V_24 , 24 , 16 , 0 , & V_9 -> V_39 ) ;
if ( V_10 )
return V_10 ;
F_24 ( V_9 -> V_39 , 0x00 , 0x7fc00000 ) ;
F_24 ( V_9 -> V_39 , 0x04 , F_25 ( V_28 ) ) ;
F_24 ( V_9 -> V_39 , 0x08 , F_25 ( V_27 ) ) ;
F_24 ( V_9 -> V_39 , 0x0c , F_26 ( V_28 ) << 24 |
F_26 ( V_27 ) ) ;
F_24 ( V_9 -> V_39 , 0x10 , 0x00000000 ) ;
F_24 ( V_9 -> V_39 , 0x14 , 0x00000000 ) ;
V_27 = 0x0000000000ULL ;
V_28 = V_27 + F_20 ( V_23 , 1 ) ;
V_10 = F_21 ( V_23 , V_27 , V_28 -- , V_27 , & V_26 ) ;
if ( V_10 )
return V_10 ;
F_22 ( & V_26 -> V_33 [ V_34 ] ) ;
V_10 = F_23 ( V_26 , & V_9 -> V_13 , V_9 -> V_32 ) ;
F_23 ( NULL , & V_26 , NULL ) ;
if ( V_10 )
return V_10 ;
V_10 = F_19 ( F_18 ( V_9 ) , V_24 , 24 , 16 , 0 , & V_9 -> V_40 ) ;
if ( V_10 )
return V_10 ;
F_24 ( V_9 -> V_40 , 0x00 , 0x7fc00000 ) ;
F_24 ( V_9 -> V_40 , 0x04 , F_25 ( V_28 ) ) ;
F_24 ( V_9 -> V_40 , 0x08 , F_25 ( V_27 ) ) ;
F_24 ( V_9 -> V_40 , 0x0c , F_26 ( V_28 ) << 24 |
F_26 ( V_27 ) ) ;
F_24 ( V_9 -> V_40 , 0x10 , 0x00000000 ) ;
F_24 ( V_9 -> V_40 , 0x14 , 0x00000000 ) ;
V_9 -> V_41 . V_42 = V_43 ;
V_9 -> V_41 . V_44 = F_1 ;
V_9 -> V_41 . V_45 = F_4 ;
V_9 -> V_41 . V_46 = F_5 ;
if ( V_23 -> V_30 == 0x50 )
V_9 -> V_41 . V_47 = F_8 ;
else
V_9 -> V_41 . V_47 = F_14 ;
F_27 ( & V_9 -> V_14 ) ;
return 0 ;
}
static void
F_28 ( struct V_15 * V_48 )
{
struct V_8 * V_9 = ( void * ) V_48 ;
F_29 ( NULL , & V_9 -> V_40 ) ;
F_23 ( NULL , & V_9 -> V_13 , V_9 -> V_32 ) ;
F_29 ( NULL , & V_9 -> V_39 ) ;
if ( V_9 -> V_11 ) {
F_29 ( NULL , & V_9 -> V_11 -> V_36 [ 0 ] . V_37 [ 0 ] ) ;
F_23 ( NULL , & V_9 -> V_11 , V_9 -> V_32 ) ;
}
F_29 ( NULL , & V_9 -> V_32 ) ;
F_29 ( NULL , & V_9 -> V_31 ) ;
F_29 ( NULL , & V_9 -> V_4 ) ;
F_30 ( & V_9 -> V_41 ) ;
}
static int
F_31 ( struct V_15 * V_48 )
{
struct V_8 * V_9 = ( void * ) V_48 ;
int V_10 , V_49 ;
V_10 = F_32 ( & V_9 -> V_41 ) ;
if ( V_10 )
return V_10 ;
F_33 ( V_9 , 0x000200 , 0x00000100 , 0x00000000 ) ;
F_33 ( V_9 , 0x000200 , 0x00000100 , 0x00000100 ) ;
F_10 ( V_9 , 0x100c80 , 0x00060001 ) ;
if ( ! F_11 ( V_9 , 0x100c80 , 0x00000001 , 0x00000000 ) ) {
F_34 ( V_9 , L_2 ) ;
return - V_50 ;
}
F_10 ( V_9 , 0x001704 , 0x00000000 | V_9 -> V_4 -> V_51 >> 12 ) ;
F_10 ( V_9 , 0x001704 , 0x40000000 | V_9 -> V_4 -> V_51 >> 12 ) ;
F_10 ( V_9 , 0x001708 , 0x80000000 | V_9 -> V_40 -> V_52 -> V_53 >> 4 ) ;
F_10 ( V_9 , 0x00170c , 0x80000000 | V_9 -> V_39 -> V_52 -> V_53 >> 4 ) ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ )
F_10 ( V_9 , 0x001900 + ( V_49 * 4 ) , 0x00000000 ) ;
return 0 ;
}
static int
F_35 ( struct V_15 * V_48 , bool V_54 )
{
struct V_8 * V_9 = ( void * ) V_48 ;
return F_36 ( & V_9 -> V_41 , V_54 ) ;
}
