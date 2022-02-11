static
void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_4 = F_2 ( V_2 , struct V_4 , V_5 ) ;
struct V_6 * V_6 = & V_4 -> V_6 ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_11 * V_12 ;
T_1 V_13 ;
F_3 ( 4 , V_10 , L_1 , V_4 , V_4 ) ;
while ( NULL != ( V_12 = F_4 ( V_6 , & V_13 ) ) ) {
F_5 ( 2 , V_10 , L_2 , V_13 ) ;
F_6 ( 5 , V_10 , V_12 , V_13 ) ;
F_7 ( V_8 ) ;
V_3 = F_8 ( V_8 , 0 , V_12 , V_13 ) ;
F_9 ( V_8 ) ;
F_10 ( V_6 ) ;
if ( V_3 < 0 ) {
F_11 ( V_10 , L_3
L_4 , ( void * ) V_12 - V_6 -> V_14 ,
V_13 , V_3 ) ;
}
if ( V_3 == - V_15 ) {
F_12 ( V_6 ) ;
break;
}
F_5 ( 2 , V_10 , L_5 , V_13 ) ;
}
F_13 ( 4 , V_10 , L_6 , V_4 ) ;
}
void F_14 ( struct V_6 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 , struct V_4 , V_6 ) ;
struct V_9 * V_10 = & V_4 -> V_8 -> V_10 ;
unsigned long V_16 ;
F_3 ( 3 , V_10 , L_7 , V_6 ) ;
F_15 ( & V_6 -> V_17 , V_16 ) ;
if ( V_4 -> V_18 != NULL )
F_16 ( V_4 -> V_18 , & V_4 -> V_5 ) ;
F_17 ( & V_6 -> V_17 , V_16 ) ;
F_13 ( 3 , V_10 , L_7 , V_6 ) ;
}
int F_18 ( struct V_4 * V_4 )
{
int V_3 ;
struct V_9 * V_10 = & V_4 -> V_8 -> V_10 ;
struct V_6 * V_6 = & V_4 -> V_6 ;
struct V_19 * V_18 ;
unsigned long V_16 ;
F_3 ( 5 , V_10 , L_8 , V_4 ) ;
F_19 ( & V_4 -> V_5 , F_1 ) ;
snprintf ( V_4 -> V_20 , sizeof( V_4 -> V_20 ) ,
L_9 , V_6 -> V_21 . V_22 ) ;
V_18 =
F_20 ( V_4 -> V_20 ) ;
if ( V_18 == NULL ) {
F_11 ( V_10 , L_10 ) ;
V_3 = - V_23 ;
} else
V_3 = 0 ;
F_15 ( & V_6 -> V_17 , V_16 ) ;
V_4 -> V_18 = V_18 ;
F_17 ( & V_6 -> V_17 , V_16 ) ;
F_13 ( 5 , V_10 , L_11 , V_4 , V_3 ) ;
return V_3 ;
}
void F_21 ( struct V_4 * V_4 )
{
struct V_6 * V_6 = & V_4 -> V_6 ;
struct V_19 * V_18 ;
unsigned long V_16 ;
V_18 = V_4 -> V_18 ;
F_15 ( & V_6 -> V_17 , V_16 ) ;
V_4 -> V_18 = NULL ;
F_17 ( & V_6 -> V_17 , V_16 ) ;
if ( V_18 )
F_22 ( V_18 ) ;
}
