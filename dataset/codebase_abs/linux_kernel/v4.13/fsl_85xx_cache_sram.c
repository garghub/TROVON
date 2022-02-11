void * F_1 ( unsigned int V_1 ,
T_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 ;
unsigned long V_5 ;
if ( F_2 ( V_6 == NULL ) )
return NULL ;
if ( ! V_1 || ( V_1 > V_6 -> V_1 ) || ( V_3 > V_6 -> V_1 ) ) {
F_3 ( L_1 ,
V_7 , V_1 , V_3 ) ;
return NULL ;
}
if ( ( V_3 & ( V_3 - 1 ) ) || V_3 <= 1 ) {
F_3 ( L_2 ,
V_7 , V_3 ) ;
return NULL ;
}
F_4 ( & V_6 -> V_8 , V_5 ) ;
V_4 = F_5 ( V_6 -> V_9 , V_1 , V_3 , NULL ) ;
F_6 ( & V_6 -> V_8 , V_5 ) ;
if ( F_7 ( V_4 ) )
return NULL ;
* V_2 = V_6 -> V_10 + V_4 ;
return ( unsigned char * ) V_6 -> V_11 + V_4 ;
}
void F_8 ( void * V_12 )
{
unsigned long V_5 ;
F_9 ( ! V_12 ) ;
F_4 ( & V_6 -> V_8 , V_5 ) ;
F_10 ( V_6 -> V_9 , V_12 - V_6 -> V_11 ) ;
F_6 ( & V_6 -> V_8 , V_5 ) ;
}
int T_2 F_11 ( struct V_13 * V_14 ,
struct V_15 V_16 )
{
int V_17 = 0 ;
if ( V_6 ) {
F_12 ( & V_14 -> V_14 , L_3 ) ;
return - V_18 ;
}
V_6 = F_13 ( sizeof( struct V_19 ) , V_20 ) ;
if ( ! V_6 ) {
F_12 ( & V_14 -> V_14 , L_4 ) ;
return - V_21 ;
}
V_6 -> V_10 = V_16 . V_22 ;
V_6 -> V_1 = V_16 . V_23 ;
if ( ! F_14 ( V_6 -> V_10 , V_6 -> V_1 ,
L_5 ) ) {
F_12 ( & V_14 -> V_14 , L_6 ,
V_14 -> V_14 . V_24 -> V_25 ) ;
V_17 = - V_26 ;
goto V_27;
}
V_6 -> V_11 = F_15 ( V_6 -> V_10 ,
V_6 -> V_1 , V_28 | V_29 ) ;
if ( ! V_6 -> V_11 ) {
F_12 ( & V_14 -> V_14 , L_7 ,
V_14 -> V_14 . V_24 -> V_25 ) ;
V_17 = - V_21 ;
goto V_30;
}
V_6 -> V_9 = F_16 ( sizeof( unsigned int ) ) ;
if ( F_17 ( V_6 -> V_9 ) ) {
F_12 ( & V_14 -> V_14 , L_8 ,
V_14 -> V_14 . V_24 -> V_25 ) ;
V_17 = F_18 ( V_6 -> V_9 ) ;
goto V_31;
}
F_19 ( V_6 -> V_9 , 0 , V_6 -> V_1 ) ;
F_20 ( & V_6 -> V_8 ) ;
F_21 ( & V_14 -> V_14 , L_9 ,
( unsigned long long ) V_6 -> V_10 , V_6 -> V_1 ) ;
return 0 ;
V_31:
F_22 ( V_6 -> V_11 ) ;
V_30:
F_23 ( V_6 -> V_10 , V_6 -> V_1 ) ;
V_27:
F_24 ( V_6 ) ;
return V_17 ;
}
void F_25 ( struct V_13 * V_14 )
{
F_9 ( ! V_6 ) ;
F_26 ( V_6 -> V_9 , 0 , V_6 -> V_1 ) ;
F_27 ( V_6 -> V_9 ) ;
F_22 ( V_6 -> V_11 ) ;
F_23 ( V_6 -> V_10 , V_6 -> V_1 ) ;
F_24 ( V_6 ) ;
V_6 = NULL ;
F_21 ( & V_14 -> V_14 , L_10 ) ;
}
