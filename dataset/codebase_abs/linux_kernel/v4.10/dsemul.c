static int F_1 ( void )
{
T_1 * V_1 = & V_2 -> V_3 -> V_4 ;
int V_5 ;
V_6:
F_2 ( & V_1 -> V_7 ) ;
if ( ! V_1 -> V_8 ) {
V_1 -> V_8 =
F_3 ( F_4 ( V_9 ) ,
sizeof( unsigned long ) ,
V_10 ) ;
if ( ! V_1 -> V_8 ) {
V_5 = V_11 ;
goto V_12;
}
}
V_5 = F_5 ( V_1 -> V_8 ,
V_9 , 0 ) ;
if ( V_5 < 0 ) {
F_6 ( & V_1 -> V_7 ) ;
if ( ! F_7 ( V_1 -> V_13 ,
! F_8 ( V_1 -> V_8 ,
V_9 ) ) )
goto V_6;
return V_11 ;
}
F_9 ( L_1 , V_5 , V_2 -> V_14 ) ;
V_12:
F_6 ( & V_1 -> V_7 ) ;
return V_5 ;
}
static void F_10 ( int V_5 , struct V_15 * V_3 )
{
T_1 * V_1 = & V_3 -> V_4 ;
F_2 ( & V_1 -> V_7 ) ;
F_9 ( L_2 , V_5 , V_2 -> V_14 ) ;
F_11 ( V_1 -> V_8 , V_5 , 1 ) ;
F_12 ( & V_1 -> V_13 ) ;
F_6 ( & V_1 -> V_7 ) ;
}
static bool F_13 ( struct V_16 * V_17 )
{
unsigned long V_18 = ( unsigned long ) F_14 () ;
if ( V_17 -> V_19 < V_18 )
return false ;
if ( V_17 -> V_19 >= ( V_18 + V_20 ) )
return false ;
return true ;
}
bool F_15 ( struct V_21 * V_22 )
{
int V_23 ;
V_23 = F_16 ( & V_22 -> V_24 . V_25 , V_11 ) ;
if ( V_23 == V_11 )
return false ;
F_17 ( V_22 ) ;
if ( V_22 -> V_3 )
F_10 ( V_23 , V_22 -> V_3 ) ;
F_18 ( V_22 ) ;
return true ;
}
bool F_19 ( struct V_16 * V_17 )
{
struct V_26 T_2 * V_27 ;
int V_23 ;
if ( ! F_13 ( V_17 ) )
return false ;
V_23 = F_20 ( & V_2 -> V_24 . V_25 ) ;
if ( V_23 == V_11 )
return false ;
V_27 = & F_14 () [ V_23 ] ;
if ( F_21 ( V_17 -> V_19 ) == ( unsigned long ) & V_27 -> V_28 )
V_17 -> V_19 = V_2 -> V_24 . V_29 ;
else if ( F_21 ( V_17 -> V_19 ) == ( unsigned long ) & V_27 -> V_30 )
V_17 -> V_19 = V_2 -> V_24 . V_31 ;
F_22 ( & V_2 -> V_24 . V_25 , V_11 ) ;
F_10 ( V_23 , V_2 -> V_3 ) ;
return true ;
}
void F_23 ( struct V_15 * V_3 )
{
T_1 * V_1 = & V_3 -> V_4 ;
F_24 ( V_1 -> V_8 ) ;
}
int F_25 ( struct V_16 * V_17 , T_3 V_32 ,
unsigned long V_33 , unsigned long V_34 )
{
int V_35 = F_26 ( V_17 -> V_19 ) ;
T_3 V_36 ;
struct V_26 T_2 * V_27 ;
int V_37 , V_23 ;
if ( V_32 == 0 )
return - 1 ;
if ( V_35 ) {
union T_3 V_38 = { . V_39 = V_32 } ;
if ( ( V_32 >> 16 ) == V_40 )
return - 1 ;
if ( V_38 . V_41 . V_42 == V_43 ) {
unsigned int V_44 ;
T_4 V_45 ;
V_44 = ( ( ( V_38 . V_41 . V_44 + 0xe ) & 0xf ) + 2 ) ;
V_45 = V_17 -> V_19 & ~ 3 ;
V_45 += V_38 . V_41 . V_46 << 2 ;
V_17 -> V_17 [ V_44 ] = ( long ) V_45 ;
return - 1 ;
}
}
F_9 ( L_3 , V_17 -> V_19 , V_34 ) ;
V_23 = F_20 ( & V_2 -> V_24 . V_25 ) ;
if ( V_23 == V_11 )
V_23 = F_1 () ;
if ( V_23 == V_11 )
return V_47 ;
V_27 = & F_14 () [ V_23 ] ;
V_36 = F_27 ( V_35 ) ;
if ( V_35 ) {
V_37 = F_28 ( V_32 >> 16 ,
( V_48 T_2 * ) ( & V_27 -> V_28 ) ) ;
V_37 |= F_28 ( V_32 & 0xffff ,
( V_48 T_2 * ) ( ( long ) ( & V_27 -> V_28 ) + 2 ) ) ;
V_37 |= F_28 ( V_36 >> 16 ,
( V_48 T_2 * ) ( & V_27 -> V_30 ) ) ;
V_37 |= F_28 ( V_36 & 0xffff ,
( V_48 T_2 * ) ( ( long ) ( & V_27 -> V_30 ) + 2 ) ) ;
} else {
V_37 = F_28 ( V_32 , & V_27 -> V_28 ) ;
V_37 |= F_28 ( V_36 , & V_27 -> V_30 ) ;
}
if ( F_29 ( V_37 ) ) {
F_30 ( V_49 ) ;
F_10 ( V_23 , V_2 -> V_3 ) ;
return V_47 ;
}
V_2 -> V_24 . V_29 = V_33 ;
V_2 -> V_24 . V_31 = V_34 ;
F_22 ( & V_2 -> V_24 . V_25 , V_23 ) ;
V_17 -> V_19 = ( unsigned long ) & V_27 -> V_28 | V_35 ;
F_31 ( ( unsigned long ) & V_27 -> V_28 ) ;
return 0 ;
}
bool F_32 ( struct V_16 * V_50 )
{
if ( ! F_15 ( V_2 ) ) {
F_30 ( V_49 ) ;
return false ;
}
V_50 -> V_19 = V_2 -> V_24 . V_31 ;
F_9 ( L_4 , V_50 -> V_19 ) ;
F_30 ( V_51 ) ;
return true ;
}
