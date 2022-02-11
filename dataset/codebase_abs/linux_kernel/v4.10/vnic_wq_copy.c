void F_1 ( struct V_1 * V_2 )
{
F_2 ( 1 , & V_2 -> V_3 -> V_4 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_2 ( 0 , & V_2 -> V_3 -> V_4 ) ;
for ( V_5 = 0 ; V_5 < 100 ; V_5 ++ ) {
if ( ! ( F_4 ( & V_2 -> V_3 -> V_6 ) ) )
return 0 ;
F_5 ( 1 ) ;
}
F_6 ( V_7 L_1
L_2 ,
V_2 -> V_8 , F_4 ( & V_2 -> V_3 -> V_9 ) ,
F_4 ( & V_2 -> V_3 -> V_10 ) ) ;
return - V_11 ;
}
void F_7 ( struct V_1 * V_2 ,
void (* F_8)( struct V_1 * V_2 ,
struct V_12 * V_13 ) )
{
F_9 ( F_4 ( & V_2 -> V_3 -> V_4 ) ) ;
if ( F_10 ( V_2 ) )
F_11 ( V_2 , - 1 , F_8 ) ;
V_2 -> V_14 = V_2 -> V_15 = 0 ;
F_2 ( 0 , & V_2 -> V_3 -> V_9 ) ;
F_2 ( 0 , & V_2 -> V_3 -> V_10 ) ;
F_2 ( 0 , & V_2 -> V_3 -> V_16 ) ;
F_12 ( & V_2 -> V_17 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
V_19 = V_2 -> V_19 ;
F_14 ( V_19 , & V_2 -> V_17 ) ;
V_2 -> V_3 = NULL ;
}
int F_15 ( struct V_18 * V_19 , struct V_1 * V_2 ,
unsigned int V_8 , unsigned int V_20 ,
unsigned int V_21 )
{
int V_22 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_14 = V_2 -> V_15 = 0 ;
V_2 -> V_3 = F_16 ( V_19 , V_23 , V_8 ) ;
if ( ! V_2 -> V_3 ) {
F_6 ( V_7 L_3 , V_8 ) ;
return - V_24 ;
}
F_3 ( V_2 ) ;
V_22 = F_17 ( V_19 , & V_2 -> V_17 , V_20 , V_21 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
void F_18 ( struct V_1 * V_2 , unsigned int V_25 ,
unsigned int V_26 ,
unsigned int V_27 )
{
T_1 V_28 ;
V_28 = ( T_1 ) V_2 -> V_17 . V_29 | V_30 ;
F_19 ( V_28 , & V_2 -> V_3 -> V_31 ) ;
F_2 ( V_2 -> V_17 . V_20 , & V_2 -> V_3 -> V_32 ) ;
F_2 ( 0 , & V_2 -> V_3 -> V_9 ) ;
F_2 ( 0 , & V_2 -> V_3 -> V_10 ) ;
F_2 ( V_25 , & V_2 -> V_3 -> V_25 ) ;
F_2 ( V_26 , & V_2 -> V_3 -> V_26 ) ;
F_2 ( V_27 , & V_2 -> V_3 -> V_27 ) ;
}
