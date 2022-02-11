static void * F_1 ( void * V_1 , void * V_2 )
{
if ( V_1 < V_2 || V_1 >= ( V_2 + V_3 ) )
return NULL ;
return V_2 + V_3 ;
}
static void * F_2 ( unsigned long * V_4 , int V_5 )
{
void * V_2 = F_3 ( V_6 , V_5 ) ;
return F_1 ( V_4 , V_2 ) ;
}
static void * F_4 ( unsigned long * V_4 , int V_5 )
{
void * V_2 = F_3 ( V_7 , V_5 ) ;
return F_1 ( V_4 , V_2 ) ;
}
void F_5 ( struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * V_4 , unsigned long V_12 ,
const struct V_13 * V_14 , void * V_15 )
{
const unsigned V_5 = F_6 () ;
int V_16 = 0 ;
T_1 * V_17 ;
if ( ! V_9 )
V_9 = V_18 ;
if ( ! V_4 ) {
unsigned long V_19 ;
V_4 = & V_19 ;
if ( V_9 != V_18 )
V_4 = ( unsigned long * ) V_9 -> V_20 . V_21 ;
}
if ( ! V_12 )
V_12 = F_7 ( V_9 , V_11 ) ;
for (; ; ) {
void * V_22 ;
V_22 = F_2 ( V_4 , V_5 ) ;
if ( ! V_22 )
V_22 = F_4 ( V_4 , V_5 ) ;
V_12 = V_14 -> V_23 ( V_9 , V_4 , V_12 , V_14 , V_15 ,
V_22 , & V_16 ) ;
if ( ! V_22 )
break;
V_17 = ( T_1 * ) ( V_22 - V_3 ) ;
V_4 = ( unsigned long * ) * V_17 ;
if ( ! V_4 )
break;
if ( V_14 -> V_4 ( V_15 , L_1 ) < 0 )
break;
F_8 () ;
}
F_9 () ;
}
void
F_10 ( struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * V_21 , unsigned long V_12 , char * V_24 )
{
unsigned long * V_4 ;
int V_25 ;
if ( V_21 == NULL ) {
if ( V_9 )
V_21 = ( unsigned long * ) V_9 -> V_20 . V_21 ;
else
V_21 = ( unsigned long * ) & V_21 ;
}
V_4 = V_21 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( F_11 ( V_4 ) )
break;
if ( ( V_25 % V_27 ) == 0 ) {
if ( V_25 != 0 )
F_12 ( L_2 ) ;
F_13 ( L_3 , V_24 , * V_4 ++ ) ;
} else
F_12 ( L_4 , * V_4 ++ ) ;
F_8 () ;
}
F_12 ( L_2 ) ;
F_14 ( V_9 , V_11 , V_21 , V_12 , V_24 ) ;
}
void F_15 ( struct V_10 * V_11 )
{
int V_25 ;
F_16 ( V_28 ) ;
F_17 ( V_11 , ! F_18 ( V_11 ) ) ;
if ( ! F_18 ( V_11 ) ) {
unsigned int V_29 = V_30 * 43 / 64 ;
unsigned int V_31 = V_30 ;
unsigned char V_32 ;
T_2 * V_33 ;
F_19 ( L_5 ) ;
F_10 ( NULL , V_11 , & V_11 -> V_21 , 0 , V_28 ) ;
F_19 ( L_6 ) ;
V_33 = ( T_2 * ) V_11 -> V_33 - V_29 ;
if ( V_33 < ( T_2 * ) V_34 || F_20 ( V_33 , V_32 ) ) {
V_33 = ( T_2 * ) V_11 -> V_33 ;
V_31 = V_31 - V_29 + 1 ;
}
for ( V_25 = 0 ; V_25 < V_31 ; V_25 ++ , V_33 ++ ) {
if ( V_33 < ( T_2 * ) V_34 ||
F_20 ( V_33 , V_32 ) ) {
F_12 ( L_7 ) ;
break;
}
if ( V_33 == ( T_2 * ) V_11 -> V_33 )
F_12 ( L_8 , V_32 ) ;
else
F_12 ( L_9 , V_32 ) ;
}
}
F_12 ( L_2 ) ;
}
int F_21 ( unsigned long V_33 )
{
unsigned short V_35 ;
if ( V_33 < V_34 )
return 0 ;
if ( F_20 ( ( unsigned short * ) V_33 , V_35 ) )
return 0 ;
return V_35 == 0x0b0f ;
}
