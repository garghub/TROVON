static int F_1 ( char V_1 , struct V_2 * V_3 )
{
int V_4 ;
unsigned long V_5 ;
static unsigned char V_6 = 1 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
F_2 ( V_3 , L_1 , V_1 ) ;
memset ( V_3 -> V_10 , 0 , V_11 ) ;
memcpy ( V_3 -> V_10 , V_12 , V_13 ) ;
V_3 -> V_10 [ 5 ] = V_1 ;
V_3 -> V_10 [ 6 ] = V_6 ;
V_5 = V_14 + F_3 ( 6000 ) ;
for (; ; ) {
V_4 = F_4 ( V_3 , V_3 -> V_15 ,
V_3 -> V_10 , V_11 , NULL ) ;
if ( V_4 != V_16 )
goto V_17;
V_4 = F_4 ( V_3 , V_3 -> V_18 ,
V_8 -> V_19 , V_20 , NULL ) ;
if ( V_4 != V_16 )
goto V_17;
if ( V_8 -> V_19 [ 5 ] == V_6 )
break;
if ( F_5 ( V_14 , V_5 ) )
goto V_17;
V_3 -> V_10 [ 4 ] = 0x80 ;
V_3 -> V_10 [ 5 ] = 0 ;
F_6 ( 50 ) ;
}
V_6 ++ ;
if ( V_6 == 0 )
V_6 = 1 ;
F_2 ( V_3 , L_2 , V_1 ) ;
return 0 ;
V_17:
F_2 ( V_3 , L_3 , V_1 ) ;
return V_21 ;
}
static int F_7 ( struct V_22 * V_23 , struct V_2 * V_3 )
{
int V_24 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
if ( V_23 -> V_25 [ 0 ] == V_26 && ! V_8 -> V_27 ) {
V_24 = F_1 ( V_28 , V_3 ) ;
if ( V_24 )
return V_24 ;
V_8 -> V_27 = 1 ;
return F_8 ( V_23 , V_3 ) ;
} else if ( V_23 -> V_25 [ 0 ] == V_29 ) {
V_24 = F_1 ( V_30 , V_3 ) ;
if ( V_24 )
return V_24 ;
V_8 -> V_27 = 0 ;
return F_1 ( V_31 , V_3 ) ;
}
return F_8 ( V_23 , V_3 ) ;
}
static void F_9 ( void * V_9 )
{
struct V_7 * V_8 = (struct V_7 * ) V_9 ;
F_10 ( V_8 -> V_19 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
int V_24 = 0 ;
struct V_7 * V_8 = F_12 ( sizeof( struct V_7 ) , V_32 ) ;
if ( ! V_8 )
goto V_33;
V_8 -> V_19 = F_13 ( V_20 , V_32 ) ;
if ( ! V_8 -> V_19 ) {
F_10 ( V_8 ) ;
goto V_33;
}
V_3 -> V_9 = V_8 ;
V_3 -> V_34 = F_9 ;
V_24 = F_1 ( V_28 , V_3 ) ;
V_8 -> V_27 = ( V_24 == 0 ) ;
V_33:
return V_24 ;
}
static int F_14 ( struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
struct V_2 * V_3 ;
int V_4 ;
V_4 = F_15 ( & V_3 , V_36 , V_38 ,
( V_38 - V_39 ) + V_40 ,
& V_41 ) ;
if ( V_4 )
return V_4 ;
V_3 -> V_42 = L_4 ;
V_3 -> V_43 = F_7 ;
V_3 -> V_44 = V_45 ;
V_4 = F_16 ( V_3 ) ;
return V_4 ;
}
