static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
if ( F_2 ( V_3 -> type != V_6 ) ) {
F_3 ( V_7 L_1 ,
V_3 -> type ) ;
return NULL ;
}
V_5 = F_4 ( V_3 , V_8 ) ;
if ( F_2 ( ! V_5 ) ) {
F_3 ( V_7 L_2
L_3
L_4 ) ;
return NULL ;
}
return (struct V_1 * ) & V_5 -> V_9 ;
}
static T_1 F_5 ( int V_10 , void * V_11 )
{
struct V_1 * V_12 ;
int V_13 ;
for (; ; ) {
V_13 = F_6 ( V_14 , 6 , 1 , NULL ,
V_15 ,
F_7 ( V_10 ) ,
V_16 , 1 ,
F_8 ( V_17 ) ,
V_18 ) ;
if ( V_13 != 0 )
break;
V_12 = F_1 ( (struct V_2 * ) V_17 ) ;
if ( ! V_12 )
continue;
F_9 ( & V_19 ,
0 , V_12 ) ;
}
return V_20 ;
}
static int T_2 F_10 ( void )
{
struct V_21 * V_22 ;
V_14 = F_11 ( L_5 ) ;
if ( V_14 == V_23 )
return - V_24 ;
V_22 = F_12 ( L_6 ) ;
if ( V_22 ) {
F_13 ( V_22 , F_5 , L_7 ) ;
F_14 ( L_8 ) ;
F_15 ( V_22 ) ;
} else {
return - V_24 ;
}
return 0 ;
}
