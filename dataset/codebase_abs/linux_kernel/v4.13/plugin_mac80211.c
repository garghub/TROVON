static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , const void * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 , V_5 ) ;
int V_9 ;
int V_10 ;
if ( ! V_8 ) {
F_3 ( V_2 , L_1 , V_5 ) ;
return;
}
V_9 = V_8 -> V_9 ;
V_10 = V_8 -> V_11 ;
if ( ! strncmp ( V_8 -> type , L_2 , 10 ) ) {
unsigned long long V_12 ;
if ( F_4 ( V_8 , V_6 , & V_12 ) ) {
F_3 ( V_2 , L_3 ) ;
return;
}
V_9 = V_12 & 0xffff ;
V_10 = V_12 >> 16 ;
}
F_3 ( V_2 , L_4 , V_10 , ( char * ) V_6 + V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_3 * V_4 , void * V_15 )
{
void * V_6 = V_14 -> V_6 ;
F_1 ( V_2 , V_4 , L_5 , V_6 ) ;
F_3 ( V_2 , L_6 ) ;
F_1 ( V_2 , V_4 , L_7 , V_6 ) ;
F_6 ( V_2 , L_8 , V_4 , L_9 , V_14 , 1 ) ;
F_3 ( V_2 , L_10 , V_16 , L_11 ) ;
F_7 ( L_12 ) ; F_8 () ;
F_7 ( L_13 ) ; F_8 () ;
F_7 ( L_14 ) ; F_8 () ;
F_7 ( L_15 ) ; F_8 () ;
F_7 ( L_16 ) ; F_8 () ;
F_7 ( L_17 ) ; F_8 () ;
F_3 ( V_2 , L_10 , V_16 , L_11 ) ;
F_7 ( L_18 ) ; F_8 () ;
F_9 ( L_19 ) ; F_8 () ;
F_9 ( L_20 ) ; F_8 () ;
F_7 ( L_21 ) ;
F_3 ( V_2 , L_10 , V_16 , L_11 ) ;
F_7 ( L_22 ) ;
return 0 ;
}
int F_10 ( struct V_17 * V_17 )
{
F_11 ( V_17 , - 1 , L_23 ,
L_24 ,
F_5 , NULL ) ;
return 0 ;
}
void F_12 ( struct V_17 * V_17 )
{
F_13 ( V_17 , - 1 , L_23 ,
L_24 ,
F_5 , NULL ) ;
}
