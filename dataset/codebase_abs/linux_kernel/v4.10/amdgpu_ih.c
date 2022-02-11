static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 . V_5 . V_6 == NULL ) {
V_3 = F_2 ( V_2 , V_2 -> V_4 . V_5 . V_7 ,
V_8 , V_9 ,
& V_2 -> V_4 . V_5 . V_6 ,
& V_2 -> V_4 . V_5 . V_10 ,
( void * * ) & V_2 -> V_4 . V_5 . V_11 ) ;
if ( V_3 ) {
F_3 ( L_1 , V_3 ) ;
return V_3 ;
}
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 , unsigned V_7 ,
bool V_12 )
{
T_1 V_13 ;
int V_3 ;
V_13 = F_5 ( V_7 / 4 ) ;
V_7 = ( 1 << V_13 ) * 4 ;
V_2 -> V_4 . V_5 . V_7 = V_7 ;
V_2 -> V_4 . V_5 . V_14 = V_2 -> V_4 . V_5 . V_7 - 1 ;
V_2 -> V_4 . V_5 . V_15 = 0 ;
V_2 -> V_4 . V_5 . V_12 = V_12 ;
if ( V_2 -> V_4 . V_5 . V_12 ) {
if ( ! V_2 -> V_4 . V_5 . V_11 ) {
V_2 -> V_4 . V_5 . V_11 = F_6 ( V_2 -> V_16 ,
V_2 -> V_4 . V_5 . V_7 + 8 ,
& V_2 -> V_4 . V_5 . V_17 ) ;
if ( V_2 -> V_4 . V_5 . V_11 == NULL )
return - V_18 ;
memset ( ( void * ) V_2 -> V_4 . V_5 . V_11 , 0 , V_2 -> V_4 . V_5 . V_7 + 8 ) ;
V_2 -> V_4 . V_5 . V_19 = ( V_2 -> V_4 . V_5 . V_7 / 4 ) + 0 ;
V_2 -> V_4 . V_5 . V_20 = ( V_2 -> V_4 . V_5 . V_7 / 4 ) + 1 ;
}
return 0 ;
} else {
V_3 = F_7 ( V_2 , & V_2 -> V_4 . V_5 . V_19 ) ;
if ( V_3 ) {
F_8 ( V_2 -> V_21 , L_2 , V_3 ) ;
return V_3 ;
}
V_3 = F_7 ( V_2 , & V_2 -> V_4 . V_5 . V_20 ) ;
if ( V_3 ) {
F_9 ( V_2 , V_2 -> V_4 . V_5 . V_19 ) ;
F_8 ( V_2 -> V_21 , L_3 , V_3 ) ;
return V_3 ;
}
return F_1 ( V_2 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_5 . V_12 ) {
if ( V_2 -> V_4 . V_5 . V_11 ) {
F_11 ( V_2 -> V_16 , V_2 -> V_4 . V_5 . V_7 + 8 ,
( void * ) V_2 -> V_4 . V_5 . V_11 ,
V_2 -> V_4 . V_5 . V_17 ) ;
V_2 -> V_4 . V_5 . V_11 = NULL ;
}
} else {
F_12 ( & V_2 -> V_4 . V_5 . V_6 ,
& V_2 -> V_4 . V_5 . V_10 ,
( void * * ) & V_2 -> V_4 . V_5 . V_11 ) ;
F_9 ( V_2 , V_2 -> V_4 . V_5 . V_19 ) ;
F_9 ( V_2 , V_2 -> V_4 . V_5 . V_20 ) ;
}
}
int F_13 ( struct V_1 * V_2 )
{
struct V_22 V_23 ;
T_1 V_24 ;
if ( ! V_2 -> V_4 . V_5 . V_25 || V_2 -> V_26 )
return V_27 ;
V_24 = F_14 ( V_2 ) ;
V_28:
if ( F_15 ( & V_2 -> V_4 . V_5 . V_29 , 1 ) )
return V_27 ;
F_16 ( L_4 , V_30 , V_2 -> V_4 . V_5 . V_15 , V_24 ) ;
F_17 () ;
while ( V_2 -> V_4 . V_5 . V_15 != V_24 ) {
T_1 V_31 = V_2 -> V_4 . V_5 . V_15 >> 2 ;
F_18 ( V_2 ,
( const void * ) & V_2 -> V_4 . V_5 . V_11 [ V_31 ] ) ;
V_23 . V_32 = ( const V_33 * )
& V_2 -> V_4 . V_5 . V_11 [ V_31 ] ;
F_19 ( V_2 , & V_23 ) ;
V_2 -> V_4 . V_5 . V_15 &= V_2 -> V_4 . V_5 . V_14 ;
F_20 ( V_2 , & V_23 ) ;
}
F_21 ( V_2 ) ;
F_22 ( & V_2 -> V_4 . V_5 . V_29 , 0 ) ;
V_24 = F_14 ( V_2 ) ;
if ( V_24 != V_2 -> V_4 . V_5 . V_15 )
goto V_28;
return V_34 ;
}
