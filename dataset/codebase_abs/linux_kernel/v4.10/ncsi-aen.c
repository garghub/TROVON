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
bool V_19 ;
int V_20 ;
unsigned long V_21 , V_22 ;
unsigned long V_23 ;
F_7 ( V_12 , V_2 -> V_6 . V_24 , NULL , & V_16 ) ;
if ( ! V_16 )
return - V_25 ;
V_14 = (struct V_13 * ) V_2 ;
F_8 ( & V_16 -> V_26 , V_23 ) ;
V_18 = & V_16 -> V_27 [ V_28 ] ;
V_21 = V_18 -> V_22 [ 2 ] ;
V_22 = F_3 ( V_14 -> V_29 ) ;
V_18 -> V_22 [ 2 ] = V_22 ;
V_18 -> V_22 [ 4 ] = F_3 ( V_14 -> V_30 ) ;
V_19 = ! F_9 ( & V_16 -> V_31 ) ;
V_20 = V_16 -> V_20 ;
F_10 ( & V_16 -> V_26 , V_23 ) ;
if ( ! ( ( V_21 ^ V_22 ) & 0x1 ) || V_19 )
return 0 ;
if ( ! ( V_20 == V_32 && ( V_22 & 0x1 ) ) &&
! ( V_20 == V_33 && ! ( V_22 & 0x1 ) ) )
return 0 ;
if ( ! ( V_12 -> V_23 & V_34 ) &&
V_20 == V_33 )
V_12 -> V_23 |= V_35 ;
F_11 ( V_16 ) ;
F_8 ( & V_12 -> V_26 , V_23 ) ;
F_12 ( & V_16 -> V_31 , & V_12 -> V_36 ) ;
F_10 ( & V_12 -> V_26 , V_23 ) ;
return F_13 ( V_12 ) ;
}
static int F_14 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 ;
unsigned long V_23 ;
F_7 ( V_12 , V_2 -> V_6 . V_24 , NULL , & V_16 ) ;
if ( ! V_16 )
return - V_25 ;
F_8 ( & V_16 -> V_26 , V_23 ) ;
if ( ! F_9 ( & V_16 -> V_31 ) ||
V_16 -> V_20 != V_33 ) {
F_10 ( & V_16 -> V_26 , V_23 ) ;
return 0 ;
}
F_10 ( & V_16 -> V_26 , V_23 ) ;
F_11 ( V_16 ) ;
F_8 ( & V_16 -> V_26 , V_23 ) ;
V_16 -> V_20 = V_37 ;
F_10 ( & V_16 -> V_26 , V_23 ) ;
F_8 ( & V_12 -> V_26 , V_23 ) ;
V_16 -> V_20 = V_32 ;
F_12 ( & V_16 -> V_31 , & V_12 -> V_36 ) ;
F_10 ( & V_12 -> V_26 , V_23 ) ;
return F_13 ( V_12 ) ;
}
static int F_15 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_38 * V_39 ;
unsigned long V_23 ;
F_7 ( V_12 , V_2 -> V_6 . V_24 , NULL , & V_16 ) ;
if ( ! V_16 )
return - V_25 ;
F_8 ( & V_16 -> V_26 , V_23 ) ;
V_18 = & V_16 -> V_27 [ V_28 ] ;
V_39 = (struct V_38 * ) V_2 ;
V_18 -> V_22 [ 3 ] = F_3 ( V_39 -> V_29 ) ;
if ( ! F_9 ( & V_16 -> V_31 ) ||
V_16 -> V_20 != V_33 ) {
F_10 ( & V_16 -> V_26 , V_23 ) ;
return 0 ;
}
F_10 ( & V_16 -> V_26 , V_23 ) ;
if ( ! ( V_12 -> V_23 & V_34 ) && ! ( V_18 -> V_22 [ 3 ] & 0x1 ) )
V_12 -> V_23 |= V_35 ;
F_11 ( V_16 ) ;
F_8 ( & V_16 -> V_26 , V_23 ) ;
V_16 -> V_20 = ( V_18 -> V_22 [ 3 ] & 0x1 ) ? V_32 :
V_33 ;
F_10 ( & V_16 -> V_26 , V_23 ) ;
F_8 ( & V_12 -> V_26 , V_23 ) ;
F_12 ( & V_16 -> V_31 , & V_12 -> V_36 ) ;
F_10 ( & V_12 -> V_26 , V_23 ) ;
F_13 ( V_12 ) ;
return 0 ;
}
int F_16 ( struct V_11 * V_12 , struct V_40 * V_41 )
{
struct V_1 * V_2 ;
struct F_16 * V_42 = NULL ;
int V_43 , V_44 ;
V_2 = (struct V_1 * ) F_17 ( V_41 ) ;
for ( V_43 = 0 ; V_43 < F_18 ( V_45 ) ; V_43 ++ ) {
if ( V_45 [ V_43 ] . type == V_2 -> type ) {
V_42 = & V_45 [ V_43 ] ;
break;
}
}
if ( ! V_42 ) {
F_19 ( V_12 -> V_46 . V_47 , L_1 ,
V_2 -> type ) ;
return - V_48 ;
}
V_44 = F_1 ( V_2 , V_42 -> V_3 ) ;
if ( V_44 )
goto V_49;
V_44 = V_42 -> V_50 ( V_12 , V_2 ) ;
V_49:
F_20 ( V_41 ) ;
return V_44 ;
}
