void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long * V_5 , unsigned long V_6 ,
const struct V_7 * V_8 , void * V_9 )
{
int V_10 = 0 ;
if ( ! V_2 )
V_2 = V_11 ;
if ( ! V_5 ) {
unsigned long V_12 ;
V_5 = & V_12 ;
if ( V_2 && V_2 != V_11 )
V_5 = ( unsigned long * ) V_2 -> V_13 . V_14 ;
}
if ( ! V_6 )
V_6 = F_2 ( V_2 , V_4 ) ;
for (; ; ) {
struct V_15 * V_16 ;
V_16 = (struct V_15 * )
( ( unsigned long ) V_5 & ( ~ ( V_17 - 1 ) ) ) ;
V_6 = V_8 -> V_18 ( V_16 , V_5 , V_6 , V_8 , V_9 , NULL , & V_10 ) ;
V_5 = ( unsigned long * ) V_16 -> V_19 ;
if ( ! V_5 )
break;
if ( V_8 -> V_5 ( V_9 , L_1 ) < 0 )
break;
F_3 () ;
}
}
void
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long * V_14 , unsigned long V_6 , char * V_20 )
{
unsigned long * V_5 ;
int V_21 ;
if ( V_14 == NULL ) {
if ( V_2 )
V_14 = ( unsigned long * ) V_2 -> V_13 . V_14 ;
else
V_14 = ( unsigned long * ) & V_14 ;
}
V_5 = V_14 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( F_5 ( V_5 ) )
break;
if ( V_21 && ( ( V_21 % V_23 ) == 0 ) )
F_6 ( L_2 ) ;
F_6 ( L_3 , * V_5 ++ ) ;
F_3 () ;
}
F_6 ( L_2 ) ;
F_7 ( V_2 , V_4 , V_14 , V_6 , V_20 ) ;
}
void F_8 ( struct V_3 * V_4 )
{
int V_21 ;
F_9 ( V_4 , ! F_10 ( V_4 ) ) ;
F_11 ( L_4 ,
V_24 , V_11 -> V_25 , F_12 ( V_11 ) ,
F_13 () , V_11 , F_14 ( V_11 ) ) ;
if ( ! F_10 ( V_4 ) ) {
unsigned int V_26 = V_27 * 43 / 64 ;
unsigned int V_28 = V_27 ;
unsigned char V_29 ;
T_1 * V_30 ;
F_11 ( L_5 ) ;
F_4 ( NULL , V_4 , & V_4 -> V_14 , 0 , V_31 ) ;
F_11 ( L_6 ) ;
V_30 = ( T_1 * ) V_4 -> V_30 - V_26 ;
if ( V_30 < ( T_1 * ) V_32 || F_15 ( V_30 , V_29 ) ) {
V_30 = ( T_1 * ) V_4 -> V_30 ;
V_28 = V_28 - V_26 + 1 ;
}
for ( V_21 = 0 ; V_21 < V_28 ; V_21 ++ , V_30 ++ ) {
if ( V_30 < ( T_1 * ) V_32 ||
F_15 ( V_30 , V_29 ) ) {
F_6 ( L_7 ) ;
break;
}
if ( V_30 == ( T_1 * ) V_4 -> V_30 )
F_6 ( L_8 , V_29 ) ;
else
F_6 ( L_9 , V_29 ) ;
}
}
F_6 ( L_2 ) ;
}
int F_16 ( unsigned long V_30 )
{
unsigned short V_33 ;
if ( V_30 < V_32 )
return 0 ;
if ( F_15 ( ( unsigned short * ) V_30 , V_33 ) )
return 0 ;
return V_33 == 0x0b0f ;
}
