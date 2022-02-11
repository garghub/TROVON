static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_3 -> V_7 ;
struct V_1 * V_8 ;
unsigned char * V_9 , * V_10 ;
if ( V_3 -> V_11 < sizeof( struct V_5 ) ||
V_6 -> V_12 != V_13 ||
V_6 -> V_14 != V_15 )
return NULL ;
V_10 = V_3 -> V_7 + V_3 -> V_11 ;
V_9 = V_6 -> V_16 ;
while ( V_9 < V_10 ) {
V_8 = (struct V_1 * ) V_9 ;
if ( V_8 -> V_17 == V_4 )
return V_8 ;
V_9 += V_8 -> V_18 ;
}
return NULL ;
}
static struct V_19 * F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
if ( F_3 ( V_3 -> type != V_20 ) ) {
F_4 ( V_21 L_1 ,
V_3 -> type ) ;
return NULL ;
}
V_8 = F_1 ( V_3 , V_22 ) ;
if ( F_3 ( ! V_8 ) ) {
F_4 ( V_21 L_2
L_3
L_4 ) ;
return NULL ;
}
return (struct V_19 * ) & V_8 -> V_23 ;
}
static T_2 F_5 ( int V_24 , void * V_25 )
{
struct V_19 * V_26 ;
int V_27 ;
for (; ; ) {
V_27 = F_6 ( V_28 , 6 , 1 , NULL ,
V_29 ,
F_7 ( V_24 ) ,
V_30 , 1 ,
F_8 ( V_31 ) ,
V_32 ) ;
if ( V_27 != 0 )
break;
V_26 = F_2 ( (struct V_2 * ) V_31 ) ;
if ( ! V_26 )
continue;
F_9 ( & V_33 ,
0 , V_26 ) ;
}
return V_34 ;
}
static int T_3 F_10 ( void )
{
struct V_35 * V_36 ;
V_28 = F_11 ( L_5 ) ;
if ( V_28 == V_37 ) {
F_12 ( L_6 ) ;
return - V_38 ;
}
V_36 = F_13 ( L_7 ) ;
if ( V_36 ) {
F_14 ( V_36 , F_5 , L_8 ) ;
F_15 ( V_36 ) ;
} else {
F_16 ( L_9
L_10 ) ;
return - V_38 ;
}
return 0 ;
}
