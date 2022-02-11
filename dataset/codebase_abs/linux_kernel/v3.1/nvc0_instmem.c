int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = false ;
return 0 ;
}
void
F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = V_4 -> V_9 . V_10 . V_8 ;
F_3 ( V_2 , 0x100c80 , 0x00000001 , 0x00000000 ) ;
F_4 ( V_2 , 0x001704 , 0x80000000 | V_8 -> V_11 -> V_12 -> V_13 >> 12 ) ;
F_4 ( V_2 , 0x001714 , 0xc0000000 | V_8 -> V_14 -> V_12 -> V_13 >> 12 ) ;
V_4 -> V_6 = true ;
}
static void
F_5 ( struct V_15 * * V_16 )
{
struct V_15 * V_17 ;
V_17 = * V_16 ;
* V_16 = NULL ;
if ( ! V_17 )
return;
F_6 ( NULL , & V_17 -> V_18 , NULL ) ;
if ( F_7 ( & V_17 -> V_19 ) )
F_8 ( & V_17 -> V_19 ) ;
F_9 ( NULL , & V_17 -> V_12 ) ;
F_10 ( V_17 ) ;
}
static int
F_11 ( struct V_1 * V_2 , T_1 V_20 , struct V_21 * V_18 ,
struct V_15 * * V_16 ,
struct V_22 * V_23 , T_2 V_24 )
{
struct V_15 * V_17 ;
int V_25 ;
V_17 = F_12 ( sizeof( * V_17 ) , V_26 ) ;
if ( ! V_17 )
return - V_27 ;
V_17 -> V_2 = V_2 ;
V_25 = F_13 ( V_2 , NULL , V_20 , 0x1000 , 0 , & V_17 -> V_12 ) ;
if ( V_25 ) {
F_5 ( & V_17 ) ;
return V_25 ;
}
V_25 = F_14 ( & V_17 -> V_19 , 0x1000 , V_20 - 0x1000 ) ;
if ( V_25 ) {
F_5 ( & V_17 ) ;
return V_25 ;
}
V_25 = F_6 ( V_18 , & V_17 -> V_18 , NULL ) ;
if ( V_25 ) {
F_5 ( & V_17 ) ;
return V_25 ;
}
F_15 ( V_17 -> V_12 , 0x0200 , F_16 ( V_23 -> V_13 ) ) ;
F_15 ( V_17 -> V_12 , 0x0204 , F_17 ( V_23 -> V_13 ) ) ;
F_15 ( V_17 -> V_12 , 0x0208 , F_16 ( V_24 - 1 ) ) ;
F_15 ( V_17 -> V_12 , 0x020c , F_17 ( V_24 - 1 ) ) ;
* V_16 = V_17 ;
return 0 ;
}
int
F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_28 * V_29 = & V_4 -> V_9 . V_10 ;
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_7 * V_8 ;
struct V_21 * V_18 = NULL ;
int V_25 ;
V_8 = F_12 ( sizeof( * V_8 ) , V_26 ) ;
if ( ! V_8 )
return - V_27 ;
V_29 -> V_8 = V_8 ;
V_25 = F_19 ( V_2 , 0 , F_20 ( V_31 , 3 ) , 0 ,
& V_4 -> V_32 ) ;
if ( V_25 )
goto error;
V_25 = F_13 ( V_2 , NULL ,
( F_20 ( V_31 , 3 ) >> 12 ) * 8 , 0 ,
V_33 |
V_34 ,
& V_4 -> V_32 -> V_35 [ 0 ] . V_36 [ 0 ] ) ;
if ( V_25 )
goto error;
V_4 -> V_32 -> V_35 [ 0 ] . V_37 [ 0 ] = 1 ;
F_21 ( V_4 -> V_32 -> V_35 [ 0 ] . V_36 [ 0 ] ) ;
V_25 = F_13 ( V_2 , NULL , 0x8000 , 4096 ,
V_34 , & V_8 -> V_38 ) ;
if ( V_25 )
goto error;
V_25 = F_6 ( V_4 -> V_32 , & V_18 , V_8 -> V_38 ) ;
if ( V_25 )
goto error;
F_6 ( NULL , & V_18 , NULL ) ;
V_25 = F_11 ( V_2 , 8192 , V_4 -> V_32 , & V_8 -> V_14 ,
V_8 -> V_38 , F_20 ( V_2 -> V_31 , 3 ) ) ;
if ( V_25 )
goto error;
V_25 = F_19 ( V_2 , 0 , F_20 ( V_31 , 1 ) , 0 , & V_18 ) ;
if ( V_25 )
goto error;
V_25 = F_13 ( V_2 , NULL , 0x8000 , 4096 ,
V_34 , & V_8 -> V_39 ) ;
if ( V_25 )
goto error;
V_25 = F_6 ( V_18 , & V_4 -> V_40 , V_8 -> V_39 ) ;
if ( V_25 )
goto error;
F_6 ( NULL , & V_18 , NULL ) ;
V_25 = F_11 ( V_2 , 8192 , V_4 -> V_40 , & V_8 -> V_11 ,
V_8 -> V_39 , F_20 ( V_2 -> V_31 , 1 ) ) ;
if ( V_25 )
goto error;
V_25 = F_19 ( V_2 , 0 , ( 1ULL << 40 ) , 0x0008000000ULL ,
& V_4 -> V_41 ) ;
if ( V_25 )
goto error;
F_2 ( V_2 ) ;
return 0 ;
error:
F_22 ( V_2 ) ;
return V_25 ;
}
void
F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = V_4 -> V_9 . V_10 . V_8 ;
struct V_21 * V_18 = NULL ;
F_1 ( V_2 ) ;
F_4 ( V_2 , 0x1704 , 0x00000000 ) ;
F_4 ( V_2 , 0x1714 , 0x00000000 ) ;
F_6 ( NULL , & V_4 -> V_41 , NULL ) ;
F_5 ( & V_8 -> V_11 ) ;
F_6 ( NULL , & V_4 -> V_40 , V_8 -> V_39 ) ;
F_9 ( NULL , & V_8 -> V_39 ) ;
F_5 ( & V_8 -> V_14 ) ;
F_6 ( V_4 -> V_32 , & V_18 , NULL ) ;
F_6 ( NULL , & V_18 , V_8 -> V_38 ) ;
F_9 ( NULL , & V_8 -> V_38 ) ;
F_9 ( NULL , & V_4 -> V_32 -> V_35 [ 0 ] . V_36 [ 0 ] ) ;
F_6 ( NULL , & V_4 -> V_32 , NULL ) ;
V_4 -> V_9 . V_10 . V_8 = NULL ;
F_10 ( V_8 ) ;
}
