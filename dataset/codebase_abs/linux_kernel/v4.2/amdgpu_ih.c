static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 . V_5 . V_6 == NULL ) {
V_3 = F_2 ( V_2 , V_2 -> V_4 . V_5 . V_7 ,
V_8 , true ,
V_9 , 0 ,
NULL , & V_2 -> V_4 . V_5 . V_6 ) ;
if ( V_3 ) {
F_3 ( L_1 , V_3 ) ;
return V_3 ;
}
V_3 = F_4 ( V_2 -> V_4 . V_5 . V_6 , false ) ;
if ( F_5 ( V_3 != 0 ) )
return V_3 ;
V_3 = F_6 ( V_2 -> V_4 . V_5 . V_6 ,
V_9 ,
& V_2 -> V_4 . V_5 . V_10 ) ;
if ( V_3 ) {
F_7 ( V_2 -> V_4 . V_5 . V_6 ) ;
F_3 ( L_2 , V_3 ) ;
return V_3 ;
}
V_3 = F_8 ( V_2 -> V_4 . V_5 . V_6 ,
( void * * ) & V_2 -> V_4 . V_5 . V_11 ) ;
F_7 ( V_2 -> V_4 . V_5 . V_6 ) ;
if ( V_3 ) {
F_3 ( L_3 , V_3 ) ;
return V_3 ;
}
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 , unsigned V_7 ,
bool V_12 )
{
T_1 V_13 ;
int V_3 ;
V_13 = F_10 ( V_7 / 4 ) ;
V_7 = ( 1 << V_13 ) * 4 ;
V_2 -> V_4 . V_5 . V_7 = V_7 ;
V_2 -> V_4 . V_5 . V_14 = V_2 -> V_4 . V_5 . V_7 - 1 ;
V_2 -> V_4 . V_5 . V_15 = 0 ;
V_2 -> V_4 . V_5 . V_12 = V_12 ;
if ( V_2 -> V_4 . V_5 . V_12 ) {
if ( ! V_2 -> V_4 . V_5 . V_11 ) {
V_2 -> V_4 . V_5 . V_11 = F_11 ( V_2 -> V_4 . V_5 . V_7 + 8 , V_16 ) ;
if ( V_2 -> V_4 . V_5 . V_11 == NULL )
return - V_17 ;
V_2 -> V_4 . V_5 . V_18 = F_12 ( V_2 -> V_19 ,
( void * ) V_2 -> V_4 . V_5 . V_11 ,
V_2 -> V_4 . V_5 . V_7 ,
V_20 ) ;
if ( F_13 ( V_2 -> V_19 , V_2 -> V_4 . V_5 . V_18 ) ) {
F_14 ( & V_2 -> V_19 -> V_21 , L_4 ) ;
F_15 ( ( void * ) V_2 -> V_4 . V_5 . V_11 ) ;
return - V_17 ;
}
V_2 -> V_4 . V_5 . V_22 = ( V_2 -> V_4 . V_5 . V_7 / 4 ) + 0 ;
V_2 -> V_4 . V_5 . V_23 = ( V_2 -> V_4 . V_5 . V_7 / 4 ) + 1 ;
}
return 0 ;
} else {
V_3 = F_16 ( V_2 , & V_2 -> V_4 . V_5 . V_22 ) ;
if ( V_3 ) {
F_14 ( V_2 -> V_21 , L_5 , V_3 ) ;
return V_3 ;
}
V_3 = F_16 ( V_2 , & V_2 -> V_4 . V_5 . V_23 ) ;
if ( V_3 ) {
F_17 ( V_2 , V_2 -> V_4 . V_5 . V_22 ) ;
F_14 ( V_2 -> V_21 , L_6 , V_3 ) ;
return V_3 ;
}
return F_1 ( V_2 ) ;
}
}
void F_18 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 . V_5 . V_12 ) {
if ( V_2 -> V_4 . V_5 . V_11 ) {
F_19 ( V_2 -> V_19 , V_2 -> V_4 . V_5 . V_18 ,
V_2 -> V_4 . V_5 . V_7 + 8 , V_20 ) ;
F_15 ( ( void * ) V_2 -> V_4 . V_5 . V_11 ) ;
V_2 -> V_4 . V_5 . V_11 = NULL ;
}
} else {
if ( V_2 -> V_4 . V_5 . V_6 ) {
V_3 = F_4 ( V_2 -> V_4 . V_5 . V_6 , false ) ;
if ( F_20 ( V_3 == 0 ) ) {
F_21 ( V_2 -> V_4 . V_5 . V_6 ) ;
F_22 ( V_2 -> V_4 . V_5 . V_6 ) ;
F_7 ( V_2 -> V_4 . V_5 . V_6 ) ;
}
F_23 ( & V_2 -> V_4 . V_5 . V_6 ) ;
V_2 -> V_4 . V_5 . V_11 = NULL ;
V_2 -> V_4 . V_5 . V_6 = NULL ;
}
F_17 ( V_2 , V_2 -> V_4 . V_5 . V_22 ) ;
F_17 ( V_2 , V_2 -> V_4 . V_5 . V_23 ) ;
}
}
int F_24 ( struct V_1 * V_2 )
{
struct V_24 V_25 ;
T_1 V_26 ;
if ( ! V_2 -> V_4 . V_5 . V_27 || V_2 -> V_28 )
return V_29 ;
V_26 = F_25 ( V_2 ) ;
V_30:
if ( F_26 ( & V_2 -> V_4 . V_5 . V_31 , 1 ) )
return V_29 ;
F_27 ( L_7 , V_32 , V_2 -> V_4 . V_5 . V_15 , V_26 ) ;
F_28 () ;
while ( V_2 -> V_4 . V_5 . V_15 != V_26 ) {
F_29 ( V_2 , & V_25 ) ;
V_2 -> V_4 . V_5 . V_15 &= V_2 -> V_4 . V_5 . V_14 ;
F_30 ( V_2 , & V_25 ) ;
}
F_31 ( V_2 ) ;
F_32 ( & V_2 -> V_4 . V_5 . V_31 , 0 ) ;
V_26 = F_25 ( V_2 ) ;
if ( V_26 != V_2 -> V_4 . V_5 . V_15 )
goto V_30;
return V_33 ;
}
