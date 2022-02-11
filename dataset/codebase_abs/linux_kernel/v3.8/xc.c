int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_2 ( V_6 , V_2 -> V_4 + V_7 ) ;
F_2 ( V_8 , V_2 -> V_9 + V_10 ) ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_4 + V_5 ) ;
F_2 ( 0 , V_2 -> V_4 + V_7 ) ;
F_2 ( 0 , V_2 -> V_9 + V_10 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
return ( F_5 ( V_2 -> V_4 + V_5 ) & V_3 )
|| ( F_5 ( V_2 -> V_4 + V_7 ) & V_6 )
|| ( F_5 ( V_2 -> V_9 + V_10 ) & V_8 ) ?
0 : 1 ;
}
int F_6 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_9 + V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned long V_12 , unsigned int V_13 )
{
if ( V_12 >= F_8 ( V_2 -> V_14 ) &&
V_12 + V_13 < F_8 ( V_2 -> V_14 ) + V_15 )
return 0 ;
if ( V_12 >= F_9 ( V_2 -> V_14 ) &&
V_12 + V_13 < F_9 ( V_2 -> V_14 ) + V_16 )
return 0 ;
F_10 ( V_2 -> V_17 , L_1 ) ;
return - 1 ;
}
static int F_11 ( struct V_1 * V_2 , const void * V_18 , int V_19 )
{
unsigned int V_20 , V_12 ;
const unsigned int * V_21 = V_18 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_19 ; V_22 ++ ) {
V_12 = * V_21 ++ ;
V_20 = * V_21 ++ ;
if ( F_7 ( V_2 , V_12 , 4 ) < 0 )
return - V_23 ;
F_2 ( V_20 , ( void V_24 * ) F_12 ( V_12 ) ) ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_25 ;
char V_26 [ 16 ] ;
const struct V_27 * V_28 ;
struct V_29 * V_30 ;
unsigned int V_13 ;
int V_22 ;
const void * V_31 ;
unsigned long V_32 ;
sprintf ( V_26 , L_2 , V_2 -> V_14 ) ;
V_25 = F_14 ( & V_28 , V_26 , V_2 -> V_17 ) ;
if ( V_25 < 0 ) {
F_10 ( V_2 -> V_17 , L_3 ) ;
return V_25 ;
}
V_30 = (struct V_29 * ) V_28 -> V_21 ;
if ( V_30 -> V_33 != 0x4e657458 ) {
if ( V_30 -> V_33 == 0x5874654e ) {
F_10 ( V_2 -> V_17 ,
L_4 ) ;
V_25 = - V_34 ;
goto V_35;
}
F_10 ( V_2 -> V_17 , L_5 ,
V_30 -> V_33 ) ;
V_25 = - V_34 ;
goto V_35;
}
V_2 -> type = V_30 -> type ;
V_2 -> V_36 = V_30 -> V_36 ;
V_25 = - V_23 ;
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ ) {
V_31 = V_28 -> V_21 + V_30 -> V_37 [ V_22 ] . V_38 ;
V_32 = * ( unsigned int * ) V_31 ;
V_31 += sizeof ( unsigned int ) ;
V_13 = V_30 -> V_37 [ V_22 ] . V_13 - sizeof ( unsigned int ) ;
if ( F_7 ( V_2 , V_32 , V_13 ) )
goto V_35;
memcpy ( ( void * ) F_12 ( V_32 ) , V_31 , V_13 ) ;
V_31 = V_28 -> V_21 + V_30 -> V_37 [ V_22 ] . V_39 ;
V_13 = V_30 -> V_37 [ V_22 ] . V_40 ;
V_25 = F_11 ( V_2 , V_31 , V_13 ) ;
if ( V_25 < 0 )
goto V_35;
}
V_25 = 0 ;
V_35:
F_15 ( V_28 ) ;
return V_25 ;
}
struct V_1 * F_16 ( int V_41 , struct V_42 * V_17 )
{
struct V_1 * V_2 = NULL ;
F_17 ( & V_43 ) ;
if ( V_41 > 3 )
goto exit;
if ( V_44 & ( 1 << V_41 ) )
goto exit;
V_2 = F_18 ( sizeof ( struct V_1 ) , V_45 ) ;
if ( ! V_2 )
goto exit;
if ( ! F_19
( F_9 ( V_41 ) , V_16 , F_20 ( & V_17 -> V_46 ) ) )
goto V_47;
if ( ! F_19
( F_8 ( V_41 ) , V_15 , F_20 ( & V_17 -> V_46 ) ) )
goto V_48;
if ( ! F_19
( F_21 ( V_41 ) , V_49 , F_20 ( & V_17 -> V_46 ) ) )
goto V_50;
V_2 -> V_9 = ( void * V_24 ) F_12 ( F_9 ( V_41 ) ) ;
V_2 -> V_4 = ( void * V_24 ) F_12 ( F_8 ( V_41 ) ) ;
V_2 -> V_51 = F_22 ( F_21 ( V_41 ) , V_49 ) ;
if ( ! V_2 -> V_51 )
goto V_52;
V_2 -> V_53 = F_23 ( V_41 ) ;
V_2 -> V_14 = V_41 ;
V_2 -> V_17 = V_17 ;
V_44 |= ( 1 << V_41 ) ;
goto exit;
V_52:
F_24 ( F_21 ( V_41 ) , V_49 ) ;
V_50:
F_24 ( F_8 ( V_41 ) , V_15 ) ;
V_48:
F_24 ( F_9 ( V_41 ) , V_16 ) ;
V_47:
F_25 ( V_2 ) ;
V_2 = NULL ;
exit:
F_26 ( & V_43 ) ;
return V_2 ;
}
void F_27 ( struct V_1 * V_2 )
{
int V_41 = V_2 -> V_14 ;
F_17 ( & V_43 ) ;
F_28 ( V_2 -> V_51 ) ;
F_24 ( F_21 ( V_41 ) , V_49 ) ;
F_24 ( F_8 ( V_41 ) , V_15 ) ;
F_24 ( F_9 ( V_41 ) , V_16 ) ;
V_44 &= ~ ( 1 << V_2 -> V_14 ) ;
F_25 ( V_2 ) ;
F_26 ( & V_43 ) ;
}
