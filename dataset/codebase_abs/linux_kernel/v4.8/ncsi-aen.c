static int F_1 ( struct V_1 * V_2 ,
const unsigned short V_3 )
{
T_1 V_4 ;
T_2 * V_5 ;
if ( V_2 -> V_6 . V_7 != V_8 )
return - V_9 ;
if ( F_2 ( V_2 -> V_6 . V_10 ) != V_3 )
return - V_9 ;
V_5 = ( T_2 * ) ( ( void * ) ( V_2 + 1 ) + V_3 - 4 ) ;
if ( F_3 ( * V_5 ) == 0 )
return 0 ;
V_4 = F_4 ( ( unsigned char * ) V_2 ,
sizeof( * V_2 ) + V_3 - 4 ) ;
if ( * V_5 != F_5 ( V_4 ) )
return - V_9 ;
return 0 ;
}
static int F_6 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
unsigned long V_19 ;
unsigned long V_20 ;
F_7 ( V_12 , V_2 -> V_6 . V_21 , NULL , & V_16 ) ;
if ( ! V_16 )
return - V_22 ;
V_18 = & V_16 -> V_23 [ V_24 ] ;
V_14 = (struct V_13 * ) V_2 ;
V_19 = V_18 -> V_25 [ 2 ] ;
V_18 -> V_25 [ 2 ] = F_3 ( V_14 -> V_26 ) ;
V_18 -> V_25 [ 4 ] = F_3 ( V_14 -> V_27 ) ;
if ( ! ( ( V_19 ^ V_18 -> V_25 [ 2 ] ) & 0x1 ) ||
! F_8 ( & V_16 -> V_28 ) )
return 0 ;
if ( ! ( V_16 -> V_29 == V_30 && ( V_18 -> V_25 [ 2 ] & 0x1 ) ) &&
! ( V_16 -> V_29 == V_31 && ! ( V_18 -> V_25 [ 2 ] & 0x1 ) ) )
return 0 ;
if ( ! ( V_12 -> V_20 & V_32 ) &&
V_16 -> V_29 == V_31 )
V_12 -> V_20 |= V_33 ;
F_9 ( V_16 ) ;
F_10 ( & V_12 -> V_34 , V_20 ) ;
F_11 ( & V_16 -> V_28 , & V_12 -> V_35 ) ;
F_12 ( & V_12 -> V_34 , V_20 ) ;
return F_13 ( V_12 ) ;
}
static int F_14 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 ;
unsigned long V_20 ;
F_7 ( V_12 , V_2 -> V_6 . V_21 , NULL , & V_16 ) ;
if ( ! V_16 )
return - V_22 ;
if ( ! F_8 ( & V_16 -> V_28 ) ||
V_16 -> V_29 != V_31 )
return 0 ;
F_9 ( V_16 ) ;
F_10 ( & V_12 -> V_34 , V_20 ) ;
F_15 ( & V_16 -> V_29 , V_30 ) ;
F_11 ( & V_16 -> V_28 , & V_12 -> V_35 ) ;
F_12 ( & V_12 -> V_34 , V_20 ) ;
return F_13 ( V_12 ) ;
}
static int F_16 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_36 * V_37 ;
unsigned long V_20 ;
F_7 ( V_12 , V_2 -> V_6 . V_21 , NULL , & V_16 ) ;
if ( ! V_16 )
return - V_22 ;
V_18 = & V_16 -> V_23 [ V_24 ] ;
V_37 = (struct V_36 * ) V_2 ;
V_18 -> V_25 [ 3 ] = F_3 ( V_37 -> V_26 ) ;
if ( ! F_8 ( & V_16 -> V_28 ) ||
V_16 -> V_29 != V_31 ||
( V_18 -> V_25 [ 3 ] & 0x1 ) )
return 0 ;
if ( V_12 -> V_20 & V_32 )
V_12 -> V_20 |= V_33 ;
F_9 ( V_16 ) ;
F_10 ( & V_12 -> V_34 , V_20 ) ;
F_11 ( & V_16 -> V_28 , & V_12 -> V_35 ) ;
F_12 ( & V_12 -> V_34 , V_20 ) ;
F_13 ( V_12 ) ;
return 0 ;
}
int F_17 ( struct V_11 * V_12 , struct V_38 * V_39 )
{
struct V_1 * V_2 ;
struct F_17 * V_40 = NULL ;
int V_41 , V_42 ;
V_2 = (struct V_1 * ) F_18 ( V_39 ) ;
for ( V_41 = 0 ; V_41 < F_19 ( V_43 ) ; V_41 ++ ) {
if ( V_43 [ V_41 ] . type == V_2 -> type ) {
V_40 = & V_43 [ V_41 ] ;
break;
}
}
if ( ! V_40 ) {
F_20 ( V_12 -> V_44 . V_45 , L_1 ,
V_2 -> type ) ;
return - V_46 ;
}
V_42 = F_1 ( V_2 , V_40 -> V_3 ) ;
if ( V_42 )
goto V_47;
V_42 = V_40 -> V_48 ( V_12 , V_2 ) ;
V_47:
F_21 ( V_39 ) ;
return V_42 ;
}
